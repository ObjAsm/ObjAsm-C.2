; ==================================================================================================
; Title:      MsgInterceptor.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of Windows MsgInterceptor objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Object:     MsgInterceptor
; Purpose:    MsgInterceptor is an object designed to intercept messages send to a window.
;             To use it, its WndProc must be redefined to get the property used to store the object
;             instance. By default, szMsgIptorProp name is used, but if more than one MsgInterceptor
;             is used on the same window, to avoid conflicts, different property names must be used!
;             A descendant object must also define the intercepted events and the handling methods.

Object MsgInterceptor, MsgInterceptorID, Streamable
  VirtualMethod     Dispatch,             HWND, DWORD, WPARAM, LPARAM
  RedefineMethod    Done
  RedefineMethod    Init,                 POINTER, HWND, PSTRING
  VirtualMethod     WndProc,              DWORD, WPARAM, LPARAM

  DefineVariable    hWnd,                 HWND,       0
  DefineVariable    pPrevWndProc,         POINTER,    NULL
  DefineVariable    pPropName,            PSTRING,    NULL
ObjectEnd


; ==================================================================================================

if IMPLEMENT

CStr szMsgIptorProp, "MsgIptor"

; --------------------------------------------------------------------------------------------------
; Method:     MsgInterceptor.Dispatch
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Window handle.
;             Arg2: Message identifier.
;             Arg3: First message parameter.
;             Arg4: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.

Method MsgInterceptor.Dispatch, uses xsi, hWnd:HWND, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg
  SetObject xsi
  DispatchEvent <CallWindowProc, [xsi].pPrevWndProc, hWnd>        ;xsi -> Object Instance
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MsgInterceptor.Done
; Purpose:    Finalize MsgInterceptor object.
; Arguments:  None.
; Return:     Nothing.

Method MsgInterceptor.Done, uses xsi
  SetObject xsi
  .if [xsi].dErrorCode == OBJ_OK
    invoke SetWindowLongPtr, [xsi].hWnd, GWLP_WNDPROC, [xsi].pPrevWndProc
    invoke RemoveProp, [xsi].hWnd, [xsi].pPropName
  .endif
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MsgInterceptor.Init
; Purpose:    Initialize MsgInterceptor object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Intercepted window handle.
;             Arg3: -> Property name.
; Return:     Nothing.

Method MsgInterceptor.Init, uses xsi, pOwner:POINTER, hWnd:HWND, pPropName:PSTRING
  SetObject xsi
  m2m [xsi].hWnd, hWnd, xax
  m2m [xsi].pPropName, pPropName, xax
  ACall xsi.Init, pOwner

  ;Intercept the window
  .if $invoke(SetProp, hWnd, pPropName, xsi) != FALSE
    invoke SetWindowLongPtr, hWnd, GWLP_WNDPROC, $MethodAddr(xsi::MsgInterceptor.WndProc)
    mov [xsi].pPrevWndProc, xax
  .else
    OCall xsi.ErrorReport, NULL, MIP_SETPROP_ERROR
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MsgInterceptor.WndProc
; Purpose:    Processing of window messages. Before invoking it, the window must be subclassed.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.
; Note:       Window handle is passed in pSelf (hidden parameter).

Method MsgInterceptor.WndProc,, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  invoke GetProp, pSelf, offset szMsgIptorProp
  ASSERT xax, "MsgInterceptor.WndProc failed to retrieve windows property"
  OCall xax::MsgInterceptor.Dispatch, pSelf, uMsg, wParam, lParam
MethodEnd

endif
