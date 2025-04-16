; ==================================================================================================
; Title:    DB_RecordEditor.inc
; Author:   G. Friedrich
; Version:  C.1.0
; Purpose:  ObjAsm Database DB_RecordEditor object.
; Notes:      Version C.1.1, August 2019
;             - First release.
; ==================================================================================================


Object DB_RecordEditorLine, DB_RecordEditorLineID, Primer
  VirtualMethod     CtlsGet,            PSTRING
  VirtualMethod     CtlsSet,            PSTRING
  VirtualMethod     CtlsMove,           POINTER, PCTRL_POSITIONS
  RedefineMethod    Done
  RedefineMethod    Init,               $ObjPtr(Collection), $ObjPtr(DB_Field)
  VirtualMethod     ShowIndexed,        DWORD, POINTER

  DefineVariable    pField,             $ObjPtr(DB_Field),  NULL
  DefineVariable    hStcFieldName,      HWND,       0
  DefineVariable    hRbnFieldName,      HWND,       0
  DefineVariable    hEdtRecord,         HWND,       0
ObjectEnd


Object DB_RecordEditor, DB_RecordEditorID, WinPrimer
  VirtualMethod     CtlsEnable,         DWORD
  VirtualMethod     CtlsGet,            $ObjPtr(DB_Record)
  VirtualMethod     CtlsInit,           $ObjPtr(DB_Table)
  VirtualMethod     CtlsMove
  VirtualMethod     CtlsSet,            $ObjPtr(DB_Record)
  VirtualMethod     Dispatch,           HWND, DWORD, WPARAM, LPARAM
  RedefineMethod    Done
  VirtualMethod     GetSelectedIndex
  RedefineMethod    Init,               POINTER, HWND
  VirtualMethod     InitRes,            HWND
  VirtualMethod     ShowRadioButtons,   DWORD
  StaticMethod      Startup
  VirtualMethod     WndProc,            DWORD, WPARAM, LPARAM

  ;Events
  StaticEvent       OnCommand,          WM_COMMAND
  StaticEvent       OnCreate,           WM_CREATE
  StaticEvent       OnEraseBkgnd,       WM_ERASEBKGND
  StaticEvent       OnMouseWheel,       WM_MOUSEWHEEL
  StaticEvent       OnScrollVert,       WM_VSCROLL
  StaticEvent       OnSize,             WM_SIZE

  DefineVariable    pTable,             $ObjPtr(DB_Table), NULL
  DefineVariable    dAllowErase,        DWORD,      0
  DefineVariable    hDWP,               HANDLE,     0

  ;UI elements
  Embed             EditorLines,        Collection
  DefineVariable    hFont,              HFONT,      0

  ;Metrics
  DefineVariable    DlgBaseUnit,        POINT,      {0,0}
  DefineVariable    ViewOrigin,         POINT,      {0,0}   ;Pixel offset from 0,0
  DefineVariable    ViewExtent,         POINT,      {0,0}   ;Size of content in pixel
  DefineVariable    ScrollPage,         POINT,      {0,0}   ;Chars and Lines to (page)scroll
  DefineVariable    dEdtButOffsetY,     DWORD,      0       ;Vertical offset from Edit to Button ctl
  DefineVariable    dEdtStcOffsetY,     DWORD,      0       ;Vertical offset from Edit to Static ctl
  DefineVariable    BtnSize,            POINT,      {0,0}   ;Radio button size
  DefineVariable    CtlSize,            POINT,      {0,0}   ;This control size
  DefineVariable    EdtSize,            POINT,      {0, CTL_HEIGHT_EDIT}    ;Edit control size
  DefineVariable    StcSize,            POINT,      {0, CTL_HEIGHT_STATIC}  ;Static control size
  DefineVariable    Margin,             POINT,      {CTL_MARGIN_HORZ, CTL_MARGIN_VERT}
  DefineVariable    Separation,         POINT,      {CTL_SEPARATION_HORZ, CTL_SEPARATION_VERT}
ObjectEnd


if IMPLEMENT

REL_CTRLS_PER_LINE  equ   3

; ==================================================================================================
; DB_RecordEditorLine
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditorLine.CtlsGet
; Purpose:    Get the content of the edit control of a field.
; Arguments:  Arg1: -> String buffer.
; Return:     Nothing.

Method DB_RecordEditorLine.CtlsGet,, pString:PSTRING
  SetObject xcx
  invoke GetWindowText, [xcx].hEdtRecord, pString, (LOCAL_BUFFER_SIZE/sizeof(CHR))
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditorLine.CtlsMove
; Purpose:    Moves the controls of the line into the DB_RecordEditor control.
; Arguments:  Arg1: -> DB_RecordEditor.
;             Arg2: -> CTRL_POSITIONS structure.

