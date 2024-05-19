; ==================================================================================================
; Title:      h2inc+_RenderEnumMember.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:    ObjAsm h2inc+ translation procedures.
; ==================================================================================================


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  RenderEnumMember
; Purpose:    Render an enumerator declaration (member of an enumeration).
; Arguments:  Arg1 -> Token.
;             xbx -> IncFile.
; Return:     xax -> Last Token, usually ';' or NULL if failed.

RenderEnumMember proc pToken:PTOKEN
  GED_MacroInvocation macro
    invoke IsMacro?, pToken
    .if eax != 0
      mov edx, ecx
      .if eax == 1
        OCall pNewMacros::List.ItemAt, edx
      .else
        OCall pKnwMacros::List.ItemAt, edx
      .endif
      mov edx, [xax - sizeof(DWORD)]                    ;edx = length
      invoke RenderMacroCall, pToken, DWORD ptr [xax + xdx], FALSE
      mov bFirstToken, FALSE
      jmp @GetNextToken
    .endif
  endm

  local sdValue:SDWORD, dStep:DWORD, bFirstToken:DWORD, bNegative:DWORD, cTransBuffer[128]:CHRA

  OCall $ObjTmpl(Application)::Application.ShowInfo, VERBOSITY_DEAFENING, $OfsCStr("RenderEnumMember")
  mov xax, pToken                                       ;Use token passed to this proc
  mov sdValue, 0
  .while TRUE
    mov dStep, 0
    mov bFirstToken, TRUE
    .while TRUE
      test xax, xax
      jz @ErrorEoF
      cmp CHRA ptr [xax], ';'                           ;Statement terminator
      jz @ErrorSyntax

      .if dStep == 0
        .if CHRA ptr [xax] == ',' || CHRA ptr [xax] == '}'  ;Item terminator or end of declaration
          .break
        .endif

        GED_MacroInvocation

        mov xax, pToken
        lea xdx, cTransBuffer
        invoke TranslateReservedWord, xax, xdx
        OCall xbx::IncFile.StmWrite, xax
        mov dStep, 1
        jmp @GetNextToken
      .endif

      .if dStep == 1
        mov xax, pToken
        .if CHRA ptr [xax] == ',' || CHRA ptr [xax] == '}'  ;Item terminator or end of declaration
          OCall xbx::IncFile.StmWriteF, $OfsCStrA(" equ %d"), sdValue
          inc sdValue
          OCall xbx::IncFile.StmWriteEoL
          .break
        .endif

        .if CHRA ptr [xax] == "="
          OCall xbx::IncFile.StmWrite, $OfsCStrA(" equ ") ;Use equ (unchangeable)
          mov bFirstToken, TRUE
          mov bNegative, FALSE
          mov dStep, 2
          jmp @GetNextToken
        .endif
      .endif

      .if dStep == 2
        .if bFirstToken != FALSE
          .if CHRA ptr [xax] == ',' || CHRA ptr [xax] == '}'
            OCall xbx::IncFile.StmWriteF, $OfsCStrA("%d"), sdValue
            inc sdValue
            OCall xbx::IncFile.StmWriteEoL
            .break
          .endif
        .else
          .if CHRA ptr [xax] == ',' || CHRA ptr [xax] == '}'
            OCall xbx::IncFile.StmDeleteLastSpace
            OCall xbx::IncFile.StmWriteEoL
            .break
          .endif
        .endif

        GED_MacroInvocation

        mov xax, pToken
        .if CHRA ptr [xax] == '('                     ;On enumerations, we will skip ... = (int) xxxx
          mov bFirstToken, FALSE
          invoke SkipBraces, '(', ')'
          test xax, xax
          jz @ErrorEoF
          jmp @GetNextToken
        .endif

        .if (CHRA ptr [xax] == "-" || CHRA ptr [xax] == "+") && bFirstToken != FALSE
          .if CHRA ptr [xax] == "-"
            mov bNegative, TRUE
          .endif
          OCall xbx::IncFile.StmWrite, xax
          mov bFirstToken, FALSE
          jmp @GetNextToken
        .endif

        invoke TranslateNumOperator, xax
        OCall xbx::IncFile.StmWrite, xax
        OCall xbx::IncFile.StmWriteChar, SPC
        mov bFirstToken, FALSE

        mov xax, pToken
        .if CHRA ptr [xax] >= "0"
          invoke dec2dwordA, pToken
          inc eax                                       ;Increment for next enum item
          .if bNegative != FALSE
            neg eax
            inc eax
          .endif
          mov sdValue, eax
        .endif
      .endif

@GetNextToken:
      mov pToken, $OCall(xbx::IncFile.GetNextTokenC)
    .endw
    mov xax, pToken
    .break .if CHRA ptr [xax] == '}'                    ;Statment terminator
    mov pToken, $OCall(xbx::IncFile.GetNextTokenC)
  .endw

  ;Exit ---------------------------------------------------------------------------------
@Exit:
  mov xax, pToken
  ret

@ErrorSyntax:
  OCall xbx::IncFile.ShowError, $OfsCStr("RenderEnumMember")
  OCall xbx::IncFile.StmWriteError
  invoke GotoNextToken, addr szSemiColon
  ret

@ErrorEoF:
  inc [xbx].$Obj(IncFile).dErrorCount
  xor eax, eax
  ret
RenderEnumMember endp
