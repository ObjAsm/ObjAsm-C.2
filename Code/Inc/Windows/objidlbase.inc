;Include file created by h2incX, Version B.01.01, 29/10/2018 18:21
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\objidlbase.h', last modified: 19/04/2018 09:46
;Creation parameters: 

ifndef __REQUIRED_RPCNDR_H_VERSION__
  __REQUIRED_RPCNDR_H_VERSION__ equ 500
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
  ifndef __IMarshal_FWD_DEFINED__
    __IMarshal_FWD_DEFINED__ equ <>
    ;IMarshal typedef IMarshal
    
  endif
  ifndef __INoMarshal_FWD_DEFINED__
    __INoMarshal_FWD_DEFINED__ equ <>
    ;INoMarshal typedef INoMarshal
    
  endif
  ifndef __IAgileObject_FWD_DEFINED__
    __IAgileObject_FWD_DEFINED__ equ <>
    ;IAgileObject typedef IAgileObject
    
  endif
  ifndef __IActivationFilter_FWD_DEFINED__
    __IActivationFilter_FWD_DEFINED__ equ <>
    ;IActivationFilter typedef IActivationFilter
    
  endif
  ifndef __IMarshal2_FWD_DEFINED__
    __IMarshal2_FWD_DEFINED__ equ <>
    ;IMarshal2 typedef IMarshal2
    
  endif
  ifndef __IMalloc_FWD_DEFINED__
    __IMalloc_FWD_DEFINED__ equ <>
    ;IMalloc typedef IMalloc
    
  endif
  ifndef __IStdMarshalInfo_FWD_DEFINED__
    __IStdMarshalInfo_FWD_DEFINED__ equ <>
    ;IStdMarshalInfo typedef IStdMarshalInfo
    
  endif
  ifndef __IExternalConnection_FWD_DEFINED__
    __IExternalConnection_FWD_DEFINED__ equ <>
    ;IExternalConnection typedef IExternalConnection
    
  endif
  ifndef __IMultiQI_FWD_DEFINED__
    __IMultiQI_FWD_DEFINED__ equ <>
    ;IMultiQI typedef IMultiQI
    
  endif
  ifndef __AsyncIMultiQI_FWD_DEFINED__
    __AsyncIMultiQI_FWD_DEFINED__ equ <>
    ;AsyncIMultiQI typedef AsyncIMultiQI
    
  endif
  ifndef __IInternalUnknown_FWD_DEFINED__
    __IInternalUnknown_FWD_DEFINED__ equ <>
    ;IInternalUnknown typedef IInternalUnknown
    
  endif
  ifndef __IEnumUnknown_FWD_DEFINED__
    __IEnumUnknown_FWD_DEFINED__ equ <>
    ;IEnumUnknown typedef IEnumUnknown
    
  endif
  ifndef __IEnumString_FWD_DEFINED__
    __IEnumString_FWD_DEFINED__ equ <>
    ;IEnumString typedef IEnumString
    
  endif
  ifndef __ISequentialStream_FWD_DEFINED__
    __ISequentialStream_FWD_DEFINED__ equ <>
    ;ISequentialStream typedef ISequentialStream
    
  endif
  ifndef __IStream_FWD_DEFINED__
    __IStream_FWD_DEFINED__ equ <>
    ;IStream typedef IStream
    
  endif
  ifndef __IRpcChannelBuffer_FWD_DEFINED__
    __IRpcChannelBuffer_FWD_DEFINED__ equ <>
    ;IRpcChannelBuffer typedef IRpcChannelBuffer
    
  endif
  ifndef __IRpcChannelBuffer2_FWD_DEFINED__
    __IRpcChannelBuffer2_FWD_DEFINED__ equ <>
    ;IRpcChannelBuffer2 typedef IRpcChannelBuffer2
    
  endif
  ifndef __IAsyncRpcChannelBuffer_FWD_DEFINED__
    __IAsyncRpcChannelBuffer_FWD_DEFINED__ equ <>
    ;IAsyncRpcChannelBuffer typedef IAsyncRpcChannelBuffer
    
  endif
  ifndef __IRpcChannelBuffer3_FWD_DEFINED__
    __IRpcChannelBuffer3_FWD_DEFINED__ equ <>
    ;IRpcChannelBuffer3 typedef IRpcChannelBuffer3
    
  endif
  ifndef __IRpcSyntaxNegotiate_FWD_DEFINED__
    __IRpcSyntaxNegotiate_FWD_DEFINED__ equ <>
    ;IRpcSyntaxNegotiate typedef IRpcSyntaxNegotiate
    
  endif
  ifndef __IRpcProxyBuffer_FWD_DEFINED__
    __IRpcProxyBuffer_FWD_DEFINED__ equ <>
    ;IRpcProxyBuffer typedef IRpcProxyBuffer
    
  endif
  ifndef __IRpcStubBuffer_FWD_DEFINED__
    __IRpcStubBuffer_FWD_DEFINED__ equ <>
    ;IRpcStubBuffer typedef IRpcStubBuffer
    
  endif
  ifndef __IPSFactoryBuffer_FWD_DEFINED__
    __IPSFactoryBuffer_FWD_DEFINED__ equ <>
    ;IPSFactoryBuffer typedef IPSFactoryBuffer
    
  endif
  ifndef __IChannelHook_FWD_DEFINED__
    __IChannelHook_FWD_DEFINED__ equ <>
    ;IChannelHook typedef IChannelHook
    
  endif
  ifndef __IClientSecurity_FWD_DEFINED__
    __IClientSecurity_FWD_DEFINED__ equ <>
    ;IClientSecurity typedef IClientSecurity
    
  endif
  ifndef __IServerSecurity_FWD_DEFINED__
    __IServerSecurity_FWD_DEFINED__ equ <>
    ;IServerSecurity typedef IServerSecurity
    
  endif
  ifndef __IRpcOptions_FWD_DEFINED__
    __IRpcOptions_FWD_DEFINED__ equ <>
    ;IRpcOptions typedef IRpcOptions
    
  endif
  ifndef __IGlobalOptions_FWD_DEFINED__
    __IGlobalOptions_FWD_DEFINED__ equ <>
    ;IGlobalOptions typedef IGlobalOptions
    
  endif
  ifndef __ISurrogate_FWD_DEFINED__
    __ISurrogate_FWD_DEFINED__ equ <>
    ;ISurrogate typedef ISurrogate
    
  endif
  ifndef __IGlobalInterfaceTable_FWD_DEFINED__
    __IGlobalInterfaceTable_FWD_DEFINED__ equ <>
    ;IGlobalInterfaceTable typedef IGlobalInterfaceTable
    
  endif
  ifndef __ISynchronize_FWD_DEFINED__
    __ISynchronize_FWD_DEFINED__ equ <>
    ;ISynchronize typedef ISynchronize
    
  endif
  ifndef __ISynchronizeHandle_FWD_DEFINED__
    __ISynchronizeHandle_FWD_DEFINED__ equ <>
    ;ISynchronizeHandle typedef ISynchronizeHandle
    
  endif
  ifndef __ISynchronizeEvent_FWD_DEFINED__
    __ISynchronizeEvent_FWD_DEFINED__ equ <>
    ;ISynchronizeEvent typedef ISynchronizeEvent
    
  endif
  ifndef __ISynchronizeContainer_FWD_DEFINED__
    __ISynchronizeContainer_FWD_DEFINED__ equ <>
    ;ISynchronizeContainer typedef ISynchronizeContainer
    
  endif
  ifndef __ISynchronizeMutex_FWD_DEFINED__
    __ISynchronizeMutex_FWD_DEFINED__ equ <>
    ;ISynchronizeMutex typedef ISynchronizeMutex
    
  endif
  ifndef __ICancelMethodCalls_FWD_DEFINED__
    __ICancelMethodCalls_FWD_DEFINED__ equ <>
    ;ICancelMethodCalls typedef ICancelMethodCalls
    
  endif
  ifndef __IAsyncManager_FWD_DEFINED__
    __IAsyncManager_FWD_DEFINED__ equ <>
    ;IAsyncManager typedef IAsyncManager
    
  endif
  ifndef __ICallFactory_FWD_DEFINED__
    __ICallFactory_FWD_DEFINED__ equ <>
    ;ICallFactory typedef ICallFactory
    
  endif
  ifndef __IRpcHelper_FWD_DEFINED__
    __IRpcHelper_FWD_DEFINED__ equ <>
    ;IRpcHelper typedef IRpcHelper
    
  endif
  ifndef __IReleaseMarshalBuffers_FWD_DEFINED__
    __IReleaseMarshalBuffers_FWD_DEFINED__ equ <>
    ;IReleaseMarshalBuffers typedef IReleaseMarshalBuffers
    
  endif
  ifndef __IWaitMultiple_FWD_DEFINED__
    __IWaitMultiple_FWD_DEFINED__ equ <>
    ;IWaitMultiple typedef IWaitMultiple
    
  endif
  ifndef __IAddrTrackingControl_FWD_DEFINED__
    __IAddrTrackingControl_FWD_DEFINED__ equ <>
    ;IAddrTrackingControl typedef IAddrTrackingControl
    
  endif
  ifndef __IAddrExclusionControl_FWD_DEFINED__
    __IAddrExclusionControl_FWD_DEFINED__ equ <>
    ;IAddrExclusionControl typedef IAddrExclusionControl
    
  endif
  ifndef __IPipeByte_FWD_DEFINED__
    __IPipeByte_FWD_DEFINED__ equ <>
    ;IPipeByte typedef IPipeByte
    
  endif
  ifndef __AsyncIPipeByte_FWD_DEFINED__
    __AsyncIPipeByte_FWD_DEFINED__ equ <>
    ;AsyncIPipeByte typedef AsyncIPipeByte
    
  endif
  ifndef __IPipeLong_FWD_DEFINED__
    __IPipeLong_FWD_DEFINED__ equ <>
    ;IPipeLong typedef IPipeLong
    
  endif
  ifndef __AsyncIPipeLong_FWD_DEFINED__
    __AsyncIPipeLong_FWD_DEFINED__ equ <>
    ;AsyncIPipeLong typedef AsyncIPipeLong
    
  endif
  ifndef __IPipeDouble_FWD_DEFINED__
    __IPipeDouble_FWD_DEFINED__ equ <>
    ;IPipeDouble typedef IPipeDouble
    
  endif
  ifndef __AsyncIPipeDouble_FWD_DEFINED__
    __AsyncIPipeDouble_FWD_DEFINED__ equ <>
    ;AsyncIPipeDouble typedef AsyncIPipeDouble
    
  endif
  ifndef __IEnumContextProps_FWD_DEFINED__
    __IEnumContextProps_FWD_DEFINED__ equ <>
    ;IEnumContextProps typedef IEnumContextProps
    
  endif
  ifndef __IContext_FWD_DEFINED__
    __IContext_FWD_DEFINED__ equ <>
    ;IContext typedef IContext
    
  endif
  ifndef __IObjContext_FWD_DEFINED__
    __IObjContext_FWD_DEFINED__ equ <>
    ;IObjContext typedef IObjContext
    
  endif
  ifndef __IComThreadingInfo_FWD_DEFINED__
    __IComThreadingInfo_FWD_DEFINED__ equ <>
    ;IComThreadingInfo typedef IComThreadingInfo
    
  endif
  ifndef __IProcessInitControl_FWD_DEFINED__
    __IProcessInitControl_FWD_DEFINED__ equ <>
    ;IProcessInitControl typedef IProcessInitControl
    
  endif
  ifndef __IFastRundown_FWD_DEFINED__
    __IFastRundown_FWD_DEFINED__ equ <>
    ;IFastRundown typedef IFastRundown
    
  endif
  ifndef __IMarshalingStream_FWD_DEFINED__
    __IMarshalingStream_FWD_DEFINED__ equ <>
    ;IMarshalingStream typedef IMarshalingStream
    
  endif
  ifndef __IAgileReference_FWD_DEFINED__
    __IAgileReference_FWD_DEFINED__ equ <>
    ;IAgileReference typedef IAgileReference
    
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
  include limits.inc
  ifndef _OBJIDLBASE_
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
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
            STD_METHOD QueryInterface, :ptr IMarshal, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IMarshal
            STD_METHOD Release, :ptr IMarshal
            STD_METHOD GetUnmarshalClass, :ptr IMarshal, :REFIID, :ptr, :DWORD, :ptr, :DWORD, :ptr CLSID
            STD_METHOD GetMarshalSizeMax, :ptr IMarshal, :REFIID, :ptr, :DWORD, :ptr, :DWORD, :ptr DWORD
            STD_METHOD MarshalInterface, :ptr IMarshal, :ptr IStream, :REFIID, :ptr, :DWORD, :ptr, :DWORD
            STD_METHOD UnmarshalInterface, :ptr IMarshal, :ptr IStream, :REFIID, :ptr ptr
            STD_METHOD ReleaseMarshalData, :ptr IMarshal, :ptr IStream
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
            STD_METHOD QueryInterface, :ptr INoMarshal, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr INoMarshal
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
            STD_METHOD QueryInterface, :ptr IAgileObject, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IAgileObject
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
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
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
            STD_METHOD QueryInterface, :ptr IActivationFilter, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IActivationFilter
            STD_METHOD Release, :ptr IActivationFilter
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
            STD_METHOD QueryInterface, :ptr IMarshal2, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IMarshal2
            STD_METHOD Release, :ptr IMarshal2
            STD_METHOD GetUnmarshalClass, :ptr IMarshal2, :REFIID, :ptr, :DWORD, :ptr, :DWORD, :ptr CLSID
            STD_METHOD GetMarshalSizeMax, :ptr IMarshal2, :REFIID, :ptr, :DWORD, :ptr, :DWORD, :ptr DWORD
            STD_METHOD MarshalInterface, :ptr IMarshal2, :ptr IStream, :REFIID, :ptr, :DWORD, :ptr, :DWORD
            STD_METHOD UnmarshalInterface, :ptr IMarshal2, :ptr IStream, :REFIID, :ptr ptr
            STD_METHOD ReleaseMarshalData, :ptr IMarshal2, :ptr IStream
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
            STD_METHOD QueryInterface, :ptr IMalloc, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IMalloc
            STD_METHOD Release, :ptr IMalloc
            STD_METHOD Alloc, :ptr IMalloc, :SIZE_T
            STD_METHOD Realloc, :ptr IMalloc, :ptr, :SIZE_T
            STD_METHOD Free, :ptr IMalloc, :ptr
            STD_METHOD GetSize, :ptr IMalloc, :ptr
            STD_METHOD DidAlloc, :ptr IMalloc, :ptr
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
            STD_METHOD QueryInterface, :ptr IStdMarshalInfo, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IStdMarshalInfo
            STD_METHOD Release, :ptr IStdMarshalInfo
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
            STD_METHOD QueryInterface, :ptr IExternalConnection, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IExternalConnection
            STD_METHOD Release, :ptr IExternalConnection
            STD_METHOD AddConnection, :ptr IExternalConnection, :DWORD, :DWORD
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
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
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
            STD_METHOD QueryInterface, :ptr IMultiQI, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IMultiQI
            STD_METHOD Release, :ptr IMultiQI
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
            STD_METHOD QueryInterface, :ptr AsyncIMultiQI, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr AsyncIMultiQI
            STD_METHOD Release, :ptr AsyncIMultiQI
            STD_METHOD Begin_QueryMultipleInterfaces, :ptr AsyncIMultiQI, :ULONG, :ptr MULTI_QI
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
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
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
            STD_METHOD QueryInterface, :ptr IInternalUnknown, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IInternalUnknown
            STD_METHOD Release, :ptr IInternalUnknown
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
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
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
            STD_METHOD QueryInterface, :ptr IEnumUnknown, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IEnumUnknown
            STD_METHOD Release, :ptr IEnumUnknown
            STD_METHOD Next, :ptr IEnumUnknown, :ULONG, :ptr ptr IUnknown, :ptr ULONG
            STD_METHOD Skip, :ptr IEnumUnknown, :ULONG
            STD_METHOD Reset, :ptr IEnumUnknown
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
            STD_METHOD QueryInterface, :ptr IEnumString, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IEnumString
            STD_METHOD Release, :ptr IEnumString
            STD_METHOD Next, :ptr IEnumString, :ULONG, :ptr LPOLESTR, :ptr ULONG
            STD_METHOD Skip, :ptr IEnumString, :ULONG
            STD_METHOD Reset, :ptr IEnumString
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
            STD_METHOD QueryInterface, :ptr ISequentialStream, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr ISequentialStream
            STD_METHOD Release, :ptr ISequentialStream
            STD_METHOD Read, :ptr ISequentialStream, :ptr, :ULONG, :ptr ULONG
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
            STD_METHOD QueryInterface, :ptr IStream, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IStream
            STD_METHOD Release, :ptr IStream
            STD_METHOD Read, :ptr IStream, :ptr, :ULONG, :ptr ULONG
            STD_METHOD Write, :ptr IStream, :ptr, :ULONG, :ptr ULONG
            STD_METHOD Seek, :ptr IStream, :LARGE_INTEGER, :DWORD, :ptr ULARGE_INTEGER
            STD_METHOD SetSize, :ptr IStream, :ULARGE_INTEGER
            STD_METHOD CopyTo, :ptr IStream, :ptr IStream, :ULARGE_INTEGER, :ptr ULARGE_INTEGER, :ptr ULARGE_INTEGER
            STD_METHOD Commit, :ptr IStream, :DWORD
            STD_METHOD Revert, :ptr IStream
            STD_METHOD LockRegion, :ptr IStream, :ULARGE_INTEGER, :ULARGE_INTEGER, :DWORD
            STD_METHOD UnlockRegion, :ptr IStream, :ULARGE_INTEGER, :ULARGE_INTEGER, :DWORD
            STD_METHOD Stat, :ptr IStream, :ptr STATSTG, :DWORD
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
            STD_METHOD QueryInterface, :ptr IRpcChannelBuffer, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IRpcChannelBuffer
            STD_METHOD Release, :ptr IRpcChannelBuffer
            STD_METHOD GetBuffer, :ptr IRpcChannelBuffer, :ptr RPCOLEMESSAGE, :REFIID
            STD_METHOD SendReceive, :ptr IRpcChannelBuffer, :ptr RPCOLEMESSAGE, :ptr ULONG
            STD_METHOD FreeBuffer, :ptr IRpcChannelBuffer, :ptr RPCOLEMESSAGE
            STD_METHOD GetDestCtx, :ptr IRpcChannelBuffer, :ptr DWORD, :ptr ptr
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
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
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
            STD_METHOD QueryInterface, :ptr IRpcChannelBuffer2, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IRpcChannelBuffer2
            STD_METHOD Release, :ptr IRpcChannelBuffer2
            STD_METHOD GetBuffer, :ptr IRpcChannelBuffer2, :ptr RPCOLEMESSAGE, :REFIID
            STD_METHOD SendReceive, :ptr IRpcChannelBuffer2, :ptr RPCOLEMESSAGE, :ptr ULONG
            STD_METHOD FreeBuffer, :ptr IRpcChannelBuffer2, :ptr RPCOLEMESSAGE
            STD_METHOD GetDestCtx, :ptr IRpcChannelBuffer2, :ptr DWORD, :ptr ptr
            STD_METHOD IsConnected, :ptr IRpcChannelBuffer2
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
            STD_METHOD QueryInterface, :ptr IAsyncRpcChannelBuffer, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IAsyncRpcChannelBuffer
            STD_METHOD Release, :ptr IAsyncRpcChannelBuffer
            STD_METHOD GetBuffer, :ptr IAsyncRpcChannelBuffer, :ptr RPCOLEMESSAGE, :REFIID
            STD_METHOD SendReceive, :ptr IAsyncRpcChannelBuffer, :ptr RPCOLEMESSAGE, :ptr ULONG
            STD_METHOD FreeBuffer, :ptr IAsyncRpcChannelBuffer, :ptr RPCOLEMESSAGE
            STD_METHOD GetDestCtx, :ptr IAsyncRpcChannelBuffer, :ptr DWORD, :ptr ptr
            STD_METHOD IsConnected, :ptr IAsyncRpcChannelBuffer
            STD_METHOD GetProtocolVersion, :ptr IAsyncRpcChannelBuffer, :ptr DWORD
            STD_METHOD Send, :ptr IAsyncRpcChannelBuffer, :ptr RPCOLEMESSAGE, :ptr ISynchronize, :ptr ULONG
            STD_METHOD Receive, :ptr IAsyncRpcChannelBuffer, :ptr RPCOLEMESSAGE, :ptr ULONG
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
            STD_METHOD QueryInterface, :ptr IRpcChannelBuffer3, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IRpcChannelBuffer3
            STD_METHOD Release, :ptr IRpcChannelBuffer3
            STD_METHOD GetBuffer, :ptr IRpcChannelBuffer3, :ptr RPCOLEMESSAGE, :REFIID
            STD_METHOD SendReceive, :ptr IRpcChannelBuffer3, :ptr RPCOLEMESSAGE, :ptr ULONG
            STD_METHOD FreeBuffer, :ptr IRpcChannelBuffer3, :ptr RPCOLEMESSAGE
            STD_METHOD GetDestCtx, :ptr IRpcChannelBuffer3, :ptr DWORD, :ptr ptr
            STD_METHOD IsConnected, :ptr IRpcChannelBuffer3
            STD_METHOD GetProtocolVersion, :ptr IRpcChannelBuffer3, :ptr DWORD
            STD_METHOD Send, :ptr IRpcChannelBuffer3, :ptr RPCOLEMESSAGE, :ptr ULONG
            STD_METHOD Receive, :ptr IRpcChannelBuffer3, :ptr RPCOLEMESSAGE, :ULONG, :ptr ULONG
            STD_METHOD Cancel, :ptr IRpcChannelBuffer3, :ptr RPCOLEMESSAGE
            STD_METHOD GetCallContext, :ptr IRpcChannelBuffer3, :ptr RPCOLEMESSAGE, :REFIID, :ptr ptr
            STD_METHOD GetDestCtxEx, :ptr IRpcChannelBuffer3, :ptr RPCOLEMESSAGE, :ptr DWORD, :ptr ptr
            STD_METHOD GetState, :ptr IRpcChannelBuffer3, :ptr RPCOLEMESSAGE, :ptr DWORD
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
            STD_METHOD QueryInterface, :ptr IRpcSyntaxNegotiate, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IRpcSyntaxNegotiate
            STD_METHOD Release, :ptr IRpcSyntaxNegotiate
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
            STD_METHOD QueryInterface, :ptr IRpcProxyBuffer, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IRpcProxyBuffer
            STD_METHOD Release, :ptr IRpcProxyBuffer
            STD_METHOD Connect, :ptr IRpcProxyBuffer, :ptr IRpcChannelBuffer
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
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
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
            STD_METHOD QueryInterface, :ptr IRpcStubBuffer, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IRpcStubBuffer
            STD_METHOD Release, :ptr IRpcStubBuffer
            STD_METHOD Connect, :ptr IRpcStubBuffer, :ptr IUnknown
            STD_METHOD Disconnect, :ptr IRpcStubBuffer
            STD_METHOD Invoke_, :ptr IRpcStubBuffer, :ptr RPCOLEMESSAGE, :ptr IRpcChannelBuffer
            STD_METHOD IsIIDSupported, :ptr IRpcStubBuffer, :REFIID
            STD_METHOD CountRefs, :ptr IRpcStubBuffer
            STD_METHOD DebugServerQueryInterface, :ptr IRpcStubBuffer, :ptr ptr
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
            STD_METHOD QueryInterface, :ptr IPSFactoryBuffer, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IPSFactoryBuffer
            STD_METHOD Release, :ptr IPSFactoryBuffer
            STD_METHOD CreateProxy, :ptr IPSFactoryBuffer, :ptr IUnknown, :REFIID, :ptr ptr IRpcProxyBuffer, :ptr ptr
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
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
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
              STD_METHOD QueryInterface, :ptr IChannelHook, :REFIID, :ptr ptr
              STD_METHOD AddRef, :ptr IChannelHook
              STD_METHOD Release, :ptr IChannelHook
              STD_METHOD ClientGetSize, :ptr IChannelHook, :REFGUID, :REFIID, :ptr ULONG
              STD_METHOD ClientFillBuffer, :ptr IChannelHook, :REFGUID, :REFIID, :ptr ULONG, :ptr
              STD_METHOD ClientNotify, :ptr IChannelHook, :REFGUID, :REFIID, :ULONG, :ptr, :DWORD, :HRESULT
              STD_METHOD ServerNotify, :ptr IChannelHook, :REFGUID, :REFIID, :ULONG, :ptr, :DWORD
              STD_METHOD ServerGetSize, :ptr IChannelHook, :REFGUID, :REFIID, :HRESULT, :ptr ULONG
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
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
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
              STD_METHOD QueryInterface, :ptr IClientSecurity, :REFIID, :ptr ptr
              STD_METHOD AddRef, :ptr IClientSecurity
              STD_METHOD Release, :ptr IClientSecurity
              STD_METHOD QueryBlanket, :ptr IClientSecurity, :ptr IUnknown, :ptr DWORD, :ptr DWORD, :ptr ptr OLECHAR, :ptr DWORD, :ptr DWORD, :ptr ptr, :ptr DWORD
              STD_METHOD SetBlanket, :ptr IClientSecurity, :ptr IUnknown, :DWORD, :DWORD, :ptr OLECHAR, :DWORD, :DWORD, :ptr, :DWORD
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
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
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
              STD_METHOD QueryInterface, :ptr IServerSecurity, :REFIID, :ptr ptr
              STD_METHOD AddRef, :ptr IServerSecurity
              STD_METHOD Release, :ptr IServerSecurity
              STD_METHOD QueryBlanket, :ptr IServerSecurity, :ptr DWORD, :ptr DWORD, :ptr ptr OLECHAR, :ptr DWORD, :ptr DWORD, :ptr ptr, :ptr DWORD
              STD_METHOD ImpersonateClient, :ptr IServerSecurity
              STD_METHOD RevertToSelf, :ptr IServerSecurity
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
              STD_METHOD QueryInterface, :ptr IRpcOptions, :REFIID, :ptr ptr
              STD_METHOD AddRef, :ptr IRpcOptions
              STD_METHOD Release, :ptr IRpcOptions
              STD_METHOD Set, :ptr IRpcOptions, :ptr IUnknown, :RPCOPT_PROPERTIES, :ULONG_PTR
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
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        GLOBALOPT_PROPERTIES typedef SDWORD
        COMGLB_EXCEPTION_HANDLING equ 1
        COMGLB_APPID equ 2
        COMGLB_RPC_THREADPOOL_SETTING equ 3
        COMGLB_RO_SETTINGS equ 4
        COMGLB_UNMARSHALING_POLICY equ 5
        COMGLB_PROPERTIES_RESERVED1 equ 6
        COMGLB_PROPERTIES_RESERVED2 equ 7
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
              STD_METHOD QueryInterface, :ptr IGlobalOptions, :REFIID, :ptr ptr
              STD_METHOD AddRef, :ptr IGlobalOptions
              STD_METHOD Release, :ptr IGlobalOptions
              STD_METHOD Set, :ptr IGlobalOptions, :GLOBALOPT_PROPERTIES, :ULONG_PTR
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
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
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
            STD_METHOD QueryInterface, :ptr ISurrogate, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr ISurrogate
            STD_METHOD Release, :ptr ISurrogate
            STD_METHOD LoadDllServer, :ptr ISurrogate, :REFCLSID
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
            STD_METHOD QueryInterface, :ptr IGlobalInterfaceTable, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IGlobalInterfaceTable
            STD_METHOD Release, :ptr IGlobalInterfaceTable
            STD_METHOD RegisterInterfaceInGlobal, :ptr IGlobalInterfaceTable, :ptr IUnknown, :REFIID, :ptr DWORD
            STD_METHOD RevokeInterfaceFromGlobal, :ptr IGlobalInterfaceTable, :DWORD
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
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
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
            STD_METHOD QueryInterface, :ptr ISynchronize, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr ISynchronize
            STD_METHOD Release, :ptr ISynchronize
            STD_METHOD Wait_, :ptr ISynchronize, :DWORD, :DWORD
            STD_METHOD Signal, :ptr ISynchronize
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
            STD_METHOD QueryInterface, :ptr ISynchronizeHandle, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr ISynchronizeHandle
            STD_METHOD Release, :ptr ISynchronizeHandle
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
            STD_METHOD QueryInterface, :ptr ISynchronizeEvent, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr ISynchronizeEvent
            STD_METHOD Release, :ptr ISynchronizeEvent
            STD_METHOD GetHandle, :ptr ISynchronizeEvent, :ptr HANDLE
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
            STD_METHOD QueryInterface, :ptr ISynchronizeContainer, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr ISynchronizeContainer
            STD_METHOD Release, :ptr ISynchronizeContainer
            STD_METHOD AddSynchronize, :ptr ISynchronizeContainer, :ptr ISynchronize
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
            STD_METHOD QueryInterface, :ptr ISynchronizeMutex, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr ISynchronizeMutex
            STD_METHOD Release, :ptr ISynchronizeMutex
            STD_METHOD Wait_, :ptr ISynchronizeMutex, :DWORD, :DWORD
            STD_METHOD Signal, :ptr ISynchronizeMutex
            STD_METHOD Reset, :ptr ISynchronizeMutex
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
            STD_METHOD QueryInterface, :ptr ICancelMethodCalls, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr ICancelMethodCalls
            STD_METHOD Release, :ptr ICancelMethodCalls
            STD_METHOD Cancel, :ptr ICancelMethodCalls, :ULONG
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
            STD_METHOD QueryInterface, :ptr IAsyncManager, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IAsyncManager
            STD_METHOD Release, :ptr IAsyncManager
            STD_METHOD CompleteCall, :ptr IAsyncManager, :HRESULT
            STD_METHOD GetCallContext, :ptr IAsyncManager, :REFIID, :ptr ptr
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
            STD_METHOD QueryInterface, :ptr ICallFactory, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr ICallFactory
            STD_METHOD Release, :ptr ICallFactory
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
            STD_METHOD QueryInterface, :ptr IRpcHelper, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IRpcHelper
            STD_METHOD Release, :ptr IRpcHelper
            STD_METHOD GetDCOMProtocolVersion, :ptr IRpcHelper, :ptr DWORD
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
            STD_METHOD QueryInterface, :ptr IReleaseMarshalBuffers, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IReleaseMarshalBuffers
            STD_METHOD Release, :ptr IReleaseMarshalBuffers
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
            STD_METHOD QueryInterface, :ptr IWaitMultiple, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IWaitMultiple
            STD_METHOD Release, :ptr IWaitMultiple
            STD_METHOD WaitMultiple, :ptr IWaitMultiple, :DWORD, :ptr ptr ISynchronize
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
            STD_METHOD QueryInterface, :ptr IAddrTrackingControl, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IAddrTrackingControl
            STD_METHOD Release, :ptr IAddrTrackingControl
            STD_METHOD EnableCOMDynamicAddrTracking, :ptr IAddrTrackingControl
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
            STD_METHOD QueryInterface, :ptr IAddrExclusionControl, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IAddrExclusionControl
            STD_METHOD Release, :ptr IAddrExclusionControl
            STD_METHOD GetCurrentAddrExclusionList, :ptr IAddrExclusionControl, :REFIID, :ptr ptr
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
            STD_METHOD QueryInterface, :ptr IPipeByte, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IPipeByte
            STD_METHOD Release, :ptr IPipeByte
            STD_METHOD Pull, :ptr IPipeByte, :ptr BYTE, :ULONG, :ptr ULONG
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
            STD_METHOD QueryInterface, :ptr AsyncIPipeByte, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr AsyncIPipeByte
            STD_METHOD Release, :ptr AsyncIPipeByte
            STD_METHOD Begin_Pull, :ptr AsyncIPipeByte, :ULONG
            STD_METHOD Finish_Pull, :ptr AsyncIPipeByte, :ptr BYTE, :ptr ULONG
            STD_METHOD Begin_Push, :ptr AsyncIPipeByte, :ptr BYTE, :ULONG
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
            STD_METHOD QueryInterface, :ptr IPipeLong, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IPipeLong
            STD_METHOD Release, :ptr IPipeLong
            STD_METHOD Pull, :ptr IPipeLong, :ptr LONG, :ULONG, :ptr ULONG
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
            STD_METHOD QueryInterface, :ptr AsyncIPipeLong, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr AsyncIPipeLong
            STD_METHOD Release, :ptr AsyncIPipeLong
            STD_METHOD Begin_Pull, :ptr AsyncIPipeLong, :ULONG
            STD_METHOD Finish_Pull, :ptr AsyncIPipeLong, :ptr LONG, :ptr ULONG
            STD_METHOD Begin_Push, :ptr AsyncIPipeLong, :ptr LONG, :ULONG
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
            STD_METHOD QueryInterface, :ptr IPipeDouble, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IPipeDouble
            STD_METHOD Release, :ptr IPipeDouble
            STD_METHOD Pull, :ptr IPipeDouble, :ptr DOUBLE, :ULONG, :ptr ULONG
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
            STD_METHOD QueryInterface, :ptr AsyncIPipeDouble, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr AsyncIPipeDouble
            STD_METHOD Release, :ptr AsyncIPipeDouble
            STD_METHOD Begin_Pull, :ptr AsyncIPipeDouble, :ULONG
            STD_METHOD Finish_Pull, :ptr AsyncIPipeDouble, :ptr DOUBLE, :ptr ULONG
            STD_METHOD Begin_Push, :ptr AsyncIPipeDouble, :ptr DOUBLE, :ULONG
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
              STD_METHOD QueryInterface, :ptr IEnumContextProps, :REFIID, :ptr ptr
              STD_METHOD AddRef, :ptr IEnumContextProps
              STD_METHOD Release, :ptr IEnumContextProps
              STD_METHOD Next, :ptr IEnumContextProps, :ULONG, :ptr ContextProperty, :ptr ULONG
              STD_METHOD Skip, :ptr IEnumContextProps, :ULONG
              STD_METHOD Reset, :ptr IEnumContextProps
              STD_METHOD Clone, :ptr IEnumContextProps, :ptr ptr IEnumContextProps
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
              STD_METHOD QueryInterface, :ptr IContext, :REFIID, :ptr ptr
              STD_METHOD AddRef, :ptr IContext
              STD_METHOD Release, :ptr IContext
              STD_METHOD SetProperty, :ptr IContext, :REFGUID, :CPFLAGS, :ptr IUnknown
              STD_METHOD RemoveProperty, :ptr IContext, :REFGUID
              STD_METHOD GetProperty, :ptr IContext, :REFGUID, :ptr CPFLAGS, :ptr ptr IUnknown
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
                STD_METHOD QueryInterface, :ptr IObjContext, :REFIID, :ptr ptr
                STD_METHOD AddRef, :ptr IObjContext
                STD_METHOD Release, :ptr IObjContext
                STD_METHOD SetProperty, :ptr IObjContext, :REFGUID, :CPFLAGS, :ptr IUnknown
                STD_METHOD RemoveProperty, :ptr IObjContext, :REFGUID
                STD_METHOD GetProperty, :ptr IObjContext, :REFGUID, :ptr CPFLAGS, :ptr ptr IUnknown
                STD_METHOD EnumContextProps, :ptr IObjContext, :ptr ptr IEnumContextProps
                STD_METHOD Reserved1, :ptr IObjContext
                STD_METHOD Reserved2, :ptr IObjContext
                STD_METHOD Reserved3, :ptr IObjContext
                STD_METHOD Reserved4, :ptr IObjContext
                STD_METHOD Reserved5, :ptr IObjContext
                STD_METHOD Reserved6, :ptr IObjContext
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
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      APTTYPEQUALIFIER typedef SDWORD
      APTTYPEQUALIFIER_NONE equ 0
      APTTYPEQUALIFIER_IMPLICIT_MTA equ 1
      APTTYPEQUALIFIER_NA_ON_MTA equ 2
      APTTYPEQUALIFIER_NA_ON_STA equ 3
      APTTYPEQUALIFIER_NA_ON_IMPLICIT_MTA equ 4
      APTTYPEQUALIFIER_NA_ON_MAINSTA equ 5
      APTTYPEQUALIFIER_APPLICATION_STA equ 6
      _APTTYPEQUALIFIER typedef APTTYPEQUALIFIER
      
      APTTYPE typedef SDWORD
      APTTYPE_CURRENT equ -1
      APTTYPE_STA equ 0
      APTTYPE_MTA equ 1
      APTTYPE_NA equ 2
      APTTYPE_MAINSTA equ 3
      _APTTYPE typedef APTTYPE
      
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
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
            STD_METHOD QueryInterface, :ptr IComThreadingInfo, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IComThreadingInfo
            STD_METHOD Release, :ptr IComThreadingInfo
            STD_METHOD GetCurrentApartmentType, :ptr IComThreadingInfo, :ptr APTTYPE
            STD_METHOD GetCurrentThreadType, :ptr IComThreadingInfo, :ptr THDTYPE
            STD_METHOD GetCurrentLogicalThreadId, :ptr IComThreadingInfo, :ptr GUID
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
            STD_METHOD QueryInterface, :ptr IProcessInitControl, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IProcessInitControl
            STD_METHOD Release, :ptr IProcessInitControl
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
            STD_METHOD QueryInterface, :ptr IFastRundown, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IFastRundown
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
            STD_METHOD QueryInterface, :ptr IMarshalingStream, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IMarshalingStream
            STD_METHOD Release, :ptr IMarshalingStream
            STD_METHOD Read, :ptr IMarshalingStream, :ptr, :ULONG, :ptr ULONG
            STD_METHOD Write, :ptr IMarshalingStream, :ptr, :ULONG, :ptr ULONG
            STD_METHOD Seek, :ptr IMarshalingStream, :LARGE_INTEGER, :DWORD, :ptr ULARGE_INTEGER
            STD_METHOD SetSize, :ptr IMarshalingStream, :ULARGE_INTEGER
            STD_METHOD CopyTo, :ptr IMarshalingStream, :ptr IStream, :ULARGE_INTEGER, :ptr ULARGE_INTEGER, :ptr ULARGE_INTEGER
            STD_METHOD Commit, :ptr IMarshalingStream, :DWORD
            STD_METHOD Revert, :ptr IMarshalingStream
            STD_METHOD LockRegion, :ptr IMarshalingStream, :ULARGE_INTEGER, :ULARGE_INTEGER, :DWORD
            STD_METHOD UnlockRegion, :ptr IMarshalingStream, :ULARGE_INTEGER, :ULARGE_INTEGER, :DWORD
            STD_METHOD Stat, :ptr IMarshalingStream, :ptr STATSTG, :DWORD
            STD_METHOD Clone, :ptr IMarshalingStream, :ptr ptr IStream
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
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
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
              STD_METHOD QueryInterface, :ptr IAgileReference, :REFIID, :ptr ptr
              STD_METHOD AddRef, :ptr IAgileReference
              STD_METHOD Release, :ptr IAgileReference
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
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      externdef IID_ICallbackWithNoReentrancyToApplicationSTA:GUID
    endif
    _OBJIDLBASE_ equ <>
  endif
  if (_MSC_VER ge 800)
    if _MSC_VER ge 1200
    else
    endif
  endif
  externdef __MIDL_itf_objidlbase_0000_0053_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_objidlbase_0000_0053_v0_0_s_ifspec:RPC_IF_HANDLE
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

