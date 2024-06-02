;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\activdbg.h
;             Created on (UTC) 06/04/2024 06:15:51
;             Last modified on (UTC) 21/02/2024 18:15:40

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
ifndef __activdbg_h__
  __activdbg_h__ equ <>
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
  ifndef __IActiveScriptDebug32_FWD_DEFINED__
    __IActiveScriptDebug32_FWD_DEFINED__ equ <>
  endif
  ifndef __IActiveScriptDebug64_FWD_DEFINED__
    __IActiveScriptDebug64_FWD_DEFINED__ equ <>
  endif
  ifndef __IActiveScriptSiteDebug32_FWD_DEFINED__
    __IActiveScriptSiteDebug32_FWD_DEFINED__ equ <>
  endif
  ifndef __IActiveScriptSiteDebug64_FWD_DEFINED__
    __IActiveScriptSiteDebug64_FWD_DEFINED__ equ <>
  endif
  ifndef __IActiveScriptSiteDebugEx_FWD_DEFINED__
    __IActiveScriptSiteDebugEx_FWD_DEFINED__ equ <>
  endif
  ifndef __IActiveScriptErrorDebug_FWD_DEFINED__
    __IActiveScriptErrorDebug_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugCodeContext_FWD_DEFINED__
    __IDebugCodeContext_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugExpression_FWD_DEFINED__
    __IDebugExpression_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugExpressionContext_FWD_DEFINED__
    __IDebugExpressionContext_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugExpressionCallBack_FWD_DEFINED__
    __IDebugExpressionCallBack_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugStackFrame_FWD_DEFINED__
    __IDebugStackFrame_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugStackFrameSniffer_FWD_DEFINED__
    __IDebugStackFrameSniffer_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugStackFrameSnifferEx32_FWD_DEFINED__
    __IDebugStackFrameSnifferEx32_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugStackFrameSnifferEx64_FWD_DEFINED__
    __IDebugStackFrameSnifferEx64_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugSyncOperation_FWD_DEFINED__
    __IDebugSyncOperation_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugAsyncOperation_FWD_DEFINED__
    __IDebugAsyncOperation_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugAsyncOperationCallBack_FWD_DEFINED__
    __IDebugAsyncOperationCallBack_FWD_DEFINED__ equ <>
  endif
  ifndef __IEnumDebugCodeContexts_FWD_DEFINED__
    __IEnumDebugCodeContexts_FWD_DEFINED__ equ <>
  endif
  ifndef __IEnumDebugStackFrames_FWD_DEFINED__
    __IEnumDebugStackFrames_FWD_DEFINED__ equ <>
  endif
  ifndef __IEnumDebugStackFrames64_FWD_DEFINED__
    __IEnumDebugStackFrames64_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugDocumentInfo_FWD_DEFINED__
    __IDebugDocumentInfo_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugDocumentProvider_FWD_DEFINED__
    __IDebugDocumentProvider_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugDocument_FWD_DEFINED__
    __IDebugDocument_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugDocumentText_FWD_DEFINED__
    __IDebugDocumentText_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugDocumentTextEvents_FWD_DEFINED__
    __IDebugDocumentTextEvents_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugDocumentTextAuthor_FWD_DEFINED__
    __IDebugDocumentTextAuthor_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugDocumentTextExternalAuthor_FWD_DEFINED__
    __IDebugDocumentTextExternalAuthor_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugDocumentHelper32_FWD_DEFINED__
    __IDebugDocumentHelper32_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugDocumentHelper64_FWD_DEFINED__
    __IDebugDocumentHelper64_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugDocumentHost_FWD_DEFINED__
    __IDebugDocumentHost_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugDocumentContext_FWD_DEFINED__
    __IDebugDocumentContext_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugSessionProvider_FWD_DEFINED__
    __IDebugSessionProvider_FWD_DEFINED__ equ <>
  endif
  ifndef __IApplicationDebugger_FWD_DEFINED__
    __IApplicationDebugger_FWD_DEFINED__ equ <>
  endif
  ifndef __IApplicationDebuggerUI_FWD_DEFINED__
    __IApplicationDebuggerUI_FWD_DEFINED__ equ <>
  endif
  ifndef __IMachineDebugManager_FWD_DEFINED__
    __IMachineDebugManager_FWD_DEFINED__ equ <>
  endif
  ifndef __IMachineDebugManagerCookie_FWD_DEFINED__
    __IMachineDebugManagerCookie_FWD_DEFINED__ equ <>
  endif
  ifndef __IMachineDebugManagerEvents_FWD_DEFINED__
    __IMachineDebugManagerEvents_FWD_DEFINED__ equ <>
  endif
  ifndef __IProcessDebugManager32_FWD_DEFINED__
    __IProcessDebugManager32_FWD_DEFINED__ equ <>
  endif
  ifndef __IProcessDebugManager64_FWD_DEFINED__
    __IProcessDebugManager64_FWD_DEFINED__ equ <>
  endif
  ifndef __IRemoteDebugApplication_FWD_DEFINED__
    __IRemoteDebugApplication_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugApplication32_FWD_DEFINED__
    __IDebugApplication32_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugApplication64_FWD_DEFINED__
    __IDebugApplication64_FWD_DEFINED__ equ <>
  endif
  ifndef __IRemoteDebugApplicationEvents_FWD_DEFINED__
    __IRemoteDebugApplicationEvents_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugApplicationNode_FWD_DEFINED__
    __IDebugApplicationNode_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugApplicationNodeEvents_FWD_DEFINED__
    __IDebugApplicationNodeEvents_FWD_DEFINED__ equ <>
  endif
  ifndef __AsyncIDebugApplicationNodeEvents_FWD_DEFINED__
    __AsyncIDebugApplicationNodeEvents_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugThreadCall32_FWD_DEFINED__
    __IDebugThreadCall32_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugThreadCall64_FWD_DEFINED__
    __IDebugThreadCall64_FWD_DEFINED__ equ <>
  endif
  ifndef __IRemoteDebugApplicationThread_FWD_DEFINED__
    __IRemoteDebugApplicationThread_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugApplicationThread_FWD_DEFINED__
    __IDebugApplicationThread_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugApplicationThread64_FWD_DEFINED__
    __IDebugApplicationThread64_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugCookie_FWD_DEFINED__
    __IDebugCookie_FWD_DEFINED__ equ <>
  endif
  ifndef __IEnumDebugApplicationNodes_FWD_DEFINED__
    __IEnumDebugApplicationNodes_FWD_DEFINED__ equ <>
  endif
  ifndef __IEnumRemoteDebugApplications_FWD_DEFINED__
    __IEnumRemoteDebugApplications_FWD_DEFINED__ equ <>
  endif
  ifndef __IEnumRemoteDebugApplicationThreads_FWD_DEFINED__
    __IEnumRemoteDebugApplicationThreads_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugFormatter_FWD_DEFINED__
    __IDebugFormatter_FWD_DEFINED__ equ <>
  endif
  ifndef __ISimpleConnectionPoint_FWD_DEFINED__
    __ISimpleConnectionPoint_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugHelper_FWD_DEFINED__
    __IDebugHelper_FWD_DEFINED__ equ <>
  endif
  ifndef __IEnumDebugExpressionContexts_FWD_DEFINED__
    __IEnumDebugExpressionContexts_FWD_DEFINED__ equ <>
  endif
  ifndef __IProvideExpressionContexts_FWD_DEFINED__
    __IProvideExpressionContexts_FWD_DEFINED__ equ <>
  endif
  ifndef __IActiveScriptDebug32_FWD_DEFINED__
    __IActiveScriptDebug32_FWD_DEFINED__ equ <>
  endif
  ifndef __IActiveScriptDebug64_FWD_DEFINED__
    __IActiveScriptDebug64_FWD_DEFINED__ equ <>
  endif
  ifndef __IActiveScriptErrorDebug_FWD_DEFINED__
    __IActiveScriptErrorDebug_FWD_DEFINED__ equ <>
  endif
  ifndef __IActiveScriptSiteDebug32_FWD_DEFINED__
    __IActiveScriptSiteDebug32_FWD_DEFINED__ equ <>
  endif
  ifndef __IActiveScriptSiteDebug64_FWD_DEFINED__
    __IActiveScriptSiteDebug64_FWD_DEFINED__ equ <>
  endif
  ifndef __IActiveScriptSiteDebugEx_FWD_DEFINED__
    __IActiveScriptSiteDebugEx_FWD_DEFINED__ equ <>
  endif
  ifndef __IApplicationDebugger_FWD_DEFINED__
    __IApplicationDebugger_FWD_DEFINED__ equ <>
  endif
  ifndef __IApplicationDebuggerUI_FWD_DEFINED__
    __IApplicationDebuggerUI_FWD_DEFINED__ equ <>
  endif
  ifndef __IRemoteDebugApplication_FWD_DEFINED__
    __IRemoteDebugApplication_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugApplication32_FWD_DEFINED__
    __IDebugApplication32_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugApplication64_FWD_DEFINED__
    __IDebugApplication64_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugDocumentInfo_FWD_DEFINED__
    __IDebugDocumentInfo_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugDocumentProvider_FWD_DEFINED__
    __IDebugDocumentProvider_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugApplicationNode_FWD_DEFINED__
    __IDebugApplicationNode_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugApplicationNodeEvents_FWD_DEFINED__
    __IDebugApplicationNodeEvents_FWD_DEFINED__ equ <>
  endif
  ifndef __IRemoteDebugApplicationThread_FWD_DEFINED__
    __IRemoteDebugApplicationThread_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugApplicationThread_FWD_DEFINED__
    __IDebugApplicationThread_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugAsyncOperation_FWD_DEFINED__
    __IDebugAsyncOperation_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugAsyncOperationCallBack_FWD_DEFINED__
    __IDebugAsyncOperationCallBack_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugCodeContext_FWD_DEFINED__
    __IDebugCodeContext_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugCookie_FWD_DEFINED__
    __IDebugCookie_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugDocument_FWD_DEFINED__
    __IDebugDocument_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugDocumentContext_FWD_DEFINED__
    __IDebugDocumentContext_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugDocumentHelper32_FWD_DEFINED__
    __IDebugDocumentHelper32_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugDocumentHelper64_FWD_DEFINED__
    __IDebugDocumentHelper64_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugDocumentHost_FWD_DEFINED__
    __IDebugDocumentHost_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugDocumentText_FWD_DEFINED__
    __IDebugDocumentText_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugDocumentTextAuthor_FWD_DEFINED__
    __IDebugDocumentTextAuthor_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugDocumentTextEvents_FWD_DEFINED__
    __IDebugDocumentTextEvents_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugDocumentTextExternalAuthor_FWD_DEFINED__
    __IDebugDocumentTextExternalAuthor_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugExpression_FWD_DEFINED__
    __IDebugExpression_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugExpressionCallBack_FWD_DEFINED__
    __IDebugExpressionCallBack_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugExpressionContext_FWD_DEFINED__
    __IDebugExpressionContext_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugFormatter_FWD_DEFINED__
    __IDebugFormatter_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugHelper_FWD_DEFINED__
    __IDebugHelper_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugSessionProvider_FWD_DEFINED__
    __IDebugSessionProvider_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugStackFrame_FWD_DEFINED__
    __IDebugStackFrame_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugStackFrameSniffer_FWD_DEFINED__
    __IDebugStackFrameSniffer_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugStackFrameSnifferEx32_FWD_DEFINED__
    __IDebugStackFrameSnifferEx32_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugStackFrameSnifferEx64_FWD_DEFINED__
    __IDebugStackFrameSnifferEx64_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugSyncOperation_FWD_DEFINED__
    __IDebugSyncOperation_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugThreadCall32_FWD_DEFINED__
    __IDebugThreadCall32_FWD_DEFINED__ equ <>
  endif
  ifndef __IDebugThreadCall64_FWD_DEFINED__
    __IDebugThreadCall64_FWD_DEFINED__ equ <>
  endif
  ifndef __IEnumDebugApplicationNodes_FWD_DEFINED__
    __IEnumDebugApplicationNodes_FWD_DEFINED__ equ <>
  endif
  ifndef __IEnumDebugCodeContexts_FWD_DEFINED__
    __IEnumDebugCodeContexts_FWD_DEFINED__ equ <>
  endif
  ifndef __IEnumDebugExpressionContexts_FWD_DEFINED__
    __IEnumDebugExpressionContexts_FWD_DEFINED__ equ <>
  endif
  ifndef __IEnumDebugStackFrames_FWD_DEFINED__
    __IEnumDebugStackFrames_FWD_DEFINED__ equ <>
  endif
  ifndef __IEnumDebugStackFrames64_FWD_DEFINED__
    __IEnumDebugStackFrames64_FWD_DEFINED__ equ <>
  endif
  ifndef __IEnumRemoteDebugApplications_FWD_DEFINED__
    __IEnumRemoteDebugApplications_FWD_DEFINED__ equ <>
  endif
  ifndef __IEnumRemoteDebugApplicationThreads_FWD_DEFINED__
    __IEnumRemoteDebugApplicationThreads_FWD_DEFINED__ equ <>
  endif
  ifndef __IProcessDebugManager32_FWD_DEFINED__
    __IProcessDebugManager32_FWD_DEFINED__ equ <>
  endif
  ifndef __IProcessDebugManager64_FWD_DEFINED__
    __IProcessDebugManager64_FWD_DEFINED__ equ <>
  endif
  ifndef __IProvideExpressionContexts_FWD_DEFINED__
    __IProvideExpressionContexts_FWD_DEFINED__ equ <>
  endif
  ifndef __IMachineDebugManager_FWD_DEFINED__
    __IMachineDebugManager_FWD_DEFINED__ equ <>
  endif
  ifndef __IMachineDebugManagerCookie_FWD_DEFINED__
    __IMachineDebugManagerCookie_FWD_DEFINED__ equ <>
  endif
  ifndef __IMachineDebugManagerEvents_FWD_DEFINED__
    __IMachineDebugManagerEvents_FWD_DEFINED__ equ <>
  endif
  ifndef __IRemoteDebugApplicationEvents_FWD_DEFINED__
    __IRemoteDebugApplicationEvents_FWD_DEFINED__ equ <>
  endif
  ifndef __ISimpleConnectionPoint_FWD_DEFINED__
    __ISimpleConnectionPoint_FWD_DEFINED__ equ <>
  endif
  ifndef __ProcessDebugManager_FWD_DEFINED__
    __ProcessDebugManager_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __DebugHelper_FWD_DEFINED__
    __DebugHelper_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __CDebugDocumentHelper_FWD_DEFINED__
    __CDebugDocumentHelper_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __MachineDebugManager_RETAIL_FWD_DEFINED__
    __MachineDebugManager_RETAIL_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __MachineDebugManager_DEBUG_FWD_DEFINED__
    __MachineDebugManager_DEBUG_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __DefaultDebugSessionProvider_FWD_DEFINED__
    __DefaultDebugSessionProvider_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  include ocidl.inc
  include activscp.inc
  include dbgprop.inc
  ifdef __cplusplus
    ;[...]
  endif
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef __ActivDbg_h
      __ActivDbg_h equ <>
      BREAKPOINT_STATE typedef SDWORD
      BREAKPOINT_DELETED equ 0
      BREAKPOINT_DISABLED equ 1
      BREAKPOINT_ENABLED equ 2
      tagBREAKPOINT_STATE typedef BREAKPOINT_STATE

      APPBREAKFLAGS typedef DWORD
      APPBREAKFLAG_DEBUGGER_BLOCK equ (1h)
      APPBREAKFLAG_DEBUGGER_HALT equ (2h)
      APPBREAKFLAG_STEP equ (10000h)
      APPBREAKFLAG_NESTED equ (20000h)
      APPBREAKFLAG_STEPTYPE_SOURCE equ (0)
      APPBREAKFLAG_STEPTYPE_BYTECODE equ (100000h)
      APPBREAKFLAG_STEPTYPE_MACHINE equ (200000h)
      APPBREAKFLAG_STEPTYPE_MASK equ (0f00000h)
      APPBREAKFLAG_IN_BREAKPOINT equ (80000000h)
      BREAKREASON typedef SDWORD
      BREAKREASON_STEP equ 0
      BREAKREASON_BREAKPOINT equ 1
      BREAKREASON_DEBUGGER_BLOCK equ 2
      BREAKREASON_HOST_INITIATED equ 3
      BREAKREASON_LANGUAGE_INITIATED equ 4
      BREAKREASON_DEBUGGER_HALT equ 5
      BREAKREASON_ERROR equ 6
      BREAKREASON_JIT equ 7
      BREAKREASON_MUTATION_BREAKPOINT equ 8
      tagBREAKREASON typedef BREAKREASON

      BREAKRESUMEACTION typedef SDWORD
      BREAKRESUMEACTION_ABORT equ 0
      BREAKRESUMEACTION_CONTINUE equ 1
      BREAKRESUMEACTION_STEP_INTO equ 2
      BREAKRESUMEACTION_STEP_OVER equ 3
      BREAKRESUMEACTION_STEP_OUT equ 4
      BREAKRESUMEACTION_IGNORE equ 5
      BREAKRESUMEACTION_STEP_DOCUMENT equ 6
      tagBREAKRESUME_ACTION typedef BREAKRESUMEACTION

      ERRORRESUMEACTION typedef SDWORD
      ERRORRESUMEACTION_ReexecuteErrorStatement equ 0
      ERRORRESUMEACTION_AbortCallAndReturnErrorToCaller equ 1
      ERRORRESUMEACTION_SkipErrorStatement equ 2
      tagERRORRESUMEACTION typedef ERRORRESUMEACTION

      DOCUMENTNAMETYPE typedef SDWORD
      DOCUMENTNAMETYPE_APPNODE equ 0
      DOCUMENTNAMETYPE_TITLE equ 1
      DOCUMENTNAMETYPE_FILE_TAIL equ 2
      DOCUMENTNAMETYPE_URL equ 3
      DOCUMENTNAMETYPE_UNIQUE_TITLE equ 4
      DOCUMENTNAMETYPE_SOURCE_MAP_URL equ 5
      tagDOCUMENTNAMETYPE typedef DOCUMENTNAMETYPE

      SOURCE_TEXT_ATTR typedef WORD
      SOURCETEXT_ATTR_KEYWORD equ (1h)
      SOURCETEXT_ATTR_COMMENT equ (2h)
      SOURCETEXT_ATTR_NONSOURCE equ (4h)
      SOURCETEXT_ATTR_OPERATOR equ (8h)
      SOURCETEXT_ATTR_NUMBER equ (10h)
      SOURCETEXT_ATTR_STRING equ (20h)
      SOURCETEXT_ATTR_FUNCTION_START equ (40h)
      TEXT_DOC_ATTR typedef DWORD
      TEXT_DOC_ATTR_READONLY equ (1h)
      TEXT_DOC_ATTR_TYPE_PRIMARY equ (2h)
      TEXT_DOC_ATTR_TYPE_WORKER equ (4h)
      TEXT_DOC_ATTR_TYPE_SCRIPT equ (8h)
      DEBUG_TEXT_ISEXPRESSION equ (1h)
      DEBUG_TEXT_RETURNVALUE equ (2h)
      DEBUG_TEXT_NOSIDEEFFECTS equ (4h)
      DEBUG_TEXT_ALLOWBREAKPOINTS equ (8h)
      DEBUG_TEXT_ALLOWERRORREPORT equ (10h)
      DEBUG_TEXT_EVALUATETOCODECONTEXT equ (20h)
      DEBUG_TEXT_ISNONUSERCODE equ (40h)
      ifndef DISABLE_ACTIVDBG_INTERFACE_WRAPPERS
        ifdef _WIN64
          IActiveScriptDebug equ <IActiveScriptDebug64>
          IID_IActiveScriptDebug equ <IID_IActiveScriptDebug64>
        else
          IActiveScriptDebug equ <IActiveScriptDebug32>
          IID_IActiveScriptDebug equ <IID_IActiveScriptDebug32>
        endif
      endif
      externdef __MIDL_itf_activdbg_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_activdbg_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IActiveScriptDebug32_INTERFACE_DEFINED__
        __IActiveScriptDebug32_INTERFACE_DEFINED__ equ <>
        externdef IID_IActiveScriptDebug32:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptDebug32Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptDebug32Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IActiveScriptDebug32, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IActiveScriptDebug32
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IActiveScriptDebug32
            DECLSPEC_XFGVIRT(IActiveScriptDebug32, GetScriptTextAttributes)
            STD_METHOD GetScriptTextAttributes, :ptr IActiveScriptDebug32, :LPCOLESTR, :ULONG, :LPCOLESTR, :DWORD, :ptr SOURCE_TEXT_ATTR
            DECLSPEC_XFGVIRT(IActiveScriptDebug32, GetScriptletTextAttributes)
            STD_METHOD GetScriptletTextAttributes, :ptr IActiveScriptDebug32, :LPCOLESTR, :ULONG, :LPCOLESTR, :DWORD, :ptr SOURCE_TEXT_ATTR
            DECLSPEC_XFGVIRT(IActiveScriptDebug32, EnumCodeContextsOfPosition)
            STD_METHOD EnumCodeContextsOfPosition, :ptr IActiveScriptDebug32, :DWORD, :ULONG, :ULONG, :ptr ptr IEnumDebugCodeContexts
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptDebug32Vtbl ends
          IActiveScriptDebug32 struct
            lpVtbl POINTER ?
          IActiveScriptDebug32 ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IActiveScriptDebug64_INTERFACE_DEFINED__
        __IActiveScriptDebug64_INTERFACE_DEFINED__ equ <>
        externdef IID_IActiveScriptDebug64:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptDebug64Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptDebug64Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IActiveScriptDebug64, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IActiveScriptDebug64
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IActiveScriptDebug64
            DECLSPEC_XFGVIRT(IActiveScriptDebug64, GetScriptTextAttributes)
            STD_METHOD GetScriptTextAttributes, :ptr IActiveScriptDebug64, :LPCOLESTR, :ULONG, :LPCOLESTR, :DWORD, :ptr SOURCE_TEXT_ATTR
            DECLSPEC_XFGVIRT(IActiveScriptDebug64, GetScriptletTextAttributes)
            STD_METHOD GetScriptletTextAttributes, :ptr IActiveScriptDebug64, :LPCOLESTR, :ULONG, :LPCOLESTR, :DWORD, :ptr SOURCE_TEXT_ATTR
            DECLSPEC_XFGVIRT(IActiveScriptDebug64, EnumCodeContextsOfPosition)
            STD_METHOD EnumCodeContextsOfPosition, :ptr IActiveScriptDebug64, :DWORDLONG, :ULONG, :ULONG, :ptr ptr IEnumDebugCodeContexts
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptDebug64Vtbl ends
          IActiveScriptDebug64 struct
            lpVtbl POINTER ?
          IActiveScriptDebug64 ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef DISABLE_ACTIVDBG_INTERFACE_WRAPPERS
        ifdef _WIN64
          IActiveScriptSiteDebug equ <IActiveScriptSiteDebug64>
          IID_IActiveScriptSiteDebug equ <IID_IActiveScriptSiteDebug64>
        else
          IActiveScriptSiteDebug equ <IActiveScriptSiteDebug32>
          IID_IActiveScriptSiteDebug equ <IID_IActiveScriptSiteDebug32>
        endif
      endif
      externdef __MIDL_itf_activdbg_0000_0002_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_activdbg_0000_0002_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IActiveScriptSiteDebug32_INTERFACE_DEFINED__
        __IActiveScriptSiteDebug32_INTERFACE_DEFINED__ equ <>
        externdef IID_IActiveScriptSiteDebug32:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptSiteDebug32Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptSiteDebug32Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IActiveScriptSiteDebug32, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IActiveScriptSiteDebug32
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IActiveScriptSiteDebug32
            DECLSPEC_XFGVIRT(IActiveScriptSiteDebug32, GetDocumentContextFromPosition)
            STD_METHOD GetDocumentContextFromPosition, :ptr IActiveScriptSiteDebug32, :DWORD, :ULONG, :ULONG, :ptr ptr IDebugDocumentContext
            DECLSPEC_XFGVIRT(IActiveScriptSiteDebug32, GetApplication)
            STD_METHOD GetApplication, :ptr IActiveScriptSiteDebug32, :ptr ptr IDebugApplication32
            DECLSPEC_XFGVIRT(IActiveScriptSiteDebug32, GetRootApplicationNode)
            STD_METHOD GetRootApplicationNode, :ptr IActiveScriptSiteDebug32, :ptr ptr IDebugApplicationNode
            DECLSPEC_XFGVIRT(IActiveScriptSiteDebug32, OnScriptErrorDebug)
            STD_METHOD OnScriptErrorDebug, :ptr IActiveScriptSiteDebug32, :ptr IActiveScriptErrorDebug, :ptr BOOL, :ptr BOOL
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptSiteDebug32Vtbl ends
          IActiveScriptSiteDebug32 struct
            lpVtbl POINTER ?
          IActiveScriptSiteDebug32 ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IActiveScriptSiteDebug64_INTERFACE_DEFINED__
        __IActiveScriptSiteDebug64_INTERFACE_DEFINED__ equ <>
        externdef IID_IActiveScriptSiteDebug64:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptSiteDebug64Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptSiteDebug64Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IActiveScriptSiteDebug64, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IActiveScriptSiteDebug64
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IActiveScriptSiteDebug64
            DECLSPEC_XFGVIRT(IActiveScriptSiteDebug64, GetDocumentContextFromPosition)
            STD_METHOD GetDocumentContextFromPosition, :ptr IActiveScriptSiteDebug64, :DWORDLONG, :ULONG, :ULONG, :ptr ptr IDebugDocumentContext
            DECLSPEC_XFGVIRT(IActiveScriptSiteDebug64, GetApplication)
            STD_METHOD GetApplication, :ptr IActiveScriptSiteDebug64, :ptr ptr IDebugApplication64
            DECLSPEC_XFGVIRT(IActiveScriptSiteDebug64, GetRootApplicationNode)
            STD_METHOD GetRootApplicationNode, :ptr IActiveScriptSiteDebug64, :ptr ptr IDebugApplicationNode
            DECLSPEC_XFGVIRT(IActiveScriptSiteDebug64, OnScriptErrorDebug)
            STD_METHOD OnScriptErrorDebug, :ptr IActiveScriptSiteDebug64, :ptr IActiveScriptErrorDebug, :ptr BOOL, :ptr BOOL
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptSiteDebug64Vtbl ends
          IActiveScriptSiteDebug64 struct
            lpVtbl POINTER ?
          IActiveScriptSiteDebug64 ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IActiveScriptSiteDebugEx_INTERFACE_DEFINED__
        __IActiveScriptSiteDebugEx_INTERFACE_DEFINED__ equ <>
        externdef IID_IActiveScriptSiteDebugEx:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptSiteDebugExVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptSiteDebugExVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IActiveScriptSiteDebugEx, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IActiveScriptSiteDebugEx
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IActiveScriptSiteDebugEx
            DECLSPEC_XFGVIRT(IActiveScriptSiteDebugEx, OnCanNotJITScriptErrorDebug)
            STD_METHOD OnCanNotJITScriptErrorDebug, :ptr IActiveScriptSiteDebugEx, :ptr IActiveScriptErrorDebug, :ptr BOOL
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptSiteDebugExVtbl ends
          IActiveScriptSiteDebugEx struct
            lpVtbl POINTER ?
          IActiveScriptSiteDebugEx ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IActiveScriptErrorDebug_INTERFACE_DEFINED__
        __IActiveScriptErrorDebug_INTERFACE_DEFINED__ equ <>
        externdef IID_IActiveScriptErrorDebug:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptErrorDebugVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptErrorDebugVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IActiveScriptErrorDebug, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IActiveScriptErrorDebug
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IActiveScriptErrorDebug
            DECLSPEC_XFGVIRT(IActiveScriptError, GetExceptionInfo)
            STD_METHOD GetExceptionInfo, :ptr IActiveScriptErrorDebug, :ptr EXCEPINFO
            DECLSPEC_XFGVIRT(IActiveScriptError, GetSourcePosition)
            STD_METHOD GetSourcePosition, :ptr IActiveScriptErrorDebug, :ptr DWORD, :ptr ULONG, :ptr LONG
            DECLSPEC_XFGVIRT(IActiveScriptError, GetSourceLineText)
            STD_METHOD GetSourceLineText, :ptr IActiveScriptErrorDebug, :ptr BSTR
            DECLSPEC_XFGVIRT(IActiveScriptErrorDebug, GetDocumentContext)
            STD_METHOD GetDocumentContext, :ptr IActiveScriptErrorDebug, :ptr ptr IDebugDocumentContext
            DECLSPEC_XFGVIRT(IActiveScriptErrorDebug, GetStackFrame)
            STD_METHOD GetStackFrame, :ptr IActiveScriptErrorDebug, :ptr ptr IDebugStackFrame
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptErrorDebugVtbl ends
          IActiveScriptErrorDebug struct
            lpVtbl POINTER ?
          IActiveScriptErrorDebug ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IDebugCodeContext_INTERFACE_DEFINED__
        __IDebugCodeContext_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugCodeContext:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugCodeContextVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugCodeContextVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugCodeContext, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugCodeContext
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugCodeContext
            DECLSPEC_XFGVIRT(IDebugCodeContext, GetDocumentContext)
            STD_METHOD GetDocumentContext, :ptr IDebugCodeContext, :ptr ptr IDebugDocumentContext
            DECLSPEC_XFGVIRT(IDebugCodeContext, SetBreakPoint)
            STD_METHOD SetBreakPoint, :ptr IDebugCodeContext, :BREAKPOINT_STATE
            ??Interface equ <>
            END_INTERFACE
          IDebugCodeContextVtbl ends
          IDebugCodeContext struct
            lpVtbl POINTER ?
          IDebugCodeContext ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IDebugExpression_INTERFACE_DEFINED__
        __IDebugExpression_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugExpression:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugExpressionVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugExpressionVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugExpression, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugExpression
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugExpression
            DECLSPEC_XFGVIRT(IDebugExpression, Start)
            STD_METHOD Start, :ptr IDebugExpression, :ptr IDebugExpressionCallBack
            DECLSPEC_XFGVIRT(IDebugExpression, Abort)
            STD_METHOD Abort, :ptr IDebugExpression
            DECLSPEC_XFGVIRT(IDebugExpression, QueryIsComplete)
            STD_METHOD QueryIsComplete, :ptr IDebugExpression
            DECLSPEC_XFGVIRT(IDebugExpression, GetResultAsString)
            STD_METHOD GetResultAsString, :ptr IDebugExpression, :ptr HRESULT, :ptr BSTR
            DECLSPEC_XFGVIRT(IDebugExpression, GetResultAsDebugProperty)
            STD_METHOD GetResultAsDebugProperty, :ptr IDebugExpression, :ptr HRESULT, :ptr ptr IDebugProperty
            ??Interface equ <>
            END_INTERFACE
          IDebugExpressionVtbl ends
          IDebugExpression struct
            lpVtbl POINTER ?
          IDebugExpression ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IDebugExpressionContext_INTERFACE_DEFINED__
        __IDebugExpressionContext_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugExpressionContext:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugExpressionContextVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugExpressionContextVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugExpressionContext, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugExpressionContext
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugExpressionContext
            DECLSPEC_XFGVIRT(IDebugExpressionContext, ParseLanguageText)
            STD_METHOD ParseLanguageText, :ptr IDebugExpressionContext, :LPCOLESTR, :UINT, :LPCOLESTR, :DWORD, :ptr ptr IDebugExpression
            DECLSPEC_XFGVIRT(IDebugExpressionContext, GetLanguageInfo)
            STD_METHOD GetLanguageInfo, :ptr IDebugExpressionContext, :ptr BSTR, :ptr GUID
            ??Interface equ <>
            END_INTERFACE
          IDebugExpressionContextVtbl ends
          IDebugExpressionContext struct
            lpVtbl POINTER ?
          IDebugExpressionContext ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IDebugExpressionCallBack_INTERFACE_DEFINED__
        __IDebugExpressionCallBack_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugExpressionCallBack:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugExpressionCallBackVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugExpressionCallBackVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugExpressionCallBack, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugExpressionCallBack
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugExpressionCallBack
            DECLSPEC_XFGVIRT(IDebugExpressionCallBack, onComplete)
            STD_METHOD onComplete, :ptr IDebugExpressionCallBack
            ??Interface equ <>
            END_INTERFACE
          IDebugExpressionCallBackVtbl ends
          IDebugExpressionCallBack struct
            lpVtbl POINTER ?
          IDebugExpressionCallBack ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IDebugStackFrame_INTERFACE_DEFINED__
        __IDebugStackFrame_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugStackFrame:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugStackFrameVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugStackFrameVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugStackFrame, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugStackFrame
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugStackFrame
            DECLSPEC_XFGVIRT(IDebugStackFrame, GetCodeContext)
            STD_METHOD GetCodeContext, :ptr IDebugStackFrame, :ptr ptr IDebugCodeContext
            DECLSPEC_XFGVIRT(IDebugStackFrame, GetDescriptionString)
            STD_METHOD GetDescriptionString, :ptr IDebugStackFrame, :BOOL, :ptr BSTR
            DECLSPEC_XFGVIRT(IDebugStackFrame, GetLanguageString)
            STD_METHOD GetLanguageString, :ptr IDebugStackFrame, :BOOL, :ptr BSTR
            DECLSPEC_XFGVIRT(IDebugStackFrame, GetThread)
            STD_METHOD GetThread, :ptr IDebugStackFrame, :ptr ptr IDebugApplicationThread
            DECLSPEC_XFGVIRT(IDebugStackFrame, GetDebugProperty)
            STD_METHOD GetDebugProperty, :ptr IDebugStackFrame, :ptr ptr IDebugProperty
            ??Interface equ <>
            END_INTERFACE
          IDebugStackFrameVtbl ends
          IDebugStackFrame struct
            lpVtbl POINTER ?
          IDebugStackFrame ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IDebugStackFrameSniffer_INTERFACE_DEFINED__
        __IDebugStackFrameSniffer_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugStackFrameSniffer:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugStackFrameSnifferVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugStackFrameSnifferVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugStackFrameSniffer, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugStackFrameSniffer
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugStackFrameSniffer
            DECLSPEC_XFGVIRT(IDebugStackFrameSniffer, EnumStackFrames)
            STD_METHOD EnumStackFrames, :ptr IDebugStackFrameSniffer, :ptr ptr IEnumDebugStackFrames
            ??Interface equ <>
            END_INTERFACE
          IDebugStackFrameSnifferVtbl ends
          IDebugStackFrameSniffer struct
            lpVtbl POINTER ?
          IDebugStackFrameSniffer ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef DISABLE_ACTIVDBG_INTERFACE_WRAPPERS
        ifdef _WIN64
          IDebugStackFrameSnifferEx equ <IDebugStackFrameSnifferEx64>
          IID_IDebugStackFrameSnifferEx equ <IID_IDebugStackFrameSnifferEx64>
          EnumStackFramesEx equ <EnumStackFramesEx64>
        else
          IDebugStackFrameSnifferEx equ <IDebugStackFrameSnifferEx32>
          IID_IDebugStackFrameSnifferEx equ <IID_IDebugStackFrameSnifferEx32>
          EnumStackFramesEx equ <EnumStackFramesEx32>
        endif
      endif
      externdef __MIDL_itf_activdbg_0000_0012_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_activdbg_0000_0012_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDebugStackFrameSnifferEx32_INTERFACE_DEFINED__
        __IDebugStackFrameSnifferEx32_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugStackFrameSnifferEx32:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugStackFrameSnifferEx32Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugStackFrameSnifferEx32Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugStackFrameSnifferEx32, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugStackFrameSnifferEx32
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugStackFrameSnifferEx32
            DECLSPEC_XFGVIRT(IDebugStackFrameSniffer, EnumStackFrames)
            STD_METHOD EnumStackFrames, :ptr IDebugStackFrameSnifferEx32, :ptr ptr IEnumDebugStackFrames
            DECLSPEC_XFGVIRT(IDebugStackFrameSnifferEx32, EnumStackFramesEx32)
            STD_METHOD EnumStackFramesEx32, :ptr IDebugStackFrameSnifferEx32, :DWORD, :ptr ptr IEnumDebugStackFrames
            ??Interface equ <>
            END_INTERFACE
          IDebugStackFrameSnifferEx32Vtbl ends
          IDebugStackFrameSnifferEx32 struct
            lpVtbl POINTER ?
          IDebugStackFrameSnifferEx32 ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IDebugStackFrameSnifferEx64_INTERFACE_DEFINED__
        __IDebugStackFrameSnifferEx64_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugStackFrameSnifferEx64:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugStackFrameSnifferEx64Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugStackFrameSnifferEx64Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugStackFrameSnifferEx64, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugStackFrameSnifferEx64
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugStackFrameSnifferEx64
            DECLSPEC_XFGVIRT(IDebugStackFrameSniffer, EnumStackFrames)
            STD_METHOD EnumStackFrames, :ptr IDebugStackFrameSnifferEx64, :ptr ptr IEnumDebugStackFrames
            DECLSPEC_XFGVIRT(IDebugStackFrameSnifferEx64, EnumStackFramesEx64)
            STD_METHOD EnumStackFramesEx64, :ptr IDebugStackFrameSnifferEx64, :DWORDLONG, :ptr ptr IEnumDebugStackFrames64
            ??Interface equ <>
            END_INTERFACE
          IDebugStackFrameSnifferEx64Vtbl ends
          IDebugStackFrameSnifferEx64 struct
            lpVtbl POINTER ?
          IDebugStackFrameSnifferEx64 ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IDebugSyncOperation_INTERFACE_DEFINED__
        __IDebugSyncOperation_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugSyncOperation:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugSyncOperationVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugSyncOperationVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugSyncOperation, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugSyncOperation
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugSyncOperation
            DECLSPEC_XFGVIRT(IDebugSyncOperation, GetTargetThread)
            STD_METHOD GetTargetThread, :ptr IDebugSyncOperation, :ptr ptr IDebugApplicationThread
            DECLSPEC_XFGVIRT(IDebugSyncOperation, Execute)
            STD_METHOD Execute, :ptr IDebugSyncOperation, :ptr ptr IUnknown
            DECLSPEC_XFGVIRT(IDebugSyncOperation, InProgressAbort)
            STD_METHOD InProgressAbort, :ptr IDebugSyncOperation
            ??Interface equ <>
            END_INTERFACE
          IDebugSyncOperationVtbl ends
          IDebugSyncOperation struct
            lpVtbl POINTER ?
          IDebugSyncOperation ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IDebugAsyncOperation_INTERFACE_DEFINED__
        __IDebugAsyncOperation_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugAsyncOperation:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugAsyncOperationVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugAsyncOperationVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugAsyncOperation, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugAsyncOperation
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugAsyncOperation
            DECLSPEC_XFGVIRT(IDebugAsyncOperation, GetSyncDebugOperation)
            STD_METHOD GetSyncDebugOperation, :ptr IDebugAsyncOperation, :ptr ptr IDebugSyncOperation
            DECLSPEC_XFGVIRT(IDebugAsyncOperation, Start)
            STD_METHOD Start, :ptr IDebugAsyncOperation, :ptr IDebugAsyncOperationCallBack
            DECLSPEC_XFGVIRT(IDebugAsyncOperation, Abort)
            STD_METHOD Abort, :ptr IDebugAsyncOperation
            DECLSPEC_XFGVIRT(IDebugAsyncOperation, QueryIsComplete)
            STD_METHOD QueryIsComplete, :ptr IDebugAsyncOperation
            DECLSPEC_XFGVIRT(IDebugAsyncOperation, GetResult)
            STD_METHOD GetResult, :ptr IDebugAsyncOperation, :ptr HRESULT, :ptr ptr IUnknown
            ??Interface equ <>
            END_INTERFACE
          IDebugAsyncOperationVtbl ends
          IDebugAsyncOperation struct
            lpVtbl POINTER ?
          IDebugAsyncOperation ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IDebugAsyncOperationCallBack_INTERFACE_DEFINED__
        __IDebugAsyncOperationCallBack_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugAsyncOperationCallBack:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugAsyncOperationCallBackVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugAsyncOperationCallBackVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugAsyncOperationCallBack, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugAsyncOperationCallBack
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugAsyncOperationCallBack
            DECLSPEC_XFGVIRT(IDebugAsyncOperationCallBack, onComplete)
            STD_METHOD onComplete, :ptr IDebugAsyncOperationCallBack
            ??Interface equ <>
            END_INTERFACE
          IDebugAsyncOperationCallBackVtbl ends
          IDebugAsyncOperationCallBack struct
            lpVtbl POINTER ?
          IDebugAsyncOperationCallBack ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IEnumDebugCodeContexts_INTERFACE_DEFINED__
        __IEnumDebugCodeContexts_INTERFACE_DEFINED__ equ <>
        externdef IID_IEnumDebugCodeContexts:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IEnumDebugCodeContextsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEnumDebugCodeContextsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IEnumDebugCodeContexts, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IEnumDebugCodeContexts
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IEnumDebugCodeContexts
            DECLSPEC_XFGVIRT(IEnumDebugCodeContexts, Next)
            STD_METHOD Next, :ptr IEnumDebugCodeContexts, :ULONG, :ptr ptr IDebugCodeContext, :ptr ULONG
            DECLSPEC_XFGVIRT(IEnumDebugCodeContexts, Skip)
            STD_METHOD Skip, :ptr IEnumDebugCodeContexts, :ULONG
            DECLSPEC_XFGVIRT(IEnumDebugCodeContexts, Reset)
            STD_METHOD Reset, :ptr IEnumDebugCodeContexts
            DECLSPEC_XFGVIRT(IEnumDebugCodeContexts, Clone)
            STD_METHOD Clone, :ptr IEnumDebugCodeContexts, :ptr ptr IEnumDebugCodeContexts
            ??Interface equ <>
            END_INTERFACE
          IEnumDebugCodeContextsVtbl ends
          IEnumDebugCodeContexts struct
            lpVtbl POINTER ?
          IEnumDebugCodeContexts ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
        IEnumDebugCodeContexts_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumDebugCodeContexts, :ULONG, :ptr ptr IDebugCodeContext, :ptr ULONG
        IEnumDebugCodeContexts_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      endif
      DebugStackFrameDescriptor struct
        pdsf POINTER ?
        dwMin DWORD ?
        dwLim DWORD ?
        fFinal BOOL ?
        punkFinal POINTER ?
      DebugStackFrameDescriptor ends
      tagDebugStackFrameDescriptor typedef DebugStackFrameDescriptor
      DebugStackFrameDescriptor64 struct
        pdsf POINTER ?
        dwMin DWORDLONG ?
        dwLim DWORDLONG ?
        fFinal BOOL ?
        punkFinal POINTER ?
      DebugStackFrameDescriptor64 ends
      tagDebugStackFrameDescriptor64 typedef DebugStackFrameDescriptor64
      externdef __MIDL_itf_activdbg_0000_0018_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_activdbg_0000_0018_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IEnumDebugStackFrames_INTERFACE_DEFINED__
        __IEnumDebugStackFrames_INTERFACE_DEFINED__ equ <>
        externdef IID_IEnumDebugStackFrames:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IEnumDebugStackFramesVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEnumDebugStackFramesVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IEnumDebugStackFrames, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IEnumDebugStackFrames
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IEnumDebugStackFrames
            DECLSPEC_XFGVIRT(IEnumDebugStackFrames, Next)
            STD_METHOD Next, :ptr IEnumDebugStackFrames, :ULONG, :ptr DebugStackFrameDescriptor, :ptr ULONG
            DECLSPEC_XFGVIRT(IEnumDebugStackFrames, Skip)
            STD_METHOD Skip, :ptr IEnumDebugStackFrames, :ULONG
            DECLSPEC_XFGVIRT(IEnumDebugStackFrames, Reset)
            STD_METHOD Reset, :ptr IEnumDebugStackFrames
            DECLSPEC_XFGVIRT(IEnumDebugStackFrames, Clone)
            STD_METHOD Clone, :ptr IEnumDebugStackFrames, :ptr ptr IEnumDebugStackFrames
            ??Interface equ <>
            END_INTERFACE
          IEnumDebugStackFramesVtbl ends
          IEnumDebugStackFrames struct
            lpVtbl POINTER ?
          IEnumDebugStackFrames ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
        IEnumDebugStackFrames_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumDebugStackFrames, :ULONG, :ptr DebugStackFrameDescriptor, :ptr ULONG
        IEnumDebugStackFrames_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      endif
      ifndef __IEnumDebugStackFrames64_INTERFACE_DEFINED__
        __IEnumDebugStackFrames64_INTERFACE_DEFINED__ equ <>
        externdef IID_IEnumDebugStackFrames64:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IEnumDebugStackFrames64Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEnumDebugStackFrames64Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IEnumDebugStackFrames64, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IEnumDebugStackFrames64
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IEnumDebugStackFrames64
            DECLSPEC_XFGVIRT(IEnumDebugStackFrames, Next)
            STD_METHOD Next, :ptr IEnumDebugStackFrames64, :ULONG, :ptr DebugStackFrameDescriptor, :ptr ULONG
            DECLSPEC_XFGVIRT(IEnumDebugStackFrames, Skip)
            STD_METHOD Skip, :ptr IEnumDebugStackFrames64, :ULONG
            DECLSPEC_XFGVIRT(IEnumDebugStackFrames, Reset)
            STD_METHOD Reset, :ptr IEnumDebugStackFrames64
            DECLSPEC_XFGVIRT(IEnumDebugStackFrames, Clone)
            STD_METHOD Clone, :ptr IEnumDebugStackFrames64, :ptr ptr IEnumDebugStackFrames
            DECLSPEC_XFGVIRT(IEnumDebugStackFrames64, Next64)
            STD_METHOD Next64, :ptr IEnumDebugStackFrames64, :ULONG, :ptr DebugStackFrameDescriptor64, :ptr ULONG
            ??Interface equ <>
            END_INTERFACE
          IEnumDebugStackFrames64Vtbl ends
          IEnumDebugStackFrames64 struct
            lpVtbl POINTER ?
          IEnumDebugStackFrames64 ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
        IEnumDebugStackFrames64_RemoteNext64_Proxy proto WIN_STD_CALL_CONV :ptr IEnumDebugStackFrames64, :ULONG, :ptr DebugStackFrameDescriptor64, :ptr ULONG
        IEnumDebugStackFrames64_RemoteNext64_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      endif
      ifndef __IDebugDocumentInfo_INTERFACE_DEFINED__
        __IDebugDocumentInfo_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugDocumentInfo:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugDocumentInfoVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugDocumentInfoVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugDocumentInfo, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugDocumentInfo
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugDocumentInfo
            DECLSPEC_XFGVIRT(IDebugDocumentInfo, GetName)
            STD_METHOD GetName, :ptr IDebugDocumentInfo, :DOCUMENTNAMETYPE, :ptr BSTR
            DECLSPEC_XFGVIRT(IDebugDocumentInfo, GetDocumentClassId)
            STD_METHOD GetDocumentClassId, :ptr IDebugDocumentInfo, :ptr CLSID
            ??Interface equ <>
            END_INTERFACE
          IDebugDocumentInfoVtbl ends
          IDebugDocumentInfo struct
            lpVtbl POINTER ?
          IDebugDocumentInfo ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IDebugDocumentProvider_INTERFACE_DEFINED__
        __IDebugDocumentProvider_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugDocumentProvider:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugDocumentProviderVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugDocumentProviderVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugDocumentProvider, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugDocumentProvider
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugDocumentProvider
            DECLSPEC_XFGVIRT(IDebugDocumentInfo, GetName)
            STD_METHOD GetName, :ptr IDebugDocumentProvider, :DOCUMENTNAMETYPE, :ptr BSTR
            DECLSPEC_XFGVIRT(IDebugDocumentInfo, GetDocumentClassId)
            STD_METHOD GetDocumentClassId, :ptr IDebugDocumentProvider, :ptr CLSID
            DECLSPEC_XFGVIRT(IDebugDocumentProvider, GetDocument)
            STD_METHOD GetDocument, :ptr IDebugDocumentProvider, :ptr ptr IDebugDocument
            ??Interface equ <>
            END_INTERFACE
          IDebugDocumentProviderVtbl ends
          IDebugDocumentProvider struct
            lpVtbl POINTER ?
          IDebugDocumentProvider ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IDebugDocument_INTERFACE_DEFINED__
        __IDebugDocument_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugDocument:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugDocumentVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugDocumentVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugDocument, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugDocument
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugDocument
            DECLSPEC_XFGVIRT(IDebugDocumentInfo, GetName)
            STD_METHOD GetName, :ptr IDebugDocument, :DOCUMENTNAMETYPE, :ptr BSTR
            DECLSPEC_XFGVIRT(IDebugDocumentInfo, GetDocumentClassId)
            STD_METHOD GetDocumentClassId, :ptr IDebugDocument, :ptr CLSID
            ??Interface equ <>
            END_INTERFACE
          IDebugDocumentVtbl ends
          IDebugDocument struct
            lpVtbl POINTER ?
          IDebugDocument ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      externdef __MIDL_itf_activdbg_0000_0023_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_activdbg_0000_0023_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDebugDocumentText_INTERFACE_DEFINED__
        __IDebugDocumentText_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugDocumentText:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugDocumentTextVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugDocumentTextVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugDocumentText, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugDocumentText
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugDocumentText
            DECLSPEC_XFGVIRT(IDebugDocumentInfo, GetName)
            STD_METHOD GetName, :ptr IDebugDocumentText, :DOCUMENTNAMETYPE, :ptr BSTR
            DECLSPEC_XFGVIRT(IDebugDocumentInfo, GetDocumentClassId)
            STD_METHOD GetDocumentClassId, :ptr IDebugDocumentText, :ptr CLSID
            DECLSPEC_XFGVIRT(IDebugDocumentText, GetDocumentAttributes)
            STD_METHOD GetDocumentAttributes, :ptr IDebugDocumentText, :ptr TEXT_DOC_ATTR
            DECLSPEC_XFGVIRT(IDebugDocumentText, GetSize)
            STD_METHOD GetSize, :ptr IDebugDocumentText, :ptr ULONG, :ptr ULONG
            DECLSPEC_XFGVIRT(IDebugDocumentText, GetPositionOfLine)
            STD_METHOD GetPositionOfLine, :ptr IDebugDocumentText, :ULONG, :ptr ULONG
            DECLSPEC_XFGVIRT(IDebugDocumentText, GetLineOfPosition)
            STD_METHOD GetLineOfPosition, :ptr IDebugDocumentText, :ULONG, :ptr ULONG, :ptr ULONG
            DECLSPEC_XFGVIRT(IDebugDocumentText, GetText)
            STD_METHOD GetText, :ptr IDebugDocumentText, :ULONG, :ptr WCHAR, :ptr SOURCE_TEXT_ATTR, :ptr ULONG, :ULONG
            DECLSPEC_XFGVIRT(IDebugDocumentText, GetPositionOfContext)
            STD_METHOD GetPositionOfContext, :ptr IDebugDocumentText, :ptr IDebugDocumentContext, :ptr ULONG, :ptr ULONG
            DECLSPEC_XFGVIRT(IDebugDocumentText, GetContextOfPosition)
            STD_METHOD GetContextOfPosition, :ptr IDebugDocumentText, :ULONG, :ULONG, :ptr ptr IDebugDocumentContext
            ??Interface equ <>
            END_INTERFACE
          IDebugDocumentTextVtbl ends
          IDebugDocumentText struct
            lpVtbl POINTER ?
          IDebugDocumentText ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      externdef __MIDL_itf_activdbg_0000_0024_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_activdbg_0000_0024_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDebugDocumentTextEvents_INTERFACE_DEFINED__
        __IDebugDocumentTextEvents_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugDocumentTextEvents:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugDocumentTextEventsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugDocumentTextEventsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugDocumentTextEvents, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugDocumentTextEvents
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugDocumentTextEvents
            DECLSPEC_XFGVIRT(IDebugDocumentTextEvents, onDestroy)
            STD_METHOD onDestroy, :ptr IDebugDocumentTextEvents
            DECLSPEC_XFGVIRT(IDebugDocumentTextEvents, onInsertText)
            STD_METHOD onInsertText, :ptr IDebugDocumentTextEvents, :ULONG, :ULONG
            DECLSPEC_XFGVIRT(IDebugDocumentTextEvents, onRemoveText)
            STD_METHOD onRemoveText, :ptr IDebugDocumentTextEvents, :ULONG, :ULONG
            DECLSPEC_XFGVIRT(IDebugDocumentTextEvents, onReplaceText)
            STD_METHOD onReplaceText, :ptr IDebugDocumentTextEvents, :ULONG, :ULONG
            DECLSPEC_XFGVIRT(IDebugDocumentTextEvents, onUpdateTextAttributes)
            STD_METHOD onUpdateTextAttributes, :ptr IDebugDocumentTextEvents, :ULONG, :ULONG
            DECLSPEC_XFGVIRT(IDebugDocumentTextEvents, onUpdateDocumentAttributes)
            STD_METHOD onUpdateDocumentAttributes, :ptr IDebugDocumentTextEvents, :TEXT_DOC_ATTR
            ??Interface equ <>
            END_INTERFACE
          IDebugDocumentTextEventsVtbl ends
          IDebugDocumentTextEvents struct
            lpVtbl POINTER ?
          IDebugDocumentTextEvents ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      externdef __MIDL_itf_activdbg_0000_0025_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_activdbg_0000_0025_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDebugDocumentTextAuthor_INTERFACE_DEFINED__
        __IDebugDocumentTextAuthor_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugDocumentTextAuthor:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugDocumentTextAuthorVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugDocumentTextAuthorVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugDocumentTextAuthor, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugDocumentTextAuthor
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugDocumentTextAuthor
            DECLSPEC_XFGVIRT(IDebugDocumentInfo, GetName)
            STD_METHOD GetName, :ptr IDebugDocumentTextAuthor, :DOCUMENTNAMETYPE, :ptr BSTR
            DECLSPEC_XFGVIRT(IDebugDocumentInfo, GetDocumentClassId)
            STD_METHOD GetDocumentClassId, :ptr IDebugDocumentTextAuthor, :ptr CLSID
            DECLSPEC_XFGVIRT(IDebugDocumentText, GetDocumentAttributes)
            STD_METHOD GetDocumentAttributes, :ptr IDebugDocumentTextAuthor, :ptr TEXT_DOC_ATTR
            DECLSPEC_XFGVIRT(IDebugDocumentText, GetSize)
            STD_METHOD GetSize, :ptr IDebugDocumentTextAuthor, :ptr ULONG, :ptr ULONG
            DECLSPEC_XFGVIRT(IDebugDocumentText, GetPositionOfLine)
            STD_METHOD GetPositionOfLine, :ptr IDebugDocumentTextAuthor, :ULONG, :ptr ULONG
            DECLSPEC_XFGVIRT(IDebugDocumentText, GetLineOfPosition)
            STD_METHOD GetLineOfPosition, :ptr IDebugDocumentTextAuthor, :ULONG, :ptr ULONG, :ptr ULONG
            DECLSPEC_XFGVIRT(IDebugDocumentText, GetText)
            STD_METHOD GetText, :ptr IDebugDocumentTextAuthor, :ULONG, :ptr WCHAR, :ptr SOURCE_TEXT_ATTR, :ptr ULONG, :ULONG
            DECLSPEC_XFGVIRT(IDebugDocumentText, GetPositionOfContext)
            STD_METHOD GetPositionOfContext, :ptr IDebugDocumentTextAuthor, :ptr IDebugDocumentContext, :ptr ULONG, :ptr ULONG
            DECLSPEC_XFGVIRT(IDebugDocumentText, GetContextOfPosition)
            STD_METHOD GetContextOfPosition, :ptr IDebugDocumentTextAuthor, :ULONG, :ULONG, :ptr ptr IDebugDocumentContext
            DECLSPEC_XFGVIRT(IDebugDocumentTextAuthor, InsertText)
            STD_METHOD InsertText, :ptr IDebugDocumentTextAuthor, :ULONG, :ULONG, :ptr OLECHAR
            DECLSPEC_XFGVIRT(IDebugDocumentTextAuthor, RemoveText)
            STD_METHOD RemoveText, :ptr IDebugDocumentTextAuthor, :ULONG, :ULONG
            DECLSPEC_XFGVIRT(IDebugDocumentTextAuthor, ReplaceText)
            STD_METHOD ReplaceText, :ptr IDebugDocumentTextAuthor, :ULONG, :ULONG, :ptr OLECHAR
            ??Interface equ <>
            END_INTERFACE
          IDebugDocumentTextAuthorVtbl ends
          IDebugDocumentTextAuthor struct
            lpVtbl POINTER ?
          IDebugDocumentTextAuthor ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      externdef __MIDL_itf_activdbg_0000_0026_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_activdbg_0000_0026_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDebugDocumentTextExternalAuthor_INTERFACE_DEFINED__
        __IDebugDocumentTextExternalAuthor_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugDocumentTextExternalAuthor:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugDocumentTextExternalAuthorVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugDocumentTextExternalAuthorVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugDocumentTextExternalAuthor, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugDocumentTextExternalAuthor
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugDocumentTextExternalAuthor
            DECLSPEC_XFGVIRT(IDebugDocumentTextExternalAuthor, GetPathName)
            STD_METHOD GetPathName, :ptr IDebugDocumentTextExternalAuthor, :ptr BSTR, :ptr BOOL
            DECLSPEC_XFGVIRT(IDebugDocumentTextExternalAuthor, GetFileName)
            STD_METHOD GetFileName, :ptr IDebugDocumentTextExternalAuthor, :ptr BSTR
            DECLSPEC_XFGVIRT(IDebugDocumentTextExternalAuthor, NotifyChanged)
            STD_METHOD NotifyChanged, :ptr IDebugDocumentTextExternalAuthor
            ??Interface equ <>
            END_INTERFACE
          IDebugDocumentTextExternalAuthorVtbl ends
          IDebugDocumentTextExternalAuthor struct
            lpVtbl POINTER ?
          IDebugDocumentTextExternalAuthor ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef DISABLE_ACTIVDBG_INTERFACE_WRAPPERS
        ifdef _WIN64
          IDebugDocumentHelper equ <IDebugDocumentHelper64>
          IID_IDebugDocumentHelper equ <IID_IDebugDocumentHelper64>
        else
          IDebugDocumentHelper equ <IDebugDocumentHelper32>
          IID_IDebugDocumentHelper equ <IID_IDebugDocumentHelper32>
        endif
      endif
      externdef __MIDL_itf_activdbg_0000_0027_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_activdbg_0000_0027_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDebugDocumentHelper32_INTERFACE_DEFINED__
        __IDebugDocumentHelper32_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugDocumentHelper32:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugDocumentHelper32Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugDocumentHelper32Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugDocumentHelper32, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugDocumentHelper32
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugDocumentHelper32
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, Init)
            STD_METHOD Init, :ptr IDebugDocumentHelper32, :ptr IDebugApplication32, :LPCOLESTR, :LPCOLESTR, :TEXT_DOC_ATTR
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, Attach)
            STD_METHOD Attach, :ptr IDebugDocumentHelper32, :ptr IDebugDocumentHelper32
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, Detach)
            STD_METHOD Detach, :ptr IDebugDocumentHelper32
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, AddUnicodeText)
            STD_METHOD AddUnicodeText, :ptr IDebugDocumentHelper32, :LPCOLESTR
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, AddDBCSText)
            STD_METHOD AddDBCSText, :ptr IDebugDocumentHelper32, :LPCSTR
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, SetDebugDocumentHost)
            STD_METHOD SetDebugDocumentHost, :ptr IDebugDocumentHelper32, :ptr IDebugDocumentHost
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, AddDeferredText)
            STD_METHOD AddDeferredText, :ptr IDebugDocumentHelper32, :ULONG, :DWORD
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, DefineScriptBlock)
            STD_METHOD DefineScriptBlock, :ptr IDebugDocumentHelper32, :ULONG, :ULONG, :ptr IActiveScript, :BOOL, :ptr DWORD
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, SetDefaultTextAttr)
            STD_METHOD SetDefaultTextAttr, :ptr IDebugDocumentHelper32, :SOURCE_TEXT_ATTR
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, SetTextAttributes)
            STD_METHOD SetTextAttributes, :ptr IDebugDocumentHelper32, :ULONG, :ULONG, :ptr SOURCE_TEXT_ATTR
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, SetLongName)
            STD_METHOD SetLongName, :ptr IDebugDocumentHelper32, :LPCOLESTR
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, SetShortName)
            STD_METHOD SetShortName, :ptr IDebugDocumentHelper32, :LPCOLESTR
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, SetDocumentAttr)
            STD_METHOD SetDocumentAttr, :ptr IDebugDocumentHelper32, :TEXT_DOC_ATTR
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, GetDebugApplicationNode)
            STD_METHOD GetDebugApplicationNode, :ptr IDebugDocumentHelper32, :ptr ptr IDebugApplicationNode
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, GetScriptBlockInfo)
            STD_METHOD GetScriptBlockInfo, :ptr IDebugDocumentHelper32, :DWORD, :ptr ptr IActiveScript, :ptr ULONG, :ptr ULONG
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, CreateDebugDocumentContext)
            STD_METHOD CreateDebugDocumentContext, :ptr IDebugDocumentHelper32, :ULONG, :ULONG, :ptr ptr IDebugDocumentContext
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, BringDocumentToTop)
            STD_METHOD BringDocumentToTop, :ptr IDebugDocumentHelper32
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, BringDocumentContextToTop)
            STD_METHOD BringDocumentContextToTop, :ptr IDebugDocumentHelper32, :ptr IDebugDocumentContext
            ??Interface equ <>
            END_INTERFACE
          IDebugDocumentHelper32Vtbl ends
          IDebugDocumentHelper32 struct
            lpVtbl POINTER ?
          IDebugDocumentHelper32 ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IDebugDocumentHelper64_INTERFACE_DEFINED__
        __IDebugDocumentHelper64_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugDocumentHelper64:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugDocumentHelper64Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugDocumentHelper64Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugDocumentHelper64, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugDocumentHelper64
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugDocumentHelper64
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, Init)
            STD_METHOD Init, :ptr IDebugDocumentHelper64, :ptr IDebugApplication64, :LPCOLESTR, :LPCOLESTR, :TEXT_DOC_ATTR
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, Attach)
            STD_METHOD Attach, :ptr IDebugDocumentHelper64, :ptr IDebugDocumentHelper64
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, Detach)
            STD_METHOD Detach, :ptr IDebugDocumentHelper64
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, AddUnicodeText)
            STD_METHOD AddUnicodeText, :ptr IDebugDocumentHelper64, :LPCOLESTR
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, AddDBCSText)
            STD_METHOD AddDBCSText, :ptr IDebugDocumentHelper64, :LPCSTR
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, SetDebugDocumentHost)
            STD_METHOD SetDebugDocumentHost, :ptr IDebugDocumentHelper64, :ptr IDebugDocumentHost
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, AddDeferredText)
            STD_METHOD AddDeferredText, :ptr IDebugDocumentHelper64, :ULONG, :DWORD
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, DefineScriptBlock)
            STD_METHOD DefineScriptBlock, :ptr IDebugDocumentHelper64, :ULONG, :ULONG, :ptr IActiveScript, :BOOL, :ptr DWORDLONG
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, SetDefaultTextAttr)
            STD_METHOD SetDefaultTextAttr, :ptr IDebugDocumentHelper64, :SOURCE_TEXT_ATTR
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, SetTextAttributes)
            STD_METHOD SetTextAttributes, :ptr IDebugDocumentHelper64, :ULONG, :ULONG, :ptr SOURCE_TEXT_ATTR
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, SetLongName)
            STD_METHOD SetLongName, :ptr IDebugDocumentHelper64, :LPCOLESTR
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, SetShortName)
            STD_METHOD SetShortName, :ptr IDebugDocumentHelper64, :LPCOLESTR
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, SetDocumentAttr)
            STD_METHOD SetDocumentAttr, :ptr IDebugDocumentHelper64, :TEXT_DOC_ATTR
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, GetDebugApplicationNode)
            STD_METHOD GetDebugApplicationNode, :ptr IDebugDocumentHelper64, :ptr ptr IDebugApplicationNode
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, GetScriptBlockInfo)
            STD_METHOD GetScriptBlockInfo, :ptr IDebugDocumentHelper64, :DWORDLONG, :ptr ptr IActiveScript, :ptr ULONG, :ptr ULONG
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, CreateDebugDocumentContext)
            STD_METHOD CreateDebugDocumentContext, :ptr IDebugDocumentHelper64, :ULONG, :ULONG, :ptr ptr IDebugDocumentContext
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, BringDocumentToTop)
            STD_METHOD BringDocumentToTop, :ptr IDebugDocumentHelper64
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, BringDocumentContextToTop)
            STD_METHOD BringDocumentContextToTop, :ptr IDebugDocumentHelper64, :ptr IDebugDocumentContext
            ??Interface equ <>
            END_INTERFACE
          IDebugDocumentHelper64Vtbl ends
          IDebugDocumentHelper64 struct
            lpVtbl POINTER ?
          IDebugDocumentHelper64 ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      externdef __MIDL_itf_activdbg_0000_0029_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_activdbg_0000_0029_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDebugDocumentHost_INTERFACE_DEFINED__
        __IDebugDocumentHost_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugDocumentHost:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugDocumentHostVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugDocumentHostVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugDocumentHost, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugDocumentHost
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugDocumentHost
            DECLSPEC_XFGVIRT(IDebugDocumentHost, GetDeferredText)
            STD_METHOD GetDeferredText, :ptr IDebugDocumentHost, :DWORD, :ptr WCHAR, :ptr SOURCE_TEXT_ATTR, :ptr ULONG, :ULONG
            DECLSPEC_XFGVIRT(IDebugDocumentHost, GetScriptTextAttributes)
            STD_METHOD GetScriptTextAttributes, :ptr IDebugDocumentHost, :LPCOLESTR, :ULONG, :LPCOLESTR, :DWORD, :ptr SOURCE_TEXT_ATTR
            DECLSPEC_XFGVIRT(IDebugDocumentHost, OnCreateDocumentContext)
            STD_METHOD OnCreateDocumentContext, :ptr IDebugDocumentHost, :ptr ptr IUnknown
            DECLSPEC_XFGVIRT(IDebugDocumentHost, GetPathName)
            STD_METHOD GetPathName, :ptr IDebugDocumentHost, :ptr BSTR, :ptr BOOL
            DECLSPEC_XFGVIRT(IDebugDocumentHost, GetFileName)
            STD_METHOD GetFileName, :ptr IDebugDocumentHost, :ptr BSTR
            DECLSPEC_XFGVIRT(IDebugDocumentHost, NotifyChanged)
            STD_METHOD NotifyChanged, :ptr IDebugDocumentHost
            ??Interface equ <>
            END_INTERFACE
          IDebugDocumentHostVtbl ends
          IDebugDocumentHost struct
            lpVtbl POINTER ?
          IDebugDocumentHost ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      externdef __MIDL_itf_activdbg_0000_0030_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_activdbg_0000_0030_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDebugDocumentContext_INTERFACE_DEFINED__
        __IDebugDocumentContext_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugDocumentContext:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugDocumentContextVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugDocumentContextVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugDocumentContext, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugDocumentContext
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugDocumentContext
            DECLSPEC_XFGVIRT(IDebugDocumentContext, GetDocument)
            STD_METHOD GetDocument, :ptr IDebugDocumentContext, :ptr ptr IDebugDocument
            DECLSPEC_XFGVIRT(IDebugDocumentContext, EnumCodeContexts)
            STD_METHOD EnumCodeContexts, :ptr IDebugDocumentContext, :ptr ptr IEnumDebugCodeContexts
            ??Interface equ <>
            END_INTERFACE
          IDebugDocumentContextVtbl ends
          IDebugDocumentContext struct
            lpVtbl POINTER ?
          IDebugDocumentContext ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IDebugSessionProvider_INTERFACE_DEFINED__
        __IDebugSessionProvider_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugSessionProvider:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugSessionProviderVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugSessionProviderVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugSessionProvider, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugSessionProvider
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugSessionProvider
            DECLSPEC_XFGVIRT(IDebugSessionProvider, StartDebugSession)
            STD_METHOD StartDebugSession, :ptr IDebugSessionProvider, :ptr IRemoteDebugApplication
            ??Interface equ <>
            END_INTERFACE
          IDebugSessionProviderVtbl ends
          IDebugSessionProvider struct
            lpVtbl POINTER ?
          IDebugSessionProvider ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IApplicationDebugger_INTERFACE_DEFINED__
        __IApplicationDebugger_INTERFACE_DEFINED__ equ <>
        externdef IID_IApplicationDebugger:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IApplicationDebuggerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IApplicationDebuggerVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IApplicationDebugger, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IApplicationDebugger
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IApplicationDebugger
            DECLSPEC_XFGVIRT(IApplicationDebugger, QueryAlive)
            STD_METHOD QueryAlive, :ptr IApplicationDebugger
            DECLSPEC_XFGVIRT(IApplicationDebugger, CreateInstanceAtDebugger)
            STD_METHOD CreateInstanceAtDebugger, :ptr IApplicationDebugger, :REFCLSID, :ptr IUnknown, :DWORD, :REFIID, :ptr ptr IUnknown
            DECLSPEC_XFGVIRT(IApplicationDebugger, onDebugOutput)
            STD_METHOD onDebugOutput, :ptr IApplicationDebugger, :LPCOLESTR
            DECLSPEC_XFGVIRT(IApplicationDebugger, onHandleBreakPoint)
            STD_METHOD onHandleBreakPoint, :ptr IApplicationDebugger, :ptr IRemoteDebugApplicationThread, :BREAKREASON, :ptr IActiveScriptErrorDebug
            DECLSPEC_XFGVIRT(IApplicationDebugger, onClose)
            STD_METHOD onClose, :ptr IApplicationDebugger
            DECLSPEC_XFGVIRT(IApplicationDebugger, onDebuggerEvent)
            STD_METHOD onDebuggerEvent, :ptr IApplicationDebugger, :REFIID, :ptr IUnknown
            ??Interface equ <>
            END_INTERFACE
          IApplicationDebuggerVtbl ends
          IApplicationDebugger struct
            lpVtbl POINTER ?
          IApplicationDebugger ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IApplicationDebuggerUI_INTERFACE_DEFINED__
        __IApplicationDebuggerUI_INTERFACE_DEFINED__ equ <>
        externdef IID_IApplicationDebuggerUI:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IApplicationDebuggerUIVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IApplicationDebuggerUIVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IApplicationDebuggerUI, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IApplicationDebuggerUI
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IApplicationDebuggerUI
            DECLSPEC_XFGVIRT(IApplicationDebuggerUI, BringDocumentToTop)
            STD_METHOD BringDocumentToTop, :ptr IApplicationDebuggerUI, :ptr IDebugDocumentText
            DECLSPEC_XFGVIRT(IApplicationDebuggerUI, BringDocumentContextToTop)
            STD_METHOD BringDocumentContextToTop, :ptr IApplicationDebuggerUI, :ptr IDebugDocumentContext
            ??Interface equ <>
            END_INTERFACE
          IApplicationDebuggerUIVtbl ends
          IApplicationDebuggerUI struct
            lpVtbl POINTER ?
          IApplicationDebuggerUI ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      externdef CLSID_MachineDebugManager:CLSID
      externdef __MIDL_itf_activdbg_0000_0034_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_activdbg_0000_0034_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IMachineDebugManager_INTERFACE_DEFINED__
        __IMachineDebugManager_INTERFACE_DEFINED__ equ <>
        externdef IID_IMachineDebugManager:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IMachineDebugManagerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IMachineDebugManagerVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IMachineDebugManager, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IMachineDebugManager
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IMachineDebugManager
            DECLSPEC_XFGVIRT(IMachineDebugManager, AddApplication)
            STD_METHOD AddApplication, :ptr IMachineDebugManager, :ptr IRemoteDebugApplication, :ptr DWORD
            DECLSPEC_XFGVIRT(IMachineDebugManager, RemoveApplication)
            STD_METHOD RemoveApplication, :ptr IMachineDebugManager, :DWORD
            DECLSPEC_XFGVIRT(IMachineDebugManager, EnumApplications)
            STD_METHOD EnumApplications, :ptr IMachineDebugManager, :ptr ptr IEnumRemoteDebugApplications
            ??Interface equ <>
            END_INTERFACE
          IMachineDebugManagerVtbl ends
          IMachineDebugManager struct
            lpVtbl POINTER ?
          IMachineDebugManager ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IMachineDebugManagerCookie_INTERFACE_DEFINED__
        __IMachineDebugManagerCookie_INTERFACE_DEFINED__ equ <>
        externdef IID_IMachineDebugManagerCookie:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IMachineDebugManagerCookieVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IMachineDebugManagerCookieVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IMachineDebugManagerCookie, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IMachineDebugManagerCookie
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IMachineDebugManagerCookie
            DECLSPEC_XFGVIRT(IMachineDebugManagerCookie, AddApplication)
            STD_METHOD AddApplication, :ptr IMachineDebugManagerCookie, :ptr IRemoteDebugApplication, :DWORD, :ptr DWORD
            DECLSPEC_XFGVIRT(IMachineDebugManagerCookie, RemoveApplication)
            STD_METHOD RemoveApplication, :ptr IMachineDebugManagerCookie, :DWORD, :DWORD
            DECLSPEC_XFGVIRT(IMachineDebugManagerCookie, EnumApplications)
            STD_METHOD EnumApplications, :ptr IMachineDebugManagerCookie, :ptr ptr IEnumRemoteDebugApplications
            ??Interface equ <>
            END_INTERFACE
          IMachineDebugManagerCookieVtbl ends
          IMachineDebugManagerCookie struct
            lpVtbl POINTER ?
          IMachineDebugManagerCookie ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IMachineDebugManagerEvents_INTERFACE_DEFINED__
        __IMachineDebugManagerEvents_INTERFACE_DEFINED__ equ <>
        externdef IID_IMachineDebugManagerEvents:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IMachineDebugManagerEventsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IMachineDebugManagerEventsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IMachineDebugManagerEvents, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IMachineDebugManagerEvents
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IMachineDebugManagerEvents
            DECLSPEC_XFGVIRT(IMachineDebugManagerEvents, onAddApplication)
            STD_METHOD onAddApplication, :ptr IMachineDebugManagerEvents, :ptr IRemoteDebugApplication, :DWORD
            DECLSPEC_XFGVIRT(IMachineDebugManagerEvents, onRemoveApplication)
            STD_METHOD onRemoveApplication, :ptr IMachineDebugManagerEvents, :ptr IRemoteDebugApplication, :DWORD
            ??Interface equ <>
            END_INTERFACE
          IMachineDebugManagerEventsVtbl ends
          IMachineDebugManagerEvents struct
            lpVtbl POINTER ?
          IMachineDebugManagerEvents ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      externdef CLSID_ProcessDebugManager:CLSID
      ifndef DISABLE_ACTIVDBG_INTERFACE_WRAPPERS
        ifdef _WIN64
          IProcessDebugManager equ <IProcessDebugManager64>
          IID_IProcessDebugManager equ <IID_IProcessDebugManager64>
        else
          IProcessDebugManager equ <IProcessDebugManager32>
          IID_IProcessDebugManager equ <IID_IProcessDebugManager32>
        endif
      endif
      externdef __MIDL_itf_activdbg_0000_0037_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_activdbg_0000_0037_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IProcessDebugManager32_INTERFACE_DEFINED__
        __IProcessDebugManager32_INTERFACE_DEFINED__ equ <>
        externdef IID_IProcessDebugManager32:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IProcessDebugManager32Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IProcessDebugManager32Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IProcessDebugManager32, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IProcessDebugManager32
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IProcessDebugManager32
            DECLSPEC_XFGVIRT(IProcessDebugManager32, CreateApplication)
            STD_METHOD CreateApplication, :ptr IProcessDebugManager32, :ptr ptr IDebugApplication32
            DECLSPEC_XFGVIRT(IProcessDebugManager32, GetDefaultApplication)
            STD_METHOD GetDefaultApplication, :ptr IProcessDebugManager32, :ptr ptr IDebugApplication32
            DECLSPEC_XFGVIRT(IProcessDebugManager32, AddApplication)
            STD_METHOD AddApplication, :ptr IProcessDebugManager32, :ptr IDebugApplication32, :ptr DWORD
            DECLSPEC_XFGVIRT(IProcessDebugManager32, RemoveApplication)
            STD_METHOD RemoveApplication, :ptr IProcessDebugManager32, :DWORD
            DECLSPEC_XFGVIRT(IProcessDebugManager32, CreateDebugDocumentHelper)
            STD_METHOD CreateDebugDocumentHelper, :ptr IProcessDebugManager32, :ptr IUnknown, :ptr ptr IDebugDocumentHelper32
            ??Interface equ <>
            END_INTERFACE
          IProcessDebugManager32Vtbl ends
          IProcessDebugManager32 struct
            lpVtbl POINTER ?
          IProcessDebugManager32 ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IProcessDebugManager64_INTERFACE_DEFINED__
        __IProcessDebugManager64_INTERFACE_DEFINED__ equ <>
        externdef IID_IProcessDebugManager64:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IProcessDebugManager64Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IProcessDebugManager64Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IProcessDebugManager64, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IProcessDebugManager64
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IProcessDebugManager64
            DECLSPEC_XFGVIRT(IProcessDebugManager64, CreateApplication)
            STD_METHOD CreateApplication, :ptr IProcessDebugManager64, :ptr ptr IDebugApplication64
            DECLSPEC_XFGVIRT(IProcessDebugManager64, GetDefaultApplication)
            STD_METHOD GetDefaultApplication, :ptr IProcessDebugManager64, :ptr ptr IDebugApplication64
            DECLSPEC_XFGVIRT(IProcessDebugManager64, AddApplication)
            STD_METHOD AddApplication, :ptr IProcessDebugManager64, :ptr IDebugApplication64, :ptr DWORD
            DECLSPEC_XFGVIRT(IProcessDebugManager64, RemoveApplication)
            STD_METHOD RemoveApplication, :ptr IProcessDebugManager64, :DWORD
            DECLSPEC_XFGVIRT(IProcessDebugManager64, CreateDebugDocumentHelper)
            STD_METHOD CreateDebugDocumentHelper, :ptr IProcessDebugManager64, :ptr IUnknown, :ptr ptr IDebugDocumentHelper64
            ??Interface equ <>
            END_INTERFACE
          IProcessDebugManager64Vtbl ends
          IProcessDebugManager64 struct
            lpVtbl POINTER ?
          IProcessDebugManager64 ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IRemoteDebugApplication_INTERFACE_DEFINED__
        __IRemoteDebugApplication_INTERFACE_DEFINED__ equ <>
        externdef IID_IRemoteDebugApplication:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IRemoteDebugApplicationVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IRemoteDebugApplicationVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IRemoteDebugApplication, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IRemoteDebugApplication
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IRemoteDebugApplication
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, ResumeFromBreakPoint)
            STD_METHOD ResumeFromBreakPoint, :ptr IRemoteDebugApplication, :ptr IRemoteDebugApplicationThread, :BREAKRESUMEACTION, :ERRORRESUMEACTION
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, CauseBreak)
            STD_METHOD CauseBreak, :ptr IRemoteDebugApplication
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, ConnectDebugger)
            STD_METHOD ConnectDebugger, :ptr IRemoteDebugApplication, :ptr IApplicationDebugger
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, DisconnectDebugger)
            STD_METHOD DisconnectDebugger, :ptr IRemoteDebugApplication
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, GetDebugger)
            STD_METHOD GetDebugger, :ptr IRemoteDebugApplication, :ptr ptr IApplicationDebugger
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, CreateInstanceAtApplication)
            STD_METHOD CreateInstanceAtApplication, :ptr IRemoteDebugApplication, :REFCLSID, :ptr IUnknown, :DWORD, :REFIID, :ptr ptr IUnknown
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, QueryAlive)
            STD_METHOD QueryAlive, :ptr IRemoteDebugApplication
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, EnumThreads)
            STD_METHOD EnumThreads, :ptr IRemoteDebugApplication, :ptr ptr IEnumRemoteDebugApplicationThreads
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, GetName)
            STD_METHOD GetName, :ptr IRemoteDebugApplication, :ptr BSTR
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, GetRootNode)
            STD_METHOD GetRootNode, :ptr IRemoteDebugApplication, :ptr ptr IDebugApplicationNode
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, EnumGlobalExpressionContexts)
            STD_METHOD EnumGlobalExpressionContexts, :ptr IRemoteDebugApplication, :ptr ptr IEnumDebugExpressionContexts
            ??Interface equ <>
            END_INTERFACE
          IRemoteDebugApplicationVtbl ends
          IRemoteDebugApplication struct
            lpVtbl POINTER ?
          IRemoteDebugApplication ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef DISABLE_ACTIVDBG_INTERFACE_WRAPPERS
        ifdef _WIN64
          IDebugApplication equ <IDebugApplication64>
          IID_IDebugApplication equ <IID_IDebugApplication64>
        else
          IDebugApplication equ <IDebugApplication32>
          IID_IDebugApplication equ <IID_IDebugApplication32>
        endif
      endif
      externdef __MIDL_itf_activdbg_0000_0040_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_activdbg_0000_0040_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDebugApplication32_INTERFACE_DEFINED__
        __IDebugApplication32_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugApplication32:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugApplication32Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugApplication32Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugApplication32, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugApplication32
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugApplication32
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, ResumeFromBreakPoint)
            STD_METHOD ResumeFromBreakPoint, :ptr IDebugApplication32, :ptr IRemoteDebugApplicationThread, :BREAKRESUMEACTION, :ERRORRESUMEACTION
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, CauseBreak)
            STD_METHOD CauseBreak, :ptr IDebugApplication32
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, ConnectDebugger)
            STD_METHOD ConnectDebugger, :ptr IDebugApplication32, :ptr IApplicationDebugger
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, DisconnectDebugger)
            STD_METHOD DisconnectDebugger, :ptr IDebugApplication32
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, GetDebugger)
            STD_METHOD GetDebugger, :ptr IDebugApplication32, :ptr ptr IApplicationDebugger
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, CreateInstanceAtApplication)
            STD_METHOD CreateInstanceAtApplication, :ptr IDebugApplication32, :REFCLSID, :ptr IUnknown, :DWORD, :REFIID, :ptr ptr IUnknown
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, QueryAlive)
            STD_METHOD QueryAlive, :ptr IDebugApplication32
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, EnumThreads)
            STD_METHOD EnumThreads, :ptr IDebugApplication32, :ptr ptr IEnumRemoteDebugApplicationThreads
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, GetName)
            STD_METHOD GetName, :ptr IDebugApplication32, :ptr BSTR
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, GetRootNode)
            STD_METHOD GetRootNode, :ptr IDebugApplication32, :ptr ptr IDebugApplicationNode
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, EnumGlobalExpressionContexts)
            STD_METHOD EnumGlobalExpressionContexts, :ptr IDebugApplication32, :ptr ptr IEnumDebugExpressionContexts
            DECLSPEC_XFGVIRT(IDebugApplication32, SetName)
            STD_METHOD SetName, :ptr IDebugApplication32, :LPCOLESTR
            DECLSPEC_XFGVIRT(IDebugApplication32, StepOutComplete)
            STD_METHOD StepOutComplete, :ptr IDebugApplication32
            DECLSPEC_XFGVIRT(IDebugApplication32, DebugOutput)
            STD_METHOD DebugOutput, :ptr IDebugApplication32, :LPCOLESTR
            DECLSPEC_XFGVIRT(IDebugApplication32, StartDebugSession)
            STD_METHOD StartDebugSession, :ptr IDebugApplication32
            DECLSPEC_XFGVIRT(IDebugApplication32, HandleBreakPoint)
            STD_METHOD HandleBreakPoint, :ptr IDebugApplication32, :BREAKREASON, :ptr BREAKRESUMEACTION
            DECLSPEC_XFGVIRT(IDebugApplication32, Close)
            STD_METHOD Close, :ptr IDebugApplication32
            DECLSPEC_XFGVIRT(IDebugApplication32, GetBreakFlags)
            STD_METHOD GetBreakFlags, :ptr IDebugApplication32, :ptr APPBREAKFLAGS, :ptr ptr IRemoteDebugApplicationThread
            DECLSPEC_XFGVIRT(IDebugApplication32, GetCurrentThread)
            STD_METHOD GetCurrentThread, :ptr IDebugApplication32, :ptr ptr IDebugApplicationThread
            DECLSPEC_XFGVIRT(IDebugApplication32, CreateAsyncDebugOperation)
            STD_METHOD CreateAsyncDebugOperation, :ptr IDebugApplication32, :ptr IDebugSyncOperation, :ptr ptr IDebugAsyncOperation
            DECLSPEC_XFGVIRT(IDebugApplication32, AddStackFrameSniffer)
            STD_METHOD AddStackFrameSniffer, :ptr IDebugApplication32, :ptr IDebugStackFrameSniffer, :ptr DWORD
            DECLSPEC_XFGVIRT(IDebugApplication32, RemoveStackFrameSniffer)
            STD_METHOD RemoveStackFrameSniffer, :ptr IDebugApplication32, :DWORD
            DECLSPEC_XFGVIRT(IDebugApplication32, QueryCurrentThreadIsDebuggerThread)
            STD_METHOD QueryCurrentThreadIsDebuggerThread, :ptr IDebugApplication32
            DECLSPEC_XFGVIRT(IDebugApplication32, SynchronousCallInDebuggerThread)
            STD_METHOD SynchronousCallInDebuggerThread, :ptr IDebugApplication32, :ptr IDebugThreadCall32, :DWORD, :DWORD, :DWORD
            DECLSPEC_XFGVIRT(IDebugApplication32, CreateApplicationNode)
            STD_METHOD CreateApplicationNode, :ptr IDebugApplication32, :ptr ptr IDebugApplicationNode
            DECLSPEC_XFGVIRT(IDebugApplication32, FireDebuggerEvent)
            STD_METHOD FireDebuggerEvent, :ptr IDebugApplication32, :REFGUID, :ptr IUnknown
            DECLSPEC_XFGVIRT(IDebugApplication32, HandleRuntimeError)
            STD_METHOD HandleRuntimeError, :ptr IDebugApplication32, :ptr IActiveScriptErrorDebug, :ptr IActiveScriptSite, :ptr BREAKRESUMEACTION, :ptr ERRORRESUMEACTION, :ptr BOOL
            DECLSPEC_XFGVIRT(IDebugApplication32, FCanJitDebug)
            STD_METHOD FCanJitDebug, :ptr IDebugApplication32
            DECLSPEC_XFGVIRT(IDebugApplication32, FIsAutoJitDebugEnabled)
            STD_METHOD FIsAutoJitDebugEnabled, :ptr IDebugApplication32
            DECLSPEC_XFGVIRT(IDebugApplication32, AddGlobalExpressionContextProvider)
            STD_METHOD AddGlobalExpressionContextProvider, :ptr IDebugApplication32, :ptr IProvideExpressionContexts, :ptr DWORD
            DECLSPEC_XFGVIRT(IDebugApplication32, RemoveGlobalExpressionContextProvider)
            STD_METHOD RemoveGlobalExpressionContextProvider, :ptr IDebugApplication32, :DWORD
            ??Interface equ <>
            END_INTERFACE
          IDebugApplication32Vtbl ends
          IDebugApplication32 struct
            lpVtbl POINTER ?
          IDebugApplication32 ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IDebugApplication64_INTERFACE_DEFINED__
        __IDebugApplication64_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugApplication64:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugApplication64Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugApplication64Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugApplication64, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugApplication64
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugApplication64
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, ResumeFromBreakPoint)
            STD_METHOD ResumeFromBreakPoint, :ptr IDebugApplication64, :ptr IRemoteDebugApplicationThread, :BREAKRESUMEACTION, :ERRORRESUMEACTION
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, CauseBreak)
            STD_METHOD CauseBreak, :ptr IDebugApplication64
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, ConnectDebugger)
            STD_METHOD ConnectDebugger, :ptr IDebugApplication64, :ptr IApplicationDebugger
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, DisconnectDebugger)
            STD_METHOD DisconnectDebugger, :ptr IDebugApplication64
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, GetDebugger)
            STD_METHOD GetDebugger, :ptr IDebugApplication64, :ptr ptr IApplicationDebugger
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, CreateInstanceAtApplication)
            STD_METHOD CreateInstanceAtApplication, :ptr IDebugApplication64, :REFCLSID, :ptr IUnknown, :DWORD, :REFIID, :ptr ptr IUnknown
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, QueryAlive)
            STD_METHOD QueryAlive, :ptr IDebugApplication64
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, EnumThreads)
            STD_METHOD EnumThreads, :ptr IDebugApplication64, :ptr ptr IEnumRemoteDebugApplicationThreads
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, GetName)
            STD_METHOD GetName, :ptr IDebugApplication64, :ptr BSTR
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, GetRootNode)
            STD_METHOD GetRootNode, :ptr IDebugApplication64, :ptr ptr IDebugApplicationNode
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, EnumGlobalExpressionContexts)
            STD_METHOD EnumGlobalExpressionContexts, :ptr IDebugApplication64, :ptr ptr IEnumDebugExpressionContexts
            DECLSPEC_XFGVIRT(IDebugApplication64, SetName)
            STD_METHOD SetName, :ptr IDebugApplication64, :LPCOLESTR
            DECLSPEC_XFGVIRT(IDebugApplication64, StepOutComplete)
            STD_METHOD StepOutComplete, :ptr IDebugApplication64
            DECLSPEC_XFGVIRT(IDebugApplication64, DebugOutput)
            STD_METHOD DebugOutput, :ptr IDebugApplication64, :LPCOLESTR
            DECLSPEC_XFGVIRT(IDebugApplication64, StartDebugSession)
            STD_METHOD StartDebugSession, :ptr IDebugApplication64
            DECLSPEC_XFGVIRT(IDebugApplication64, HandleBreakPoint)
            STD_METHOD HandleBreakPoint, :ptr IDebugApplication64, :BREAKREASON, :ptr BREAKRESUMEACTION
            DECLSPEC_XFGVIRT(IDebugApplication64, Close)
            STD_METHOD Close, :ptr IDebugApplication64
            DECLSPEC_XFGVIRT(IDebugApplication64, GetBreakFlags)
            STD_METHOD GetBreakFlags, :ptr IDebugApplication64, :ptr APPBREAKFLAGS, :ptr ptr IRemoteDebugApplicationThread
            DECLSPEC_XFGVIRT(IDebugApplication64, GetCurrentThread)
            STD_METHOD GetCurrentThread, :ptr IDebugApplication64, :ptr ptr IDebugApplicationThread
            DECLSPEC_XFGVIRT(IDebugApplication64, CreateAsyncDebugOperation)
            STD_METHOD CreateAsyncDebugOperation, :ptr IDebugApplication64, :ptr IDebugSyncOperation, :ptr ptr IDebugAsyncOperation
            DECLSPEC_XFGVIRT(IDebugApplication64, AddStackFrameSniffer)
            STD_METHOD AddStackFrameSniffer, :ptr IDebugApplication64, :ptr IDebugStackFrameSniffer, :ptr DWORD
            DECLSPEC_XFGVIRT(IDebugApplication64, RemoveStackFrameSniffer)
            STD_METHOD RemoveStackFrameSniffer, :ptr IDebugApplication64, :DWORD
            DECLSPEC_XFGVIRT(IDebugApplication64, QueryCurrentThreadIsDebuggerThread)
            STD_METHOD QueryCurrentThreadIsDebuggerThread, :ptr IDebugApplication64
            DECLSPEC_XFGVIRT(IDebugApplication64, SynchronousCallInDebuggerThread)
            STD_METHOD SynchronousCallInDebuggerThread, :ptr IDebugApplication64, :ptr IDebugThreadCall64, :DWORDLONG, :DWORDLONG, :DWORDLONG
            DECLSPEC_XFGVIRT(IDebugApplication64, CreateApplicationNode)
            STD_METHOD CreateApplicationNode, :ptr IDebugApplication64, :ptr ptr IDebugApplicationNode
            DECLSPEC_XFGVIRT(IDebugApplication64, FireDebuggerEvent)
            STD_METHOD FireDebuggerEvent, :ptr IDebugApplication64, :REFGUID, :ptr IUnknown
            DECLSPEC_XFGVIRT(IDebugApplication64, HandleRuntimeError)
            STD_METHOD HandleRuntimeError, :ptr IDebugApplication64, :ptr IActiveScriptErrorDebug, :ptr IActiveScriptSite, :ptr BREAKRESUMEACTION, :ptr ERRORRESUMEACTION, :ptr BOOL
            DECLSPEC_XFGVIRT(IDebugApplication64, FCanJitDebug)
            STD_METHOD FCanJitDebug, :ptr IDebugApplication64
            DECLSPEC_XFGVIRT(IDebugApplication64, FIsAutoJitDebugEnabled)
            STD_METHOD FIsAutoJitDebugEnabled, :ptr IDebugApplication64
            DECLSPEC_XFGVIRT(IDebugApplication64, AddGlobalExpressionContextProvider)
            STD_METHOD AddGlobalExpressionContextProvider, :ptr IDebugApplication64, :ptr IProvideExpressionContexts, :ptr DWORDLONG
            DECLSPEC_XFGVIRT(IDebugApplication64, RemoveGlobalExpressionContextProvider)
            STD_METHOD RemoveGlobalExpressionContextProvider, :ptr IDebugApplication64, :DWORDLONG
            ??Interface equ <>
            END_INTERFACE
          IDebugApplication64Vtbl ends
          IDebugApplication64 struct
            lpVtbl POINTER ?
          IDebugApplication64 ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IRemoteDebugApplicationEvents_INTERFACE_DEFINED__
        __IRemoteDebugApplicationEvents_INTERFACE_DEFINED__ equ <>
        externdef IID_IRemoteDebugApplicationEvents:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IRemoteDebugApplicationEventsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IRemoteDebugApplicationEventsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IRemoteDebugApplicationEvents, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IRemoteDebugApplicationEvents
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IRemoteDebugApplicationEvents
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationEvents, OnConnectDebugger)
            STD_METHOD OnConnectDebugger, :ptr IRemoteDebugApplicationEvents, :ptr IApplicationDebugger
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationEvents, OnDisconnectDebugger)
            STD_METHOD OnDisconnectDebugger, :ptr IRemoteDebugApplicationEvents
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationEvents, OnSetName)
            STD_METHOD OnSetName, :ptr IRemoteDebugApplicationEvents, :LPCOLESTR
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationEvents, OnDebugOutput)
            STD_METHOD OnDebugOutput, :ptr IRemoteDebugApplicationEvents, :LPCOLESTR
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationEvents, OnClose)
            STD_METHOD OnClose, :ptr IRemoteDebugApplicationEvents
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationEvents, OnEnterBreakPoint)
            STD_METHOD OnEnterBreakPoint, :ptr IRemoteDebugApplicationEvents, :ptr IRemoteDebugApplicationThread
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationEvents, OnLeaveBreakPoint)
            STD_METHOD OnLeaveBreakPoint, :ptr IRemoteDebugApplicationEvents, :ptr IRemoteDebugApplicationThread
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationEvents, OnCreateThread)
            STD_METHOD OnCreateThread, :ptr IRemoteDebugApplicationEvents, :ptr IRemoteDebugApplicationThread
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationEvents, OnDestroyThread)
            STD_METHOD OnDestroyThread, :ptr IRemoteDebugApplicationEvents, :ptr IRemoteDebugApplicationThread
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationEvents, OnBreakFlagChange)
            STD_METHOD OnBreakFlagChange, :ptr IRemoteDebugApplicationEvents, :APPBREAKFLAGS, :ptr IRemoteDebugApplicationThread
            ??Interface equ <>
            END_INTERFACE
          IRemoteDebugApplicationEventsVtbl ends
          IRemoteDebugApplicationEvents struct
            lpVtbl POINTER ?
          IRemoteDebugApplicationEvents ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IDebugApplicationNode_INTERFACE_DEFINED__
        __IDebugApplicationNode_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugApplicationNode:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugApplicationNodeVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugApplicationNodeVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugApplicationNode, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugApplicationNode
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugApplicationNode
            DECLSPEC_XFGVIRT(IDebugDocumentInfo, GetName)
            STD_METHOD GetName, :ptr IDebugApplicationNode, :DOCUMENTNAMETYPE, :ptr BSTR
            DECLSPEC_XFGVIRT(IDebugDocumentInfo, GetDocumentClassId)
            STD_METHOD GetDocumentClassId, :ptr IDebugApplicationNode, :ptr CLSID
            DECLSPEC_XFGVIRT(IDebugDocumentProvider, GetDocument)
            STD_METHOD GetDocument, :ptr IDebugApplicationNode, :ptr ptr IDebugDocument
            DECLSPEC_XFGVIRT(IDebugApplicationNode, EnumChildren)
            STD_METHOD EnumChildren, :ptr IDebugApplicationNode, :ptr ptr IEnumDebugApplicationNodes
            DECLSPEC_XFGVIRT(IDebugApplicationNode, GetParent)
            STD_METHOD GetParent, :ptr IDebugApplicationNode, :ptr ptr IDebugApplicationNode
            DECLSPEC_XFGVIRT(IDebugApplicationNode, SetDocumentProvider)
            STD_METHOD SetDocumentProvider, :ptr IDebugApplicationNode, :ptr IDebugDocumentProvider
            DECLSPEC_XFGVIRT(IDebugApplicationNode, Close)
            STD_METHOD Close, :ptr IDebugApplicationNode
            DECLSPEC_XFGVIRT(IDebugApplicationNode, Attach)
            STD_METHOD Attach, :ptr IDebugApplicationNode, :ptr IDebugApplicationNode
            DECLSPEC_XFGVIRT(IDebugApplicationNode, Detach)
            STD_METHOD Detach, :ptr IDebugApplicationNode
            ??Interface equ <>
            END_INTERFACE
          IDebugApplicationNodeVtbl ends
          IDebugApplicationNode struct
            lpVtbl POINTER ?
          IDebugApplicationNode ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IDebugApplicationNodeEvents_INTERFACE_DEFINED__
        __IDebugApplicationNodeEvents_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugApplicationNodeEvents:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugApplicationNodeEventsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugApplicationNodeEventsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugApplicationNodeEvents, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugApplicationNodeEvents
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugApplicationNodeEvents
            DECLSPEC_XFGVIRT(IDebugApplicationNodeEvents, onAddChild)
            STD_METHOD onAddChild, :ptr IDebugApplicationNodeEvents, :ptr IDebugApplicationNode
            DECLSPEC_XFGVIRT(IDebugApplicationNodeEvents, onRemoveChild)
            STD_METHOD onRemoveChild, :ptr IDebugApplicationNodeEvents, :ptr IDebugApplicationNode
            DECLSPEC_XFGVIRT(IDebugApplicationNodeEvents, onDetach)
            STD_METHOD onDetach, :ptr IDebugApplicationNodeEvents
            DECLSPEC_XFGVIRT(IDebugApplicationNodeEvents, onAttach)
            STD_METHOD onAttach, :ptr IDebugApplicationNodeEvents, :ptr IDebugApplicationNode
            ??Interface equ <>
            END_INTERFACE
          IDebugApplicationNodeEventsVtbl ends
          IDebugApplicationNodeEvents struct
            lpVtbl POINTER ?
          IDebugApplicationNodeEvents ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __AsyncIDebugApplicationNodeEvents_INTERFACE_DEFINED__
        __AsyncIDebugApplicationNodeEvents_INTERFACE_DEFINED__ equ <>
        externdef IID_AsyncIDebugApplicationNodeEvents:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          AsyncIDebugApplicationNodeEventsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <AsyncIDebugApplicationNodeEventsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr AsyncIDebugApplicationNodeEvents, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr AsyncIDebugApplicationNodeEvents
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr AsyncIDebugApplicationNodeEvents
            DECLSPEC_XFGVIRT(AsyncIDebugApplicationNodeEvents, Begin_onAddChild)
            STD_METHOD Begin_onAddChild, :ptr AsyncIDebugApplicationNodeEvents, :ptr IDebugApplicationNode
            DECLSPEC_XFGVIRT(AsyncIDebugApplicationNodeEvents, Finish_onAddChild)
            STD_METHOD Finish_onAddChild, :ptr AsyncIDebugApplicationNodeEvents
            DECLSPEC_XFGVIRT(AsyncIDebugApplicationNodeEvents, Begin_onRemoveChild)
            STD_METHOD Begin_onRemoveChild, :ptr AsyncIDebugApplicationNodeEvents, :ptr IDebugApplicationNode
            DECLSPEC_XFGVIRT(AsyncIDebugApplicationNodeEvents, Finish_onRemoveChild)
            STD_METHOD Finish_onRemoveChild, :ptr AsyncIDebugApplicationNodeEvents
            DECLSPEC_XFGVIRT(AsyncIDebugApplicationNodeEvents, Begin_onDetach)
            STD_METHOD Begin_onDetach, :ptr AsyncIDebugApplicationNodeEvents
            DECLSPEC_XFGVIRT(AsyncIDebugApplicationNodeEvents, Finish_onDetach)
            STD_METHOD Finish_onDetach, :ptr AsyncIDebugApplicationNodeEvents
            DECLSPEC_XFGVIRT(AsyncIDebugApplicationNodeEvents, Begin_onAttach)
            STD_METHOD Begin_onAttach, :ptr AsyncIDebugApplicationNodeEvents, :ptr IDebugApplicationNode
            DECLSPEC_XFGVIRT(AsyncIDebugApplicationNodeEvents, Finish_onAttach)
            STD_METHOD Finish_onAttach, :ptr AsyncIDebugApplicationNodeEvents
            ??Interface equ <>
            END_INTERFACE
          AsyncIDebugApplicationNodeEventsVtbl ends
          AsyncIDebugApplicationNodeEvents struct
            lpVtbl POINTER ?
          AsyncIDebugApplicationNodeEvents ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef DISABLE_ACTIVDBG_INTERFACE_WRAPPERS
        ifdef _WIN64
          IDebugThreadCall equ <IDebugThreadCall64>
          IID_IDebugThreadCall equ <IID_IDebugThreadCall64>
        else
          IDebugThreadCall equ <IDebugThreadCall32>
          IID_IDebugThreadCall equ <IID_IDebugThreadCall32>
        endif
      endif
      externdef __MIDL_itf_activdbg_0000_0045_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_activdbg_0000_0045_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDebugThreadCall32_INTERFACE_DEFINED__
        __IDebugThreadCall32_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugThreadCall32:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugThreadCall32Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugThreadCall32Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugThreadCall32, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugThreadCall32
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugThreadCall32
            DECLSPEC_XFGVIRT(IDebugThreadCall32, ThreadCallHandler)
            STD_METHOD ThreadCallHandler, :ptr IDebugThreadCall32, :DWORD, :DWORD, :DWORD
            ??Interface equ <>
            END_INTERFACE
          IDebugThreadCall32Vtbl ends
          IDebugThreadCall32 struct
            lpVtbl POINTER ?
          IDebugThreadCall32 ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IDebugThreadCall64_INTERFACE_DEFINED__
        __IDebugThreadCall64_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugThreadCall64:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugThreadCall64Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugThreadCall64Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugThreadCall64, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugThreadCall64
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugThreadCall64
            DECLSPEC_XFGVIRT(IDebugThreadCall64, ThreadCallHandler)
            STD_METHOD ThreadCallHandler, :ptr IDebugThreadCall64, :DWORDLONG, :DWORDLONG, :DWORDLONG
            ??Interface equ <>
            END_INTERFACE
          IDebugThreadCall64Vtbl ends
          IDebugThreadCall64 struct
            lpVtbl POINTER ?
          IDebugThreadCall64 ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IRemoteDebugApplicationThread_INTERFACE_DEFINED__
        __IRemoteDebugApplicationThread_INTERFACE_DEFINED__ equ <>
        THREAD_STATE typedef DWORD
        THREAD_STATE_RUNNING equ (1h)
        THREAD_STATE_SUSPENDED equ (2h)
        THREAD_BLOCKED equ (4h)
        THREAD_OUT_OF_CONTEXT equ (8h)
        externdef IID_IRemoteDebugApplicationThread:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IRemoteDebugApplicationThreadVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IRemoteDebugApplicationThreadVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IRemoteDebugApplicationThread, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IRemoteDebugApplicationThread
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IRemoteDebugApplicationThread
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, GetSystemThreadId)
            STD_METHOD GetSystemThreadId, :ptr IRemoteDebugApplicationThread, :ptr DWORD
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, GetApplication)
            STD_METHOD GetApplication, :ptr IRemoteDebugApplicationThread, :ptr ptr IRemoteDebugApplication
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, EnumStackFrames)
            STD_METHOD EnumStackFrames, :ptr IRemoteDebugApplicationThread, :ptr ptr IEnumDebugStackFrames
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, GetDescription)
            STD_METHOD GetDescription, :ptr IRemoteDebugApplicationThread, :ptr BSTR, :ptr BSTR
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, SetNextStatement)
            STD_METHOD SetNextStatement, :ptr IRemoteDebugApplicationThread, :ptr IDebugStackFrame, :ptr IDebugCodeContext
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, GetState)
            STD_METHOD GetState, :ptr IRemoteDebugApplicationThread, :ptr DWORD
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, Suspend)
            STD_METHOD Suspend, :ptr IRemoteDebugApplicationThread, :ptr DWORD
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, Resume)
            STD_METHOD Resume, :ptr IRemoteDebugApplicationThread, :ptr DWORD
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, GetSuspendCount)
            STD_METHOD GetSuspendCount, :ptr IRemoteDebugApplicationThread, :ptr DWORD
            ??Interface equ <>
            END_INTERFACE
          IRemoteDebugApplicationThreadVtbl ends
          IRemoteDebugApplicationThread struct
            lpVtbl POINTER ?
          IRemoteDebugApplicationThread ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef DISABLE_ACTIVDBG_INTERFACE_WRAPPERS
        ifdef _WIN64
          SynchronousCallIntoThread equ <SynchronousCallIntoThread64>
        else
          SynchronousCallIntoThread equ <SynchronousCallIntoThread32>
        endif
      endif
      externdef __MIDL_itf_activdbg_0000_0048_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_activdbg_0000_0048_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDebugApplicationThread_INTERFACE_DEFINED__
        __IDebugApplicationThread_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugApplicationThread:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugApplicationThreadVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugApplicationThreadVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugApplicationThread, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugApplicationThread
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugApplicationThread
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, GetSystemThreadId)
            STD_METHOD GetSystemThreadId, :ptr IDebugApplicationThread, :ptr DWORD
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, GetApplication)
            STD_METHOD GetApplication, :ptr IDebugApplicationThread, :ptr ptr IRemoteDebugApplication
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, EnumStackFrames)
            STD_METHOD EnumStackFrames, :ptr IDebugApplicationThread, :ptr ptr IEnumDebugStackFrames
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, GetDescription)
            STD_METHOD GetDescription, :ptr IDebugApplicationThread, :ptr BSTR, :ptr BSTR
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, SetNextStatement)
            STD_METHOD SetNextStatement, :ptr IDebugApplicationThread, :ptr IDebugStackFrame, :ptr IDebugCodeContext
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, GetState)
            STD_METHOD GetState, :ptr IDebugApplicationThread, :ptr DWORD
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, Suspend)
            STD_METHOD Suspend, :ptr IDebugApplicationThread, :ptr DWORD
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, Resume)
            STD_METHOD Resume, :ptr IDebugApplicationThread, :ptr DWORD
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, GetSuspendCount)
            STD_METHOD GetSuspendCount, :ptr IDebugApplicationThread, :ptr DWORD
            DECLSPEC_XFGVIRT(IDebugApplicationThread, SynchronousCallIntoThread32)
            STD_METHOD SynchronousCallIntoThread32, :ptr IDebugApplicationThread, :ptr IDebugThreadCall32, :DWORD, :DWORD, :DWORD
            DECLSPEC_XFGVIRT(IDebugApplicationThread, QueryIsCurrentThread)
            STD_METHOD QueryIsCurrentThread, :ptr IDebugApplicationThread
            DECLSPEC_XFGVIRT(IDebugApplicationThread, QueryIsDebuggerThread)
            STD_METHOD QueryIsDebuggerThread, :ptr IDebugApplicationThread
            DECLSPEC_XFGVIRT(IDebugApplicationThread, SetDescription)
            STD_METHOD SetDescription, :ptr IDebugApplicationThread, :LPCOLESTR
            DECLSPEC_XFGVIRT(IDebugApplicationThread, SetStateString)
            STD_METHOD SetStateString, :ptr IDebugApplicationThread, :LPCOLESTR
            ??Interface equ <>
            END_INTERFACE
          IDebugApplicationThreadVtbl ends
          IDebugApplicationThread struct
            lpVtbl POINTER ?
          IDebugApplicationThread ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IDebugApplicationThread64_INTERFACE_DEFINED__
        __IDebugApplicationThread64_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugApplicationThread64:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugApplicationThread64Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugApplicationThread64Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugApplicationThread64, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugApplicationThread64
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugApplicationThread64
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, GetSystemThreadId)
            STD_METHOD GetSystemThreadId, :ptr IDebugApplicationThread64, :ptr DWORD
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, GetApplication)
            STD_METHOD GetApplication, :ptr IDebugApplicationThread64, :ptr ptr IRemoteDebugApplication
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, EnumStackFrames)
            STD_METHOD EnumStackFrames, :ptr IDebugApplicationThread64, :ptr ptr IEnumDebugStackFrames
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, GetDescription)
            STD_METHOD GetDescription, :ptr IDebugApplicationThread64, :ptr BSTR, :ptr BSTR
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, SetNextStatement)
            STD_METHOD SetNextStatement, :ptr IDebugApplicationThread64, :ptr IDebugStackFrame, :ptr IDebugCodeContext
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, GetState)
            STD_METHOD GetState, :ptr IDebugApplicationThread64, :ptr DWORD
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, Suspend)
            STD_METHOD Suspend, :ptr IDebugApplicationThread64, :ptr DWORD
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, Resume)
            STD_METHOD Resume, :ptr IDebugApplicationThread64, :ptr DWORD
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, GetSuspendCount)
            STD_METHOD GetSuspendCount, :ptr IDebugApplicationThread64, :ptr DWORD
            DECLSPEC_XFGVIRT(IDebugApplicationThread, SynchronousCallIntoThread32)
            STD_METHOD SynchronousCallIntoThread32, :ptr IDebugApplicationThread64, :ptr IDebugThreadCall32, :DWORD, :DWORD, :DWORD
            DECLSPEC_XFGVIRT(IDebugApplicationThread, QueryIsCurrentThread)
            STD_METHOD QueryIsCurrentThread, :ptr IDebugApplicationThread64
            DECLSPEC_XFGVIRT(IDebugApplicationThread, QueryIsDebuggerThread)
            STD_METHOD QueryIsDebuggerThread, :ptr IDebugApplicationThread64
            DECLSPEC_XFGVIRT(IDebugApplicationThread, SetDescription)
            STD_METHOD SetDescription, :ptr IDebugApplicationThread64, :LPCOLESTR
            DECLSPEC_XFGVIRT(IDebugApplicationThread, SetStateString)
            STD_METHOD SetStateString, :ptr IDebugApplicationThread64, :LPCOLESTR
            DECLSPEC_XFGVIRT(IDebugApplicationThread64, SynchronousCallIntoThread64)
            STD_METHOD SynchronousCallIntoThread64, :ptr IDebugApplicationThread64, :ptr IDebugThreadCall64, :DWORDLONG, :DWORDLONG, :DWORDLONG
            ??Interface equ <>
            END_INTERFACE
          IDebugApplicationThread64Vtbl ends
          IDebugApplicationThread64 struct
            lpVtbl POINTER ?
          IDebugApplicationThread64 ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IDebugCookie_INTERFACE_DEFINED__
        __IDebugCookie_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugCookie:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugCookieVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugCookieVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugCookie, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugCookie
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugCookie
            DECLSPEC_XFGVIRT(IDebugCookie, SetDebugCookie)
            STD_METHOD SetDebugCookie, :ptr IDebugCookie, :DWORD
            ??Interface equ <>
            END_INTERFACE
          IDebugCookieVtbl ends
          IDebugCookie struct
            lpVtbl POINTER ?
          IDebugCookie ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IEnumDebugApplicationNodes_INTERFACE_DEFINED__
        __IEnumDebugApplicationNodes_INTERFACE_DEFINED__ equ <>
        externdef IID_IEnumDebugApplicationNodes:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IEnumDebugApplicationNodesVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEnumDebugApplicationNodesVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IEnumDebugApplicationNodes, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IEnumDebugApplicationNodes
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IEnumDebugApplicationNodes
            DECLSPEC_XFGVIRT(IEnumDebugApplicationNodes, Next)
            STD_METHOD Next, :ptr IEnumDebugApplicationNodes, :ULONG, :ptr ptr IDebugApplicationNode, :ptr ULONG
            DECLSPEC_XFGVIRT(IEnumDebugApplicationNodes, Skip)
            STD_METHOD Skip, :ptr IEnumDebugApplicationNodes, :ULONG
            DECLSPEC_XFGVIRT(IEnumDebugApplicationNodes, Reset)
            STD_METHOD Reset, :ptr IEnumDebugApplicationNodes
            DECLSPEC_XFGVIRT(IEnumDebugApplicationNodes, Clone)
            STD_METHOD Clone, :ptr IEnumDebugApplicationNodes, :ptr ptr IEnumDebugApplicationNodes
            ??Interface equ <>
            END_INTERFACE
          IEnumDebugApplicationNodesVtbl ends
          IEnumDebugApplicationNodes struct
            lpVtbl POINTER ?
          IEnumDebugApplicationNodes ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
        IEnumDebugApplicationNodes_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumDebugApplicationNodes, :ULONG, :ptr ptr IDebugApplicationNode, :ptr ULONG
        IEnumDebugApplicationNodes_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      endif
      ifndef __IEnumRemoteDebugApplications_INTERFACE_DEFINED__
        __IEnumRemoteDebugApplications_INTERFACE_DEFINED__ equ <>
        externdef IID_IEnumRemoteDebugApplications:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IEnumRemoteDebugApplicationsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEnumRemoteDebugApplicationsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IEnumRemoteDebugApplications, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IEnumRemoteDebugApplications
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IEnumRemoteDebugApplications
            DECLSPEC_XFGVIRT(IEnumRemoteDebugApplications, Next)
            STD_METHOD Next, :ptr IEnumRemoteDebugApplications, :ULONG, :ptr ptr IRemoteDebugApplication, :ptr ULONG
            DECLSPEC_XFGVIRT(IEnumRemoteDebugApplications, Skip)
            STD_METHOD Skip, :ptr IEnumRemoteDebugApplications, :ULONG
            DECLSPEC_XFGVIRT(IEnumRemoteDebugApplications, Reset)
            STD_METHOD Reset, :ptr IEnumRemoteDebugApplications
            DECLSPEC_XFGVIRT(IEnumRemoteDebugApplications, Clone)
            STD_METHOD Clone, :ptr IEnumRemoteDebugApplications, :ptr ptr IEnumRemoteDebugApplications
            ??Interface equ <>
            END_INTERFACE
          IEnumRemoteDebugApplicationsVtbl ends
          IEnumRemoteDebugApplications struct
            lpVtbl POINTER ?
          IEnumRemoteDebugApplications ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
        IEnumRemoteDebugApplications_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumRemoteDebugApplications, :ULONG, :ptr ptr IRemoteDebugApplication, :ptr ULONG
        IEnumRemoteDebugApplications_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      endif
      ifndef __IEnumRemoteDebugApplicationThreads_INTERFACE_DEFINED__
        __IEnumRemoteDebugApplicationThreads_INTERFACE_DEFINED__ equ <>
        externdef IID_IEnumRemoteDebugApplicationThreads:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IEnumRemoteDebugApplicationThreadsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEnumRemoteDebugApplicationThreadsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IEnumRemoteDebugApplicationThreads, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IEnumRemoteDebugApplicationThreads
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IEnumRemoteDebugApplicationThreads
            DECLSPEC_XFGVIRT(IEnumRemoteDebugApplicationThreads, Next)
            STD_METHOD Next, :ptr IEnumRemoteDebugApplicationThreads, :ULONG, :ptr ptr IRemoteDebugApplicationThread, :ptr ULONG
            DECLSPEC_XFGVIRT(IEnumRemoteDebugApplicationThreads, Skip)
            STD_METHOD Skip, :ptr IEnumRemoteDebugApplicationThreads, :ULONG
            DECLSPEC_XFGVIRT(IEnumRemoteDebugApplicationThreads, Reset)
            STD_METHOD Reset, :ptr IEnumRemoteDebugApplicationThreads
            DECLSPEC_XFGVIRT(IEnumRemoteDebugApplicationThreads, Clone)
            STD_METHOD Clone, :ptr IEnumRemoteDebugApplicationThreads, :ptr ptr IEnumRemoteDebugApplicationThreads
            ??Interface equ <>
            END_INTERFACE
          IEnumRemoteDebugApplicationThreadsVtbl ends
          IEnumRemoteDebugApplicationThreads struct
            lpVtbl POINTER ?
          IEnumRemoteDebugApplicationThreads ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
        IEnumRemoteDebugApplicationThreads_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumRemoteDebugApplicationThreads, :ULONG, :ptr ptr IRemoteDebugApplicationThread, :ptr ULONG
        IEnumRemoteDebugApplicationThreads_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      endif
      ifndef __IDebugFormatter_INTERFACE_DEFINED__
        __IDebugFormatter_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugFormatter:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugFormatterVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugFormatterVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugFormatter, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugFormatter
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugFormatter
            DECLSPEC_XFGVIRT(IDebugFormatter, GetStringForVariant)
            STD_METHOD GetStringForVariant, :ptr IDebugFormatter, :ptr VARIANT, :ULONG, :ptr BSTR
            DECLSPEC_XFGVIRT(IDebugFormatter, GetVariantForString)
            STD_METHOD GetVariantForString, :ptr IDebugFormatter, :LPCOLESTR, :ptr VARIANT
            DECLSPEC_XFGVIRT(IDebugFormatter, GetStringForVarType)
            STD_METHOD GetStringForVarType, :ptr IDebugFormatter, :VARTYPE, :ptr TYPEDESC, :ptr BSTR
            ??Interface equ <>
            END_INTERFACE
          IDebugFormatterVtbl ends
          IDebugFormatter struct
            lpVtbl POINTER ?
          IDebugFormatter ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __ISimpleConnectionPoint_INTERFACE_DEFINED__
        __ISimpleConnectionPoint_INTERFACE_DEFINED__ equ <>
        externdef IID_ISimpleConnectionPoint:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISimpleConnectionPointVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISimpleConnectionPointVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr ISimpleConnectionPoint, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISimpleConnectionPoint
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISimpleConnectionPoint
            DECLSPEC_XFGVIRT(ISimpleConnectionPoint, GetEventCount)
            STD_METHOD GetEventCount, :ptr ISimpleConnectionPoint, :ptr ULONG
            DECLSPEC_XFGVIRT(ISimpleConnectionPoint, DescribeEvents)
            STD_METHOD DescribeEvents, :ptr ISimpleConnectionPoint, :ULONG, :ULONG, :ptr DISPID, :ptr BSTR, :ptr ULONG
            DECLSPEC_XFGVIRT(ISimpleConnectionPoint, Advise)
            STD_METHOD Advise, :ptr ISimpleConnectionPoint, :ptr IDispatch, :ptr DWORD
            DECLSPEC_XFGVIRT(ISimpleConnectionPoint, Unadvise)
            STD_METHOD Unadvise, :ptr ISimpleConnectionPoint, :DWORD
            ??Interface equ <>
            END_INTERFACE
          ISimpleConnectionPointVtbl ends
          ISimpleConnectionPoint struct
            lpVtbl POINTER ?
          ISimpleConnectionPoint ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      externdef CLSID_DebugHelper:CLSID
      externdef __MIDL_itf_activdbg_0000_0056_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_activdbg_0000_0056_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDebugHelper_INTERFACE_DEFINED__
        __IDebugHelper_INTERFACE_DEFINED__ equ <>
        externdef IID_IDebugHelper:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugHelperVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugHelperVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IDebugHelper, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugHelper
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugHelper
            DECLSPEC_XFGVIRT(IDebugHelper, CreatePropertyBrowser)
            STD_METHOD CreatePropertyBrowser, :ptr IDebugHelper, :ptr VARIANT, :LPCOLESTR, :ptr IDebugApplicationThread, :ptr ptr IDebugProperty
            DECLSPEC_XFGVIRT(IDebugHelper, CreatePropertyBrowserEx)
            STD_METHOD CreatePropertyBrowserEx, :ptr IDebugHelper, :ptr VARIANT, :LPCOLESTR, :ptr IDebugApplicationThread, :ptr IDebugFormatter, :ptr ptr IDebugProperty
            DECLSPEC_XFGVIRT(IDebugHelper, CreateSimpleConnectionPoint)
            STD_METHOD CreateSimpleConnectionPoint, :ptr IDebugHelper, :ptr IDispatch, :ptr ptr ISimpleConnectionPoint
            ??Interface equ <>
            END_INTERFACE
          IDebugHelperVtbl ends
          IDebugHelper struct
            lpVtbl POINTER ?
          IDebugHelper ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IEnumDebugExpressionContexts_INTERFACE_DEFINED__
        __IEnumDebugExpressionContexts_INTERFACE_DEFINED__ equ <>
        externdef IID_IEnumDebugExpressionContexts:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IEnumDebugExpressionContextsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEnumDebugExpressionContextsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IEnumDebugExpressionContexts, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IEnumDebugExpressionContexts
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IEnumDebugExpressionContexts
            DECLSPEC_XFGVIRT(IEnumDebugExpressionContexts, Next)
            STD_METHOD Next, :ptr IEnumDebugExpressionContexts, :ULONG, :ptr ptr IDebugExpressionContext, :ptr ULONG
            DECLSPEC_XFGVIRT(IEnumDebugExpressionContexts, Skip)
            STD_METHOD Skip, :ptr IEnumDebugExpressionContexts, :ULONG
            DECLSPEC_XFGVIRT(IEnumDebugExpressionContexts, Reset)
            STD_METHOD Reset, :ptr IEnumDebugExpressionContexts
            DECLSPEC_XFGVIRT(IEnumDebugExpressionContexts, Clone)
            STD_METHOD Clone, :ptr IEnumDebugExpressionContexts, :ptr ptr IEnumDebugExpressionContexts
            ??Interface equ <>
            END_INTERFACE
          IEnumDebugExpressionContextsVtbl ends
          IEnumDebugExpressionContexts struct
            lpVtbl POINTER ?
          IEnumDebugExpressionContexts ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
        IEnumDebugExpressionContexts_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumDebugExpressionContexts, :ULONG, :ptr ptr IDebugExpressionContext, :ptr ULONG
        IEnumDebugExpressionContexts_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      endif
      ifndef __IProvideExpressionContexts_INTERFACE_DEFINED__
        __IProvideExpressionContexts_INTERFACE_DEFINED__ equ <>
        externdef IID_IProvideExpressionContexts:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IProvideExpressionContextsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IProvideExpressionContextsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IProvideExpressionContexts, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IProvideExpressionContexts
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IProvideExpressionContexts
            DECLSPEC_XFGVIRT(IProvideExpressionContexts, EnumExpressionContexts)
            STD_METHOD EnumExpressionContexts, :ptr IProvideExpressionContexts, :ptr ptr IEnumDebugExpressionContexts
            ??Interface equ <>
            END_INTERFACE
          IProvideExpressionContextsVtbl ends
          IProvideExpressionContexts struct
            lpVtbl POINTER ?
          IProvideExpressionContexts ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __ProcessDebugManagerLib_LIBRARY_DEFINED__
        __ProcessDebugManagerLib_LIBRARY_DEFINED__ equ <>
        externdef CLSID_CDebugDocumentHelper:CLSID
        ifdef DEBUG
          MachineDebugManger equ <MachineDebugManager_DEBUG>
