; ==================================================================================================
; Title:      Magnetism.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of magnetic windows.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


MAG_SNAP_X  equ   BIT00
MAG_SNAP_Y  equ   BIT01

; --------------------------------------------------------------------------------------------------
; Object:     Magnetism
; Purpose:    Implement a magnetic snapping property for MDI child windows to stick them when
;             moveing or resizing while the SHIFT key is pressed. The windows snaps to any border
;             that comes into a snap range called intensity.

Object Magnetism, MagnetismID, MsgInterceptor
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, HWND, DWORD
  RedefineMethod    WndProc,            DWORD, WPARAM, LPARAM

  VirtualEvent      OnEnterSizeMove,    WM_ENTERSIZEMOVE
  VirtualEvent      OnExitSizeMove,     WM_EXITSIZEMOVE
  VirtualEvent      OnMoving,           WM_MOVING
  VirtualEvent      OnSizing,           WM_SIZING

  DefineVariable    dIntensity,         DWORD,      0
  DefineVariable    pBoundingRect,      POINTER,    NULL
  DefineVariable    dSnappedBorder,     DWORD,      0
  DefineVariable    dDeltaX,            SDWORD,     0
  DefineVariable    dDeltaY,            SDWORD,     0

  Embed RectColl, DataCollection
ObjectEnd


; ==================================================================================================

if IMPLEMENT

CStr szMagnetism, "Magnetism"

; ==================================================================================================
;    Auxiliary procedures
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Procedure:  Magnetism_AddMonitorRects
; Purpose:    Add monitor Rect and Workarea to Rect-Collection.
; Arguments:  Arg1: Monitor handle.
;             Arg2: Monitor DC handle.
;             Arg3: -> RECT structure.
;             Arg4: -> Magnetism object instance.
; Return:     Nothing.

Magnetism_AddMonitorRects proc uses xbx xsi hMon:HANDLE, hMonDC:HDC, pMonRect:POINTER, \
                                            pObject:POINTER
  local MI:MONITORINFO

  SetObject xsi, Magnetism, pObject
  mov MI.cbSize, sizeof MONITORINFO
  invoke GetMonitorInfo, hMon, addr MI

  mov xbx, $MemAlloc(sizeof RECT)
  invoke MemClone, xbx, addr MI.rcMonitor, sizeof RECT
  OCall [xsi].RectColl::DataCollection.Insert, xbx

  invoke EqualRect, addr MI.rcMonitor, addr MI.rcWork
  .if eax == FALSE
    mov xbx, $MemAlloc(sizeof RECT)
    invoke MemClone, xbx, addr MI.rcWork, sizeof RECT
    OCall [xsi].RectColl::DataCollection.Insert, xbx
  .endif

  ReleaseObject
  ret
Magnetism_AddMonitorRects endp

; --------------------------------------------------------------------------------------------------
; Procedure:  Magnetism_SnapXXX
; Purpose:    Compute XXX border distance to other borders stored in the Rect-Collection.
; Arguments:  Arg1: -> RECT structure.
;             Arg2: -> Object instance.
; Return:     Nothing.

CheckBorder macro BorderType:req, Border1:req, Border2:req, Border3:req, Border4:req
  mov xax, [xsi].pBoundingRect
  mov ecx, [xax].RECT.Border1
  mov xdx, pRect
  sub ecx, [xdx].RECT.Border2

  mov eax, ecx
  .if SDWORD ptr eax < 0          ;Calc eax = abs(ecx)
    not eax
  .endif

  @CatStr(<mov edx, [xsi].dDelta>, BorderType)
  .if SDWORD ptr edx < 0          ;Calc edx = abs(xbx)
    not edx
  .endif

  .if eax <= edx
    mov xax, [xsi].pBoundingRect
    mov eax, [xax].RECT.Border3
    mov xdx, pRect
    .if SDWORD ptr eax <= [xdx].RECT.Border4
      mov xax, [xsi].pBoundingRect
      mov eax, [xax].RECT.Border4
      .if SDWORD ptr eax >= [xdx].RECT.Border3
        @CatStr(<mov [xsi].dDelta>, BorderType, <, ecx>)
        @CatStr(<BitSet [xsi].dSnappedBorder, MAG_SNAP_>, BorderType)
      .endif
    .endif
  .endif
endm

Magnetism_SnapLeft proc uses xsi pRect:POINTER, pObject:POINTER
  SetObject xsi, Magnetism, pObject
  CheckBorder X, left, left, top, bottom
  CheckBorder X, left, right, top, bottom
  ReleaseObject
  ret
