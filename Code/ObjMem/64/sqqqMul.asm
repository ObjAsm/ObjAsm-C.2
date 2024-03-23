; ==================================================================================================
; Title:      sqqqMul.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  sqqqMul
; Purpose:    Multiply 2 signed QWORDs.
;             (64 bit) Multiplicand multiplied by (64 bit) Multiplier = (64 bit) Product.
; Arguments:  Arg1: Multiplicand low signed word.
;             Arg2 Multiplicand high signed word.
;             Arg3 Multiplier low signed word.
;             Arg4 Multiplier high signed word.
; Return:     rdx:rax = Signed product.

align ALIGN_CODE
sqqqMul proc sdMultiplicandLo:SDWORD, sdMultiplicandHi:SDWORD, \
             sdMultiplierLo:SDWORD, sdMultiplierHi:SDWORD
  mov rax, SQWORD ptr sdMultiplicandLo
  imul SQWORD ptr sdMultiplierLo
  ret
sqqqMul endp

end

