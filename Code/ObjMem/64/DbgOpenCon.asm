; ==================================================================================================
; Title:      DbgOpenCon.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  DbgOpenCon
; Purpose:    Open a new console for the calling process.
; Arguments:  None.
; Return:     rax = TRUE if it was opened, otherwise FALSE.

.code
align ALIGN_CODE
DbgOpenCon proc
  .if hDbgDev == 0
    .if $invoke(AllocConsole)
      invoke SetConsoleTitleW, offset szDbgSrc
      mov hDbgDev, $invoke(GetStdHandle, STD_OUTPUT_HANDLE)
    .else
      mov hDbgDev, -1
      xor eax, eax
    .endif
  .else
    xor eax, eax
    inc eax
  .endif
  ret
DbgOpenCon endp

end
