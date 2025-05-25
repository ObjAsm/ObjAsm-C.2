; ==================================================================================================
; Title:      BStrReplace_X.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.0, October 2024
;               - First release.
;               - Character and bitness neutral code.
;             Version C.1.1, March 2025
;               - Indirection bug corrected.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  BStrReplace
; Purpose:    Dispose an existing BSTR and replace it with a new one.
; Arguments:  Arg1: -> BSTR to be replaced.
;             Arg2: -> new BSTR.
; Return:     rax -> New allocated BSTR or NULL if failed.

.code
align ALIGN_CODE
BStrReplace proc ppOldBStr:POINTER, pNewBStr:POINTER
  mov xax, ppOldBStr
  invoke BStrDispose, POINTER ptr [xax]
  invoke BStrNew, pNewBStr
  mov xcx, ppOldBStr
  mov [xcx], xax
  ret
BStrReplace endp
