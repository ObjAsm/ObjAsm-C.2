; ==================================================================================================
; Title:      GetRawClientRect_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, February 2020
;               - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetRawClientRect
; Purpose:    Calculate the window client RECT including scrollbars, but without the room needed
;             for the menubar 
; Arguments:  Arg1: Window HANDLE
;             Arg2: -> RECT.
; Return:     Nothing.

.code
align ALIGN_CODE
GetRawClientRect proc uses xbx xdi hWnd:HWND, pRect:PRECT
  mov xdi, pRect
  invoke GetClientRect, hWnd, xdi
  invoke GetWindowLongPtr, hWnd, GWL_STYLE
  mov ebx, eax
  .ifBitSet ebx, WS_HSCROLL
    invoke GetSystemMetrics, SM_CYHSCROLL
    add [xdi].RECT.bottom, eax
  .endif
  .ifBitSet ebx, WS_VSCROLL
    invoke GetSystemMetrics, SM_CXVSCROLL
    add [xdi].RECT.right, eax
  .endif
  ret
GetRawClientRect endp