Method DB_RecordEditorLine.CtlsMove, uses xbx xdi xsi, pControl:POINTER, pCtlPos:PCTRL_POSITIONS
  SetObject xsi
  mov xdi, pControl
  assume xdi:$ObjPtr(DB_RecordEditor)
  mov xbx, pCtlPos
  assume xbx:PCTRL_POSITIONS

  mov eax, [xbx].LineOrigin.y
  add eax, [xdi].dEdtButOffsetY
  mov [xdi].hDWP, $invoke(DeferWindowPos, [xdi].hDWP, [xsi].hRbnFieldName, HWND_BOTTOM, \
                                          [xbx].sdPosX1, eax, [xdi].BtnSize.x, [xdi].BtnSize.y, 0)
  mov eax, [xbx].LineOrigin.y
  add eax, [xdi].dEdtStcOffsetY
  mov [xdi].hDWP, $invoke(DeferWindowPos, [xdi].hDWP, [xsi].hStcFieldName, HWND_BOTTOM, \
                                          [xbx].sdPosX2, eax, [xdi].StcSize.x, [xdi].StcSize.y, 0)

  mov eax, [xbx].LineOrigin.y
  mov [xdi].hDWP, $invoke(DeferWindowPos, [xdi].hDWP, [xsi].hEdtRecord, HWND_BOTTOM, \
                                          [xbx].sdPosX3, eax, [xdi].EdtSize.x, [xdi].EdtSize.y, 0)

  ;Increment Y position for the next line.
  mov eax, [xdi].Separation.y
  add [xbx].LineOrigin.y, eax
  assume xdi:NOTHING, xbx:NOTHING
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditorLine.CtlsSet
; Purpose:    Set the content of the edit control of a field.
; Arguments:  Arg1: -> New string.
; Return:     Nothing.

Method DB_RecordEditorLine.CtlsSet,, pStr:PSTRING
  SetObject xcx
  invoke SetWindowText, [xcx].hEdtRecord, pStr
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditorLine.Done
; Purpose:    Finalize the DB_RecordEditorLine object.
; Arguments:  None.
; Return:     Nothing.

Method DB_RecordEditorLine.Done, uses xsi
  SetObject xsi
  invoke DestroyWindow, [xsi].hRbnFieldName
  invoke DestroyWindow, [xsi].hStcFieldName
  invoke DestroyWindow, [xsi].hEdtRecord
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditorLine.Init
; Purpose:    Initialize the DB_RecordEditor object.
; Arguments:  Arg1: -> Collection
;             Arg2: -> DB_Field.
; Note:       Avoid setting CtlIDs that equals IDOK and IDCANCEL.
;             If used and the control is disabled, these messages are no longer sent!

Method DB_RecordEditorLine.Init, uses xbx xdi xsi, pOwner:$ObjPtr(Collection), \
                                                   pField:$ObjPtr(DB_Field)
  local xCtlID:XWORD

  SetObject xsi
  ACall xsi.Init, pOwner
  mov xdx, pOwner
  mov xdi, [xdx].$Obj(Collection).pOwner
  mrm [xsi].pField, pField, xbx                         ;xbx -> Field
  assume xdi:$ObjPtr(DB_RecordEditor)

  mov ecx, [xdx].$Obj(Collection).dCount                ;Starts with 1
  imul ecx, REL_CTRLS_PER_LINE
  mov xCtlID, xcx
  ;Use the ANSI version of the control to pass the ANSI caption string (Descriptor.bName)
  invoke CreateWindowExA, 0, $OfsCStrA("STATIC"), addr [xbx].$Obj(DB_Field).Descriptor.bName, \
                          WS_CHILD or WS_VISIBLE or WS_CLIPSIBLINGS or SS_ENDELLIPSIS or \
                          SS_CENTERIMAGE or SS_NOTIFY, \
                          CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                          [xdi].hWnd, xCtlID, hInstance, 0
  mov [xsi].hStcFieldName, xax
  invoke SendMessage, xax, WM_SETFONT, [xdi].hFont, FALSE
  inc xCtlID
  invoke CreateWindowEx, 0, $OfsCStr("BUTTON"), NULL, \
                         WS_CHILD or WS_TABSTOP or WS_CLIPSIBLINGS or BS_AUTORADIOBUTTON, \ ;Hidden!
                         CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                         [xdi].hWnd, xCtlID, hInstance, 0
  mov [xsi].hRbnFieldName, xax
  invoke SendMessage, xax, WM_SETFONT, [xdi].hFont, FALSE
  inc xCtlID
  invoke CreateWindowEx, WS_EX_CLIENTEDGE, $OfsCStr("EDIT"), NULL, \
                         WS_CHILD or WS_VISIBLE or WS_CLIPSIBLINGS or WS_TABSTOP or ES_AUTOHSCROLL,\
                         CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                         [xdi].hWnd, xCtlID, hInstance, 0
  mov [xsi].hEdtRecord, xax
  invoke SendMessage, [xsi].hEdtRecord, WM_SETFONT, [xdi].hFont, FALSE
  ;Limit the number of chars the user can input
  invoke DB_GetStdFieldInfo, [xbx].$Obj(DB_Field).Descriptor.bType
  .if [xax].STD_FIELD_INFO.bType == FDT_CHAR_WIDE
    movzx eax, [xbx].$Obj(DB_Field).Descriptor.bLength
    shr eax, 1
  .else
    movzx eax, [xax].STD_FIELD_INFO.bMaxInput
    .if eax == 0
      movzx eax, [xbx].$Obj(DB_Field).Descriptor.bLength
    .endif
  .endif
  invoke SendMessage, [xsi].hEdtRecord, EM_SETLIMITTEXT, eax, 0

  assume xdi:NOTHING
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditorLine.ShowIndexed
; Purpose:    Show or hide the index RadioButton.
; Arguments:  Arg1: Flag.
;             Arg2: Unused.

