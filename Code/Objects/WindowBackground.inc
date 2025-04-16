; ==================================================================================================
; Title:      WindowBackground.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of WindowBackground objects.
;             It optimizes the drawing of the window background in the client area.
;             It excludes the RECTs used by the child windows to avoid repetitive drawing over
;             the same area resulting in unwanted flicker.
; Notes:      Version C.1.0, Mai 2021
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Object:  WindowBackground
; Purpose: Implement an object that manages a collection of RECT structures that are used to draw
;          the window client area efficiently and without noticeable flicker.
; Usage:   1. Call the Init constructor after getting the window HANDLE.
;          2. Call the Update method every time the client window has changed, usually when
;             responding to a WM_SIZE message.
;          3. Return nonzero when reponding to a WM_ERASEBKGND message.
;          4. Use the Paint method to paint the background, usually when responding to a
;             WM_PAINT message.
; Note:    The fragmentation of rectangles can be reduced by trying to reconnect adjacent
;          rectangles. In most cases, this process is more expensive than the gain in performance.

Object WindowBackground, WindowBackgroundID, DataCollection
  RedefineMethod    Init,             POINTER, HWND
  VirtualMethod     ExcludeRect,      PRECT
  VirtualMethod     ExcludeChild,     HWND
  VirtualMethod     Paint,            HDC, HBRUSH
  VirtualMethod     Update

  DefineVariable    hWnd,       HWND,   0       ;Main window HANDLE
  DefineVariable    WndOffset,  POINT,  {}      ;Client to Screen offset
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     WindowBackground.Init
; Purpose:    Constructor.
; Arguments:  Arg1: -> Owner.
;             Arg2: Main window HANDLE.
; Return:     Nothing.

Method WindowBackground.Init,, pOwner:POINTER, hWnd:HWND
  ;DbgText "WindowBackground.Init"
  SetObject xcx
  m2m [xcx].hWnd, hWnd, xax
  ACall xcx.Init, pOwner, 9, 8, COL_MAX_CAPACITY
MethodEnd

; --------------------------------------------------------------------------------------------------
; Procedure:  _WB_ExcludeRect_
; Purpose:    ForEach interator procedure. It excludes a RECT from the collection, splitting
;             existing RECTs as needed.
; Arguments:  Arg1: -> RECT to compare with.
;             Arg2: -> RECT to exclude.
;             Arg3: -> WindowBackground instance.
; Return:     Nothing.
;
;     -------------------
;    |         1         |        1: Top RECT
;    |-------------------|        2: Left RECT
;    |   |           |   |        3: Right RECT
;    | 2 |  ExcRect  | 3 |        4: Bottom RECT
;    |   |           |   |
;    |-------------------|        Note: Slitting is done in such a way that the new RECTs as
;    |         4         |              wide as possible => accelerate drawing
;     -------------------


_WB_ExcludeRect_ proc uses xbx, pSrcRect:PRECT, pExcRect:PRECT, pSelf:$ObjPtr(WindowBackground)
  local IscRect:RECT                                    ;Intersection between SrcRect and ExcRect
  local pRectL:PRECT, pRectT:PRECT, pRectR:PRECT, pRectB:PRECT

  mov xbx, pSrcRect
  mov xcx, pExcRect
  mov IscRect.top, $sMax([xbx].RECT.top, [xcx].RECT.top, eax)
  sMin [xbx].RECT.bottom, [xcx].RECT.bottom, edx
  .if SDWORD ptr eax < edx
    mov IscRect.bottom, edx
    mov IscRect.left, $sMax([xbx].RECT.left, [xcx].RECT.left, eax)
    sMin [xbx].RECT.right, [xcx].RECT.right, edx
    .if SDWORD ptr eax < edx
      mov IscRect.right, edx
      xor edx, edx
      mov pRectL, xdx
      mov pRectT, xdx
      mov pRectR, xdx
      mov pRectB, xdx
      mov eax, IscRect.top
      .if eax != [xbx].RECT.top
        ;Create top rectangle
        MemAlloc sizeof(RECT)
        .if xax != NULL
          mov pRectT, xax
          m2m [xax].RECT.left, [xbx].RECT.left, edx
          m2m [xax].RECT.top, [xbx].RECT.top, ecx
          m2m [xax].RECT.right, [xbx].RECT.right, edx
          m2m [xax].RECT.bottom, IscRect.top, ecx
        .endif
      .endif

      mov eax, IscRect.bottom
      .if eax != [xbx].RECT.bottom
        ;Create bottom rectangle
        MemAlloc sizeof(RECT)
        .if xax != NULL
          mov pRectB, xax
          m2m [xax].RECT.left, [xbx].RECT.left, edx
          m2m [xax].RECT.top, IscRect.bottom, ecx
          m2m [xax].RECT.right, [xbx].RECT.right, edx
          m2m [xax].RECT.bottom, [xbx].RECT.bottom, ecx
        .endif
      .endif

      mov eax, IscRect.left
      .if eax != [xbx].RECT.left
        ;Create left rectangle
        MemAlloc sizeof(RECT)
        .if xax != NULL
          mov pRectL, xax
          m2m [xax].RECT.left, [xbx].RECT.left, edx
          m2m [xax].RECT.top, IscRect.top, ecx
          m2m [xax].RECT.right, IscRect.left, edx
          m2m [xax].RECT.bottom, IscRect.bottom, ecx
        .endif
      .endif

      mov eax, IscRect.right
      .if eax != [xbx].RECT.right
        ;Create right rectangle
        MemAlloc sizeof(RECT)
        .if xax != NULL
          mov pRectR, xax
          m2m [xax].RECT.left, IscRect.right, edx
          m2m [xax].RECT.top, IscRect.top, ecx
          m2m [xax].RECT.right, [xbx].RECT.right, edx
          m2m [xax].RECT.bottom, IscRect.bottom, ecx
        .endif
      .endif

      ;Replace SrcRect with the first new rectangle and insert the rest.
      ;Note: new inserted RECTs are not processed by the current ForEach call!
      .if pRectL != NULL
        mov xax, pRectL
        s2s RECT ptr [xbx], RECT ptr [xax], xcx, xdx, xmm0
        MemFree pRectL
        jmp .TopRect
      .endif
      .if pRectT != NULL
        mov xax, pRectT
        s2s RECT ptr [xbx], RECT ptr [xax], xcx, xdx, xmm0
        MemFree pRectT
        jmp .RightRect
      .endif
      .if pRectR != NULL
        mov xax, pRectR
        s2s RECT ptr [xbx], RECT ptr [xax], xcx, xdx, xmm0
        MemFree pRectR
        jmp .BottomRect
      .endif
      .if pRectB != NULL
        mov xax, pRectB
        s2s RECT ptr [xbx], RECT ptr [xax], xcx, xdx, xmm0
        MemFree pRectB
      .endif
      ret

    .TopRect:
      .if pRectT != NULL
        OCall pSelf::WindowBackground.Insert, pRectT
      .endif
    .RightRect:
      .if pRectR != NULL
        OCall pSelf::WindowBackground.Insert, pRectR
      .endif
    .BottomRect:
      .if pRectB != NULL
        OCall pSelf::WindowBackground.Insert, pRectB
      .endif
    .endif
  .endif
  ret
