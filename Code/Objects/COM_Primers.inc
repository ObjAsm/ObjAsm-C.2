; ==================================================================================================
; Title:      COM_Primers.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of COM Primer objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


externdef dDllRefCount:DWORD
if MAKETEMPL eq TRUE                                    ;If we are building the object
  .data                                                 ; template, then add the
  dDllRefCount  DWORD     0                             ; dDllRefCount global variable
endif

externdef IID_IUnknown:GUID

; --------------------------------------------------------------------------------------------------
; Object:     IUnknown
; Purpose:    Implementation of the IUnknown COM interface used by a Component or derived object.

Object IUnknown, IUnknownID, Primer
  ;Don't change the order of the interface methods!
  InterfaceMethod   QueryInterface,   REFIID, POINTER   ;Must be the 1st method
  InterfaceMethod   AddRef                              ;Must be the 2nd method
  InterfaceMethod   Release                             ;Must be the 3rd method

  DefineVariable    pIID,             REFIID,       offset IID_IUnknown ;-> Interface class GUID
  DefineVariable    dRefCount,        DWORD,        0   ;Reference counter
ObjectEnd

; --------------------------------------------------------------------------------------------------
; Object:     IUnknownNoDelegate
; Purpose:    Implementation of the IUnknownNoDelegate COM interface used by a Component or derived
;             object.

Object IUnknownNoDelegate, IUnknownNoDelegateID, IUnknown
  RedefineMethod    QueryInterface,   REFIID, POINTER
  RedefineMethod    AddRef
  RedefineMethod    Release
ObjectEnd

; --------------------------------------------------------------------------------------------------
; Object:     Component
; Purpose:    Implementation of the Component COM object.
;             This object is the core of all COM objects. It holds all interfaces in a Collection
;             and implements a way to reuse other COM objects called aggregation, shown in the
;             following diagram:
;
;                                                                --・;                                                               |   |
;                                                                --・;                                                                 |
;              Outer Component                                    |
;              ---------------------------------------------------|------------------------------
;             |                                                   |                              |
;             |                                      ----------------・      ・・・・・・・・・  |
;             |                                     |                 |     |                 |  |
;             |                                     |      Outer      |        Outer IUnknown    |
;             |                                     |     IUnknown    |---->|  Non Delegating |  |
;             |                                     |                 |                          |
;             |                                     |        I.RefCnt |     |     C.+A.RefCnt |  |
;             |                                     '----------------・      ・・・・・・・・・  |
;             |                                                                  /|\   /|\       |
;             |                                                                   |     |        |
;             |                    --・                aggr. redirection          |     |        |
;             |                   |   |        ----------------------------------・     |        |
;             |                    --・       |                                         |        |
;             |                     |         |                                         |        |
;             |    Inner Component  |         |                                         |        |
;             |    -----------------|---------|--------------------------・             |        |
;             |   |                 |         |                           |             |        |
;             |   |    ----------------・     |      ・・・・・・・・・   |             |        |
;             |   |   |                 |     |     |                 |   |             |        |
;             |   |   |                 |     |           IUnknown        |             |        |
;             |   |   |     IUnknown    |----・・・>|  Non Delegating |   |             |        |
;             |   |   |                 |                                 |             |        |
;             |   |   |        I.RefCnt |           |        C.RefCnt |   |             |        |
;             |   |   '----------------・            ・・・・・・・・・   |             |        |
;             |   |                                         /|\           |             |        |
;             |   |                                                       |             |        |
;             |   |  Aggregated Interface                    |            |             |        |
;             |   |  --  --  --  --  --  --  --  --  --  --  --  --  --   |             |        |
;             |   | |                                        |         |  |             |        |
;             |   | |   ----------------                               |  |             |        |
;             |   |    |                |                    |            |             |        |
;     --・    |   | |  |    IUnknown    |                          aggr. redirection    |        |
;    |   |-------------|   Descendant   |----------------------------------------------・        |
;     --・    |   | |  |                |                              |  |                      |
;             |   |    |       I.RefCnt |                                 |                      |
;             |   | |  '----------------'                              |  |                      |
;             |   | |                                                  |  |                      |
;             |   |  --  --  --  --  --  --  --  --  --  --  --  --  --   |                      |
;             |   '------------------------------------------------------・                      |
;             |                                                                                  |
;             '----------------------------------------------------------------------------------'
;
; Note: The IUnknown interface passed when an aggregated component is created should be the
;       non delegating IUnknown interface of the outer component.

