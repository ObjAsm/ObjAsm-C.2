; ==================================================================================================
; Title:      OA_Tools_Setup.inc
; Author:     G. Friedrich
; Version:    See OA_Tools.asm
; Purpose:    ObjAsm Tools.
; ==================================================================================================



STSTYLE   equ   WS_CHILD or WS_VISIBLE or WS_TABSTOP or TCS_TABS or TCS_HOTTRACK; or TCS_FOCUSNEVER;

.const
SetupTabCtrl DEF_TABCONTROL {100, STSTYLE, WS_EX_CONTROLPARENT, NULL, {<4,3,268,200>}}

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     Tab1
; Purpose:    Tab 1 (Main) of the Setup dialog.

Object Tab1, , DialogModeless
  RedefineMethod    OnInitDialog,       WPARAM, LPARAM

  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    OnCommand,          WPARAM, LPARAM
  RedefineMethod    OnDestroy,          WPARAM, LPARAM

  VirtualEvent      OnCtlColorDlg,      WM_CTLCOLORDLG, WM_CTLCOLORSTATIC
  VirtualEvent      OnCompareItem,      WM_COMPAREITEM
  VirtualEvent      OnDrawItem,         WM_DRAWITEM
  VirtualEvent      OnMeasureItem,      WM_MEASUREITEM

  DefineVariable    hComboBox,          HANDLE,     0
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     Tab2
; Purpose:    Tab 2 (Tools) of the Setup dialog.

Object Tab2, , DialogModeless
  RedefineMethod    OnInitDialog,       WPARAM, LPARAM

  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    OnCommand,          WPARAM, LPARAM

  VirtualEvent      OnCtlColorDlg,      WM_CTLCOLORDLG, WM_CTLCOLORSTATIC
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     Tab3
; Purpose:    Tab 3 (Colors) of the Setup dialog.

Object Tab3, , DialogModeless
  RedefineMethod    OnInitDialog,       WPARAM, LPARAM

  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    OnCommand,          WPARAM, LPARAM

  VirtualEvent      OnCtlColorDlg,      WM_CTLCOLORDLG, WM_CTLCOLORSTATIC
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     OAT_Setup
; Purpose:    Custom Setup dialog.

Object OAT_Setup, , DialogModal
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    Done
  VirtualMethod     GetFileName
  RedefineMethod    Init,               POINTER, HWND
  RedefineMethod    OnCommand,          WPARAM, LPARAM
  RedefineMethod    OnDestroy,          WPARAM, LPARAM
  RedefineMethod    OnInitDialog,       WPARAM, LPARAM

  Embed     TabControl,       TabCtrl
  Embed     TabDialog1,       Tab1
  Embed     TabDialog2,       Tab2
  Embed     TabDialog3,       Tab3
  Embed     IconImageList,    MaskedImageList
ObjectEnd


; ==================================================================================================


SetItemString macro iID:req, sID:req
  mov edx, edi
  %add edx, &sID
  invoke LoadString, hInstance, edx, xbx, lengthof cBuffer
  %invoke SetDlgItemText, [xsi].hWnd, &iID, xbx
endm

GetTool macro ID:req
  %.if [xdi].$Obj(Application).Setup.Tool&ID.pName != NULL
    %invoke StrDispose, [xdi].$Obj(Application).Setup.Tool&ID.pName
  .endif
  %invoke GetDlgItemText, xbx, IDC_EDT_NAME_&ID, addr cBuffer, lengthof cBuffer
  mov [xdi].$Obj(Application).Setup.Tool&ID.pName, $invoke(StrNew, addr cBuffer)
  .if [xdi].$Obj(Application).Setup.Tool&ID.pCommand != NULL
    %invoke StrDispose, [xdi].$Obj(Application).Setup.Tool&ID.pCommand
  .endif
  %invoke GetDlgItemText, xbx, IDC_EDT_CMD_&ID, addr cBuffer, lengthof cBuffer
  mov [xdi].$Obj(Application).Setup.Tool&ID.pCommand, $invoke(StrNew, addr cBuffer)
