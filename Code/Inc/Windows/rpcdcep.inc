;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\rpcdcep.h', last modified: 19/04/2018 10:43
;Creation parameters: 

include winapifamily.inc
ifndef __RPCDCEP_H__
  __RPCDCEP_H__ equ <>
  if _MSC_VER gt 1000
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if _MSC_VER ge 1200
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    RPC_VERSION struct
      MajorVersion WORD ?
      MinorVersion WORD ?
    RPC_VERSION ends

    _RPC_VERSION typedef RPC_VERSION
    RPC_SYNTAX_IDENTIFIER struct
      SyntaxGUID GUID <>
      SyntaxVersion RPC_VERSION <>
    RPC_SYNTAX_IDENTIFIER ends

    _RPC_SYNTAX_IDENTIFIER typedef RPC_SYNTAX_IDENTIFIER
    PRPC_SYNTAX_IDENTIFIER typedef ptr RPC_SYNTAX_IDENTIFIER
    
    RPC_MESSAGE struct
      Handle RPC_BINDING_HANDLE ?
      DataRepresentation DWORD ?
      Buffer POINTER ?
      BufferLength DWORD ?
      ProcNum DWORD ?
      TransferSyntax PRPC_SYNTAX_IDENTIFIER ?
      RpcInterfaceInformation POINTER ?
      ReservedForRuntime POINTER ?
      ManagerEpv POINTER ?
      ImportContext POINTER ?
      RpcFlags DWORD ?
    RPC_MESSAGE ends

    _RPC_MESSAGE typedef RPC_MESSAGE
    PRPC_MESSAGE typedef ptr RPC_MESSAGE
    
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    RPC_FORWARD_FUNCTION typedef proto :ptr UUID, :ptr RPC_VERSION, :ptr UUID, :ptr BYTE, :ptr ptr
    RPC_ADDRESS_CHANGE_TYPE typedef SDWORD
    PROTOCOL_NOT_LOADED equ 1
    PROTOCOL_LOADED equ 2
    PROTOCOL_ADDRESS_CHANGE equ 3
    
    RPC_ADDRESS_CHANGE_FN typedef proto :ptr
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    RPC_CONTEXT_HANDLE_DEFAULT_GUARD equ (0FFFFF00Dh)
    RPC_CONTEXT_HANDLE_DEFAULT_FLAGS equ 00000000h
    RPC_CONTEXT_HANDLE_FLAGS equ 30000000h
    RPC_CONTEXT_HANDLE_SERIALIZE equ 10000000h
    RPC_CONTEXT_HANDLE_DONT_SERIALIZE equ 20000000h
    if (NTDDI_VERSION ge NTDDI_VISTA)
      RPC_TYPE_STRICT_CONTEXT_HANDLE equ 40000000h
    endif
    RPC_NCA_FLAGS_DEFAULT equ 00000000h
    RPC_NCA_FLAGS_IDEMPOTENT equ 00000001h
    RPC_NCA_FLAGS_BROADCAST equ 00000002h
    RPC_NCA_FLAGS_MAYBE equ 00000004h
    if (NTDDI_VERSION ge NTDDI_VISTA)
      RPCFLG_HAS_GUARANTEE equ 00000010h
    endif
    RPCFLG_WINRT_REMOTE_ASYNC equ 00000020h
    RPC_BUFFER_COMPLETE equ 00001000h
    RPC_BUFFER_PARTIAL equ 00002000h
    RPC_BUFFER_EXTRA equ 00004000h
    RPC_BUFFER_ASYNC equ 00008000h
    RPC_BUFFER_NONOTIFY equ 00010000h
    RPCFLG_MESSAGE equ 01000000h
    RPCFLG_AUTO_COMPLETE equ 08000000h
    RPCFLG_LOCAL_CALL equ 10000000h
    RPCFLG_INPUT_SYNCHRONOUS equ 20000000h
    RPCFLG_ASYNCHRONOUS equ 40000000h
    RPCFLG_NON_NDR equ 80000000h
    if (NTDDI_VERSION ge NTDDI_WINXP)
      RPCFLG_HAS_MULTI_SYNTAXES equ 02000000h
      RPCFLG_HAS_CALLBACK equ 04000000h
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      RPCFLG_ACCESSIBILITY_BIT1 equ 00100000h
      RPCFLG_ACCESSIBILITY_BIT2 equ 00200000h
      RPCFLG_ACCESS_LOCAL equ 00400000h
      NDR_CUSTOM_OR_DEFAULT_ALLOCATOR equ 10000000h
      NDR_DEFAULT_ALLOCATOR equ 20000000h
    endif
    if (NTDDI_VERSION ge NTDDI_WIN8)
      RPCFLG_NDR64_CONTAINS_ARM_LAYOUT equ 04000000h
    endif
    if (NTDDI_VERSION ge NTDDI_WINBLUE)
      RPCFLG_SENDER_WAITING_FOR_REPLY equ 00800000h
    endif
    RPC_FLAGS_VALID_BIT equ 00008000h
    TYPE_RPC_DISPATCH_FUNCTION typedef proto WIN_STD_CALL_CONV :PRPC_MESSAGE
    RPC_DISPATCH_FUNCTION typedef ptr TYPE_RPC_DISPATCH_FUNCTION
    RPC_DISPATCH_TABLE struct
      DispatchTableCount DWORD ?
      DispatchTable POINTER ?
      Reserved LONG_PTR ?
    RPC_DISPATCH_TABLE ends

    PRPC_DISPATCH_TABLE typedef ptr RPC_DISPATCH_TABLE
    
    RPC_PROTSEQ_ENDPOINT struct
      RpcProtocolSequence POINTER ?
      Endpoint POINTER ?
    RPC_PROTSEQ_ENDPOINT ends

    _RPC_PROTSEQ_ENDPOINT typedef RPC_PROTSEQ_ENDPOINT
    PRPC_PROTSEQ_ENDPOINT typedef ptr RPC_PROTSEQ_ENDPOINT
    
    NT351_INTERFACE_SIZE equ 40h
    RPC_INTERFACE_HAS_PIPES equ 0001h
    RPC_SERVER_INTERFACE struct
      Length_ DWORD ?
      InterfaceId RPC_SYNTAX_IDENTIFIER <>
      TransferSyntax RPC_SYNTAX_IDENTIFIER <>
      DispatchTable PRPC_DISPATCH_TABLE ?
      RpcProtseqEndpointCount DWORD ?
      RpcProtseqEndpoint PRPC_PROTSEQ_ENDPOINT ?
      DefaultManagerEpv POINTER ?
      InterpreterInfo POINTER ?
      Flags DWORD ?
    RPC_SERVER_INTERFACE ends

    _RPC_SERVER_INTERFACE typedef RPC_SERVER_INTERFACE
    PRPC_SERVER_INTERFACE typedef ptr RPC_SERVER_INTERFACE
    
    RPC_CLIENT_INTERFACE struct
      Length_ DWORD ?
      InterfaceId RPC_SYNTAX_IDENTIFIER <>
      TransferSyntax RPC_SYNTAX_IDENTIFIER <>
      DispatchTable PRPC_DISPATCH_TABLE ?
      RpcProtseqEndpointCount DWORD ?
      RpcProtseqEndpoint PRPC_PROTSEQ_ENDPOINT ?
      Reserved ULONG_PTR ?
      InterpreterInfo POINTER ?
      Flags DWORD ?
    RPC_CLIENT_INTERFACE ends

    _RPC_CLIENT_INTERFACE typedef RPC_CLIENT_INTERFACE
    PRPC_CLIENT_INTERFACE typedef ptr RPC_CLIENT_INTERFACE
    
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (NTDDI_VERSION ge NTDDI_WINXP)
      @DefProto DllImport, I_RpcNegotiateTransferSyntax, WIN_STD_CALL_CONV,, <:ptr RPC_MESSAGE>, 4
    endif
    @DefProto DllImport, I_RpcGetBuffer, WIN_STD_CALL_CONV,, <:ptr RPC_MESSAGE>, 4
    @DefProto DllImport, I_RpcGetBufferWithObject, WIN_STD_CALL_CONV,, <:ptr RPC_MESSAGE, :ptr UUID>, 8
    @DefProto DllImport, I_RpcSendReceive, WIN_STD_CALL_CONV,, <:ptr RPC_MESSAGE>, 4
    @DefProto DllImport, I_RpcFreeBuffer, WIN_STD_CALL_CONV,, <:ptr RPC_MESSAGE>, 4
    @DefProto DllImport, I_RpcSend, WIN_STD_CALL_CONV,, <:PRPC_MESSAGE>, 4
    @DefProto DllImport, I_RpcReceive, WIN_STD_CALL_CONV,, <:PRPC_MESSAGE, :DWORD>, 8
    @DefProto DllImport, I_RpcFreePipeBuffer, WIN_STD_CALL_CONV,, <:ptr RPC_MESSAGE>, 4
    @DefProto DllImport, I_RpcReallocPipeBuffer, WIN_STD_CALL_CONV,, <:PRPC_MESSAGE, :DWORD>, 8
    I_RPC_MUTEX typedef ptr
    @DefProto DllImport, I_RpcRequestMutex, WIN_STD_CALL_CONV,, <:ptr I_RPC_MUTEX>, 4
    @DefProto DllImport, I_RpcClearMutex, WIN_STD_CALL_CONV,, <:I_RPC_MUTEX>, 4
    @DefProto DllImport, I_RpcDeleteMutex, WIN_STD_CALL_CONV,, <:I_RPC_MUTEX>, 4
    @DefProto DllImport, I_RpcAllocate, WIN_STD_CALL_CONV,, <:DWORD>, 4
    @DefProto DllImport, I_RpcFree, WIN_STD_CALL_CONV,, <:ptr>, 4
    RPC_SYSTEM_HANDLE_FREE_UNRETRIEVED equ 1
    RPC_SYSTEM_HANDLE_FREE_RETRIEVED equ 2
    RPC_SYSTEM_HANDLE_FREE_ALL equ 3
    RPC_SYSTEM_HANDLE_FREE_ERROR_ON_CLOSE equ 4
    @DefProto DllImport, I_RpcFreeSystemHandleCollection, WIN_STD_CALL_CONV,, <:ptr, :DWORD>, 8
    @DefProto DllImport, I_RpcSetSystemHandle, WIN_STD_CALL_CONV,, <:ptr, :BYTE, :DWORD, :ptr, :ptr DWORD>, 20
    @DefProto DllImport, I_RpcGetSystemHandle, WIN_STD_CALL_CONV,, <:ptr BYTE, :BYTE, :DWORD, :DWORD, :ptr>, 20
    @DefProto DllImport, I_RpcFreeSystemHandle, WIN_STD_CALL_CONV,, <:BYTE, :ptr>, 8
    @DefProto DllImport, I_RpcPauseExecution, WIN_STD_CALL_CONV,, <:DWORD>, 4
    @DefProto DllImport, I_RpcGetExtendedError, WIN_STD_CALL_CONV,, <>, 0
    LRPC_SYSTEM_HANDLE_MARSHAL_DIRECTION typedef SDWORD
    MarshalDirectionMarshal equ 0
    MarshalDirectionUnmarshal equ 1
    _LRPC_SYSTEM_HANDLE_MARSHAL_DIRECTION typedef LRPC_SYSTEM_HANDLE_MARSHAL_DIRECTION
    
    @DefProto DllImport, I_RpcSystemHandleTypeSpecificWork, WIN_STD_CALL_CONV,, <:ptr, :BYTE, :BYTE, :LRPC_SYSTEM_HANDLE_MARSHAL_DIRECTION>, 16
    TYPE_PRPC_RUNDOWN typedef proto WIN_STD_CALL_CONV :ptr
    PRPC_RUNDOWN typedef ptr TYPE_PRPC_RUNDOWN
    @DefProto DllImport, I_RpcMonitorAssociation, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :PRPC_RUNDOWN, :ptr>, 12
    @DefProto DllImport, I_RpcStopMonitorAssociation, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE>, 4
    @DefProto DllImport, I_RpcGetCurrentCallHandle, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, I_RpcGetAssociationContext, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr ptr>, 8
    @DefProto DllImport, I_RpcGetServerContextList, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE>, 4
    @DefProto DllImport, I_RpcSetServerContextList, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr>, 8
    @DefProto DllImport, I_RpcNsInterfaceExported, WIN_STD_CALL_CONV,, <:DWORD, :ptr WORD, :ptr RPC_SERVER_INTERFACE>, 12
    @DefProto DllImport, I_RpcNsInterfaceUnexported, WIN_STD_CALL_CONV,, <:DWORD, :ptr WORD, :ptr RPC_SERVER_INTERFACE>, 12
    @DefProto DllImport, I_RpcBindingToStaticStringBindingW, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr ptr WORD>, 8
    @DefProto DllImport, I_RpcBindingInqSecurityContext, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr ptr>, 8
    if (NTDDI_VERSION ge NTDDI_VISTA)
      RPC_SEC_CONTEXT_KEY_INFO struct
        EncryptAlgorithm DWORD ?
        KeySize DWORD ?
        SignatureAlgorithm DWORD ?
      RPC_SEC_CONTEXT_KEY_INFO ends

      _RPC_SEC_CONTEXT_KEY_INFO typedef RPC_SEC_CONTEXT_KEY_INFO
      PRPC_SEC_CONTEXT_KEY_INFO typedef ptr RPC_SEC_CONTEXT_KEY_INFO
      
      @DefProto DllImport, I_RpcBindingInqSecurityContextKeyInfo, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr>, 8
    endif
    @DefProto DllImport, I_RpcBindingInqWireIdForSnego, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr BYTE>, 8
    if (NTDDI_VERSION ge NTDDI_WS03)
      @DefProto DllImport, I_RpcBindingInqMarshalledTargetInfo, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr DWORD, :ptr RPC_CSTR>, 12
    endif
    if (NTDDI_VERSION ge NTDDI_WINXP)
      @DefProto DllImport, I_RpcBindingInqLocalClientPID, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr DWORD>, 8
      @DefProto DllImport, I_RpcBindingHandleToAsyncHandle, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr ptr>, 8
    endif
    ifdef RPC_UNICODE_SUPPORTED
      @DefProto DllImport, I_RpcNsBindingSetEntryNameW, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :DWORD, :RPC_WSTR>, 12
      @DefProto DllImport, I_RpcNsBindingSetEntryNameA, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :DWORD, :RPC_CSTR>, 12
      @DefProto DllImport, I_RpcServerUseProtseqEp2A, WIN_STD_CALL_CONV,, <:RPC_CSTR, :RPC_CSTR, :DWORD, :RPC_CSTR, :ptr, :ptr>, 24
      @DefProto DllImport, I_RpcServerUseProtseqEp2W, WIN_STD_CALL_CONV,, <:RPC_WSTR, :RPC_WSTR, :DWORD, :RPC_WSTR, :ptr, :ptr>, 24
      @DefProto DllImport, I_RpcServerUseProtseq2W, WIN_STD_CALL_CONV,, <:RPC_WSTR, :RPC_WSTR, :DWORD, :ptr, :ptr>, 20
      @DefProto DllImport, I_RpcServerUseProtseq2A, WIN_STD_CALL_CONV,, <:RPC_CSTR, :RPC_CSTR, :DWORD, :ptr, :ptr>, 20
      ifdef UNICODE
        I_RpcNsBindingSetEntryName equ <I_RpcNsBindingSetEntryNameW>
        I_RpcServerUseProtseqEp2 equ <I_RpcServerUseProtseqEp2W>
        I_RpcServerUseProtseq2 equ <I_RpcServerUseProtseq2W>
      else
        I_RpcNsBindingSetEntryName equ <I_RpcNsBindingSetEntryNameA>
        I_RpcServerUseProtseqEp2 equ <I_RpcServerUseProtseqEp2A>
        I_RpcServerUseProtseq2 equ <I_RpcServerUseProtseq2A>
      endif
    else
      @DefProto DllImport, I_RpcNsBindingSetEntryName, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :DWORD, :RPC_CSTR>, 12
      @DefProto DllImport, I_RpcServerUseProtseq2, WIN_STD_CALL_CONV,, <:RPC_CSTR, :RPC_CSTR, :DWORD, :ptr, :ptr>, 20
      @DefProto DllImport, I_RpcServerUseProtseqEp2, WIN_STD_CALL_CONV,, <:RPC_CSTR, :RPC_CSTR, :DWORD, :RPC_CSTR, :ptr, :ptr>, 24
    endif
    @DefProto DllImport, I_RpcServerStartService, WIN_STD_CALL_CONV,, <:RPC_WSTR, :RPC_WSTR, :RPC_IF_HANDLE>, 12
    ifdef RPC_UNICODE_SUPPORTED
      @DefProto DllImport, I_RpcBindingInqDynamicEndpointW, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr RPC_WSTR>, 8
      @DefProto DllImport, I_RpcBindingInqDynamicEndpointA, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr RPC_CSTR>, 8
      ifdef UNICODE
        I_RpcBindingInqDynamicEndpoint equ <I_RpcBindingInqDynamicEndpointW>
      else
        I_RpcBindingInqDynamicEndpoint equ <I_RpcBindingInqDynamicEndpointA>
      endif
    else
      @DefProto DllImport, I_RpcBindingInqDynamicEndpoint, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr RPC_CSTR>, 8
    endif
    if (NTDDI_VERSION ge NTDDI_WINXP)
      @DefProto DllImport, I_RpcServerCheckClientRestriction, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE>, 4
    endif
    TRANSPORT_TYPE_CN equ 01h
    TRANSPORT_TYPE_DG equ 02h
    TRANSPORT_TYPE_LPC equ 04h
    TRANSPORT_TYPE_WMSG equ 08h
    @DefProto DllImport, I_RpcBindingInqTransportType, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr DWORD>, 8
    RPC_TRANSFER_SYNTAX struct
      Uuid UUID <>
      VersMajor WORD ?
      VersMinor WORD ?
    RPC_TRANSFER_SYNTAX ends

    _RPC_TRANSFER_SYNTAX typedef RPC_TRANSFER_SYNTAX
    @DefProto DllImport, I_RpcIfInqTransferSyntaxes, WIN_STD_CALL_CONV,, <:RPC_IF_HANDLE, :ptr RPC_TRANSFER_SYNTAX, :DWORD, :ptr DWORD>, 16
    @DefProto DllImport, I_UuidCreate, WIN_STD_CALL_CONV,, <:ptr UUID>, 4
    @DefProto DllImport, I_RpcUninitializeNdrOle, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, I_RpcBindingCopy, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr RPC_BINDING_HANDLE>, 8
    @DefProto DllImport, I_RpcBindingIsClientLocal, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr DWORD>, 8
    @DefProto DllImport, I_RpcBindingInqConnId, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr ptr, :ptr SDWORD>, 12
    @DefProto DllImport, I_RpcBindingCreateNP, WIN_STD_CALL_CONV,, <:RPC_WSTR, :RPC_WSTR, :RPC_WSTR, :ptr RPC_BINDING_HANDLE>, 16
    @DefProto DllImport, I_RpcSsDontSerializeContext, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, I_RpcLaunchDatagramReceiveThread, WIN_STD_CALL_CONV,, <:ptr>, 4
    @DefProto DllImport, I_RpcServerRegisterForwardFunction, WIN_STD_CALL_CONV,, <:ptr RPC_FORWARD_FUNCTION>, 4
    I_RpcServerInqAddressChangeFn proto WIN_STD_CALL_CONV
    I_RpcServerSetAddressChangeFn proto WIN_STD_CALL_CONV :ptr RPC_ADDRESS_CHANGE_FN
    if (NTDDI_VERSION ge NTDDI_WINXP)
      RPC_P_ADDR_FORMAT_TCP_IPV4 equ 1
      RPC_P_ADDR_FORMAT_TCP_IPV6 equ 2
      @DefProto DllImport, I_RpcServerInqLocalConnAddress, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr, :ptr DWORD, :ptr DWORD>, 16
      @DefProto DllImport, I_RpcServerInqRemoteConnAddress, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr, :ptr DWORD, :ptr DWORD>, 16
      @DefProto DllImport, I_RpcSessionStrictContextHandle, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, I_RpcTurnOnEEInfoPropagation, WIN_STD_CALL_CONV,, <>, 0
    endif
    @DefProto DllImport, I_RpcConnectionInqSockBuffSize, WIN_STD_CALL_CONV,, <:ptr DWORD, :ptr DWORD>, 8
    @DefProto DllImport, I_RpcConnectionSetSockBuffSize, WIN_STD_CALL_CONV,, <:DWORD, :DWORD>, 8
    TYPE_RPCLT_PDU_FILTER_FUNC typedef proto WIN_STD_CALL_CONV :ptr, :DWORD, :SDWORD
    RPCLT_PDU_FILTER_FUNC typedef ptr TYPE_RPCLT_PDU_FILTER_FUNC
    TYPE_RPC_SETFILTER_FUNC typedef proto c :RPCLT_PDU_FILTER_FUNC
    RPC_SETFILTER_FUNC typedef ptr TYPE_RPC_SETFILTER_FUNC
    ifndef WINNT
      @DefProto DllImport, I_RpcServerStartListening, WIN_STD_CALL_CONV,, <:ptr>, 4
      @DefProto DllImport, I_RpcServerStopListening, WIN_STD_CALL_CONV,, <>, 0
      TYPE_RPC_BLOCKING_FN typedef proto WIN_STD_CALL_CONV :ptr, :ptr, :ptr
      RPC_BLOCKING_FN typedef ptr TYPE_RPC_BLOCKING_FN
      @DefProto DllImport, I_RpcBindingSetAsync, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :RPC_BLOCKING_FN, :DWORD>, 12
      @DefProto DllImport, I_RpcSetThreadParams, WIN_STD_CALL_CONV,, <:SDWORD, :ptr, :ptr>, 12
      @DefProto DllImport, I_RpcWindowProc, WIN_STD_CALL_CONV,, <:ptr, :DWORD, :DWORD, :DWORD>, 16
      @DefProto DllImport, I_RpcServerUnregisterEndpointA, WIN_STD_CALL_CONV,, <:RPC_CSTR, :RPC_CSTR>, 8
      @DefProto DllImport, I_RpcServerUnregisterEndpointW, WIN_STD_CALL_CONV,, <:RPC_WSTR, :RPC_WSTR>, 8
      ifdef UNICODE
        I_RpcServerUnregisterEndpoint equ <I_RpcServerUnregisterEndpointW>
      else
        I_RpcServerUnregisterEndpoint equ <I_RpcServerUnregisterEndpointA>
      endif
    endif
    @DefProto DllImport, I_RpcServerInqTransportType, WIN_STD_CALL_CONV,, <:ptr DWORD>, 4
    @DefProto DllImport, I_RpcMapWin32Status, WIN_STD_CALL_CONV,, <:RPC_STATUS>, 4
    if (NTDDI_VERSION ge NTDDI_WS03)
      RPC_C_OPT_SESSION_ID equ 6
      RPC_C_OPT_COOKIE_AUTH equ 7
      RPC_C_OPT_RESOURCE_TYPE_UUID equ 8
      RPC_C_OPT_COOKIE_AUTH_DESCRIPTOR struct
        BufferSize DWORD ?
        Buffer POINTER ?
      RPC_C_OPT_COOKIE_AUTH_DESCRIPTOR ends

      _RPC_C_OPT_COOKIE_AUTH_DESCRIPTOR typedef RPC_C_OPT_COOKIE_AUTH_DESCRIPTOR
      RDR_CALLOUT_STATE struct
        LastError RPC_STATUS ?
        LastEEInfo POINTER ?
        LastCalledStage RPC_HTTP_REDIRECTOR_STAGE ?
        ServerName POINTER ?
        ServerPort POINTER ?
        RemoteUser POINTER ?
        AuthType POINTER ?
        ResourceTypePresent BYTE ?
        SessionIdPresent BYTE ?
        InterfacePresent BYTE ?
        ResourceType UUID <>
        SessionId UUID <>
        Interface RPC_SYNTAX_IDENTIFIER <>
        CertContext POINTER ?
      RDR_CALLOUT_STATE ends

      _RDR_CALLOUT_STATE typedef RDR_CALLOUT_STATE
    endif
    if (NTDDI_VERSION ge NTDDI_WINXP)
      TYPE_I_RpcProxyIsValidMachineFn typedef proto WIN_STD_CALL_CONV :RPC_WSTR, :RPC_WSTR, :DWORD
      I_RpcProxyIsValidMachineFn typedef ptr TYPE_I_RpcProxyIsValidMachineFn
      TYPE_I_RpcProxyGetClientAddressFn typedef proto WIN_STD_CALL_CONV :ptr, :ptr SBYTE, :ptr DWORD
      I_RpcProxyGetClientAddressFn typedef ptr TYPE_I_RpcProxyGetClientAddressFn
      TYPE_I_RpcProxyGetConnectionTimeoutFn typedef proto WIN_STD_CALL_CONV :ptr DWORD
      I_RpcProxyGetConnectionTimeoutFn typedef ptr TYPE_I_RpcProxyGetConnectionTimeoutFn
      if (NTDDI_VERSION ge NTDDI_WS03)
        TYPE_I_RpcPerformCalloutFn typedef proto WIN_STD_CALL_CONV :ptr, :ptr RDR_CALLOUT_STATE, :RPC_HTTP_REDIRECTOR_STAGE
        I_RpcPerformCalloutFn typedef ptr TYPE_I_RpcPerformCalloutFn
        TYPE_I_RpcFreeCalloutStateFn typedef proto WIN_STD_CALL_CONV :ptr RDR_CALLOUT_STATE
        I_RpcFreeCalloutStateFn typedef ptr TYPE_I_RpcFreeCalloutStateFn
        TYPE_I_RpcProxyGetClientSessionAndResourceUUID typedef proto WIN_STD_CALL_CONV :ptr, :ptr SDWORD, :ptr UUID, :ptr SDWORD, :ptr UUID
        I_RpcProxyGetClientSessionAndResourceUUID typedef ptr TYPE_I_RpcProxyGetClientSessionAndResourceUUID
      endif
      if (NTDDI_VERSION ge NTDDI_VISTA)
        TYPE_I_RpcProxyFilterIfFn typedef proto WIN_STD_CALL_CONV :ptr, :ptr UUID, :WORD, :ptr SDWORD
        I_RpcProxyFilterIfFn typedef ptr TYPE_I_RpcProxyFilterIfFn
        RpcPerfCounters typedef SDWORD
        RpcCurrentUniqueUser equ 1
        RpcBackEndConnectionAttempts equ 2
        RpcBackEndConnectionFailed equ 3
        RpcRequestsPerSecond equ 4
        RpcIncomingConnections equ 5
        RpcIncomingBandwidth equ 6
        RpcOutgoingBandwidth equ 7
        RpcAttemptedLbsDecisions equ 8
        RpcFailedLbsDecisions equ 9
        RpcAttemptedLbsMessages equ 10
        RpcFailedLbsMessages equ 11
        RpcLastCounter equ 12
        RpcProxyPerfCounters typedef RpcPerfCounters
        
        TYPE_I_RpcProxyUpdatePerfCounterFn typedef proto WIN_STD_CALL_CONV :RpcPerfCounters, :SDWORD, :DWORD
        I_RpcProxyUpdatePerfCounterFn typedef ptr TYPE_I_RpcProxyUpdatePerfCounterFn
        TYPE_I_RpcProxyUpdatePerfCounterBackendServerFn typedef proto WIN_STD_CALL_CONV :ptr WORD, :SDWORD
        I_RpcProxyUpdatePerfCounterBackendServerFn typedef ptr TYPE_I_RpcProxyUpdatePerfCounterBackendServerFn
      endif
      RPC_PROXY_CONNECTION_TYPE_IN_PROXY equ 0
      RPC_PROXY_CONNECTION_TYPE_OUT_PROXY equ 1
      if (NTDDI_VERSION ge NTDDI_WS03)
        I_RpcProxyCallbackInterface struct
          IsValidMachineFn I_RpcProxyIsValidMachineFn ?
          GetClientAddressFn I_RpcProxyGetClientAddressFn ?
          GetConnectionTimeoutFn I_RpcProxyGetConnectionTimeoutFn ?
          PerformCalloutFn I_RpcPerformCalloutFn ?
          FreeCalloutStateFn I_RpcFreeCalloutStateFn ?
          GetClientSessionAndResourceUUIDFn I_RpcProxyGetClientSessionAndResourceUUID ?
          if (NTDDI_VERSION ge NTDDI_VISTA)
            ProxyFilterIfFn I_RpcProxyFilterIfFn ?
            RpcProxyUpdatePerfCounterFn I_RpcProxyUpdatePerfCounterFn ?
            RpcProxyUpdatePerfCounterBackendServerFn I_RpcProxyUpdatePerfCounterBackendServerFn ?
          endif
        I_RpcProxyCallbackInterface ends

        tagI_RpcProxyCallbackInterface typedef I_RpcProxyCallbackInterface
        @DefProto DllImport, I_RpcProxyNewConnection, WIN_STD_CALL_CONV,, <:DWORD, :ptr WORD, :ptr WORD, :ptr WORD, :ptr, :ptr RDR_CALLOUT_STATE, :ptr I_RpcProxyCallbackInterface>, 28
      else
        I_RpcProxyCallbackInterface struct
          IsValidMachineFn I_RpcProxyIsValidMachineFn ?
          GetClientAddressFn I_RpcProxyGetClientAddressFn ?
          GetConnectionTimeoutFn I_RpcProxyGetConnectionTimeoutFn ?
        I_RpcProxyCallbackInterface ends

        tagI_RpcProxyCallbackInterface typedef I_RpcProxyCallbackInterface
        @DefProto DllImport, I_RpcProxyNewConnection, WIN_STD_CALL_CONV,, <:DWORD, :ptr WORD, :ptr WORD, :ptr, :ptr I_RpcProxyCallbackInterface>, 20
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_WS03)
      @DefProto DllImport, I_RpcReplyToClientWithStatus, WIN_STD_CALL_CONV,, <:ptr, :RPC_STATUS>, 8
      @DefProto DllImport, I_RpcRecordCalloutFailure, WIN_STD_CALL_CONV,, <:RPC_STATUS, :ptr RDR_CALLOUT_STATE, :ptr WORD>, 12
    endif
    if (NTDDI_VERSION ge NTDDI_WIN7)
      @DefProto DllImport, I_RpcMgmtEnableDedicatedThreadPool, WIN_STD_CALL_CONV,, <>, 0
    endif
    if (NTDDI_VERSION ge NTDDI_WIN7)
      @DefProto DllImport, I_RpcGetDefaultSD, WIN_STD_CALL_CONV,, <:ptr ptr>, 4
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      @DefProto DllImport, I_RpcOpenClientProcess, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :DWORD, :ptr ptr>, 12
    endif
    if (NTDDI_VERSION ge NTDDI_WIN8)
      @DefProto DllImport, I_RpcBindingIsServerLocal, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr DWORD>, 8
      I_RpcBindingSetPrivateOption proto WIN_STD_CALL_CONV :RPC_BINDING_HANDLE, :DWORD, :ULONG_PTR
      RPC_C_OPT_PRIVATE_SUPPRESS_WAKE equ 1
      RPC_C_OPT_PRIVATE_DO_NOT_DISTURB equ 2
    endif
    if (NTDDI_VERSION ge NTDDI_WINBLUE)
      I_RpcServerSubscribeForDisconnectNotification proto WIN_STD_CALL_CONV :RPC_BINDING_HANDLE, :ptr
      I_RpcServerGetAssociationID proto WIN_STD_CALL_CONV :RPC_BINDING_HANDLE, :ptr DWORD
      @DefProto DllImport, I_RpcServerDisableExceptionFilter, WIN_STD_CALL_CONV,, <>, 0
    endif
  endif
  if _MSC_VER ge 1200
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if Defined(__cplusplus)
    ;[...]
  else
    I_RRPCUNINITIALIZENDROLE_EXPORT_NAME equ (1000)
  endif
endif

