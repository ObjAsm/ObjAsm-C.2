; ==================================================================================================
; Title:      h2inc+_ParseTypedefFunctionPtr.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:    
; ==================================================================================================


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ParseTypedefFunctionPtr
; Purpose:    typedef function pointer occured.
; Arguments:  Arg1 -> Parent.
; Return:     xax -> Last Token, usually ';' or NULL if failed.
;             xdx -> Name.
; Syntax:     typedef function pointer
;             typedef <annotations><qualifiers><returntype> ( <qualifiers> * <name> )(<parameters>)
; Notes:      The first "(" has been read already!
;             This procedure has to be reentrant, since a function parameter may have "function ptr"
;             types. That means, that we have to write to an intermediate buffer (szPrototype) until
;             we returned from the last recursive call.

ParseTypedefFunctionPtr proc uses xdi pParent:PSTRINGA
  local pToken:PTOKEN, pName:PSTRINGA, pType:PSTRINGA
  local dQualifier:DWORD, dPtrCount:DWORD, bFirstParam:DWORD
  local dTypeCSpec:DWORD, dScanStep:DWORD
  local szPrototype[1024*3]:CHRA, szType[128]:CHRA, cTransBuffer[128]:CHRA, dInside:DWORD

  mov dPtrCount, 0
  mov dQualifier, 0
  mov szPrototype, 0
  mov pName, NULL

  ;Get Qualifiers & Name ----------------------------------------------------
  .while TRUE
    OCall xbx::IncFile.GetNextToken
    jz @Error
    invoke SkipAnnotations, xax
    jz @Error
    mov pToken, xax

    cmp CHRA ptr [xax], ";"                           ;Statement terminator
    jz @Error

    cmp CHRA ptr [xax], "}"                           ;block terminator
    jz @Exit

    .break .if CHRA ptr [xax] == ")"
    .if CHRA ptr [xax] == "*"
      inc dPtrCount
    .else
      invoke GetProtoQualifier, xax
      .if xax != NULL
        mov edx, [xax - sizeof DWORD]
        mov eax, [xax + xdx]
        or dQualifier, eax
      .else
        m2m pName, pToken, xax                        ;Ignore any qualifiers
      .endif
    .endif
  .endw

  DbgPrintF , "¦UD: ParseTypedefFunctionPtr - ¦SA", [xbx].$Obj(IncFile).dLineNumber, pName

  ;Parse function header ----------------------------------------------------
  OCall xbx::IncFile.GetNextToken
  jz @Error
  invoke SkipAnnotations, xax
  jz @Error
  cmp CHRA ptr [xax], "("
  jnz @Error

  lea xdi, szPrototype                                ;xdi -> Buffer
  xor eax, eax
  .if pName != NULL
    .if ([xbx].$Obj(IncFile).bInsideInterface != FALSE); && (dQualifier & PTQ_STDCALL || dQualifier & PTQ_FASTCALL)
      invoke TranslateReservedWord, pName, NULL
      invoke wsprintf, xdi, $OfsCStr("STD_METHOD %s, "), xax ;Use asm adhoc macro
    .else
      invoke GetCallConvString, dQualifier
      .if pParent != NULL
        invoke wsprintf, xdi, $OfsCStr("TYPE_%s_%s typedef proto %s "), pParent, pName, xax
      .else
        invoke wsprintf, xdi, $OfsCStr("TYPE_%s typedef proto %s "), pName, xax
      .endif
    .endif
    add xdi, xax                                        ;Move pointer to the end
  .endif

  ;Parse function parameters ------------------------------------------------
  mov dPtrCount, 0
  mov pType, NULL
  mov bFirstParam, TRUE
  .while TRUE
    OCall xbx::IncFile.GetNextToken
