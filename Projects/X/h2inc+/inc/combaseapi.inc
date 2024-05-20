;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\combaseapi.h
;             Created on (UTC) 06/04/2024 06:15:52
;             Last modified on (UTC) 21/02/2024 18:13:20

;----------------------------------------------------------------------------
include apiset.inc
include apisetcconv.inc
;TODO version number should be bumped when _APISET_TARGET_VERSION_WIN10_RS2 becomes available
include rpc.inc
include rpcndr.inc
if (NTDDI_VERSION ge NTDDI_VISTA and  not Defined(_WIN32_WINNT))
  _WIN32_WINNT equ 0600h
endif
if (NTDDI_VERSION ge NTDDI_WS03 and  not Defined(_WIN32_WINNT))
  _WIN32_WINNT equ 0502h
endif
if (NTDDI_VERSION ge NTDDI_WINXP and  not Defined(_WIN32_WINNT))
  _WIN32_WINNT equ 0501h
endif
if (NTDDI_VERSION ge NTDDI_WIN2K and  not Defined(_WIN32_WINNT))
  _WIN32_WINNT equ 0500h
endif
if  not Defined(_COMBASEAPI_H_)
  _COMBASEAPI_H_ equ <>
  ifdef _MSC_VER
  endif
  ; _MSC_VER
  include pshpack8.inc
  ;TODO change _OLE32_ to _COMBASEAPI_
  ifdef _OLE32_
    WINOLEAPI equ <STDAPI>
    WINOLEAPI_ macro type_
      exitm <STDAPI_(type_)>
    endm
  else
    ifdef _68K_
      ;[...]
    else
      WINOLEAPI equ <EXTERN_C DECLSPEC_IMPORT HRESULT STDAPICALLTYPE>
      WINOLEAPI_ macro type_
        exitm <EXTERN_C DECLSPEC_IMPORT type_ STDAPICALLTYPE>
      endm
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    ;****** Interface Declaration ***********************************************
    ;*
    ;*      These are macros for declaring interfaces.  They exist so that
    ;*      a single definition of the interface is simulataneously a proper
    ;*      declaration of the interface structures (C++ abstract classes)
    ;*      for both C and C++.
    ;*
    ;*      DECLARE_INTERFACE(iface) is used to declare an interface that does
    ;*      not derive from a base interface.
    ;*      DECLARE_INTERFACE_(iface, baseiface) is used to declare an interface
    ;*      that does derive from a base interface.
    ;*
    ;*      By default if the source file has a .c extension the C version of
    ;*      the interface declaratations will be expanded; if it has a .cpp
    ;*      extension the C++ version will be expanded. if you want to force
    ;*      the C version expansion even though the source file has a .cpp
    ;*      extension, then define the macro "CINTERFACE".
    ;*      eg.     cl -DCINTERFACE file.cpp
    ;*
    ;*      Example Interface declaration:
    ;*
    ;*          #undef  INTERFACE
    ;*          #define INTERFACE   IClassFactory
    ;*
    ;*          DECLARE_INTERFACE_(IClassFactory, IUnknown)
    ;*          {
    ;*              // *** IUnknown methods ***
    ;*              STDMETHOD(QueryInterface) (THIS_
    ;*                                        REFIID riid,
    ;*                                        LPVOID FAR* ppvObj) PURE;
    ;*              STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    ;*              STDMETHOD_(ULONG,Release) (THIS) PURE;
    ;*
    ;*              // *** IClassFactory methods ***
    ;*              STDMETHOD(CreateInstance) (THIS_
    ;*                                        LPUNKNOWN pUnkOuter,
    ;*                                        REFIID riid,
    ;*                                        LPVOID FAR* ppvObject) PURE;
    ;*          };
    ;*
    ;*      Example C++ expansion:
    ;*
    ;*          struct FAR IClassFactory : public IUnknown
    ;*          {
    ;*              virtual HRESULT STDMETHODCALLTYPE QueryInterface(
    ;*                                                  IID FAR& riid,
    ;*                                                  LPVOID FAR* ppvObj) = 0;
    ;*              virtual HRESULT STDMETHODCALLTYPE AddRef(void) = 0;
    ;*              virtual HRESULT STDMETHODCALLTYPE Release(void) = 0;
    ;*              virtual HRESULT STDMETHODCALLTYPE CreateInstance(
    ;*                                              LPUNKNOWN pUnkOuter,
    ;*                                              IID FAR& riid,
    ;*                                              LPVOID FAR* ppvObject) = 0;
    ;*          };
    ;*
    ;*          NOTE: Our documentation says '#define interface class' but we use
    ;*          'struct' instead of 'class' to keep a lot of 'public:' lines
    ;*          out of the interfaces.  The 'FAR' forces the 'this' pointers to
    ;*          be far, which is what we need.
    ;*
    ;*      Example C expansion:
    ;*
    ;*          typedef struct IClassFactory
    ;*          {
    ;*              const struct IClassFactoryVtbl FAR* lpVtbl;
    ;*          } IClassFactory;
    ;*
    ;*          typedef struct IClassFactoryVtbl IClassFactoryVtbl;
    ;*
    ;*          struct IClassFactoryVtbl
    ;*          {
    ;*              HRESULT (STDMETHODCALLTYPE * QueryInterface) (
    ;*                                                  IClassFactory FAR* This,
    ;*                                                  IID FAR* riid,
    ;*                                                  LPVOID FAR* ppvObj) ;
    ;*              HRESULT (STDMETHODCALLTYPE * AddRef) (IClassFactory FAR* This) ;
    ;*              HRESULT (STDMETHODCALLTYPE * Release) (IClassFactory FAR* This) ;
    ;*              HRESULT (STDMETHODCALLTYPE * CreateInstance) (
    ;*                                                  IClassFactory FAR* This,
    ;*                                                  LPUNKNOWN pUnkOuter,
    ;*                                                  IID FAR* riid,
    ;*                                                  LPVOID FAR* ppvObject);
    ;*              HRESULT (STDMETHODCALLTYPE * LockServer) (
    ;*                                                  IClassFactory FAR* This,
    ;*                                                  BOOL fLock);
    ;*          };
    ;*
    if Defined(__cplusplus) and  not Defined(CINTERFACE)
      ;[...]
      ; !SORTPP_PASS
    else
      interface equ <struct>
      STDMETHOD macro method_
        exitm <HRESULT (STDMETHODCALLTYPE * method_)>
      endm
      STDMETHOD_ macro type_, method_
        exitm <type_(STDMETHODCALLTYPE * method_)>
      endm
      STDMETHODV macro method_
        exitm <HRESULT (STDMETHODVCALLTYPE * method_)>
      endm
      STDMETHODV_ macro type_, method_
        exitm <type_(STDMETHODVCALLTYPE * method_)>
      endm
      IFACEMETHOD macro method_
        exitm <__override STDMETHOD(method_)>
      endm
      IFACEMETHOD_ macro type_, method_
        exitm <__override STDMETHOD_(type_, method_)>
      endm
      IFACEMETHODV macro method_
        exitm <__override STDMETHODV(method_)>
      endm
      IFACEMETHODV_ macro type_, method_
        exitm <__override STDMETHODV_(type_, method_)>
      endm
      if  not Defined(BEGIN_INTERFACE)
        if Defined(_MPPC_)
          ;[...]
        else
          BEGIN_INTERFACE equ <>
          END_INTERFACE equ <>
        endif
      endif
      PURE equ <>
      THIS_ equ <INTERFACE FAR * This,>
      THIS_ equ <INTERFACE FAR * This>
      ifdef CONST_VTABLE
        CONST_VTBL equ <const>
        DECLARE_INTERFACE macro iface
          exitm <typedef interface iface { const struct iface ## Vtbl FAR * lpVtbl ; } iface ; typedef const struct iface ## Vtbl iface ## Vtbl ; const struct iface ## Vtbl>
        endm
      else
        CONST_VTBL equ <>
        DECLARE_INTERFACE macro iface
          exitm <typedef interface iface { struct iface ## Vtbl FAR * lpVtbl ; } iface ; typedef struct iface ## Vtbl iface ## Vtbl ; struct iface ## Vtbl>
        endm
      endif
      DECLARE_INTERFACE_ macro iface, baseiface
        exitm <DECLARE_INTERFACE(iface)>
      endm
      DECLARE_INTERFACE_IID macro iface, iid
        exitm <DECLARE_INTERFACE(iface)>
      endm
      DECLARE_INTERFACE_IID_ macro iface, baseiface, iid
        exitm <DECLARE_INTERFACE_(iface, baseiface)>
      endm
    endif
    ;****** Additional basic types **********************************************
    ifndef FARSTRUCT
      ifdef __cplusplus
        ;[...]
      else
        FARSTRUCT equ <>
      endif
      ; __cplusplus
    endif
    ; FARSTRUCT
    ifndef HUGEP
      if Defined(_WIN32) or Defined(_MPPC_)
        HUGEP equ <>
      else
        ;[...]
      endif
      ; WIN32
    endif
    ; HUGEP
    include stdlib.inc
    LISet32 macro li, v
      exitm <((li).HighPart = ((v)) < 0 ? - 1 : 0, (li).LowPart = (v))>
    endm
    ULISet32 macro li, v
      exitm <((li).HighPart = 0, (li).LowPart = (v))>
    endm
    CLSCTX_INPROC equ <(CLSCTX_INPROC_SERVER or CLSCTX_INPROC_HANDLER)>
    ; With DCOM, CLSCTX_REMOTE_SERVER should be included
    ; DCOM
    if (_WIN32_WINNT ge 0400h) or Defined(_WIN32_DCOM)
      CLSCTX_ALL equ <(CLSCTX_INPROC_SERVER or CLSCTX_INPROC_HANDLER or CLSCTX_LOCAL_SERVER or CLSCTX_REMOTE_SERVER)>
      CLSCTX_SERVER equ <(CLSCTX_INPROC_SERVER or CLSCTX_LOCAL_SERVER or CLSCTX_REMOTE_SERVER)>
    else
      CLSCTX_ALL equ <(CLSCTX_INPROC_SERVER or CLSCTX_INPROC_HANDLER or CLSCTX_LOCAL_SERVER)>
      CLSCTX_SERVER equ <(CLSCTX_INPROC_SERVER or CLSCTX_LOCAL_SERVER)>
    endif
    ; class registration flags; passed to CoRegisterClassObject
    REGCLS typedef SDWORD
    REGCLS_SINGLEUSE equ 0
    ; class object only generates one instance
    REGCLS_MULTIPLEUSE equ 1
    ; same class object genereates multiple inst.
    ; and local automatically goes into inproc tbl.
    REGCLS_MULTI_SEPARATE equ 2
    ; multiple use, but separate control over each
    ; context.
    REGCLS_SUSPENDED equ 4
    ; register is as suspended, will be activated
    ; when app calls CoResumeClassObjects
    REGCLS_SURROGATE equ 8
    ; must be used when a surrogate process
    ; is registering a class object that will be
    ; loaded in the surrogate
    if (NTDDI_VERSION ge NTDDI_WINTHRESHOLD)
      REGCLS_AGILE equ 10h
      ; Class object aggregates the free-threaded marshaler
      ; and will be made visible to all inproc apartments.
      ; Can be used together with other flags - for example,
      ; REGCLS_AGILE | REGCLS_MULTIPLEUSE to register a
      ; class object that can be used multiple times from
      ; different apartments. Without other flags, behavior
      ; will retain REGCLS_SINGLEUSE semantics in that only
      ; one instance can be generated.
    endif
    tagREGCLS typedef REGCLS

    DEFINE_ENUM_FLAG_OPERATORS(REGCLS)
    ;* here is where we pull in the MIDL generated headers for the interfaces *
    ; COM initialization flags; passed to CoInitialize.
    COINITBASE typedef SDWORD
    ; DCOM
    ; DCOM
    if (_WIN32_WINNT ge 0400h) or Defined(_WIN32_DCOM)
      ; These constants are only valid on Windows NT 4.0
      COINITBASE_MULTITHREADED equ 0h
      ; OLE calls objects on any thread.
    endif
    ; DCOM
    tagCOINITBASE typedef COINITBASE

    include wtypesbase.inc
    include unknwnbase.inc
    if Defined(__cplusplus) and  not Defined(CINTERFACE)
      ;[...]
    endif
    ; defined(__cplusplus) && !defined(CINTERFACE)
    include objidlbase.inc
    include guiddef.inc
    ifndef INITGUID
      ; TODO change to cguidbase.h
      include cguid.inc
    endif
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
  ;****** STD Object API Prototypes *****************************************
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, CoGetMalloc, WIN_STD_CALL_CONV,, <:DWORD, :ptr LPMALLOC>, 8
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, CreateStreamOnHGlobal, WIN_STD_CALL_CONV,, <:HGLOBAL, :BOOL, :ptr LPSTREAM>, 12
    @DefProto DllImport, GetHGlobalFromStream, WIN_STD_CALL_CONV,, <:LPSTREAM, :ptr HGLOBAL>, 8
    ;* init/uninit *
    @DefProto DllImport, CoUninitialize, WIN_STD_CALL_CONV,, <>, 0
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, CoGetCurrentProcess, WIN_STD_CALL_CONV,, <>, 0
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
  ; DCOM
  if (_WIN32_WINNT ge 0400h) or Defined(_WIN32_DCOM)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CoInitializeEx, WIN_STD_CALL_CONV,, <:LPVOID, :DWORD>, 8
    endif
    ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, CoGetCallerTID, WIN_STD_CALL_CONV,, <:LPDWORD>, 4
    endif
    ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, CoGetCurrentLogicalThreadId, WIN_STD_CALL_CONV,, <:ptr GUID>, 4
    endif
    ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)
  endif
  ; DCOM
  if (_WIN32_WINNT ge 0501h)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CoGetContextToken, WIN_STD_CALL_CONV,, <:ptr ULONG_PTR>, 4
    endif
    ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, CoGetDefaultContext, WIN_STD_CALL_CONV,, <:APTTYPE, :REFIID, :ptr ptr>, 12
    endif
    ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    ; definition for Win7 new APIs
    if (NTDDI_VERSION ge NTDDI_WIN7)
      @DefProto DllImport, CoGetApartmentType, WIN_STD_CALL_CONV,, <:ptr APTTYPE, :ptr APTTYPEQUALIFIER>, 8
    endif
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
  ; definition for Win8 new APIs
  if (NTDDI_VERSION ge NTDDI_WIN8)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      ServerInformation struct
        dwServerPid DWORD ?
        dwServerTid DWORD ?
        ui64ServerAddress QWORD ?
      ServerInformation ends
      tagServerInformation typedef ServerInformation
      PServerInformation typedef ptr ServerInformation
    endif
    ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, CoDecodeProxy, WIN_STD_CALL_CONV,, <:DWORD, :UINT64, :PServerInformation>, 12
    endif
    ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      DECLARE_HANDLE CO_MTA_USAGE_COOKIE
      @DefProto DllImport, CoIncrementMTAUsage, WIN_STD_CALL_CONV,, <:ptr CO_MTA_USAGE_COOKIE>, 4
      @DefProto DllImport, CoDecrementMTAUsage, WIN_STD_CALL_CONV,, <:CO_MTA_USAGE_COOKIE>, 4
    endif
    ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CoAllowUnmarshalerCLSID, WIN_STD_CALL_CONV,, <:REFCLSID>, 4
      ; Predefine _EXE_INITIALIZE_MTA to have the runtime initialize an MTA for your process
      ; prior to initializing globals (i.e. dynamic initializers)
      if  not Defined(RC_INVOKED)
        ; _EXE_INITIALIZE_MTA et al. are too long for rc
        if Defined(_M_IX86)
          _CRT_INTERNAL_COMBASE_SYMBOL_PREFIX equ <"_">
        elseif Defined(_M_X64) or Defined(_M_ARM) or Defined(_M_ARM64)
          _CRT_INTERNAL_COMBASE_SYMBOL_PREFIX equ <>
        endif
        if Defined(_EXE_INITIALIZE_MTA) and  not Defined(_M_CEE)
        endif
      endif
    endif
    ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, CoGetObjectContext, WIN_STD_CALL_CONV,, <:REFIID, :ptr LPVOID>, 8
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    ;* register/revoke/get class objects *
    @DefProto DllImport, CoGetClassObject, WIN_STD_CALL_CONV,, <:REFCLSID, :DWORD, :LPVOID, :REFIID, :ptr LPVOID>, 20
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, CoRegisterClassObject, WIN_STD_CALL_CONV,, <:REFCLSID, :LPUNKNOWN, :DWORD, :DWORD, :LPDWORD>, 20
    @DefProto DllImport, CoRevokeClassObject, WIN_STD_CALL_CONV,, <:DWORD>, 4
    @DefProto DllImport, CoResumeClassObjects, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, CoSuspendClassObjects, WIN_STD_CALL_CONV,, <>, 0
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, CoAddRefServerProcess, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, CoReleaseServerProcess, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, CoGetPSClsid, WIN_STD_CALL_CONV,, <:REFIID, :ptr CLSID>, 8
    @DefProto DllImport, CoRegisterPSClsid, WIN_STD_CALL_CONV,, <:REFIID, :REFCLSID>, 8
    ; Registering surrogate processes
    @DefProto DllImport, CoRegisterSurrogate, WIN_STD_CALL_CONV,, <:LPSURROGATE>, 4
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    ;* marshaling interface pointers *
    @DefProto DllImport, CoGetMarshalSizeMax, WIN_STD_CALL_CONV,, <:ptr ULONG, :REFIID, :LPUNKNOWN, :DWORD, :LPVOID, :DWORD>, 24
    @DefProto DllImport, CoMarshalInterface, WIN_STD_CALL_CONV,, <:LPSTREAM, :REFIID, :LPUNKNOWN, :DWORD, :LPVOID, :DWORD>, 24
    @DefProto DllImport, CoUnmarshalInterface, WIN_STD_CALL_CONV,, <:LPSTREAM, :REFIID, :ptr LPVOID>, 12
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, CoMarshalHresult, WIN_STD_CALL_CONV,, <:LPSTREAM, :HRESULT>, 8
    @DefProto DllImport, CoUnmarshalHresult, WIN_STD_CALL_CONV,, <:LPSTREAM, :ptr HRESULT>, 8
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, CoReleaseMarshalData, WIN_STD_CALL_CONV,, <:LPSTREAM>, 4
    @DefProto DllImport, CoDisconnectObject, WIN_STD_CALL_CONV,, <:LPUNKNOWN, :DWORD>, 8
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, CoLockObjectExternal, WIN_STD_CALL_CONV,, <:LPUNKNOWN, :BOOL, :BOOL>, 12
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, CoGetStandardMarshal, WIN_STD_CALL_CONV,, <:REFIID, :LPUNKNOWN, :DWORD, :LPVOID, :DWORD, :ptr LPMARSHAL>, 24
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, CoGetStdMarshalEx, WIN_STD_CALL_CONV,, <:LPUNKNOWN, :DWORD, :ptr LPUNKNOWN>, 12
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    ;* flags for CoGetStdMarshalEx *
    STDMSHLFLAGS typedef SDWORD
    SMEXF_SERVER equ 01h
    ; server side aggregated std marshaler
    SMEXF_HANDLER equ 02h
    tagSTDMSHLFLAGS typedef STDMSHLFLAGS

    ; client side (handler) agg std marshaler
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, CoIsHandlerConnected, WIN_STD_CALL_CONV,, <:LPUNKNOWN>, 4
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    ; Apartment model inter-thread interface passing helpers
    @DefProto DllImport, CoMarshalInterThreadInterfaceInStream, WIN_STD_CALL_CONV,, <:REFIID, :LPUNKNOWN, :ptr LPSTREAM>, 12
    @DefProto DllImport, CoGetInterfaceAndReleaseStream, WIN_STD_CALL_CONV,, <:LPSTREAM, :REFIID, :ptr LPVOID>, 12
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, CoCreateFreeThreadedMarshaler, WIN_STD_CALL_CONV,, <:LPUNKNOWN, :ptr LPUNKNOWN>, 8
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, CoFreeUnusedLibraries, WIN_STD_CALL_CONV,, <>, 0
    if (_WIN32_WINNT ge 0501h)
      @DefProto DllImport, CoFreeUnusedLibrariesEx, WIN_STD_CALL_CONV,, <:DWORD, :DWORD>, 8
    endif
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)
  if (_WIN32_WINNT ge 0600h)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, CoDisconnectContext, WIN_STD_CALL_CONV,, <:DWORD>, 4
    endif
    ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
  endif
  ; DCOM
  if (_WIN32_WINNT ge 0400h) or Defined(_WIN32_DCOM)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;* Call Security. *
      @DefProto DllImport, CoInitializeSecurity, WIN_STD_CALL_CONV,, <:PSECURITY_DESCRIPTOR, :LONG, :ptr SOLE_AUTHENTICATION_SERVICE, :ptr, :DWORD, :DWORD, :ptr, :DWORD, :ptr>, 36
    endif
    ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, CoGetCallContext, WIN_STD_CALL_CONV,, <:REFIID, :ptr ptr>, 8
      @DefProto DllImport, CoQueryProxyBlanket, WIN_STD_CALL_CONV,, <:ptr IUnknown, :ptr DWORD, :ptr DWORD, :ptr LPOLESTR, :ptr DWORD, :ptr DWORD, :ptr RPC_AUTH_IDENTITY_HANDLE, :ptr DWORD>, 32
      @DefProto DllImport, CoSetProxyBlanket, WIN_STD_CALL_CONV,, <:ptr IUnknown, :DWORD, :DWORD, :ptr OLECHAR, :DWORD, :DWORD, :RPC_AUTH_IDENTITY_HANDLE, :DWORD>, 32
      @DefProto DllImport, CoCopyProxy, WIN_STD_CALL_CONV,, <:ptr IUnknown, :ptr ptr IUnknown>, 8
      @DefProto DllImport, CoQueryClientBlanket, WIN_STD_CALL_CONV,, <:ptr DWORD, :ptr DWORD, :ptr LPOLESTR, :ptr DWORD, :ptr DWORD, :ptr RPC_AUTHZ_HANDLE, :ptr DWORD>, 28
      @DefProto DllImport, CoImpersonateClient, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, CoRevertToSelf, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, CoQueryAuthenticationServices, WIN_STD_CALL_CONV,, <:ptr DWORD, :ptr ptr SOLE_AUTHENTICATION_SERVICE>, 8
    endif
    ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, CoSwitchCallContext, WIN_STD_CALL_CONV,, <:ptr IUnknown, :ptr ptr IUnknown>, 8
      COM_RIGHTS_EXECUTE equ 1
      COM_RIGHTS_EXECUTE_LOCAL equ 2
      COM_RIGHTS_EXECUTE_REMOTE equ 4
      COM_RIGHTS_ACTIVATE_LOCAL equ 8
      COM_RIGHTS_ACTIVATE_REMOTE equ 16
      COM_RIGHTS_RESERVED1 equ 32
      COM_RIGHTS_RESERVED2 equ 64
    endif
    ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)
  endif
  ; DCOM
  if (WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES))
    ;* helper for creating instances *
    @DefProto DllImport, CoCreateInstance, WIN_STD_CALL_CONV,, <:REFCLSID, :LPUNKNOWN, :DWORD, :REFIID, :ptr LPVOID>, 20
  endif
  ; (WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES))
  if (WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM))
    ; DCOM
    if (_WIN32_WINNT ge 0400h) or Defined(_WIN32_DCOM)
      @DefProto DllImport, CoCreateInstanceEx, WIN_STD_CALL_CONV,, <:REFCLSID, :ptr IUnknown, :DWORD, :ptr COSERVERINFO, :DWORD, :ptr MULTI_QI>, 24
    endif
    ; DCOM
    if (_WIN32_WINNT ge 0602h)
      @DefProto DllImport, CoCreateInstanceFromApp, WIN_STD_CALL_CONV,, <:REFCLSID, :ptr IUnknown, :DWORD, :PVOID, :DWORD, :ptr MULTI_QI>, 24
    endif
    ; (_WIN32_WINNT >= 0x0602)
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, CoRegisterActivationFilter, WIN_STD_CALL_CONV,, <:ptr IActivationFilter>, 4
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
  ;* Call related APIs *
  ; DCOM
  if (_WIN32_WINNT ge 0500h) or Defined(_WIN32_DCOM)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, CoGetCancelObject, WIN_STD_CALL_CONV,, <:DWORD, :REFIID, :ptr ptr>, 12
      @DefProto DllImport, CoSetCancelObject, WIN_STD_CALL_CONV,, <:ptr IUnknown>, 4
      @DefProto DllImport, CoCancelCall, WIN_STD_CALL_CONV,, <:DWORD, :ULONG>, 8
      @DefProto DllImport, CoTestCancel, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, CoEnableCallCancellation, WIN_STD_CALL_CONV,, <:LPVOID>, 4
      @DefProto DllImport, CoDisableCallCancellation, WIN_STD_CALL_CONV,, <:LPVOID>, 4
    endif
    ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    ;* other helpers *
    @DefProto DllImport, StringFromCLSID, WIN_STD_CALL_CONV,, <:REFCLSID, :ptr LPOLESTR>, 8
    @DefProto DllImport, CLSIDFromString, WIN_STD_CALL_CONV,, <:LPCOLESTR, :LPCLSID>, 8
    @DefProto DllImport, StringFromIID, WIN_STD_CALL_CONV,, <:REFIID, :ptr LPOLESTR>, 8
    @DefProto DllImport, IIDFromString, WIN_STD_CALL_CONV,, <:LPCOLESTR, :LPIID>, 8
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, ProgIDFromCLSID, WIN_STD_CALL_CONV,, <:REFCLSID, :ptr LPOLESTR>, 8
    @DefProto DllImport, CLSIDFromProgID, WIN_STD_CALL_CONV,, <:LPCOLESTR, :LPCLSID>, 8
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, StringFromGUID2, WIN_STD_CALL_CONV,, <:REFGUID, :LPOLESTR, :SDWORD>, 12
    @DefProto DllImport, CoCreateGuid, WIN_STD_CALL_CONV,, <:ptr GUID>, 4
    ;* Prop variant support *
    PROPVARIANT typedef tagPROPVARIANT
    @DefProto DllImport, PropVariantCopy, WIN_STD_CALL_CONV,, <:ptr PROPVARIANT, :ptr PROPVARIANT>, 8
    @DefProto DllImport, PropVariantClear, WIN_STD_CALL_CONV,, <:ptr PROPVARIANT>, 4
    @DefProto DllImport, FreePropVariantArray, WIN_STD_CALL_CONV,, <:ULONG, :ptr PROPVARIANT>, 8
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
  ; DCOM
  if (_WIN32_WINNT ge 0400h) or Defined(_WIN32_DCOM)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    endif
    ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
  endif
  ; DCOM
  ; DCOM
  if (_WIN32_WINNT ge 0400h) or Defined(_WIN32_DCOM)
    ;* Synchronization API *
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, CoWaitForMultipleHandles, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :ULONG, :LPHANDLE, :LPDWORD>, 20
      ;* Flags for Synchronization API and Classes *
      COWAIT_FLAGS typedef SDWORD
      COWAIT_DEFAULT equ 0
      COWAIT_WAITALL equ 1
      COWAIT_ALERTABLE equ 2
      COWAIT_INPUTAVAILABLE equ 4
      COWAIT_DISPATCH_CALLS equ 8
      COWAIT_DISPATCH_WINDOW_MESSAGES equ 10h
      tagCOWAIT_FLAGS typedef COWAIT_FLAGS

      DEFINE_ENUM_FLAG_OPERATORS(COWAIT_FLAGS)
      if (NTDDI_VERSION ge NTDDI_WIN8)
        CWMO_FLAGS typedef SDWORD
        CWMO_DEFAULT equ 0
        CWMO_DISPATCH_CALLS equ 1
        CWMO_DISPATCH_WINDOW_MESSAGES equ 2

        DEFINE_ENUM_FLAG_OPERATORS(CWMO_FLAGS)
        @DefProto DllImport, CoWaitForMultipleObjects, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :ULONG, :ptr HANDLE, :LPDWORD>, 20
      endif
      ; (NTDDI_VERSION >= NTDDI_WIN8)
      CWMO_MAX_HANDLES equ 56
    endif
    ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
  endif
  ; DCOM
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, CoGetTreatAsClass, WIN_STD_CALL_CONV,, <:REFCLSID, :LPCLSID>, 8
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
  ;* for flushing OLESCM remote binding handles *
  if (_WIN32_WINNT ge 0501h)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, CoInvalidateRemoteMachineBindings, WIN_STD_CALL_CONV,, <:LPOLESTR>, 4
    endif
    ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
  endif
  if (NTDDI_VERSION ge NTDDI_WINBLUE)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      AgileReferenceOptions typedef SDWORD
      AGILEREFERENCE_DEFAULT equ 0
      AGILEREFERENCE_DELAYEDMARSHAL equ 1

      @DefProto DllImport, RoGetAgileReference, WIN_STD_CALL_CONV,, <:AgileReferenceOptions, :REFIID, :ptr IUnknown, :ptr ptr IAgileReference>, 16
    endif
    ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    ;* the server dlls must define their DllGetClassObject and DllCanUnloadNow
    ;* to match these; the typedefs are located here to ensure all are changed at
    ;* the same time.
    ;*
    TYPE_LPFNGETCLASSOBJECT typedef proto WIN_STD_CALL_CONV :REFCLSID, :REFIID, :ptr LPVOID
    LPFNGETCLASSOBJECT typedef ptr TYPE_LPFNGETCLASSOBJECT

    TYPE_LPFNCANUNLOADNOW typedef proto WIN_STD_CALL_CONV
    LPFNCANUNLOADNOW typedef ptr TYPE_LPFNCANUNLOADNOW

    @DefProto DllImport, DllGetClassObject, WIN_STD_CALL_CONV,, <:REFCLSID, :REFIID, :ptr LPVOID>, 12
    @DefProto DllImport, DllCanUnloadNow, WIN_STD_CALL_CONV,, <>, 0
    ;****** Default Memory Allocation ******************************************
    @DefProto DllImport, CoTaskMemAlloc, WIN_STD_CALL_CONV,, <:SIZE_T>, 4
    @DefProto DllImport, CoTaskMemRealloc, WIN_STD_CALL_CONV,, <:LPVOID, :SIZE_T>, 8
    @DefProto DllImport, CoTaskMemFree, WIN_STD_CALL_CONV,, <:LPVOID>, 4
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, CoFileTimeNow, WIN_STD_CALL_CONV,, <:ptr FILETIME>, 4
    @DefProto DllImport, CLSIDFromProgIDEx, WIN_STD_CALL_CONV,, <:LPCOLESTR, :LPCLSID>, 8
    if (NTDDI_VERSION ge NTDDI_WIN10_VB)
      if  not Defined(_CO_DEVICE_CATALOG_)
        _CO_DEVICE_CATALOG_ equ <>
      endif
      DECLARE_HANDLE CO_DEVICE_CATALOG_COOKIE
      @DefProto DllImport, CoRegisterDeviceCatalog, WIN_STD_CALL_CONV,, <:PCWSTR, :ptr CO_DEVICE_CATALOG_COOKIE>, 8
      @DefProto DllImport, CoRevokeDeviceCatalog, WIN_STD_CALL_CONV,, <:CO_DEVICE_CATALOG_COOKIE>, 4
    endif
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
  ifndef RC_INVOKED
    include poppack.inc
  endif
  ; RC_INVOKED
endif
; __COMBASEAPI_H__
