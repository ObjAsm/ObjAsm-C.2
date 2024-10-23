; ==================================================================================================
; Title:      DebugCenter_ChildBmp.inc
; Author:     G. Friedrich
; Version:    See DebugCenter.asm
; Purpose:    ObjAsm DebugCenter Bitmap MDI child window.
; ==================================================================================================


CStr szDbgMdiChildBmpClass, "OAC_DbgMdiChildBmp"                         ;Debug Window Child

Object DbgMdiChildBmp, DBG_MDI_CHILD_BMP_ID, DbgMdiChild
  RedefineMethod    ClpBrdClear
  RedefineMethod    ClpBrdCopy
  RedefineMethod    ClpBrdCut
  RedefineMethod    ClpBrdPaste
  RedefineMethod    ClpBrdSetBtns
  RedefineMethod    Done
  RedefineMethod    Erase
  RedefineMethod    Init,             POINTER, PSTRING, DWORD   ;-> Owner, -> Title, BackColor
  RedefineMethod    Open,             PSTRING
  RedefineMethod    Print
  RedefineMethod    SaveAs,           PSTRING, PSTRING          ;-> Filter, -> Def. extension
  RedefineMethod    SaveTo,           PSTRING
  VirtualMethod     SetBitmap,        POINTER                   ;-> BbgBmpInfo
  RedefineMethod    UpdateStatusbar
  RedefineMethod    ZoomIn
  RedefineMethod    ZoomOut
  StaticMethod      Startup

  VirtualEvent      OnEraseBkgnd,     WM_ERASEBKGND
  VirtualEvent      OnPaint,          WM_PAINT
  VirtualEvent      OnHScroll,        WM_HSCROLL
  VirtualEvent      OnVScroll,        WM_VSCROLL
  VirtualEvent      OnRButtonDown,    WM_RBUTTONDOWN
  VirtualEvent      OnRButtonUp,      WM_RBUTTONUP
  VirtualEvent      OnMouseWheel,     WM_MOUSEWHEEL
  VirtualEvent      OnKeyDown,        WM_KEYDOWN

  DefineVariable    pBmp,             POINTER,        NULL
  DefineVariable    dHorzOffset,      DWORD,          0
  DefineVariable    dVertOffset,      DWORD,          0
  DefineVariable    dBackColor,       DWORD,          DBG_COLOR_BACKGROUND_WND_LIGHT
ObjectEnd


