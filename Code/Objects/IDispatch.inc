; ==================================================================================================
; Title:      IDispatch.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of COM Interface object IDispatch.
;             This interface exposes objects, methods, and properties to automation programming
;             tools and other applications.
; Notes:      Version C.1.0, October 2017
;              - First release.
; ==================================================================================================


externdef IID_IDispatch:GUID

; --------------------------------------------------------------------------------------------------
; Object:     IDispatch
; Purpose:    Implement the IDispatch COM interface.

Object IDispatch, IDispatchID, IUnknown
  RedefineMethod    Init,                 POINTER, POINTER, POINTER

  ;Don't change the order of the interface methods!
  InterfaceMethod   GetTypeInfoCount,     POINTER
  InterfaceMethod   GetTypeInfo,          DWORD, DWORD, POINTER
  InterfaceMethod   GetIDsOfNames,        POINTER, POINTER, DWORD, DWORD, POINTER
  InterfaceMethod   Invoke,               DWORD, REFIID, DWORD, WORD, ptr DISPPARAMS, LPVARIANT, \
                                          POINTER, POINTER

  RedefineVariable  pIID,                 offset IID_IDispatch
  DefineVariable    pITypeInfo,           POINTER,      NULL
  DefineVariable    pDispInterface,       POINTER,      NULL
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     IDispatch.Init
; Purpose:    Initialize the IDispatch interface object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> Interface object whose methods will be dispatched.
;             Arg3: -> TypeLib GUID associated to the interface.
; Return:     Nothing.

Method IDispatch.Init, uses xsi, pOwner:POINTER, pDispInterface:POINTER, pTypeLibGUID:POINTER
  local pITypeLib:POINTER

  DbgText "IDispatch.Init", "IDispatch"
  SetObject xsi
  ACall xsi.Init, pOwner

  .if pDispInterface == NULL                            ;If NULL => it's a dual interface!
    mov [xsi].pDispInterface, xsi
  .else
    m2m [xsi].pDispInterface, pDispInterface, xax
  .endif

  .if pTypeLibGUID == NULL
    m2z [xsi].pITypeInfo
  .else
    invoke LoadRegTypeLib, pTypeLibGUID, 1, 0, LOCALE_USER_DEFAULT, addr pITypeLib
    .if SUCCEEDED(eax)
      mov xdx, [xsi].pDispInterface
      ICall pITypeLib::ITypeLib.GetTypeInfoOfGuid, [xdx].$Obj(IUnknown).pIID, \
                                                   addr [xsi].pITypeInfo
      ICall pITypeLib::ITypeLib.Release
    if DEBUGGING eq TRUE
    .else
      DbgComError eax
    endif
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IDispatch.GetTypeInfoCount
; Purpose:    Retrieve the number of type information interfaces that an object provides, either
;             0 or 1.
; Arguments:  Arg1: -> Info count. (0: NO info available, 1: info available)
; Return:     eax = HRESULT.
;             S_OK: success.
;             E_NOTIMPL: failure.

Method IDispatch.GetTypeInfoCount,, pInfoCnt:POINTER
  DbgText "IDispatch.GetTypeInfoCount", "IDispatch"
  ;Return that one TypeInfo can be found
  SetObject xcx
  mov xdx, pInfoCnt
  .if [xcx].pITypeInfo != NULL
    mov DWORD ptr [xdx], 1
  .else
    m2z DWORD ptr [xdx]
  .endif
  xor eax, eax                                          ;Return S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IDispatch.GetTypeInfo
; Purpose:    Retrieve the type information for an object.
; Arguments:  Arg1: TypeInfo Index.
;             Arg2: Locale context in which to interpret the TypeInfo.
;             Arg3: -> pTypeInfo.
; Return:     eax = HRESULT.
;             S_OK: Success: the type information element exists.
;             DISP_E_BADINDEX: failure, dTypeInfoIndex parameter was not 0.
;             TYPE_E_ELEMENTNOTFOUND: failure, dTypeInfoIndex parameter was not 0.

