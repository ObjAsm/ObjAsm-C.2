;Include file created by h2incX, Version B.01.02, 23/09/2018 15:31
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\unknwn.h', last modified: 19/04/2018 10:46
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
ifndef __unknwn_h__
  __unknwn_h__ equ <>
  if Defined(_MSC_VER) and (_MSC_VER ge 1020)
  endif
  ifndef __IUnknown_FWD_DEFINED__
    __IUnknown_FWD_DEFINED__ equ <>
    ;IUnknown typedef IUnknown
  endif
  ifndef __AsyncIUnknown_FWD_DEFINED__
    __AsyncIUnknown_FWD_DEFINED__ equ <>
    ;AsyncIUnknown typedef AsyncIUnknown
  endif
  ifndef __IClassFactory_FWD_DEFINED__
    __IClassFactory_FWD_DEFINED__ equ <>
    ;IClassFactory typedef IClassFactory
  endif
  include wtypes.inc
  ifdef __cplusplus
    ;[...]
  endif
  if (_MSC_VER ge 1020)
  endif
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_unknwn_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_unknwn_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IUnknown_INTERFACE_DEFINED__
      __IUnknown_INTERFACE_DEFINED__ equ <>
      LPUNKNOWN typedef ptr IUnknown
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
            STD_METHOD QueryInterface, :ptr IUnknown, :REFIID, :ptr ptr
            STD_METHOD AddRef, :ptr IUnknown
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
        endif
        ;Warning: duplicate proto = IUnknown_QueryInterface_Proxy proto WIN_STD_CALL_CONV :ptr IUnknown, :REFIID, :ptr ptr
        ;Warning: duplicate proto = IUnknown_QueryInterface_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        ;Warning: duplicate proto = IUnknown_AddRef_Proxy proto WIN_STD_CALL_CONV :ptr IUnknown
        ;Warning: duplicate proto = IUnknown_AddRef_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        ;Warning: duplicate proto = IUnknown_Release_Proxy proto WIN_STD_CALL_CONV :ptr IUnknown
        ;Warning: duplicate proto = IUnknown_Release_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_unknwn_0000_0001_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_unknwn_0000_0001_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __AsyncIUnknown_INTERFACE_DEFINED__
      __AsyncIUnknown_INTERFACE_DEFINED__ equ <>
      externdef IID_AsyncIUnknown:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        TYPE_AsyncIUnknownVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr AsyncIUnknown, :REFIID, :ptr ptr
        AsyncIUnknownVtbl_QueryInterface typedef ptr TYPE_AsyncIUnknownVtbl_QueryInterface
        TYPE_AsyncIUnknownVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr AsyncIUnknown
        AsyncIUnknownVtbl_AddRef typedef ptr TYPE_AsyncIUnknownVtbl_AddRef
        TYPE_AsyncIUnknownVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr AsyncIUnknown
        AsyncIUnknownVtbl_Release typedef ptr TYPE_AsyncIUnknownVtbl_Release
        TYPE_AsyncIUnknownVtbl_Begin_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr AsyncIUnknown, :REFIID
        AsyncIUnknownVtbl_Begin_QueryInterface typedef ptr TYPE_AsyncIUnknownVtbl_Begin_QueryInterface
        TYPE_AsyncIUnknownVtbl_Finish_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr AsyncIUnknown, :ptr ptr
        AsyncIUnknownVtbl_Finish_QueryInterface typedef ptr TYPE_AsyncIUnknownVtbl_Finish_QueryInterface
        TYPE_AsyncIUnknownVtbl_Begin_AddRef typedef proto WIN_STD_CALL_CONV :ptr AsyncIUnknown
        AsyncIUnknownVtbl_Begin_AddRef typedef ptr TYPE_AsyncIUnknownVtbl_Begin_AddRef
        TYPE_AsyncIUnknownVtbl_Finish_AddRef typedef proto WIN_STD_CALL_CONV :ptr AsyncIUnknown
        AsyncIUnknownVtbl_Finish_AddRef typedef ptr TYPE_AsyncIUnknownVtbl_Finish_AddRef
        TYPE_AsyncIUnknownVtbl_Begin_Release typedef proto WIN_STD_CALL_CONV :ptr AsyncIUnknown
        AsyncIUnknownVtbl_Begin_Release typedef ptr TYPE_AsyncIUnknownVtbl_Begin_Release
        TYPE_AsyncIUnknownVtbl_Finish_Release typedef proto WIN_STD_CALL_CONV :ptr AsyncIUnknown
        AsyncIUnknownVtbl_Finish_Release typedef ptr TYPE_AsyncIUnknownVtbl_Finish_Release
        AsyncIUnknownVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <AsyncIUnknownVtbl>
          QueryInterface PAsyncIUnknownVtbl_QueryInterface ?
          AddRef PAsyncIUnknownVtbl_AddRef ?
          Release PAsyncIUnknownVtbl_Release ?
          Begin_QueryInterface PAsyncIUnknownVtbl_Begin_QueryInterface ?
          Finish_QueryInterface PAsyncIUnknownVtbl_Finish_QueryInterface ?
          Begin_AddRef PAsyncIUnknownVtbl_Begin_AddRef ?
          Finish_AddRef PAsyncIUnknownVtbl_Finish_AddRef ?
          Begin_Release PAsyncIUnknownVtbl_Begin_Release ?
          Finish_Release PAsyncIUnknownVtbl_Finish_Release ?
          ??Interface equ <>
          END_INTERFACE
        AsyncIUnknownVtbl ends
        AsyncIUnknown struct
          lpVtbl POINTER ?
        AsyncIUnknown ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_unknwn_0000_0002_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_unknwn_0000_0002_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IClassFactory_INTERFACE_DEFINED__
      __IClassFactory_INTERFACE_DEFINED__ equ <>
      LPCLASSFACTORY typedef ptr IClassFactory
      externdef IID_IClassFactory:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        TYPE_IClassFactoryVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IClassFactory, :REFIID, :ptr ptr
        IClassFactoryVtbl_QueryInterface typedef ptr TYPE_IClassFactoryVtbl_QueryInterface
        TYPE_IClassFactoryVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IClassFactory
        IClassFactoryVtbl_AddRef typedef ptr TYPE_IClassFactoryVtbl_AddRef
        TYPE_IClassFactoryVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IClassFactory
        IClassFactoryVtbl_Release typedef ptr TYPE_IClassFactoryVtbl_Release
        TYPE_IClassFactoryVtbl_CreateInstance typedef proto WIN_STD_CALL_CONV :ptr IClassFactory, :ptr IUnknown, :REFIID, :ptr ptr
        IClassFactoryVtbl_CreateInstance typedef ptr TYPE_IClassFactoryVtbl_CreateInstance
        TYPE_IClassFactoryVtbl_LockServer typedef proto WIN_STD_CALL_CONV :ptr IClassFactory, :BOOL
        IClassFactoryVtbl_LockServer typedef ptr TYPE_IClassFactoryVtbl_LockServer
        IClassFactoryVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IClassFactoryVtbl>
          QueryInterface PIClassFactoryVtbl_QueryInterface ?
          AddRef PIClassFactoryVtbl_AddRef ?
          Release PIClassFactoryVtbl_Release ?
          CreateInstance PIClassFactoryVtbl_CreateInstance ?
          LockServer PIClassFactoryVtbl_LockServer ?
          ??Interface equ <>
          END_INTERFACE
        IClassFactoryVtbl ends
        IClassFactory struct
          lpVtbl POINTER ?
        IClassFactory ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
      ;Warning: duplicate proto = IClassFactory_RemoteCreateInstance_Proxy proto WIN_STD_CALL_CONV :ptr IClassFactory, :REFIID, :ptr ptr IUnknown
      ;Warning: duplicate proto = IClassFactory_RemoteCreateInstance_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;Warning: duplicate proto = IClassFactory_RemoteLockServer_Proxy proto WIN_STD_CALL_CONV :ptr IClassFactory, :BOOL
      ;Warning: duplicate proto = IClassFactory_RemoteLockServer_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
    endif
  endif
  externdef __MIDL_itf_unknwn_0000_0003_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_unknwn_0000_0003_v0_0_s_ifspec:RPC_IF_HANDLE
  ;Warning: duplicate proto = IClassFactory_CreateInstance_Proxy proto WIN_STD_CALL_CONV :ptr IClassFactory, :ptr IUnknown, :REFIID, :ptr ptr
  ;Warning: duplicate proto = IClassFactory_CreateInstance_Stub proto WIN_STD_CALL_CONV :ptr IClassFactory, :REFIID, :ptr ptr IUnknown
  ;Warning: duplicate proto = IClassFactory_LockServer_Proxy proto WIN_STD_CALL_CONV :ptr IClassFactory, :BOOL
  ;Warning: duplicate proto = IClassFactory_LockServer_Stub proto WIN_STD_CALL_CONV :ptr IClassFactory, :BOOL
  ifdef __cplusplus
    ;[...]
  endif
endif

