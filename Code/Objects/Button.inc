; ==================================================================================================
; Title:      Button.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of Button objects.
; Notes:      Version C.1.0, November 2017
;               - First release.
; Links:      https://docs.microsoft.com/en-us/windows/win32/w8cookbook/high-contrast-mode
;             https://docs.microsoft.com/en-us/windows/win32/winauto/high-contrast-parameter
; ==================================================================================================


BM_GETCOLOR     equ     WM_USER + 100   ;Used to get the color of the ColorButton object
BM_SETCOLOR     equ     WM_USER + 101   ;Used to set the color of the ColorButton object

;ButtonState     record  BS_Unused:2 = 0, \
;                        BS_Resource:1 = FALSE, BS_ShowShortCut:1 = FALSE, BS_Disabled:1 = FALSE, \
;                        BS_Hovered:1 = FALSE, BS_Focused:1 = FALSE, BS_Pressed:1 = FALSE
BTF_SELF_INST       equ   BIT00                         ;Object was instanced by CreateWindowEx
BTF_SHOW_SHORTCUT   equ   BIT01
BTF_DISABLED        equ   BIT02
BTF_HOVERED         equ   BIT03
BTF_FOCUSED         equ   BIT04
BTF_PRESSED         equ   BIT05

DEF_BUTTON struc
  xCtlID        XWORD     ?                             ;Contol ID
  dStyle        DWORD     ?                             ;Style
  dExStyle      DWORD     ?                             ;Extended style
  pTitle        PSTRING   ?                             ;-> Button text
  union
    rect        RECT      {}
    struct
      sdPosX    SDWORD  ?                               ;X position
      sdPosY    SDWORD  ?                               ;Y position
      dWidth    DWORD   ?                               ;Width
      dHeight   DWORD   ?                               ;Height
    ends
  ends
DEF_BUTTON ends
PDEF_BUTTON typedef ptr DEF_BUTTON

; --------------------------------------------------------------------------------------------------
; Object:   Button
; Purpose:  Implementation of a base object used as ancestor for objects like ColorButton, Hyperlink
;           or IconButton.

Object Button, ButtonID, WinPrimer
  VirtualMethod     Dispatch,       HWND, DWORD, WPARAM, LPARAM
  RedefineMethod    Done
  VirtualMethod     InitRes,        HWND
  VirtualAbstract   OnCreate,       WPARAM, LPARAM
  VirtualAbstract   OnDestroy,      WPARAM, LPARAM
  VirtualAbstract   OnPaint,        WPARAM, LPARAM
  VirtualAbstract   WndProc,        DWORD, WPARAM, LPARAM

  VirtualEvent      OnEnable,       WM_ENABLE
  VirtualEvent      OnGetDlgCode,   WM_GETDLGCODE
  VirtualEvent      OnKeyDown,      WM_KEYDOWN
  VirtualEvent      OnLButtonDown,  WM_LBUTTONDOWN
  VirtualEvent      OnLButtonUp,    WM_LBUTTONUP
  VirtualEvent      OnMouseMove,    WM_MOUSEMOVE
  VirtualEvent      OnUpdateUIState,WM_UPDATEUISTATE        ;Show underscores (XP)
  VirtualEvent      OnNcDestroy,    WM_NCDESTROY
  VirtualEvent      OnSetFont,      WM_SETFONT
  VirtualEvent      OnGetFont,      WM_GETFONT
  VirtualEvent      OnSetText,      WM_SETTEXT
  VirtualEvent      OnGetText,      WM_GETTEXT
  VirtualEvent      OnSetFocus,     WM_SETFOCUS
  VirtualEvent      OnKillFocus,    WM_KILLFOCUS

  Event             OnCreate,       WM_CREATE
  Event             OnDestroy,      WM_DESTROY
  Event             OnPaint,        WM_PAINT

;  DefineVariable    hBgBrush,       HBRUSH,     0           ;Background brush HANDLE
  DefineVariable    hMemDC,         HDC,        0           ;Memory DC
  DefineVariable    hMemBmp,        HBITMAP,    0           ;Memory DC bitmap
  DefineVariable    hPrevBmp,       HBITMAP,    0           ;Previous hMemDC bitmap
  DefineVariable    dFlags,         DWORD,      0
  DefineVariable    FaceRect,       RECT,       {}          ;Face RECT
  DefineVariable    IconRect,       RECT,       {}          ;Button RECT
  DefineVariable    TextRect,       RECT,       {}          ;Text RECT
  DefineVariable    pTextBuffer,    PSTRING,    NULL
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     Button.Dispatch
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Window handle.
;             Arg2: Message identifier.
;             Arg3: First message parameter.
;             Arg4: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the message.

