; ==================================================================================================
; Title:      sxxxDivRem_XP.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
;               - Bitness and Platform independent code.
; ==================================================================================================


USE_OVERFLOW_FLAG equ 1

DIV_SIGN  equ 1
REM_SIGN  equ 2

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  syooDivRem / soqqDivRem
; Purpose:    Calculate a signed extended precision division, emulating the idiv x86 instr.
;             (256/128 bit) Dividend divided by (128/64 bit) Divisor = (128/64 bit) Quotient. 
; Arguments:  Arg1: Dividend signed low low word.
;             Arg2: Dividend signed high low word.
;             Arg3: Dividend signed low high word.
;             Arg4: Dividend signed high high word.
;             Arg5: Divisor signed low word.
;             Arg6: Divisor signed high word.
; Return:     xdx:xax = Signed quotient.
;             xbx:xcx = Signed remainder.
;             OF set on division overlow and the content of the registers is undetermined.
; Note:       Non-integral results are truncated (chopped) towards 0. 
;             The remainder is always less than the divisor in magnitude.
;             Don't include xbx in the uses clause.

align ALIGN_CODE
ProcName proc sxDividendLoLo:SXWORD, sxDividendHiLo:SXWORD, \
              sxDividendLoHi:SXWORD, sxDividendHiHi:SXWORD, \
              sxDivisorLo:SXWORD, sxDivisorHi:SXWORD
  local dFlags:DWORD
;  local .LoLo: SXWORD, .HiLo: SXWORD, .LoHi: SXWORD, .HiHi: SXWORD, .Lo: SXWORD, .Hi: SXWORD

  mov dFlags, 0

; Take the absolute value of the divisor
  mov xcx, sxDivisorHi
  or xcx, xcx
  mov xbx, sxDividendHiHi
  mov xax, sxDividendLoHi
  mov xdx, sxDividendHiLo
  mov xcx, sxDividendLoLo
  .if SIGN?
    xor dFlags, DIV_SIGN
    neg sxDivisorLo
    adc sxDivisorHi, 0
    neg sxDivisorHi
  .endif

; Take the absolute value of the dividend
  or xbx, xbx
  .if SIGN?
    xor dFlags, DIV_SIGN or REM_SIGN
    not xcx
    not xdx
    not xax
    not xbx
    add xcx, 1
    adc xdx, 0
    adc xax, 0
    adc xbx, 0
  .endif

; Do the unsigned division
;  mov .LoLo, xcx
;  mov .HiLo, xdx
;  mov .LoHi, xax
;  mov .HiHi, xbx
;  DbgWriteF,, "Dividend = ¦HX:¦HX:¦HX:¦HX", .HiHi, .LoHi, .HiLo, .LoLo
;  DbgWriteF,, "Divisor  = ¦HX:¦HX", sxDivisorHi, sxDivisorLo
  invoke uxDivRemExEx, xcx, xdx, xax, xbx, sxDivisorLo, sxDivisorHi
ifdef USE_OVERFLOW_FLAG
  jo @@Exit                                             ;Overflow returned from uxwordDivRemEx
endif

; Check for signed overflow
  or xdx, xdx
  .if SIGN?                                             ;Have a bit to spare
ifdef USE_OVERFLOW_FLAG
    mov al, 7Fh
    inc al                                              ;Set OF flag
    jmp short @@Exit
else
    int 0                                               ;Divide Error Interrupt => you're toasted
endif
  .endif

; If required, negate the quotient 
  test dFlags, DIV_SIGN
  .if !ZERO?
    neg xax
    adc xdx, 0
    neg xdx
  .endif

; If required, negate the remainder 
  test dFlags, REM_SIGN
  .if !ZERO?
    neg xcx
    adc xbx, 0
    neg xbx
  .endif

@@Exit:
  ret
ProcName endp
