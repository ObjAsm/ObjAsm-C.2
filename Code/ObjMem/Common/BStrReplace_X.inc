; ==================================================================================================
; Title:      BStrReplace_X.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.0, October 2024
;               - Initial release.
;               - Character and bitness neutral code.
;             Version C.1.1, March 2025
;               - Indirection bug corrected.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  BStrReplace
; Purpose:    Dispose a BSTR and replace it with another BSTR.
; Arguments:  Arg1: -> -> BSTR to be replaced.
;             Arg2: -> Replacing BSTR.
; Return:     xax -> Replacing BSTR or NULL if failed.

.code
align ALIGN_CODE
BStrReplace proc ppPrevBStr:POINTER, pReplBStr:POINTER
  ?mov xcx, ppPrevBStr
  invoke BStrDispose, POINTER ptr [xcx]
  invoke BStrNew, pReplBStr
  mov xcx, ppPrevBStr
  mov [xcx], xax
  ret
BStrReplace endp
