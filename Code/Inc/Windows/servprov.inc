;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\servprov.h', last modified: 19/04/2018 10:45
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
ifndef __servprov_h__
  __servprov_h__ equ <>
  if Defined(_MSC_VER) and (_MSC_VER ge 1020)
  endif
  ifndef __IServiceProvider_FWD_DEFINED__
    __IServiceProvider_FWD_DEFINED__ equ <>
    ;IServiceProvider typedef IServiceProvider
    
  endif
  include objidl.inc
  ifdef __cplusplus
    ;[...]
  endif
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    externdef __MIDL_itf_servprov_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_servprov_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IServiceProvider_INTERFACE_DEFINED__
      __IServiceProvider_INTERFACE_DEFINED__ equ <>
      LPSERVICEPROVIDER typedef ptr IServiceProvider
      if (_MSC_VER ge 1100) and Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        externdef IID_IServiceProvider:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IServiceProviderVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IServiceProviderVtbl>
            STD_METHOD QueryInterface, :ptr IServiceProvider, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IServiceProvider
            STD_METHOD Release, :ptr IServiceProvider
            STD_METHOD QueryService, :ptr IServiceProvider, :REFGUID, :REFIID, :ptr ptr
            ??Interface equ <>
            END_INTERFACE
          IServiceProviderVtbl ends

          IServiceProvider struct
            lpVtbl POINTER ?
          IServiceProvider ends

          ifdef COBJMACROS
            ;[...]
          endif
        endif
        IServiceProvider_RemoteQueryService_Proxy proto WIN_STD_CALL_CONV :ptr IServiceProvider, :REFGUID, :REFIID, :ptr ptr IUnknown
        IServiceProvider_RemoteQueryService_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      endif
    endif
  endif
  externdef __MIDL_itf_servprov_0000_0001_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_servprov_0000_0001_v0_0_s_ifspec:RPC_IF_HANDLE
  IServiceProvider_QueryService_Proxy proto WIN_STD_CALL_CONV :ptr IServiceProvider, :REFGUID, :REFIID, :ptr ptr
  IServiceProvider_QueryService_Stub proto WIN_STD_CALL_CONV :ptr IServiceProvider, :REFGUID, :REFIID, :ptr ptr IUnknown
  ifdef __cplusplus
    ;[...]
  endif
endif

