; ==================================================================================================
; Title:      DB_RecordEditorDlg.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm Database record editor dialog.
; Notes:      Version C.1.1, August 2019
;             - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------

RDF_EDITOR_ENABLED    equ   BIT00
RDF_APPEND_ENABLED    equ   BIT01
RDF_DELETE_ENABLED    equ   BIT02
RDF_RESTORE_ENABLED   equ   BIT03
RDF_BOTTOM_ENABLED    equ   BIT04
RDF_NEXT_ENABLED      equ   BIT05
RDF_PREV_ENABLED      equ   BIT06
RDF_TOP_ENABLED       equ   BIT07
RDF_CLOSE_ENABLED     equ   BIT08
RDF_EDIT_ENABLED      equ   BIT09
RDF_USE_INDEX_ENABLED equ   BIT10

DRF_INIT              equ   RDF_CLOSE_ENABLED


Object DB_RecordEditorDlg,, DialogModal
  VirtualMethod     CtlsEnable,       DWORD
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    Done
  RedefineMethod    Init,             POINTER, HWND, $ObjPtr(DB_Table), DB_DATA_LINK_TYPE
  RedefineMethod    OnCommand,        WPARAM, LPARAM
  RedefineMethod    OnInitDialog,     WPARAM, LPARAM
  RedefineMethod    OnSize,           WPARAM, LPARAM

  VirtualMethod     InsertIndexes
  VirtualMethod     SwitchToSelectedIndex
  VirtualMethod     UpdateNdxsAndTable, $ObjPtr(DB_Record)
  VirtualMethod     UpdateStatusbar

  VirtualEvent      OnExitSizeMove,   WM_EXITSIZEMOVE

  DefineVariable    pTable,           $ObjPtr(DB_Table),        NULL
  DefineVariable    pActiveIndex,     $ObjPtr(DB_Index),        NULL    ;Currently active index
  DefineVariable    pRecordEditor,    $ObjPtr(DB_RecordEditor), NULL    ;Created by the Dlg Template
  DefineVariable    dRecNo,           DB_DATA_LINK_TYPE,        1       ;Initially displayed RecNo
  DefineVariable    dFlags,           DWORD,                    DRF_INIT

  Embed     StatusBar,    Statusbar                                     ;Statusbar object
ObjectEnd


.code

; ==================================================================================================
;    DB_RecordEditorDlg implementation
; ==================================================================================================

UBO_OPS_CONTROLS  equ   BIT00
UBO_NAV_BUTTONS   equ   BIT01
UDO_ALL           equ   UBO_OPS_CONTROLS or UBO_NAV_BUTTONS

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditorDlg.CtlsEnable
; Purpose:    Enable or disable the dialog children controls.
; Arguments:  Arg1: Update options: UBO_ALL, UBO_OPS_CONTROLS, UBO_NAV_BUTTONS.
; Return:     Nothing.

EnableDialogButton macro CtlID:req, FlagID:req
  invoke GetDlgItem, [xsi].hWnd, CtlID
  xor edx, edx
  .ifBitSet [xsi].dFlags, FlagID
    inc edx
  .endif
  invoke EnableWindow, xax, edx
endm

