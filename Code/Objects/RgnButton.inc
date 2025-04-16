; ==================================================================================================
; Title:      RgnButton.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of Region Button objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


DEF_REGIONBUTTON struc
  xCtlID        XWORD     ?   ;Button Contol ID
  dStyle        DWORD     ?   ;Button Style
  dExStyle      DWORD     ?   ;Extended style
  sdPosX        SDWORD    ?   ;Button X position
  sdPosY        SDWORD    ?   ;Button Y position
  pResName      POINTER   ?   ;Resource name
DEF_REGIONBUTTON ends
PDEF_REGIONBUTTON typedef ptr DEF_REGIONBUTTON

; --------------------------------------------------------------------------------------------------
; Object:   RgnButton
; Purpose:  Implement a button object of irregular shape.

Object RgnButton, RgnButtonID, WinPrimer
  VirtualMethod     Dispatch,       HWND, DWORD, WPARAM, LPARAM
  RedefineMethod    Done
  RedefineMethod    Init,           POINTER, HWND, PDEF_REGIONBUTTON
  VirtualMethod     InitRes,        HWND
  StaticMethod      Startup
  VirtualMethod     WndProc,        DWORD, WPARAM, LPARAM

  VirtualEvent      OnCreate,       WM_CREATE
  VirtualEvent      OnDestroy,      WM_DESTROY
  VirtualEvent      OnEnable,       WM_ENABLE
  VirtualEvent      OnGetDlgCode,   WM_GETDLGCODE
  VirtualEvent      OnGetFont,      WM_GETFONT
  VirtualEvent      OnLButtonDown,  WM_LBUTTONDOWN
  VirtualEvent      OnLButtonUp,    WM_LBUTTONUP
  VirtualEvent      OnMouseMove,    WM_MOUSEMOVE
  VirtualEvent      OnNcDestroy,    WM_NCDESTROY
  VirtualEvent      OnPaint,        WM_PAINT
  VirtualEvent      OnSetFont,      WM_SETFONT

  Embed   BtnToolTip,   Tooltip

  DefineVariable    hBmpDisabled,   HBITMAP,    0
  DefineVariable    hBmpEnabled,    HBITMAP,    0
  DefineVariable    hBmpHovered,    HBITMAP,    0
  DefineVariable    hBmpPressed,    HBITMAP,    0
  DefineVariable    hBmpBkgnd,      HBITMAP,    0
  DefineVariable    hMemDC,         HDC,        0           ;Memory DC
  DefineVariable    hRgnDisabled,   HRGN,       0           ;Disabled Button region
  DefineVariable    hRgnEnabled,    HRGN,       0           ;Enabled Button region
  DefineVariable    hRgnHovered,    HRGN,       0           ;Hovered Button region
  DefineVariable    hRgnPressed,    HRGN,       0           ;Pressed Button region
  DefineVariable    RgnColor,       COLORREF,   $RGB(000,000,000) ;Region delimiter color
  DefineVariable    dFlags,         DWORD,      0           ;RegButtonState
  DefineVariable    pTooltipText,   PSTRING,    NULL        ;-> Tooltip text
  DefineVariable    pButtonText,    PSTRING,    NULL        ;-> Button text
  DefineVariable    TextColor,      COLORREF,   $RGB(000,000,000) ;Text color
  DefineVariable    hFont,          HFONT,      0           ;Control font handle
  DefineVariable    dFirstDraw,     DWORD,      TRUE        ;Drawing flag

ObjectEnd

; ==================================================================================================

if IMPLEMENT

RBF_SELF_INST       equ   BIT00                         ;Object was instanced by CreateWindowEx
RBF_SHOW_SHORTCUT   equ   BIT01
RBF_DISABLED        equ   BIT02
RBF_HOVERED         equ   BIT03
RBF_FOCUSED         equ   BIT04
RBF_PRESSED         equ   BIT05

RGNBTNRESDATA struc
  RgnColor        COLORREF  ?   ;Color that delimits the button region
  dBmpEnabledID   DWORD     ?   ;Button enabled bitmap resource ID
  dBmpHoveredID   DWORD     ?   ;Button hovered bitmap resource ID
  dBmpPressedID   DWORD     ?   ;Button pressed bitmap resource ID
  dBmpDisabledID  DWORD     ?   ;Button disabled bitmap resource ID
  dButtonTextID   DWORD     ?   ;Button string resource ID
  TextColor       COLORREF  ?   ;Button Text Color
  dTooltipTextID  DWORD     ?   ;Tooltip string resource ID
