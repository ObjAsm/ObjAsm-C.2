; ==================================================================================================
; Title:      ADE_EditorDisplay.inc
; Author:     G. Friedrich
; Version:    See ADE.asm
; Purpose:    ObjAsm Assembler Development Environment.
; ==================================================================================================


; ==================================================================================================
; EditorDisplay implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     EditorDisplay.DrawStatusPanel
; Purpose:    Draw the status panel.
; Arguments:  None.
; Return:     Nothing.

Method EditorDisplay.DrawStatusPanel, uses xbx xdi xsi
  local DrawRect:RECT, hPrevFont:HFONT

  SetObject xsi
  mov xbx, [xsi].pOwner                                 ;xbx -> Editor
  mov xdi, [xsi].pResources

  mov DrawRect.left, 0
  mov eax, [xsi].StatusPanelRect.right
  sub eax, [xsi].StatusPanelRect.left
  mov DrawRect.right, eax
  mov DrawRect.top, 0
  mov ecx, [xsi].StatusPanelRect.bottom
  sub ecx, [xsi].StatusPanelRect.top
  mov DrawRect.bottom, ecx

  invoke FillRect, [xsi].hPanelDC, addr DrawRect, [xdi].$Obj(EditorResources).StatusPanelText.Background.hBrush
  .ifBitSet [xbx].$Obj(Editor).dFlags, EIF_DIRTY
    mov xdx, [xdi].$Obj(EditorResources).hBmpStatusIndYellow
  .else
    mov xdx, [xdi].$Obj(EditorResources).hBmpStatusIndGreen
  .endif
  invoke DrawTransparentBitmap, [xsi].hPanelDC, xdx, [xsi].PosIndDirty.x, [xsi].PosIndDirty.y, 80000000h

  invoke SetTextColor, [xsi].hPanelDC, [xdi].$Obj(EditorResources).StatusPanelText.ForeColor
  mov hPrevFont, $invoke(SelectObject, [xsi].hPanelDC, [xdi].$Obj(EditorResources).StatusPanelText.hFont)
  mov xax, [xsi].pOwner
  .ifBitSet [xax].$Obj(Editor).dFlags, EIF_BLOCK_MODE
    lea xdx, cBlockModeLabel
  .elseIfBitSet [xax].$Obj(Editor).dFlags, EIF_OVERWRITE_MODE
    lea xdx, cOverwriteModeLabel
  .else
    lea xdx, cInsertModeLabel
  .endif
  sub DrawRect.right, 4                                 ;Add space from the right side
  invoke DrawText, [xsi].hPanelDC, xdx, -1, addr DrawRect, DT_SINGLELINE or DT_VCENTER or DT_RIGHT or DT_NOCLIP
  invoke SelectObject, [xsi].hPanelDC, hPrevFont
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     EditorDisplay.Done
; Purpose:    Finalize the EditorDisplay object.
; Arguments:  None.
; Return:     Nothing.

Method EditorDisplay.Done, uses xsi
  SetObject xsi
  invoke SelectObject, [xsi].hPanelDC, [xsi].hPrvPanelBmp  ;xax = hTextBmp
  invoke DeleteObject, xax                              ;Delete memory bitmap
  invoke DeleteDC, [xsi].hPanelDC                       ;Delete memory DC
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     EditorDisplay.InformDeletionOf
; Purpose:    Inform that a specific lines was deleted.
; Arguments:  Arg1: Line number of Arg1.
; Return:     Nothing.

Method EditorDisplay.InformDeletionOf, uses xsi, dLineNumber:DWORD
  SetObject xsi
  mov ecx, dLineNumber
  .if ecx < [xsi].View.d1stVisLineNum                   ;A line before the 1st vis line is to be deleted   
    dec [xsi].View.d1StVisLineCount
    dec [xsi].View.d1stVisLineNum
  .elseif ecx == [xsi].View.d1stVisLineNum              ;The 1st vis line is to be deleted
    mov xax, [xsi].View.p1stVisLine 
    GotoNextVisTextLine xax,,, edx
    .if xax != NULL
      sub [xsi].View.d1StVisLineCount, edx
    .else
      mov xax, [xsi].View.p1stVisLine 
      GotoPrevVisTextLine xax,,, edx
      .if xax != NULL
        sub [xsi].View.d1StVisLineCount, edx
      .else
        mov [xsi].View.d1stVisLineNum, 0
        mov [xsi].View.d1StVisLineCount, 0
      .endif
    .endif
    mov [xsi].View.p1stVisLine, xax
  .endif
