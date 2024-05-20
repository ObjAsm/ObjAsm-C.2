;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\oleidl.h
;             Created on (UTC) 06/04/2024 06:15:57
;             Last modified on (UTC) 21/02/2024 18:18:10

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
ifndef __oleidl_h__
  __oleidl_h__ equ <>
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
  ifndef __IOleAdviseHolder_FWD_DEFINED__
    __IOleAdviseHolder_FWD_DEFINED__ equ <>
    ;* __IOleAdviseHolder_FWD_DEFINED__ *
  endif
  ifndef __IOleCache_FWD_DEFINED__
    __IOleCache_FWD_DEFINED__ equ <>
    ;* __IOleCache_FWD_DEFINED__ *
  endif
  ifndef __IOleCache2_FWD_DEFINED__
    __IOleCache2_FWD_DEFINED__ equ <>
    ;* __IOleCache2_FWD_DEFINED__ *
  endif
  ifndef __IOleCacheControl_FWD_DEFINED__
    __IOleCacheControl_FWD_DEFINED__ equ <>
    ;* __IOleCacheControl_FWD_DEFINED__ *
  endif
  ifndef __IParseDisplayName_FWD_DEFINED__
    __IParseDisplayName_FWD_DEFINED__ equ <>
    ;* __IParseDisplayName_FWD_DEFINED__ *
  endif
  ifndef __IOleContainer_FWD_DEFINED__
    __IOleContainer_FWD_DEFINED__ equ <>
    ;* __IOleContainer_FWD_DEFINED__ *
  endif
  ifndef __IOleClientSite_FWD_DEFINED__
    __IOleClientSite_FWD_DEFINED__ equ <>
    ;* __IOleClientSite_FWD_DEFINED__ *
  endif
  ifndef __IOleObject_FWD_DEFINED__
    __IOleObject_FWD_DEFINED__ equ <>
    ;* __IOleObject_FWD_DEFINED__ *
  endif
  ifndef __IOleWindow_FWD_DEFINED__
    __IOleWindow_FWD_DEFINED__ equ <>
    ;* __IOleWindow_FWD_DEFINED__ *
  endif
  ifndef __IOleLink_FWD_DEFINED__
    __IOleLink_FWD_DEFINED__ equ <>
    ;* __IOleLink_FWD_DEFINED__ *
  endif
  ifndef __IOleItemContainer_FWD_DEFINED__
    __IOleItemContainer_FWD_DEFINED__ equ <>
    ;* __IOleItemContainer_FWD_DEFINED__ *
  endif
  ifndef __IOleInPlaceUIWindow_FWD_DEFINED__
    __IOleInPlaceUIWindow_FWD_DEFINED__ equ <>
    ;* __IOleInPlaceUIWindow_FWD_DEFINED__ *
  endif
  ifndef __IOleInPlaceActiveObject_FWD_DEFINED__
    __IOleInPlaceActiveObject_FWD_DEFINED__ equ <>
    ;* __IOleInPlaceActiveObject_FWD_DEFINED__ *
  endif
  ifndef __IOleInPlaceFrame_FWD_DEFINED__
    __IOleInPlaceFrame_FWD_DEFINED__ equ <>
    ;* __IOleInPlaceFrame_FWD_DEFINED__ *
  endif
  ifndef __IOleInPlaceObject_FWD_DEFINED__
    __IOleInPlaceObject_FWD_DEFINED__ equ <>
    ;* __IOleInPlaceObject_FWD_DEFINED__ *
  endif
  ifndef __IOleInPlaceSite_FWD_DEFINED__
    __IOleInPlaceSite_FWD_DEFINED__ equ <>
    ;* __IOleInPlaceSite_FWD_DEFINED__ *
  endif
  ifndef __IContinue_FWD_DEFINED__
    __IContinue_FWD_DEFINED__ equ <>
    ;* __IContinue_FWD_DEFINED__ *
  endif
  ifndef __IViewObject_FWD_DEFINED__
    __IViewObject_FWD_DEFINED__ equ <>
    ;* __IViewObject_FWD_DEFINED__ *
  endif
  ifndef __IViewObject2_FWD_DEFINED__
    __IViewObject2_FWD_DEFINED__ equ <>
    ;* __IViewObject2_FWD_DEFINED__ *
  endif
  ifndef __IDropSource_FWD_DEFINED__
    __IDropSource_FWD_DEFINED__ equ <>
    ;* __IDropSource_FWD_DEFINED__ *
  endif
  ifndef __IDropTarget_FWD_DEFINED__
    __IDropTarget_FWD_DEFINED__ equ <>
    ;* __IDropTarget_FWD_DEFINED__ *
  endif
  ifndef __IDropSourceNotify_FWD_DEFINED__
    __IDropSourceNotify_FWD_DEFINED__ equ <>
    ;* __IDropSourceNotify_FWD_DEFINED__ *
  endif
  ifndef __IEnterpriseDropTarget_FWD_DEFINED__
    __IEnterpriseDropTarget_FWD_DEFINED__ equ <>
    ;* __IEnterpriseDropTarget_FWD_DEFINED__ *
  endif
  ifndef __IEnumOLEVERB_FWD_DEFINED__
    __IEnumOLEVERB_FWD_DEFINED__ equ <>
    ;* __IEnumOLEVERB_FWD_DEFINED__ *
  endif
  ;* header files for imported files *
  include objidl.inc
  ifdef __cplusplus
    ;[...]
  endif
  ;* interface __MIDL_itf_oleidl_0000_0000 *
  ;* [local] *
  ;+-------------------------------------------------------------------------
  ;  Microsoft Windows
  ;  Copyright (c) Microsoft Corporation. All rights reserved.
  ;--------------------------------------------------------------------------
  if (_MSC_VER ge 1020)
  endif
  include winapifamily.inc
  if _MSC_VER ge 1200
    ;* padding added after data member *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_oleidl_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_oleidl_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IOleAdviseHolder_INTERFACE_DEFINED__
      __IOleAdviseHolder_INTERFACE_DEFINED__ equ <>
      ;* interface IOleAdviseHolder *
      ;* [uuid][object][local] *
      ;* [unique] *
      LPOLEADVISEHOLDER typedef ptr IOleAdviseHolder
      externdef IID_IOleAdviseHolder:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IOleAdviseHolderVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IOleAdviseHolderVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IOleAdviseHolder, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IOleAdviseHolder
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IOleAdviseHolder
          DECLSPEC_XFGVIRT(IOleAdviseHolder, Advise)
          ;* [annotation][unique][in] *
          ;* [annotation][out] *
          STD_METHOD Advise, :ptr IOleAdviseHolder, :ptr IAdviseSink, :ptr DWORD
          DECLSPEC_XFGVIRT(IOleAdviseHolder, Unadvise)
          STD_METHOD Unadvise, :ptr IOleAdviseHolder, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleAdviseHolder, EnumAdvise)
          ;* [annotation][out] *
          STD_METHOD EnumAdvise, :ptr IOleAdviseHolder, :ptr ptr IEnumSTATDATA
          DECLSPEC_XFGVIRT(IOleAdviseHolder, SendOnRename)
          ;* [annotation][unique][in] *
          STD_METHOD SendOnRename, :ptr IOleAdviseHolder, :ptr IMoniker
          DECLSPEC_XFGVIRT(IOleAdviseHolder, SendOnSave)
          STD_METHOD SendOnSave, :ptr IOleAdviseHolder
          DECLSPEC_XFGVIRT(IOleAdviseHolder, SendOnClose)
          STD_METHOD SendOnClose, :ptr IOleAdviseHolder
          ??Interface equ <>
          END_INTERFACE
        IOleAdviseHolderVtbl ends
        IOleAdviseHolder struct
          lpVtbl POINTER ?
        IOleAdviseHolder ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IOleAdviseHolder_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_oleidl_0000_0001 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_oleidl_0000_0001_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_oleidl_0000_0001_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IOleCache_INTERFACE_DEFINED__
      __IOleCache_INTERFACE_DEFINED__ equ <>
      ;* interface IOleCache *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPOLECACHE typedef ptr IOleCache
      externdef IID_IOleCache:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IOleCacheVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IOleCacheVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IOleCache, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IOleCache
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IOleCache
          DECLSPEC_XFGVIRT(IOleCache, Cache)
          ;* [unique][in] *
          ;* [in] *
          STD_METHOD Cache, :ptr IOleCache, :ptr FORMATETC, :DWORD, :ptr DWORD
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleCache, Uncache)
          STD_METHOD Uncache, :ptr IOleCache, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleCache, EnumCache)
          STD_METHOD EnumCache, :ptr IOleCache, :ptr ptr IEnumSTATDATA
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleCache, InitCache)
          STD_METHOD InitCache, :ptr IOleCache, :ptr IDataObject
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IOleCache, SetData)
          ;* [unique][in] *
          ;* [unique][in] *
          STD_METHOD SetData, :ptr IOleCache, :ptr FORMATETC, :ptr STGMEDIUM, :BOOL
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IOleCacheVtbl ends
        IOleCache struct
          lpVtbl POINTER ?
        IOleCache ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IOleCache_INTERFACE_DEFINED__ *
    endif
    ifndef __IOleCache2_INTERFACE_DEFINED__
      __IOleCache2_INTERFACE_DEFINED__ equ <>
      ;* interface IOleCache2 *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPOLECACHE2 typedef ptr IOleCache2
      UPDFCACHE_NODATACACHE equ (1h)
      UPDFCACHE_ONSAVECACHE equ (2h)
      UPDFCACHE_ONSTOPCACHE equ (4h)
      UPDFCACHE_NORMALCACHE equ (8h)
      UPDFCACHE_IFBLANK equ (10h)
      UPDFCACHE_ONLYIFBLANK equ (80000000h)
      UPDFCACHE_IFBLANKORONSAVECACHE equ <((UPDFCACHE_IFBLANK or UPDFCACHE_ONSAVECACHE))>
      UPDFCACHE_ALL equ <(not UPDFCACHE_ONLYIFBLANK)>
      UPDFCACHE_ALLBUTNODATACACHE equ <((UPDFCACHE_ALL and not UPDFCACHE_NODATACACHE))>
      ;* [v1_enum] *
      DISCARDCACHE typedef SDWORD
      DISCARDCACHE_SAVEIFDIRTY equ 0
      DISCARDCACHE_NOSAVE equ 1
      tagDISCARDCACHE typedef DISCARDCACHE

      externdef IID_IOleCache2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IOleCache2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IOleCache2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IOleCache2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IOleCache2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IOleCache2
          DECLSPEC_XFGVIRT(IOleCache, Cache)
          ;* [unique][in] *
          ;* [in] *
          STD_METHOD Cache, :ptr IOleCache2, :ptr FORMATETC, :DWORD, :ptr DWORD
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleCache, Uncache)
          STD_METHOD Uncache, :ptr IOleCache2, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleCache, EnumCache)
          STD_METHOD EnumCache, :ptr IOleCache2, :ptr ptr IEnumSTATDATA
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleCache, InitCache)
          STD_METHOD InitCache, :ptr IOleCache2, :ptr IDataObject
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IOleCache, SetData)
          ;* [unique][in] *
          ;* [unique][in] *
          STD_METHOD SetData, :ptr IOleCache2, :ptr FORMATETC, :ptr STGMEDIUM, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleCache2, UpdateCache)
          ;* [local] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          STD_METHOD UpdateCache, :ptr IOleCache2, :LPDATAOBJECT, :DWORD, :LPVOID
          DECLSPEC_XFGVIRT(IOleCache2, DiscardCache)
          STD_METHOD DiscardCache, :ptr IOleCache2, :DWORD
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IOleCache2Vtbl ends
        IOleCache2 struct
          lpVtbl POINTER ?
        IOleCache2 ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      IOleCache2_RemoteUpdateCache_Proxy proto WIN_STD_CALL_CONV :ptr IOleCache2, :LPDATAOBJECT, :DWORD, :LONG_PTR
      ;* [in] *
      IOleCache2_RemoteUpdateCache_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __IOleCache2_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_oleidl_0000_0003 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_oleidl_0000_0003_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_oleidl_0000_0003_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IOleCacheControl_INTERFACE_DEFINED__
      __IOleCacheControl_INTERFACE_DEFINED__ equ <>
      ;* interface IOleCacheControl *
      ;* [uuid][object] *
      ;* [unique] *
      LPOLECACHECONTROL typedef ptr IOleCacheControl
      externdef IID_IOleCacheControl:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IOleCacheControlVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IOleCacheControlVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IOleCacheControl, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IOleCacheControl
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IOleCacheControl
          DECLSPEC_XFGVIRT(IOleCacheControl, OnRun)
          STD_METHOD OnRun, :ptr IOleCacheControl, :LPDATAOBJECT
          DECLSPEC_XFGVIRT(IOleCacheControl, OnStop)
          STD_METHOD OnStop, :ptr IOleCacheControl
          ??Interface equ <>
          END_INTERFACE
        IOleCacheControlVtbl ends
        IOleCacheControl struct
          lpVtbl POINTER ?
        IOleCacheControl ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IOleCacheControl_INTERFACE_DEFINED__ *
    endif
    ifndef __IParseDisplayName_INTERFACE_DEFINED__
      __IParseDisplayName_INTERFACE_DEFINED__ equ <>
      ;* interface IParseDisplayName *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPPARSEDISPLAYNAME typedef ptr IParseDisplayName
      externdef IID_IParseDisplayName:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IParseDisplayNameVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IParseDisplayNameVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IParseDisplayName, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IParseDisplayName
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IParseDisplayName
          DECLSPEC_XFGVIRT(IParseDisplayName, ParseDisplayName)
          ;* [unique][in] *
          ;* [in] *
          ;* [out] *
          STD_METHOD ParseDisplayName, :ptr IParseDisplayName, :ptr IBindCtx, :LPOLESTR, :ptr ULONG, :ptr ptr IMoniker
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IParseDisplayNameVtbl ends
        IParseDisplayName struct
          lpVtbl POINTER ?
        IParseDisplayName ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IParseDisplayName_INTERFACE_DEFINED__ *
    endif
    ifndef __IOleContainer_INTERFACE_DEFINED__
      __IOleContainer_INTERFACE_DEFINED__ equ <>
      ;* interface IOleContainer *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPOLECONTAINER typedef ptr IOleContainer
      externdef IID_IOleContainer:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IOleContainerVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IOleContainerVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IOleContainer, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IOleContainer
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IOleContainer
          DECLSPEC_XFGVIRT(IParseDisplayName, ParseDisplayName)
          ;* [unique][in] *
          ;* [in] *
          ;* [out] *
          STD_METHOD ParseDisplayName, :ptr IOleContainer, :ptr IBindCtx, :LPOLESTR, :ptr ULONG, :ptr ptr IMoniker
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleContainer, EnumObjects)
          ;* [in] *
          STD_METHOD EnumObjects, :ptr IOleContainer, :DWORD, :ptr ptr IEnumUnknown
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleContainer, LockContainer)
          STD_METHOD LockContainer, :ptr IOleContainer, :BOOL
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IOleContainerVtbl ends
        IOleContainer struct
          lpVtbl POINTER ?
        IOleContainer ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IOleContainer_INTERFACE_DEFINED__ *
    endif
    ifndef __IOleClientSite_INTERFACE_DEFINED__
      __IOleClientSite_INTERFACE_DEFINED__ equ <>
      ;* interface IOleClientSite *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPOLECLIENTSITE typedef ptr IOleClientSite
      externdef IID_IOleClientSite:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IOleClientSiteVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IOleClientSiteVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IOleClientSite, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IOleClientSite
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IOleClientSite
          DECLSPEC_XFGVIRT(IOleClientSite, SaveObject)
          STD_METHOD SaveObject, :ptr IOleClientSite
          DECLSPEC_XFGVIRT(IOleClientSite, GetMoniker)
          ;* [in] *
          ;* [in] *
          STD_METHOD GetMoniker, :ptr IOleClientSite, :DWORD, :DWORD, :ptr ptr IMoniker
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleClientSite, GetContainer)
          STD_METHOD GetContainer, :ptr IOleClientSite, :ptr ptr IOleContainer
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleClientSite, ShowObject)
          STD_METHOD ShowObject, :ptr IOleClientSite
          DECLSPEC_XFGVIRT(IOleClientSite, OnShowWindow)
          STD_METHOD OnShowWindow, :ptr IOleClientSite, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleClientSite, RequestNewObjectLayout)
          STD_METHOD RequestNewObjectLayout, :ptr IOleClientSite
          ??Interface equ <>
          END_INTERFACE
        IOleClientSiteVtbl ends
        IOleClientSite struct
          lpVtbl POINTER ?
        IOleClientSite ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IOleClientSite_INTERFACE_DEFINED__ *
    endif
    ifndef __IOleObject_INTERFACE_DEFINED__
      __IOleObject_INTERFACE_DEFINED__ equ <>
      ;* interface IOleObject *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPOLEOBJECT typedef ptr IOleObject
      OLEGETMONIKER typedef SDWORD
      OLEGETMONIKER_ONLYIFTHERE equ 1
      OLEGETMONIKER_FORCEASSIGN equ 2
      OLEGETMONIKER_UNASSIGN equ 3
      OLEGETMONIKER_TEMPFORUSER equ 4
      tagOLEGETMONIKER typedef OLEGETMONIKER

      OLEWHICHMK typedef SDWORD
      OLEWHICHMK_CONTAINER equ 1
      OLEWHICHMK_OBJREL equ 2
      OLEWHICHMK_OBJFULL equ 3
      tagOLEWHICHMK typedef OLEWHICHMK

      USERCLASSTYPE typedef SDWORD
      USERCLASSTYPE_FULL equ 1
      USERCLASSTYPE_SHORT equ 2
      USERCLASSTYPE_APPNAME equ 3
      tagUSERCLASSTYPE typedef USERCLASSTYPE

      OLEMISC typedef SDWORD
      OLEMISC_RECOMPOSEONRESIZE equ 1h
      OLEMISC_ONLYICONIC equ 2h
      OLEMISC_INSERTNOTREPLACE equ 4h
      OLEMISC_STATIC equ 8h
      OLEMISC_CANTLINKINSIDE equ 10h
      OLEMISC_CANLINKBYOLE1 equ 20h
      OLEMISC_ISLINKOBJECT equ 40h
      OLEMISC_INSIDEOUT equ 80h
      OLEMISC_ACTIVATEWHENVISIBLE equ 100h
      OLEMISC_RENDERINGISDEVICEINDEPENDENT equ 200h
      OLEMISC_INVISIBLEATRUNTIME equ 400h
      OLEMISC_ALWAYSRUN equ 800h
      OLEMISC_ACTSLIKEBUTTON equ 1000h
      OLEMISC_ACTSLIKELABEL equ 2000h
      OLEMISC_NOUIACTIVATE equ 4000h
      OLEMISC_ALIGNABLE equ 8000h
      OLEMISC_SIMPLEFRAME equ 10000h
      OLEMISC_SETCLIENTSITEFIRST equ 20000h
      OLEMISC_IMEMODE equ 40000h
      OLEMISC_IGNOREACTIVATEWHENVISIBLE equ 80000h
      OLEMISC_WANTSTOMENUMERGE equ 100000h
      OLEMISC_SUPPORTSMULTILEVELUNDO equ 200000h
      tagOLEMISC typedef OLEMISC

      OLECLOSE typedef SDWORD
      OLECLOSE_SAVEIFDIRTY equ 0
      OLECLOSE_NOSAVE equ 1
      OLECLOSE_PROMPTSAVE equ 2
      tagOLECLOSE typedef OLECLOSE

      externdef IID_IOleObject:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IOleObjectVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IOleObjectVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IOleObject, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IOleObject
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IOleObject
          DECLSPEC_XFGVIRT(IOleObject, SetClientSite)
          STD_METHOD SetClientSite, :ptr IOleObject, :ptr IOleClientSite
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IOleObject, GetClientSite)
          STD_METHOD GetClientSite, :ptr IOleObject, :ptr ptr IOleClientSite
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleObject, SetHostNames)
          ;* [in] *
          STD_METHOD SetHostNames, :ptr IOleObject, :LPCOLESTR, :LPCOLESTR
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IOleObject, Close)
          STD_METHOD Close, :ptr IOleObject, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleObject, SetMoniker)
          ;* [in] *
          STD_METHOD SetMoniker, :ptr IOleObject, :DWORD, :ptr IMoniker
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IOleObject, GetMoniker)
          ;* [in] *
          ;* [in] *
          STD_METHOD GetMoniker, :ptr IOleObject, :DWORD, :DWORD, :ptr ptr IMoniker
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleObject, InitFromData)
          ;* [unique][in] *
          ;* [in] *
          STD_METHOD InitFromData, :ptr IOleObject, :ptr IDataObject, :BOOL, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleObject, GetClipboardData)
          ;* [in] *
          STD_METHOD GetClipboardData, :ptr IOleObject, :DWORD, :ptr ptr IDataObject
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleObject, DoVerb)
          ;* [in] *
          ;* [unique][in] *
          ;* [unique][in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD DoVerb, :ptr IOleObject, :LONG, :LPMSG, :ptr IOleClientSite, :LONG, :HWND, :LPCRECT
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IOleObject, EnumVerbs)
          STD_METHOD EnumVerbs, :ptr IOleObject, :ptr ptr IEnumOLEVERB
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleObject, Update)
          STD_METHOD Update, :ptr IOleObject
          DECLSPEC_XFGVIRT(IOleObject, IsUpToDate)
          STD_METHOD IsUpToDate, :ptr IOleObject
          DECLSPEC_XFGVIRT(IOleObject, GetUserClassID)
          STD_METHOD GetUserClassID, :ptr IOleObject, :ptr CLSID
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleObject, GetUserType)
          ;* [in] *
          STD_METHOD GetUserType, :ptr IOleObject, :DWORD, :ptr LPOLESTR
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleObject, SetExtent)
          ;* [in] *
          STD_METHOD SetExtent, :ptr IOleObject, :DWORD, :ptr SIZEL
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleObject, GetExtent)
          ;* [in] *
          STD_METHOD GetExtent, :ptr IOleObject, :DWORD, :ptr SIZEL
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleObject, Advise)
          ;* [unique][in] *
          STD_METHOD Advise, :ptr IOleObject, :ptr IAdviseSink, :ptr DWORD
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleObject, Unadvise)
          STD_METHOD Unadvise, :ptr IOleObject, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleObject, EnumAdvise)
          STD_METHOD EnumAdvise, :ptr IOleObject, :ptr ptr IEnumSTATDATA
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleObject, GetMiscStatus)
          ;* [in] *
          STD_METHOD GetMiscStatus, :ptr IOleObject, :DWORD, :ptr DWORD
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleObject, SetColorScheme)
          STD_METHOD SetColorScheme, :ptr IOleObject, :ptr LOGPALETTE
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IOleObjectVtbl ends
        IOleObject struct
          lpVtbl POINTER ?
        IOleObject ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IOleObject_INTERFACE_DEFINED__ *
    endif
    ifndef __IOLETypes_INTERFACE_DEFINED__
      __IOLETypes_INTERFACE_DEFINED__ equ <>
      ;* interface IOLETypes *
      ;* [uuid] *
      OLERENDER typedef SDWORD
      OLERENDER_NONE equ 0
      OLERENDER_DRAW equ 1
      OLERENDER_FORMAT equ 2
      OLERENDER_ASIS equ 3
      tagOLERENDER typedef OLERENDER

      LPOLERENDER typedef ptr OLERENDER
      OBJECTDESCRIPTOR struct
        cbSize DWORD ?
        clsid CLSID <>
        dwDrawAspect DWORD ?
        sizel SIZEL <>
        pointl POINTL <>
        dwStatus DWORD ?
        dwFullUserTypeName DWORD ?
        dwSrcOfCopy DWORD ?
      OBJECTDESCRIPTOR ends
      tagOBJECTDESCRIPTOR typedef OBJECTDESCRIPTOR
      POBJECTDESCRIPTOR typedef ptr tagOBJECTDESCRIPTOR
      LPOBJECTDESCRIPTOR typedef ptr tagOBJECTDESCRIPTOR
      LINKSRCDESCRIPTOR typedef tagOBJECTDESCRIPTOR
      PLINKSRCDESCRIPTOR typedef ptr tagOBJECTDESCRIPTOR
      LPLINKSRCDESCRIPTOR typedef ptr tagOBJECTDESCRIPTOR
      externdef IOLETypes_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef IOLETypes_v0_0_s_ifspec:RPC_IF_HANDLE
      ;* __IOLETypes_INTERFACE_DEFINED__ *
    endif
    ifndef __IOleWindow_INTERFACE_DEFINED__
      __IOleWindow_INTERFACE_DEFINED__ equ <>
      ;* interface IOleWindow *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPOLEWINDOW typedef ptr IOleWindow
      externdef IID_IOleWindow:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IOleWindowVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IOleWindowVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IOleWindow, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IOleWindow
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IOleWindow
          DECLSPEC_XFGVIRT(IOleWindow, GetWindow)
          ;* [input_sync] *
          STD_METHOD GetWindow, :ptr IOleWindow, :ptr HWND
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleWindow, ContextSensitiveHelp)
          STD_METHOD ContextSensitiveHelp, :ptr IOleWindow, :BOOL
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IOleWindowVtbl ends
        IOleWindow struct
          lpVtbl POINTER ?
        IOleWindow ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IOleWindow_INTERFACE_DEFINED__ *
    endif
    ifndef __IOleLink_INTERFACE_DEFINED__
      __IOleLink_INTERFACE_DEFINED__ equ <>
      ;* interface IOleLink *
      ;* [uuid][object] *
      ;* [unique] *
      LPOLELINK typedef ptr IOleLink
      OLEUPDATE typedef SDWORD
      OLEUPDATE_ALWAYS equ 1
      OLEUPDATE_ONCALL equ 3
      tagOLEUPDATE typedef OLEUPDATE

      LPOLEUPDATE typedef ptr OLEUPDATE
      POLEUPDATE typedef ptr OLEUPDATE
      OLELINKBIND typedef SDWORD
      OLELINKBIND_EVENIFCLASSDIFF equ 1
      tagOLELINKBIND typedef OLELINKBIND

      externdef IID_IOleLink:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IOleLinkVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IOleLinkVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IOleLink, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IOleLink
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IOleLink
          DECLSPEC_XFGVIRT(IOleLink, SetUpdateOptions)
          STD_METHOD SetUpdateOptions, :ptr IOleLink, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleLink, GetUpdateOptions)
          STD_METHOD GetUpdateOptions, :ptr IOleLink, :ptr DWORD
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleLink, SetSourceMoniker)
          ;* [unique][in] *
          STD_METHOD SetSourceMoniker, :ptr IOleLink, :ptr IMoniker, :REFCLSID
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleLink, GetSourceMoniker)
          STD_METHOD GetSourceMoniker, :ptr IOleLink, :ptr ptr IMoniker
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleLink, SetSourceDisplayName)
          STD_METHOD SetSourceDisplayName, :ptr IOleLink, :LPCOLESTR
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleLink, GetSourceDisplayName)
          STD_METHOD GetSourceDisplayName, :ptr IOleLink, :ptr LPOLESTR
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleLink, BindToSource)
          ;* [in] *
          STD_METHOD BindToSource, :ptr IOleLink, :DWORD, :ptr IBindCtx
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IOleLink, BindIfRunning)
          STD_METHOD BindIfRunning, :ptr IOleLink
          DECLSPEC_XFGVIRT(IOleLink, GetBoundSource)
          STD_METHOD GetBoundSource, :ptr IOleLink, :ptr ptr IUnknown
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleLink, UnbindSource)
          STD_METHOD UnbindSource, :ptr IOleLink
          DECLSPEC_XFGVIRT(IOleLink, Update)
          STD_METHOD Update, :ptr IOleLink, :ptr IBindCtx
          ;* [unique][in] *
          ??Interface equ <>
          END_INTERFACE
        IOleLinkVtbl ends
        IOleLink struct
          lpVtbl POINTER ?
        IOleLink ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IOleLink_INTERFACE_DEFINED__ *
    endif
    ifndef __IOleItemContainer_INTERFACE_DEFINED__
      __IOleItemContainer_INTERFACE_DEFINED__ equ <>
      ;* interface IOleItemContainer *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPOLEITEMCONTAINER typedef ptr IOleItemContainer
      BINDSPEED typedef SDWORD
      BINDSPEED_INDEFINITE equ 1
      BINDSPEED_MODERATE equ 2
      BINDSPEED_IMMEDIATE equ 3
      tagBINDSPEED typedef BINDSPEED

      ;* [v1_enum] *
      OLECONTF typedef SDWORD
      OLECONTF_EMBEDDINGS equ 1
      OLECONTF_LINKS equ 2
      OLECONTF_OTHERS equ 4
      OLECONTF_ONLYUSER equ 8
      OLECONTF_ONLYIFRUNNING equ 16
      tagOLECONTF typedef OLECONTF

      externdef IID_IOleItemContainer:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IOleItemContainerVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IOleItemContainerVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IOleItemContainer, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IOleItemContainer
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IOleItemContainer
          DECLSPEC_XFGVIRT(IParseDisplayName, ParseDisplayName)
          ;* [unique][in] *
          ;* [in] *
          ;* [out] *
          STD_METHOD ParseDisplayName, :ptr IOleItemContainer, :ptr IBindCtx, :LPOLESTR, :ptr ULONG, :ptr ptr IMoniker
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleContainer, EnumObjects)
          ;* [in] *
          STD_METHOD EnumObjects, :ptr IOleItemContainer, :DWORD, :ptr ptr IEnumUnknown
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleContainer, LockContainer)
          STD_METHOD LockContainer, :ptr IOleItemContainer, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleItemContainer, GetObject)
          ;* [in] *
          ;* [in] *
          ;* [unique][in] *
          ;* [in] *
          STD_METHOD GetObject, :ptr IOleItemContainer, :LPOLESTR, :DWORD, :ptr IBindCtx, :REFIID, :ptr ptr
          ;* [iid_is][out] *
          DECLSPEC_XFGVIRT(IOleItemContainer, GetObjectStorage)
          ;* [in] *
          ;* [unique][in] *
          ;* [in] *
          STD_METHOD GetObjectStorage, :ptr IOleItemContainer, :LPOLESTR, :ptr IBindCtx, :REFIID, :ptr ptr
          ;* [iid_is][out] *
          DECLSPEC_XFGVIRT(IOleItemContainer, IsRunning)
          STD_METHOD IsRunning, :ptr IOleItemContainer, :LPOLESTR
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IOleItemContainerVtbl ends
        IOleItemContainer struct
          lpVtbl POINTER ?
        IOleItemContainer ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IOleItemContainer_INTERFACE_DEFINED__ *
    endif
    ifndef __IOleInPlaceUIWindow_INTERFACE_DEFINED__
      __IOleInPlaceUIWindow_INTERFACE_DEFINED__ equ <>
      ;* interface IOleInPlaceUIWindow *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPOLEINPLACEUIWINDOW typedef ptr IOleInPlaceUIWindow
      BORDERWIDTHS typedef RECT
      LPBORDERWIDTHS typedef LPRECT
      LPCBORDERWIDTHS typedef LPCRECT
      externdef IID_IOleInPlaceUIWindow:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IOleInPlaceUIWindowVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IOleInPlaceUIWindowVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IOleInPlaceUIWindow, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IOleInPlaceUIWindow
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IOleInPlaceUIWindow
          DECLSPEC_XFGVIRT(IOleWindow, GetWindow)
          ;* [input_sync] *
          STD_METHOD GetWindow, :ptr IOleInPlaceUIWindow, :ptr HWND
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleWindow, ContextSensitiveHelp)
          STD_METHOD ContextSensitiveHelp, :ptr IOleInPlaceUIWindow, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleInPlaceUIWindow, GetBorder)
          ;* [input_sync] *
          STD_METHOD GetBorder, :ptr IOleInPlaceUIWindow, :LPRECT
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleInPlaceUIWindow, RequestBorderSpace)
          ;* [input_sync] *
          STD_METHOD RequestBorderSpace, :ptr IOleInPlaceUIWindow, :LPCBORDERWIDTHS
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IOleInPlaceUIWindow, SetBorderSpace)
          ;* [input_sync] *
          STD_METHOD SetBorderSpace, :ptr IOleInPlaceUIWindow, :LPCBORDERWIDTHS
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IOleInPlaceUIWindow, SetActiveObject)
          ;* [unique][in] *
          STD_METHOD SetActiveObject, :ptr IOleInPlaceUIWindow, :ptr IOleInPlaceActiveObject, :LPCOLESTR
          ;* [unique][string][in] *
          ??Interface equ <>
          END_INTERFACE
        IOleInPlaceUIWindowVtbl ends
        IOleInPlaceUIWindow struct
          lpVtbl POINTER ?
        IOleInPlaceUIWindow ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IOleInPlaceUIWindow_INTERFACE_DEFINED__ *
    endif
    ifndef __IOleInPlaceActiveObject_INTERFACE_DEFINED__
      __IOleInPlaceActiveObject_INTERFACE_DEFINED__ equ <>
      ;* interface IOleInPlaceActiveObject *
      ;* [uuid][object] *
      ;* [unique] *
      LPOLEINPLACEACTIVEOBJECT typedef ptr IOleInPlaceActiveObject
      externdef IID_IOleInPlaceActiveObject:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IOleInPlaceActiveObjectVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IOleInPlaceActiveObjectVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IOleInPlaceActiveObject, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IOleInPlaceActiveObject
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IOleInPlaceActiveObject
          DECLSPEC_XFGVIRT(IOleWindow, GetWindow)
          ;* [input_sync] *
          STD_METHOD GetWindow, :ptr IOleInPlaceActiveObject, :ptr HWND
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleWindow, ContextSensitiveHelp)
          STD_METHOD ContextSensitiveHelp, :ptr IOleInPlaceActiveObject, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleInPlaceActiveObject, TranslateAccelerator)
          ;* [local] *
          ;* [annotation][in] *
          STD_METHOD TranslateAccelerator, :ptr IOleInPlaceActiveObject, :LPMSG
          DECLSPEC_XFGVIRT(IOleInPlaceActiveObject, OnFrameWindowActivate)
          ;* [input_sync] *
          STD_METHOD OnFrameWindowActivate, :ptr IOleInPlaceActiveObject, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleInPlaceActiveObject, OnDocWindowActivate)
          ;* [input_sync] *
          STD_METHOD OnDocWindowActivate, :ptr IOleInPlaceActiveObject, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleInPlaceActiveObject, ResizeBorder)
          ;* [local] *
          ;* [annotation][in] *
          ;* [annotation][unique][in] *
          ;* [annotation][in] *
          STD_METHOD ResizeBorder, :ptr IOleInPlaceActiveObject, :LPCRECT, :ptr IOleInPlaceUIWindow, :BOOL
          DECLSPEC_XFGVIRT(IOleInPlaceActiveObject, EnableModeless)
          STD_METHOD EnableModeless, :ptr IOleInPlaceActiveObject, :BOOL
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IOleInPlaceActiveObjectVtbl ends
        IOleInPlaceActiveObject struct
          lpVtbl POINTER ?
        IOleInPlaceActiveObject ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      IOleInPlaceActiveObject_RemoteTranslateAccelerator_Proxy proto WIN_STD_CALL_CONV :ptr IOleInPlaceActiveObject
      IOleInPlaceActiveObject_RemoteTranslateAccelerator_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [input_sync][call_as] *
      IOleInPlaceActiveObject_RemoteResizeBorder_Proxy proto WIN_STD_CALL_CONV :ptr IOleInPlaceActiveObject, :LPCRECT, :REFIID, :ptr IOleInPlaceUIWindow, :BOOL
      ;* [in] *
      IOleInPlaceActiveObject_RemoteResizeBorder_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __IOleInPlaceActiveObject_INTERFACE_DEFINED__ *
    endif
    ifndef __IOleInPlaceFrame_INTERFACE_DEFINED__
      __IOleInPlaceFrame_INTERFACE_DEFINED__ equ <>
      ;* interface IOleInPlaceFrame *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPOLEINPLACEFRAME typedef ptr IOleInPlaceFrame
      OLEINPLACEFRAMEINFO struct
        cb DWORD ?
        fMDIApp DWORD ?
        hwndFrame HWND ?
        haccel HACCEL ?
        cAccelEntries DWORD ?
      OLEINPLACEFRAMEINFO ends
      tagOIFI typedef OLEINPLACEFRAMEINFO
      LPOLEINPLACEFRAMEINFO typedef ptr tagOIFI
      OLEMENUGROUPWIDTHS struct
        width_ SDWORD 6 dup (?)
      OLEMENUGROUPWIDTHS ends
      tagOleMenuGroupWidths typedef OLEMENUGROUPWIDTHS
      LPOLEMENUGROUPWIDTHS typedef ptr tagOleMenuGroupWidths
      HOLEMENU typedef HGLOBAL
      externdef IID_IOleInPlaceFrame:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IOleInPlaceFrameVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IOleInPlaceFrameVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IOleInPlaceFrame, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IOleInPlaceFrame
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IOleInPlaceFrame
          DECLSPEC_XFGVIRT(IOleWindow, GetWindow)
          ;* [input_sync] *
          STD_METHOD GetWindow, :ptr IOleInPlaceFrame, :ptr HWND
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleWindow, ContextSensitiveHelp)
          STD_METHOD ContextSensitiveHelp, :ptr IOleInPlaceFrame, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleInPlaceUIWindow, GetBorder)
          ;* [input_sync] *
          STD_METHOD GetBorder, :ptr IOleInPlaceFrame, :LPRECT
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleInPlaceUIWindow, RequestBorderSpace)
          ;* [input_sync] *
          STD_METHOD RequestBorderSpace, :ptr IOleInPlaceFrame, :LPCBORDERWIDTHS
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IOleInPlaceUIWindow, SetBorderSpace)
          ;* [input_sync] *
          STD_METHOD SetBorderSpace, :ptr IOleInPlaceFrame, :LPCBORDERWIDTHS
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IOleInPlaceUIWindow, SetActiveObject)
          ;* [unique][in] *
          STD_METHOD SetActiveObject, :ptr IOleInPlaceFrame, :ptr IOleInPlaceActiveObject, :LPCOLESTR
          ;* [unique][string][in] *
          DECLSPEC_XFGVIRT(IOleInPlaceFrame, InsertMenus)
          ;* [in] *
          STD_METHOD InsertMenus, :ptr IOleInPlaceFrame, :HMENU, :LPOLEMENUGROUPWIDTHS
          ;* [out][in] *
          DECLSPEC_XFGVIRT(IOleInPlaceFrame, SetMenu)
          ;* [input_sync] *
          ;* [in] *
          ;* [in] *
          STD_METHOD SetMenu, :ptr IOleInPlaceFrame, :HMENU, :HOLEMENU, :HWND
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleInPlaceFrame, RemoveMenus)
          STD_METHOD RemoveMenus, :ptr IOleInPlaceFrame, :HMENU
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleInPlaceFrame, SetStatusText)
          ;* [input_sync] *
          STD_METHOD SetStatusText, :ptr IOleInPlaceFrame, :LPCOLESTR
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IOleInPlaceFrame, EnableModeless)
          STD_METHOD EnableModeless, :ptr IOleInPlaceFrame, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleInPlaceFrame, TranslateAccelerator)
          ;* [in] *
          STD_METHOD TranslateAccelerator, :ptr IOleInPlaceFrame, :LPMSG, :WORD
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IOleInPlaceFrameVtbl ends
        IOleInPlaceFrame struct
          lpVtbl POINTER ?
        IOleInPlaceFrame ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IOleInPlaceFrame_INTERFACE_DEFINED__ *
    endif
    ifndef __IOleInPlaceObject_INTERFACE_DEFINED__
      __IOleInPlaceObject_INTERFACE_DEFINED__ equ <>
      ;* interface IOleInPlaceObject *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPOLEINPLACEOBJECT typedef ptr IOleInPlaceObject
      externdef IID_IOleInPlaceObject:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IOleInPlaceObjectVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IOleInPlaceObjectVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IOleInPlaceObject, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IOleInPlaceObject
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IOleInPlaceObject
          DECLSPEC_XFGVIRT(IOleWindow, GetWindow)
          ;* [input_sync] *
          STD_METHOD GetWindow, :ptr IOleInPlaceObject, :ptr HWND
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleWindow, ContextSensitiveHelp)
          STD_METHOD ContextSensitiveHelp, :ptr IOleInPlaceObject, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleInPlaceObject, InPlaceDeactivate)
          STD_METHOD InPlaceDeactivate, :ptr IOleInPlaceObject
          DECLSPEC_XFGVIRT(IOleInPlaceObject, UIDeactivate)
          STD_METHOD UIDeactivate, :ptr IOleInPlaceObject
          DECLSPEC_XFGVIRT(IOleInPlaceObject, SetObjectRects)
          ;* [input_sync] *
          ;* [in] *
          STD_METHOD SetObjectRects, :ptr IOleInPlaceObject, :LPCRECT, :LPCRECT
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleInPlaceObject, ReactivateAndUndo)
          STD_METHOD ReactivateAndUndo, :ptr IOleInPlaceObject
          ??Interface equ <>
          END_INTERFACE
        IOleInPlaceObjectVtbl ends
        IOleInPlaceObject struct
          lpVtbl POINTER ?
        IOleInPlaceObject ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IOleInPlaceObject_INTERFACE_DEFINED__ *
    endif
    ifndef __IOleInPlaceSite_INTERFACE_DEFINED__
      __IOleInPlaceSite_INTERFACE_DEFINED__ equ <>
      ;* interface IOleInPlaceSite *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPOLEINPLACESITE typedef ptr IOleInPlaceSite
      externdef IID_IOleInPlaceSite:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IOleInPlaceSiteVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IOleInPlaceSiteVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IOleInPlaceSite, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IOleInPlaceSite
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IOleInPlaceSite
          DECLSPEC_XFGVIRT(IOleWindow, GetWindow)
          ;* [input_sync] *
          STD_METHOD GetWindow, :ptr IOleInPlaceSite, :ptr HWND
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleWindow, ContextSensitiveHelp)
          STD_METHOD ContextSensitiveHelp, :ptr IOleInPlaceSite, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleInPlaceSite, CanInPlaceActivate)
          STD_METHOD CanInPlaceActivate, :ptr IOleInPlaceSite
          DECLSPEC_XFGVIRT(IOleInPlaceSite, OnInPlaceActivate)
          STD_METHOD OnInPlaceActivate, :ptr IOleInPlaceSite
          DECLSPEC_XFGVIRT(IOleInPlaceSite, OnUIActivate)
          STD_METHOD OnUIActivate, :ptr IOleInPlaceSite
          DECLSPEC_XFGVIRT(IOleInPlaceSite, GetWindowContext)
          ;* [out] *
          ;* [out] *
          ;* [out] *
          ;* [out] *
          STD_METHOD GetWindowContext, :ptr IOleInPlaceSite, :ptr ptr IOleInPlaceFrame, :ptr ptr IOleInPlaceUIWindow, :LPRECT, :LPRECT, :LPOLEINPLACEFRAMEINFO
          ;* [out][in] *
          DECLSPEC_XFGVIRT(IOleInPlaceSite, Scroll)
          STD_METHOD Scroll, :ptr IOleInPlaceSite, :SIZE_
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleInPlaceSite, OnUIDeactivate)
          STD_METHOD OnUIDeactivate, :ptr IOleInPlaceSite, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleInPlaceSite, OnInPlaceDeactivate)
          STD_METHOD OnInPlaceDeactivate, :ptr IOleInPlaceSite
          DECLSPEC_XFGVIRT(IOleInPlaceSite, DiscardUndoState)
          STD_METHOD DiscardUndoState, :ptr IOleInPlaceSite
          DECLSPEC_XFGVIRT(IOleInPlaceSite, DeactivateAndUndo)
          STD_METHOD DeactivateAndUndo, :ptr IOleInPlaceSite
          DECLSPEC_XFGVIRT(IOleInPlaceSite, OnPosRectChange)
          STD_METHOD OnPosRectChange, :ptr IOleInPlaceSite, :LPCRECT
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IOleInPlaceSiteVtbl ends
        IOleInPlaceSite struct
          lpVtbl POINTER ?
        IOleInPlaceSite ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IOleInPlaceSite_INTERFACE_DEFINED__ *
    endif
    ifndef __IContinue_INTERFACE_DEFINED__
      __IContinue_INTERFACE_DEFINED__ equ <>
      ;* interface IContinue *
      ;* [uuid][object] *
      externdef IID_IContinue:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IContinueVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IContinueVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IContinue, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IContinue
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IContinue
          DECLSPEC_XFGVIRT(IContinue, FContinue)
          STD_METHOD FContinue, :ptr IContinue
          ??Interface equ <>
          END_INTERFACE
        IContinueVtbl ends
        IContinue struct
          lpVtbl POINTER ?
        IContinue ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IContinue_INTERFACE_DEFINED__ *
    endif
    ifndef __IViewObject_INTERFACE_DEFINED__
      __IViewObject_INTERFACE_DEFINED__ equ <>
      ;* interface IViewObject *
      ;* [uuid][object] *
      ;* [unique] *
      LPVIEWOBJECT typedef ptr IViewObject
      externdef IID_IViewObject:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IViewObjectVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IViewObjectVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IViewObject, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IViewObject
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IViewObject
          DECLSPEC_XFGVIRT(IViewObject, Draw)
          ;* [local] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][unique][in] *
          ;* [annotation][unique][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][unique][in] *
          ;* [annotation][in] *
          TYPE_Draw_pfnContinue typedef proto WIN_STD_CALL_CONV :ULONG_PTR
          PDraw_pfnContinue typedef ptr TYPEDraw_pfnContinue
          pfnContinue PDraw_pfnContinue ?
          ;* [annotation][in] *
          STD_METHOD Draw, :ptr IViewObject, :DWORD, :LONG, :ptr, :ptr DVTARGETDEVICE, :HDC, :HDC, :LPCRECTL, :LPCRECTL, :, :ULONG_PTR
          DECLSPEC_XFGVIRT(IViewObject, GetColorSet)
          ;* [local] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][unique][in] *
          ;* [annotation][unique][in] *
          ;* [annotation][in] *
          ;* [annotation][out] *
          STD_METHOD GetColorSet, :ptr IViewObject, :DWORD, :LONG, :ptr, :ptr DVTARGETDEVICE, :HDC, :ptr ptr LOGPALETTE
          DECLSPEC_XFGVIRT(IViewObject, Freeze)
          ;* [local] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][unique][in] *
          ;* [annotation][out] *
          STD_METHOD Freeze, :ptr IViewObject, :DWORD, :LONG, :ptr, :ptr DWORD
          DECLSPEC_XFGVIRT(IViewObject, Unfreeze)
          STD_METHOD Unfreeze, :ptr IViewObject, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IViewObject, SetAdvise)
          ;* [in] *
          ;* [in] *
          STD_METHOD SetAdvise, :ptr IViewObject, :DWORD, :DWORD, :ptr IAdviseSink
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IViewObject, GetAdvise)
          ;* [local] *
          ;* [annotation][unique][out] *
          ;* [annotation][unique][out] *
          ;* [annotation][out] *
          STD_METHOD GetAdvise, :ptr IViewObject, :ptr DWORD, :ptr DWORD, :ptr ptr IAdviseSink
          ??Interface equ <>
          END_INTERFACE
        IViewObjectVtbl ends
        IViewObject struct
          lpVtbl POINTER ?
        IViewObject ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      IViewObject_RemoteDraw_Proxy proto WIN_STD_CALL_CONV :ptr IViewObject, :DWORD, :LONG, :ULONG_PTR, :ptr DVTARGETDEVICE, :HDC, :HDC, :LPCRECTL, :LPCRECTL, :ptr IContinue
      ;* [in] *
      IViewObject_RemoteDraw_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      IViewObject_RemoteGetColorSet_Proxy proto WIN_STD_CALL_CONV :ptr IViewObject, :DWORD, :LONG, :ULONG_PTR, :ptr DVTARGETDEVICE, :ULONG_PTR, :ptr ptr LOGPALETTE
      ;* [out] *
      IViewObject_RemoteGetColorSet_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      IViewObject_RemoteFreeze_Proxy proto WIN_STD_CALL_CONV :ptr IViewObject, :DWORD, :LONG, :ULONG_PTR, :ptr DWORD
      ;* [out] *
      IViewObject_RemoteFreeze_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      IViewObject_RemoteGetAdvise_Proxy proto WIN_STD_CALL_CONV :ptr IViewObject, :ptr DWORD, :ptr DWORD, :ptr ptr IAdviseSink
      ;* [out] *
      IViewObject_RemoteGetAdvise_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __IViewObject_INTERFACE_DEFINED__ *
    endif
    ifndef __IViewObject2_INTERFACE_DEFINED__
      __IViewObject2_INTERFACE_DEFINED__ equ <>
      ;* interface IViewObject2 *
      ;* [uuid][object] *
      ;* [unique] *
      LPVIEWOBJECT2 typedef ptr IViewObject2
      externdef IID_IViewObject2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IViewObject2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IViewObject2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IViewObject2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IViewObject2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IViewObject2
          DECLSPEC_XFGVIRT(IViewObject, Draw)
          ;* [local] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][unique][in] *
          ;* [annotation][unique][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][unique][in] *
          ;* [annotation][in] *
          TYPE_Draw_pfnContinue typedef proto WIN_STD_CALL_CONV :ULONG_PTR
          PDraw_pfnContinue typedef ptr TYPEDraw_pfnContinue
          pfnContinue PDraw_pfnContinue ?
          ;* [annotation][in] *
          STD_METHOD Draw, :ptr IViewObject2, :DWORD, :LONG, :ptr, :ptr DVTARGETDEVICE, :HDC, :HDC, :LPCRECTL, :LPCRECTL, :, :ULONG_PTR
          DECLSPEC_XFGVIRT(IViewObject, GetColorSet)
          ;* [local] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][unique][in] *
          ;* [annotation][unique][in] *
          ;* [annotation][in] *
          ;* [annotation][out] *
          STD_METHOD GetColorSet, :ptr IViewObject2, :DWORD, :LONG, :ptr, :ptr DVTARGETDEVICE, :HDC, :ptr ptr LOGPALETTE
          DECLSPEC_XFGVIRT(IViewObject, Freeze)
          ;* [local] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][unique][in] *
          ;* [annotation][out] *
          STD_METHOD Freeze, :ptr IViewObject2, :DWORD, :LONG, :ptr, :ptr DWORD
          DECLSPEC_XFGVIRT(IViewObject, Unfreeze)
          STD_METHOD Unfreeze, :ptr IViewObject2, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IViewObject, SetAdvise)
          ;* [in] *
          ;* [in] *
          STD_METHOD SetAdvise, :ptr IViewObject2, :DWORD, :DWORD, :ptr IAdviseSink
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IViewObject, GetAdvise)
          ;* [local] *
          ;* [annotation][unique][out] *
          ;* [annotation][unique][out] *
          ;* [annotation][out] *
          STD_METHOD GetAdvise, :ptr IViewObject2, :ptr DWORD, :ptr DWORD, :ptr ptr IAdviseSink
          DECLSPEC_XFGVIRT(IViewObject2, GetExtent)
          ;* [in] *
          ;* [in] *
          ;* [unique][in] *
          STD_METHOD GetExtent, :ptr IViewObject2, :DWORD, :LONG, :ptr DVTARGETDEVICE, :LPSIZEL
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IViewObject2Vtbl ends
        IViewObject2 struct
          lpVtbl POINTER ?
        IViewObject2 ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IViewObject2_INTERFACE_DEFINED__ *
    endif
    ifndef __IDropSource_INTERFACE_DEFINED__
      __IDropSource_INTERFACE_DEFINED__ equ <>
      ;* interface IDropSource *
      ;* [uuid][object][local] *
      ;* [unique] *
      LPDROPSOURCE typedef ptr IDropSource
      externdef IID_IDropSource:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IDropSourceVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IDropSourceVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IDropSource, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IDropSource
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IDropSource
          DECLSPEC_XFGVIRT(IDropSource, QueryContinueDrag)
          ;* [annotation][in] *
          ;* [annotation][in] *
          STD_METHOD QueryContinueDrag, :ptr IDropSource, :BOOL, :DWORD
          DECLSPEC_XFGVIRT(IDropSource, GiveFeedback)
          ;* [annotation][in] *
          STD_METHOD GiveFeedback, :ptr IDropSource, :DWORD
          ??Interface equ <>
          END_INTERFACE
        IDropSourceVtbl ends
        IDropSource struct
          lpVtbl POINTER ?
        IDropSource ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IDropSource_INTERFACE_DEFINED__ *
    endif
    ifndef __IDropTarget_INTERFACE_DEFINED__
      __IDropTarget_INTERFACE_DEFINED__ equ <>
      ;* interface IDropTarget *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPDROPTARGET typedef ptr IDropTarget
      MK_ALT equ (20h)
      DROPEFFECT_NONE equ (0)
      DROPEFFECT_COPY equ (1)
      DROPEFFECT_MOVE equ (2)
      DROPEFFECT_LINK equ (4)
      DROPEFFECT_SCROLL equ (80000000h)
      ; default inset-width of the hot zone, in pixels
      ;   typical use: GetProfileInt("windows","DragScrollInset",DD_DEFSCROLLINSET)
      DD_DEFSCROLLINSET equ (11)
      ; default delay before scrolling, in milliseconds
      ;   typical use: GetProfileInt("windows","DragScrollDelay",DD_DEFSCROLLDELAY)
      DD_DEFSCROLLDELAY equ (50)
      ; default scroll interval, in milliseconds
      ;   typical use: GetProfileInt("windows","DragScrollInterval", DD_DEFSCROLLINTERVAL)
      DD_DEFSCROLLINTERVAL equ (50)
      ; default delay before dragging should start, in milliseconds
      ;   typical use: GetProfileInt("windows", "DragDelay", DD_DEFDRAGDELAY)
      DD_DEFDRAGDELAY equ (200)
      ; default minimum distance (radius) before dragging should start, in pixels
      ;   typical use: GetProfileInt("windows", "DragMinDist", DD_DEFDRAGMINDIST)
      DD_DEFDRAGMINDIST equ (2)
      externdef IID_IDropTarget:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IDropTargetVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IDropTargetVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IDropTarget, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IDropTarget
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IDropTarget
          DECLSPEC_XFGVIRT(IDropTarget, DragEnter)
          ;* [unique][in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD DragEnter, :ptr IDropTarget, :ptr IDataObject, :DWORD, :POINTL, :ptr DWORD
          ;* [out][in] *
          DECLSPEC_XFGVIRT(IDropTarget, DragOver)
          ;* [in] *
          ;* [in] *
          STD_METHOD DragOver, :ptr IDropTarget, :DWORD, :POINTL, :ptr DWORD
          ;* [out][in] *
          DECLSPEC_XFGVIRT(IDropTarget, DragLeave)
          STD_METHOD DragLeave, :ptr IDropTarget
          DECLSPEC_XFGVIRT(IDropTarget, Drop)
          ;* [unique][in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD Drop, :ptr IDropTarget, :ptr IDataObject, :DWORD, :POINTL, :ptr DWORD
          ;* [out][in] *
          ??Interface equ <>
          END_INTERFACE
        IDropTargetVtbl ends
        IDropTarget struct
          lpVtbl POINTER ?
        IDropTarget ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IDropTarget_INTERFACE_DEFINED__ *
    endif
    ifndef __IDropSourceNotify_INTERFACE_DEFINED__
      __IDropSourceNotify_INTERFACE_DEFINED__ equ <>
      ;* interface IDropSourceNotify *
      ;* [unique][uuid][object][local] *
      externdef IID_IDropSourceNotify:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IDropSourceNotifyVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IDropSourceNotifyVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IDropSourceNotify, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IDropSourceNotify
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IDropSourceNotify
          DECLSPEC_XFGVIRT(IDropSourceNotify, DragEnterTarget)
          ;* [annotation][in] *
          STD_METHOD DragEnterTarget, :ptr IDropSourceNotify, :HWND
          DECLSPEC_XFGVIRT(IDropSourceNotify, DragLeaveTarget)
          STD_METHOD DragLeaveTarget, :ptr IDropSourceNotify
          ??Interface equ <>
          END_INTERFACE
        IDropSourceNotifyVtbl ends
        IDropSourceNotify struct
          lpVtbl POINTER ?
        IDropSourceNotify ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IDropSourceNotify_INTERFACE_DEFINED__ *
    endif
    ifndef __IEnterpriseDropTarget_INTERFACE_DEFINED__
      __IEnterpriseDropTarget_INTERFACE_DEFINED__ equ <>
      ;* interface IEnterpriseDropTarget *
      ;* [unique][uuid][object] *
      externdef IID_IEnterpriseDropTarget:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IEnterpriseDropTargetVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IEnterpriseDropTargetVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IEnterpriseDropTarget, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IEnterpriseDropTarget
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IEnterpriseDropTarget
          DECLSPEC_XFGVIRT(IEnterpriseDropTarget, SetDropSourceEnterpriseId)
          STD_METHOD SetDropSourceEnterpriseId, :ptr IEnterpriseDropTarget, :LPCWSTR
          ;* [in] *
          DECLSPEC_XFGVIRT(IEnterpriseDropTarget, IsEvaluatingEdpPolicy)
          STD_METHOD IsEvaluatingEdpPolicy, :ptr IEnterpriseDropTarget, :ptr BOOL
          ;* [retval][out] *
          ??Interface equ <>
          END_INTERFACE
        IEnterpriseDropTargetVtbl ends
        IEnterpriseDropTarget struct
          lpVtbl POINTER ?
        IEnterpriseDropTarget ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IEnterpriseDropTarget_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_oleidl_0000_0024 *
    ;* [local] *
    CFSTR_ENTERPRISE_ID equ <(TEXT("EnterpriseDataProtectionId"))>
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    externdef __MIDL_itf_oleidl_0000_0024_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_oleidl_0000_0024_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IEnumOLEVERB_INTERFACE_DEFINED__
      __IEnumOLEVERB_INTERFACE_DEFINED__ equ <>
      ;* interface IEnumOLEVERB *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPENUMOLEVERB typedef ptr IEnumOLEVERB
      OLEVERB struct
        lVerb SDWORD ?
        lpszVerbName LPOLESTR ?
        fuFlags DWORD ?
        grfAttribs DWORD ?
      OLEVERB ends
      tagOLEVERB typedef OLEVERB
      LPOLEVERB typedef ptr tagOLEVERB
      ;* [v1_enum] *
      OLEVERBATTRIB typedef SDWORD
      OLEVERBATTRIB_NEVERDIRTIES equ 1
      OLEVERBATTRIB_ONCONTAINERMENU equ 2
      tagOLEVERBATTRIB typedef OLEVERBATTRIB

      externdef IID_IEnumOLEVERB:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IEnumOLEVERBVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IEnumOLEVERBVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IEnumOLEVERB, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IEnumOLEVERB
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IEnumOLEVERB
          DECLSPEC_XFGVIRT(IEnumOLEVERB, Next)
          ;* [local] *
          ;* [annotation][in] *
          ;* [annotation][length_is][size_is][out] *
          ;* [annotation][out] *
          STD_METHOD Next, :ptr IEnumOLEVERB, :ULONG, :LPOLEVERB, :ptr ULONG
          DECLSPEC_XFGVIRT(IEnumOLEVERB, Skip)
          STD_METHOD Skip, :ptr IEnumOLEVERB, :ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(IEnumOLEVERB, Reset)
          STD_METHOD Reset, :ptr IEnumOLEVERB
          DECLSPEC_XFGVIRT(IEnumOLEVERB, Clone)
          STD_METHOD Clone, :ptr IEnumOLEVERB, :ptr ptr IEnumOLEVERB
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IEnumOLEVERBVtbl ends
        IEnumOLEVERB struct
          lpVtbl POINTER ?
        IEnumOLEVERB ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      IEnumOLEVERB_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumOLEVERB, :ULONG, :LPOLEVERB, :ptr ULONG
      ;* [out] *
      IEnumOLEVERB_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __IEnumOLEVERB_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_oleidl_0000_0025 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  if _MSC_VER ge 1200
  endif
  externdef __MIDL_itf_oleidl_0000_0025_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_oleidl_0000_0025_v0_0_s_ifspec:RPC_IF_HANDLE
  ;* Additional Prototypes for ALL interfaces *
  CLIPFORMAT_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr CLIPFORMAT
  CLIPFORMAT_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr CLIPFORMAT
  CLIPFORMAT_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr CLIPFORMAT
  CLIPFORMAT_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr CLIPFORMAT
  HACCEL_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HACCEL
  HACCEL_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HACCEL
  HACCEL_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HACCEL
  HACCEL_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HACCEL
  HDC_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HDC
  HDC_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HDC
  HDC_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HDC
  HDC_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HDC
  HGLOBAL_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HGLOBAL
  HGLOBAL_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HGLOBAL
  HGLOBAL_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HGLOBAL
  HGLOBAL_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HGLOBAL
  HMENU_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HMENU
  HMENU_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HMENU
  HMENU_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HMENU
  HMENU_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HMENU
  HWND_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HWND
  HWND_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HWND
  HWND_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HWND
  HWND_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HWND
  STGMEDIUM_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr STGMEDIUM
  STGMEDIUM_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr STGMEDIUM
  STGMEDIUM_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr STGMEDIUM
  STGMEDIUM_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr STGMEDIUM
  CLIPFORMAT_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr CLIPFORMAT
  CLIPFORMAT_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr CLIPFORMAT
  CLIPFORMAT_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr CLIPFORMAT
  CLIPFORMAT_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr CLIPFORMAT
  HACCEL_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HACCEL
  HACCEL_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HACCEL
  HACCEL_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HACCEL
  HACCEL_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HACCEL
  HDC_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HDC
  HDC_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HDC
  HDC_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HDC
  HDC_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HDC
  HGLOBAL_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HGLOBAL
  HGLOBAL_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HGLOBAL
  HGLOBAL_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HGLOBAL
  HGLOBAL_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HGLOBAL
  HMENU_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HMENU
  HMENU_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HMENU
  HMENU_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HMENU
  HMENU_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HMENU
  HWND_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HWND
  HWND_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HWND
  HWND_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HWND
  HWND_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HWND
  STGMEDIUM_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr STGMEDIUM
  STGMEDIUM_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr STGMEDIUM
  STGMEDIUM_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr STGMEDIUM
  STGMEDIUM_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr STGMEDIUM
  ;* [local] *
  IOleCache2_UpdateCache_Proxy proto WIN_STD_CALL_CONV :ptr IOleCache2, :LPDATAOBJECT, :DWORD, :LPVOID
  ;* [annotation][in] *
  ;* [call_as] *
  IOleCache2_UpdateCache_Stub proto WIN_STD_CALL_CONV :ptr IOleCache2, :LPDATAOBJECT, :DWORD, :LONG_PTR
  ;* [in] *
  ;* [local] *
  IOleInPlaceActiveObject_TranslateAccelerator_Proxy proto WIN_STD_CALL_CONV :ptr IOleInPlaceActiveObject, :LPMSG
  ;* [annotation][in] *
  ;* [call_as] *
  IOleInPlaceActiveObject_TranslateAccelerator_Stub proto WIN_STD_CALL_CONV :ptr IOleInPlaceActiveObject
  ;* [local] *
  IOleInPlaceActiveObject_ResizeBorder_Proxy proto WIN_STD_CALL_CONV :ptr IOleInPlaceActiveObject, :LPCRECT, :ptr IOleInPlaceUIWindow, :BOOL
  ;* [annotation][in] *
  ;* [input_sync][call_as] *
  IOleInPlaceActiveObject_ResizeBorder_Stub proto WIN_STD_CALL_CONV :ptr IOleInPlaceActiveObject, :LPCRECT, :REFIID, :ptr IOleInPlaceUIWindow, :BOOL
  ;* [in] *
  ;* [local] *
  IViewObject_Draw_Proxy proto WIN_STD_CALL_CONV :ptr IViewObject, :DWORD, :LONG, :ptr, :ptr DVTARGETDEVICE, :HDC, :HDC, :LPCRECTL, :LPCRECTL, :POINTER, :ULONG_PTR
  ;* [annotation][in] *
  ;* [call_as] *
  IViewObject_Draw_Stub proto WIN_STD_CALL_CONV :ptr IViewObject, :DWORD, :LONG, :ULONG_PTR, :ptr DVTARGETDEVICE, :HDC, :HDC, :LPCRECTL, :LPCRECTL, :ptr IContinue
  ;* [in] *
  ;* [local] *
  IViewObject_GetColorSet_Proxy proto WIN_STD_CALL_CONV :ptr IViewObject, :DWORD, :LONG, :ptr, :ptr DVTARGETDEVICE, :HDC, :ptr ptr LOGPALETTE
  ;* [annotation][out] *
  ;* [call_as] *
  IViewObject_GetColorSet_Stub proto WIN_STD_CALL_CONV :ptr IViewObject, :DWORD, :LONG, :ULONG_PTR, :ptr DVTARGETDEVICE, :ULONG_PTR, :ptr ptr LOGPALETTE
  ;* [out] *
  ;* [local] *
  IViewObject_Freeze_Proxy proto WIN_STD_CALL_CONV :ptr IViewObject, :DWORD, :LONG, :ptr, :ptr DWORD
  ;* [annotation][out] *
  ;* [call_as] *
  IViewObject_Freeze_Stub proto WIN_STD_CALL_CONV :ptr IViewObject, :DWORD, :LONG, :ULONG_PTR, :ptr DWORD
  ;* [out] *
  ;* [local] *
  IViewObject_GetAdvise_Proxy proto WIN_STD_CALL_CONV :ptr IViewObject, :ptr DWORD, :ptr DWORD, :ptr ptr IAdviseSink
  ;* [annotation][out] *
  ;* [call_as] *
  IViewObject_GetAdvise_Stub proto WIN_STD_CALL_CONV :ptr IViewObject, :ptr DWORD, :ptr DWORD, :ptr ptr IAdviseSink
  ;* [out] *
  ;* [local] *
  IEnumOLEVERB_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumOLEVERB, :ULONG, :LPOLEVERB, :ptr ULONG
  ;* [annotation][out] *
  ;* [call_as] *
  IEnumOLEVERB_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumOLEVERB, :ULONG, :LPOLEVERB, :ptr ULONG
  ;* [out] *
  ;* end of Additional Prototypes *
  ifdef __cplusplus
    ;[...]
  endif
endif