Magnetism_SnapLeft endp

Magnetism_SnapRight proc uses xsi pRect:POINTER, pObject:POINTER
  SetObject xsi, Magnetism, pObject
  CheckBorder X, right, left, top, bottom
  CheckBorder X, right, right, top, bottom
  ReleaseObject
  ret
Magnetism_SnapRight endp

Magnetism_SnapTop proc uses xsi pRect:POINTER, pObject:POINTER
  SetObject xsi, Magnetism, pObject
  CheckBorder Y, top, top, left, right
  CheckBorder Y, top, bottom, left, right
  ReleaseObject
  ret
Magnetism_SnapTop endp

Magnetism_SnapBottom proc uses xsi pRect:POINTER, pObject:POINTER
  SetObject xsi, Magnetism, pObject
  CheckBorder Y, bottom, top, left, right
  CheckBorder Y, bottom, bottom, left, right
  ReleaseObject
  ret
Magnetism_SnapBottom endp



; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     Magnetism.Done
; Purpose:    Finalize the Magnetism object.
; Arguments:  None.
; Return:     Nothing.

Method Magnetism.Done
  SetObject xcx
  OCall [xcx].RectColl::DataCollection.Done
  ACall Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Magnetism.Init
; Purpose:    Initialize the Magnetism object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: HANDLE of a window to make magnetic.
;             Arg3: Magnetism intensity in pixel.
; Return:     Nothing.

Method Magnetism.Init, uses xsi, pOwner:POINTER, hWnd:HWND, dIntensity:DWORD
  SetObject xsi
  ACall xsi.Init, pOwner, hWnd, offset szMagnetism
  m2m [xsi].dIntensity, dIntensity, eax
  OCall [xsi].RectColl::DataCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Magnetism.OnEnterSizeMove
; Purpose:    Event procedure for WM_ENTERSIZEMOVE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Magnetism.OnEnterSizeMove, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local hWnd:HWND, hParent:HWND

  SetObject xsi
  mov hWnd, $invoke(GetWindow, [xsi].hWnd, GW_HWNDFIRST)
  .if xax != 0
    invoke GetWindowLongPtr, hWnd, GWL_EXSTYLE
    .ifBitSet eax, WS_EX_MDICHILD
      ;Add Mdi-Client rect
      mov xbx, $MemAlloc(sizeof RECT)
      mov hParent, $invoke(GetParent, hWnd)
      invoke GetClientRect, hParent, xbx
      invoke ClientToScreen, hParent, addr [xbx].RECT.left
      invoke ClientToScreen, hParent, addr [xbx].RECT.right
      OCall [xsi].RectColl::DataCollection.Insert, xbx
    .else
      ;Add monitor rect and workarea
      invoke EnumDisplayMonitors, 0, 0, offset Magnetism_AddMonitorRects, xsi
    .endif
    mov xax, hWnd

    ;Add windows at the same Z-order
    .while xax != 0
      mov hWnd, xax
      .if xax != [xsi].hWnd
        invoke GetWindowLongPtr, hWnd, GWL_STYLE
        .ifBitSet xax, (WS_VISIBLE or WS_BORDER)   ;Window must be visible and have a border
          mov xbx, $MemAlloc(sizeof RECT)
          invoke GetWindowRect, hWnd, xbx
          invoke IsRectEmpty, xbx
          .if eax == TRUE
            MemFree xbx
          .else
            invoke GetWindowTextLength, hWnd
            .if eax == 0
              MemFree xbx
            .else
              invoke IsWindowVisible, hWnd
              .if eax == TRUE
                OCall [xsi].RectColl::DataCollection.Insert, xbx
              .else
                MemFree xbx
              .endif
            .endif
          .endif
        .endif
      .endif
      invoke GetWindow, hWnd, GW_HWNDNEXT
    .endw
  .endif
  invoke CallWindowProc, [xsi].pPrevWndProc, [xsi].hWnd, WM_ENTERSIZEMOVE, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Magnetism.OnExitSizeMove
; Purpose:    Event procedure for WM_EXITSIZEMOVE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Magnetism.OnExitSizeMove, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  OCall [xsi].RectColl::DataCollection.DisposeAll
  invoke CallWindowProc, [xsi].pPrevWndProc, [xsi].hWnd, WM_EXITSIZEMOVE, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Magnetism.OnMoving
