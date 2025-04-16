; ==================================================================================================
; Title:      h2inc+_Handler.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:    ObjAsm h2inc+ Handler routines.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  PPCH_Define
; Purpose:    PP Command Handler for "#define".
; Arguments:  xsi -> input token stream.
; Return:     Nothing.
; Note:       If a macro is defined and an argument name is a reseved word, it is converted. In the
;             following exitm, only reserved words are converted that were converted previously.

PPCH_Define proc uses xdi xsi
  local pName:PSTRINGA, pToken:PTOKEN, dSize:DWORD
  local dParams:DWORD, bMacro:BYTE, bAddSpace:BYTE, pArgStack:POINTER, bFirstParam:DWORD
  local PrevOutStat:STMOUT_STAT, cTransBuffer[128]:CHRA

  OCall $ObjTmpl(Application)::Application.ShowInfo, VERBOSITY_DEAFENING, $OfsCStr("PPCH-Define")
  StmOutSave PrevOutStat                                ;Save output stream status
  OCall xbx::IncFile.GetNextTokenPP                     ;Get the name of constant/macro
  .if xax != NULL
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
      test xax, xax
      jz @Exit
      OCall xbx::IncFile.GetNextTokenPP                 ;Skip '('
      test xax, xax
      jz @Exit

      OCall xbx::IncFile.StmWrite, $OfsCStrA(" macro ")

      ;Write the macro params
      invoke SkipSimpleBraces

      mov pArgStack, $Create@Stacklist()
      mov dParams, 0
      .while TRUE
        OCall xbx::IncFile.GetNextTokenPP
        .break .if xax == NULL
        .break .if CHRA ptr [xax] == ')'
        mov pToken, xax
        .if CHRA ptr [xax] == ','
          mov xax, $OfsCStrA(", ")
        .else
          inc dParams
          lea xdx, cTransBuffer
          invoke TranslateReservedWord, xax, xdx
          .if edx != 0
            ;Translation occurred
            Add@Stacklist pArgStack, pToken, xcx        ;Does NOT change xax
          .endif
        .endif
        OCall xbx::IncFile.StmWrite, xax
      .endw
      OCall xbx::IncFile.StmWriteEoL

      ;Save macro name in new macros list
      invoke IsMacro?, pName                            ;Check if we know this macro
      .if eax == 0
        invoke StrSizeA, pName
        mov dSize, eax
        .if dParams > 0
          mov eax, MCF_HAS_PARAMS
        .else
          xor eax, eax
        .endif
        invoke InsertAttr, pNewMacros, pName, dSize, eax
      .endif

      OCall xbx::IncFile.StmWrite, $OfsCStrA("  exitm ", 3Ch)   ;"  exitm <", incl. 2 spc 4 indent.
      invoke SkipCasts

      mov bAddSpace, TRUE
      mov bFirstParam, TRUE
      .while TRUE
        OCall xbx::IncFile.GetNextTokenPP
        .break .if xax == NULL
        mov xsi, xax
        .if bFirstParam == FALSE && CHRA ptr [xsi] != ')' && CHRA ptr [xsi] != ',' && \
            bAddSpace != FALSE && CHRA ptr [xax] != "."
          OCall xbx::IncFile.StmWriteChar, SPC
        .endif
        invoke IsMacro?, xsi
        .if eax != 0
          OCall xbx::IncFile.PeekNextTokenC
          .if xax != NULL && CHRA ptr [xax] == '('
            mov bAddSpace, FALSE
          .else
            mov bAddSpace, TRUE
          .endif
        .else
          mov bAddSpace, FALSE
          cmp CHRA ptr [xsi], '('
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
        .if edx == FALSE || edi == 0                    ;No translation
          invoke TranslateNumOperator, xsi              ;  => try to handle it as an numeric operator
        .endif
        OCall xbx::IncFile.StmWrite, xax
        mov bFirstParam, FALSE
      .endw
      Destroy@Stacklist pArgStack

      OCall xbx::IncFile.StmWriteChar, 3Eh              ;>
      OCall xbx::IncFile.StmWriteEoL
      OCall xbx::IncFile.StmWrite, $OfsCStrA("endm")
      OCall xbx::IncFile.StmWriteEoL

    .else
      invoke IsEquate?, pName                           ;Check if it already exist
      .if eax == FALSE
        invoke StrSizeA, pName
        invoke InsertAttr, pNewEquates, pName, eax, 0
      .endif
      OCall xbx::IncFile.StmWrite, $OfsCStrA(" equ ")
      invoke SkipSimpleBraces
      invoke RenderDefineConst, pName
      OCall xbx::IncFile.StmWriteEoL
    .endif
  .endif

