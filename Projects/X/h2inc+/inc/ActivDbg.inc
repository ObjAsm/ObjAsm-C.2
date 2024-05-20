;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\activdbg.h
;             Created on (UTC) 06/04/2024 06:15:51
;             Last modified on (UTC) 21/02/2024 18:15:40

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
  ;* Forward Declarations *
  ifndef __IActiveScriptDebug32_FWD_DEFINED__
    __IActiveScriptDebug32_FWD_DEFINED__ equ <>
    ;* __IActiveScriptDebug32_FWD_DEFINED__ *
  endif
  ifndef __IActiveScriptDebug64_FWD_DEFINED__
    __IActiveScriptDebug64_FWD_DEFINED__ equ <>
    ;* __IActiveScriptDebug64_FWD_DEFINED__ *
  endif
  ifndef __IActiveScriptSiteDebug32_FWD_DEFINED__
    __IActiveScriptSiteDebug32_FWD_DEFINED__ equ <>
    ;* __IActiveScriptSiteDebug32_FWD_DEFINED__ *
  endif
  ifndef __IActiveScriptSiteDebug64_FWD_DEFINED__
    __IActiveScriptSiteDebug64_FWD_DEFINED__ equ <>
    ;* __IActiveScriptSiteDebug64_FWD_DEFINED__ *
  endif
  ifndef __IActiveScriptSiteDebugEx_FWD_DEFINED__
    __IActiveScriptSiteDebugEx_FWD_DEFINED__ equ <>
    ;* __IActiveScriptSiteDebugEx_FWD_DEFINED__ *
  endif
  ifndef __IActiveScriptErrorDebug_FWD_DEFINED__
    __IActiveScriptErrorDebug_FWD_DEFINED__ equ <>
    ;* __IActiveScriptErrorDebug_FWD_DEFINED__ *
  endif
  ifndef __IDebugCodeContext_FWD_DEFINED__
    __IDebugCodeContext_FWD_DEFINED__ equ <>
    ;* __IDebugCodeContext_FWD_DEFINED__ *
  endif
  ifndef __IDebugExpression_FWD_DEFINED__
    __IDebugExpression_FWD_DEFINED__ equ <>
    ;* __IDebugExpression_FWD_DEFINED__ *
  endif
  ifndef __IDebugExpressionContext_FWD_DEFINED__
    __IDebugExpressionContext_FWD_DEFINED__ equ <>
    ;* __IDebugExpressionContext_FWD_DEFINED__ *
  endif
  ifndef __IDebugExpressionCallBack_FWD_DEFINED__
    __IDebugExpressionCallBack_FWD_DEFINED__ equ <>
    ;* __IDebugExpressionCallBack_FWD_DEFINED__ *
  endif
  ifndef __IDebugStackFrame_FWD_DEFINED__
    __IDebugStackFrame_FWD_DEFINED__ equ <>
    ;* __IDebugStackFrame_FWD_DEFINED__ *
  endif
  ifndef __IDebugStackFrameSniffer_FWD_DEFINED__
    __IDebugStackFrameSniffer_FWD_DEFINED__ equ <>
    ;* __IDebugStackFrameSniffer_FWD_DEFINED__ *
  endif
  ifndef __IDebugStackFrameSnifferEx32_FWD_DEFINED__
    __IDebugStackFrameSnifferEx32_FWD_DEFINED__ equ <>
    ;* __IDebugStackFrameSnifferEx32_FWD_DEFINED__ *
  endif
  ifndef __IDebugStackFrameSnifferEx64_FWD_DEFINED__
    __IDebugStackFrameSnifferEx64_FWD_DEFINED__ equ <>
    ;* __IDebugStackFrameSnifferEx64_FWD_DEFINED__ *
  endif
  ifndef __IDebugSyncOperation_FWD_DEFINED__
    __IDebugSyncOperation_FWD_DEFINED__ equ <>
    ;* __IDebugSyncOperation_FWD_DEFINED__ *
  endif
  ifndef __IDebugAsyncOperation_FWD_DEFINED__
    __IDebugAsyncOperation_FWD_DEFINED__ equ <>
    ;* __IDebugAsyncOperation_FWD_DEFINED__ *
  endif
  ifndef __IDebugAsyncOperationCallBack_FWD_DEFINED__
    __IDebugAsyncOperationCallBack_FWD_DEFINED__ equ <>
    ;* __IDebugAsyncOperationCallBack_FWD_DEFINED__ *
  endif
  ifndef __IEnumDebugCodeContexts_FWD_DEFINED__
    __IEnumDebugCodeContexts_FWD_DEFINED__ equ <>
    ;* __IEnumDebugCodeContexts_FWD_DEFINED__ *
  endif
  ifndef __IEnumDebugStackFrames_FWD_DEFINED__
    __IEnumDebugStackFrames_FWD_DEFINED__ equ <>
    ;* __IEnumDebugStackFrames_FWD_DEFINED__ *
  endif
  ifndef __IEnumDebugStackFrames64_FWD_DEFINED__
    __IEnumDebugStackFrames64_FWD_DEFINED__ equ <>
    ;* __IEnumDebugStackFrames64_FWD_DEFINED__ *
  endif
  ifndef __IDebugDocumentInfo_FWD_DEFINED__
    __IDebugDocumentInfo_FWD_DEFINED__ equ <>
    ;* __IDebugDocumentInfo_FWD_DEFINED__ *
  endif
  ifndef __IDebugDocumentProvider_FWD_DEFINED__
    __IDebugDocumentProvider_FWD_DEFINED__ equ <>
    ;* __IDebugDocumentProvider_FWD_DEFINED__ *
  endif
  ifndef __IDebugDocument_FWD_DEFINED__
    __IDebugDocument_FWD_DEFINED__ equ <>
    ;* __IDebugDocument_FWD_DEFINED__ *
  endif
  ifndef __IDebugDocumentText_FWD_DEFINED__
    __IDebugDocumentText_FWD_DEFINED__ equ <>
    ;* __IDebugDocumentText_FWD_DEFINED__ *
  endif
  ifndef __IDebugDocumentTextEvents_FWD_DEFINED__
    __IDebugDocumentTextEvents_FWD_DEFINED__ equ <>
    ;* __IDebugDocumentTextEvents_FWD_DEFINED__ *
  endif
  ifndef __IDebugDocumentTextAuthor_FWD_DEFINED__
    __IDebugDocumentTextAuthor_FWD_DEFINED__ equ <>
    ;* __IDebugDocumentTextAuthor_FWD_DEFINED__ *
  endif
  ifndef __IDebugDocumentTextExternalAuthor_FWD_DEFINED__
    __IDebugDocumentTextExternalAuthor_FWD_DEFINED__ equ <>
    ;* __IDebugDocumentTextExternalAuthor_FWD_DEFINED__ *
  endif
  ifndef __IDebugDocumentHelper32_FWD_DEFINED__
    __IDebugDocumentHelper32_FWD_DEFINED__ equ <>
    ;* __IDebugDocumentHelper32_FWD_DEFINED__ *
  endif
  ifndef __IDebugDocumentHelper64_FWD_DEFINED__
    __IDebugDocumentHelper64_FWD_DEFINED__ equ <>
    ;* __IDebugDocumentHelper64_FWD_DEFINED__ *
  endif
  ifndef __IDebugDocumentHost_FWD_DEFINED__
    __IDebugDocumentHost_FWD_DEFINED__ equ <>
    ;* __IDebugDocumentHost_FWD_DEFINED__ *
  endif
  ifndef __IDebugDocumentContext_FWD_DEFINED__
    __IDebugDocumentContext_FWD_DEFINED__ equ <>
    ;* __IDebugDocumentContext_FWD_DEFINED__ *
  endif
  ifndef __IDebugSessionProvider_FWD_DEFINED__
    __IDebugSessionProvider_FWD_DEFINED__ equ <>
    ;* __IDebugSessionProvider_FWD_DEFINED__ *
  endif
  ifndef __IApplicationDebugger_FWD_DEFINED__
    __IApplicationDebugger_FWD_DEFINED__ equ <>
    ;* __IApplicationDebugger_FWD_DEFINED__ *
  endif
  ifndef __IApplicationDebuggerUI_FWD_DEFINED__
    __IApplicationDebuggerUI_FWD_DEFINED__ equ <>
    ;* __IApplicationDebuggerUI_FWD_DEFINED__ *
  endif
  ifndef __IMachineDebugManager_FWD_DEFINED__
    __IMachineDebugManager_FWD_DEFINED__ equ <>
    ;* __IMachineDebugManager_FWD_DEFINED__ *
  endif
  ifndef __IMachineDebugManagerCookie_FWD_DEFINED__
    __IMachineDebugManagerCookie_FWD_DEFINED__ equ <>
    ;* __IMachineDebugManagerCookie_FWD_DEFINED__ *
  endif
  ifndef __IMachineDebugManagerEvents_FWD_DEFINED__
    __IMachineDebugManagerEvents_FWD_DEFINED__ equ <>
    ;* __IMachineDebugManagerEvents_FWD_DEFINED__ *
  endif
  ifndef __IProcessDebugManager32_FWD_DEFINED__
    __IProcessDebugManager32_FWD_DEFINED__ equ <>
    ;* __IProcessDebugManager32_FWD_DEFINED__ *
  endif
  ifndef __IProcessDebugManager64_FWD_DEFINED__
    __IProcessDebugManager64_FWD_DEFINED__ equ <>
    ;* __IProcessDebugManager64_FWD_DEFINED__ *
  endif
  ifndef __IRemoteDebugApplication_FWD_DEFINED__
    __IRemoteDebugApplication_FWD_DEFINED__ equ <>
    ;* __IRemoteDebugApplication_FWD_DEFINED__ *
  endif
  ifndef __IDebugApplication32_FWD_DEFINED__
    __IDebugApplication32_FWD_DEFINED__ equ <>
    ;* __IDebugApplication32_FWD_DEFINED__ *
  endif
  ifndef __IDebugApplication64_FWD_DEFINED__
    __IDebugApplication64_FWD_DEFINED__ equ <>
    ;* __IDebugApplication64_FWD_DEFINED__ *
  endif
  ifndef __IRemoteDebugApplicationEvents_FWD_DEFINED__
    __IRemoteDebugApplicationEvents_FWD_DEFINED__ equ <>
    ;* __IRemoteDebugApplicationEvents_FWD_DEFINED__ *
  endif
  ifndef __IDebugApplicationNode_FWD_DEFINED__
    __IDebugApplicationNode_FWD_DEFINED__ equ <>
    ;* __IDebugApplicationNode_FWD_DEFINED__ *
  endif
  ifndef __IDebugApplicationNodeEvents_FWD_DEFINED__
    __IDebugApplicationNodeEvents_FWD_DEFINED__ equ <>
    ;* __IDebugApplicationNodeEvents_FWD_DEFINED__ *
  endif
  ifndef __AsyncIDebugApplicationNodeEvents_FWD_DEFINED__
    __AsyncIDebugApplicationNodeEvents_FWD_DEFINED__ equ <>
    ;* __AsyncIDebugApplicationNodeEvents_FWD_DEFINED__ *
  endif
  ifndef __IDebugThreadCall32_FWD_DEFINED__
    __IDebugThreadCall32_FWD_DEFINED__ equ <>
    ;* __IDebugThreadCall32_FWD_DEFINED__ *
  endif
  ifndef __IDebugThreadCall64_FWD_DEFINED__
    __IDebugThreadCall64_FWD_DEFINED__ equ <>
    ;* __IDebugThreadCall64_FWD_DEFINED__ *
  endif
  ifndef __IRemoteDebugApplicationThread_FWD_DEFINED__
    __IRemoteDebugApplicationThread_FWD_DEFINED__ equ <>
    ;* __IRemoteDebugApplicationThread_FWD_DEFINED__ *
  endif
  ifndef __IDebugApplicationThread_FWD_DEFINED__
    __IDebugApplicationThread_FWD_DEFINED__ equ <>
    ;* __IDebugApplicationThread_FWD_DEFINED__ *
  endif
  ifndef __IDebugApplicationThread64_FWD_DEFINED__
    __IDebugApplicationThread64_FWD_DEFINED__ equ <>
    ;* __IDebugApplicationThread64_FWD_DEFINED__ *
  endif
  ifndef __IDebugCookie_FWD_DEFINED__
    __IDebugCookie_FWD_DEFINED__ equ <>
    ;* __IDebugCookie_FWD_DEFINED__ *
  endif
  ifndef __IEnumDebugApplicationNodes_FWD_DEFINED__
    __IEnumDebugApplicationNodes_FWD_DEFINED__ equ <>
    ;* __IEnumDebugApplicationNodes_FWD_DEFINED__ *
  endif
  ifndef __IEnumRemoteDebugApplications_FWD_DEFINED__
    __IEnumRemoteDebugApplications_FWD_DEFINED__ equ <>
    ;* __IEnumRemoteDebugApplications_FWD_DEFINED__ *
  endif
  ifndef __IEnumRemoteDebugApplicationThreads_FWD_DEFINED__
    __IEnumRemoteDebugApplicationThreads_FWD_DEFINED__ equ <>
    ;* __IEnumRemoteDebugApplicationThreads_FWD_DEFINED__ *
  endif
  ifndef __IDebugFormatter_FWD_DEFINED__
    __IDebugFormatter_FWD_DEFINED__ equ <>
    ;* __IDebugFormatter_FWD_DEFINED__ *
  endif
  ifndef __ISimpleConnectionPoint_FWD_DEFINED__
    __ISimpleConnectionPoint_FWD_DEFINED__ equ <>
    ;* __ISimpleConnectionPoint_FWD_DEFINED__ *
  endif
  ifndef __IDebugHelper_FWD_DEFINED__
    __IDebugHelper_FWD_DEFINED__ equ <>
    ;* __IDebugHelper_FWD_DEFINED__ *
  endif
  ifndef __IEnumDebugExpressionContexts_FWD_DEFINED__
    __IEnumDebugExpressionContexts_FWD_DEFINED__ equ <>
    ;* __IEnumDebugExpressionContexts_FWD_DEFINED__ *
  endif
  ifndef __IProvideExpressionContexts_FWD_DEFINED__
    __IProvideExpressionContexts_FWD_DEFINED__ equ <>
    ;* __IProvideExpressionContexts_FWD_DEFINED__ *
  endif
  ifndef __IActiveScriptDebug32_FWD_DEFINED__
    __IActiveScriptDebug32_FWD_DEFINED__ equ <>
    ;* __IActiveScriptDebug32_FWD_DEFINED__ *
  endif
  ifndef __IActiveScriptDebug64_FWD_DEFINED__
    __IActiveScriptDebug64_FWD_DEFINED__ equ <>
    ;* __IActiveScriptDebug64_FWD_DEFINED__ *
  endif
  ifndef __IActiveScriptErrorDebug_FWD_DEFINED__
    __IActiveScriptErrorDebug_FWD_DEFINED__ equ <>
    ;* __IActiveScriptErrorDebug_FWD_DEFINED__ *
  endif
  ifndef __IActiveScriptSiteDebug32_FWD_DEFINED__
    __IActiveScriptSiteDebug32_FWD_DEFINED__ equ <>
    ;* __IActiveScriptSiteDebug32_FWD_DEFINED__ *
  endif
  ifndef __IActiveScriptSiteDebug64_FWD_DEFINED__
    __IActiveScriptSiteDebug64_FWD_DEFINED__ equ <>
    ;* __IActiveScriptSiteDebug64_FWD_DEFINED__ *
  endif
  ifndef __IActiveScriptSiteDebugEx_FWD_DEFINED__
    __IActiveScriptSiteDebugEx_FWD_DEFINED__ equ <>
    ;* __IActiveScriptSiteDebugEx_FWD_DEFINED__ *
  endif
  ifndef __IApplicationDebugger_FWD_DEFINED__
    __IApplicationDebugger_FWD_DEFINED__ equ <>
    ;* __IApplicationDebugger_FWD_DEFINED__ *
  endif
  ifndef __IApplicationDebuggerUI_FWD_DEFINED__
    __IApplicationDebuggerUI_FWD_DEFINED__ equ <>
    ;* __IApplicationDebuggerUI_FWD_DEFINED__ *
  endif
  ifndef __IRemoteDebugApplication_FWD_DEFINED__
    __IRemoteDebugApplication_FWD_DEFINED__ equ <>
    ;* __IRemoteDebugApplication_FWD_DEFINED__ *
  endif
  ifndef __IDebugApplication32_FWD_DEFINED__
    __IDebugApplication32_FWD_DEFINED__ equ <>
    ;* __IDebugApplication32_FWD_DEFINED__ *
  endif
  ifndef __IDebugApplication64_FWD_DEFINED__
    __IDebugApplication64_FWD_DEFINED__ equ <>
    ;* __IDebugApplication64_FWD_DEFINED__ *
  endif
  ifndef __IDebugDocumentInfo_FWD_DEFINED__
    __IDebugDocumentInfo_FWD_DEFINED__ equ <>
    ;* __IDebugDocumentInfo_FWD_DEFINED__ *
  endif
  ifndef __IDebugDocumentProvider_FWD_DEFINED__
    __IDebugDocumentProvider_FWD_DEFINED__ equ <>
    ;* __IDebugDocumentProvider_FWD_DEFINED__ *
  endif
  ifndef __IDebugApplicationNode_FWD_DEFINED__
    __IDebugApplicationNode_FWD_DEFINED__ equ <>
    ;* __IDebugApplicationNode_FWD_DEFINED__ *
  endif
  ifndef __IDebugApplicationNodeEvents_FWD_DEFINED__
    __IDebugApplicationNodeEvents_FWD_DEFINED__ equ <>
    ;* __IDebugApplicationNodeEvents_FWD_DEFINED__ *
  endif
  ifndef __IRemoteDebugApplicationThread_FWD_DEFINED__
    __IRemoteDebugApplicationThread_FWD_DEFINED__ equ <>
    ;* __IRemoteDebugApplicationThread_FWD_DEFINED__ *
  endif
  ifndef __IDebugApplicationThread_FWD_DEFINED__
    __IDebugApplicationThread_FWD_DEFINED__ equ <>
    ;* __IDebugApplicationThread_FWD_DEFINED__ *
  endif
  ifndef __IDebugAsyncOperation_FWD_DEFINED__
    __IDebugAsyncOperation_FWD_DEFINED__ equ <>
    ;* __IDebugAsyncOperation_FWD_DEFINED__ *
  endif
  ifndef __IDebugAsyncOperationCallBack_FWD_DEFINED__
    __IDebugAsyncOperationCallBack_FWD_DEFINED__ equ <>
    ;* __IDebugAsyncOperationCallBack_FWD_DEFINED__ *
  endif
  ifndef __IDebugCodeContext_FWD_DEFINED__
    __IDebugCodeContext_FWD_DEFINED__ equ <>
    ;* __IDebugCodeContext_FWD_DEFINED__ *
  endif
  ifndef __IDebugCookie_FWD_DEFINED__
    __IDebugCookie_FWD_DEFINED__ equ <>
    ;* __IDebugCookie_FWD_DEFINED__ *
  endif
  ifndef __IDebugDocument_FWD_DEFINED__
    __IDebugDocument_FWD_DEFINED__ equ <>
    ;* __IDebugDocument_FWD_DEFINED__ *
  endif
  ifndef __IDebugDocumentContext_FWD_DEFINED__
    __IDebugDocumentContext_FWD_DEFINED__ equ <>
    ;* __IDebugDocumentContext_FWD_DEFINED__ *
  endif
  ifndef __IDebugDocumentHelper32_FWD_DEFINED__
    __IDebugDocumentHelper32_FWD_DEFINED__ equ <>
    ;* __IDebugDocumentHelper32_FWD_DEFINED__ *
  endif
  ifndef __IDebugDocumentHelper64_FWD_DEFINED__
    __IDebugDocumentHelper64_FWD_DEFINED__ equ <>
    ;* __IDebugDocumentHelper64_FWD_DEFINED__ *
  endif
  ifndef __IDebugDocumentHost_FWD_DEFINED__
    __IDebugDocumentHost_FWD_DEFINED__ equ <>
    ;* __IDebugDocumentHost_FWD_DEFINED__ *
  endif
  ifndef __IDebugDocumentText_FWD_DEFINED__
    __IDebugDocumentText_FWD_DEFINED__ equ <>
    ;* __IDebugDocumentText_FWD_DEFINED__ *
  endif
  ifndef __IDebugDocumentTextAuthor_FWD_DEFINED__
    __IDebugDocumentTextAuthor_FWD_DEFINED__ equ <>
    ;* __IDebugDocumentTextAuthor_FWD_DEFINED__ *
  endif
  ifndef __IDebugDocumentTextEvents_FWD_DEFINED__
    __IDebugDocumentTextEvents_FWD_DEFINED__ equ <>
    ;* __IDebugDocumentTextEvents_FWD_DEFINED__ *
  endif
  ifndef __IDebugDocumentTextExternalAuthor_FWD_DEFINED__
    __IDebugDocumentTextExternalAuthor_FWD_DEFINED__ equ <>
    ;* __IDebugDocumentTextExternalAuthor_FWD_DEFINED__ *
  endif
  ifndef __IDebugExpression_FWD_DEFINED__
    __IDebugExpression_FWD_DEFINED__ equ <>
    ;* __IDebugExpression_FWD_DEFINED__ *
  endif
  ifndef __IDebugExpressionCallBack_FWD_DEFINED__
    __IDebugExpressionCallBack_FWD_DEFINED__ equ <>
    ;* __IDebugExpressionCallBack_FWD_DEFINED__ *
  endif
  ifndef __IDebugExpressionContext_FWD_DEFINED__
    __IDebugExpressionContext_FWD_DEFINED__ equ <>
    ;* __IDebugExpressionContext_FWD_DEFINED__ *
  endif
  ifndef __IDebugFormatter_FWD_DEFINED__
    __IDebugFormatter_FWD_DEFINED__ equ <>
    ;* __IDebugFormatter_FWD_DEFINED__ *
  endif
  ifndef __IDebugHelper_FWD_DEFINED__
    __IDebugHelper_FWD_DEFINED__ equ <>
    ;* __IDebugHelper_FWD_DEFINED__ *
  endif
  ifndef __IDebugSessionProvider_FWD_DEFINED__
    __IDebugSessionProvider_FWD_DEFINED__ equ <>
    ;* __IDebugSessionProvider_FWD_DEFINED__ *
  endif
  ifndef __IDebugStackFrame_FWD_DEFINED__
    __IDebugStackFrame_FWD_DEFINED__ equ <>
    ;* __IDebugStackFrame_FWD_DEFINED__ *
  endif
  ifndef __IDebugStackFrameSniffer_FWD_DEFINED__
    __IDebugStackFrameSniffer_FWD_DEFINED__ equ <>
    ;* __IDebugStackFrameSniffer_FWD_DEFINED__ *
  endif
  ifndef __IDebugStackFrameSnifferEx32_FWD_DEFINED__
    __IDebugStackFrameSnifferEx32_FWD_DEFINED__ equ <>
    ;* __IDebugStackFrameSnifferEx32_FWD_DEFINED__ *
  endif
  ifndef __IDebugStackFrameSnifferEx64_FWD_DEFINED__
    __IDebugStackFrameSnifferEx64_FWD_DEFINED__ equ <>
    ;* __IDebugStackFrameSnifferEx64_FWD_DEFINED__ *
  endif
  ifndef __IDebugSyncOperation_FWD_DEFINED__
    __IDebugSyncOperation_FWD_DEFINED__ equ <>
    ;* __IDebugSyncOperation_FWD_DEFINED__ *
  endif
  ifndef __IDebugThreadCall32_FWD_DEFINED__
    __IDebugThreadCall32_FWD_DEFINED__ equ <>
    ;* __IDebugThreadCall32_FWD_DEFINED__ *
  endif
  ifndef __IDebugThreadCall64_FWD_DEFINED__
    __IDebugThreadCall64_FWD_DEFINED__ equ <>
    ;* __IDebugThreadCall64_FWD_DEFINED__ *
  endif
  ifndef __IEnumDebugApplicationNodes_FWD_DEFINED__
    __IEnumDebugApplicationNodes_FWD_DEFINED__ equ <>
    ;* __IEnumDebugApplicationNodes_FWD_DEFINED__ *
  endif
  ifndef __IEnumDebugCodeContexts_FWD_DEFINED__
    __IEnumDebugCodeContexts_FWD_DEFINED__ equ <>
    ;* __IEnumDebugCodeContexts_FWD_DEFINED__ *
  endif
  ifndef __IEnumDebugExpressionContexts_FWD_DEFINED__
    __IEnumDebugExpressionContexts_FWD_DEFINED__ equ <>
    ;* __IEnumDebugExpressionContexts_FWD_DEFINED__ *
  endif
  ifndef __IEnumDebugStackFrames_FWD_DEFINED__
    __IEnumDebugStackFrames_FWD_DEFINED__ equ <>
    ;* __IEnumDebugStackFrames_FWD_DEFINED__ *
  endif
  ifndef __IEnumDebugStackFrames64_FWD_DEFINED__
    __IEnumDebugStackFrames64_FWD_DEFINED__ equ <>
    ;* __IEnumDebugStackFrames64_FWD_DEFINED__ *
  endif
  ifndef __IEnumRemoteDebugApplications_FWD_DEFINED__
    __IEnumRemoteDebugApplications_FWD_DEFINED__ equ <>
    ;* __IEnumRemoteDebugApplications_FWD_DEFINED__ *
  endif
  ifndef __IEnumRemoteDebugApplicationThreads_FWD_DEFINED__
    __IEnumRemoteDebugApplicationThreads_FWD_DEFINED__ equ <>
    ;* __IEnumRemoteDebugApplicationThreads_FWD_DEFINED__ *
  endif
  ifndef __IProcessDebugManager32_FWD_DEFINED__
    __IProcessDebugManager32_FWD_DEFINED__ equ <>
    ;* __IProcessDebugManager32_FWD_DEFINED__ *
  endif
  ifndef __IProcessDebugManager64_FWD_DEFINED__
    __IProcessDebugManager64_FWD_DEFINED__ equ <>
    ;* __IProcessDebugManager64_FWD_DEFINED__ *
  endif
  ifndef __IProvideExpressionContexts_FWD_DEFINED__
    __IProvideExpressionContexts_FWD_DEFINED__ equ <>
    ;* __IProvideExpressionContexts_FWD_DEFINED__ *
  endif
  ifndef __IMachineDebugManager_FWD_DEFINED__
    __IMachineDebugManager_FWD_DEFINED__ equ <>
    ;* __IMachineDebugManager_FWD_DEFINED__ *
  endif
  ifndef __IMachineDebugManagerCookie_FWD_DEFINED__
    __IMachineDebugManagerCookie_FWD_DEFINED__ equ <>
    ;* __IMachineDebugManagerCookie_FWD_DEFINED__ *
  endif
  ifndef __IMachineDebugManagerEvents_FWD_DEFINED__
    __IMachineDebugManagerEvents_FWD_DEFINED__ equ <>
    ;* __IMachineDebugManagerEvents_FWD_DEFINED__ *
  endif
  ifndef __IRemoteDebugApplicationEvents_FWD_DEFINED__
    __IRemoteDebugApplicationEvents_FWD_DEFINED__ equ <>
    ;* __IRemoteDebugApplicationEvents_FWD_DEFINED__ *
  endif
  ifndef __ISimpleConnectionPoint_FWD_DEFINED__
    __ISimpleConnectionPoint_FWD_DEFINED__ equ <>
    ;* __ISimpleConnectionPoint_FWD_DEFINED__ *
  endif
  ifndef __ProcessDebugManager_FWD_DEFINED__
    __ProcessDebugManager_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __ProcessDebugManager_FWD_DEFINED__ *
  endif
  ifndef __DebugHelper_FWD_DEFINED__
    __DebugHelper_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __DebugHelper_FWD_DEFINED__ *
  endif
  ifndef __CDebugDocumentHelper_FWD_DEFINED__
    __CDebugDocumentHelper_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __CDebugDocumentHelper_FWD_DEFINED__ *
  endif
  ifndef __MachineDebugManager_RETAIL_FWD_DEFINED__
    __MachineDebugManager_RETAIL_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __MachineDebugManager_RETAIL_FWD_DEFINED__ *
  endif
  ifndef __MachineDebugManager_DEBUG_FWD_DEFINED__
    __MachineDebugManager_DEBUG_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __MachineDebugManager_DEBUG_FWD_DEFINED__ *
  endif
  ifndef __DefaultDebugSessionProvider_FWD_DEFINED__
    __DefaultDebugSessionProvider_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
      ;* __cplusplus *
    endif
    ;* __DefaultDebugSessionProvider_FWD_DEFINED__ *
  endif
  ;* header files for imported files *
  include ocidl.inc
  include activscp.inc
  include dbgprop.inc
  ifdef __cplusplus
    ;[...]
  endif
  ;* interface __MIDL_itf_activdbg_0000_0000 *
  ;* [local] *
  ;=--------------------------------------------------------------------------=
  ; ActivDbg.h
  ;=--------------------------------------------------------------------------=
  ; (C) Copyright 2000 Microsoft Corporation.  All Rights Reserved.
  ; THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
  ; ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
  ; THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
  ; PARTICULAR PURPOSE.
  ;=--------------------------------------------------------------------------=
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ; Declarations for ActiveX Scripting authoring/Debugging.
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
      BREAKREASON_BREAKPOINT equ
      BREAKREASON_DEBUGGER_BLOCK equ
      BREAKREASON_HOST_INITIATED equ
      BREAKREASON_LANGUAGE_INITIATED equ
      BREAKREASON_DEBUGGER_HALT equ
      BREAKREASON_ERROR equ
      BREAKREASON_JIT equ
      BREAKREASON_MUTATION_BREAKPOINT equ
      tagBREAKREASON typedef BREAKREASON

      BREAKRESUMEACTION typedef SDWORD
      BREAKRESUMEACTION_ABORT equ 0
      BREAKRESUMEACTION_CONTINUE equ
      BREAKRESUMEACTION_STEP_INTO equ
      BREAKRESUMEACTION_STEP_OVER equ
      BREAKRESUMEACTION_STEP_OUT equ
      BREAKRESUMEACTION_IGNORE equ
      BREAKRESUMEACTION_STEP_DOCUMENT equ
      tagBREAKRESUME_ACTION typedef BREAKRESUMEACTION

      ERRORRESUMEACTION typedef SDWORD
      ERRORRESUMEACTION_ReexecuteErrorStatement equ 0
      ERRORRESUMEACTION_AbortCallAndReturnErrorToCaller equ
      ERRORRESUMEACTION_SkipErrorStatement equ
      tagERRORRESUMEACTION typedef ERRORRESUMEACTION

      DOCUMENTNAMETYPE typedef SDWORD
      DOCUMENTNAMETYPE_APPNODE equ 0
      DOCUMENTNAMETYPE_TITLE equ
      DOCUMENTNAMETYPE_FILE_TAIL equ
      DOCUMENTNAMETYPE_URL equ
      DOCUMENTNAMETYPE_UNIQUE_TITLE equ
      DOCUMENTNAMETYPE_SOURCE_MAP_URL equ
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
        ;* interface IActiveScriptDebug32 *
        ;* [unique][uuid][object] *
        externdef IID_IActiveScriptDebug32:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptDebug32Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptDebug32Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IActiveScriptDebug32, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IActiveScriptDebug32
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IActiveScriptDebug32
            DECLSPEC_XFGVIRT(IActiveScriptDebug32, GetScriptTextAttributes)
            ;* [size_is][in] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD GetScriptTextAttributes, :ptr IActiveScriptDebug32, :LPCOLESTR, :ULONG, :LPCOLESTR, :DWORD, :ptr SOURCE_TEXT_ATTR
            ;* [size_is][out][in] *
            DECLSPEC_XFGVIRT(IActiveScriptDebug32, GetScriptletTextAttributes)
            ;* [size_is][in] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD GetScriptletTextAttributes, :ptr IActiveScriptDebug32, :LPCOLESTR, :ULONG, :LPCOLESTR, :DWORD, :ptr SOURCE_TEXT_ATTR
            ;* [size_is][out][in] *
            DECLSPEC_XFGVIRT(IActiveScriptDebug32, EnumCodeContextsOfPosition)
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD EnumCodeContextsOfPosition, :ptr IActiveScriptDebug32, :DWORD, :ULONG, :ULONG, :ptr ptr IEnumDebugCodeContexts
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptDebug32Vtbl ends
          IActiveScriptDebug32 struct
            lpVtbl POINTER ?
          IActiveScriptDebug32 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IActiveScriptDebug32_INTERFACE_DEFINED__ *
      endif
      ifndef __IActiveScriptDebug64_INTERFACE_DEFINED__
        __IActiveScriptDebug64_INTERFACE_DEFINED__ equ <>
        ;* interface IActiveScriptDebug64 *
        ;* [unique][uuid][object] *
        externdef IID_IActiveScriptDebug64:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptDebug64Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptDebug64Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IActiveScriptDebug64, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IActiveScriptDebug64
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IActiveScriptDebug64
            DECLSPEC_XFGVIRT(IActiveScriptDebug64, GetScriptTextAttributes)
            ;* [size_is][in] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD GetScriptTextAttributes, :ptr IActiveScriptDebug64, :LPCOLESTR, :ULONG, :LPCOLESTR, :DWORD, :ptr SOURCE_TEXT_ATTR
            ;* [size_is][out][in] *
            DECLSPEC_XFGVIRT(IActiveScriptDebug64, GetScriptletTextAttributes)
            ;* [size_is][in] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD GetScriptletTextAttributes, :ptr IActiveScriptDebug64, :LPCOLESTR, :ULONG, :LPCOLESTR, :DWORD, :ptr SOURCE_TEXT_ATTR
            ;* [size_is][out][in] *
            DECLSPEC_XFGVIRT(IActiveScriptDebug64, EnumCodeContextsOfPosition)
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD EnumCodeContextsOfPosition, :ptr IActiveScriptDebug64, :DWORDLONG, :ULONG, :ULONG, :ptr ptr IEnumDebugCodeContexts
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptDebug64Vtbl ends
          IActiveScriptDebug64 struct
            lpVtbl POINTER ?
          IActiveScriptDebug64 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IActiveScriptDebug64_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_activdbg_0000_0002 *
      ;* [local] *
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
        ;* interface IActiveScriptSiteDebug32 *
        ;* [local][unique][uuid][object] *
        externdef IID_IActiveScriptSiteDebug32:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptSiteDebug32Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptSiteDebug32Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IActiveScriptSiteDebug32, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IActiveScriptSiteDebug32
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IActiveScriptSiteDebug32
            DECLSPEC_XFGVIRT(IActiveScriptSiteDebug32, GetDocumentContextFromPosition)
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD GetDocumentContextFromPosition, :ptr IActiveScriptSiteDebug32, :DWORD, :ULONG, :ULONG, :ptr ptr IDebugDocumentContext
            ;* [out] *
            DECLSPEC_XFGVIRT(IActiveScriptSiteDebug32, GetApplication)
            STD_METHOD GetApplication, :ptr IActiveScriptSiteDebug32, :ptr ptr IDebugApplication32
            ;* [out] *
            DECLSPEC_XFGVIRT(IActiveScriptSiteDebug32, GetRootApplicationNode)
            STD_METHOD GetRootApplicationNode, :ptr IActiveScriptSiteDebug32, :ptr ptr IDebugApplicationNode
            ;* [out] *
            DECLSPEC_XFGVIRT(IActiveScriptSiteDebug32, OnScriptErrorDebug)
            ;* [in] *
            ;* [out] *
            STD_METHOD OnScriptErrorDebug, :ptr IActiveScriptSiteDebug32, :ptr IActiveScriptErrorDebug, :ptr BOOL, :ptr BOOL
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptSiteDebug32Vtbl ends
          IActiveScriptSiteDebug32 struct
            lpVtbl POINTER ?
          IActiveScriptSiteDebug32 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IActiveScriptSiteDebug32_INTERFACE_DEFINED__ *
      endif
      ifndef __IActiveScriptSiteDebug64_INTERFACE_DEFINED__
        __IActiveScriptSiteDebug64_INTERFACE_DEFINED__ equ <>
        ;* interface IActiveScriptSiteDebug64 *
        ;* [local][unique][uuid][object] *
        externdef IID_IActiveScriptSiteDebug64:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptSiteDebug64Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptSiteDebug64Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IActiveScriptSiteDebug64, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IActiveScriptSiteDebug64
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IActiveScriptSiteDebug64
            DECLSPEC_XFGVIRT(IActiveScriptSiteDebug64, GetDocumentContextFromPosition)
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD GetDocumentContextFromPosition, :ptr IActiveScriptSiteDebug64, :DWORDLONG, :ULONG, :ULONG, :ptr ptr IDebugDocumentContext
            ;* [out] *
            DECLSPEC_XFGVIRT(IActiveScriptSiteDebug64, GetApplication)
            STD_METHOD GetApplication, :ptr IActiveScriptSiteDebug64, :ptr ptr IDebugApplication64
            ;* [out] *
            DECLSPEC_XFGVIRT(IActiveScriptSiteDebug64, GetRootApplicationNode)
            STD_METHOD GetRootApplicationNode, :ptr IActiveScriptSiteDebug64, :ptr ptr IDebugApplicationNode
            ;* [out] *
            DECLSPEC_XFGVIRT(IActiveScriptSiteDebug64, OnScriptErrorDebug)
            ;* [in] *
            ;* [out] *
            STD_METHOD OnScriptErrorDebug, :ptr IActiveScriptSiteDebug64, :ptr IActiveScriptErrorDebug, :ptr BOOL, :ptr BOOL
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptSiteDebug64Vtbl ends
          IActiveScriptSiteDebug64 struct
            lpVtbl POINTER ?
          IActiveScriptSiteDebug64 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IActiveScriptSiteDebug64_INTERFACE_DEFINED__ *
      endif
      ifndef __IActiveScriptSiteDebugEx_INTERFACE_DEFINED__
        __IActiveScriptSiteDebugEx_INTERFACE_DEFINED__ equ <>
        ;* interface IActiveScriptSiteDebugEx *
        ;* [local][unique][uuid][object] *
        externdef IID_IActiveScriptSiteDebugEx:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptSiteDebugExVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptSiteDebugExVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IActiveScriptSiteDebugEx, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IActiveScriptSiteDebugEx
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IActiveScriptSiteDebugEx
            DECLSPEC_XFGVIRT(IActiveScriptSiteDebugEx, OnCanNotJITScriptErrorDebug)
            ;* [in] *
            STD_METHOD OnCanNotJITScriptErrorDebug, :ptr IActiveScriptSiteDebugEx, :ptr IActiveScriptErrorDebug, :ptr BOOL
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptSiteDebugExVtbl ends
          IActiveScriptSiteDebugEx struct
            lpVtbl POINTER ?
          IActiveScriptSiteDebugEx ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IActiveScriptSiteDebugEx_INTERFACE_DEFINED__ *
      endif
      ifndef __IActiveScriptErrorDebug_INTERFACE_DEFINED__
        __IActiveScriptErrorDebug_INTERFACE_DEFINED__ equ <>
        ;* interface IActiveScriptErrorDebug *
        ;* [unique][uuid][object] *
        externdef IID_IActiveScriptErrorDebug:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IActiveScriptErrorDebugVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IActiveScriptErrorDebugVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IActiveScriptErrorDebug, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IActiveScriptErrorDebug
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IActiveScriptErrorDebug
            DECLSPEC_XFGVIRT(IActiveScriptError, GetExceptionInfo)
            ;* [local] *
            STD_METHOD GetExceptionInfo, :ptr IActiveScriptErrorDebug, :ptr EXCEPINFO
            ;* [out] *
            DECLSPEC_XFGVIRT(IActiveScriptError, GetSourcePosition)
            ;* [out] *
            ;* [out] *
            STD_METHOD GetSourcePosition, :ptr IActiveScriptErrorDebug, :ptr DWORD, :ptr ULONG, :ptr LONG
            ;* [out] *
            DECLSPEC_XFGVIRT(IActiveScriptError, GetSourceLineText)
            STD_METHOD GetSourceLineText, :ptr IActiveScriptErrorDebug, :ptr BSTR
            ;* [out] *
            DECLSPEC_XFGVIRT(IActiveScriptErrorDebug, GetDocumentContext)
            STD_METHOD GetDocumentContext, :ptr IActiveScriptErrorDebug, :ptr ptr IDebugDocumentContext
            ;* [out] *
            DECLSPEC_XFGVIRT(IActiveScriptErrorDebug, GetStackFrame)
            STD_METHOD GetStackFrame, :ptr IActiveScriptErrorDebug, :ptr ptr IDebugStackFrame
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IActiveScriptErrorDebugVtbl ends
          IActiveScriptErrorDebug struct
            lpVtbl POINTER ?
          IActiveScriptErrorDebug ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IActiveScriptErrorDebug_INTERFACE_DEFINED__ *
      endif
      ifndef __IDebugCodeContext_INTERFACE_DEFINED__
        __IDebugCodeContext_INTERFACE_DEFINED__ equ <>
        ;* interface IDebugCodeContext *
        ;* [unique][uuid][object] *
        externdef IID_IDebugCodeContext:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugCodeContextVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugCodeContextVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDebugCodeContext, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugCodeContext
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugCodeContext
            DECLSPEC_XFGVIRT(IDebugCodeContext, GetDocumentContext)
            STD_METHOD GetDocumentContext, :ptr IDebugCodeContext, :ptr ptr IDebugDocumentContext
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugCodeContext, SetBreakPoint)
            STD_METHOD SetBreakPoint, :ptr IDebugCodeContext, :BREAKPOINT_STATE
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IDebugCodeContextVtbl ends
          IDebugCodeContext struct
            lpVtbl POINTER ?
          IDebugCodeContext ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IDebugCodeContext_INTERFACE_DEFINED__ *
      endif
      ifndef __IDebugExpression_INTERFACE_DEFINED__
        __IDebugExpression_INTERFACE_DEFINED__ equ <>
        ;* interface IDebugExpression *
        ;* [unique][uuid][object] *
        externdef IID_IDebugExpression:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugExpressionVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugExpressionVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDebugExpression, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugExpression
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugExpression
            DECLSPEC_XFGVIRT(IDebugExpression, Start)
            STD_METHOD Start, :ptr IDebugExpression, :ptr IDebugExpressionCallBack
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugExpression, Abort)
            STD_METHOD Abort, :ptr IDebugExpression
            DECLSPEC_XFGVIRT(IDebugExpression, QueryIsComplete)
            STD_METHOD QueryIsComplete, :ptr IDebugExpression
            DECLSPEC_XFGVIRT(IDebugExpression, GetResultAsString)
            ;* [out] *
            STD_METHOD GetResultAsString, :ptr IDebugExpression, :ptr HRESULT, :ptr BSTR
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugExpression, GetResultAsDebugProperty)
            ;* [out] *
            STD_METHOD GetResultAsDebugProperty, :ptr IDebugExpression, :ptr HRESULT, :ptr ptr IDebugProperty
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IDebugExpressionVtbl ends
          IDebugExpression struct
            lpVtbl POINTER ?
          IDebugExpression ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IDebugExpression_INTERFACE_DEFINED__ *
      endif
      ifndef __IDebugExpressionContext_INTERFACE_DEFINED__
        __IDebugExpressionContext_INTERFACE_DEFINED__ equ <>
        ;* interface IDebugExpressionContext *
        ;* [unique][helpstring][uuid][object] *
        externdef IID_IDebugExpressionContext:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugExpressionContextVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugExpressionContextVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDebugExpressionContext, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugExpressionContext
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugExpressionContext
            DECLSPEC_XFGVIRT(IDebugExpressionContext, ParseLanguageText)
            ;* [in] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD ParseLanguageText, :ptr IDebugExpressionContext, :LPCOLESTR, :UINT, :LPCOLESTR, :DWORD, :ptr ptr IDebugExpression
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugExpressionContext, GetLanguageInfo)
            ;* [out] *
            STD_METHOD GetLanguageInfo, :ptr IDebugExpressionContext, :ptr BSTR, :ptr GUID
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IDebugExpressionContextVtbl ends
          IDebugExpressionContext struct
            lpVtbl POINTER ?
          IDebugExpressionContext ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IDebugExpressionContext_INTERFACE_DEFINED__ *
      endif
      ifndef __IDebugExpressionCallBack_INTERFACE_DEFINED__
        __IDebugExpressionCallBack_INTERFACE_DEFINED__ equ <>
        ;* interface IDebugExpressionCallBack *
        ;* [unique][uuid][object] *
        externdef IID_IDebugExpressionCallBack:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugExpressionCallBackVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugExpressionCallBackVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
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
          ;* C style interface *
        endif
        ;* __IDebugExpressionCallBack_INTERFACE_DEFINED__ *
      endif
      ifndef __IDebugStackFrame_INTERFACE_DEFINED__
        __IDebugStackFrame_INTERFACE_DEFINED__ equ <>
        ;* interface IDebugStackFrame *
        ;* [unique][uuid][object] *
        externdef IID_IDebugStackFrame:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugStackFrameVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugStackFrameVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDebugStackFrame, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugStackFrame
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugStackFrame
            DECLSPEC_XFGVIRT(IDebugStackFrame, GetCodeContext)
            STD_METHOD GetCodeContext, :ptr IDebugStackFrame, :ptr ptr IDebugCodeContext
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugStackFrame, GetDescriptionString)
            ;* [in] *
            STD_METHOD GetDescriptionString, :ptr IDebugStackFrame, :BOOL, :ptr BSTR
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugStackFrame, GetLanguageString)
            ;* [in] *
            STD_METHOD GetLanguageString, :ptr IDebugStackFrame, :BOOL, :ptr BSTR
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugStackFrame, GetThread)
            STD_METHOD GetThread, :ptr IDebugStackFrame, :ptr ptr IDebugApplicationThread
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugStackFrame, GetDebugProperty)
            STD_METHOD GetDebugProperty, :ptr IDebugStackFrame, :ptr ptr IDebugProperty
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IDebugStackFrameVtbl ends
          IDebugStackFrame struct
            lpVtbl POINTER ?
          IDebugStackFrame ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IDebugStackFrame_INTERFACE_DEFINED__ *
      endif
      ifndef __IDebugStackFrameSniffer_INTERFACE_DEFINED__
        __IDebugStackFrameSniffer_INTERFACE_DEFINED__ equ <>
        ;* interface IDebugStackFrameSniffer *
        ;* [unique][uuid][object] *
        externdef IID_IDebugStackFrameSniffer:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugStackFrameSnifferVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugStackFrameSnifferVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDebugStackFrameSniffer, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugStackFrameSniffer
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugStackFrameSniffer
            DECLSPEC_XFGVIRT(IDebugStackFrameSniffer, EnumStackFrames)
            STD_METHOD EnumStackFrames, :ptr IDebugStackFrameSniffer, :ptr ptr IEnumDebugStackFrames
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IDebugStackFrameSnifferVtbl ends
          IDebugStackFrameSniffer struct
            lpVtbl POINTER ?
          IDebugStackFrameSniffer ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IDebugStackFrameSniffer_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_activdbg_0000_0012 *
      ;* [local] *
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
        ;* interface IDebugStackFrameSnifferEx32 *
        ;* [unique][uuid][object] *
        externdef IID_IDebugStackFrameSnifferEx32:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugStackFrameSnifferEx32Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugStackFrameSnifferEx32Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDebugStackFrameSnifferEx32, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugStackFrameSnifferEx32
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugStackFrameSnifferEx32
            DECLSPEC_XFGVIRT(IDebugStackFrameSniffer, EnumStackFrames)
            STD_METHOD EnumStackFrames, :ptr IDebugStackFrameSnifferEx32, :ptr ptr IEnumDebugStackFrames
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugStackFrameSnifferEx32, EnumStackFramesEx32)
            ;* [in] *
            STD_METHOD EnumStackFramesEx32, :ptr IDebugStackFrameSnifferEx32, :DWORD, :ptr ptr IEnumDebugStackFrames
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IDebugStackFrameSnifferEx32Vtbl ends
          IDebugStackFrameSnifferEx32 struct
            lpVtbl POINTER ?
          IDebugStackFrameSnifferEx32 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IDebugStackFrameSnifferEx32_INTERFACE_DEFINED__ *
      endif
      ifndef __IDebugStackFrameSnifferEx64_INTERFACE_DEFINED__
        __IDebugStackFrameSnifferEx64_INTERFACE_DEFINED__ equ <>
        ;* interface IDebugStackFrameSnifferEx64 *
        ;* [unique][uuid][object] *
        externdef IID_IDebugStackFrameSnifferEx64:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugStackFrameSnifferEx64Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugStackFrameSnifferEx64Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDebugStackFrameSnifferEx64, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugStackFrameSnifferEx64
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugStackFrameSnifferEx64
            DECLSPEC_XFGVIRT(IDebugStackFrameSniffer, EnumStackFrames)
            STD_METHOD EnumStackFrames, :ptr IDebugStackFrameSnifferEx64, :ptr ptr IEnumDebugStackFrames
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugStackFrameSnifferEx64, EnumStackFramesEx64)
            ;* [in] *
            STD_METHOD EnumStackFramesEx64, :ptr IDebugStackFrameSnifferEx64, :DWORDLONG, :ptr ptr IEnumDebugStackFrames64
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IDebugStackFrameSnifferEx64Vtbl ends
          IDebugStackFrameSnifferEx64 struct
            lpVtbl POINTER ?
          IDebugStackFrameSnifferEx64 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IDebugStackFrameSnifferEx64_INTERFACE_DEFINED__ *
      endif
      ifndef __IDebugSyncOperation_INTERFACE_DEFINED__
        __IDebugSyncOperation_INTERFACE_DEFINED__ equ <>
        ;* interface IDebugSyncOperation *
        ;* [local][unique][uuid][object] *
        externdef IID_IDebugSyncOperation:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugSyncOperationVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugSyncOperationVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDebugSyncOperation, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugSyncOperation
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugSyncOperation
            DECLSPEC_XFGVIRT(IDebugSyncOperation, GetTargetThread)
            STD_METHOD GetTargetThread, :ptr IDebugSyncOperation, :ptr ptr IDebugApplicationThread
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugSyncOperation, Execute)
            STD_METHOD Execute, :ptr IDebugSyncOperation, :ptr ptr IUnknown
            ;* [out] *
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
          ;* C style interface *
        endif
        ;* __IDebugSyncOperation_INTERFACE_DEFINED__ *
      endif
      ifndef __IDebugAsyncOperation_INTERFACE_DEFINED__
        __IDebugAsyncOperation_INTERFACE_DEFINED__ equ <>
        ;* interface IDebugAsyncOperation *
        ;* [local][unique][uuid][object] *
        externdef IID_IDebugAsyncOperation:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugAsyncOperationVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugAsyncOperationVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDebugAsyncOperation, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugAsyncOperation
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugAsyncOperation
            DECLSPEC_XFGVIRT(IDebugAsyncOperation, GetSyncDebugOperation)
            STD_METHOD GetSyncDebugOperation, :ptr IDebugAsyncOperation, :ptr ptr IDebugSyncOperation
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugAsyncOperation, Start)
            STD_METHOD Start, :ptr IDebugAsyncOperation, :ptr IDebugAsyncOperationCallBack
            DECLSPEC_XFGVIRT(IDebugAsyncOperation, Abort)
            STD_METHOD Abort, :ptr IDebugAsyncOperation
            DECLSPEC_XFGVIRT(IDebugAsyncOperation, QueryIsComplete)
            STD_METHOD QueryIsComplete, :ptr IDebugAsyncOperation
            DECLSPEC_XFGVIRT(IDebugAsyncOperation, GetResult)
            ;* [out] *
            STD_METHOD GetResult, :ptr IDebugAsyncOperation, :ptr HRESULT, :ptr ptr IUnknown
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IDebugAsyncOperationVtbl ends
          IDebugAsyncOperation struct
            lpVtbl POINTER ?
          IDebugAsyncOperation ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IDebugAsyncOperation_INTERFACE_DEFINED__ *
      endif
      ifndef __IDebugAsyncOperationCallBack_INTERFACE_DEFINED__
        __IDebugAsyncOperationCallBack_INTERFACE_DEFINED__ equ <>
        ;* interface IDebugAsyncOperationCallBack *
        ;* [local][unique][uuid][object] *
        externdef IID_IDebugAsyncOperationCallBack:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugAsyncOperationCallBackVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugAsyncOperationCallBackVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
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
          ;* C style interface *
        endif
        ;* __IDebugAsyncOperationCallBack_INTERFACE_DEFINED__ *
      endif
      ifndef __IEnumDebugCodeContexts_INTERFACE_DEFINED__
        __IEnumDebugCodeContexts_INTERFACE_DEFINED__ equ <>
        ;* interface IEnumDebugCodeContexts *
        ;* [unique][helpstring][uuid][object] *
        externdef IID_IEnumDebugCodeContexts:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IEnumDebugCodeContextsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEnumDebugCodeContextsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IEnumDebugCodeContexts, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IEnumDebugCodeContexts
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IEnumDebugCodeContexts
            DECLSPEC_XFGVIRT(IEnumDebugCodeContexts, Next)
            ;* [local] *
            ;* [in] *
            ;* [out] *
            STD_METHOD Next, :ptr IEnumDebugCodeContexts, :ULONG, :ptr ptr IDebugCodeContext, :ptr ULONG
            ;* [out] *
            DECLSPEC_XFGVIRT(IEnumDebugCodeContexts, Skip)
            STD_METHOD Skip, :ptr IEnumDebugCodeContexts, :ULONG
            ;* [in] *
            DECLSPEC_XFGVIRT(IEnumDebugCodeContexts, Reset)
            STD_METHOD Reset, :ptr IEnumDebugCodeContexts
            DECLSPEC_XFGVIRT(IEnumDebugCodeContexts, Clone)
            STD_METHOD Clone, :ptr IEnumDebugCodeContexts, :ptr ptr IEnumDebugCodeContexts
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IEnumDebugCodeContextsVtbl ends
          IEnumDebugCodeContexts struct
            lpVtbl POINTER ?
          IEnumDebugCodeContexts ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* [call_as] *
        IEnumDebugCodeContexts_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumDebugCodeContexts, :ULONG, :ptr ptr IDebugCodeContext, :ptr ULONG
        ;* [out] *
        IEnumDebugCodeContexts_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        ;* __IEnumDebugCodeContexts_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_activdbg_0000_0018 *
      ;* [local] *
      DebugStackFrameDescriptor struct
        pdsf POINTER ?
        dwMin DWORD ?
        dwLim DWORD ?
        fFinal DWORD ?
        punkFinal POINTER ?
      DebugStackFrameDescriptor ends
      tagDebugStackFrameDescriptor typedef DebugStackFrameDescriptor
      DebugStackFrameDescriptor64 struct
        pdsf POINTER ?
        dwMin QWORD ?
        dwLim QWORD ?
        fFinal DWORD ?
        punkFinal POINTER ?
      DebugStackFrameDescriptor64 ends
      tagDebugStackFrameDescriptor64 typedef DebugStackFrameDescriptor64
      externdef __MIDL_itf_activdbg_0000_0018_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_activdbg_0000_0018_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IEnumDebugStackFrames_INTERFACE_DEFINED__
        __IEnumDebugStackFrames_INTERFACE_DEFINED__ equ <>
        ;* interface IEnumDebugStackFrames *
        ;* [unique][helpstring][uuid][object] *
        externdef IID_IEnumDebugStackFrames:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IEnumDebugStackFramesVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEnumDebugStackFramesVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IEnumDebugStackFrames, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IEnumDebugStackFrames
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IEnumDebugStackFrames
            DECLSPEC_XFGVIRT(IEnumDebugStackFrames, Next)
            ;* [local] *
            ;* [in] *
            ;* [out] *
            STD_METHOD Next, :ptr IEnumDebugStackFrames, :ULONG, :ptr DebugStackFrameDescriptor, :ptr ULONG
            ;* [out] *
            DECLSPEC_XFGVIRT(IEnumDebugStackFrames, Skip)
            STD_METHOD Skip, :ptr IEnumDebugStackFrames, :ULONG
            ;* [in] *
            DECLSPEC_XFGVIRT(IEnumDebugStackFrames, Reset)
            STD_METHOD Reset, :ptr IEnumDebugStackFrames
            DECLSPEC_XFGVIRT(IEnumDebugStackFrames, Clone)
            STD_METHOD Clone, :ptr IEnumDebugStackFrames, :ptr ptr IEnumDebugStackFrames
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IEnumDebugStackFramesVtbl ends
          IEnumDebugStackFrames struct
            lpVtbl POINTER ?
          IEnumDebugStackFrames ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* [call_as] *
        IEnumDebugStackFrames_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumDebugStackFrames, :ULONG, :ptr DebugStackFrameDescriptor, :ptr ULONG
        ;* [out] *
        IEnumDebugStackFrames_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        ;* __IEnumDebugStackFrames_INTERFACE_DEFINED__ *
      endif
      ifndef __IEnumDebugStackFrames64_INTERFACE_DEFINED__
        __IEnumDebugStackFrames64_INTERFACE_DEFINED__ equ <>
        ;* interface IEnumDebugStackFrames64 *
        ;* [unique][helpstring][uuid][object] *
        externdef IID_IEnumDebugStackFrames64:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IEnumDebugStackFrames64Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEnumDebugStackFrames64Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IEnumDebugStackFrames64, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IEnumDebugStackFrames64
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IEnumDebugStackFrames64
            DECLSPEC_XFGVIRT(IEnumDebugStackFrames, Next)
            ;* [local] *
            ;* [in] *
            ;* [out] *
            STD_METHOD Next, :ptr IEnumDebugStackFrames64, :ULONG, :ptr DebugStackFrameDescriptor, :ptr ULONG
            ;* [out] *
            DECLSPEC_XFGVIRT(IEnumDebugStackFrames, Skip)
            STD_METHOD Skip, :ptr IEnumDebugStackFrames64, :ULONG
            ;* [in] *
            DECLSPEC_XFGVIRT(IEnumDebugStackFrames, Reset)
            STD_METHOD Reset, :ptr IEnumDebugStackFrames64
            DECLSPEC_XFGVIRT(IEnumDebugStackFrames, Clone)
            STD_METHOD Clone, :ptr IEnumDebugStackFrames64, :ptr ptr IEnumDebugStackFrames
            ;* [out] *
            DECLSPEC_XFGVIRT(IEnumDebugStackFrames64, Next64)
            ;* [local] *
            ;* [in] *
            ;* [out] *
            STD_METHOD Next64, :ptr IEnumDebugStackFrames64, :ULONG, :ptr DebugStackFrameDescriptor64, :ptr ULONG
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IEnumDebugStackFrames64Vtbl ends
          IEnumDebugStackFrames64 struct
            lpVtbl POINTER ?
          IEnumDebugStackFrames64 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* [call_as] *
        IEnumDebugStackFrames64_RemoteNext64_Proxy proto WIN_STD_CALL_CONV :ptr IEnumDebugStackFrames64, :ULONG, :ptr DebugStackFrameDescriptor64, :ptr ULONG
        ;* [out] *
        IEnumDebugStackFrames64_RemoteNext64_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        ;* __IEnumDebugStackFrames64_INTERFACE_DEFINED__ *
      endif
      ifndef __IDebugDocumentInfo_INTERFACE_DEFINED__
        __IDebugDocumentInfo_INTERFACE_DEFINED__ equ <>
        ;* interface IDebugDocumentInfo *
        ;* [unique][helpstring][uuid][object] *
        externdef IID_IDebugDocumentInfo:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugDocumentInfoVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugDocumentInfoVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDebugDocumentInfo, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugDocumentInfo
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugDocumentInfo
            DECLSPEC_XFGVIRT(IDebugDocumentInfo, GetName)
            ;* [in] *
            STD_METHOD GetName, :ptr IDebugDocumentInfo, :DOCUMENTNAMETYPE, :ptr BSTR
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugDocumentInfo, GetDocumentClassId)
            STD_METHOD GetDocumentClassId, :ptr IDebugDocumentInfo, :ptr CLSID
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IDebugDocumentInfoVtbl ends
          IDebugDocumentInfo struct
            lpVtbl POINTER ?
          IDebugDocumentInfo ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IDebugDocumentInfo_INTERFACE_DEFINED__ *
      endif
      ifndef __IDebugDocumentProvider_INTERFACE_DEFINED__
        __IDebugDocumentProvider_INTERFACE_DEFINED__ equ <>
        ;* interface IDebugDocumentProvider *
        ;* [unique][helpstring][uuid][object] *
        externdef IID_IDebugDocumentProvider:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugDocumentProviderVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugDocumentProviderVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDebugDocumentProvider, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugDocumentProvider
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugDocumentProvider
            DECLSPEC_XFGVIRT(IDebugDocumentInfo, GetName)
            ;* [in] *
            STD_METHOD GetName, :ptr IDebugDocumentProvider, :DOCUMENTNAMETYPE, :ptr BSTR
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugDocumentInfo, GetDocumentClassId)
            STD_METHOD GetDocumentClassId, :ptr IDebugDocumentProvider, :ptr CLSID
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugDocumentProvider, GetDocument)
            STD_METHOD GetDocument, :ptr IDebugDocumentProvider, :ptr ptr IDebugDocument
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IDebugDocumentProviderVtbl ends
          IDebugDocumentProvider struct
            lpVtbl POINTER ?
          IDebugDocumentProvider ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IDebugDocumentProvider_INTERFACE_DEFINED__ *
      endif
      ifndef __IDebugDocument_INTERFACE_DEFINED__
        __IDebugDocument_INTERFACE_DEFINED__ equ <>
        ;* interface IDebugDocument *
        ;* [unique][uuid][object] *
        externdef IID_IDebugDocument:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugDocumentVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugDocumentVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDebugDocument, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugDocument
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugDocument
            DECLSPEC_XFGVIRT(IDebugDocumentInfo, GetName)
            ;* [in] *
            STD_METHOD GetName, :ptr IDebugDocument, :DOCUMENTNAMETYPE, :ptr BSTR
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugDocumentInfo, GetDocumentClassId)
            STD_METHOD GetDocumentClassId, :ptr IDebugDocument, :ptr CLSID
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IDebugDocumentVtbl ends
          IDebugDocument struct
            lpVtbl POINTER ?
          IDebugDocument ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IDebugDocument_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_activdbg_0000_0023 *
      ;* [local] *
      externdef __MIDL_itf_activdbg_0000_0023_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_activdbg_0000_0023_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDebugDocumentText_INTERFACE_DEFINED__
        __IDebugDocumentText_INTERFACE_DEFINED__ equ <>
        ;* interface IDebugDocumentText *
        ;* [unique][uuid][object] *
        externdef IID_IDebugDocumentText:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugDocumentTextVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugDocumentTextVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDebugDocumentText, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugDocumentText
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugDocumentText
            DECLSPEC_XFGVIRT(IDebugDocumentInfo, GetName)
            ;* [in] *
            STD_METHOD GetName, :ptr IDebugDocumentText, :DOCUMENTNAMETYPE, :ptr BSTR
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugDocumentInfo, GetDocumentClassId)
            STD_METHOD GetDocumentClassId, :ptr IDebugDocumentText, :ptr CLSID
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugDocumentText, GetDocumentAttributes)
            STD_METHOD GetDocumentAttributes, :ptr IDebugDocumentText, :ptr TEXT_DOC_ATTR
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugDocumentText, GetSize)
            ;* [out] *
            STD_METHOD GetSize, :ptr IDebugDocumentText, :ptr ULONG, :ptr ULONG
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugDocumentText, GetPositionOfLine)
            ;* [in] *
            STD_METHOD GetPositionOfLine, :ptr IDebugDocumentText, :ULONG, :ptr ULONG
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugDocumentText, GetLineOfPosition)
            ;* [in] *
            ;* [out] *
            STD_METHOD GetLineOfPosition, :ptr IDebugDocumentText, :ULONG, :ptr ULONG, :ptr ULONG
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugDocumentText, GetText)
            ;* [in] *
            ;* [size_is][length_is][out][in] *
            ;* [full][size_is][length_is][out][in] *
            ;* [out][in] *
            STD_METHOD GetText, :ptr IDebugDocumentText, :ULONG, :ptr WCHAR, :ptr SOURCE_TEXT_ATTR, :ptr ULONG, :ULONG
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugDocumentText, GetPositionOfContext)
            ;* [in] *
            ;* [out] *
            STD_METHOD GetPositionOfContext, :ptr IDebugDocumentText, :ptr IDebugDocumentContext, :ptr ULONG, :ptr ULONG
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugDocumentText, GetContextOfPosition)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetContextOfPosition, :ptr IDebugDocumentText, :ULONG, :ULONG, :ptr ptr IDebugDocumentContext
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IDebugDocumentTextVtbl ends
          IDebugDocumentText struct
            lpVtbl POINTER ?
          IDebugDocumentText ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IDebugDocumentText_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_activdbg_0000_0024 *
      ;* [local] *
      externdef __MIDL_itf_activdbg_0000_0024_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_activdbg_0000_0024_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDebugDocumentTextEvents_INTERFACE_DEFINED__
        __IDebugDocumentTextEvents_INTERFACE_DEFINED__ equ <>
        ;* interface IDebugDocumentTextEvents *
        ;* [unique][uuid][object] *
        externdef IID_IDebugDocumentTextEvents:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugDocumentTextEventsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugDocumentTextEventsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDebugDocumentTextEvents, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugDocumentTextEvents
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugDocumentTextEvents
            DECLSPEC_XFGVIRT(IDebugDocumentTextEvents, onDestroy)
            STD_METHOD onDestroy, :ptr IDebugDocumentTextEvents
            DECLSPEC_XFGVIRT(IDebugDocumentTextEvents, onInsertText)
            ;* [in] *
            STD_METHOD onInsertText, :ptr IDebugDocumentTextEvents, :ULONG, :ULONG
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugDocumentTextEvents, onRemoveText)
            ;* [in] *
            STD_METHOD onRemoveText, :ptr IDebugDocumentTextEvents, :ULONG, :ULONG
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugDocumentTextEvents, onReplaceText)
            ;* [in] *
            STD_METHOD onReplaceText, :ptr IDebugDocumentTextEvents, :ULONG, :ULONG
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugDocumentTextEvents, onUpdateTextAttributes)
            ;* [in] *
            STD_METHOD onUpdateTextAttributes, :ptr IDebugDocumentTextEvents, :ULONG, :ULONG
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugDocumentTextEvents, onUpdateDocumentAttributes)
            STD_METHOD onUpdateDocumentAttributes, :ptr IDebugDocumentTextEvents, :TEXT_DOC_ATTR
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IDebugDocumentTextEventsVtbl ends
          IDebugDocumentTextEvents struct
            lpVtbl POINTER ?
          IDebugDocumentTextEvents ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IDebugDocumentTextEvents_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_activdbg_0000_0025 *
      ;* [local] *
      externdef __MIDL_itf_activdbg_0000_0025_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_activdbg_0000_0025_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDebugDocumentTextAuthor_INTERFACE_DEFINED__
        __IDebugDocumentTextAuthor_INTERFACE_DEFINED__ equ <>
        ;* interface IDebugDocumentTextAuthor *
        ;* [unique][uuid][object] *
        externdef IID_IDebugDocumentTextAuthor:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugDocumentTextAuthorVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugDocumentTextAuthorVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDebugDocumentTextAuthor, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugDocumentTextAuthor
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugDocumentTextAuthor
            DECLSPEC_XFGVIRT(IDebugDocumentInfo, GetName)
            ;* [in] *
            STD_METHOD GetName, :ptr IDebugDocumentTextAuthor, :DOCUMENTNAMETYPE, :ptr BSTR
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugDocumentInfo, GetDocumentClassId)
            STD_METHOD GetDocumentClassId, :ptr IDebugDocumentTextAuthor, :ptr CLSID
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugDocumentText, GetDocumentAttributes)
            STD_METHOD GetDocumentAttributes, :ptr IDebugDocumentTextAuthor, :ptr TEXT_DOC_ATTR
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugDocumentText, GetSize)
            ;* [out] *
            STD_METHOD GetSize, :ptr IDebugDocumentTextAuthor, :ptr ULONG, :ptr ULONG
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugDocumentText, GetPositionOfLine)
            ;* [in] *
            STD_METHOD GetPositionOfLine, :ptr IDebugDocumentTextAuthor, :ULONG, :ptr ULONG
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugDocumentText, GetLineOfPosition)
            ;* [in] *
            ;* [out] *
            STD_METHOD GetLineOfPosition, :ptr IDebugDocumentTextAuthor, :ULONG, :ptr ULONG, :ptr ULONG
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugDocumentText, GetText)
            ;* [in] *
            ;* [size_is][length_is][out][in] *
            ;* [full][size_is][length_is][out][in] *
            ;* [out][in] *
            STD_METHOD GetText, :ptr IDebugDocumentTextAuthor, :ULONG, :ptr WCHAR, :ptr SOURCE_TEXT_ATTR, :ptr ULONG, :ULONG
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugDocumentText, GetPositionOfContext)
            ;* [in] *
            ;* [out] *
            STD_METHOD GetPositionOfContext, :ptr IDebugDocumentTextAuthor, :ptr IDebugDocumentContext, :ptr ULONG, :ptr ULONG
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugDocumentText, GetContextOfPosition)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetContextOfPosition, :ptr IDebugDocumentTextAuthor, :ULONG, :ULONG, :ptr ptr IDebugDocumentContext
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugDocumentTextAuthor, InsertText)
            ;* [in] *
            ;* [in] *
            STD_METHOD InsertText, :ptr IDebugDocumentTextAuthor, :ULONG, :ULONG, :ptr OLECHAR
            ;* [size_is][in] *
            DECLSPEC_XFGVIRT(IDebugDocumentTextAuthor, RemoveText)
            ;* [in] *
            STD_METHOD RemoveText, :ptr IDebugDocumentTextAuthor, :ULONG, :ULONG
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugDocumentTextAuthor, ReplaceText)
            ;* [in] *
            ;* [in] *
            STD_METHOD ReplaceText, :ptr IDebugDocumentTextAuthor, :ULONG, :ULONG, :ptr OLECHAR
            ;* [size_is][in] *
            ??Interface equ <>
            END_INTERFACE
          IDebugDocumentTextAuthorVtbl ends
          IDebugDocumentTextAuthor struct
            lpVtbl POINTER ?
          IDebugDocumentTextAuthor ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IDebugDocumentTextAuthor_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_activdbg_0000_0026 *
      ;* [local] *
      externdef __MIDL_itf_activdbg_0000_0026_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_activdbg_0000_0026_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDebugDocumentTextExternalAuthor_INTERFACE_DEFINED__
        __IDebugDocumentTextExternalAuthor_INTERFACE_DEFINED__ equ <>
        ;* interface IDebugDocumentTextExternalAuthor *
        ;* [unique][uuid][object] *
        externdef IID_IDebugDocumentTextExternalAuthor:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugDocumentTextExternalAuthorVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugDocumentTextExternalAuthorVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDebugDocumentTextExternalAuthor, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugDocumentTextExternalAuthor
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugDocumentTextExternalAuthor
            DECLSPEC_XFGVIRT(IDebugDocumentTextExternalAuthor, GetPathName)
            ;* [out] *
            STD_METHOD GetPathName, :ptr IDebugDocumentTextExternalAuthor, :ptr BSTR, :ptr BOOL
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugDocumentTextExternalAuthor, GetFileName)
            STD_METHOD GetFileName, :ptr IDebugDocumentTextExternalAuthor, :ptr BSTR
            ;* [out] *
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
          ;* C style interface *
        endif
        ;* __IDebugDocumentTextExternalAuthor_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_activdbg_0000_0027 *
      ;* [local] *
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
        ;* interface IDebugDocumentHelper32 *
        ;* [unique][helpstring][uuid][object] *
        externdef IID_IDebugDocumentHelper32:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugDocumentHelper32Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugDocumentHelper32Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDebugDocumentHelper32, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugDocumentHelper32
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugDocumentHelper32
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, Init)
            ;* [in] *
            ;* [string][in] *
            ;* [string][in] *
            STD_METHOD Init, :ptr IDebugDocumentHelper32, :ptr IDebugApplication32, :LPCOLESTR, :LPCOLESTR, :TEXT_DOC_ATTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, Attach)
            STD_METHOD Attach, :ptr IDebugDocumentHelper32, :ptr IDebugDocumentHelper32
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, Detach)
            STD_METHOD Detach, :ptr IDebugDocumentHelper32
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, AddUnicodeText)
            STD_METHOD AddUnicodeText, :ptr IDebugDocumentHelper32, :LPCOLESTR
            ;* [string][in] *
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, AddDBCSText)
            STD_METHOD AddDBCSText, :ptr IDebugDocumentHelper32, :LPCSTR
            ;* [string][in] *
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, SetDebugDocumentHost)
            STD_METHOD SetDebugDocumentHost, :ptr IDebugDocumentHelper32, :ptr IDebugDocumentHost
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, AddDeferredText)
            ;* [in] *
            STD_METHOD AddDeferredText, :ptr IDebugDocumentHelper32, :ULONG, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, DefineScriptBlock)
            ;* [in] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD DefineScriptBlock, :ptr IDebugDocumentHelper32, :ULONG, :ULONG, :ptr IActiveScript, :BOOL, :ptr DWORD
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, SetDefaultTextAttr)
            STD_METHOD SetDefaultTextAttr, :ptr IDebugDocumentHelper32, :SOURCE_TEXT_ATTR
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, SetTextAttributes)
            ;* [in] *
            ;* [in] *
            STD_METHOD SetTextAttributes, :ptr IDebugDocumentHelper32, :ULONG, :ULONG, :ptr SOURCE_TEXT_ATTR
            ;* [size_is][length_is][in] *
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, SetLongName)
            STD_METHOD SetLongName, :ptr IDebugDocumentHelper32, :LPCOLESTR
            ;* [string][in] *
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, SetShortName)
            STD_METHOD SetShortName, :ptr IDebugDocumentHelper32, :LPCOLESTR
            ;* [string][in] *
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, SetDocumentAttr)
            STD_METHOD SetDocumentAttr, :ptr IDebugDocumentHelper32, :TEXT_DOC_ATTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, GetDebugApplicationNode)
            STD_METHOD GetDebugApplicationNode, :ptr IDebugDocumentHelper32, :ptr ptr IDebugApplicationNode
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, GetScriptBlockInfo)
            ;* [in] *
            ;* [out] *
            ;* [out] *
            STD_METHOD GetScriptBlockInfo, :ptr IDebugDocumentHelper32, :DWORD, :ptr ptr IActiveScript, :ptr ULONG, :ptr ULONG
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugDocumentHelper32, CreateDebugDocumentContext)
            ;* [in] *
            ;* [in] *
            STD_METHOD CreateDebugDocumentContext, :ptr IDebugDocumentHelper32, :ULONG, :ULONG, :ptr ptr IDebugDocumentContext
            ;* [out] *
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
          ;* C style interface *
        endif
        ;* __IDebugDocumentHelper32_INTERFACE_DEFINED__ *
      endif
      ifndef __IDebugDocumentHelper64_INTERFACE_DEFINED__
        __IDebugDocumentHelper64_INTERFACE_DEFINED__ equ <>
        ;* interface IDebugDocumentHelper64 *
        ;* [unique][helpstring][uuid][object] *
        externdef IID_IDebugDocumentHelper64:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugDocumentHelper64Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugDocumentHelper64Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDebugDocumentHelper64, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugDocumentHelper64
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugDocumentHelper64
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, Init)
            ;* [in] *
            ;* [string][in] *
            ;* [string][in] *
            STD_METHOD Init, :ptr IDebugDocumentHelper64, :ptr IDebugApplication64, :LPCOLESTR, :LPCOLESTR, :TEXT_DOC_ATTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, Attach)
            STD_METHOD Attach, :ptr IDebugDocumentHelper64, :ptr IDebugDocumentHelper64
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, Detach)
            STD_METHOD Detach, :ptr IDebugDocumentHelper64
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, AddUnicodeText)
            STD_METHOD AddUnicodeText, :ptr IDebugDocumentHelper64, :LPCOLESTR
            ;* [string][in] *
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, AddDBCSText)
            STD_METHOD AddDBCSText, :ptr IDebugDocumentHelper64, :LPCSTR
            ;* [string][in] *
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, SetDebugDocumentHost)
            STD_METHOD SetDebugDocumentHost, :ptr IDebugDocumentHelper64, :ptr IDebugDocumentHost
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, AddDeferredText)
            ;* [in] *
            STD_METHOD AddDeferredText, :ptr IDebugDocumentHelper64, :ULONG, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, DefineScriptBlock)
            ;* [in] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD DefineScriptBlock, :ptr IDebugDocumentHelper64, :ULONG, :ULONG, :ptr IActiveScript, :BOOL, :ptr DWORDLONG
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, SetDefaultTextAttr)
            STD_METHOD SetDefaultTextAttr, :ptr IDebugDocumentHelper64, :SOURCE_TEXT_ATTR
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, SetTextAttributes)
            ;* [in] *
            ;* [in] *
            STD_METHOD SetTextAttributes, :ptr IDebugDocumentHelper64, :ULONG, :ULONG, :ptr SOURCE_TEXT_ATTR
            ;* [size_is][length_is][in] *
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, SetLongName)
            STD_METHOD SetLongName, :ptr IDebugDocumentHelper64, :LPCOLESTR
            ;* [string][in] *
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, SetShortName)
            STD_METHOD SetShortName, :ptr IDebugDocumentHelper64, :LPCOLESTR
            ;* [string][in] *
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, SetDocumentAttr)
            STD_METHOD SetDocumentAttr, :ptr IDebugDocumentHelper64, :TEXT_DOC_ATTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, GetDebugApplicationNode)
            STD_METHOD GetDebugApplicationNode, :ptr IDebugDocumentHelper64, :ptr ptr IDebugApplicationNode
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, GetScriptBlockInfo)
            ;* [in] *
            ;* [out] *
            ;* [out] *
            STD_METHOD GetScriptBlockInfo, :ptr IDebugDocumentHelper64, :DWORDLONG, :ptr ptr IActiveScript, :ptr ULONG, :ptr ULONG
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugDocumentHelper64, CreateDebugDocumentContext)
            ;* [in] *
            ;* [in] *
            STD_METHOD CreateDebugDocumentContext, :ptr IDebugDocumentHelper64, :ULONG, :ULONG, :ptr ptr IDebugDocumentContext
            ;* [out] *
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
          ;* C style interface *
        endif
        ;* __IDebugDocumentHelper64_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_activdbg_0000_0029 *
      ;* [local] *
      externdef __MIDL_itf_activdbg_0000_0029_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_activdbg_0000_0029_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDebugDocumentHost_INTERFACE_DEFINED__
        __IDebugDocumentHost_INTERFACE_DEFINED__ equ <>
        ;* interface IDebugDocumentHost *
        ;* [unique][helpstring][uuid][object] *
        externdef IID_IDebugDocumentHost:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugDocumentHostVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugDocumentHostVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDebugDocumentHost, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugDocumentHost
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugDocumentHost
            DECLSPEC_XFGVIRT(IDebugDocumentHost, GetDeferredText)
            ;* [in] *
            ;* [size_is][length_is][out][in] *
            ;* [size_is][length_is][out][in] *
            ;* [out][in] *
            STD_METHOD GetDeferredText, :ptr IDebugDocumentHost, :DWORD, :ptr WCHAR, :ptr SOURCE_TEXT_ATTR, :ptr ULONG, :ULONG
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugDocumentHost, GetScriptTextAttributes)
            ;* [size_is][in] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD GetScriptTextAttributes, :ptr IDebugDocumentHost, :LPCOLESTR, :ULONG, :LPCOLESTR, :DWORD, :ptr SOURCE_TEXT_ATTR
            ;* [size_is][out][in] *
            DECLSPEC_XFGVIRT(IDebugDocumentHost, OnCreateDocumentContext)
            STD_METHOD OnCreateDocumentContext, :ptr IDebugDocumentHost, :ptr ptr IUnknown
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugDocumentHost, GetPathName)
            ;* [out] *
            STD_METHOD GetPathName, :ptr IDebugDocumentHost, :ptr BSTR, :ptr BOOL
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugDocumentHost, GetFileName)
            STD_METHOD GetFileName, :ptr IDebugDocumentHost, :ptr BSTR
            ;* [out] *
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
          ;* C style interface *
        endif
        ;* __IDebugDocumentHost_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_activdbg_0000_0030 *
      ;* [local] *
      externdef __MIDL_itf_activdbg_0000_0030_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_activdbg_0000_0030_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDebugDocumentContext_INTERFACE_DEFINED__
        __IDebugDocumentContext_INTERFACE_DEFINED__ equ <>
        ;* interface IDebugDocumentContext *
        ;* [unique][uuid][object] *
        externdef IID_IDebugDocumentContext:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugDocumentContextVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugDocumentContextVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDebugDocumentContext, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugDocumentContext
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugDocumentContext
            DECLSPEC_XFGVIRT(IDebugDocumentContext, GetDocument)
            STD_METHOD GetDocument, :ptr IDebugDocumentContext, :ptr ptr IDebugDocument
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugDocumentContext, EnumCodeContexts)
            STD_METHOD EnumCodeContexts, :ptr IDebugDocumentContext, :ptr ptr IEnumDebugCodeContexts
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IDebugDocumentContextVtbl ends
          IDebugDocumentContext struct
            lpVtbl POINTER ?
          IDebugDocumentContext ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IDebugDocumentContext_INTERFACE_DEFINED__ *
      endif
      ifndef __IDebugSessionProvider_INTERFACE_DEFINED__
        __IDebugSessionProvider_INTERFACE_DEFINED__ equ <>
        ;* interface IDebugSessionProvider *
        ;* [unique][helpstring][uuid][object] *
        externdef IID_IDebugSessionProvider:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugSessionProviderVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugSessionProviderVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDebugSessionProvider, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugSessionProvider
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugSessionProvider
            DECLSPEC_XFGVIRT(IDebugSessionProvider, StartDebugSession)
            STD_METHOD StartDebugSession, :ptr IDebugSessionProvider, :ptr IRemoteDebugApplication
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IDebugSessionProviderVtbl ends
          IDebugSessionProvider struct
            lpVtbl POINTER ?
          IDebugSessionProvider ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IDebugSessionProvider_INTERFACE_DEFINED__ *
      endif
      ifndef __IApplicationDebugger_INTERFACE_DEFINED__
        __IApplicationDebugger_INTERFACE_DEFINED__ equ <>
        ;* interface IApplicationDebugger *
        ;* [unique][helpstring][uuid][object] *
        externdef IID_IApplicationDebugger:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IApplicationDebuggerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IApplicationDebuggerVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IApplicationDebugger, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IApplicationDebugger
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IApplicationDebugger
            DECLSPEC_XFGVIRT(IApplicationDebugger, QueryAlive)
            STD_METHOD QueryAlive, :ptr IApplicationDebugger
            DECLSPEC_XFGVIRT(IApplicationDebugger, CreateInstanceAtDebugger)
            ;* [in] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD CreateInstanceAtDebugger, :ptr IApplicationDebugger, :REFCLSID, :ptr IUnknown, :DWORD, :REFIID, :ptr ptr IUnknown
            ;* [iid_is][out] *
            DECLSPEC_XFGVIRT(IApplicationDebugger, onDebugOutput)
            STD_METHOD onDebugOutput, :ptr IApplicationDebugger, :LPCOLESTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IApplicationDebugger, onHandleBreakPoint)
            ;* [in] *
            ;* [in] *
            STD_METHOD onHandleBreakPoint, :ptr IApplicationDebugger, :ptr IRemoteDebugApplicationThread, :BREAKREASON, :ptr IActiveScriptErrorDebug
            ;* [in] *
            DECLSPEC_XFGVIRT(IApplicationDebugger, onClose)
            STD_METHOD onClose, :ptr IApplicationDebugger
            DECLSPEC_XFGVIRT(IApplicationDebugger, onDebuggerEvent)
            ;* [in] *
            STD_METHOD onDebuggerEvent, :ptr IApplicationDebugger, :REFIID, :ptr IUnknown
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IApplicationDebuggerVtbl ends
          IApplicationDebugger struct
            lpVtbl POINTER ?
          IApplicationDebugger ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IApplicationDebugger_INTERFACE_DEFINED__ *
      endif
      ifndef __IApplicationDebuggerUI_INTERFACE_DEFINED__
        __IApplicationDebuggerUI_INTERFACE_DEFINED__ equ <>
        ;* interface IApplicationDebuggerUI *
        ;* [unique][helpstring][uuid][object] *
        externdef IID_IApplicationDebuggerUI:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IApplicationDebuggerUIVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IApplicationDebuggerUIVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IApplicationDebuggerUI, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IApplicationDebuggerUI
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IApplicationDebuggerUI
            DECLSPEC_XFGVIRT(IApplicationDebuggerUI, BringDocumentToTop)
            STD_METHOD BringDocumentToTop, :ptr IApplicationDebuggerUI, :ptr IDebugDocumentText
            ;* [in] *
            DECLSPEC_XFGVIRT(IApplicationDebuggerUI, BringDocumentContextToTop)
            STD_METHOD BringDocumentContextToTop, :ptr IApplicationDebuggerUI, :ptr IDebugDocumentContext
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IApplicationDebuggerUIVtbl ends
          IApplicationDebuggerUI struct
            lpVtbl POINTER ?
          IApplicationDebuggerUI ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IApplicationDebuggerUI_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_activdbg_0000_0034 *
      ;* [local] *
      externdef CLSID_MachineDebugManager:CLSID
      externdef __MIDL_itf_activdbg_0000_0034_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_activdbg_0000_0034_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IMachineDebugManager_INTERFACE_DEFINED__
        __IMachineDebugManager_INTERFACE_DEFINED__ equ <>
        ;* interface IMachineDebugManager *
        ;* [unique][helpstring][uuid][object] *
        externdef IID_IMachineDebugManager:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IMachineDebugManagerVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IMachineDebugManagerVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IMachineDebugManager, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IMachineDebugManager
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IMachineDebugManager
            DECLSPEC_XFGVIRT(IMachineDebugManager, AddApplication)
            ;* [in] *
            STD_METHOD AddApplication, :ptr IMachineDebugManager, :ptr IRemoteDebugApplication, :ptr DWORD
            ;* [out] *
            DECLSPEC_XFGVIRT(IMachineDebugManager, RemoveApplication)
            STD_METHOD RemoveApplication, :ptr IMachineDebugManager, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IMachineDebugManager, EnumApplications)
            STD_METHOD EnumApplications, :ptr IMachineDebugManager, :ptr ptr IEnumRemoteDebugApplications
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IMachineDebugManagerVtbl ends
          IMachineDebugManager struct
            lpVtbl POINTER ?
          IMachineDebugManager ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IMachineDebugManager_INTERFACE_DEFINED__ *
      endif
      ifndef __IMachineDebugManagerCookie_INTERFACE_DEFINED__
        __IMachineDebugManagerCookie_INTERFACE_DEFINED__ equ <>
        ;* interface IMachineDebugManagerCookie *
        ;* [unique][helpstring][uuid][object] *
        externdef IID_IMachineDebugManagerCookie:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IMachineDebugManagerCookieVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IMachineDebugManagerCookieVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IMachineDebugManagerCookie, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IMachineDebugManagerCookie
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IMachineDebugManagerCookie
            DECLSPEC_XFGVIRT(IMachineDebugManagerCookie, AddApplication)
            ;* [in] *
            ;* [in] *
            STD_METHOD AddApplication, :ptr IMachineDebugManagerCookie, :ptr IRemoteDebugApplication, :DWORD, :ptr DWORD
            ;* [out] *
            DECLSPEC_XFGVIRT(IMachineDebugManagerCookie, RemoveApplication)
            ;* [in] *
            STD_METHOD RemoveApplication, :ptr IMachineDebugManagerCookie, :DWORD, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IMachineDebugManagerCookie, EnumApplications)
            STD_METHOD EnumApplications, :ptr IMachineDebugManagerCookie, :ptr ptr IEnumRemoteDebugApplications
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IMachineDebugManagerCookieVtbl ends
          IMachineDebugManagerCookie struct
            lpVtbl POINTER ?
          IMachineDebugManagerCookie ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IMachineDebugManagerCookie_INTERFACE_DEFINED__ *
      endif
      ifndef __IMachineDebugManagerEvents_INTERFACE_DEFINED__
        __IMachineDebugManagerEvents_INTERFACE_DEFINED__ equ <>
        ;* interface IMachineDebugManagerEvents *
        ;* [unique][helpstring][uuid][object] *
        externdef IID_IMachineDebugManagerEvents:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IMachineDebugManagerEventsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IMachineDebugManagerEventsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IMachineDebugManagerEvents, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IMachineDebugManagerEvents
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IMachineDebugManagerEvents
            DECLSPEC_XFGVIRT(IMachineDebugManagerEvents, onAddApplication)
            ;* [in] *
            STD_METHOD onAddApplication, :ptr IMachineDebugManagerEvents, :ptr IRemoteDebugApplication, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IMachineDebugManagerEvents, onRemoveApplication)
            ;* [in] *
            STD_METHOD onRemoveApplication, :ptr IMachineDebugManagerEvents, :ptr IRemoteDebugApplication, :DWORD
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IMachineDebugManagerEventsVtbl ends
          IMachineDebugManagerEvents struct
            lpVtbl POINTER ?
          IMachineDebugManagerEvents ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IMachineDebugManagerEvents_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_activdbg_0000_0037 *
      ;* [local] *
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
        ;* interface IProcessDebugManager32 *
        ;* [local][unique][helpstring][uuid][object] *
        externdef IID_IProcessDebugManager32:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IProcessDebugManager32Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IProcessDebugManager32Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IProcessDebugManager32, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IProcessDebugManager32
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IProcessDebugManager32
            DECLSPEC_XFGVIRT(IProcessDebugManager32, CreateApplication)
            STD_METHOD CreateApplication, :ptr IProcessDebugManager32, :ptr ptr IDebugApplication32
            ;* [out] *
            DECLSPEC_XFGVIRT(IProcessDebugManager32, GetDefaultApplication)
            STD_METHOD GetDefaultApplication, :ptr IProcessDebugManager32, :ptr ptr IDebugApplication32
            ;* [out] *
            DECLSPEC_XFGVIRT(IProcessDebugManager32, AddApplication)
            ;* [in] *
            STD_METHOD AddApplication, :ptr IProcessDebugManager32, :ptr IDebugApplication32, :ptr DWORD
            ;* [out] *
            DECLSPEC_XFGVIRT(IProcessDebugManager32, RemoveApplication)
            STD_METHOD RemoveApplication, :ptr IProcessDebugManager32, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IProcessDebugManager32, CreateDebugDocumentHelper)
            ;* [in] *
            STD_METHOD CreateDebugDocumentHelper, :ptr IProcessDebugManager32, :ptr IUnknown, :ptr ptr IDebugDocumentHelper32
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IProcessDebugManager32Vtbl ends
          IProcessDebugManager32 struct
            lpVtbl POINTER ?
          IProcessDebugManager32 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IProcessDebugManager32_INTERFACE_DEFINED__ *
      endif
      ifndef __IProcessDebugManager64_INTERFACE_DEFINED__
        __IProcessDebugManager64_INTERFACE_DEFINED__ equ <>
        ;* interface IProcessDebugManager64 *
        ;* [local][unique][helpstring][uuid][object] *
        externdef IID_IProcessDebugManager64:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IProcessDebugManager64Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IProcessDebugManager64Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IProcessDebugManager64, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IProcessDebugManager64
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IProcessDebugManager64
            DECLSPEC_XFGVIRT(IProcessDebugManager64, CreateApplication)
            STD_METHOD CreateApplication, :ptr IProcessDebugManager64, :ptr ptr IDebugApplication64
            ;* [out] *
            DECLSPEC_XFGVIRT(IProcessDebugManager64, GetDefaultApplication)
            STD_METHOD GetDefaultApplication, :ptr IProcessDebugManager64, :ptr ptr IDebugApplication64
            ;* [out] *
            DECLSPEC_XFGVIRT(IProcessDebugManager64, AddApplication)
            ;* [in] *
            STD_METHOD AddApplication, :ptr IProcessDebugManager64, :ptr IDebugApplication64, :ptr DWORD
            ;* [out] *
            DECLSPEC_XFGVIRT(IProcessDebugManager64, RemoveApplication)
            STD_METHOD RemoveApplication, :ptr IProcessDebugManager64, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IProcessDebugManager64, CreateDebugDocumentHelper)
            ;* [in] *
            STD_METHOD CreateDebugDocumentHelper, :ptr IProcessDebugManager64, :ptr IUnknown, :ptr ptr IDebugDocumentHelper64
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IProcessDebugManager64Vtbl ends
          IProcessDebugManager64 struct
            lpVtbl POINTER ?
          IProcessDebugManager64 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IProcessDebugManager64_INTERFACE_DEFINED__ *
      endif
      ifndef __IRemoteDebugApplication_INTERFACE_DEFINED__
        __IRemoteDebugApplication_INTERFACE_DEFINED__ equ <>
        ;* interface IRemoteDebugApplication *
        ;* [unique][helpstring][uuid][object] *
        externdef IID_IRemoteDebugApplication:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IRemoteDebugApplicationVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IRemoteDebugApplicationVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IRemoteDebugApplication, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IRemoteDebugApplication
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IRemoteDebugApplication
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, ResumeFromBreakPoint)
            ;* [in] *
            ;* [in] *
            STD_METHOD ResumeFromBreakPoint, :ptr IRemoteDebugApplication, :ptr IRemoteDebugApplicationThread, :BREAKRESUMEACTION, :ERRORRESUMEACTION
            ;* [in] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, CauseBreak)
            STD_METHOD CauseBreak, :ptr IRemoteDebugApplication
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, ConnectDebugger)
            STD_METHOD ConnectDebugger, :ptr IRemoteDebugApplication, :ptr IApplicationDebugger
            ;* [in] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, DisconnectDebugger)
            STD_METHOD DisconnectDebugger, :ptr IRemoteDebugApplication
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, GetDebugger)
            STD_METHOD GetDebugger, :ptr IRemoteDebugApplication, :ptr ptr IApplicationDebugger
            ;* [out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, CreateInstanceAtApplication)
            ;* [in] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD CreateInstanceAtApplication, :ptr IRemoteDebugApplication, :REFCLSID, :ptr IUnknown, :DWORD, :REFIID, :ptr ptr IUnknown
            ;* [iid_is][out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, QueryAlive)
            STD_METHOD QueryAlive, :ptr IRemoteDebugApplication
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, EnumThreads)
            STD_METHOD EnumThreads, :ptr IRemoteDebugApplication, :ptr ptr IEnumRemoteDebugApplicationThreads
            ;* [out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, GetName)
            STD_METHOD GetName, :ptr IRemoteDebugApplication, :ptr BSTR
            ;* [out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, GetRootNode)
            STD_METHOD GetRootNode, :ptr IRemoteDebugApplication, :ptr ptr IDebugApplicationNode
            ;* [out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, EnumGlobalExpressionContexts)
            STD_METHOD EnumGlobalExpressionContexts, :ptr IRemoteDebugApplication, :ptr ptr IEnumDebugExpressionContexts
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IRemoteDebugApplicationVtbl ends
          IRemoteDebugApplication struct
            lpVtbl POINTER ?
          IRemoteDebugApplication ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IRemoteDebugApplication_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_activdbg_0000_0040 *
      ;* [local] *
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
        ;* interface IDebugApplication32 *
        ;* [local][unique][helpstring][uuid][object] *
        externdef IID_IDebugApplication32:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugApplication32Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugApplication32Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDebugApplication32, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugApplication32
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugApplication32
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, ResumeFromBreakPoint)
            ;* [in] *
            ;* [in] *
            STD_METHOD ResumeFromBreakPoint, :ptr IDebugApplication32, :ptr IRemoteDebugApplicationThread, :BREAKRESUMEACTION, :ERRORRESUMEACTION
            ;* [in] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, CauseBreak)
            STD_METHOD CauseBreak, :ptr IDebugApplication32
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, ConnectDebugger)
            STD_METHOD ConnectDebugger, :ptr IDebugApplication32, :ptr IApplicationDebugger
            ;* [in] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, DisconnectDebugger)
            STD_METHOD DisconnectDebugger, :ptr IDebugApplication32
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, GetDebugger)
            STD_METHOD GetDebugger, :ptr IDebugApplication32, :ptr ptr IApplicationDebugger
            ;* [out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, CreateInstanceAtApplication)
            ;* [in] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD CreateInstanceAtApplication, :ptr IDebugApplication32, :REFCLSID, :ptr IUnknown, :DWORD, :REFIID, :ptr ptr IUnknown
            ;* [iid_is][out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, QueryAlive)
            STD_METHOD QueryAlive, :ptr IDebugApplication32
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, EnumThreads)
            STD_METHOD EnumThreads, :ptr IDebugApplication32, :ptr ptr IEnumRemoteDebugApplicationThreads
            ;* [out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, GetName)
            STD_METHOD GetName, :ptr IDebugApplication32, :ptr BSTR
            ;* [out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, GetRootNode)
            STD_METHOD GetRootNode, :ptr IDebugApplication32, :ptr ptr IDebugApplicationNode
            ;* [out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, EnumGlobalExpressionContexts)
            STD_METHOD EnumGlobalExpressionContexts, :ptr IDebugApplication32, :ptr ptr IEnumDebugExpressionContexts
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugApplication32, SetName)
            STD_METHOD SetName, :ptr IDebugApplication32, :LPCOLESTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugApplication32, StepOutComplete)
            STD_METHOD StepOutComplete, :ptr IDebugApplication32
            DECLSPEC_XFGVIRT(IDebugApplication32, DebugOutput)
            STD_METHOD DebugOutput, :ptr IDebugApplication32, :LPCOLESTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugApplication32, StartDebugSession)
            STD_METHOD StartDebugSession, :ptr IDebugApplication32
            DECLSPEC_XFGVIRT(IDebugApplication32, HandleBreakPoint)
            ;* [in] *
            STD_METHOD HandleBreakPoint, :ptr IDebugApplication32, :BREAKREASON, :ptr BREAKRESUMEACTION
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugApplication32, Close)
            STD_METHOD Close, :ptr IDebugApplication32
            DECLSPEC_XFGVIRT(IDebugApplication32, GetBreakFlags)
            ;* [out] *
            STD_METHOD GetBreakFlags, :ptr IDebugApplication32, :ptr APPBREAKFLAGS, :ptr ptr IRemoteDebugApplicationThread
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugApplication32, GetCurrentThread)
            STD_METHOD GetCurrentThread, :ptr IDebugApplication32, :ptr ptr IDebugApplicationThread
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugApplication32, CreateAsyncDebugOperation)
            ;* [in] *
            STD_METHOD CreateAsyncDebugOperation, :ptr IDebugApplication32, :ptr IDebugSyncOperation, :ptr ptr IDebugAsyncOperation
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugApplication32, AddStackFrameSniffer)
            ;* [in] *
            STD_METHOD AddStackFrameSniffer, :ptr IDebugApplication32, :ptr IDebugStackFrameSniffer, :ptr DWORD
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugApplication32, RemoveStackFrameSniffer)
            STD_METHOD RemoveStackFrameSniffer, :ptr IDebugApplication32, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugApplication32, QueryCurrentThreadIsDebuggerThread)
            STD_METHOD QueryCurrentThreadIsDebuggerThread, :ptr IDebugApplication32
            DECLSPEC_XFGVIRT(IDebugApplication32, SynchronousCallInDebuggerThread)
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD SynchronousCallInDebuggerThread, :ptr IDebugApplication32, :ptr IDebugThreadCall32, :DWORD, :DWORD, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugApplication32, CreateApplicationNode)
            STD_METHOD CreateApplicationNode, :ptr IDebugApplication32, :ptr ptr IDebugApplicationNode
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugApplication32, FireDebuggerEvent)
            ;* [in] *
            STD_METHOD FireDebuggerEvent, :ptr IDebugApplication32, :REFGUID, :ptr IUnknown
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugApplication32, HandleRuntimeError)
            ;* [in] *
            ;* [in] *
            ;* [out] *
            ;* [out] *
            STD_METHOD HandleRuntimeError, :ptr IDebugApplication32, :ptr IActiveScriptErrorDebug, :ptr IActiveScriptSite, :ptr BREAKRESUMEACTION, :ptr ERRORRESUMEACTION, :ptr BOOL
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugApplication32, FCanJitDebug)
            STD_METHOD FCanJitDebug, :ptr IDebugApplication32
            DECLSPEC_XFGVIRT(IDebugApplication32, FIsAutoJitDebugEnabled)
            STD_METHOD FIsAutoJitDebugEnabled, :ptr IDebugApplication32
            DECLSPEC_XFGVIRT(IDebugApplication32, AddGlobalExpressionContextProvider)
            ;* [in] *
            STD_METHOD AddGlobalExpressionContextProvider, :ptr IDebugApplication32, :ptr IProvideExpressionContexts, :ptr DWORD
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugApplication32, RemoveGlobalExpressionContextProvider)
            STD_METHOD RemoveGlobalExpressionContextProvider, :ptr IDebugApplication32, :DWORD
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IDebugApplication32Vtbl ends
          IDebugApplication32 struct
            lpVtbl POINTER ?
          IDebugApplication32 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IDebugApplication32_INTERFACE_DEFINED__ *
      endif
      ifndef __IDebugApplication64_INTERFACE_DEFINED__
        __IDebugApplication64_INTERFACE_DEFINED__ equ <>
        ;* interface IDebugApplication64 *
        ;* [local][unique][helpstring][uuid][object] *
        externdef IID_IDebugApplication64:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugApplication64Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugApplication64Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDebugApplication64, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugApplication64
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugApplication64
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, ResumeFromBreakPoint)
            ;* [in] *
            ;* [in] *
            STD_METHOD ResumeFromBreakPoint, :ptr IDebugApplication64, :ptr IRemoteDebugApplicationThread, :BREAKRESUMEACTION, :ERRORRESUMEACTION
            ;* [in] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, CauseBreak)
            STD_METHOD CauseBreak, :ptr IDebugApplication64
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, ConnectDebugger)
            STD_METHOD ConnectDebugger, :ptr IDebugApplication64, :ptr IApplicationDebugger
            ;* [in] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, DisconnectDebugger)
            STD_METHOD DisconnectDebugger, :ptr IDebugApplication64
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, GetDebugger)
            STD_METHOD GetDebugger, :ptr IDebugApplication64, :ptr ptr IApplicationDebugger
            ;* [out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, CreateInstanceAtApplication)
            ;* [in] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD CreateInstanceAtApplication, :ptr IDebugApplication64, :REFCLSID, :ptr IUnknown, :DWORD, :REFIID, :ptr ptr IUnknown
            ;* [iid_is][out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, QueryAlive)
            STD_METHOD QueryAlive, :ptr IDebugApplication64
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, EnumThreads)
            STD_METHOD EnumThreads, :ptr IDebugApplication64, :ptr ptr IEnumRemoteDebugApplicationThreads
            ;* [out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, GetName)
            STD_METHOD GetName, :ptr IDebugApplication64, :ptr BSTR
            ;* [out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, GetRootNode)
            STD_METHOD GetRootNode, :ptr IDebugApplication64, :ptr ptr IDebugApplicationNode
            ;* [out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplication, EnumGlobalExpressionContexts)
            STD_METHOD EnumGlobalExpressionContexts, :ptr IDebugApplication64, :ptr ptr IEnumDebugExpressionContexts
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugApplication64, SetName)
            STD_METHOD SetName, :ptr IDebugApplication64, :LPCOLESTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugApplication64, StepOutComplete)
            STD_METHOD StepOutComplete, :ptr IDebugApplication64
            DECLSPEC_XFGVIRT(IDebugApplication64, DebugOutput)
            STD_METHOD DebugOutput, :ptr IDebugApplication64, :LPCOLESTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugApplication64, StartDebugSession)
            STD_METHOD StartDebugSession, :ptr IDebugApplication64
            DECLSPEC_XFGVIRT(IDebugApplication64, HandleBreakPoint)
            ;* [in] *
            STD_METHOD HandleBreakPoint, :ptr IDebugApplication64, :BREAKREASON, :ptr BREAKRESUMEACTION
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugApplication64, Close)
            STD_METHOD Close, :ptr IDebugApplication64
            DECLSPEC_XFGVIRT(IDebugApplication64, GetBreakFlags)
            ;* [out] *
            STD_METHOD GetBreakFlags, :ptr IDebugApplication64, :ptr APPBREAKFLAGS, :ptr ptr IRemoteDebugApplicationThread
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugApplication64, GetCurrentThread)
            STD_METHOD GetCurrentThread, :ptr IDebugApplication64, :ptr ptr IDebugApplicationThread
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugApplication64, CreateAsyncDebugOperation)
            ;* [in] *
            STD_METHOD CreateAsyncDebugOperation, :ptr IDebugApplication64, :ptr IDebugSyncOperation, :ptr ptr IDebugAsyncOperation
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugApplication64, AddStackFrameSniffer)
            ;* [in] *
            STD_METHOD AddStackFrameSniffer, :ptr IDebugApplication64, :ptr IDebugStackFrameSniffer, :ptr DWORD
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugApplication64, RemoveStackFrameSniffer)
            STD_METHOD RemoveStackFrameSniffer, :ptr IDebugApplication64, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugApplication64, QueryCurrentThreadIsDebuggerThread)
            STD_METHOD QueryCurrentThreadIsDebuggerThread, :ptr IDebugApplication64
            DECLSPEC_XFGVIRT(IDebugApplication64, SynchronousCallInDebuggerThread)
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD SynchronousCallInDebuggerThread, :ptr IDebugApplication64, :ptr IDebugThreadCall64, :DWORDLONG, :DWORDLONG, :DWORDLONG
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugApplication64, CreateApplicationNode)
            STD_METHOD CreateApplicationNode, :ptr IDebugApplication64, :ptr ptr IDebugApplicationNode
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugApplication64, FireDebuggerEvent)
            ;* [in] *
            STD_METHOD FireDebuggerEvent, :ptr IDebugApplication64, :REFGUID, :ptr IUnknown
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugApplication64, HandleRuntimeError)
            ;* [in] *
            ;* [in] *
            ;* [out] *
            ;* [out] *
            STD_METHOD HandleRuntimeError, :ptr IDebugApplication64, :ptr IActiveScriptErrorDebug, :ptr IActiveScriptSite, :ptr BREAKRESUMEACTION, :ptr ERRORRESUMEACTION, :ptr BOOL
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugApplication64, FCanJitDebug)
            STD_METHOD FCanJitDebug, :ptr IDebugApplication64
            DECLSPEC_XFGVIRT(IDebugApplication64, FIsAutoJitDebugEnabled)
            STD_METHOD FIsAutoJitDebugEnabled, :ptr IDebugApplication64
            DECLSPEC_XFGVIRT(IDebugApplication64, AddGlobalExpressionContextProvider)
            ;* [in] *
            STD_METHOD AddGlobalExpressionContextProvider, :ptr IDebugApplication64, :ptr IProvideExpressionContexts, :ptr DWORDLONG
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugApplication64, RemoveGlobalExpressionContextProvider)
            STD_METHOD RemoveGlobalExpressionContextProvider, :ptr IDebugApplication64, :DWORDLONG
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IDebugApplication64Vtbl ends
          IDebugApplication64 struct
            lpVtbl POINTER ?
          IDebugApplication64 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IDebugApplication64_INTERFACE_DEFINED__ *
      endif
      ifndef __IRemoteDebugApplicationEvents_INTERFACE_DEFINED__
        __IRemoteDebugApplicationEvents_INTERFACE_DEFINED__ equ <>
        ;* interface IRemoteDebugApplicationEvents *
        ;* [unique][helpstring][uuid][object] *
        externdef IID_IRemoteDebugApplicationEvents:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IRemoteDebugApplicationEventsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IRemoteDebugApplicationEventsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IRemoteDebugApplicationEvents, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IRemoteDebugApplicationEvents
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IRemoteDebugApplicationEvents
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationEvents, OnConnectDebugger)
            STD_METHOD OnConnectDebugger, :ptr IRemoteDebugApplicationEvents, :ptr IApplicationDebugger
            ;* [in] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationEvents, OnDisconnectDebugger)
            STD_METHOD OnDisconnectDebugger, :ptr IRemoteDebugApplicationEvents
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationEvents, OnSetName)
            STD_METHOD OnSetName, :ptr IRemoteDebugApplicationEvents, :LPCOLESTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationEvents, OnDebugOutput)
            STD_METHOD OnDebugOutput, :ptr IRemoteDebugApplicationEvents, :LPCOLESTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationEvents, OnClose)
            STD_METHOD OnClose, :ptr IRemoteDebugApplicationEvents
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationEvents, OnEnterBreakPoint)
            STD_METHOD OnEnterBreakPoint, :ptr IRemoteDebugApplicationEvents, :ptr IRemoteDebugApplicationThread
            ;* [in] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationEvents, OnLeaveBreakPoint)
            STD_METHOD OnLeaveBreakPoint, :ptr IRemoteDebugApplicationEvents, :ptr IRemoteDebugApplicationThread
            ;* [in] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationEvents, OnCreateThread)
            STD_METHOD OnCreateThread, :ptr IRemoteDebugApplicationEvents, :ptr IRemoteDebugApplicationThread
            ;* [in] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationEvents, OnDestroyThread)
            STD_METHOD OnDestroyThread, :ptr IRemoteDebugApplicationEvents, :ptr IRemoteDebugApplicationThread
            ;* [in] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationEvents, OnBreakFlagChange)
            ;* [in] *
            STD_METHOD OnBreakFlagChange, :ptr IRemoteDebugApplicationEvents, :APPBREAKFLAGS, :ptr IRemoteDebugApplicationThread
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IRemoteDebugApplicationEventsVtbl ends
          IRemoteDebugApplicationEvents struct
            lpVtbl POINTER ?
          IRemoteDebugApplicationEvents ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IRemoteDebugApplicationEvents_INTERFACE_DEFINED__ *
      endif
      ifndef __IDebugApplicationNode_INTERFACE_DEFINED__
        __IDebugApplicationNode_INTERFACE_DEFINED__ equ <>
        ;* interface IDebugApplicationNode *
        ;* [unique][uuid][object] *
        externdef IID_IDebugApplicationNode:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugApplicationNodeVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugApplicationNodeVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDebugApplicationNode, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugApplicationNode
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugApplicationNode
            DECLSPEC_XFGVIRT(IDebugDocumentInfo, GetName)
            ;* [in] *
            STD_METHOD GetName, :ptr IDebugApplicationNode, :DOCUMENTNAMETYPE, :ptr BSTR
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugDocumentInfo, GetDocumentClassId)
            STD_METHOD GetDocumentClassId, :ptr IDebugApplicationNode, :ptr CLSID
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugDocumentProvider, GetDocument)
            STD_METHOD GetDocument, :ptr IDebugApplicationNode, :ptr ptr IDebugDocument
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugApplicationNode, EnumChildren)
            STD_METHOD EnumChildren, :ptr IDebugApplicationNode, :ptr ptr IEnumDebugApplicationNodes
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugApplicationNode, GetParent)
            STD_METHOD GetParent, :ptr IDebugApplicationNode, :ptr ptr IDebugApplicationNode
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugApplicationNode, SetDocumentProvider)
            STD_METHOD SetDocumentProvider, :ptr IDebugApplicationNode, :ptr IDebugDocumentProvider
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugApplicationNode, Close)
            STD_METHOD Close, :ptr IDebugApplicationNode
            DECLSPEC_XFGVIRT(IDebugApplicationNode, Attach)
            STD_METHOD Attach, :ptr IDebugApplicationNode, :ptr IDebugApplicationNode
            ;* [in] *
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
          ;* C style interface *
        endif
        ;* __IDebugApplicationNode_INTERFACE_DEFINED__ *
      endif
      ifndef __IDebugApplicationNodeEvents_INTERFACE_DEFINED__
        __IDebugApplicationNodeEvents_INTERFACE_DEFINED__ equ <>
        ;* interface IDebugApplicationNodeEvents *
        ;* [unique][async_uuid][uuid][object] *
        externdef IID_IDebugApplicationNodeEvents:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugApplicationNodeEventsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugApplicationNodeEventsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDebugApplicationNodeEvents, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugApplicationNodeEvents
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugApplicationNodeEvents
            DECLSPEC_XFGVIRT(IDebugApplicationNodeEvents, onAddChild)
            STD_METHOD onAddChild, :ptr IDebugApplicationNodeEvents, :ptr IDebugApplicationNode
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugApplicationNodeEvents, onRemoveChild)
            STD_METHOD onRemoveChild, :ptr IDebugApplicationNodeEvents, :ptr IDebugApplicationNode
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugApplicationNodeEvents, onDetach)
            STD_METHOD onDetach, :ptr IDebugApplicationNodeEvents
            DECLSPEC_XFGVIRT(IDebugApplicationNodeEvents, onAttach)
            STD_METHOD onAttach, :ptr IDebugApplicationNodeEvents, :ptr IDebugApplicationNode
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IDebugApplicationNodeEventsVtbl ends
          IDebugApplicationNodeEvents struct
            lpVtbl POINTER ?
          IDebugApplicationNodeEvents ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IDebugApplicationNodeEvents_INTERFACE_DEFINED__ *
      endif
      ifndef __AsyncIDebugApplicationNodeEvents_INTERFACE_DEFINED__
        __AsyncIDebugApplicationNodeEvents_INTERFACE_DEFINED__ equ <>
        ;* interface AsyncIDebugApplicationNodeEvents *
        ;* [uuid][unique][object] *
        externdef IID_AsyncIDebugApplicationNodeEvents:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          AsyncIDebugApplicationNodeEventsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <AsyncIDebugApplicationNodeEventsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr AsyncIDebugApplicationNodeEvents, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr AsyncIDebugApplicationNodeEvents
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr AsyncIDebugApplicationNodeEvents
            DECLSPEC_XFGVIRT(AsyncIDebugApplicationNodeEvents, Begin_onAddChild)
            STD_METHOD Begin_onAddChild, :ptr AsyncIDebugApplicationNodeEvents, :ptr IDebugApplicationNode
            ;* [in] *
            DECLSPEC_XFGVIRT(AsyncIDebugApplicationNodeEvents, Finish_onAddChild)
            STD_METHOD Finish_onAddChild, :ptr AsyncIDebugApplicationNodeEvents
            DECLSPEC_XFGVIRT(AsyncIDebugApplicationNodeEvents, Begin_onRemoveChild)
            STD_METHOD Begin_onRemoveChild, :ptr AsyncIDebugApplicationNodeEvents, :ptr IDebugApplicationNode
            ;* [in] *
            DECLSPEC_XFGVIRT(AsyncIDebugApplicationNodeEvents, Finish_onRemoveChild)
            STD_METHOD Finish_onRemoveChild, :ptr AsyncIDebugApplicationNodeEvents
            DECLSPEC_XFGVIRT(AsyncIDebugApplicationNodeEvents, Begin_onDetach)
            STD_METHOD Begin_onDetach, :ptr AsyncIDebugApplicationNodeEvents
            DECLSPEC_XFGVIRT(AsyncIDebugApplicationNodeEvents, Finish_onDetach)
            STD_METHOD Finish_onDetach, :ptr AsyncIDebugApplicationNodeEvents
            DECLSPEC_XFGVIRT(AsyncIDebugApplicationNodeEvents, Begin_onAttach)
            STD_METHOD Begin_onAttach, :ptr AsyncIDebugApplicationNodeEvents, :ptr IDebugApplicationNode
            ;* [in] *
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
          ;* C style interface *
        endif
        ;* __AsyncIDebugApplicationNodeEvents_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_activdbg_0000_0045 *
      ;* [local] *
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
        ;* interface IDebugThreadCall32 *
        ;* [local][unique][uuid][object] *
        externdef IID_IDebugThreadCall32:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugThreadCall32Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugThreadCall32Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDebugThreadCall32, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugThreadCall32
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugThreadCall32
            DECLSPEC_XFGVIRT(IDebugThreadCall32, ThreadCallHandler)
            ;* [in] *
            ;* [in] *
            STD_METHOD ThreadCallHandler, :ptr IDebugThreadCall32, :DWORD, :DWORD, :DWORD
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IDebugThreadCall32Vtbl ends
          IDebugThreadCall32 struct
            lpVtbl POINTER ?
          IDebugThreadCall32 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IDebugThreadCall32_INTERFACE_DEFINED__ *
      endif
      ifndef __IDebugThreadCall64_INTERFACE_DEFINED__
        __IDebugThreadCall64_INTERFACE_DEFINED__ equ <>
        ;* interface IDebugThreadCall64 *
        ;* [local][unique][uuid][object] *
        externdef IID_IDebugThreadCall64:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugThreadCall64Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugThreadCall64Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDebugThreadCall64, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugThreadCall64
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugThreadCall64
            DECLSPEC_XFGVIRT(IDebugThreadCall64, ThreadCallHandler)
            ;* [in] *
            ;* [in] *
            STD_METHOD ThreadCallHandler, :ptr IDebugThreadCall64, :DWORDLONG, :DWORDLONG, :DWORDLONG
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IDebugThreadCall64Vtbl ends
          IDebugThreadCall64 struct
            lpVtbl POINTER ?
          IDebugThreadCall64 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IDebugThreadCall64_INTERFACE_DEFINED__ *
      endif
      ifndef __IRemoteDebugApplicationThread_INTERFACE_DEFINED__
        __IRemoteDebugApplicationThread_INTERFACE_DEFINED__ equ <>
        ;* interface IRemoteDebugApplicationThread *
        ;* [unique][uuid][object] *
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
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IRemoteDebugApplicationThread, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IRemoteDebugApplicationThread
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IRemoteDebugApplicationThread
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, GetSystemThreadId)
            STD_METHOD GetSystemThreadId, :ptr IRemoteDebugApplicationThread, :ptr DWORD
            ;* [out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, GetApplication)
            STD_METHOD GetApplication, :ptr IRemoteDebugApplicationThread, :ptr ptr IRemoteDebugApplication
            ;* [out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, EnumStackFrames)
            STD_METHOD EnumStackFrames, :ptr IRemoteDebugApplicationThread, :ptr ptr IEnumDebugStackFrames
            ;* [out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, GetDescription)
            ;* [out] *
            STD_METHOD GetDescription, :ptr IRemoteDebugApplicationThread, :ptr BSTR, :ptr BSTR
            ;* [out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, SetNextStatement)
            ;* [in] *
            STD_METHOD SetNextStatement, :ptr IRemoteDebugApplicationThread, :ptr IDebugStackFrame, :ptr IDebugCodeContext
            ;* [in] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, GetState)
            STD_METHOD GetState, :ptr IRemoteDebugApplicationThread, :ptr DWORD
            ;* [out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, Suspend)
            STD_METHOD Suspend, :ptr IRemoteDebugApplicationThread, :ptr DWORD
            ;* [out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, Resume)
            STD_METHOD Resume, :ptr IRemoteDebugApplicationThread, :ptr DWORD
            ;* [out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, GetSuspendCount)
            STD_METHOD GetSuspendCount, :ptr IRemoteDebugApplicationThread, :ptr DWORD
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IRemoteDebugApplicationThreadVtbl ends
          IRemoteDebugApplicationThread struct
            lpVtbl POINTER ?
          IRemoteDebugApplicationThread ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IRemoteDebugApplicationThread_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_activdbg_0000_0048 *
      ;* [local] *
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
        ;* interface IDebugApplicationThread *
        ;* [local][unique][uuid][object] *
        externdef IID_IDebugApplicationThread:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugApplicationThreadVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugApplicationThreadVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDebugApplicationThread, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugApplicationThread
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugApplicationThread
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, GetSystemThreadId)
            STD_METHOD GetSystemThreadId, :ptr IDebugApplicationThread, :ptr DWORD
            ;* [out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, GetApplication)
            STD_METHOD GetApplication, :ptr IDebugApplicationThread, :ptr ptr IRemoteDebugApplication
            ;* [out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, EnumStackFrames)
            STD_METHOD EnumStackFrames, :ptr IDebugApplicationThread, :ptr ptr IEnumDebugStackFrames
            ;* [out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, GetDescription)
            ;* [out] *
            STD_METHOD GetDescription, :ptr IDebugApplicationThread, :ptr BSTR, :ptr BSTR
            ;* [out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, SetNextStatement)
            ;* [in] *
            STD_METHOD SetNextStatement, :ptr IDebugApplicationThread, :ptr IDebugStackFrame, :ptr IDebugCodeContext
            ;* [in] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, GetState)
            STD_METHOD GetState, :ptr IDebugApplicationThread, :ptr DWORD
            ;* [out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, Suspend)
            STD_METHOD Suspend, :ptr IDebugApplicationThread, :ptr DWORD
            ;* [out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, Resume)
            STD_METHOD Resume, :ptr IDebugApplicationThread, :ptr DWORD
            ;* [out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, GetSuspendCount)
            STD_METHOD GetSuspendCount, :ptr IDebugApplicationThread, :ptr DWORD
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugApplicationThread, SynchronousCallIntoThread32)
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD SynchronousCallIntoThread32, :ptr IDebugApplicationThread, :ptr IDebugThreadCall32, :DWORD, :DWORD, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugApplicationThread, QueryIsCurrentThread)
            STD_METHOD QueryIsCurrentThread, :ptr IDebugApplicationThread
            DECLSPEC_XFGVIRT(IDebugApplicationThread, QueryIsDebuggerThread)
            STD_METHOD QueryIsDebuggerThread, :ptr IDebugApplicationThread
            DECLSPEC_XFGVIRT(IDebugApplicationThread, SetDescription)
            STD_METHOD SetDescription, :ptr IDebugApplicationThread, :LPCOLESTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugApplicationThread, SetStateString)
            STD_METHOD SetStateString, :ptr IDebugApplicationThread, :LPCOLESTR
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IDebugApplicationThreadVtbl ends
          IDebugApplicationThread struct
            lpVtbl POINTER ?
          IDebugApplicationThread ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IDebugApplicationThread_INTERFACE_DEFINED__ *
      endif
      ifndef __IDebugApplicationThread64_INTERFACE_DEFINED__
        __IDebugApplicationThread64_INTERFACE_DEFINED__ equ <>
        ;* interface IDebugApplicationThread64 *
        ;* [local][unique][uuid][object] *
        externdef IID_IDebugApplicationThread64:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugApplicationThread64Vtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugApplicationThread64Vtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDebugApplicationThread64, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugApplicationThread64
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugApplicationThread64
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, GetSystemThreadId)
            STD_METHOD GetSystemThreadId, :ptr IDebugApplicationThread64, :ptr DWORD
            ;* [out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, GetApplication)
            STD_METHOD GetApplication, :ptr IDebugApplicationThread64, :ptr ptr IRemoteDebugApplication
            ;* [out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, EnumStackFrames)
            STD_METHOD EnumStackFrames, :ptr IDebugApplicationThread64, :ptr ptr IEnumDebugStackFrames
            ;* [out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, GetDescription)
            ;* [out] *
            STD_METHOD GetDescription, :ptr IDebugApplicationThread64, :ptr BSTR, :ptr BSTR
            ;* [out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, SetNextStatement)
            ;* [in] *
            STD_METHOD SetNextStatement, :ptr IDebugApplicationThread64, :ptr IDebugStackFrame, :ptr IDebugCodeContext
            ;* [in] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, GetState)
            STD_METHOD GetState, :ptr IDebugApplicationThread64, :ptr DWORD
            ;* [out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, Suspend)
            STD_METHOD Suspend, :ptr IDebugApplicationThread64, :ptr DWORD
            ;* [out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, Resume)
            STD_METHOD Resume, :ptr IDebugApplicationThread64, :ptr DWORD
            ;* [out] *
            DECLSPEC_XFGVIRT(IRemoteDebugApplicationThread, GetSuspendCount)
            STD_METHOD GetSuspendCount, :ptr IDebugApplicationThread64, :ptr DWORD
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugApplicationThread, SynchronousCallIntoThread32)
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD SynchronousCallIntoThread32, :ptr IDebugApplicationThread64, :ptr IDebugThreadCall32, :DWORD, :DWORD, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugApplicationThread, QueryIsCurrentThread)
            STD_METHOD QueryIsCurrentThread, :ptr IDebugApplicationThread64
            DECLSPEC_XFGVIRT(IDebugApplicationThread, QueryIsDebuggerThread)
            STD_METHOD QueryIsDebuggerThread, :ptr IDebugApplicationThread64
            DECLSPEC_XFGVIRT(IDebugApplicationThread, SetDescription)
            STD_METHOD SetDescription, :ptr IDebugApplicationThread64, :LPCOLESTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugApplicationThread, SetStateString)
            STD_METHOD SetStateString, :ptr IDebugApplicationThread64, :LPCOLESTR
            ;* [in] *
            DECLSPEC_XFGVIRT(IDebugApplicationThread64, SynchronousCallIntoThread64)
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD SynchronousCallIntoThread64, :ptr IDebugApplicationThread64, :ptr IDebugThreadCall64, :DWORDLONG, :DWORDLONG, :DWORDLONG
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IDebugApplicationThread64Vtbl ends
          IDebugApplicationThread64 struct
            lpVtbl POINTER ?
          IDebugApplicationThread64 ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IDebugApplicationThread64_INTERFACE_DEFINED__ *
      endif
      ifndef __IDebugCookie_INTERFACE_DEFINED__
        __IDebugCookie_INTERFACE_DEFINED__ equ <>
        ;* interface IDebugCookie *
        ;* [unique][helpstring][uuid][local][object] *
        externdef IID_IDebugCookie:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugCookieVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugCookieVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDebugCookie, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugCookie
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugCookie
            DECLSPEC_XFGVIRT(IDebugCookie, SetDebugCookie)
            STD_METHOD SetDebugCookie, :ptr IDebugCookie, :DWORD
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          IDebugCookieVtbl ends
          IDebugCookie struct
            lpVtbl POINTER ?
          IDebugCookie ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IDebugCookie_INTERFACE_DEFINED__ *
      endif
      ifndef __IEnumDebugApplicationNodes_INTERFACE_DEFINED__
        __IEnumDebugApplicationNodes_INTERFACE_DEFINED__ equ <>
        ;* interface IEnumDebugApplicationNodes *
        ;* [unique][helpstring][uuid][object] *
        externdef IID_IEnumDebugApplicationNodes:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IEnumDebugApplicationNodesVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEnumDebugApplicationNodesVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IEnumDebugApplicationNodes, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IEnumDebugApplicationNodes
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IEnumDebugApplicationNodes
            DECLSPEC_XFGVIRT(IEnumDebugApplicationNodes, Next)
            ;* [local] *
            ;* [in] *
            ;* [out] *
            STD_METHOD Next, :ptr IEnumDebugApplicationNodes, :ULONG, :ptr ptr IDebugApplicationNode, :ptr ULONG
            ;* [out] *
            DECLSPEC_XFGVIRT(IEnumDebugApplicationNodes, Skip)
            STD_METHOD Skip, :ptr IEnumDebugApplicationNodes, :ULONG
            ;* [in] *
            DECLSPEC_XFGVIRT(IEnumDebugApplicationNodes, Reset)
            STD_METHOD Reset, :ptr IEnumDebugApplicationNodes
            DECLSPEC_XFGVIRT(IEnumDebugApplicationNodes, Clone)
            STD_METHOD Clone, :ptr IEnumDebugApplicationNodes, :ptr ptr IEnumDebugApplicationNodes
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IEnumDebugApplicationNodesVtbl ends
          IEnumDebugApplicationNodes struct
            lpVtbl POINTER ?
          IEnumDebugApplicationNodes ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* [call_as] *
        IEnumDebugApplicationNodes_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumDebugApplicationNodes, :ULONG, :ptr ptr IDebugApplicationNode, :ptr ULONG
        ;* [out] *
        IEnumDebugApplicationNodes_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        ;* __IEnumDebugApplicationNodes_INTERFACE_DEFINED__ *
      endif
      ifndef __IEnumRemoteDebugApplications_INTERFACE_DEFINED__
        __IEnumRemoteDebugApplications_INTERFACE_DEFINED__ equ <>
        ;* interface IEnumRemoteDebugApplications *
        ;* [unique][helpstring][uuid][object] *
        externdef IID_IEnumRemoteDebugApplications:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IEnumRemoteDebugApplicationsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEnumRemoteDebugApplicationsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IEnumRemoteDebugApplications, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IEnumRemoteDebugApplications
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IEnumRemoteDebugApplications
            DECLSPEC_XFGVIRT(IEnumRemoteDebugApplications, Next)
            ;* [local] *
            ;* [in] *
            ;* [out] *
            STD_METHOD Next, :ptr IEnumRemoteDebugApplications, :ULONG, :ptr ptr IRemoteDebugApplication, :ptr ULONG
            ;* [out] *
            DECLSPEC_XFGVIRT(IEnumRemoteDebugApplications, Skip)
            STD_METHOD Skip, :ptr IEnumRemoteDebugApplications, :ULONG
            ;* [in] *
            DECLSPEC_XFGVIRT(IEnumRemoteDebugApplications, Reset)
            STD_METHOD Reset, :ptr IEnumRemoteDebugApplications
            DECLSPEC_XFGVIRT(IEnumRemoteDebugApplications, Clone)
            STD_METHOD Clone, :ptr IEnumRemoteDebugApplications, :ptr ptr IEnumRemoteDebugApplications
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IEnumRemoteDebugApplicationsVtbl ends
          IEnumRemoteDebugApplications struct
            lpVtbl POINTER ?
          IEnumRemoteDebugApplications ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* [call_as] *
        IEnumRemoteDebugApplications_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumRemoteDebugApplications, :ULONG, :ptr ptr IRemoteDebugApplication, :ptr ULONG
        ;* [out] *
        IEnumRemoteDebugApplications_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        ;* __IEnumRemoteDebugApplications_INTERFACE_DEFINED__ *
      endif
      ifndef __IEnumRemoteDebugApplicationThreads_INTERFACE_DEFINED__
        __IEnumRemoteDebugApplicationThreads_INTERFACE_DEFINED__ equ <>
        ;* interface IEnumRemoteDebugApplicationThreads *
        ;* [unique][helpstring][uuid][object] *
        externdef IID_IEnumRemoteDebugApplicationThreads:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IEnumRemoteDebugApplicationThreadsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEnumRemoteDebugApplicationThreadsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IEnumRemoteDebugApplicationThreads, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IEnumRemoteDebugApplicationThreads
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IEnumRemoteDebugApplicationThreads
            DECLSPEC_XFGVIRT(IEnumRemoteDebugApplicationThreads, Next)
            ;* [local] *
            ;* [in] *
            ;* [out] *
            STD_METHOD Next, :ptr IEnumRemoteDebugApplicationThreads, :ULONG, :ptr ptr IRemoteDebugApplicationThread, :ptr ULONG
            ;* [out] *
            DECLSPEC_XFGVIRT(IEnumRemoteDebugApplicationThreads, Skip)
            STD_METHOD Skip, :ptr IEnumRemoteDebugApplicationThreads, :ULONG
            ;* [in] *
            DECLSPEC_XFGVIRT(IEnumRemoteDebugApplicationThreads, Reset)
            STD_METHOD Reset, :ptr IEnumRemoteDebugApplicationThreads
            DECLSPEC_XFGVIRT(IEnumRemoteDebugApplicationThreads, Clone)
            STD_METHOD Clone, :ptr IEnumRemoteDebugApplicationThreads, :ptr ptr IEnumRemoteDebugApplicationThreads
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IEnumRemoteDebugApplicationThreadsVtbl ends
          IEnumRemoteDebugApplicationThreads struct
            lpVtbl POINTER ?
          IEnumRemoteDebugApplicationThreads ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* [call_as] *
        IEnumRemoteDebugApplicationThreads_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumRemoteDebugApplicationThreads, :ULONG, :ptr ptr IRemoteDebugApplicationThread, :ptr ULONG
        ;* [out] *
        IEnumRemoteDebugApplicationThreads_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        ;* __IEnumRemoteDebugApplicationThreads_INTERFACE_DEFINED__ *
      endif
      ifndef __IDebugFormatter_INTERFACE_DEFINED__
        __IDebugFormatter_INTERFACE_DEFINED__ equ <>
        ;* interface IDebugFormatter *
        ;* [local][unique][helpstring][uuid][object] *
        externdef IID_IDebugFormatter:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugFormatterVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugFormatterVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDebugFormatter, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugFormatter
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugFormatter
            DECLSPEC_XFGVIRT(IDebugFormatter, GetStringForVariant)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetStringForVariant, :ptr IDebugFormatter, :ptr VARIANT, :ULONG, :ptr BSTR
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugFormatter, GetVariantForString)
            ;* [in] *
            STD_METHOD GetVariantForString, :ptr IDebugFormatter, :LPCOLESTR, :ptr VARIANT
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugFormatter, GetStringForVarType)
            ;* [in] *
            ;* [in] *
            STD_METHOD GetStringForVarType, :ptr IDebugFormatter, :VARTYPE, :ptr TYPEDESC, :ptr BSTR
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IDebugFormatterVtbl ends
          IDebugFormatter struct
            lpVtbl POINTER ?
          IDebugFormatter ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IDebugFormatter_INTERFACE_DEFINED__ *
      endif
      ifndef __ISimpleConnectionPoint_INTERFACE_DEFINED__
        __ISimpleConnectionPoint_INTERFACE_DEFINED__ equ <>
        ;* interface ISimpleConnectionPoint *
        ;* [local][unique][helpstring][uuid][object] *
        externdef IID_ISimpleConnectionPoint:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          ISimpleConnectionPointVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <ISimpleConnectionPointVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr ISimpleConnectionPoint, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr ISimpleConnectionPoint
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr ISimpleConnectionPoint
            DECLSPEC_XFGVIRT(ISimpleConnectionPoint, GetEventCount)
            STD_METHOD GetEventCount, :ptr ISimpleConnectionPoint, :ptr ULONG
            ;* [out] *
            DECLSPEC_XFGVIRT(ISimpleConnectionPoint, DescribeEvents)
            ;* [in] *
            ;* [in] *
            ;* [length_is][size_is][out] *
            ;* [length_is][size_is][out] *
            STD_METHOD DescribeEvents, :ptr ISimpleConnectionPoint, :ULONG, :ULONG, :ptr DISPID, :ptr BSTR, :ptr ULONG
            ;* [out] *
            DECLSPEC_XFGVIRT(ISimpleConnectionPoint, Advise)
            ;* [in] *
            STD_METHOD Advise, :ptr ISimpleConnectionPoint, :ptr IDispatch, :ptr DWORD
            ;* [out] *
            DECLSPEC_XFGVIRT(ISimpleConnectionPoint, Unadvise)
            STD_METHOD Unadvise, :ptr ISimpleConnectionPoint, :DWORD
            ;* [in] *
            ??Interface equ <>
            END_INTERFACE
          ISimpleConnectionPointVtbl ends
          ISimpleConnectionPoint struct
            lpVtbl POINTER ?
          ISimpleConnectionPoint ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __ISimpleConnectionPoint_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_activdbg_0000_0056 *
      ;* [local] *
      externdef CLSID_DebugHelper:CLSID
      externdef __MIDL_itf_activdbg_0000_0056_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_activdbg_0000_0056_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IDebugHelper_INTERFACE_DEFINED__
        __IDebugHelper_INTERFACE_DEFINED__ equ <>
        ;* interface IDebugHelper *
        ;* [local][unique][helpstring][uuid][object] *
        externdef IID_IDebugHelper:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IDebugHelperVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IDebugHelperVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IDebugHelper, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IDebugHelper
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IDebugHelper
            DECLSPEC_XFGVIRT(IDebugHelper, CreatePropertyBrowser)
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD CreatePropertyBrowser, :ptr IDebugHelper, :ptr VARIANT, :LPCOLESTR, :ptr IDebugApplicationThread, :ptr ptr IDebugProperty
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugHelper, CreatePropertyBrowserEx)
            ;* [in] *
            ;* [in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD CreatePropertyBrowserEx, :ptr IDebugHelper, :ptr VARIANT, :LPCOLESTR, :ptr IDebugApplicationThread, :ptr IDebugFormatter, :ptr ptr IDebugProperty
            ;* [out] *
            DECLSPEC_XFGVIRT(IDebugHelper, CreateSimpleConnectionPoint)
            ;* [in] *
            STD_METHOD CreateSimpleConnectionPoint, :ptr IDebugHelper, :ptr IDispatch, :ptr ptr ISimpleConnectionPoint
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IDebugHelperVtbl ends
          IDebugHelper struct
            lpVtbl POINTER ?
          IDebugHelper ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IDebugHelper_INTERFACE_DEFINED__ *
      endif
      ifndef __IEnumDebugExpressionContexts_INTERFACE_DEFINED__
        __IEnumDebugExpressionContexts_INTERFACE_DEFINED__ equ <>
        ;* interface IEnumDebugExpressionContexts *
        ;* [unique][helpstring][uuid][object] *
        externdef IID_IEnumDebugExpressionContexts:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IEnumDebugExpressionContextsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEnumDebugExpressionContextsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IEnumDebugExpressionContexts, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IEnumDebugExpressionContexts
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IEnumDebugExpressionContexts
            DECLSPEC_XFGVIRT(IEnumDebugExpressionContexts, Next)
            ;* [local] *
            ;* [in] *
            ;* [out] *
            STD_METHOD Next, :ptr IEnumDebugExpressionContexts, :ULONG, :ptr ptr IDebugExpressionContext, :ptr ULONG
            ;* [out] *
            DECLSPEC_XFGVIRT(IEnumDebugExpressionContexts, Skip)
            STD_METHOD Skip, :ptr IEnumDebugExpressionContexts, :ULONG
            ;* [in] *
            DECLSPEC_XFGVIRT(IEnumDebugExpressionContexts, Reset)
            STD_METHOD Reset, :ptr IEnumDebugExpressionContexts
            DECLSPEC_XFGVIRT(IEnumDebugExpressionContexts, Clone)
            STD_METHOD Clone, :ptr IEnumDebugExpressionContexts, :ptr ptr IEnumDebugExpressionContexts
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IEnumDebugExpressionContextsVtbl ends
          IEnumDebugExpressionContexts struct
            lpVtbl POINTER ?
          IEnumDebugExpressionContexts ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* [call_as] *
        IEnumDebugExpressionContexts_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumDebugExpressionContexts, :ULONG, :ptr ptr IDebugExpressionContext, :ptr ULONG
        ;* [out] *
        IEnumDebugExpressionContexts_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        ;* __IEnumDebugExpressionContexts_INTERFACE_DEFINED__ *
      endif
      ifndef __IProvideExpressionContexts_INTERFACE_DEFINED__
        __IProvideExpressionContexts_INTERFACE_DEFINED__ equ <>
        ;* interface IProvideExpressionContexts *
        ;* [unique][uuid][object] *
        externdef IID_IProvideExpressionContexts:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IProvideExpressionContextsVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IProvideExpressionContextsVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IProvideExpressionContexts, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IProvideExpressionContexts
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IProvideExpressionContexts
            DECLSPEC_XFGVIRT(IProvideExpressionContexts, EnumExpressionContexts)
            STD_METHOD EnumExpressionContexts, :ptr IProvideExpressionContexts, :ptr ptr IEnumDebugExpressionContexts
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IProvideExpressionContextsVtbl ends
          IProvideExpressionContexts struct
            lpVtbl POINTER ?
          IProvideExpressionContexts ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IProvideExpressionContexts_INTERFACE_DEFINED__ *
      endif
      ifndef __ProcessDebugManagerLib_LIBRARY_DEFINED__
        __ProcessDebugManagerLib_LIBRARY_DEFINED__ equ <>
        ;* library ProcessDebugManagerLib *
        ;* [helpstring][version][uuid] *
        externdef CLSID_CDebugDocumentHelper:CLSID
        ifdef DEBUG
          MachineDebugManger equ <MachineDebugManager_DEBUG>
          CLSID_MachineDebugManager equ <CLSID_MachineDebugManager_DEBUG>
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
        ;* __ProcessDebugManagerLib_LIBRARY_DEFINED__ *
      endif
      ;* interface __MIDL_itf_activdbg_0000_0060 *
      ;* [local] *
    endif
    ; __ActivDbg_h
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  externdef __MIDL_itf_activdbg_0000_0060_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_activdbg_0000_0060_v0_0_s_ifspec:RPC_IF_HANDLE
  ;* Additional Prototypes for ALL interfaces *
  BSTR_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr BSTR
  BSTR_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BSTR
  BSTR_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr BSTR
  BSTR_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BSTR
  ;* [local] *
  IEnumDebugCodeContexts_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumDebugCodeContexts, :ULONG, :ptr ptr IDebugCodeContext, :ptr ULONG
  ;* [out] *
  ;* [call_as] *
  IEnumDebugCodeContexts_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumDebugCodeContexts, :ULONG, :ptr ptr IDebugCodeContext, :ptr ULONG
  ;* [out] *
  ;* [local] *
  IEnumDebugStackFrames_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumDebugStackFrames, :ULONG, :ptr DebugStackFrameDescriptor, :ptr ULONG
  ;* [out] *
  ;* [call_as] *
  IEnumDebugStackFrames_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumDebugStackFrames, :ULONG, :ptr DebugStackFrameDescriptor, :ptr ULONG
  ;* [out] *
  ;* [local] *
  IEnumDebugStackFrames64_Next64_Proxy proto WIN_STD_CALL_CONV :ptr IEnumDebugStackFrames64, :ULONG, :ptr DebugStackFrameDescriptor64, :ptr ULONG
  ;* [out] *
  ;* [call_as] *
  IEnumDebugStackFrames64_Next64_Stub proto WIN_STD_CALL_CONV :ptr IEnumDebugStackFrames64, :ULONG, :ptr DebugStackFrameDescriptor64, :ptr ULONG
  ;* [out] *
  ;* [local] *
  IEnumDebugApplicationNodes_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumDebugApplicationNodes, :ULONG, :ptr ptr IDebugApplicationNode, :ptr ULONG
  ;* [out] *
  ;* [call_as] *
  IEnumDebugApplicationNodes_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumDebugApplicationNodes, :ULONG, :ptr ptr IDebugApplicationNode, :ptr ULONG
  ;* [out] *
  ;* [local] *
  IEnumRemoteDebugApplications_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumRemoteDebugApplications, :ULONG, :ptr ptr IRemoteDebugApplication, :ptr ULONG
  ;* [out] *
  ;* [call_as] *
  IEnumRemoteDebugApplications_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumRemoteDebugApplications, :ULONG, :ptr ptr IRemoteDebugApplication, :ptr ULONG
  ;* [out] *
  ;* [local] *
  IEnumRemoteDebugApplicationThreads_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumRemoteDebugApplicationThreads, :ULONG, :ptr ptr IRemoteDebugApplicationThread, :ptr ULONG
  ;* [out] *
  ;* [call_as] *
  IEnumRemoteDebugApplicationThreads_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumRemoteDebugApplicationThreads, :ULONG, :ptr ptr IRemoteDebugApplicationThread, :ptr ULONG
  ;* [out] *
  ;* [local] *
  IEnumDebugExpressionContexts_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumDebugExpressionContexts, :ULONG, :ptr ptr IDebugExpressionContext, :ptr ULONG
  ;* [out] *
  ;* [call_as] *
  IEnumDebugExpressionContexts_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumDebugExpressionContexts, :ULONG, :ptr ptr IDebugExpressionContext, :ptr ULONG
  ;* [out] *
  ;* end of Additional Prototypes *
  ifdef __cplusplus
    ;[...]
  endif
endif
