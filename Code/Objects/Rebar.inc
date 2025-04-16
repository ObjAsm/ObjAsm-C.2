; ==================================================================================================
; Title:      Rebar.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of Rebar controls based on common controls Version 5.81.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


PNMREBARCHEVRON typedef ptr NMREBARCHEVRON

; --------------------------------------------------------------------------------------------------
; Object:     RbIptor
; Purpose:    Implement message interceptor used internally by the Rebar object.

Object RbIptor, RbIptorID, MsgInterceptor
  RedefineMethod    WndProc,            DWORD, WPARAM, LPARAM

  VirtualEvent      OnParentNotify,     WM_PARENTNOTIFY
  VirtualEvent      OnNotify,           WM_NOTIFY

  DefineVariable    dChevronPressed,    DWORD,      FALSE

ObjectEnd

; --------------------------------------------------------------------------------------------------
; Object:     Rebar
; Purpose:    Implement a thin wrapper around the ReBarWindow32 GDI control.
;             The Rebar object uses internally 2 other objects: RbIptor, derived from MsgInterceptor
;             and BandFrame, derived from WinControl.
;             The first object is responsible to intercept notification messages sent to the parent
;             of the Rebar control while the second provides a Window frame when the toolbar
;             contained in the Rebar control is detached, dragging it away from the Rebar control.

Object Rebar, RebarID, WinControl                             ;Class "ReBarWindow32"
  DynamicMethod     ChevronMenu,        PNMREBARCHEVRON       ;-> NMREBARCHEVRON
  RedefineMethod    Done
  VirtualMethod     GetBandIndex,       HWND                  ;Child window handle
  RedefineMethod    Init,               POINTER, HWND         ;-> Owner, hParent
  VirtualMethod     InsertBand,         HWND, DWORD, DWORD
  VirtualMethod     RemoveBand,         DWORD
  RedefineMethod    WndProc,            DWORD, WPARAM, LPARAM

  VirtualEvent      OnMouseMove,        WM_MOUSEMOVE

  DefineVariable    hDraggedBandWnd,    HWND,       0         ;Temp var: handle of dragged band Wnd
  DefineVariable    hCursorSize,        HCURSOR,    0
  DefineVariable    hCursorArrow,       HCURSOR,    0
  DefineVariable    hParent,            HWND,       0
  DefineVariable    pMsgIptor,          $ObjPtr(RbIptor),  NULL
ObjectEnd

; --------------------------------------------------------------------------------------------------
; Object:     BandFrame
; Purpose:    Provide a Window frame when the toolbar contained in the Rebar control is detached,
;             dragging it away from the Rebar control.

Object BandFrame, BandFrameID, WinPrimer
  RedefineMethod    Init,               POINTER, HWND, POINTER, HWND, DWORD, DWORD
  VirtualMethod     WndProc,            DWORD, WPARAM, LPARAM
  StaticMethod      Startup

  VirtualEvent      OnNCLButtonDown,    WM_NCLBUTTONDOWN
  VirtualEvent      OnLButtonUp,        WM_LBUTTONUP, WM_NCLBUTTONUP
  VirtualEvent      OnMouseMove,        WM_MOUSEMOVE
  VirtualEvent      OnDestroy,          WM_DESTROY

  DefineVariable    dIsMoving,          DWORD,      FALSE
  DefineVariable    pSrcRebar,          HWND,       0
  DefineVariable    hChildWnd,          HWND,       0
  DefineVariable    ChildSize,          POINT,      {}
  DefineVariable    StartMovingPnt,     POINT,      {}
ObjectEnd


; ==================================================================================================

if IMPLEMENT

RB_DOCKINGBORDER    equ     10
RB_GRIPPERWIDTH     equ     09
RB_CHEVRONWIDTH     equ     15
RB_CHEVRONGAP       equ     04      ;Gap between the last button anf the start of the Chevron button
RB_BORDERWIDTH      equ     05


CStr szRbMsgIptorProp, "OAP_RbMsgIptor"
CStr szBandFrameClass, "OAC_BandFrame"

