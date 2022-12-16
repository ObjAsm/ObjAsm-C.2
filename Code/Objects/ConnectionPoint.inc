; ==================================================================================================
; Title:      IConnectionPoint.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of COM Interface IConnectionPoint and related code.
;             Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


externdef IID_IConnectionPoint:GUID
externdef IID_IEnumConnections:GUID

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:  IConnectionPoint
; Purpose: Implementation of the IConnectionPoint COM interface used by the ConnectionPoint object.  

Object IConnectionPoint, IConnectionPointID, IUnknown
  ;Don't change the order of the interface methods!
  InterfaceMethod   GetConnectionInterface,       REFIID
  InterfaceMethod   GetConnectionPointContainer,  POINTER
  InterfaceMethod   Advise,                       POINTER, POINTER
  InterfaceMethod   Unadvise,                     DWORD
  InterfaceMethod   EnumConnections,              POINTER

  RedefineVariable  pIID,                         offset IID_IConnectionPoint
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:  ConnectionPoint
; Purpose: Implementation of the ConnectionPoint COM object.
;          This object is used to connect COM objects.

Object ConnectionPoint, ConnectionPointID, Component
  RedefineMethod    Done
  RedefineMethod    Init,                     POINTER, REFIID
  VirtualMethod     FireEvent,                DWORD
  DynamicAbstract   FireNow,                  DWORD

  DefineVariable    pSinkIID,                 REFIID,    NULL         ;-> Sink IID

  Embed             ConnectedInterfaces,      DataCollection
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:  IEnumConnections
; Purpose: Implementation of the IEnumConnections COM interface used by the EnumConnections object.  

Object IEnumConnections, IEnumConnectionsID, IUnknown
  InterfaceMethod   Next,                     DWORD, POINTER, POINTER
  InterfaceMethod   Skip,                     DWORD
  InterfaceMethod   Reset
  InterfaceMethod   Clone,                    POINTER

  RedefineVariable  pIID,                     offset IID_IEnumConnections
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:  EnumConnections
; Purpose: Implementation of the EnumConnections COM object.
;          This object is used to enumerate connections between COM objects.

Object EnumConnections, EnumConnectionsID, Component
  RedefineMethod    Init,                     POINTER

  DefineVariable    pConnections,             $ObjPtr(DataCollection),   NULL
  DefineVariable    dCurrentIndex,            DWORD,      0
ObjectEnd



; ==================================================================================================

if IMPLEMENT

; ==================================================================================================
;    IConnectionPoint implementation
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IConnectionPoint.GetConnectionInterface
; Purpose:    Return the IID of the outgoing interface managed by this connection point.
; Arguments:  Arg1: -> Variable that will hold the pIID.
; Return:     eax = HRESULT.

Method IConnectionPoint.GetConnectionInterface,, pIID:REFIID
  DbgText "IConnectionPoint.GetConnectionInterface", "IConnectionPoint"
  mov xdx, pIID
  .if xdx == NULL
    mov eax, E_POINTER                                  ;Error!
  .else
    mov xax, pSelf
    mov xdx, [xax].$Obj(IConnectionPoint).pOwner        ;xcx -> ConnectionPoint
    invoke MemClone, pIID, [xdx].$Obj(ConnectionPoint).pSinkIID, sizeof GUID
    xor eax, eax                                        ;Return S_OK
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IConnectionPoint.GetConnectionPointContainer
; Purpose:    Return the ConnectionPointContainer that owns this ConnectionPoint.
; Arguments:  Arg1: -> Return value.
; Return:     eax = HRESULT.

