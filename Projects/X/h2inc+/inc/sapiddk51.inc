;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\sapiddk51.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 21/02/2024 18:17:12

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
ifndef __sapiddk51_h__
  __sapiddk51_h__ equ <>
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
  ifndef __ISpTokenUI_FWD_DEFINED__
    __ISpTokenUI_FWD_DEFINED__ equ <>
    ;* __ISpTokenUI_FWD_DEFINED__ *
  endif
  ifndef __ISpObjectTokenEnumBuilder_FWD_DEFINED__
    __ISpObjectTokenEnumBuilder_FWD_DEFINED__ equ <>
    ;* __ISpObjectTokenEnumBuilder_FWD_DEFINED__ *
  endif
  ifndef __ISpErrorLog_FWD_DEFINED__
    __ISpErrorLog_FWD_DEFINED__ equ <>
    ;* __ISpErrorLog_FWD_DEFINED__ *
  endif
  ifndef __ISpGrammarCompiler_FWD_DEFINED__
    __ISpGrammarCompiler_FWD_DEFINED__ equ <>
    ;* __ISpGrammarCompiler_FWD_DEFINED__ *
  endif
  ifndef __ISpGramCompBackend_FWD_DEFINED__
    __ISpGramCompBackend_FWD_DEFINED__ equ <>
    ;* __ISpGramCompBackend_FWD_DEFINED__ *
  endif
  ifndef __ISpITNProcessor_FWD_DEFINED__
    __ISpITNProcessor_FWD_DEFINED__ equ <>
    ;* __ISpITNProcessor_FWD_DEFINED__ *
  endif
  ifndef __ISpPhraseBuilder_FWD_DEFINED__
    __ISpPhraseBuilder_FWD_DEFINED__ equ <>
    ;* __ISpPhraseBuilder_FWD_DEFINED__ *
  endif
  ifndef __ISpThreadControl_FWD_DEFINED__
    __ISpThreadControl_FWD_DEFINED__ equ <>
    ;* __ISpThreadControl_FWD_DEFINED__ *
  endif
  ifndef __ISpTaskManager_FWD_DEFINED__
    __ISpTaskManager_FWD_DEFINED__ equ <>
    ;* __ISpTaskManager_FWD_DEFINED__ *
  endif
  ifndef __ISpTTSEngineSite_FWD_DEFINED__
    __ISpTTSEngineSite_FWD_DEFINED__ equ <>
    ;* __ISpTTSEngineSite_FWD_DEFINED__ *
  endif
  ifndef __ISpTTSEngine_FWD_DEFINED__
    __ISpTTSEngine_FWD_DEFINED__ equ <>
    ;* __ISpTTSEngine_FWD_DEFINED__ *
  endif
  ifndef __ISpCFGInterpreterSite_FWD_DEFINED__
    __ISpCFGInterpreterSite_FWD_DEFINED__ equ <>
    ;* __ISpCFGInterpreterSite_FWD_DEFINED__ *
  endif
  ifndef __ISpCFGInterpreter_FWD_DEFINED__
    __ISpCFGInterpreter_FWD_DEFINED__ equ <>
    ;* __ISpCFGInterpreter_FWD_DEFINED__ *
  endif
  ifndef __ISpSREngineSite_FWD_DEFINED__
    __ISpSREngineSite_FWD_DEFINED__ equ <>
    ;* __ISpSREngineSite_FWD_DEFINED__ *
  endif
  ifndef __ISpSREngine_FWD_DEFINED__
    __ISpSREngine_FWD_DEFINED__ equ <>
    ;* __ISpSREngine_FWD_DEFINED__ *
  endif
  ifndef ___ISpPrivateEngineCall_FWD_DEFINED__
    ___ISpPrivateEngineCall_FWD_DEFINED__ equ <>
    ;* ___ISpPrivateEngineCall_FWD_DEFINED__ *
  endif
  ifndef __SpDataKey_FWD_DEFINED__
    __SpDataKey_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __SpDataKey_FWD_DEFINED__ *
  endif
  ifndef __SpObjectTokenEnum_FWD_DEFINED__
    __SpObjectTokenEnum_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __SpObjectTokenEnum_FWD_DEFINED__ *
  endif
  ifndef __SpPhraseBuilder_FWD_DEFINED__
    __SpPhraseBuilder_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __SpPhraseBuilder_FWD_DEFINED__ *
  endif
  ifndef __SpITNProcessor_FWD_DEFINED__
    __SpITNProcessor_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __SpITNProcessor_FWD_DEFINED__ *
  endif
  ifndef __SpGrammarCompiler_FWD_DEFINED__
    __SpGrammarCompiler_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __SpGrammarCompiler_FWD_DEFINED__ *
  endif
  ifndef __SpGramCompBackend_FWD_DEFINED__
    __SpGramCompBackend_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __SpGramCompBackend_FWD_DEFINED__ *
  endif
  ;* header files for imported files *
  include oaidl.inc
  include ocidl.inc
  include sapi.inc
  ifdef __cplusplus
    ;[...]
  endif
  ;* interface __MIDL_itf_sapiddk51_0000_0000 *
  ;* [local] *
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    SPRECOEXTENSION equ <L("RecoExtension")>
    SPALTERNATESCLSID equ <L("AlternatesCLSID")>
    externdef __MIDL_itf_sapiddk51_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_sapiddk51_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ISpTokenUI_INTERFACE_DEFINED__
      __ISpTokenUI_INTERFACE_DEFINED__ equ <>
      ;* interface ISpTokenUI *
      ;* [restricted][unique][helpstring][uuid][object] *
      externdef IID_ISpTokenUI:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpTokenUIVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpTokenUIVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpTokenUI, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpTokenUI
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpTokenUI
          DECLSPEC_XFGVIRT(ISpTokenUI, IsUISupported)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD IsUISupported, :ptr ISpTokenUI, :LPCWSTR, :ptr, :ULONG, :ptr IUnknown, :ptr BOOL
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpTokenUI, DisplayUI)
          ;* [local] *
          ;* [in] *
          ;* [in][annotation] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD DisplayUI, :ptr ISpTokenUI, :HWND, :LPCWSTR, :LPCWSTR, :ptr, :ULONG, :ptr ISpObjectToken, :ptr IUnknown
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        ISpTokenUIVtbl ends
        ISpTokenUI struct
          lpVtbl POINTER ?
        ISpTokenUI ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpTokenUI_INTERFACE_DEFINED__ *
    endif
    ifndef __ISpObjectTokenEnumBuilder_INTERFACE_DEFINED__
      __ISpObjectTokenEnumBuilder_INTERFACE_DEFINED__ equ <>
      ;* interface ISpObjectTokenEnumBuilder *
      ;* [restricted][local][unique][helpstring][uuid][object] *
      externdef IID_ISpObjectTokenEnumBuilder:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpObjectTokenEnumBuilderVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpObjectTokenEnumBuilderVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpObjectTokenEnumBuilder, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpObjectTokenEnumBuilder
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpObjectTokenEnumBuilder
          DECLSPEC_XFGVIRT(IEnumSpObjectTokens, Next)
          ;* [in] *
          ;* [length_is][size_is][out] *
          ;* [out][annotation] *
          STD_METHOD Next, :ptr ISpObjectTokenEnumBuilder, :ULONG, :ptr ptr ISpObjectToken, :ptr ULONG
          DECLSPEC_XFGVIRT(IEnumSpObjectTokens, Skip)
          STD_METHOD Skip, :ptr ISpObjectTokenEnumBuilder, :ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(IEnumSpObjectTokens, Reset)
          STD_METHOD Reset, :ptr ISpObjectTokenEnumBuilder
          DECLSPEC_XFGVIRT(IEnumSpObjectTokens, Clone)
          STD_METHOD Clone, :ptr ISpObjectTokenEnumBuilder, :ptr ptr IEnumSpObjectTokens
          ;* [out] *
          DECLSPEC_XFGVIRT(IEnumSpObjectTokens, Item)
          ;* [in] *
          STD_METHOD Item, :ptr ISpObjectTokenEnumBuilder, :ULONG, :ptr ptr ISpObjectToken
          ;* [out] *
          DECLSPEC_XFGVIRT(IEnumSpObjectTokens, GetCount)
          STD_METHOD GetCount, :ptr ISpObjectTokenEnumBuilder, :ptr ULONG
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpObjectTokenEnumBuilder, SetAttribs)
          ;* [in][annotation] *
          ;* [in][annotation] *
          STD_METHOD SetAttribs, :ptr ISpObjectTokenEnumBuilder, :LPCWSTR, :LPCWSTR
          DECLSPEC_XFGVIRT(ISpObjectTokenEnumBuilder, AddTokens)
          ;* [in] *
          STD_METHOD AddTokens, :ptr ISpObjectTokenEnumBuilder, :ULONG, :ptr ptr ISpObjectToken
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpObjectTokenEnumBuilder, AddTokensFromDataKey)
          ;* [in] *
          ;* [in] *
          STD_METHOD AddTokensFromDataKey, :ptr ISpObjectTokenEnumBuilder, :ptr ISpDataKey, :LPCWSTR, :LPCWSTR
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpObjectTokenEnumBuilder, AddTokensFromTokenEnum)
          STD_METHOD AddTokensFromTokenEnum, :ptr ISpObjectTokenEnumBuilder, :ptr IEnumSpObjectTokens
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpObjectTokenEnumBuilder, Sort)
          STD_METHOD Sort, :ptr ISpObjectTokenEnumBuilder, :LPCWSTR
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        ISpObjectTokenEnumBuilderVtbl ends
        ISpObjectTokenEnumBuilder struct
          lpVtbl POINTER ?
        ISpObjectTokenEnumBuilder ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpObjectTokenEnumBuilder_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_sapiddk51_0000_0002 *
    ;* [local] *
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
    externdef __MIDL_itf_sapiddk51_0000_0002_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_sapiddk51_0000_0002_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ISpErrorLog_INTERFACE_DEFINED__
      __ISpErrorLog_INTERFACE_DEFINED__ equ <>
      ;* interface ISpErrorLog *
      ;* [restricted][local][unique][helpstring][uuid][object] *
      externdef IID_ISpErrorLog:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpErrorLogVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpErrorLogVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpErrorLog, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpErrorLog
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpErrorLog
          DECLSPEC_XFGVIRT(ISpErrorLog, AddError)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in][annotation] *
          STD_METHOD AddError, :ptr ISpErrorLog, :SDWORD, :HRESULT, :LPCWSTR, :LPCWSTR, :DWORD
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        ISpErrorLogVtbl ends
        ISpErrorLog struct
          lpVtbl POINTER ?
        ISpErrorLog ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpErrorLog_INTERFACE_DEFINED__ *
    endif
    ifndef __ISpGrammarCompiler_INTERFACE_DEFINED__
      __ISpGrammarCompiler_INTERFACE_DEFINED__ equ <>
      ;* interface ISpGrammarCompiler *
      ;* [restricted][local][unique][helpstring][uuid][object] *
      externdef IID_ISpGrammarCompiler:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpGrammarCompilerVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpGrammarCompilerVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpGrammarCompiler, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpGrammarCompiler
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpGrammarCompiler
          DECLSPEC_XFGVIRT(ISpGrammarCompiler, CompileStream)
          ;* [in] *
          ;* [out] *
          ;* [in][annotation] *
          ;* [in][annotation] *
          ;* [in][annotation] *
          STD_METHOD CompileStream, :ptr ISpGrammarCompiler, :ptr IStream, :ptr IStream, :ptr IStream, :ptr IUnknown, :ptr ISpErrorLog, :DWORD
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        ISpGrammarCompilerVtbl ends
        ISpGrammarCompiler struct
          lpVtbl POINTER ?
        ISpGrammarCompiler ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpGrammarCompiler_INTERFACE_DEFINED__ *
    endif
    ifndef __ISpGramCompBackend_INTERFACE_DEFINED__
      __ISpGramCompBackend_INTERFACE_DEFINED__ equ <>
      ;* interface ISpGramCompBackend *
      ;* [restricted][unique][helpstring][uuid][object] *
      externdef IID_ISpGramCompBackend:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpGramCompBackendVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpGramCompBackendVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpGramCompBackend, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpGramCompBackend
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpGramCompBackend
          DECLSPEC_XFGVIRT(ISpGrammarBuilder, ResetGrammar)
          STD_METHOD ResetGrammar, :ptr ISpGramCompBackend, :WORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpGrammarBuilder, GetRule)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD GetRule, :ptr ISpGramCompBackend, :LPCWSTR, :DWORD, :DWORD, :BOOL, :ptr SPSTATEHANDLE
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpGrammarBuilder, ClearRule)
          STD_METHOD ClearRule, :ptr ISpGramCompBackend, :SPSTATEHANDLE
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpGrammarBuilder, CreateNewState)
          ;* [in] *
          STD_METHOD CreateNewState, :ptr ISpGramCompBackend, :SPSTATEHANDLE, :ptr SPSTATEHANDLE
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpGrammarBuilder, AddWordTransition)
          ;* [in] *
          ;* [in] *
          ;* [in][annotation] *
          ;* [in][annotation] *
          ;* [in] *
          ;* [in] *
          STD_METHOD AddWordTransition, :ptr ISpGramCompBackend, :SPSTATEHANDLE, :SPSTATEHANDLE, :LPCWSTR, :LPCWSTR, :SPGRAMMARWORDTYPE, :REAL4, :ptr SPPROPERTYINFO
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpGrammarBuilder, AddRuleTransition)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD AddRuleTransition, :ptr ISpGramCompBackend, :SPSTATEHANDLE, :SPSTATEHANDLE, :SPSTATEHANDLE, :REAL4, :ptr SPPROPERTYINFO
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpGrammarBuilder, AddResource)
          ;* [in] *
          ;* [in] *
          ;* [in][annotation] *
          STD_METHOD AddResource, :ptr ISpGramCompBackend, :SPSTATEHANDLE, :LPCWSTR, :LPCWSTR
          DECLSPEC_XFGVIRT(ISpGrammarBuilder, Commit)
          STD_METHOD Commit, :ptr ISpGramCompBackend, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpGramCompBackend, SetSaveObjects)
          ;* [in] *
          STD_METHOD SetSaveObjects, :ptr ISpGramCompBackend, :ptr IStream, :ptr ISpErrorLog
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpGramCompBackend, InitFromBinaryGrammar)
          STD_METHOD InitFromBinaryGrammar, :ptr ISpGramCompBackend, :ptr SPBINARYGRAMMAR
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        ISpGramCompBackendVtbl ends
        ISpGramCompBackend struct
          lpVtbl POINTER ?
        ISpGramCompBackend ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpGramCompBackend_INTERFACE_DEFINED__ *
    endif
    ifndef __ISpITNProcessor_INTERFACE_DEFINED__
      __ISpITNProcessor_INTERFACE_DEFINED__ equ <>
      ;* interface ISpITNProcessor *
      ;* [restricted][local][unique][helpstring][uuid][object] *
      externdef IID_ISpITNProcessor:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpITNProcessorVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpITNProcessorVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpITNProcessor, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpITNProcessor
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpITNProcessor
          DECLSPEC_XFGVIRT(ISpITNProcessor, LoadITNGrammar)
          ;* [in][annotation] *
          STD_METHOD LoadITNGrammar, :ptr ISpITNProcessor, :LPWSTR
          DECLSPEC_XFGVIRT(ISpITNProcessor, ITNPhrase)
          STD_METHOD ITNPhrase, :ptr ISpITNProcessor, :ptr ISpPhraseBuilder
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        ISpITNProcessorVtbl ends
        ISpITNProcessor struct
          lpVtbl POINTER ?
        ISpITNProcessor ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpITNProcessor_INTERFACE_DEFINED__ *
    endif
    ifndef __ISpPhraseBuilder_INTERFACE_DEFINED__
      __ISpPhraseBuilder_INTERFACE_DEFINED__ equ <>
      ;* interface ISpPhraseBuilder *
      ;* [restricted][unique][helpstring][local][uuid][object] *
      externdef IID_ISpPhraseBuilder:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpPhraseBuilderVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpPhraseBuilderVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpPhraseBuilder, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpPhraseBuilder
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpPhraseBuilder
          DECLSPEC_XFGVIRT(ISpPhrase, GetPhrase)
          ;* [out][annotation] *
          STD_METHOD GetPhrase, :ptr ISpPhraseBuilder, :ptr ptr SPPHRASE
          DECLSPEC_XFGVIRT(ISpPhrase, GetSerializedPhrase)
          ;* [out][annotation] *
          STD_METHOD GetSerializedPhrase, :ptr ISpPhraseBuilder, :ptr ptr SPSERIALIZEDPHRASE
          DECLSPEC_XFGVIRT(ISpPhrase, GetText)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [out][annotation] *
          ;* [optional][out][annotation] *
          STD_METHOD GetText, :ptr ISpPhraseBuilder, :ULONG, :ULONG, :BOOL, :ptr LPWSTR, :ptr BYTE
          DECLSPEC_XFGVIRT(ISpPhrase, Discard)
          STD_METHOD Discard, :ptr ISpPhraseBuilder, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpPhraseBuilder, InitFromPhrase)
          STD_METHOD InitFromPhrase, :ptr ISpPhraseBuilder, :ptr SPPHRASE
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpPhraseBuilder, InitFromSerializedPhrase)
          STD_METHOD InitFromSerializedPhrase, :ptr ISpPhraseBuilder, :ptr SPSERIALIZEDPHRASE
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpPhraseBuilder, AddElements)
          ;* [in] *
          STD_METHOD AddElements, :ptr ISpPhraseBuilder, :ULONG, :ptr SPPHRASEELEMENT
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpPhraseBuilder, AddRules)
          ;* [in] *
          ;* [in] *
          STD_METHOD AddRules, :ptr ISpPhraseBuilder, :SPPHRASERULEHANDLE, :ptr SPPHRASERULE, :ptr SPPHRASERULEHANDLE
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpPhraseBuilder, AddProperties)
          ;* [in] *
          ;* [in] *
          STD_METHOD AddProperties, :ptr ISpPhraseBuilder, :SPPHRASEPROPERTYHANDLE, :ptr SPPHRASEPROPERTY, :ptr SPPHRASEPROPERTYHANDLE
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpPhraseBuilder, AddReplacements)
          ;* [in] *
          STD_METHOD AddReplacements, :ptr ISpPhraseBuilder, :ULONG, :ptr SPPHRASEREPLACEMENT
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        ISpPhraseBuilderVtbl ends
        ISpPhraseBuilder struct
          lpVtbl POINTER ?
        ISpPhraseBuilder ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpPhraseBuilder_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_sapiddk51_0000_0007 *
    ;* [local] *
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
    externdef __MIDL_itf_sapiddk51_0000_0007_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_sapiddk51_0000_0007_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ISpThreadControl_INTERFACE_DEFINED__
      __ISpThreadControl_INTERFACE_DEFINED__ equ <>
      ;* interface ISpThreadControl *
      ;* [restricted][local][unique][helpstring][uuid][object] *
      externdef IID_ISpThreadControl:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpThreadControlVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpThreadControlVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpThreadControl, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpThreadControl
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpThreadControl
          DECLSPEC_XFGVIRT(ISpNotifySink, Notify)
          STD_METHOD Notify, :ptr ISpThreadControl
          DECLSPEC_XFGVIRT(ISpThreadControl, StartThread)
          ;* [in] *
          STD_METHOD StartThread, :ptr ISpThreadControl, :DWORD, :ptr HWND
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpThreadControl, WaitForThreadDone)
          ;* [in] *
          ;* [out] *
          STD_METHOD WaitForThreadDone, :ptr ISpThreadControl, :BOOL, :ptr HRESULT, :ULONG
          ;* [in] *
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
        ;* C style interface *
      endif
      ;* __ISpThreadControl_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_sapiddk51_0000_0008 *
    ;* [local] *
    ;* [restricted] *
    SPTMTHREADINFO struct
      lPoolSize SDWORD ?
      lPriority SDWORD ?
      ulConcurrencyLimit DWORD ?
      ulMaxQuickAllocThreads DWORD ?
    SPTMTHREADINFO ends
    externdef __MIDL_itf_sapiddk51_0000_0008_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_sapiddk51_0000_0008_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ISpTaskManager_INTERFACE_DEFINED__
      __ISpTaskManager_INTERFACE_DEFINED__ equ <>
      ;* interface ISpTaskManager *
      ;* [object][restricted][unique][helpstring][uuid][local] *
      externdef IID_ISpTaskManager:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpTaskManagerVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpTaskManagerVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpTaskManager, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpTaskManager
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpTaskManager
          DECLSPEC_XFGVIRT(ISpTaskManager, SetThreadPoolInfo)
          STD_METHOD SetThreadPoolInfo, :ptr ISpTaskManager, :ptr SPTMTHREADINFO
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpTaskManager, GetThreadPoolInfo)
          STD_METHOD GetThreadPoolInfo, :ptr ISpTaskManager, :ptr SPTMTHREADINFO
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpTaskManager, QueueTask)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [out][in] *
          STD_METHOD QueueTask, :ptr ISpTaskManager, :ptr ISpTask, :ptr, :HANDLE, :ptr DWORD, :ptr DWORD
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpTaskManager, CreateReoccurringTask)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD CreateReoccurringTask, :ptr ISpTaskManager, :ptr ISpTask, :ptr, :HANDLE, :ptr ptr ISpNotifySink
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpTaskManager, CreateThreadControl)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [out][annotation] *
          STD_METHOD CreateThreadControl, :ptr ISpTaskManager, :ptr ISpThreadTask, :ptr, :SDWORD, :ptr ptr ISpThreadControl
          DECLSPEC_XFGVIRT(ISpTaskManager, TerminateTask)
          ;* [in] *
          STD_METHOD TerminateTask, :ptr ISpTaskManager, :DWORD, :ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpTaskManager, TerminateTaskGroup)
          ;* [in] *
          STD_METHOD TerminateTaskGroup, :ptr ISpTaskManager, :DWORD, :ULONG
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        ISpTaskManagerVtbl ends
        ISpTaskManager struct
          lpVtbl POINTER ?
        ISpTaskManager ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpTaskManager_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_sapiddk51_0000_0009 *
    ;* [local] *
    SPVSKIPTYPE typedef SDWORD
    SPVST_SENTENCE equ

    SPVESACTIONS typedef SDWORD
    SPVES_CONTINUE equ 0
    SPVES_ABORT equ
    SPVES_SKIP equ
    SPVES_RATE equ
    SPVES_VOLUME equ

    externdef __MIDL_itf_sapiddk51_0000_0009_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_sapiddk51_0000_0009_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ISpTTSEngineSite_INTERFACE_DEFINED__
      __ISpTTSEngineSite_INTERFACE_DEFINED__ equ <>
      ;* interface ISpTTSEngineSite *
      ;* [unique][helpstring][uuid][local][object] *
      externdef IID_ISpTTSEngineSite:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpTTSEngineSiteVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpTTSEngineSiteVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpTTSEngineSite, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpTTSEngineSite
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpTTSEngineSite
          DECLSPEC_XFGVIRT(ISpEventSink, AddEvents)
          ;* [in] *
          STD_METHOD AddEvents, :ptr ISpTTSEngineSite, :ptr SPEVENT, :ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpEventSink, GetEventInterest)
          STD_METHOD GetEventInterest, :ptr ISpTTSEngineSite, :ptr ULONGLONG
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpTTSEngineSite, GetActions)
          STD_METHOD GetActions, :ptr ISpTTSEngineSite
          DECLSPEC_XFGVIRT(ISpTTSEngineSite, Write)
          ;* [in] *
          ;* [in] *
          STD_METHOD Write, :ptr ISpTTSEngineSite, :ptr, :ULONG, :ptr ULONG
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpTTSEngineSite, GetRate)
          STD_METHOD GetRate, :ptr ISpTTSEngineSite, :ptr SDWORD
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpTTSEngineSite, GetVolume)
          STD_METHOD GetVolume, :ptr ISpTTSEngineSite, :ptr USHORT
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpTTSEngineSite, GetSkipInfo)
          ;* [out] *
          STD_METHOD GetSkipInfo, :ptr ISpTTSEngineSite, :ptr SPVSKIPTYPE, :ptr SDWORD
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpTTSEngineSite, CompleteSkip)
          STD_METHOD CompleteSkip, :ptr ISpTTSEngineSite, :SDWORD
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        ISpTTSEngineSiteVtbl ends
        ISpTTSEngineSite struct
          lpVtbl POINTER ?
        ISpTTSEngineSite ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpTTSEngineSite_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_sapiddk51_0000_0010 *
    ;* [local] *
    SPVTEXTFRAG struct
      pNext POINTER ?
      State SPVSTATE <>
      pTextStart =POINTER ?
      ulTextLen DWORD ?
      ulTextSrcOffset DWORD ?
    SPVTEXTFRAG ends
    externdef __MIDL_itf_sapiddk51_0000_0010_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_sapiddk51_0000_0010_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ISpTTSEngine_INTERFACE_DEFINED__
      __ISpTTSEngine_INTERFACE_DEFINED__ equ <>
      ;* interface ISpTTSEngine *
      ;* [unique][helpstring][uuid][local][object] *
      externdef IID_ISpTTSEngine:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpTTSEngineVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpTTSEngineVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpTTSEngine, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpTTSEngine
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpTTSEngine
          DECLSPEC_XFGVIRT(ISpTTSEngine, Speak)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD Speak, :ptr ISpTTSEngine, :DWORD, :REFGUID, :ptr WAVEFORMATEX, :ptr SPVTEXTFRAG, :ptr ISpTTSEngineSite
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpTTSEngine, GetOutputFormat)
          ;* [in] *
          ;* [in] *
          ;* [out] *
          ;* [out][annotation] *
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
        ;* C style interface *
      endif
      ;* __ISpTTSEngine_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_sapiddk51_0000_0011 *
    ;* [local] *
    ;* [restricted] *
    SPWORDENTRY struct
      hWord SPWORDHANDLE ?
      LangID WORD ?
      pszDisplayText POINTER ?
      pszLexicalForm POINTER ?
      aPhoneId POINTER ?
      pvClientContext POINTER ?
    SPWORDENTRY ends
    ;* [restricted] *
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

    ;* [restricted] *
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
    ;* [restricted] *
    SPTRANSITIONPROPERTY struct
      pszName =POINTER ?
      ulId DWORD ?
      pszValue =POINTER ?
      vValue VARIANT <>
    SPTRANSITIONPROPERTY ends
    ;* [restricted] *
    SPSTATEINFO struct
      cAllocatedEntries DWORD ?
      pTransitions POINTER ?
      cEpsilons DWORD ?
      cRules DWORD ?
      cWords DWORD ?
      cSpecialTransitions DWORD ?
    SPSTATEINFO ends
    ;* [restricted] *
    SPPATHENTRY struct
      hTransition SPTRANSITIONID ?
      elem SPPHRASEELEMENT <>
    SPPATHENTRY ends
    externdef __MIDL_itf_sapiddk51_0000_0011_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_sapiddk51_0000_0011_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ISpCFGInterpreterSite_INTERFACE_DEFINED__
      __ISpCFGInterpreterSite_INTERFACE_DEFINED__ equ <>
      ;* interface ISpCFGInterpreterSite *
      ;* [restricted][local][unique][helpstring][uuid][object] *
      externdef IID_ISpCFGInterpreterSite:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpCFGInterpreterSiteVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpCFGInterpreterSiteVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpCFGInterpreterSite, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpCFGInterpreterSite
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpCFGInterpreterSite
          DECLSPEC_XFGVIRT(ISpCFGInterpreterSite, AddTextReplacement)
          STD_METHOD AddTextReplacement, :ptr ISpCFGInterpreterSite, :ptr SPPHRASEREPLACEMENT
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpCFGInterpreterSite, AddProperty)
          STD_METHOD AddProperty, :ptr ISpCFGInterpreterSite, :ptr SPPHRASEPROPERTY
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpCFGInterpreterSite, GetResourceValue)
          ;* [in] *
          ;* [out][annotation] *
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
        ;* C style interface *
      endif
      ;* __ISpCFGInterpreterSite_INTERFACE_DEFINED__ *
    endif
    ifndef __ISpCFGInterpreter_INTERFACE_DEFINED__
      __ISpCFGInterpreter_INTERFACE_DEFINED__ equ <>
      ;* interface ISpCFGInterpreter *
      ;* [restricted][local][unique][helpstring][uuid][object] *
      externdef IID_ISpCFGInterpreter:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpCFGInterpreterVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpCFGInterpreterVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpCFGInterpreter, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpCFGInterpreter
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpCFGInterpreter
          DECLSPEC_XFGVIRT(ISpCFGInterpreter, InitGrammar)
          ;* [in] *
          STD_METHOD InitGrammar, :ptr ISpCFGInterpreter, :LPCWSTR, :ptr ptr
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpCFGInterpreter, Interpret)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD Interpret, :ptr ISpCFGInterpreter, :ptr ISpPhraseBuilder, :ULONG, :ULONG, :ptr ISpCFGInterpreterSite
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        ISpCFGInterpreterVtbl ends
        ISpCFGInterpreter struct
          lpVtbl POINTER ?
        ISpCFGInterpreter ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpCFGInterpreter_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_sapiddk51_0000_0013 *
    ;* [local] *
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

    SPPHRASEALT struct
      pPhrase POINTER ?
      ulStartElementInParent DWORD ?
      cElementsInParent DWORD ?
      cElementsInAlternate DWORD ?
      pvAltExtra POINTER ?
      cbAltExtra DWORD ?
    SPPHRASEALT ends
    tagSPPHRASEALT typedef SPPHRASEALT
    SPRECORESULTINFO struct
      cbSize DWORD ?
      eResultType SPRESULTTYPE ?
      fHypothesis DWORD ?
      fProprietaryAutoPause DWORD ?
      ullStreamPosStart QWORD ?
      ullStreamPosEnd QWORD ?
      hGrammar SPGRAMMARHANDLE ?
      ulSizeEngineData DWORD ?
      pvEngineData POINTER ?
      pPhrase POINTER ?
      aPhraseAlts POINTER ?
      ulNumAlts DWORD ?
    SPRECORESULTINFO ends
    SPWORDINFOOPT typedef SDWORD
    SPWIO_NONE equ 0
    SPWIO_WANT_TEXT equ 1

    SPRULEINFOOPT typedef SDWORD
    SPRIO_NONE equ 0

    SPPARSEINFO struct
      cbSize DWORD ?
      hRule SPRULEHANDLE ?
      ullAudioStreamPosition QWORD ?
      ulAudioSize DWORD ?
      cTransitions DWORD ?
      pPath POINTER ?
      SREngineID GUID <>
      ulSREnginePrivateDataSize DWORD ?
      pSREnginePrivateData POINTER ?
      fHypothesis DWORD ?
    SPPARSEINFO ends
    externdef __MIDL_itf_sapiddk51_0000_0013_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_sapiddk51_0000_0013_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ISpSREngineSite_INTERFACE_DEFINED__
      __ISpSREngineSite_INTERFACE_DEFINED__ equ <>
      ;* interface ISpSREngineSite *
      ;* [local][unique][helpstring][uuid][object] *
      externdef IID_ISpSREngineSite:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpSREngineSiteVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpSREngineSiteVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpSREngineSite, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpSREngineSite
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpSREngineSite
          DECLSPEC_XFGVIRT(ISpSREngineSite, Read)
          ;* [in] *
          ;* [in] *
          STD_METHOD Read, :ptr ISpSREngineSite, :ptr, :ULONG, :ptr ULONG
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpSREngineSite, DataAvailable)
          STD_METHOD DataAvailable, :ptr ISpSREngineSite, :ptr ULONG
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpSREngineSite, SetBufferNotifySize)
          STD_METHOD SetBufferNotifySize, :ptr ISpSREngineSite, :ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpSREngineSite, ParseFromTransitions)
          ;* [in] *
          STD_METHOD ParseFromTransitions, :ptr ISpSREngineSite, :ptr SPPARSEINFO, :ptr ptr ISpPhraseBuilder
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpSREngineSite, Recognition)
          STD_METHOD Recognition, :ptr ISpSREngineSite, :ptr SPRECORESULTINFO
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpSREngineSite, AddEvent)
          ;* [in] *
          STD_METHOD AddEvent, :ptr ISpSREngineSite, :ptr SPEVENT, :SPRECOCONTEXTHANDLE
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpSREngineSite, Synchronize)
          STD_METHOD Synchronize, :ptr ISpSREngineSite, :ULONGLONG
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpSREngineSite, GetWordInfo)
          ;* [out][in] *
          STD_METHOD GetWordInfo, :ptr ISpSREngineSite, :ptr SPWORDENTRY, :SPWORDINFOOPT
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpSREngineSite, SetWordClientContext)
          ;* [in] *
          STD_METHOD SetWordClientContext, :ptr ISpSREngineSite, :SPWORDHANDLE, :ptr
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpSREngineSite, GetRuleInfo)
          ;* [out][in] *
          STD_METHOD GetRuleInfo, :ptr ISpSREngineSite, :ptr SPRULEENTRY, :SPRULEINFOOPT
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpSREngineSite, SetRuleClientContext)
          ;* [in] *
          STD_METHOD SetRuleClientContext, :ptr ISpSREngineSite, :SPRULEHANDLE, :ptr
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpSREngineSite, GetStateInfo)
          ;* [in] *
          STD_METHOD GetStateInfo, :ptr ISpSREngineSite, :SPSTATEHANDLE, :ptr SPSTATEINFO
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpSREngineSite, GetResource)
          ;* [in] *
          ;* [in] *
          ;* [out][annotation] *
          STD_METHOD GetResource, :ptr ISpSREngineSite, :SPRULEHANDLE, :LPCWSTR, :ptr LPWSTR
          DECLSPEC_XFGVIRT(ISpSREngineSite, GetTransitionProperty)
          ;* [in] *
          ;* [out][annotation] *
          STD_METHOD GetTransitionProperty, :ptr ISpSREngineSite, :SPTRANSITIONID, :ptr ptr SPTRANSITIONPROPERTY
          DECLSPEC_XFGVIRT(ISpSREngineSite, IsAlternate)
          ;* [in] *
          STD_METHOD IsAlternate, :ptr ISpSREngineSite, :SPRULEHANDLE, :SPRULEHANDLE
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpSREngineSite, GetMaxAlternates)
          ;* [in] *
          STD_METHOD GetMaxAlternates, :ptr ISpSREngineSite, :SPRULEHANDLE, :ptr ULONG
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpSREngineSite, GetContextMaxAlternates)
          ;* [in] *
          STD_METHOD GetContextMaxAlternates, :ptr ISpSREngineSite, :SPRECOCONTEXTHANDLE, :ptr ULONG
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpSREngineSite, UpdateRecoPos)
          STD_METHOD UpdateRecoPos, :ptr ISpSREngineSite, :ULONGLONG
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        ISpSREngineSiteVtbl ends
        ISpSREngineSite struct
          lpVtbl POINTER ?
        ISpSREngineSite ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpSREngineSite_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_sapiddk51_0000_0014 *
    ;* [local] *
    SPPROPSRC typedef SDWORD
    SPPROPSRC_RECO_INST equ 0
    SPPROPSRC_RECO_CTX equ
    SPPROPSRC_RECO_GRAMMAR equ

    externdef __MIDL_itf_sapiddk51_0000_0014_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_sapiddk51_0000_0014_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ISpSREngine_INTERFACE_DEFINED__
      __ISpSREngine_INTERFACE_DEFINED__ equ <>
      ;* interface ISpSREngine *
      ;* [local][unique][helpstring][uuid][object] *
      externdef IID_ISpSREngine:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISpSREngineVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISpSREngineVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISpSREngine, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISpSREngine
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISpSREngine
          DECLSPEC_XFGVIRT(ISpSREngine, SetSite)
          STD_METHOD SetSite, :ptr ISpSREngine, :ptr ISpSREngineSite
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpSREngine, GetInputAudioFormat)
          ;* [in] *
          ;* [in] *
          ;* [out] *
          ;* [out][annotation] *
          STD_METHOD GetInputAudioFormat, :ptr ISpSREngine, :ptr GUID, :ptr WAVEFORMATEX, :ptr GUID, :ptr ptr WAVEFORMATEX
          DECLSPEC_XFGVIRT(ISpSREngine, RecognizeStream)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD RecognizeStream, :ptr ISpSREngine, :REFGUID, :ptr WAVEFORMATEX, :HANDLE, :HANDLE, :HANDLE, :BOOL, :BOOL, :ptr ISpObjectToken
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpSREngine, SetRecoProfile)
          STD_METHOD SetRecoProfile, :ptr ISpSREngine, :ptr ISpObjectToken
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpSREngine, OnCreateGrammar)
          ;* [in] *
          ;* [in] *
          ;* [out][annotation] *
          STD_METHOD OnCreateGrammar, :ptr ISpSREngine, :ptr, :SPGRAMMARHANDLE, :ptr ptr
          DECLSPEC_XFGVIRT(ISpSREngine, OnDeleteGrammar)
          STD_METHOD OnDeleteGrammar, :ptr ISpSREngine, :ptr
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpSREngine, LoadProprietaryGrammar)
          ;* [in] *
          ;* [in] *
          ;* [string][in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD LoadProprietaryGrammar, :ptr ISpSREngine, :ptr, :REFGUID, :LPCWSTR, :ptr, :ULONG, :SPLOADOPTIONS
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpSREngine, UnloadProprietaryGrammar)
          STD_METHOD UnloadProprietaryGrammar, :ptr ISpSREngine, :ptr
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpSREngine, SetProprietaryRuleState)
          ;* [in] *
          ;* [string][in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD SetProprietaryRuleState, :ptr ISpSREngine, :ptr, :LPCWSTR, :ptr, :SPRULESTATE, :ptr ULONG
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpSREngine, SetProprietaryRuleIdState)
          ;* [in] *
          ;* [in] *
          STD_METHOD SetProprietaryRuleIdState, :ptr ISpSREngine, :ptr, :DWORD, :SPRULESTATE
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpSREngine, LoadSLM)
          ;* [in] *
          STD_METHOD LoadSLM, :ptr ISpSREngine, :ptr, :LPCWSTR
          ;* [string][in] *
          DECLSPEC_XFGVIRT(ISpSREngine, UnloadSLM)
          STD_METHOD UnloadSLM, :ptr ISpSREngine, :ptr
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpSREngine, SetSLMState)
          ;* [in] *
          STD_METHOD SetSLMState, :ptr ISpSREngine, :ptr, :SPRULESTATE
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpSREngine, SetWordSequenceData)
          ;* [in] *
          ;* [in][annotation] *
          ;* [in] *
          STD_METHOD SetWordSequenceData, :ptr ISpSREngine, :ptr, :ptr WCHAR, :ULONG, :ptr SPTEXTSELECTIONINFO
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpSREngine, SetTextSelection)
          ;* [in] *
          STD_METHOD SetTextSelection, :ptr ISpSREngine, :ptr, :ptr SPTEXTSELECTIONINFO
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpSREngine, IsPronounceable)
          ;* [in] *
          ;* [string][in] *
          STD_METHOD IsPronounceable, :ptr ISpSREngine, :ptr, :LPCWSTR, :ptr SPWORDPRONOUNCEABLE
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpSREngine, OnCreateRecoContext)
          ;* [in] *
          STD_METHOD OnCreateRecoContext, :ptr ISpSREngine, :SPRECOCONTEXTHANDLE, :ptr ptr
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpSREngine, OnDeleteRecoContext)
          STD_METHOD OnDeleteRecoContext, :ptr ISpSREngine, :ptr
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpSREngine, PrivateCall)
          ;* [in] *
          ;* [out][in] *
          STD_METHOD PrivateCall, :ptr ISpSREngine, :ptr, :PVOID, :ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpSREngine, SetAdaptationData)
          ;* [in] *
          ;* [annotation] *
          STD_METHOD SetAdaptationData, :ptr ISpSREngine, :ptr, :ptr WCHAR, :ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpSREngine, SetPropertyNum)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD SetPropertyNum, :ptr ISpSREngine, :SPPROPSRC, :ptr, :ptr WCHAR, :LONG
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpSREngine, GetPropertyNum)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD GetPropertyNum, :ptr ISpSREngine, :SPPROPSRC, :ptr, :ptr WCHAR, :ptr LONG
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpSREngine, SetPropertyString)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD SetPropertyString, :ptr ISpSREngine, :SPPROPSRC, :ptr, :LPCWSTR, :LPCWSTR
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpSREngine, GetPropertyString)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [out][annotation] *
          STD_METHOD GetPropertyString, :ptr ISpSREngine, :SPPROPSRC, :ptr, :LPCWSTR, :ptr LPWSTR
          DECLSPEC_XFGVIRT(ISpSREngine, SetGrammarState)
          ;* [in] *
          STD_METHOD SetGrammarState, :ptr ISpSREngine, :ptr, :SPGRAMMARSTATE
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpSREngine, WordNotify)
          ;* [in] *
          ;* [in] *
          STD_METHOD WordNotify, :ptr ISpSREngine, :SPCFGNOTIFY, :ULONG, :ptr SPWORDENTRY
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpSREngine, RuleNotify)
          ;* [in] *
          ;* [in] *
          STD_METHOD RuleNotify, :ptr ISpSREngine, :SPCFGNOTIFY, :ULONG, :ptr SPRULEENTRY
          ;* [in] *
          DECLSPEC_XFGVIRT(ISpSREngine, PrivateCallEx)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [out] *
          STD_METHOD PrivateCallEx, :ptr ISpSREngine, :ptr, :ptr, :ULONG, :ptr ptr, :ptr ULONG
          ;* [out] *
          DECLSPEC_XFGVIRT(ISpSREngine, SetContextState)
          ;* [in] *
          STD_METHOD SetContextState, :ptr ISpSREngine, :ptr, :SPCONTEXTSTATE
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        ISpSREngineVtbl ends
        ISpSREngine struct
          lpVtbl POINTER ?
        ISpSREngine ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISpSREngine_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_sapiddk51_0000_0015 *
    ;* [local] *
    SPPHRASEALTREQUEST struct
      ulStartElement DWORD ?
      cElements DWORD ?
      ulRequestAltCount DWORD ?
      pvResultExtra POINTER ?
      cbResultExtra DWORD ?
      pPhrase POINTER ?
      pRecoContext POINTER ?
    SPPHRASEALTREQUEST ends
    tagSPPHRASEALTREQUEST typedef SPPHRASEALTREQUEST
    externdef __MIDL_itf_sapiddk51_0000_0015_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_sapiddk51_0000_0015_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef ___ISpPrivateEngineCall_INTERFACE_DEFINED__
      ___ISpPrivateEngineCall_INTERFACE_DEFINED__ equ <>
      ;* interface _ISpPrivateEngineCall *
      ;* [local][unique][helpstring][uuid][object] *
      externdef IID__ISpPrivateEngineCall:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        _ISpPrivateEngineCallVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <_ISpPrivateEngineCallVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr _ISpPrivateEngineCall, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr _ISpPrivateEngineCall
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr _ISpPrivateEngineCall
          DECLSPEC_XFGVIRT(_ISpPrivateEngineCall, CallEngine)
          ;* [out][in][annotation] *
          STD_METHOD CallEngine, :ptr _ISpPrivateEngineCall, :ptr, :ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(_ISpPrivateEngineCall, CallEngineEx)
          ;* [in][annotation] *
          ;* [in] *
          ;* [out][annotation] *
          ;* [out][annotation] *
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
        ;* C style interface *
      endif
      ;* ___ISpPrivateEngineCall_INTERFACE_DEFINED__ *
    endif
    ifndef __SpeechDDKLib_LIBRARY_DEFINED__
      __SpeechDDKLib_LIBRARY_DEFINED__ equ <>
      ;* library SpeechDDKLib *
      ;* [version][uuid][helpstring] *
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
      externdef CLSID_SpGramCompBackend:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      ;* __SpeechDDKLib_LIBRARY_DEFINED__ *
    endif
    ;* interface __MIDL_itf_sapiddk51_0000_0017 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  externdef __MIDL_itf_sapiddk51_0000_0017_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_sapiddk51_0000_0017_v0_0_s_ifspec:RPC_IF_HANDLE
  ;* Additional Prototypes for ALL interfaces *
  ;* end of Additional Prototypes *
  ifdef __cplusplus
    ;[...]
  endif
endif