Method DB_RecordEditorLine.ShowIndexed,, dShow:DWORD, xUnused:XWORD
  SetObject xcx
  mov eax, SW_HIDE
  .if dShow != FALSE
    mov xdx, [xcx].pField
    .if [xdx].$Obj(DB_Field).pIndex != NULL
      mov eax, SW_SHOW
    .endif
  .endif
  invoke ShowWindow, [xcx].hRbnFieldName, eax
MethodEnd


; ==================================================================================================
; DB_RecordEditor
; ==================================================================================================

CStr szDB_RecordEditorClass, "DB_RecordEditor"

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditor.CtlsEnable
; Purpose:    Enable or disable all edit controls.
; Arguments:  Arg1: TRUE or FALSE.
; Return:     Nothing.

Method DB_RecordEditor.CtlsEnable, uses xbx xdi xsi, dAction:DWORD
  SetObject xsi
;  invoke EnableWindow, [xsi].hWnd, dAction
  xor edi, edi
  .while edi < [xsi].EditorLines.dCount
    OCall [xsi].EditorLines::Collection.ItemAt, edi
    mov xbx, xax
    mov xcx, [xbx].$Obj(DB_RecordEditorLine).pField
    invoke DB_GetStdFieldInfo, [xcx].$Obj(DB_Field).Descriptor.bType
    .ifBitSet [xax].STD_FIELD_INFO.bFlags, SFF_READ_ONLY
      xor edx, edx
    .else
      mov edx, dAction
    .endif
    invoke EnableWindow, [xbx].$Obj(DB_RecordEditorLine).hEdtRecord, edx
    inc edi
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditor.CtlsGet
; Purpose:    Get the content of the editor controls and put it into the record fields.
; Arguments:  Arg1: -> DB_Record.
; Return:     Nothing.

Method DB_RecordEditor.CtlsGet, uses xbx xdi xsi, pRecord:$ObjPtr(DB_Record)
  local cBuffer[LOCAL_BUFFER_SIZE]:CHR, dFieldIndex:DWORD

  SetObject xsi
  mov xdx, [xsi].pTable
  m2m dFieldIndex, [xdx].$Obj(DB_Table).Fields.dCount, eax
  lea xdi, cBuffer
  .while dFieldIndex > 0
    dec dFieldIndex
    mov xbx, $OCall([xsi].EditorLines::Collection.ItemAt, dFieldIndex)  ;xbx -> DB_RecordEditorLine
    OCall xbx::DB_RecordEditorLine.CtlsGet, xdi
    OCall [xbx].$Obj(DB_RecordEditorLine).pField::DB_Field.DataPutStr, pRecord, xdi
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditor.CtlsInit
; Purpose:    Create and initialize the controls according to the DB_Table information
; Arguments:  Arg1: -> DB_Table.
; Return:     Nothing.