Method DB_RecordEditorDlg.CtlsEnable, uses xsi, dOptions:DWORD
  SetObject xsi
  .ifBitSet dOptions, UBO_NAV_BUTTONS
    mov xcx, [xsi].pTable
    mov edx, [xcx].$Obj(DB_Table).Descriptor.dNumRecs
    .if edx == 0
      mov [xsi].dFlags, RDF_APPEND_ENABLED or RDF_CLOSE_ENABLED
    .elseif edx == 1
      mov [xsi].dFlags, RDF_CLOSE_ENABLED or \
                        RDF_EDIT_ENABLED or RDF_USE_INDEX_ENABLED
    .else
      BitSet [xsi].dFlags, RDF_TOP_ENABLED or RDF_PREV_ENABLED or \
                           RDF_NEXT_ENABLED or RDF_BOTTOM_ENABLED or \
                           RDF_EDIT_ENABLED or RDF_USE_INDEX_ENABLED
      .if [xsi].pActiveIndex == NULL
        mov eax, [xsi].dRecNo
        .if eax == 1
          BitClr [xsi].dFlags, RDF_TOP_ENABLED or RDF_PREV_ENABLED
          invoke GetDlgItem, [xsi].hWnd, IDC_RECORD_SBR
          invoke SendMessage, [xsi].hWnd, WM_NEXTDLGCTL, xax, TRUE
        .endif
        mov xcx, [xsi].pTable
        .if eax == [xcx].$Obj(DB_Table).Descriptor.dNumRecs
          BitClr [xsi].dFlags, RDF_NEXT_ENABLED or RDF_BOTTOM_ENABLED
          invoke GetDlgItem, [xsi].hWnd, IDC_RECORD_SBR
          invoke SendMessage, [xsi].hWnd, WM_NEXTDLGCTL, xax, TRUE
        .endif
      .else
        OCall [xsi].pActiveIndex::DB_Index.AtTop?
        .if ecx != FALSE
          BitClr [xsi].dFlags, RDF_TOP_ENABLED or RDF_PREV_ENABLED
          invoke GetDlgItem, [xsi].hWnd, IDC_RECORD_SBR
          invoke SendMessage, [xsi].hWnd, WM_NEXTDLGCTL, xax, TRUE
        .endif
        OCall [xsi].pActiveIndex::DB_Index.AtBottom?
        .if ecx != FALSE
          BitClr [xsi].dFlags, RDF_NEXT_ENABLED or RDF_BOTTOM_ENABLED
          invoke GetDlgItem, [xsi].hWnd, IDC_RECORD_SBR
          invoke SendMessage, [xsi].hWnd, WM_NEXTDLGCTL, xax, TRUE
        .endif
      .endif
    .endif
    EnableDialogButton IDC_RECORD_BTN_TOP,        RDF_TOP_ENABLED
    EnableDialogButton IDC_RECORD_BTN_PREV,       RDF_PREV_ENABLED
    EnableDialogButton IDC_RECORD_BTN_NEXT,       RDF_NEXT_ENABLED
    EnableDialogButton IDC_RECORD_BTN_BOTTOM,     RDF_BOTTOM_ENABLED
    EnableDialogButton IDC_RECORD_CHK_EDIT,       RDF_EDIT_ENABLED
    EnableDialogButton IDC_RECORD_CHK_USE_INDEX,  RDF_USE_INDEX_ENABLED
  .endif

  .ifBitSet dOptions, UBO_OPS_CONTROLS
    EnableDialogButton IDC_RECORD_BTN_APPEND,     RDF_APPEND_ENABLED
    EnableDialogButton IDC_RECORD_BTN_DELETE,     RDF_DELETE_ENABLED
    EnableDialogButton IDC_RECORD_BTN_RESTORE,    RDF_RESTORE_ENABLED

    xor edx, edx
    .ifBitSet [xsi].dFlags, RDF_EDITOR_ENABLED
      inc edx
    .endif
    OCall [xsi].pRecordEditor::DB_RecordEditor.CtlsEnable, edx
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditorDlg.CtlsGet
; Purpose:    Read the controls in this dialog window.
; Arguments:  None.
; Return:     Nothing.

Method DB_RecordEditorDlg.CtlsGet, uses xsi
  SetObject xsi
  mov xcx, [xsi].pTable
  OCall [xcx].$Obj(DB_Table).Records::DB_RecordCache.Get, [xsi].dRecNo
  .if eax == OBJ_OK
    mov xdx, xcx
    OCall [xsi].pRecordEditor::DB_RecordEditor.CtlsGet, xdx
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditorDlg.CtlsSet
; Purpose:    Set the controls in this dialog window.
; Arguments:  None.
; Return:     Nothing.

