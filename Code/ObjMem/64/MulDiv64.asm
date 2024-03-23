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
; Purpose:    Multiply 2 signed QWORDs and divide the product by another signed QWORD 
;             with 128 bit precision.
;             (64 bit) Multiplicand multiplied by (64 bit) Multiplier divided by (64 bit) Divisor = 
;             (128 bit) Result. 
; Arguments:  Arg1: Signed multiplicand.
;             Arg2: Signed multiplier.
;             Arg3: Signed divisor.
; Return:     rdx:rax = Signed result.

MulDiv64 proc uses rbx sqMultiplicand:SQWORD, sqMultiplier:SQWORD, sqDivisor:SQWORD
  mov rax, sqMultiplier
  cqo                                                 ;Sign extend to rdx:rax
  mov rbx, rdx
  mov rax, sqMultiplicand
  cqo                                                 ;Sign extend to rdx:rax

  invoke soooMul, sqMultiplicand, rdx, sqMultiplier, rbx
  mov rcx, rax
  mov rbx, rdx
  mov rax, sqDivisor
  cqo                                                 ;Sign extend to rdx:rax
  mov rax, rdx

  invoke soooDiv, rcx, rbx, sqDivisor, rax
  ret
MulDiv64 endp


end

