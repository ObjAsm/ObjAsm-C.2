; ==================================================================================================
; Title:      WinApp.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm support of WinApp objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.1.1, January 2020
;               - WinApp inherits from Window.
;               - OnNcDestroy method moved from SdiApp, MdiApp and DlgApp.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Object:     WinApp
; Purpose:    WinApp is the base object for all SDI, MDI and Dialog descendant application objects.
;             It implements basic features like modeless dialog and idle processing.

Object WinApp, WinAppID, Window
  VirtualAbstract   Run
  RedefineMethod    Init
  VirtualMethod     OnIdle,           XWORD

  VirtualEvent      OnNcDestroy,      WM_NCDESTROY

  DefineVariable    pCommandLine,     PSTRING,    NULL
  DefineVariable    hActiveMlsDlg,    HWND,       0     ;Active modeless dialog, can be only one
  DefineVariable    hAccelerators,    HACCEL,     0
ObjectEnd

; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     WinApp.Init
; Purpose:    Initialize the WinApp object.
; Arguments:  None.
; Return:     Nothing.

Method WinApp.Init
  SetObject xcx
  ACall xcx.Init, NULL, 0
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     WinApp.OnIdle
; Purpose:    Procedure called when the application is idle.
; Arguments:  Arg1: Number of times OnIdle was called since the last processed message.
; Return:     eax = Zero to stop getting more OnIdle calls.

Method WinApp.OnIdle,, xCount:XWORD
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     WinApp.OnNcDestroy
; Purpose:    Event procedure for WM_NCDESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method WinApp.OnNcDestroy,, wParam:WPARAM, lParam:LPARAM
  SetObject xcx
  invoke SetWindowLongPtr, [xcx].hWnd, DWLP_USER, NULL
  invoke PostQuitMessage, 0
  xor eax, eax
MethodEnd

endif