; --------------------------------------------------------------------------------------------------
; Method:     Rebar.ChevronMenu
; Purpose:    Draw a popup menu with the hidden toolbar buttons. XMenu must be active!
; Arguments:  Arg1: -> NMREBARCHEVRON.
; Return:     Nothing.
; Note:       This method must be overwritten to provide other functionality, like support for
;             other embedded controls different from a toolbar.

Method Rebar.ChevronMenu, uses xbx xdi xsi, pNMREBARCHEVRON:PNMREBARCHEVRON
  local BandRect:RECT, dButtonCnt:DWORD, dButtonIdx:DWORD, sdTotalLenght:SDWORD
  local cBuffer[256]:CHR, cButtonText[256]:CHR, cMenuText[256]:CHR
  local tbbi:TBBUTTONINFO, rbi:REBARBANDINFO
  local dMenuItemState:DWORD, BtnRct:RECT, dMenuItemCnt:DWORD

;  DbgText "Rebar.ChevronMenu"
  SetObject xsi
  mov xbx, pNMREBARCHEVRON
  invoke SendMessage, [xsi].hWnd, RB_GETRECT, [xbx].NMREBARCHEVRON.uBand, addr BandRect
  m2m sdTotalLenght, BandRect.right, eax
  mov eax, BandRect.left
  sub sdTotalLenght, eax
  sub sdTotalLenght, RB_GRIPPERWIDTH + RB_CHEVRONWIDTH + RB_CHEVRONGAP
  sub BandRect.right, RB_CHEVRONWIDTH
  invoke ClientToScreen, [xsi].hWnd, addr BandRect.right

  mov rbi.cbSize, sizeof(REBARBANDINFO)
  mov rbi.fMask, RBBIM_CHILD
  invoke SendMessage, [xsi].hWnd, RB_GETBANDINFO, [xbx].NMREBARCHEVRON.uBand, addr rbi
  invoke GetClassName, rbi.hwndChild, addr cBuffer, lengthof cBuffer
  invoke StrIComp, addr cBuffer, $OfsCStr("ToolbarWindow32")
  .if eax == 0                                        ;It is a toolbar!
    invoke SendMessage, rbi.REBARBANDINFO.hwndChild, TB_BUTTONCOUNT, 0, 0
    mov dButtonCnt, eax
    invoke CreatePopupMenu
    mov edi, eax
    mov tbbi.cbSize, sizeof(TBBUTTONINFO)
    mov tbbi.dwMask, TBIF_IMAGE or TBIF_STATE or TBIF_TEXT or TBIF_BYINDEX or \
                     TBIF_COMMAND or TBIF_SIZE or TBIF_STYLE
    lea xax, cButtonText
    mov tbbi.pszText, xax
    mov tbbi.cchText, lengthof cButtonText
    xor ebx, ebx
    mov dMenuItemCnt, ebx
    .while ebx < dButtonCnt
      mov dButtonIdx, ebx
      mov xax, tbbi.pszText
      m2z CHR ptr [xax]
      invoke SendMessage, rbi.hwndChild, TB_GETBUTTONINFO, dButtonIdx, addr tbbi
      .ifBitClr tbbi.fsState, TBSTATE_HIDDEN
        mov dMenuItemState, MF_STRING
        invoke SendMessage, rbi.hwndChild, TB_GETRECT, tbbi.idCommand, addr BtnRct
        mov eax, BtnRct.right
        .if eax >= sdTotalLenght
          lea xbx, cMenuText
          .ifBitSet tbbi.fsStyle, BTNS_SEP
            cmp dMenuItemCnt, 0                         ;Skip if first Menu Item
            je @F                                       ;   is a separator
            mov DCHR ptr [xbx], MENU_CHAR_SEPARATOR
          .elseIfBitSet tbbi.fsStyle, BTNS_CHECKGROUP   ;if any of these 2 bits are set
            .ifBitSet tbbi.fsStyle, BTNS_GROUP
              mov DCHR ptr [xbx], MENU_CHAR_RADIO
            .else
              mov DCHR ptr [xbx], MENU_CHAR_CHECK
            .endif
          .else
            invoke dword2dec, xbx, tbbi.iImage
          .endif
          invoke StrCatChar, xbx, MENU_CHAR_LITERAL
          invoke StrCCat, xbx, tbbi.pszText, lengthof cMenuText - 1
          .ifBitClr tbbi.fsState, TBSTATE_ENABLED
            or dMenuItemState, MF_GRAYED
          .endif
          .ifBitSet tbbi.fsState, TBSTATE_CHECKED
            or dMenuItemState, MF_CHECKED
          .endif
          invoke AppendMenu, xdi, dMenuItemState, tbbi.idCommand, xbx
          inc dMenuItemCnt
        .endif
      .endif
    @@:
      mov ebx, dButtonIdx
      inc ebx
    .endw
    invoke TrackPopupMenu, xdi, TPM_LEFTALIGN or TPM_LEFTBUTTON, \
                           BandRect.right, BandRect.bottom, \
                           0, [xsi].hParent, NULL
    invoke DestroyMenu, xdi
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Rebar.Done
; Purpose:    Finalize the Rebar object, freeing allocated resources.
; Arguments:  None.
; Return:     Nothing.

