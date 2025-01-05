; ==================================================================================================
; Title:      ScrollBar.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of ScrollBar objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


DEF_SCROLLBAR struc
  xCtlID        XWORD     ?         ;Contol ID
  dStyle        DWORD     ?         ;Style
  dExStyle      DWORD     ?         ;Extended style
  pTitle        PSTRING   ?         ;-> Window title
  union
    rect        RECT      {}
    struct
      sdPosX    SDWORD    ?         ;X position
      sdPosY    SDWORD    ?         ;Y position
      dWidth    DWORD     ?         ;Width
      dHeight   DWORD     ?         ;Height
    ends
  ends
DEF_SCROLLBAR ends
PDEF_SCROLLBAR typedef ptr DEF_SCROLLBAR


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     ScrollBar
; Purpose:    Implement a thin wrapper around the ScrollBar GDI object.

Object ScrollBar, ScrollBarID, WinControl               ;Class "ScrollBar"
  RedefineMethod    Done
  RedefineMethod    Init,         POINTER, HWND, PDEF_SCROLLBAR
  RedefineMethod    WndProc,      DWORD, WPARAM, LPARAM
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ScrollBar.Done
; Purpose:    Finalize the ScrollBar object.
; Arguments:  None.
; Return:     Nothing.

Method ScrollBar.Done, uses xsi
  SetObject xsi
  Unsubclass ScrollBar                                  ;Uses xsi
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ScrollBar.Init
; Purpose:    Initialize the ScrollBar object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> DEF_SCROLLBAR initialization structure.
; Return:     Nothing.

Method ScrollBar.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND, pDefStruc:PDEF_SCROLLBAR
  SetObject xsi
  mov xbx, pDefStruc
  assume xbx:PDEF_SCROLLBAR
  mov eax, [xbx].dStyle
  or eax, WS_CHILD or WS_VISIBLE
  invoke CreateWindowEx, [xbx].dExStyle, $OfsCStr("ScrollBar"), [xbx].pTitle, eax, \
                         [xbx].sdPosX, [xbx].sdPosY, [xbx].dWidth, [xbx].dHeight, \
                         hParent, [xbx].xCtlID, hInstance, 0
  assume xbx:NOTHING
  ACall xsi.Init, pOwner, xax
  Subclass ScrollBar                                    ;Uses xsi
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ScrollBar.WndProc
; Purpose:    Processing of window messages. Before invoking it, the window must be subclassed.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     xax = This value is the result of the message processing and depends on the message ID.
; Note:       Window HANDLE is passed in pSelf (hidden argument).

Method ScrollBar.WndProc,, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg,, "ScrollBar"
  GetSubclassingInst ScrollBar, pSelf
  OCall xax::ScrollBar.Dispatch, pSelf, uMsg, wParam, lParam
MethodEnd

endif