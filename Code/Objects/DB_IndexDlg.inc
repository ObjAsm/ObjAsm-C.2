; ==================================================================================================
; Title:      DB_IndexDlg.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm Database Index dialog.
; Notes:      Version C.1.1, August 2019
;             - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————

Object DB_IndexDlg,, DialogModal
  VirtualMethod     CtlsEnable
  RedefineMethod    Init,             POINTER, HWND, $ObjPtr(DB_Table)

  RedefineMethod    OnCommand,        WPARAM, LPARAM
  RedefineMethod    OnInitDialog,     WPARAM, LPARAM
  VirtualMethod     RebuildIndex,     PTaskStatus, $ObjPtr(DB_Field), PSTRING
  VirtualMethod     UpdateStatusbar

  DefineVariable    dFlags,           DWORD,              0
  DefineVariable    pTable,           $ObjPtr(DB_Table),  NULL
  DefineVariable    hCboFieldName,    HANDLE,             0
  DefineVariable    hEdtFileName,     HANDLE,             0
  DefineVariable    hBtnSearchFile,   HANDLE,             0
  DefineVariable    hBtnIndex,        HANDLE,             0

  Embed     StatusBar,    Statusbar
ObjectEnd


.code

; ==================================================================================================
;    DB_IndexDlg implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DB_IndexDlg.CtlsEnable
; Purpose:    Enables the controls if the input is valid.
; Arguments:  None.
; Return:     eax = TRUE if the input values are valid, otherwise FALSE.

Method DB_IndexDlg.CtlsEnable, uses xsi
  SetObject xsi
  invoke SendMessage, [xsi].hCboFieldName, CB_GETCURSEL, 0, 0
  .if eax != CB_ERR
    invoke SendMessage, [xsi].hEdtFileName, WM_GETTEXTLENGTH, 0, 0
    .if eax != 0
      invoke EnableWindow, [xsi].hBtnIndex, TRUE
      mov eax, TRUE
      ExitMethod
    .endif
  .endif
  invoke EnableWindow, [xsi].hBtnIndex, FALSE
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DB_IndexDlg.Init
; Purpose:    Initialize the DB_IndexDlg object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> DB_Table.
; Return:     Nothing.

Method DB_IndexDlg.Init,, pOwner:POINTER, hParent:HWND, pTable:$ObjPtr(DB_Table)
  SetObject xcx
  m2m [xcx].pTable, pTable, xax
  ACall xcx.Init, pOwner, hParent, IDD_INDEX
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DB_IndexDlg.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

MultiFileSpec struc
  FS0 COMDLG_FILTERSPEC {}
  FS1 COMDLG_FILTERSPEC {}
MultiFileSpec ends

IndexTask struct
  Header    TaskHeader  {}
  Indexing  TaskSetup   {}
IndexTask ends

