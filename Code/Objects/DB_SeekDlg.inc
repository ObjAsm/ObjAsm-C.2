; ==================================================================================================
; Title:      DB_SeekDlg.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm Database seek dialog.
; Notes:      Version C.1.1, August 2019
;             - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------

Object DB_SeekDlg,, DialogModal
  VirtualMethod     CtlsEnable
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    Done
  RedefineMethod    Init,           POINTER, HWND, \
                                    $ObjPtr(DB_Table), $ObjPtr(DB_Index), PDB_DATA_LINK_TYPE
  RedefineMethod    OnCommand,      WPARAM, LPARAM
  RedefineMethod    OnInitDialog,   WPARAM, LPARAM
  VirtualMethod     UpdateStatusbar

  DefineVariable    pTable,         $ObjPtr(DB_Table),  NULL
  DefineVariable    pActiveIndex,   $ObjPtr(DB_Index),  NULL    ;Currently active index
  DefineVariable    pRecNo,         PDB_DATA_LINK_TYPE, NULL

  Embed     StatusBar,  Statusbar                               ;Statusbar object
ObjectEnd


.code

; ==================================================================================================
;    DB_SeekDlg implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     DB_SeekDlg.CtlsEnable
; Purpose:    Set the enable state of the controls.
; Arguments:  None.
; Return:     Nothing.

Method DB_SeekDlg.CtlsEnable, uses xdi xsi
  SetObject xsi
  xor edi, edi
  invoke SendDlgItemMessage, [xsi].hWnd, IDC_SEEK_EDT_SEEK_FOR, WM_GETTEXTLENGTH, 0, 0
  .if eax > 0
    invoke SendDlgItemMessage, [xsi].hWnd, IDC_SEEK_CBO_INDEX, CB_GETCURSEL, 0, 0
    .if eax != CB_ERR
      inc edi
    .endif
  .endif
  invoke GetDlgItem, [xsi].hWnd, IDC_SEEK_BTN_SEEK
  invoke EnableWindow, xax, edi

  xor edi, edi
  mov xcx, [xsi].pRecNo
  .if DB_DATA_LINK_TYPE ptr [xcx] != 0
    inc edi
  .endif
  invoke GetDlgItem, [xsi].hWnd, IDC_SEEK_BTN_EDIT
  invoke EnableWindow, xax, edi
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_SeekDlg.CtlsGet
; Purpose:    Read the controls in this dialog window.
; Arguments:  None.
; Return:     Nothing.

Method DB_SeekDlg.CtlsGet, uses xbx xdi xsi
  local dSelectedIndex:DWORD

  SetObject xsi
  ;Get Selected DB_Index
  invoke SendDlgItemMessage, [xsi].hWnd, IDC_SEEK_CBO_INDEX, CB_GETCURSEL, 0, 0
  .if eax != CB_ERR
    mov dSelectedIndex, eax
    mov xax, [xsi].pTable
    lea xdi, [xax].$Obj(DB_Table).Fields
    xor ebx, ebx
    .repeat
      OCall xdi::Collection.ItemAt, ebx
      .if [xax].$Obj(DB_Field).pIndex != NULL
        .if dSelectedIndex == 0
          m2m [xsi].pActiveIndex, [xax].$Obj(DB_Field).pIndex, xdx
          .break
        .endif
        dec dSelectedIndex
      .endif
      inc ebx
    .until ebx == [xdi].$Obj(Collection).dCount
  .else
    mov [xsi].pActiveIndex, NULL
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_SeekDlg.CtlsSet
; Purpose:    Set the controls in this dialog window.
; Arguments:  None.
; Return:     Nothing.

Method DB_SeekDlg.CtlsSet, uses xbx xdi xsi
  local dSelectedIndex:DWORD, dCurrentIndex:DWORD

  SetObject xsi

  ;Fill the Combobox
  xor ebx, ebx
  mov dCurrentIndex, ebx
  mov xax, [xsi].pTable
  lea xdi, [xax].$Obj(DB_Table).Fields
  mov dSelectedIndex, CB_ERR
  .repeat
    OCall xdi::Collection.ItemAt, ebx                   ;xax -> DB_Field
    .if [xax].$Obj(DB_Field).pIndex != NULL
      mov xdx, [xsi].pActiveIndex
      .if xdx == [xax].$Obj(DB_Field).pIndex
        m2m dSelectedIndex, dCurrentIndex, edx
      .endif
      invoke SendDlgItemMessageA, [xsi].hWnd, IDC_SEEK_CBO_INDEX, CB_ADDSTRING, \
                                  0, addr [xax].$Obj(DB_Field).Descriptor.bName
      inc dCurrentIndex
    .endif
    inc ebx
  .until ebx == [xdi].$Obj(Collection).dCount

  ;Set current selection
  invoke SendDlgItemMessage, [xsi].hWnd, IDC_SEEK_CBO_INDEX, CB_SETCURSEL, dSelectedIndex, 0

  OCall xsi.UpdateStatusbar
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_SeekDlg.Done
; Purpose:    Finalize the DB_QueryDlg object.
; Arguments:  None.
; Return:     Nothing.