@Exit:
  .ifBitClr $ObjTmpl(Application).Options.dSelectiveOutput, OUTPUT_CONSTANTS
    StmOutLoad PrevOutStat                              ;Restore initial output stream status
    mov CHRA ptr [xax], 0
  .endif
  ret
PPCH_Define endp

; --------------------------------------------------------------------------------------------------
; Procedure:  PPCH_Undef
; Purpose:    PP Command Handler for "#undef".
; Arguments:  xsi -> Input token stream.
; Return:     Nothing.

PPCH_Undef proc
  OCall $ObjTmpl(Application)::Application.ShowInfo, VERBOSITY_DEAFENING, $OfsCStr("PPCH-Undef")
  ;Consume tokens until EOL
  SkipPPLine
  ret
PPCH_Undef endp

; --------------------------------------------------------------------------------------------------
; Procedure:  PPCH_Include
; Purpose:    PP Command Handler for "#include".
; Arguments:  xsi -> input token stream.
;             xbx -> IncFile.
; Return:     Nothing

PPCH_Include proc uses xsi xdi
  local pPath:PSTRINGA, cIncludeFile[1024]:CHRW
  local .xdi:XWORD, .xsi:XWORD

  OCall $ObjTmpl(Application)::Application.ShowInfo, VERBOSITY_DEAFENING, $OfsCStr("PPCH-Include")
  OCall xbx::IncFile.StmWrite, $OfsCStrA("include ")
  OCall xbx::IncFile.GetNextTokenPP
  .if xax != NULL && CHRA ptr [xax] == "<"
    OCall xbx::IncFile.GetNextTokenPP
  .endif
  mov xdi, [xbx].$Obj(IncFile).pStmOutPos
  test xax, xax
  jz @Exit
  mov pPath, xax
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
        mov .xdi, xdi
        mov .xsi, xsi
        mov al, 0
        stosb
        invoke StrA2StrW, addr cIncludeFile, [xbx].$Obj(IncFile).pStmOutPos
        OCall $ObjTmpl(Application)::Application.ProcessFile, [xbx].$Obj(IncFile).pHeaderFilePath, \
                addr cIncludeFile, xbx                  ;Ignore result and continue
        mov xdi, .xdi
        mov xsi, .xsi
      .endif
      dec xdi
      dec xdi
      mov eax, "cni."
      stosd
    .endif
    mov ax, 0A0Dh
    stosw
    mov [xbx].$Obj(IncFile).dStmOutEoL, TRUE
  .endif
@Exit:
  mov [xbx].$Obj(IncFile).pStmOutPos, xdi
  mov al, 0
  stosb
  ret
PPCH_Include endp

; --------------------------------------------------------------------------------------------------
; Procedure:  PPCH_Error
; Purpose:    PP Command Handler for "#error".
; Arguments:  None.
; Return:     Nothing.

PPCH_Error proc uses xsi
  local pToken:PTOKEN

  OCall $ObjTmpl(Application)::Application.ShowInfo, VERBOSITY_DEAFENING, $OfsCStr("PPCH-Error")
  OCall xbx::IncFile.StmWrite, $OfsCStrA(".err ", 3Ch)   ;"<"
  xor esi, esi
  .while TRUE
    OCall xbx::IncFile.GetNextTokenPP
    .break .if xax == NULL
    mov pToken, xax
    .if esi != 0
      OCall xbx::IncFile.StmWriteChar, " "
    .endif
    OCall xbx::IncFile.StmWrite, pToken
    inc esi
  .endw
  OCall xbx::IncFile.StmWriteChar, 3Eh                ;">"
  OCall xbx::IncFile.StmWriteEoL
  ret