Method Button.Dispatch, uses xsi, hWnd:HWND, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg
  SetObject xsi
  DispatchEvent <DefWindowProc, hWnd>                   ;xsi -> Object instance
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Button.Done
; Purpose:    Finalize the Button object.
; Arguments:  None.
; Return:     Nothing.

Method Button.Done, uses xsi
  SetObject xsi
  invoke StrDispose, [xsi].pTextBuffer
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Button.InitRes
; Purpose:    Initialize the Button object from a resource.
; Arguments:  Arg1: Button window handle.
; Return:     Nothing.
; Note:       WM_GETOBJECTINSTANCE may fail if the dialog has not processed WM_INITDIALOG yet.

Method Button.InitRes, uses xsi, hWnd:HWND
  SetObject xsi
  BitSet [xsi].dFlags, BTF_SELF_INST
  invoke GetParent, hWnd
  .if xax != 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0 ;Get instance POINTER of the parent object
  .endif
  ACall xsi.Init, xax, hWnd
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Button.OnEnable
; Purpose:    Event procedure for WM_ENABLE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Button.OnEnable, uses xsi, wParam:WPARAM, lParam:LPARAM
  ;DbgText "Button.OnEnable"
  SetObject xsi
  .if wParam == FALSE
    BitSet [xsi].dFlags, BTF_DISABLED
  .else
    BitClr [xsi].dFlags, BTF_DISABLED
  .endif
  BitClr [xsi].dFlags, BTF_HOVERED or BTF_FOCUSED or BTF_PRESSED
  invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Button.OnGetDlgCode
; Purpose:    Event procedure for WM_GETDLGCODE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Value indicating type of control and input type the application processes.

Method Button.OnGetDlgCode, uses xsi, wParam:WPARAM, lParam:LPARAM
  ;DbgText "Button.OnGetDlgCode"
  SetObject xsi
  invoke GetWindowLongPtr, [xsi].hWnd, GWL_STYLE
  .ifBitSet eax, BS_DEFPUSHBUTTON
     mov eax, DLGC_BUTTON or DLGC_DEFPUSHBUTTON
  .else
     mov eax, DLGC_BUTTON or DLGC_UNDEFPUSHBUTTON
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Button.OnGetFont
; Purpose:    Event procedure for WM_GETFONT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Requested font handle.

Method Button.OnGetFont,, wParam:WPARAM, lParam:LPARAM
  ;DbgText "Button.OnGetFont"
  SetObject xcx
  invoke GetCurrentObject, [xcx].hMemDC, OBJ_FONT
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Button.OnGetText
; Purpose:    Event procedure for WM_GETTEXT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = The return value is the number of characters copied including zero termnator.

Method Button.OnGetText,, wParam:WPARAM, lParam:LPARAM
  ;DbgText "Button.OnGetText"
  SetObject xdx
  .if (lParam != NULL) && (wParam > 0)
    mov xax, wParam
    dec xax                                             ;Leave place for the ZTC
    invoke StrCCopy, lParam, [xdx].pTextBuffer, eax
    inc edx
    mov eax, edx
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Button.OnKeyDown
; Purpose:    Event procedure for WM_KEYDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Button.OnKeyDown, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  ;DbgText "Button.OnKeyDown"
  SetObject xsi
  mov xax, wParam
  .if al == " "                                         ;Space was pressed!
    invoke GetParent, [xsi].hWnd
    mov xbx, xax
    invoke GetWindowLongPtr, [xsi].hWnd, GWL_ID
    invoke SendMessage, xbx, WM_COMMAND, eax, [xsi].hWnd
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Button.OnKillFocus
; Purpose:    Event procedure for WM_KILLFOCUS message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Button.OnKillFocus, uses xsi, wParam:WPARAM, lParam:LPARAM
  ;DbgText "Button.OnKillFocus"
  SetObject xsi
  BitClr [xsi].dFlags, BTF_FOCUSED or BTF_HOVERED
  invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Button.OnLButtonDown