.code
; ==================================================================================================
;    DbgMdiChildBmp implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildBmp.ClpBrdClear
; Purpose:    Delete the selection to the clipboard.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildBmp.ClpBrdClear, uses xsi
  SetObject xsi
  .if [xsi].pBmp != NULL
    MemFree [xsi].pBmp                                  ;Free data memory
    m2z [xsi].pBmp                                      ;Mark as empty!
    invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE or RDW_ERASE
  .endif
  ACall xsi.ClpBrdClear
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildBmp.ClpBrdCopy
; Purpose:    Copy the selection to the clipboard.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildBmp.ClpBrdCopy, uses xsi
  local hGlobalMem:HGLOBAL, pGlobalMem:POINTER, dMemSize:DWORD

  SetObject xsi
  .if [xsi].pBmp != NULL
    invoke OpenClipboard, [xsi].hWnd
    invoke EmptyClipboard
    mov dMemSize, $32($invoke(HeapSize, hProcessHeap, HEAP_NO_SERIALIZE, [xsi].pBmp))
    mov hGlobalMem, $invoke(GlobalAlloc, GMEM_MOVEABLE or GMEM_DISCARDABLE or GMEM_SHARE, eax)
    mov pGlobalMem, $invoke(GlobalLock, hGlobalMem)
    invoke MemClone, pGlobalMem, [xsi].pBmp, dMemSize
    invoke GlobalUnlock, hGlobalMem
    invoke SetClipboardData, CF_DIB, hGlobalMem
    invoke CloseClipboard
  .endif
  ACall xsi.ClpBrdCopy
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildBmp.ClpBrdCut
; Purpose:    Cut the selection to the clipboard.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildBmp.ClpBrdCut, uses xsi
  local hGlobalMem:HGLOBAL, pGlobalMem:POINTER, dMemSize:DWORD

  SetObject xsi
  .if [xsi].pBmp != NULL
    invoke OpenClipboard, [xsi].hWnd
    invoke EmptyClipboard
    mov dMemSize, $32($invoke(HeapSize, hProcessHeap, HEAP_NO_SERIALIZE, [xsi].pBmp))
    mov hGlobalMem, $invoke(GlobalAlloc, GMEM_MOVEABLE or GMEM_DISCARDABLE or GMEM_SHARE, eax)
    mov pGlobalMem, $invoke(GlobalLock, hGlobalMem)
    invoke MemClone, pGlobalMem, [xsi].pBmp, dMemSize
    invoke GlobalUnlock, hGlobalMem
    invoke SetClipboardData, CF_DIB, hGlobalMem
    invoke CloseClipboard
    MemFree [xsi].pBmp                                ;Free data memory
    m2z [xsi].pBmp                                    ;Mark as empty!
    invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE or RDW_ERASE
  .endif
  ACall xsi.ClpBrdCut
  OCall xsi.UpdateStatusbar
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildBmp.ClpBrdPaste
; Purpose:    Paste the selection to the clipboard.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildBmp.ClpBrdPaste, uses xsi
  local hGlobalMem:HGLOBAL, pGlobalMem:POINTER, dMemSize:DWORD

  SetObject xsi
  .if [xsi].pBmp != NULL
    MemFree [xsi].pBmp                                ;Free old memory data
  .endif
  invoke OpenClipboard, [xsi].hWnd
  mov hGlobalMem, $invoke(GetClipboardData, CF_DIB)
  mov dMemSize, $32($invoke(GlobalSize, hGlobalMem))
  mov [xsi].pBmp, $MemAlloc(dMemSize)
  mov pGlobalMem, $invoke(GlobalLock, hGlobalMem)
  invoke MemClone, [xsi].pBmp, pGlobalMem, dMemSize
  invoke GlobalUnlock, hGlobalMem
  invoke CloseClipboard
  invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE or RDW_ERASE
  ACall xsi.ClpBrdPaste
  OCall xsi.UpdateStatusbar
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildBmp.ClpBrdSetBtns
; Purpose:    Set the cut, copy & paste clipboard buttons.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildBmp.ClpBrdSetBtns, uses xbx xdi xsi
  local hMenu:HMENU, dActivate:DWORD

  SetObject xsi
  mov xcx, [xsi].pOwner
  mov xdi, [xcx].$Obj(DbgMdiClient).pOwner
  mov hMenu, $invoke(GetMenu, [xdi].$Obj(Application).hWnd) ;Get the current menu
  .if [xsi].pBmp == NULL
    mov xbx, [xdi].$Obj(Application).pToolbarEdit
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_CUT, FALSE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_COPY, FALSE
    mov xbx, hMenu
    invoke EnableMenuItem, xbx, IDM_EDIT_CUT, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xbx, IDM_EDIT_COPY, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xbx, IDM_EDIT_CLEAR, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xbx, IDM_EDIT_ERASE, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xbx, IDM_EDIT_CALC, MF_BYCOMMAND or MF_GRAYED
    mov xbx, $ObjTmpl(Application).hMenuContext
    invoke EnableMenuItem, xbx, IDM_EDIT_CUT, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xbx, IDM_EDIT_COPY, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xbx, IDM_EDIT_CLEAR, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xbx, IDM_EDIT_ERASE, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xbx, IDM_EDIT_CALC, MF_BYCOMMAND or MF_GRAYED
  .else
    mov xbx, [xdi].$Obj(Application).pToolbarEdit
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_CUT, TRUE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_COPY, TRUE
    mov xbx, hMenu
    invoke EnableMenuItem, xbx, IDM_EDIT_CUT, MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xbx, IDM_EDIT_COPY, MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xbx, IDM_EDIT_CLEAR, MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xbx, IDM_EDIT_ERASE, MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xbx, IDM_EDIT_CALC, MF_BYCOMMAND or MF_GRAYED
    mov xbx, $ObjTmpl(Application).hMenuContext
    invoke EnableMenuItem, xbx, IDM_EDIT_CUT, MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xbx, IDM_EDIT_COPY, MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xbx, IDM_EDIT_CLEAR, MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xbx, IDM_EDIT_ERASE, MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xbx, IDM_EDIT_CALC, MF_BYCOMMAND or MF_GRAYED
  .endif

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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildBmp.Done
; Purpose:    Finalize the DbgMdiChildBmp object.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildBmp.Done, uses xsi
  SetObject xsi
  .if [xsi].pBmp != NULL
    MemFree [xsi].pBmp
  .endif
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildBmp.Erase
; Purpose:    Erase the content of the window.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildBmp.Erase
  OCall ClpBrdClear
  OCall UpdateStatusbar
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildBmp.Init
; Purpose:    Initialize the DbgMdiChildBmp object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> Title string.
;             Arg3: Background RGB color value.
; Return:     Nothing.