GetFieldNameMaxWidth proc pField:$ObjPtr(DB_Field), pOwner:$ObjPtr(DB_RecordEditor), hDC:HDC
  local FieldNameSize:SIZE_

  mov xax, pField
  lea xdx, [xax].$Obj(DB_Field).Descriptor.bName
  invoke GetTextExtentPoint32A, hDC, xdx, DB_FIELD_NAME_LENGTH, addr FieldNameSize  ;Not incl. ZTC
  mov xcx, pOwner
  mov eax, FieldNameSize.cx_
  .if eax > [xcx].$Obj(DB_RecordEditor).StcSize.x
    mov [xcx].$Obj(DB_RecordEditor).StcSize.x, eax
  .endif
  ret
GetFieldNameMaxWidth endp

NewRecordEditorLine proc uses xsi pField:$ObjPtr(DB_Field), pControl:$ObjPtr(DB_RecordEditor), \
                                  xUnused:XWORD
  New DB_RecordEditorLine
  mov xcx, pControl
  lea xsi, [xcx].$Obj(DB_RecordEditor).EditorLines
  OCall xsi::Collection.Insert, xax
  OCall xax::DB_RecordEditorLine.Init, xsi, pField
  ret
NewRecordEditorLine endp

Method DB_RecordEditor.CtlsInit, uses xbx xsi, pTable:$ObjPtr(DB_Table)
  local hParent:HWND, hDC:HDC, hPrevFont:HFONT

  SetObject xsi
  mov hParent, $invoke(GetParent, [xsi].hWnd)
  mov [xsi].hFont, $invoke(SendMessage, hParent, WM_GETFONT, 0, 0)
  mov hDC, $invoke(GetDC, hParent)
  mov hPrevFont, $invoke(SelectObject, hDC, [xsi].hFont)

  ;Translate the control metrics from DLU to pixel.
  invoke GetDlgBaseUnits, hDC                           ;eax = DBUX, ecx = DBUY
  mov ebx, eax

  mov [xsi].Margin.x,     $Dlu2PixX([xsi].Margin.x, ebx)
  mov [xsi].Margin.y,     $Dlu2PixY([xsi].Margin.y, ecx)
  mov [xsi].Separation.x, $Dlu2PixX([xsi].Separation.x, ebx)
  mov [xsi].Separation.y, $Dlu2PixY([xsi].Separation.y, ecx)
  mov [xsi].EdtSize.y,    $Dlu2PixY([xsi].EdtSize.y, ecx)
  mov [xsi].StcSize.y,    $Dlu2PixY([xsi].StcSize.y, ecx)

  mov [xsi].BtnSize.x, $32($invoke(GetSystemMetrics, SM_CXMENUCHECK))
  mov [xsi].BtnSize.y, $32($invoke(GetSystemMetrics, SM_CYMENUCHECK))

  mov eax, [xsi].EdtSize.y
  sub eax, [xsi].StcSize.y
  shr eax, 1
  mov [xsi].dEdtStcOffsetY, eax

  mov eax, [xsi].EdtSize.y
  sub eax, [xsi].BtnSize.y
  shr eax, 1
  mov [xsi].dEdtButOffsetY, eax

  mrm [xsi].pTable, pTable, xbx
  mov [xsi].StcSize.x, 0
  OCall [xbx].$Obj(DB_Table).Fields::Collection.ForEach, offset(GetFieldNameMaxWidth), xsi, hDC
  OCall [xbx].$Obj(DB_Table).Fields::Collection.ForEach, offset(NewRecordEditorLine), xsi, 0

  invoke SelectObject, hDC, hPrevFont
  invoke ReleaseDC, hParent, hDC
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditor.CtlsMove
; Purpose:    Reposition the controls according to the new origin.
; Arguments:  None
; Return:     Nothing.

Method DB_RecordEditor.CtlsMove, uses xsi
  local ScrollInfo:SCROLLINFO, CtrlPos:CTRL_POSITIONS

