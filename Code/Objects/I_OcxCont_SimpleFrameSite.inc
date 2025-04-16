; ==================================================================================================
; Title:      I_OcxCont_SimpleFrameSite.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of SimpleFrameSite Interface for COM OcxContainer objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


externdef IID_ISimpleFrameSite:GUID

; --------------------------------------------------------------------------------------------------
; Object:     I_OcxCont_SimpleFrameSite
; Purpose:    Provide simple frame controls that act as simple containers for other nested controls.
;             Some controls merely contain other controls. In such cases, the simple control
;             container, called a simple frame, need not implement all container requirements. It
;             can delegate most of the interface calls from its contained controls to the outer
;             container that manages the simple frame. To support what are called simple frame
;             controls, a container implements this interface as well as other site interfaces such
;             as IOleControlSite. An example of a simple frame control is a group box that only
;             needs to capture a few keystrokes for its contained controls to implement the correct
;             tab or arrow key behavior, but does not want to handle every other message. Through
;             the two methods of this interface, the simple frame control passes messages to its
;             control site both before and after its own processing. If that site is itself a
;             simple frame, it can continue to pass messages up the chain.

Object I_OcxCont_SimpleFrameSite,, IUnknown
  InterfaceMethod   PreMessageFilter,   HWND, DWORD, WPARAM, LPARAM, POINTER, POINTER
  InterfaceMethod   PostMessageFilter,  HWND, DWORD, WPARAM, LPARAM, POINTER, DWORD

  RedefineVariable  pIID,   offset IID_ISimpleFrameSite
ObjectEnd


if IMPLEMENT

.code
; ==================================================================================================
;     I_OcxCont_SimpleFrameSite implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_SimpleFrameSite.PreMessageFilter
; Purpose:    Provide a site with the opportunity to process a message that is received by a
;             control's own window before the control itself does any processing.
; Arguments:  Arg1: handle of the control window receiving the message.
;             Arg2: The message received by the simple frame site.
;             Arg3: The WPARAM of the message.
;             Arg4: The LARAM of the message.
;             Arg5: -> Variable that receives the result of the message processing.
;             Arg6: -> Variable that will be passed to ISimpleFrameSite::PostMessageFilter if it is
;                   called later. This parameter should only contain allocated data if this method
;                   returns S_OK so it will also receive a call to PostMessageFilter which can free
;                   the allocation. The caller is not in any way responsible for anything returned
;                   in this parameter.
; Return:     eax = HRESULT.

Method I_OcxCont_SimpleFrameSite.PreMessageFilter,, hWnd:HWND, dMsg:DWORD, \
                                                    wParam:WPARAM, lParam:LPARAM, \
                                                    pResult:POINTER, pCookie:POINTER
  DbgText "I_OcxCont_SimpleFrameSite.PreMessageFilter", "I_OcxCont_SimpleFrameSite"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_SimpleFrameSite.PostMessageFilter
; Purpose:    Send the simple frame site a message that is received by a control's own window after
;             the control has processed the message.
; Arguments:  Arg1: handle of the control window receiving the message.
;             Arg2: The message received by the simple frame site.
;             Arg3: The WPARAM of the message.
;             Arg4: The LARAM of the message.
;             Arg5: -> Variable that receives the result of the message processing.
;             Arg6: The value that was returned by ISimpleFrameSite::PreMessageFilter through its
;                   pCookie parameter.
; Return:     eax = HRESULT.

Method I_OcxCont_SimpleFrameSite.PostMessageFilter,, hWnd:HWND, dMsg:DWORD, \
                                                     wParam:WPARAM, lParam:LPARAM, \
                                                     pResult:POINTER, dCookie:DWORD
  DbgText "I_OcxCont_SimpleFrameSite.PostMessageFilter", "I_OcxCont_SimpleFrameSite"
  xor eax, eax                                          ;S_OK
MethodEnd

endif