Method DbgMdiChildBmp.Init, uses xbx xdi xsi, pOwner:POINTER, pTitle:PSTRING, dBackColor:DWORD
  local cMsg[1024]:CHR

  SetObject xsi
  ACall xsi.Init, pOwner, NULL                          ;hWnd is set in WndProc
  m2m [xsi].dBackColor, dBackColor, ecx
  m2m [xsi].dZoomFactor, $ObjTmpl(Application).dTxtZoomFactor, eax
  mov xdi, pOwner
  invoke CreateMDIWindow, offset szDbgMdiChildBmpClass, pTitle, \
             WS_HSCROLL or WS_VSCROLL, CW_USEDEFAULT, CW_USEDEFAULT, \
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
      invoke DrawMenuBar, [xbx].$Obj(MdiApp).hWnd             ;Redraw the new menu bar
      OCall xbx::Application.ManageOptions, DBG_MDI_CHILD_BMP_ID
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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildBmp.OnEraseBkgnd
; Purpose:    Event procedure for WM_ERASEBKGND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DbgMdiChildBmp.OnEraseBkgnd,, wParam:WPARAM, lParam:LPARAM
  xor eax, eax
  inc eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildBmp.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DbgMdiChildBmp.OnPaint, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, dWidth:DWORD, dHeight:DWORD, Rct:RECT
  local ScrollInfo:SCROLLINFO, DstRect:RECT, hBrush:HANDLE

  SetObject xsi
  invoke BeginPaint, [xsi].hWnd, addr PS
  invoke GetClientRect, [xsi].hWnd, addr Rct

  .if [xsi].pBmp != NULL
    mov xdi, [xsi].pBmp
    mov eax, [xdi].BITMAPINFO.bmiHeader.biWidth
    mul [xsi].dZoomFactor
    shr eax, 6
    mov dWidth, eax
    mov eax, [xdi].BITMAPINFO.bmiHeader.biHeight
    mul [xsi].dZoomFactor
    shr eax, 6
    mov dHeight, eax

    xor eax, eax
    mov ecx, dHeight
    .if ecx > Rct.bottom
      inc eax
    .endif
    invoke ShowScrollBar, [xsi].hWnd, SB_VERT, eax
    invoke GetClientRect, [xsi].hWnd, addr Rct          ;Update client rect

    mov ScrollInfo.cbSize, sizeof(SCROLLINFO)
    mov ScrollInfo.fMask, SIF_ALL
    m2z ScrollInfo.nMin

    ;Adjust horizontal scrollbar
    mov eax, dWidth
    .if eax > Rct.right
      mov ecx, dWidth
      sub ecx, Rct.right
      .if SDWORD ptr ecx < [xsi].dHorzOffset
        mov [xsi].dHorzOffset, ecx
      .endif

      m2m ScrollInfo.nMax, dWidth, eax
      dec ScrollInfo.nMax
      m2m ScrollInfo.nPage, Rct.right, eax
      m2m ScrollInfo.nPos, [xsi].dHorzOffset, ecx
      invoke SetScrollInfo, [xsi].hWnd, SB_HORZ, addr ScrollInfo, TRUE
      invoke ShowScrollBar, [xsi].hWnd, SB_HORZ, TRUE
    .else
      xor eax, eax
      mov [xsi].dHorzOffset, eax
      invoke ShowScrollBar, [xsi].hWnd, SB_HORZ, eax
    .endif
    invoke GetClientRect, [xsi].hWnd, addr Rct          ;Update client rect

    ;Adjust vertical scrollbar
    mov eax, dHeight
    .if eax > Rct.bottom
      mov ecx, dHeight
      sub ecx, Rct.bottom
      .if SDWORD ptr ecx < [xsi].dVertOffset
        mov [xsi].dVertOffset, ecx
      .endif

      m2m ScrollInfo.nMax, dHeight, eax
      dec ScrollInfo.nMax
      m2m ScrollInfo.nPage, Rct.bottom, eax
      m2m ScrollInfo.nPos, [xsi].dVertOffset, ecx
      invoke SetScrollInfo, [xsi].hWnd, SB_VERT, addr ScrollInfo, TRUE
      invoke ShowScrollBar, [xsi].hWnd, SB_VERT, TRUE
    .else
      xor eax, eax
      mov [xsi].dVertOffset, eax
      invoke ShowScrollBar, [xsi].hWnd, SB_VERT, eax
    .endif
    invoke SetStretchBltMode, PS.hdc, HALFTONE
    invoke GetClientRect, [xsi].hWnd, addr Rct

    ;Show the DIB
    mov edx, [xsi].dHorzOffset
    neg edx
    mov eax, [xsi].dVertOffset
    neg eax

    lea xbx, [xdi + sizeof(BITMAPINFO) - sizeof(RGBQUAD)]
    .if [xdi].BITMAPINFO.bmiHeader.biBitCount == 1
      add xbx, 2*4
    .elseif [xdi].BITMAPINFO.bmiHeader.biBitCount == 4
      add xbx, 16*4
    .elseif [xdi].BITMAPINFO.bmiHeader.biBitCount == 8
      add xbx, 256*4
    .endif

    mov DstRect.left, edx
    mov DstRect.top, eax
    m2m DstRect.right, dWidth, ecx
    m2m DstRect.bottom, dHeight, ecx

    invoke StretchDIBits, PS.hdc, edx, eax, dWidth, dHeight, \
             0, 0, [xdi].BITMAPINFO.bmiHeader.biWidth, [xdi].BITMAPINFO.bmiHeader.biHeight, \
             xbx, xdi, DIB_RGB_COLORS, SRCCOPY

    ;Fill the remainig background with COLOR_APPWORKSPACE color
    mov hBrush, $invoke(CreateSolidBrush, [xsi].dBackColor)
    m2m Rct.left, DstRect.right, ecx
    invoke FillRect, PS.hdc, addr Rct, hBrush
    m2z Rct.left
    m2m Rct.top, DstRect.bottom, ecx
    invoke FillRect, PS.hdc, addr Rct, hBrush
    invoke DeleteObject, hBrush

  .else
    ;Fill the background with COLOR_APPWORKSPACE color
    mov hBrush, $invoke(CreateSolidBrush, [xsi].dBackColor)
    invoke FillRect, PS.hdc, addr Rct, hBrush
    invoke DeleteObject, hBrush

    invoke ShowScrollBar, [xsi].hWnd, SB_BOTH, FALSE
  .endif
  invoke EndPaint, [xsi].hWnd, addr PS
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildBmp.OnHScroll
; Purpose:    Event procedure for WM_HSCROLL message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DbgMdiChildBmp.OnHScroll, uses xsi, wParam:WPARAM, lParam:LPARAM
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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildBmp.OnVScroll
; Purpose:    Event procedure for WM_VSCROLL message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DbgMdiChildBmp.OnVScroll, uses xsi, wParam:WPARAM, lParam:LPARAM
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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildBmp.OnRButtonDown
; Purpose:    Event procedure for WM_RBUTTONDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method DbgMdiChildBmp.OnRButtonDown,, wParam:WPARAM, lParam:LPARAM
  SetObject xax
  mov xcx, [xax].pOwner                                 ;xcx -> DbgMdiClient
  invoke SendMessage, [xcx].$Obj(DbgMdiClient).hWnd, WM_MDIACTIVATE, \
                      [xax].$Obj(DbgMdiChildBmp).hWnd, 0
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildBmp.OnRButtonUp
; Purpose:    Event procedure for WM_RBUTTONUP message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method DbgMdiChildBmp.OnRButtonUp,, wParam:WPARAM, lParam:LPARAM
  local Pnt:POINT

  invoke GetCursorPos, addr Pnt
  invoke GetSubMenu, $ObjTmpl(Application).hMenuContext, 0
  invoke TrackPopupMenu, xax, TPM_LEFTALIGN, Pnt.x, Pnt.y, 0, $ObjTmpl(Application).hWnd, NULL
  invoke PostMessage, $ObjTmpl(Application).hWnd, WM_NULL, 0, 0
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildBmp.OnMouseWheel
; Purpose:    Event procedure for WM_MOUSEWHEEL message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if processed.

