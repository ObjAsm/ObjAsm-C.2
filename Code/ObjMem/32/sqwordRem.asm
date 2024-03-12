; ==================================================================================================
; Title:      sqwordRem.asm
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
; Procedure:  sqwordRem
; Purpose:    Calculate the remainder of the division of 2 signed QWORDs.
; Arguments:  Arg1: Dividend.
;             Arg2: Divisor.
; Return:     edx:eax = Remainder.

HIGH_OFFSET = sizeof(DWORD)

align ALIGN_CODE
sqwordRem proc uses edi esi sqDividend:SQWORD, sqDivisor:SQWORD
; Determine sign of the result (edi = 0 if result is positive, non-zero otherwise)
; and make operands positive.
  xor edi, edi                                          ;Result sign assumed positive
  mov eax, SDWORD ptr (sqDividend + HIGH_OFFSET)        ;hi-word of dividend
  or eax, eax                                           ;Test to see if signed
  jge short L1                                          ;Skip rest if dividend is already positive
  inc edi                                               ;Complement result sign flag
  mov edx, SDWORD ptr (sqDividend)                      ;lo-word of dividend
  neg eax                                               ;Make dividend positive
  neg edx
  sbb eax, 0
  mov SDWORD ptr (sqDividend + HIGH_OFFSET), eax        ;Save positive value
  mov SDWORD ptr (sqDividend), edx
L1:
  mov eax, SDWORD ptr (sqDivisor + HIGH_OFFSET)         ;Hi-word of divisor
  or eax, eax                                           ;Test to see if signed
  jge short L2                                          ;Skip rest if divisor is already positive
  inc edi                                               ;Complement the result sign flag
  mov edx, SDWORD ptr (sqDivisor)                       ;Lo-word of dividend
  neg eax                                               ;Make divisor positive
  neg edx
  sbb eax, 0
  mov SDWORD ptr (sqDivisor + HIGH_OFFSET), eax         ;Save positive value
  mov SDWORD ptr (sqDivisor), edx
L2:

; Now do the divide. First look to see if the divisor is less than 4194304K.
; If so, then we can use a simple algorithm with word divides, otherwise
; things get a little more complex.
;
; NOTE - eax currently contains the high order word of sqDivisor
  or eax, eax                                           ;Check to see if divisor < 4194304K
  jnz short L3                                          ;Nope, gotta do this the hard way
  mov ecx, SDWORD ptr (sqDivisor)                       ;Load divisor
  mov eax, SDWORD ptr (sqDividend + HIGH_OFFSET)        ;Load high word of dividend
  xor edx, edx
  div ecx                                               ;edx <- remainder
  mov eax, SDWORD ptr (sqDividend)                      ;edx:eax <- remainder:lo-word of dividend
  div ecx                                               ;edx <- final remainder
  mov eax, edx                                          ;edx:eax <- remainder
  xor edx, edx
  dec edi                                               ;Check result sign flag
  jns short L4                                          ;Negate result & return
  jmp short L8                                          ;Result sign ok, return

; Here we do it the hard way. Remember, eax contains the high word of sqDivisor
L3:
  mov ebx, eax                                          ;ebx:ecx <- divisor
  mov ecx, SDWORD ptr (sqDivisor)
  mov edx, SDWORD ptr (sqDividend + HIGH_OFFSET)        ;edx:eax <- dividend
  mov eax, SDWORD ptr (sqDividend)
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
  mul SDWORD ptr (sqDivisor + HIGH_OFFSET)
  xchg ecx, eax                                         ;Save product, get quotient in eax
  mul SDWORD ptr (sqDivisor)
  add edx, ecx                                          ;edx:eax = QUOT * divisor
  jc short L6                                           ;Carry means quotient is off by 1

; Do long compare here between original dividend and the result of the
; multiply in edx:eax. If original is larger or equal, we are ok, otherwise
; subtract one (1) from the quotient.
  cmp edx, SDWORD ptr (sqDividend + HIGH_OFFSET)        ;Compare hi-words of result and original
  ja short L6                                           ;If result > original, do subtract
  jb short L7                                           ;If result < original, we are ok
  cmp eax, SDWORD ptr (sqDividend)                      ;hi-words are equal, compare lo-words
  jbe short L7                                          ;If less or equal we are ok, else subtract
L6:
  sub eax, SDWORD ptr (sqDivisor)                       ;Subtract divisor from result
  sbb edx, SDWORD ptr (sqDivisor + HIGH_OFFSET)
L7:

; Calculate remainder by subtracting the result from the original dividend.
; Since the result is already in a register, we will do the subtract in the
; opposite direction and negate the result if necessary.
  sub eax, SDWORD ptr (sqDividend)                      ;Subtract dividend from result
  sbb edx, SDWORD ptr (sqDividend + HIGH_OFFSET)

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
sqwordRem endp

end

