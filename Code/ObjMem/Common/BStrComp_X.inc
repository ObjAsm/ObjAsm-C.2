; ==================================================================================================
; Title:      BStrComp_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2024.
;               - First release.
;               - Bitness neutral code.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrComp
; Purpose:    Compare 2 BSTRs.
; Arguments:  Arg1: First BSTR.
;             Arg2: Second BSTR.
; Return:     eax = 0 if both BSTRs are identical, otherwise non zero.

.code
align ALIGN_CODE
BStrComp proc bstr1:POINTER, bstr2:POINTER
  ?mov xcx, bstr1
  ?mov xdx, bstr2
  mov eax, DWORD ptr [xcx - sizeof DWORD]
  sub eax, DWORD ptr [xdx - sizeof DWORD]
  .if ZERO?
    invoke StrCompW, xcx, xdx
  .endif
  ret
BStrComp endp