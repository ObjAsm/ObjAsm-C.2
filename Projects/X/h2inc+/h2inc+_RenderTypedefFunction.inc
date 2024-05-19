; ==================================================================================================
; Title:      h2inc+_RenderTypedefFunction.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:    ObjAsm h2inc+ translation procedures.
; ==================================================================================================


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  RenderTypedefFunction
; Purpose:    Translate a typedef function.
; Arguments:  Arg1 -> Name.
; Return:     Nothing.
; Syntax:     typedef <qualifiers> returntype name(<parameters>)<{...}>;
;             or in a class definition:
;             <qualifiers> returntype name(<parameters>)<{...}>;

RenderTypedefFunction proc pName:PSTRINGA
  local pToken:PTOKEN, pCurrToken:PTOKEN, dPtrCount:DWORD, bFirstParam:DWORD
  local dTypeCSpec:DWORD, pType:PSTRINGA, cTransBuffer[128]:CHRA

  OCall $ObjTmpl(Application)::Application.ShowInfo, VERBOSITY_DEAFENING, $OfsCStr("RenderTypedefFunction")
  ;Parse function header ----------------------------------------------------
  mov bFirstParam, FALSE
  mov pName, $invoke(TranslateReservedWord, pName, addr cTransBuffer)
  OCall xbx::IncFile.StmWriteF, $OfsCStrA("%hs typedef proto "), pName

  ;Parse function parameters ------------------------------------------------
  mov pType, NULL
  mov dPtrCount, 0
  .while TRUE
    OCall xbx::IncFile.GetNextTokenC
@ProcessToken:
    test xax, xax
    jz @ErrorEoF

    invoke SkipAnnotations, xax
    test xax, xax
    jz @ErrorEoF

    .if CHRA ptr [xax] == '*'
      inc dPtrCount
      .continue
    .endif

    .continue .if $DoesStringMatchA?([xax], <struct>)   ;Ignore 'struct'
    .continue .if $DoesStringMatchA?([xax], <union>)    ;Ignore 'union'
    .continue .if $DoesStringMatchA?([xax], <enum>)     ;Ignore 'enum'

    ;pToken may be a basic C type
    mov pToken, xax
    .if pType == NULL
      BasicTypeCScan
      mov pToken, xax
      .if dTypeCSpec != 0
        invoke ConvBasicTypeC, dTypeCSpec
        .if xax == NULL                                 ;If conversion failed
          lea xax, szUnkType
          mov pType, xax
        .else
          mov pType, xax
          mov xax, pToken
          test xax, xax
          jmp @ProcessToken
          .continue
        .endif
      .endif
    .endif
    mov pToken, xax
    .if CHRA ptr [xax] == ',' || CHRA ptr [xax] == ')'  ;End of function parameter list
      mov pCurrToken, xax
      .if dPtrCount != 0 || pType != NULL
        .if pType != NULL
          mov pType, $invoke(TranslateReservedWord, pType, addr cTransBuffer)  ;Maybe it is a reserved word!
        .endif
        mov xax, pType

        .if dPtrCount != 0 || CHRA ptr [xax] != 0
          .if bFirstParam != FALSE
            OCall xbx::IncFile.StmWrite, $OfsCStrA(", ")
            mov bFirstParam, FALSE
          .endif
          OCall xbx::IncFile.StmWriteChar, ':'
        .endif
        WritePtr
        .if pType != NULL
          OCall xbx::IncFile.StmWrite, pType
        .endif
        OCall xbx::IncFile.StmDeleteLastSpace
      .endif
      mov xax, pCurrToken
      .break .if CHRA ptr [xax] == ')'
      OCall xbx::IncFile.StmWrite, $OfsCStrA(", ")
      mov pType, NULL
      mov dPtrCount, 0
      .continue
    .endif

    mov pToken, xax
    invoke TranslateTypeQualifier, xax
    .continue .if CHRA ptr [xax] == 0
    .if pType == NULL
      m2m pType, pToken, xax
    .endif
  .endw
  OCall xbx::IncFile.StmWriteEoL

  OCall xbx::IncFile.PeekNextTokenC
  .if xax != NULL && CHRA ptr [xax] == '{'
    invoke SkipBraces, '{', '}'
  .endif

  ;Exit ---------------------------------------------------------------------------------
@Exit:
  ret

@ErrorSyntax:
  OCall xbx::IncFile.ShowError, $OfsCStr("RenderTypedefFunction")
  OCall xbx::IncFile.StmWriteError
  invoke GotoNextToken, addr szSemiColon
  ret

@ErrorEoF:
  inc [xbx].$Obj(IncFile).dErrorCount
  OCall xbx::IncFile.StmWriteError
  ret
RenderTypedefFunction endp