Method IDispatch.GetTypeInfo,, dTypeInfoIndex:DWORD, dLCID:DWORD, ppTypeInfo:POINTER
  DbgText "IDispatch.GetTypeInfo", "IDispatch"
  SetObject xcx

  ;Set ppTInfo to initially NULL
  mov xdx, ppTypeInfo
  xor eax, eax
  mov POINTER ptr [xdx], xax

  ;Check for a type info index = 0 (only 1 available / zero based index)
  .if dTypeInfoIndex != 0
    mov eax, DISP_E_BADINDEX
  .else
    ;Set ppTInfo to the stored pITypeInfo
    mov xax, [xcx].pITypeInfo
    mov POINTER ptr [xdx], xax

    ;If the stored value is a pointer, indicate a reference is handed out
    .if xax != NULL
      OCall xax::IUnknown.AddRef
      xor eax, eax                                      ;Return S_OK
    .else
      mov eax, E_FAIL
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IDispatch.GetIDsOfNames
; Purpose:    Map a single member name and an optional set of parameter names to a corresponding set
;             of integer dispatch identifiers (DISPIDs), which can then be used on subsequent calls
;             to Invoke.
; Arguments:  Arg1: -> IID_NULL
;             Arg2: -> Passed in array of names to be mapped.
;             Arg3: Count of names to be mapped.
;             Arg4: Locale context in which to interpret the names.
;             Arg5: -> Return ID array corresponding to the Arg2.
; Return:     eax = HRESULT.
;             S_OK: success.
;             E_OUTOFMEMORY: out of memory.
;             DISP_E_UNKNOWNNAME: one or more of the names were not known. The returned array of
;               DISPIDs contains DISPID_UNKNOWN for each entry that corresponds to an unknown name.
;             DISP_E_UNKNOWNLCID: the locale identifier (LCID) was not recognized.

Method IDispatch.GetIDsOfNames,, pIID:POINTER, pNames:POINTER, dNameCnt:DWORD, dLCID:DWORD, \
                                 pNameIDs:POINTER
  DbgText "IDispatch.GetIDsOfNames", "IDispatch"
  SetObject xcx
  ;Get IDs of the Names in the TypeInfo
  .if [xcx].pITypeInfo != NULL
    ICall [xcx].pITypeInfo::ITypeInfo.GetIDsOfNames, pNames, dNameCnt, pNameIDs
  .else
    mov eax, E_FAIL
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IDispatch.Invoke
; Purpose:    Provide access to properties and methods exposed by an object.
; Arguments:  Arg1: Method Member ID.
;             Arg2: -> IID_NULL
;             Arg3: Locale context in which to interpret the names.
;             Arg4: Flags.
;               DISPATCH_METHOD: The member is invoked as a method. If a property has the same name,
;                                both this and the DISPATCH_PROPERTYGET flag may be set.
;               DISPATCH_PROPERTYGET: The member is retrieved as a property or data member.
;               DISPATCH_PROPERTYPUT: The member is changed as a property or data member.
;               DISPATCH_PROPERTYPUTREF: The member is changed by a reference assignment, rather
;                                than a value assignment. This flag is valid only when the
;                                property accepts a reference to an object.
;             Arg5: -> Array of arguments DispParams.
;             Arg6: -> Result VARIANT.
;             Arg7: -> Exception Info.
;             Arg8: -> Index of the argument that produces the error.
; Return:     eax = HRESULT.
;             S_OK: success.
;             DISP_E_BADPARAMCOUNT: the number of elements provided to DISPPARAMS is different from
;               the number of parameters accepted by the method or property.
;             DISP_E_BADVARTYPE: 1 of the parameters in rgvarg is not a valid variant type.
;             DISP_E_EXCEPTION: the application needs to raise an exception. In this case, the
;               structure passed in pExcepInfo should be filled in.
;             DISP_E_MEMBERNOTFOUND: the requested member does not exist, or the call to Invoke
;               tried to set the value of a read-only property.
;             DISP_E_NONAMEDARGS: this implementation of IDispatch does not support named
;               parameters.
;             DISP_E_OVERFLOW: 1 of the parameters in rgvarg could not be coerced to the specified
;               type.
;             DISP_E_PARAMNOTFOUND: 1 of the parameter DISPIDs does not correspond to a parameter on
;               the method. In this case, puArgErr should be set to the first parameter that
;               contains the error.
;             DISP_E_TYPEMISMATCH: 1 or more of the parameters could not be coerced. The index
;               within rgvarg of the first parameter with the incorrect type is returned in the
;               puArgErr parameter.
;             DISP_E_UNKNOWNINTERFACE: the interface identifier passed in riid is not IID_NULL.
;             DISP_E_UNKNOWNLCID: the member being invoked interprets string parameters according
;               to the LCID, and the LCID is not recognized. If the LCID is not needed to interpret
;               parameters, this error should not be returned.
;             DISP_E_PARAMNOTOPTIONAL: a required parameter was omitted.
; Note:       Static methods can NOT be redirected to another interface!
; Link:       https://docs.microsoft.com/en-us/openspecs/windows_protocols/ms-oaut/5c2a1997-60d7-496d-8d9a-ed940bbb82eb

