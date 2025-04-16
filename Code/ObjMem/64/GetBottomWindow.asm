; ==================================================================================================
; Title:      GetBottomWindow.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  GetBottomWindow
; Purpose:    Get the Z order bottom child window HANDLE.
; Arguments:  Arg1: Parent HWND.
; Return:     eax =  Z order bottom child window HANDLE.

.code
align ALIGN_CODE
GetBottomWindow proc uses rdi hWnd:HANDLE
  invoke GetTopWindow, hWnd
  .while rax != 0
    mov rdi, rax
    invoke GetWindow, rax, GW_HWNDNEXT
  .endw
  mov rax, rdi
  ret
GetBottomWindow endp

end
