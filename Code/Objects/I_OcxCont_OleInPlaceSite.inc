; ==================================================================================================
; Title:      I_OcxCont_OleInPlaceSite.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of OleInPlaceSite Interface for COM OcxContainer objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


externdef IID_IOleInPlaceSite:GUID
externdef IID_IOleInPlaceObject:GUID

; --------------------------------------------------------------------------------------------------
; Object:     I_OcxCont_OleInPlaceSite
; Purpose:    Manage the interaction between the container and the object's in-place client site.
;             Recall that the client site is the display site for embedded objects, and provides
;             position and conceptual information about the object.
;             This interface provides methods that manage in-place objects. With IOleInPlaceSite,
;             you can determine if an object can be activated and manage its activation and
;             deactivation. You can notify the container when one of its objects is being activated
;             and inform the container that a composite menu will replace the container's regular
;             menu. It provides methods that make it possible for the in-place object to retrieve
;             the window object hierarchy, and the position in the parent window where the object
;             should place its in-place activation window. Finally, it determines how the container
;             scrolls the object, manages the object undo state, and notifies the object when its
;             borders have changed.

Object I_OcxCont_OleInPlaceSite,, I_OcxCont_OleWindow
  InterfaceMethod   CanInPlaceActivate
  InterfaceMethod   OnInPlaceActivate
  InterfaceMethod   OnUIActivate
  InterfaceMethod   GetWindowContext,   POINTER, POINTER, PRECT, PRECT, LPOLEINPLACEFRAMEINFO
  InterfaceMethod   Scroll,             DWORD
  InterfaceMethod   OnUIDeactivate,     BOOL
  InterfaceMethod   OnInPlaceDeactivate
  InterfaceMethod   DiscardUndoState
  InterfaceMethod   DeactivateAndUndo
  InterfaceMethod   OnPosRectChange,    ptr RECT

  RedefineVariable  pIID,   offset IID_IOleInPlaceSite
ObjectEnd


if IMPLEMENT

.code
; ==================================================================================================
;     I_OcxCont_OleInPlaceSite implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceSite.CanInPlaceActivate
; Purpose:    Determine whether the container can activate the object in place.
; Arguments:  None.
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceSite.CanInPlaceActivate
  DbgText "I_OcxCont_OleInPlaceSite.CanInPlaceActivate", "I_OcxCont_OleInPlaceSite"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceSite.OnInPlaceActivate
; Purpose:    Notify the container that one of its objects is being activated in place.
; Arguments:  None.
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceSite.OnInPlaceActivate
  DbgText "I_OcxCont_OleInPlaceSite.OnInPlaceActivate", "I_OcxCont_OleInPlaceSite"

  SetOwner xcx, OcxClientSite
  mov [xcx].dInPlaceActive, TRUE
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceSite.OnUIActivate
; Purpose:    Notify the container that the object is about to be activated in place and that the
;             object is going to replace the container's main menu with an in-place composite menu.
; Arguments:  None.
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceSite.OnUIActivate
  DbgText "I_OcxCont_OleInPlaceSite.OnUIActivate", "I_OcxCont_OleInPlaceSite"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceSite.GetWindowContext
