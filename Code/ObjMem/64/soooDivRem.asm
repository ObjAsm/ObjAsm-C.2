; ==================================================================================================
; Title:      soooDivRem.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
;               - Inspired by Microsoft's lldvrm.asm (nt5src-master).
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  soooDivRem
; Purpose:    Divide 2 signed OWORDs.
;             (128 bit) Dividend divided by (128 bit) Divisor = (128 bit) Quotient. 
; Arguments:  Arg1: Dividend signed low word.
;             Arg2: Dividend signed high word.
;             Arg3: Divisor signed low word.
;             Arg4: Divisor signed high word.
; Return:     rdx:rax = Signed quotient.
;             rbx:rcx = Signed remainder.
; Note:       Don't include rbx in the uses clause.

.code
align ALIGN_CODE
soooDivRem proc uses rdi rsi sqDividendLo:SQWORD, sqDividendHi:SQWORD, \
                             sqDivisorLo:SQWORD, sqDivisorHi:SQWORD
  local dSign:DWORD

; Determine sign of the result (edi = 0 if result is positive, non-zero otherwise)
; and make operands positive.
  xor edi, edi                                          ;Result sign assumed positive
  mov dSign, edi                                        ;Result sign assumed positive

  mov rax, sqDividendHi                                 ;Hi-word of dividend
  or rax, rax                                           ;Test to see if signed
  jge short L1                                          ;Skip rest if dividend is already positive
  inc rdi                                               ;Complement result sign flag
  inc dSign                                             ;Complement result sign flag
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
  div rcx                                               ;rax <= high order bits of quotient
  mov rbx, rax                                          ;Save high bits of quotient
  mov rax, sqDividendLo                                 ;rdx:rax <= remainder: lo-word of dividend
  div rcx                                               ;rax <= low order bits of quotient
  mov rsi, rax                                          ;rbx:rsi <= quotient

; Now we need to do a multiply so that we can compute the remainder.
  mov rax, rbx                                          ;Set up hi-word of quotient
  mul sqDivisorLo                                       ;Hi-word QUOT * divisor
  mov rcx, rax                                          ;Save the result in ecx
  mov rax, rsi                                          ;Set up lo-word of quotient
  mul sqDivisorLo                                       ;Lo-word(QUOT) * divisor
  add rdx, rcx                                          ;rdx:rax = QUOT * divisor
  jmp short L4                                          ;Complete remainder calculation

; Here we do it the hard way. Remember, eax contains the hi-word of divisor
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
  mov rsi, rax                                          ;Save quotient

; We may be off by one, so to check, we will multiply the quotient
; by the divisor and check the result against the orignal dividend
; Note that we must also check for overflow, which can occur if the
; dividend is close to 2**64 and the quotient is off by 1.
  mul sqDivisorHi                                       ;QUOT * hi-word(divisor)
  mov rcx, rax
  mov rax, sqDivisorLo
  mul rsi                                               ;QUOT * lo-word(divisor)
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
  dec rsi                                               ;Subtract 1 from quotient
  sub rax, sqDivisorLo                                  ;Subtract divisor from result
  sbb rdx, sqDivisorHi
L7:
  xor ebx, ebx                                          ;rbx:rsi <= quotient

L4:
; Calculate remainder by subtracting the result from the original dividend.
; Since the result is already in a register, we will do the subtract in the
; opposite direction and negate the result if necessary.
  sub rax, sqDividendLo                      ;Subtract dividend from result
  sbb rdx, sqDividendHi

; Now check the result sign flag to see if the result is supposed to be positive
; or negative.  It is currently negated (because we subtracted in the 'wrong'
; direction), so if the sign flag is set we are done, otherwise we must negate
; the result to make it positive again.
  dec dSign                                             ;Check result sign flag
  jns short L9                                          ;Result is ok, set up the quotient
  neg rdx                                               ; otherwise, negate the result
  neg rax
  sbb rdx, 0

L9:
; Now we need to get the quotient into rdx:rax and the remainder into rbx:rcx.
  mov rcx, rdx
  mov rdx, rbx
  mov rbx, rcx
  mov rcx, rax
  mov rax, rsi

; Just the cleanup left to do. rdx:rax contains the quotient.
; Set the sign according to the save value and return.
  dec rdi                                               ;Check to see if result is negative
  jnz short L8                                          ;If edi == 0, result should be negative
  neg rdx                                               ; otherwise, negate the result
  neg rax
  sbb rdx, 0

L8:
  ret
soooDivRem endp

end
