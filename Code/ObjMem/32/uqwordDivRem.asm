; ==================================================================================================
; Title:      uqwordDivRem.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
;               - Inspired by Microsoft's lldvrm.asm (nt5src-master).
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  uqwordDivRem
; Purpose:    Divide 2 unsigned QWORDs.
; Arguments:  Arg1: Dividend.
;             Arg2: Divisor.
; Return:     edx:eax = Quotient.
;             ebx:ecx = Remainder.
; Note:       Don't include ebx in the uses clause.

HIGH_OFFSET = sizeof(DWORD)

align ALIGN_CODE
uqwordDivRem proc uses esi qDividend:QWORD, qDivisor:QWORD
; Now do the divide. First look to see if the divisor is less than 4194304K.
; If so, then we can use a simple algorithm with word divides, otherwise
; things get a little more complex.
  mov eax, DWORD ptr (qDivisor + HIGH_OFFSET)           ;Load hi-word of divisor
  or eax, eax                                           ;Check to see if divisor < 4194304K
  jnz short L1                                          ;Nope, gotta do this the hard way
  mov ecx, DWORD ptr (qDivisor)                         ;Load divisor
  mov eax, DWORD ptr (qDividend + HIGH_OFFSET)          ;Load hi-word of dividend
  xor edx, edx
  div ecx                                               ;eax <- high order bits of quotient
  mov ebx, eax                                          ;Save high bits of quotient
  mov eax, DWORD ptr (qDividend)                        ;edx:eax <- remainder:lo-word of dividend
  div ecx                                               ;eax <- low order bits of quotient
  mov esi, eax                                          ;ebx:esi <- quotient

; Now we need to do a multiply so that we can compute the remainder.
  mov eax, ebx                                          ;Set up high word of quotient
  mul DWORD ptr (qDivisor)                              ;Hi-word QUOT * divisor
  mov ecx, eax                                          ;Save the result in ecx
  mov eax, esi                                          ;Set up lo-word of quotient
  mul DWORD ptr (qDivisor)                              ;Lo-word(QUOT) * divisor
  add edx, ecx                                          ;edx:eax = QUOT * divisor
  jmp short L2                                          ;Complete remainder calculation

; Here we do it the hard way. Remember, eax contains the high word of divisor
L1:
  mov ecx, eax                                          ;ecx:ebx <- divisor
  mov ebx, DWORD ptr (qDivisor)
  mov edx, DWORD ptr (qDividend + HIGH_OFFSET)          ;edx:eax <- dividend
  mov eax, DWORD ptr (qDividend)
L3:
  shr ecx, 1                                            ;Shift divisor right one bit
  rcr ebx, 1
  shr edx, 1                                            ;Shift dividend right one bit
  rcr eax, 1
  or ecx, ecx
  jnz short L3                                          ;Loop until divisor < 4194304K
  div ebx                                               ;Now divide, ignore remainder
  mov esi, eax                                          ;Save quotient

; We may be off by one, so to check, we will multiply the quotient
; by the divisor and check the result against the orignal dividend
; Note that we must also check for overflow, which can occur if the
; dividend is close to 2**64 and the quotient is off by 1.
  mul DWORD ptr (qDivisor + HIGH_OFFSET)                ;QUOT * hi-word(divisor)
  mov ecx, eax
  mov eax, DWORD ptr (qDivisor)
  mul esi                                               ;QUOT * lo-word(divisor)
  add edx, ecx                                          ;edx:eax = QUOT * divisor
  jc short L4                                           ;Carry means quotient is off by 1

; Do long compare here between original dividend and the result of the
; multiply in edx:eax. If original is larger or equal, we are ok, otherwise
; subtract one (1) from the quotient.
  cmp edx, DWORD ptr (qDividend + HIGH_OFFSET)          ;Compare hi words of result and original
  ja short L4                                           ;If result > original, do subtract
  jb short L5                                           ;If result < original, we are ok
  cmp eax, DWORD ptr (qDividend)                        ;hi words are equal, compare lo words
  jbe short L5                                          ;If less or equal we are ok, else subtract
L4:
  dec esi                                               ;Subtract 1 from quotient
  sub eax, DWORD ptr (qDivisor)                         ; subtract divisor from result
  sbb edx, DWORD ptr (qDivisor + HIGH_OFFSET)
L5:
  xor  ebx, ebx                                         ;ebx:esi <- quotient

L2:
; Calculate remainder by subtracting the result from the original dividend.
; Since the result is already in a register, we will do the subtract in the
; opposite direction and negate the result if necessary.
  sub eax, DWORD ptr (qDividend)                        ;Subtract dividend from result
  sbb edx, DWORD ptr (qDividend + HIGH_OFFSET)
  neg edx
  neg eax
  sbb edx, 0

; Now we need to get the quotient into edx:eax and the remainder into ebx:ecx.
  mov ecx, edx
  mov edx, ebx
  mov ebx, ecx
  mov ecx, eax
  mov eax, esi

; Cleanup and return, edx:eax contains the quotient.
  ret
uqwordDivRem endp

end
