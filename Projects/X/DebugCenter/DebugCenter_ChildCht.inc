; ==================================================================================================
; Title:      DebugCenter_ChildCht.inc
; Author:     G. Friedrich
; Version:    See DebugCenter.asm
; Purpose:    ObjAsm DebugCenter Chart MDI child window.
; ==================================================================================================


CStr szDbgMdiChildChtClass, "OAC_DbgMdiChildCht"                         ;Debug Window Child

DATAPOINTS        equ    1001

Object DbgMdiChildCht, DBG_MDI_CHILD_CHT_ID, DbgMdiChild
  RedefineMethod    ClpBrdClear
  RedefineMethod    ClpBrdCopy
  RedefineMethod    ClpBrdCut
  RedefineMethod    ClpBrdPaste
  RedefineMethod    ClpBrdSetBtns
  RedefineMethod    Done
  RedefineMethod    Erase
  RedefineMethod    Init,             POINTER, PSTRING, DWORD   ;-> Owner, -> Title, BackColor
  RedefineMethod    OnSize,           WPARAM, LPARAM
  RedefineMethod    Open,             PSTRING
  RedefineMethod    Print
  RedefineMethod    SaveAs,           PSTRING, PSTRING          ;-> Filter, -> Def. extension
  RedefineMethod    SaveTo,           PSTRING
  RedefineMethod    UpdateStatusbar
  RedefineMethod    ZoomIn
  RedefineMethod    ZoomOut
  StaticMethod      Startup

  VirtualEvent      OnCreate,         WM_CREATE
  VirtualEvent      OnEraseBkgnd,     WM_ERASEBKGND
  VirtualEvent      OnPaint,          WM_PAINT
  VirtualEvent      OnHScroll,        WM_HSCROLL
  VirtualEvent      OnVScroll,        WM_VSCROLL
  VirtualEvent      OnRButtonDown,    WM_RBUTTONDOWN
  VirtualEvent      OnRButtonUp,      WM_RBUTTONUP
  VirtualEvent      OnMouseWheel,     WM_MOUSEWHEEL
  VirtualEvent      OnKeyDown,        WM_KEYDOWN

  DefineVariable    dHorzOffset,      DWORD,          0
  DefineVariable    dVertOffset,      DWORD,          0
  DefineVariable    dBackColor,       DWORD,          DBG_COLOR_BACKGROUND_WND_LIGHT

  Embed   Chart,    ChartWnd
ObjectEnd


.code
; ==================================================================================================
;    DbgMdiChildCht implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     DbgMdiChildCht.ClpBrdClear
; Purpose:    Delete the selection to the clipboard.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildCht.ClpBrdClear, uses xsi
  SetObject xsi
  ACall xsi.ClpBrdClear
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DbgMdiChildCht.ClpBrdCopy
; Purpose:    Copy the selection to the clipboard.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildCht.ClpBrdCopy, uses xsi
  SetObject xsi
  ACall xsi.ClpBrdCopy
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DbgMdiChildCht.ClpBrdCut
; Purpose:    Cut the selection to the clipboard.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildCht.ClpBrdCut, uses xsi
  SetObject xsi
  ACall xsi.ClpBrdCut
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DbgMdiChildCht.ClpBrdPaste
; Purpose:    Paste the selection to the clipboard.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildCht.ClpBrdPaste, uses xsi
  SetObject xsi
  ACall xsi.ClpBrdPaste
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DbgMdiChildCht.ClpBrdSetBtns
; Purpose:    Set the cut, copy & paste clipboard buttons.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildCht.ClpBrdSetBtns, uses xbx xdi xsi
  local hMenu:HMENU, dActivate:DWORD

  SetObject xsi
  mov xcx, [xsi].pOwner
  mov xdi, [xcx].$Obj(DbgMdiClient).pOwner
  mov hMenu, $invoke(GetMenu, [xdi].$Obj(Application).hWnd) ;Get the current menu
