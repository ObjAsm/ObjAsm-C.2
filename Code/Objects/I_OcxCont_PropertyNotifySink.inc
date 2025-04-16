; ==================================================================================================
; Title:      I_OcxCont_PropertyNotifySink.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of PropertyNotifySink Interface for COM OcxContainer objects.
; Notes:      Version C.1.0, October 2017.
;               - First release.
; ==================================================================================================


externdef IID_IPropertyNotifySink:GUID  ;9BFBBC02-EFF1-101A-84ED-00AA00341D07

; --------------------------------------------------------------------------------------------------
; Object:     I_OcxCont_PropertyNotifySink
; Purpose:    Objects that support properties, for example, through OLE Automation and the IDispatch
;             interface, may want to allow clients to be notified when certain properties change
;             value. Such a property is called a bindable property because the notifications allow a
;             client to synchronize its own display of the object's current property values. In
;             addition, the same objects may wish to allow a client to control when certain
;             properties are allowed to change. Such properties are called request edit properties.

Object I_OcxCont_PropertyNotifySink,, IUnknown
  InterfaceMethod   OnChanged,          WORD
  InterfaceMethod   OnRequestEdit,      WORD

  RedefineVariable  pIID,   offset IID_IPropertyNotifySink
ObjectEnd


if IMPLEMENT

.code
; ==================================================================================================
;     I_OcxCont_PropertyNotifySink implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_PropertyNotifySink.OnChanged
; Purpose:    Notifies a sink that a bindable property has changed.
; Arguments:  Arg1: The dispatch identifier of the property that changed, or DISPID_UNKNOWN (-1) if
;                   multiple properties have changed. The client (owner of the sink) should retrieve
;                   the current value of each property of interest from the object that generated
;                   the notification.
; Return:     eax = HRESULT.

Method I_OcxCont_PropertyNotifySink.OnChanged,, wDispID:WORD
  DbgText "I_OcxCont_PropertyNotifySink.OnChanged", "I_OcxCont_PropertyNotifySink"
  DbgDec wDispID,, "I_OcxCont_PropertyNotifySink"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_PropertyNotifySink.OnRequestEdit
; Purpose:    Notifies a sink that a requestedit property is about to change.
; Arguments:  Arg1: The dispatch identifier of the property that is about to change or
;                   DISPID_UNKNOWN (-1) if multiple properties are about to change.
; Return:     eax = HRESULT.

Method I_OcxCont_PropertyNotifySink.OnRequestEdit,, wDispID:WORD
  DbgText "I_OcxCont_PropertyNotifySink.OnRequestEdit", "I_OcxCont_PropertyNotifySink"
  DbgDec wDispID,, "I_OcxCont_PropertyNotifySink"
  xor eax, eax                                          ;S_OK
MethodEnd

endif
