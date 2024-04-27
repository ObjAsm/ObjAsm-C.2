; ==================================================================================================
; Title:      h2inc+_Handler.inc
; Author:     G. Friedrich
; Version:    C.2.0
; Purpose:    ObjAsm h2inc+ Handler routines.
; Notes:      See h2inc+.asm
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  PPCH_Define
; Purpose:    PP Command Handler for "#define".
; Arguments:  xsi -> input token stream.
; Return:     Nothing.
; Note:       If a macro is defined and an argument name is a reseved word, it is converted. In the
;             following exitm, only reserved words are converted that were converted previously.

PPCH_Define proc uses xdi xsi
  local pName:PSTRINGA, pToken:PTOKEN, dSize:DWORD
  local dParams:DWORD, bMacro:BYTE, bAddSpace:BYTE, pArgStack:POINTER, bFirstParam:DWORD
  local pStmOutPos:POINTER, cTransBuffer[128]:CHRA

  m2m pStmOutPos, [xbx].$Obj(IncFile).pStmOutPos, xax

  OCall xbx::IncFile.GetNextTokenPP                     ;Get the name of constant/macro
  .if !ZERO?
    mov pName, xax
    invoke TranslateReservedWord, pName, addr cTransBuffer
    OCall xbx::IncFile.StmWrite, xax
    mov xax, [xbx].$Obj(IncFile).pStmInpPos
    .if WORD ptr [xax] == PCT_MACRO
      mov bMacro, TRUE
    .else
      mov bMacro, FALSE
    .endif
    .if bMacro != FALSE
      OCall xbx::IncFile.GetNextTokenPP                 ;Skip PCT_MACRO
      OCall xbx::IncFile.GetNextTokenPP                 ;Skip "("
      OCall xbx::IncFile.StmWrite, $OfsCStrA(" macro ")

      ;Write the macro params
      invoke SkipSimpleBraces

      mov pArgStack, $Create@Stacklist()
      mov dParams, 0
      .while TRUE
        OCall xbx::IncFile.GetNextTokenPP
        .break .if ZERO?
        .break .if CHRA ptr [xax] == ")"
        mov pToken, xax
        .if CHRA ptr [xax] == ","
          mov xax, $OfsCStrA(", ")
        .else
          inc dParams
          invoke TranslateReservedWord, xax, addr cTransBuffer
          .if edx != 0
            ;Translation occurred
            Add@Stacklist pArgStack, pToken           ;Does NOT change xax
          .endif
        .endif
        OCall xbx::IncFile.StmWrite, xax
      .endw
      OCall xbx::IncFile.StmWriteEOL

      ;Save macro name in symbol table
      invoke IsMacro?, pName                          ;Check if we know this macro
      .if eax == 0
        invoke StrSizeA, pName
        mov dSize, eax
        .if dParams > 0
          mov eax, MCF_HAS_PARAMS
        .else
          xor eax, eax
        .endif
        invoke InsertAttr, pMacros, pName, dSize, eax
      .endif

      OCall xbx::IncFile.StmWrite, $OfsCStrA("  exitm ", 3Ch)   ;"  exitm <", incl. 2 spc 4 indent.
      invoke SkipCasts

      mov bAddSpace, TRUE
      mov bFirstParam, TRUE
      .while TRUE
        OCall xbx::IncFile.GetNextTokenPP
        .break .if ZERO?
        mov xsi, xax
        .continue .if CHRA ptr [xsi] == ")"
        .if bFirstParam == FALSE && CHRA ptr [xsi] != ")" && CHRA ptr [xsi] != "," && bAddSpace != FALSE && CHRA ptr [xax] != "."
          OCall xbx::IncFile.StmWriteChar, SPC
        .endif
        invoke IsMacro?, xsi
        .if eax != 0
          OCall xbx::IncFile.PeekNextTokenC
          .if !ZERO? && CHRA ptr [xax] == "("
            mov bAddSpace, FALSE
          .else
            mov bAddSpace, TRUE
          .endif
        .else
          mov bAddSpace, FALSE
          cmp CHRA ptr [xsi], "("
          setne bAddSpace
        .endif

        ;Check if the reserved word is an argument
        mov edi, $GetCount@Stacklist(pArgStack)
        .while edi != 0
          dec edi
          mov xax, $GetItem@Stacklist(pArgStack, edi)
          invoke StrCompA, xax, xsi
          .if eax == 0
            invoke TranslateReservedWord, xsi, addr cTransBuffer   ;Yes => translate it
            mov xsi, xax
            .break
          .endif
        .endw
        .if edx == FALSE || edi == 0                  ;No translation
          invoke TranslateNumOperator, xsi            ;  => try to handle it as an numeric operator
        .endif
        OCall xbx::IncFile.StmWrite, xax
        mov bFirstParam, FALSE
      .endw
      Destroy@Stacklist pArgStack

      OCall xbx::IncFile.StmWriteChar, 3Eh            ;>
      OCall xbx::IncFile.StmWriteEOL
      OCall xbx::IncFile.StmWrite, $OfsCStrA("endm")
      OCall xbx::IncFile.StmWriteEOL
    .else
      invoke IsEquate?, pName                         ;Check if it already exist
      .if eax == FALSE
        invoke StrSizeA, pName
        invoke InsertAttr, pEquates, pName, eax, 0
      .endif
      OCall xbx::IncFile.StmWrite, $OfsCStrA(" equ ")
      invoke SkipSimpleBraces
      invoke ParseEqu, pName
    .endif
  .endif