;  .if [xsi].pBmp == NULL
;    mov xbx, [xdi].$Obj(Application).pToolbarEdit
;    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_CUT, FALSE
;    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_COPY, FALSE
;    mov xbx, hMenu
;    invoke EnableMenuItem, xbx, IDM_EDIT_CUT, MF_BYCOMMAND or MF_GRAYED
;    invoke EnableMenuItem, xbx, IDM_EDIT_COPY, MF_BYCOMMAND or MF_GRAYED
;    invoke EnableMenuItem, xbx, IDM_EDIT_CLEAR, MF_BYCOMMAND or MF_GRAYED
;    invoke EnableMenuItem, xbx, IDM_EDIT_ERASE, MF_BYCOMMAND or MF_GRAYED
;    invoke EnableMenuItem, xbx, IDM_EDIT_CALC, MF_BYCOMMAND or MF_GRAYED
;    mov xbx, $ObjTmpl(Application).hMenuContext
;    invoke EnableMenuItem, xbx, IDM_EDIT_CUT, MF_BYCOMMAND or MF_GRAYED
;    invoke EnableMenuItem, xbx, IDM_EDIT_COPY, MF_BYCOMMAND or MF_GRAYED
;    invoke EnableMenuItem, xbx, IDM_EDIT_CLEAR, MF_BYCOMMAND or MF_GRAYED
;    invoke EnableMenuItem, xbx, IDM_EDIT_ERASE, MF_BYCOMMAND or MF_GRAYED
;    invoke EnableMenuItem, xbx, IDM_EDIT_CALC, MF_BYCOMMAND or MF_GRAYED
;  .else
;    mov xbx, [xdi].$Obj(Application).pToolbarEdit
;    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_CUT, TRUE
;    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_COPY, TRUE
;    mov xbx, hMenu
;    invoke EnableMenuItem, xbx, IDM_EDIT_CUT, MF_BYCOMMAND or MF_ENABLED
;    invoke EnableMenuItem, xbx, IDM_EDIT_COPY, MF_BYCOMMAND or MF_ENABLED
;    invoke EnableMenuItem, xbx, IDM_EDIT_CLEAR, MF_BYCOMMAND or MF_ENABLED
;    invoke EnableMenuItem, xbx, IDM_EDIT_ERASE, MF_BYCOMMAND or MF_ENABLED
;    invoke EnableMenuItem, xbx, IDM_EDIT_CALC, MF_BYCOMMAND or MF_GRAYED
;    mov xbx, $ObjTmpl(Application).hMenuContext
;    invoke EnableMenuItem, xbx, IDM_EDIT_CUT, MF_BYCOMMAND or MF_ENABLED
;    invoke EnableMenuItem, xbx, IDM_EDIT_COPY, MF_BYCOMMAND or MF_ENABLED
;    invoke EnableMenuItem, xbx, IDM_EDIT_CLEAR, MF_BYCOMMAND or MF_ENABLED
;    invoke EnableMenuItem, xbx, IDM_EDIT_ERASE, MF_BYCOMMAND or MF_ENABLED
;    invoke EnableMenuItem, xbx, IDM_EDIT_CALC, MF_BYCOMMAND or MF_GRAYED
;  .endif

  mov dActivate, TRUE
  .if !$invoke(IsClipboardFormatAvailable, CF_DIB)
    dec dActivate
  .endif

  mov xbx, [xdi].$Obj(Application).pToolbarEdit
  invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_PASTE, dActivate
  .if dActivate
    mov edi, MF_BYCOMMAND or MF_ENABLED
  .else
    mov edi, MF_BYCOMMAND or MF_GRAYED
  .endif
  invoke EnableMenuItem, hMenu, IDM_EDIT_PASTE, edi
  invoke EnableMenuItem, $ObjTmpl(Application).hMenuContext, IDM_EDIT_PASTE, edi
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DbgMdiChildCht.Done
; Purpose:    Finalize the DbgMdiChildCht object.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildCht.Done, uses xsi
  SetObject xsi
  OCall [xsi].Chart::ChartWnd.Done
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DbgMdiChildCht.Erase
; Purpose:    Erase the content of the window.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildCht.Erase, uses xsi
  SetObject xsi
  OCall xsi.ClpBrdClear
  OCall [xsi].Chart.Data::Collection.DisposeAll
  OCall [xsi].Chart::ChartWnd.Refresh
  OCall xsi.UpdateStatusbar
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DbgMdiChildCht.Init
; Purpose:    Initialize the DbgMdiChildCht object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> Title string.
;             Arg3: Background RGB color value.
; Return:     Nothing.