Method IConnectionPoint.GetConnectionPointContainer,, ppCPContainer:POINTER
  DbgText "IConnectionPoint.GetConnectionPointContainer", "IConnectionPoint"
  mov xdx, ppCPContainer
  .if xdx == NULL
    mov eax, E_POINTER                                ;Error!
  .else
    mov xax, pSelf
    mov xcx, [xax].$Obj(IConnectionPoint).pOwner      ;xcx -> ConnectionPoint
    mov xax, [xcx].$Obj(ConnectionPoint).pOwner       ;xax -> Collection
    m2m [xdx], [xax].$Obj(Collection).pOwner, xcx     ;[xdx] -> IConnectionPointContainer
    xor eax, eax                                      ;Return S_OK
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IConnectionPoint.Advise
; Purpose:    Establish a connection between the connection point object and the client's sink.
; Arguments:  Arg1: -> Unknown Interface.
;             Arg2: -> Token (DWORD) that uniquely identifies this connection.
; Return:     eax = HRESULT.

Method IConnectionPoint.Advise, uses xbx xsi, pIUnknown:POINTER, pCookie:POINTER
  local pSinkInterface:POINTER

  DbgText "IConnectionPoint.Advise", "IConnectionPoint"
  .if (pIUnknown == NULL) || (pCookie == NULL)
    mov eax, E_POINTER                                  ;Error!
  .else
    mov xax, pSelf
    SetObject xsi, ConnectionPoint, [xax].$Obj(IConnectionPoint).pOwner
    ICall pIUnknown::IUnknown.QueryInterface, [xsi].pSinkIID, addr pSinkInterface
    .if SUCCEEDED(eax)
      mov eax, [xsi].ConnectedInterfaces.dMaxCapacity
      dec eax
      .if [xsi].ConnectedInterfaces.dCount != eax
        mov xbx, $MemAlloc(sizeof(CONNECTDATA))         ;Get memory for Info-Structure
        mov xdx, pCookie
        mov POINTER ptr [xdx], xbx                      ;Return Cookie value = alloc ptr
        mov [xbx].CONNECTDATA.dwCookie, ebx
        m2m [xbx].CONNECTDATA.pUnk, pSinkInterface, xdx
        OCall [xsi].ConnectedInterfaces::DataCollection.Insert, xbx  ;Add this connection
        xor eax, eax                                    ;Return S_OK
      .else
        mov xdx, pCookie
        m2z POINTER ptr [xdx]
        mov eax, CONNECT_E_ADVISELIMIT                  ;No more connections are possible!
      .endif
    .else
      mov xdx, pCookie
      m2z POINTER ptr [xdx]
      mov eax, CONNECT_E_CANNOTCONNECT                  ;Sink GUID not supported!
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IConnectionPoint.Unadvise
; Purpose:    Disconnect the previous connection established by IConnectionPoint.Advise.
; Arguments:  Arg1: Connection token (DWORD) previously returned from IConnectionPoint.Advise.
; Return:     eax = HRESULT.

Method IConnectionPoint.Unadvise,, dPrvCookie:Dword
  DbgText "IConnectionPoint.Unadvise", "IConnectionPoint"
  mov xax, POINTER ptr dPrvCookie
  ICall [xax].CONNECTDATA.pUnk::IUnknown.Release
  mov xax, pSelf
  mov xcx, [xax].$Obj(IConnectionPoint).pOwner          ;xcx -> ConnectionPoint
  OCall [xcx].$Obj(ConnectionPoint).ConnectedInterfaces::DataCollection.Dispose, POINTER ptr dPrvCookie
  xor eax, eax                                          ;Return S_OK
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IConnectionPoint.EnumConnections
; Purpose:    Create an enumerator object to iterate through the current connections for this
;             connection point.
; Arguments:  Arg1: -> Variable that will hold the Interface pointer of the enumeration object.
; Return:     eax = HRESULT.

Method IConnectionPoint.EnumConnections,, ppIEnum:POINTER
  local pEnuCon:POINTER

  DbgText "IConnectionPoint.EnumConnections", "IConnectionPoint"
  .if ppIEnum == NULL
    mov eax, E_POINTER
  .else
    New EnumConnections
    mov pEnuCon, xax
    mov xdx, pSelf
    OCall pEnuCon::EnumConnections.Init, [xdx].$Obj(IConnectionPoint).pOwner
    OCall pEnuCon::EnumConnections.GetInterface, offset IID_IEnumConnections, ppIEnum
    xor eax, eax                                        ;Return S_OK
  .endif
