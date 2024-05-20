;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\urlmon.h
;             Created on (UTC) 06/04/2024 06:16:02
;             Last modified on (UTC) 21/02/2024 18:16:58

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
ifndef __urlmon_h__
  __urlmon_h__ equ <>
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
  ifndef __IPersistMoniker_FWD_DEFINED__
    __IPersistMoniker_FWD_DEFINED__ equ <>
    ;* __IPersistMoniker_FWD_DEFINED__ *
  endif
  ifndef __IMonikerProp_FWD_DEFINED__
    __IMonikerProp_FWD_DEFINED__ equ <>
    ;* __IMonikerProp_FWD_DEFINED__ *
  endif
  ifndef __IBindProtocol_FWD_DEFINED__
    __IBindProtocol_FWD_DEFINED__ equ <>
    ;* __IBindProtocol_FWD_DEFINED__ *
  endif
  ifndef __IBinding_FWD_DEFINED__
    __IBinding_FWD_DEFINED__ equ <>
    ;* __IBinding_FWD_DEFINED__ *
  endif
  ifndef __IBindStatusCallback_FWD_DEFINED__
    __IBindStatusCallback_FWD_DEFINED__ equ <>
    ;* __IBindStatusCallback_FWD_DEFINED__ *
  endif
  ifndef __IBindStatusCallbackEx_FWD_DEFINED__
    __IBindStatusCallbackEx_FWD_DEFINED__ equ <>
    ;* __IBindStatusCallbackEx_FWD_DEFINED__ *
  endif
  ifndef __IAuthenticate_FWD_DEFINED__
    __IAuthenticate_FWD_DEFINED__ equ <>
    ;* __IAuthenticate_FWD_DEFINED__ *
  endif
  ifndef __IAuthenticateEx_FWD_DEFINED__
    __IAuthenticateEx_FWD_DEFINED__ equ <>
    ;* __IAuthenticateEx_FWD_DEFINED__ *
  endif
  ifndef __IHttpNegotiate_FWD_DEFINED__
    __IHttpNegotiate_FWD_DEFINED__ equ <>
    ;* __IHttpNegotiate_FWD_DEFINED__ *
  endif
  ifndef __IHttpNegotiate2_FWD_DEFINED__
    __IHttpNegotiate2_FWD_DEFINED__ equ <>
    ;* __IHttpNegotiate2_FWD_DEFINED__ *
  endif
  ifndef __IHttpNegotiate3_FWD_DEFINED__
    __IHttpNegotiate3_FWD_DEFINED__ equ <>
    ;* __IHttpNegotiate3_FWD_DEFINED__ *
  endif
  ifndef __IWinInetFileStream_FWD_DEFINED__
    __IWinInetFileStream_FWD_DEFINED__ equ <>
    ;* __IWinInetFileStream_FWD_DEFINED__ *
  endif
  ifndef __IWindowForBindingUI_FWD_DEFINED__
    __IWindowForBindingUI_FWD_DEFINED__ equ <>
    ;* __IWindowForBindingUI_FWD_DEFINED__ *
  endif
  ifndef __ICodeInstall_FWD_DEFINED__
    __ICodeInstall_FWD_DEFINED__ equ <>
    ;* __ICodeInstall_FWD_DEFINED__ *
  endif
  ifndef __IUri_FWD_DEFINED__
    __IUri_FWD_DEFINED__ equ <>
    ;* __IUri_FWD_DEFINED__ *
  endif
  ifndef __IUriContainer_FWD_DEFINED__
    __IUriContainer_FWD_DEFINED__ equ <>
    ;* __IUriContainer_FWD_DEFINED__ *
  endif
  ifndef __IUriBuilder_FWD_DEFINED__
    __IUriBuilder_FWD_DEFINED__ equ <>
    ;* __IUriBuilder_FWD_DEFINED__ *
  endif
  ifndef __IUriBuilderFactory_FWD_DEFINED__
    __IUriBuilderFactory_FWD_DEFINED__ equ <>
    ;* __IUriBuilderFactory_FWD_DEFINED__ *
  endif
  ifndef __IWinInetInfo_FWD_DEFINED__
    __IWinInetInfo_FWD_DEFINED__ equ <>
    ;* __IWinInetInfo_FWD_DEFINED__ *
  endif
  ifndef __IHttpSecurity_FWD_DEFINED__
    __IHttpSecurity_FWD_DEFINED__ equ <>
    ;* __IHttpSecurity_FWD_DEFINED__ *
  endif
  ifndef __IWinInetHttpInfo_FWD_DEFINED__
    __IWinInetHttpInfo_FWD_DEFINED__ equ <>
    ;* __IWinInetHttpInfo_FWD_DEFINED__ *
  endif
  ifndef __IWinInetHttpTimeouts_FWD_DEFINED__
    __IWinInetHttpTimeouts_FWD_DEFINED__ equ <>
    ;* __IWinInetHttpTimeouts_FWD_DEFINED__ *
  endif
  ifndef __IWinInetCacheHints_FWD_DEFINED__
    __IWinInetCacheHints_FWD_DEFINED__ equ <>
    ;* __IWinInetCacheHints_FWD_DEFINED__ *
  endif
  ifndef __IWinInetCacheHints2_FWD_DEFINED__
    __IWinInetCacheHints2_FWD_DEFINED__ equ <>
    ;* __IWinInetCacheHints2_FWD_DEFINED__ *
  endif
  ifndef __IBindHost_FWD_DEFINED__
    __IBindHost_FWD_DEFINED__ equ <>
    ;* __IBindHost_FWD_DEFINED__ *
  endif
  ifndef __IInternet_FWD_DEFINED__
    __IInternet_FWD_DEFINED__ equ <>
    ;* __IInternet_FWD_DEFINED__ *
  endif
  ifndef __IInternetBindInfo_FWD_DEFINED__
    __IInternetBindInfo_FWD_DEFINED__ equ <>
    ;* __IInternetBindInfo_FWD_DEFINED__ *
  endif
  ifndef __IInternetBindInfoEx_FWD_DEFINED__
    __IInternetBindInfoEx_FWD_DEFINED__ equ <>
    ;* __IInternetBindInfoEx_FWD_DEFINED__ *
  endif
  ifndef __IInternetProtocolRoot_FWD_DEFINED__
    __IInternetProtocolRoot_FWD_DEFINED__ equ <>
    ;* __IInternetProtocolRoot_FWD_DEFINED__ *
  endif
  ifndef __IInternetProtocol_FWD_DEFINED__
    __IInternetProtocol_FWD_DEFINED__ equ <>
    ;* __IInternetProtocol_FWD_DEFINED__ *
  endif
  ifndef __IInternetProtocolEx_FWD_DEFINED__
    __IInternetProtocolEx_FWD_DEFINED__ equ <>
    ;* __IInternetProtocolEx_FWD_DEFINED__ *
  endif
  ifndef __IInternetProtocolSink_FWD_DEFINED__
    __IInternetProtocolSink_FWD_DEFINED__ equ <>
    ;* __IInternetProtocolSink_FWD_DEFINED__ *
  endif
  ifndef __IInternetProtocolSinkStackable_FWD_DEFINED__
    __IInternetProtocolSinkStackable_FWD_DEFINED__ equ <>
    ;* __IInternetProtocolSinkStackable_FWD_DEFINED__ *
  endif
  ifndef __IInternetSession_FWD_DEFINED__
    __IInternetSession_FWD_DEFINED__ equ <>
    ;* __IInternetSession_FWD_DEFINED__ *
  endif
  ifndef __IInternetThreadSwitch_FWD_DEFINED__
    __IInternetThreadSwitch_FWD_DEFINED__ equ <>
    ;* __IInternetThreadSwitch_FWD_DEFINED__ *
  endif
  ifndef __IInternetPriority_FWD_DEFINED__
    __IInternetPriority_FWD_DEFINED__ equ <>
    ;* __IInternetPriority_FWD_DEFINED__ *
  endif
  ifndef __IInternetProtocolInfo_FWD_DEFINED__
    __IInternetProtocolInfo_FWD_DEFINED__ equ <>
    ;* __IInternetProtocolInfo_FWD_DEFINED__ *
  endif
  ifndef __IInternetSecurityMgrSite_FWD_DEFINED__
    __IInternetSecurityMgrSite_FWD_DEFINED__ equ <>
    ;* __IInternetSecurityMgrSite_FWD_DEFINED__ *
  endif
  ifndef __IInternetSecurityManager_FWD_DEFINED__
    __IInternetSecurityManager_FWD_DEFINED__ equ <>
    ;* __IInternetSecurityManager_FWD_DEFINED__ *
  endif
  ifndef __IInternetSecurityManagerEx_FWD_DEFINED__
    __IInternetSecurityManagerEx_FWD_DEFINED__ equ <>
    ;* __IInternetSecurityManagerEx_FWD_DEFINED__ *
  endif
  ifndef __IInternetSecurityManagerEx2_FWD_DEFINED__
    __IInternetSecurityManagerEx2_FWD_DEFINED__ equ <>
    ;* __IInternetSecurityManagerEx2_FWD_DEFINED__ *
  endif
  ifndef __IZoneIdentifier_FWD_DEFINED__
    __IZoneIdentifier_FWD_DEFINED__ equ <>
    ;* __IZoneIdentifier_FWD_DEFINED__ *
  endif
  ifndef __IZoneIdentifier2_FWD_DEFINED__
    __IZoneIdentifier2_FWD_DEFINED__ equ <>
    ;* __IZoneIdentifier2_FWD_DEFINED__ *
  endif
  ifndef __IInternetHostSecurityManager_FWD_DEFINED__
    __IInternetHostSecurityManager_FWD_DEFINED__ equ <>
    ;* __IInternetHostSecurityManager_FWD_DEFINED__ *
  endif
  ifndef __IInternetZoneManager_FWD_DEFINED__
    __IInternetZoneManager_FWD_DEFINED__ equ <>
    ;* __IInternetZoneManager_FWD_DEFINED__ *
  endif
  ifndef __IInternetZoneManagerEx_FWD_DEFINED__
    __IInternetZoneManagerEx_FWD_DEFINED__ equ <>
    ;* __IInternetZoneManagerEx_FWD_DEFINED__ *
  endif
  ifndef __IInternetZoneManagerEx2_FWD_DEFINED__
    __IInternetZoneManagerEx2_FWD_DEFINED__ equ <>
    ;* __IInternetZoneManagerEx2_FWD_DEFINED__ *
  endif
  ifndef __ISoftDistExt_FWD_DEFINED__
    __ISoftDistExt_FWD_DEFINED__ equ <>
    ;* __ISoftDistExt_FWD_DEFINED__ *
  endif
  ifndef __ICatalogFileInfo_FWD_DEFINED__
    __ICatalogFileInfo_FWD_DEFINED__ equ <>
    ;* __ICatalogFileInfo_FWD_DEFINED__ *
  endif
  ifndef __IDataFilter_FWD_DEFINED__
    __IDataFilter_FWD_DEFINED__ equ <>
    ;* __IDataFilter_FWD_DEFINED__ *
  endif
  ifndef __IEncodingFilterFactory_FWD_DEFINED__
    __IEncodingFilterFactory_FWD_DEFINED__ equ <>
    ;* __IEncodingFilterFactory_FWD_DEFINED__ *
  endif
  ifndef __IWrappedProtocol_FWD_DEFINED__
    __IWrappedProtocol_FWD_DEFINED__ equ <>
    ;* __IWrappedProtocol_FWD_DEFINED__ *
  endif
  ifndef __IGetBindHandle_FWD_DEFINED__
    __IGetBindHandle_FWD_DEFINED__ equ <>
    ;* __IGetBindHandle_FWD_DEFINED__ *
  endif
  ifndef __IBindCallbackRedirect_FWD_DEFINED__
    __IBindCallbackRedirect_FWD_DEFINED__ equ <>
    ;* __IBindCallbackRedirect_FWD_DEFINED__ *
  endif
  ifndef __IBindHttpSecurity_FWD_DEFINED__
    __IBindHttpSecurity_FWD_DEFINED__ equ <>
    ;* __IBindHttpSecurity_FWD_DEFINED__ *
  endif
  ;* header files for imported files *
  include objidl.inc
  include oleidl.inc
  include servprov.inc
  include msxml.inc
  ifdef __cplusplus
    ;[...]
  endif
  ;* interface __MIDL_itf_urlmon_0000_0000 *
  ;* [local] *
  ;=--------------------------------------------------------------------------=
  ; UrlMon.h
  ;=--------------------------------------------------------------------------=
  ; Copyright (c) Microsoft Corporation.  All rights reserved.
  ; THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
  ; ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
  ; THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
  ; PARTICULAR PURPOSE.
  ;=--------------------------------------------------------------------------=
  ;---------------------------------------------------------------------------=
  ; URL Moniker Interfaces.
  include winapifamily.inc
  if _MSC_VER ge 1200
    ifndef _MSC_EXTENSIONS
      ;* truncation of constant value *
    endif
    ;* padding added after data member *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ; Side-by-Side clsid
    externdef CLSID_SBS_StdURLMoniker:IID
    externdef CLSID_SBS_HttpProtocol:IID
    externdef CLSID_SBS_FtpProtocol:IID
    externdef CLSID_SBS_GopherProtocol:IID
    externdef CLSID_SBS_HttpSProtocol:IID
    externdef CLSID_SBS_FileProtocol:IID
    externdef CLSID_SBS_MkProtocol:IID
    externdef CLSID_SBS_UrlMkBindCtx:IID
    externdef CLSID_SBS_SoftDistExt:IID
    externdef CLSID_SBS_CdlProtocol:IID
    externdef CLSID_SBS_ClassInstallFilter:IID
    externdef CLSID_SBS_InternetSecurityManager:IID
    externdef CLSID_SBS_InternetZoneManager:IID
    ; END Side-by-Side clsid
    ; These are for backwards compatibility with previous URLMON versions
    BINDF_DONTUSECACHE equ <BINDF_GETNEWESTVERSION>
    BINDF_DONTPUTINCACHE equ <BINDF_NOWRITECACHE>
    BINDF_NOCOPYDATA equ <BINDF_PULLDATA>
    INVALID_P_ROOT_SECURITY_ID equ (- 1)
    PI_DOCFILECLSIDLOOKUP equ <PI_CLSIDLOOKUP>
    externdef IID_IAsyncMoniker:IID
    externdef CLSID_StdURLMoniker:IID
    externdef CLSID_HttpProtocol:IID
    externdef CLSID_FtpProtocol:IID
    externdef CLSID_GopherProtocol:IID
    externdef CLSID_HttpSProtocol:IID
    externdef CLSID_FileProtocol:IID
    externdef CLSID_ResProtocol:IID
    externdef CLSID_AboutProtocol:IID
    externdef CLSID_JSProtocol:IID
    externdef CLSID_MailtoProtocol:IID
    externdef CLSID_IE4_PROTOCOLS:IID
    externdef CLSID_MkProtocol:IID
    externdef CLSID_StdURLProtocol:IID
    externdef CLSID_TBAuthProtocol:IID
    externdef CLSID_UrlMkBindCtx:IID
    externdef CLSID_CdlProtocol:IID
    externdef CLSID_ClassInstallFilter:IID
    externdef IID_IAsyncBindCtx:IID
    SZ_URLCONTEXT equ <OLESTR("URL Context")>
    SZ_ASYNC_CALLEE equ <OLESTR("AsyncCallee")>
    MKSYS_URLMONIKER equ 6
    URL_MK_LEGACY equ 0
    URL_MK_UNIFORM equ 1
    URL_MK_NO_CANONICALIZE equ 2
    @DefProto DllImport, CreateURLMoniker, WIN_STD_CALL_CONV,, <:LPMONIKER, :LPCWSTR, :ptr LPMONIKER>, 12
    @DefProto DllImport, CreateURLMonikerEx, WIN_STD_CALL_CONV,, <:LPMONIKER, :LPCWSTR, :ptr LPMONIKER, :DWORD>, 16
    @DefProto DllImport, GetClassURL, WIN_STD_CALL_CONV,, <:LPCWSTR, :ptr CLSID>, 8
    @DefProto DllImport, CreateAsyncBindCtx, WIN_STD_CALL_CONV,, <:DWORD, :ptr IBindStatusCallback, :ptr IEnumFORMATETC, :ptr ptr IBindCtx>, 16
    if (_WIN32_IE ge _WIN32_IE_IE70)
      @DefProto DllImport, CreateURLMonikerEx2, WIN_STD_CALL_CONV,, <:LPMONIKER, :ptr IUri, :ptr LPMONIKER, :DWORD>, 16
    endif
    @DefProto DllImport, CreateAsyncBindCtxEx, WIN_STD_CALL_CONV,, <:ptr IBindCtx, :DWORD, :ptr IBindStatusCallback, :ptr IEnumFORMATETC, :ptr ptr IBindCtx, :DWORD>, 24
    @DefProto DllImport, MkParseDisplayNameEx, WIN_STD_CALL_CONV,, <:ptr IBindCtx, :LPCWSTR, :ptr ULONG, :ptr LPMONIKER>, 16
    @DefProto DllImport, RegisterBindStatusCallback, WIN_STD_CALL_CONV,, <:LPBC, :ptr IBindStatusCallback, :ptr ptr IBindStatusCallback, :DWORD>, 16
    @DefProto DllImport, RevokeBindStatusCallback, WIN_STD_CALL_CONV,, <:LPBC, :ptr IBindStatusCallback>, 8
    @DefProto DllImport, GetClassFileOrMime, WIN_STD_CALL_CONV,, <:LPBC, :LPCWSTR, :LPVOID, :DWORD, :LPCWSTR, :DWORD, :ptr CLSID>, 28
    @DefProto DllImport, IsValidURL, WIN_STD_CALL_CONV,, <:LPBC, :LPCWSTR, :DWORD>, 12
    @DefProto DllImport, CoGetClassObjectFromURL, WIN_STD_CALL_CONV,, <:REFCLSID, :LPCWSTR, :DWORD, :DWORD, :LPCWSTR, :LPBINDCTX, :DWORD, :LPVOID, :REFIID, :ptr LPVOID>, 40
    @DefProto DllImport, IEInstallScope, WIN_STD_CALL_CONV,, <:LPDWORD>, 4
    @DefProto DllImport, FaultInIEFeature, WIN_STD_CALL_CONV,, <:HWND, :ptr uCLSSPEC, :ptr QUERYCONTEXT, :DWORD>, 16
    @DefProto DllImport, GetComponentIDFromCLSSPEC, WIN_STD_CALL_CONV,, <:ptr uCLSSPEC, :ptr LPSTR>, 8
    ; flags for FaultInIEFeature
    FIEF_FLAG_FORCE_JITUI equ 1h; force JIT ui even if

    ; previoulsy rejected by 
    ; user in this session or
    ; marked as Never Ask Again
    FIEF_FLAG_PEEK equ 2h; just peek, don't faultin

    FIEF_FLAG_SKIP_INSTALLED_VERSION_CHECK equ 4h; force JIT without checking local version

    FIEF_FLAG_RESERVED_0 equ 8h; reserved

    ;helper apis                                                                               
    @DefProto DllImport, IsAsyncMoniker, WIN_STD_CALL_CONV,, <:ptr IMoniker>, 4
    @DefProto DllImport, CreateURLBinding, WIN_STD_CALL_CONV,, <:LPCWSTR, :ptr IBindCtx, :ptr ptr IBinding>, 12
    @DefProto DllImport, RegisterMediaTypes, WIN_STD_CALL_CONV,, <:UINT, :ptr LPCSTR, :ptr CLIPFORMAT>, 12
    @DefProto DllImport, FindMediaType, WIN_STD_CALL_CONV,, <:LPCSTR, :ptr CLIPFORMAT>, 8
    @DefProto DllImport, CreateFormatEnumerator, WIN_STD_CALL_CONV,, <:UINT, :ptr FORMATETC, :ptr ptr IEnumFORMATETC>, 12
    @DefProto DllImport, RegisterFormatEnumerator, WIN_STD_CALL_CONV,, <:LPBC, :ptr IEnumFORMATETC, :DWORD>, 12
    @DefProto DllImport, RevokeFormatEnumerator, WIN_STD_CALL_CONV,, <:LPBC, :ptr IEnumFORMATETC>, 8
    @DefProto DllImport, RegisterMediaTypeClass, WIN_STD_CALL_CONV,, <:LPBC, :UINT, :ptr LPCSTR, :ptr CLSID, :DWORD>, 20
    @DefProto DllImport, FindMediaTypeClass, WIN_STD_CALL_CONV,, <:LPBC, :LPCSTR, :ptr CLSID, :DWORD>, 16
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, UrlMkSetSessionOption, WIN_STD_CALL_CONV,, <:DWORD, :LPVOID, :DWORD, :DWORD>, 16
    @DefProto DllImport, UrlMkGetSessionOption, WIN_STD_CALL_CONV,, <:DWORD, :LPVOID, :DWORD, :ptr DWORD, :DWORD>, 20
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    @DefProto DllImport, FindMimeFromData, WIN_STD_CALL_CONV,, <:LPBC, :LPCWSTR, :LPVOID, :DWORD, :LPCWSTR, :DWORD, :ptr LPWSTR, :DWORD>, 32
    ; the suggested mime                                                         
    ; must be 0                                                                  
    FMFD_DEFAULT equ 00000000h
    FMFD_URLASFILENAME equ 00000001h
    if (_WIN32_IE ge _WIN32_IE_IE60SP2)
      FMFD_ENABLEMIMESNIFFING equ 00000002h
      FMFD_IGNOREMIMETEXTPLAIN equ 00000004h
    endif
    ;(_WIN32_IE >= _WIN32_IE_IE60SP2)
    FMFD_SERVERMIME equ 00000008h
    FMFD_RESPECTTEXTPLAIN equ 00000010h
    FMFD_RETURNUPDATEDIMGMIMES equ 00000020h
    FMFD_RESERVED_1 equ 00000040h
    FMFD_RESERVED_2 equ 00000080h
    UAS_EXACTLEGACY equ 00001000h
    @DefProto DllImport, ObtainUserAgentString, WIN_STD_CALL_CONV,, <:DWORD, :LPSTR, :ptr DWORD>, 12
    @DefProto DllImport, CompareSecurityIds, WIN_STD_CALL_CONV,, <:ptr BYTE, :DWORD, :ptr BYTE, :DWORD, :DWORD>, 20
    @DefProto DllImport, CompatFlagsFromClsid, WIN_STD_CALL_CONV,, <:ptr CLSID, :LPDWORD, :LPDWORD>, 12
    if (NTDDI_VERSION gt NTDDI_WINBLUE or (NTDDI_VERSION eq NTDDI_WINBLUE and Defined(WINBLUE_KBSPRING14)))
      ; Enhanced Protected Mode (EPM) Convenience Functions
      IEObjectType typedef SDWORD
      IE_EPM_OBJECT_EVENT equ 0
      IE_EPM_OBJECT_MUTEX equ 1
      IE_EPM_OBJECT_SEMAPHORE equ 2
      IE_EPM_OBJECT_SHARED_MEMORY equ 3
      IE_EPM_OBJECT_WAITABLE_TIMER equ 4
      IE_EPM_OBJECT_FILE equ 5
      IE_EPM_OBJECT_NAMED_PIPE equ 6
      IE_EPM_OBJECT_REGISTRY equ 7

      @DefProto DllImport, SetAccessForIEAppContainer, WIN_STD_CALL_CONV,, <:HANDLE, :IEObjectType, :DWORD>, 12
    endif
    ; URLMON-specific defines for UrlMkSetSessionOption() above
    URLMON_OPTION_USERAGENT equ 10000001h
    URLMON_OPTION_USERAGENT_REFRESH equ 10000002h
    URLMON_OPTION_URL_ENCODING equ 10000004h
    if (_WIN32_IE ge _WIN32_IE_IE60SP2)
      URLMON_OPTION_USE_BINDSTRINGCREDS equ 10000008h
    endif
    ;(_WIN32_IE >= _WIN32_IE_IE60SP2)
    if (_WIN32_IE ge _WIN32_IE_IE70)
      URLMON_OPTION_USE_BROWSERAPPSDOCUMENTS equ 10000010h
    endif
    ;(_WIN32_IE >= _WIN32_IE_IE70)
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    CF_NULL equ 0
    CFSTR_MIME_NULL equ <NULL>
    CFSTR_MIME_TEXT equ <(TEXT("text/plain"))>
    CFSTR_MIME_RICHTEXT equ <(TEXT("text/richtext"))>
    CFSTR_MIME_MANIFEST equ <(TEXT("text/cache-manifest"))>
    CFSTR_MIME_WEBVTT equ <(TEXT("text/vtt"))>
    CFSTR_MIME_X_BITMAP equ <(TEXT("image/x-xbitmap"))>
    CFSTR_MIME_POSTSCRIPT equ <(TEXT("application/postscript"))>
    CFSTR_MIME_AIFF equ <(TEXT("audio/aiff"))>
    CFSTR_MIME_BASICAUDIO equ <(TEXT("audio/basic"))>
    CFSTR_MIME_WAV equ <(TEXT("audio/wav"))>
    CFSTR_MIME_X_WAV equ <(TEXT("audio/x-wav"))>
    CFSTR_MIME_GIF equ <(TEXT("image/gif"))>
    CFSTR_MIME_PJPEG equ <(TEXT("image/pjpeg"))>
    CFSTR_MIME_JPEG equ <(TEXT("image/jpeg"))>
    CFSTR_MIME_TIFF equ <(TEXT("image/tiff"))>
    CFSTR_MIME_JPEG_XR equ <(TEXT("image/vnd.ms-photo"))>
    CFSTR_MIME_PNG equ <(TEXT("image/png"))>
    CFSTR_MIME_DDS equ <(TEXT("image/vnd.ms-dds"))>
    CFSTR_MIME_X_PNG equ <(TEXT("image/x-png"))>
    CFSTR_MIME_X_ICON equ <(TEXT("image/x-icon"))>
    CFSTR_MIME_SVG_XML equ <(TEXT("image/svg+xml"))>
    CFSTR_MIME_BMP equ <(TEXT("image/bmp"))>
    CFSTR_MIME_X_EMF equ <(TEXT("image/x-emf"))>
    CFSTR_MIME_X_WMF equ <(TEXT("image/x-wmf"))>
    CFSTR_MIME_AVI equ <(TEXT("video/avi"))>
    CFSTR_MIME_MPEG equ <(TEXT("video/mpeg"))>
    CFSTR_MIME_FRACTALS equ <(TEXT("application/fractals"))>
    CFSTR_MIME_RAWDATA equ <(TEXT("application/octet-stream"))>
    CFSTR_MIME_RAWDATASTRM equ <(TEXT("application/octet-stream"))>
    CFSTR_MIME_PDF equ <(TEXT("application/pdf"))>
    CFSTR_MIME_HTA equ <(TEXT("application/hta"))>
    CFSTR_MIME_APP_XML equ <(TEXT("application/xml"))>
    CFSTR_MIME_XHTML equ <(TEXT("application/xhtml+xml"))>
    CFSTR_MIME_X_AIFF equ <(TEXT("audio/x-aiff"))>
    CFSTR_MIME_X_REALAUDIO equ <(TEXT("audio/x-pn-realaudio"))>
    CFSTR_MIME_XBM equ <(TEXT("image/xbm"))>
    CFSTR_MIME_QUICKTIME equ <(TEXT("video/quicktime"))>
    CFSTR_MIME_X_MSVIDEO equ <(TEXT("video/x-msvideo"))>
    CFSTR_MIME_X_SGI_MOVIE equ <(TEXT("video/x-sgi-movie"))>
    CFSTR_MIME_X_MIXED_REPLACE equ <(TEXT("multipart/x-mixed-replace"))>
    CFSTR_MIME_HTML equ <(TEXT("text/html"))>
    CFSTR_MIME_XML equ <(TEXT("text/xml"))>
    CFSTR_MIME_TTML equ <(TEXT("application/ttml+xml"))>
    CFSTR_MIME_TTAF equ <(TEXT("application/ttaf+xml"))>
    CFSTR_MIME_X_JAVASCRIPT equ <(TEXT("application/x-javascript"))>
    CFSTR_MIME_TEXT_JSON equ <(TEXT("text/json"))>
    CFSTR_MIME_APPLICATION_JAVASCRIPT equ <(TEXT("application/javascript"))>
    ; MessageId: MK_S_ASYNCHRONOUS                                              
    ; MessageText: Operation is successful, but will complete asynchronously.   
    ;                                                                           
    MK_S_ASYNCHRONOUS equ _HRESULT_TYPEDEF_(000401E8h)
    ifndef S_ASYNCHRONOUS
      S_ASYNCHRONOUS equ <MK_S_ASYNCHRONOUS>
    endif
    ifndef E_PENDING
      E_PENDING equ _HRESULT_TYPEDEF_(8000000Ah)
    endif
    ;                                                                           
    ;                                                                           
    ; WinINet and protocol specific errors are mapped to one of the following   
    ; error which are returned in IBSC::OnStopBinding                           
    ;                                                                           
    ;                                                                           
    ; Note: FACILITY C is split into ranges of 1k                               
    ; C0000 - C03FF  INET_E_ (URLMON's original hresult)                        
    ; C0400 - C07FF  INET_E_CLIENT_xxx                                          
    ; C0800 - C0BFF  INET_E_SERVER_xxx                                          
    ; C0C00 - C0FFF  INET_E_????                                                
    ; C1000 - C13FF  INET_E_AGENT_xxx (info delivery agents)                    
    INET_E_INVALID_URL equ _HRESULT_TYPEDEF_(800C0002h)
    INET_E_NO_SESSION equ _HRESULT_TYPEDEF_(800C0003h)
    INET_E_CANNOT_CONNECT equ _HRESULT_TYPEDEF_(800C0004h)
    INET_E_RESOURCE_NOT_FOUND equ _HRESULT_TYPEDEF_(800C0005h)
    INET_E_OBJECT_NOT_FOUND equ _HRESULT_TYPEDEF_(800C0006h)
    INET_E_DATA_NOT_AVAILABLE equ _HRESULT_TYPEDEF_(800C0007h)
    INET_E_DOWNLOAD_FAILURE equ _HRESULT_TYPEDEF_(800C0008h)
    INET_E_AUTHENTICATION_REQUIRED equ _HRESULT_TYPEDEF_(800C0009h)
    INET_E_NO_VALID_MEDIA equ _HRESULT_TYPEDEF_(800C000Ah)
    INET_E_CONNECTION_TIMEOUT equ _HRESULT_TYPEDEF_(800C000Bh)
    INET_E_INVALID_REQUEST equ _HRESULT_TYPEDEF_(800C000Ch)
    INET_E_UNKNOWN_PROTOCOL equ _HRESULT_TYPEDEF_(800C000Dh)
    INET_E_SECURITY_PROBLEM equ _HRESULT_TYPEDEF_(800C000Eh)
    INET_E_CANNOT_LOAD_DATA equ _HRESULT_TYPEDEF_(800C000Fh)
    INET_E_CANNOT_INSTANTIATE_OBJECT equ _HRESULT_TYPEDEF_(800C0010h)
    INET_E_INVALID_CERTIFICATE equ _HRESULT_TYPEDEF_(800C0019h)
    INET_E_REDIRECT_FAILED equ _HRESULT_TYPEDEF_(800C0014h)
    INET_E_REDIRECT_TO_DIR equ _HRESULT_TYPEDEF_(800C0015h)
    INET_E_CANNOT_LOCK_REQUEST equ _HRESULT_TYPEDEF_(800C0016h)
    INET_E_USE_EXTEND_BINDING equ _HRESULT_TYPEDEF_(800C0017h)
    INET_E_TERMINATED_BIND equ _HRESULT_TYPEDEF_(800C0018h)
    INET_E_RESERVED_1 equ _HRESULT_TYPEDEF_(800C001Ah)
    INET_E_BLOCKED_REDIRECT_XSECURITYID equ _HRESULT_TYPEDEF_(800C001Bh)
    INET_E_DOMINJECTIONVALIDATION equ _HRESULT_TYPEDEF_(800C001Ch)
    INET_E_VTAB_SWITCH_FORCE_ENGINE equ _HRESULT_TYPEDEF_(800C001Dh)
    INET_E_HSTS_CERTIFICATE_ERROR equ _HRESULT_TYPEDEF_(800C001Eh)
    INET_E_RESERVED_2 equ _HRESULT_TYPEDEF_(800C001Fh)
    INET_E_RESERVED_3 equ _HRESULT_TYPEDEF_(800C0020h)
    INET_E_RESERVED_4 equ _HRESULT_TYPEDEF_(800C0021h)
    INET_E_RESERVED_5 equ _HRESULT_TYPEDEF_(800C0022h)
    INET_E_ERROR_FIRST equ _HRESULT_TYPEDEF_(800C0002h)
    INET_E_CODE_DOWNLOAD_DECLINED equ _HRESULT_TYPEDEF_(800C0100h)
    INET_E_RESULT_DISPATCHED equ _HRESULT_TYPEDEF_(800C0200h)
    INET_E_CANNOT_REPLACE_SFP_FILE equ _HRESULT_TYPEDEF_(800C0300h)
    if (_WIN32_IE ge _WIN32_IE_IE60SP2)
      INET_E_CODE_INSTALL_SUPPRESSED equ _HRESULT_TYPEDEF_(800C0400h)
    endif
    ;(_WIN32_IE >= _WIN32_IE_IE60SP2)
    INET_E_CODE_INSTALL_BLOCKED_BY_HASH_POLICY equ _HRESULT_TYPEDEF_(800C0500h)
    INET_E_DOWNLOAD_BLOCKED_BY_INPRIVATE equ _HRESULT_TYPEDEF_(800C0501h)
    INET_E_CODE_INSTALL_BLOCKED_IMMERSIVE equ _HRESULT_TYPEDEF_(800C0502h)
    INET_E_FORBIDFRAMING equ _HRESULT_TYPEDEF_(800C0503h)
    INET_E_CODE_INSTALL_BLOCKED_ARM equ _HRESULT_TYPEDEF_(800C0504h)
    INET_E_BLOCKED_PLUGGABLE_PROTOCOL equ _HRESULT_TYPEDEF_(800C0505h)
    INET_E_BLOCKED_ENHANCEDPROTECTEDMODE equ _HRESULT_TYPEDEF_(800C0506h)
    INET_E_CODE_INSTALL_BLOCKED_BITNESS equ _HRESULT_TYPEDEF_(800C0507h)
    INET_E_DOWNLOAD_BLOCKED_BY_CSP equ _HRESULT_TYPEDEF_(800C0508h)
    INET_E_ERROR_LAST equ <INET_E_DOWNLOAD_BLOCKED_BY_CSP>
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef _LPPERSISTMONIKER_DEFINED
      _LPPERSISTMONIKER_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IPersistMoniker_INTERFACE_DEFINED__
        __IPersistMoniker_INTERFACE_DEFINED__ equ <>
        ;* interface IPersistMoniker *
        ;* [unique][uuid][object] *
        ;* [unique] *
        LPPERSISTMONIKER typedef ptr IPersistMoniker
        externdef IID_IPersistMoniker:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IPersistMonikerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IPersistMonikerVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IPersistMoniker, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IPersistMoniker
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IPersistMoniker
            DECLSPEC_XFGVIRT(IPersistMoniker, GetClassID)
            STD_METHOD GetClassID, :ptr IPersistMoniker, :ptr CLSID
            ;* [out] *
            DECLSPEC_XFGVIRT(IPersistMoniker, IsDirty)
            STD_METHOD IsDirty, :ptr IPersistMoniker
            DECLSPEC_XFGVIRT(IPersistMoniker, Load)
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD Load, :ptr IPersistMoniker, :BOOL, :ptr IMoniker, :LPBC, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IPersistMoniker, Save)
            ;* [in] *
            ;* [in] *
            STD_METHOD Save, :ptr IPersistMoniker, :ptr IMoniker, :LPBC, :BOOL
            ;* [in] *
            DECLSPEC_XFGVIRT(IPersistMoniker, SaveCompleted)
            ;* [in] *
            STD_METHOD SaveCompleted, :ptr IPersistMoniker, :ptr IMoniker, :LPBC
            ;* [in] *
            DECLSPEC_XFGVIRT(IPersistMoniker, GetCurMoniker)
            STD_METHOD GetCurMoniker, :ptr IPersistMoniker, :ptr ptr IMoniker
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IPersistMonikerVtbl ends
          IPersistMoniker struct
            lpVtbl POINTER ?
          IPersistMoniker ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IPersistMoniker_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0001 *
      ;* [local] *
    endif
    ifndef _LPMONIKERPROP_DEFINED
      _LPMONIKERPROP_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0001_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0001_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IMonikerProp_INTERFACE_DEFINED__
        __IMonikerProp_INTERFACE_DEFINED__ equ <>
        ;* interface IMonikerProp *
        ;* [unique][uuid][object] *
        ;* [unique] *
        LPMONIKERPROP typedef ptr IMonikerProp
        ;* [public][public] *
        MONIKERPROPERTY typedef SDWORD
        MIMETYPEPROP equ 0
        USE_SRC_URL equ 1h
        CLASSIDPROP equ 2h
        TRUSTEDDOWNLOADPROP equ 3h
        POPUPLEVELPROP equ 4h
        __MIDL_IMonikerProp_0001 typedef MONIKERPROPERTY

        externdef IID_IMonikerProp:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IMonikerPropVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IMonikerPropVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IMonikerProp, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IMonikerProp
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IMonikerProp
            DECLSPEC_XFGVIRT(IMonikerProp, PutProperty)
            ;* [in] *
            STD_METHOD PutProperty, :ptr IMonikerProp, :MONIKERPROPERTY, :LPCWSTR
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IMonikerPropVtbl ends
          IMonikerProp struct
            lpVtbl POINTER ?
          IMonikerProp ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IMonikerProp_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0002 *
      ;* [local] *
    endif
    ifndef _LPBINDPROTOCOL_DEFINED
      _LPBINDPROTOCOL_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0002_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0002_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IBindProtocol_INTERFACE_DEFINED__
        __IBindProtocol_INTERFACE_DEFINED__ equ <>
        ;* interface IBindProtocol *
        ;* [unique][uuid][object][local] *
        ;* [unique] *
        LPBINDPROTOCOL typedef ptr IBindProtocol
        externdef IID_IBindProtocol:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IBindProtocolVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IBindProtocolVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IBindProtocol, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IBindProtocol
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IBindProtocol
            DECLSPEC_XFGVIRT(IBindProtocol, CreateBinding)
            ;* [in] *
            ;* [in] *
            STD_METHOD CreateBinding, :ptr IBindProtocol, :LPCWSTR, :ptr IBindCtx, :ptr ptr IBinding
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IBindProtocolVtbl ends
          IBindProtocol struct
            lpVtbl POINTER ?
          IBindProtocol ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IBindProtocol_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0003 *
      ;* [local] *
    endif
    ifndef _LPBINDING_DEFINED
      _LPBINDING_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0003_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0003_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IBinding_INTERFACE_DEFINED__
        __IBinding_INTERFACE_DEFINED__ equ <>
        ;* interface IBinding *
        ;* [unique][uuid][object] *
        ;* [unique] *
        LPBINDING typedef ptr IBinding
        externdef IID_IBinding:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IBindingVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IBindingVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IBinding, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IBinding
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IBinding
            DECLSPEC_XFGVIRT(IBinding, Abort)
            STD_METHOD Abort, :ptr IBinding
            DECLSPEC_XFGVIRT(IBinding, Suspend)
            STD_METHOD Suspend, :ptr IBinding
            DECLSPEC_XFGVIRT(IBinding, Resume)
            STD_METHOD Resume, :ptr IBinding
            DECLSPEC_XFGVIRT(IBinding, SetPriority)
            STD_METHOD SetPriority, :ptr IBinding, :LONG
            ;* [in] *
            DECLSPEC_XFGVIRT(IBinding, GetPriority)
            STD_METHOD GetPriority, :ptr IBinding, :ptr LONG
            ;* [out] *
            DECLSPEC_XFGVIRT(IBinding, GetBindResult)
            ;* [local] *
            ;* [out] *
            ;* [out] *
            ;* [annotation][out] *
            STD_METHOD GetBindResult, :ptr IBinding, :ptr CLSID, :ptr DWORD, :ptr LPOLESTR, :ptr DWORD
            ;* [out][in] *
            ??Interface equ <>
            END_INTERFACE
          IBindingVtbl ends
          IBinding struct
            lpVtbl POINTER ?
          IBinding ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* [call_as] *
        IBinding_RemoteGetBindResult_Proxy proto WIN_STD_CALL_CONV :ptr IBinding, :ptr CLSID, :ptr DWORD, :ptr LPOLESTR, :DWORD
        ;* [in] *
        IBinding_RemoteGetBindResult_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        ;* __IBinding_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0004 *
      ;* [local] *
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    ifndef _LPBINDSTATUSCALLBACK_DEFINED
      _LPBINDSTATUSCALLBACK_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0004_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0004_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IBindStatusCallback_INTERFACE_DEFINED__
        __IBindStatusCallback_INTERFACE_DEFINED__ equ <>
        ;* interface IBindStatusCallback *
        ;* [unique][uuid][object] *
        ;* [unique] *
        LPBINDSTATUSCALLBACK typedef ptr IBindStatusCallback
        ;* [public] *
        BINDVERB typedef SDWORD
        BINDVERB_GET equ 0
        BINDVERB_POST equ 1h
        BINDVERB_PUT equ 2h
        BINDVERB_CUSTOM equ 3h
        BINDVERB_RESERVED1 equ 4h
        __MIDL_IBindStatusCallback_0001 typedef BINDVERB

        ;* [public] *
        BINDINFOF typedef SDWORD
        BINDINFOF_URLENCODESTGMEDDATA equ 1h
        BINDINFOF_URLENCODEDEXTRAINFO equ 2h
        __MIDL_IBindStatusCallback_0002 typedef BINDINFOF

        ;* [public] *
        BINDF typedef SDWORD
        BINDF_ASYNCHRONOUS equ 1h
        BINDF_ASYNCSTORAGE equ 2h
        BINDF_NOPROGRESSIVERENDERING equ 4h
        BINDF_OFFLINEOPERATION equ 8h
        BINDF_GETNEWESTVERSION equ 10h
        BINDF_NOWRITECACHE equ 20h
        BINDF_NEEDFILE equ 40h
        BINDF_PULLDATA equ 80h
        BINDF_IGNORESECURITYPROBLEM equ 100h
        BINDF_RESYNCHRONIZE equ 200h
        BINDF_HYPERLINK equ 400h
        BINDF_NO_UI equ 800h
        BINDF_SILENTOPERATION equ 1000h
        BINDF_PRAGMA_NO_CACHE equ 2000h
        BINDF_GETCLASSOBJECT equ 4000h
        BINDF_RESERVED_1 equ 8000h
        BINDF_FREE_THREADED equ 10000h
        BINDF_DIRECT_READ equ 20000h
        BINDF_FORMS_SUBMIT equ 40000h
        BINDF_GETFROMCACHE_IF_NET_FAIL equ 80000h
        BINDF_FROMURLMON equ 100000h
        BINDF_FWD_BACK equ 200000h
        BINDF_PREFERDEFAULTHANDLER equ 400000h
        BINDF_ENFORCERESTRICTED equ 800000h
        BINDF_RESERVED_2 equ 80000000h
        BINDF_RESERVED_3 equ 1000000h
        BINDF_RESERVED_4 equ 2000000h
        BINDF_RESERVED_5 equ 4000000h
        BINDF_RESERVED_6 equ 8000000h
        BINDF_RESERVED_7 equ 40000000h
        BINDF_RESERVED_8 equ 20000000h
        __MIDL_IBindStatusCallback_0003 typedef BINDF

        ;* [public] *
        URL_ENCODING typedef SDWORD
        URL_ENCODING_NONE equ 0
        URL_ENCODING_ENABLE_UTF8 equ 10000000h
        URL_ENCODING_DISABLE_UTF8 equ 20000000h
        __MIDL_IBindStatusCallback_0004 typedef URL_ENCODING

        BINDINFO struct
          cbSize DWORD ?
          szExtraInfo POINTER ?
          stgmedData STGMEDIUM <>
          grfBindInfoF DWORD ?
          dwBindVerb DWORD ?
          szCustomVerb POINTER ?
          cbstgmedData DWORD ?
          dwOptions DWORD ?
          dwOptionsFlags DWORD ?
          dwCodePage DWORD ?
          securityAttributes SECURITY_ATTRIBUTES <>
          iid IID <>
          pUnk POINTER ?
          dwReserved DWORD ?
        BINDINFO ends
        _tagBINDINFO typedef BINDINFO
        REMSECURITY_ATTRIBUTES struct
          nLength DWORD ?
          lpSecurityDescriptor DWORD ?
          bInheritHandle DWORD ?
        REMSECURITY_ATTRIBUTES ends
        _REMSECURITY_ATTRIBUTES typedef REMSECURITY_ATTRIBUTES
        PREMSECURITY_ATTRIBUTES typedef ptr _REMSECURITY_ATTRIBUTES
        LPREMSECURITY_ATTRIBUTES typedef ptr _REMSECURITY_ATTRIBUTES
        RemBINDINFO struct
          cbSize DWORD ?
          szExtraInfo POINTER ?
          grfBindInfoF DWORD ?
          dwBindVerb DWORD ?
          szCustomVerb POINTER ?
          cbstgmedData DWORD ?
          dwOptions DWORD ?
          dwOptionsFlags DWORD ?
          dwCodePage DWORD ?
          securityAttributes REMSECURITY_ATTRIBUTES <>
          iid IID <>
          pUnk POINTER ?
          dwReserved DWORD ?
        RemBINDINFO ends
        _tagRemBINDINFO typedef RemBINDINFO
        RemFORMATETC struct
          cfFormat DWORD ?
          ptd DWORD ?
          dwAspect DWORD ?
          lindex SDWORD ?
          tymed DWORD ?
        RemFORMATETC ends
        tagRemFORMATETC typedef RemFORMATETC
        LPREMFORMATETC typedef ptr tagRemFORMATETC
        ;* [public] *
        BINDINFO_OPTIONS typedef SDWORD
        BINDINFO_OPTIONS_WININETFLAG equ 10000h
        BINDINFO_OPTIONS_ENABLE_UTF8 equ 20000h
        BINDINFO_OPTIONS_DISABLE_UTF8 equ 40000h
        BINDINFO_OPTIONS_USE_IE_ENCODING equ 80000h
        BINDINFO_OPTIONS_BINDTOOBJECT equ 100000h
        BINDINFO_OPTIONS_SECURITYOPTOUT equ 200000h
        BINDINFO_OPTIONS_IGNOREMIMETEXTPLAIN equ 400000h
        BINDINFO_OPTIONS_USEBINDSTRINGCREDS equ 800000h
        BINDINFO_OPTIONS_IGNOREHTTPHTTPSREDIRECTS equ 1000000h
        BINDINFO_OPTIONS_IGNORE_SSLERRORS_ONCE equ 2000000h
        BINDINFO_WPC_DOWNLOADBLOCKED equ 8000000h
        BINDINFO_WPC_LOGGING_ENABLED equ 10000000h
        BINDINFO_OPTIONS_ALLOWCONNECTDATA equ 20000000h
        BINDINFO_OPTIONS_DISABLEAUTOREDIRECTS equ 40000000h
        BINDINFO_OPTIONS_SHDOCVW_NAVIGATE equ 80000000h
        __MIDL_IBindStatusCallback_0005 typedef BINDINFO_OPTIONS

        ;* [public] *
        BSCF typedef SDWORD
        BSCF_FIRSTDATANOTIFICATION equ 1h
        BSCF_INTERMEDIATEDATANOTIFICATION equ 2h
        BSCF_LASTDATANOTIFICATION equ 4h
        BSCF_DATAFULLYAVAILABLE equ 8h
        BSCF_AVAILABLEDATASIZEUNKNOWN equ 10h
        BSCF_SKIPDRAINDATAFORFILEURLS equ 20h
        BSCF_64BITLENGTHDOWNLOAD equ 40h
        __MIDL_IBindStatusCallback_0006 typedef BSCF

        BINDSTATUS typedef SDWORD
        BINDSTATUS_FINDINGRESOURCE equ 1
        BINDSTATUS_CONNECTING equ
        BINDSTATUS_REDIRECTING equ
        BINDSTATUS_BEGINDOWNLOADDATA equ
        BINDSTATUS_DOWNLOADINGDATA equ
        BINDSTATUS_ENDDOWNLOADDATA equ
        BINDSTATUS_BEGINDOWNLOADCOMPONENTS equ
        BINDSTATUS_INSTALLINGCOMPONENTS equ
        BINDSTATUS_ENDDOWNLOADCOMPONENTS equ
        BINDSTATUS_USINGCACHEDCOPY equ
        BINDSTATUS_SENDINGREQUEST equ
        BINDSTATUS_CLASSIDAVAILABLE equ
        BINDSTATUS_MIMETYPEAVAILABLE equ
        BINDSTATUS_CACHEFILENAMEAVAILABLE equ
        BINDSTATUS_BEGINSYNCOPERATION equ
        BINDSTATUS_ENDSYNCOPERATION equ
        BINDSTATUS_BEGINUPLOADDATA equ
        BINDSTATUS_UPLOADINGDATA equ
        BINDSTATUS_ENDUPLOADDATA equ
        BINDSTATUS_PROTOCOLCLASSID equ
        BINDSTATUS_ENCODING equ
        BINDSTATUS_VERIFIEDMIMETYPEAVAILABLE equ
        BINDSTATUS_CLASSINSTALLLOCATION equ
        BINDSTATUS_DECODING equ
        BINDSTATUS_LOADINGMIMEHANDLER equ
        BINDSTATUS_CONTENTDISPOSITIONATTACH equ
        BINDSTATUS_FILTERREPORTMIMETYPE equ
        BINDSTATUS_CLSIDCANINSTANTIATE equ
        BINDSTATUS_IUNKNOWNAVAILABLE equ
        BINDSTATUS_DIRECTBIND equ
        BINDSTATUS_RAWMIMETYPE equ
        BINDSTATUS_PROXYDETECTING equ
        BINDSTATUS_ACCEPTRANGES equ
        BINDSTATUS_COOKIE_SENT equ
        BINDSTATUS_COMPACT_POLICY_RECEIVED equ
        BINDSTATUS_COOKIE_SUPPRESSED equ
        BINDSTATUS_COOKIE_STATE_UNKNOWN equ
        BINDSTATUS_COOKIE_STATE_ACCEPT equ
        BINDSTATUS_COOKIE_STATE_REJECT equ
        BINDSTATUS_COOKIE_STATE_PROMPT equ
        BINDSTATUS_COOKIE_STATE_LEASH equ
        BINDSTATUS_COOKIE_STATE_DOWNGRADE equ
        BINDSTATUS_POLICY_HREF equ
        BINDSTATUS_P3P_HEADER equ
        BINDSTATUS_SESSION_COOKIE_RECEIVED equ
        BINDSTATUS_PERSISTENT_COOKIE_RECEIVED equ
        BINDSTATUS_SESSION_COOKIES_ALLOWED equ
        BINDSTATUS_CACHECONTROL equ
        BINDSTATUS_CONTENTDISPOSITIONFILENAME equ
        BINDSTATUS_MIMETEXTPLAINMISMATCH equ
        BINDSTATUS_PUBLISHERAVAILABLE equ
        BINDSTATUS_DISPLAYNAMEAVAILABLE equ
        BINDSTATUS_SSLUX_NAVBLOCKED equ
        BINDSTATUS_SERVER_MIMETYPEAVAILABLE equ
        BINDSTATUS_SNIFFED_CLASSIDAVAILABLE equ
        BINDSTATUS_64BIT_PROGRESS equ
        BINDSTATUS_LAST equ BINDSTATUS_64BIT_PROGRESS
        BINDSTATUS_RESERVED_0 equ
        BINDSTATUS_RESERVED_1 equ
        BINDSTATUS_RESERVED_2 equ
        BINDSTATUS_RESERVED_3 equ
        BINDSTATUS_RESERVED_4 equ
        BINDSTATUS_RESERVED_5 equ
        BINDSTATUS_RESERVED_6 equ
        BINDSTATUS_RESERVED_7 equ
        BINDSTATUS_RESERVED_8 equ
        BINDSTATUS_RESERVED_9 equ
        BINDSTATUS_RESERVED_A equ
        BINDSTATUS_RESERVED_B equ
        BINDSTATUS_RESERVED_C equ
        BINDSTATUS_RESERVED_D equ
        BINDSTATUS_RESERVED_E equ
        BINDSTATUS_RESERVED_F equ
        BINDSTATUS_RESERVED_10 equ
        BINDSTATUS_RESERVED_11 equ
        BINDSTATUS_RESERVED_12 equ
        BINDSTATUS_RESERVED_13 equ
        BINDSTATUS_RESERVED_14 equ
        BINDSTATUS_LAST_PRIVATE equ BINDSTATUS_RESERVED_14
        tagBINDSTATUS typedef BINDSTATUS

        externdef IID_IBindStatusCallback:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IBindStatusCallbackVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IBindStatusCallbackVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IBindStatusCallback, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IBindStatusCallback
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IBindStatusCallback
            DECLSPEC_XFGVIRT(IBindStatusCallback, OnStartBinding)
            ;* [in] *
            STD_METHOD OnStartBinding, :ptr IBindStatusCallback, :DWORD, :ptr IBinding
            ;* [in] *
            DECLSPEC_XFGVIRT(IBindStatusCallback, GetPriority)
            STD_METHOD GetPriority, :ptr IBindStatusCallback, :ptr LONG
            ;* [out] *
            DECLSPEC_XFGVIRT(IBindStatusCallback, OnLowResource)
            STD_METHOD OnLowResource, :ptr IBindStatusCallback, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IBindStatusCallback, OnProgress)
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD OnProgress, :ptr IBindStatusCallback, :ULONG, :ULONG, :ULONG, :LPCWSTR
            ;* [unique][in] *
            DECLSPEC_XFGVIRT(IBindStatusCallback, OnStopBinding)
            ;* [in] *
            STD_METHOD OnStopBinding, :ptr IBindStatusCallback, :HRESULT, :LPCWSTR
            ;* [unique][in] *
            DECLSPEC_XFGVIRT(IBindStatusCallback, GetBindInfo)
            ;* [local] *
            ;* [out] *
            STD_METHOD GetBindInfo, :ptr IBindStatusCallback, :ptr DWORD, :ptr BINDINFO
            ;* [unique][out][in] *
            DECLSPEC_XFGVIRT(IBindStatusCallback, OnDataAvailable)
            ;* [local] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD OnDataAvailable, :ptr IBindStatusCallback, :DWORD, :DWORD, :ptr FORMATETC, :ptr STGMEDIUM
            ;* [in] *
            DECLSPEC_XFGVIRT(IBindStatusCallback, OnObjectAvailable)
            ;* [in] *
            STD_METHOD OnObjectAvailable, :ptr IBindStatusCallback, :REFIID, :ptr IUnknown
            ;* [iid_is][in] *
            ??Interface equ <>
            END_INTERFACE
          IBindStatusCallbackVtbl ends
          IBindStatusCallback struct
            lpVtbl POINTER ?
          IBindStatusCallback ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* [call_as] *
        IBindStatusCallback_RemoteGetBindInfo_Proxy proto WIN_STD_CALL_CONV :ptr IBindStatusCallback, :ptr DWORD, :ptr RemBINDINFO, :ptr RemSTGMEDIUM
        ;* [unique][out][in] *
        IBindStatusCallback_RemoteGetBindInfo_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        ;* [call_as] *
        IBindStatusCallback_RemoteOnDataAvailable_Proxy proto WIN_STD_CALL_CONV :ptr IBindStatusCallback, :DWORD, :DWORD, :ptr RemFORMATETC, :ptr RemSTGMEDIUM
        ;* [in] *
        IBindStatusCallback_RemoteOnDataAvailable_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        ;* __IBindStatusCallback_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0005 *
      ;* [local] *
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef _LPBINDSTATUSCALLBACKEX_DEFINED
      _LPBINDSTATUSCALLBACKEX_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0005_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0005_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IBindStatusCallbackEx_INTERFACE_DEFINED__
        __IBindStatusCallbackEx_INTERFACE_DEFINED__ equ <>
        ;* interface IBindStatusCallbackEx *
        ;* [unique][uuid][object] *
        ;* [unique] *
        LPBINDSTATUSCALLBACKEX typedef ptr IBindStatusCallbackEx
        ;* [public] *
        BINDF2 typedef SDWORD
        BINDF2_DISABLEBASICOVERHTTP equ 1h
        BINDF2_DISABLEAUTOCOOKIEHANDLING equ 2h
        BINDF2_READ_DATA_GREATER_THAN_4GB equ 4h
        BINDF2_DISABLE_HTTP_REDIRECT_XSECURITYID equ 8h
        BINDF2_SETDOWNLOADMODE equ 20h
        BINDF2_DISABLE_HTTP_REDIRECT_CACHING equ 40h
        BINDF2_KEEP_CALLBACK_MODULE_LOADED equ 80h
        BINDF2_ALLOW_PROXY_CRED_PROMPT equ 100h
        BINDF2_RESERVED_17 equ 200h
        BINDF2_RESERVED_16 equ 400h
        BINDF2_RESERVED_15 equ 800h
        BINDF2_RESERVED_14 equ 1000h
        BINDF2_RESERVED_13 equ 2000h
        BINDF2_RESERVED_12 equ 4000h
        BINDF2_RESERVED_11 equ 8000h
        BINDF2_RESERVED_10 equ 10000h
        BINDF2_RESERVED_F equ 20000h
        BINDF2_RESERVED_E equ 40000h
        BINDF2_RESERVED_D equ 80000h
        BINDF2_RESERVED_C equ 100000h
        BINDF2_RESERVED_B equ 200000h
        BINDF2_RESERVED_A equ 400000h
        BINDF2_RESERVED_9 equ 800000h
        BINDF2_RESERVED_8 equ 1000000h
        BINDF2_RESERVED_7 equ 2000000h
        BINDF2_RESERVED_6 equ 4000000h
        BINDF2_RESERVED_5 equ 8000000h
        BINDF2_RESERVED_4 equ 10000000h
        BINDF2_RESERVED_3 equ 20000000h
        BINDF2_RESERVED_2 equ 40000000h
        BINDF2_RESERVED_1 equ 80000000h
        __MIDL_IBindStatusCallbackEx_0001 typedef BINDF2

        externdef IID_IBindStatusCallbackEx:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IBindStatusCallbackExVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IBindStatusCallbackExVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IBindStatusCallbackEx, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IBindStatusCallbackEx
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IBindStatusCallbackEx
            DECLSPEC_XFGVIRT(IBindStatusCallback, OnStartBinding)
            ;* [in] *
            STD_METHOD OnStartBinding, :ptr IBindStatusCallbackEx, :DWORD, :ptr IBinding
            ;* [in] *
            DECLSPEC_XFGVIRT(IBindStatusCallback, GetPriority)
            STD_METHOD GetPriority, :ptr IBindStatusCallbackEx, :ptr LONG
            ;* [out] *
            DECLSPEC_XFGVIRT(IBindStatusCallback, OnLowResource)
            STD_METHOD OnLowResource, :ptr IBindStatusCallbackEx, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IBindStatusCallback, OnProgress)
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD OnProgress, :ptr IBindStatusCallbackEx, :ULONG, :ULONG, :ULONG, :LPCWSTR
            ;* [unique][in] *
            DECLSPEC_XFGVIRT(IBindStatusCallback, OnStopBinding)
            ;* [in] *
            STD_METHOD OnStopBinding, :ptr IBindStatusCallbackEx, :HRESULT, :LPCWSTR
            ;* [unique][in] *
            DECLSPEC_XFGVIRT(IBindStatusCallback, GetBindInfo)
            ;* [local] *
            ;* [out] *
            STD_METHOD GetBindInfo, :ptr IBindStatusCallbackEx, :ptr DWORD, :ptr BINDINFO
            ;* [unique][out][in] *
            DECLSPEC_XFGVIRT(IBindStatusCallback, OnDataAvailable)
            ;* [local] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD OnDataAvailable, :ptr IBindStatusCallbackEx, :DWORD, :DWORD, :ptr FORMATETC, :ptr STGMEDIUM
            ;* [in] *
            DECLSPEC_XFGVIRT(IBindStatusCallback, OnObjectAvailable)
            ;* [in] *
            STD_METHOD OnObjectAvailable, :ptr IBindStatusCallbackEx, :REFIID, :ptr IUnknown
            ;* [iid_is][in] *
            DECLSPEC_XFGVIRT(IBindStatusCallbackEx, GetBindInfoEx)
            ;* [local] *
            ;* [out] *
            ;* [unique][out][in] *
            ;* [out] *
            STD_METHOD GetBindInfoEx, :ptr IBindStatusCallbackEx, :ptr DWORD, :ptr BINDINFO, :ptr DWORD, :ptr DWORD
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IBindStatusCallbackExVtbl ends
          IBindStatusCallbackEx struct
            lpVtbl POINTER ?
          IBindStatusCallbackEx ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* [call_as] *
        IBindStatusCallbackEx_RemoteGetBindInfoEx_Proxy proto WIN_STD_CALL_CONV :ptr IBindStatusCallbackEx, :ptr DWORD, :ptr RemBINDINFO, :ptr RemSTGMEDIUM, :ptr DWORD, :ptr DWORD
        ;* [out] *
        IBindStatusCallbackEx_RemoteGetBindInfoEx_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        ;* __IBindStatusCallbackEx_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0006 *
      ;* [local] *
    endif
    ifndef _LPAUTHENTICATION_DEFINED
      _LPAUTHENTICATION_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0006_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0006_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IAuthenticate_INTERFACE_DEFINED__
        __IAuthenticate_INTERFACE_DEFINED__ equ <>
        ;* interface IAuthenticate *
        ;* [unique][uuid][object] *
        ;* [unique] *
        LPAUTHENTICATION typedef ptr IAuthenticate
        externdef IID_IAuthenticate:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IAuthenticateVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IAuthenticateVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IAuthenticate, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IAuthenticate
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IAuthenticate
            DECLSPEC_XFGVIRT(IAuthenticate, Authenticate)
            ;* [out] *
            ;* [out] *
            STD_METHOD Authenticate, :ptr IAuthenticate, :ptr HWND, :ptr LPWSTR, :ptr LPWSTR
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IAuthenticateVtbl ends
          IAuthenticate struct
            lpVtbl POINTER ?
          IAuthenticate ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IAuthenticate_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0007 *
      ;* [local] *
    endif
    ifndef _LPAUTHENTICATIONEX_DEFINED
      _LPAUTHENTICATIONEX_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0007_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0007_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IAuthenticateEx_INTERFACE_DEFINED__
        __IAuthenticateEx_INTERFACE_DEFINED__ equ <>
        ;* interface IAuthenticateEx *
        ;* [unique][uuid][object] *
        ;* [unique] *
        LPAUTHENTICATIONEX typedef ptr IAuthenticateEx
        ;* [public] *
        AUTHENTICATEF typedef SDWORD
        AUTHENTICATEF_PROXY equ 1h
        AUTHENTICATEF_BASIC equ 2h
        AUTHENTICATEF_HTTP equ 4h
        __MIDL_IAuthenticateEx_0001 typedef AUTHENTICATEF

        AUTHENTICATEINFO struct
          dwFlags DWORD ?
          dwReserved DWORD ?
        AUTHENTICATEINFO ends
        _tagAUTHENTICATEINFO typedef AUTHENTICATEINFO
        externdef IID_IAuthenticateEx:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IAuthenticateExVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IAuthenticateExVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IAuthenticateEx, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IAuthenticateEx
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IAuthenticateEx
            DECLSPEC_XFGVIRT(IAuthenticate, Authenticate)
            ;* [out] *
            ;* [out] *
            STD_METHOD Authenticate, :ptr IAuthenticateEx, :ptr HWND, :ptr LPWSTR, :ptr LPWSTR
            ;* [out] *
            DECLSPEC_XFGVIRT(IAuthenticateEx, AuthenticateEx)
            ;* [out] *
            ;* [out] *
            ;* [out] *
            STD_METHOD AuthenticateEx, :ptr IAuthenticateEx, :ptr HWND, :ptr LPWSTR, :ptr LPWSTR, :ptr AUTHENTICATEINFO
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IAuthenticateExVtbl ends
          IAuthenticateEx struct
            lpVtbl POINTER ?
          IAuthenticateEx ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IAuthenticateEx_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0008 *
      ;* [local] *
    endif
    ifndef _LPHTTPNEGOTIATE_DEFINED
      _LPHTTPNEGOTIATE_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0008_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0008_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IHttpNegotiate_INTERFACE_DEFINED__
        __IHttpNegotiate_INTERFACE_DEFINED__ equ <>
        ;* interface IHttpNegotiate *
        ;* [unique][uuid][object] *
        ;* [unique] *
        LPHTTPNEGOTIATE typedef ptr IHttpNegotiate
        externdef IID_IHttpNegotiate:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IHttpNegotiateVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IHttpNegotiateVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IHttpNegotiate, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IHttpNegotiate
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IHttpNegotiate
            DECLSPEC_XFGVIRT(IHttpNegotiate, BeginningTransaction)
            ;* [in] *
            ;* [unique][in] *
            ;* [in] *
            STD_METHOD BeginningTransaction, :ptr IHttpNegotiate, :LPCWSTR, :LPCWSTR, :DWORD, :ptr LPWSTR
            ;* [out] *
            DECLSPEC_XFGVIRT(IHttpNegotiate, OnResponse)
            ;* [in] *
            ;* [unique][in] *
            ;* [unique][in] *
            STD_METHOD OnResponse, :ptr IHttpNegotiate, :DWORD, :LPCWSTR, :LPCWSTR, :ptr LPWSTR
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IHttpNegotiateVtbl ends
          IHttpNegotiate struct
            lpVtbl POINTER ?
          IHttpNegotiate ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IHttpNegotiate_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0009 *
      ;* [local] *
    endif
    ifndef _LPHTTPNEGOTIATE2_DEFINED
      _LPHTTPNEGOTIATE2_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0009_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0009_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IHttpNegotiate2_INTERFACE_DEFINED__
        __IHttpNegotiate2_INTERFACE_DEFINED__ equ <>
        ;* interface IHttpNegotiate2 *
        ;* [unique][uuid][object] *
        ;* [unique] *
        LPHTTPNEGOTIATE2 typedef ptr IHttpNegotiate2
        externdef IID_IHttpNegotiate2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IHttpNegotiate2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IHttpNegotiate2Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IHttpNegotiate2, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IHttpNegotiate2
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IHttpNegotiate2
            DECLSPEC_XFGVIRT(IHttpNegotiate, BeginningTransaction)
            ;* [in] *
            ;* [unique][in] *
            ;* [in] *
            STD_METHOD BeginningTransaction, :ptr IHttpNegotiate2, :LPCWSTR, :LPCWSTR, :DWORD, :ptr LPWSTR
            ;* [out] *
            DECLSPEC_XFGVIRT(IHttpNegotiate, OnResponse)
            ;* [in] *
            ;* [unique][in] *
            ;* [unique][in] *
            STD_METHOD OnResponse, :ptr IHttpNegotiate2, :DWORD, :LPCWSTR, :LPCWSTR, :ptr LPWSTR
            ;* [out] *
            DECLSPEC_XFGVIRT(IHttpNegotiate2, GetRootSecurityId)
            ;* [size_is][out] *
            ;* [out][in] *
            STD_METHOD GetRootSecurityId, :ptr IHttpNegotiate2, :ptr BYTE, :ptr DWORD, :DWORD_PTR
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IHttpNegotiate2Vtbl ends
          IHttpNegotiate2 struct
            lpVtbl POINTER ?
          IHttpNegotiate2 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IHttpNegotiate2_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0010 *
      ;* [local] *
    endif
    ifndef _LPHTTPNEGOTIATE3_DEFINED
      _LPHTTPNEGOTIATE3_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0010_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0010_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IHttpNegotiate3_INTERFACE_DEFINED__
        __IHttpNegotiate3_INTERFACE_DEFINED__ equ <>
        ;* interface IHttpNegotiate3 *
        ;* [unique][uuid][object] *
        ;* [unique] *
        LPHTTPNEGOTIATE3 typedef ptr IHttpNegotiate3
        externdef IID_IHttpNegotiate3:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IHttpNegotiate3Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IHttpNegotiate3Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IHttpNegotiate3, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IHttpNegotiate3
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IHttpNegotiate3
            DECLSPEC_XFGVIRT(IHttpNegotiate, BeginningTransaction)
            ;* [in] *
            ;* [unique][in] *
            ;* [in] *
            STD_METHOD BeginningTransaction, :ptr IHttpNegotiate3, :LPCWSTR, :LPCWSTR, :DWORD, :ptr LPWSTR
            ;* [out] *
            DECLSPEC_XFGVIRT(IHttpNegotiate, OnResponse)
            ;* [in] *
            ;* [unique][in] *
            ;* [unique][in] *
            STD_METHOD OnResponse, :ptr IHttpNegotiate3, :DWORD, :LPCWSTR, :LPCWSTR, :ptr LPWSTR
            ;* [out] *
            DECLSPEC_XFGVIRT(IHttpNegotiate2, GetRootSecurityId)
            ;* [size_is][out] *
            ;* [out][in] *
            STD_METHOD GetRootSecurityId, :ptr IHttpNegotiate3, :ptr BYTE, :ptr DWORD, :DWORD_PTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IHttpNegotiate3, GetSerializedClientCertContext)
            ;* [size_is][size_is][out] *
            STD_METHOD GetSerializedClientCertContext, :ptr IHttpNegotiate3, :ptr ptr BYTE, :ptr DWORD
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IHttpNegotiate3Vtbl ends
          IHttpNegotiate3 struct
            lpVtbl POINTER ?
          IHttpNegotiate3 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IHttpNegotiate3_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0011 *
      ;* [local] *
    endif
    ifndef _LPWININETFILESTREAM_DEFINED
      _LPWININETFILESTREAM_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0011_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0011_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IWinInetFileStream_INTERFACE_DEFINED__
        __IWinInetFileStream_INTERFACE_DEFINED__ equ <>
        ;* interface IWinInetFileStream *
        ;* [unique][uuid][object] *
        ;* [unique] *
        LPWININETFILESTREAM typedef ptr IWinInetFileStream
        externdef IID_IWinInetFileStream:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IWinInetFileStreamVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IWinInetFileStreamVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IWinInetFileStream, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IWinInetFileStream
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IWinInetFileStream
            DECLSPEC_XFGVIRT(IWinInetFileStream, SetHandleForUnlock)
            ;* [in] *
            STD_METHOD SetHandleForUnlock, :ptr IWinInetFileStream, :DWORD_PTR, :DWORD_PTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IWinInetFileStream, SetDeleteFile)
            STD_METHOD SetDeleteFile, :ptr IWinInetFileStream, :DWORD_PTR
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IWinInetFileStreamVtbl ends
          IWinInetFileStream struct
            lpVtbl POINTER ?
          IWinInetFileStream ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IWinInetFileStream_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0012 *
      ;* [local] *
    endif
    ifndef _LPWINDOWFORBINDINGUI_DEFINED
      _LPWINDOWFORBINDINGUI_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0012_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0012_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IWindowForBindingUI_INTERFACE_DEFINED__
        __IWindowForBindingUI_INTERFACE_DEFINED__ equ <>
        ;* interface IWindowForBindingUI *
        ;* [unique][uuid][object][local] *
        ;* [unique] *
        LPWINDOWFORBINDINGUI typedef ptr IWindowForBindingUI
        externdef IID_IWindowForBindingUI:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IWindowForBindingUIVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IWindowForBindingUIVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IWindowForBindingUI, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IWindowForBindingUI
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IWindowForBindingUI
            DECLSPEC_XFGVIRT(IWindowForBindingUI, GetWindow)
            ;* [in] *
            STD_METHOD GetWindow, :ptr IWindowForBindingUI, :REFGUID, :ptr HWND
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IWindowForBindingUIVtbl ends
          IWindowForBindingUI struct
            lpVtbl POINTER ?
          IWindowForBindingUI ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IWindowForBindingUI_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0013 *
      ;* [local] *
    endif
    ifndef _LPCODEINSTALL_DEFINED
      _LPCODEINSTALL_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0013_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0013_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ICodeInstall_INTERFACE_DEFINED__
        __ICodeInstall_INTERFACE_DEFINED__ equ <>
        ;* interface ICodeInstall *
        ;* [unique][uuid][object][local] *
        ;* [unique] *
        LPCODEINSTALL typedef ptr ICodeInstall
        ;* [public] *
        CIP_STATUS typedef SDWORD
        CIP_DISK_FULL equ 0
        CIP_ACCESS_DENIED equ
        CIP_NEWER_VERSION_EXISTS equ
        CIP_OLDER_VERSION_EXISTS equ
        CIP_NAME_CONFLICT equ
        CIP_TRUST_VERIFICATION_COMPONENT_MISSING equ
        CIP_EXE_SELF_REGISTERATION_TIMEOUT equ
        CIP_UNSAFE_TO_ABORT equ
        CIP_NEED_REBOOT equ
        CIP_NEED_REBOOT_UI_PERMISSION equ
        __MIDL_ICodeInstall_0001 typedef CIP_STATUS

        externdef IID_ICodeInstall:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ICodeInstallVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ICodeInstallVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ICodeInstall, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ICodeInstall
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ICodeInstall
            DECLSPEC_XFGVIRT(IWindowForBindingUI, GetWindow)
            ;* [in] *
            STD_METHOD GetWindow, :ptr ICodeInstall, :REFGUID, :ptr HWND
            ;* [out] *
            DECLSPEC_XFGVIRT(ICodeInstall, OnCodeInstallProblem)
            ;* [in] *
            ;* [unique][in] *
            ;* [unique][in] *
            STD_METHOD OnCodeInstallProblem, :ptr ICodeInstall, :ULONG, :LPCWSTR, :LPCWSTR, :DWORD
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          ICodeInstallVtbl ends
          ICodeInstall struct
            lpVtbl POINTER ?
          ICodeInstall ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ICodeInstall_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0014 *
      ;* [local] *
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  if (_WIN32_IE ge _WIN32_IE_IE70)
    ifndef _LPUri_DEFINED
      _LPUri_DEFINED equ <>
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        externdef __MIDL_itf_urlmon_0000_0014_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0014_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IUri_INTERFACE_DEFINED__
          __IUri_INTERFACE_DEFINED__ equ <>
          ;* interface IUri *
          ;* [unique][uuid][object] *
          ;* [public][public][public][public][public][helpstring] *
          Uri_PROPERTY typedef SDWORD
          Uri_PROPERTY_ABSOLUTE_URI equ 0
          Uri_PROPERTY_STRING_START equ Uri_PROPERTY_ABSOLUTE_URI
          Uri_PROPERTY_AUTHORITY equ 1
          Uri_PROPERTY_DISPLAY_URI equ 2
          Uri_PROPERTY_DOMAIN equ 3
          Uri_PROPERTY_EXTENSION equ 4
          Uri_PROPERTY_FRAGMENT equ 5
          Uri_PROPERTY_HOST equ 6
          Uri_PROPERTY_PASSWORD equ 7
          Uri_PROPERTY_PATH equ 8
          Uri_PROPERTY_PATH_AND_QUERY equ 9
          Uri_PROPERTY_QUERY equ 10
          Uri_PROPERTY_RAW_URI equ 11
          Uri_PROPERTY_SCHEME_NAME equ 12
          Uri_PROPERTY_USER_INFO equ 13
          Uri_PROPERTY_USER_NAME equ 14
          Uri_PROPERTY_STRING_LAST equ Uri_PROPERTY_USER_NAME
          Uri_PROPERTY_HOST_TYPE equ 15
          Uri_PROPERTY_DWORD_START equ Uri_PROPERTY_HOST_TYPE
          Uri_PROPERTY_PORT equ 16
          Uri_PROPERTY_SCHEME equ 17
          Uri_PROPERTY_ZONE equ 18
          Uri_PROPERTY_DWORD_LAST equ Uri_PROPERTY_ZONE
          __MIDL_IUri_0001 typedef Uri_PROPERTY

          ;* [public][helpstring] *
          Uri_HOST_TYPE typedef SDWORD
          Uri_HOST_UNKNOWN equ 0
          Uri_HOST_DNS equ
          Uri_HOST_IPV4 equ
          Uri_HOST_IPV6 equ
          Uri_HOST_IDN equ
          __MIDL_IUri_0002 typedef Uri_HOST_TYPE

          externdef IID_IUri:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IUriVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IUriVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              ;* [in] *
              ;* [annotation][iid_is][out] *
              STD_METHOD QueryInterface, :ptr IUri, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IUri
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IUri
              DECLSPEC_XFGVIRT(IUri, GetPropertyBSTR)
              ;* [helpstring] *
              ;* [range][in] *
              ;* [out] *
              STD_METHOD GetPropertyBSTR, :ptr IUri, :Uri_PROPERTY, :ptr BSTR, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IUri, GetPropertyLength)
              ;* [helpstring] *
              ;* [range][in] *
              ;* [out] *
              STD_METHOD GetPropertyLength, :ptr IUri, :Uri_PROPERTY, :ptr DWORD, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IUri, GetPropertyDWORD)
              ;* [helpstring] *
              ;* [range][in] *
              ;* [out] *
              STD_METHOD GetPropertyDWORD, :ptr IUri, :Uri_PROPERTY, :ptr DWORD, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IUri, HasProperty)
              ;* [helpstring] *
              ;* [range][in] *
              STD_METHOD HasProperty, :ptr IUri, :Uri_PROPERTY, :ptr BOOL
              ;* [out] *
              DECLSPEC_XFGVIRT(IUri, GetAbsoluteUri)
              ;* [helpstring] *
              STD_METHOD GetAbsoluteUri, :ptr IUri, :ptr BSTR
              ;* [out] *
              DECLSPEC_XFGVIRT(IUri, GetAuthority)
              ;* [helpstring] *
              STD_METHOD GetAuthority, :ptr IUri, :ptr BSTR
              ;* [out] *
              DECLSPEC_XFGVIRT(IUri, GetDisplayUri)
              ;* [helpstring] *
              STD_METHOD GetDisplayUri, :ptr IUri, :ptr BSTR
              ;* [out] *
              DECLSPEC_XFGVIRT(IUri, GetDomain)
              ;* [helpstring] *
              STD_METHOD GetDomain, :ptr IUri, :ptr BSTR
              ;* [out] *
              DECLSPEC_XFGVIRT(IUri, GetExtension)
              ;* [helpstring] *
              STD_METHOD GetExtension, :ptr IUri, :ptr BSTR
              ;* [out] *
              DECLSPEC_XFGVIRT(IUri, GetFragment)
              ;* [helpstring] *
              STD_METHOD GetFragment, :ptr IUri, :ptr BSTR
              ;* [out] *
              DECLSPEC_XFGVIRT(IUri, GetHost)
              ;* [helpstring] *
              STD_METHOD GetHost, :ptr IUri, :ptr BSTR
              ;* [out] *
              DECLSPEC_XFGVIRT(IUri, GetPassword)
              ;* [helpstring] *
              STD_METHOD GetPassword, :ptr IUri, :ptr BSTR
              ;* [out] *
              DECLSPEC_XFGVIRT(IUri, GetPath)
              ;* [helpstring] *
              STD_METHOD GetPath, :ptr IUri, :ptr BSTR
              ;* [out] *
              DECLSPEC_XFGVIRT(IUri, GetPathAndQuery)
              ;* [helpstring] *
              STD_METHOD GetPathAndQuery, :ptr IUri, :ptr BSTR
              ;* [out] *
              DECLSPEC_XFGVIRT(IUri, GetQuery)
              ;* [helpstring] *
              STD_METHOD GetQuery, :ptr IUri, :ptr BSTR
              ;* [out] *
              DECLSPEC_XFGVIRT(IUri, GetRawUri)
              ;* [helpstring] *
              STD_METHOD GetRawUri, :ptr IUri, :ptr BSTR
              ;* [out] *
              DECLSPEC_XFGVIRT(IUri, GetSchemeName)
              ;* [helpstring] *
              STD_METHOD GetSchemeName, :ptr IUri, :ptr BSTR
              ;* [out] *
              DECLSPEC_XFGVIRT(IUri, GetUserInfo)
              ;* [helpstring] *
              STD_METHOD GetUserInfo, :ptr IUri, :ptr BSTR
              ;* [out] *
              DECLSPEC_XFGVIRT(IUri, GetUserName)
              ;* [helpstring] *
              STD_METHOD GetUserName, :ptr IUri, :ptr BSTR
              ;* [out] *
              DECLSPEC_XFGVIRT(IUri, GetHostType)
              ;* [helpstring] *
              STD_METHOD GetHostType, :ptr IUri, :ptr DWORD
              ;* [out] *
              DECLSPEC_XFGVIRT(IUri, GetPort)
              ;* [helpstring] *
              STD_METHOD GetPort, :ptr IUri, :ptr DWORD
              ;* [out] *
              DECLSPEC_XFGVIRT(IUri, GetScheme)
              ;* [helpstring] *
              STD_METHOD GetScheme, :ptr IUri, :ptr DWORD
              ;* [out] *
              DECLSPEC_XFGVIRT(IUri, GetZone)
              ;* [helpstring] *
              STD_METHOD GetZone, :ptr IUri, :ptr DWORD
              ;* [out] *
              DECLSPEC_XFGVIRT(IUri, GetProperties)
              ;* [helpstring] *
              STD_METHOD GetProperties, :ptr IUri, :LPDWORD
              ;* [out] *
              DECLSPEC_XFGVIRT(IUri, IsEqual)
              ;* [helpstring] *
              ;* [in] *
              STD_METHOD IsEqual, :ptr IUri, :ptr IUri, :ptr BOOL
              ;* [out] *
              ??Interface equ <>
              END_INTERFACE
            IUriVtbl ends
            IUri struct
              lpVtbl POINTER ?
            IUri ends
            ifdef COBJMACROS
              ;[...]
            endif
            ;* C style interface *
          endif
          ;* __IUri_INTERFACE_DEFINED__ *
        endif
        ;* interface __MIDL_itf_urlmon_0000_0015 *
        ;* [local] *
        @DefProto DllImport, CreateUri, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :DWORD_PTR, :ptr ptr IUri>, 16
        ; must be 0
        @DefProto DllImport, CreateUriWithFragment, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :DWORD, :DWORD_PTR, :ptr ptr IUri>, 20
        ; must be 0
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, CreateUriFromMultiByteString, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :DWORD, :DWORD, :DWORD_PTR, :ptr ptr IUri>, 24
        ; must be 0
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        ;The following flags are used with IUri::GetProperties.
        Uri_HAS_ABSOLUTE_URI equ (1 shl Uri_PROPERTY_ABSOLUTE_URI)
        Uri_HAS_AUTHORITY equ (1 shl Uri_PROPERTY_AUTHORITY)
        Uri_HAS_DISPLAY_URI equ (1 shl Uri_PROPERTY_DISPLAY_URI)
        Uri_HAS_DOMAIN equ (1 shl Uri_PROPERTY_DOMAIN)
        Uri_HAS_EXTENSION equ (1 shl Uri_PROPERTY_EXTENSION)
        Uri_HAS_FRAGMENT equ (1 shl Uri_PROPERTY_FRAGMENT)
        Uri_HAS_HOST equ (1 shl Uri_PROPERTY_HOST)
        Uri_HAS_PASSWORD equ (1 shl Uri_PROPERTY_PASSWORD)
        Uri_HAS_PATH equ (1 shl Uri_PROPERTY_PATH)
        Uri_HAS_QUERY equ (1 shl Uri_PROPERTY_QUERY)
        Uri_HAS_RAW_URI equ (1 shl Uri_PROPERTY_RAW_URI)
        Uri_HAS_SCHEME_NAME equ (1 shl Uri_PROPERTY_SCHEME_NAME)
        Uri_HAS_USER_NAME equ (1 shl Uri_PROPERTY_USER_NAME)
        Uri_HAS_PATH_AND_QUERY equ (1 shl Uri_PROPERTY_PATH_AND_QUERY)
        Uri_HAS_USER_INFO equ (1 shl Uri_PROPERTY_USER_INFO)
        Uri_HAS_HOST_TYPE equ (1 shl Uri_PROPERTY_HOST_TYPE)
        Uri_HAS_PORT equ (1 shl Uri_PROPERTY_PORT)
        Uri_HAS_SCHEME equ (1 shl Uri_PROPERTY_SCHEME)
        Uri_HAS_ZONE equ (1 shl Uri_PROPERTY_ZONE)
        ;The following public Uri_CREATE flags may be passed in 
        ;through the dwFlags parameter of the CreateUri functions.
        ;Note that ALLOW_RELATIVE and ALLOW_IMPLICIT_WILDCARD_SCHEME are mutually exclusive and may not be passed together.
        Uri_CREATE_ALLOW_RELATIVE equ 00000001h; When the scheme is unspecified and not implicit file, assume relative.

        Uri_CREATE_ALLOW_IMPLICIT_WILDCARD_SCHEME equ 00000002h; When the scheme is unspecified and not implicit file, assume wildcard.

        Uri_CREATE_ALLOW_IMPLICIT_FILE_SCHEME equ 00000004h; When the scheme is unspecified and it starts with X: or \\ assume its a file scheme.

        Uri_CREATE_NOFRAG equ 00000008h; If there's a query string don't look for a fragment

        Uri_CREATE_NO_CANONICALIZE equ 00000010h; Do not canonicalize the scheme, host, authority, or path

        Uri_CREATE_CANONICALIZE equ 00000100h; DEFAULT: Canonicalize the scheme, host, authority, and path

        Uri_CREATE_FILE_USE_DOS_PATH equ 00000020h; Use DOS path compat mode for file URI creation

        Uri_CREATE_DECODE_EXTRA_INFO equ 00000040h; Beta2 DEFAULT: Decode the contents of query and fragment, then re-encode reserved characters

        Uri_CREATE_NO_DECODE_EXTRA_INFO equ 00000080h; Beta1 DEFAULT: Neither decode nor re-encode any part of the query or fragment

        Uri_CREATE_CRACK_UNKNOWN_SCHEMES equ 00000200h; Beta2 DEFAULT: Heirarchical URIs with present and unknown schemes will be treated like heirarchical URIs

        Uri_CREATE_NO_CRACK_UNKNOWN_SCHEMES equ 00000400h; Beta1 DEFAULT: Heirarchical URIs with present and unknown schemes will be treated like opaque URIs

        Uri_CREATE_PRE_PROCESS_HTML_URI equ 00000800h; DEFAULT:  Perform pre-processing on the URI to remove control characters and whitespace as if the URI comes from the raw href value of an HTML page.

        Uri_CREATE_NO_PRE_PROCESS_HTML_URI equ 00001000h; Don't perform pre-processing to remove control characters and whitespace as appropriate.

        Uri_CREATE_IE_SETTINGS equ 00002000h; Use IE registry settings for such things as whether or not to use IDN.

        Uri_CREATE_NO_IE_SETTINGS equ 00004000h; DEFAULT: Don't use IE registry settings.

        Uri_CREATE_NO_ENCODE_FORBIDDEN_CHARACTERS equ 00008000h; Don't percent-encode characters that are forbidden by the RFC.

        Uri_CREATE_NORMALIZE_INTL_CHARACTERS equ 00010000h; Percent encode all extended unicode charcters, then decode all percent encoded extended unicode characters (except those identified as dangerous)

        Uri_CREATE_CANONICALIZE_ABSOLUTE equ 00020000h; Generate a fully UTF-8 encoded value for absoluteUri

        ;The following flags may be passed in through the dwFlags 
        ;parameter of the IUri::GetPropertyBSTR or IUri::GetPropertyLength functions.
        ;The following flags apply only to the property Uri_PROPERTY_DISPLAY_URI:
        Uri_DISPLAY_NO_FRAGMENT equ 00000001h; Exclude fragment from the DisplayUri, if one exists

        Uri_PUNYCODE_IDN_HOST equ 00000002h; Show the hostname encoded as punycode inside the Host, Domain, or AbsoluteUri properties, if the Uri is IDN

        Uri_DISPLAY_IDN_HOST equ 00000004h; Show the hostname encoded as punycode or Unicode as it would appear in the DisplayUri property. This applies to the Host, Domain, and AbsoluteUri properties.

        Uri_DISPLAY_NO_PUNYCODE equ 00000008h; Show the hostname encoded as Unicode from the DisplayUri, if the Uri is IDN

        ; The following are Uri_ENCODING_ flags for use with the function CreateUriFromMultiByteString
        Uri_ENCODING_USER_INFO_AND_PATH_IS_PERCENT_ENCODED_UTF8 equ 00000001h
        Uri_ENCODING_USER_INFO_AND_PATH_IS_CP equ 00000002h
        Uri_ENCODING_HOST_IS_IDN equ 00000004h
        Uri_ENCODING_HOST_IS_PERCENT_ENCODED_UTF8 equ 00000008h
        Uri_ENCODING_HOST_IS_PERCENT_ENCODED_CP equ 00000010h
        Uri_ENCODING_QUERY_AND_FRAGMENT_IS_PERCENT_ENCODED_UTF8 equ 00000020h
        Uri_ENCODING_QUERY_AND_FRAGMENT_IS_CP equ 00000040h
        Uri_ENCODING_RFC equ <(Uri_ENCODING_USER_INFO_AND_PATH_IS_PERCENT_ENCODED_UTF8 or Uri_ENCODING_HOST_IS_PERCENT_ENCODED_UTF8 or Uri_ENCODING_QUERY_AND_FRAGMENT_IS_PERCENT_ENCODED_UTF8)>
        ;The following flags may be passed in through the dwUriBuilderFlags 
        ;parameter of the IUriBuilder::CreateUri
        UriBuilder_USE_ORIGINAL_FLAGS equ 00000001h; Use the create flags from the underlying IUri if they are available.

        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      externdef __MIDL_itf_urlmon_0000_0015_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0015_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IUriContainer_INTERFACE_DEFINED__
        __IUriContainer_INTERFACE_DEFINED__ equ <>
        ;* interface IUriContainer *
        ;* [unique][uuid][local][object] *
        externdef IID_IUriContainer:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IUriContainerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IUriContainerVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IUriContainer, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IUriContainer
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IUriContainer
            DECLSPEC_XFGVIRT(IUriContainer, GetIUri)
            ;* [helpstring] *
            STD_METHOD GetIUri, :ptr IUriContainer, :ptr ptr IUri
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IUriContainerVtbl ends
          IUriContainer struct
            lpVtbl POINTER ?
          IUriContainer ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IUriContainer_INTERFACE_DEFINED__ *
      endif
      ifndef __IUriBuilder_INTERFACE_DEFINED__
        __IUriBuilder_INTERFACE_DEFINED__ equ <>
        ;* interface IUriBuilder *
        ;* [unique][uuid][object][local][helpstring] *
        externdef IID_IUriBuilder:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IUriBuilderVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IUriBuilderVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IUriBuilder, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IUriBuilder
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IUriBuilder
            DECLSPEC_XFGVIRT(IUriBuilder, CreateUriSimple)
            ;* [helpstring] *
            ;* [in] *
            ;* [in] *
            ;* [annotation][out] *
            STD_METHOD CreateUriSimple, :ptr IUriBuilder, :DWORD, :DWORD_PTR, :ptr ptr IUri
            DECLSPEC_XFGVIRT(IUriBuilder, CreateUri)
            ;* [helpstring] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            ;* [annotation][out] *
            STD_METHOD CreateUri, :ptr IUriBuilder, :DWORD, :DWORD, :DWORD_PTR, :ptr ptr IUri
            DECLSPEC_XFGVIRT(IUriBuilder, CreateUriWithFlags)
            ;* [helpstring] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            ;* [annotation][out] *
            STD_METHOD CreateUriWithFlags, :ptr IUriBuilder, :DWORD, :DWORD, :DWORD, :DWORD_PTR, :ptr ptr IUri
            DECLSPEC_XFGVIRT(IUriBuilder, GetIUri)
            ;* [helpstring] *
            ;* [annotation][out] *
            STD_METHOD GetIUri, :ptr IUriBuilder, :ptr ptr IUri
            DECLSPEC_XFGVIRT(IUriBuilder, SetIUri)
            ;* [helpstring] *
            ;* [annotation][unique][in] *
            STD_METHOD SetIUri, :ptr IUriBuilder, :ptr IUri
            DECLSPEC_XFGVIRT(IUriBuilder, GetFragment)
            ;* [helpstring] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD GetFragment, :ptr IUriBuilder, :ptr DWORD, :ptr LPCWSTR
            DECLSPEC_XFGVIRT(IUriBuilder, GetHost)
            ;* [helpstring] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD GetHost, :ptr IUriBuilder, :ptr DWORD, :ptr LPCWSTR
            DECLSPEC_XFGVIRT(IUriBuilder, GetPassword)
            ;* [helpstring] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD GetPassword, :ptr IUriBuilder, :ptr DWORD, :ptr LPCWSTR
            DECLSPEC_XFGVIRT(IUriBuilder, GetPath)
            ;* [helpstring] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD GetPath, :ptr IUriBuilder, :ptr DWORD, :ptr LPCWSTR
            DECLSPEC_XFGVIRT(IUriBuilder, GetPort)
            ;* [helpstring] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD GetPort, :ptr IUriBuilder, :ptr BOOL, :ptr DWORD
            DECLSPEC_XFGVIRT(IUriBuilder, GetQuery)
            ;* [helpstring] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD GetQuery, :ptr IUriBuilder, :ptr DWORD, :ptr LPCWSTR
            DECLSPEC_XFGVIRT(IUriBuilder, GetSchemeName)
            ;* [helpstring] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD GetSchemeName, :ptr IUriBuilder, :ptr DWORD, :ptr LPCWSTR
            DECLSPEC_XFGVIRT(IUriBuilder, GetUserName)
            ;* [helpstring] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD GetUserName, :ptr IUriBuilder, :ptr DWORD, :ptr LPCWSTR
            DECLSPEC_XFGVIRT(IUriBuilder, SetFragment)
            ;* [helpstring] *
            ;* [annotation][in] *
            STD_METHOD SetFragment, :ptr IUriBuilder, :LPCWSTR
            DECLSPEC_XFGVIRT(IUriBuilder, SetHost)
            ;* [helpstring] *
            ;* [annotation][in] *
            STD_METHOD SetHost, :ptr IUriBuilder, :LPCWSTR
            DECLSPEC_XFGVIRT(IUriBuilder, SetPassword)
            ;* [helpstring] *
            ;* [annotation][in] *
            STD_METHOD SetPassword, :ptr IUriBuilder, :LPCWSTR
            DECLSPEC_XFGVIRT(IUriBuilder, SetPath)
            ;* [helpstring] *
            ;* [annotation][in] *
            STD_METHOD SetPath, :ptr IUriBuilder, :LPCWSTR
            DECLSPEC_XFGVIRT(IUriBuilder, SetPort)
            ;* [helpstring] *
            ;* [in] *
            STD_METHOD SetPort, :ptr IUriBuilder, :BOOL, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IUriBuilder, SetQuery)
            ;* [helpstring] *
            ;* [annotation][in] *
            STD_METHOD SetQuery, :ptr IUriBuilder, :LPCWSTR
            DECLSPEC_XFGVIRT(IUriBuilder, SetSchemeName)
            ;* [helpstring] *
            ;* [annotation][in] *
            STD_METHOD SetSchemeName, :ptr IUriBuilder, :LPCWSTR
            DECLSPEC_XFGVIRT(IUriBuilder, SetUserName)
            ;* [helpstring] *
            ;* [annotation][in] *
            STD_METHOD SetUserName, :ptr IUriBuilder, :LPCWSTR
            DECLSPEC_XFGVIRT(IUriBuilder, RemoveProperties)
            ;* [helpstring] *
            STD_METHOD RemoveProperties, :ptr IUriBuilder, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IUriBuilder, HasBeenModified)
            ;* [helpstring] *
            ;* [annotation][out] *
            STD_METHOD HasBeenModified, :ptr IUriBuilder, :ptr BOOL
            ??Interface equ <>
            END_INTERFACE
          IUriBuilderVtbl ends
          IUriBuilder struct
            lpVtbl POINTER ?
          IUriBuilder ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IUriBuilder_INTERFACE_DEFINED__ *
      endif
      ifndef __IUriBuilderFactory_INTERFACE_DEFINED__
        __IUriBuilderFactory_INTERFACE_DEFINED__ equ <>
        ;* interface IUriBuilderFactory *
        ;* [unique][uuid][object][local][helpstring] *
        externdef IID_IUriBuilderFactory:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IUriBuilderFactoryVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IUriBuilderFactoryVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IUriBuilderFactory, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IUriBuilderFactory
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IUriBuilderFactory
            DECLSPEC_XFGVIRT(IUriBuilderFactory, CreateIUriBuilder)
            ;* [helpstring] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out] *
            STD_METHOD CreateIUriBuilder, :ptr IUriBuilderFactory, :DWORD, :DWORD_PTR, :ptr ptr IUriBuilder
            DECLSPEC_XFGVIRT(IUriBuilderFactory, CreateInitializedIUriBuilder)
            ;* [helpstring] *
            ;* [annotation][in] *
            ;* [annotation][in] *
            ;* [annotation][out] *
            STD_METHOD CreateInitializedIUriBuilder, :ptr IUriBuilderFactory, :DWORD, :DWORD_PTR, :ptr ptr IUriBuilder
            ??Interface equ <>
            END_INTERFACE
          IUriBuilderFactoryVtbl ends
          IUriBuilderFactory struct
            lpVtbl POINTER ?
          IUriBuilderFactory ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IUriBuilderFactory_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0018 *
      ;* [local] *
      @DefProto DllImport, CreateIUriBuilder, WIN_STD_CALL_CONV,, <:ptr IUri, :DWORD, :DWORD_PTR, :ptr ptr IUriBuilder>, 16
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
  endif
  ;(_WIN32_IE >= _WIN32_IE_IE70)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef _LPWININETINFO_DEFINED
      _LPWININETINFO_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0018_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0018_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IWinInetInfo_INTERFACE_DEFINED__
        __IWinInetInfo_INTERFACE_DEFINED__ equ <>
        ;* interface IWinInetInfo *
        ;* [unique][uuid][object] *
        ;* [unique] *
        LPWININETINFO typedef ptr IWinInetInfo
        externdef IID_IWinInetInfo:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IWinInetInfoVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IWinInetInfoVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IWinInetInfo, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IWinInetInfo
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IWinInetInfo
            DECLSPEC_XFGVIRT(IWinInetInfo, QueryOption)
            ;* [local] *
            ;* [in] *
            ;* [size_is][out][in] *
            STD_METHOD QueryOption, :ptr IWinInetInfo, :DWORD, :LPVOID, :ptr DWORD
            ;* [out][in] *
            ??Interface equ <>
            END_INTERFACE
          IWinInetInfoVtbl ends
          IWinInetInfo struct
            lpVtbl POINTER ?
          IWinInetInfo ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* [call_as] *
        IWinInetInfo_RemoteQueryOption_Proxy proto WIN_STD_CALL_CONV :ptr IWinInetInfo, :DWORD, :ptr BYTE, :ptr DWORD
        ;* [out][in] *
        IWinInetInfo_RemoteQueryOption_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        ;* __IWinInetInfo_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0019 *
      ;* [local] *
    endif
    WININETINFO_OPTION_LOCK_HANDLE equ 65534
    ifndef _LPHTTPSECURITY_DEFINED
      _LPHTTPSECURITY_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0019_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0019_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IHttpSecurity_INTERFACE_DEFINED__
        __IHttpSecurity_INTERFACE_DEFINED__ equ <>
        ;* interface IHttpSecurity *
        ;* [unique][uuid][object][local] *
        ;* [unique] *
        LPHTTPSECURITY typedef ptr IHttpSecurity
        externdef IID_IHttpSecurity:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IHttpSecurityVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IHttpSecurityVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IHttpSecurity, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IHttpSecurity
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IHttpSecurity
            DECLSPEC_XFGVIRT(IWindowForBindingUI, GetWindow)
            ;* [in] *
            STD_METHOD GetWindow, :ptr IHttpSecurity, :REFGUID, :ptr HWND
            ;* [out] *
            DECLSPEC_XFGVIRT(IHttpSecurity, OnSecurityProblem)
            STD_METHOD OnSecurityProblem, :ptr IHttpSecurity, :DWORD
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IHttpSecurityVtbl ends
          IHttpSecurity struct
            lpVtbl POINTER ?
          IHttpSecurity ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IHttpSecurity_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0020 *
      ;* [local] *
    endif
    ifndef _LPWININETHTTPINFO_DEFINED
      _LPWININETHTTPINFO_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0020_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0020_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IWinInetHttpInfo_INTERFACE_DEFINED__
        __IWinInetHttpInfo_INTERFACE_DEFINED__ equ <>
        ;* interface IWinInetHttpInfo *
        ;* [unique][uuid][object] *
        ;* [unique] *
        LPWININETHTTPINFO typedef ptr IWinInetHttpInfo
        externdef IID_IWinInetHttpInfo:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IWinInetHttpInfoVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IWinInetHttpInfoVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IWinInetHttpInfo, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IWinInetHttpInfo
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IWinInetHttpInfo
            DECLSPEC_XFGVIRT(IWinInetInfo, QueryOption)
            ;* [local] *
            ;* [in] *
            ;* [size_is][out][in] *
            STD_METHOD QueryOption, :ptr IWinInetHttpInfo, :DWORD, :LPVOID, :ptr DWORD
            ;* [out][in] *
            DECLSPEC_XFGVIRT(IWinInetHttpInfo, QueryInfo)
            ;* [local] *
            ;* [in] *
            ;* [size_is][out][in] *
            ;* [out][in] *
            ;* [out][in] *
            STD_METHOD QueryInfo, :ptr IWinInetHttpInfo, :DWORD, :LPVOID, :ptr DWORD, :ptr DWORD, :ptr DWORD
            ;* [out][in] *
            ??Interface equ <>
            END_INTERFACE
          IWinInetHttpInfoVtbl ends
          IWinInetHttpInfo struct
            lpVtbl POINTER ?
          IWinInetHttpInfo ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* [call_as] *
        IWinInetHttpInfo_RemoteQueryInfo_Proxy proto WIN_STD_CALL_CONV :ptr IWinInetHttpInfo, :DWORD, :ptr BYTE, :ptr DWORD, :ptr DWORD, :ptr DWORD
        ;* [out][in] *
        IWinInetHttpInfo_RemoteQueryInfo_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        ;* __IWinInetHttpInfo_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0021 *
      ;* [local] *
    endif
    ifndef _LPWININETHTTPTIMEOUTS_DEFINED
      _LPWININETHTTPTIMEOUTS_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0021_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0021_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IWinInetHttpTimeouts_INTERFACE_DEFINED__
        __IWinInetHttpTimeouts_INTERFACE_DEFINED__ equ <>
        ;* interface IWinInetHttpTimeouts *
        ;* [unique][uuid][object][local] *
        externdef IID_IWinInetHttpTimeouts:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IWinInetHttpTimeoutsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IWinInetHttpTimeoutsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IWinInetHttpTimeouts, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IWinInetHttpTimeouts
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IWinInetHttpTimeouts
            DECLSPEC_XFGVIRT(IWinInetHttpTimeouts, GetRequestTimeouts)
            ;* [helpstring] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            ;* [annotation][out] *
            STD_METHOD GetRequestTimeouts, :ptr IWinInetHttpTimeouts, :ptr DWORD, :ptr DWORD, :ptr DWORD
            ??Interface equ <>
            END_INTERFACE
          IWinInetHttpTimeoutsVtbl ends
          IWinInetHttpTimeouts struct
            lpVtbl POINTER ?
          IWinInetHttpTimeouts ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IWinInetHttpTimeouts_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0022 *
      ;* [local] *
    endif
    if (_WIN32_IE ge _WIN32_IE_IE60SP2)
      ifndef _LPWININETCACHEHINTS_DEFINED
        _LPWININETCACHEHINTS_DEFINED equ <>
        externdef __MIDL_itf_urlmon_0000_0022_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0022_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IWinInetCacheHints_INTERFACE_DEFINED__
          __IWinInetCacheHints_INTERFACE_DEFINED__ equ <>
          ;* interface IWinInetCacheHints *
          ;* [unique][uuid][object][local] *
          ;* [unique] *
          LPWININETCACHEHINTS typedef ptr IWinInetCacheHints
          externdef IID_IWinInetCacheHints:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IWinInetCacheHintsVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IWinInetCacheHintsVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              ;* [in] *
              ;* [annotation][iid_is][out] *
              STD_METHOD QueryInterface, :ptr IWinInetCacheHints, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IWinInetCacheHints
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IWinInetCacheHints
              DECLSPEC_XFGVIRT(IWinInetCacheHints, SetCacheExtension)
              ;* [in] *
              ;* [size_is][out][in] *
              ;* [out][in] *
              ;* [out][in] *
              STD_METHOD SetCacheExtension, :ptr IWinInetCacheHints, :LPCWSTR, :LPVOID, :ptr DWORD, :ptr DWORD, :ptr DWORD
              ;* [out][in] *
              ??Interface equ <>
              END_INTERFACE
            IWinInetCacheHintsVtbl ends
            IWinInetCacheHints struct
              lpVtbl POINTER ?
            IWinInetCacheHints ends
            ifdef COBJMACROS
              ;[...]
            endif
            ;* C style interface *
          endif
          ;* __IWinInetCacheHints_INTERFACE_DEFINED__ *
        endif
        ;* interface __MIDL_itf_urlmon_0000_0023 *
        ;* [local] *
      endif
    endif
    ;(_WIN32_IE >= _WIN32_IE_IE60SP2)
    if (_WIN32_IE ge _WIN32_IE_IE70)
      ifndef _LPWININETCACHEHINTS2_DEFINED
        _LPWININETCACHEHINTS2_DEFINED equ <>
        externdef __MIDL_itf_urlmon_0000_0023_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0023_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IWinInetCacheHints2_INTERFACE_DEFINED__
          __IWinInetCacheHints2_INTERFACE_DEFINED__ equ <>
          ;* interface IWinInetCacheHints2 *
          ;* [unique][uuid][object][local] *
          ;* [unique] *
          LPWININETCACHEHINTS2 typedef ptr IWinInetCacheHints2
          externdef IID_IWinInetCacheHints2:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IWinInetCacheHints2Vtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IWinInetCacheHints2Vtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              ;* [in] *
              ;* [annotation][iid_is][out] *
              STD_METHOD QueryInterface, :ptr IWinInetCacheHints2, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IWinInetCacheHints2
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IWinInetCacheHints2
              DECLSPEC_XFGVIRT(IWinInetCacheHints, SetCacheExtension)
              ;* [in] *
              ;* [size_is][out][in] *
              ;* [out][in] *
              ;* [out][in] *
              STD_METHOD SetCacheExtension, :ptr IWinInetCacheHints2, :LPCWSTR, :LPVOID, :ptr DWORD, :ptr DWORD, :ptr DWORD
              ;* [out][in] *
              DECLSPEC_XFGVIRT(IWinInetCacheHints2, SetCacheExtension2)
              ;* [in] *
              ;* [annotation][size_is][out] *
              ;* [out][in] *
              ;* [out] *
              STD_METHOD SetCacheExtension2, :ptr IWinInetCacheHints2, :LPCWSTR, :ptr WCHAR, :ptr DWORD, :ptr DWORD, :ptr DWORD
              ;* [out] *
              ??Interface equ <>
              END_INTERFACE
            IWinInetCacheHints2Vtbl ends
            IWinInetCacheHints2 struct
              lpVtbl POINTER ?
            IWinInetCacheHints2 ends
            ifdef COBJMACROS
              ;[...]
            endif
            ;* C style interface *
          endif
          ;* __IWinInetCacheHints2_INTERFACE_DEFINED__ *
        endif
        ;* interface __MIDL_itf_urlmon_0000_0024 *
        ;* [local] *
      endif
    endif
    ;(_WIN32_IE >= _WIN32_IE_IE70)
    SID_IBindHost equ <IID_IBindHost>
    SID_SBindHost equ <IID_IBindHost>
    ifndef _LPBINDHOST_DEFINED
      _LPBINDHOST_DEFINED equ <>
      externdef SID_BindHost:GUID
      externdef __MIDL_itf_urlmon_0000_0024_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0024_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IBindHost_INTERFACE_DEFINED__
        __IBindHost_INTERFACE_DEFINED__ equ <>
        ;* interface IBindHost *
        ;* [unique][uuid][object] *
        ;* [unique] *
        LPBINDHOST typedef ptr IBindHost
        externdef IID_IBindHost:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IBindHostVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IBindHostVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IBindHost, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IBindHost
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IBindHost
            DECLSPEC_XFGVIRT(IBindHost, CreateMoniker)
            ;* [in] *
            ;* [in] *
            ;* [out] *
            STD_METHOD CreateMoniker, :ptr IBindHost, :LPOLESTR, :ptr IBindCtx, :ptr ptr IMoniker, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IBindHost, MonikerBindToStorage)
            ;* [local] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD MonikerBindToStorage, :ptr IBindHost, :ptr IMoniker, :ptr IBindCtx, :ptr IBindStatusCallback, :REFIID, :ptr ptr
            ;* [out] *
            DECLSPEC_XFGVIRT(IBindHost, MonikerBindToObject)
            ;* [local] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD MonikerBindToObject, :ptr IBindHost, :ptr IMoniker, :ptr IBindCtx, :ptr IBindStatusCallback, :REFIID, :ptr ptr
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IBindHostVtbl ends
          IBindHost struct
            lpVtbl POINTER ?
          IBindHost ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* [call_as] *
        IBindHost_RemoteMonikerBindToStorage_Proxy proto WIN_STD_CALL_CONV :ptr IBindHost, :ptr IMoniker, :ptr IBindCtx, :ptr IBindStatusCallback, :REFIID, :ptr ptr IUnknown
        ;* [iid_is][out] *
        IBindHost_RemoteMonikerBindToStorage_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        ;* [call_as] *
        IBindHost_RemoteMonikerBindToObject_Proxy proto WIN_STD_CALL_CONV :ptr IBindHost, :ptr IMoniker, :ptr IBindCtx, :ptr IBindStatusCallback, :REFIID, :ptr ptr IUnknown
        ;* [iid_is][out] *
        IBindHost_RemoteMonikerBindToObject_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        ;* __IBindHost_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0025 *
      ;* [local] *
    endif
    ; These are for backwards compatibility with previous URLMON versions
    ; Flags for the UrlDownloadToCacheFile                                                                    
    URLOSTRM_USECACHEDCOPY_ONLY equ 1h; Only get from cache                            

    URLOSTRM_USECACHEDCOPY equ 2h; Get from cache if available else download      

    URLOSTRM_GETNEWESTVERSION equ 3h; Get new version only. But put it in cache too  

    @DefProto DllImport, HlinkSimpleNavigateToString, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPCWSTR, :ptr IUnknown, :ptr IBindCtx, :ptr IBindStatusCallback, :DWORD, :DWORD>, 32
    ; for future use, must be NULL                                   
    @DefProto DllImport, HlinkSimpleNavigateToMoniker, WIN_STD_CALL_CONV,, <:ptr IMoniker, :LPCWSTR, :LPCWSTR, :ptr IUnknown, :ptr IBindCtx, :ptr IBindStatusCallback, :DWORD, :DWORD>, 32
    ; for future use, must be NULL                                   
    @DefProto DllImport, URLOpenStreamA, WIN_STD_CALL_CONV,, <:LPUNKNOWN, :LPCSTR, :DWORD, :LPBINDSTATUSCALLBACK>, 16
    @DefProto DllImport, URLOpenStreamW, WIN_STD_CALL_CONV,, <:LPUNKNOWN, :LPCWSTR, :DWORD, :LPBINDSTATUSCALLBACK>, 16
    @DefProto DllImport, URLOpenPullStreamA, WIN_STD_CALL_CONV,, <:LPUNKNOWN, :LPCSTR, :DWORD, :LPBINDSTATUSCALLBACK>, 16
    @DefProto DllImport, URLOpenPullStreamW, WIN_STD_CALL_CONV,, <:LPUNKNOWN, :LPCWSTR, :DWORD, :LPBINDSTATUSCALLBACK>, 16
    @DefProto DllImport, URLDownloadToFileA, WIN_STD_CALL_CONV,, <:LPUNKNOWN, :LPCSTR, :LPCSTR, :DWORD, :LPBINDSTATUSCALLBACK>, 20
    @DefProto DllImport, URLDownloadToFileW, WIN_STD_CALL_CONV,, <:LPUNKNOWN, :LPCWSTR, :LPCWSTR, :DWORD, :LPBINDSTATUSCALLBACK>, 20
    @DefProto DllImport, URLDownloadToCacheFileA, WIN_STD_CALL_CONV,, <:LPUNKNOWN, :LPCSTR, :LPSTR, :DWORD, :DWORD, :LPBINDSTATUSCALLBACK>, 24
    @DefProto DllImport, URLDownloadToCacheFileW, WIN_STD_CALL_CONV,, <:LPUNKNOWN, :LPCWSTR, :LPWSTR, :DWORD, :DWORD, :LPBINDSTATUSCALLBACK>, 24
    @DefProto DllImport, URLOpenBlockingStreamA, WIN_STD_CALL_CONV,, <:LPUNKNOWN, :LPCSTR, :ptr LPSTREAM, :DWORD, :LPBINDSTATUSCALLBACK>, 20
    @DefProto DllImport, URLOpenBlockingStreamW, WIN_STD_CALL_CONV,, <:LPUNKNOWN, :LPCWSTR, :ptr LPSTREAM, :DWORD, :LPBINDSTATUSCALLBACK>, 20
    ifdef UNICODE
      URLOpenStream equ <URLOpenStreamW>
      URLOpenPullStream equ <URLOpenPullStreamW>
      URLDownloadToFile equ <URLDownloadToFileW>
      URLDownloadToCacheFile equ <URLDownloadToCacheFileW>
      URLOpenBlockingStream equ <URLOpenBlockingStreamW>
    else
      URLOpenStream equ <URLOpenStreamA>
      URLOpenPullStream equ <URLOpenPullStreamA>
      URLDownloadToFile equ <URLDownloadToFileA>
      URLDownloadToCacheFile equ <URLDownloadToCacheFileA>
      URLOpenBlockingStream equ <URLOpenBlockingStreamA>
    endif
    ; !UNICODE                                                                                         
    @DefProto DllImport, HlinkGoBack, WIN_STD_CALL_CONV,, <:ptr IUnknown>, 4
    @DefProto DllImport, HlinkGoForward, WIN_STD_CALL_CONV,, <:ptr IUnknown>, 4
    @DefProto DllImport, HlinkNavigateString, WIN_STD_CALL_CONV,, <:ptr IUnknown, :LPCWSTR>, 8
    @DefProto DllImport, HlinkNavigateMoniker, WIN_STD_CALL_CONV,, <:ptr IUnknown, :ptr IMoniker>, 8
    ifndef _URLMON_NO_ASYNC_PLUGABLE_PROTOCOLS_
      ifndef _LPIINTERNET
        _LPIINTERNET equ <>
        externdef __MIDL_itf_urlmon_0000_0025_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0025_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IInternet_INTERFACE_DEFINED__
          __IInternet_INTERFACE_DEFINED__ equ <>
          ;* interface IInternet *
          ;* [unique][uuid][object][local] *
          ;* [unique] *
          LPIINTERNET typedef ptr IInternet
          externdef IID_IInternet:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IInternetVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              ;* [in] *
              ;* [annotation][iid_is][out] *
              STD_METHOD QueryInterface, :ptr IInternet, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IInternet
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IInternet
              ??Interface equ <>
              END_INTERFACE
            IInternetVtbl ends
            IInternet struct
              lpVtbl POINTER ?
            IInternet ends
            ifdef COBJMACROS
              ;[...]
            endif
            ;* C style interface *
          endif
          ;* __IInternet_INTERFACE_DEFINED__ *
        endif
        ;* interface __MIDL_itf_urlmon_0000_0026 *
        ;* [local] *
      endif
      ifndef _LPIINTERNETBINDINFO
        _LPIINTERNETBINDINFO equ <>
        externdef __MIDL_itf_urlmon_0000_0026_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0026_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IInternetBindInfo_INTERFACE_DEFINED__
          __IInternetBindInfo_INTERFACE_DEFINED__ equ <>
          ;* interface IInternetBindInfo *
          ;* [unique][uuid][object][local] *
          ;* [unique] *
          LPIINTERNETBINDINFO typedef ptr IInternetBindInfo
          BINDSTRING typedef SDWORD
          BINDSTRING_HEADERS equ 1
          BINDSTRING_ACCEPT_MIMES equ
          BINDSTRING_EXTRA_URL equ
          BINDSTRING_LANGUAGE equ
          BINDSTRING_USERNAME equ
          BINDSTRING_PASSWORD equ
          BINDSTRING_UA_PIXELS equ
          BINDSTRING_UA_COLOR equ
          BINDSTRING_OS equ
          BINDSTRING_USER_AGENT equ
          BINDSTRING_ACCEPT_ENCODINGS equ
          BINDSTRING_POST_COOKIE equ
          BINDSTRING_POST_DATA_MIME equ
          BINDSTRING_URL equ
          BINDSTRING_IID equ
          BINDSTRING_FLAG_BIND_TO_OBJECT equ
          BINDSTRING_PTR_BIND_CONTEXT equ
          BINDSTRING_XDR_ORIGIN equ
          BINDSTRING_DOWNLOADPATH equ
          BINDSTRING_ROOTDOC_URL equ
          BINDSTRING_INITIAL_FILENAME equ
          BINDSTRING_PROXY_USERNAME equ
          BINDSTRING_PROXY_PASSWORD equ
          BINDSTRING_ENTERPRISE_ID equ
          BINDSTRING_DOC_URL equ
          BINDSTRING_SAMESITE_COOKIE_LEVEL equ
          tagBINDSTRING typedef BINDSTRING

          externdef IID_IInternetBindInfo:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IInternetBindInfoVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetBindInfoVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              ;* [in] *
              ;* [annotation][iid_is][out] *
              STD_METHOD QueryInterface, :ptr IInternetBindInfo, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IInternetBindInfo
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IInternetBindInfo
              DECLSPEC_XFGVIRT(IInternetBindInfo, GetBindInfo)
              ;* [out] *
              STD_METHOD GetBindInfo, :ptr IInternetBindInfo, :ptr DWORD, :ptr BINDINFO
              ;* [unique][out][in] *
              DECLSPEC_XFGVIRT(IInternetBindInfo, GetBindString)
              ;* [in] *
              ;* [annotation][out][in] *
              ;* [in] *
              STD_METHOD GetBindString, :ptr IInternetBindInfo, :ULONG, :ptr LPOLESTR, :ULONG, :ptr ULONG
              ;* [out][in] *
              ??Interface equ <>
              END_INTERFACE
            IInternetBindInfoVtbl ends
            IInternetBindInfo struct
              lpVtbl POINTER ?
            IInternetBindInfo ends
            ifdef COBJMACROS
              ;[...]
            endif
            ;* C style interface *
          endif
          ;* __IInternetBindInfo_INTERFACE_DEFINED__ *
        endif
        ;* interface __MIDL_itf_urlmon_0000_0027 *
        ;* [local] *
      endif
      ifndef _LPIINTERNETBINDINFOEX
        _LPIINTERNETBINDINFOEX equ <>
        externdef __MIDL_itf_urlmon_0000_0027_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0027_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IInternetBindInfoEx_INTERFACE_DEFINED__
          __IInternetBindInfoEx_INTERFACE_DEFINED__ equ <>
          ;* interface IInternetBindInfoEx *
          ;* [unique][uuid][object][local] *
          ;* [unique] *
          LPIINTERNETBINDINFOEX typedef ptr IInternetBindInfoEx
          externdef IID_IInternetBindInfoEx:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IInternetBindInfoExVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetBindInfoExVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              ;* [in] *
              ;* [annotation][iid_is][out] *
              STD_METHOD QueryInterface, :ptr IInternetBindInfoEx, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IInternetBindInfoEx
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IInternetBindInfoEx
              DECLSPEC_XFGVIRT(IInternetBindInfo, GetBindInfo)
              ;* [out] *
              STD_METHOD GetBindInfo, :ptr IInternetBindInfoEx, :ptr DWORD, :ptr BINDINFO
              ;* [unique][out][in] *
              DECLSPEC_XFGVIRT(IInternetBindInfo, GetBindString)
              ;* [in] *
              ;* [annotation][out][in] *
              ;* [in] *
              STD_METHOD GetBindString, :ptr IInternetBindInfoEx, :ULONG, :ptr LPOLESTR, :ULONG, :ptr ULONG
              ;* [out][in] *
              DECLSPEC_XFGVIRT(IInternetBindInfoEx, GetBindInfoEx)
              ;* [out] *
              ;* [unique][out][in] *
              ;* [out] *
              STD_METHOD GetBindInfoEx, :ptr IInternetBindInfoEx, :ptr DWORD, :ptr BINDINFO, :ptr DWORD, :ptr DWORD
              ;* [out] *
              ??Interface equ <>
              END_INTERFACE
            IInternetBindInfoExVtbl ends
            IInternetBindInfoEx struct
              lpVtbl POINTER ?
            IInternetBindInfoEx ends
            ifdef COBJMACROS
              ;[...]
            endif
            ;* C style interface *
          endif
          ;* __IInternetBindInfoEx_INTERFACE_DEFINED__ *
        endif
        ;* interface __MIDL_itf_urlmon_0000_0028 *
        ;* [local] *
      endif
      ifndef _LPIINTERNETPROTOCOLROOT_DEFINED
        _LPIINTERNETPROTOCOLROOT_DEFINED equ <>
        externdef __MIDL_itf_urlmon_0000_0028_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0028_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IInternetProtocolRoot_INTERFACE_DEFINED__
          __IInternetProtocolRoot_INTERFACE_DEFINED__ equ <>
          ;* interface IInternetProtocolRoot *
          ;* [unique][uuid][object][local] *
          ;* [unique] *
          LPIINTERNETPROTOCOLROOT typedef ptr IInternetProtocolRoot
          PI_FLAGS typedef SDWORD
          PI_PARSE_URL equ 1h
          PI_FILTER_MODE equ 2h
          PI_FORCE_ASYNC equ 4h
          PI_USE_WORKERTHREAD equ 8h
          PI_MIMEVERIFICATION equ 10h
          PI_CLSIDLOOKUP equ 20h
          PI_DATAPROGRESS equ 40h
          PI_SYNCHRONOUS equ 80h
          PI_APARTMENTTHREADED equ 100h
          PI_CLASSINSTALL equ 200h
          PI_PASSONBINDCTX equ 2000h
          PI_NOMIMEHANDLER equ 8000h
          PI_LOADAPPDIRECT equ 4000h
          PD_FORCE_SWITCH equ 10000h
          PI_PREFERDEFAULTHANDLER equ 20000h
          _tagPI_FLAGS typedef PI_FLAGS

          PROTOCOLDATA struct
            grfFlags DWORD ?
            dwState DWORD ?
            pData POINTER ?
            cbData DWORD ?
          PROTOCOLDATA ends
          _tagPROTOCOLDATA typedef PROTOCOLDATA
          StartParam struct
            iid IID <>
            pIBindCtx POINTER ?
            pItf POINTER ?
          StartParam ends
          _tagStartParam typedef StartParam
          externdef IID_IInternetProtocolRoot:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IInternetProtocolRootVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetProtocolRootVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              ;* [in] *
              ;* [annotation][iid_is][out] *
              STD_METHOD QueryInterface, :ptr IInternetProtocolRoot, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IInternetProtocolRoot
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IInternetProtocolRoot
              DECLSPEC_XFGVIRT(IInternetProtocolRoot, Start)
              ;* [in] *
              ;* [in] *
              ;* [in] *
              ;* [in] *
              STD_METHOD Start, :ptr IInternetProtocolRoot, :LPCWSTR, :ptr IInternetProtocolSink, :ptr IInternetBindInfo, :DWORD, :HANDLE_PTR
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetProtocolRoot, Continue)
              STD_METHOD Continue, :ptr IInternetProtocolRoot, :ptr PROTOCOLDATA
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetProtocolRoot, Abort)
              ;* [in] *
              STD_METHOD Abort, :ptr IInternetProtocolRoot, :HRESULT, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetProtocolRoot, Terminate)
              STD_METHOD Terminate, :ptr IInternetProtocolRoot, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetProtocolRoot, Suspend)
              STD_METHOD Suspend, :ptr IInternetProtocolRoot
              DECLSPEC_XFGVIRT(IInternetProtocolRoot, Resume)
              STD_METHOD Resume, :ptr IInternetProtocolRoot
              ??Interface equ <>
              END_INTERFACE
            IInternetProtocolRootVtbl ends
            IInternetProtocolRoot struct
              lpVtbl POINTER ?
            IInternetProtocolRoot ends
            ifdef COBJMACROS
              ;[...]
            endif
            ;* C style interface *
          endif
          ;* __IInternetProtocolRoot_INTERFACE_DEFINED__ *
        endif
        ;* interface __MIDL_itf_urlmon_0000_0029 *
        ;* [local] *
      endif
      ifndef _LPIINTERNETPROTOCOL_DEFINED
        _LPIINTERNETPROTOCOL_DEFINED equ <>
        externdef __MIDL_itf_urlmon_0000_0029_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0029_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IInternetProtocol_INTERFACE_DEFINED__
          __IInternetProtocol_INTERFACE_DEFINED__ equ <>
          ;* interface IInternetProtocol *
          ;* [unique][uuid][object][local] *
          ;* [unique] *
          LPIINTERNETPROTOCOL typedef ptr IInternetProtocol
          externdef IID_IInternetProtocol:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IInternetProtocolVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetProtocolVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              ;* [in] *
              ;* [annotation][iid_is][out] *
              STD_METHOD QueryInterface, :ptr IInternetProtocol, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IInternetProtocol
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IInternetProtocol
              DECLSPEC_XFGVIRT(IInternetProtocolRoot, Start)
              ;* [in] *
              ;* [in] *
              ;* [in] *
              ;* [in] *
              STD_METHOD Start, :ptr IInternetProtocol, :LPCWSTR, :ptr IInternetProtocolSink, :ptr IInternetBindInfo, :DWORD, :HANDLE_PTR
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetProtocolRoot, Continue)
              STD_METHOD Continue, :ptr IInternetProtocol, :ptr PROTOCOLDATA
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetProtocolRoot, Abort)
              ;* [in] *
              STD_METHOD Abort, :ptr IInternetProtocol, :HRESULT, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetProtocolRoot, Terminate)
              STD_METHOD Terminate, :ptr IInternetProtocol, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetProtocolRoot, Suspend)
              STD_METHOD Suspend, :ptr IInternetProtocol
              DECLSPEC_XFGVIRT(IInternetProtocolRoot, Resume)
              STD_METHOD Resume, :ptr IInternetProtocol
              DECLSPEC_XFGVIRT(IInternetProtocol, Read)
              ;* [length_is][size_is][out][in] *
              ;* [in] *
              STD_METHOD Read, :ptr IInternetProtocol, :ptr, :ULONG, :ptr ULONG
              ;* [out] *
              DECLSPEC_XFGVIRT(IInternetProtocol, Seek)
              ;* [in] *
              ;* [in] *
              STD_METHOD Seek, :ptr IInternetProtocol, :LARGE_INTEGER, :DWORD, :ptr ULARGE_INTEGER
              ;* [out] *
              DECLSPEC_XFGVIRT(IInternetProtocol, LockRequest)
              STD_METHOD LockRequest, :ptr IInternetProtocol, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetProtocol, UnlockRequest)
              STD_METHOD UnlockRequest, :ptr IInternetProtocol
              ??Interface equ <>
              END_INTERFACE
            IInternetProtocolVtbl ends
            IInternetProtocol struct
              lpVtbl POINTER ?
            IInternetProtocol ends
            ifdef COBJMACROS
              ;[...]
            endif
            ;* C style interface *
          endif
          ;* __IInternetProtocol_INTERFACE_DEFINED__ *
        endif
        ;* interface __MIDL_itf_urlmon_0000_0030 *
        ;* [local] *
      endif
      if (_WIN32_IE ge _WIN32_IE_IE70)
        ifndef _LPIINTERNETPROTOCOLEX_DEFINED
          _LPIINTERNETPROTOCOLEX_DEFINED equ <>
          externdef __MIDL_itf_urlmon_0000_0030_v0_0_c_ifspec:RPC_IF_HANDLE
          externdef __MIDL_itf_urlmon_0000_0030_v0_0_s_ifspec:RPC_IF_HANDLE
          ifndef __IInternetProtocolEx_INTERFACE_DEFINED__
            __IInternetProtocolEx_INTERFACE_DEFINED__ equ <>
            ;* interface IInternetProtocolEx *
            ;* [unique][uuid][object][local] *
            externdef IID_IInternetProtocolEx:IID
            if Defined(__cplusplus) and  not Defined(CINTERFACE)
              ;[...]
            else
              IInternetProtocolExVtbl struct
                BEGIN_INTERFACE
                ??Interface equ <IInternetProtocolExVtbl>
                DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
                ;* [in] *
                ;* [annotation][iid_is][out] *
                STD_METHOD QueryInterface, :ptr IInternetProtocolEx, :REFIID, :ptr ptr
                DECLSPEC_XFGVIRT(IUnknown, AddRef)
                STD_METHOD AddRef, :ptr IInternetProtocolEx
                DECLSPEC_XFGVIRT(IUnknown, Release)
                STD_METHOD Release, :ptr IInternetProtocolEx
                DECLSPEC_XFGVIRT(IInternetProtocolRoot, Start)
                ;* [in] *
                ;* [in] *
                ;* [in] *
                ;* [in] *
                STD_METHOD Start, :ptr IInternetProtocolEx, :LPCWSTR, :ptr IInternetProtocolSink, :ptr IInternetBindInfo, :DWORD, :HANDLE_PTR
                ;* [in] *
                DECLSPEC_XFGVIRT(IInternetProtocolRoot, Continue)
                STD_METHOD Continue, :ptr IInternetProtocolEx, :ptr PROTOCOLDATA
                ;* [in] *
                DECLSPEC_XFGVIRT(IInternetProtocolRoot, Abort)
                ;* [in] *
                STD_METHOD Abort, :ptr IInternetProtocolEx, :HRESULT, :DWORD
                ;* [in] *
                DECLSPEC_XFGVIRT(IInternetProtocolRoot, Terminate)
                STD_METHOD Terminate, :ptr IInternetProtocolEx, :DWORD
                ;* [in] *
                DECLSPEC_XFGVIRT(IInternetProtocolRoot, Suspend)
                STD_METHOD Suspend, :ptr IInternetProtocolEx
                DECLSPEC_XFGVIRT(IInternetProtocolRoot, Resume)
                STD_METHOD Resume, :ptr IInternetProtocolEx
                DECLSPEC_XFGVIRT(IInternetProtocol, Read)
                ;* [length_is][size_is][out][in] *
                ;* [in] *
                STD_METHOD Read, :ptr IInternetProtocolEx, :ptr, :ULONG, :ptr ULONG
                ;* [out] *
                DECLSPEC_XFGVIRT(IInternetProtocol, Seek)
                ;* [in] *
                ;* [in] *
                STD_METHOD Seek, :ptr IInternetProtocolEx, :LARGE_INTEGER, :DWORD, :ptr ULARGE_INTEGER
                ;* [out] *
                DECLSPEC_XFGVIRT(IInternetProtocol, LockRequest)
                STD_METHOD LockRequest, :ptr IInternetProtocolEx, :DWORD
                ;* [in] *
                DECLSPEC_XFGVIRT(IInternetProtocol, UnlockRequest)
                STD_METHOD UnlockRequest, :ptr IInternetProtocolEx
                DECLSPEC_XFGVIRT(IInternetProtocolEx, StartEx)
                ;* [in] *
                ;* [in] *
                ;* [in] *
                ;* [in] *
                STD_METHOD StartEx, :ptr IInternetProtocolEx, :ptr IUri, :ptr IInternetProtocolSink, :ptr IInternetBindInfo, :DWORD, :HANDLE_PTR
                ;* [in] *
                ??Interface equ <>
                END_INTERFACE
              IInternetProtocolExVtbl ends
              IInternetProtocolEx struct
                lpVtbl POINTER ?
              IInternetProtocolEx ends
              ifdef COBJMACROS
                ;[...]
              endif
              ;* C style interface *
            endif
            ;* __IInternetProtocolEx_INTERFACE_DEFINED__ *
          endif
          ;* interface __MIDL_itf_urlmon_0000_0031 *
          ;* [local] *
        endif
      endif
      ;(_WIN32_IE >= _WIN32_IE_IE70)
      ifndef _LPIINTERNETPROTOCOLSINK_DEFINED
        _LPIINTERNETPROTOCOLSINK_DEFINED equ <>
        externdef __MIDL_itf_urlmon_0000_0031_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0031_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IInternetProtocolSink_INTERFACE_DEFINED__
          __IInternetProtocolSink_INTERFACE_DEFINED__ equ <>
          ;* interface IInternetProtocolSink *
          ;* [unique][uuid][object][local] *
          ;* [unique] *
          LPIINTERNETPROTOCOLSINK typedef ptr IInternetProtocolSink
          externdef IID_IInternetProtocolSink:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IInternetProtocolSinkVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetProtocolSinkVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              ;* [in] *
              ;* [annotation][iid_is][out] *
              STD_METHOD QueryInterface, :ptr IInternetProtocolSink, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IInternetProtocolSink
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IInternetProtocolSink
              DECLSPEC_XFGVIRT(IInternetProtocolSink, Switch)
              STD_METHOD Switch, :ptr IInternetProtocolSink, :ptr PROTOCOLDATA
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetProtocolSink, ReportProgress)
              ;* [in] *
              STD_METHOD ReportProgress, :ptr IInternetProtocolSink, :ULONG, :LPCWSTR
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetProtocolSink, ReportData)
              ;* [in] *
              ;* [in] *
              STD_METHOD ReportData, :ptr IInternetProtocolSink, :DWORD, :ULONG, :ULONG
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetProtocolSink, ReportResult)
              ;* [in] *
              ;* [in] *
              STD_METHOD ReportResult, :ptr IInternetProtocolSink, :HRESULT, :DWORD, :LPCWSTR
              ;* [in] *
              ??Interface equ <>
              END_INTERFACE
            IInternetProtocolSinkVtbl ends
            IInternetProtocolSink struct
              lpVtbl POINTER ?
            IInternetProtocolSink ends
            ifdef COBJMACROS
              ;[...]
            endif
            ;* C style interface *
          endif
          ;* __IInternetProtocolSink_INTERFACE_DEFINED__ *
        endif
        ;* interface __MIDL_itf_urlmon_0000_0032 *
        ;* [local] *
      endif
      ifndef _LPIINTERNETPROTOCOLSINKSTACKABLE_DEFINED
        _LPIINTERNETPROTOCOLSINKSTACKABLE_DEFINED equ <>
        externdef __MIDL_itf_urlmon_0000_0032_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0032_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IInternetProtocolSinkStackable_INTERFACE_DEFINED__
          __IInternetProtocolSinkStackable_INTERFACE_DEFINED__ equ <>
          ;* interface IInternetProtocolSinkStackable *
          ;* [unique][uuid][object][local] *
          ;* [unique] *
          LPIINTERNETPROTOCOLSINKStackable typedef ptr IInternetProtocolSinkStackable
          externdef IID_IInternetProtocolSinkStackable:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IInternetProtocolSinkStackableVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetProtocolSinkStackableVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              ;* [in] *
              ;* [annotation][iid_is][out] *
              STD_METHOD QueryInterface, :ptr IInternetProtocolSinkStackable, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IInternetProtocolSinkStackable
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IInternetProtocolSinkStackable
              DECLSPEC_XFGVIRT(IInternetProtocolSinkStackable, SwitchSink)
              STD_METHOD SwitchSink, :ptr IInternetProtocolSinkStackable, :ptr IInternetProtocolSink
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetProtocolSinkStackable, CommitSwitch)
              STD_METHOD CommitSwitch, :ptr IInternetProtocolSinkStackable
              DECLSPEC_XFGVIRT(IInternetProtocolSinkStackable, RollbackSwitch)
              STD_METHOD RollbackSwitch, :ptr IInternetProtocolSinkStackable
              ??Interface equ <>
              END_INTERFACE
            IInternetProtocolSinkStackableVtbl ends
            IInternetProtocolSinkStackable struct
              lpVtbl POINTER ?
            IInternetProtocolSinkStackable ends
            ifdef COBJMACROS
              ;[...]
            endif
            ;* C style interface *
          endif
          ;* __IInternetProtocolSinkStackable_INTERFACE_DEFINED__ *
        endif
        ;* interface __MIDL_itf_urlmon_0000_0033 *
        ;* [local] *
      endif
      ifndef _LPIINTERNETSESSION_DEFINED
        _LPIINTERNETSESSION_DEFINED equ <>
        externdef __MIDL_itf_urlmon_0000_0033_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0033_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IInternetSession_INTERFACE_DEFINED__
          __IInternetSession_INTERFACE_DEFINED__ equ <>
          ;* interface IInternetSession *
          ;* [unique][uuid][object][local] *
          ;* [unique] *
          LPIINTERNETSESSION typedef ptr IInternetSession
          OIBDG_FLAGS typedef SDWORD
          OIBDG_APARTMENTTHREADED equ 100h
          OIBDG_DATAONLY equ 1000h
          _tagOIBDG_FLAGS typedef OIBDG_FLAGS

          externdef IID_IInternetSession:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IInternetSessionVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetSessionVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              ;* [in] *
              ;* [annotation][iid_is][out] *
              STD_METHOD QueryInterface, :ptr IInternetSession, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IInternetSession
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IInternetSession
              DECLSPEC_XFGVIRT(IInternetSession, RegisterNameSpace)
              ;* [in] *
              ;* [in] *
              ;* [in] *
              ;* [in] *
              ;* [in] *
              STD_METHOD RegisterNameSpace, :ptr IInternetSession, :ptr IClassFactory, :REFCLSID, :LPCWSTR, :ULONG, :ptr LPCWSTR, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetSession, UnregisterNameSpace)
              ;* [in] *
              STD_METHOD UnregisterNameSpace, :ptr IInternetSession, :ptr IClassFactory, :LPCWSTR
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetSession, RegisterMimeFilter)
              ;* [in] *
              ;* [in] *
              STD_METHOD RegisterMimeFilter, :ptr IInternetSession, :ptr IClassFactory, :REFCLSID, :LPCWSTR
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetSession, UnregisterMimeFilter)
              ;* [in] *
              STD_METHOD UnregisterMimeFilter, :ptr IInternetSession, :ptr IClassFactory, :LPCWSTR
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetSession, CreateBinding)
              ;* [in] *
              ;* [in] *
              ;* [in] *
              ;* [unique][out] *
              ;* [unique][out] *
              STD_METHOD CreateBinding, :ptr IInternetSession, :LPBC, :LPCWSTR, :ptr IUnknown, :ptr ptr IUnknown, :ptr ptr IInternetProtocol, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetSession, SetSessionOption)
              ;* [in] *
              ;* [in] *
              ;* [in] *
              STD_METHOD SetSessionOption, :ptr IInternetSession, :DWORD, :LPVOID, :DWORD, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetSession, GetSessionOption)
              ;* [in] *
              ;* [out][in] *
              ;* [out][in] *
              STD_METHOD GetSessionOption, :ptr IInternetSession, :DWORD, :LPVOID, :ptr DWORD, :DWORD
              ;* [in] *
              ??Interface equ <>
              END_INTERFACE
            IInternetSessionVtbl ends
            IInternetSession struct
              lpVtbl POINTER ?
            IInternetSession ends
            ifdef COBJMACROS
              ;[...]
            endif
            ;* C style interface *
          endif
          ;* __IInternetSession_INTERFACE_DEFINED__ *
        endif
        ;* interface __MIDL_itf_urlmon_0000_0034 *
        ;* [local] *
      endif
      ifndef _LPIINTERNETTHREADSWITCH_DEFINED
        _LPIINTERNETTHREADSWITCH_DEFINED equ <>
        externdef __MIDL_itf_urlmon_0000_0034_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0034_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IInternetThreadSwitch_INTERFACE_DEFINED__
          __IInternetThreadSwitch_INTERFACE_DEFINED__ equ <>
          ;* interface IInternetThreadSwitch *
          ;* [unique][uuid][object][local] *
          ;* [unique] *
          LPIINTERNETTHREADSWITCH typedef ptr IInternetThreadSwitch
          externdef IID_IInternetThreadSwitch:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IInternetThreadSwitchVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetThreadSwitchVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              ;* [in] *
              ;* [annotation][iid_is][out] *
              STD_METHOD QueryInterface, :ptr IInternetThreadSwitch, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IInternetThreadSwitch
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IInternetThreadSwitch
              DECLSPEC_XFGVIRT(IInternetThreadSwitch, Prepare)
              STD_METHOD Prepare, :ptr IInternetThreadSwitch
              DECLSPEC_XFGVIRT(IInternetThreadSwitch, Continue)
              STD_METHOD Continue, :ptr IInternetThreadSwitch
              ??Interface equ <>
              END_INTERFACE
            IInternetThreadSwitchVtbl ends
            IInternetThreadSwitch struct
              lpVtbl POINTER ?
            IInternetThreadSwitch ends
            ifdef COBJMACROS
              ;[...]
            endif
            ;* C style interface *
          endif
          ;* __IInternetThreadSwitch_INTERFACE_DEFINED__ *
        endif
        ;* interface __MIDL_itf_urlmon_0000_0035 *
        ;* [local] *
      endif
      ifndef _LPIINTERNETPRIORITY_DEFINED
        _LPIINTERNETPRIORITY_DEFINED equ <>
        externdef __MIDL_itf_urlmon_0000_0035_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0035_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IInternetPriority_INTERFACE_DEFINED__
          __IInternetPriority_INTERFACE_DEFINED__ equ <>
          ;* interface IInternetPriority *
          ;* [unique][uuid][object][local] *
          ;* [unique] *
          LPIINTERNETPRIORITY typedef ptr IInternetPriority
          externdef IID_IInternetPriority:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IInternetPriorityVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetPriorityVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              ;* [in] *
              ;* [annotation][iid_is][out] *
              STD_METHOD QueryInterface, :ptr IInternetPriority, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IInternetPriority
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IInternetPriority
              DECLSPEC_XFGVIRT(IInternetPriority, SetPriority)
              STD_METHOD SetPriority, :ptr IInternetPriority, :LONG
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetPriority, GetPriority)
              STD_METHOD GetPriority, :ptr IInternetPriority, :ptr LONG
              ;* [out] *
              ??Interface equ <>
              END_INTERFACE
            IInternetPriorityVtbl ends
            IInternetPriority struct
              lpVtbl POINTER ?
            IInternetPriority ends
            ifdef COBJMACROS
              ;[...]
            endif
            ;* C style interface *
          endif
          ;* __IInternetPriority_INTERFACE_DEFINED__ *
        endif
        ;* interface __MIDL_itf_urlmon_0000_0036 *
        ;* [local] *
      endif
      ifndef _LPIINTERNETPROTOCOLINFO_DEFINED
        _LPIINTERNETPROTOCOLINFO_DEFINED equ <>
        externdef __MIDL_itf_urlmon_0000_0036_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0036_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IInternetProtocolInfo_INTERFACE_DEFINED__
          __IInternetProtocolInfo_INTERFACE_DEFINED__ equ <>
          ;* interface IInternetProtocolInfo *
          ;* [unique][uuid][object][local] *
          ;* [unique] *
          LPIINTERNETPROTOCOLINFO typedef ptr IInternetProtocolInfo
          PARSEACTION typedef SDWORD
          PARSE_CANONICALIZE equ 1
          PARSE_FRIENDLY equ
          PARSE_SECURITY_URL equ
          PARSE_ROOTDOCUMENT equ
          PARSE_DOCUMENT equ
          PARSE_ANCHOR equ
          PARSE_ENCODE_IS_UNESCAPE equ
          PARSE_DECODE_IS_ESCAPE equ
          PARSE_PATH_FROM_URL equ
          PARSE_URL_FROM_PATH equ
          PARSE_MIME equ
          PARSE_SERVER equ
          PARSE_SCHEMA equ
          PARSE_SITE equ
          PARSE_DOMAIN equ
          PARSE_LOCATION equ
          PARSE_SECURITY_DOMAIN equ
          PARSE_ESCAPE equ
          PARSE_UNESCAPE equ
          _tagPARSEACTION typedef PARSEACTION

          PSUACTION typedef SDWORD
          PSU_DEFAULT equ 1
          PSU_SECURITY_URL_ONLY equ
          _tagPSUACTION typedef PSUACTION

          QUERYOPTION typedef SDWORD
          QUERY_EXPIRATION_DATE equ 1
          QUERY_TIME_OF_LAST_CHANGE equ
          QUERY_CONTENT_ENCODING equ
          QUERY_CONTENT_TYPE equ
          QUERY_REFRESH equ
          QUERY_RECOMBINE equ
          QUERY_CAN_NAVIGATE equ
          QUERY_USES_NETWORK equ
          QUERY_IS_CACHED equ
          QUERY_IS_INSTALLEDENTRY equ
          QUERY_IS_CACHED_OR_MAPPED equ
          QUERY_USES_CACHE equ
          QUERY_IS_SECURE equ
          QUERY_IS_SAFE equ
          QUERY_USES_HISTORYFOLDER equ
          QUERY_IS_CACHED_AND_USABLE_OFFLINE equ
          _tagQUERYOPTION typedef QUERYOPTION

          externdef IID_IInternetProtocolInfo:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IInternetProtocolInfoVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetProtocolInfoVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              ;* [in] *
              ;* [annotation][iid_is][out] *
              STD_METHOD QueryInterface, :ptr IInternetProtocolInfo, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IInternetProtocolInfo
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IInternetProtocolInfo
              DECLSPEC_XFGVIRT(IInternetProtocolInfo, ParseUrl)
              ;* [in] *
              ;* [in] *
              ;* [in] *
              ;* [annotation][out] *
              ;* [in] *
              ;* [out] *
              STD_METHOD ParseUrl, :ptr IInternetProtocolInfo, :LPCWSTR, :PARSEACTION, :DWORD, :LPWSTR, :DWORD, :ptr DWORD, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetProtocolInfo, CombineUrl)
              ;* [in] *
              ;* [in] *
              ;* [in] *
              ;* [annotation][out] *
              ;* [in] *
              ;* [out] *
              STD_METHOD CombineUrl, :ptr IInternetProtocolInfo, :LPCWSTR, :LPCWSTR, :DWORD, :LPWSTR, :DWORD, :ptr DWORD, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetProtocolInfo, CompareUrl)
              ;* [in] *
              ;* [in] *
              STD_METHOD CompareUrl, :ptr IInternetProtocolInfo, :LPCWSTR, :LPCWSTR, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetProtocolInfo, QueryInfo)
              ;* [in] *
              ;* [in] *
              ;* [in] *
              ;* [size_is][out][in] *
              ;* [in] *
              ;* [out][in] *
              STD_METHOD QueryInfo, :ptr IInternetProtocolInfo, :LPCWSTR, :QUERYOPTION, :DWORD, :LPVOID, :DWORD, :ptr DWORD, :DWORD
              ;* [in] *
              ??Interface equ <>
              END_INTERFACE
            IInternetProtocolInfoVtbl ends
            IInternetProtocolInfo struct
              lpVtbl POINTER ?
            IInternetProtocolInfo ends
            ifdef COBJMACROS
              ;[...]
            endif
            ;* C style interface *
          endif
          ;* __IInternetProtocolInfo_INTERFACE_DEFINED__ *
        endif
        ;* interface __MIDL_itf_urlmon_0000_0037 *
        ;* [local] *
        ifndef URLMON_STRICT
          ; PARSE_ENCODE was misnamed and is deprecated for PARSE_UNESCAPE
          PARSE_ENCODE equ <PARSE_ENCODE_IS_UNESCAPE>
          ; PARSE_DECODE was misnamed and is deprecated for PARSE_ESCAPE
          PARSE_DECODE equ <PARSE_DECODE_IS_ESCAPE>
        endif
        ;!URLMON_STRICT
      endif
      IOInet equ <IInternet>
      IOInetBindInfo equ <IInternetBindInfo>
      IOInetBindInfoEx equ <IInternetBindInfoEx>
      IOInetProtocolRoot equ <IInternetProtocolRoot>
      IOInetProtocol equ <IInternetProtocol>
      if (_WIN32_IE ge _WIN32_IE_IE70)
        IOInetProtocolEx equ <IInternetProtocolEx>
      endif
      ;(_WIN32_IE >= _WIN32_IE_IE70)
      IOInetProtocolSink equ <IInternetProtocolSink>
      IOInetProtocolInfo equ <IInternetProtocolInfo>
      IOInetSession equ <IInternetSession>
      IOInetPriority equ <IInternetPriority>
      IOInetThreadSwitch equ <IInternetThreadSwitch>
      IOInetProtocolSinkStackable equ <IInternetProtocolSinkStackable>
      LPOINET equ <LPIINTERNET>
      LPOINETPROTOCOLINFO equ <LPIINTERNETPROTOCOLINFO>
      LPOINETBINDINFO equ <LPIINTERNETBINDINFO>
      LPOINETPROTOCOLROOT equ <LPIINTERNETPROTOCOLROOT>
      LPOINETPROTOCOL equ <LPIINTERNETPROTOCOL>
      if (_WIN32_IE ge _WIN32_IE_IE70)
        LPOINETPROTOCOLEX equ <LPIINTERNETPROTOCOLEX>
      endif
      ;(_WIN32_IE >= _WIN32_IE_IE70)
      LPOINETPROTOCOLSINK equ <LPIINTERNETPROTOCOLSINK>
      LPOINETSESSION equ <LPIINTERNETSESSION>
      LPOINETTHREADSWITCH equ <LPIINTERNETTHREADSWITCH>
      LPOINETPRIORITY equ <LPIINTERNETPRIORITY>
      LPOINETPROTOCOLINFO equ <LPIINTERNETPROTOCOLINFO>
      LPOINETPROTOCOLSINKSTACKABLE equ <LPIINTERNETPROTOCOLSINKSTACKABLE>
      IID_IOInet equ <IID_IInternet>
      IID_IOInetBindInfo equ <IID_IInternetBindInfo>
      IID_IOInetBindInfoEx equ <IID_IInternetBindInfoEx>
      IID_IOInetProtocolRoot equ <IID_IInternetProtocolRoot>
      IID_IOInetProtocol equ <IID_IInternetProtocol>
      if (_WIN32_IE ge _WIN32_IE_IE70)
        IID_IOInetProtocolEx equ <IID_IInternetProtocolEx>
      endif
      ;(_WIN32_IE >= _WIN32_IE_IE70)
      IID_IOInetProtocolSink equ <IID_IInternetProtocolSink>
      IID_IOInetProtocolInfo equ <IID_IInternetProtocolInfo>
      IID_IOInetSession equ <IID_IInternetSession>
      IID_IOInetPriority equ <IID_IInternetPriority>
      IID_IOInetThreadSwitch equ <IID_IInternetThreadSwitch>
      IID_IOInetProtocolSinkStackable equ <IID_IInternetProtocolSinkStackable>
      @DefProto DllImport, CoInternetParseUrl, WIN_STD_CALL_CONV,, <:LPCWSTR, :PARSEACTION, :DWORD, :LPWSTR, :DWORD, :ptr DWORD, :DWORD>, 28
      if (_WIN32_IE ge _WIN32_IE_IE70)
        @DefProto DllImport, CoInternetParseIUri, WIN_STD_CALL_CONV,, <:ptr IUri, :PARSEACTION, :DWORD, :LPWSTR, :DWORD, :ptr DWORD, :DWORD_PTR>, 28
      endif
      ;(_WIN32_IE >= _WIN32_IE_IE70)
      @DefProto DllImport, CoInternetCombineUrl, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :DWORD, :LPWSTR, :DWORD, :ptr DWORD, :DWORD>, 28
      if (_WIN32_IE ge _WIN32_IE_IE70)
        @DefProto DllImport, CoInternetCombineUrlEx, WIN_STD_CALL_CONV,, <:ptr IUri, :LPCWSTR, :DWORD, :ptr ptr IUri, :DWORD_PTR>, 20
        @DefProto DllImport, CoInternetCombineIUri, WIN_STD_CALL_CONV,, <:ptr IUri, :ptr IUri, :DWORD, :ptr ptr IUri, :DWORD_PTR>, 20
      endif
      ;(_WIN32_IE >= _WIN32_IE_IE70)
      @DefProto DllImport, CoInternetCompareUrl, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :DWORD>, 12
      @DefProto DllImport, CoInternetGetProtocolFlags, WIN_STD_CALL_CONV,, <:LPCWSTR, :ptr DWORD, :DWORD>, 12
      @DefProto DllImport, CoInternetQueryInfo, WIN_STD_CALL_CONV,, <:LPCWSTR, :QUERYOPTION, :DWORD, :LPVOID, :DWORD, :ptr DWORD, :DWORD>, 28
      @DefProto DllImport, CoInternetGetSession, WIN_STD_CALL_CONV,, <:DWORD, :ptr ptr IInternetSession, :DWORD>, 12
      @DefProto DllImport, CoInternetGetSecurityUrl, WIN_STD_CALL_CONV,, <:LPCWSTR, :ptr LPWSTR, :PSUACTION, :DWORD>, 16
      @DefProto DllImport, AsyncInstallDistributionUnit, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPCWSTR, :DWORD, :DWORD, :LPCWSTR, :ptr IBindCtx, :LPVOID, :DWORD>, 36
      if (_WIN32_IE ge _WIN32_IE_IE70)
        @DefProto DllImport, CoInternetGetSecurityUrlEx, WIN_STD_CALL_CONV,, <:ptr IUri, :ptr ptr IUri, :PSUACTION, :DWORD_PTR>, 16
      endif
      ;(_WIN32_IE >= _WIN32_IE_IE70)
      if (_WIN32_IE ge _WIN32_IE_IE60SP2)
        ifndef _INTERNETFEATURELIST_DEFINED
          _INTERNETFEATURELIST_DEFINED equ <>
          INTERNETFEATURELIST typedef SDWORD
          FEATURE_OBJECT_CACHING equ 0
          FEATURE_ZONE_ELEVATION equ
          FEATURE_MIME_HANDLING equ
          FEATURE_MIME_SNIFFING equ
          FEATURE_WINDOW_RESTRICTIONS equ
          FEATURE_WEBOC_POPUPMANAGEMENT equ
          FEATURE_BEHAVIORS equ
          FEATURE_DISABLE_MK_PROTOCOL equ
          FEATURE_LOCALMACHINE_LOCKDOWN equ
          FEATURE_SECURITYBAND equ
          FEATURE_RESTRICT_ACTIVEXINSTALL equ
          FEATURE_VALIDATE_NAVIGATE_URL equ
          FEATURE_RESTRICT_FILEDOWNLOAD equ
          FEATURE_ADDON_MANAGEMENT equ
          FEATURE_PROTOCOL_LOCKDOWN equ
          FEATURE_HTTP_USERNAME_PASSWORD_DISABLE equ
          FEATURE_SAFE_BINDTOOBJECT equ
          FEATURE_UNC_SAVEDFILECHECK equ
          FEATURE_GET_URL_DOM_FILEPATH_UNENCODED equ
          FEATURE_TABBED_BROWSING equ
          FEATURE_SSLUX equ
          FEATURE_DISABLE_NAVIGATION_SOUNDS equ
          FEATURE_DISABLE_LEGACY_COMPRESSION equ
          FEATURE_FORCE_ADDR_AND_STATUS equ
          FEATURE_XMLHTTP equ
          FEATURE_DISABLE_TELNET_PROTOCOL equ
          FEATURE_FEEDS equ
          FEATURE_BLOCK_INPUT_PROMPTS equ
          FEATURE_ENTRY_COUNT equ
          _tagINTERNETFEATURELIST typedef INTERNETFEATURELIST

          ; CoInternetSetFeatureEnabled can be used to set/reset features. 
          ; The following flags control where the feature is set
          SET_FEATURE_ON_THREAD equ 00000001h
          SET_FEATURE_ON_PROCESS equ 00000002h
          SET_FEATURE_IN_REGISTRY equ 00000004h
          SET_FEATURE_ON_THREAD_LOCALMACHINE equ 00000008h
          SET_FEATURE_ON_THREAD_INTRANET equ 00000010h
          SET_FEATURE_ON_THREAD_TRUSTED equ 00000020h
          SET_FEATURE_ON_THREAD_INTERNET equ 00000040h
          SET_FEATURE_ON_THREAD_RESTRICTED equ 00000080h
          ; CoInternetIsFeatureEnabled can be used to get features. 
          ; The following flags control where the feature is obtained from
          ; default is from process
          GET_FEATURE_FROM_THREAD equ 00000001h
          GET_FEATURE_FROM_PROCESS equ 00000002h
          GET_FEATURE_FROM_REGISTRY equ 00000004h
          GET_FEATURE_FROM_THREAD_LOCALMACHINE equ 00000008h
          GET_FEATURE_FROM_THREAD_INTRANET equ 00000010h
          GET_FEATURE_FROM_THREAD_TRUSTED equ 00000020h
          GET_FEATURE_FROM_THREAD_INTERNET equ 00000040h
          GET_FEATURE_FROM_THREAD_RESTRICTED equ 00000080h
        endif
        @DefProto DllImport, CoInternetSetFeatureEnabled, WIN_STD_CALL_CONV,, <:INTERNETFEATURELIST, :DWORD, :BOOL>, 12
        @DefProto DllImport, CoInternetIsFeatureEnabled, WIN_STD_CALL_CONV,, <:INTERNETFEATURELIST, :DWORD>, 8
        @DefProto DllImport, CoInternetIsFeatureEnabledForUrl, WIN_STD_CALL_CONV,, <:INTERNETFEATURELIST, :DWORD, :LPCWSTR, :ptr IInternetSecurityManager>, 16
        @DefProto DllImport, CoInternetIsFeatureEnabledForIUri, WIN_STD_CALL_CONV,, <:INTERNETFEATURELIST, :DWORD, :ptr IUri, :ptr IInternetSecurityManagerEx2>, 16
        @DefProto DllImport, CoInternetIsFeatureZoneElevationEnabled, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :ptr IInternetSecurityManager, :DWORD>, 16
      endif
      ;(_WIN32_IE >= _WIN32_IE_IE60SP2)
      @DefProto DllImport, CopyStgMedium, WIN_STD_CALL_CONV,, <:ptr STGMEDIUM, :ptr STGMEDIUM>, 8
      @DefProto DllImport, CopyBindInfo, WIN_STD_CALL_CONV,, <:ptr BINDINFO, :ptr BINDINFO>, 8
      @DefProto DllImport, ReleaseBindInfo, WIN_STD_CALL_CONV,, <:ptr BINDINFO>, 4
      INET_E_USE_DEFAULT_PROTOCOLHANDLER equ _HRESULT_TYPEDEF_(800C0011h)
      INET_E_USE_DEFAULT_SETTING equ _HRESULT_TYPEDEF_(800C0012h)
      INET_E_DEFAULT_ACTION equ <INET_E_USE_DEFAULT_PROTOCOLHANDLER>
      INET_E_QUERYOPTION_UNKNOWN equ _HRESULT_TYPEDEF_(800C0013h)
      INET_E_REDIRECTING equ _HRESULT_TYPEDEF_(800C0014h)
      OInetParseUrl equ <CoInternetParseUrl>
      OInetCombineUrl equ <CoInternetCombineUrl>
      if (_WIN32_IE ge _WIN32_IE_IE70)
        OInetCombineUrlEx equ <CoInternetCombineUrlEx>
        OInetCombineIUri equ <CoInternetCombineIUri>
      endif
      ;(_WIN32_IE >= _WIN32_IE_IE70)
      OInetCompareUrl equ <CoInternetCompareUrl>
      OInetQueryInfo equ <CoInternetQueryInfo>
      OInetGetSession equ <CoInternetGetSession>
    endif
    ; !_URLMON_NO_ASYNC_PLUGABLE_PROTOCOLS_ 
    ; Static Protocol flags
    PROTOCOLFLAG_NO_PICS_CHECK equ 00000001h
    ; Do not take a dependency on the exact value of the private namespace, no guarantee is given that it won't change.
    @DefProto DllImport, IEGetUserPrivateNamespaceName, WIN_STD_CALL_CONV,, <>, 0
    ; Creates the security manager object. The first argument is the Service provider
    ; to allow for delegation
    @DefProto DllImport, CoInternetCreateSecurityManager, WIN_STD_CALL_CONV,, <:ptr IServiceProvider, :ptr ptr IInternetSecurityManager, :DWORD>, 12
    @DefProto DllImport, CoInternetCreateZoneManager, WIN_STD_CALL_CONV,, <:ptr IServiceProvider, :ptr ptr IInternetZoneManager, :DWORD>, 12
    ; Security manager CLSID's
    externdef CLSID_InternetSecurityManager:IID
    externdef CLSID_InternetZoneManager:IID
    if (_WIN32_IE ge _WIN32_IE_IE60SP2)
      externdef CLSID_PersistentZoneIdentifier:IID
    endif
    ;(_WIN32_IE >= _WIN32_IE_IE60SP2)
    ; This service is used for delegation support on the Security Manager interface
    SID_SInternetSecurityManager equ <IID_IInternetSecurityManager>
    if (_WIN32_IE ge _WIN32_IE_IE60SP2)
      SID_SInternetSecurityManagerEx equ <IID_IInternetSecurityManagerEx>
    endif
    ;(_WIN32_IE >= _WIN32_IE_IE60SP2)
    if (_WIN32_IE ge _WIN32_IE_IE70)
      SID_SInternetSecurityManagerEx2 equ <IID_IInternetSecurityManagerEx2>
    endif
    ;(_WIN32_IE >= _WIN32_IE_IE70)
    SID_SInternetHostSecurityManager equ <IID_IInternetHostSecurityManager>
    ifndef _LPINTERNETSECURITYMGRSITE_DEFINED
      _LPINTERNETSECURITYMGRSITE_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0037_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0037_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IInternetSecurityMgrSite_INTERFACE_DEFINED__
        __IInternetSecurityMgrSite_INTERFACE_DEFINED__ equ <>
        ;* interface IInternetSecurityMgrSite *
        ;* [unique][helpstring][uuid][object][local] *
        externdef IID_IInternetSecurityMgrSite:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IInternetSecurityMgrSiteVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IInternetSecurityMgrSiteVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IInternetSecurityMgrSite, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IInternetSecurityMgrSite
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IInternetSecurityMgrSite
            DECLSPEC_XFGVIRT(IInternetSecurityMgrSite, GetWindow)
            STD_METHOD GetWindow, :ptr IInternetSecurityMgrSite, :ptr HWND
            ;* [out] *
            DECLSPEC_XFGVIRT(IInternetSecurityMgrSite, EnableModeless)
            STD_METHOD EnableModeless, :ptr IInternetSecurityMgrSite, :BOOL
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IInternetSecurityMgrSiteVtbl ends
          IInternetSecurityMgrSite struct
            lpVtbl POINTER ?
          IInternetSecurityMgrSite ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IInternetSecurityMgrSite_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0038 *
      ;* [local] *
    endif
    ifndef _LPINTERNETSECURITYMANANGER_DEFINED
      _LPINTERNETSECURITYMANANGER_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0038_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0038_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IInternetSecurityManager_INTERFACE_DEFINED__
        __IInternetSecurityManager_INTERFACE_DEFINED__ equ <>
        ;* interface IInternetSecurityManager *
        ;* [object][unique][helpstring][uuid] *
        MUTZ_NOSAVEDFILECHECK equ 00000001h; don't check file: for saved file comment

        MUTZ_ISFILE equ 00000002h; Assume URL if File, url does not need file://

        MUTZ_ACCEPT_WILDCARD_SCHEME equ 00000080h; Accept a wildcard scheme

        MUTZ_ENFORCERESTRICTED equ 00000100h; enforce restricted zone independent of URL

        MUTZ_RESERVED equ 00000200h; This is same as PUAF_NOSAVEDFILECHECK. However we already have MUTZ_NOSAVEDFILECHECK for this.

        MUTZ_REQUIRESAVEDFILECHECK equ 00000400h; always check the file for MOTW (overriding FEATURE_UNC_SAVEDFILECHECK)

        MUTZ_DONT_UNESCAPE equ 00000800h; Do not unescape the url

        MUTZ_DONT_USE_CACHE equ 00001000h; Do not check the cache

        MUTZ_FORCE_INTRANET_FLAGS equ 00002000h; Force the intranet flags to be active

        MUTZ_IGNORE_ZONE_MAPPINGS equ 00004000h; Don't look up the Zone Mappings

        ; MapUrlToZone returns the zone index given a URL
        MAX_SIZE_SECURITY_ID equ 512; bytes

        ;* [public] *
        PUAF typedef SDWORD
        PUAF_DEFAULT equ 0
        PUAF_NOUI equ 1h
        PUAF_ISFILE equ 2h
        PUAF_WARN_IF_DENIED equ 4h
        PUAF_FORCEUI_FOREGROUND equ 8h
        PUAF_CHECK_TIFS equ 10h
        PUAF_DONTCHECKBOXINDIALOG equ 20h
        PUAF_TRUSTED equ 40h
        PUAF_ACCEPT_WILDCARD_SCHEME equ 80h
        PUAF_ENFORCERESTRICTED equ 100h
        PUAF_NOSAVEDFILECHECK equ 200h
        PUAF_REQUIRESAVEDFILECHECK equ 400h
        PUAF_DONT_USE_CACHE equ 1000h
        PUAF_RESERVED1 equ 2000h
        PUAF_RESERVED2 equ 4000h
        PUAF_LMZ_UNLOCKED equ 10000h
        PUAF_LMZ_LOCKED equ 20000h
        PUAF_DEFAULTZONEPOL equ 40000h
        PUAF_NPL_USE_LOCKED_IF_RESTRICTED equ 80000h
        PUAF_NOUIIFLOCKED equ 100000h
        PUAF_DRAGPROTOCOLCHECK equ 200000h
        __MIDL_IInternetSecurityManager_0001 typedef PUAF

        ;* [public] *
        PUAFOUT typedef SDWORD
        PUAFOUT_DEFAULT equ 0
        PUAFOUT_ISLOCKZONEPOLICY equ 1h
        __MIDL_IInternetSecurityManager_0002 typedef PUAFOUT

        ; Note that for the below function, the semantics of the 'pwszUrl',
        ; 'pContext', and 'cbContext' parameters depend on the specific
        ; URLACTION_* enum value that is passed for 'dwAction'. For example,
        ; when 'dwAction' is URLACTION_HTML_MIXED_CONTENT, 'pwszUrl' will be
        ; the target URL of the resource, 'pContext' will be the containing
        ; document's IUri* cast to BYTE*, and 'cbContext' will be sizeof(Uri*).
        ; When 'dwAction' is URLACTION_CROSS_DOMAIN_DATA, 'pwszUrl' will be
        ; the source URL, 'pContext' will be the target PCWSTR cast to BYTE*,
        ; and 'cbContext' will be the size of the string including its null
        ; terminator. Implementers should use the value of 'dwAction' to
        ; correctly interpret the 'pswzUrl', 'pContext' and 'cbContext' for
        ; each action type.
        ; This is the wrapper function that most clients will use.
        ; It figures out the current Policy for the passed in Action,
        ; and puts up UI if the current Policy indicates that the user
        ; should be queried. It returns back the Policy which the caller
        ; will use to determine if the action should be allowed
        ; This is the wrapper function to conveniently read a custom policy.
        ;* [public] *
        SZM_FLAGS typedef SDWORD
        SZM_CREATE equ 0
        SZM_DELETE equ 1h
        __MIDL_IInternetSecurityManager_0003 typedef SZM_FLAGS

        ; SetZoneMapping
        ;    lpszPattern: string denoting a URL pattern
        ;        Examples of valid patterns:   
        ;            *://*.msn.com             
        ;            http://*.sony.co.jp       
        ;            *://et.msn.com            
        ;            ftp://157.54.23.41/       
        ;            https://localsvr          
        ;            file:\localsvr\share     
        ;            *://157.54.100-200.*      
        ;        Examples of invalid patterns: 
        ;            http://*.lcs.mit.edu      
        ;            ftp://*                   
        ;    dwFlags: SZM_FLAGS values         
        externdef IID_IInternetSecurityManager:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IInternetSecurityManagerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IInternetSecurityManagerVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IInternetSecurityManager, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IInternetSecurityManager
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IInternetSecurityManager
            DECLSPEC_XFGVIRT(IInternetSecurityManager, SetSecuritySite)
            STD_METHOD SetSecuritySite, :ptr IInternetSecurityManager, :ptr IInternetSecurityMgrSite
            ;* [unique][in] *
            DECLSPEC_XFGVIRT(IInternetSecurityManager, GetSecuritySite)
            STD_METHOD GetSecuritySite, :ptr IInternetSecurityManager, :ptr ptr IInternetSecurityMgrSite
            ;* [out] *
            DECLSPEC_XFGVIRT(IInternetSecurityManager, MapUrlToZone)
            ;* [in] *
            ;* [out] *
            STD_METHOD MapUrlToZone, :ptr IInternetSecurityManager, :LPCWSTR, :ptr DWORD, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IInternetSecurityManager, GetSecurityId)
            ;* [annotation][in] *
            ;* [annotation][size_is][out] *
            ;* [annotation][out][in] *
            ;* [annotation][in] *
            STD_METHOD GetSecurityId, :ptr IInternetSecurityManager, :LPCWSTR, :ptr BYTE, :ptr DWORD, :DWORD_PTR
            DECLSPEC_XFGVIRT(IInternetSecurityManager, ProcessUrlAction)
            ;* [in] *
            ;* [in] *
            ;* [size_is][out] *
            ;* [in] *
            ;* [unique][in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD ProcessUrlAction, :ptr IInternetSecurityManager, :LPCWSTR, :DWORD, :ptr BYTE, :DWORD, :ptr BYTE, :DWORD, :DWORD, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IInternetSecurityManager, QueryCustomPolicy)
            ;* [in] *
            ;* [in] *
            ;* [size_is][size_is][out] *
            ;* [out] *
            ;* [in] *
            ;* [in] *
            STD_METHOD QueryCustomPolicy, :ptr IInternetSecurityManager, :LPCWSTR, :REFGUID, :ptr ptr BYTE, :ptr DWORD, :ptr BYTE, :DWORD, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IInternetSecurityManager, SetZoneMapping)
            ;* [in] *
            ;* [in] *
            STD_METHOD SetZoneMapping, :ptr IInternetSecurityManager, :DWORD, :LPCWSTR, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IInternetSecurityManager, GetZoneMappings)
            ;* [in] *
            ;* [out] *
            STD_METHOD GetZoneMappings, :ptr IInternetSecurityManager, :DWORD, :ptr ptr IEnumString, :DWORD
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IInternetSecurityManagerVtbl ends
          IInternetSecurityManager struct
            lpVtbl POINTER ?
          IInternetSecurityManager ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IInternetSecurityManager_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0039 *
      ;* [local] *
    endif
    if (_WIN32_IE ge _WIN32_IE_IE60SP2)
      ifndef _LPINTERNETSECURITYMANANGEREX_DEFINED
        _LPINTERNETSECURITYMANANGEREX_DEFINED equ <>
        externdef __MIDL_itf_urlmon_0000_0039_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0039_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IInternetSecurityManagerEx_INTERFACE_DEFINED__
          __IInternetSecurityManagerEx_INTERFACE_DEFINED__ equ <>
          ;* interface IInternetSecurityManagerEx *
          ;* [object][unique][helpstring][uuid] *
          ; Please see notes on IInternetSecurityManager::ProcessUrlAction
          ; This is the wrapper function that most clients will use.
          ; It figures out the current Policy for the passed in Action,
          ; and puts up UI if the current Policy indicates that the user
          ; should be queried. It returns back the Policy which the caller
          ; will use to determine if the action should be allowed
          externdef IID_IInternetSecurityManagerEx:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IInternetSecurityManagerExVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetSecurityManagerExVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              ;* [in] *
              ;* [annotation][iid_is][out] *
              STD_METHOD QueryInterface, :ptr IInternetSecurityManagerEx, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IInternetSecurityManagerEx
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IInternetSecurityManagerEx
              DECLSPEC_XFGVIRT(IInternetSecurityManager, SetSecuritySite)
              STD_METHOD SetSecuritySite, :ptr IInternetSecurityManagerEx, :ptr IInternetSecurityMgrSite
              ;* [unique][in] *
              DECLSPEC_XFGVIRT(IInternetSecurityManager, GetSecuritySite)
              STD_METHOD GetSecuritySite, :ptr IInternetSecurityManagerEx, :ptr ptr IInternetSecurityMgrSite
              ;* [out] *
              DECLSPEC_XFGVIRT(IInternetSecurityManager, MapUrlToZone)
              ;* [in] *
              ;* [out] *
              STD_METHOD MapUrlToZone, :ptr IInternetSecurityManagerEx, :LPCWSTR, :ptr DWORD, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetSecurityManager, GetSecurityId)
              ;* [annotation][in] *
              ;* [annotation][size_is][out] *
              ;* [annotation][out][in] *
              ;* [annotation][in] *
              STD_METHOD GetSecurityId, :ptr IInternetSecurityManagerEx, :LPCWSTR, :ptr BYTE, :ptr DWORD, :DWORD_PTR
              DECLSPEC_XFGVIRT(IInternetSecurityManager, ProcessUrlAction)
              ;* [in] *
              ;* [in] *
              ;* [size_is][out] *
              ;* [in] *
              ;* [unique][in] *
              ;* [in] *
              ;* [in] *
              STD_METHOD ProcessUrlAction, :ptr IInternetSecurityManagerEx, :LPCWSTR, :DWORD, :ptr BYTE, :DWORD, :ptr BYTE, :DWORD, :DWORD, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetSecurityManager, QueryCustomPolicy)
              ;* [in] *
              ;* [in] *
              ;* [size_is][size_is][out] *
              ;* [out] *
              ;* [in] *
              ;* [in] *
              STD_METHOD QueryCustomPolicy, :ptr IInternetSecurityManagerEx, :LPCWSTR, :REFGUID, :ptr ptr BYTE, :ptr DWORD, :ptr BYTE, :DWORD, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetSecurityManager, SetZoneMapping)
              ;* [in] *
              ;* [in] *
              STD_METHOD SetZoneMapping, :ptr IInternetSecurityManagerEx, :DWORD, :LPCWSTR, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetSecurityManager, GetZoneMappings)
              ;* [in] *
              ;* [out] *
              STD_METHOD GetZoneMappings, :ptr IInternetSecurityManagerEx, :DWORD, :ptr ptr IEnumString, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetSecurityManagerEx, ProcessUrlActionEx)
              ;* [in] *
              ;* [in] *
              ;* [size_is][out] *
              ;* [in] *
              ;* [in] *
              ;* [in] *
              ;* [in] *
              ;* [in] *
              STD_METHOD ProcessUrlActionEx, :ptr IInternetSecurityManagerEx, :LPCWSTR, :DWORD, :ptr BYTE, :DWORD, :ptr BYTE, :DWORD, :DWORD, :DWORD, :ptr DWORD
              ;* [out] *
              ??Interface equ <>
              END_INTERFACE
            IInternetSecurityManagerExVtbl ends
            IInternetSecurityManagerEx struct
              lpVtbl POINTER ?
            IInternetSecurityManagerEx ends
            ifdef COBJMACROS
              ;[...]
            endif
            ;* C style interface *
          endif
          ;* __IInternetSecurityManagerEx_INTERFACE_DEFINED__ *
        endif
        ;* interface __MIDL_itf_urlmon_0000_0040 *
        ;* [local] *
      endif
    endif
    ;(_WIN32_IE >= _WIN32_IE_IE60SP2)
    if (_WIN32_IE ge _WIN32_IE_IE70)
      ifndef _LPINTERNETSECURITYMANANGEREx2_DEFINED
        _LPINTERNETSECURITYMANANGEREx2_DEFINED equ <>
        externdef __MIDL_itf_urlmon_0000_0040_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0040_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IInternetSecurityManagerEx2_INTERFACE_DEFINED__
          __IInternetSecurityManagerEx2_INTERFACE_DEFINED__ equ <>
          ;* interface IInternetSecurityManagerEx2 *
          ;* [object][unique][helpstring][uuid] *
          ; Please see notes on IInternetSecurityManager::ProcessUrlAction
          externdef IID_IInternetSecurityManagerEx2:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IInternetSecurityManagerEx2Vtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetSecurityManagerEx2Vtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              ;* [in] *
              ;* [annotation][iid_is][out] *
              STD_METHOD QueryInterface, :ptr IInternetSecurityManagerEx2, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IInternetSecurityManagerEx2
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IInternetSecurityManagerEx2
              DECLSPEC_XFGVIRT(IInternetSecurityManager, SetSecuritySite)
              STD_METHOD SetSecuritySite, :ptr IInternetSecurityManagerEx2, :ptr IInternetSecurityMgrSite
              ;* [unique][in] *
              DECLSPEC_XFGVIRT(IInternetSecurityManager, GetSecuritySite)
              STD_METHOD GetSecuritySite, :ptr IInternetSecurityManagerEx2, :ptr ptr IInternetSecurityMgrSite
              ;* [out] *
              DECLSPEC_XFGVIRT(IInternetSecurityManager, MapUrlToZone)
              ;* [in] *
              ;* [out] *
              STD_METHOD MapUrlToZone, :ptr IInternetSecurityManagerEx2, :LPCWSTR, :ptr DWORD, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetSecurityManager, GetSecurityId)
              ;* [annotation][in] *
              ;* [annotation][size_is][out] *
              ;* [annotation][out][in] *
              ;* [annotation][in] *
              STD_METHOD GetSecurityId, :ptr IInternetSecurityManagerEx2, :LPCWSTR, :ptr BYTE, :ptr DWORD, :DWORD_PTR
              DECLSPEC_XFGVIRT(IInternetSecurityManager, ProcessUrlAction)
              ;* [in] *
              ;* [in] *
              ;* [size_is][out] *
              ;* [in] *
              ;* [unique][in] *
              ;* [in] *
              ;* [in] *
              STD_METHOD ProcessUrlAction, :ptr IInternetSecurityManagerEx2, :LPCWSTR, :DWORD, :ptr BYTE, :DWORD, :ptr BYTE, :DWORD, :DWORD, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetSecurityManager, QueryCustomPolicy)
              ;* [in] *
              ;* [in] *
              ;* [size_is][size_is][out] *
              ;* [out] *
              ;* [in] *
              ;* [in] *
              STD_METHOD QueryCustomPolicy, :ptr IInternetSecurityManagerEx2, :LPCWSTR, :REFGUID, :ptr ptr BYTE, :ptr DWORD, :ptr BYTE, :DWORD, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetSecurityManager, SetZoneMapping)
              ;* [in] *
              ;* [in] *
              STD_METHOD SetZoneMapping, :ptr IInternetSecurityManagerEx2, :DWORD, :LPCWSTR, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetSecurityManager, GetZoneMappings)
              ;* [in] *
              ;* [out] *
              STD_METHOD GetZoneMappings, :ptr IInternetSecurityManagerEx2, :DWORD, :ptr ptr IEnumString, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetSecurityManagerEx, ProcessUrlActionEx)
              ;* [in] *
              ;* [in] *
              ;* [size_is][out] *
              ;* [in] *
              ;* [in] *
              ;* [in] *
              ;* [in] *
              ;* [in] *
              STD_METHOD ProcessUrlActionEx, :ptr IInternetSecurityManagerEx2, :LPCWSTR, :DWORD, :ptr BYTE, :DWORD, :ptr BYTE, :DWORD, :DWORD, :DWORD, :ptr DWORD
              ;* [out] *
              DECLSPEC_XFGVIRT(IInternetSecurityManagerEx2, MapUrlToZoneEx2)
              ;* [annotation][in] *
              ;* [out] *
              ;* [in] *
              ;* [annotation][out] *
              ;* [annotation][out] *
              STD_METHOD MapUrlToZoneEx2, :ptr IInternetSecurityManagerEx2, :ptr IUri, :ptr DWORD, :DWORD, :ptr LPWSTR, :ptr DWORD
              DECLSPEC_XFGVIRT(IInternetSecurityManagerEx2, ProcessUrlActionEx2)
              ;* [annotation][in] *
              ;* [in] *
              ;* [size_is][out] *
              ;* [in] *
              ;* [unique][in] *
              ;* [in] *
              ;* [in] *
              ;* [in] *
              STD_METHOD ProcessUrlActionEx2, :ptr IInternetSecurityManagerEx2, :ptr IUri, :DWORD, :ptr BYTE, :DWORD, :ptr BYTE, :DWORD, :DWORD, :DWORD_PTR, :ptr DWORD
              ;* [out] *
              DECLSPEC_XFGVIRT(IInternetSecurityManagerEx2, GetSecurityIdEx2)
              ;* [annotation][in] *
              ;* [annotation][size_is][out] *
              ;* [annotation][out][in] *
              ;* [annotation][in] *
              STD_METHOD GetSecurityIdEx2, :ptr IInternetSecurityManagerEx2, :ptr IUri, :ptr BYTE, :ptr DWORD, :DWORD_PTR
              DECLSPEC_XFGVIRT(IInternetSecurityManagerEx2, QueryCustomPolicyEx2)
              ;* [annotation][in] *
              ;* [in] *
              ;* [size_is][size_is][out] *
              ;* [out] *
              ;* [in] *
              ;* [in] *
              STD_METHOD QueryCustomPolicyEx2, :ptr IInternetSecurityManagerEx2, :ptr IUri, :REFGUID, :ptr ptr BYTE, :ptr DWORD, :ptr BYTE, :DWORD, :DWORD_PTR
              ;* [in] *
              ??Interface equ <>
              END_INTERFACE
            IInternetSecurityManagerEx2Vtbl ends
            IInternetSecurityManagerEx2 struct
              lpVtbl POINTER ?
            IInternetSecurityManagerEx2 ends
            ifdef COBJMACROS
              ;[...]
            endif
            ;* C style interface *
          endif
          ;* __IInternetSecurityManagerEx2_INTERFACE_DEFINED__ *
        endif
        ;* interface __MIDL_itf_urlmon_0000_0041 *
        ;* [local] *
      endif
    endif
    ;(_WIN32_IE >= _WIN32_IE_IE70)
    if (_WIN32_IE ge _WIN32_IE_IE60SP2)
      externdef __MIDL_itf_urlmon_0000_0041_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0041_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IZoneIdentifier_INTERFACE_DEFINED__
        __IZoneIdentifier_INTERFACE_DEFINED__ equ <>
        ;* interface IZoneIdentifier *
        ;* [unique][uuid][object] *
        externdef IID_IZoneIdentifier:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IZoneIdentifierVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IZoneIdentifierVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IZoneIdentifier, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IZoneIdentifier
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IZoneIdentifier
            DECLSPEC_XFGVIRT(IZoneIdentifier, GetId)
            STD_METHOD GetId, :ptr IZoneIdentifier, :ptr DWORD
            ;* [out] *
            DECLSPEC_XFGVIRT(IZoneIdentifier, SetId)
            STD_METHOD SetId, :ptr IZoneIdentifier, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IZoneIdentifier, Remove)
            STD_METHOD Remove, :ptr IZoneIdentifier
            ??Interface equ <>
            END_INTERFACE
          IZoneIdentifierVtbl ends
          IZoneIdentifier struct
            lpVtbl POINTER ?
          IZoneIdentifier ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IZoneIdentifier_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0042 *
      ;* [local] *
    endif
    ;(_WIN32_IE >= _WIN32_IE_IE60SP2)
    if (_WIN32_IE ge _WIN32_IE_WIN10)
      externdef __MIDL_itf_urlmon_0000_0042_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0042_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IZoneIdentifier2_INTERFACE_DEFINED__
        __IZoneIdentifier2_INTERFACE_DEFINED__ equ <>
        ;* interface IZoneIdentifier2 *
        ;* [unique][uuid][object] *
        externdef IID_IZoneIdentifier2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IZoneIdentifier2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IZoneIdentifier2Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IZoneIdentifier2, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IZoneIdentifier2
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IZoneIdentifier2
            DECLSPEC_XFGVIRT(IZoneIdentifier, GetId)
            STD_METHOD GetId, :ptr IZoneIdentifier2, :ptr DWORD
            ;* [out] *
            DECLSPEC_XFGVIRT(IZoneIdentifier, SetId)
            STD_METHOD SetId, :ptr IZoneIdentifier2, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IZoneIdentifier, Remove)
            STD_METHOD Remove, :ptr IZoneIdentifier2
            DECLSPEC_XFGVIRT(IZoneIdentifier2, GetLastWriterPackageFamilyName)
            STD_METHOD GetLastWriterPackageFamilyName, :ptr IZoneIdentifier2, :ptr LPWSTR
            ;* [out] *
            DECLSPEC_XFGVIRT(IZoneIdentifier2, SetLastWriterPackageFamilyName)
            STD_METHOD SetLastWriterPackageFamilyName, :ptr IZoneIdentifier2, :LPCWSTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IZoneIdentifier2, RemoveLastWriterPackageFamilyName)
            STD_METHOD RemoveLastWriterPackageFamilyName, :ptr IZoneIdentifier2
            DECLSPEC_XFGVIRT(IZoneIdentifier2, GetAppZoneId)
            STD_METHOD GetAppZoneId, :ptr IZoneIdentifier2, :ptr DWORD
            ;* [out] *
            DECLSPEC_XFGVIRT(IZoneIdentifier2, SetAppZoneId)
            STD_METHOD SetAppZoneId, :ptr IZoneIdentifier2, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IZoneIdentifier2, RemoveAppZoneId)
            STD_METHOD RemoveAppZoneId, :ptr IZoneIdentifier2
            ??Interface equ <>
            END_INTERFACE
          IZoneIdentifier2Vtbl ends
          IZoneIdentifier2 struct
            lpVtbl POINTER ?
          IZoneIdentifier2 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IZoneIdentifier2_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0043 *
      ;* [local] *
    endif
    ;(_WIN32_IE >= _WIN32_IE_WIN10
    ifndef _LPINTERNETHOSTSECURITYMANANGER_DEFINED
      _LPINTERNETHOSTSECURITYMANANGER_DEFINED equ <>
      ;This is the interface MSHTML exposes to its clients
      ;The clients need not pass in a URL to these functions
      ;since MSHTML maintains the notion of the current URL
      externdef __MIDL_itf_urlmon_0000_0043_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0043_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IInternetHostSecurityManager_INTERFACE_DEFINED__
        __IInternetHostSecurityManager_INTERFACE_DEFINED__ equ <>
        ;* interface IInternetHostSecurityManager *
        ;* [unique][helpstring][uuid][object][local] *
        ; Please see notes on IInternetSecurityManager::ProcessUrlAction
        externdef IID_IInternetHostSecurityManager:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IInternetHostSecurityManagerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IInternetHostSecurityManagerVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IInternetHostSecurityManager, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IInternetHostSecurityManager
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IInternetHostSecurityManager
            DECLSPEC_XFGVIRT(IInternetHostSecurityManager, GetSecurityId)
            ;* [annotation][size_is][out] *
            ;* [annotation][out][in] *
            STD_METHOD GetSecurityId, :ptr IInternetHostSecurityManager, :ptr BYTE, :ptr DWORD, :DWORD_PTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IInternetHostSecurityManager, ProcessUrlAction)
            ;* [in] *
            ;* [annotation][size_is][out] *
            ;* [in] *
            ;* [annotation][in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD ProcessUrlAction, :ptr IInternetHostSecurityManager, :DWORD, :ptr BYTE, :DWORD, :ptr BYTE, :DWORD, :DWORD, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IInternetHostSecurityManager, QueryCustomPolicy)
            ;* [in] *
            ;* [annotation][size_is][size_is][out] *
            ;* [annotation][out] *
            ;* [annotation][in] *
            ;* [in] *
            STD_METHOD QueryCustomPolicy, :ptr IInternetHostSecurityManager, :REFGUID, :ptr ptr BYTE, :ptr DWORD, :ptr BYTE, :DWORD, :DWORD
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IInternetHostSecurityManagerVtbl ends
          IInternetHostSecurityManager struct
            lpVtbl POINTER ?
          IInternetHostSecurityManager ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IInternetHostSecurityManager_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0044 *
      ;* [local] *
    endif
    ; The zone manager maintains policies for a set of standard actions. 
    ; These actions are identified by integral values (called action indexes)
    ; specified below.
    ; Minimum legal value for an action    
    URLACTION_MIN equ 00001000h
    URLACTION_DOWNLOAD_MIN equ 00001000h
    URLACTION_DOWNLOAD_SIGNED_ACTIVEX equ 00001001h
    URLACTION_DOWNLOAD_UNSIGNED_ACTIVEX equ 00001004h
    URLACTION_DOWNLOAD_CURR_MAX equ 00001004h
    URLACTION_DOWNLOAD_MAX equ 000011FFh
    URLACTION_ACTIVEX_MIN equ 00001200h
    URLACTION_ACTIVEX_RUN equ 00001200h
    URLPOLICY_ACTIVEX_CHECK_LIST equ 00010000h
    URLACTION_ACTIVEX_OVERRIDE_OBJECT_SAFETY equ 00001201h; aggregate next four

    URLACTION_ACTIVEX_OVERRIDE_DATA_SAFETY equ 00001202h
    URLACTION_ACTIVEX_OVERRIDE_SCRIPT_SAFETY equ 00001203h
    URLACTION_SCRIPT_OVERRIDE_SAFETY equ 00001401h
    URLACTION_ACTIVEX_CONFIRM_NOOBJECTSAFETY equ 00001204h
    URLACTION_ACTIVEX_TREATASUNTRUSTED equ 00001205h
    URLACTION_ACTIVEX_NO_WEBOC_SCRIPT equ 00001206h
    URLACTION_ACTIVEX_OVERRIDE_REPURPOSEDETECTION equ 00001207h
    URLACTION_ACTIVEX_OVERRIDE_OPTIN equ 00001208h
    URLACTION_ACTIVEX_SCRIPTLET_RUN equ 00001209h
    URLACTION_ACTIVEX_DYNSRC_VIDEO_AND_ANIMATION equ 0000120Ah
    URLACTION_ACTIVEX_OVERRIDE_DOMAINLIST equ 0000120Bh
    URLACTION_ACTIVEX_ALLOW_TDC equ 0000120Ch
    URLACTION_ACTIVEX_CURR_MAX equ 0000120Ch
    URLACTION_ACTIVEX_MAX equ 000013ffh
    URLACTION_SCRIPT_MIN equ 00001400h
    URLACTION_SCRIPT_RUN equ 00001400h
    URLACTION_SCRIPT_JAVA_USE equ 00001402h
    URLACTION_SCRIPT_SAFE_ACTIVEX equ 00001405h
    URLACTION_CROSS_DOMAIN_DATA equ 00001406h
    URLACTION_SCRIPT_PASTE equ 00001407h
    URLACTION_ALLOW_XDOMAIN_SUBFRAME_RESIZE equ 00001408h
    URLACTION_SCRIPT_XSSFILTER equ 00001409h
    URLACTION_SCRIPT_NAVIGATE equ 0000140Ah
    URLACTION_PLUGGABLE_PROTOCOL_XHR equ 0000140Bh
    URLACTION_ALLOW_VBSCRIPT_IE equ 0000140Ch
    URLACTION_ALLOW_JSCRIPT_IE equ 0000140Dh
    URLACTION_SCRIPT_CURR_MAX equ 0000140Dh
    URLACTION_SCRIPT_MAX equ 000015ffh
    URLACTION_HTML_MIN equ 00001600h
    URLACTION_HTML_SUBMIT_FORMS equ 00001601h; aggregate next two

    URLACTION_HTML_SUBMIT_FORMS_FROM equ 00001602h
    URLACTION_HTML_SUBMIT_FORMS_TO equ 00001603h
    URLACTION_HTML_FONT_DOWNLOAD equ 00001604h
    URLACTION_HTML_JAVA_RUN equ 00001605h; derive from Java custom policy

    URLACTION_HTML_USERDATA_SAVE equ 00001606h
    URLACTION_HTML_SUBFRAME_NAVIGATE equ 00001607h
    URLACTION_HTML_META_REFRESH equ 00001608h
    URLACTION_HTML_MIXED_CONTENT equ 00001609h
    URLACTION_HTML_INCLUDE_FILE_PATH equ 0000160Ah
    URLACTION_HTML_ALLOW_INJECTED_DYNAMIC_HTML equ 0000160Bh
    URLACTION_HTML_REQUIRE_UTF8_DOCUMENT_CODEPAGE equ 0000160Ch
    URLACTION_HTML_ALLOW_CROSS_DOMAIN_CANVAS equ 0000160Dh
    URLACTION_HTML_ALLOW_WINDOW_CLOSE equ 0000160Eh
    URLACTION_HTML_ALLOW_CROSS_DOMAIN_WEBWORKER equ 0000160Fh
    URLACTION_HTML_ALLOW_CROSS_DOMAIN_TEXTTRACK equ 00001610h
    URLACTION_HTML_ALLOW_INDEXEDDB equ 00001611h
    URLACTION_HTML_MAX equ 000017ffh
    URLACTION_SHELL_MIN equ 00001800h
    URLACTION_SHELL_INSTALL_DTITEMS equ 00001800h
    URLACTION_SHELL_MOVE_OR_COPY equ 00001802h
    URLACTION_SHELL_FILE_DOWNLOAD equ 00001803h
    URLACTION_SHELL_VERB equ 00001804h
    URLACTION_SHELL_WEBVIEW_VERB equ 00001805h
    URLACTION_SHELL_SHELLEXECUTE equ 00001806h
    if (_WIN32_IE ge _WIN32_IE_IE60SP2)
      URLACTION_SHELL_EXECUTE_HIGHRISK equ 00001806h
      URLACTION_SHELL_EXECUTE_MODRISK equ 00001807h
      URLACTION_SHELL_EXECUTE_LOWRISK equ 00001808h
      URLACTION_SHELL_POPUPMGR equ 00001809h
      URLACTION_SHELL_RTF_OBJECTS_LOAD equ 0000180Ah
      URLACTION_SHELL_ENHANCED_DRAGDROP_SECURITY equ 0000180Bh
      URLACTION_SHELL_EXTENSIONSECURITY equ 0000180Ch
      URLACTION_SHELL_SECURE_DRAGSOURCE equ 0000180Dh
    endif
    ;(_WIN32_IE >= _WIN32_IE_IE60SP2)
    if (_WIN32_IE ge _WIN32_IE_WIN7)
      URLACTION_SHELL_REMOTEQUERY equ 0000180Eh
      URLACTION_SHELL_PREVIEW equ 0000180Fh
      URLACTION_SHELL_SHARE equ 00001810h
      URLACTION_SHELL_ALLOW_CROSS_SITE_SHARE equ 00001811h
    endif
    ;(_WIN32_IE >= _WIN32_IE_WIN7)
    URLACTION_SHELL_TOCTOU_RISK equ 00001812h
    URLACTION_SHELL_CURR_MAX equ 00001812h
    URLACTION_SHELL_MAX equ 000019ffh
    URLACTION_NETWORK_MIN equ 00001A00h
    URLACTION_CREDENTIALS_USE equ 00001A00h
    URLPOLICY_CREDENTIALS_SILENT_LOGON_OK equ 00000000h
    URLPOLICY_CREDENTIALS_MUST_PROMPT_USER equ 00010000h
    URLPOLICY_CREDENTIALS_CONDITIONAL_PROMPT equ 00020000h
    URLPOLICY_CREDENTIALS_ANONYMOUS_ONLY equ 00030000h
    URLACTION_AUTHENTICATE_CLIENT equ 00001A01h
    URLPOLICY_AUTHENTICATE_CLEARTEXT_OK equ 00000000h
    URLPOLICY_AUTHENTICATE_CHALLENGE_RESPONSE equ 00010000h
    URLPOLICY_AUTHENTICATE_MUTUAL_ONLY equ 00030000h
    URLACTION_COOKIES equ 00001A02h
    URLACTION_COOKIES_SESSION equ 00001A03h
    URLACTION_CLIENT_CERT_PROMPT equ 00001A04h
    URLACTION_COOKIES_THIRD_PARTY equ 00001A05h
    URLACTION_COOKIES_SESSION_THIRD_PARTY equ 00001A06h
    URLACTION_COOKIES_ENABLED equ 00001A10h
    URLACTION_NETWORK_CURR_MAX equ 00001A10h
    URLACTION_NETWORK_MAX equ 00001Bffh
    URLACTION_JAVA_MIN equ 00001C00h
    URLACTION_JAVA_PERMISSIONS equ 00001C00h
    URLPOLICY_JAVA_PROHIBIT equ 00000000h
    URLPOLICY_JAVA_HIGH equ 00010000h
    URLPOLICY_JAVA_MEDIUM equ 00020000h
    URLPOLICY_JAVA_LOW equ 00030000h
    URLPOLICY_JAVA_CUSTOM equ 00800000h
    URLACTION_JAVA_CURR_MAX equ 00001C00h
    URLACTION_JAVA_MAX equ 00001Cffh
    ; The following Infodelivery actions should have no default policies
    ; in the registry.  They assume that no default policy means fall
    ; back to the global restriction.  If an admin sets a policy per
    ; zone, then it overrides the global restriction.
    URLACTION_INFODELIVERY_MIN equ 00001D00h
    URLACTION_INFODELIVERY_NO_ADDING_CHANNELS equ 00001D00h
    URLACTION_INFODELIVERY_NO_EDITING_CHANNELS equ 00001D01h
    URLACTION_INFODELIVERY_NO_REMOVING_CHANNELS equ 00001D02h
    URLACTION_INFODELIVERY_NO_ADDING_SUBSCRIPTIONS equ 00001D03h
    URLACTION_INFODELIVERY_NO_EDITING_SUBSCRIPTIONS equ 00001D04h
    URLACTION_INFODELIVERY_NO_REMOVING_SUBSCRIPTIONS equ 00001D05h
    URLACTION_INFODELIVERY_NO_CHANNEL_LOGGING equ 00001D06h
    URLACTION_INFODELIVERY_CURR_MAX equ 00001D06h
    URLACTION_INFODELIVERY_MAX equ 00001Dffh
    URLACTION_CHANNEL_SOFTDIST_MIN equ 00001E00h
    URLACTION_CHANNEL_SOFTDIST_PERMISSIONS equ 00001E05h
    URLPOLICY_CHANNEL_SOFTDIST_PROHIBIT equ 00010000h
    URLPOLICY_CHANNEL_SOFTDIST_PRECACHE equ 00020000h
    URLPOLICY_CHANNEL_SOFTDIST_AUTOINSTALL equ 00030000h
    URLACTION_CHANNEL_SOFTDIST_MAX equ 00001Effh
    if (_WIN32_IE ge _WIN32_IE_IE80)
      URLACTION_DOTNET_USERCONTROLS equ 00002005h
    endif
    ;(_WIN32_IE >= _WIN32_IE_IE80)
    if (_WIN32_IE ge _WIN32_IE_IE60SP2)
      URLACTION_BEHAVIOR_MIN equ 00002000h
      URLACTION_BEHAVIOR_RUN equ 00002000h
      URLPOLICY_BEHAVIOR_CHECK_LIST equ 00010000h
      ; The following actions correspond to the Feature options above.
      ; However, they are NOT in the same order.
      URLACTION_FEATURE_MIN equ 00002100h
      URLACTION_FEATURE_MIME_SNIFFING equ 00002100h
      URLACTION_FEATURE_ZONE_ELEVATION equ 00002101h
      URLACTION_FEATURE_WINDOW_RESTRICTIONS equ 00002102h
      URLACTION_FEATURE_SCRIPT_STATUS_BAR equ 00002103h
      URLACTION_FEATURE_FORCE_ADDR_AND_STATUS equ 00002104h
      URLACTION_FEATURE_BLOCK_INPUT_PROMPTS equ 00002105h
      URLACTION_FEATURE_DATA_BINDING equ 00002106h
      URLACTION_FEATURE_CROSSDOMAIN_FOCUS_CHANGE equ 00002107h
      URLACTION_AUTOMATIC_DOWNLOAD_UI_MIN equ 00002200h
      URLACTION_AUTOMATIC_DOWNLOAD_UI equ 00002200h
      URLACTION_AUTOMATIC_ACTIVEX_UI equ 00002201h
      URLACTION_ALLOW_RESTRICTEDPROTOCOLS equ 00002300h
    endif
    ;(_WIN32_IE >= _WIN32_IE_IE60SP2)
    if (_WIN32_IE ge _WIN32_IE_IE70)
      ; Whether to do the Anti-Phishing check.
      URLACTION_ALLOW_APEVALUATION equ 00002301h
      URLACTION_ALLOW_XHR_EVALUATION equ 00002302h
      ; The following ExpressAPP and XPS actions are trumped by registry in
      ; case of Internet Explorer upgrade from IE 6.0 which honors registry.
      URLACTION_WINDOWS_BROWSER_APPLICATIONS equ 00002400h
      URLACTION_XPS_DOCUMENTS equ 00002401h
      URLACTION_LOOSE_XAML equ 00002402h
      URLACTION_LOWRIGHTS equ 00002500h
      ; The following action belong to WinFX Bootstrapper
      URLACTION_WINFX_SETUP equ 00002600h
      URLACTION_INPRIVATE_BLOCKING equ 00002700h
    endif
    ;(_WIN32_IE >= _WIN32_IE_IE70)
    URLACTION_ALLOW_AUDIO_VIDEO equ 00002701h
    URLACTION_ALLOW_ACTIVEX_FILTERING equ 00002702h
    URLACTION_ALLOW_STRUCTURED_STORAGE_SNIFFING equ 00002703h
    URLACTION_ALLOW_AUDIO_VIDEO_PLUGINS equ 00002704h
    ; The following two URLACTIONs each have as their context parameter a string that is the destination URI.
    URLACTION_ALLOW_ZONE_ELEVATION_VIA_OPT_OUT equ 00002705h
    URLACTION_ALLOW_ZONE_ELEVATION_OPT_OUT_ADDITION equ 00002706h
    URLACTION_ALLOW_CROSSDOMAIN_DROP_WITHIN_WINDOW equ 00002708h
    URLACTION_ALLOW_CROSSDOMAIN_DROP_ACROSS_WINDOWS equ 00002709h
    URLACTION_ALLOW_CROSSDOMAIN_APPCACHE_MANIFEST equ 0000270Ah
    URLACTION_ALLOW_RENDER_LEGACY_DXTFILTERS equ 0000270Bh
    URLACTION_ALLOW_ANTIMALWARE_SCANNING_OF_ACTIVEX equ 0000270Ch
    URLACTION_ALLOW_CSS_EXPRESSIONS equ 0000270Dh
    ; For each action specified above the system maintains
    ; a set of policies for the action. 
    ; The only policies supported currently are permissions (i.e. is something allowed)
    ; and logging status. 
    ; IMPORTANT: If you are defining your own policies don't overload the meaning of the
    ; loword of the policy. You can use the hiword to store any policy bits which are only
    ; meaningful to your action.
    ; For an example of how to do this look at the URLPOLICY_JAVA above
    ; Permissions 
    URLPOLICY_ALLOW equ 00h
    URLPOLICY_QUERY equ 01h
    URLPOLICY_DISALLOW equ 03h
    ; Notifications are not done when user already queried.
    URLPOLICY_NOTIFY_ON_ALLOW equ 10h
    URLPOLICY_NOTIFY_ON_DISALLOW equ 20h
    ; Logging is done regardless of whether user was queried.
    URLPOLICY_LOG_ON_ALLOW equ 40h
    URLPOLICY_LOG_ON_DISALLOW equ 80h
    URLPOLICY_MASK_PERMISSIONS equ 0fh
    GetUrlPolicyPermissions macro dw_
      exitm <(dw_ and URLPOLICY_MASK_PERMISSIONS)>
    endm
    SetUrlPolicyPermissions macro dw_, dw2
      exitm <((dw_) = ((dw_) and not (URLPOLICY_MASK_PERMISSIONS)) or (dw2))>
    endm
    URLPOLICY_DONTCHECKDLGBOX equ 100h
    ; The ordinal #'s that define the predefined zones internet explorer knows about. 
    ; When we support user-defined zones their zone numbers should be between 
    ; URLZONE_USER_MIN and URLZONE_USER_MAX
    if (_WIN32_IE ge _WIN32_IE_IE60SP2)
      ; Custom policy to query whether the local machine zone
      ; has been unlocked for current document.
      externdef GUID_CUSTOM_LOCALMACHINEZONEUNLOCKED:GUID
    endif
    ;(_WIN32_IE >= _WIN32_IE_IE60SP2)
    ifndef _LPINTERNETZONEMANAGER_DEFINED
      _LPINTERNETZONEMANAGER_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0044_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0044_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IInternetZoneManager_INTERFACE_DEFINED__
        __IInternetZoneManager_INTERFACE_DEFINED__ equ <>
        ;* interface IInternetZoneManager *
        ;* [unique][helpstring][uuid][object][local] *
        ;* [unique] *
        LPURLZONEMANAGER typedef ptr IInternetZoneManager
        URLZONE typedef SDWORD
        URLZONE_INVALID equ -1
        URLZONE_PREDEFINED_MIN equ 0
        URLZONE_LOCAL_MACHINE equ 0
        URLZONE_INTRANET equ
        URLZONE_TRUSTED equ
        URLZONE_INTERNET equ
        URLZONE_UNTRUSTED equ
        URLZONE_PREDEFINED_MAX equ 999
        URLZONE_USER_MIN equ 1000
        URLZONE_USER_MAX equ 10000
        tagURLZONE typedef URLZONE

        ; Enhanced Security Configuration zone mapping flag for IInternetSecurityManager::SetZoneMapping
        URLZONE_ESC_FLAG equ 100h
        URLTEMPLATE typedef SDWORD
        URLTEMPLATE_CUSTOM equ 0
        URLTEMPLATE_PREDEFINED_MIN equ 10000h
        URLTEMPLATE_LOW equ 10000h
        URLTEMPLATE_MEDLOW equ 10500h
        URLTEMPLATE_MEDIUM equ 11000h
        URLTEMPLATE_MEDHIGH equ 11500h
        URLTEMPLATE_HIGH equ 12000h
        URLTEMPLATE_PREDEFINED_MAX equ 20000h
        tagURLTEMPLATE typedef URLTEMPLATE

        __MIDL_IInternetZoneManager_0001 typedef SDWORD
        MAX_ZONE_PATH equ 260
        MAX_ZONE_DESCRIPTION equ 200

        ;* [public] *
        ZAFLAGS typedef SDWORD
        ZAFLAGS_CUSTOM_EDIT equ 1h
        ZAFLAGS_ADD_SITES equ 2h
        ZAFLAGS_REQUIRE_VERIFICATION equ 4h
        ZAFLAGS_INCLUDE_PROXY_OVERRIDE equ 8h
        ZAFLAGS_INCLUDE_INTRANET_SITES equ 10h
        ZAFLAGS_NO_UI equ 20h
        ZAFLAGS_SUPPORTS_VERIFICATION equ 40h
        ZAFLAGS_UNC_AS_INTRANET equ 80h
        ZAFLAGS_DETECT_INTRANET equ 100h
        ZAFLAGS_USE_LOCKED_ZONES equ 10000h
        ZAFLAGS_VERIFY_TEMPLATE_SETTINGS equ 20000h
        ZAFLAGS_NO_CACHE equ 40000h
        __MIDL_IInternetZoneManager_0002 typedef ZAFLAGS

        ZONEATTRIBUTES struct
          cbSize DWORD ?
          szDisplayName WORD 260 dup (?)
          szDescription WORD 200 dup (?)
          szIconPath WORD 260 dup (?)
          dwTemplateMinLevel DWORD ?
          dwTemplateRecommended DWORD ?
          dwTemplateCurrentLevel DWORD ?
          dwFlags DWORD ?
        ZONEATTRIBUTES ends
        _ZONEATTRIBUTES typedef ZONEATTRIBUTES
        LPZONEATTRIBUTES typedef ptr _ZONEATTRIBUTES
        ; Gets the zone attributes (information in registry other than actual security
        ; policies associated with the zone).  Zone attributes are fixed as:
        ; Sets the zone attributes (information in registry other than actual security
        ; policies associated with the zone).  Zone attributes as above.
        ; Returns S_OK or ??? if failed to write the zone attributes.
        ;* Registry Flags
        ;When reading, default behavior is:
        ;If HKLM allows override and HKCU value exists
        ;Then use HKCU value
        ;Else use HKLM value
        ;When writing, default behavior is same as HKCU
        ;If HKLM allows override
        ;Then Write to HKCU
        ;Else Fail
        ;*
        URLZONEREG typedef SDWORD
        URLZONEREG_DEFAULT equ 0
        URLZONEREG_HKLM equ
        URLZONEREG_HKCU equ
        _URLZONEREG typedef URLZONEREG

        ; Gets a named custom policy associated with a zone;
        ; e.g. the Java VM settings can be defined with a unique key such as 'Java'.
        ; Custom policy support is intended to allow extensibility from the predefined
        ; set of policies that IE4 has built in.
        ; 
        ; pwszKey is the string name designating the custom policy.  Components are
        ;   responsible for having unique names.
        ; ppPolicy is the callee allocated buffer for the policy byte blob; caller is
        ;   responsible for freeing this buffer eventually.
        ; pcbPolicy is the size of the byte blob returned.
        ; dwRegFlags determines how registry is accessed (see above).
        ; Returns S_OK if key is found and buffer allocated; ??? if key is not found (no buffer alloced).
        ; Sets a named custom policy associated with a zone;
        ; e.g. the Java VM settings can be defined with a unique key such as 'Java'.
        ; Custom policy support is intended to allow extensibility from the predefined
        ; set of policies that IE4 has built in.  
        ; 
        ; pwszKey is the string name designating the custom policy.  Components are
        ;   responsible for having unique names.
        ; ppPolicy is the caller allocated buffer for the policy byte blob.
        ; pcbPolicy is the size of the byte blob to be set.
        ; dwRegFlags determines if HTCU or HKLM is set.
        ; Returns S_OK or ??? if failed to write the zone custom policy.
        ; Gets action policy associated with a zone, the builtin, fixed-length policies info.
        ; dwAction is the action code for the action as defined above.
        ; pPolicy is the caller allocated buffer for the policy data.
        ; cbPolicy is the size of the caller allocated buffer.
        ; dwRegFlags determines how registry is accessed (see above).
        ; Returns S_OK if action is valid; ??? if action is not valid.
        externdef IID_IInternetZoneManager:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IInternetZoneManagerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IInternetZoneManagerVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IInternetZoneManager, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IInternetZoneManager
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IInternetZoneManager
            DECLSPEC_XFGVIRT(IInternetZoneManager, GetZoneAttributes)
            ;* [in] *
            ;* [annotation][unique][out][in] *
            STD_METHOD GetZoneAttributes, :ptr IInternetZoneManager, :DWORD, :ptr ZONEATTRIBUTES
            DECLSPEC_XFGVIRT(IInternetZoneManager, SetZoneAttributes)
            ;* [in] *
            ;* [annotation][in] *
            STD_METHOD SetZoneAttributes, :ptr IInternetZoneManager, :DWORD, :ptr ZONEATTRIBUTES
            DECLSPEC_XFGVIRT(IInternetZoneManager, GetZoneCustomPolicy)
            ;* [in] *
            ;* [in] *
            ;* [annotation][size_is][size_is][out] *
            ;* [annotation][out] *
            STD_METHOD GetZoneCustomPolicy, :ptr IInternetZoneManager, :DWORD, :REFGUID, :ptr ptr BYTE, :ptr DWORD, :URLZONEREG
            ;* [in] *
            DECLSPEC_XFGVIRT(IInternetZoneManager, SetZoneCustomPolicy)
            ;* [in] *
            ;* [in] *
            ;* [annotation][size_is][in] *
            ;* [in] *
            STD_METHOD SetZoneCustomPolicy, :ptr IInternetZoneManager, :DWORD, :REFGUID, :ptr BYTE, :DWORD, :URLZONEREG
            ;* [in] *
            DECLSPEC_XFGVIRT(IInternetZoneManager, GetZoneActionPolicy)
            ;* [in] *
            ;* [in] *
            ;* [annotation][size_is][out] *
            ;* [in] *
            STD_METHOD GetZoneActionPolicy, :ptr IInternetZoneManager, :DWORD, :DWORD, :ptr BYTE, :DWORD, :URLZONEREG
            ;* [in] *
            DECLSPEC_XFGVIRT(IInternetZoneManager, SetZoneActionPolicy)
            ;* [in] *
            ;* [in] *
            ;* [annotation][size_is][in] *
            ;* [in] *
            STD_METHOD SetZoneActionPolicy, :ptr IInternetZoneManager, :DWORD, :DWORD, :ptr BYTE, :DWORD, :URLZONEREG
            ;* [in] *
            DECLSPEC_XFGVIRT(IInternetZoneManager, PromptAction)
            ;* [in] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD PromptAction, :ptr IInternetZoneManager, :DWORD, :HWND, :LPCWSTR, :LPCWSTR, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IInternetZoneManager, LogAction)
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD LogAction, :ptr IInternetZoneManager, :DWORD, :LPCWSTR, :LPCWSTR, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IInternetZoneManager, CreateZoneEnumerator)
            ;* [out] *
            ;* [out] *
            STD_METHOD CreateZoneEnumerator, :ptr IInternetZoneManager, :ptr DWORD, :ptr DWORD, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IInternetZoneManager, GetZoneAt)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetZoneAt, :ptr IInternetZoneManager, :DWORD, :DWORD, :ptr DWORD
            ;* [out] *
            DECLSPEC_XFGVIRT(IInternetZoneManager, DestroyZoneEnumerator)
            STD_METHOD DestroyZoneEnumerator, :ptr IInternetZoneManager, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IInternetZoneManager, CopyTemplatePoliciesToZone)
            ;* [in] *
            ;* [in] *
            STD_METHOD CopyTemplatePoliciesToZone, :ptr IInternetZoneManager, :DWORD, :DWORD, :DWORD
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IInternetZoneManagerVtbl ends
          IInternetZoneManager struct
            lpVtbl POINTER ?
          IInternetZoneManager ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IInternetZoneManager_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0045 *
      ;* [local] *
    endif
    if (_WIN32_IE ge _WIN32_IE_IE60SP2)
      ifndef _LPINTERNETZONEMANAGEREX_DEFINED
        _LPINTERNETZONEMANAGEREX_DEFINED equ <>
        externdef __MIDL_itf_urlmon_0000_0045_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0045_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IInternetZoneManagerEx_INTERFACE_DEFINED__
          __IInternetZoneManagerEx_INTERFACE_DEFINED__ equ <>
          ;* interface IInternetZoneManagerEx *
          ;* [unique][helpstring][uuid][object][local] *
          ; Gets action policy associated with a zone, the builtin, fixed-length policies info.
          ; dwAction is the action code for the action as defined above.
          ; pPolicy is the caller allocated buffer for the policy data.
          ; cbPolicy is the size of the caller allocated buffer.
          ; dwRegFlags determines how registry is accessed (see above).
          ; dwFlags determine which registry policies are accessed (see above).
          ; Returns S_OK if action is valid; ??? if action is not valid.
          externdef IID_IInternetZoneManagerEx:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IInternetZoneManagerExVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetZoneManagerExVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              ;* [in] *
              ;* [annotation][iid_is][out] *
              STD_METHOD QueryInterface, :ptr IInternetZoneManagerEx, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IInternetZoneManagerEx
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IInternetZoneManagerEx
              DECLSPEC_XFGVIRT(IInternetZoneManager, GetZoneAttributes)
              ;* [in] *
              ;* [annotation][unique][out][in] *
              STD_METHOD GetZoneAttributes, :ptr IInternetZoneManagerEx, :DWORD, :ptr ZONEATTRIBUTES
              DECLSPEC_XFGVIRT(IInternetZoneManager, SetZoneAttributes)
              ;* [in] *
              ;* [annotation][in] *
              STD_METHOD SetZoneAttributes, :ptr IInternetZoneManagerEx, :DWORD, :ptr ZONEATTRIBUTES
              DECLSPEC_XFGVIRT(IInternetZoneManager, GetZoneCustomPolicy)
              ;* [in] *
              ;* [in] *
              ;* [annotation][size_is][size_is][out] *
              ;* [annotation][out] *
              STD_METHOD GetZoneCustomPolicy, :ptr IInternetZoneManagerEx, :DWORD, :REFGUID, :ptr ptr BYTE, :ptr DWORD, :URLZONEREG
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetZoneManager, SetZoneCustomPolicy)
              ;* [in] *
              ;* [in] *
              ;* [annotation][size_is][in] *
              ;* [in] *
              STD_METHOD SetZoneCustomPolicy, :ptr IInternetZoneManagerEx, :DWORD, :REFGUID, :ptr BYTE, :DWORD, :URLZONEREG
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetZoneManager, GetZoneActionPolicy)
              ;* [in] *
              ;* [in] *
              ;* [annotation][size_is][out] *
              ;* [in] *
              STD_METHOD GetZoneActionPolicy, :ptr IInternetZoneManagerEx, :DWORD, :DWORD, :ptr BYTE, :DWORD, :URLZONEREG
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetZoneManager, SetZoneActionPolicy)
              ;* [in] *
              ;* [in] *
              ;* [annotation][size_is][in] *
              ;* [in] *
              STD_METHOD SetZoneActionPolicy, :ptr IInternetZoneManagerEx, :DWORD, :DWORD, :ptr BYTE, :DWORD, :URLZONEREG
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetZoneManager, PromptAction)
              ;* [in] *
              ;* [in] *
              ;* [in] *
              ;* [in] *
              STD_METHOD PromptAction, :ptr IInternetZoneManagerEx, :DWORD, :HWND, :LPCWSTR, :LPCWSTR, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetZoneManager, LogAction)
              ;* [in] *
              ;* [in] *
              ;* [in] *
              STD_METHOD LogAction, :ptr IInternetZoneManagerEx, :DWORD, :LPCWSTR, :LPCWSTR, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetZoneManager, CreateZoneEnumerator)
              ;* [out] *
              ;* [out] *
              STD_METHOD CreateZoneEnumerator, :ptr IInternetZoneManagerEx, :ptr DWORD, :ptr DWORD, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetZoneManager, GetZoneAt)
              ;* [in] *
              ;* [in] *
              STD_METHOD GetZoneAt, :ptr IInternetZoneManagerEx, :DWORD, :DWORD, :ptr DWORD
              ;* [out] *
              DECLSPEC_XFGVIRT(IInternetZoneManager, DestroyZoneEnumerator)
              STD_METHOD DestroyZoneEnumerator, :ptr IInternetZoneManagerEx, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetZoneManager, CopyTemplatePoliciesToZone)
              ;* [in] *
              ;* [in] *
              STD_METHOD CopyTemplatePoliciesToZone, :ptr IInternetZoneManagerEx, :DWORD, :DWORD, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetZoneManagerEx, GetZoneActionPolicyEx)
              ;* [in] *
              ;* [in] *
              ;* [annotation][size_is][out] *
              ;* [in] *
              ;* [in] *
              STD_METHOD GetZoneActionPolicyEx, :ptr IInternetZoneManagerEx, :DWORD, :DWORD, :ptr BYTE, :DWORD, :URLZONEREG, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetZoneManagerEx, SetZoneActionPolicyEx)
              ;* [in] *
              ;* [in] *
              ;* [annotation][size_is][in] *
              ;* [in] *
              ;* [in] *
              STD_METHOD SetZoneActionPolicyEx, :ptr IInternetZoneManagerEx, :DWORD, :DWORD, :ptr BYTE, :DWORD, :URLZONEREG, :DWORD
              ;* [in] *
              ??Interface equ <>
              END_INTERFACE
            IInternetZoneManagerExVtbl ends
            IInternetZoneManagerEx struct
              lpVtbl POINTER ?
            IInternetZoneManagerEx ends
            ifdef COBJMACROS
              ;[...]
            endif
            ;* C style interface *
          endif
          ;* __IInternetZoneManagerEx_INTERFACE_DEFINED__ *
        endif
        ;* interface __MIDL_itf_urlmon_0000_0046 *
        ;* [local] *
      endif
    endif
    ;(_WIN32_IE >= _WIN32_IE_IE60SP2)
    if (_WIN32_IE ge _WIN32_IE_IE70)
      ifndef _LPINTERNETZONEMANAGEREX2_DEFINED
        _LPINTERNETZONEMANAGEREX2_DEFINED equ <>
        SECURITY_IE_STATE_GREEN equ 00000000h
        SECURITY_IE_STATE_RED equ 00000001h
        externdef __MIDL_itf_urlmon_0000_0046_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0046_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IInternetZoneManagerEx2_INTERFACE_DEFINED__
          __IInternetZoneManagerEx2_INTERFACE_DEFINED__ equ <>
          ;* interface IInternetZoneManagerEx2 *
          ;* [unique][helpstring][uuid][object][local] *
          ; Gets the zone attributes (information in registry other than actual security
          ; policies associated with the zone).  Zone attributes are fixed as:
          ; Can also verify template settings by matching current settings with security template
          externdef IID_IInternetZoneManagerEx2:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            IInternetZoneManagerEx2Vtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetZoneManagerEx2Vtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              ;* [in] *
              ;* [annotation][iid_is][out] *
              STD_METHOD QueryInterface, :ptr IInternetZoneManagerEx2, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IInternetZoneManagerEx2
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IInternetZoneManagerEx2
              DECLSPEC_XFGVIRT(IInternetZoneManager, GetZoneAttributes)
              ;* [in] *
              ;* [annotation][unique][out][in] *
              STD_METHOD GetZoneAttributes, :ptr IInternetZoneManagerEx2, :DWORD, :ptr ZONEATTRIBUTES
              DECLSPEC_XFGVIRT(IInternetZoneManager, SetZoneAttributes)
              ;* [in] *
              ;* [annotation][in] *
              STD_METHOD SetZoneAttributes, :ptr IInternetZoneManagerEx2, :DWORD, :ptr ZONEATTRIBUTES
              DECLSPEC_XFGVIRT(IInternetZoneManager, GetZoneCustomPolicy)
              ;* [in] *
              ;* [in] *
              ;* [annotation][size_is][size_is][out] *
              ;* [annotation][out] *
              STD_METHOD GetZoneCustomPolicy, :ptr IInternetZoneManagerEx2, :DWORD, :REFGUID, :ptr ptr BYTE, :ptr DWORD, :URLZONEREG
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetZoneManager, SetZoneCustomPolicy)
              ;* [in] *
              ;* [in] *
              ;* [annotation][size_is][in] *
              ;* [in] *
              STD_METHOD SetZoneCustomPolicy, :ptr IInternetZoneManagerEx2, :DWORD, :REFGUID, :ptr BYTE, :DWORD, :URLZONEREG
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetZoneManager, GetZoneActionPolicy)
              ;* [in] *
              ;* [in] *
              ;* [annotation][size_is][out] *
              ;* [in] *
              STD_METHOD GetZoneActionPolicy, :ptr IInternetZoneManagerEx2, :DWORD, :DWORD, :ptr BYTE, :DWORD, :URLZONEREG
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetZoneManager, SetZoneActionPolicy)
              ;* [in] *
              ;* [in] *
              ;* [annotation][size_is][in] *
              ;* [in] *
              STD_METHOD SetZoneActionPolicy, :ptr IInternetZoneManagerEx2, :DWORD, :DWORD, :ptr BYTE, :DWORD, :URLZONEREG
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetZoneManager, PromptAction)
              ;* [in] *
              ;* [in] *
              ;* [in] *
              ;* [in] *
              STD_METHOD PromptAction, :ptr IInternetZoneManagerEx2, :DWORD, :HWND, :LPCWSTR, :LPCWSTR, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetZoneManager, LogAction)
              ;* [in] *
              ;* [in] *
              ;* [in] *
              STD_METHOD LogAction, :ptr IInternetZoneManagerEx2, :DWORD, :LPCWSTR, :LPCWSTR, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetZoneManager, CreateZoneEnumerator)
              ;* [out] *
              ;* [out] *
              STD_METHOD CreateZoneEnumerator, :ptr IInternetZoneManagerEx2, :ptr DWORD, :ptr DWORD, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetZoneManager, GetZoneAt)
              ;* [in] *
              ;* [in] *
              STD_METHOD GetZoneAt, :ptr IInternetZoneManagerEx2, :DWORD, :DWORD, :ptr DWORD
              ;* [out] *
              DECLSPEC_XFGVIRT(IInternetZoneManager, DestroyZoneEnumerator)
              STD_METHOD DestroyZoneEnumerator, :ptr IInternetZoneManagerEx2, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetZoneManager, CopyTemplatePoliciesToZone)
              ;* [in] *
              ;* [in] *
              STD_METHOD CopyTemplatePoliciesToZone, :ptr IInternetZoneManagerEx2, :DWORD, :DWORD, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetZoneManagerEx, GetZoneActionPolicyEx)
              ;* [in] *
              ;* [in] *
              ;* [annotation][size_is][out] *
              ;* [in] *
              ;* [in] *
              STD_METHOD GetZoneActionPolicyEx, :ptr IInternetZoneManagerEx2, :DWORD, :DWORD, :ptr BYTE, :DWORD, :URLZONEREG, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetZoneManagerEx, SetZoneActionPolicyEx)
              ;* [in] *
              ;* [in] *
              ;* [annotation][size_is][in] *
              ;* [in] *
              ;* [in] *
              STD_METHOD SetZoneActionPolicyEx, :ptr IInternetZoneManagerEx2, :DWORD, :DWORD, :ptr BYTE, :DWORD, :URLZONEREG, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetZoneManagerEx2, GetZoneAttributesEx)
              ;* [in] *
              ;* [unique][out][in] *
              STD_METHOD GetZoneAttributesEx, :ptr IInternetZoneManagerEx2, :DWORD, :ptr ZONEATTRIBUTES, :DWORD
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetZoneManagerEx2, GetZoneSecurityState)
              ;* [in] *
              ;* [in] *
              ;* [out][in] *
              STD_METHOD GetZoneSecurityState, :ptr IInternetZoneManagerEx2, :DWORD, :BOOL, :LPDWORD, :ptr BOOL
              ;* [out][in] *
              DECLSPEC_XFGVIRT(IInternetZoneManagerEx2, GetIESecurityState)
              ;* [in] *
              ;* [out][in] *
              ;* [out][in] *
              STD_METHOD GetIESecurityState, :ptr IInternetZoneManagerEx2, :BOOL, :LPDWORD, :ptr BOOL, :BOOL
              ;* [in] *
              DECLSPEC_XFGVIRT(IInternetZoneManagerEx2, FixUnsecureSettings)
              STD_METHOD FixUnsecureSettings, :ptr IInternetZoneManagerEx2
              ??Interface equ <>
              END_INTERFACE
            IInternetZoneManagerEx2Vtbl ends
            IInternetZoneManagerEx2 struct
              lpVtbl POINTER ?
            IInternetZoneManagerEx2 ends
            ifdef COBJMACROS
              ;[...]
            endif
            ;* C style interface *
          endif
          ;* __IInternetZoneManagerEx2_INTERFACE_DEFINED__ *
        endif
        ;* interface __MIDL_itf_urlmon_0000_0047 *
        ;* [local] *
      endif
    endif
    ;(_WIN32_IE >= _WIN32_IE_IE70)
    externdef CLSID_SoftDistExt:IID
    ifndef _LPSOFTDISTEXT_DEFINED
      _LPSOFTDISTEXT_DEFINED equ <>
      SOFTDIST_FLAG_USAGE_EMAIL equ 00000001h
      SOFTDIST_FLAG_USAGE_PRECACHE equ 00000002h
      SOFTDIST_FLAG_USAGE_AUTOINSTALL equ 00000004h
      SOFTDIST_FLAG_DELETE_SUBSCRIPTION equ 00000008h
      SOFTDIST_ADSTATE_NONE equ 00000000h
      SOFTDIST_ADSTATE_AVAILABLE equ 00000001h
      SOFTDIST_ADSTATE_DOWNLOADED equ 00000002h
      SOFTDIST_ADSTATE_INSTALLED equ 00000003h
      CODEBASEHOLD struct
        cbSize DWORD ?
        szDistUnit POINTER ?
        szCodeBase POINTER ?
        dwVersionMS DWORD ?
        dwVersionLS DWORD ?
        dwStyle DWORD ?
      CODEBASEHOLD ends
      _tagCODEBASEHOLD typedef CODEBASEHOLD
      LPCODEBASEHOLD typedef ptr _tagCODEBASEHOLD
      SOFTDISTINFO struct
        cbSize DWORD ?
        dwFlags DWORD ?
        dwAdState DWORD ?
        szTitle POINTER ?
        szAbstract POINTER ?
        szHREF POINTER ?
        dwInstalledVersionMS DWORD ?
        dwInstalledVersionLS DWORD ?
        dwUpdateVersionMS DWORD ?
        dwUpdateVersionLS DWORD ?
        dwAdvertisedVersionMS DWORD ?
        dwAdvertisedVersionLS DWORD ?
        dwReserved DWORD ?
      SOFTDISTINFO ends
      _tagSOFTDISTINFO typedef SOFTDISTINFO
      LPSOFTDISTINFO typedef ptr _tagSOFTDISTINFO
      externdef __MIDL_itf_urlmon_0000_0047_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0047_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ISoftDistExt_INTERFACE_DEFINED__
        __ISoftDistExt_INTERFACE_DEFINED__ equ <>
        ;* interface ISoftDistExt *
        ;* [unique][helpstring][uuid][object][local] *
        externdef IID_ISoftDistExt:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISoftDistExtVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISoftDistExtVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISoftDistExt, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISoftDistExt
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISoftDistExt
            DECLSPEC_XFGVIRT(ISoftDistExt, ProcessSoftDist)
            ;* [in] *
            ;* [in] *
            STD_METHOD ProcessSoftDist, :ptr ISoftDistExt, :LPCWSTR, :ptr IXMLElement, :LPSOFTDISTINFO
            ;* [out][in] *
            DECLSPEC_XFGVIRT(ISoftDistExt, GetFirstCodeBase)
            ;* [annotation][in] *
            STD_METHOD GetFirstCodeBase, :ptr ISoftDistExt, :ptr LPWSTR, :LPDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(ISoftDistExt, GetNextCodeBase)
            ;* [annotation][in] *
            STD_METHOD GetNextCodeBase, :ptr ISoftDistExt, :ptr LPWSTR, :LPDWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(ISoftDistExt, AsyncInstallDistributionUnit)
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD AsyncInstallDistributionUnit, :ptr ISoftDistExt, :ptr IBindCtx, :LPVOID, :DWORD, :LPCODEBASEHOLD
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          ISoftDistExtVtbl ends
          ISoftDistExt struct
            lpVtbl POINTER ?
          ISoftDistExt ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISoftDistExt_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0048 *
      ;* [local] *
      @DefProto DllImport, GetSoftwareUpdateInfo, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPSOFTDISTINFO>, 8
      @DefProto DllImport, SetSoftwareUpdateAdvertisementState, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :DWORD, :DWORD>, 16
    endif
    ifndef _LPCATALOGFILEINFO_DEFINED
      _LPCATALOGFILEINFO_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0048_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0048_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ICatalogFileInfo_INTERFACE_DEFINED__
        __ICatalogFileInfo_INTERFACE_DEFINED__ equ <>
        ;* interface ICatalogFileInfo *
        ;* [unique][uuid][object][local] *
        ;* [unique] *
        LPCATALOGFILEINFO typedef ptr ICatalogFileInfo
        externdef IID_ICatalogFileInfo:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ICatalogFileInfoVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ICatalogFileInfoVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ICatalogFileInfo, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ICatalogFileInfo
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ICatalogFileInfo
            DECLSPEC_XFGVIRT(ICatalogFileInfo, GetCatalogFile)
            ;* [annotation][out] *
            STD_METHOD GetCatalogFile, :ptr ICatalogFileInfo, :ptr LPSTR
            DECLSPEC_XFGVIRT(ICatalogFileInfo, GetJavaTrust)
            STD_METHOD GetJavaTrust, :ptr ICatalogFileInfo, :ptr ptr
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          ICatalogFileInfoVtbl ends
          ICatalogFileInfo struct
            lpVtbl POINTER ?
          ICatalogFileInfo ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ICatalogFileInfo_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0049 *
      ;* [local] *
    endif
    ifndef _LPDATAFILTER_DEFINED
      _LPDATAFILTER_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0049_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0049_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDataFilter_INTERFACE_DEFINED__
        __IDataFilter_INTERFACE_DEFINED__ equ <>
        ;* interface IDataFilter *
        ;* [unique][uuid][object] *
        ;* [unique] *
        LPDATAFILTER typedef ptr IDataFilter
        externdef IID_IDataFilter:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDataFilterVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDataFilterVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDataFilter, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDataFilter
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDataFilter
            DECLSPEC_XFGVIRT(IDataFilter, DoEncode)
            ;* [in] *
            ;* [in] *
            ;* [size_is][in] *
            ;* [in] *
            ;* [size_is][out] *
            ;* [in] *
            ;* [out] *
            ;* [out] *
            STD_METHOD DoEncode, :ptr IDataFilter, :DWORD, :LONG, :ptr BYTE, :LONG, :ptr BYTE, :LONG, :ptr LONG, :ptr LONG, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IDataFilter, DoDecode)
            ;* [in] *
            ;* [in] *
            ;* [size_is][in] *
            ;* [in] *
            ;* [size_is][out] *
            ;* [in] *
            ;* [out] *
            ;* [out] *
            STD_METHOD DoDecode, :ptr IDataFilter, :DWORD, :LONG, :ptr BYTE, :LONG, :ptr BYTE, :LONG, :ptr LONG, :ptr LONG, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IDataFilter, SetEncodingLevel)
            STD_METHOD SetEncodingLevel, :ptr IDataFilter, :DWORD
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IDataFilterVtbl ends
          IDataFilter struct
            lpVtbl POINTER ?
          IDataFilter ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IDataFilter_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0050 *
      ;* [local] *
    endif
    ifndef _LPENCODINGFILTERFACTORY_DEFINED
      _LPENCODINGFILTERFACTORY_DEFINED equ <>
      PROTOCOLFILTERDATA struct
        cbSize DWORD ?
        pProtocolSink POINTER ?
        pProtocol POINTER ?
        pUnk POINTER ?
        dwFilterFlags DWORD ?
      PROTOCOLFILTERDATA ends
      _tagPROTOCOLFILTERDATA typedef PROTOCOLFILTERDATA
      externdef __MIDL_itf_urlmon_0000_0050_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0050_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IEncodingFilterFactory_INTERFACE_DEFINED__
        __IEncodingFilterFactory_INTERFACE_DEFINED__ equ <>
        ;* interface IEncodingFilterFactory *
        ;* [unique][uuid][object][local] *
        ;* [unique] *
        LPENCODINGFILTERFACTORY typedef ptr IEncodingFilterFactory
        DATAINFO struct
          ulTotalSize DWORD ?
          ulavrPacketSize DWORD ?
          ulConnectSpeed DWORD ?
          ulProcessorSpeed DWORD ?
        DATAINFO ends
        _tagDATAINFO typedef DATAINFO
        externdef IID_IEncodingFilterFactory:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IEncodingFilterFactoryVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEncodingFilterFactoryVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IEncodingFilterFactory, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IEncodingFilterFactory
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IEncodingFilterFactory
            DECLSPEC_XFGVIRT(IEncodingFilterFactory, FindBestFilter)
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD FindBestFilter, :ptr IEncodingFilterFactory, :LPCWSTR, :LPCWSTR, :DATAINFO, :ptr ptr IDataFilter
            ;* [out] *
            DECLSPEC_XFGVIRT(IEncodingFilterFactory, GetDefaultFilter)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetDefaultFilter, :ptr IEncodingFilterFactory, :LPCWSTR, :LPCWSTR, :ptr ptr IDataFilter
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IEncodingFilterFactoryVtbl ends
          IEncodingFilterFactory struct
            lpVtbl POINTER ?
          IEncodingFilterFactory ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IEncodingFilterFactory_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0051 *
      ;* [local] *
    endif
    ifndef _HITLOGGING_DEFINED
      _HITLOGGING_DEFINED equ <>
      ; Logging-specific apis
      IsLoggingEnabledA proto WIN_STD_CALL_CONV :LPCSTR
      IsLoggingEnabledW proto WIN_STD_CALL_CONV :LPCWSTR
      ifdef UNICODE
        IsLoggingEnabled equ <IsLoggingEnabledW>
      else
        IsLoggingEnabled equ <IsLoggingEnabledA>
      endif
      ; !UNICODE                                                   
      HIT_LOGGING_INFO struct
        dwStructSize DWORD ?
        lpszLoggedUrlName POINTER ?
        StartTime SYSTEMTIME <>
        EndTime SYSTEMTIME <>
        lpszExtendedInfo POINTER ?
      HIT_LOGGING_INFO ends
      _tagHIT_LOGGING_INFO typedef HIT_LOGGING_INFO
      LPHIT_LOGGING_INFO typedef ptr _tagHIT_LOGGING_INFO
      WriteHitLogging proto WIN_STD_CALL_CONV :LPHIT_LOGGING_INFO
      CONFIRMSAFETYACTION_LOADOBJECT equ 00000001h
      CONFIRMSAFETY struct
        clsid CLSID <>
        pUnk POINTER ?
        dwFlags DWORD ?
      CONFIRMSAFETY ends
      externdef GUID_CUSTOM_CONFIRMOBJECTSAFETY:GUID
    endif
    ifndef _LPIWRAPPEDPROTOCOL_DEFINED
      _LPIWRAPPEDPROTOCOL_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0051_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0051_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IWrappedProtocol_INTERFACE_DEFINED__
        __IWrappedProtocol_INTERFACE_DEFINED__ equ <>
        ;* interface IWrappedProtocol *
        ;* [unique][uuid][object][local] *
        ;* [unique] *
        LPIWRAPPEDPROTOCOL typedef ptr IWrappedProtocol
        externdef IID_IWrappedProtocol:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IWrappedProtocolVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IWrappedProtocolVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IWrappedProtocol, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IWrappedProtocol
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IWrappedProtocol
            DECLSPEC_XFGVIRT(IWrappedProtocol, GetWrapperCode)
            ;* [out] *
            STD_METHOD GetWrapperCode, :ptr IWrappedProtocol, :ptr LONG, :DWORD_PTR
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IWrappedProtocolVtbl ends
          IWrappedProtocol struct
            lpVtbl POINTER ?
          IWrappedProtocol ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IWrappedProtocol_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0052 *
      ;* [local] *
    endif
    ifndef _LPGETBINDHANDLE_DEFINED
      _LPGETBINDHANDLE_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0052_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0052_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IGetBindHandle_INTERFACE_DEFINED__
        __IGetBindHandle_INTERFACE_DEFINED__ equ <>
        ;* interface IGetBindHandle *
        ;* [unique][uuid][object][local] *
        ;* [unique] *
        LPGETBINDHANDLE typedef ptr IGetBindHandle
        ;* [public][public] *
        BINDHANDLETYPES typedef SDWORD
        BINDHANDLETYPES_APPCACHE equ 0
        BINDHANDLETYPES_DEPENDENCY equ 1h
        BINDHANDLETYPES_COUNT equ
        __MIDL_IGetBindHandle_0001 typedef BINDHANDLETYPES

        externdef IID_IGetBindHandle:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IGetBindHandleVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IGetBindHandleVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IGetBindHandle, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IGetBindHandle
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IGetBindHandle
            DECLSPEC_XFGVIRT(IGetBindHandle, GetBindHandle)
            ;* [in] *
            STD_METHOD GetBindHandle, :ptr IGetBindHandle, :BINDHANDLETYPES, :ptr HANDLE
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IGetBindHandleVtbl ends
          IGetBindHandle struct
            lpVtbl POINTER ?
          IGetBindHandle ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IGetBindHandle_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0053 *
      ;* [local] *
    endif
    ifndef _XHRPLUGGABLEPROTOCOL_DEFINED
      _XHRPLUGGABLEPROTOCOL_DEFINED equ <>
      PROTOCOL_ARGUMENT struct
        szMethod =POINTER ?
        szTargetUrl =POINTER ?
      PROTOCOL_ARGUMENT ends
      _tagPROTOCOL_ARGUMENT typedef PROTOCOL_ARGUMENT
      LPPROTOCOL_ARGUMENT typedef ptr _tagPROTOCOL_ARGUMENT
    endif
    ifndef _LPBINDCALLBACKREDIRECT_DEFINED
      _LPBINDCALLBACKREDIRECT_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0053_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0053_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IBindCallbackRedirect_INTERFACE_DEFINED__
        __IBindCallbackRedirect_INTERFACE_DEFINED__ equ <>
        ;* interface IBindCallbackRedirect *
        ;* [unique][uuid][object][local] *
        ;* [unique] *
        LPBINDCALLBACKREDIRECT typedef ptr IBindCallbackRedirect
        externdef IID_IBindCallbackRedirect:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IBindCallbackRedirectVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IBindCallbackRedirectVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IBindCallbackRedirect, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IBindCallbackRedirect
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IBindCallbackRedirect
            DECLSPEC_XFGVIRT(IBindCallbackRedirect, Redirect)
            ;* [in] *
            STD_METHOD Redirect, :ptr IBindCallbackRedirect, :LPCWSTR, :ptr VARIANT_BOOL
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IBindCallbackRedirectVtbl ends
          IBindCallbackRedirect struct
            lpVtbl POINTER ?
          IBindCallbackRedirect ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IBindCallbackRedirect_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0054 *
      ;* [local] *
    endif
    ifndef _LPIBINDHTTPSECURITY_DEFINED
      _LPIBINDHTTPSECURITY_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0054_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0054_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IBindHttpSecurity_INTERFACE_DEFINED__
        __IBindHttpSecurity_INTERFACE_DEFINED__ equ <>
        ;* interface IBindHttpSecurity *
        ;* [helpstring][uuid][object] *
        externdef IID_IBindHttpSecurity:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IBindHttpSecurityVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IBindHttpSecurityVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IBindHttpSecurity, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IBindHttpSecurity
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IBindHttpSecurity
            DECLSPEC_XFGVIRT(IBindHttpSecurity, GetIgnoreCertMask)
            STD_METHOD GetIgnoreCertMask, :ptr IBindHttpSecurity, :ptr DWORD
            ;* [ref][out] *
            ??Interface equ <>
            END_INTERFACE
          IBindHttpSecurityVtbl ends
          IBindHttpSecurity struct
            lpVtbl POINTER ?
          IBindHttpSecurity ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IBindHttpSecurity_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_urlmon_0000_0055 *
      ;* [local] *
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  if _MSC_VER ge 1200
  endif
  externdef __MIDL_itf_urlmon_0000_0055_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_urlmon_0000_0055_v0_0_s_ifspec:RPC_IF_HANDLE
  ;* Additional Prototypes for ALL interfaces *
  BSTR_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr BSTR
  BSTR_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BSTR
  HWND_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HWND
  HWND_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HWND
  HWND_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HWND
  HWND_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HWND
  BSTR_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr BSTR
  BSTR_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BSTR
  HWND_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HWND
  HWND_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HWND
  HWND_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HWND
  HWND_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HWND
  ;* [local] *
  IBinding_GetBindResult_Proxy proto WIN_STD_CALL_CONV :ptr IBinding, :ptr CLSID, :ptr DWORD, :ptr LPOLESTR, :ptr DWORD
  ;* [out][in] *
  ;* [call_as] *
  IBinding_GetBindResult_Stub proto WIN_STD_CALL_CONV :ptr IBinding, :ptr CLSID, :ptr DWORD, :ptr LPOLESTR, :DWORD
  ;* [in] *
  ;* [local] *
  IBindStatusCallback_GetBindInfo_Proxy proto WIN_STD_CALL_CONV :ptr IBindStatusCallback, :ptr DWORD, :ptr BINDINFO
  ;* [unique][out][in] *
  ;* [call_as] *
  IBindStatusCallback_GetBindInfo_Stub proto WIN_STD_CALL_CONV :ptr IBindStatusCallback, :ptr DWORD, :ptr RemBINDINFO, :ptr RemSTGMEDIUM
  ;* [unique][out][in] *
  ;* [local] *
  IBindStatusCallback_OnDataAvailable_Proxy proto WIN_STD_CALL_CONV :ptr IBindStatusCallback, :DWORD, :DWORD, :ptr FORMATETC, :ptr STGMEDIUM
  ;* [in] *
  ;* [call_as] *
  IBindStatusCallback_OnDataAvailable_Stub proto WIN_STD_CALL_CONV :ptr IBindStatusCallback, :DWORD, :DWORD, :ptr RemFORMATETC, :ptr RemSTGMEDIUM
  ;* [in] *
  ;* [local] *
  IBindStatusCallbackEx_GetBindInfoEx_Proxy proto WIN_STD_CALL_CONV :ptr IBindStatusCallbackEx, :ptr DWORD, :ptr BINDINFO, :ptr DWORD, :ptr DWORD
  ;* [out] *
  ;* [call_as] *
  IBindStatusCallbackEx_GetBindInfoEx_Stub proto WIN_STD_CALL_CONV :ptr IBindStatusCallbackEx, :ptr DWORD, :ptr RemBINDINFO, :ptr RemSTGMEDIUM, :ptr DWORD, :ptr DWORD
  ;* [out] *
  ;* [local] *
  IWinInetInfo_QueryOption_Proxy proto WIN_STD_CALL_CONV :ptr IWinInetInfo, :DWORD, :LPVOID, :ptr DWORD
  ;* [out][in] *
  ;* [call_as] *
  IWinInetInfo_QueryOption_Stub proto WIN_STD_CALL_CONV :ptr IWinInetInfo, :DWORD, :ptr BYTE, :ptr DWORD
  ;* [out][in] *
  ;* [local] *
  IWinInetHttpInfo_QueryInfo_Proxy proto WIN_STD_CALL_CONV :ptr IWinInetHttpInfo, :DWORD, :LPVOID, :ptr DWORD, :ptr DWORD, :ptr DWORD
  ;* [out][in] *
  ;* [call_as] *
  IWinInetHttpInfo_QueryInfo_Stub proto WIN_STD_CALL_CONV :ptr IWinInetHttpInfo, :DWORD, :ptr BYTE, :ptr DWORD, :ptr DWORD, :ptr DWORD
  ;* [out][in] *
  ;* [local] *
  IBindHost_MonikerBindToStorage_Proxy proto WIN_STD_CALL_CONV :ptr IBindHost, :ptr IMoniker, :ptr IBindCtx, :ptr IBindStatusCallback, :REFIID, :ptr ptr
  ;* [out] *
  ;* [call_as] *
  IBindHost_MonikerBindToStorage_Stub proto WIN_STD_CALL_CONV :ptr IBindHost, :ptr IMoniker, :ptr IBindCtx, :ptr IBindStatusCallback, :REFIID, :ptr ptr IUnknown
  ;* [iid_is][out] *
  ;* [local] *
  IBindHost_MonikerBindToObject_Proxy proto WIN_STD_CALL_CONV :ptr IBindHost, :ptr IMoniker, :ptr IBindCtx, :ptr IBindStatusCallback, :REFIID, :ptr ptr
  ;* [out] *
  ;* [call_as] *
  IBindHost_MonikerBindToObject_Stub proto WIN_STD_CALL_CONV :ptr IBindHost, :ptr IMoniker, :ptr IBindCtx, :ptr IBindStatusCallback, :REFIID, :ptr ptr IUnknown
  ;* [iid_is][out] *
  ;* end of Additional Prototypes *
  ifdef __cplusplus
    ;[...]
  endif
endif