Method DB_RecordEditorDlg.CtlsSet, uses xsi
  SetObject xsi
  OCall xsi.CtlsEnable, UDO_ALL
  .if [xsi].dRecNo != 0
    mov xcx, [xsi].pTable
    OCall [xcx].$Obj(DB_Table).Records::DB_RecordCache.Get, [xsi].dRecNo
    .if eax == OBJ_OK
      mov xdx, xcx
      OCall [xsi].pRecordEditor::DB_RecordEditor.CtlsSet, xdx
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditorDlg.Done
; Purpose:    Finalize the DB_QueryDlg object.
; Arguments:  None.
; Return:     Nothing.

Method DB_RecordEditorDlg.Done, uses xsi
  SetObject xsi
  OCall [xsi].StatusBar::Statusbar.Done
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditorDlg.Init
; Purpose:    Initialize the DB_RecordEditorDlg object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> DB_Table.
;             Arg4: Initially displayed RecNo.
; Return:     Nothing.

Method DB_RecordEditorDlg.Init,, pOwner:POINTER, hParent:HWND, \
                                 pTable:$ObjPtr(DB_Table), dRecNo:DB_DATA_LINK_TYPE
  SetObject xcx
  m2m [xcx].pTable, pTable, xax
  m2m [xcx].dRecNo, dRecNo, xax
  ACall xcx.Init, pOwner, hParent, IDD_RECORD_EDITOR
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditorDlg.UpdateNdxsAndTable
; Purpose:    Update all used indexes.
; Arguments:  Arg1: -> Temporary DB_Record containing updated fields.
; Return:     Nothing.

Method DB_RecordEditorDlg.InsertIndexes, uses xbx xdi xsi
  local pCurrRec:$ObjPtr(DB_Record)

  SetObject xsi
  mov xdi, [xsi].pTable
  ;Get the unchanged record
  OCall [xdi].$Obj(DB_Table).Records::DB_RecordCache.Get, [xsi].dRecNo
  mov pCurrRec, xcx

  ;Compare each field. If it was modiefied, then update the corresponding index.
  xor ebx, ebx
  .while ebx != [xdi].$Obj(DB_Table).Fields.dCount
    OCall [xdi].$Obj(DB_Table).Fields::Collection.ItemAt, ebx
    mov xcx, [xax].$Obj(DB_Field).pIndex
    .if xcx != NULL
      OCall xcx::DB_Index.InsertRecord, pCurrRec
    .endif
    inc ebx
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditorDlg.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

$AllocRecord macro DataRecNo:req
  mov xdx, [xsi].pTable
  movzx eax, [xdx].$Obj(DB_Table).Descriptor.wRecordLen
  add eax, sizeof($Obj(DB_Record))
  MemAlloc eax
  m2m [xax].$Obj(DB_Record).dRecNo, DataRecNo, edx
  m2z [xax].$Obj(DB_Record).dFlags
  exitm xax
endm

Method DB_RecordEditorDlg.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  local pTempRec:$ObjPtr(DB_Record)

