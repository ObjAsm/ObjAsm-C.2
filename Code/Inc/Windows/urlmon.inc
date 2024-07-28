;Include file created by h2incX, Version B.01.02, 23/09/2018 18:52
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\urlmon.h', last modified: 19/04/2018 10:45
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
ifndef __urlmon_h__
  __urlmon_h__ equ <>
  if Defined(_MSC_VER) and (_MSC_VER ge 1020)
  endif
  ifndef __IPersistMoniker_FWD_DEFINED__
    __IPersistMoniker_FWD_DEFINED__ equ <>
    ;IPersistMoniker typedef IPersistMoniker
  endif
  ifndef __IMonikerProp_FWD_DEFINED__
    __IMonikerProp_FWD_DEFINED__ equ <>
    ;IMonikerProp typedef IMonikerProp
  endif
  ifndef __IBindProtocol_FWD_DEFINED__
    __IBindProtocol_FWD_DEFINED__ equ <>
    ;IBindProtocol typedef IBindProtocol
  endif
  ifndef __IBinding_FWD_DEFINED__
    __IBinding_FWD_DEFINED__ equ <>
    ;IBinding typedef IBinding
  endif
  ifndef __IBindStatusCallback_FWD_DEFINED__
    __IBindStatusCallback_FWD_DEFINED__ equ <>
    ;IBindStatusCallback typedef IBindStatusCallback
  endif
  ifndef __IBindStatusCallbackEx_FWD_DEFINED__
    __IBindStatusCallbackEx_FWD_DEFINED__ equ <>
    ;IBindStatusCallbackEx typedef IBindStatusCallbackEx
  endif
  ifndef __IAuthenticate_FWD_DEFINED__
    __IAuthenticate_FWD_DEFINED__ equ <>
    ;IAuthenticate typedef IAuthenticate
  endif
  ifndef __IAuthenticateEx_FWD_DEFINED__
    __IAuthenticateEx_FWD_DEFINED__ equ <>
    ;IAuthenticateEx typedef IAuthenticateEx
  endif
  ifndef __IHttpNegotiate_FWD_DEFINED__
    __IHttpNegotiate_FWD_DEFINED__ equ <>
    ;IHttpNegotiate typedef IHttpNegotiate
  endif
  ifndef __IHttpNegotiate2_FWD_DEFINED__
    __IHttpNegotiate2_FWD_DEFINED__ equ <>
    ;IHttpNegotiate2 typedef IHttpNegotiate2
  endif
  ifndef __IHttpNegotiate3_FWD_DEFINED__
    __IHttpNegotiate3_FWD_DEFINED__ equ <>
    ;IHttpNegotiate3 typedef IHttpNegotiate3
  endif
  ifndef __IWinInetFileStream_FWD_DEFINED__
    __IWinInetFileStream_FWD_DEFINED__ equ <>
    ;IWinInetFileStream typedef IWinInetFileStream
  endif
  ifndef __IWindowForBindingUI_FWD_DEFINED__
    __IWindowForBindingUI_FWD_DEFINED__ equ <>
    ;IWindowForBindingUI typedef IWindowForBindingUI
  endif
  ifndef __ICodeInstall_FWD_DEFINED__
    __ICodeInstall_FWD_DEFINED__ equ <>
    ;ICodeInstall typedef ICodeInstall
  endif
  ifndef __IUri_FWD_DEFINED__
    __IUri_FWD_DEFINED__ equ <>
    ;IUri typedef IUri
  endif
  ifndef __IUriContainer_FWD_DEFINED__
    __IUriContainer_FWD_DEFINED__ equ <>
    ;IUriContainer typedef IUriContainer
  endif
  ifndef __IUriBuilder_FWD_DEFINED__
    __IUriBuilder_FWD_DEFINED__ equ <>
    ;IUriBuilder typedef IUriBuilder
  endif
  ifndef __IUriBuilderFactory_FWD_DEFINED__
    __IUriBuilderFactory_FWD_DEFINED__ equ <>
    ;IUriBuilderFactory typedef IUriBuilderFactory
  endif
  ifndef __IWinInetInfo_FWD_DEFINED__
    __IWinInetInfo_FWD_DEFINED__ equ <>
    ;IWinInetInfo typedef IWinInetInfo
  endif
  ifndef __IHttpSecurity_FWD_DEFINED__
    __IHttpSecurity_FWD_DEFINED__ equ <>
    ;IHttpSecurity typedef IHttpSecurity
  endif
  ifndef __IWinInetHttpInfo_FWD_DEFINED__
    __IWinInetHttpInfo_FWD_DEFINED__ equ <>
    ;IWinInetHttpInfo typedef IWinInetHttpInfo
  endif
  ifndef __IWinInetHttpTimeouts_FWD_DEFINED__
    __IWinInetHttpTimeouts_FWD_DEFINED__ equ <>
    ;IWinInetHttpTimeouts typedef IWinInetHttpTimeouts
  endif
  ifndef __IWinInetCacheHints_FWD_DEFINED__
    __IWinInetCacheHints_FWD_DEFINED__ equ <>
    ;IWinInetCacheHints typedef IWinInetCacheHints
  endif
  ifndef __IWinInetCacheHints2_FWD_DEFINED__
    __IWinInetCacheHints2_FWD_DEFINED__ equ <>
    ;IWinInetCacheHints2 typedef IWinInetCacheHints2
  endif
  ifndef __IBindHost_FWD_DEFINED__
    __IBindHost_FWD_DEFINED__ equ <>
    ;IBindHost typedef IBindHost
  endif
  ifndef __IInternet_FWD_DEFINED__
    __IInternet_FWD_DEFINED__ equ <>
    ;IInternet typedef IInternet
  endif
  ifndef __IInternetBindInfo_FWD_DEFINED__
    __IInternetBindInfo_FWD_DEFINED__ equ <>
    ;IInternetBindInfo typedef IInternetBindInfo
  endif
  ifndef __IInternetBindInfoEx_FWD_DEFINED__
    __IInternetBindInfoEx_FWD_DEFINED__ equ <>
    ;IInternetBindInfoEx typedef IInternetBindInfoEx
  endif
  ifndef __IInternetProtocolRoot_FWD_DEFINED__
    __IInternetProtocolRoot_FWD_DEFINED__ equ <>
    ;IInternetProtocolRoot typedef IInternetProtocolRoot
  endif
  ifndef __IInternetProtocol_FWD_DEFINED__
    __IInternetProtocol_FWD_DEFINED__ equ <>
    ;IInternetProtocol typedef IInternetProtocol
  endif
  ifndef __IInternetProtocolEx_FWD_DEFINED__
    __IInternetProtocolEx_FWD_DEFINED__ equ <>
    ;IInternetProtocolEx typedef IInternetProtocolEx
  endif
  ifndef __IInternetProtocolSink_FWD_DEFINED__
    __IInternetProtocolSink_FWD_DEFINED__ equ <>
    ;IInternetProtocolSink typedef IInternetProtocolSink
  endif
  ifndef __IInternetProtocolSinkStackable_FWD_DEFINED__
    __IInternetProtocolSinkStackable_FWD_DEFINED__ equ <>
    ;IInternetProtocolSinkStackable typedef IInternetProtocolSinkStackable
  endif
  ifndef __IInternetSession_FWD_DEFINED__
    __IInternetSession_FWD_DEFINED__ equ <>
    ;IInternetSession typedef IInternetSession
  endif
  ifndef __IInternetThreadSwitch_FWD_DEFINED__
    __IInternetThreadSwitch_FWD_DEFINED__ equ <>
    ;IInternetThreadSwitch typedef IInternetThreadSwitch
  endif
  ifndef __IInternetPriority_FWD_DEFINED__
    __IInternetPriority_FWD_DEFINED__ equ <>
    ;IInternetPriority typedef IInternetPriority
  endif
  ifndef __IInternetProtocolInfo_FWD_DEFINED__
    __IInternetProtocolInfo_FWD_DEFINED__ equ <>
    ;IInternetProtocolInfo typedef IInternetProtocolInfo
  endif
  ifndef __IInternetSecurityMgrSite_FWD_DEFINED__
    __IInternetSecurityMgrSite_FWD_DEFINED__ equ <>
    ;IInternetSecurityMgrSite typedef IInternetSecurityMgrSite
  endif
  ifndef __IInternetSecurityManager_FWD_DEFINED__
    __IInternetSecurityManager_FWD_DEFINED__ equ <>
    ;IInternetSecurityManager typedef IInternetSecurityManager
  endif
  ifndef __IInternetSecurityManagerEx_FWD_DEFINED__
    __IInternetSecurityManagerEx_FWD_DEFINED__ equ <>
    ;IInternetSecurityManagerEx typedef IInternetSecurityManagerEx
  endif
  ifndef __IInternetSecurityManagerEx2_FWD_DEFINED__
    __IInternetSecurityManagerEx2_FWD_DEFINED__ equ <>
    ;IInternetSecurityManagerEx2 typedef IInternetSecurityManagerEx2
  endif
  ifndef __IZoneIdentifier_FWD_DEFINED__
    __IZoneIdentifier_FWD_DEFINED__ equ <>
    ;IZoneIdentifier typedef IZoneIdentifier
  endif
  ifndef __IZoneIdentifier2_FWD_DEFINED__
    __IZoneIdentifier2_FWD_DEFINED__ equ <>
    ;IZoneIdentifier2 typedef IZoneIdentifier2
  endif
  ifndef __IInternetHostSecurityManager_FWD_DEFINED__
    __IInternetHostSecurityManager_FWD_DEFINED__ equ <>
    ;IInternetHostSecurityManager typedef IInternetHostSecurityManager
  endif
  ifndef __IInternetZoneManager_FWD_DEFINED__
    __IInternetZoneManager_FWD_DEFINED__ equ <>
    ;IInternetZoneManager typedef IInternetZoneManager
  endif
  ifndef __IInternetZoneManagerEx_FWD_DEFINED__
    __IInternetZoneManagerEx_FWD_DEFINED__ equ <>
    ;IInternetZoneManagerEx typedef IInternetZoneManagerEx
  endif
  ifndef __IInternetZoneManagerEx2_FWD_DEFINED__
    __IInternetZoneManagerEx2_FWD_DEFINED__ equ <>
    ;IInternetZoneManagerEx2 typedef IInternetZoneManagerEx2
  endif
  ifndef __ISoftDistExt_FWD_DEFINED__
    __ISoftDistExt_FWD_DEFINED__ equ <>
    ;ISoftDistExt typedef ISoftDistExt
  endif
  ifndef __ICatalogFileInfo_FWD_DEFINED__
    __ICatalogFileInfo_FWD_DEFINED__ equ <>
    ;ICatalogFileInfo typedef ICatalogFileInfo
  endif
  ifndef __IDataFilter_FWD_DEFINED__
    __IDataFilter_FWD_DEFINED__ equ <>
    ;IDataFilter typedef IDataFilter
  endif
  ifndef __IEncodingFilterFactory_FWD_DEFINED__
    __IEncodingFilterFactory_FWD_DEFINED__ equ <>
    ;IEncodingFilterFactory typedef IEncodingFilterFactory
  endif
  ifndef __IWrappedProtocol_FWD_DEFINED__
    __IWrappedProtocol_FWD_DEFINED__ equ <>
    ;IWrappedProtocol typedef IWrappedProtocol
  endif
  ifndef __IGetBindHandle_FWD_DEFINED__
    __IGetBindHandle_FWD_DEFINED__ equ <>
    ;IGetBindHandle typedef IGetBindHandle
  endif
  ifndef __IBindCallbackRedirect_FWD_DEFINED__
    __IBindCallbackRedirect_FWD_DEFINED__ equ <>
    ;IBindCallbackRedirect typedef IBindCallbackRedirect
  endif
  ifndef __IBindHttpSecurity_FWD_DEFINED__
    __IBindHttpSecurity_FWD_DEFINED__ equ <>
    ;IBindHttpSecurity typedef IBindHttpSecurity
  endif
  include objidl.inc
  include oleidl.inc
  include servprov.inc
  include msxml.inc
  ifdef __cplusplus
    ;[...]
  endif
  include winapifamily.inc
  if _MSC_VER ge 1200
    ifndef _MSC_EXTENSIONS
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
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
    FIEF_FLAG_FORCE_JITUI equ 1h
    FIEF_FLAG_PEEK equ 2h
    FIEF_FLAG_SKIP_INSTALLED_VERSION_CHECK equ 4h
    FIEF_FLAG_RESERVED_0 equ 8h
    @DefProto DllImport, IsAsyncMoniker, WIN_STD_CALL_CONV,, <:ptr IMoniker>, 4
    @DefProto DllImport, CreateURLBinding, WIN_STD_CALL_CONV,, <:LPCWSTR, :ptr IBindCtx, :ptr ptr IBinding>, 12
    @DefProto DllImport, RegisterMediaTypes, WIN_STD_CALL_CONV,, <:UINT, :ptr LPCSTR, :ptr CLIPFORMAT>, 12
    @DefProto DllImport, FindMediaType, WIN_STD_CALL_CONV,, <:LPCSTR, :ptr CLIPFORMAT>, 8
    @DefProto DllImport, CreateFormatEnumerator, WIN_STD_CALL_CONV,, <:UINT, :ptr FORMATETC, :ptr ptr IEnumFORMATETC>, 12
    @DefProto DllImport, RegisterFormatEnumerator, WIN_STD_CALL_CONV,, <:LPBC, :ptr IEnumFORMATETC, :DWORD>, 12
    @DefProto DllImport, RevokeFormatEnumerator, WIN_STD_CALL_CONV,, <:LPBC, :ptr IEnumFORMATETC>, 8
    @DefProto DllImport, RegisterMediaTypeClass, WIN_STD_CALL_CONV,, <:LPBC, :UINT, :ptr LPCSTR, :ptr CLSID, :DWORD>, 20
    @DefProto DllImport, FindMediaTypeClass, WIN_STD_CALL_CONV,, <:LPBC, :LPCSTR, :ptr CLSID, :DWORD>, 16
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, UrlMkSetSessionOption, WIN_STD_CALL_CONV,, <:DWORD, :LPVOID, :DWORD, :DWORD>, 16
    @DefProto DllImport, UrlMkGetSessionOption, WIN_STD_CALL_CONV,, <:DWORD, :LPVOID, :DWORD, :ptr DWORD, :DWORD>, 20
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    @DefProto DllImport, FindMimeFromData, WIN_STD_CALL_CONV,, <:LPBC, :LPCWSTR, :LPVOID, :DWORD, :LPCWSTR, :DWORD, :ptr LPWSTR, :DWORD>, 32
    FMFD_DEFAULT equ 00000000h
    FMFD_URLASFILENAME equ 00000001h
    if (_WIN32_IE ge _WIN32_IE_IE60SP2)
      FMFD_ENABLEMIMESNIFFING equ 00000002h
      FMFD_IGNOREMIMETEXTPLAIN equ 00000004h
    endif
    FMFD_SERVERMIME equ 00000008h
    FMFD_RESPECTTEXTPLAIN equ 00000010h
    FMFD_RETURNUPDATEDIMGMIMES equ 00000020h
    FMFD_RESERVED_1 equ 00000040h
    UAS_EXACTLEGACY equ 00001000h
    @DefProto DllImport, ObtainUserAgentString, WIN_STD_CALL_CONV,, <:DWORD, :LPSTR, :ptr DWORD>, 12
    @DefProto DllImport, CompareSecurityIds, WIN_STD_CALL_CONV,, <:ptr BYTE, :DWORD, :ptr BYTE, :DWORD, :DWORD>, 20
    @DefProto DllImport, CompatFlagsFromClsid, WIN_STD_CALL_CONV,, <:ptr CLSID, :LPDWORD, :LPDWORD>, 12
    if (NTDDI_VERSION gt NTDDI_WINBLUE or (NTDDI_VERSION eq NTDDI_WINBLUE and Defined(WINBLUE_KBSPRING14)))
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
    URLMON_OPTION_USERAGENT equ 10000001h
    URLMON_OPTION_USERAGENT_REFRESH equ 10000002h
    URLMON_OPTION_URL_ENCODING equ 10000004h
    if (_WIN32_IE ge _WIN32_IE_IE60SP2)
      URLMON_OPTION_USE_BINDSTRINGCREDS equ 10000008h
    endif
    if (_WIN32_IE ge _WIN32_IE_IE70)
      URLMON_OPTION_USE_BROWSERAPPSDOCUMENTS equ 10000010h
    endif
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
    MK_S_ASYNCHRONOUS equ _HRESULT_TYPEDEF_(000401E8h)
    ifndef S_ASYNCHRONOUS
      S_ASYNCHRONOUS equ <MK_S_ASYNCHRONOUS>
    endif
    ifndef E_PENDING
      E_PENDING equ _HRESULT_TYPEDEF_(8000000Ah)
    endif
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
    INET_E_ERROR_FIRST equ _HRESULT_TYPEDEF_(800C0002h)
    INET_E_CODE_DOWNLOAD_DECLINED equ _HRESULT_TYPEDEF_(800C0100h)
    INET_E_RESULT_DISPATCHED equ _HRESULT_TYPEDEF_(800C0200h)
    INET_E_CANNOT_REPLACE_SFP_FILE equ _HRESULT_TYPEDEF_(800C0300h)
    if (_WIN32_IE ge _WIN32_IE_IE60SP2)
      INET_E_CODE_INSTALL_SUPPRESSED equ _HRESULT_TYPEDEF_(800C0400h)
    endif
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
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef _LPPERSISTMONIKER_DEFINED
      _LPPERSISTMONIKER_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IPersistMoniker_INTERFACE_DEFINED__
        __IPersistMoniker_INTERFACE_DEFINED__ equ <>
        LPPERSISTMONIKER typedef ptr IPersistMoniker
        externdef IID_IPersistMoniker:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          TYPE_IPersistMonikerVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IPersistMoniker, :REFIID, :ptr ptr
          PIPersistMonikerVtbl_QueryInterface typedef ptr TYPE_IPersistMonikerVtbl_QueryInterface
          TYPE_IPersistMonikerVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IPersistMoniker
          PIPersistMonikerVtbl_AddRef typedef ptr TYPE_IPersistMonikerVtbl_AddRef
          TYPE_IPersistMonikerVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IPersistMoniker
          PIPersistMonikerVtbl_Release typedef ptr TYPE_IPersistMonikerVtbl_Release
          TYPE_IPersistMonikerVtbl_GetClassID typedef proto WIN_STD_CALL_CONV :ptr IPersistMoniker, :ptr CLSID
          PIPersistMonikerVtbl_GetClassID typedef ptr TYPE_IPersistMonikerVtbl_GetClassID
          TYPE_IPersistMonikerVtbl_IsDirty typedef proto WIN_STD_CALL_CONV :ptr IPersistMoniker
          PIPersistMonikerVtbl_IsDirty typedef ptr TYPE_IPersistMonikerVtbl_IsDirty
          TYPE_IPersistMonikerVtbl_Load typedef proto WIN_STD_CALL_CONV :ptr IPersistMoniker, :BOOL, :ptr IMoniker, :LPBC, :DWORD
          PIPersistMonikerVtbl_Load typedef ptr TYPE_IPersistMonikerVtbl_Load
          TYPE_IPersistMonikerVtbl_Save typedef proto WIN_STD_CALL_CONV :ptr IPersistMoniker, :ptr IMoniker, :LPBC, :BOOL
          PIPersistMonikerVtbl_Save typedef ptr TYPE_IPersistMonikerVtbl_Save
          TYPE_IPersistMonikerVtbl_SaveCompleted typedef proto WIN_STD_CALL_CONV :ptr IPersistMoniker, :ptr IMoniker, :LPBC
          PIPersistMonikerVtbl_SaveCompleted typedef ptr TYPE_IPersistMonikerVtbl_SaveCompleted
          TYPE_IPersistMonikerVtbl_GetCurMoniker typedef proto WIN_STD_CALL_CONV :ptr IPersistMoniker, :ptr ptr IMoniker
          PIPersistMonikerVtbl_GetCurMoniker typedef ptr TYPE_IPersistMonikerVtbl_GetCurMoniker
          IPersistMonikerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IPersistMoniker>
            QueryInterface PIPersistMonikerVtbl_QueryInterface ?
            AddRef PIPersistMonikerVtbl_AddRef ?
            Release PIPersistMonikerVtbl_Release ?
            GetClassID PIPersistMonikerVtbl_GetClassID ?
            IsDirty PIPersistMonikerVtbl_IsDirty ?
            Load PIPersistMonikerVtbl_Load ?
            Save PIPersistMonikerVtbl_Save ?
            SaveCompleted PIPersistMonikerVtbl_SaveCompleted ?
            GetCurMoniker PIPersistMonikerVtbl_GetCurMoniker ?
            ??Interface equ <>
            END_INTERFACE
          IPersistMonikerVtbl ends
          IPersistMoniker struct
            lpVtbl POINTER ?
          IPersistMoniker ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    ifndef _LPMONIKERPROP_DEFINED
      _LPMONIKERPROP_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0001_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0001_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IMonikerProp_INTERFACE_DEFINED__
        __IMonikerProp_INTERFACE_DEFINED__ equ <>
        LPMONIKERPROP typedef ptr IMonikerProp
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
          TYPE_IMonikerPropVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IMonikerProp, :REFIID, :ptr ptr
          PIMonikerPropVtbl_QueryInterface typedef ptr TYPE_IMonikerPropVtbl_QueryInterface
          TYPE_IMonikerPropVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IMonikerProp
          PIMonikerPropVtbl_AddRef typedef ptr TYPE_IMonikerPropVtbl_AddRef
          TYPE_IMonikerPropVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IMonikerProp
          PIMonikerPropVtbl_Release typedef ptr TYPE_IMonikerPropVtbl_Release
          TYPE_IMonikerPropVtbl_utProperty typedef proto WIN_STD_CALL_CONV :ptr IMonikerProp, :MONIKERPROPERTY, :LPCWSTR
          PIMonikerPropVtbl_utProperty typedef ptr TYPE_IMonikerPropVtbl_utProperty
          IMonikerPropVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IMonikerProp>
            QueryInterface PIMonikerPropVtbl_QueryInterface ?
            AddRef PIMonikerPropVtbl_AddRef ?
            Release PIMonikerPropVtbl_Release ?
            utProperty PIMonikerPropVtbl_utProperty ?
            ??Interface equ <>
            END_INTERFACE
          IMonikerPropVtbl ends
          IMonikerProp struct
            lpVtbl POINTER ?
          IMonikerProp ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    ifndef _LPBINDPROTOCOL_DEFINED
      _LPBINDPROTOCOL_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0002_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0002_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IBindProtocol_INTERFACE_DEFINED__
        __IBindProtocol_INTERFACE_DEFINED__ equ <>
        LPBINDPROTOCOL typedef ptr IBindProtocol
        externdef IID_IBindProtocol:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          TYPE_IBindProtocolVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IBindProtocol, :REFIID, :ptr ptr
          PIBindProtocolVtbl_QueryInterface typedef ptr TYPE_IBindProtocolVtbl_QueryInterface
          TYPE_IBindProtocolVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IBindProtocol
          PIBindProtocolVtbl_AddRef typedef ptr TYPE_IBindProtocolVtbl_AddRef
          TYPE_IBindProtocolVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IBindProtocol
          PIBindProtocolVtbl_Release typedef ptr TYPE_IBindProtocolVtbl_Release
          TYPE_IBindProtocolVtbl_CreateBinding typedef proto WIN_STD_CALL_CONV :ptr IBindProtocol, :LPCWSTR, :ptr IBindCtx, :ptr ptr IBinding
          PIBindProtocolVtbl_CreateBinding typedef ptr TYPE_IBindProtocolVtbl_CreateBinding
          IBindProtocolVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IBindProtocol>
            QueryInterface PIBindProtocolVtbl_QueryInterface ?
            AddRef PIBindProtocolVtbl_AddRef ?
            Release PIBindProtocolVtbl_Release ?
            CreateBinding PIBindProtocolVtbl_CreateBinding ?
            ??Interface equ <>
            END_INTERFACE
          IBindProtocolVtbl ends
          IBindProtocol struct
            lpVtbl POINTER ?
          IBindProtocol ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    ifndef _LPBINDING_DEFINED
      _LPBINDING_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0003_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0003_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IBinding_INTERFACE_DEFINED__
        __IBinding_INTERFACE_DEFINED__ equ <>
        LPBINDING typedef ptr IBinding
        externdef IID_IBinding:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          TYPE_IBindingVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IBinding, :REFIID, :ptr ptr
          PIBindingVtbl_QueryInterface typedef ptr TYPE_IBindingVtbl_QueryInterface
          TYPE_IBindingVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IBinding
          PIBindingVtbl_AddRef typedef ptr TYPE_IBindingVtbl_AddRef
          TYPE_IBindingVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IBinding
          PIBindingVtbl_Release typedef ptr TYPE_IBindingVtbl_Release
          TYPE_IBindingVtbl_Abort typedef proto WIN_STD_CALL_CONV :ptr IBinding
          PIBindingVtbl_Abort typedef ptr TYPE_IBindingVtbl_Abort
          TYPE_IBindingVtbl_Suspend typedef proto WIN_STD_CALL_CONV :ptr IBinding
          PIBindingVtbl_Suspend typedef ptr TYPE_IBindingVtbl_Suspend
          TYPE_IBindingVtbl_Resume typedef proto WIN_STD_CALL_CONV :ptr IBinding
          PIBindingVtbl_Resume typedef ptr TYPE_IBindingVtbl_Resume
          TYPE_IBindingVtbl_SetPriority typedef proto WIN_STD_CALL_CONV :ptr IBinding, :LONG
          PIBindingVtbl_SetPriority typedef ptr TYPE_IBindingVtbl_SetPriority
          TYPE_IBindingVtbl_GetPriority typedef proto WIN_STD_CALL_CONV :ptr IBinding, :ptr LONG
          PIBindingVtbl_GetPriority typedef ptr TYPE_IBindingVtbl_GetPriority
          TYPE_IBindingVtbl_GetBindResult typedef proto WIN_STD_CALL_CONV :ptr IBinding, :ptr CLSID, :ptr DWORD, :ptr LPOLESTR, :ptr DWORD
          PIBindingVtbl_GetBindResult typedef ptr TYPE_IBindingVtbl_GetBindResult
          IBindingVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IBinding>
            QueryInterface PIBindingVtbl_QueryInterface ?
            AddRef PIBindingVtbl_AddRef ?
            Release PIBindingVtbl_Release ?
            Abort PIBindingVtbl_Abort ?
            Suspend PIBindingVtbl_Suspend ?
            Resume PIBindingVtbl_Resume ?
            SetPriority PIBindingVtbl_SetPriority ?
            GetPriority PIBindingVtbl_GetPriority ?
            GetBindResult PIBindingVtbl_GetBindResult ?
            ??Interface equ <>
            END_INTERFACE
          IBindingVtbl ends
          IBinding struct
            lpVtbl POINTER ?
          IBinding ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
        IBinding_RemoteGetBindResult_Proxy proto WIN_STD_CALL_CONV :ptr IBinding, :ptr CLSID, :ptr DWORD, :ptr LPOLESTR, :DWORD
        IBinding_RemoteGetBindResult_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    ifndef _LPBINDSTATUSCALLBACK_DEFINED
      _LPBINDSTATUSCALLBACK_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0004_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0004_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IBindStatusCallback_INTERFACE_DEFINED__
        __IBindStatusCallback_INTERFACE_DEFINED__ equ <>
        LPBINDSTATUSCALLBACK typedef ptr IBindStatusCallback
        BINDVERB typedef SDWORD
        BINDVERB_GET equ 0
        BINDVERB_POST equ 1h
        BINDVERB_PUT equ 2h
        BINDVERB_CUSTOM equ 3h
        BINDVERB_RESERVED1 equ 4h
        __MIDL_IBindStatusCallback_0001 typedef BINDVERB
        BINDINFOF typedef SDWORD
        BINDINFOF_URLENCODESTGMEDDATA equ 1h
        BINDINFOF_URLENCODEDEXTRAINFO equ 2h
        __MIDL_IBindStatusCallback_0002 typedef BINDINFOF
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
        URL_ENCODING typedef SDWORD
        URL_ENCODING_NONE equ 0
        URL_ENCODING_ENABLE_UTF8 equ 10000000h
        URL_ENCODING_DISABLE_UTF8 equ 20000000h
        __MIDL_IBindStatusCallback_0004 typedef URL_ENCODING
        BINDINFO struct
          cbSize ULONG ?
          szExtraInfo LPWSTR ?
          stgmedData STGMEDIUM <>
          grfBindInfoF DWORD ?
          dwBindVerb DWORD ?
          szCustomVerb LPWSTR ?
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
          bInheritHandle BOOL ?
        REMSECURITY_ATTRIBUTES ends
        _REMSECURITY_ATTRIBUTES typedef REMSECURITY_ATTRIBUTES
        PREMSECURITY_ATTRIBUTES typedef ptr _REMSECURITY_ATTRIBUTES
        LPREMSECURITY_ATTRIBUTES typedef ptr _REMSECURITY_ATTRIBUTES
        RemBINDINFO struct
          cbSize ULONG ?
          szExtraInfo LPWSTR ?
          grfBindInfoF DWORD ?
          dwBindVerb DWORD ?
          szCustomVerb LPWSTR ?
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
          lindex LONG ?
          tymed DWORD ?
        RemFORMATETC ends
        tagRemFORMATETC typedef RemFORMATETC
        LPREMFORMATETC typedef ptr tagRemFORMATETC
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
        BINDSTATUS_LAST_PRIVATE equ BINDSTATUS_RESERVED_13
        tagBINDSTATUS typedef BINDSTATUS
        externdef IID_IBindStatusCallback:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          TYPE_IBindStatusCallbackVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IBindStatusCallback, :REFIID, :ptr ptr
          PIBindStatusCallbackVtbl_QueryInterface typedef ptr TYPE_IBindStatusCallbackVtbl_QueryInterface
          TYPE_IBindStatusCallbackVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IBindStatusCallback
          PIBindStatusCallbackVtbl_AddRef typedef ptr TYPE_IBindStatusCallbackVtbl_AddRef
          TYPE_IBindStatusCallbackVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IBindStatusCallback
          PIBindStatusCallbackVtbl_Release typedef ptr TYPE_IBindStatusCallbackVtbl_Release
          TYPE_IBindStatusCallbackVtbl_OnStartBinding typedef proto WIN_STD_CALL_CONV :ptr IBindStatusCallback, :DWORD, :ptr IBinding
          PIBindStatusCallbackVtbl_OnStartBinding typedef ptr TYPE_IBindStatusCallbackVtbl_OnStartBinding
          TYPE_IBindStatusCallbackVtbl_GetPriority typedef proto WIN_STD_CALL_CONV :ptr IBindStatusCallback, :ptr LONG
          PIBindStatusCallbackVtbl_GetPriority typedef ptr TYPE_IBindStatusCallbackVtbl_GetPriority
          TYPE_IBindStatusCallbackVtbl_OnLowResource typedef proto WIN_STD_CALL_CONV :ptr IBindStatusCallback, :DWORD
          PIBindStatusCallbackVtbl_OnLowResource typedef ptr TYPE_IBindStatusCallbackVtbl_OnLowResource
          TYPE_IBindStatusCallbackVtbl_OnProgress typedef proto WIN_STD_CALL_CONV :ptr IBindStatusCallback, :ULONG, :ULONG, :ULONG, :LPCWSTR
          PIBindStatusCallbackVtbl_OnProgress typedef ptr TYPE_IBindStatusCallbackVtbl_OnProgress
          TYPE_IBindStatusCallbackVtbl_OnStopBinding typedef proto WIN_STD_CALL_CONV :ptr IBindStatusCallback, :HRESULT, :LPCWSTR
          PIBindStatusCallbackVtbl_OnStopBinding typedef ptr TYPE_IBindStatusCallbackVtbl_OnStopBinding
          TYPE_IBindStatusCallbackVtbl_GetBindInfo typedef proto WIN_STD_CALL_CONV :ptr IBindStatusCallback, :ptr DWORD, :ptr BINDINFO
          PIBindStatusCallbackVtbl_GetBindInfo typedef ptr TYPE_IBindStatusCallbackVtbl_GetBindInfo
          TYPE_IBindStatusCallbackVtbl_OnDataAvailable typedef proto WIN_STD_CALL_CONV :ptr IBindStatusCallback, :DWORD, :DWORD, :ptr FORMATETC, :ptr STGMEDIUM
          PIBindStatusCallbackVtbl_OnDataAvailable typedef ptr TYPE_IBindStatusCallbackVtbl_OnDataAvailable
          TYPE_IBindStatusCallbackVtbl_OnObjectAvailable typedef proto WIN_STD_CALL_CONV :ptr IBindStatusCallback, :REFIID, :ptr IUnknown
          PIBindStatusCallbackVtbl_OnObjectAvailable typedef ptr TYPE_IBindStatusCallbackVtbl_OnObjectAvailable
          IBindStatusCallbackVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IBindStatusCallback>
            QueryInterface PIBindStatusCallbackVtbl_QueryInterface ?
            AddRef PIBindStatusCallbackVtbl_AddRef ?
            Release PIBindStatusCallbackVtbl_Release ?
            OnStartBinding PIBindStatusCallbackVtbl_OnStartBinding ?
            GetPriority PIBindStatusCallbackVtbl_GetPriority ?
            OnLowResource PIBindStatusCallbackVtbl_OnLowResource ?
            OnProgress PIBindStatusCallbackVtbl_OnProgress ?
            OnStopBinding PIBindStatusCallbackVtbl_OnStopBinding ?
            GetBindInfo PIBindStatusCallbackVtbl_GetBindInfo ?
            OnDataAvailable PIBindStatusCallbackVtbl_OnDataAvailable ?
            OnObjectAvailable PIBindStatusCallbackVtbl_OnObjectAvailable ?
            ??Interface equ <>
            END_INTERFACE
          IBindStatusCallbackVtbl ends
          IBindStatusCallback struct
            lpVtbl POINTER ?
          IBindStatusCallback ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
        IBindStatusCallback_RemoteGetBindInfo_Proxy proto WIN_STD_CALL_CONV :ptr IBindStatusCallback, :ptr DWORD, :ptr RemBINDINFO, :ptr RemSTGMEDIUM
        IBindStatusCallback_RemoteGetBindInfo_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        IBindStatusCallback_RemoteOnDataAvailable_Proxy proto WIN_STD_CALL_CONV :ptr IBindStatusCallback, :DWORD, :DWORD, :ptr RemFORMATETC, :ptr RemSTGMEDIUM
        IBindStatusCallback_RemoteOnDataAvailable_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef _LPBINDSTATUSCALLBACKEX_DEFINED
      _LPBINDSTATUSCALLBACKEX_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0005_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0005_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IBindStatusCallbackEx_INTERFACE_DEFINED__
        __IBindStatusCallbackEx_INTERFACE_DEFINED__ equ <>
        LPBINDSTATUSCALLBACKEX typedef ptr IBindStatusCallbackEx
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
          TYPE_IBindStatusCallbackExVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IBindStatusCallbackEx, :REFIID, :ptr ptr
          PIBindStatusCallbackExVtbl_QueryInterface typedef ptr TYPE_IBindStatusCallbackExVtbl_QueryInterface
          TYPE_IBindStatusCallbackExVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IBindStatusCallbackEx
          PIBindStatusCallbackExVtbl_AddRef typedef ptr TYPE_IBindStatusCallbackExVtbl_AddRef
          TYPE_IBindStatusCallbackExVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IBindStatusCallbackEx
          PIBindStatusCallbackExVtbl_Release typedef ptr TYPE_IBindStatusCallbackExVtbl_Release
          TYPE_IBindStatusCallbackExVtbl_OnStartBinding typedef proto WIN_STD_CALL_CONV :ptr IBindStatusCallbackEx, :DWORD, :ptr IBinding
          PIBindStatusCallbackExVtbl_OnStartBinding typedef ptr TYPE_IBindStatusCallbackExVtbl_OnStartBinding
          TYPE_IBindStatusCallbackExVtbl_GetPriority typedef proto WIN_STD_CALL_CONV :ptr IBindStatusCallbackEx, :ptr LONG
          PIBindStatusCallbackExVtbl_GetPriority typedef ptr TYPE_IBindStatusCallbackExVtbl_GetPriority
          TYPE_IBindStatusCallbackExVtbl_OnLowResource typedef proto WIN_STD_CALL_CONV :ptr IBindStatusCallbackEx, :DWORD
          PIBindStatusCallbackExVtbl_OnLowResource typedef ptr TYPE_IBindStatusCallbackExVtbl_OnLowResource
          TYPE_IBindStatusCallbackExVtbl_OnProgress typedef proto WIN_STD_CALL_CONV :ptr IBindStatusCallbackEx, :ULONG, :ULONG, :ULONG, :LPCWSTR
          PIBindStatusCallbackExVtbl_OnProgress typedef ptr TYPE_IBindStatusCallbackExVtbl_OnProgress
          TYPE_IBindStatusCallbackExVtbl_OnStopBinding typedef proto WIN_STD_CALL_CONV :ptr IBindStatusCallbackEx, :HRESULT, :LPCWSTR
          PIBindStatusCallbackExVtbl_OnStopBinding typedef ptr TYPE_IBindStatusCallbackExVtbl_OnStopBinding
          TYPE_IBindStatusCallbackExVtbl_GetBindInfo typedef proto WIN_STD_CALL_CONV :ptr IBindStatusCallbackEx, :ptr DWORD, :ptr BINDINFO
          PIBindStatusCallbackExVtbl_GetBindInfo typedef ptr TYPE_IBindStatusCallbackExVtbl_GetBindInfo
          TYPE_IBindStatusCallbackExVtbl_OnDataAvailable typedef proto WIN_STD_CALL_CONV :ptr IBindStatusCallbackEx, :DWORD, :DWORD, :ptr FORMATETC, :ptr STGMEDIUM
          PIBindStatusCallbackExVtbl_OnDataAvailable typedef ptr TYPE_IBindStatusCallbackExVtbl_OnDataAvailable
          TYPE_IBindStatusCallbackExVtbl_OnObjectAvailable typedef proto WIN_STD_CALL_CONV :ptr IBindStatusCallbackEx, :REFIID, :ptr IUnknown
          PIBindStatusCallbackExVtbl_OnObjectAvailable typedef ptr TYPE_IBindStatusCallbackExVtbl_OnObjectAvailable
          TYPE_IBindStatusCallbackExVtbl_GetBindInfoEx typedef proto WIN_STD_CALL_CONV :ptr IBindStatusCallbackEx, :ptr DWORD, :ptr BINDINFO, :ptr DWORD, :ptr DWORD
          PIBindStatusCallbackExVtbl_GetBindInfoEx typedef ptr TYPE_IBindStatusCallbackExVtbl_GetBindInfoEx
          IBindStatusCallbackExVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IBindStatusCallbackEx>
            QueryInterface PIBindStatusCallbackExVtbl_QueryInterface ?
            AddRef PIBindStatusCallbackExVtbl_AddRef ?
            Release PIBindStatusCallbackExVtbl_Release ?
            OnStartBinding PIBindStatusCallbackExVtbl_OnStartBinding ?
            GetPriority PIBindStatusCallbackExVtbl_GetPriority ?
            OnLowResource PIBindStatusCallbackExVtbl_OnLowResource ?
            OnProgress PIBindStatusCallbackExVtbl_OnProgress ?
            OnStopBinding PIBindStatusCallbackExVtbl_OnStopBinding ?
            GetBindInfo PIBindStatusCallbackExVtbl_GetBindInfo ?
            OnDataAvailable PIBindStatusCallbackExVtbl_OnDataAvailable ?
            OnObjectAvailable PIBindStatusCallbackExVtbl_OnObjectAvailable ?
            GetBindInfoEx PIBindStatusCallbackExVtbl_GetBindInfoEx ?
            ??Interface equ <>
            END_INTERFACE
          IBindStatusCallbackExVtbl ends
          IBindStatusCallbackEx struct
            lpVtbl POINTER ?
          IBindStatusCallbackEx ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
        IBindStatusCallbackEx_RemoteGetBindInfoEx_Proxy proto WIN_STD_CALL_CONV :ptr IBindStatusCallbackEx, :ptr DWORD, :ptr RemBINDINFO, :ptr RemSTGMEDIUM, :ptr DWORD, :ptr DWORD
        IBindStatusCallbackEx_RemoteGetBindInfoEx_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      endif
    endif
    ifndef _LPAUTHENTICATION_DEFINED
      _LPAUTHENTICATION_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0006_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0006_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IAuthenticate_INTERFACE_DEFINED__
        __IAuthenticate_INTERFACE_DEFINED__ equ <>
        LPAUTHENTICATION typedef ptr IAuthenticate
        externdef IID_IAuthenticate:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          TYPE_IAuthenticateVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IAuthenticate, :REFIID, :ptr ptr
          PIAuthenticateVtbl_QueryInterface typedef ptr TYPE_IAuthenticateVtbl_QueryInterface
          TYPE_IAuthenticateVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IAuthenticate
          PIAuthenticateVtbl_AddRef typedef ptr TYPE_IAuthenticateVtbl_AddRef
          TYPE_IAuthenticateVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IAuthenticate
          PIAuthenticateVtbl_Release typedef ptr TYPE_IAuthenticateVtbl_Release
          TYPE_IAuthenticateVtbl_Authenticate typedef proto WIN_STD_CALL_CONV :ptr IAuthenticate, :ptr HWND, :ptr LPWSTR, :ptr LPWSTR
          PIAuthenticateVtbl_Authenticate typedef ptr TYPE_IAuthenticateVtbl_Authenticate
          IAuthenticateVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IAuthenticate>
            QueryInterface PIAuthenticateVtbl_QueryInterface ?
            AddRef PIAuthenticateVtbl_AddRef ?
            Release PIAuthenticateVtbl_Release ?
            Authenticate PIAuthenticateVtbl_Authenticate ?
            ??Interface equ <>
            END_INTERFACE
          IAuthenticateVtbl ends
          IAuthenticate struct
            lpVtbl POINTER ?
          IAuthenticate ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    ifndef _LPAUTHENTICATIONEX_DEFINED
      _LPAUTHENTICATIONEX_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0007_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0007_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IAuthenticateEx_INTERFACE_DEFINED__
        __IAuthenticateEx_INTERFACE_DEFINED__ equ <>
        LPAUTHENTICATIONEX typedef ptr IAuthenticateEx
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
          TYPE_IAuthenticateExVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IAuthenticateEx, :REFIID, :ptr ptr
          PIAuthenticateExVtbl_QueryInterface typedef ptr TYPE_IAuthenticateExVtbl_QueryInterface
          TYPE_IAuthenticateExVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IAuthenticateEx
          PIAuthenticateExVtbl_AddRef typedef ptr TYPE_IAuthenticateExVtbl_AddRef
          TYPE_IAuthenticateExVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IAuthenticateEx
          PIAuthenticateExVtbl_Release typedef ptr TYPE_IAuthenticateExVtbl_Release
          TYPE_IAuthenticateExVtbl_Authenticate typedef proto WIN_STD_CALL_CONV :ptr IAuthenticateEx, :ptr HWND, :ptr LPWSTR, :ptr LPWSTR
          PIAuthenticateExVtbl_Authenticate typedef ptr TYPE_IAuthenticateExVtbl_Authenticate
          TYPE_IAuthenticateExVtbl_AuthenticateEx typedef proto WIN_STD_CALL_CONV :ptr IAuthenticateEx, :ptr HWND, :ptr LPWSTR, :ptr LPWSTR, :ptr AUTHENTICATEINFO
          PIAuthenticateExVtbl_AuthenticateEx typedef ptr TYPE_IAuthenticateExVtbl_AuthenticateEx
          IAuthenticateExVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IAuthenticateEx>
            QueryInterface PIAuthenticateExVtbl_QueryInterface ?
            AddRef PIAuthenticateExVtbl_AddRef ?
            Release PIAuthenticateExVtbl_Release ?
            Authenticate PIAuthenticateExVtbl_Authenticate ?
            AuthenticateEx PIAuthenticateExVtbl_AuthenticateEx ?
            ??Interface equ <>
            END_INTERFACE
          IAuthenticateExVtbl ends
          IAuthenticateEx struct
            lpVtbl POINTER ?
          IAuthenticateEx ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    ifndef _LPHTTPNEGOTIATE_DEFINED
      _LPHTTPNEGOTIATE_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0008_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0008_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IHttpNegotiate_INTERFACE_DEFINED__
        __IHttpNegotiate_INTERFACE_DEFINED__ equ <>
        LPHTTPNEGOTIATE typedef ptr IHttpNegotiate
        externdef IID_IHttpNegotiate:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          TYPE_IHttpNegotiateVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IHttpNegotiate, :REFIID, :ptr ptr
          PIHttpNegotiateVtbl_QueryInterface typedef ptr TYPE_IHttpNegotiateVtbl_QueryInterface
          TYPE_IHttpNegotiateVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IHttpNegotiate
          PIHttpNegotiateVtbl_AddRef typedef ptr TYPE_IHttpNegotiateVtbl_AddRef
          TYPE_IHttpNegotiateVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IHttpNegotiate
          PIHttpNegotiateVtbl_Release typedef ptr TYPE_IHttpNegotiateVtbl_Release
          TYPE_IHttpNegotiateVtbl_BeginningTransaction typedef proto WIN_STD_CALL_CONV :ptr IHttpNegotiate, :LPCWSTR, :LPCWSTR, :DWORD, :ptr LPWSTR
          PIHttpNegotiateVtbl_BeginningTransaction typedef ptr TYPE_IHttpNegotiateVtbl_BeginningTransaction
          TYPE_IHttpNegotiateVtbl_OnResponse typedef proto WIN_STD_CALL_CONV :ptr IHttpNegotiate, :DWORD, :LPCWSTR, :LPCWSTR, :ptr LPWSTR
          PIHttpNegotiateVtbl_OnResponse typedef ptr TYPE_IHttpNegotiateVtbl_OnResponse
          IHttpNegotiateVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IHttpNegotiate>
            QueryInterface PIHttpNegotiateVtbl_QueryInterface ?
            AddRef PIHttpNegotiateVtbl_AddRef ?
            Release PIHttpNegotiateVtbl_Release ?
            BeginningTransaction PIHttpNegotiateVtbl_BeginningTransaction ?
            OnResponse PIHttpNegotiateVtbl_OnResponse ?
            ??Interface equ <>
            END_INTERFACE
          IHttpNegotiateVtbl ends
          IHttpNegotiate struct
            lpVtbl POINTER ?
          IHttpNegotiate ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    ifndef _LPHTTPNEGOTIATE2_DEFINED
      _LPHTTPNEGOTIATE2_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0009_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0009_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IHttpNegotiate2_INTERFACE_DEFINED__
        __IHttpNegotiate2_INTERFACE_DEFINED__ equ <>
        LPHTTPNEGOTIATE2 typedef ptr IHttpNegotiate2
        externdef IID_IHttpNegotiate2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          TYPE_IHttpNegotiate2Vtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IHttpNegotiate2, :REFIID, :ptr ptr
          PIHttpNegotiate2Vtbl_QueryInterface typedef ptr TYPE_IHttpNegotiate2Vtbl_QueryInterface
          TYPE_IHttpNegotiate2Vtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IHttpNegotiate2
          PIHttpNegotiate2Vtbl_AddRef typedef ptr TYPE_IHttpNegotiate2Vtbl_AddRef
          TYPE_IHttpNegotiate2Vtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IHttpNegotiate2
          PIHttpNegotiate2Vtbl_Release typedef ptr TYPE_IHttpNegotiate2Vtbl_Release
          TYPE_IHttpNegotiate2Vtbl_BeginningTransaction typedef proto WIN_STD_CALL_CONV :ptr IHttpNegotiate2, :LPCWSTR, :LPCWSTR, :DWORD, :ptr LPWSTR
          PIHttpNegotiate2Vtbl_BeginningTransaction typedef ptr TYPE_IHttpNegotiate2Vtbl_BeginningTransaction
          TYPE_IHttpNegotiate2Vtbl_OnResponse typedef proto WIN_STD_CALL_CONV :ptr IHttpNegotiate2, :DWORD, :LPCWSTR, :LPCWSTR, :ptr LPWSTR
          PIHttpNegotiate2Vtbl_OnResponse typedef ptr TYPE_IHttpNegotiate2Vtbl_OnResponse
          TYPE_IHttpNegotiate2Vtbl_GetRootSecurityId typedef proto WIN_STD_CALL_CONV :ptr IHttpNegotiate2, :ptr BYTE, :ptr DWORD, :DWORD_PTR
          PIHttpNegotiate2Vtbl_GetRootSecurityId typedef ptr TYPE_IHttpNegotiate2Vtbl_GetRootSecurityId
          IHttpNegotiate2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IHttpNegotiate2>
            QueryInterface PIHttpNegotiate2Vtbl_QueryInterface ?
            AddRef PIHttpNegotiate2Vtbl_AddRef ?
            Release PIHttpNegotiate2Vtbl_Release ?
            BeginningTransaction PIHttpNegotiate2Vtbl_BeginningTransaction ?
            OnResponse PIHttpNegotiate2Vtbl_OnResponse ?
            GetRootSecurityId PIHttpNegotiate2Vtbl_GetRootSecurityId ?
            ??Interface equ <>
            END_INTERFACE
          IHttpNegotiate2Vtbl ends
          IHttpNegotiate2 struct
            lpVtbl POINTER ?
          IHttpNegotiate2 ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    ifndef _LPHTTPNEGOTIATE3_DEFINED
      _LPHTTPNEGOTIATE3_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0010_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0010_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IHttpNegotiate3_INTERFACE_DEFINED__
        __IHttpNegotiate3_INTERFACE_DEFINED__ equ <>
        LPHTTPNEGOTIATE3 typedef ptr IHttpNegotiate3
        externdef IID_IHttpNegotiate3:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          TYPE_IHttpNegotiate3Vtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IHttpNegotiate3, :REFIID, :ptr ptr
          PIHttpNegotiate3Vtbl_QueryInterface typedef ptr TYPE_IHttpNegotiate3Vtbl_QueryInterface
          TYPE_IHttpNegotiate3Vtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IHttpNegotiate3
          PIHttpNegotiate3Vtbl_AddRef typedef ptr TYPE_IHttpNegotiate3Vtbl_AddRef
          TYPE_IHttpNegotiate3Vtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IHttpNegotiate3
          PIHttpNegotiate3Vtbl_Release typedef ptr TYPE_IHttpNegotiate3Vtbl_Release
          TYPE_IHttpNegotiate3Vtbl_BeginningTransaction typedef proto WIN_STD_CALL_CONV :ptr IHttpNegotiate3, :LPCWSTR, :LPCWSTR, :DWORD, :ptr LPWSTR
          PIHttpNegotiate3Vtbl_BeginningTransaction typedef ptr TYPE_IHttpNegotiate3Vtbl_BeginningTransaction
          TYPE_IHttpNegotiate3Vtbl_OnResponse typedef proto WIN_STD_CALL_CONV :ptr IHttpNegotiate3, :DWORD, :LPCWSTR, :LPCWSTR, :ptr LPWSTR
          PIHttpNegotiate3Vtbl_OnResponse typedef ptr TYPE_IHttpNegotiate3Vtbl_OnResponse
          TYPE_IHttpNegotiate3Vtbl_GetRootSecurityId typedef proto WIN_STD_CALL_CONV :ptr IHttpNegotiate3, :ptr BYTE, :ptr DWORD, :DWORD_PTR
          PIHttpNegotiate3Vtbl_GetRootSecurityId typedef ptr TYPE_IHttpNegotiate3Vtbl_GetRootSecurityId
          TYPE_IHttpNegotiate3Vtbl_GetSerializedClientCertContext typedef proto WIN_STD_CALL_CONV :ptr IHttpNegotiate3, :ptr ptr BYTE, :ptr DWORD
          PIHttpNegotiate3Vtbl_GetSerializedClientCertContext typedef ptr TYPE_IHttpNegotiate3Vtbl_GetSerializedClientCertContext
          IHttpNegotiate3Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IHttpNegotiate3>
            QueryInterface PIHttpNegotiate3Vtbl_QueryInterface ?
            AddRef PIHttpNegotiate3Vtbl_AddRef ?
            Release PIHttpNegotiate3Vtbl_Release ?
            BeginningTransaction PIHttpNegotiate3Vtbl_BeginningTransaction ?
            OnResponse PIHttpNegotiate3Vtbl_OnResponse ?
            GetRootSecurityId PIHttpNegotiate3Vtbl_GetRootSecurityId ?
            GetSerializedClientCertContext PIHttpNegotiate3Vtbl_GetSerializedClientCertContext ?
            ??Interface equ <>
            END_INTERFACE
          IHttpNegotiate3Vtbl ends
          IHttpNegotiate3 struct
            lpVtbl POINTER ?
          IHttpNegotiate3 ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    ifndef _LPWININETFILESTREAM_DEFINED
      _LPWININETFILESTREAM_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0011_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0011_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IWinInetFileStream_INTERFACE_DEFINED__
        __IWinInetFileStream_INTERFACE_DEFINED__ equ <>
        LPWININETFILESTREAM typedef ptr IWinInetFileStream
        externdef IID_IWinInetFileStream:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          TYPE_IWinInetFileStreamVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IWinInetFileStream, :REFIID, :ptr ptr
          PIWinInetFileStreamVtbl_QueryInterface typedef ptr TYPE_IWinInetFileStreamVtbl_QueryInterface
          TYPE_IWinInetFileStreamVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IWinInetFileStream
          PIWinInetFileStreamVtbl_AddRef typedef ptr TYPE_IWinInetFileStreamVtbl_AddRef
          TYPE_IWinInetFileStreamVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IWinInetFileStream
          PIWinInetFileStreamVtbl_Release typedef ptr TYPE_IWinInetFileStreamVtbl_Release
          TYPE_IWinInetFileStreamVtbl_SetHandleForUnlock typedef proto WIN_STD_CALL_CONV :ptr IWinInetFileStream, :DWORD_PTR, :DWORD_PTR
          PIWinInetFileStreamVtbl_SetHandleForUnlock typedef ptr TYPE_IWinInetFileStreamVtbl_SetHandleForUnlock
          TYPE_IWinInetFileStreamVtbl_SetDeleteFile typedef proto WIN_STD_CALL_CONV :ptr IWinInetFileStream, :DWORD_PTR
          PIWinInetFileStreamVtbl_SetDeleteFile typedef ptr TYPE_IWinInetFileStreamVtbl_SetDeleteFile
          IWinInetFileStreamVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IWinInetFileStream>
            QueryInterface PIWinInetFileStreamVtbl_QueryInterface ?
            AddRef PIWinInetFileStreamVtbl_AddRef ?
            Release PIWinInetFileStreamVtbl_Release ?
            SetHandleForUnlock PIWinInetFileStreamVtbl_SetHandleForUnlock ?
            SetDeleteFile PIWinInetFileStreamVtbl_SetDeleteFile ?
            ??Interface equ <>
            END_INTERFACE
          IWinInetFileStreamVtbl ends
          IWinInetFileStream struct
            lpVtbl POINTER ?
          IWinInetFileStream ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    ifndef _LPWINDOWFORBINDINGUI_DEFINED
      _LPWINDOWFORBINDINGUI_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0012_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0012_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IWindowForBindingUI_INTERFACE_DEFINED__
        __IWindowForBindingUI_INTERFACE_DEFINED__ equ <>
        LPWINDOWFORBINDINGUI typedef ptr IWindowForBindingUI
        externdef IID_IWindowForBindingUI:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          TYPE_IWindowForBindingUIVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IWindowForBindingUI, :REFIID, :ptr ptr
          PIWindowForBindingUIVtbl_QueryInterface typedef ptr TYPE_IWindowForBindingUIVtbl_QueryInterface
          TYPE_IWindowForBindingUIVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IWindowForBindingUI
          PIWindowForBindingUIVtbl_AddRef typedef ptr TYPE_IWindowForBindingUIVtbl_AddRef
          TYPE_IWindowForBindingUIVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IWindowForBindingUI
          PIWindowForBindingUIVtbl_Release typedef ptr TYPE_IWindowForBindingUIVtbl_Release
          TYPE_IWindowForBindingUIVtbl_GetWindow typedef proto WIN_STD_CALL_CONV :ptr IWindowForBindingUI, :REFGUID, :ptr HWND
          PIWindowForBindingUIVtbl_GetWindow typedef ptr TYPE_IWindowForBindingUIVtbl_GetWindow
          IWindowForBindingUIVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IWindowForBindingUI>
            QueryInterface PIWindowForBindingUIVtbl_QueryInterface ?
            AddRef PIWindowForBindingUIVtbl_AddRef ?
            Release PIWindowForBindingUIVtbl_Release ?
            GetWindow PIWindowForBindingUIVtbl_GetWindow ?
            ??Interface equ <>
            END_INTERFACE
          IWindowForBindingUIVtbl ends
          IWindowForBindingUI struct
            lpVtbl POINTER ?
          IWindowForBindingUI ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    ifndef _LPCODEINSTALL_DEFINED
      _LPCODEINSTALL_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0013_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0013_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ICodeInstall_INTERFACE_DEFINED__
        __ICodeInstall_INTERFACE_DEFINED__ equ <>
        LPCODEINSTALL typedef ptr ICodeInstall
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
          TYPE_ICodeInstallVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr ICodeInstall, :REFIID, :ptr ptr
          PICodeInstallVtbl_QueryInterface typedef ptr TYPE_ICodeInstallVtbl_QueryInterface
          TYPE_ICodeInstallVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr ICodeInstall
          PICodeInstallVtbl_AddRef typedef ptr TYPE_ICodeInstallVtbl_AddRef
          TYPE_ICodeInstallVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr ICodeInstall
          PICodeInstallVtbl_Release typedef ptr TYPE_ICodeInstallVtbl_Release
          TYPE_ICodeInstallVtbl_GetWindow typedef proto WIN_STD_CALL_CONV :ptr ICodeInstall, :REFGUID, :ptr HWND
          PICodeInstallVtbl_GetWindow typedef ptr TYPE_ICodeInstallVtbl_GetWindow
          TYPE_ICodeInstallVtbl_OnCodeInstallProblem typedef proto WIN_STD_CALL_CONV :ptr ICodeInstall, :ULONG, :LPCWSTR, :LPCWSTR, :DWORD
          PICodeInstallVtbl_OnCodeInstallProblem typedef ptr TYPE_ICodeInstallVtbl_OnCodeInstallProblem
          ICodeInstallVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ICodeInstall>
            QueryInterface PICodeInstallVtbl_QueryInterface ?
            AddRef PICodeInstallVtbl_AddRef ?
            Release PICodeInstallVtbl_Release ?
            GetWindow PICodeInstallVtbl_GetWindow ?
            OnCodeInstallProblem PICodeInstallVtbl_OnCodeInstallProblem ?
            ??Interface equ <>
            END_INTERFACE
          ICodeInstallVtbl ends
          ICodeInstall struct
            lpVtbl POINTER ?
          ICodeInstall ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
  endif
  if (_WIN32_IE ge _WIN32_IE_IE70)
    ifndef _LPUri_DEFINED
      _LPUri_DEFINED equ <>
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        externdef __MIDL_itf_urlmon_0000_0014_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0014_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IUri_INTERFACE_DEFINED__
          __IUri_INTERFACE_DEFINED__ equ <>
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
            TYPE_IUriVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IUri, :REFIID, :ptr ptr
            PIUriVtbl_QueryInterface typedef ptr TYPE_IUriVtbl_QueryInterface
            TYPE_IUriVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IUri
            PIUriVtbl_AddRef typedef ptr TYPE_IUriVtbl_AddRef
            TYPE_IUriVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IUri
            PIUriVtbl_Release typedef ptr TYPE_IUriVtbl_Release
            TYPE_IUriVtbl_GetPropertyBSTR typedef proto WIN_STD_CALL_CONV :ptr IUri, :Uri_PROPERTY, :ptr BSTR, :DWORD
            PIUriVtbl_GetPropertyBSTR typedef ptr TYPE_IUriVtbl_GetPropertyBSTR
            TYPE_IUriVtbl_GetPropertyLength typedef proto WIN_STD_CALL_CONV :ptr IUri, :Uri_PROPERTY, :ptr DWORD, :DWORD
            PIUriVtbl_GetPropertyLength typedef ptr TYPE_IUriVtbl_GetPropertyLength
            TYPE_IUriVtbl_GetPropertyDWORD typedef proto WIN_STD_CALL_CONV :ptr IUri, :Uri_PROPERTY, :ptr DWORD, :DWORD
            PIUriVtbl_GetPropertyDWORD typedef ptr TYPE_IUriVtbl_GetPropertyDWORD
            TYPE_IUriVtbl_HasProperty typedef proto WIN_STD_CALL_CONV :ptr IUri, :Uri_PROPERTY, :ptr BOOL
            PIUriVtbl_HasProperty typedef ptr TYPE_IUriVtbl_HasProperty
            TYPE_IUriVtbl_GetAbsoluteUri typedef proto WIN_STD_CALL_CONV :ptr IUri, :ptr BSTR
            PIUriVtbl_GetAbsoluteUri typedef ptr TYPE_IUriVtbl_GetAbsoluteUri
            TYPE_IUriVtbl_GetAuthority typedef proto WIN_STD_CALL_CONV :ptr IUri, :ptr BSTR
            PIUriVtbl_GetAuthority typedef ptr TYPE_IUriVtbl_GetAuthority
            TYPE_IUriVtbl_GetDisplayUri typedef proto WIN_STD_CALL_CONV :ptr IUri, :ptr BSTR
            PIUriVtbl_GetDisplayUri typedef ptr TYPE_IUriVtbl_GetDisplayUri
            TYPE_IUriVtbl_GetDomain typedef proto WIN_STD_CALL_CONV :ptr IUri, :ptr BSTR
            PIUriVtbl_GetDomain typedef ptr TYPE_IUriVtbl_GetDomain
            TYPE_IUriVtbl_GetExtension typedef proto WIN_STD_CALL_CONV :ptr IUri, :ptr BSTR
            PIUriVtbl_GetExtension typedef ptr TYPE_IUriVtbl_GetExtension
            TYPE_IUriVtbl_GetFragment typedef proto WIN_STD_CALL_CONV :ptr IUri, :ptr BSTR
            PIUriVtbl_GetFragment typedef ptr TYPE_IUriVtbl_GetFragment
            TYPE_IUriVtbl_GetHost typedef proto WIN_STD_CALL_CONV :ptr IUri, :ptr BSTR
            PIUriVtbl_GetHost typedef ptr TYPE_IUriVtbl_GetHost
            TYPE_IUriVtbl_GetPassword typedef proto WIN_STD_CALL_CONV :ptr IUri, :ptr BSTR
            PIUriVtbl_GetPassword typedef ptr TYPE_IUriVtbl_GetPassword
            TYPE_IUriVtbl_GetPath typedef proto WIN_STD_CALL_CONV :ptr IUri, :ptr BSTR
            PIUriVtbl_GetPath typedef ptr TYPE_IUriVtbl_GetPath
            TYPE_IUriVtbl_GetPathAndQuery typedef proto WIN_STD_CALL_CONV :ptr IUri, :ptr BSTR
            PIUriVtbl_GetPathAndQuery typedef ptr TYPE_IUriVtbl_GetPathAndQuery
            TYPE_IUriVtbl_GetQuery typedef proto WIN_STD_CALL_CONV :ptr IUri, :ptr BSTR
            PIUriVtbl_GetQuery typedef ptr TYPE_IUriVtbl_GetQuery
            TYPE_IUriVtbl_GetRawUri typedef proto WIN_STD_CALL_CONV :ptr IUri, :ptr BSTR
            PIUriVtbl_GetRawUri typedef ptr TYPE_IUriVtbl_GetRawUri
            TYPE_IUriVtbl_GetSchemeName typedef proto WIN_STD_CALL_CONV :ptr IUri, :ptr BSTR
            PIUriVtbl_GetSchemeName typedef ptr TYPE_IUriVtbl_GetSchemeName
            TYPE_IUriVtbl_GetUserInfo typedef proto WIN_STD_CALL_CONV :ptr IUri, :ptr BSTR
            PIUriVtbl_GetUserInfo typedef ptr TYPE_IUriVtbl_GetUserInfo
            TYPE_IUriVtbl_GetUserName typedef proto WIN_STD_CALL_CONV :ptr IUri, :ptr BSTR
            PIUriVtbl_GetUserName typedef ptr TYPE_IUriVtbl_GetUserName
            TYPE_IUriVtbl_GetHostType typedef proto WIN_STD_CALL_CONV :ptr IUri, :ptr DWORD
            PIUriVtbl_GetHostType typedef ptr TYPE_IUriVtbl_GetHostType
            TYPE_IUriVtbl_GetPort typedef proto WIN_STD_CALL_CONV :ptr IUri, :ptr DWORD
            PIUriVtbl_GetPort typedef ptr TYPE_IUriVtbl_GetPort
            TYPE_IUriVtbl_GetScheme typedef proto WIN_STD_CALL_CONV :ptr IUri, :ptr DWORD
            PIUriVtbl_GetScheme typedef ptr TYPE_IUriVtbl_GetScheme
            TYPE_IUriVtbl_GetZone typedef proto WIN_STD_CALL_CONV :ptr IUri, :ptr DWORD
            PIUriVtbl_GetZone typedef ptr TYPE_IUriVtbl_GetZone
            TYPE_IUriVtbl_GetProperties typedef proto WIN_STD_CALL_CONV :ptr IUri, :LPDWORD
            PIUriVtbl_GetProperties typedef ptr TYPE_IUriVtbl_GetProperties
            TYPE_IUriVtbl_IsEqual typedef proto WIN_STD_CALL_CONV :ptr IUri, :ptr IUri, :ptr BOOL
            PIUriVtbl_IsEqual typedef ptr TYPE_IUriVtbl_IsEqual
            IUriVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IUri>
              QueryInterface PIUriVtbl_QueryInterface ?
              AddRef PIUriVtbl_AddRef ?
              Release PIUriVtbl_Release ?
              GetPropertyBSTR PIUriVtbl_GetPropertyBSTR ?
              GetPropertyLength PIUriVtbl_GetPropertyLength ?
              GetPropertyDWORD PIUriVtbl_GetPropertyDWORD ?
              HasProperty PIUriVtbl_HasProperty ?
              GetAbsoluteUri PIUriVtbl_GetAbsoluteUri ?
              GetAuthority PIUriVtbl_GetAuthority ?
              GetDisplayUri PIUriVtbl_GetDisplayUri ?
              GetDomain PIUriVtbl_GetDomain ?
              GetExtension PIUriVtbl_GetExtension ?
              GetFragment PIUriVtbl_GetFragment ?
              GetHost PIUriVtbl_GetHost ?
              GetPassword PIUriVtbl_GetPassword ?
              GetPath_ PIUriVtbl_GetPath ?
              GetPathAndQuery PIUriVtbl_GetPathAndQuery ?
              GetQuery PIUriVtbl_GetQuery ?
              GetRawUri PIUriVtbl_GetRawUri ?
              GetSchemeName PIUriVtbl_GetSchemeName ?
              GetUserInfo PIUriVtbl_GetUserInfo ?
              GetUserName_ PIUriVtbl_GetUserName ?
              GetHostType PIUriVtbl_GetHostType ?
              GetPort PIUriVtbl_GetPort ?
              GetScheme PIUriVtbl_GetScheme ?
              GetZone PIUriVtbl_GetZone ?
              GetProperties PIUriVtbl_GetProperties ?
              IsEqual PIUriVtbl_IsEqual ?
              ??Interface equ <>
              END_INTERFACE
            IUriVtbl ends
            IUri struct
              lpVtbl POINTER ?
            IUri ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
        @DefProto DllImport, CreateUri, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :DWORD_PTR, :ptr ptr IUri>, 16
        @DefProto DllImport, CreateUriWithFragment, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :DWORD, :DWORD_PTR, :ptr ptr IUri>, 20
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, CreateUriFromMultiByteString, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :DWORD, :DWORD, :DWORD_PTR, :ptr ptr IUri>, 24
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
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
        Uri_CREATE_ALLOW_RELATIVE equ 00000001h
        Uri_CREATE_ALLOW_IMPLICIT_WILDCARD_SCHEME equ 00000002h
        Uri_CREATE_ALLOW_IMPLICIT_FILE_SCHEME equ 00000004h
        Uri_CREATE_NOFRAG equ 00000008h
        Uri_CREATE_NO_CANONICALIZE equ 00000010h
        Uri_CREATE_CANONICALIZE equ 00000100h
        Uri_CREATE_FILE_USE_DOS_PATH equ 00000020h
        Uri_CREATE_DECODE_EXTRA_INFO equ 00000040h
        Uri_CREATE_NO_DECODE_EXTRA_INFO equ 00000080h
        Uri_CREATE_CRACK_UNKNOWN_SCHEMES equ 00000200h
        Uri_CREATE_NO_CRACK_UNKNOWN_SCHEMES equ 00000400h
        Uri_CREATE_PRE_PROCESS_HTML_URI equ 00000800h
        Uri_CREATE_NO_PRE_PROCESS_HTML_URI equ 00001000h
        Uri_CREATE_IE_SETTINGS equ 00002000h
        Uri_CREATE_NO_IE_SETTINGS equ 00004000h
        Uri_CREATE_NO_ENCODE_FORBIDDEN_CHARACTERS equ 00008000h
        Uri_CREATE_NORMALIZE_INTL_CHARACTERS equ 00010000h
        Uri_CREATE_CANONICALIZE_ABSOLUTE equ 00020000h
        Uri_DISPLAY_NO_FRAGMENT equ 00000001h
        Uri_PUNYCODE_IDN_HOST equ 00000002h
        Uri_DISPLAY_IDN_HOST equ 00000004h
        Uri_DISPLAY_NO_PUNYCODE equ 00000008h
        Uri_ENCODING_USER_INFO_AND_PATH_IS_PERCENT_ENCODED_UTF8 equ 00000001h
        Uri_ENCODING_USER_INFO_AND_PATH_IS_CP equ 00000002h
        Uri_ENCODING_HOST_IS_IDN equ 00000004h
        Uri_ENCODING_HOST_IS_PERCENT_ENCODED_UTF8 equ 00000008h
        Uri_ENCODING_HOST_IS_PERCENT_ENCODED_CP equ 00000010h
        Uri_ENCODING_QUERY_AND_FRAGMENT_IS_PERCENT_ENCODED_UTF8 equ 00000020h
        Uri_ENCODING_QUERY_AND_FRAGMENT_IS_CP equ 00000040h
        Uri_ENCODING_RFC equ <(Uri_ENCODING_USER_INFO_AND_PATH_IS_PERCENT_ENCODED_UTF8 or Uri_ENCODING_HOST_IS_PERCENT_ENCODED_UTF8 or Uri_ENCODING_QUERY_AND_FRAGMENT_IS_PERCENT_ENCODED_UTF8)>
        UriBuilder_USE_ORIGINAL_FLAGS equ 00000001h
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      externdef __MIDL_itf_urlmon_0000_0015_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0015_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IUriContainer_INTERFACE_DEFINED__
        __IUriContainer_INTERFACE_DEFINED__ equ <>
        externdef IID_IUriContainer:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          TYPE_IUriContainerVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IUriContainer, :REFIID, :ptr ptr
          PIUriContainerVtbl_QueryInterface typedef ptr TYPE_IUriContainerVtbl_QueryInterface
          TYPE_IUriContainerVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IUriContainer
          PIUriContainerVtbl_AddRef typedef ptr TYPE_IUriContainerVtbl_AddRef
          TYPE_IUriContainerVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IUriContainer
          PIUriContainerVtbl_Release typedef ptr TYPE_IUriContainerVtbl_Release
          TYPE_IUriContainerVtbl_GetIUri typedef proto WIN_STD_CALL_CONV :ptr IUriContainer, :ptr ptr IUri
          PIUriContainerVtbl_GetIUri typedef ptr TYPE_IUriContainerVtbl_GetIUri
          IUriContainerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IUriContainer>
            QueryInterface PIUriContainerVtbl_QueryInterface ?
            AddRef PIUriContainerVtbl_AddRef ?
            Release PIUriContainerVtbl_Release ?
            GetIUri PIUriContainerVtbl_GetIUri ?
            ??Interface equ <>
            END_INTERFACE
          IUriContainerVtbl ends
          IUriContainer struct
            lpVtbl POINTER ?
          IUriContainer ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IUriBuilder_INTERFACE_DEFINED__
        __IUriBuilder_INTERFACE_DEFINED__ equ <>
        externdef IID_IUriBuilder:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          TYPE_IUriBuilderVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IUriBuilder, :REFIID, :ptr ptr
          PIUriBuilderVtbl_QueryInterface typedef ptr TYPE_IUriBuilderVtbl_QueryInterface
          TYPE_IUriBuilderVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IUriBuilder
          PIUriBuilderVtbl_AddRef typedef ptr TYPE_IUriBuilderVtbl_AddRef
          TYPE_IUriBuilderVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IUriBuilder
          PIUriBuilderVtbl_Release typedef ptr TYPE_IUriBuilderVtbl_Release
          TYPE_IUriBuilderVtbl_CreateUriSimple typedef proto WIN_STD_CALL_CONV :ptr IUriBuilder, :DWORD, :DWORD_PTR, :ptr ptr IUri
          PIUriBuilderVtbl_CreateUriSimple typedef ptr TYPE_IUriBuilderVtbl_CreateUriSimple
          TYPE_IUriBuilderVtbl_CreateUri typedef proto WIN_STD_CALL_CONV :ptr IUriBuilder, :DWORD, :DWORD, :DWORD_PTR, :ptr ptr IUri
          PIUriBuilderVtbl_CreateUri typedef ptr TYPE_IUriBuilderVtbl_CreateUri
          TYPE_IUriBuilderVtbl_CreateUriWithFlags typedef proto WIN_STD_CALL_CONV :ptr IUriBuilder, :DWORD, :DWORD, :DWORD, :DWORD_PTR, :ptr ptr IUri
          PIUriBuilderVtbl_CreateUriWithFlags typedef ptr TYPE_IUriBuilderVtbl_CreateUriWithFlags
          TYPE_IUriBuilderVtbl_GetIUri typedef proto WIN_STD_CALL_CONV :ptr IUriBuilder, :ptr ptr IUri
          PIUriBuilderVtbl_GetIUri typedef ptr TYPE_IUriBuilderVtbl_GetIUri
          TYPE_IUriBuilderVtbl_SetIUri typedef proto WIN_STD_CALL_CONV :ptr IUriBuilder, :ptr IUri
          PIUriBuilderVtbl_SetIUri typedef ptr TYPE_IUriBuilderVtbl_SetIUri
          TYPE_IUriBuilderVtbl_GetFragment typedef proto WIN_STD_CALL_CONV :ptr IUriBuilder, :ptr DWORD, :ptr LPCWSTR
          PIUriBuilderVtbl_GetFragment typedef ptr TYPE_IUriBuilderVtbl_GetFragment
          TYPE_IUriBuilderVtbl_GetHost typedef proto WIN_STD_CALL_CONV :ptr IUriBuilder, :ptr DWORD, :ptr LPCWSTR
          PIUriBuilderVtbl_GetHost typedef ptr TYPE_IUriBuilderVtbl_GetHost
          TYPE_IUriBuilderVtbl_GetPassword typedef proto WIN_STD_CALL_CONV :ptr IUriBuilder, :ptr DWORD, :ptr LPCWSTR
          PIUriBuilderVtbl_GetPassword typedef ptr TYPE_IUriBuilderVtbl_GetPassword
          TYPE_IUriBuilderVtbl_GetPath typedef proto WIN_STD_CALL_CONV :ptr IUriBuilder, :ptr DWORD, :ptr LPCWSTR
          PIUriBuilderVtbl_GetPath typedef ptr TYPE_IUriBuilderVtbl_GetPath
          TYPE_IUriBuilderVtbl_GetPort typedef proto WIN_STD_CALL_CONV :ptr IUriBuilder, :ptr BOOL, :ptr DWORD
          PIUriBuilderVtbl_GetPort typedef ptr TYPE_IUriBuilderVtbl_GetPort
          TYPE_IUriBuilderVtbl_GetQuery typedef proto WIN_STD_CALL_CONV :ptr IUriBuilder, :ptr DWORD, :ptr LPCWSTR
          PIUriBuilderVtbl_GetQuery typedef ptr TYPE_IUriBuilderVtbl_GetQuery
          TYPE_IUriBuilderVtbl_GetSchemeName typedef proto WIN_STD_CALL_CONV :ptr IUriBuilder, :ptr DWORD, :ptr LPCWSTR
          PIUriBuilderVtbl_GetSchemeName typedef ptr TYPE_IUriBuilderVtbl_GetSchemeName
          TYPE_IUriBuilderVtbl_GetUserName typedef proto WIN_STD_CALL_CONV :ptr IUriBuilder, :ptr DWORD, :ptr LPCWSTR
          PIUriBuilderVtbl_GetUserName typedef ptr TYPE_IUriBuilderVtbl_GetUserName
          TYPE_IUriBuilderVtbl_SetFragment typedef proto WIN_STD_CALL_CONV :ptr IUriBuilder, :LPCWSTR
          PIUriBuilderVtbl_SetFragment typedef ptr TYPE_IUriBuilderVtbl_SetFragment
          TYPE_IUriBuilderVtbl_SetHost typedef proto WIN_STD_CALL_CONV :ptr IUriBuilder, :LPCWSTR
          PIUriBuilderVtbl_SetHost typedef ptr TYPE_IUriBuilderVtbl_SetHost
          TYPE_IUriBuilderVtbl_SetPassword typedef proto WIN_STD_CALL_CONV :ptr IUriBuilder, :LPCWSTR
          PIUriBuilderVtbl_SetPassword typedef ptr TYPE_IUriBuilderVtbl_SetPassword
          TYPE_IUriBuilderVtbl_SetPath typedef proto WIN_STD_CALL_CONV :ptr IUriBuilder, :LPCWSTR
          PIUriBuilderVtbl_SetPath typedef ptr TYPE_IUriBuilderVtbl_SetPath
          TYPE_IUriBuilderVtbl_SetPort typedef proto WIN_STD_CALL_CONV :ptr IUriBuilder, :BOOL, :DWORD
          PIUriBuilderVtbl_SetPort typedef ptr TYPE_IUriBuilderVtbl_SetPort
          TYPE_IUriBuilderVtbl_SetQuery typedef proto WIN_STD_CALL_CONV :ptr IUriBuilder, :LPCWSTR
          PIUriBuilderVtbl_SetQuery typedef ptr TYPE_IUriBuilderVtbl_SetQuery
          TYPE_IUriBuilderVtbl_SetSchemeName typedef proto WIN_STD_CALL_CONV :ptr IUriBuilder, :LPCWSTR
          PIUriBuilderVtbl_SetSchemeName typedef ptr TYPE_IUriBuilderVtbl_SetSchemeName
          TYPE_IUriBuilderVtbl_SetUserName typedef proto WIN_STD_CALL_CONV :ptr IUriBuilder, :LPCWSTR
          PIUriBuilderVtbl_SetUserName typedef ptr TYPE_IUriBuilderVtbl_SetUserName
          TYPE_IUriBuilderVtbl_RemoveProperties typedef proto WIN_STD_CALL_CONV :ptr IUriBuilder, :DWORD
          PIUriBuilderVtbl_RemoveProperties typedef ptr TYPE_IUriBuilderVtbl_RemoveProperties
          TYPE_IUriBuilderVtbl_HasBeenModified typedef proto WIN_STD_CALL_CONV :ptr IUriBuilder, :ptr BOOL
          PIUriBuilderVtbl_HasBeenModified typedef ptr TYPE_IUriBuilderVtbl_HasBeenModified
          IUriBuilderVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IUriBuilder>
            QueryInterface PIUriBuilderVtbl_QueryInterface ?
            AddRef PIUriBuilderVtbl_AddRef ?
            Release PIUriBuilderVtbl_Release ?
            CreateUriSimple PIUriBuilderVtbl_CreateUriSimple ?
            CreateUri_ PIUriBuilderVtbl_CreateUri ?
            CreateUriWithFlags PIUriBuilderVtbl_CreateUriWithFlags ?
            GetIUri PIUriBuilderVtbl_GetIUri ?
            SetIUri PIUriBuilderVtbl_SetIUri ?
            GetFragment PIUriBuilderVtbl_GetFragment ?
            GetHost PIUriBuilderVtbl_GetHost ?
            GetPassword PIUriBuilderVtbl_GetPassword ?
            GetPath_ PIUriBuilderVtbl_GetPath ?
            GetPort PIUriBuilderVtbl_GetPort ?
            GetQuery PIUriBuilderVtbl_GetQuery ?
            GetSchemeName PIUriBuilderVtbl_GetSchemeName ?
            GetUserName_ PIUriBuilderVtbl_GetUserName ?
            SetFragment PIUriBuilderVtbl_SetFragment ?
            SetHost PIUriBuilderVtbl_SetHost ?
            SetPassword PIUriBuilderVtbl_SetPassword ?
            SetPath PIUriBuilderVtbl_SetPath ?
            SetPort_ PIUriBuilderVtbl_SetPort ?
            SetQuery PIUriBuilderVtbl_SetQuery ?
            SetSchemeName PIUriBuilderVtbl_SetSchemeName ?
            SetUserName PIUriBuilderVtbl_SetUserName ?
            RemoveProperties PIUriBuilderVtbl_RemoveProperties ?
            HasBeenModified PIUriBuilderVtbl_HasBeenModified ?
            ??Interface equ <>
            END_INTERFACE
          IUriBuilderVtbl ends
          IUriBuilder struct
            lpVtbl POINTER ?
          IUriBuilder ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IUriBuilderFactory_INTERFACE_DEFINED__
        __IUriBuilderFactory_INTERFACE_DEFINED__ equ <>
        externdef IID_IUriBuilderFactory:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          TYPE_IUriBuilderFactoryVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IUriBuilderFactory, :REFIID, :ptr ptr
          PIUriBuilderFactoryVtbl_QueryInterface typedef ptr TYPE_IUriBuilderFactoryVtbl_QueryInterface
          TYPE_IUriBuilderFactoryVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IUriBuilderFactory
          PIUriBuilderFactoryVtbl_AddRef typedef ptr TYPE_IUriBuilderFactoryVtbl_AddRef
          TYPE_IUriBuilderFactoryVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IUriBuilderFactory
          PIUriBuilderFactoryVtbl_Release typedef ptr TYPE_IUriBuilderFactoryVtbl_Release
          TYPE_IUriBuilderFactoryVtbl_CreateIUriBuilder typedef proto WIN_STD_CALL_CONV :ptr IUriBuilderFactory, :DWORD, :DWORD_PTR, :ptr ptr IUriBuilder
          PIUriBuilderFactoryVtbl_CreateIUriBuilder typedef ptr TYPE_IUriBuilderFactoryVtbl_CreateIUriBuilder
          TYPE_IUriBuilderFactoryVtbl_CreateInitializedIUriBuilder typedef proto WIN_STD_CALL_CONV :ptr IUriBuilderFactory, :DWORD, :DWORD_PTR, :ptr ptr IUriBuilder
          PIUriBuilderFactoryVtbl_CreateInitializedIUriBuilder typedef ptr TYPE_IUriBuilderFactoryVtbl_CreateInitializedIUriBuilder
          IUriBuilderFactoryVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IUriBuilderFactory>
            QueryInterface PIUriBuilderFactoryVtbl_QueryInterface ?
            AddRef PIUriBuilderFactoryVtbl_AddRef ?
            Release PIUriBuilderFactoryVtbl_Release ?
            CreateIUriBuilder PIUriBuilderFactoryVtbl_CreateIUriBuilder ?
            CreateInitializedIUriBuilder PIUriBuilderFactoryVtbl_CreateInitializedIUriBuilder ?
            ??Interface equ <>
            END_INTERFACE
          IUriBuilderFactoryVtbl ends
          IUriBuilderFactory struct
            lpVtbl POINTER ?
          IUriBuilderFactory ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      @DefProto DllImport, CreateIUriBuilder, WIN_STD_CALL_CONV,, <:ptr IUri, :DWORD, :DWORD_PTR, :ptr ptr IUriBuilder>, 16
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef _LPWININETINFO_DEFINED
      _LPWININETINFO_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0018_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0018_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IWinInetInfo_INTERFACE_DEFINED__
        __IWinInetInfo_INTERFACE_DEFINED__ equ <>
        LPWININETINFO typedef ptr IWinInetInfo
        externdef IID_IWinInetInfo:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          TYPE_IWinInetInfoVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IWinInetInfo, :REFIID, :ptr ptr
          PIWinInetInfoVtbl_QueryInterface typedef ptr TYPE_IWinInetInfoVtbl_QueryInterface
          TYPE_IWinInetInfoVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IWinInetInfo
          PIWinInetInfoVtbl_AddRef typedef ptr TYPE_IWinInetInfoVtbl_AddRef
          TYPE_IWinInetInfoVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IWinInetInfo
          PIWinInetInfoVtbl_Release typedef ptr TYPE_IWinInetInfoVtbl_Release
          TYPE_IWinInetInfoVtbl_QueryOption typedef proto WIN_STD_CALL_CONV :ptr IWinInetInfo, :DWORD, :LPVOID, :ptr DWORD
          PIWinInetInfoVtbl_QueryOption typedef ptr TYPE_IWinInetInfoVtbl_QueryOption
          IWinInetInfoVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IWinInetInfo>
            QueryInterface PIWinInetInfoVtbl_QueryInterface ?
            AddRef PIWinInetInfoVtbl_AddRef ?
            Release PIWinInetInfoVtbl_Release ?
            QueryOption PIWinInetInfoVtbl_QueryOption ?
            ??Interface equ <>
            END_INTERFACE
          IWinInetInfoVtbl ends
          IWinInetInfo struct
            lpVtbl POINTER ?
          IWinInetInfo ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
        IWinInetInfo_RemoteQueryOption_Proxy proto WIN_STD_CALL_CONV :ptr IWinInetInfo, :DWORD, :ptr BYTE, :ptr DWORD
        IWinInetInfo_RemoteQueryOption_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      endif
    endif
    WININETINFO_OPTION_LOCK_HANDLE equ 65534
    ifndef _LPHTTPSECURITY_DEFINED
      _LPHTTPSECURITY_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0019_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0019_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IHttpSecurity_INTERFACE_DEFINED__
        __IHttpSecurity_INTERFACE_DEFINED__ equ <>
        LPHTTPSECURITY typedef ptr IHttpSecurity
        externdef IID_IHttpSecurity:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          TYPE_IHttpSecurityVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IHttpSecurity, :REFIID, :ptr ptr
          PIHttpSecurityVtbl_QueryInterface typedef ptr TYPE_IHttpSecurityVtbl_QueryInterface
          TYPE_IHttpSecurityVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IHttpSecurity
          PIHttpSecurityVtbl_AddRef typedef ptr TYPE_IHttpSecurityVtbl_AddRef
          TYPE_IHttpSecurityVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IHttpSecurity
          PIHttpSecurityVtbl_Release typedef ptr TYPE_IHttpSecurityVtbl_Release
          TYPE_IHttpSecurityVtbl_GetWindow typedef proto WIN_STD_CALL_CONV :ptr IHttpSecurity, :REFGUID, :ptr HWND
          PIHttpSecurityVtbl_GetWindow typedef ptr TYPE_IHttpSecurityVtbl_GetWindow
          TYPE_IHttpSecurityVtbl_OnSecurityProblem typedef proto WIN_STD_CALL_CONV :ptr IHttpSecurity, :DWORD
          PIHttpSecurityVtbl_OnSecurityProblem typedef ptr TYPE_IHttpSecurityVtbl_OnSecurityProblem
          IHttpSecurityVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IHttpSecurity>
            QueryInterface PIHttpSecurityVtbl_QueryInterface ?
            AddRef PIHttpSecurityVtbl_AddRef ?
            Release PIHttpSecurityVtbl_Release ?
            GetWindow PIHttpSecurityVtbl_GetWindow ?
            OnSecurityProblem PIHttpSecurityVtbl_OnSecurityProblem ?
            ??Interface equ <>
            END_INTERFACE
          IHttpSecurityVtbl ends
          IHttpSecurity struct
            lpVtbl POINTER ?
          IHttpSecurity ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    ifndef _LPWININETHTTPINFO_DEFINED
      _LPWININETHTTPINFO_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0020_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0020_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IWinInetHttpInfo_INTERFACE_DEFINED__
        __IWinInetHttpInfo_INTERFACE_DEFINED__ equ <>
        LPWININETHTTPINFO typedef ptr IWinInetHttpInfo
        externdef IID_IWinInetHttpInfo:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          TYPE_IWinInetHttpInfoVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IWinInetHttpInfo, :REFIID, :ptr ptr
          PIWinInetHttpInfoVtbl_QueryInterface typedef ptr TYPE_IWinInetHttpInfoVtbl_QueryInterface
          TYPE_IWinInetHttpInfoVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IWinInetHttpInfo
          PIWinInetHttpInfoVtbl_AddRef typedef ptr TYPE_IWinInetHttpInfoVtbl_AddRef
          TYPE_IWinInetHttpInfoVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IWinInetHttpInfo
          PIWinInetHttpInfoVtbl_Release typedef ptr TYPE_IWinInetHttpInfoVtbl_Release
          TYPE_IWinInetHttpInfoVtbl_QueryOption typedef proto WIN_STD_CALL_CONV :ptr IWinInetHttpInfo, :DWORD, :LPVOID, :ptr DWORD
          PIWinInetHttpInfoVtbl_QueryOption typedef ptr TYPE_IWinInetHttpInfoVtbl_QueryOption
          TYPE_IWinInetHttpInfoVtbl_QueryInfo typedef proto WIN_STD_CALL_CONV :ptr IWinInetHttpInfo, :DWORD, :LPVOID, :ptr DWORD, :ptr DWORD, :ptr DWORD
          PIWinInetHttpInfoVtbl_QueryInfo typedef ptr TYPE_IWinInetHttpInfoVtbl_QueryInfo
          IWinInetHttpInfoVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IWinInetHttpInfo>
            QueryInterface PIWinInetHttpInfoVtbl_QueryInterface ?
            AddRef PIWinInetHttpInfoVtbl_AddRef ?
            Release PIWinInetHttpInfoVtbl_Release ?
            QueryOption PIWinInetHttpInfoVtbl_QueryOption ?
            QueryInfo PIWinInetHttpInfoVtbl_QueryInfo ?
            ??Interface equ <>
            END_INTERFACE
          IWinInetHttpInfoVtbl ends
          IWinInetHttpInfo struct
            lpVtbl POINTER ?
          IWinInetHttpInfo ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
        IWinInetHttpInfo_RemoteQueryInfo_Proxy proto WIN_STD_CALL_CONV :ptr IWinInetHttpInfo, :DWORD, :ptr BYTE, :ptr DWORD, :ptr DWORD, :ptr DWORD
        IWinInetHttpInfo_RemoteQueryInfo_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      endif
    endif
    ifndef _LPWININETHTTPTIMEOUTS_DEFINED
      _LPWININETHTTPTIMEOUTS_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0021_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0021_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IWinInetHttpTimeouts_INTERFACE_DEFINED__
        __IWinInetHttpTimeouts_INTERFACE_DEFINED__ equ <>
        externdef IID_IWinInetHttpTimeouts:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          TYPE_IWinInetHttpTimeoutsVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IWinInetHttpTimeouts, :REFIID, :ptr ptr
          PIWinInetHttpTimeoutsVtbl_QueryInterface typedef ptr TYPE_IWinInetHttpTimeoutsVtbl_QueryInterface
          TYPE_IWinInetHttpTimeoutsVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IWinInetHttpTimeouts
          PIWinInetHttpTimeoutsVtbl_AddRef typedef ptr TYPE_IWinInetHttpTimeoutsVtbl_AddRef
          TYPE_IWinInetHttpTimeoutsVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IWinInetHttpTimeouts
          PIWinInetHttpTimeoutsVtbl_Release typedef ptr TYPE_IWinInetHttpTimeoutsVtbl_Release
          TYPE_IWinInetHttpTimeoutsVtbl_GetRequestTimeouts typedef proto WIN_STD_CALL_CONV :ptr IWinInetHttpTimeouts, :ptr DWORD, :ptr DWORD, :ptr DWORD
          PIWinInetHttpTimeoutsVtbl_GetRequestTimeouts typedef ptr TYPE_IWinInetHttpTimeoutsVtbl_GetRequestTimeouts
          IWinInetHttpTimeoutsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IWinInetHttpTimeouts>
            QueryInterface PIWinInetHttpTimeoutsVtbl_QueryInterface ?
            AddRef PIWinInetHttpTimeoutsVtbl_AddRef ?
            Release PIWinInetHttpTimeoutsVtbl_Release ?
            GetRequestTimeouts PIWinInetHttpTimeoutsVtbl_GetRequestTimeouts ?
            ??Interface equ <>
            END_INTERFACE
          IWinInetHttpTimeoutsVtbl ends
          IWinInetHttpTimeouts struct
            lpVtbl POINTER ?
          IWinInetHttpTimeouts ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    if (_WIN32_IE ge _WIN32_IE_IE60SP2)
      ifndef _LPWININETCACHEHINTS_DEFINED
        _LPWININETCACHEHINTS_DEFINED equ <>
        externdef __MIDL_itf_urlmon_0000_0022_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0022_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IWinInetCacheHints_INTERFACE_DEFINED__
          __IWinInetCacheHints_INTERFACE_DEFINED__ equ <>
          LPWININETCACHEHINTS typedef ptr IWinInetCacheHints
          externdef IID_IWinInetCacheHints:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            TYPE_IWinInetCacheHintsVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IWinInetCacheHints, :REFIID, :ptr ptr
            PIWinInetCacheHintsVtbl_QueryInterface typedef ptr TYPE_IWinInetCacheHintsVtbl_QueryInterface
            TYPE_IWinInetCacheHintsVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IWinInetCacheHints
            PIWinInetCacheHintsVtbl_AddRef typedef ptr TYPE_IWinInetCacheHintsVtbl_AddRef
            TYPE_IWinInetCacheHintsVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IWinInetCacheHints
            PIWinInetCacheHintsVtbl_Release typedef ptr TYPE_IWinInetCacheHintsVtbl_Release
            TYPE_IWinInetCacheHintsVtbl_SetCacheExtension typedef proto WIN_STD_CALL_CONV :ptr IWinInetCacheHints, :LPCWSTR, :LPVOID, :ptr DWORD, :ptr DWORD, :ptr DWORD
            PIWinInetCacheHintsVtbl_SetCacheExtension typedef ptr TYPE_IWinInetCacheHintsVtbl_SetCacheExtension
            IWinInetCacheHintsVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IWinInetCacheHints>
              QueryInterface PIWinInetCacheHintsVtbl_QueryInterface ?
              AddRef PIWinInetCacheHintsVtbl_AddRef ?
              Release PIWinInetCacheHintsVtbl_Release ?
              SetCacheExtension PIWinInetCacheHintsVtbl_SetCacheExtension ?
              ??Interface equ <>
              END_INTERFACE
            IWinInetCacheHintsVtbl ends
            IWinInetCacheHints struct
              lpVtbl POINTER ?
            IWinInetCacheHints ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
      endif
    endif
    if (_WIN32_IE ge _WIN32_IE_IE70)
      ifndef _LPWININETCACHEHINTS2_DEFINED
        _LPWININETCACHEHINTS2_DEFINED equ <>
        externdef __MIDL_itf_urlmon_0000_0023_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0023_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IWinInetCacheHints2_INTERFACE_DEFINED__
          __IWinInetCacheHints2_INTERFACE_DEFINED__ equ <>
          LPWININETCACHEHINTS2 typedef ptr IWinInetCacheHints2
          externdef IID_IWinInetCacheHints2:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            TYPE_IWinInetCacheHints2Vtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IWinInetCacheHints2, :REFIID, :ptr ptr
            PIWinInetCacheHints2Vtbl_QueryInterface typedef ptr TYPE_IWinInetCacheHints2Vtbl_QueryInterface
            TYPE_IWinInetCacheHints2Vtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IWinInetCacheHints2
            PIWinInetCacheHints2Vtbl_AddRef typedef ptr TYPE_IWinInetCacheHints2Vtbl_AddRef
            TYPE_IWinInetCacheHints2Vtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IWinInetCacheHints2
            PIWinInetCacheHints2Vtbl_Release typedef ptr TYPE_IWinInetCacheHints2Vtbl_Release
            TYPE_IWinInetCacheHints2Vtbl_SetCacheExtension typedef proto WIN_STD_CALL_CONV :ptr IWinInetCacheHints2, :LPCWSTR, :LPVOID, :ptr DWORD, :ptr DWORD, :ptr DWORD
            PIWinInetCacheHints2Vtbl_SetCacheExtension typedef ptr TYPE_IWinInetCacheHints2Vtbl_SetCacheExtension
            TYPE_IWinInetCacheHints2Vtbl_SetCacheExtension2 typedef proto WIN_STD_CALL_CONV :ptr IWinInetCacheHints2, :LPCWSTR, :ptr WCHAR, :ptr DWORD, :ptr DWORD, :ptr DWORD
            PIWinInetCacheHints2Vtbl_SetCacheExtension2 typedef ptr TYPE_IWinInetCacheHints2Vtbl_SetCacheExtension2
            IWinInetCacheHints2Vtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IWinInetCacheHints2>
              QueryInterface PIWinInetCacheHints2Vtbl_QueryInterface ?
              AddRef PIWinInetCacheHints2Vtbl_AddRef ?
              Release PIWinInetCacheHints2Vtbl_Release ?
              SetCacheExtension PIWinInetCacheHints2Vtbl_SetCacheExtension ?
              SetCacheExtension2 PIWinInetCacheHints2Vtbl_SetCacheExtension2 ?
              ??Interface equ <>
              END_INTERFACE
            IWinInetCacheHints2Vtbl ends
            IWinInetCacheHints2 struct
              lpVtbl POINTER ?
            IWinInetCacheHints2 ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
      endif
    endif
    SID_IBindHost equ <IID_IBindHost>
    SID_SBindHost equ <IID_IBindHost>
    ifndef _LPBINDHOST_DEFINED
      _LPBINDHOST_DEFINED equ <>
      externdef SID_BindHost:GUID
      externdef __MIDL_itf_urlmon_0000_0024_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0024_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IBindHost_INTERFACE_DEFINED__
        __IBindHost_INTERFACE_DEFINED__ equ <>
        LPBINDHOST typedef ptr IBindHost
        externdef IID_IBindHost:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          TYPE_IBindHostVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IBindHost, :REFIID, :ptr ptr
          PIBindHostVtbl_QueryInterface typedef ptr TYPE_IBindHostVtbl_QueryInterface
          TYPE_IBindHostVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IBindHost
          PIBindHostVtbl_AddRef typedef ptr TYPE_IBindHostVtbl_AddRef
          TYPE_IBindHostVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IBindHost
          PIBindHostVtbl_Release typedef ptr TYPE_IBindHostVtbl_Release
          TYPE_IBindHostVtbl_CreateMoniker typedef proto WIN_STD_CALL_CONV :ptr IBindHost, :LPOLESTR, :ptr IBindCtx, :ptr ptr IMoniker, :DWORD
          PIBindHostVtbl_CreateMoniker typedef ptr TYPE_IBindHostVtbl_CreateMoniker
          TYPE_IBindHostVtbl_MonikerBindToStorage typedef proto WIN_STD_CALL_CONV :ptr IBindHost, :ptr IMoniker, :ptr IBindCtx, :ptr IBindStatusCallback, :REFIID, :ptr ptr
          PIBindHostVtbl_MonikerBindToStorage typedef ptr TYPE_IBindHostVtbl_MonikerBindToStorage
          TYPE_IBindHostVtbl_MonikerBindToObject typedef proto WIN_STD_CALL_CONV :ptr IBindHost, :ptr IMoniker, :ptr IBindCtx, :ptr IBindStatusCallback, :REFIID, :ptr ptr
          PIBindHostVtbl_MonikerBindToObject typedef ptr TYPE_IBindHostVtbl_MonikerBindToObject
          IBindHostVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IBindHost>
            QueryInterface PIBindHostVtbl_QueryInterface ?
            AddRef PIBindHostVtbl_AddRef ?
            Release PIBindHostVtbl_Release ?
            CreateMoniker PIBindHostVtbl_CreateMoniker ?
            MonikerBindToStorage PIBindHostVtbl_MonikerBindToStorage ?
            MonikerBindToObject PIBindHostVtbl_MonikerBindToObject ?
            ??Interface equ <>
            END_INTERFACE
          IBindHostVtbl ends
          IBindHost struct
            lpVtbl POINTER ?
          IBindHost ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
        IBindHost_RemoteMonikerBindToStorage_Proxy proto WIN_STD_CALL_CONV :ptr IBindHost, :ptr IMoniker, :ptr IBindCtx, :ptr IBindStatusCallback, :REFIID, :ptr ptr IUnknown
        IBindHost_RemoteMonikerBindToStorage_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        IBindHost_RemoteMonikerBindToObject_Proxy proto WIN_STD_CALL_CONV :ptr IBindHost, :ptr IMoniker, :ptr IBindCtx, :ptr IBindStatusCallback, :REFIID, :ptr ptr IUnknown
        IBindHost_RemoteMonikerBindToObject_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      endif
    endif
    URLOSTRM_USECACHEDCOPY_ONLY equ 1h
    URLOSTRM_USECACHEDCOPY equ 2h
    URLOSTRM_GETNEWESTVERSION equ 3h
    @DefProto DllImport, HlinkSimpleNavigateToString, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPCWSTR, :ptr IUnknown, :ptr IBindCtx, :ptr IBindStatusCallback, :DWORD, :DWORD>, 32
    @DefProto DllImport, HlinkSimpleNavigateToMoniker, WIN_STD_CALL_CONV,, <:ptr IMoniker, :LPCWSTR, :LPCWSTR, :ptr IUnknown, :ptr IBindCtx, :ptr IBindStatusCallback, :DWORD, :DWORD>, 32
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
          LPIINTERNET typedef ptr IInternet
          externdef IID_IInternet:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            TYPE_IInternetVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IInternet, :REFIID, :ptr ptr
            PIInternetVtbl_QueryInterface typedef ptr TYPE_IInternetVtbl_QueryInterface
            TYPE_IInternetVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IInternet
            PIInternetVtbl_AddRef typedef ptr TYPE_IInternetVtbl_AddRef
            TYPE_IInternetVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IInternet
            PIInternetVtbl_Release typedef ptr TYPE_IInternetVtbl_Release
            IInternetVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternet>
              QueryInterface PIInternetVtbl_QueryInterface ?
              AddRef PIInternetVtbl_AddRef ?
              Release PIInternetVtbl_Release ?
              ??Interface equ <>
              END_INTERFACE
            IInternetVtbl ends
            IInternet struct
              lpVtbl POINTER ?
            IInternet ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
      endif
      ifndef _LPIINTERNETBINDINFO
        _LPIINTERNETBINDINFO equ <>
        externdef __MIDL_itf_urlmon_0000_0026_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0026_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IInternetBindInfo_INTERFACE_DEFINED__
          __IInternetBindInfo_INTERFACE_DEFINED__ equ <>
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
          tagBINDSTRING typedef BINDSTRING
          externdef IID_IInternetBindInfo:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            TYPE_IInternetBindInfoVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IInternetBindInfo, :REFIID, :ptr ptr
            PIInternetBindInfoVtbl_QueryInterface typedef ptr TYPE_IInternetBindInfoVtbl_QueryInterface
            TYPE_IInternetBindInfoVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IInternetBindInfo
            PIInternetBindInfoVtbl_AddRef typedef ptr TYPE_IInternetBindInfoVtbl_AddRef
            TYPE_IInternetBindInfoVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IInternetBindInfo
            PIInternetBindInfoVtbl_Release typedef ptr TYPE_IInternetBindInfoVtbl_Release
            TYPE_IInternetBindInfoVtbl_GetBindInfo typedef proto WIN_STD_CALL_CONV :ptr IInternetBindInfo, :ptr DWORD, :ptr BINDINFO
            PIInternetBindInfoVtbl_GetBindInfo typedef ptr TYPE_IInternetBindInfoVtbl_GetBindInfo
            TYPE_IInternetBindInfoVtbl_GetBindString typedef proto WIN_STD_CALL_CONV :ptr IInternetBindInfo, :ULONG, :ptr LPOLESTR, :ULONG, :ptr ULONG
            PIInternetBindInfoVtbl_GetBindString typedef ptr TYPE_IInternetBindInfoVtbl_GetBindString
            IInternetBindInfoVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetBindInfo>
              QueryInterface PIInternetBindInfoVtbl_QueryInterface ?
              AddRef PIInternetBindInfoVtbl_AddRef ?
              Release PIInternetBindInfoVtbl_Release ?
              GetBindInfo PIInternetBindInfoVtbl_GetBindInfo ?
              GetBindString PIInternetBindInfoVtbl_GetBindString ?
              ??Interface equ <>
              END_INTERFACE
            IInternetBindInfoVtbl ends
            IInternetBindInfo struct
              lpVtbl POINTER ?
            IInternetBindInfo ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
      endif
      ifndef _LPIINTERNETBINDINFOEX
        _LPIINTERNETBINDINFOEX equ <>
        externdef __MIDL_itf_urlmon_0000_0027_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0027_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IInternetBindInfoEx_INTERFACE_DEFINED__
          __IInternetBindInfoEx_INTERFACE_DEFINED__ equ <>
          LPIINTERNETBINDINFOEX typedef ptr IInternetBindInfoEx
          externdef IID_IInternetBindInfoEx:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            TYPE_IInternetBindInfoExVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IInternetBindInfoEx, :REFIID, :ptr ptr
            PIInternetBindInfoExVtbl_QueryInterface typedef ptr TYPE_IInternetBindInfoExVtbl_QueryInterface
            TYPE_IInternetBindInfoExVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IInternetBindInfoEx
            PIInternetBindInfoExVtbl_AddRef typedef ptr TYPE_IInternetBindInfoExVtbl_AddRef
            TYPE_IInternetBindInfoExVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IInternetBindInfoEx
            PIInternetBindInfoExVtbl_Release typedef ptr TYPE_IInternetBindInfoExVtbl_Release
            TYPE_IInternetBindInfoExVtbl_GetBindInfo typedef proto WIN_STD_CALL_CONV :ptr IInternetBindInfoEx, :ptr DWORD, :ptr BINDINFO
            PIInternetBindInfoExVtbl_GetBindInfo typedef ptr TYPE_IInternetBindInfoExVtbl_GetBindInfo
            TYPE_IInternetBindInfoExVtbl_GetBindString typedef proto WIN_STD_CALL_CONV :ptr IInternetBindInfoEx, :ULONG, :ptr LPOLESTR, :ULONG, :ptr ULONG
            PIInternetBindInfoExVtbl_GetBindString typedef ptr TYPE_IInternetBindInfoExVtbl_GetBindString
            TYPE_IInternetBindInfoExVtbl_GetBindInfoEx typedef proto WIN_STD_CALL_CONV :ptr IInternetBindInfoEx, :ptr DWORD, :ptr BINDINFO, :ptr DWORD, :ptr DWORD
            PIInternetBindInfoExVtbl_GetBindInfoEx typedef ptr TYPE_IInternetBindInfoExVtbl_GetBindInfoEx
            IInternetBindInfoExVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetBindInfoEx>
              QueryInterface PIInternetBindInfoExVtbl_QueryInterface ?
              AddRef PIInternetBindInfoExVtbl_AddRef ?
              Release PIInternetBindInfoExVtbl_Release ?
              GetBindInfo PIInternetBindInfoExVtbl_GetBindInfo ?
              GetBindString PIInternetBindInfoExVtbl_GetBindString ?
              GetBindInfoEx PIInternetBindInfoExVtbl_GetBindInfoEx ?
              ??Interface equ <>
              END_INTERFACE
            IInternetBindInfoExVtbl ends
            IInternetBindInfoEx struct
              lpVtbl POINTER ?
            IInternetBindInfoEx ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
      endif
      ifndef _LPIINTERNETPROTOCOLROOT_DEFINED
        _LPIINTERNETPROTOCOLROOT_DEFINED equ <>
        externdef __MIDL_itf_urlmon_0000_0028_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0028_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IInternetProtocolRoot_INTERFACE_DEFINED__
          __IInternetProtocolRoot_INTERFACE_DEFINED__ equ <>
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
            pData LPVOID ?
            cbData ULONG ?
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
            TYPE_IInternetProtocolRootVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolRoot, :REFIID, :ptr ptr
            PIInternetProtocolRootVtbl_QueryInterface typedef ptr TYPE_IInternetProtocolRootVtbl_QueryInterface
            TYPE_IInternetProtocolRootVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolRoot
            PIInternetProtocolRootVtbl_AddRef typedef ptr TYPE_IInternetProtocolRootVtbl_AddRef
            TYPE_IInternetProtocolRootVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolRoot
            PIInternetProtocolRootVtbl_Release typedef ptr TYPE_IInternetProtocolRootVtbl_Release
            TYPE_IInternetProtocolRootVtbl_Start typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolRoot, :LPCWSTR, :ptr IInternetProtocolSink, :ptr IInternetBindInfo, :DWORD, :HANDLE_PTR
            PIInternetProtocolRootVtbl_Start typedef ptr TYPE_IInternetProtocolRootVtbl_Start
            TYPE_IInternetProtocolRootVtbl_Continue typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolRoot, :ptr PROTOCOLDATA
            PIInternetProtocolRootVtbl_Continue typedef ptr TYPE_IInternetProtocolRootVtbl_Continue
            TYPE_IInternetProtocolRootVtbl_Abort typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolRoot, :HRESULT, :DWORD
            PIInternetProtocolRootVtbl_Abort typedef ptr TYPE_IInternetProtocolRootVtbl_Abort
            TYPE_IInternetProtocolRootVtbl_Terminate typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolRoot, :DWORD
            PIInternetProtocolRootVtbl_Terminate typedef ptr TYPE_IInternetProtocolRootVtbl_Terminate
            TYPE_IInternetProtocolRootVtbl_Suspend typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolRoot
            PIInternetProtocolRootVtbl_Suspend typedef ptr TYPE_IInternetProtocolRootVtbl_Suspend
            TYPE_IInternetProtocolRootVtbl_Resume typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolRoot
            PIInternetProtocolRootVtbl_Resume typedef ptr TYPE_IInternetProtocolRootVtbl_Resume
            IInternetProtocolRootVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetProtocolRoot>
              QueryInterface PIInternetProtocolRootVtbl_QueryInterface ?
              AddRef PIInternetProtocolRootVtbl_AddRef ?
              Release PIInternetProtocolRootVtbl_Release ?
              Start PIInternetProtocolRootVtbl_Start ?
              Continue PIInternetProtocolRootVtbl_Continue ?
              Abort PIInternetProtocolRootVtbl_Abort ?
              Terminate PIInternetProtocolRootVtbl_Terminate ?
              Suspend PIInternetProtocolRootVtbl_Suspend ?
              Resume PIInternetProtocolRootVtbl_Resume ?
              ??Interface equ <>
              END_INTERFACE
            IInternetProtocolRootVtbl ends
            IInternetProtocolRoot struct
              lpVtbl POINTER ?
            IInternetProtocolRoot ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
      endif
      ifndef _LPIINTERNETPROTOCOL_DEFINED
        _LPIINTERNETPROTOCOL_DEFINED equ <>
        externdef __MIDL_itf_urlmon_0000_0029_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0029_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IInternetProtocol_INTERFACE_DEFINED__
          __IInternetProtocol_INTERFACE_DEFINED__ equ <>
          LPIINTERNETPROTOCOL typedef ptr IInternetProtocol
          externdef IID_IInternetProtocol:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            TYPE_IInternetProtocolVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocol, :REFIID, :ptr ptr
            PIInternetProtocolVtbl_QueryInterface typedef ptr TYPE_IInternetProtocolVtbl_QueryInterface
            TYPE_IInternetProtocolVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocol
            PIInternetProtocolVtbl_AddRef typedef ptr TYPE_IInternetProtocolVtbl_AddRef
            TYPE_IInternetProtocolVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocol
            PIInternetProtocolVtbl_Release typedef ptr TYPE_IInternetProtocolVtbl_Release
            TYPE_IInternetProtocolVtbl_Start typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocol, :LPCWSTR, :ptr IInternetProtocolSink, :ptr IInternetBindInfo, :DWORD, :HANDLE_PTR
            PIInternetProtocolVtbl_Start typedef ptr TYPE_IInternetProtocolVtbl_Start
            TYPE_IInternetProtocolVtbl_Continue typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocol, :ptr PROTOCOLDATA
            PIInternetProtocolVtbl_Continue typedef ptr TYPE_IInternetProtocolVtbl_Continue
            TYPE_IInternetProtocolVtbl_Abort typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocol, :HRESULT, :DWORD
            PIInternetProtocolVtbl_Abort typedef ptr TYPE_IInternetProtocolVtbl_Abort
            TYPE_IInternetProtocolVtbl_Terminate typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocol, :DWORD
            PIInternetProtocolVtbl_Terminate typedef ptr TYPE_IInternetProtocolVtbl_Terminate
            TYPE_IInternetProtocolVtbl_Suspend typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocol
            PIInternetProtocolVtbl_Suspend typedef ptr TYPE_IInternetProtocolVtbl_Suspend
            TYPE_IInternetProtocolVtbl_Resume typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocol
            PIInternetProtocolVtbl_Resume typedef ptr TYPE_IInternetProtocolVtbl_Resume
            TYPE_IInternetProtocolVtbl_Read typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocol, :ptr, :ULONG, :ptr ULONG
            PIInternetProtocolVtbl_Read typedef ptr TYPE_IInternetProtocolVtbl_Read
            TYPE_IInternetProtocolVtbl_Seek typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocol, :LARGE_INTEGER, :DWORD, :ptr ULARGE_INTEGER
            PIInternetProtocolVtbl_Seek typedef ptr TYPE_IInternetProtocolVtbl_Seek
            TYPE_IInternetProtocolVtbl_LockRequest typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocol, :DWORD
            PIInternetProtocolVtbl_LockRequest typedef ptr TYPE_IInternetProtocolVtbl_LockRequest
            TYPE_IInternetProtocolVtbl_UnlockRequest typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocol
            PIInternetProtocolVtbl_UnlockRequest typedef ptr TYPE_IInternetProtocolVtbl_UnlockRequest
            IInternetProtocolVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetProtocol>
              QueryInterface PIInternetProtocolVtbl_QueryInterface ?
              AddRef PIInternetProtocolVtbl_AddRef ?
              Release PIInternetProtocolVtbl_Release ?
              Start PIInternetProtocolVtbl_Start ?
              Continue PIInternetProtocolVtbl_Continue ?
              Abort PIInternetProtocolVtbl_Abort ?
              Terminate PIInternetProtocolVtbl_Terminate ?
              Suspend PIInternetProtocolVtbl_Suspend ?
              Resume PIInternetProtocolVtbl_Resume ?
              Read PIInternetProtocolVtbl_Read ?
              Seek PIInternetProtocolVtbl_Seek ?
              LockRequest PIInternetProtocolVtbl_LockRequest ?
              UnlockRequest PIInternetProtocolVtbl_UnlockRequest ?
              ??Interface equ <>
              END_INTERFACE
            IInternetProtocolVtbl ends
            IInternetProtocol struct
              lpVtbl POINTER ?
            IInternetProtocol ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
      endif
      if (_WIN32_IE ge _WIN32_IE_IE70)
        ifndef _LPIINTERNETPROTOCOLEX_DEFINED
          _LPIINTERNETPROTOCOLEX_DEFINED equ <>
          externdef __MIDL_itf_urlmon_0000_0030_v0_0_c_ifspec:RPC_IF_HANDLE
          externdef __MIDL_itf_urlmon_0000_0030_v0_0_s_ifspec:RPC_IF_HANDLE
          ifndef __IInternetProtocolEx_INTERFACE_DEFINED__
            __IInternetProtocolEx_INTERFACE_DEFINED__ equ <>
            externdef IID_IInternetProtocolEx:IID
            if Defined(__cplusplus) and  not Defined(CINTERFACE)
              ;[...]
            else
              TYPE_IInternetProtocolExVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolEx, :REFIID, :ptr ptr
              PIInternetProtocolExVtbl_QueryInterface typedef ptr TYPE_IInternetProtocolExVtbl_QueryInterface
              TYPE_IInternetProtocolExVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolEx
              PIInternetProtocolExVtbl_AddRef typedef ptr TYPE_IInternetProtocolExVtbl_AddRef
              TYPE_IInternetProtocolExVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolEx
              PIInternetProtocolExVtbl_Release typedef ptr TYPE_IInternetProtocolExVtbl_Release
              TYPE_IInternetProtocolExVtbl_Start typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolEx, :LPCWSTR, :ptr IInternetProtocolSink, :ptr IInternetBindInfo, :DWORD, :HANDLE_PTR
              PIInternetProtocolExVtbl_Start typedef ptr TYPE_IInternetProtocolExVtbl_Start
              TYPE_IInternetProtocolExVtbl_Continue typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolEx, :ptr PROTOCOLDATA
              PIInternetProtocolExVtbl_Continue typedef ptr TYPE_IInternetProtocolExVtbl_Continue
              TYPE_IInternetProtocolExVtbl_Abort typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolEx, :HRESULT, :DWORD
              PIInternetProtocolExVtbl_Abort typedef ptr TYPE_IInternetProtocolExVtbl_Abort
              TYPE_IInternetProtocolExVtbl_Terminate typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolEx, :DWORD
              PIInternetProtocolExVtbl_Terminate typedef ptr TYPE_IInternetProtocolExVtbl_Terminate
              TYPE_IInternetProtocolExVtbl_Suspend typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolEx
              PIInternetProtocolExVtbl_Suspend typedef ptr TYPE_IInternetProtocolExVtbl_Suspend
              TYPE_IInternetProtocolExVtbl_Resume typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolEx
              PIInternetProtocolExVtbl_Resume typedef ptr TYPE_IInternetProtocolExVtbl_Resume
              TYPE_IInternetProtocolExVtbl_Read typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolEx, :ptr, :ULONG, :ptr ULONG
              PIInternetProtocolExVtbl_Read typedef ptr TYPE_IInternetProtocolExVtbl_Read
              TYPE_IInternetProtocolExVtbl_Seek typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolEx, :LARGE_INTEGER, :DWORD, :ptr ULARGE_INTEGER
              PIInternetProtocolExVtbl_Seek typedef ptr TYPE_IInternetProtocolExVtbl_Seek
              TYPE_IInternetProtocolExVtbl_LockRequest typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolEx, :DWORD
              PIInternetProtocolExVtbl_LockRequest typedef ptr TYPE_IInternetProtocolExVtbl_LockRequest
              TYPE_IInternetProtocolExVtbl_UnlockRequest typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolEx
              PIInternetProtocolExVtbl_UnlockRequest typedef ptr TYPE_IInternetProtocolExVtbl_UnlockRequest
              TYPE_IInternetProtocolExVtbl_StartEx typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolEx, :ptr IUri, :ptr IInternetProtocolSink, :ptr IInternetBindInfo, :DWORD, :HANDLE_PTR
              PIInternetProtocolExVtbl_StartEx typedef ptr TYPE_IInternetProtocolExVtbl_StartEx
              IInternetProtocolExVtbl struct
                BEGIN_INTERFACE
                ??Interface equ <IInternetProtocolEx>
                QueryInterface PIInternetProtocolExVtbl_QueryInterface ?
                AddRef PIInternetProtocolExVtbl_AddRef ?
                Release PIInternetProtocolExVtbl_Release ?
                Start PIInternetProtocolExVtbl_Start ?
                Continue PIInternetProtocolExVtbl_Continue ?
                Abort PIInternetProtocolExVtbl_Abort ?
                Terminate PIInternetProtocolExVtbl_Terminate ?
                Suspend PIInternetProtocolExVtbl_Suspend ?
                Resume PIInternetProtocolExVtbl_Resume ?
                Read PIInternetProtocolExVtbl_Read ?
                Seek PIInternetProtocolExVtbl_Seek ?
                LockRequest PIInternetProtocolExVtbl_LockRequest ?
                UnlockRequest PIInternetProtocolExVtbl_UnlockRequest ?
                StartEx PIInternetProtocolExVtbl_StartEx ?
                ??Interface equ <>
                END_INTERFACE
              IInternetProtocolExVtbl ends
              IInternetProtocolEx struct
                lpVtbl POINTER ?
              IInternetProtocolEx ends
              ifdef COBJMACROS
                ;[...]
              endif
            endif
          endif
        endif
      endif
      ifndef _LPIINTERNETPROTOCOLSINK_DEFINED
        _LPIINTERNETPROTOCOLSINK_DEFINED equ <>
        externdef __MIDL_itf_urlmon_0000_0031_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0031_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IInternetProtocolSink_INTERFACE_DEFINED__
          __IInternetProtocolSink_INTERFACE_DEFINED__ equ <>
          LPIINTERNETPROTOCOLSINK typedef ptr IInternetProtocolSink
          externdef IID_IInternetProtocolSink:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            TYPE_IInternetProtocolSinkVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolSink, :REFIID, :ptr ptr
            PIInternetProtocolSinkVtbl_QueryInterface typedef ptr TYPE_IInternetProtocolSinkVtbl_QueryInterface
            TYPE_IInternetProtocolSinkVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolSink
            PIInternetProtocolSinkVtbl_AddRef typedef ptr TYPE_IInternetProtocolSinkVtbl_AddRef
            TYPE_IInternetProtocolSinkVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolSink
            PIInternetProtocolSinkVtbl_Release typedef ptr TYPE_IInternetProtocolSinkVtbl_Release
            TYPE_IInternetProtocolSinkVtbl_Switch typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolSink, :ptr PROTOCOLDATA
            PIInternetProtocolSinkVtbl_Switch typedef ptr TYPE_IInternetProtocolSinkVtbl_Switch
            TYPE_IInternetProtocolSinkVtbl_ReportProgress typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolSink, :ULONG, :LPCWSTR
            PIInternetProtocolSinkVtbl_ReportProgress typedef ptr TYPE_IInternetProtocolSinkVtbl_ReportProgress
            TYPE_IInternetProtocolSinkVtbl_ReportData typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolSink, :DWORD, :ULONG, :ULONG
            PIInternetProtocolSinkVtbl_ReportData typedef ptr TYPE_IInternetProtocolSinkVtbl_ReportData
            TYPE_IInternetProtocolSinkVtbl_ReportResult typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolSink, :HRESULT, :DWORD, :LPCWSTR
            PIInternetProtocolSinkVtbl_ReportResult typedef ptr TYPE_IInternetProtocolSinkVtbl_ReportResult
            IInternetProtocolSinkVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetProtocolSink>
              QueryInterface PIInternetProtocolSinkVtbl_QueryInterface ?
              AddRef PIInternetProtocolSinkVtbl_AddRef ?
              Release PIInternetProtocolSinkVtbl_Release ?
              Switch PIInternetProtocolSinkVtbl_Switch ?
              ReportProgress PIInternetProtocolSinkVtbl_ReportProgress ?
              ReportData PIInternetProtocolSinkVtbl_ReportData ?
              ReportResult PIInternetProtocolSinkVtbl_ReportResult ?
              ??Interface equ <>
              END_INTERFACE
            IInternetProtocolSinkVtbl ends
            IInternetProtocolSink struct
              lpVtbl POINTER ?
            IInternetProtocolSink ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
      endif
      ifndef _LPIINTERNETPROTOCOLSINKSTACKABLE_DEFINED
        _LPIINTERNETPROTOCOLSINKSTACKABLE_DEFINED equ <>
        externdef __MIDL_itf_urlmon_0000_0032_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0032_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IInternetProtocolSinkStackable_INTERFACE_DEFINED__
          __IInternetProtocolSinkStackable_INTERFACE_DEFINED__ equ <>
          LPIINTERNETPROTOCOLSINKStackable typedef ptr IInternetProtocolSinkStackable
          externdef IID_IInternetProtocolSinkStackable:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            TYPE_IInternetProtocolSinkStackableVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolSinkStackable, :REFIID, :ptr ptr
            PIInternetProtocolSinkStackableVtbl_QueryInterface typedef ptr TYPE_IInternetProtocolSinkStackableVtbl_QueryInterface
            TYPE_IInternetProtocolSinkStackableVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolSinkStackable
            PIInternetProtocolSinkStackableVtbl_AddRef typedef ptr TYPE_IInternetProtocolSinkStackableVtbl_AddRef
            TYPE_IInternetProtocolSinkStackableVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolSinkStackable
            PIInternetProtocolSinkStackableVtbl_Release typedef ptr TYPE_IInternetProtocolSinkStackableVtbl_Release
            TYPE_IInternetProtocolSinkStackableVtbl_SwitchSink typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolSinkStackable, :ptr IInternetProtocolSink
            PIInternetProtocolSinkStackableVtbl_SwitchSink typedef ptr TYPE_IInternetProtocolSinkStackableVtbl_SwitchSink
            TYPE_IInternetProtocolSinkStackableVtbl_CommitSwitch typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolSinkStackable
            PIInternetProtocolSinkStackableVtbl_CommitSwitch typedef ptr TYPE_IInternetProtocolSinkStackableVtbl_CommitSwitch
            TYPE_IInternetProtocolSinkStackableVtbl_RollbackSwitch typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolSinkStackable
            PIInternetProtocolSinkStackableVtbl_RollbackSwitch typedef ptr TYPE_IInternetProtocolSinkStackableVtbl_RollbackSwitch
            IInternetProtocolSinkStackableVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetProtocolSinkStackable>
              QueryInterface PIInternetProtocolSinkStackableVtbl_QueryInterface ?
              AddRef PIInternetProtocolSinkStackableVtbl_AddRef ?
              Release PIInternetProtocolSinkStackableVtbl_Release ?
              SwitchSink PIInternetProtocolSinkStackableVtbl_SwitchSink ?
              CommitSwitch PIInternetProtocolSinkStackableVtbl_CommitSwitch ?
              RollbackSwitch PIInternetProtocolSinkStackableVtbl_RollbackSwitch ?
              ??Interface equ <>
              END_INTERFACE
            IInternetProtocolSinkStackableVtbl ends
            IInternetProtocolSinkStackable struct
              lpVtbl POINTER ?
            IInternetProtocolSinkStackable ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
      endif
      ifndef _LPIINTERNETSESSION_DEFINED
        _LPIINTERNETSESSION_DEFINED equ <>
        externdef __MIDL_itf_urlmon_0000_0033_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0033_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IInternetSession_INTERFACE_DEFINED__
          __IInternetSession_INTERFACE_DEFINED__ equ <>
          LPIINTERNETSESSION typedef ptr IInternetSession
          OIBDG_FLAGS typedef SDWORD
          OIBDG_APARTMENTTHREADED equ 100h
          OIBDG_DATAONLY equ 1000h
          _tagOIBDG_FLAGS typedef OIBDG_FLAGS
          externdef IID_IInternetSession:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            TYPE_IInternetSessionVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IInternetSession, :REFIID, :ptr ptr
            PIInternetSessionVtbl_QueryInterface typedef ptr TYPE_IInternetSessionVtbl_QueryInterface
            TYPE_IInternetSessionVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IInternetSession
            PIInternetSessionVtbl_AddRef typedef ptr TYPE_IInternetSessionVtbl_AddRef
            TYPE_IInternetSessionVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IInternetSession
            PIInternetSessionVtbl_Release typedef ptr TYPE_IInternetSessionVtbl_Release
            TYPE_IInternetSessionVtbl_RegisterNameSpace typedef proto WIN_STD_CALL_CONV :ptr IInternetSession, :ptr IClassFactory, :REFCLSID, :LPCWSTR, :ULONG, :ptr LPCWSTR, :DWORD
            PIInternetSessionVtbl_RegisterNameSpace typedef ptr TYPE_IInternetSessionVtbl_RegisterNameSpace
            TYPE_IInternetSessionVtbl_UnregisterNameSpace typedef proto WIN_STD_CALL_CONV :ptr IInternetSession, :ptr IClassFactory, :LPCWSTR
            PIInternetSessionVtbl_UnregisterNameSpace typedef ptr TYPE_IInternetSessionVtbl_UnregisterNameSpace
            TYPE_IInternetSessionVtbl_RegisterMimeFilter typedef proto WIN_STD_CALL_CONV :ptr IInternetSession, :ptr IClassFactory, :REFCLSID, :LPCWSTR
            PIInternetSessionVtbl_RegisterMimeFilter typedef ptr TYPE_IInternetSessionVtbl_RegisterMimeFilter
            TYPE_IInternetSessionVtbl_UnregisterMimeFilter typedef proto WIN_STD_CALL_CONV :ptr IInternetSession, :ptr IClassFactory, :LPCWSTR
            PIInternetSessionVtbl_UnregisterMimeFilter typedef ptr TYPE_IInternetSessionVtbl_UnregisterMimeFilter
            TYPE_IInternetSessionVtbl_CreateBinding typedef proto WIN_STD_CALL_CONV :ptr IInternetSession, :LPBC, :LPCWSTR, :ptr IUnknown, :ptr ptr IUnknown, :ptr ptr IInternetProtocol, :DWORD
            PIInternetSessionVtbl_CreateBinding typedef ptr TYPE_IInternetSessionVtbl_CreateBinding
            TYPE_IInternetSessionVtbl_SetSessionOption typedef proto WIN_STD_CALL_CONV :ptr IInternetSession, :DWORD, :LPVOID, :DWORD, :DWORD
            PIInternetSessionVtbl_SetSessionOption typedef ptr TYPE_IInternetSessionVtbl_SetSessionOption
            TYPE_IInternetSessionVtbl_GetSessionOption typedef proto WIN_STD_CALL_CONV :ptr IInternetSession, :DWORD, :LPVOID, :ptr DWORD, :DWORD
            PIInternetSessionVtbl_GetSessionOption typedef ptr TYPE_IInternetSessionVtbl_GetSessionOption
            IInternetSessionVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetSession>
              QueryInterface PIInternetSessionVtbl_QueryInterface ?
              AddRef PIInternetSessionVtbl_AddRef ?
              Release PIInternetSessionVtbl_Release ?
              RegisterNameSpace PIInternetSessionVtbl_RegisterNameSpace ?
              UnregisterNameSpace PIInternetSessionVtbl_UnregisterNameSpace ?
              RegisterMimeFilter PIInternetSessionVtbl_RegisterMimeFilter ?
              UnregisterMimeFilter PIInternetSessionVtbl_UnregisterMimeFilter ?
              CreateBinding PIInternetSessionVtbl_CreateBinding ?
              SetSessionOption PIInternetSessionVtbl_SetSessionOption ?
              GetSessionOption PIInternetSessionVtbl_GetSessionOption ?
              ??Interface equ <>
              END_INTERFACE
            IInternetSessionVtbl ends
            IInternetSession struct
              lpVtbl POINTER ?
            IInternetSession ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
      endif
      ifndef _LPIINTERNETTHREADSWITCH_DEFINED
        _LPIINTERNETTHREADSWITCH_DEFINED equ <>
        externdef __MIDL_itf_urlmon_0000_0034_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0034_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IInternetThreadSwitch_INTERFACE_DEFINED__
          __IInternetThreadSwitch_INTERFACE_DEFINED__ equ <>
          LPIINTERNETTHREADSWITCH typedef ptr IInternetThreadSwitch
          externdef IID_IInternetThreadSwitch:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            TYPE_IInternetThreadSwitchVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IInternetThreadSwitch, :REFIID, :ptr ptr
            PIInternetThreadSwitchVtbl_QueryInterface typedef ptr TYPE_IInternetThreadSwitchVtbl_QueryInterface
            TYPE_IInternetThreadSwitchVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IInternetThreadSwitch
            PIInternetThreadSwitchVtbl_AddRef typedef ptr TYPE_IInternetThreadSwitchVtbl_AddRef
            TYPE_IInternetThreadSwitchVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IInternetThreadSwitch
            PIInternetThreadSwitchVtbl_Release typedef ptr TYPE_IInternetThreadSwitchVtbl_Release
            TYPE_IInternetThreadSwitchVtbl_repare typedef proto WIN_STD_CALL_CONV :ptr IInternetThreadSwitch
            PIInternetThreadSwitchVtbl_repare typedef ptr TYPE_IInternetThreadSwitchVtbl_repare
            TYPE_IInternetThreadSwitchVtbl_Continue typedef proto WIN_STD_CALL_CONV :ptr IInternetThreadSwitch
            PIInternetThreadSwitchVtbl_Continue typedef ptr TYPE_IInternetThreadSwitchVtbl_Continue
            IInternetThreadSwitchVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetThreadSwitch>
              QueryInterface PIInternetThreadSwitchVtbl_QueryInterface ?
              AddRef PIInternetThreadSwitchVtbl_AddRef ?
              Release PIInternetThreadSwitchVtbl_Release ?
              repare PIInternetThreadSwitchVtbl_repare ?
              Continue PIInternetThreadSwitchVtbl_Continue ?
              ??Interface equ <>
              END_INTERFACE
            IInternetThreadSwitchVtbl ends
            IInternetThreadSwitch struct
              lpVtbl POINTER ?
            IInternetThreadSwitch ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
      endif
      ifndef _LPIINTERNETPRIORITY_DEFINED
        _LPIINTERNETPRIORITY_DEFINED equ <>
        externdef __MIDL_itf_urlmon_0000_0035_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0035_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IInternetPriority_INTERFACE_DEFINED__
          __IInternetPriority_INTERFACE_DEFINED__ equ <>
          LPIINTERNETPRIORITY typedef ptr IInternetPriority
          externdef IID_IInternetPriority:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            TYPE_IInternetPriorityVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IInternetPriority, :REFIID, :ptr ptr
            PIInternetPriorityVtbl_QueryInterface typedef ptr TYPE_IInternetPriorityVtbl_QueryInterface
            TYPE_IInternetPriorityVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IInternetPriority
            PIInternetPriorityVtbl_AddRef typedef ptr TYPE_IInternetPriorityVtbl_AddRef
            TYPE_IInternetPriorityVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IInternetPriority
            PIInternetPriorityVtbl_Release typedef ptr TYPE_IInternetPriorityVtbl_Release
            TYPE_IInternetPriorityVtbl_SetPriority typedef proto WIN_STD_CALL_CONV :ptr IInternetPriority, :LONG
            PIInternetPriorityVtbl_SetPriority typedef ptr TYPE_IInternetPriorityVtbl_SetPriority
            TYPE_IInternetPriorityVtbl_GetPriority typedef proto WIN_STD_CALL_CONV :ptr IInternetPriority, :ptr LONG
            PIInternetPriorityVtbl_GetPriority typedef ptr TYPE_IInternetPriorityVtbl_GetPriority
            IInternetPriorityVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetPriority>
              QueryInterface PIInternetPriorityVtbl_QueryInterface ?
              AddRef PIInternetPriorityVtbl_AddRef ?
              Release PIInternetPriorityVtbl_Release ?
              SetPriority PIInternetPriorityVtbl_SetPriority ?
              GetPriority PIInternetPriorityVtbl_GetPriority ?
              ??Interface equ <>
              END_INTERFACE
            IInternetPriorityVtbl ends
            IInternetPriority struct
              lpVtbl POINTER ?
            IInternetPriority ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
      endif
      ifndef _LPIINTERNETPROTOCOLINFO_DEFINED
        _LPIINTERNETPROTOCOLINFO_DEFINED equ <>
        externdef __MIDL_itf_urlmon_0000_0036_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0036_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IInternetProtocolInfo_INTERFACE_DEFINED__
          __IInternetProtocolInfo_INTERFACE_DEFINED__ equ <>
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
            TYPE_IInternetProtocolInfoVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolInfo, :REFIID, :ptr ptr
            PIInternetProtocolInfoVtbl_QueryInterface typedef ptr TYPE_IInternetProtocolInfoVtbl_QueryInterface
            TYPE_IInternetProtocolInfoVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolInfo
            PIInternetProtocolInfoVtbl_AddRef typedef ptr TYPE_IInternetProtocolInfoVtbl_AddRef
            TYPE_IInternetProtocolInfoVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolInfo
            PIInternetProtocolInfoVtbl_Release typedef ptr TYPE_IInternetProtocolInfoVtbl_Release
            TYPE_IInternetProtocolInfoVtbl_arseUrl typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolInfo, :LPCWSTR, :PARSEACTION, :DWORD, :LPWSTR, :DWORD, :ptr DWORD, :DWORD
            PIInternetProtocolInfoVtbl_arseUrl typedef ptr TYPE_IInternetProtocolInfoVtbl_arseUrl
            TYPE_IInternetProtocolInfoVtbl_CombineUrl typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolInfo, :LPCWSTR, :LPCWSTR, :DWORD, :LPWSTR, :DWORD, :ptr DWORD, :DWORD
            PIInternetProtocolInfoVtbl_CombineUrl typedef ptr TYPE_IInternetProtocolInfoVtbl_CombineUrl
            TYPE_IInternetProtocolInfoVtbl_CompareUrl typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolInfo, :LPCWSTR, :LPCWSTR, :DWORD
            PIInternetProtocolInfoVtbl_CompareUrl typedef ptr TYPE_IInternetProtocolInfoVtbl_CompareUrl
            TYPE_IInternetProtocolInfoVtbl_QueryInfo typedef proto WIN_STD_CALL_CONV :ptr IInternetProtocolInfo, :LPCWSTR, :QUERYOPTION, :DWORD, :LPVOID, :DWORD, :ptr DWORD, :DWORD
            PIInternetProtocolInfoVtbl_QueryInfo typedef ptr TYPE_IInternetProtocolInfoVtbl_QueryInfo
            IInternetProtocolInfoVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetProtocolInfo>
              QueryInterface PIInternetProtocolInfoVtbl_QueryInterface ?
              AddRef PIInternetProtocolInfoVtbl_AddRef ?
              Release PIInternetProtocolInfoVtbl_Release ?
              arseUrl PIInternetProtocolInfoVtbl_arseUrl ?
              CombineUrl PIInternetProtocolInfoVtbl_CombineUrl ?
              CompareUrl PIInternetProtocolInfoVtbl_CompareUrl ?
              QueryInfo PIInternetProtocolInfoVtbl_QueryInfo ?
              ??Interface equ <>
              END_INTERFACE
            IInternetProtocolInfoVtbl ends
            IInternetProtocolInfo struct
              lpVtbl POINTER ?
            IInternetProtocolInfo ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
        ifndef URLMON_STRICT
          PARSE_ENCODE equ <PARSE_ENCODE_IS_UNESCAPE>
          PARSE_DECODE equ <PARSE_DECODE_IS_ESCAPE>
        endif
      endif
      IOInet equ <IInternet>
      IOInetBindInfo equ <IInternetBindInfo>
      IOInetBindInfoEx equ <IInternetBindInfoEx>
      IOInetProtocolRoot equ <IInternetProtocolRoot>
      IOInetProtocol equ <IInternetProtocol>
      if (_WIN32_IE ge _WIN32_IE_IE70)
        IOInetProtocolEx equ <IInternetProtocolEx>
      endif
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
      @DefProto DllImport, CoInternetCombineUrl, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :DWORD, :LPWSTR, :DWORD, :ptr DWORD, :DWORD>, 28
      if (_WIN32_IE ge _WIN32_IE_IE70)
        @DefProto DllImport, CoInternetCombineUrlEx, WIN_STD_CALL_CONV,, <:ptr IUri, :LPCWSTR, :DWORD, :ptr ptr IUri, :DWORD_PTR>, 20
        @DefProto DllImport, CoInternetCombineIUri, WIN_STD_CALL_CONV,, <:ptr IUri, :ptr IUri, :DWORD, :ptr ptr IUri, :DWORD_PTR>, 20
      endif
      @DefProto DllImport, CoInternetCompareUrl, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :DWORD>, 12
      @DefProto DllImport, CoInternetGetProtocolFlags, WIN_STD_CALL_CONV,, <:LPCWSTR, :ptr DWORD, :DWORD>, 12
      @DefProto DllImport, CoInternetQueryInfo, WIN_STD_CALL_CONV,, <:LPCWSTR, :QUERYOPTION, :DWORD, :LPVOID, :DWORD, :ptr DWORD, :DWORD>, 28
      @DefProto DllImport, CoInternetGetSession, WIN_STD_CALL_CONV,, <:DWORD, :ptr ptr IInternetSession, :DWORD>, 12
      @DefProto DllImport, CoInternetGetSecurityUrl, WIN_STD_CALL_CONV,, <:LPCWSTR, :ptr LPWSTR, :PSUACTION, :DWORD>, 16
      @DefProto DllImport, AsyncInstallDistributionUnit, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPCWSTR, :DWORD, :DWORD, :LPCWSTR, :ptr IBindCtx, :LPVOID, :DWORD>, 36
      if (_WIN32_IE ge _WIN32_IE_IE70)
        @DefProto DllImport, CoInternetGetSecurityUrlEx, WIN_STD_CALL_CONV,, <:ptr IUri, :ptr ptr IUri, :PSUACTION, :DWORD_PTR>, 16
      endif
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
          SET_FEATURE_ON_THREAD equ 00000001h
          SET_FEATURE_ON_PROCESS equ 00000002h
          SET_FEATURE_IN_REGISTRY equ 00000004h
          SET_FEATURE_ON_THREAD_LOCALMACHINE equ 00000008h
          SET_FEATURE_ON_THREAD_INTRANET equ 00000010h
          SET_FEATURE_ON_THREAD_TRUSTED equ 00000020h
          SET_FEATURE_ON_THREAD_INTERNET equ 00000040h
          SET_FEATURE_ON_THREAD_RESTRICTED equ 00000080h
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
      OInetCompareUrl equ <CoInternetCompareUrl>
      OInetQueryInfo equ <CoInternetQueryInfo>
      OInetGetSession equ <CoInternetGetSession>
    endif
    PROTOCOLFLAG_NO_PICS_CHECK equ 00000001h
    @DefProto DllImport, IEGetUserPrivateNamespaceName, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, CoInternetCreateSecurityManager, WIN_STD_CALL_CONV,, <:ptr IServiceProvider, :ptr ptr IInternetSecurityManager, :DWORD>, 12
    @DefProto DllImport, CoInternetCreateZoneManager, WIN_STD_CALL_CONV,, <:ptr IServiceProvider, :ptr ptr IInternetZoneManager, :DWORD>, 12
    externdef CLSID_InternetSecurityManager:IID
    externdef CLSID_InternetZoneManager:IID
    if (_WIN32_IE ge _WIN32_IE_IE60SP2)
      externdef CLSID_PersistentZoneIdentifier:IID
    endif
    SID_SInternetSecurityManager equ <IID_IInternetSecurityManager>
    if (_WIN32_IE ge _WIN32_IE_IE60SP2)
      SID_SInternetSecurityManagerEx equ <IID_IInternetSecurityManagerEx>
    endif
    if (_WIN32_IE ge _WIN32_IE_IE70)
      SID_SInternetSecurityManagerEx2 equ <IID_IInternetSecurityManagerEx2>
    endif
    SID_SInternetHostSecurityManager equ <IID_IInternetHostSecurityManager>
    ifndef _LPINTERNETSECURITYMGRSITE_DEFINED
      _LPINTERNETSECURITYMGRSITE_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0037_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0037_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IInternetSecurityMgrSite_INTERFACE_DEFINED__
        __IInternetSecurityMgrSite_INTERFACE_DEFINED__ equ <>
        externdef IID_IInternetSecurityMgrSite:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          TYPE_IInternetSecurityMgrSiteVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityMgrSite, :REFIID, :ptr ptr
          PIInternetSecurityMgrSiteVtbl_QueryInterface typedef ptr TYPE_IInternetSecurityMgrSiteVtbl_QueryInterface
          TYPE_IInternetSecurityMgrSiteVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityMgrSite
          PIInternetSecurityMgrSiteVtbl_AddRef typedef ptr TYPE_IInternetSecurityMgrSiteVtbl_AddRef
          TYPE_IInternetSecurityMgrSiteVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityMgrSite
          PIInternetSecurityMgrSiteVtbl_Release typedef ptr TYPE_IInternetSecurityMgrSiteVtbl_Release
          TYPE_IInternetSecurityMgrSiteVtbl_GetWindow typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityMgrSite, :ptr HWND
          PIInternetSecurityMgrSiteVtbl_GetWindow typedef ptr TYPE_IInternetSecurityMgrSiteVtbl_GetWindow
          TYPE_IInternetSecurityMgrSiteVtbl_EnableModeless typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityMgrSite, :BOOL
          PIInternetSecurityMgrSiteVtbl_EnableModeless typedef ptr TYPE_IInternetSecurityMgrSiteVtbl_EnableModeless
          IInternetSecurityMgrSiteVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IInternetSecurityMgrSite>
            QueryInterface PIInternetSecurityMgrSiteVtbl_QueryInterface ?
            AddRef PIInternetSecurityMgrSiteVtbl_AddRef ?
            Release PIInternetSecurityMgrSiteVtbl_Release ?
            GetWindow PIInternetSecurityMgrSiteVtbl_GetWindow ?
            EnableModeless PIInternetSecurityMgrSiteVtbl_EnableModeless ?
            ??Interface equ <>
            END_INTERFACE
          IInternetSecurityMgrSiteVtbl ends
          IInternetSecurityMgrSite struct
            lpVtbl POINTER ?
          IInternetSecurityMgrSite ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    ifndef _LPINTERNETSECURITYMANANGER_DEFINED
      _LPINTERNETSECURITYMANANGER_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0038_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0038_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IInternetSecurityManager_INTERFACE_DEFINED__
        __IInternetSecurityManager_INTERFACE_DEFINED__ equ <>
        MUTZ_NOSAVEDFILECHECK equ 00000001h
        MUTZ_ISFILE equ 00000002h
        MUTZ_ACCEPT_WILDCARD_SCHEME equ 00000080h
        MUTZ_ENFORCERESTRICTED equ 00000100h
        MUTZ_RESERVED equ 00000200h
        MUTZ_REQUIRESAVEDFILECHECK equ 00000400h
        MUTZ_DONT_UNESCAPE equ 00000800h
        MUTZ_DONT_USE_CACHE equ 00001000h
        MUTZ_FORCE_INTRANET_FLAGS equ 00002000h
        MUTZ_IGNORE_ZONE_MAPPINGS equ 00004000h
        MAX_SIZE_SECURITY_ID equ 512
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
        PUAFOUT typedef SDWORD
        PUAFOUT_DEFAULT equ 0
        PUAFOUT_ISLOCKZONEPOLICY equ 1h
        __MIDL_IInternetSecurityManager_0002 typedef PUAFOUT
        SZM_FLAGS typedef SDWORD
        SZM_CREATE equ 0
        SZM_DELETE equ 1h
        __MIDL_IInternetSecurityManager_0003 typedef SZM_FLAGS
        externdef IID_IInternetSecurityManager:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          TYPE_IInternetSecurityManagerVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManager, :REFIID, :ptr ptr
          PIInternetSecurityManagerVtbl_QueryInterface typedef ptr TYPE_IInternetSecurityManagerVtbl_QueryInterface
          TYPE_IInternetSecurityManagerVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManager
          PIInternetSecurityManagerVtbl_AddRef typedef ptr TYPE_IInternetSecurityManagerVtbl_AddRef
          TYPE_IInternetSecurityManagerVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManager
          PIInternetSecurityManagerVtbl_Release typedef ptr TYPE_IInternetSecurityManagerVtbl_Release
          TYPE_IInternetSecurityManagerVtbl_SetSecuritySite typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManager, :ptr IInternetSecurityMgrSite
          PIInternetSecurityManagerVtbl_SetSecuritySite typedef ptr TYPE_IInternetSecurityManagerVtbl_SetSecuritySite
          TYPE_IInternetSecurityManagerVtbl_GetSecuritySite typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManager, :ptr ptr IInternetSecurityMgrSite
          PIInternetSecurityManagerVtbl_GetSecuritySite typedef ptr TYPE_IInternetSecurityManagerVtbl_GetSecuritySite
          TYPE_IInternetSecurityManagerVtbl_MapUrlToZone typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManager, :LPCWSTR, :ptr DWORD, :DWORD
          PIInternetSecurityManagerVtbl_MapUrlToZone typedef ptr TYPE_IInternetSecurityManagerVtbl_MapUrlToZone
          TYPE_IInternetSecurityManagerVtbl_GetSecurityId typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManager, :LPCWSTR, :ptr BYTE, :ptr DWORD, :DWORD_PTR
          PIInternetSecurityManagerVtbl_GetSecurityId typedef ptr TYPE_IInternetSecurityManagerVtbl_GetSecurityId
          TYPE_IInternetSecurityManagerVtbl_rocessUrlAction typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManager, :LPCWSTR, :DWORD, :ptr BYTE, :DWORD, :ptr BYTE, :DWORD, :DWORD, :DWORD
          PIInternetSecurityManagerVtbl_rocessUrlAction typedef ptr TYPE_IInternetSecurityManagerVtbl_rocessUrlAction
          TYPE_IInternetSecurityManagerVtbl_QueryCustomPolicy typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManager, :LPCWSTR, :REFGUID, :ptr ptr BYTE, :ptr DWORD, :ptr BYTE, :DWORD, :DWORD
          PIInternetSecurityManagerVtbl_QueryCustomPolicy typedef ptr TYPE_IInternetSecurityManagerVtbl_QueryCustomPolicy
          TYPE_IInternetSecurityManagerVtbl_SetZoneMapping typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManager, :DWORD, :LPCWSTR, :DWORD
          PIInternetSecurityManagerVtbl_SetZoneMapping typedef ptr TYPE_IInternetSecurityManagerVtbl_SetZoneMapping
          TYPE_IInternetSecurityManagerVtbl_GetZoneMappings typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManager, :DWORD, :ptr ptr IEnumString, :DWORD
          PIInternetSecurityManagerVtbl_GetZoneMappings typedef ptr TYPE_IInternetSecurityManagerVtbl_GetZoneMappings
          IInternetSecurityManagerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IInternetSecurityManager>
            QueryInterface PIInternetSecurityManagerVtbl_QueryInterface ?
            AddRef PIInternetSecurityManagerVtbl_AddRef ?
            Release PIInternetSecurityManagerVtbl_Release ?
            SetSecuritySite PIInternetSecurityManagerVtbl_SetSecuritySite ?
            GetSecuritySite PIInternetSecurityManagerVtbl_GetSecuritySite ?
            MapUrlToZone PIInternetSecurityManagerVtbl_MapUrlToZone ?
            GetSecurityId PIInternetSecurityManagerVtbl_GetSecurityId ?
            rocessUrlAction PIInternetSecurityManagerVtbl_rocessUrlAction ?
            QueryCustomPolicy PIInternetSecurityManagerVtbl_QueryCustomPolicy ?
            SetZoneMapping PIInternetSecurityManagerVtbl_SetZoneMapping ?
            GetZoneMappings PIInternetSecurityManagerVtbl_GetZoneMappings ?
            ??Interface equ <>
            END_INTERFACE
          IInternetSecurityManagerVtbl ends
          IInternetSecurityManager struct
            lpVtbl POINTER ?
          IInternetSecurityManager ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    if (_WIN32_IE ge _WIN32_IE_IE60SP2)
      ifndef _LPINTERNETSECURITYMANANGEREX_DEFINED
        _LPINTERNETSECURITYMANANGEREX_DEFINED equ <>
        externdef __MIDL_itf_urlmon_0000_0039_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0039_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IInternetSecurityManagerEx_INTERFACE_DEFINED__
          __IInternetSecurityManagerEx_INTERFACE_DEFINED__ equ <>
          externdef IID_IInternetSecurityManagerEx:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            TYPE_IInternetSecurityManagerExVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManagerEx, :REFIID, :ptr ptr
            PIInternetSecurityManagerExVtbl_QueryInterface typedef ptr TYPE_IInternetSecurityManagerExVtbl_QueryInterface
            TYPE_IInternetSecurityManagerExVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManagerEx
            PIInternetSecurityManagerExVtbl_AddRef typedef ptr TYPE_IInternetSecurityManagerExVtbl_AddRef
            TYPE_IInternetSecurityManagerExVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManagerEx
            PIInternetSecurityManagerExVtbl_Release typedef ptr TYPE_IInternetSecurityManagerExVtbl_Release
            TYPE_IInternetSecurityManagerExVtbl_SetSecuritySite typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManagerEx, :ptr IInternetSecurityMgrSite
            PIInternetSecurityManagerExVtbl_SetSecuritySite typedef ptr TYPE_IInternetSecurityManagerExVtbl_SetSecuritySite
            TYPE_IInternetSecurityManagerExVtbl_GetSecuritySite typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManagerEx, :ptr ptr IInternetSecurityMgrSite
            PIInternetSecurityManagerExVtbl_GetSecuritySite typedef ptr TYPE_IInternetSecurityManagerExVtbl_GetSecuritySite
            TYPE_IInternetSecurityManagerExVtbl_MapUrlToZone typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManagerEx, :LPCWSTR, :ptr DWORD, :DWORD
            PIInternetSecurityManagerExVtbl_MapUrlToZone typedef ptr TYPE_IInternetSecurityManagerExVtbl_MapUrlToZone
            TYPE_IInternetSecurityManagerExVtbl_GetSecurityId typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManagerEx, :LPCWSTR, :ptr BYTE, :ptr DWORD, :DWORD_PTR
            PIInternetSecurityManagerExVtbl_GetSecurityId typedef ptr TYPE_IInternetSecurityManagerExVtbl_GetSecurityId
            TYPE_IInternetSecurityManagerExVtbl_rocessUrlAction typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManagerEx, :LPCWSTR, :DWORD, :ptr BYTE, :DWORD, :ptr BYTE, :DWORD, :DWORD, :DWORD
            PIInternetSecurityManagerExVtbl_rocessUrlAction typedef ptr TYPE_IInternetSecurityManagerExVtbl_rocessUrlAction
            TYPE_IInternetSecurityManagerExVtbl_QueryCustomPolicy typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManagerEx, :LPCWSTR, :REFGUID, :ptr ptr BYTE, :ptr DWORD, :ptr BYTE, :DWORD, :DWORD
            PIInternetSecurityManagerExVtbl_QueryCustomPolicy typedef ptr TYPE_IInternetSecurityManagerExVtbl_QueryCustomPolicy
            TYPE_IInternetSecurityManagerExVtbl_SetZoneMapping typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManagerEx, :DWORD, :LPCWSTR, :DWORD
            PIInternetSecurityManagerExVtbl_SetZoneMapping typedef ptr TYPE_IInternetSecurityManagerExVtbl_SetZoneMapping
            TYPE_IInternetSecurityManagerExVtbl_GetZoneMappings typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManagerEx, :DWORD, :ptr ptr IEnumString, :DWORD
            PIInternetSecurityManagerExVtbl_GetZoneMappings typedef ptr TYPE_IInternetSecurityManagerExVtbl_GetZoneMappings
            TYPE_IInternetSecurityManagerExVtbl_rocessUrlActionEx typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManagerEx, :LPCWSTR, :DWORD, :ptr BYTE, :DWORD, :ptr BYTE, :DWORD, :DWORD, :DWORD, :ptr DWORD
            PIInternetSecurityManagerExVtbl_rocessUrlActionEx typedef ptr TYPE_IInternetSecurityManagerExVtbl_rocessUrlActionEx
            IInternetSecurityManagerExVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetSecurityManagerEx>
              QueryInterface PIInternetSecurityManagerExVtbl_QueryInterface ?
              AddRef PIInternetSecurityManagerExVtbl_AddRef ?
              Release PIInternetSecurityManagerExVtbl_Release ?
              SetSecuritySite PIInternetSecurityManagerExVtbl_SetSecuritySite ?
              GetSecuritySite PIInternetSecurityManagerExVtbl_GetSecuritySite ?
              MapUrlToZone PIInternetSecurityManagerExVtbl_MapUrlToZone ?
              GetSecurityId PIInternetSecurityManagerExVtbl_GetSecurityId ?
              rocessUrlAction PIInternetSecurityManagerExVtbl_rocessUrlAction ?
              QueryCustomPolicy PIInternetSecurityManagerExVtbl_QueryCustomPolicy ?
              SetZoneMapping PIInternetSecurityManagerExVtbl_SetZoneMapping ?
              GetZoneMappings PIInternetSecurityManagerExVtbl_GetZoneMappings ?
              rocessUrlActionEx PIInternetSecurityManagerExVtbl_rocessUrlActionEx ?
              ??Interface equ <>
              END_INTERFACE
            IInternetSecurityManagerExVtbl ends
            IInternetSecurityManagerEx struct
              lpVtbl POINTER ?
            IInternetSecurityManagerEx ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
      endif
    endif
    if (_WIN32_IE ge _WIN32_IE_IE70)
      ifndef _LPINTERNETSECURITYMANANGEREx2_DEFINED
        _LPINTERNETSECURITYMANANGEREx2_DEFINED equ <>
        externdef __MIDL_itf_urlmon_0000_0040_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0040_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IInternetSecurityManagerEx2_INTERFACE_DEFINED__
          __IInternetSecurityManagerEx2_INTERFACE_DEFINED__ equ <>
          externdef IID_IInternetSecurityManagerEx2:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            TYPE_IInternetSecurityManagerEx2Vtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManagerEx2, :REFIID, :ptr ptr
            PIInternetSecurityManagerEx2Vtbl_QueryInterface typedef ptr TYPE_IInternetSecurityManagerEx2Vtbl_QueryInterface
            TYPE_IInternetSecurityManagerEx2Vtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManagerEx2
            PIInternetSecurityManagerEx2Vtbl_AddRef typedef ptr TYPE_IInternetSecurityManagerEx2Vtbl_AddRef
            TYPE_IInternetSecurityManagerEx2Vtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManagerEx2
            PIInternetSecurityManagerEx2Vtbl_Release typedef ptr TYPE_IInternetSecurityManagerEx2Vtbl_Release
            TYPE_IInternetSecurityManagerEx2Vtbl_SetSecuritySite typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManagerEx2, :ptr IInternetSecurityMgrSite
            PIInternetSecurityManagerEx2Vtbl_SetSecuritySite typedef ptr TYPE_IInternetSecurityManagerEx2Vtbl_SetSecuritySite
            TYPE_IInternetSecurityManagerEx2Vtbl_GetSecuritySite typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManagerEx2, :ptr ptr IInternetSecurityMgrSite
            PIInternetSecurityManagerEx2Vtbl_GetSecuritySite typedef ptr TYPE_IInternetSecurityManagerEx2Vtbl_GetSecuritySite
            TYPE_IInternetSecurityManagerEx2Vtbl_MapUrlToZone typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManagerEx2, :LPCWSTR, :ptr DWORD, :DWORD
            PIInternetSecurityManagerEx2Vtbl_MapUrlToZone typedef ptr TYPE_IInternetSecurityManagerEx2Vtbl_MapUrlToZone
            TYPE_IInternetSecurityManagerEx2Vtbl_GetSecurityId typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManagerEx2, :LPCWSTR, :ptr BYTE, :ptr DWORD, :DWORD_PTR
            PIInternetSecurityManagerEx2Vtbl_GetSecurityId typedef ptr TYPE_IInternetSecurityManagerEx2Vtbl_GetSecurityId
            TYPE_IInternetSecurityManagerEx2Vtbl_rocessUrlAction typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManagerEx2, :LPCWSTR, :DWORD, :ptr BYTE, :DWORD, :ptr BYTE, :DWORD, :DWORD, :DWORD
            PIInternetSecurityManagerEx2Vtbl_rocessUrlAction typedef ptr TYPE_IInternetSecurityManagerEx2Vtbl_rocessUrlAction
            TYPE_IInternetSecurityManagerEx2Vtbl_QueryCustomPolicy typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManagerEx2, :LPCWSTR, :REFGUID, :ptr ptr BYTE, :ptr DWORD, :ptr BYTE, :DWORD, :DWORD
            PIInternetSecurityManagerEx2Vtbl_QueryCustomPolicy typedef ptr TYPE_IInternetSecurityManagerEx2Vtbl_QueryCustomPolicy
            TYPE_IInternetSecurityManagerEx2Vtbl_SetZoneMapping typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManagerEx2, :DWORD, :LPCWSTR, :DWORD
            PIInternetSecurityManagerEx2Vtbl_SetZoneMapping typedef ptr TYPE_IInternetSecurityManagerEx2Vtbl_SetZoneMapping
            TYPE_IInternetSecurityManagerEx2Vtbl_GetZoneMappings typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManagerEx2, :DWORD, :ptr ptr IEnumString, :DWORD
            PIInternetSecurityManagerEx2Vtbl_GetZoneMappings typedef ptr TYPE_IInternetSecurityManagerEx2Vtbl_GetZoneMappings
            TYPE_IInternetSecurityManagerEx2Vtbl_rocessUrlActionEx typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManagerEx2, :LPCWSTR, :DWORD, :ptr BYTE, :DWORD, :ptr BYTE, :DWORD, :DWORD, :DWORD, :ptr DWORD
            PIInternetSecurityManagerEx2Vtbl_rocessUrlActionEx typedef ptr TYPE_IInternetSecurityManagerEx2Vtbl_rocessUrlActionEx
            TYPE_IInternetSecurityManagerEx2Vtbl_MapUrlToZoneEx2 typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManagerEx2, :ptr IUri, :ptr DWORD, :DWORD, :ptr LPWSTR, :ptr DWORD
            PIInternetSecurityManagerEx2Vtbl_MapUrlToZoneEx2 typedef ptr TYPE_IInternetSecurityManagerEx2Vtbl_MapUrlToZoneEx2
            TYPE_IInternetSecurityManagerEx2Vtbl_rocessUrlActionEx2 typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManagerEx2, :ptr IUri, :DWORD, :ptr BYTE, :DWORD, :ptr BYTE, :DWORD, :DWORD, :DWORD_PTR, :ptr DWORD
            PIInternetSecurityManagerEx2Vtbl_rocessUrlActionEx2 typedef ptr TYPE_IInternetSecurityManagerEx2Vtbl_rocessUrlActionEx2
            TYPE_IInternetSecurityManagerEx2Vtbl_GetSecurityIdEx2 typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManagerEx2, :ptr IUri, :ptr BYTE, :ptr DWORD, :DWORD_PTR
            PIInternetSecurityManagerEx2Vtbl_GetSecurityIdEx2 typedef ptr TYPE_IInternetSecurityManagerEx2Vtbl_GetSecurityIdEx2
            TYPE_IInternetSecurityManagerEx2Vtbl_QueryCustomPolicyEx2 typedef proto WIN_STD_CALL_CONV :ptr IInternetSecurityManagerEx2, :ptr IUri, :REFGUID, :ptr ptr BYTE, :ptr DWORD, :ptr BYTE, :DWORD, :DWORD_PTR
            PIInternetSecurityManagerEx2Vtbl_QueryCustomPolicyEx2 typedef ptr TYPE_IInternetSecurityManagerEx2Vtbl_QueryCustomPolicyEx2
            IInternetSecurityManagerEx2Vtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetSecurityManagerEx2>
              QueryInterface PIInternetSecurityManagerEx2Vtbl_QueryInterface ?
              AddRef PIInternetSecurityManagerEx2Vtbl_AddRef ?
              Release PIInternetSecurityManagerEx2Vtbl_Release ?
              SetSecuritySite PIInternetSecurityManagerEx2Vtbl_SetSecuritySite ?
              GetSecuritySite PIInternetSecurityManagerEx2Vtbl_GetSecuritySite ?
              MapUrlToZone PIInternetSecurityManagerEx2Vtbl_MapUrlToZone ?
              GetSecurityId PIInternetSecurityManagerEx2Vtbl_GetSecurityId ?
              rocessUrlAction PIInternetSecurityManagerEx2Vtbl_rocessUrlAction ?
              QueryCustomPolicy PIInternetSecurityManagerEx2Vtbl_QueryCustomPolicy ?
              SetZoneMapping PIInternetSecurityManagerEx2Vtbl_SetZoneMapping ?
              GetZoneMappings PIInternetSecurityManagerEx2Vtbl_GetZoneMappings ?
              rocessUrlActionEx PIInternetSecurityManagerEx2Vtbl_rocessUrlActionEx ?
              MapUrlToZoneEx2 PIInternetSecurityManagerEx2Vtbl_MapUrlToZoneEx2 ?
              rocessUrlActionEx2 PIInternetSecurityManagerEx2Vtbl_rocessUrlActionEx2 ?
              GetSecurityIdEx2 PIInternetSecurityManagerEx2Vtbl_GetSecurityIdEx2 ?
              QueryCustomPolicyEx2 PIInternetSecurityManagerEx2Vtbl_QueryCustomPolicyEx2 ?
              ??Interface equ <>
              END_INTERFACE
            IInternetSecurityManagerEx2Vtbl ends
            IInternetSecurityManagerEx2 struct
              lpVtbl POINTER ?
            IInternetSecurityManagerEx2 ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
      endif
    endif
    if (_WIN32_IE ge _WIN32_IE_IE60SP2)
      externdef __MIDL_itf_urlmon_0000_0041_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0041_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IZoneIdentifier_INTERFACE_DEFINED__
        __IZoneIdentifier_INTERFACE_DEFINED__ equ <>
        externdef IID_IZoneIdentifier:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          TYPE_IZoneIdentifierVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IZoneIdentifier, :REFIID, :ptr ptr
          PIZoneIdentifierVtbl_QueryInterface typedef ptr TYPE_IZoneIdentifierVtbl_QueryInterface
          TYPE_IZoneIdentifierVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IZoneIdentifier
          PIZoneIdentifierVtbl_AddRef typedef ptr TYPE_IZoneIdentifierVtbl_AddRef
          TYPE_IZoneIdentifierVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IZoneIdentifier
          PIZoneIdentifierVtbl_Release typedef ptr TYPE_IZoneIdentifierVtbl_Release
          TYPE_IZoneIdentifierVtbl_GetId typedef proto WIN_STD_CALL_CONV :ptr IZoneIdentifier, :ptr DWORD
          PIZoneIdentifierVtbl_GetId typedef ptr TYPE_IZoneIdentifierVtbl_GetId
          TYPE_IZoneIdentifierVtbl_SetId typedef proto WIN_STD_CALL_CONV :ptr IZoneIdentifier, :DWORD
          PIZoneIdentifierVtbl_SetId typedef ptr TYPE_IZoneIdentifierVtbl_SetId
          TYPE_IZoneIdentifierVtbl_Remove typedef proto WIN_STD_CALL_CONV :ptr IZoneIdentifier
          PIZoneIdentifierVtbl_Remove typedef ptr TYPE_IZoneIdentifierVtbl_Remove
          IZoneIdentifierVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IZoneIdentifier>
            QueryInterface PIZoneIdentifierVtbl_QueryInterface ?
            AddRef PIZoneIdentifierVtbl_AddRef ?
            Release PIZoneIdentifierVtbl_Release ?
            GetId PIZoneIdentifierVtbl_GetId ?
            SetId PIZoneIdentifierVtbl_SetId ?
            Remove PIZoneIdentifierVtbl_Remove ?
            ??Interface equ <>
            END_INTERFACE
          IZoneIdentifierVtbl ends
          IZoneIdentifier struct
            lpVtbl POINTER ?
          IZoneIdentifier ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    if (_WIN32_IE ge _WIN32_IE_WIN10)
      externdef __MIDL_itf_urlmon_0000_0042_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0042_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IZoneIdentifier2_INTERFACE_DEFINED__
        __IZoneIdentifier2_INTERFACE_DEFINED__ equ <>
        externdef IID_IZoneIdentifier2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          TYPE_IZoneIdentifier2Vtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IZoneIdentifier2, :REFIID, :ptr ptr
          PIZoneIdentifier2Vtbl_QueryInterface typedef ptr TYPE_IZoneIdentifier2Vtbl_QueryInterface
          TYPE_IZoneIdentifier2Vtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IZoneIdentifier2
          PIZoneIdentifier2Vtbl_AddRef typedef ptr TYPE_IZoneIdentifier2Vtbl_AddRef
          TYPE_IZoneIdentifier2Vtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IZoneIdentifier2
          PIZoneIdentifier2Vtbl_Release typedef ptr TYPE_IZoneIdentifier2Vtbl_Release
          TYPE_IZoneIdentifier2Vtbl_GetId typedef proto WIN_STD_CALL_CONV :ptr IZoneIdentifier2, :ptr DWORD
          PIZoneIdentifier2Vtbl_GetId typedef ptr TYPE_IZoneIdentifier2Vtbl_GetId
          TYPE_IZoneIdentifier2Vtbl_SetId typedef proto WIN_STD_CALL_CONV :ptr IZoneIdentifier2, :DWORD
          PIZoneIdentifier2Vtbl_SetId typedef ptr TYPE_IZoneIdentifier2Vtbl_SetId
          TYPE_IZoneIdentifier2Vtbl_Remove typedef proto WIN_STD_CALL_CONV :ptr IZoneIdentifier2
          PIZoneIdentifier2Vtbl_Remove typedef ptr TYPE_IZoneIdentifier2Vtbl_Remove
          TYPE_IZoneIdentifier2Vtbl_GetLastWriterPackageFamilyName typedef proto WIN_STD_CALL_CONV :ptr IZoneIdentifier2, :ptr LPWSTR
          PIZoneIdentifier2Vtbl_GetLastWriterPackageFamilyName typedef ptr TYPE_IZoneIdentifier2Vtbl_GetLastWriterPackageFamilyName
          TYPE_IZoneIdentifier2Vtbl_SetLastWriterPackageFamilyName typedef proto WIN_STD_CALL_CONV :ptr IZoneIdentifier2, :LPCWSTR
          PIZoneIdentifier2Vtbl_SetLastWriterPackageFamilyName typedef ptr TYPE_IZoneIdentifier2Vtbl_SetLastWriterPackageFamilyName
          TYPE_IZoneIdentifier2Vtbl_RemoveLastWriterPackageFamilyName typedef proto WIN_STD_CALL_CONV :ptr IZoneIdentifier2
          PIZoneIdentifier2Vtbl_RemoveLastWriterPackageFamilyName typedef ptr TYPE_IZoneIdentifier2Vtbl_RemoveLastWriterPackageFamilyName
          TYPE_IZoneIdentifier2Vtbl_GetAppZoneId typedef proto WIN_STD_CALL_CONV :ptr IZoneIdentifier2, :ptr DWORD
          PIZoneIdentifier2Vtbl_GetAppZoneId typedef ptr TYPE_IZoneIdentifier2Vtbl_GetAppZoneId
          TYPE_IZoneIdentifier2Vtbl_SetAppZoneId typedef proto WIN_STD_CALL_CONV :ptr IZoneIdentifier2, :DWORD
          PIZoneIdentifier2Vtbl_SetAppZoneId typedef ptr TYPE_IZoneIdentifier2Vtbl_SetAppZoneId
          TYPE_IZoneIdentifier2Vtbl_RemoveAppZoneId typedef proto WIN_STD_CALL_CONV :ptr IZoneIdentifier2
          PIZoneIdentifier2Vtbl_RemoveAppZoneId typedef ptr TYPE_IZoneIdentifier2Vtbl_RemoveAppZoneId
          IZoneIdentifier2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IZoneIdentifier2>
            QueryInterface PIZoneIdentifier2Vtbl_QueryInterface ?
            AddRef PIZoneIdentifier2Vtbl_AddRef ?
            Release PIZoneIdentifier2Vtbl_Release ?
            GetId PIZoneIdentifier2Vtbl_GetId ?
            SetId PIZoneIdentifier2Vtbl_SetId ?
            Remove PIZoneIdentifier2Vtbl_Remove ?
            GetLastWriterPackageFamilyName PIZoneIdentifier2Vtbl_GetLastWriterPackageFamilyName ?
            SetLastWriterPackageFamilyName PIZoneIdentifier2Vtbl_SetLastWriterPackageFamilyName ?
            RemoveLastWriterPackageFamilyName PIZoneIdentifier2Vtbl_RemoveLastWriterPackageFamilyName ?
            GetAppZoneId PIZoneIdentifier2Vtbl_GetAppZoneId ?
            SetAppZoneId PIZoneIdentifier2Vtbl_SetAppZoneId ?
            RemoveAppZoneId PIZoneIdentifier2Vtbl_RemoveAppZoneId ?
            ??Interface equ <>
            END_INTERFACE
          IZoneIdentifier2Vtbl ends
          IZoneIdentifier2 struct
            lpVtbl POINTER ?
          IZoneIdentifier2 ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    ifndef _LPINTERNETHOSTSECURITYMANANGER_DEFINED
      _LPINTERNETHOSTSECURITYMANANGER_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0043_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0043_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IInternetHostSecurityManager_INTERFACE_DEFINED__
        __IInternetHostSecurityManager_INTERFACE_DEFINED__ equ <>
        externdef IID_IInternetHostSecurityManager:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          TYPE_IInternetHostSecurityManagerVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IInternetHostSecurityManager, :REFIID, :ptr ptr
          PIInternetHostSecurityManagerVtbl_QueryInterface typedef ptr TYPE_IInternetHostSecurityManagerVtbl_QueryInterface
          TYPE_IInternetHostSecurityManagerVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IInternetHostSecurityManager
          PIInternetHostSecurityManagerVtbl_AddRef typedef ptr TYPE_IInternetHostSecurityManagerVtbl_AddRef
          TYPE_IInternetHostSecurityManagerVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IInternetHostSecurityManager
          PIInternetHostSecurityManagerVtbl_Release typedef ptr TYPE_IInternetHostSecurityManagerVtbl_Release
          TYPE_IInternetHostSecurityManagerVtbl_GetSecurityId typedef proto WIN_STD_CALL_CONV :ptr IInternetHostSecurityManager, :ptr BYTE, :ptr DWORD, :DWORD_PTR
          PIInternetHostSecurityManagerVtbl_GetSecurityId typedef ptr TYPE_IInternetHostSecurityManagerVtbl_GetSecurityId
          TYPE_IInternetHostSecurityManagerVtbl_rocessUrlAction typedef proto WIN_STD_CALL_CONV :ptr IInternetHostSecurityManager, :DWORD, :ptr BYTE, :DWORD, :ptr BYTE, :DWORD, :DWORD, :DWORD
          PIInternetHostSecurityManagerVtbl_rocessUrlAction typedef ptr TYPE_IInternetHostSecurityManagerVtbl_rocessUrlAction
          TYPE_IInternetHostSecurityManagerVtbl_QueryCustomPolicy typedef proto WIN_STD_CALL_CONV :ptr IInternetHostSecurityManager, :REFGUID, :ptr ptr BYTE, :ptr DWORD, :ptr BYTE, :DWORD, :DWORD
          PIInternetHostSecurityManagerVtbl_QueryCustomPolicy typedef ptr TYPE_IInternetHostSecurityManagerVtbl_QueryCustomPolicy
          IInternetHostSecurityManagerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IInternetHostSecurityManager>
            QueryInterface PIInternetHostSecurityManagerVtbl_QueryInterface ?
            AddRef PIInternetHostSecurityManagerVtbl_AddRef ?
            Release PIInternetHostSecurityManagerVtbl_Release ?
            GetSecurityId PIInternetHostSecurityManagerVtbl_GetSecurityId ?
            rocessUrlAction PIInternetHostSecurityManagerVtbl_rocessUrlAction ?
            QueryCustomPolicy PIInternetHostSecurityManagerVtbl_QueryCustomPolicy ?
            ??Interface equ <>
            END_INTERFACE
          IInternetHostSecurityManagerVtbl ends
          IInternetHostSecurityManager struct
            lpVtbl POINTER ?
          IInternetHostSecurityManager ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    URLACTION_MIN equ 00001000h
    URLACTION_DOWNLOAD_MIN equ 00001000h
    URLACTION_DOWNLOAD_SIGNED_ACTIVEX equ 00001001h
    URLACTION_DOWNLOAD_UNSIGNED_ACTIVEX equ 00001004h
    URLACTION_DOWNLOAD_CURR_MAX equ 00001004h
    URLACTION_DOWNLOAD_MAX equ 000011FFh
    URLACTION_ACTIVEX_MIN equ 00001200h
    URLACTION_ACTIVEX_RUN equ 00001200h
    URLPOLICY_ACTIVEX_CHECK_LIST equ 00010000h
    URLACTION_ACTIVEX_OVERRIDE_OBJECT_SAFETY equ 00001201h
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
    URLACTION_SCRIPT_CURR_MAX equ 0000140Ch
    URLACTION_SCRIPT_MAX equ 000015ffh
    URLACTION_HTML_MIN equ 00001600h
    URLACTION_HTML_SUBMIT_FORMS equ 00001601h
    URLACTION_HTML_SUBMIT_FORMS_FROM equ 00001602h
    URLACTION_HTML_SUBMIT_FORMS_TO equ 00001603h
    URLACTION_HTML_FONT_DOWNLOAD equ 00001604h
    URLACTION_HTML_JAVA_RUN equ 00001605h
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
    if (_WIN32_IE ge _WIN32_IE_WIN7)
      URLACTION_SHELL_REMOTEQUERY equ 0000180Eh
      URLACTION_SHELL_PREVIEW equ 0000180Fh
      URLACTION_SHELL_SHARE equ 00001810h
      URLACTION_SHELL_ALLOW_CROSS_SITE_SHARE equ 00001811h
    endif
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
    if (_WIN32_IE ge _WIN32_IE_IE60SP2)
      URLACTION_BEHAVIOR_MIN equ 00002000h
      URLACTION_BEHAVIOR_RUN equ 00002000h
      URLPOLICY_BEHAVIOR_CHECK_LIST equ 00010000h
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
    if (_WIN32_IE ge _WIN32_IE_IE70)
      URLACTION_ALLOW_APEVALUATION equ 00002301h
      URLACTION_ALLOW_XHR_EVALUATION equ 00002302h
      URLACTION_WINDOWS_BROWSER_APPLICATIONS equ 00002400h
      URLACTION_XPS_DOCUMENTS equ 00002401h
      URLACTION_LOOSE_XAML equ 00002402h
      URLACTION_LOWRIGHTS equ 00002500h
      URLACTION_WINFX_SETUP equ 00002600h
      URLACTION_INPRIVATE_BLOCKING equ 00002700h
    endif
    URLACTION_ALLOW_AUDIO_VIDEO equ 00002701h
    URLACTION_ALLOW_ACTIVEX_FILTERING equ 00002702h
    URLACTION_ALLOW_STRUCTURED_STORAGE_SNIFFING equ 00002703h
    URLACTION_ALLOW_AUDIO_VIDEO_PLUGINS equ 00002704h
    URLACTION_ALLOW_ZONE_ELEVATION_VIA_OPT_OUT equ 00002705h
    URLACTION_ALLOW_ZONE_ELEVATION_OPT_OUT_ADDITION equ 00002706h
    URLACTION_ALLOW_CROSSDOMAIN_DROP_WITHIN_WINDOW equ 00002708h
    URLACTION_ALLOW_CROSSDOMAIN_DROP_ACROSS_WINDOWS equ 00002709h
    URLACTION_ALLOW_CROSSDOMAIN_APPCACHE_MANIFEST equ 0000270Ah
    URLACTION_ALLOW_RENDER_LEGACY_DXTFILTERS equ 0000270Bh
    URLACTION_ALLOW_ANTIMALWARE_SCANNING_OF_ACTIVEX equ 0000270Ch
    URLACTION_ALLOW_CSS_EXPRESSIONS equ 0000270Dh
    URLPOLICY_ALLOW equ 00h
    URLPOLICY_QUERY equ 01h
    URLPOLICY_DISALLOW equ 03h
    URLPOLICY_NOTIFY_ON_ALLOW equ 10h
    URLPOLICY_NOTIFY_ON_DISALLOW equ 20h
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
    if (_WIN32_IE ge _WIN32_IE_IE60SP2)
      externdef GUID_CUSTOM_LOCALMACHINEZONEUNLOCKED:GUID
    endif
    ifndef _LPINTERNETZONEMANAGER_DEFINED
      _LPINTERNETZONEMANAGER_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0044_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0044_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IInternetZoneManager_INTERFACE_DEFINED__
        __IInternetZoneManager_INTERFACE_DEFINED__ equ <>
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
          cbSize ULONG ?
          szDisplayName WCHAR 260 dup (?)
          szDescription WCHAR 200 dup (?)
          szIconPath WCHAR 260 dup (?)
          dwTemplateMinLevel DWORD ?
          dwTemplateRecommended DWORD ?
          dwTemplateCurrentLevel DWORD ?
          dwFlags DWORD ?
        ZONEATTRIBUTES ends
        _ZONEATTRIBUTES typedef ZONEATTRIBUTES
        LPZONEATTRIBUTES typedef ptr _ZONEATTRIBUTES
        URLZONEREG typedef SDWORD
        URLZONEREG_DEFAULT equ 0
        URLZONEREG_HKLM equ
        URLZONEREG_HKCU equ
        _URLZONEREG typedef URLZONEREG
        externdef IID_IInternetZoneManager:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          TYPE_IInternetZoneManagerVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManager, :REFIID, :ptr ptr
          PIInternetZoneManagerVtbl_QueryInterface typedef ptr TYPE_IInternetZoneManagerVtbl_QueryInterface
          TYPE_IInternetZoneManagerVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManager
          PIInternetZoneManagerVtbl_AddRef typedef ptr TYPE_IInternetZoneManagerVtbl_AddRef
          TYPE_IInternetZoneManagerVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManager
          PIInternetZoneManagerVtbl_Release typedef ptr TYPE_IInternetZoneManagerVtbl_Release
          TYPE_IInternetZoneManagerVtbl_GetZoneAttributes typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManager, :DWORD, :ptr ZONEATTRIBUTES
          PIInternetZoneManagerVtbl_GetZoneAttributes typedef ptr TYPE_IInternetZoneManagerVtbl_GetZoneAttributes
          TYPE_IInternetZoneManagerVtbl_SetZoneAttributes typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManager, :DWORD, :ptr ZONEATTRIBUTES
          PIInternetZoneManagerVtbl_SetZoneAttributes typedef ptr TYPE_IInternetZoneManagerVtbl_SetZoneAttributes
          TYPE_IInternetZoneManagerVtbl_GetZoneCustomPolicy typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManager, :DWORD, :REFGUID, :ptr ptr BYTE, :ptr DWORD, :URLZONEREG
          PIInternetZoneManagerVtbl_GetZoneCustomPolicy typedef ptr TYPE_IInternetZoneManagerVtbl_GetZoneCustomPolicy
          TYPE_IInternetZoneManagerVtbl_SetZoneCustomPolicy typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManager, :DWORD, :REFGUID, :ptr BYTE, :DWORD, :URLZONEREG
          PIInternetZoneManagerVtbl_SetZoneCustomPolicy typedef ptr TYPE_IInternetZoneManagerVtbl_SetZoneCustomPolicy
          TYPE_IInternetZoneManagerVtbl_GetZoneActionPolicy typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManager, :DWORD, :DWORD, :ptr BYTE, :DWORD, :URLZONEREG
          PIInternetZoneManagerVtbl_GetZoneActionPolicy typedef ptr TYPE_IInternetZoneManagerVtbl_GetZoneActionPolicy
          TYPE_IInternetZoneManagerVtbl_SetZoneActionPolicy typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManager, :DWORD, :DWORD, :ptr BYTE, :DWORD, :URLZONEREG
          PIInternetZoneManagerVtbl_SetZoneActionPolicy typedef ptr TYPE_IInternetZoneManagerVtbl_SetZoneActionPolicy
          TYPE_IInternetZoneManagerVtbl_romptAction typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManager, :DWORD, :HWND, :LPCWSTR, :LPCWSTR, :DWORD
          PIInternetZoneManagerVtbl_romptAction typedef ptr TYPE_IInternetZoneManagerVtbl_romptAction
          TYPE_IInternetZoneManagerVtbl_LogAction typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManager, :DWORD, :LPCWSTR, :LPCWSTR, :DWORD
          PIInternetZoneManagerVtbl_LogAction typedef ptr TYPE_IInternetZoneManagerVtbl_LogAction
          TYPE_IInternetZoneManagerVtbl_CreateZoneEnumerator typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManager, :ptr DWORD, :ptr DWORD, :DWORD
          PIInternetZoneManagerVtbl_CreateZoneEnumerator typedef ptr TYPE_IInternetZoneManagerVtbl_CreateZoneEnumerator
          TYPE_IInternetZoneManagerVtbl_GetZoneAt typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManager, :DWORD, :DWORD, :ptr DWORD
          PIInternetZoneManagerVtbl_GetZoneAt typedef ptr TYPE_IInternetZoneManagerVtbl_GetZoneAt
          TYPE_IInternetZoneManagerVtbl_DestroyZoneEnumerator typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManager, :DWORD
          PIInternetZoneManagerVtbl_DestroyZoneEnumerator typedef ptr TYPE_IInternetZoneManagerVtbl_DestroyZoneEnumerator
          TYPE_IInternetZoneManagerVtbl_CopyTemplatePoliciesToZone typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManager, :DWORD, :DWORD, :DWORD
          PIInternetZoneManagerVtbl_CopyTemplatePoliciesToZone typedef ptr TYPE_IInternetZoneManagerVtbl_CopyTemplatePoliciesToZone
          IInternetZoneManagerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IInternetZoneManager>
            QueryInterface PIInternetZoneManagerVtbl_QueryInterface ?
            AddRef PIInternetZoneManagerVtbl_AddRef ?
            Release PIInternetZoneManagerVtbl_Release ?
            GetZoneAttributes PIInternetZoneManagerVtbl_GetZoneAttributes ?
            SetZoneAttributes PIInternetZoneManagerVtbl_SetZoneAttributes ?
            GetZoneCustomPolicy PIInternetZoneManagerVtbl_GetZoneCustomPolicy ?
            SetZoneCustomPolicy PIInternetZoneManagerVtbl_SetZoneCustomPolicy ?
            GetZoneActionPolicy PIInternetZoneManagerVtbl_GetZoneActionPolicy ?
            SetZoneActionPolicy PIInternetZoneManagerVtbl_SetZoneActionPolicy ?
            romptAction PIInternetZoneManagerVtbl_romptAction ?
            LogAction PIInternetZoneManagerVtbl_LogAction ?
            CreateZoneEnumerator PIInternetZoneManagerVtbl_CreateZoneEnumerator ?
            GetZoneAt PIInternetZoneManagerVtbl_GetZoneAt ?
            DestroyZoneEnumerator PIInternetZoneManagerVtbl_DestroyZoneEnumerator ?
            CopyTemplatePoliciesToZone PIInternetZoneManagerVtbl_CopyTemplatePoliciesToZone ?
            ??Interface equ <>
            END_INTERFACE
          IInternetZoneManagerVtbl ends
          IInternetZoneManager struct
            lpVtbl POINTER ?
          IInternetZoneManager ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    if (_WIN32_IE ge _WIN32_IE_IE60SP2)
      ifndef _LPINTERNETZONEMANAGEREX_DEFINED
        _LPINTERNETZONEMANAGEREX_DEFINED equ <>
        externdef __MIDL_itf_urlmon_0000_0045_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0045_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IInternetZoneManagerEx_INTERFACE_DEFINED__
          __IInternetZoneManagerEx_INTERFACE_DEFINED__ equ <>
          externdef IID_IInternetZoneManagerEx:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            TYPE_IInternetZoneManagerExVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx, :REFIID, :ptr ptr
            PIInternetZoneManagerExVtbl_QueryInterface typedef ptr TYPE_IInternetZoneManagerExVtbl_QueryInterface
            TYPE_IInternetZoneManagerExVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx
            PIInternetZoneManagerExVtbl_AddRef typedef ptr TYPE_IInternetZoneManagerExVtbl_AddRef
            TYPE_IInternetZoneManagerExVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx
            PIInternetZoneManagerExVtbl_Release typedef ptr TYPE_IInternetZoneManagerExVtbl_Release
            TYPE_IInternetZoneManagerExVtbl_GetZoneAttributes typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx, :DWORD, :ptr ZONEATTRIBUTES
            PIInternetZoneManagerExVtbl_GetZoneAttributes typedef ptr TYPE_IInternetZoneManagerExVtbl_GetZoneAttributes
            TYPE_IInternetZoneManagerExVtbl_SetZoneAttributes typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx, :DWORD, :ptr ZONEATTRIBUTES
            PIInternetZoneManagerExVtbl_SetZoneAttributes typedef ptr TYPE_IInternetZoneManagerExVtbl_SetZoneAttributes
            TYPE_IInternetZoneManagerExVtbl_GetZoneCustomPolicy typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx, :DWORD, :REFGUID, :ptr ptr BYTE, :ptr DWORD, :URLZONEREG
            PIInternetZoneManagerExVtbl_GetZoneCustomPolicy typedef ptr TYPE_IInternetZoneManagerExVtbl_GetZoneCustomPolicy
            TYPE_IInternetZoneManagerExVtbl_SetZoneCustomPolicy typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx, :DWORD, :REFGUID, :ptr BYTE, :DWORD, :URLZONEREG
            PIInternetZoneManagerExVtbl_SetZoneCustomPolicy typedef ptr TYPE_IInternetZoneManagerExVtbl_SetZoneCustomPolicy
            TYPE_IInternetZoneManagerExVtbl_GetZoneActionPolicy typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx, :DWORD, :DWORD, :ptr BYTE, :DWORD, :URLZONEREG
            PIInternetZoneManagerExVtbl_GetZoneActionPolicy typedef ptr TYPE_IInternetZoneManagerExVtbl_GetZoneActionPolicy
            TYPE_IInternetZoneManagerExVtbl_SetZoneActionPolicy typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx, :DWORD, :DWORD, :ptr BYTE, :DWORD, :URLZONEREG
            PIInternetZoneManagerExVtbl_SetZoneActionPolicy typedef ptr TYPE_IInternetZoneManagerExVtbl_SetZoneActionPolicy
            TYPE_IInternetZoneManagerExVtbl_romptAction typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx, :DWORD, :HWND, :LPCWSTR, :LPCWSTR, :DWORD
            PIInternetZoneManagerExVtbl_romptAction typedef ptr TYPE_IInternetZoneManagerExVtbl_romptAction
            TYPE_IInternetZoneManagerExVtbl_LogAction typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx, :DWORD, :LPCWSTR, :LPCWSTR, :DWORD
            PIInternetZoneManagerExVtbl_LogAction typedef ptr TYPE_IInternetZoneManagerExVtbl_LogAction
            TYPE_IInternetZoneManagerExVtbl_CreateZoneEnumerator typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx, :ptr DWORD, :ptr DWORD, :DWORD
            PIInternetZoneManagerExVtbl_CreateZoneEnumerator typedef ptr TYPE_IInternetZoneManagerExVtbl_CreateZoneEnumerator
            TYPE_IInternetZoneManagerExVtbl_GetZoneAt typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx, :DWORD, :DWORD, :ptr DWORD
            PIInternetZoneManagerExVtbl_GetZoneAt typedef ptr TYPE_IInternetZoneManagerExVtbl_GetZoneAt
            TYPE_IInternetZoneManagerExVtbl_DestroyZoneEnumerator typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx, :DWORD
            PIInternetZoneManagerExVtbl_DestroyZoneEnumerator typedef ptr TYPE_IInternetZoneManagerExVtbl_DestroyZoneEnumerator
            TYPE_IInternetZoneManagerExVtbl_CopyTemplatePoliciesToZone typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx, :DWORD, :DWORD, :DWORD
            PIInternetZoneManagerExVtbl_CopyTemplatePoliciesToZone typedef ptr TYPE_IInternetZoneManagerExVtbl_CopyTemplatePoliciesToZone
            TYPE_IInternetZoneManagerExVtbl_GetZoneActionPolicyEx typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx, :DWORD, :DWORD, :ptr BYTE, :DWORD, :URLZONEREG, :DWORD
            PIInternetZoneManagerExVtbl_GetZoneActionPolicyEx typedef ptr TYPE_IInternetZoneManagerExVtbl_GetZoneActionPolicyEx
            TYPE_IInternetZoneManagerExVtbl_SetZoneActionPolicyEx typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx, :DWORD, :DWORD, :ptr BYTE, :DWORD, :URLZONEREG, :DWORD
            PIInternetZoneManagerExVtbl_SetZoneActionPolicyEx typedef ptr TYPE_IInternetZoneManagerExVtbl_SetZoneActionPolicyEx
            IInternetZoneManagerExVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetZoneManagerEx>
              QueryInterface PIInternetZoneManagerExVtbl_QueryInterface ?
              AddRef PIInternetZoneManagerExVtbl_AddRef ?
              Release PIInternetZoneManagerExVtbl_Release ?
              GetZoneAttributes PIInternetZoneManagerExVtbl_GetZoneAttributes ?
              SetZoneAttributes PIInternetZoneManagerExVtbl_SetZoneAttributes ?
              GetZoneCustomPolicy PIInternetZoneManagerExVtbl_GetZoneCustomPolicy ?
              SetZoneCustomPolicy PIInternetZoneManagerExVtbl_SetZoneCustomPolicy ?
              GetZoneActionPolicy PIInternetZoneManagerExVtbl_GetZoneActionPolicy ?
              SetZoneActionPolicy PIInternetZoneManagerExVtbl_SetZoneActionPolicy ?
              romptAction PIInternetZoneManagerExVtbl_romptAction ?
              LogAction PIInternetZoneManagerExVtbl_LogAction ?
              CreateZoneEnumerator PIInternetZoneManagerExVtbl_CreateZoneEnumerator ?
              GetZoneAt PIInternetZoneManagerExVtbl_GetZoneAt ?
              DestroyZoneEnumerator PIInternetZoneManagerExVtbl_DestroyZoneEnumerator ?
              CopyTemplatePoliciesToZone PIInternetZoneManagerExVtbl_CopyTemplatePoliciesToZone ?
              GetZoneActionPolicyEx PIInternetZoneManagerExVtbl_GetZoneActionPolicyEx ?
              SetZoneActionPolicyEx PIInternetZoneManagerExVtbl_SetZoneActionPolicyEx ?
              ??Interface equ <>
              END_INTERFACE
            IInternetZoneManagerExVtbl ends
            IInternetZoneManagerEx struct
              lpVtbl POINTER ?
            IInternetZoneManagerEx ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
      endif
    endif
    if (_WIN32_IE ge _WIN32_IE_IE70)
      ifndef _LPINTERNETZONEMANAGEREX2_DEFINED
        _LPINTERNETZONEMANAGEREX2_DEFINED equ <>
        SECURITY_IE_STATE_GREEN equ 00000000h
        SECURITY_IE_STATE_RED equ 00000001h
        externdef __MIDL_itf_urlmon_0000_0046_v0_0_c_ifspec:RPC_IF_HANDLE
        externdef __MIDL_itf_urlmon_0000_0046_v0_0_s_ifspec:RPC_IF_HANDLE
        ifndef __IInternetZoneManagerEx2_INTERFACE_DEFINED__
          __IInternetZoneManagerEx2_INTERFACE_DEFINED__ equ <>
          externdef IID_IInternetZoneManagerEx2:IID
          if Defined(__cplusplus) and  not Defined(CINTERFACE)
            ;[...]
          else
            TYPE_IInternetZoneManagerEx2Vtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx2, :REFIID, :ptr ptr
            PIInternetZoneManagerEx2Vtbl_QueryInterface typedef ptr TYPE_IInternetZoneManagerEx2Vtbl_QueryInterface
            TYPE_IInternetZoneManagerEx2Vtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx2
            PIInternetZoneManagerEx2Vtbl_AddRef typedef ptr TYPE_IInternetZoneManagerEx2Vtbl_AddRef
            TYPE_IInternetZoneManagerEx2Vtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx2
            PIInternetZoneManagerEx2Vtbl_Release typedef ptr TYPE_IInternetZoneManagerEx2Vtbl_Release
            TYPE_IInternetZoneManagerEx2Vtbl_GetZoneAttributes typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx2, :DWORD, :ptr ZONEATTRIBUTES
            PIInternetZoneManagerEx2Vtbl_GetZoneAttributes typedef ptr TYPE_IInternetZoneManagerEx2Vtbl_GetZoneAttributes
            TYPE_IInternetZoneManagerEx2Vtbl_SetZoneAttributes typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx2, :DWORD, :ptr ZONEATTRIBUTES
            PIInternetZoneManagerEx2Vtbl_SetZoneAttributes typedef ptr TYPE_IInternetZoneManagerEx2Vtbl_SetZoneAttributes
            TYPE_IInternetZoneManagerEx2Vtbl_GetZoneCustomPolicy typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx2, :DWORD, :REFGUID, :ptr ptr BYTE, :ptr DWORD, :URLZONEREG
            PIInternetZoneManagerEx2Vtbl_GetZoneCustomPolicy typedef ptr TYPE_IInternetZoneManagerEx2Vtbl_GetZoneCustomPolicy
            TYPE_IInternetZoneManagerEx2Vtbl_SetZoneCustomPolicy typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx2, :DWORD, :REFGUID, :ptr BYTE, :DWORD, :URLZONEREG
            PIInternetZoneManagerEx2Vtbl_SetZoneCustomPolicy typedef ptr TYPE_IInternetZoneManagerEx2Vtbl_SetZoneCustomPolicy
            TYPE_IInternetZoneManagerEx2Vtbl_GetZoneActionPolicy typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx2, :DWORD, :DWORD, :ptr BYTE, :DWORD, :URLZONEREG
            PIInternetZoneManagerEx2Vtbl_GetZoneActionPolicy typedef ptr TYPE_IInternetZoneManagerEx2Vtbl_GetZoneActionPolicy
            TYPE_IInternetZoneManagerEx2Vtbl_SetZoneActionPolicy typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx2, :DWORD, :DWORD, :ptr BYTE, :DWORD, :URLZONEREG
            PIInternetZoneManagerEx2Vtbl_SetZoneActionPolicy typedef ptr TYPE_IInternetZoneManagerEx2Vtbl_SetZoneActionPolicy
            TYPE_IInternetZoneManagerEx2Vtbl_romptAction typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx2, :DWORD, :HWND, :LPCWSTR, :LPCWSTR, :DWORD
            PIInternetZoneManagerEx2Vtbl_romptAction typedef ptr TYPE_IInternetZoneManagerEx2Vtbl_romptAction
            TYPE_IInternetZoneManagerEx2Vtbl_LogAction typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx2, :DWORD, :LPCWSTR, :LPCWSTR, :DWORD
            PIInternetZoneManagerEx2Vtbl_LogAction typedef ptr TYPE_IInternetZoneManagerEx2Vtbl_LogAction
            TYPE_IInternetZoneManagerEx2Vtbl_CreateZoneEnumerator typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx2, :ptr DWORD, :ptr DWORD, :DWORD
            PIInternetZoneManagerEx2Vtbl_CreateZoneEnumerator typedef ptr TYPE_IInternetZoneManagerEx2Vtbl_CreateZoneEnumerator
            TYPE_IInternetZoneManagerEx2Vtbl_GetZoneAt typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx2, :DWORD, :DWORD, :ptr DWORD
            PIInternetZoneManagerEx2Vtbl_GetZoneAt typedef ptr TYPE_IInternetZoneManagerEx2Vtbl_GetZoneAt
            TYPE_IInternetZoneManagerEx2Vtbl_DestroyZoneEnumerator typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx2, :DWORD
            PIInternetZoneManagerEx2Vtbl_DestroyZoneEnumerator typedef ptr TYPE_IInternetZoneManagerEx2Vtbl_DestroyZoneEnumerator
            TYPE_IInternetZoneManagerEx2Vtbl_CopyTemplatePoliciesToZone typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx2, :DWORD, :DWORD, :DWORD
            PIInternetZoneManagerEx2Vtbl_CopyTemplatePoliciesToZone typedef ptr TYPE_IInternetZoneManagerEx2Vtbl_CopyTemplatePoliciesToZone
            TYPE_IInternetZoneManagerEx2Vtbl_GetZoneActionPolicyEx typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx2, :DWORD, :DWORD, :ptr BYTE, :DWORD, :URLZONEREG, :DWORD
            PIInternetZoneManagerEx2Vtbl_GetZoneActionPolicyEx typedef ptr TYPE_IInternetZoneManagerEx2Vtbl_GetZoneActionPolicyEx
            TYPE_IInternetZoneManagerEx2Vtbl_SetZoneActionPolicyEx typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx2, :DWORD, :DWORD, :ptr BYTE, :DWORD, :URLZONEREG, :DWORD
            PIInternetZoneManagerEx2Vtbl_SetZoneActionPolicyEx typedef ptr TYPE_IInternetZoneManagerEx2Vtbl_SetZoneActionPolicyEx
            TYPE_IInternetZoneManagerEx2Vtbl_GetZoneAttributesEx typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx2, :DWORD, :ptr ZONEATTRIBUTES, :DWORD
            PIInternetZoneManagerEx2Vtbl_GetZoneAttributesEx typedef ptr TYPE_IInternetZoneManagerEx2Vtbl_GetZoneAttributesEx
            TYPE_IInternetZoneManagerEx2Vtbl_GetZoneSecurityState typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx2, :DWORD, :BOOL, :LPDWORD, :ptr BOOL
            PIInternetZoneManagerEx2Vtbl_GetZoneSecurityState typedef ptr TYPE_IInternetZoneManagerEx2Vtbl_GetZoneSecurityState
            TYPE_IInternetZoneManagerEx2Vtbl_GetIESecurityState typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx2, :BOOL, :LPDWORD, :ptr BOOL, :BOOL
            PIInternetZoneManagerEx2Vtbl_GetIESecurityState typedef ptr TYPE_IInternetZoneManagerEx2Vtbl_GetIESecurityState
            TYPE_IInternetZoneManagerEx2Vtbl_FixUnsecureSettings typedef proto WIN_STD_CALL_CONV :ptr IInternetZoneManagerEx2
            PIInternetZoneManagerEx2Vtbl_FixUnsecureSettings typedef ptr TYPE_IInternetZoneManagerEx2Vtbl_FixUnsecureSettings
            IInternetZoneManagerEx2Vtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetZoneManagerEx2>
              QueryInterface PIInternetZoneManagerEx2Vtbl_QueryInterface ?
              AddRef PIInternetZoneManagerEx2Vtbl_AddRef ?
              Release PIInternetZoneManagerEx2Vtbl_Release ?
              GetZoneAttributes PIInternetZoneManagerEx2Vtbl_GetZoneAttributes ?
              SetZoneAttributes PIInternetZoneManagerEx2Vtbl_SetZoneAttributes ?
              GetZoneCustomPolicy PIInternetZoneManagerEx2Vtbl_GetZoneCustomPolicy ?
              SetZoneCustomPolicy PIInternetZoneManagerEx2Vtbl_SetZoneCustomPolicy ?
              GetZoneActionPolicy PIInternetZoneManagerEx2Vtbl_GetZoneActionPolicy ?
              SetZoneActionPolicy PIInternetZoneManagerEx2Vtbl_SetZoneActionPolicy ?
              romptAction PIInternetZoneManagerEx2Vtbl_romptAction ?
              LogAction PIInternetZoneManagerEx2Vtbl_LogAction ?
              CreateZoneEnumerator PIInternetZoneManagerEx2Vtbl_CreateZoneEnumerator ?
              GetZoneAt PIInternetZoneManagerEx2Vtbl_GetZoneAt ?
              DestroyZoneEnumerator PIInternetZoneManagerEx2Vtbl_DestroyZoneEnumerator ?
              CopyTemplatePoliciesToZone PIInternetZoneManagerEx2Vtbl_CopyTemplatePoliciesToZone ?
              GetZoneActionPolicyEx PIInternetZoneManagerEx2Vtbl_GetZoneActionPolicyEx ?
              SetZoneActionPolicyEx PIInternetZoneManagerEx2Vtbl_SetZoneActionPolicyEx ?
              GetZoneAttributesEx PIInternetZoneManagerEx2Vtbl_GetZoneAttributesEx ?
              GetZoneSecurityState PIInternetZoneManagerEx2Vtbl_GetZoneSecurityState ?
              GetIESecurityState PIInternetZoneManagerEx2Vtbl_GetIESecurityState ?
              FixUnsecureSettings PIInternetZoneManagerEx2Vtbl_FixUnsecureSettings ?
              ??Interface equ <>
              END_INTERFACE
            IInternetZoneManagerEx2Vtbl ends
            IInternetZoneManagerEx2 struct
              lpVtbl POINTER ?
            IInternetZoneManagerEx2 ends
            ifdef COBJMACROS
              ;[...]
            endif
          endif
        endif
      endif
    endif
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
        cbSize ULONG ?
        szDistUnit LPWSTR ?
        szCodeBase LPWSTR ?
        dwVersionMS DWORD ?
        dwVersionLS DWORD ?
        dwStyle DWORD ?
      CODEBASEHOLD ends
      _tagCODEBASEHOLD typedef CODEBASEHOLD
      LPCODEBASEHOLD typedef ptr _tagCODEBASEHOLD
      SOFTDISTINFO struct
        cbSize ULONG ?
        dwFlags DWORD ?
        dwAdState DWORD ?
        szTitle LPWSTR ?
        szAbstract LPWSTR ?
        szHREF LPWSTR ?
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
        externdef IID_ISoftDistExt:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          TYPE_ISoftDistExtVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr ISoftDistExt, :REFIID, :ptr ptr
          PISoftDistExtVtbl_QueryInterface typedef ptr TYPE_ISoftDistExtVtbl_QueryInterface
          TYPE_ISoftDistExtVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr ISoftDistExt
          PISoftDistExtVtbl_AddRef typedef ptr TYPE_ISoftDistExtVtbl_AddRef
          TYPE_ISoftDistExtVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr ISoftDistExt
          PISoftDistExtVtbl_Release typedef ptr TYPE_ISoftDistExtVtbl_Release
          TYPE_ISoftDistExtVtbl_rocessSoftDist typedef proto WIN_STD_CALL_CONV :ptr ISoftDistExt, :LPCWSTR, :ptr IXMLElement, :LPSOFTDISTINFO
          PISoftDistExtVtbl_rocessSoftDist typedef ptr TYPE_ISoftDistExtVtbl_rocessSoftDist
          TYPE_ISoftDistExtVtbl_GetFirstCodeBase typedef proto WIN_STD_CALL_CONV :ptr ISoftDistExt, :ptr LPWSTR, :LPDWORD
          PISoftDistExtVtbl_GetFirstCodeBase typedef ptr TYPE_ISoftDistExtVtbl_GetFirstCodeBase
          TYPE_ISoftDistExtVtbl_GetNextCodeBase typedef proto WIN_STD_CALL_CONV :ptr ISoftDistExt, :ptr LPWSTR, :LPDWORD
          PISoftDistExtVtbl_GetNextCodeBase typedef ptr TYPE_ISoftDistExtVtbl_GetNextCodeBase
          TYPE_ISoftDistExtVtbl_AsyncInstallDistributionUnit typedef proto WIN_STD_CALL_CONV :ptr ISoftDistExt, :ptr IBindCtx, :LPVOID, :DWORD, :LPCODEBASEHOLD
          PISoftDistExtVtbl_AsyncInstallDistributionUnit typedef ptr TYPE_ISoftDistExtVtbl_AsyncInstallDistributionUnit
          ISoftDistExtVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISoftDistExt>
            QueryInterface PISoftDistExtVtbl_QueryInterface ?
            AddRef PISoftDistExtVtbl_AddRef ?
            Release PISoftDistExtVtbl_Release ?
            rocessSoftDist PISoftDistExtVtbl_rocessSoftDist ?
            GetFirstCodeBase PISoftDistExtVtbl_GetFirstCodeBase ?
            GetNextCodeBase PISoftDistExtVtbl_GetNextCodeBase ?
            AsyncInstallDistributionUnit_ PISoftDistExtVtbl_AsyncInstallDistributionUnit ?
            ??Interface equ <>
            END_INTERFACE
          ISoftDistExtVtbl ends
          ISoftDistExt struct
            lpVtbl POINTER ?
          ISoftDistExt ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      @DefProto DllImport, GetSoftwareUpdateInfo, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPSOFTDISTINFO>, 8
      @DefProto DllImport, SetSoftwareUpdateAdvertisementState, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :DWORD, :DWORD>, 16
    endif
    ifndef _LPCATALOGFILEINFO_DEFINED
      _LPCATALOGFILEINFO_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0048_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0048_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ICatalogFileInfo_INTERFACE_DEFINED__
        __ICatalogFileInfo_INTERFACE_DEFINED__ equ <>
        LPCATALOGFILEINFO typedef ptr ICatalogFileInfo
        externdef IID_ICatalogFileInfo:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          TYPE_ICatalogFileInfoVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr ICatalogFileInfo, :REFIID, :ptr ptr
          PICatalogFileInfoVtbl_QueryInterface typedef ptr TYPE_ICatalogFileInfoVtbl_QueryInterface
          TYPE_ICatalogFileInfoVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr ICatalogFileInfo
          PICatalogFileInfoVtbl_AddRef typedef ptr TYPE_ICatalogFileInfoVtbl_AddRef
          TYPE_ICatalogFileInfoVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr ICatalogFileInfo
          PICatalogFileInfoVtbl_Release typedef ptr TYPE_ICatalogFileInfoVtbl_Release
          TYPE_ICatalogFileInfoVtbl_GetCatalogFile typedef proto WIN_STD_CALL_CONV :ptr ICatalogFileInfo, :ptr LPSTR
          PICatalogFileInfoVtbl_GetCatalogFile typedef ptr TYPE_ICatalogFileInfoVtbl_GetCatalogFile
          TYPE_ICatalogFileInfoVtbl_GetJavaTrust typedef proto WIN_STD_CALL_CONV :ptr ICatalogFileInfo, :ptr ptr
          PICatalogFileInfoVtbl_GetJavaTrust typedef ptr TYPE_ICatalogFileInfoVtbl_GetJavaTrust
          ICatalogFileInfoVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ICatalogFileInfo>
            QueryInterface PICatalogFileInfoVtbl_QueryInterface ?
            AddRef PICatalogFileInfoVtbl_AddRef ?
            Release PICatalogFileInfoVtbl_Release ?
            GetCatalogFile PICatalogFileInfoVtbl_GetCatalogFile ?
            GetJavaTrust PICatalogFileInfoVtbl_GetJavaTrust ?
            ??Interface equ <>
            END_INTERFACE
          ICatalogFileInfoVtbl ends
          ICatalogFileInfo struct
            lpVtbl POINTER ?
          ICatalogFileInfo ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    ifndef _LPDATAFILTER_DEFINED
      _LPDATAFILTER_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0049_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0049_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDataFilter_INTERFACE_DEFINED__
        __IDataFilter_INTERFACE_DEFINED__ equ <>
        LPDATAFILTER typedef ptr IDataFilter
        externdef IID_IDataFilter:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          TYPE_IDataFilterVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IDataFilter, :REFIID, :ptr ptr
          PIDataFilterVtbl_QueryInterface typedef ptr TYPE_IDataFilterVtbl_QueryInterface
          TYPE_IDataFilterVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IDataFilter
          PIDataFilterVtbl_AddRef typedef ptr TYPE_IDataFilterVtbl_AddRef
          TYPE_IDataFilterVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IDataFilter
          PIDataFilterVtbl_Release typedef ptr TYPE_IDataFilterVtbl_Release
          TYPE_IDataFilterVtbl_DoEncode typedef proto WIN_STD_CALL_CONV :ptr IDataFilter, :DWORD, :LONG, :ptr BYTE, :LONG, :ptr BYTE, :LONG, :ptr LONG, :ptr LONG, :DWORD
          PIDataFilterVtbl_DoEncode typedef ptr TYPE_IDataFilterVtbl_DoEncode
          TYPE_IDataFilterVtbl_DoDecode typedef proto WIN_STD_CALL_CONV :ptr IDataFilter, :DWORD, :LONG, :ptr BYTE, :LONG, :ptr BYTE, :LONG, :ptr LONG, :ptr LONG, :DWORD
          PIDataFilterVtbl_DoDecode typedef ptr TYPE_IDataFilterVtbl_DoDecode
          TYPE_IDataFilterVtbl_SetEncodingLevel typedef proto WIN_STD_CALL_CONV :ptr IDataFilter, :DWORD
          PIDataFilterVtbl_SetEncodingLevel typedef ptr TYPE_IDataFilterVtbl_SetEncodingLevel
          IDataFilterVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDataFilter>
            QueryInterface PIDataFilterVtbl_QueryInterface ?
            AddRef PIDataFilterVtbl_AddRef ?
            Release PIDataFilterVtbl_Release ?
            DoEncode PIDataFilterVtbl_DoEncode ?
            DoDecode PIDataFilterVtbl_DoDecode ?
            SetEncodingLevel PIDataFilterVtbl_SetEncodingLevel ?
            ??Interface equ <>
            END_INTERFACE
          IDataFilterVtbl ends
          IDataFilter struct
            lpVtbl POINTER ?
          IDataFilter ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
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
        LPENCODINGFILTERFACTORY typedef ptr IEncodingFilterFactory
        DATAINFO struct
          ulTotalSize ULONG ?
          ulavrPacketSize ULONG ?
          ulConnectSpeed ULONG ?
          ulProcessorSpeed ULONG ?
        DATAINFO ends
        _tagDATAINFO typedef DATAINFO
        externdef IID_IEncodingFilterFactory:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          TYPE_IEncodingFilterFactoryVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IEncodingFilterFactory, :REFIID, :ptr ptr
          PIEncodingFilterFactoryVtbl_QueryInterface typedef ptr TYPE_IEncodingFilterFactoryVtbl_QueryInterface
          TYPE_IEncodingFilterFactoryVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IEncodingFilterFactory
          PIEncodingFilterFactoryVtbl_AddRef typedef ptr TYPE_IEncodingFilterFactoryVtbl_AddRef
          TYPE_IEncodingFilterFactoryVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IEncodingFilterFactory
          PIEncodingFilterFactoryVtbl_Release typedef ptr TYPE_IEncodingFilterFactoryVtbl_Release
          TYPE_IEncodingFilterFactoryVtbl_FindBestFilter typedef proto WIN_STD_CALL_CONV :ptr IEncodingFilterFactory, :LPCWSTR, :LPCWSTR, :DATAINFO, :ptr ptr IDataFilter
          PIEncodingFilterFactoryVtbl_FindBestFilter typedef ptr TYPE_IEncodingFilterFactoryVtbl_FindBestFilter
          TYPE_IEncodingFilterFactoryVtbl_GetDefaultFilter typedef proto WIN_STD_CALL_CONV :ptr IEncodingFilterFactory, :LPCWSTR, :LPCWSTR, :ptr ptr IDataFilter
          PIEncodingFilterFactoryVtbl_GetDefaultFilter typedef ptr TYPE_IEncodingFilterFactoryVtbl_GetDefaultFilter
          IEncodingFilterFactoryVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEncodingFilterFactory>
            QueryInterface PIEncodingFilterFactoryVtbl_QueryInterface ?
            AddRef PIEncodingFilterFactoryVtbl_AddRef ?
            Release PIEncodingFilterFactoryVtbl_Release ?
            FindBestFilter PIEncodingFilterFactoryVtbl_FindBestFilter ?
            GetDefaultFilter PIEncodingFilterFactoryVtbl_GetDefaultFilter ?
            ??Interface equ <>
            END_INTERFACE
          IEncodingFilterFactoryVtbl ends
          IEncodingFilterFactory struct
            lpVtbl POINTER ?
          IEncodingFilterFactory ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    ifndef _HITLOGGING_DEFINED
      _HITLOGGING_DEFINED equ <>
      IsLoggingEnabledA proto WIN_STD_CALL_CONV :LPCSTR
      IsLoggingEnabledW proto WIN_STD_CALL_CONV :LPCWSTR
      ifdef UNICODE
        IsLoggingEnabled equ <IsLoggingEnabledW>
      else
        IsLoggingEnabled equ <IsLoggingEnabledA>
      endif
      HIT_LOGGING_INFO struct
        dwStructSize DWORD ?
        lpszLoggedUrlName LPSTR ?
        StartTime SYSTEMTIME <>
        EndTime SYSTEMTIME <>
        lpszExtendedInfo LPSTR ?
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
        LPIWRAPPEDPROTOCOL typedef ptr IWrappedProtocol
        externdef IID_IWrappedProtocol:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          TYPE_IWrappedProtocolVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IWrappedProtocol, :REFIID, :ptr ptr
          PIWrappedProtocolVtbl_QueryInterface typedef ptr TYPE_IWrappedProtocolVtbl_QueryInterface
          TYPE_IWrappedProtocolVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IWrappedProtocol
          PIWrappedProtocolVtbl_AddRef typedef ptr TYPE_IWrappedProtocolVtbl_AddRef
          TYPE_IWrappedProtocolVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IWrappedProtocol
          PIWrappedProtocolVtbl_Release typedef ptr TYPE_IWrappedProtocolVtbl_Release
          TYPE_IWrappedProtocolVtbl_GetWrapperCode typedef proto WIN_STD_CALL_CONV :ptr IWrappedProtocol, :ptr LONG, :DWORD_PTR
          PIWrappedProtocolVtbl_GetWrapperCode typedef ptr TYPE_IWrappedProtocolVtbl_GetWrapperCode
          IWrappedProtocolVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IWrappedProtocol>
            QueryInterface PIWrappedProtocolVtbl_QueryInterface ?
            AddRef PIWrappedProtocolVtbl_AddRef ?
            Release PIWrappedProtocolVtbl_Release ?
            GetWrapperCode PIWrappedProtocolVtbl_GetWrapperCode ?
            ??Interface equ <>
            END_INTERFACE
          IWrappedProtocolVtbl ends
          IWrappedProtocol struct
            lpVtbl POINTER ?
          IWrappedProtocol ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    ifndef _LPGETBINDHANDLE_DEFINED
      _LPGETBINDHANDLE_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0052_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0052_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IGetBindHandle_INTERFACE_DEFINED__
        __IGetBindHandle_INTERFACE_DEFINED__ equ <>
        LPGETBINDHANDLE typedef ptr IGetBindHandle
        BINDHANDLETYPES typedef SDWORD
        BINDHANDLETYPES_APPCACHE equ 0
        BINDHANDLETYPES_DEPENDENCY equ 1h
        BINDHANDLETYPES_COUNT equ
        __MIDL_IGetBindHandle_0001 typedef BINDHANDLETYPES
        externdef IID_IGetBindHandle:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          TYPE_IGetBindHandleVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IGetBindHandle, :REFIID, :ptr ptr
          PIGetBindHandleVtbl_QueryInterface typedef ptr TYPE_IGetBindHandleVtbl_QueryInterface
          TYPE_IGetBindHandleVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IGetBindHandle
          PIGetBindHandleVtbl_AddRef typedef ptr TYPE_IGetBindHandleVtbl_AddRef
          TYPE_IGetBindHandleVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IGetBindHandle
          PIGetBindHandleVtbl_Release typedef ptr TYPE_IGetBindHandleVtbl_Release
          TYPE_IGetBindHandleVtbl_GetBindHandle typedef proto WIN_STD_CALL_CONV :ptr IGetBindHandle, :BINDHANDLETYPES, :ptr HANDLE
          PIGetBindHandleVtbl_GetBindHandle typedef ptr TYPE_IGetBindHandleVtbl_GetBindHandle
          IGetBindHandleVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IGetBindHandle>
            QueryInterface PIGetBindHandleVtbl_QueryInterface ?
            AddRef PIGetBindHandleVtbl_AddRef ?
            Release PIGetBindHandleVtbl_Release ?
            GetBindHandle PIGetBindHandleVtbl_GetBindHandle ?
            ??Interface equ <>
            END_INTERFACE
          IGetBindHandleVtbl ends
          IGetBindHandle struct
            lpVtbl POINTER ?
          IGetBindHandle ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    ifndef _XHRPLUGGABLEPROTOCOL_DEFINED
      _XHRPLUGGABLEPROTOCOL_DEFINED equ <>
      PROTOCOL_ARGUMENT struct
        szMethod LPCWSTR ?
        szTargetUrl LPCWSTR ?
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
        LPBINDCALLBACKREDIRECT typedef ptr IBindCallbackRedirect
        externdef IID_IBindCallbackRedirect:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          TYPE_IBindCallbackRedirectVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IBindCallbackRedirect, :REFIID, :ptr ptr
          PIBindCallbackRedirectVtbl_QueryInterface typedef ptr TYPE_IBindCallbackRedirectVtbl_QueryInterface
          TYPE_IBindCallbackRedirectVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IBindCallbackRedirect
          PIBindCallbackRedirectVtbl_AddRef typedef ptr TYPE_IBindCallbackRedirectVtbl_AddRef
          TYPE_IBindCallbackRedirectVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IBindCallbackRedirect
          PIBindCallbackRedirectVtbl_Release typedef ptr TYPE_IBindCallbackRedirectVtbl_Release
          TYPE_IBindCallbackRedirectVtbl_Redirect typedef proto WIN_STD_CALL_CONV :ptr IBindCallbackRedirect, :LPCWSTR, :ptr VARIANT_BOOL
          PIBindCallbackRedirectVtbl_Redirect typedef ptr TYPE_IBindCallbackRedirectVtbl_Redirect
          IBindCallbackRedirectVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IBindCallbackRedirect>
            QueryInterface PIBindCallbackRedirectVtbl_QueryInterface ?
            AddRef PIBindCallbackRedirectVtbl_AddRef ?
            Release PIBindCallbackRedirectVtbl_Release ?
            Redirect PIBindCallbackRedirectVtbl_Redirect ?
            ??Interface equ <>
            END_INTERFACE
          IBindCallbackRedirectVtbl ends
          IBindCallbackRedirect struct
            lpVtbl POINTER ?
          IBindCallbackRedirect ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
    ifndef _LPIBINDHTTPSECURITY_DEFINED
      _LPIBINDHTTPSECURITY_DEFINED equ <>
      externdef __MIDL_itf_urlmon_0000_0054_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_urlmon_0000_0054_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IBindHttpSecurity_INTERFACE_DEFINED__
        __IBindHttpSecurity_INTERFACE_DEFINED__ equ <>
        externdef IID_IBindHttpSecurity:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          TYPE_IBindHttpSecurityVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IBindHttpSecurity, :REFIID, :ptr ptr
          PIBindHttpSecurityVtbl_QueryInterface typedef ptr TYPE_IBindHttpSecurityVtbl_QueryInterface
          TYPE_IBindHttpSecurityVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IBindHttpSecurity
          PIBindHttpSecurityVtbl_AddRef typedef ptr TYPE_IBindHttpSecurityVtbl_AddRef
          TYPE_IBindHttpSecurityVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IBindHttpSecurity
          PIBindHttpSecurityVtbl_Release typedef ptr TYPE_IBindHttpSecurityVtbl_Release
          TYPE_IBindHttpSecurityVtbl_GetIgnoreCertMask typedef proto WIN_STD_CALL_CONV :ptr IBindHttpSecurity, :ptr DWORD
          PIBindHttpSecurityVtbl_GetIgnoreCertMask typedef ptr TYPE_IBindHttpSecurityVtbl_GetIgnoreCertMask
          IBindHttpSecurityVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IBindHttpSecurity>
            QueryInterface PIBindHttpSecurityVtbl_QueryInterface ?
            AddRef PIBindHttpSecurityVtbl_AddRef ?
            Release PIBindHttpSecurityVtbl_Release ?
            GetIgnoreCertMask PIBindHttpSecurityVtbl_GetIgnoreCertMask ?
            ??Interface equ <>
            END_INTERFACE
          IBindHttpSecurityVtbl ends
          IBindHttpSecurity struct
            lpVtbl POINTER ?
          IBindHttpSecurity ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
    endif
  endif
  if _MSC_VER ge 1200
  endif
  externdef __MIDL_itf_urlmon_0000_0055_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_urlmon_0000_0055_v0_0_s_ifspec:RPC_IF_HANDLE
  ;Warning: duplicate proto = BSTR_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr BSTR
  ;Warning: duplicate proto = BSTR_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  ;Warning: duplicate proto = BSTR_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  ;Warning: duplicate proto = BSTR_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BSTR
  ;Warning: duplicate proto = HWND_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HWND
  ;Warning: duplicate proto = HWND_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HWND
  ;Warning: duplicate proto = HWND_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HWND
  ;Warning: duplicate proto = HWND_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HWND
  ;Warning: duplicate proto = BSTR_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr BSTR
  ;Warning: duplicate proto = BSTR_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  ;Warning: duplicate proto = BSTR_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  ;Warning: duplicate proto = BSTR_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BSTR
  ;Warning: duplicate proto = HWND_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr HWND
  ;Warning: duplicate proto = HWND_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HWND
  ;Warning: duplicate proto = HWND_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr HWND
  ;Warning: duplicate proto = HWND_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr HWND
  IBinding_GetBindResult_Proxy proto WIN_STD_CALL_CONV :ptr IBinding, :ptr CLSID, :ptr DWORD, :ptr LPOLESTR, :ptr DWORD
  IBinding_GetBindResult_Stub proto WIN_STD_CALL_CONV :ptr IBinding, :ptr CLSID, :ptr DWORD, :ptr LPOLESTR, :DWORD
  IBindStatusCallback_GetBindInfo_Proxy proto WIN_STD_CALL_CONV :ptr IBindStatusCallback, :ptr DWORD, :ptr BINDINFO
  IBindStatusCallback_GetBindInfo_Stub proto WIN_STD_CALL_CONV :ptr IBindStatusCallback, :ptr DWORD, :ptr RemBINDINFO, :ptr RemSTGMEDIUM
  IBindStatusCallback_OnDataAvailable_Proxy proto WIN_STD_CALL_CONV :ptr IBindStatusCallback, :DWORD, :DWORD, :ptr FORMATETC, :ptr STGMEDIUM
  IBindStatusCallback_OnDataAvailable_Stub proto WIN_STD_CALL_CONV :ptr IBindStatusCallback, :DWORD, :DWORD, :ptr RemFORMATETC, :ptr RemSTGMEDIUM
  IBindStatusCallbackEx_GetBindInfoEx_Proxy proto WIN_STD_CALL_CONV :ptr IBindStatusCallbackEx, :ptr DWORD, :ptr BINDINFO, :ptr DWORD, :ptr DWORD
  IBindStatusCallbackEx_GetBindInfoEx_Stub proto WIN_STD_CALL_CONV :ptr IBindStatusCallbackEx, :ptr DWORD, :ptr RemBINDINFO, :ptr RemSTGMEDIUM, :ptr DWORD, :ptr DWORD
  IWinInetInfo_QueryOption_Proxy proto WIN_STD_CALL_CONV :ptr IWinInetInfo, :DWORD, :LPVOID, :ptr DWORD
  IWinInetInfo_QueryOption_Stub proto WIN_STD_CALL_CONV :ptr IWinInetInfo, :DWORD, :ptr BYTE, :ptr DWORD
  IWinInetHttpInfo_QueryInfo_Proxy proto WIN_STD_CALL_CONV :ptr IWinInetHttpInfo, :DWORD, :LPVOID, :ptr DWORD, :ptr DWORD, :ptr DWORD
  IWinInetHttpInfo_QueryInfo_Stub proto WIN_STD_CALL_CONV :ptr IWinInetHttpInfo, :DWORD, :ptr BYTE, :ptr DWORD, :ptr DWORD, :ptr DWORD
  IBindHost_MonikerBindToStorage_Proxy proto WIN_STD_CALL_CONV :ptr IBindHost, :ptr IMoniker, :ptr IBindCtx, :ptr IBindStatusCallback, :REFIID, :ptr ptr
  IBindHost_MonikerBindToStorage_Stub proto WIN_STD_CALL_CONV :ptr IBindHost, :ptr IMoniker, :ptr IBindCtx, :ptr IBindStatusCallback, :REFIID, :ptr ptr IUnknown
  IBindHost_MonikerBindToObject_Proxy proto WIN_STD_CALL_CONV :ptr IBindHost, :ptr IMoniker, :ptr IBindCtx, :ptr IBindStatusCallback, :REFIID, :ptr ptr
  IBindHost_MonikerBindToObject_Stub proto WIN_STD_CALL_CONV :ptr IBindHost, :ptr IMoniker, :ptr IBindCtx, :ptr IBindStatusCallback, :REFIID, :ptr ptr IUnknown
  ifdef __cplusplus
    ;[...]
  endif
endif