;  DbgText "DB_RecordEditor.CtlsMove"
  SetObject xsi

  ;Calulate the control fix-positions and set the initial value for the line y-position
  s2s CtrlPos.LineOrigin, [xsi].ViewOrigin, xax, xcx
  xor eax, eax
  mov CtrlPos.sdPosX1, eax
  mov xcx, [xsi].pOwner                                 ;xcx -> DB_RecordEditorDlg
  .if xcx != NULL
    .ifBitSet [xcx].$Obj(DB_RecordEditorDlg).dFlags, RDF_USE_INDEX_ENABLED
      invoke SendDlgItemMessage, [xcx].$Obj(DB_RecordEditorDlg).hWnd, IDC_RECORD_CHK_USE_INDEX, \
                                 BM_GETCHECK, 0, 0
      .if eax == BST_CHECKED
        add eax, [xsi].BtnSize.x
        add eax, [xsi].Separation.x
      .endif
    .endif
  .endif
  mov CtrlPos.sdPosX2, eax
  add eax, [xsi].StcSize.x
  add eax, [xsi].Separation.x
  mov CtrlPos.sdPosX3, eax

  ;Calculate the X size of the edit control.
  mov edx, [xsi].CtlSize.x
  sub edx, eax
  mov ecx, [xsi].ViewExtent.y
  .if ecx > [xsi].CtlSize.y
    sub edx, [xsi].Margin.x                             ;Between EDIT and Scrollbar
  .endif
  mov [xsi].EdtSize.x, edx

  ;Lock all drawings and enable double buffering while the child windows are repositioned
  SetWndStyleEx [xsi].hWnd, WS_EX_COMPOSITED
  invoke SendMessage, [xsi].hWnd, WM_SETREDRAW, FALSE, 0

  mov ecx, [xsi].EditorLines.dCount
  imul ecx, REL_CTRLS_PER_LINE
  mov [xsi].hDWP, $invoke(BeginDeferWindowPos, ecx)
  mov xdx, $MethodAddr(DB_RecordEditorLine.CtlsMove)
  OCall [xsi].EditorLines::Collection.ForEach, xdx, xsi, addr CtrlPos
  invoke EndDeferWindowPos, [xsi].hDWP

  ;Update the Scrollbar information.
  ;This API shows/hides the Scrollbar automatically and may retrigger a WM_SIZE.
  mov ScrollInfo.cbSize, sizeof(ScrollInfo)
  mov ScrollInfo.fMask, SIF_PAGE or SIF_RANGE or SIF_POS
  mov ScrollInfo.nMin, 0
  mov eax, [xsi].ViewExtent.y
  dec eax
  mov ScrollInfo.nMax, eax
  mov eax, [xsi].CtlSize.y
  mov ScrollInfo.nPage, eax
  mov edx, [xsi].ViewOrigin.y
  neg edx
  mov ScrollInfo.nPos, edx
  invoke SetScrollInfo, [xsi].hWnd, SB_VERT, addr ScrollInfo, FALSE

  ;Reenable drawing and reset double buffering to allow smooth effect transitions
  invoke SendMessage, [xsi].hWnd, WM_SETREDRAW, TRUE, 0
  invoke InvalidateRect, [xsi].hWnd, NULL, TRUE
  mov [xsi].dAllowErase, TRUE
  invoke RedrawWindow, [xsi].hWnd, NULL, 0, RDW_UPDATENOW
  ClrWndStyleEx [xsi].hWnd, WS_EX_COMPOSITED
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditor.CtlsSet
; Purpose:    Set the editor controls with the content of the record fields.
; Arguments:  Arg1: -> DB_Record.
; Return:     Nothing.

Method DB_RecordEditor.CtlsSet, uses xbx xdi xsi, pRecord:$ObjPtr(DB_Record)
  local cBuffer[LOCAL_BUFFER_SIZE]:CHR, dFieldIndex:DWORD

  SetObject xsi
  mov xdx, [xsi].pTable
  m2m dFieldIndex, [xdx].$Obj(DB_Table).Fields.dCount, eax
  lea xdi, cBuffer
  .while dFieldIndex > 0
    dec dFieldIndex
    .if pRecord == NULL
      OCall xbx::DB_RecordEditorLine.CtlsSet, NULL
    .else
      mov xbx, $OCall([xsi].EditorLines::Collection.ItemAt, dFieldIndex)  ;xbx -> DB_RecordEditorLine
      OCall [xbx].$Obj(DB_RecordEditorLine).pField::DB_Field.DataGetStr, pRecord, xdi
      .if eax == OBJ_OK
        OCall xbx::DB_RecordEditorLine.CtlsSet, xdi
      .endif
    .endif
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditor.Dispatch
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Window handle.
;             Arg2: Message identifier.
;             Arg3: First message parameter.
;             Arg4: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the message.

Method DB_RecordEditor.Dispatch, uses xsi, hWnd:HWND, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg
  SetObject xsi
  DispatchEvent <DefWindowProc, hWnd>                   ;xsi -> Object instance
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditor.Done
; Purpose:    Finalize the DB_RecordEditor object.
; Arguments:  None.
; Return:     Nothing.

Method DB_RecordEditor.Done, uses xsi
  SetObject xsi
  OCall [xsi].EditorLines::Collection.Done
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditor.GetSelectedIndex
; Purpose:    Get the current selected Index.
; Arguments:  None.
; Return:     xax -> DB_Index or NULL.

