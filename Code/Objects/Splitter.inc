; ==================================================================================================
; Title:      Splitter.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm support of Splitter objects.
; Notes:      Version C.1.1, January 2021
;               - OnPaint color bug corrected.
;               - Color change to dMoveSysColor & dMoveSysBrush while moving.
;             Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


SPT_FLAG_VERTICAL         equ     0
SPT_FLAG_HORIZONTAL       equ     BIT00
SPT_FLAG_LOCKED           equ     BIT01
SPT_FLAG_NO_FLIPBOX       equ     BIT02
SPT_FLAG_SEND_WM_SIZE     equ     BIT03

;Internal flags
SPT_FLAG_MOVING           equ     BIT31

SPT_DEFAULT_WIDTH         equ     6         ;Startup default value
SPT_DEFAULT_LENGTH        equ     100       ;Startup default value

SPT_NO_POSITION           equ     -1

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     Splitter
; Purpose:    Implement a splitter window to divide the work area and resize easily contained frames
;             or windows. Dragging it, the size of the adjacent frames will be adjusted to the new
;             position. Splitters can be horizontal or vertical and can have different widths.

Object Splitter, SplitterID, Window
  RedefineMethod    Done
  RedefineMethod    Init,           POINTER, HWND, DWORD, SDWORD, SDWORD, SDWORD
  RedefineMethod    Load,           $ObjPtr(Stream), PDESER_INFO
  StaticMethod      Startup
  RedefineMethod    OnSize,         WPARAM, LPARAM
  RedefineMethod    Store,          $ObjPtr(Stream)
  RedefineMethod    WndProc,        DWORD, WPARAM, LPARAM

  VirtualEvent      OnLButtonDown,  WM_LBUTTONDOWN
  VirtualEvent      OnLButtonUp,    WM_LBUTTONUP
  VirtualEvent      OnMouseHover,   WM_MOUSEHOVER, WM_RBUTTONDOWN
  VirtualEvent      OnMouseMove,    WM_MOUSEMOVE
  VirtualEvent      OnNotify,       WM_NOTIFY
  VirtualEvent      OnPaint,        WM_PAINT
  VirtualEvent      OnSetCursor,    WM_SETCURSOR

  DefineVariable    dFlags,         DWORD,    SPT_FLAG_VERTICAL
  DefineVariable    dMoveSysColor,  DWORD,    COLOR_WINDOW          ;Used to draw the border
  DefineVariable    dMoveSysBrush,  DWORD,    COLOR_ACTIVEBORDER    ;Used to draw the interior
  DefineVariable    dHoverTime,     DWORD,    1200                  ;Time until the flipbox appears
  DefineVariable    dThickness,     DWORD,    0                     ;Splitter thinkness
  DefineVariable    hCursor,        HCURSOR,  0                     
  DefineVariable    hParent,        HANDLE,   0
  DefineVariable    sdMouseFstPos,  SDWORD,   0
  DefineVariable    sdMouseLstPos,  SDWORD,   0
  DefineVariable    sdLastPos,      SDWORD,   SPT_NO_POSITION
  DefineVariable    sdLimit1,       SDWORD,   0
  DefineVariable    sdLimit2,       SDWORD,   0

  Embed   Flipper,    FlipBox
ObjectEnd


; ==================================================================================================

if IMPLEMENT

CStr szSplitter, "Splitter"

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  SetNewParent
; Purpose:    Helper procedure to switch the a new window parent.
; Arguments:  Arg1: Target window HANDLE.
;             Arg2: New parent HANDLE.
; Return:     Nothing.

SetNewParent proc hWnd:HWND, hNewParent:HWND
  local WndRect:RECT

  invoke GetWindowRect, hWnd, addr WndRect              ;In desktop coords
  invoke MapWindowPoints, HWND_DESKTOP, hNewParent, addr WndRect, 2
  invoke SetParent, hWnd, hNewParent                    ;Set new parent window
  mov eax, WndRect.left
  sub WndRect.right, eax
  mov eax, WndRect.top
  sub WndRect.bottom, eax                               ;Move into new parent coordinate space
  invoke MoveWindow, hWnd, WndRect.left, WndRect.top, WndRect.right, WndRect.bottom, FALSE
  ret
