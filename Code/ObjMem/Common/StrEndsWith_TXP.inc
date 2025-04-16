; ==================================================================================================
; Title:      StrEndsWith_TXP.inc
; Author:     G. Friedrich
; Version:    C.1.2
; Notes:      Version C.1.2, December 2020.
;               - xbx preservation added by HSE.
;             Version C.1.1, April 2020.
;               - First release.
;               - Character, bitness and platform independent code.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  StrEndsWithA / StrEndsWithW
; Purpose:    Compare the ending of a string.
; Arguments:  Arg1: -> Analized string.
;             Arg2: -> Suffix string.
; Return:     eax = TRUE of the ending matches, otherwise FALSE.

.code
align ALIGN_CODE
ProcName proc uses xbx pString:POINTER, pSuffix:POINTER
  invoke StrEnd, pString
  mov xbx, xax
  invoke StrSize, pSuffix
  sub xax, sizeof(CHR)                                  ;Skip ZTC
  sub xbx, xax
  cmp xbx, pString
  jl @F
  invoke MemComp, xbx, pSuffix, eax
  test eax, eax
  jnz @F
  mov eax, TRUE
  ret
@@:
  xor eax, eax
  ret
ProcName endp
