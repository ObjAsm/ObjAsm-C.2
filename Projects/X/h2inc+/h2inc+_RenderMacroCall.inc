; ==================================================================================================
; Title:      h2inc+_RenderMacroCall.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:    ObjAsm h2inc+ translation procedures.
; ==================================================================================================


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  RenderMacroCall
; Purpose:    A known macro has been found.
; Arguments:  Arg1 -> Macro Name
;             Arg2: Macro Flags (MCF_xxx).
;             Arg3: Flag to write LF after macro invocation.
;             xbx -> IncFile.
; Return:     eax = returns TRUE if macro was invoked, otherwise FALSE (turned out to be
;             NO macro invocation).

RenderMacroCall proc uses xsi pMacroName:PSTRINGA, dMacroFlags:DWORD, bWriteLF:DWORD
  local pToken:PTOKEN, pType:PSTRINGA, pName:PSTRINGA, pStmOutPos:PSTRINGA, bAddSpace:DWORD
  local dPtrCount:DWORD, dParenthesesCount:DWORD, bSkipTheRest:DWORd, pCurrToken:PTOKEN
  local dTypeCSpec:DWORD, dScanStep:DWORD, pArgStack:POINTER, cTransBuffer[128]:CHRA
  local pStr:PSTRINGA

;  m2m pStmOutPos, [xbx].$Obj(IncFile).pStmOutPos, xax

  DbgPrintF , "¦UD: RenderMacroCall - found: ¦SA", \
            [xbx].$Obj(IncFile).dLineNumber, pMacroName

  .ifBitSet dMacroFlags, MCF_SKIP_INVOKATION
    OCall xbx::IncFile.PeekNextTokenC
    .if !ZERO? && CHRA ptr [xax] == "("
      OCall xbx::IncFile.GetNextTokenC                  ;Consume it
      invoke SkipBraces, "(", ")"
    .endif
    mov eax, TRUE
    ret
  .endif

  mov pArgStack, $Create@Stacklist()

  .ifBitSet dMacroFlags, MCF_INTERFACE_END
    OCall xbx::IncFile.StmWrite, $OfsCStrA("??Interface equ <>")  ;Reset ??Interface symbol
    OCall xbx::IncFile.StmWriteEoL
    mov [xbx].$Obj(IncFile).bInsideInterface, FALSE
  .endif

  OCall xbx::IncFile.PeekNextTokenC
  .if !ZERO? && CHRA ptr [xax] == "("
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
      .break .if ZERO?
      Add@Stacklist pArgStack, xax, xdx
      .if CHRA ptr [xax] == "("
        inc dParenthesesCount
        mov bAddSpace, FALSE
      .elseif CHRA ptr [xax] == ")"
        dec dParenthesesCount
        mov bAddSpace, TRUE
        .break .if dParenthesesCount == 0
      .else
        .if CHRA ptr [xax] != ","
          mov pCurrToken, xax
          .if bAddSpace != FALSE
            OCall xbx::IncFile.StmWriteChar, SPC
          .endif
          mov xax, pCurrToken
          .ifBitSet dMacroFlags, MCF_PARAMS_FOLLOW
            invoke TranslateReservedWord, xax, addr cTransBuffer   ;Arguments can not be reserved words
          .endif
          invoke TranslateNumOperator, xax
          DbgPrintF , "¦UD: RenderMacroCall - Parameter = ¦SA", [xbx].$Obj(IncFile).dLineNumber, xax
          mov bAddSpace, TRUE
        .endif
      .endif
      OCall xbx::IncFile.StmWrite, xax
    .endw

    .ifBitClr dMacroFlags, MCF_SKIP_BRACES
      OCall xbx::IncFile.StmWriteChar, 29h            ;")"
    .endif

    ;Up to now we processed MacroName(...). Now comes the rest of the line.
    .ifBitSet dMacroFlags, MCF_COPY_LINE              ;Rest of line belongs to macro invocation
      mov pType, NULL
      mov pName, NULL
      mov dPtrCount, 0
      mov dTypeCSpec, 0
      mov dScanStep, 0
      mov bSkipTheRest, FALSE
      .while TRUE
        .ifBitSet dMacroFlags, MCF_PARAMS_FOLLOW
          OCall xbx::IncFile.GetNextTokenC
          .break .if ZERO? || CHRA ptr [xax] == ";"     ;Statement terminator
        .else
          OCall xbx::IncFile.GetNextTokenPP
          .break .if ZERO?
        .endif
        .continue .if bSkipTheRest != FALSE