; Purpose:    Event procedure for WM_MOVING message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Magnetism.OnMoving, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke GetKeyState, VK_SHIFT
  .ifBitSet eax, BIT07
    mrm [xsi].pBoundingRect, lParam, xax
    mov eax, [xsi].dIntensity
    m2z [xsi].dSnappedBorder
    mov [xsi].dDeltaX, eax
    mov [xsi].dDeltaY, eax
    lea xbx, [xsi].RectColl
    OCall xbx::DataCollection.ForEach, offset Magnetism_SnapLeft, xsi, NULL
    OCall xbx::DataCollection.ForEach, offset Magnetism_SnapRight, xsi, NULL
    OCall xbx::DataCollection.ForEach, offset Magnetism_SnapTop, xsi, NULL
    OCall xbx::DataCollection.ForEach, offset Magnetism_SnapBottom, xsi, NULL
    mov xdx, lParam
    .ifBitSet [xsi].dSnappedBorder, MAG_SNAP_X
      mov eax, [xsi].dDeltaX
      sub [xdx].RECT.left, eax
      sub [xdx].RECT.right, eax
    .endif
    .ifBitSet [xsi].dSnappedBorder, MAG_SNAP_Y
      mov eax, [xsi].dDeltaY
      sub [xdx].RECT.top, eax
      sub [xdx].RECT.bottom, eax
    .endif
  .endif
  invoke CallWindowProc, [xsi].pPrevWndProc, [xsi].hWnd, WM_MOVING, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Magnetism.OnSizing
; Purpose:    Event procedure for WM_SIZING message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Magnetism.OnSizing, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke GetKeyState, VK_SHIFT
  .ifBitSet eax, BIT07
    mrm [xsi].pBoundingRect, lParam, xax
    mov eax, [xsi].dIntensity
    m2z [xsi].dSnappedBorder
    mov [xsi].dDeltaX, eax
    mov [xsi].dDeltaY, eax

    .if (wParam == WMSZ_LEFT) || (wParam == WMSZ_TOPLEFT) || (wParam == WMSZ_BOTTOMLEFT)
      OCall [xsi].RectColl::DataCollection.ForEach, offset Magnetism_SnapLeft, xsi, NULL
      .ifBitSet [xsi].dSnappedBorder, MAG_SNAP_X
        mov xdx, lParam
        mov eax, [xsi].dDeltaX
        sub [xdx].RECT.left, eax
      .endif
    .endif

    .if (wParam == WMSZ_RIGHT) || (wParam == WMSZ_TOPRIGHT) || (wParam == WMSZ_BOTTOMRIGHT)
      OCall [xsi].RectColl::DataCollection.ForEach, offset Magnetism_SnapRight, xsi, NULL
      .ifBitSet [xsi].dSnappedBorder, MAG_SNAP_X
        mov xdx, lParam
        mov eax, [xsi].dDeltaX
        sub [xdx].RECT.right, eax
      .endif
    .endif

    .if (wParam == WMSZ_TOP) || (wParam == WMSZ_TOPLEFT) || (wParam == WMSZ_TOPRIGHT)
      OCall [xsi].RectColl::DataCollection.ForEach, offset Magnetism_SnapTop, xsi, NULL
      .ifBitSet [xsi].dSnappedBorder, MAG_SNAP_Y
        mov xdx, lParam
        mov eax, [xsi].dDeltaY
        sub [xdx].RECT.top, eax
      .endif
    .endif

    .if (wParam == WMSZ_BOTTOM) || (wParam == WMSZ_BOTTOMLEFT) || (wParam == WMSZ_BOTTOMRIGHT)
      OCall [xsi].RectColl::DataCollection.ForEach, offset Magnetism_SnapBottom, xsi, NULL
      .ifBitSet [xsi].dSnappedBorder, MAG_SNAP_Y
        mov xdx, lParam
        mov eax, [xsi].dDeltaY
        sub [xdx].RECT.bottom, eax
      .endif
    .endif
  .endif
  invoke CallWindowProc, [xsi].pPrevWndProc, [xsi].hWnd, WM_SIZING, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Magnetism.WndProc
; Purpose:    Processing of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.
; Note:       Window handle is passed in pSelf (hidden parameter).

Method Magnetism.WndProc,, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  invoke GetProp, pSelf, offset szMagnetism
  OCall xax::MsgInterceptor.Dispatch, pSelf, uMsg, wParam, lParam
MethodEnd

endif
