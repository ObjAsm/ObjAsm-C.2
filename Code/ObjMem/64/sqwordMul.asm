; ==================================================================================================
; Title:      sqwordMul.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  sqwordMul
; Purpose:    Multiply 2 signed QWORDs.
; Arguments:  Arg1: Multiplicand low signed word.
;             Arg2 Multiplicand high signed word.
;             Arg3 Multiplier low signed word.
;             Arg4 Multiplier high signed word.
; Return:     rdx:rax = Product.

align ALIGN_CODE
sqwordMul proc sdMultiplicandLo:SDWORD, sdMultiplicandHi:SDWORD, \
               sdMultiplierLo:SDWORD, sdMultiplierHi:SDWORD
  mov rax, SQWORD ptr sdMultiplicandLo
  imul SQWORD ptr sqMultiplierLo
  ret
sqwordMul endp

end

