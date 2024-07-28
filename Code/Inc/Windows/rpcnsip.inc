;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\rpcnsip.h', last modified: 19/04/2018 10:43
;Creation parameters: 

include winapifamily.inc
ifndef __RPCNSIP_H__
  __RPCNSIP_H__ equ <>
  if _MSC_VER gt 1000
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    RPC_IMPORT_CONTEXT_P struct
      LookupContext RPC_NS_HANDLE ?
      ProposedHandle RPC_BINDING_HANDLE ?
      Bindings POINTER ?
    RPC_IMPORT_CONTEXT_P ends

    PRPC_IMPORT_CONTEXT_P typedef ptr RPC_IMPORT_CONTEXT_P
    
    @DefProto DllImport, I_RpcNsGetBuffer, WIN_STD_CALL_CONV,, <:PRPC_MESSAGE>, 4
    @DefProto DllImport, I_RpcNsSendReceive, WIN_STD_CALL_CONV,, <:PRPC_MESSAGE, :ptr RPC_BINDING_HANDLE>, 8
    @DefProto DllImport, I_RpcNsRaiseException, WIN_STD_CALL_CONV,, <:PRPC_MESSAGE, :RPC_STATUS>, 8
    @DefProto DllImport, I_RpcReBindBuffer, WIN_STD_CALL_CONV,, <:PRPC_MESSAGE>, 4
    @DefProto DllImport, I_NsServerBindSearch, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, I_NsClientBindSearch, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, I_NsClientBindDone, WIN_STD_CALL_CONV,, <>, 0
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

