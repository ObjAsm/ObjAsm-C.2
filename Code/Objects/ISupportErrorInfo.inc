; ==================================================================================================
; Title:      ISupportErrorInfo.inc
; Author:     Kai Liebenau.
; Purpose:    ObjAsm support of ISupportErrorInfo interfaces.
; Version:    Version 1.0.0, September 2006
;               - First release.
; ==================================================================================================


externdef IID_ISupportErrorInfo:GUID      ;{DF0B3D60-548F-101B-8E65-08002B2BD119}

SetErrorFromID  proto :DWORD, :POINTER, :POINTER, :DWORD
SetErrorFromStr proto :POINTER, :POINTER, :POINTER

; --------------------------------------------------------------------------------------------------
; Object:  ISupportErrorInfo
; Purpose: Implement the ISupportErrorInfo COM interface.

Object ISupportErrorInfo, ISupportErrorInfoID, IUnknown
  RedefineMethod    Done
  RedefineMethod    Init,                 POINTER
  VirtualMethod     InsertIID,            POINTER               ;-> IID

  InterfaceMethod   InterfaceSupportsErrorInfo,     POINTER

  RedefineVariable  pIID,                 offset IID_ISupportErrorInfo
  DefineVariable    pSupportedIIDs,       POINTER,  NULL
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     ISupportErrorInfo.Done
; Purpose:    Finalize the interface object.
; Arguments:  None.
; Return:     Nothing.

Method ISupportErrorInfo.Done,
  DbgText "ISupportErrorInfo.Done", "ISupportErrorInfo"
  SetObject xcx
  Destroy [xcx].pSupportedIIDs                          ;Destroy DataCollection
  ACall pSelf::ISupportErrorInfo.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ISupportErrorInfo.Init
; Purpose:    Initialize the interface object.
; Arguments:  Arg1: -> Owner object.
; Return:     Nothing.

Method ISupportErrorInfo.Init, uses xbx, pOwner:POINTER
  DbgText "ISupportErrorInfo.Init", "ISupportErrorInfo"
  mov xbx, $New(XWCollection)
  OCall xbx::XWCollection.Init, pOwner, 0, 1, COL_MAX_CAPACITY
  SetObject xcx
  mov [xcx].pSupportedIIDs, xbx
  ACall xcx.Init, pOwner
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ISupportErrorInfo.InterfaceSupportsErrorInfo
; Purpose:    Query if the interface identified with RefIID supports the IErrorInfo interface.
; Arguments:  Arg1: -> RefIID of the queried interface.
; Return:     xax = HRESULT (S_OK, S_FALSE or E_POINTER).

Method ISupportErrorInfo.InterfaceSupportsErrorInfo,, pRefIID:POINTER
  DbgText "ISupportErrorInfo.InterfaceSupportsErrorInfo", "ISupportErrorInfo"
  SetObject xcx
  .if pRefIID != NULL
    OCall [xcx].pSupportedIIDs::Collection.FirstThat, \
                                offset MemComp, pRefIID, sizeof(GUID)  ;pRefIID
    .if xax == NULL
      mov xax, S_FALSE
    .else
      xor xax, xax                                      ;S_OK
    .endif
  .else
    mov xax, E_POINTER
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ISupportErrorInfo.InsertIID
; Purpose:    Insert a GUID in the Collection.
; Arguments:  Arg1: -> GUID.
; Return:     xax -> inserted GUID.

Method ISupportErrorInfo.InsertIID,, pRefIID:POINTER
   DbgText "ISupportErrorInfo.InsertIID", "ISupportErrorInfo"
   SetObject xcx
   OCall [xcx].pSupportedIIDs::Collection.Insert, pRefIID
MethodEnd

; --------------------------------------------------------------------------------------------------
; Procedure:   SetErrorFromID
; Purpose:     Create an error object with the specified error information.
; Arguments:   Arg1: API error code, i.e. 87 => wrong parameter.
;              Arg2: -> Error source UNICODE string.
;              Arg3: -> Error raising IID.
;              Arg4: LCID.
; Return:      Nothing.

SetErrorFromID proc dErrID:DWORD, pSrcStr:POINTER, pIID:POINTER, dLCID:DWORD
  local pErrorStr:POINTER

  .if dErrID != 0
    invoke FormatMessage, FORMAT_MESSAGE_FROM_SYSTEM or FORMAT_MESSAGE_ALLOCATE_BUFFER,
                          NULL, dErrID, dLCID, addr pErrorStr, 0, NULL
    .if pErrorStr != NULL
      invoke SetErrorFromStr, pErrorStr, pSrcStr, pIID
      invoke LocalFree, pErrorStr
    .endif
  .endif
  ret
SetErrorFromID endp

; --------------------------------------------------------------------------------------------------
; Procedure:   SetErrorFromStr
; Purpose:     Create an error object with the specified error information.
; Arguments:   Arg1: -> Error description UNICODE string.
;              Arg2: -> Error source UNICODE string.
;              Arg3: -> Error raising IID.
; Return:      Nothing.

SetErrorFromStr proc pErrorStr:POINTER, pSrcStr:POINTER, pIID:POINTER
  local pErrorInfo:POINTER

  .if pErrorStr != NULL
    invoke CreateErrorInfo, addr pErrorInfo
    .if pErrorInfo != NULL
      ICall pErrorInfo::ICreateErrorInfo.SetDescription, pErrorStr
      .if pSrcStr != NULL
        ICall pErrorInfo::ICreateErrorInfo.SetSource, pSrcStr
      .endif
      .if pIID != NULL
        ICall pErrorInfo::ICreateErrorInfo.SetGUID, pIID
      .endif
      invoke SetErrorInfo, NULL, pErrorInfo
      ICall pErrorInfo::IUnknown.Release
    .endif
  .endif
  ret
SetErrorFromStr endp

endif