SetNewParent endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Splitter.Done
; Purpose:    Finalize the Splitter object.
; Arguments:  None.
; Return:     Nothing.

Method Splitter.Done, uses xsi
  SetObject xsi
  OCall [xsi].Flipper::FlipBox.Done
  invoke DestroyCursor, [xsi].hCursor
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Splitter.Init
; Purpose:    Initialize the Splitter object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE (usually main application window).
;             Arg3: Splitter type (SPT_FLAG_VERTICAL, SPT_FLAG_HORIZONTAL, etc.).
;             Arg4: Initial position in pixel from parent window left-top corner.
;             Arg5: Splitter limit 1 from parent left/top window.
;             Arg6: Splitter limit 2 within parent window.
; Return:     Nothing.

Method Splitter.Init, uses xsi, pOwner:POINTER, hParent:HWND, dFlags:DWORD, \
                                sdPosition:SDWORD, sdLimit1:SDWORD, sdLimit2:SDWORD
  local DFB:DEF_FLIPBOX

  SetObject xsi
  ACall xsi.Init, pOwner, NULL                          ;hWnd is set in WndProc
  m2m [xsi].sdLimit1, sdLimit1, eax
  m2m [xsi].sdLimit2, sdLimit2, ecx
  m2m [xsi].hParent, hParent, eax
  m2m [xsi].dFlags, dFlags, ecx

  mov DFB.DEF_FLIPBOX.xCtlID, 0
  .ifBitSet dFlags, SPT_FLAG_HORIZONTAL
    invoke CreateWindowEx, WS_EX_TOOLWINDOW, offset szSplitter, NULL, \
                           WS_CHILD, 0, sdPosition, \
                           SPT_DEFAULT_LENGTH, SPT_DEFAULT_WIDTH, \
                           hParent, 0, hInstance, xsi
    mov DFB.DEF_FLIPBOX.dFlags, FBF_VERTICAL
    OCall [xsi].Flipper::FlipBox.Init, xsi, [xsi].hWnd, addr DFB
    mov xdx, $OfsCStr("CURSOR_SPLITHOR")
  .else
    invoke CreateWindowEx, WS_EX_TOOLWINDOW, offset szSplitter, NULL, \
                           WS_CHILD, sdPosition, 0, \
                           SPT_DEFAULT_WIDTH, SPT_DEFAULT_LENGTH, \
                           hParent, 0, hInstance, xsi
    mov DFB.DEF_FLIPBOX.dFlags, FBF_HORIZONTAL
    OCall [xsi].Flipper::FlipBox.Init, xsi, [xsi].hWnd, addr DFB
    mov xdx, $OfsCStr("CURSOR_SPLITVER")
  .endif
  invoke LoadImage, hInstance, xdx, IMAGE_CURSOR, 0, 0, LR_SHARED

  .if xax != NULL
    mov [xsi].hCursor, xax
  .else
    ;Fallback if resource can't be loaded
    .ifBitSet dFlags, SPT_FLAG_HORIZONTAL
      mov xdx, IDC_SIZENS
    .else
      mov xdx, IDC_SIZEWE
    .endif
    mov [xsi].hCursor, $invoke(LoadImage, 0, xdx, IMAGE_CURSOR, 0, 0, LR_SHARED)
  .endif

  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Splitter.Load
; Purpose:    Load and initialize the Splitter instance from a stream object.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> DESER_INFO.
; Return:     Nothing.

