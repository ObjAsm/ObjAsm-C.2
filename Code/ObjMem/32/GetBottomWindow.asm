; ==================================================================================================
; Title:      GetBottomWindow.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  GetBottomWindow
; Purpose:    Get the Z order bottom child window HANDLE.
; Arguments:  Arg1: Parenat HWND.
; Return:     eax = Z order bottom child window HANDLE.

.code
align ALIGN_CODE
GetBottomWindow proc uses edi hWnd:HANDLE
  invoke GetTopWindow, hWnd
  .while eax != 0
    mov edi, eax
    invoke GetWindow, eax, GW_HWNDNEXT
  .endw
  mov eax, edi
  ret
GetBottomWindow endp

end
