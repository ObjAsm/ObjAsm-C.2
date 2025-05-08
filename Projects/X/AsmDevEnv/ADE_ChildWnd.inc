; ==================================================================================================
; Title:      ADE_ChildWnd.inc
; Author:     G. Friedrich
; Version:    See ADE.asm
; Purpose:    ObjAsm Child Window implementation.
; ==================================================================================================


; ==================================================================================================
;  ADE_ChildWnd implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     ChildWnd.Done
; Purpose:    Finalize the ChildWnd object.
; Arguments:  None.
; Return:     Nothing.

Method ChildWnd.Done, uses xsi
  SetObject xsi
  mov xax, [xsi].pOwner
  dec [xax].$Obj(ClientWnd).dChildCount
  invoke StrDispose, [xsi].pFullFileName
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ChildWnd.Init
; Purpose:    Initialize the ChildWnd object.
; Arguments:  Arg1: -> Owner object.
; Return:     Nothing.

Method ChildWnd.Init,, pOwner:POINTER
  SetObject xcx
  mov xax, pOwner                                       ;xax -> ClientWnd
  inc [xax].$Obj(ClientWnd).dChildCount
  ACall xcx.Init, pOwner, NULL                          ;hWnd is set in WndProc
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ChildWnd.OnMdiActivate
; Purpose:    Event procedure for WM_MDIACTIVATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ChildWnd.OnMdiActivate, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  ;Manage Menu, Statusbar and Toolbar options
  mov xax, lParam
  .if xax == [xsi].hWnd
    invoke GetObjectID, xsi
    mov xcx, [xsi].pOwner
    OCall [xcx].$Obj(ClientWnd).pOwner::Application.ManageGuiCmds, [xsi].hWnd
    OCall xsi.ManageEditCmds
    OCall xsi.UpdateStatusbar
  .elseif xax == NULL                                   ;Last Child!
    mov xcx, [xsi].pOwner
    OCall [xcx].$Obj(ClientWnd).pOwner::Application.ManageGuiCmds, 0
  .endif

  invoke DefMDIChildProc, [xsi].hWnd, WM_MDIACTIVATE, wParam, lParam
MethodEnd