Method Splitter.Load, uses xbx xsi, pStream:$ObjPtr(Stream), pDeserInfo:PDESER_INFO
  local WP:WINDOWPLACEMENT

  SetObject xsi
  ACall xsi.Load, pStream, pDeserInfo                   ;Load pSelf, ..., hWnd
  mov xcx, pDeserInfo                                   ;WinPrimer returns the previous hWnd
  mov xbx, [xcx].DESER_INFO.pDesLUT
  OCall xbx::DesLUT.Insert, xax, [xsi].hWnd

  mov [xsi].dFlags, $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].dHoverTime, $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].dThickness, $32($OCall(pStream::Stream.BinRead32))
  OCall pStream::Stream.BinReadX                        ;Previous hParent
  OCall xbx::DesLUT.Find, xax
  .if eax == OBJ_OK
    mov [xsi].hParent, xcx
  .endif
  mov [xsi].sdMouseFstPos, $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].sdMouseLstPos, $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].sdLastPos, $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].sdLimit1, $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].sdLimit2, $32($OCall(pStream::Stream.BinRead32))
  OCall [xsi].Flipper::FlipBox.Load, pStream, pDeserInfo

  OCall pStream::Stream.BinRead, addr WP, sizeof WP
  invoke SetWindowPlacement, [xsi].hWnd, addr WP
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Splitter.OnLButtonDown
; Purpose:    Event procedure for WM_LBUTTONDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Splitter.OnLButtonDown, uses xsi, wParam:WPARAM, lParam:LPARAM
  local WndRect:RECT, CntRect:RECT

;  DbgText "Splitter.OnLButtonDown"
  SetObject xsi
  .ifBitClr [xsi].dFlags, SPT_FLAG_LOCKED               ;If not locked
    BitSet [xsi].dFlags, SPT_FLAG_MOVING

    invoke GetClientRect, [xsi].hParent, addr CntRect
    invoke GetWindowRect, [xsi].hWnd, addr WndRect
    invoke MapWindowPoints, HWND_DESKTOP, [xsi].hParent, addr WndRect, 2
    mov ecx, [xsi].sdLimit1
    .ifBitClr [xsi].dFlags, SPT_FLAG_HORIZONTAL
      mov edx, CntRect.right
      mov eax, WndRect.left
    .else
      mov edx, CntRect.bottom
      mov eax, WndRect.top
    .endif
    sub edx, [xsi].sdLimit2
    sub edx, [xsi].dThickness
    dec edx
    .if sdword ptr eax > ecx && sdword ptr eax < edx
      mov [xsi].sdLastPos, eax
    .endif

    mov xax, lParam
    .ifBitSet [xsi].dFlags, SPT_FLAG_HORIZONTAL
      shr eax, 16
    .endif
    cwde
    mov [xsi].sdMouseFstPos, eax

    PntS2Regs lParam, ecx                               ;Relative to the Splitter client area

    invoke ShowWindow, [xsi].Flipper.hWnd, SW_HIDE
    invoke SetNewParent, [xsi].hWnd, HWND_DESKTOP
    invoke SetCapture, [xsi].hWnd
    xor eax, eax
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Splitter.OnLButtonUp
; Purpose:    Event procedure for WM_LBUTTONUP message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Splitter.OnLButtonUp, uses xsi, wParam:WPARAM, lParam:LPARAM
  local WndRect:RECT, PntRect:RECT, CntRect:RECT

