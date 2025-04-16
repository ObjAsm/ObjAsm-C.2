; ==================================================================================================
; Title:      h2inc+_RenderTypedefFuncPtr.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:    ObjAsm h2inc+ translation procedures.
; ==================================================================================================


.code

; --------------------------------------------------------------------------------------------------
; Procedure:  RenderTypedefFuncPtr
; Purpose:    Translate a typedef function pointer.
; Arguments:  Arg1: -> Parent.
; Return:     xax -> Last Token, usually ';' or NULL if failed.
;             xdx -> Name.
; Syntax:     typedef function pointer
;             typedef <annotations><qualifiers><returntype> ( <qualifiers> * <name> )(<parameters>)
; Notes:      The first '(' has been read already!
;             This procedure has to be reentrant, since a function parameter may have "function ptr"
;             types. That means, that we have to write to an intermediate buffer (szPrototype) until
;             we returned from the last recursive call.

RenderTypedefFuncPtr proc uses xdi pParent:PSTRINGA
  local pToken:PTOKEN, pName:PSTRINGA, pType:PSTRINGA, dTypeCSpec:DWORD
  local dQualifier:DWORD, dPtrCount:DWORD, bFirstParam:DWORD
  local cPrototype[1024*3]:CHRA, cType[128]:CHRA, cTransBuffer[128]:CHRA, dInside:DWORD

  OCall $ObjTmpl(Application)::Application.ShowInfo, VERBOSITY_DEAFENING, $OfsCStr("RenderTypedefFuncPtr")
  mov dPtrCount, 0
  mov dQualifier, 0
  mov cPrototype, 0
  mov pName, NULL

  ;Get Qualifiers & Name ----------------------------------------------------------------
  .while TRUE
    OCall xbx::IncFile.GetNextTokenC
    test xax, xax
    jz @ErrorEoF
    invoke SkipAnnotations, xax
    test xax, xax
    jz @ErrorEoF
    mov pToken, xax

    cmp CHRA ptr [xax], ';'                             ;Statement terminator
    jz @ErrorSyntax

    cmp CHRA ptr [xax], '}'                             ;block terminator
    jz @Exit

    .break .if CHRA ptr [xax] == ')'
    .if CHRA ptr [xax] == '*'
      inc dPtrCount
    .else
      invoke GetProtoQualifier, xax
      .if xax != NULL
        mov edx, [xax - sizeof(DWORD)]
        mov eax, [xax + xdx]
        or dQualifier, eax
      .else
        m2m pName, pToken, xax                          ;Ignore any qualifiers
      .endif
    .endif
  .endw

  ;Parse function header ----------------------------------------------------------------
  OCall xbx::IncFile.GetNextTokenC
  test xax, xax
  jz @ErrorEoF
  invoke SkipAnnotations, xax
  test xax, xax
  jz @ErrorEoF
  cmp CHRA ptr [xax], '('
  jnz @ErrorSyntax

  lea xdi, cPrototype                                   ;xdi -> Buffer
  xor eax, eax
  .if pName != NULL
    .if ([xbx].$Obj(IncFile).bInsideInterface != FALSE); && (dQualifier & PTQ_STDCALL || dQualifier & PTQ_FASTCALL)
      invoke TranslateReservedWord, pName, addr cTransBuffer
      invoke wsprintfA, xdi, $OfsCStrA("STD_METHOD %hs, "), xax ;Use asm adhoc macro
    .else
      invoke GetCallConvString, dQualifier
      .if pParent != NULL
        invoke wsprintfA, xdi, $OfsCStrA("TYPE_%hs_%hs typedef proto %hs "), pParent, pName, xax
      .else
        invoke wsprintfA, xdi, $OfsCStrA("TYPE_%hs typedef proto %hs "), pName, xax
      .endif
    .endif
    add xdi, xax                                        ;Move pointer to the end
  .endif

  ;Parse function parameters ------------------------------------------------------------
  mov dPtrCount, 0
  mov pType, NULL
  mov bFirstParam, TRUE
  .while TRUE
    OCall xbx::IncFile.GetNextTokenC