Object Component, ComponentID, Primer
  VirtualMethod     AggregateInterface, POINTER, REFIID         ;-> IUnkND, -> IID
  RedefineMethod    Done
  VirtualMethod     GetInterface,       REFIID, POINTER         ;-> IID, -> Return
  RedefineMethod    Init,               POINTER, POINTER        ;-> Owner, -> Outer IUnk. (Aggr.)

  DefineVariable    pCLSID,             REFGUID,      offset IID_NULL  ;-> Component class GUID
  DefineVariable    pIUnkOuter,         $ObjPtr(IUnknown), NULL ;-> Outer component IUnknown

  Embed             Interfaces,         Collection
  Embed             AggrInterfaces,     DataCollection
  Embed             IUnkNoDelegate,     IUnknownNoDelegate
ObjectEnd


; ==================================================================================================
;   COM helpers
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Procedure:  PrintRefCounters
; Purpose:    Output the a GUID on the debug device.
; Arguments:  ARG1: -> Interface.
; Return:     Nothing.

if DEBUGGING

if TARGET_BITNESS eq 64
  option stackbase:rbp
endif

PrintRefCounters proc pInterface:POINTER, dColor:DWORD, pDestWnd:PSTRINGW
  local COM_GUID_STR[37]:CHRA

  ANNOTATION prv:xbx xsi

  DbgSaveContext
  invoke EnterCriticalSection, offset DbgCritSect
  DbgOutHex <Interface -\] >, dColor, xbx, dColor, pDestWnd
  invoke DbgOutTextA, $OfsCStrA(",   IID = "), dColor, DbgColorBackground, DBG_EFFECT_NORMAL, pDestWnd
  mov xsi, pInterface
  invoke DbgOutInterfaceName, [xsi].$Obj(IUnknown).pIID, dColor, DbgColorBackground, pDestWnd
  mov ebx, [xsi].$Obj(IUnknown).dRefCount
  DbgOutHex <, Reference Count = >, dColor, ebx, dColor, pDestWnd
  invoke DbgOutTextA, offset bCRLF, dColor, DbgColorBackground, DBG_EFFECT_NORMAL, pDestWnd

  mov xsi, pInterface
  mov xbx, [xsi].$Obj(IUnknown).pOwner
  DbgOutHex <Component -\] >, dColor, xbx, dColor, pDestWnd
  invoke DbgOutTextA, $OfsCStrA(", CLSID = "), dColor, DbgColorBackground, DBG_EFFECT_NORMAL, pDestWnd
  mov xsi, pInterface
  mov xdx, [xsi].$Obj(IUnknown).pOwner
  .if [xdx].$Obj(Component).pCLSID == NULL
    invoke DbgOutTextA, $OfsCStrA("????????-????-????-????-????????????"), \
                        dColor, DbgColorBackground, DBG_EFFECT_NORMAL, pDestWnd
  .else
    lea xbx, COM_GUID_STR
    invoke GUID2StrA, xbx, [xdx].$Obj(Component).pCLSID
    invoke DbgOutTextA, xbx, dColor, DbgColorBackground, DBG_EFFECT_NORMAL, pDestWnd
  .endif
  mov xsi, pInterface
  mov xcx, [xsi].$Obj(IUnknown).pOwner
  lea xdx, [xcx].$Obj(Component).IUnkNoDelegate
  mov ebx, [xdx].$Obj(IUnknown).dRefCount
  DbgOutHex <, Reference Count = >, dColor, ebx, dColor, pDestWnd
  invoke DbgOutTextA, offset bCRLF, dColor, DbgColorBackground, DBG_EFFECT_NORMAL, pDestWnd
  invoke LeaveCriticalSection, offset DbgCritSect
  DbgLoadContext
  ret
PrintRefCounters endp

