; ==================================================================================================
; Title:      h2inc+_RenderPrototype.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:    ObjAsm h2inc+ translation procedures.
; ==================================================================================================


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  RenderPrototype
; Purpose:    Translate a function prototype.
; Arguments:  Arg1 -> Function name.
;             Arg2 -> Import specification (for example WINOLEAPI). Can be NULL.
;             xbx -> IncFile.
; Return:     Nothing.
; Link:       https://msdn.microsoft.com/en-us/library/zw3za17w.aspx
; Format:     [Annotation] [Import-Spec] return-type [Call-Conv] Function-Name[(Argument-List)]

RenderPrototype proc uses xdi pProcName:PSTRINGA, pImportSpec:PSTRINGA
  local pName:PSTRINGA, pToken:PTOKEN, pPrefix:PSTRINGA, pCallConvStr:PSTRINGA
  local bFunctionPtr:DWORD, dPtrCount:DWORD, dParenthesisCount:DWORD, dParamBytes:DWORD
  local InpStat:INP_STAT, szSuffix[8]:CHRA
  local dTypeCSpec:DWORD, pType:PSTRINGA, cTransBuffer[128]:CHRA
  local pStmOutPos:POINTER, dStmOutEoL:DWORD

  OCall $ObjTmpl(Application)::Application.ShowInfo, VERBOSITY_DEAFENING, \
                                                     $OfsCStr("RenderPrototype")
  ;Parse function header ----------------------------------------------------
  mov pCallConvStr, $invoke(GetCallConvString, [xbx].$Obj(IncFile).dQualifiers)
  .if $ObjTmpl(Application).Options.dDllImport != DLLIMPORT_DEFPROTO && pImportSpec != NULL
  .else
    .if $ObjTmpl(Application).Options.dDllImport == DLLIMPORT_ASSUME
      or [xbx].$Obj(IncFile).dQualifiers, PTQ_IMPORT
    .elseif $ObjTmpl(Application).Options.dDllImport == DLLIMPORT_IGNORE
      and [xbx].$Obj(IncFile).dQualifiers, not PTQ_IMPORT
    .endif
  .endif

  .if $ObjTmpl(Application).Options.dDllImport == DLLIMPORT_DEFPROTO && pImportSpec != NULL
    OCall xbx::IncFile.StmWriteF, $OfsCStrA("@DefProto %hs, %hs, %hs,"), \
                                  pImportSpec, pProcName, pCallConvStr
    invoke IsReservedWord?, pProcName
    .if eax != FALSE
      OCall xbx::IncFile.StmWriteF, $OfsCStrA(" %hs"), addr szResWordSuffix    ;ProcName suffix
    .endif
    OCall xbx::IncFile.StmWrite, $OfsCStrA(", ", 3Ch)  ;", <"
  .else
    .if ([xbx].$Obj(IncFile).dQualifiers & PTQ_IMPORT)
      OCall xbx::IncFile.StmWriteF, $OfsCStrA("TYPE_%hs typedef proto %hs"), pProcName, xax
    .else
      invoke TranslateReservedWord, pProcName, addr cTransBuffer
      lea xdx, szEmpty
      .if xcx != xdx
        OCall xbx::IncFile.StmWriteF, $OfsCStrA("%hs proto %hs"), xax, pCallConvStr
      .else
        OCall xbx::IncFile.StmWriteF, $OfsCStrA("%hs proto"), xax
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
    OCall xbx::IncFile.GetNextTokenC
