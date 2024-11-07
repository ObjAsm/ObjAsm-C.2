; ==================================================================================================
; Title:      StrW2NewStrA_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2024.
;               - First release.
;               - Bitness neutral code.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrW2NewStrA
; Purpose:    Create a new StringA with the content of a STRINGW.
; Arguments:  Arg1: -> STRINGW.
; Return:     xax -> STRINGW. When no longer needed, it must be freed using StrDisposeA.

.code
align ALIGN_CODE
StrW2NewStrA proc pStringW:POINTER
  local pStringA:PSTRINGA, dCharCount:DWORD

  invoke StrLengthW, pStringW
  mov dCharCount, eax
  invoke StrAllocA, eax
  .if xax != NULL
    mov pStringA, xax
    inc dCharCount
    invoke WideCharToMultiByte, CP_ACP, 0, pStringW, dCharCount, xax, dCharCount, NULL, NULL
    mov xax, pStringA
  .endif
  ret
StrW2NewStrA endp