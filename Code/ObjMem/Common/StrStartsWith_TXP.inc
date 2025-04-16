; ==================================================================================================
; Title:      StrStartsWith_TXP.inc
; Author:     HSE / G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, April 2020.
;               - First release.
;               - Character, bitness and platform independent code. 
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  StrStartsWithA / StrStartsWithW 
; Purpose:    Compare the beginning of a string.
; Arguments:  Arg1: -> Analized string.
;             Arg2: -> Prefix string.
; Return:     eax = TRUE of the beginning matches, otherwise FALSE.

.code
align ALIGN_CODE
ProcName proc pString:POINTER, pPrefix:POINTER
  invoke StrLength, pPrefix
  invoke StrCComp, pString, pPrefix, eax
  test eax, eax
  jnz @F
  mov eax, TRUE
  ret
@@:
  xor eax, eax
  ret
ProcName endp