Method DbgMdiChildCht.Init, uses xbx xdi xsi, pOwner:POINTER, pTitle:PSTRING, dBackColor:DWORD
  local cMsg[1024]:CHR

  SetObject xsi
  ACall xsi.Init, pOwner, NULL                          ;hWnd is set in WndProc
  m2m [xsi].dBackColor, dBackColor, ecx
  m2m [xsi].dZoomFactor, $ObjTmpl(Application).dTxtZoomFactor, eax
  mov xdi, pOwner
  invoke CreateMDIWindow, offset szDbgMdiChildChtClass, pTitle, \
             0, CW_USEDEFAULT, CW_USEDEFAULT, \
             CW_USEDEFAULT, CW_USEDEFAULT, [xdi].$Obj(DbgMdiClient).hWnd, hInstance, pSelf
  .if xax != 0
    ;Manage the main Menu
    inc [xdi].$Obj(DbgMdiClient).dChildCount
    mov xbx, [xdi].$Obj(DbgMdiClient).pOwner
    .if [xdi].$Obj(DbgMdiClient).dChildCount == 1       ;First child window ?
      invoke SendMessage, [xbx].$Obj(Application).hWnd, WM_CANCELMODE, 0, 0   ;Close any opened submenu
      invoke SendMessage, [xdi].$Obj(DbgMdiClient).hWnd, WM_MDISETMENU, \
                          [xbx].$Obj(Application).hMenuChild, [xbx].$Obj(Application).hMenuChildWnd
      OCall xbx::Application.EnableActions, TRUE
      invoke DrawMenuBar, [xbx].$Obj(MdiApp).hWnd       ;Redraw the new menu bar
      OCall xbx::Application.ManageOptions, DBG_MDI_CHILD_CHT_ID
    .endif

    ;Install Magnetism
    mov [xsi].pMagnetism, $New(Magnetism)
    OCall [xsi].pMagnetism::Magnetism.Init, xsi, [xsi].hWnd, 10

    invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL
  .else
    mov edx, $ObjTmpl(Application).dLanguage
    add edx, 125
    invoke LoadString, hInstance, edx, addr cMsg, lengthof cMsg - 1
    invoke MessageBox, [xbx].$Obj(Application).hWnd, addr cMsg, offset szError, \
                       MB_OK or MB_ICONERROR
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DbgMdiChildTxt.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

$CFloat macro Value
  if type CHT_FLOAT eq 4
    exitm $CReal4(Value)
  else
    exitm $CReal8(Value)
  endif
endm