;  .ifBitSet $ObjTmpl(Application).Options.dSelectiveOutput, OUTPUT_CONSTANTS
;    mrm pStmOutPos, [xbx].$Obj(IncFile).pStmOutPos, xcx
;    mov CHRA ptr [xcx], 0
;  .endif
  ret
PPCH_Define endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  PPCH_Undef
; Purpose:    PP Command Handler for "#undef".
; Arguments:  xsi -> Input token stream.
; Return:     Nothing.

PPCH_Undef proc
  ;Consume tokens until EOL
  SkipPPLine
  ret
PPCH_Undef endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  PPCH_Include
; Purpose:    PP Command Handler for "#include".
; Arguments:  xsi -> input token stream.
;             xbx -> IncFile.
; Return:     Nothing

PPCH_Include proc uses xsi xdi
  local pPath:PSTRINGA, cIncludeFile[1024]:CHRW

  OCall xbx::IncFile.StmWrite, $OfsCStrA("include ")
  OCall xbx::IncFile.GetNextTokenPP
  .if !ZERO? && CHRA ptr [xax] == "<"
    OCall xbx::IncFile.GetNextTokenPP
  .endif
  mov pPath, xax
  mov xdi, [xbx].$Obj(IncFile).pStmOutPos
  mov xsi, pPath
  .if xsi != NULL
    mov dh, 0
    .if CHRA ptr [xsi] == '"'
      inc xsi
      mov dh, '"'
    .endif
    .while CHRA ptr [xsi] != 0
      lodsb
      .break .if al == dh
      .break .if al == 0
      stosb
    .endw
    mov ax, [xdi - 2]
    or ah, 20h
    .if ax == "h."
      .if $ObjTmpl(Application).Options.bProcessInclude != FALSE
        pushax
        mov al, 0
        stosb
        invoke StrA2StrW, addr cIncludeFile, [xbx].$Obj(IncFile).pStmOutPos
        OCall $ObjTmpl(Application)::Application.ProcessFile, [xbx].$Obj(IncFile).pHeaderFilePath, addr cIncludeFile, xbx   ;Ignore result and continue
        popax
      .endif
      dec xdi
      dec xdi
      mov eax, "cni."
      stosd
    .endif
    mov ax, 0A0Dh
    stosw
    mov [xbx].$Obj(IncFile).dStmOutEOL, TRUE
  .endif
  mov [xbx].$Obj(IncFile).pStmOutPos, xdi
  mov al, 0
  stosb
  ret
