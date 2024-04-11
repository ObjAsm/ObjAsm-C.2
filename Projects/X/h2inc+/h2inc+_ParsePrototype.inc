; ==================================================================================================
; Title:      h2inc+_ParsePrototype.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:  
; ==================================================================================================


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ParsePrototype
; Purpose:    Parse a function prototype.
; Arguments:  Arg1 -> Function name.
;             Arg2 -> Import specification (for example WINOLEAPI). Can be NULL.
;             Arg3 -> Call convention (for example WINAPI). Can be NULL.
;             xbx -> IncFile.
; Return:     Nothing.
; Link:       https://msdn.microsoft.com/en-us/library/zw3za17w.aspx
; Format:     [Annotation] [Import-Spec] return-type [Call-Conv] Function-Name[(Argument-List)]

ParsePrototype proc uses xdi pProcName:PSTRINGA, pImportSpec:PSTRINGA, pCallConv:PSTRINGA
  local pName:PSTRINGA, pToken:PTOKEN, pPrefix:PSTRINGA, pCallConvStr:PSTRINGA
  local bFunctionPtr:DWORD, dPtrCount:DWORD, dParenthesisCount:DWORD, dParamBytes:DWORD
  local InpStat:INP_STAT, szSuffix[8]:CHRA, szBuffer[512]:CHRA
  local dTypeCSpec:DWORD, pType:PSTRINGA, cTransBuffer[128]:CHRA
  local pStmOutPos:POINTER, dStmOutEOL:DWORD

  ;Parse function header ----------------------------------------------------
  mov pCallConvStr, $invoke(GetCallConvString, [xbx].$Obj(IncFile).dQualifiers)
  DbgPrintF , "¦UD: ParsePrototype - name = ¦SA", [xbx].$Obj(IncFile).dLineNumber, pProcName
  .if pImportSpec == NULL
    DbgPrintF , "ImportSpec = undefined"
  .else
    DbgPrintF , "ImportSpec = ¦SA", pImportSpec
  .endif
  .if $ObjTmpl(Application).Options.dDllImport != DLLIMPORT_DEFPROTO && pImportSpec != NULL
  .else
    .if $ObjTmpl(Application).Options.dDllImport == DLLIMPORT_ASSUME
      or [xbx].$Obj(IncFile).dQualifiers, PTQ_IMPORT
    .elseif $ObjTmpl(Application).Options.dDllImport == DLLIMPORT_IGNORE
      and [xbx].$Obj(IncFile).dQualifiers, not PTQ_IMPORT
    .endif
  .endif

  .if $ObjTmpl(Application).Options.dDllImport == DLLIMPORT_DEFPROTO && pImportSpec != NULL
    OCall xbx::IncFile.StmWriteF, $OfsCStr("@DefProto %s, %s, %s,"), pImportSpec, pProcName, pCallConvStr
    invoke IsReservedWord?, pProcName
    .if eax != FALSE
      OCall xbx::IncFile.ShowWarning, WARNING_MINOR, $OfsCStr("reserved word '%s' used as prototype"), pProcName
      OCall xbx::IncFile.StmWriteF, $OfsCStr(" %s"), addr szResWordSuffix    ;ProcName suffix
    .endif
    OCall xbx::IncFile.StmWrite, $OfsCStrA(", ", 3Ch)  ;", <"
  .else
    .if ([xbx].$Obj(IncFile).dQualifiers & PTQ_IMPORT)
      OCall xbx::IncFile.StmWriteF, $OfsCStrA("TYPE_%s typedef proto %s"), pProcName, xax
    .else
      invoke TranslateReservedWord, pProcName, addr cTransBuffer
      lea xdx, szEmpty
      .if xcx != xdx
        OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s proto %s"), xax, pCallConvStr
      .else
        OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s proto"), xax
      .endif
    .endif
  .endif

  ;Parse function parameters ------------------------------------------------
  mov [xbx].$Obj(IncFile).pPrevToken, NULL
  mov pType, NULL
  mov pName, NULL
  mov bFunctionPtr, FALSE
  mov dPtrCount, 0
  mov dParamBytes, 0
  mov dParenthesisCount, 1
  .while dParenthesisCount != 0
    OCall xbx::IncFile.GetNextToken
