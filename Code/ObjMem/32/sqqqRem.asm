; ==================================================================================================
; Title:      sqqqRem.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
;               - Inspired by Microsoft's llRem.asm (nt5src-master).
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  sqqqRem
; Purpose:    Calculate the remainder of the division of 2 signed QWORDs.
;             (64 bit) Dividend divided by (64 bit) Divisor => (64 bit) Remainder. 
; Arguments:  Arg1: Dividend signed low word.
;             Arg2: Dividend signed high word.
;             Arg3: Divisor signed low word.
;             Arg4: Divisor signed high word.
; Return:     edx:eax = Signend remainder.

.code
align ALIGN_CODE
sqqqRem proc uses edi esi sdDividendLo:SDWORD, sdDividendHi:SDWORD, \
                          sdDivisorLo:SDWORD, sdDivisorHi:SDWORD
; Determine sign of the result (edi = 0 if result is positive, non-zero otherwise)
; and make operands positive.
  xor edi, edi                                          ;Result sign assumed positive
  mov eax, sdDividendHi                                 ;Hi-word of dividend
  or eax, eax                                           ;Test to see if signed
  jge short L1                                          ;Skip rest if dividend is already positive
  inc edi                                               ;Complement result sign flag
  mov edx, sdDividendLo                                 ;Lo-word of dividend
  neg eax                                               ;Make dividend positive
  neg edx
  sbb eax, 0
  mov sdDividendHi, eax                                 ;Save positive value
  mov sdDividendLo, edx
L1:
  mov eax, sdDivisorHi                                  ;Hi-word of divisor
  or eax, eax                                           ;Test to see if signed
  jge short L2                                          ;Skip rest if divisor is already positive
  inc edi                                               ;Complement the result sign flag
  mov edx, sdDivisorLo                                  ;Lo-word of dividend
  neg eax                                               ;Make divisor positive
  neg edx
  sbb eax, 0
  mov sdDivisorHi, eax                                  ;Save positive value
  mov sdDivisorLo, edx
L2:

; Now do the divide. First look to see if the divisor is less than 4194304K.
; If so, then we can use a simple algorithm with word divides, otherwise
; things get a little more complex.
;
; NOTE - eax currently contains the high order word of sqDivisor
  or eax, eax                                           ;Check to see if divisor < 4194304K
  jnz short L3                                          ;Nope, gotta do this the hard way
  mov ecx, sdDivisorLo                                  ;Load divisor
  mov eax, sdDividendHi                                 ;Load hi-word of dividend
  xor edx, edx
  div ecx                                               ;edx <= remainder
  mov eax, sdDividendLo                                 ;edx:eax <= remainder: lo-word of dividend
  div ecx                                               ;edx <= final remainder
  mov eax, edx                                          ;edx:eax <= remainder
  xor edx, edx
  dec edi                                               ;Check result sign flag
  jns short L4                                          ;Negate result & return
  jmp short L8                                          ;Result sign ok, return

; Here we do it the hard way. Remember, eax contains the hi-word of sqDivisor
L3:
  mov ebx, eax                                          ;ebx:ecx <= divisor
  mov ecx, sdDivisorLo
  mov edx, sdDividendHi                                 ;edx:eax <= dividend
  mov eax, sdDividendLo
L5:
  shr ebx, 1                                            ;Shift divisor right one bit
  rcr ecx, 1
  shr edx, 1                                            ;Shift dividend right one bit
  rcr eax, 1
  or ebx, ebx
  jnz short L5                                          ;Loop until divisor < 4194304K
  div ecx                                               ;Now divide, ignore remainder

; We may be off by one, so to check, we will multiply the quotient
; by the divisor and check the result against the orignal dividend
; Note that we must also check for overflow, which can occur if the
; dividend is close to 2**64 and the quotient is off by 1.
  mov ecx, eax                                          ;Save a copy of quotient in ecx
  mul sdDivisorHi
  xchg ecx, eax                                         ;Save product, get quotient in eax
  mul sdDivisorLo
  add edx, ecx                                          ;edx:eax = QUOT * divisor
  jc short L6                                           ;Carry means quotient is off by 1

; Do long compare here between original dividend and the result of the
; multiply in edx:eax. If original is larger or equal, we are ok, otherwise
; subtract one (1) from the quotient.
  cmp edx, sdDividendHi                                 ;Compare hi-words of result and original
  ja short L6                                           ;If result > original, do subtract
  jb short L7                                           ;If result < original, we are ok
  cmp eax, sdDividendLo                                 ;Hi-words are equal, compare lo-words
  jbe short L7                                          ;If less or equal we are ok, else subtract
L6:
  sub eax, sdDivisorLo                                  ;Subtract divisor from result
  sbb edx, sdDivisorHi
L7:

; Calculate remainder by subtracting the result from the original dividend.
; Since the result is already in a register, we will do the subtract in the
; opposite direction and negate the result if necessary.
  sub eax, sdDividendLo                                 ;Subtract dividend from result
  sbb edx, sdDividendHi

; Now check the result sign flag to see if the result is supposed to be positive
; or negative. It is currently negated (because we subtracted in the 'wrong'
; direction), so if the sign flag is set we are done, otherwise we must negate
; the result to make it positive again.
  dec edi                                               ;Check result sign flag
  jns short L8                                          ;Result is ok, return
L4:
  neg edx                                               ;otherwise, negate the result
  neg eax
  sbb edx, 0

L8:
  ret
sqqqRem endp

end
