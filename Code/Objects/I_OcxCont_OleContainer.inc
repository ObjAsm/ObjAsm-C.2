; ==================================================================================================
; Title:      I_OcxCont_OleContainer.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of OleContainer Interface for COM OcxContainer objects.
; Notes:      Version C.1.0, June 2009
;               - First release.
; ==================================================================================================


externdef IID_IOleContainer:GUID

; --------------------------------------------------------------------------------------------------
; Object:     I_OcxCont_OleContainer
; Purpose:    Enumerate objects in a compound document or lock a container in the running state.
;             Container and object applications both implement this interface.

Object I_OcxCont_OleContainer,, IUnknown
  InterfaceMethod   ParseDisplayName,   POINTER, BSTR, POINTER, POINTER
  InterfaceMethod   EnumObjects,        DWORD, POINTER
  InterfaceMethod   LockContainer,      BOOL

  RedefineVariable  pIID,   offset IID_IOleContainer
ObjectEnd


if IMPLEMENT

.code
; ==================================================================================================
;     I_OcxCont_OleContainer implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleContainer.ParseDisplayName
; Purpose:    Parse the specified display name and creates a corresponding moniker.
; Arguments:  Arg1: -> bind context to be used in this binding operation. See IBindCtx.
;             Arg2: The display name to be parsed.
;             Arg3: -> variable that receives the number of characters in the display name that
;                   correspond to the ppmkOut moniker.
;             Arg4: -> IMoniker pointer variable that receives the interface pointer to the
;                   resulting moniker. If an error occurs, the implementation sets *ppmkOut to NULL.
;                   If *ppIMoniker is non-NULL, the implementation must call AddRef; it is the
;                   caller's responsibility to call Release.
; Return:     eax = HRESULT.

Method I_OcxCont_OleContainer.ParseDisplayName,, pIBindCtx:POINTER, pDispName:BSTR, \
                                                 pCharEaten:POINTER, ppIMoniker:POINTER
  DbgText "I_OcxCont_OleContainer.ParseDisplayName", "I_OcxCont_OleContainer"
  mov eax, E_NOTIMPL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleContainer.EnumObjects
; Purpose:    Enumerate the objects in the current container.
; Arguments:  Arg1: Specifies which objects in a container are to be enumerated, as defined in the
;                   enumeration OLECONTF.
;             Arg2: -> IEnumUnknown pointer variable that receives the interface pointer to the
;                   enumerator object. Each time a container receives a successful call to
;                   EnumObjects, it must increase the reference count on the ppenum pointer the
;                   method returns. It is the caller's responsibility to call IUnknown::Release
;                   when it is done with the pointer. If an error is returned, the implementation
;                   must set ppenum to NULL.
; Return:     eax = HRESULT.

Method I_OcxCont_OleContainer.EnumObjects,, dFlags:DWORD, ppIEnumUnk:POINTER
  DbgText "I_OcxCont_OleContainer.EnumObjects", "I_OcxCont_OleContainer"
  .if ppIEnumUnk != NULL
    mov xcx, ppIEnumUnk
    m2z POINTER ptr [xcx]
  .endif
  mov eax, E_NOTIMPL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     I_OcxCont_OleContainer.LockContainer
; Purpose:    Keep the container for embedded objects running until explicitly released.
; Arguments:  Arg1: Indicates whether to lock (TRUE) or unlock (FALSE) a container.
; Return:     eax = HRESULT.

Method I_OcxCont_OleContainer.LockContainer,, bLock:BOOL
  DbgText "I_OcxCont_OleContainer.LockContainer", "I_OcxCont_OleContainer"
  DbgHex bLock
  SetOwner xcx, OcxClientSite
  .if bLock == 0
    dec [xcx].$Obj(OcxClientSite).dLockCount
  .else
    inc [xcx].$Obj(OcxClientSite).dLockCount
  .endif
  DbgDec [xcx].$Obj(OcxClientSite).dLockCount
  xor eax, eax                                          ;S_OK
MethodEnd

endif