;  DbgText "Splitter.OnLButtonUp"
  SetObject xsi
  .ifBitSet [xsi].dFlags, SPT_FLAG_MOVING
    BitClr [xsi].dFlags, SPT_FLAG_MOVING
    invoke ReleaseCapture
    invoke SetNewParent, [xsi].hWnd, [xsi].hParent

    invoke GetClientRect, [xsi].hParent, addr CntRect
    invoke GetWindowRect, [xsi].hWnd, addr WndRect
    invoke MapWindowPoints, HWND_DESKTOP, [xsi].hParent, addr WndRect, 2
    mov ecx, [xsi].sdLimit1
    .ifBitClr [xsi].dFlags, SPT_FLAG_HORIZONTAL
      mov edx, CntRect.right
      mov eax, WndRect.left
    .else
      mov edx, CntRect.bottom
      mov eax, WndRect.top
    .endif
    sub edx, [xsi].sdLimit2
    sub edx, [xsi].dThickness
    dec edx
    .if sdword ptr eax > ecx && sdword ptr eax < edx
      mov [xsi].sdLastPos, eax
    .endif

    .if sdword ptr eax <= ecx
      mov edx, FBB_FRWD
    .elseif sdword ptr eax >= edx
      mov edx, FBB_BACK
    .else
      mov edx, FBB_BOTH
    .endif
    OCall [xsi].Flipper::FlipBox.EnableButton, edx

    ;Force parent window to resize its children
    invoke GetWindowRect, [xsi].hParent, addr PntRect
    mov eax, PntRect.left
    sub PntRect.right, eax
    mov eax, PntRect.top
    sub PntRect.bottom, eax
    Pnt2Reg32 eax, (POINT ptr PntRect.right)
    invoke SendMessage, [xsi].hParent, WM_SIZE, SIZE_RESTORED, eax
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Splitter.OnMouseHover
; Purpose:    Event procedure for WM_MOUSEHOVER message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax: Zero if handled.

Method Splitter.OnMouseHover, uses xsi, wParam:WPARAM, lParam:LPARAM
  local CntRect:RECT, WndRect:RECT, CursorPos:POINT

  SetObject xsi
  .ifBitClr [xsi].dFlags, SPT_FLAG_MOVING or SPT_FLAG_NO_FLIPBOX
    invoke IsWindowVisible, [xsi].Flipper.hWnd
    .if eax == FALSE
      invoke GetWindowRect, [xsi].hWnd, addr WndRect    ;In Screen coords
      invoke ScreenToClient, [xsi].hParent, addr WndRect.left ;Get position in parent coords
      invoke GetClientRect, [xsi].hParent, addr CntRect
      .ifBitSet [xsi].dFlags, SPT_FLAG_HORIZONTAL
        mov ecx, CntRect.bottom
        sub ecx, [xsi].sdLimit2
        sub ecx, [xsi].dThickness                       ;edx = Limit2 in parent coords
        .if ecx <= WndRect.top
          mov edx, FBB_BACK
        .else
          mov ecx, [xsi].sdLimit1
          .if ecx >= WndRect.top
            mov edx, FBB_FRWD
          .else
            mov edx, FBB_BOTH
          .endif
        .endif
      .else
        mov ecx, CntRect.right
        sub ecx, [xsi].sdLimit2
        sub ecx, [xsi].dThickness                       ;edx = Limit2 in parent coords
        .if ecx <= WndRect.left
          mov edx, FBB_BACK
        .else
          mov ecx, [xsi].sdLimit1
          .if ecx >= WndRect.left
            mov edx, FBB_FRWD
          .else
            mov edx, FBB_BOTH
          .endif
        .endif
      .endif
      OCall [xsi].Flipper::FlipBox.EnableButton, edx

      invoke GetCursorPos, addr CursorPos
      invoke GetWindowRect, [xsi].Flipper.hWnd, addr WndRect
      invoke GetCursorPos, addr CursorPos
      mov eax, WndRect.left
      sub WndRect.right, eax
      mov ecx, WndRect.right
      shr ecx, 1
      sub CursorPos.x, ecx
      mov eax, WndRect.top
      sub WndRect.bottom, eax
      mov ecx, WndRect.bottom
      shr ecx, 1
      sub CursorPos.y, ecx
      invoke MoveWindow, [xsi].Flipper.hWnd, CursorPos.x, CursorPos.y, \
                                             WndRect.right, WndRect.bottom, FALSE
      invoke SetParent, [xsi].Flipper.hWnd, HWND_DESKTOP
      invoke ShowWindow, [xsi].Flipper.hWnd, SW_SHOW
      OCall [xsi].Flipper::FlipBox.CaptureMouse, TRUE
      invoke SetCursor, $invoke(LoadCursor, 0, IDC_ARROW)
    .endif
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Splitter.OnMouseMove
; Purpose:    Event procedure for WM_MOUSEMOVE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax: Zero if handled.