@ProcessToken:
    .break .if ZERO? || CHRA ptr [xax] == ";"           ;Statement terminator
    invoke SkipAnnotations, xax
    .break .if ZERO?

    .if CHRA ptr [xax] == "," || CHRA ptr [xax] == ")"
      mov pToken, xax
      .if pType != NULL || dPtrCount != 0
        mov xax, pType
        .if xax == NULL && dPtrCount != 0
          lea xax, szEmpty                              ;Make sure it is a valid PSTRINGA
        .else
          .if dPtrCount == 0 && pName == NULL
            .break .if $DoesStringMatchA?([xax], <void>)
            .break .if $DoesStringMatchA?([xax], <VOID>)
          .endif
        .endif
                                                        ;Don't interpret xxx(void) as parameter
        .if dPtrCount != 0 || CHRA ptr [xax] != 0
          .if dParamBytes != 0 || $ObjTmpl(Application).Options.dDllImport != DLLIMPORT_DEFPROTO || pImportSpec == NULL
            OCall xbx::IncFile.StmWrite, addr szSpace
          .endif
          OCall xbx::IncFile.StmWrite, addr szColon
          .if dPtrCount != 0
            mov eax, sizeof DWORD                       ;Size of a 32 bit POINTER
          .else
            ;Get type sizes (for structures used as parameters). Only relevant for 32 bit!
            OCall pTypeSize::List.Search, pType
            .if eax != FALSE
            	mov edx, ecx
              OCall pTypeSize::List.ItemAt, edx
              mov edx, [xax - sizeof DWORD]
              mov eax, [xax + xdx]
            .else
              mov eax, sizeof DWORD                     ;Default for 32 bit!
            .endif
          .endif
          add dParamBytes, eax
        .endif
        WritePtr                                        ;On exit, dPtrCount = 0
        mov xax, pType
        .if xax != NULL && CHRA ptr [xax] != 0
          OCall xbx::IncFile.StmWrite, pType
        .else
          OCall xbx::IncFile.StmDeleteLastSpace
        .endif
        mov pType, NULL
        mov pName, NULL
        mov bFunctionPtr, FALSE
      .endif

      mov xax, pToken
      .if CHRA ptr [xax] == ")"
        dec dParenthesisCount
      .else
        OCall xbx::IncFile.StmWrite, xax
      .endif

    .elseif CHRA ptr [xax] == "*" || CHRA ptr [xax] == "&"
      inc dPtrCount

    .elseif CHRA ptr [xax] == "["
      inc dPtrCount
      .repeat
        OCall xbx::IncFile.GetNextToken
      .until xax == NULL || CHRA ptr [xax] == "]" || CHRA ptr [xax] == ";"

    .elseif CHRA ptr [xax] == "("
      ;Function ptr as function parameter?
      invoke IsFunctionPtr?
      .if eax != FALSE
        m2m pStmOutPos, [xbx].$Obj(IncFile).pStmOutPos, xax
        m2m dStmOutEOL, [xbx].$Obj(IncFile).dStmOutEOL, ecx
        invoke ParseTypedefFunctionPtr, NULL
        m2m [xbx].$Obj(IncFile).pStmOutPos, pStmOutPos, xax
        m2m [xbx].$Obj(IncFile).dStmOutEOL, dStmOutEOL, ecx
        ;Alternative code without explicit declaration of the Function pointer
        invoke SkipBraces, "(", ")"
        OCall xbx::IncFile.GetNextToken
        invoke SkipBraces, "(", ")"
        mov dPtrCount, TRUE
        mov pName, NULL
        mov pType, NULL
      .else
        inc dParenthesisCount
      .endif

    .else
      invoke TranslateTypeQualifier, xax
      .continue .if CHRA ptr [xax] == 0
      .continue .if $DoesStringMatchA?([xax], <struct>) ;Ignore 'struct'
      .continue .if $DoesStringMatchA?([xax], <union>)  ;Ignore 'union'
      .continue .if $DoesStringMatchA?([xax], <enum>)   ;Ignore 'enum'

      .if $DoesStringMatchA?([xax], <...>)
        c2m pType, $OfsCStrA("vararg"), xax
        lea xax, szEmpty
        mov pName, xax
        .continue
      .endif

      ;pToken may be a basic C type
      mov pToken, xax
      .if pType == NULL
        BasicTypeCScan
        mov pToken, xax
        .if dTypeCSpec != 0
          invoke ConvBasicTypeC, dTypeCSpec
          .if xax == NULL                             ;If conversion failed
            lea xax, szUnkType
            mov pType, xax
          .else
            mov pType, xax
            mov xax, pToken
            test xax, xax
            jmp @ProcessToken
          .endif
          mov xax, pToken
        .endif
      .endif

      lea xdx, szBuffer
      invoke TranslateReservedWord, xax, xdx
      .if pType == NULL
        mov pType, xax
      .elseif pName == NULL
        mov pName, xax
      .endif
    .endif
  .endw

  .if $ObjTmpl(Application).Options.dDllImport == DLLIMPORT_DEFPROTO 
    .if pImportSpec != NULL
      OCall xbx::IncFile.StmWriteChar, 3Eh              ;">"
      mov xax, pCallConvStr
      .if CHRA ptr [xax] != "c"                         ;cdecl doesn't need decoration suffix
        OCall xbx::IncFile.StmWriteF, $OfsCStrA(", &u"), dParamBytes
      .endif
    .endif
  .endif
  OCall xbx::IncFile.StmWriteEOL

  .if !($ObjTmpl(Application).Options.dDllImport == DLLIMPORT_DEFPROTO && pImportSpec != NULL)
    .ifBitSet [xbx].$Obj(IncFile).dQualifiers, PTQ_IMPORT
      .if ([xbx].$Obj(IncFile).dQualifiers & PTQ_STDCALL)
        lea xax, szUnderscore
        mov pPrefix, xax
        lea xdi, szSuffix
        WriteFA xdi, "@¦UD", dParamBytes
      .elseif ([xbx].$Obj(IncFile).dQualifiers & PTQ_CDECL)
        lea xax, szUnderscore
        mov pPrefix, xax
        mov szSuffix, 0
      .else
        lea xax, szEmpty
        mov pPrefix, xax
        mov szSuffix, 0
      .endif

      OCall xbx::IncFile.StmWriteF, $OfsCStrA("externdef stdcall _imp_%s%s%s: ptr proto_%s"), \
                                    pPrefix, pProcName, addr szSuffix, pProcName
      OCall xbx::IncFile.StmWriteEOL
      invoke TranslateReservedWord, pProcName, addr cTransBuffer
      mov ecx, eax
      OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s equ ", 3Ch, "_imp_%s%s%s", 3Eh), \     ;"<" ">"
                                    xcx, pPrefix, pProcName, addr szSuffix
      OCall xbx::IncFile.StmWriteEOL
    .endif
  .endif
  invoke StrSizeA, pProcName
  invoke InsertStrg, pPrototypes, pProcName, eax

  .if $ObjTmpl(Application).Options.bCreateDefs != FALSE
    invoke InsertDefItem, pProcName, dParamBytes
  .endif
  .ifBitSet [xbx].$Obj(IncFile).dQualifiers, PTQ_INLINE
    ;Skip inline C-code block
    OCall xbx::IncFile.SaveInputStatus, addr InpStat
    OCall xbx::IncFile.GetNextToken
    .if !ZERO? && CHRA ptr [xax] == "{"
      invoke SkipBraces, "{", "}"
    .else
      OCall xbx::IncFile.LoadInputStatus, addr InpStat
    .endif
  .endif

@Exit:
  ret

@Error:
  DbgErrorF , "¦SU(¦UD): ParsePrototype - error", [xbx].$Obj(IncFile).pHeaderFileName, [xbx].$Obj(IncFile).dLineNumber
  ret
ParsePrototype endp
