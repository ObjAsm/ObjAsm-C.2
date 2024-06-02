;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\objidlbase.h
;             Created on (UTC) 06/04/2024 06:15:57
;             Last modified on (UTC) 21/02/2024 18:18:08

ifndef __REQUIRED_RPCNDR_H_VERSION__
  __REQUIRED_RPCNDR_H_VERSION__ equ 501
endif
ifndef __REQUIRED_RPCSAL_H_VERSION__
  __REQUIRED_RPCSAL_H_VERSION__ equ 100
endif
include rpc.inc
include rpcndr.inc
ifndef __RPCNDR_H_VERSION__
  .err <this stub requires an updated version of < rpcndr.h >>
endif
ifndef COM_NO_WINDOWS_H
  include windows.inc
  include ole2.inc
endif
ifndef __objidlbase_h__
  __objidlbase_h__ equ <>
  if Defined(_MSC_VER) and (_MSC_VER ge 1020)
  endif
  ifndef DECLSPEC_XFGVIRT
    if Defined(_CONTROL_FLOW_GUARD_XFG)
      DECLSPEC_XFGVIRT macro base, func
        exitm <__declspec(xfg_virtual (base, func))>
      endm
    else
      DECLSPEC_XFGVIRT macro base, func
        exitm <>
      endm
    endif
  endif
  ifndef __IMarshal_FWD_DEFINED__
    __IMarshal_FWD_DEFINED__ equ <>
  endif
  ifndef __INoMarshal_FWD_DEFINED__
    __INoMarshal_FWD_DEFINED__ equ <>
  endif
  ifndef __IAgileObject_FWD_DEFINED__
    __IAgileObject_FWD_DEFINED__ equ <>
  endif
  ifndef __IActivationFilter_FWD_DEFINED__
    __IActivationFilter_FWD_DEFINED__ equ <>
  endif
  ifndef __IMarshal2_FWD_DEFINED__
    __IMarshal2_FWD_DEFINED__ equ <>
  endif
  ifndef __IMalloc_FWD_DEFINED__
    __IMalloc_FWD_DEFINED__ equ <>
  endif
  ifndef __IStdMarshalInfo_FWD_DEFINED__
    __IStdMarshalInfo_FWD_DEFINED__ equ <>
  endif
  ifndef __IExternalConnection_FWD_DEFINED__
    __IExternalConnection_FWD_DEFINED__ equ <>
  endif
  ifndef __IMultiQI_FWD_DEFINED__
    __IMultiQI_FWD_DEFINED__ equ <>
  endif
  ifndef __AsyncIMultiQI_FWD_DEFINED__
    __AsyncIMultiQI_FWD_DEFINED__ equ <>
  endif
  ifndef __IInternalUnknown_FWD_DEFINED__
    __IInternalUnknown_FWD_DEFINED__ equ <>
  endif
  ifndef __IEnumUnknown_FWD_DEFINED__
    __IEnumUnknown_FWD_DEFINED__ equ <>
  endif
  ifndef __IEnumString_FWD_DEFINED__
    __IEnumString_FWD_DEFINED__ equ <>
  endif
  ifndef __ISequentialStream_FWD_DEFINED__
    __ISequentialStream_FWD_DEFINED__ equ <>
  endif
  ifndef __IStream_FWD_DEFINED__
    __IStream_FWD_DEFINED__ equ <>
  endif
  ifndef __IRpcChannelBuffer_FWD_DEFINED__
    __IRpcChannelBuffer_FWD_DEFINED__ equ <>
  endif
  ifndef __IRpcChannelBuffer2_FWD_DEFINED__
    __IRpcChannelBuffer2_FWD_DEFINED__ equ <>
  endif
  ifndef __IAsyncRpcChannelBuffer_FWD_DEFINED__
    __IAsyncRpcChannelBuffer_FWD_DEFINED__ equ <>
  endif
  ifndef __IRpcChannelBuffer3_FWD_DEFINED__
    __IRpcChannelBuffer3_FWD_DEFINED__ equ <>
  endif
  ifndef __IRpcSyntaxNegotiate_FWD_DEFINED__
    __IRpcSyntaxNegotiate_FWD_DEFINED__ equ <>
  endif
  ifndef __IRpcProxyBuffer_FWD_DEFINED__
    __IRpcProxyBuffer_FWD_DEFINED__ equ <>
  endif
  ifndef __IRpcStubBuffer_FWD_DEFINED__
    __IRpcStubBuffer_FWD_DEFINED__ equ <>
  endif
  ifndef __IPSFactoryBuffer_FWD_DEFINED__
    __IPSFactoryBuffer_FWD_DEFINED__ equ <>
  endif
  ifndef __IChannelHook_FWD_DEFINED__
    __IChannelHook_FWD_DEFINED__ equ <>
  endif
  ifndef __IClientSecurity_FWD_DEFINED__
    __IClientSecurity_FWD_DEFINED__ equ <>
  endif
  ifndef __IServerSecurity_FWD_DEFINED__
    __IServerSecurity_FWD_DEFINED__ equ <>
  endif
  ifndef __IRpcOptions_FWD_DEFINED__
    __IRpcOptions_FWD_DEFINED__ equ <>
  endif
  ifndef __IGlobalOptions_FWD_DEFINED__
    __IGlobalOptions_FWD_DEFINED__ equ <>
  endif
  ifndef __ISurrogate_FWD_DEFINED__
    __ISurrogate_FWD_DEFINED__ equ <>
  endif
  ifndef __IGlobalInterfaceTable_FWD_DEFINED__
    __IGlobalInterfaceTable_FWD_DEFINED__ equ <>
  endif
  ifndef __ISynchronize_FWD_DEFINED__
    __ISynchronize_FWD_DEFINED__ equ <>
  endif
  ifndef __ISynchronizeHandle_FWD_DEFINED__
    __ISynchronizeHandle_FWD_DEFINED__ equ <>
  endif
  ifndef __ISynchronizeEvent_FWD_DEFINED__
    __ISynchronizeEvent_FWD_DEFINED__ equ <>
  endif
  ifndef __ISynchronizeContainer_FWD_DEFINED__
    __ISynchronizeContainer_FWD_DEFINED__ equ <>
  endif
  ifndef __ISynchronizeMutex_FWD_DEFINED__
    __ISynchronizeMutex_FWD_DEFINED__ equ <>
  endif
  ifndef __ICancelMethodCalls_FWD_DEFINED__
    __ICancelMethodCalls_FWD_DEFINED__ equ <>
  endif
  ifndef __IAsyncManager_FWD_DEFINED__
    __IAsyncManager_FWD_DEFINED__ equ <>
  endif
  ifndef __ICallFactory_FWD_DEFINED__
    __ICallFactory_FWD_DEFINED__ equ <>
  endif
  ifndef __IRpcHelper_FWD_DEFINED__
    __IRpcHelper_FWD_DEFINED__ equ <>
  endif
  ifndef __IReleaseMarshalBuffers_FWD_DEFINED__
    __IReleaseMarshalBuffers_FWD_DEFINED__ equ <>
  endif
  ifndef __IWaitMultiple_FWD_DEFINED__
    __IWaitMultiple_FWD_DEFINED__ equ <>
  endif
  ifndef __IAddrTrackingControl_FWD_DEFINED__
    __IAddrTrackingControl_FWD_DEFINED__ equ <>
  endif
  ifndef __IAddrExclusionControl_FWD_DEFINED__
    __IAddrExclusionControl_FWD_DEFINED__ equ <>
  endif
  ifndef __IPipeByte_FWD_DEFINED__
    __IPipeByte_FWD_DEFINED__ equ <>
  endif
  ifndef __AsyncIPipeByte_FWD_DEFINED__
    __AsyncIPipeByte_FWD_DEFINED__ equ <>
  endif
  ifndef __IPipeLong_FWD_DEFINED__
    __IPipeLong_FWD_DEFINED__ equ <>
  endif
  ifndef __AsyncIPipeLong_FWD_DEFINED__
    __AsyncIPipeLong_FWD_DEFINED__ equ <>
  endif
  ifndef __IPipeDouble_FWD_DEFINED__
    __IPipeDouble_FWD_DEFINED__ equ <>
  endif
  ifndef __AsyncIPipeDouble_FWD_DEFINED__
    __AsyncIPipeDouble_FWD_DEFINED__ equ <>
  endif
  ifndef __IEnumContextProps_FWD_DEFINED__
    __IEnumContextProps_FWD_DEFINED__ equ <>
  endif
  ifndef __IContext_FWD_DEFINED__
    __IContext_FWD_DEFINED__ equ <>
  endif
  ifndef __IObjContext_FWD_DEFINED__
    __IObjContext_FWD_DEFINED__ equ <>
  endif
  ifndef __IComThreadingInfo_FWD_DEFINED__
    __IComThreadingInfo_FWD_DEFINED__ equ <>
  endif
  ifndef __IProcessInitControl_FWD_DEFINED__
    __IProcessInitControl_FWD_DEFINED__ equ <>
  endif
  ifndef __IFastRundown_FWD_DEFINED__
    __IFastRundown_FWD_DEFINED__ equ <>
  endif
  ifndef __IMarshalingStream_FWD_DEFINED__
    __IMarshalingStream_FWD_DEFINED__ equ <>
  endif
  ifndef __IAgileReference_FWD_DEFINED__
    __IAgileReference_FWD_DEFINED__ equ <>
  endif
  ifndef __IMachineGlobalObjectTable_FWD_DEFINED__
    __IMachineGlobalObjectTable_FWD_DEFINED__ equ <>
  endif
  ifndef __ISupportAllowLowerTrustActivation_FWD_DEFINED__
    __ISupportAllowLowerTrustActivation_FWD_DEFINED__ equ <>
  endif
  include unknwnbase.inc
  ifdef __cplusplus
    ;[...]
  endif
  include winapifamily.inc
  if (NTDDI_VERSION ge NTDDI_VISTA and  not Defined(_WIN32_WINNT))
    _WIN32_WINNT equ 0600h
  endif
  if (NTDDI_VERSION ge NTDDI_WS03 and  not Defined(_WIN32_WINNT))
    _WIN32_WINNT equ 0502h
  endif
  if (NTDDI_VERSION ge NTDDI_WINXP and  not Defined(_WIN32_WINNT))
    _WIN32_WINNT equ 0501h
  endif
  if (NTDDI_VERSION ge NTDDI_WIN2K and  not Defined(_WIN32_WINNT))
    _WIN32_WINNT equ 0500h
  endif
  if (_MSC_VER ge 800)
    if _MSC_VER ge 1200
      ifndef _MSC_EXTENSIONS
      endif
    endif
  endif
  if (_MSC_VER ge 1020)
  endif
