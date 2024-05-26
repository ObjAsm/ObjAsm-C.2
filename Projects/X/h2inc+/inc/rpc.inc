;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\rpc.h
;             Created on (UTC) 22/05/2024 17:57:08
;             Last modified on (UTC) 21/02/2024 18:13:14

if  not Defined(RPC_NO_WINDOWS_H) and  not Defined(MAC) and  not Defined(_MAC) and  not Defined(_KRPCENV_)
  ifndef _INC_WINDOWS
    include windows.inc
  endif
endif
ifndef __RPC_H__
  __RPC_H__ equ <>
  if _MSC_VER gt 1000
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if Defined(MAC) or Defined(_MAC)
    __RPC_MAC__ equ <>
    include pshpack2.inc
  else
    include basetsd.inc
    if Defined(_M_ARM64)
      ;[...]
    elseif Defined(_M_IA64) or Defined(_M_AMD64)
      __RPC_WIN64__ equ <>
    elseif Defined(_ARM_)
      ;[...]
    else
      __RPC_WIN32__ equ <>
    endif
  endif
  if Defined(__RPC_WIN64__) or Defined(__RPC_ARM64__)
    include pshpack8.inc
  endif
  ifndef __MIDL_USER_DEFINED
    midl_user_allocate equ <MIDL_user_allocate>
    midl_user_free equ <MIDL_user_free>
    __MIDL_USER_DEFINED equ <>
  endif
  I_RPC_HANDLE typedef ptr
  if Defined(__specstrings)
    RPC_STATUS typedef SDWORD
  else
    RPC_STATUS typedef SDWORD
  endif
  if Defined(__RPC_WIN32__) or Defined(__RPC_WIN64__) or Defined(__RPC_ARM32__) or Defined(__RPC_ARM64__)
    RPC_UNICODE_SUPPORTED equ <>
  endif
  if  not Defined(__RPC_MAC__) and ((_MSC_VER ge 800) or Defined(_STDCALL_SUPPORTED))
    __RPC_API equ <__stdcall>
    __RPC_USER equ <__stdcall>
    __RPC_STUB equ <__stdcall>
    RPC_ENTRY equ <__stdcall>
  else
    __RPC_API equ <>
    __RPC_USER equ <>
    __RPC_STUB equ <>
    RPC_ENTRY equ <>
  endif
  __RPC_FAR equ <>
  if  not Defined(DECLSPEC_IMPORT)
    if (Defined(_M_MRX000) or Defined(_M_IX86) or Defined(_M_IA64) or Defined(_M_AMD64) or Defined(_M_ARM) or Defined(_M_ARM64)) and  not Defined(MIDL_PASS)
      DECLSPEC_IMPORT equ <__declspec(dllimport)>
    else
      DECLSPEC_IMPORT equ <>
    endif
  endif
  if  not Defined(_RPCRT4_) and  not Defined(_KRPCENV_)
    RPCRTAPI equ <DECLSPEC_IMPORT>
  else
    RPCRTAPI equ <>
  endif
  if  not Defined(_RPCNS4_)
    RPCNSAPI equ <DECLSPEC_IMPORT>
  else
    RPCNSAPI equ <>
  endif
  ifdef __RPC_MAC__
    include setjmp.inc
    RPCXCWORD equ <(sizeof(jmp_buf) / sizeof(int))>
    if _MSC_VER ge 1200
    endif
    include rpcdce.inc
    include rpcnsi.inc
    include rpcerr.inc
    include rpcmac.inc
    if _MSC_VER ge 1200
    else
    endif
    TYPE_MACYIELDCALLBACK typedef proto WIN_STD_CALL_CONV :ptr SWORD
    MACYIELDCALLBACK typedef ptr TYPE_MACYIELDCALLBACK

    RpcMacSetYieldInfo proto WIN_STD_CALL_CONV :MACYIELDCALLBACK
    if  not Defined(UNALIGNED)
      UNALIGNED equ <>
    endif
    include poppack.inc
  else
    include rpcdce.inc
    if  not Defined(_KRPCENV_)
      include rpcnsi.inc
    endif
    include rpcnterr.inc
    include excpt.inc
    if  not Defined(_KRPCENV_)
      include winerror.inc
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      RpcTryExcept equ <__try {>
      RpcExcept macro expr
        exitm <} __except (expr) {>
      endm
      RpcEndExcept equ <}>
      RpcTryFinally equ <__try {>
      RpcFinally equ <} __finally {>
      RpcEndFinally equ <}>
      RpcExceptionCode macro 
        exitm <GetExceptionCode ()>
      endm
      RpcAbnormalTermination macro 
        exitm <AbnormalTermination ()>
      endm
    endif
  endif
  if (( not Defined(RPC_NO_WINDOWS_H) or Defined(RPC_NEED_RPCASYNC_H)) and  not Defined(__RPC_MAC__)) or Defined(_KRPCENV_)
    include rpcasync.inc
  endif
  if Defined(__RPC_WIN64__) or Defined(__RPC_ARM64__)
    include poppack.inc
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
