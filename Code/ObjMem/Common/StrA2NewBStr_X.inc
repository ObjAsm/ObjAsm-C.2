; ==================================================================================================
; Title:      StrA2NewBStr_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2024.
;               - First release.
;               - Bitness neutral code.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  StrA2NewBStr
; Purpose:    Create a new BSTR with the content of a STRINGA.
; Arguments:  Arg1: -> STRINGA.
; Return:     xax = BSTR. When no longer needed, it must be freed using BStrDispose or 
;             SysFreeString.

.code
align ALIGN_CODE
StrA2NewBStr proc uses xbx pStringA:POINTER
  local bstr:BSTR

  invoke StrLengthA, pStringA
  .if eax != 0
    mov ebx, eax
    mov bstr, $invoke(BStrAlloc, eax)
    inc ebx                                             ;Include the ZTC
    invoke MultiByteToWideChar, CP_ACP, 0, pStringA, ebx, xax, ebx
    mov xax, bstr
    lea edx, [sizeof(CHRW)*ebx - sizeof(CHRW)]          ;Convert to BYTE count, without the ZTC
    mov [xax - sizeof DWORD], edx                       ;Store the BYTE count
  .endif
  ret
StrA2NewBStr endp