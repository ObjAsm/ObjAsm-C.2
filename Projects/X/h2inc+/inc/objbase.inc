;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\objbase.h
;             Created on (UTC) 06/04/2024 06:15:57
;             Last modified on (UTC) 21/02/2024 18:13:14

include winapifamily.inc
include rpc.inc
include rpcndr.inc
if  not Defined(_OBJBASE_H_)
  _OBJBASE_H_ equ <>
  if _MSC_VER gt 1000
  endif
  include pshpack8.inc
  include combaseapi.inc
  include coml2api.inc
  COINIT typedef SDWORD
  COINIT_APARTMENTTHREADED equ 2h
  if (_WIN32_WINNT ge 0400h) or Defined(_WIN32_DCOM)
    COINIT_MULTITHREADED equ COINITBASE_MULTITHREADED
    COINIT_DISABLE_OLE1DDE equ 4h
    COINIT_SPEED_OVER_MEMORY equ 8h
  endif
  tagCOINIT typedef COINIT

  MARSHALINTERFACE_MIN equ 500
  ASYNC_MODE_COMPATIBILITY equ 00000001h
  ASYNC_MODE_DEFAULT equ 00000000h
  STGTY_REPEAT equ 00000100h
  STG_TOEND equ 0FFFFFFFFh
  STG_LAYOUT_SEQUENTIAL equ 00000000h
  STG_LAYOUT_INTERLEAVED equ 00000001h
  include objidl.inc
  ifdef _OLE32_
    ifdef _OLE32PRIV_
      wIsEqualGUID proto WIN_STD_CALL_CONV :REFGUID, :REFGUID
      IsEqualGUID macro rguid1, rguid2
        exitm <wIsEqualGUID (rguid1, rguid2)>
      endm
    else
      __INLINE_ISEQUAL_GUID equ <>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    @DefProto DllImport, CoBuildVersion, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, CoInitialize, WIN_STD_CALL_CONV,, <:LPVOID>, 4
    COM_SUPPORT_MALLOC_SPIES equ <>
    @DefProto DllImport, CoRegisterMallocSpy, WIN_STD_CALL_CONV,, <:LPMALLOCSPY>, 4
    @DefProto DllImport, CoRevokeMallocSpy, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, CoCreateStandardMalloc, WIN_STD_CALL_CONV,, <:DWORD, :ptr ptr IMalloc>, 8
    if (_WIN32_WINNT ge 0501h)
      @DefProto DllImport, CoRegisterInitializeSpy, WIN_STD_CALL_CONV,, <:ptr IInitializeSpy, :ptr ULARGE_INTEGER>, 8
      @DefProto DllImport, CoRevokeInitializeSpy, WIN_STD_CALL_CONV,, <:ULARGE_INTEGER>, 4
      COMSD typedef SDWORD
      SD_LAUNCHPERMISSIONS equ 0
      SD_ACCESSPERMISSIONS equ 1
      SD_LAUNCHRESTRICTIONS equ 2
      SD_ACCESSRESTRICTIONS equ 3
      tagCOMSD typedef COMSD

      @DefProto DllImport, CoGetSystemSecurityPermissions, WIN_STD_CALL_CONV,, <:COMSD, :ptr PSECURITY_DESCRIPTOR>, 8
    endif
    @DefProto DllImport, CoLoadLibrary, WIN_STD_CALL_CONV,, <:LPOLESTR, :BOOL>, 8
    @DefProto DllImport, CoFreeLibrary, WIN_STD_CALL_CONV,, <:HINSTANCE>, 4
    @DefProto DllImport, CoFreeAllLibraries, WIN_STD_CALL_CONV,, <>, 0
    if (_WIN32_WINNT ge 0400h) or Defined(_WIN32_DCOM)
      @DefProto DllImport, CoGetInstanceFromFile, WIN_STD_CALL_CONV,, <:ptr COSERVERINFO, :ptr CLSID, :ptr IUnknown, :DWORD, :DWORD, :ptr OLECHAR, :DWORD, :ptr MULTI_QI>, 32
      @DefProto DllImport, CoGetInstanceFromIStorage, WIN_STD_CALL_CONV,, <:ptr COSERVERINFO, :ptr CLSID, :ptr IUnknown, :DWORD, :ptr IStorage, :DWORD, :ptr MULTI_QI>, 28
    endif
    if (_WIN32_WINNT ge 0500h) or Defined(_WIN32_DCOM)
      @DefProto DllImport, CoAllowSetForegroundWindow, WIN_STD_CALL_CONV,, <:ptr IUnknown, :LPVOID>, 8
      @DefProto DllImport, DcomChannelSetHResult, WIN_STD_CALL_CONV,, <:LPVOID, :ptr ULONG, :HRESULT>, 12
    endif
    @DefProto DllImport, CoIsOle1Class, WIN_STD_CALL_CONV,, <:REFCLSID>, 4
    @DefProto DllImport, CLSIDFromProgIDEx, WIN_STD_CALL_CONV,, <:LPCOLESTR, :LPCLSID>, 8
    @DefProto DllImport, CoFileTimeToDosDateTime, WIN_STD_CALL_CONV,, <:ptr FILETIME, :LPWORD, :LPWORD>, 12
    @DefProto DllImport, CoDosDateTimeToFileTime, WIN_STD_CALL_CONV,, <:WORD, :WORD, :ptr FILETIME>, 12
    @DefProto DllImport, CoFileTimeNow, WIN_STD_CALL_CONV,, <:ptr FILETIME>, 4
    @DefProto DllImport, CoRegisterMessageFilter, WIN_STD_CALL_CONV,, <:LPMESSAGEFILTER, :ptr LPMESSAGEFILTER>, 8
    if (_WIN32_WINNT ge 0400h) or Defined(_WIN32_DCOM)
      @DefProto DllImport, CoRegisterChannelHook, WIN_STD_CALL_CONV,, <:REFGUID, :ptr IChannelHook>, 8
    endif
    @DefProto DllImport, CoTreatAsClass, WIN_STD_CALL_CONV,, <:REFCLSID, :REFCLSID>, 8
    @DefProto DllImport, CreateDataAdviseHolder, WIN_STD_CALL_CONV,, <:ptr LPDATAADVISEHOLDER>, 4
    @DefProto DllImport, CreateDataCache, WIN_STD_CALL_CONV,, <:LPUNKNOWN, :REFCLSID, :REFIID, :ptr LPVOID>, 16
    @DefProto DllImport, StgOpenAsyncDocfileOnIFillLockBytes, WIN_STD_CALL_CONV,, <:ptr IFillLockBytes, :DWORD, :DWORD, :ptr ptr IStorage>, 16
    @DefProto DllImport, StgGetIFillLockBytesOnILockBytes, WIN_STD_CALL_CONV,, <:ptr ILockBytes, :ptr ptr IFillLockBytes>, 8
    @DefProto DllImport, StgGetIFillLockBytesOnFile, WIN_STD_CALL_CONV,, <:ptr OLECHAR, :ptr ptr IFillLockBytes>, 8
    @DefProto DllImport, StgOpenLayoutDocfile, WIN_STD_CALL_CONV,, <:ptr OLECHAR, :DWORD, :DWORD, :ptr ptr IStorage>, 16
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    @DefProto DllImport, CoInstall, WIN_STD_CALL_CONV,, <:ptr IBindCtx, :DWORD, :ptr uCLSSPEC, :ptr QUERYCONTEXT, :LPWSTR>, 20
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_PC_APP)
    @DefProto DllImport, BindMoniker, WIN_STD_CALL_CONV,, <:LPMONIKER, :DWORD, :REFIID, :ptr LPVOID>, 16
    @DefProto DllImport, CoGetObject, WIN_STD_CALL_CONV,, <:LPCWSTR, :ptr BIND_OPTS, :REFIID, :ptr ptr>, 16
    @DefProto DllImport, MkParseDisplayName, WIN_STD_CALL_CONV,, <:LPBC, :LPCOLESTR, :ptr ULONG, :ptr LPMONIKER>, 16
    @DefProto DllImport, MonikerRelativePathTo, WIN_STD_CALL_CONV,, <:LPMONIKER, :LPMONIKER, :ptr LPMONIKER, :BOOL>, 16
    @DefProto DllImport, MonikerCommonPrefixWith, WIN_STD_CALL_CONV,, <:LPMONIKER, :LPMONIKER, :ptr LPMONIKER>, 12
    @DefProto DllImport, CreateBindCtx, WIN_STD_CALL_CONV,, <:DWORD, :ptr LPBC>, 8
    @DefProto DllImport, CreateGenericComposite, WIN_STD_CALL_CONV,, <:LPMONIKER, :LPMONIKER, :ptr LPMONIKER>, 12
    @DefProto DllImport, GetClassFile, WIN_STD_CALL_CONV,, <:LPCOLESTR, :ptr CLSID>, 8
    @DefProto DllImport, CreateClassMoniker, WIN_STD_CALL_CONV,, <:REFCLSID, :ptr LPMONIKER>, 8
    @DefProto DllImport, CreateFileMoniker, WIN_STD_CALL_CONV,, <:LPCOLESTR, :ptr LPMONIKER>, 8
    @DefProto DllImport, CreateItemMoniker, WIN_STD_CALL_CONV,, <:LPCOLESTR, :LPCOLESTR, :ptr LPMONIKER>, 12
    @DefProto DllImport, CreateAntiMoniker, WIN_STD_CALL_CONV,, <:ptr LPMONIKER>, 4
    @DefProto DllImport, CreatePointerMoniker, WIN_STD_CALL_CONV,, <:LPUNKNOWN, :ptr LPMONIKER>, 8
    @DefProto DllImport, CreateObjrefMoniker, WIN_STD_CALL_CONV,, <:LPUNKNOWN, :ptr LPMONIKER>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    @DefProto DllImport, GetRunningObjectTable, WIN_STD_CALL_CONV,, <:DWORD, :ptr LPRUNNINGOBJECTTABLE>, 8
  endif
  include urlmon.inc
  include propidl.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    @DefProto DllImport, CreateStdProgressIndicator, WIN_STD_CALL_CONV,, <:HWND, :LPCOLESTR, :ptr IBindStatusCallback, :ptr ptr IBindStatusCallback>, 16
  endif
  ifndef RC_INVOKED
    include poppack.inc
  endif
endif
