; ==================================================================================================
; Title:      I_OcxCont_OleInPlaceSiteEx.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of OleInPlaceSiteEx Interface for COM OcxContainer objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


externdef IID_IOleInPlaceSiteEx:GUID

; --------------------------------------------------------------------------------------------------
; Object:     I_OcxCont_OleInPlaceFrame
; Purpose:    Provides an additional set of activation and deactivation notification methods that
;             enable an object to avoid unnecessary flashing on the screen when the object is
;             activated and deactivated. When an object is activated, it does not know if its visual
;             display is already correct. When the object is deactivated, the container does not
;             know if the visual display is correct. To avoid a redraw and the associated screen
;             flicker in both cases, the container can provide this extension to IOleInPlaceSite.

Object I_OcxCont_OleInPlaceSiteEx,, I_OcxCont_OleInPlaceSite
  InterfaceMethod   OnInPlaceActivateEx,          POINTER, DWORD
  InterfaceMethod   OnInPlaceDeactivateEx,        BOOL
  InterfaceMethod   RequestUIActivate

  RedefineVariable  pIID,   offset IID_IOleInPlaceSiteEx
ObjectEnd


if IMPLEMENT

.code
; ==================================================================================================
;     I_OcxCont_OleInPlaceSiteEx implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceSiteEx.OnInPlaceActivateEx
; Purpose:    Called by the embedded object to determine whether it needs to redraw itself
;             upon activation.
; Arguments:  Arg1: -> BOOL that receives the current redraw status. The status is TRUE if the
;                   object need not redraw itself upon activation and FALSE otherwise. Windowless
;                   objects usually do not need the value returned by this parameter and may pass
;                   a NULL POINTER to save the container the burden of computing this value.
;             Arg2: Indicates whether the object is activated as a windowless object. This
;                   parameter takes values from the ACTIVATEFLAGS enumeration.
;                   See IOleInPlaceSiteWindowless for more information on windowless objects.
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceSiteEx.OnInPlaceActivateEx,, pfNoRedraw:POINTER, dFlags:DWORD
  DbgText "I_OcxCont_OleInPlaceSiteEx.OnInPlaceActivateEx", "I_OcxCont_OleInPlaceSiteEx"
  .if pfNoRedraw != NULL
    mov xdx, pfNoRedraw
    m2z BOOL ptr [xdx]                                  ;Redraw on activation
    SetOwner xcx, OcxClientSite
    ICall [xcx].$Obj(OcxClientSite).pIOleInPlaceSite::IOleInPlaceSite.OnInPlaceActivate
  .else
    mov eax, E_POINTER
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceSiteEx.OnInPlaceDeactivateEx
; Purpose:    Notifies the container if the object needs to be redrawn upon deactivation.
; Arguments:  Arg1: If TRUE, the container need not redraw the object after completing the
;                   deactivation; if FALSE the object must be redrawn after deactivation.
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceSiteEx.OnInPlaceDeactivateEx,, fNoRedraw:BOOL
  DbgText "I_OcxCont_OleInPlaceSiteEx.OnInPlaceDeactivateEx", "I_OcxCont_OleInPlaceSiteEx"
  SetOwner xcx, OcxClientSite
  ICall [xcx].$Obj(OcxClientSite).pIOleInPlaceSite::IOleInPlaceSite.OnInPlaceDeactivate
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleInPlaceSiteEx.RequestUIActivate
; Purpose:    Notifies the container that the object is about to enter the UI-active state.
; Arguments:  None.
; Return:     eax = HRESULT.

Method I_OcxCont_OleInPlaceSiteEx.RequestUIActivate
  DbgText "I_OcxCont_OleInPlaceSiteEx.RequestUIActivate", "I_OcxCont_OleInPlaceSiteEx"
  xor eax, eax                                          ;S_OK
MethodEnd

endif
