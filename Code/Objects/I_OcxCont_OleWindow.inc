; ==================================================================================================
; Title:      I_OcxCont_OleWindow.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of OleWindow Interface for COM OcxContainer objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


externdef IID_IOleWindow:GUID

; --------------------------------------------------------------------------------------------------
; Object: 	  I_OcxCont_OleWindow
; Purpose:	  The IOleWindow interface provides methods that allow an application to obtain the
;         	  HANDLE to the various windows that participate in in-place activation, and also to
;         	  enter and exit context-sensitive help mode.

Object I_OcxCont_OleWindow,, IUnknown
  RedefineMethod    Init,                   POINTER, HWND         ;-> Owner, hWnd

  InterfaceMethod   GetWindow,              POINTER
  InterfaceMethod   ContextSensitiveHelp,   BOOL

  RedefineVariable  pIID,   offset IID_IOleWindow

  DefineVariable    hWnd,       HANDLE,         0

ObjectEnd


if IMPLEMENT

.code
; ==================================================================================================
;     I_OcxCont_OleWindow implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleWindow.Init
; Purpose:    Initialize the I_OcxCont_OleWindow COM object.
; Arguments:  Arg1: -> Owner (Component object).
;             Arg2: Window handle this interface referes to.
; Return:     Nothing.

Method I_OcxCont_OleWindow.Init,, pOwner:POINTER, hWnd:HWND
  DbgText "I_OcxCont_OleWindow.Init", "I_OcxCont_OleWindow"
  SetObject xcx
  m2m [xcx].hWnd, hWnd, xax
  ACall xcx.Init, pOwner
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleWindow.GetWindow
; Purpose:    Retrieve a handle of one of the windows participating in in-place activation
;             (frame, document, parent, or in-place object window).
; Arguments:  Arg1: -> Variable that receives the window handle.
; Return:     eax = HRESULT.

Method I_OcxCont_OleWindow.GetWindow,, pWndHandle:POINTER
  DbgText "I_OcxCont_OleWindow.GetWindow", "I_OcxCont_OleWindow"
  .if pWndHandle != NULL
    SetObject xcx
    mov xdx, pWndHandle
    m2m HANDLE ptr [xdx], [xcx].hWnd, xax
    xor eax, eax                                      ;S_OK
  .else
    mov eax, E_POINTER
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleWindow.ContextSensitiveHelp
; Purpose:    Determine whether context-sensitive help mode should be entered during an in-place
;             activation session.
; Arguments:  Arg1: TRUE if help mode should be entered; FALSE if it should be exited.
; Return:     eax = HRESULT.

Method I_OcxCont_OleWindow.ContextSensitiveHelp,, bEnterMode:BOOL
  DbgText "I_OcxCont_OleWindow.ContextSensitiveHelp", "I_OcxCont_OleWindow"
  mov eax, E_NOTIMPL
MethodEnd

endif
