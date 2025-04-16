; ==================================================================================================
; Title:      SetClientSize_X.inc
; Author:     MichelW / G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, January 2021
;               - Code based on this article:
;                 https://devblogs.microsoft.com/oldnewthing/20030911-00/?p=42553
;             Version C.1.0, October 2017
;               - First release
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  SetClientSize
; Purpose:    Set the client window size.
; Arguments:  Arg1: Target window handle.
;             Arg2: Client area width in pixel.
;             Arg3: Client area height in pixel.
; Return:     Nothing.

.code
align ALIGN_CODE
SetClientSize proc uses xbx hWnd:HWND, dCx:DWORD, dCy:DWORD
  local hMenu:HMENU, rcWindow:RECT, rcTemp:RECT

  mov hMenu, $invoke(GetMenu, hWnd)
  mov rcWindow.left, 0
  mov rcWindow.top, 0
  m2m rcWindow.right, dCx, eax
  m2m rcWindow.bottom, dCy, eax

  ;First convert the client rectangle to a window rectangle
  ;the menu-wrap-agnostic way.
  invoke GetWindowLongPtr, hWnd, GWL_STYLE
  mov ebx, eax
  invoke GetWindowLongPtr, hWnd, GWL_EXSTYLE
  lea xcx, rcWindow
  mov edx, ebx
  xor ebx, ebx
  .if hMenu != 0
    inc ebx
  .endif
  invoke AdjustWindowRectEx, xcx, edx, ebx, eax

  ;If there is a menu, then check how much wrapping occurs when we set a
  ;window to the width specified by AdjustWindowRect and an infinite amount
  ;of height. An infinite height allows us to see every single menu wrap.
  .if ebx != 0
    s2s rcTemp, rcWindow, xax, xcx, xdx, xmm0, xmm1, xmm2, xmm3
    mov rcTemp.bottom, 7FFFh                            ;"Infinite" height
    invoke SendMessage, hWnd, WM_NCCALCSIZE, FALSE, addr rcTemp

    ;Adjust our previous calculation to compensate for menu wrapping.
    mov eax, rcTemp.top
    add rcWindow.bottom, eax
  .endif

  mov eax, rcWindow.right
  sub eax, rcWindow.left
  mov ebx, rcWindow.bottom
  sub ebx, rcWindow.top 
  invoke SetWindowPos, hWnd, NULL, 0, 0, eax, ebx, SWP_NOMOVE or SWP_NOZORDER
  ret
SetClientSize endp


;Version C.1.0 - fails if menu folding changes while modifying the window size
;SetClientSize proc hWnd:HWND, dPixelWidth:DWORD, dPixelHeight:DWORD
;  local CRect:RECT, WRect:RECT, WndSize:POINT
;
;  invoke GetClientRect, hWnd, addr CRect
;  invoke GetWindowRect, hWnd, addr WRect
;
;  mov ecx, WRect.right
;  sub ecx, WRect.left
;  add ecx, dPixelWidth
;  sub ecx, CRect.right
;  mov WndSize.x, ecx
;
;  mov edx, WRect.bottom
;  sub edx, WRect.top
;  add edx, dPixelHeight
;  sub edx, CRect.bottom
;  mov WndSize.y, edx
;
;  invoke MoveWindow, hWnd, WRect.left, WRect.top, WndSize.x, WndSize.y, TRUE
;
;  ret
;SetClientSize endp