PrintQueryInfoBeg proc pInterface:POINTER, pReqIID:POINTER, dColor:DWORD, pDestWnd:PSTRINGW
  ANNOTATION prv:xbx xsi

  DbgSaveContext
  invoke EnterCriticalSection, offset DbgCritSect
  mov xsi, pInterface
  Invoke DbgOutInterface, pReqIID, dColor, DbgColorBackground, pDestWnd
  invoke DbgOutTextA, offset bCRLF, dColor, DbgColorBackground, DBG_EFFECT_NORMAL, pDestWnd

  mov xbx, pInterface
  DbgOutHex <Interface -\] >, dColor, xbx, dColor, pDestWnd
  invoke DbgOutTextA, $OfsCStrA(",   IID = "), dColor, DbgColorBackground, DBG_EFFECT_NORMAL, pDestWnd
  mov xsi, pInterface
  invoke DbgOutInterfaceName, [xsi].$Obj(IUnknown).pIID, dColor, DbgColorBackground, pDestWnd
  invoke DbgOutTextA, offset bCRLF, dColor, DbgColorBackground, DBG_EFFECT_NORMAL, pDestWnd

  mov xbx, [xsi].$Obj(IUnknown).pOwner
  DbgOutHex <Component -\] >, dColor, xbx, dColor, pDestWnd
  invoke DbgOutTextA, $OfsCStrA(", CLSID = "), dColor, DbgColorBackground, DBG_EFFECT_NORMAL, pDestWnd
  mov xsi, pInterface
  mov xdx, [xsi].$Obj(IUnknown).pOwner
  .if [xdx].$Obj(Component).pCLSID == NULL
    invoke DbgOutTextA, $OfsCStrA("????????-????-????-????-????????????"), \
                        dColor, DbgColorBackground, DBG_EFFECT_NORMAL, pDestWnd
  .else
    invoke DbgOutComponentName, [xdx].$Obj(Component).pCLSID, dColor, DbgColorBackground, pDestWnd
  .endif
  invoke DbgOutTextA, offset bCRLF, dColor, DbgColorBackground, DBG_EFFECT_NORMAL, pDestWnd

  invoke LeaveCriticalSection, offset DbgCritSect
  DbgLoadContext
  ret
PrintQueryInfoBeg endp

PrintQueryInfoEnd proc hResult:DWORD, dColor:DWORD, pDestWnd:PSTRINGW
  DbgSaveContext
  invoke EnterCriticalSection, offset DbgCritSect
  .if hResult == S_OK
    invoke DbgOutTextA, $OfsCStrA("IUnknown.QueryInterface succeeded"), dColor, DbgColorBackground, \
                        DBG_EFFECT_BOLD or DBG_EFFECT_NEWLINE, pDestWnd
  .else
    invoke DbgOutComErr, hResult, DbgColorForeground, DbgColorBackground, pDestWnd
    invoke DbgOutTextA, offset bCRLF, dColor, DbgColorBackground, DBG_EFFECT_NORMAL, pDestWnd
  .endif
  invoke LeaveCriticalSection, offset DbgCritSect
  DbgLoadContext
  ret
PrintQueryInfoEnd endp

if TARGET_BITNESS eq 64
  option stackbase:??StackBase
endif

endif

; ==================================================================================================

if IMPLEMENT

; ==================================================================================================
;    IUnknown Implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     IUnknown.QueryInterface
; Purpose:    Check if the requested interface is supported. If it is, a pointer to a pointer
;             to the interface is returned and the reference count is incremented
; Arguments:  Arg1: -> Requested interface ID.
;             Arg2: -> Variable that will hold the interface pointer.
; Return:     eax = HRESULT.

Method IUnknown.QueryInterface,, pReqIID:REFIID, ppInterface:POINTER
  DbgText "IUnkown.QueryInterface", "IUnkown"
  if DEBUGGING
    invoke PrintQueryInfoBeg, pSelf, pReqIID, $RGB(0,192,0), $OfsCStrW("IUnkown")
  endif
  SetOwner xcx, Component
  .if [xcx].pIUnkOuter == NULL
    lea xax, [xcx].IUnkNoDelegate
  .else
    mov xax, [xcx].pIUnkOuter
  .endif
  ICall xax::IUnknown.QueryInterface, pReqIID, ppInterface

  if DEBUGGING
    invoke PrintQueryInfoEnd, eax, $RGB(0,192,0), $OfsCStrW("IUnkown")
  endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IUnknown.AddRef
; Purpose:    Increment the internal interface reference count.
; Arguments:  None.
; Return:     eax = Current reference count.

