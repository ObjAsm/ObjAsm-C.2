; ==================================================================================================
; Title:      sqwordDiv.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
;               - Inspired lldiv.asm (nt5src-master).
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  sqwordDiv
; Purpose:    Divide 2 signed QWORDs.
; Arguments:  Arg1: Dividend.
;             Arg2: Divisor.
; Return:     edx:eax = Quotient.

HIGH_OFFSET = sizeof(DWORD)

align ALIGN_CODE
sqwordDiv proc uses ebx edi esi sqDividend:SQWORD, sqDivisor:SQWORD
; Determine sign of the result (edi = 0 if result is positive, non-zero otherwise)
; and make operands positive.
  xor edi, edi                                          ;Result sign assumed positive

  mov eax, SDWORD ptr (sqDividend + HIGH_OFFSET)        ;hi-word of dividend
  or eax, eax                                           ;Test to see if signed
  jge short L1                                          ;Skip rest if a is already positive
  inc edi                                               ;Complement result sign flag
  mov edx, SDWORD ptr (sqDividend)                      ;lo-word of dividend
  neg eax                                               ;Make dividend positive
  neg edx
  sbb eax, 0
  mov SDWORD ptr (sqDividend + HIGH_OFFSET), eax        ;Save positive value
  mov SDWORD ptr (sqDividend), edx
L1:
  mov eax, SDWORD ptr (sqDivisor + HIGH_OFFSET)         ;hi-word of divisor
  or eax, eax                                           ;Test to see if signed
  jge short L2                                          ;Skip rest if b is already positive
  inc edi                                               ;Complement the result sign flag
  mov edx, SDWORD ptr (sqDivisor)                       ;lo-word of dividend
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
  div ecx                                               ;eax <- high order bits of quotient
  mov ebx, eax                                          ;Save high bits of quotient
  mov eax, SDWORD ptr (sqDividend)                      ;edx:eax <- remainder:lo-word of dividend
  div ecx                                               ;eax <- low order bits of quotient
  mov edx, ebx                                          ;edx:eax <- quotient
  jmp short L4                                          ;Set sign, restore stack and return

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
  mov esi, eax                                          ;Save quotient

; We may be off by one, so to check, we will multiply the quotient
; by the divisor and check the result against the orignal dividend
; Note that we must also check for overflow, which can occur if the
; dividend is close to 2**64 and the quotient is off by 1.
;

  mul SDWORD ptr (sqDivisor + HIGH_OFFSET)              ;QUOT * hi-word(sqDivisor)
  mov ecx, eax
  mov eax, SDWORD ptr (sqDivisor)
  mul esi                                               ;QUOT * lo-word(sqDivisor)
  add edx, ecx                                          ;edx:eax = QUOT * sqDivisor
  jc short L6                                           ;Carry means Quotient is off by 1

; do long compare here between original dividend and the result of the
; multiply in edx:eax. If original is larger or equal, we are ok, otherwise
; subtract one (1) from the quotient.
  cmp edx, SDWORD ptr (sqDividend + HIGH_OFFSET)        ;Compare hi words of result and original
  ja short L6                                           ;If result > original, do subtract
  jb short L7                                           ;If result < original, we are ok
  cmp eax, SDWORD ptr (sqDividend)                      ;hi words are equal, compare lo words
  jbe short L7                                          ;If less or equal we are ok, else subtract
L6:
  dec esi                                               ;Subtract 1 from quotient
L7:
  xor edx, edx                                          ;edx:eax <- quotient
  mov eax, esi

; Just the cleanup left to do. edx:eax contains the quotient.
; Set the sign according to the saved value and return.
L4:
  dec edi                                               ;Check to see if result is negative
  jnz short L8                                          ;If edi == 0, result should be negative
  neg edx                                               ; otherwise, negate the result
  neg eax
  sbb edx, 0

L8:
  ret
sqwordDiv endp

end

