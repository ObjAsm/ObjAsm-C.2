; ==================================================================================================
; Title:      BStrReplaceWithCopy_X.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.0, October 2026
;               - Initial release.
;               - Character and bitness neutral code.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  BStrReplaceWithCopy
; Purpose:    Dispose a BSTR and replace it with a a copy of another BSTR.
; Arguments:  Arg1: -> -> BSTR to be replaced.
;             Arg2: -> Replacing source BSTR.
; Return:     xax -> Replacing BSTR copy or NULL if failed.

.code
align ALIGN_CODE
BStrReplaceWithCopy proc ppPrevBStr:POINTER, pReplBStr:POINTER
  invoke BStrNew, pReplBStr
  .if xax != NULL
    invoke BStrReplace, ppPrevBStr, xax
  .endif
  ret
BStrReplaceWithCopy endp