;  DbgText "DB_RecordEditorDlg.OnCommand"
  SetObject xsi

  mov xax, [xsi].pActiveIndex
  .if xax != NULL && [xax].$Obj(DB_Index).dInfoStackTop == 0
    DbgWarning "[xsi].dInfoStackTop == 0"
  .endif

  mov xax, wParam
  .if ax == IDC_RECORD_EDT
    mov [xsi].pActiveIndex, $OCall(xsi.SwitchToSelectedIndex)
    OCall xsi.CtlsEnable, UBO_NAV_BUTTONS
    xor eax, eax

  .elseif ax == IDC_RECORD_CHK_USE_INDEX
    invoke SendDlgItemMessage, [xsi].hWnd, IDC_RECORD_CHK_USE_INDEX, BM_GETCHECK, 0, 0
    .if eax == BST_UNCHECKED
      BitClr [xsi].dFlags, RDF_USE_INDEX_ENABLED
      mov eax, FALSE
    .else
      BitSet [xsi].dFlags, RDF_USE_INDEX_ENABLED
      mov eax, TRUE
    .endif
    OCall [xsi].pRecordEditor::DB_RecordEditor.ShowRadioButtons, eax
    invoke InvalidateRect, [xsi].hWnd, NULL, TRUE
    mov [xsi].pActiveIndex, $OCall(xsi.SwitchToSelectedIndex)
    OCall xsi.CtlsEnable, UBO_NAV_BUTTONS
    OCall xsi.UpdateStatusbar
    xor eax, eax

  .elseif ax == IDC_RECORD_CHK_EDIT
    invoke SendDlgItemMessage, [xsi].hWnd, IDC_RECORD_CHK_EDIT, BM_GETCHECK, 0, 0
    .if eax == BST_UNCHECKED
      BitClr [xsi].dFlags, RDF_EDIT_ENABLED or RDF_EDITOR_ENABLED or \
                           RDF_APPEND_ENABLED or RDF_DELETE_ENABLED or RDF_RESTORE_ENABLED

    .else
      BitSet [xsi].dFlags, RDF_EDIT_ENABLED or RDF_EDITOR_ENABLED or \
                           RDF_APPEND_ENABLED or RDF_DELETE_ENABLED or RDF_RESTORE_ENABLED
    .endif
    OCall xsi.CtlsEnable, UBO_OPS_CONTROLS
    OCall xsi.UpdateStatusbar
    xor eax, eax

  .elseif ax == IDC_RECORD_BTN_APPEND
    ;Get current record
    mov xcx, [xsi].pTable
    .if [xcx].$Obj(DB_Table).Descriptor.dNumRecs != 0
      mov pTempRec, $AllocRecord([xsi].dRecNo)
      OCall [xsi].pRecordEditor::DB_RecordEditor.CtlsGet, xax
      OCall xsi.UpdateNdxsAndTable, pTempRec
      MemFree pTempRec
    .endif
    ;Append new record
    OCall [xsi].pTable::DB_Table.AppendRecord           ;eax = Error, ecx = RecNo
    .if eax == OBJ_OK
      mov [xsi].dRecNo, ecx
      OCall xsi.InsertIndexes
      mov [xsi].pActiveIndex, $OCall(xsi.SwitchToSelectedIndex)
      .if xax != NULL
        OCall [xsi].pActiveIndex::DB_Index.SeekRecNo, [xsi].dRecNo
      .endif
      OCall xsi.CtlsSet
    .else
      DbgWarning "DB_Table.AppendRecord failed"
    .endif
    OCall xsi.UpdateStatusbar
    xor eax, eax

  .elseif ax == IDC_RECORD_BTN_DELETE
    OCall [xsi].pTable::DB_Table.Deleted?, [xsi].dRecNo ;eax = Error, ecx = TRUE/FALSE
    .if eax == OBJ_OK
      mov eax, ecx
      xor eax, TRUE                                     ;Toggle TRUE/FALSE
      OCall [xsi].pTable::DB_Table.Delete, [xsi].dRecNo, eax
    .endif
    OCall xsi.UpdateStatusbar
    xor eax, eax

  .elseif ax == IDC_RECORD_BTN_RESTORE
    OCall xsi.CtlsSet
    OCall xsi.UpdateStatusbar
    xor eax, eax

  .elseif ax == IDC_RECORD_BTN_TOP
    mov [xsi].pActiveIndex, $OCall(xsi.SwitchToSelectedIndex)
    .ifBitSet [xsi].dFlags, RDF_EDIT_ENABLED
      mov pTempRec, $AllocRecord([xsi].dRecNo)
      OCall [xsi].pRecordEditor::DB_RecordEditor.CtlsGet, xax
    .endif
    .if [xsi].pActiveIndex != NULL
      mov [xsi].dRecNo, $32($OCall([xsi].pActiveIndex::DB_Index.SeekTop))
    .else
      mov [xsi].dRecNo, 1
    .endif
    .ifBitSet [xsi].dFlags, RDF_EDIT_ENABLED
      OCall xsi.UpdateNdxsAndTable, pTempRec
      MemFree pTempRec
    .endif
    OCall xsi.CtlsSet
    OCall xsi.UpdateStatusbar
    xor eax, eax

  .elseif ax == IDC_RECORD_BTN_PREV
    mov [xsi].pActiveIndex, $OCall(xsi.SwitchToSelectedIndex)
    .ifBitSet [xsi].dFlags, RDF_EDIT_ENABLED
      mov pTempRec, $AllocRecord([xsi].dRecNo)
      OCall [xsi].pRecordEditor::DB_RecordEditor.CtlsGet, xax
    .endif
    .if [xsi].pActiveIndex != NULL
      mov [xsi].dRecNo, $32($OCall([xsi].pActiveIndex::DB_Index.Skip, -1))
    .else
      dec [xsi].dRecNo
    .endif
    .ifBitSet [xsi].dFlags, RDF_EDIT_ENABLED
      OCall xsi.UpdateNdxsAndTable, pTempRec
      MemFree pTempRec
    .endif
    OCall xsi.CtlsSet
    OCall xsi.UpdateStatusbar
    xor eax, eax

  .elseif ax == IDC_RECORD_BTN_NEXT
    mov [xsi].pActiveIndex, $OCall(xsi.SwitchToSelectedIndex)
    .ifBitSet [xsi].dFlags, RDF_EDIT_ENABLED
      mov pTempRec, $AllocRecord([xsi].dRecNo)
      OCall [xsi].pRecordEditor::DB_RecordEditor.CtlsGet, xax
    .endif
    .if [xsi].pActiveIndex != NULL
      mov [xsi].dRecNo, $32($OCall([xsi].pActiveIndex::DB_Index.Skip, +1))
    .else
      inc [xsi].dRecNo
    .endif
    .ifBitSet [xsi].dFlags, RDF_EDIT_ENABLED
      OCall xsi.UpdateNdxsAndTable, pTempRec
      MemFree pTempRec
    .endif

    OCall xsi.CtlsSet
    OCall xsi.UpdateStatusbar
    xor eax, eax

  .elseif ax == IDC_RECORD_BTN_BOTTOM
    mov [xsi].pActiveIndex, $OCall(xsi.SwitchToSelectedIndex)
    .ifBitSet [xsi].dFlags, RDF_EDIT_ENABLED
      mov pTempRec, $AllocRecord([xsi].dRecNo)
      OCall [xsi].pRecordEditor::DB_RecordEditor.CtlsGet, xax
    .endif
    .if [xsi].pActiveIndex != NULL
      mov [xsi].dRecNo, $32($OCall([xsi].pActiveIndex::DB_Index.SeekBottom))
    .else
      mov xcx, [xsi].pTable
      m2m [xsi].dRecNo, [xcx].$Obj(DB_Table).Descriptor.dNumRecs, eax
    .endif
    .ifBitSet [xsi].dFlags, RDF_EDIT_ENABLED
      OCall xsi.UpdateNdxsAndTable, pTempRec
      MemFree pTempRec
    .endif
    OCall xsi.CtlsSet
    OCall xsi.UpdateStatusbar
    xor eax, eax

  .elseif ax == IDCANCEL || ax == IDC_RECORD_BTN_CLOSE
    .ifBitSet [xsi].dFlags, RDF_EDIT_ENABLED
      mov pTempRec, $AllocRecord([xsi].dRecNo)
      OCall [xsi].pRecordEditor::DB_RecordEditor.CtlsGet, xax
      OCall xsi.UpdateNdxsAndTable, pTempRec
      MemFree pTempRec
    .endif
    OCall xsi.DestroyDialog, wParam
    xor eax, eax                                        ;Return zero

  .else
    mov eax, 1
  .endif

  mov xax, [xsi].pActiveIndex
  .if xax != NULL && [xax].$Obj(DB_Index).dInfoStackTop == 0
    DbgWarning "[xsi].dInfoStackTop == 0"
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditorDlg.OnExitSizeMove
; Purpose:    Event procedure for WM_EXITSIZEMOVE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method DB_RecordEditorDlg.OnExitSizeMove, uses xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "DB_RecordEditorDlg.OnExitSizeMove"
  SetObject xsi
  invoke SendMessage, [xsi].hWnd, DM_REPOSITION, 0, 0
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditorDlg.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = TRUE to direct the system to set the keyboard focus to the control specified by
;             wParam. Otherwise, it should return FALSE to prevent the system from setting the
;             default keyboard focus.