Method DbgMdiChildCht.OnCreate, uses xsi, wParam:WPARAM, lParam:LPARAM
  local dDataBuff:DWORD, ChartDef:DEF_CHART

  SetObject xsi
  mov ChartDef.xCtlID, 123456
  mov ChartDef.dStyle, WS_BORDER or WS_CHILD
  mov ChartDef.dExStyle, 0
  invoke GetClientRect, [xsi].hWnd, addr ChartDef.rect
  OCall [xsi].Chart::ChartWnd.Init, xsi, [xsi].hWnd, addr ChartDef

  BitSet [xsi].Chart.dFlags, CHT_WND_FORCE_Y1
  BitClr [xsi].Chart.ScaleY2.dFlags, CHT_SCALE_SHOW_TAB

  ;Set paddings
  mov [xsi].Chart.Padding.left, 20
  mov [xsi].Chart.Padding.top, 20
  mov [xsi].Chart.Padding.right, 20
  mov [xsi].Chart.Padding.bottom, 20

  ;Scale X axis
  s2s [xsi].Chart.ScaleX.fSetupMax, $CFloat(1.0), xax, xcx
  s2s [xsi].Chart.ScaleX.fSetupMin, $CFloat(0.0), xax, xcx
  s2s [xsi].Chart.ScaleX.fDataMax,  $CFloat(1.0), xax, xcx
  s2s [xsi].Chart.ScaleX.fDataMin,  $CFloat(0.0), xax, xcx

  mov [xsi].Chart.ScaleX.dSetupMjrDiv, 16
  mov [xsi].Chart.ScaleX.dSetupMnrDiv, 8
  mov [xsi].Chart.ScaleX.dDataMjrDiv, 16
  mov [xsi].Chart.ScaleX.dDataMnrDiv, 8

  ;Scale Y1 axis
  s2s [xsi].Chart.ScaleY1.fSetupMax, $CFloat(1.0), xax, xcx
  s2s [xsi].Chart.ScaleY1.fSetupMin, $CFloat(-1.0), xax, xcx
  s2s [xsi].Chart.ScaleY1.fDataMax,  $CFloat(1.0), xax, xcx
  s2s [xsi].Chart.ScaleY1.fDataMin,  $CFloat(-1.0), xax, xcx

  mov [xsi].Chart.ScaleY1.dSetupMjrDiv, 2
  mov [xsi].Chart.ScaleY1.dSetupMnrDiv, 1
  mov [xsi].Chart.ScaleY1.dDataMjrDiv, 2
  mov [xsi].Chart.ScaleY1.dDataMnrDiv, 1

  xor eax, eax