Method IUnknown.AddRef, uses xsi
  DbgText "IUnknown.AddRef", "IUnkown"
  SetObject xsi
  mov xdx, [xsi].pOwner                                 ;Component
  .if [xdx].$Obj(Component).pIUnkOuter == NULL
    lea xax, [xdx].$Obj(Component).IUnkNoDelegate
  .else
    mov xax, [xdx].$Obj(Component).pIUnkOuter
  .endif
  ICall xax::IUnknown.AddRef
  lock inc [xsi].dRefCount                              ;Increment interface reference count
  mov eax, [xsi].dRefCount                              ;Return interface reference count (debug)
  if DEBUGGING
    invoke PrintRefCounters, xsi, $RGB(0,128,255), $OfsCStrW("IUnkown")
  endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IUnknown.Release
; Purpose:    Decrement the internal interface reference count.
; Arguments:  None.
; Return:     eax = (optional) Current reference count.

Method IUnknown.Release, uses xsi
  DbgText "IUnknown.Release", "IUnkown"
  SetObject xsi
  mov xdx, [xsi].pOwner                                 ;Component
  .if [xdx].$Obj(Component).pIUnkOuter == NULL
    OCall [xdx].$Obj(Component).IUnkNoDelegate::IUnknownNoDelegate.Release
    .if eax == 0
      if DEBUGGING
        lock dec [xsi].dRefCount                        ;Decrement interface reference count
        invoke PrintRefCounters, xsi, $RGB(255,128,0), $OfsCStrW("IUnkown")
      endif
      DbgHex [xsi].pOwner, "Destroying component and all associated interfaces"
      Destroy [xsi].pOwner                              ;Destroy the component (owner of interface)
      xor eax, eax                                      ;Return zero
    .else
      lock dec [xsi].dRefCount                          ;Decrement interface reference count
      if DEBUGGING
        invoke PrintRefCounters, xsi, $RGB(255,128,0), $OfsCStrW("IUnkown")
      endif
      mov eax, [xsi].dRefCount                          ;Return interface reference count (debug)
    .endif
  .else
    ICall [xdx].$Obj(Component).pIUnkOuter::IUnknown.Release
    .if eax == 0
      xor eax, eax                                      ;Return zero
    .else
      lock dec [xsi].dRefCount                          ;Decrement interface reference count
      mov eax, [xsi].dRefCount                          ;Return interface reference count (debug)
    .endif
  .endif
MethodEnd


; ==================================================================================================
;    IUnknownNoDelegate Implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     IUnknownNoDelegate.QueryInterface
; Purpose:    Check if the requested interface is supported. If it is, a pointer to a pointer
;             to the interface is returned and the reference count is incremented
; Arguments:  Arg1: -> Requested interface GUID.
;             Arg2: -> Variable that will hold the interface pointer.
; Return:     eax = HRESULT.

Method IUnknownNoDelegate.QueryInterface,, pReqIID:REFIID, ppInterface:POINTER
;  DbgText "IUnknownNoDelegate.QueryInterface", "IUnknownNoDelegate"
;  DbgGUID pReqIID,, "IUnknownNoDelegate"
  SetOwner xax, Component
  OCall xax::Component.GetInterface, pReqIID, ppInterface
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IUnknownNoDelegate.AddRef
; Purpose:    Increment the internal component reference count.
; Arguments:  None.
; Return:     eax = Current component reference count.

Method IUnknownNoDelegate.AddRef
;  DbgText "IUnknownNoDelegate.AddRef", "IUnknownNoDelegate"
  SetObject xcx
  lock inc [xcx].dRefCount                              ;Increment component reference count
  mov eax, [xcx].dRefCount                              ;Return component reference count (debug)
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IUnknownNoDelegate.Release
; Purpose:    Decrement the internal component reference count.
; Arguments:  None.
; Return:     eax = Current component reference count.

Method IUnknownNoDelegate.Release
;  DbgText "IUnknownNoDelegate.Release", "IUnknownNoDelegate"
  SetObject xcx
  .if [xcx].dRefCount == 0                              ;Component reference count
    OCall xcx.ErrorReport, NULL, COM_INTERFACE_REF_ERROR
    xor eax, eax                                        ;Return component reference count = 0
  .else
    lock dec [xcx].dRefCount
    mov eax, [xcx].dRefCount
  .endif
MethodEnd