Method Splitter.OnMouseMove, uses xsi, wParam:WPARAM, lParam:LPARAM
  local CursorPos:POINT, WndRect:RECT, PntRect:RECT, EventTrack:TRACKMOUSEEVENT

;  DbgText "Splitter.OnMouseMove"
  SetObject xsi
  .ifBitSet [xsi].dFlags, SPT_FLAG_MOVING
    invoke GetClientRect, [xsi].hParent, addr PntRect   ;Parent client area
    invoke MapWindowPoints, [xsi].hParent, HWND_DESKTOP, addr PntRect, 2
    invoke GetWindowRect, [xsi].hWnd, addr WndRect      ;In Screen coords
    invoke ScreenToClient, [xsi].hWnd, addr WndRect.right ;Get width and height
    PntS2Regs lParam, ecx                               ;Relative to the Splitter client area
    mov CursorPos.x, eax
    mov CursorPos.y, ecx

    .ifBitSet [xsi].dFlags, SPT_FLAG_HORIZONTAL
      .if ecx != [xsi].sdMouseLstPos
        mov [xsi].sdMouseLstPos, ecx
        invoke ClientToScreen, [xsi].hWnd, addr CursorPos
        mov eax, CursorPos.y
        sub eax, [xsi].sdMouseFstPos                    ;eax = left border in screen coords
        mov edx, PntRect.top                            ;edx = limit1 in screen coords
        add edx, [xsi].sdLimit1
        .if sdword ptr eax < edx
          mov eax, edx
        .else
          mov edx, PntRect.bottom                       ;edx = limit2 in screen coords
          sub edx, [xsi].sdLimit2
          sub edx, [xsi].dThickness
          .if sdword ptr eax > edx
            mov eax, edx
          .endif
        .endif
        invoke MoveWindow, [xsi].hWnd, WndRect.left, eax, WndRect.right, WndRect.bottom, FALSE
        .ifBitSet [xsi].dFlags, SPT_FLAG_SEND_WM_SIZE
          invoke SetNewParent, [xsi].hWnd, [xsi].hParent
          Pnt2Reg32 eax, (POINT ptr WndRect.right)
          invoke SendMessage, [xsi].hParent, WM_SIZE, SIZE_RESTORED, 0
          invoke SetNewParent, [xsi].hWnd, HWND_DESKTOP
        .endif
      .endif
    .else
      .if eax != [xsi].sdMouseLstPos
        mov [xsi].sdMouseLstPos, eax
        invoke ClientToScreen, [xsi].hWnd, addr CursorPos
        mov edx, CursorPos.x
        sub edx, [xsi].sdMouseFstPos                    ;edx = left border in screen coords
        mov eax, PntRect.left                           ;eax = limit1 in screen coords
        add eax, [xsi].sdLimit1
        .if sdword ptr edx < eax
          mov edx, eax
        .else
          mov eax, PntRect.right                        ;eax = limit2 in screen coords
          sub eax, [xsi].sdLimit2
          sub eax, [xsi].dThickness
          .if sdword ptr edx > eax
            mov edx, eax
          .endif
        .endif
        invoke MoveWindow, [xsi].hWnd, edx, WndRect.top, WndRect.right, WndRect.bottom, FALSE
        .ifBitSet [xsi].dFlags, SPT_FLAG_SEND_WM_SIZE
          invoke SetNewParent, [xsi].hWnd, [xsi].hParent
          Pnt2Reg32 eax, (POINT ptr WndRect.right)
          invoke SendMessage, [xsi].hParent, WM_SIZE, SIZE_RESTORED, 0
          invoke SetNewParent, [xsi].hWnd, HWND_DESKTOP
        .endif
      .endif
    .endif
  .else
    .ifBitClr [xsi].dFlags, SPT_FLAG_LOCKED or SPT_FLAG_NO_FLIPBOX ;If not locked and has a FlipBox
      mov EventTrack.cbSize, sizeof EventTrack
      mov EventTrack.dwFlags, TME_LEAVE or TME_HOVER
      m2m EventTrack.hwndTrack, [xsi].hWnd, xax
      m2m EventTrack.dwHoverTime, [xsi].dHoverTime, ecx
      invoke TrackMouseEvent, addr EventTrack
    .endif
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Splitter.OnNotify
; Purpose:    Event procedure for WM_NOTIFY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method Splitter.OnNotify, uses xsi, wParam:WPARAM, lParam:LPARAM
  local CntRect:RECT, WndRect:RECT

