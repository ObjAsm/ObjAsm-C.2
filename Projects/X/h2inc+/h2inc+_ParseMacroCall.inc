; ==================================================================================================
; Title:      h2inc+_ParseMacroCall.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:  
; ==================================================================================================


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ParseMacroCall
; Purpose:    A known macro has been found.
; Arguments:  Arg1 -> Macro Name
;             Arg2: Macro Flags (MCF_xxx).
;             Arg3: Flag to write LF after macro invocation.
;             xbx -> IncFile.
; Return:     eax = returns TRUE if macro was invoked, otherwise FALSE (turned out to be
;             NO macro invocation).

ParseMacroCall proc pMacroName:PSTRINGA, dMacroFlags:DWORD, bWriteLF:DWORD
  local pToken:PTOKEN, pType:PSTRINGA, pName:PSTRINGA, pStmOutPos:PSTRINGA, bAddSpace:DWORD
  local dPtrCount:DWORD, dParenthesesCount:DWORD, bSkipTheRest:DWORd, pCurrToken:PTOKEN
  local dTypeCSpec:DWORD, dScanStep:DWORD, pArgStack:POINTER, cTransBuffer[128]:CHRA
  local pStr:PSTRINGA

  m2m pStmOutPos, [xbx].$Obj(IncFile).pStmOutPos, xax

  DbgPrintF , "¦UD: ParseMacroCall - found: ¦SA", \
            [xbx].$Obj(IncFile).dLineNumber, pMacroName

  .ifBitSet dMacroFlags, MCF_SKIP_INVOKATION
    OCall xbx::IncFile.PeekNextToken
    .if xax != NULL
      .if CHRA ptr [xax] == "("
        OCall xbx::IncFile.GetNextToken                 ;Consume it
        invoke SkipBraces, "(", ")"
      .endif
    .endif
    mov eax, TRUE
    ret
  .endif

  mov pArgStack, $Create@Stacklist()

  .ifBitSet dMacroFlags, MCF_INTERFACE_END
    OCall xbx::IncFile.StmWrite, $OfsCStrA("??Interface equ <>")  ;Reset ??Interface symbol
    OCall xbx::IncFile.StmWriteEOL
    mov [xbx].$Obj(IncFile).bInsideInterface, FALSE
  .endif

  OCall xbx::IncFile.PeekNextToken
  .if xax != NULL && CHRA ptr [xax] == "("
    OCall xbx::IncFile.StmWrite, pMacroName
    OCall xbx::IncFile.GetNextToken                   ;Can NOT fail, we peeked a token previously
    .ifBitClr dMacroFlags, MCF_SKIP_BRACES
      OCall xbx::IncFile.StmWrite, xax
    .else
      OCall xbx::IncFile.StmWriteChar, SPC
    .endif
    mov dParenthesesCount, 1
    mov bAddSpace, FALSE
    .while TRUE
      OCall xbx::IncFile.GetNextToken
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
          DbgPrintF , "¦UD: ParseMacroCall - Parameter = ¦SA", [xbx].$Obj(IncFile).dLineNumber, xax
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
          OCall xbx::IncFile.GetNextToken
          .break .if ZERO? || CHRA ptr [xax] == ";"     ;Statement terminator
        .else
          OCall xbx::IncFile.GetNextTokenFromPPLine
          .break .if xax == NULL
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
              DbgPrintF , "¦UD: ParseMacroCall - Param = ¦SA", [xbx].$Obj(IncFile).dLineNumber, xax
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
          jmp @Error
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
  .endif

@Done:
  .if bWriteLF != FALSE
    OCall xbx::IncFile.StmWriteEOL
  .endif
  .ifBitSet dMacroFlags, MCF_INTERFACE_BEG
    .if [xbx].$Obj(IncFile).pContainerName != NULL
      OCall xbx::IncFile.StmWriteF, $OfsCStrA("??Interface equ <%s>"), [xbx].$Obj(IncFile).pContainerName
      OCall xbx::IncFile.StmWriteEOL
      mov [xbx].$Obj(IncFile).bInsideInterface, TRUE
    .endif
  .endif
  .ifBitSet $ObjTmpl(Application).Options.dSelectiveOutput, OUTPUT_CONSTANTS
    mrm [xbx].$Obj(IncFile).pStmOutPos, pStmOutPos, xcx
    mov CHRA ptr [xcx], 0
  .endif

  .ifBitSet dMacroFlags, MCF_STRUCT_BEG
    inc [xbx].$Obj(IncFile).dIndentation
    OCall xbx::IncFile.GetNextToken
    .if CHRA ptr [xax] == "{"
      mov xcx, $GetItem@Stacklist(pArgStack, 0)
      invoke ParseBlock, xcx, PBT_CONTAINER
      invoke ParseInterfaceBlock, xcx
      dec [xbx].$Obj(IncFile).dIndentation
      OCall xbx::IncFile.StmWriteF, $OfsCStrA("END_%s"), pMacroName
      OCall xbx::IncFile.StmWriteEOL
    .else
      jmp @Error
    .endif
  .endif
  mov eax, TRUE

@Exit:
  Destroy@Stacklist pArgStack
  ret

@Error:
  DbgErrorF , "¦SU(¦UD): ParseMacroCall - error", \
              [xbx].$Obj(IncFile).pHeaderFileName, [xbx].$Obj(IncFile).dLineNumber
  Destroy@Stacklist pArgStack
  xor eax, eax
  ret
ParseMacroCall endp