endm

.code
include OA_Tools_Setup_Tab1.inc
include OA_Tools_Setup_Tab2.inc
include OA_Tools_Setup_Tab3.inc


; ==================================================================================================
;    OAT_Setup implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OAT_Setup.CtlsGet
; Purpose:    Read the setting of all controls.
; Arguments:  None.
; Return:     Nothing.

Method OAT_Setup.CtlsGet, uses xsi
  SetObject xsi
  OCall [xsi].TabDialog1::Tab1.CtlsGet
  OCall [xsi].TabDialog2::Tab2.CtlsGet
  OCall [xsi].TabDialog3::Tab3.CtlsGet
  mov eax, TRUE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OAT_Setup.CtlsSet
; Purpose:    Set the controls of the setup dialog.
; Arguments:  None.
; Return:     eax = this procedure should return TRUE to direct Windows to set the keyboard focus to
;                   the control specified by hwndFocus. Otherwise, it should return FALSE to prevent
;                   Windows from setting the default keyboard focus.

Method OAT_Setup.CtlsSet, uses xsi
  SetObject xsi
  OCall [xsi].TabDialog1::Tab1.CtlsSet
  OCall [xsi].TabDialog2::Tab2.CtlsSet
  OCall [xsi].TabDialog3::Tab2.CtlsSet
  mov eax, TRUE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OAT_Setup.Done
; Purpose:    Finalize the OAT_Setup object.
; Arguments:  None.
; Return:     Nothing.

Method OAT_Setup.Done, uses xsi
  SetObject xsi
  OCall [xsi].IconImageList::MaskedImageList.Done
  OCall [xsi].TabDialog1::Tab1.Done
  OCall [xsi].TabDialog2::Tab2.Done
  OCall [xsi].TabDialog3::Tab3.Done
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OAT_Setup.GetFileName
; Purpose:    Shows a OFN dialog and returns a single IShellItem pointer.
; Arguments:  None.
; Return:     xax -> IShellItem or NULL. IShellItem must be released after use.

ToolMultiFileSpec struc
  FS0 COMDLG_FILTERSPEC {}
  FS1 COMDLG_FILTERSPEC {}
  FS2 COMDLG_FILTERSPEC {}
  FS3 COMDLG_FILTERSPEC {}
ToolMultiFileSpec ends

