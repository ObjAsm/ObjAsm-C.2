;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\rpcnsip.h
;             Created on (UTC) 06/04/2024 06:15:57
;             Last modified on (UTC) 16/12/2023 11:07:16

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