@ProcessToken:
    .break .if xax == NULL || CHRA ptr [xax] == ';'     ;Statement terminator
    invoke SkipAnnotations, xax
    .break .if xax == NULL

    .if CHRA ptr [xax] == ',' || CHRA ptr [xax] == ')'
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
          .if dParamBytes != 0 || \
              $ObjTmpl(Application).Options.dDllImport != DLLIMPORT_DEFPROTO || \
              pImportSpec == NULL
            OCall xbx::IncFile.StmWrite, addr szSpace
          .endif
          OCall xbx::IncFile.StmWrite, addr szColon
          .if dPtrCount != 0
            mov eax, sizeof(DWORD)                      ;Size of a 32 bit POINTER
          .else
            ;Get type sizes (for structures used as parameters). Only relevant for 32 bit!
            OCall pNewTypeSize::List.Search, pType
            .if eax != FALSE
            	mov edx, ecx
              OCall pNewTypeSize::List.ItemAt, edx
              mov edx, [xax - sizeof(DWORD)]
              mov eax, [xax + xdx]
            .else
              mov eax, sizeof(DWORD)                    ;Default for 32 bit!
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
      .if CHRA ptr [xax] == ')'
        dec dParenthesisCount
      .else
        OCall xbx::IncFile.StmWrite, xax
      .endif

    .elseif CHRA ptr [xax] == '*' || CHRA ptr [xax] == '&'
      inc dPtrCount

    .elseif CHRA ptr [xax] == '['
      inc dPtrCount
      .repeat
        OCall xbx::IncFile.GetNextTokenC
      .until xax == NULL || CHRA ptr [xax] == ']' || CHRA ptr [xax] == ';'

    .elseif CHRA ptr [xax] == '('
      ;Function ptr as function parameter?
      invoke IsFunctionPtr?
      .if eax != FALSE
        m2m pStmOutPos, [xbx].$Obj(IncFile).pStmOutPos, xax
        m2m dStmOutEoL, [xbx].$Obj(IncFile).dStmOutEoL, ecx
        invoke RenderTypedefFuncPtr, NULL
        test xax, xax
        jz @ErrorEoF
        m2m [xbx].$Obj(IncFile).pStmOutPos, pStmOutPos, xax
        m2m [xbx].$Obj(IncFile).dStmOutEoL, dStmOutEoL, ecx
        ;Alternative code without explicit declaration of the Function pointer
        invoke SkipBraces, '(', ')'
        OCall xbx::IncFile.GetNextTokenC
        test xax, xax
        jz @ErrorEoF
        invoke SkipBraces, '(', ')'
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

      lea xdx, cTransBuffer
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
        OCall xbx::IncFile.StmWriteF, $OfsCStrA(", %u"), dParamBytes
      .endif
    .endif
  .endif
  OCall xbx::IncFile.StmWriteEoL

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

      OCall xbx::IncFile.StmWriteF, $OfsCStrA("externdef stdcall _imp_%hs%hs%hs: ptr proto_%hs"), \
                                    pPrefix, pProcName, addr szSuffix, pProcName
      OCall xbx::IncFile.StmWriteEoL
      invoke TranslateReservedWord, pProcName, addr cTransBuffer
      mov xcx, xax
      OCall xbx::IncFile.StmWriteF, $OfsCStrA("%hs equ ", 3Ch, "_imp_%hs%hs%hs", 3Eh), \   ;"<" ">"
                                    xcx, pPrefix, pProcName, addr szSuffix
      OCall xbx::IncFile.StmWriteEoL
    .endif
  .endif
  invoke StrLengthA, pProcName
  invoke InsertStrg, pNewPrototypes, pProcName, eax

  .if $ObjTmpl(Application).Options.bCreateDefs != FALSE
    invoke InsertDefItem, pProcName, dParamBytes
  .endif
  .ifBitSet [xbx].$Obj(IncFile).dQualifiers, PTQ_INLINE
    ;Skip inline C-code block
    OCall xbx::IncFile.InputStatusSave, addr InpStat
    OCall xbx::IncFile.GetNextTokenC
    .if xax != NULL && CHRA ptr [xax] == '{'
      invoke SkipBraces, '{', '}'
    .else
      OCall xbx::IncFile.InputStatusLoad, addr InpStat
    .endif
  .endif

  ;Exit ---------------------------------------------------------------------------------
@Exit:
  ret

@ErrorSyntax:
  inc [xbx].$Obj(IncFile).dErrorCount
  OCall xbx::IncFile.ShowError, $OfsCStr("RenderPrototype")
  OCall xbx::IncFile.StmWriteError
  invoke GotoNextToken, addr szSemiColon
  ret

@ErrorEoF:
  inc [xbx].$Obj(IncFile).dErrorCount
  OCall xbx::IncFile.StmWriteError
  xor eax, eax
  ret
RenderPrototype endp