Method Rebar.Done, uses xsi
  SetObject xsi
  Unsubclass Rebar                                      ;Uses xsi
  Destroy [xsi].pMsgIptor
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Rebar.GetBandIndex
; Purpose:    Get the band number of a specified hWnd.
; Arguments:  Arg1: Band window handle.
; Return:     eax = Band index. -1 if not found.

Method Rebar.GetBandIndex, uses xbx xsi, hBandWnd:HWND
  local RbInfo:REBARBANDINFO

;  DbgText "Rebar.GetBandIndex"
  SetObject xsi
  invoke SendMessage, [xsi].hWnd, RB_GETBANDCOUNT, NULL, NULL
  mov ebx, eax

  mov RbInfo.cbSize, sizeof(REBARBANDINFO)
  mov RbInfo.fMask, RBBIM_CHILD
  .while ebx
    dec ebx
    invoke SendMessage, [xsi].hWnd, RB_GETBANDINFO, ebx, addr RbInfo
    mov xax, RbInfo.hwndChild
    .if xax == hBandWnd
      mov eax, ebx                                      ;Return window index
      ExitMethod
    .endif
  .endw
  mov eax, -1                                           ;No window found => return -1
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Rebar.Init
; Purpose:    Initialize the Rebar object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
; Return:     Nothing.

Method Rebar.Init, uses xsi, pOwner:POINTER, hParent:HWND
  local Rct:RECT

;  DbgText "Rebar.Init"
  SetObject xsi
  m2m [xsi].hParent, hParent, xax
  mov [xsi].hCursorSize, $invoke(LoadCursor, 0, IDC_SIZEWE)   ;Temporary cursor.
  mov [xsi].hCursorArrow, $invoke(LoadCursor, 0, IDC_ARROW)

  invoke GetClientRect, hParent, addr Rct

  WndStyle equ WS_VISIBLE or WS_BORDER or WS_CHILD or WS_CLIPCHILDREN or \
               WS_CLIPSIBLINGS or CCS_NODIVIDER or CCS_NOPARENTALIGN  or \
               RBS_VARHEIGHT or RBS_BANDBORDERS or RBS_DBLCLKTOGGLE; or CCS_VERT

  invoke CreateWindowEx, NULL, $OfsCStr("ReBarWindow32"), NULL, WndStyle, \
                         0, 0, Rct.right, 20, hParent, NULL, hInstance, NULL
  ACall xsi.Init, pOwner, xax
  Subclass Rebar                                        ;Uses xsi

  ;Create MsgInterceptor of parent window to catch the WM_NOTIFY message
  mov [xsi].pMsgIptor, $New(RbIptor)
  OCall xax::RbIptor.Init, xsi, hParent, offset szRbMsgIptorProp
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Rebar.InsertBand
; Purpose:    Insert a child band in the Rebar.
; Arguments:  Arg1: Inserted Child Window handle.
;             Arg2: Width of the inserted child window (pixels).
;             Arg3: Height of the inserted child window (pixels).
; Return:     Nothing.

