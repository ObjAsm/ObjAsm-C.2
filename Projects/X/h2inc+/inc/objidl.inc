;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\objidl.h
;             Created on (UTC) 06/04/2024 06:15:57
;             Last modified on (UTC) 21/02/2024 18:18:08

;* verify that the <rpcndr.h> version is high enough to compile this file*
ifndef __REQUIRED_RPCNDR_H_VERSION__
  __REQUIRED_RPCNDR_H_VERSION__ equ 501
endif
;* verify that the <rpcsal.h> version is high enough to compile this file*
ifndef __REQUIRED_RPCSAL_H_VERSION__
  __REQUIRED_RPCSAL_H_VERSION__ equ 100
endif
include rpc.inc
include rpcndr.inc
ifndef __RPCNDR_H_VERSION__
  .err <this stub requires an updated version of < rpcndr.h >>
  ;* __RPCNDR_H_VERSION__ *
endif
ifndef COM_NO_WINDOWS_H
  include windows.inc
  include ole2.inc
  ;*COM_NO_WINDOWS_H*
endif
ifndef __objidl_h__
  __objidl_h__ equ <>
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
  ;* Forward Declarations *
  ifndef __IMarshal_FWD_DEFINED__
    __IMarshal_FWD_DEFINED__ equ <>
    ;* __IMarshal_FWD_DEFINED__ *
  endif
  ifndef __INoMarshal_FWD_DEFINED__
    __INoMarshal_FWD_DEFINED__ equ <>
    ;* __INoMarshal_FWD_DEFINED__ *
  endif
  ifndef __IAgileObject_FWD_DEFINED__
    __IAgileObject_FWD_DEFINED__ equ <>
    ;* __IAgileObject_FWD_DEFINED__ *
  endif
  ifndef __IActivationFilter_FWD_DEFINED__
    __IActivationFilter_FWD_DEFINED__ equ <>
    ;* __IActivationFilter_FWD_DEFINED__ *
  endif
  ifndef __IMarshal2_FWD_DEFINED__
    __IMarshal2_FWD_DEFINED__ equ <>
    ;* __IMarshal2_FWD_DEFINED__ *
  endif
  ifndef __IMalloc_FWD_DEFINED__
    __IMalloc_FWD_DEFINED__ equ <>
    ;* __IMalloc_FWD_DEFINED__ *
  endif
  ifndef __IStdMarshalInfo_FWD_DEFINED__
    __IStdMarshalInfo_FWD_DEFINED__ equ <>
    ;* __IStdMarshalInfo_FWD_DEFINED__ *
  endif
  ifndef __IExternalConnection_FWD_DEFINED__
    __IExternalConnection_FWD_DEFINED__ equ <>
    ;* __IExternalConnection_FWD_DEFINED__ *
  endif
  ifndef __IMultiQI_FWD_DEFINED__
    __IMultiQI_FWD_DEFINED__ equ <>
    ;* __IMultiQI_FWD_DEFINED__ *
  endif
  ifndef __AsyncIMultiQI_FWD_DEFINED__
    __AsyncIMultiQI_FWD_DEFINED__ equ <>
    ;* __AsyncIMultiQI_FWD_DEFINED__ *
  endif
  ifndef __IInternalUnknown_FWD_DEFINED__
    __IInternalUnknown_FWD_DEFINED__ equ <>
    ;* __IInternalUnknown_FWD_DEFINED__ *
  endif
  ifndef __IEnumUnknown_FWD_DEFINED__
    __IEnumUnknown_FWD_DEFINED__ equ <>
    ;* __IEnumUnknown_FWD_DEFINED__ *
  endif
  ifndef __IEnumString_FWD_DEFINED__
    __IEnumString_FWD_DEFINED__ equ <>
    ;* __IEnumString_FWD_DEFINED__ *
  endif
  ifndef __ISequentialStream_FWD_DEFINED__
    __ISequentialStream_FWD_DEFINED__ equ <>
    ;* __ISequentialStream_FWD_DEFINED__ *
  endif
  ifndef __IStream_FWD_DEFINED__
    __IStream_FWD_DEFINED__ equ <>
    ;* __IStream_FWD_DEFINED__ *
  endif
  ifndef __IRpcChannelBuffer_FWD_DEFINED__
    __IRpcChannelBuffer_FWD_DEFINED__ equ <>
    ;* __IRpcChannelBuffer_FWD_DEFINED__ *
  endif
  ifndef __IRpcChannelBuffer2_FWD_DEFINED__
    __IRpcChannelBuffer2_FWD_DEFINED__ equ <>
    ;* __IRpcChannelBuffer2_FWD_DEFINED__ *
  endif
  ifndef __IAsyncRpcChannelBuffer_FWD_DEFINED__
    __IAsyncRpcChannelBuffer_FWD_DEFINED__ equ <>
    ;* __IAsyncRpcChannelBuffer_FWD_DEFINED__ *
  endif
  ifndef __IRpcChannelBuffer3_FWD_DEFINED__
    __IRpcChannelBuffer3_FWD_DEFINED__ equ <>
    ;* __IRpcChannelBuffer3_FWD_DEFINED__ *
  endif
  ifndef __IRpcSyntaxNegotiate_FWD_DEFINED__
    __IRpcSyntaxNegotiate_FWD_DEFINED__ equ <>
    ;* __IRpcSyntaxNegotiate_FWD_DEFINED__ *
  endif
  ifndef __IRpcProxyBuffer_FWD_DEFINED__
    __IRpcProxyBuffer_FWD_DEFINED__ equ <>
    ;* __IRpcProxyBuffer_FWD_DEFINED__ *
  endif
  ifndef __IRpcStubBuffer_FWD_DEFINED__
    __IRpcStubBuffer_FWD_DEFINED__ equ <>
    ;* __IRpcStubBuffer_FWD_DEFINED__ *
  endif
  ifndef __IPSFactoryBuffer_FWD_DEFINED__
    __IPSFactoryBuffer_FWD_DEFINED__ equ <>
    ;* __IPSFactoryBuffer_FWD_DEFINED__ *
  endif
  ifndef __IChannelHook_FWD_DEFINED__
    __IChannelHook_FWD_DEFINED__ equ <>
    ;* __IChannelHook_FWD_DEFINED__ *
  endif
  ifndef __IClientSecurity_FWD_DEFINED__
    __IClientSecurity_FWD_DEFINED__ equ <>
    ;* __IClientSecurity_FWD_DEFINED__ *
  endif
  ifndef __IServerSecurity_FWD_DEFINED__
    __IServerSecurity_FWD_DEFINED__ equ <>
    ;* __IServerSecurity_FWD_DEFINED__ *
  endif
  ifndef __IRpcOptions_FWD_DEFINED__
    __IRpcOptions_FWD_DEFINED__ equ <>
    ;* __IRpcOptions_FWD_DEFINED__ *
  endif
  ifndef __IGlobalOptions_FWD_DEFINED__
    __IGlobalOptions_FWD_DEFINED__ equ <>
    ;* __IGlobalOptions_FWD_DEFINED__ *
  endif
  ifndef __ISurrogate_FWD_DEFINED__
    __ISurrogate_FWD_DEFINED__ equ <>
    ;* __ISurrogate_FWD_DEFINED__ *
  endif
  ifndef __IGlobalInterfaceTable_FWD_DEFINED__
    __IGlobalInterfaceTable_FWD_DEFINED__ equ <>
    ;* __IGlobalInterfaceTable_FWD_DEFINED__ *
  endif
  ifndef __ISynchronize_FWD_DEFINED__
    __ISynchronize_FWD_DEFINED__ equ <>
    ;* __ISynchronize_FWD_DEFINED__ *
  endif
  ifndef __ISynchronizeHandle_FWD_DEFINED__
    __ISynchronizeHandle_FWD_DEFINED__ equ <>
    ;* __ISynchronizeHandle_FWD_DEFINED__ *
  endif
  ifndef __ISynchronizeEvent_FWD_DEFINED__
    __ISynchronizeEvent_FWD_DEFINED__ equ <>
    ;* __ISynchronizeEvent_FWD_DEFINED__ *
  endif
  ifndef __ISynchronizeContainer_FWD_DEFINED__
    __ISynchronizeContainer_FWD_DEFINED__ equ <>
    ;* __ISynchronizeContainer_FWD_DEFINED__ *
  endif
  ifndef __ISynchronizeMutex_FWD_DEFINED__
    __ISynchronizeMutex_FWD_DEFINED__ equ <>
    ;* __ISynchronizeMutex_FWD_DEFINED__ *
  endif
  ifndef __ICancelMethodCalls_FWD_DEFINED__
    __ICancelMethodCalls_FWD_DEFINED__ equ <>
    ;* __ICancelMethodCalls_FWD_DEFINED__ *
  endif
  ifndef __IAsyncManager_FWD_DEFINED__
    __IAsyncManager_FWD_DEFINED__ equ <>
    ;* __IAsyncManager_FWD_DEFINED__ *
  endif
  ifndef __ICallFactory_FWD_DEFINED__
    __ICallFactory_FWD_DEFINED__ equ <>
    ;* __ICallFactory_FWD_DEFINED__ *
  endif
  ifndef __IRpcHelper_FWD_DEFINED__
    __IRpcHelper_FWD_DEFINED__ equ <>
    ;* __IRpcHelper_FWD_DEFINED__ *
  endif
  ifndef __IReleaseMarshalBuffers_FWD_DEFINED__
    __IReleaseMarshalBuffers_FWD_DEFINED__ equ <>
    ;* __IReleaseMarshalBuffers_FWD_DEFINED__ *
  endif
  ifndef __IWaitMultiple_FWD_DEFINED__
    __IWaitMultiple_FWD_DEFINED__ equ <>
    ;* __IWaitMultiple_FWD_DEFINED__ *
  endif
  ifndef __IAddrTrackingControl_FWD_DEFINED__
    __IAddrTrackingControl_FWD_DEFINED__ equ <>
    ;* __IAddrTrackingControl_FWD_DEFINED__ *
  endif
  ifndef __IAddrExclusionControl_FWD_DEFINED__
    __IAddrExclusionControl_FWD_DEFINED__ equ <>
    ;* __IAddrExclusionControl_FWD_DEFINED__ *
  endif
  ifndef __IPipeByte_FWD_DEFINED__
    __IPipeByte_FWD_DEFINED__ equ <>
    ;* __IPipeByte_FWD_DEFINED__ *
  endif
  ifndef __AsyncIPipeByte_FWD_DEFINED__
    __AsyncIPipeByte_FWD_DEFINED__ equ <>
    ;* __AsyncIPipeByte_FWD_DEFINED__ *
  endif
  ifndef __IPipeLong_FWD_DEFINED__
    __IPipeLong_FWD_DEFINED__ equ <>
    ;* __IPipeLong_FWD_DEFINED__ *
  endif
  ifndef __AsyncIPipeLong_FWD_DEFINED__
    __AsyncIPipeLong_FWD_DEFINED__ equ <>
    ;* __AsyncIPipeLong_FWD_DEFINED__ *
  endif
  ifndef __IPipeDouble_FWD_DEFINED__
    __IPipeDouble_FWD_DEFINED__ equ <>
    ;* __IPipeDouble_FWD_DEFINED__ *
  endif
  ifndef __AsyncIPipeDouble_FWD_DEFINED__
    __AsyncIPipeDouble_FWD_DEFINED__ equ <>
    ;* __AsyncIPipeDouble_FWD_DEFINED__ *
  endif
  ifndef __IEnumContextProps_FWD_DEFINED__
    __IEnumContextProps_FWD_DEFINED__ equ <>
    ;* __IEnumContextProps_FWD_DEFINED__ *
  endif
  ifndef __IContext_FWD_DEFINED__
    __IContext_FWD_DEFINED__ equ <>
    ;* __IContext_FWD_DEFINED__ *
  endif
  ifndef __IObjContext_FWD_DEFINED__
    __IObjContext_FWD_DEFINED__ equ <>
    ;* __IObjContext_FWD_DEFINED__ *
  endif
  ifndef __IComThreadingInfo_FWD_DEFINED__
    __IComThreadingInfo_FWD_DEFINED__ equ <>
    ;* __IComThreadingInfo_FWD_DEFINED__ *
  endif
  ifndef __IProcessInitControl_FWD_DEFINED__
    __IProcessInitControl_FWD_DEFINED__ equ <>
    ;* __IProcessInitControl_FWD_DEFINED__ *
  endif
  ifndef __IFastRundown_FWD_DEFINED__
    __IFastRundown_FWD_DEFINED__ equ <>
    ;* __IFastRundown_FWD_DEFINED__ *
  endif
  ifndef __IMarshalingStream_FWD_DEFINED__
    __IMarshalingStream_FWD_DEFINED__ equ <>
    ;* __IMarshalingStream_FWD_DEFINED__ *
  endif
  ifndef __IAgileReference_FWD_DEFINED__
    __IAgileReference_FWD_DEFINED__ equ <>
    ;* __IAgileReference_FWD_DEFINED__ *
  endif
  ifndef __IMachineGlobalObjectTable_FWD_DEFINED__
    __IMachineGlobalObjectTable_FWD_DEFINED__ equ <>
    ;* __IMachineGlobalObjectTable_FWD_DEFINED__ *
  endif
  ifndef __ISupportAllowLowerTrustActivation_FWD_DEFINED__
    __ISupportAllowLowerTrustActivation_FWD_DEFINED__ equ <>
    ;* __ISupportAllowLowerTrustActivation_FWD_DEFINED__ *
  endif
  ifndef __IMallocSpy_FWD_DEFINED__
    __IMallocSpy_FWD_DEFINED__ equ <>
    ;* __IMallocSpy_FWD_DEFINED__ *
  endif
  ifndef __IBindCtx_FWD_DEFINED__
    __IBindCtx_FWD_DEFINED__ equ <>
    ;* __IBindCtx_FWD_DEFINED__ *
  endif
  ifndef __IEnumMoniker_FWD_DEFINED__
    __IEnumMoniker_FWD_DEFINED__ equ <>
    ;* __IEnumMoniker_FWD_DEFINED__ *
  endif
  ifndef __IRunnableObject_FWD_DEFINED__
    __IRunnableObject_FWD_DEFINED__ equ <>
    ;* __IRunnableObject_FWD_DEFINED__ *
  endif
  ifndef __IRunningObjectTable_FWD_DEFINED__
    __IRunningObjectTable_FWD_DEFINED__ equ <>
    ;* __IRunningObjectTable_FWD_DEFINED__ *
  endif
  ifndef __IPersist_FWD_DEFINED__
    __IPersist_FWD_DEFINED__ equ <>
    ;* __IPersist_FWD_DEFINED__ *
  endif
  ifndef __IPersistStream_FWD_DEFINED__
    __IPersistStream_FWD_DEFINED__ equ <>
    ;* __IPersistStream_FWD_DEFINED__ *
  endif
  ifndef __IMoniker_FWD_DEFINED__
    __IMoniker_FWD_DEFINED__ equ <>
    ;* __IMoniker_FWD_DEFINED__ *
  endif
  ifndef __IROTData_FWD_DEFINED__
    __IROTData_FWD_DEFINED__ equ <>
    ;* __IROTData_FWD_DEFINED__ *
  endif
  ifndef __IEnumSTATSTG_FWD_DEFINED__
    __IEnumSTATSTG_FWD_DEFINED__ equ <>
    ;* __IEnumSTATSTG_FWD_DEFINED__ *
  endif
  ifndef __IStorage_FWD_DEFINED__
    __IStorage_FWD_DEFINED__ equ <>
    ;* __IStorage_FWD_DEFINED__ *
  endif
  ifndef __IPersistFile_FWD_DEFINED__
    __IPersistFile_FWD_DEFINED__ equ <>
    ;* __IPersistFile_FWD_DEFINED__ *
  endif
  ifndef __IPersistStorage_FWD_DEFINED__
    __IPersistStorage_FWD_DEFINED__ equ <>
    ;* __IPersistStorage_FWD_DEFINED__ *
  endif
  ifndef __ILockBytes_FWD_DEFINED__
    __ILockBytes_FWD_DEFINED__ equ <>
    ;* __ILockBytes_FWD_DEFINED__ *
  endif
  ifndef __IEnumFORMATETC_FWD_DEFINED__
    __IEnumFORMATETC_FWD_DEFINED__ equ <>
    ;* __IEnumFORMATETC_FWD_DEFINED__ *
  endif
  ifndef __IEnumSTATDATA_FWD_DEFINED__
    __IEnumSTATDATA_FWD_DEFINED__ equ <>
    ;* __IEnumSTATDATA_FWD_DEFINED__ *
  endif
  ifndef __IRootStorage_FWD_DEFINED__
    __IRootStorage_FWD_DEFINED__ equ <>
    ;* __IRootStorage_FWD_DEFINED__ *
  endif
  ifndef __IAdviseSink_FWD_DEFINED__
    __IAdviseSink_FWD_DEFINED__ equ <>
    ;* __IAdviseSink_FWD_DEFINED__ *
  endif
  ifndef __AsyncIAdviseSink_FWD_DEFINED__
    __AsyncIAdviseSink_FWD_DEFINED__ equ <>
    ;* __AsyncIAdviseSink_FWD_DEFINED__ *
  endif
  ifndef __IAdviseSink2_FWD_DEFINED__
    __IAdviseSink2_FWD_DEFINED__ equ <>
    ;* __IAdviseSink2_FWD_DEFINED__ *
  endif
  ifndef __AsyncIAdviseSink2_FWD_DEFINED__
    __AsyncIAdviseSink2_FWD_DEFINED__ equ <>
    ;* __AsyncIAdviseSink2_FWD_DEFINED__ *
  endif
  ifndef __IDataObject_FWD_DEFINED__
    __IDataObject_FWD_DEFINED__ equ <>
    ;* __IDataObject_FWD_DEFINED__ *
  endif
  ifndef __IDataAdviseHolder_FWD_DEFINED__
    __IDataAdviseHolder_FWD_DEFINED__ equ <>
    ;* __IDataAdviseHolder_FWD_DEFINED__ *
  endif
  ifndef __IMessageFilter_FWD_DEFINED__
    __IMessageFilter_FWD_DEFINED__ equ <>
    ;* __IMessageFilter_FWD_DEFINED__ *
  endif
  ifndef __IClassActivator_FWD_DEFINED__
    __IClassActivator_FWD_DEFINED__ equ <>
    ;* __IClassActivator_FWD_DEFINED__ *
  endif
  ifndef __IFillLockBytes_FWD_DEFINED__
    __IFillLockBytes_FWD_DEFINED__ equ <>
    ;* __IFillLockBytes_FWD_DEFINED__ *
  endif
  ifndef __IProgressNotify_FWD_DEFINED__
    __IProgressNotify_FWD_DEFINED__ equ <>
    ;* __IProgressNotify_FWD_DEFINED__ *
  endif
  ifndef __ILayoutStorage_FWD_DEFINED__
    __ILayoutStorage_FWD_DEFINED__ equ <>
    ;* __ILayoutStorage_FWD_DEFINED__ *
  endif
  ifndef __IBlockingLock_FWD_DEFINED__
    __IBlockingLock_FWD_DEFINED__ equ <>
    ;* __IBlockingLock_FWD_DEFINED__ *
  endif
  ifndef __ITimeAndNoticeControl_FWD_DEFINED__
    __ITimeAndNoticeControl_FWD_DEFINED__ equ <>
    ;* __ITimeAndNoticeControl_FWD_DEFINED__ *
  endif
  ifndef __IOplockStorage_FWD_DEFINED__
    __IOplockStorage_FWD_DEFINED__ equ <>
    ;* __IOplockStorage_FWD_DEFINED__ *
  endif
  ifndef __IDirectWriterLock_FWD_DEFINED__
    __IDirectWriterLock_FWD_DEFINED__ equ <>
    ;* __IDirectWriterLock_FWD_DEFINED__ *
  endif
  ifndef __IUrlMon_FWD_DEFINED__
    __IUrlMon_FWD_DEFINED__ equ <>
    ;* __IUrlMon_FWD_DEFINED__ *
  endif
  ifndef __IForegroundTransfer_FWD_DEFINED__
    __IForegroundTransfer_FWD_DEFINED__ equ <>
    ;* __IForegroundTransfer_FWD_DEFINED__ *
  endif
  ifndef __IThumbnailExtractor_FWD_DEFINED__
    __IThumbnailExtractor_FWD_DEFINED__ equ <>
    ;* __IThumbnailExtractor_FWD_DEFINED__ *
  endif
  ifndef __IDummyHICONIncluder_FWD_DEFINED__
    __IDummyHICONIncluder_FWD_DEFINED__ equ <>
    ;* __IDummyHICONIncluder_FWD_DEFINED__ *
  endif
  ifndef __IProcessLock_FWD_DEFINED__
    __IProcessLock_FWD_DEFINED__ equ <>
    ;* __IProcessLock_FWD_DEFINED__ *
  endif
  ifndef __ISurrogateService_FWD_DEFINED__
    __ISurrogateService_FWD_DEFINED__ equ <>
    ;* __ISurrogateService_FWD_DEFINED__ *
  endif
  ifndef __IInitializeSpy_FWD_DEFINED__
    __IInitializeSpy_FWD_DEFINED__ equ <>
    ;* __IInitializeSpy_FWD_DEFINED__ *
  endif
  ifndef __IApartmentShutdown_FWD_DEFINED__
    __IApartmentShutdown_FWD_DEFINED__ equ <>
    ;* __IApartmentShutdown_FWD_DEFINED__ *
  endif
  ;* header files for imported files *
  include unknwn.inc
  ifdef __cplusplus
    ;[...]
  endif
  ;* interface __MIDL_itf_objidl_0000_0000 *
  ;* [local] *
  include winapifamily.inc
  ;+-------------------------------------------------------------------------
  ;+-------------------------------------------------------------------------
  ;  Microsoft Windows
  ;  Copyright (c) Microsoft Corporation. All rights reserved.
  ;--------------------------------------------------------------------------
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
      ;* padding added after data member *
    endif
  endif
  if (_MSC_VER ge 1020)
  endif
  include winapifamily.inc
  ;+-------------------------------------------------------------------------
  ;+-------------------------------------------------------------------------
  ;  Microsoft Windows
  ;  Copyright (c) Microsoft Corporation. All rights reserved.
  ;--------------------------------------------------------------------------
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
        ;* truncation of constant value *
      endif
      ;* padding added after data member *
    endif
  endif
  if (_MSC_VER ge 1020)
  endif
  include limits.inc
  ifndef _OBJIDLBASE_
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      COSERVERINFO struct
        dwReserved1 DWORD ?
        pwszName POINTER ?
        pAuthInfo POINTER ?
        dwReserved2 DWORD ?
      COSERVERINFO ends
      _COSERVERINFO typedef COSERVERINFO
      externdef __MIDL_itf_objidl_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_objidl_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IMarshal_INTERFACE_DEFINED__
        __IMarshal_INTERFACE_DEFINED__ equ <>
        ;* interface IMarshal *
        ;* [uuid][object][local] *
        ;* [unique] *
        LPMARSHAL typedef ptr IMarshal
        externdef IID_IMarshal:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IMarshalVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IMarshalVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IMarshal, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IMarshal
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IMarshal
            DECLSPEC_XFGVIRT(IMarshal, GetUnmarshalClass)
            ;* [annotation][in] *
            ;* [annotation][unique][in] *
            ;* [annotation][in] *
            ;* [annotation][unique][in] *
            ;* [annotation][in] *
            ;* [annotation][out] *
            STD_METHOD GetUnmarshalClass, :ptr IMarshal, :REFIID, :ptr, :DWORD, :ptr, :DWORD, :ptr CLSID
            DECLSPEC_XFGVIRT(IMarshal, GetMarshalSizeMax)
            ;* [annotation][in] *
            ;* [annotation][unique][in] *
            ;* [annotation][in] *
            ;* [annotation][unique][in] *
            ;* [annotation][in] *
            ;* [annotation][out] *
            STD_METHOD GetMarshalSizeMax, :ptr IMarshal, :REFIID, :ptr, :DWORD, :ptr, :DWORD, :ptr DWORD
            DECLSPEC_XFGVIRT(IMarshal, MarshalInterface)
            ;* [annotation][unique][in] *
            ;* [annotation][in] *
            ;* [annotation][unique][in] *
            ;* [annotation][in] *
            ;* [annotation][unique][in] *
            ;* [annotation][in] *
            STD_METHOD MarshalInterface, :ptr IMarshal, :ptr IStream, :REFIID, :ptr, :DWORD, :ptr, :DWORD
            DECLSPEC_XFGVIRT(IMarshal, UnmarshalInterface)
            ;* [annotation][unique][in] *
            ;* [annotation][in] *
            ;* [annotation][out] *
            STD_METHOD UnmarshalInterface, :ptr IMarshal, :ptr IStream, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IMarshal, ReleaseMarshalData)
            ;* [annotation][unique][in] *
            STD_METHOD ReleaseMarshalData, :ptr IMarshal, :ptr IStream
            DECLSPEC_XFGVIRT(IMarshal, DisconnectObject)
            ;* [annotation][in] *
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
          ;* C style interface *
        endif
        ;* __IMarshal_INTERFACE_DEFINED__ *
      endif
      ifndef __INoMarshal_INTERFACE_DEFINED__
        __INoMarshal_INTERFACE_DEFINED__ equ <>
        ;* interface INoMarshal *
        ;* [uuid][object][local] *
        externdef IID_INoMarshal:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          INoMarshalVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <INoMarshalVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
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
          ;* C style interface *
        endif
        ;* __INoMarshal_INTERFACE_DEFINED__ *
      endif
      ifndef __IAgileObject_INTERFACE_DEFINED__
        __IAgileObject_INTERFACE_DEFINED__ equ <>
        ;* interface IAgileObject *
        ;* [uuid][object][local] *
        externdef IID_IAgileObject:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IAgileObjectVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IAgileObjectVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
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
          ;* C style interface *
        endif
        ;* __IAgileObject_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_objidl_0000_0003 *
      ;* [local] *
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      externdef __MIDL_itf_objidl_0000_0003_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_objidl_0000_0003_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IActivationFilter_INTERFACE_DEFINED__
        __IActivationFilter_INTERFACE_DEFINED__ equ <>
        ;* interface IActivationFilter *
        ;* [uuid][object][local] *
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
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IActivationFilter, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IActivationFilter
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IActivationFilter
            DECLSPEC_XFGVIRT(IActivationFilter, HandleActivation)
            ;* [in] *
            ;* [in] *
            STD_METHOD HandleActivation, :ptr IActivationFilter, :DWORD, :REFCLSID, :ptr CLSID
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IActivationFilterVtbl ends
          IActivationFilter struct
            lpVtbl POINTER ?
          IActivationFilter ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IActivationFilter_INTERFACE_DEFINED__ *
      endif
      ifndef __IMarshal2_INTERFACE_DEFINED__
        __IMarshal2_INTERFACE_DEFINED__ equ <>
        ;* interface IMarshal2 *
        ;* [uuid][object][local] *
        ;* [unique] *
        LPMARSHAL2 typedef ptr IMarshal2
        externdef IID_IMarshal2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IMarshal2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IMarshal2Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IMarshal2, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IMarshal2
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IMarshal2
            DECLSPEC_XFGVIRT(IMarshal, GetUnmarshalClass)
            ;* [annotation][in] *
            ;* [annotation][unique][in] *
            ;* [annotation][in] *
            ;* [annotation][unique][in] *
            ;* [annotation][in] *
            ;* [annotation][out] *
            STD_METHOD GetUnmarshalClass, :ptr IMarshal2, :REFIID, :ptr, :DWORD, :ptr, :DWORD, :ptr CLSID
            DECLSPEC_XFGVIRT(IMarshal, GetMarshalSizeMax)
            ;* [annotation][in] *
            ;* [annotation][unique][in] *
            ;* [annotation][in] *
            ;* [annotation][unique][in] *
            ;* [annotation][in] *
            ;* [annotation][out] *
            STD_METHOD GetMarshalSizeMax, :ptr IMarshal2, :REFIID, :ptr, :DWORD, :ptr, :DWORD, :ptr DWORD
            DECLSPEC_XFGVIRT(IMarshal, MarshalInterface)
            ;* [annotation][unique][in] *
            ;* [annotation][in] *
            ;* [annotation][unique][in] *
            ;* [annotation][in] *
            ;* [annotation][unique][in] *
            ;* [annotation][in] *
            STD_METHOD MarshalInterface, :ptr IMarshal2, :ptr IStream, :REFIID, :ptr, :DWORD, :ptr, :DWORD
            DECLSPEC_XFGVIRT(IMarshal, UnmarshalInterface)
            ;* [annotation][unique][in] *
            ;* [annotation][in] *
            ;* [annotation][out] *
            STD_METHOD UnmarshalInterface, :ptr IMarshal2, :ptr IStream, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IMarshal, ReleaseMarshalData)
            ;* [annotation][unique][in] *
            STD_METHOD ReleaseMarshalData, :ptr IMarshal2, :ptr IStream
            DECLSPEC_XFGVIRT(IMarshal, DisconnectObject)
            ;* [annotation][in] *
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
          ;* C style interface *
        endif
        ;* __IMarshal2_INTERFACE_DEFINED__ *
      endif
      ifndef __IMalloc_INTERFACE_DEFINED__
        __IMalloc_INTERFACE_DEFINED__ equ <>
        ;* interface IMalloc *
        ;* [uuid][object][local] *
        ;* [unique] *
        LPMALLOC typedef ptr IMalloc
        externdef IID_IMalloc:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IMallocVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IMallocVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IMalloc, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IMalloc
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IMalloc
            DECLSPEC_XFGVIRT(IMalloc, Alloc)
            ;* [annotation][in] *
            STD_METHOD Alloc, :ptr IMalloc, :SIZE_T
            DECLSPEC_XFGVIRT(IMalloc, Realloc)
            ;* [annotation][in] *
            ;* [annotation][in] *
            STD_METHOD Realloc, :ptr IMalloc, :ptr, :SIZE_T
            DECLSPEC_XFGVIRT(IMalloc, Free)
            ;* [annotation][in] *
            STD_METHOD Free, :ptr IMalloc, :ptr
            DECLSPEC_XFGVIRT(IMalloc, GetSize)
            ;* [annotation][in] *
            STD_METHOD GetSize, :ptr IMalloc, :ptr
            DECLSPEC_XFGVIRT(IMalloc, DidAlloc)
            ;* [annotation][in] *
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
          ;* C style interface *
        endif
        ;* __IMalloc_INTERFACE_DEFINED__ *
      endif
      ifndef __IStdMarshalInfo_INTERFACE_DEFINED__
        __IStdMarshalInfo_INTERFACE_DEFINED__ equ <>
        ;* interface IStdMarshalInfo *
        ;* [uuid][object][local] *
        ;* [unique] *
        LPSTDMARSHALINFO typedef ptr IStdMarshalInfo
        externdef IID_IStdMarshalInfo:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IStdMarshalInfoVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IStdMarshalInfoVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IStdMarshalInfo, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IStdMarshalInfo
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IStdMarshalInfo
            DECLSPEC_XFGVIRT(IStdMarshalInfo, GetClassForHandler)
            ;* [annotation][in] *
            ;* [annotation][unique][in] *
            ;* [annotation][out] *
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
          ;* C style interface *
        endif
        ;* __IStdMarshalInfo_INTERFACE_DEFINED__ *
      endif
      ifndef __IExternalConnection_INTERFACE_DEFINED__
        __IExternalConnection_INTERFACE_DEFINED__ equ <>
        ;* interface IExternalConnection *
        ;* [uuid][local][object] *
        ;* [unique] *
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
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IExternalConnection, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IExternalConnection
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IExternalConnection
            DECLSPEC_XFGVIRT(IExternalConnection, AddConnection)
            ;* [annotation][in] *
            ;* [annotation][in] *
            STD_METHOD AddConnection, :ptr IExternalConnection, :DWORD, :DWORD
            DECLSPEC_XFGVIRT(IExternalConnection, ReleaseConnection)
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
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
          ;* C style interface *
        endif
        ;* __IExternalConnection_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_objidl_0000_0008 *
      ;* [local] *
      ;* [unique] *
      LPMULTIQI typedef ptr IMultiQI
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      MULTI_QI struct
        pIID POINTER ?
        pItf POINTER ?
        hr HRESULT ?
      MULTI_QI ends
      tagMULTI_QI typedef MULTI_QI
      externdef __MIDL_itf_objidl_0000_0008_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_objidl_0000_0008_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IMultiQI_INTERFACE_DEFINED__
        __IMultiQI_INTERFACE_DEFINED__ equ <>
        ;* interface IMultiQI *
        ;* [async_uuid][uuid][local][object] *
        externdef IID_IMultiQI:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IMultiQIVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IMultiQIVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IMultiQI, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IMultiQI
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IMultiQI
            DECLSPEC_XFGVIRT(IMultiQI, QueryMultipleInterfaces)
            ;* [annotation][in] *
            ;* [annotation][out][in] *
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
          ;* C style interface *
        endif
        ;* __IMultiQI_INTERFACE_DEFINED__ *
      endif
      ifndef __AsyncIMultiQI_INTERFACE_DEFINED__
        __AsyncIMultiQI_INTERFACE_DEFINED__ equ <>
        ;* interface AsyncIMultiQI *
        ;* [uuid][local][object] *
        externdef IID_AsyncIMultiQI:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          AsyncIMultiQIVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <AsyncIMultiQIVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr AsyncIMultiQI, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr AsyncIMultiQI
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr AsyncIMultiQI
            DECLSPEC_XFGVIRT(AsyncIMultiQI, Begin_QueryMultipleInterfaces)
            ;* [annotation][in] *
            ;* [annotation][out][in] *
            STD_METHOD Begin_QueryMultipleInterfaces, :ptr AsyncIMultiQI, :ULONG, :ptr MULTI_QI
            DECLSPEC_XFGVIRT(AsyncIMultiQI, Finish_QueryMultipleInterfaces)
            ;* [annotation][out][in] *
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
          ;* C style interface *
        endif
        ;* __AsyncIMultiQI_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_objidl_0000_0009 *
      ;* [local] *
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      externdef __MIDL_itf_objidl_0000_0009_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_objidl_0000_0009_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IInternalUnknown_INTERFACE_DEFINED__
        __IInternalUnknown_INTERFACE_DEFINED__ equ <>
        ;* interface IInternalUnknown *
        ;* [uuid][local][object] *
        externdef IID_IInternalUnknown:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IInternalUnknownVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IInternalUnknownVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IInternalUnknown, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IInternalUnknown
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IInternalUnknown
            DECLSPEC_XFGVIRT(IInternalUnknown, QueryInternalInterface)
            ;* [annotation][in] *
            ;* [annotation][out] *
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
          ;* C style interface *
        endif
        ;* __IInternalUnknown_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_objidl_0000_0010 *
      ;* [local] *
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      externdef __MIDL_itf_objidl_0000_0010_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_objidl_0000_0010_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IEnumUnknown_INTERFACE_DEFINED__
        __IEnumUnknown_INTERFACE_DEFINED__ equ <>
        ;* interface IEnumUnknown *
        ;* [unique][uuid][object] *
        ;* [unique] *
        LPENUMUNKNOWN typedef ptr IEnumUnknown
        externdef IID_IEnumUnknown:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IEnumUnknownVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEnumUnknownVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IEnumUnknown, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IEnumUnknown
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IEnumUnknown
            DECLSPEC_XFGVIRT(IEnumUnknown, Next)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD Next, :ptr IEnumUnknown, :ULONG, :ptr ptr IUnknown, :ptr ULONG
            DECLSPEC_XFGVIRT(IEnumUnknown, Skip)
            STD_METHOD Skip, :ptr IEnumUnknown, :ULONG
            ;* [in] *
            DECLSPEC_XFGVIRT(IEnumUnknown, Reset)
            STD_METHOD Reset, :ptr IEnumUnknown
            DECLSPEC_XFGVIRT(IEnumUnknown, Clone)
            STD_METHOD Clone, :ptr IEnumUnknown, :ptr ptr IEnumUnknown
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IEnumUnknownVtbl ends
          IEnumUnknown struct
            lpVtbl POINTER ?
          IEnumUnknown ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* [call_as] *
        IEnumUnknown_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumUnknown, :ULONG, :ptr ptr IUnknown, :ptr ULONG
        ;* [out] *
        IEnumUnknown_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        ;* __IEnumUnknown_INTERFACE_DEFINED__ *
      endif
      ifndef __IEnumString_INTERFACE_DEFINED__
        __IEnumString_INTERFACE_DEFINED__ equ <>
        ;* interface IEnumString *
        ;* [unique][uuid][object] *
        ;* [unique] *
        LPENUMSTRING typedef ptr IEnumString
        externdef IID_IEnumString:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IEnumStringVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEnumStringVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IEnumString, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IEnumString
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IEnumString
            DECLSPEC_XFGVIRT(IEnumString, Next)
            ;* [local] *
            ;* [in] *
            ;* [annotation] *
            ;* [annotation] *
            STD_METHOD Next, :ptr IEnumString, :ULONG, :ptr LPOLESTR, :ptr ULONG
            DECLSPEC_XFGVIRT(IEnumString, Skip)
            STD_METHOD Skip, :ptr IEnumString, :ULONG
            ;* [in] *
            DECLSPEC_XFGVIRT(IEnumString, Reset)
            STD_METHOD Reset, :ptr IEnumString
            DECLSPEC_XFGVIRT(IEnumString, Clone)
            STD_METHOD Clone, :ptr IEnumString, :ptr ptr IEnumString
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IEnumStringVtbl ends
          IEnumString struct
            lpVtbl POINTER ?
          IEnumString ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* [call_as] *
        IEnumString_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumString, :ULONG, :ptr LPOLESTR, :ptr ULONG
        ;* [out] *
        IEnumString_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        ;* __IEnumString_INTERFACE_DEFINED__ *
      endif
      ifndef __ISequentialStream_INTERFACE_DEFINED__
        __ISequentialStream_INTERFACE_DEFINED__ equ <>
        ;* interface ISequentialStream *
        ;* [unique][uuid][object] *
        externdef IID_ISequentialStream:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISequentialStreamVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISequentialStreamVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISequentialStream, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISequentialStream
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISequentialStream
            DECLSPEC_XFGVIRT(ISequentialStream, Read)
            ;* [local] *
            ;* [annotation] *
            ;* [annotation][in] *
            ;* [annotation] *
            STD_METHOD Read, :ptr ISequentialStream, :ptr, :ULONG, :ptr ULONG
            DECLSPEC_XFGVIRT(ISequentialStream, Write)
            ;* [local] *
            ;* [annotation] *
            ;* [annotation][in] *
            ;* [annotation] *
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
          ;* C style interface *
        endif
        ;* [call_as] *
        ISequentialStream_RemoteRead_Proxy proto WIN_STD_CALL_CONV :ptr ISequentialStream, :ptr byte, :ULONG, :ptr ULONG
        ;* [out] *
        ISequentialStream_RemoteRead_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        ;* [call_as] *
        ISequentialStream_RemoteWrite_Proxy proto WIN_STD_CALL_CONV :ptr ISequentialStream, :ptr byte, :ULONG, :ptr ULONG
        ;* [out] *
        ISequentialStream_RemoteWrite_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        ;* __ISequentialStream_INTERFACE_DEFINED__ *
      endif
      ifndef __IStream_INTERFACE_DEFINED__
        __IStream_INTERFACE_DEFINED__ equ <>
        ;* interface IStream *
        ;* [unique][uuid][object] *
        ;* [unique] *
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
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IStream, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IStream
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IStream
            DECLSPEC_XFGVIRT(ISequentialStream, Read)
            ;* [local] *
            ;* [annotation] *
            ;* [annotation][in] *
            ;* [annotation] *
            STD_METHOD Read, :ptr IStream, :ptr, :ULONG, :ptr ULONG
            DECLSPEC_XFGVIRT(ISequentialStream, Write)
            ;* [local] *
            ;* [annotation] *
            ;* [annotation][in] *
            ;* [annotation] *
            STD_METHOD Write, :ptr IStream, :ptr, :ULONG, :ptr ULONG
            DECLSPEC_XFGVIRT(IStream, Seek)
            ;* [local] *
            ;* [in] *
            ;* [in] *
            ;* [annotation] *
            STD_METHOD Seek, :ptr IStream, :LARGE_INTEGER, :DWORD, :ptr ULARGE_INTEGER
            DECLSPEC_XFGVIRT(IStream, SetSize)
            STD_METHOD SetSize, :ptr IStream, :ULARGE_INTEGER
            ;* [in] *
            DECLSPEC_XFGVIRT(IStream, CopyTo)
            ;* [local] *
            ;* [annotation][unique][in] *
            ;* [in] *
            ;* [annotation] *
            ;* [annotation] *
            STD_METHOD CopyTo, :ptr IStream, :ptr IStream, :ULARGE_INTEGER, :ptr ULARGE_INTEGER, :ptr ULARGE_INTEGER
            DECLSPEC_XFGVIRT(IStream, Commit)
            STD_METHOD Commit, :ptr IStream, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IStream, Revert)
            STD_METHOD Revert, :ptr IStream
            DECLSPEC_XFGVIRT(IStream, LockRegion)
            ;* [in] *
            ;* [in] *
            STD_METHOD LockRegion, :ptr IStream, :ULARGE_INTEGER, :ULARGE_INTEGER, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IStream, UnlockRegion)
            ;* [in] *
            ;* [in] *
            STD_METHOD UnlockRegion, :ptr IStream, :ULARGE_INTEGER, :ULARGE_INTEGER, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IStream, Stat)
            ;* [out] *
            STD_METHOD Stat, :ptr IStream, :ptr STATSTG, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IStream, Clone)
            STD_METHOD Clone, :ptr IStream, :ptr ptr IStream
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IStreamVtbl ends
          IStream struct
            lpVtbl POINTER ?
          IStream ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* [call_as] *
        IStream_RemoteSeek_Proxy proto WIN_STD_CALL_CONV :ptr IStream, :LARGE_INTEGER, :DWORD, :ptr ULARGE_INTEGER
        ;* [out] *
        IStream_RemoteSeek_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        ;* [call_as] *
        IStream_RemoteCopyTo_Proxy proto WIN_STD_CALL_CONV :ptr IStream, :ptr IStream, :ULARGE_INTEGER, :ptr ULARGE_INTEGER, :ptr ULARGE_INTEGER
        ;* [out] *
        IStream_RemoteCopyTo_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        ;* __IStream_INTERFACE_DEFINED__ *
      endif
      ifndef __IRpcChannelBuffer_INTERFACE_DEFINED__
        __IRpcChannelBuffer_INTERFACE_DEFINED__ equ <>
        ;* interface IRpcChannelBuffer *
        ;* [uuid][object][local] *
        RPCOLEDATAREP typedef ULONG
        RPCOLEMESSAGE struct
          reserved1 POINTER ?
          dataRepresentation RPCOLEDATAREP ?
          Buffer POINTER ?
          cbBuffer DWORD ?
          iMethod DWORD ?
          reserved2 POINTER 5 dup (?)
          rpcFlags DWORD ?
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
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IRpcChannelBuffer, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IRpcChannelBuffer
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IRpcChannelBuffer
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, GetBuffer)
            ;* [annotation][out][in] *
            ;* [annotation][in] *
            STD_METHOD GetBuffer, :ptr IRpcChannelBuffer, :ptr RPCOLEMESSAGE, :REFIID
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, SendReceive)
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            STD_METHOD SendReceive, :ptr IRpcChannelBuffer, :ptr RPCOLEMESSAGE, :ptr ULONG
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, FreeBuffer)
            ;* [annotation][out][in] *
            STD_METHOD FreeBuffer, :ptr IRpcChannelBuffer, :ptr RPCOLEMESSAGE
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, GetDestCtx)
            ;* [annotation][out] *
            ;* [annotation][out] *
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
          ;* C style interface *
        endif
        ;* __IRpcChannelBuffer_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_objidl_0000_0015 *
      ;* [local] *
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      externdef __MIDL_itf_objidl_0000_0015_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_objidl_0000_0015_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IRpcChannelBuffer2_INTERFACE_DEFINED__
        __IRpcChannelBuffer2_INTERFACE_DEFINED__ equ <>
        ;* interface IRpcChannelBuffer2 *
        ;* [uuid][object][local] *
        externdef IID_IRpcChannelBuffer2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IRpcChannelBuffer2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IRpcChannelBuffer2Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IRpcChannelBuffer2, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IRpcChannelBuffer2
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IRpcChannelBuffer2
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, GetBuffer)
            ;* [annotation][out][in] *
            ;* [annotation][in] *
            STD_METHOD GetBuffer, :ptr IRpcChannelBuffer2, :ptr RPCOLEMESSAGE, :REFIID
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, SendReceive)
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            STD_METHOD SendReceive, :ptr IRpcChannelBuffer2, :ptr RPCOLEMESSAGE, :ptr ULONG
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, FreeBuffer)
            ;* [annotation][out][in] *
            STD_METHOD FreeBuffer, :ptr IRpcChannelBuffer2, :ptr RPCOLEMESSAGE
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, GetDestCtx)
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD GetDestCtx, :ptr IRpcChannelBuffer2, :ptr DWORD, :ptr ptr
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, IsConnected)
            STD_METHOD IsConnected, :ptr IRpcChannelBuffer2
            DECLSPEC_XFGVIRT(IRpcChannelBuffer2, GetProtocolVersion)
            ;* [annotation][out] *
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
          ;* C style interface *
        endif
        ;* __IRpcChannelBuffer2_INTERFACE_DEFINED__ *
      endif
      ifndef __IAsyncRpcChannelBuffer_INTERFACE_DEFINED__
        __IAsyncRpcChannelBuffer_INTERFACE_DEFINED__ equ <>
        ;* interface IAsyncRpcChannelBuffer *
        ;* [unique][uuid][object][local] *
        externdef IID_IAsyncRpcChannelBuffer:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IAsyncRpcChannelBufferVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IAsyncRpcChannelBufferVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IAsyncRpcChannelBuffer, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IAsyncRpcChannelBuffer
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IAsyncRpcChannelBuffer
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, GetBuffer)
            ;* [annotation][out][in] *
            ;* [annotation][in] *
            STD_METHOD GetBuffer, :ptr IAsyncRpcChannelBuffer, :ptr RPCOLEMESSAGE, :REFIID
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, SendReceive)
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            STD_METHOD SendReceive, :ptr IAsyncRpcChannelBuffer, :ptr RPCOLEMESSAGE, :ptr ULONG
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, FreeBuffer)
            ;* [annotation][out][in] *
            STD_METHOD FreeBuffer, :ptr IAsyncRpcChannelBuffer, :ptr RPCOLEMESSAGE
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, GetDestCtx)
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD GetDestCtx, :ptr IAsyncRpcChannelBuffer, :ptr DWORD, :ptr ptr
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, IsConnected)
            STD_METHOD IsConnected, :ptr IAsyncRpcChannelBuffer
            DECLSPEC_XFGVIRT(IRpcChannelBuffer2, GetProtocolVersion)
            ;* [annotation][out] *
            STD_METHOD GetProtocolVersion, :ptr IAsyncRpcChannelBuffer, :ptr DWORD
            DECLSPEC_XFGVIRT(IAsyncRpcChannelBuffer, Send)
            ;* [annotation][out][in] *
            ;* [annotation][in] *
            ;* [annotation][out] *
            STD_METHOD Send, :ptr IAsyncRpcChannelBuffer, :ptr RPCOLEMESSAGE, :ptr ISynchronize, :ptr ULONG
            DECLSPEC_XFGVIRT(IAsyncRpcChannelBuffer, Receive)
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            STD_METHOD Receive, :ptr IAsyncRpcChannelBuffer, :ptr RPCOLEMESSAGE, :ptr ULONG
            DECLSPEC_XFGVIRT(IAsyncRpcChannelBuffer, GetDestCtxEx)
            ;* [annotation][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
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
          ;* C style interface *
        endif
        ;* __IAsyncRpcChannelBuffer_INTERFACE_DEFINED__ *
      endif
      ifndef __IRpcChannelBuffer3_INTERFACE_DEFINED__
        __IRpcChannelBuffer3_INTERFACE_DEFINED__ equ <>
        ;* interface IRpcChannelBuffer3 *
        ;* [uuid][object][local] *
        externdef IID_IRpcChannelBuffer3:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IRpcChannelBuffer3Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IRpcChannelBuffer3Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IRpcChannelBuffer3, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IRpcChannelBuffer3
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IRpcChannelBuffer3
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, GetBuffer)
            ;* [annotation][out][in] *
            ;* [annotation][in] *
            STD_METHOD GetBuffer, :ptr IRpcChannelBuffer3, :ptr RPCOLEMESSAGE, :REFIID
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, SendReceive)
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            STD_METHOD SendReceive, :ptr IRpcChannelBuffer3, :ptr RPCOLEMESSAGE, :ptr ULONG
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, FreeBuffer)
            ;* [annotation][out][in] *
            STD_METHOD FreeBuffer, :ptr IRpcChannelBuffer3, :ptr RPCOLEMESSAGE
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, GetDestCtx)
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD GetDestCtx, :ptr IRpcChannelBuffer3, :ptr DWORD, :ptr ptr
            DECLSPEC_XFGVIRT(IRpcChannelBuffer, IsConnected)
            STD_METHOD IsConnected, :ptr IRpcChannelBuffer3
            DECLSPEC_XFGVIRT(IRpcChannelBuffer2, GetProtocolVersion)
            ;* [annotation][out] *
            STD_METHOD GetProtocolVersion, :ptr IRpcChannelBuffer3, :ptr DWORD
            DECLSPEC_XFGVIRT(IRpcChannelBuffer3, Send)
            ;* [annotation][out][in] *
            ;* [annotation][out] *
            STD_METHOD Send, :ptr IRpcChannelBuffer3, :ptr RPCOLEMESSAGE, :ptr ULONG
            DECLSPEC_XFGVIRT(IRpcChannelBuffer3, Receive)
            ;* [annotation][out][in] *
            ;* [annotation][in] *
            ;* [annotation][out] *
            STD_METHOD Receive, :ptr IRpcChannelBuffer3, :ptr RPCOLEMESSAGE, :ULONG, :ptr ULONG
            DECLSPEC_XFGVIRT(IRpcChannelBuffer3, Cancel)
            ;* [annotation][out][in] *
            STD_METHOD Cancel, :ptr IRpcChannelBuffer3, :ptr RPCOLEMESSAGE
            DECLSPEC_XFGVIRT(IRpcChannelBuffer3, GetCallContext)
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out] *
            STD_METHOD GetCallContext, :ptr IRpcChannelBuffer3, :ptr RPCOLEMESSAGE, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IRpcChannelBuffer3, GetDestCtxEx)
            ;* [annotation][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD GetDestCtxEx, :ptr IRpcChannelBuffer3, :ptr RPCOLEMESSAGE, :ptr DWORD, :ptr ptr
            DECLSPEC_XFGVIRT(IRpcChannelBuffer3, GetState)
            ;* [annotation][in] *
            ;* [annotation][out] *
            STD_METHOD GetState, :ptr IRpcChannelBuffer3, :ptr RPCOLEMESSAGE, :ptr DWORD
            DECLSPEC_XFGVIRT(IRpcChannelBuffer3, RegisterAsync)
            ;* [annotation][out][in] *
            ;* [annotation][in] *
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
          ;* C style interface *
        endif
        ;* __IRpcChannelBuffer3_INTERFACE_DEFINED__ *
      endif
      ifndef __IRpcSyntaxNegotiate_INTERFACE_DEFINED__
        __IRpcSyntaxNegotiate_INTERFACE_DEFINED__ equ <>
        ;* interface IRpcSyntaxNegotiate *
        ;* [uuid][object][local] *
        externdef IID_IRpcSyntaxNegotiate:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IRpcSyntaxNegotiateVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IRpcSyntaxNegotiateVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IRpcSyntaxNegotiate, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IRpcSyntaxNegotiate
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IRpcSyntaxNegotiate
            DECLSPEC_XFGVIRT(IRpcSyntaxNegotiate, NegotiateSyntax)
            ;* [annotation][out][in] *
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
          ;* C style interface *
        endif
        ;* __IRpcSyntaxNegotiate_INTERFACE_DEFINED__ *
      endif
      ifndef __IRpcProxyBuffer_INTERFACE_DEFINED__
        __IRpcProxyBuffer_INTERFACE_DEFINED__ equ <>
        ;* interface IRpcProxyBuffer *
        ;* [uuid][object][local] *
        externdef IID_IRpcProxyBuffer:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IRpcProxyBufferVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IRpcProxyBufferVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IRpcProxyBuffer, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IRpcProxyBuffer
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IRpcProxyBuffer
            DECLSPEC_XFGVIRT(IRpcProxyBuffer, Connect)
            ;* [annotation][unique][in] *
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
          ;* C style interface *
        endif
        ;* __IRpcProxyBuffer_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_objidl_0000_0020 *
      ;* [local] *
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      externdef __MIDL_itf_objidl_0000_0020_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_objidl_0000_0020_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IRpcStubBuffer_INTERFACE_DEFINED__
        __IRpcStubBuffer_INTERFACE_DEFINED__ equ <>
        ;* interface IRpcStubBuffer *
        ;* [uuid][object][local] *
        externdef IID_IRpcStubBuffer:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IRpcStubBufferVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IRpcStubBufferVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IRpcStubBuffer, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IRpcStubBuffer
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IRpcStubBuffer
            DECLSPEC_XFGVIRT(IRpcStubBuffer, Connect)
            ;* [annotation][in] *
            STD_METHOD Connect, :ptr IRpcStubBuffer, :ptr IUnknown
            DECLSPEC_XFGVIRT(IRpcStubBuffer, Disconnect)
            STD_METHOD Disconnect, :ptr IRpcStubBuffer
            DECLSPEC_XFGVIRT(IRpcStubBuffer, Invoke)
            ;* [annotation][out][in] *
            ;* [annotation][in] *
            STD_METHOD Invoke_, :ptr IRpcStubBuffer, :ptr RPCOLEMESSAGE, :ptr IRpcChannelBuffer
            DECLSPEC_XFGVIRT(IRpcStubBuffer, IsIIDSupported)
            ;* [annotation][in] *
            STD_METHOD IsIIDSupported, :ptr IRpcStubBuffer, :REFIID
            DECLSPEC_XFGVIRT(IRpcStubBuffer, CountRefs)
            STD_METHOD CountRefs, :ptr IRpcStubBuffer
            DECLSPEC_XFGVIRT(IRpcStubBuffer, DebugServerQueryInterface)
            ;* [annotation][out] *
            STD_METHOD DebugServerQueryInterface, :ptr IRpcStubBuffer, :ptr ptr
            DECLSPEC_XFGVIRT(IRpcStubBuffer, DebugServerRelease)
            ;* [annotation][in] *
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
          ;* C style interface *
        endif
        ;* __IRpcStubBuffer_INTERFACE_DEFINED__ *
      endif
      ifndef __IPSFactoryBuffer_INTERFACE_DEFINED__
        __IPSFactoryBuffer_INTERFACE_DEFINED__ equ <>
        ;* interface IPSFactoryBuffer *
        ;* [uuid][object][local] *
        externdef IID_IPSFactoryBuffer:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IPSFactoryBufferVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IPSFactoryBufferVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IPSFactoryBuffer, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IPSFactoryBuffer
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IPSFactoryBuffer
            DECLSPEC_XFGVIRT(IPSFactoryBuffer, CreateProxy)
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD CreateProxy, :ptr IPSFactoryBuffer, :ptr IUnknown, :REFIID, :ptr ptr IRpcProxyBuffer, :ptr ptr
            DECLSPEC_XFGVIRT(IPSFactoryBuffer, CreateStub)
            ;* [annotation][in] *
            ;* [annotation][unique][in] *
            ;* [annotation][out] *
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
          ;* C style interface *
        endif
        ;* __IPSFactoryBuffer_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_objidl_0000_0022 *
      ;* [local] *
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      if (_WIN32_WINNT ge 0400h) or Defined(_WIN32_DCOM)
        ; This interface is only valid on Windows NT 4.0
        SChannelHookCallInfo struct
          iid IID <>
          cbSize DWORD ?
          uCausality GUID <>
          dwServerPid DWORD ?
          iMethod DWORD ?
          pObject POINTER ?
        SChannelHookCallInfo ends
        externdef __MIDL_itf_objidl_0000_0022_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_objidl_0000_0022_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IChannelHook_INTERFACE_DEFINED__
          __IChannelHook_INTERFACE_DEFINED__ equ <>
          ;* interface IChannelHook *
          ;* [uuid][object][local] *
          externdef IID_IChannelHook:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IChannelHookVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IChannelHookVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              ;* [in] *
              ;* [annotation][iid_is][out] *
              STD_METHOD QueryInterface, :ptr IChannelHook, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IChannelHook
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IChannelHook
              DECLSPEC_XFGVIRT(IChannelHook, ClientGetSize)
              ;* [annotation][in] *
              ;* [annotation][in] *
              ;* [annotation][out] *
              STD_METHOD ClientGetSize, :ptr IChannelHook, :REFGUID, :REFIID, :ptr ULONG
              DECLSPEC_XFGVIRT(IChannelHook, ClientFillBuffer)
              ;* [annotation][in] *
              ;* [annotation][in] *
              ;* [annotation][out][in] *
              ;* [annotation][in] *
              STD_METHOD ClientFillBuffer, :ptr IChannelHook, :REFGUID, :REFIID, :ptr ULONG, :ptr
              DECLSPEC_XFGVIRT(IChannelHook, ClientNotify)
              ;* [annotation][in] *
              ;* [annotation][in] *
              ;* [annotation][in] *
              ;* [annotation][in] *
              ;* [annotation][in] *
              ;* [annotation][in] *
              STD_METHOD ClientNotify, :ptr IChannelHook, :REFGUID, :REFIID, :ULONG, :ptr, :DWORD, :HRESULT
              DECLSPEC_XFGVIRT(IChannelHook, ServerNotify)
              ;* [annotation][in] *
              ;* [annotation][in] *
              ;* [annotation][in] *
              ;* [annotation][in] *
              ;* [annotation][in] *
              STD_METHOD ServerNotify, :ptr IChannelHook, :REFGUID, :REFIID, :ULONG, :ptr, :DWORD
              DECLSPEC_XFGVIRT(IChannelHook, ServerGetSize)
              ;* [annotation][in] *
              ;* [annotation][in] *
              ;* [annotation][in] *
              ;* [annotation][out] *
              STD_METHOD ServerGetSize, :ptr IChannelHook, :REFGUID, :REFIID, :HRESULT, :ptr ULONG
              DECLSPEC_XFGVIRT(IChannelHook, ServerFillBuffer)
              ;* [annotation][in] *
              ;* [annotation][in] *
              ;* [annotation][out][in] *
              ;* [annotation][in] *
              ;* [annotation][in] *
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
            ;* C style interface *
          endif
          ;* __IChannelHook_INTERFACE_DEFINED__ *
        endif
        ;* interface __MIDL_itf_objidl_0000_0023 *
        ;* [local] *
      endif
      ;DCOM
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if (_WIN32_WINNT ge 0400h) or Defined(_WIN32_DCOM)
      ; This interface is only valid on Windows NT 4.0
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
        externdef __MIDL_itf_objidl_0000_0023_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_objidl_0000_0023_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IClientSecurity_INTERFACE_DEFINED__
          __IClientSecurity_INTERFACE_DEFINED__ equ <>
          ;* interface IClientSecurity *
          ;* [uuid][object][local] *
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
              ;* [in] *
              ;* [annotation][iid_is][out] *
              STD_METHOD QueryInterface, :ptr IClientSecurity, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IClientSecurity
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IClientSecurity
              DECLSPEC_XFGVIRT(IClientSecurity, QueryBlanket)
              ;* [annotation][in] *
              ;* [annotation][out] *
              ;* [annotation][out] *
              ;* [annotation][out] *
              ;* [annotation][out] *
              ;* [annotation][out] *
              ;* [annotation][out] *
              ;* [annotation][out] *
              STD_METHOD QueryBlanket, :ptr IClientSecurity, :ptr IUnknown, :ptr DWORD, :ptr DWORD, :ptr ptr OLECHAR, :ptr DWORD, :ptr DWORD, :ptr ptr, :ptr DWORD
              DECLSPEC_XFGVIRT(IClientSecurity, SetBlanket)
              ;* [annotation][in] *
              ;* [annotation][in] *
              ;* [annotation][in] *
              ;* [annotation][in] *
              ;* [annotation][in] *
              ;* [annotation][in] *
              ;* [annotation][in] *
              ;* [annotation][in] *
              STD_METHOD SetBlanket, :ptr IClientSecurity, :ptr IUnknown, :DWORD, :DWORD, :ptr OLECHAR, :DWORD, :DWORD, :ptr, :DWORD
              DECLSPEC_XFGVIRT(IClientSecurity, CopyProxy)
              ;* [annotation][in] *
              ;* [annotation][out] *
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
            ;* C style interface *
          endif
          ;* __IClientSecurity_INTERFACE_DEFINED__ *
        endif
        ;* interface __MIDL_itf_objidl_0000_0024 *
        ;* [local] *
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
        externdef __MIDL_itf_objidl_0000_0024_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_objidl_0000_0024_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IServerSecurity_INTERFACE_DEFINED__
          __IServerSecurity_INTERFACE_DEFINED__ equ <>
          ;* interface IServerSecurity *
          ;* [uuid][object][local] *
          externdef IID_IServerSecurity:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IServerSecurityVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IServerSecurityVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              ;* [in] *
              ;* [annotation][iid_is][out] *
              STD_METHOD QueryInterface, :ptr IServerSecurity, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IServerSecurity
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IServerSecurity
              DECLSPEC_XFGVIRT(IServerSecurity, QueryBlanket)
              ;* [annotation][out] *
              ;* [annotation][out] *
              ;* [annotation][out] *
              ;* [annotation][out] *
              ;* [annotation][out] *
              ;* [annotation][out] *
              ;* [annotation][out][in] *
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
            ;* C style interface *
          endif
          ;* __IServerSecurity_INTERFACE_DEFINED__ *
        endif
        ;* interface __MIDL_itf_objidl_0000_0025 *
        ;* [local] *
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

        externdef __MIDL_itf_objidl_0000_0025_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_objidl_0000_0025_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IRpcOptions_INTERFACE_DEFINED__
          __IRpcOptions_INTERFACE_DEFINED__ equ <>
          ;* interface IRpcOptions *
          ;* [uuid][local][object] *
          externdef IID_IRpcOptions:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IRpcOptionsVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IRpcOptionsVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              ;* [in] *
              ;* [annotation][iid_is][out] *
              STD_METHOD QueryInterface, :ptr IRpcOptions, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IRpcOptions
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IRpcOptions
              DECLSPEC_XFGVIRT(IRpcOptions, Set)
              ;* [annotation][in] *
              ;* [annotation][in] *
              ;* [annotation][in] *
              STD_METHOD Set, :ptr IRpcOptions, :ptr IUnknown, :RPCOPT_PROPERTIES, :ULONG_PTR
              DECLSPEC_XFGVIRT(IRpcOptions, Query)
              ;* [annotation][in] *
              ;* [annotation][in] *
              ;* [annotation][out] *
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
            ;* C style interface *
          endif
          ;* __IRpcOptions_INTERFACE_DEFINED__ *
        endif
        ;* interface __MIDL_itf_objidl_0000_0026 *
        ;* [local] *
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
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

        externdef __MIDL_itf_objidl_0000_0026_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_objidl_0000_0026_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IGlobalOptions_INTERFACE_DEFINED__
          __IGlobalOptions_INTERFACE_DEFINED__ equ <>
          ;* interface IGlobalOptions *
          ;* [uuid][unique][local][object] *
          externdef IID_IGlobalOptions:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IGlobalOptionsVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IGlobalOptionsVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              ;* [in] *
              ;* [annotation][iid_is][out] *
              STD_METHOD QueryInterface, :ptr IGlobalOptions, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IGlobalOptions
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IGlobalOptions
              DECLSPEC_XFGVIRT(IGlobalOptions, Set)
              ;* [annotation][in] *
              ;* [annotation][in] *
              STD_METHOD Set, :ptr IGlobalOptions, :GLOBALOPT_PROPERTIES, :ULONG_PTR
              DECLSPEC_XFGVIRT(IGlobalOptions, Query)
              ;* [annotation][in] *
              ;* [annotation][out] *
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
            ;* C style interface *
          endif
          ;* __IGlobalOptions_INTERFACE_DEFINED__ *
        endif
        ;* interface __MIDL_itf_objidl_0000_0027 *
        ;* [local] *
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
      endif
    endif
    ;DCOM
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      externdef __MIDL_itf_objidl_0000_0027_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_objidl_0000_0027_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ISurrogate_INTERFACE_DEFINED__
        __ISurrogate_INTERFACE_DEFINED__ equ <>
        ;* interface ISurrogate *
        ;* [object][unique][version][uuid] *
        ;* [unique] *
        LPSURROGATE typedef ptr ISurrogate
        externdef IID_ISurrogate:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISurrogateVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISurrogateVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISurrogate, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISurrogate
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISurrogate
            DECLSPEC_XFGVIRT(ISurrogate, LoadDllServer)
            STD_METHOD LoadDllServer, :ptr ISurrogate, :REFCLSID
            ;* [in] *
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
          ;* C style interface *
        endif
        ;* __ISurrogate_INTERFACE_DEFINED__ *
      endif
      ifndef __IGlobalInterfaceTable_INTERFACE_DEFINED__
        __IGlobalInterfaceTable_INTERFACE_DEFINED__ equ <>
        ;* interface IGlobalInterfaceTable *
        ;* [uuid][object][local] *
        ;* [unique] *
        LPGLOBALINTERFACETABLE typedef ptr IGlobalInterfaceTable
        externdef IID_IGlobalInterfaceTable:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IGlobalInterfaceTableVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IGlobalInterfaceTableVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IGlobalInterfaceTable, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IGlobalInterfaceTable
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IGlobalInterfaceTable
            DECLSPEC_XFGVIRT(IGlobalInterfaceTable, RegisterInterfaceInGlobal)
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out] *
            STD_METHOD RegisterInterfaceInGlobal, :ptr IGlobalInterfaceTable, :ptr IUnknown, :REFIID, :ptr DWORD
            DECLSPEC_XFGVIRT(IGlobalInterfaceTable, RevokeInterfaceFromGlobal)
            ;* [annotation][in] *
            STD_METHOD RevokeInterfaceFromGlobal, :ptr IGlobalInterfaceTable, :DWORD
            DECLSPEC_XFGVIRT(IGlobalInterfaceTable, GetInterfaceFromGlobal)
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][iid_is][out] *
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
          ;* C style interface *
        endif
        ;* __IGlobalInterfaceTable_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_objidl_0000_0029 *
      ;* [local] *
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      externdef __MIDL_itf_objidl_0000_0029_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_objidl_0000_0029_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ISynchronize_INTERFACE_DEFINED__
        __ISynchronize_INTERFACE_DEFINED__ equ <>
        ;* interface ISynchronize *
        ;* [uuid][object] *
        externdef IID_ISynchronize:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISynchronizeVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISynchronizeVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISynchronize, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISynchronize
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISynchronize
            DECLSPEC_XFGVIRT(ISynchronize, Wait)
            ;* [in] *
            STD_METHOD Wait_, :ptr ISynchronize, :DWORD, :DWORD
            ;* [in] *
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
          ;* C style interface *
        endif
        ;* __ISynchronize_INTERFACE_DEFINED__ *
      endif
      ifndef __ISynchronizeHandle_INTERFACE_DEFINED__
        __ISynchronizeHandle_INTERFACE_DEFINED__ equ <>
        ;* interface ISynchronizeHandle *
        ;* [uuid][object][local] *
        externdef IID_ISynchronizeHandle:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISynchronizeHandleVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISynchronizeHandleVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISynchronizeHandle, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISynchronizeHandle
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISynchronizeHandle
            DECLSPEC_XFGVIRT(ISynchronizeHandle, GetHandle)
            ;* [annotation][out] *
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
          ;* C style interface *
        endif
        ;* __ISynchronizeHandle_INTERFACE_DEFINED__ *
      endif
      ifndef __ISynchronizeEvent_INTERFACE_DEFINED__
        __ISynchronizeEvent_INTERFACE_DEFINED__ equ <>
        ;* interface ISynchronizeEvent *
        ;* [uuid][object][local] *
        externdef IID_ISynchronizeEvent:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISynchronizeEventVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISynchronizeEventVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISynchronizeEvent, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISynchronizeEvent
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISynchronizeEvent
            DECLSPEC_XFGVIRT(ISynchronizeHandle, GetHandle)
            ;* [annotation][out] *
            STD_METHOD GetHandle, :ptr ISynchronizeEvent, :ptr HANDLE
            DECLSPEC_XFGVIRT(ISynchronizeEvent, SetEventHandle)
            ;* [annotation][in] *
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
          ;* C style interface *
        endif
        ;* __ISynchronizeEvent_INTERFACE_DEFINED__ *
      endif
      ifndef __ISynchronizeContainer_INTERFACE_DEFINED__
        __ISynchronizeContainer_INTERFACE_DEFINED__ equ <>
        ;* interface ISynchronizeContainer *
        ;* [uuid][object][local] *
        externdef IID_ISynchronizeContainer:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISynchronizeContainerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISynchronizeContainerVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISynchronizeContainer, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISynchronizeContainer
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISynchronizeContainer
            DECLSPEC_XFGVIRT(ISynchronizeContainer, AddSynchronize)
            ;* [annotation][in] *
            STD_METHOD AddSynchronize, :ptr ISynchronizeContainer, :ptr ISynchronize
            DECLSPEC_XFGVIRT(ISynchronizeContainer, WaitMultiple)
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out] *
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
          ;* C style interface *
        endif
        ;* __ISynchronizeContainer_INTERFACE_DEFINED__ *
      endif
      ifndef __ISynchronizeMutex_INTERFACE_DEFINED__
        __ISynchronizeMutex_INTERFACE_DEFINED__ equ <>
        ;* interface ISynchronizeMutex *
        ;* [uuid][object][local] *
        externdef IID_ISynchronizeMutex:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISynchronizeMutexVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISynchronizeMutexVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISynchronizeMutex, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISynchronizeMutex
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISynchronizeMutex
            DECLSPEC_XFGVIRT(ISynchronize, Wait)
            ;* [in] *
            STD_METHOD Wait_, :ptr ISynchronizeMutex, :DWORD, :DWORD
            ;* [in] *
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
          ;* C style interface *
        endif
        ;* __ISynchronizeMutex_INTERFACE_DEFINED__ *
      endif
      ifndef __ICancelMethodCalls_INTERFACE_DEFINED__
        __ICancelMethodCalls_INTERFACE_DEFINED__ equ <>
        ;* interface ICancelMethodCalls *
        ;* [uuid][object][local] *
        ;* [unique] *
        LPCANCELMETHODCALLS typedef ptr ICancelMethodCalls
        externdef IID_ICancelMethodCalls:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ICancelMethodCallsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ICancelMethodCallsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ICancelMethodCalls, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ICancelMethodCalls
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ICancelMethodCalls
            DECLSPEC_XFGVIRT(ICancelMethodCalls, Cancel)
            ;* [annotation][in] *
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
          ;* C style interface *
        endif
        ;* __ICancelMethodCalls_INTERFACE_DEFINED__ *
      endif
      ifndef __IAsyncManager_INTERFACE_DEFINED__
        __IAsyncManager_INTERFACE_DEFINED__ equ <>
        ;* interface IAsyncManager *
        ;* [uuid][object][local] *
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
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IAsyncManager, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IAsyncManager
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IAsyncManager
            DECLSPEC_XFGVIRT(IAsyncManager, CompleteCall)
            ;* [annotation][in] *
            STD_METHOD CompleteCall, :ptr IAsyncManager, :HRESULT
            DECLSPEC_XFGVIRT(IAsyncManager, GetCallContext)
            ;* [annotation][in] *
            ;* [annotation][out] *
            STD_METHOD GetCallContext, :ptr IAsyncManager, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IAsyncManager, GetState)
            ;* [annotation][out] *
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
          ;* C style interface *
        endif
        ;* __IAsyncManager_INTERFACE_DEFINED__ *
      endif
      ifndef __ICallFactory_INTERFACE_DEFINED__
        __ICallFactory_INTERFACE_DEFINED__ equ <>
        ;* interface ICallFactory *
        ;* [unique][uuid][object][local] *
        externdef IID_ICallFactory:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ICallFactoryVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ICallFactoryVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ICallFactory, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ICallFactory
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ICallFactory
            DECLSPEC_XFGVIRT(ICallFactory, CreateCall)
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][iid_is][out] *
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
          ;* C style interface *
        endif
        ;* __ICallFactory_INTERFACE_DEFINED__ *
      endif
      ifndef __IRpcHelper_INTERFACE_DEFINED__
        __IRpcHelper_INTERFACE_DEFINED__ equ <>
        ;* interface IRpcHelper *
        ;* [object][local][unique][version][uuid] *
        externdef IID_IRpcHelper:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IRpcHelperVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IRpcHelperVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IRpcHelper, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IRpcHelper
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IRpcHelper
            DECLSPEC_XFGVIRT(IRpcHelper, GetDCOMProtocolVersion)
            ;* [annotation][out] *
            STD_METHOD GetDCOMProtocolVersion, :ptr IRpcHelper, :ptr DWORD
            DECLSPEC_XFGVIRT(IRpcHelper, GetIIDFromOBJREF)
            ;* [annotation][in] *
            ;* [annotation][out] *
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
          ;* C style interface *
        endif
        ;* __IRpcHelper_INTERFACE_DEFINED__ *
      endif
      ifndef __IReleaseMarshalBuffers_INTERFACE_DEFINED__
        __IReleaseMarshalBuffers_INTERFACE_DEFINED__ equ <>
        ;* interface IReleaseMarshalBuffers *
        ;* [uuid][object][local] *
        externdef IID_IReleaseMarshalBuffers:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IReleaseMarshalBuffersVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IReleaseMarshalBuffersVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IReleaseMarshalBuffers, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IReleaseMarshalBuffers
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IReleaseMarshalBuffers
            DECLSPEC_XFGVIRT(IReleaseMarshalBuffers, ReleaseMarshalBuffer)
            ;* [annotation][out][in] *
            ;* [annotation][in] *
            ;* [annotation][unique][in] *
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
          ;* C style interface *
        endif
        ;* __IReleaseMarshalBuffers_INTERFACE_DEFINED__ *
      endif
      ifndef __IWaitMultiple_INTERFACE_DEFINED__
        __IWaitMultiple_INTERFACE_DEFINED__ equ <>
        ;* interface IWaitMultiple *
        ;* [uuid][object][local] *
        externdef IID_IWaitMultiple:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IWaitMultipleVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IWaitMultipleVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IWaitMultiple, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IWaitMultiple
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IWaitMultiple
            DECLSPEC_XFGVIRT(IWaitMultiple, WaitMultiple)
            ;* [annotation][in] *
            ;* [annotation][out] *
            STD_METHOD WaitMultiple, :ptr IWaitMultiple, :DWORD, :ptr ptr ISynchronize
            DECLSPEC_XFGVIRT(IWaitMultiple, AddSynchronize)
            ;* [annotation][in] *
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
          ;* C style interface *
        endif
        ;* __IWaitMultiple_INTERFACE_DEFINED__ *
      endif
      ifndef __IAddrTrackingControl_INTERFACE_DEFINED__
        __IAddrTrackingControl_INTERFACE_DEFINED__ equ <>
        ;* interface IAddrTrackingControl *
        ;* [uuid][object][local] *
        ;* [unique] *
        LPADDRTRACKINGCONTROL typedef ptr IAddrTrackingControl
        externdef IID_IAddrTrackingControl:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IAddrTrackingControlVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IAddrTrackingControlVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
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
          ;* C style interface *
        endif
        ;* __IAddrTrackingControl_INTERFACE_DEFINED__ *
      endif
      ifndef __IAddrExclusionControl_INTERFACE_DEFINED__
        __IAddrExclusionControl_INTERFACE_DEFINED__ equ <>
        ;* interface IAddrExclusionControl *
        ;* [uuid][object][local] *
        ;* [unique] *
        LPADDREXCLUSIONCONTROL typedef ptr IAddrExclusionControl
        externdef IID_IAddrExclusionControl:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IAddrExclusionControlVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IAddrExclusionControlVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IAddrExclusionControl, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IAddrExclusionControl
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IAddrExclusionControl
            DECLSPEC_XFGVIRT(IAddrExclusionControl, GetCurrentAddrExclusionList)
            ;* [annotation][in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD GetCurrentAddrExclusionList, :ptr IAddrExclusionControl, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IAddrExclusionControl, UpdateAddrExclusionList)
            ;* [annotation][in] *
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
          ;* C style interface *
        endif
        ;* __IAddrExclusionControl_INTERFACE_DEFINED__ *
      endif
      ifndef __IPipeByte_INTERFACE_DEFINED__
        __IPipeByte_INTERFACE_DEFINED__ equ <>
        ;* interface IPipeByte *
        ;* [unique][async_uuid][uuid][object] *
        externdef IID_IPipeByte:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IPipeByteVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IPipeByteVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IPipeByte, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IPipeByte
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IPipeByte
            DECLSPEC_XFGVIRT(IPipeByte, Pull)
            ;* [length_is][size_is][out] *
            ;* [in] *
            STD_METHOD Pull, :ptr IPipeByte, :ptr BYTE, :ULONG, :ptr ULONG
            ;* [out] *
            DECLSPEC_XFGVIRT(IPipeByte, Push)
            ;* [size_is][in] *
            STD_METHOD Push_, :ptr IPipeByte, :ptr BYTE, :ULONG
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IPipeByteVtbl ends
          IPipeByte struct
            lpVtbl POINTER ?
          IPipeByte ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IPipeByte_INTERFACE_DEFINED__ *
      endif
      ifndef __AsyncIPipeByte_INTERFACE_DEFINED__
        __AsyncIPipeByte_INTERFACE_DEFINED__ equ <>
        ;* interface AsyncIPipeByte *
        ;* [uuid][unique][object] *
        externdef IID_AsyncIPipeByte:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          AsyncIPipeByteVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <AsyncIPipeByteVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr AsyncIPipeByte, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr AsyncIPipeByte
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr AsyncIPipeByte
            DECLSPEC_XFGVIRT(AsyncIPipeByte, Begin_Pull)
            STD_METHOD Begin_Pull, :ptr AsyncIPipeByte, :ULONG
            ;* [in] *
            DECLSPEC_XFGVIRT(AsyncIPipeByte, Finish_Pull)
            ;* [length_is][size_is][out] *
            STD_METHOD Finish_Pull, :ptr AsyncIPipeByte, :ptr BYTE, :ptr ULONG
            ;* [out] *
            DECLSPEC_XFGVIRT(AsyncIPipeByte, Begin_Push)
            ;* [size_is][in] *
            STD_METHOD Begin_Push, :ptr AsyncIPipeByte, :ptr BYTE, :ULONG
            ;* [in] *
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
          ;* C style interface *
        endif
        ;* __AsyncIPipeByte_INTERFACE_DEFINED__ *
      endif
      ifndef __IPipeLong_INTERFACE_DEFINED__
        __IPipeLong_INTERFACE_DEFINED__ equ <>
        ;* interface IPipeLong *
        ;* [unique][async_uuid][uuid][object] *
        externdef IID_IPipeLong:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IPipeLongVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IPipeLongVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IPipeLong, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IPipeLong
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IPipeLong
            DECLSPEC_XFGVIRT(IPipeLong, Pull)
            ;* [length_is][size_is][out] *
            ;* [in] *
            STD_METHOD Pull, :ptr IPipeLong, :ptr LONG, :ULONG, :ptr ULONG
            ;* [out] *
            DECLSPEC_XFGVIRT(IPipeLong, Push)
            ;* [size_is][in] *
            STD_METHOD Push_, :ptr IPipeLong, :ptr LONG, :ULONG
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IPipeLongVtbl ends
          IPipeLong struct
            lpVtbl POINTER ?
          IPipeLong ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IPipeLong_INTERFACE_DEFINED__ *
      endif
      ifndef __AsyncIPipeLong_INTERFACE_DEFINED__
        __AsyncIPipeLong_INTERFACE_DEFINED__ equ <>
        ;* interface AsyncIPipeLong *
        ;* [uuid][unique][object] *
        externdef IID_AsyncIPipeLong:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          AsyncIPipeLongVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <AsyncIPipeLongVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr AsyncIPipeLong, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr AsyncIPipeLong
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr AsyncIPipeLong
            DECLSPEC_XFGVIRT(AsyncIPipeLong, Begin_Pull)
            STD_METHOD Begin_Pull, :ptr AsyncIPipeLong, :ULONG
            ;* [in] *
            DECLSPEC_XFGVIRT(AsyncIPipeLong, Finish_Pull)
            ;* [length_is][size_is][out] *
            STD_METHOD Finish_Pull, :ptr AsyncIPipeLong, :ptr LONG, :ptr ULONG
            ;* [out] *
            DECLSPEC_XFGVIRT(AsyncIPipeLong, Begin_Push)
            ;* [size_is][in] *
            STD_METHOD Begin_Push, :ptr AsyncIPipeLong, :ptr LONG, :ULONG
            ;* [in] *
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
          ;* C style interface *
        endif
        ;* __AsyncIPipeLong_INTERFACE_DEFINED__ *
      endif
      ifndef __IPipeDouble_INTERFACE_DEFINED__
        __IPipeDouble_INTERFACE_DEFINED__ equ <>
        ;* interface IPipeDouble *
        ;* [unique][async_uuid][uuid][object] *
        externdef IID_IPipeDouble:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IPipeDoubleVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IPipeDoubleVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IPipeDouble, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IPipeDouble
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IPipeDouble
            DECLSPEC_XFGVIRT(IPipeDouble, Pull)
            ;* [length_is][size_is][out] *
            ;* [in] *
            STD_METHOD Pull, :ptr IPipeDouble, :ptr DOUBLE, :ULONG, :ptr ULONG
            ;* [out] *
            DECLSPEC_XFGVIRT(IPipeDouble, Push)
            ;* [size_is][in] *
            STD_METHOD Push_, :ptr IPipeDouble, :ptr DOUBLE, :ULONG
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IPipeDoubleVtbl ends
          IPipeDouble struct
            lpVtbl POINTER ?
          IPipeDouble ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IPipeDouble_INTERFACE_DEFINED__ *
      endif
      ifndef __AsyncIPipeDouble_INTERFACE_DEFINED__
        __AsyncIPipeDouble_INTERFACE_DEFINED__ equ <>
        ;* interface AsyncIPipeDouble *
        ;* [uuid][unique][object] *
        externdef IID_AsyncIPipeDouble:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          AsyncIPipeDoubleVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <AsyncIPipeDoubleVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr AsyncIPipeDouble, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr AsyncIPipeDouble
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr AsyncIPipeDouble
            DECLSPEC_XFGVIRT(AsyncIPipeDouble, Begin_Pull)
            STD_METHOD Begin_Pull, :ptr AsyncIPipeDouble, :ULONG
            ;* [in] *
            DECLSPEC_XFGVIRT(AsyncIPipeDouble, Finish_Pull)
            ;* [length_is][size_is][out] *
            STD_METHOD Finish_Pull, :ptr AsyncIPipeDouble, :ptr DOUBLE, :ptr ULONG
            ;* [out] *
            DECLSPEC_XFGVIRT(AsyncIPipeDouble, Begin_Push)
            ;* [size_is][in] *
            STD_METHOD Begin_Push, :ptr AsyncIPipeDouble, :ptr DOUBLE, :ULONG
            ;* [in] *
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
          ;* C style interface *
        endif
        ;* __AsyncIPipeDouble_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_objidl_0000_0045 *
      ;* [local] *
      if Defined(USE_COM_CONTEXT_DEF) or Defined(BUILDTYPE_COMSVCS) or Defined(_COMBASEAPI_) or Defined(_OLE32_)
        CPFLAGS typedef DWORD
        ContextProperty struct
          policyId GUID <>
          flags CPFLAGS ?
          pUnk POINTER ?
          ;* [unique] *
        ContextProperty ends
        tagContextProperty typedef ContextProperty
        externdef __MIDL_itf_objidl_0000_0045_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_objidl_0000_0045_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IEnumContextProps_INTERFACE_DEFINED__
          __IEnumContextProps_INTERFACE_DEFINED__ equ <>
          ;* interface IEnumContextProps *
          ;* [unique][uuid][object][local] *
          ;* [unique] *
          LPENUMCONTEXTPROPS typedef ptr IEnumContextProps
          externdef IID_IEnumContextProps:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IEnumContextPropsVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IEnumContextPropsVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              ;* [in] *
              ;* [annotation][iid_is][out] *
              STD_METHOD QueryInterface, :ptr IEnumContextProps, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IEnumContextProps
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IEnumContextProps
              DECLSPEC_XFGVIRT(IEnumContextProps, Next)
              ;* [annotation][in] *
              ;* [annotation][length_is][size_is][out] *
              ;* [annotation][out] *
              STD_METHOD Next, :ptr IEnumContextProps, :ULONG, :ptr ContextProperty, :ptr ULONG
              DECLSPEC_XFGVIRT(IEnumContextProps, Skip)
              ;* [annotation][in] *
              STD_METHOD Skip, :ptr IEnumContextProps, :ULONG
              DECLSPEC_XFGVIRT(IEnumContextProps, Reset)
              STD_METHOD Reset, :ptr IEnumContextProps
              DECLSPEC_XFGVIRT(IEnumContextProps, Clone)
              ;* [annotation][out] *
              STD_METHOD Clone, :ptr IEnumContextProps, :ptr ptr IEnumContextProps
              DECLSPEC_XFGVIRT(IEnumContextProps, Count)
              ;* [annotation][out] *
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
            ;* C style interface *
          endif
          ;* __IEnumContextProps_INTERFACE_DEFINED__ *
        endif
        ifndef __IContext_INTERFACE_DEFINED__
          __IContext_INTERFACE_DEFINED__ equ <>
          ;* interface IContext *
          ;* [unique][uuid][object][local] *
          externdef IID_IContext:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IContextVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IContextVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              ;* [in] *
              ;* [annotation][iid_is][out] *
              STD_METHOD QueryInterface, :ptr IContext, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IContext
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IContext
              DECLSPEC_XFGVIRT(IContext, SetProperty)
              ;* [annotation][in] *
              ;* [annotation][in] *
              ;* [annotation][in] *
              STD_METHOD SetProperty, :ptr IContext, :REFGUID, :CPFLAGS, :ptr IUnknown
              DECLSPEC_XFGVIRT(IContext, RemoveProperty)
              ;* [annotation][in] *
              STD_METHOD RemoveProperty, :ptr IContext, :REFGUID
              DECLSPEC_XFGVIRT(IContext, GetProperty)
              ;* [annotation][in] *
              ;* [annotation][out] *
              ;* [annotation][out] *
              STD_METHOD GetProperty, :ptr IContext, :REFGUID, :ptr CPFLAGS, :ptr ptr IUnknown
              DECLSPEC_XFGVIRT(IContext, EnumContextProps)
              ;* [annotation][out] *
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
            ;* C style interface *
          endif
          ;* __IContext_INTERFACE_DEFINED__ *
        endif
        ;* interface __MIDL_itf_objidl_0000_0047 *
        ;* [local] *
        if  not Defined(BUILDTYPE_COMSVCS) and  not (Defined(_COMBASEAPI_) or Defined(_OLE32_))
          externdef __MIDL_itf_objidl_0000_0047_v0_0_c_ifspec:RPC_IF_HANDLE
          externdef __MIDL_itf_objidl_0000_0047_v0_0_s_ifspec:RPC_IF_HANDLE
          ifndef __IObjContext_INTERFACE_DEFINED__
            __IObjContext_INTERFACE_DEFINED__ equ <>
            ;* interface IObjContext *
            ;* [unique][uuid][object][local] *
            externdef IID_IObjContext:IID
            if Defined(__cplusplus) and  not Defined(CINTERFACE)
              ;[...]
            else
              IObjContextVtbl struct
                BEGIN_INTERFACE
                ??Interface equ <IObjContextVtbl>
                DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
                ;* [in] *
                ;* [annotation][iid_is][out] *
                STD_METHOD QueryInterface, :ptr IObjContext, :REFIID, :ptr ptr
                DECLSPEC_XFGVIRT(IUnknown, AddRef)
                STD_METHOD AddRef, :ptr IObjContext
                DECLSPEC_XFGVIRT(IUnknown, Release)
                STD_METHOD Release, :ptr IObjContext
                DECLSPEC_XFGVIRT(IContext, SetProperty)
                ;* [annotation][in] *
                ;* [annotation][in] *
                ;* [annotation][in] *
                STD_METHOD SetProperty, :ptr IObjContext, :REFGUID, :CPFLAGS, :ptr IUnknown
                DECLSPEC_XFGVIRT(IContext, RemoveProperty)
                ;* [annotation][in] *
                STD_METHOD RemoveProperty, :ptr IObjContext, :REFGUID
                DECLSPEC_XFGVIRT(IContext, GetProperty)
                ;* [annotation][in] *
                ;* [annotation][out] *
                ;* [annotation][out] *
                STD_METHOD GetProperty, :ptr IObjContext, :REFGUID, :ptr CPFLAGS, :ptr ptr IUnknown
                DECLSPEC_XFGVIRT(IContext, EnumContextProps)
                ;* [annotation][out] *
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
              ;* C style interface *
            endif
            ;* __IObjContext_INTERFACE_DEFINED__ *
          endif
          ;* interface __MIDL_itf_objidl_0000_0048 *
          ;* [local] *
        endif
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
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

      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      THDTYPE typedef SDWORD
      THDTYPE_BLOCKMESSAGES equ 0
      THDTYPE_PROCESSMESSAGES equ 1
      _THDTYPE typedef THDTYPE

      APARTMENTID typedef DWORD
      externdef __MIDL_itf_objidl_0000_0048_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_objidl_0000_0048_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IComThreadingInfo_INTERFACE_DEFINED__
        __IComThreadingInfo_INTERFACE_DEFINED__ equ <>
        ;* interface IComThreadingInfo *
        ;* [unique][uuid][object][local] *
        externdef IID_IComThreadingInfo:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IComThreadingInfoVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IComThreadingInfoVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IComThreadingInfo, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IComThreadingInfo
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IComThreadingInfo
            DECLSPEC_XFGVIRT(IComThreadingInfo, GetCurrentApartmentType)
            ;* [annotation][out] *
            STD_METHOD GetCurrentApartmentType, :ptr IComThreadingInfo, :ptr APTTYPE
            DECLSPEC_XFGVIRT(IComThreadingInfo, GetCurrentThreadType)
            ;* [annotation][out] *
            STD_METHOD GetCurrentThreadType, :ptr IComThreadingInfo, :ptr THDTYPE
            DECLSPEC_XFGVIRT(IComThreadingInfo, GetCurrentLogicalThreadId)
            ;* [annotation][out] *
            STD_METHOD GetCurrentLogicalThreadId, :ptr IComThreadingInfo, :ptr GUID
            DECLSPEC_XFGVIRT(IComThreadingInfo, SetCurrentLogicalThreadId)
            ;* [annotation][in] *
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
          ;* C style interface *
        endif
        ;* __IComThreadingInfo_INTERFACE_DEFINED__ *
      endif
      ifndef __IProcessInitControl_INTERFACE_DEFINED__
        __IProcessInitControl_INTERFACE_DEFINED__ equ <>
        ;* interface IProcessInitControl *
        ;* [uuid][unique][object] *
        externdef IID_IProcessInitControl:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IProcessInitControlVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IProcessInitControlVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IProcessInitControl, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IProcessInitControl
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IProcessInitControl
            DECLSPEC_XFGVIRT(IProcessInitControl, ResetInitializerTimeout)
            STD_METHOD ResetInitializerTimeout, :ptr IProcessInitControl, :DWORD
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IProcessInitControlVtbl ends
          IProcessInitControl struct
            lpVtbl POINTER ?
          IProcessInitControl ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IProcessInitControl_INTERFACE_DEFINED__ *
      endif
      ifndef __IFastRundown_INTERFACE_DEFINED__
        __IFastRundown_INTERFACE_DEFINED__ equ <>
        ;* interface IFastRundown *
        ;* [uuid][unique][local][object] *
        externdef IID_IFastRundown:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IFastRundownVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IFastRundownVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
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
          ;* C style interface *
        endif
        ;* __IFastRundown_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_objidl_0000_0051 *
      ;* [local] *
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

      externdef __MIDL_itf_objidl_0000_0051_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_objidl_0000_0051_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IMarshalingStream_INTERFACE_DEFINED__
        __IMarshalingStream_INTERFACE_DEFINED__ equ <>
        ;* interface IMarshalingStream *
        ;* [unique][uuid][object][local] *
        externdef IID_IMarshalingStream:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IMarshalingStreamVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IMarshalingStreamVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IMarshalingStream, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IMarshalingStream
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IMarshalingStream
            DECLSPEC_XFGVIRT(ISequentialStream, Read)
            ;* [local] *
            ;* [annotation] *
            ;* [annotation][in] *
            ;* [annotation] *
            STD_METHOD Read, :ptr IMarshalingStream, :ptr, :ULONG, :ptr ULONG
            DECLSPEC_XFGVIRT(ISequentialStream, Write)
            ;* [local] *
            ;* [annotation] *
            ;* [annotation][in] *
            ;* [annotation] *
            STD_METHOD Write, :ptr IMarshalingStream, :ptr, :ULONG, :ptr ULONG
            DECLSPEC_XFGVIRT(IStream, Seek)
            ;* [local] *
            ;* [in] *
            ;* [in] *
            ;* [annotation] *
            STD_METHOD Seek, :ptr IMarshalingStream, :LARGE_INTEGER, :DWORD, :ptr ULARGE_INTEGER
            DECLSPEC_XFGVIRT(IStream, SetSize)
            STD_METHOD SetSize, :ptr IMarshalingStream, :ULARGE_INTEGER
            ;* [in] *
            DECLSPEC_XFGVIRT(IStream, CopyTo)
            ;* [local] *
            ;* [annotation][unique][in] *
            ;* [in] *
            ;* [annotation] *
            ;* [annotation] *
            STD_METHOD CopyTo, :ptr IMarshalingStream, :ptr IStream, :ULARGE_INTEGER, :ptr ULARGE_INTEGER, :ptr ULARGE_INTEGER
            DECLSPEC_XFGVIRT(IStream, Commit)
            STD_METHOD Commit, :ptr IMarshalingStream, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IStream, Revert)
            STD_METHOD Revert, :ptr IMarshalingStream
            DECLSPEC_XFGVIRT(IStream, LockRegion)
            ;* [in] *
            ;* [in] *
            STD_METHOD LockRegion, :ptr IMarshalingStream, :ULARGE_INTEGER, :ULARGE_INTEGER, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IStream, UnlockRegion)
            ;* [in] *
            ;* [in] *
            STD_METHOD UnlockRegion, :ptr IMarshalingStream, :ULARGE_INTEGER, :ULARGE_INTEGER, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IStream, Stat)
            ;* [out] *
            STD_METHOD Stat, :ptr IMarshalingStream, :ptr STATSTG, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IStream, Clone)
            STD_METHOD Clone, :ptr IMarshalingStream, :ptr ptr IStream
            ;* [out] *
            DECLSPEC_XFGVIRT(IMarshalingStream, GetMarshalingContextAttribute)
            ;* [in] *
            STD_METHOD GetMarshalingContextAttribute, :ptr IMarshalingStream, :CO_MARSHALING_CONTEXT_ATTRIBUTES, :ptr ULONG_PTR
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IMarshalingStreamVtbl ends
          IMarshalingStream struct
            lpVtbl POINTER ?
          IMarshalingStream ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IMarshalingStream_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_objidl_0000_0052 *
      ;* [local] *
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      externdef __MIDL_itf_objidl_0000_0052_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_objidl_0000_0052_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IAgileReference_INTERFACE_DEFINED__
        __IAgileReference_INTERFACE_DEFINED__ equ <>
        ;* interface IAgileReference *
        ;* [unique][uuid][object][local] *
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
              ;* [in] *
              ;* [annotation][iid_is][out] *
              STD_METHOD QueryInterface, :ptr IAgileReference, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IAgileReference
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IAgileReference
              DECLSPEC_XFGVIRT(IAgileReference, Resolve)
              ;* [in] *
              STD_METHOD Resolve, :ptr IAgileReference, :REFIID, :ptr ptr
              ;* [iid_is][retval][out] *
              ??Interface equ <>
              END_INTERFACE
            IAgileReferenceVtbl ends
            IAgileReference struct
              lpVtbl POINTER ?
            IAgileReference ends
            ifdef COBJMACROS
              ;[...]
            endif
            ;* C style interface *
          endif
          ;* __IAgileReference_INTERFACE_DEFINED__ *
        endif
        ;* interface __MIDL_itf_objidl_0000_0053 *
        ;* [local] *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      externdef IID_ICallbackWithNoReentrancyToApplicationSTA:GUID
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      MachineGlobalObjectTableRegistrationToken__ struct
        unused SDWORD ?
      MachineGlobalObjectTableRegistrationToken__ ends
      externdef __MIDL_itf_objidl_0000_0053_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_objidl_0000_0053_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IMachineGlobalObjectTable_INTERFACE_DEFINED__
        __IMachineGlobalObjectTable_INTERFACE_DEFINED__ equ <>
        ;* interface IMachineGlobalObjectTable *
        ;* [unique][uuid][object][local] *
        externdef IID_IMachineGlobalObjectTable:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IMachineGlobalObjectTableVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IMachineGlobalObjectTableVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IMachineGlobalObjectTable, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IMachineGlobalObjectTable
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IMachineGlobalObjectTable
            DECLSPEC_XFGVIRT(IMachineGlobalObjectTable, RegisterObject)
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD RegisterObject, :ptr IMachineGlobalObjectTable, :REFCLSID, :LPCWSTR, :ptr IUnknown, :ptr MachineGlobalObjectTableRegistrationToken
            ;* [out] *
            DECLSPEC_XFGVIRT(IMachineGlobalObjectTable, GetObject)
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD GetObject, :ptr IMachineGlobalObjectTable, :REFCLSID, :LPCWSTR, :REFIID, :ptr ptr
            ;* [iid_is][out] *
            DECLSPEC_XFGVIRT(IMachineGlobalObjectTable, RevokeObject)
            STD_METHOD RevokeObject, :ptr IMachineGlobalObjectTable, :MachineGlobalObjectTableRegistrationToken
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IMachineGlobalObjectTableVtbl ends
          IMachineGlobalObjectTable struct
            lpVtbl POINTER ?
          IMachineGlobalObjectTable ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IMachineGlobalObjectTable_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_objidl_0000_0054 *
      ;* [local] *
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      externdef __MIDL_itf_objidl_0000_0054_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_objidl_0000_0054_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ISupportAllowLowerTrustActivation_INTERFACE_DEFINED__
        __ISupportAllowLowerTrustActivation_INTERFACE_DEFINED__ equ <>
        ;* interface ISupportAllowLowerTrustActivation *
        ;* [uuid][object][local] *
        externdef IID_ISupportAllowLowerTrustActivation:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISupportAllowLowerTrustActivationVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISupportAllowLowerTrustActivationVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
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
          ;* C style interface *
        endif
        ;* __ISupportAllowLowerTrustActivation_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_objidl_0000_0055 *
      ;* [local] *
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    _OBJIDLBASE_ equ <>
  endif
  if (_MSC_VER ge 800)
    if _MSC_VER ge 1200
    else
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_objidl_0000_0055_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_objidl_0000_0055_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IMallocSpy_INTERFACE_DEFINED__
      __IMallocSpy_INTERFACE_DEFINED__ equ <>
      ;* interface IMallocSpy *
      ;* [uuid][object][local] *
      ;* [unique] *
      LPMALLOCSPY typedef ptr IMallocSpy
      externdef IID_IMallocSpy:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IMallocSpyVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IMallocSpyVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IMallocSpy, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IMallocSpy
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IMallocSpy
          DECLSPEC_XFGVIRT(IMallocSpy, PreAlloc)
          ;* [annotation][in] *
          STD_METHOD PreAlloc, :ptr IMallocSpy, :SIZE_T
          DECLSPEC_XFGVIRT(IMallocSpy, PostAlloc)
          ;* [annotation][in] *
          STD_METHOD PostAlloc, :ptr IMallocSpy, :ptr
          DECLSPEC_XFGVIRT(IMallocSpy, PreFree)
          ;* [annotation][in] *
          ;* [annotation][in] *
          STD_METHOD PreFree, :ptr IMallocSpy, :ptr, :BOOL
          DECLSPEC_XFGVIRT(IMallocSpy, PostFree)
          ;* [annotation][in] *
          STD_METHOD PostFree, :ptr IMallocSpy, :BOOL
          DECLSPEC_XFGVIRT(IMallocSpy, PreRealloc)
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][out] *
          ;* [annotation][in] *
          STD_METHOD PreRealloc, :ptr IMallocSpy, :ptr, :SIZE_T, :ptr ptr, :BOOL
          DECLSPEC_XFGVIRT(IMallocSpy, PostRealloc)
          ;* [annotation][in] *
          ;* [annotation][in] *
          STD_METHOD PostRealloc, :ptr IMallocSpy, :ptr, :BOOL
          DECLSPEC_XFGVIRT(IMallocSpy, PreGetSize)
          ;* [annotation][in] *
          ;* [annotation][in] *
          STD_METHOD PreGetSize, :ptr IMallocSpy, :ptr, :BOOL
          DECLSPEC_XFGVIRT(IMallocSpy, PostGetSize)
          ;* [annotation][in] *
          ;* [annotation][in] *
          STD_METHOD PostGetSize, :ptr IMallocSpy, :SIZE_T, :BOOL
          DECLSPEC_XFGVIRT(IMallocSpy, PreDidAlloc)
          ;* [annotation][in] *
          ;* [annotation][in] *
          STD_METHOD PreDidAlloc, :ptr IMallocSpy, :ptr, :BOOL
          DECLSPEC_XFGVIRT(IMallocSpy, PostDidAlloc)
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          STD_METHOD PostDidAlloc, :ptr IMallocSpy, :ptr, :BOOL, :SDWORD
          DECLSPEC_XFGVIRT(IMallocSpy, PreHeapMinimize)
          STD_METHOD PreHeapMinimize, :ptr IMallocSpy
          DECLSPEC_XFGVIRT(IMallocSpy, PostHeapMinimize)
          STD_METHOD PostHeapMinimize, :ptr IMallocSpy
          ??Interface equ <>
          END_INTERFACE
        IMallocSpyVtbl ends
        IMallocSpy struct
          lpVtbl POINTER ?
        IMallocSpy ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IMallocSpy_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_objidl_0000_0056 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    externdef __MIDL_itf_objidl_0000_0056_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_objidl_0000_0056_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IBindCtx_INTERFACE_DEFINED__
      __IBindCtx_INTERFACE_DEFINED__ equ <>
      ;* interface IBindCtx *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPBC typedef ptr IBindCtx
      ;* [unique] *
      LPBINDCTX typedef ptr IBindCtx
      if Defined(__cplusplus)
        ;[...]
      else
        BIND_OPTS struct
          cbStruct DWORD ?
          grfFlags DWORD ?
          grfMode DWORD ?
          dwTickCountDeadline DWORD ?
        BIND_OPTS ends
        tagBIND_OPTS typedef BIND_OPTS
        LPBIND_OPTS typedef ptr tagBIND_OPTS
      endif
      if Defined(__cplusplus)
        ;[...]
      else
        BIND_OPTS2 struct
          cbStruct DWORD ?
          grfFlags DWORD ?
          grfMode DWORD ?
          dwTickCountDeadline DWORD ?
          dwTrackFlags DWORD ?
          dwClassContext DWORD ?
          locale LCID ?
          pServerInfo POINTER ?
        BIND_OPTS2 ends
        tagBIND_OPTS2 typedef BIND_OPTS2
        LPBIND_OPTS2 typedef ptr tagBIND_OPTS2
      endif
      if Defined(__cplusplus)
        ;[...]
      else
        BIND_OPTS3 struct
          cbStruct DWORD ?
          grfFlags DWORD ?
          grfMode DWORD ?
          dwTickCountDeadline DWORD ?
          dwTrackFlags DWORD ?
          dwClassContext DWORD ?
          locale LCID ?
          pServerInfo POINTER ?
          hwnd HWND ?
        BIND_OPTS3 ends
        tagBIND_OPTS3 typedef BIND_OPTS3
        LPBIND_OPTS3 typedef ptr tagBIND_OPTS3
      endif
      BIND_FLAGS typedef SDWORD
      BIND_MAYBOTHERUSER equ 1
      BIND_JUSTTESTEXISTENCE equ 2
      tagBIND_FLAGS typedef BIND_FLAGS

      externdef IID_IBindCtx:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IBindCtxVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IBindCtxVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IBindCtx, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IBindCtx
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IBindCtx
          DECLSPEC_XFGVIRT(IBindCtx, RegisterObjectBound)
          STD_METHOD RegisterObjectBound, :ptr IBindCtx, :ptr IUnknown
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IBindCtx, RevokeObjectBound)
          STD_METHOD RevokeObjectBound, :ptr IBindCtx, :ptr IUnknown
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IBindCtx, ReleaseBoundObjects)
          STD_METHOD ReleaseBoundObjects, :ptr IBindCtx
          DECLSPEC_XFGVIRT(IBindCtx, SetBindOptions)
          ;* [local] *
          ;* [annotation][in] *
          STD_METHOD SetBindOptions, :ptr IBindCtx, :ptr BIND_OPTS
          DECLSPEC_XFGVIRT(IBindCtx, GetBindOptions)
          ;* [local] *
          ;* [annotation][out][in] *
          STD_METHOD GetBindOptions, :ptr IBindCtx, :ptr BIND_OPTS
          DECLSPEC_XFGVIRT(IBindCtx, GetRunningObjectTable)
          STD_METHOD GetRunningObjectTable, :ptr IBindCtx, :ptr ptr IRunningObjectTable
          ;* [out] *
          DECLSPEC_XFGVIRT(IBindCtx, RegisterObjectParam)
          ;* [in] *
          STD_METHOD RegisterObjectParam, :ptr IBindCtx, :LPOLESTR, :ptr IUnknown
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IBindCtx, GetObjectParam)
          ;* [in] *
          STD_METHOD GetObjectParam, :ptr IBindCtx, :LPOLESTR, :ptr ptr IUnknown
          ;* [out] *
          DECLSPEC_XFGVIRT(IBindCtx, EnumObjectParam)
          STD_METHOD EnumObjectParam, :ptr IBindCtx, :ptr ptr IEnumString
          ;* [out] *
          DECLSPEC_XFGVIRT(IBindCtx, RevokeObjectParam)
          STD_METHOD RevokeObjectParam, :ptr IBindCtx, :LPOLESTR
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IBindCtxVtbl ends
        IBindCtx struct
          lpVtbl POINTER ?
        IBindCtx ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      IBindCtx_RemoteSetBindOptions_Proxy proto WIN_STD_CALL_CONV :ptr IBindCtx, :ptr BIND_OPTS2
      ;* [in] *
      IBindCtx_RemoteSetBindOptions_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      IBindCtx_RemoteGetBindOptions_Proxy proto WIN_STD_CALL_CONV :ptr IBindCtx, :ptr BIND_OPTS2
      ;* [out][in] *
      IBindCtx_RemoteGetBindOptions_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __IBindCtx_INTERFACE_DEFINED__ *
    endif
    ifndef __IEnumMoniker_INTERFACE_DEFINED__
      __IEnumMoniker_INTERFACE_DEFINED__ equ <>
      ;* interface IEnumMoniker *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPENUMMONIKER typedef ptr IEnumMoniker
      externdef IID_IEnumMoniker:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IEnumMonikerVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IEnumMonikerVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IEnumMoniker, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IEnumMoniker
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IEnumMoniker
          DECLSPEC_XFGVIRT(IEnumMoniker, Next)
          ;* [local] *
          ;* [in] *
          ;* [annotation] *
          ;* [annotation] *
          STD_METHOD Next, :ptr IEnumMoniker, :ULONG, :ptr ptr IMoniker, :ptr ULONG
          DECLSPEC_XFGVIRT(IEnumMoniker, Skip)
          STD_METHOD Skip, :ptr IEnumMoniker, :ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(IEnumMoniker, Reset)
          STD_METHOD Reset, :ptr IEnumMoniker
          DECLSPEC_XFGVIRT(IEnumMoniker, Clone)
          STD_METHOD Clone, :ptr IEnumMoniker, :ptr ptr IEnumMoniker
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IEnumMonikerVtbl ends
        IEnumMoniker struct
          lpVtbl POINTER ?
        IEnumMoniker ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      IEnumMoniker_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumMoniker, :ULONG, :ptr ptr IMoniker, :ptr ULONG
      ;* [out] *
      IEnumMoniker_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __IEnumMoniker_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_objidl_0000_0058 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_objidl_0000_0058_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_objidl_0000_0058_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IRunnableObject_INTERFACE_DEFINED__
      __IRunnableObject_INTERFACE_DEFINED__ equ <>
      ;* interface IRunnableObject *
      ;* [uuid][object] *
      ;* [unique] *
      LPRUNNABLEOBJECT typedef ptr IRunnableObject
      externdef IID_IRunnableObject:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IRunnableObjectVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IRunnableObjectVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IRunnableObject, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IRunnableObject
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IRunnableObject
          DECLSPEC_XFGVIRT(IRunnableObject, GetRunningClass)
          STD_METHOD GetRunningClass, :ptr IRunnableObject, :LPCLSID
          ;* [out] *
          DECLSPEC_XFGVIRT(IRunnableObject, Run)
          STD_METHOD Run, :ptr IRunnableObject, :LPBINDCTX
          ;* [in] *
          DECLSPEC_XFGVIRT(IRunnableObject, IsRunning)
          ;* [local] *
          STD_METHOD IsRunning, :ptr IRunnableObject
          DECLSPEC_XFGVIRT(IRunnableObject, LockRunning)
          ;* [in] *
          STD_METHOD LockRunning, :ptr IRunnableObject, :BOOL, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IRunnableObject, SetContainedObject)
          STD_METHOD SetContainedObject, :ptr IRunnableObject, :BOOL
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IRunnableObjectVtbl ends
        IRunnableObject struct
          lpVtbl POINTER ?
        IRunnableObject ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      IRunnableObject_RemoteIsRunning_Proxy proto WIN_STD_CALL_CONV :ptr IRunnableObject
      IRunnableObject_RemoteIsRunning_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __IRunnableObject_INTERFACE_DEFINED__ *
    endif
    ifndef __IRunningObjectTable_INTERFACE_DEFINED__
      __IRunningObjectTable_INTERFACE_DEFINED__ equ <>
      ;* interface IRunningObjectTable *
      ;* [uuid][object] *
      ;* [unique] *
      LPRUNNINGOBJECTTABLE typedef ptr IRunningObjectTable
      externdef IID_IRunningObjectTable:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IRunningObjectTableVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IRunningObjectTableVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IRunningObjectTable, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IRunningObjectTable
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IRunningObjectTable
          DECLSPEC_XFGVIRT(IRunningObjectTable, Register)
          ;* [in] *
          ;* [unique][in] *
          ;* [unique][in] *
          STD_METHOD Register, :ptr IRunningObjectTable, :DWORD, :ptr IUnknown, :ptr IMoniker, :ptr DWORD
          ;* [out] *
          DECLSPEC_XFGVIRT(IRunningObjectTable, Revoke)
          STD_METHOD Revoke, :ptr IRunningObjectTable, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IRunningObjectTable, IsRunning)
          STD_METHOD IsRunning, :ptr IRunningObjectTable, :ptr IMoniker
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IRunningObjectTable, GetObject)
          ;* [unique][in] *
          STD_METHOD GetObject, :ptr IRunningObjectTable, :ptr IMoniker, :ptr ptr IUnknown
          ;* [out] *
          DECLSPEC_XFGVIRT(IRunningObjectTable, NoteChangeTime)
          ;* [in] *
          STD_METHOD NoteChangeTime, :ptr IRunningObjectTable, :DWORD, :ptr FILETIME
          ;* [in] *
          DECLSPEC_XFGVIRT(IRunningObjectTable, GetTimeOfLastChange)
          ;* [unique][in] *
          STD_METHOD GetTimeOfLastChange, :ptr IRunningObjectTable, :ptr IMoniker, :ptr FILETIME
          ;* [out] *
          DECLSPEC_XFGVIRT(IRunningObjectTable, EnumRunning)
          STD_METHOD EnumRunning, :ptr IRunningObjectTable, :ptr ptr IEnumMoniker
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IRunningObjectTableVtbl ends
        IRunningObjectTable struct
          lpVtbl POINTER ?
        IRunningObjectTable ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IRunningObjectTable_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_objidl_0000_0060 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    externdef __MIDL_itf_objidl_0000_0060_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_objidl_0000_0060_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IPersist_INTERFACE_DEFINED__
      __IPersist_INTERFACE_DEFINED__ equ <>
      ;* interface IPersist *
      ;* [uuid][object] *
      ;* [unique] *
      LPPERSIST typedef ptr IPersist
      externdef IID_IPersist:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPersistVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPersistVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IPersist, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPersist
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPersist
          DECLSPEC_XFGVIRT(IPersist, GetClassID)
          STD_METHOD GetClassID, :ptr IPersist, :ptr CLSID
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IPersistVtbl ends
        IPersist struct
          lpVtbl POINTER ?
        IPersist ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IPersist_INTERFACE_DEFINED__ *
    endif
    ifndef __IPersistStream_INTERFACE_DEFINED__
      __IPersistStream_INTERFACE_DEFINED__ equ <>
      ;* interface IPersistStream *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPPERSISTSTREAM typedef ptr IPersistStream
      externdef IID_IPersistStream:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPersistStreamVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPersistStreamVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IPersistStream, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPersistStream
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPersistStream
          DECLSPEC_XFGVIRT(IPersist, GetClassID)
          STD_METHOD GetClassID, :ptr IPersistStream, :ptr CLSID
          ;* [out] *
          DECLSPEC_XFGVIRT(IPersistStream, IsDirty)
          STD_METHOD IsDirty, :ptr IPersistStream
          DECLSPEC_XFGVIRT(IPersistStream, Load)
          STD_METHOD Load, :ptr IPersistStream, :ptr IStream
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IPersistStream, Save)
          ;* [unique][in] *
          STD_METHOD Save, :ptr IPersistStream, :ptr IStream, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IPersistStream, GetSizeMax)
          STD_METHOD GetSizeMax, :ptr IPersistStream, :ptr ULARGE_INTEGER
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IPersistStreamVtbl ends
        IPersistStream struct
          lpVtbl POINTER ?
        IPersistStream ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IPersistStream_INTERFACE_DEFINED__ *
    endif
    ifndef __IMoniker_INTERFACE_DEFINED__
      __IMoniker_INTERFACE_DEFINED__ equ <>
      ;* interface IMoniker *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPMONIKER typedef ptr IMoniker
      MKSYS typedef SDWORD
      MKSYS_NONE equ 0
      MKSYS_GENERICCOMPOSITE equ 1
      MKSYS_FILEMONIKER equ 2
      MKSYS_ANTIMONIKER equ 3
      MKSYS_ITEMMONIKER equ 4
      MKSYS_POINTERMONIKER equ 5
      MKSYS_CLASSMONIKER equ 7
      MKSYS_OBJREFMONIKER equ 8
      MKSYS_SESSIONMONIKER equ 9
      MKSYS_LUAMONIKER equ 10
      tagMKSYS typedef MKSYS

      ;* [v1_enum] *
      MKRREDUCE typedef SDWORD
      MKRREDUCE_ONE equ
      MKRREDUCE_TOUSER equ
      MKRREDUCE_THROUGHUSER equ
      MKRREDUCE_ALL equ 0
      tagMKREDUCE typedef MKRREDUCE

      externdef IID_IMoniker:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IMonikerVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IMonikerVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IMoniker, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IMoniker
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IMoniker
          DECLSPEC_XFGVIRT(IPersist, GetClassID)
          STD_METHOD GetClassID, :ptr IMoniker, :ptr CLSID
          ;* [out] *
          DECLSPEC_XFGVIRT(IPersistStream, IsDirty)
          STD_METHOD IsDirty, :ptr IMoniker
          DECLSPEC_XFGVIRT(IPersistStream, Load)
          STD_METHOD Load, :ptr IMoniker, :ptr IStream
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IPersistStream, Save)
          ;* [unique][in] *
          STD_METHOD Save, :ptr IMoniker, :ptr IStream, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IPersistStream, GetSizeMax)
          STD_METHOD GetSizeMax, :ptr IMoniker, :ptr ULARGE_INTEGER
          ;* [out] *
          DECLSPEC_XFGVIRT(IMoniker, BindToObject)
          ;* [local] *
          ;* [annotation][unique][in] *
          ;* [annotation][unique][in] *
          ;* [annotation][in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD BindToObject, :ptr IMoniker, :ptr IBindCtx, :ptr IMoniker, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IMoniker, BindToStorage)
          ;* [local] *
          ;* [annotation][unique][in] *
          ;* [annotation][unique][in] *
          ;* [annotation][in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD BindToStorage, :ptr IMoniker, :ptr IBindCtx, :ptr IMoniker, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IMoniker, Reduce)
          ;* [unique][in] *
          ;* [in] *
          ;* [unique][out][in] *
          STD_METHOD Reduce, :ptr IMoniker, :ptr IBindCtx, :DWORD, :ptr ptr IMoniker, :ptr ptr IMoniker
          ;* [out] *
          DECLSPEC_XFGVIRT(IMoniker, ComposeWith)
          ;* [unique][in] *
          ;* [in] *
          STD_METHOD ComposeWith, :ptr IMoniker, :ptr IMoniker, :BOOL, :ptr ptr IMoniker
          ;* [out] *
          DECLSPEC_XFGVIRT(IMoniker, Enum)
          ;* [in] *
          STD_METHOD Enum, :ptr IMoniker, :BOOL, :ptr ptr IEnumMoniker
          ;* [out] *
          DECLSPEC_XFGVIRT(IMoniker, IsEqual)
          STD_METHOD IsEqual, :ptr IMoniker, :ptr IMoniker
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IMoniker, Hash)
          STD_METHOD Hash, :ptr IMoniker, :ptr DWORD
          ;* [out] *
          DECLSPEC_XFGVIRT(IMoniker, IsRunning)
          ;* [unique][in] *
          ;* [unique][in] *
          STD_METHOD IsRunning, :ptr IMoniker, :ptr IBindCtx, :ptr IMoniker, :ptr IMoniker
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IMoniker, GetTimeOfLastChange)
          ;* [unique][in] *
          ;* [unique][in] *
          STD_METHOD GetTimeOfLastChange, :ptr IMoniker, :ptr IBindCtx, :ptr IMoniker, :ptr FILETIME
          ;* [out] *
          DECLSPEC_XFGVIRT(IMoniker, Inverse)
          STD_METHOD Inverse, :ptr IMoniker, :ptr ptr IMoniker
          ;* [out] *
          DECLSPEC_XFGVIRT(IMoniker, CommonPrefixWith)
          ;* [unique][in] *
          STD_METHOD CommonPrefixWith, :ptr IMoniker, :ptr IMoniker, :ptr ptr IMoniker
          ;* [out] *
          DECLSPEC_XFGVIRT(IMoniker, RelativePathTo)
          ;* [unique][in] *
          STD_METHOD RelativePathTo, :ptr IMoniker, :ptr IMoniker, :ptr ptr IMoniker
          ;* [out] *
          DECLSPEC_XFGVIRT(IMoniker, GetDisplayName)
          ;* [unique][in] *
          ;* [unique][in] *
          STD_METHOD GetDisplayName, :ptr IMoniker, :ptr IBindCtx, :ptr IMoniker, :ptr LPOLESTR
          ;* [out] *
          DECLSPEC_XFGVIRT(IMoniker, ParseDisplayName)
          ;* [unique][in] *
          ;* [unique][in] *
          ;* [in] *
          ;* [out] *
          STD_METHOD ParseDisplayName, :ptr IMoniker, :ptr IBindCtx, :ptr IMoniker, :LPOLESTR, :ptr ULONG, :ptr ptr IMoniker
          ;* [out] *
          DECLSPEC_XFGVIRT(IMoniker, IsSystemMoniker)
          STD_METHOD IsSystemMoniker, :ptr IMoniker, :ptr DWORD
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IMonikerVtbl ends
        IMoniker struct
          lpVtbl POINTER ?
        IMoniker ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      IMoniker_RemoteBindToObject_Proxy proto WIN_STD_CALL_CONV :ptr IMoniker, :ptr IBindCtx, :ptr IMoniker, :REFIID, :ptr ptr IUnknown
      ;* [iid_is][out] *
      IMoniker_RemoteBindToObject_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      IMoniker_RemoteBindToStorage_Proxy proto WIN_STD_CALL_CONV :ptr IMoniker, :ptr IBindCtx, :ptr IMoniker, :REFIID, :ptr ptr IUnknown
      ;* [iid_is][out] *
      IMoniker_RemoteBindToStorage_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __IMoniker_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_objidl_0000_0063 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_objidl_0000_0063_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_objidl_0000_0063_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IROTData_INTERFACE_DEFINED__
      __IROTData_INTERFACE_DEFINED__ equ <>
      ;* interface IROTData *
      ;* [unique][uuid][object] *
      externdef IID_IROTData:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IROTDataVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IROTDataVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IROTData, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IROTData
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IROTData
          DECLSPEC_XFGVIRT(IROTData, GetComparisonData)
          ;* [size_is][out] *
          ;* [in] *
          STD_METHOD GetComparisonData, :ptr IROTData, :ptr byte, :ULONG, :ptr ULONG
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IROTDataVtbl ends
        IROTData struct
          lpVtbl POINTER ?
        IROTData ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IROTData_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_objidl_0000_0064 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    externdef __MIDL_itf_objidl_0000_0064_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_objidl_0000_0064_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IEnumSTATSTG_INTERFACE_DEFINED__
      __IEnumSTATSTG_INTERFACE_DEFINED__ equ <>
      ;* interface IEnumSTATSTG *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPENUMSTATSTG typedef ptr IEnumSTATSTG
      externdef IID_IEnumSTATSTG:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IEnumSTATSTGVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IEnumSTATSTGVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IEnumSTATSTG, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IEnumSTATSTG
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IEnumSTATSTG
          DECLSPEC_XFGVIRT(IEnumSTATSTG, Next)
          ;* [local] *
          ;* [in] *
          ;* [annotation] *
          ;* [annotation] *
          STD_METHOD Next, :ptr IEnumSTATSTG, :ULONG, :ptr STATSTG, :ptr ULONG
          DECLSPEC_XFGVIRT(IEnumSTATSTG, Skip)
          STD_METHOD Skip, :ptr IEnumSTATSTG, :ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(IEnumSTATSTG, Reset)
          STD_METHOD Reset, :ptr IEnumSTATSTG
          DECLSPEC_XFGVIRT(IEnumSTATSTG, Clone)
          STD_METHOD Clone, :ptr IEnumSTATSTG, :ptr ptr IEnumSTATSTG
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IEnumSTATSTGVtbl ends
        IEnumSTATSTG struct
          lpVtbl POINTER ?
        IEnumSTATSTG ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      IEnumSTATSTG_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumSTATSTG, :ULONG, :ptr STATSTG, :ptr ULONG
      ;* [out] *
      IEnumSTATSTG_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __IEnumSTATSTG_INTERFACE_DEFINED__ *
    endif
    ifndef __IStorage_INTERFACE_DEFINED__
      __IStorage_INTERFACE_DEFINED__ equ <>
      ;* interface IStorage *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPSTORAGE typedef ptr IStorage
      RemSNB struct
        ulCntStr DWORD ?
        ulCntChar DWORD ?
        rgString OLECHAR 1 dup (?)
        ;* [size_is] *
      RemSNB ends
      tagRemSNB typedef RemSNB
      ;* [unique] *
      wireSNB typedef ptr RemSNB
      ;* [annotation][wire_marshal] *
      SNB typedef ptr LPOLESTR
      externdef IID_IStorage:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IStorageVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IStorageVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IStorage, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IStorage
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IStorage
          DECLSPEC_XFGVIRT(IStorage, CreateStream)
          ;* [string][in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD CreateStream, :ptr IStorage, :ptr OLECHAR, :DWORD, :DWORD, :DWORD, :ptr ptr IStream
          ;* [out] *
          DECLSPEC_XFGVIRT(IStorage, OpenStream)
          ;* [local] *
          ;* [annotation][string][in] *
          ;* [annotation][unique][in] *
          ;* [in] *
          ;* [in] *
          ;* [annotation][out] *
          STD_METHOD OpenStream, :ptr IStorage, :ptr OLECHAR, :ptr, :DWORD, :DWORD, :ptr ptr IStream
          DECLSPEC_XFGVIRT(IStorage, CreateStorage)
          ;* [string][in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD CreateStorage, :ptr IStorage, :ptr OLECHAR, :DWORD, :DWORD, :DWORD, :ptr ptr IStorage
          ;* [out] *
          DECLSPEC_XFGVIRT(IStorage, OpenStorage)
          ;* [string][unique][in] *
          ;* [unique][in] *
          ;* [in] *
          ;* [unique][in] *
          ;* [in] *
          STD_METHOD OpenStorage, :ptr IStorage, :ptr OLECHAR, :ptr IStorage, :DWORD, :SNB, :DWORD, :ptr ptr IStorage
          ;* [out] *
          DECLSPEC_XFGVIRT(IStorage, CopyTo)
          ;* [local] *
          ;* [in] *
          ;* [annotation][size_is][unique][in] *
          ;* [annotation][unique][in] *
          ;* [annotation][unique][in] *
          STD_METHOD CopyTo, :ptr IStorage, :DWORD, :ptr IID, :SNB, :ptr IStorage
          DECLSPEC_XFGVIRT(IStorage, MoveElementTo)
          ;* [string][in] *
          ;* [unique][in] *
          ;* [string][in] *
          STD_METHOD MoveElementTo, :ptr IStorage, :ptr OLECHAR, :ptr IStorage, :ptr OLECHAR, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IStorage, Commit)
          STD_METHOD Commit, :ptr IStorage, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IStorage, Revert)
          STD_METHOD Revert, :ptr IStorage
          DECLSPEC_XFGVIRT(IStorage, EnumElements)
          ;* [local] *
          ;* [annotation][in] *
          ;* [annotation][size_is][unique][in] *
          ;* [annotation][in] *
          ;* [annotation][out] *
          STD_METHOD EnumElements, :ptr IStorage, :DWORD, :ptr, :DWORD, :ptr ptr IEnumSTATSTG
          DECLSPEC_XFGVIRT(IStorage, DestroyElement)
          STD_METHOD DestroyElement, :ptr IStorage, :ptr OLECHAR
          ;* [string][in] *
          DECLSPEC_XFGVIRT(IStorage, RenameElement)
          ;* [string][in] *
          STD_METHOD RenameElement, :ptr IStorage, :ptr OLECHAR, :ptr OLECHAR
          ;* [string][in] *
          DECLSPEC_XFGVIRT(IStorage, SetElementTimes)
          ;* [string][unique][in] *
          ;* [unique][in] *
          ;* [unique][in] *
          STD_METHOD SetElementTimes, :ptr IStorage, :ptr OLECHAR, :ptr FILETIME, :ptr FILETIME, :ptr FILETIME
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IStorage, SetClass)
          STD_METHOD SetClass, :ptr IStorage, :REFCLSID
          ;* [in] *
          DECLSPEC_XFGVIRT(IStorage, SetStateBits)
          ;* [in] *
          STD_METHOD SetStateBits, :ptr IStorage, :DWORD, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IStorage, Stat)
          ;* [out] *
          STD_METHOD Stat, :ptr IStorage, :ptr STATSTG, :DWORD
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IStorageVtbl ends
        IStorage struct
          lpVtbl POINTER ?
        IStorage ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      IStorage_RemoteOpenStream_Proxy proto WIN_STD_CALL_CONV :ptr IStorage, :ptr OLECHAR, :ULONG, :ptr byte, :DWORD, :DWORD, :ptr ptr IStream
      ;* [out] *
      IStorage_RemoteOpenStream_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      IStorage_RemoteCopyTo_Proxy proto WIN_STD_CALL_CONV :ptr IStorage, :DWORD, :ptr IID, :SNB, :ptr IStorage
      ;* [unique][in] *
      IStorage_RemoteCopyTo_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      IStorage_RemoteEnumElements_Proxy proto WIN_STD_CALL_CONV :ptr IStorage, :DWORD, :ULONG, :ptr byte, :DWORD, :ptr ptr IEnumSTATSTG
      ;* [out] *
      IStorage_RemoteEnumElements_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __IStorage_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_objidl_0000_0066 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_objidl_0000_0066_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_objidl_0000_0066_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IPersistFile_INTERFACE_DEFINED__
      __IPersistFile_INTERFACE_DEFINED__ equ <>
      ;* interface IPersistFile *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPPERSISTFILE typedef ptr IPersistFile
      externdef IID_IPersistFile:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPersistFileVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPersistFileVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IPersistFile, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPersistFile
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPersistFile
          DECLSPEC_XFGVIRT(IPersist, GetClassID)
          STD_METHOD GetClassID, :ptr IPersistFile, :ptr CLSID
          ;* [out] *
          DECLSPEC_XFGVIRT(IPersistFile, IsDirty)
          STD_METHOD IsDirty, :ptr IPersistFile
          DECLSPEC_XFGVIRT(IPersistFile, Load)
          ;* [in] *
          STD_METHOD Load, :ptr IPersistFile, :LPCOLESTR, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IPersistFile, Save)
          ;* [unique][in] *
          STD_METHOD Save, :ptr IPersistFile, :LPCOLESTR, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IPersistFile, SaveCompleted)
          STD_METHOD SaveCompleted, :ptr IPersistFile, :LPCOLESTR
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IPersistFile, GetCurFile)
          STD_METHOD GetCurFile, :ptr IPersistFile, :ptr LPOLESTR
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IPersistFileVtbl ends
        IPersistFile struct
          lpVtbl POINTER ?
        IPersistFile ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IPersistFile_INTERFACE_DEFINED__ *
    endif
    ifndef __IPersistStorage_INTERFACE_DEFINED__
      __IPersistStorage_INTERFACE_DEFINED__ equ <>
      ;* interface IPersistStorage *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPPERSISTSTORAGE typedef ptr IPersistStorage
      externdef IID_IPersistStorage:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPersistStorageVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPersistStorageVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IPersistStorage, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPersistStorage
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPersistStorage
          DECLSPEC_XFGVIRT(IPersist, GetClassID)
          STD_METHOD GetClassID, :ptr IPersistStorage, :ptr CLSID
          ;* [out] *
          DECLSPEC_XFGVIRT(IPersistStorage, IsDirty)
          STD_METHOD IsDirty, :ptr IPersistStorage
          DECLSPEC_XFGVIRT(IPersistStorage, InitNew)
          STD_METHOD InitNew, :ptr IPersistStorage, :ptr IStorage
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IPersistStorage, Load)
          STD_METHOD Load, :ptr IPersistStorage, :ptr IStorage
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IPersistStorage, Save)
          ;* [unique][in] *
          STD_METHOD Save, :ptr IPersistStorage, :ptr IStorage, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IPersistStorage, SaveCompleted)
          STD_METHOD SaveCompleted, :ptr IPersistStorage, :ptr IStorage
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IPersistStorage, HandsOffStorage)
          STD_METHOD HandsOffStorage, :ptr IPersistStorage
          ??Interface equ <>
          END_INTERFACE
        IPersistStorageVtbl ends
        IPersistStorage struct
          lpVtbl POINTER ?
        IPersistStorage ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IPersistStorage_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_objidl_0000_0068 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    externdef __MIDL_itf_objidl_0000_0068_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_objidl_0000_0068_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ILockBytes_INTERFACE_DEFINED__
      __ILockBytes_INTERFACE_DEFINED__ equ <>
      ;* interface ILockBytes *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPLOCKBYTES typedef ptr ILockBytes
      externdef IID_ILockBytes:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ILockBytesVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ILockBytesVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ILockBytes, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ILockBytes
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ILockBytes
          DECLSPEC_XFGVIRT(ILockBytes, ReadAt)
          ;* [local] *
          ;* [in] *
          ;* [annotation][length_is][size_is][out] *
          ;* [in] *
          ;* [annotation][out] *
          STD_METHOD ReadAt, :ptr ILockBytes, :ULARGE_INTEGER, :ptr, :ULONG, :ptr ULONG
          DECLSPEC_XFGVIRT(ILockBytes, WriteAt)
          ;* [local] *
          ;* [in] *
          ;* [annotation][size_is][in] *
          ;* [in] *
          ;* [annotation][out] *
          STD_METHOD WriteAt, :ptr ILockBytes, :ULARGE_INTEGER, :ptr, :ULONG, :ptr ULONG
          DECLSPEC_XFGVIRT(ILockBytes, Flush)
          STD_METHOD Flush, :ptr ILockBytes
          DECLSPEC_XFGVIRT(ILockBytes, SetSize)
          STD_METHOD SetSize, :ptr ILockBytes, :ULARGE_INTEGER
          ;* [in] *
          DECLSPEC_XFGVIRT(ILockBytes, LockRegion)
          ;* [in] *
          ;* [in] *
          STD_METHOD LockRegion, :ptr ILockBytes, :ULARGE_INTEGER, :ULARGE_INTEGER, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ILockBytes, UnlockRegion)
          ;* [in] *
          ;* [in] *
          STD_METHOD UnlockRegion, :ptr ILockBytes, :ULARGE_INTEGER, :ULARGE_INTEGER, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ILockBytes, Stat)
          ;* [out] *
          STD_METHOD Stat, :ptr ILockBytes, :ptr STATSTG, :DWORD
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        ILockBytesVtbl ends
        ILockBytes struct
          lpVtbl POINTER ?
        ILockBytes ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      ILockBytes_RemoteReadAt_Proxy proto WIN_STD_CALL_CONV :ptr ILockBytes, :ULARGE_INTEGER, :ptr byte, :ULONG, :ptr ULONG
      ;* [out] *
      ILockBytes_RemoteReadAt_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      ILockBytes_RemoteWriteAt_Proxy proto WIN_STD_CALL_CONV :ptr ILockBytes, :ULARGE_INTEGER, :ptr byte, :ULONG, :ptr ULONG
      ;* [out] *
      ILockBytes_RemoteWriteAt_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __ILockBytes_INTERFACE_DEFINED__ *
    endif
    ifndef __IEnumFORMATETC_INTERFACE_DEFINED__
      __IEnumFORMATETC_INTERFACE_DEFINED__ equ <>
      ;* interface IEnumFORMATETC *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPENUMFORMATETC typedef ptr IEnumFORMATETC
      DVTARGETDEVICE struct
        tdSize DWORD ?
        tdDriverNameOffset WORD ?
        tdDeviceNameOffset WORD ?
        tdPortNameOffset WORD ?
        tdExtDevmodeOffset WORD ?
        tdData BYTE 1 dup (?)
        ;* [size_is] *
      DVTARGETDEVICE ends
      tagDVTARGETDEVICE typedef DVTARGETDEVICE
      LPCLIPFORMAT typedef ptr CLIPFORMAT
      FORMATETC struct 4
        cfFormat CLIPFORMAT ?
        ptd POINTER ?
        ;* [unique] *
        dwAspect DWORD ?
        lindex SDWORD ?
        tymed DWORD ?
      FORMATETC ends
      tagFORMATETC typedef FORMATETC
      LPFORMATETC typedef ptr tagFORMATETC
      externdef IID_IEnumFORMATETC:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IEnumFORMATETCVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IEnumFORMATETCVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IEnumFORMATETC, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IEnumFORMATETC
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IEnumFORMATETC
          DECLSPEC_XFGVIRT(IEnumFORMATETC, Next)
          ;* [local] *
          ;* [in] *
          ;* [annotation] *
          ;* [annotation] *
          STD_METHOD Next, :ptr IEnumFORMATETC, :ULONG, :ptr FORMATETC, :ptr ULONG
          DECLSPEC_XFGVIRT(IEnumFORMATETC, Skip)
          STD_METHOD Skip, :ptr IEnumFORMATETC, :ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(IEnumFORMATETC, Reset)
          STD_METHOD Reset, :ptr IEnumFORMATETC
          DECLSPEC_XFGVIRT(IEnumFORMATETC, Clone)
          STD_METHOD Clone, :ptr IEnumFORMATETC, :ptr ptr IEnumFORMATETC
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IEnumFORMATETCVtbl ends
        IEnumFORMATETC struct
          lpVtbl POINTER ?
        IEnumFORMATETC ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      IEnumFORMATETC_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumFORMATETC, :ULONG, :ptr FORMATETC, :ptr ULONG
      ;* [out] *
      IEnumFORMATETC_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __IEnumFORMATETC_INTERFACE_DEFINED__ *
    endif
    ifndef __IEnumSTATDATA_INTERFACE_DEFINED__
      __IEnumSTATDATA_INTERFACE_DEFINED__ equ <>
      ;* interface IEnumSTATDATA *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPENUMSTATDATA typedef ptr IEnumSTATDATA
      ADVF typedef SDWORD
      ADVF_NODATA equ 1
      ADVF_PRIMEFIRST equ 2
      ADVF_ONLYONCE equ 4
      ADVF_DATAONSTOP equ 64
      ADVFCACHE_NOHANDLER equ 8
      ADVFCACHE_FORCEBUILTIN equ 16
      ADVFCACHE_ONSAVE equ 32
      tagADVF typedef ADVF

      STATDATA struct
        formatetc FORMATETC <>
        advf DWORD ?
        pAdvSink POINTER ?
        ;* [unique] *
        dwConnection DWORD ?
      STATDATA ends
      tagSTATDATA typedef STATDATA
      LPSTATDATA typedef ptr STATDATA
      externdef IID_IEnumSTATDATA:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IEnumSTATDATAVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IEnumSTATDATAVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IEnumSTATDATA, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IEnumSTATDATA
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IEnumSTATDATA
          DECLSPEC_XFGVIRT(IEnumSTATDATA, Next)
          ;* [local] *
          ;* [in] *
          ;* [annotation] *
          ;* [annotation] *
          STD_METHOD Next, :ptr IEnumSTATDATA, :ULONG, :ptr STATDATA, :ptr ULONG
          DECLSPEC_XFGVIRT(IEnumSTATDATA, Skip)
          STD_METHOD Skip, :ptr IEnumSTATDATA, :ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(IEnumSTATDATA, Reset)
          STD_METHOD Reset, :ptr IEnumSTATDATA
          DECLSPEC_XFGVIRT(IEnumSTATDATA, Clone)
          STD_METHOD Clone, :ptr IEnumSTATDATA, :ptr ptr IEnumSTATDATA
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IEnumSTATDATAVtbl ends
        IEnumSTATDATA struct
          lpVtbl POINTER ?
        IEnumSTATDATA ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      IEnumSTATDATA_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumSTATDATA, :ULONG, :ptr STATDATA, :ptr ULONG
      ;* [out] *
      IEnumSTATDATA_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __IEnumSTATDATA_INTERFACE_DEFINED__ *
    endif
    ifndef __IRootStorage_INTERFACE_DEFINED__
      __IRootStorage_INTERFACE_DEFINED__ equ <>
      ;* interface IRootStorage *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPROOTSTORAGE typedef ptr IRootStorage
      externdef IID_IRootStorage:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IRootStorageVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IRootStorageVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IRootStorage, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IRootStorage
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IRootStorage
          DECLSPEC_XFGVIRT(IRootStorage, SwitchToFile)
          STD_METHOD SwitchToFile, :ptr IRootStorage, :LPOLESTR
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IRootStorageVtbl ends
        IRootStorage struct
          lpVtbl POINTER ?
        IRootStorage ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IRootStorage_INTERFACE_DEFINED__ *
    endif
    ifndef __IAdviseSink_INTERFACE_DEFINED__
      __IAdviseSink_INTERFACE_DEFINED__ equ <>
      ;* interface IAdviseSink *
      ;* [unique][async_uuid][uuid][object] *
      LPADVISESINK typedef ptr IAdviseSink
      ;* [v1_enum] *
      TYMED typedef SDWORD
      TYMED_HGLOBAL equ 1
      TYMED_FILE equ 2
      TYMED_ISTREAM equ 4
      TYMED_ISTORAGE equ 8
      TYMED_GDI equ 16
      TYMED_MFPICT equ 32
      TYMED_ENHMF equ 64
      TYMED_NULL equ 0
      tagTYMED typedef TYMED

      ifndef RC_INVOKED
        if _MSC_VER ge 1200
        endif
      endif
      RemSTGMEDIUM struct
        tymed DWORD ?
        dwHandleType DWORD ?
        pData DWORD ?
        pUnkForRelease DWORD ?
        cbData DWORD ?
        data byte 1 dup (?)
        ;* [size_is] *
      RemSTGMEDIUM ends
      tagRemSTGMEDIUM typedef RemSTGMEDIUM
      ifndef RC_INVOKED
        if _MSC_VER ge 1200
        else
        endif
      endif
      ifdef NONAMELESSUNION
        uSTGMEDIUM struct
          tymed DWORD ?
          union u
            hBitmap HBITMAP ?
            hMetaFilePict HMETAFILEPICT ?
            hEnhMetaFile HENHMETAFILE ?
            hGlobal HGLOBAL ?
            lpszFileName LPOLESTR ?
            pstm POINTER ?
            pstg POINTER ?
          ends
          pUnkForRelease POINTER ?
        uSTGMEDIUM ends
        tagSTGMEDIUM typedef uSTGMEDIUM
      else
        uSTGMEDIUM struct
          tymed DWORD ?
          ;* [switch_is][switch_type] *
          union
            hBitmap HBITMAP ?
            ;* [case()] *
            hMetaFilePict HMETAFILEPICT ?
            ;* [case()] *
            hEnhMetaFile HENHMETAFILE ?
            ;* [case()] *
            hGlobal HGLOBAL ?
            ;* [case()] *
            lpszFileName LPOLESTR ?
            ;* [case()] *
            pstm POINTER ?
            ;* [case()] *
            pstg POINTER ?
            ;* [case()] *
            ;* [default] ** Empty union arm *
          ends
          pUnkForRelease POINTER ?
          ;* [unique] *
        uSTGMEDIUM ends
        tagSTGMEDIUM typedef uSTGMEDIUM
        ;* !NONAMELESSUNION *
      endif
      GDI_OBJECT struct
        ObjectType DWORD ?
        ;* [switch_is] ** [switch_type] *
        union u
          hBitmap wireHBITMAP ?
          ;* [case()] *
          hPalette wireHPALETTE ?
          ;* [case()] *
          hGeneric wireHGLOBAL ?
          ;* [default] *
        ends
      GDI_OBJECT ends
      _GDI_OBJECT typedef GDI_OBJECT
      userSTGMEDIUM struct
        struct
          tymed DWORD ?
          ;* [switch_is] ** [switch_type] *
          union u
            ;* [case()] ** Empty union arm *
            hMetaFilePict wireHMETAFILEPICT ?
            ;* [case()] *
            hHEnhMetaFile wireHENHMETAFILE ?
            ;* [case()] *
            hGdiHandle POINTER ?
            ;* [case()] *
            hGlobal wireHGLOBAL ?
            ;* [case()] *
            lpszFileName LPOLESTR ?
            ;* [case()] *
            pstm POINTER ?
            ;* [case()] *
            pstg POINTER ?
            ;* [case()] *
          ends
        ends
        pUnkForRelease POINTER ?
      userSTGMEDIUM ends
      _userSTGMEDIUM typedef userSTGMEDIUM
      ;* [unique] *
      wireSTGMEDIUM typedef ptr userSTGMEDIUM
      ;* [wire_marshal] *
      STGMEDIUM typedef uSTGMEDIUM
      ;* [unique] *
      wireASYNC_STGMEDIUM typedef ptr userSTGMEDIUM
      ;* [wire_marshal] *
      ASYNC_STGMEDIUM typedef STGMEDIUM
      LPSTGMEDIUM typedef ptr STGMEDIUM
      userFLAG_STGMEDIUM struct
        ContextFlags SDWORD ?
        fPassOwnership SDWORD ?
        Stgmed userSTGMEDIUM <>
      userFLAG_STGMEDIUM ends
      _userFLAG_STGMEDIUM typedef userFLAG_STGMEDIUM
      ;* [unique] *
      wireFLAG_STGMEDIUM typedef ptr userFLAG_STGMEDIUM
      ;* [wire_marshal] *
      FLAG_STGMEDIUM struct
        ContextFlags SDWORD ?
        fPassOwnership SDWORD ?
        Stgmed STGMEDIUM <>
      FLAG_STGMEDIUM ends
      _FLAG_STGMEDIUM typedef FLAG_STGMEDIUM
      externdef IID_IAdviseSink:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IAdviseSinkVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IAdviseSinkVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IAdviseSink, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IAdviseSink
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IAdviseSink
          DECLSPEC_XFGVIRT(IAdviseSink, OnDataChange)
          ;* [local] *
          ;* [annotation][unique][in] *
          ;* [annotation][unique][in] *
          STD_METHOD OnDataChange, :ptr IAdviseSink, :ptr FORMATETC, :ptr STGMEDIUM
          DECLSPEC_XFGVIRT(IAdviseSink, OnViewChange)
          ;* [local] *
          ;* [in] *
          STD_METHOD OnViewChange, :ptr IAdviseSink, :DWORD, :LONG
          ;* [in] *
          DECLSPEC_XFGVIRT(IAdviseSink, OnRename)
          ;* [local] *
          ;* [annotation][in] *
          STD_METHOD OnRename, :ptr IAdviseSink, :ptr IMoniker
          DECLSPEC_XFGVIRT(IAdviseSink, OnSave)
          ;* [local] *
          STD_METHOD OnSave, :ptr IAdviseSink
          DECLSPEC_XFGVIRT(IAdviseSink, OnClose)
          ;* [local] *
          STD_METHOD OnClose, :ptr IAdviseSink
          ??Interface equ <>
          END_INTERFACE
        IAdviseSinkVtbl ends
        IAdviseSink struct
          lpVtbl POINTER ?
        IAdviseSink ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      IAdviseSink_RemoteOnDataChange_Proxy proto WIN_STD_CALL_CONV :ptr IAdviseSink, :ptr FORMATETC, :ptr ASYNC_STGMEDIUM
      ;* [unique][in] *
      IAdviseSink_RemoteOnDataChange_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      IAdviseSink_RemoteOnViewChange_Proxy proto WIN_STD_CALL_CONV :ptr IAdviseSink, :DWORD, :LONG
      ;* [in] *
      IAdviseSink_RemoteOnViewChange_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      IAdviseSink_RemoteOnRename_Proxy proto WIN_STD_CALL_CONV :ptr IAdviseSink, :ptr IMoniker
      ;* [in] *
      IAdviseSink_RemoteOnRename_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      IAdviseSink_RemoteOnSave_Proxy proto WIN_STD_CALL_CONV :ptr IAdviseSink
      IAdviseSink_RemoteOnSave_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      IAdviseSink_RemoteOnClose_Proxy proto WIN_STD_CALL_CONV :ptr IAdviseSink
      IAdviseSink_RemoteOnClose_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __IAdviseSink_INTERFACE_DEFINED__ *
    endif
    ifndef __AsyncIAdviseSink_INTERFACE_DEFINED__
      __AsyncIAdviseSink_INTERFACE_DEFINED__ equ <>
      ;* interface AsyncIAdviseSink *
      ;* [uuid][unique][object] *
      externdef IID_AsyncIAdviseSink:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        AsyncIAdviseSinkVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <AsyncIAdviseSinkVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr AsyncIAdviseSink, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr AsyncIAdviseSink
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr AsyncIAdviseSink
          DECLSPEC_XFGVIRT(AsyncIAdviseSink, Begin_OnDataChange)
          ;* [local] *
          ;* [annotation][unique][in] *
          ;* [annotation][unique][in] *
          STD_METHOD Begin_OnDataChange, :ptr AsyncIAdviseSink, :ptr FORMATETC, :ptr STGMEDIUM
          DECLSPEC_XFGVIRT(AsyncIAdviseSink, Finish_OnDataChange)
          ;* [local] *
          STD_METHOD Finish_OnDataChange, :ptr AsyncIAdviseSink
          DECLSPEC_XFGVIRT(AsyncIAdviseSink, Begin_OnViewChange)
          ;* [local] *
          ;* [in] *
          STD_METHOD Begin_OnViewChange, :ptr AsyncIAdviseSink, :DWORD, :LONG
          ;* [in] *
          DECLSPEC_XFGVIRT(AsyncIAdviseSink, Finish_OnViewChange)
          ;* [local] *
          STD_METHOD Finish_OnViewChange, :ptr AsyncIAdviseSink
          DECLSPEC_XFGVIRT(AsyncIAdviseSink, Begin_OnRename)
          ;* [local] *
          ;* [annotation][in] *
          STD_METHOD Begin_OnRename, :ptr AsyncIAdviseSink, :ptr IMoniker
          DECLSPEC_XFGVIRT(AsyncIAdviseSink, Finish_OnRename)
          ;* [local] *
          STD_METHOD Finish_OnRename, :ptr AsyncIAdviseSink
          DECLSPEC_XFGVIRT(AsyncIAdviseSink, Begin_OnSave)
          ;* [local] *
          STD_METHOD Begin_OnSave, :ptr AsyncIAdviseSink
          DECLSPEC_XFGVIRT(AsyncIAdviseSink, Finish_OnSave)
          ;* [local] *
          STD_METHOD Finish_OnSave, :ptr AsyncIAdviseSink
          DECLSPEC_XFGVIRT(AsyncIAdviseSink, Begin_OnClose)
          ;* [local] *
          STD_METHOD Begin_OnClose, :ptr AsyncIAdviseSink
          DECLSPEC_XFGVIRT(AsyncIAdviseSink, Finish_OnClose)
          ;* [local] *
          STD_METHOD Finish_OnClose, :ptr AsyncIAdviseSink
          ??Interface equ <>
          END_INTERFACE
        AsyncIAdviseSinkVtbl ends
        AsyncIAdviseSink struct
          lpVtbl POINTER ?
        AsyncIAdviseSink ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      AsyncIAdviseSink_Begin_RemoteOnDataChange_Proxy proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink, :ptr FORMATETC, :ptr ASYNC_STGMEDIUM
      ;* [unique][in] *
      AsyncIAdviseSink_Begin_RemoteOnDataChange_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      AsyncIAdviseSink_Finish_RemoteOnDataChange_Proxy proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink
      AsyncIAdviseSink_Finish_RemoteOnDataChange_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      AsyncIAdviseSink_Begin_RemoteOnViewChange_Proxy proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink, :DWORD, :LONG
      ;* [in] *
      AsyncIAdviseSink_Begin_RemoteOnViewChange_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      AsyncIAdviseSink_Finish_RemoteOnViewChange_Proxy proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink
      AsyncIAdviseSink_Finish_RemoteOnViewChange_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      AsyncIAdviseSink_Begin_RemoteOnRename_Proxy proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink, :ptr IMoniker
      ;* [in] *
      AsyncIAdviseSink_Begin_RemoteOnRename_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      AsyncIAdviseSink_Finish_RemoteOnRename_Proxy proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink
      AsyncIAdviseSink_Finish_RemoteOnRename_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      AsyncIAdviseSink_Begin_RemoteOnSave_Proxy proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink
      AsyncIAdviseSink_Begin_RemoteOnSave_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      AsyncIAdviseSink_Finish_RemoteOnSave_Proxy proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink
      AsyncIAdviseSink_Finish_RemoteOnSave_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      AsyncIAdviseSink_Begin_RemoteOnClose_Proxy proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink
      AsyncIAdviseSink_Begin_RemoteOnClose_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      AsyncIAdviseSink_Finish_RemoteOnClose_Proxy proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink
      AsyncIAdviseSink_Finish_RemoteOnClose_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __AsyncIAdviseSink_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_objidl_0000_0073 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_objidl_0000_0073_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_objidl_0000_0073_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IAdviseSink2_INTERFACE_DEFINED__
      __IAdviseSink2_INTERFACE_DEFINED__ equ <>
      ;* interface IAdviseSink2 *
      ;* [unique][async_uuid][uuid][object] *
      ;* [unique] *
      LPADVISESINK2 typedef ptr IAdviseSink2
      externdef IID_IAdviseSink2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IAdviseSink2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IAdviseSink2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IAdviseSink2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IAdviseSink2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IAdviseSink2
          DECLSPEC_XFGVIRT(IAdviseSink, OnDataChange)
          ;* [local] *
          ;* [annotation][unique][in] *
          ;* [annotation][unique][in] *
          STD_METHOD OnDataChange, :ptr IAdviseSink2, :ptr FORMATETC, :ptr STGMEDIUM
          DECLSPEC_XFGVIRT(IAdviseSink, OnViewChange)
          ;* [local] *
          ;* [in] *
          STD_METHOD OnViewChange, :ptr IAdviseSink2, :DWORD, :LONG
          ;* [in] *
          DECLSPEC_XFGVIRT(IAdviseSink, OnRename)
          ;* [local] *
          ;* [annotation][in] *
          STD_METHOD OnRename, :ptr IAdviseSink2, :ptr IMoniker
          DECLSPEC_XFGVIRT(IAdviseSink, OnSave)
          ;* [local] *
          STD_METHOD OnSave, :ptr IAdviseSink2
          DECLSPEC_XFGVIRT(IAdviseSink, OnClose)
          ;* [local] *
          STD_METHOD OnClose, :ptr IAdviseSink2
          DECLSPEC_XFGVIRT(IAdviseSink2, OnLinkSrcChange)
          ;* [local] *
          ;* [annotation][unique][in] *
          STD_METHOD OnLinkSrcChange, :ptr IAdviseSink2, :ptr IMoniker
          ??Interface equ <>
          END_INTERFACE
        IAdviseSink2Vtbl ends
        IAdviseSink2 struct
          lpVtbl POINTER ?
        IAdviseSink2 ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      IAdviseSink2_RemoteOnLinkSrcChange_Proxy proto WIN_STD_CALL_CONV :ptr IAdviseSink2, :ptr IMoniker
      ;* [unique][in] *
      IAdviseSink2_RemoteOnLinkSrcChange_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __IAdviseSink2_INTERFACE_DEFINED__ *
    endif
    ifndef __AsyncIAdviseSink2_INTERFACE_DEFINED__
      __AsyncIAdviseSink2_INTERFACE_DEFINED__ equ <>
      ;* interface AsyncIAdviseSink2 *
      ;* [uuid][unique][object] *
      externdef IID_AsyncIAdviseSink2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        AsyncIAdviseSink2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <AsyncIAdviseSink2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr AsyncIAdviseSink2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr AsyncIAdviseSink2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr AsyncIAdviseSink2
          DECLSPEC_XFGVIRT(AsyncIAdviseSink, Begin_OnDataChange)
          ;* [local] *
          ;* [annotation][unique][in] *
          ;* [annotation][unique][in] *
          STD_METHOD Begin_OnDataChange, :ptr AsyncIAdviseSink2, :ptr FORMATETC, :ptr STGMEDIUM
          DECLSPEC_XFGVIRT(AsyncIAdviseSink, Finish_OnDataChange)
          ;* [local] *
          STD_METHOD Finish_OnDataChange, :ptr AsyncIAdviseSink2
          DECLSPEC_XFGVIRT(AsyncIAdviseSink, Begin_OnViewChange)
          ;* [local] *
          ;* [in] *
          STD_METHOD Begin_OnViewChange, :ptr AsyncIAdviseSink2, :DWORD, :LONG
          ;* [in] *
          DECLSPEC_XFGVIRT(AsyncIAdviseSink, Finish_OnViewChange)
          ;* [local] *
          STD_METHOD Finish_OnViewChange, :ptr AsyncIAdviseSink2
          DECLSPEC_XFGVIRT(AsyncIAdviseSink, Begin_OnRename)
          ;* [local] *
          ;* [annotation][in] *
          STD_METHOD Begin_OnRename, :ptr AsyncIAdviseSink2, :ptr IMoniker
          DECLSPEC_XFGVIRT(AsyncIAdviseSink, Finish_OnRename)
          ;* [local] *
          STD_METHOD Finish_OnRename, :ptr AsyncIAdviseSink2
          DECLSPEC_XFGVIRT(AsyncIAdviseSink, Begin_OnSave)
          ;* [local] *
          STD_METHOD Begin_OnSave, :ptr AsyncIAdviseSink2
          DECLSPEC_XFGVIRT(AsyncIAdviseSink, Finish_OnSave)
          ;* [local] *
          STD_METHOD Finish_OnSave, :ptr AsyncIAdviseSink2
          DECLSPEC_XFGVIRT(AsyncIAdviseSink, Begin_OnClose)
          ;* [local] *
          STD_METHOD Begin_OnClose, :ptr AsyncIAdviseSink2
          DECLSPEC_XFGVIRT(AsyncIAdviseSink, Finish_OnClose)
          ;* [local] *
          STD_METHOD Finish_OnClose, :ptr AsyncIAdviseSink2
          DECLSPEC_XFGVIRT(AsyncIAdviseSink2, Begin_OnLinkSrcChange)
          ;* [local] *
          ;* [annotation][unique][in] *
          STD_METHOD Begin_OnLinkSrcChange, :ptr AsyncIAdviseSink2, :ptr IMoniker
          DECLSPEC_XFGVIRT(AsyncIAdviseSink2, Finish_OnLinkSrcChange)
          ;* [local] *
          STD_METHOD Finish_OnLinkSrcChange, :ptr AsyncIAdviseSink2
          ??Interface equ <>
          END_INTERFACE
        AsyncIAdviseSink2Vtbl ends
        AsyncIAdviseSink2 struct
          lpVtbl POINTER ?
        AsyncIAdviseSink2 ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      AsyncIAdviseSink2_Begin_RemoteOnLinkSrcChange_Proxy proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink2, :ptr IMoniker
      ;* [unique][in] *
      AsyncIAdviseSink2_Begin_RemoteOnLinkSrcChange_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      AsyncIAdviseSink2_Finish_RemoteOnLinkSrcChange_Proxy proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink2
      AsyncIAdviseSink2_Finish_RemoteOnLinkSrcChange_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __AsyncIAdviseSink2_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_objidl_0000_0074 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    externdef __MIDL_itf_objidl_0000_0074_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_objidl_0000_0074_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IDataObject_INTERFACE_DEFINED__
      __IDataObject_INTERFACE_DEFINED__ equ <>
      ;* interface IDataObject *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPDATAOBJECT typedef ptr IDataObject
      DATADIR typedef SDWORD
      DATADIR_GET equ 1
      DATADIR_SET equ 2
      tagDATADIR typedef DATADIR

      externdef IID_IDataObject:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IDataObjectVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IDataObjectVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IDataObject, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IDataObject
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IDataObject
          DECLSPEC_XFGVIRT(IDataObject, GetData)
          ;* [local] *
          ;* [annotation][unique][in] *
          ;* [annotation][out] *
          STD_METHOD GetData, :ptr IDataObject, :ptr FORMATETC, :ptr STGMEDIUM
          DECLSPEC_XFGVIRT(IDataObject, GetDataHere)
          ;* [local] *
          ;* [annotation][unique][in] *
          ;* [annotation][out][in] *
          STD_METHOD GetDataHere, :ptr IDataObject, :ptr FORMATETC, :ptr STGMEDIUM
          DECLSPEC_XFGVIRT(IDataObject, QueryGetData)
          STD_METHOD QueryGetData, :ptr IDataObject, :ptr FORMATETC
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IDataObject, GetCanonicalFormatEtc)
          ;* [unique][in] *
          STD_METHOD GetCanonicalFormatEtc, :ptr IDataObject, :ptr FORMATETC, :ptr FORMATETC
          ;* [out] *
          DECLSPEC_XFGVIRT(IDataObject, SetData)
          ;* [local] *
          ;* [annotation][unique][in] *
          ;* [annotation][unique][in] *
          STD_METHOD SetData, :ptr IDataObject, :ptr FORMATETC, :ptr STGMEDIUM, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IDataObject, EnumFormatEtc)
          ;* [in] *
          STD_METHOD EnumFormatEtc, :ptr IDataObject, :DWORD, :ptr ptr IEnumFORMATETC
          ;* [out] *
          DECLSPEC_XFGVIRT(IDataObject, DAdvise)
          ;* [in] *
          ;* [in] *
          ;* [unique][in] *
          STD_METHOD DAdvise, :ptr IDataObject, :ptr FORMATETC, :DWORD, :ptr IAdviseSink, :ptr DWORD
          ;* [out] *
          DECLSPEC_XFGVIRT(IDataObject, DUnadvise)
          STD_METHOD DUnadvise, :ptr IDataObject, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IDataObject, EnumDAdvise)
          STD_METHOD EnumDAdvise, :ptr IDataObject, :ptr ptr IEnumSTATDATA
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IDataObjectVtbl ends
        IDataObject struct
          lpVtbl POINTER ?
        IDataObject ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      IDataObject_RemoteGetData_Proxy proto WIN_STD_CALL_CONV :ptr IDataObject, :ptr FORMATETC, :ptr STGMEDIUM
      ;* [out] *
      IDataObject_RemoteGetData_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      IDataObject_RemoteGetDataHere_Proxy proto WIN_STD_CALL_CONV :ptr IDataObject, :ptr FORMATETC, :ptr STGMEDIUM
      ;* [out][in] *
      IDataObject_RemoteGetDataHere_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      IDataObject_RemoteSetData_Proxy proto WIN_STD_CALL_CONV :ptr IDataObject, :ptr FORMATETC, :ptr FLAG_STGMEDIUM, :BOOL
      ;* [in] *
      IDataObject_RemoteSetData_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __IDataObject_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_objidl_0000_0075 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    externdef __MIDL_itf_objidl_0000_0075_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_objidl_0000_0075_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IDataAdviseHolder_INTERFACE_DEFINED__
      __IDataAdviseHolder_INTERFACE_DEFINED__ equ <>
      ;* interface IDataAdviseHolder *
      ;* [uuid][object][local] *
      ;* [unique] *
      LPDATAADVISEHOLDER typedef ptr IDataAdviseHolder
      externdef IID_IDataAdviseHolder:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IDataAdviseHolderVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IDataAdviseHolderVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IDataAdviseHolder, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IDataAdviseHolder
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IDataAdviseHolder
          DECLSPEC_XFGVIRT(IDataAdviseHolder, Advise)
          ;* [annotation][unique][in] *
          ;* [annotation][unique][in] *
          ;* [annotation][in] *
          ;* [annotation][unique][in] *
          ;* [annotation][out] *
          STD_METHOD Advise, :ptr IDataAdviseHolder, :ptr IDataObject, :ptr FORMATETC, :DWORD, :ptr IAdviseSink, :ptr DWORD
          DECLSPEC_XFGVIRT(IDataAdviseHolder, Unadvise)
          ;* [annotation][in] *
          STD_METHOD Unadvise, :ptr IDataAdviseHolder, :DWORD
          DECLSPEC_XFGVIRT(IDataAdviseHolder, EnumAdvise)
          ;* [annotation][out] *
          STD_METHOD EnumAdvise, :ptr IDataAdviseHolder, :ptr ptr IEnumSTATDATA
          DECLSPEC_XFGVIRT(IDataAdviseHolder, SendOnDataChange)
          ;* [annotation][unique][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          STD_METHOD SendOnDataChange, :ptr IDataAdviseHolder, :ptr IDataObject, :DWORD, :DWORD
          ??Interface equ <>
          END_INTERFACE
        IDataAdviseHolderVtbl ends
        IDataAdviseHolder struct
          lpVtbl POINTER ?
        IDataAdviseHolder ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IDataAdviseHolder_INTERFACE_DEFINED__ *
    endif
    ifndef __IMessageFilter_INTERFACE_DEFINED__
      __IMessageFilter_INTERFACE_DEFINED__ equ <>
      ;* interface IMessageFilter *
      ;* [uuid][object][local] *
      ;* [unique] *
      LPMESSAGEFILTER typedef ptr IMessageFilter
      CALLTYPE typedef SDWORD
      CALLTYPE_TOPLEVEL equ 1
      CALLTYPE_NESTED equ 2
      CALLTYPE_ASYNC equ 3
      CALLTYPE_TOPLEVEL_CALLPENDING equ 4
      CALLTYPE_ASYNC_CALLPENDING equ 5
      tagCALLTYPE typedef CALLTYPE

      SERVERCALL typedef SDWORD
      SERVERCALL_ISHANDLED equ 0
      SERVERCALL_REJECTED equ 1
      SERVERCALL_RETRYLATER equ 2
      tagSERVERCALL typedef SERVERCALL

      PENDINGTYPE typedef SDWORD
      PENDINGTYPE_TOPLEVEL equ 1
      PENDINGTYPE_NESTED equ 2
      tagPENDINGTYPE typedef PENDINGTYPE

      PENDINGMSG typedef SDWORD
      PENDINGMSG_CANCELCALL equ 0
      PENDINGMSG_WAITNOPROCESS equ 1
      PENDINGMSG_WAITDEFPROCESS equ 2
      tagPENDINGMSG typedef PENDINGMSG

      INTERFACEINFO struct
        pUnk POINTER ?
        iid IID <>
        wMethod WORD ?
      INTERFACEINFO ends
      tagINTERFACEINFO typedef INTERFACEINFO
      LPINTERFACEINFO typedef ptr tagINTERFACEINFO
      externdef IID_IMessageFilter:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IMessageFilterVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IMessageFilterVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IMessageFilter, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IMessageFilter
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IMessageFilter
          DECLSPEC_XFGVIRT(IMessageFilter, HandleInComingCall)
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          STD_METHOD HandleInComingCall, :ptr IMessageFilter, :DWORD, :HTASK, :DWORD, :LPINTERFACEINFO
          DECLSPEC_XFGVIRT(IMessageFilter, RetryRejectedCall)
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          STD_METHOD RetryRejectedCall, :ptr IMessageFilter, :HTASK, :DWORD, :DWORD
          DECLSPEC_XFGVIRT(IMessageFilter, MessagePending)
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          STD_METHOD MessagePending, :ptr IMessageFilter, :HTASK, :DWORD, :DWORD
          ??Interface equ <>
          END_INTERFACE
        IMessageFilterVtbl ends
        IMessageFilter struct
          lpVtbl POINTER ?
        IMessageFilter ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IMessageFilter_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_objidl_0000_0077 *
    ;* [local] *
    ; Well-known Property Set Format IDs
    externdef FMTID_SummaryInformation:FMTID
    externdef FMTID_DocSummaryInformation:FMTID
    externdef FMTID_UserDefinedProperties:FMTID
    externdef FMTID_DiscardableInformation:FMTID
    externdef FMTID_ImageSummaryInformation:FMTID
    externdef FMTID_AudioSummaryInformation:FMTID
    externdef FMTID_VideoSummaryInformation:FMTID
    externdef FMTID_MediaFileSummaryInformation:FMTID
    externdef __MIDL_itf_objidl_0000_0077_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_objidl_0000_0077_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IClassActivator_INTERFACE_DEFINED__
      __IClassActivator_INTERFACE_DEFINED__ equ <>
      ;* interface IClassActivator *
      ;* [uuid][object] *
      externdef IID_IClassActivator:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IClassActivatorVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IClassActivatorVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IClassActivator, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IClassActivator
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IClassActivator
          DECLSPEC_XFGVIRT(IClassActivator, GetClassObject)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD GetClassObject, :ptr IClassActivator, :REFCLSID, :DWORD, :LCID, :REFIID, :ptr ptr
          ;* [iid_is][out] *
          ??Interface equ <>
          END_INTERFACE
        IClassActivatorVtbl ends
        IClassActivator struct
          lpVtbl POINTER ?
        IClassActivator ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IClassActivator_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_objidl_0000_0078 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_objidl_0000_0078_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_objidl_0000_0078_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IFillLockBytes_INTERFACE_DEFINED__
      __IFillLockBytes_INTERFACE_DEFINED__ equ <>
      ;* interface IFillLockBytes *
      ;* [unique][uuid][object] *
      externdef IID_IFillLockBytes:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IFillLockBytesVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IFillLockBytesVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IFillLockBytes, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IFillLockBytes
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IFillLockBytes
          DECLSPEC_XFGVIRT(IFillLockBytes, FillAppend)
          ;* [local] *
          ;* [annotation][size_is][in] *
          ;* [annotation][in] *
          ;* [annotation][out] *
          STD_METHOD FillAppend, :ptr IFillLockBytes, :ptr, :ULONG, :ptr ULONG
          DECLSPEC_XFGVIRT(IFillLockBytes, FillAt)
          ;* [local] *
          ;* [annotation][in] *
          ;* [annotation][size_is][in] *
          ;* [annotation][in] *
          ;* [annotation][out] *
          STD_METHOD FillAt, :ptr IFillLockBytes, :ULARGE_INTEGER, :ptr, :ULONG, :ptr ULONG
          DECLSPEC_XFGVIRT(IFillLockBytes, SetFillSize)
          STD_METHOD SetFillSize, :ptr IFillLockBytes, :ULARGE_INTEGER
          ;* [in] *
          DECLSPEC_XFGVIRT(IFillLockBytes, Terminate)
          STD_METHOD Terminate, :ptr IFillLockBytes, :BOOL
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IFillLockBytesVtbl ends
        IFillLockBytes struct
          lpVtbl POINTER ?
        IFillLockBytes ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      IFillLockBytes_RemoteFillAppend_Proxy proto WIN_STD_CALL_CONV :ptr IFillLockBytes, :ptr byte, :ULONG, :ptr ULONG
      ;* [out] *
      IFillLockBytes_RemoteFillAppend_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      IFillLockBytes_RemoteFillAt_Proxy proto WIN_STD_CALL_CONV :ptr IFillLockBytes, :ULARGE_INTEGER, :ptr byte, :ULONG, :ptr ULONG
      ;* [out] *
      IFillLockBytes_RemoteFillAt_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __IFillLockBytes_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_objidl_0000_0079 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_objidl_0000_0079_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_objidl_0000_0079_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IProgressNotify_INTERFACE_DEFINED__
      __IProgressNotify_INTERFACE_DEFINED__ equ <>
      ;* interface IProgressNotify *
      ;* [unique][uuid][object] *
      externdef IID_IProgressNotify:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IProgressNotifyVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IProgressNotifyVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IProgressNotify, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IProgressNotify
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IProgressNotify
          DECLSPEC_XFGVIRT(IProgressNotify, OnProgress)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD OnProgress, :ptr IProgressNotify, :DWORD, :DWORD, :BOOL, :BOOL
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IProgressNotifyVtbl ends
        IProgressNotify struct
          lpVtbl POINTER ?
        IProgressNotify ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IProgressNotify_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_objidl_0000_0080 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_objidl_0000_0080_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_objidl_0000_0080_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ILayoutStorage_INTERFACE_DEFINED__
      __ILayoutStorage_INTERFACE_DEFINED__ equ <>
      ;* interface ILayoutStorage *
      ;* [unique][uuid][object][local] *
      StorageLayout struct
        LayoutType DWORD ?
        pwcsElementName POINTER ?
        cOffset LARGE_INTEGER <>
        cBytes LARGE_INTEGER <>
      StorageLayout ends
      tagStorageLayout typedef StorageLayout
      externdef IID_ILayoutStorage:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ILayoutStorageVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ILayoutStorageVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ILayoutStorage, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ILayoutStorage
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ILayoutStorage
          DECLSPEC_XFGVIRT(ILayoutStorage, LayoutScript)
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          STD_METHOD LayoutScript, :ptr ILayoutStorage, :ptr StorageLayout, :DWORD, :DWORD
          DECLSPEC_XFGVIRT(ILayoutStorage, BeginMonitor)
          STD_METHOD BeginMonitor, :ptr ILayoutStorage
          DECLSPEC_XFGVIRT(ILayoutStorage, EndMonitor)
          STD_METHOD EndMonitor, :ptr ILayoutStorage
          DECLSPEC_XFGVIRT(ILayoutStorage, ReLayoutDocfile)
          ;* [annotation][in] *
          STD_METHOD ReLayoutDocfile, :ptr ILayoutStorage, :ptr OLECHAR
          DECLSPEC_XFGVIRT(ILayoutStorage, ReLayoutDocfileOnILockBytes)
          ;* [annotation][in] *
          STD_METHOD ReLayoutDocfileOnILockBytes, :ptr ILayoutStorage, :ptr ILockBytes
          ??Interface equ <>
          END_INTERFACE
        ILayoutStorageVtbl ends
        ILayoutStorage struct
          lpVtbl POINTER ?
        ILayoutStorage ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ILayoutStorage_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_objidl_0000_0081 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_objidl_0000_0081_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_objidl_0000_0081_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IBlockingLock_INTERFACE_DEFINED__
      __IBlockingLock_INTERFACE_DEFINED__ equ <>
      ;* interface IBlockingLock *
      ;* [uuid][object] *
      externdef IID_IBlockingLock:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IBlockingLockVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IBlockingLockVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IBlockingLock, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IBlockingLock
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IBlockingLock
          DECLSPEC_XFGVIRT(IBlockingLock, Lock)
          STD_METHOD Lock_, :ptr IBlockingLock, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IBlockingLock, Unlock)
          STD_METHOD Unlock, :ptr IBlockingLock
          ??Interface equ <>
          END_INTERFACE
        IBlockingLockVtbl ends
        IBlockingLock struct
          lpVtbl POINTER ?
        IBlockingLock ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IBlockingLock_INTERFACE_DEFINED__ *
    endif
    ifndef __ITimeAndNoticeControl_INTERFACE_DEFINED__
      __ITimeAndNoticeControl_INTERFACE_DEFINED__ equ <>
      ;* interface ITimeAndNoticeControl *
      ;* [uuid][object] *
      externdef IID_ITimeAndNoticeControl:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ITimeAndNoticeControlVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ITimeAndNoticeControlVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ITimeAndNoticeControl, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ITimeAndNoticeControl
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ITimeAndNoticeControl
          DECLSPEC_XFGVIRT(ITimeAndNoticeControl, SuppressChanges)
          ;* [in] *
          STD_METHOD SuppressChanges, :ptr ITimeAndNoticeControl, :DWORD, :DWORD
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        ITimeAndNoticeControlVtbl ends
        ITimeAndNoticeControl struct
          lpVtbl POINTER ?
        ITimeAndNoticeControl ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ITimeAndNoticeControl_INTERFACE_DEFINED__ *
    endif
    ifndef __IOplockStorage_INTERFACE_DEFINED__
      __IOplockStorage_INTERFACE_DEFINED__ equ <>
      ;* interface IOplockStorage *
      ;* [uuid][object] *
      externdef IID_IOplockStorage:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IOplockStorageVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IOplockStorageVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IOplockStorage, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IOplockStorage
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IOplockStorage
          DECLSPEC_XFGVIRT(IOplockStorage, CreateStorageEx)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD CreateStorageEx, :ptr IOplockStorage, :LPCWSTR, :DWORD, :DWORD, :DWORD, :REFIID, :ptr ptr
          ;* [iid_is][out] *
          DECLSPEC_XFGVIRT(IOplockStorage, OpenStorageEx)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD OpenStorageEx, :ptr IOplockStorage, :LPCWSTR, :DWORD, :DWORD, :DWORD, :REFIID, :ptr ptr
          ;* [iid_is][out] *
          ??Interface equ <>
          END_INTERFACE
        IOplockStorageVtbl ends
        IOplockStorage struct
          lpVtbl POINTER ?
        IOplockStorage ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IOplockStorage_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_objidl_0000_0084 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_objidl_0000_0084_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_objidl_0000_0084_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IDirectWriterLock_INTERFACE_DEFINED__
      __IDirectWriterLock_INTERFACE_DEFINED__ equ <>
      ;* interface IDirectWriterLock *
      ;* [unique][uuid][object] *
      externdef IID_IDirectWriterLock:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IDirectWriterLockVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IDirectWriterLockVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IDirectWriterLock, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IDirectWriterLock
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IDirectWriterLock
          DECLSPEC_XFGVIRT(IDirectWriterLock, WaitForWriteAccess)
          STD_METHOD WaitForWriteAccess, :ptr IDirectWriterLock, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IDirectWriterLock, ReleaseWriteAccess)
          STD_METHOD ReleaseWriteAccess, :ptr IDirectWriterLock
          DECLSPEC_XFGVIRT(IDirectWriterLock, HaveWriteAccess)
          STD_METHOD HaveWriteAccess, :ptr IDirectWriterLock
          ??Interface equ <>
          END_INTERFACE
        IDirectWriterLockVtbl ends
        IDirectWriterLock struct
          lpVtbl POINTER ?
        IDirectWriterLock ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IDirectWriterLock_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_objidl_0000_0085 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_objidl_0000_0085_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_objidl_0000_0085_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IUrlMon_INTERFACE_DEFINED__
      __IUrlMon_INTERFACE_DEFINED__ equ <>
      ;* interface IUrlMon *
      ;* [uuid][object] *
      externdef IID_IUrlMon:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IUrlMonVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IUrlMonVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IUrlMon, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IUrlMon
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IUrlMon
          DECLSPEC_XFGVIRT(IUrlMon, AsyncGetClassBits)
          ;* [in] *
          ;* [unique][in] *
          ;* [unique][in] *
          ;* [in] *
          ;* [in] *
          ;* [unique][in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD AsyncGetClassBits, :ptr IUrlMon, :REFCLSID, :LPCWSTR, :LPCWSTR, :DWORD, :DWORD, :LPCWSTR, :ptr IBindCtx, :DWORD, :REFIID, :DWORD
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IUrlMonVtbl ends
        IUrlMon struct
          lpVtbl POINTER ?
        IUrlMon ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IUrlMon_INTERFACE_DEFINED__ *
    endif
    ifndef __IForegroundTransfer_INTERFACE_DEFINED__
      __IForegroundTransfer_INTERFACE_DEFINED__ equ <>
      ;* interface IForegroundTransfer *
      ;* [uuid][object][local] *
      externdef IID_IForegroundTransfer:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IForegroundTransferVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IForegroundTransferVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IForegroundTransfer, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IForegroundTransfer
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IForegroundTransfer
          DECLSPEC_XFGVIRT(IForegroundTransfer, AllowForegroundTransfer)
          ;* [annotation][in] *
          STD_METHOD AllowForegroundTransfer, :ptr IForegroundTransfer, :ptr
          ??Interface equ <>
          END_INTERFACE
        IForegroundTransferVtbl ends
        IForegroundTransfer struct
          lpVtbl POINTER ?
        IForegroundTransfer ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IForegroundTransfer_INTERFACE_DEFINED__ *
    endif
    ifndef __IThumbnailExtractor_INTERFACE_DEFINED__
      __IThumbnailExtractor_INTERFACE_DEFINED__ equ <>
      ;* interface IThumbnailExtractor *
      ;* [object][uuid] *
      externdef IID_IThumbnailExtractor:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IThumbnailExtractorVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IThumbnailExtractorVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IThumbnailExtractor, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IThumbnailExtractor
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IThumbnailExtractor
          DECLSPEC_XFGVIRT(IThumbnailExtractor, ExtractThumbnail)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [out] *
          ;* [out] *
          STD_METHOD ExtractThumbnail, :ptr IThumbnailExtractor, :ptr IStorage, :ULONG, :ULONG, :ptr ULONG, :ptr ULONG, :ptr HBITMAP
          ;* [out] *
          DECLSPEC_XFGVIRT(IThumbnailExtractor, OnFileUpdated)
          STD_METHOD OnFileUpdated, :ptr IThumbnailExtractor, :ptr IStorage
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IThumbnailExtractorVtbl ends
        IThumbnailExtractor struct
          lpVtbl POINTER ?
        IThumbnailExtractor ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IThumbnailExtractor_INTERFACE_DEFINED__ *
    endif
    ifndef __IDummyHICONIncluder_INTERFACE_DEFINED__
      __IDummyHICONIncluder_INTERFACE_DEFINED__ equ <>
      ;* interface IDummyHICONIncluder *
      ;* [uuid][unique][object] *
      externdef IID_IDummyHICONIncluder:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IDummyHICONIncluderVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IDummyHICONIncluderVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IDummyHICONIncluder, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IDummyHICONIncluder
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IDummyHICONIncluder
          DECLSPEC_XFGVIRT(IDummyHICONIncluder, Dummy)
          ;* [in] *
          STD_METHOD Dummy, :ptr IDummyHICONIncluder, :HICON, :HDC
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IDummyHICONIncluderVtbl ends
        IDummyHICONIncluder struct
          lpVtbl POINTER ?
        IDummyHICONIncluder ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IDummyHICONIncluder_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_objidl_0000_0089 *
    ;* [local] *
    ApplicationType typedef SDWORD
    ServerApplication equ 0
    LibraryApplication equ
    tagApplicationType typedef ApplicationType

    ShutdownType typedef SDWORD
    IdleShutdown equ 0
    ForcedShutdown equ
    tagShutdownType typedef ShutdownType

    externdef __MIDL_itf_objidl_0000_0089_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_objidl_0000_0089_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IProcessLock_INTERFACE_DEFINED__
      __IProcessLock_INTERFACE_DEFINED__ equ <>
      ;* interface IProcessLock *
      ;* [unique][uuid][local][object] *
      externdef IID_IProcessLock:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IProcessLockVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IProcessLockVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IProcessLock, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IProcessLock
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IProcessLock
          DECLSPEC_XFGVIRT(IProcessLock, AddRefOnProcess)
          STD_METHOD AddRefOnProcess, :ptr IProcessLock
          DECLSPEC_XFGVIRT(IProcessLock, ReleaseRefOnProcess)
          STD_METHOD ReleaseRefOnProcess, :ptr IProcessLock
          ??Interface equ <>
          END_INTERFACE
        IProcessLockVtbl ends
        IProcessLock struct
          lpVtbl POINTER ?
        IProcessLock ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IProcessLock_INTERFACE_DEFINED__ *
    endif
    ifndef __ISurrogateService_INTERFACE_DEFINED__
      __ISurrogateService_INTERFACE_DEFINED__ equ <>
      ;* interface ISurrogateService *
      ;* [unique][uuid][local][object] *
      externdef IID_ISurrogateService:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISurrogateServiceVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISurrogateServiceVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISurrogateService, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISurrogateService
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISurrogateService
          DECLSPEC_XFGVIRT(ISurrogateService, Init)
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][out] *
          STD_METHOD Init, :ptr ISurrogateService, :REFGUID, :ptr IProcessLock, :ptr BOOL
          DECLSPEC_XFGVIRT(ISurrogateService, ApplicationLaunch)
          ;* [annotation][in] *
          ;* [annotation][in] *
          STD_METHOD ApplicationLaunch, :ptr ISurrogateService, :REFGUID, :ApplicationType
          DECLSPEC_XFGVIRT(ISurrogateService, ApplicationFree)
          ;* [annotation][in] *
          STD_METHOD ApplicationFree, :ptr ISurrogateService, :REFGUID
          DECLSPEC_XFGVIRT(ISurrogateService, CatalogRefresh)
          ;* [annotation][in] *
          STD_METHOD CatalogRefresh, :ptr ISurrogateService, :ULONG
          DECLSPEC_XFGVIRT(ISurrogateService, ProcessShutdown)
          ;* [annotation][in] *
          STD_METHOD ProcessShutdown, :ptr ISurrogateService, :ShutdownType
          ??Interface equ <>
          END_INTERFACE
        ISurrogateServiceVtbl ends
        ISurrogateService struct
          lpVtbl POINTER ?
        ISurrogateService ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISurrogateService_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_objidl_0000_0091 *
    ;* [local] *
    if (_WIN32_WINNT ge 0501h)
      externdef __MIDL_itf_objidl_0000_0091_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_objidl_0000_0091_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IInitializeSpy_INTERFACE_DEFINED__
        __IInitializeSpy_INTERFACE_DEFINED__ equ <>
        ;* interface IInitializeSpy *
        ;* [unique][uuid][object][local] *
        ;* [unique] *
        LPINITIALIZESPY typedef ptr IInitializeSpy
        externdef IID_IInitializeSpy:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IInitializeSpyVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IInitializeSpyVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IInitializeSpy, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IInitializeSpy
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IInitializeSpy
            DECLSPEC_XFGVIRT(IInitializeSpy, PreInitialize)
            ;* [annotation][in] *
            ;* [annotation][in] *
            STD_METHOD PreInitialize, :ptr IInitializeSpy, :DWORD, :DWORD
            DECLSPEC_XFGVIRT(IInitializeSpy, PostInitialize)
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            STD_METHOD PostInitialize, :ptr IInitializeSpy, :HRESULT, :DWORD, :DWORD
            DECLSPEC_XFGVIRT(IInitializeSpy, PreUninitialize)
            ;* [annotation][in] *
            STD_METHOD PreUninitialize, :ptr IInitializeSpy, :DWORD
            DECLSPEC_XFGVIRT(IInitializeSpy, PostUninitialize)
            ;* [annotation][in] *
            STD_METHOD PostUninitialize, :ptr IInitializeSpy, :DWORD
            ??Interface equ <>
            END_INTERFACE
          IInitializeSpyVtbl ends
          IInitializeSpy struct
            lpVtbl POINTER ?
          IInitializeSpy ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IInitializeSpy_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_objidl_0000_0092 *
      ;* [local] *
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_objidl_0000_0092_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_objidl_0000_0092_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IApartmentShutdown_INTERFACE_DEFINED__
      __IApartmentShutdown_INTERFACE_DEFINED__ equ <>
      ;* interface IApartmentShutdown *
      ;* [unique][uuid][object][local] *
      externdef IID_IApartmentShutdown:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IApartmentShutdownVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IApartmentShutdownVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IApartmentShutdown, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IApartmentShutdown
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IApartmentShutdown
          DECLSPEC_XFGVIRT(IApartmentShutdown, OnUninitialize)
          ;* [annotation][in] *
          STD_METHOD OnUninitialize, :ptr IApartmentShutdown, :UINT64
          ??Interface equ <>
          END_INTERFACE
        IApartmentShutdownVtbl ends
        IApartmentShutdown struct
          lpVtbl POINTER ?
        IApartmentShutdown ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IApartmentShutdown_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_objidl_0000_0093 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
  endif
  if (_MSC_VER ge 800)
    if _MSC_VER ge 1200
    else
    endif
  endif
  externdef __MIDL_itf_objidl_0000_0093_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_objidl_0000_0093_v0_0_s_ifspec:RPC_IF_HANDLE
  ;* Additional Prototypes for ALL interfaces *
  ASYNC_STGMEDIUM_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr ASYNC_STGMEDIUM
  ASYNC_STGMEDIUM_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr ASYNC_STGMEDIUM
  ASYNC_STGMEDIUM_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr ASYNC_STGMEDIUM
  ASYNC_STGMEDIUM_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr ASYNC_STGMEDIUM
  CLIPFORMAT_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr CLIPFORMAT
  CLIPFORMAT_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr CLIPFORMAT
  CLIPFORMAT_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr CLIPFORMAT
  CLIPFORMAT_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr CLIPFORMAT
  FLAG_STGMEDIUM_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr FLAG_STGMEDIUM
  FLAG_STGMEDIUM_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr FLAG_STGMEDIUM
  FLAG_STGMEDIUM_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr FLAG_STGMEDIUM
  FLAG_STGMEDIUM_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr FLAG_STGMEDIUM
  HBITMAP_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HBITMAP
  HBITMAP_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HBITMAP
  HBITMAP_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HBITMAP
  HBITMAP_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HBITMAP
  HDC_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HDC
  HDC_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HDC
  HDC_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HDC
  HDC_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HDC
  HICON_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HICON
  HICON_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HICON
  HICON_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HICON
  HICON_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HICON
  SNB_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr SNB
  SNB_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr SNB
  SNB_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr SNB
  SNB_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr SNB
  STGMEDIUM_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr STGMEDIUM
  STGMEDIUM_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr STGMEDIUM
  STGMEDIUM_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr STGMEDIUM
  STGMEDIUM_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr STGMEDIUM
  ASYNC_STGMEDIUM_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr ASYNC_STGMEDIUM
  ASYNC_STGMEDIUM_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr ASYNC_STGMEDIUM
  ASYNC_STGMEDIUM_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr ASYNC_STGMEDIUM
  ASYNC_STGMEDIUM_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr ASYNC_STGMEDIUM
  CLIPFORMAT_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr CLIPFORMAT
  CLIPFORMAT_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr CLIPFORMAT
  CLIPFORMAT_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr CLIPFORMAT
  CLIPFORMAT_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr CLIPFORMAT
  FLAG_STGMEDIUM_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr FLAG_STGMEDIUM
  FLAG_STGMEDIUM_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr FLAG_STGMEDIUM
  FLAG_STGMEDIUM_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr FLAG_STGMEDIUM
  FLAG_STGMEDIUM_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr FLAG_STGMEDIUM
  HBITMAP_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HBITMAP
  HBITMAP_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HBITMAP
  HBITMAP_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HBITMAP
  HBITMAP_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HBITMAP
  HDC_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HDC
  HDC_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HDC
  HDC_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HDC
  HDC_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HDC
  HICON_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HICON
  HICON_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HICON
  HICON_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HICON
  HICON_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HICON
  SNB_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr SNB
  SNB_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr SNB
  SNB_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr SNB
  SNB_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr SNB
  STGMEDIUM_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr STGMEDIUM
  STGMEDIUM_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr STGMEDIUM
  STGMEDIUM_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr STGMEDIUM
  STGMEDIUM_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr STGMEDIUM
  ;* [local] *
  IEnumUnknown_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumUnknown, :ULONG, :ptr ptr IUnknown, :ptr ULONG
  ;* [annotation][out] *
  ;* [call_as] *
  IEnumUnknown_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumUnknown, :ULONG, :ptr ptr IUnknown, :ptr ULONG
  ;* [out] *
  ;* [local] *
  IEnumString_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumString, :ULONG, :ptr LPOLESTR, :ptr ULONG
  ;* [annotation] *
  ;* [call_as] *
  IEnumString_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumString, :ULONG, :ptr LPOLESTR, :ptr ULONG
  ;* [out] *
  ;* [local] *
  ISequentialStream_Read_Proxy proto WIN_STD_CALL_CONV :ptr ISequentialStream, :ptr, :ULONG, :ptr ULONG
  ;* [annotation] *
  ;* [call_as] *
  ISequentialStream_Read_Stub proto WIN_STD_CALL_CONV :ptr ISequentialStream, :ptr byte, :ULONG, :ptr ULONG
  ;* [out] *
  ;* [local] *
  ISequentialStream_Write_Proxy proto WIN_STD_CALL_CONV :ptr ISequentialStream, :ptr, :ULONG, :ptr ULONG
  ;* [annotation] *
  ;* [call_as] *
  ISequentialStream_Write_Stub proto WIN_STD_CALL_CONV :ptr ISequentialStream, :ptr byte, :ULONG, :ptr ULONG
  ;* [out] *
  ;* [local] *
  IStream_Seek_Proxy proto WIN_STD_CALL_CONV :ptr IStream, :LARGE_INTEGER, :DWORD, :ptr ULARGE_INTEGER
  ;* [annotation] *
  ;* [call_as] *
  IStream_Seek_Stub proto WIN_STD_CALL_CONV :ptr IStream, :LARGE_INTEGER, :DWORD, :ptr ULARGE_INTEGER
  ;* [out] *
  ;* [local] *
  IStream_CopyTo_Proxy proto WIN_STD_CALL_CONV :ptr IStream, :ptr IStream, :ULARGE_INTEGER, :ptr ULARGE_INTEGER, :ptr ULARGE_INTEGER
  ;* [annotation] *
  ;* [call_as] *
  IStream_CopyTo_Stub proto WIN_STD_CALL_CONV :ptr IStream, :ptr IStream, :ULARGE_INTEGER, :ptr ULARGE_INTEGER, :ptr ULARGE_INTEGER
  ;* [out] *
  ;* [local] *
  IBindCtx_SetBindOptions_Proxy proto WIN_STD_CALL_CONV :ptr IBindCtx, :ptr BIND_OPTS
  ;* [annotation][in] *
  ;* [call_as] *
  IBindCtx_SetBindOptions_Stub proto WIN_STD_CALL_CONV :ptr IBindCtx, :ptr BIND_OPTS2
  ;* [in] *
  ;* [local] *
  IBindCtx_GetBindOptions_Proxy proto WIN_STD_CALL_CONV :ptr IBindCtx, :ptr BIND_OPTS
  ;* [annotation][out][in] *
  ;* [call_as] *
  IBindCtx_GetBindOptions_Stub proto WIN_STD_CALL_CONV :ptr IBindCtx, :ptr BIND_OPTS2
  ;* [out][in] *
  ;* [local] *
  IEnumMoniker_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumMoniker, :ULONG, :ptr ptr IMoniker, :ptr ULONG
  ;* [annotation] *
  ;* [call_as] *
  IEnumMoniker_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumMoniker, :ULONG, :ptr ptr IMoniker, :ptr ULONG
  ;* [out] *
  ;* [local] *
  IRunnableObject_IsRunning_Proxy proto WIN_STD_CALL_CONV :ptr IRunnableObject
  ;* [call_as] *
  IRunnableObject_IsRunning_Stub proto WIN_STD_CALL_CONV :ptr IRunnableObject
  ;* [local] *
  IMoniker_BindToObject_Proxy proto WIN_STD_CALL_CONV :ptr IMoniker, :ptr IBindCtx, :ptr IMoniker, :REFIID, :ptr ptr
  ;* [annotation][iid_is][out] *
  ;* [call_as] *
  IMoniker_BindToObject_Stub proto WIN_STD_CALL_CONV :ptr IMoniker, :ptr IBindCtx, :ptr IMoniker, :REFIID, :ptr ptr IUnknown
  ;* [iid_is][out] *
  ;* [local] *
  IMoniker_BindToStorage_Proxy proto WIN_STD_CALL_CONV :ptr IMoniker, :ptr IBindCtx, :ptr IMoniker, :REFIID, :ptr ptr
  ;* [annotation][iid_is][out] *
  ;* [call_as] *
  IMoniker_BindToStorage_Stub proto WIN_STD_CALL_CONV :ptr IMoniker, :ptr IBindCtx, :ptr IMoniker, :REFIID, :ptr ptr IUnknown
  ;* [iid_is][out] *
  ;* [local] *
  IEnumSTATSTG_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumSTATSTG, :ULONG, :ptr STATSTG, :ptr ULONG
  ;* [annotation] *
  ;* [call_as] *
  IEnumSTATSTG_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumSTATSTG, :ULONG, :ptr STATSTG, :ptr ULONG
  ;* [out] *
  ;* [local] *
  IStorage_OpenStream_Proxy proto WIN_STD_CALL_CONV :ptr IStorage, :ptr OLECHAR, :ptr, :DWORD, :DWORD, :ptr ptr IStream
  ;* [annotation][out] *
  ;* [call_as] *
  IStorage_OpenStream_Stub proto WIN_STD_CALL_CONV :ptr IStorage, :ptr OLECHAR, :ULONG, :ptr byte, :DWORD, :DWORD, :ptr ptr IStream
  ;* [out] *
  ;* [local] *
  IStorage_CopyTo_Proxy proto WIN_STD_CALL_CONV :ptr IStorage, :DWORD, :ptr IID, :SNB, :ptr IStorage
  ;* [annotation][unique][in] *
  ;* [call_as] *
  IStorage_CopyTo_Stub proto WIN_STD_CALL_CONV :ptr IStorage, :DWORD, :ptr IID, :SNB, :ptr IStorage
  ;* [unique][in] *
  ;* [local] *
  IStorage_EnumElements_Proxy proto WIN_STD_CALL_CONV :ptr IStorage, :DWORD, :ptr, :DWORD, :ptr ptr IEnumSTATSTG
  ;* [annotation][out] *
  ;* [call_as] *
  IStorage_EnumElements_Stub proto WIN_STD_CALL_CONV :ptr IStorage, :DWORD, :ULONG, :ptr byte, :DWORD, :ptr ptr IEnumSTATSTG
  ;* [out] *
  ;* [local] *
  ILockBytes_ReadAt_Proxy proto WIN_STD_CALL_CONV :ptr ILockBytes, :ULARGE_INTEGER, :ptr, :ULONG, :ptr ULONG
  ;* [annotation][out] *
  ;* [call_as] *
  ILockBytes_ReadAt_Stub proto WIN_STD_CALL_CONV :ptr ILockBytes, :ULARGE_INTEGER, :ptr byte, :ULONG, :ptr ULONG
  ;* [out] *
  ;* [local] *
  ILockBytes_WriteAt_Proxy proto WIN_STD_CALL_CONV :ptr ILockBytes, :ULARGE_INTEGER, :ptr, :ULONG, :ptr ULONG
  ;* [annotation][out] *
  ;* [call_as] *
  ILockBytes_WriteAt_Stub proto WIN_STD_CALL_CONV :ptr ILockBytes, :ULARGE_INTEGER, :ptr byte, :ULONG, :ptr ULONG
  ;* [out] *
  ;* [local] *
  IEnumFORMATETC_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumFORMATETC, :ULONG, :ptr FORMATETC, :ptr ULONG
  ;* [annotation] *
  ;* [call_as] *
  IEnumFORMATETC_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumFORMATETC, :ULONG, :ptr FORMATETC, :ptr ULONG
  ;* [out] *
  ;* [local] *
  IEnumSTATDATA_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumSTATDATA, :ULONG, :ptr STATDATA, :ptr ULONG
  ;* [annotation] *
  ;* [call_as] *
  IEnumSTATDATA_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumSTATDATA, :ULONG, :ptr STATDATA, :ptr ULONG
  ;* [out] *
  ;* [local] *
  IAdviseSink_OnDataChange_Proxy proto WIN_STD_CALL_CONV :ptr IAdviseSink, :ptr FORMATETC, :ptr STGMEDIUM
  ;* [annotation][unique][in] *
  ;* [call_as] *
  IAdviseSink_OnDataChange_Stub proto WIN_STD_CALL_CONV :ptr IAdviseSink, :ptr FORMATETC, :ptr ASYNC_STGMEDIUM
  ;* [unique][in] *
  ;* [local] *
  IAdviseSink_OnViewChange_Proxy proto WIN_STD_CALL_CONV :ptr IAdviseSink, :DWORD, :LONG
  ;* [in] *
  ;* [call_as] *
  IAdviseSink_OnViewChange_Stub proto WIN_STD_CALL_CONV :ptr IAdviseSink, :DWORD, :LONG
  ;* [in] *
  ;* [local] *
  IAdviseSink_OnRename_Proxy proto WIN_STD_CALL_CONV :ptr IAdviseSink, :ptr IMoniker
  ;* [annotation][in] *
  ;* [call_as] *
  IAdviseSink_OnRename_Stub proto WIN_STD_CALL_CONV :ptr IAdviseSink, :ptr IMoniker
  ;* [in] *
  ;* [local] *
  IAdviseSink_OnSave_Proxy proto WIN_STD_CALL_CONV :ptr IAdviseSink
  ;* [call_as] *
  IAdviseSink_OnSave_Stub proto WIN_STD_CALL_CONV :ptr IAdviseSink
  ;* [local] *
  IAdviseSink_OnClose_Proxy proto WIN_STD_CALL_CONV :ptr IAdviseSink
  ;* [call_as] *
  IAdviseSink_OnClose_Stub proto WIN_STD_CALL_CONV :ptr IAdviseSink
  ;* [local] *
  AsyncIAdviseSink_Begin_OnDataChange_Proxy proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink, :ptr FORMATETC, :ptr STGMEDIUM
  ;* [annotation][unique][in] *
  ;* [call_as] *
  AsyncIAdviseSink_Begin_OnDataChange_Stub proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink, :ptr FORMATETC, :ptr ASYNC_STGMEDIUM
  ;* [unique][in] *
  ;* [local] *
  AsyncIAdviseSink_Finish_OnDataChange_Proxy proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink
  ;* [call_as] *
  AsyncIAdviseSink_Finish_OnDataChange_Stub proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink
  ;* [local] *
  AsyncIAdviseSink_Begin_OnViewChange_Proxy proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink, :DWORD, :LONG
  ;* [in] *
  ;* [call_as] *
  AsyncIAdviseSink_Begin_OnViewChange_Stub proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink, :DWORD, :LONG
  ;* [in] *
  ;* [local] *
  AsyncIAdviseSink_Finish_OnViewChange_Proxy proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink
  ;* [call_as] *
  AsyncIAdviseSink_Finish_OnViewChange_Stub proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink
  ;* [local] *
  AsyncIAdviseSink_Begin_OnRename_Proxy proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink, :ptr IMoniker
  ;* [annotation][in] *
  ;* [call_as] *
  AsyncIAdviseSink_Begin_OnRename_Stub proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink, :ptr IMoniker
  ;* [in] *
  ;* [local] *
  AsyncIAdviseSink_Finish_OnRename_Proxy proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink
  ;* [call_as] *
  AsyncIAdviseSink_Finish_OnRename_Stub proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink
  ;* [local] *
  AsyncIAdviseSink_Begin_OnSave_Proxy proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink
  ;* [call_as] *
  AsyncIAdviseSink_Begin_OnSave_Stub proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink
  ;* [local] *
  AsyncIAdviseSink_Finish_OnSave_Proxy proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink
  ;* [call_as] *
  AsyncIAdviseSink_Finish_OnSave_Stub proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink
  ;* [local] *
  AsyncIAdviseSink_Begin_OnClose_Proxy proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink
  ;* [call_as] *
  AsyncIAdviseSink_Begin_OnClose_Stub proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink
  ;* [local] *
  AsyncIAdviseSink_Finish_OnClose_Proxy proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink
  ;* [call_as] *
  AsyncIAdviseSink_Finish_OnClose_Stub proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink
  ;* [local] *
  IAdviseSink2_OnLinkSrcChange_Proxy proto WIN_STD_CALL_CONV :ptr IAdviseSink2, :ptr IMoniker
  ;* [annotation][unique][in] *
  ;* [call_as] *
  IAdviseSink2_OnLinkSrcChange_Stub proto WIN_STD_CALL_CONV :ptr IAdviseSink2, :ptr IMoniker
  ;* [unique][in] *
  ;* [local] *
  AsyncIAdviseSink2_Begin_OnLinkSrcChange_Proxy proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink2, :ptr IMoniker
  ;* [annotation][unique][in] *
  ;* [call_as] *
  AsyncIAdviseSink2_Begin_OnLinkSrcChange_Stub proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink2, :ptr IMoniker
  ;* [unique][in] *
  ;* [local] *
  AsyncIAdviseSink2_Finish_OnLinkSrcChange_Proxy proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink2
  ;* [call_as] *
  AsyncIAdviseSink2_Finish_OnLinkSrcChange_Stub proto WIN_STD_CALL_CONV :ptr AsyncIAdviseSink2
  ;* [local] *
  IDataObject_GetData_Proxy proto WIN_STD_CALL_CONV :ptr IDataObject, :ptr FORMATETC, :ptr STGMEDIUM
  ;* [annotation][out] *
  ;* [call_as] *
  IDataObject_GetData_Stub proto WIN_STD_CALL_CONV :ptr IDataObject, :ptr FORMATETC, :ptr STGMEDIUM
  ;* [out] *
  ;* [local] *
  IDataObject_GetDataHere_Proxy proto WIN_STD_CALL_CONV :ptr IDataObject, :ptr FORMATETC, :ptr STGMEDIUM
  ;* [annotation][out][in] *
  ;* [call_as] *
  IDataObject_GetDataHere_Stub proto WIN_STD_CALL_CONV :ptr IDataObject, :ptr FORMATETC, :ptr STGMEDIUM
  ;* [out][in] *
  ;* [local] *
  IDataObject_SetData_Proxy proto WIN_STD_CALL_CONV :ptr IDataObject, :ptr FORMATETC, :ptr STGMEDIUM, :BOOL
  ;* [in] *
  ;* [call_as] *
  IDataObject_SetData_Stub proto WIN_STD_CALL_CONV :ptr IDataObject, :ptr FORMATETC, :ptr FLAG_STGMEDIUM, :BOOL
  ;* [in] *
  ;* [local] *
  IFillLockBytes_FillAppend_Proxy proto WIN_STD_CALL_CONV :ptr IFillLockBytes, :ptr, :ULONG, :ptr ULONG
  ;* [annotation][out] *
  ;* [call_as] *
  IFillLockBytes_FillAppend_Stub proto WIN_STD_CALL_CONV :ptr IFillLockBytes, :ptr byte, :ULONG, :ptr ULONG
  ;* [out] *
  ;* [local] *
  IFillLockBytes_FillAt_Proxy proto WIN_STD_CALL_CONV :ptr IFillLockBytes, :ULARGE_INTEGER, :ptr, :ULONG, :ptr ULONG
  ;* [annotation][out] *
  ;* [call_as] *
  IFillLockBytes_FillAt_Stub proto WIN_STD_CALL_CONV :ptr IFillLockBytes, :ULARGE_INTEGER, :ptr byte, :ULONG, :ptr ULONG
  ;* [out] *
  ;* end of Additional Prototypes *
  ifdef __cplusplus
    ;[...]
  endif
endif