Method DB_SeekDlg.Done, uses xsi
  SetObject xsi
  OCall [xsi].StatusBar::Statusbar.Done
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_SeekDlg.Init
; Purpose:    Initialaize a DB_SeekDlg object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> DB_Table.
;             Arg4: -> Current active DB_Index.
;             Arg5: -> Current RecNo.
; Return:     Nothing.

.data
align ALIGN_DATA
SeekChildrenInfo label DL_HEADER
DL_HEADER     {DLF_LOAD_MIN or DLF_LIMIT_MINMAX, {}, {600, 400}}
DL_CHILD_INFO {{100, 100, 000, 000}}  ;BTN Seek
DL_CHILD_INFO {{100, 100, 000, 000}}  ;BTN Close
DL_CHILD_INFO {{000, 000, 000, 000}}  ;STC Field
DL_CHILD_INFO {{000, 000, 100, 100}}  ;CBO Field
DL_CHILD_INFO {{000, 000, 000, 000}}  ;STC For
DL_CHILD_INFO {{000, 000, 100, 100}}  ;EDT For
DL_CHILD_INFO {{000, 100, 000, 000}}  ;BTN Edit
DL_CHILD_INFO {{000, 100, 100, 000}}  ;SBR

.code
Method DB_SeekDlg.Init,, pOwner:POINTER, hParent:HWND, \
                         pTable:$ObjPtr(DB_Table), pActiveIndex:$ObjPtr(DB_Index), \
                         pRecNo:PDB_DATA_LINK_TYPE
  SetObject xcx
  m2m [xcx].pTable, pTable, xdx
  m2m [xcx].pActiveIndex, pActiveIndex, xdx
  m2m [xcx].pRecNo, pRecNo, xdx
  c2m [xcx].pDynamicLayout, offset SeekChildrenInfo, xdx
  ACall xcx.Init, pOwner, hParent, IDD_SEEK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_SeekDlg.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DB_SeekDlg.OnCommand, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local dSize:DWORD, RecDlg:$Obj(DB_RecordEditorDlg), DateBuffer[8]:CHRA
  local cBufferCtrl[LOCAL_BUFFER_SIZE]:CHR, cBuffer[LOCAL_BUFFER_SIZE]:CHR