MethodEnd
; --------------------------------------------------------------------------------------------------
; Method:     DbgMdiChildCht.OnEraseBkgnd
; Purpose:    Event procedure for WM_ERASEBKGND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DbgMdiChildCht.OnEraseBkgnd,, wParam:WPARAM, lParam:LPARAM
  xor eax, eax
  inc eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DbgMdiChildCht.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DbgMdiChildCht.OnPaint, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, dWidth:DWORD, dHeight:DWORD, Rct:RECT
  local ScrollInfo:SCROLLINFO, DstRect:RECT, hBrush:HANDLE

  SetObject xsi
  invoke BeginPaint, [xsi].hWnd, addr PS
  invoke GetClientRect, [xsi].hWnd, addr Rct

  invoke EndPaint, [xsi].hWnd, addr PS
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DbgMdiChildCht.OnHScroll
; Purpose:    Event procedure for WM_HSCROLL message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DbgMdiChildCht.OnHScroll, uses xsi, wParam:WPARAM, lParam:LPARAM
  local ScrollInfo:SCROLLINFO

  SetObject xsi
  mov xax, wParam
  .if ax == SB_THUMBPOSITION || ax == SB_THUMBTRACK
    shr eax, 16
    mov [xsi].dHorzOffset, eax

  .elseif ax == SB_LINELEFT
    mov edx, [xsi].dZoomFactor
    shr edx, 6
    sub [xsi].dHorzOffset, edx
    .if SDWORD ptr [xsi].dHorzOffset < 0
      m2z [xsi].dHorzOffset
    .endif

  .else
    mov ScrollInfo.cbSize, sizeof(ScrollInfo)
    mov ScrollInfo.fMask, SIF_RANGE or SIF_PAGE
    invoke GetScrollInfo, [xsi].hWnd, SB_HORZ, addr ScrollInfo

    mov xax, wParam
    .if ax == SB_LINERIGHT
      mov eax, [xsi].dZoomFactor
      shr eax, 6
      add eax, [xsi].dHorzOffset
      mov edx, ScrollInfo.nMax
      sub edx, ScrollInfo.nPage
      inc edx
      .if eax > edx
        mov eax, edx
      .endif
      mov [xsi].dHorzOffset, eax

    .elseif ax == SB_PAGERIGHT
      mov eax, [xsi].dHorzOffset
      add eax, ScrollInfo.nPage
      mov edx, ScrollInfo.nMax
      sub edx, ScrollInfo.nPage
      inc edx
      .if eax > edx
        mov eax, edx
      .endif
      mov [xsi].dHorzOffset, eax

    .elseif ax == SB_PAGELEFT
      mov eax, ScrollInfo.nPage
      sub [xsi].dHorzOffset, eax
      .if SDWORD ptr [xsi].dHorzOffset < 0
        m2z [xsi].dHorzOffset
      .endif

    .endif
  .endif

  invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE or RDW_FRAME
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DbgMdiChildCht.OnVScroll
; Purpose:    Event procedure for WM_VSCROLL message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DbgMdiChildCht.OnVScroll, uses xsi, wParam:WPARAM, lParam:LPARAM
  local ScrollInfo:SCROLLINFO

  SetObject xsi
  mov xax, wParam
  .if ax == SB_THUMBPOSITION || ax == SB_THUMBTRACK
    shr eax, 16
    mov [xsi].dVertOffset, eax

  .elseif ax == SB_LINEUP
    mov edx, [xsi].dZoomFactor
    shr edx, 6
    sub [xsi].dVertOffset, edx
    .if SDWORD ptr [xsi].dVertOffset < 0
      m2z [xsi].dVertOffset
    .endif

  .else
    mov ScrollInfo.cbSize, sizeof(ScrollInfo)
    mov ScrollInfo.fMask, SIF_RANGE or SIF_PAGE
    invoke GetScrollInfo, [xsi].hWnd, SB_VERT, addr ScrollInfo

    mov xax, wParam
    .if ax == SB_LINEDOWN
      mov eax, [xsi].dZoomFactor
      shr eax, 6
      add eax, [xsi].dVertOffset
      mov edx, ScrollInfo.nMax
      sub edx, ScrollInfo.nPage
      inc edx
      .if eax > edx
        mov eax, edx
      .endif
      mov [xsi].dVertOffset, eax

    .elseif ax == SB_PAGEDOWN
      mov eax, [xsi].dVertOffset
      add eax, ScrollInfo.nPage
      mov edx, ScrollInfo.nMax
      sub edx, ScrollInfo.nPage
      inc edx
      .if eax > edx
        mov eax, edx
      .endif
      mov [xsi].dVertOffset, eax

    .elseif ax == SB_PAGEUP
      mov eax, ScrollInfo.nPage
      sub [xsi].dVertOffset, eax
      .if SDWORD ptr [xsi].dVertOffset < 0
        m2z [xsi].dVertOffset
      .endif

    .endif
  .endif

  invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE or RDW_FRAME
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DbgMdiChildCht.OnRButtonDown
; Purpose:    Event procedure for WM_RBUTTONDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method DbgMdiChildCht.OnRButtonDown,, wParam:WPARAM, lParam:LPARAM
  SetObject xax
  mov xcx, [xax].pOwner                                 ;xcx -> DbgMdiClient
  invoke SendMessage, [xcx].$Obj(DbgMdiClient).hWnd, WM_MDIACTIVATE, \
                      [xax].$Obj(DbgMdiChildCht).hWnd, 0
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DbgMdiChildCht.OnRButtonUp
; Purpose:    Event procedure for WM_RBUTTONUP message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method DbgMdiChildCht.OnRButtonUp,, wParam:WPARAM, lParam:LPARAM
  local Pnt:POINT

  invoke GetCursorPos, addr Pnt
  invoke GetSubMenu, $ObjTmpl(Application).hMenuContext, 0
  invoke TrackPopupMenu, xax, TPM_LEFTALIGN, Pnt.x, Pnt.y, 0, $ObjTmpl(Application).hWnd, NULL
  invoke PostMessage, $ObjTmpl(Application).hWnd, WM_NULL, 0, 0
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DbgMdiChildCht.OnMouseWheel
; Purpose:    Event procedure for WM_MOUSEWHEEL message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DbgMdiChildCht.OnMouseWheel, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  ;DbgText "DbgMdiChildCht.OnMouseWheel"
  invoke SendMessage, [xsi].Chart.hWnd, WM_MOUSEWHEEL, wParam, lParam
  xor eax, eax