.data
align ALIGN_DATA
RecDlgChildrenInfo label DL_HEADER
DL_HEADER     {DLF_LOAD_MINMAX or DLF_LIMIT_MIN or DLF_LIMIT_MAX_Y}
DL_CHILD_INFO {{100, 100, 000, 000}}    ;Close
DL_CHILD_INFO {{000, 000, 100, 100}}    ;Editor
DL_CHILD_INFO {{100, 000, 000, 000}}    ;Append
DL_CHILD_INFO {{100, 000, 000, 000}}    ;Delete
DL_CHILD_INFO {{100, 000, 000, 000}}    ;Restore
DL_CHILD_INFO {{100, 100, 000, 000}}    ;Top
DL_CHILD_INFO {{100, 100, 000, 000}}    ;Prev
DL_CHILD_INFO {{100, 100, 000, 000}}    ;Next
DL_CHILD_INFO {{100, 100, 000, 000}}    ;Bottom
DL_CHILD_INFO {{100, 100, 000, 000}}    ;Use Indexes
DL_CHILD_INFO {{100, 100, 000, 000}}    ;Edit
DL_CHILD_INFO {{000, 100, 100, 000}}    ;Statusbar

.const
align ALIGN_DATA
RecDlgStatusbar DEF_STATUSBAR {IDC_RECORD_SBR, SBR_STYLE, 0, 3}
  DEF_STATUSBAR_PART {200, 200, 2, SBT_SUNKEN, NULL}
  DEF_STATUSBAR_PART {100, 100, 1, SBT_SUNKEN, NULL}
  DEF_STATUSBAR_PART {120,  -2, 0, SBT_SUNKEN, NULL}    ;Spring

