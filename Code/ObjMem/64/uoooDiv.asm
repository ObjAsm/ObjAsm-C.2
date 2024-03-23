; ==================================================================================================
; Title:      uoooDiv.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
;               - Inspired by Microsoft's ulldiv.asm (nt5src-master).
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  uoooDiv
; Purpose:    Divide 2 unsigned OWORDs.
;             (128 bit) Dividend divided by (128 bit) Divisor = (128 bit) Quotient. 
; Arguments:  Arg1: Dividend unsigned low word.
;             Arg2: Dividend unsigned high word.
;             Arg3: Divisor unsigned low word.
;             Arg4: Divisor unsigned high word.
; Return:     rdx:rax = Unsigned quotient.

align ALIGN_CODE
uoooDiv proc uses rbx rsi qDividendLo:QWORD, qDividendHi:QWORD, \
                          qDivisorLo:QWORD, qDivisorHi:QWORD
; Now do the divide. First look to see if the divisor is less than 18446744073G.
; If so, then we can use a simple algorithm with word divides, otherwise
; things get a little more complex.
  mov rax, qDivisorHi                                   ;Load hi-word of divisor
  or rax, rax                                           ;Check to see if divisor < 18446744073G
  jnz short L1                                          ;Nope, gotta do this the hard way
  mov rcx, qDivisorLo                                   ;Load divisor
  mov rax, qDividendHi                                  ;Load hi-word of dividend
  xor edx, edx
  div rcx                                               ;rax <= high order bits of quotient
  mov rbx, rax                                          ;Save high bits of quotient
  mov rax, qDividendLo                                  ;rdx:rax <= remainder: lo-word of dividend
  div rcx                                               ;rax <= low order bits of quotient
  mov rdx, rbx                                          ;rdx:rax <= quotient
  jmp short L2                                          ;Set sign, restore stack and return

; Here we do it the hard way. Remember, eax contains the hi-word of qDivisor
L1:
  mov rcx, rax                                          ;rcx:rbx <= divisor
  mov rbx, qDivisorLo
  mov rdx, qDividendHi                                  ;rdx:rax <= dividend
  mov rax, qDividendLo
L3:
  shr rcx, 1                                            ;Shift divisor right one bit
  rcr rbx, 1
  shr rdx, 1                                            ;Shift dividend right one bit
  rcr rax, 1
  or rcx, rcx
  jnz short L3                                          ;Loop until divisor < 18446744073G
  div rbx                                               ;Now divide, ignore remainder
  mov rsi, rax                                          ;Save quotient

; We may be off by one, so to check, we will multiply the quotient
; by the divisor and check the result against the orignal dividend
; Note that we must also check for overflow, which can occur if the
; dividend is close to 2**64 and the quotient is off by 1.
  mul qDivisorHi                                        ;QUOT * hi-word(divisor)
  mov rcx, rax
  mov rax, qDivisorLo
  mul rsi                                               ;QUOT * lo-word(divisor)
  add rdx, rcx                                          ;rdx:rax = QUOT * divisor
  jc short L4                                           ;Carry means quotient is off by 1

; Do long compare here between original dividend and the result of the
; multiply in rdx:rax. If original is larger or equal, we are ok, otherwise
; subtract one (1) from the quotient.
  cmp rdx, qDividendHi                                  ;Compare hi-words of result and original
  ja short L4                                           ;If result > original, do subtract
  jb short L5                                           ;If result < original, we are ok
  cmp rax, qDividendLo                                  ;Hi-words are equal, compare lo-words
  jbe short L5                                          ;If less or equal we are ok, else subtract
L4:
  dec rsi                                               ;Subtract 1 from quotient
L5:
  xor edx, edx                                          ;rdx:rax <= quotient
  mov rax, rsi

; Just the cleanup left to do. rdx:rax contains the quotient.
L2:
  ret
uoooDiv endp

end