Method OAT_Setup.GetFileName, uses xbx xdi xsi
  local pIFODlg: POINTER, MFS:ToolMultiFileSpec, pIFileDialog2:POINTER
  local pISIArr:POINTER, pIShellItem:POINTER, pFileName:POINTER
  local cBuffer[MAX_PATH]:CHR

  SetObject xsi
  invoke CoCreateInstance, offset CLSID_FileOpenDialog, NULL, CLSCTX_INPROC_SERVER, \
                           offset IID_IFileOpenDialog, addr pIFODlg
  .if SUCCEEDED(eax)
    lea xdi, cBuffer
    mov xcx, [xsi].pOwner                                 ;xcx -> Application
    mov ebx, [xcx].$Obj(Application).dLanguage

    invoke LoadString, hInstance, addr [ebx + IDS_TOOL_FILTER_NAME_0], xdi, lengthof cBuffer
    mov MFS.FS0.pszName, $invoke(StrNew, xdi)
    c2m MFS.FS0.pszSpec, $OfsCStr("*.exe"), xax
    invoke LoadString, hInstance, addr [ebx + IDS_TOOL_FILTER_NAME_1], xdi, lengthof cBuffer
    mov MFS.FS1.pszName, $invoke(StrNew, xdi)
    c2m MFS.FS1.pszSpec, $OfsCStr("*.bat; *.cmd"), xax
    invoke LoadString, hInstance, addr [ebx + IDS_TOOL_FILTER_NAME_2], xdi, lengthof cBuffer
    mov MFS.FS2.pszName, $invoke(StrNew, xdi)
    c2m MFS.FS2.pszSpec, $OfsCStr("*.vbs; *.ps1"), xax
    invoke LoadString, hInstance, addr [ebx + IDS_TOOL_FILTER_NAME_3], xdi, lengthof cBuffer
    mov MFS.FS3.pszName, $invoke(StrNew, xdi)
    c2m MFS.FS3.pszSpec, $OfsCStr("*.*"), xax

    ICall pIFODlg::IFileOpenDialog.SetFileTypes, sizeof(ToolMultiFileSpec)/sizeof(COMDLG_FILTERSPEC), \
                                                 addr MFS
    ICall pIFODlg::IFileOpenDialog.SetFileTypeIndex, 0
    ICall pIFODlg::IFileOpenDialog.SetOptions, FOS_FILEMUSTEXIST

    invoke LoadString, hInstance, addr [ebx + IDS_SELECT_FILE], xdi, lengthof cBuffer
    ICall pIFODlg::IFileOpenDialog.SetTitle, xdi
    invoke LoadString, hInstance, addr [ebx + IDS_SELECTION_FILE_NAME], xdi, lengthof cBuffer
    ICall pIFODlg::IFileOpenDialog.SetFileNameLabel, xdi
    invoke LoadString, hInstance, addr [ebx + IDS_SELECTION_OPEN], xdi, lengthof cBuffer
    ICall pIFODlg::IFileOpenDialog.SetOkButtonLabel, xdi

    ICall pIFODlg::IFileOpenDialog.QueryInterface, offset IID_IFileDialog2, addr pIFileDialog2
    .if SUCCEEDED(eax)
      invoke LoadString, hInstance, addr [ebx + IDS_CANCEL], xdi, lengthof cBuffer
      ICall pIFileDialog2::IFileDialog2.SetCancelButtonLabel, xdi
      ICall pIFileDialog2::IFileDialog2.Release
    .endif

    mov xcx, [xsi].pOwner                                 ;xcx -> Application
    invoke SHCreateItemFromParsingName, [xcx].$Obj(Application).pWorkDirectoryW, NULL, \
                                        offset IID_IShellItem, addr pIShellItem
    ICall pIFODlg::IFileOpenDialog.SetDefaultFolder, pIShellItem
    ICall pIShellItem::IShellItem.Release

    ICall pIFODlg::IFileOpenDialog.Show, [xsi].hWnd
    .if SUCCEEDED(eax)
      ICall pIFODlg::IFileOpenDialog.GetResults, addr pISIArr
    .else
      mov pISIArr, NULL
    .endif

    ICall pIFODlg::IFileOpenDialog.GetFolder, addr pIShellItem
    ICall pIShellItem::IShellItem.GetDisplayName, SIGDN_FILESYSPATH, addr pFileName
    mov xdi, [xsi].pOwner                                 ;xdi -> Application
    .if [xdi].$Obj(Application).pWorkDirectoryW != NULL
      invoke StrDispose, [xdi].$Obj(Application).pWorkDirectoryW
    .endif
    mov [xdi].$Obj(Application).pWorkDirectoryW, $invoke(StrNewW, pFileName)

    .if pISIArr != NULL
      ICall pISIArr::IShellItemArray.GetItemAt, 0, addr pIShellItem
      ICall pISIArr::IShellItemArray.Release
    .else
      mov pIShellItem, NULL
    .endif

    invoke StrDispose, MFS.FS0.pszName
    invoke StrDispose, MFS.FS1.pszName
    invoke StrDispose, MFS.FS2.pszName
    invoke StrDispose, MFS.FS3.pszName

    mov xax, pIShellItem
  .else
    xor eax, eax
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OAT_Setup.Init
; Purpose:    Initialaize a OAT_Setup object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> Parent window HANDLE.
; Return:     Nothing.

