; ==================================================================================================
; Title:      StrA2NewStrW_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2024.
;               - First release.
;               - Bitness neutral code.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  StrA2NewStrW
; Purpose:    Create a new StringW with the content of a STRINGA.
; Arguments:  Arg1: -> STRINGA.
; Return:     xax -> STRINGW. When no longer needed, it must be freed using StrDisposeW.

.code
align ALIGN_CODE
StrA2NewStrW proc pStringA:POINTER
  local pStringW:PSTRINGW, dCharCount:DWORD

  invoke StrLengthA, pStringA
  mov dCharCount, eax
  invoke StrAllocW, eax
  .if xax != NULL
    mov pStringW, xax
    inc dCharCount
    invoke MultiByteToWideChar, CP_ACP, 0, pStringA, dCharCount, xax, dCharCount
    mov xax, pStringW
  .endif
  ret
StrA2NewStrW endp