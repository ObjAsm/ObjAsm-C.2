; ==================================================================================================
; Title:      IsScrollBarVisible.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  IsScrollBarVisible
; Purpose:    Determine if a Scrollbar is currently visible. 
; Arguments:  Arg1: Main window HANDLE that the scrollbar belongs to.
;             Arg2: Scrollbar type [SB_HORZ or SB_VERT].
; Return:     eax = TRUE if the scrollbar is visible, otherwise FALSE.

.code
align ALIGN_CODE
IsScrollBarVisible proc hWnd:HWND, dScrollbarType:DWORD
  invoke GetWindowLongPtr, rcx, GWL_STYLE
  mov ecx, dScrollbarType
  .if ((ecx == SB_HORZ) && (eax & WS_HSCROLL)) || \
      ((ecx == SB_VERT) && (eax & WS_VSCROLL))
    mov eax, TRUE
    ret
  .endif
  xor eax, eax
  ret
IsScrollBarVisible endp

end