MethodEnd


; --------------------------------------------------------------------------------------------------
; Method:     DbgMdiChildCht.OnKeyDown
; Purpose:    Event procedure for WM_KEYDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if processed.

Method DbgMdiChildCht.OnKeyDown,, wParam:WPARAM, lParam:LPARAM
  invoke GetAsyncKeyState, VK_SHIFT
  test eax, eax
  mov xax, wParam
  .if ZERO?
    .if eax == VK_PRIOR
      OCall pSelf.OnVScroll, SB_PAGEUP, 0
      jmp @F
    .endif
    .if eax == VK_NEXT
      OCall pSelf.OnVScroll, SB_PAGEDOWN, 0
      jmp @F
    .endif
  .else
    .if eax == VK_PRIOR
      OCall pSelf.OnHScroll, SB_PAGEUP, 0
      jmp @F
    .endif
    .if eax == VK_NEXT
      OCall pSelf.OnHScroll, SB_PAGEDOWN, 0
      jmp @F
    .endif
  .endif
  .if eax == VK_UP
    OCall pSelf.OnVScroll, SB_LINEUP, 0
  .elseif eax == VK_DOWN
    OCall pSelf.OnVScroll, SB_LINEDOWN, 0
  .elseif eax == VK_LEFT
    OCall pSelf.OnHScroll, SB_LINEUP, 0
  .elseif eax == VK_RIGHT
    OCall pSelf.OnHScroll, SB_LINEDOWN, 0
  .endif
@@:
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DbgMdiChildCht.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DbgMdiChildCht.OnSize, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  ;DbgText "DbgMdiChildCht.OnSize"
  ACall xsi.OnSize, wParam, lParam
  .if wParam != SIZE_MINIMIZED
    LoWord lParam, xax
    HiWord lParam, xbx
    invoke MoveWindow, [xsi].Chart.hWnd, 0, 0, eax, ebx, TRUE
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DbgMdiChildCht.Open
; Purpose:    Load the content of a txt file.
; Arguments:  Arg1: -> Filename.
; Return:     Nothing.

Method DbgMdiChildCht.Open, uses xbx xdi xsi, pFileName:PSTRING
  SetObject xsi
  OCall xsi.ClpBrdSetBtns