;  DbgEditorDisplay xsi,, "EditorDisplay"
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     EditorDisplay.InformInsertionOf
; Purpose:    Inform that a specific lines was inserted.
; Arguments:  Arg1: Line number of Arg1.
; Return:     Nothing.

Method EditorDisplay.InformInsertionOf, uses xsi, dLineNumber:DWORD
  SetObject xsi
  mov ecx, dLineNumber
  .if ecx <= [xsi].View.d1stVisLineNum                   ;A line before the 1st vis line is to be inserted   
    inc [xsi].View.d1StVisLineCount
    inc [xsi].View.d1stVisLineNum
  .endif
;  DbgEditorDisplay xsi,, "EditorDisplay"
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     EditorDisplay.Init
; Purpose:    Initialize the EditorDisplay object.
; Arguments:  Arg1: -> Owner object (Editor).
;             Arg2: -> RECT.
;             Arg3: -> EditorResources.
; Return:     eax = hWnd or 0 if failed.

Method EditorDisplay.Init, uses xbx xdi xsi, pOwner:POINTER, pRect:PRECT, pResources:$ObjPtr(EditorResources)
;  DbgText "EditorDisplay.Init"
  SetObject xsi
  ACall xsi.Init, pOwner, 0
  m2m [xsi].pResources, pResources, xax

  ;Initialize both scrollbars
  OCall xsi.SetupScrollBarHorz
  OCall xsi.SetupScrollBarVert

  ;Create the EditorDisplay window
  mov xbx, pRect
  mov xdi, pOwner
  invoke CreateWindowEx, 0, offset szEditorDisplayClassName, NULL, WS_CHILD, \
                         [xbx].RECT.left, [xbx].RECT.top, [xbx].RECT.right, [xbx].RECT.bottom, \
                         [xdi].$Obj(Editor).hWnd, 0, hInstance, xsi
  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL          ;Show the window
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     EditorDisplay.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero to continue the window creation process and -1 to stop it.

Method EditorDisplay.OnCreate, uses xsi, wParam:WPARAM, lParam:LPARAM
  local hDC:HDC, ClientRect:RECT, DefStruc:DEF_SCROLLBAR

  ANNOTATION use:wParam lParam

;  DbgText "EditorDisplay.OnCreate"
  SetObject xsi
  invoke GetClientRect, [xsi].hWnd, addr ClientRect

  mov xcx, [xsi].pResources
  mov eax, [xcx].$Obj(EditorResources).ScrollBarMetric.x
  sub ClientRect.right, eax
  mov eax, [xcx].$Obj(EditorResources).ScrollBarMetric.y
  sub ClientRect.bottom, eax
  OCall [xsi].View::EditorView.Init, xsi, addr ClientRect, [xsi].pResources

  m2z DefStruc.dExStyle
  m2z DefStruc.pTitle
  m2z DefStruc.sdPosX
  m2z DefStruc.sdPosY
  m2z DefStruc.dWidth
  m2z DefStruc.dHeight

  ;Create the 2 scrollbars
  mov DefStruc.dStyle, SBS_VERT
  mov DefStruc.xCtlID, IDC_SCROLLBARVERT
  OCall [xsi].ScrollBarVert::ScrollBar.Init, xsi, [xsi].hWnd, addr DefStruc

  mov DefStruc.dStyle, SBS_HORZ
  mov DefStruc.xCtlID, IDC_SCROLLBARHORZ
  OCall [xsi].ScrollBarHorz::ScrollBar.Init, xsi, [xsi].hWnd, addr DefStruc

  mov hDC, $invoke(GetWindowDC, [xsi].hWnd)
  mov [xsi].hPanelDC, $invoke(CreateCompatibleDC, hDC)
  invoke SetBkMode, [xsi].hPanelDC, TRANSPARENT
  invoke CreateCompatibleBitmap, hDC, 1, 1
  mov [xsi].hPanelBmp, xax
  mov [xsi].hPrvPanelBmp, $invoke(SelectObject, [xsi].hPanelDC, [xsi].hPanelBmp)

  invoke ReleaseDC, [xsi].hWnd, hDC
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     EditorDisplay.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method EditorDisplay.OnPaint, uses xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, hDC:HDC, hBrush:HBRUSH

  ANNOTATION use:wParam lParam

