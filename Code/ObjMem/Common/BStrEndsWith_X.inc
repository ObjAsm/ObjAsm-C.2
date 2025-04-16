; ==================================================================================================
; Title:      BStrEndsWith_X.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, April 2020.
;               - First release.
;               - Bitness neutral code.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  BStrEndsWith
; Purpose:    Compare the ending of a BSTR.
; Arguments:  Arg1: -> Analized BSTR.
;             Arg2: -> Suffix BSTR.
; Return:     eax = TRUE of the ending matches, otherwise FALSE.

.code
align ALIGN_CODE
BStrEndsWith proc pString:POINTER, pSuffix:POINTER
  ?mov xdx, pSuffix
  mov xax, pString
  mov ecx, [xax - 4]                                    ;Byte count of the analized BSTR without ZTC
  add xcx, xax
  mov eax, [xdx - 4]
  sub xcx, xax
  invoke MemComp, xcx, xdx, eax
  test eax, eax
  jnz @F
  mov eax, TRUE
  ret
@@:
  xor eax, eax
  ret
BStrEndsWith endp