; ==================================================================================================
;    Component Implementation
; ==================================================================================================

AggregatedInterfaceData struc
  pIUnkND POINTER   NULL    ;Non delegating IUnkown of the component that owns the aggr. interface
  pIID    POINTER   NULL    ;Interface ID of the aggregated interface
AggregatedInterfaceData ends
PAggregatedInterfaceData typedef ptr AggregatedInterfaceData

; --------------------------------------------------------------------------------------------------
; Method:     Component.AggregateInterface
; Purpose:    Aggregate an interface of an inner component.
; Arguments:  Arg1: -> Non delegating IUnknown interface.
;             Arg2: -> IID of the aggregated interface.
; Return:     Nothing.

Method Component.AggregateInterface,, pIUnkND:POINTER, pIID:REFIID
;  DbgText "Component.AggregateInterface", "Component"
;  DbgGUID pIID,, "Component"
  MemAlloc sizeof(AggregatedInterfaceData)
  m2m [xax].AggregatedInterfaceData.pIUnkND, pIUnkND, xdx
  m2m [xax].AggregatedInterfaceData.pIID, pIID, xdx
  SetObject xcx
  OCall [xcx].AggrInterfaces::Collection.Insert, xax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Component.Done
; Purpose:    Finalize the COM object.
; Arguments:  None.
; Return:     Nothing.

Method Component.Done, uses xsi
;  DbgText "Component.Done", "Component"
  SetObject xsi
;  DbgHex xsi,, "Component"
  OCall [xsi].Interfaces::Collection.Done               ;Destroys all interfaces of this component
  OCall [xsi].AggrInterfaces::DataCollection.Done
  OCall [xsi].IUnkNoDelegate::IUnknownNoDelegate.Done   ;This interface is not contained in the
  .if dDllRefCount == 0                                 ;  previous collections!
    OCall xsi.ErrorReport, NULL, COM_DLL_REFCNT_ERROR
  .else
    lock dec dDllRefCount                               ;Decrement the DLL reference count
  .endif
  ACall Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Procedure:  (Iterator) IUnknown_CheckIID
; Purpose:    Check interface IID against a test IID.
; Arguments:  Arg1: -> Interface whose IID is used to to compare against.
;             Arg2: -> Test IID.
; Return:     eax = Zero if equal, otherwise non zero.

if TARGET_BITNESS eq 32

  OPTION PROLOGUE:NONE
  OPTION EPILOGUE:NONE

  IUnknown_CheckIID proc pInterface:$ObjPtr(IUnknown), pReqIID:REFGUID, xUnused:XWORD
    mov eax, [esp + 4]
    mov edx, [esp + 8]
    mov ecx, [eax].$Obj(IUnknown).pIID

    mov eax, [ecx]
    sub eax, [edx]
    jnz @F
    mov eax, [ecx + sizeof(DWORD)]
    sub eax, [edx + sizeof(DWORD)]
    jnz @F
    mov eax, [ecx + 2*sizeof(DWORD)]
    sub eax, [edx + 2*sizeof(DWORD)]
    jnz @F
    mov eax, [ecx + 3*sizeof(DWORD)]
    sub eax, [edx + 3*sizeof(DWORD)]
  @@:
    ret 12
  IUnknown_CheckIID endp

  OPTION PROLOGUE:PrologueDef
  OPTION EPILOGUE:EpilogueDef

else

  IUnknown_CheckIID proc pInterface:$ObjPtr(IUnknown), pReqIID:REFGUID, xUnused:XWORD
    mov rcx, [rcx].$Obj(IUnknown).pIID

    mov rax, [rcx]
    sub rax, [rdx]
    jnz @F
    mov rax, [rcx + sizeof(QWORD)]
    sub rax, [rdx + sizeof(QWORD)]
    jnz @F
  @@:
    ret
  IUnknown_CheckIID endp

endif

; --------------------------------------------------------------------------------------------------
; Procedure: (Iterator) IUnknown_CheckAggrIID
; Purpose:   Check aggredated interface IID againt a test IID.
; Arguments: Arg1: -> AggregatedInterfaceData structure.
;            Arg2: -> Requested interface GUID.
;            Arg3: Unused XWORD.
; Return:    eax = TRUE/FALSE.