Method DbgMdiChildBmp.OnMouseWheel,, wParam:WPARAM, lParam:LPARAM
  mov xax, wParam
  .ifBitSet ax, MK_CONTROL
    shr eax, 16
    .if SWORD ptr ax > 0
      OCall pSelf.ZoomIn
    .else
      OCall pSelf.ZoomOut
    .endif
  .else
    .ifBitSet ax, MK_SHIFT
      shr eax, 16
      .if SWORD ptr ax > 0
        OCall pSelf.OnHScroll, SB_LINEDOWN, 0
      .else
        OCall pSelf.OnHScroll, SB_LINEUP, 0
      .endif
    .else
      shr eax, 16
      .if SWORD ptr ax > 0
        OCall pSelf.OnVScroll, SB_LINEDOWN, 0
      .else
        OCall pSelf.OnVScroll, SB_LINEUP, 0
      .endif
    .endif
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildBmp.OnKeyDown
; Purpose:    Event procedure for WM_KEYDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if processed.

Method DbgMdiChildBmp.OnKeyDown,, wParam:WPARAM, lParam:LPARAM
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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildBmp.Open
; Purpose:    Load the content of a txt file.
; Arguments:  Arg1: -> Filename.
; Return:     Nothing.

Method DbgMdiChildBmp.Open, uses xbx xdi xsi, pFileName:PSTRING
  local BMFH:BITMAPFILEHEADER, pBmp:POINTER
  local cMsg[1024]:CHR

  SetObject xsi
  mov pBmp, NULL
  mov xdi, $New(DiskStream)
  OCall xdi::DiskStream.Init, xsi, pFileName, 0, 0, NULL, 0, 0, 0
  OCall xdi::DiskStream.BinRead, addr BMFH, sizeof(BMFH)
  .if [xdi].$Obj(DiskStream).dErrorCode == OBJ_OK
    .if BMFH.bfType == "MB"                             ;Check Bitmap file signature
      mov ebx, BMFH.bfSize
      sub ebx, sizeof(BMFH)
      MemAlloc ebx
      .if xax != NULL
        mov pBmp, xax
        OCall xdi::DiskStream.BinRead, pBmp, ebx        ;Load bitmap data
        cmp eax, ebx
        jne @@Error
        .if [xdi].$Obj(DiskStream).dErrorCode == OBJ_OK
          .if [xsi].pBmp != NULL
            MemFree [xsi].pBmp                            ;Free old data if any...
          .endif
          m2m [xsi].pBmp, pBmp, xax                       ;Assign bitmap data to object member
        .else
          jmp @@Error
        .endif
      .else
        mov edx, $ObjTmpl(Application).dLanguage
        add edx, 126
        invoke LoadString, hInstance, edx, addr cMsg, lengthof cMsg - 1
        invoke MessageBox, [xsi].hWnd, addr cMsg, offset szDebugCenter, MB_OK or MB_ICONERROR
      .endif
    .else
      mov edx, $ObjTmpl(Application).dLanguage
      add edx, 123
      invoke LoadString, hInstance, edx, addr cMsg, lengthof cMsg - 1
      invoke MessageBox, [xsi].hWnd, addr cMsg, offset szDebugCenter, MB_OK or MB_ICONERROR
    .endif
  .else