.code
Method DB_RecordEditorDlg.OnInitDialog, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local CRect:RECT, WRect:RECT, ButtonSize:POINT, dTotalWidth:DWORD, dSpacing:DWORD

;  DbgText "Dialog.OnInitDialog"
  SetObject xsi
  c2m [xsi].pDynamicLayout, offset RecDlgChildrenInfo, xcx

  invoke GetDlgItem, [xsi].hWnd, IDC_RECORD_EDT
  mov [xsi].pRecordEditor, $invoke(SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0)
  mov [xax].$Obj(DB_RecordEditor).pOwner, xsi
  OCall xax::DB_RecordEditor.CtlsInit, [xsi].pTable
  OCall [xsi].StatusBar::Statusbar.Init, xsi, [xsi].hWnd, offset(RecDlgStatusbar)

  ;Position the navigation button more precisely than Windows does
  invoke GetDlgItem, [xsi].hWnd, IDC_RECORD_BTN_RESTORE
  lea xdx, WRect
  invoke GetWindowRect, xax, xdx
  invoke ScreenToClient, [xsi].hWnd, addr WRect.left
  mov ebx, WRect.left                                   ;This is the starting X position
  invoke ScreenToClient, [xsi].hWnd, addr WRect.right
  mov eax, WRect.right
  sub eax, WRect.left
  mov dTotalWidth, eax

  invoke GetDlgItem, [xsi].hWnd, IDC_RECORD_BTN_TOP     ;Left nav-button
  lea xdx, WRect
  invoke GetWindowRect, xax, xdx
  invoke ScreenToClient, [xsi].hWnd, addr WRect.left
  mov edi, WRect.top
  invoke ScreenToClient, [xsi].hWnd, addr WRect.right
  mov ecx, WRect.right
  sub ecx, WRect.left
  mov edx, WRect.bottom
  sub edx, WRect.top
  mov ButtonSize.x, ecx
  mov ButtonSize.y, edx

  mov eax, dTotalWidth
  shl ecx, 2
  sub eax, ecx
  cdiv 3
  mov dSpacing, edx
  invoke GetDlgItem, [xsi].hWnd, IDC_RECORD_BTN_TOP
  invoke SetWindowPos, xax, 0, ebx, edi, ButtonSize.x, ButtonSize.y, SWP_NOZORDER
  add ebx, ButtonSize.x
  add ebx, dSpacing
  invoke GetDlgItem, [xsi].hWnd, IDC_RECORD_BTN_PREV
  invoke SetWindowPos, xax, 0, ebx, edi, ButtonSize.x, ButtonSize.y, SWP_NOZORDER
  add ebx, ButtonSize.x
  add ebx, dSpacing
  invoke GetDlgItem, [xsi].hWnd, IDC_RECORD_BTN_NEXT
  invoke SetWindowPos, xax, 0, ebx, edi, ButtonSize.x, ButtonSize.y, SWP_NOZORDER
  add ebx, ButtonSize.x
  add ebx, dSpacing
  invoke GetDlgItem, [xsi].hWnd, IDC_RECORD_BTN_BOTTOM
  invoke SetWindowPos, xax, 0, ebx, edi, ButtonSize.x, ButtonSize.y, SWP_NOZORDER

  ACall xsi.OnInitDialog, wParam, lParam
  ;Set the max Y size, when the DB_RecordEditor is completely visible
  invoke GetClientRect, [xsi].hWnd, addr CRect
  mov xcx, [xsi].pRecordEditor
  mov eax, CRect.bottom
  sub eax, [xcx].$Obj(DB_RecordEditor).CtlSize.y
  add eax, [xcx].$Obj(DB_RecordEditor).ViewExtent.y
  mov RecDlgChildrenInfo.DL_HEADER.MaxSize.y, eax

  OCall xsi.CtlsEnable, UBO_OPS_CONTROLS or UBO_NAV_BUTTONS
  OCall xsi.UpdateStatusbar

  mov eax, TRUE                                         ;Let Windows set the default keyboard focus
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditorDlg.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter. wParam = SIZE_xxx
;             Arg2: Second message parameter. lParam = POINTS containing client area size.
; Return:     eax = Zero if handled.

