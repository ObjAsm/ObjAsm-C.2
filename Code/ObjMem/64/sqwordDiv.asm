; ==================================================================================================
; Title:      sqwordDiv.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  sqwordDiv
; Purpose:    Divide 2 signed QWORDs.
; Arguments:  Arg1: Dividend.
;             Arg2: Divisor.
; Return:     rax = Quotient.

align ALIGN_CODE
sqwordDiv proc sqDividend:SQWORD, sqDivisor:SQWORD
  mov rax, sqDividend
  xor edx, edx
  idiv sqDivisor
  ret
sqwordDiv endp

end