MethodEnd



; ==================================================================================================
;    ConnectionPoint implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ConnectionPoint.Done
; Purpose:    Finalize the ConnectionPoint object.
; Arguments:  None.
; Return:     Nothing.

Method ConnectionPoint.Done
  DbgText "ConnectionPoint.Done", "ConnectionPoint"
  SetObject xcx
  if DEBUGGING
    .if [xcx].ConnectedInterfaces.dCount != 0
      DbgWarning "There exist unreleased connections associated with this ConnectionPoint"
      DbgWarning "This will cause instabilities in the client using them."
    .endif
  endif
  OCall [xcx].ConnectedInterfaces::DataCollection.Done
  ACall Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ConnectionPoint.Init
; Purpose:    Initialize the ConnectionPoint object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> Sink IID.
; Return:     Nothing.

Method ConnectionPoint.Init, uses xsi, pOwner:POINTER, pSinkIID:REFIID
  DbgText "ConnectionPoint.Init", "ConnectionPoint"
  SetObject xsi
  ACall xsi.Init, pOwner, NULL                          ;No aggregation

  inc [xsi].IUnkNoDelegate.dRefCount                    ;Increment RefCount to prevent premature
                                                        ;  destruction of this component!
  OCall [xsi].ConnectedInterfaces::DataCollection.Init, xsi, 1, 1, COL_MAX_CAPACITY
  m2m [xsi].pSinkIID, pSinkIID, xdx

  New IConnectionPoint                                  ;Create IConnectionPoint interface
  OCall [xsi].Interfaces::Collection.Insert, xax        ;Add it to the supported interfaces
  OCall xax::IConnectionPoint.Init, xsi
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ConnectionPoint.FireEvent
; Purpose:    Fire an Event for each active connection in this ConnectionPoint. It calls FireNow,
;             which has th be redefined to allow proper behaviour for each Sink Interface.
; Arguments:  Arg1: Parameter.
; Return:     Nothing.

Method ConnectionPoint.FireEvent, uses xsi, dParameter:DWORD
  DbgText "ConnectionPoint.FireEvent", "ConnectionPoint"
  SetObject xsi
  OCall [xsi].ConnectedInterfaces::DataCollection.ForEach, $MethodAddr(xsi.FireNow), \
                                                           XWORD ptr dParameter, NULL
MethodEnd


; ==================================================================================================
;    IEnumConnections implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IEnumConnections.Next
; Purpose:    Enumerate the next requested IConnectionPoint pointers, returning them along with the
;             actual number of enumerated elements in pFetched. The enumerator calls
;             IConnectionPoint.AddRef for each returned pointer, and the caller is responsible for
;             calling IConnectionPoint.Release through each pointer when they are no longer needed.
; Arguments:  Arg1: Number of IConnectionPoint values being requested.
;             Arg2: -> Buffer to hold the IConnectionPoint values.
;             Arg3: -> Number of elements actually supplied. Caller can pass in NULL if Arg1 is one.
; Return:     eax = HRESULT.

