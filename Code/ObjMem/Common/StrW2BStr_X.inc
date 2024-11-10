; ==================================================================================================
; Title:      StrW2BStr_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrW2BStr
; Purpose:    Convert a WIDE string into a BStr.
; Arguments:  Arg1: -> Destination BStr buffer = Buffer address + sizeof(DWORD).
;             Arg2: -> Source WIDE string.
; Return:     eax = Number of BYTEs in the BSTR, including the ZTC.

.code
align ALIGN_CODE
StrW2BStr proc pDstBStr:POINTER, pSrcStrW:POINTER
  invoke StrLengthW, pSrcStrW
  shl eax, 1                                            ;eax = # chars * 2
  mov xcx, pDstBStr
  mov DWORD ptr [xcx - sizeof(DWORD)], eax              ;Store it
  add eax, sizeof(CHRW)                                 ;Include the ZTC
  invoke MemClone, xcx, pSrcStrW, eax                   ;Copy the source string
  ret
StrW2BStr endp
