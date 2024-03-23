; ==================================================================================================
; Title:      sxxxMul_XP.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
;               - Bitness and Platform independent code.
; ==================================================================================================


.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  sooyMul / sqqoMul
; Purpose:    Calculate a signed extended precision multiplication, emulating the imul x86 instr.
;             (128/64 bit) Multiplicand multiplied by (128/64 bit) Multiplier = (256/128 bit) Prod. 
; Arguments:  Arg1: Multiplicand signed low word.
;             Arg2: Multiplicand signed high word.
;             Arg3: Multiplier signed low word.
;             Arg4: Multiplier signed high word.
; Return:     xbx:xcx:xdx:xax = Signed product (256/128 bit).

align ALIGN_CODE
ProcName proc sxMultiplicandLo:SXWORD, sxMultiplicandHi:SXWORD, \
              sxMultiplierLo:SXWORD, sxMultiplierHi:SXWORD
  local sxTempLoLo:SXWORD, sxTempLoHi:SXWORD, sxTempHiLo:SXWORD, sxTempHiHi:SXWORD

; Do the low order unsigned product
  mov xax, sxMultiplicandLo
  mul sxMultiplierLo
  mov sxTempLoLo, xax
  mov sxTempLoHi, xdx

; Do the high order signed product
  mov xax, sxMultiplicandHi
  imul sxMultiplierHi
  mov sxTempHiLo, xax
  mov sxTempHiHi, xdx

; Do a mixed product
  mov xax, sxMultiplicandHi
  if type(xax) eq 4
    cdq
  else
    cqo
  endif
  and xdx, sxMultiplierLo
  sub sxTempHiLo, xdx                                   ;Adjust for sign bit
  sbb sxTempHiHi, 0
  mul sxMultiplierLo
  add sxTempLoHi, xax
  adc sxTempHiLo, xdx
  adc sxTempHiHi, 0

; Do the other mixed product
  mov xax, sxMultiplierHi
  if type(xax) eq 4
    cdq
  else
    cqo
  endif
  and xdx,sxMultiplicandLo
  sub sxTempHiLo, xdx
  sbb sxTempHiHi, 0
  mul sxMultiplicandLo

; Pick up the answer
  mov xcx, xdx
  mov xdx, xax
  xor xbx, xbx

  mov xax, sxTempLoLo
  add xdx, sxTempLoHi
  adc xcx, sxTempHiLo
  adc xbx, sxTempHiHi

  ret
ProcName endp