;  include limits.inc
  ifndef _OBJIDLBASE_
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      COSERVERINFO struct
        dwReserved1 DWORD ?
        pwszName LPWSTR ?
        pAuthInfo POINTER ?
        dwReserved2 DWORD ?
      COSERVERINFO ends
      _COSERVERINFO typedef COSERVERINFO
      externdef __MIDL_itf_objidlbase_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_objidlbase_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IMarshal_INTERFACE_DEFINED__
        __IMarshal_INTERFACE_DEFINED__ equ <>
        LPMARSHAL typedef ptr IMarshal
        externdef IID_IMarshal:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IMarshalVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IMarshalVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IMarshal, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IMarshal
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IMarshal
            DECLSPEC_XFGVIRT(IMarshal, GetUnmarshalClass)
            STD_METHOD GetUnmarshalClass, :ptr IMarshal, :REFIID, :ptr, :DWORD, :ptr, :DWORD, :ptr CLSID
            DECLSPEC_XFGVIRT(IMarshal, GetMarshalSizeMax)
            STD_METHOD GetMarshalSizeMax, :ptr IMarshal, :REFIID, :ptr, :DWORD, :ptr, :DWORD, :ptr DWORD
            DECLSPEC_XFGVIRT(IMarshal, MarshalInterface)
            STD_METHOD MarshalInterface, :ptr IMarshal, :ptr IStream, :REFIID, :ptr, :DWORD, :ptr, :DWORD
            DECLSPEC_XFGVIRT(IMarshal, UnmarshalInterface)
            STD_METHOD UnmarshalInterface, :ptr IMarshal, :ptr IStream, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IMarshal, ReleaseMarshalData)
            STD_METHOD ReleaseMarshalData, :ptr IMarshal, :ptr IStream
            DECLSPEC_XFGVIRT(IMarshal, DisconnectObject)
            STD_METHOD DisconnectObject, :ptr IMarshal, :DWORD
            ??Interface equ <>
            END_INTERFACE
          IMarshalVtbl ends
          IMarshal struct
            lpVtbl POINTER ?
          IMarshal ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __INoMarshal_INTERFACE_DEFINED__
        __INoMarshal_INTERFACE_DEFINED__ equ <>
        externdef IID_INoMarshal:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          INoMarshalVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <INoMarshalVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr INoMarshal, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr INoMarshal
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr INoMarshal
            ??Interface equ <>
            END_INTERFACE
          INoMarshalVtbl ends
          INoMarshal struct
            lpVtbl POINTER ?
          INoMarshal ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IAgileObject_INTERFACE_DEFINED__
        __IAgileObject_INTERFACE_DEFINED__ equ <>
        externdef IID_IAgileObject:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IAgileObjectVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IAgileObjectVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IAgileObject, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IAgileObject
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IAgileObject
            ??Interface equ <>
            END_INTERFACE
          IAgileObjectVtbl ends
          IAgileObject struct
            lpVtbl POINTER ?
          IAgileObject ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      externdef __MIDL_itf_objidlbase_0000_0003_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_objidlbase_0000_0003_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IActivationFilter_INTERFACE_DEFINED__
        __IActivationFilter_INTERFACE_DEFINED__ equ <>
        ACTIVATIONTYPE typedef SDWORD
        ACTIVATIONTYPE_UNCATEGORIZED equ 0
        ACTIVATIONTYPE_FROM_MONIKER equ 1h
        ACTIVATIONTYPE_FROM_DATA equ 2h
        ACTIVATIONTYPE_FROM_STORAGE equ 4h
        ACTIVATIONTYPE_FROM_STREAM equ 8h
        ACTIVATIONTYPE_FROM_FILE equ 10h
        tagACTIVATIONTYPE typedef ACTIVATIONTYPE

        externdef IID_IActivationFilter:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActivationFilterVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActivationFilterVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IActivationFilter, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IActivationFilter
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IActivationFilter
            DECLSPEC_XFGVIRT(IActivationFilter, HandleActivation)
            STD_METHOD HandleActivation, :ptr IActivationFilter, :DWORD, :REFCLSID, :ptr CLSID
            ??Interface equ <>
            END_INTERFACE
          IActivationFilterVtbl ends
          IActivationFilter struct
            lpVtbl POINTER ?
          IActivationFilter ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IMarshal2_INTERFACE_DEFINED__
        __IMarshal2_INTERFACE_DEFINED__ equ <>
        LPMARSHAL2 typedef ptr IMarshal2
        externdef IID_IMarshal2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IMarshal2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IMarshal2Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IMarshal2, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IMarshal2
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IMarshal2
            DECLSPEC_XFGVIRT(IMarshal, GetUnmarshalClass)
            STD_METHOD GetUnmarshalClass, :ptr IMarshal2, :REFIID, :ptr, :DWORD, :ptr, :DWORD, :ptr CLSID
            DECLSPEC_XFGVIRT(IMarshal, GetMarshalSizeMax)
            STD_METHOD GetMarshalSizeMax, :ptr IMarshal2, :REFIID, :ptr, :DWORD, :ptr, :DWORD, :ptr DWORD
            DECLSPEC_XFGVIRT(IMarshal, MarshalInterface)
            STD_METHOD MarshalInterface, :ptr IMarshal2, :ptr IStream, :REFIID, :ptr, :DWORD, :ptr, :DWORD
            DECLSPEC_XFGVIRT(IMarshal, UnmarshalInterface)
            STD_METHOD UnmarshalInterface, :ptr IMarshal2, :ptr IStream, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IMarshal, ReleaseMarshalData)
            STD_METHOD ReleaseMarshalData, :ptr IMarshal2, :ptr IStream
            DECLSPEC_XFGVIRT(IMarshal, DisconnectObject)
            STD_METHOD DisconnectObject, :ptr IMarshal2, :DWORD
            ??Interface equ <>
            END_INTERFACE
          IMarshal2Vtbl ends
          IMarshal2 struct
            lpVtbl POINTER ?
          IMarshal2 ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IMalloc_INTERFACE_DEFINED__
        __IMalloc_INTERFACE_DEFINED__ equ <>
        LPMALLOC typedef ptr IMalloc
        externdef IID_IMalloc:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IMallocVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IMallocVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IMalloc, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IMalloc
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IMalloc
            DECLSPEC_XFGVIRT(IMalloc, Alloc)
            STD_METHOD Alloc, :ptr IMalloc, :SIZE_T
            DECLSPEC_XFGVIRT(IMalloc, Realloc)
            STD_METHOD Realloc, :ptr IMalloc, :ptr, :SIZE_T
            DECLSPEC_XFGVIRT(IMalloc, Free)
            STD_METHOD Free, :ptr IMalloc, :ptr
            DECLSPEC_XFGVIRT(IMalloc, GetSize)
            STD_METHOD GetSize, :ptr IMalloc, :ptr
            DECLSPEC_XFGVIRT(IMalloc, DidAlloc)
            STD_METHOD DidAlloc, :ptr IMalloc, :ptr
            DECLSPEC_XFGVIRT(IMalloc, HeapMinimize)
            STD_METHOD HeapMinimize, :ptr IMalloc
            ??Interface equ <>
            END_INTERFACE
          IMallocVtbl ends
          IMalloc struct
            lpVtbl POINTER ?
          IMalloc ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IStdMarshalInfo_INTERFACE_DEFINED__
        __IStdMarshalInfo_INTERFACE_DEFINED__ equ <>
        LPSTDMARSHALINFO typedef ptr IStdMarshalInfo
        externdef IID_IStdMarshalInfo:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IStdMarshalInfoVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IStdMarshalInfoVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IStdMarshalInfo, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IStdMarshalInfo
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IStdMarshalInfo
            DECLSPEC_XFGVIRT(IStdMarshalInfo, GetClassForHandler)
            STD_METHOD GetClassForHandler, :ptr IStdMarshalInfo, :DWORD, :ptr, :ptr CLSID
            ??Interface equ <>
            END_INTERFACE
          IStdMarshalInfoVtbl ends
          IStdMarshalInfo struct
            lpVtbl POINTER ?
          IStdMarshalInfo ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IExternalConnection_INTERFACE_DEFINED__
        __IExternalConnection_INTERFACE_DEFINED__ equ <>
        LPEXTERNALCONNECTION typedef ptr IExternalConnection
        EXTCONN typedef SDWORD
        EXTCONN_STRONG equ 1h
        EXTCONN_WEAK equ 2h
        EXTCONN_CALLABLE equ 4h
        tagEXTCONN typedef EXTCONN

        externdef IID_IExternalConnection:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IExternalConnectionVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IExternalConnectionVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IExternalConnection, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IExternalConnection
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IExternalConnection
            DECLSPEC_XFGVIRT(IExternalConnection, AddConnection)
            STD_METHOD AddConnection, :ptr IExternalConnection, :DWORD, :DWORD
            DECLSPEC_XFGVIRT(IExternalConnection, ReleaseConnection)
            STD_METHOD ReleaseConnection, :ptr IExternalConnection, :DWORD, :DWORD, :BOOL
            ??Interface equ <>
            END_INTERFACE
          IExternalConnectionVtbl ends
          IExternalConnection struct
            lpVtbl POINTER ?
          IExternalConnection ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      LPMULTIQI typedef ptr IMultiQI
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      MULTI_QI struct
        pIID POINTER ?
        pItf POINTER ?
        hr HRESULT ?
      MULTI_QI ends
      tagMULTI_QI typedef MULTI_QI
      externdef __MIDL_itf_objidlbase_0000_0008_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_objidlbase_0000_0008_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IMultiQI_INTERFACE_DEFINED__
        __IMultiQI_INTERFACE_DEFINED__ equ <>
        externdef IID_IMultiQI:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IMultiQIVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IMultiQIVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IMultiQI, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IMultiQI
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IMultiQI
            DECLSPEC_XFGVIRT(IMultiQI, QueryMultipleInterfaces)
            STD_METHOD QueryMultipleInterfaces, :ptr IMultiQI, :ULONG, :ptr MULTI_QI
            ??Interface equ <>
            END_INTERFACE
          IMultiQIVtbl ends
          IMultiQI struct
            lpVtbl POINTER ?
          IMultiQI ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __AsyncIMultiQI_INTERFACE_DEFINED__
        __AsyncIMultiQI_INTERFACE_DEFINED__ equ <>
        externdef IID_AsyncIMultiQI:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          AsyncIMultiQIVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <AsyncIMultiQIVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr AsyncIMultiQI, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr AsyncIMultiQI
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr AsyncIMultiQI
            DECLSPEC_XFGVIRT(AsyncIMultiQI, Begin_QueryMultipleInterfaces)
            STD_METHOD Begin_QueryMultipleInterfaces, :ptr AsyncIMultiQI, :ULONG, :ptr MULTI_QI
            DECLSPEC_XFGVIRT(AsyncIMultiQI, Finish_QueryMultipleInterfaces)
            STD_METHOD Finish_QueryMultipleInterfaces, :ptr AsyncIMultiQI, :ptr MULTI_QI
            ??Interface equ <>
            END_INTERFACE
          AsyncIMultiQIVtbl ends
          AsyncIMultiQI struct
            lpVtbl POINTER ?
          AsyncIMultiQI ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      externdef __MIDL_itf_objidlbase_0000_0009_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_objidlbase_0000_0009_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IInternalUnknown_INTERFACE_DEFINED__
        __IInternalUnknown_INTERFACE_DEFINED__ equ <>
        externdef IID_IInternalUnknown:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IInternalUnknownVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IInternalUnknownVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IInternalUnknown, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IInternalUnknown
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IInternalUnknown
            DECLSPEC_XFGVIRT(IInternalUnknown, QueryInternalInterface)
            STD_METHOD QueryInternalInterface, :ptr IInternalUnknown, :REFIID, :ptr ptr
            ??Interface equ <>
            END_INTERFACE
          IInternalUnknownVtbl ends
          IInternalUnknown struct
            lpVtbl POINTER ?
          IInternalUnknown ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      externdef __MIDL_itf_objidlbase_0000_0010_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_objidlbase_0000_0010_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IEnumUnknown_INTERFACE_DEFINED__
        __IEnumUnknown_INTERFACE_DEFINED__ equ <>
        LPENUMUNKNOWN typedef ptr IEnumUnknown
        externdef IID_IEnumUnknown:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IEnumUnknownVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEnumUnknownVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IEnumUnknown, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IEnumUnknown
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IEnumUnknown
            DECLSPEC_XFGVIRT(IEnumUnknown, Next)
            STD_METHOD Next, :ptr IEnumUnknown, :ULONG, :ptr ptr IUnknown, :ptr ULONG
            DECLSPEC_XFGVIRT(IEnumUnknown, Skip)
            STD_METHOD Skip, :ptr IEnumUnknown, :ULONG
            DECLSPEC_XFGVIRT(IEnumUnknown, Reset)
            STD_METHOD Reset, :ptr IEnumUnknown
            DECLSPEC_XFGVIRT(IEnumUnknown, Clone)
            STD_METHOD Clone, :ptr IEnumUnknown, :ptr ptr IEnumUnknown
            ??Interface equ <>
            END_INTERFACE
          IEnumUnknownVtbl ends
          IEnumUnknown struct
            lpVtbl POINTER ?
          IEnumUnknown ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
        IEnumUnknown_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumUnknown, :ULONG, :ptr ptr IUnknown, :ptr ULONG
        IEnumUnknown_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      endif
      ifndef __IEnumString_INTERFACE_DEFINED__
        __IEnumString_INTERFACE_DEFINED__ equ <>
        LPENUMSTRING typedef ptr IEnumString
        externdef IID_IEnumString:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IEnumStringVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEnumStringVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IEnumString, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IEnumString
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IEnumString
            DECLSPEC_XFGVIRT(IEnumString, Next)
            STD_METHOD Next, :ptr IEnumString, :ULONG, :ptr LPOLESTR, :ptr ULONG
            DECLSPEC_XFGVIRT(IEnumString, Skip)
            STD_METHOD Skip, :ptr IEnumString, :ULONG
            DECLSPEC_XFGVIRT(IEnumString, Reset)
            STD_METHOD Reset, :ptr IEnumString
            DECLSPEC_XFGVIRT(IEnumString, Clone)
            STD_METHOD Clone, :ptr IEnumString, :ptr ptr IEnumString
            ??Interface equ <>
            END_INTERFACE
          IEnumStringVtbl ends
          IEnumString struct
            lpVtbl POINTER ?
          IEnumString ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
        IEnumString_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumString, :ULONG, :ptr LPOLESTR, :ptr ULONG
        IEnumString_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      endif
      ifndef __ISequentialStream_INTERFACE_DEFINED__
        __ISequentialStream_INTERFACE_DEFINED__ equ <>
        externdef IID_ISequentialStream:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISequentialStreamVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISequentialStreamVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISequentialStream, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISequentialStream
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISequentialStream
            DECLSPEC_XFGVIRT(ISequentialStream, Read)
            STD_METHOD Read, :ptr ISequentialStream, :ptr, :ULONG, :ptr ULONG
            DECLSPEC_XFGVIRT(ISequentialStream, Write)
            STD_METHOD Write, :ptr ISequentialStream, :ptr, :ULONG, :ptr ULONG
            ??Interface equ <>
            END_INTERFACE
          ISequentialStreamVtbl ends
          ISequentialStream struct
            lpVtbl POINTER ?
          ISequentialStream ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
        ISequentialStream_RemoteRead_Proxy proto WIN_STD_CALL_CONV :ptr ISequentialStream, :ptr byte, :ULONG, :ptr ULONG
        ISequentialStream_RemoteRead_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        ISequentialStream_RemoteWrite_Proxy proto WIN_STD_CALL_CONV :ptr ISequentialStream, :ptr byte, :ULONG, :ptr ULONG
        ISequentialStream_RemoteWrite_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      endif
      ifndef __IStream_INTERFACE_DEFINED__
        __IStream_INTERFACE_DEFINED__ equ <>
        LPSTREAM typedef ptr IStream
        STATSTG struct
          pwcsName LPOLESTR ?
          type_ DWORD ?
          cbSize ULARGE_INTEGER <>
          mtime FILETIME <>
          ctime FILETIME <>
          atime FILETIME <>
          grfMode DWORD ?
          grfLocksSupported DWORD ?
          clsid CLSID <>
          grfStateBits DWORD ?
          reserved DWORD ?
        STATSTG ends
        tagSTATSTG typedef STATSTG
        STGTY typedef SDWORD
        STGTY_STORAGE equ 1
        STGTY_STREAM equ 2
        STGTY_LOCKBYTES equ 3
        STGTY_PROPERTY equ 4
        tagSTGTY typedef STGTY

        STREAM_SEEK typedef SDWORD
        STREAM_SEEK_SET equ 0
        STREAM_SEEK_CUR equ 1
        STREAM_SEEK_END equ 2
        tagSTREAM_SEEK typedef STREAM_SEEK

        LOCKTYPE typedef SDWORD
        LOCK_WRITE equ 1
        LOCK_EXCLUSIVE equ 2
        LOCK_ONLYONCE equ 4
        tagLOCKTYPE typedef LOCKTYPE

        externdef IID_IStream:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IStreamVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IStreamVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IStream, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IStream
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IStream
            DECLSPEC_XFGVIRT(ISequentialStream, Read)
            STD_METHOD Read, :ptr IStream, :ptr, :ULONG, :ptr ULONG
            DECLSPEC_XFGVIRT(ISequentialStream, Write)
            STD_METHOD Write, :ptr IStream, :ptr, :ULONG, :ptr ULONG
            DECLSPEC_XFGVIRT(IStream, Seek)
            STD_METHOD Seek, :ptr IStream, :LARGE_INTEGER, :DWORD, :ptr ULARGE_INTEGER
            DECLSPEC_XFGVIRT(IStream, SetSize)
            STD_METHOD SetSize, :ptr IStream, :ULARGE_INTEGER
            DECLSPEC_XFGVIRT(IStream, CopyTo)
            STD_METHOD CopyTo, :ptr IStream, :ptr IStream, :ULARGE_INTEGER, :ptr ULARGE_INTEGER, :ptr ULARGE_INTEGER
            DECLSPEC_XFGVIRT(IStream, Commit)
            STD_METHOD Commit, :ptr IStream, :DWORD
            DECLSPEC_XFGVIRT(IStream, Revert)
            STD_METHOD Revert, :ptr IStream
            DECLSPEC_XFGVIRT(IStream, LockRegion)
            STD_METHOD LockRegion, :ptr IStream, :ULARGE_INTEGER, :ULARGE_INTEGER, :DWORD
            DECLSPEC_XFGVIRT(IStream, UnlockRegion)
            STD_METHOD UnlockRegion, :ptr IStream, :ULARGE_INTEGER, :ULARGE_INTEGER, :DWORD
            DECLSPEC_XFGVIRT(IStream, Stat)
            STD_METHOD Stat, :ptr IStream, :ptr STATSTG, :DWORD
            DECLSPEC_XFGVIRT(IStream, Clone)
            STD_METHOD Clone, :ptr IStream, :ptr ptr IStream
            ??Interface equ <>
            END_INTERFACE
          IStreamVtbl ends
          IStream struct
            lpVtbl POINTER ?
          IStream ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
        IStream_RemoteSeek_Proxy proto WIN_STD_CALL_CONV :ptr IStream, :LARGE_INTEGER, :DWORD, :ptr ULARGE_INTEGER
        IStream_RemoteSeek_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        IStream_RemoteCopyTo_Proxy proto WIN_STD_CALL_CONV :ptr IStream, :ptr IStream, :ULARGE_INTEGER, :ptr ULARGE_INTEGER, :ptr ULARGE_INTEGER
        IStream_RemoteCopyTo_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      endif
      ifndef __IRpcChannelBuffer_INTERFACE_DEFINED__
        __IRpcChannelBuffer_INTERFACE_DEFINED__ equ <>
        RPCOLEDATAREP typedef ULONG
        RPCOLEMESSAGE struct
          reserved1 POINTER ?
          dataRepresentation RPCOLEDATAREP ?
          Buffer POINTER ?
          cbBuffer ULONG ?
          iMethod ULONG ?
          reserved2 POINTER 5 dup (?)
          rpcFlags ULONG ?
        RPCOLEMESSAGE ends
        tagRPCOLEMESSAGE typedef RPCOLEMESSAGE
        PRPCOLEMESSAGE typedef ptr RPCOLEMESSAGE
        externdef IID_IRpcChannelBuffer:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IRpcChannelBufferVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IRpcChannelBufferVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IRpcChannelBuffer, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IRpcChannelBuffer
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IRpcChannelBuffer
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, GetBuffer)
            STD_METHOD GetBuffer, :ptr IRpcChannelBuffer, :ptr RPCOLEMESSAGE, :REFIID
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, SendReceive)
            STD_METHOD SendReceive, :ptr IRpcChannelBuffer, :ptr RPCOLEMESSAGE, :ptr ULONG
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, FreeBuffer)
            STD_METHOD FreeBuffer, :ptr IRpcChannelBuffer, :ptr RPCOLEMESSAGE
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, GetDestCtx)
            STD_METHOD GetDestCtx, :ptr IRpcChannelBuffer, :ptr DWORD, :ptr ptr
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, IsConnected)
            STD_METHOD IsConnected, :ptr IRpcChannelBuffer
            ??Interface equ <>
            END_INTERFACE
          IRpcChannelBufferVtbl ends
          IRpcChannelBuffer struct
            lpVtbl POINTER ?
          IRpcChannelBuffer ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      externdef __MIDL_itf_objidlbase_0000_0015_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_objidlbase_0000_0015_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IRpcChannelBuffer2_INTERFACE_DEFINED__
        __IRpcChannelBuffer2_INTERFACE_DEFINED__ equ <>
        externdef IID_IRpcChannelBuffer2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IRpcChannelBuffer2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IRpcChannelBuffer2Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IRpcChannelBuffer2, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IRpcChannelBuffer2
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IRpcChannelBuffer2
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, GetBuffer)
            STD_METHOD GetBuffer, :ptr IRpcChannelBuffer2, :ptr RPCOLEMESSAGE, :REFIID
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, SendReceive)
            STD_METHOD SendReceive, :ptr IRpcChannelBuffer2, :ptr RPCOLEMESSAGE, :ptr ULONG
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, FreeBuffer)
            STD_METHOD FreeBuffer, :ptr IRpcChannelBuffer2, :ptr RPCOLEMESSAGE
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, GetDestCtx)
            STD_METHOD GetDestCtx, :ptr IRpcChannelBuffer2, :ptr DWORD, :ptr ptr
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, IsConnected)
            STD_METHOD IsConnected, :ptr IRpcChannelBuffer2
            DECLSPEC_XFGVIRT(IRpcChannelBuffer2, GetProtocolVersion)
            STD_METHOD GetProtocolVersion, :ptr IRpcChannelBuffer2, :ptr DWORD
            ??Interface equ <>
            END_INTERFACE
          IRpcChannelBuffer2Vtbl ends
          IRpcChannelBuffer2 struct
            lpVtbl POINTER ?
          IRpcChannelBuffer2 ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IAsyncRpcChannelBuffer_INTERFACE_DEFINED__
        __IAsyncRpcChannelBuffer_INTERFACE_DEFINED__ equ <>
        externdef IID_IAsyncRpcChannelBuffer:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IAsyncRpcChannelBufferVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IAsyncRpcChannelBufferVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IAsyncRpcChannelBuffer, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IAsyncRpcChannelBuffer
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IAsyncRpcChannelBuffer
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, GetBuffer)
            STD_METHOD GetBuffer, :ptr IAsyncRpcChannelBuffer, :ptr RPCOLEMESSAGE, :REFIID
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, SendReceive)
            STD_METHOD SendReceive, :ptr IAsyncRpcChannelBuffer, :ptr RPCOLEMESSAGE, :ptr ULONG
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, FreeBuffer)
            STD_METHOD FreeBuffer, :ptr IAsyncRpcChannelBuffer, :ptr RPCOLEMESSAGE
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, GetDestCtx)
            STD_METHOD GetDestCtx, :ptr IAsyncRpcChannelBuffer, :ptr DWORD, :ptr ptr
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, IsConnected)
            STD_METHOD IsConnected, :ptr IAsyncRpcChannelBuffer
            DECLSPEC_XFGVIRT(IRpcChannelBuffer2, GetProtocolVersion)
            STD_METHOD GetProtocolVersion, :ptr IAsyncRpcChannelBuffer, :ptr DWORD
            DECLSPEC_XFGVIRT(IAsyncRpcChannelBuffer, Send)
            STD_METHOD Send, :ptr IAsyncRpcChannelBuffer, :ptr RPCOLEMESSAGE, :ptr ISynchronize, :ptr ULONG
            DECLSPEC_XFGVIRT(IAsyncRpcChannelBuffer, Receive)
            STD_METHOD Receive, :ptr IAsyncRpcChannelBuffer, :ptr RPCOLEMESSAGE, :ptr ULONG
            DECLSPEC_XFGVIRT(IAsyncRpcChannelBuffer, GetDestCtxEx)
            STD_METHOD GetDestCtxEx, :ptr IAsyncRpcChannelBuffer, :ptr RPCOLEMESSAGE, :ptr DWORD, :ptr ptr
            ??Interface equ <>
            END_INTERFACE
          IAsyncRpcChannelBufferVtbl ends
          IAsyncRpcChannelBuffer struct
            lpVtbl POINTER ?
          IAsyncRpcChannelBuffer ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IRpcChannelBuffer3_INTERFACE_DEFINED__
        __IRpcChannelBuffer3_INTERFACE_DEFINED__ equ <>
        externdef IID_IRpcChannelBuffer3:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IRpcChannelBuffer3Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IRpcChannelBuffer3Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IRpcChannelBuffer3, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IRpcChannelBuffer3
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IRpcChannelBuffer3
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, GetBuffer)
            STD_METHOD GetBuffer, :ptr IRpcChannelBuffer3, :ptr RPCOLEMESSAGE, :REFIID
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, SendReceive)
            STD_METHOD SendReceive, :ptr IRpcChannelBuffer3, :ptr RPCOLEMESSAGE, :ptr ULONG
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, FreeBuffer)
            STD_METHOD FreeBuffer, :ptr IRpcChannelBuffer3, :ptr RPCOLEMESSAGE
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, GetDestCtx)
            STD_METHOD GetDestCtx, :ptr IRpcChannelBuffer3, :ptr DWORD, :ptr ptr
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, IsConnected)
            STD_METHOD IsConnected, :ptr IRpcChannelBuffer3
            DECLSPEC_XFGVIRT(IRpcChannelBuffer2, GetProtocolVersion)
            STD_METHOD GetProtocolVersion, :ptr IRpcChannelBuffer3, :ptr DWORD
            DECLSPEC_XFGVIRT(IRpcChannelBuffer3, Send)
            STD_METHOD Send, :ptr IRpcChannelBuffer3, :ptr RPCOLEMESSAGE, :ptr ULONG
            DECLSPEC_XFGVIRT(IRpcChannelBuffer3, Receive)
            STD_METHOD Receive, :ptr IRpcChannelBuffer3, :ptr RPCOLEMESSAGE, :ULONG, :ptr ULONG
            DECLSPEC_XFGVIRT(IRpcChannelBuffer3, Cancel)
            STD_METHOD Cancel, :ptr IRpcChannelBuffer3, :ptr RPCOLEMESSAGE
            DECLSPEC_XFGVIRT(IRpcChannelBuffer3, GetCallContext)
            STD_METHOD GetCallContext, :ptr IRpcChannelBuffer3, :ptr RPCOLEMESSAGE, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IRpcChannelBuffer3, GetDestCtxEx)
            STD_METHOD GetDestCtxEx, :ptr IRpcChannelBuffer3, :ptr RPCOLEMESSAGE, :ptr DWORD, :ptr ptr
            DECLSPEC_XFGVIRT(IRpcChannelBuffer3, GetState)
            STD_METHOD GetState, :ptr IRpcChannelBuffer3, :ptr RPCOLEMESSAGE, :ptr DWORD
            DECLSPEC_XFGVIRT(IRpcChannelBuffer3, RegisterAsync)
            STD_METHOD RegisterAsync, :ptr IRpcChannelBuffer3, :ptr RPCOLEMESSAGE, :ptr IAsyncManager
            ??Interface equ <>
            END_INTERFACE
          IRpcChannelBuffer3Vtbl ends
          IRpcChannelBuffer3 struct
            lpVtbl POINTER ?
          IRpcChannelBuffer3 ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IRpcSyntaxNegotiate_INTERFACE_DEFINED__
        __IRpcSyntaxNegotiate_INTERFACE_DEFINED__ equ <>
        externdef IID_IRpcSyntaxNegotiate:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IRpcSyntaxNegotiateVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IRpcSyntaxNegotiateVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IRpcSyntaxNegotiate, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IRpcSyntaxNegotiate
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IRpcSyntaxNegotiate
            DECLSPEC_XFGVIRT(IRpcSyntaxNegotiate, NegotiateSyntax)
            STD_METHOD NegotiateSyntax, :ptr IRpcSyntaxNegotiate, :ptr RPCOLEMESSAGE
            ??Interface equ <>
            END_INTERFACE
          IRpcSyntaxNegotiateVtbl ends
          IRpcSyntaxNegotiate struct
            lpVtbl POINTER ?
          IRpcSyntaxNegotiate ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IRpcProxyBuffer_INTERFACE_DEFINED__
        __IRpcProxyBuffer_INTERFACE_DEFINED__ equ <>
        externdef IID_IRpcProxyBuffer:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IRpcProxyBufferVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IRpcProxyBufferVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IRpcProxyBuffer, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IRpcProxyBuffer
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IRpcProxyBuffer
            DECLSPEC_XFGVIRT(IRpcProxyBuffer, Connect)
            STD_METHOD Connect, :ptr IRpcProxyBuffer, :ptr IRpcChannelBuffer
            DECLSPEC_XFGVIRT(IRpcProxyBuffer, Disconnect)
            STD_METHOD Disconnect, :ptr IRpcProxyBuffer
            ??Interface equ <>
            END_INTERFACE
          IRpcProxyBufferVtbl ends
          IRpcProxyBuffer struct
            lpVtbl POINTER ?
          IRpcProxyBuffer ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      externdef __MIDL_itf_objidlbase_0000_0020_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_objidlbase_0000_0020_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IRpcStubBuffer_INTERFACE_DEFINED__
        __IRpcStubBuffer_INTERFACE_DEFINED__ equ <>
        externdef IID_IRpcStubBuffer:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IRpcStubBufferVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IRpcStubBufferVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IRpcStubBuffer, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IRpcStubBuffer
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IRpcStubBuffer
            DECLSPEC_XFGVIRT(IRpcStubBuffer, Connect)
            STD_METHOD Connect, :ptr IRpcStubBuffer, :ptr IUnknown
            DECLSPEC_XFGVIRT(IRpcStubBuffer, Disconnect)
            STD_METHOD Disconnect, :ptr IRpcStubBuffer
            DECLSPEC_XFGVIRT(IRpcStubBuffer, Invoke)
            STD_METHOD Invoke, :ptr IRpcStubBuffer, :ptr RPCOLEMESSAGE, :ptr IRpcChannelBuffer
            DECLSPEC_XFGVIRT(IRpcStubBuffer, IsIIDSupported)
            STD_METHOD IsIIDSupported, :ptr IRpcStubBuffer, :REFIID
            DECLSPEC_XFGVIRT(IRpcStubBuffer, CountRefs)
            STD_METHOD CountRefs, :ptr IRpcStubBuffer
            DECLSPEC_XFGVIRT(IRpcStubBuffer, DebugServerQueryInterface)
            STD_METHOD DebugServerQueryInterface, :ptr IRpcStubBuffer, :ptr ptr
            DECLSPEC_XFGVIRT(IRpcStubBuffer, DebugServerRelease)
            STD_METHOD DebugServerRelease, :ptr IRpcStubBuffer, :ptr
            ??Interface equ <>
            END_INTERFACE
          IRpcStubBufferVtbl ends
          IRpcStubBuffer struct
            lpVtbl POINTER ?
          IRpcStubBuffer ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IPSFactoryBuffer_INTERFACE_DEFINED__
        __IPSFactoryBuffer_INTERFACE_DEFINED__ equ <>
        externdef IID_IPSFactoryBuffer:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IPSFactoryBufferVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IPSFactoryBufferVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IPSFactoryBuffer, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IPSFactoryBuffer
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IPSFactoryBuffer
            DECLSPEC_XFGVIRT(IPSFactoryBuffer, CreateProxy)
            STD_METHOD CreateProxy, :ptr IPSFactoryBuffer, :ptr IUnknown, :REFIID, :ptr ptr IRpcProxyBuffer, :ptr ptr
            DECLSPEC_XFGVIRT(IPSFactoryBuffer, CreateStub)
            STD_METHOD CreateStub, :ptr IPSFactoryBuffer, :REFIID, :ptr IUnknown, :ptr ptr IRpcStubBuffer
            ??Interface equ <>
            END_INTERFACE
          IPSFactoryBufferVtbl ends
          IPSFactoryBuffer struct
            lpVtbl POINTER ?
          IPSFactoryBuffer ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      if (_WIN32_WINNT ge 0400h) or Defined(_WIN32_DCOM)
        SChannelHookCallInfo struct
          iid IID <>
          cbSize DWORD ?
          uCausality GUID <>
          dwServerPid DWORD ?
          iMethod DWORD ?
          pObject POINTER ?
        SChannelHookCallInfo ends
        externdef __MIDL_itf_objidlbase_0000_0022_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_objidlbase_0000_0022_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IChannelHook_INTERFACE_DEFINED__
          __IChannelHook_INTERFACE_DEFINED__ equ <>
          externdef IID_IChannelHook:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IChannelHookVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IChannelHookVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IChannelHook, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IChannelHook
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IChannelHook
              DECLSPEC_XFGVIRT(IChannelHook, ClientGetSize)
              STD_METHOD ClientGetSize, :ptr IChannelHook, :REFGUID, :REFIID, :ptr ULONG
              DECLSPEC_XFGVIRT(IChannelHook, ClientFillBuffer)
              STD_METHOD ClientFillBuffer, :ptr IChannelHook, :REFGUID, :REFIID, :ptr ULONG, :ptr
              DECLSPEC_XFGVIRT(IChannelHook, ClientNotify)
              STD_METHOD ClientNotify, :ptr IChannelHook, :REFGUID, :REFIID, :ULONG, :ptr, :DWORD, :HRESULT
              DECLSPEC_XFGVIRT(IChannelHook, ServerNotify)
              STD_METHOD ServerNotify, :ptr IChannelHook, :REFGUID, :REFIID, :ULONG, :ptr, :DWORD
              DECLSPEC_XFGVIRT(IChannelHook, ServerGetSize)
              STD_METHOD ServerGetSize, :ptr IChannelHook, :REFGUID, :REFIID, :HRESULT, :ptr ULONG
              DECLSPEC_XFGVIRT(IChannelHook, ServerFillBuffer)
              STD_METHOD ServerFillBuffer, :ptr IChannelHook, :REFGUID, :REFIID, :ptr ULONG, :ptr, :HRESULT
              ??Interface equ <>
              END_INTERFACE
            IChannelHookVtbl ends
            IChannelHook struct
              lpVtbl POINTER ?
            IChannelHook ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
      endif
    endif
    if (_WIN32_WINNT ge 0400h) or Defined(_WIN32_DCOM)
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
        externdef __MIDL_itf_objidlbase_0000_0023_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_objidlbase_0000_0023_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IClientSecurity_INTERFACE_DEFINED__
          __IClientSecurity_INTERFACE_DEFINED__ equ <>
          SOLE_AUTHENTICATION_SERVICE struct
            dwAuthnSvc DWORD ?
            dwAuthzSvc DWORD ?
            pPrincipalName POINTER ?
            hr HRESULT ?
          SOLE_AUTHENTICATION_SERVICE ends
          tagSOLE_AUTHENTICATION_SERVICE typedef SOLE_AUTHENTICATION_SERVICE
          PSOLE_AUTHENTICATION_SERVICE typedef ptr SOLE_AUTHENTICATION_SERVICE
          EOLE_AUTHENTICATION_CAPABILITIES typedef SDWORD
          EOAC_NONE equ 0
          EOAC_MUTUAL_AUTH equ 1h
          EOAC_STATIC_CLOAKING equ 20h
          EOAC_DYNAMIC_CLOAKING equ 40h
          EOAC_ANY_AUTHORITY equ 80h
          EOAC_MAKE_FULLSIC equ 100h
          EOAC_DEFAULT equ 800h
          EOAC_SECURE_REFS equ 2h
          EOAC_ACCESS_CONTROL equ 4h
          EOAC_APPID equ 8h
          EOAC_DYNAMIC equ 10h
          EOAC_REQUIRE_FULLSIC equ 200h
          EOAC_AUTO_IMPERSONATE equ 400h
          EOAC_DISABLE_AAA equ 1000h
          EOAC_NO_CUSTOM_MARSHAL equ 2000h
          EOAC_RESERVED1 equ 4000h
          tagEOLE_AUTHENTICATION_CAPABILITIES typedef EOLE_AUTHENTICATION_CAPABILITIES

          COLE_DEFAULT_PRINCIPAL equ (- 1)
          COLE_DEFAULT_AUTHINFO equ (- 1)
          SOLE_AUTHENTICATION_INFO struct
            dwAuthnSvc DWORD ?
            dwAuthzSvc DWORD ?
            pAuthInfo POINTER ?
          SOLE_AUTHENTICATION_INFO ends
          tagSOLE_AUTHENTICATION_INFO typedef SOLE_AUTHENTICATION_INFO
          PSOLE_AUTHENTICATION_INFO typedef ptr tagSOLE_AUTHENTICATION_INFO
          SOLE_AUTHENTICATION_LIST struct
            cAuthInfo DWORD ?
            aAuthInfo POINTER ?
          SOLE_AUTHENTICATION_LIST ends
          tagSOLE_AUTHENTICATION_LIST typedef SOLE_AUTHENTICATION_LIST
          PSOLE_AUTHENTICATION_LIST typedef ptr tagSOLE_AUTHENTICATION_LIST
          externdef IID_IClientSecurity:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IClientSecurityVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IClientSecurityVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IClientSecurity, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IClientSecurity
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IClientSecurity
              DECLSPEC_XFGVIRT(IClientSecurity, QueryBlanket)
              STD_METHOD QueryBlanket, :ptr IClientSecurity, :ptr IUnknown, :ptr DWORD, :ptr DWORD, :ptr ptr OLECHAR, :ptr DWORD, :ptr DWORD, :ptr ptr, :ptr DWORD
              DECLSPEC_XFGVIRT(IClientSecurity, SetBlanket)
              STD_METHOD SetBlanket, :ptr IClientSecurity, :ptr IUnknown, :DWORD, :DWORD, :ptr OLECHAR, :DWORD, :DWORD, :ptr, :DWORD
              DECLSPEC_XFGVIRT(IClientSecurity, CopyProxy)
              STD_METHOD CopyProxy, :ptr IClientSecurity, :ptr IUnknown, :ptr ptr IUnknown
              ??Interface equ <>
              END_INTERFACE
            IClientSecurityVtbl ends
            IClientSecurity struct
              lpVtbl POINTER ?
            IClientSecurity ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
        externdef __MIDL_itf_objidlbase_0000_0024_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_objidlbase_0000_0024_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IServerSecurity_INTERFACE_DEFINED__
          __IServerSecurity_INTERFACE_DEFINED__ equ <>
          externdef IID_IServerSecurity:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IServerSecurityVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IServerSecurityVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IServerSecurity, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IServerSecurity
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IServerSecurity
              DECLSPEC_XFGVIRT(IServerSecurity, QueryBlanket)
              STD_METHOD QueryBlanket, :ptr IServerSecurity, :ptr DWORD, :ptr DWORD, :ptr ptr OLECHAR, :ptr DWORD, :ptr DWORD, :ptr ptr, :ptr DWORD
              DECLSPEC_XFGVIRT(IServerSecurity, ImpersonateClient)
              STD_METHOD ImpersonateClient, :ptr IServerSecurity
              DECLSPEC_XFGVIRT(IServerSecurity, RevertToSelf)
              STD_METHOD RevertToSelf, :ptr IServerSecurity
              DECLSPEC_XFGVIRT(IServerSecurity, IsImpersonating)
              STD_METHOD IsImpersonating, :ptr IServerSecurity
              ??Interface equ <>
              END_INTERFACE
            IServerSecurityVtbl ends
            IServerSecurity struct
              lpVtbl POINTER ?
            IServerSecurity ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
        RPCOPT_PROPERTIES typedef SDWORD
        COMBND_RPCTIMEOUT equ 1h
        COMBND_SERVER_LOCALITY equ 2h
        COMBND_RESERVED1 equ 4h
        COMBND_RESERVED2 equ 5h
        COMBND_RESERVED3 equ 8h
        COMBND_RESERVED4 equ 10h
        tagRPCOPT_PROPERTIES typedef RPCOPT_PROPERTIES

        RPCOPT_SERVER_LOCALITY_VALUES typedef SDWORD
        SERVER_LOCALITY_PROCESS_LOCAL equ 0
        SERVER_LOCALITY_MACHINE_LOCAL equ 1
        SERVER_LOCALITY_REMOTE equ 2
        tagRPCOPT_SERVER_LOCALITY_VALUES typedef RPCOPT_SERVER_LOCALITY_VALUES

        externdef __MIDL_itf_objidlbase_0000_0025_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_objidlbase_0000_0025_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IRpcOptions_INTERFACE_DEFINED__
          __IRpcOptions_INTERFACE_DEFINED__ equ <>
          externdef IID_IRpcOptions:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IRpcOptionsVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IRpcOptionsVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IRpcOptions, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IRpcOptions
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IRpcOptions
              DECLSPEC_XFGVIRT(IRpcOptions, Set)
              STD_METHOD Set, :ptr IRpcOptions, :ptr IUnknown, :RPCOPT_PROPERTIES, :ULONG_PTR
              DECLSPEC_XFGVIRT(IRpcOptions, Query)
              STD_METHOD Query, :ptr IRpcOptions, :ptr IUnknown, :RPCOPT_PROPERTIES, :ptr ULONG_PTR
              ??Interface equ <>
              END_INTERFACE
            IRpcOptionsVtbl ends
            IRpcOptions struct
              lpVtbl POINTER ?
            IRpcOptions ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
        GLOBALOPT_PROPERTIES typedef SDWORD
        COMGLB_EXCEPTION_HANDLING equ 1
        COMGLB_APPID equ 2
        COMGLB_RPC_THREADPOOL_SETTING equ 3
        COMGLB_RO_SETTINGS equ 4
        COMGLB_UNMARSHALING_POLICY equ 5
        COMGLB_PROPERTIES_RESERVED1 equ 6
        COMGLB_PROPERTIES_RESERVED2 equ 7
        COMGLB_PROPERTIES_RESERVED3 equ 8
        tagGLOBALOPT_PROPERTIES typedef GLOBALOPT_PROPERTIES

        GLOBALOPT_EH_VALUES typedef SDWORD
        COMGLB_EXCEPTION_HANDLE equ 0
        COMGLB_EXCEPTION_DONOT_HANDLE_FATAL equ 1
        COMGLB_EXCEPTION_DONOT_HANDLE equ COMGLB_EXCEPTION_DONOT_HANDLE_FATAL
        COMGLB_EXCEPTION_DONOT_HANDLE_ANY equ 2
        tagGLOBALOPT_EH_VALUES typedef GLOBALOPT_EH_VALUES

        GLOBALOPT_RPCTP_VALUES typedef SDWORD
        COMGLB_RPC_THREADPOOL_SETTING_DEFAULT_POOL equ 0
        COMGLB_RPC_THREADPOOL_SETTING_PRIVATE_POOL equ 1
        tagGLOBALOPT_RPCTP_VALUES typedef GLOBALOPT_RPCTP_VALUES

        GLOBALOPT_RO_FLAGS typedef SDWORD
        COMGLB_STA_MODALLOOP_REMOVE_TOUCH_MESSAGES equ 1h
        COMGLB_STA_MODALLOOP_SHARED_QUEUE_REMOVE_INPUT_MESSAGES equ 2h
        COMGLB_STA_MODALLOOP_SHARED_QUEUE_DONOT_REMOVE_INPUT_MESSAGES equ 4h
        COMGLB_FAST_RUNDOWN equ 8h
        COMGLB_RESERVED1 equ 10h
        COMGLB_RESERVED2 equ 20h
        COMGLB_RESERVED3 equ 40h
        COMGLB_STA_MODALLOOP_SHARED_QUEUE_REORDER_POINTER_MESSAGES equ 80h
        COMGLB_RESERVED4 equ 100h
        COMGLB_RESERVED5 equ 200h
        COMGLB_RESERVED6 equ 400h
        tagGLOBALOPT_RO_FLAGS typedef GLOBALOPT_RO_FLAGS

        GLOBALOPT_UNMARSHALING_POLICY_VALUES typedef SDWORD
        COMGLB_UNMARSHALING_POLICY_NORMAL equ 0
        COMGLB_UNMARSHALING_POLICY_STRONG equ 1
        COMGLB_UNMARSHALING_POLICY_HYBRID equ 2
        tagGLOBALOPT_UNMARSHALING_POLICY_VALUES typedef GLOBALOPT_UNMARSHALING_POLICY_VALUES

        externdef __MIDL_itf_objidlbase_0000_0026_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_objidlbase_0000_0026_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IGlobalOptions_INTERFACE_DEFINED__
          __IGlobalOptions_INTERFACE_DEFINED__ equ <>
          externdef IID_IGlobalOptions:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IGlobalOptionsVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IGlobalOptionsVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IGlobalOptions, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IGlobalOptions
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IGlobalOptions
              DECLSPEC_XFGVIRT(IGlobalOptions, Set)
              STD_METHOD Set, :ptr IGlobalOptions, :GLOBALOPT_PROPERTIES, :ULONG_PTR
              DECLSPEC_XFGVIRT(IGlobalOptions, Query)
              STD_METHOD Query, :ptr IGlobalOptions, :GLOBALOPT_PROPERTIES, :ptr ULONG_PTR
              ??Interface equ <>
              END_INTERFACE
            IGlobalOptionsVtbl ends
            IGlobalOptions struct
              lpVtbl POINTER ?
            IGlobalOptions ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      externdef __MIDL_itf_objidlbase_0000_0027_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_objidlbase_0000_0027_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ISurrogate_INTERFACE_DEFINED__
        __ISurrogate_INTERFACE_DEFINED__ equ <>
        LPSURROGATE typedef ptr ISurrogate
        externdef IID_ISurrogate:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISurrogateVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISurrogateVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISurrogate, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISurrogate
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISurrogate
            DECLSPEC_XFGVIRT(ISurrogate, LoadDllServer)
            STD_METHOD LoadDllServer, :ptr ISurrogate, :REFCLSID
            DECLSPEC_XFGVIRT(ISurrogate, FreeSurrogate)
            STD_METHOD FreeSurrogate, :ptr ISurrogate
            ??Interface equ <>
            END_INTERFACE
          ISurrogateVtbl ends
          ISurrogate struct
            lpVtbl POINTER ?
          ISurrogate ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IGlobalInterfaceTable_INTERFACE_DEFINED__
        __IGlobalInterfaceTable_INTERFACE_DEFINED__ equ <>
        LPGLOBALINTERFACETABLE typedef ptr IGlobalInterfaceTable
        externdef IID_IGlobalInterfaceTable:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IGlobalInterfaceTableVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IGlobalInterfaceTableVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IGlobalInterfaceTable, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IGlobalInterfaceTable
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IGlobalInterfaceTable
            DECLSPEC_XFGVIRT(IGlobalInterfaceTable, RegisterInterfaceInGlobal)
            STD_METHOD RegisterInterfaceInGlobal, :ptr IGlobalInterfaceTable, :ptr IUnknown, :REFIID, :ptr DWORD
            DECLSPEC_XFGVIRT(IGlobalInterfaceTable, RevokeInterfaceFromGlobal)
            STD_METHOD RevokeInterfaceFromGlobal, :ptr IGlobalInterfaceTable, :DWORD
            DECLSPEC_XFGVIRT(IGlobalInterfaceTable, GetInterfaceFromGlobal)
            STD_METHOD GetInterfaceFromGlobal, :ptr IGlobalInterfaceTable, :DWORD, :REFIID, :ptr ptr
            ??Interface equ <>
            END_INTERFACE
          IGlobalInterfaceTableVtbl ends
          IGlobalInterfaceTable struct
            lpVtbl POINTER ?
          IGlobalInterfaceTable ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      externdef __MIDL_itf_objidlbase_0000_0029_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_objidlbase_0000_0029_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ISynchronize_INTERFACE_DEFINED__
        __ISynchronize_INTERFACE_DEFINED__ equ <>
        externdef IID_ISynchronize:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISynchronizeVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISynchronizeVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISynchronize, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISynchronize
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISynchronize
            DECLSPEC_XFGVIRT(ISynchronize, Wait)
            STD_METHOD Wait_, :ptr ISynchronize, :DWORD, :DWORD
            DECLSPEC_XFGVIRT(ISynchronize, Signal)
            STD_METHOD Signal, :ptr ISynchronize
            DECLSPEC_XFGVIRT(ISynchronize, Reset)
            STD_METHOD Reset, :ptr ISynchronize
            ??Interface equ <>
            END_INTERFACE
          ISynchronizeVtbl ends
          ISynchronize struct
            lpVtbl POINTER ?
          ISynchronize ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __ISynchronizeHandle_INTERFACE_DEFINED__
        __ISynchronizeHandle_INTERFACE_DEFINED__ equ <>
        externdef IID_ISynchronizeHandle:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISynchronizeHandleVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISynchronizeHandleVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISynchronizeHandle, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISynchronizeHandle
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISynchronizeHandle
            DECLSPEC_XFGVIRT(ISynchronizeHandle, GetHandle)
            STD_METHOD GetHandle, :ptr ISynchronizeHandle, :ptr HANDLE
            ??Interface equ <>
            END_INTERFACE
          ISynchronizeHandleVtbl ends
          ISynchronizeHandle struct
            lpVtbl POINTER ?
          ISynchronizeHandle ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __ISynchronizeEvent_INTERFACE_DEFINED__
        __ISynchronizeEvent_INTERFACE_DEFINED__ equ <>
        externdef IID_ISynchronizeEvent:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISynchronizeEventVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISynchronizeEventVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISynchronizeEvent, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISynchronizeEvent
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISynchronizeEvent
            DECLSPEC_XFGVIRT(ISynchronizeHandle, GetHandle)
            STD_METHOD GetHandle, :ptr ISynchronizeEvent, :ptr HANDLE
            DECLSPEC_XFGVIRT(ISynchronizeEvent, SetEventHandle)
            STD_METHOD SetEventHandle, :ptr ISynchronizeEvent, :ptr HANDLE
            ??Interface equ <>
            END_INTERFACE
          ISynchronizeEventVtbl ends
          ISynchronizeEvent struct
            lpVtbl POINTER ?
          ISynchronizeEvent ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __ISynchronizeContainer_INTERFACE_DEFINED__
        __ISynchronizeContainer_INTERFACE_DEFINED__ equ <>
        externdef IID_ISynchronizeContainer:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISynchronizeContainerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISynchronizeContainerVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISynchronizeContainer, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISynchronizeContainer
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISynchronizeContainer
            DECLSPEC_XFGVIRT(ISynchronizeContainer, AddSynchronize)
            STD_METHOD AddSynchronize, :ptr ISynchronizeContainer, :ptr ISynchronize
            DECLSPEC_XFGVIRT(ISynchronizeContainer, WaitMultiple)
            STD_METHOD WaitMultiple, :ptr ISynchronizeContainer, :DWORD, :DWORD, :ptr ptr ISynchronize
            ??Interface equ <>
            END_INTERFACE
          ISynchronizeContainerVtbl ends
          ISynchronizeContainer struct
            lpVtbl POINTER ?
          ISynchronizeContainer ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __ISynchronizeMutex_INTERFACE_DEFINED__
        __ISynchronizeMutex_INTERFACE_DEFINED__ equ <>
        externdef IID_ISynchronizeMutex:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISynchronizeMutexVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISynchronizeMutexVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISynchronizeMutex, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISynchronizeMutex
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISynchronizeMutex
            DECLSPEC_XFGVIRT(ISynchronize, Wait)
            STD_METHOD Wait_, :ptr ISynchronizeMutex, :DWORD, :DWORD
            DECLSPEC_XFGVIRT(ISynchronize, Signal)
            STD_METHOD Signal, :ptr ISynchronizeMutex
            DECLSPEC_XFGVIRT(ISynchronize, Reset)
            STD_METHOD Reset, :ptr ISynchronizeMutex
            DECLSPEC_XFGVIRT(ISynchronizeMutex, ReleaseMutex)
            STD_METHOD ReleaseMutex, :ptr ISynchronizeMutex
            ??Interface equ <>
            END_INTERFACE
          ISynchronizeMutexVtbl ends
          ISynchronizeMutex struct
            lpVtbl POINTER ?
          ISynchronizeMutex ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __ICancelMethodCalls_INTERFACE_DEFINED__
        __ICancelMethodCalls_INTERFACE_DEFINED__ equ <>
        LPCANCELMETHODCALLS typedef ptr ICancelMethodCalls
        externdef IID_ICancelMethodCalls:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ICancelMethodCallsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ICancelMethodCallsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ICancelMethodCalls, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ICancelMethodCalls
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ICancelMethodCalls
            DECLSPEC_XFGVIRT(ICancelMethodCalls, Cancel)
            STD_METHOD Cancel, :ptr ICancelMethodCalls, :ULONG
            DECLSPEC_XFGVIRT(ICancelMethodCalls, TestCancel)
            STD_METHOD TestCancel, :ptr ICancelMethodCalls
            ??Interface equ <>
            END_INTERFACE
          ICancelMethodCallsVtbl ends
          ICancelMethodCalls struct
            lpVtbl POINTER ?
          ICancelMethodCalls ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IAsyncManager_INTERFACE_DEFINED__
        __IAsyncManager_INTERFACE_DEFINED__ equ <>
        DCOM_CALL_STATE typedef SDWORD
        DCOM_NONE equ 0
        DCOM_CALL_COMPLETE equ 1h
        DCOM_CALL_CANCELED equ 2h
        tagDCOM_CALL_STATE typedef DCOM_CALL_STATE

        externdef IID_IAsyncManager:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IAsyncManagerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IAsyncManagerVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IAsyncManager, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IAsyncManager
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IAsyncManager
            DECLSPEC_XFGVIRT(IAsyncManager, CompleteCall)
            STD_METHOD CompleteCall, :ptr IAsyncManager, :HRESULT
            DECLSPEC_XFGVIRT(IAsyncManager, GetCallContext)
            STD_METHOD GetCallContext, :ptr IAsyncManager, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IAsyncManager, GetState)
            STD_METHOD GetState, :ptr IAsyncManager, :ptr ULONG
            ??Interface equ <>
            END_INTERFACE
          IAsyncManagerVtbl ends
          IAsyncManager struct
            lpVtbl POINTER ?
          IAsyncManager ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __ICallFactory_INTERFACE_DEFINED__
        __ICallFactory_INTERFACE_DEFINED__ equ <>
        externdef IID_ICallFactory:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ICallFactoryVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ICallFactoryVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ICallFactory, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ICallFactory
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ICallFactory
            DECLSPEC_XFGVIRT(ICallFactory, CreateCall)
            STD_METHOD CreateCall, :ptr ICallFactory, :REFIID, :ptr IUnknown, :REFIID, :ptr ptr IUnknown
            ??Interface equ <>
            END_INTERFACE
          ICallFactoryVtbl ends
          ICallFactory struct
            lpVtbl POINTER ?
          ICallFactory ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IRpcHelper_INTERFACE_DEFINED__
        __IRpcHelper_INTERFACE_DEFINED__ equ <>
        externdef IID_IRpcHelper:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IRpcHelperVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IRpcHelperVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IRpcHelper, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IRpcHelper
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IRpcHelper
            DECLSPEC_XFGVIRT(IRpcHelper, GetDCOMProtocolVersion)
            STD_METHOD GetDCOMProtocolVersion, :ptr IRpcHelper, :ptr DWORD
            DECLSPEC_XFGVIRT(IRpcHelper, GetIIDFromOBJREF)
            STD_METHOD GetIIDFromOBJREF, :ptr IRpcHelper, :ptr, :ptr ptr IID
            ??Interface equ <>
            END_INTERFACE
          IRpcHelperVtbl ends
          IRpcHelper struct
            lpVtbl POINTER ?
          IRpcHelper ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IReleaseMarshalBuffers_INTERFACE_DEFINED__
        __IReleaseMarshalBuffers_INTERFACE_DEFINED__ equ <>
        externdef IID_IReleaseMarshalBuffers:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IReleaseMarshalBuffersVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IReleaseMarshalBuffersVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IReleaseMarshalBuffers, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IReleaseMarshalBuffers
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IReleaseMarshalBuffers
            DECLSPEC_XFGVIRT(IReleaseMarshalBuffers, ReleaseMarshalBuffer)
            STD_METHOD ReleaseMarshalBuffer, :ptr IReleaseMarshalBuffers, :ptr RPCOLEMESSAGE, :DWORD, :ptr IUnknown
            ??Interface equ <>
            END_INTERFACE
          IReleaseMarshalBuffersVtbl ends
          IReleaseMarshalBuffers struct
            lpVtbl POINTER ?
          IReleaseMarshalBuffers ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IWaitMultiple_INTERFACE_DEFINED__
        __IWaitMultiple_INTERFACE_DEFINED__ equ <>
        externdef IID_IWaitMultiple:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IWaitMultipleVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IWaitMultipleVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IWaitMultiple, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IWaitMultiple
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IWaitMultiple
            DECLSPEC_XFGVIRT(IWaitMultiple, WaitMultiple)
            STD_METHOD WaitMultiple, :ptr IWaitMultiple, :DWORD, :ptr ptr ISynchronize
            DECLSPEC_XFGVIRT(IWaitMultiple, AddSynchronize)
            STD_METHOD AddSynchronize, :ptr IWaitMultiple, :ptr ISynchronize
            ??Interface equ <>
            END_INTERFACE
          IWaitMultipleVtbl ends
          IWaitMultiple struct
            lpVtbl POINTER ?
          IWaitMultiple ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IAddrTrackingControl_INTERFACE_DEFINED__
        __IAddrTrackingControl_INTERFACE_DEFINED__ equ <>
        LPADDRTRACKINGCONTROL typedef ptr IAddrTrackingControl
        externdef IID_IAddrTrackingControl:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IAddrTrackingControlVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IAddrTrackingControlVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IAddrTrackingControl, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IAddrTrackingControl
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IAddrTrackingControl
            DECLSPEC_XFGVIRT(IAddrTrackingControl, EnableCOMDynamicAddrTracking)
            STD_METHOD EnableCOMDynamicAddrTracking, :ptr IAddrTrackingControl
            DECLSPEC_XFGVIRT(IAddrTrackingControl, DisableCOMDynamicAddrTracking)
            STD_METHOD DisableCOMDynamicAddrTracking, :ptr IAddrTrackingControl
            ??Interface equ <>
            END_INTERFACE
          IAddrTrackingControlVtbl ends
          IAddrTrackingControl struct
            lpVtbl POINTER ?
          IAddrTrackingControl ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IAddrExclusionControl_INTERFACE_DEFINED__
        __IAddrExclusionControl_INTERFACE_DEFINED__ equ <>
        LPADDREXCLUSIONCONTROL typedef ptr IAddrExclusionControl
        externdef IID_IAddrExclusionControl:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IAddrExclusionControlVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IAddrExclusionControlVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IAddrExclusionControl, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IAddrExclusionControl
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IAddrExclusionControl
            DECLSPEC_XFGVIRT(IAddrExclusionControl, GetCurrentAddrExclusionList)
            STD_METHOD GetCurrentAddrExclusionList, :ptr IAddrExclusionControl, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IAddrExclusionControl, UpdateAddrExclusionList)
            STD_METHOD UpdateAddrExclusionList, :ptr IAddrExclusionControl, :ptr IUnknown
            ??Interface equ <>
            END_INTERFACE
          IAddrExclusionControlVtbl ends
          IAddrExclusionControl struct
            lpVtbl POINTER ?
          IAddrExclusionControl ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IPipeByte_INTERFACE_DEFINED__
        __IPipeByte_INTERFACE_DEFINED__ equ <>
        externdef IID_IPipeByte:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IPipeByteVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IPipeByteVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IPipeByte, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IPipeByte
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IPipeByte
            DECLSPEC_XFGVIRT(IPipeByte, Pull)
            STD_METHOD Pull, :ptr IPipeByte, :ptr BYTE, :ULONG, :ptr ULONG
            DECLSPEC_XFGVIRT(IPipeByte, Push)
            STD_METHOD Push_, :ptr IPipeByte, :ptr BYTE, :ULONG
            ??Interface equ <>
            END_INTERFACE
          IPipeByteVtbl ends
          IPipeByte struct
            lpVtbl POINTER ?
          IPipeByte ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __AsyncIPipeByte_INTERFACE_DEFINED__
        __AsyncIPipeByte_INTERFACE_DEFINED__ equ <>
        externdef IID_AsyncIPipeByte:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          AsyncIPipeByteVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <AsyncIPipeByteVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr AsyncIPipeByte, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr AsyncIPipeByte
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr AsyncIPipeByte
            DECLSPEC_XFGVIRT(AsyncIPipeByte, Begin_Pull)
            STD_METHOD Begin_Pull, :ptr AsyncIPipeByte, :ULONG
            DECLSPEC_XFGVIRT(AsyncIPipeByte, Finish_Pull)
            STD_METHOD Finish_Pull, :ptr AsyncIPipeByte, :ptr BYTE, :ptr ULONG
            DECLSPEC_XFGVIRT(AsyncIPipeByte, Begin_Push)
            STD_METHOD Begin_Push, :ptr AsyncIPipeByte, :ptr BYTE, :ULONG
            DECLSPEC_XFGVIRT(AsyncIPipeByte, Finish_Push)
            STD_METHOD Finish_Push, :ptr AsyncIPipeByte
            ??Interface equ <>
            END_INTERFACE
          AsyncIPipeByteVtbl ends
          AsyncIPipeByte struct
            lpVtbl POINTER ?
          AsyncIPipeByte ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IPipeLong_INTERFACE_DEFINED__
        __IPipeLong_INTERFACE_DEFINED__ equ <>
        externdef IID_IPipeLong:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IPipeLongVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IPipeLongVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IPipeLong, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IPipeLong
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IPipeLong
            DECLSPEC_XFGVIRT(IPipeLong, Pull)
            STD_METHOD Pull, :ptr IPipeLong, :ptr LONG, :ULONG, :ptr ULONG
            DECLSPEC_XFGVIRT(IPipeLong, Push)
            STD_METHOD Push_, :ptr IPipeLong, :ptr LONG, :ULONG
            ??Interface equ <>
            END_INTERFACE
          IPipeLongVtbl ends
          IPipeLong struct
            lpVtbl POINTER ?
          IPipeLong ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __AsyncIPipeLong_INTERFACE_DEFINED__
        __AsyncIPipeLong_INTERFACE_DEFINED__ equ <>
        externdef IID_AsyncIPipeLong:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          AsyncIPipeLongVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <AsyncIPipeLongVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr AsyncIPipeLong, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr AsyncIPipeLong
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr AsyncIPipeLong
            DECLSPEC_XFGVIRT(AsyncIPipeLong, Begin_Pull)
            STD_METHOD Begin_Pull, :ptr AsyncIPipeLong, :ULONG
            DECLSPEC_XFGVIRT(AsyncIPipeLong, Finish_Pull)
            STD_METHOD Finish_Pull, :ptr AsyncIPipeLong, :ptr LONG, :ptr ULONG
            DECLSPEC_XFGVIRT(AsyncIPipeLong, Begin_Push)
            STD_METHOD Begin_Push, :ptr AsyncIPipeLong, :ptr LONG, :ULONG
            DECLSPEC_XFGVIRT(AsyncIPipeLong, Finish_Push)
            STD_METHOD Finish_Push, :ptr AsyncIPipeLong
            ??Interface equ <>
            END_INTERFACE
          AsyncIPipeLongVtbl ends
          AsyncIPipeLong struct
            lpVtbl POINTER ?
          AsyncIPipeLong ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IPipeDouble_INTERFACE_DEFINED__
        __IPipeDouble_INTERFACE_DEFINED__ equ <>
        externdef IID_IPipeDouble:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IPipeDoubleVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IPipeDoubleVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IPipeDouble, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IPipeDouble
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IPipeDouble
            DECLSPEC_XFGVIRT(IPipeDouble, Pull)
            STD_METHOD Pull, :ptr IPipeDouble, :ptr DOUBLE, :ULONG, :ptr ULONG
            DECLSPEC_XFGVIRT(IPipeDouble, Push)
            STD_METHOD Push_, :ptr IPipeDouble, :ptr DOUBLE, :ULONG
            ??Interface equ <>
            END_INTERFACE
          IPipeDoubleVtbl ends
          IPipeDouble struct
            lpVtbl POINTER ?
          IPipeDouble ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __AsyncIPipeDouble_INTERFACE_DEFINED__
        __AsyncIPipeDouble_INTERFACE_DEFINED__ equ <>
        externdef IID_AsyncIPipeDouble:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          AsyncIPipeDoubleVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <AsyncIPipeDoubleVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr AsyncIPipeDouble, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr AsyncIPipeDouble
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr AsyncIPipeDouble
            DECLSPEC_XFGVIRT(AsyncIPipeDouble, Begin_Pull)
            STD_METHOD Begin_Pull, :ptr AsyncIPipeDouble, :ULONG
            DECLSPEC_XFGVIRT(AsyncIPipeDouble, Finish_Pull)
            STD_METHOD Finish_Pull, :ptr AsyncIPipeDouble, :ptr DOUBLE, :ptr ULONG
            DECLSPEC_XFGVIRT(AsyncIPipeDouble, Begin_Push)
            STD_METHOD Begin_Push, :ptr AsyncIPipeDouble, :ptr DOUBLE, :ULONG
            DECLSPEC_XFGVIRT(AsyncIPipeDouble, Finish_Push)
            STD_METHOD Finish_Push, :ptr AsyncIPipeDouble
            ??Interface equ <>
            END_INTERFACE
          AsyncIPipeDoubleVtbl ends
          AsyncIPipeDouble struct
            lpVtbl POINTER ?
          AsyncIPipeDouble ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      if Defined(USE_COM_CONTEXT_DEF) or Defined(BUILDTYPE_COMSVCS) or Defined(_COMBASEAPI_) or Defined(_OLE32_)
        CPFLAGS typedef DWORD
        ContextProperty struct
          policyId GUID <>
          flags CPFLAGS ?
          pUnk POINTER ?
        ContextProperty ends
        tagContextProperty typedef ContextProperty
        externdef __MIDL_itf_objidlbase_0000_0045_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_objidlbase_0000_0045_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IEnumContextProps_INTERFACE_DEFINED__
          __IEnumContextProps_INTERFACE_DEFINED__ equ <>
          LPENUMCONTEXTPROPS typedef ptr IEnumContextProps
          externdef IID_IEnumContextProps:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IEnumContextPropsVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IEnumContextPropsVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IEnumContextProps, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IEnumContextProps
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IEnumContextProps
              DECLSPEC_XFGVIRT(IEnumContextProps, Next)
              STD_METHOD Next, :ptr IEnumContextProps, :ULONG, :ptr ContextProperty, :ptr ULONG
              DECLSPEC_XFGVIRT(IEnumContextProps, Skip)
              STD_METHOD Skip, :ptr IEnumContextProps, :ULONG
              DECLSPEC_XFGVIRT(IEnumContextProps, Reset)
              STD_METHOD Reset, :ptr IEnumContextProps
              DECLSPEC_XFGVIRT(IEnumContextProps, Clone)
              STD_METHOD Clone, :ptr IEnumContextProps, :ptr ptr IEnumContextProps
              DECLSPEC_XFGVIRT(IEnumContextProps, Count)
              STD_METHOD Count, :ptr IEnumContextProps, :ptr ULONG
              ??Interface equ <>
              END_INTERFACE
            IEnumContextPropsVtbl ends
            IEnumContextProps struct
              lpVtbl POINTER ?
            IEnumContextProps ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
        ifndef __IContext_INTERFACE_DEFINED__
          __IContext_INTERFACE_DEFINED__ equ <>
          externdef IID_IContext:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IContextVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IContextVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IContext, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IContext
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IContext
              DECLSPEC_XFGVIRT(IContext, SetProperty)
              STD_METHOD SetProperty, :ptr IContext, :REFGUID, :CPFLAGS, :ptr IUnknown
              DECLSPEC_XFGVIRT(IContext, RemoveProperty)
              STD_METHOD RemoveProperty, :ptr IContext, :REFGUID
              DECLSPEC_XFGVIRT(IContext, GetProperty)
              STD_METHOD GetProperty, :ptr IContext, :REFGUID, :ptr CPFLAGS, :ptr ptr IUnknown
              DECLSPEC_XFGVIRT(IContext, EnumContextProps)
              STD_METHOD EnumContextProps, :ptr IContext, :ptr ptr IEnumContextProps
              ??Interface equ <>
              END_INTERFACE
            IContextVtbl ends
            IContext struct
              lpVtbl POINTER ?
            IContext ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
        if  not Defined(BUILDTYPE_COMSVCS) and  not (Defined(_COMBASEAPI_) or Defined(_OLE32_))
          externdef __MIDL_itf_objidlbase_0000_0047_v0_0_c_ifspec:RPC_IF_HANDLE
          externdef __MIDL_itf_objidlbase_0000_0047_v0_0_s_ifspec:RPC_IF_HANDLE
          ifndef __IObjContext_INTERFACE_DEFINED__
            __IObjContext_INTERFACE_DEFINED__ equ <>
            externdef IID_IObjContext:IID
            if Defined(__cplusplus) and  not Defined(CINTERFACE)
              ;[...]
            else
              IObjContextVtbl struct
                BEGIN_INTERFACE
                ??Interface equ <IObjContextVtbl>
                DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
                STD_METHOD QueryInterface, :ptr IObjContext, :REFIID, :ptr ptr
                DECLSPEC_XFGVIRT(IUnknown, AddRef)
                STD_METHOD AddRef, :ptr IObjContext
                DECLSPEC_XFGVIRT(IUnknown, Release)
                STD_METHOD Release, :ptr IObjContext
                DECLSPEC_XFGVIRT(IContext, SetProperty)
                STD_METHOD SetProperty, :ptr IObjContext, :REFGUID, :CPFLAGS, :ptr IUnknown
                DECLSPEC_XFGVIRT(IContext, RemoveProperty)
                STD_METHOD RemoveProperty, :ptr IObjContext, :REFGUID
                DECLSPEC_XFGVIRT(IContext, GetProperty)
                STD_METHOD GetProperty, :ptr IObjContext, :REFGUID, :ptr CPFLAGS, :ptr ptr IUnknown
                DECLSPEC_XFGVIRT(IContext, EnumContextProps)
                STD_METHOD EnumContextProps, :ptr IObjContext, :ptr ptr IEnumContextProps
                DECLSPEC_XFGVIRT(IObjContext, Reserved1)
                STD_METHOD Reserved1, :ptr IObjContext
                DECLSPEC_XFGVIRT(IObjContext, Reserved2)
                STD_METHOD Reserved2, :ptr IObjContext
                DECLSPEC_XFGVIRT(IObjContext, Reserved3)
                STD_METHOD Reserved3, :ptr IObjContext
                DECLSPEC_XFGVIRT(IObjContext, Reserved4)
                STD_METHOD Reserved4, :ptr IObjContext
                DECLSPEC_XFGVIRT(IObjContext, Reserved5)
                STD_METHOD Reserved5, :ptr IObjContext
                DECLSPEC_XFGVIRT(IObjContext, Reserved6)
                STD_METHOD Reserved6, :ptr IObjContext
                DECLSPEC_XFGVIRT(IObjContext, Reserved7)
                STD_METHOD Reserved7, :ptr IObjContext
                ??Interface equ <>
                END_INTERFACE
              IObjContextVtbl ends
              IObjContext struct
                lpVtbl POINTER ?
              IObjContext ends
              ifdef COBJMACROS
                ;[...]
              endif
            endif
          endif
        endif
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      APTTYPEQUALIFIER typedef SDWORD
      APTTYPEQUALIFIER_NONE equ 0
      APTTYPEQUALIFIER_IMPLICIT_MTA equ 1
      APTTYPEQUALIFIER_NA_ON_MTA equ 2
      APTTYPEQUALIFIER_NA_ON_STA equ 3
      APTTYPEQUALIFIER_NA_ON_IMPLICIT_MTA equ 4
      APTTYPEQUALIFIER_NA_ON_MAINSTA equ 5
      APTTYPEQUALIFIER_APPLICATION_STA equ 6
      APTTYPEQUALIFIER_RESERVED_1 equ 7
      _APTTYPEQUALIFIER typedef APTTYPEQUALIFIER

      APTTYPE typedef SDWORD
      APTTYPE_CURRENT equ -1
      APTTYPE_STA equ 0
      APTTYPE_MTA equ 1
      APTTYPE_NA equ 2
      APTTYPE_MAINSTA equ 3
      _APTTYPE typedef APTTYPE

    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      THDTYPE typedef SDWORD
      THDTYPE_BLOCKMESSAGES equ 0
      THDTYPE_PROCESSMESSAGES equ 1
      _THDTYPE typedef THDTYPE

      APARTMENTID typedef DWORD
      externdef __MIDL_itf_objidlbase_0000_0048_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_objidlbase_0000_0048_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IComThreadingInfo_INTERFACE_DEFINED__
        __IComThreadingInfo_INTERFACE_DEFINED__ equ <>
        externdef IID_IComThreadingInfo:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IComThreadingInfoVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IComThreadingInfoVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IComThreadingInfo, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IComThreadingInfo
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IComThreadingInfo
            DECLSPEC_XFGVIRT(IComThreadingInfo, GetCurrentApartmentType)
            STD_METHOD GetCurrentApartmentType, :ptr IComThreadingInfo, :ptr APTTYPE
            DECLSPEC_XFGVIRT(IComThreadingInfo, GetCurrentThreadType)
            STD_METHOD GetCurrentThreadType, :ptr IComThreadingInfo, :ptr THDTYPE
            DECLSPEC_XFGVIRT(IComThreadingInfo, GetCurrentLogicalThreadId)
            STD_METHOD GetCurrentLogicalThreadId, :ptr IComThreadingInfo, :ptr GUID
            DECLSPEC_XFGVIRT(IComThreadingInfo, SetCurrentLogicalThreadId)
            STD_METHOD SetCurrentLogicalThreadId, :ptr IComThreadingInfo, :REFGUID
            ??Interface equ <>
            END_INTERFACE
          IComThreadingInfoVtbl ends
          IComThreadingInfo struct
            lpVtbl POINTER ?
          IComThreadingInfo ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IProcessInitControl_INTERFACE_DEFINED__
        __IProcessInitControl_INTERFACE_DEFINED__ equ <>
        externdef IID_IProcessInitControl:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IProcessInitControlVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IProcessInitControlVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IProcessInitControl, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IProcessInitControl
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IProcessInitControl
            DECLSPEC_XFGVIRT(IProcessInitControl, ResetInitializerTimeout)
            STD_METHOD ResetInitializerTimeout, :ptr IProcessInitControl, :DWORD
            ??Interface equ <>
            END_INTERFACE
          IProcessInitControlVtbl ends
          IProcessInitControl struct
            lpVtbl POINTER ?
          IProcessInitControl ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IFastRundown_INTERFACE_DEFINED__
        __IFastRundown_INTERFACE_DEFINED__ equ <>
        externdef IID_IFastRundown:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IFastRundownVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IFastRundownVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IFastRundown, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IFastRundown
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IFastRundown
            ??Interface equ <>
            END_INTERFACE
          IFastRundownVtbl ends
          IFastRundown struct
            lpVtbl POINTER ?
          IFastRundown ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      CO_MARSHALING_CONTEXT_ATTRIBUTES typedef SDWORD
      CO_MARSHALING_SOURCE_IS_APP_CONTAINER equ 0
      CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_1 equ 80000000h
      CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_2 equ 80000001h
      CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_3 equ 80000002h
      CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_4 equ 80000003h
      CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_5 equ 80000004h
      CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_6 equ 80000005h
      CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_7 equ 80000006h
      CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_8 equ 80000007h
      CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_9 equ 80000008h
      CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_10 equ 80000009h
      CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_11 equ 8000000ah
      CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_12 equ 8000000bh
      CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_13 equ 8000000ch
      CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_14 equ 8000000dh
      CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_15 equ 8000000eh
      CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_16 equ 8000000fh
      CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_17 equ 80000010h
      CO_MARSHALING_CONTEXT_ATTRIBUTE_RESERVED_18 equ 80000011h

      externdef __MIDL_itf_objidlbase_0000_0051_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_objidlbase_0000_0051_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IMarshalingStream_INTERFACE_DEFINED__
        __IMarshalingStream_INTERFACE_DEFINED__ equ <>
        externdef IID_IMarshalingStream:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IMarshalingStreamVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IMarshalingStreamVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IMarshalingStream, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IMarshalingStream
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IMarshalingStream
            DECLSPEC_XFGVIRT(ISequentialStream, Read)
            STD_METHOD Read, :ptr IMarshalingStream, :ptr, :ULONG, :ptr ULONG
            DECLSPEC_XFGVIRT(ISequentialStream, Write)
            STD_METHOD Write, :ptr IMarshalingStream, :ptr, :ULONG, :ptr ULONG
            DECLSPEC_XFGVIRT(IStream, Seek)
            STD_METHOD Seek, :ptr IMarshalingStream, :LARGE_INTEGER, :DWORD, :ptr ULARGE_INTEGER
            DECLSPEC_XFGVIRT(IStream, SetSize)
            STD_METHOD SetSize, :ptr IMarshalingStream, :ULARGE_INTEGER
            DECLSPEC_XFGVIRT(IStream, CopyTo)
            STD_METHOD CopyTo, :ptr IMarshalingStream, :ptr IStream, :ULARGE_INTEGER, :ptr ULARGE_INTEGER, :ptr ULARGE_INTEGER
            DECLSPEC_XFGVIRT(IStream, Commit)
            STD_METHOD Commit, :ptr IMarshalingStream, :DWORD
            DECLSPEC_XFGVIRT(IStream, Revert)
            STD_METHOD Revert, :ptr IMarshalingStream
            DECLSPEC_XFGVIRT(IStream, LockRegion)
            STD_METHOD LockRegion, :ptr IMarshalingStream, :ULARGE_INTEGER, :ULARGE_INTEGER, :DWORD
            DECLSPEC_XFGVIRT(IStream, UnlockRegion)
            STD_METHOD UnlockRegion, :ptr IMarshalingStream, :ULARGE_INTEGER, :ULARGE_INTEGER, :DWORD
            DECLSPEC_XFGVIRT(IStream, Stat)
            STD_METHOD Stat, :ptr IMarshalingStream, :ptr STATSTG, :DWORD
            DECLSPEC_XFGVIRT(IStream, Clone)
            STD_METHOD Clone, :ptr IMarshalingStream, :ptr ptr IStream
            DECLSPEC_XFGVIRT(IMarshalingStream, GetMarshalingContextAttribute)
            STD_METHOD GetMarshalingContextAttribute, :ptr IMarshalingStream, :CO_MARSHALING_CONTEXT_ATTRIBUTES, :ptr ULONG_PTR
            ??Interface equ <>
            END_INTERFACE
          IMarshalingStreamVtbl ends
          IMarshalingStream struct
            lpVtbl POINTER ?
          IMarshalingStream ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      externdef __MIDL_itf_objidlbase_0000_0052_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_objidlbase_0000_0052_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IAgileReference_INTERFACE_DEFINED__
        __IAgileReference_INTERFACE_DEFINED__ equ <>
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          externdef IID_IAgileReference:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IAgileReferenceVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IAgileReferenceVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IAgileReference, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IAgileReference
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IAgileReference
              DECLSPEC_XFGVIRT(IAgileReference, Resolve)
              STD_METHOD Resolve, :ptr IAgileReference, :REFIID, :ptr ptr
              ??Interface equ <>
              END_INTERFACE
            IAgileReferenceVtbl ends
            IAgileReference struct
              lpVtbl POINTER ?
            IAgileReference ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      externdef IID_ICallbackWithNoReentrancyToApplicationSTA:GUID
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      MachineGlobalObjectTableRegistrationToken__ struct
        unused SDWORD ?
      MachineGlobalObjectTableRegistrationToken__ ends
      MachineGlobalObjectTableRegistrationToken typedef ptr MachineGlobalObjectTableRegistrationToken__
      externdef __MIDL_itf_objidlbase_0000_0053_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_objidlbase_0000_0053_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IMachineGlobalObjectTable_INTERFACE_DEFINED__
        __IMachineGlobalObjectTable_INTERFACE_DEFINED__ equ <>
        externdef IID_IMachineGlobalObjectTable:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IMachineGlobalObjectTableVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IMachineGlobalObjectTableVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IMachineGlobalObjectTable, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IMachineGlobalObjectTable
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IMachineGlobalObjectTable
            DECLSPEC_XFGVIRT(IMachineGlobalObjectTable, RegisterObject)
            STD_METHOD RegisterObject, :ptr IMachineGlobalObjectTable, :REFCLSID, :LPCWSTR, :ptr IUnknown, :ptr MachineGlobalObjectTableRegistrationToken
            DECLSPEC_XFGVIRT(IMachineGlobalObjectTable, GetObject)
            STD_METHOD GetObject, :ptr IMachineGlobalObjectTable, :REFCLSID, :LPCWSTR, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IMachineGlobalObjectTable, RevokeObject)
            STD_METHOD RevokeObject, :ptr IMachineGlobalObjectTable, :MachineGlobalObjectTableRegistrationToken
            ??Interface equ <>
            END_INTERFACE
          IMachineGlobalObjectTableVtbl ends
          IMachineGlobalObjectTable struct
            lpVtbl POINTER ?
          IMachineGlobalObjectTable ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      externdef __MIDL_itf_objidlbase_0000_0054_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_objidlbase_0000_0054_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ISupportAllowLowerTrustActivation_INTERFACE_DEFINED__
        __ISupportAllowLowerTrustActivation_INTERFACE_DEFINED__ equ <>
        externdef IID_ISupportAllowLowerTrustActivation:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISupportAllowLowerTrustActivationVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISupportAllowLowerTrustActivationVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISupportAllowLowerTrustActivation, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISupportAllowLowerTrustActivation
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISupportAllowLowerTrustActivation
            ??Interface equ <>
            END_INTERFACE
          ISupportAllowLowerTrustActivationVtbl ends
          ISupportAllowLowerTrustActivation struct
            lpVtbl POINTER ?
          ISupportAllowLowerTrustActivation ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    _OBJIDLBASE_ equ <>
  endif
  if (_MSC_VER ge 800)
    if _MSC_VER ge 1200
    else
    endif
  endif
  externdef __MIDL_itf_objidlbase_0000_0055_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_objidlbase_0000_0055_v0_0_s_ifspec:RPC_IF_HANDLE
  IEnumUnknown_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumUnknown, :ULONG, :ptr ptr IUnknown, :ptr ULONG
  IEnumUnknown_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumUnknown, :ULONG, :ptr ptr IUnknown, :ptr ULONG
  IEnumString_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumString, :ULONG, :ptr LPOLESTR, :ptr ULONG
  IEnumString_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumString, :ULONG, :ptr LPOLESTR, :ptr ULONG
  ISequentialStream_Read_Proxy proto WIN_STD_CALL_CONV :ptr ISequentialStream, :ptr, :ULONG, :ptr ULONG
  ISequentialStream_Read_Stub proto WIN_STD_CALL_CONV :ptr ISequentialStream, :ptr byte, :ULONG, :ptr ULONG
  ISequentialStream_Write_Proxy proto WIN_STD_CALL_CONV :ptr ISequentialStream, :ptr, :ULONG, :ptr ULONG
  ISequentialStream_Write_Stub proto WIN_STD_CALL_CONV :ptr ISequentialStream, :ptr byte, :ULONG, :ptr ULONG
  IStream_Seek_Proxy proto WIN_STD_CALL_CONV :ptr IStream, :LARGE_INTEGER, :DWORD, :ptr ULARGE_INTEGER
  IStream_Seek_Stub proto WIN_STD_CALL_CONV :ptr IStream, :LARGE_INTEGER, :DWORD, :ptr ULARGE_INTEGER
  IStream_CopyTo_Proxy proto WIN_STD_CALL_CONV :ptr IStream, :ptr IStream, :ULARGE_INTEGER, :ptr ULARGE_INTEGER, :ptr ULARGE_INTEGER
  IStream_CopyTo_Stub proto WIN_STD_CALL_CONV :ptr IStream, :ptr IStream, :ULARGE_INTEGER, :ptr ULARGE_INTEGER, :ptr ULARGE_INTEGER
  ifdef __cplusplus
    ;[...]
  endif
endif