Method DB_RecordEditorDlg.OnSize, uses xsi, wParam:WPARAM, lParam:LPARAM
  local EditorRect:RECT

;  DbgText "DB_RecordEditorDlg.OnSize"
  SetObject xsi
  ACall xsi.OnSize, wParam, lParam

  ;Forward the message to the structure editor control control.
  mov xcx, [xsi].pRecordEditor
  invoke GetClientRect, [xcx].$Obj(DB_RecordEditor).hWnd, addr EditorRect
  mov ecx, EditorRect.right
  mov eax, EditorRect.bottom
  shl eax, 16
  mov ax, cx
  invoke SendDlgItemMessage, [xsi].hWnd, IDC_RECORD_EDT, WM_SIZE, SIZE_RESTORED, xax

  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditorDlg.SwitchToSelectedIndex
; Purpose:    Updates the used index and build a new InfoStack.
; Arguments:  None.
; Return:     xax -> DB_Index or NULL if no index is selected.

Method DB_RecordEditorDlg.SwitchToSelectedIndex, uses xbx xsi
;  DbgText "DB_RecordEditorDlg.SwitchToSelectedIndex"
  SetObject xsi
  OCall [xsi].pRecordEditor::DB_RecordEditor.GetSelectedIndex
  .if xax != [xsi].pActiveIndex
    mov xbx, xax
    .if xax != NULL
      mov xcx, [xsi].pTable
      OCall [xcx].$Obj(DB_Table).Records::DB_RecordCache.Get, [xsi].dRecNo
      mov xdx, xcx
      OCall xbx::DB_Index.SeekRecord, xdx
      mov xax, xbx                                      ;Return value xax -> DB_Index
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditorDlg.UpdateNdxsAndTable
; Purpose:    Update all indexes and the current database record.
; Arguments:  Arg1: -> Temporary DB_Record containing the updated fields.
; Return:     Nothing.

