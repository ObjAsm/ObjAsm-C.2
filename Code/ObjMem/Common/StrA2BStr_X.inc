; ==================================================================================================
; Title:      StrA2BStr_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrA2BStr
; Purpose:    Convert a ANSI string into a BStr.
; Arguments:  Arg1: -> Destination BStr buffer = Buffer address + sizeof(DWORD).
;             Arg2: -> Source ANSI string.
; Return:     eax = Number of BYTEs in the BSTR, including the ZTC.

.code
align ALIGN_CODE
StrA2BStr proc pDstBStr:POINTER, pSrcStrA:POINTER
  local dSize:DWORD

  invoke StrSizeA, pSrcStrA
  mov dSize, eax
  invoke MultiByteToWideChar, CP_ACP, 0, pSrcStrA, dSize, pDstBStr, dSize
  add eax, eax                                          ;Get number of BYTEs
  mov xdx, pDstBStr
  lea ecx, [eax - sizeof(CHRW)]                         ;Subract ZTC space
  mov DWORD ptr [xdx - sizeof(DWORD)], ecx              ;Store BSTR storage
  ret
StrA2BStr endp