;  DbgText "DB_SeekDlg.OnCommand"
  SetObject xsi

  ;Enable/Disable the SEEK button
  mov xax, wParam
  shr eax, 16
  .if ax == CBN_SELCHANGE || ax == EN_CHANGE
    OCall xsi.CtlsEnable
  .endif

  mov xax, wParam
  .if ax == IDC_SEEK_BTN_SEEK
    OCall xsi.CtlsGet
    .if [xsi].pActiveIndex != NULL
      lea xbx, cBuffer
      mov xcx, [xsi].pActiveIndex
      mov xdi, [xcx].$Obj(DB_Index).pOwner              ;xdx -> DB_Field
      mov cl, [xdi].$Obj(DB_Field).Descriptor.bType
      .if cl == FDT_CHAR_ANSI || cl == FDT_BOOL || cl == FDT_NUMERIC
        movzx eax, [xdi].$Obj(DB_Field).Descriptor.bLength
        inc eax                                         ;Include ZTC
        mov dSize, eax
        if TARGET_STR_TYPE eq STR_TYPE_WIDE
          invoke SendDlgItemMessage, [xsi].hWnd, IDC_SEEK_EDT_SEEK_FOR, WM_GETTEXT, \
                                     dSize, addr cBufferCtrl
          invoke WideCharToMultiByte, CP_ACP, 0, addr cBufferCtrl, -1, xbx, LOCAL_BUFFER_SIZE, \
                                      NULL, NULL
          ;eax = written bytes including ZTC
          dec eax
        else
          invoke SendDlgItemMessage, [xsi].hWnd, IDC_SEEK_EDT_SEEK_FOR, WM_GETTEXT, dSize, xbx
          ;eax = written Chars without ZTC
        endif
        ;Fill the rest of the buffer with spaces
        .if eax < dSize
          mov ecx, dSize
          sub ecx, eax
          dec ecx                                       ;Let room for the ZTC
          lea xdi, cBuffer
          add xdi, xax
          mov al, " "
          rep stosb
          mov CHRA ptr [xdi], 0
        .endif
      .elseif cl == FDT_CHAR_WIDE
        movzx eax, [xdi].$Obj(DB_Field).Descriptor.bLength;Bytes
        shr eax, 1                                      ;Chars
        inc eax                                         ;Include ZTC
        mov dSize, eax
        if TARGET_STR_TYPE eq STR_TYPE_WIDE
          invoke SendDlgItemMessage, [xsi].hWnd, IDC_SEEK_EDT_SEEK_FOR, WM_GETTEXT, eax, xbx
          ;eax = written chars without ZTC
        else
          invoke SendDlgItemMessage, [xsi].hWnd, IDC_SEEK_EDT_SEEK_FOR, WM_GETTEXT, \
                                     dSize, addr cBufferCtrl
          invoke MultiByteToWideChar, CP_ACP, 0, addr cBufferCtrl, -1, xbx, LOCAL_BUFFER_SIZE
          ;eax = written chars including ZTC
          dec eax
        endif
        ;Fill the rest of the buffer with WIDE spaces
        .if eax < dSize
          mov ecx, dSize
          sub ecx, eax
          dec ecx
          lea xdi, [cBuffer + 2*xax]
          mov ax, " "
          rep stosw
          mov CHRW ptr [xdi], 0
        .endif
      .elseif cl == FDT_CHAR_UTF8
        movzx eax, [xdi].$Obj(DB_Field).Descriptor.bLength
        inc eax                                         ;Include ZTC
        mov dSize, eax
        if TARGET_STR_TYPE eq STR_TYPE_WIDE
          invoke SendDlgItemMessage, [xsi].hWnd, IDC_SEEK_EDT_SEEK_FOR, WM_GETTEXT, \
                                     dSize, addr cBufferCtrl
        else
          invoke SendDlgItemMessage, [xsi].hWnd, IDC_SEEK_EDT_SEEK_FOR, WM_GETTEXT, dSize, xbx
          invoke MultiByteToWideChar, CP_ACP, 0, xbx, -1, addr cBufferCtrl, LOCAL_BUFFER_SIZE
        endif
        invoke WideCharToMultiByte, CP_UTF8, 0, addr cBufferCtrl, -1, xbx, LOCAL_BUFFER_SIZE, \
                                    NULL, NULL
        ;Fill the rest of the buffer with WIDE spaces
        .if eax < dSize
          mov ecx, dSize
          sub ecx, eax
          lea xdi, cBuffer
          add xdi, xax
          dec xdi                                       ;Overwrite ZTC too
          mov al, " "
          rep stosb
          mov CHRA ptr [xdi], 0
        .endif
      .elseif cl == FDT_DATE
        invoke SendDlgItemMessage, [xsi].hWnd, IDC_SEEK_EDT_SEEK_FOR, WM_GETTEXT, \
                                   LOCAL_BUFFER_SIZE/sizeof(CHR), xbx
        lea xcx, DateBuffer
        mov xax, [xsi].pOwner                           ;-> Application
        invoke DB_StrToDate, xcx, xbx, [xax].$Obj(Application).AppSetup.bDateFormat
        lea xbx, DateBuffer
      .elseif cl == FDT_SDWORD || cl == FDT_AUTOINC
        invoke SendDlgItemMessage, [xsi].hWnd, IDC_SEEK_EDT_SEEK_FOR, WM_GETTEXT, \
                                   LOCAL_BUFFER_SIZE/sizeof(CHR), xbx
        invoke dec2dword, xbx
        mov DWORD ptr [cBuffer], eax
      .elseif cl == FDT_REAL4
        invoke SendDlgItemMessage, [xsi].hWnd, IDC_SEEK_EDT_SEEK_FOR, WM_GETTEXT, \
                                   LOCAL_BUFFER_SIZE/sizeof(CHR), xbx
        invoke StrToSt0, xbx
        fstp REAL4 ptr [cBuffer]
      .elseif cl == FDT_REAL8 || cl == FDT_CURRENCY
        invoke SendDlgItemMessage, [xsi].hWnd, IDC_SEEK_EDT_SEEK_FOR, WM_GETTEXT, \
                                   LOCAL_BUFFER_SIZE/sizeof(CHR), xbx
        invoke StrToSt0, xbx
        fstp REAL8 ptr [cBuffer]
      .elseif cl == FDT_REAL10
        invoke SendDlgItemMessage, [xsi].hWnd, IDC_SEEK_EDT_SEEK_FOR, WM_GETTEXT, \
                                   LOCAL_BUFFER_SIZE/sizeof(CHR), xbx
        invoke StrToSt0, xbx
        fstp REAL10 ptr [cBuffer]
      .else
        mov DWORD ptr [cBuffer], 0
      .endif

      OCall [xsi].pActiveIndex::DB_Index.Seek, xbx
      .if eax == 0
        invoke MessageBox, [xsi].hWnd, $OfsCStr("No match found."), $OfsCStr("Notification"), \
                                       MB_OK or MB_ICONINFORMATION
      .else
        mov xcx, [xsi].pRecNo
        mov DB_DATA_LINK_TYPE ptr [xcx], eax
        OCall xsi.CtlsEnable
        OCall xsi.UpdateStatusbar
      .endif
    .endif

  .elseif ax == IDC_SEEK_BTN_EDIT
    .if [xsi].pRecNo != 0
      New RecDlg::DB_RecordEditorDlg
      mov xax, [xsi].pRecNo
      mov edi, DB_DATA_LINK_TYPE ptr [xax]
      OCall RecDlg::DB_RecordEditorDlg.Init, xsi, [xsi].hWnd, [xsi].pTable, edi
      OCall RecDlg::DB_RecordEditorDlg.Show
      OCall RecDlg::DB_RecordEditorDlg.Done
    .endif
    xor eax, eax

  .elseif ax == IDCANCEL || ax == IDC_SEEK_BTN_CLOSE
    OCall xsi.DestroyDialog, wParam
    xor eax, eax                                        ;Return zero

  .else
    mov eax, 1
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_SeekDlg.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = TRUE to direct the system to set the keyboard focus to the control specified by
;             wParam. Otherwise, it should return FALSE to prevent the system from setting the
;             default keyboard focus.

