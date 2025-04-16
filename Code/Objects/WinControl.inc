; ==================================================================================================
; Title:      WinControl.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of base object for common controls Version 5.81.
;             Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


;WCTRL_RESOURCE      equ     BIT00

; --------------------------------------------------------------------------------------------------
; Object:     WinControl
; Purpose:    This object is the ancestor of all Windows control wrapper objects and implements
;             the basic methods, common for all descendant objects.
;             Getting OS controls is done using subclassing. First, the control is created,
;             returning a Window HANDLE and then the message processing loop is redirected to the
;             object dispatching method. If no matching message ID is found, the message is passed
;             to the original control message handler.

Object WinControl, WinControlID, WinPrimer
  VirtualMethod     Dispatch,       HWND, DWORD, WPARAM, LPARAM
  VirtualMethod     GetHeight
  VirtualMethod     GetWidth
  VirtualAbstract   WndProc,        DWORD, WPARAM, LPARAM

  DefineVariable    pPrevWndProc,   POINTER,    NULL
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     WinControl.Dispatch
; Purpose:    Processing of window messages. Before invoking it, the window must be subclassed.
; Arguments:  Arg1: Window handle.
;             Arg2: Message identifier.
;             Arg3: First message parameter.
;             Arg4: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.

Method WinControl.Dispatch, uses xsi, hWnd:HWND, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  DispatchEvent <CallWindowProc, [xsi].pPrevWndProc, hWnd>    ;xsi -> Object instance
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     WinControl.GetHeight
; Purpose:    Return the control height in pixels.
; Arguments:  None.
; Return:     eax = Height.

Method WinControl.GetHeight
  local WndRect:RECT

  SetObject xcx
  invoke GetWindowRect, [xcx].hWnd, addr WndRect
  mov eax, WndRect.bottom
  sub eax, WndRect.top
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     WinControl.GetWidth
; Purpose:    Return the control width in pixels.
; Arguments:  None.
; Return:     eax = Width.

Method WinControl.GetWidth
  local WndRect:RECT

  SetObject xcx
  invoke GetWindowRect, [xcx].hWnd, addr WndRect
  mov eax, WndRect.right
  sub eax, WndRect.left
MethodEnd

endif