Method DB_RecordEditor.GetSelectedIndex, uses xbx xdi xsi
  local pEditorLine:$ObjPtr(DB_RecordEditorLine)

  SetObject xsi
  xor ebx, ebx
  xor eax, eax
  .while ebx < [xsi].EditorLines.dCount
    OCall [xsi].EditorLines::Collection.ItemAt, ebx
    mov pEditorLine, xax
    mov xdi, [xax].$Obj(DB_RecordEditorLine).hRbnFieldName
    invoke IsWindowVisible, xdi
    .if eax != FALSE
      invoke SendMessage, xdi, BM_GETCHECK, 0, 0
      .break .if eax != FALSE
    .endif
    inc ebx
  .endw
  .if eax != FALSE
    mov xcx, pEditorLine
    mov xdx, [xcx].$Obj(DB_RecordEditorLine).pField
    mov xax, [xdx].$Obj(DB_Field).pIndex
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditor.Init
; Purpose:    Initialize the DB_RecordEditor object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
; Return:     xax = hWnd or 0 if failed.

Method DB_RecordEditor.Init, uses xsi, pOwner:POINTER, hParent:HWND
  DbgText "DB_RecordEditor.Init"

  SetObject xsi
  ACall xsi.Init, pOwner, 0

  ;Create DB_RecordEditor Window
  invoke CreateWindowEx, 0, offset(szDB_RecordEditorClass), NULL, \
                         WS_CHILD or WS_CLIPSIBLINGS or WS_CLIPCHILDREN or WS_VSCROLL, \
                         CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                         hParent, NULL, hInstance, pSelf
  .if xax != 0
    mov [xsi].hWnd, xax
    invoke ShowWindow, [xsi].hWnd, SW_SHOWDEFAULT
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditor.InitRes
; Purpose:    Initialize the Button object from a resource.
; Arguments:  Arg1: Button window handle.
; Return:     Nothing.

Method DB_RecordEditor.InitRes,, hWnd:HWND
;  DbgText "DB_RecordEditor.InitRes"
  SetObject xcx
  ?mov xdx, hWnd
  mov [xcx].hWnd, xdx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditor.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Zero if handled.

Method DB_RecordEditor.OnCommand, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "DB_RecordEditor.OnCommand"
  SetObject xsi
  mov xax, wParam
  shr eax, 16
  .if ax == STN_CLICKED                                 ;STN_CLICKED = 0
    mov xax, wParam
    and xax, 0FFFFh                                     ;ax = Control ID
    cdiv REL_CTRLS_PER_LINE
    dec edx
    OCall [xsi].EditorLines::Collection.ItemAt, edx
    .if xax != NULL
      mov xbx, xax
      invoke IsWindowVisible, [xbx].$Obj(DB_RecordEditorLine).hRbnFieldName
      .if eax != FALSE
        invoke SendMessage, [xbx].$Obj(DB_RecordEditorLine).hRbnFieldName, BM_GETSTATE, 0, 0

        .if eax == BST_UNCHECKED
          mov xax, wParam
          and eax, 0FFFFh                               ;ax = Control ID
          inc eax
          DbgDec eax
          invoke CheckRadioButton, [xsi].hWnd, 1, 999, eax
;          invoke SendMessage, [xbx].$Obj(DB_RecordEditorLine).hRbnFieldName, BM_SETCHECK, \
;                              BST_CHECKED, 0
        .elseif eax == BST_CHECKED
          invoke GetParent, [xsi].hWnd
          invoke SendMessage, xax, WM_NEXTDLGCTL, [xbx].$Obj(DB_RecordEditorLine).hEdtRecord, TRUE
        .endif
        ;Forward the WM_COMMAND to the parent
        invoke GetParent, [xsi].hWnd
        invoke SendMessage, xax, WM_COMMAND, IDC_RECORD_EDT, [xsi].hWnd
      .else
        invoke GetParent, [xsi].hWnd
        invoke SendMessage, xax, WM_NEXTDLGCTL, [xbx].$Obj(DB_RecordEditorLine).hEdtRecord, TRUE
      .endif
    .endif
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditor.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero to continue the window creation process and -1 to stop it.

Method DB_RecordEditor.OnCreate,, wParam:WPARAM, lParam:LPARAM
;  DbgText "DB_RecordEditor.OnCreate"
  SetObject xdx
  OCall [xdx].EditorLines::Collection.Init, xdx, 10, 10, COL_MAX_CAPACITY
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditor.OnEraseBkgnd
; Purpose:    Event procedure for WM_ERASEBKGND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Non zero if handled.