; Purpose:    Enable an in-place object to retrieve the window interfaces that form the window
;             object hierarchy, and the position in the parent window where the object's in-place
;             activation window should be located.
; Arguments:  Arg1: -> IOleInPlaceFrame pointer variable that receives the interface pointer to the
;                   frame. If an error occurs, the implementation must set ppFrame to NULL.
;             Arg2: -> IOleInPlaceUIWindow pointer variable that receives the interface pointer to
;                   the document window. If the document window is the same as the frame window,
;                   ppDoc is set to NULL. In this case, the object can only use ppFrame or border
;                   negotiation. If an error is returned, the implementation must set ppDoc to NULL.
;             Arg3: -> RECT structure for the rectangle containing the position of the in-place
;                   object in the client coordinates of its parent window. If an error is returned,
;                   this parameter must be set to NULL.
;             Arg4: -> RECT structure for the outer rectangle containing the in-place object's
;                   position rectangle (pPosRect). This rectangle is relative to the client area
;                   of the object's parent window. If an error is returned, this parameter must be
;                   set to NULL.
;             Arg5: -> OLEINPLACEFRAMEINFO structure the container is to fill in with appropriate
;                   data. If an error is returned, this parameter must be set to NULL.
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceSite.GetWindowContext, uses xsi, ppFrame:POINTER, ppDoc:POINTER, \
                                                            pPosRect:ptr RECT, pClipRect:ptr RECT, \
                                                            pFrameInfo:ptr OLEINPLACEFRAMEINFO
  DbgText "I_OcxCont_OleInPlaceSite.GetWindowContext", "I_OcxCont_OleInPlaceSite"
  SetOwner xsi, OcxClientSite
  ;Copy RECTs
  mov xcx, pPosRect
  CloneRect RECT ptr [xcx], [xsi].CtrlRect, xax, xdx
  mov xcx, pClipRect
  CloneRect RECT ptr [xcx], [xsi].ClipRect, xax, xdx

  .if ppFrame != NULL
    mov xdx, ppFrame
    mrm POINTER ptr [xdx], [xsi].pIOleInPlaceFrame, xcx
    ICall xcx::IOleInPlaceFrame.AddRef
  .endif

  .if ppDoc != NULL
    mov xcx, ppDoc
    m2z POINTER ptr [xcx]
  .endif

  mov xax, pFrameInfo
  mov [xax].OLEINPLACEFRAMEINFO.cb, sizeof OLEINPLACEFRAMEINFO
  m2z [xax].OLEINPLACEFRAMEINFO.fMDIApp
  mov xcx, [xsi].pOwner
  m2m [xax].OLEINPLACEFRAMEINFO.hwndFrame, [xcx].$Obj(OcxContainer).hWndSite, xdx
  m2z [xax].OLEINPLACEFRAMEINFO.haccel
  m2z [xax].OLEINPLACEFRAMEINFO.cAccelEntries

  xor eax, eax                                        ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceSite.Scroll
; Purpose:    Instruct the container to scroll the view of the object by the specified number of px.
; Arguments:  Arg1: The number of pixels by which to scroll in the X and Y directions.
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceSite.Scroll,, dScrollExtant:DWORD
  DbgText "I_OcxCont_OleInPlaceSite.Scroll", "I_OcxCont_OleInPlaceSite"
  mov eax, S_FALSE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceSite.OnUIDeactivate
; Purpose:    Notify the container that it should reinstall its user interface and take focus,
;             and whether or not the object has an undoable state.
; Arguments:  Arg1: Specifies whether the object can undo changes (TRUE) or not (FALSE).
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceSite.OnUIDeactivate,, bUndoable:BOOL
  DbgText "I_OcxCont_OleInPlaceSite.OnUIDeactivate", "I_OcxCont_OleInPlaceSite"
  xor eax, eax                                        ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceSite.OnInPlaceDeactivate
; Purpose:    Notify the container that the object is no longer active in place.
; Arguments:  None.
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceSite.OnInPlaceDeactivate
  DbgText "I_OcxCont_OleInPlaceSite.OnInPlaceDeactivate", "I_OcxCont_OleInPlaceSite"
  SetOwner xcx, OcxClientSite
  m2z [xcx].dInPlaceActive
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceSite.DiscardUndoState
; Purpose:    Instruct the container to discard its undo state. The container should not call
;             IOleInPlaceObject::ReActivateAndUndo.
; Arguments:  None.
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceSite.DiscardUndoState
  DbgText "I_OcxCont_OleInPlaceSite.DiscardUndoState", "I_OcxCont_OleInPlaceSite"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceSite.DeactivateAndUndo
; Purpose:    Deactivate the object, ends the in-place session, and reverts to the container's
;             saved undo state.
; Arguments:  None.
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceSite.DeactivateAndUndo
  DbgText "I_OcxCont_OleInPlaceSite.DeactivateAndUndo", "I_OcxCont_OleInPlaceSite"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceSite.OnPosRectChange
; Purpose:    Notify the container that the object extents have changed.
; Arguments:  Arg1: -> RECT structure that contains the position of the in-place object in the
;                   client coordinates of its parent window.
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceSite.OnPosRectChange,, pPosRect:ptr RECT
  DbgText "I_OcxCont_OleInPlaceSite.OnPosRectChange", "I_OcxCont_OleInPlaceSite"
  SetOwner xcx, OcxClientSite
  ;Save the new position rect
  mov xdx, pPosRect
  CloneRect [xcx].CtrlRect, RECT ptr [xdx], xax

  ;Reposition the control
  .if [xcx].pIOleInPlaceObject != NULL
    lea xdx, [xcx].CtrlRect
    lea xax, [xcx].ClipRect
    ICall [xcx].pIOleInPlaceObject::IOleInPlaceObject.SetObjectRects, xdx, xax
  .else
    xor eax, eax                                        ;S_OK
  .endif
MethodEnd

endif
