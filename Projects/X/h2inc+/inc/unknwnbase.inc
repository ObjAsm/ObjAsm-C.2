;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\unknwnbase.h
;             Created on (UTC) 06/04/2024 06:16:02
;             Last modified on (UTC) 21/02/2024 18:18:12

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
ifndef __unknwnbase_h__
  __unknwnbase_h__ equ <>
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
  ifndef __IUnknown_FWD_DEFINED__
    __IUnknown_FWD_DEFINED__ equ <>
    ;* __IUnknown_FWD_DEFINED__ *
  endif
  ifndef __AsyncIUnknown_FWD_DEFINED__
    __AsyncIUnknown_FWD_DEFINED__ equ <>
    ;* __AsyncIUnknown_FWD_DEFINED__ *
  endif
  ifndef __IClassFactory_FWD_DEFINED__
    __IClassFactory_FWD_DEFINED__ equ <>
    ;* __IClassFactory_FWD_DEFINED__ *
  endif
  ;* header files for imported files *
  include wtypesbase.inc
  ifdef __cplusplus
    ;[...]
  endif
  ;* interface __MIDL_itf_unknwnbase_0000_0000 *
  ;* [local] *
  include winapifamily.inc
  ;+-------------------------------------------------------------------------
  ;  Microsoft Windows
  ;  Copyright (c) Microsoft Corporation. All rights reserved.
  ;--------------------------------------------------------------------------
  if (_MSC_VER ge 1020)
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    externdef __MIDL_itf_unknwnbase_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_unknwnbase_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IUnknown_INTERFACE_DEFINED__
      __IUnknown_INTERFACE_DEFINED__ equ <>
      ;* interface IUnknown *
      ;* [unique][uuid][object][local] *
      ;* [unique] *
      LPUNKNOWN typedef ptr IUnknown
      ;////////////////////////////////////////////////////////////////
      ; IID_IUnknown and all other system IIDs are provided in UUID.LIB
      ; Link that library in with your proxies, clients and servers
      ;////////////////////////////////////////////////////////////////
      if (_MSC_VER ge 1100) and Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        externdef IID_IUnknown:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IUnknownVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IUnknownVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IUnknown, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IUnknown
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IUnknown
            ??Interface equ <>
            END_INTERFACE
          IUnknownVtbl ends
          IUnknown struct
            lpVtbl POINTER ?
          IUnknown ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        IUnknown_QueryInterface_Proxy proto WIN_STD_CALL_CONV :ptr IUnknown, :REFIID, :ptr ptr
        ;* [annotation][iid_is][out] *
        IUnknown_QueryInterface_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        IUnknown_AddRef_Proxy proto WIN_STD_CALL_CONV :ptr IUnknown
        IUnknown_AddRef_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        IUnknown_Release_Proxy proto WIN_STD_CALL_CONV :ptr IUnknown
        IUnknown_Release_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        ;* __IUnknown_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_unknwnbase_0000_0001 *
      ;* [local] *
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    externdef __MIDL_itf_unknwnbase_0000_0001_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_unknwnbase_0000_0001_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __AsyncIUnknown_INTERFACE_DEFINED__
      __AsyncIUnknown_INTERFACE_DEFINED__ equ <>
      ;* interface AsyncIUnknown *
      ;* [unique][uuid][object][local] *
      externdef IID_AsyncIUnknown:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        AsyncIUnknownVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <AsyncIUnknownVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr AsyncIUnknown, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr AsyncIUnknown
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr AsyncIUnknown
          DECLSPEC_XFGVIRT(AsyncIUnknown, Begin_QueryInterface)
          STD_METHOD Begin_QueryInterface, :ptr AsyncIUnknown, :REFIID
          ;* [in] *
          DECLSPEC_XFGVIRT(AsyncIUnknown, Finish_QueryInterface)
          ;* [annotation][out] *
          STD_METHOD Finish_QueryInterface, :ptr AsyncIUnknown, :ptr ptr
          DECLSPEC_XFGVIRT(AsyncIUnknown, Begin_AddRef)
          STD_METHOD Begin_AddRef, :ptr AsyncIUnknown
          DECLSPEC_XFGVIRT(AsyncIUnknown, Finish_AddRef)
          STD_METHOD Finish_AddRef, :ptr AsyncIUnknown
          DECLSPEC_XFGVIRT(AsyncIUnknown, Begin_Release)
          STD_METHOD Begin_Release, :ptr AsyncIUnknown
          DECLSPEC_XFGVIRT(AsyncIUnknown, Finish_Release)
          STD_METHOD Finish_Release, :ptr AsyncIUnknown
          ??Interface equ <>
          END_INTERFACE
        AsyncIUnknownVtbl ends
        AsyncIUnknown struct
          lpVtbl POINTER ?
        AsyncIUnknown ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __AsyncIUnknown_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_unknwnbase_0000_0002 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    externdef __MIDL_itf_unknwnbase_0000_0002_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_unknwnbase_0000_0002_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IClassFactory_INTERFACE_DEFINED__
      __IClassFactory_INTERFACE_DEFINED__ equ <>
      ;* interface IClassFactory *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPCLASSFACTORY typedef ptr IClassFactory
      externdef IID_IClassFactory:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IClassFactoryVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IClassFactoryVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IClassFactory, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IClassFactory
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IClassFactory
          DECLSPEC_XFGVIRT(IClassFactory, CreateInstance)
          ;* [local] *
          ;* [annotation][unique][in] *
          ;* [annotation][in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD CreateInstance, :ptr IClassFactory, :ptr IUnknown, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IClassFactory, LockServer)
          ;* [local] *
          STD_METHOD LockServer, :ptr IClassFactory, :BOOL
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IClassFactoryVtbl ends
        IClassFactory struct
          lpVtbl POINTER ?
        IClassFactory ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      IClassFactory_RemoteCreateInstance_Proxy proto WIN_STD_CALL_CONV :ptr IClassFactory, :REFIID, :ptr ptr IUnknown
      ;* [iid_is][out] *
      IClassFactory_RemoteCreateInstance_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      IClassFactory_RemoteLockServer_Proxy proto WIN_STD_CALL_CONV :ptr IClassFactory, :BOOL
      ;* [in] *
      IClassFactory_RemoteLockServer_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __IClassFactory_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_unknwnbase_0000_0003 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  externdef __MIDL_itf_unknwnbase_0000_0003_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_unknwnbase_0000_0003_v0_0_s_ifspec:RPC_IF_HANDLE
  ;* Additional Prototypes for ALL interfaces *
  ;* [local] *
  IClassFactory_CreateInstance_Proxy proto WIN_STD_CALL_CONV :ptr IClassFactory, :ptr IUnknown, :REFIID, :ptr ptr
  ;* [annotation][iid_is][out] *
  ;* [call_as] *
  IClassFactory_CreateInstance_Stub proto WIN_STD_CALL_CONV :ptr IClassFactory, :REFIID, :ptr ptr IUnknown
  ;* [iid_is][out] *
  ;* [local] *
  IClassFactory_LockServer_Proxy proto WIN_STD_CALL_CONV :ptr IClassFactory, :BOOL
  ;* [in] *
  ;* [call_as] *
  IClassFactory_LockServer_Stub proto WIN_STD_CALL_CONV :ptr IClassFactory, :BOOL
  ;* [in] *
  ;* end of Additional Prototypes *
  ifdef __cplusplus
    ;[...]
  endif
endif