Method DB_IndexDlg.OnCommand, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local pIFODlg: POINTER, MFS:MultiFileSpec, pIFileDialog2:POINTER
  local pISIArr:POINTER, dCount:DWORD, pIShellItem:POINTER, pDisplayName:POINTER
  local NdxTask:IndexTask, ProgDlg:$Obj(DialogProgress)
  local cBuffer[LOCAL_BUFFER_SIZE]:CHR, bBuffer[LOCAL_BUFFER_SIZE]:CHRA
  local bMsgBuffer[LOCAL_BUFFER_SIZE]:CHRA

  SetObject xsi
  mov xax, wParam
  .if eax == IDC_INDEX_CBO_FIELD_NAME or CBN_SELCHANGE shl 16
    invoke SendMessage, [xsi].hCboFieldName, CB_GETCURSEL, 0, 0
    .if eax != CB_ERR
      mov xcx, [xsi].pTable
      OCall [xcx].$Obj(DB_Table).Fields::Collection.ItemAt, eax
      mov xax, [xax].$Obj(DB_Field).pIndex
      .if xax != NULL
        mov xax, [xax].$Obj(DB_Index).pFileName
      .endif
      invoke SendMessage, [xsi].hEdtFileName, WM_SETTEXT, 0, xax
    .endif
    OCall xsi.CtlsEnable
    xor eax, eax

  .elseif eax == IDC_INDEX_EDT_FILE_NAME or EN_CHANGE shl 16
    OCall xsi.CtlsEnable 
    xor eax, eax

  .elseif ax == IDC_INDEX_BTN_SEARCH_FILE
    invoke CoCreateInstance, offset CLSID_FileOpenDialog, NULL, CLSCTX_INPROC_SERVER, \
                             offset IID_IFileOpenDialog, addr pIFODlg
    .if SUCCEEDED(eax)
      c2m MFS.FS0.pszName, $OfsCStr("All"), xax
      c2m MFS.FS0.pszSpec, $OfsCStr("*.*"), xcx
      c2m MFS.FS1.pszName, $OfsCStr("Index"), xax
      c2m MFS.FS1.pszSpec, $OfsCStr("*.ndx"), xcx

      ICall pIFODlg::IFileOpenDialog.SetFileTypes, sizeof(MultiFileSpec)/sizeof(COMDLG_FILTERSPEC), \
                                                   addr MFS
      ICall pIFODlg::IFileOpenDialog.SetFileTypeIndex, 2
      ICall pIFODlg::IFileOpenDialog.SetOptions, 0
      ICall pIFODlg::IFileOpenDialog.SetTitle, $OfsCStr("Select a file...")
      ICall pIFODlg::IFileOpenDialog.SetOkButtonLabel, $OfsCStr("&Select")
      ICall pIFODlg::IFileOpenDialog.SetFileNameLabel, $OfsCStr("Selected file name: ")

      ICall pIFODlg::IFileOpenDialog.QueryInterface, offset IID_IFileDialog2, addr pIFileDialog2
      .if SUCCEEDED(eax)
        ICall pIFileDialog2::IFileDialog2.SetCancelButtonLabel, $OfsCStr("&Cancel")
        ICall pIFileDialog2::IFileDialog2.Release
      .endif

      ICall pIFODlg::IFileOpenDialog.Show, [xsi].hWnd
      .if SUCCEEDED(eax)
        ICall pIFODlg::IFileOpenDialog.GetResults, addr pISIArr
        ICall pISIArr::IShellItemArray.GetCount, addr dCount
        ICall pISIArr::IShellItemArray.GetItemAt, 0, addr pIShellItem
        ICall pIShellItem::IShellItem.GetDisplayName, SIGDN_FILESYSPATH, addr pDisplayName
        invoke SendMessage, [xsi].hEdtFileName, WM_SETTEXT, 0, pDisplayName
        ICall pIShellItem::IShellItem.Release
        ICall pISIArr::IShellItemArray.Release
      .endif
      ICall pIFODlg::IFileOpenDialog.Release
    .endif
    OCall xsi.CtlsEnable
    xor eax, eax

  .elseif ax == IDC_INDEX_BTN_INDEX
    ;Set Task header
    mov NdxTask.Header.dTaskCount, 1
    c2m NdxTask.Header.pMainDesc, $OfsCStrA("{\rtf1\sa50\fs19\b Description:\b0", \
        "\par\fs18 The index file is created according to the settings ", \
        "of the selected databse field.}"), xax
    c2m NdxTask.Header.pOverallDesc, $OfsCStrA("{\rtf1\b Overall progress:\b0}"), xax
    mov NdxTask.Header.hIcon, $invoke(LoadImage, hInstance, $OfsCStr("ICON_MUTATION"), \
                                      IMAGE_ICON, 0, 0, LR_DEFAULTCOLOR)
    ;Set index TaskSetup
    mov NdxTask.Indexing.pOwner, xsi
    lea xbx, cBuffer
    lea xdi, bBuffer
    invoke SendMessage, [xsi].hEdtFileName, WM_GETTEXT, LOCAL_BUFFER_SIZE/sizeof(CHR), xbx
    .if eax != 0
      invoke PathFindFileName, xbx
      if TARGET_STR_TYPE eq STR_TYPE_ANSI
        invoke StrCopyA, xdi, xax
      else
        invoke WideCharToMultiByte, CP_ACP, 0, xax, -1, xdi, LOCAL_BUFFER_SIZE, NULL, NULL
      endif
      invoke SendMessage, [xsi].hCboFieldName, CB_GETCURSEL, 0, 0
      .if eax != CB_ERR
        mov xcx, [xsi].pTable
        OCall [xcx].$Obj(DB_Table).Fields::Collection.ItemAt, eax
        mov NdxTask.Indexing.xParam1, xax               ;pField
        mov NdxTask.Indexing.xParam2, xbx               ;pFileName
  
        ProgressText textequ <{\rtf1\b Task:\b0  Creating Index \ul > 
        FillTextA bMsgBuffer, <%ProgressText>
        invoke StrECopyA, addr [bMsgBuffer + @SizeStr(%ProgressText)], xdi 
        ProgressText textequ <\ul0  for table field >
        FillTextA [xax], <%ProgressText>
        mov xdx, NdxTask.Indexing.xParam1               ;xdx -> DB_Field
        invoke StrECopyA, addr [xax + @SizeStr(%ProgressText)], \
                          addr [xdx].$Obj(DB_Field).Descriptor.bName
        FillStringA [xax], <...}>
        mov NdxTask.Indexing.pDescription, $invoke(StrNewA, addr bMsgBuffer)

        m2m NdxTask.Indexing.pTaskProc, $MethodAddr(DB_IndexDlg.RebuildIndex), xax
        mov xcx, [xsi].pTable
        mov eax, [xcx].$Obj(DB_Table).Descriptor.dNumRecs
        add eax, eax                                    ;Best guess
        mov NdxTask.Indexing.dPrgCntMax, eax
      
        ;Invoke Progress dialog
        New ProgDlg::DialogProgress
        OCall ProgDlg::DialogProgress.Init, xsi, [xsi].hWnd, addr NdxTask
        OCall ProgDlg::DialogProgress.Show
        OCall ProgDlg::DialogProgress.Done
      
        invoke StrDispose, NdxTask.Indexing.pDescription   ;Does nothing if argument is NULL
      .endif
    .endif

    ;Free resources
    invoke DestroyIcon, NdxTask.Header.hIcon
    xor eax, eax

  .elseif ax == IDC_INDEX_BTN_CLOSE || ax == IDCANCEL 
    OCall xsi.DestroyDialog, wParam
    xor eax, eax

  .else
    mov eax, 1
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DB_IndexDlg.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = TRUE to direct the system to set the keyboard focus to the control specified by
;             wParam. Otherwise, it should return FALSE to prevent the system from setting the
;             default keyboard focus.

