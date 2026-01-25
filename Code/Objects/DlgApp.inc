; ==================================================================================================
; Title:      DlgApp.inc
; Author:     G. Friedrich
; Version:    C.1.3
; Purpose:    ObjAsm support of Dialog based Application objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.1.1, January 2020
;               - DlgApp.OnNCDestroy moved to WinApp.
;             Version C.1.2, May 2024
;               - DlgApp.WndProc corrected to support child dialogs.
;             Version C.1.3, September 2025
;               - DlgApp.Run corrected.
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Object:     DlgApp
; Purpose:    Implement a specialised WinApp object using a dialog as main window.

Object DlgApp, DlgAppID, WinApp                         ;Dialog based Application.
  VirtualMethod     CtlsGet
  VirtualMethod     CtlsSet

  VirtualEvent      OnInitDialog,   WM_INITDIALOG

  RedefineMethod    Run
  RedefineMethod    WndProc,        DWORD, WPARAM, LPARAM
ObjectEnd


; ==================================================================================================
;    DlgApp implementation
; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     DlgApp.CtlsGet
; Purpose:    Do nothing at this stage. It has to be redefined to provide proper functionality.
; Arguments:  None.
; Return:     Nothing.

Method DlgApp.CtlsGet
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DlgApp.CtlsSet
; Purpose:    Do nothing at this stage. It has to be redefined to provide proper functionality.
; Arguments:  None.
; Return:     Nothing.

Method DlgApp.CtlsSet
MethodEnd

;; --------------------------------------------------------------------------------------------------
;; Method:     DlgApp.Init   - code sample-
;; Purpose:    Initialize the dialog based application object.
;; Arguments:  None.
;; Return:     Nothing.
;
;Method DlgApp.Init, uses xsi
;  SetObject xsi
;  ACall xsi.Init
;  invoke CreateDialogParam, hInstance, offset szDlgName, 0, $MethodAddr(DlgApp.WndProc), xsi
;MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DlgApp.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = TRUE to direct the system to set the keyboard focus to the control specified by
;             wParam. Otherwise, it should return FALSE to prevent the system from setting the
;             default keyboard focus.

Method DlgApp.OnInitDialog, uses xsi, wParam:WPARAM, lParam:LPARAM
  ;DbgText "DlgApp.OnInitDialog"
  SetObject xsi
  ACall xsi.InitWindow
  OCall xsi.CtlsSet
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DlgApp.Run
; Purpose:    Launch the dialog based application object starting the message loop.
; Arguments:  None.
; Return:     xax = Exit code passed to PostQuitMessage.
; Note:       xdi = Idle counter.

Method DlgApp.Run, uses xbx xdi xsi
  local Msg:MSG

;  DbgText "DlgApp.Run"
  SetObject xsi
  lea xbx, Msg
  xor edi, edi
  .if [xsi].hWnd != 0
    .repeat
      invoke PeekMessage, xbx, 0, 0, 0, PM_REMOVE
      .if eax == FALSE
        OCall xsi.OnIdle, xdi
        .if eax == 0
          invoke WaitMessage
        .else
          inc xdi
        .endif
      .else
        .break .if Msg.message == WM_QUIT
        .if [xsi].hActiveMlsDlg != 0
          .if $invoke(IsDialogMessage, [xsi].hActiveMlsDlg, xbx) == 0
            .if $invoke(TranslateAccelerator, [xsi].hActiveMlsDlg, [xsi].hAccelerators, xbx) == 0
              invoke TranslateMessage, xbx
              invoke DispatchMessage, xbx
            .endif
          .endif
        .else
          .if $invoke(IsDialogMessage, [xsi].hWnd, xbx) == 0
            .if $invoke(TranslateAccelerator, [xsi].hWnd, [xsi].hAccelerators, xbx) == 0
              invoke TranslateMessage, xbx
              invoke DispatchMessage, xbx
            .endif
          .endif
        .endif
        xor edi, edi
      .endif
    .until FALSE
    mov xax, Msg.wParam
  .else
    mov xax, -1
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DlgApp.WindowProc
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     xax = This value is the result of the message processing and depends on the message.
; Note:       Window handle is passed in pSelf (hidden parameter).

Method DlgApp.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg,, "DlgApp Messages"
  .if uMsg == WM_INITDIALOG
    mov xsi, lParam
    test xsi, xsi
    jz @@EOM
    mrm [xsi].$Obj(DlgApp).hWnd, pSelf, xcx             ;pSelf = hWnd
    invoke SetWindowLongPtr, xcx, DWLP_USER, xsi
  .else
    invoke GetWindowLongPtr, pSelf, DWLP_USER
    test xax, xax
    jz @@EOM
    mov xsi, xax
  .endif
  DispatchEvent                                         ;xsi -> Object Instance
MethodEnd

endif
