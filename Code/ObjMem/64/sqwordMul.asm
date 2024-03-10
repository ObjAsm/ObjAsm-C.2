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
; Arguments:  Arg1: Multiplicand.
;             Arg2: Multiplier.
; Return:     rdx:rax = Product.

align ALIGN_CODE
sqwordMul proc sqMultiplicand:SQWORD, sqMultiplier:SQWORD
  mov rax, sqMultiplicand
  imul sqMultiplier
  ret
sqwordMul endp

end