Method DB_RecordEditor.OnEraseBkgnd, uses xsi, wParam:WPARAM, lParam:LPARAM
  local CRect:RECT

;  DbgText "DB_RecordEditor.OnEraseBkgnd"
  SetObject xsi
  .if [xsi].dAllowErase == TRUE
    mov [xsi].dAllowErase, FALSE
    invoke GetClientRect, [xsi].hWnd, addr CRect
    invoke GetParent, [xsi].hWnd
    invoke SendMessage, xax, WM_CTLCOLORSTATIC, wParam, [xsi].hWnd  ;On return xax = Brush handle
    lea xdx, CRect
    invoke FillRect, wParam, xdx, xax
  .endif
  mov eax, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditor.OnMouseWheel
; Purpose:    Event procedure for WM_MOUSEWHEEL message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method DB_RecordEditor.OnMouseWheel, uses xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "DB_RecordEditor.OnMouseWheel"
  SetObject xsi
  mov eax, [xsi].ViewExtent.y
  .if eax > [xsi].CtlSize.y
    mov xdx, wParam
    shr edx, 16
    movsx ecx, dx                                       ;ecx = distance the wheel is rotated
    mov eax, [xsi].ViewOrigin.y

    ;Vertical scroll
    .ifBitSet wParam, MK_CONTROL
      ;Page scroll
      .if SDWORD ptr ecx > 0
        add eax, [xsi].CtlSize.y
      .else
        sub eax, [xsi].CtlSize.y
      .endif
    .else
      ;Regular scroll = 120 px
      .if SDWORD ptr ecx < 0
        mov eax, [xsi].ViewOrigin.y
        mov ecx, [xsi].Separation.y
        cdq
        idiv ecx
        dec eax
        imul ecx
        mov ecx, [xsi].ViewExtent.y
        sub ecx, [xsi].CtlSize.y
        neg ecx
        .if SDWORD ptr eax < ecx
          mov eax, ecx
        .endif
      .else
        mov eax, [xsi].ViewOrigin.y
        mov ecx, [xsi].Separation.y
        cdq
        idiv ecx
        .if edx == 0
          inc eax
        .endif
        imul ecx
        .if SDWORD ptr eax > 0
          xor eax, eax
        .endif
      .endif
    .endif

    ;Bound check
    .if SDWORD ptr eax > 0
      xor eax, eax
    .else
      mov ecx, [xsi].ViewExtent.y
      sub ecx, [xsi].CtlSize.y
      neg ecx
      .if SDWORD ptr eax < ecx
        mov eax, ecx
      .endif
    .endif

    .if eax != [xsi].ViewOrigin.y
      mov [xsi].ViewOrigin.y, eax
      OCall xsi.CtlsMove
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditor.OnScrollVert
; Purpose:    Event procedure for WM_VSCROLL message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DB_RecordEditor.OnScrollVert, uses xsi, wParam:WPARAM, lParam:LPARAM
  local ScrollInfo:SCROLLINFO

;  DbgText "DB_RecordEditor.OnScrollVert"
  SetObject xsi
  mov xax, wParam
  .if ax == SB_THUMBTRACK
    mov ScrollInfo.cbSize, sizeof(ScrollInfo)
    mov ScrollInfo.fMask, SIF_TRACKPOS
    invoke GetScrollInfo, [xsi].hWnd, SB_VERT, addr ScrollInfo
    mov eax, ScrollInfo.nTrackPos
    neg eax

  .elseif ax == SB_LINEUP
    mov eax, [xsi].ViewOrigin.y
    mov ecx, [xsi].Separation.y
    cdq
    idiv ecx
    .if edx == 0
      inc eax
    .endif
    imul ecx
    .if SDWORD ptr eax > 0
      xor eax, eax
    .endif

  .elseif ax == SB_LINEDOWN
    mov eax, [xsi].ViewOrigin.y
    mov ecx, [xsi].Separation.y
    cdq
    idiv ecx
    dec eax
    imul ecx
    mov ecx, [xsi].ViewExtent.y
    sub ecx, [xsi].CtlSize.y
    neg ecx
    .if SDWORD ptr eax < ecx
      mov eax, ecx
    .endif

  .elseif ax == SB_PAGEUP
    mov eax, [xsi].ViewOrigin.y
    mov ecx, [xsi].CtlSize.y
    add eax, ecx
    .if SDWORD ptr eax > 0
      xor eax, eax
    .endif

  .elseif ax == SB_PAGEDOWN
    mov eax, [xsi].ViewOrigin.y
    mov ecx, [xsi].CtlSize.y
    sub eax, ecx
    mov ecx, [xsi].ViewExtent.y
    sub ecx, [xsi].CtlSize.y
    neg ecx
    .if SDWORD ptr eax < ecx
      mov eax, ecx
    .endif

  .else
    jmp @F
  .endif

  mov [xsi].ViewOrigin.y, eax
  OCall xsi.CtlsMove