RGNBTNRESDATA ends
PRGNBTNRESDATA typedef ptr RGNBTNRESDATA

CStr szRgnButton, "RgnButton"

.code
; --------------------------------------------------------------------------------------------------
; Method:     RgnButton.Dispatch
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Window handle.
;             Arg2: Message identifier.
;             Arg3: First message parameter.
;             Arg4: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.

Method RgnButton.Dispatch, uses xsi, hWnd:HWND, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg
  SetObject xsi
  DispatchEvent <DefWindowProc, hWnd>                   ;xsi -> Object Instance
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     RgnButton.Done
; Purpose:    Finalize the RgnButton object.
; Arguments:  None.
; Return:     Nothing.

Method RgnButton.Done, uses xsi
  SetObject xsi
  OCall [xsi].BtnToolTip::Tooltip.Done
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     RgnButton.Init
; Purpose:    Initialize the RgnButton object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> DEF_REGIONBUTTON structure.
; Return:     Nothing.

Method RgnButton.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND, pDefStruc:PDEF_REGIONBUTTON
  local BmpInfo:BITMAP

;  DbgText "RgnButton.Init"
  SetObject xsi
  mov xbx, pDefStruc
  assume xbx:PDEF_REGIONBUTTON
  mov eax, [xbx].dStyle
  or eax, WS_VISIBLE or WS_CLIPSIBLINGS or WS_CHILD
  invoke CreateWindowEx, [xbx].dExStyle, offset szRgnButton, [xbx].pResName, \
                         eax, [xbx].sdPosX, [xbx].sdPosY, 1, 1, \
                         hParent, [xbx].xCtlID, hInstance, pSelf
  ACall xsi.Init, pOwner, xax

  invoke GetObject, [xsi].hBmpEnabled, sizeof BmpInfo, addr BmpInfo
  invoke MoveWindow, [xsi].hWnd, [xbx].sdPosX, [xbx].sdPosY, \
                     BmpInfo.bmWidth, BmpInfo.bmHeight, FALSE
  assume xbx:NOTHING

  invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE

  OCall [xsi].BtnToolTip::Tooltip.Init, xsi, [xsi].hWnd
  OCall [xsi].BtnToolTip::Tooltip.AddWndTip, [xsi].hWnd, [xsi].pTooltipText

  mov [xsi].hFont, $invoke(SendMessage, hParent, WM_GETFONT, 0, 0)
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     RgnButton.InitRes
; Purpose:    Initialize the RgnButton object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
; Return:     Nothing.

Method RgnButton.InitRes, uses xsi, hWnd:HWND
  local BmpInfo:BITMAP, hDC:HDC, hPrvBmp:HBITMAP

;  DbgText "RgnButton.InitRes"
  SetObject xsi
  BitSet [xsi].dFlags, RBF_SELF_INST
  ACall xsi.Init, NULL, hWnd
  invoke GetObject, [xsi].hBmpEnabled, sizeof BmpInfo, addr BmpInfo

  invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
  OCall [xsi].BtnToolTip::Tooltip.Init, xsi, [xsi].hWnd
  OCall [xsi].BtnToolTip::Tooltip.AddWndTip, [xsi].hWnd, [xsi].pTooltipText

  mov hDC, $invoke(GetDC, [xsi].hWnd)
  mov hPrvBmp, $invoke(SelectObject, [xsi].hMemDC, xax)
  invoke BitBlt, [xsi].hMemDC, 0, 0, BmpInfo.bmWidth, BmpInfo.bmHeight, hDC, 0, 0, SRCCOPY
  invoke SelectObject, [xsi].hMemDC, hPrvBmp
  invoke ReleaseDC, [xsi].hWnd, hDC
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     RgnButton.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero to continue creation of the window.

Method RgnButton.OnCreate, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local hDC:HDC, cTextBuffer[1024]:CHR