$$PDspMtd typedef proto :POINTER, :ptr DISPPARAMS, :LPVARIANT

Method IDispatch.Invoke, uses xbx xsi, dMethodID:DWORD, pIID:REFIID, dLCID:DWORD, \
                                       wFlags:WORD, pParams:ptr DISPPARAMS, pResult:LPVARIANT, \
                                       pExcepInfo:POINTER, pArgErrIdx:POINTER
  DbgText "IDispatch.Invoke", "IDispatch"
  DbgHex dMethodID,, "IDispatch"
  DbgHex wFlags,, "IDispatch"

.const
  @@IDispatch_JumpTable label POINTER
  POINTER offset @@IDispatch_Static
  POINTER offset @@IDispatch_VirtualInterface
  POINTER offset @@IDispatch_VirtualInterface
  POINTER offset @@IDispatch_Dynamic

.code
  if TARGET_BITNESS eq 32
    $$Reg textequ <edx>
  else
    $$Reg textequ <r10>
  endif

  SetObject xsi
  .if [xsi].pITypeInfo == NULL
    ;Since we have no ITypeInfo, we'll try to dispatch this call using the IDispEvents table
    mov xdx, POINTER ptr [xsi]                          ;xdx -> Dual Method Table
    mov xbx, [xdx - sizeof(POINTER)]                    ;xbx -> Event Translation Table
    mov xcx, [xbx]                                      ;Number of ??EVENT_ENTRY structures
    add xbx, sizeof(QWORD)                              ;xbx -> first ??EVENT_ENTRY
    test xcx, xcx
    .while !ZERO?
      mov eax, [xbx].??EVENT_ENTRY.dID                  ;Recover DispID
      .if eax == dMethodID
        mov dx, [xbx].??EVENT_ENTRY.wFlags              ;DispID found!
        cmp dx, wFlags                                  ;Now check the flags
        je @@Found                                      ;Flags OK
      .endif
      add xbx, sizeof ??EVENT_ENTRY                     ;Goto next ??EVENT_ENTRY
      dec xcx
    .endw
    DbgWarning "Failed to find dMethodID", "IDispatch"
    mov eax, DISP_E_MEMBERNOTFOUND
    ExitMethod

  @@Found:

    if TARGET_BITNESS eq 32
      ;Push pointer to the ret value (only if DISPATCH_METHOD or DISPATCH_PROPERTYGET are specified)
      .ifBitSet wFlags, (DISPATCH_PROPERTYGET or DISPATCH_METHOD)
        mov eax, pResult
        .if eax != NULL                                   ;Check if we have a valid pointer
          mov [eax].VARIANT.vt, VT_I4
          lea ecx, [eax].VARIANT.lVal
          push ecx
        .endif
      .endif

      ;Extract the arguments from the VARIANTS and push them onto the stack
      mov eax, pParams
      mov ecx, [eax].DISPPARAMS.cArgs
      mov edx, [eax].DISPPARAMS.rgvarg
      .while ecx != 0
        mov ax, [edx].VARIANT.vt
        .if (ax & VT_BYREF)
          push [edx].VARIANT.byref
        .elseif eax == VT_VARIANT
          push [edx + 12]
          push [edx + 8]
          push [edx + 4]
          push [edx]
        .elseif (ax == VT_R8 || ax == VT_DATE || ax == VT_CY || ax == VT_FILETIME)
          push [edx + 12]
          push [edx + 8]
        .else
          push [edx].VARIANT.lVal
        .endif
        add edx, sizeof VARIANT
        dec ecx
      .endw
      push esi
    
      ;Call the method according to its type
      movzx ecx, [xbx].??EVENT_ENTRY.wType              ;ecx = Method type 1..4
      test ecx, ecx
      jz @@EOM
      jmp POINTER ptr [offset @@IDispatch_JumpTable + sizeof(POINTER)*ecx - sizeof(POINTER)]
  
    @@IDispatch_Static:
      call [xbx].??EVENT_ENTRY.pHandler                 ;Call event handler
      ExitMethod
    @@IDispatch_VirtualInterface:
      mov $$Reg, [xbx].??EVENT_ENTRY.pHandler           ;Offset into DMT
      add $$Reg, [xsi].pDispInterface                   ;Correct the offset to redirect to
      sub $$Reg, xsi                                    ;  another interface
      call POINTER ptr [$$Reg]                          ;Call event handler
      ExitMethod
    @@IDispatch_Dynamic:
      mov $$Reg, [xbx].??EVENT_ENTRY.pHandler           ;Offset into object instance
      add $$Reg, [xsi].pDispInterface                   ;Add instance POINTER
      call POINTER ptr [$$Reg]                          ;Call event handler

    else

      ;/////////////////////////////////////////////////////////////////////////////////////
      ; This code for x64 is incomplete and wrong due to the more complex calling convention
      ;/////////////////////////////////////////////////////////////////////////////////////
  
      ;Call the method according to its type
      movzx ecx, [xbx].??EVENT_ENTRY.wType              ;ecx = Method type 1..4
      test ecx, ecx
      jz @@EOM
      mov xdx, offset @@IDispatch_JumpTable - sizeof(POINTER)
      jmp POINTER ptr [xdx + sizeof(POINTER)*xcx]
  
    @@IDispatch_Static:
      invoke $$PDspMtd ptr [xbx].??EVENT_ENTRY.pHandler, xsi, pParams, pResult  ;Invoke event handler
      ExitMethod
    @@IDispatch_VirtualInterface:
      mov $$Reg, [xbx].??EVENT_ENTRY.pHandler             ;Offset into DMT
      add $$Reg, [xsi].pDispInterface                     ;Correct the offset to redirect to
      sub $$Reg, xsi                                      ;  another interface
      invoke $$PDspMtd ptr [$$Reg], xsi, pParams, pResult ;Invoke event handler
      ExitMethod
    @@IDispatch_Dynamic:
      mov $$Reg, [xbx].??EVENT_ENTRY.pHandler             ;Offset into object instance
      add $$Reg, [xsi].pDispInterface                     ;Add instance POINTER
      invoke $$PDspMtd ptr [$$Reg], xsi, pParams, pResult ;Invoke event handler
    
    endif
  .else
    invoke SetErrorInfo, 0, 0
    ICall [xsi].pITypeInfo::ITypeInfo.Invoke, [xsi].pDispInterface, dMethodID, \
                                              wFlags, pParams, pResult, pExcepInfo, pArgErrIdx
    if DEBUGGING eq TRUE
      .if FAILED(eax)
        DbgComError eax,, "IDispatch"
      .endif
    endif
  .endif
MethodEnd

endif
