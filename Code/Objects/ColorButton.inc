; ==================================================================================================
; Title:      ColorButton.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of Color selection button objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Object:  ColorButton
; Purpose: Implement a color selection button showing the selection on  its surface.

Object ColorButton, ColorButtonID, Button
  RedefineMethod    Init,           POINTER, HWND, PDEF_BUTTON
  RedefineMethod    OnCreate,       WPARAM, LPARAM
  RedefineMethod    OnDestroy,      WPARAM, LPARAM
  RedefineMethod    OnLButtonDown,  WPARAM, LPARAM
  RedefineMethod    OnLButtonUp,    WPARAM, LPARAM
  RedefineMethod    OnPaint,        WPARAM, LPARAM
  StaticMethod      Startup
  RedefineMethod    WndProc,        DWORD, WPARAM, LPARAM

  VirtualEvent      OnSetColor,     BM_SETCOLOR
  VirtualEvent      OnGetColor,     BM_GETCOLOR

  DefineVariable    Color,          COLORREF,       $RGB(000,000,255)
ObjectEnd


; ==================================================================================================

if IMPLEMENT

CStr szColorButton, "ColorButton"

; --------------------------------------------------------------------------------------------------
; Method:     ColorButton.Init
; Purpose:    Initialize the ColorButton object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> DEF_BUTTON definition structure.
; Return:     Nothing.

Method ColorButton.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND, pDefStruc:PDEF_BUTTON
  SetObject xsi
  mov xbx, pDefStruc
  assume xbx:PDEF_BUTTON
  mov eax, [xbx].dStyle
  or eax, WS_CHILD or WS_VISIBLE or WS_TABSTOP
  invoke CreateWindowEx, [xbx].dExStyle, offset(szColorButton), [xbx].pTitle, \
                         eax, [xbx].sdPosX, [xbx].sdPosY, [xbx].dWidth, [xbx].dHeight, \
                         hParent, [xbx].xCtlID, hInstance, pSelf
  assume xbx:NOTHING

  ACall xsi.Init, pOwner, xax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ColorButton.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero to continue creation of the window, else -1.

