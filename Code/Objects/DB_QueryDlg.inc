; ==================================================================================================
; Title:      DB_QueryDlg.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm Database query dialog.
; Notes:      Version C.1.1, August 2019
;             - First release.
; ==================================================================================================



CStr szColTitle0, "Rec.Nbr."
CStr szColTitle1, "Manufacturer"
CStr szColTitle2, "Bearing ID"
CStr szColTitle3, "Pitch Diam."
CStr szColTitle4, "Roller Diam."
CStr szColTitle5, "Contact Angle"
CStr szColTitle6, "# Rollers"

PROPLVSTYLE     equ  WS_CHILD or WS_VISIBLE or WS_CLIPCHILDREN or WS_BORDER or \
                     LVS_REPORT or LVS_SHOWSELALWAYS

PROPLVEXSTYLE   equ  LVS_EX_FULLROWSELECT or LVS_EX_GRIDLINES or \
                     LVS_EX_HEADERDRAGDROP or LVS_EX_TRACKSELECT or LVS_EX_ONECLICKACTIVATE

PROPCOLUMNFLAG  equ  LVCF_FMT or LVCF_SUBITEM or LVCF_WIDTH or LVCF_TEXT

.data
align ALIGN_DATA
PropListView DEF_LISTVIEW {101, PROPLVSTYLE, PROPLVEXSTYLE, NULL, {<5,5,420,257>}, 7}
  LV_COLUMN {PROPCOLUMNFLAG, LVCFMT_LEFT, 60, offset szColTitle0, 0, 0}
  LV_COLUMN {PROPCOLUMNFLAG, LVCFMT_LEFT, 60, offset szColTitle1, 0, 1}
  LV_COLUMN {PROPCOLUMNFLAG, LVCFMT_LEFT, 60, offset szColTitle2, 0, 2}
  LV_COLUMN {PROPCOLUMNFLAG, LVCFMT_LEFT, 60, offset szColTitle3, 0, 3}
  LV_COLUMN {PROPCOLUMNFLAG, LVCFMT_LEFT, 60, offset szColTitle4, 0, 4}
  LV_COLUMN {PROPCOLUMNFLAG, LVCFMT_LEFT, 60, offset szColTitle5, 0, 5}
  LV_COLUMN {PROPCOLUMNFLAG, LVCFMT_LEFT, 60, offset szColTitle6, 0, 6}

; --------------------------------------------------------------------------------------------------

Object DB_QueryDlg,, DialogModal
  RedefineMethod    Done
  RedefineMethod    CtlsSet
  RedefineMethod    OnCommand,   WPARAM, LPARAM
  VirtualMethod     Refresh

  VirtualEvent      OnNotify,    WM_NOTIFY

  DefineVariable    pListView,   $ObjPtr(ListView),     NULL
ObjectEnd


; ==================================================================================================
;    DB_QueryDlg implementation
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Method:     DB_QueryDlg.Done
; Purpose:    Finalize the DB_QueryDlg object.
; Arguments:  None.
; Return:     Nothing.

Method DB_QueryDlg.Done, uses xsi
  SetObject xsi
  Destroy [xsi].pListView
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_QueryDlg.CtlsSet
; Purpose:    Set the controls in this dialog window.
; Arguments:  None.
; Return:     Nothing.