@ProcessToken:
    jz @Error
    invoke SkipAnnotations, xax
    jz @Error
    .break .if CHRA ptr [xax] == ";"                  ;Statement terminator

    .if CHRA ptr [xax] == "*"
      inc dPtrCount
      .continue
    .endif

    .continue .if $DoesStringMatchA?([xax], <struct>) ;Ignore 'struct'
    .continue .if $DoesStringMatchA?([xax], <union>)  ;Ignore 'union'
    .continue .if $DoesStringMatchA?([xax], <enum>)   ;Ignore 'enum'

    .if CHRA ptr [xax] == "["
      inc dPtrCount
      .repeat
        OCall xbx::IncFile.GetNextToken
      .until ZERO? || CHRA ptr [xax] == "]" || CHRA ptr [xax] == ";"
      .continue
    .endif

    .if CHRA ptr [xax] == "("
      ;Function ptr as function parameter?
      invoke IsFunctionPtr?
      .if eax != FALSE
        movzx eax, [xbx].$Obj(IncFile).bInsideInterface     ;If we are inside an interface declaration
      mov dInside, eax                                ;  then we want to declare a typedef
        mov [xbx].$Obj(IncFile).bInsideInterface, FALSE
        invoke ParseTypedefFunctionPtr, pName         ;Possible recursion here!!!
        mov pToken, xax
      mov eax, dInside
        mov [xbx].$Obj(IncFile).bInsideInterface, al
        ;invoke sprintf, addr szType, $OfsCStrA("P¦SA_¦SA"), pName, edx
        lea eax, szType
        mov pType, xax
        mov xax, pToken
        .break .if CHRA ptr [xax] == ";"
      .endif
    .endif

    invoke TranslateTypeQualifier, xax
    .continue .if CHRA ptr [xax] == 0

    ;pToken may be a basic C type -------------------------------------------
    mov pToken, xax
    .if pType == NULL
      BasicTypeCScan
      mov pToken, xax
      .if dTypeCSpec != 0
        invoke ConvBasicTypeC, dTypeCSpec
        .if xax == NULL
          lea xax, szUnkType
          mov pType, xax
        .else
          mov pType, xax
        .endif
        mov xax, pToken
        test xax, xax
        jmp @ProcessToken
      .else
        mov pType, xax
      .endif
    .endif

    mov xax, pToken                                   ;Needed
    .if CHRA ptr [xax] == "," || CHRA ptr [xax] == ")"
      .if bFirstParam != FALSE
        mov xcx, pType
        .break .if CHRA ptr [xcx] == 0 && dPtrCount == 0
        .break .if CHRA ptr [xcx] == ")"              ;We have no argument => name()
        FillStringA [xdi], <:>
        add xdi, 1
        mov bFirstParam, FALSE
      .else
        FillStringA [xdi], <, :>
        add xdi, 3
      .endif

      .while dPtrCount != 0
        FillStringA [xdi], <ptr >
        add xdi, 4
        dec dPtrCount
      .endw

      mov xax, pType
      .if xax != NULL && CHRA ptr [xax] != 0
        invoke TranslateReservedWord, pType, addr cTransBuffer
        mov xdi, $invoke(StrECopyA, xdi, xax)
      .else
        mov CHRA ptr [xdi], 0
      .endif

      mov xax, pToken
      .break .if CHRA ptr [xax] == ")"                ;Exit here with ')'

      .if CHRA ptr [xdi - 1] == SPC
        dec edi
        mov CHRA ptr [xdi], 0
      .endif

      mov pType, NULL
      mov dPtrCount, 0
      .continue
    .endif

    .if pType == NULL && dPtrCount == 0               ;After an '*' can't come a type
      mov pType, xax
    .endif

  .endw

  .while CHRA ptr [xax] != ";" && CHRA ptr [xax] != ","     ;Consume the rest up to ';' or ','
    OCall xbx::IncFile.GetNextToken
  .endw
  mov pToken, xax

  .if pName != NULL
    OCall xbx::IncFile.StmWrite, addr szPrototype
    OCall xbx::IncFile.StmDeleteLastSpace
    OCall xbx::IncFile.StmWriteEOL

    .if [xbx].$Obj(IncFile).bInsideInterface == FALSE
      .if pParent != NULL
        OCall xbx::IncFile.StmWriteF, $OfsCStrA("P%s_%s"), pParent, pName
      .else
        invoke TranslateReservedWord, pName, addr cTransBuffer
        OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s"), xax
      .endif
      OCall xbx::IncFile.StmWrite, $OfsCStrA(" typedef ptr TYPE")
      .if pParent != NULL
        OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s_%s"), pParent, pName
      .else
        OCall xbx::IncFile.StmWriteF, $OfsCStrA("_%s"), pName
      .endif
      OCall xbx::IncFile.StmWriteEOL

      .if pParent != NULL
        OCall xbx::IncFile.StmWriteF, $OfsCStr("%s "), pName
        OCall xbx::IncFile.StmWriteF, $OfsCStr("P%s_%s ?"), pParent, pName
;      .else
;        invoke TranslateReservedWord, pName, NULL
;        OCall xbx::IncFile.StmWriteF, $OfsCStr("%s ?"), xax
      .endif
      OCall xbx::IncFile.StmWriteEOL
    .endif
  .endif
@Exit:
  mov xdx, pName
  mov xax, pToken
  ret

@Error:
  DbgErrorF , "¦SU(¦UD): ParseTypedefFunctionPtr - error", [xbx].$Obj(IncFile).pHeaderFileName, [xbx].$Obj(IncFile).dLineNumber
  mov xdx, pName
  mov xax, pToken
  ret
ParseTypedefFunctionPtr endp