Method ColorButton.OnCreate, uses xsi, wParam:WPARAM, lParam:LPARAM
  local hDC:HDC, hParent:HWND

  ;DbgText "ColorButton.OnCreate"
  SetObject xsi
  mov xax, lParam
  mov [xsi].pTextBuffer, $invoke(StrNew, [xax].CREATESTRUCT.lpszName)
  invoke GetClientRect, [xsi].hWnd, addr [xsi].FaceRect
  invoke MemClone, addr [xsi].IconRect, addr [xsi].FaceRect, sizeof(RECT)
  invoke MemClone, addr [xsi].TextRect, addr [xsi].FaceRect, sizeof(RECT)

  m2m [xsi].IconRect.right, [xsi].IconRect.bottom, xdx
  m2m [xsi].TextRect.left, [xsi].IconRect.right, xdx
  GrowRect [xsi].TextRect, -4

  mov hParent, $invoke(GetParent, [xsi].hWnd)
  mov hDC, $invoke(GetDC, hParent)
  mov [xsi].hMemDC, $invoke(CreateCompatibleDC, hDC)
  invoke CreateCompatibleBitmap, hDC, [xsi].FaceRect.right, [xsi].FaceRect.bottom
  mov [xsi].hMemBmp, xax
  invoke ReleaseDC, hParent, hDC
  mov [xsi].hPrevBmp, $invoke(SelectObject, [xsi].hMemDC, [xsi].hMemBmp)
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ColorButton.OnDestroy
; Purpose:    Event procedure for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method ColorButton.OnDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke DeleteObject, $invoke(SelectObject, [xsi].hMemDC, [xsi].hPrevBmp)
  invoke DeleteDC, [xsi].hMemDC
  invoke SetWindowLong, [xsi].hWnd, GWL_USERDATA, NULL
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ColorButton.OnLButtonDown
; Purpose:    Event procedure for WM_LBUTTONDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method ColorButton.OnLButtonDown, uses xsi, wParam:WPARAM, lParam:LPARAM
  local Pnt:POINT

  SetObject xsi
  .ifBitClr [xsi].dFlags, BTF_DISABLED
    PntS2Pnt Pnt, lParam
    .if $invoke(PtInRect, addr [xsi].IconRect, Pnt) != FALSE
      invoke SetFocus, [xsi].hWnd
      BitSet [xsi].dFlags, (BTF_PRESSED or BTF_FOCUSED)
      BitClr [xsi].dFlags, BTF_HOVERED
      invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
    .endif
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ColorButton.OnLButtonUp
; Purpose:    Event procedure for WM_LBUTTONUP message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method ColorButton.OnLButtonUp, uses xsi, wParam:WPARAM, lParam:LPARAM
  local Pnt:POINT, hParent:HWND

  SetObject xsi
  .ifBitClr [xsi].dFlags, BTF_DISABLED
    PntS2Pnt Pnt, lParam
    .ifBitSet [xsi].dFlags, BTF_PRESSED
      BitClr [xsi].dFlags, (BTF_PRESSED or BTF_HOVERED)
      .if $invoke(PtInRect, addr [xsi].FaceRect, Pnt) != FALSE
        .if $invoke(PtInRect, addr [xsi].IconRect, Pnt) != FALSE
          mov hParent, $invoke(GetParent, [xsi].hWnd)
          invoke GetWindowLongPtr, [xsi].hWnd, GWLP_ID
          invoke SendMessage, hParent, WM_COMMAND, eax, [xsi].hWnd
        .endif
      .else
        invoke ReleaseCapture
      .endif
      invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
    .endif
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ColorButton.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method ColorButton.OnPaint, uses xdi xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, hPrevBrush:HBRUSH, PrevColor:COLORREF, dPrevBackMode:DWORD, Rct:RECT

  SetObject xsi
  invoke GetParent, [xsi].hWnd
  invoke SendMessage, xax, WM_CTLCOLORSTATIC, [xsi].hMemDC, [xsi].hWnd
  invoke FillRect, [xsi].hMemDC, addr [xsi].FaceRect, xax

  .ifBitSet [xsi].dFlags, BTF_HOVERED
    invoke DrawEdge, [xsi].hMemDC, addr [xsi].IconRect, BDR_RAISEDINNER, BF_RECT or BF_MIDDLE
  .elseIfBitSet [xsi].dFlags, BTF_PRESSED
    invoke DrawEdge, [xsi].hMemDC, addr [xsi].IconRect, BDR_SUNKENOUTER, BF_RECT or BF_MIDDLE
  .endif

  invoke GetClassLongPtr, [xsi].hWnd, GCL_HICON
  mov edi, [xsi].IconRect.bottom
  sub edi, 16
  shr edi, 1
  .ifBitSet [xsi].dFlags, BTF_PRESSED
    inc edi
  .endif
  invoke DrawIconEx, [xsi].hMemDC, edi, edi, xax, 16, 16, 0, 0, DI_NORMAL
  invoke CreateSolidBrush, [xsi].Color
  mov hPrevBrush, $invoke(SelectObject, [xsi].hMemDC, xax)
  add edi, 8                                            ;Move to the center of the 16x16 icon
  invoke FloodFill, [xsi].hMemDC, edi, edi, $RGB(000,000,000)
  invoke DeleteObject, $invoke(SelectObject, [xsi].hMemDC, hPrevBrush)

  mov xax, [xsi].pTextBuffer
  .if (xax != NULL) && (BYTE ptr [xax] != 0)
    mov dPrevBackMode, $32($invoke(SetBkMode, [xsi].hMemDC, TRANSPARENT))
    .ifBitClr [xsi].dFlags, BTF_DISABLED
      ;Enabled
      invoke GetSysColor, COLOR_WINDOWTEXT
      mov PrevColor, $32($invoke(SetTextColor, [xsi].hMemDC, eax))
      invoke DrawTextEx, [xsi].hMemDC, [xsi].pTextBuffer, -1, \
                         addr [xsi].TextRect, DT_LEFT or DT_VCENTER or DT_SINGLELINE, NULL
      .ifBitSet [xsi].dFlags, BTF_FOCUSED
        invoke MemClone, addr Rct, addr [xsi].TextRect, sizeof(RECT)
        invoke DrawTextEx, [xsi].hMemDC, [xsi].pTextBuffer, -1, \
               addr Rct, DT_CALCRECT or DT_LEFT or DT_VCENTER or DT_SINGLELINE, NULL
        GrowRect Rct, 3, 1
        invoke DrawFocusRect, [xsi].hMemDC, addr Rct
      .endif
    .else
      ;Disabled
      invoke GetSysColor, COLOR_BTNHILIGHT
      mov PrevColor, $32($invoke(SetTextColor, [xsi].hMemDC, eax))
      MoveRect [xsi].TextRect, 1
      invoke DrawTextEx, [xsi].hMemDC, [xsi].pTextBuffer, -1, \
                     addr [xsi].TextRect, DT_LEFT or DT_VCENTER or DT_SINGLELINE, NULL
      MoveRect [xsi].TextRect, -1
      invoke SetTextColor, [xsi].hMemDC, $32($invoke(GetSysColor, COLOR_BTNSHADOW))
      invoke DrawTextEx, [xsi].hMemDC, [xsi].pTextBuffer, -1, \
                         addr [xsi].TextRect, DT_LEFT or DT_VCENTER or DT_SINGLELINE, NULL
    .endif
    invoke SetTextColor, [xsi].hMemDC, PrevColor
    invoke SetBkMode, [xsi].hMemDC, dPrevBackMode
  .endif

  ;Now, copy the content of the memory DC to the drawing DC.
  invoke BeginPaint, [xsi].hWnd, addr PS
  invoke BitBlt, PS.hdc, 0, 0, [xsi].FaceRect.right, [xsi].FaceRect.bottom, \
                 [xsi].hMemDC, 0, 0, SRCCOPY
  invoke EndPaint, [xsi].hWnd, addr PS
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ColorButton.OnGetColor
; Purpose:    Event procedure for BM_GETCOLOR message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Requested color.

