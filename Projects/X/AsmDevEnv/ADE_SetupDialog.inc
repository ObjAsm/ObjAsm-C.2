; ==================================================================================================
; Title:      ADE_SetupDialog.inc
; Author:     G. Friedrich
; Version:    See ADE.asm
; Purpose:    ObjAsm Setup dialog implementation.
; ==================================================================================================


; ==================================================================================================
; SetupDlg implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     SetupDialog.CtlsGet
; Purpose:    Read the setting of all controls.
; Arguments:  None.
; Return:     Nothing.

Method SetupDialog.CtlsGet, uses xsi
  SetObject xsi
  OCall [xsi].TabDialog1::Tab1.CtlsGet
  OCall [xsi].TabDialog2::Tab2.CtlsGet
  mov eax, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SetupDialog.CtlsSet
; Purpose:    Set the controls of the setup dialog.
; Arguments:  None.
; Return:     eax = this procedure should return TRUE to direct Windows to set the keyboard focus to
;                   the control specified by hwndFocus. Otherwise, it should return FALSE to prevent
;                   Windows from setting the default keyboard focus.

Method SetupDialog.CtlsSet
  ;No controls to setup!
  mov eax, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SetupDialog.Done
; Purpose:    Finalize the SetupDialog object.
; Arguments:  None.
; Return:     Nothing.

Method SetupDialog.Done, uses xsi
  SetObject xsi
  OCall [xsi].IconImageList::MaskedImageList.Done
  OCall [xsi].TabDialog1::Tab1.Done
  OCall [xsi].TabDialog2::Tab2.Done
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SetupDialog.Init
; Purpose:    Initialaize a SetupDialog object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> Parent window HANDLE.
; Return:     Nothing.

Method SetupDialog.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND
  SetObject xsi
  ACall xsi.Init, pOwner, hParent, $OfsCStr("DIALOGSETUP")

  lea xbx, [xsi].IconImageList
  OCall xbx::MaskedImageList.Init, xsi, 16, 16, 2
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_NEW")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_SETUP")
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SetupDialog.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method SetupDialog.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  ANNOTATION use:wParam lParam

  SetObject xsi
  LoWord(wParam)
  .if ax == IDOK
    OCall xsi.CtlsGet
    OCall xsi.DestroyDialog, wParam
  .elseif ax == IDCANCEL
    OCall xsi.DestroyDialog, wParam
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SetupDialog.OnDestroy
; Purpose:    Event procedure for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method SetupDialog.OnDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  ANNOTATION use:wParam lParam

  SetObject xsi
  invoke SetWindowLongPtr, [xsi].hWnd, DWLP_USER, NULL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SetupDialog.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = FALSE.

Method SetupDialog.OnInitDialog, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  lea xbx, [xsi].TabControl
  OCall xbx::TabCtrl.Init, xsi, [xsi].hWnd, addr [xsi].IconImageList, offset SetupTabCtrl

  OCall [xsi].TabDialog1::Tab1.Init, xbx, [xbx].$Obj(TabCtrl).hWnd, $OfsCStr("SETUPTAB1")
  OCall [xsi].TabDialog1::Tab1.Show
  invoke ShowWindow, [xsi].TabDialog1.hWnd, SW_SHOWDEFAULT

  OCall [xsi].TabDialog2::Tab2.Init, xbx, [xbx].$Obj(TabCtrl).hWnd, $OfsCStr("SETUPTAB2"), \
                                               addr $ObjTmpl(Application).hActiveMlsDlg

  OCall [xsi].TabDialog2::Tab2.Show
  invoke ShowWindow, [xsi].TabDialog2.hWnd, SW_HIDE

  OCall xbx::TabCtrl.Insert, 0, [xsi].TabDialog1.hWnd, $OfsCStr("Setup 1"), 0
  OCall xbx::TabCtrl.Insert, 1, [xsi].TabDialog2.hWnd, $OfsCStr("Setup 2"), 1
  ACall xsi.OnInitDialog, wParam, lParam
MethodEnd



; ==================================================================================================
;    Tab1 implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     Tab1.Init
; Purpose:    Initialize the Tab1 object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> Template name or Resource ID.
; Return:     Nothing.

Method Tab1.Init, uses xsi, pOwner:POINTER, hParent:HWND, pTemplate:POINTER
  SetObject xsi
  ACall xsi.Init, pOwner, hParent, pTemplate, addr $ObjTmpl(Application).hActiveMlsDlg
  mov [xsi].hBackBrush, $invoke(CreateHatchBrush, HS_DIAGCROSS, $RGB(0, 0, 255))
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Tab1.Done
; Purpose:    Finalize the Tab1 object.
; Arguments:  None.
; Return:     Nothing.

Method Tab1.Done, uses xsi
  SetObject xsi
  invoke DeleteObject, [xsi].hBackBrush
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Tab1.OnCtlColorStatic
; Purpose:    Event procedure for WM_CTLCOLORSTATIC message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Brush handle that Windows uses to paint the background of the static control.

Method Tab1.OnCtlColorStatic, uses xsi, wParam:WPARAM, lParam:LPARAM
  ANNOTATION use:wParam lParam

  SetObject xsi
  invoke GetDlgItem, [xsi].hWnd, IDC_CONTROL
  .if xax == lParam
    mov xax, [xsi].hBackBrush
  .else
    xor eax, eax
  .endif
MethodEnd



; ==================================================================================================
;    Tab2 implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     Tab2.CtlsGet
; Purpose:    Read the setting of all controls.
; Arguments:  None.
; Return:     Nothing.

Method Tab2.CtlsGet, uses xsi
  SetObject xsi
  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_CHOICE1
  .if eax == BST_CHECKED
    m2z dSetupOption1
  .else
    invoke IsDlgButtonChecked, [xsi].hWnd, IDC_CHOICE2
    .if eax == BST_CHECKED
      mov dSetupOption1, 1
    .else
      invoke IsDlgButtonChecked, [xsi].hWnd, IDC_CHOICE3
      .if eax == BST_CHECKED
        mov dSetupOption1, 2
      .else
        mov dSetupOption1, 3
      .endif
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Tab2.CtlsSet
; Purpose:    Set the controls of the setup dialog.
; Arguments:  None.
; Return:     eax = this procedure should return TRUE to direct Windows to set the keyboard focus to
;                   the control specified by hwndFocus. Otherwise, it should return FALSE to prevent
;                   Windows from setting the default keyboard focus.

Method Tab2.CtlsSet
  SetObject xcx
  mov eax, IDC_CHOICE1
  add eax, dSetupOption1
  invoke CheckRadioButton, [xcx].hWnd, IDC_CHOICE1, IDC_CHOICE4, eax
MethodEnd