Method OAT_Setup.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND

  SetObject xsi
  ACall xsi.Init, pOwner, hParent, 5000

  lea xbx, [xsi].IconImageList
  OCall xbx::MaskedImageList.Init, xsi, 16, 16, 3
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_APPL_SETUP")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_CHECK")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_BRUSH")
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OAT_Setup.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method OAT_Setup.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  LoWord(wParam)
  .if ax == IDOK
    OCall xsi.CtlsGet
    OCall [xsi].pOwner::Application.SetToolMenu
  .endif
  OCall xsi.DestroyDialog, wParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OAT_Setup.OnDestroy
; Purpose:    Event procedure for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method OAT_Setup.OnDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke SetWindowLongPtr, [xsi].hWnd, DWLP_USER, NULL
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OAT_Setup.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = FALSE.

Method OAT_Setup.OnInitDialog, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[MAX_PATH]:CHR, CtrlSetup:DEF_TABCONTROL

  SetObject xsi
  lea xbx, [xsi].TabControl
  invoke MemClone, addr CtrlSetup, offset SetupTabCtrl, sizeof DEF_TABCONTROL
  invoke MapDialogRect, [xsi].hWnd, addr CtrlSetup.sdPosX
  OCall xbx::TabCtrl.Init, xsi, [xsi].hWnd, addr [xsi].IconImageList, addr CtrlSetup

  OCall [xsi].TabDialog1::Tab1.Init, xbx, [xbx].$Obj(TabCtrl).hWnd, SETUP_TAB_MAIN, \
                                          addr $ObjTmpl(Application).hActiveMlsDlg
  OCall [xsi].TabDialog1::Tab1.Show
  invoke ShowWindow, [xsi].TabDialog1.hWnd, SW_SHOWDEFAULT

  OCall [xsi].TabDialog2::Tab2.Init, xbx, [xbx].$Obj(TabCtrl).hWnd, SETUP_TAB_TOOLS, \
                                          addr $ObjTmpl(Application).hActiveMlsDlg
  OCall [xsi].TabDialog2::Tab2.Show
  invoke ShowWindow, [xsi].TabDialog2.hWnd, SW_HIDE

  OCall [xsi].TabDialog3::Tab3.Init, xbx, [xbx].$Obj(TabCtrl).hWnd, SETUP_TAB_COLORS, \
                                          addr $ObjTmpl(Application).hActiveMlsDlg
  OCall [xsi].TabDialog3::Tab3.Show
  invoke ShowWindow, [xsi].TabDialog3.hWnd, SW_HIDE

  mov xcx, [xsi].pOwner                                 ;xcx -> Application
  mov edi, [xcx].$Obj(Application).dLanguage
  lea xbx, cBuffer

  mov edx, edi
  add edx, IDS_SETUP
  invoke LoadString, hInstance, edx, xbx, lengthof cBuffer
  invoke SetWindowText, [xsi].hWnd, xbx

  SetItemString IDCANCEL, IDS_CANCEL

  mov edx, edi
  add edx, IDS_TAB1_MAIN
  invoke LoadString, hInstance, edx, xbx, lengthof cBuffer
  OCall [xsi].TabControl::TabCtrl.Insert, 0, [xsi].TabDialog1.hWnd, xbx, 0

  mov edx, edi
  add edx, IDS_TAB2_TOOLS
  invoke LoadString, hInstance, edx, xbx, lengthof cBuffer
  OCall [xsi].TabControl::TabCtrl.Insert, 1, [xsi].TabDialog2.hWnd, xbx, 1

  mov edx, edi
  add edx, IDS_TAB3_COLORS
  invoke LoadString, hInstance, edx, xbx, lengthof cBuffer
  OCall [xsi].TabControl::TabCtrl.Insert, 2, [xsi].TabDialog3.hWnd, xbx, 2

  ACall xsi.OnInitDialog, wParam, lParam
MethodEnd
