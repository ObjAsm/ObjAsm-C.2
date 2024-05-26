;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\rpcdce.h
;             Created on (UTC) 22/05/2024 17:57:08
;             Last modified on (UTC) 08/01/2024 17:04:22

include winapifamily.inc
ifndef __RPCDCE_H__
  __RPCDCE_H__ equ <>
  if _MSC_VER gt 1000
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if _MSC_VER ge 1200
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    ifndef IN_
      IN_ equ <>
    endif
    ifndef OUT_
      OUT_ equ <>
    endif
    ifndef OPTIONAL
      OPTIONAL equ <>
    endif
    ifndef DECLSPEC_NORETURN
      if (_MSC_VER ge 1200) and  not Defined(MIDL_PASS)
        DECLSPEC_NORETURN equ <__declspec(noreturn)>
      else
        DECLSPEC_NORETURN equ <>
      endif
    endif
    include specstrings.inc
    RPC_CSTR typedef ptr BYTE
    if Defined(RPC_USE_NATIVE_WCHAR) and Defined(_NATIVE_WCHAR_T_DEFINED)
      RPC_WSTR typedef ptr wchar_t
      RPC_CWSTR typedef ptr wchar_t
    else
      RPC_WSTR typedef ptr WORD
      RPC_CWSTR typedef ptr WORD
    endif
    RPC_BINDING_HANDLE typedef I_RPC_HANDLE
    handle_t typedef RPC_BINDING_HANDLE
    rpc_binding_handle_t equ <RPC_BINDING_HANDLE>
    ifndef GUID_DEFINED
      include guiddef.inc
    endif
    ifndef UUID_DEFINED
      UUID_DEFINED equ <>
      UUID typedef GUID
      ifndef uuid_t
        uuid_t equ <UUID>
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    RPC_BINDING_VECTOR struct
      Count DWORD ?
      BindingH RPC_BINDING_HANDLE 1 dup (?)
    RPC_BINDING_VECTOR ends
    _RPC_BINDING_VECTOR typedef RPC_BINDING_VECTOR
    ifndef rpc_binding_vector_t
      rpc_binding_vector_t equ <RPC_BINDING_VECTOR>
    endif
    UUID_VECTOR struct
      Count DWORD ?
      Uuid POINTER 1 dup (?)
    UUID_VECTOR ends
    _UUID_VECTOR typedef UUID_VECTOR
    ifndef uuid_vector_t
      uuid_vector_t equ <UUID_VECTOR>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    RPC_IF_HANDLE typedef ptr
    ifndef IFID_DEFINED
      IFID_DEFINED equ <>
      RPC_IF_ID struct
        Uuid UUID <>
        VersMajor WORD ?
        VersMinor WORD ?
      RPC_IF_ID ends
      _RPC_IF_ID typedef RPC_IF_ID
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    RPC_C_BINDING_INFINITE_TIMEOUT equ 10
    RPC_C_BINDING_MIN_TIMEOUT equ 0
    RPC_C_BINDING_DEFAULT_TIMEOUT equ 5
    RPC_C_BINDING_MAX_TIMEOUT equ 9
    RPC_C_CANCEL_INFINITE_TIMEOUT equ -1
    RPC_C_LISTEN_MAX_CALLS_DEFAULT equ 1234
    RPC_C_PROTSEQ_MAX_REQS_DEFAULT equ 10
    RPC_C_BIND_TO_ALL_NICS equ 1
    RPC_C_USE_INTERNET_PORT equ 1h
    RPC_C_USE_INTRANET_PORT equ 2h
    RPC_C_DONT_FAIL equ 4h
    RPC_C_RPCHTTP_USE_LOAD_BALANCE equ 8h
    RPC_C_TRY_ENFORCE_MAX_CALLS equ 10h
    if (NTDDI_VERSION lt NTDDI_VISTA)
      RPC_C_MQ_TEMPORARY equ 0000h
      RPC_C_MQ_PERMANENT equ 0001h
      RPC_C_MQ_CLEAR_ON_OPEN equ 0002h
      RPC_C_MQ_USE_EXISTING_SECURITY equ 0004h
      RPC_C_MQ_AUTHN_LEVEL_NONE equ 0000h
      RPC_C_MQ_AUTHN_LEVEL_PKT_INTEGRITY equ 0008h
      RPC_C_MQ_AUTHN_LEVEL_PKT_PRIVACY equ 0010h
      RPC_C_MQ_EXPRESS equ 0
      RPC_C_MQ_RECOVERABLE equ 1
      RPC_C_MQ_JOURNAL_NONE equ 0
      RPC_C_MQ_JOURNAL_DEADLETTER equ 1
      RPC_C_MQ_JOURNAL_ALWAYS equ 2
      RPC_C_OPT_MQ_DELIVERY equ 1
      RPC_C_OPT_MQ_PRIORITY equ 2
      RPC_C_OPT_MQ_JOURNAL equ 3
      RPC_C_OPT_MQ_ACKNOWLEDGE equ 4
      RPC_C_OPT_MQ_AUTHN_SERVICE equ 5
      RPC_C_OPT_MQ_AUTHN_LEVEL equ 6
      RPC_C_OPT_MQ_TIME_TO_REACH_QUEUE equ 7
      RPC_C_OPT_MQ_TIME_TO_BE_RECEIVED equ 8
    endif
    RPC_C_OPT_BINDING_NONCAUSAL equ 9
    RPC_C_OPT_SECURITY_CALLBACK equ 10
    RPC_C_OPT_UNIQUE_BINDING equ 11
    if (NTDDI_VERSION le NTDDI_WIN2K)
      RPC_C_OPT_MAX_OPTIONS equ 12
    elseif (NTDDI_VERSION le NTDDI_WS03)
      RPC_C_OPT_CALL_TIMEOUT equ 12
      RPC_C_OPT_DONT_LINGER equ 13
      RPC_C_OPT_MAX_OPTIONS equ 14
    else
      RPC_C_OPT_TRANS_SEND_BUFFER_SIZE equ 5
      RPC_C_OPT_CALL_TIMEOUT equ 12
      RPC_C_OPT_DONT_LINGER equ 13
      RPC_C_OPT_TRUST_PEER equ 14
      RPC_C_OPT_ASYNC_BLOCK equ 15
      RPC_C_OPT_OPTIMIZE_TIME equ 16
      RPC_C_OPT_MAX_OPTIONS equ 17
    endif
    RPC_C_FULL_CERT_CHAIN equ 0001h
    ifdef RPC_UNICODE_SUPPORTED
      RPC_PROTSEQ_VECTORA struct
        Count DWORD ?
        Protseq POINTER 1 dup (?)
      RPC_PROTSEQ_VECTORA ends
      _RPC_PROTSEQ_VECTORA typedef RPC_PROTSEQ_VECTORA
      RPC_PROTSEQ_VECTORW struct
        Count DWORD ?
        Protseq POINTER 1 dup (?)
      RPC_PROTSEQ_VECTORW ends
      _RPC_PROTSEQ_VECTORW typedef RPC_PROTSEQ_VECTORW
      ifdef UNICODE
        RPC_PROTSEQ_VECTOR equ <RPC_PROTSEQ_VECTORW>
      else
        RPC_PROTSEQ_VECTOR equ <RPC_PROTSEQ_VECTORA>
      endif
    else
      RPC_PROTSEQ_VECTOR struct
        Count DWORD ?
        Protseq POINTER 1 dup (?)
      RPC_PROTSEQ_VECTOR ends
      _RPC_PROTSEQ_VECTOR typedef RPC_PROTSEQ_VECTOR
    endif
    RPC_POLICY struct
      Length_ DWORD ?
      EndpointFlags DWORD ?
      NICFlags DWORD ?
    RPC_POLICY ends
    _RPC_POLICY typedef RPC_POLICY
    PRPC_POLICY typedef ptr RPC_POLICY
    RPC_OBJECT_INQ_FN typedef proto :ptr UUID, :ptr UUID, :ptr RPC_STATUS
    RPC_IF_CALLBACK_FN typedef proto :RPC_IF_HANDLE, :ptr
    RPC_SECURITY_CALLBACK_FN typedef proto :ptr
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    RPC_MGR_EPV equ <void>
    RPC_STATS_VECTOR struct
      Count DWORD ?
      Stats DWORD 1 dup (?)
    RPC_STATS_VECTOR ends
    RPC_C_STATS_CALLS_IN equ 0
    RPC_C_STATS_CALLS_OUT equ 1
    RPC_C_STATS_PKTS_IN equ 2
    RPC_C_STATS_PKTS_OUT equ 3
    RPC_IF_ID_VECTOR struct
      Count DWORD ?
      IfId POINTER 1 dup (?)
    RPC_IF_ID_VECTOR ends
    @DefProto DllImport, RpcBindingCopy, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr RPC_BINDING_HANDLE>, 8
    @DefProto DllImport, RpcBindingFree, WIN_STD_CALL_CONV,, <:ptr RPC_BINDING_HANDLE>, 4
    @DefProto DllImport, RpcBindingSetOption, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :DWORD, :ULONG_PTR>, 12
    @DefProto DllImport, RpcBindingInqOption, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :DWORD, :ptr ULONG_PTR>, 12
    if  not Defined(_KRPCENV_)
      ifdef RPC_UNICODE_SUPPORTED
        @DefProto DllImport, RpcBindingFromStringBindingA, WIN_STD_CALL_CONV,, <:RPC_CSTR, :ptr RPC_BINDING_HANDLE>, 8
        @DefProto DllImport, RpcBindingFromStringBindingW, WIN_STD_CALL_CONV,, <:RPC_WSTR, :ptr RPC_BINDING_HANDLE>, 8
        ifdef UNICODE
          RpcBindingFromStringBinding equ <RpcBindingFromStringBindingW>
        else
          RpcBindingFromStringBinding equ <RpcBindingFromStringBindingA>
        endif
      else
        @DefProto DllImport, RpcBindingFromStringBinding, WIN_STD_CALL_CONV,, <:RPC_CSTR, :ptr RPC_BINDING_HANDLE>, 8
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, RpcSsGetContextBinding, WIN_STD_CALL_CONV,, <:ptr, :ptr RPC_BINDING_HANDLE>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, RpcBindingInqMaxCalls, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr DWORD>, 8
    @DefProto DllImport, RpcBindingInqObject, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr UUID>, 8
    @DefProto DllImport, RpcBindingReset, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE>, 4
    @DefProto DllImport, RpcBindingSetObject, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr UUID>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, RpcMgmtInqDefaultProtectLevel, WIN_STD_CALL_CONV,, <:DWORD, :ptr DWORD>, 8
  endif
  ifdef RPC_UNICODE_SUPPORTED
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, RpcBindingToStringBindingA, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr RPC_CSTR>, 8
      @DefProto DllImport, RpcBindingToStringBindingW, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr RPC_WSTR>, 8
      ifdef UNICODE
        RpcBindingToStringBinding equ <RpcBindingToStringBindingW>
      else
        RpcBindingToStringBinding equ <RpcBindingToStringBindingA>
      endif
    endif
  else
    @DefProto DllImport, RpcBindingToStringBinding, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr RPC_CSTR>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, RpcBindingVectorFree, WIN_STD_CALL_CONV,, <:ptr ptr RPC_BINDING_VECTOR>, 4
  endif
  if  not Defined(_KRPCENV_)
    ifdef RPC_UNICODE_SUPPORTED
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        @DefProto DllImport, RpcStringBindingComposeA, WIN_STD_CALL_CONV,, <:RPC_CSTR, :RPC_CSTR, :RPC_CSTR, :RPC_CSTR, :RPC_CSTR, :ptr RPC_CSTR>, 24
        @DefProto DllImport, RpcStringBindingComposeW, WIN_STD_CALL_CONV,, <:RPC_WSTR, :RPC_WSTR, :RPC_WSTR, :RPC_WSTR, :RPC_WSTR, :ptr RPC_WSTR>, 24
        ifdef UNICODE
          RpcStringBindingCompose equ <RpcStringBindingComposeW>
        else
          RpcStringBindingCompose equ <RpcStringBindingComposeA>
        endif
      endif
    else
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
        @DefProto DllImport, RpcStringBindingCompose, WIN_STD_CALL_CONV,, <:RPC_CSTR, :RPC_CSTR, :RPC_CSTR, :RPC_CSTR, :RPC_CSTR, :ptr RPC_CSTR>, 24
      endif
    endif
    ifdef RPC_UNICODE_SUPPORTED
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        @DefProto DllImport, RpcStringBindingParseA, WIN_STD_CALL_CONV,, <:RPC_CSTR, :ptr RPC_CSTR, :ptr RPC_CSTR, :ptr RPC_CSTR, :ptr RPC_CSTR, :ptr RPC_CSTR>, 24
        @DefProto DllImport, RpcStringBindingParseW, WIN_STD_CALL_CONV,, <:RPC_WSTR, :ptr RPC_WSTR, :ptr RPC_WSTR, :ptr RPC_WSTR, :ptr RPC_WSTR, :ptr RPC_WSTR>, 24
        ifdef UNICODE
          RpcStringBindingParse equ <RpcStringBindingParseW>
        else
          RpcStringBindingParse equ <RpcStringBindingParseA>
        endif
      endif
    else
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
        @DefProto DllImport, RpcStringBindingParse, WIN_STD_CALL_CONV,, <:RPC_CSTR, :ptr RPC_CSTR, :ptr RPC_CSTR, :ptr RPC_CSTR, :ptr RPC_CSTR, :ptr RPC_CSTR>, 24
      endif
    endif
  endif
  ifdef RPC_UNICODE_SUPPORTED
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, RpcStringFreeA, WIN_STD_CALL_CONV,, <:ptr RPC_CSTR>, 4
      @DefProto DllImport, RpcStringFreeW, WIN_STD_CALL_CONV,, <:ptr RPC_WSTR>, 4
      ifdef UNICODE
        RpcStringFree equ <RpcStringFreeW>
      else
        RpcStringFree equ <RpcStringFreeA>
      endif
    endif
  else
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, RpcStringFree, WIN_STD_CALL_CONV,, <:ptr RPC_CSTR>, 4
    endif
  endif
  @DefProto DllImport, RpcIfInqId, WIN_STD_CALL_CONV,, <:RPC_IF_HANDLE, :ptr RPC_IF_ID>, 8
  ifdef RPC_UNICODE_SUPPORTED
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, RpcNetworkIsProtseqValidA, WIN_STD_CALL_CONV,, <:RPC_CSTR>, 4
      @DefProto DllImport, RpcNetworkIsProtseqValidW, WIN_STD_CALL_CONV,, <:RPC_WSTR>, 4
      ifdef UNICODE
        RpcNetworkIsProtseqValid equ <RpcNetworkIsProtseqValidW>
      else
        RpcNetworkIsProtseqValid equ <RpcNetworkIsProtseqValidA>
      endif
    endif
  else
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, RpcNetworkIsProtseqValid, WIN_STD_CALL_CONV,, <:RPC_CSTR>, 4
    endif
  endif
  @DefProto DllImport, RpcMgmtInqComTimeout, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr DWORD>, 8
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, RpcMgmtSetComTimeout, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :DWORD>, 8
    @DefProto DllImport, RpcMgmtSetCancelTimeout, WIN_STD_CALL_CONV,, <:SDWORD>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    ifdef RPC_UNICODE_SUPPORTED
      @DefProto DllImport, RpcNetworkInqProtseqsA, WIN_STD_CALL_CONV,, <:ptr ptr RPC_PROTSEQ_VECTORA>, 4
      @DefProto DllImport, RpcNetworkInqProtseqsW, WIN_STD_CALL_CONV,, <:ptr ptr RPC_PROTSEQ_VECTORW>, 4
      ifdef UNICODE
        RpcNetworkInqProtseqs equ <RpcNetworkInqProtseqsW>
      else
        RpcNetworkInqProtseqs equ <RpcNetworkInqProtseqsA>
      endif
    else
      @DefProto DllImport, RpcNetworkInqProtseqs, WIN_STD_CALL_CONV,, <:ptr ptr RPC_PROTSEQ_VECTOR>, 4
    endif
    @DefProto DllImport, RpcObjectInqType, WIN_STD_CALL_CONV,, <:ptr UUID, :ptr UUID>, 8
    @DefProto DllImport, RpcObjectSetInqFn, WIN_STD_CALL_CONV,, <:ptr RPC_OBJECT_INQ_FN>, 4
    @DefProto DllImport, RpcObjectSetType, WIN_STD_CALL_CONV,, <:ptr UUID, :ptr UUID>, 8
    ifdef RPC_UNICODE_SUPPORTED
      @DefProto DllImport, RpcProtseqVectorFreeA, WIN_STD_CALL_CONV,, <:ptr ptr RPC_PROTSEQ_VECTORA>, 4
      @DefProto DllImport, RpcProtseqVectorFreeW, WIN_STD_CALL_CONV,, <:ptr ptr RPC_PROTSEQ_VECTORW>, 4
      ifdef UNICODE
        RpcProtseqVectorFree equ <RpcProtseqVectorFreeW>
      else
        RpcProtseqVectorFree equ <RpcProtseqVectorFreeA>
      endif
    else
      @DefProto DllImport, RpcProtseqVectorFree, WIN_STD_CALL_CONV,, <:ptr ptr RPC_PROTSEQ_VECTOR>, 4
    endif
    @DefProto DllImport, RpcServerInqBindings, WIN_STD_CALL_CONV,, <:ptr ptr RPC_BINDING_VECTOR>, 4
    @DefProto DllImport, RpcServerInqBindingsEx, WIN_STD_CALL_CONV,, <:ptr, :ptr ptr RPC_BINDING_VECTOR>, 8
    @DefProto DllImport, RpcServerInqIf, WIN_STD_CALL_CONV,, <:RPC_IF_HANDLE, :ptr UUID, :ptr ptr RPC_MGR_EPV>, 12
    @DefProto DllImport, RpcServerListen, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :DWORD>, 12
    @DefProto DllImport, RpcServerRegisterIf, WIN_STD_CALL_CONV,, <:RPC_IF_HANDLE, :ptr UUID, :ptr RPC_MGR_EPV>, 12
    @DefProto DllImport, RpcServerRegisterIfEx, WIN_STD_CALL_CONV,, <:RPC_IF_HANDLE, :ptr UUID, :ptr RPC_MGR_EPV, :DWORD, :DWORD, :ptr RPC_IF_CALLBACK_FN>, 24
    @DefProto DllImport, RpcServerRegisterIf2, WIN_STD_CALL_CONV,, <:RPC_IF_HANDLE, :ptr UUID, :ptr RPC_MGR_EPV, :DWORD, :DWORD, :DWORD, :ptr RPC_IF_CALLBACK_FN>, 28
    if (NTDDI_VERSION ge NTDDI_WIN8)
      @DefProto DllImport, RpcServerRegisterIf3, WIN_STD_CALL_CONV,, <:RPC_IF_HANDLE, :ptr UUID, :ptr RPC_MGR_EPV, :DWORD, :DWORD, :DWORD, :ptr RPC_IF_CALLBACK_FN, :ptr>, 32
    endif
    @DefProto DllImport, RpcServerUnregisterIf, WIN_STD_CALL_CONV,, <:RPC_IF_HANDLE, :ptr UUID, :DWORD>, 12
    if (NTDDI_VERSION ge NTDDI_WINXP)
      @DefProto DllImport, RpcServerUnregisterIfEx, WIN_STD_CALL_CONV,, <:RPC_IF_HANDLE, :ptr UUID, :SDWORD>, 12
    endif
    @DefProto DllImport, RpcServerUseAllProtseqs, WIN_STD_CALL_CONV,, <:DWORD, :ptr>, 8
    @DefProto DllImport, RpcServerUseAllProtseqsEx, WIN_STD_CALL_CONV,, <:DWORD, :ptr, :PRPC_POLICY>, 12
    @DefProto DllImport, RpcServerUseAllProtseqsIf, WIN_STD_CALL_CONV,, <:DWORD, :RPC_IF_HANDLE, :ptr>, 12
    @DefProto DllImport, RpcServerUseAllProtseqsIfEx, WIN_STD_CALL_CONV,, <:DWORD, :RPC_IF_HANDLE, :ptr, :PRPC_POLICY>, 16
    ifdef RPC_UNICODE_SUPPORTED
      @DefProto DllImport, RpcServerUseProtseqA, WIN_STD_CALL_CONV,, <:RPC_CSTR, :DWORD, :ptr>, 12
      @DefProto DllImport, RpcServerUseProtseqExA, WIN_STD_CALL_CONV,, <:RPC_CSTR, :DWORD, :ptr, :PRPC_POLICY>, 16
      @DefProto DllImport, RpcServerUseProtseqW, WIN_STD_CALL_CONV,, <:RPC_WSTR, :DWORD, :ptr>, 12
      @DefProto DllImport, RpcServerUseProtseqExW, WIN_STD_CALL_CONV,, <:RPC_WSTR, :DWORD, :ptr, :PRPC_POLICY>, 16
      ifdef UNICODE
        RpcServerUseProtseq equ <RpcServerUseProtseqW>
        RpcServerUseProtseqEx equ <RpcServerUseProtseqExW>
      else
        RpcServerUseProtseq equ <RpcServerUseProtseqA>
        RpcServerUseProtseqEx equ <RpcServerUseProtseqExA>
      endif
    else
      @DefProto DllImport, RpcServerUseProtseq, WIN_STD_CALL_CONV,, <:RPC_CSTR, :DWORD, :ptr>, 12
      @DefProto DllImport, RpcServerUseProtseqEx, WIN_STD_CALL_CONV,, <:RPC_CSTR, :DWORD, :ptr, :PRPC_POLICY>, 16
    endif
    ifdef RPC_UNICODE_SUPPORTED
      @DefProto DllImport, RpcServerUseProtseqEpA, WIN_STD_CALL_CONV,, <:RPC_CSTR, :DWORD, :RPC_CSTR, :ptr>, 16
      @DefProto DllImport, RpcServerUseProtseqEpExA, WIN_STD_CALL_CONV,, <:RPC_CSTR, :DWORD, :RPC_CSTR, :ptr, :PRPC_POLICY>, 20
      @DefProto DllImport, RpcServerUseProtseqEpW, WIN_STD_CALL_CONV,, <:RPC_WSTR, :DWORD, :RPC_WSTR, :ptr>, 16
      @DefProto DllImport, RpcServerUseProtseqEpExW, WIN_STD_CALL_CONV,, <:RPC_WSTR, :DWORD, :RPC_WSTR, :ptr, :PRPC_POLICY>, 20
      ifdef UNICODE
        RpcServerUseProtseqEp equ <RpcServerUseProtseqEpW>
        RpcServerUseProtseqEpEx equ <RpcServerUseProtseqEpExW>
      else
        RpcServerUseProtseqEp equ <RpcServerUseProtseqEpA>
        RpcServerUseProtseqEpEx equ <RpcServerUseProtseqEpExA>
      endif
    else
      @DefProto DllImport, RpcServerUseProtseqEp, WIN_STD_CALL_CONV,, <:RPC_CSTR, :DWORD, :RPC_CSTR, :ptr>, 16
      @DefProto DllImport, RpcServerUseProtseqEpEx, WIN_STD_CALL_CONV,, <:RPC_WSTR, :DWORD, :RPC_WSTR, :ptr, :PRPC_POLICY>, 20
    endif
    ifdef RPC_UNICODE_SUPPORTED
      @DefProto DllImport, RpcServerUseProtseqIfA, WIN_STD_CALL_CONV,, <:RPC_CSTR, :DWORD, :RPC_IF_HANDLE, :ptr>, 16
      @DefProto DllImport, RpcServerUseProtseqIfExA, WIN_STD_CALL_CONV,, <:RPC_CSTR, :DWORD, :RPC_IF_HANDLE, :ptr, :PRPC_POLICY>, 20
      @DefProto DllImport, RpcServerUseProtseqIfW, WIN_STD_CALL_CONV,, <:RPC_WSTR, :DWORD, :RPC_IF_HANDLE, :ptr>, 16
      @DefProto DllImport, RpcServerUseProtseqIfExW, WIN_STD_CALL_CONV,, <:RPC_WSTR, :DWORD, :RPC_IF_HANDLE, :ptr, :PRPC_POLICY>, 20
      ifdef UNICODE
        RpcServerUseProtseqIf equ <RpcServerUseProtseqIfW>
        RpcServerUseProtseqIfEx equ <RpcServerUseProtseqIfExW>
      else
        RpcServerUseProtseqIf equ <RpcServerUseProtseqIfA>
        RpcServerUseProtseqIfEx equ <RpcServerUseProtseqIfExA>
      endif
    else
      @DefProto DllImport, RpcServerUseProtseqIf, WIN_STD_CALL_CONV,, <:RPC_CSTR, :DWORD, :RPC_IF_HANDLE, :ptr>, 16
      @DefProto DllImport, RpcServerUseProtseqIfEx, WIN_STD_CALL_CONV,, <:RPC_CSTR, :DWORD, :RPC_IF_HANDLE, :ptr, :PRPC_POLICY>, 20
    endif
    @DefProto DllImport, RpcServerYield, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, RpcMgmtStatsVectorFree, WIN_STD_CALL_CONV,, <:ptr ptr RPC_STATS_VECTOR>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, RpcMgmtInqStats, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr ptr RPC_STATS_VECTOR>, 8
    @DefProto DllImport, RpcMgmtIsServerListening, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, RpcMgmtStopServerListening, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE>, 4
    @DefProto DllImport, RpcMgmtWaitServerListen, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, RpcMgmtSetServerStackSize, WIN_STD_CALL_CONV,, <:DWORD>, 4
    @DefProto DllImport, RpcSsDontSerializeContext, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, RpcMgmtEnableIdleCleanup, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, RpcMgmtInqIfIds, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr ptr RPC_IF_ID_VECTOR>, 8
    @DefProto DllImport, RpcIfIdVectorFree, WIN_STD_CALL_CONV,, <:ptr ptr RPC_IF_ID_VECTOR>, 4
  endif
  ifdef RPC_UNICODE_SUPPORTED
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, RpcMgmtInqServerPrincNameA, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :DWORD, :ptr RPC_CSTR>, 12
      @DefProto DllImport, RpcMgmtInqServerPrincNameW, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :DWORD, :ptr RPC_WSTR>, 12
      ifdef UNICODE
        RpcMgmtInqServerPrincName equ <RpcMgmtInqServerPrincNameW>
      else
        RpcMgmtInqServerPrincName equ <RpcMgmtInqServerPrincNameA>
      endif
    endif
  else
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, RpcMgmtInqServerPrincName, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :DWORD, :ptr RPC_WSTR>, 12
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    ifdef RPC_UNICODE_SUPPORTED
      @DefProto DllImport, RpcServerInqDefaultPrincNameA, WIN_STD_CALL_CONV,, <:DWORD, :ptr RPC_CSTR>, 8
      @DefProto DllImport, RpcServerInqDefaultPrincNameW, WIN_STD_CALL_CONV,, <:DWORD, :ptr RPC_WSTR>, 8
      ifdef UNICODE
        RpcServerInqDefaultPrincName equ <RpcServerInqDefaultPrincNameW>
      else
        RpcServerInqDefaultPrincName equ <RpcServerInqDefaultPrincNameA>
      endif
    else
      @DefProto DllImport, RpcServerInqDefaultPrincName, WIN_STD_CALL_CONV,, <:DWORD, :ptr RPC_WSTR>, 8
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, RpcEpResolveBinding, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :RPC_IF_HANDLE>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    ifdef RPC_UNICODE_SUPPORTED
      @DefProto DllImport, RpcNsBindingInqEntryNameA, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :DWORD, :ptr RPC_CSTR>, 12
      @DefProto DllImport, RpcNsBindingInqEntryNameW, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :DWORD, :ptr RPC_WSTR>, 12
      ifdef UNICODE
        RpcNsBindingInqEntryName equ <RpcNsBindingInqEntryNameW>
      else
        RpcNsBindingInqEntryName equ <RpcNsBindingInqEntryNameA>
      endif
    else
      @DefProto DllImport, RpcNsBindingInqEntryName, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :DWORD, :ptr RPC_CSTR>, 12
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    RPC_AUTH_IDENTITY_HANDLE typedef ptr
    RPC_AUTHZ_HANDLE typedef ptr
    RPC_C_AUTHN_LEVEL_DEFAULT equ 0
    RPC_C_AUTHN_LEVEL_NONE equ 1
    RPC_C_AUTHN_LEVEL_CONNECT equ 2
    RPC_C_AUTHN_LEVEL_CALL equ 3
    RPC_C_AUTHN_LEVEL_PKT equ 4
    RPC_C_AUTHN_LEVEL_PKT_INTEGRITY equ 5
    RPC_C_AUTHN_LEVEL_PKT_PRIVACY equ 6
    RPC_C_IMP_LEVEL_DEFAULT equ 0
    RPC_C_IMP_LEVEL_ANONYMOUS equ 1
    RPC_C_IMP_LEVEL_IDENTIFY equ 2
    RPC_C_IMP_LEVEL_IMPERSONATE equ 3
    RPC_C_IMP_LEVEL_DELEGATE equ 4
    RPC_C_QOS_IDENTITY_STATIC equ 0
    RPC_C_QOS_IDENTITY_DYNAMIC equ 1
    RPC_C_QOS_CAPABILITIES_DEFAULT equ 0h
    RPC_C_QOS_CAPABILITIES_MUTUAL_AUTH equ 1h
    RPC_C_QOS_CAPABILITIES_MAKE_FULLSIC equ 2h
    RPC_C_QOS_CAPABILITIES_ANY_AUTHORITY equ 4h
    if (NTDDI_VERSION ge NTDDI_WS03)
      RPC_C_QOS_CAPABILITIES_IGNORE_DELEGATE_FAILURE equ 8h
      RPC_C_QOS_CAPABILITIES_LOCAL_MA_HINT equ 10h
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      RPC_C_QOS_CAPABILITIES_SCHANNEL_FULL_AUTH_IDENTITY equ 20h
    endif
    RPC_C_PROTECT_LEVEL_DEFAULT equ <(RPC_C_AUTHN_LEVEL_DEFAULT)>
    RPC_C_PROTECT_LEVEL_NONE equ <(RPC_C_AUTHN_LEVEL_NONE)>
    RPC_C_PROTECT_LEVEL_CONNECT equ <(RPC_C_AUTHN_LEVEL_CONNECT)>
    RPC_C_PROTECT_LEVEL_CALL equ <(RPC_C_AUTHN_LEVEL_CALL)>
    RPC_C_PROTECT_LEVEL_PKT equ <(RPC_C_AUTHN_LEVEL_PKT)>
    RPC_C_PROTECT_LEVEL_PKT_INTEGRITY equ <(RPC_C_AUTHN_LEVEL_PKT_INTEGRITY)>
    RPC_C_PROTECT_LEVEL_PKT_PRIVACY equ <(RPC_C_AUTHN_LEVEL_PKT_PRIVACY)>
    RPC_C_AUTHN_NONE equ 0
    RPC_C_AUTHN_DCE_PRIVATE equ 1
    RPC_C_AUTHN_DCE_PUBLIC equ 2
    RPC_C_AUTHN_DEC_PUBLIC equ 4
    RPC_C_AUTHN_GSS_NEGOTIATE equ 9
    RPC_C_AUTHN_WINNT equ 10
    RPC_C_AUTHN_GSS_SCHANNEL equ 14
    RPC_C_AUTHN_GSS_KERBEROS equ 16
    RPC_C_AUTHN_DPA equ 17
    RPC_C_AUTHN_MSN equ 18
    if (NTDDI_VERSION ge NTDDI_WINXP)
      RPC_C_AUTHN_DIGEST equ 21
    endif
    if (NTDDI_VERSION ge NTDDI_WIN7)
      RPC_C_AUTHN_KERNEL equ 20
    endif
    RPC_C_AUTHN_NEGO_EXTENDER equ 30
    RPC_C_AUTHN_PKU2U equ 31
    RPC_C_AUTHN_LIVE_SSP equ 32
    RPC_C_AUTHN_LIVEXP_SSP equ 35
    RPC_C_AUTHN_CLOUD_AP equ 36
    RPC_C_AUTHN_MSONLINE equ 82
    RPC_C_AUTHN_MQ equ 100
    RPC_C_AUTHN_DEFAULT equ 0FFFFFFFFh
    RPC_C_NO_CREDENTIALS equ <((RPC_AUTH_IDENTITY_HANDLE) MAXUINT_PTR)>
    RPC_C_SECURITY_QOS_VERSION equ 1
    RPC_C_SECURITY_QOS_VERSION_1 equ 1
    RPC_SECURITY_QOS struct
      Version DWORD ?
      Capabilities DWORD ?
      IdentityTracking DWORD ?
      ImpersonationType DWORD ?
    RPC_SECURITY_QOS ends
    _RPC_SECURITY_QOS typedef RPC_SECURITY_QOS
    PRPC_SECURITY_QOS typedef ptr RPC_SECURITY_QOS
    ifndef _AUTH_IDENTITY_DEFINED
      _AUTH_IDENTITY_DEFINED equ <>
      SEC_WINNT_AUTH_IDENTITY_ANSI equ 1h
      SEC_WINNT_AUTH_IDENTITY_UNICODE equ 2h
      SEC_WINNT_AUTH_IDENTITY_W struct
        User POINTER ?
        UserLength DWORD ?
        Domain POINTER ?
        DomainLength DWORD ?
        Password POINTER ?
        PasswordLength DWORD ?
        Flags DWORD ?
      SEC_WINNT_AUTH_IDENTITY_W ends
      _SEC_WINNT_AUTH_IDENTITY_W typedef SEC_WINNT_AUTH_IDENTITY_W
      PSEC_WINNT_AUTH_IDENTITY_W typedef ptr SEC_WINNT_AUTH_IDENTITY_W
      if (NTDDI_VERSION ge NTDDI_VISTA)
        _AUTH_IDENTITY_A_DEFINED equ <>
      endif
      SEC_WINNT_AUTH_IDENTITY_A struct
        User POINTER ?
        UserLength DWORD ?
        Domain POINTER ?
        DomainLength DWORD ?
        Password POINTER ?
        PasswordLength DWORD ?
        Flags DWORD ?
      SEC_WINNT_AUTH_IDENTITY_A ends
      _SEC_WINNT_AUTH_IDENTITY_A typedef SEC_WINNT_AUTH_IDENTITY_A
      PSEC_WINNT_AUTH_IDENTITY_A typedef ptr SEC_WINNT_AUTH_IDENTITY_A
      ifdef UNICODE
        SEC_WINNT_AUTH_IDENTITY equ <SEC_WINNT_AUTH_IDENTITY_W>
        PSEC_WINNT_AUTH_IDENTITY equ <PSEC_WINNT_AUTH_IDENTITY_W>
        _SEC_WINNT_AUTH_IDENTITY equ <_SEC_WINNT_AUTH_IDENTITY_W>
      else
        SEC_WINNT_AUTH_IDENTITY equ <SEC_WINNT_AUTH_IDENTITY_A>
        PSEC_WINNT_AUTH_IDENTITY equ <PSEC_WINNT_AUTH_IDENTITY_A>
        _SEC_WINNT_AUTH_IDENTITY equ <_SEC_WINNT_AUTH_IDENTITY_A>
      endif
      if (NTDDI_VERSION ge NTDDI_WINXP)
        RPC_C_SECURITY_QOS_VERSION_2 equ 2
        RPC_C_AUTHN_INFO_TYPE_HTTP equ 1
        RPC_C_HTTP_AUTHN_TARGET_SERVER equ 1
        if (NTDDI_VERSION ge NTDDI_VISTA)
          RPC_C_HTTP_AUTHN_TARGET_PROXY equ 2
        endif
        RPC_C_HTTP_AUTHN_SCHEME_BASIC equ 00000001h
        RPC_C_HTTP_AUTHN_SCHEME_NTLM equ 00000002h
        RPC_C_HTTP_AUTHN_SCHEME_PASSPORT equ 00000004h
        RPC_C_HTTP_AUTHN_SCHEME_DIGEST equ 00000008h
        RPC_C_HTTP_AUTHN_SCHEME_NEGOTIATE equ 00000010h
        if (NTDDI_VERSION ge NTDDI_WS03)
          RPC_C_HTTP_AUTHN_SCHEME_CERT equ 00010000h
        endif
        RPC_C_HTTP_FLAG_USE_SSL equ 1
        RPC_C_HTTP_FLAG_USE_FIRST_AUTH_SCHEME equ 2
        if (NTDDI_VERSION ge NTDDI_WS03)
          RPC_C_HTTP_FLAG_IGNORE_CERT_CN_INVALID equ 8
        endif
        if (NTDDI_VERSION ge NTDDI_VISTASP1)
          RPC_C_HTTP_FLAG_ENABLE_CERT_REVOCATION_CHECK equ 16
        endif
        RPC_HTTP_TRANSPORT_CREDENTIALS_W struct
          TransportCredentials POINTER ?
          Flags DWORD ?
          AuthenticationTarget DWORD ?
          NumberOfAuthnSchemes DWORD ?
          AuthnSchemes POINTER ?
          ServerCertificateSubject POINTER ?
        RPC_HTTP_TRANSPORT_CREDENTIALS_W ends
        _RPC_HTTP_TRANSPORT_CREDENTIALS_W typedef RPC_HTTP_TRANSPORT_CREDENTIALS_W
        PRPC_HTTP_TRANSPORT_CREDENTIALS_W typedef ptr RPC_HTTP_TRANSPORT_CREDENTIALS_W
        RPC_HTTP_TRANSPORT_CREDENTIALS_A struct
          TransportCredentials POINTER ?
          Flags DWORD ?
          AuthenticationTarget DWORD ?
          NumberOfAuthnSchemes DWORD ?
          AuthnSchemes POINTER ?
          ServerCertificateSubject POINTER ?
        RPC_HTTP_TRANSPORT_CREDENTIALS_A ends
        _RPC_HTTP_TRANSPORT_CREDENTIALS_A typedef RPC_HTTP_TRANSPORT_CREDENTIALS_A
        PRPC_HTTP_TRANSPORT_CREDENTIALS_A typedef ptr RPC_HTTP_TRANSPORT_CREDENTIALS_A
        if (NTDDI_VERSION ge NTDDI_VISTA)
          RPC_HTTP_TRANSPORT_CREDENTIALS_V2_W struct
            TransportCredentials POINTER ?
            Flags DWORD ?
            AuthenticationTarget DWORD ?
            NumberOfAuthnSchemes DWORD ?
            AuthnSchemes POINTER ?
            ServerCertificateSubject POINTER ?
            ProxyCredentials POINTER ?
            NumberOfProxyAuthnSchemes DWORD ?
            ProxyAuthnSchemes POINTER ?
          RPC_HTTP_TRANSPORT_CREDENTIALS_V2_W ends
          _RPC_HTTP_TRANSPORT_CREDENTIALS_V2_W typedef RPC_HTTP_TRANSPORT_CREDENTIALS_V2_W
          PRPC_HTTP_TRANSPORT_CREDENTIALS_V2_W typedef ptr RPC_HTTP_TRANSPORT_CREDENTIALS_V2_W
          RPC_HTTP_TRANSPORT_CREDENTIALS_V2_A struct
            TransportCredentials POINTER ?
            Flags DWORD ?
            AuthenticationTarget DWORD ?
            NumberOfAuthnSchemes DWORD ?
            AuthnSchemes POINTER ?
            ServerCertificateSubject POINTER ?
            ProxyCredentials POINTER ?
            NumberOfProxyAuthnSchemes DWORD ?
            ProxyAuthnSchemes POINTER ?
          RPC_HTTP_TRANSPORT_CREDENTIALS_V2_A ends
          _RPC_HTTP_TRANSPORT_CREDENTIALS_V2_A typedef RPC_HTTP_TRANSPORT_CREDENTIALS_V2_A
          PRPC_HTTP_TRANSPORT_CREDENTIALS_V2_A typedef ptr RPC_HTTP_TRANSPORT_CREDENTIALS_V2_A
        endif
        if (NTDDI_VERSION ge NTDDI_WIN7)
          RPC_HTTP_TRANSPORT_CREDENTIALS_V3_W struct
            TransportCredentials RPC_AUTH_IDENTITY_HANDLE ?
            Flags DWORD ?
            AuthenticationTarget DWORD ?
            NumberOfAuthnSchemes DWORD ?
            AuthnSchemes POINTER ?
            ServerCertificateSubject POINTER ?
            ProxyCredentials RPC_AUTH_IDENTITY_HANDLE ?
            NumberOfProxyAuthnSchemes DWORD ?
            ProxyAuthnSchemes POINTER ?
          RPC_HTTP_TRANSPORT_CREDENTIALS_V3_W ends
          _RPC_HTTP_TRANSPORT_CREDENTIALS_V3_W typedef RPC_HTTP_TRANSPORT_CREDENTIALS_V3_W
          PRPC_HTTP_TRANSPORT_CREDENTIALS_V3_W typedef ptr RPC_HTTP_TRANSPORT_CREDENTIALS_V3_W
          RPC_HTTP_TRANSPORT_CREDENTIALS_V3_A struct
            TransportCredentials RPC_AUTH_IDENTITY_HANDLE ?
            Flags DWORD ?
            AuthenticationTarget DWORD ?
            NumberOfAuthnSchemes DWORD ?
            AuthnSchemes POINTER ?
            ServerCertificateSubject POINTER ?
            ProxyCredentials RPC_AUTH_IDENTITY_HANDLE ?
            NumberOfProxyAuthnSchemes DWORD ?
            ProxyAuthnSchemes POINTER ?
          RPC_HTTP_TRANSPORT_CREDENTIALS_V3_A ends
          _RPC_HTTP_TRANSPORT_CREDENTIALS_V3_A typedef RPC_HTTP_TRANSPORT_CREDENTIALS_V3_A
          PRPC_HTTP_TRANSPORT_CREDENTIALS_V3_A typedef ptr RPC_HTTP_TRANSPORT_CREDENTIALS_V3_A
        endif
        RPC_SECURITY_QOS_V2_W struct
          Version DWORD ?
          Capabilities DWORD ?
          IdentityTracking DWORD ?
          ImpersonationType DWORD ?
          AdditionalSecurityInfoType DWORD ?
          union u
            HttpCredentials POINTER ?
          ends
        RPC_SECURITY_QOS_V2_W ends
        _RPC_SECURITY_QOS_V2_W typedef RPC_SECURITY_QOS_V2_W
        PRPC_SECURITY_QOS_V2_W typedef ptr RPC_SECURITY_QOS_V2_W
        RPC_SECURITY_QOS_V2_A struct
          Version DWORD ?
          Capabilities DWORD ?
          IdentityTracking DWORD ?
          ImpersonationType DWORD ?
          AdditionalSecurityInfoType DWORD ?
          union u
            HttpCredentials POINTER ?
          ends
        RPC_SECURITY_QOS_V2_A ends
        _RPC_SECURITY_QOS_V2_A typedef RPC_SECURITY_QOS_V2_A
        PRPC_SECURITY_QOS_V2_A typedef ptr RPC_SECURITY_QOS_V2_A
        if (NTDDI_VERSION ge NTDDI_WS03)
          RPC_C_SECURITY_QOS_VERSION_3 equ 3
          RPC_SECURITY_QOS_V3_W struct
            Version DWORD ?
            Capabilities DWORD ?
            IdentityTracking DWORD ?
            ImpersonationType DWORD ?
            AdditionalSecurityInfoType DWORD ?
            union u
              HttpCredentials POINTER ?
            ends
            Sid POINTER ?
          RPC_SECURITY_QOS_V3_W ends
          _RPC_SECURITY_QOS_V3_W typedef RPC_SECURITY_QOS_V3_W
          PRPC_SECURITY_QOS_V3_W typedef ptr RPC_SECURITY_QOS_V3_W
          RPC_SECURITY_QOS_V3_A struct
            Version DWORD ?
            Capabilities DWORD ?
            IdentityTracking DWORD ?
            ImpersonationType DWORD ?
            AdditionalSecurityInfoType DWORD ?
            union u
              HttpCredentials POINTER ?
            ends
            Sid POINTER ?
          RPC_SECURITY_QOS_V3_A ends
          _RPC_SECURITY_QOS_V3_A typedef RPC_SECURITY_QOS_V3_A
          PRPC_SECURITY_QOS_V3_A typedef ptr RPC_SECURITY_QOS_V3_A
        endif
        if (NTDDI_VERSION ge NTDDI_VISTA)
          RPC_C_SECURITY_QOS_VERSION_4 equ 4
          RPC_SECURITY_QOS_V4_W struct
            Version DWORD ?
            Capabilities DWORD ?
            IdentityTracking DWORD ?
            ImpersonationType DWORD ?
            AdditionalSecurityInfoType DWORD ?
            union u
              HttpCredentials POINTER ?
            ends
            Sid POINTER ?
            EffectiveOnly DWORD ?
          RPC_SECURITY_QOS_V4_W ends
          _RPC_SECURITY_QOS_V4_W typedef RPC_SECURITY_QOS_V4_W
          PRPC_SECURITY_QOS_V4_W typedef ptr RPC_SECURITY_QOS_V4_W
          RPC_SECURITY_QOS_V4_A struct
            Version DWORD ?
            Capabilities DWORD ?
            IdentityTracking DWORD ?
            ImpersonationType DWORD ?
            AdditionalSecurityInfoType DWORD ?
            union u
              HttpCredentials POINTER ?
            ends
            Sid POINTER ?
            EffectiveOnly DWORD ?
          RPC_SECURITY_QOS_V4_A ends
          _RPC_SECURITY_QOS_V4_A typedef RPC_SECURITY_QOS_V4_A
          PRPC_SECURITY_QOS_V4_A typedef ptr RPC_SECURITY_QOS_V4_A
        endif
        if (NTDDI_VERSION ge NTDDI_WIN8)
          RPC_C_SECURITY_QOS_VERSION_5 equ 5
          RPC_SECURITY_QOS_V5_W struct
            Version DWORD ?
            Capabilities DWORD ?
            IdentityTracking DWORD ?
            ImpersonationType DWORD ?
            AdditionalSecurityInfoType DWORD ?
            union u
              HttpCredentials POINTER ?
            ends
            Sid POINTER ?
            EffectiveOnly DWORD ?
            ServerSecurityDescriptor POINTER ?
          RPC_SECURITY_QOS_V5_W ends
          _RPC_SECURITY_QOS_V5_W typedef RPC_SECURITY_QOS_V5_W
          PRPC_SECURITY_QOS_V5_W typedef ptr RPC_SECURITY_QOS_V5_W
          RPC_SECURITY_QOS_V5_A struct
            Version DWORD ?
            Capabilities DWORD ?
            IdentityTracking DWORD ?
            ImpersonationType DWORD ?
            AdditionalSecurityInfoType DWORD ?
            union u
              HttpCredentials POINTER ?
            ends
            Sid POINTER ?
            EffectiveOnly DWORD ?
            ServerSecurityDescriptor POINTER ?
          RPC_SECURITY_QOS_V5_A ends
          _RPC_SECURITY_QOS_V5_A typedef RPC_SECURITY_QOS_V5_A
          PRPC_SECURITY_QOS_V5_A typedef ptr RPC_SECURITY_QOS_V5_A
        endif
      endif
    endif
  endif
  if (NTDDI_VERSION ge NTDDI_WINXP)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      ifdef UNICODE
        RPC_SECURITY_QOS_V2 equ <RPC_SECURITY_QOS_V2_W>
        PRPC_SECURITY_QOS_V2 equ <PRPC_SECURITY_QOS_V2_W>
        _RPC_SECURITY_QOS_V2 equ <_RPC_SECURITY_QOS_V2_W>
        RPC_HTTP_TRANSPORT_CREDENTIALS equ <RPC_HTTP_TRANSPORT_CREDENTIALS_W>
        PRPC_HTTP_TRANSPORT_CREDENTIALS equ <PRPC_HTTP_TRANSPORT_CREDENTIALS_W>
        _RPC_HTTP_TRANSPORT_CREDENTIALS equ <_RPC_HTTP_TRANSPORT_CREDENTIALS_W>
        if (NTDDI_VERSION ge NTDDI_VISTA)
          RPC_HTTP_TRANSPORT_CREDENTIALS_V2 equ <RPC_HTTP_TRANSPORT_CREDENTIALS_V2_W>
          PRPC_HTTP_TRANSPORT_CREDENTIALS_V2 equ <PRPC_HTTP_TRANSPORT_CREDENTIALS_V2_W>
          _RPC_HTTP_TRANSPORT_CREDENTIALS_V2 equ <_RPC_HTTP_TRANSPORT_CREDENTIALS_V2_W>
        endif
        if (NTDDI_VERSION ge NTDDI_WIN7)
          RPC_HTTP_TRANSPORT_CREDENTIALS_V3 equ <RPC_HTTP_TRANSPORT_CREDENTIALS_V3_W>
          PRPC_HTTP_TRANSPORT_CREDENTIALS_V3 equ <PRPC_HTTP_TRANSPORT_CREDENTIALS_V3_W>
          _RPC_HTTP_TRANSPORT_CREDENTIALS_V3 equ <_RPC_HTTP_TRANSPORT_CREDENTIALS_V3_W>
        endif
        if (NTDDI_VERSION ge NTDDI_WS03)
          RPC_SECURITY_QOS_V3 equ <RPC_SECURITY_QOS_V3_W>
          PRPC_SECURITY_QOS_V3 equ <PRPC_SECURITY_QOS_V3_W>
          _RPC_SECURITY_QOS_V3 equ <_RPC_SECURITY_QOS_V3_W>
        endif
        if (NTDDI_VERSION ge NTDDI_VISTA)
          RPC_SECURITY_QOS_V4 equ <RPC_SECURITY_QOS_V4_W>
          PRPC_SECURITY_QOS_V4 equ <PRPC_SECURITY_QOS_V4_W>
          _RPC_SECURITY_QOS_V4 equ <_RPC_SECURITY_QOS_V4_W>
        endif
        if (NTDDI_VERSION ge NTDDI_WIN8)
          RPC_SECURITY_QOS_V5 equ <RPC_SECURITY_QOS_V5_W>
          PRPC_SECURITY_QOS_V5 equ <PRPC_SECURITY_QOS_V5_W>
          _RPC_SECURITY_QOS_V5 equ <_RPC_SECURITY_QOS_V5_W>
        endif
      else
        RPC_SECURITY_QOS_V2 equ <RPC_SECURITY_QOS_V2_A>
        PRPC_SECURITY_QOS_V2 equ <PRPC_SECURITY_QOS_V2_A>
        _RPC_SECURITY_QOS_V2 equ <_RPC_SECURITY_QOS_V2_A>
        RPC_HTTP_TRANSPORT_CREDENTIALS equ <RPC_HTTP_TRANSPORT_CREDENTIALS_A>
        PRPC_HTTP_TRANSPORT_CREDENTIALS equ <PRPC_HTTP_TRANSPORT_CREDENTIALS_A>
        _RPC_HTTP_TRANSPORT_CREDENTIALS equ <_RPC_HTTP_TRANSPORT_CREDENTIALS_A>
        if (NTDDI_VERSION ge NTDDI_VISTA)
          RPC_HTTP_TRANSPORT_CREDENTIALS_V2 equ <RPC_HTTP_TRANSPORT_CREDENTIALS_V2_A>
          PRPC_HTTP_TRANSPORT_CREDENTIALS_V2 equ <PRPC_HTTP_TRANSPORT_CREDENTIALS_V2_A>
          _RPC_HTTP_TRANSPORT_CREDENTIALS_V2 equ <_RPC_HTTP_TRANSPORT_CREDENTIALS_V2_A>
        endif
        if (NTDDI_VERSION ge NTDDI_WIN7)
          RPC_HTTP_TRANSPORT_CREDENTIALS_V3 equ <RPC_HTTP_TRANSPORT_CREDENTIALS_V3_A>
          PRPC_HTTP_TRANSPORT_CREDENTIALS_V3 equ <PRPC_HTTP_TRANSPORT_CREDENTIALS_V3_A>
          _RPC_HTTP_TRANSPORT_CREDENTIALS_V3 equ <_RPC_HTTP_TRANSPORT_CREDENTIALS_V3_A>
        endif
        if (NTDDI_VERSION ge NTDDI_WS03)
          RPC_SECURITY_QOS_V3 equ <RPC_SECURITY_QOS_V3_A>
          PRPC_SECURITY_QOS_V3 equ <PRPC_SECURITY_QOS_V3_A>
          _RPC_SECURITY_QOS_V3 equ <_RPC_SECURITY_QOS_V3_A>
        endif
        if (NTDDI_VERSION ge NTDDI_VISTA)
          RPC_SECURITY_QOS_V4 equ <RPC_SECURITY_QOS_V4_A>
          PRPC_SECURITY_QOS_V4 equ <PRPC_SECURITY_QOS_V4_A>
          _RPC_SECURITY_QOS_V4 equ <_RPC_SECURITY_QOS_V4_A>
        endif
        if (NTDDI_VERSION ge NTDDI_WIN8)
          RPC_SECURITY_QOS_V5 equ <RPC_SECURITY_QOS_V5_A>
          PRPC_SECURITY_QOS_V5 equ <PRPC_SECURITY_QOS_V5_A>
          _RPC_SECURITY_QOS_V5 equ <_RPC_SECURITY_QOS_V5_A>
        endif
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        RPC_PROTSEQ_TCP equ (1h)
        RPC_PROTSEQ_NMP equ (2h)
        RPC_PROTSEQ_LRPC equ (3h)
        RPC_PROTSEQ_HTTP equ (4h)
        RPC_BHT_OBJECT_UUID_VALID equ (1h)
        RPC_BHO_NONCAUSAL equ (1h)
        RPC_BHO_DONTLINGER equ (2h)
        RPC_BHO_EXCLUSIVE_AND_GUARANTEED equ (4h)
        RPC_BINDING_HANDLE_TEMPLATE_V1_W struct
          Version DWORD ?
          Flags DWORD ?
          ProtocolSequence DWORD ?
          NetworkAddress POINTER ?
          StringEndpoint POINTER ?
          union u1
            Reserved POINTER ?
          ends
          ObjectUuid UUID <>
        RPC_BINDING_HANDLE_TEMPLATE_V1_W ends
        _RPC_BINDING_HANDLE_TEMPLATE_V1_W typedef RPC_BINDING_HANDLE_TEMPLATE_V1_W
        PRPC_BINDING_HANDLE_TEMPLATE_V1_W typedef ptr RPC_BINDING_HANDLE_TEMPLATE_V1_W
        RPC_BINDING_HANDLE_TEMPLATE_V1_A struct
          Version DWORD ?
          Flags DWORD ?
          ProtocolSequence DWORD ?
          NetworkAddress POINTER ?
          StringEndpoint POINTER ?
          union u1
            Reserved POINTER ?
          ends
          ObjectUuid UUID <>
        RPC_BINDING_HANDLE_TEMPLATE_V1_A ends
        _RPC_BINDING_HANDLE_TEMPLATE_V1_A typedef RPC_BINDING_HANDLE_TEMPLATE_V1_A
        PRPC_BINDING_HANDLE_TEMPLATE_V1_A typedef ptr RPC_BINDING_HANDLE_TEMPLATE_V1_A
        RPC_BINDING_HANDLE_SECURITY_V1_W struct
          Version DWORD ?
          ServerPrincName POINTER ?
          AuthnLevel DWORD ?
          AuthnSvc DWORD ?
          AuthIdentity POINTER ?
          SecurityQos POINTER ?
        RPC_BINDING_HANDLE_SECURITY_V1_W ends
        _RPC_BINDING_HANDLE_SECURITY_V1_W typedef RPC_BINDING_HANDLE_SECURITY_V1_W
        PRPC_BINDING_HANDLE_SECURITY_V1_W typedef ptr RPC_BINDING_HANDLE_SECURITY_V1_W
        ifdef _AUTH_IDENTITY_A_DEFINED
          RPC_BINDING_HANDLE_SECURITY_V1_A struct
            Version DWORD ?
            ServerPrincName POINTER ?
            AuthnLevel DWORD ?
            AuthnSvc DWORD ?
            AuthIdentity POINTER ?
            SecurityQos POINTER ?
          RPC_BINDING_HANDLE_SECURITY_V1_A ends
          _RPC_BINDING_HANDLE_SECURITY_V1_A typedef RPC_BINDING_HANDLE_SECURITY_V1_A
          PRPC_BINDING_HANDLE_SECURITY_V1_A typedef ptr RPC_BINDING_HANDLE_SECURITY_V1_A
        endif
        RPC_BINDING_HANDLE_OPTIONS_V1 struct
          Version DWORD ?
          Flags DWORD ?
          ComTimeout DWORD ?
          CallTimeout DWORD ?
        RPC_BINDING_HANDLE_OPTIONS_V1 ends
        _RPC_BINDING_HANDLE_OPTIONS_V1 typedef RPC_BINDING_HANDLE_OPTIONS_V1
        PRPC_BINDING_HANDLE_OPTIONS_V1 typedef ptr RPC_BINDING_HANDLE_OPTIONS_V1
        ifdef UNICODE
          RPC_BINDING_HANDLE_TEMPLATE_V1 equ <RPC_BINDING_HANDLE_TEMPLATE_V1_W>
          PRPC_BINDING_HANDLE_TEMPLATE_V1 equ <PRPC_BINDING_HANDLE_TEMPLATE_V1_W>
          _RPC_BINDING_HANDLE_TEMPLATE_V1 equ <_RPC_BINDING_HANDLE_TEMPLATE_V1_W>
          RPC_BINDING_HANDLE_SECURITY_V1 equ <RPC_BINDING_HANDLE_SECURITY_V1_W>
          PRPC_BINDING_HANDLE_SECURITY_V1 equ <PRPC_BINDING_HANDLE_SECURITY_V1_W>
          _RPC_BINDING_HANDLE_SECURITY_V1 equ <_RPC_BINDING_HANDLE_SECURITY_V1_W>
        else
          RPC_BINDING_HANDLE_TEMPLATE_V1 equ <RPC_BINDING_HANDLE_TEMPLATE_V1_A>
          PRPC_BINDING_HANDLE_TEMPLATE_V1 equ <PRPC_BINDING_HANDLE_TEMPLATE_V1_A>
          _RPC_BINDING_HANDLE_TEMPLATE_V1 equ <_RPC_BINDING_HANDLE_TEMPLATE_V1_A>
          RPC_BINDING_HANDLE_SECURITY_V1 equ <RPC_BINDING_HANDLE_SECURITY_V1_A>
          PRPC_BINDING_HANDLE_SECURITY_V1 equ <PRPC_BINDING_HANDLE_SECURITY_V1_A>
          _RPC_BINDING_HANDLE_SECURITY_V1 equ <_RPC_BINDING_HANDLE_SECURITY_V1_A>
        endif
        ifdef _AUTH_IDENTITY_A_DEFINED
          @DefProto DllImport, RpcBindingCreateA, WIN_STD_CALL_CONV,, <:ptr RPC_BINDING_HANDLE_TEMPLATE_V1_A, :ptr RPC_BINDING_HANDLE_SECURITY_V1_A, :ptr RPC_BINDING_HANDLE_OPTIONS_V1, :ptr RPC_BINDING_HANDLE>, 16
        endif
        @DefProto DllImport, RpcBindingCreateW, WIN_STD_CALL_CONV,, <:ptr RPC_BINDING_HANDLE_TEMPLATE_V1_W, :ptr RPC_BINDING_HANDLE_SECURITY_V1_W, :ptr RPC_BINDING_HANDLE_OPTIONS_V1, :ptr RPC_BINDING_HANDLE>, 16
        ifdef UNICODE
          RpcBindingCreate equ <RpcBindingCreateW>
        else
          RpcBindingCreate equ <RpcBindingCreateA>
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
        @DefProto DllImport, RpcBindingGetTrainingContextHandle, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr ptr>, 8
        @DefProto DllImport, RpcServerInqBindingHandle, WIN_STD_CALL_CONV,, <:ptr RPC_BINDING_HANDLE>, 4
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_WS03)
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        RPC_HTTP_REDIRECTOR_STAGE typedef SDWORD
        RPCHTTP_RS_REDIRECT equ 1
        RPCHTTP_RS_ACCESS_1 equ 2
        RPCHTTP_RS_SESSION equ 3
        RPCHTTP_RS_ACCESS_2 equ 4
        RPCHTTP_RS_INTERFACE equ 5
        _RPC_HTTP_REDIRECTOR_STAGE typedef RPC_HTTP_REDIRECTOR_STAGE

      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      if (NTDDI_VERSION ge NTDDI_WS03)
        TYPE_RPC_NEW_HTTP_PROXY_CHANNEL typedef proto WIN_STD_CALL_CONV :RPC_HTTP_REDIRECTOR_STAGE, :RPC_WSTR, :RPC_WSTR, :RPC_WSTR, :RPC_WSTR, :ptr, :ptr, :ptr, :ptr, :DWORD, :ptr RPC_WSTR, :ptr RPC_WSTR
        RPC_NEW_HTTP_PROXY_CHANNEL typedef ptr TYPE_RPC_NEW_HTTP_PROXY_CHANNEL

      else
        TYPE_RPC_NEW_HTTP_PROXY_CHANNEL typedef proto WIN_STD_CALL_CONV :ptr WORD, :ptr WORD, :ptr BYTE, :ptr ptr WORD
        RPC_NEW_HTTP_PROXY_CHANNEL typedef ptr TYPE_RPC_NEW_HTTP_PROXY_CHANNEL

      endif
      TYPE_RPC_HTTP_PROXY_FREE_STRING typedef proto WIN_STD_CALL_CONV :RPC_WSTR
      RPC_HTTP_PROXY_FREE_STRING typedef ptr TYPE_RPC_HTTP_PROXY_FREE_STRING

    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    RPC_C_AUTHZ_NONE equ 0
    RPC_C_AUTHZ_NAME equ 1
    RPC_C_AUTHZ_DCE equ 2
    RPC_C_AUTHZ_DEFAULT equ 0ffffffffh
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, RpcImpersonateClient, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE>, 4
    @DefProto DllImport, RpcImpersonateClient2, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE>, 4
    @DefProto DllImport, RpcRevertToSelfEx, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE>, 4
    @DefProto DllImport, RpcRevertToSelf, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, RpcImpersonateClientContainer, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE>, 4
    @DefProto DllImport, RpcRevertContainerImpersonation, WIN_STD_CALL_CONV,, <>, 0
  endif
  ifdef RPC_UNICODE_SUPPORTED
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, RpcBindingInqAuthClientA, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr RPC_AUTHZ_HANDLE, :ptr RPC_CSTR, :ptr DWORD, :ptr DWORD, :ptr DWORD>, 24
      @DefProto DllImport, RpcBindingInqAuthClientW, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr RPC_AUTHZ_HANDLE, :ptr RPC_WSTR, :ptr DWORD, :ptr DWORD, :ptr DWORD>, 24
      @DefProto DllImport, RpcBindingInqAuthClientExA, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr RPC_AUTHZ_HANDLE, :ptr RPC_CSTR, :ptr DWORD, :ptr DWORD, :ptr DWORD, :DWORD>, 28
      @DefProto DllImport, RpcBindingInqAuthClientExW, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr RPC_AUTHZ_HANDLE, :ptr RPC_WSTR, :ptr DWORD, :ptr DWORD, :ptr DWORD, :DWORD>, 28
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, RpcBindingInqAuthInfoA, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr RPC_CSTR, :ptr DWORD, :ptr DWORD, :ptr RPC_AUTH_IDENTITY_HANDLE, :ptr DWORD>, 24
      @DefProto DllImport, RpcBindingInqAuthInfoW, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr RPC_WSTR, :ptr DWORD, :ptr DWORD, :ptr RPC_AUTH_IDENTITY_HANDLE, :ptr DWORD>, 24
      @DefProto DllImport, RpcBindingSetAuthInfoA, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :RPC_CSTR, :DWORD, :DWORD, :RPC_AUTH_IDENTITY_HANDLE, :DWORD>, 24
      @DefProto DllImport, RpcBindingSetAuthInfoExA, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :RPC_CSTR, :DWORD, :DWORD, :RPC_AUTH_IDENTITY_HANDLE, :DWORD, :ptr RPC_SECURITY_QOS>, 28
      @DefProto DllImport, RpcBindingSetAuthInfoW, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :RPC_WSTR, :DWORD, :DWORD, :RPC_AUTH_IDENTITY_HANDLE, :DWORD>, 24
      @DefProto DllImport, RpcBindingSetAuthInfoExW, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :RPC_WSTR, :DWORD, :DWORD, :RPC_AUTH_IDENTITY_HANDLE, :DWORD, :ptr RPC_SECURITY_QOS>, 28
      @DefProto DllImport, RpcBindingInqAuthInfoExA, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr RPC_CSTR, :ptr DWORD, :ptr DWORD, :ptr RPC_AUTH_IDENTITY_HANDLE, :ptr DWORD, :DWORD, :ptr RPC_SECURITY_QOS>, 32
      @DefProto DllImport, RpcBindingInqAuthInfoExW, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr RPC_WSTR, :ptr DWORD, :ptr DWORD, :ptr RPC_AUTH_IDENTITY_HANDLE, :ptr DWORD, :DWORD, :ptr RPC_SECURITY_QOS>, 32
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      TYPE_RPC_AUTH_KEY_RETRIEVAL_FN typedef proto WIN_STD_CALL_CONV :ptr, :RPC_WSTR, :DWORD, :ptr ptr, :ptr RPC_STATUS
      RPC_AUTH_KEY_RETRIEVAL_FN typedef ptr TYPE_RPC_AUTH_KEY_RETRIEVAL_FN

      @DefProto DllImport, RpcServerCompleteSecurityCallback, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :RPC_STATUS>, 8
      @DefProto DllImport, RpcServerRegisterAuthInfoA, WIN_STD_CALL_CONV,, <:RPC_CSTR, :DWORD, :RPC_AUTH_KEY_RETRIEVAL_FN, :ptr>, 16
      @DefProto DllImport, RpcServerRegisterAuthInfoW, WIN_STD_CALL_CONV,, <:RPC_WSTR, :DWORD, :RPC_AUTH_KEY_RETRIEVAL_FN, :ptr>, 16
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      ifdef UNICODE
        RpcBindingInqAuthClient equ <RpcBindingInqAuthClientW>
        RpcBindingInqAuthClientEx equ <RpcBindingInqAuthClientExW>
        RpcBindingInqAuthInfo equ <RpcBindingInqAuthInfoW>
        RpcBindingSetAuthInfo equ <RpcBindingSetAuthInfoW>
        RpcServerRegisterAuthInfo equ <RpcServerRegisterAuthInfoW>
        RpcBindingInqAuthInfoEx equ <RpcBindingInqAuthInfoExW>
        RpcBindingSetAuthInfoEx equ <RpcBindingSetAuthInfoExW>
      else
        RpcBindingInqAuthClient equ <RpcBindingInqAuthClientA>
        RpcBindingInqAuthClientEx equ <RpcBindingInqAuthClientExA>
        RpcBindingInqAuthInfo equ <RpcBindingInqAuthInfoA>
        RpcBindingSetAuthInfo equ <RpcBindingSetAuthInfoA>
        RpcServerRegisterAuthInfo equ <RpcServerRegisterAuthInfoA>
        RpcBindingInqAuthInfoEx equ <RpcBindingInqAuthInfoExA>
        RpcBindingSetAuthInfoEx equ <RpcBindingSetAuthInfoExA>
      endif
    endif
  else
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, RpcBindingInqAuthClient, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr RPC_AUTHZ_HANDLE, :ptr RPC_WSTR, :ptr DWORD, :ptr DWORD, :ptr DWORD>, 24
      @DefProto DllImport, RpcBindingInqAuthClientEx, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr RPC_AUTHZ_HANDLE, :ptr RPC_CSTR, :ptr DWORD, :ptr DWORD, :ptr DWORD, :DWORD>, 28
      @DefProto DllImport, RpcBindingInqAuthInfo, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr RPC_CSTR, :ptr DWORD, :ptr DWORD, :ptr RPC_AUTH_IDENTITY_HANDLE, :ptr DWORD>, 24
      @DefProto DllImport, RpcBindingSetAuthInfo, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :RPC_CSTR, :DWORD, :DWORD, :RPC_AUTH_IDENTITY_HANDLE, :DWORD>, 24
      TYPE_RPC_AUTH_KEY_RETRIEVAL_FN typedef proto WIN_STD_CALL_CONV :ptr, :ptr BYTE, :DWORD, :ptr ptr, :ptr RPC_STATUS
      RPC_AUTH_KEY_RETRIEVAL_FN typedef ptr TYPE_RPC_AUTH_KEY_RETRIEVAL_FN

      @DefProto DllImport, RpcServerRegisterAuthInfo, WIN_STD_CALL_CONV,, <:RPC_CSTR, :DWORD, :RPC_AUTH_KEY_RETRIEVAL_FN, :ptr>, 16
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (NTDDI_VERSION ge NTDDI_WINXP)
      if  not Defined(_M_IA64)
        RPC_CLIENT_INFORMATION1 struct
          UserName POINTER ?
          ComputerName POINTER ?
          Privilege WORD ?
          AuthFlags DWORD ?
        RPC_CLIENT_INFORMATION1 ends
        PRPC_CLIENT_INFORMATION1 typedef ptr RPC_CLIENT_INFORMATION1
      endif
    endif
    @DefProto DllImport, RpcBindingServerFromClient, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr RPC_BINDING_HANDLE>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, RpcRaiseException, WIN_STD_CALL_CONV,, <:RPC_STATUS>, 4
    @DefProto DllImport, RpcTestCancel, WIN_STD_CALL_CONV,, <>, 0
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, RpcServerTestCancel, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE>, 4
    @DefProto DllImport, RpcCancelThread, WIN_STD_CALL_CONV,, <:ptr>, 4
    @DefProto DllImport, RpcCancelThreadEx, WIN_STD_CALL_CONV,, <:ptr, :SDWORD>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, UuidCreate, WIN_STD_CALL_CONV,, <:ptr UUID>, 4
    @DefProto DllImport, UuidCreateSequential, WIN_STD_CALL_CONV,, <:ptr UUID>, 4
    ifdef RPC_UNICODE_SUPPORTED
      @DefProto DllImport, UuidToStringA, WIN_STD_CALL_CONV,, <:ptr UUID, :ptr RPC_CSTR>, 8
      @DefProto DllImport, UuidFromStringA, WIN_STD_CALL_CONV,, <:RPC_CSTR, :ptr UUID>, 8
      @DefProto DllImport, UuidToStringW, WIN_STD_CALL_CONV,, <:ptr UUID, :ptr RPC_WSTR>, 8
      @DefProto DllImport, UuidFromStringW, WIN_STD_CALL_CONV,, <:RPC_WSTR, :ptr UUID>, 8
      ifdef UNICODE
        UuidFromString equ <UuidFromStringW>
        UuidToString equ <UuidToStringW>
      else
        UuidFromString equ <UuidFromStringA>
        UuidToString equ <UuidToStringA>
      endif
    else
      @DefProto DllImport, UuidToString, WIN_STD_CALL_CONV,, <:ptr UUID, :ptr RPC_CSTR>, 8
      @DefProto DllImport, UuidFromString, WIN_STD_CALL_CONV,, <:RPC_CSTR, :ptr UUID>, 8
    endif
    @DefProto DllImport, UuidCompare, WIN_STD_CALL_CONV,, <:ptr UUID, :ptr UUID, :ptr RPC_STATUS>, 12
    @DefProto DllImport, UuidCreateNil, WIN_STD_CALL_CONV,, <:ptr UUID>, 4
    @DefProto DllImport, UuidEqual, WIN_STD_CALL_CONV,, <:ptr UUID, :ptr UUID, :ptr RPC_STATUS>, 12
    @DefProto DllImport, UuidHash, WIN_STD_CALL_CONV,, <:ptr UUID, :ptr RPC_STATUS>, 8
    @DefProto DllImport, UuidIsNil, WIN_STD_CALL_CONV,, <:ptr UUID, :ptr RPC_STATUS>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    ifdef RPC_UNICODE_SUPPORTED
      @DefProto DllImport, RpcEpRegisterNoReplaceA, WIN_STD_CALL_CONV,, <:RPC_IF_HANDLE, :ptr RPC_BINDING_VECTOR, :ptr UUID_VECTOR, :RPC_CSTR>, 16
      @DefProto DllImport, RpcEpRegisterNoReplaceW, WIN_STD_CALL_CONV,, <:RPC_IF_HANDLE, :ptr RPC_BINDING_VECTOR, :ptr UUID_VECTOR, :RPC_WSTR>, 16
      @DefProto DllImport, RpcEpRegisterA, WIN_STD_CALL_CONV,, <:RPC_IF_HANDLE, :ptr RPC_BINDING_VECTOR, :ptr UUID_VECTOR, :RPC_CSTR>, 16
      @DefProto DllImport, RpcEpRegisterW, WIN_STD_CALL_CONV,, <:RPC_IF_HANDLE, :ptr RPC_BINDING_VECTOR, :ptr UUID_VECTOR, :RPC_WSTR>, 16
      ifdef UNICODE
        RpcEpRegisterNoReplace equ <RpcEpRegisterNoReplaceW>
        RpcEpRegister equ <RpcEpRegisterW>
      else
        RpcEpRegisterNoReplace equ <RpcEpRegisterNoReplaceA>
        RpcEpRegister equ <RpcEpRegisterA>
      endif
    else
      @DefProto DllImport, RpcEpRegisterNoReplace, WIN_STD_CALL_CONV,, <:RPC_IF_HANDLE, :ptr RPC_BINDING_VECTOR, :ptr UUID_VECTOR, :RPC_CSTR>, 16
      @DefProto DllImport, RpcEpRegister, WIN_STD_CALL_CONV,, <:RPC_IF_HANDLE, :ptr RPC_BINDING_VECTOR, :ptr UUID_VECTOR, :RPC_CSTR>, 16
    endif
    @DefProto DllImport, RpcEpUnregister, WIN_STD_CALL_CONV,, <:RPC_IF_HANDLE, :ptr RPC_BINDING_VECTOR, :ptr UUID_VECTOR>, 12
  endif
  DCE_C_ERROR_STRING_LEN equ 256
  ifdef RPC_UNICODE_SUPPORTED
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, DceErrorInqTextA, WIN_STD_CALL_CONV,, <:RPC_STATUS, :RPC_CSTR>, 8
      @DefProto DllImport, DceErrorInqTextW, WIN_STD_CALL_CONV,, <:RPC_STATUS, :RPC_WSTR>, 8
      ifdef UNICODE
        DceErrorInqText equ <DceErrorInqTextW>
      else
        DceErrorInqText equ <DceErrorInqTextA>
      endif
    endif
  else
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, DceErrorInqText, WIN_STD_CALL_CONV,, <:RPC_STATUS, :RPC_CSTR>, 8
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    RPC_EP_INQ_HANDLE typedef ptr I_RPC_HANDLE
    RPC_C_EP_ALL_ELTS equ 0
    RPC_C_EP_MATCH_BY_IF equ 1
    RPC_C_EP_MATCH_BY_OBJ equ 2
    RPC_C_EP_MATCH_BY_BOTH equ 3
    RPC_C_VERS_ALL equ 1
    RPC_C_VERS_COMPATIBLE equ 2
    RPC_C_VERS_EXACT equ 3
    RPC_C_VERS_MAJOR_ONLY equ 4
    RPC_C_VERS_UPTO equ 5
    @DefProto DllImport, RpcMgmtEpEltInqBegin, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :DWORD, :ptr RPC_IF_ID, :DWORD, :ptr UUID, :ptr RPC_EP_INQ_HANDLE>, 24
    @DefProto DllImport, RpcMgmtEpEltInqDone, WIN_STD_CALL_CONV,, <:ptr RPC_EP_INQ_HANDLE>, 4
    ifdef RPC_UNICODE_SUPPORTED
      @DefProto DllImport, RpcMgmtEpEltInqNextA, WIN_STD_CALL_CONV,, <:RPC_EP_INQ_HANDLE, :ptr RPC_IF_ID, :ptr RPC_BINDING_HANDLE, :ptr UUID, :ptr RPC_CSTR>, 20
      @DefProto DllImport, RpcMgmtEpEltInqNextW, WIN_STD_CALL_CONV,, <:RPC_EP_INQ_HANDLE, :ptr RPC_IF_ID, :ptr RPC_BINDING_HANDLE, :ptr UUID, :ptr RPC_WSTR>, 20
      ifdef UNICODE
        RpcMgmtEpEltInqNext equ <RpcMgmtEpEltInqNextW>
      else
        RpcMgmtEpEltInqNext equ <RpcMgmtEpEltInqNextA>
      endif
    else
      @DefProto DllImport, RpcMgmtEpEltInqNext, WIN_STD_CALL_CONV,, <:RPC_EP_INQ_HANDLE, :ptr RPC_IF_ID, :ptr RPC_BINDING_HANDLE, :ptr RPC_CSTR>, 16
    endif
    @DefProto DllImport, RpcMgmtEpUnregister, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr RPC_IF_ID, :RPC_BINDING_HANDLE, :ptr UUID>, 16
    TYPE_RPC_MGMT_AUTHORIZATION_FN typedef proto WIN_STD_CALL_CONV :RPC_BINDING_HANDLE, :DWORD, :ptr RPC_STATUS
    RPC_MGMT_AUTHORIZATION_FN typedef ptr TYPE_RPC_MGMT_AUTHORIZATION_FN

    RPC_C_MGMT_INQ_IF_IDS equ 0
    RPC_C_MGMT_INQ_PRINC_NAME equ 1
    RPC_C_MGMT_INQ_STATS equ 2
    RPC_C_MGMT_IS_SERVER_LISTEN equ 3
    RPC_C_MGMT_STOP_SERVER_LISTEN equ 4
    @DefProto DllImport, RpcMgmtSetAuthorizationFn, WIN_STD_CALL_CONV,, <:RPC_MGMT_AUTHORIZATION_FN>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    if (NTDDI_VERSION ge NTDDI_VISTA)
      @DefProto DllImport, RpcExceptionFilter, WIN_STD_CALL_CONV,, <:DWORD>, 4
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    RPC_C_PARM_MAX_PACKET_LENGTH equ 1
    RPC_C_PARM_BUFFER_LENGTH equ 2
    RPC_IF_AUTOLISTEN equ 0001h
    RPC_IF_OLE equ 0002h
    RPC_IF_ALLOW_UNKNOWN_AUTHORITY equ 0004h
    RPC_IF_ALLOW_SECURE_ONLY equ 0008h
    RPC_IF_ALLOW_CALLBACKS_WITH_NO_AUTH equ 0010h
    RPC_IF_ALLOW_LOCAL_ONLY equ 0020h
    RPC_IF_SEC_NO_CACHE equ 0040h
    if (NTDDI_VERSION ge NTDDI_VISTA)
      RPC_IF_SEC_CACHE_PER_PROC equ 0080h
      RPC_IF_ASYNC_CALLBACK equ 0100h
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      RPC_FW_IF_FLAG_DCOM equ 0001h
    endif
    if (NTDDI_VERSION ge NTDDI_WIN8)
      RPC_INTERFACE_GROUP typedef ptr
      PRPC_INTERFACE_GROUP typedef ptr ptr
      ifdef RPC_UNICODE_SUPPORTED
        RPC_ENDPOINT_TEMPLATEW struct
          Version DWORD ?
          ProtSeq RPC_WSTR ?
          Endpoint RPC_WSTR ?
          SecurityDescriptor POINTER ?
          Backlog DWORD ?
        RPC_ENDPOINT_TEMPLATEW ends
        PRPC_ENDPOINT_TEMPLATEW typedef ptr RPC_ENDPOINT_TEMPLATEW
        RPC_ENDPOINT_TEMPLATEA struct
          Version DWORD ?
          ProtSeq RPC_CSTR ?
          Endpoint RPC_CSTR ?
          SecurityDescriptor POINTER ?
          Backlog DWORD ?
        RPC_ENDPOINT_TEMPLATEA ends
        PRPC_ENDPOINT_TEMPLATEA typedef ptr RPC_ENDPOINT_TEMPLATEA
        ifdef UNICODE
          RPC_ENDPOINT_TEMPLATE equ <RPC_ENDPOINT_TEMPLATEW>
          PRPC_ENDPOINT_TEMPLATE equ <PRPC_ENDPOINT_TEMPLATEW>
        else
          RPC_ENDPOINT_TEMPLATE equ <RPC_ENDPOINT_TEMPLATEA>
          PRPC_ENDPOINT_TEMPLATE equ <PRPC_ENDPOINT_TEMPLATEA>
        endif
      else
        RPC_ENDPOINT_TEMPLATE struct
          Version DWORD ?
          ProtSeq RPC_CSTR ?
          Endpoint RPC_CSTR ?
          SecurityDescriptor POINTER ?
          Backlog DWORD ?
        RPC_ENDPOINT_TEMPLATE ends
        PRPC_ENDPOINT_TEMPLATE typedef ptr RPC_ENDPOINT_TEMPLATE
      endif
      ifdef RPC_UNICODE_SUPPORTED
        RPC_INTERFACE_TEMPLATEA struct
          Version DWORD ?
          IfSpec RPC_IF_HANDLE ?
          MgrTypeUuid POINTER ?
          MgrEpv POINTER ?
          Flags DWORD ?
          MaxCalls DWORD ?
          MaxRpcSize DWORD ?
          IfCallback POINTER ?
          UuidVector POINTER ?
          Annotation RPC_CSTR ?
          SecurityDescriptor POINTER ?
        RPC_INTERFACE_TEMPLATEA ends
        PRPC_INTERFACE_TEMPLATEA typedef ptr RPC_INTERFACE_TEMPLATEA
        RPC_INTERFACE_TEMPLATEW struct
          Version DWORD ?
          IfSpec RPC_IF_HANDLE ?
          MgrTypeUuid POINTER ?
          MgrEpv POINTER ?
          Flags DWORD ?
          MaxCalls DWORD ?
          MaxRpcSize DWORD ?
          IfCallback POINTER ?
          UuidVector POINTER ?
          Annotation RPC_WSTR ?
          SecurityDescriptor POINTER ?
        RPC_INTERFACE_TEMPLATEW ends
        PRPC_INTERFACE_TEMPLATEW typedef ptr RPC_INTERFACE_TEMPLATEW
        ifdef UNICODE
          RPC_INTERFACE_TEMPLATE equ <RPC_INTERFACE_TEMPLATEW>
          PRPC_INTERFACE_TEMPLATE equ <PRPC_INTERFACE_TEMPLATEW>
        else
          RPC_INTERFACE_TEMPLATE equ <RPC_INTERFACE_TEMPLATEA>
          PRPC_INTERFACE_TEMPLATE equ <PRPC_INTERFACE_TEMPLATEA>
        endif
      else
        RPC_INTERFACE_TEMPLATE struct
          Version DWORD ?
          IfSpec RPC_IF_HANDLE ?
          MgrTypeUuid POINTER ?
          MgrEpv POINTER ?
          Flags DWORD ?
          MaxCalls DWORD ?
          MaxRpcSize DWORD ?
          IfCallback POINTER ?
          UuidVector POINTER ?
          Annotation RPC_CSTR ?
          SecurityDescriptor POINTER ?
        RPC_INTERFACE_TEMPLATE ends
        PRPC_INTERFACE_TEMPLATE typedef ptr RPC_INTERFACE_TEMPLATE
      endif
      RPC_INTERFACE_GROUP_IDLE_CALLBACK_FN typedef proto :RPC_INTERFACE_GROUP, :ptr, :DWORD
      ifdef RPC_UNICODE_SUPPORTED
        @DefProto DllImport, RpcServerInterfaceGroupCreateW, WIN_STD_CALL_CONV,, <:ptr RPC_INTERFACE_TEMPLATEW, :DWORD, :ptr RPC_ENDPOINT_TEMPLATEW, :DWORD, :DWORD, :RPC_INTERFACE_GROUP_IDLE_CALLBACK_FN, :ptr, :PRPC_INTERFACE_GROUP>, 32
        @DefProto DllImport, RpcServerInterfaceGroupCreateA, WIN_STD_CALL_CONV,, <:ptr RPC_INTERFACE_TEMPLATEA, :DWORD, :ptr RPC_ENDPOINT_TEMPLATEA, :DWORD, :DWORD, :RPC_INTERFACE_GROUP_IDLE_CALLBACK_FN, :ptr, :PRPC_INTERFACE_GROUP>, 32
        ifdef UNICODE
          RpcServerInterfaceGroupCreate equ <RpcServerInterfaceGroupCreateW>
        else
          RpcServerInterfaceGroupCreate equ <RpcServerInterfaceGroupCreateA>
        endif
      else
        @DefProto DllImport, RpcServerInterfaceGroupCreate, WIN_STD_CALL_CONV,, <:ptr RPC_INTERFACE_TEMPLATE, :DWORD, :ptr RPC_ENDPOINT_TEMPLATE, :DWORD, :DWORD, :RPC_INTERFACE_GROUP_IDLE_CALLBACK_FN, :ptr, :PRPC_INTERFACE_GROUP>, 32
      endif
      @DefProto DllImport, RpcServerInterfaceGroupClose, WIN_STD_CALL_CONV,, <:RPC_INTERFACE_GROUP>, 4
      @DefProto DllImport, RpcServerInterfaceGroupActivate, WIN_STD_CALL_CONV,, <:RPC_INTERFACE_GROUP>, 4
      @DefProto DllImport, RpcServerInterfaceGroupDeactivate, WIN_STD_CALL_CONV,, <:RPC_INTERFACE_GROUP, :DWORD>, 8
      @DefProto DllImport, RpcServerInterfaceGroupInqBindings, WIN_STD_CALL_CONV,, <:RPC_INTERFACE_GROUP, :ptr ptr RPC_BINDING_VECTOR>, 8
    endif
  endif
  if _MSC_VER ge 1200
  endif
  include rpcdcep.inc
  ifdef __cplusplus
    ;[...]
  endif
endif
