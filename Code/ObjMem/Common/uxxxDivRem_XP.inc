; ==================================================================================================
; Title:      uxxxDivRem_XP.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
;               - Bitness and Platform independent code.
; ==================================================================================================


USE_OVERFLOW_FLAG equ 1

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  Normalize
; Purpose:    Auxiliary procedure that normalizes a XWORD so that the highest order bit is 1.
; Arguments:  Arg1: Number unsigned low word.
;             Arg2: Number unsigned high word.
; Return:     xdx:xax = Normalized input number.
;             ecx = Number of shifts required to normalize the input number.
;             ZF = 1 if the input number was zero, otherwise 0.

align ALIGN_CODE
Normalize proc uses xbx uxNumberLo:XWORD, uxNumberHi:XWORD
  xor ecx, ecx                                          ;Reset shift counter
  mov xdx, uxNumberHi
  mov xax, uxNumberLo

if TARGET_BITNESS eq 64
  ;Inspect high QWORD
  or rdx, rdx
  js @@Exit
  .if ZERO?
    xchg rax, rdx
    or rdx, rdx
    jz @@Exit                                           ;ecx = 0, SF = 1, the zero exit
    mov ecx, 64
    js @@Exit                                           ;ecx = 64, SF = 0
  .else
    bsr rcx, rdx                                        ;Get MSB(rdx)
    mov ebx, ecx                                        ;Save ecx
    invoke uoShl                                        ;Shift left rdx:rax
    mov ecx, ebx                                        ;Restore ecx
  .endif
else
  ;Inspect high DWORD
  or edx, edx
  js @@Exit
  .if ZERO?
    xchg eax, edx
    or edx, edx
    jz @@Exit                                           ;ecx = 0, SF = 1, the zero exit
    mov ecx, 32
    js @@Exit                                           ;ecx = 32, SF = 0
  .else
    bsr ecx, edx                                        ;Get MSB(edx)
    mov ebx, ecx                                        ;Save ecx
    invoke uqShl                                        ;Shift left edx:eax
    mov ecx, ebx                                        ;Restore ecx
  .endif
endif
@@Exit:
  ret
Normalize endp


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  uyooDivRem / uoqqDivRem
; Purpose:    Calculate an unsigned extended precision division, emulating the div x86 instr.
;             (256/128 bit) Dividend divided by (128/64 bit) Divisor = (128/64 bit) Quotient. 
; Arguments:  Arg1: Dividend unsigned low low word.
;             Arg2: Dividend unsigned high low word.
;             Arg3: Dividend unsigned low high word.
;             Arg4: Dividend unsigned high high word.
;             Arg5: Divisor unsigned low word.
;             Arg6: Divisor unsigned high word.
; Return:     xdx:xax = Unsigned quotient.
;             xbx:xcx = Unsigned remainder.
;             OF set on division overlow and the content of the registers is undetermined.
; Note:       Non-integral results are truncated (chopped) towards 0. 
;             The remainder is always less than the divisor in magnitude.
;             Don't include xbx in the uses clause.

align ALIGN_CODE
ProcName proc uses xdi xsi uxDividendLoLo:XWORD, uxDividendHiLo:XWORD, \
                           uxDividendLoHi:XWORD, uxDividendHiHi:XWORD, \
                           uxDivisorLo:XWORD, uxDivisorHi:XWORD
  local dShift:DWORD

; Stuff the arguments into registers
  mov xbx, uxDividendLoHi
  mov xdx, uxDividendHiHi

  mov xdi, uxDivisorLo
  mov xsi, uxDivisorHi

; Check for overflow
  cmp xsi, xdx
  ja @@NoOverflow
  jb @@Overflow
  cmp xdi, xbx
  ja @@NoOverflow

@@Overflow:
ifdef USE_OVERFLOW_FLAG
  mov si, 8000h
  dec si                                                ;Set OF flag, xsi is restored at proc end
  jmp @@Exit
else
  int 0                                                 ;Divide Error Interrupt => you're toasted
endif

@@NoOverflow:
  mov xax, uxDividendLoLo
  mov xcx, uxDividendHiLo

; Check for a zero dividend
  or xax, xcx
  or xax, xbx
  or xax, xdx
  jz @@ExitRelay                                        ;Quotient = remainder = 0

; Handle the special case when the divisor lives in the low word
  or xsi, xsi
  jnz @@NotThatSpecial

; Calculate (xdx=0):xbx:xcx:uxDividendLoLo / (xsi=0):xdi
  cmp xdi, 1                                            ;Separate out the trivial case
  jz @@DivByOne
  xchg xdx, xbx                                         ;xbx = remainder.hi = 0
  mov xax, xcx
  div xdi
  mov xcx, xax                                          ;xcx = quotient.hi
  mov xax, uxDividendLoLo
  div xdi                                               ;xax = quotient.lo
  xchg xcx, xdx                                         ;xdx = quotient.hi, xcx = remainder.lo
ifdef USE_OVERFLOW_FLAG
  or xax, xax                                           ;Clear OF
endif
@@ExitRelay:
  jmp @@Exit

; Calculate (xdx=0):(xbx=0):xcx:uxDividendLoLo / (xsi=0):(xdi=1)
@@DivByOne:
  xchg xdx, xcx                                         ;xdx = quotient.hi, xcx = remainder.lo = 0
  mov xax, uxDividendLoLo                               ;xax = quotient.lo
  jmp @@Exit
@@NotThatSpecial:

; Handle the special case when the divisor lives in the high word
  or xdi, xdi
  jnz @@NotThisSpecialEither

