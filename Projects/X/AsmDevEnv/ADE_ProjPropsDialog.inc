; ==================================================================================================
; Title:      ADE_ProjPropsDialog.inc
; Author:     G. Friedrich
; Version:    See ADE.asm
; Purpose:    ObjAsm Setup dialog implementation.
; ==================================================================================================


IDD_DLG_PROJPROPS	            	equ 3000
IDC_STC_PROJNAME	            	equ 1001
IDC_EDT_NAME	                	equ 1002
IDC_STC_FILENAME	            	equ 1003
IDC_EDT_FILENAME	            	equ 1004
IDC_STC_DIRPATH	              	equ 1005
IDC_EDT_DIRPATH	              	equ 1006
IDC_BTN_SEARCHDIR	            	equ 1007
IDC_STC_DESC	                	equ 1007
IDC_EDT_DESC	                	equ 1008
IDC_CHK_CRASH	                	equ 1009
IDC_BTN_OK	                  	equ 1
IDC_BTN_CANCEL	              	equ 2

; ==================================================================================================
; ProjPropsDialog implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     ProjPropsDialog.CtlsGet
; Purpose:    Read the setting of all controls.
; Arguments:  None.
; Return:     Nothing.

Method ProjPropsDialog.CtlsGet, uses xbx xsi
  local cBuffer[4096]:CHR

  SetObject xsi
  mov xax, [xsi].pOwner
  lea xbx, [xax].$Obj(Application).ProjMgr
  invoke GetDlgItemText, [xsi].hWnd, IDC_EDT_NAME, addr cBuffer, lengthof cBuffer
  invoke StrReplace, addr [xbx].$Obj(ProjectManager).pProjName, addr cBuffer
  invoke GetDlgItemText, [xsi].hWnd, IDC_EDT_FILENAME, addr cBuffer, lengthof cBuffer
  invoke StrReplace, addr [xbx].$Obj(ProjectManager).pProjFileName, addr cBuffer
  invoke GetDlgItemText, [xsi].hWnd, IDC_EDT_DIRPATH, addr cBuffer, lengthof cBuffer
  invoke StrReplace, addr [xbx].$Obj(ProjectManager).pProjDirPath, addr cBuffer
  invoke GetDlgItemText, [xsi].hWnd, IDC_EDT_DESC, addr cBuffer, lengthof cBuffer
  invoke StrReplace, addr [xbx].$Obj(ProjectManager).pProjDescription, addr cBuffer
  BitSet [xbx].$Obj(ProjectManager).dFlags, PMF_DIRTY
  mov eax, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjPropsDialog.CtlsSet
; Purpose:    Set the controls of the setup dialog.
; Arguments:  None.
; Return:     eax = this procedure should return TRUE to direct Windows to set the keyboard focus to
;                   the control specified by hwndFocus. Otherwise, it should return FALSE to prevent
;                   Windows from setting the default keyboard focus.

Method ProjPropsDialog.CtlsSet, uses xbx xsi
  SetObject xsi
  mov xax, [xsi].pOwner
  lea xbx, [xax].$Obj(Application).ProjMgr
  invoke SetDlgItemText, [xsi].hWnd, IDC_EDT_NAME, [xbx].$Obj(ProjectManager).pProjName
  invoke GetDlgItem, [xsi].hWnd, IDC_EDT_NAME
  invoke SendMessage, xax, EM_SETCUEBANNER, FALSE, $OfsCStrW("Enter a new project name")
  
  invoke SetDlgItemText, [xsi].hWnd, IDC_EDT_FILENAME, [xbx].$Obj(ProjectManager).pProjFileName
  invoke GetDlgItem, [xsi].hWnd, IDC_EDT_FILENAME
  invoke SendMessage, xax, EM_SETCUEBANNER, FALSE, $OfsCStrW("Enter a new file name")

  invoke SetDlgItemText, [xsi].hWnd, IDC_EDT_DIRPATH, [xbx].$Obj(ProjectManager).pProjDirPath
  invoke GetDlgItem, [xsi].hWnd, IDC_EDT_DIRPATH
  invoke SendMessage, xax, EM_SETCUEBANNER, FALSE, $OfsCStrW("Enter a directory path or use the button on the right")

  ;Cuebanner doesn't work on multiline edit controls
  invoke SetDlgItemText, [xsi].hWnd, IDC_EDT_DESC, [xbx].$Obj(ProjectManager).pProjDescription

  invoke CheckDlgButton, [xsi].hWnd, IDC_CHK_CRASH, BST_CHECKED
  mov eax, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjPropsDialog.GetDirectoryName