Method DB_QueryDlg.CtlsSet, uses xsi
  local cBuffer[128*sizeof(CHR)]:CHR

  SetObject xsi
  invoke StrECopy, addr cBuffer, $OfsCStr("Query result  - ")
  mov xdx, [xsi].pOwner
  invoke dword2dec, xax, [xdx].$Obj(Application).Query.dCount
  invoke StrECat, addr cBuffer, $OfsCStr(" matches -")
  invoke SetWindowText, [xsi].hWnd, addr cBuffer

  ;Create the ListView object; It's automatically destroyed by the dialog.
  mov [xsi].pListView, $New(ListView)
  OCall [xsi].pListView::ListView.Init, xsi, [xsi].hWnd, offset PropListView
  OCall [xsi].pListView::ListView.HeaderSetFontStyle, LVHDRFONTBOLD
  OCall xsi.Refresh
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_QueryDlg.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DB_QueryDlg.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov xax, wParam
  .if ax == IDC_QUERY_UPDATE
    OCall xsi.CtlsGet
    OCall xsi.DestroyDialog, wParam
  .elseif ax == IDC_QUERY_CLOSE
    OCall xsi.DestroyDialog, wParam
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_QueryDlg.OnNotify
; Purpose:    Event procedure for WM_NOTIFY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method DB_QueryDlg.OnNotify, uses xsi, wParam:WPARAM, lParam:LPARAM
  local RecDlg:$Obj(DB_RecordEditorDlg)

  SetObject xsi
  mov xax, lParam
  .if ([xax].NMHDR.code == NM_DBLCLK) && ([xax].NMHDR.idFrom == 101)
    mov xax, [xsi].pListView
    invoke SendMessage, [xax].$Obj(ListView).hWnd, LVM_GETNEXTITEM, -1, LVNI_ALL or LVNI_SELECTED
    .if eax != -1
      mov xcx, [xsi].pOwner
      lea xcx, [xcx].$Obj(Application).Query
      OCall xcx::DB_Query.RecNoAt, eax
      mov xcx, [xsi].pOwner
      mov [xcx].$Obj(Application).dRecNo, eax
      New RecDlg::DB_RecordEditorDlg
      mov xcx, [xsi].pOwner
      lea xax, [xcx].$Obj(Application).Table
      OCall RecDlg::DB_RecordEditorDlg.Init, [xsi].pOwner, [xsi].hWnd, xax, 1
      OCall RecDlg::DB_RecordEditorDlg.Show
      .if eax == IDC_QUERY_UPDATE
        OCall xsi.Refresh
      .endif
      OCall RecDlg::DB_RecordEditorDlg.Done
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_QueryDlg.Refresh
; Purpose:    Update the ListView content.
; Arguments:  None.
; Return:     Nothing.

Method DB_QueryDlg.Refresh, uses xbx xdi xsi
  local cBuffer[50*sizeof(CHR)]:CHR, pTable:$ObjPtr(DB_Table), LVI:LV_ITEM
  local dRow:DWORD, dColumn:DWORD, dRecNo:DWORD

  SetObject xsi

  mov xax, [xsi].pOwner
  lea xcx, [xax].$Obj(Application).Table
  mov pTable, xcx
  lea xdi, [xax].$Obj(Application).Query
  mov xbx, [xsi].pListView
;  invoke LockWindowUpdate, [xbx].ListView.hWnd    ;Disable drawing on the ListView
  invoke SendMessage, [xbx].$Obj(ListView).hWnd, LVM_DELETEALLITEMS, 0, 0

  mov LVI.mask_, LVIF_TEXT
  lea xdx, cBuffer
  mov LVI.pszText, xdx
  mov dRow, 0
  .while TRUE
    mov edx, dRow
    .break .if edx == [xdi].$Obj(DB_Query).dCount
    mov LVI.iItem, edx
    m2z LVI.iSubItem
    mov dRecNo, $32($OCall(xdi::DB_Query.RecNoAt, edx))
    invoke dword2dec, addr cBuffer, dRecNo
    invoke SendMessage, [xbx].$Obj(ListView).hWnd, LVM_INSERTITEM, 0, addr LVI

    mov dColumn, 0
    .while TRUE
      mov edx, dColumn
      .break .if edx == 6
      inc edx
      mov LVI.iSubItem, edx
      OCall pTable::DB_Table.DataGetFrom, dRecNo, dColumn ;xcx -> Data, edx = size
      lea xax, cBuffer
      add xax, xdx
      m2z CHR ptr [xax]                                 ;Set ZTC
      mov eax, edx
      mov xdx, xcx
      lea xcx, cBuffer
      invoke MemClone, xcx, xdx, eax                    ;Copy the rest of the string
      invoke StrRTrim, addr cBuffer, addr cBuffer
      invoke SendMessage, [xbx].$Obj(ListView).hWnd, LVM_SETITEM, 0, addr LVI
      inc dColumn
    .endw
    inc dRow
  .endw
MethodEnd
