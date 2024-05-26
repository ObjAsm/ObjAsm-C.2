;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\sapiddk.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 21/02/2024 18:17:12

ifndef __REQUIRED_RPCNDR_H_VERSION__
  __REQUIRED_RPCNDR_H_VERSION__ equ 501
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
ifndef __sapiddk_h__
  __sapiddk_h__ equ <>
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
  ifndef __ISpTokenUI_FWD_DEFINED__
    __ISpTokenUI_FWD_DEFINED__ equ <>
  endif
  ifndef __ISpObjectTokenEnumBuilder_FWD_DEFINED__
    __ISpObjectTokenEnumBuilder_FWD_DEFINED__ equ <>
  endif
  ifndef __ISpErrorLog_FWD_DEFINED__
    __ISpErrorLog_FWD_DEFINED__ equ <>
  endif
  ifndef __ISpGrammarCompiler_FWD_DEFINED__
    __ISpGrammarCompiler_FWD_DEFINED__ equ <>
  endif
  ifndef __ISpGramCompBackend_FWD_DEFINED__
    __ISpGramCompBackend_FWD_DEFINED__ equ <>
  endif
  ifndef __ISpITNProcessor_FWD_DEFINED__
    __ISpITNProcessor_FWD_DEFINED__ equ <>
  endif
  ifndef __ISpPhraseBuilder_FWD_DEFINED__
    __ISpPhraseBuilder_FWD_DEFINED__ equ <>
  endif
  ifndef __ISpThreadControl_FWD_DEFINED__
    __ISpThreadControl_FWD_DEFINED__ equ <>
  endif
  ifndef __ISpTaskManager_FWD_DEFINED__
    __ISpTaskManager_FWD_DEFINED__ equ <>
  endif
  ifndef __ISpTTSEngineSite_FWD_DEFINED__
    __ISpTTSEngineSite_FWD_DEFINED__ equ <>
  endif
  ifndef __ISpTTSEngine_FWD_DEFINED__
    __ISpTTSEngine_FWD_DEFINED__ equ <>
  endif
  ifndef __ISpCFGInterpreterSite_FWD_DEFINED__
    __ISpCFGInterpreterSite_FWD_DEFINED__ equ <>
  endif
  ifndef __ISpCFGInterpreter_FWD_DEFINED__
    __ISpCFGInterpreter_FWD_DEFINED__ equ <>
  endif
  ifndef __ISpSREngineSite_FWD_DEFINED__
    __ISpSREngineSite_FWD_DEFINED__ equ <>
  endif
  ifndef __ISpSREngineSite2_FWD_DEFINED__
    __ISpSREngineSite2_FWD_DEFINED__ equ <>
  endif
  ifndef __ISpSREngine_FWD_DEFINED__
    __ISpSREngine_FWD_DEFINED__ equ <>
  endif
  ifndef __ISpSREngine2_FWD_DEFINED__
    __ISpSREngine2_FWD_DEFINED__ equ <>
  endif
  ifndef __ISpSRAlternates_FWD_DEFINED__
    __ISpSRAlternates_FWD_DEFINED__ equ <>
  endif
  ifndef __ISpSRAlternates2_FWD_DEFINED__
    __ISpSRAlternates2_FWD_DEFINED__ equ <>
  endif
  ifndef ___ISpPrivateEngineCall_FWD_DEFINED__
    ___ISpPrivateEngineCall_FWD_DEFINED__ equ <>
  endif
  ifndef __ISpPrivateEngineCallEx_FWD_DEFINED__
    __ISpPrivateEngineCallEx_FWD_DEFINED__ equ <>
  endif
  ifndef __SpDataKey_FWD_DEFINED__
    __SpDataKey_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __SpObjectTokenEnum_FWD_DEFINED__
    __SpObjectTokenEnum_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __SpPhraseBuilder_FWD_DEFINED__
    __SpPhraseBuilder_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __SpITNProcessor_FWD_DEFINED__
    __SpITNProcessor_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __SpGrammarCompiler_FWD_DEFINED__
    __SpGrammarCompiler_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __SpW3CGrammarCompiler_FWD_DEFINED__
    __SpW3CGrammarCompiler_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __SpGramCompBackend_FWD_DEFINED__
    __SpGramCompBackend_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  include oaidl.inc
  include ocidl.inc
  include sapi.inc
  ifdef __cplusplus
    ;[...]
  endif
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef _SAPI_VER
      if _WIN32_WINNT ge 0601h
        _SAPI_VER equ 054h
      elseif _WIN32_WINNT ge 0600h
        _SAPI_VER equ 053h
      else
        _SAPI_VER equ 051h
      endif
    endif
    if _SAPI_VER ge 053h
      SPRECOEXTENSION equ <L("RecoExtension")>
      SPALTERNATESCLSID equ <L("AlternatesCLSID")>
      SR_LOCALIZED_DESCRIPTION equ <L("Description")>
      externdef __MIDL_itf_sapiddk_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_sapiddk_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ISpTokenUI_INTERFACE_DEFINED__
        __ISpTokenUI_INTERFACE_DEFINED__ equ <>
        externdef IID_ISpTokenUI:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpTokenUIVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpTokenUIVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISpTokenUI, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpTokenUI
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpTokenUI
            DECLSPEC_XFGVIRT(ISpTokenUI, IsUISupported)
            STD_METHOD IsUISupported, :ptr ISpTokenUI, :LPCWSTR, :ptr, :ULONG, :ptr IUnknown, :ptr BOOL
            DECLSPEC_XFGVIRT(ISpTokenUI, DisplayUI)
            STD_METHOD DisplayUI, :ptr ISpTokenUI, :HWND, :LPCWSTR, :LPCWSTR, :ptr, :ULONG, :ptr ISpObjectToken, :ptr IUnknown
            ??Interface equ <>
            END_INTERFACE
          ISpTokenUIVtbl ends
          ISpTokenUI struct
            lpVtbl POINTER ?
          ISpTokenUI ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __ISpObjectTokenEnumBuilder_INTERFACE_DEFINED__
        __ISpObjectTokenEnumBuilder_INTERFACE_DEFINED__ equ <>
        externdef IID_ISpObjectTokenEnumBuilder:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpObjectTokenEnumBuilderVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpObjectTokenEnumBuilderVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISpObjectTokenEnumBuilder, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpObjectTokenEnumBuilder
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpObjectTokenEnumBuilder
            DECLSPEC_XFGVIRT(IEnumSpObjectTokens, Next)
            STD_METHOD Next, :ptr ISpObjectTokenEnumBuilder, :ULONG, :ptr ptr ISpObjectToken, :ptr ULONG
            DECLSPEC_XFGVIRT(IEnumSpObjectTokens, Skip)
            STD_METHOD Skip, :ptr ISpObjectTokenEnumBuilder, :ULONG
            DECLSPEC_XFGVIRT(IEnumSpObjectTokens, Reset)
            STD_METHOD Reset, :ptr ISpObjectTokenEnumBuilder
            DECLSPEC_XFGVIRT(IEnumSpObjectTokens, Clone)
            STD_METHOD Clone, :ptr ISpObjectTokenEnumBuilder, :ptr ptr IEnumSpObjectTokens
            DECLSPEC_XFGVIRT(IEnumSpObjectTokens, Item)
            STD_METHOD Item, :ptr ISpObjectTokenEnumBuilder, :ULONG, :ptr ptr ISpObjectToken
            DECLSPEC_XFGVIRT(IEnumSpObjectTokens, GetCount)
            STD_METHOD GetCount, :ptr ISpObjectTokenEnumBuilder, :ptr ULONG
            DECLSPEC_XFGVIRT(ISpObjectTokenEnumBuilder, SetAttribs)
            STD_METHOD SetAttribs, :ptr ISpObjectTokenEnumBuilder, :LPCWSTR, :LPCWSTR
            DECLSPEC_XFGVIRT(ISpObjectTokenEnumBuilder, AddTokens)
            STD_METHOD AddTokens, :ptr ISpObjectTokenEnumBuilder, :ULONG, :ptr ptr ISpObjectToken
            DECLSPEC_XFGVIRT(ISpObjectTokenEnumBuilder, AddTokensFromDataKey)
            STD_METHOD AddTokensFromDataKey, :ptr ISpObjectTokenEnumBuilder, :ptr ISpDataKey, :LPCWSTR, :LPCWSTR
            DECLSPEC_XFGVIRT(ISpObjectTokenEnumBuilder, AddTokensFromTokenEnum)
            STD_METHOD AddTokensFromTokenEnum, :ptr ISpObjectTokenEnumBuilder, :ptr IEnumSpObjectTokens
            DECLSPEC_XFGVIRT(ISpObjectTokenEnumBuilder, Sort)
            STD_METHOD Sort, :ptr ISpObjectTokenEnumBuilder, :LPCWSTR
            ??Interface equ <>
            END_INTERFACE
          ISpObjectTokenEnumBuilderVtbl ends
          ISpObjectTokenEnumBuilder struct
            lpVtbl POINTER ?
          ISpObjectTokenEnumBuilder ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      if 0
        ;[...]
      else
        DECLARE_HANDLE SPWORDHANDLE
        DECLARE_HANDLE SPRULEHANDLE
        DECLARE_HANDLE SPGRAMMARHANDLE
        DECLARE_HANDLE SPRECOCONTEXTHANDLE
        DECLARE_HANDLE SPPHRASERULEHANDLE
        DECLARE_HANDLE SPPHRASEPROPERTYHANDLE
        DECLARE_HANDLE SPTRANSITIONID
      endif
      externdef __MIDL_itf_sapiddk_0000_0002_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_sapiddk_0000_0002_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ISpErrorLog_INTERFACE_DEFINED__
        __ISpErrorLog_INTERFACE_DEFINED__ equ <>
        externdef IID_ISpErrorLog:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpErrorLogVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpErrorLogVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISpErrorLog, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpErrorLog
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpErrorLog
            DECLSPEC_XFGVIRT(ISpErrorLog, AddError)
            STD_METHOD AddError, :ptr ISpErrorLog, :SDWORD, :HRESULT, :LPCWSTR, :LPCWSTR, :DWORD
            ??Interface equ <>
            END_INTERFACE
          ISpErrorLogVtbl ends
          ISpErrorLog struct
            lpVtbl POINTER ?
          ISpErrorLog ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __ISpGrammarCompiler_INTERFACE_DEFINED__
        __ISpGrammarCompiler_INTERFACE_DEFINED__ equ <>
        externdef IID_ISpGrammarCompiler:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpGrammarCompilerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpGrammarCompilerVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISpGrammarCompiler, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpGrammarCompiler
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpGrammarCompiler
            DECLSPEC_XFGVIRT(ISpGrammarCompiler, CompileStream)
            STD_METHOD CompileStream, :ptr ISpGrammarCompiler, :ptr IStream, :ptr IStream, :ptr IStream, :ptr IUnknown, :ptr ISpErrorLog, :DWORD
            ??Interface equ <>
            END_INTERFACE
          ISpGrammarCompilerVtbl ends
          ISpGrammarCompiler struct
            lpVtbl POINTER ?
          ISpGrammarCompiler ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __ISpGramCompBackend_INTERFACE_DEFINED__
        __ISpGramCompBackend_INTERFACE_DEFINED__ equ <>
        externdef IID_ISpGramCompBackend:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpGramCompBackendVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpGramCompBackendVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISpGramCompBackend, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpGramCompBackend
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpGramCompBackend
            DECLSPEC_XFGVIRT(ISpGrammarBuilder, ResetGrammar)
            STD_METHOD ResetGrammar, :ptr ISpGramCompBackend, :WORD
            DECLSPEC_XFGVIRT(ISpGrammarBuilder, GetRule)
            STD_METHOD GetRule, :ptr ISpGramCompBackend, :LPCWSTR, :DWORD, :DWORD, :BOOL, :ptr SPSTATEHANDLE
            DECLSPEC_XFGVIRT(ISpGrammarBuilder, ClearRule)
            STD_METHOD ClearRule, :ptr ISpGramCompBackend, :SPSTATEHANDLE
            DECLSPEC_XFGVIRT(ISpGrammarBuilder, CreateNewState)
            STD_METHOD CreateNewState, :ptr ISpGramCompBackend, :SPSTATEHANDLE, :ptr SPSTATEHANDLE
            DECLSPEC_XFGVIRT(ISpGrammarBuilder, AddWordTransition)
            STD_METHOD AddWordTransition, :ptr ISpGramCompBackend, :SPSTATEHANDLE, :SPSTATEHANDLE, :LPCWSTR, :LPCWSTR, :SPGRAMMARWORDTYPE, :REAL4, :ptr SPPROPERTYINFO
            DECLSPEC_XFGVIRT(ISpGrammarBuilder, AddRuleTransition)
            STD_METHOD AddRuleTransition, :ptr ISpGramCompBackend, :SPSTATEHANDLE, :SPSTATEHANDLE, :SPSTATEHANDLE, :REAL4, :ptr SPPROPERTYINFO
            DECLSPEC_XFGVIRT(ISpGrammarBuilder, AddResource)
            STD_METHOD AddResource, :ptr ISpGramCompBackend, :SPSTATEHANDLE, :LPCWSTR, :LPCWSTR
            DECLSPEC_XFGVIRT(ISpGrammarBuilder, Commit)
            STD_METHOD Commit, :ptr ISpGramCompBackend, :DWORD
            DECLSPEC_XFGVIRT(ISpGramCompBackend, SetSaveObjects)
            STD_METHOD SetSaveObjects, :ptr ISpGramCompBackend, :ptr IStream, :ptr ISpErrorLog
            DECLSPEC_XFGVIRT(ISpGramCompBackend, InitFromBinaryGrammar)
            STD_METHOD InitFromBinaryGrammar, :ptr ISpGramCompBackend, :ptr SPBINARYGRAMMAR
            ??Interface equ <>
            END_INTERFACE
          ISpGramCompBackendVtbl ends
          ISpGramCompBackend struct
            lpVtbl POINTER ?
          ISpGramCompBackend ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __ISpITNProcessor_INTERFACE_DEFINED__
        __ISpITNProcessor_INTERFACE_DEFINED__ equ <>
        externdef IID_ISpITNProcessor:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpITNProcessorVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpITNProcessorVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISpITNProcessor, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpITNProcessor
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpITNProcessor
            DECLSPEC_XFGVIRT(ISpITNProcessor, LoadITNGrammar)
            STD_METHOD LoadITNGrammar, :ptr ISpITNProcessor, :LPWSTR
            DECLSPEC_XFGVIRT(ISpITNProcessor, ITNPhrase)
            STD_METHOD ITNPhrase, :ptr ISpITNProcessor, :ptr ISpPhraseBuilder
            ??Interface equ <>
            END_INTERFACE
          ISpITNProcessorVtbl ends
          ISpITNProcessor struct
            lpVtbl POINTER ?
          ISpITNProcessor ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __ISpPhraseBuilder_INTERFACE_DEFINED__
        __ISpPhraseBuilder_INTERFACE_DEFINED__ equ <>
        externdef IID_ISpPhraseBuilder:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpPhraseBuilderVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpPhraseBuilderVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISpPhraseBuilder, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpPhraseBuilder
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpPhraseBuilder
            DECLSPEC_XFGVIRT(ISpPhrase, GetPhrase)
            STD_METHOD GetPhrase, :ptr ISpPhraseBuilder, :ptr ptr SPPHRASE
            DECLSPEC_XFGVIRT(ISpPhrase, GetSerializedPhrase)
            STD_METHOD GetSerializedPhrase, :ptr ISpPhraseBuilder, :ptr ptr SPSERIALIZEDPHRASE
            DECLSPEC_XFGVIRT(ISpPhrase, GetText)
            STD_METHOD GetText, :ptr ISpPhraseBuilder, :ULONG, :ULONG, :BOOL, :ptr LPWSTR, :ptr BYTE
            DECLSPEC_XFGVIRT(ISpPhrase, Discard)
            STD_METHOD Discard, :ptr ISpPhraseBuilder, :DWORD
            DECLSPEC_XFGVIRT(ISpPhraseBuilder, InitFromPhrase)
            STD_METHOD InitFromPhrase, :ptr ISpPhraseBuilder, :ptr SPPHRASE
            DECLSPEC_XFGVIRT(ISpPhraseBuilder, InitFromSerializedPhrase)
            STD_METHOD InitFromSerializedPhrase, :ptr ISpPhraseBuilder, :ptr SPSERIALIZEDPHRASE
            DECLSPEC_XFGVIRT(ISpPhraseBuilder, AddElements)
            STD_METHOD AddElements, :ptr ISpPhraseBuilder, :ULONG, :ptr SPPHRASEELEMENT
            DECLSPEC_XFGVIRT(ISpPhraseBuilder, AddRules)
            STD_METHOD AddRules, :ptr ISpPhraseBuilder, :SPPHRASERULEHANDLE, :ptr SPPHRASERULE, :ptr SPPHRASERULEHANDLE
            DECLSPEC_XFGVIRT(ISpPhraseBuilder, AddProperties)
            STD_METHOD AddProperties, :ptr ISpPhraseBuilder, :SPPHRASEPROPERTYHANDLE, :ptr SPPHRASEPROPERTY, :ptr SPPHRASEPROPERTYHANDLE
            DECLSPEC_XFGVIRT(ISpPhraseBuilder, AddReplacements)
            STD_METHOD AddReplacements, :ptr ISpPhraseBuilder, :ULONG, :ptr SPPHRASEREPLACEMENT
            ??Interface equ <>
            END_INTERFACE
          ISpPhraseBuilderVtbl ends
          ISpPhraseBuilder struct
            lpVtbl POINTER ?
          ISpPhraseBuilder ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      if Defined(__cplusplus)
        ;[...]
      else
        ISpTask typedef ptr
      endif
      if Defined(__cplusplus)
        ;[...]
      else
        ISpThreadTask typedef ptr
      endif
      externdef __MIDL_itf_sapiddk_0000_0007_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_sapiddk_0000_0007_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ISpThreadControl_INTERFACE_DEFINED__
        __ISpThreadControl_INTERFACE_DEFINED__ equ <>
        externdef IID_ISpThreadControl:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpThreadControlVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpThreadControlVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISpThreadControl, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpThreadControl
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpThreadControl
            DECLSPEC_XFGVIRT(ISpNotifySink, Notify)
            STD_METHOD Notify, :ptr ISpThreadControl
            DECLSPEC_XFGVIRT(ISpThreadControl, StartThread)
            STD_METHOD StartThread, :ptr ISpThreadControl, :DWORD, :ptr HWND
            DECLSPEC_XFGVIRT(ISpThreadControl, WaitForThreadDone)
            STD_METHOD WaitForThreadDone, :ptr ISpThreadControl, :BOOL, :ptr HRESULT, :ULONG
            DECLSPEC_XFGVIRT(ISpThreadControl, TerminateThread)
            STD_METHOD TerminateThread, :ptr ISpThreadControl
            DECLSPEC_XFGVIRT(ISpThreadControl, ThreadHandle)
            STD_METHOD ThreadHandle, :ptr ISpThreadControl
            DECLSPEC_XFGVIRT(ISpThreadControl, ThreadId)
            STD_METHOD ThreadId, :ptr ISpThreadControl
            DECLSPEC_XFGVIRT(ISpThreadControl, NotifyEvent)
            STD_METHOD NotifyEvent, :ptr ISpThreadControl
            DECLSPEC_XFGVIRT(ISpThreadControl, WindowHandle)
            STD_METHOD WindowHandle, :ptr ISpThreadControl
            DECLSPEC_XFGVIRT(ISpThreadControl, ThreadCompleteEvent)
            STD_METHOD ThreadCompleteEvent, :ptr ISpThreadControl
            DECLSPEC_XFGVIRT(ISpThreadControl, ExitThreadEvent)
            STD_METHOD ExitThreadEvent, :ptr ISpThreadControl
            ??Interface equ <>
            END_INTERFACE
          ISpThreadControlVtbl ends
          ISpThreadControl struct
            lpVtbl POINTER ?
          ISpThreadControl ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      SPTMTHREADINFO struct
        lPoolSize SDWORD ?
        lPriority SDWORD ?
        ulConcurrencyLimit ULONG ?
        ulMaxQuickAllocThreads ULONG ?
      SPTMTHREADINFO ends
      externdef __MIDL_itf_sapiddk_0000_0008_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_sapiddk_0000_0008_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ISpTaskManager_INTERFACE_DEFINED__
        __ISpTaskManager_INTERFACE_DEFINED__ equ <>
        externdef IID_ISpTaskManager:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpTaskManagerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpTaskManagerVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISpTaskManager, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpTaskManager
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpTaskManager
            DECLSPEC_XFGVIRT(ISpTaskManager, SetThreadPoolInfo)
            STD_METHOD SetThreadPoolInfo, :ptr ISpTaskManager, :ptr SPTMTHREADINFO
            DECLSPEC_XFGVIRT(ISpTaskManager, GetThreadPoolInfo)
            STD_METHOD GetThreadPoolInfo, :ptr ISpTaskManager, :ptr SPTMTHREADINFO
            DECLSPEC_XFGVIRT(ISpTaskManager, QueueTask)
            STD_METHOD QueueTask, :ptr ISpTaskManager, :ptr ISpTask, :ptr, :HANDLE, :ptr DWORD, :ptr DWORD
            DECLSPEC_XFGVIRT(ISpTaskManager, CreateReoccurringTask)
            STD_METHOD CreateReoccurringTask, :ptr ISpTaskManager, :ptr ISpTask, :ptr, :HANDLE, :ptr ptr ISpNotifySink
            DECLSPEC_XFGVIRT(ISpTaskManager, CreateThreadControl)
            STD_METHOD CreateThreadControl, :ptr ISpTaskManager, :ptr ISpThreadTask, :ptr, :SDWORD, :ptr ptr ISpThreadControl
            DECLSPEC_XFGVIRT(ISpTaskManager, TerminateTask)
            STD_METHOD TerminateTask, :ptr ISpTaskManager, :DWORD, :ULONG
            DECLSPEC_XFGVIRT(ISpTaskManager, TerminateTaskGroup)
            STD_METHOD TerminateTaskGroup, :ptr ISpTaskManager, :DWORD, :ULONG
            ??Interface equ <>
            END_INTERFACE
          ISpTaskManagerVtbl ends
          ISpTaskManager struct
            lpVtbl POINTER ?
          ISpTaskManager ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      SPVSKIPTYPE typedef SDWORD
      SPVST_SENTENCE equ

      SPVESACTIONS typedef SDWORD
      SPVES_CONTINUE equ 0
      SPVES_ABORT equ
      SPVES_SKIP equ
      SPVES_RATE equ
      SPVES_VOLUME equ

      externdef __MIDL_itf_sapiddk_0000_0009_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_sapiddk_0000_0009_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ISpTTSEngineSite_INTERFACE_DEFINED__
        __ISpTTSEngineSite_INTERFACE_DEFINED__ equ <>
        externdef IID_ISpTTSEngineSite:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpTTSEngineSiteVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpTTSEngineSiteVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISpTTSEngineSite, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpTTSEngineSite
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpTTSEngineSite
            DECLSPEC_XFGVIRT(ISpEventSink, AddEvents)
            STD_METHOD AddEvents, :ptr ISpTTSEngineSite, :ptr SPEVENT, :ULONG
            DECLSPEC_XFGVIRT(ISpEventSink, GetEventInterest)
            STD_METHOD GetEventInterest, :ptr ISpTTSEngineSite, :ptr ULONGLONG
            DECLSPEC_XFGVIRT(ISpTTSEngineSite, GetActions)
            STD_METHOD GetActions, :ptr ISpTTSEngineSite
            DECLSPEC_XFGVIRT(ISpTTSEngineSite, Write)
            STD_METHOD Write, :ptr ISpTTSEngineSite, :ptr, :ULONG, :ptr ULONG
            DECLSPEC_XFGVIRT(ISpTTSEngineSite, GetRate)
            STD_METHOD GetRate, :ptr ISpTTSEngineSite, :ptr SDWORD
            DECLSPEC_XFGVIRT(ISpTTSEngineSite, GetVolume)
            STD_METHOD GetVolume, :ptr ISpTTSEngineSite, :ptr USHORT
            DECLSPEC_XFGVIRT(ISpTTSEngineSite, GetSkipInfo)
            STD_METHOD GetSkipInfo, :ptr ISpTTSEngineSite, :ptr SPVSKIPTYPE, :ptr SDWORD
            DECLSPEC_XFGVIRT(ISpTTSEngineSite, CompleteSkip)
            STD_METHOD CompleteSkip, :ptr ISpTTSEngineSite, :SDWORD
            ??Interface equ <>
            END_INTERFACE
          ISpTTSEngineSiteVtbl ends
          ISpTTSEngineSite struct
            lpVtbl POINTER ?
          ISpTTSEngineSite ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      SPVTEXTFRAG struct
        pNext POINTER ?
        State SPVSTATE <>
        pTextStart LPCWSTR ?
        ulTextLen ULONG ?
        ulTextSrcOffset ULONG ?
      SPVTEXTFRAG ends
      externdef __MIDL_itf_sapiddk_0000_0010_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_sapiddk_0000_0010_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ISpTTSEngine_INTERFACE_DEFINED__
        __ISpTTSEngine_INTERFACE_DEFINED__ equ <>
        externdef IID_ISpTTSEngine:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpTTSEngineVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpTTSEngineVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISpTTSEngine, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpTTSEngine
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpTTSEngine
            DECLSPEC_XFGVIRT(ISpTTSEngine, Speak)
            STD_METHOD Speak, :ptr ISpTTSEngine, :DWORD, :REFGUID, :ptr WAVEFORMATEX, :ptr SPVTEXTFRAG, :ptr ISpTTSEngineSite
            DECLSPEC_XFGVIRT(ISpTTSEngine, GetOutputFormat)
            STD_METHOD GetOutputFormat, :ptr ISpTTSEngine, :ptr GUID, :ptr WAVEFORMATEX, :ptr GUID, :ptr ptr WAVEFORMATEX
            ??Interface equ <>
            END_INTERFACE
          ISpTTSEngineVtbl ends
          ISpTTSEngine struct
            lpVtbl POINTER ?
          ISpTTSEngine ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      SPWORDENTRY struct
        hWord SPWORDHANDLE ?
        LangID WORD ?
        pszDisplayText POINTER ?
        pszLexicalForm POINTER ?
        aPhoneId POINTER ?
        pvClientContext POINTER ?
      SPWORDENTRY ends
      SPRULEENTRY struct
        hRule SPRULEHANDLE ?
        hInitialState SPSTATEHANDLE ?
        Attributes DWORD ?
        pvClientRuleContext POINTER ?
        pvClientGrammarContext POINTER ?
      SPRULEENTRY ends
      SPTRANSITIONTYPE typedef SDWORD
      SPTRANSEPSILON equ 0
      SPTRANSWORD equ
      SPTRANSRULE equ
      SPTRANSTEXTBUF equ
      SPTRANSWILDCARD equ
      SPTRANSDICTATION equ

      SPTRANSITIONENTRY struct
        ID SPTRANSITIONID ?
        hNextState SPSTATEHANDLE ?
        Type_ BYTE ?
        RequiredConfidence SBYTE ?
        struct
          fHasProperty DWORD ?
        ends
        Weight REAL4 ?
        union
          struct
            hRuleInitialState SPSTATEHANDLE ?
            hRule SPRULEHANDLE ?
            pvClientRuleContext POINTER ?
          ends
          struct
            hWord SPWORDHANDLE ?
            pvClientWordContext POINTER ?
          ends
          struct
            pvGrammarCookie POINTER ?
          ends
        ends
      SPTRANSITIONENTRY ends
      SPTRANSITIONPROPERTY struct
        pszName LPCWSTR ?
        ulId ULONG ?
        pszValue LPCWSTR ?
        vValue VARIANT <>
      SPTRANSITIONPROPERTY ends
      SPSTATEINFO struct
        cAllocatedEntries ULONG ?
        pTransitions POINTER ?
        cEpsilons ULONG ?
        cRules ULONG ?
        cWords ULONG ?
        cSpecialTransitions ULONG ?
      SPSTATEINFO ends
      SPPATHENTRY struct
        hTransition SPTRANSITIONID ?
        elem SPPHRASEELEMENT <>
      SPPATHENTRY ends
      externdef __MIDL_itf_sapiddk_0000_0011_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_sapiddk_0000_0011_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ISpCFGInterpreterSite_INTERFACE_DEFINED__
        __ISpCFGInterpreterSite_INTERFACE_DEFINED__ equ <>
        externdef IID_ISpCFGInterpreterSite:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpCFGInterpreterSiteVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpCFGInterpreterSiteVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISpCFGInterpreterSite, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpCFGInterpreterSite
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpCFGInterpreterSite
            DECLSPEC_XFGVIRT(ISpCFGInterpreterSite, AddTextReplacement)
            STD_METHOD AddTextReplacement, :ptr ISpCFGInterpreterSite, :ptr SPPHRASEREPLACEMENT
            DECLSPEC_XFGVIRT(ISpCFGInterpreterSite, AddProperty)
            STD_METHOD AddProperty, :ptr ISpCFGInterpreterSite, :ptr SPPHRASEPROPERTY
            DECLSPEC_XFGVIRT(ISpCFGInterpreterSite, GetResourceValue)
            STD_METHOD GetResourceValue, :ptr ISpCFGInterpreterSite, :LPCWSTR, :ptr LPWSTR
            ??Interface equ <>
            END_INTERFACE
          ISpCFGInterpreterSiteVtbl ends
          ISpCFGInterpreterSite struct
            lpVtbl POINTER ?
          ISpCFGInterpreterSite ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __ISpCFGInterpreter_INTERFACE_DEFINED__
        __ISpCFGInterpreter_INTERFACE_DEFINED__ equ <>
        externdef IID_ISpCFGInterpreter:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpCFGInterpreterVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpCFGInterpreterVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISpCFGInterpreter, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpCFGInterpreter
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpCFGInterpreter
            DECLSPEC_XFGVIRT(ISpCFGInterpreter, InitGrammar)
            STD_METHOD InitGrammar, :ptr ISpCFGInterpreter, :LPCWSTR, :ptr ptr
            DECLSPEC_XFGVIRT(ISpCFGInterpreter, Interpret)
            STD_METHOD Interpret, :ptr ISpCFGInterpreter, :ptr ISpPhraseBuilder, :ULONG, :ULONG, :ptr ISpCFGInterpreterSite
            ??Interface equ <>
            END_INTERFACE
          ISpCFGInterpreterVtbl ends
          ISpCFGInterpreter struct
            lpVtbl POINTER ?
          ISpCFGInterpreter ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      SPCFGNOTIFY typedef SDWORD
      SPCFGN_ADD equ 0
      SPCFGN_REMOVE equ
      SPCFGN_INVALIDATE equ
      SPCFGN_ACTIVATE equ
      SPCFGN_DEACTIVATE equ

      SPRESULTTYPE typedef SDWORD
      SPRT_CFG equ 0
      SPRT_SLM equ 1
      SPRT_PROPRIETARY equ 2
      SPRT_FALSE_RECOGNITION equ
      SPRT_TYPE_MASK equ 3
      SPRT_EMULATED equ
      SPRT_EXTENDABLE_PARSE equ

      SPPHRASEALT struct
        pPhrase POINTER ?
        ulStartElementInParent ULONG ?
        cElementsInParent ULONG ?
        cElementsInAlternate ULONG ?
        pvAltExtra POINTER ?
        cbAltExtra ULONG ?
      SPPHRASEALT ends
      tagSPPHRASEALT typedef SPPHRASEALT
      SPRECORESULTINFO struct
        cbSize ULONG ?
        eResultType SPRESULTTYPE ?
        fHypothesis BOOL ?
        fProprietaryAutoPause BOOL ?
        ullStreamPosStart ULONGLONG ?
        ullStreamPosEnd ULONGLONG ?
        hGrammar SPGRAMMARHANDLE ?
        ulSizeEngineData ULONG ?
        pvEngineData POINTER ?
        pPhrase POINTER ?
        aPhraseAlts POINTER ?
        ulNumAlts ULONG ?
      SPRECORESULTINFO ends
      if 0
        ;[...]
      else
        ullStreamTimeStart typedef SPRECORESULTINFOEX
      endif
      SPWORDINFOOPT typedef SDWORD
      SPWIO_NONE equ 0
      SPWIO_WANT_TEXT equ 1

      SPRULEINFOOPT typedef SDWORD
      SPRIO_NONE equ 0

      SPPARSEINFO struct
        cbSize ULONG ?
        hRule SPRULEHANDLE ?
        ullAudioStreamPosition ULONGLONG ?
        ulAudioSize ULONG ?
        cTransitions ULONG ?
        pPath POINTER ?
        SREngineID GUID <>
        ulSREnginePrivateDataSize ULONG ?
        pSREnginePrivateData POINTER ?
        fHypothesis BOOL ?
      SPPARSEINFO ends
      externdef __MIDL_itf_sapiddk_0000_0013_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_sapiddk_0000_0013_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ISpSREngineSite_INTERFACE_DEFINED__
        __ISpSREngineSite_INTERFACE_DEFINED__ equ <>
        externdef IID_ISpSREngineSite:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpSREngineSiteVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpSREngineSiteVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISpSREngineSite, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpSREngineSite
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpSREngineSite
            DECLSPEC_XFGVIRT(ISpSREngineSite, Read)
            STD_METHOD Read, :ptr ISpSREngineSite, :ptr, :ULONG, :ptr ULONG
            DECLSPEC_XFGVIRT(ISpSREngineSite, DataAvailable)
            STD_METHOD DataAvailable, :ptr ISpSREngineSite, :ptr ULONG
            DECLSPEC_XFGVIRT(ISpSREngineSite, SetBufferNotifySize)
            STD_METHOD SetBufferNotifySize, :ptr ISpSREngineSite, :ULONG
            DECLSPEC_XFGVIRT(ISpSREngineSite, ParseFromTransitions)
            STD_METHOD ParseFromTransitions, :ptr ISpSREngineSite, :ptr SPPARSEINFO, :ptr ptr ISpPhraseBuilder
            DECLSPEC_XFGVIRT(ISpSREngineSite, Recognition)
            STD_METHOD Recognition, :ptr ISpSREngineSite, :ptr SPRECORESULTINFO
            DECLSPEC_XFGVIRT(ISpSREngineSite, AddEvent)
            STD_METHOD AddEvent, :ptr ISpSREngineSite, :ptr SPEVENT, :SPRECOCONTEXTHANDLE
            DECLSPEC_XFGVIRT(ISpSREngineSite, Synchronize)
            STD_METHOD Synchronize, :ptr ISpSREngineSite, :ULONGLONG
            DECLSPEC_XFGVIRT(ISpSREngineSite, GetWordInfo)
            STD_METHOD GetWordInfo, :ptr ISpSREngineSite, :ptr SPWORDENTRY, :SPWORDINFOOPT
            DECLSPEC_XFGVIRT(ISpSREngineSite, SetWordClientContext)
            STD_METHOD SetWordClientContext, :ptr ISpSREngineSite, :SPWORDHANDLE, :ptr
            DECLSPEC_XFGVIRT(ISpSREngineSite, GetRuleInfo)
            STD_METHOD GetRuleInfo, :ptr ISpSREngineSite, :ptr SPRULEENTRY, :SPRULEINFOOPT
            DECLSPEC_XFGVIRT(ISpSREngineSite, SetRuleClientContext)
            STD_METHOD SetRuleClientContext, :ptr ISpSREngineSite, :SPRULEHANDLE, :ptr
            DECLSPEC_XFGVIRT(ISpSREngineSite, GetStateInfo)
            STD_METHOD GetStateInfo, :ptr ISpSREngineSite, :SPSTATEHANDLE, :ptr SPSTATEINFO
            DECLSPEC_XFGVIRT(ISpSREngineSite, GetResource)
            STD_METHOD GetResource, :ptr ISpSREngineSite, :SPRULEHANDLE, :LPCWSTR, :ptr LPWSTR
            DECLSPEC_XFGVIRT(ISpSREngineSite, GetTransitionProperty)
            STD_METHOD GetTransitionProperty, :ptr ISpSREngineSite, :SPTRANSITIONID, :ptr ptr SPTRANSITIONPROPERTY
            DECLSPEC_XFGVIRT(ISpSREngineSite, IsAlternate)
            STD_METHOD IsAlternate, :ptr ISpSREngineSite, :SPRULEHANDLE, :SPRULEHANDLE
            DECLSPEC_XFGVIRT(ISpSREngineSite, GetMaxAlternates)
            STD_METHOD GetMaxAlternates, :ptr ISpSREngineSite, :SPRULEHANDLE, :ptr ULONG
            DECLSPEC_XFGVIRT(ISpSREngineSite, GetContextMaxAlternates)
            STD_METHOD GetContextMaxAlternates, :ptr ISpSREngineSite, :SPRECOCONTEXTHANDLE, :ptr ULONG
            DECLSPEC_XFGVIRT(ISpSREngineSite, UpdateRecoPos)
            STD_METHOD UpdateRecoPos, :ptr ISpSREngineSite, :ULONGLONG
            ??Interface equ <>
            END_INTERFACE
          ISpSREngineSiteVtbl ends
          ISpSREngineSite struct
            lpVtbl POINTER ?
          ISpSREngineSite ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __ISpSREngineSite2_INTERFACE_DEFINED__
        __ISpSREngineSite2_INTERFACE_DEFINED__ equ <>
        externdef IID_ISpSREngineSite2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpSREngineSite2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpSREngineSite2Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISpSREngineSite2, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpSREngineSite2
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpSREngineSite2
            DECLSPEC_XFGVIRT(ISpSREngineSite, Read)
            STD_METHOD Read, :ptr ISpSREngineSite2, :ptr, :ULONG, :ptr ULONG
            DECLSPEC_XFGVIRT(ISpSREngineSite, DataAvailable)
            STD_METHOD DataAvailable, :ptr ISpSREngineSite2, :ptr ULONG
            DECLSPEC_XFGVIRT(ISpSREngineSite, SetBufferNotifySize)
            STD_METHOD SetBufferNotifySize, :ptr ISpSREngineSite2, :ULONG
            DECLSPEC_XFGVIRT(ISpSREngineSite, ParseFromTransitions)
            STD_METHOD ParseFromTransitions, :ptr ISpSREngineSite2, :ptr SPPARSEINFO, :ptr ptr ISpPhraseBuilder
            DECLSPEC_XFGVIRT(ISpSREngineSite, Recognition)
            STD_METHOD Recognition, :ptr ISpSREngineSite2, :ptr SPRECORESULTINFO
            DECLSPEC_XFGVIRT(ISpSREngineSite, AddEvent)
            STD_METHOD AddEvent, :ptr ISpSREngineSite2, :ptr SPEVENT, :SPRECOCONTEXTHANDLE
            DECLSPEC_XFGVIRT(ISpSREngineSite, Synchronize)
            STD_METHOD Synchronize, :ptr ISpSREngineSite2, :ULONGLONG
            DECLSPEC_XFGVIRT(ISpSREngineSite, GetWordInfo)
            STD_METHOD GetWordInfo, :ptr ISpSREngineSite2, :ptr SPWORDENTRY, :SPWORDINFOOPT
            DECLSPEC_XFGVIRT(ISpSREngineSite, SetWordClientContext)
            STD_METHOD SetWordClientContext, :ptr ISpSREngineSite2, :SPWORDHANDLE, :ptr
            DECLSPEC_XFGVIRT(ISpSREngineSite, GetRuleInfo)
            STD_METHOD GetRuleInfo, :ptr ISpSREngineSite2, :ptr SPRULEENTRY, :SPRULEINFOOPT
            DECLSPEC_XFGVIRT(ISpSREngineSite, SetRuleClientContext)
            STD_METHOD SetRuleClientContext, :ptr ISpSREngineSite2, :SPRULEHANDLE, :ptr
            DECLSPEC_XFGVIRT(ISpSREngineSite, GetStateInfo)
            STD_METHOD GetStateInfo, :ptr ISpSREngineSite2, :SPSTATEHANDLE, :ptr SPSTATEINFO
            DECLSPEC_XFGVIRT(ISpSREngineSite, GetResource)
            STD_METHOD GetResource, :ptr ISpSREngineSite2, :SPRULEHANDLE, :LPCWSTR, :ptr LPWSTR
            DECLSPEC_XFGVIRT(ISpSREngineSite, GetTransitionProperty)
            STD_METHOD GetTransitionProperty, :ptr ISpSREngineSite2, :SPTRANSITIONID, :ptr ptr SPTRANSITIONPROPERTY
            DECLSPEC_XFGVIRT(ISpSREngineSite, IsAlternate)
            STD_METHOD IsAlternate, :ptr ISpSREngineSite2, :SPRULEHANDLE, :SPRULEHANDLE
            DECLSPEC_XFGVIRT(ISpSREngineSite, GetMaxAlternates)
            STD_METHOD GetMaxAlternates, :ptr ISpSREngineSite2, :SPRULEHANDLE, :ptr ULONG
            DECLSPEC_XFGVIRT(ISpSREngineSite, GetContextMaxAlternates)
            STD_METHOD GetContextMaxAlternates, :ptr ISpSREngineSite2, :SPRECOCONTEXTHANDLE, :ptr ULONG
            DECLSPEC_XFGVIRT(ISpSREngineSite, UpdateRecoPos)
            STD_METHOD UpdateRecoPos, :ptr ISpSREngineSite2, :ULONGLONG
            DECLSPEC_XFGVIRT(ISpSREngineSite2, AddEventEx)
            STD_METHOD AddEventEx, :ptr ISpSREngineSite2, :ptr SPEVENTEX, :SPRECOCONTEXTHANDLE
            DECLSPEC_XFGVIRT(ISpSREngineSite2, UpdateRecoPosEx)
            STD_METHOD UpdateRecoPosEx, :ptr ISpSREngineSite2, :ULONGLONG, :ULONGLONG
            DECLSPEC_XFGVIRT(ISpSREngineSite2, GetRuleTransition)
            STD_METHOD GetRuleTransition, :ptr ISpSREngineSite2, :ULONG, :ULONG, :ptr SPTRANSITIONENTRY
            DECLSPEC_XFGVIRT(ISpSREngineSite2, RecognitionEx)
            STD_METHOD RecognitionEx, :ptr ISpSREngineSite2, :ptr SPRECORESULTINFOEX
            ??Interface equ <>
            END_INTERFACE
          ISpSREngineSite2Vtbl ends
          ISpSREngineSite2 struct
            lpVtbl POINTER ?
          ISpSREngineSite2 ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      SPPROPSRC typedef SDWORD
      SPPROPSRC_RECO_INST equ 0
      SPPROPSRC_RECO_CTX equ
      SPPROPSRC_RECO_GRAMMAR equ

      externdef __MIDL_itf_sapiddk_0000_0015_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_sapiddk_0000_0015_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ISpSREngine_INTERFACE_DEFINED__
        __ISpSREngine_INTERFACE_DEFINED__ equ <>
        externdef IID_ISpSREngine:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpSREngineVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpSREngineVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISpSREngine, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpSREngine
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpSREngine
            DECLSPEC_XFGVIRT(ISpSREngine, SetSite)
            STD_METHOD SetSite, :ptr ISpSREngine, :ptr ISpSREngineSite
            DECLSPEC_XFGVIRT(ISpSREngine, GetInputAudioFormat)
            STD_METHOD GetInputAudioFormat, :ptr ISpSREngine, :ptr GUID, :ptr WAVEFORMATEX, :ptr GUID, :ptr ptr WAVEFORMATEX
            DECLSPEC_XFGVIRT(ISpSREngine, RecognizeStream)
            STD_METHOD RecognizeStream, :ptr ISpSREngine, :REFGUID, :ptr WAVEFORMATEX, :HANDLE, :HANDLE, :HANDLE, :BOOL, :BOOL, :ptr ISpObjectToken
            DECLSPEC_XFGVIRT(ISpSREngine, SetRecoProfile)
            STD_METHOD SetRecoProfile, :ptr ISpSREngine, :ptr ISpObjectToken
            DECLSPEC_XFGVIRT(ISpSREngine, OnCreateGrammar)
            STD_METHOD OnCreateGrammar, :ptr ISpSREngine, :ptr, :SPGRAMMARHANDLE, :ptr ptr
            DECLSPEC_XFGVIRT(ISpSREngine, OnDeleteGrammar)
            STD_METHOD OnDeleteGrammar, :ptr ISpSREngine, :ptr
            DECLSPEC_XFGVIRT(ISpSREngine, LoadProprietaryGrammar)
            STD_METHOD LoadProprietaryGrammar, :ptr ISpSREngine, :ptr, :REFGUID, :LPCWSTR, :ptr, :ULONG, :SPLOADOPTIONS
            DECLSPEC_XFGVIRT(ISpSREngine, UnloadProprietaryGrammar)
            STD_METHOD UnloadProprietaryGrammar, :ptr ISpSREngine, :ptr
            DECLSPEC_XFGVIRT(ISpSREngine, SetProprietaryRuleState)
            STD_METHOD SetProprietaryRuleState, :ptr ISpSREngine, :ptr, :LPCWSTR, :ptr, :SPRULESTATE, :ptr ULONG
            DECLSPEC_XFGVIRT(ISpSREngine, SetProprietaryRuleIdState)
            STD_METHOD SetProprietaryRuleIdState, :ptr ISpSREngine, :ptr, :DWORD, :SPRULESTATE
            DECLSPEC_XFGVIRT(ISpSREngine, LoadSLM)
            STD_METHOD LoadSLM, :ptr ISpSREngine, :ptr, :LPCWSTR
            DECLSPEC_XFGVIRT(ISpSREngine, UnloadSLM)
            STD_METHOD UnloadSLM, :ptr ISpSREngine, :ptr
            DECLSPEC_XFGVIRT(ISpSREngine, SetSLMState)
            STD_METHOD SetSLMState, :ptr ISpSREngine, :ptr, :SPRULESTATE
            DECLSPEC_XFGVIRT(ISpSREngine, SetWordSequenceData)
            STD_METHOD SetWordSequenceData, :ptr ISpSREngine, :ptr, :ptr WCHAR, :ULONG, :ptr SPTEXTSELECTIONINFO
            DECLSPEC_XFGVIRT(ISpSREngine, SetTextSelection)
            STD_METHOD SetTextSelection, :ptr ISpSREngine, :ptr, :ptr SPTEXTSELECTIONINFO
            DECLSPEC_XFGVIRT(ISpSREngine, IsPronounceable)
            STD_METHOD IsPronounceable, :ptr ISpSREngine, :ptr, :LPCWSTR, :ptr SPWORDPRONOUNCEABLE
            DECLSPEC_XFGVIRT(ISpSREngine, OnCreateRecoContext)
            STD_METHOD OnCreateRecoContext, :ptr ISpSREngine, :SPRECOCONTEXTHANDLE, :ptr ptr
            DECLSPEC_XFGVIRT(ISpSREngine, OnDeleteRecoContext)
            STD_METHOD OnDeleteRecoContext, :ptr ISpSREngine, :ptr
            DECLSPEC_XFGVIRT(ISpSREngine, PrivateCall)
            STD_METHOD PrivateCall, :ptr ISpSREngine, :ptr, :PVOID, :ULONG
            DECLSPEC_XFGVIRT(ISpSREngine, SetAdaptationData)
            STD_METHOD SetAdaptationData, :ptr ISpSREngine, :ptr, :ptr WCHAR, :ULONG
            DECLSPEC_XFGVIRT(ISpSREngine, SetPropertyNum)
            STD_METHOD SetPropertyNum, :ptr ISpSREngine, :SPPROPSRC, :ptr, :ptr WCHAR, :LONG
            DECLSPEC_XFGVIRT(ISpSREngine, GetPropertyNum)
            STD_METHOD GetPropertyNum, :ptr ISpSREngine, :SPPROPSRC, :ptr, :ptr WCHAR, :ptr LONG
            DECLSPEC_XFGVIRT(ISpSREngine, SetPropertyString)
            STD_METHOD SetPropertyString, :ptr ISpSREngine, :SPPROPSRC, :ptr, :LPCWSTR, :LPCWSTR
            DECLSPEC_XFGVIRT(ISpSREngine, GetPropertyString)
            STD_METHOD GetPropertyString, :ptr ISpSREngine, :SPPROPSRC, :ptr, :LPCWSTR, :ptr LPWSTR
            DECLSPEC_XFGVIRT(ISpSREngine, SetGrammarState)
            STD_METHOD SetGrammarState, :ptr ISpSREngine, :ptr, :SPGRAMMARSTATE
            DECLSPEC_XFGVIRT(ISpSREngine, WordNotify)
            STD_METHOD WordNotify, :ptr ISpSREngine, :SPCFGNOTIFY, :ULONG, :ptr SPWORDENTRY
            DECLSPEC_XFGVIRT(ISpSREngine, RuleNotify)
            STD_METHOD RuleNotify, :ptr ISpSREngine, :SPCFGNOTIFY, :ULONG, :ptr SPRULEENTRY
            DECLSPEC_XFGVIRT(ISpSREngine, PrivateCallEx)
            STD_METHOD PrivateCallEx, :ptr ISpSREngine, :ptr, :ptr, :ULONG, :ptr ptr, :ptr ULONG
            DECLSPEC_XFGVIRT(ISpSREngine, SetContextState)
            STD_METHOD SetContextState, :ptr ISpSREngine, :ptr, :SPCONTEXTSTATE
            ??Interface equ <>
            END_INTERFACE
          ISpSREngineVtbl ends
          ISpSREngine struct
            lpVtbl POINTER ?
          ISpSREngine ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __ISpSREngine2_INTERFACE_DEFINED__
        __ISpSREngine2_INTERFACE_DEFINED__ equ <>
        externdef IID_ISpSREngine2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpSREngine2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpSREngine2Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISpSREngine2, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpSREngine2
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpSREngine2
            DECLSPEC_XFGVIRT(ISpSREngine, SetSite)
            STD_METHOD SetSite, :ptr ISpSREngine2, :ptr ISpSREngineSite
            DECLSPEC_XFGVIRT(ISpSREngine, GetInputAudioFormat)
            STD_METHOD GetInputAudioFormat, :ptr ISpSREngine2, :ptr GUID, :ptr WAVEFORMATEX, :ptr GUID, :ptr ptr WAVEFORMATEX
            DECLSPEC_XFGVIRT(ISpSREngine, RecognizeStream)
            STD_METHOD RecognizeStream, :ptr ISpSREngine2, :REFGUID, :ptr WAVEFORMATEX, :HANDLE, :HANDLE, :HANDLE, :BOOL, :BOOL, :ptr ISpObjectToken
            DECLSPEC_XFGVIRT(ISpSREngine, SetRecoProfile)
            STD_METHOD SetRecoProfile, :ptr ISpSREngine2, :ptr ISpObjectToken
            DECLSPEC_XFGVIRT(ISpSREngine, OnCreateGrammar)
            STD_METHOD OnCreateGrammar, :ptr ISpSREngine2, :ptr, :SPGRAMMARHANDLE, :ptr ptr
            DECLSPEC_XFGVIRT(ISpSREngine, OnDeleteGrammar)
            STD_METHOD OnDeleteGrammar, :ptr ISpSREngine2, :ptr
            DECLSPEC_XFGVIRT(ISpSREngine, LoadProprietaryGrammar)
            STD_METHOD LoadProprietaryGrammar, :ptr ISpSREngine2, :ptr, :REFGUID, :LPCWSTR, :ptr, :ULONG, :SPLOADOPTIONS
            DECLSPEC_XFGVIRT(ISpSREngine, UnloadProprietaryGrammar)
            STD_METHOD UnloadProprietaryGrammar, :ptr ISpSREngine2, :ptr
            DECLSPEC_XFGVIRT(ISpSREngine, SetProprietaryRuleState)
            STD_METHOD SetProprietaryRuleState, :ptr ISpSREngine2, :ptr, :LPCWSTR, :ptr, :SPRULESTATE, :ptr ULONG
            DECLSPEC_XFGVIRT(ISpSREngine, SetProprietaryRuleIdState)
            STD_METHOD SetProprietaryRuleIdState, :ptr ISpSREngine2, :ptr, :DWORD, :SPRULESTATE
            DECLSPEC_XFGVIRT(ISpSREngine, LoadSLM)
            STD_METHOD LoadSLM, :ptr ISpSREngine2, :ptr, :LPCWSTR
            DECLSPEC_XFGVIRT(ISpSREngine, UnloadSLM)
            STD_METHOD UnloadSLM, :ptr ISpSREngine2, :ptr
            DECLSPEC_XFGVIRT(ISpSREngine, SetSLMState)
            STD_METHOD SetSLMState, :ptr ISpSREngine2, :ptr, :SPRULESTATE
            DECLSPEC_XFGVIRT(ISpSREngine, SetWordSequenceData)
            STD_METHOD SetWordSequenceData, :ptr ISpSREngine2, :ptr, :ptr WCHAR, :ULONG, :ptr SPTEXTSELECTIONINFO
            DECLSPEC_XFGVIRT(ISpSREngine, SetTextSelection)
            STD_METHOD SetTextSelection, :ptr ISpSREngine2, :ptr, :ptr SPTEXTSELECTIONINFO
            DECLSPEC_XFGVIRT(ISpSREngine, IsPronounceable)
            STD_METHOD IsPronounceable, :ptr ISpSREngine2, :ptr, :LPCWSTR, :ptr SPWORDPRONOUNCEABLE
            DECLSPEC_XFGVIRT(ISpSREngine, OnCreateRecoContext)
            STD_METHOD OnCreateRecoContext, :ptr ISpSREngine2, :SPRECOCONTEXTHANDLE, :ptr ptr
            DECLSPEC_XFGVIRT(ISpSREngine, OnDeleteRecoContext)
            STD_METHOD OnDeleteRecoContext, :ptr ISpSREngine2, :ptr
            DECLSPEC_XFGVIRT(ISpSREngine, PrivateCall)
            STD_METHOD PrivateCall, :ptr ISpSREngine2, :ptr, :PVOID, :ULONG
            DECLSPEC_XFGVIRT(ISpSREngine, SetAdaptationData)
            STD_METHOD SetAdaptationData, :ptr ISpSREngine2, :ptr, :ptr WCHAR, :ULONG
            DECLSPEC_XFGVIRT(ISpSREngine, SetPropertyNum)
            STD_METHOD SetPropertyNum, :ptr ISpSREngine2, :SPPROPSRC, :ptr, :ptr WCHAR, :LONG
            DECLSPEC_XFGVIRT(ISpSREngine, GetPropertyNum)
            STD_METHOD GetPropertyNum, :ptr ISpSREngine2, :SPPROPSRC, :ptr, :ptr WCHAR, :ptr LONG
            DECLSPEC_XFGVIRT(ISpSREngine, SetPropertyString)
            STD_METHOD SetPropertyString, :ptr ISpSREngine2, :SPPROPSRC, :ptr, :LPCWSTR, :LPCWSTR
            DECLSPEC_XFGVIRT(ISpSREngine, GetPropertyString)
            STD_METHOD GetPropertyString, :ptr ISpSREngine2, :SPPROPSRC, :ptr, :LPCWSTR, :ptr LPWSTR
            DECLSPEC_XFGVIRT(ISpSREngine, SetGrammarState)
            STD_METHOD SetGrammarState, :ptr ISpSREngine2, :ptr, :SPGRAMMARSTATE
            DECLSPEC_XFGVIRT(ISpSREngine, WordNotify)
            STD_METHOD WordNotify, :ptr ISpSREngine2, :SPCFGNOTIFY, :ULONG, :ptr SPWORDENTRY
            DECLSPEC_XFGVIRT(ISpSREngine, RuleNotify)
            STD_METHOD RuleNotify, :ptr ISpSREngine2, :SPCFGNOTIFY, :ULONG, :ptr SPRULEENTRY
            DECLSPEC_XFGVIRT(ISpSREngine, PrivateCallEx)
            STD_METHOD PrivateCallEx, :ptr ISpSREngine2, :ptr, :ptr, :ULONG, :ptr ptr, :ptr ULONG
            DECLSPEC_XFGVIRT(ISpSREngine, SetContextState)
            STD_METHOD SetContextState, :ptr ISpSREngine2, :ptr, :SPCONTEXTSTATE
            DECLSPEC_XFGVIRT(ISpSREngine2, PrivateCallImmediate)
            STD_METHOD PrivateCallImmediate, :ptr ISpSREngine2, :ptr, :ptr, :ULONG, :ptr ptr, :ptr ULONG
            DECLSPEC_XFGVIRT(ISpSREngine2, SetAdaptationData2)
            STD_METHOD SetAdaptationData2, :ptr ISpSREngine2, :ptr, :ptr WCHAR, :ULONG, :LPCWSTR, :SPADAPTATIONSETTINGS, :SPADAPTATIONRELEVANCE
            DECLSPEC_XFGVIRT(ISpSREngine2, SetGrammarPrefix)
            STD_METHOD SetGrammarPrefix, :ptr ISpSREngine2, :ptr, :LPCWSTR, :BOOL
            DECLSPEC_XFGVIRT(ISpSREngine2, SetRulePriority)
            STD_METHOD SetRulePriority, :ptr ISpSREngine2, :SPRULEHANDLE, :ptr, :SDWORD
            DECLSPEC_XFGVIRT(ISpSREngine2, EmulateRecognition)
            STD_METHOD EmulateRecognition, :ptr ISpSREngine2, :ptr ISpPhrase, :DWORD
            DECLSPEC_XFGVIRT(ISpSREngine2, SetSLMWeight)
            STD_METHOD SetSLMWeight, :ptr ISpSREngine2, :ptr, :REAL4
            DECLSPEC_XFGVIRT(ISpSREngine2, SetRuleWeight)
            STD_METHOD SetRuleWeight, :ptr ISpSREngine2, :SPRULEHANDLE, :ptr, :REAL4
            DECLSPEC_XFGVIRT(ISpSREngine2, SetTrainingState)
            STD_METHOD SetTrainingState, :ptr ISpSREngine2, :BOOL, :BOOL
            DECLSPEC_XFGVIRT(ISpSREngine2, ResetAcousticModelAdaptation)
            STD_METHOD ResetAcousticModelAdaptation, :ptr ISpSREngine2
            DECLSPEC_XFGVIRT(ISpSREngine2, OnLoadCFG)
            STD_METHOD OnLoadCFG, :ptr ISpSREngine2, :ptr, :ptr SPBINARYGRAMMAR, :ULONG
            DECLSPEC_XFGVIRT(ISpSREngine2, OnUnloadCFG)
            STD_METHOD OnUnloadCFG, :ptr ISpSREngine2, :ptr, :ULONG
            ??Interface equ <>
            END_INTERFACE
          ISpSREngine2Vtbl ends
          ISpSREngine2 struct
            lpVtbl POINTER ?
          ISpSREngine2 ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      SPPHRASEALTREQUEST struct
        ulStartElement ULONG ?
        cElements ULONG ?
        ulRequestAltCount ULONG ?
        pvResultExtra POINTER ?
        cbResultExtra ULONG ?
        pPhrase POINTER ?
        pRecoContext POINTER ?
      SPPHRASEALTREQUEST ends
      tagSPPHRASEALTREQUEST typedef SPPHRASEALTREQUEST
      externdef __MIDL_itf_sapiddk_0000_0017_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_sapiddk_0000_0017_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __ISpSRAlternates_INTERFACE_DEFINED__
        __ISpSRAlternates_INTERFACE_DEFINED__ equ <>
        externdef IID_ISpSRAlternates:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpSRAlternatesVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpSRAlternatesVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISpSRAlternates, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpSRAlternates
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpSRAlternates
            DECLSPEC_XFGVIRT(ISpSRAlternates, GetAlternates)
            STD_METHOD GetAlternates, :ptr ISpSRAlternates, :ptr SPPHRASEALTREQUEST, :ptr ptr SPPHRASEALT, :ptr ULONG
            DECLSPEC_XFGVIRT(ISpSRAlternates, Commit)
            STD_METHOD Commit, :ptr ISpSRAlternates, :ptr SPPHRASEALTREQUEST, :ptr SPPHRASEALT, :ptr ptr, :ptr ULONG
            ??Interface equ <>
            END_INTERFACE
          ISpSRAlternatesVtbl ends
          ISpSRAlternates struct
            lpVtbl POINTER ?
          ISpSRAlternates ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __ISpSRAlternates2_INTERFACE_DEFINED__
        __ISpSRAlternates2_INTERFACE_DEFINED__ equ <>
        externdef IID_ISpSRAlternates2:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpSRAlternates2Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpSRAlternates2Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISpSRAlternates2, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpSRAlternates2
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpSRAlternates2
            DECLSPEC_XFGVIRT(ISpSRAlternates, GetAlternates)
            STD_METHOD GetAlternates, :ptr ISpSRAlternates2, :ptr SPPHRASEALTREQUEST, :ptr ptr SPPHRASEALT, :ptr ULONG
            DECLSPEC_XFGVIRT(ISpSRAlternates, Commit)
            STD_METHOD Commit, :ptr ISpSRAlternates2, :ptr SPPHRASEALTREQUEST, :ptr SPPHRASEALT, :ptr ptr, :ptr ULONG
            DECLSPEC_XFGVIRT(ISpSRAlternates2, CommitText)
            STD_METHOD CommitText, :ptr ISpSRAlternates2, :ptr SPPHRASEALTREQUEST, :LPCWSTR, :SPCOMMITFLAGS
            ??Interface equ <>
            END_INTERFACE
          ISpSRAlternates2Vtbl ends
          ISpSRAlternates2 struct
            lpVtbl POINTER ?
          ISpSRAlternates2 ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef ___ISpPrivateEngineCall_INTERFACE_DEFINED__
        ___ISpPrivateEngineCall_INTERFACE_DEFINED__ equ <>
        externdef IID__ISpPrivateEngineCall:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          _ISpPrivateEngineCallVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <_ISpPrivateEngineCallVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr _ISpPrivateEngineCall, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr _ISpPrivateEngineCall
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr _ISpPrivateEngineCall
            DECLSPEC_XFGVIRT(_ISpPrivateEngineCall, CallEngine)
            STD_METHOD CallEngine, :ptr _ISpPrivateEngineCall, :ptr, :ULONG
            DECLSPEC_XFGVIRT(_ISpPrivateEngineCall, CallEngineEx)
            STD_METHOD CallEngineEx, :ptr _ISpPrivateEngineCall, :ptr, :ULONG, :ptr ptr, :ptr ULONG
            ??Interface equ <>
            END_INTERFACE
          _ISpPrivateEngineCallVtbl ends
          _ISpPrivateEngineCall struct
            lpVtbl POINTER ?
          _ISpPrivateEngineCall ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __ISpPrivateEngineCallEx_INTERFACE_DEFINED__
        __ISpPrivateEngineCallEx_INTERFACE_DEFINED__ equ <>
        externdef IID_ISpPrivateEngineCallEx:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISpPrivateEngineCallExVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISpPrivateEngineCallExVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISpPrivateEngineCallEx, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISpPrivateEngineCallEx
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISpPrivateEngineCallEx
            DECLSPEC_XFGVIRT(ISpPrivateEngineCallEx, CallEngineSynchronize)
            STD_METHOD CallEngineSynchronize, :ptr ISpPrivateEngineCallEx, :ptr, :ULONG, :ptr ptr, :ptr ULONG
            DECLSPEC_XFGVIRT(ISpPrivateEngineCallEx, CallEngineImmediate)
            STD_METHOD CallEngineImmediate, :ptr ISpPrivateEngineCallEx, :ptr, :ULONG, :ptr ptr, :ptr ULONG
            ??Interface equ <>
            END_INTERFACE
          ISpPrivateEngineCallExVtbl ends
          ISpPrivateEngineCallEx struct
            lpVtbl POINTER ?
          ISpPrivateEngineCallEx ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __SpeechDDKLib_LIBRARY_DEFINED__
        __SpeechDDKLib_LIBRARY_DEFINED__ equ <>
        externdef LIBID_SpeechDDKLib:IID
        externdef CLSID_SpDataKey:CLSID
        ifdef __cplusplus
          ;[...]
        endif
        externdef CLSID_SpObjectTokenEnum:CLSID
        ifdef __cplusplus
          ;[...]
        endif
        externdef CLSID_SpPhraseBuilder:CLSID
        ifdef __cplusplus
          ;[...]
        endif
        externdef CLSID_SpITNProcessor:CLSID
        ifdef __cplusplus
          ;[...]
        endif
        externdef CLSID_SpGrammarCompiler:CLSID
        ifdef __cplusplus
          ;[...]
        endif
        externdef CLSID_SpW3CGrammarCompiler:CLSID
        ifdef __cplusplus
          ;[...]
        endif
        externdef CLSID_SpGramCompBackend:CLSID
        ifdef __cplusplus
          ;[...]
        endif
      endif
    else
      include sapiddk51.inc
    endif
  endif
  externdef __MIDL_itf_sapiddk_0000_0022_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_sapiddk_0000_0022_v0_0_s_ifspec:RPC_IF_HANDLE
  ifdef __cplusplus
    ;[...]
  endif
endif
