; ==================================================================================================
; Title:      h2inc+_RenderMacroCall.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:    ObjAsm h2inc+ translation procedures.
; ==================================================================================================


.code

; --------------------------------------------------------------------------------------------------
; Procedure:  RenderMacroCall
; Purpose:    A known macro has been found.
; Arguments:  Arg1: -> Macro Name
;             Arg2: Macro Flags (MCF_xxx).
;             Arg3: Flag to write LF after macro invocation.
;             xbx -> IncFile.
; Return:     eax = TRUE if macro was invoked, otherwise FALSE (turned out to be
;             NO macro invocation).

RenderMacroCall proc uses xsi pMacroName:PSTRINGA, dMacroFlags:DWORD, bWriteLF:DWORD
  local pToken:PTOKEN, pType:PSTRINGA, pName:PSTRINGA, bAddSpace:DWORD
  local dPtrCount:DWORD, dParenthesesCount:DWORD, bSkipTheRest:DWORd, pCurrToken:PTOKEN
  local dTypeCSpec:DWORD, dScanStep:DWORD, pArgStack:POINTER, cTransBuffer[128]:CHRA
  local pStr:PSTRINGA, PrevOutStat:STMOUT_STAT

  OCall $ObjTmpl(Application)::Application.ShowInfo, VERBOSITY_DEAFENING, $OfsCStr("RenderMacroCall")
  .ifBitSet dMacroFlags, MCF_SKIP_INVOKATION
    OCall xbx::IncFile.PeekNextTokenC
    .if xax != NULL && CHRA ptr [xax] == '('
      OCall xbx::IncFile.GetNextTokenC                  ;Consume it
      test xax, xax
      jz @ErrorEoF
      invoke SkipBraces, '(', ')'
    .endif
    mov eax, TRUE
    ret
  .endif

  mov pArgStack, $Create@Stacklist()

  .ifBitSet dMacroFlags, MCF_INTERFACE_END
    .ifBitSet $ObjTmpl(Application).Options.dSelectiveOutput, OUTPUT_CONSTANTS
      OCall xbx::IncFile.StmWrite, $OfsCStrA("??Interface equ <>")  ;Reset ??Interface symbol
      OCall xbx::IncFile.StmWriteEoL
    .endif
    mov [xbx].$Obj(IncFile).bInsideInterface, FALSE
  .endif

  OCall xbx::IncFile.PeekNextTokenC
  .if xax != NULL && CHRA ptr [xax] == '('
    OCall xbx::IncFile.StmWrite, pMacroName
    OCall xbx::IncFile.GetNextTokenC                   ;Can NOT fail, we peeked a token previously
    .ifBitClr dMacroFlags, MCF_SKIP_BRACES
      OCall xbx::IncFile.StmWrite, xax
    .else
      OCall xbx::IncFile.StmWriteChar, SPC
    .endif
    mov dParenthesesCount, 1
    mov bAddSpace, FALSE
    .while TRUE
      OCall xbx::IncFile.GetNextTokenC
      .break .if xax == NULL
      Add@Stacklist pArgStack, xax, xdx
      .if CHRA ptr [xax] == '('
        inc dParenthesesCount
        mov bAddSpace, FALSE
      .elseif CHRA ptr [xax] == ')'
        dec dParenthesesCount
        mov bAddSpace, TRUE
        .break .if dParenthesesCount == 0
      .else
        .if CHRA ptr [xax] != ','
          mov pCurrToken, xax
          .if bAddSpace != FALSE
            OCall xbx::IncFile.StmWriteChar, SPC
          .endif
          mov xax, pCurrToken
          .ifBitSet dMacroFlags, MCF_PARAMS_FOLLOW
            lea xdx, cTransBuffer
            invoke TranslateReservedWord, xax, xdx      ;Arguments can not be reserved words
          .endif
          invoke TranslateNumOperator, xax
          mov bAddSpace, TRUE
        .endif
      .endif
      OCall xbx::IncFile.StmWrite, xax
    .endw

    .ifBitClr dMacroFlags, MCF_SKIP_BRACES
      OCall xbx::IncFile.StmWriteChar, 29h              ;')'
    .endif

    ;Up to now we processed MacroName(...). Now comes the rest of the line.
    .ifBitSet dMacroFlags, MCF_COPY_LINE                ;Rest of line belongs to macro invocation
      mov pType, NULL
      mov pName, NULL
      mov dPtrCount, 0
      mov dTypeCSpec, 0
      mov dScanStep, 0
      mov bSkipTheRest, FALSE
      .while TRUE
        .ifBitSet dMacroFlags, MCF_PARAMS_FOLLOW
          OCall xbx::IncFile.GetNextTokenC
          .break .if xax == NULL || CHRA ptr [xax] == ';' ;Statement terminator
        .else
          OCall xbx::IncFile.GetNextTokenPP
          .break .if xax == NULL
        .endif
        .continue .if bSkipTheRest != FALSE

