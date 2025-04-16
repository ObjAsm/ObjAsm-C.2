; ==================================================================================================
; Title:      IconButton.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of icon button objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


BUTTONLITERALCHAR   equ    "|"    ;Literal marker character.
BUTTONRESOURCECHAR  equ    "$"    ;Resource redirctor character.

;          Face
;    -----------------
;   | II |  Press Me  |
;    -----------------
;    Icon     Text

;BS_FLAT draws a flat button

;Icon button styles
IBS_EX_HOOVER   equ     BIT20

; --------------------------------------------------------------------------------------------------
; Object:     IconButton
; Purpose:    Implement a button control that displays an icon on its surface.

Object IconButton, IconButtonID, Button
  RedefineMethod    Init,           POINTER, HWND, PDEF_BUTTON
  RedefineMethod    OnCreate,       WPARAM, LPARAM
  RedefineMethod    OnDestroy,      WPARAM, LPARAM
  RedefineMethod    OnPaint,        WPARAM, LPARAM
  StaticMethod      Startup
  RedefineMethod    WndProc,        DWORD, WPARAM, LPARAM

  DefineVariable    hIcon,          HICON,   0
ObjectEnd


; ==================================================================================================

if IMPLEMENT

CStr szIconButton, "IconButton"

; --------------------------------------------------------------------------------------------------
; Method:     IconButton.Init
; Purpose:    Initialize the IconButton object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> Definition structure.
; Return:     Nothing.

Method IconButton.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND, pDefStruc:PDEF_BUTTON
  SetObject xsi
  mov xbx, pDefStruc
  assume xbx:PDEF_BUTTON
  mov eax, [xbx].dStyle
  or eax, WS_CHILD or WS_VISIBLE or WS_TABSTOP
  invoke CreateWindowEx, [xbx].dExStyle, offset(szIconButton), [xbx].pTitle, \
                         eax, [xbx].sdPosX, [xbx].sdPosY, [xbx].dWidth, [xbx].dHeight, \
                         hParent, [xbx].xCtlID, hInstance, pSelf
  assume xbx:NOTHING
  ACall xsi.Init, pOwner, xax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IconButton.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero to continue creation of the window, else -1.

