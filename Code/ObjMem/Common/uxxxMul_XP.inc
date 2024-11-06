; ==================================================================================================
; Title:      uxxxMul_XP.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
;               - Bitness and Platform independent code.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  uooywordMul / uqqowordMul
; Purpose:    Calculate an extended precision unsigned multiplication, emulating the mul x86 instr.
; Arguments:  Arg1: Multiplicand unsigned low word.
;             Arg2: Multiplicand unsigned high word.
;             Arg3: Multiplier unsigned low word.
;             Arg4: Multiplier unsigned high word.
; Return:     xbx:xcx:xdx:xax = Unsigned product (128/256 bit).

.code
align ALIGN_CODE
ProcName proc xMultiplicandLo:XWORD, xMultiplicandHi:XWORD, \
              xMultiplierLo:XWORD, xMultiplierHi:XWORD
  local xTempLoLo:XWORD, xTempLoHi:XWORD, xTempHiLo:XWORD, xTempHiHi:XWORD

; Do the low order unsigned product
  mov xax, xMultiplicandLo
  mul xMultiplierLo
  mov xTempLoLo, xax
  mov xTempLoHi, xdx

; Do the high order signed product
  mov xax, xMultiplicandHi
  imul xMultiplierHi
  mov xTempHiLo, xax
  mov xTempHiHi, xdx

; Do a mixed product
  mov xax, xMultiplicandHi
  mul xMultiplierLo
  add xTempLoHi, xax
  adc xTempHiLo, xdx
  adc xTempHiHi, 0

; Do the other mixed product
  mov xax, xMultiplierHi
  mul xMultiplicandLo

; Pick up the answer
  mov xcx, xdx
  mov xdx, xax
  xor xbx, xbx

  mov xax, xTempLoLo
  add xdx, xTempLoHi
  adc xcx, xTempHiLo
  adc xbx, xTempHiHi

  ret
ProcName endp