;  DbgText "EditorDisplay.OnPaint"
  SetObject xsi
  mov hDC, $invoke(BeginPaint, [xsi].hWnd, addr PS)     ;Hides the caret automatically

  OCall xsi.SetupScrollBarHorz
  OCall xsi.SetupScrollBarVert

  ;Fill the SplitterRect
  mov xcx, [xsi].pResources
  mov xax, [xcx].$Obj(EditorResources).StatusPanelText.Background.hBrush
  lea xdx, [xsi].SplitterRect
  invoke FillRect, hDC, xdx, xax

  OCall xsi.DrawStatusPanel
  ;Copy bitmap to screen
  invoke BitBlt, hDC, [xsi].StatusPanelRect.left, [xsi].StatusPanelRect.top, \
                      [xsi].StatusPanelRect.right, [xsi].StatusPanelRect.bottom, \
                      [xsi].hPanelDC, 0, 0, SRCCOPY

  invoke EndPaint, [xsi].hWnd, addr PS                  ;Restores the caret if it was previously
  xor eax, eax                                          ;   hidden by BeginPaint
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     EditorDisplay.OnScrollHorz
; Purpose:    Event procedure for WM_HSCROLL message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method EditorDisplay.OnScrollHorz, uses xsi, wParam:WPARAM, lParam:LPARAM
  local dNeedRedrawing:DWORD, ScrollInfo:SCROLLINFO

  ANNOTATION use:wParam lParam

  SetObject xsi
;  DbgText "EditorDisplay.OnScrollHorz"
  mov dNeedRedrawing, 0

  mov xax, wParam
  .if ax == SB_THUMBTRACK || ax == SB_THUMBPOSITION
    shr eax, 16
    mov ScrollInfo.cbSize, sizeof ScrollInfo
    mov ScrollInfo.fMask, SIF_TRACKPOS
    invoke GetScrollInfo, [xsi].ScrollBarHorz.hWnd, SB_CTL, addr ScrollInfo
    mov edx, [xsi].View.d1stVisCharIndex
    mov eax, ScrollInfo.nTrackPos
    .if edx < eax
      sub eax, edx
      OCall [xsi].View::EditorView.ScrollPageRight, eax  ;Goto right eax lines with saturation
      .if eax != 0
        inc dNeedRedrawing
;        add [xsi].View.CaretLocation.dCharIndex, ecx
        OCall [xsi].View::EditorView.CaretSet
      .endif

    .elseif edx > eax
      sub edx, eax
      OCall [xsi].View::EditorView.ScrollPageLeft, edx   ;Goto left edx lines with saturation
      .if eax != 0
        inc dNeedRedrawing
;        add [xsi].View.CaretLocation.dCharIndex, ecx
        OCall [xsi].View::EditorView.CaretSet
      .endif
    .endif

  .elseif ax == SB_PAGELEFT
    OCall [xsi].View::EditorView.ScrollPageLeft, [xsi].ScrollPage.x  ;Goto previous page with saturation
    .if eax != 0
      inc dNeedRedrawing
;      add [xsi].View.CaretLocation.dCharIndex, ecx
      OCall [xsi].View::EditorView.CaretSet
    .endif

  .elseif ax == SB_PAGERIGHT
    OCall [xsi].View::EditorView.ScrollPageRight, [xsi].ScrollPage.x ;Goto next page with saturation
    .if eax != 0
      inc dNeedRedrawing
;      add [xsi].View.CaretLocation.dCharIndex, ecx
      OCall [xsi].View::EditorView.CaretSet
    .endif

  .elseif ax == SB_LINELEFT
    OCall [xsi].View::EditorView.ScrollLineLeft         ;Goto previous line with saturation
    .if eax != 0
      inc dNeedRedrawing
;      inc [xsi].View.CaretLocation.dCharIndex
      OCall [xsi].View::EditorView.CaretSet
    .endif

  .elseif ax == SB_LINERIGHT
    OCall [xsi].View::EditorView.ScrollLineRight        ;Goto next line with saturation
    .if eax != 0
      inc dNeedRedrawing
;      dec [xsi].View.CaretLocation.dCharIndex
      OCall [xsi].View::EditorView.CaretSet
    .endif
  .endif

  .if dNeedRedrawing != 0
    invoke RedrawWindow, [xsi].hWnd, NULL, 0, RDW_ALLCHILDREN or RDW_INVALIDATE
  .endif

  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     EditorDisplay.OnScrollVert