PPCH_Include endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  PPCH_Error
; Purpose:    PP Command Handler for "#error".
; Arguments:  None.
; Return:     Nothing.

PPCH_Error proc uses xsi
  local pToken:PTOKEN

  OCall xbx::IncFile.StmWrite, $OfsCStrA(".err ", 3Ch)   ;"<"
  xor esi, esi
  .while TRUE
    OCall xbx::IncFile.GetNextTokenPP
    .break .if ZERO?
    mov pToken, xax
    .if esi != 0
      OCall xbx::IncFile.StmWriteChar, " "
    .endif
    OCall xbx::IncFile.StmWrite, pToken
    inc esi
  .endw
  OCall xbx::IncFile.StmWriteChar, 3Eh                ;">"
  OCall xbx::IncFile.StmWriteEOL
  ret
PPCH_Error endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  PPCH_Pragma
; Purpose:    PP Command Handler for "#pragma".
; Arguments:  None.
; Return:     Nothing.

PPCH_Pragma proc uses xsi
  local InpStat:INP_STAT, dParenthesesCount:DWORD, pToken:PTOKEN

  OCall xbx::IncFile.InputStatusSave, addr InpStat
  OCall xbx::IncFile.GetNextTokenPP
  .if !$DoesStringMatchA?([xax], <message>)
    OCall xbx::IncFile.InputStatusLoad, addr InpStat
    jmp @NotMessage
  .endif

  ;Handle "#pragma message(...)"
  OCall xbx::IncFile.GetNextTokenPP           ;skip "("
  .if !ZERO?
    OCall xbx::IncFile.StmWrite, $OfsCStrA("echo ")
    mov dParenthesesCount, 1
    xor esi, esi
    .while TRUE
      OCall xbx::IncFile.GetNextTokenPP
;      jz @Error
      .if CHRA ptr [xax] == "("
        inc dParenthesesCount
      .elseif CHRA ptr [xax] == ")"
        dec dParenthesesCount
      .endif
      .break .if ZERO? || xax == NULL
      .if esi == 0
        mov pToken, xax
        OCall xbx::IncFile.StmWriteChar, " "
        mov xax, pToken
      .endif
      .if CHRA ptr [xax] == '"'
        inc xax
        mov pToken, xax
        invoke StrLengthA, xax
        mov xcx, pToken
        mov CHRA ptr [xcx + xax - 1], 0
        mov xax, xcx
      .endif
      OCall xbx::IncFile.StmWrite, xax
      inc esi
    .endw
    .if xax != NULL
      SkipPPLine
    .endif
    mov xcx, [xbx].$Obj(IncFile).pStmOutPos
    ;Check if last character is a ",". This causes %echo to continue with next line!
    mov al, CHRA ptr [xcx - 1]
    .if al == ","
      OCall xbx::IncFile.StmWriteChar, "'"
    .endif
    OCall xbx::IncFile.StmWriteEOL
  .endif
  ret

@NotMessage:
;    OCall xbx::IncFile.StmWrite, $OfsCStrA(";#pragma")
;    OCall xbx::IncFile.StmCopyRestOfPPLine
  .while TRUE
    OCall xbx::IncFile.GetNextTokenPP
    .break .if ZERO?
  .endw
  ret
PPCH_Pragma endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————

PPCH_Beg macro
;    int 3
;    DbgHex [xbx].$Obj(IncFile).bSkipScanPP
;    DbgHex [xbx].$Obj(IncFile).bSkipLogiPP
;    DbgHex [xbx].$Obj(IncFile).dIndentation
;    DbgHex [xbx].$Obj(IncFile).bCondIfLevel
endm

