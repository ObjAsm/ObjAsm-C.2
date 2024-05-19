;Include file created by h2inc+ version C.2.0 on (UTC) 19/05/2024 07:52:23
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\urlmon.h\urlmon.h
;             Created on (UTC) 06/04/2024 06:16:02
;             Last modified on (UTC) 21/02/2024 18:16:58

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
  ifndef __IPersistMoniker_FWD_DEFINED__
    __IPersistMoniker_FWD_DEFINED__ equ <>
  endif
  ifndef __IMonikerProp_FWD_DEFINED__
    __IMonikerProp_FWD_DEFINED__ equ <>
  endif
  ifndef __IBindProtocol_FWD_DEFINED__
    __IBindProtocol_FWD_DEFINED__ equ <>
  endif
  ifndef __IBinding_FWD_DEFINED__
    __IBinding_FWD_DEFINED__ equ <>
  endif
  ifndef __IBindStatusCallback_FWD_DEFINED__
    __IBindStatusCallback_FWD_DEFINED__ equ <>
  endif
  ifndef __IBindStatusCallbackEx_FWD_DEFINED__
    __IBindStatusCallbackEx_FWD_DEFINED__ equ <>
  endif
  ifndef __IAuthenticate_FWD_DEFINED__
    __IAuthenticate_FWD_DEFINED__ equ <>
  endif
  ifndef __IAuthenticateEx_FWD_DEFINED__
    __IAuthenticateEx_FWD_DEFINED__ equ <>
  endif
  ifndef __IHttpNegotiate_FWD_DEFINED__
    __IHttpNegotiate_FWD_DEFINED__ equ <>
  endif
  ifndef __IHttpNegotiate2_FWD_DEFINED__
    __IHttpNegotiate2_FWD_DEFINED__ equ <>
  endif
  ifndef __IHttpNegotiate3_FWD_DEFINED__
    __IHttpNegotiate3_FWD_DEFINED__ equ <>
  endif
  ifndef __IWinInetFileStream_FWD_DEFINED__
    __IWinInetFileStream_FWD_DEFINED__ equ <>
  endif
  ifndef __IWindowForBindingUI_FWD_DEFINED__
    __IWindowForBindingUI_FWD_DEFINED__ equ <>
  endif
  ifndef __ICodeInstall_FWD_DEFINED__
    __ICodeInstall_FWD_DEFINED__ equ <>
  endif
  ifndef __IUri_FWD_DEFINED__
    __IUri_FWD_DEFINED__ equ <>
  endif
  ifndef __IUriContainer_FWD_DEFINED__
    __IUriContainer_FWD_DEFINED__ equ <>
  endif
  ifndef __IUriBuilder_FWD_DEFINED__
    __IUriBuilder_FWD_DEFINED__ equ <>
  endif
  ifndef __IUriBuilderFactory_FWD_DEFINED__
    __IUriBuilderFactory_FWD_DEFINED__ equ <>
  endif
  ifndef __IWinInetInfo_FWD_DEFINED__
    __IWinInetInfo_FWD_DEFINED__ equ <>
  endif
  ifndef __IHttpSecurity_FWD_DEFINED__
    __IHttpSecurity_FWD_DEFINED__ equ <>
  endif
  ifndef __IWinInetHttpInfo_FWD_DEFINED__
    __IWinInetHttpInfo_FWD_DEFINED__ equ <>
  endif
  ifndef __IWinInetHttpTimeouts_FWD_DEFINED__
    __IWinInetHttpTimeouts_FWD_DEFINED__ equ <>
  endif
  ifndef __IWinInetCacheHints_FWD_DEFINED__
    __IWinInetCacheHints_FWD_DEFINED__ equ <>
  endif
  ifndef __IWinInetCacheHints2_FWD_DEFINED__
    __IWinInetCacheHints2_FWD_DEFINED__ equ <>
  endif
  ifndef __IBindHost_FWD_DEFINED__
    __IBindHost_FWD_DEFINED__ equ <>
  endif
  ifndef __IInternet_FWD_DEFINED__
    __IInternet_FWD_DEFINED__ equ <>
  endif
  ifndef __IInternetBindInfo_FWD_DEFINED__
    __IInternetBindInfo_FWD_DEFINED__ equ <>
  endif
  ifndef __IInternetBindInfoEx_FWD_DEFINED__
    __IInternetBindInfoEx_FWD_DEFINED__ equ <>
  endif
  ifndef __IInternetProtocolRoot_FWD_DEFINED__
    __IInternetProtocolRoot_FWD_DEFINED__ equ <>
  endif
  ifndef __IInternetProtocol_FWD_DEFINED__
    __IInternetProtocol_FWD_DEFINED__ equ <>
  endif
  ifndef __IInternetProtocolEx_FWD_DEFINED__
    __IInternetProtocolEx_FWD_DEFINED__ equ <>
  endif
  ifndef __IInternetProtocolSink_FWD_DEFINED__
    __IInternetProtocolSink_FWD_DEFINED__ equ <>
  endif
  ifndef __IInternetProtocolSinkStackable_FWD_DEFINED__
    __IInternetProtocolSinkStackable_FWD_DEFINED__ equ <>
  endif
  ifndef __IInternetSession_FWD_DEFINED__
    __IInternetSession_FWD_DEFINED__ equ <>
  endif
  ifndef __IInternetThreadSwitch_FWD_DEFINED__
    __IInternetThreadSwitch_FWD_DEFINED__ equ <>
  endif
  ifndef __IInternetPriority_FWD_DEFINED__
    __IInternetPriority_FWD_DEFINED__ equ <>
  endif
  ifndef __IInternetProtocolInfo_FWD_DEFINED__
    __IInternetProtocolInfo_FWD_DEFINED__ equ <>
  endif
  ifndef __IInternetSecurityMgrSite_FWD_DEFINED__
    __IInternetSecurityMgrSite_FWD_DEFINED__ equ <>
  endif
  ifndef __IInternetSecurityManager_FWD_DEFINED__
    __IInternetSecurityManager_FWD_DEFINED__ equ <>
  endif
  ifndef __IInternetSecurityManagerEx_FWD_DEFINED__
    __IInternetSecurityManagerEx_FWD_DEFINED__ equ <>
  endif
  ifndef __IInternetSecurityManagerEx2_FWD_DEFINED__
    __IInternetSecurityManagerEx2_FWD_DEFINED__ equ <>
  endif
  ifndef __IZoneIdentifier_FWD_DEFINED__
    __IZoneIdentifier_FWD_DEFINED__ equ <>
  endif
  ifndef __IZoneIdentifier2_FWD_DEFINED__
    __IZoneIdentifier2_FWD_DEFINED__ equ <>
  endif
  ifndef __IInternetHostSecurityManager_FWD_DEFINED__
    __IInternetHostSecurityManager_FWD_DEFINED__ equ <>
  endif
  ifndef __IInternetZoneManager_FWD_DEFINED__
    __IInternetZoneManager_FWD_DEFINED__ equ <>
  endif
  ifndef __IInternetZoneManagerEx_FWD_DEFINED__
    __IInternetZoneManagerEx_FWD_DEFINED__ equ <>
  endif
  ifndef __IInternetZoneManagerEx2_FWD_DEFINED__
    __IInternetZoneManagerEx2_FWD_DEFINED__ equ <>
  endif
  ifndef __ISoftDistExt_FWD_DEFINED__
    __ISoftDistExt_FWD_DEFINED__ equ <>
  endif
  ifndef __ICatalogFileInfo_FWD_DEFINED__
    __ICatalogFileInfo_FWD_DEFINED__ equ <>
  endif
  ifndef __IDataFilter_FWD_DEFINED__
    __IDataFilter_FWD_DEFINED__ equ <>
  endif
  ifndef __IEncodingFilterFactory_FWD_DEFINED__
    __IEncodingFilterFactory_FWD_DEFINED__ equ <>
  endif
  ifndef __IWrappedProtocol_FWD_DEFINED__
    __IWrappedProtocol_FWD_DEFINED__ equ <>
  endif
  ifndef __IGetBindHandle_FWD_DEFINED__
    __IGetBindHandle_FWD_DEFINED__ equ <>
  endif
  ifndef __IBindCallbackRedirect_FWD_DEFINED__
    __IBindCallbackRedirect_FWD_DEFINED__ equ <>
  endif
  ifndef __IBindHttpSecurity_FWD_DEFINED__
    __IBindHttpSecurity_FWD_DEFINED__ equ <>
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
    FMFD_RESERVED_2 equ 00000080h
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
    INET_E_RESERVED_5 equ _HRESULT_TYPEDEF_(800C0022h)
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
          IPersistMonikerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IPersistMonikerVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IPersistMoniker, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IPersistMoniker
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IPersistMoniker
            DECLSPEC_XFGVIRT(IPersistMoniker, GetClassID)
            STD_METHOD GetClassID, :ptr IPersistMoniker, :ptr CLSID
            DECLSPEC_XFGVIRT(IPersistMoniker, IsDirty)
            STD_METHOD IsDirty, :ptr IPersistMoniker
            DECLSPEC_XFGVIRT(IPersistMoniker, Load)
            STD_METHOD Load, :ptr IPersistMoniker, :BOOL, :ptr IMoniker, :LPBC, :DWORD
            DECLSPEC_XFGVIRT(IPersistMoniker, Save)
            STD_METHOD Save, :ptr IPersistMoniker, :ptr IMoniker, :LPBC, :BOOL
            DECLSPEC_XFGVIRT(IPersistMoniker, SaveCompleted)
            STD_METHOD SaveCompleted, :ptr IPersistMoniker, :ptr IMoniker, :LPBC
            DECLSPEC_XFGVIRT(IPersistMoniker, GetCurMoniker)
            STD_METHOD GetCurMoniker, :ptr IPersistMoniker, :ptr ptr IMoniker
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
          IMonikerPropVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IMonikerPropVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IMonikerProp, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IMonikerProp
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IMonikerProp
            DECLSPEC_XFGVIRT(IMonikerProp, PutProperty)
            STD_METHOD PutProperty, :ptr IMonikerProp, :MONIKERPROPERTY, :LPCWSTR
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
          IBindProtocolVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IBindProtocolVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IBindProtocol, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IBindProtocol
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IBindProtocol
            DECLSPEC_XFGVIRT(IBindProtocol, CreateBinding)
            STD_METHOD CreateBinding, :ptr IBindProtocol, :LPCWSTR, :ptr IBindCtx, :ptr ptr IBinding
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
          IBindingVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IBindingVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
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
            DECLSPEC_XFGVIRT(IBinding, GetPriority)
            STD_METHOD GetPriority, :ptr IBinding, :ptr LONG
            DECLSPEC_XFGVIRT(IBinding, GetBindResult)
            STD_METHOD GetBindResult, :ptr IBinding, :ptr CLSID, :ptr DWORD, :ptr LPOLESTR, :ptr DWORD
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
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
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
            STD_METHOD QueryInterface, :ptr IBindStatusCallback, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IBindStatusCallback
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IBindStatusCallback
            DECLSPEC_XFGVIRT(IBindStatusCallback, OnStartBinding)
            STD_METHOD OnStartBinding, :ptr IBindStatusCallback, :DWORD, :ptr IBinding
            DECLSPEC_XFGVIRT(IBindStatusCallback, GetPriority)
            STD_METHOD GetPriority, :ptr IBindStatusCallback, :ptr LONG
            DECLSPEC_XFGVIRT(IBindStatusCallback, OnLowResource)
            STD_METHOD OnLowResource, :ptr IBindStatusCallback, :DWORD
            DECLSPEC_XFGVIRT(IBindStatusCallback, OnProgress)
            STD_METHOD OnProgress, :ptr IBindStatusCallback, :ULONG, :ULONG, :ULONG, :LPCWSTR
            DECLSPEC_XFGVIRT(IBindStatusCallback, OnStopBinding)
            STD_METHOD OnStopBinding, :ptr IBindStatusCallback, :HRESULT, :LPCWSTR
            DECLSPEC_XFGVIRT(IBindStatusCallback, GetBindInfo)
            STD_METHOD GetBindInfo, :ptr IBindStatusCallback, :ptr DWORD, :ptr BINDINFO
            DECLSPEC_XFGVIRT(IBindStatusCallback, OnDataAvailable)
            STD_METHOD OnDataAvailable, :ptr IBindStatusCallback, :DWORD, :DWORD, :ptr FORMATETC, :ptr STGMEDIUM
            DECLSPEC_XFGVIRT(IBindStatusCallback, OnObjectAvailable)
            STD_METHOD OnObjectAvailable, :ptr IBindStatusCallback, :REFIID, :ptr IUnknown
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
          IBindStatusCallbackExVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IBindStatusCallbackExVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IBindStatusCallbackEx, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IBindStatusCallbackEx
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IBindStatusCallbackEx
            DECLSPEC_XFGVIRT(IBindStatusCallback, OnStartBinding)
            STD_METHOD OnStartBinding, :ptr IBindStatusCallbackEx, :DWORD, :ptr IBinding
            DECLSPEC_XFGVIRT(IBindStatusCallback, GetPriority)
            STD_METHOD GetPriority, :ptr IBindStatusCallbackEx, :ptr LONG
            DECLSPEC_XFGVIRT(IBindStatusCallback, OnLowResource)
            STD_METHOD OnLowResource, :ptr IBindStatusCallbackEx, :DWORD
            DECLSPEC_XFGVIRT(IBindStatusCallback, OnProgress)
            STD_METHOD OnProgress, :ptr IBindStatusCallbackEx, :ULONG, :ULONG, :ULONG, :LPCWSTR
            DECLSPEC_XFGVIRT(IBindStatusCallback, OnStopBinding)
            STD_METHOD OnStopBinding, :ptr IBindStatusCallbackEx, :HRESULT, :LPCWSTR
            DECLSPEC_XFGVIRT(IBindStatusCallback, GetBindInfo)
            STD_METHOD GetBindInfo, :ptr IBindStatusCallbackEx, :ptr DWORD, :ptr BINDINFO
            DECLSPEC_XFGVIRT(IBindStatusCallback, OnDataAvailable)
            STD_METHOD OnDataAvailable, :ptr IBindStatusCallbackEx, :DWORD, :DWORD, :ptr FORMATETC, :ptr STGMEDIUM
            DECLSPEC_XFGVIRT(IBindStatusCallback, OnObjectAvailable)
            STD_METHOD OnObjectAvailable, :ptr IBindStatusCallbackEx, :REFIID, :ptr IUnknown
            DECLSPEC_XFGVIRT(IBindStatusCallbackEx, GetBindInfoEx)
            STD_METHOD GetBindInfoEx, :ptr IBindStatusCallbackEx, :ptr DWORD, :ptr BINDINFO, :ptr DWORD, :ptr DWORD
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
          IAuthenticateVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IAuthenticateVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IAuthenticate, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IAuthenticate
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IAuthenticate
            DECLSPEC_XFGVIRT(IAuthenticate, Authenticate)
            STD_METHOD Authenticate, :ptr IAuthenticate, :ptr HWND, :ptr LPWSTR, :ptr LPWSTR
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
          IAuthenticateExVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IAuthenticateExVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IAuthenticateEx, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IAuthenticateEx
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IAuthenticateEx
            DECLSPEC_XFGVIRT(IAuthenticate, Authenticate)
            STD_METHOD Authenticate, :ptr IAuthenticateEx, :ptr HWND, :ptr LPWSTR, :ptr LPWSTR
            DECLSPEC_XFGVIRT(IAuthenticateEx, AuthenticateEx)
            STD_METHOD AuthenticateEx, :ptr IAuthenticateEx, :ptr HWND, :ptr LPWSTR, :ptr LPWSTR, :ptr AUTHENTICATEINFO
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
          IHttpNegotiateVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IHttpNegotiateVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IHttpNegotiate, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IHttpNegotiate
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IHttpNegotiate
            DECLSPEC_XFGVIRT(IHttpNegotiate, BeginningTransaction)
            STD_METHOD BeginningTransaction, :ptr IHttpNegotiate, :LPCWSTR, :LPCWSTR, :DWORD, :ptr LPWSTR
            DECLSPEC_XFGVIRT(IHttpNegotiate, OnResponse)
            STD_METHOD OnResponse, :ptr IHttpNegotiate, :DWORD, :LPCWSTR, :LPCWSTR, :ptr LPWSTR
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
          IHttpNegotiate2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IHttpNegotiate2Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IHttpNegotiate2, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IHttpNegotiate2
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IHttpNegotiate2
            DECLSPEC_XFGVIRT(IHttpNegotiate, BeginningTransaction)
            STD_METHOD BeginningTransaction, :ptr IHttpNegotiate2, :LPCWSTR, :LPCWSTR, :DWORD, :ptr LPWSTR
            DECLSPEC_XFGVIRT(IHttpNegotiate, OnResponse)
            STD_METHOD OnResponse, :ptr IHttpNegotiate2, :DWORD, :LPCWSTR, :LPCWSTR, :ptr LPWSTR
            DECLSPEC_XFGVIRT(IHttpNegotiate2, GetRootSecurityId)
            STD_METHOD GetRootSecurityId, :ptr IHttpNegotiate2, :ptr BYTE, :ptr DWORD, :DWORD_PTR
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
          IHttpNegotiate3Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IHttpNegotiate3Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IHttpNegotiate3, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IHttpNegotiate3
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IHttpNegotiate3
            DECLSPEC_XFGVIRT(IHttpNegotiate, BeginningTransaction)
            STD_METHOD BeginningTransaction, :ptr IHttpNegotiate3, :LPCWSTR, :LPCWSTR, :DWORD, :ptr LPWSTR
            DECLSPEC_XFGVIRT(IHttpNegotiate, OnResponse)
            STD_METHOD OnResponse, :ptr IHttpNegotiate3, :DWORD, :LPCWSTR, :LPCWSTR, :ptr LPWSTR
            DECLSPEC_XFGVIRT(IHttpNegotiate2, GetRootSecurityId)
            STD_METHOD GetRootSecurityId, :ptr IHttpNegotiate3, :ptr BYTE, :ptr DWORD, :DWORD_PTR
            DECLSPEC_XFGVIRT(IHttpNegotiate3, GetSerializedClientCertContext)
            STD_METHOD GetSerializedClientCertContext, :ptr IHttpNegotiate3, :ptr ptr BYTE, :ptr DWORD
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
          IWinInetFileStreamVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IWinInetFileStreamVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IWinInetFileStream, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IWinInetFileStream
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IWinInetFileStream
            DECLSPEC_XFGVIRT(IWinInetFileStream, SetHandleForUnlock)
            STD_METHOD SetHandleForUnlock, :ptr IWinInetFileStream, :DWORD_PTR, :DWORD_PTR
            DECLSPEC_XFGVIRT(IWinInetFileStream, SetDeleteFile)
            STD_METHOD SetDeleteFile, :ptr IWinInetFileStream, :DWORD_PTR
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
          IWindowForBindingUIVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IWindowForBindingUIVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IWindowForBindingUI, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IWindowForBindingUI
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IWindowForBindingUI
            DECLSPEC_XFGVIRT(IWindowForBindingUI, GetWindow)
            STD_METHOD GetWindow, :ptr IWindowForBindingUI, :REFGUID, :ptr HWND
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
          ICodeInstallVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ICodeInstallVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ICodeInstall, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ICodeInstall
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ICodeInstall
            DECLSPEC_XFGVIRT(IWindowForBindingUI, GetWindow)
            STD_METHOD GetWindow, :ptr ICodeInstall, :REFGUID, :ptr HWND
            DECLSPEC_XFGVIRT(ICodeInstall, OnCodeInstallProblem)
            STD_METHOD OnCodeInstallProblem, :ptr ICodeInstall, :ULONG, :LPCWSTR, :LPCWSTR, :DWORD
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
            IUriVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IUriVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IUri, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IUri
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IUri
              DECLSPEC_XFGVIRT(IUri, GetPropertyBSTR)
              STD_METHOD GetPropertyBSTR, :ptr IUri, :Uri_PROPERTY, :ptr BSTR, :DWORD
              DECLSPEC_XFGVIRT(IUri, GetPropertyLength)
              STD_METHOD GetPropertyLength, :ptr IUri, :Uri_PROPERTY, :ptr DWORD, :DWORD
              DECLSPEC_XFGVIRT(IUri, GetPropertyDWORD)
              STD_METHOD GetPropertyDWORD, :ptr IUri, :Uri_PROPERTY, :ptr DWORD, :DWORD
              DECLSPEC_XFGVIRT(IUri, HasProperty)
              STD_METHOD HasProperty, :ptr IUri, :Uri_PROPERTY, :ptr BOOL
              DECLSPEC_XFGVIRT(IUri, GetAbsoluteUri)
              STD_METHOD GetAbsoluteUri, :ptr IUri, :ptr BSTR
              DECLSPEC_XFGVIRT(IUri, GetAuthority)
              STD_METHOD GetAuthority, :ptr IUri, :ptr BSTR
              DECLSPEC_XFGVIRT(IUri, GetDisplayUri)
              STD_METHOD GetDisplayUri, :ptr IUri, :ptr BSTR
              DECLSPEC_XFGVIRT(IUri, GetDomain)
              STD_METHOD GetDomain, :ptr IUri, :ptr BSTR
              DECLSPEC_XFGVIRT(IUri, GetExtension)
              STD_METHOD GetExtension, :ptr IUri, :ptr BSTR
              DECLSPEC_XFGVIRT(IUri, GetFragment)
              STD_METHOD GetFragment, :ptr IUri, :ptr BSTR
              DECLSPEC_XFGVIRT(IUri, GetHost)
              STD_METHOD GetHost, :ptr IUri, :ptr BSTR
              DECLSPEC_XFGVIRT(IUri, GetPassword)
              STD_METHOD GetPassword, :ptr IUri, :ptr BSTR
              DECLSPEC_XFGVIRT(IUri, GetPath)
              STD_METHOD GetPath, :ptr IUri, :ptr BSTR
              DECLSPEC_XFGVIRT(IUri, GetPathAndQuery)
              STD_METHOD GetPathAndQuery, :ptr IUri, :ptr BSTR
              DECLSPEC_XFGVIRT(IUri, GetQuery)
              STD_METHOD GetQuery, :ptr IUri, :ptr BSTR
              DECLSPEC_XFGVIRT(IUri, GetRawUri)
              STD_METHOD GetRawUri, :ptr IUri, :ptr BSTR
              DECLSPEC_XFGVIRT(IUri, GetSchemeName)
              STD_METHOD GetSchemeName, :ptr IUri, :ptr BSTR
              DECLSPEC_XFGVIRT(IUri, GetUserInfo)
              STD_METHOD GetUserInfo, :ptr IUri, :ptr BSTR
              DECLSPEC_XFGVIRT(IUri, GetUserName)
              STD_METHOD GetUserName, :ptr IUri, :ptr BSTR
              DECLSPEC_XFGVIRT(IUri, GetHostType)
              STD_METHOD GetHostType, :ptr IUri, :ptr DWORD
              DECLSPEC_XFGVIRT(IUri, GetPort)
              STD_METHOD GetPort, :ptr IUri, :ptr DWORD
              DECLSPEC_XFGVIRT(IUri, GetScheme)
              STD_METHOD GetScheme, :ptr IUri, :ptr DWORD
              DECLSPEC_XFGVIRT(IUri, GetZone)
              STD_METHOD GetZone, :ptr IUri, :ptr DWORD
              DECLSPEC_XFGVIRT(IUri, GetProperties)
              STD_METHOD GetProperties, :ptr IUri, :LPDWORD
              DECLSPEC_XFGVIRT(IUri, IsEqual)
              STD_METHOD IsEqual, :ptr IUri, :ptr IUri, :ptr BOOL
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
          IUriContainerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IUriContainerVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IUriContainer, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IUriContainer
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IUriContainer
            DECLSPEC_XFGVIRT(IUriContainer, GetIUri)
            STD_METHOD GetIUri, :ptr IUriContainer, :ptr ptr IUri
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
          IUriBuilderVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IUriBuilderVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IUriBuilder, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IUriBuilder
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IUriBuilder
            DECLSPEC_XFGVIRT(IUriBuilder, CreateUriSimple)
            STD_METHOD CreateUriSimple, :ptr IUriBuilder, :DWORD, :DWORD_PTR, :ptr ptr IUri
            DECLSPEC_XFGVIRT(IUriBuilder, CreateUri)
            STD_METHOD CreateUri, :ptr IUriBuilder, :DWORD, :DWORD, :DWORD_PTR, :ptr ptr IUri
            DECLSPEC_XFGVIRT(IUriBuilder, CreateUriWithFlags)
            STD_METHOD CreateUriWithFlags, :ptr IUriBuilder, :DWORD, :DWORD, :DWORD, :DWORD_PTR, :ptr ptr IUri
            DECLSPEC_XFGVIRT(IUriBuilder, GetIUri)
            STD_METHOD GetIUri, :ptr IUriBuilder, :ptr ptr IUri
            DECLSPEC_XFGVIRT(IUriBuilder, SetIUri)
            STD_METHOD SetIUri, :ptr IUriBuilder, :ptr IUri
            DECLSPEC_XFGVIRT(IUriBuilder, GetFragment)
            STD_METHOD GetFragment, :ptr IUriBuilder, :ptr DWORD, :ptr LPCWSTR
            DECLSPEC_XFGVIRT(IUriBuilder, GetHost)
            STD_METHOD GetHost, :ptr IUriBuilder, :ptr DWORD, :ptr LPCWSTR
            DECLSPEC_XFGVIRT(IUriBuilder, GetPassword)
            STD_METHOD GetPassword, :ptr IUriBuilder, :ptr DWORD, :ptr LPCWSTR
            DECLSPEC_XFGVIRT(IUriBuilder, GetPath)
            STD_METHOD GetPath, :ptr IUriBuilder, :ptr DWORD, :ptr LPCWSTR
            DECLSPEC_XFGVIRT(IUriBuilder, GetPort)
            STD_METHOD GetPort, :ptr IUriBuilder, :ptr BOOL, :ptr DWORD
            DECLSPEC_XFGVIRT(IUriBuilder, GetQuery)
            STD_METHOD GetQuery, :ptr IUriBuilder, :ptr DWORD, :ptr LPCWSTR
            DECLSPEC_XFGVIRT(IUriBuilder, GetSchemeName)
            STD_METHOD GetSchemeName, :ptr IUriBuilder, :ptr DWORD, :ptr LPCWSTR
            DECLSPEC_XFGVIRT(IUriBuilder, GetUserName)
            STD_METHOD GetUserName, :ptr IUriBuilder, :ptr DWORD, :ptr LPCWSTR
            DECLSPEC_XFGVIRT(IUriBuilder, SetFragment)
            STD_METHOD SetFragment, :ptr IUriBuilder, :LPCWSTR
            DECLSPEC_XFGVIRT(IUriBuilder, SetHost)
            STD_METHOD SetHost, :ptr IUriBuilder, :LPCWSTR
            DECLSPEC_XFGVIRT(IUriBuilder, SetPassword)
            STD_METHOD SetPassword, :ptr IUriBuilder, :LPCWSTR
            DECLSPEC_XFGVIRT(IUriBuilder, SetPath)
            STD_METHOD SetPath, :ptr IUriBuilder, :LPCWSTR
            DECLSPEC_XFGVIRT(IUriBuilder, SetPort)
            STD_METHOD SetPort, :ptr IUriBuilder, :BOOL, :DWORD
            DECLSPEC_XFGVIRT(IUriBuilder, SetQuery)
            STD_METHOD SetQuery, :ptr IUriBuilder, :LPCWSTR
            DECLSPEC_XFGVIRT(IUriBuilder, SetSchemeName)
            STD_METHOD SetSchemeName, :ptr IUriBuilder, :LPCWSTR
            DECLSPEC_XFGVIRT(IUriBuilder, SetUserName)
            STD_METHOD SetUserName, :ptr IUriBuilder, :LPCWSTR
            DECLSPEC_XFGVIRT(IUriBuilder, RemoveProperties)
            STD_METHOD RemoveProperties, :ptr IUriBuilder, :DWORD
            DECLSPEC_XFGVIRT(IUriBuilder, HasBeenModified)
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
        endif
      endif
      ifndef __IUriBuilderFactory_INTERFACE_DEFINED__
        __IUriBuilderFactory_INTERFACE_DEFINED__ equ <>
        externdef IID_IUriBuilderFactory:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IUriBuilderFactoryVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IUriBuilderFactoryVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IUriBuilderFactory, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IUriBuilderFactory
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IUriBuilderFactory
            DECLSPEC_XFGVIRT(IUriBuilderFactory, CreateIUriBuilder)
            STD_METHOD CreateIUriBuilder, :ptr IUriBuilderFactory, :DWORD, :DWORD_PTR, :ptr ptr IUriBuilder
            DECLSPEC_XFGVIRT(IUriBuilderFactory, CreateInitializedIUriBuilder)
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
          IWinInetInfoVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IWinInetInfoVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IWinInetInfo, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IWinInetInfo
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IWinInetInfo
            DECLSPEC_XFGVIRT(IWinInetInfo, QueryOption)
            STD_METHOD QueryOption, :ptr IWinInetInfo, :DWORD, :LPVOID, :ptr DWORD
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
          IHttpSecurityVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IHttpSecurityVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IHttpSecurity, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IHttpSecurity
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IHttpSecurity
            DECLSPEC_XFGVIRT(IWindowForBindingUI, GetWindow)
            STD_METHOD GetWindow, :ptr IHttpSecurity, :REFGUID, :ptr HWND
            DECLSPEC_XFGVIRT(IHttpSecurity, OnSecurityProblem)
            STD_METHOD OnSecurityProblem, :ptr IHttpSecurity, :DWORD
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
          IWinInetHttpInfoVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IWinInetHttpInfoVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IWinInetHttpInfo, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IWinInetHttpInfo
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IWinInetHttpInfo
            DECLSPEC_XFGVIRT(IWinInetInfo, QueryOption)
            STD_METHOD QueryOption, :ptr IWinInetHttpInfo, :DWORD, :LPVOID, :ptr DWORD
            DECLSPEC_XFGVIRT(IWinInetHttpInfo, QueryInfo)
            STD_METHOD QueryInfo, :ptr IWinInetHttpInfo, :DWORD, :LPVOID, :ptr DWORD, :ptr DWORD, :ptr DWORD
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
          IWinInetHttpTimeoutsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IWinInetHttpTimeoutsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IWinInetHttpTimeouts, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IWinInetHttpTimeouts
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IWinInetHttpTimeouts
            DECLSPEC_XFGVIRT(IWinInetHttpTimeouts, GetRequestTimeouts)
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
            IWinInetCacheHintsVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IWinInetCacheHintsVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IWinInetCacheHints, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IWinInetCacheHints
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IWinInetCacheHints
              DECLSPEC_XFGVIRT(IWinInetCacheHints, SetCacheExtension)
              STD_METHOD SetCacheExtension, :ptr IWinInetCacheHints, :LPCWSTR, :LPVOID, :ptr DWORD, :ptr DWORD, :ptr DWORD
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
            IWinInetCacheHints2Vtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IWinInetCacheHints2Vtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IWinInetCacheHints2, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IWinInetCacheHints2
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IWinInetCacheHints2
              DECLSPEC_XFGVIRT(IWinInetCacheHints, SetCacheExtension)
              STD_METHOD SetCacheExtension, :ptr IWinInetCacheHints2, :LPCWSTR, :LPVOID, :ptr DWORD, :ptr DWORD, :ptr DWORD
              DECLSPEC_XFGVIRT(IWinInetCacheHints2, SetCacheExtension2)
              STD_METHOD SetCacheExtension2, :ptr IWinInetCacheHints2, :LPCWSTR, :ptr WCHAR, :ptr DWORD, :ptr DWORD, :ptr DWORD
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
          IBindHostVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IBindHostVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IBindHost, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IBindHost
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IBindHost
            DECLSPEC_XFGVIRT(IBindHost, CreateMoniker)
            STD_METHOD CreateMoniker, :ptr IBindHost, :LPOLESTR, :ptr IBindCtx, :ptr ptr IMoniker, :DWORD
            DECLSPEC_XFGVIRT(IBindHost, MonikerBindToStorage)
            STD_METHOD MonikerBindToStorage, :ptr IBindHost, :ptr IMoniker, :ptr IBindCtx, :ptr IBindStatusCallback, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IBindHost, MonikerBindToObject)
            STD_METHOD MonikerBindToObject, :ptr IBindHost, :ptr IMoniker, :ptr IBindCtx, :ptr IBindStatusCallback, :REFIID, :ptr ptr
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
            IInternetVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
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
              STD_METHOD QueryInterface, :ptr IInternetBindInfo, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IInternetBindInfo
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IInternetBindInfo
              DECLSPEC_XFGVIRT(IInternetBindInfo, GetBindInfo)
              STD_METHOD GetBindInfo, :ptr IInternetBindInfo, :ptr DWORD, :ptr BINDINFO
              DECLSPEC_XFGVIRT(IInternetBindInfo, GetBindString)
              STD_METHOD GetBindString, :ptr IInternetBindInfo, :ULONG, :ptr LPOLESTR, :ULONG, :ptr ULONG
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
            IInternetBindInfoExVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetBindInfoExVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IInternetBindInfoEx, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IInternetBindInfoEx
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IInternetBindInfoEx
              DECLSPEC_XFGVIRT(IInternetBindInfo, GetBindInfo)
              STD_METHOD GetBindInfo, :ptr IInternetBindInfoEx, :ptr DWORD, :ptr BINDINFO
              DECLSPEC_XFGVIRT(IInternetBindInfo, GetBindString)
              STD_METHOD GetBindString, :ptr IInternetBindInfoEx, :ULONG, :ptr LPOLESTR, :ULONG, :ptr ULONG
              DECLSPEC_XFGVIRT(IInternetBindInfoEx, GetBindInfoEx)
              STD_METHOD GetBindInfoEx, :ptr IInternetBindInfoEx, :ptr DWORD, :ptr BINDINFO, :ptr DWORD, :ptr DWORD
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
            IInternetProtocolRootVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetProtocolRootVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IInternetProtocolRoot, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IInternetProtocolRoot
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IInternetProtocolRoot
              DECLSPEC_XFGVIRT(IInternetProtocolRoot, Start)
              STD_METHOD Start, :ptr IInternetProtocolRoot, :LPCWSTR, :ptr IInternetProtocolSink, :ptr IInternetBindInfo, :DWORD, :HANDLE_PTR
              DECLSPEC_XFGVIRT(IInternetProtocolRoot, Continue)
              STD_METHOD Continue, :ptr IInternetProtocolRoot, :ptr PROTOCOLDATA
              DECLSPEC_XFGVIRT(IInternetProtocolRoot, Abort)
              STD_METHOD Abort, :ptr IInternetProtocolRoot, :HRESULT, :DWORD
              DECLSPEC_XFGVIRT(IInternetProtocolRoot, Terminate)
              STD_METHOD Terminate, :ptr IInternetProtocolRoot, :DWORD
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
            IInternetProtocolVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetProtocolVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IInternetProtocol, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IInternetProtocol
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IInternetProtocol
              DECLSPEC_XFGVIRT(IInternetProtocolRoot, Start)
              STD_METHOD Start, :ptr IInternetProtocol, :LPCWSTR, :ptr IInternetProtocolSink, :ptr IInternetBindInfo, :DWORD, :HANDLE_PTR
              DECLSPEC_XFGVIRT(IInternetProtocolRoot, Continue)
              STD_METHOD Continue, :ptr IInternetProtocol, :ptr PROTOCOLDATA
              DECLSPEC_XFGVIRT(IInternetProtocolRoot, Abort)
              STD_METHOD Abort, :ptr IInternetProtocol, :HRESULT, :DWORD
              DECLSPEC_XFGVIRT(IInternetProtocolRoot, Terminate)
              STD_METHOD Terminate, :ptr IInternetProtocol, :DWORD
              DECLSPEC_XFGVIRT(IInternetProtocolRoot, Suspend)
              STD_METHOD Suspend, :ptr IInternetProtocol
              DECLSPEC_XFGVIRT(IInternetProtocolRoot, Resume)
              STD_METHOD Resume, :ptr IInternetProtocol
              DECLSPEC_XFGVIRT(IInternetProtocol, Read)
              STD_METHOD Read, :ptr IInternetProtocol, :ptr, :ULONG, :ptr ULONG
              DECLSPEC_XFGVIRT(IInternetProtocol, Seek)
              STD_METHOD Seek, :ptr IInternetProtocol, :LARGE_INTEGER, :DWORD, :ptr ULARGE_INTEGER
              DECLSPEC_XFGVIRT(IInternetProtocol, LockRequest)
              STD_METHOD LockRequest, :ptr IInternetProtocol, :DWORD
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
              IInternetProtocolExVtbl struct
                BEGIN_INTERFACE
                ??Interface equ <IInternetProtocolExVtbl>
                DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
                STD_METHOD QueryInterface, :ptr IInternetProtocolEx, :REFIID, :ptr ptr
                DECLSPEC_XFGVIRT(IUnknown, AddRef)
                STD_METHOD AddRef, :ptr IInternetProtocolEx
                DECLSPEC_XFGVIRT(IUnknown, Release)
                STD_METHOD Release, :ptr IInternetProtocolEx
                DECLSPEC_XFGVIRT(IInternetProtocolRoot, Start)
                STD_METHOD Start, :ptr IInternetProtocolEx, :LPCWSTR, :ptr IInternetProtocolSink, :ptr IInternetBindInfo, :DWORD, :HANDLE_PTR
                DECLSPEC_XFGVIRT(IInternetProtocolRoot, Continue)
                STD_METHOD Continue, :ptr IInternetProtocolEx, :ptr PROTOCOLDATA
                DECLSPEC_XFGVIRT(IInternetProtocolRoot, Abort)
                STD_METHOD Abort, :ptr IInternetProtocolEx, :HRESULT, :DWORD
                DECLSPEC_XFGVIRT(IInternetProtocolRoot, Terminate)
                STD_METHOD Terminate, :ptr IInternetProtocolEx, :DWORD
                DECLSPEC_XFGVIRT(IInternetProtocolRoot, Suspend)
                STD_METHOD Suspend, :ptr IInternetProtocolEx
                DECLSPEC_XFGVIRT(IInternetProtocolRoot, Resume)
                STD_METHOD Resume, :ptr IInternetProtocolEx
                DECLSPEC_XFGVIRT(IInternetProtocol, Read)
                STD_METHOD Read, :ptr IInternetProtocolEx, :ptr, :ULONG, :ptr ULONG
                DECLSPEC_XFGVIRT(IInternetProtocol, Seek)
                STD_METHOD Seek, :ptr IInternetProtocolEx, :LARGE_INTEGER, :DWORD, :ptr ULARGE_INTEGER
                DECLSPEC_XFGVIRT(IInternetProtocol, LockRequest)
                STD_METHOD LockRequest, :ptr IInternetProtocolEx, :DWORD
                DECLSPEC_XFGVIRT(IInternetProtocol, UnlockRequest)
                STD_METHOD UnlockRequest, :ptr IInternetProtocolEx
                DECLSPEC_XFGVIRT(IInternetProtocolEx, StartEx)
                STD_METHOD StartEx, :ptr IInternetProtocolEx, :ptr IUri, :ptr IInternetProtocolSink, :ptr IInternetBindInfo, :DWORD, :HANDLE_PTR
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
            IInternetProtocolSinkVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetProtocolSinkVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IInternetProtocolSink, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IInternetProtocolSink
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IInternetProtocolSink
              DECLSPEC_XFGVIRT(IInternetProtocolSink, Switch)
              STD_METHOD Switch, :ptr IInternetProtocolSink, :ptr PROTOCOLDATA
              DECLSPEC_XFGVIRT(IInternetProtocolSink, ReportProgress)
              STD_METHOD ReportProgress, :ptr IInternetProtocolSink, :ULONG, :LPCWSTR
              DECLSPEC_XFGVIRT(IInternetProtocolSink, ReportData)
              STD_METHOD ReportData, :ptr IInternetProtocolSink, :DWORD, :ULONG, :ULONG
              DECLSPEC_XFGVIRT(IInternetProtocolSink, ReportResult)
              STD_METHOD ReportResult, :ptr IInternetProtocolSink, :HRESULT, :DWORD, :LPCWSTR
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
            IInternetProtocolSinkStackableVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetProtocolSinkStackableVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IInternetProtocolSinkStackable, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IInternetProtocolSinkStackable
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IInternetProtocolSinkStackable
              DECLSPEC_XFGVIRT(IInternetProtocolSinkStackable, SwitchSink)
              STD_METHOD SwitchSink, :ptr IInternetProtocolSinkStackable, :ptr IInternetProtocolSink
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
            IInternetSessionVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetSessionVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IInternetSession, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IInternetSession
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IInternetSession
              DECLSPEC_XFGVIRT(IInternetSession, RegisterNameSpace)
              STD_METHOD RegisterNameSpace, :ptr IInternetSession, :ptr IClassFactory, :REFCLSID, :LPCWSTR, :ULONG, :ptr LPCWSTR, :DWORD
              DECLSPEC_XFGVIRT(IInternetSession, UnregisterNameSpace)
              STD_METHOD UnregisterNameSpace, :ptr IInternetSession, :ptr IClassFactory, :LPCWSTR
              DECLSPEC_XFGVIRT(IInternetSession, RegisterMimeFilter)
              STD_METHOD RegisterMimeFilter, :ptr IInternetSession, :ptr IClassFactory, :REFCLSID, :LPCWSTR
              DECLSPEC_XFGVIRT(IInternetSession, UnregisterMimeFilter)
              STD_METHOD UnregisterMimeFilter, :ptr IInternetSession, :ptr IClassFactory, :LPCWSTR
              DECLSPEC_XFGVIRT(IInternetSession, CreateBinding)
              STD_METHOD CreateBinding, :ptr IInternetSession, :LPBC, :LPCWSTR, :ptr IUnknown, :ptr ptr IUnknown, :ptr ptr IInternetProtocol, :DWORD
              DECLSPEC_XFGVIRT(IInternetSession, SetSessionOption)
              STD_METHOD SetSessionOption, :ptr IInternetSession, :DWORD, :LPVOID, :DWORD, :DWORD
              DECLSPEC_XFGVIRT(IInternetSession, GetSessionOption)
              STD_METHOD GetSessionOption, :ptr IInternetSession, :DWORD, :LPVOID, :ptr DWORD, :DWORD
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
            IInternetThreadSwitchVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetThreadSwitchVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
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
            IInternetPriorityVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetPriorityVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IInternetPriority, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IInternetPriority
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IInternetPriority
              DECLSPEC_XFGVIRT(IInternetPriority, SetPriority)
              STD_METHOD SetPriority, :ptr IInternetPriority, :LONG
              DECLSPEC_XFGVIRT(IInternetPriority, GetPriority)
              STD_METHOD GetPriority, :ptr IInternetPriority, :ptr LONG
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
            IInternetProtocolInfoVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetProtocolInfoVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IInternetProtocolInfo, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IInternetProtocolInfo
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IInternetProtocolInfo
              DECLSPEC_XFGVIRT(IInternetProtocolInfo, ParseUrl)
              STD_METHOD ParseUrl, :ptr IInternetProtocolInfo, :LPCWSTR, :PARSEACTION, :DWORD, :LPWSTR, :DWORD, :ptr DWORD, :DWORD
              DECLSPEC_XFGVIRT(IInternetProtocolInfo, CombineUrl)
              STD_METHOD CombineUrl, :ptr IInternetProtocolInfo, :LPCWSTR, :LPCWSTR, :DWORD, :LPWSTR, :DWORD, :ptr DWORD, :DWORD
              DECLSPEC_XFGVIRT(IInternetProtocolInfo, CompareUrl)
              STD_METHOD CompareUrl, :ptr IInternetProtocolInfo, :LPCWSTR, :LPCWSTR, :DWORD
              DECLSPEC_XFGVIRT(IInternetProtocolInfo, QueryInfo)
              STD_METHOD QueryInfo, :ptr IInternetProtocolInfo, :LPCWSTR, :QUERYOPTION, :DWORD, :LPVOID, :DWORD, :ptr DWORD, :DWORD
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
          IInternetSecurityMgrSiteVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IInternetSecurityMgrSiteVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IInternetSecurityMgrSite, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IInternetSecurityMgrSite
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IInternetSecurityMgrSite
            DECLSPEC_XFGVIRT(IInternetSecurityMgrSite, GetWindow)
            STD_METHOD GetWindow, :ptr IInternetSecurityMgrSite, :ptr HWND
            DECLSPEC_XFGVIRT(IInternetSecurityMgrSite, EnableModeless)
            STD_METHOD EnableModeless, :ptr IInternetSecurityMgrSite, :BOOL
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
          IInternetSecurityManagerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IInternetSecurityManagerVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IInternetSecurityManager, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IInternetSecurityManager
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IInternetSecurityManager
            DECLSPEC_XFGVIRT(IInternetSecurityManager, SetSecuritySite)
            STD_METHOD SetSecuritySite, :ptr IInternetSecurityManager, :ptr IInternetSecurityMgrSite
            DECLSPEC_XFGVIRT(IInternetSecurityManager, GetSecuritySite)
            STD_METHOD GetSecuritySite, :ptr IInternetSecurityManager, :ptr ptr IInternetSecurityMgrSite
            DECLSPEC_XFGVIRT(IInternetSecurityManager, MapUrlToZone)
            STD_METHOD MapUrlToZone, :ptr IInternetSecurityManager, :LPCWSTR, :ptr DWORD, :DWORD
            DECLSPEC_XFGVIRT(IInternetSecurityManager, GetSecurityId)
            STD_METHOD GetSecurityId, :ptr IInternetSecurityManager, :LPCWSTR, :ptr BYTE, :ptr DWORD, :DWORD_PTR
            DECLSPEC_XFGVIRT(IInternetSecurityManager, ProcessUrlAction)
            STD_METHOD ProcessUrlAction, :ptr IInternetSecurityManager, :LPCWSTR, :DWORD, :ptr BYTE, :DWORD, :ptr BYTE, :DWORD, :DWORD, :DWORD
            DECLSPEC_XFGVIRT(IInternetSecurityManager, QueryCustomPolicy)
            STD_METHOD QueryCustomPolicy, :ptr IInternetSecurityManager, :LPCWSTR, :REFGUID, :ptr ptr BYTE, :ptr DWORD, :ptr BYTE, :DWORD, :DWORD
            DECLSPEC_XFGVIRT(IInternetSecurityManager, SetZoneMapping)
            STD_METHOD SetZoneMapping, :ptr IInternetSecurityManager, :DWORD, :LPCWSTR, :DWORD
            DECLSPEC_XFGVIRT(IInternetSecurityManager, GetZoneMappings)
            STD_METHOD GetZoneMappings, :ptr IInternetSecurityManager, :DWORD, :ptr ptr IEnumString, :DWORD
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
            IInternetSecurityManagerExVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetSecurityManagerExVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IInternetSecurityManagerEx, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IInternetSecurityManagerEx
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IInternetSecurityManagerEx
              DECLSPEC_XFGVIRT(IInternetSecurityManager, SetSecuritySite)
              STD_METHOD SetSecuritySite, :ptr IInternetSecurityManagerEx, :ptr IInternetSecurityMgrSite
              DECLSPEC_XFGVIRT(IInternetSecurityManager, GetSecuritySite)
              STD_METHOD GetSecuritySite, :ptr IInternetSecurityManagerEx, :ptr ptr IInternetSecurityMgrSite
              DECLSPEC_XFGVIRT(IInternetSecurityManager, MapUrlToZone)
              STD_METHOD MapUrlToZone, :ptr IInternetSecurityManagerEx, :LPCWSTR, :ptr DWORD, :DWORD
              DECLSPEC_XFGVIRT(IInternetSecurityManager, GetSecurityId)
              STD_METHOD GetSecurityId, :ptr IInternetSecurityManagerEx, :LPCWSTR, :ptr BYTE, :ptr DWORD, :DWORD_PTR
              DECLSPEC_XFGVIRT(IInternetSecurityManager, ProcessUrlAction)
              STD_METHOD ProcessUrlAction, :ptr IInternetSecurityManagerEx, :LPCWSTR, :DWORD, :ptr BYTE, :DWORD, :ptr BYTE, :DWORD, :DWORD, :DWORD
              DECLSPEC_XFGVIRT(IInternetSecurityManager, QueryCustomPolicy)
              STD_METHOD QueryCustomPolicy, :ptr IInternetSecurityManagerEx, :LPCWSTR, :REFGUID, :ptr ptr BYTE, :ptr DWORD, :ptr BYTE, :DWORD, :DWORD
              DECLSPEC_XFGVIRT(IInternetSecurityManager, SetZoneMapping)
              STD_METHOD SetZoneMapping, :ptr IInternetSecurityManagerEx, :DWORD, :LPCWSTR, :DWORD
              DECLSPEC_XFGVIRT(IInternetSecurityManager, GetZoneMappings)
              STD_METHOD GetZoneMappings, :ptr IInternetSecurityManagerEx, :DWORD, :ptr ptr IEnumString, :DWORD
              DECLSPEC_XFGVIRT(IInternetSecurityManagerEx, ProcessUrlActionEx)
              STD_METHOD ProcessUrlActionEx, :ptr IInternetSecurityManagerEx, :LPCWSTR, :DWORD, :ptr BYTE, :DWORD, :ptr BYTE, :DWORD, :DWORD, :DWORD, :ptr DWORD
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
            IInternetSecurityManagerEx2Vtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetSecurityManagerEx2Vtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IInternetSecurityManagerEx2, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IInternetSecurityManagerEx2
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IInternetSecurityManagerEx2
              DECLSPEC_XFGVIRT(IInternetSecurityManager, SetSecuritySite)
              STD_METHOD SetSecuritySite, :ptr IInternetSecurityManagerEx2, :ptr IInternetSecurityMgrSite
              DECLSPEC_XFGVIRT(IInternetSecurityManager, GetSecuritySite)
              STD_METHOD GetSecuritySite, :ptr IInternetSecurityManagerEx2, :ptr ptr IInternetSecurityMgrSite
              DECLSPEC_XFGVIRT(IInternetSecurityManager, MapUrlToZone)
              STD_METHOD MapUrlToZone, :ptr IInternetSecurityManagerEx2, :LPCWSTR, :ptr DWORD, :DWORD
              DECLSPEC_XFGVIRT(IInternetSecurityManager, GetSecurityId)
              STD_METHOD GetSecurityId, :ptr IInternetSecurityManagerEx2, :LPCWSTR, :ptr BYTE, :ptr DWORD, :DWORD_PTR
              DECLSPEC_XFGVIRT(IInternetSecurityManager, ProcessUrlAction)
              STD_METHOD ProcessUrlAction, :ptr IInternetSecurityManagerEx2, :LPCWSTR, :DWORD, :ptr BYTE, :DWORD, :ptr BYTE, :DWORD, :DWORD, :DWORD
              DECLSPEC_XFGVIRT(IInternetSecurityManager, QueryCustomPolicy)
              STD_METHOD QueryCustomPolicy, :ptr IInternetSecurityManagerEx2, :LPCWSTR, :REFGUID, :ptr ptr BYTE, :ptr DWORD, :ptr BYTE, :DWORD, :DWORD
              DECLSPEC_XFGVIRT(IInternetSecurityManager, SetZoneMapping)
              STD_METHOD SetZoneMapping, :ptr IInternetSecurityManagerEx2, :DWORD, :LPCWSTR, :DWORD
              DECLSPEC_XFGVIRT(IInternetSecurityManager, GetZoneMappings)
              STD_METHOD GetZoneMappings, :ptr IInternetSecurityManagerEx2, :DWORD, :ptr ptr IEnumString, :DWORD
              DECLSPEC_XFGVIRT(IInternetSecurityManagerEx, ProcessUrlActionEx)
              STD_METHOD ProcessUrlActionEx, :ptr IInternetSecurityManagerEx2, :LPCWSTR, :DWORD, :ptr BYTE, :DWORD, :ptr BYTE, :DWORD, :DWORD, :DWORD, :ptr DWORD
              DECLSPEC_XFGVIRT(IInternetSecurityManagerEx2, MapUrlToZoneEx2)
              STD_METHOD MapUrlToZoneEx2, :ptr IInternetSecurityManagerEx2, :ptr IUri, :ptr DWORD, :DWORD, :ptr LPWSTR, :ptr DWORD
              DECLSPEC_XFGVIRT(IInternetSecurityManagerEx2, ProcessUrlActionEx2)
              STD_METHOD ProcessUrlActionEx2, :ptr IInternetSecurityManagerEx2, :ptr IUri, :DWORD, :ptr BYTE, :DWORD, :ptr BYTE, :DWORD, :DWORD, :DWORD_PTR, :ptr DWORD
              DECLSPEC_XFGVIRT(IInternetSecurityManagerEx2, GetSecurityIdEx2)
              STD_METHOD GetSecurityIdEx2, :ptr IInternetSecurityManagerEx2, :ptr IUri, :ptr BYTE, :ptr DWORD, :DWORD_PTR
              DECLSPEC_XFGVIRT(IInternetSecurityManagerEx2, QueryCustomPolicyEx2)
              STD_METHOD QueryCustomPolicyEx2, :ptr IInternetSecurityManagerEx2, :ptr IUri, :REFGUID, :ptr ptr BYTE, :ptr DWORD, :ptr BYTE, :DWORD, :DWORD_PTR
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
          IZoneIdentifierVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IZoneIdentifierVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IZoneIdentifier, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IZoneIdentifier
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IZoneIdentifier
            DECLSPEC_XFGVIRT(IZoneIdentifier, GetId)
            STD_METHOD GetId, :ptr IZoneIdentifier, :ptr DWORD
            DECLSPEC_XFGVIRT(IZoneIdentifier, SetId)
            STD_METHOD SetId, :ptr IZoneIdentifier, :DWORD
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
          IZoneIdentifier2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IZoneIdentifier2Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IZoneIdentifier2, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IZoneIdentifier2
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IZoneIdentifier2
            DECLSPEC_XFGVIRT(IZoneIdentifier, GetId)
            STD_METHOD GetId, :ptr IZoneIdentifier2, :ptr DWORD
            DECLSPEC_XFGVIRT(IZoneIdentifier, SetId)
            STD_METHOD SetId, :ptr IZoneIdentifier2, :DWORD
            DECLSPEC_XFGVIRT(IZoneIdentifier, Remove)
            STD_METHOD Remove, :ptr IZoneIdentifier2
            DECLSPEC_XFGVIRT(IZoneIdentifier2, GetLastWriterPackageFamilyName)
            STD_METHOD GetLastWriterPackageFamilyName, :ptr IZoneIdentifier2, :ptr LPWSTR
            DECLSPEC_XFGVIRT(IZoneIdentifier2, SetLastWriterPackageFamilyName)
            STD_METHOD SetLastWriterPackageFamilyName, :ptr IZoneIdentifier2, :LPCWSTR
            DECLSPEC_XFGVIRT(IZoneIdentifier2, RemoveLastWriterPackageFamilyName)
            STD_METHOD RemoveLastWriterPackageFamilyName, :ptr IZoneIdentifier2
            DECLSPEC_XFGVIRT(IZoneIdentifier2, GetAppZoneId)
            STD_METHOD GetAppZoneId, :ptr IZoneIdentifier2, :ptr DWORD
            DECLSPEC_XFGVIRT(IZoneIdentifier2, SetAppZoneId)
            STD_METHOD SetAppZoneId, :ptr IZoneIdentifier2, :DWORD
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
          IInternetHostSecurityManagerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IInternetHostSecurityManagerVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IInternetHostSecurityManager, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IInternetHostSecurityManager
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IInternetHostSecurityManager
            DECLSPEC_XFGVIRT(IInternetHostSecurityManager, GetSecurityId)
            STD_METHOD GetSecurityId, :ptr IInternetHostSecurityManager, :ptr BYTE, :ptr DWORD, :DWORD_PTR
            DECLSPEC_XFGVIRT(IInternetHostSecurityManager, ProcessUrlAction)
            STD_METHOD ProcessUrlAction, :ptr IInternetHostSecurityManager, :DWORD, :ptr BYTE, :DWORD, :ptr BYTE, :DWORD, :DWORD, :DWORD
            DECLSPEC_XFGVIRT(IInternetHostSecurityManager, QueryCustomPolicy)
            STD_METHOD QueryCustomPolicy, :ptr IInternetHostSecurityManager, :REFGUID, :ptr ptr BYTE, :ptr DWORD, :ptr BYTE, :DWORD, :DWORD
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
    URLACTION_ALLOW_JSCRIPT_IE equ 0000140Dh
    URLACTION_SCRIPT_CURR_MAX equ 0000140Dh
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
          IInternetZoneManagerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IInternetZoneManagerVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IInternetZoneManager, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IInternetZoneManager
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IInternetZoneManager
            DECLSPEC_XFGVIRT(IInternetZoneManager, GetZoneAttributes)
            STD_METHOD GetZoneAttributes, :ptr IInternetZoneManager, :DWORD, :ptr ZONEATTRIBUTES
            DECLSPEC_XFGVIRT(IInternetZoneManager, SetZoneAttributes)
            STD_METHOD SetZoneAttributes, :ptr IInternetZoneManager, :DWORD, :ptr ZONEATTRIBUTES
            DECLSPEC_XFGVIRT(IInternetZoneManager, GetZoneCustomPolicy)
            STD_METHOD GetZoneCustomPolicy, :ptr IInternetZoneManager, :DWORD, :REFGUID, :ptr ptr BYTE, :ptr DWORD, :URLZONEREG
            DECLSPEC_XFGVIRT(IInternetZoneManager, SetZoneCustomPolicy)
            STD_METHOD SetZoneCustomPolicy, :ptr IInternetZoneManager, :DWORD, :REFGUID, :ptr BYTE, :DWORD, :URLZONEREG
            DECLSPEC_XFGVIRT(IInternetZoneManager, GetZoneActionPolicy)
            STD_METHOD GetZoneActionPolicy, :ptr IInternetZoneManager, :DWORD, :DWORD, :ptr BYTE, :DWORD, :URLZONEREG
            DECLSPEC_XFGVIRT(IInternetZoneManager, SetZoneActionPolicy)
            STD_METHOD SetZoneActionPolicy, :ptr IInternetZoneManager, :DWORD, :DWORD, :ptr BYTE, :DWORD, :URLZONEREG
            DECLSPEC_XFGVIRT(IInternetZoneManager, PromptAction)
            STD_METHOD PromptAction, :ptr IInternetZoneManager, :DWORD, :HWND, :LPCWSTR, :LPCWSTR, :DWORD
            DECLSPEC_XFGVIRT(IInternetZoneManager, LogAction)
            STD_METHOD LogAction, :ptr IInternetZoneManager, :DWORD, :LPCWSTR, :LPCWSTR, :DWORD
            DECLSPEC_XFGVIRT(IInternetZoneManager, CreateZoneEnumerator)
            STD_METHOD CreateZoneEnumerator, :ptr IInternetZoneManager, :ptr DWORD, :ptr DWORD, :DWORD
            DECLSPEC_XFGVIRT(IInternetZoneManager, GetZoneAt)
            STD_METHOD GetZoneAt, :ptr IInternetZoneManager, :DWORD, :DWORD, :ptr DWORD
            DECLSPEC_XFGVIRT(IInternetZoneManager, DestroyZoneEnumerator)
            STD_METHOD DestroyZoneEnumerator, :ptr IInternetZoneManager, :DWORD
            DECLSPEC_XFGVIRT(IInternetZoneManager, CopyTemplatePoliciesToZone)
            STD_METHOD CopyTemplatePoliciesToZone, :ptr IInternetZoneManager, :DWORD, :DWORD, :DWORD
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
            IInternetZoneManagerExVtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetZoneManagerExVtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IInternetZoneManagerEx, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IInternetZoneManagerEx
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IInternetZoneManagerEx
              DECLSPEC_XFGVIRT(IInternetZoneManager, GetZoneAttributes)
              STD_METHOD GetZoneAttributes, :ptr IInternetZoneManagerEx, :DWORD, :ptr ZONEATTRIBUTES
              DECLSPEC_XFGVIRT(IInternetZoneManager, SetZoneAttributes)
              STD_METHOD SetZoneAttributes, :ptr IInternetZoneManagerEx, :DWORD, :ptr ZONEATTRIBUTES
              DECLSPEC_XFGVIRT(IInternetZoneManager, GetZoneCustomPolicy)
              STD_METHOD GetZoneCustomPolicy, :ptr IInternetZoneManagerEx, :DWORD, :REFGUID, :ptr ptr BYTE, :ptr DWORD, :URLZONEREG
              DECLSPEC_XFGVIRT(IInternetZoneManager, SetZoneCustomPolicy)
              STD_METHOD SetZoneCustomPolicy, :ptr IInternetZoneManagerEx, :DWORD, :REFGUID, :ptr BYTE, :DWORD, :URLZONEREG
              DECLSPEC_XFGVIRT(IInternetZoneManager, GetZoneActionPolicy)
              STD_METHOD GetZoneActionPolicy, :ptr IInternetZoneManagerEx, :DWORD, :DWORD, :ptr BYTE, :DWORD, :URLZONEREG
              DECLSPEC_XFGVIRT(IInternetZoneManager, SetZoneActionPolicy)
              STD_METHOD SetZoneActionPolicy, :ptr IInternetZoneManagerEx, :DWORD, :DWORD, :ptr BYTE, :DWORD, :URLZONEREG
              DECLSPEC_XFGVIRT(IInternetZoneManager, PromptAction)
              STD_METHOD PromptAction, :ptr IInternetZoneManagerEx, :DWORD, :HWND, :LPCWSTR, :LPCWSTR, :DWORD
              DECLSPEC_XFGVIRT(IInternetZoneManager, LogAction)
              STD_METHOD LogAction, :ptr IInternetZoneManagerEx, :DWORD, :LPCWSTR, :LPCWSTR, :DWORD
              DECLSPEC_XFGVIRT(IInternetZoneManager, CreateZoneEnumerator)
              STD_METHOD CreateZoneEnumerator, :ptr IInternetZoneManagerEx, :ptr DWORD, :ptr DWORD, :DWORD
              DECLSPEC_XFGVIRT(IInternetZoneManager, GetZoneAt)
              STD_METHOD GetZoneAt, :ptr IInternetZoneManagerEx, :DWORD, :DWORD, :ptr DWORD
              DECLSPEC_XFGVIRT(IInternetZoneManager, DestroyZoneEnumerator)
              STD_METHOD DestroyZoneEnumerator, :ptr IInternetZoneManagerEx, :DWORD
              DECLSPEC_XFGVIRT(IInternetZoneManager, CopyTemplatePoliciesToZone)
              STD_METHOD CopyTemplatePoliciesToZone, :ptr IInternetZoneManagerEx, :DWORD, :DWORD, :DWORD
              DECLSPEC_XFGVIRT(IInternetZoneManagerEx, GetZoneActionPolicyEx)
              STD_METHOD GetZoneActionPolicyEx, :ptr IInternetZoneManagerEx, :DWORD, :DWORD, :ptr BYTE, :DWORD, :URLZONEREG, :DWORD
              DECLSPEC_XFGVIRT(IInternetZoneManagerEx, SetZoneActionPolicyEx)
              STD_METHOD SetZoneActionPolicyEx, :ptr IInternetZoneManagerEx, :DWORD, :DWORD, :ptr BYTE, :DWORD, :URLZONEREG, :DWORD
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
            IInternetZoneManagerEx2Vtbl struct
              BEGIN_INTERFACE
              ??Interface equ <IInternetZoneManagerEx2Vtbl>
              DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
              STD_METHOD QueryInterface, :ptr IInternetZoneManagerEx2, :REFIID, :ptr ptr
              DECLSPEC_XFGVIRT(IUnknown, AddRef)
              STD_METHOD AddRef, :ptr IInternetZoneManagerEx2
              DECLSPEC_XFGVIRT(IUnknown, Release)
              STD_METHOD Release, :ptr IInternetZoneManagerEx2
              DECLSPEC_XFGVIRT(IInternetZoneManager, GetZoneAttributes)
              STD_METHOD GetZoneAttributes, :ptr IInternetZoneManagerEx2, :DWORD, :ptr ZONEATTRIBUTES
              DECLSPEC_XFGVIRT(IInternetZoneManager, SetZoneAttributes)
              STD_METHOD SetZoneAttributes, :ptr IInternetZoneManagerEx2, :DWORD, :ptr ZONEATTRIBUTES
              DECLSPEC_XFGVIRT(IInternetZoneManager, GetZoneCustomPolicy)
              STD_METHOD GetZoneCustomPolicy, :ptr IInternetZoneManagerEx2, :DWORD, :REFGUID, :ptr ptr BYTE, :ptr DWORD, :URLZONEREG
              DECLSPEC_XFGVIRT(IInternetZoneManager, SetZoneCustomPolicy)
              STD_METHOD SetZoneCustomPolicy, :ptr IInternetZoneManagerEx2, :DWORD, :REFGUID, :ptr BYTE, :DWORD, :URLZONEREG
              DECLSPEC_XFGVIRT(IInternetZoneManager, GetZoneActionPolicy)
              STD_METHOD GetZoneActionPolicy, :ptr IInternetZoneManagerEx2, :DWORD, :DWORD, :ptr BYTE, :DWORD, :URLZONEREG
              DECLSPEC_XFGVIRT(IInternetZoneManager, SetZoneActionPolicy)
              STD_METHOD SetZoneActionPolicy, :ptr IInternetZoneManagerEx2, :DWORD, :DWORD, :ptr BYTE, :DWORD, :URLZONEREG
              DECLSPEC_XFGVIRT(IInternetZoneManager, PromptAction)
              STD_METHOD PromptAction, :ptr IInternetZoneManagerEx2, :DWORD, :HWND, :LPCWSTR, :LPCWSTR, :DWORD
              DECLSPEC_XFGVIRT(IInternetZoneManager, LogAction)
              STD_METHOD LogAction, :ptr IInternetZoneManagerEx2, :DWORD, :LPCWSTR, :LPCWSTR, :DWORD
              DECLSPEC_XFGVIRT(IInternetZoneManager, CreateZoneEnumerator)
              STD_METHOD CreateZoneEnumerator, :ptr IInternetZoneManagerEx2, :ptr DWORD, :ptr DWORD, :DWORD
              DECLSPEC_XFGVIRT(IInternetZoneManager, GetZoneAt)
              STD_METHOD GetZoneAt, :ptr IInternetZoneManagerEx2, :DWORD, :DWORD, :ptr DWORD
              DECLSPEC_XFGVIRT(IInternetZoneManager, DestroyZoneEnumerator)
              STD_METHOD DestroyZoneEnumerator, :ptr IInternetZoneManagerEx2, :DWORD
              DECLSPEC_XFGVIRT(IInternetZoneManager, CopyTemplatePoliciesToZone)
              STD_METHOD CopyTemplatePoliciesToZone, :ptr IInternetZoneManagerEx2, :DWORD, :DWORD, :DWORD
              DECLSPEC_XFGVIRT(IInternetZoneManagerEx, GetZoneActionPolicyEx)
              STD_METHOD GetZoneActionPolicyEx, :ptr IInternetZoneManagerEx2, :DWORD, :DWORD, :ptr BYTE, :DWORD, :URLZONEREG, :DWORD
              DECLSPEC_XFGVIRT(IInternetZoneManagerEx, SetZoneActionPolicyEx)
              STD_METHOD SetZoneActionPolicyEx, :ptr IInternetZoneManagerEx2, :DWORD, :DWORD, :ptr BYTE, :DWORD, :URLZONEREG, :DWORD
              DECLSPEC_XFGVIRT(IInternetZoneManagerEx2, GetZoneAttributesEx)
              STD_METHOD GetZoneAttributesEx, :ptr IInternetZoneManagerEx2, :DWORD, :ptr ZONEATTRIBUTES, :DWORD
              DECLSPEC_XFGVIRT(IInternetZoneManagerEx2, GetZoneSecurityState)
              STD_METHOD GetZoneSecurityState, :ptr IInternetZoneManagerEx2, :DWORD, :BOOL, :LPDWORD, :ptr BOOL
              DECLSPEC_XFGVIRT(IInternetZoneManagerEx2, GetIESecurityState)
              STD_METHOD GetIESecurityState, :ptr IInternetZoneManagerEx2, :BOOL, :LPDWORD, :ptr BOOL, :BOOL
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
          ISoftDistExtVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISoftDistExtVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISoftDistExt, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISoftDistExt
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISoftDistExt
            DECLSPEC_XFGVIRT(ISoftDistExt, ProcessSoftDist)
            STD_METHOD ProcessSoftDist, :ptr ISoftDistExt, :LPCWSTR, :ptr IXMLElement, :LPSOFTDISTINFO
            DECLSPEC_XFGVIRT(ISoftDistExt, GetFirstCodeBase)
            STD_METHOD GetFirstCodeBase, :ptr ISoftDistExt, :ptr LPWSTR, :LPDWORD
            DECLSPEC_XFGVIRT(ISoftDistExt, GetNextCodeBase)
            STD_METHOD GetNextCodeBase, :ptr ISoftDistExt, :ptr LPWSTR, :LPDWORD
            DECLSPEC_XFGVIRT(ISoftDistExt, AsyncInstallDistributionUnit)
            STD_METHOD AsyncInstallDistributionUnit, :ptr ISoftDistExt, :ptr IBindCtx, :LPVOID, :DWORD, :LPCODEBASEHOLD
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
          ICatalogFileInfoVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ICatalogFileInfoVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ICatalogFileInfo, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ICatalogFileInfo
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ICatalogFileInfo
            DECLSPEC_XFGVIRT(ICatalogFileInfo, GetCatalogFile)
            STD_METHOD GetCatalogFile, :ptr ICatalogFileInfo, :ptr LPSTR
            DECLSPEC_XFGVIRT(ICatalogFileInfo, GetJavaTrust)
            STD_METHOD GetJavaTrust, :ptr ICatalogFileInfo, :ptr ptr
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
          IDataFilterVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDataFilterVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDataFilter, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDataFilter
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDataFilter
            DECLSPEC_XFGVIRT(IDataFilter, DoEncode)
            STD_METHOD DoEncode, :ptr IDataFilter, :DWORD, :LONG, :ptr BYTE, :LONG, :ptr BYTE, :LONG, :ptr LONG, :ptr LONG, :DWORD
            DECLSPEC_XFGVIRT(IDataFilter, DoDecode)
            STD_METHOD DoDecode, :ptr IDataFilter, :DWORD, :LONG, :ptr BYTE, :LONG, :ptr BYTE, :LONG, :ptr LONG, :ptr LONG, :DWORD
            DECLSPEC_XFGVIRT(IDataFilter, SetEncodingLevel)
            STD_METHOD SetEncodingLevel, :ptr IDataFilter, :DWORD
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
          IEncodingFilterFactoryVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEncodingFilterFactoryVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IEncodingFilterFactory, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IEncodingFilterFactory
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IEncodingFilterFactory
            DECLSPEC_XFGVIRT(IEncodingFilterFactory, FindBestFilter)
            STD_METHOD FindBestFilter, :ptr IEncodingFilterFactory, :LPCWSTR, :LPCWSTR, :DATAINFO, :ptr ptr IDataFilter
            DECLSPEC_XFGVIRT(IEncodingFilterFactory, GetDefaultFilter)
            STD_METHOD GetDefaultFilter, :ptr IEncodingFilterFactory, :LPCWSTR, :LPCWSTR, :ptr ptr IDataFilter
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
          IWrappedProtocolVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IWrappedProtocolVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IWrappedProtocol, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IWrappedProtocol
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IWrappedProtocol
            DECLSPEC_XFGVIRT(IWrappedProtocol, GetWrapperCode)
            STD_METHOD GetWrapperCode, :ptr IWrappedProtocol, :ptr LONG, :DWORD_PTR
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
          IGetBindHandleVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IGetBindHandleVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IGetBindHandle, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IGetBindHandle
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IGetBindHandle
            DECLSPEC_XFGVIRT(IGetBindHandle, GetBindHandle)
            STD_METHOD GetBindHandle, :ptr IGetBindHandle, :BINDHANDLETYPES, :ptr HANDLE
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
          IBindCallbackRedirectVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IBindCallbackRedirectVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IBindCallbackRedirect, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IBindCallbackRedirect
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IBindCallbackRedirect
            DECLSPEC_XFGVIRT(IBindCallbackRedirect, Redirect)
            STD_METHOD Redirect, :ptr IBindCallbackRedirect, :LPCWSTR, :ptr VARIANT_BOOL
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
          IBindHttpSecurityVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IBindHttpSecurityVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IBindHttpSecurity, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IBindHttpSecurity
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IBindHttpSecurity
            DECLSPEC_XFGVIRT(IBindHttpSecurity, GetIgnoreCertMask)
            STD_METHOD GetIgnoreCertMask, :ptr IBindHttpSecurity, :ptr DWORD
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