if TARGET_BITNESS eq 32

  OPTION PROLOGUE:NONE
 OPTION EPILOGUE:NONE

  IUnknown_CheckAggrIID proc pAggregatedInterfaceData:POINTER, pTestIID:REFGUID, xUnused:XWORD
    mov eax, [esp + 4]
    mov edx, [esp + 8]
    mov ecx, [eax].AggregatedInterfaceData.pIID

    mov eax, [ecx]
    sub eax, [edx]
    jnz @F
    mov eax, [ecx + sizeof(DWORD)]
    sub eax, [edx + sizeof(DWORD)]
    jnz @F
    mov eax, [ecx + 2*sizeof(DWORD)]
    sub eax, [edx + 2*sizeof(DWORD)]
    jnz @F
    mov eax, [ecx + 3*sizeof(DWORD)]
    sub eax, [edx + 3*sizeof(DWORD)]
  @@:
    ret 12
  IUnknown_CheckAggrIID endp

  OPTION PROLOGUE:PrologueDef
 OPTION EPILOGUE:EpilogueDef

else

  IUnknown_CheckAggrIID proc pAggregatedInterfaceData:POINTER, pTestIID:REFIID, xUnused:XWORD
    mov rcx, [rcx].AggregatedInterfaceData.pIID

    mov rax, [rcx]
    sub rax, [rdx]
    jnz @F
    mov rax, [rcx + sizeof(QWORD)]
    sub rax, [rdx + sizeof(QWORD)]
    jnz @F
  @@:
    ret
  IUnknown_CheckAggrIID endp

endif

; --------------------------------------------------------------------------------------------------
; Method:     Component.GetInterface
; Purpose:    Return a COM interface POINTER and increments dRefCount.
; Arguments:  Arg1: -> Requested interface ID.
;             Arg2: -> Variable that will hold the interface pointer.
; Return:     eax = HRESULT.

Method Component.GetInterface, uses xsi, pReqIID:REFIID, ppInterface:POINTER
  local pInterface:POINTER

  DbgText "Component.GetInterface", "Component"
  SetObject xsi
  ;Search for native interfaces
  OCall [xsi].Interfaces::Collection.FirstThatNot, \
                                     offset IUnknown_CheckIID, pReqIID, NULL
  .if xax == NULL
    ;Search for aggregated interfaces
    OCall [xsi].AggrInterfaces::DataCollection.FirstThatNot, \
                                     offset IUnknown_CheckAggrIID, pReqIID, NULL
    .if xax != NULL
      mov pInterface, xax
      mov xdx, [xax].AggregatedInterfaceData.pIUnkND
      ICall xdx::IUnknown.QueryInterface, [xdx].AggregatedInterfaceData.pIID, addr pInterface
      mov xax, pInterface
    .endif
  .endif
  mov xcx, ppInterface
  mov POINTER ptr [xcx], xax                            ;Store the result
  .if xax == NULL
    DbgWarning "Interface NOT supported!", "Component"
    mov eax, E_NOINTERFACE                              ; [:-(    Return error
  .else
    ICall xax::IUnknown.AddRef
    xor eax, eax                                        ;  :-)    Return S_OK
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Component.Init
; Purpose:    Initialize the COM object.
; Arguments:  Arg1: -> Owner (Component object).
;             Arg2: -> Outer Unknown interface.
; Return:     Nothing.

Method Component.Init, uses xsi, pOwner:POINTER, pIUnkOuter:POINTER
  DbgText "Component.Init", "Component"
  SetObject xsi
;  DbgHex xsi,, "Component"
  ACall xsi.Init, pOwner
  lock inc dDllRefCount                                 ;Increment the DLL reference count
  m2m [xsi].pIUnkOuter, pIUnkOuter, xdx                 ;Only useful if the component is
                                                        ;  located in a DLL.
  OCall [xsi].IUnkNoDelegate::IUnknownNoDelegate.Init, xsi
  OCall [xsi].AggrInterfaces::DataCollection.Init, xsi, 0, 1, COL_MAX_CAPACITY
  OCall [xsi].Interfaces::Collection.Init, xsi, 2, 1, COL_MAX_CAPACITY ;Min 2 interfaces

  New IUnknown
  OCall [xsi].Interfaces::Collection.Insert, xax        ;IUnknown added here
  OCall xax::IUnknown.Init, xsi
MethodEnd

endif
