;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\ocidl.h
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
ifndef __ocidl_h__
  __ocidl_h__ equ <>
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
  ifndef __IEnumConnections_FWD_DEFINED__
    __IEnumConnections_FWD_DEFINED__ equ <>
    ;* __IEnumConnections_FWD_DEFINED__ *
  endif
  ifndef __IConnectionPoint_FWD_DEFINED__
    __IConnectionPoint_FWD_DEFINED__ equ <>
    ;* __IConnectionPoint_FWD_DEFINED__ *
  endif
  ifndef __IEnumConnectionPoints_FWD_DEFINED__
    __IEnumConnectionPoints_FWD_DEFINED__ equ <>
    ;* __IEnumConnectionPoints_FWD_DEFINED__ *
  endif
  ifndef __IConnectionPointContainer_FWD_DEFINED__
    __IConnectionPointContainer_FWD_DEFINED__ equ <>
    ;* __IConnectionPointContainer_FWD_DEFINED__ *
  endif
  ifndef __IClassFactory2_FWD_DEFINED__
    __IClassFactory2_FWD_DEFINED__ equ <>
    ;* __IClassFactory2_FWD_DEFINED__ *
  endif
  ifndef __IProvideClassInfo_FWD_DEFINED__
    __IProvideClassInfo_FWD_DEFINED__ equ <>
    ;* __IProvideClassInfo_FWD_DEFINED__ *
  endif
  ifndef __IProvideClassInfo2_FWD_DEFINED__
    __IProvideClassInfo2_FWD_DEFINED__ equ <>
    ;* __IProvideClassInfo2_FWD_DEFINED__ *
  endif
  ifndef __IProvideMultipleClassInfo_FWD_DEFINED__
    __IProvideMultipleClassInfo_FWD_DEFINED__ equ <>
    ;* __IProvideMultipleClassInfo_FWD_DEFINED__ *
  endif
  ifndef __IOleControl_FWD_DEFINED__
    __IOleControl_FWD_DEFINED__ equ <>
    ;* __IOleControl_FWD_DEFINED__ *
  endif
  ifndef __IOleControlSite_FWD_DEFINED__
    __IOleControlSite_FWD_DEFINED__ equ <>
    ;* __IOleControlSite_FWD_DEFINED__ *
  endif
  ifndef __IPropertyPage_FWD_DEFINED__
    __IPropertyPage_FWD_DEFINED__ equ <>
    ;* __IPropertyPage_FWD_DEFINED__ *
  endif
  ifndef __IPropertyPage2_FWD_DEFINED__
    __IPropertyPage2_FWD_DEFINED__ equ <>
    ;* __IPropertyPage2_FWD_DEFINED__ *
  endif
  ifndef __IPropertyPageSite_FWD_DEFINED__
    __IPropertyPageSite_FWD_DEFINED__ equ <>
    ;* __IPropertyPageSite_FWD_DEFINED__ *
  endif
  ifndef __IPropertyNotifySink_FWD_DEFINED__
    __IPropertyNotifySink_FWD_DEFINED__ equ <>
    ;* __IPropertyNotifySink_FWD_DEFINED__ *
  endif
  ifndef __ISpecifyPropertyPages_FWD_DEFINED__
    __ISpecifyPropertyPages_FWD_DEFINED__ equ <>
    ;* __ISpecifyPropertyPages_FWD_DEFINED__ *
  endif
  ifndef __IPersistMemory_FWD_DEFINED__
    __IPersistMemory_FWD_DEFINED__ equ <>
    ;* __IPersistMemory_FWD_DEFINED__ *
  endif
  ifndef __IPersistStreamInit_FWD_DEFINED__
    __IPersistStreamInit_FWD_DEFINED__ equ <>
    ;* __IPersistStreamInit_FWD_DEFINED__ *
  endif
  ifndef __IPersistPropertyBag_FWD_DEFINED__
    __IPersistPropertyBag_FWD_DEFINED__ equ <>
    ;* __IPersistPropertyBag_FWD_DEFINED__ *
  endif
  ifndef __ISimpleFrameSite_FWD_DEFINED__
    __ISimpleFrameSite_FWD_DEFINED__ equ <>
    ;* __ISimpleFrameSite_FWD_DEFINED__ *
  endif
  ifndef __IFont_FWD_DEFINED__
    __IFont_FWD_DEFINED__ equ <>
    ;* __IFont_FWD_DEFINED__ *
  endif
  ifndef __IPicture_FWD_DEFINED__
    __IPicture_FWD_DEFINED__ equ <>
    ;* __IPicture_FWD_DEFINED__ *
  endif
  ifndef __IPicture2_FWD_DEFINED__
    __IPicture2_FWD_DEFINED__ equ <>
    ;* __IPicture2_FWD_DEFINED__ *
  endif
  ifndef __IFontEventsDisp_FWD_DEFINED__
    __IFontEventsDisp_FWD_DEFINED__ equ <>
    ;* __IFontEventsDisp_FWD_DEFINED__ *
  endif
  ifndef __IFontDisp_FWD_DEFINED__
    __IFontDisp_FWD_DEFINED__ equ <>
    ;* __IFontDisp_FWD_DEFINED__ *
  endif
  ifndef __IPictureDisp_FWD_DEFINED__
    __IPictureDisp_FWD_DEFINED__ equ <>
    ;* __IPictureDisp_FWD_DEFINED__ *
  endif
  ifndef __IOleInPlaceObjectWindowless_FWD_DEFINED__
    __IOleInPlaceObjectWindowless_FWD_DEFINED__ equ <>
    ;* __IOleInPlaceObjectWindowless_FWD_DEFINED__ *
  endif
  ifndef __IOleInPlaceSiteEx_FWD_DEFINED__
    __IOleInPlaceSiteEx_FWD_DEFINED__ equ <>
    ;* __IOleInPlaceSiteEx_FWD_DEFINED__ *
  endif
  ifndef __IOleInPlaceSiteWindowless_FWD_DEFINED__
    __IOleInPlaceSiteWindowless_FWD_DEFINED__ equ <>
    ;* __IOleInPlaceSiteWindowless_FWD_DEFINED__ *
  endif
  ifndef __IViewObjectEx_FWD_DEFINED__
    __IViewObjectEx_FWD_DEFINED__ equ <>
    ;* __IViewObjectEx_FWD_DEFINED__ *
  endif
  ifndef __IOleUndoUnit_FWD_DEFINED__
    __IOleUndoUnit_FWD_DEFINED__ equ <>
    ;* __IOleUndoUnit_FWD_DEFINED__ *
  endif
  ifndef __IOleParentUndoUnit_FWD_DEFINED__
    __IOleParentUndoUnit_FWD_DEFINED__ equ <>
    ;* __IOleParentUndoUnit_FWD_DEFINED__ *
  endif
  ifndef __IEnumOleUndoUnits_FWD_DEFINED__
    __IEnumOleUndoUnits_FWD_DEFINED__ equ <>
    ;* __IEnumOleUndoUnits_FWD_DEFINED__ *
  endif
  ifndef __IOleUndoManager_FWD_DEFINED__
    __IOleUndoManager_FWD_DEFINED__ equ <>
    ;* __IOleUndoManager_FWD_DEFINED__ *
  endif
  ifndef __IPointerInactive_FWD_DEFINED__
    __IPointerInactive_FWD_DEFINED__ equ <>
    ;* __IPointerInactive_FWD_DEFINED__ *
  endif
  ifndef __IObjectWithSite_FWD_DEFINED__
    __IObjectWithSite_FWD_DEFINED__ equ <>
    ;* __IObjectWithSite_FWD_DEFINED__ *
  endif
  ifndef __IPerPropertyBrowsing_FWD_DEFINED__
    __IPerPropertyBrowsing_FWD_DEFINED__ equ <>
    ;* __IPerPropertyBrowsing_FWD_DEFINED__ *
  endif
  ifndef __IPropertyBag2_FWD_DEFINED__
    __IPropertyBag2_FWD_DEFINED__ equ <>
    ;* __IPropertyBag2_FWD_DEFINED__ *
  endif
  ifndef __IPersistPropertyBag2_FWD_DEFINED__
    __IPersistPropertyBag2_FWD_DEFINED__ equ <>
    ;* __IPersistPropertyBag2_FWD_DEFINED__ *
  endif
  ifndef __IAdviseSinkEx_FWD_DEFINED__
    __IAdviseSinkEx_FWD_DEFINED__ equ <>
    ;* __IAdviseSinkEx_FWD_DEFINED__ *
  endif
  ifndef __IQuickActivate_FWD_DEFINED__
    __IQuickActivate_FWD_DEFINED__ equ <>
    ;* __IQuickActivate_FWD_DEFINED__ *
  endif
  ;* header files for imported files *
  include oleidl.inc
  include oaidl.inc
  include servprov.inc
  include urlmon.inc
  ifdef __cplusplus
    ;[...]
  endif
  ;* interface __MIDL_itf_ocidl_0000_0000 *
  ;* [local] *
  include winapifamily.inc
  ;+-------------------------------------------------------------------------
  ;  Microsoft Windows
  ;  Copyright (c) Microsoft Corporation. All rights reserved.
  ;--------------------------------------------------------------------------
  if (_MSC_VER ge 1020)
  endif
  if _MSC_VER ge 1200
    ;* padding added after data member *
    ;* a GUID can only be associated with a class, interface or namespace *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_ocidl_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_ocidl_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IOleControlTypes_INTERFACE_DEFINED__
      __IOleControlTypes_INTERFACE_DEFINED__ equ <>
      ;* interface IOleControlTypes *
      ;* [unique][version] *
      ;* [v1_enum] *
      UASFLAGS typedef SDWORD
      UAS_NORMAL equ 0
      UAS_BLOCKED equ 1h
      UAS_NOPARENTENABLE equ 2h
      UAS_MASK equ 3h
      tagUASFLAGS typedef UASFLAGS

      ;* State values for the DISPID_READYSTATE property *
      ;* [v1_enum] *
      READYSTATE typedef SDWORD
      READYSTATE_UNINITIALIZED equ 0
      READYSTATE_LOADING equ 1
      READYSTATE_LOADED equ 2
      READYSTATE_INTERACTIVE equ 3
      READYSTATE_COMPLETE equ 4
      tagREADYSTATE typedef READYSTATE

      externdef IOleControlTypes_v1_0_c_ifspec:RPC_IF_HANDLE
      externdef IOleControlTypes_v1_0_s_ifspec:RPC_IF_HANDLE
      ;* __IOleControlTypes_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_ocidl_0000_0001 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    externdef __MIDL_itf_ocidl_0000_0001_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_ocidl_0000_0001_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IEnumConnections_INTERFACE_DEFINED__
      __IEnumConnections_INTERFACE_DEFINED__ equ <>
      ;* interface IEnumConnections *
      ;* [unique][uuid][object] *
      PENUMCONNECTIONS typedef ptr IEnumConnections
      LPENUMCONNECTIONS typedef ptr IEnumConnections
      CONNECTDATA struct
        pUnk POINTER ?
        dwCookie DWORD ?
      CONNECTDATA ends
      tagCONNECTDATA typedef CONNECTDATA
      PCONNECTDATA typedef ptr tagCONNECTDATA
      LPCONNECTDATA typedef ptr tagCONNECTDATA
      externdef IID_IEnumConnections:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IEnumConnectionsVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IEnumConnectionsVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IEnumConnections, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IEnumConnections
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IEnumConnections
          DECLSPEC_XFGVIRT(IEnumConnections, Next)
          ;* [local] *
          ;* [in] *
          ;* [length_is][size_is][out] *
          STD_METHOD Next, :ptr IEnumConnections, :ULONG, :LPCONNECTDATA, :ptr ULONG
          ;* [out] *
          DECLSPEC_XFGVIRT(IEnumConnections, Skip)
          STD_METHOD Skip, :ptr IEnumConnections, :ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(IEnumConnections, Reset)
          STD_METHOD Reset, :ptr IEnumConnections
          DECLSPEC_XFGVIRT(IEnumConnections, Clone)
          STD_METHOD Clone, :ptr IEnumConnections, :ptr ptr IEnumConnections
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IEnumConnectionsVtbl ends
        IEnumConnections struct
          lpVtbl POINTER ?
        IEnumConnections ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      IEnumConnections_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumConnections, :ULONG, :LPCONNECTDATA, :ptr ULONG
      ;* [out] *
      IEnumConnections_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __IEnumConnections_INTERFACE_DEFINED__ *
    endif
    ifndef __IConnectionPoint_INTERFACE_DEFINED__
      __IConnectionPoint_INTERFACE_DEFINED__ equ <>
      ;* interface IConnectionPoint *
      ;* [unique][uuid][object] *
      PCONNECTIONPOINT typedef ptr IConnectionPoint
      LPCONNECTIONPOINT typedef ptr IConnectionPoint
      externdef IID_IConnectionPoint:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IConnectionPointVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IConnectionPointVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IConnectionPoint, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IConnectionPoint
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IConnectionPoint
          DECLSPEC_XFGVIRT(IConnectionPoint, GetConnectionInterface)
          STD_METHOD GetConnectionInterface, :ptr IConnectionPoint, :ptr IID
          ;* [out] *
          DECLSPEC_XFGVIRT(IConnectionPoint, GetConnectionPointContainer)
          STD_METHOD GetConnectionPointContainer, :ptr IConnectionPoint, :ptr ptr IConnectionPointContainer
          ;* [out] *
          DECLSPEC_XFGVIRT(IConnectionPoint, Advise)
          ;* [in] *
          STD_METHOD Advise, :ptr IConnectionPoint, :ptr IUnknown, :ptr DWORD
          ;* [out] *
          DECLSPEC_XFGVIRT(IConnectionPoint, Unadvise)
          STD_METHOD Unadvise, :ptr IConnectionPoint, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IConnectionPoint, EnumConnections)
          STD_METHOD EnumConnections, :ptr IConnectionPoint, :ptr ptr IEnumConnections
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IConnectionPointVtbl ends
        IConnectionPoint struct
          lpVtbl POINTER ?
        IConnectionPoint ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IConnectionPoint_INTERFACE_DEFINED__ *
    endif
    ifndef __IEnumConnectionPoints_INTERFACE_DEFINED__
      __IEnumConnectionPoints_INTERFACE_DEFINED__ equ <>
      ;* interface IEnumConnectionPoints *
      ;* [unique][uuid][object] *
      PENUMCONNECTIONPOINTS typedef ptr IEnumConnectionPoints
      LPENUMCONNECTIONPOINTS typedef ptr IEnumConnectionPoints
      externdef IID_IEnumConnectionPoints:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IEnumConnectionPointsVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IEnumConnectionPointsVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IEnumConnectionPoints, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IEnumConnectionPoints
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IEnumConnectionPoints
          DECLSPEC_XFGVIRT(IEnumConnectionPoints, Next)
          ;* [local] *
          ;* [in] *
          ;* [length_is][size_is][out] *
          STD_METHOD Next, :ptr IEnumConnectionPoints, :ULONG, :ptr LPCONNECTIONPOINT, :ptr ULONG
          ;* [out] *
          DECLSPEC_XFGVIRT(IEnumConnectionPoints, Skip)
          STD_METHOD Skip, :ptr IEnumConnectionPoints, :ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(IEnumConnectionPoints, Reset)
          STD_METHOD Reset, :ptr IEnumConnectionPoints
          DECLSPEC_XFGVIRT(IEnumConnectionPoints, Clone)
          STD_METHOD Clone, :ptr IEnumConnectionPoints, :ptr ptr IEnumConnectionPoints
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IEnumConnectionPointsVtbl ends
        IEnumConnectionPoints struct
          lpVtbl POINTER ?
        IEnumConnectionPoints ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      IEnumConnectionPoints_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumConnectionPoints, :ULONG, :ptr LPCONNECTIONPOINT, :ptr ULONG
      ;* [out] *
      IEnumConnectionPoints_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __IEnumConnectionPoints_INTERFACE_DEFINED__ *
    endif
    ifndef __IConnectionPointContainer_INTERFACE_DEFINED__
      __IConnectionPointContainer_INTERFACE_DEFINED__ equ <>
      ;* interface IConnectionPointContainer *
      ;* [unique][uuid][object] *
      PCONNECTIONPOINTCONTAINER typedef ptr IConnectionPointContainer
      LPCONNECTIONPOINTCONTAINER typedef ptr IConnectionPointContainer
      externdef IID_IConnectionPointContainer:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IConnectionPointContainerVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IConnectionPointContainerVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IConnectionPointContainer, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IConnectionPointContainer
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IConnectionPointContainer
          DECLSPEC_XFGVIRT(IConnectionPointContainer, EnumConnectionPoints)
          STD_METHOD EnumConnectionPoints, :ptr IConnectionPointContainer, :ptr ptr IEnumConnectionPoints
          ;* [out] *
          DECLSPEC_XFGVIRT(IConnectionPointContainer, FindConnectionPoint)
          ;* [in] *
          STD_METHOD FindConnectionPoint, :ptr IConnectionPointContainer, :REFIID, :ptr ptr IConnectionPoint
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IConnectionPointContainerVtbl ends
        IConnectionPointContainer struct
          lpVtbl POINTER ?
        IConnectionPointContainer ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IConnectionPointContainer_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_ocidl_0000_0005 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_ocidl_0000_0005_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_ocidl_0000_0005_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IClassFactory2_INTERFACE_DEFINED__
      __IClassFactory2_INTERFACE_DEFINED__ equ <>
      ;* interface IClassFactory2 *
      ;* [unique][uuid][object] *
      LPCLASSFACTORY2 typedef ptr IClassFactory2
      LICINFO struct
        cbLicInfo SDWORD ?
        fRuntimeKeyAvail DWORD ?
        fLicVerified DWORD ?
      LICINFO ends
      tagLICINFO typedef LICINFO
      LPLICINFO typedef ptr tagLICINFO
      externdef IID_IClassFactory2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IClassFactory2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IClassFactory2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IClassFactory2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IClassFactory2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IClassFactory2
          DECLSPEC_XFGVIRT(IClassFactory, CreateInstance)
          ;* [local] *
          ;* [annotation][unique][in] *
          ;* [annotation][in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD CreateInstance, :ptr IClassFactory2, :ptr IUnknown, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IClassFactory, LockServer)
          ;* [local] *
          STD_METHOD LockServer, :ptr IClassFactory2, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IClassFactory2, GetLicInfo)
          STD_METHOD GetLicInfo, :ptr IClassFactory2, :ptr LICINFO
          ;* [out][in] *
          DECLSPEC_XFGVIRT(IClassFactory2, RequestLicKey)
          ;* [in] *
          STD_METHOD RequestLicKey, :ptr IClassFactory2, :DWORD, :ptr BSTR
          ;* [out] *
          DECLSPEC_XFGVIRT(IClassFactory2, CreateInstanceLic)
          ;* [local] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD CreateInstanceLic, :ptr IClassFactory2, :ptr IUnknown, :ptr IUnknown, :REFIID, :BSTR, :ptr PVOID
          ??Interface equ <>
          END_INTERFACE
        IClassFactory2Vtbl ends
        IClassFactory2 struct
          lpVtbl POINTER ?
        IClassFactory2 ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      IClassFactory2_RemoteCreateInstanceLic_Proxy proto WIN_STD_CALL_CONV :ptr IClassFactory2, :REFIID, :BSTR, :ptr ptr IUnknown
      ;* [iid_is][out] *
      IClassFactory2_RemoteCreateInstanceLic_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __IClassFactory2_INTERFACE_DEFINED__ *
    endif
    ifndef __IProvideClassInfo_INTERFACE_DEFINED__
      __IProvideClassInfo_INTERFACE_DEFINED__ equ <>
      ;* interface IProvideClassInfo *
      ;* [unique][uuid][object] *
      LPPROVIDECLASSINFO typedef ptr IProvideClassInfo
      externdef IID_IProvideClassInfo:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IProvideClassInfoVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IProvideClassInfoVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IProvideClassInfo, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IProvideClassInfo
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IProvideClassInfo
          DECLSPEC_XFGVIRT(IProvideClassInfo, GetClassInfo)
          STD_METHOD GetClassInfo, :ptr IProvideClassInfo, :ptr ptr ITypeInfo
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IProvideClassInfoVtbl ends
        IProvideClassInfo struct
          lpVtbl POINTER ?
        IProvideClassInfo ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IProvideClassInfo_INTERFACE_DEFINED__ *
    endif
    ifndef __IProvideClassInfo2_INTERFACE_DEFINED__
      __IProvideClassInfo2_INTERFACE_DEFINED__ equ <>
      ;* interface IProvideClassInfo2 *
      ;* [unique][uuid][object] *
      LPPROVIDECLASSINFO2 typedef ptr IProvideClassInfo2
      GUIDKIND typedef SDWORD
      GUIDKIND_DEFAULT_SOURCE_DISP_IID equ 1
      tagGUIDKIND typedef GUIDKIND

      externdef IID_IProvideClassInfo2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IProvideClassInfo2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IProvideClassInfo2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IProvideClassInfo2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IProvideClassInfo2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IProvideClassInfo2
          DECLSPEC_XFGVIRT(IProvideClassInfo, GetClassInfo)
          STD_METHOD GetClassInfo, :ptr IProvideClassInfo2, :ptr ptr ITypeInfo
          ;* [out] *
          DECLSPEC_XFGVIRT(IProvideClassInfo2, GetGUID)
          ;* [in] *
          STD_METHOD GetGUID, :ptr IProvideClassInfo2, :DWORD, :ptr GUID
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IProvideClassInfo2Vtbl ends
        IProvideClassInfo2 struct
          lpVtbl POINTER ?
        IProvideClassInfo2 ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IProvideClassInfo2_INTERFACE_DEFINED__ *
    endif
    ifndef __IProvideMultipleClassInfo_INTERFACE_DEFINED__
      __IProvideMultipleClassInfo_INTERFACE_DEFINED__ equ <>
      ;* interface IProvideMultipleClassInfo *
      ;* [unique][uuid][object] *
      MULTICLASSINFO_GETTYPEINFO equ 00000001h
      MULTICLASSINFO_GETNUMRESERVEDDISPIDS equ 00000002h
      MULTICLASSINFO_GETIIDPRIMARY equ 00000004h
      MULTICLASSINFO_GETIIDSOURCE equ 00000008h
      TIFLAGS_EXTENDDISPATCHONLY equ 00000001h
      LPPROVIDEMULTIPLECLASSINFO typedef ptr IProvideMultipleClassInfo
      externdef IID_IProvideMultipleClassInfo:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IProvideMultipleClassInfoVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IProvideMultipleClassInfoVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IProvideMultipleClassInfo, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IProvideMultipleClassInfo
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IProvideMultipleClassInfo
          DECLSPEC_XFGVIRT(IProvideClassInfo, GetClassInfo)
          STD_METHOD GetClassInfo, :ptr IProvideMultipleClassInfo, :ptr ptr ITypeInfo
          ;* [out] *
          DECLSPEC_XFGVIRT(IProvideClassInfo2, GetGUID)
          ;* [in] *
          STD_METHOD GetGUID, :ptr IProvideMultipleClassInfo, :DWORD, :ptr GUID
          ;* [out] *
          DECLSPEC_XFGVIRT(IProvideMultipleClassInfo, GetMultiTypeInfoCount)
          STD_METHOD GetMultiTypeInfoCount, :ptr IProvideMultipleClassInfo, :ptr ULONG
          ;* [out] *
          DECLSPEC_XFGVIRT(IProvideMultipleClassInfo, GetInfoOfIndex)
          ;* [in] *
          ;* [in] *
          ;* [out] *
          ;* [out] *
          ;* [out] *
          ;* [out] *
          STD_METHOD GetInfoOfIndex, :ptr IProvideMultipleClassInfo, :ULONG, :DWORD, :ptr ptr ITypeInfo, :ptr DWORD, :ptr ULONG, :ptr IID, :ptr IID
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IProvideMultipleClassInfoVtbl ends
        IProvideMultipleClassInfo struct
          lpVtbl POINTER ?
        IProvideMultipleClassInfo ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IProvideMultipleClassInfo_INTERFACE_DEFINED__ *
    endif
    ifndef __IOleControl_INTERFACE_DEFINED__
      __IOleControl_INTERFACE_DEFINED__ equ <>
      ;* interface IOleControl *
      ;* [unique][uuid][object] *
      LPOLECONTROL typedef ptr IOleControl
      CONTROLINFO struct
        cb DWORD ?
        hAccel HACCEL ?
        cAccel WORD ?
        dwFlags DWORD ?
      CONTROLINFO ends
      tagCONTROLINFO typedef CONTROLINFO
      LPCONTROLINFO typedef ptr tagCONTROLINFO
      CTRLINFO typedef SDWORD
      CTRLINFO_EATS_RETURN equ 1
      CTRLINFO_EATS_ESCAPE equ 2
      tagCTRLINFO typedef CTRLINFO

      externdef IID_IOleControl:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IOleControlVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IOleControlVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IOleControl, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IOleControl
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IOleControl
          DECLSPEC_XFGVIRT(IOleControl, GetControlInfo)
          STD_METHOD GetControlInfo, :ptr IOleControl, :ptr CONTROLINFO
          ;* [out][in] *
          DECLSPEC_XFGVIRT(IOleControl, OnMnemonic)
          STD_METHOD OnMnemonic, :ptr IOleControl, :ptr MSG
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleControl, OnAmbientPropertyChange)
          STD_METHOD OnAmbientPropertyChange, :ptr IOleControl, :DISPID
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleControl, FreezeEvents)
          STD_METHOD FreezeEvents, :ptr IOleControl, :BOOL
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IOleControlVtbl ends
        IOleControl struct
          lpVtbl POINTER ?
        IOleControl ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IOleControl_INTERFACE_DEFINED__ *
    endif
    ifndef __IOleControlSite_INTERFACE_DEFINED__
      __IOleControlSite_INTERFACE_DEFINED__ equ <>
      ;* interface IOleControlSite *
      ;* [unique][uuid][object] *
      LPOLECONTROLSITE typedef ptr IOleControlSite
      POINTF struct
        x REAL4 ?
        y REAL4 ?
      POINTF ends
      tagPOINTF typedef POINTF
      LPPOINTF typedef ptr tagPOINTF
      XFORMCOORDS typedef SDWORD
      XFORMCOORDS_POSITION equ 1h
      XFORMCOORDS_SIZE equ 2h
      XFORMCOORDS_HIMETRICTOCONTAINER equ 4h
      XFORMCOORDS_CONTAINERTOHIMETRIC equ 8h
      XFORMCOORDS_EVENTCOMPAT equ 10h
      tagXFORMCOORDS typedef XFORMCOORDS

      externdef IID_IOleControlSite:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IOleControlSiteVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IOleControlSiteVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IOleControlSite, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IOleControlSite
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IOleControlSite
          DECLSPEC_XFGVIRT(IOleControlSite, OnControlInfoChanged)
          STD_METHOD OnControlInfoChanged, :ptr IOleControlSite
          DECLSPEC_XFGVIRT(IOleControlSite, LockInPlaceActive)
          STD_METHOD LockInPlaceActive, :ptr IOleControlSite, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleControlSite, GetExtendedControl)
          STD_METHOD GetExtendedControl, :ptr IOleControlSite, :ptr ptr IDispatch
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleControlSite, TransformCoords)
          ;* [out][in] *
          ;* [out][in] *
          STD_METHOD TransformCoords, :ptr IOleControlSite, :ptr POINTL, :ptr POINTF, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleControlSite, TranslateAccelerator)
          ;* [in] *
          STD_METHOD TranslateAccelerator, :ptr IOleControlSite, :ptr MSG, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleControlSite, OnFocus)
          STD_METHOD OnFocus, :ptr IOleControlSite, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleControlSite, ShowPropertyFrame)
          STD_METHOD ShowPropertyFrame, :ptr IOleControlSite
          ??Interface equ <>
          END_INTERFACE
        IOleControlSiteVtbl ends
        IOleControlSite struct
          lpVtbl POINTER ?
        IOleControlSite ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IOleControlSite_INTERFACE_DEFINED__ *
    endif
    ifndef __IPropertyPage_INTERFACE_DEFINED__
      __IPropertyPage_INTERFACE_DEFINED__ equ <>
      ;* interface IPropertyPage *
      ;* [unique][uuid][object] *
      LPPROPERTYPAGE typedef ptr IPropertyPage
      PROPPAGEINFO struct
        cb DWORD ?
        pszTitle LPOLESTR ?
        size_ SIZE_ ?
        pszDocString LPOLESTR ?
        pszHelpFile LPOLESTR ?
        dwHelpContext DWORD ?
      PROPPAGEINFO ends
      tagPROPPAGEINFO typedef PROPPAGEINFO
      LPPROPPAGEINFO typedef ptr tagPROPPAGEINFO
      externdef IID_IPropertyPage:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPropertyPageVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPropertyPageVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IPropertyPage, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPropertyPage
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPropertyPage
          DECLSPEC_XFGVIRT(IPropertyPage, SetPageSite)
          STD_METHOD SetPageSite, :ptr IPropertyPage, :ptr IPropertyPageSite
          ;* [in] *
          DECLSPEC_XFGVIRT(IPropertyPage, Activate)
          ;* [in] *
          ;* [in] *
          STD_METHOD Activate, :ptr IPropertyPage, :HWND, :LPCRECT, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IPropertyPage, Deactivate)
          STD_METHOD Deactivate, :ptr IPropertyPage
          DECLSPEC_XFGVIRT(IPropertyPage, GetPageInfo)
          STD_METHOD GetPageInfo, :ptr IPropertyPage, :ptr PROPPAGEINFO
          ;* [out] *
          DECLSPEC_XFGVIRT(IPropertyPage, SetObjects)
          ;* [in] *
          STD_METHOD SetObjects, :ptr IPropertyPage, :ULONG, :ptr ptr IUnknown
          ;* [size_is][in] *
          DECLSPEC_XFGVIRT(IPropertyPage, Show)
          STD_METHOD Show, :ptr IPropertyPage, :UINT
          ;* [in] *
          DECLSPEC_XFGVIRT(IPropertyPage, Move)
          STD_METHOD Move, :ptr IPropertyPage, :LPCRECT
          ;* [in] *
          DECLSPEC_XFGVIRT(IPropertyPage, IsPageDirty)
          STD_METHOD IsPageDirty, :ptr IPropertyPage
          DECLSPEC_XFGVIRT(IPropertyPage, Apply)
          STD_METHOD Apply, :ptr IPropertyPage
          DECLSPEC_XFGVIRT(IPropertyPage, Help)
          STD_METHOD Help, :ptr IPropertyPage, :LPCOLESTR
          ;* [in] *
          DECLSPEC_XFGVIRT(IPropertyPage, TranslateAccelerator)
          STD_METHOD TranslateAccelerator, :ptr IPropertyPage, :ptr MSG
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IPropertyPageVtbl ends
        IPropertyPage struct
          lpVtbl POINTER ?
        IPropertyPage ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IPropertyPage_INTERFACE_DEFINED__ *
    endif
    ifndef __IPropertyPage2_INTERFACE_DEFINED__
      __IPropertyPage2_INTERFACE_DEFINED__ equ <>
      ;* interface IPropertyPage2 *
      ;* [unique][uuid][object] *
      LPPROPERTYPAGE2 typedef ptr IPropertyPage2
      externdef IID_IPropertyPage2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPropertyPage2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPropertyPage2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IPropertyPage2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPropertyPage2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPropertyPage2
          DECLSPEC_XFGVIRT(IPropertyPage, SetPageSite)
          STD_METHOD SetPageSite, :ptr IPropertyPage2, :ptr IPropertyPageSite
          ;* [in] *
          DECLSPEC_XFGVIRT(IPropertyPage, Activate)
          ;* [in] *
          ;* [in] *
          STD_METHOD Activate, :ptr IPropertyPage2, :HWND, :LPCRECT, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IPropertyPage, Deactivate)
          STD_METHOD Deactivate, :ptr IPropertyPage2
          DECLSPEC_XFGVIRT(IPropertyPage, GetPageInfo)
          STD_METHOD GetPageInfo, :ptr IPropertyPage2, :ptr PROPPAGEINFO
          ;* [out] *
          DECLSPEC_XFGVIRT(IPropertyPage, SetObjects)
          ;* [in] *
          STD_METHOD SetObjects, :ptr IPropertyPage2, :ULONG, :ptr ptr IUnknown
          ;* [size_is][in] *
          DECLSPEC_XFGVIRT(IPropertyPage, Show)
          STD_METHOD Show, :ptr IPropertyPage2, :UINT
          ;* [in] *
          DECLSPEC_XFGVIRT(IPropertyPage, Move)
          STD_METHOD Move, :ptr IPropertyPage2, :LPCRECT
          ;* [in] *
          DECLSPEC_XFGVIRT(IPropertyPage, IsPageDirty)
          STD_METHOD IsPageDirty, :ptr IPropertyPage2
          DECLSPEC_XFGVIRT(IPropertyPage, Apply)
          STD_METHOD Apply, :ptr IPropertyPage2
          DECLSPEC_XFGVIRT(IPropertyPage, Help)
          STD_METHOD Help, :ptr IPropertyPage2, :LPCOLESTR
          ;* [in] *
          DECLSPEC_XFGVIRT(IPropertyPage, TranslateAccelerator)
          STD_METHOD TranslateAccelerator, :ptr IPropertyPage2, :ptr MSG
          ;* [in] *
          DECLSPEC_XFGVIRT(IPropertyPage2, EditProperty)
          STD_METHOD EditProperty, :ptr IPropertyPage2, :DISPID
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IPropertyPage2Vtbl ends
        IPropertyPage2 struct
          lpVtbl POINTER ?
        IPropertyPage2 ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IPropertyPage2_INTERFACE_DEFINED__ *
    endif
    ifndef __IPropertyPageSite_INTERFACE_DEFINED__
      __IPropertyPageSite_INTERFACE_DEFINED__ equ <>
      ;* interface IPropertyPageSite *
      ;* [unique][uuid][object] *
      LPPROPERTYPAGESITE typedef ptr IPropertyPageSite
      PROPPAGESTATUS typedef SDWORD
      PROPPAGESTATUS_DIRTY equ 1h
      PROPPAGESTATUS_VALIDATE equ 2h
      PROPPAGESTATUS_CLEAN equ 4h
      tagPROPPAGESTATUS typedef PROPPAGESTATUS

      externdef IID_IPropertyPageSite:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPropertyPageSiteVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPropertyPageSiteVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IPropertyPageSite, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPropertyPageSite
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPropertyPageSite
          DECLSPEC_XFGVIRT(IPropertyPageSite, OnStatusChange)
          STD_METHOD OnStatusChange, :ptr IPropertyPageSite, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IPropertyPageSite, GetLocaleID)
          STD_METHOD GetLocaleID, :ptr IPropertyPageSite, :ptr LCID
          ;* [out] *
          DECLSPEC_XFGVIRT(IPropertyPageSite, GetPageContainer)
          STD_METHOD GetPageContainer, :ptr IPropertyPageSite, :ptr ptr IUnknown
          ;* [out] *
          DECLSPEC_XFGVIRT(IPropertyPageSite, TranslateAccelerator)
          STD_METHOD TranslateAccelerator, :ptr IPropertyPageSite, :ptr MSG
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IPropertyPageSiteVtbl ends
        IPropertyPageSite struct
          lpVtbl POINTER ?
        IPropertyPageSite ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IPropertyPageSite_INTERFACE_DEFINED__ *
    endif
    ifndef __IPropertyNotifySink_INTERFACE_DEFINED__
      __IPropertyNotifySink_INTERFACE_DEFINED__ equ <>
      ;* interface IPropertyNotifySink *
      ;* [unique][uuid][object] *
      LPPROPERTYNOTIFYSINK typedef ptr IPropertyNotifySink
      externdef IID_IPropertyNotifySink:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPropertyNotifySinkVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPropertyNotifySinkVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IPropertyNotifySink, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPropertyNotifySink
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPropertyNotifySink
          DECLSPEC_XFGVIRT(IPropertyNotifySink, OnChanged)
          STD_METHOD OnChanged, :ptr IPropertyNotifySink, :DISPID
          ;* [in] *
          DECLSPEC_XFGVIRT(IPropertyNotifySink, OnRequestEdit)
          STD_METHOD OnRequestEdit, :ptr IPropertyNotifySink, :DISPID
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IPropertyNotifySinkVtbl ends
        IPropertyNotifySink struct
          lpVtbl POINTER ?
        IPropertyNotifySink ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IPropertyNotifySink_INTERFACE_DEFINED__ *
    endif
    ifndef __ISpecifyPropertyPages_INTERFACE_DEFINED__
      __ISpecifyPropertyPages_INTERFACE_DEFINED__ equ <>
      ;* interface ISpecifyPropertyPages *
      ;* [unique][uuid][object] *
      LPSPECIFYPROPERTYPAGES typedef ptr ISpecifyPropertyPages
      CAUUID struct
        cElems DWORD ?
        pElems POINTER ?
        ;* [size_is] *
      CAUUID ends
      tagCAUUID typedef CAUUID
      LPCAUUID typedef ptr tagCAUUID
      externdef IID_ISpecifyPropertyPages:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpecifyPropertyPagesVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpecifyPropertyPagesVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpecifyPropertyPages, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpecifyPropertyPages
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpecifyPropertyPages
          DECLSPEC_XFGVIRT(ISpecifyPropertyPages, GetPages)
          STD_METHOD GetPages, :ptr ISpecifyPropertyPages, :ptr CAUUID
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        ISpecifyPropertyPagesVtbl ends
        ISpecifyPropertyPages struct
          lpVtbl POINTER ?
        ISpecifyPropertyPages ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpecifyPropertyPages_INTERFACE_DEFINED__ *
    endif
    ifndef __IPersistMemory_INTERFACE_DEFINED__
      __IPersistMemory_INTERFACE_DEFINED__ equ <>
      ;* interface IPersistMemory *
      ;* [unique][uuid][object] *
      LPPERSISTMEMORY typedef ptr IPersistMemory
      externdef IID_IPersistMemory:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPersistMemoryVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPersistMemoryVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IPersistMemory, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPersistMemory
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPersistMemory
          DECLSPEC_XFGVIRT(IPersist, GetClassID)
          STD_METHOD GetClassID, :ptr IPersistMemory, :ptr CLSID
          ;* [out] *
          DECLSPEC_XFGVIRT(IPersistMemory, IsDirty)
          STD_METHOD IsDirty, :ptr IPersistMemory
          DECLSPEC_XFGVIRT(IPersistMemory, Load)
          ;* [local] *
          ;* [size_is][in] *
          STD_METHOD Load, :ptr IPersistMemory, :LPVOID, :ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(IPersistMemory, Save)
          ;* [local] *
          ;* [size_is][out] *
          ;* [in] *
          STD_METHOD Save, :ptr IPersistMemory, :LPVOID, :BOOL, :ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(IPersistMemory, GetSizeMax)
          STD_METHOD GetSizeMax, :ptr IPersistMemory, :ptr ULONG
          ;* [out] *
          DECLSPEC_XFGVIRT(IPersistMemory, InitNew)
          STD_METHOD InitNew, :ptr IPersistMemory
          ??Interface equ <>
          END_INTERFACE
        IPersistMemoryVtbl ends
        IPersistMemory struct
          lpVtbl POINTER ?
        IPersistMemory ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      IPersistMemory_RemoteLoad_Proxy proto WIN_STD_CALL_CONV :ptr IPersistMemory, :ptr BYTE, :ULONG
      ;* [in] *
      IPersistMemory_RemoteLoad_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      IPersistMemory_RemoteSave_Proxy proto WIN_STD_CALL_CONV :ptr IPersistMemory, :ptr BYTE, :BOOL, :ULONG
      ;* [in] *
      IPersistMemory_RemoteSave_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __IPersistMemory_INTERFACE_DEFINED__ *
    endif
    ifndef __IPersistStreamInit_INTERFACE_DEFINED__
      __IPersistStreamInit_INTERFACE_DEFINED__ equ <>
      ;* interface IPersistStreamInit *
      ;* [unique][uuid][object] *
      LPPERSISTSTREAMINIT typedef ptr IPersistStreamInit
      externdef IID_IPersistStreamInit:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPersistStreamInitVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPersistStreamInitVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IPersistStreamInit, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPersistStreamInit
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPersistStreamInit
          DECLSPEC_XFGVIRT(IPersist, GetClassID)
          STD_METHOD GetClassID, :ptr IPersistStreamInit, :ptr CLSID
          ;* [out] *
          DECLSPEC_XFGVIRT(IPersistStreamInit, IsDirty)
          STD_METHOD IsDirty, :ptr IPersistStreamInit
          DECLSPEC_XFGVIRT(IPersistStreamInit, Load)
          STD_METHOD Load, :ptr IPersistStreamInit, :LPSTREAM
          ;* [in] *
          DECLSPEC_XFGVIRT(IPersistStreamInit, Save)
          ;* [in] *
          STD_METHOD Save, :ptr IPersistStreamInit, :LPSTREAM, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IPersistStreamInit, GetSizeMax)
          STD_METHOD GetSizeMax, :ptr IPersistStreamInit, :ptr ULARGE_INTEGER
          ;* [out] *
          DECLSPEC_XFGVIRT(IPersistStreamInit, InitNew)
          STD_METHOD InitNew, :ptr IPersistStreamInit
          ??Interface equ <>
          END_INTERFACE
        IPersistStreamInitVtbl ends
        IPersistStreamInit struct
          lpVtbl POINTER ?
        IPersistStreamInit ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IPersistStreamInit_INTERFACE_DEFINED__ *
    endif
    ifndef __IPersistPropertyBag_INTERFACE_DEFINED__
      __IPersistPropertyBag_INTERFACE_DEFINED__ equ <>
      ;* interface IPersistPropertyBag *
      ;* [unique][uuid][object] *
      LPPERSISTPROPERTYBAG typedef ptr IPersistPropertyBag
      externdef IID_IPersistPropertyBag:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPersistPropertyBagVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPersistPropertyBagVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IPersistPropertyBag, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPersistPropertyBag
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPersistPropertyBag
          DECLSPEC_XFGVIRT(IPersist, GetClassID)
          STD_METHOD GetClassID, :ptr IPersistPropertyBag, :ptr CLSID
          ;* [out] *
          DECLSPEC_XFGVIRT(IPersistPropertyBag, InitNew)
          STD_METHOD InitNew, :ptr IPersistPropertyBag
          DECLSPEC_XFGVIRT(IPersistPropertyBag, Load)
          ;* [in] *
          STD_METHOD Load, :ptr IPersistPropertyBag, :ptr IPropertyBag, :ptr IErrorLog
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IPersistPropertyBag, Save)
          ;* [in] *
          ;* [in] *
          STD_METHOD Save, :ptr IPersistPropertyBag, :ptr IPropertyBag, :BOOL, :BOOL
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IPersistPropertyBagVtbl ends
        IPersistPropertyBag struct
          lpVtbl POINTER ?
        IPersistPropertyBag ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IPersistPropertyBag_INTERFACE_DEFINED__ *
    endif
    ifndef __ISimpleFrameSite_INTERFACE_DEFINED__
      __ISimpleFrameSite_INTERFACE_DEFINED__ equ <>
      ;* interface ISimpleFrameSite *
      ;* [unique][uuid][object] *
      LPSIMPLEFRAMESITE typedef ptr ISimpleFrameSite
      externdef IID_ISimpleFrameSite:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISimpleFrameSiteVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISimpleFrameSiteVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISimpleFrameSite, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISimpleFrameSite
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISimpleFrameSite
          DECLSPEC_XFGVIRT(ISimpleFrameSite, PreMessageFilter)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [out] *
          STD_METHOD PreMessageFilter, :ptr ISimpleFrameSite, :HWND, :UINT, :WPARAM, :LPARAM, :ptr LRESULT, :ptr DWORD
          ;* [out] *
          DECLSPEC_XFGVIRT(ISimpleFrameSite, PostMessageFilter)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [out] *
          STD_METHOD PostMessageFilter, :ptr ISimpleFrameSite, :HWND, :UINT, :WPARAM, :LPARAM, :ptr LRESULT, :DWORD
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        ISimpleFrameSiteVtbl ends
        ISimpleFrameSite struct
          lpVtbl POINTER ?
        ISimpleFrameSite ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISimpleFrameSite_INTERFACE_DEFINED__ *
    endif
    ifndef __IFont_INTERFACE_DEFINED__
      __IFont_INTERFACE_DEFINED__ equ <>
      ;* interface IFont *
      ;* [unique][uuid][object] *
      LPFONT typedef ptr IFont
      if (Defined(_WIN32) or Defined(_WIN64)) and  not Defined(OLE2ANSI)
        TEXTMETRICOLE typedef TEXTMETRICW
      else
        TEXTMETRICOLE typedef TEXTMETRIC
      endif
      LPTEXTMETRICOLE typedef ptr TEXTMETRICOLE
      externdef IID_IFont:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IFontVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IFontVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IFont, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IFont
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IFont
          DECLSPEC_XFGVIRT(IFont, get_Name)
          STD_METHOD get_Name, :ptr IFont, :ptr BSTR
          ;* [out] *
          DECLSPEC_XFGVIRT(IFont, put_Name)
          STD_METHOD put_Name, :ptr IFont, :BSTR
          ;* [in] *
          DECLSPEC_XFGVIRT(IFont, get_Size)
          STD_METHOD get_Size, :ptr IFont, :ptr CY
          ;* [out] *
          DECLSPEC_XFGVIRT(IFont, put_Size)
          STD_METHOD put_Size, :ptr IFont, :CY
          ;* [in] *
          DECLSPEC_XFGVIRT(IFont, get_Bold)
          STD_METHOD get_Bold, :ptr IFont, :ptr BOOL
          ;* [out] *
          DECLSPEC_XFGVIRT(IFont, put_Bold)
          STD_METHOD put_Bold, :ptr IFont, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IFont, get_Italic)
          STD_METHOD get_Italic, :ptr IFont, :ptr BOOL
          ;* [out] *
          DECLSPEC_XFGVIRT(IFont, put_Italic)
          STD_METHOD put_Italic, :ptr IFont, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IFont, get_Underline)
          STD_METHOD get_Underline, :ptr IFont, :ptr BOOL
          ;* [out] *
          DECLSPEC_XFGVIRT(IFont, put_Underline)
          STD_METHOD put_Underline, :ptr IFont, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IFont, get_Strikethrough)
          STD_METHOD get_Strikethrough, :ptr IFont, :ptr BOOL
          ;* [out] *
          DECLSPEC_XFGVIRT(IFont, put_Strikethrough)
          STD_METHOD put_Strikethrough, :ptr IFont, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IFont, get_Weight)
          STD_METHOD get_Weight, :ptr IFont, :ptr SHORT_
          ;* [out] *
          DECLSPEC_XFGVIRT(IFont, put_Weight)
          STD_METHOD put_Weight, :ptr IFont, :SHORT_
          ;* [in] *
          DECLSPEC_XFGVIRT(IFont, get_Charset)
          STD_METHOD get_Charset, :ptr IFont, :ptr SHORT_
          ;* [out] *
          DECLSPEC_XFGVIRT(IFont, put_Charset)
          STD_METHOD put_Charset, :ptr IFont, :SHORT_
          ;* [in] *
          DECLSPEC_XFGVIRT(IFont, get_hFont)
          STD_METHOD get_hFont, :ptr IFont, :ptr HFONT
          ;* [out] *
          DECLSPEC_XFGVIRT(IFont, Clone)
          STD_METHOD Clone, :ptr IFont, :ptr ptr IFont
          ;* [out] *
          DECLSPEC_XFGVIRT(IFont, IsEqual)
          STD_METHOD IsEqual, :ptr IFont, :ptr IFont
          ;* [in] *
          DECLSPEC_XFGVIRT(IFont, SetRatio)
          ;* [in] *
          STD_METHOD SetRatio, :ptr IFont, :LONG, :LONG
          ;* [in] *
          DECLSPEC_XFGVIRT(IFont, QueryTextMetrics)
          STD_METHOD QueryTextMetrics, :ptr IFont, :ptr TEXTMETRICOLE
          ;* [out] *
          DECLSPEC_XFGVIRT(IFont, AddRefHfont)
          STD_METHOD AddRefHfont, :ptr IFont, :HFONT
          ;* [in] *
          DECLSPEC_XFGVIRT(IFont, ReleaseHfont)
          STD_METHOD ReleaseHfont, :ptr IFont, :HFONT
          ;* [in] *
          DECLSPEC_XFGVIRT(IFont, SetHdc)
          STD_METHOD SetHdc, :ptr IFont, :HDC
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IFontVtbl ends
        IFont struct
          lpVtbl POINTER ?
        IFont ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IFont_INTERFACE_DEFINED__ *
    endif
    ifndef __IPicture_INTERFACE_DEFINED__
      __IPicture_INTERFACE_DEFINED__ equ <>
      ;* interface IPicture *
      ;* [unique][uuid][object] *
      LPPICTURE typedef ptr IPicture
      PICTUREATTRIBUTES typedef SDWORD
      PICTURE_SCALABLE equ 1h
      PICTURE_TRANSPARENT equ 2h
      tagPictureAttributes typedef PICTUREATTRIBUTES

      ;* [public][uuid] *
      DECLSPEC_UUID("66504313-BE0F-101A-8BBB-00AA00300CAB")
      OLE_HANDLE typedef UINT
      ;* [hidden][uuid] *
      DECLSPEC_UUID("66504306-BE0F-101A-8BBB-00AA00300CAB")
      OLE_XPOS_HIMETRIC typedef LONG
      ;* [hidden][uuid] *
      DECLSPEC_UUID("66504307-BE0F-101A-8BBB-00AA00300CAB")
      OLE_YPOS_HIMETRIC typedef LONG
      ;* [hidden][uuid] *
      DECLSPEC_UUID("66504308-BE0F-101A-8BBB-00AA00300CAB")
      OLE_XSIZE_HIMETRIC typedef LONG
      ;* [hidden][uuid] *
      DECLSPEC_UUID("66504309-BE0F-101A-8BBB-00AA00300CAB")
      OLE_YSIZE_HIMETRIC typedef LONG
      externdef IID_IPicture:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPictureVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPictureVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IPicture, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPicture
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPicture
          DECLSPEC_XFGVIRT(IPicture, get_Handle)
          STD_METHOD get_Handle, :ptr IPicture, :ptr OLE_HANDLE
          ;* [out] *
          DECLSPEC_XFGVIRT(IPicture, get_hPal)
          STD_METHOD get_hPal, :ptr IPicture, :ptr OLE_HANDLE
          ;* [out] *
          DECLSPEC_XFGVIRT(IPicture, get_Type)
          STD_METHOD get_Type, :ptr IPicture, :ptr SHORT_
          ;* [out] *
          DECLSPEC_XFGVIRT(IPicture, get_Width)
          STD_METHOD get_Width, :ptr IPicture, :ptr OLE_XSIZE_HIMETRIC
          ;* [out] *
          DECLSPEC_XFGVIRT(IPicture, get_Height)
          STD_METHOD get_Height, :ptr IPicture, :ptr OLE_YSIZE_HIMETRIC
          ;* [out] *
          DECLSPEC_XFGVIRT(IPicture, Render)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD Render, :ptr IPicture, :HDC, :LONG, :LONG, :LONG, :LONG, :OLE_XPOS_HIMETRIC, :OLE_YPOS_HIMETRIC, :OLE_XSIZE_HIMETRIC, :OLE_YSIZE_HIMETRIC, :LPCRECT
          ;* [in] *
          DECLSPEC_XFGVIRT(IPicture, set_hPal)
          STD_METHOD set_hPal, :ptr IPicture, :OLE_HANDLE
          ;* [in] *
          DECLSPEC_XFGVIRT(IPicture, get_CurDC)
          STD_METHOD get_CurDC, :ptr IPicture, :ptr HDC
          ;* [out] *
          DECLSPEC_XFGVIRT(IPicture, SelectPicture)
          ;* [in] *
          ;* [out] *
          STD_METHOD SelectPicture, :ptr IPicture, :HDC, :ptr HDC, :ptr OLE_HANDLE
          ;* [out] *
          DECLSPEC_XFGVIRT(IPicture, get_KeepOriginalFormat)
          STD_METHOD get_KeepOriginalFormat, :ptr IPicture, :ptr BOOL
          ;* [out] *
          DECLSPEC_XFGVIRT(IPicture, put_KeepOriginalFormat)
          STD_METHOD put_KeepOriginalFormat, :ptr IPicture, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IPicture, PictureChanged)
          STD_METHOD PictureChanged, :ptr IPicture
          DECLSPEC_XFGVIRT(IPicture, SaveAsFile)
          ;* [in] *
          ;* [in] *
          STD_METHOD SaveAsFile, :ptr IPicture, :LPSTREAM, :BOOL, :ptr LONG
          ;* [out] *
          DECLSPEC_XFGVIRT(IPicture, get_Attributes)
          STD_METHOD get_Attributes, :ptr IPicture, :ptr DWORD
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IPictureVtbl ends
        IPicture struct
          lpVtbl POINTER ?
        IPicture ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IPicture_INTERFACE_DEFINED__ *
    endif
    ifndef __IPicture2_INTERFACE_DEFINED__
      __IPicture2_INTERFACE_DEFINED__ equ <>
      ;* interface IPicture2 *
      ;* [unique][uuid][object] *
      LPPICTURE2 typedef ptr IPicture2
      HHANDLE typedef UINT_PTR
      externdef IID_IPicture2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPicture2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPicture2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IPicture2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPicture2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPicture2
          DECLSPEC_XFGVIRT(IPicture2, get_Handle)
          STD_METHOD get_Handle, :ptr IPicture2, :ptr HHANDLE
          ;* [out] *
          DECLSPEC_XFGVIRT(IPicture2, get_hPal)
          STD_METHOD get_hPal, :ptr IPicture2, :ptr HHANDLE
          ;* [out] *
          DECLSPEC_XFGVIRT(IPicture2, get_Type)
          STD_METHOD get_Type, :ptr IPicture2, :ptr SHORT_
          ;* [out] *
          DECLSPEC_XFGVIRT(IPicture2, get_Width)
          STD_METHOD get_Width, :ptr IPicture2, :ptr OLE_XSIZE_HIMETRIC
          ;* [out] *
          DECLSPEC_XFGVIRT(IPicture2, get_Height)
          STD_METHOD get_Height, :ptr IPicture2, :ptr OLE_YSIZE_HIMETRIC
          ;* [out] *
          DECLSPEC_XFGVIRT(IPicture2, Render)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD Render, :ptr IPicture2, :HDC, :LONG, :LONG, :LONG, :LONG, :OLE_XPOS_HIMETRIC, :OLE_YPOS_HIMETRIC, :OLE_XSIZE_HIMETRIC, :OLE_YSIZE_HIMETRIC, :LPCRECT
          ;* [in] *
          DECLSPEC_XFGVIRT(IPicture2, set_hPal)
          STD_METHOD set_hPal, :ptr IPicture2, :HHANDLE
          ;* [in] *
          DECLSPEC_XFGVIRT(IPicture2, get_CurDC)
          STD_METHOD get_CurDC, :ptr IPicture2, :ptr HDC
          ;* [out] *
          DECLSPEC_XFGVIRT(IPicture2, SelectPicture)
          ;* [in] *
          ;* [out] *
          STD_METHOD SelectPicture, :ptr IPicture2, :HDC, :ptr HDC, :ptr HHANDLE
          ;* [out] *
          DECLSPEC_XFGVIRT(IPicture2, get_KeepOriginalFormat)
          STD_METHOD get_KeepOriginalFormat, :ptr IPicture2, :ptr BOOL
          ;* [out] *
          DECLSPEC_XFGVIRT(IPicture2, put_KeepOriginalFormat)
          STD_METHOD put_KeepOriginalFormat, :ptr IPicture2, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IPicture2, PictureChanged)
          STD_METHOD PictureChanged, :ptr IPicture2
          DECLSPEC_XFGVIRT(IPicture2, SaveAsFile)
          ;* [in] *
          ;* [in] *
          STD_METHOD SaveAsFile, :ptr IPicture2, :LPSTREAM, :BOOL, :ptr LONG
          ;* [out] *
          DECLSPEC_XFGVIRT(IPicture2, get_Attributes)
          STD_METHOD get_Attributes, :ptr IPicture2, :ptr DWORD
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IPicture2Vtbl ends
        IPicture2 struct
          lpVtbl POINTER ?
        IPicture2 ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IPicture2_INTERFACE_DEFINED__ *
    endif
    ifndef __IFontEventsDisp_INTERFACE_DEFINED__
      __IFontEventsDisp_INTERFACE_DEFINED__ equ <>
      ;* interface IFontEventsDisp *
      ;* [unique][uuid][object] *
      LPFONTEVENTS typedef ptr IFontEventsDisp
      externdef IID_IFontEventsDisp:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IFontEventsDispVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IFontEventsDispVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IFontEventsDisp, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IFontEventsDisp
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IFontEventsDisp
          DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
          STD_METHOD GetTypeInfoCount, :ptr IFontEventsDisp, :ptr UINT
          ;* [out] *
          DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
          ;* [in] *
          ;* [in] *
          STD_METHOD GetTypeInfo, :ptr IFontEventsDisp, :UINT, :LCID, :ptr ptr ITypeInfo
          ;* [out] *
          DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
          ;* [in] *
          ;* [size_is][in] *
          ;* [range][in] *
          ;* [in] *
          STD_METHOD GetIDsOfNames, :ptr IFontEventsDisp, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
          ;* [size_is][out] *
          DECLSPEC_XFGVIRT(IDispatch, Invoke)
          ;* [local] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][out][in] *
          ;* [annotation][out] *
          ;* [annotation][out] *
          ;* [annotation][out] *
          STD_METHOD Invoke_, :ptr IFontEventsDisp, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
          ??Interface equ <>
          END_INTERFACE
        IFontEventsDispVtbl ends
        IFontEventsDisp struct
          lpVtbl POINTER ?
        IFontEventsDisp ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IFontEventsDisp_INTERFACE_DEFINED__ *
    endif
    ifndef __IFontDisp_INTERFACE_DEFINED__
      __IFontDisp_INTERFACE_DEFINED__ equ <>
      ;* interface IFontDisp *
      ;* [unique][uuid][object] *
      LPFONTDISP typedef ptr IFontDisp
      externdef IID_IFontDisp:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IFontDispVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IFontDispVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IFontDisp, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IFontDisp
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IFontDisp
          DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
          STD_METHOD GetTypeInfoCount, :ptr IFontDisp, :ptr UINT
          ;* [out] *
          DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
          ;* [in] *
          ;* [in] *
          STD_METHOD GetTypeInfo, :ptr IFontDisp, :UINT, :LCID, :ptr ptr ITypeInfo
          ;* [out] *
          DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
          ;* [in] *
          ;* [size_is][in] *
          ;* [range][in] *
          ;* [in] *
          STD_METHOD GetIDsOfNames, :ptr IFontDisp, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
          ;* [size_is][out] *
          DECLSPEC_XFGVIRT(IDispatch, Invoke)
          ;* [local] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][out][in] *
          ;* [annotation][out] *
          ;* [annotation][out] *
          ;* [annotation][out] *
          STD_METHOD Invoke_, :ptr IFontDisp, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
          ??Interface equ <>
          END_INTERFACE
        IFontDispVtbl ends
        IFontDisp struct
          lpVtbl POINTER ?
        IFontDisp ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IFontDisp_INTERFACE_DEFINED__ *
    endif
    ifndef __IPictureDisp_INTERFACE_DEFINED__
      __IPictureDisp_INTERFACE_DEFINED__ equ <>
      ;* interface IPictureDisp *
      ;* [unique][uuid][object] *
      LPPICTUREDISP typedef ptr IPictureDisp
      externdef IID_IPictureDisp:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPictureDispVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPictureDispVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IPictureDisp, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPictureDisp
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPictureDisp
          DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
          STD_METHOD GetTypeInfoCount, :ptr IPictureDisp, :ptr UINT
          ;* [out] *
          DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
          ;* [in] *
          ;* [in] *
          STD_METHOD GetTypeInfo, :ptr IPictureDisp, :UINT, :LCID, :ptr ptr ITypeInfo
          ;* [out] *
          DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
          ;* [in] *
          ;* [size_is][in] *
          ;* [range][in] *
          ;* [in] *
          STD_METHOD GetIDsOfNames, :ptr IPictureDisp, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
          ;* [size_is][out] *
          DECLSPEC_XFGVIRT(IDispatch, Invoke)
          ;* [local] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][out][in] *
          ;* [annotation][out] *
          ;* [annotation][out] *
          ;* [annotation][out] *
          STD_METHOD Invoke_, :ptr IPictureDisp, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
          ??Interface equ <>
          END_INTERFACE
        IPictureDispVtbl ends
        IPictureDisp struct
          lpVtbl POINTER ?
        IPictureDisp ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IPictureDisp_INTERFACE_DEFINED__ *
    endif
    ifndef __IOleInPlaceObjectWindowless_INTERFACE_DEFINED__
      __IOleInPlaceObjectWindowless_INTERFACE_DEFINED__ equ <>
      ;* interface IOleInPlaceObjectWindowless *
      ;* [uuid][unique][object] *
      LPOLEINPLACEOBJECTWINDOWLESS typedef ptr IOleInPlaceObjectWindowless
      externdef IID_IOleInPlaceObjectWindowless:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IOleInPlaceObjectWindowlessVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IOleInPlaceObjectWindowlessVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IOleInPlaceObjectWindowless, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IOleInPlaceObjectWindowless
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IOleInPlaceObjectWindowless
          DECLSPEC_XFGVIRT(IOleWindow, GetWindow)
          ;* [input_sync] *
          STD_METHOD GetWindow, :ptr IOleInPlaceObjectWindowless, :ptr HWND
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleWindow, ContextSensitiveHelp)
          STD_METHOD ContextSensitiveHelp, :ptr IOleInPlaceObjectWindowless, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleInPlaceObject, InPlaceDeactivate)
          STD_METHOD InPlaceDeactivate, :ptr IOleInPlaceObjectWindowless
          DECLSPEC_XFGVIRT(IOleInPlaceObject, UIDeactivate)
          STD_METHOD UIDeactivate, :ptr IOleInPlaceObjectWindowless
          DECLSPEC_XFGVIRT(IOleInPlaceObject, SetObjectRects)
          ;* [input_sync] *
          ;* [in] *
          STD_METHOD SetObjectRects, :ptr IOleInPlaceObjectWindowless, :LPCRECT, :LPCRECT
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleInPlaceObject, ReactivateAndUndo)
          STD_METHOD ReactivateAndUndo, :ptr IOleInPlaceObjectWindowless
          DECLSPEC_XFGVIRT(IOleInPlaceObjectWindowless, OnWindowMessage)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD OnWindowMessage, :ptr IOleInPlaceObjectWindowless, :UINT, :WPARAM, :LPARAM, :ptr LRESULT
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleInPlaceObjectWindowless, GetDropTarget)
          STD_METHOD GetDropTarget, :ptr IOleInPlaceObjectWindowless, :ptr ptr IDropTarget
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IOleInPlaceObjectWindowlessVtbl ends
        IOleInPlaceObjectWindowless struct
          lpVtbl POINTER ?
        IOleInPlaceObjectWindowless ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IOleInPlaceObjectWindowless_INTERFACE_DEFINED__ *
    endif
    ifndef __IOleInPlaceSiteEx_INTERFACE_DEFINED__
      __IOleInPlaceSiteEx_INTERFACE_DEFINED__ equ <>
      ;* interface IOleInPlaceSiteEx *
      ;* [uuid][unique][object] *
      LPOLEINPLACESITEEX typedef ptr IOleInPlaceSiteEx
      ;* [v1_enum] *
      ACTIVATEFLAGS typedef SDWORD
      ACTIVATE_WINDOWLESS equ 1
      tagACTIVATEFLAGS typedef ACTIVATEFLAGS

      externdef IID_IOleInPlaceSiteEx:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IOleInPlaceSiteExVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IOleInPlaceSiteExVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IOleInPlaceSiteEx, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IOleInPlaceSiteEx
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IOleInPlaceSiteEx
          DECLSPEC_XFGVIRT(IOleWindow, GetWindow)
          ;* [input_sync] *
          STD_METHOD GetWindow, :ptr IOleInPlaceSiteEx, :ptr HWND
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleWindow, ContextSensitiveHelp)
          STD_METHOD ContextSensitiveHelp, :ptr IOleInPlaceSiteEx, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleInPlaceSite, CanInPlaceActivate)
          STD_METHOD CanInPlaceActivate, :ptr IOleInPlaceSiteEx
          DECLSPEC_XFGVIRT(IOleInPlaceSite, OnInPlaceActivate)
          STD_METHOD OnInPlaceActivate, :ptr IOleInPlaceSiteEx
          DECLSPEC_XFGVIRT(IOleInPlaceSite, OnUIActivate)
          STD_METHOD OnUIActivate, :ptr IOleInPlaceSiteEx
          DECLSPEC_XFGVIRT(IOleInPlaceSite, GetWindowContext)
          ;* [out] *
          ;* [out] *
          ;* [out] *
          ;* [out] *
          STD_METHOD GetWindowContext, :ptr IOleInPlaceSiteEx, :ptr ptr IOleInPlaceFrame, :ptr ptr IOleInPlaceUIWindow, :LPRECT, :LPRECT, :LPOLEINPLACEFRAMEINFO
          ;* [out][in] *
          DECLSPEC_XFGVIRT(IOleInPlaceSite, Scroll)
          STD_METHOD Scroll, :ptr IOleInPlaceSiteEx, :SIZE_
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleInPlaceSite, OnUIDeactivate)
          STD_METHOD OnUIDeactivate, :ptr IOleInPlaceSiteEx, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleInPlaceSite, OnInPlaceDeactivate)
          STD_METHOD OnInPlaceDeactivate, :ptr IOleInPlaceSiteEx
          DECLSPEC_XFGVIRT(IOleInPlaceSite, DiscardUndoState)
          STD_METHOD DiscardUndoState, :ptr IOleInPlaceSiteEx
          DECLSPEC_XFGVIRT(IOleInPlaceSite, DeactivateAndUndo)
          STD_METHOD DeactivateAndUndo, :ptr IOleInPlaceSiteEx
          DECLSPEC_XFGVIRT(IOleInPlaceSite, OnPosRectChange)
          STD_METHOD OnPosRectChange, :ptr IOleInPlaceSiteEx, :LPCRECT
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleInPlaceSiteEx, OnInPlaceActivateEx)
          ;* [out] *
          STD_METHOD OnInPlaceActivateEx, :ptr IOleInPlaceSiteEx, :ptr BOOL, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleInPlaceSiteEx, OnInPlaceDeactivateEx)
          STD_METHOD OnInPlaceDeactivateEx, :ptr IOleInPlaceSiteEx, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleInPlaceSiteEx, RequestUIActivate)
          STD_METHOD RequestUIActivate, :ptr IOleInPlaceSiteEx
          ??Interface equ <>
          END_INTERFACE
        IOleInPlaceSiteExVtbl ends
        IOleInPlaceSiteEx struct
          lpVtbl POINTER ?
        IOleInPlaceSiteEx ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IOleInPlaceSiteEx_INTERFACE_DEFINED__ *
    endif
    ifndef __IOleInPlaceSiteWindowless_INTERFACE_DEFINED__
      __IOleInPlaceSiteWindowless_INTERFACE_DEFINED__ equ <>
      ;* interface IOleInPlaceSiteWindowless *
      ;* [uuid][unique][object] *
      LPOLEINPLACESITEWINDOWLESS typedef ptr IOleInPlaceSiteWindowless
      ;* [v1_enum] *
      OLEDCFLAGS typedef SDWORD
      OLEDC_NODRAW equ 1h
      OLEDC_PAINTBKGND equ 2h
      OLEDC_OFFSCREEN equ 4h
      tagOLEDCFLAGS typedef OLEDCFLAGS

      externdef IID_IOleInPlaceSiteWindowless:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IOleInPlaceSiteWindowlessVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IOleInPlaceSiteWindowlessVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IOleInPlaceSiteWindowless, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IOleInPlaceSiteWindowless
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IOleInPlaceSiteWindowless
          DECLSPEC_XFGVIRT(IOleWindow, GetWindow)
          ;* [input_sync] *
          STD_METHOD GetWindow, :ptr IOleInPlaceSiteWindowless, :ptr HWND
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleWindow, ContextSensitiveHelp)
          STD_METHOD ContextSensitiveHelp, :ptr IOleInPlaceSiteWindowless, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleInPlaceSite, CanInPlaceActivate)
          STD_METHOD CanInPlaceActivate, :ptr IOleInPlaceSiteWindowless
          DECLSPEC_XFGVIRT(IOleInPlaceSite, OnInPlaceActivate)
          STD_METHOD OnInPlaceActivate, :ptr IOleInPlaceSiteWindowless
          DECLSPEC_XFGVIRT(IOleInPlaceSite, OnUIActivate)
          STD_METHOD OnUIActivate, :ptr IOleInPlaceSiteWindowless
          DECLSPEC_XFGVIRT(IOleInPlaceSite, GetWindowContext)
          ;* [out] *
          ;* [out] *
          ;* [out] *
          ;* [out] *
          STD_METHOD GetWindowContext, :ptr IOleInPlaceSiteWindowless, :ptr ptr IOleInPlaceFrame, :ptr ptr IOleInPlaceUIWindow, :LPRECT, :LPRECT, :LPOLEINPLACEFRAMEINFO
          ;* [out][in] *
          DECLSPEC_XFGVIRT(IOleInPlaceSite, Scroll)
          STD_METHOD Scroll, :ptr IOleInPlaceSiteWindowless, :SIZE_
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleInPlaceSite, OnUIDeactivate)
          STD_METHOD OnUIDeactivate, :ptr IOleInPlaceSiteWindowless, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleInPlaceSite, OnInPlaceDeactivate)
          STD_METHOD OnInPlaceDeactivate, :ptr IOleInPlaceSiteWindowless
          DECLSPEC_XFGVIRT(IOleInPlaceSite, DiscardUndoState)
          STD_METHOD DiscardUndoState, :ptr IOleInPlaceSiteWindowless
          DECLSPEC_XFGVIRT(IOleInPlaceSite, DeactivateAndUndo)
          STD_METHOD DeactivateAndUndo, :ptr IOleInPlaceSiteWindowless
          DECLSPEC_XFGVIRT(IOleInPlaceSite, OnPosRectChange)
          STD_METHOD OnPosRectChange, :ptr IOleInPlaceSiteWindowless, :LPCRECT
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleInPlaceSiteEx, OnInPlaceActivateEx)
          ;* [out] *
          STD_METHOD OnInPlaceActivateEx, :ptr IOleInPlaceSiteWindowless, :ptr BOOL, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleInPlaceSiteEx, OnInPlaceDeactivateEx)
          STD_METHOD OnInPlaceDeactivateEx, :ptr IOleInPlaceSiteWindowless, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleInPlaceSiteEx, RequestUIActivate)
          STD_METHOD RequestUIActivate, :ptr IOleInPlaceSiteWindowless
          DECLSPEC_XFGVIRT(IOleInPlaceSiteWindowless, CanWindowlessActivate)
          STD_METHOD CanWindowlessActivate, :ptr IOleInPlaceSiteWindowless
          DECLSPEC_XFGVIRT(IOleInPlaceSiteWindowless, GetCapture)
          STD_METHOD GetCapture, :ptr IOleInPlaceSiteWindowless
          DECLSPEC_XFGVIRT(IOleInPlaceSiteWindowless, SetCapture)
          STD_METHOD SetCapture, :ptr IOleInPlaceSiteWindowless, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleInPlaceSiteWindowless, GetFocus)
          STD_METHOD GetFocus, :ptr IOleInPlaceSiteWindowless
          DECLSPEC_XFGVIRT(IOleInPlaceSiteWindowless, SetFocus)
          STD_METHOD SetFocus, :ptr IOleInPlaceSiteWindowless, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleInPlaceSiteWindowless, GetDC)
          ;* [unique][in] *
          ;* [in] *
          STD_METHOD GetDC, :ptr IOleInPlaceSiteWindowless, :LPCRECT, :DWORD, :ptr HDC
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleInPlaceSiteWindowless, ReleaseDC)
          STD_METHOD ReleaseDC, :ptr IOleInPlaceSiteWindowless, :HDC
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleInPlaceSiteWindowless, InvalidateRect)
          ;* [unique][in] *
          STD_METHOD InvalidateRect, :ptr IOleInPlaceSiteWindowless, :LPCRECT, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleInPlaceSiteWindowless, InvalidateRgn)
          ;* [in] *
          STD_METHOD InvalidateRgn, :ptr IOleInPlaceSiteWindowless, :HRGN, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleInPlaceSiteWindowless, ScrollRect)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD ScrollRect, :ptr IOleInPlaceSiteWindowless, :INT_, :INT_, :LPCRECT, :LPCRECT
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleInPlaceSiteWindowless, AdjustRect)
          STD_METHOD AdjustRect, :ptr IOleInPlaceSiteWindowless, :LPRECT
          ;* [out][in] *
          DECLSPEC_XFGVIRT(IOleInPlaceSiteWindowless, OnDefWindowMessage)
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          STD_METHOD OnDefWindowMessage, :ptr IOleInPlaceSiteWindowless, :UINT, :WPARAM, :LPARAM, :ptr LRESULT
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IOleInPlaceSiteWindowlessVtbl ends
        IOleInPlaceSiteWindowless struct
          lpVtbl POINTER ?
        IOleInPlaceSiteWindowless ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IOleInPlaceSiteWindowless_INTERFACE_DEFINED__ *
    endif
    ifndef __IViewObjectEx_INTERFACE_DEFINED__
      __IViewObjectEx_INTERFACE_DEFINED__ equ <>
      ;* interface IViewObjectEx *
      ;* [uuid][unique][object] *
      LPVIEWOBJECTEX typedef ptr IViewObjectEx
      ;* [v1_enum] *
      VIEWSTATUS typedef SDWORD
      VIEWSTATUS_OPAQUE equ 1
      VIEWSTATUS_SOLIDBKGND equ 2
      VIEWSTATUS_DVASPECTOPAQUE equ 4
      VIEWSTATUS_DVASPECTTRANSPARENT equ 8
      VIEWSTATUS_SURFACE equ 16
      VIEWSTATUS_3DSURFACE equ 32
      tagVIEWSTATUS typedef VIEWSTATUS

      ;* [v1_enum] *
      HITRESULT typedef SDWORD
      HITRESULT_OUTSIDE equ 0
      HITRESULT_TRANSPARENT equ 1
      HITRESULT_CLOSE equ 2
      HITRESULT_HIT equ 3
      tagHITRESULT typedef HITRESULT

      ;* [v1_enum] *
      DVASPECT2 typedef SDWORD
      DVASPECT_OPAQUE equ 16
      DVASPECT_TRANSPARENT equ 32
      tagDVASPECT2 typedef DVASPECT2

      DVEXTENTINFO struct
        cb DWORD ?
        dwExtentMode DWORD ?
        sizelProposed SIZEL <>
      DVEXTENTINFO ends
      tagExtentInfo typedef DVEXTENTINFO
      ;* [v1_enum] *
      DVEXTENTMODE typedef SDWORD
      DVEXTENT_CONTENT equ 0
      DVEXTENT_INTEGRAL equ
      tagExtentMode typedef DVEXTENTMODE

      ;* [v1_enum] *
      DVASPECTINFOFLAG typedef SDWORD
      DVASPECTINFOFLAG_CANOPTIMIZE equ 1
      tagAspectInfoFlag typedef DVASPECTINFOFLAG

      DVASPECTINFO struct
        cb DWORD ?
        dwFlags DWORD ?
      DVASPECTINFO ends
      tagAspectInfo typedef DVASPECTINFO
      externdef IID_IViewObjectEx:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IViewObjectExVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IViewObjectExVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IViewObjectEx, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IViewObjectEx
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IViewObjectEx
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
          STD_METHOD Draw, :ptr IViewObjectEx, :DWORD, :LONG, :ptr, :ptr DVTARGETDEVICE, :HDC, :HDC, :LPCRECTL, :LPCRECTL, :, :ULONG_PTR
          DECLSPEC_XFGVIRT(IViewObject, GetColorSet)
          ;* [local] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][unique][in] *
          ;* [annotation][unique][in] *
          ;* [annotation][in] *
          ;* [annotation][out] *
          STD_METHOD GetColorSet, :ptr IViewObjectEx, :DWORD, :LONG, :ptr, :ptr DVTARGETDEVICE, :HDC, :ptr ptr LOGPALETTE
          DECLSPEC_XFGVIRT(IViewObject, Freeze)
          ;* [local] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][unique][in] *
          ;* [annotation][out] *
          STD_METHOD Freeze, :ptr IViewObjectEx, :DWORD, :LONG, :ptr, :ptr DWORD
          DECLSPEC_XFGVIRT(IViewObject, Unfreeze)
          STD_METHOD Unfreeze, :ptr IViewObjectEx, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IViewObject, SetAdvise)
          ;* [in] *
          ;* [in] *
          STD_METHOD SetAdvise, :ptr IViewObjectEx, :DWORD, :DWORD, :ptr IAdviseSink
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IViewObject, GetAdvise)
          ;* [local] *
          ;* [annotation][unique][out] *
          ;* [annotation][unique][out] *
          ;* [annotation][out] *
          STD_METHOD GetAdvise, :ptr IViewObjectEx, :ptr DWORD, :ptr DWORD, :ptr ptr IAdviseSink
          DECLSPEC_XFGVIRT(IViewObject2, GetExtent)
          ;* [in] *
          ;* [in] *
          ;* [unique][in] *
          STD_METHOD GetExtent, :ptr IViewObjectEx, :DWORD, :LONG, :ptr DVTARGETDEVICE, :LPSIZEL
          ;* [out] *
          DECLSPEC_XFGVIRT(IViewObjectEx, GetRect)
          ;* [in] *
          STD_METHOD GetRect, :ptr IViewObjectEx, :DWORD, :LPRECTL
          ;* [out] *
          DECLSPEC_XFGVIRT(IViewObjectEx, GetViewStatus)
          STD_METHOD GetViewStatus, :ptr IViewObjectEx, :ptr DWORD
          ;* [out] *
          DECLSPEC_XFGVIRT(IViewObjectEx, QueryHitPoint)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD QueryHitPoint, :ptr IViewObjectEx, :DWORD, :LPCRECT, :POINT, :LONG, :ptr DWORD
          ;* [out] *
          DECLSPEC_XFGVIRT(IViewObjectEx, QueryHitRect)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD QueryHitRect, :ptr IViewObjectEx, :DWORD, :LPCRECT, :LPCRECT, :LONG, :ptr DWORD
          ;* [out] *
          DECLSPEC_XFGVIRT(IViewObjectEx, GetNaturalExtent)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD GetNaturalExtent, :ptr IViewObjectEx, :DWORD, :LONG, :ptr DVTARGETDEVICE, :HDC, :ptr DVEXTENTINFO, :LPSIZEL
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IViewObjectExVtbl ends
        IViewObjectEx struct
          lpVtbl POINTER ?
        IViewObjectEx ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IViewObjectEx_INTERFACE_DEFINED__ *
    endif
    ifndef __IOleUndoUnit_INTERFACE_DEFINED__
      __IOleUndoUnit_INTERFACE_DEFINED__ equ <>
      ;* interface IOleUndoUnit *
      ;* [uuid][unique][object] *
      LPOLEUNDOUNIT typedef ptr IOleUndoUnit
      externdef IID_IOleUndoUnit:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IOleUndoUnitVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IOleUndoUnitVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IOleUndoUnit, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IOleUndoUnit
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IOleUndoUnit
          DECLSPEC_XFGVIRT(IOleUndoUnit, Do)
          STD_METHOD Do, :ptr IOleUndoUnit, :ptr IOleUndoManager
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleUndoUnit, GetDescription)
          STD_METHOD GetDescription, :ptr IOleUndoUnit, :ptr BSTR
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleUndoUnit, GetUnitType)
          ;* [out] *
          STD_METHOD GetUnitType, :ptr IOleUndoUnit, :ptr CLSID, :ptr LONG
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleUndoUnit, OnNextAdd)
          STD_METHOD OnNextAdd, :ptr IOleUndoUnit
          ??Interface equ <>
          END_INTERFACE
        IOleUndoUnitVtbl ends
        IOleUndoUnit struct
          lpVtbl POINTER ?
        IOleUndoUnit ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IOleUndoUnit_INTERFACE_DEFINED__ *
    endif
    ifndef __IOleParentUndoUnit_INTERFACE_DEFINED__
      __IOleParentUndoUnit_INTERFACE_DEFINED__ equ <>
      ;* interface IOleParentUndoUnit *
      ;* [uuid][unique][object] *
      LPOLEPARENTUNDOUNIT typedef ptr IOleParentUndoUnit
      externdef IID_IOleParentUndoUnit:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IOleParentUndoUnitVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IOleParentUndoUnitVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IOleParentUndoUnit, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IOleParentUndoUnit
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IOleParentUndoUnit
          DECLSPEC_XFGVIRT(IOleUndoUnit, Do)
          STD_METHOD Do, :ptr IOleParentUndoUnit, :ptr IOleUndoManager
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleUndoUnit, GetDescription)
          STD_METHOD GetDescription, :ptr IOleParentUndoUnit, :ptr BSTR
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleUndoUnit, GetUnitType)
          ;* [out] *
          STD_METHOD GetUnitType, :ptr IOleParentUndoUnit, :ptr CLSID, :ptr LONG
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleUndoUnit, OnNextAdd)
          STD_METHOD OnNextAdd, :ptr IOleParentUndoUnit
          DECLSPEC_XFGVIRT(IOleParentUndoUnit, Open)
          STD_METHOD Open, :ptr IOleParentUndoUnit, :ptr IOleParentUndoUnit
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleParentUndoUnit, Close)
          ;* [in] *
          STD_METHOD Close, :ptr IOleParentUndoUnit, :ptr IOleParentUndoUnit, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleParentUndoUnit, Add)
          STD_METHOD Add_, :ptr IOleParentUndoUnit, :ptr IOleUndoUnit
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleParentUndoUnit, FindUnit)
          STD_METHOD FindUnit, :ptr IOleParentUndoUnit, :ptr IOleUndoUnit
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleParentUndoUnit, GetParentState)
          STD_METHOD GetParentState, :ptr IOleParentUndoUnit, :ptr DWORD
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IOleParentUndoUnitVtbl ends
        IOleParentUndoUnit struct
          lpVtbl POINTER ?
        IOleParentUndoUnit ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IOleParentUndoUnit_INTERFACE_DEFINED__ *
    endif
    ifndef __IEnumOleUndoUnits_INTERFACE_DEFINED__
      __IEnumOleUndoUnits_INTERFACE_DEFINED__ equ <>
      ;* interface IEnumOleUndoUnits *
      ;* [uuid][unique][object] *
      LPENUMOLEUNDOUNITS typedef ptr IEnumOleUndoUnits
      externdef IID_IEnumOleUndoUnits:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IEnumOleUndoUnitsVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IEnumOleUndoUnitsVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IEnumOleUndoUnits, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IEnumOleUndoUnits
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IEnumOleUndoUnits
          DECLSPEC_XFGVIRT(IEnumOleUndoUnits, Next)
          ;* [local] *
          ;* [in] *
          ;* [length_is][size_is][out] *
          STD_METHOD Next, :ptr IEnumOleUndoUnits, :ULONG, :ptr ptr IOleUndoUnit, :ptr ULONG
          ;* [out] *
          DECLSPEC_XFGVIRT(IEnumOleUndoUnits, Skip)
          STD_METHOD Skip, :ptr IEnumOleUndoUnits, :ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(IEnumOleUndoUnits, Reset)
          STD_METHOD Reset, :ptr IEnumOleUndoUnits
          DECLSPEC_XFGVIRT(IEnumOleUndoUnits, Clone)
          STD_METHOD Clone, :ptr IEnumOleUndoUnits, :ptr ptr IEnumOleUndoUnits
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IEnumOleUndoUnitsVtbl ends
        IEnumOleUndoUnits struct
          lpVtbl POINTER ?
        IEnumOleUndoUnits ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      IEnumOleUndoUnits_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumOleUndoUnits, :ULONG, :ptr ptr IOleUndoUnit, :ptr ULONG
      ;* [out] *
      IEnumOleUndoUnits_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __IEnumOleUndoUnits_INTERFACE_DEFINED__ *
    endif
    ifndef __IOleUndoManager_INTERFACE_DEFINED__
      __IOleUndoManager_INTERFACE_DEFINED__ equ <>
      ;* interface IOleUndoManager *
      ;* [uuid][unique][object] *
      SID_SOleUndoManager equ <IID_IOleUndoManager>
      LPOLEUNDOMANAGER typedef ptr IOleUndoManager
      externdef IID_IOleUndoManager:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IOleUndoManagerVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IOleUndoManagerVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IOleUndoManager, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IOleUndoManager
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IOleUndoManager
          DECLSPEC_XFGVIRT(IOleUndoManager, Open)
          STD_METHOD Open, :ptr IOleUndoManager, :ptr IOleParentUndoUnit
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleUndoManager, Close)
          ;* [in] *
          STD_METHOD Close, :ptr IOleUndoManager, :ptr IOleParentUndoUnit, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleUndoManager, Add)
          STD_METHOD Add_, :ptr IOleUndoManager, :ptr IOleUndoUnit
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleUndoManager, GetOpenParentState)
          STD_METHOD GetOpenParentState, :ptr IOleUndoManager, :ptr DWORD
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleUndoManager, DiscardFrom)
          STD_METHOD DiscardFrom, :ptr IOleUndoManager, :ptr IOleUndoUnit
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleUndoManager, UndoTo)
          STD_METHOD UndoTo, :ptr IOleUndoManager, :ptr IOleUndoUnit
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleUndoManager, RedoTo)
          STD_METHOD RedoTo, :ptr IOleUndoManager, :ptr IOleUndoUnit
          ;* [in] *
          DECLSPEC_XFGVIRT(IOleUndoManager, EnumUndoable)
          STD_METHOD EnumUndoable, :ptr IOleUndoManager, :ptr ptr IEnumOleUndoUnits
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleUndoManager, EnumRedoable)
          STD_METHOD EnumRedoable, :ptr IOleUndoManager, :ptr ptr IEnumOleUndoUnits
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleUndoManager, GetLastUndoDescription)
          STD_METHOD GetLastUndoDescription, :ptr IOleUndoManager, :ptr BSTR
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleUndoManager, GetLastRedoDescription)
          STD_METHOD GetLastRedoDescription, :ptr IOleUndoManager, :ptr BSTR
          ;* [out] *
          DECLSPEC_XFGVIRT(IOleUndoManager, Enable)
          STD_METHOD Enable, :ptr IOleUndoManager, :BOOL
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IOleUndoManagerVtbl ends
        IOleUndoManager struct
          lpVtbl POINTER ?
        IOleUndoManager ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IOleUndoManager_INTERFACE_DEFINED__ *
    endif
    ifndef __IPointerInactive_INTERFACE_DEFINED__
      __IPointerInactive_INTERFACE_DEFINED__ equ <>
      ;* interface IPointerInactive *
      ;* [uuid][unique][object] *
      LPPOINTERINACTIVE typedef ptr IPointerInactive
      ;* [v1_enum] *
      POINTERINACTIVE typedef SDWORD
      POINTERINACTIVE_ACTIVATEONENTRY equ 1
      POINTERINACTIVE_DEACTIVATEONLEAVE equ 2
      POINTERINACTIVE_ACTIVATEONDRAG equ 4
      tagPOINTERINACTIVE typedef POINTERINACTIVE

      externdef IID_IPointerInactive:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPointerInactiveVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPointerInactiveVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IPointerInactive, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPointerInactive
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPointerInactive
          DECLSPEC_XFGVIRT(IPointerInactive, GetActivationPolicy)
          STD_METHOD GetActivationPolicy, :ptr IPointerInactive, :ptr DWORD
          ;* [out] *
          DECLSPEC_XFGVIRT(IPointerInactive, OnInactiveMouseMove)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD OnInactiveMouseMove, :ptr IPointerInactive, :LPCRECT, :LONG, :LONG, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(IPointerInactive, OnInactiveSetCursor)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD OnInactiveSetCursor, :ptr IPointerInactive, :LPCRECT, :LONG, :LONG, :DWORD, :BOOL
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IPointerInactiveVtbl ends
        IPointerInactive struct
          lpVtbl POINTER ?
        IPointerInactive ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IPointerInactive_INTERFACE_DEFINED__ *
    endif
    ifndef __IObjectWithSite_INTERFACE_DEFINED__
      __IObjectWithSite_INTERFACE_DEFINED__ equ <>
      ;* interface IObjectWithSite *
      ;* [unique][uuid][object] *
      LPOBJECTWITHSITE typedef ptr IObjectWithSite
      externdef IID_IObjectWithSite:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IObjectWithSiteVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IObjectWithSiteVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IObjectWithSite, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IObjectWithSite
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IObjectWithSite
          DECLSPEC_XFGVIRT(IObjectWithSite, SetSite)
          STD_METHOD SetSite, :ptr IObjectWithSite, :ptr IUnknown
          ;* [in] *
          DECLSPEC_XFGVIRT(IObjectWithSite, GetSite)
          ;* [in] *
          STD_METHOD GetSite, :ptr IObjectWithSite, :REFIID, :ptr ptr
          ;* [iid_is][out] *
          ??Interface equ <>
          END_INTERFACE
        IObjectWithSiteVtbl ends
        IObjectWithSite struct
          lpVtbl POINTER ?
        IObjectWithSite ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IObjectWithSite_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_ocidl_0000_0036 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_ocidl_0000_0036_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_ocidl_0000_0036_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IPerPropertyBrowsing_INTERFACE_DEFINED__
      __IPerPropertyBrowsing_INTERFACE_DEFINED__ equ <>
      ;* interface IPerPropertyBrowsing *
      ;* [unique][uuid][object] *
      LPPERPROPERTYBROWSING typedef ptr IPerPropertyBrowsing
      CALPOLESTR struct
        cElems DWORD ?
        pElems POINTER ?
        ;* [size_is] *
      CALPOLESTR ends
      tagCALPOLESTR typedef CALPOLESTR
      LPCALPOLESTR typedef ptr tagCALPOLESTR
      CADWORD struct
        cElems DWORD ?
        pElems POINTER ?
        ;* [size_is] *
      CADWORD ends
      tagCADWORD typedef CADWORD
      LPCADWORD typedef ptr tagCADWORD
      externdef IID_IPerPropertyBrowsing:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPerPropertyBrowsingVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPerPropertyBrowsingVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IPerPropertyBrowsing, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPerPropertyBrowsing
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPerPropertyBrowsing
          DECLSPEC_XFGVIRT(IPerPropertyBrowsing, GetDisplayString)
          ;* [in] *
          STD_METHOD GetDisplayString, :ptr IPerPropertyBrowsing, :DISPID, :ptr BSTR
          ;* [out] *
          DECLSPEC_XFGVIRT(IPerPropertyBrowsing, MapPropertyToPage)
          ;* [in] *
          STD_METHOD MapPropertyToPage, :ptr IPerPropertyBrowsing, :DISPID, :ptr CLSID
          ;* [out] *
          DECLSPEC_XFGVIRT(IPerPropertyBrowsing, GetPredefinedStrings)
          ;* [in] *
          ;* [out] *
          STD_METHOD GetPredefinedStrings, :ptr IPerPropertyBrowsing, :DISPID, :ptr CALPOLESTR, :ptr CADWORD
          ;* [out] *
          DECLSPEC_XFGVIRT(IPerPropertyBrowsing, GetPredefinedValue)
          ;* [in] *
          ;* [in] *
          STD_METHOD GetPredefinedValue, :ptr IPerPropertyBrowsing, :DISPID, :DWORD, :ptr VARIANT
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IPerPropertyBrowsingVtbl ends
        IPerPropertyBrowsing struct
          lpVtbl POINTER ?
        IPerPropertyBrowsing ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IPerPropertyBrowsing_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_ocidl_0000_0037 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    externdef __MIDL_itf_ocidl_0000_0037_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_ocidl_0000_0037_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IPropertyBag2_INTERFACE_DEFINED__
      __IPropertyBag2_INTERFACE_DEFINED__ equ <>
      ;* interface IPropertyBag2 *
      ;* [unique][uuid][object] *
      LPPROPERTYBAG2 typedef ptr IPropertyBag2
      ;* [v1_enum] *
      PROPBAG2_TYPE typedef SDWORD
      PROPBAG2_TYPE_UNDEFINED equ 0
      PROPBAG2_TYPE_DATA equ 1
      PROPBAG2_TYPE_URL equ 2
      PROPBAG2_TYPE_OBJECT equ 3
      PROPBAG2_TYPE_STREAM equ 4
      PROPBAG2_TYPE_STORAGE equ 5
      PROPBAG2_TYPE_MONIKER equ 6
      tagPROPBAG2_TYPE typedef PROPBAG2_TYPE

      PROPBAG2 struct
        dwType DWORD ?
        vt VARTYPE ?
        cfType CLIPFORMAT ?
        dwHint DWORD ?
        pstrName LPOLESTR ?
        clsid CLSID <>
      PROPBAG2 ends
      tagPROPBAG2 typedef PROPBAG2
      externdef IID_IPropertyBag2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPropertyBag2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPropertyBag2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IPropertyBag2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPropertyBag2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPropertyBag2
          DECLSPEC_XFGVIRT(IPropertyBag2, Read)
          ;* [in] *
          ;* [size_is][in] *
          ;* [unique][in] *
          ;* [size_is][out] *
          STD_METHOD Read, :ptr IPropertyBag2, :ULONG, :ptr PROPBAG2, :ptr IErrorLog, :ptr VARIANT, :ptr HRESULT
          ;* [size_is][unique][out][in] *
          DECLSPEC_XFGVIRT(IPropertyBag2, Write)
          ;* [in] *
          ;* [size_is][in] *
          STD_METHOD Write, :ptr IPropertyBag2, :ULONG, :ptr PROPBAG2, :ptr VARIANT
          ;* [size_is][in] *
          DECLSPEC_XFGVIRT(IPropertyBag2, CountProperties)
          STD_METHOD CountProperties, :ptr IPropertyBag2, :ptr ULONG
          ;* [out] *
          DECLSPEC_XFGVIRT(IPropertyBag2, GetPropertyInfo)
          ;* [in] *
          ;* [in] *
          ;* [size_is][out] *
          STD_METHOD GetPropertyInfo, :ptr IPropertyBag2, :ULONG, :ULONG, :ptr PROPBAG2, :ptr ULONG
          ;* [out] *
          DECLSPEC_XFGVIRT(IPropertyBag2, LoadObject)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD LoadObject, :ptr IPropertyBag2, :LPCOLESTR, :DWORD, :ptr IUnknown, :ptr IErrorLog
          ;* [unique][in] *
          ??Interface equ <>
          END_INTERFACE
        IPropertyBag2Vtbl ends
        IPropertyBag2 struct
          lpVtbl POINTER ?
        IPropertyBag2 ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IPropertyBag2_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_ocidl_0000_0038 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_ocidl_0000_0038_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_ocidl_0000_0038_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IPersistPropertyBag2_INTERFACE_DEFINED__
      __IPersistPropertyBag2_INTERFACE_DEFINED__ equ <>
      ;* interface IPersistPropertyBag2 *
      ;* [unique][uuid][object] *
      LPPERSISTPROPERTYBAG2 typedef ptr IPersistPropertyBag2
      externdef IID_IPersistPropertyBag2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPersistPropertyBag2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPersistPropertyBag2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IPersistPropertyBag2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPersistPropertyBag2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPersistPropertyBag2
          DECLSPEC_XFGVIRT(IPersist, GetClassID)
          STD_METHOD GetClassID, :ptr IPersistPropertyBag2, :ptr CLSID
          ;* [out] *
          DECLSPEC_XFGVIRT(IPersistPropertyBag2, InitNew)
          STD_METHOD InitNew, :ptr IPersistPropertyBag2
          DECLSPEC_XFGVIRT(IPersistPropertyBag2, Load)
          ;* [in] *
          STD_METHOD Load, :ptr IPersistPropertyBag2, :ptr IPropertyBag2, :ptr IErrorLog
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IPersistPropertyBag2, Save)
          ;* [in] *
          ;* [in] *
          STD_METHOD Save, :ptr IPersistPropertyBag2, :ptr IPropertyBag2, :BOOL, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IPersistPropertyBag2, IsDirty)
          STD_METHOD IsDirty, :ptr IPersistPropertyBag2
          ??Interface equ <>
          END_INTERFACE
        IPersistPropertyBag2Vtbl ends
        IPersistPropertyBag2 struct
          lpVtbl POINTER ?
        IPersistPropertyBag2 ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IPersistPropertyBag2_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_ocidl_0000_0039 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_ocidl_0000_0039_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_ocidl_0000_0039_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IAdviseSinkEx_INTERFACE_DEFINED__
      __IAdviseSinkEx_INTERFACE_DEFINED__ equ <>
      ;* interface IAdviseSinkEx *
      ;* [uuid][unique][object] *
      LPADVISESINKEX typedef ptr IAdviseSinkEx
      externdef IID_IAdviseSinkEx:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IAdviseSinkExVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IAdviseSinkExVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IAdviseSinkEx, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IAdviseSinkEx
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IAdviseSinkEx
          DECLSPEC_XFGVIRT(IAdviseSink, OnDataChange)
          ;* [local] *
          ;* [annotation][unique][in] *
          ;* [annotation][unique][in] *
          STD_METHOD OnDataChange, :ptr IAdviseSinkEx, :ptr FORMATETC, :ptr STGMEDIUM
          DECLSPEC_XFGVIRT(IAdviseSink, OnViewChange)
          ;* [local] *
          ;* [in] *
          STD_METHOD OnViewChange, :ptr IAdviseSinkEx, :DWORD, :LONG
          ;* [in] *
          DECLSPEC_XFGVIRT(IAdviseSink, OnRename)
          ;* [local] *
          ;* [annotation][in] *
          STD_METHOD OnRename, :ptr IAdviseSinkEx, :ptr IMoniker
          DECLSPEC_XFGVIRT(IAdviseSink, OnSave)
          ;* [local] *
          STD_METHOD OnSave, :ptr IAdviseSinkEx
          DECLSPEC_XFGVIRT(IAdviseSink, OnClose)
          ;* [local] *
          STD_METHOD OnClose, :ptr IAdviseSinkEx
          DECLSPEC_XFGVIRT(IAdviseSinkEx, OnViewStatusChange)
          ;* [local] *
          STD_METHOD OnViewStatusChange, :ptr IAdviseSinkEx, :DWORD
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IAdviseSinkExVtbl ends
        IAdviseSinkEx struct
          lpVtbl POINTER ?
        IAdviseSinkEx ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      IAdviseSinkEx_RemoteOnViewStatusChange_Proxy proto WIN_STD_CALL_CONV :ptr IAdviseSinkEx, :DWORD
      ;* [in] *
      IAdviseSinkEx_RemoteOnViewStatusChange_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __IAdviseSinkEx_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_ocidl_0000_0040 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    externdef __MIDL_itf_ocidl_0000_0040_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_ocidl_0000_0040_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IQuickActivate_INTERFACE_DEFINED__
      __IQuickActivate_INTERFACE_DEFINED__ equ <>
      ;* interface IQuickActivate *
      ;* [uuid][unique][object] *
      LPQUICKACTIVATE typedef ptr IQuickActivate
      ;* [v1_enum] *
      QACONTAINERFLAGS typedef SDWORD
      QACONTAINER_SHOWHATCHING equ 1h
      QACONTAINER_SHOWGRABHANDLES equ 2h
      QACONTAINER_USERMODE equ 4h
      QACONTAINER_DISPLAYASDEFAULT equ 8h
      QACONTAINER_UIDEAD equ 10h
      QACONTAINER_AUTOCLIP equ 20h
      QACONTAINER_MESSAGEREFLECT equ 40h
      QACONTAINER_SUPPORTSMNEMONICS equ 80h
      tagQACONTAINERFLAGS typedef QACONTAINERFLAGS

      ;* [public][uuid] *
      DECLSPEC_UUID("66504301-BE0F-101A-8BBB-00AA00300CAB")
      OLE_COLOR typedef DWORD
      QACONTAINER struct
        cbSize DWORD ?
        pClientSite POINTER ?
        pAdviseSink POINTER ?
        pPropertyNotifySink POINTER ?
        pUnkEventSink POINTER ?
        dwAmbientFlags DWORD ?
        colorFore OLE_COLOR ?
        colorBack OLE_COLOR ?
        pFont POINTER ?
        pUndoMgr POINTER ?
        dwAppearance DWORD ?
        lcid SDWORD ?
        hpal HPALETTE ?
        pBindHost POINTER ?
        pOleControlSite POINTER ?
        pServiceProvider POINTER ?
      QACONTAINER ends
      tagQACONTAINER typedef QACONTAINER
      QACONTROL struct
        cbSize DWORD ?
        dwMiscStatus DWORD ?
        dwViewStatus DWORD ?
        dwEventCookie DWORD ?
        dwPropNotifyCookie DWORD ?
        dwPointerActivationPolicy DWORD ?
      QACONTROL ends
      tagQACONTROL typedef QACONTROL
      externdef IID_IQuickActivate:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IQuickActivateVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IQuickActivateVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IQuickActivate, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IQuickActivate
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IQuickActivate
          DECLSPEC_XFGVIRT(IQuickActivate, QuickActivate)
          ;* [local] *
          ;* [in] *
          STD_METHOD QuickActivate, :ptr IQuickActivate, :ptr QACONTAINER, :ptr QACONTROL
          ;* [out][in] *
          DECLSPEC_XFGVIRT(IQuickActivate, SetContentExtent)
          STD_METHOD SetContentExtent, :ptr IQuickActivate, :LPSIZEL
          ;* [in] *
          DECLSPEC_XFGVIRT(IQuickActivate, GetContentExtent)
          STD_METHOD GetContentExtent, :ptr IQuickActivate, :LPSIZEL
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IQuickActivateVtbl ends
        IQuickActivate struct
          lpVtbl POINTER ?
        IQuickActivate ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      IQuickActivate_RemoteQuickActivate_Proxy proto WIN_STD_CALL_CONV :ptr IQuickActivate, :ptr QACONTAINER, :ptr QACONTROL
      ;* [out] *
      IQuickActivate_RemoteQuickActivate_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __IQuickActivate_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_ocidl_0000_0041 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  if _MSC_VER ge 1200
  endif
  externdef __MIDL_itf_ocidl_0000_0041_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_ocidl_0000_0041_v0_0_s_ifspec:RPC_IF_HANDLE
  ;* Additional Prototypes for ALL interfaces *
  BSTR_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr BSTR
  BSTR_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BSTR
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
  HFONT_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HFONT
  HFONT_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HFONT
  HFONT_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HFONT
  HFONT_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HFONT
  HPALETTE_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HPALETTE
  HPALETTE_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HPALETTE
  HPALETTE_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HPALETTE
  HPALETTE_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HPALETTE
  HRGN_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HRGN
  HRGN_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HRGN
  HRGN_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HRGN
  HRGN_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HRGN
  HWND_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HWND
  HWND_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HWND
  HWND_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HWND
  HWND_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HWND
  VARIANT_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr VARIANT
  VARIANT_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr VARIANT
  VARIANT_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr VARIANT
  VARIANT_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr VARIANT
  BSTR_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr BSTR
  BSTR_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BSTR
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
  HFONT_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HFONT
  HFONT_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HFONT
  HFONT_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HFONT
  HFONT_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HFONT
  HPALETTE_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HPALETTE
  HPALETTE_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HPALETTE
  HPALETTE_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HPALETTE
  HPALETTE_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HPALETTE
  HRGN_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HRGN
  HRGN_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HRGN
  HRGN_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HRGN
  HRGN_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HRGN
  HWND_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HWND
  HWND_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HWND
  HWND_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HWND
  HWND_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HWND
  VARIANT_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr VARIANT
  VARIANT_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr VARIANT
  VARIANT_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr VARIANT
  VARIANT_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr VARIANT
  ;* [local] *
  IEnumConnections_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumConnections, :ULONG, :LPCONNECTDATA, :ptr ULONG
  ;* [out] *
  ;* [call_as] *
  IEnumConnections_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumConnections, :ULONG, :LPCONNECTDATA, :ptr ULONG
  ;* [out] *
  ;* [local] *
  IEnumConnectionPoints_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumConnectionPoints, :ULONG, :ptr LPCONNECTIONPOINT, :ptr ULONG
  ;* [out] *
  ;* [call_as] *
  IEnumConnectionPoints_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumConnectionPoints, :ULONG, :ptr LPCONNECTIONPOINT, :ptr ULONG
  ;* [out] *
  ;* [local] *
  IClassFactory2_CreateInstanceLic_Proxy proto WIN_STD_CALL_CONV :ptr IClassFactory2, :ptr IUnknown, :ptr IUnknown, :REFIID, :BSTR, :ptr PVOID
  ;* [annotation][iid_is][out] *
  ;* [call_as] *
  IClassFactory2_CreateInstanceLic_Stub proto WIN_STD_CALL_CONV :ptr IClassFactory2, :REFIID, :BSTR, :ptr ptr IUnknown
  ;* [iid_is][out] *
  ;* [local] *
  IPersistMemory_Load_Proxy proto WIN_STD_CALL_CONV :ptr IPersistMemory, :LPVOID, :ULONG
  ;* [in] *
  ;* [call_as] *
  IPersistMemory_Load_Stub proto WIN_STD_CALL_CONV :ptr IPersistMemory, :ptr BYTE, :ULONG
  ;* [in] *
  ;* [local] *
  IPersistMemory_Save_Proxy proto WIN_STD_CALL_CONV :ptr IPersistMemory, :LPVOID, :BOOL, :ULONG
  ;* [in] *
  ;* [call_as] *
  IPersistMemory_Save_Stub proto WIN_STD_CALL_CONV :ptr IPersistMemory, :ptr BYTE, :BOOL, :ULONG
  ;* [in] *
  ;* [local] *
  IEnumOleUndoUnits_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumOleUndoUnits, :ULONG, :ptr ptr IOleUndoUnit, :ptr ULONG
  ;* [out] *
  ;* [call_as] *
  IEnumOleUndoUnits_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumOleUndoUnits, :ULONG, :ptr ptr IOleUndoUnit, :ptr ULONG
  ;* [out] *
  ;* [local] *
  IAdviseSinkEx_OnViewStatusChange_Proxy proto WIN_STD_CALL_CONV :ptr IAdviseSinkEx, :DWORD
  ;* [in] *
  ;* [call_as] *
  IAdviseSinkEx_OnViewStatusChange_Stub proto WIN_STD_CALL_CONV :ptr IAdviseSinkEx, :DWORD
  ;* [in] *
  ;* [local] *
  IQuickActivate_QuickActivate_Proxy proto WIN_STD_CALL_CONV :ptr IQuickActivate, :ptr QACONTAINER, :ptr QACONTROL
  ;* [out][in] *
  ;* [call_as] *
  IQuickActivate_QuickActivate_Stub proto WIN_STD_CALL_CONV :ptr IQuickActivate, :ptr QACONTAINER, :ptr QACONTROL
  ;* [out] *
  ;* end of Additional Prototypes *
  ifdef __cplusplus
    ;[...]
  endif
endif