Method IEnumConnections.Next, uses xbx xdi xsi, dReqCount:DWORD, pBuffer:POINTER, pFetched:POINTER
  local dIndex:DWORD

  DbgText "IEnumConnections.Next", "IEnumConnections"
  SetObject xsi
  mov xdi, pBuffer
  .if pBuffer == NULL
    mov eax, E_POINTER                                  ;Error!
  .else
    mov xdi, pBuffer
    mov xcx, [xsi].pOwner                               ;xcx -> EnumConnections
    m2m dIndex, [xcx].$Obj(EnumConnections).dCurrentIndex, edx
    xor ebx, ebx                                        ;Reset counter
    .while ebx < dReqCount
      mov xdx, [xsi].pOwner                             ;xcx -> EnumConnections
      mov xax, [xdx].$Obj(EnumConnections).pConnections
      mov edx, dIndex
      .break .if ecx >= [xax].$Obj(Collection).dCount   ;break if no more Connections
      OCall xax::Collection.ItemAt, edx
      inc dIndex
      inc ebx
      lea xcx, [xdi]
      invoke MemClone, xdi, xax, sizeof CONNECTDATA
      add xdi, sizeof CONNECTDATA
    .endw
    mov xcx, [xsi].pOwner                               ;xcx -> EnumConnections
    add [xcx].$Obj(EnumConnections).dCurrentIndex, ebx

    .if pFetched == NULL
      .if dReqCount > 1
        mov eax, E_POINTER                              ;Error!
        ExitMethod
      .endif
    .else
      mov xdx, pFetched
      mov DWORD ptr [xdx], ebx
    .endif
    xor eax, eax                                        ;Return S_OK (0)
    cmp ebx, dReqCount
    setne al                                            ;Return S_FALSE (1) if different
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IEnumConnections.Skip
; Purpose:    Increment the internal counter.
; Arguments:  Arg1: Increment value.
; Return:     eax = HRESULT.

Method IEnumConnections.Skip,, dIncrement:DWORD
  DbgText "IEnumConnections.Skip", "IEnumConnections"
  mov xax, pSelf
  mov xcx, [xax].$Obj(IEnumConnections).pOwner          ;xcx -> EnumConnections
  mov edx, dIncrement
  add [xcx].$Obj(EnumConnections).dCurrentIndex, edx    ;Increment
  xor eax, eax                                          ;Return S_OK
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IEnumConnections.Reset
; Purpose:    Reset the internal counter.
; Arguments:  None.
; Return:     eax = HRESULT.

Method IEnumConnections.Reset
  DbgText "IEnumConnections.Reset", "IEnumConnections"
  mov xax, pSelf
  mov xcx, [xax].$Obj(IEnumConnections).pOwner          ;xcx -> EnumConnections
  xor edx, edx
  mov [xcx].$Obj(EnumConnections).dCurrentIndex, edx    ;Reset
  xor eax, eax                                          ;Return S_OK
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IEnumConnections.Clone
; Purpose:    Make an exact duplicate of EnumConnections with all it's internal values.
; Arguments:  Arg1: -> IEnumConnections interface of the new object.
; Return:     eax = HRESULT.

Method IEnumConnections.Clone, uses xsi, pEnumInt:POINTER
  local pEnuCon:$ObjPtr(EnumConnections)

  DbgText "IEnumConnections.Clone", "IEnumConnections"
  SetObject xsi
  mov pEnuCon, $New(EnumConnections)
  OCall xax::EnumConnections.Init, [xsi].pOwner
  mov xcx, [xsi].pOwner                                 ;xcx -> original EnumConnections
  mov xax, pEnuCon
  m2m [xax].$Obj(EnumConnections).dCurrentIndex, \
      [xcx].$Obj(EnumConnections).dCurrentIndex, edx
  OCall xax::EnumConnections.GetInterface, offset IID_IEnumConnections, pEnumInt
MethodEnd



; ==================================================================================================
;    EnumConnections implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     EnumConnections.Init
; Purpose:    Initialize the EnumConnections object.
; Arguments:  Arg1: -> Owner ConnectionPoint object.
; Return:     Nothing.

Method EnumConnections.Init, uses xsi, pOwner:POINTER
  DbgText "EnumConnections.Init", "EnumConnections"
  SetObject xsi
  ACall xsi.Init, pOwner, NULL                          ;No aggregation
  mov xcx, pOwner                                       ;xcx -> ConnectionPoint
  lea xdx, [xcx].$Obj(ConnectionPoint).ConnectedInterfaces
  mov [xsi].pConnections, xdx

  New IEnumConnections                                  ;Create IEnumConnections interface
  OCall [xsi].Interfaces::Collection.Insert, xax  ;Add it to the supported interfaces
  OCall xax::IEnumConnections.Init, xsi
MethodEnd

endif