@@Error:
    mov edx, $ObjTmpl(Application).dLanguage
    add edx, 121
    invoke LoadString, hInstance, edx, addr cMsg, lengthof cMsg - 1
    invoke MessageBox, [xsi].hWnd, addr cMsg, offset szDebugCenter, \
                       MB_OK or MB_ICONERROR
    .if pBmp != NULL
      MemFree pBmp
    .endif
  .endif
  Destroy xdi
  OCall xsi.ClpBrdSetBtns
  ACall xsi.Open, pFileName                             ;Remenber this file name
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildBmp.Print
; Purpose:    Print the content of a BmpChild.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildBmp.Print, uses xbx xdi xsi
  local PrtDlg:PRINTDLG, DocInfo:DOCINFO, cMsg[1024]:CHR
  local LogPix:POINT, Pagrsize:POINT, PageOffset:POINT, PrintSize:POINT

  SetObject xsi

  mov PrtDlg.lStructSize, sizeof(PrtDlg)
  m2m PrtDlg.hwndOwner, [xsi].hWnd, xax
  mov xdx, [xsi].pOwner
  mov xbx, [xdx].$Obj(DbgMdiClient).pOwner
  m2m PrtDlg.hDevMode, [xbx].$Obj(Application).hDevMode, xax
  m2m PrtDlg.hDevNames, [xbx].$Obj(Application).hDevNames, xcx
  m2z PrtDlg.hDC
  mov PrtDlg.Flags, PD_NOSELECTION or PD_RETURNDC
  m2z PrtDlg.nFromPage
  m2z PrtDlg.nToPage
  m2z PrtDlg.nMinPage
  m2z PrtDlg.nMaxPage
  mov PrtDlg.nCopies, 1
  m2m PrtDlg.hInstance, hInstance, xax
  m2z PrtDlg.lCustData
  m2z PrtDlg.lpfnPrintHook
  m2z PrtDlg.lpfnSetupHook
  m2z PrtDlg.lpPrintTemplateName
  m2z PrtDlg.lpSetupTemplateName
  m2z PrtDlg.hPrintTemplate
  m2z PrtDlg.hSetupTemplate

  .if $invoke(PrintDlg, addr PrtDlg)
    m2m [xbx].$Obj(Application).hDevMode, PrtDlg.hDevMode, xax
    m2m [xbx].$Obj(Application).hDevNames, PrtDlg.hDevNames, xcx
    .ifBitSet $invoke(GetDeviceCaps, PrtDlg.hDC, RASTERCAPS), RC_BITBLT
      mov DocInfo.cbSize, sizeof(DocInfo)
      m2m DocInfo.lpszDocName, offset szDebugCenter, xax
      m2z DocInfo.lpszOutput
      m2z DocInfo.lpszDatatype
      m2z DocInfo.fwType

      mov Pagrsize.x, $32($invoke(GetDeviceCaps, PrtDlg.hDC, PHYSICALWIDTH))
      mov Pagrsize.y, $32($invoke(GetDeviceCaps, PrtDlg.hDC, PHYSICALHEIGHT))
      mov PageOffset.x, $32($invoke(GetDeviceCaps, PrtDlg.hDC, PHYSICALOFFSETX))
      mov PageOffset.y, $32($invoke(GetDeviceCaps, PrtDlg.hDC, PHYSICALOFFSETY))
      mov LogPix.x, $32($invoke(GetDeviceCaps, PrtDlg.hDC, LOGPIXELSX))
      mov LogPix.y, $32($invoke(GetDeviceCaps, PrtDlg.hDC, LOGPIXELSY))

      ;Set paper margins using the Viewport
      invoke SetMapMode, PrtDlg.hDC, MM_ISOTROPIC
      invoke MulDiv, [xbx].$Obj(Application).PrintMargin.left, LogPix.x, 2540
      sub eax, PageOffset.x
      mov edi, eax
      invoke MulDiv, [xbx].$Obj(Application).PrintMargin.top, LogPix.y, 2540
      sub eax, PageOffset.y
      invoke SetViewportOrgEx, PrtDlg.hDC, edi, eax, NULL

      mov eax, [xbx].$Obj(Application).PrintMargin.left
      add eax, [xbx].$Obj(Application).PrintMargin.right
      invoke MulDiv, eax, LogPix.x, -2540
      add eax, Pagrsize.x
      mov PrintSize.x, eax
      mov eax, [xbx].$Obj(Application).PrintMargin.top
      add eax, [xbx].$Obj(Application).PrintMargin.bottom
      invoke MulDiv, eax, LogPix.y, -2540
      add eax, Pagrsize.y
      mov PrintSize.y, eax
      invoke SetWindowExtEx, PrtDlg.hDC, PrintSize.x, PrintSize.y, NULL
      invoke SetViewportExtEx, PrtDlg.hDC, PrintSize.x, PrintSize.y, NULL
      invoke CreateRectRgn, 0, 0, PrintSize.x, PrintSize.y
      mov xbx, xax
      invoke SelectClipRgn, PrtDlg.hDC, xbx
      invoke DeleteObject, xbx

      invoke StartDoc, PrtDlg.hDC, addr DocInfo
      invoke StartPage, PrtDlg.hDC
      mov xbx, [xsi].pBmp

      invoke StretchDIBits, PrtDlg.hDC, \
                   0, 0, [xbx].BITMAPINFO.bmiHeader.biWidth, [xbx].BITMAPINFO.bmiHeader.biHeight, \
                   0, 0, [xbx].BITMAPINFO.bmiHeader.biWidth, [xbx].BITMAPINFO.bmiHeader.biHeight, \
                   addr [xbx].BITMAPINFO.bmiColors, xbx, DIB_RGB_COLORS, SRCCOPY

      invoke EndPage, PrtDlg.hDC
      invoke EndDoc, PrtDlg.hDC
      invoke DeleteDC, PrtDlg.hDC
    .else
      mov edx, $ObjTmpl(Application).dLanguage
      add edx, 124
      invoke LoadString, hInstance, edx, addr cMsg, lengthof cMsg - 1
      invoke MessageBox, [xsi].hWnd, addr cMsg, offset szDebugCenter, MB_OK or MB_ICONERROR
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildBmp.SaveAs
; Purpose:    Save the content of the RichEdit control to a specified file.
; Arguments:  Arg1: Dummy value 1.
;             Arg2: Dummy value 2.
; Return:     Nothing.

