; ==================================================================================================
; Title:      FlipBox.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support for FlipBox objects for Splitter controls.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


;FlipBox button IDs
FBB_BACK            equ   BIT00
FBB_FRWD            equ   BIT01
FBB_BOTH            equ   FBB_BACK or FBB_FRWD

;FlipBox flags
FBF_BACK_ENABLED    equ   FBB_BACK
FBF_FRWD_ENABLED    equ   FBB_FRWD
FBF_BOTH_ENABLED    equ   FBF_BACK_ENABLED or FBF_FRWD_ENABLED
FBF_VERTICAL        equ   0
FBF_HORIZONTAL      equ   BIT02


;FlipBox parent notification flags
FBN_BACK_PRESSED    equ   FBB_BACK                      ;Only FBN_BACK_PRESSED, FBN_FRWD_PRESSED
FBN_FRWD_PRESSED    equ   FBB_FRWD                      ;  or none at the same time
FBN_SHFT_PRESSED    equ   BIT02                         ;SHIFT key pressed
FBN_CTRL_PRESSED    equ   BIT03                         ;CONTROL key pressed
FBN_HIDE_CTRL       equ   BIT04                         ;Hide the FlipBox

DEF_FLIPBOX struc
  xCtlID          XWORD     ?                           ;Contol ID
  dFlags          DWORD     ?                           ;FBF_VERTICAL, FBF_HORIZONTAL
DEF_FLIPBOX ends
PDEF_FLIPBOX typedef ptr DEF_FLIPBOX


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     FlipBox
; Purpose:    Implement a FlipBox GDI object. Based on a subclassed ScrollBar.

Object FlipBox, FlipBoxID, WinControl
  VirtualMethod     CaptureMouse,   DWORD
  RedefineMethod    Done
  VirtualMethod     EnableButton,   DWORD
  RedefineMethod    Init,           POINTER, HWND, PDEF_FLIPBOX
  RedefineMethod    Load,           $ObjPtr(Stream), PDESER_INFO
  RedefineMethod    Store,          $ObjPtr(Stream)
  RedefineMethod    WndProc,        DWORD, WPARAM, LPARAM

  VirtualEvent      OnMouseMove,    WM_MOUSEMOVE
  VirtualEvent      OnLButtonDown,  WM_LBUTTONDOWN

  DefineVariable    dFlags,         DWORD,    FBF_VERTICAL
  DefineVariable    hParent,        HWND,     0
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FlipBox.CaptureMouse
; Purpose:    Sets the mouse capture.
; Arguments:  Arg1: Action = TRUE/FALSE.
; Return:     Nothing.

Method FlipBox.CaptureMouse,, dAction:DWORD
  SetObject xcx
  .if dAction == FALSE
    invoke ReleaseCapture
  .else
    invoke SetCapture, [xcx].hWnd
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FlipBox.Done
; Purpose:    Finalize the FlipBox object.
; Arguments:  None.
; Return:     Nothing.

Method FlipBox.Done, uses xsi
  SetObject xsi
  Unsubclass FlipBox                                ;Uses xsi
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FlipBox.EnableButton
; Purpose:    Enables or disables a button of the FlipBox.
; Arguments:  Arg1: Button flags (FBB_xxx).
; Return:     Nothing.

Method FlipBox.EnableButton, uses xsi, dBtnState:DWORD
;  DbgText "FlipBox.EnableButton"
  SetObject xsi
  .ifBitClr dBtnState, FBB_FRWD or FBB_BACK
    invoke SendMessage, [xsi].hWnd, SBM_ENABLE_ARROWS, ESB_DISABLE_BOTH, 0
    and [xsi].dFlags, not FBF_BOTH_ENABLED
  .else
    invoke SendMessage, [xsi].hWnd, SBM_ENABLE_ARROWS, ESB_ENABLE_BOTH, 0
    or [xsi].dFlags, FBF_BOTH_ENABLED
    .ifBitClr dBtnState, FBB_FRWD
      invoke SendMessage, [xsi].hWnd, SBM_ENABLE_ARROWS, ESB_DISABLE_RTDN, 0
      and [xsi].dFlags, not FBF_FRWD_ENABLED
    .endif
    .ifBitClr dBtnState, FBB_BACK
      invoke SendMessage, [xsi].hWnd, SBM_ENABLE_ARROWS, ESB_DISABLE_LTUP, 0
      and [xsi].dFlags, not FBF_BACK_ENABLED
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FlipBox.Init
; Purpose:    Initialize the FlipBox object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> DEF_FLIPBOX initialization structure.
; Return:     Nothing.

Method FlipBox.Init, uses xbx xdi xsi, pOwner:POINTER, hParent:HWND, pDefStruc:PDEF_FLIPBOX
  local SysSize:POINT

  SetObject xsi
  m2m [xsi].hParent, hParent, xax
  mov SysSize.x, $32($invoke(GetSystemMetrics, SM_CXHSCROLL))     ;Get ScrollBar system metrics
  mov SysSize.y, $32($invoke(GetSystemMetrics, SM_CYHSCROLL))

  mov xdi, $invoke(GetDesktopWindow)

  mov xbx, pDefStruc
  assume xbx:PDEF_FLIPBOX
  mov edx, [xbx].dFlags
  or [xsi].dFlags, edx
  .ifBitSet [xsi].dFlags, FBF_HORIZONTAL
    shl SysSize.x, 1
    mov eax, WS_CHILD
  .else
    shl SysSize.y, 1
    mov eax, WS_CHILD or SBS_VERT
  .endif

  invoke CreateWindowEx, WS_EX_TOOLWINDOW, $OfsCStr("ScrollBar"), NULL, eax, \
                         0, 0, SysSize.x, SysSize.y, \
                         xdi, [xbx].xCtlID, hInstance, 0
  assume xbx:NOTHING
  ACall xsi.Init, pOwner, xax
  Subclass FlipBox                             ;Uses xsi
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FlipBox.Load
; Purpose:    Load and initialize the Splitter instance from a stream object.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> DESER_INFO.
; Return:     Nothing.