PPCH_End macro
;    int 3
;    DbgHex [xbx].$Obj(IncFile).bSkipScanPP
;    DbgHex [xbx].$Obj(IncFile).bSkipLogiPP
;    DbgHex [xbx].$Obj(IncFile).dIndentation
;    DbgHex [xbx].$Obj(IncFile).bCondIfLevel
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  PPCH_If
; Purpose:    PP Command Handler for "#if".
; Arguments:  None.
; Return:     Nothing.

PPCH_If proc
;  DbgText "if"
  PPCH_Beg
  movzx ecx, [xbx].$Obj(IncFile).bCondIfLevel
  .if ecx == 0 || (ecx != 0 && [xbx].$Obj(IncFile).bCondResult[xcx - 1] != PPR_FALSE)
    IncIfLevel
    invoke If_ElIf, PCT_IF
  .else
    SkipPPLine
  .endif
  inc [xbx].$Obj(IncFile).dIndentation
  PPCH_End
  ret
PPCH_If endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  PPCH_ElIf
; Purpose:    PP Command Handler for "#elif".
; Arguments:  None.
; Return:     Nothing.

PPCH_ElIf proc uses xsi
;    DbgText "elif"
  PPCH_Beg
  dec [xbx].$Obj(IncFile).dIndentation

  movzx esi, [xbx].$Obj(IncFile).bCondIfLevel
  .if (esi == 1) || (esi > 1 && [xbx].$Obj(IncFile).bCondResult[xsi - 2] != PPR_FALSE)
    IncElseLevel
    invoke If_ElIf, PCT_ELIF
    inc [xbx].$Obj(IncFile).dIndentation
  .else
    SkipPPLine
    mov [xbx].$Obj(IncFile).bSkipLogiPP, TRUE
    mov [xbx].$Obj(IncFile).bSkipC, TRUE
  .endif
  PPCH_End
  ret
PPCH_ElIf endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  PPCH_Else
; Purpose:    PP Command Handler for "#else".
; Arguments:  None.
; Return:     Nothing.

PPCH_Else proc uses xsi
;    DbgText "else"
  PPCH_Beg
  movzx esi, [xbx].$Obj(IncFile).bCondIfLevel
  .if (esi == 1) || (esi > 1 && [xbx].$Obj(IncFile).bCondResult[xsi - 2] != PPR_FALSE)
    dec [xbx].$Obj(IncFile).dIndentation
    IncElseLevel
    OCall xbx::IncFile.StmWrite, $OfsCStrA("else")
    OCall xbx::IncFile.StmWriteEOL
    mov [xbx].$Obj(IncFile).bSkipUselessCode, FALSE
    OCall xbx::IncFile.StmSkipRestOfPPLine
    inc [xbx].$Obj(IncFile).dIndentation
    .if [xbx].$Obj(IncFile).bCondHistory[xsi - 1] == PPR_TRUE
      mov [xbx].$Obj(IncFile).bCondResult[xsi - 1], PPR_FALSE
      mov [xbx].$Obj(IncFile).bSkipLogiPP, TRUE
      mov [xbx].$Obj(IncFile).bSkipC, TRUE
    .else
      .if [xbx].$Obj(IncFile).bCondHistory[xsi - 1] == PPR_FALSE
        mov [xbx].$Obj(IncFile).bCondResult[xsi - 1], PPR_TRUE
        mov [xbx].$Obj(IncFile).bSkipLogiPP, FALSE
        mov [xbx].$Obj(IncFile).bSkipC, FALSE
        mov [xbx].$Obj(IncFile).bCondHistory[xsi - 1], PPR_TRUE
      .else
        mov [xbx].$Obj(IncFile).bCondResult[xsi - 1], PPR_UNKNOWN
        mov [xbx].$Obj(IncFile).bSkipLogiPP, FALSE
        mov [xbx].$Obj(IncFile).bSkipC, FALSE
        mov [xbx].$Obj(IncFile).bCondHistory[xsi - 1], PPR_UNKNOWN
      .endif
    .endif
  .else
    SkipPPLine
    mov [xbx].$Obj(IncFile).bSkipLogiPP, TRUE
    mov [xbx].$Obj(IncFile).bSkipC, TRUE
  .endif
  PPCH_End
  ret