.const
align ALIGN_DATA
SeekDlgStatusbar DEF_STATUSBAR {IDC_SEEK_SBR, WS_CHILD or WS_VISIBLE or SBARS_TOOLTIPS, 0, 2}
  DEF_STATUSBAR_PART {200, 200, 1, SBT_SUNKEN,    NULL}
  DEF_STATUSBAR_PART {100, 100, 0, SBT_SUNKEN,    NULL}

.code
Method DB_SeekDlg.OnInitDialog, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  OCall [xsi].StatusBar::Statusbar.Init, xsi, [xsi].hWnd, offset(SeekDlgStatusbar)
  ACall xsi.OnInitDialog, wParam, lParam
  OCall xsi.CtlsEnable
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    DB_SeekDlg.UpdateStatusbar
; Purpose:   Update the info on the Statusbar.
; Arguments: None.
; Return:    Nothing.

Method DB_SeekDlg.UpdateStatusbar, uses xbx xdi xsi
  local cBuffer[50*sizeof(CHR)]:CHR

  SetObject xsi
  lea xdi, cBuffer
  mov xax, [xsi].pRecNo
  mov edx, DB_DATA_LINK_TYPE ptr [xax]
  .if edx == 0
    FillString [xdi], <Out of index>
  .else
    FillString [xdi], < Record >
    lea xbx, [xdi + 8*sizeof(CHR)]
    invoke dword2dec, xbx, edx
    invoke StrLRTrim, xbx, xbx
    invoke StrEnd, xbx
    FillString [xax], < of >
    lea xbx, [xax + 4*sizeof(CHR)]
    mov xdx, [xsi].pTable
    invoke dword2dec, xbx, [xdx].$Obj(DB_Table).Descriptor.dNumRecs
    invoke StrLRTrim, xbx, xbx
  .endif
  OCall [xsi].StatusBar::Statusbar.SetPartText, 0, xdi, SBT_SUNKEN

  .if [xsi].pActiveIndex == NULL
    OCall [xsi].StatusBar::Statusbar.SetPartText, 1, $OfsCStr("No active index"), SBT_SUNKEN
  .else
    OCall [xsi].StatusBar::Statusbar.SetPartText, 1, NULL, SBT_SUNKEN
  .endif
MethodEnd