.const
align ALIGN_DATA
IndexDlgStatusbar DEF_STATUSBAR {IDC_INDEX_SBR, SBR_STYLE, 0, 1}
  DEF_STATUSBAR_PART {400, -2, 0, SBT_SUNKEN, NULL}    ;Table information

.data
align ALIGN_DATA
IndexDlgChildrenInfo label DL_HEADER
DL_HEADER     {DLF_LOAD_MIN or DLF_LIMIT_MINMAX}
DL_CHILD_INFO {{100, 100, 000, 000}}    ;BTN Close
DL_CHILD_INFO {{000, 000, 000, 000}}    ;STC FieldName
DL_CHILD_INFO {{000, 000, 000, 000}}    ;CBO FieldName
DL_CHILD_INFO {{000, 000, 100, 000}}    ;STC FileName
DL_CHILD_INFO {{000, 000, 100, 000}}    ;EDT FileName
DL_CHILD_INFO {{100, 000, 000, 000}}    ;BTN Search
DL_CHILD_INFO {{100, 100, 000, 000}}    ;BTN Reindex
DL_CHILD_INFO {{000, 100, 100, 000}}    ;SBR

.code
Method DB_IndexDlg.OnInitDialog, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "DB_IndexDlg.OnInitDialog"
  SetObject xsi
  c2m [xsi].pDynamicLayout, offset IndexDlgChildrenInfo, xcx

  OCall [xsi].StatusBar::Statusbar.Init, xsi, [xsi].hWnd, offset(IndexDlgStatusbar)

  ;Reposition dialog controls and set content
  ACall xsi.OnInitDialog, wParam, lParam

  ;Get Control handles
  mov [xsi].hCboFieldName,  $invoke(GetDlgItem, [xsi].hWnd, IDC_INDEX_CBO_FIELD_NAME)
  mov [xsi].hEdtFileName,   $invoke(GetDlgItem, [xsi].hWnd, IDC_INDEX_EDT_FILE_NAME)
  mov [xsi].hBtnSearchFile, $invoke(GetDlgItem, [xsi].hWnd, IDC_INDEX_BTN_SEARCH_FILE)
  mov [xsi].hBtnIndex,      $invoke(GetDlgItem, [xsi].hWnd, IDC_INDEX_BTN_INDEX)

  ;Load the ComboBox with field names
  mov xcx, [xsi].pTable
  lea xdi, [xcx].$Obj(DB_Table).Fields
  xor ebx, ebx
  .while ebx != [xdi].$Obj(Collection).dCount
    OCall xdi::Collection.ItemAt, ebx
    invoke SendMessageA, [xsi].hCboFieldName, CB_ADDSTRING, \
                         0, addr [xax].$Obj(DB_Field).Descriptor.bName
    inc ebx
  .endw

  OCall xsi.CtlsEnable
  OCall xsi.UpdateStatusbar

  mov eax, TRUE                                         ;Let Windows set the default keyboard focus
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DB_IndexDlg.RebuildIndex
; Purpose:    Table index rebuild.
; Arguments:  Arg1: -> TaskStatus.
;             Arg2: -> DB_Field.
;             Arg3: -> File name.
; Return:     Nothing.