Method Rebar.InsertBand, uses xsi, hChild:HWND, dChildWidth:DWORD, dChildHeight:DWORD
  local RbInfo:REBARBANDINFO

;  DbgText "Rebar.InsertBand"
  SetObject xsi
  mov RbInfo.cbSize, sizeof(REBARBANDINFO)
  mov RbInfo.fMask, RBBIM_STYLE or RBBIM_IDEALSIZE or RBBIM_SIZE or \
                    RBBIM_CHILD or RBBIM_CHILDSIZE or RBBIM_LPARAM
  mov RbInfo.fStyle, RBBS_CHILDEDGE or RBBS_GRIPPERALWAYS or RBBS_USECHEVRON
  m2m RbInfo.hwndChild, hChild, xdx

  mov eax, dChildWidth
  mov RbInfo.lParam, xax                                ;Store child width here
  add eax, RB_GRIPPERWIDTH + RB_BORDERWIDTH + 2
  mov RbInfo.cx_, eax                                   ;Complete bandwidth
  m2z RbInfo.cxMinChild
  sub eax, RB_CHEVRONWIDTH + 1
  mov RbInfo.cxIdeal, eax
  m2m RbInfo.cyChild, dChildHeight, edx
  mov RbInfo.cyMaxChild, 0FFFFFFFFh                     ;No limit
  m2m RbInfo.cyMinChild, dChildHeight, edx              ;Store child height here
  invoke SendMessage, [xsi].hWnd, RB_INSERTBAND, 0, addr RbInfo
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Rebar.OnMouseMove
; Purpose:    Event procedure for WM_MOUSEMOVE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Rebar.OnMouseMove, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local ClientRect:RECT, Pnt:POINT
  local pBandFrame:$ObjPtr(BandFrame), RbInfo:REBARBANDINFO
  local pCaption:PSTRING, cTextGetRbI[1024]:CHR, TotSize:SIZE_

;  DbgText "Rebar.OnMouseMove"
  SetObject xsi
  invoke CallWindowProc, [xsi].pPrevWndProc, [xsi].hWnd, WM_MOUSEMOVE, wParam, lParam
  invoke GetCapture
  .if (xax == [xsi].hWnd) && ([xsi].hDraggedBandWnd != 0)
    PntS2Pnt Pnt, lParam
    invoke GetClientRect, [xsi].hWnd, addr ClientRect
    add ClientRect.bottom, 10
    invoke PtInRect, addr ClientRect, Pnt
    .if eax == FALSE
      ;At this point we want to detach the Toolbar from the Rebar
      mov RbInfo.cbSize, sizeof(REBARBANDINFO)
      mov RbInfo.fMask, RBBIM_CHILDSIZE or RBBIM_LPARAM or RBBIM_SIZE or \
                        RBBIM_CHILD or RBBIM_IDEALSIZE
      mov RbInfo.cch, lengthof cTextGetRbI
      lea xax, cTextGetRbI
      mov RbInfo.lpText, xax
      OCall xsi.GetBandIndex, [xsi].hDraggedBandWnd
      mov ebx, eax
      invoke SendMessage, [xsi].hWnd, RB_GETBANDINFO, ebx, addr RbInfo
      OCall xsi.RemoveBand, ebx

      invoke ReleaseCapture

      mov pBandFrame, $New(BandFrame)

      invoke SendMessage, RbInfo.hwndChild, TB_GETMAXSIZE, 0, addr TotSize
      invoke GetParent, [xsi].hWnd
      dec TotSize.cy
      OCall pBandFrame::BandFrame.Init, xsi, xax, xsi, RbInfo.hwndChild, \
                                        TotSize.cx_, TotSize.cy
      mov xax, pBandFrame
      mov xbx, [xax].$Obj(BandFrame).hWnd

      invoke SetParent, RbInfo.hwndChild, xbx
      invoke ShowWindow, RbInfo.hwndChild, SW_SHOW
      invoke SetFocus, xbx
      invoke GetWindowTextLength, RbInfo.hwndChild
      lea xdi, [sizeof(CHR)*xax + sizeof(CHR)]      ;max. number of chars, including the ZTC + 20h
      MemAlloc xdi
      mov pCaption, xax
      invoke GetWindowText, RbInfo.hwndChild, xax, edi
      invoke SetWindowText, xbx, pCaption
      MemFree pCaption

      invoke SetWindowPos, RbInfo.hwndChild, HWND_TOP, 0, 0, 0, 0, SWP_NOSIZE

      invoke SetCursor, [xsi].hCursorArrow
      invoke GetCursorPos, addr Pnt
      Pnt2Reg32 eax, Pnt

      ;Fire ToolWnd dragging
      invoke PostMessage, xbx, WM_NCLBUTTONDOWN, HTCAPTION, eax
      invoke ShowWindow, xbx, SW_SHOW

    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Rebar.RemoveBand
