; ==================================================================================================
; Title:      BStr2NewStrW_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2024.
;               - First release.
;               - Bitness neutral code.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  BStr2NewStrW
; Purpose:    Create a new STRINGW with the content of a BSTR.
; Arguments:  Arg1: BSTR.
; Return:     xax -> STRINGW. When no longer needed, it must be freed using StrDisposeW.

.code
align ALIGN_CODE
BStr2NewStrW proc bstr:POINTER
  local pBuffer:PSTRING, dBufferSize:DWORD

  invoke StrSizeW, bstr
  .if eax != 0
    mov dBufferSize, eax
    invoke GlobalAlloc, GPTR, eax
    mov pBuffer, xax
    invoke MemClone, xax, bstr, dBufferSize
    mov xax, pBuffer
  .endif
  ret
BStr2NewStrW endp