; Purpose:    Event procedure for WM_VSCROLL message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method EditorDisplay.OnScrollVert, uses xsi, wParam:WPARAM, lParam:LPARAM
  local dNeedRedrawing:DWORD, ScrollInfo:SCROLLINFO

  ANNOTATION use:wParam lParam

;  DbgText "EditorDisplay.OnScrollVert"
  SetObject xsi
  mov dNeedRedrawing, 0

  mov xax, wParam
  .if ax == SB_THUMBTRACK
    mov ScrollInfo.cbSize, sizeof ScrollInfo
    mov ScrollInfo.fMask, SIF_TRACKPOS
    invoke GetScrollInfo, [xsi].ScrollBarVert.hWnd, SB_CTL, addr ScrollInfo
    mov edx, [xsi].View.d1stVisLineNum
    mov eax, ScrollInfo.nTrackPos
    .if edx < eax
      sub eax, edx
      OCall [xsi].View::EditorView.ScrollVisPageDown, eax   ;Goto down eax lines with saturation
      .if eax != 0
        inc dNeedRedrawing
        sub [xsi].View.sdCaretVisLineOffset, ecx            ;ecx = scrolled lines
        OCall [xsi].View::EditorView.CaretSet
      .endif
    .elseif edx > eax
      sub edx, eax
      OCall [xsi].View::EditorView.ScrollVisPageUp, edx     ;Goto up edx lines with saturation
      .if eax != 0
        inc dNeedRedrawing
        add [xsi].View.sdCaretVisLineOffset, ecx            ;ecx = scrolled lines
        OCall [xsi].View::EditorView.CaretSet
      .endif
    .endif
    add dNeedRedrawing, eax

  .elseif ax == SB_PAGEUP
    OCall [xsi].View::EditorView.ScrollVisPageUp, [xsi].ScrollPage.y    ;Goto previous page with saturation
    .if eax != 0
      inc dNeedRedrawing
      add [xsi].View.sdCaretVisLineOffset, ecx          ;ecx = scrolled lines
      OCall [xsi].View::EditorView.CaretSet
    .endif

  .elseif ax == SB_PAGEDOWN
    OCall [xsi].View::EditorView.ScrollVisPageDown, [xsi].ScrollPage.y  ;Goto next page with saturation
    .if eax != 0
      inc dNeedRedrawing
      sub [xsi].View.sdCaretVisLineOffset, ecx          ;ecx = scrolled lines
      OCall [xsi].View::EditorView.CaretSet
    .endif

  .elseif ax == SB_LINEUP
    OCall [xsi].View::EditorView.ScrollVisLineUp        ;Goto previous visible line with saturation
    .if eax != 0
      inc dNeedRedrawing
      inc [xsi].View.sdCaretVisLineOffset
      OCall [xsi].View::EditorView.CaretSet
    .endif

  .elseif ax == SB_LINEDOWN
    OCall [xsi].View::EditorView.ScrollVisLineDown      ;Goto next visible line with saturation
    .if eax != 0
      inc dNeedRedrawing
      dec [xsi].View.sdCaretVisLineOffset
      OCall [xsi].View::EditorView.CaretSet
    .endif
  .endif

  .if dNeedRedrawing != 0
    invoke RedrawWindow, [xsi].hWnd, NULL, 0, RDW_ALLCHILDREN or RDW_INVALIDATE
  .endif

  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     EditorDisplay.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter. wParam = SIZE_xxx
;             Arg2: Second message parameter. lParam = POINTS containing client area size.
; Return:     eax = Zero if handled.

Method EditorDisplay.OnSize, uses xsi, wParam:WPARAM, lParam:LPARAM
  ANNOTATION use:wParam lParam

;  DbgText "EditorDisplay.OnSize"
  SetObject xsi
  .if wParam != SIZE_MINIMIZED && lParam != 0           ;x = 0 & y = 0
    OCall xsi.SetGuiLayout
    xor eax, eax
  .else
    mov eax, -1
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     EditorDisplay.OnSetFocus
; Purpose:    Event procedure for WM_SETFOCUS message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method EditorDisplay.OnSetFocus,, wParam:WPARAM, lParam:LPARAM
  ANNOTATION use:wParam lParam

