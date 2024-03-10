; ==================================================================================================
; Title:      MulDiv64.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  MulDiv64
; Purpose:    Multiply 2 SQWORDs and divide the product by another SQWORD with 128 bit precision.
; Arguments:  Arg1: Multiplicand.
;             Arg2: Multiplier.
; Return:     rdx:rax = Product.

MulDiv64 proc uses rbx sqMultiplicand:SQWORD, sqMultiplier:SQWORD, sqDivisor:SQWORD
  mov rax, sqMultiplier
  cqo                                                 ;Sign extend to rdx:rax
  mov rbx, rdx
  mov rax, sqMultiplicand
  cqo                                                 ;Sign extend to rdx:rax

  invoke sowordMul, sqMultiplicand, rdx, sqMultiplier, rbx
  mov rcx, rax
  mov rbx, rdx
  mov rax, sqDivisor
  cqo                                                 ;Sign extend to rdx:rax
  mov rax, rdx

  invoke sowordDiv, rcx, rbx, sqDivisor, rax
  ret
MulDiv64 endp


end

