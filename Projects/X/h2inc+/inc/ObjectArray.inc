;Include file created by h2inc+ version C.2.0 on (UTC) 19/05/2024 07:52:23
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\objectarray.h\objectarray.h
;             Created on (UTC) 06/04/2024 06:15:57
;             Last modified on (UTC) 21/02/2024 18:17:36

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
ifndef __objectarray_h__
  __objectarray_h__ equ <>
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
  ifndef __IObjectArray_FWD_DEFINED__
    __IObjectArray_FWD_DEFINED__ equ <>
  endif
  ifndef __IObjectCollection_FWD_DEFINED__
    __IObjectCollection_FWD_DEFINED__ equ <>
  endif
  include oaidl.inc
  include ocidl.inc
  ifdef __cplusplus
    ;[...]
  endif
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    externdef __MIDL_itf_objectarray_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_objectarray_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IObjectArray_INTERFACE_DEFINED__
      __IObjectArray_INTERFACE_DEFINED__ equ <>
      externdef IID_IObjectArray:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IObjectArrayVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IObjectArrayVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IObjectArray, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IObjectArray
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IObjectArray
          DECLSPEC_XFGVIRT(IObjectArray, GetCount)
          STD_METHOD GetCount, :ptr IObjectArray, :ptr UINT
          DECLSPEC_XFGVIRT(IObjectArray, GetAt)
          STD_METHOD GetAt, :ptr IObjectArray, :UINT, :REFIID, :ptr ptr
          ??Interface equ <>
          END_INTERFACE
        IObjectArrayVtbl ends
        IObjectArray struct
          lpVtbl POINTER ?
        IObjectArray ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IObjectCollection_INTERFACE_DEFINED__
      __IObjectCollection_INTERFACE_DEFINED__ equ <>
      externdef IID_IObjectCollection:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IObjectCollectionVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IObjectCollectionVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IObjectCollection, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IObjectCollection
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IObjectCollection
          DECLSPEC_XFGVIRT(IObjectArray, GetCount)
          STD_METHOD GetCount, :ptr IObjectCollection, :ptr UINT
          DECLSPEC_XFGVIRT(IObjectArray, GetAt)
          STD_METHOD GetAt, :ptr IObjectCollection, :UINT, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IObjectCollection, AddObject)
          STD_METHOD AddObject, :ptr IObjectCollection, :ptr IUnknown
          DECLSPEC_XFGVIRT(IObjectCollection, AddFromArray)
          STD_METHOD AddFromArray, :ptr IObjectCollection, :ptr IObjectArray
          DECLSPEC_XFGVIRT(IObjectCollection, RemoveObjectAt)
          STD_METHOD RemoveObjectAt, :ptr IObjectCollection, :UINT
          DECLSPEC_XFGVIRT(IObjectCollection, Clear)
          STD_METHOD Clear, :ptr IObjectCollection
          ??Interface equ <>
          END_INTERFACE
        IObjectCollectionVtbl ends
        IObjectCollection struct
          lpVtbl POINTER ?
        IObjectCollection ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
  endif
  externdef __MIDL_itf_objectarray_0000_0002_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_objectarray_0000_0002_v0_0_s_ifspec:RPC_IF_HANDLE
  ifdef __cplusplus
    ;[...]
  endif
endif