Method DbgMdiChildBmp.SaveAs,, pDummy1:PSTRING, pDummy2:PSTRING
  ACall SaveAs, offset szBmpFilter, offset szBmpExt
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildBmp.SaveTo
; Purpose:    Save the content of the RichEdit control to a specified file.
; Arguments:  Arg1: -> File path and name.
; Return:     Nothing.

Method DbgMdiChildBmp.SaveTo, uses xsi, pFileName:PSTRING
  local pStream:$ObjPtr(Stream), BMFH:BITMAPFILEHEADER, dSize:DWORD

  SetObject xsi
  mov BMFH.bfType, "MB"                                 ;Set Bitmap file signature = "BM"
  mov dSize, $32($invoke(HeapSize, hProcessHeap, HEAP_NO_SERIALIZE, [xsi].pBmp))
  add eax, size BMFH
  mov BMFH.bfSize, eax                                  ;Set file size
  m2z BMFH.bfReserved1
  m2z BMFH.bfReserved2
  mov BMFH.bfOffBits, size BITMAPINFOHEADER + sizeof(BITMAPFILEHEADER)

  mov pStream, $New(DiskStream)
  OCall pStream::DiskStream.Init, xsi, pFileName, 0, 0, NULL, 0, 0, 0
  OCall pStream::DiskStream.BinWrite, addr BMFH, sizeof(BMFH)
  OCall pStream::DiskStream.BinWrite, [xsi].pBmp, dSize
  Destroy pStream
  ACall xsi.SaveTo, pFileName                           ;Save FileName
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildBmp.SetBitmap
; Purpose:    Allocate in local meory the recieved bitmap.
; Arguments:  Arg1: ->  DBG_BMP_INFO structure.
; Return:     Nothing.