;  DbgText "Splitter.OnNotify"
  SetObject xsi
  mov xax, lParam                                       ;xax -> NMHDR
  .if xax != NULL
    mov xcx, [xax].NMHDR.hwndFrom
    .if xcx == [xsi].Flipper.hWnd
      .ifBitSet [xax].NMHDR.code, FBN_HIDE_CTRL
        invoke ShowWindow, [xsi].Flipper.hWnd, SW_HIDE
      .else
        invoke ShowWindow, [xsi].Flipper.hWnd, SW_HIDE
        invoke GetWindowRect, [xsi].hWnd, addr WndRect  ;In Screen coords
        invoke ScreenToClient, [xsi].hWnd, addr WndRect.right ;Get width and height
        invoke ScreenToClient, [xsi].hParent, addr WndRect.left ;Get position in parent coords
        invoke GetClientRect, [xsi].hParent, addr CntRect
        mov xax, lParam                                 ;xax -> NMHDR
        mov edx, -1
        .ifBitSet [xsi].dFlags, SPT_FLAG_HORIZONTAL
          mov ecx, CntRect.bottom
          sub ecx, [xsi].sdLimit2
          sub ecx, [xsi].dThickness                     ;edx = Limit2 in parent coords
          .ifBitSet [xax].NMHDR.code, FBN_FRWD_PRESSED
            mov edx, WndRect.top
            .if edx == [xsi].sdLimit1
              .if [xsi].sdLastPos == SPT_NO_POSITION
                mov eax, ecx
              .else
                .ifBitSet [xax].NMHDR.code, FBN_SHFT_PRESSED or FBN_CTRL_PRESSED
                  mov eax, ecx
                .else
                  .if ecx < [xsi].sdLastPos
                    m2m [xsi].sdLastPos, [xsi].sdLimit1, edx
                    mov eax, ecx
                  .else
                    mov eax, [xsi].sdLastPos
                  .endif
                .endif
              .endif
            .else
              .if [xsi].sdLastPos == SPT_NO_POSITION
                m2m [xsi].sdLastPos, WndRect.top, edx
              .endif
              mov eax, ecx
            .endif
            mov WndRect.top, eax
          .elseIfBitSet [xax].NMHDR.code, FBN_BACK_PRESSED
            .if WndRect.top == ecx
              .if [xsi].sdLastPos == SPT_NO_POSITION
                mov eax, [xsi].sdLimit1
              .else
                .ifBitSet [xax].NMHDR.code, FBN_SHFT_PRESSED or FBN_CTRL_PRESSED
                  mov eax, [xsi].sdLimit1
                .else
                  mov edx, [xsi].sdLimit1
                  .if edx > [xsi].sdLastPos
                    mov [xsi].sdLastPos, ecx
                    mov eax, edx
                  .else
                    mov eax, [xsi].sdLastPos
                  .endif
                .endif
              .endif
            .else
              .if [xsi].sdLastPos == SPT_NO_POSITION
                mrm [xsi].sdLastPos, WndRect.top, edx
              .endif
              mov eax, [xsi].sdLimit1
            .endif
            mov WndRect.top, eax
          .endif

        .else
          mov ecx, CntRect.right
          sub ecx, [xsi].sdLimit2
          sub ecx, [xsi].dThickness                     ;edx = Limit2 in parent coords
          .ifBitSet [xax].NMHDR.code, FBN_FRWD_PRESSED
            mov edx, WndRect.left
            .if edx <= [xsi].sdLimit1
              .if [xsi].sdLastPos == SPT_NO_POSITION
                mov eax, ecx
              .else
                .ifBitSet [xax].NMHDR.code, FBN_SHFT_PRESSED or FBN_CTRL_PRESSED
                  mov eax, ecx
                .else
                  .if ecx < [xsi].sdLastPos
                    mrm [xsi].sdLastPos, [xsi].sdLimit1, edx
                    mov eax, ecx
                  .else
                    mov eax, [xsi].sdLastPos
                  .endif
                .endif
              .endif
            .else
              .if [xsi].sdLastPos == SPT_NO_POSITION
                mrm [xsi].sdLastPos, WndRect.left, edx
              .endif
              mov eax, ecx
            .endif
            mov WndRect.left, eax
          .elseIfBitSet [xax].NMHDR.code, FBN_BACK_PRESSED
            .if WndRect.left == ecx
              .if [xsi].sdLastPos == SPT_NO_POSITION
                mov eax, [xsi].sdLimit1
              .else
                .ifBitSet [xax].NMHDR.code, FBN_SHFT_PRESSED or FBN_CTRL_PRESSED
                  mov eax, [xsi].sdLimit1
                .else
                  mov edx, [xsi].sdLimit1
                  .if edx > [xsi].sdLastPos
                    mov [xsi].sdLastPos, ecx
                    mov eax, edx
                  .else
                    mov eax, [xsi].sdLastPos
                  .endif
                .endif
              .endif
            .else
              .if [xsi].sdLastPos == SPT_NO_POSITION
                mrm [xsi].sdLastPos, WndRect.left, edx
              .endif
              mov eax, [xsi].sdLimit1
            .endif
            mov WndRect.left, eax
          .endif

        .endif
        invoke MoveWindow, [xsi].hWnd, WndRect.left, WndRect.top, WndRect.right, WndRect.bottom, \
                           FALSE
        ;Force parent window to resize children
        invoke GetWindowRect, [xsi].hParent, addr WndRect
        mov eax, WndRect.left
        sub WndRect.right, eax
        mov eax, WndRect.top
        sub WndRect.bottom, eax
        Pnt2Reg32 eax, (POINT ptr WndRect.right)
        invoke SendMessage, [xsi].hParent, WM_SIZE, SIZE_RESTORED, eax
      .endif
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Splitter.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero (handled).