_WB_ExcludeRect_ endp

; --------------------------------------------------------------------------------------------------
; Method:     WindowBackground.ExcludeRect
; Purpose:    Exclude RECT in client coords from the window client background.
; Arguments:  Arg1: -> RECT to exclude.
; Return:     Nothing.

Method WindowBackground.ExcludeRect,, pRect:PRECT
  ;DbgText "WindowBackground.ExcludeRect"
  OCall pSelf::WindowBackground.ForEach, offset _WB_ExcludeRect_, pRect, pSelf
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     WindowBackground.ExcludeChild
; Purpose:    Exclude the child window RECT from the window client background.
; Arguments:  Arg1: HANDLE of the Child window to exclude.
; Return:     Nothing.

Method WindowBackground.ExcludeChild,, hExcWnd:HWND
  local ExcRect:RECT

  ;DbgText "WindowBackground.ExcludeChild"
  invoke GetWindowRect, hExcWnd, addr ExcRect
  ;Convert the coordiantes to client values
  mov xax, pSelf
  mov ecx, [xax].$Obj(WindowBackground).WndOffset.x
  mov edx, [xax].$Obj(WindowBackground).WndOffset.y
  sub ExcRect.left, ecx
  sub ExcRect.top, edx
  sub ExcRect.right, ecx
  sub ExcRect.bottom, edx

  OCall pSelf::WindowBackground.ForEach, offset _WB_ExcludeRect_, addr ExcRect, pSelf
MethodEnd

; --------------------------------------------------------------------------------------------------
; Procedure:  _WB_PaintRect_
; Purpose:    ForEach interator procedure. It fills a RECT using the passed brush.
; Arguments:  Arg1: -> RECT to fill.
;             Arg2: Device Context HANDLE.
;             Arg3: Brush HANDLE.
; Return:     Nothing.

_WB_PaintRect_ proc pRect:PRECT, hDC:HDC, hBrush:HBRUSH
  invoke FillRect, hDC, pRect, hBrush
  ret
_WB_PaintRect_ endp

; --------------------------------------------------------------------------------------------------
; Method:     WindowBackground.Paint
; Purpose:    Fill the RECT collection using the hDC and hBrush.
; Arguments:  Arg1: Device Context HANDLE.
;             Arg2: Brush HANDLE.
; Return:     Nothing.

Method WindowBackground.Paint,, hDC:HDC, hBrush:HBRUSH
  ;DbgText "WindowBackground.Paint"
  OCall pSelf::WindowBackground.ForEach, offset _WB_PaintRect_, hDC, hBrush
MethodEnd

; --------------------------------------------------------------------------------------------------
; Procedure:  _WB_EnumChildren_
; Purpose:    EnumChildWindows callback procedure. It excludes a child window from window
;             client background,
; Arguments:  Arg1: HANDLE of the window to exclude.
;             Arg2: -> WindowBackground instance.
; Return:     eax = TRUE => Continue enumeration.

_WB_EnumChildren_ proc hWnd:HWND, pSelf:$ObjPtr(WindowBackground)
  OCall pSelf::WindowBackground.ExcludeChild, hWnd
  mov eax, TRUE
  ret
_WB_EnumChildren_ endp

; --------------------------------------------------------------------------------------------------
; Method:     WindowBackground.Update
; Purpose:    Updates the internal data accorting to the current positions and sizes of all
;             child windows.
; Arguments:  None.
; Return:     Nothing.

Method WindowBackground.Update, uses xsi
  ;DbgText "WindowBackground.Update"
  SetObject xsi
  OCall xsi.DisposeAll

  ;Get the new client to screen offset, used by the ExcludeChild method
  m2z [xsi].WndOffset.x
  m2z [xsi].WndOffset.y
  invoke ClientToScreen, [xsi].$Obj(WindowBackground).hWnd, addr [xsi].WndOffset

  ;Get the initial RECT = client RECT.
  MemAlloc sizeof(RECT), HEAP_ZERO_MEMORY
  .if xax != NULL
    OCall xsi.Insert, xax
    invoke GetClientRect, [xsi].hWnd, xax
    .if eax != 0
      invoke EnumChildWindows, [xsi].hWnd, offset _WB_EnumChildren_, xsi
    .endif
  .endif
MethodEnd

endif
