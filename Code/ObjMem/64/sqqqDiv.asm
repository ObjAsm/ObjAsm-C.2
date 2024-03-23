; ==================================================================================================
; Title:      sqqqDiv.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  sqqqDiv
; Purpose:    Divide 2 signed QWORDs.
;             (64 bit) Dividend divided by (64 bit) Divisor = (64 bit) Quotient. 
; Arguments:  Arg1: Dividend signed low word.
;             Arg2: Dividend signed high word.
;             Arg3: Divisor signed low word.
;             Arg4: Divisor signed high word.
; Return:     rax = edx::eax = Signed quotient.

align ALIGN_CODE
sqqqDiv proc sdDividendLo:SDWORD, sdDividendHi:SDWORD, \
             sdDivisorLo:SDWORD, sdDivisorHi:SDWORD
  mov rax, SQWORD ptr sdDividendLo
  xor edx, edx
  idiv SQWORD ptr sdDivisorLo
  mov rdx, rax
  shr rdx, 32 
  ret
  
sqqqDiv endp

end

