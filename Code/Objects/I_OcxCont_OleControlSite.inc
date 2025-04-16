; ==================================================================================================
; Title:   	  I_OcxCont_OleControlSite.inc
; Author:  	  G. Friedrich
; Version: 	  C.1.0
; Purpose: 	  ObjAsm support of OleControlSite Interface for COM OcxContainer objects.
; Notes:   	  Version C.1.0, October 2017
;          	    - First release.
; ==================================================================================================


externdef IID_IOleControlSite:GUID

; --------------------------------------------------------------------------------------------------
; Object:     I_OcxCont_AdviseSink
; Purpose:    Provides the methods that enable a site object to manage each embedded control within
;             a container. A site object provides IOleControlSite as well as other site interfaces
;             such as IOleClientSite and IOleInPlaceSite. When a control requires the services
;             expressed through this interface, it will query one of the other client site
;             interfaces for IOleControlSite.

Object I_OcxCont_OleControlSite,, IUnknown
  InterfaceMethod   OnControlInfoChanged
  InterfaceMethod   LockInPlaceActive,          BOOL
  InterfaceMethod   GetExtendedControl,         POINTER
  InterfaceMethod   TransformCoords,            POINTER, POINTER, DWORD
  InterfaceMethod   TranslateAccel,             POINTER, DWORD
  InterfaceMethod   OnFocus,                    BOOL
  InterfaceMethod   ShowPropertyFrame

  RedefineVariable  pIID,   offset IID_IOleControlSite
ObjectEnd



if IMPLEMENT

.code
; ==================================================================================================
;     I_OcxCont_OleControlSite implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleControlSite.OnControlInfoChanged
; Purpose:    Informs the container that the control's CONTROLINFO structure has changed and that the
;             container should call the control's IOleControl::GetControlInfo for an update.
; Arguments:  None.
; Return:     eax = HRESULT.

Method I_OcxCont_OleControlSite.OnControlInfoChanged
  DbgText "I_OcxCont_OleControlSite.OnControlInfoChanged", "I_OcxCont_OleControlSite"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleControlSite.LockInPlaceActive
; Purpose:    Indicates whether a control should remain in-place active. Calls to this method
;             typically nest an event to ensure that the object's activation state remains stable
;             throughout the processing of the event.
; Arguments:  Arg1: Indicates whether to ensure the in-place active state (TRUE) or to allow
;                   activation to change (FALSE). When TRUE, a supporting container must not
;                   deactivate the in-place object until this method is called again with FALSE.
; Return:     eax = HRESULT.

Method I_OcxCont_OleControlSite.LockInPlaceActive,, bLock:BOOL
  DbgText "I_OcxCont_OleControlSite.LockInPlaceActive", "I_OcxCont_OleControlSite"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleControlSite.GetExtendedControl
; Purpose:    Retrieves an IDispatch pointer to the extended control that the container uses to
;             wrap the real control.
; Arguments:  Arg1: -> IDispatch pointer variable that receives the interface pointer to the extended
;                      control. If an error occurs, the implementation must set *ppDisp to NULL.
;                      On success, the caller is responsible for calling Release when pIDispatch is
;                      no longer needed.

; Return:     eax = HRESULT.

Method I_OcxCont_OleControlSite.GetExtendedControl,, ppIDispatch:POINTER
  DbgText "I_OcxCont_OleControlSite.GetExtendedControl", "I_OcxCont_OleControlSite"
  mov eax, E_NOTIMPL      ;The container does not implement extended controls.
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleControlSite.TransformCoords
; Purpose:    Converts coordinates expressed in HIMETRIC units (as is standard in OLE) to the units
;             specified by the container.
; Arguments:  Arg1: -> POINTL structure containing coordinates expressed in HIMETRIC units. This is
;                   an [in] parameter when dwFlags contains XFORMCOORDS_HIMETRICTOCONTAINER;
;                   it is an [out] parameter with XFORMCOORDS_CONTAINERTOHIMETRIC. In the latter
;                   case, the contents are undefined on error.
;             Arg2: -> caller-allocated POINTF structure that receives the converted coordinates.
;                   This is an [in] parameter when dwFlags contains XFORMCOORDS_CONTAINERTOHIMETRIC;
;                   it is an [out] parameter with XFORMCOORDS_HIMETRICTOCONTAINER. In the latter
;                   case, the contents are undefined on error.
;             Arg3: Flags indicating the exact conversion to perform. This parameter can be any
;                   combination of the following values, except as indicated.
;
;        Value                            Meaning
;        XFORMCOORDS_POSITION             The coordinates to convert represent a position point.
;        01h                              Cannot be used with XFORMCOORDS_SIZE.
;        XFORMCOORDS_SIZE                 The coordinates to convert represent a set of dimensions.
;        02h                              Cannot be used with XFORMCOORDS_POSITION.
;        XFORMCOORDS_HIMETRICTOCONTAINER  The operation converts pptlHimetric into pptfContainer.
;        04h                              Cannot be used with XFORMCOORDS_CONTAINERTOHIMETRIC.
;        XFORMCOORDS_CONTAINERTOHIMETRIC  The operation converts pptfContainer into pptlHimetric.
;        08h                              Cannot be used with XFORMCOORDS_HIMETRICTOCONTAINER.
;        XFORMCOORDS_EVENTCOMPAT          TBD
;        10h
;
; Return:    eax = HRESULT.

Method I_OcxCont_OleControlSite.TransformCoords,, pPtlHimetric:POINTER, pPtfContainer:POINTER, \
                                                      dFlags:DWORD
  DbgText "I_OcxCont_OleControlSite.TransformCoords", "I_OcxCont_OleControlSite"
  mov eax, E_NOTIMPL    ;The container does not require any special coordinate conversions.
                        ;The container deals completely in HIMETRIC.
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleControlSite.TranslateAccel
; Purpose:    Passes a keystroke to the control site for processing.
; Arguments:  Arg1: -> MSG structure describing the keystroke to be processed.
;             Arg2: Flags describing the state of the Control, Alt, and Shift keys. The value of the
;                   flag can be any valid KEYMODIFIERS enumeration values.
; Return:     eax = HRESULT.

Method I_OcxCont_OleControlSite.TranslateAccel,, pMsg:POINTER, dModifieres:DWORD
  DbgText "I_OcxCont_OleControlSite.TranslateAccel", "I_OcxCont_OleControlSite"
  mov eax, E_NOTIMPL    ;The container does not implement accelerator support.
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleControlSite.OnFocus
; Purpose:    Indicates whether the control managed by this client site has gained or lost the
;             focus.
; Arguments:  Arg1: Indicates whether the control gained (TRUE) or lost the focus (FALSE).
; Return:     eax = HRESULT.

Method I_OcxCont_OleControlSite.OnFocus,, dGotFocus:BOOL
  DbgText "I_OcxCont_OleControlSite.OnFocus", "I_OcxCont_OleControlSite"
  DbgHex dGotFocus,, "I_OcxCont_OleControlSite"
  xor eax, eax                                        ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleControlSite.ShowPropertyFrame
; Purpose:    Instructs a container to display a property sheet for the ctrl embedded in this site.
; Arguments:  None.
; Return:     eax = HRESULT.

Method I_OcxCont_OleControlSite.ShowPropertyFrame
  DbgText "I_OcxCont_OleControlSite.ShowPropertyFrame", "I_OcxCont_OleControlSite"
  mov eax, E_NOTIMPL    ;The container does not need to show property pages itself.
MethodEnd

endif
