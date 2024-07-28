;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\ObjectArray.h', last modified: 19/04/2018 10:46
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
ifndef __objectarray_h__
  __objectarray_h__ equ <>
  if Defined(_MSC_VER) and (_MSC_VER ge 1020)
  endif
  ifndef __IObjectArray_FWD_DEFINED__
    __IObjectArray_FWD_DEFINED__ equ <>
    ;IObjectArray typedef IObjectArray
    
  endif
  ifndef __IObjectCollection_FWD_DEFINED__
    __IObjectCollection_FWD_DEFINED__ equ <>
    ;IObjectCollection typedef IObjectCollection
    
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
          STD_METHOD QueryInterface, :ptr IObjectArray, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IObjectArray
          STD_METHOD Release, :ptr IObjectArray
          STD_METHOD GetCount, :ptr IObjectArray, :ptr UINT
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
          STD_METHOD QueryInterface, :ptr IObjectCollection, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IObjectCollection
          STD_METHOD Release, :ptr IObjectCollection
          STD_METHOD GetCount, :ptr IObjectCollection, :ptr UINT
          STD_METHOD GetAt, :ptr IObjectCollection, :UINT, :REFIID, :ptr ptr
          STD_METHOD AddObject, :ptr IObjectCollection, :ptr IUnknown
          STD_METHOD AddFromArray, :ptr IObjectCollection, :ptr IObjectArray
          STD_METHOD RemoveObjectAt, :ptr IObjectCollection, :UINT
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

