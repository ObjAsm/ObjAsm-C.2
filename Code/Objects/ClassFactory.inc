; ==================================================================================================
; Title:      ClassFactory.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of ClassFactory COM object.
; Notes:      Version C.1.0, November 2017
;               - First release.
; ==================================================================================================


externdef IID_IUnknown:GUID
externdef IID_IClassFactory:GUID
externdef dClassFactoryLocks:DWORD

; --------------------------------------------------------------------------------------------------
; Object:  IClassFactory
; Purpose: Implementation of the IClassFactory COM interface used by the ClassFactory object.

Object IClassFactory, IClassFactoryID, IUnknown
  InterfaceMethod   CreateInstance,   POINTER, REFIID, POINTER
  InterfaceMethod   LockServer,       DWORD

  RedefineVariable  pIID,             offset IID_IClassFactory
ObjectEnd

; --------------------------------------------------------------------------------------------------
; Object:  ClassFactory
; Purpose: Implementation of the ClassFactory COM object.
;          This object is used to create new instances of COM objects using its class ID (CLSID)
;          on the IClassFactory main interface.

Object ClassFactory, ClassFactoryID, Component
  RedefineMethod    Done
  RedefineMethod    Init,             POINTER, POINTER  ;-> Owner, -> Supported CLSID

  DefineVariable    pTemplate,        POINTER,    NULL  ;-> Object dynamic data template
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ==================================================================================================
;    IClassFactory Implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     IClassFactory.CreateInstance
; Purpose:    Create a new object instance.
; Arguments:  Arg1: -> Outer IUnknown.
;             Arg2: -> Requested interface GUID.
;             Arg3: -> Variable that will hold the interface pointer.
; Return:     eax = HRESULT.

Method IClassFactory.CreateInstance, uses xbx xdi xsi, pIUnkOuter:POINTER, pReqIID:REFIID, ppInterface:POINTER
  DbgText "IClassFactory.CreateInstance"
  .if pIUnkOuter != NULL                                ;A component can only be aggregated
    GuidComp offset IID_IUnknown, pReqIID               ;  if pIUnkOuter != NULL and
    .if eax != 0                                        ;  the requested IID is IID_IUnknown.
      mov eax, E_INVALIDARG                             ;  Note: the returned Interface pointer is the
      ExitMethod                                        ;    non delegating IUnknown interface pointer!
    .endif                                              ;    It must be stored by the outer component
  .endif                                                ;    to control the component live cycle.

  SetOwner xcx, ClassFactory                            ;xcx -> ClassFactory

  ;Create the component object
  mov xsi, [xcx].pTemplate                              ;xsi -> object dynamic template
  mov ebx, [xsi - sizeof(XWORD)]                        ;ebx = object dynamic template size
  mov xdi, $MemAlloc(ebx)                               ;rdi -> new object instance
  invoke MemClone, xdi, xsi, ebx                        ;Initialize object members

  ;Initialize it
  OCall xdi::Component.Init, NULL, pIUnkOuter           ;Call Init constructor, pOwner = NULL.
                                                        ;  Calling InProcServer polymorphicaly
  ;Return the correct interface pointer
  .if pIUnkOuter == NULL
    OCall xdi::Component.GetInterface, pReqIID, ppInterface ;Return requested interface pointer
    .if FAILED(eax)
      DbgWarning "ClassFactory failed to obtain the requested interface"
      DbgGUID pReqIID
      mov esi, eax
      Destroy xdi                                       ;Destroy the just created component
      mov eax, esi                                      ;Return error condition
    .endif
  .else
    mov xcx, ppInterface
    lea xdx, [xbx].$Obj(Component).IUnkNoDelegate
    mov POINTER ptr [xcx], xdx                          ;Save the non delegating IUnknown
    OCall xdx::IUnknownNoDelegate.AddRef
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IClassFactory.LockServer
; Purpose:    Used to hold the ClassFactory object from being destroyed.
; Arguments:  Arg1: TRUE to lock / FALSE to unlock.
; Return:     eax = HRESULT.

Method IClassFactory.LockServer,, dLockServer:DWORD
  DbgText "IClassFactory.LockServer"
  SetOwner xcx, ClassFactory
  .if dLockServer == FALSE
    .if dClassFactoryLocks == 0
      OCall xcx::ClassFactory.ErrorReport, NULL, COM_SERVER_LOCK_ERROR
    .else
      dec dClassFactoryLocks
    .endif
  .else
    inc dClassFactoryLocks
  .endif
  xor eax, eax                                          ;Return S_OK
MethodEnd


; ==================================================================================================
;    ClassFactory Implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     ClassFactory.Done
; Purpose:    Finalize the ClassFactory object.
; Arguments:  None.
; Return:     Nothing.

Method ClassFactory.Done
  DbgText "ClassFactory.Done"
  inc dDllRefCount                                      ;Increment the DLL reference count
  SetObject xcx
  ACall xcx.Done                                        ;Here, the DLL reference count is
MethodEnd                                               ;  decremented again

; --------------------------------------------------------------------------------------------------
; Method:     ClassFactory.Init
; Purpose:    Initialize the COM object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> Dynamic template of the supported object.
; Return:     Nothing.
; Note:       ClassFactories doesn't change the dDllRefCount!
;             To avoid freeing the DLL from memory use the Lock method.

Method ClassFactory.Init, uses xsi, pOwner:POINTER, pTemplate:POINTER
  DbgText "ClassFactory.Init"
  SetObject xsi
  dec dDllRefCount                                      ;Decrement the DLL reference count again
  m2m [xsi].pTemplate, pTemplate, xax                   ;Store template pointer
  ACall xsi.Init, pOwner, NULL                          ;Invoke Ancestor Init method
  New IClassFactory
  OCall [xsi].Interfaces::Collection.Insert, xax
  OCall xax::IClassFactory.Init, xsi
MethodEnd

endif