;  DbgText "RgnButton.OnCreate"
  SetObject xsi
  mov xbx, lParam
  mov hDC, $invoke(GetDC, [xbx].CREATESTRUCT.hwndParent)
  mov [xsi].hMemDC, $invoke(CreateCompatibleDC, hDC)

  invoke ReleaseDC, [xbx].CREATESTRUCT.hwndParent, hDC

  invoke FindResource, hInstance, $OfsCStr("RGNBUTTON"), [xbx].CREATESTRUCT.lpszName
  .if xax == NULL
    OCall ErrorReport, NULL, RGB_NO_RES
  .else
    ;Load the Resource
    mov xbx, $invoke(LoadResource, hInstance, xax)
    .if xax == NULL
      OCall ErrorReport, NULL, RGB_RES_ERROR
    .else
      m2m [xsi].RgnColor, [xbx].RGNBTNRESDATA.RgnColor, edx
      m2m [xsi].TextColor, [xbx].RGNBTNRESDATA.TextColor, eax
      mov edx, [xbx].RGNBTNRESDATA.dBmpEnabledID
      mov [xsi].hBmpEnabled, $invoke(LoadBitmap, hInstance, xdx)
      .if xax == NULL
        OCall ErrorReport, NULL, RGB_RES_BMP_ERROR
      .else
        mov [xsi].hRgnEnabled, $invoke(Bmp2Rgn, xax, [xsi].RgnColor)
      .endif
      mov edx, [xbx].RGNBTNRESDATA.dBmpHoveredID
      mov [xsi].hBmpHovered, $invoke(LoadBitmap, hInstance, xdx)
      .if xax == NULL
        OCall ErrorReport, NULL, RGB_RES_BMP_ERROR
      .else
        mov [xsi].hRgnHovered, $invoke(Bmp2Rgn, xax, [xsi].RgnColor)
      .endif
      mov edx, [xbx].RGNBTNRESDATA.dBmpPressedID
      mov [xsi].hBmpPressed, $invoke(LoadBitmap, hInstance, xdx)
      .if xax == NULL
        OCall ErrorReport, NULL, RGB_RES_BMP_ERROR
      .else
        mov [xsi].hRgnPressed, $invoke(Bmp2Rgn, xax, [xsi].RgnColor)
      .endif
      mov edx, [xbx].RGNBTNRESDATA.dBmpDisabledID
      mov [xsi].hBmpDisabled, $invoke(LoadBitmap, hInstance, xdx)
      .if xax == NULL
        OCall ErrorReport, NULL, RGB_RES_BMP_ERROR
      .else
        mov [xsi].hRgnDisabled, $invoke(Bmp2Rgn, xax, [xsi].RgnColor)
      .endif

      invoke LoadString, hInstance, [xbx].RGNBTNRESDATA.dButtonTextID, \
                         addr cTextBuffer, lengthof cTextBuffer
      mov [xsi].pButtonText, $invoke(StrNew, addr cTextBuffer)
      invoke LoadString, hInstance, [xbx].RGNBTNRESDATA.dTooltipTextID, \
                         addr cTextBuffer, lengthof cTextBuffer
      mov [xsi].pTooltipText, $invoke(StrNew, addr cTextBuffer)
    .endif
  .endif
  xor eax, eax                                          ;Always continue the creation of the window
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     RgnButton.OnDestroy
; Purpose:    Event procedure for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method RgnButton.OnDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi

  invoke DestroyWindow, [xsi].BtnToolTip.hWnd

  invoke DeleteObject, [xsi].hBmpBkgnd
  invoke DeleteObject, [xsi].hBmpEnabled
  invoke DeleteObject, [xsi].hBmpHovered
  invoke DeleteObject, [xsi].hBmpPressed
  invoke DeleteObject, [xsi].hBmpDisabled
  invoke DeleteDC, [xsi].hMemDC

  invoke DeleteObject, [xsi].hRgnDisabled
  invoke DeleteObject, [xsi].hRgnEnabled
  invoke DeleteObject, [xsi].hRgnHovered
  invoke DeleteObject, [xsi].hRgnPressed

  invoke StrDispose, [xsi].pButtonText
  invoke StrDispose, [xsi].pTooltipText
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     RgnButton.OnEnable
; Purpose:    Event procedure for WM_ENABLE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method RgnButton.OnEnable, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi, RgnButton
  BitClr [xsi].dFlags, (RBF_HOVERED or RBF_PRESSED)
  .if wParam == FALSE
    BitSet [xsi].dFlags, RBF_DISABLED
  .else
    BitClr [xsi].dFlags, RBF_DISABLED
  .endif
  invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     RgnButton.OnGetDlgCode
; Purpose:    Event procedure for WM_GETDLGCODE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Value indicating type of control and input type the application processes.