Method IconButton.OnCreate, uses xsi, wParam:WPARAM, lParam:LPARAM
  local hDC:HDC, hParent:HWND, pBuffer:POINTER, pPos:POINTER

  ;DbgText "IconButton.OnCreate"
  SetObject xsi
  mov xax, lParam
  mov pBuffer, $invoke(StrNew, [xax].CREATESTRUCT.lpszName)
  mov pPos, $invoke(StrLScan, pBuffer, BUTTONLITERALCHAR)    ;Literal indicator char
  .if xax == NULL
    m2m [xsi].pTextBuffer, pBuffer, xdx
  .else
    m2z CHR ptr [xax]                                   ;Set zero terminator
    mov [xsi].hIcon, $invoke(LoadIcon, hInstance, pBuffer)
    add pPos, sizeof(CHR)
    mov [xsi].pTextBuffer, $invoke(StrNew, pPos)
    invoke StrDispose, pBuffer
  .endif

  invoke GetClientRect, [xsi].hWnd, addr [xsi].FaceRect
  invoke MemClone, addr [xsi].IconRect, addr [xsi].FaceRect, sizeof(RECT)
  invoke MemClone, addr [xsi].TextRect, addr [xsi].FaceRect, sizeof(RECT)

  .if [xsi].hIcon == 0
    m2m [xsi].IconRect.right, [xsi].IconRect.left, eax    ;No width
  .else
    m2m [xsi].IconRect.right, [xsi].IconRect.bottom, eax  ;Width = Height
  .endif

  m2m [xsi].TextRect.left, [xsi].IconRect.right, eax
  GrowRect [xsi].TextRect, -2, -4
  MoveRect [xsi].TextRect, -3, 0                        ;Compensate border

  mov hParent, $invoke(GetParent, [xsi].hWnd)
  mov hDC, $invoke(GetDC, hParent)
  mov [xsi].hMemDC, $invoke(CreateCompatibleDC, hDC)
  invoke CreateCompatibleBitmap, hDC, [xsi].FaceRect.right, [xsi].IconRect.bottom
  mov [xsi].hMemBmp, xax
  invoke ReleaseDC, hParent, hDC
  mov [xsi].hPrevBmp, $invoke(SelectObject, [xsi].hMemDC, [xsi].hMemBmp)
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IconButton.OnDestroy
; Purpose:    Event procedure for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method IconButton.OnDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke DeleteObject, $invoke(SelectObject, [xsi].hMemDC, [xsi].hPrevBmp)
  invoke DeleteDC, [xsi].hMemDC
  .if [xsi].hIcon != 0
    invoke DestroyIcon, [xsi].hIcon
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IconButton.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method IconButton.OnPaint, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, cBuffer[256]:CHR, hBgBrush:HBRUSH
  local dPrevColor:DWORD, dPrevBackMode:DWORD, Rct:RECT, dState:DWORD

  ;DbgText "IconButton.OnPaint"
  SetObject xsi
  invoke GetParent, [xsi].hWnd
  invoke SendMessage, xax, WM_CTLCOLORSTATIC, [xsi].hMemDC, [xsi].hWnd
  mov hBgBrush, xax
  .if TRUE;$invoke(AreVisualStylesEnabled) == FALSE
    invoke FillRect, [xsi].hMemDC, addr [xsi].FaceRect, hBgBrush
    invoke MemClone, addr Rct, addr [xsi].FaceRect, sizeof(Rct)
    invoke GetWindowLongPtr, [xsi].hWnd, GWL_STYLE
    mov ebx, eax
    .ifBitSet eax, BS_DEFPUSHBUTTON
      invoke FrameRect, [xsi].hMemDC, addr Rct, $invoke(GetStockObject, BLACK_BRUSH)
      GrowRect Rct, -1
    .endif
    .ifBitSet ebx, BS_FLAT
      invoke GetWindowLongPtr, [xsi].hWnd, GWL_EXSTYLE
      .ifBitSet eax, IBS_EX_HOOVER
        .ifBitSet [xsi].dFlags, BTF_HOVERED
          invoke DrawEdge, [xsi].hMemDC, addr Rct, BDR_RAISEDINNER, BF_RECT
        .elseIfBitSet [xsi].dFlags, BTF_PRESSED
          invoke DrawEdge, [xsi].hMemDC, addr Rct, BDR_SUNKENOUTER, BF_RECT
        .endif
      .else
        .ifBitSet [xsi].dFlags, BTF_PRESSED
          invoke DrawEdge, [xsi].hMemDC, addr Rct, BDR_SUNKENOUTER, BF_RECT
        .else
          invoke DrawEdge, [xsi].hMemDC, addr Rct, BDR_RAISEDINNER, BF_RECT
        .endif
      .endif
    .else
      .ifBitSet [xsi].dFlags, BTF_PRESSED
        invoke DrawFrameControl, [xsi].hMemDC, addr Rct, DFC_BUTTON, \
                                                         DFCS_BUTTONPUSH or DFCS_PUSHED
      .else
        invoke DrawFrameControl, [xsi].hMemDC, addr Rct, DFC_BUTTON, DFCS_BUTTONPUSH
      .endif
    .endif

  .else
    m2z dState
    invoke FillRect, [xsi].hMemDC, addr [xsi].FaceRect, hBgBrush
    invoke OpenThemeData, [xsi].hWnd, $OfsCStrW("Button")
    mov xbx, xax
    invoke GetWindowLongPtr, [xsi].hWnd, GWL_STYLE
    .ifBitSet eax, BS_DEFPUSHBUTTON
      mov dState, PBS_DEFAULTED
    .else
      mov dState, PBS_NORMAL
    .endif

    .ifBitSet [xsi].dFlags, BTF_HOVERED
      mov dState, PBS_HOT
    .elseIfBitSet [xsi].dFlags, BTF_PRESSED
      mov dState, PBS_PRESSED
    .endif

    lea xbx, [xsi].FaceRect
    invoke DrawThemeBackground, xbx, [xsi].hMemDC, BP_PUSHBUTTON, dState, xbx, NULL
    invoke CloseThemeData, xbx
  .endif

  mov edx, [xsi].IconRect.bottom
  sub edx, 16
  shr edx, 1
  .ifBitSet [xsi].dFlags, BTF_PRESSED
    inc edx
  .endif
  invoke DrawIconEx, [xsi].hMemDC, edx, edx, [xsi].hIcon, 16, 16, 0, 0, DI_NORMAL

  mov xax, [xsi].pTextBuffer
  .if (xax != NULL) && (BYTE ptr [xax] != 0)
    mov dPrevBackMode, $32($invoke(SetBkMode, [xsi].hMemDC, TRANSPARENT))
    .ifBitClr [xsi].dFlags, BTF_DISABLED
      ;Enabled
      invoke GetSysColor, COLOR_BTNTEXT
      mov dPrevColor, $32($invoke(SetTextColor, [xsi].hMemDC, eax))
      .ifBitSet [xsi].dFlags, BTF_SHOW_SHORTCUT
        invoke DrawTextEx, [xsi].hMemDC, [xsi].pTextBuffer, -1, \
                           addr [xsi].TextRect, DT_CENTER or DT_VCENTER or DT_SINGLELINE, NULL
      .else
        invoke StrCCopy, addr cBuffer, [xsi].pTextBuffer, lengthof(cBuffer) - 1
        invoke StrLScan, addr cBuffer, "&"
        .if xax != 0
          m2z CHR ptr [xax]
          add xax, sizeof(CHR)
          invoke StrCat, addr cBuffer, xax
        .endif
        invoke DrawTextEx, [xsi].hMemDC, addr cBuffer, -1, \
                           addr [xsi].TextRect, DT_CENTER or DT_VCENTER or DT_SINGLELINE, NULL
      .endif
      .ifBitSet [xsi].dFlags, BTF_FOCUSED
        invoke MemClone, addr Rct, addr [xsi].TextRect, sizeof(RECT)
        invoke DrawTextEx, [xsi].hMemDC, [xsi].pTextBuffer, -1, \
                           addr Rct, DT_CALCRECT or DT_CENTER or DT_VCENTER or DT_SINGLELINE, NULL
        mov eax, [xsi].TextRect.right
        sub eax, Rct.right
        shr eax, 1
        add Rct.left, eax
        add Rct.right, eax
        GrowRect Rct, 3, 1
        invoke DrawFocusRect, [xsi].hMemDC, addr [xsi].TextRect
      .endif
    .else
      ;Disabled
      invoke GetSysColor, COLOR_BTNHILIGHT
      mov dPrevColor, $32($invoke(SetTextColor, [xsi].hMemDC, eax))
      MoveRect [xsi].TextRect, 1
      invoke DrawTextEx, [xsi].hMemDC, [xsi].pTextBuffer, -1, \
                         addr [xsi].TextRect, DT_CENTER or DT_VCENTER or DT_SINGLELINE, NULL
      MoveRect [xsi].TextRect, -1
      invoke SetTextColor, [xsi].hMemDC, $32($invoke(GetSysColor, COLOR_BTNSHADOW))
      invoke DrawTextEx, [xsi].hMemDC, [xsi].pTextBuffer, -1, \
                         addr [xsi].TextRect, DT_CENTER or DT_VCENTER or DT_SINGLELINE, NULL
    .endif
    invoke SetTextColor, [xsi].hMemDC, dPrevColor
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
; Method:     IconButton.Startup
; Purpose:    Register the IconButton object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method IconButton.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof(WNDCLASSEX)
  mov WC.style, CS_HREDRAW or CS_VREDRAW or CS_PARENTDC
  m2m WC.lpfnWndProc, $MethodAddr(IconButton.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  m2z WC.hbrBackground
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset(szIconButton), xax
  m2z WC.hIcon
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IconButton.WindowProc
; Purpose:    Processing of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.
; Note:       Window handle passed in pSelf (hidden parameter).

Method IconButton.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  ;DbgMessage uMsg,, "IconButton"
  .if uMsg == WM_NCCREATE
    mov xax, lParam
    .if [xax].CREATESTRUCT.lpCreateParams == NULL
      ;If lpCreateParams is 0, then it is a resource call => Create new object instance
      mov xsi, $New(IconButton)
      OCall xsi::IconButton.InitRes, pSelf
    .else
      ;Init call
      mov xsi, [xax].CREATESTRUCT.lpCreateParams
      mrm [xsi].$Obj(IconButton).hWnd, pSelf, xax
    .endif
    invoke SetWindowLongPtr, pSelf, GWLP_USERDATA, xsi
    OCall xsi::IconButton.Dispatch, pSelf, uMsg, wParam, lParam
  .else
    invoke GetWindowLongPtr, pSelf, GWLP_USERDATA       ;if GWLP_USERDATA wasn't set,
    .if xax == NULL                                     ;GetWindowLongPtr returns NULL
      invoke DefWindowProc, pSelf, uMsg, wParam, lParam
    .else
      OCall xax::IconButton.Dispatch, pSelf, uMsg, wParam, lParam
    .endif
  .endif
MethodEnd

endif