;  ACall xsi.Open, pFileName                             ;Remenber this file name
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DbgMdiChildCht.Print
; Purpose:    Print the content of a BmpChild.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildCht.Print, uses xbx xdi xsi
;  local PrtDlg:PRINTDLG, DocInfo:DOCINFO, cMsg[1024]:CHR
;  local LogPix:POINT, Pagrsize:POINT, PageOffset:POINT, PrintSize:POINT
;
;  SetObject xsi
;
;  mov PrtDlg.lStructSize, sizeof(PrtDlg)
;  m2m PrtDlg.hwndOwner, [xsi].hWnd, xax
;  mov xdx, [xsi].pOwner
;  mov xbx, [xdx].$Obj(DbgMdiClient).pOwner
;  m2m PrtDlg.hDevMode, [xbx].$Obj(Application).hDevMode, xax
;  m2m PrtDlg.hDevNames, [xbx].$Obj(Application).hDevNames, xcx
;  m2z PrtDlg.hDC
;  mov PrtDlg.Flags, PD_NOSELECTION or PD_RETURNDC
;  m2z PrtDlg.nFromPage
;  m2z PrtDlg.nToPage
;  m2z PrtDlg.nMinPage
;  m2z PrtDlg.nMaxPage
;  mov PrtDlg.nCopies, 1
;  m2m PrtDlg.hInstance, hInstance, xax
;  m2z PrtDlg.lCustData
;  m2z PrtDlg.lpfnPrintHook
;  m2z PrtDlg.lpfnSetupHook
;  m2z PrtDlg.lpPrintTemplateName
;  m2z PrtDlg.lpSetupTemplateName
;  m2z PrtDlg.hPrintTemplate
;  m2z PrtDlg.hSetupTemplate
;
;  .if $invoke(PrintDlg, addr PrtDlg)
;    m2m [xbx].$Obj(Application).hDevMode, PrtDlg.hDevMode, xax
;    m2m [xbx].$Obj(Application).hDevNames, PrtDlg.hDevNames, xcx
;    .ifBitSet $invoke(GetDeviceCaps, PrtDlg.hDC, RASTERCAPS), RC_BITBLT
;      mov DocInfo.cbSize, sizeof(DocInfo)
;      m2m DocInfo.lpszDocName, offset szDebugCenter, xax
;      m2z DocInfo.lpszOutput
;      m2z DocInfo.lpszDatatype
;      m2z DocInfo.fwType
;
;      mov Pagrsize.x, $32($invoke(GetDeviceCaps, PrtDlg.hDC, PHYSICALWIDTH))
;      mov Pagrsize.y, $32($invoke(GetDeviceCaps, PrtDlg.hDC, PHYSICALHEIGHT))
;      mov PageOffset.x, $32($invoke(GetDeviceCaps, PrtDlg.hDC, PHYSICALOFFSETX))
;      mov PageOffset.y, $32($invoke(GetDeviceCaps, PrtDlg.hDC, PHYSICALOFFSETY))
;      mov LogPix.x, $32($invoke(GetDeviceCaps, PrtDlg.hDC, LOGPIXELSX))
;      mov LogPix.y, $32($invoke(GetDeviceCaps, PrtDlg.hDC, LOGPIXELSY))
;
;      ;Set paper margins using the Viewport
;      invoke SetMapMode, PrtDlg.hDC, MM_ISOTROPIC
;      invoke MulDiv, [xbx].$Obj(Application).PrintMargin.left, LogPix.x, 2540
;      sub eax, PageOffset.x
;      mov edi, eax
;      invoke MulDiv, [xbx].$Obj(Application).PrintMargin.top, LogPix.y, 2540
;      sub eax, PageOffset.y
;      invoke SetViewportOrgEx, PrtDlg.hDC, edi, eax, NULL
;
;      mov eax, [xbx].$Obj(Application).PrintMargin.left
;      add eax, [xbx].$Obj(Application).PrintMargin.right
;      invoke MulDiv, eax, LogPix.x, -2540
;      add eax, Pagrsize.x
;      mov PrintSize.x, eax
;      mov eax, [xbx].$Obj(Application).PrintMargin.top
;      add eax, [xbx].$Obj(Application).PrintMargin.bottom
;      invoke MulDiv, eax, LogPix.y, -2540
;      add eax, Pagrsize.y
;      mov PrintSize.y, eax
;      invoke SetWindowExtEx, PrtDlg.hDC, PrintSize.x, PrintSize.y, NULL
;      invoke SetViewportExtEx, PrtDlg.hDC, PrintSize.x, PrintSize.y, NULL
;      invoke CreateRectRgn, 0, 0, PrintSize.x, PrintSize.y
;      mov xbx, xax
;      invoke SelectClipRgn, PrtDlg.hDC, xbx
;      invoke DeleteObject, xbx
;
;      invoke StartDoc, PrtDlg.hDC, addr DocInfo
;      invoke StartPage, PrtDlg.hDC
;      mov xbx, [xsi].pBmp
;
;      invoke StretchDIBits, PrtDlg.hDC, \
;                   0, 0, [xbx].BITMAPINFO.bmiHeader.biWidth, [xbx].BITMAPINFO.bmiHeader.biHeight, \
;                   0, 0, [xbx].BITMAPINFO.bmiHeader.biWidth, [xbx].BITMAPINFO.bmiHeader.biHeight, \
;                   addr [xbx].BITMAPINFO.bmiColors, xbx, DIB_RGB_COLORS, SRCCOPY
;
;      invoke EndPage, PrtDlg.hDC
;      invoke EndDoc, PrtDlg.hDC
;      invoke DeleteDC, PrtDlg.hDC
;    .else
;      mov edx, $ObjTmpl(Application).dLanguage
;      add edx, 124
;      invoke LoadString, hInstance, edx, addr cMsg, lengthof cMsg - 1
;      invoke MessageBox, [xsi].hWnd, addr cMsg, offset szDebugCenter, MB_OK or MB_ICONERROR
;    .endif
;  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DbgMdiChildCht.SaveAs
; Purpose:    Save the content of the RichEdit control to a specified file.
; Arguments:  Arg1: Dummy value 1.
;             Arg2: Dummy value 2.
; Return:     Nothing.

