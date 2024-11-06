; ==================================================================================================
; Title:      GetDlgBaseUnits_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
;               - Bitness neutral version.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetDlgBaseUnits
; Purpose:    Return the Dialog Base Units.
; Arguments:  Arg1: Dialog DC.
; Return:     eax = X DBU.
;             ecx = Y DBU.

.code
align ALIGN_CODE
GetDlgBaseUnits proc hDC:HDC
  local StrExtend:SIZE_, TM:TEXTMETRIC

  invoke GetTextMetrics, hDC, addr TM
  invoke GetTextExtentPoint32A, hDC, \
                               $OfsCStrA("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"), \
                               52, addr StrExtend
  mov eax, StrExtend.cx_
  xor edx, edx
  mov ecx, 52
  div ecx
  mov ecx, TM.tmHeight
  ret
GetDlgBaseUnits endp
