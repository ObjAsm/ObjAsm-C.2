; ==================================================================================================
; Title:      StrA2NewBStr_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2024.
;               - First release.
;               - Bitness neutral code.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrA2NewBStr
; Purpose:    Create a new BSTR with the content of a STRINGA.
; Arguments:  Arg1: -> STRINGA.
; Return:     xax = BSTR. When no longer needed, it must be freed using BStrDispose or 
;             SysFreeString.

.code
align ALIGN_CODE
StrA2NewBStr proc pStringA:POINTER
	local bstr:BSTR, dBufferCharCapacity:DWORD

	invoke StrSizeA, pStringA
  .if eax != 0
  	mov dBufferCharCapacity, eax
  	lea edx, [sizeof(CHRW)*eax]
  	mov bstr, $invoke(SysAllocStringByteLen, NULL, edx)
  	invoke MultiByteToWideChar, CP_ACP, 0, pStringA, -1, xax, dBufferCharCapacity
  	mov ecx, dBufferCharCapacity
  	dec ecx                                              ;This value does not include the ZTC 
  	mov xax, bstr
  	add ecx, ecx
  	mov [xax - sizeof DWORD], ecx
  .endif
	ret
StrA2NewBStr endp