; Purpose:    Remove a child object in the Rebar.
; Arguments:  Arg1: HANDLE of the object (WinControl) to remove.
; Return:     Nothing.

Method Rebar.RemoveBand, uses xsi, dBandIndex:DWORD
;  DbgText "Rebar.RemoveBand"
  SetObject xsi
  invoke SendMessage, [xsi].hWnd, RB_SHOWBAND, dBandIndex, FALSE
  invoke SendMessage, [xsi].hWnd, RB_DELETEBAND, dBandIndex, NULL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Rebar.WndProc
; Purpose:    Processing of window messages. Before invoking it, the window must be subclassed.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.
; Note:       Window handle is passed in pSelf (hidden parameter).

Method Rebar.WndProc,, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg,, "Rebar"
  GetSubclassingInst Rebar, pSelf
  OCall xax::Rebar.Dispatch, pSelf, uMsg, wParam, lParam
MethodEnd



; ==================================================================================================
;    RbIptor implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     RbIptor.OnParentNotify
; Purpose:    Event procedure for WM_PARENTNOTIFY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = CallWindowProc return value.

Method RbIptor.OnParentNotify, uses xsi, wParam:WPARAM, lParam:LPARAM
  local RBHTI:RBHITTESTINFO

  SetObject xsi
  mov xax, wParam
  .if ax == WM_LBUTTONDOWN || ax == WM_RBUTTONDOWN || ax == WM_MBUTTONDOWN
    PntS2Pnt RBHTI.RBHITTESTINFO.pt, lParam
    mov xcx, [xsi].pOwner
    invoke SendMessage, [xcx].$Obj(Rebar).hWnd, RB_HITTEST, 0, addr RBHTI
    .if RBHTI.RBHITTESTINFO.iBand != -1
      .ifBitSet RBHTI.RBHITTESTINFO.flags, RBHT_CHEVRON
        mov [xsi].dChevronPressed, TRUE
      .endif
    .endif
  .endif
  invoke CallWindowProc, [xsi].pPrevWndProc, [xsi].hWnd, WM_PARENTNOTIFY, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     RbIptor.OnNotify
; Purpose:    Event procedure for WM_NOTIFY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method RbIptor.OnNotify, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local RbInfo:REBARBANDINFO, Rct:RECT

