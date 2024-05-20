;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\comcat.h
;             Created on (UTC) 06/04/2024 06:15:52
;             Last modified on (UTC) 21/02/2024 18:14:20

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
ifndef __comcat_h__
  __comcat_h__ equ <>
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
  ifndef __IEnumGUID_FWD_DEFINED__
    __IEnumGUID_FWD_DEFINED__ equ <>
    ;* __IEnumGUID_FWD_DEFINED__ *
  endif
  ifndef __IEnumCATEGORYINFO_FWD_DEFINED__
    __IEnumCATEGORYINFO_FWD_DEFINED__ equ <>
    ;* __IEnumCATEGORYINFO_FWD_DEFINED__ *
  endif
  ifndef __ICatRegister_FWD_DEFINED__
    __ICatRegister_FWD_DEFINED__ equ <>
    ;* __ICatRegister_FWD_DEFINED__ *
  endif
  ifndef __ICatInformation_FWD_DEFINED__
    __ICatInformation_FWD_DEFINED__ equ <>
    ;* __ICatInformation_FWD_DEFINED__ *
  endif
  ;* header files for imported files *
  include unknwn.inc
  ifdef __cplusplus
    ;[...]
  endif
  ;* interface __MIDL_itf_comcat_0000_0000 *
  ;* [local] *
  ;=--------------------------------------------------------------------------=
  ; ComCat.h
  ;=--------------------------------------------------------------------------=
  ; Copyright (c) Microsoft Corporation. All rights reserved.
  ; THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
  ; ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
  ; THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
  ; PARTICULAR PURPOSE.
  ;=--------------------------------------------------------------------------=
  ;=--------------------------------------------------------------------------=
  ; OLE Componet Categories Interfaces.
  ;=--------------------------------------------------------------------------=
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    externdef CLSID_StdComponentCategoriesMgr:CLSID
    ;//////////////////////////////////////////////////////////////////////////
    ;  Types
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    CATID typedef GUID
    REFCATID typedef REFGUID
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    IID_IEnumCLSID equ <IID_IEnumGUID>
    IEnumCLSID equ <IEnumGUID>
    LPENUMCLSID equ <LPENUMGUID>
    CATID_NULL equ <GUID_NULL>
    IsEqualCATID macro rcatid1, rcatid2
      exitm <IsEqualGUID(rcatid1, rcatid2)>
    endm
    IID_IEnumCATID equ <IID_IEnumGUID>
    IEnumCATID equ <IEnumGUID>
    ;//////////////////////////////////////////////////////////////////////////
    ;  Category IDs (link to uuid3.lib)
    externdef CATID_Insertable:CATID
    externdef CATID_Control:CATID
    externdef CATID_Programmable:CATID
    externdef CATID_IsShortcut:CATID
    externdef CATID_NeverShowExt:CATID
    externdef CATID_DocObject:CATID
    externdef CATID_Printable:CATID
    externdef CATID_RequiresDataPathHost:CATID
    externdef CATID_PersistsToMoniker:CATID
    externdef CATID_PersistsToStorage:CATID
    externdef CATID_PersistsToStreamInit:CATID
    externdef CATID_PersistsToStream:CATID
    externdef CATID_PersistsToMemory:CATID
    externdef CATID_PersistsToFile:CATID
    externdef CATID_PersistsToPropertyBag:CATID
    externdef CATID_InternetAware:CATID
    externdef CATID_DesignTimeUIActivatableControl:CATID
    ;//////////////////////////////////////////////////////////////////////////
    ;  Interface Definitions
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
    ifndef _LPENUMGUID_DEFINED
      _LPENUMGUID_DEFINED equ <>
      externdef __MIDL_itf_comcat_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_comcat_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IEnumGUID_INTERFACE_DEFINED__
        __IEnumGUID_INTERFACE_DEFINED__ equ <>
        ;* interface IEnumGUID *
        ;* [unique][uuid][object] *
        ;* [unique] *
        LPENUMGUID typedef ptr IEnumGUID
        externdef IID_IEnumGUID:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IEnumGUIDVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEnumGUIDVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IEnumGUID, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IEnumGUID
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IEnumGUID
            DECLSPEC_XFGVIRT(IEnumGUID, Next)
            ;* [local] *
            ;* [in] *
            ;* [annotation][length_is][size_is][out] *
            ;* [annotation][out] *
            STD_METHOD Next, :ptr IEnumGUID, :ULONG, :ptr GUID, :ptr ULONG
            DECLSPEC_XFGVIRT(IEnumGUID, Skip)
            STD_METHOD Skip, :ptr IEnumGUID, :ULONG
            ;* [in] *
            DECLSPEC_XFGVIRT(IEnumGUID, Reset)
            STD_METHOD Reset, :ptr IEnumGUID
            DECLSPEC_XFGVIRT(IEnumGUID, Clone)
            STD_METHOD Clone, :ptr IEnumGUID, :ptr ptr IEnumGUID
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IEnumGUIDVtbl ends
          IEnumGUID struct
            lpVtbl POINTER ?
          IEnumGUID ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* [call_as] *
        IEnumGUID_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumGUID, :ULONG, :ptr GUID, :ptr ULONG
        ;* [out] *
        IEnumGUID_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        ;* __IEnumGUID_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_comcat_0000_0001 *
      ;* [local] *
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef _LPENUMCATEGORYINFO_DEFINED
      _LPENUMCATEGORYINFO_DEFINED equ <>
      externdef __MIDL_itf_comcat_0000_0001_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_comcat_0000_0001_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IEnumCATEGORYINFO_INTERFACE_DEFINED__
        __IEnumCATEGORYINFO_INTERFACE_DEFINED__ equ <>
        ;* interface IEnumCATEGORYINFO *
        ;* [unique][uuid][object] *
        ;* [unique] *
        LPENUMCATEGORYINFO typedef ptr IEnumCATEGORYINFO
        CATEGORYINFO struct
          catid CATID <>
          lcid LCID ?
          szDescription OLECHAR 128 dup (?)
        CATEGORYINFO ends
        tagCATEGORYINFO typedef CATEGORYINFO
        LPCATEGORYINFO typedef ptr tagCATEGORYINFO
        externdef IID_IEnumCATEGORYINFO:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IEnumCATEGORYINFOVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEnumCATEGORYINFOVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IEnumCATEGORYINFO, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IEnumCATEGORYINFO
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IEnumCATEGORYINFO
            DECLSPEC_XFGVIRT(IEnumCATEGORYINFO, Next)
            ;* [in] *
            ;* [length_is][size_is][out] *
            STD_METHOD Next, :ptr IEnumCATEGORYINFO, :ULONG, :ptr CATEGORYINFO, :ptr ULONG
            ;* [out] *
            DECLSPEC_XFGVIRT(IEnumCATEGORYINFO, Skip)
            STD_METHOD Skip, :ptr IEnumCATEGORYINFO, :ULONG
            ;* [in] *
            DECLSPEC_XFGVIRT(IEnumCATEGORYINFO, Reset)
            STD_METHOD Reset, :ptr IEnumCATEGORYINFO
            DECLSPEC_XFGVIRT(IEnumCATEGORYINFO, Clone)
            STD_METHOD Clone, :ptr IEnumCATEGORYINFO, :ptr ptr IEnumCATEGORYINFO
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IEnumCATEGORYINFOVtbl ends
          IEnumCATEGORYINFO struct
            lpVtbl POINTER ?
          IEnumCATEGORYINFO ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IEnumCATEGORYINFO_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_comcat_0000_0002 *
      ;* [local] *
    endif
    ifndef _LPCATREGISTER_DEFINED
      _LPCATREGISTER_DEFINED equ <>
      externdef __MIDL_itf_comcat_0000_0002_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_comcat_0000_0002_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ICatRegister_INTERFACE_DEFINED__
        __ICatRegister_INTERFACE_DEFINED__ equ <>
        ;* interface ICatRegister *
        ;* [unique][uuid][object] *
        ;* [unique] *
        LPCATREGISTER typedef ptr ICatRegister
        externdef IID_ICatRegister:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ICatRegisterVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ICatRegisterVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ICatRegister, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ICatRegister
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ICatRegister
            DECLSPEC_XFGVIRT(ICatRegister, RegisterCategories)
            ;* [in] *
            STD_METHOD RegisterCategories, :ptr ICatRegister, :ULONG, :ptr CATEGORYINFO
            ;* [size_is][in] *
            DECLSPEC_XFGVIRT(ICatRegister, UnRegisterCategories)
            ;* [in] *
            STD_METHOD UnRegisterCategories, :ptr ICatRegister, :ULONG, :ptr CATID
            ;* [size_is][in] *
            DECLSPEC_XFGVIRT(ICatRegister, RegisterClassImplCategories)
            ;* [in] *
            ;* [in] *
            STD_METHOD RegisterClassImplCategories, :ptr ICatRegister, :REFCLSID, :ULONG, :ptr CATID
            ;* [size_is][in] *
            DECLSPEC_XFGVIRT(ICatRegister, UnRegisterClassImplCategories)
            ;* [in] *
            ;* [in] *
            STD_METHOD UnRegisterClassImplCategories, :ptr ICatRegister, :REFCLSID, :ULONG, :ptr CATID
            ;* [size_is][in] *
            DECLSPEC_XFGVIRT(ICatRegister, RegisterClassReqCategories)
            ;* [in] *
            ;* [in] *
            STD_METHOD RegisterClassReqCategories, :ptr ICatRegister, :REFCLSID, :ULONG, :ptr CATID
            ;* [size_is][in] *
            DECLSPEC_XFGVIRT(ICatRegister, UnRegisterClassReqCategories)
            ;* [in] *
            ;* [in] *
            STD_METHOD UnRegisterClassReqCategories, :ptr ICatRegister, :REFCLSID, :ULONG, :ptr CATID
            ;* [size_is][in] *
            ??Interface equ <>
            END_INTERFACE
          ICatRegisterVtbl ends
          ICatRegister struct
            lpVtbl POINTER ?
          ICatRegister ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ICatRegister_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_comcat_0000_0003 *
      ;* [local] *
    endif
    ifndef _LPCATINFORMATION_DEFINED
      _LPCATINFORMATION_DEFINED equ <>
      externdef __MIDL_itf_comcat_0000_0003_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_comcat_0000_0003_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ICatInformation_INTERFACE_DEFINED__
        __ICatInformation_INTERFACE_DEFINED__ equ <>
        ;* interface ICatInformation *
        ;* [unique][uuid][object] *
        ;* [unique] *
        LPCATINFORMATION typedef ptr ICatInformation
        externdef IID_ICatInformation:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ICatInformationVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ICatInformationVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ICatInformation, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ICatInformation
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ICatInformation
            DECLSPEC_XFGVIRT(ICatInformation, EnumCategories)
            ;* [in] *
            STD_METHOD EnumCategories, :ptr ICatInformation, :LCID, :ptr ptr IEnumCATEGORYINFO
            ;* [out] *
            DECLSPEC_XFGVIRT(ICatInformation, GetCategoryDesc)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetCategoryDesc, :ptr ICatInformation, :REFCATID, :LCID, :ptr LPWSTR
            ;* [out] *
            DECLSPEC_XFGVIRT(ICatInformation, EnumClassesOfCategories)
            ;* [local] *
            ;* [in] *
            ;* [size_is][in] *
            ;* [in] *
            ;* [size_is][in] *
            STD_METHOD EnumClassesOfCategories, :ptr ICatInformation, :ULONG, :ptr CATID, :ULONG, :ptr CATID, :ptr ptr IEnumGUID
            ;* [out] *
            DECLSPEC_XFGVIRT(ICatInformation, IsClassOfCategories)
            ;* [local] *
            ;* [in] *
            ;* [in] *
            ;* [size_is][in] *
            ;* [in] *
            STD_METHOD IsClassOfCategories, :ptr ICatInformation, :REFCLSID, :ULONG, :ptr CATID, :ULONG, :ptr CATID
            ;* [size_is][in] *
            DECLSPEC_XFGVIRT(ICatInformation, EnumImplCategoriesOfClass)
            ;* [in] *
            STD_METHOD EnumImplCategoriesOfClass, :ptr ICatInformation, :REFCLSID, :ptr ptr IEnumGUID
            ;* [out] *
            DECLSPEC_XFGVIRT(ICatInformation, EnumReqCategoriesOfClass)
            ;* [in] *
            STD_METHOD EnumReqCategoriesOfClass, :ptr ICatInformation, :REFCLSID, :ptr ptr IEnumGUID
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          ICatInformationVtbl ends
          ICatInformation struct
            lpVtbl POINTER ?
          ICatInformation ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* [call_as] *
        ICatInformation_RemoteEnumClassesOfCategories_Proxy proto WIN_STD_CALL_CONV :ptr ICatInformation, :ULONG, :ptr CATID, :ULONG, :ptr CATID, :ptr ptr IEnumGUID
        ;* [out] *
        ICatInformation_RemoteEnumClassesOfCategories_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        ;* [call_as] *
        ICatInformation_RemoteIsClassOfCategories_Proxy proto WIN_STD_CALL_CONV :ptr ICatInformation, :REFCLSID, :ULONG, :ptr CATID, :ULONG, :ptr CATID
        ;* [size_is][unique][in] *
        ICatInformation_RemoteIsClassOfCategories_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        ;* __ICatInformation_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_comcat_0000_0004 *
      ;* [local] *
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  externdef __MIDL_itf_comcat_0000_0004_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_comcat_0000_0004_v0_0_s_ifspec:RPC_IF_HANDLE
  ;* Additional Prototypes for ALL interfaces *
  ;* [local] *
  IEnumGUID_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumGUID, :ULONG, :ptr GUID, :ptr ULONG
  ;* [annotation][out] *
  ;* [call_as] *
  IEnumGUID_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumGUID, :ULONG, :ptr GUID, :ptr ULONG
  ;* [out] *
  ;* [local] *
  ICatInformation_EnumClassesOfCategories_Proxy proto WIN_STD_CALL_CONV :ptr ICatInformation, :ULONG, :ptr CATID, :ULONG, :ptr CATID, :ptr ptr IEnumGUID
  ;* [out] *
  ;* [call_as] *
  ICatInformation_EnumClassesOfCategories_Stub proto WIN_STD_CALL_CONV :ptr ICatInformation, :ULONG, :ptr CATID, :ULONG, :ptr CATID, :ptr ptr IEnumGUID
  ;* [out] *
  ;* [local] *
  ICatInformation_IsClassOfCategories_Proxy proto WIN_STD_CALL_CONV :ptr ICatInformation, :REFCLSID, :ULONG, :ptr CATID, :ULONG, :ptr CATID
  ;* [size_is][in] *
  ;* [call_as] *
  ICatInformation_IsClassOfCategories_Stub proto WIN_STD_CALL_CONV :ptr ICatInformation, :REFCLSID, :ULONG, :ptr CATID, :ULONG, :ptr CATID
  ;* [size_is][unique][in] *
  ;* end of Additional Prototypes *
  ifdef __cplusplus
    ;[...]
  endif
endif
