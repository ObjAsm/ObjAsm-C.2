; ==================================================================================================
; Title:      DialogModeless.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of modeless dialog objects.
;             Version C.1.0, February 2003
;               - First release.
; ==================================================================================================


DLGDESTROYED  equ   -1                            ;Notification code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     DialogModeless
; Purpose:    This object provides the functionality of modeless dialogs.
;             It is prepared to work seamlessly with the ObjAsm application framework using one of
;             the descendant objects of WinApp, like DlgApp, SdiApp or MdiApp. The hActiveMlsDlg
;             member must be set to the current active modeless so that the application run method
;             is able to process the dialog messages. Check the SdiApp.Run or MdiApp.Run
;             implementations.

Object DialogModeless, DialogModelessID, Dialog
  RedefineMethod    DestroyDialog,      XWORD
  RedefineMethod    Init,               POINTER, HWND, POINTER, POINTER
  RedefineMethod    OnDestroy,          WPARAM, LPARAM
  RedefineMethod    Show

  VirtualEvent      OnActivate,         WM_ACTIVATE

  DefineVariable    pActiveDlgHandle,   POINTER         ;Usually -> WinApp.hActiveMlsDlg (HWND)
  DefineVariable    hPrvActiveDlg,      HWND,     0
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DialogModeless.DestroyDialog
; Purpose:    Destroy a modeless dialog
; Arguments:  Arg1: Windows return value.
; Return:     Nothing.

Method DialogModeless.DestroyDialog, uses xsi, xArgument:XWORD
  SetObject xsi
  ACall xsi.DestroyDialog, xArgument
  invoke DestroyWindow, [xsi].hWnd
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DialogModeless.Init
; Purpose:    Initialize the DialogModeless object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> Template Name or Resource ID.
;             Arg4: -> HANDLE that identifies the current active modeless dialog.
; Return:     Nothing.

Method DialogModeless.Init,, pOwner:POINTER, hParent:HWND, pTemplate:POINTER, pActDlgHandle:POINTER
  SetObject xcx
  m2m [xcx].pActiveDlgHandle, pActDlgHandle, xax
  ACall xcx.Init, pOwner, hParent, pTemplate
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DialogModeless.OnActivate
; Purpose:    Event procedure for WM_ACTIVATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if processed.

Method DialogModeless.OnActivate,, wParam:WPARAM, lParam:LPARAM
  SetObject xcx
  mov xdx, [xcx].pActiveDlgHandle
  .if xdx != NULL
    mov xax, wParam
    .if ax == WA_INACTIVE
      ;Restore old handle
      m2m HWND ptr [xdx], [xcx].hPrvActiveDlg, xax
    .else
      ;Save the current HANDLE and set our dialog to process its messages
      m2m [xcx].hPrvActiveDlg, HANDLE ptr [xdx], xax
      m2m HWND ptr [xdx], [xcx].hWnd, xax
    .endif
  .endif
  invoke DefWindowProc, [xcx].hWnd, WM_ACTIVATE, wParam, lParam    ;Perform default processing
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DialogModeless.OnDestroy
; Purpose:    Event procedure for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method DialogModeless.OnDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  local NMH:NMHDR

  SetObject xsi
  mrm NMH.hwndFrom, [xsi].hWnd, xcx
  mov NMH.idFrom, xsi
  mov NMH.code, DLGDESTROYED
  invoke SetWindowLongPtr, xcx, DWLP_USER, NULL
  invoke SendMessage, [xsi].hParent, WM_NOTIFY, pSelf, addr NMH     ;Send notification to parent
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DialogModeless.Show
; Purpose:    Show the modeless dialog.
; Arguments:  None.
; Return:     Nothing.

Method DialogModeless.Show, uses xsi
  SetObject xsi
  mov xax, $MethodAddr(Dialog.DlgProc)
  invoke CreateDialogParam, hInstance, [xsi].pTemplate, [xsi].hParent, xax, xsi ;lParam in WM_INITDIALOG
  if DEBUGGING
    .if xax == 0
      DbgApiError
    .endif
  endif
;  invoke ShowWindow, xax, SW_SHOW
MethodEnd

endif
