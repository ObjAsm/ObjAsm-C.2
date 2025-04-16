; ==================================================================================================
; Title:      FileExist_TX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  FileExist
; Purpose:    Check the existence of a file.
; Arguments:  Arg1: -> File name.
; Return:     eax = TRUE if the file exists, otherwise FALSE.

.code
align ALIGN_CODE
ProcName proc pFileName:POINTER
  local wfd:WIN32_FIND_DATA

  ?mov ecx, pFileName
  invoke FindFirstFile, xcx, addr wfd
  .if xax == INVALID_HANDLE_VALUE
    xor eax, eax                                        ;FALSE = NOT exist
  .else
    invoke FindClose, xax
    mov eax, TRUE                                       ;TRUE = exist
  .endif
  ret
ProcName endp