Method RgnButton.OnGetDlgCode,, wParam:WPARAM, lParam:LPARAM
  SetObject xcx
  invoke GetWindowLongPtr, [xcx].hWnd, GWL_STYLE
  .ifBitSet xax, BS_DEFPUSHBUTTON
     mov eax, DLGC_BUTTON or DLGC_DEFPUSHBUTTON
  .else
     mov eax, DLGC_BUTTON or DLGC_UNDEFPUSHBUTTON
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     RgnButton.OnGetFont
; Purpose:    Event procedure for WM_GETFONT message. Return the current font handle.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     xax = Font handle.

Method RgnButton.OnGetFont,, wParam:WPARAM, lParam:LPARAM
  SetObject xcx
  mov xax, [xcx].hFont
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     RgnButton.OnMouseMove
; Purpose:    Event procedure for WM_MOUSEMOVE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method RgnButton.OnMouseMove, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi, RgnButton
  .ifBitClr [xsi].dFlags, RBF_DISABLED
    PntS2Regs lParam, ebx
    .if $invoke(PtInRegion, [xsi].hRgnEnabled, eax, ebx) != FALSE
      .ifBitClr [xsi].dFlags, (RBF_PRESSED or RBF_HOVERED)
        invoke SetCapture, [xsi].hWnd
        BitSet [xsi].dFlags, RBF_HOVERED
        invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
      .endif
    .else
      .ifBitClr [xsi].dFlags, RBF_PRESSED
        BitClr [xsi].dFlags, RBF_HOVERED
        invoke ReleaseCapture
        invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
      .endif
    .endif
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     RgnButton.OnLButtonDown
; Purpose:    Event procedure for WM_LBUTTONDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method RgnButton.OnLButtonDown, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi, RgnButton
  .ifBitClr [xsi].dFlags, RBF_DISABLED
    BitSet [xsi].dFlags, RBF_PRESSED
    BitClr [xsi].dFlags, RBF_HOVERED
    invoke SetCapture, [xsi].hWnd
    invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     RgnButton.OnLButtonUp