Method DbgMdiChildBmp.SetBitmap, uses xbx xdi xsi, pBmpInfo:POINTER
  local InvalidRect:RECT

  SetObject xsi
  mov xbx, [xsi].pBmp
  .if xbx != NULL
    m2z InvalidRect.left
    m2z InvalidRect.top
    m2m InvalidRect.right, [xbx].DBG_BMP_INFO.BmpHeader.biWidth, eax
    m2m InvalidRect.bottom, [xbx].DBG_BMP_INFO.BmpHeader.biHeight, ecx
    invoke InvalidateRect, [xsi].hWnd, addr InvalidRect, TRUE
    MemFree xbx
  .else
    invoke InvalidateRect, [xsi].hWnd, NULL, TRUE
  .endif
  mov xbx, pBmpInfo
  mov edi, [xbx].DBG_BMP_INFO.dBlockLen
  sub edi, sizeof(DBG_BMP_INFO) - sizeof(BITMAPINFOHEADER)
  mov [xsi].pBmp, $MemAlloc(edi)
  lea xdx, [xbx].DBG_BMP_INFO.BmpHeader
  invoke MemClone, xax, xdx, edi                        ;Copy BITMAPINFO + BMP data
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildBmp.Startup
; Purpose:    Register the object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildBmp.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof(WNDCLASSEX)
  mov WC.style, CS_HREDRAW or CS_VREDRAW or CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT
  m2m WC.lpfnWndProc, $MethodAddr(DbgMdiChildBmp.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  m2z WC.hbrBackground
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szDbgMdiChildBmpClass, xax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP_CHILD_BMP"))
  m2z WC.hIconSm
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)

  invoke RegisterClassEx, addr WC
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildBmp.UpdateStatusbar
; Purpose:    Draw new information on the Statusbar.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildBmp.UpdateStatusbar, uses xbx xdi xsi
  local cTextBuffer[1024]:CHR, wResText[1024]:CHRW, dWidth:DWORD, dHeight:DWORD