; Calculate xdx:xbx:xcx:uxDividendLoLo / xsi:(xdi=0)
  cmp xsi, 1                                            ;Separate out the trivial case
  jz @@DivByHiWord
  mov xax, xbx
  div xsi
  mov xbx, xax                                          ;xbx = quotient.hi
  mov xax, xcx
  div xsi                                               ;xax = quotient.lo
  xchg xbx, xdx                                         ;xdx = quotient.hi, xbx = remainder.hi
  mov xcx, uxDividendLoLo                               ;xcx = remainder.lo
ifdef USE_OVERFLOW_FLAG
  or xax, xax                                           ;Clear OF
endif
  jmp @@Exit

; Calculate (xdx=0):xbx:xcx:uxDividendLoLo / (xsi=1):(xdi=0)
@@DivByHiWord:
  xchg xbx, xdx                                         ;xdx = quotient.hi, xbx = remainder.hi = 0
  mov xax, xcx                                          ;xax = quotient.lo
  mov xcx, uxDividendLoLo                               ;xcx = remainder.lo
  jmp @@Exit

@@NotThisSpecialEither:
; Normalize the divisor
  invoke Normalize, xdi, xsi                            ;xsi:xdi = normalized divisor
  mov dShift, ecx                                       ;ecx < 64
  mov uxDivisorLo, xax
  mov uxDivisorHi, xdx

; Shift the dividend by the same amount
  .if ecx != 0
    mov xsi, -1
    shl xsi, cl
    not xsi          ; SI = mask
    mov xbx, uxDividendHiHi
    shl xbx, cl
    mov xax, uxDividendLoHi
    rol xax, cl
    mov xdi, xsi
    and xdi, xax
    or xbx, xdi
    mov uxDividendHiHi, xbx
    xor xax, xdi
    mov xbx, uxDividendHiLo
    rol xbx, cl
    mov xdi, xsi
    and xdi, xbx
    or xax, xdi
    mov uxDividendLoHi, xax
    xor xbx, xdi
    mov xax, uxDividendLoLo
    rol xax, cl
    mov xdi, xsi
    and xdi, xax
    or xbx, xdi
    mov uxDividendHiLo, xbx
    xor xax, xdi
    mov uxDividendLoLo, xax
  .endif

; Set up registers for division
  mov xdx, uxDividendHiHi
  mov xax, uxDividendLoHi
  mov xdi, uxDividendHiLo
  mov xcx, uxDivisorHi
  mov xbx, uxDivisorLo

; Check for case when divisor has only 32/64 bits
  or xbx, xbx
  jnz @@MustDoLongDivision
  div xcx
  mov xsi, xax
  mov xax, uxDividendHiLo
  div xcx
  xchg xsi, xdx                                         ;xdx:xax = quotient
  mov xdi, uxDividendLoLo                               ;xsi:xdi = remainder (shifted)
  jmp @@UnshiftRemainder

@@MustDoLongDivision:
; Do the long division, part IZ@NL@%
  cmp xdx, xcx                                          ;We only know that xdx:xax < xcx:xbx!
  jb @@FirstDivisionIsSafe
  mov uxDivisorHi, 0                                    ;i.e. 10000h, our guess is too big
  mov xsi, xax
  sub xsi, xbx                                          ;... remainder is negative
  jmp short first_adjuster

@@FirstDivisionIsSafe:
  div xcx
  mov uxDivisorHi, xax
  mov xsi, xdx
  mul xbx                                               ;Fix remainder for low order term
  sub xdi, xax
  sbb xsi, xdx
  jnc @@FirstAdjusterDone                               ;The remainder is UNSIGNED!  We have
first_adjuster:                                         ;  to use the carry flag to keep track
  dec uxDivisorHi                                       ;  of the sign.  The adjuster loop
  add xdi, xbx                                          ;  watches for a change to the carry
  adc xsi, xcx                                          ;  flag which would indicate a sign
  jnc first_adjuster                                    ;  change IF we had more bits to keep
@@FirstAdjusterDone:                                    ;  a sign in.

; Do the long division, part II
  mov xdx, xsi
  mov xax, xdi
  mov xdi, uxDividendLoLo
  cmp xdx, xcx                                          ;We only know that xdx:xax < xcx:xbx!
  jb @@SecondDivisionIsSafe
  mov uxDivisorLo, 0                                    ;i.e. 10000h, our guess is too big
  mov xsi, xax
  sub xsi, xbx                                          ;... remainder is negative
  jmp  short @@SecondAdjuster
@@SecondDivisionIsSafe:
  div xcx
  mov uxDivisorLo, xax
  mov xsi, xdx
  mul xbx                                               ;Fix remainder for low order term
  sub xdi, xax
  sbb xsi, xdx
  jnc @@SecondAdjusterDone
@@SecondAdjuster:
  dec uxDivisorLo
  add xdi, xbx
  adc xsi, xcx
  jnc @@SecondAdjuster
@@SecondAdjusterDone:
  mov xax, uxDivisorLo
  mov xdx, uxDivisorHi

; Unshift the remainder in xsi:xdi
@@UnshiftRemainder:
  mov ecx, dShift
  .if ecx != 0
    mov xbx, -1
    shr xbx, cl
    not xbx
    shr xdi, cl
    ror xsi, cl
    and xbx, xsi
    or xdi, xbx
    xor xsi, xbx
  .endif
  mov xbx, xsi
  mov xcx, xdi
ifdef USE_OF
  or xax, xax                                           ;Clear OF
endif

@@Exit:
  ret
ProcName endp