;  DbgText "EditorDisplay.OnSetFocus"
  SetObject xcx
  mov xdx, [xcx].pOwner
  mov xax, [xdx].$Obj(Editor).pFocusedView
  .if xax != NULL
    invoke SetFocus, [xax].$Obj(EditorView).hWnd
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     EditorView.SetGuiLayout
; Purpose:    Define the position an size of all GUI elements in the EditorView.
; Arguments:  None.
; Return:     Nothing.

Method EditorDisplay.SetGuiLayout, uses xdi xsi
  local ClientRect:RECT, PanelSize:POINT

;  DbgText "EditorDisplay.SetGuiLayout"
  SetObject xsi
  mov xdi, [xsi].pResources
  invoke GetClientRect, [xsi].hWnd, addr ClientRect

  ;Define the coords of the StatusPanel RECT 
  mov [xsi].StatusPanelRect.left, 0
  mov eax, [xsi].View.dSelBarWidth
  mov [xsi].StatusPanelRect.right, eax
  mov eax, ClientRect.bottom
  mov [xsi].StatusPanelRect.bottom, eax
  sub eax, [xdi].$Obj(EditorResources).ScrollBarMetric.y
  mov [xsi].StatusPanelRect.top, eax

  ;Define the coords of the Splitter RECT 
  mov [xsi].SplitterRect.top, eax
  mov eax, ClientRect.bottom
  mov [xsi].SplitterRect.bottom, eax
  mov eax, ClientRect.right
  mov [xsi].SplitterRect.right, eax
  sub eax, [xdi].$Obj(EditorResources).ScrollBarMetric.x
  mov [xsi].SplitterRect.left, eax

  ;Create a new bitmap for the StatusPanel
  mov eax, [xsi].StatusPanelRect.right
  sub eax, [xsi].StatusPanelRect.left
  mov PanelSize.x, eax
  mov ecx, [xsi].StatusPanelRect.bottom
  sub ecx, [xsi].StatusPanelRect.top
  mov PanelSize.y, ecx
  .if PanelSize.x > 0 && PanelSize.y > 0
    invoke CreateCompatibleBitmap, [xsi].hPanelDC, PanelSize.x, PanelSize.y
    mov [xsi].hPanelBmp, xax
    invoke SelectObject, [xsi].hPanelDC, xax            ;Use it in the memory DC
    invoke DeleteObject, xax                            ;Discard the old bitmap
  .endif

  ;Position the 2 scrollbars
  mov eax, ClientRect.right
  sub eax, PanelSize.x
  sub eax, [xdi].$Obj(EditorResources).ScrollBarMetric.x
  invoke MoveWindow, [xsi].ScrollBarHorz.hWnd, \
                     [xsi].StatusPanelRect.right, [xsi].StatusPanelRect.top, \
                     eax, [xdi].$Obj(EditorResources).ScrollBarMetric.y, FALSE
  mov eax, [xdi].$Obj(EditorResources).ScrollBarMetric.x
  sub ClientRect.right, eax
  mov eax, [xdi].$Obj(EditorResources).ScrollBarMetric.y
  sub ClientRect.bottom, eax
  invoke MoveWindow, [xsi].ScrollBarVert.hWnd, \
                     ClientRect.right, ClientRect.top, \
                     [xdi].$Obj(EditorResources).ScrollBarMetric.x, ClientRect.bottom, FALSE
  
  ;Position the EditorView using the modified ClientRect
  invoke MoveWindow, [xsi].View.hWnd, \
                     ClientRect.left, ClientRect.top, \
                     ClientRect.right, ClientRect.bottom, FALSE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     EditorDisplay.SetupScrollBarHorz
; Purpose:    Configure the horizontal scrollbar.
; Arguments:  None.
; Return:     Nothing.

Method EditorDisplay.SetupScrollBarHorz, uses xsi
  local ScrollInfo:SCROLLINFO, ClientRect:RECT

