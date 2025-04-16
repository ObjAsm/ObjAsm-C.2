; ==================================================================================================
; Title:      StrW2NewBStr_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2024.
;               - First release.
;               - Bitness neutral code.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  StrW2NewBStr
; Purpose:    Create a new BSTR with the content of a STRINGW.
; Arguments:  Arg1: -> STRINGW.
; Return:     xax = BSTR. When no longer needed, it must be freed using BStrDispose or 
;             SysFreeString.

.code
align ALIGN_CODE
StrW2NewBStr proc pStringW:POINTER
  local bstr:BSTR, dBufferSize:DWORD

  invoke StrSizeW, pStringW
  .if eax != 0
    mov dBufferSize, eax
    mov bstr, $invoke(BStrAlloc, eax)
    mov ecx, dBufferSize
    sub ecx, sizeof(CHRW)                                ;This value does not include the ZTC
    mov [xax - sizeof DWORD], ecx
    invoke MemClone, xax, pStringW, dBufferSize
    mov xax, bstr
  .endif
  ret
StrW2NewBStr endp