Method FlipBox.Load, uses xbx xsi, pStream:$ObjPtr(Stream), pDeserInfo:PDESER_INFO
  SetObject xsi
  ACall xsi.Load, pStream, pDeserInfo                   ;Load pSelf, ..., hWnd
  mov xcx, pDeserInfo                                   ;WinPrimer returns the previous hWnd
  mov xbx, [xcx].DESER_INFO.pDesLUT
  OCall xbx::DesLUT.Insert, xax, [xsi].hWnd

  mov [xsi].dFlags, $32($OCall(pStream::Stream.BinRead32))
  OCall pStream::Stream.BinReadX                       ;Previous hParent
  OCall xbx::DesLUT.Find, xax
  .if eax == OBJ_OK
    mov [xsi].hParent, xcx
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FlipBox.Store
; Purpose:    Store the streamable instance in a stream object. Descendant objects should redefine
;             this method and store new members.
; Arguments:  Arg1: -> Stream object.
; Return:     Nothing.

Method FlipBox.Store, uses xsi, pStream:$ObjPtr(Stream)
  SetObject xsi
  ACall xsi.Store, pStream                              ;Store pSelf, ..., hWnd

  OCall pStream::Stream.BinWrite32, [xsi].dFlags
  OCall pStream::Stream.BinWriteX, [xsi].hParent
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FlipBox.OnLButtonDown
; Purpose:    Event procedure for WM_LBUTTONDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax: Zero if handled.

Method FlipBox.OnLButtonDown, uses xsi, wParam:WPARAM, lParam:LPARAM
  local CursorPos:POINT, WndRect:RECT, NotifHdr:NMHDR

;  DbgText "FlipBox.OnLButtonDown"
  SetObject xsi
  invoke GetCursorPos, addr CursorPos
  invoke GetWindowRect, [xsi].hWnd, addr WndRect
  .ifBitSet [xsi].dFlags, FBF_HORIZONTAL
    mov eax, WndRect.right
    add eax, WndRect.left
    shr eax, 1
    .if eax > CursorPos.x
      mov edx, FBN_BACK_PRESSED
      test [xsi].dFlags, FBF_BACK_ENABLED
    .else
      mov edx, FBN_FRWD_PRESSED
      test [xsi].dFlags, FBF_FRWD_ENABLED
    .endif
  .else
    mov eax, WndRect.bottom
    add eax, WndRect.top
    shr eax, 1
    .if eax > CursorPos.y
      mov edx, FBN_BACK_PRESSED
      test [xsi].dFlags, FBF_BACK_ENABLED
    .else
      mov edx, FBN_FRWD_PRESSED
      test [xsi].dFlags, FBF_FRWD_ENABLED
    .endif
  .endif
  .if !ZERO?
    mov NotifHdr.code, edx
    .ifBitSet wParam, MK_SHIFT
      BitSet NotifHdr.code, FBN_SHFT_PRESSED
    .endif
    .ifBitSet wParam, MK_CONTROL
      BitSet NotifHdr.code, FBN_CTRL_PRESSED
    .endif
    mrm NotifHdr.hwndFrom, [xsi].hWnd, xax
    invoke GetMenu, xax
    mov NotifHdr.idFrom, xax
    OCall xsi.CaptureMouse, FALSE
    invoke SendMessage, [xsi].hParent, WM_NOTIFY, NotifHdr.idFrom, addr NotifHdr
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FlipBox.OnMouseMove
; Purpose:    Event procedure for WM_MOUSEMOVE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax: Zero if handled.

Method FlipBox.OnMouseMove, uses xsi, wParam:WPARAM, lParam:LPARAM
  local WndRect:RECT, CursorPos:POINT, NotifHdr:NMHDR

;  DbgText "FlipBox.OnMouseMove"
  SetObject xsi
  invoke GetWindowRect, [xsi].hWnd, addr WndRect
  invoke GetCursorPos, addr CursorPos
  invoke PtInRect, addr WndRect, CursorPos
  .if eax == FALSE
    ;Mouse left the FlipBox control
    OCall xsi.CaptureMouse, FALSE
    mrm NotifHdr.hwndFrom, [xsi].hWnd, xax
    invoke GetMenu, xax
    mov NotifHdr.idFrom, xax
    mov NotifHdr.code, FBN_HIDE_CTRL
    invoke SendMessage, [xsi].hParent, WM_NOTIFY, NotifHdr.idFrom, addr NotifHdr
    xor eax, eax
  .else
    invoke CallWindowProc, [xsi].pPrevWndProc, [xsi].hWnd, WM_MOUSEMOVE, wParam, lParam
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FlipBox.WndProc
; Purpose:    Processing of window messages. Before invoking it, the window must be subclassed.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.
; Note:       Window HANDLE is passed in pSelf (hidden argument).

Method FlipBox.WndProc,, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg,, "FlipBox"
  GetSubclassingInst FlipBox, pSelf
  OCall xax::FlipBox.Dispatch, pSelf, uMsg, wParam, lParam
MethodEnd

endif
