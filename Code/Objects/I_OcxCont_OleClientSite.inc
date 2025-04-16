; ==================================================================================================
; Title:      I_OcxCont_OleClientSite.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of OleClientSite Interface for COM OcxContainer objects.
; Notes:      Version C.1.0, October 2017
;              - First release.
; ==================================================================================================


externdef IID_IOleClientSite:GUID

; --------------------------------------------------------------------------------------------------
; Object:     I_OcxCont_ErrorInfo
; Purpose:    Provides the primary means by which an embedded object obtains information about the
;             location and extent of its display site, its moniker, its user interface, and other
;             resources provided by its container. An object server calls IOleClientSite to request
;             services from the container. A container must provide one instance of IOleClientSite
;             for every compound-document object it contains.

Object I_OcxCont_OleClientSite,, IUnknown
  InterfaceMethod   SaveObject
  InterfaceMethod   GetMoniker,                   DWORD, DWORD, POINTER
  InterfaceMethod   GetContainer,                 POINTER
  InterfaceMethod   ShowObject
  InterfaceMethod   OnShowWindow,                 BOOL
  InterfaceMethod   RequestNewObjectLayout

  RedefineVariable  pIID,   offset IID_IOleClientSite
ObjectEnd


if IMPLEMENT

.code
; ==================================================================================================
;     I_OcxCont_OleClientSite implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleClientSite.SaveObject
; Purpose:    Saves the embedded object associated with the client site. This function is
;             synchronous; by the time it returns, the save will be completed.
; Arguments:  None.
; Return:     eax = HRESULT.

Method I_OcxCont_OleClientSite.SaveObject, uses xsi
  DbgText "I_OcxCont_OleClientSite.SaveObject", "I_OcxCont_OleClientSite"
  SetOwner xsi, OcxClientSite
  .if [xsi].pIPersistStorage != NULL && [xsi].pIStorage != NULL
    ICall [xsi].pIPersistStorage::IPersistStorage.Save, [xsi].pIStorage, TRUE
    ICall [xsi].pIPersistStorage::IPersistStorage.SaveCompleted, [xsi].pIStorage
  .endif
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleClientSite.GetMoniker
; Purpose:    Retrieves a moniker for the object's client site.
;             An object can force the assignment of its own or its container's moniker by specifying
;             a value for dwAssign.
; Arguments:  Arg1: Specifies whether to get a moniker only if one already exists, force assignment
;                   of a moniker, create a temporary moniker, or remove a moniker that has been
;                   assigned. In practice, you will usually request that the container force
;                   assignment of the moniker. Possible values are taken from the OLEGETMONIKER
;                   enumeration.
;             Arg2: Specifies whether to return the container's moniker, the object's moniker
;                   relative to the container, or the object's full moniker. In practice, you will
;                   usually request the object's full moniker. Possible values are taken from the
;                   OLEWHICHMK enumeration.
;             Arg3: -> IMoniker pointer variable that receives the interface pointer
;                   to the moniker for the object's client site. If an error occurs, the
;                   implementation must set ppmk to NULL. Each time a container receives a call to
;                   IOleClientSite::GetMoniker, it must increase the reference count on the ppmk
;                   pointer it returns. It is the caller's responsibility to call Release when it
;                   is finished with the pointer.
; Return:     eax = HRESULT.

Method I_OcxCont_OleClientSite.GetMoniker,, dAssign:DWORD, dWhichMoniker:DWORD, ppMoniker:POINTER
  DbgText "I_OcxCont_OleClientSite.GetMoniker", "I_OcxCont_OleClientSite"
  .if ppMoniker != NULL
    mov xdx, ppMoniker
    m2z POINTER ptr [xdx]
  .endif
  mov eax, E_NOTIMPL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleClientSite.GetContainer
; Purpose:    Retrieves a pointer to the object's container.
; Arguments:  Arg1: Address of IOleContainer pointer variable that receives the interface pointer to
;                   the container object. If an error occurs, the implementation must set ppContainer
;                   to NULL.
; Return:     eax = HRESULT.

Method I_OcxCont_OleClientSite.GetContainer,, ppContainer:POINTER
  DbgText "I_OcxCont_OleClientSite.GetContainer", "I_OcxCont_OleClientSite"
  .if ppContainer != NULL
    SetOwner xcx, OcxClientSite
    mov xdx, ppContainer
    .if [xcx].pIOleContainer != NULL
      mrm POINTER ptr [xdx], [xcx].pIOleContainer, xax
      ICall xax::IOleContainer.AddRef
      xor eax, eax                                      ;S_OK
    .else
      m2z POINTER ptr [xdx]
      mov eax, E_NOINTERFACE
    .endif
  .else
    mov eax, E_POINTER
  .endif
MethodEnd

 ; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleClientSite.ShowObject
; Purpose:    Asks a container to display its object to the user. This method ensures that the
;             container itself is visible and not minimized.
; Arguments:  None.
; Return:     eax = HRESULT.

Method I_OcxCont_OleClientSite.ShowObject
  DbgText "I_OcxCont_OleClientSite.ShowObject", "I_OcxCont_OleClientSite"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleClientSite.OnShowWindow
; Purpose:    Notifies a container when an embedded object's window is about to become visible or
;             invisible. This method does not apply to an object that is activated in place and
;             therefore has no window separate from that of its container.
; Arguments:  Arg1: Indicates whether an object's window is open (TRUE) or closed (FALSE).
; Return:     eax = HRESULT.

Method I_OcxCont_OleClientSite.OnShowWindow,, dShow:BOOL
  DbgText "I_OcxCont_OleClientSite.OnShowWindow", "I_OcxCont_OleClientSite"
  SetOwner xcx, OcxClientSite
  mov [xcx].dShow, edx                                  ;dShow
  DbgHex edx
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleClientSite.RequestNewObjectLayout
; Purpose:    Asks a container to resize the display site for embedded objects.
; Arguments:  None.
; Return:     eax = HRESULT.

Method I_OcxCont_OleClientSite.RequestNewObjectLayout
  DbgText "I_OcxCont_OleClientSite.RequestNewObjectLayout", "I_OcxCont_OleClientSite"
  mov eax, E_NOTIMPL
MethodEnd

endif
