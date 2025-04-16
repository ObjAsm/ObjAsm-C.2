; ==================================================================================================
; Title:      I_OcxCont_ServiceProvider.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of IServiceProvider Interface for COM OcxContainer objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


externdef IID_IServiceProvider:GUID

; --------------------------------------------------------------------------------------------------
; Object:     I_OcxCont_ServiceProvider
; Purpose:    Defines a mechanism for retrieving a service object; that is, an object that provides
;             custom support to other objects.

Object I_OcxCont_ServiceProvider,, IUnknown
  VirtualMethod     QueryService,         REFGUID, REFIID, POINTER

  RedefineVariable  pIID,   offset IID_IServiceProvider
ObjectEnd


if IMPLEMENT

.code
; ==================================================================================================
;     I_OcxCont_ServiceProvider implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_ServiceProvider.QueryService
; Purpose:    The IServiceProvider interface is a generic access mechanism to locate a GUID-
;             identified service that is provided through a control or any other object that the
;             service can communicate with. For example, an embedded object (such as an OLE control)
;             typically communicates only with its associated client site object in the container
;             through the IOleClientSite interface that is supplied by using
;             IOleObject.SetClientSite. The embedded object must ask the client site for some other
;             service that the container supports when that service might not be implemented in the
;             client site. The client site must provide a means by which the control that is managed
;             by the site can access the service when necessary. For example, the
;             IOleInPlaceSite.GetWindowContext function can be used by an in-place object or control
;             to access interface pointers for the document object that contains the site and the
;             frame object that contains the document. Because these interface pointers exist on
;             separate objects, the control cannot call the site's QueryInterface to obtain those
;             pointers. Instead, use the IServiceProvider interface.
;             The IServiceProvider interface has only one member, QueryService, through which a
;             caller specifies the service ID (SID, a GUID), the IID of the interface to return,
;             and the address of the caller's interface pointer variable.
; Arguments:  Arg1: -> Service GUID.
;             Arg2: -> requested Interface IID.
;             Arg3: -> recieving variable.
; Return:     eax = HRESULT.

Method I_OcxCont_ServiceProvider.QueryService,, pService:REFGUID, pInterface:REFIID, ppvObject:POINTER
    DbgText "I_OcxCont_ServiceProvider.QueryService", "I_OcxCont_ServiceProvider"
    DbgGUID pService
    DbgGUID pInterface
    mov eax, E_NOTIMPL
MethodEnd

endif