; Purpose:    Event procedure for WM_LBUTTONUP message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method RgnButton.OnLButtonUp, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi, RgnButton
  .ifBitClr [xsi].dFlags, RBF_DISABLED
    .ifBitSet [xsi].dFlags, RBF_PRESSED
      BitClr [xsi].dFlags, (RBF_PRESSED or RBF_HOVERED)
      invoke ReleaseCapture
      PntS2Regs lParam, ebx
      .if $invoke(PtInRegion, [xsi].hRgnPressed, eax, ebx) != FALSE
        invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
        mov xbx, $invoke(GetParent, [xsi].hWnd)
        invoke GetWindowLongPtr, [xsi].hWnd, GWL_ID
        invoke SendMessage, xbx, WM_COMMAND, eax, [xsi].hWnd
      .else
        invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
      .endif
    .endif
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     RgnButton.OnNcDestroy
; Purpose:    Event procedure for WM_NCDESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method RgnButton.OnNcDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke SetWindowLongPtr, [xsi].hWnd, GWLP_USERDATA, NULL
  .ifBitSet [xsi].dFlags, RBF_SELF_INST
    Destroy xsi
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     RgnButton.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method RgnButton.OnPaint, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, BmpInfo:BITMAP, hDC:HDC, hPrvBmp:HBITMAP, Rct:RECT
  local hTmpDC:HDC, hPrvTmpBmp:HBITMAP
  local dPrvBkMode:DWORD, hPrvFont:HFONT, dPrvTextColor:DWORD

  SetObject xsi
  mov hDC, $invoke(BeginPaint, [xsi].hWnd, addr PS)
  invoke GetObject, [xsi].hBmpEnabled, sizeof BmpInfo, addr BmpInfo

  .if [xsi].dFirstDraw == TRUE                        ;Save the background
    m2z [xsi].dFirstDraw
    mov [xsi].hBmpBkgnd, $invoke(CreateCompatibleBitmap, hDC, BmpInfo.bmWidth, BmpInfo.bmHeight)
    mov hPrvBmp, $invoke(SelectObject, [xsi].hMemDC, xax)
    invoke BitBlt, [xsi].hMemDC, 0, 0, BmpInfo.bmWidth, BmpInfo.bmHeight, hDC, 0, 0, SRCCOPY
    invoke SelectObject, [xsi].hMemDC, hPrvBmp
  .endif

  ;Restore the background
  mov hTmpDC, $invoke(CreateCompatibleDC, hDC)
  mov hPrvTmpBmp, $invoke(SelectObject, hTmpDC, [xsi].hBmpBkgnd)

  invoke CreateCompatibleBitmap, hDC, BmpInfo.bmWidth, BmpInfo.bmHeight
  mov hPrvBmp, $invoke(SelectObject, [xsi].hMemDC, xax)
  invoke BitBlt, [xsi].hMemDC, 0, 0, BmpInfo.bmWidth, BmpInfo.bmHeight, hTmpDC, 0, 0, SRCCOPY

  .ifBitSet [xsi].dFlags, RBF_DISABLED
    mov xbx, [xsi].hBmpDisabled
  .elseIfBitSet [xsi].dFlags, RBF_HOVERED
    mov xbx, [xsi].hBmpHovered
  .elseIfBitSet [xsi].dFlags, RBF_PRESSED
    mov xbx, [xsi].hBmpPressed
  .else
    mov xbx, [xsi].hBmpEnabled
  .endif
  invoke DrawTransparentBitmap, [xsi].hMemDC, xbx, 0, 0, [xsi].RgnColor

  invoke BitBlt, hDC, 0, 0, BmpInfo.bmWidth, BmpInfo.bmHeight, [xsi].hMemDC, 0, 0, SRCCOPY

  m2z Rct.left
  m2m Rct.right, BmpInfo.bmWidth, eax
  m2z Rct.top
  m2m Rct.bottom, BmpInfo.bmHeight, eax
  sub Rct.bottom, 3
  .ifBitSet [xsi].dFlags, RBF_PRESSED
    inc Rct.top
    inc Rct.bottom
    inc Rct.left
    inc Rct.right
  .endif
  mov dPrvBkMode, $32($invoke(SetBkMode, hDC, TRANSPARENT))
  mov dPrvTextColor, $32($invoke(SetTextColor, hDC, [xsi].TextColor))
  mov hPrvFont, $invoke(SelectObject, hDC, [xsi].hFont)
  invoke DrawText, hDC, [xsi].pButtonText, -1, addr Rct, \
                   DT_CENTER or DT_VCENTER or DT_SINGLELINE or DT_END_ELLIPSIS
  invoke SelectObject, hDC, hPrvFont
  invoke SetTextColor, hDC, dPrvTextColor
  invoke SetBkMode, hDC, dPrvBkMode

  invoke SelectObject, hTmpDC, hPrvTmpBmp
  invoke DeleteDC, hTmpDC

  invoke DeleteObject, $invoke(SelectObject, [xsi].hMemDC, hPrvBmp)
  invoke EndPaint, [xsi].hWnd, addr PS
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     RgnButton.OnSetFont
; Purpose:    Event procedure for WM_SETFONT message. Set the current font handle.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method RgnButton.OnSetFont,, wParam:WPARAM, lParam:LPARAM
  SetObject xcx
  m2m [xcx].hFont, wParam, xax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     RgnButton.Startup
; Purpose:    Register the RgnButton window class with the operating system.
; Arguments:  None.
; Return:     Nothing.

Method RgnButton.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CS_HREDRAW or CS_VREDRAW
  m2m WC.lpfnWndProc, $MethodAddr(RgnButton.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  m2z WC.hbrBackground
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szRgnButton, xax
  m2z WC.hIcon
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     RgnButton.WindowProc
; Purpose:    Processing of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.
; Note:       Window HANDLE is passed in pSelf (hidden parameter).

Method RgnButton.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg,, "RgnButton"
  .if uMsg == WM_NCCREATE
    mov xax, lParam
    .if [xax].CREATESTRUCT.lpCreateParams == NULL
      ;If lpCreateParams is 0, then it is a resource call => Create new object instance
      mov xsi, $New(RgnButton)
      OCall xsi::RgnButton.InitRes, pSelf               ;pSelf = hWnd
      mov xcx, pSelf
    .else
      ;Init call
      mov xsi, [xax].CREATESTRUCT.lpCreateParams
      mrm [xsi].$Obj(RgnButton).hWnd, pSelf, xcx
    .endif
    invoke SetWindowLongPtr, xcx, GWLP_USERDATA, xsi
    OCall xsi::RgnButton.Dispatch, pSelf, uMsg, wParam, lParam
  .else
    invoke GetWindowLongPtr, pSelf, GWLP_USERDATA       ;If GWL_USERDATA wasn't set,
    .if xax == NULL                                     ;GetWindowLongPtr returns NULL
      invoke DefWindowProc, pSelf, uMsg, wParam, lParam
    .else
      OCall xax::RgnButton.Dispatch, pSelf, uMsg, wParam, lParam
    .endif
  .endif
MethodEnd

endif