Method Splitter.OnPaint, uses xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, ClientRect:RECT, hPrvBrush:HBRUSH, hPrvPen:HPEN

;  DbgText "Splitter.OnPaint"
  SetObject xsi
  invoke BeginPaint, [xsi].hWnd, addr PS
  invoke GetClientRect, [xsi].hWnd, addr ClientRect
  .ifBitSet [xsi].dFlags, SPT_FLAG_MOVING
    mov hPrvBrush, $invoke(SelectObject, PS.hdc, $invoke(GetSysColorBrush, [xsi].dMoveSysBrush))
    invoke GetSysColor, [xsi].dMoveSysColor
    invoke SelectObject, PS.hdc, $invoke(CreatePen, PS_SOLID or PS_INSIDEFRAME, 1, eax)
    mov hPrvPen, xax
    invoke Rectangle, PS.hdc, ClientRect.left, ClientRect.top, ClientRect.right, ClientRect.bottom
    invoke DeleteObject, $invoke(SelectObject, PS.hdc, hPrvPen)
    invoke SelectObject, PS.hdc, hPrvBrush
  .else
    invoke SendMessage, [xsi].hParent, WM_CTLCOLORSTATIC, 0, 0    ;xax = Brush HANDLE
    invoke FillRect, PS.hdc, addr ClientRect, xax
  .endif
  invoke EndPaint, [xsi].hWnd, addr PS
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Splitter.OnSetCursor
; Purpose:    Event procedure for WM_SETCURSOR message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = TRUE to halt further processing or FALSE to continue.