; Purpose:    Show a OFN dialog and set the IDC_EDT_DIRPATH control.
; Arguments:  None.
; Return:     Nothing.

Method ProjPropsDialog.GetDirectoryName, uses xbx xdi xsi
  local pIFODlg: POINTER
  local pISIArr:POINTER, pIShellItem:POINTER, pDirName:PSTRING, cBuffer[MAX_PATH]:CHR

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
    ICall pIFODlg::IFileOpenDialog.SetOptions, FOS_PICKFOLDERS or FOS_PATHMUSTEXIST or FOS_SHAREAWARE
    mov xax, [xsi].pOwner
    lea xcx, [xax].$Obj(Application).ProjMgr
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
      ICall pIFODlg::IFileOpenDialog.GetFolder, addr pIShellItem
      .if pIShellItem != NULL
        ICall pIShellItem::IShellItem.GetDisplayName, SIGDN_FILESYSPATH, addr pDirName
        invoke SetDlgItemText, [xsi].hWnd, IDC_EDT_DIRPATH, pDirName
        invoke CoTaskMemFree, pDirName
        ICall pIShellItem::IShellItem.Release
      .endif
    .endif
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjPropsDialog.Init
; Purpose:    Initialaize a ProjPropsDialog object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> Parent window HANDLE.
; Return:     Nothing.

.data
align ALIGN_DATA
ProjPropDlgChildrenInfo label DL_HEADER
DL_HEADER     {DLF_LOAD_MINMAX or DLF_LIMIT_MIN or DLF_LIMIT_MAX_Y or DLF_ADD_GRIPPER}
DL_CHILD_INFO {{100, 000, 000, 000}}      ;OK Buttom
DL_CHILD_INFO {{000, 000, 000, 000}}      ;Proj name Label
DL_CHILD_INFO {{000, 000, 100, 000}}      ;Proj name Edit
DL_CHILD_INFO {{000, 000, 000, 000}}      ;File name Label
DL_CHILD_INFO {{000, 000, 100, 000}}      ;File name Edit
DL_CHILD_INFO {{000, 000, 000, 000}}      ;Dir path Label
DL_CHILD_INFO {{000, 000, 100, 100}}      ;Dir Path Edit
DL_CHILD_INFO {{100, 000, 000, 000}}      ;Dir Search Button
DL_CHILD_INFO {{000, 000, 000, 000}}      ;Description Label
DL_CHILD_INFO {{000, 000, 100, 100}}      ;Description Edit
DL_CHILD_INFO {{000, 000, 000, 000}}      ;Checkbox
DL_CHILD_INFO {{100, 000, 000, 000}}      ;Cancel Button

Method ProjPropsDialog.Init, uses xsi, pOwner:POINTER, hParent:HWND
  SetObject xsi
  ACall xsi.Init, pOwner, hParent, IDD_DLG_PROJPROPS
  c2m [xsi].pDynamicLayout, offset ProjPropDlgChildrenInfo, xcx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ProjPropsDialog.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ProjPropsDialog.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  ANNOTATION use: lParam

  SetObject xsi
  LoWord(wParam)
  .if ax == IDOK
    OCall xsi.CtlsGet
    OCall xsi.DestroyDialog, wParam
  .elseif ax == IDCANCEL
    OCall xsi.DestroyDialog, wParam
  .elseif ax == IDC_BTN_SEARCHDIR
    OCall xsi.GetDirectoryName
  .endif
MethodEnd