PPCH_Error endp

; --------------------------------------------------------------------------------------------------
; Procedure:  PPCH_Pragma
; Purpose:    PP Command Handler for "#pragma".
; Arguments:  None.
; Return:     Nothing.

PPCH_Pragma proc uses xsi
  local InpStat:INP_STAT, dParenthesesCount:DWORD, pToken:PTOKEN

  OCall $ObjTmpl(Application)::Application.ShowInfo, VERBOSITY_DEAFENING, $OfsCStr("PPCH-Pragma")
  OCall xbx::IncFile.InputStatusSave, addr InpStat
  OCall xbx::IncFile.GetNextTokenPP
  test xax, xax
  jz @Exit
  .if !$DoesStringMatchA?([xax], <message>)
    OCall xbx::IncFile.InputStatusLoad, addr InpStat
    jmp @NotMessage
  .endif

  ;Handle "#pragma message(...)"
  OCall xbx::IncFile.GetNextTokenPP                     ;skip '('
  .if xax != NULL
    OCall xbx::IncFile.StmWrite, $OfsCStrA("echo ")
    mov dParenthesesCount, 1
    xor esi, esi
    .while TRUE
      OCall xbx::IncFile.GetNextTokenPP
      test xax, xax
      jz @Exit
      .if CHRA ptr [xax] == '('
        inc dParenthesesCount
      .elseif CHRA ptr [xax] == ')'
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
    ;Check if last character is a ','. This causes %echo to continue with next line!
    mov al, CHRA ptr [xcx - 1]
    .if al == ','
      OCall xbx::IncFile.StmWriteChar, "'"
    .endif
@Exit:
    OCall xbx::IncFile.StmWriteEoL
  .endif
  ret

@NotMessage:
;    OCall xbx::IncFile.StmWrite, $OfsCStrA(";#pragma")
;    OCall xbx::IncFile.StmCopyRestOfPPLine
  .while TRUE
    OCall xbx::IncFile.GetNextTokenPP
    .break .if xax == NULL
  .endw
  ret
PPCH_Pragma endp

; --------------------------------------------------------------------------------------------------

PPCH_Beg macro
;    int 3
;    DbgHex [xbx].$Obj(IncFile).bSkipLinePP
;    DbgHex [xbx].$Obj(IncFile).bSkipCondPP
;    DbgHex [xbx].$Obj(IncFile).dIndentation
;    DbgHex [xbx].$Obj(IncFile).bCondIfLevel
endm

PPCH_End macro
;    int 3
;    DbgHex [xbx].$Obj(IncFile).bSkipLinePP
;    DbgHex [xbx].$Obj(IncFile).bSkipCondPP
;    DbgHex [xbx].$Obj(IncFile).dIndentation
;    DbgHex [xbx].$Obj(IncFile).bCondIfLevel
endm

; --------------------------------------------------------------------------------------------------
; Procedure:  PPCH_If
; Purpose:    PP Command Handler for "#if".
; Arguments:  None.
; Return:     Nothing.

PPCH_If proc
;  DbgText "if"
  OCall $ObjTmpl(Application)::Application.ShowInfo, VERBOSITY_DEAFENING, $OfsCStr("PPCH-If")
  PPCH_Beg
  movzx ecx, [xbx].$Obj(IncFile).bCondIfLevel
  .if ecx == 0 || (ecx != 0 && [xbx].$Obj(IncFile).bCondResult[xcx - 1] != PPR_FALSE)
    IncIfLevel
    invoke If_ElIf, PCT_IF
    inc [xbx].$Obj(IncFile).dIndentation                ;Following C-code is indented
  .else
    SkipPPLine                                          ;CondResut = FALSE => skip the PP-Line
  .endif
  PPCH_End
  ret
