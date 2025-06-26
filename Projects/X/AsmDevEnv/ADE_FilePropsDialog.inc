; ==================================================================================================
; Title:      ADE_FilePropsDlg.inc
; Author:     G. Friedrich
; Version:    See ADE.asm
; Purpose:    ObjAsm Setup dialog implementation.
; ==================================================================================================


IDD_DLG_FILEPROPS               equ 4000
IDC_STC_DISPNAME                equ 1001
IDC_EDT_DISPNAME                equ 1002
IDC_STC_FILENAME                equ 1003
IDC_EDT_FILENAME                equ 1004
IDC_BTN_SEARCHFILE              equ 1005
IDC_CHK_CMD                     equ 1006
IDC_BTN_OK                      equ 1
IDC_BTN_CANCEL                  equ 2

; ==================================================================================================
; FilePropsDialog implementation
; ==================================================================================================

.code
; --------------------------------------------------------------------------------------------------
; Method:     FilePropsDialog.CtlsGet
; Purpose:    Read the setting of all controls.
; Arguments:  None.
; Return:     Nothing.

Method FilePropsDialog.CtlsGet, uses xbx xdi xsi
  local cBuffer[4096]:CHR, Item:TVITEM

  SetObject xsi
  mov xax, [xsi].pOwner
  lea xbx, [xax].$Obj(Application).PrjMgr
  m2m Item.hItem, [xsi].hItem, xax
  mov Item.mask_, TVIF_HANDLE or TVIF_PARAM
  invoke SendMessage, [xbx].$Obj(ProjectManager).TView.hWnd, TVM_GETITEM, 0, addr Item
  mov xdi, Item.lParam

  invoke GetDlgItemText, [xsi].hWnd, IDC_EDT_DISPNAME, addr cBuffer, lengthof cBuffer
  invoke StrReplace, addr [xdi].PROJECTITEM.pDispName, addr cBuffer
  invoke GetDlgItemText, [xsi].hWnd, IDC_EDT_FILENAME, addr cBuffer, lengthof cBuffer
  invoke StrReplace, addr [xdi].PROJECTITEM.pFileName, addr cBuffer

  mov Item.mask_, TVIF_HANDLE or TVIF_TEXT or TVIF_IMAGE or TVIF_SELECTEDIMAGE or TVIF_PARAM
  invoke StrLength, [xdi].PROJECTITEM.pDispName
  mov Item.cchTextMax, eax
  m2m Item.pszText, [xdi].PROJECTITEM.pDispName, xdx
  mov Item.iImage, ICON_INDEX_FILE
  mov Item.iSelectedImage, ICON_INDEX_FILE
  mov [xdi].PROJECTITEM.dType, PIT_FILE
  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_CHK_CMD
  .if eax == BST_CHECKED
    mov Item.iImage, ICON_INDEX_CMD
    mov Item.iSelectedImage, ICON_INDEX_CMD
    mov [xdi].PROJECTITEM.dType, PIT_COMMAND
  .endif
  invoke SendMessage, [xbx].$Obj(ProjectManager).TView.hWnd, TVM_SETITEM, 0, addr Item
  BitSet [xbx].$Obj(ProjectManager).dFlags, PMF_DIRTY
  mov xbx, [xsi].pOwner
  mov xcx, [xbx].$Obj(Application).pClientWnd
  invoke SendMessage, [xcx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
  OCall xbx::Application.ManageGuiCmds, xax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     FilePropsDialog.CtlsSet
; Purpose:    Set the controls of the setup dialog.
; Arguments:  None.
; Return:     eax = This procedure should return TRUE to direct Windows to set the keyboard focus to
;                   the control specified by hwndFocus. Otherwise, it should return FALSE to prevent
;                   Windows from setting the default keyboard focus.

Method FilePropsDialog.CtlsSet, uses xbx xdi xsi
  local Item:TVITEM

  SetObject xsi
  mov xax, [xsi].pOwner
  lea xbx, [xax].$Obj(Application).PrjMgr
  m2m Item.hItem, [xsi].hItem, xax
  mov Item.mask_, TVIF_HANDLE or TVIF_PARAM
  invoke SendMessage, [xbx].$Obj(ProjectManager).TView.hWnd, TVM_GETITEM, 0, addr Item
  mov xdi, Item.lParam

  invoke SetDlgItemText, [xsi].hWnd, IDC_EDT_DISPNAME, [xdi].PROJECTITEM.pDispName
  invoke GetDlgItem, [xsi].hWnd, IDC_EDT_NAME
  invoke SendMessage, xax, EM_SETCUEBANNER, FALSE, $OfsCStrW("Enter a new display name")

  invoke SetDlgItemText, [xsi].hWnd, IDC_EDT_FILENAME, [xdi].PROJECTITEM.pFileName
  invoke GetDlgItem, [xsi].hWnd, IDC_EDT_FILENAME
  invoke SendMessage, xax, EM_SETCUEBANNER, FALSE, $OfsCStrW("Enter a file name or use the button on the right")

  mov eax, BST_UNCHECKED
  .if [xdi].PROJECTITEM.dType == PIT_COMMAND
    mov eax, BST_CHECKED
  .endif
  invoke CheckDlgButton, [xsi].hWnd, IDC_CHK_CMD, eax

  mov eax, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     FilePropsDialog.GetFileName
; Purpose:    Show a OFN dialog and set the IDC_EDT_FILENAME control.
; Arguments:  None.
; Return:     Nothing.

Method FilePropsDialog.GetFileName, uses xbx xdi xsi
  local pIFODlg: POINTER
  local pISIArr:POINTER, dCount:DWORD, pIShellItem:POINTER, pFileName:POINTER

  SetObject xsi
  invoke CoCreateInstance, offset CLSID_FileOpenDialog, NULL, CLSCTX_INPROC_SERVER, \
                           offset IID_IFileOpenDialog, addr pIFODlg
  .if SUCCEEDED(eax)
    ;Language customization
;    mov xcx, [xsi].pOwner                                 ;xcx -> Application
;    lea xdi, cBuffer
;    mov ebx, [xcx].$Obj(Application).dLanguage
;    invoke LoadString, hInstance, addr [ebx + IDS_SELECT_FILE], xdi, lengthof cBuffer
;    ICall pIFODlg::IFileOpenDialog.SetTitle, xdi
;    invoke LoadString, hInstance, addr [ebx + IDS_SELECTION_FILE_NAME], xdi, lengthof cBuffer
;    ICall pIFODlg::IFileOpenDialog.SetFileNameLabel, xdi
;    invoke LoadString, hInstance, addr [ebx + IDS_SELECTION_OPEN], xdi, lengthof cBuffer
;    ICall pIFODlg::IFileOpenDialog.SetOkButtonLabel, xdi
;
;    ICall pIFODlg::IFileOpenDialog.QueryInterface, offset IID_IFileDialog2, addr pIFileDialog2
;    .if SUCCEEDED(eax)
;      invoke LoadString, hInstance, addr [ebx + IDS_CANCEL], xdi, lengthof cBuffer
;      ICall pIFileDialog2::IFileDialog2.SetCancelButtonLabel, xdi
;      ICall pIFileDialog2::IFileDialog2.Release
;    .endif

    ;Setup dialog functionality
    ICall pIFODlg::IFileOpenDialog.SetOptions, FOS_SHAREAWARE
    ICall pIFODlg::IFileOpenDialog.SetTitle, $OfsCStrW("Open a file...")
    ICall pIFODlg::IFileOpenDialog.SetOkButtonLabel, $OfsCStrW("&Open")
    ICall pIFODlg::IFileOpenDialog.SetFileNameLabel, $OfsCStrW("Selected file: ")

    mov xax, [xsi].pOwner
    lea xcx, [xax].$Obj(Application).PrjMgr
    invoke SHCreateItemFromParsingName, [xcx].$Obj(ProjectManager).pProjDirPath, NULL, \
                                        offset IID_IShellItem, addr pIShellItem
    .if pIShellItem != NULL
      ICall pIFODlg::IFileOpenDialog.SetDefaultFolder, pIShellItem
      ICall pIShellItem::IShellItem.Release
    .endif

    ;Call the dialog
    ICall pIFODlg::IFileOpenDialog.Show, [xsi].hWnd
    .if SUCCEEDED(eax)
      ;Get result and store it
      ICall pIFODlg::IFileOpenDialog.GetResults, addr pISIArr
      ICall pISIArr::IShellItemArray.GetCount, addr dCount
      .if dCount > 0
        ICall pISIArr::IShellItemArray.GetItemAt, 0, addr pIShellItem
        ICall pIShellItem::IShellItem.GetDisplayName, SIGDN_FILESYSPATH, addr pFileName
        invoke SetDlgItemText, [xsi].hWnd, IDC_EDT_FILENAME, pFileName
        invoke CoTaskMemFree, pFileName
        ICall pIShellItem::IShellItem.Release
      .endif
      ICall pISIArr::IShellItemArray.Release
    .endif
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     FilePropsDialog.Init
; Purpose:    Initialaize a FilePropsDialog object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> Parent window HANDLE.
; Return:     Nothing.

.data
align ALIGN_DATA
FilePropDlgChildrenInfo label DL_HEADER
DL_HEADER     {DLF_LOAD_MINMAX or DLF_LIMIT_MIN or DLF_LIMIT_MAX_Y or DLF_ADD_GRIPPER}
DL_CHILD_INFO {{100, 000, 000, 000}}      ;OK Buttom
DL_CHILD_INFO {{000, 000, 000, 000}}      ;Disp name Label
DL_CHILD_INFO {{000, 000, 100, 000}}      ;Disp name Edit
DL_CHILD_INFO {{000, 000, 000, 000}}      ;File name Label
DL_CHILD_INFO {{000, 000, 100, 000}}      ;File name Edit
DL_CHILD_INFO {{100, 000, 000, 000}}      ;File Search Button
DL_CHILD_INFO {{000, 000, 000, 000}}      ;CheckBox Command
DL_CHILD_INFO {{100, 000, 000, 000}}      ;Cancel Button

Method FilePropsDialog.Init, uses xsi, pOwner:POINTER, hParent:HWND, hItem:HTREEITEM
  SetObject xsi
  ACall xsi.Init, pOwner, hParent, IDD_DLG_FILEPROPS
  c2m [xsi].pDynamicLayout, offset FilePropDlgChildrenInfo, xcx
  m2m [xsi].hItem, hItem, xax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     FilePropsDialog.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method FilePropsDialog.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  ANNOTATION use: lParam

  SetObject xsi
  LoWord(wParam)
  .if ax == IDOK
    OCall xsi.CtlsGet
    OCall xsi.DestroyDialog, wParam
  .elseif ax == IDCANCEL
    OCall xsi.DestroyDialog, wParam
  .elseif ax == IDC_BTN_SEARCHFILE
    OCall xsi.GetFileName
  .endif
MethodEnd