PPCH_Else endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  PPCH_Endif
; Purpose:    PP Command Handler for "#endif".
; Arguments:  None.
; Return:     Nothing.

PPCH_Endif proc uses xsi
;  DbgText "endif"
  PPCH_Beg
  dec [xbx].$Obj(IncFile).dIndentation
  DecIfLevel

  movzx esi, [xbx].$Obj(IncFile).bCondIfLevel
  .if (esi == 0) || (esi > 0) && ([xbx].$Obj(IncFile).bCondResult[xsi - 1] != PPR_FALSE)
    OCall xbx::IncFile.StmWrite, $OfsCStrA("endif")
    mov [xbx].$Obj(IncFile).bSkipUselessCode, FALSE
    OCall xbx::IncFile.StmSkipRestOfPPLine
    mov [xbx].$Obj(IncFile).bSkipLogiPP, FALSE
    mov [xbx].$Obj(IncFile).bSkipC, FALSE
  .else
    SkipPPLine
    mov [xbx].$Obj(IncFile).bSkipLogiPP, TRUE
    mov [xbx].$Obj(IncFile).bSkipC, TRUE
  .endif
  PPCH_End
  ret
PPCH_Endif endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  PPCH_Ifdef
; Purpose:    PP Command Handler for "#ifdef".
; Arguments:  None.
; Return:     Nothing.

PPCH_Ifdef proc
;  DbgText "ifdef"
  PPCH_Beg
  movzx ecx, [xbx].$Obj(IncFile).bCondIfLevel
  .if ecx == 0 || (ecx != 0 && [xbx].$Obj(IncFile).bCondResult[xcx - 1] != PPR_FALSE)
    IncIfLevel
    invoke Ifdef_Ifndef, PCT_IFDEF
  .else
    SkipPPLine
  .endif
  mov [xbx].$Obj(IncFile).bSkipUselessCode, FALSE
  inc [xbx].$Obj(IncFile).dIndentation
  PPCH_End
  ret
PPCH_Ifdef endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  PPCH_Ifndef
; Purpose:    PP Command Handler for "#ifndef".
; Arguments:  None.
; Return:     Nothing.

PPCH_Ifndef proc
;  DbgText "ifndef"
  PPCH_Beg
  movzx ecx, [xbx].$Obj(IncFile).bCondIfLevel
  .if ecx == 0 || (ecx != 0 && [xbx].$Obj(IncFile).bCondResult[xcx - 1] != PPR_FALSE)
    IncIfLevel
    invoke Ifdef_Ifndef, PCT_IFNDEF
  .else
    SkipPPLine
  .endif
  inc [xbx].$Obj(IncFile).dIndentation
  PPCH_End
  ret
PPCH_Ifndef endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  PPCH_IfNP
; Purpose:    PP Command Handler for "#if" only when IncFile.bSkipLogiPP == TRUE.
; Arguments:  None.
; Return:     Nothing.

PPCH_IfNP proc uses xsi
;  DbgText "ifNP"
  PPCH_Beg
  IncIfLevel
  movzx esi, [xbx].$Obj(IncFile).bCondIfLevel
  mov [xbx].$Obj(IncFile).bCondResult[xsi - 1], PPR_FALSE
  mov [xbx].$Obj(IncFile).bCondHistory[xsi - 1], PPR_FALSE
  mov [xbx].$Obj(IncFile).bSkipLogiPP, TRUE
  mov [xbx].$Obj(IncFile).bSkipC, TRUE

  SkipPPLine
  inc [xbx].$Obj(IncFile).dIndentation
  PPCH_End
  ret
PPCH_IfNP endp
