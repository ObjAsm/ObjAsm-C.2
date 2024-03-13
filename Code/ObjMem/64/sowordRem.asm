; ==================================================================================================
; Title:      sowordRem.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
;               - Inspired by Microsoft's llRem.asm (nt5src-master).
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  sowordRem
; Purpose:    Calculate the remainder of the division of 2 signed OWORDs.
; Arguments:  Arg1: Dividend.
;             Arg2: Divisor.
; Return:     rdx:rax = Remainder.

align ALIGN_CODE
sowordRem proc uses rdi rsi sqDividendLo:SQWORD, qDividendHi:SQWORD, \
                            sqDivisorLo:SQWORD, sqDivisorHi:SQWORD
; Determine sign of the result (edi = 0 if result is positive, non-zero otherwise)
; and make operands positive.
  xor edi, edi                                          ;Result sign assumed positive
  mov rax, sqDividendHi                                 ;Hi-word of dividend
  or rax, rax                                           ;Test to see if signed
  jge short L1                                          ;Skip rest if dividend is already positive
  inc rdi                                               ;Complement result sign flag
  mov rdx, sqDividendLo                                 ;Lo-word of dividend
  neg rax                                               ;Make dividend positive
  neg rdx
  sbb rax, 0
  mov sqDividendHi, rax                                 ;Save positive value
  mov sqDividendLo, rdx
L1:
  mov rax, sqDivisorHi                                  ;Hi-word of divisor
  or rax, rax                                           ;Test to see if signed
  jge short L2                                          ;Skip rest if divisor is already positive
  inc rdi                                               ;Complement the result sign flag
  mov rdx, sqDivisorLo                                  ;Lo-word of dividend
  neg rax                                               ;Make divisor positive
  neg rdx
  sbb rax, 0
  mov sqDivisorHi, rax                                  ;Save positive value
  mov sqDivisorLo, rdx
L2:

; Now do the divide. First look to see if the divisor is less than 18446744073G.
; If so, then we can use a simple algorithm with word divides, otherwise
; things get a little more complex.
;
; NOTE - eax currently contains the high order word of sqDivisor
  or rax, rax                                           ;Check to see if divisor < 18446744073G
  jnz short L3                                          ;Nope, gotta do this the hard way
  mov rcx, sqDivisorLo                                  ;Load divisor
  mov rax, sqDividendHi                                 ;Load hi-word of dividend
  xor edx, edx
  div rcx                                               ;rdx <= remainder
  mov rax, sqDividendLo                                 ;rdx:rax <= remainder: lo-word of dividend
  div rcx                                               ;rdx <= final remainder
  mov rax, rdx                                          ;rdx:rax <= remainder
  xor rdx, rdx
  dec rdi                                               ;Check result sign flag
  jns short L4                                          ;Negate result & return
  jmp short L8                                          ;Result sign ok, return

; Here we do it the hard way. Remember, eax contains the hi-word of sqDivisor
L3:
  mov rbx, rax                                          ;rbx:rcx <= divisor
  mov rcx, sqDivisorLo
  mov rdx, sqDividendHi                                 ;rdx:rax <= dividend
  mov rax, sqDividendLo
L5:
  shr rbx, 1                                            ;Shift divisor right one bit
  rcr rcx, 1                                            
  shr rdx, 1                                            ;Shift dividend right one bit
  rcr rax, 1                                            
  or rbx, rbx                                           
  jnz short L5                                          ;Loop until divisor < 18446744073G
  div rcx                                               ;Now divide, ignore remainder

; We may be off by one, so to check, we will multiply the quotient
; by the divisor and check the result against the orignal dividend
; Note that we must also check for overflow, which can occur if the
; dividend is close to 2**64 and the quotient is off by 1.
  mov rcx, rax                                          ;Save a copy of quotient in ecx
  mul sqDivisorHi
  xchg rcx, rax                                         ;Save product, get quotient in eax
  mul sqDivisorLo
  add rdx, rcx                                          ;rdx:rax = QUOT * divisor
  jc short L6                                           ;Carry means quotient is off by 1

; Do long compare here between original dividend and the result of the
; multiply in rdx:rax. If original is larger or equal, we are ok, otherwise
; subtract one (1) from the quotient.
  cmp rdx, sqDividendHi                                 ;Compare hi-words of result and original
  ja short L6                                           ;If result > original, do subtract
  jb short L7                                           ;If result < original, we are ok
  cmp rax, sqDividendLo                                 ;Hi-words are equal, compare lo-words
  jbe short L7                                          ;If less or equal we are ok, else subtract
L6:
  sub rax, sqDivisorLo                                  ;Subtract divisor from result
  sbb rdx, sqDivisorHi
L7:

; Calculate remainder by subtracting the result from the original dividend.
; Since the result is already in a register, we will do the subtract in the
; opposite direction and negate the result if necessary.
  sub rax, sqDividendLo                      ;Subtract dividend from result
  sbb rdx, sqDividendHi

; Now check the result sign flag to see if the result is supposed to be positive
; or negative. It is currently negated (because we subtracted in the 'wrong'
; direction), so if the sign flag is set we are done, otherwise we must negate
; the result to make it positive again.
  dec rdi                                               ;Check result sign flag
  jns short L8                                          ;Result is ok, return
L4:                                                     
  neg rdx                                               ;otherwise, negate the result
  neg rax
  sbb rdx, 0

L8:
  ret
sowordRem endp

end
