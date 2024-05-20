;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\objbase.h
;             Created on (UTC) 06/04/2024 06:15:57
;             Last modified on (UTC) 21/02/2024 18:13:14

include winapifamily.inc
;+---------------------------------------------------------------------------
;  Microsoft Windows
;  Copyright (c) Microsoft Corporation. All rights reserved.
;  File:       objbase.h
;  Contents:   Component object model definitions.
;----------------------------------------------------------------------------
include rpc.inc
include rpcndr.inc
if  not Defined(_OBJBASE_H_)
  _OBJBASE_H_ equ <>
  if _MSC_VER gt 1000
  endif
  include pshpack8.inc
  include combaseapi.inc
  include coml2api.inc
  ; COM initialization flags; passed to CoInitialize.
  ; DCOM
  COINIT typedef SDWORD
  ; DCOM
  COINIT_APARTMENTTHREADED equ 2h
  ; Apartment model
  if (_WIN32_WINNT ge 0400h) or Defined(_WIN32_DCOM)
    ; These constants are only valid on Windows NT 4.0
    COINIT_MULTITHREADED equ COINITBASE_MULTITHREADED
    COINIT_DISABLE_OLE1DDE equ 4h
    ; Don't use DDE for Ole1 support.
    COINIT_SPEED_OVER_MEMORY equ 8h
    ; Trade memory for speed.
  endif
  ; DCOM
  tagCOINIT typedef COINIT

  ; interface marshaling definitions
  MARSHALINTERFACE_MIN equ 500; minimum number of bytes for interface marshal

  ;*  flags for internet asynchronous and layout docfile *
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
    ; _OLE32PRIV_
  endif
  ; _OLE32_
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ;****** STD Object API Prototypes *****************************************
    @DefProto DllImport, CoBuildVersion, WIN_STD_CALL_CONV,, <>, 0
    ;* init/uninit *
    @DefProto DllImport, CoInitialize, WIN_STD_CALL_CONV,, <:LPVOID>, 4
    COM_SUPPORT_MALLOC_SPIES equ <>
    @DefProto DllImport, CoRegisterMallocSpy, WIN_STD_CALL_CONV,, <:LPMALLOCSPY>, 4
    @DefProto DllImport, CoRevokeMallocSpy, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, CoCreateStandardMalloc, WIN_STD_CALL_CONV,, <:DWORD, :ptr ptr IMalloc>, 8
    if (_WIN32_WINNT ge 0501h)
      @DefProto DllImport, CoRegisterInitializeSpy, WIN_STD_CALL_CONV,, <:ptr IInitializeSpy, :ptr ULARGE_INTEGER>, 8
      @DefProto DllImport, CoRevokeInitializeSpy, WIN_STD_CALL_CONV,, <:ULARGE_INTEGER>, 4
      ; COM System Security Descriptors (used when the corresponding registry
      ; entries are absent)
      COMSD typedef SDWORD
      SD_LAUNCHPERMISSIONS equ 0
      ; Machine wide launch permissions
      SD_ACCESSPERMISSIONS equ 1
      ; Machine wide acesss permissions
      SD_LAUNCHRESTRICTIONS equ 2
      ; Machine wide launch limits
      SD_ACCESSRESTRICTIONS equ 3
      tagCOMSD typedef COMSD

      ; Machine wide access limits
      @DefProto DllImport, CoGetSystemSecurityPermissions, WIN_STD_CALL_CONV,, <:COMSD, :ptr PSECURITY_DESCRIPTOR>, 8
    endif
    ;* dll loading helpers; keeps track of ref counts and unloads all on exit *
    @DefProto DllImport, CoLoadLibrary, WIN_STD_CALL_CONV,, <:LPOLESTR, :BOOL>, 8
    @DefProto DllImport, CoFreeLibrary, WIN_STD_CALL_CONV,, <:HINSTANCE>, 4
    @DefProto DllImport, CoFreeAllLibraries, WIN_STD_CALL_CONV,, <>, 0
    if (_WIN32_WINNT ge 0400h) or Defined(_WIN32_DCOM)
      ; DCOM
      @DefProto DllImport, CoGetInstanceFromFile, WIN_STD_CALL_CONV,, <:ptr COSERVERINFO, :ptr CLSID, :ptr IUnknown, :DWORD, :DWORD, :ptr OLECHAR, :DWORD, :ptr MULTI_QI>, 32
      ; only relevant locally
      @DefProto DllImport, CoGetInstanceFromIStorage, WIN_STD_CALL_CONV,, <:ptr COSERVERINFO, :ptr CLSID, :ptr IUnknown, :DWORD, :ptr IStorage, :DWORD, :ptr MULTI_QI>, 28
      ; only relevant locally
    endif
    ; DCOM
    ;* Call related APIs *
    if (_WIN32_WINNT ge 0500h) or Defined(_WIN32_DCOM)
      ; DCOM
      @DefProto DllImport, CoAllowSetForegroundWindow, WIN_STD_CALL_CONV,, <:ptr IUnknown, :LPVOID>, 8
      @DefProto DllImport, DcomChannelSetHResult, WIN_STD_CALL_CONV,, <:LPVOID, :ptr ULONG, :HRESULT>, 12
    endif
    ;* other helpers *
    @DefProto DllImport, CoIsOle1Class, WIN_STD_CALL_CONV,, <:REFCLSID>, 4
    @DefProto DllImport, CLSIDFromProgIDEx, WIN_STD_CALL_CONV,, <:LPCOLESTR, :LPCLSID>, 8
    @DefProto DllImport, CoFileTimeToDosDateTime, WIN_STD_CALL_CONV,, <:ptr FILETIME, :LPWORD, :LPWORD>, 12
    @DefProto DllImport, CoDosDateTimeToFileTime, WIN_STD_CALL_CONV,, <:WORD, :WORD, :ptr FILETIME>, 12
    @DefProto DllImport, CoFileTimeNow, WIN_STD_CALL_CONV,, <:ptr FILETIME>, 4
    @DefProto DllImport, CoRegisterMessageFilter, WIN_STD_CALL_CONV,, <:LPMESSAGEFILTER, :ptr LPMESSAGEFILTER>, 8
    if (_WIN32_WINNT ge 0400h) or Defined(_WIN32_DCOM)
      ; DCOM
      @DefProto DllImport, CoRegisterChannelHook, WIN_STD_CALL_CONV,, <:REFGUID, :ptr IChannelHook>, 8
    endif
    ; DCOM
    ;* TreatAs APIS *
    @DefProto DllImport, CoTreatAsClass, WIN_STD_CALL_CONV,, <:REFCLSID, :REFCLSID>, 8
    ;****** DV APIs ***********************************************************
    @DefProto DllImport, CreateDataAdviseHolder, WIN_STD_CALL_CONV,, <:ptr LPDATAADVISEHOLDER>, 4
    @DefProto DllImport, CreateDataCache, WIN_STD_CALL_CONV,, <:LPUNKNOWN, :REFCLSID, :REFIID, :ptr LPVOID>, 16
    ;****** Storage API Prototypes ********************************************
    @DefProto DllImport, StgOpenAsyncDocfileOnIFillLockBytes, WIN_STD_CALL_CONV,, <:ptr IFillLockBytes, :DWORD, :DWORD, :ptr ptr IStorage>, 16
    @DefProto DllImport, StgGetIFillLockBytesOnILockBytes, WIN_STD_CALL_CONV,, <:ptr ILockBytes, :ptr ptr IFillLockBytes>, 8
    @DefProto DllImport, StgGetIFillLockBytesOnFile, WIN_STD_CALL_CONV,, <:ptr OLECHAR, :ptr ptr IFillLockBytes>, 8
    @DefProto DllImport, StgOpenLayoutDocfile, WIN_STD_CALL_CONV,, <:ptr OLECHAR, :DWORD, :DWORD, :ptr ptr IStorage>, 16
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    @DefProto DllImport, CoInstall, WIN_STD_CALL_CONV,, <:ptr IBindCtx, :DWORD, :ptr uCLSSPEC, :ptr QUERYCONTEXT, :LPWSTR>, 20
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_PC_APP)
    ;  Moniker APIs
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
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_PC_APP) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    @DefProto DllImport, GetRunningObjectTable, WIN_STD_CALL_CONV,, <:DWORD, :ptr LPRUNNINGOBJECTTABLE>, 8
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  include urlmon.inc
  include propidl.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ; Standard Progress Indicator implementation
    @DefProto DllImport, CreateStdProgressIndicator, WIN_STD_CALL_CONV,, <:HWND, :LPCOLESTR, :ptr IBindStatusCallback, :ptr ptr IBindStatusCallback>, 16
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  ifndef RC_INVOKED
    include poppack.inc
  endif
  ; RC_INVOKED
endif
; __OBJBASE_H__