;  DbgText "DbgMdiChildBmp.UpdateStatusbar"
  SetObject xsi
  mov xcx, [xsi].pOwner
  mov xbx, [xcx].$Obj(DbgMdiClient).pOwner

  .if [xsi].pBmp != NULL
    mov xcx, [xsi].pBmp
    m2m dWidth, [xcx].BITMAPINFO.bmiHeader.biWidth, eax
    m2m dHeight, [xcx].BITMAPINFO.bmiHeader.biHeight, eax
    lea xdi, cTextBuffer
    mov edx, [xbx].$Obj(Application).dLanguage
    add edx, 150                                        ;"Bitmap size"
    invoke LoadStringW, hInstance, edx, addr wResText, lengthof wResText
    WriteF xdi, "¦SU: ¦UD x ¦UD ", addr wResText, dWidth, dHeight
    mov edx, [xbx].$Obj(Application).dLanguage
    add edx, 151                                        ;"pixel"
    invoke LoadStringW, hInstance, edx, addr wResText, lengthof wResText
    WriteF xdi, "¦SU", addr wResText
    OCall [xbx].$Obj(Application).pStatusbar::Statusbar.SetPartText, 1, addr cTextBuffer, SBT_SUNKEN
  .else
    OCall [xbx].$Obj(Application).pStatusbar::Statusbar.SetPartText, 1, NULL, SBT_SUNKEN
  .endif
  OCall [xbx].$Obj(Application).pStatusbar::Statusbar.SetPartText, 2, NULL, SBT_SUNKEN
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildBmp.ZoomIn
; Purpose:    Increase the output size.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildBmp.ZoomIn, uses xsi
  local HScrollInfo:SCROLLINFO, VScrollInfo:SCROLLINFO

  SetObject xsi
  invoke MulDiv, [xsi].dZoomFactor, 67145533, 56462438  ;Rational approximation of Sqrt(Sqrt(2))
  mov [xsi].dZoomFactor, eax                            ;https://www.johndcook.com/rational_approximation.html
  .if [xsi].dZoomFactor > BMP_ZOOM_MAX
    mov [xsi].dZoomFactor, BMP_ZOOM_MAX
  .else
    mov HScrollInfo.cbSize, sizeof(HScrollInfo)
    mov HScrollInfo.fMask, SIF_RANGE or SIF_PAGE
    invoke GetScrollInfo, [xsi].hWnd, SB_HORZ, addr HScrollInfo
    mov VScrollInfo.cbSize, sizeof(VScrollInfo)
    mov VScrollInfo.fMask, SIF_RANGE or SIF_PAGE
    invoke GetScrollInfo, [xsi].hWnd, SB_VERT, addr VScrollInfo
    shr [xsi].dHorzOffset, 1
    mov eax, HScrollInfo.nPage
    shr eax, 2
    sub [xsi].dHorzOffset, eax

    mov edx, HScrollInfo.nMax
    sub edx, HScrollInfo.nPage
    inc edx
    .if [xsi].dHorzOffset > edx
      mov [xsi].dHorzOffset, edx
    .elseif SDWORD ptr [xsi].dHorzOffset < 0
      m2z [xsi].dHorzOffset
    .endif

    shr [xsi].dVertOffset, 1
    mov eax, VScrollInfo.nPage
    shr eax, 2
    sub [xsi].dVertOffset, eax

    mov edx, VScrollInfo.nMax
    sub edx, VScrollInfo.nPage
    inc edx
    .if [xsi].dVertOffset > edx
      mov [xsi].dVertOffset, edx
    .elseif SDWORD ptr [xsi].dVertOffset < 0
      m2z [xsi].dVertOffset
    .endif
    invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE or RDW_ERASE
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiChildBmp.ZoomOut
; Purpose:    Decrease the output size.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiChildBmp.ZoomOut, uses xsi
  local HScrollInfo:SCROLLINFO, VScrollInfo:SCROLLINFO

  SetObject xsi
  invoke MulDiv, [xsi].dZoomFactor, 56462438, 67145533  ;Rational approximation of 1/Sqrt(Sqrt(2))
  mov [xsi].dZoomFactor, eax                            ;https://www.johndcook.com/rational_approximation.html
  .if [xsi].dZoomFactor < BMP_ZOOM_MIN
    mov [xsi].dZoomFactor, BMP_ZOOM_MIN
  .else
    mov HScrollInfo.cbSize, sizeof(HScrollInfo)
    mov HScrollInfo.fMask, SIF_RANGE or SIF_PAGE
    invoke GetScrollInfo, [xsi].hWnd, SB_HORZ, addr HScrollInfo
    mov VScrollInfo.cbSize, sizeof(VScrollInfo)
    mov VScrollInfo.fMask, SIF_RANGE or SIF_PAGE
    invoke GetScrollInfo, [xsi].hWnd, SB_HORZ, addr VScrollInfo
    shl [xsi].dHorzOffset, 1
    mov eax, HScrollInfo.nPage
    shr eax, 2
    add [xsi].dHorzOffset, eax
    shl [xsi].dVertOffset, 1
    mov eax, VScrollInfo.nPage
    shr eax, 2
    add [xsi].dVertOffset, eax
    invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE or RDW_ERASE
  .endif
MethodEnd
