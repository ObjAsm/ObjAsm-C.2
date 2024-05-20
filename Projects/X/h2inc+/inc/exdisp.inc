;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\exdisp.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 21/02/2024 18:15:30

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
ifndef __exdisp_h__
  __exdisp_h__ equ <>
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
  ifndef __IWebBrowser_FWD_DEFINED__
    __IWebBrowser_FWD_DEFINED__ equ <>
    ;* __IWebBrowser_FWD_DEFINED__ *
  endif
  ifndef __DWebBrowserEvents_FWD_DEFINED__
    __DWebBrowserEvents_FWD_DEFINED__ equ <>
    ;* __DWebBrowserEvents_FWD_DEFINED__ *
  endif
  ifndef __IWebBrowserApp_FWD_DEFINED__
    __IWebBrowserApp_FWD_DEFINED__ equ <>
    ;* __IWebBrowserApp_FWD_DEFINED__ *
  endif
  ifndef __IWebBrowser2_FWD_DEFINED__
    __IWebBrowser2_FWD_DEFINED__ equ <>
    ;* __IWebBrowser2_FWD_DEFINED__ *
  endif
  ifndef __DWebBrowserEvents2_FWD_DEFINED__
    __DWebBrowserEvents2_FWD_DEFINED__ equ <>
    ;* __DWebBrowserEvents2_FWD_DEFINED__ *
  endif
  ifndef __WebBrowser_V1_FWD_DEFINED__
    __WebBrowser_V1_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __WebBrowser_V1_FWD_DEFINED__ *
  endif
  ifndef __WebBrowser_FWD_DEFINED__
    __WebBrowser_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __WebBrowser_FWD_DEFINED__ *
  endif
  ifndef __InternetExplorer_FWD_DEFINED__
    __InternetExplorer_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __InternetExplorer_FWD_DEFINED__ *
  endif
  ifndef __InternetExplorerMedium_FWD_DEFINED__
    __InternetExplorerMedium_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __InternetExplorerMedium_FWD_DEFINED__ *
  endif
  ifndef __ShellBrowserWindow_FWD_DEFINED__
    __ShellBrowserWindow_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __ShellBrowserWindow_FWD_DEFINED__ *
  endif
  ifndef __DShellWindowsEvents_FWD_DEFINED__
    __DShellWindowsEvents_FWD_DEFINED__ equ <>
    ;* __DShellWindowsEvents_FWD_DEFINED__ *
  endif
  ifndef __IShellWindows_FWD_DEFINED__
    __IShellWindows_FWD_DEFINED__ equ <>
    ;* __IShellWindows_FWD_DEFINED__ *
  endif
  ifndef __ShellWindows_FWD_DEFINED__
    __ShellWindows_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __ShellWindows_FWD_DEFINED__ *
  endif
  ifndef __IShellUIHelper_FWD_DEFINED__
    __IShellUIHelper_FWD_DEFINED__ equ <>
    ;* __IShellUIHelper_FWD_DEFINED__ *
  endif
  ifndef __IShellUIHelper2_FWD_DEFINED__
    __IShellUIHelper2_FWD_DEFINED__ equ <>
    ;* __IShellUIHelper2_FWD_DEFINED__ *
  endif
  ifndef __IShellUIHelper3_FWD_DEFINED__
    __IShellUIHelper3_FWD_DEFINED__ equ <>
    ;* __IShellUIHelper3_FWD_DEFINED__ *
  endif
  ifndef __IShellUIHelper4_FWD_DEFINED__
    __IShellUIHelper4_FWD_DEFINED__ equ <>
    ;* __IShellUIHelper4_FWD_DEFINED__ *
  endif
  ifndef __IShellUIHelper5_FWD_DEFINED__
    __IShellUIHelper5_FWD_DEFINED__ equ <>
    ;* __IShellUIHelper5_FWD_DEFINED__ *
  endif
  ifndef __IShellUIHelper6_FWD_DEFINED__
    __IShellUIHelper6_FWD_DEFINED__ equ <>
    ;* __IShellUIHelper6_FWD_DEFINED__ *
  endif
  ifndef __IShellUIHelper7_FWD_DEFINED__
    __IShellUIHelper7_FWD_DEFINED__ equ <>
    ;* __IShellUIHelper7_FWD_DEFINED__ *
  endif
  ifndef __IShellUIHelper8_FWD_DEFINED__
    __IShellUIHelper8_FWD_DEFINED__ equ <>
    ;* __IShellUIHelper8_FWD_DEFINED__ *
  endif
  ifndef __IShellUIHelper9_FWD_DEFINED__
    __IShellUIHelper9_FWD_DEFINED__ equ <>
    ;* __IShellUIHelper9_FWD_DEFINED__ *
  endif
  ifndef __ShellUIHelper_FWD_DEFINED__
    __ShellUIHelper_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __ShellUIHelper_FWD_DEFINED__ *
  endif
  ifndef __DShellNameSpaceEvents_FWD_DEFINED__
    __DShellNameSpaceEvents_FWD_DEFINED__ equ <>
    ;* __DShellNameSpaceEvents_FWD_DEFINED__ *
  endif
  ifndef __IShellFavoritesNameSpace_FWD_DEFINED__
    __IShellFavoritesNameSpace_FWD_DEFINED__ equ <>
    ;* __IShellFavoritesNameSpace_FWD_DEFINED__ *
  endif
  ifndef __IShellNameSpace_FWD_DEFINED__
    __IShellNameSpace_FWD_DEFINED__ equ <>
    ;* __IShellNameSpace_FWD_DEFINED__ *
  endif
  ifndef __ShellNameSpace_FWD_DEFINED__
    __ShellNameSpace_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __ShellNameSpace_FWD_DEFINED__ *
  endif
  ifndef __IScriptErrorList_FWD_DEFINED__
    __IScriptErrorList_FWD_DEFINED__ equ <>
    ;* __IScriptErrorList_FWD_DEFINED__ *
  endif
  ifndef __CScriptErrorList_FWD_DEFINED__
    __CScriptErrorList_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __CScriptErrorList_FWD_DEFINED__ *
  endif
  ;* header files for imported files *
  include ocidl.inc
  include docobj.inc
  ifdef __cplusplus
    ;[...]
  endif
  ;* interface __MIDL_itf_exdisp_0000_0000 *
  ;* [local] *
  ;=--------------------------------------------------------------------------=
  ; exdisp.h
  ;=--------------------------------------------------------------------------=
  ; (C) Copyright Microsoft Corporation.  All Rights Reserved.
  ; THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
  ; ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
  ; THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
  ; PARTICULAR PURPOSE.
  ;=--------------------------------------------------------------------------=
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    SID_SkipHung equ <IID_IEnumVARIANT>
    externdef __MIDL_itf_exdisp_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_exdisp_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __SHDocVw_LIBRARY_DEFINED__
      __SHDocVw_LIBRARY_DEFINED__ equ <>
      ;* library SHDocVw *
      ;* [version][lcid][helpstring][uuid] *
      ;* [helpstring][uuid] *
      DECLSPEC_UUID("34A226E0-DF30-11CF-89A9-00A0C9054129")
      CommandStateChangeConstants typedef SDWORD
      CSC_UPDATECOMMANDS equ 0ffffffffh
      CSC_NAVIGATEFORWARD equ 1h
      CSC_NAVIGATEBACK equ 2h

      ;* [helpstring][uuid] *
      DECLSPEC_UUID("65507BE0-91A8-11d3-A845-009027220E6D")
      SecureLockIconConstants typedef SDWORD
      secureLockIconUnsecure equ 0
      secureLockIconMixed equ 1h
      secureLockIconSecureUnknownBits equ 2h
      secureLockIconSecure40Bit equ 3h
      secureLockIconSecure56Bit equ 4h
      secureLockIconSecureFortezza equ 5h
      secureLockIconSecure128Bit equ 6h

      ;* [helpstring][uuid] *
      DECLSPEC_UUID("a8317d46-03cb-4975-ae94-85e9f2e1d020")
      NewProcessCauseConstants typedef SDWORD
      ProtectedModeRedirect equ 1h

      ;* [helpstring][uuid] *
      DECLSPEC_UUID("F41E6981-28E5-11d0-82B4-00A0C90C29C5")
      ShellWindowTypeConstants typedef SDWORD
      SWC_EXPLORER equ 0
      SWC_BROWSER equ 1h
      SWC_3RDPARTY equ 2h
      SWC_CALLBACK equ 4h
      SWC_DESKTOP equ 8h

      ;* [hidden][helpstring][uuid] *
      DECLSPEC_UUID("7716a370-38ca-11d0-a48b-00a0c90a8f39")
      ShellWindowFindWindowOptions typedef SDWORD
      SWFO_NEEDDISPATCH equ 1h
      SWFO_INCLUDEPENDING equ 2h
      SWFO_COOKIEPASSED equ 4h

      externdef LIBID_SHDocVw:IID
      ifndef __IWebBrowser_INTERFACE_DEFINED__
        __IWebBrowser_INTERFACE_DEFINED__ equ <>
        ;* interface IWebBrowser *
        ;* [object][oleautomation][dual][hidden][helpcontext][helpstring][uuid] *
        ;* [helpstring][uuid] *
        DECLSPEC_UUID("14EE5380-A378-11cf-A731-00A0C9082637")
        BrowserNavConstants typedef SDWORD
        navOpenInNewWindow equ 1h
        navNoHistory equ 2h
        navNoReadFromCache equ 4h
        navNoWriteToCache equ 8h
        navAllowAutosearch equ 10h
        navBrowserBar equ 20h
        navHyperlink equ 40h
        navEnforceRestricted equ 80h
        navNewWindowsManaged equ 100h
        navUntrustedForDownload equ 200h
        navTrustedForActiveX equ 400h
        navOpenInNewTab equ 800h
        navOpenInBackgroundTab equ 1000h
        navKeepWordWheelText equ 2000h
        navVirtualTab equ 4000h
        navBlockRedirectsXDomain equ 8000h
        navOpenNewForegroundTab equ 10000h
        navTravelLogScreenshot equ 20000h
        navDeferUnload equ 40000h
        navSpeculative equ 80000h
        navSuggestNewWindow equ 100000h
        navSuggestNewTab equ 200000h
        navReserved1 equ 400000h
        navHomepageNavigate equ 800000h
        navRefresh equ 1000000h
        navHostNavigation equ 2000000h
        navReserved2 equ 4000000h
        navReserved3 equ 8000000h
        navReserved4 equ 10000000h
        navReserved5 equ 20000000h
        navReserved6 equ 40000000h
        navReserved7 equ 80000000h

        ;;begin_internal
        navUserInitiatedAction equ <navReserved1>
        navDisableDownloadSave equ <navReserved2>
        navServerRedirectedVtabSwitch equ <navReserved3>
        navVtabSwitchNotUserInitiatedAction equ <navReserved4>
        navCheckDontShowNeedIE equ <navReserved5>
        navCheckDontShowNeedHVSI equ <navReserved6>
        navCheckDontShowHVSINeedHost equ <navReserved7>
        ;;end_internal
        ;* [helpstring][uuid] *
        DECLSPEC_UUID("C317C261-A991-11cf-A731-00A0C9082637")
        RefreshConstants typedef SDWORD
        REFRESH_NORMAL equ 0
        REFRESH_IFEXPIRED equ 1
        REFRESH_COMPLETELY equ 3

        externdef IID_IWebBrowser:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IWebBrowserVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IWebBrowserVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IWebBrowser, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IWebBrowser
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IWebBrowser
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IWebBrowser, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr IWebBrowser, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr IWebBrowser, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
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
            STD_METHOD Invoke_, :ptr IWebBrowser, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IWebBrowser, GoBack)
            ;* [helpcontext][helpstring][id] *
            STD_METHOD GoBack, :ptr IWebBrowser
            DECLSPEC_XFGVIRT(IWebBrowser, GoForward)
            ;* [helpcontext][helpstring][id] *
            STD_METHOD GoForward, :ptr IWebBrowser
            DECLSPEC_XFGVIRT(IWebBrowser, GoHome)
            ;* [helpcontext][helpstring][id] *
            STD_METHOD GoHome, :ptr IWebBrowser
            DECLSPEC_XFGVIRT(IWebBrowser, GoSearch)
            ;* [helpcontext][helpstring][id] *
            STD_METHOD GoSearch, :ptr IWebBrowser
            DECLSPEC_XFGVIRT(IWebBrowser, Navigate)
            ;* [helpcontext][helpstring][id] *
            ;* [in] *
            ;* [unique][optional][in] *
            ;* [unique][optional][in] *
            ;* [unique][optional][in] *
            STD_METHOD Navigate, :ptr IWebBrowser, :BSTR, :ptr VARIANT, :ptr VARIANT, :ptr VARIANT, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IWebBrowser, Refresh)
            ;* [helpcontext][helpstring][id] *
            STD_METHOD Refresh, :ptr IWebBrowser
            DECLSPEC_XFGVIRT(IWebBrowser, Refresh2)
            ;* [helpcontext][helpstring][id] *
            STD_METHOD Refresh2, :ptr IWebBrowser, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IWebBrowser, Stop)
            ;* [helpcontext][helpstring][id] *
            STD_METHOD Stop, :ptr IWebBrowser
            DECLSPEC_XFGVIRT(IWebBrowser, get_Application)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Application, :ptr IWebBrowser, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_Parent)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Parent, :ptr IWebBrowser, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_Container)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Container, :ptr IWebBrowser, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_Document)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Document, :ptr IWebBrowser, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_TopLevelContainer)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_TopLevelContainer, :ptr IWebBrowser, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_Type)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Type, :ptr IWebBrowser, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_Left)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Left, :ptr IWebBrowser, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, put_Left)
            ;* [propput][id] *
            STD_METHOD put_Left, :ptr IWebBrowser, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_Top)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Top, :ptr IWebBrowser, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, put_Top)
            ;* [propput][id] *
            STD_METHOD put_Top, :ptr IWebBrowser, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_Width)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Width, :ptr IWebBrowser, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, put_Width)
            ;* [propput][id] *
            STD_METHOD put_Width, :ptr IWebBrowser, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_Height)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Height, :ptr IWebBrowser, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, put_Height)
            ;* [propput][id] *
            STD_METHOD put_Height, :ptr IWebBrowser, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_LocationName)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_LocationName, :ptr IWebBrowser, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_LocationURL)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_LocationURL, :ptr IWebBrowser, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_Busy)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Busy, :ptr IWebBrowser, :ptr VARIANT_BOOL
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          IWebBrowserVtbl ends
          IWebBrowser struct
            lpVtbl POINTER ?
          IWebBrowser ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IWebBrowser_INTERFACE_DEFINED__ *
      endif
      ifndef __DWebBrowserEvents_DISPINTERFACE_DEFINED__
        __DWebBrowserEvents_DISPINTERFACE_DEFINED__ equ <>
        ;* dispinterface DWebBrowserEvents *
        ;* [hidden][helpstring][uuid] *
        externdef DIID_DWebBrowserEvents:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          DWebBrowserEventsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <DWebBrowserEventsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr DWebBrowserEvents, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr DWebBrowserEvents
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr DWebBrowserEvents
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr DWebBrowserEvents, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr DWebBrowserEvents, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr DWebBrowserEvents, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
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
            STD_METHOD Invoke_, :ptr DWebBrowserEvents, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            ??Interface equ <>
            END_INTERFACE
          DWebBrowserEventsVtbl ends
          DWebBrowserEvents struct
            lpVtbl POINTER ?
          DWebBrowserEvents ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __DWebBrowserEvents_DISPINTERFACE_DEFINED__ *
      endif
      ifndef __IWebBrowserApp_INTERFACE_DEFINED__
        __IWebBrowserApp_INTERFACE_DEFINED__ equ <>
        ;* interface IWebBrowserApp *
        ;* [object][dual][oleautomation][hidden][helpcontext][helpstring][uuid] *
        externdef IID_IWebBrowserApp:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IWebBrowserAppVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IWebBrowserAppVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IWebBrowserApp, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IWebBrowserApp
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IWebBrowserApp
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IWebBrowserApp, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr IWebBrowserApp, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr IWebBrowserApp, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
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
            STD_METHOD Invoke_, :ptr IWebBrowserApp, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IWebBrowser, GoBack)
            ;* [helpcontext][helpstring][id] *
            STD_METHOD GoBack, :ptr IWebBrowserApp
            DECLSPEC_XFGVIRT(IWebBrowser, GoForward)
            ;* [helpcontext][helpstring][id] *
            STD_METHOD GoForward, :ptr IWebBrowserApp
            DECLSPEC_XFGVIRT(IWebBrowser, GoHome)
            ;* [helpcontext][helpstring][id] *
            STD_METHOD GoHome, :ptr IWebBrowserApp
            DECLSPEC_XFGVIRT(IWebBrowser, GoSearch)
            ;* [helpcontext][helpstring][id] *
            STD_METHOD GoSearch, :ptr IWebBrowserApp
            DECLSPEC_XFGVIRT(IWebBrowser, Navigate)
            ;* [helpcontext][helpstring][id] *
            ;* [in] *
            ;* [unique][optional][in] *
            ;* [unique][optional][in] *
            ;* [unique][optional][in] *
            STD_METHOD Navigate, :ptr IWebBrowserApp, :BSTR, :ptr VARIANT, :ptr VARIANT, :ptr VARIANT, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IWebBrowser, Refresh)
            ;* [helpcontext][helpstring][id] *
            STD_METHOD Refresh, :ptr IWebBrowserApp
            DECLSPEC_XFGVIRT(IWebBrowser, Refresh2)
            ;* [helpcontext][helpstring][id] *
            STD_METHOD Refresh2, :ptr IWebBrowserApp, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IWebBrowser, Stop)
            ;* [helpcontext][helpstring][id] *
            STD_METHOD Stop, :ptr IWebBrowserApp
            DECLSPEC_XFGVIRT(IWebBrowser, get_Application)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Application, :ptr IWebBrowserApp, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_Parent)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Parent, :ptr IWebBrowserApp, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_Container)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Container, :ptr IWebBrowserApp, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_Document)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Document, :ptr IWebBrowserApp, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_TopLevelContainer)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_TopLevelContainer, :ptr IWebBrowserApp, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_Type)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Type, :ptr IWebBrowserApp, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_Left)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Left, :ptr IWebBrowserApp, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, put_Left)
            ;* [propput][id] *
            STD_METHOD put_Left, :ptr IWebBrowserApp, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_Top)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Top, :ptr IWebBrowserApp, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, put_Top)
            ;* [propput][id] *
            STD_METHOD put_Top, :ptr IWebBrowserApp, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_Width)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Width, :ptr IWebBrowserApp, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, put_Width)
            ;* [propput][id] *
            STD_METHOD put_Width, :ptr IWebBrowserApp, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_Height)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Height, :ptr IWebBrowserApp, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, put_Height)
            ;* [propput][id] *
            STD_METHOD put_Height, :ptr IWebBrowserApp, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_LocationName)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_LocationName, :ptr IWebBrowserApp, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_LocationURL)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_LocationURL, :ptr IWebBrowserApp, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_Busy)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Busy, :ptr IWebBrowserApp, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, Quit)
            ;* [helpcontext][helpstring][id] *
            STD_METHOD Quit, :ptr IWebBrowserApp
            DECLSPEC_XFGVIRT(IWebBrowserApp, ClientToWindow)
            ;* [helpcontext][helpstring][id] *
            ;* [out][in] *
            STD_METHOD ClientToWindow, :ptr IWebBrowserApp, :ptr SDWORD, :ptr SDWORD
            ;* [out][in] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, PutProperty)
            ;* [helpcontext][helpstring][id] *
            ;* [in] *
            STD_METHOD PutProperty, :ptr IWebBrowserApp, :BSTR, :VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, GetProperty)
            ;* [helpcontext][helpstring][id] *
            ;* [in] *
            STD_METHOD GetProperty, :ptr IWebBrowserApp, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, get_Name)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Name, :ptr IWebBrowserApp, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, get_HWND)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_HWND, :ptr IWebBrowserApp, :ptr SHANDLE_PTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, get_FullName)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_FullName, :ptr IWebBrowserApp, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, get_Path)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Path, :ptr IWebBrowserApp, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, get_Visible)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Visible, :ptr IWebBrowserApp, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, put_Visible)
            ;* [helpcontext][helpstring][propput][id] *
            STD_METHOD put_Visible, :ptr IWebBrowserApp, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, get_StatusBar)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_StatusBar, :ptr IWebBrowserApp, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, put_StatusBar)
            ;* [helpcontext][helpstring][propput][id] *
            STD_METHOD put_StatusBar, :ptr IWebBrowserApp, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, get_StatusText)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_StatusText, :ptr IWebBrowserApp, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, put_StatusText)
            ;* [helpcontext][helpstring][propput][id] *
            STD_METHOD put_StatusText, :ptr IWebBrowserApp, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, get_ToolBar)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_ToolBar, :ptr IWebBrowserApp, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, put_ToolBar)
            ;* [helpcontext][helpstring][propput][id] *
            STD_METHOD put_ToolBar, :ptr IWebBrowserApp, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, get_MenuBar)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_MenuBar, :ptr IWebBrowserApp, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, put_MenuBar)
            ;* [helpcontext][helpstring][propput][id] *
            STD_METHOD put_MenuBar, :ptr IWebBrowserApp, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, get_FullScreen)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_FullScreen, :ptr IWebBrowserApp, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, put_FullScreen)
            ;* [helpcontext][helpstring][propput][id] *
            STD_METHOD put_FullScreen, :ptr IWebBrowserApp, :VARIANT_BOOL
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IWebBrowserAppVtbl ends
          IWebBrowserApp struct
            lpVtbl POINTER ?
          IWebBrowserApp ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IWebBrowserApp_INTERFACE_DEFINED__ *
      endif
      ifndef __IWebBrowser2_INTERFACE_DEFINED__
        __IWebBrowser2_INTERFACE_DEFINED__ equ <>
        ;* interface IWebBrowser2 *
        ;* [object][dual][oleautomation][hidden][helpcontext][helpstring][uuid] *
        externdef IID_IWebBrowser2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IWebBrowser2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IWebBrowser2Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IWebBrowser2, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IWebBrowser2
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IWebBrowser2
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IWebBrowser2, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr IWebBrowser2, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr IWebBrowser2, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
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
            STD_METHOD Invoke_, :ptr IWebBrowser2, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IWebBrowser, GoBack)
            ;* [helpcontext][helpstring][id] *
            STD_METHOD GoBack, :ptr IWebBrowser2
            DECLSPEC_XFGVIRT(IWebBrowser, GoForward)
            ;* [helpcontext][helpstring][id] *
            STD_METHOD GoForward, :ptr IWebBrowser2
            DECLSPEC_XFGVIRT(IWebBrowser, GoHome)
            ;* [helpcontext][helpstring][id] *
            STD_METHOD GoHome, :ptr IWebBrowser2
            DECLSPEC_XFGVIRT(IWebBrowser, GoSearch)
            ;* [helpcontext][helpstring][id] *
            STD_METHOD GoSearch, :ptr IWebBrowser2
            DECLSPEC_XFGVIRT(IWebBrowser, Navigate)
            ;* [helpcontext][helpstring][id] *
            ;* [in] *
            ;* [unique][optional][in] *
            ;* [unique][optional][in] *
            ;* [unique][optional][in] *
            STD_METHOD Navigate, :ptr IWebBrowser2, :BSTR, :ptr VARIANT, :ptr VARIANT, :ptr VARIANT, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IWebBrowser, Refresh)
            ;* [helpcontext][helpstring][id] *
            STD_METHOD Refresh, :ptr IWebBrowser2
            DECLSPEC_XFGVIRT(IWebBrowser, Refresh2)
            ;* [helpcontext][helpstring][id] *
            STD_METHOD Refresh2, :ptr IWebBrowser2, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IWebBrowser, Stop)
            ;* [helpcontext][helpstring][id] *
            STD_METHOD Stop, :ptr IWebBrowser2
            DECLSPEC_XFGVIRT(IWebBrowser, get_Application)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Application, :ptr IWebBrowser2, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_Parent)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Parent, :ptr IWebBrowser2, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_Container)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Container, :ptr IWebBrowser2, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_Document)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Document, :ptr IWebBrowser2, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_TopLevelContainer)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_TopLevelContainer, :ptr IWebBrowser2, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_Type)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Type, :ptr IWebBrowser2, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_Left)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Left, :ptr IWebBrowser2, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, put_Left)
            ;* [propput][id] *
            STD_METHOD put_Left, :ptr IWebBrowser2, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_Top)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Top, :ptr IWebBrowser2, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, put_Top)
            ;* [propput][id] *
            STD_METHOD put_Top, :ptr IWebBrowser2, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_Width)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Width, :ptr IWebBrowser2, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, put_Width)
            ;* [propput][id] *
            STD_METHOD put_Width, :ptr IWebBrowser2, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_Height)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Height, :ptr IWebBrowser2, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, put_Height)
            ;* [propput][id] *
            STD_METHOD put_Height, :ptr IWebBrowser2, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_LocationName)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_LocationName, :ptr IWebBrowser2, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_LocationURL)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_LocationURL, :ptr IWebBrowser2, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser, get_Busy)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Busy, :ptr IWebBrowser2, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, Quit)
            ;* [helpcontext][helpstring][id] *
            STD_METHOD Quit, :ptr IWebBrowser2
            DECLSPEC_XFGVIRT(IWebBrowserApp, ClientToWindow)
            ;* [helpcontext][helpstring][id] *
            ;* [out][in] *
            STD_METHOD ClientToWindow, :ptr IWebBrowser2, :ptr SDWORD, :ptr SDWORD
            ;* [out][in] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, PutProperty)
            ;* [helpcontext][helpstring][id] *
            ;* [in] *
            STD_METHOD PutProperty, :ptr IWebBrowser2, :BSTR, :VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, GetProperty)
            ;* [helpcontext][helpstring][id] *
            ;* [in] *
            STD_METHOD GetProperty, :ptr IWebBrowser2, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, get_Name)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Name, :ptr IWebBrowser2, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, get_HWND)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_HWND, :ptr IWebBrowser2, :ptr SHANDLE_PTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, get_FullName)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_FullName, :ptr IWebBrowser2, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, get_Path)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Path, :ptr IWebBrowser2, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, get_Visible)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Visible, :ptr IWebBrowser2, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, put_Visible)
            ;* [helpcontext][helpstring][propput][id] *
            STD_METHOD put_Visible, :ptr IWebBrowser2, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, get_StatusBar)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_StatusBar, :ptr IWebBrowser2, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, put_StatusBar)
            ;* [helpcontext][helpstring][propput][id] *
            STD_METHOD put_StatusBar, :ptr IWebBrowser2, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, get_StatusText)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_StatusText, :ptr IWebBrowser2, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, put_StatusText)
            ;* [helpcontext][helpstring][propput][id] *
            STD_METHOD put_StatusText, :ptr IWebBrowser2, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, get_ToolBar)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_ToolBar, :ptr IWebBrowser2, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, put_ToolBar)
            ;* [helpcontext][helpstring][propput][id] *
            STD_METHOD put_ToolBar, :ptr IWebBrowser2, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, get_MenuBar)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_MenuBar, :ptr IWebBrowser2, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, put_MenuBar)
            ;* [helpcontext][helpstring][propput][id] *
            STD_METHOD put_MenuBar, :ptr IWebBrowser2, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, get_FullScreen)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_FullScreen, :ptr IWebBrowser2, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowserApp, put_FullScreen)
            ;* [helpcontext][helpstring][propput][id] *
            STD_METHOD put_FullScreen, :ptr IWebBrowser2, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebBrowser2, Navigate2)
            ;* [helpcontext][helpstring][id] *
            ;* [in] *
            ;* [unique][optional][in] *
            ;* [unique][optional][in] *
            ;* [unique][optional][in] *
            STD_METHOD Navigate2, :ptr IWebBrowser2, :ptr VARIANT, :ptr VARIANT, :ptr VARIANT, :ptr VARIANT, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IWebBrowser2, QueryStatusWB)
            ;* [helpcontext][helpstring][id] *
            ;* [in] *
            STD_METHOD QueryStatusWB, :ptr IWebBrowser2, :OLECMDID, :ptr OLECMDF
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser2, ExecWB)
            ;* [helpcontext][helpstring][id] *
            ;* [in] *
            ;* [in] *
            ;* [unique][optional][in] *
            STD_METHOD ExecWB, :ptr IWebBrowser2, :OLECMDID, :OLECMDEXECOPT, :ptr VARIANT, :ptr VARIANT
            ;* [unique][optional][out][in] *
            DECLSPEC_XFGVIRT(IWebBrowser2, ShowBrowserBar)
            ;* [helpcontext][helpstring][id] *
            ;* [in] *
            ;* [unique][optional][in] *
            STD_METHOD ShowBrowserBar, :ptr IWebBrowser2, :ptr VARIANT, :ptr VARIANT, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IWebBrowser2, get_ReadyState)
            ;* [bindable][propget][id] *
            STD_METHOD get_ReadyState, :ptr IWebBrowser2, :ptr READYSTATE
            ;* [out][retval] *
            DECLSPEC_XFGVIRT(IWebBrowser2, get_Offline)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Offline, :ptr IWebBrowser2, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser2, put_Offline)
            ;* [helpcontext][helpstring][propput][id] *
            STD_METHOD put_Offline, :ptr IWebBrowser2, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebBrowser2, get_Silent)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Silent, :ptr IWebBrowser2, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser2, put_Silent)
            ;* [helpcontext][helpstring][propput][id] *
            STD_METHOD put_Silent, :ptr IWebBrowser2, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebBrowser2, get_RegisterAsBrowser)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_RegisterAsBrowser, :ptr IWebBrowser2, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser2, put_RegisterAsBrowser)
            ;* [helpcontext][helpstring][propput][id] *
            STD_METHOD put_RegisterAsBrowser, :ptr IWebBrowser2, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebBrowser2, get_RegisterAsDropTarget)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_RegisterAsDropTarget, :ptr IWebBrowser2, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser2, put_RegisterAsDropTarget)
            ;* [helpcontext][helpstring][propput][id] *
            STD_METHOD put_RegisterAsDropTarget, :ptr IWebBrowser2, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebBrowser2, get_TheaterMode)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_TheaterMode, :ptr IWebBrowser2, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser2, put_TheaterMode)
            ;* [helpcontext][helpstring][propput][id] *
            STD_METHOD put_TheaterMode, :ptr IWebBrowser2, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebBrowser2, get_AddressBar)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_AddressBar, :ptr IWebBrowser2, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser2, put_AddressBar)
            ;* [helpcontext][helpstring][propput][id] *
            STD_METHOD put_AddressBar, :ptr IWebBrowser2, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IWebBrowser2, get_Resizable)
            ;* [helpcontext][helpstring][propget][id] *
            STD_METHOD get_Resizable, :ptr IWebBrowser2, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IWebBrowser2, put_Resizable)
            ;* [helpcontext][helpstring][propput][id] *
            STD_METHOD put_Resizable, :ptr IWebBrowser2, :VARIANT_BOOL
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IWebBrowser2Vtbl ends
          IWebBrowser2 struct
            lpVtbl POINTER ?
          IWebBrowser2 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IWebBrowser2_INTERFACE_DEFINED__ *
      endif
      ifndef __DWebBrowserEvents2_DISPINTERFACE_DEFINED__
        __DWebBrowserEvents2_DISPINTERFACE_DEFINED__ equ <>
        ;* dispinterface DWebBrowserEvents2 *
        ;* [hidden][helpstring][uuid] *
        externdef DIID_DWebBrowserEvents2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          DWebBrowserEvents2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <DWebBrowserEvents2Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr DWebBrowserEvents2, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr DWebBrowserEvents2
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr DWebBrowserEvents2
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr DWebBrowserEvents2, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr DWebBrowserEvents2, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr DWebBrowserEvents2, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
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
            STD_METHOD Invoke_, :ptr DWebBrowserEvents2, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            ??Interface equ <>
            END_INTERFACE
          DWebBrowserEvents2Vtbl ends
          DWebBrowserEvents2 struct
            lpVtbl POINTER ?
          DWebBrowserEvents2 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __DWebBrowserEvents2_DISPINTERFACE_DEFINED__ *
      endif
      externdef CLSID_WebBrowser_V1:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_WebBrowser:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_InternetExplorer:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_InternetExplorerMedium:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_ShellBrowserWindow:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      ifndef __DShellWindowsEvents_DISPINTERFACE_DEFINED__
        __DShellWindowsEvents_DISPINTERFACE_DEFINED__ equ <>
        ;* dispinterface DShellWindowsEvents *
        ;* [helpstring][uuid] *
        externdef DIID_DShellWindowsEvents:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          DShellWindowsEventsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <DShellWindowsEventsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr DShellWindowsEvents, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr DShellWindowsEvents
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr DShellWindowsEvents
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr DShellWindowsEvents, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr DShellWindowsEvents, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr DShellWindowsEvents, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
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
            STD_METHOD Invoke_, :ptr DShellWindowsEvents, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            ??Interface equ <>
            END_INTERFACE
          DShellWindowsEventsVtbl ends
          DShellWindowsEvents struct
            lpVtbl POINTER ?
          DShellWindowsEvents ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __DShellWindowsEvents_DISPINTERFACE_DEFINED__ *
      endif
      ifndef __IShellWindows_INTERFACE_DEFINED__
        __IShellWindows_INTERFACE_DEFINED__ equ <>
        ;* interface IShellWindows *
        ;* [object][dual][oleautomation][helpstring][uuid] *
        externdef IID_IShellWindows:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellWindowsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellWindowsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IShellWindows, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IShellWindows
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IShellWindows
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IShellWindows, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr IShellWindows, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr IShellWindows, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
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
            STD_METHOD Invoke_, :ptr IShellWindows, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IShellWindows, get_Count)
            ;* [helpstring][propget] *
            STD_METHOD get_Count, :ptr IShellWindows, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellWindows, Item)
            ;* [helpstring][id] *
            ;* [optional][in] *
            STD_METHOD Item, :ptr IShellWindows, :VARIANT, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellWindows, _NewEnum)
            ;* [helpstring][id] *
            STD_METHOD _NewEnum, :ptr IShellWindows, :ptr ptr IUnknown
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellWindows, Register)
            ;* [hidden][helpstring] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD Register, :ptr IShellWindows, :ptr IDispatch, :SDWORD, :SDWORD, :ptr SDWORD
            ;* [out] *
            DECLSPEC_XFGVIRT(IShellWindows, RegisterPending)
            ;* [hidden][helpstring] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD RegisterPending, :ptr IShellWindows, :SDWORD, :ptr VARIANT, :ptr VARIANT, :SDWORD, :ptr SDWORD
            ;* [out] *
            DECLSPEC_XFGVIRT(IShellWindows, Revoke)
            ;* [hidden][helpstring] *
            STD_METHOD Revoke, :ptr IShellWindows, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellWindows, OnNavigate)
            ;* [hidden][helpstring] *
            ;* [in] *
            STD_METHOD OnNavigate, :ptr IShellWindows, :SDWORD, :ptr VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellWindows, OnActivated)
            ;* [hidden][helpstring] *
            ;* [in] *
            STD_METHOD OnActivated, :ptr IShellWindows, :SDWORD, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellWindows, FindWindowSW)
            ;* [hidden][helpstring] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            ;* [out] *
            ;* [in] *
            STD_METHOD FindWindowSW, :ptr IShellWindows, :ptr VARIANT, :ptr VARIANT, :SDWORD, :ptr SDWORD, :SDWORD, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellWindows, OnCreated)
            ;* [hidden][helpstring] *
            ;* [in] *
            STD_METHOD OnCreated, :ptr IShellWindows, :SDWORD, :ptr IUnknown
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellWindows, ProcessAttachDetach)
            ;* [hidden][helpstring] *
            STD_METHOD ProcessAttachDetach, :ptr IShellWindows, :VARIANT_BOOL
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IShellWindowsVtbl ends
          IShellWindows struct
            lpVtbl POINTER ?
          IShellWindows ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IShellWindows_INTERFACE_DEFINED__ *
      endif
      externdef CLSID_ShellWindows:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      ifndef __IShellUIHelper_INTERFACE_DEFINED__
        __IShellUIHelper_INTERFACE_DEFINED__ equ <>
        ;* interface IShellUIHelper *
        ;* [object][dual][oleautomation][helpstring][uuid] *
        externdef IID_IShellUIHelper:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellUIHelperVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellUIHelperVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IShellUIHelper, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IShellUIHelper
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IShellUIHelper
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IShellUIHelper, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr IShellUIHelper, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr IShellUIHelper, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
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
            STD_METHOD Invoke_, :ptr IShellUIHelper, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IShellUIHelper, ResetFirstBootMode)
            ;* [id][hidden] *
            STD_METHOD ResetFirstBootMode, :ptr IShellUIHelper
            DECLSPEC_XFGVIRT(IShellUIHelper, ResetSafeMode)
            ;* [id][hidden] *
            STD_METHOD ResetSafeMode, :ptr IShellUIHelper
            DECLSPEC_XFGVIRT(IShellUIHelper, RefreshOfflineDesktop)
            ;* [id][hidden] *
            STD_METHOD RefreshOfflineDesktop, :ptr IShellUIHelper
            DECLSPEC_XFGVIRT(IShellUIHelper, AddFavorite)
            ;* [id] *
            ;* [in] *
            STD_METHOD AddFavorite, :ptr IShellUIHelper, :BSTR, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AddChannel)
            ;* [id] *
            STD_METHOD AddChannel, :ptr IShellUIHelper, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AddDesktopComponent)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            ;* [unique][optional][in] *
            ;* [unique][optional][in] *
            ;* [unique][optional][in] *
            STD_METHOD AddDesktopComponent, :ptr IShellUIHelper, :BSTR, :BSTR, :ptr VARIANT, :ptr VARIANT, :ptr VARIANT, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, IsSubscribed)
            ;* [id] *
            ;* [in] *
            STD_METHOD IsSubscribed, :ptr IShellUIHelper, :BSTR, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper, NavigateAndFind)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD NavigateAndFind, :ptr IShellUIHelper, :BSTR, :BSTR, :ptr VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, ImportExportFavorites)
            ;* [id] *
            ;* [in] *
            STD_METHOD ImportExportFavorites, :ptr IShellUIHelper, :VARIANT_BOOL, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AutoCompleteSaveForm)
            ;* [id] *
            STD_METHOD AutoCompleteSaveForm, :ptr IShellUIHelper, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AutoScan)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD AutoScan, :ptr IShellUIHelper, :BSTR, :BSTR, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AutoCompleteAttach)
            ;* [id][hidden] *
            STD_METHOD AutoCompleteAttach, :ptr IShellUIHelper, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, ShowBrowserUI)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD ShowBrowserUI, :ptr IShellUIHelper, :BSTR, :ptr VARIANT, :ptr VARIANT
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          IShellUIHelperVtbl ends
          IShellUIHelper struct
            lpVtbl POINTER ?
          IShellUIHelper ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IShellUIHelper_INTERFACE_DEFINED__ *
      endif
      ifndef __IShellUIHelper2_INTERFACE_DEFINED__
        __IShellUIHelper2_INTERFACE_DEFINED__ equ <>
        ;* interface IShellUIHelper2 *
        ;* [object][dual][oleautomation][helpstring][uuid] *
        externdef IID_IShellUIHelper2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellUIHelper2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellUIHelper2Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IShellUIHelper2, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IShellUIHelper2
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IShellUIHelper2
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IShellUIHelper2, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr IShellUIHelper2, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr IShellUIHelper2, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
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
            STD_METHOD Invoke_, :ptr IShellUIHelper2, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IShellUIHelper, ResetFirstBootMode)
            ;* [id][hidden] *
            STD_METHOD ResetFirstBootMode, :ptr IShellUIHelper2
            DECLSPEC_XFGVIRT(IShellUIHelper, ResetSafeMode)
            ;* [id][hidden] *
            STD_METHOD ResetSafeMode, :ptr IShellUIHelper2
            DECLSPEC_XFGVIRT(IShellUIHelper, RefreshOfflineDesktop)
            ;* [id][hidden] *
            STD_METHOD RefreshOfflineDesktop, :ptr IShellUIHelper2
            DECLSPEC_XFGVIRT(IShellUIHelper, AddFavorite)
            ;* [id] *
            ;* [in] *
            STD_METHOD AddFavorite, :ptr IShellUIHelper2, :BSTR, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AddChannel)
            ;* [id] *
            STD_METHOD AddChannel, :ptr IShellUIHelper2, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AddDesktopComponent)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            ;* [unique][optional][in] *
            ;* [unique][optional][in] *
            ;* [unique][optional][in] *
            STD_METHOD AddDesktopComponent, :ptr IShellUIHelper2, :BSTR, :BSTR, :ptr VARIANT, :ptr VARIANT, :ptr VARIANT, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, IsSubscribed)
            ;* [id] *
            ;* [in] *
            STD_METHOD IsSubscribed, :ptr IShellUIHelper2, :BSTR, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper, NavigateAndFind)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD NavigateAndFind, :ptr IShellUIHelper2, :BSTR, :BSTR, :ptr VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, ImportExportFavorites)
            ;* [id] *
            ;* [in] *
            STD_METHOD ImportExportFavorites, :ptr IShellUIHelper2, :VARIANT_BOOL, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AutoCompleteSaveForm)
            ;* [id] *
            STD_METHOD AutoCompleteSaveForm, :ptr IShellUIHelper2, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AutoScan)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD AutoScan, :ptr IShellUIHelper2, :BSTR, :BSTR, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AutoCompleteAttach)
            ;* [id][hidden] *
            STD_METHOD AutoCompleteAttach, :ptr IShellUIHelper2, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, ShowBrowserUI)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD ShowBrowserUI, :ptr IShellUIHelper2, :BSTR, :ptr VARIANT, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, AddSearchProvider)
            ;* [id] *
            STD_METHOD AddSearchProvider, :ptr IShellUIHelper2, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, RunOnceShown)
            ;* [id] *
            STD_METHOD RunOnceShown, :ptr IShellUIHelper2
            DECLSPEC_XFGVIRT(IShellUIHelper2, SkipRunOnce)
            ;* [id] *
            STD_METHOD SkipRunOnce, :ptr IShellUIHelper2
            DECLSPEC_XFGVIRT(IShellUIHelper2, CustomizeSettings)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD CustomizeSettings, :ptr IShellUIHelper2, :VARIANT_BOOL, :VARIANT_BOOL, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, SqmEnabled)
            ;* [id] *
            STD_METHOD SqmEnabled, :ptr IShellUIHelper2, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, PhishingEnabled)
            ;* [id] *
            STD_METHOD PhishingEnabled, :ptr IShellUIHelper2, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, BrandImageUri)
            ;* [id] *
            STD_METHOD BrandImageUri, :ptr IShellUIHelper2, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, SkipTabsWelcome)
            ;* [id] *
            STD_METHOD SkipTabsWelcome, :ptr IShellUIHelper2
            DECLSPEC_XFGVIRT(IShellUIHelper2, DiagnoseConnection)
            ;* [id] *
            STD_METHOD DiagnoseConnection, :ptr IShellUIHelper2
            DECLSPEC_XFGVIRT(IShellUIHelper2, CustomizeClearType)
            ;* [id] *
            STD_METHOD CustomizeClearType, :ptr IShellUIHelper2, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, IsSearchProviderInstalled)
            ;* [id] *
            ;* [in] *
            STD_METHOD IsSearchProviderInstalled, :ptr IShellUIHelper2, :BSTR, :ptr DWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, IsSearchMigrated)
            ;* [id] *
            STD_METHOD IsSearchMigrated, :ptr IShellUIHelper2, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, DefaultSearchProvider)
            ;* [id] *
            STD_METHOD DefaultSearchProvider, :ptr IShellUIHelper2, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, RunOnceRequiredSettingsComplete)
            ;* [id] *
            STD_METHOD RunOnceRequiredSettingsComplete, :ptr IShellUIHelper2, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, RunOnceHasShown)
            ;* [id] *
            STD_METHOD RunOnceHasShown, :ptr IShellUIHelper2, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, SearchGuideUrl)
            ;* [id] *
            STD_METHOD SearchGuideUrl, :ptr IShellUIHelper2, :ptr BSTR
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          IShellUIHelper2Vtbl ends
          IShellUIHelper2 struct
            lpVtbl POINTER ?
          IShellUIHelper2 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IShellUIHelper2_INTERFACE_DEFINED__ *
      endif
      ifndef __IShellUIHelper3_INTERFACE_DEFINED__
        __IShellUIHelper3_INTERFACE_DEFINED__ equ <>
        ;* interface IShellUIHelper3 *
        ;* [object][dual][oleautomation][helpstring][uuid] *
        externdef IID_IShellUIHelper3:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellUIHelper3Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellUIHelper3Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IShellUIHelper3, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IShellUIHelper3
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IShellUIHelper3
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IShellUIHelper3, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr IShellUIHelper3, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr IShellUIHelper3, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
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
            STD_METHOD Invoke_, :ptr IShellUIHelper3, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IShellUIHelper, ResetFirstBootMode)
            ;* [id][hidden] *
            STD_METHOD ResetFirstBootMode, :ptr IShellUIHelper3
            DECLSPEC_XFGVIRT(IShellUIHelper, ResetSafeMode)
            ;* [id][hidden] *
            STD_METHOD ResetSafeMode, :ptr IShellUIHelper3
            DECLSPEC_XFGVIRT(IShellUIHelper, RefreshOfflineDesktop)
            ;* [id][hidden] *
            STD_METHOD RefreshOfflineDesktop, :ptr IShellUIHelper3
            DECLSPEC_XFGVIRT(IShellUIHelper, AddFavorite)
            ;* [id] *
            ;* [in] *
            STD_METHOD AddFavorite, :ptr IShellUIHelper3, :BSTR, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AddChannel)
            ;* [id] *
            STD_METHOD AddChannel, :ptr IShellUIHelper3, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AddDesktopComponent)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            ;* [unique][optional][in] *
            ;* [unique][optional][in] *
            ;* [unique][optional][in] *
            STD_METHOD AddDesktopComponent, :ptr IShellUIHelper3, :BSTR, :BSTR, :ptr VARIANT, :ptr VARIANT, :ptr VARIANT, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, IsSubscribed)
            ;* [id] *
            ;* [in] *
            STD_METHOD IsSubscribed, :ptr IShellUIHelper3, :BSTR, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper, NavigateAndFind)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD NavigateAndFind, :ptr IShellUIHelper3, :BSTR, :BSTR, :ptr VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, ImportExportFavorites)
            ;* [id] *
            ;* [in] *
            STD_METHOD ImportExportFavorites, :ptr IShellUIHelper3, :VARIANT_BOOL, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AutoCompleteSaveForm)
            ;* [id] *
            STD_METHOD AutoCompleteSaveForm, :ptr IShellUIHelper3, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AutoScan)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD AutoScan, :ptr IShellUIHelper3, :BSTR, :BSTR, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AutoCompleteAttach)
            ;* [id][hidden] *
            STD_METHOD AutoCompleteAttach, :ptr IShellUIHelper3, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, ShowBrowserUI)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD ShowBrowserUI, :ptr IShellUIHelper3, :BSTR, :ptr VARIANT, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, AddSearchProvider)
            ;* [id] *
            STD_METHOD AddSearchProvider, :ptr IShellUIHelper3, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, RunOnceShown)
            ;* [id] *
            STD_METHOD RunOnceShown, :ptr IShellUIHelper3
            DECLSPEC_XFGVIRT(IShellUIHelper2, SkipRunOnce)
            ;* [id] *
            STD_METHOD SkipRunOnce, :ptr IShellUIHelper3
            DECLSPEC_XFGVIRT(IShellUIHelper2, CustomizeSettings)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD CustomizeSettings, :ptr IShellUIHelper3, :VARIANT_BOOL, :VARIANT_BOOL, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, SqmEnabled)
            ;* [id] *
            STD_METHOD SqmEnabled, :ptr IShellUIHelper3, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, PhishingEnabled)
            ;* [id] *
            STD_METHOD PhishingEnabled, :ptr IShellUIHelper3, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, BrandImageUri)
            ;* [id] *
            STD_METHOD BrandImageUri, :ptr IShellUIHelper3, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, SkipTabsWelcome)
            ;* [id] *
            STD_METHOD SkipTabsWelcome, :ptr IShellUIHelper3
            DECLSPEC_XFGVIRT(IShellUIHelper2, DiagnoseConnection)
            ;* [id] *
            STD_METHOD DiagnoseConnection, :ptr IShellUIHelper3
            DECLSPEC_XFGVIRT(IShellUIHelper2, CustomizeClearType)
            ;* [id] *
            STD_METHOD CustomizeClearType, :ptr IShellUIHelper3, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, IsSearchProviderInstalled)
            ;* [id] *
            ;* [in] *
            STD_METHOD IsSearchProviderInstalled, :ptr IShellUIHelper3, :BSTR, :ptr DWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, IsSearchMigrated)
            ;* [id] *
            STD_METHOD IsSearchMigrated, :ptr IShellUIHelper3, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, DefaultSearchProvider)
            ;* [id] *
            STD_METHOD DefaultSearchProvider, :ptr IShellUIHelper3, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, RunOnceRequiredSettingsComplete)
            ;* [id] *
            STD_METHOD RunOnceRequiredSettingsComplete, :ptr IShellUIHelper3, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, RunOnceHasShown)
            ;* [id] *
            STD_METHOD RunOnceHasShown, :ptr IShellUIHelper3, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, SearchGuideUrl)
            ;* [id] *
            STD_METHOD SearchGuideUrl, :ptr IShellUIHelper3, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, AddService)
            ;* [id] *
            STD_METHOD AddService, :ptr IShellUIHelper3, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, IsServiceInstalled)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD IsServiceInstalled, :ptr IShellUIHelper3, :BSTR, :BSTR, :ptr DWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, InPrivateFilteringEnabled)
            ;* [id] *
            STD_METHOD InPrivateFilteringEnabled, :ptr IShellUIHelper3, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, AddToFavoritesBar)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD AddToFavoritesBar, :ptr IShellUIHelper3, :BSTR, :BSTR, :ptr VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, BuildNewTabPage)
            ;* [id] *
            STD_METHOD BuildNewTabPage, :ptr IShellUIHelper3
            DECLSPEC_XFGVIRT(IShellUIHelper3, SetRecentlyClosedVisible)
            ;* [id] *
            STD_METHOD SetRecentlyClosedVisible, :ptr IShellUIHelper3, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, SetActivitiesVisible)
            ;* [id] *
            STD_METHOD SetActivitiesVisible, :ptr IShellUIHelper3, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, ContentDiscoveryReset)
            ;* [id] *
            STD_METHOD ContentDiscoveryReset, :ptr IShellUIHelper3
            DECLSPEC_XFGVIRT(IShellUIHelper3, IsSuggestedSitesEnabled)
            ;* [id] *
            STD_METHOD IsSuggestedSitesEnabled, :ptr IShellUIHelper3, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, EnableSuggestedSites)
            ;* [id] *
            STD_METHOD EnableSuggestedSites, :ptr IShellUIHelper3, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, NavigateToSuggestedSites)
            ;* [id] *
            STD_METHOD NavigateToSuggestedSites, :ptr IShellUIHelper3, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, ShowTabsHelp)
            ;* [id] *
            STD_METHOD ShowTabsHelp, :ptr IShellUIHelper3
            DECLSPEC_XFGVIRT(IShellUIHelper3, ShowInPrivateHelp)
            ;* [id] *
            STD_METHOD ShowInPrivateHelp, :ptr IShellUIHelper3
            ??Interface equ <>
            END_INTERFACE
          IShellUIHelper3Vtbl ends
          IShellUIHelper3 struct
            lpVtbl POINTER ?
          IShellUIHelper3 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IShellUIHelper3_INTERFACE_DEFINED__ *
      endif
      ifndef __IShellUIHelper4_INTERFACE_DEFINED__
        __IShellUIHelper4_INTERFACE_DEFINED__ equ <>
        ;* interface IShellUIHelper4 *
        ;* [object][dual][oleautomation][helpstring][uuid] *
        externdef IID_IShellUIHelper4:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellUIHelper4Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellUIHelper4Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IShellUIHelper4, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IShellUIHelper4
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IShellUIHelper4
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IShellUIHelper4, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr IShellUIHelper4, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr IShellUIHelper4, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
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
            STD_METHOD Invoke_, :ptr IShellUIHelper4, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IShellUIHelper, ResetFirstBootMode)
            ;* [id][hidden] *
            STD_METHOD ResetFirstBootMode, :ptr IShellUIHelper4
            DECLSPEC_XFGVIRT(IShellUIHelper, ResetSafeMode)
            ;* [id][hidden] *
            STD_METHOD ResetSafeMode, :ptr IShellUIHelper4
            DECLSPEC_XFGVIRT(IShellUIHelper, RefreshOfflineDesktop)
            ;* [id][hidden] *
            STD_METHOD RefreshOfflineDesktop, :ptr IShellUIHelper4
            DECLSPEC_XFGVIRT(IShellUIHelper, AddFavorite)
            ;* [id] *
            ;* [in] *
            STD_METHOD AddFavorite, :ptr IShellUIHelper4, :BSTR, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AddChannel)
            ;* [id] *
            STD_METHOD AddChannel, :ptr IShellUIHelper4, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AddDesktopComponent)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            ;* [unique][optional][in] *
            ;* [unique][optional][in] *
            ;* [unique][optional][in] *
            STD_METHOD AddDesktopComponent, :ptr IShellUIHelper4, :BSTR, :BSTR, :ptr VARIANT, :ptr VARIANT, :ptr VARIANT, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, IsSubscribed)
            ;* [id] *
            ;* [in] *
            STD_METHOD IsSubscribed, :ptr IShellUIHelper4, :BSTR, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper, NavigateAndFind)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD NavigateAndFind, :ptr IShellUIHelper4, :BSTR, :BSTR, :ptr VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, ImportExportFavorites)
            ;* [id] *
            ;* [in] *
            STD_METHOD ImportExportFavorites, :ptr IShellUIHelper4, :VARIANT_BOOL, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AutoCompleteSaveForm)
            ;* [id] *
            STD_METHOD AutoCompleteSaveForm, :ptr IShellUIHelper4, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AutoScan)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD AutoScan, :ptr IShellUIHelper4, :BSTR, :BSTR, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AutoCompleteAttach)
            ;* [id][hidden] *
            STD_METHOD AutoCompleteAttach, :ptr IShellUIHelper4, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, ShowBrowserUI)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD ShowBrowserUI, :ptr IShellUIHelper4, :BSTR, :ptr VARIANT, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, AddSearchProvider)
            ;* [id] *
            STD_METHOD AddSearchProvider, :ptr IShellUIHelper4, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, RunOnceShown)
            ;* [id] *
            STD_METHOD RunOnceShown, :ptr IShellUIHelper4
            DECLSPEC_XFGVIRT(IShellUIHelper2, SkipRunOnce)
            ;* [id] *
            STD_METHOD SkipRunOnce, :ptr IShellUIHelper4
            DECLSPEC_XFGVIRT(IShellUIHelper2, CustomizeSettings)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD CustomizeSettings, :ptr IShellUIHelper4, :VARIANT_BOOL, :VARIANT_BOOL, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, SqmEnabled)
            ;* [id] *
            STD_METHOD SqmEnabled, :ptr IShellUIHelper4, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, PhishingEnabled)
            ;* [id] *
            STD_METHOD PhishingEnabled, :ptr IShellUIHelper4, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, BrandImageUri)
            ;* [id] *
            STD_METHOD BrandImageUri, :ptr IShellUIHelper4, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, SkipTabsWelcome)
            ;* [id] *
            STD_METHOD SkipTabsWelcome, :ptr IShellUIHelper4
            DECLSPEC_XFGVIRT(IShellUIHelper2, DiagnoseConnection)
            ;* [id] *
            STD_METHOD DiagnoseConnection, :ptr IShellUIHelper4
            DECLSPEC_XFGVIRT(IShellUIHelper2, CustomizeClearType)
            ;* [id] *
            STD_METHOD CustomizeClearType, :ptr IShellUIHelper4, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, IsSearchProviderInstalled)
            ;* [id] *
            ;* [in] *
            STD_METHOD IsSearchProviderInstalled, :ptr IShellUIHelper4, :BSTR, :ptr DWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, IsSearchMigrated)
            ;* [id] *
            STD_METHOD IsSearchMigrated, :ptr IShellUIHelper4, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, DefaultSearchProvider)
            ;* [id] *
            STD_METHOD DefaultSearchProvider, :ptr IShellUIHelper4, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, RunOnceRequiredSettingsComplete)
            ;* [id] *
            STD_METHOD RunOnceRequiredSettingsComplete, :ptr IShellUIHelper4, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, RunOnceHasShown)
            ;* [id] *
            STD_METHOD RunOnceHasShown, :ptr IShellUIHelper4, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, SearchGuideUrl)
            ;* [id] *
            STD_METHOD SearchGuideUrl, :ptr IShellUIHelper4, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, AddService)
            ;* [id] *
            STD_METHOD AddService, :ptr IShellUIHelper4, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, IsServiceInstalled)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD IsServiceInstalled, :ptr IShellUIHelper4, :BSTR, :BSTR, :ptr DWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, InPrivateFilteringEnabled)
            ;* [id] *
            STD_METHOD InPrivateFilteringEnabled, :ptr IShellUIHelper4, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, AddToFavoritesBar)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD AddToFavoritesBar, :ptr IShellUIHelper4, :BSTR, :BSTR, :ptr VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, BuildNewTabPage)
            ;* [id] *
            STD_METHOD BuildNewTabPage, :ptr IShellUIHelper4
            DECLSPEC_XFGVIRT(IShellUIHelper3, SetRecentlyClosedVisible)
            ;* [id] *
            STD_METHOD SetRecentlyClosedVisible, :ptr IShellUIHelper4, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, SetActivitiesVisible)
            ;* [id] *
            STD_METHOD SetActivitiesVisible, :ptr IShellUIHelper4, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, ContentDiscoveryReset)
            ;* [id] *
            STD_METHOD ContentDiscoveryReset, :ptr IShellUIHelper4
            DECLSPEC_XFGVIRT(IShellUIHelper3, IsSuggestedSitesEnabled)
            ;* [id] *
            STD_METHOD IsSuggestedSitesEnabled, :ptr IShellUIHelper4, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, EnableSuggestedSites)
            ;* [id] *
            STD_METHOD EnableSuggestedSites, :ptr IShellUIHelper4, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, NavigateToSuggestedSites)
            ;* [id] *
            STD_METHOD NavigateToSuggestedSites, :ptr IShellUIHelper4, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, ShowTabsHelp)
            ;* [id] *
            STD_METHOD ShowTabsHelp, :ptr IShellUIHelper4
            DECLSPEC_XFGVIRT(IShellUIHelper3, ShowInPrivateHelp)
            ;* [id] *
            STD_METHOD ShowInPrivateHelp, :ptr IShellUIHelper4
            DECLSPEC_XFGVIRT(IShellUIHelper4, msIsSiteMode)
            ;* [id] *
            STD_METHOD msIsSiteMode, :ptr IShellUIHelper4, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeShowThumbBar)
            ;* [id] *
            STD_METHOD msSiteModeShowThumbBar, :ptr IShellUIHelper4
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeAddThumbBarButton)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD msSiteModeAddThumbBarButton, :ptr IShellUIHelper4, :BSTR, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeUpdateThumbBarButton)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD msSiteModeUpdateThumbBarButton, :ptr IShellUIHelper4, :VARIANT, :VARIANT_BOOL, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeSetIconOverlay)
            ;* [id] *
            ;* [in] *
            STD_METHOD msSiteModeSetIconOverlay, :ptr IShellUIHelper4, :BSTR, :ptr VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeClearIconOverlay)
            ;* [id] *
            STD_METHOD msSiteModeClearIconOverlay, :ptr IShellUIHelper4
            DECLSPEC_XFGVIRT(IShellUIHelper4, msAddSiteMode)
            ;* [id] *
            STD_METHOD msAddSiteMode, :ptr IShellUIHelper4
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeCreateJumpList)
            ;* [id] *
            STD_METHOD msSiteModeCreateJumpList, :ptr IShellUIHelper4, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeAddJumpListItem)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD msSiteModeAddJumpListItem, :ptr IShellUIHelper4, :BSTR, :BSTR, :BSTR, :ptr VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeClearJumpList)
            ;* [id] *
            STD_METHOD msSiteModeClearJumpList, :ptr IShellUIHelper4
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeShowJumpList)
            ;* [id] *
            STD_METHOD msSiteModeShowJumpList, :ptr IShellUIHelper4
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeAddButtonStyle)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD msSiteModeAddButtonStyle, :ptr IShellUIHelper4, :VARIANT, :BSTR, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeShowButtonStyle)
            ;* [id] *
            ;* [in] *
            STD_METHOD msSiteModeShowButtonStyle, :ptr IShellUIHelper4, :VARIANT, :VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeActivate)
            ;* [id] *
            STD_METHOD msSiteModeActivate, :ptr IShellUIHelper4
            DECLSPEC_XFGVIRT(IShellUIHelper4, msIsSiteModeFirstRun)
            ;* [id] *
            ;* [in] *
            STD_METHOD msIsSiteModeFirstRun, :ptr IShellUIHelper4, :VARIANT_BOOL, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msAddTrackingProtectionList)
            ;* [id] *
            ;* [in] *
            STD_METHOD msAddTrackingProtectionList, :ptr IShellUIHelper4, :BSTR, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msTrackingProtectionEnabled)
            ;* [id] *
            STD_METHOD msTrackingProtectionEnabled, :ptr IShellUIHelper4, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msActiveXFilteringEnabled)
            ;* [id] *
            STD_METHOD msActiveXFilteringEnabled, :ptr IShellUIHelper4, :ptr VARIANT_BOOL
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          IShellUIHelper4Vtbl ends
          IShellUIHelper4 struct
            lpVtbl POINTER ?
          IShellUIHelper4 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IShellUIHelper4_INTERFACE_DEFINED__ *
      endif
      ifndef __IShellUIHelper5_INTERFACE_DEFINED__
        __IShellUIHelper5_INTERFACE_DEFINED__ equ <>
        ;* interface IShellUIHelper5 *
        ;* [object][dual][oleautomation][helpstring][uuid] *
        externdef IID_IShellUIHelper5:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellUIHelper5Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellUIHelper5Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IShellUIHelper5, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IShellUIHelper5
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IShellUIHelper5
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IShellUIHelper5, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr IShellUIHelper5, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr IShellUIHelper5, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
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
            STD_METHOD Invoke_, :ptr IShellUIHelper5, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IShellUIHelper, ResetFirstBootMode)
            ;* [id][hidden] *
            STD_METHOD ResetFirstBootMode, :ptr IShellUIHelper5
            DECLSPEC_XFGVIRT(IShellUIHelper, ResetSafeMode)
            ;* [id][hidden] *
            STD_METHOD ResetSafeMode, :ptr IShellUIHelper5
            DECLSPEC_XFGVIRT(IShellUIHelper, RefreshOfflineDesktop)
            ;* [id][hidden] *
            STD_METHOD RefreshOfflineDesktop, :ptr IShellUIHelper5
            DECLSPEC_XFGVIRT(IShellUIHelper, AddFavorite)
            ;* [id] *
            ;* [in] *
            STD_METHOD AddFavorite, :ptr IShellUIHelper5, :BSTR, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AddChannel)
            ;* [id] *
            STD_METHOD AddChannel, :ptr IShellUIHelper5, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AddDesktopComponent)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            ;* [unique][optional][in] *
            ;* [unique][optional][in] *
            ;* [unique][optional][in] *
            STD_METHOD AddDesktopComponent, :ptr IShellUIHelper5, :BSTR, :BSTR, :ptr VARIANT, :ptr VARIANT, :ptr VARIANT, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, IsSubscribed)
            ;* [id] *
            ;* [in] *
            STD_METHOD IsSubscribed, :ptr IShellUIHelper5, :BSTR, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper, NavigateAndFind)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD NavigateAndFind, :ptr IShellUIHelper5, :BSTR, :BSTR, :ptr VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, ImportExportFavorites)
            ;* [id] *
            ;* [in] *
            STD_METHOD ImportExportFavorites, :ptr IShellUIHelper5, :VARIANT_BOOL, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AutoCompleteSaveForm)
            ;* [id] *
            STD_METHOD AutoCompleteSaveForm, :ptr IShellUIHelper5, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AutoScan)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD AutoScan, :ptr IShellUIHelper5, :BSTR, :BSTR, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AutoCompleteAttach)
            ;* [id][hidden] *
            STD_METHOD AutoCompleteAttach, :ptr IShellUIHelper5, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, ShowBrowserUI)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD ShowBrowserUI, :ptr IShellUIHelper5, :BSTR, :ptr VARIANT, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, AddSearchProvider)
            ;* [id] *
            STD_METHOD AddSearchProvider, :ptr IShellUIHelper5, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, RunOnceShown)
            ;* [id] *
            STD_METHOD RunOnceShown, :ptr IShellUIHelper5
            DECLSPEC_XFGVIRT(IShellUIHelper2, SkipRunOnce)
            ;* [id] *
            STD_METHOD SkipRunOnce, :ptr IShellUIHelper5
            DECLSPEC_XFGVIRT(IShellUIHelper2, CustomizeSettings)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD CustomizeSettings, :ptr IShellUIHelper5, :VARIANT_BOOL, :VARIANT_BOOL, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, SqmEnabled)
            ;* [id] *
            STD_METHOD SqmEnabled, :ptr IShellUIHelper5, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, PhishingEnabled)
            ;* [id] *
            STD_METHOD PhishingEnabled, :ptr IShellUIHelper5, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, BrandImageUri)
            ;* [id] *
            STD_METHOD BrandImageUri, :ptr IShellUIHelper5, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, SkipTabsWelcome)
            ;* [id] *
            STD_METHOD SkipTabsWelcome, :ptr IShellUIHelper5
            DECLSPEC_XFGVIRT(IShellUIHelper2, DiagnoseConnection)
            ;* [id] *
            STD_METHOD DiagnoseConnection, :ptr IShellUIHelper5
            DECLSPEC_XFGVIRT(IShellUIHelper2, CustomizeClearType)
            ;* [id] *
            STD_METHOD CustomizeClearType, :ptr IShellUIHelper5, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, IsSearchProviderInstalled)
            ;* [id] *
            ;* [in] *
            STD_METHOD IsSearchProviderInstalled, :ptr IShellUIHelper5, :BSTR, :ptr DWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, IsSearchMigrated)
            ;* [id] *
            STD_METHOD IsSearchMigrated, :ptr IShellUIHelper5, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, DefaultSearchProvider)
            ;* [id] *
            STD_METHOD DefaultSearchProvider, :ptr IShellUIHelper5, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, RunOnceRequiredSettingsComplete)
            ;* [id] *
            STD_METHOD RunOnceRequiredSettingsComplete, :ptr IShellUIHelper5, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, RunOnceHasShown)
            ;* [id] *
            STD_METHOD RunOnceHasShown, :ptr IShellUIHelper5, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, SearchGuideUrl)
            ;* [id] *
            STD_METHOD SearchGuideUrl, :ptr IShellUIHelper5, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, AddService)
            ;* [id] *
            STD_METHOD AddService, :ptr IShellUIHelper5, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, IsServiceInstalled)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD IsServiceInstalled, :ptr IShellUIHelper5, :BSTR, :BSTR, :ptr DWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, InPrivateFilteringEnabled)
            ;* [id] *
            STD_METHOD InPrivateFilteringEnabled, :ptr IShellUIHelper5, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, AddToFavoritesBar)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD AddToFavoritesBar, :ptr IShellUIHelper5, :BSTR, :BSTR, :ptr VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, BuildNewTabPage)
            ;* [id] *
            STD_METHOD BuildNewTabPage, :ptr IShellUIHelper5
            DECLSPEC_XFGVIRT(IShellUIHelper3, SetRecentlyClosedVisible)
            ;* [id] *
            STD_METHOD SetRecentlyClosedVisible, :ptr IShellUIHelper5, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, SetActivitiesVisible)
            ;* [id] *
            STD_METHOD SetActivitiesVisible, :ptr IShellUIHelper5, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, ContentDiscoveryReset)
            ;* [id] *
            STD_METHOD ContentDiscoveryReset, :ptr IShellUIHelper5
            DECLSPEC_XFGVIRT(IShellUIHelper3, IsSuggestedSitesEnabled)
            ;* [id] *
            STD_METHOD IsSuggestedSitesEnabled, :ptr IShellUIHelper5, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, EnableSuggestedSites)
            ;* [id] *
            STD_METHOD EnableSuggestedSites, :ptr IShellUIHelper5, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, NavigateToSuggestedSites)
            ;* [id] *
            STD_METHOD NavigateToSuggestedSites, :ptr IShellUIHelper5, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, ShowTabsHelp)
            ;* [id] *
            STD_METHOD ShowTabsHelp, :ptr IShellUIHelper5
            DECLSPEC_XFGVIRT(IShellUIHelper3, ShowInPrivateHelp)
            ;* [id] *
            STD_METHOD ShowInPrivateHelp, :ptr IShellUIHelper5
            DECLSPEC_XFGVIRT(IShellUIHelper4, msIsSiteMode)
            ;* [id] *
            STD_METHOD msIsSiteMode, :ptr IShellUIHelper5, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeShowThumbBar)
            ;* [id] *
            STD_METHOD msSiteModeShowThumbBar, :ptr IShellUIHelper5
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeAddThumbBarButton)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD msSiteModeAddThumbBarButton, :ptr IShellUIHelper5, :BSTR, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeUpdateThumbBarButton)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD msSiteModeUpdateThumbBarButton, :ptr IShellUIHelper5, :VARIANT, :VARIANT_BOOL, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeSetIconOverlay)
            ;* [id] *
            ;* [in] *
            STD_METHOD msSiteModeSetIconOverlay, :ptr IShellUIHelper5, :BSTR, :ptr VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeClearIconOverlay)
            ;* [id] *
            STD_METHOD msSiteModeClearIconOverlay, :ptr IShellUIHelper5
            DECLSPEC_XFGVIRT(IShellUIHelper4, msAddSiteMode)
            ;* [id] *
            STD_METHOD msAddSiteMode, :ptr IShellUIHelper5
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeCreateJumpList)
            ;* [id] *
            STD_METHOD msSiteModeCreateJumpList, :ptr IShellUIHelper5, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeAddJumpListItem)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD msSiteModeAddJumpListItem, :ptr IShellUIHelper5, :BSTR, :BSTR, :BSTR, :ptr VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeClearJumpList)
            ;* [id] *
            STD_METHOD msSiteModeClearJumpList, :ptr IShellUIHelper5
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeShowJumpList)
            ;* [id] *
            STD_METHOD msSiteModeShowJumpList, :ptr IShellUIHelper5
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeAddButtonStyle)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD msSiteModeAddButtonStyle, :ptr IShellUIHelper5, :VARIANT, :BSTR, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeShowButtonStyle)
            ;* [id] *
            ;* [in] *
            STD_METHOD msSiteModeShowButtonStyle, :ptr IShellUIHelper5, :VARIANT, :VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeActivate)
            ;* [id] *
            STD_METHOD msSiteModeActivate, :ptr IShellUIHelper5
            DECLSPEC_XFGVIRT(IShellUIHelper4, msIsSiteModeFirstRun)
            ;* [id] *
            ;* [in] *
            STD_METHOD msIsSiteModeFirstRun, :ptr IShellUIHelper5, :VARIANT_BOOL, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msAddTrackingProtectionList)
            ;* [id] *
            ;* [in] *
            STD_METHOD msAddTrackingProtectionList, :ptr IShellUIHelper5, :BSTR, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msTrackingProtectionEnabled)
            ;* [id] *
            STD_METHOD msTrackingProtectionEnabled, :ptr IShellUIHelper5, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msActiveXFilteringEnabled)
            ;* [id] *
            STD_METHOD msActiveXFilteringEnabled, :ptr IShellUIHelper5, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper5, msProvisionNetworks)
            ;* [id] *
            ;* [in] *
            STD_METHOD msProvisionNetworks, :ptr IShellUIHelper5, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper5, msReportSafeUrl)
            ;* [id] *
            STD_METHOD msReportSafeUrl, :ptr IShellUIHelper5
            DECLSPEC_XFGVIRT(IShellUIHelper5, msSiteModeRefreshBadge)
            ;* [id] *
            STD_METHOD msSiteModeRefreshBadge, :ptr IShellUIHelper5
            DECLSPEC_XFGVIRT(IShellUIHelper5, msSiteModeClearBadge)
            ;* [id] *
            STD_METHOD msSiteModeClearBadge, :ptr IShellUIHelper5
            DECLSPEC_XFGVIRT(IShellUIHelper5, msDiagnoseConnectionUILess)
            ;* [id] *
            STD_METHOD msDiagnoseConnectionUILess, :ptr IShellUIHelper5
            DECLSPEC_XFGVIRT(IShellUIHelper5, msLaunchNetworkClientHelp)
            ;* [id] *
            STD_METHOD msLaunchNetworkClientHelp, :ptr IShellUIHelper5
            DECLSPEC_XFGVIRT(IShellUIHelper5, msChangeDefaultBrowser)
            ;* [id] *
            STD_METHOD msChangeDefaultBrowser, :ptr IShellUIHelper5, :VARIANT_BOOL
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IShellUIHelper5Vtbl ends
          IShellUIHelper5 struct
            lpVtbl POINTER ?
          IShellUIHelper5 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IShellUIHelper5_INTERFACE_DEFINED__ *
      endif
      ifndef __IShellUIHelper6_INTERFACE_DEFINED__
        __IShellUIHelper6_INTERFACE_DEFINED__ equ <>
        ;* interface IShellUIHelper6 *
        ;* [object][dual][oleautomation][helpstring][uuid] *
        externdef IID_IShellUIHelper6:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellUIHelper6Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellUIHelper6Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IShellUIHelper6, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IShellUIHelper6
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IShellUIHelper6
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IShellUIHelper6, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr IShellUIHelper6, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr IShellUIHelper6, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
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
            STD_METHOD Invoke_, :ptr IShellUIHelper6, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IShellUIHelper, ResetFirstBootMode)
            ;* [id][hidden] *
            STD_METHOD ResetFirstBootMode, :ptr IShellUIHelper6
            DECLSPEC_XFGVIRT(IShellUIHelper, ResetSafeMode)
            ;* [id][hidden] *
            STD_METHOD ResetSafeMode, :ptr IShellUIHelper6
            DECLSPEC_XFGVIRT(IShellUIHelper, RefreshOfflineDesktop)
            ;* [id][hidden] *
            STD_METHOD RefreshOfflineDesktop, :ptr IShellUIHelper6
            DECLSPEC_XFGVIRT(IShellUIHelper, AddFavorite)
            ;* [id] *
            ;* [in] *
            STD_METHOD AddFavorite, :ptr IShellUIHelper6, :BSTR, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AddChannel)
            ;* [id] *
            STD_METHOD AddChannel, :ptr IShellUIHelper6, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AddDesktopComponent)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            ;* [unique][optional][in] *
            ;* [unique][optional][in] *
            ;* [unique][optional][in] *
            STD_METHOD AddDesktopComponent, :ptr IShellUIHelper6, :BSTR, :BSTR, :ptr VARIANT, :ptr VARIANT, :ptr VARIANT, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, IsSubscribed)
            ;* [id] *
            ;* [in] *
            STD_METHOD IsSubscribed, :ptr IShellUIHelper6, :BSTR, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper, NavigateAndFind)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD NavigateAndFind, :ptr IShellUIHelper6, :BSTR, :BSTR, :ptr VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, ImportExportFavorites)
            ;* [id] *
            ;* [in] *
            STD_METHOD ImportExportFavorites, :ptr IShellUIHelper6, :VARIANT_BOOL, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AutoCompleteSaveForm)
            ;* [id] *
            STD_METHOD AutoCompleteSaveForm, :ptr IShellUIHelper6, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AutoScan)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD AutoScan, :ptr IShellUIHelper6, :BSTR, :BSTR, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AutoCompleteAttach)
            ;* [id][hidden] *
            STD_METHOD AutoCompleteAttach, :ptr IShellUIHelper6, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, ShowBrowserUI)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD ShowBrowserUI, :ptr IShellUIHelper6, :BSTR, :ptr VARIANT, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, AddSearchProvider)
            ;* [id] *
            STD_METHOD AddSearchProvider, :ptr IShellUIHelper6, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, RunOnceShown)
            ;* [id] *
            STD_METHOD RunOnceShown, :ptr IShellUIHelper6
            DECLSPEC_XFGVIRT(IShellUIHelper2, SkipRunOnce)
            ;* [id] *
            STD_METHOD SkipRunOnce, :ptr IShellUIHelper6
            DECLSPEC_XFGVIRT(IShellUIHelper2, CustomizeSettings)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD CustomizeSettings, :ptr IShellUIHelper6, :VARIANT_BOOL, :VARIANT_BOOL, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, SqmEnabled)
            ;* [id] *
            STD_METHOD SqmEnabled, :ptr IShellUIHelper6, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, PhishingEnabled)
            ;* [id] *
            STD_METHOD PhishingEnabled, :ptr IShellUIHelper6, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, BrandImageUri)
            ;* [id] *
            STD_METHOD BrandImageUri, :ptr IShellUIHelper6, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, SkipTabsWelcome)
            ;* [id] *
            STD_METHOD SkipTabsWelcome, :ptr IShellUIHelper6
            DECLSPEC_XFGVIRT(IShellUIHelper2, DiagnoseConnection)
            ;* [id] *
            STD_METHOD DiagnoseConnection, :ptr IShellUIHelper6
            DECLSPEC_XFGVIRT(IShellUIHelper2, CustomizeClearType)
            ;* [id] *
            STD_METHOD CustomizeClearType, :ptr IShellUIHelper6, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, IsSearchProviderInstalled)
            ;* [id] *
            ;* [in] *
            STD_METHOD IsSearchProviderInstalled, :ptr IShellUIHelper6, :BSTR, :ptr DWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, IsSearchMigrated)
            ;* [id] *
            STD_METHOD IsSearchMigrated, :ptr IShellUIHelper6, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, DefaultSearchProvider)
            ;* [id] *
            STD_METHOD DefaultSearchProvider, :ptr IShellUIHelper6, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, RunOnceRequiredSettingsComplete)
            ;* [id] *
            STD_METHOD RunOnceRequiredSettingsComplete, :ptr IShellUIHelper6, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, RunOnceHasShown)
            ;* [id] *
            STD_METHOD RunOnceHasShown, :ptr IShellUIHelper6, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, SearchGuideUrl)
            ;* [id] *
            STD_METHOD SearchGuideUrl, :ptr IShellUIHelper6, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, AddService)
            ;* [id] *
            STD_METHOD AddService, :ptr IShellUIHelper6, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, IsServiceInstalled)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD IsServiceInstalled, :ptr IShellUIHelper6, :BSTR, :BSTR, :ptr DWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, InPrivateFilteringEnabled)
            ;* [id] *
            STD_METHOD InPrivateFilteringEnabled, :ptr IShellUIHelper6, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, AddToFavoritesBar)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD AddToFavoritesBar, :ptr IShellUIHelper6, :BSTR, :BSTR, :ptr VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, BuildNewTabPage)
            ;* [id] *
            STD_METHOD BuildNewTabPage, :ptr IShellUIHelper6
            DECLSPEC_XFGVIRT(IShellUIHelper3, SetRecentlyClosedVisible)
            ;* [id] *
            STD_METHOD SetRecentlyClosedVisible, :ptr IShellUIHelper6, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, SetActivitiesVisible)
            ;* [id] *
            STD_METHOD SetActivitiesVisible, :ptr IShellUIHelper6, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, ContentDiscoveryReset)
            ;* [id] *
            STD_METHOD ContentDiscoveryReset, :ptr IShellUIHelper6
            DECLSPEC_XFGVIRT(IShellUIHelper3, IsSuggestedSitesEnabled)
            ;* [id] *
            STD_METHOD IsSuggestedSitesEnabled, :ptr IShellUIHelper6, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, EnableSuggestedSites)
            ;* [id] *
            STD_METHOD EnableSuggestedSites, :ptr IShellUIHelper6, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, NavigateToSuggestedSites)
            ;* [id] *
            STD_METHOD NavigateToSuggestedSites, :ptr IShellUIHelper6, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, ShowTabsHelp)
            ;* [id] *
            STD_METHOD ShowTabsHelp, :ptr IShellUIHelper6
            DECLSPEC_XFGVIRT(IShellUIHelper3, ShowInPrivateHelp)
            ;* [id] *
            STD_METHOD ShowInPrivateHelp, :ptr IShellUIHelper6
            DECLSPEC_XFGVIRT(IShellUIHelper4, msIsSiteMode)
            ;* [id] *
            STD_METHOD msIsSiteMode, :ptr IShellUIHelper6, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeShowThumbBar)
            ;* [id] *
            STD_METHOD msSiteModeShowThumbBar, :ptr IShellUIHelper6
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeAddThumbBarButton)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD msSiteModeAddThumbBarButton, :ptr IShellUIHelper6, :BSTR, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeUpdateThumbBarButton)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD msSiteModeUpdateThumbBarButton, :ptr IShellUIHelper6, :VARIANT, :VARIANT_BOOL, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeSetIconOverlay)
            ;* [id] *
            ;* [in] *
            STD_METHOD msSiteModeSetIconOverlay, :ptr IShellUIHelper6, :BSTR, :ptr VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeClearIconOverlay)
            ;* [id] *
            STD_METHOD msSiteModeClearIconOverlay, :ptr IShellUIHelper6
            DECLSPEC_XFGVIRT(IShellUIHelper4, msAddSiteMode)
            ;* [id] *
            STD_METHOD msAddSiteMode, :ptr IShellUIHelper6
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeCreateJumpList)
            ;* [id] *
            STD_METHOD msSiteModeCreateJumpList, :ptr IShellUIHelper6, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeAddJumpListItem)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD msSiteModeAddJumpListItem, :ptr IShellUIHelper6, :BSTR, :BSTR, :BSTR, :ptr VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeClearJumpList)
            ;* [id] *
            STD_METHOD msSiteModeClearJumpList, :ptr IShellUIHelper6
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeShowJumpList)
            ;* [id] *
            STD_METHOD msSiteModeShowJumpList, :ptr IShellUIHelper6
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeAddButtonStyle)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD msSiteModeAddButtonStyle, :ptr IShellUIHelper6, :VARIANT, :BSTR, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeShowButtonStyle)
            ;* [id] *
            ;* [in] *
            STD_METHOD msSiteModeShowButtonStyle, :ptr IShellUIHelper6, :VARIANT, :VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeActivate)
            ;* [id] *
            STD_METHOD msSiteModeActivate, :ptr IShellUIHelper6
            DECLSPEC_XFGVIRT(IShellUIHelper4, msIsSiteModeFirstRun)
            ;* [id] *
            ;* [in] *
            STD_METHOD msIsSiteModeFirstRun, :ptr IShellUIHelper6, :VARIANT_BOOL, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msAddTrackingProtectionList)
            ;* [id] *
            ;* [in] *
            STD_METHOD msAddTrackingProtectionList, :ptr IShellUIHelper6, :BSTR, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msTrackingProtectionEnabled)
            ;* [id] *
            STD_METHOD msTrackingProtectionEnabled, :ptr IShellUIHelper6, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msActiveXFilteringEnabled)
            ;* [id] *
            STD_METHOD msActiveXFilteringEnabled, :ptr IShellUIHelper6, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper5, msProvisionNetworks)
            ;* [id] *
            ;* [in] *
            STD_METHOD msProvisionNetworks, :ptr IShellUIHelper6, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper5, msReportSafeUrl)
            ;* [id] *
            STD_METHOD msReportSafeUrl, :ptr IShellUIHelper6
            DECLSPEC_XFGVIRT(IShellUIHelper5, msSiteModeRefreshBadge)
            ;* [id] *
            STD_METHOD msSiteModeRefreshBadge, :ptr IShellUIHelper6
            DECLSPEC_XFGVIRT(IShellUIHelper5, msSiteModeClearBadge)
            ;* [id] *
            STD_METHOD msSiteModeClearBadge, :ptr IShellUIHelper6
            DECLSPEC_XFGVIRT(IShellUIHelper5, msDiagnoseConnectionUILess)
            ;* [id] *
            STD_METHOD msDiagnoseConnectionUILess, :ptr IShellUIHelper6
            DECLSPEC_XFGVIRT(IShellUIHelper5, msLaunchNetworkClientHelp)
            ;* [id] *
            STD_METHOD msLaunchNetworkClientHelp, :ptr IShellUIHelper6
            DECLSPEC_XFGVIRT(IShellUIHelper5, msChangeDefaultBrowser)
            ;* [id] *
            STD_METHOD msChangeDefaultBrowser, :ptr IShellUIHelper6, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msStopPeriodicTileUpdate)
            ;* [id] *
            STD_METHOD msStopPeriodicTileUpdate, :ptr IShellUIHelper6
            DECLSPEC_XFGVIRT(IShellUIHelper6, msStartPeriodicTileUpdate)
            ;* [id] *
            ;* [in] *
            ;* [in][optional] *
            STD_METHOD msStartPeriodicTileUpdate, :ptr IShellUIHelper6, :VARIANT, :VARIANT, :VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msStartPeriodicTileUpdateBatch)
            ;* [id] *
            ;* [in] *
            ;* [in][optional] *
            STD_METHOD msStartPeriodicTileUpdateBatch, :ptr IShellUIHelper6, :VARIANT, :VARIANT, :VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msClearTile)
            ;* [id] *
            STD_METHOD msClearTile, :ptr IShellUIHelper6
            DECLSPEC_XFGVIRT(IShellUIHelper6, msEnableTileNotificationQueue)
            ;* [id] *
            STD_METHOD msEnableTileNotificationQueue, :ptr IShellUIHelper6, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msPinnedSiteState)
            ;* [id] *
            STD_METHOD msPinnedSiteState, :ptr IShellUIHelper6, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msEnableTileNotificationQueueForSquare150x150)
            ;* [id] *
            STD_METHOD msEnableTileNotificationQueueForSquare150x150, :ptr IShellUIHelper6, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msEnableTileNotificationQueueForWide310x150)
            ;* [id] *
            STD_METHOD msEnableTileNotificationQueueForWide310x150, :ptr IShellUIHelper6, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msEnableTileNotificationQueueForSquare310x310)
            ;* [id] *
            STD_METHOD msEnableTileNotificationQueueForSquare310x310, :ptr IShellUIHelper6, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msScheduledTileNotification)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            ;* [in][optional] *
            STD_METHOD msScheduledTileNotification, :ptr IShellUIHelper6, :BSTR, :BSTR, :BSTR, :VARIANT, :VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msRemoveScheduledTileNotification)
            ;* [id] *
            STD_METHOD msRemoveScheduledTileNotification, :ptr IShellUIHelper6, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msStartPeriodicBadgeUpdate)
            ;* [id] *
            ;* [in] *
            ;* [in][optional] *
            STD_METHOD msStartPeriodicBadgeUpdate, :ptr IShellUIHelper6, :BSTR, :VARIANT, :VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msStopPeriodicBadgeUpdate)
            ;* [id] *
            STD_METHOD msStopPeriodicBadgeUpdate, :ptr IShellUIHelper6
            DECLSPEC_XFGVIRT(IShellUIHelper6, msLaunchInternetOptions)
            ;* [id] *
            STD_METHOD msLaunchInternetOptions, :ptr IShellUIHelper6
            ??Interface equ <>
            END_INTERFACE
          IShellUIHelper6Vtbl ends
          IShellUIHelper6 struct
            lpVtbl POINTER ?
          IShellUIHelper6 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IShellUIHelper6_INTERFACE_DEFINED__ *
      endif
      ifndef __IShellUIHelper7_INTERFACE_DEFINED__
        __IShellUIHelper7_INTERFACE_DEFINED__ equ <>
        ;* interface IShellUIHelper7 *
        ;* [object][dual][oleautomation][helpstring][uuid] *
        externdef IID_IShellUIHelper7:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellUIHelper7Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellUIHelper7Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IShellUIHelper7, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IShellUIHelper7
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IShellUIHelper7
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IShellUIHelper7, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr IShellUIHelper7, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr IShellUIHelper7, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
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
            STD_METHOD Invoke_, :ptr IShellUIHelper7, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IShellUIHelper, ResetFirstBootMode)
            ;* [id][hidden] *
            STD_METHOD ResetFirstBootMode, :ptr IShellUIHelper7
            DECLSPEC_XFGVIRT(IShellUIHelper, ResetSafeMode)
            ;* [id][hidden] *
            STD_METHOD ResetSafeMode, :ptr IShellUIHelper7
            DECLSPEC_XFGVIRT(IShellUIHelper, RefreshOfflineDesktop)
            ;* [id][hidden] *
            STD_METHOD RefreshOfflineDesktop, :ptr IShellUIHelper7
            DECLSPEC_XFGVIRT(IShellUIHelper, AddFavorite)
            ;* [id] *
            ;* [in] *
            STD_METHOD AddFavorite, :ptr IShellUIHelper7, :BSTR, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AddChannel)
            ;* [id] *
            STD_METHOD AddChannel, :ptr IShellUIHelper7, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AddDesktopComponent)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            ;* [unique][optional][in] *
            ;* [unique][optional][in] *
            ;* [unique][optional][in] *
            STD_METHOD AddDesktopComponent, :ptr IShellUIHelper7, :BSTR, :BSTR, :ptr VARIANT, :ptr VARIANT, :ptr VARIANT, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, IsSubscribed)
            ;* [id] *
            ;* [in] *
            STD_METHOD IsSubscribed, :ptr IShellUIHelper7, :BSTR, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper, NavigateAndFind)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD NavigateAndFind, :ptr IShellUIHelper7, :BSTR, :BSTR, :ptr VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, ImportExportFavorites)
            ;* [id] *
            ;* [in] *
            STD_METHOD ImportExportFavorites, :ptr IShellUIHelper7, :VARIANT_BOOL, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AutoCompleteSaveForm)
            ;* [id] *
            STD_METHOD AutoCompleteSaveForm, :ptr IShellUIHelper7, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AutoScan)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD AutoScan, :ptr IShellUIHelper7, :BSTR, :BSTR, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AutoCompleteAttach)
            ;* [id][hidden] *
            STD_METHOD AutoCompleteAttach, :ptr IShellUIHelper7, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, ShowBrowserUI)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD ShowBrowserUI, :ptr IShellUIHelper7, :BSTR, :ptr VARIANT, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, AddSearchProvider)
            ;* [id] *
            STD_METHOD AddSearchProvider, :ptr IShellUIHelper7, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, RunOnceShown)
            ;* [id] *
            STD_METHOD RunOnceShown, :ptr IShellUIHelper7
            DECLSPEC_XFGVIRT(IShellUIHelper2, SkipRunOnce)
            ;* [id] *
            STD_METHOD SkipRunOnce, :ptr IShellUIHelper7
            DECLSPEC_XFGVIRT(IShellUIHelper2, CustomizeSettings)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD CustomizeSettings, :ptr IShellUIHelper7, :VARIANT_BOOL, :VARIANT_BOOL, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, SqmEnabled)
            ;* [id] *
            STD_METHOD SqmEnabled, :ptr IShellUIHelper7, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, PhishingEnabled)
            ;* [id] *
            STD_METHOD PhishingEnabled, :ptr IShellUIHelper7, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, BrandImageUri)
            ;* [id] *
            STD_METHOD BrandImageUri, :ptr IShellUIHelper7, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, SkipTabsWelcome)
            ;* [id] *
            STD_METHOD SkipTabsWelcome, :ptr IShellUIHelper7
            DECLSPEC_XFGVIRT(IShellUIHelper2, DiagnoseConnection)
            ;* [id] *
            STD_METHOD DiagnoseConnection, :ptr IShellUIHelper7
            DECLSPEC_XFGVIRT(IShellUIHelper2, CustomizeClearType)
            ;* [id] *
            STD_METHOD CustomizeClearType, :ptr IShellUIHelper7, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, IsSearchProviderInstalled)
            ;* [id] *
            ;* [in] *
            STD_METHOD IsSearchProviderInstalled, :ptr IShellUIHelper7, :BSTR, :ptr DWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, IsSearchMigrated)
            ;* [id] *
            STD_METHOD IsSearchMigrated, :ptr IShellUIHelper7, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, DefaultSearchProvider)
            ;* [id] *
            STD_METHOD DefaultSearchProvider, :ptr IShellUIHelper7, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, RunOnceRequiredSettingsComplete)
            ;* [id] *
            STD_METHOD RunOnceRequiredSettingsComplete, :ptr IShellUIHelper7, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, RunOnceHasShown)
            ;* [id] *
            STD_METHOD RunOnceHasShown, :ptr IShellUIHelper7, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, SearchGuideUrl)
            ;* [id] *
            STD_METHOD SearchGuideUrl, :ptr IShellUIHelper7, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, AddService)
            ;* [id] *
            STD_METHOD AddService, :ptr IShellUIHelper7, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, IsServiceInstalled)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD IsServiceInstalled, :ptr IShellUIHelper7, :BSTR, :BSTR, :ptr DWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, InPrivateFilteringEnabled)
            ;* [id] *
            STD_METHOD InPrivateFilteringEnabled, :ptr IShellUIHelper7, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, AddToFavoritesBar)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD AddToFavoritesBar, :ptr IShellUIHelper7, :BSTR, :BSTR, :ptr VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, BuildNewTabPage)
            ;* [id] *
            STD_METHOD BuildNewTabPage, :ptr IShellUIHelper7
            DECLSPEC_XFGVIRT(IShellUIHelper3, SetRecentlyClosedVisible)
            ;* [id] *
            STD_METHOD SetRecentlyClosedVisible, :ptr IShellUIHelper7, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, SetActivitiesVisible)
            ;* [id] *
            STD_METHOD SetActivitiesVisible, :ptr IShellUIHelper7, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, ContentDiscoveryReset)
            ;* [id] *
            STD_METHOD ContentDiscoveryReset, :ptr IShellUIHelper7
            DECLSPEC_XFGVIRT(IShellUIHelper3, IsSuggestedSitesEnabled)
            ;* [id] *
            STD_METHOD IsSuggestedSitesEnabled, :ptr IShellUIHelper7, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, EnableSuggestedSites)
            ;* [id] *
            STD_METHOD EnableSuggestedSites, :ptr IShellUIHelper7, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, NavigateToSuggestedSites)
            ;* [id] *
            STD_METHOD NavigateToSuggestedSites, :ptr IShellUIHelper7, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, ShowTabsHelp)
            ;* [id] *
            STD_METHOD ShowTabsHelp, :ptr IShellUIHelper7
            DECLSPEC_XFGVIRT(IShellUIHelper3, ShowInPrivateHelp)
            ;* [id] *
            STD_METHOD ShowInPrivateHelp, :ptr IShellUIHelper7
            DECLSPEC_XFGVIRT(IShellUIHelper4, msIsSiteMode)
            ;* [id] *
            STD_METHOD msIsSiteMode, :ptr IShellUIHelper7, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeShowThumbBar)
            ;* [id] *
            STD_METHOD msSiteModeShowThumbBar, :ptr IShellUIHelper7
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeAddThumbBarButton)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD msSiteModeAddThumbBarButton, :ptr IShellUIHelper7, :BSTR, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeUpdateThumbBarButton)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD msSiteModeUpdateThumbBarButton, :ptr IShellUIHelper7, :VARIANT, :VARIANT_BOOL, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeSetIconOverlay)
            ;* [id] *
            ;* [in] *
            STD_METHOD msSiteModeSetIconOverlay, :ptr IShellUIHelper7, :BSTR, :ptr VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeClearIconOverlay)
            ;* [id] *
            STD_METHOD msSiteModeClearIconOverlay, :ptr IShellUIHelper7
            DECLSPEC_XFGVIRT(IShellUIHelper4, msAddSiteMode)
            ;* [id] *
            STD_METHOD msAddSiteMode, :ptr IShellUIHelper7
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeCreateJumpList)
            ;* [id] *
            STD_METHOD msSiteModeCreateJumpList, :ptr IShellUIHelper7, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeAddJumpListItem)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD msSiteModeAddJumpListItem, :ptr IShellUIHelper7, :BSTR, :BSTR, :BSTR, :ptr VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeClearJumpList)
            ;* [id] *
            STD_METHOD msSiteModeClearJumpList, :ptr IShellUIHelper7
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeShowJumpList)
            ;* [id] *
            STD_METHOD msSiteModeShowJumpList, :ptr IShellUIHelper7
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeAddButtonStyle)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD msSiteModeAddButtonStyle, :ptr IShellUIHelper7, :VARIANT, :BSTR, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeShowButtonStyle)
            ;* [id] *
            ;* [in] *
            STD_METHOD msSiteModeShowButtonStyle, :ptr IShellUIHelper7, :VARIANT, :VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeActivate)
            ;* [id] *
            STD_METHOD msSiteModeActivate, :ptr IShellUIHelper7
            DECLSPEC_XFGVIRT(IShellUIHelper4, msIsSiteModeFirstRun)
            ;* [id] *
            ;* [in] *
            STD_METHOD msIsSiteModeFirstRun, :ptr IShellUIHelper7, :VARIANT_BOOL, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msAddTrackingProtectionList)
            ;* [id] *
            ;* [in] *
            STD_METHOD msAddTrackingProtectionList, :ptr IShellUIHelper7, :BSTR, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msTrackingProtectionEnabled)
            ;* [id] *
            STD_METHOD msTrackingProtectionEnabled, :ptr IShellUIHelper7, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msActiveXFilteringEnabled)
            ;* [id] *
            STD_METHOD msActiveXFilteringEnabled, :ptr IShellUIHelper7, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper5, msProvisionNetworks)
            ;* [id] *
            ;* [in] *
            STD_METHOD msProvisionNetworks, :ptr IShellUIHelper7, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper5, msReportSafeUrl)
            ;* [id] *
            STD_METHOD msReportSafeUrl, :ptr IShellUIHelper7
            DECLSPEC_XFGVIRT(IShellUIHelper5, msSiteModeRefreshBadge)
            ;* [id] *
            STD_METHOD msSiteModeRefreshBadge, :ptr IShellUIHelper7
            DECLSPEC_XFGVIRT(IShellUIHelper5, msSiteModeClearBadge)
            ;* [id] *
            STD_METHOD msSiteModeClearBadge, :ptr IShellUIHelper7
            DECLSPEC_XFGVIRT(IShellUIHelper5, msDiagnoseConnectionUILess)
            ;* [id] *
            STD_METHOD msDiagnoseConnectionUILess, :ptr IShellUIHelper7
            DECLSPEC_XFGVIRT(IShellUIHelper5, msLaunchNetworkClientHelp)
            ;* [id] *
            STD_METHOD msLaunchNetworkClientHelp, :ptr IShellUIHelper7
            DECLSPEC_XFGVIRT(IShellUIHelper5, msChangeDefaultBrowser)
            ;* [id] *
            STD_METHOD msChangeDefaultBrowser, :ptr IShellUIHelper7, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msStopPeriodicTileUpdate)
            ;* [id] *
            STD_METHOD msStopPeriodicTileUpdate, :ptr IShellUIHelper7
            DECLSPEC_XFGVIRT(IShellUIHelper6, msStartPeriodicTileUpdate)
            ;* [id] *
            ;* [in] *
            ;* [in][optional] *
            STD_METHOD msStartPeriodicTileUpdate, :ptr IShellUIHelper7, :VARIANT, :VARIANT, :VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msStartPeriodicTileUpdateBatch)
            ;* [id] *
            ;* [in] *
            ;* [in][optional] *
            STD_METHOD msStartPeriodicTileUpdateBatch, :ptr IShellUIHelper7, :VARIANT, :VARIANT, :VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msClearTile)
            ;* [id] *
            STD_METHOD msClearTile, :ptr IShellUIHelper7
            DECLSPEC_XFGVIRT(IShellUIHelper6, msEnableTileNotificationQueue)
            ;* [id] *
            STD_METHOD msEnableTileNotificationQueue, :ptr IShellUIHelper7, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msPinnedSiteState)
            ;* [id] *
            STD_METHOD msPinnedSiteState, :ptr IShellUIHelper7, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msEnableTileNotificationQueueForSquare150x150)
            ;* [id] *
            STD_METHOD msEnableTileNotificationQueueForSquare150x150, :ptr IShellUIHelper7, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msEnableTileNotificationQueueForWide310x150)
            ;* [id] *
            STD_METHOD msEnableTileNotificationQueueForWide310x150, :ptr IShellUIHelper7, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msEnableTileNotificationQueueForSquare310x310)
            ;* [id] *
            STD_METHOD msEnableTileNotificationQueueForSquare310x310, :ptr IShellUIHelper7, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msScheduledTileNotification)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            ;* [in][optional] *
            STD_METHOD msScheduledTileNotification, :ptr IShellUIHelper7, :BSTR, :BSTR, :BSTR, :VARIANT, :VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msRemoveScheduledTileNotification)
            ;* [id] *
            STD_METHOD msRemoveScheduledTileNotification, :ptr IShellUIHelper7, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msStartPeriodicBadgeUpdate)
            ;* [id] *
            ;* [in] *
            ;* [in][optional] *
            STD_METHOD msStartPeriodicBadgeUpdate, :ptr IShellUIHelper7, :BSTR, :VARIANT, :VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msStopPeriodicBadgeUpdate)
            ;* [id] *
            STD_METHOD msStopPeriodicBadgeUpdate, :ptr IShellUIHelper7
            DECLSPEC_XFGVIRT(IShellUIHelper6, msLaunchInternetOptions)
            ;* [id] *
            STD_METHOD msLaunchInternetOptions, :ptr IShellUIHelper7
            DECLSPEC_XFGVIRT(IShellUIHelper7, SetExperimentalFlag)
            ;* [id] *
            ;* [in] *
            STD_METHOD SetExperimentalFlag, :ptr IShellUIHelper7, :BSTR, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper7, GetExperimentalFlag)
            ;* [id] *
            ;* [in] *
            STD_METHOD GetExperimentalFlag, :ptr IShellUIHelper7, :BSTR, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper7, SetExperimentalValue)
            ;* [id] *
            ;* [in] *
            STD_METHOD SetExperimentalValue, :ptr IShellUIHelper7, :BSTR, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper7, GetExperimentalValue)
            ;* [id] *
            ;* [in] *
            STD_METHOD GetExperimentalValue, :ptr IShellUIHelper7, :BSTR, :ptr DWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper7, ResetAllExperimentalFlagsAndValues)
            ;* [id] *
            STD_METHOD ResetAllExperimentalFlagsAndValues, :ptr IShellUIHelper7
            DECLSPEC_XFGVIRT(IShellUIHelper7, GetNeedIEAutoLaunchFlag)
            ;* [id] *
            ;* [in] *
            STD_METHOD GetNeedIEAutoLaunchFlag, :ptr IShellUIHelper7, :BSTR, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper7, SetNeedIEAutoLaunchFlag)
            ;* [id] *
            ;* [in] *
            STD_METHOD SetNeedIEAutoLaunchFlag, :ptr IShellUIHelper7, :BSTR, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper7, HasNeedIEAutoLaunchFlag)
            ;* [id] *
            ;* [in] *
            STD_METHOD HasNeedIEAutoLaunchFlag, :ptr IShellUIHelper7, :BSTR, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper7, LaunchIE)
            ;* [id] *
            ;* [in] *
            STD_METHOD LaunchIE, :ptr IShellUIHelper7, :BSTR, :VARIANT_BOOL
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IShellUIHelper7Vtbl ends
          IShellUIHelper7 struct
            lpVtbl POINTER ?
          IShellUIHelper7 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IShellUIHelper7_INTERFACE_DEFINED__ *
      endif
      ifndef __IShellUIHelper8_INTERFACE_DEFINED__
        __IShellUIHelper8_INTERFACE_DEFINED__ equ <>
        ;* interface IShellUIHelper8 *
        ;* [object][dual][oleautomation][helpstring][uuid] *
        externdef IID_IShellUIHelper8:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellUIHelper8Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellUIHelper8Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IShellUIHelper8, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IShellUIHelper8
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IShellUIHelper8
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IShellUIHelper8, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr IShellUIHelper8, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr IShellUIHelper8, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
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
            STD_METHOD Invoke_, :ptr IShellUIHelper8, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IShellUIHelper, ResetFirstBootMode)
            ;* [id][hidden] *
            STD_METHOD ResetFirstBootMode, :ptr IShellUIHelper8
            DECLSPEC_XFGVIRT(IShellUIHelper, ResetSafeMode)
            ;* [id][hidden] *
            STD_METHOD ResetSafeMode, :ptr IShellUIHelper8
            DECLSPEC_XFGVIRT(IShellUIHelper, RefreshOfflineDesktop)
            ;* [id][hidden] *
            STD_METHOD RefreshOfflineDesktop, :ptr IShellUIHelper8
            DECLSPEC_XFGVIRT(IShellUIHelper, AddFavorite)
            ;* [id] *
            ;* [in] *
            STD_METHOD AddFavorite, :ptr IShellUIHelper8, :BSTR, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AddChannel)
            ;* [id] *
            STD_METHOD AddChannel, :ptr IShellUIHelper8, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AddDesktopComponent)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            ;* [unique][optional][in] *
            ;* [unique][optional][in] *
            ;* [unique][optional][in] *
            STD_METHOD AddDesktopComponent, :ptr IShellUIHelper8, :BSTR, :BSTR, :ptr VARIANT, :ptr VARIANT, :ptr VARIANT, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, IsSubscribed)
            ;* [id] *
            ;* [in] *
            STD_METHOD IsSubscribed, :ptr IShellUIHelper8, :BSTR, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper, NavigateAndFind)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD NavigateAndFind, :ptr IShellUIHelper8, :BSTR, :BSTR, :ptr VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, ImportExportFavorites)
            ;* [id] *
            ;* [in] *
            STD_METHOD ImportExportFavorites, :ptr IShellUIHelper8, :VARIANT_BOOL, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AutoCompleteSaveForm)
            ;* [id] *
            STD_METHOD AutoCompleteSaveForm, :ptr IShellUIHelper8, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AutoScan)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD AutoScan, :ptr IShellUIHelper8, :BSTR, :BSTR, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AutoCompleteAttach)
            ;* [id][hidden] *
            STD_METHOD AutoCompleteAttach, :ptr IShellUIHelper8, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, ShowBrowserUI)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD ShowBrowserUI, :ptr IShellUIHelper8, :BSTR, :ptr VARIANT, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, AddSearchProvider)
            ;* [id] *
            STD_METHOD AddSearchProvider, :ptr IShellUIHelper8, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, RunOnceShown)
            ;* [id] *
            STD_METHOD RunOnceShown, :ptr IShellUIHelper8
            DECLSPEC_XFGVIRT(IShellUIHelper2, SkipRunOnce)
            ;* [id] *
            STD_METHOD SkipRunOnce, :ptr IShellUIHelper8
            DECLSPEC_XFGVIRT(IShellUIHelper2, CustomizeSettings)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD CustomizeSettings, :ptr IShellUIHelper8, :VARIANT_BOOL, :VARIANT_BOOL, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, SqmEnabled)
            ;* [id] *
            STD_METHOD SqmEnabled, :ptr IShellUIHelper8, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, PhishingEnabled)
            ;* [id] *
            STD_METHOD PhishingEnabled, :ptr IShellUIHelper8, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, BrandImageUri)
            ;* [id] *
            STD_METHOD BrandImageUri, :ptr IShellUIHelper8, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, SkipTabsWelcome)
            ;* [id] *
            STD_METHOD SkipTabsWelcome, :ptr IShellUIHelper8
            DECLSPEC_XFGVIRT(IShellUIHelper2, DiagnoseConnection)
            ;* [id] *
            STD_METHOD DiagnoseConnection, :ptr IShellUIHelper8
            DECLSPEC_XFGVIRT(IShellUIHelper2, CustomizeClearType)
            ;* [id] *
            STD_METHOD CustomizeClearType, :ptr IShellUIHelper8, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, IsSearchProviderInstalled)
            ;* [id] *
            ;* [in] *
            STD_METHOD IsSearchProviderInstalled, :ptr IShellUIHelper8, :BSTR, :ptr DWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, IsSearchMigrated)
            ;* [id] *
            STD_METHOD IsSearchMigrated, :ptr IShellUIHelper8, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, DefaultSearchProvider)
            ;* [id] *
            STD_METHOD DefaultSearchProvider, :ptr IShellUIHelper8, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, RunOnceRequiredSettingsComplete)
            ;* [id] *
            STD_METHOD RunOnceRequiredSettingsComplete, :ptr IShellUIHelper8, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, RunOnceHasShown)
            ;* [id] *
            STD_METHOD RunOnceHasShown, :ptr IShellUIHelper8, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, SearchGuideUrl)
            ;* [id] *
            STD_METHOD SearchGuideUrl, :ptr IShellUIHelper8, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, AddService)
            ;* [id] *
            STD_METHOD AddService, :ptr IShellUIHelper8, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, IsServiceInstalled)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD IsServiceInstalled, :ptr IShellUIHelper8, :BSTR, :BSTR, :ptr DWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, InPrivateFilteringEnabled)
            ;* [id] *
            STD_METHOD InPrivateFilteringEnabled, :ptr IShellUIHelper8, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, AddToFavoritesBar)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD AddToFavoritesBar, :ptr IShellUIHelper8, :BSTR, :BSTR, :ptr VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, BuildNewTabPage)
            ;* [id] *
            STD_METHOD BuildNewTabPage, :ptr IShellUIHelper8
            DECLSPEC_XFGVIRT(IShellUIHelper3, SetRecentlyClosedVisible)
            ;* [id] *
            STD_METHOD SetRecentlyClosedVisible, :ptr IShellUIHelper8, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, SetActivitiesVisible)
            ;* [id] *
            STD_METHOD SetActivitiesVisible, :ptr IShellUIHelper8, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, ContentDiscoveryReset)
            ;* [id] *
            STD_METHOD ContentDiscoveryReset, :ptr IShellUIHelper8
            DECLSPEC_XFGVIRT(IShellUIHelper3, IsSuggestedSitesEnabled)
            ;* [id] *
            STD_METHOD IsSuggestedSitesEnabled, :ptr IShellUIHelper8, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, EnableSuggestedSites)
            ;* [id] *
            STD_METHOD EnableSuggestedSites, :ptr IShellUIHelper8, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, NavigateToSuggestedSites)
            ;* [id] *
            STD_METHOD NavigateToSuggestedSites, :ptr IShellUIHelper8, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, ShowTabsHelp)
            ;* [id] *
            STD_METHOD ShowTabsHelp, :ptr IShellUIHelper8
            DECLSPEC_XFGVIRT(IShellUIHelper3, ShowInPrivateHelp)
            ;* [id] *
            STD_METHOD ShowInPrivateHelp, :ptr IShellUIHelper8
            DECLSPEC_XFGVIRT(IShellUIHelper4, msIsSiteMode)
            ;* [id] *
            STD_METHOD msIsSiteMode, :ptr IShellUIHelper8, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeShowThumbBar)
            ;* [id] *
            STD_METHOD msSiteModeShowThumbBar, :ptr IShellUIHelper8
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeAddThumbBarButton)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD msSiteModeAddThumbBarButton, :ptr IShellUIHelper8, :BSTR, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeUpdateThumbBarButton)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD msSiteModeUpdateThumbBarButton, :ptr IShellUIHelper8, :VARIANT, :VARIANT_BOOL, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeSetIconOverlay)
            ;* [id] *
            ;* [in] *
            STD_METHOD msSiteModeSetIconOverlay, :ptr IShellUIHelper8, :BSTR, :ptr VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeClearIconOverlay)
            ;* [id] *
            STD_METHOD msSiteModeClearIconOverlay, :ptr IShellUIHelper8
            DECLSPEC_XFGVIRT(IShellUIHelper4, msAddSiteMode)
            ;* [id] *
            STD_METHOD msAddSiteMode, :ptr IShellUIHelper8
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeCreateJumpList)
            ;* [id] *
            STD_METHOD msSiteModeCreateJumpList, :ptr IShellUIHelper8, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeAddJumpListItem)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD msSiteModeAddJumpListItem, :ptr IShellUIHelper8, :BSTR, :BSTR, :BSTR, :ptr VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeClearJumpList)
            ;* [id] *
            STD_METHOD msSiteModeClearJumpList, :ptr IShellUIHelper8
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeShowJumpList)
            ;* [id] *
            STD_METHOD msSiteModeShowJumpList, :ptr IShellUIHelper8
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeAddButtonStyle)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD msSiteModeAddButtonStyle, :ptr IShellUIHelper8, :VARIANT, :BSTR, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeShowButtonStyle)
            ;* [id] *
            ;* [in] *
            STD_METHOD msSiteModeShowButtonStyle, :ptr IShellUIHelper8, :VARIANT, :VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeActivate)
            ;* [id] *
            STD_METHOD msSiteModeActivate, :ptr IShellUIHelper8
            DECLSPEC_XFGVIRT(IShellUIHelper4, msIsSiteModeFirstRun)
            ;* [id] *
            ;* [in] *
            STD_METHOD msIsSiteModeFirstRun, :ptr IShellUIHelper8, :VARIANT_BOOL, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msAddTrackingProtectionList)
            ;* [id] *
            ;* [in] *
            STD_METHOD msAddTrackingProtectionList, :ptr IShellUIHelper8, :BSTR, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msTrackingProtectionEnabled)
            ;* [id] *
            STD_METHOD msTrackingProtectionEnabled, :ptr IShellUIHelper8, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msActiveXFilteringEnabled)
            ;* [id] *
            STD_METHOD msActiveXFilteringEnabled, :ptr IShellUIHelper8, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper5, msProvisionNetworks)
            ;* [id] *
            ;* [in] *
            STD_METHOD msProvisionNetworks, :ptr IShellUIHelper8, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper5, msReportSafeUrl)
            ;* [id] *
            STD_METHOD msReportSafeUrl, :ptr IShellUIHelper8
            DECLSPEC_XFGVIRT(IShellUIHelper5, msSiteModeRefreshBadge)
            ;* [id] *
            STD_METHOD msSiteModeRefreshBadge, :ptr IShellUIHelper8
            DECLSPEC_XFGVIRT(IShellUIHelper5, msSiteModeClearBadge)
            ;* [id] *
            STD_METHOD msSiteModeClearBadge, :ptr IShellUIHelper8
            DECLSPEC_XFGVIRT(IShellUIHelper5, msDiagnoseConnectionUILess)
            ;* [id] *
            STD_METHOD msDiagnoseConnectionUILess, :ptr IShellUIHelper8
            DECLSPEC_XFGVIRT(IShellUIHelper5, msLaunchNetworkClientHelp)
            ;* [id] *
            STD_METHOD msLaunchNetworkClientHelp, :ptr IShellUIHelper8
            DECLSPEC_XFGVIRT(IShellUIHelper5, msChangeDefaultBrowser)
            ;* [id] *
            STD_METHOD msChangeDefaultBrowser, :ptr IShellUIHelper8, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msStopPeriodicTileUpdate)
            ;* [id] *
            STD_METHOD msStopPeriodicTileUpdate, :ptr IShellUIHelper8
            DECLSPEC_XFGVIRT(IShellUIHelper6, msStartPeriodicTileUpdate)
            ;* [id] *
            ;* [in] *
            ;* [in][optional] *
            STD_METHOD msStartPeriodicTileUpdate, :ptr IShellUIHelper8, :VARIANT, :VARIANT, :VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msStartPeriodicTileUpdateBatch)
            ;* [id] *
            ;* [in] *
            ;* [in][optional] *
            STD_METHOD msStartPeriodicTileUpdateBatch, :ptr IShellUIHelper8, :VARIANT, :VARIANT, :VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msClearTile)
            ;* [id] *
            STD_METHOD msClearTile, :ptr IShellUIHelper8
            DECLSPEC_XFGVIRT(IShellUIHelper6, msEnableTileNotificationQueue)
            ;* [id] *
            STD_METHOD msEnableTileNotificationQueue, :ptr IShellUIHelper8, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msPinnedSiteState)
            ;* [id] *
            STD_METHOD msPinnedSiteState, :ptr IShellUIHelper8, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msEnableTileNotificationQueueForSquare150x150)
            ;* [id] *
            STD_METHOD msEnableTileNotificationQueueForSquare150x150, :ptr IShellUIHelper8, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msEnableTileNotificationQueueForWide310x150)
            ;* [id] *
            STD_METHOD msEnableTileNotificationQueueForWide310x150, :ptr IShellUIHelper8, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msEnableTileNotificationQueueForSquare310x310)
            ;* [id] *
            STD_METHOD msEnableTileNotificationQueueForSquare310x310, :ptr IShellUIHelper8, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msScheduledTileNotification)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            ;* [in][optional] *
            STD_METHOD msScheduledTileNotification, :ptr IShellUIHelper8, :BSTR, :BSTR, :BSTR, :VARIANT, :VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msRemoveScheduledTileNotification)
            ;* [id] *
            STD_METHOD msRemoveScheduledTileNotification, :ptr IShellUIHelper8, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msStartPeriodicBadgeUpdate)
            ;* [id] *
            ;* [in] *
            ;* [in][optional] *
            STD_METHOD msStartPeriodicBadgeUpdate, :ptr IShellUIHelper8, :BSTR, :VARIANT, :VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msStopPeriodicBadgeUpdate)
            ;* [id] *
            STD_METHOD msStopPeriodicBadgeUpdate, :ptr IShellUIHelper8
            DECLSPEC_XFGVIRT(IShellUIHelper6, msLaunchInternetOptions)
            ;* [id] *
            STD_METHOD msLaunchInternetOptions, :ptr IShellUIHelper8
            DECLSPEC_XFGVIRT(IShellUIHelper7, SetExperimentalFlag)
            ;* [id] *
            ;* [in] *
            STD_METHOD SetExperimentalFlag, :ptr IShellUIHelper8, :BSTR, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper7, GetExperimentalFlag)
            ;* [id] *
            ;* [in] *
            STD_METHOD GetExperimentalFlag, :ptr IShellUIHelper8, :BSTR, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper7, SetExperimentalValue)
            ;* [id] *
            ;* [in] *
            STD_METHOD SetExperimentalValue, :ptr IShellUIHelper8, :BSTR, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper7, GetExperimentalValue)
            ;* [id] *
            ;* [in] *
            STD_METHOD GetExperimentalValue, :ptr IShellUIHelper8, :BSTR, :ptr DWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper7, ResetAllExperimentalFlagsAndValues)
            ;* [id] *
            STD_METHOD ResetAllExperimentalFlagsAndValues, :ptr IShellUIHelper8
            DECLSPEC_XFGVIRT(IShellUIHelper7, GetNeedIEAutoLaunchFlag)
            ;* [id] *
            ;* [in] *
            STD_METHOD GetNeedIEAutoLaunchFlag, :ptr IShellUIHelper8, :BSTR, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper7, SetNeedIEAutoLaunchFlag)
            ;* [id] *
            ;* [in] *
            STD_METHOD SetNeedIEAutoLaunchFlag, :ptr IShellUIHelper8, :BSTR, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper7, HasNeedIEAutoLaunchFlag)
            ;* [id] *
            ;* [in] *
            STD_METHOD HasNeedIEAutoLaunchFlag, :ptr IShellUIHelper8, :BSTR, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper7, LaunchIE)
            ;* [id] *
            ;* [in] *
            STD_METHOD LaunchIE, :ptr IShellUIHelper8, :BSTR, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper8, GetCVListData)
            ;* [id] *
            STD_METHOD GetCVListData, :ptr IShellUIHelper8, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper8, GetCVListLocalData)
            ;* [id] *
            STD_METHOD GetCVListLocalData, :ptr IShellUIHelper8, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper8, GetEMIEListData)
            ;* [id] *
            STD_METHOD GetEMIEListData, :ptr IShellUIHelper8, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper8, GetEMIEListLocalData)
            ;* [id] *
            STD_METHOD GetEMIEListLocalData, :ptr IShellUIHelper8, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper8, OpenFavoritesPane)
            ;* [id] *
            STD_METHOD OpenFavoritesPane, :ptr IShellUIHelper8
            DECLSPEC_XFGVIRT(IShellUIHelper8, OpenFavoritesSettings)
            ;* [id] *
            STD_METHOD OpenFavoritesSettings, :ptr IShellUIHelper8
            DECLSPEC_XFGVIRT(IShellUIHelper8, LaunchInHVSI)
            ;* [id] *
            STD_METHOD LaunchInHVSI, :ptr IShellUIHelper8, :BSTR
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IShellUIHelper8Vtbl ends
          IShellUIHelper8 struct
            lpVtbl POINTER ?
          IShellUIHelper8 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IShellUIHelper8_INTERFACE_DEFINED__ *
      endif
      ifndef __IShellUIHelper9_INTERFACE_DEFINED__
        __IShellUIHelper9_INTERFACE_DEFINED__ equ <>
        ;* interface IShellUIHelper9 *
        ;* [object][dual][oleautomation][helpstring][uuid] *
        externdef IID_IShellUIHelper9:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellUIHelper9Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellUIHelper9Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IShellUIHelper9, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IShellUIHelper9
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IShellUIHelper9
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IShellUIHelper9, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr IShellUIHelper9, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr IShellUIHelper9, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
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
            STD_METHOD Invoke_, :ptr IShellUIHelper9, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IShellUIHelper, ResetFirstBootMode)
            ;* [id][hidden] *
            STD_METHOD ResetFirstBootMode, :ptr IShellUIHelper9
            DECLSPEC_XFGVIRT(IShellUIHelper, ResetSafeMode)
            ;* [id][hidden] *
            STD_METHOD ResetSafeMode, :ptr IShellUIHelper9
            DECLSPEC_XFGVIRT(IShellUIHelper, RefreshOfflineDesktop)
            ;* [id][hidden] *
            STD_METHOD RefreshOfflineDesktop, :ptr IShellUIHelper9
            DECLSPEC_XFGVIRT(IShellUIHelper, AddFavorite)
            ;* [id] *
            ;* [in] *
            STD_METHOD AddFavorite, :ptr IShellUIHelper9, :BSTR, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AddChannel)
            ;* [id] *
            STD_METHOD AddChannel, :ptr IShellUIHelper9, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AddDesktopComponent)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            ;* [unique][optional][in] *
            ;* [unique][optional][in] *
            ;* [unique][optional][in] *
            STD_METHOD AddDesktopComponent, :ptr IShellUIHelper9, :BSTR, :BSTR, :ptr VARIANT, :ptr VARIANT, :ptr VARIANT, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, IsSubscribed)
            ;* [id] *
            ;* [in] *
            STD_METHOD IsSubscribed, :ptr IShellUIHelper9, :BSTR, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper, NavigateAndFind)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD NavigateAndFind, :ptr IShellUIHelper9, :BSTR, :BSTR, :ptr VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, ImportExportFavorites)
            ;* [id] *
            ;* [in] *
            STD_METHOD ImportExportFavorites, :ptr IShellUIHelper9, :VARIANT_BOOL, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AutoCompleteSaveForm)
            ;* [id] *
            STD_METHOD AutoCompleteSaveForm, :ptr IShellUIHelper9, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AutoScan)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD AutoScan, :ptr IShellUIHelper9, :BSTR, :BSTR, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, AutoCompleteAttach)
            ;* [id][hidden] *
            STD_METHOD AutoCompleteAttach, :ptr IShellUIHelper9, :ptr VARIANT
            ;* [unique][optional][in] *
            DECLSPEC_XFGVIRT(IShellUIHelper, ShowBrowserUI)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD ShowBrowserUI, :ptr IShellUIHelper9, :BSTR, :ptr VARIANT, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, AddSearchProvider)
            ;* [id] *
            STD_METHOD AddSearchProvider, :ptr IShellUIHelper9, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, RunOnceShown)
            ;* [id] *
            STD_METHOD RunOnceShown, :ptr IShellUIHelper9
            DECLSPEC_XFGVIRT(IShellUIHelper2, SkipRunOnce)
            ;* [id] *
            STD_METHOD SkipRunOnce, :ptr IShellUIHelper9
            DECLSPEC_XFGVIRT(IShellUIHelper2, CustomizeSettings)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD CustomizeSettings, :ptr IShellUIHelper9, :VARIANT_BOOL, :VARIANT_BOOL, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, SqmEnabled)
            ;* [id] *
            STD_METHOD SqmEnabled, :ptr IShellUIHelper9, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, PhishingEnabled)
            ;* [id] *
            STD_METHOD PhishingEnabled, :ptr IShellUIHelper9, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, BrandImageUri)
            ;* [id] *
            STD_METHOD BrandImageUri, :ptr IShellUIHelper9, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, SkipTabsWelcome)
            ;* [id] *
            STD_METHOD SkipTabsWelcome, :ptr IShellUIHelper9
            DECLSPEC_XFGVIRT(IShellUIHelper2, DiagnoseConnection)
            ;* [id] *
            STD_METHOD DiagnoseConnection, :ptr IShellUIHelper9
            DECLSPEC_XFGVIRT(IShellUIHelper2, CustomizeClearType)
            ;* [id] *
            STD_METHOD CustomizeClearType, :ptr IShellUIHelper9, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, IsSearchProviderInstalled)
            ;* [id] *
            ;* [in] *
            STD_METHOD IsSearchProviderInstalled, :ptr IShellUIHelper9, :BSTR, :ptr DWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, IsSearchMigrated)
            ;* [id] *
            STD_METHOD IsSearchMigrated, :ptr IShellUIHelper9, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, DefaultSearchProvider)
            ;* [id] *
            STD_METHOD DefaultSearchProvider, :ptr IShellUIHelper9, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, RunOnceRequiredSettingsComplete)
            ;* [id] *
            STD_METHOD RunOnceRequiredSettingsComplete, :ptr IShellUIHelper9, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, RunOnceHasShown)
            ;* [id] *
            STD_METHOD RunOnceHasShown, :ptr IShellUIHelper9, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper2, SearchGuideUrl)
            ;* [id] *
            STD_METHOD SearchGuideUrl, :ptr IShellUIHelper9, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, AddService)
            ;* [id] *
            STD_METHOD AddService, :ptr IShellUIHelper9, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, IsServiceInstalled)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD IsServiceInstalled, :ptr IShellUIHelper9, :BSTR, :BSTR, :ptr DWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, InPrivateFilteringEnabled)
            ;* [id] *
            STD_METHOD InPrivateFilteringEnabled, :ptr IShellUIHelper9, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, AddToFavoritesBar)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD AddToFavoritesBar, :ptr IShellUIHelper9, :BSTR, :BSTR, :ptr VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, BuildNewTabPage)
            ;* [id] *
            STD_METHOD BuildNewTabPage, :ptr IShellUIHelper9
            DECLSPEC_XFGVIRT(IShellUIHelper3, SetRecentlyClosedVisible)
            ;* [id] *
            STD_METHOD SetRecentlyClosedVisible, :ptr IShellUIHelper9, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, SetActivitiesVisible)
            ;* [id] *
            STD_METHOD SetActivitiesVisible, :ptr IShellUIHelper9, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, ContentDiscoveryReset)
            ;* [id] *
            STD_METHOD ContentDiscoveryReset, :ptr IShellUIHelper9
            DECLSPEC_XFGVIRT(IShellUIHelper3, IsSuggestedSitesEnabled)
            ;* [id] *
            STD_METHOD IsSuggestedSitesEnabled, :ptr IShellUIHelper9, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, EnableSuggestedSites)
            ;* [id] *
            STD_METHOD EnableSuggestedSites, :ptr IShellUIHelper9, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, NavigateToSuggestedSites)
            ;* [id] *
            STD_METHOD NavigateToSuggestedSites, :ptr IShellUIHelper9, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper3, ShowTabsHelp)
            ;* [id] *
            STD_METHOD ShowTabsHelp, :ptr IShellUIHelper9
            DECLSPEC_XFGVIRT(IShellUIHelper3, ShowInPrivateHelp)
            ;* [id] *
            STD_METHOD ShowInPrivateHelp, :ptr IShellUIHelper9
            DECLSPEC_XFGVIRT(IShellUIHelper4, msIsSiteMode)
            ;* [id] *
            STD_METHOD msIsSiteMode, :ptr IShellUIHelper9, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeShowThumbBar)
            ;* [id] *
            STD_METHOD msSiteModeShowThumbBar, :ptr IShellUIHelper9
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeAddThumbBarButton)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD msSiteModeAddThumbBarButton, :ptr IShellUIHelper9, :BSTR, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeUpdateThumbBarButton)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            STD_METHOD msSiteModeUpdateThumbBarButton, :ptr IShellUIHelper9, :VARIANT, :VARIANT_BOOL, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeSetIconOverlay)
            ;* [id] *
            ;* [in] *
            STD_METHOD msSiteModeSetIconOverlay, :ptr IShellUIHelper9, :BSTR, :ptr VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeClearIconOverlay)
            ;* [id] *
            STD_METHOD msSiteModeClearIconOverlay, :ptr IShellUIHelper9
            DECLSPEC_XFGVIRT(IShellUIHelper4, msAddSiteMode)
            ;* [id] *
            STD_METHOD msAddSiteMode, :ptr IShellUIHelper9
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeCreateJumpList)
            ;* [id] *
            STD_METHOD msSiteModeCreateJumpList, :ptr IShellUIHelper9, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeAddJumpListItem)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD msSiteModeAddJumpListItem, :ptr IShellUIHelper9, :BSTR, :BSTR, :BSTR, :ptr VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeClearJumpList)
            ;* [id] *
            STD_METHOD msSiteModeClearJumpList, :ptr IShellUIHelper9
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeShowJumpList)
            ;* [id] *
            STD_METHOD msSiteModeShowJumpList, :ptr IShellUIHelper9
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeAddButtonStyle)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD msSiteModeAddButtonStyle, :ptr IShellUIHelper9, :VARIANT, :BSTR, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeShowButtonStyle)
            ;* [id] *
            ;* [in] *
            STD_METHOD msSiteModeShowButtonStyle, :ptr IShellUIHelper9, :VARIANT, :VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msSiteModeActivate)
            ;* [id] *
            STD_METHOD msSiteModeActivate, :ptr IShellUIHelper9
            DECLSPEC_XFGVIRT(IShellUIHelper4, msIsSiteModeFirstRun)
            ;* [id] *
            ;* [in] *
            STD_METHOD msIsSiteModeFirstRun, :ptr IShellUIHelper9, :VARIANT_BOOL, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msAddTrackingProtectionList)
            ;* [id] *
            ;* [in] *
            STD_METHOD msAddTrackingProtectionList, :ptr IShellUIHelper9, :BSTR, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msTrackingProtectionEnabled)
            ;* [id] *
            STD_METHOD msTrackingProtectionEnabled, :ptr IShellUIHelper9, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper4, msActiveXFilteringEnabled)
            ;* [id] *
            STD_METHOD msActiveXFilteringEnabled, :ptr IShellUIHelper9, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper5, msProvisionNetworks)
            ;* [id] *
            ;* [in] *
            STD_METHOD msProvisionNetworks, :ptr IShellUIHelper9, :BSTR, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper5, msReportSafeUrl)
            ;* [id] *
            STD_METHOD msReportSafeUrl, :ptr IShellUIHelper9
            DECLSPEC_XFGVIRT(IShellUIHelper5, msSiteModeRefreshBadge)
            ;* [id] *
            STD_METHOD msSiteModeRefreshBadge, :ptr IShellUIHelper9
            DECLSPEC_XFGVIRT(IShellUIHelper5, msSiteModeClearBadge)
            ;* [id] *
            STD_METHOD msSiteModeClearBadge, :ptr IShellUIHelper9
            DECLSPEC_XFGVIRT(IShellUIHelper5, msDiagnoseConnectionUILess)
            ;* [id] *
            STD_METHOD msDiagnoseConnectionUILess, :ptr IShellUIHelper9
            DECLSPEC_XFGVIRT(IShellUIHelper5, msLaunchNetworkClientHelp)
            ;* [id] *
            STD_METHOD msLaunchNetworkClientHelp, :ptr IShellUIHelper9
            DECLSPEC_XFGVIRT(IShellUIHelper5, msChangeDefaultBrowser)
            ;* [id] *
            STD_METHOD msChangeDefaultBrowser, :ptr IShellUIHelper9, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msStopPeriodicTileUpdate)
            ;* [id] *
            STD_METHOD msStopPeriodicTileUpdate, :ptr IShellUIHelper9
            DECLSPEC_XFGVIRT(IShellUIHelper6, msStartPeriodicTileUpdate)
            ;* [id] *
            ;* [in] *
            ;* [in][optional] *
            STD_METHOD msStartPeriodicTileUpdate, :ptr IShellUIHelper9, :VARIANT, :VARIANT, :VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msStartPeriodicTileUpdateBatch)
            ;* [id] *
            ;* [in] *
            ;* [in][optional] *
            STD_METHOD msStartPeriodicTileUpdateBatch, :ptr IShellUIHelper9, :VARIANT, :VARIANT, :VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msClearTile)
            ;* [id] *
            STD_METHOD msClearTile, :ptr IShellUIHelper9
            DECLSPEC_XFGVIRT(IShellUIHelper6, msEnableTileNotificationQueue)
            ;* [id] *
            STD_METHOD msEnableTileNotificationQueue, :ptr IShellUIHelper9, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msPinnedSiteState)
            ;* [id] *
            STD_METHOD msPinnedSiteState, :ptr IShellUIHelper9, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msEnableTileNotificationQueueForSquare150x150)
            ;* [id] *
            STD_METHOD msEnableTileNotificationQueueForSquare150x150, :ptr IShellUIHelper9, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msEnableTileNotificationQueueForWide310x150)
            ;* [id] *
            STD_METHOD msEnableTileNotificationQueueForWide310x150, :ptr IShellUIHelper9, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msEnableTileNotificationQueueForSquare310x310)
            ;* [id] *
            STD_METHOD msEnableTileNotificationQueueForSquare310x310, :ptr IShellUIHelper9, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msScheduledTileNotification)
            ;* [id] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            ;* [in][optional] *
            STD_METHOD msScheduledTileNotification, :ptr IShellUIHelper9, :BSTR, :BSTR, :BSTR, :VARIANT, :VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msRemoveScheduledTileNotification)
            ;* [id] *
            STD_METHOD msRemoveScheduledTileNotification, :ptr IShellUIHelper9, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msStartPeriodicBadgeUpdate)
            ;* [id] *
            ;* [in] *
            ;* [in][optional] *
            STD_METHOD msStartPeriodicBadgeUpdate, :ptr IShellUIHelper9, :BSTR, :VARIANT, :VARIANT
            ;* [in][optional] *
            DECLSPEC_XFGVIRT(IShellUIHelper6, msStopPeriodicBadgeUpdate)
            ;* [id] *
            STD_METHOD msStopPeriodicBadgeUpdate, :ptr IShellUIHelper9
            DECLSPEC_XFGVIRT(IShellUIHelper6, msLaunchInternetOptions)
            ;* [id] *
            STD_METHOD msLaunchInternetOptions, :ptr IShellUIHelper9
            DECLSPEC_XFGVIRT(IShellUIHelper7, SetExperimentalFlag)
            ;* [id] *
            ;* [in] *
            STD_METHOD SetExperimentalFlag, :ptr IShellUIHelper9, :BSTR, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper7, GetExperimentalFlag)
            ;* [id] *
            ;* [in] *
            STD_METHOD GetExperimentalFlag, :ptr IShellUIHelper9, :BSTR, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper7, SetExperimentalValue)
            ;* [id] *
            ;* [in] *
            STD_METHOD SetExperimentalValue, :ptr IShellUIHelper9, :BSTR, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper7, GetExperimentalValue)
            ;* [id] *
            ;* [in] *
            STD_METHOD GetExperimentalValue, :ptr IShellUIHelper9, :BSTR, :ptr DWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper7, ResetAllExperimentalFlagsAndValues)
            ;* [id] *
            STD_METHOD ResetAllExperimentalFlagsAndValues, :ptr IShellUIHelper9
            DECLSPEC_XFGVIRT(IShellUIHelper7, GetNeedIEAutoLaunchFlag)
            ;* [id] *
            ;* [in] *
            STD_METHOD GetNeedIEAutoLaunchFlag, :ptr IShellUIHelper9, :BSTR, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper7, SetNeedIEAutoLaunchFlag)
            ;* [id] *
            ;* [in] *
            STD_METHOD SetNeedIEAutoLaunchFlag, :ptr IShellUIHelper9, :BSTR, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper7, HasNeedIEAutoLaunchFlag)
            ;* [id] *
            ;* [in] *
            STD_METHOD HasNeedIEAutoLaunchFlag, :ptr IShellUIHelper9, :BSTR, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper7, LaunchIE)
            ;* [id] *
            ;* [in] *
            STD_METHOD LaunchIE, :ptr IShellUIHelper9, :BSTR, :VARIANT_BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper8, GetCVListData)
            ;* [id] *
            STD_METHOD GetCVListData, :ptr IShellUIHelper9, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper8, GetCVListLocalData)
            ;* [id] *
            STD_METHOD GetCVListLocalData, :ptr IShellUIHelper9, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper8, GetEMIEListData)
            ;* [id] *
            STD_METHOD GetEMIEListData, :ptr IShellUIHelper9, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper8, GetEMIEListLocalData)
            ;* [id] *
            STD_METHOD GetEMIEListLocalData, :ptr IShellUIHelper9, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellUIHelper8, OpenFavoritesPane)
            ;* [id] *
            STD_METHOD OpenFavoritesPane, :ptr IShellUIHelper9
            DECLSPEC_XFGVIRT(IShellUIHelper8, OpenFavoritesSettings)
            ;* [id] *
            STD_METHOD OpenFavoritesSettings, :ptr IShellUIHelper9
            DECLSPEC_XFGVIRT(IShellUIHelper8, LaunchInHVSI)
            ;* [id] *
            STD_METHOD LaunchInHVSI, :ptr IShellUIHelper9, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellUIHelper9, GetOSSku)
            ;* [id] *
            STD_METHOD GetOSSku, :ptr IShellUIHelper9, :ptr DWORD
            ;* [retval][out] *
            ??Interface equ <>
            END_INTERFACE
          IShellUIHelper9Vtbl ends
          IShellUIHelper9 struct
            lpVtbl POINTER ?
          IShellUIHelper9 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IShellUIHelper9_INTERFACE_DEFINED__ *
      endif
      externdef CLSID_ShellUIHelper:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      ifndef __DShellNameSpaceEvents_DISPINTERFACE_DEFINED__
        __DShellNameSpaceEvents_DISPINTERFACE_DEFINED__ equ <>
        ;* dispinterface DShellNameSpaceEvents *
        ;* [uuid] *
        externdef DIID_DShellNameSpaceEvents:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          DShellNameSpaceEventsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <DShellNameSpaceEventsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr DShellNameSpaceEvents, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr DShellNameSpaceEvents
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr DShellNameSpaceEvents
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr DShellNameSpaceEvents, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr DShellNameSpaceEvents, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr DShellNameSpaceEvents, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
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
            STD_METHOD Invoke_, :ptr DShellNameSpaceEvents, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            ??Interface equ <>
            END_INTERFACE
          DShellNameSpaceEventsVtbl ends
          DShellNameSpaceEvents struct
            lpVtbl POINTER ?
          DShellNameSpaceEvents ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __DShellNameSpaceEvents_DISPINTERFACE_DEFINED__ *
      endif
      ifndef __IShellFavoritesNameSpace_INTERFACE_DEFINED__
        __IShellFavoritesNameSpace_INTERFACE_DEFINED__ equ <>
        ;* interface IShellFavoritesNameSpace *
        ;* [hidden][unique][helpstring][dual][uuid][object] *
        externdef IID_IShellFavoritesNameSpace:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellFavoritesNameSpaceVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellFavoritesNameSpaceVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IShellFavoritesNameSpace, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IShellFavoritesNameSpace
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IShellFavoritesNameSpace
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IShellFavoritesNameSpace, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr IShellFavoritesNameSpace, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr IShellFavoritesNameSpace, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
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
            STD_METHOD Invoke_, :ptr IShellFavoritesNameSpace, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IShellFavoritesNameSpace, MoveSelectionUp)
            ;* [helpstring][id] *
            STD_METHOD MoveSelectionUp, :ptr IShellFavoritesNameSpace
            DECLSPEC_XFGVIRT(IShellFavoritesNameSpace, MoveSelectionDown)
            ;* [helpstring][id] *
            STD_METHOD MoveSelectionDown, :ptr IShellFavoritesNameSpace
            DECLSPEC_XFGVIRT(IShellFavoritesNameSpace, ResetSort)
            ;* [helpstring][id] *
            STD_METHOD ResetSort, :ptr IShellFavoritesNameSpace
            DECLSPEC_XFGVIRT(IShellFavoritesNameSpace, NewFolder)
            ;* [helpstring][id] *
            STD_METHOD NewFolder, :ptr IShellFavoritesNameSpace
            DECLSPEC_XFGVIRT(IShellFavoritesNameSpace, Synchronize)
            ;* [helpstring][id] *
            STD_METHOD Synchronize, :ptr IShellFavoritesNameSpace
            DECLSPEC_XFGVIRT(IShellFavoritesNameSpace, Import)
            ;* [helpstring][id] *
            STD_METHOD Import, :ptr IShellFavoritesNameSpace
            DECLSPEC_XFGVIRT(IShellFavoritesNameSpace, Export)
            ;* [helpstring][id] *
            STD_METHOD Export_, :ptr IShellFavoritesNameSpace
            DECLSPEC_XFGVIRT(IShellFavoritesNameSpace, InvokeContextMenuCommand)
            ;* [helpstring][id] *
            STD_METHOD InvokeContextMenuCommand, :ptr IShellFavoritesNameSpace, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellFavoritesNameSpace, MoveSelectionTo)
            ;* [helpstring][id] *
            STD_METHOD MoveSelectionTo, :ptr IShellFavoritesNameSpace
            DECLSPEC_XFGVIRT(IShellFavoritesNameSpace, get_SubscriptionsEnabled)
            ;* [helpstring][id][propget] *
            STD_METHOD get_SubscriptionsEnabled, :ptr IShellFavoritesNameSpace, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFavoritesNameSpace, CreateSubscriptionForSelection)
            ;* [helpstring][id] *
            STD_METHOD CreateSubscriptionForSelection, :ptr IShellFavoritesNameSpace, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFavoritesNameSpace, DeleteSubscriptionForSelection)
            ;* [helpstring][id] *
            STD_METHOD DeleteSubscriptionForSelection, :ptr IShellFavoritesNameSpace, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFavoritesNameSpace, SetRoot)
            ;* [helpstring][id] *
            STD_METHOD SetRoot, :ptr IShellFavoritesNameSpace, :BSTR
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IShellFavoritesNameSpaceVtbl ends
          IShellFavoritesNameSpace struct
            lpVtbl POINTER ?
          IShellFavoritesNameSpace ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IShellFavoritesNameSpace_INTERFACE_DEFINED__ *
      endif
      ifndef __IShellNameSpace_INTERFACE_DEFINED__
        __IShellNameSpace_INTERFACE_DEFINED__ equ <>
        ;* interface IShellNameSpace *
        ;* [hidden][unique][helpstring][dual][uuid][object] *
        externdef IID_IShellNameSpace:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IShellNameSpaceVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IShellNameSpaceVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IShellNameSpace, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IShellNameSpace
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IShellNameSpace
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IShellNameSpace, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr IShellNameSpace, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr IShellNameSpace, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
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
            STD_METHOD Invoke_, :ptr IShellNameSpace, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IShellFavoritesNameSpace, MoveSelectionUp)
            ;* [helpstring][id] *
            STD_METHOD MoveSelectionUp, :ptr IShellNameSpace
            DECLSPEC_XFGVIRT(IShellFavoritesNameSpace, MoveSelectionDown)
            ;* [helpstring][id] *
            STD_METHOD MoveSelectionDown, :ptr IShellNameSpace
            DECLSPEC_XFGVIRT(IShellFavoritesNameSpace, ResetSort)
            ;* [helpstring][id] *
            STD_METHOD ResetSort, :ptr IShellNameSpace
            DECLSPEC_XFGVIRT(IShellFavoritesNameSpace, NewFolder)
            ;* [helpstring][id] *
            STD_METHOD NewFolder, :ptr IShellNameSpace
            DECLSPEC_XFGVIRT(IShellFavoritesNameSpace, Synchronize)
            ;* [helpstring][id] *
            STD_METHOD Synchronize, :ptr IShellNameSpace
            DECLSPEC_XFGVIRT(IShellFavoritesNameSpace, Import)
            ;* [helpstring][id] *
            STD_METHOD Import, :ptr IShellNameSpace
            DECLSPEC_XFGVIRT(IShellFavoritesNameSpace, Export)
            ;* [helpstring][id] *
            STD_METHOD Export_, :ptr IShellNameSpace
            DECLSPEC_XFGVIRT(IShellFavoritesNameSpace, InvokeContextMenuCommand)
            ;* [helpstring][id] *
            STD_METHOD InvokeContextMenuCommand, :ptr IShellNameSpace, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellFavoritesNameSpace, MoveSelectionTo)
            ;* [helpstring][id] *
            STD_METHOD MoveSelectionTo, :ptr IShellNameSpace
            DECLSPEC_XFGVIRT(IShellFavoritesNameSpace, get_SubscriptionsEnabled)
            ;* [helpstring][id][propget] *
            STD_METHOD get_SubscriptionsEnabled, :ptr IShellNameSpace, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFavoritesNameSpace, CreateSubscriptionForSelection)
            ;* [helpstring][id] *
            STD_METHOD CreateSubscriptionForSelection, :ptr IShellNameSpace, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFavoritesNameSpace, DeleteSubscriptionForSelection)
            ;* [helpstring][id] *
            STD_METHOD DeleteSubscriptionForSelection, :ptr IShellNameSpace, :ptr VARIANT_BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellFavoritesNameSpace, SetRoot)
            ;* [helpstring][id] *
            STD_METHOD SetRoot, :ptr IShellNameSpace, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellNameSpace, get_EnumOptions)
            ;* [helpstring][id][propget] *
            STD_METHOD get_EnumOptions, :ptr IShellNameSpace, :ptr LONG
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellNameSpace, put_EnumOptions)
            ;* [helpstring][id][propput] *
            STD_METHOD put_EnumOptions, :ptr IShellNameSpace, :LONG
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellNameSpace, get_SelectedItem)
            ;* [helpstring][id][propget] *
            STD_METHOD get_SelectedItem, :ptr IShellNameSpace, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellNameSpace, put_SelectedItem)
            ;* [helpstring][id][propput] *
            STD_METHOD put_SelectedItem, :ptr IShellNameSpace, :ptr IDispatch
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellNameSpace, get_Root)
            ;* [helpstring][id][propget] *
            STD_METHOD get_Root, :ptr IShellNameSpace, :ptr VARIANT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellNameSpace, put_Root)
            ;* [helpstring][id][propput] *
            STD_METHOD put_Root, :ptr IShellNameSpace, :VARIANT
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellNameSpace, get_Depth)
            ;* [helpstring][id][propget] *
            STD_METHOD get_Depth, :ptr IShellNameSpace, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellNameSpace, put_Depth)
            ;* [helpstring][id][propput] *
            STD_METHOD put_Depth, :ptr IShellNameSpace, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellNameSpace, get_Mode)
            ;* [helpstring][id][propget] *
            STD_METHOD get_Mode, :ptr IShellNameSpace, :ptr UINT
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellNameSpace, put_Mode)
            ;* [helpstring][id][propput] *
            STD_METHOD put_Mode, :ptr IShellNameSpace, :UINT
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellNameSpace, get_Flags)
            ;* [helpstring][id][propget] *
            STD_METHOD get_Flags, :ptr IShellNameSpace, :ptr DWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellNameSpace, put_Flags)
            ;* [helpstring][id][propput] *
            STD_METHOD put_Flags, :ptr IShellNameSpace, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellNameSpace, put_TVFlags)
            ;* [helpstring][id][propput] *
            STD_METHOD put_TVFlags, :ptr IShellNameSpace, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellNameSpace, get_TVFlags)
            ;* [helpstring][id][propget] *
            STD_METHOD get_TVFlags, :ptr IShellNameSpace, :ptr DWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellNameSpace, get_Columns)
            ;* [helpstring][id][propget] *
            STD_METHOD get_Columns, :ptr IShellNameSpace, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellNameSpace, put_Columns)
            ;* [helpstring][id][propput] *
            STD_METHOD put_Columns, :ptr IShellNameSpace, :BSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellNameSpace, get_CountViewTypes)
            ;* [helpstring][id][propget] *
            STD_METHOD get_CountViewTypes, :ptr IShellNameSpace, :ptr SDWORD
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellNameSpace, SetViewType)
            ;* [helpstring][id] *
            STD_METHOD SetViewType, :ptr IShellNameSpace, :SDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IShellNameSpace, SelectedItems)
            ;* [helpstring][id] *
            STD_METHOD SelectedItems, :ptr IShellNameSpace, :ptr ptr IDispatch
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IShellNameSpace, Expand)
            ;* [helpstring][id] *
            ;* [in] *
            STD_METHOD Expand, :ptr IShellNameSpace, :VARIANT, :SDWORD
            DECLSPEC_XFGVIRT(IShellNameSpace, UnselectAll)
            ;* [helpstring][id] *
            STD_METHOD UnselectAll, :ptr IShellNameSpace
            ??Interface equ <>
            END_INTERFACE
          IShellNameSpaceVtbl ends
          IShellNameSpace struct
            lpVtbl POINTER ?
          IShellNameSpace ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IShellNameSpace_INTERFACE_DEFINED__ *
      endif
      externdef CLSID_ShellNameSpace:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      ifndef __IScriptErrorList_INTERFACE_DEFINED__
        __IScriptErrorList_INTERFACE_DEFINED__ equ <>
        ;* interface IScriptErrorList *
        ;* [object][dual][hidden][oleautomation][helpstring][uuid] *
        externdef IID_IScriptErrorList:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IScriptErrorListVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IScriptErrorListVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IScriptErrorList, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IScriptErrorList
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IScriptErrorList
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
            STD_METHOD GetTypeInfoCount, :ptr IScriptErrorList, :ptr UINT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetTypeInfo, :ptr IScriptErrorList, :UINT, :LCID, :ptr ptr ITypeInfo
            ;* [out] *
            DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
            ;* [in] *
            ;* [size_is][in] *
            ;* [range][in] *
            ;* [in] *
            STD_METHOD GetIDsOfNames, :ptr IScriptErrorList, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
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
            STD_METHOD Invoke_, :ptr IScriptErrorList, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
            DECLSPEC_XFGVIRT(IScriptErrorList, advanceError)
            ;* [id] *
            STD_METHOD advanceError, :ptr IScriptErrorList
            DECLSPEC_XFGVIRT(IScriptErrorList, retreatError)
            ;* [id] *
            STD_METHOD retreatError, :ptr IScriptErrorList
            DECLSPEC_XFGVIRT(IScriptErrorList, canAdvanceError)
            ;* [id] *
            STD_METHOD canAdvanceError, :ptr IScriptErrorList, :ptr BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IScriptErrorList, canRetreatError)
            ;* [id] *
            STD_METHOD canRetreatError, :ptr IScriptErrorList, :ptr BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IScriptErrorList, getErrorLine)
            ;* [id] *
            STD_METHOD getErrorLine, :ptr IScriptErrorList, :ptr LONG
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IScriptErrorList, getErrorChar)
            ;* [id] *
            STD_METHOD getErrorChar, :ptr IScriptErrorList, :ptr LONG
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IScriptErrorList, getErrorCode)
            ;* [id] *
            STD_METHOD getErrorCode, :ptr IScriptErrorList, :ptr LONG
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IScriptErrorList, getErrorMsg)
            ;* [id] *
            STD_METHOD getErrorMsg, :ptr IScriptErrorList, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IScriptErrorList, getErrorUrl)
            ;* [id] *
            STD_METHOD getErrorUrl, :ptr IScriptErrorList, :ptr BSTR
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IScriptErrorList, getAlwaysShowLockState)
            ;* [id] *
            STD_METHOD getAlwaysShowLockState, :ptr IScriptErrorList, :ptr BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IScriptErrorList, getDetailsPaneOpen)
            ;* [id] *
            STD_METHOD getDetailsPaneOpen, :ptr IScriptErrorList, :ptr BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IScriptErrorList, setDetailsPaneOpen)
            ;* [id] *
            STD_METHOD setDetailsPaneOpen, :ptr IScriptErrorList, :BOOL
            DECLSPEC_XFGVIRT(IScriptErrorList, getPerErrorDisplay)
            ;* [id] *
            STD_METHOD getPerErrorDisplay, :ptr IScriptErrorList, :ptr BOOL
            ;* [retval][out] *
            DECLSPEC_XFGVIRT(IScriptErrorList, setPerErrorDisplay)
            ;* [id] *
            STD_METHOD setPerErrorDisplay, :ptr IScriptErrorList, :BOOL
            ??Interface equ <>
            END_INTERFACE
          IScriptErrorListVtbl ends
          IScriptErrorList struct
            lpVtbl POINTER ?
          IScriptErrorList ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IScriptErrorList_INTERFACE_DEFINED__ *
      endif
      externdef CLSID_CScriptErrorList:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      ;* __SHDocVw_LIBRARY_DEFINED__ *
    endif
    ;* interface __MIDL_itf_exdisp_0000_0001 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  externdef __MIDL_itf_exdisp_0000_0001_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_exdisp_0000_0001_v0_0_s_ifspec:RPC_IF_HANDLE
  ;* Additional Prototypes for ALL interfaces *
  ;* end of Additional Prototypes *
  ifdef __cplusplus
    ;[...]
  endif
endif