@ProcessToken:
        .ifBitSet dMacroFlags, MCF_PARAMS_FOLLOW
          invoke SkipAnnotations, xax
          .if CHRA ptr [xax] == ')' || CHRA ptr [xax] == ','
            mov pCurrToken, xax
            mov xax, pType
            test xax, xax
            cmovz xax, pName
            .if xax != NULL
              mov pStr, xax
              OCall xbx::IncFile.StmWrite, $OfsCStrA(", :")
              WritePtr
              .if $ObjTmpl(Application).Options.bUntypedParams
                invoke TranslateType, pStr
              .endif
              OCall xbx::IncFile.StmWrite, xax
            .endif
            mov pType, NULL
            mov pName, NULL
            mov dPtrCount, 0
            mov dTypeCSpec, 0
            mov dScanStep, 0
            mov xax, pCurrToken
            .continue .if CHRA ptr [xax] == ','
          .endif
          .if CHRA ptr [xax] == '('
            inc dParenthesesCount
            .continue
          .endif
          .if CHRA ptr [xax] == ')'
            dec dParenthesesCount
            .break .if ZERO?
            .continue
          .endif
          .if CHRA ptr [xax] == '*'
            inc dPtrCount
            .continue
          .endif
          .if CHRA ptr [xax] == '['
            inc dPtrCount
            invoke SkipBraces, '[', ']'
            test xax, xax
            jz @Exit
            .continue
          .endif
          .if CHRA ptr [xax] == "="
            mov bSkipTheRest, TRUE
            .continue
          .endif

          mov ecx, [xax]
          or ecx, 20202020h                             ;Convert to lowercase
          .if ecx == "siht"
            mov cx, [xax + 4]
            .continue .if cx == "_" || cl == 0          ;Skip THIS and THIS_
          .endif

          invoke TranslateTypeQualifier, xax
          .continue .if CHRA ptr [xax] == 0
          .continue .if $DoesStringMatchA?([xax], <struct>) ;Ignore 'struct'
          .continue .if $DoesStringMatchA?([xax], <union>)  ;Ignore 'union'
          .continue .if $DoesStringMatchA?([xax], <enum>)   ;Ignore 'enum'
          mov pToken, xax

          .if pType == NULL
            BasicTypeCScan
            mov pToken, xax
            .if dTypeCSpec != 0
              invoke ConvBasicTypeC, dTypeCSpec
              .if xax == NULL
                lea xax, szUnkType
              .endif
              mov pType, xax
              mov xax, pToken
              test xax, xax
              jmp @ProcessToken
            .endif
          .endif

          mov xax, pToken
          .if pType == NULL
            mov pType, xax
            .continue
          .endif
          .if pName == NULL
            mov pName, xax
            .continue
          .endif
          jmp @ErrorSyntax
        .endif
        OCall xbx::IncFile.StmWrite, xax
      .endw
    .endif
  .else
    .ifBitClr dMacroFlags, MCF_HAS_PARAMS
      OCall xbx::IncFile.StmWrite, pMacroName
    .else
      xor eax, eax                                      ;It wasn't a macro or some error happend
      jmp @Exit
    .endif
  .endif

  .ifBitSet dMacroFlags, MCF_WRITE_END_MACRO
    mov xax, pMacroName
    mov [xbx].$Obj(IncFile).pEndMacro, xax
    mov eax, [xbx].$Obj(IncFile).dBraces
    mov [xbx].$Obj(IncFile).dBlockLevel, eax
    inc [xbx].$Obj(IncFile).dIndentation
  .endif

@Done:
  .if bWriteLF != FALSE
    OCall xbx::IncFile.StmWriteEoL
  .endif
  .ifBitSet dMacroFlags, MCF_INTERFACE_BEG
    .if [xbx].$Obj(IncFile).pContainerName != NULL
      .ifBitSet $ObjTmpl(Application).Options.dSelectiveOutput, OUTPUT_CONSTANTS
        OCall xbx::IncFile.StmWriteF, $OfsCStrA("??Interface equ <%hs>"), [xbx].$Obj(IncFile).pContainerName
        OCall xbx::IncFile.StmWriteEoL
      .endif
      mov [xbx].$Obj(IncFile).bInsideInterface, TRUE
    .endif
  .endif

  .ifBitSet dMacroFlags, MCF_STRUCT_BEG
    StmOutSave PrevOutStat                              ;Save output stream status
    inc [xbx].$Obj(IncFile).dIndentation
    OCall xbx::IncFile.GetNextTokenC
    .if CHRA ptr [xax] == '{'
      mov xsi, $GetItem@Stacklist(pArgStack, 0)
      invoke RenderBlock, xsi, RBT_CONTAINER
      test xax, xax
      jz @ErrorEoF
      invoke RenderInterfaceBlock, xsi
      test xax, xax
      jz @ErrorEoF
      dec [xbx].$Obj(IncFile).dIndentation
      OCall xbx::IncFile.StmWriteF, $OfsCStrA("END_%hs"), pMacroName
      OCall xbx::IncFile.StmWriteEoL
    .else
      jmp @ErrorSyntax
    .endif
    .ifBitClr $ObjTmpl(Application).Options.dSelectiveOutput, OUTPUT_CONTAINERS
      StmOutLoad PrevOutStat                            ;Restore initial output stream status
      mov CHRA ptr [xax], 0
    .endif
  .endif
  mov eax, TRUE

  ;Exit ---------------------------------------------------------------------------------
@Exit:
  Destroy@Stacklist pArgStack, xcx                      ;Don't trash xax
  ret

@ErrorSyntax:
  OCall xbx::IncFile.ShowError, $OfsCStr("RenderMacroCall")
  OCall xbx::IncFile.StmWriteError
  Destroy@Stacklist pArgStack, xcx                      ;Don't trash xax
  invoke GotoNextToken, addr szSemiColon
  ret

@ErrorEoF:
  inc [xbx].$Obj(IncFile).dErrorCount
  OCall xbx::IncFile.StmWriteError
  Destroy@Stacklist pArgStack, xcx                      ;Don't trash xax
  xor eax, eax
  ret
RenderMacroCall endp

