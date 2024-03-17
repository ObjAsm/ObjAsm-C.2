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
; Arguments:  Arg1: Dividend signed low word.
;             Arg2: Dividend signed high word.
;             Arg3: Divisor signed low word.
;             Arg4: Divisor signed high word.
; Return:     rax = edx::eax = Quotient.

align ALIGN_CODE
sqwordDiv proc sdDividendLo:SDWORD, sdDividendHi:SDWORD, \
               sdDivisorLo:SDWORD, sdDivisorHi:SDWORD
  mov rax, SQWORD ptr sdDividendLo
  xor edx, edx
  idiv SQWORD ptr sdDivisorLo
  mov rdx, rax
  shr rdx, 32 
  ret
  
sqwordDiv endp

end