Method DB_IndexDlg.RebuildIndex, uses xsi, pStatus:PTaskStatus, pField:$ObjPtr(DB_Field), \
                                           pFileName:PSTRING
  local pPrvIndex:$ObjPtr(DB_Index), pNewIndex:$ObjPtr(DB_Index) 
  
;  DbgText "DB_IndexDlg.RebuildIndex"
  SetObject xsi
  mov xcx, pField
  mrm pPrvIndex, [xcx].$Obj(DB_Field).pIndex, xax
  New DB_Index
  .if xax == NULL
    OCall xsi.ErrorReport, NULL, DB_OUT_OF_MEMORY
    DbgWarning "DB_IndexDlg.RebuildIndex: Out of memory creating a DB_Index", \
               offset(szDbgObjErr)
    mov xax, pStatus
    BitSet [xax].TaskStatus.dFlags, TSF_TASK_ERROR
  .else
    mov pNewIndex, xax
    .if pPrvIndex != NULL
      OCall pPrvIndex::DB_Index.Close
    .endif

    OCall pNewIndex::DB_Index.New, pField, pFileName
    OCall pNewIndex::DB_Index.Reindex, pStatus

    mov xcx, pStatus
    .ifBitSet [xcx].TaskStatus.dFlags, TSF_THREAD_CANCEL
      Kill pNewIndex
      mov xax, pPrvIndex
      .if xax == NULL
        mov xcx, pField
        mov [xcx].$Obj(DB_Field).pIndex, NULL
      .else
        OCall pPrvIndex::DB_Index.Open, pField, [xax].$Obj(DB_Index).pFileName  ;Restore prev. index
      .endif
    .else 
      Destroy pPrvIndex                                   ;Safe operation
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DB_IndexDlg.UpdateStatusbar
; Purpose:    Update relevant database information on the statusbar.
; Arguments:  None.
; Return:     Nothing.

Method DB_IndexDlg.UpdateStatusbar, uses xbx xdi xsi
  local cBuffer[LOCAL_BUFFER_SIZE]:CHR, qFileSize:QWORD

  SetObject xsi
  lea xbx, cBuffer
  mov xdi, [xsi].pTable
  FillText [xbx], < Table: >
  add xbx, 8*sizeof(CHR)
  invoke StrECopy, xbx, [xdi].$Obj(DB_Table).pFileName
  FillText [xax], < (Size: >
  lea xbx, [xax + 8*sizeof(CHR)]
  invoke GetFileSizeEx, [xdi].$Obj(DB_Table).hFile, addr qFileSize
  invoke qword2dec, xbx, qFileSize
  invoke StrEnd, xbx
  FillText [xax], < bytes, Records: >
  lea xbx, [xax + 17*sizeof(CHR)]
  invoke dword2dec, xbx, [xdi].$Obj(DB_Table).Descriptor.dNumRecs
  invoke StrEnd, xbx
  FillString [xax], <)>

  OCall [xsi].StatusBar::Statusbar.SetPartText, 0, addr cBuffer, SBT_SUNKEN
MethodEnd
