; ==================================================================================================
; Title:      IConnectionPointContainer.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of COM Interface IConnectionPointContainer.
;             Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


externdef IID_IConnectionPointContainer:GUID
externdef IID_IEnumConnectionPoints:GUID

; --------------------------------------------------------------------------------------------------
; Object:  IConnectionPointContainer
; Purpose: Implement the IConnectionPointContainer interface.

Object IConnectionPointContainer, IConnectionPointContainerID, IUnknown
  RedefineMethod    Done
  RedefineMethod    Init,                   POINTER
  VirtualMethod     Insert,                 POINTER

  ;Don't change the order of the interface methods!
  InterfaceMethod   EnumConnectionPoints,   POINTER
  InterfaceMethod   FindConnectionPoint,    POINTER, POINTER

  RedefineVariable  pIID,                   offset IID_IConnectionPointContainer

  Embed             ConnectionPoints,       Collection
ObjectEnd

; --------------------------------------------------------------------------------------------------
; Object:  IEnumConnectionPoints
; Purpose: Implement the IEnumConnectionPoints interface.

Object IEnumConnectionPoints, IEnumConnectionPointsID, IUnknown
  ;Don't change the order of the interface methods!
  InterfaceMethod   Next,                   DWORD, POINTER, POINTER
  InterfaceMethod   Skip,                   DWORD
  InterfaceMethod   Reset
  InterfaceMethod   Clone,                  POINTER

  RedefineVariable  pIID,                   offset IID_IEnumConnectionPoints
ObjectEnd

; --------------------------------------------------------------------------------------------------
; Object:  EnumConnectionPoints
; Purpose: Implement the EnumConnectionPoints COM object.

Object EnumConnectionPoints, EnumConnectionPointsID, Component
  RedefineMethod    Init,                   POINTER

  DefineVariable    pConnectionPoints,      POINTER,    NULL      ;-> Collection
  DefineVariable    dCurrentIndex,          DWORD,      0
ObjectEnd



; ==================================================================================================

if IMPLEMENT

; ==================================================================================================
;    IConnectionPointContainer implementation
; ==================================================================================================

externdef IID_IConnectionPoint:GUID

; --------------------------------------------------------------------------------------------------
; Method:     IConnectionPointContainer.Done
; Purpose:    Finalize the IConnectionPointContainer interface object.
; Arguments:  None.
; Return:     Nothing.

Method IConnectionPointContainer.Done
  DbgText "IConnectionPointContainer.Done", "IConnectionPointContainer"
  SetObject xcx
  OCall [xcx].ConnectionPoints::Collection.Done
  ACall Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    IConnectionPointContainer.Init
; Purpose:   Initialize the IConnectionPointContainer interface object.
; Arguments: Arg1: -> Owner object.
; Return:    Nothing.

Method IConnectionPointContainer.Init, uses xsi, pOwner:POINTER
  DbgText "IConnectionPointContainer.Init", "IConnectionPointContainer"
  SetObject xsi
  ACall xsi.Init, pOwner
  OCall [xsi].ConnectionPoints::Collection.Init, xsi, 1, 1, COL_MAX_CAPACITY
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IConnectionPointContainer.Insert
; Purpose:    Insert a new ConnectionPoint into the ConnectionPoints collection.
; Arguments:  Arg1: -> new ConnectionPoint.
; Return:     Nothing.

Method IConnectionPointContainer.Insert,, pConnectionPoint:POINTER
  DbgText "IConnectionPointContainer.Insert", "IConnectionPointContainer"
  SetObject xcx
  OCall [xcx].ConnectionPoints::Collection.Insert, pConnectionPoint
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IConnectionPointContainer.EnumConnectionPoints
; Purpose:    Create an enumerator object to iterate through all the connection points supported in
;             the connectable object, one connection point per outgoing IID.
; Arguments:  Arg1: -> Variable that receives the interface pointer to the newly created enumerator.
; Return:     eax = HRESULT.

