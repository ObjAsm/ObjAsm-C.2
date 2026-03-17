; ==================================================================================================
; Title:      DbgOpenCon_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - Initial release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  DbgOpenCon
; Purpose:    Open a new console for the calling process.
; Arguments:  None.
; Return:     eax = TRUE if it was opened, otherwise FALSE.

OPTION PROC:NONE

.code
align ALIGN_CODE
DbgOpenCon proc
  mov xax, hDbgDev
  .if xax == 0
    invoke GetConsoleWindow
    .if xax == NULL
      invoke AllocConsole
      .if eax == 0
        mov hDbgDev, INVALID_HANDLE_VALUE
        ret 0
      .endif
    .endif
    invoke SetConsoleTitleW, offset szDbgSrc
    invoke GetStdHandle, STD_OUTPUT_HANDLE
    mov hDbgDev, xax
    mov eax, TRUE
  .elseif xax == INVALID_HANDLE_VALUE
    xor eax, eax
  .else
    mov eax, TRUE
  .endif
  ret 0
DbgOpenCon endp

OPTION PROC:DEFAULT

end
