; ==================================================================================================
; Title:      I_OcxCont_OleInPlaceSiteWindowless.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of OleInPlaceSiteWindowless Interface for COM OcxContainer objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


externdef IID_IOleInPlaceSiteWindowless:GUID

; --------------------------------------------------------------------------------------------------
; Object:     I_OcxCont_OleInPlaceSiteWindowless
; Purpose:    Extend the IOleInPlaceSiteEx interface. IOleInPlaceSiteWindowless works with
;             IOleInPlaceObjectWindowless which is implemented on the windowless object.

Object I_OcxCont_OleInPlaceSiteWindowless,, I_OcxCont_OleInPlaceSiteEx
  InterfaceMethod   CanWindowlessActivate
  InterfaceMethod   GetCapture
  InterfaceMethod   SetCapture,           BOOL
  InterfaceMethod   GetFocus
  InterfaceMethod   SetFocus,             BOOL
  InterfaceMethod   GetDC,                POINTER, DWORD, POINTER
  InterfaceMethod   ReleaseDC,            HDC
  InterfaceMethod   InvalidateRect,       POINTER, BOOL
  InterfaceMethod   InvalidateRgn,        HANDLE, BOOL
  InterfaceMethod   ScrollRect,           SDWORD, SDWORD, POINTER, POINTER
  InterfaceMethod   AdjustRect,           POINTER
  InterfaceMethod   OnDefWindowMessage,   DWORD, WPARAM, LPARAM, POINTER

  RedefineVariable  pIID,   offset IID_IOleInPlaceSiteWindowless

ObjectEnd


if IMPLEMENT

.code
; ==================================================================================================
;     I_OcxCont_OleInPlaceSiteWindowless implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceSiteWindowless.CanWindowlessActivate
; Purpose:    Inform an object if its container can support it as a windowless object that can be
;             in-place activated.
; Arguments:  None.
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceSiteWindowless.CanWindowlessActivate
  DbgText "I_OcxCont_OleInPlaceSiteWindowless.CanWindowlessActivate", \
          "I_OcxCont_OleInPlaceSiteWindowless"
  mov eax, E_NOTIMPL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceSiteWindowless.GetCapture
; Purpose:    Enable an in-place active, windowless object to capture all mouse messages.
; Arguments:  None.
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceSiteWindowless.GetCapture
  DbgText "I_OcxCont_OleInPlaceSiteWindowless.GetCapture", "I_OcxCont_OleInPlaceSiteWindowless"
  mov eax, E_NOTIMPL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceSiteWindowless.SetCapture
; Purpose:    Inform an object if its container can support it as a windowless object that can be
;             in-place activated.
; Arguments:  Arg1: If TRUE, the container should capture the mouse for the object. If FALSE, the
;                   container should release mouse capture for the object.
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceSiteWindowless.SetCapture,, fCapture:BOOL
  DbgText "I_OcxCont_OleInPlaceSiteWindowless.SetCapture", "I_OcxCont_OleInPlaceSiteWindowless"
  mov eax, E_NOTIMPL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceSiteWindowless.GetFocus
; Purpose:    Called by an in-place active, windowless object to determine whether it still has the
;             keyboard focus.
; Arguments:  None.
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceSiteWindowless.GetFocus
  DbgText "I_OcxCont_OleInPlaceSiteWindowless.GetFocus", "I_OcxCont_OleInPlaceSiteWindowless"
  mov eax, E_NOTIMPL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceSiteWindowless.SetFocus
; Purpose:    Set the keyboard focus for a UI-active, windowless object.
; Arguments:  Arg1: If TRUE, the container should capture the mouse for the object. If FALSE, the
;                   container should release mouse capture for the object.
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceSiteWindowless.SetFocus,, fCapture:BOOL
  DbgText "I_OcxCont_OleInPlaceSiteWindowless.SetFocus", "I_OcxCont_OleInPlaceSiteWindowless"
  mov eax, E_NOTIMPL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceSiteWindowless.GetDC
; Purpose:    Set the keyboard focus for a UI-active, windowless object.
; Arguments:  Arg1: -> rectangle that the object wants to redraw, in client coordinates of the
;                   containing window. If this parameter is NULL, the object's full extent is
;                   redrawn.
;             Arg2: A combination of values from the OLEDCFLAGS enumeration.
;             Arg3: -> returned device context.
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceSiteWindowless.GetDC,, pRect:POINTER, dFlags:DWORD, pDC:POINTER
  DbgText "I_OcxCont_OleInPlaceSiteWindowless.GetDC", "I_OcxCont_OleInPlaceSiteWindowless"
  mov eax, E_NOTIMPL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceSiteWindowless.ReleaseDC