Method IConnectionPointContainer.EnumConnectionPoints,, ppIEnum:POINTER
  local pEnuConPnts:POINTER

  DbgText "IConnectionPointContainer.EnumConnectionPoints", "IConnectionPointContainer"
  .if ppIEnum == NULL
    mov eax, E_POINTER
  .else
    mov pEnuConPnts, $New(EnumConnectionPoints)
    OCall xax::EnumConnectionPoints.Init, pSelf
    OCall pEnuConPnts::EnumConnectionPoints.GetInterface, offset IID_IEnumConnectionPoints, ppIEnum
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IConnectionPointContainer.FindConnectionPoint
; Purpose:    Return a pointer to the IConnectionPoint interface of a connection point for a
;             specified IID, if that IID describes a supported outgoing interface.
; Arguments:  Arg1: Interface identifier of the outgoing interface whose connection point object
;                   is being requested.
;             Arg2: Address of IConnectionPoint pointer variable that receives the interface pointer
;                   to the connection point that supports the riid interface.
; Return:     eax = HRESULT.

ConnectionPoint_CheckIID proc pCP:$ObjPtr(ConnectionPoint), pReqIID:REFGUID, xUnused:XWORD
  ?mov xcx, pCP
  ?mov xdx, pReqIID
  mov xcx, [xcx].$Obj(ConnectionPoint).pSinkIID

  mov eax, [xcx]
  sub eax, [xdx]
  jnz @F
  mov eax, [xcx + 4]
  sub eax, [xdx + 4]
  jnz @F
  mov eax, [xcx + 8]
  sub eax, [xdx + 8]
  jnz @F
  mov eax, [xcx + 12]
  sub eax, [xdx + 12]
@@:
  ret
ConnectionPoint_CheckIID endp


Method IConnectionPointContainer.FindConnectionPoint,, pReqIID:POINTER, ppConPnt:POINTER
  DbgText "IConnectionPointContainer.FindConnectionPoint", "IConnectionPointContainer"
  .if ppConPnt == NULL
    mov eax, E_POINTER                                  ;Error!
  .else
    .if pReqIID == NULL
      mov xdx, ppConPnt
      m2z POINTER ptr [xdx]
      mov eax, E_POINTER                                ;Error!
    .else
      DbgGUID pReqIID
      mov xcx, pSelf
      OCall [xcx].$Obj(IConnectionPointContainer).ConnectionPoints::Collection.FirstThatNot, \
                                            offset ConnectionPoint_CheckIID, pReqIID, NULL
      .if eax == NULL                                   ;Not found!
        DbgText "ConnectionPoint not supported", "IConnectionPointContainer"
        mov xdx, ppConPnt
        m2z POINTER ptr [xdx]                           ;Return ConPntPtr = NULL
        mov eax, CONNECT_E_NOCONNECTION
      .else
        DbgText "ConnectionPoint found", "IConnectionPointContainer"
        OCall xax::ConnectionPoint.GetInterface, offset IID_IConnectionPoint, ppConPnt
      .endif
    .endif
  .endif
MethodEnd



; ==================================================================================================
;    IEnumConnectionPoints implementation
; ==================================================================================================

externdef IID_IConnectionPoint:GUID

; --------------------------------------------------------------------------------------------------
; Method:     IEnumConnectionPoints.Next
; Purpose:    Enumerate the next requested IConnectionPoint pointers, returning them along with the
;             actual number of enumerated elements in pFetched. The enumerator calls
;             IConnectionPoint.AddRef for each returned pointer, and the caller is responsible for
;             calling IConnectionPoint.Release through each pointer when they are no longer needed.
; Arguments:  Arg1: Number of IConnectionPoint values being requested.
;             Arg2: -> Buffer to hold the IConnectionPoint values.
;             Arg3: -> Number of elements actually supplied. Caller can pass in NULL if Arg1 is one.
; Return:     eax = HRESULT.