;  DbgText "RbIptor.OnNotify"
  SetObject xsi
  mov xdi, lParam
  mov xbx, [xsi].pOwner                                 ;Rebar
  mov xax, [xbx].$Obj(Rebar).hWnd

  .if xax == [xdi].NMHDR.hwndFrom
    .if [xdi].NMHDR.code == RBN_BEGINDRAG
      mov RbInfo.cbSize, sizeof(REBARBANDINFO)
      mov RbInfo.fMask, RBBIM_CHILD
      lea xax, RbInfo
      invoke SendMessage, [xbx].$Obj(Rebar).hWnd, RB_GETBANDINFO, [xdi].NMREBAR.uBand, xax
      m2m [xbx].$Obj(Rebar).hDraggedBandWnd, RbInfo.hwndChild, xdx

    .elseif [xdi].NMHDR.code == RBN_ENDDRAG
      m2z [xbx].$Obj(Rebar).hDraggedBandWnd

    .elseif [xdi].NMHDR.code == RBN_HEIGHTCHANGE
      invoke GetClientRect, [xsi].hWnd, addr Rct
      mov eax, Rct.bottom
      shl eax, 16
      or eax, Rct.right
      invoke CallWindowProc, [xsi].pPrevWndProc, [xsi].hWnd, WM_SIZE, SIZE_RESTORED, xax

    .elseif [xdi].NMHDR.code == RBN_CHEVRONPUSHED
      .if [xsi].dChevronPressed == FALSE
        OCall [xsi].pOwner::Rebar.ChevronMenu, xdi
      .endif
      m2z [xsi].dChevronPressed
    .endif

    xor eax, eax
  .else
    invoke CallWindowProc, [xsi].pPrevWndProc, [xsi].hWnd, WM_NOTIFY, wParam, lParam
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     RbIptor.WndProc
; Purpose:    Processing of window messages. Before invoking it, the window must be subclassed.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the message ID.
; Note:       Window handle is passed in pSelf (hidden parameter).

Method RbIptor.WndProc,, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg,, "RbIptor"
  invoke GetProp, pSelf, offset szRbMsgIptorProp
  ASSERT xax, "RbIptor.WndProc failed to retrieve windows property"
  OCall xax::MsgInterceptor.Dispatch, pSelf, uMsg, wParam, lParam
MethodEnd


; ==================================================================================================
;    BandFrame implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     BandFrame.Init
; Purpose:    Initialize the control.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: Source dock window handle.
;             Arg4: Child window handle.
;             Arg5: Child window width.
;             Arg6: Child window height.
; Return:     Nothing.

Method BandFrame.Init, uses xsi, pOwner:POINTER, hParent:HWND, pSrcRebar:POINTER, \
                                 hChildWnd:HWND, dWidth:DWORD, dHeight:DWORD
  local CurPos:POINT

  SetObject xsi
  m2m [xsi].ChildSize.x, dWidth, eax                    ;Save child sizes
  m2m [xsi].ChildSize.y, dHeight, ecx

  ;Move the window half caption height to the left and to the top
  invoke GetCursorPos, addr CurPos
  invoke GetSystemMetrics, SM_CYCAPTION
  shr eax, 1
  sub CurPos.x, eax
  sub CurPos.y, eax

  invoke CreateWindowEx, WS_EX_TOOLWINDOW, offset szBandFrameClass, NULL, WS_VISIBLE, \
                         CurPos.x, CurPos.y, 200, 50, hParent, 0, hInstance, xsi
  ACall xsi.Init, pOwner, xax
  invoke SetClientSize, [xsi].hWnd, dWidth, dHeight
  m2m [xsi].pSrcRebar, pSrcRebar, xax
  m2m [xsi].hChildWnd, hChildWnd, xax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     BandFrame.OnDestroy
; Purpose:    Event procedure for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method BandFrame.OnDestroy,, wParam:WPARAM, lParam:LPARAM
  Kill pSelf
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     BandFrame.OnLButtonDown
; Purpose:    Event procedure for WM_NCLBUTTONDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if not handled.

Method BandFrame.OnNCLButtonDown, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov xax, wParam
  and xax, HTCAPTION
  .if (![xsi].dIsMoving) && (xax)
    invoke SetCapture, [xsi].hWnd
    mov [xsi].dIsMoving, TRUE
    PntS2Pnt [xsi].StartMovingPnt, lParam
    invoke SetFocus, [xsi].hWnd
    mov eax, TRUE
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     BandFrame.OnLButtonUp
; Purpose:    Event procedure for WM_LBUTTONDOWN and WM_NCLBUTTONDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if not handled.