Method DbgMdiChildCht.SaveAs,, pDummy1:PSTRING, pDummy2:PSTRING
;  ACall SaveAs, offset szBmpFilter, offset szChtExt
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DbgMdiChildCht.SaveTo
; Purpose:    Save the content of the RichEdit control to a specified file.
; Arguments:  Arg1: -> File path and name.
; Return:     Nothing.

Method DbgMdiChildCht.SaveTo, uses xsi, pFileName:PSTRING
  local pStream:$ObjPtr(Stream), dSize:DWORD

  SetObject xsi
;  mov pStream, $New(DiskStream)
;  OCall pStream::DiskStream.Init, xsi, pFileName, 0, 0, NULL, 0, 0, 0
;  OCall pStream::DiskStream.BinWrite, addr BMFH, sizeof()
;  OCall pStream::DiskStream.BinWrite, [xsi].pBmp, dSize
;  Destroy pStream
;  ACall xsi.SaveTo, pFileName                           ;Save FileName
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DbgMdiChildCht.Startup
; Purpose:    Register the object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildCht.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof(WNDCLASSEX)
  mov WC.style, CS_HREDRAW or CS_VREDRAW or CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT
  m2m WC.lpfnWndProc, $MethodAddr(DbgMdiChildCht.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  m2z WC.hbrBackground
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szDbgMdiChildChtClass, xax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP_CHILD_CHT"))
  m2z WC.hIconSm
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)

  invoke RegisterClassEx, addr WC
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DbgMdiChildCht.UpdateStatusbar
; Purpose:    Draw new information on the Statusbar.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildCht.UpdateStatusbar, uses xbx xdi xsi
  local cTextBuffer[1024]:CHR, wResText[1024]:CHR, dWidth:DWORD, dHeight:DWORD

;  DbgText "DbgMdiChildCht.UpdateStatusbar"
  SetObject xsi
  mov xcx, [xsi].pOwner
  mov xbx, [xcx].$Obj(DbgMdiClient).pOwner
  .if [xsi].Chart.Data.dCount != 0
    lea xdi, cTextBuffer
    mov edx, [xbx].$Obj(Application).dLanguage
    add edx, 160                                      ;"Data points"
    invoke LoadStringW, hInstance, edx, addr wResText, lengthof wResText
    WriteF xdi, "¦SU: ", addr wResText
    .ColForEach [xsi].Chart.Data
      WriteF xdi, "¦UD, ", [xax].$Obj(ChartXYSeries).dDataCount
    .ColNext
    mov CHR ptr [xdi - 2*sizeof(CHR)], 0
    OCall [xbx].$Obj(Application).pStatusbar::Statusbar.SetPartText, 1, addr cTextBuffer, SBT_SUNKEN
  .else
    OCall [xbx].$Obj(Application).pStatusbar::Statusbar.SetPartText, 1, NULL, SBT_SUNKEN
  .endif
  OCall [xbx].$Obj(Application).pStatusbar::Statusbar.SetPartText, 2, NULL, SBT_SUNKEN
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DbgMdiChildCht.ZoomIn
; Purpose:    Increase the output size.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildCht.ZoomIn, uses xsi
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DbgMdiChildCht.ZoomOut
; Purpose:    Decrease the output size.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildCht.ZoomOut, uses xsi
MethodEnd