;          CLSID_MachineDebugManager equ <CLSID_MachineDebugManager_DEBUG>
        else
          MachineDebugManger equ <MachineDebugManager_RETAIL>
          CLSID_MachineDebugManager equ <CLSID_MachineDebugManager_RETAIL>
        endif
        externdef LIBID_ProcessDebugManagerLib:IID
        externdef CLSID_ProcessDebugManager:CLSID
        ifdef __cplusplus
          ;[...]
        endif
        externdef CLSID_DebugHelper:CLSID
        ifdef __cplusplus
          ;[...]
        endif
        externdef CLSID_CDebugDocumentHelper:CLSID
        ifdef __cplusplus
          ;[...]
        endif
        externdef CLSID_MachineDebugManager_RETAIL:CLSID
        ifdef __cplusplus
          ;[...]
        endif
        externdef CLSID_MachineDebugManager_DEBUG:CLSID
        ifdef __cplusplus
          ;[...]
        endif
        externdef CLSID_DefaultDebugSessionProvider:CLSID
        ifdef __cplusplus
          ;[...]
        endif
      endif
    endif
  endif
  externdef __MIDL_itf_activdbg_0000_0060_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_activdbg_0000_0060_v0_0_s_ifspec:RPC_IF_HANDLE
  BSTR_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr BSTR
  BSTR_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BSTR
  BSTR_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr BSTR
  BSTR_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BSTR
  IEnumDebugCodeContexts_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumDebugCodeContexts, :ULONG, :ptr ptr IDebugCodeContext, :ptr ULONG
  IEnumDebugCodeContexts_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumDebugCodeContexts, :ULONG, :ptr ptr IDebugCodeContext, :ptr ULONG
  IEnumDebugStackFrames_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumDebugStackFrames, :ULONG, :ptr DebugStackFrameDescriptor, :ptr ULONG
  IEnumDebugStackFrames_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumDebugStackFrames, :ULONG, :ptr DebugStackFrameDescriptor, :ptr ULONG
  IEnumDebugStackFrames64_Next64_Proxy proto WIN_STD_CALL_CONV :ptr IEnumDebugStackFrames64, :ULONG, :ptr DebugStackFrameDescriptor64, :ptr ULONG
  IEnumDebugStackFrames64_Next64_Stub proto WIN_STD_CALL_CONV :ptr IEnumDebugStackFrames64, :ULONG, :ptr DebugStackFrameDescriptor64, :ptr ULONG
  IEnumDebugApplicationNodes_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumDebugApplicationNodes, :ULONG, :ptr ptr IDebugApplicationNode, :ptr ULONG
  IEnumDebugApplicationNodes_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumDebugApplicationNodes, :ULONG, :ptr ptr IDebugApplicationNode, :ptr ULONG
  IEnumRemoteDebugApplications_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumRemoteDebugApplications, :ULONG, :ptr ptr IRemoteDebugApplication, :ptr ULONG
  IEnumRemoteDebugApplications_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumRemoteDebugApplications, :ULONG, :ptr ptr IRemoteDebugApplication, :ptr ULONG
  IEnumRemoteDebugApplicationThreads_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumRemoteDebugApplicationThreads, :ULONG, :ptr ptr IRemoteDebugApplicationThread, :ptr ULONG
  IEnumRemoteDebugApplicationThreads_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumRemoteDebugApplicationThreads, :ULONG, :ptr ptr IRemoteDebugApplicationThread, :ptr ULONG
  IEnumDebugExpressionContexts_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumDebugExpressionContexts, :ULONG, :ptr ptr IDebugExpressionContext, :ptr ULONG
  IEnumDebugExpressionContexts_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumDebugExpressionContexts, :ULONG, :ptr ptr IDebugExpressionContext, :ptr ULONG
  ifdef __cplusplus
    ;[...]
  endif
endif
