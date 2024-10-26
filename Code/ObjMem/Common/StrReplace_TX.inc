; ==================================================================================================
; Title:      StrReplace_TX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2024
;               - First release.
;               - Character and bitness neutral code.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrReplaceA / StrReplaceW
; Purpose:    Dispose an existing string and replace it with a new one.
; Arguments:  Arg1: -> String to be replaced.
;             Arg2: -> New string.
; Return:     rax -> New allocated string or NULL if failed.

align ALIGN_CODE
ProcName proc pOldString:POINTER, pNewString:POINTER
  invoke StrDispose, pOldString
  mov pOldString, $invoke(StrNew, pNewString)
  ret
ProcName endp
