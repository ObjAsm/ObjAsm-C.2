;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\servprov.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 21/02/2024 18:16:56

;* verify that the <rpcndr.h> version is high enough to compile this file*
ifndef __REQUIRED_RPCNDR_H_VERSION__
  __REQUIRED_RPCNDR_H_VERSION__ equ 500
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
ifndef __servprov_h__
  __servprov_h__ equ <>
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
  ifndef __IServiceProvider_FWD_DEFINED__
    __IServiceProvider_FWD_DEFINED__ equ <>
    ;* __IServiceProvider_FWD_DEFINED__ *
  endif
  ;* header files for imported files *
  include objidl.inc
  ifdef __cplusplus
    ;[...]
  endif
  ;* interface __MIDL_itf_servprov_0000_0000 *
  ;* [local] *
  ;=--------------------------------------------------------------------------=
  ; ServProv.h
  ;=--------------------------------------------------------------------------=
  ; (C) Copyright Microsoft Corporation.  All Rights Reserved.
  ; THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
  ; ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
  ; THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
  ; PARTICULAR PURPOSE.
  ;=--------------------------------------------------------------------------=
  ;---------------------------------------------------------------------------=
  ; IServiceProvider Interfaces.
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    externdef __MIDL_itf_servprov_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_servprov_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IServiceProvider_INTERFACE_DEFINED__
      __IServiceProvider_INTERFACE_DEFINED__ equ <>
      ;* interface IServiceProvider *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPSERVICEPROVIDER typedef ptr IServiceProvider
      if (_MSC_VER ge 1100) and Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
      ; VC6 Hack
        externdef IID_IServiceProvider:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IServiceProviderVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IServiceProviderVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IServiceProvider, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IServiceProvider
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IServiceProvider
            DECLSPEC_XFGVIRT(IServiceProvider, QueryService)
            ;* [local] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out] *
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
          ;* C style interface *
        endif
        ;* [call_as] *
        IServiceProvider_RemoteQueryService_Proxy proto WIN_STD_CALL_CONV :ptr IServiceProvider, :REFGUID, :REFIID, :ptr ptr IUnknown
        ;* [iid_is][out] *
        IServiceProvider_RemoteQueryService_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        ;* __IServiceProvider_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_servprov_0000_0001 *
      ;* [local] *
    endif
    ; VC6 Hack
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  externdef __MIDL_itf_servprov_0000_0001_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_servprov_0000_0001_v0_0_s_ifspec:RPC_IF_HANDLE
  ;* Additional Prototypes for ALL interfaces *
  ;* [local] *
  IServiceProvider_QueryService_Proxy proto WIN_STD_CALL_CONV :ptr IServiceProvider, :REFGUID, :REFIID, :ptr ptr
  ;* [annotation][out] *
  ;* [call_as] *
  IServiceProvider_QueryService_Stub proto WIN_STD_CALL_CONV :ptr IServiceProvider, :REFGUID, :REFIID, :ptr ptr IUnknown
  ;* [iid_is][out] *
  ;* end of Additional Prototypes *
  ifdef __cplusplus
    ;[...]
  endif
endif