;  DbgText "EditorDisplay.SetupScrollBarHorz"
  SetObject xsi
  invoke GetClientRect, [xsi].hWnd, addr ClientRect
  mov xdx, [xsi].pOwner                                 ;xdx -> Editor
  mov xcx, [xdx].$Obj(Editor).pResources

  mov eax, [xsi].View.dSelBarWidth
  sub ClientRect.right, eax                             ;Page width
  mov eax, [xdx].$Obj(Editor).dMaxTextLineChrCount
  mul [xcx].$Obj(EditorResources).EditorTextRegular.FontMetric.y
  .if eax > ClientRect.right
    mov ScrollInfo.cbSize, sizeof ScrollInfo
    mov ScrollInfo.fMask, SIF_ALL
    m2m ScrollInfo.nPage, [xsi].ScrollPage.x, edx
    m2z ScrollInfo.nMin
    mov xcx, [xsi].pOwner                               ;xcx -> Editor
    mov eax, [xcx].$Obj(Editor).dMaxTextLineChrCount
    add eax, edx                                        ;edx = [xsi].ScrollPage.x
    sub eax, 2                                          ;Range: 0..dMaxTextLineChrCount - 1
    mov ScrollInfo.nMax, eax                            ;       Sub 1 to last char in line
    m2m ScrollInfo.nPos, [xsi].View.d1stVisCharIndex, edx
    invoke SetScrollInfo, [xsi].ScrollBarHorz.hWnd, SB_CTL, addr ScrollInfo, FALSE
    invoke EnableWindow, [xsi].ScrollBarHorz.hWnd, TRUE
  .else
    m2z [xsi].View.d1stVisCharIndex
    invoke EnableWindow, [xsi].ScrollBarHorz.hWnd, FALSE
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     EditorDisplay.SetupScrollBarVert
; Purpose:    Configure the vertical scrollbar.
; Arguments:  None.
; Return:     Nothing.

Method EditorDisplay.SetupScrollBarVert, uses xsi
  local ScrollInfo:SCROLLINFO, ClientRect:RECT

;  DbgText "EditorDisplay.SetupScrollBarVert"
  SetObject xsi
  invoke GetClientRect, [xsi].hWnd, addr ClientRect
  mov xdx, [xsi].pOwner                                 ;xdx -> Editor
  mov xcx, [xdx].$Obj(Editor).pResources
  mov eax, [xdx].$Obj(Editor).dVisTextLineCount
  mul [xcx].$Obj(EditorResources).EditorTextRegular.FontMetric.y
  .if eax > ClientRect.bottom
    ;Setup SCROLLINFO structure
    mov ScrollInfo.cbSize, sizeof ScrollInfo
    mov ScrollInfo.fMask, SIF_ALL
    m2m ScrollInfo.nPage, [xsi].ScrollPage.y, edx
    mov ScrollInfo.nMin, 1
    mov xdx, [xsi].pOwner                               ;xcx -> Editor
    mov eax, [xdx].$Obj(Editor).dVisTextLineCount
    add eax, [xsi].ScrollPage.y
    dec eax
    mov ScrollInfo.nMax, eax
    m2m ScrollInfo.nPos, [xsi].View.d1StVisLineCount, edx
    invoke SetScrollInfo, [xsi].ScrollBarVert.hWnd, SB_CTL, addr ScrollInfo, FALSE
    invoke EnableWindow, [xsi].ScrollBarVert.hWnd, TRUE
  .else
    m2z [xsi].View.d1StVisLineCount
    invoke EnableWindow, [xsi].ScrollBarVert.hWnd, FALSE
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     EditorDisplay.Startup
; Purpose:    Register the EditorDisplay object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method EditorDisplay.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CS_DBLCLKS
  m2m WC.lpfnWndProc, $MethodAddr(EditorDisplay.WndProc), xdx
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, edx
  m2z WC.hbrBackground
  m2z WC.lpszMenuName
  m2m WC.lpszClassName, offset szEditorDisplayClassName, xdx
  m2z WC.hIcon
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     EditorDisplay.WindowProc
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.
;             Window HANDLE is passed in pSelf (hidden parameter).

Method EditorDisplay.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
    ANNOTATION use:wParam
    
;  DbgMessage uMsg, "EditorDisplay.WndProc"
  .if uMsg == WM_NCCREATE
    mov xax, lParam
    mov xsi, [xax].CREATESTRUCT.lpCreateParams
    test xsi, xsi
    jz @@DefProc                                        ;Goto handler defined in DispatchEvent
    mrm [xsi].$Obj(Window).hWnd, pSelf, xcx             ;pSelf = hWnd
    invoke SetWindowLongPtr, xcx, GWLP_USERDATA, xsi
  .else
    invoke GetWindowLongPtr, pSelf, GWLP_USERDATA       ;If GWLP_USERDATA wasn't set,
    test xax, xax                                       ;  it returns NULL
    jz @@DefProc                                        ;Goto handler defined in DispatchEvent
    mov xsi, xax
  .endif
  DispatchEvent <DefWindowProc, pSelf>                  ;xsi -> Object Instance
MethodEnd
