; ==================================================================================================
; Title:      IsScrollBarVisible.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  IsScrollBarVisible
; Purpose:    Determine if a Scrollbar is currently visible.
; Arguments:  Arg1: Main window handle that the scrollbar belongs to.
;             Arg2: Scrollbar type [SB_HORZ or SB_VERT].
; Return:     eax = TRUE if the scrollbar is visible, otherwise FALSE.

OPTION PROC:NONE

.code
align ALIGN_CODE
IsScrollBarVisible proc hWnd:HWND, dScrollbarType:DWORD
  invoke GetWindowLong, HANDLE ptr [esp + 8], GWL_STYLE
  mov ecx, DWORD ptr [esp + 8]
  .if ((ecx == SB_HORZ) && (eax & WS_HSCROLL)) || \
      ((ecx == SB_VERT) && (eax & WS_VSCROLL))
    mov eax, TRUE
    ret 8
  .endif
  xor eax, eax
  ret 8
IsScrollBarVisible endp

OPTION PROC:DEFAULT

end