PPCH_If endp

; --------------------------------------------------------------------------------------------------
; Procedure:  PPCH_ElIf
; Purpose:    PP Command Handler for "#elif".
; Arguments:  None.
; Return:     Nothing.

PPCH_ElIf proc uses xsi
;    DbgText "elif"
  OCall $ObjTmpl(Application)::Application.ShowInfo, VERBOSITY_DEAFENING, $OfsCStr("PPCH-Elif")
  PPCH_Beg
  movzx esi, [xbx].$Obj(IncFile).bCondIfLevel
  .if (esi == 1) || (esi > 1 && [xbx].$Obj(IncFile).bCondResult[xsi - 2] != PPR_FALSE)
    dec [xbx].$Obj(IncFile).dIndentation
    IncElseLevel
    invoke If_ElIf, PCT_ELIF
    inc [xbx].$Obj(IncFile).dIndentation
  .else
    SkipPPLine
    mov [xbx].$Obj(IncFile).bSkipCondPP, TRUE
    mov [xbx].$Obj(IncFile).bSkipLineC, TRUE
  .endif
  PPCH_End
  ret
PPCH_ElIf endp

; --------------------------------------------------------------------------------------------------
; Procedure:  PPCH_Else
; Purpose:    PP Command Handler for "#else".
; Arguments:  None.
; Return:     Nothing.

PPCH_Else proc uses xsi
;    DbgText "else"
  OCall $ObjTmpl(Application)::Application.ShowInfo, VERBOSITY_DEAFENING, $OfsCStr("PPCH-Else")
  PPCH_Beg
  movzx esi, [xbx].$Obj(IncFile).bCondIfLevel
  .if (esi == 1) || (esi > 1 && [xbx].$Obj(IncFile).bCondResult[xsi - 2] != PPR_FALSE)
    dec [xbx].$Obj(IncFile).dIndentation
    IncElseLevel
    OCall xbx::IncFile.StmWrite, $OfsCStrA("else")
    OCall xbx::IncFile.StmWriteEoL
    OCall xbx::IncFile.StmSkipRestOfPPLine
    mov [xbx].$Obj(IncFile).bEnableNFCodeLabel, TRUE
    inc [xbx].$Obj(IncFile).dIndentation

    .if [xbx].$Obj(IncFile).bCondHistory[xsi - 1] == PPR_TRUE
      mov [xbx].$Obj(IncFile).bCondResult[xsi - 1], PPR_FALSE
      mov [xbx].$Obj(IncFile).bSkipCondPP, TRUE
      mov [xbx].$Obj(IncFile).bSkipLineC, TRUE
    .else
      .if [xbx].$Obj(IncFile).bCondHistory[xsi - 1] == PPR_FALSE
        mov [xbx].$Obj(IncFile).bCondResult[xsi - 1], PPR_TRUE
        mov [xbx].$Obj(IncFile).bSkipCondPP, FALSE
        mov [xbx].$Obj(IncFile).bSkipLineC, FALSE
        mov [xbx].$Obj(IncFile).bCondHistory[xsi - 1], PPR_TRUE
      .else
        mov [xbx].$Obj(IncFile).bCondResult[xsi - 1], PPR_UNKNOWN
        mov [xbx].$Obj(IncFile).bSkipCondPP, FALSE
        mov [xbx].$Obj(IncFile).bSkipLineC, FALSE
        mov [xbx].$Obj(IncFile).bCondHistory[xsi - 1], PPR_UNKNOWN
      .endif
    .endif
  .else
    SkipPPLine
    mov [xbx].$Obj(IncFile).bSkipCondPP, TRUE
    mov [xbx].$Obj(IncFile).bSkipLineC, TRUE
  .endif
  PPCH_End
  ret
PPCH_Else endp

