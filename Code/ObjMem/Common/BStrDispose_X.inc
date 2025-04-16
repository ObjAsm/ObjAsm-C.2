; ==================================================================================================
; Title:      BStrDispose_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2024
;               - First release.
;               - Bitness neutral code.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  BStrDispose
; Purpose:    Free the memory allocated for the string using BStrNew, BStrCNew, BStrLENew or
;             BStrAlloc.
;             If the pointer to the string is NULL, BStrDispose does nothing.
; Arguments:  Arg1: BSTR.
; Return:     Nothing.

.code
align ALIGN_CODE
BStrDispose proc bstr:POINTER
  ?mov ecx, bstr
  .if xcx != NULL                   
    invoke SysFreeString, xcx
  .endif
  ret
BStrDispose endp