; Purpose:    Event procedure for WM_LBUTTONDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Button.OnLButtonDown, uses xsi, wParam:WPARAM, lParam:LPARAM
  local Pnt:POINT

  ;DbgText "Button.OnLButtonDown"
  SetObject xsi
  .ifBitClr [xsi].dFlags, BTF_DISABLED
    PntS2Pnt Pnt, lParam
    .if $invoke(PtInRect, addr [xsi].FaceRect, Pnt) != FALSE
      invoke SetFocus, [xsi].hWnd
      BitSet [xsi].dFlags, BTF_PRESSED or BTF_FOCUSED
      BitClr [xsi].dFlags, BTF_HOVERED
      invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
    .endif
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Button.OnLButtonUp
; Purpose:    Event procedure for WM_LBUTTONUP message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Button.OnLButtonUp, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local Pnt:POINT

  ;DbgText "Button.OnLButtonUp"
  SetObject xsi
  .ifBitClr [xsi].dFlags, BTF_DISABLED
    invoke ReleaseCapture
    .ifBitSet [xsi].dFlags, BTF_PRESSED
      BitClr [xsi].dFlags, BTF_PRESSED or BTF_HOVERED
      PntS2Pnt Pnt, lParam
      .if $invoke(PtInRect, addr [xsi].FaceRect, Pnt) != FALSE
        invoke GetParent, [xsi].hWnd
        mov xbx, xax
        invoke GetWindowLongPtr, [xsi].hWnd, GWL_ID
        invoke SendMessage, xbx, WM_COMMAND, eax, [xsi].hWnd
      .endif
      invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
    .endif
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Button.OnMouseMove
; Purpose:    Event procedure for WM_MOUSEMOVE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Button.OnMouseMove, uses xsi, wParam:WPARAM, lParam:LPARAM
  local Pnt:POINT

  ;DbgText "Button.OnMouseMove"
  SetObject xsi
  .ifBitClr [xsi].dFlags, BTF_DISABLED
    PntS2Pnt Pnt, lParam
    .if $invoke(PtInRect, addr [xsi].FaceRect, Pnt) != FALSE
      .ifBitClr [xsi].dFlags, BTF_PRESSED or BTF_HOVERED
        invoke SetCapture, [xsi].hWnd
        BitSet [xsi].dFlags, BTF_HOVERED
        invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
      .endif
    .else
      .ifBitClr [xsi].dFlags, BTF_PRESSED
        BitClr [xsi].dFlags, BTF_HOVERED
        invoke ReleaseCapture
        invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
      .endif
    .endif
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Button.OnUpdateUIState
; Purpose:    Event procedure for WM_UPDATEUISTATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Button.OnUpdateUIState, uses xsi, wParam:WPARAM, lParam:LPARAM
  ;DbgText "Button.OnUpdateUIState"
  SetObject xsi
  .ifBitSet wParam, BIT01
    BitSet [xsi].dFlags, BTF_SHOW_SHORTCUT
  .else
    BitClr [xsi].dFlags, BTF_SHOW_SHORTCUT
  .endif
  invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Button.OnNcDestroy
; Purpose:    Event procedure for WM_NCDESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Button.OnNcDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  ;DbgText "Button.OnNcDestroy"
  SetObject xsi
  invoke SetWindowLongPtr, [xsi].hWnd, GWLP_USERDATA, NULL
  .ifBitSet [xsi].dFlags, BTF_SELF_INST
    Destroy xsi
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Button.OnSetFont
; Purpose:    Event procedure for WM_SETFONT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Button.OnSetFont, uses xsi, wParam:WPARAM, lParam:LPARAM
  ;DbgText "Button.OnSetFont"
  SetObject xsi
  invoke DeleteObject, $invoke(SelectObject, [xsi].hMemDC, wParam)
  .if lParam != FALSE
    invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Button.OnSetText
; Purpose:    Event procedure for WM_SETTEXT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = TRUE.

Method Button.OnSetText, uses xsi, wParam:WPARAM, lParam:LPARAM
  ;DbgText "Button.OnSetText"
  SetObject xsi
  mov [xsi].pTextBuffer, $invoke(StrNew, lParam)
  invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
  mov eax, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Button.OnSetFocus
; Purpose:    Event procedure for WM_SETFOCUS message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Button.OnSetFocus, uses xsi, wParam:WPARAM, lParam:LPARAM
  ;DbgText "Button.OnSetFocus"
  SetObject xsi
  BitSet [xsi].dFlags, BTF_FOCUSED
  invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
  xor eax, eax
MethodEnd

endif