; --------------------------------------------------------------------------------------------------
; Procedure:  PPCH_Endif
; Purpose:    PP Command Handler for "#endif".
; Arguments:  None.
; Return:     Nothing.

PPCH_Endif proc uses xsi
;  DbgText "endif"
  OCall $ObjTmpl(Application)::Application.ShowInfo, VERBOSITY_DEAFENING, $OfsCStr("PPCH-Endif")
  PPCH_Beg
  dec [xbx].$Obj(IncFile).dIndentation
  DecIfLevel

  movzx esi, [xbx].$Obj(IncFile).bCondIfLevel
  .if (esi == 0) || (esi > 0) && ([xbx].$Obj(IncFile).bCondResult[xsi - 1] != PPR_FALSE)
    OCall xbx::IncFile.StmWrite, $OfsCStrA("endif")
    OCall xbx::IncFile.StmWriteEoL
    mov [xbx].$Obj(IncFile).bEnableNFCodeLabel, TRUE
    OCall xbx::IncFile.StmSkipRestOfPPLine
    mov [xbx].$Obj(IncFile).bSkipCondPP, FALSE
    mov [xbx].$Obj(IncFile).bSkipLineC, FALSE
  .else
    SkipPPLine
    mov [xbx].$Obj(IncFile).bSkipCondPP, TRUE
    mov [xbx].$Obj(IncFile).bSkipLineC, TRUE
  .endif
  PPCH_End
  ret
PPCH_Endif endp

; --------------------------------------------------------------------------------------------------
; Procedure:  PPCH_Ifdef
; Purpose:    PP Command Handler for "#ifdef".
; Arguments:  None.
; Return:     Nothing.

PPCH_Ifdef proc
;  DbgText "ifdef"
  OCall $ObjTmpl(Application)::Application.ShowInfo, VERBOSITY_DEAFENING, $OfsCStr("PPCH-Ifdef")
  PPCH_Beg
  movzx ecx, [xbx].$Obj(IncFile).bCondIfLevel
  .if ecx == 0 || (ecx != 0 && [xbx].$Obj(IncFile).bCondResult[xcx - 1] != PPR_FALSE)
    IncIfLevel
    invoke Ifdef_Ifndef, PCT_IFDEF
  .else
    SkipPPLine
  .endif
  mov [xbx].$Obj(IncFile).bEnableNFCodeLabel, TRUE
  inc [xbx].$Obj(IncFile).dIndentation
  PPCH_End
  ret
PPCH_Ifdef endp

; --------------------------------------------------------------------------------------------------
; Procedure:  PPCH_Ifndef
; Purpose:    PP Command Handler for "#ifndef".
; Arguments:  None.
; Return:     Nothing.

PPCH_Ifndef proc
;  DbgText "ifndef"
  OCall $ObjTmpl(Application)::Application.ShowInfo, VERBOSITY_DEAFENING, $OfsCStr("PPCH-Ifndef")
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

; --------------------------------------------------------------------------------------------------
; Procedure:  PPCH_IfNP
; Purpose:    PP Command Handler for "#if" only when IncFile.bSkipCondPP == TRUE.
; Arguments:  None.
; Return:     Nothing.

PPCH_IfNP proc uses xsi
;  DbgText "ifNP"
  OCall $ObjTmpl(Application)::Application.ShowInfo, VERBOSITY_DEAFENING, $OfsCStr("PPCH-IfNP")
  PPCH_Beg
  IncIfLevel
  movzx esi, [xbx].$Obj(IncFile).bCondIfLevel
  mov [xbx].$Obj(IncFile).bCondResult[xsi - 1], PPR_FALSE
  mov [xbx].$Obj(IncFile).bCondHistory[xsi - 1], PPR_FALSE
  mov [xbx].$Obj(IncFile).bSkipCondPP, TRUE
  mov [xbx].$Obj(IncFile).bSkipLineC, TRUE

  SkipPPLine
  inc [xbx].$Obj(IncFile).dIndentation
  PPCH_End
  ret
PPCH_IfNP endp