; Purpose:    Release the device context previously obtained by a call to
;             IOleInPlaceSiteWindowless::GetDC.
; Arguments:  Arg1: The device context to be released.
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceSiteWindowless.ReleaseDC,, hDC:HDC
  DbgText "I_OcxCont_OleInPlaceSiteWindowless.ReleaseDC", "I_OcxCont_OleInPlaceSiteWindowless"
  mov eax, E_NOTIMPL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceSiteWindowless.InvalidateRect
; Purpose:    Enable an object to invalidate a specified rectangle of its in-place image on
;             the screen.
; Arguments:  Arg1: The rectangle to be invalidated, in client coordinates of the containing window.
;                   If this parameter is NULL, the object's full extent is invalidated.
;             Arg2: Specifies whether the background within the update region is to be erased when
;                   the region is updated. If this parameter is TRUE, the background is erased.
;                   If this parameter is FALSE, the background remains unchanged.
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceSiteWindowless.InvalidateRect,, pRect:POINTER, fErase:BOOL
  DbgText "I_OcxCont_OleInPlaceSiteWindowless.InvalidateRect", "I_OcxCont_OleInPlaceSiteWindowless"
  mov eax, E_NOTIMPL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceSiteWindowless.InvalidateRgn
; Purpose:    Enable an object to invalidate a specified region of its in-place image on the screen.
; Arguments:  Arg1: The region to invalidate, in client coordinates of the containing window.
;                   If this parameter is NULL, the object's full extent is invalidated.
;             Arg2: Specifies whether the background within the update region is to be erased when
;                   the region is updated. If this parameter is TRUE, the background is erased.
;                   If this parameter is FALSE, the background remains unchanged.
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceSiteWindowless.InvalidateRgn,, hRgn:HANDLE, fErase:BOOL
  DbgText "I_OcxCont_OleInPlaceSiteWindowless.InvalidateRgn", "I_OcxCont_OleInPlaceSiteWindowless"
  mov eax, E_NOTIMPL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceSiteWindowless.ScrollRect
; Purpose:    Enable an object to scroll an area within its in-place active image on the screen.
; Arguments:  Arg1: The amount to scroll the x-axis.
;             Arg2: The amount to scroll the y-axis.
;             Arg3: The rectangle to scroll, in client coordinates of the containing window.
;                   A value of NULL indicates the full object.
;             Arg4: The rectangle to clip. Only pixels scrolling into this rectangle are drawn.
;                   Pixels scrolling out are not. If this parameter is NULL, the rectangle is not
;                   clipped.
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceSiteWindowless.ScrollRect,, sdX:SDWORD, sdY:SDWORD, \
                                                       pRectScroll:POINTER, pRectClip:POINTER
  DbgText "I_OcxCont_OleInPlaceSiteWindowless.ScrollRect", "I_OcxCont_OleInPlaceSiteWindowless"
  mov eax, E_NOTIMPL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceSiteWindowless.AdjustRect
; Purpose:    Adjust a specified rectangle if it is entirely or partially covered by overlapping,
;             opaque objects.
; Arguments:  Arg1: The rectangle to be adjusted.
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceSiteWindowless.AdjustRect,, pRect:POINTER
  DbgText "I_OcxCont_OleInPlaceSiteWindowless.AdjustRect", "I_OcxCont_OleInPlaceSiteWindowless"
  mov eax, E_NOTIMPL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceSiteWindowless.OnDefWindowMessage
; Purpose:    Invoke the default processing for all messages passed to an object.
; Arguments:  Arg1: The identifier for the window message provided to the container by Windows.
;             Arg2: A parameter for the window message provided to the container by Windows.
;             Arg3: A parameter for the window message provided to the container by Windows.
;             Arg4: -> result code for the window message.
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceSiteWindowless.OnDefWindowMessage,, dMsg:DWORD, \
                                              wParam:WPARAM, lParam:LPARAM, pResult:POINTER
  DbgText "I_OcxCont_OleInPlaceSiteWindowless.OnDefWindowMessage", \
          "I_OcxCont_OleInPlaceSiteWindowless"
  mov eax, E_NOTIMPL
MethodEnd

endif