@ProcessToken:
        .ifBitSet dMacroFlags, MCF_PARAMS_FOLLOW
          invoke SkipAnnotations, xax
          .if CHRA ptr [xax] == ")" || CHRA ptr [xax] == ","
            mov pCurrToken, xax
            mov xax, pType
            test xax, xax
            cmovz xax, pName
            .if xax != NULL
              DbgPrintF , "¦UD: RenderMacroCall - Param = ¦SA", [xbx].$Obj(IncFile).dLineNumber, xax
              mov pStr, xax
              OCall xbx::IncFile.StmWrite, $OfsCStrA(", :")
              WritePtr
              movzx edx, $ObjTmpl(Application).Options.bUntypedParams
              invoke TranslateType, pStr, edx
              OCall xbx::IncFile.StmWrite, xax
            .endif
            mov pType, NULL
            mov pName, NULL
            mov dPtrCount, 0
            mov dTypeCSpec, 0
            mov dScanStep, 0
            mov xax, pCurrToken
            .continue .if CHRA ptr [xax] == ","
          .endif
          .if CHRA ptr [xax] == "("
            inc dParenthesesCount
            .continue
          .endif
          .if CHRA ptr [xax] == ")"
            dec dParenthesesCount
            .break .if ZERO?
            .continue
          .endif
          .if CHRA ptr [xax] == "*"
            inc dPtrCount
            .continue
          .endif
          .if CHRA ptr [xax] == "["
            inc dPtrCount
            invoke SkipBraces, "[", "]"
            test eax, eax
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

  .ifBitSet dMacroFlags, MCF_END_MACRO
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
      OCall xbx::IncFile.StmWriteF, $OfsCStrA("??Interface equ <%hs>"), [xbx].$Obj(IncFile).pContainerName
      OCall xbx::IncFile.StmWriteEoL
      mov [xbx].$Obj(IncFile).bInsideInterface, TRUE
    .endif
  .endif
;  .ifBitClr $ObjTmpl(Application).Options.dSelectiveOutput, OUTPUT_CONSTANTS
;    mrm [xbx].$Obj(IncFile).pStmOutPos, pStmOutPos, xcx
;    mov CHRA ptr [xcx], 0
;  .endif

  .ifBitSet dMacroFlags, MCF_STRUCT_BEG
    inc [xbx].$Obj(IncFile).dIndentation
    OCall xbx::IncFile.GetNextTokenC
    .if CHRA ptr [xax] == "{"
      mov xsi, $GetItem@Stacklist(pArgStack, 0)
      invoke RenderBlock, xsi, RBT_CONTAINER
      invoke RenderInterfaceBlock, xsi
      dec [xbx].$Obj(IncFile).dIndentation
      OCall xbx::IncFile.StmWriteF, $OfsCStrA("END_%hs"), pMacroName
      OCall xbx::IncFile.StmWriteEoL
    .else
      jmp @ErrorSyntax
    .endif
  .endif
  mov eax, TRUE

@Exit:
  Destroy@Stacklist pArgStack, xcx                      ;Dont trash xax
  ret

@ErrorSyntax:
@ErrorEoF:
  DbgErrorF , "¦SU(¦UD): RenderMacroCall - error", \
              [xbx].$Obj(IncFile).pHeaderFileName, [xbx].$Obj(IncFile).dLineNumber
  Destroy@Stacklist pArgStack
  xor eax, eax
  ret
RenderMacroCall endp

