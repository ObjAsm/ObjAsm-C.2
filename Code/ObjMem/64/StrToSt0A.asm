; ==================================================================================================
; Title:      StrToSt0A.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

.const
dTen    DWORD    10

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrToSt0A
; Purpose:    Load an ANSI string representation of a floating point number into the st(0)
;             FPU register.
; Arguments:  Arg1: -> ANSI string floating point number.
; Return:     eax = Result code f_OK or f_ERROR.
; Notes:      - Based on the work of Raymond Filiatreault (FpuLib).
;             - Source string should not be greater than 19 chars + zero terminator.

.code
align ALIGN_CODE
StrToSt0A proc uses rbx rsi rdi pSource:POINTER
  local tBCD:TBYTE, wStatusWord:WORD

  xor eax, eax
  xor ebx, ebx
  xor edx, edx
  lea rdi, tBCD
  stosd
  stosd
  mov [rdi], ax
  mov rsi, pSource
  mov rcx, 19
@@:
  lodsb
  cmp al, " "
  jz @B                                                 ;Eliminate leading spaces
  or al, al                                             ;Is string empty?
  jz @@Error

;Check for leading sign
  cmp al, "+"
  jz @F
  cmp al, "-"
  jnz @@Integer
  mov ah, 80h
@@:
  mov [rdi + 1], ah                                     ;Put sign byte in bcd string
  xor eax, eax
  lodsb

;Convert the digits to packed decimal
@@Integer:
  cmp al, "."
  jnz @F
  test bh, 1
  jnz @@Error                                           ;Only one decimal point allowed
  or bh, 1                                              ;Use bh to set the decimal point flag
  lodsb
@@:
  cmp al, "e"
  jnz @F
  cmp cl, 19
  jz @@Error                                            ;Error if no digit before e
  jmp @@Scient
@@:
  cmp al, "E"
  jnz @F
  cmp cl, 19
  jz @@Error                                            ;Error if no digit before E
  jmp @@Scient
@@:
  or al, al
  jnz @F
  cmp cl, 19
  jz @@Error                                            ;Error if no digit before terminating 0
  jmp @@LastStep
@@:
  sub al, "0"
  jc @@Error                                            ;Unacceptable character
  cmp al, 9
  ja @@Error                                            ;Unacceptable character
  test bh, 1
  jnz @F
  inc bl
@@:
  dec rcx
  jz @@Error                                            ;Error if more than 18 digits in number
  mov ah, al

  lodsb
  cmp al, "."
  jnz @F
  test bh, 1
  jnz @@Error                                           ;Only one decimal point allowed
  or bh, 1                                              ;Use bh to set the decimal point flag
  lodsb
@@:
  cmp al, "e"
  jnz @F
  cmp cl, 19
  jz @@Error                                            ;Error if no digit before e
  m2z al
  rol al, 4
  ror ax, 4
  mov [rdi], al
  jmp @@Scient
@@:
  cmp al, "E"
  jnz @F
  cmp cl, 19
  jz @@Error                                            ;Error if no digit before E
  m2z al
  rol al, 4
  ror ax, 4
  mov [rdi], al
  jmp @@Scient
@@:
  or al, al
  jnz @F
  cmp cl, 19
  jz @@Error                                            ;Error if no digit before terminating 0
  rol al, 4
  ror ax, 4
  mov [rdi], al
  jmp @@LastStep
@@:
  sub al, "0"
  jc @@Error                                            ;Unacceptable character
  cmp al, 9
  ja @@Error                                            ;Unacceptable character
  test bh, 1
  jnz @F
  inc bl
@@:
  dec rcx
  jz @@Error                                            ;Error if more than 18 digits in number
  rol al, 4
  ror ax, 4
  mov [rdi], al
  dec rdi
  lodsb
  jmp @@Integer

@@LastStep:
  fbld tBCD
  xor eax, eax
  mov al, 18
  sub al, bl
  sub rdx, rax
  call XexpY
  fmul
  fstsw wStatusWord                                     ;Retrieve exception flags from FPU
  fwait
  test wStatusWord, mask fInvOp                         ;Test for invalid operation
  jnz @@Error                                           ;Clean-up and return error
  mov rax, f_OK
  jmp @@Exit

@@Scient:
  xor eax, eax
  lodsb
  cmp al, "+"
  jz @F
  cmp al,"-"
  jnz @@Scient1
  stc
  rcr rax, 1                                            ;Keep sign of exponent in most significant bit of EAX
@@:
  lodsb                                                 ;Get next digit after sign

@@Scient1:
  push rax
  and rax, 0ffh
  jnz @F                                                ;Continue if 1st byte of exponent is not terminating 0

@@ScientError:
  pop rax
  jmp @@Error                                           ;No exponent

@@:
  sub al, 30h
  jc @@ScientError                                      ;Unacceptable character
  cmp al, 9
  ja @@ScientError                                      ;Unacceptable character
  push rax
  mov rax, rdx
  mul dTen
  mov rdx, rax
  pop rax
  add rdx, rax
  cmp rdx, 4931
  ja @@ScientError                                      ;Exponent too large
  lodsb
  or al, al
  jnz @B
  pop rax                                               ;Retrieve exponent sign flag
  rcl rax, 1                                            ;Is most significant bit set?
  jnc @F
  neg rdx
@@:
  jmp @@LastStep

@@Error:
  mov rax, f_ERROR

@@Exit:
  ret
StrToSt0A endp

; #########################################################################

;Put 10 to the proper exponent (value in edx) on the FPU

XexpY:
  push rdx
  fild DWORD ptr [rsp]                                ;Load the exponent
  fldl2t                                              ;Load log2(10)
  add rsp, @WordSize
  fmul                                                ;-> log2(10)*exponent

;At this point, only the log base 2 of the 10^exponent is on the FPU
;the FPU can compute the antilog only with the mantissa
;the characteristic of the logarithm must thus be removed
  fld st(0)                                           ;Copy the logarithm
  frndint                                             ;Keep only the characteristic
  fsub st(1), st                                      ;Keep only the mantissa
  fxch                                                ;Get the mantissa on top

  f2xm1                                               ;->2^(mantissa)-1
  fld1
  fadd                                                ;Add 1 back

;The number must now be readjusted for the characteristic of the logarithm
  fscale                                              ;Scale it with the characteristic

;The characteristic is still on the FPU and must be removed
  fxch                                                ;Bring it back on top
  fstp st(0)                                          ;Clean-up the register
  ret

;##########################################################################

end