Method IEnumConnectionPoints.Next, uses xbx xdi xsi, dReqCount:DWORD, pBuffer:POINTER, pFetched:POINTER
  local dCount:DWORD

  DbgText "IEnumConnectionPoints.Next", "IEnumConnectionPoints"
  SetObject xsi
  .if pBuffer == NULL
    mov eax, E_POINTER                                  ;Error!
  .else
    mov xdi, [xsi].pOwner                               ;xdi -> EnumConnectionPoints
    mov ebx, [xdi].$Obj(EnumConnectionPoints).dCurrentIndex
    m2m dCount, dReqCount, eax                          ;Save requested count
    add dReqCount, ebx
    .while ebx < dReqCount
      mov xax, [xdi].$Obj(EnumConnectionPoints).pConnectionPoints
      .break .if ebx >= [xax].$Obj(Collection).dCount   ;break if no more ConnectionPoints
      OCall xax::Collection.ItemAt, ebx
      OCall xax::ConnectionPoint.GetInterface, addr IID_IConnectionPoint, pBuffer
      add pBuffer, sizeof POINTER
      inc ebx
    .endw
    mov eax, [xdi].$Obj(EnumConnectionPoints).dCurrentIndex
    mov [xdi].$Obj(EnumConnectionPoints).dCurrentIndex, ebx
    mov ecx, dCount                                     ;Restore requested count in ecx

    .if pFetched == NULL
      .if ecx > 1
        mov eax, E_POINTER
      .else
        xor eax, eax                                    ;Return S_OK (0)
      .endif
    .else
      mov xdx, pFetched
      sub ebx, eax
      mov DWORD ptr [xdx], ebx
      xor eax, eax                                      ;Return S_OK (0)
      cmp ebx, ecx
      setne al                                          ;Return S_FALSE (1) if different
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IEnumConnectionPoints.Skip
; Purpose:    Increment the internal counter.
; Arguments:  Arg1: Increment value.
; Return:     eax = HRESULT.

Method IEnumConnectionPoints.Skip,, dIncrement:DWORD
  DbgText "IEnumConnectionPoints.Skip", "IEnumConnectionPoints"
  mov xax, pSelf
  mov xcx, [xax].$Obj(IEnumConnectionPoints).pOwner     ;xcx -> EnumConnectionPoints
  mov edx, dIncrement
  add [xcx].$Obj(EnumConnectionPoints).dCurrentIndex, edx ;Increment
  xor eax, eax                                          ;Return S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IEnumConnectionPoints.Reset
; Purpose:    Reset the internal counter.
; Arguments:  None.
; Return:     eax = HRESULT.

Method IEnumConnectionPoints.Reset
  DbgText "IEnumConnectionPoints.Reset", "IEnumConnectionPoints"
  mov xax, pSelf
  mov xcx, [xax].$Obj(IEnumConnectionPoints).pOwner     ;xcx -> EnumConnectionPoints
  xor edx, edx
  mov [xcx].$Obj(EnumConnectionPoints).dCurrentIndex, edx ;Reset
  xor eax, eax                                          ;Return S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IEnumConnectionPoints.Clone
; Purpose:    Make an exact duplicate of EnumConnectionPoints with all it's internal values.
; Arguments:  Arg1: -> IEnumConnectionPoints interface of the new object.
; Return:     eax = HRESULT.

Method IEnumConnectionPoints.Clone, uses xsi, pEnumInt:POINTER
  local pEnuConPnts:POINTER

  DbgText "IEnumConnectionPoints.Clone", "IEnumConnectionPoints"
  SetObject xsi
  mov pEnuConPnts, $New(EnumConnectionPoints)           ;xax -> new EnumConnectionPoints
  OCall xax::EnumConnectionPoints.Init, [xsi].pOwner
  mov xcx, [xsi].pOwner                                 ;xcx -> original EnumConnectionPoints
  mov xax, pEnuConPnts
  m2m [xax].$Obj(EnumConnectionPoints).dCurrentIndex, \
      [xcx].$Obj(EnumConnectionPoints).dCurrentIndex, edx
  OCall xax::EnumConnectionPoints.GetInterface, offset IID_IEnumConnectionPoints, pEnumInt
MethodEnd



; ==================================================================================================
;    EnumConnectionPoints implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     EnumConnectionPoints.Init
; Purpose:    Initialize the EnumConnectionPoints object.
; Arguments:  Arg1: -> Owner object.
; Return:     Nothing.

Method EnumConnectionPoints.Init, uses xsi, pOwner:POINTER
  DbgText "EnumConnectionPoints.Init", "EnumConnectionPoints"
  SetObject xsi
  ACall xsi.Init, pOwner, NULL                          ;No aggregation
  mov xcx, pOwner                                       ;ecx -> IConnectionPointContainer
  lea xdx, [xcx].$Obj(IConnectionPointContainer).ConnectionPoints
  mov [xsi].pConnectionPoints, xdx

  New IEnumConnectionPoints                             ;Create IEnumConnectionPoints interface
  OCall [xsi].Interfaces::Collection.Insert, xax        ;Add it to the supported interfaces
  OCall xax::IEnumConnectionPoints.Init, xsi
MethodEnd

endif