Method ColorButton.OnGetColor,, wParam:WPARAM, lParam:LPARAM
  SetObject xcx
  mov eax, [xcx].Color
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ColorButton.OnSetColor
; Purpose:    Event procedure for BM_SETCOLOR message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method ColorButton.OnSetColor,, wParam:WPARAM, lParam:LPARAM
  SetObject xcx
  m2m [xcx].Color, DWORD ptr lParam, edx                ;Color is passed in lParam
  invoke RedrawWindow, [xcx].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ColorButton.Startup
; Purpose:    Register the ColorButton object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method ColorButton.Startup
  local WC:WNDCLASSEX, hWnd:HWND

  mov WC.cbSize, sizeof(WNDCLASSEX)
  m2z WC.style
  m2m WC.lpfnWndProc, $MethodAddr(ColorButton.WndProc), xdx
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xdx
  m2z WC.hbrBackground
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset(szColorButton), xdx
  invoke LoadImage, hInstance, $OfsCStr("ICON_BLOT"), IMAGE_ICON, 0, 0, LR_DEFAULTCOLOR
  mov WC.hIcon, xax

  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm
  
  invoke RegisterClassEx, addr WC
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ColorButton.WindowProc
; Purpose:    Processing of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the message ID.
; Note:       Window HANDLE is passed in pSelf (hidden argument).

Method ColorButton.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  ;DbgMessage uMsg,, "ColorButton"
  .if uMsg == WM_NCCREATE
    mov xax, lParam
    .if [xax].CREATESTRUCT.lpCreateParams == NULL
      ;If lpCreateParams is NULL, then it is a resource call => Create new object instance
      mov xsi, $New(@SubStr(%$$OName, 4))
      OCall xax::ColorButton.InitRes, pSelf
    .else
      ;Init call
      mov xsi, [xax].CREATESTRUCT.lpCreateParams
      m2m [xsi].$Obj(ColorButton).hWnd, pSelf, xdx
    .endif
    invoke SetWindowLongPtr, pSelf, GWLP_USERDATA, xsi
    OCall xsi::ColorButton.Dispatch, pSelf, uMsg, wParam, lParam
  .else
    invoke GetWindowLongPtr, pSelf, GWLP_USERDATA       ;If GWL_USERDATA wasn't set,
    .if xax == NULL                                     ;GetWindowLong returns NULL
      invoke DefWindowProc, pSelf, uMsg, wParam, lParam
    .else
      OCall xax::ColorButton.Dispatch, pSelf, uMsg, wParam, lParam
    .endif
  .endif
MethodEnd

endif