Method DB_RecordEditorDlg.UpdateNdxsAndTable, uses xbx xdi xsi, pTempRec:$ObjPtr(DB_Record)
  local pCurrRec:$ObjPtr(DB_Record)
  local pField:$ObjPtr(DB_Field), dFieldIndex:DWORD
  local pTempKey:POINTER, pCurrKey:POINTER, dKeyLength:DWORD

  SetObject xsi
  mov xbx, [xsi].pTable
  mov xax, pTempRec
  ;Get the unchanged record
  OCall [xbx].$Obj(DB_Table).Records::DB_RecordCache.Get, [xax].$Obj(DB_Record).dRecNo
  mov pCurrRec, xcx

  ;Compare each field. If it was modiefied, then update the corresponding index.
  m2m dFieldIndex, [xbx].$Obj(DB_Table).Fields.dCount, eax
  .while dFieldIndex != 0
    dec dFieldIndex
    OCall [xbx].$Obj(DB_Table).Fields::Collection.ItemAt, dFieldIndex

    ;Check if the field has changed. Some fields can not be changed from the editor => skip them
    mov pField, xax
    mov cl, [xax].$Obj(DB_Field).Descriptor.bType
    .if cl != FDT_BINARY && cl != FDT_OLE && cl != FDT_TIMESTAMP
      mov edx, [xax].$Obj(DB_Field).dOffset
      mov xcx, pTempRec
      lea xcx, [xcx + xdx].$Obj(DB_Record).Buffer
      mov pTempKey, xcx
      mov xax, pCurrRec
      lea xdx, [xax + xdx].$Obj(DB_Record).Buffer
      mov pCurrKey, xdx
      mov xax, pField
      movzx eax, [xax].$Obj(DB_Field).Descriptor.bLength
      mov dKeyLength, eax
      invoke MemComp, xcx, xdx, eax
      .if eax != 0
        ;There is a difference => Check if the field has an index.
        mov xax, pField
        mov xdi, [xax].$Obj(DB_Field).pIndex
        .if xdi != NULL
          ;Update the index
          mov xax, pCurrRec
          OCall xdi::DB_Index.SeekKeyRecNo, pCurrKey, [xax].$Obj(DB_Record).dRecNo
          OCall xdi::DB_Index.DeleteKey
          mov xax, pTempRec
          OCall xdi::DB_Index.InsertKey, pTempKey, [xax].$Obj(DB_Record).dRecNo
          .if xdi == [xsi].pActiveIndex
            OCall [xsi].pActiveIndex::DB_Index.SeekRecNo, [xsi].dRecNo   ;Build the InfoStack
          .endif
        .endif

        ;Update the record field.
        mov xcx, pCurrRec
        BitSet [xcx].$Obj(DB_Record).dFlags, DBR_DATA_CHANGED   ;Mark as changed
        invoke MemClone, pCurrKey, pTempKey, dKeyLength
      .endif
    .endif
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditorDlg.UpdateStatusbar
; Purpose:    Update relevant database information on the statusbar.
; Arguments:  None.
; Return:     Nothing.

Method DB_RecordEditorDlg.UpdateStatusbar, uses xbx xsi
  local cBuffer[200*sizeof(CHR)]:CHR

  SetObject xsi
  lea xbx, cBuffer
  FillText [xbx], < Record >
  add xbx, 8*sizeof(CHR)
  invoke dword2dec, xbx, [xsi].dRecNo
  invoke StrECat, xbx, $OfsCStr(" of ")
  mov xdx, [xsi].pTable
  invoke dword2dec, xax, [xdx].$Obj(DB_Table).Descriptor.dNumRecs
  OCall [xsi].StatusBar::Statusbar.SetPartText, 0, addr cBuffer, SBT_SUNKEN

  .if [xsi].dRecNo != 0
    OCall [xsi].pTable::DB_Table.Deleted?, [xsi].dRecNo
    .if eax == OBJ_OK
      .if ecx != FALSE
        OCall [xsi].StatusBar::Statusbar.SetPartText, 1, $OfsCStr("Deleted"), SBT_SUNKEN
      .else
        OCall [xsi].StatusBar::Statusbar.SetPartText, 1, NULL, SBT_SUNKEN
      .endif
    .else
      OCall [xsi].StatusBar::Statusbar.SetPartText, 1, $OfsCStr("DATABASE ERROR"), SBT_SUNKEN
    .endif
  .endif
MethodEnd
