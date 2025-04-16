; ==================================================================================================
; Title:      BStr2NewStrA_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2024.
;               - First release.
;               - Bitness neutral code.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  BStr2NewStrA
; Purpose:    Create a new STRINGA with the content of a BSTR.
; Arguments:  Arg1: BSTR.
; Return:     xax -> STRINGA. When no longer needed, it must be freed using StrDisposeA.

.code
align ALIGN_CODE
BStr2NewStrA proc bstr:POINTER
  local pBuffer:PSTRING, dBufferLen:DWORD

  invoke WideCharToMultiByte, CP_ACP, 0, bstr, -1, pBuffer, 0, NULL, NULL
  .if eax != 0
    mov dBufferLen, eax
    invoke GlobalAlloc, GPTR, eax
    mov pBuffer, xax
    invoke WideCharToMultiByte, CP_ACP, 0, bstr, -1, pBuffer, dBufferLen, NULL, NULL
    mov xax, pBuffer
  .endif
  ret
BStr2NewStrA endp
