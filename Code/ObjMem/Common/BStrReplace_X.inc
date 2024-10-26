; ==================================================================================================
; Title:      BStrReplace_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2024
;               - First release.
;               - Character and bitness neutral code.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrReplace
; Purpose:    Dispose an existing BSTR and replace it with a new one.
; Arguments:  Arg1: -> BSTR to be replaced.
;             Arg2: -> new BSTR.
; Return:     rax -> New allocated BSTR or NULL if failed.

align ALIGN_CODE
BStrReplace proc pOldBStr:POINTER, pNewBStr:POINTER
  invoke BStrDispose, pOldBStr
  mov pOldBStr, $invoke(BStrNew, pNewBStr)
  ret
BStrReplace endp