Method BandFrame.OnLButtonUp, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  .if [xsi].dIsMoving != FALSE
    invoke ReleaseCapture
    m2z [xsi].dIsMoving
    mov eax, TRUE
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     BandFrame.OnMouseMove
; Purpose:    Event procedure for WM_MOUSEMOVE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if not handled.

Method BandFrame.OnMouseMove, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local CurPnt:POINT, Rct:RECT

;  DbgText "BandFrame.OnMouseMove"
  SetObject xsi
  .if [xsi].dIsMoving != FALSE
    invoke GetCursorPos, addr CurPnt
    ;Check if should dock
    mov xbx, [xsi].pSrcRebar
    invoke GetClientRect, [xbx].$Obj(Rebar).hWnd, addr Rct
    .if Rct.bottom == 0                                 ;If no Rebar is attached to the application
      add Rct.bottom, 10                                ; then add a docking area of 10 px height
    .endif
    invoke ClientToScreen, [xbx].$Obj(Rebar).hWnd, addr Rct.left
    invoke ClientToScreen, [xbx].$Obj(Rebar).hWnd, addr Rct.right

    mov eax, CurPnt.x
    .if (SDWORD ptr eax >= Rct.left) && (SDWORD ptr eax < Rct.right)
      mov eax, CurPnt.y
      .if (SDWORD ptr eax >= Rct.top) && (SDWORD ptr eax < Rct.bottom)
        ;Dock Window ...
        m2z [xsi].dIsMoving
        invoke ReleaseCapture
        OCall xbx::Rebar.InsertBand, [xsi].hChildWnd, [xsi].ChildSize.x, [xsi].ChildSize.y
        invoke PostMessage, [xbx].$Obj(Rebar).hWnd, WM_LBUTTONDOWN, MK_LBUTTON, 0
        invoke PostMessage, [xsi].hWnd, WM_CLOSE, NULL, NULL
        mov eax, TRUE
        ret
      .endif
    .endif

    ;Draw as usual
    invoke GetWindowRect, [xsi].hWnd, addr Rct
    mov eax, Rct.left
    sub Rct.right, eax
    mov eax, Rct.top
    sub Rct.bottom, eax
    mov eax, CurPnt.x
    sub eax, [xsi].StartMovingPnt.x
    add Rct.left, eax
    mov eax, CurPnt.y
    sub eax, [xsi].StartMovingPnt.y
    add Rct.top, eax
    s2s [xsi].StartMovingPnt, CurPnt, xax, xcx
    invoke MoveWindow, [xsi].hWnd, Rct.left, Rct.top, Rct.right, Rct.bottom, TRUE
    mov eax, TRUE
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     BandFrame.Startup
; Purpose:    Register the BandFrame window class with the operating system.
; Arguments:  None.
; Return:     Nothing.

Method BandFrame.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof(WNDCLASSEX)
  m2z WC.style
  m2m WC.lpfnWndProc, $MethodAddr(BandFrame.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  mov WC.hbrBackground, COLOR_MENU + 1
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szBandFrameClass, xax
  m2z WC.hIcon
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     BandFrame.WndProc
; Purpose:    Processing of window messages. Before invoking it, the window must be subclassed.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.
; Note:       Window handle is passed in pSelf (hidden parameter).

Method BandFrame.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg,, "BandFrame Messages"
  .if uMsg == WM_NCCREATE
    mov xax, lParam
    mov xsi, [xax].CREATESTRUCT.lpCreateParams
    test xsi, xsi
    jz @@DefProc                                        ;Goto handler defined in DispatchEvent
    mrm [xsi].$Obj(WinPrimer).hWnd, pSelf, xcx          ;pSelf = hWnd
    invoke SetWindowLongPtr, xcx, GWLP_USERDATA, xsi
  .else
    invoke GetWindowLongPtr, pSelf, GWLP_USERDATA       ;If GWLP_USERDATA wasn't set,
    test xax, xax
    jz @@DefProc                                        ;Goto handler defined in DispatchEvent
    mov xsi, xax
  .endif
  DispatchEvent <DefWindowProc, pSelf>                  ;xsi -> Object Instance
MethodEnd

endif
