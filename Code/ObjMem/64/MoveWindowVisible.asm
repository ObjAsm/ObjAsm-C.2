; ==================================================================================================
; Title:      MoveWindowVisible.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

CheckPointAndAdjustPosition macro
  mov Pnt.x, edi
  mov Pnt.y, esi
  invoke MonitorFromPoint, Pnt, MONITOR_DEFAULTTONEAREST
  lea r8, MI
  mov MI.cbSize, sizeof(MONITORINFO)
  invoke GetMonitorInfo, rax, r8
  .if SDWORD ptr esi > MI.rcWork.bottom
    sub esi, MI.rcWork.bottom
    sub sdYPos, esi
  .elseif SDWORD ptr esi < MI.rcWork.top
    sub esi, MI.rcWork.top
    sub sdYPos, esi
  .endif

  .if SDWORD ptr edi > MI.rcWork.right
    sub edi, MI.rcWork.right
    sub sdXPos, edi
  .elseif SDWORD ptr edi < MI.rcWork.left
    sub edi, MI.rcWork.left
    sub sdXPos, edi
  .endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  MoveWindowVisible
; Purpose:    On a multimonitor system, move a window but remains always in the visible region.
; Arguments:  Arg1: HANDLE of the Window to move.
;             Arg2: Target X position in pixel.
;             Arg3: Target Y position in pixel.
; Return:     Nothing.

.code
align ALIGN_CODE
MoveWindowVisible proc uses rdi rsi hWnd:HANDLE, sdXPos:SDWORD, sdYPos:SDWORD
  local WndRect:RECT, dWndHeight:DWORD, dWndWidth:DWORD, MI:MONITORINFO, Pnt:POINT

  ;   1————————2
  ;   | Window |
  ;   3————————4

  invoke GetWindowRect, hWnd, addr WndRect
  mov eax, WndRect.right
  sub eax, WndRect.left
  mov dWndWidth, eax

  mov eax, WndRect.bottom
  sub eax, WndRect.top
  mov dWndHeight, eax

  ;Check point 4
  mov edi, sdXPos
  add edi, dWndWidth
  mov esi, sdYPos
  add esi, dWndHeight
  CheckPointAndAdjustPosition

  ;Check point 3
  mov edi, sdXPos
  mov esi, sdYPos
  add esi, dWndHeight
  CheckPointAndAdjustPosition

  ;Check point 2
  mov edi, sdXPos
  add edi, dWndWidth
  mov esi, sdYPos
  CheckPointAndAdjustPosition

  ;Check point 1
  mov edi, sdXPos
  mov esi, sdYPos
  CheckPointAndAdjustPosition

  invoke MoveWindow, hWnd, sdXPos, sdYPos, dWndWidth, dWndHeight, FALSE
  ret
MoveWindowVisible endp

end