@ProcessToken:
    test xax, xax
    jz @ErrorEoF
    invoke SkipAnnotations, xax
    test xax, xax
    jz @ErrorEoF
    .break .if CHRA ptr [xax] == ';'                    ;Statement terminator

    .if CHRA ptr [xax] == '*'
      inc dPtrCount
      .continue
    .endif

    .continue .if $DoesStringMatchA?([xax], <struct>)   ;Ignore 'struct'
    .continue .if $DoesStringMatchA?([xax], <union>)    ;Ignore 'union'
    .continue .if $DoesStringMatchA?([xax], <enum>)     ;Ignore 'enum'

    .if CHRA ptr [xax] == '['
      inc dPtrCount
      .repeat
        OCall xbx::IncFile.GetNextTokenC
      .until xax == NULL || CHRA ptr [xax] == ']' || CHRA ptr [xax] == ';'
      .continue
    .endif

    .if CHRA ptr [xax] == '('
      ;Function ptr as function parameter?
      invoke IsFunctionPtr?, xax
      .if eax != FALSE
        movzx eax, [xbx].$Obj(IncFile).bInsideInterface ;If we are inside an interface declaration
        mov dInside, eax                                ;  then we want to declare a typedef
        mov [xbx].$Obj(IncFile).bInsideInterface, FALSE
        invoke RenderTypedefFuncPtr, pName              ;Possible recursion here!!!
        test xax, xax
        jz @ErrorEoF
        mov pToken, xax
        mov eax, dInside
        mov [xbx].$Obj(IncFile).bInsideInterface, al
        ;invoke sprintf, addr cType, $OfsCStrA("P¦SA_¦SA"), pName, edx
        lea xax, cType
        mov pType, xax
        mov xax, pToken
        .break .if CHRA ptr [xax] == ';'
      .endif
    .endif

    invoke TranslateTypeQualifier, xax
    .continue .if CHRA ptr [xax] == 0

    ;pToken may be a basic C type -------------------------------------------------------
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

    mov xax, pToken                                     ;Needed
    .if CHRA ptr [xax] == ',' || CHRA ptr [xax] == ')'
      .if bFirstParam != FALSE
        mov xcx, pType
        .break .if CHRA ptr [xcx] == 0 && dPtrCount == 0
        .break .if CHRA ptr [xcx] == ')'                ;We have no argument => name()
        FillStringA [xdi], <:>
        add xdi, ??StrLen
        mov bFirstParam, FALSE
      .else
        FillStringA [xdi], <, :>
        add xdi, ??StrLen
      .endif

      .while dPtrCount != 0
        FillStringA [xdi], <ptr >
        add xdi, ??StrLen
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
      .break .if CHRA ptr [xax] == ')'                  ;Exit here with ')'

      .if CHRA ptr [xdi - 1] == SPC
        dec xdi
        mov CHRA ptr [xdi], 0
      .endif

      mov pType, NULL
      mov dPtrCount, 0
      .continue
    .endif

    .if pType == NULL && dPtrCount == 0                 ;After an '*' can't come a type
      mov pType, xax
    .endif

  .endw

  ;Consume the rest up to ';', ',' or ')'
  .while TRUE
    OCall xbx::IncFile.GetNextTokenC
    test xax, xax
    jz @ErrorEoF
    .break .if CHRA ptr [xax] != ';' || CHRA ptr [xax] != ',' || CHRA ptr [xax] != ')'
  .endw
  mov pToken, xax

  .if pName != NULL
    OCall xbx::IncFile.StmWrite, addr cPrototype
    OCall xbx::IncFile.StmDeleteLastSpace
    OCall xbx::IncFile.StmWriteEoL

    .if [xbx].$Obj(IncFile).bInsideInterface == FALSE
      .if pParent != NULL
        OCall xbx::IncFile.StmWriteF, $OfsCStrA("P%hs_%hs"), pParent, pName
      .else
        invoke TranslateReservedWord, pName, addr cTransBuffer
        OCall xbx::IncFile.StmWriteF, $OfsCStrA("%hs"), xax
      .endif
      OCall xbx::IncFile.StmWrite, $OfsCStrA(" typedef ptr TYPE")
      .if pParent != NULL
        OCall xbx::IncFile.StmWriteF, $OfsCStrA("%hs_%hs"), pParent, pName
      .else
        OCall xbx::IncFile.StmWriteF, $OfsCStrA("_%hs"), pName
      .endif
      OCall xbx::IncFile.StmWriteEoL

      .if pParent != NULL
        OCall xbx::IncFile.StmWriteF, $OfsCStrA("%hs "), pName
        OCall xbx::IncFile.StmWriteF, $OfsCStrA("P%hs_%hs ?"), pParent, pName
;      .else
;        invoke TranslateReservedWord, pName, addr cTransBuffer
;        OCall xbx::IncFile.StmWriteF, $OfsCStrA("%hs ?"), xax
      .endif
      OCall xbx::IncFile.StmWriteEoL
    .endif
  .endif

  ;Exit ---------------------------------------------------------------------------------
@Exit:
  mov xdx, pName
  mov xax, pToken
  ret

@ErrorSyntax:
  OCall xbx::IncFile.ShowError, $OfsCStr("RenderTypedefFuncPtr")
  OCall xbx::IncFile.StmWriteError
  invoke GotoNextToken, addr szSemiColon
  mov xdx, pName
  ret

@ErrorEoF:
  inc [xbx].$Obj(IncFile).dErrorCount
  OCall xbx::IncFile.StmWriteError
  xor edx, edx
  xor eax, eax
  ret
RenderTypedefFuncPtr endp
