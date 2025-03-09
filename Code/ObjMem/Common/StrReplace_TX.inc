; ==================================================================================================
; Title:      StrReplace_TX.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.0, October 2024
;               - First release.
;               - Character and bitness neutral code.
;             Version C.1.1, March 2025
;               - Indirection bug corrected.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrReplaceA / StrReplaceW
; Purpose:    Dispose an existing string and replace it with a new one.
; Arguments:  Arg1: -> -> String to be replaced.
;             Arg2: -> New string.
; Return:     rax -> New allocated string or NULL if failed.

.code
align ALIGN_CODE
ProcName proc ppOldString:POINTER, pNewString:POINTER
  mov xax, ppOldString
  invoke StrDispose, POINTER ptr [xax]
  invoke StrNew, pNewString
  mov xcx, ppOldString
  mov [xcx], xax
  ret
ProcName endp
