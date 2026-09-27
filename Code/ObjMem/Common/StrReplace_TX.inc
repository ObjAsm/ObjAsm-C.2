; ==================================================================================================
; Title:      StrReplace_TX.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.0, October 2024
;               - Initial release.
;               - Character and bitness neutral code.
;             Version C.1.1, March 2025
;               - Indirection bug corrected.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  StrReplaceA / StrReplaceW
; Purpose:    Dispose a string and replace it with another string.
; Arguments:  Arg1: -> -> String to be replaced.
;             Arg2: -> Replacing string.
; Return:     xax -> Replacing string or NULL if failed.

.code
align ALIGN_CODE
ProcName proc ppPrevString:POINTER, pReplString:POINTER
  ?mov xcx, ppPrevString
  invoke StrDispose, POINTER ptr [xcx]
  mov xcx, ppPrevString
  mov xax, pReplString
  mov [xcx], xax
  ret
ProcName endp
