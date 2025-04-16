; ==================================================================================================
; Title:      OA_Tools_Client.inc
; Author:     G. Friedrich
; Version:    See OA_Tools.asm
; Purpose:    ObjAsm Tools.
; ==================================================================================================



; ==================================================================================================
;    OAT_Client implementation
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Method:     OAT_Client.Done
; Purpose:    Finalize the OAT_Client object.
; Arguments:  None.
; Return:     Nothing.

Method OAT_Client.Done, uses xsi
  SetObject xsi
  invoke DeleteObject, [xsi].hBGBrush
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     OAT_Client.Init
; Purpose:    Initialize the MdiClientWnd object.
; Arguments:  Arg1: -> Owner object.
; Return:     Nothing.

Method OAT_Client.Init, uses xsi, pOwner:POINTER
  local hBmp:HBITMAP

  SetObject xsi
  ACall xsi.Init, pOwner
  mov hBmp, $invoke(LoadBitmap, hInstance, $OfsCStr("BMP_BACKGROUND"))
  mov [xsi].hBGBrush, $invoke(CreatePatternBrush, hBmp)
  invoke DeleteObject, hBmp
  invoke DragAcceptFiles, [xsi].hWnd, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     OAT_Client.OnDropFiles
; Purpose:    Event procedure for WM_DROPFILES message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method OAT_Client.OnDropFiles, uses xbx, wParam:WPARAM, lParam:LPARAM
  local Pnt:POINT

  SetObject xcx
  mov xbx, [xcx].pOwner                                 ;xbx -> Application
  ?mov xdx, wParam
  mov [xbx].$Obj(Application).hDrop, xdx
  invoke GetCursorPos, addr Pnt
  invoke GetSubMenu, [xbx].$Obj(Application).hMenuDropContext, 0
  invoke TrackPopupMenu, xax, TPM_LEFTALIGN, Pnt.x, Pnt.y, 0, $ObjTmpl(Application).hWnd, NULL
  invoke PostMessage, [xbx].$Obj(Application).hWnd, WM_NULL, 0, 0
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     OAT_Client.OnEraseBkgnd
; Purpose:    Event procedure for WM_ERASEBKGND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Non zero => we do the job.

Method OAT_Client.OnEraseBkgnd,, wParam:WPARAM, lParam:LPARAM
  mov eax, 1
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     OAT_Client.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method OAT_Client.OnPaint, uses xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, Rct1:RECT

  SetObject xsi
  invoke BeginPaint, [xsi].hWnd, addr PS
  invoke GetClientRect, [xsi].hWnd, addr Rct1
  invoke FillRect, PS.hdc, addr Rct1, [xsi].hBGBrush
  invoke EndPaint, [xsi].hWnd, addr PS
  invoke CallWindowProc, [xsi].$Obj(OAT_Client).pPrevWndProc, \
                         [xsi].$Obj(OAT_Client).hWnd, \
                         WM_PAINT, wParam, lParam
MethodEnd
