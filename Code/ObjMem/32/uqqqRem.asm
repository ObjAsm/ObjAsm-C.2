; ==================================================================================================
; Title:      uqqqRem.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
;               - Inspired by Microsoft's ullrem.asm (nt5src-master).
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  uqqqRem
; Purpose:    Calculate the remainder of the division of 2 unsigned QWORDs.
;             (64 bit) Dividend divided by (64 bit) Divisor => (64 bit) Remainder. 
; Arguments:  Arg1: Dividend unsigned low word.
;             Arg2: Dividend unsigned high word.
;             Arg3: Divisor unsigned low word.
;             Arg4: Divisor unsigned high word.
; Return:     edx:eax = Unsigned remainder.

align ALIGN_CODE
uqqqRem proc uses ebx dDividendLo:DWORD, dDividendHi:DWORD, \
                      dDivisorLo:DWORD, dDivisorHi:DWORD
; Now do the divide. First look to see if the divisor is less than 4194304K.
; If so, then we can use a simple algorithm with word divides, otherwise
; things get a little more complex.
  mov eax, dDivisorHi                                   ;Load hi-word of divisor
  or eax, eax                                           ;Check to see if divisor < 4194304K
  jnz short L1                                          ;Nope, gotta do this the hard way
  mov ecx, dDivisorLo                                   ;Load divisor
  mov eax, dDividendHi                                  ;Load hi-word of dividend
  xor edx, edx
  div ecx                                               ;eax <= high order bits of quotient
  mov eax, dDividendLo                                  ;edx:eax <= remainder: lo-word of dividend
  div ecx                                               ;eax <= low order bits of quotient
  mov eax, edx                                          ;edx:eax <= remainder
  xor edx, edx
  jmp short L2                                          ;Complete remainder calculation

; Here we do it the hard way. Remember, eax contains the hi-word of divisor
L1:
  mov ecx, eax                                          ;ecx:ebx <= divisor
  mov ebx, dDivisorLo
  mov edx, dDividendHi                                  ;edx:eax <= dividend
  mov eax, dDividendLo
L3:
  shr ecx, 1                                            ;Shift divisor right one bit
  rcr ebx, 1
  shr edx, 1                                            ;Shift dividend right one bit
  rcr eax, 1
  or ecx, ecx
  jnz short L3                                          ;Loop until divisor < 4194304K
  div ebx                                               ;Now divide, ignore remainder

; We may be off by one, so to check, we will multiply the quotient
; by the divisor and check the result against the orignal dividend
; Note that we must also check for overflow, which can occur if the
; dividend is close to 2**64 and the quotient is off by 1.
  mov ecx, eax
  mul dDivisorHi                                        ;QUOT * hi-word(divisor)
  xchg ecx, eax                                         ;Put partial product in ecx, get quotient in eax
  mul dDivisorLo
  add edx, ecx                                          ;edx:eax = QUOT * divisor
  jc short L4                                           ;Carry means quotient is off by 1

; Do long compare here between original dividend and the result of the
; multiply in edx:eax. If original is larger or equal, we are ok, otherwise
; subtract one (1) from the quotient.
  cmp edx, dDividendHi                                  ;Compare hi words of result and original
  ja short L4                                           ;If result > original, do subtract
  jb short L5                                           ;If result < original, we are ok
  cmp eax, dDividendLo                                  ;Hi-words are equal, compare lo words
  jbe short L5                                          ;If less or equal we are ok, else subtract
L4:
  sub eax, dDivisorLo                                   ;Subtract divisor from result
  sbb edx, dDivisorHi
L5:

; Calculate remainder by subtracting the result from the original dividend.
; Since the result is already in a register, we will do the subtract in the
; opposite direction and negate the result if necessary.
  sub eax, dDividendLo                                  ;Subtract dividend from result
  sbb edx, dDividendHi
  neg edx
  neg eax
  sbb edx, 0

; Cleanup and return, edx:eax contains the remainder.
L2:
  ret
uqqqRem endp

end