Method Splitter.OnSetCursor,, wParam:WPARAM, lParam:LPARAM
;  DbgText "Splitter.OnSetCursor"
  and lParam, 0FFFF0000h
  .if lParam != 0
    SetObject xax
    .ifBitClr [xax].dFlags, SPT_FLAG_LOCKED
      mov xax, [xax].$Obj(Splitter).hCursor
    .else
      invoke LoadCursor, 0, IDC_ARROW
    .endif
    invoke SetCursor, xax
    mov eax, TRUE
  .else
    xor eax, eax
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Splitter.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Splitter.OnSize, uses xsi, wParam:WPARAM, lParam:LPARAM
  local WndRect:RECT

  SetObject xsi
  invoke GetWindowRect, [xsi].hWnd, addr WndRect
  .ifBitSet [xsi].dFlags, SPT_FLAG_HORIZONTAL
    mov eax, WndRect.bottom
    sub eax, WndRect.top
  .else
    mov eax, WndRect.right
    sub eax, WndRect.left
  .endif
  mov [xsi].dThickness, eax                             ;Store thickness
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Splitter.Startup
; Purpose:    Register the object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method Splitter.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, 0
  mrm WC.lpfnWndProc, $MethodAddr(Splitter.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  mrm WC.hInstance, hInstance, xax
  m2z WC.hbrBackground
  m2z WC.lpszMenuName
  mrm WC.lpszClassName, offset szSplitter, xax
  m2z WC.hIcon
  m2z WC.hIconSm
  m2z WC.hCursor
  invoke RegisterClassEx, addr WC
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:   	Splitter.Store
; Purpose:  	Store the streamable instance in a stream object. Descendant objects should redefine
;           	this method and store new members.
; Arguments:	Arg1: -> Stream object.
; Return:   	Nothing.

Method Splitter.Store, uses xsi, pStream:$ObjPtr(Stream)
  local WP:WINDOWPLACEMENT

  SetObject xsi
  ACall xsi.Store, pStream                              ;Store pSelf, ..., hWnd

  OCall pStream::Stream.BinWrite32, [xsi].dFlags
  OCall pStream::Stream.BinWrite32, [xsi].dHoverTime
  OCall pStream::Stream.BinWrite32, [xsi].dThickness
  OCall pStream::Stream.BinWriteX, [xsi].hParent
  OCall pStream::Stream.BinWrite32, [xsi].sdMouseFstPos
  OCall pStream::Stream.BinWrite32, [xsi].sdMouseLstPos
  OCall pStream::Stream.BinWrite32, [xsi].sdLastPos
  OCall pStream::Stream.BinWrite32, [xsi].sdLimit1
  OCall pStream::Stream.BinWrite32, [xsi].sdLimit2
  OCall [xsi].Flipper::FlipBox.Store, pStream

  mov WP.length_, sizeof WP
  invoke GetWindowPlacement, [xsi].hWnd, addr WP
  OCall pStream::Stream.BinWrite, addr WP, sizeof WP
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Splitter.WindowProc
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.
;             Window HANDLE is passed in pSelf (hidden parameter).

Method Splitter.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg,, "Splitter"
  .if uMsg == WM_NCCREATE
    mov xax, lParam
    mov xsi, [xax].CREATESTRUCT.lpCreateParams
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

endif