@@:
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditor.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter. wParam = SIZE_xxx
;             Arg2: Second message parameter. lParam = POINTS containing client area size.
; Return:     eax = Zero if handled.

Method DB_RecordEditor.OnSize, uses xsi, wParam:WPARAM, lParam:LPARAM
  local NewCtlSize:POINT

;  DbgText "DB_RecordEditor.OnSize"
  SetObject xsi

  .if wParam != SIZE_MINIMIZED && lParam != 0           ;x = 0 & y = 0
    PntS2Pnt NewCtlSize, lParam

    mov eax, NewCtlSize.y
    .if eax > [xsi].CtlSize.y
      sub eax, [xsi].CtlSize.y
      add [xsi].ViewOrigin.y, eax
      .if !SIGN?
        m2z [xsi].ViewOrigin.y
      .endif
    .endif
    s2s [xsi].CtlSize, NewCtlSize, xax, xcx

    mov eax, [xsi].EditorLines.dCount
    .if eax != 0
      ;Calculate the new ViewExtent
      m2m [xsi].ViewExtent.x, [xsi].CtlSize.x, edx
      dec eax
      mul [xsi].Separation.y
      add eax, [xsi].EdtSize.y
      mov ecx, [xsi].Margin.y
      shl ecx, 1
      add ecx, eax
      xor eax, eax
      mov [xsi].ViewExtent.y, ecx
    .else
      xor ecx, ecx
      mov [xsi].EdtSize.x, ecx
      mov [xsi].EdtSize.x, ecx
    .endif

    OCall xsi.CtlsMove

    xor eax, eax
  .else
    mov eax, -1
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditor.ShowRadioButtons
; Purpose:    Shows or hides all RadioButtons.
; Arguments:  Arg1: TRUE or FALSE.
; Return:     Nothing.

Method DB_RecordEditor.ShowRadioButtons, uses xsi, dShow:DWORD
  SetObject xsi
  OCall xsi.CtlsMove
  OCall [xsi].EditorLines::Collection.ForEach, $MethodAddr(DB_RecordEditorLine.ShowIndexed), dShow, 0
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditor.Startup
; Purpose:    Register the DB_RecordEditor object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method DB_RecordEditor.Startup
  local WC:WNDCLASSEX

;  DbgText "DB_RecordEditor.Startup"
  mov WC.cbSize, sizeof(WNDCLASSEX)
  mov WC.style, 0
  m2m WC.lpfnWndProc, $MethodAddr(DB_RecordEditor.WndProc), xdx
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, edx
  mov WC.hbrBackground, 0
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset(szDB_RecordEditorClass), xdx
  m2z WC.hIcon
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_RecordEditor.WindowProc
; Purpose:    Processing of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the message ID.
; Note:       Window HANDLE is passed in pSelf (hidden argument).

Method DB_RecordEditor.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg, "DB_RecordEditor.WndProc"
  .if uMsg == WM_NCCREATE
    mov xax, lParam
    .if [xax].CREATESTRUCT.lpCreateParams == NULL
      ;If lpCreateParams is 0, then it is a resource call => Create new object instance
      mov xsi, $New(DB_RecordEditor)
      OCall xax::DB_RecordEditor.InitRes, pSelf
    .else
      ;Init call
      mov xsi, [xax].CREATESTRUCT.lpCreateParams
      m2m [xsi].$Obj(DB_RecordEditor).hWnd, pSelf, xdx
    .endif
    invoke SetWindowLongPtr, pSelf, GWLP_USERDATA, xsi
    OCall xsi::DB_RecordEditor.Dispatch, pSelf, uMsg, wParam, lParam
  .else
    invoke GetWindowLongPtr, pSelf, GWLP_USERDATA       ;If GWL_USERDATA wasn't set,
    .if xax == NULL                                     ;GetWindowLong returns NULL
      invoke DefWindowProc, pSelf, uMsg, wParam, lParam
    .else
      OCall xax::DB_RecordEditor.Dispatch, pSelf, uMsg, wParam, lParam
    .endif
  .endif
MethodEnd

endif
