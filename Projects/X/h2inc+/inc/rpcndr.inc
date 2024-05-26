;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\rpcndr.h
;             Created on (UTC) 22/05/2024 17:57:08
;             Last modified on (UTC) 12/02/2024 17:05:32

if _MSC_VER ge 1200
endif
ifndef __RPCNDR_H_VERSION__
  __RPCNDR_H_VERSION__ equ (501)
endif
ifndef __RPCNDR_H__
  __RPCNDR_H__ equ <>
  if _MSC_VER gt 1000
  endif
  ifdef __REQUIRED_RPCNDR_H_VERSION__
    if (__RPCNDR_H_VERSION__ lt __REQUIRED_RPCNDR_H_VERSION__)
      .err <incorrect < rpcndr.h > version. Use the header that matches with the MIDL compiler.>
    endif
  endif
  include winapifamily.inc
  include pshpack8.inc
  include basetsd.inc
  if  not Defined(_KRPCENV_)
    include rpcnsip.inc
  endif
  include rpcsal.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    NDR_CHAR_REP_MASK equ 0000000Fh
    NDR_INT_REP_MASK equ 000000F0h
    NDR_FLOAT_REP_MASK equ 0000FF00h
    NDR_LITTLE_ENDIAN equ 00000010h
    NDR_BIG_ENDIAN equ 00000000h
    NDR_IEEE_FLOAT equ 00000000h
    NDR_VAX_FLOAT equ 00000100h
    NDR_IBM_FLOAT equ 00000300h
    NDR_ASCII_CHAR equ 00000000h
    NDR_EBCDIC_CHAR equ 00000001h
    if Defined(__RPC_MAC__)
      NDR_LOCAL_DATA_REPRESENTATION equ 00000000h
      NDR_LOCAL_ENDIAN equ <NDR_BIG_ENDIAN>
    else
      NDR_LOCAL_DATA_REPRESENTATION equ 00000010h
      NDR_LOCAL_ENDIAN equ <NDR_LITTLE_ENDIAN>
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_NI)
      TARGET_IS_NT1012_OR_LATER equ 1
    else
      TARGET_IS_NT1012_OR_LATER equ 0
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_RS1)
      TARGET_IS_NT102_OR_LATER equ 1
    else
      TARGET_IS_NT102_OR_LATER equ 0
    endif
    if (0A00h le _WIN32_WINNT)
      TARGET_IS_NT100_OR_LATER equ 1
    else
      TARGET_IS_NT100_OR_LATER equ 0
    endif
    if (603h le _WIN32_WINNT)
      TARGET_IS_NT63_OR_LATER equ 1
    else
      TARGET_IS_NT63_OR_LATER equ 0
    endif
    if (602h le _WIN32_WINNT)
      TARGET_IS_NT62_OR_LATER equ 1
    else
      TARGET_IS_NT62_OR_LATER equ 0
    endif
    if (601h le _WIN32_WINNT)
      TARGET_IS_NT61_OR_LATER equ 1
    else
      TARGET_IS_NT61_OR_LATER equ 0
    endif
    if (600h le _WIN32_WINNT)
      TARGET_IS_NT60_OR_LATER equ 1
    else
      TARGET_IS_NT60_OR_LATER equ 0
    endif
    if (501h le _WIN32_WINNT)
      TARGET_IS_NT51_OR_LATER equ 1
    else
      TARGET_IS_NT51_OR_LATER equ 0
    endif
    if (500h le _WIN32_WINNT)
      TARGET_IS_NT50_OR_LATER equ 1
    else
      TARGET_IS_NT50_OR_LATER equ 0
    endif
    if (Defined(_WIN32_DCOM) or 400h le _WIN32_WINNT)
      TARGET_IS_NT40_OR_LATER equ 1
    else
      TARGET_IS_NT40_OR_LATER equ 0
    endif
    if (400h le WINVER)
      TARGET_IS_NT351_OR_WIN95_OR_LATER equ 1
    else
      TARGET_IS_NT351_OR_WIN95_OR_LATER equ 0
    endif
    small_ equ <char>
    byte typedef BYTE
    cs_byte typedef byte
    boolean typedef BYTE
    ifndef _HYPER_DEFINED
      _HYPER_DEFINED equ <>
      if ( not Defined(_M_IX86) or (Defined(_INTEGRAL_MAX_BITS) and _INTEGRAL_MAX_BITS ge 64))
        hyper equ <__int64>
        MIDL_uhyper equ <unsigned __int64>
      else
        hyper typedef REAL8
        MIDL_uhyper typedef REAL8
      endif
    endif
    ifndef _WCHAR_T_DEFINED
      wchar_t typedef WORD
      _WCHAR_T_DEFINED equ <>
    endif
    ifndef _SIZE_T_DEFINED
      if Defined(__RPC_WIN64__) or Defined(__RPC_ARM64__)
        size_t typedef QWORD
      else
        size_t typedef DWORD
      endif
      _SIZE_T_DEFINED equ <>
    endif
    ifdef __RPC_WIN32__
      if (_MSC_VER ge 800) or Defined(_STDCALL_SUPPORTED)
        __RPC_CALLEE equ <__stdcall>
      else
        __RPC_CALLEE equ <>
      endif
    endif
    ifndef __MIDL_USER_DEFINED
      midl_user_allocate equ <MIDL_user_allocate>
      midl_user_free equ <MIDL_user_free>
      __MIDL_USER_DEFINED equ <>
    endif
    MIDL_user_allocate proto WIN_STD_CALL_CONV :size_t
    MIDL_user_free proto WIN_STD_CALL_CONV :ptr
    I_RpcDefaultAllocate proto WIN_STD_CALL_CONV :handle_t, :size_t, :POINTER
    I_RpcDefaultFree proto WIN_STD_CALL_CONV :handle_t, :ptr, :POINTER
    RPC_VAR_ENTRY equ <__cdecl>
    if Defined(_M_IX86) or Defined(_M_AMD64) or Defined(_M_IA64)
      __MIDL_DECLSPEC_DLLIMPORT equ <__declspec(dllimport)>
      __MIDL_DECLSPEC_DLLEXPORT equ <__declspec(dllexport)>
    else
      __MIDL_DECLSPEC_DLLIMPORT equ <>
      __MIDL_DECLSPEC_DLLEXPORT equ <>
    endif
    NDR_CCONTEXT typedef ptr
    _NDR_SCONTEXT struct
      pad POINTER 2 dup (?)
      userContext POINTER ?
    _NDR_SCONTEXT ends
    NDR_SCONTEXT typedef ptr _NDR_SCONTEXT
    NDRSContextValue macro hContext
      exitm <(and (hContext) - userContext)>
    endm
    cbNDRContext equ 20
    TYPE_NDR_RUNDOWN typedef proto WIN_STD_CALL_CONV :ptr
    NDR_RUNDOWN typedef ptr TYPE_NDR_RUNDOWN

    TYPE_NDR_NOTIFY_ROUTINE typedef proto WIN_STD_CALL_CONV
    NDR_NOTIFY_ROUTINE typedef ptr TYPE_NDR_NOTIFY_ROUTINE

    TYPE_NDR_NOTIFY2_ROUTINE typedef proto WIN_STD_CALL_CONV :boolean
    NDR_NOTIFY2_ROUTINE typedef ptr TYPE_NDR_NOTIFY2_ROUTINE

    SCONTEXT_QUEUE struct
      NumberOfObjects DWORD ?
      ArrayOfObjects POINTER ?
    SCONTEXT_QUEUE ends
    _SCONTEXT_QUEUE typedef SCONTEXT_QUEUE
    PSCONTEXT_QUEUE typedef ptr SCONTEXT_QUEUE
    @DefProto DllImport, NDRCContextBinding, WIN_STD_CALL_CONV,, <:NDR_CCONTEXT>, 4
    @DefProto DllImport, NDRCContextMarshall, WIN_STD_CALL_CONV,, <:NDR_CCONTEXT, :ptr>, 8
    @DefProto DllImport, NDRCContextUnmarshall, WIN_STD_CALL_CONV,, <:ptr NDR_CCONTEXT, :RPC_BINDING_HANDLE, :ptr, :DWORD>, 16
    @DefProto DllImport, NDRCContextUnmarshall2, WIN_STD_CALL_CONV,, <:ptr NDR_CCONTEXT, :RPC_BINDING_HANDLE, :ptr, :DWORD>, 16
    @DefProto DllImport, NDRSContextMarshall, WIN_STD_CALL_CONV,, <:NDR_SCONTEXT, :ptr, :NDR_RUNDOWN>, 12
    @DefProto DllImport, NDRSContextUnmarshall, WIN_STD_CALL_CONV,, <:ptr, :DWORD>, 8
    @DefProto DllImport, NDRSContextMarshallEx, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :NDR_SCONTEXT, :ptr, :NDR_RUNDOWN>, 16
    @DefProto DllImport, NDRSContextMarshall2, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :NDR_SCONTEXT, :ptr, :NDR_RUNDOWN, :ptr, :DWORD>, 24
    @DefProto DllImport, NDRSContextUnmarshallEx, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr, :DWORD>, 12
    @DefProto DllImport, NDRSContextUnmarshall2, WIN_STD_CALL_CONV,, <:RPC_BINDING_HANDLE, :ptr, :DWORD, :ptr, :DWORD>, 20
    @DefProto DllImport, RpcSsDestroyClientContext, WIN_STD_CALL_CONV,, <:ptr ptr>, 4
    byte_from_ndr macro source, target
      exitm <{ * (target) = * (* and (source) - Buffer) + ; }>
    endm
    byte_array_from_ndr macro Source, LowerIndex, UpperIndex, Target
      exitm <{ NDRcopy ((((Target)) + (LowerIndex)), (Source) - Buffer, ((UpperIndex) - (LowerIndex))) ; * and (Source) - Buffer + ((UpperIndex) - (LowerIndex)) ; }>
    endm
    boolean_from_ndr macro source, target
      exitm <{ * (target) = * (* and (source) - Buffer) + ; }>
    endm
    boolean_array_from_ndr macro Source, LowerIndex, UpperIndex, Target
      exitm <{ NDRcopy ((((Target)) + (LowerIndex)), (Source) - Buffer, ((UpperIndex) - (LowerIndex))) ; * and (Source) - Buffer + ((UpperIndex) - (LowerIndex)) ; }>
    endm
    small_from_ndr macro source, target
      exitm <{ * (target) = * (* and (source) - Buffer) + ; }>
    endm
    small_from_ndr_temp macro source, target, format
      exitm <{ * (target) = * (* (source)) + ; }>
    endm
    small_array_from_ndr macro Source, LowerIndex, UpperIndex, Target
      exitm <{ NDRcopy ((((Target)) + (LowerIndex)), (Source) - Buffer, ((UpperIndex) - (LowerIndex))) ; * and (Source) - Buffer + ((UpperIndex) - (LowerIndex)) ; }>
    endm
    if Defined(__RPC_WIN32__) or Defined(__RPC_WIN64__) or Defined(__RPC_ARM32__) or Defined(__RPC_ARM64__)
      MIDL_ascii_strlen macro string
        exitm <strlen (string)>
      endm
      MIDL_ascii_strcpy macro target, source
        exitm <strcpy (target, source)>
      endm
      MIDL_memset macro s, c_, n
        exitm <memset (s, c_, n)>
      endm
    endif
    error_status_t typedef DWORD
    _midl_ma1 macro p, cast
      exitm <* (* (cast * *) and p) +>
    endm
    _midl_ma2 macro p, cast
      exitm <* (* (cast * *) and p) +>
    endm
    _midl_ma4 macro p, cast
      exitm <* (* (cast * *) and p) +>
    endm
    _midl_ma8 macro p, cast
      exitm <* (* (cast * *) and p) +>
    endm
    _midl_unma1 macro p, cast
      exitm <* ((cast *) p) +>
    endm
    _midl_unma2 macro p, cast
      exitm <* ((cast *) p) +>
    endm
    _midl_unma3 macro p, cast
      exitm <* ((cast *) p) +>
    endm
    _midl_unma4 macro p, cast
      exitm <* ((cast *) p) +>
    endm
    _midl_fa2 macro p
      exitm <(p = (RPC_BUFPTR) ((p + 1) and not 1h))>
    endm
    _midl_fa4 macro p
      exitm <(p = (RPC_BUFPTR) ((p + 3) and not 3h))>
    endm
    _midl_fa8 macro p
      exitm <(p = (RPC_BUFPTR) ((p + 7) and not 7h))>
    endm
    _midl_addp macro p, n
      exitm <(p + n)>
    endm
    _midl_marsh_lhs macro p, cast
      exitm <* (* (cast * *) and p) +>
    endm
    _midl_marsh_up macro mp, p
      exitm <* (* and mp) + = p>
    endm
    _midl_advmp macro mp
      exitm <* (* and mp) +>
    endm
    _midl_unmarsh_up macro p
      exitm <(* (* and p) +)>
    endm
    NdrMarshConfStringHdr macro p, s, l
      exitm <(_midl_ma4(p, unsigned long) = s, _midl_ma4(p, unsigned long) = 0, _midl_ma4(p, unsigned long) = l)>
    endm
    NdrUnMarshConfStringHdr macro p, s, l
      exitm <((s = _midl_unma4(p, unsigned long), (_midl_addp(p, 4)), (l = _midl_unma4(p, unsigned long))>
    endm
    NdrMarshCCtxtHdl macro pc, p
      exitm <(NDRCContextMarshall ((NDR_CCONTEXT) pc, p), p + 20)>
    endm
    NdrUnMarshCCtxtHdl macro pc, p, h, drep
      exitm <(NDRCContextUnmarshall ((NDR_CONTEXT) pc, h, p, drep), p + 20)>
    endm
    NdrUnMarshSCtxtHdl macro pc, p, drep
      exitm <(pc = NdrSContextUnMarshall (p, drep))>
    endm
    NdrMarshSCtxtHdl macro pc, p, rd
      exitm <(NdrSContextMarshall ((NDR_SCONTEXT) pc, p, (NDR_RUNDOWN) rd)>
    endm
    NdrFieldOffset macro s, f
      exitm <(and (((s *) 0) - f))>
    endm
    NdrFieldPad macro s, f, p, t
      exitm <((NdrFieldOffset(s, f) - NdrFieldOffset(s, p)) - sizeof(t))>
    endm
    NdrFcShort macro s
      exitm <(s and 0ffh), (s shr 8)>
    endm
    NdrFcLong macro s
      exitm <(s and 0ffh), ((s and 0000ff00h) shr 8), ((s and 00ff0000h) shr 16), (s shr 24)>
    endm
    RPC_BAD_STUB_DATA_EXCEPTION_FILTER equ ((RpcExceptionCode () eq STATUS_ACCESS_VIOLATION) or (RpcExceptionCode () eq STATUS_DATATYPE_MISALIGNMENT) or (RpcExceptionCode () eq RPC_X_BAD_STUB_DATA) or (RpcExceptionCode () eq RPC_S_INVALID_BOUND))
    RPC_BUFPTR typedef ptr BYTE
    RPC_LENGTH typedef DWORD
    TYPE_EXPR_EVAL typedef proto WIN_STD_CALL_CONV :ptr _MIDL_STUB_MESSAGE
    EXPR_EVAL typedef ptr TYPE_EXPR_EVAL

    PFORMAT_STRING typedef ptr BYTE
    ARRAY_INFO struct
      Dimension SDWORD ?
      BufferConformanceMark POINTER ?
      BufferVarianceMark POINTER ?
      MaxCountArray POINTER ?
      OffsetArray POINTER ?
      ActualCountArray POINTER ?
    ARRAY_INFO ends
    PARRAY_INFO typedef ptr ARRAY_INFO
    PNDR_ASYNC_MESSAGE typedef ptr _NDR_ASYNC_MESSAGE
    PNDR_CORRELATION_INFO typedef ptr _NDR_CORRELATION_INFO
    PFORMAT_STRING typedef ptr BYTE
    MIDL_SYNTAX_INFO typedef _MIDL_SYNTAX_INFO
    PMIDL_SYNTAX_INFO typedef ptr _MIDL_SYNTAX_INFO
    MIDL_STUB_MESSAGE struct
      RpcMsg PRPC_MESSAGE ?
      Buffer POINTER ?
      BufferStart POINTER ?
      BufferEnd POINTER ?
      BufferMark POINTER ?
      BufferLength DWORD ?
      MemorySize DWORD ?
      Memory_ POINTER ?
      IsClient BYTE ?
      Pad BYTE ?
      uFlags2 WORD ?
      ReuseBuffer SDWORD ?
      pAllocAllNodesContext POINTER ?
      pPointerQueueState POINTER ?
      IgnoreEmbeddedPointers SDWORD ?
      PointerBufferMark POINTER ?
      CorrDespIncrement BYTE ?
      uFlags BYTE ?
      UniquePtrCount WORD ?
      MaxCount ULONG_PTR ?
      Offset_ DWORD ?
      ActualCount DWORD ?
      TYPE_pfnAllocate typedef proto WIN_STD_CALL_CONV :size_t
      pfnAllocate typedef ptr TYPE_pfnAllocate

      TYPE_pfnFree typedef proto WIN_STD_CALL_CONV :ptr
      pfnFree typedef ptr TYPE_pfnFree

      StackTop POINTER ?
      pPresentedType POINTER ?
      pTransmitType POINTER ?
      SavedHandle handle_t ?
      StubDesc POINTER ?
      FullPtrXlatTables POINTER ?
      FullPtrRefId DWORD ?
      PointerLength DWORD ?
      MIDL_STUB_MESSAGE_REC record MIDL_STUB_MESSAGE_REC_fUnused3:16, MIDL_STUB_MESSAGE_REC_fUnused2:3, MIDL_STUB_MESSAGE_REC_fNeedMCCP:1, MIDL_STUB_MESSAGE_REC_fInFree:1, MIDL_STUB_MESSAGE_REC_fHasMemoryValidateCallback:1, MIDL_STUB_MESSAGE_REC_fBufferValid:1, MIDL_STUB_MESSAGE_REC_fIsOicf:1, MIDL_STUB_MESSAGE_REC_fIsOut:1, MIDL_STUB_MESSAGE_REC_fIsIn:1, MIDL_STUB_MESSAGE_REC_fHasNewCorrDesc:1, MIDL_STUB_MESSAGE_REC_fHasExtensions:1, MIDL_STUB_MESSAGE_REC_fHasReturn:1, MIDL_STUB_MESSAGE_REC_fUnused1:1, MIDL_STUB_MESSAGE_REC_fDontCallFreeInst:1, MIDL_STUB_MESSAGE_REC_fInDontFree:1
      MIDL_STUB_MESSAGE_BITS MIDL_STUB_MESSAGE_REC <>
      dwDestContext DWORD ?
      pvDestContext POINTER ?
      SavedContextHandles POINTER ?
      ParamNumber SDWORD ?
      pRpcChannelBuffer POINTER ?
      pArrayInfo PARRAY_INFO ?
      SizePtrCountArray POINTER ?
      SizePtrOffsetArray POINTER ?
      SizePtrLengthArray POINTER ?
      pArgQueue POINTER ?
      dwStubPhase DWORD ?
      LowStackMark POINTER ?
      pAsyncMsg PNDR_ASYNC_MESSAGE ?
      pCorrInfo PNDR_CORRELATION_INFO ?
      pCorrMemory POINTER ?
      pMemoryList POINTER ?
      pCSInfo INT_PTR ?
      ConformanceMark POINTER ?
      VarianceMark POINTER ?
      Unused INT_PTR ?
      pContext POINTER ?
      ContextHandleHash POINTER ?
      pUserMarshalList POINTER ?
      Reserved51_3 INT_PTR ?
      Reserved51_4 INT_PTR ?
      Reserved51_5 INT_PTR ?
    MIDL_STUB_MESSAGE ends
    _MIDL_STUB_MESSAGE typedef MIDL_STUB_MESSAGE
    PMIDL_STUB_MESSAGE typedef ptr MIDL_STUB_MESSAGE
    MIDL_STUB_MESSAGE typedef _MIDL_STUB_MESSAGE
    PMIDL_STUB_MESSAGE typedef ptr _MIDL_STUB_MESSAGE
    TYPE_GENERIC_BINDING_ROUTINE typedef proto WIN_STD_CALL_CONV :ptr
    GENERIC_BINDING_ROUTINE typedef ptr TYPE_GENERIC_BINDING_ROUTINE

    TYPE_GENERIC_UNBIND_ROUTINE typedef proto WIN_STD_CALL_CONV :ptr, :ptr BYTE
    GENERIC_UNBIND_ROUTINE typedef ptr TYPE_GENERIC_UNBIND_ROUTINE

    GENERIC_BINDING_ROUTINE_PAIR struct
      pfnBind GENERIC_BINDING_ROUTINE ?
      pfnUnbind GENERIC_UNBIND_ROUTINE ?
    GENERIC_BINDING_ROUTINE_PAIR ends
    _GENERIC_BINDING_ROUTINE_PAIR typedef GENERIC_BINDING_ROUTINE_PAIR
    PGENERIC_BINDING_ROUTINE_PAIR typedef ptr GENERIC_BINDING_ROUTINE_PAIR
    GENERIC_BINDING_INFO struct
      pObj POINTER ?
      Size_ DWORD ?
      pfnBind GENERIC_BINDING_ROUTINE ?
      pfnUnbind GENERIC_UNBIND_ROUTINE ?
    GENERIC_BINDING_INFO ends
    __GENERIC_BINDING_INFO typedef GENERIC_BINDING_INFO
    PGENERIC_BINDING_INFO typedef ptr GENERIC_BINDING_INFO
    ifdef __cplusplus
      ;[...]
    elseif (Defined(_MSC_VER)) and  not Defined(MIDL_PASS)
      NDR_SHAREABLE equ <__inline>
    else
      NDR_SHAREABLE equ <static>
    endif
    TYPE_XMIT_HELPER_ROUTINE typedef proto WIN_STD_CALL_CONV :PMIDL_STUB_MESSAGE
    XMIT_HELPER_ROUTINE typedef ptr TYPE_XMIT_HELPER_ROUTINE

    XMIT_ROUTINE_QUINTUPLE struct
      pfnTranslateToXmit XMIT_HELPER_ROUTINE ?
      pfnTranslateFromXmit XMIT_HELPER_ROUTINE ?
      pfnFreeXmit XMIT_HELPER_ROUTINE ?
      pfnFreeInst XMIT_HELPER_ROUTINE ?
    XMIT_ROUTINE_QUINTUPLE ends
    _XMIT_ROUTINE_QUINTUPLE typedef XMIT_ROUTINE_QUINTUPLE
    PXMIT_ROUTINE_QUINTUPLE typedef ptr XMIT_ROUTINE_QUINTUPLE
    TYPE_USER_MARSHAL_SIZING_ROUTINE typedef proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr
    USER_MARSHAL_SIZING_ROUTINE typedef ptr TYPE_USER_MARSHAL_SIZING_ROUTINE

    TYPE_USER_MARSHAL_MARSHALLING_ROUTINE typedef proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr
    USER_MARSHAL_MARSHALLING_ROUTINE typedef ptr TYPE_USER_MARSHAL_MARSHALLING_ROUTINE

    TYPE_USER_MARSHAL_UNMARSHALLING_ROUTINE typedef proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr
    USER_MARSHAL_UNMARSHALLING_ROUTINE typedef ptr TYPE_USER_MARSHAL_UNMARSHALLING_ROUTINE

    TYPE_USER_MARSHAL_FREEING_ROUTINE typedef proto WIN_STD_CALL_CONV :ptr DWORD, :ptr
    USER_MARSHAL_FREEING_ROUTINE typedef ptr TYPE_USER_MARSHAL_FREEING_ROUTINE

    USER_MARSHAL_ROUTINE_QUADRUPLE struct
      pfnBufferSize USER_MARSHAL_SIZING_ROUTINE ?
      pfnMarshall USER_MARSHAL_MARSHALLING_ROUTINE ?
      pfnUnmarshall USER_MARSHAL_UNMARSHALLING_ROUTINE ?
      pfnFree USER_MARSHAL_FREEING_ROUTINE ?
    USER_MARSHAL_ROUTINE_QUADRUPLE ends
    _USER_MARSHAL_ROUTINE_QUADRUPLE typedef USER_MARSHAL_ROUTINE_QUADRUPLE
    USER_MARSHAL_CB_SIGNATURE equ <'USRC'>
    USER_MARSHAL_CB_TYPE typedef SDWORD
    USER_MARSHAL_CB_BUFFER_SIZE equ 0
    USER_MARSHAL_CB_MARSHALL equ 1
    USER_MARSHAL_CB_UNMARSHALL equ 2
    USER_MARSHAL_CB_FREE equ 3
    _USER_MARSHAL_CB_TYPE typedef USER_MARSHAL_CB_TYPE

    USER_MARSHAL_CB struct
      Flags DWORD ?
      pStubMsg PMIDL_STUB_MESSAGE ?
      pReserve PFORMAT_STRING ?
      Signature DWORD ?
      CBType USER_MARSHAL_CB_TYPE ?
      pFormat PFORMAT_STRING ?
      pTypeFormat PFORMAT_STRING ?
    USER_MARSHAL_CB ends
    _USER_MARSHAL_CB typedef USER_MARSHAL_CB
    USER_CALL_CTXT_MASK macro f
      exitm <((f) and 00ffh)>
    endm
    USER_CALL_AUX_MASK macro f
      exitm <((f) and 0ff00h)>
    endm
    GET_USER_DATA_REP macro f
      exitm <((f) shr 16)>
    endm
    USER_CALL_IS_ASYNC equ 0100h
    USER_CALL_NEW_CORRELATION_DESC equ 0200h
    TYPE_pfnAllocate typedef proto WIN_STD_CALL_CONV :size_t
    pfnAllocate typedef ptr TYPE_pfnAllocate

    void proto WIN_STD_CALL_CONV :ptr __RPC_USER
    COMM_FAULT_OFFSETS struct
      CommOffset SWORD ?
      FaultOffset SWORD ?
    COMM_FAULT_OFFSETS ends
    _COMM_FAULT_OFFSETS typedef COMM_FAULT_OFFSETS
    IDL_CS_CONVERT typedef SDWORD
    IDL_CS_NO_CONVERT equ 0
    IDL_CS_IN_PLACE_CONVERT equ 1
    IDL_CS_NEW_BUFFER_CONVERT equ 2
    _IDL_CS_CONVERT typedef IDL_CS_CONVERT

    TYPE_CS_TYPE_NET_SIZE_ROUTINE typedef proto WIN_STD_CALL_CONV :RPC_BINDING_HANDLE, :DWORD, :DWORD, :ptr IDL_CS_CONVERT, :ptr DWORD, :ptr error_status_t
    CS_TYPE_NET_SIZE_ROUTINE typedef ptr TYPE_CS_TYPE_NET_SIZE_ROUTINE

    TYPE_CS_TYPE_LOCAL_SIZE_ROUTINE typedef proto WIN_STD_CALL_CONV :RPC_BINDING_HANDLE, :DWORD, :DWORD, :ptr IDL_CS_CONVERT, :ptr DWORD, :ptr error_status_t
    CS_TYPE_LOCAL_SIZE_ROUTINE typedef ptr TYPE_CS_TYPE_LOCAL_SIZE_ROUTINE

    TYPE_CS_TYPE_TO_NETCS_ROUTINE typedef proto WIN_STD_CALL_CONV :RPC_BINDING_HANDLE, :DWORD, :ptr, :DWORD, :ptr byte, :ptr DWORD, :ptr error_status_t
    CS_TYPE_TO_NETCS_ROUTINE typedef ptr TYPE_CS_TYPE_TO_NETCS_ROUTINE

    TYPE_CS_TYPE_FROM_NETCS_ROUTINE typedef proto WIN_STD_CALL_CONV :RPC_BINDING_HANDLE, :DWORD, :ptr byte, :DWORD, :DWORD, :ptr, :ptr DWORD, :ptr error_status_t
    CS_TYPE_FROM_NETCS_ROUTINE typedef ptr TYPE_CS_TYPE_FROM_NETCS_ROUTINE

    TYPE_CS_TAG_GETTING_ROUTINE typedef proto WIN_STD_CALL_CONV :RPC_BINDING_HANDLE, :SDWORD, :ptr DWORD, :ptr DWORD, :ptr DWORD, :ptr error_status_t
    CS_TAG_GETTING_ROUTINE typedef ptr TYPE_CS_TAG_GETTING_ROUTINE

    RpcCsGetTags proto WIN_STD_CALL_CONV :RPC_BINDING_HANDLE, :SDWORD, :ptr DWORD, :ptr DWORD, :ptr DWORD, :ptr error_status_t
    NDR_CS_SIZE_CONVERT_ROUTINES struct
      pfnNetSize CS_TYPE_NET_SIZE_ROUTINE ?
      pfnToNetCs CS_TYPE_TO_NETCS_ROUTINE ?
      pfnLocalSize CS_TYPE_LOCAL_SIZE_ROUTINE ?
      pfnFromNetCs CS_TYPE_FROM_NETCS_ROUTINE ?
    NDR_CS_SIZE_CONVERT_ROUTINES ends
    _NDR_CS_SIZE_CONVERT_ROUTINES typedef NDR_CS_SIZE_CONVERT_ROUTINES
    NDR_CS_ROUTINES struct
      pSizeConvertRoutines POINTER ?
      pTagGettingRoutines POINTER ?
    NDR_CS_ROUTINES ends
    _NDR_CS_ROUTINES typedef NDR_CS_ROUTINES
    NDR_EXPR_DESC struct
      pOffset POINTER ?
      pFormatExpr PFORMAT_STRING ?
    NDR_EXPR_DESC ends
    _NDR_EXPR_DESC typedef NDR_EXPR_DESC
    MIDL_STUB_DESC struct
      RpcInterfaceInformation POINTER ?
      TYPE_pfnAllocate typedef proto WIN_STD_CALL_CONV :size_t
      pfnAllocate typedef ptr TYPE_pfnAllocate

      TYPE_pfnFree typedef proto WIN_STD_CALL_CONV :ptr
      pfnFree typedef ptr TYPE_pfnFree

      union IMPLICIT_HANDLE_INFO
        pAutoHandle POINTER ?
        pPrimitiveHandle POINTER ?
        pGenericBindingInfo PGENERIC_BINDING_INFO ?
      ends
      apfnNdrRundownRoutines POINTER ?
      aGenericBindingRoutinePairs POINTER ?
      apfnExprEval POINTER ?
      aXmitQuintuple POINTER ?
      pFormatTypes POINTER ?
      fCheckBounds SDWORD ?
      Version DWORD ?
      pMallocFreeStruct POINTER ?
      MIDLVersion SDWORD ?
      CommFaultOffsets POINTER ?
      aUserMarshalQuadruple POINTER ?
      NotifyRoutineTable POINTER ?
      mFlags ULONG_PTR ?
      CsRoutineTables POINTER ?
      ProxyServerInfo POINTER ?
      pExprInfo POINTER ?
    MIDL_STUB_DESC ends
    _MIDL_STUB_DESC typedef MIDL_STUB_DESC
    PMIDL_STUB_DESC typedef ptr MIDL_STUB_DESC
    PMIDL_XMIT_TYPE typedef ptr
    if Defined(_MSC_EXTENSIONS)
      if  not Defined(RC_INVOKED)
        if _MSC_VER ge 1200
        endif
      endif
      MIDL_FORMAT_STRING struct
        Pad SWORD ?
        Format BYTE 0 dup (?)
      MIDL_FORMAT_STRING ends
      _MIDL_FORMAT_STRING typedef MIDL_FORMAT_STRING
      if  not Defined(RC_INVOKED)
        if _MSC_VER ge 1200
        else
        endif
      endif
    endif
    TYPE_STUB_THUNK typedef proto WIN_STD_CALL_CONV :PMIDL_STUB_MESSAGE
    STUB_THUNK typedef ptr TYPE_STUB_THUNK

    ifndef _MANAGED
      TYPE_SERVER_ROUTINE typedef proto WIN_STD_CALL_CONV
      SERVER_ROUTINE typedef ptr TYPE_SERVER_ROUTINE

    else
      ;[...]
    endif
    MIDL_METHOD_PROPERTY struct
      Id DWORD ?
      Value ULONG_PTR ?
    MIDL_METHOD_PROPERTY ends
    _MIDL_METHOD_PROPERTY typedef MIDL_METHOD_PROPERTY
    PMIDL_METHOD_PROPERTY typedef ptr MIDL_METHOD_PROPERTY
    MIDL_METHOD_PROPERTY_MAP struct
      Count DWORD ?
      Properties POINTER ?
    MIDL_METHOD_PROPERTY_MAP ends
    _MIDL_METHOD_PROPERTY_MAP typedef MIDL_METHOD_PROPERTY_MAP
    PMIDL_METHOD_PROPERTY_MAP typedef ptr MIDL_METHOD_PROPERTY_MAP
    MIDL_INTERFACE_METHOD_PROPERTIES struct
      MethodCount WORD ?
      MethodProperties POINTER ?
    MIDL_INTERFACE_METHOD_PROPERTIES ends
    _MIDL_INTERFACE_METHOD_PROPERTIES typedef MIDL_INTERFACE_METHOD_PROPERTIES
    MIDL_SERVER_INFO struct
      pStubDesc PMIDL_STUB_DESC ?
      DispatchTable POINTER ?
      ProcString PFORMAT_STRING ?
      FmtStringOffset POINTER ?
      ThunkTable POINTER ?
      pTransferSyntax PRPC_SYNTAX_IDENTIFIER ?
      nCount ULONG_PTR ?
      pSyntaxInfo PMIDL_SYNTAX_INFO ?
    MIDL_SERVER_INFO ends
    _MIDL_SERVER_INFO_ typedef MIDL_SERVER_INFO
    PMIDL_SERVER_INFO typedef ptr MIDL_SERVER_INFO
    MIDL_STUBLESS_PROXY_INFO struct
      pStubDesc PMIDL_STUB_DESC ?
      ProcFormatString PFORMAT_STRING ?
      FormatStringOffset POINTER ?
      pTransferSyntax PRPC_SYNTAX_IDENTIFIER ?
      nCount ULONG_PTR ?
      pSyntaxInfo PMIDL_SYNTAX_INFO ?
    MIDL_STUBLESS_PROXY_INFO ends
    _MIDL_STUBLESS_PROXY_INFO typedef MIDL_STUBLESS_PROXY_INFO
    PMIDL_STUBLESS_PROXY_INFO typedef ptr MIDL_STUBLESS_PROXY_INFO
    MIDL_SYNTAX_INFO struct
      TransferSyntax RPC_SYNTAX_IDENTIFIER <>
      DispatchTable POINTER ?
      ProcString PFORMAT_STRING ?
      FmtStringOffset POINTER ?
      TypeString PFORMAT_STRING ?
      aUserMarshalQuadruple POINTER ?
      pMethodProperties POINTER ?
      pReserved2 ULONG_PTR ?
    MIDL_SYNTAX_INFO ends
    _MIDL_SYNTAX_INFO typedef MIDL_SYNTAX_INFO
    PMIDL_SYNTAX_INFO typedef ptr MIDL_SYNTAX_INFO
    PARAM_OFFSETTABLE typedef ptr WORD
    PPARAM_OFFSETTABLE typedef ptr WORD
    CLIENT_CALL_RETURN union
      Pointer POINTER ?
      Simple LONG_PTR ?
    CLIENT_CALL_RETURN ends
    _CLIENT_CALL_RETURN typedef CLIENT_CALL_RETURN
    XLAT_SIDE typedef SDWORD
    XLAT_SERVER equ 1
    XLAT_CLIENT equ 2

    FULL_PTR_XLAT_TABLES struct
      RefIdToPointer POINTER ?
      PointerToRefId POINTER ?
      NextRefId DWORD ?
      XlatSide XLAT_SIDE ?
    FULL_PTR_XLAT_TABLES ends
    _FULL_PTR_XLAT_TABLES typedef FULL_PTR_XLAT_TABLES
    PFULL_PTR_XLAT_TABLES typedef ptr FULL_PTR_XLAT_TABLES
    system_handle_t typedef SDWORD
    SYSTEM_HANDLE_FILE equ 0
    SYSTEM_HANDLE_SEMAPHORE equ 1
    SYSTEM_HANDLE_EVENT equ 2
    SYSTEM_HANDLE_MUTEX equ 3
    SYSTEM_HANDLE_PROCESS equ 4
    SYSTEM_HANDLE_TOKEN equ 5
    SYSTEM_HANDLE_SECTION equ 6
    SYSTEM_HANDLE_REG_KEY equ 7
    SYSTEM_HANDLE_THREAD equ 8
    SYSTEM_HANDLE_COMPOSITION_OBJECT equ 9
    SYSTEM_HANDLE_SOCKET equ 10
    SYSTEM_HANDLE_JOB equ 11
    SYSTEM_HANDLE_PIPE equ 12
    SYSTEM_HANDLE_MAX equ 12
    SYSTEM_HANDLE_INVALID equ 0FFh
    _system_handle_t typedef system_handle_t

    MidlInterceptionInfoVersionOne equ 1

    MidlWinrtTypeSerializationInfoVersionOne equ 1

    MIDL_WINRT_TYPE_SERIALIZATION_INFO_CURRENT_VERSION equ <MidlWinrtTypeSerializationInfoVersionOne>
    MIDL_INTERCEPTION_INFO struct
      Version DWORD ?
      ProcString PFORMAT_STRING ?
      ProcFormatOffsetTable POINTER ?
      ProcCount DWORD ?
      TypeString PFORMAT_STRING ?
    MIDL_INTERCEPTION_INFO ends
    _MIDL_INTERCEPTION_INFO typedef MIDL_INTERCEPTION_INFO
    PMIDL_INTERCEPTION_INFO typedef ptr MIDL_INTERCEPTION_INFO
    MIDL_WINRT_TYPE_SERIALIZATION_INFO struct
      Version DWORD ?
      TypeFormatString PFORMAT_STRING ?
      FormatStringSize WORD ?
      TypeOffset WORD ?
      StubDesc PMIDL_STUB_DESC ?
    MIDL_WINRT_TYPE_SERIALIZATION_INFO ends
    _MIDL_WINRT_TYPE_SERIALIZATION_INFO typedef MIDL_WINRT_TYPE_SERIALIZATION_INFO
    PMIDL_WINRT_TYPE_SERIALIZATION_INFO typedef ptr MIDL_WINRT_TYPE_SERIALIZATION_INFO
    NdrClientGetSupportedSyntaxes proto WIN_STD_CALL_CONV :ptr RPC_CLIENT_INTERFACE, :ptr DWORD, :ptr ptr MIDL_SYNTAX_INFO
    NdrServerGetSupportedSyntaxes proto WIN_STD_CALL_CONV :ptr RPC_SERVER_INTERFACE, :ptr DWORD, :ptr ptr MIDL_SYNTAX_INFO, :ptr DWORD
    @DefProto DllImport, NdrSimpleTypeMarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :BYTE>, 12
    @DefProto DllImport, NdrPointerMarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrCsArrayMarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrCsTagMarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrSimpleStructMarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrConformantStructMarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrConformantVaryingStructMarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrComplexStructMarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrFixedArrayMarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrConformantArrayMarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrConformantVaryingArrayMarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrVaryingArrayMarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrComplexArrayMarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrNonConformantStringMarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrConformantStringMarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrEncapsulatedUnionMarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrNonEncapsulatedUnionMarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrByteCountPointerMarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrXmitOrRepAsMarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrUserMarshalMarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrInterfacePointerMarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrClientContextMarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :NDR_CCONTEXT, :SDWORD>, 12
    @DefProto DllImport, NdrServerContextMarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :NDR_SCONTEXT, :NDR_RUNDOWN>, 12
    @DefProto DllImport, NdrServerContextNewMarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :NDR_SCONTEXT, :NDR_RUNDOWN, :PFORMAT_STRING>, 16
    @DefProto DllImport, NdrSimpleTypeUnmarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :BYTE>, 12
    @DefProto DllImport, NdrCsArrayUnmarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr ptr BYTE, :PFORMAT_STRING, :BYTE>, 16
    @DefProto DllImport, NdrCsTagUnmarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr ptr BYTE, :PFORMAT_STRING, :BYTE>, 16
    @DefProto DllImport, NdrRangeUnmarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr ptr BYTE, :PFORMAT_STRING, :BYTE>, 16
    @DefProto DllImport, NdrCorrelationInitialize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr, :DWORD, :DWORD>, 16
    @DefProto DllImport, NdrCorrelationPass, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE>, 4
    @DefProto DllImport, NdrCorrelationFree, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE>, 4
    @DefProto DllImport, NdrPointerUnmarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr ptr BYTE, :PFORMAT_STRING, :BYTE>, 16
    @DefProto DllImport, NdrSimpleStructUnmarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr ptr BYTE, :PFORMAT_STRING, :BYTE>, 16
    @DefProto DllImport, NdrConformantStructUnmarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr ptr BYTE, :PFORMAT_STRING, :BYTE>, 16
    @DefProto DllImport, NdrConformantVaryingStructUnmarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr ptr BYTE, :PFORMAT_STRING, :BYTE>, 16
    @DefProto DllImport, NdrComplexStructUnmarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr ptr BYTE, :PFORMAT_STRING, :BYTE>, 16
    @DefProto DllImport, NdrFixedArrayUnmarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr ptr BYTE, :PFORMAT_STRING, :BYTE>, 16
    @DefProto DllImport, NdrConformantArrayUnmarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr ptr BYTE, :PFORMAT_STRING, :BYTE>, 16
    @DefProto DllImport, NdrConformantVaryingArrayUnmarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr ptr BYTE, :PFORMAT_STRING, :BYTE>, 16
    @DefProto DllImport, NdrVaryingArrayUnmarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr ptr BYTE, :PFORMAT_STRING, :BYTE>, 16
    @DefProto DllImport, NdrComplexArrayUnmarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr ptr BYTE, :PFORMAT_STRING, :BYTE>, 16
    @DefProto DllImport, NdrNonConformantStringUnmarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr ptr BYTE, :PFORMAT_STRING, :BYTE>, 16
    @DefProto DllImport, NdrConformantStringUnmarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr ptr BYTE, :PFORMAT_STRING, :BYTE>, 16
    @DefProto DllImport, NdrEncapsulatedUnionUnmarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr ptr BYTE, :PFORMAT_STRING, :BYTE>, 16
    @DefProto DllImport, NdrNonEncapsulatedUnionUnmarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr ptr BYTE, :PFORMAT_STRING, :BYTE>, 16
    @DefProto DllImport, NdrByteCountPointerUnmarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr ptr BYTE, :PFORMAT_STRING, :BYTE>, 16
    @DefProto DllImport, NdrXmitOrRepAsUnmarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr ptr BYTE, :PFORMAT_STRING, :BYTE>, 16
    @DefProto DllImport, NdrUserMarshalUnmarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr ptr BYTE, :PFORMAT_STRING, :BYTE>, 16
    @DefProto DllImport, NdrInterfacePointerUnmarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr ptr BYTE, :PFORMAT_STRING, :BYTE>, 16
    @DefProto DllImport, NdrClientContextUnmarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr NDR_CCONTEXT, :RPC_BINDING_HANDLE>, 12
    @DefProto DllImport, NdrServerContextUnmarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE>, 4
    @DefProto DllImport, NdrContextHandleInitialize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :PFORMAT_STRING>, 8
    @DefProto DllImport, NdrServerContextNewUnmarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :PFORMAT_STRING>, 8
    @DefProto DllImport, NdrPointerBufferSize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrCsArrayBufferSize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrCsTagBufferSize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrSimpleStructBufferSize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrConformantStructBufferSize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrConformantVaryingStructBufferSize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrComplexStructBufferSize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrFixedArrayBufferSize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrConformantArrayBufferSize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrConformantVaryingArrayBufferSize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrVaryingArrayBufferSize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrComplexArrayBufferSize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrConformantStringBufferSize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrNonConformantStringBufferSize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrEncapsulatedUnionBufferSize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrNonEncapsulatedUnionBufferSize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrByteCountPointerBufferSize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrXmitOrRepAsBufferSize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrUserMarshalBufferSize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrInterfacePointerBufferSize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrContextHandleSize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrPointerMemorySize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :PFORMAT_STRING>, 8
    @DefProto DllImport, NdrContextHandleMemorySize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :PFORMAT_STRING>, 8
    @DefProto DllImport, NdrCsArrayMemorySize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :PFORMAT_STRING>, 8
    @DefProto DllImport, NdrCsTagMemorySize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :PFORMAT_STRING>, 8
    @DefProto DllImport, NdrSimpleStructMemorySize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :PFORMAT_STRING>, 8
    @DefProto DllImport, NdrConformantStructMemorySize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :PFORMAT_STRING>, 8
    @DefProto DllImport, NdrConformantVaryingStructMemorySize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :PFORMAT_STRING>, 8
    @DefProto DllImport, NdrComplexStructMemorySize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :PFORMAT_STRING>, 8
    @DefProto DllImport, NdrFixedArrayMemorySize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :PFORMAT_STRING>, 8
    @DefProto DllImport, NdrConformantArrayMemorySize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :PFORMAT_STRING>, 8
    @DefProto DllImport, NdrConformantVaryingArrayMemorySize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :PFORMAT_STRING>, 8
    @DefProto DllImport, NdrVaryingArrayMemorySize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :PFORMAT_STRING>, 8
    @DefProto DllImport, NdrComplexArrayMemorySize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :PFORMAT_STRING>, 8
    @DefProto DllImport, NdrConformantStringMemorySize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :PFORMAT_STRING>, 8
    @DefProto DllImport, NdrNonConformantStringMemorySize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :PFORMAT_STRING>, 8
    @DefProto DllImport, NdrEncapsulatedUnionMemorySize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :PFORMAT_STRING>, 8
    @DefProto DllImport, NdrNonEncapsulatedUnionMemorySize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :PFORMAT_STRING>, 8
    @DefProto DllImport, NdrXmitOrRepAsMemorySize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :PFORMAT_STRING>, 8
    @DefProto DllImport, NdrUserMarshalMemorySize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :PFORMAT_STRING>, 8
    @DefProto DllImport, NdrInterfacePointerMemorySize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :PFORMAT_STRING>, 8
    @DefProto DllImport, NdrPointerFree, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrCsArrayFree, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrSimpleStructFree, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrConformantStructFree, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrConformantVaryingStructFree, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrComplexStructFree, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrFixedArrayFree, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrConformantArrayFree, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrConformantVaryingArrayFree, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrVaryingArrayFree, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrComplexArrayFree, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrEncapsulatedUnionFree, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrNonEncapsulatedUnionFree, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrByteCountPointerFree, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrXmitOrRepAsFree, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrUserMarshalFree, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrInterfacePointerFree, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :PFORMAT_STRING>, 12
    @DefProto DllImport, NdrConvert2, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :PFORMAT_STRING, :SDWORD>, 12
    @DefProto DllImport, NdrConvert, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :PFORMAT_STRING>, 8
    USER_MARSHAL_FC_BYTE equ 1
    USER_MARSHAL_FC_CHAR equ 2
    USER_MARSHAL_FC_SMALL equ 3
    USER_MARSHAL_FC_USMALL equ 4
    USER_MARSHAL_FC_WCHAR equ 5
    USER_MARSHAL_FC_SHORT equ 6
    USER_MARSHAL_FC_USHORT equ 7
    USER_MARSHAL_FC_LONG equ 8
    USER_MARSHAL_FC_ULONG equ 9
    USER_MARSHAL_FC_FLOAT equ 10
    USER_MARSHAL_FC_HYPER equ 11
    USER_MARSHAL_FC_DOUBLE equ 12
    @DefProto DllImport, NdrUserMarshalSimpleTypeConvert, WIN_STD_CALL_CONV,, <:ptr DWORD, :ptr BYTE, :BYTE>, 12
    @DefProto DllImport, NdrClientInitializeNew, WIN_STD_CALL_CONV,, <:PRPC_MESSAGE, :PMIDL_STUB_MESSAGE, :PMIDL_STUB_DESC, :DWORD>, 16
    @DefProto DllImport, NdrServerInitializeNew, WIN_STD_CALL_CONV,, <:PRPC_MESSAGE, :PMIDL_STUB_MESSAGE, :PMIDL_STUB_DESC>, 12
    @DefProto DllImport, NdrServerInitializePartial, WIN_STD_CALL_CONV,, <:PRPC_MESSAGE, :PMIDL_STUB_MESSAGE, :PMIDL_STUB_DESC, :DWORD>, 16
    @DefProto DllImport, NdrClientInitialize, WIN_STD_CALL_CONV,, <:PRPC_MESSAGE, :PMIDL_STUB_MESSAGE, :PMIDL_STUB_DESC, :DWORD>, 16
    @DefProto DllImport, NdrServerInitialize, WIN_STD_CALL_CONV,, <:PRPC_MESSAGE, :PMIDL_STUB_MESSAGE, :PMIDL_STUB_DESC>, 12
    @DefProto DllImport, NdrServerInitializeUnmarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :PMIDL_STUB_DESC, :PRPC_MESSAGE>, 12
    @DefProto DllImport, NdrServerInitializeMarshall, WIN_STD_CALL_CONV,, <:PRPC_MESSAGE, :PMIDL_STUB_MESSAGE>, 8
    @DefProto DllImport, NdrGetBuffer, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :DWORD, :RPC_BINDING_HANDLE>, 12
    @DefProto DllImport, NdrNsGetBuffer, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :DWORD, :RPC_BINDING_HANDLE>, 12
    @DefProto DllImport, NdrSendReceive, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE>, 8
    @DefProto DllImport, NdrNsSendReceive, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr BYTE, :ptr RPC_BINDING_HANDLE>, 12
    @DefProto DllImport, NdrFreeBuffer, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE>, 4
    @DefProto DllImport, NdrGetDcomProtocolVersion, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr RPC_VERSION>, 8
    NdrClientCall2 proto c :PMIDL_STUB_DESC, :PFORMAT_STRING, :vararg
    NdrClientCall proto c :PMIDL_STUB_DESC, :PFORMAT_STRING, :vararg
    NdrAsyncClientCall proto c :PMIDL_STUB_DESC, :PFORMAT_STRING, :vararg
    if ( not Defined(_WIN64) and  not Defined(_ARM_))
      NdrClientCall4 proto c :PMIDL_STUB_DESC, :PFORMAT_STRING, :vararg
      NdrAsyncClientCall2 proto c :PMIDL_STUB_DESC, :PFORMAT_STRING, :vararg
      NdrMesProcEncodeDecode4 proto c :handle_t, :ptr MIDL_STUB_DESC, :PFORMAT_STRING, :vararg
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    NdrDcomAsyncClientCall proto c :PMIDL_STUB_DESC, :PFORMAT_STRING, :vararg
    if ( not Defined(_WIN64) and  not Defined(_ARM_))
      NdrDcomAsyncClientCall2 proto c :PMIDL_STUB_DESC, :PFORMAT_STRING, :vararg
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    STUB_PHASE typedef SDWORD
    STUB_UNMARSHAL equ 0
    STUB_CALL_SERVER equ 1
    STUB_MARSHAL equ 2
    STUB_CALL_SERVER_NO_HRESULT equ 3

    PROXY_PHASE typedef SDWORD
    PROXY_CALCSIZE equ 0
    PROXY_GETBUFFER equ 1
    PROXY_MARSHAL equ 2
    PROXY_SENDRECEIVE equ 3
    PROXY_UNMARSHAL equ 4

    @DefProto DllImport, NdrAsyncServerCall, WIN_STD_CALL_CONV,, <:PRPC_MESSAGE>, 4
    @DefProto DllImport, NdrAsyncStubCall, WIN_STD_CALL_CONV,, <:ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD>, 16
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, NdrDcomAsyncStubCall, WIN_STD_CALL_CONV,, <:ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD>, 16
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, NdrStubCall2, WIN_STD_CALL_CONV,, <:ptr, :ptr, :PRPC_MESSAGE, :ptr DWORD>, 16
    @DefProto DllImport, NdrServerCall2, WIN_STD_CALL_CONV,, <:PRPC_MESSAGE>, 4
    @DefProto DllImport, NdrStubCall, WIN_STD_CALL_CONV,, <:ptr, :ptr, :PRPC_MESSAGE, :ptr DWORD>, 16
    @DefProto DllImport, NdrServerCall, WIN_STD_CALL_CONV,, <:PRPC_MESSAGE>, 4
    @DefProto DllImport, NdrServerUnmarshall, WIN_STD_CALL_CONV,, <:ptr, :PRPC_MESSAGE, :PMIDL_STUB_MESSAGE, :PMIDL_STUB_DESC, :PFORMAT_STRING, :ptr>, 24
    @DefProto DllImport, NdrServerMarshall, WIN_STD_CALL_CONV,, <:ptr, :ptr, :PMIDL_STUB_MESSAGE, :PFORMAT_STRING>, 16
    @DefProto DllImport, NdrMapCommAndFaultStatus, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr DWORD, :ptr DWORD, :RPC_STATUS>, 16
    RPC_SS_THREAD_HANDLE typedef ptr
    Size_ typedef ptr
    RPC_CLIENT_FREE typedef proto :ptr
    @DefProto DllImport, RpcSsAllocate, WIN_STD_CALL_CONV,, <:size_t>, 4
    @DefProto DllImport, RpcSsDisableAllocate, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, RpcSsEnableAllocate, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, RpcSsFree, WIN_STD_CALL_CONV,, <:ptr>, 4
    @DefProto DllImport, RpcSsGetThreadHandle, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, RpcSsSetClientAllocFree, WIN_STD_CALL_CONV,, <:ptr RPC_CLIENT_ALLOC, :ptr RPC_CLIENT_FREE>, 8
    @DefProto DllImport, RpcSsSetThreadHandle, WIN_STD_CALL_CONV,, <:RPC_SS_THREAD_HANDLE>, 4
    @DefProto DllImport, RpcSsSwapClientAllocFree, WIN_STD_CALL_CONV,, <:ptr RPC_CLIENT_ALLOC, :ptr RPC_CLIENT_FREE, :ptr ptr RPC_CLIENT_ALLOC, :ptr ptr RPC_CLIENT_FREE>, 16
    @DefProto DllImport, RpcSmAllocate, WIN_STD_CALL_CONV,, <:size_t, :ptr RPC_STATUS>, 8
    @DefProto DllImport, RpcSmClientFree, WIN_STD_CALL_CONV,, <:ptr>, 4
    @DefProto DllImport, RpcSmDestroyClientContext, WIN_STD_CALL_CONV,, <:ptr ptr>, 4
    @DefProto DllImport, RpcSmDisableAllocate, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, RpcSmEnableAllocate, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, RpcSmFree, WIN_STD_CALL_CONV,, <:ptr>, 4
    @DefProto DllImport, RpcSmGetThreadHandle, WIN_STD_CALL_CONV,, <:ptr RPC_STATUS>, 4
    @DefProto DllImport, RpcSmSetClientAllocFree, WIN_STD_CALL_CONV,, <:ptr RPC_CLIENT_ALLOC, :ptr RPC_CLIENT_FREE>, 8
    @DefProto DllImport, RpcSmSetThreadHandle, WIN_STD_CALL_CONV,, <:RPC_SS_THREAD_HANDLE>, 4
    @DefProto DllImport, RpcSmSwapClientAllocFree, WIN_STD_CALL_CONV,, <:ptr RPC_CLIENT_ALLOC, :ptr RPC_CLIENT_FREE, :ptr ptr RPC_CLIENT_ALLOC, :ptr ptr RPC_CLIENT_FREE>, 16
    @DefProto DllImport, NdrRpcSsEnableAllocate, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE>, 4
    @DefProto DllImport, NdrRpcSsDisableAllocate, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE>, 4
    @DefProto DllImport, NdrRpcSmSetClientToOsf, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE>, 4
    @DefProto DllImport, NdrRpcSmClientAllocate, WIN_STD_CALL_CONV,, <:size_t>, 4
    @DefProto DllImport, NdrRpcSmClientFree, WIN_STD_CALL_CONV,, <:ptr>, 4
    @DefProto DllImport, NdrRpcSsDefaultAllocate, WIN_STD_CALL_CONV,, <:size_t>, 4
    @DefProto DllImport, NdrRpcSsDefaultFree, WIN_STD_CALL_CONV,, <:ptr>, 4
    @DefProto DllImport, NdrFullPointerXlatInit, WIN_STD_CALL_CONV,, <:DWORD, :XLAT_SIDE>, 8
    @DefProto DllImport, NdrFullPointerXlatFree, WIN_STD_CALL_CONV,, <:PFULL_PTR_XLAT_TABLES>, 4
    @DefProto DllImport, NdrAllocate, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :size_t>, 8
    @DefProto DllImport, NdrClearOutParameters, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :PFORMAT_STRING, :ptr>, 12
    @DefProto DllImport, NdrOleAllocate, WIN_STD_CALL_CONV,, <:size_t>, 4
    @DefProto DllImport, NdrOleFree, WIN_STD_CALL_CONV,, <:ptr>, 4
    ifdef CONST_VTABLE
      CONST_VTBL equ <const>
    else
      CONST_VTBL equ <>
    endif
    ifndef DECLSPEC_SELECTANY
      if (_MSC_VER ge 1100)
        DECLSPEC_SELECTANY equ <__declspec(selectany)>
      else
        DECLSPEC_SELECTANY equ <>
      endif
    endif
    ifndef DECLSPEC_NOVTABLE
      if (_MSC_VER ge 1100) and Defined(__cplusplus)
        ;[...]
      else
        DECLSPEC_NOVTABLE equ <>
      endif
    endif
    ifndef DECLSPEC_UUID
      if (_MSC_VER ge 1100) and Defined(__cplusplus)
        ;[...]
      else
        DECLSPEC_UUID macro x
          exitm <>
        endm
      endif
    endif
    ifndef DECLSPEC_XFGVIRT
      if _CONTROL_FLOW_GUARD_XFG
        DECLSPEC_XFGVIRT macro base, func
          exitm <__declspec(xfg_virtual (base, func))>
        endm
      else
        DECLSPEC_XFGVIRT macro base, func
          exitm <>
        endm
      endif
    endif
    ifndef DECLSPEC_XFGREUSE
      if _CONTROL_FLOW_GUARD_XFG
        DECLSPEC_XFGREUSE macro vtbl, func
          exitm <__declspec(xfg_reuse_typehash (vtbl, func))>
        endm
      else
        DECLSPEC_XFGREUSE macro vtbl, func
          exitm <>
        endm
      endif
    endif
    MIDL_INTERFACE macro x
      exitm <struct DECLSPEC_UUID(x) DECLSPEC_NOVTABLE>
    endm
    if _MSC_VER ge 1100
      EXTERN_GUID macro itf, l1, s1, s2, c1, c2, c3, c4, c5, c6, c7, c8
        exitm <EXTERN_C const IID DECLSPEC_SELECTANY itf = { l1, s1, s2, { c1, c2, c3, c4, c5, c6, c7, c8 } }>
      endm
    else
      EXTERN_GUID macro itf, l1, s1, s2, c1, c2, c3, c4, c5, c6, c7, c8
        exitm <EXTERN_C const IID itf>
      endm
    endif
    if Defined(__cplusplus) and Defined(__cpp_inline_variables)
      ;[...]
    else
      if (_MSC_VER ge 1100)
        MIDL_CONSTINIT_CONST_INLINE_VARIABLE equ <EXTERN_C const __declspec(selectany)>
      else
        MIDL_CONSTINIT_CONST_INLINE_VARIABLE equ <static const>
      endif
    endif
    NDR_USER_MARSHAL_INFO_LEVEL1 struct
      Buffer POINTER ?
      BufferSize DWORD ?
      TYPE_pfnAllocate typedef proto WIN_STD_CALL_CONV :size_t
      pfnAllocate typedef ptr TYPE_pfnAllocate

      TYPE_pfnFree typedef proto WIN_STD_CALL_CONV :ptr
      pfnFree typedef ptr TYPE_pfnFree

      pRpcChannelBuffer POINTER ?
      Reserved ULONG_PTR 5 dup (?)
    NDR_USER_MARSHAL_INFO_LEVEL1 ends
    _NDR_USER_MARSHAL_INFO_LEVEL1 typedef NDR_USER_MARSHAL_INFO_LEVEL1
    if  not Defined(RC_INVOKED)
      if _MSC_VER ge 1200
      endif
    endif
    NDR_USER_MARSHAL_INFO struct
      InformationLevel DWORD ?
      union
        Level1 NDR_USER_MARSHAL_INFO_LEVEL1 <>
      ends
    NDR_USER_MARSHAL_INFO ends
    _NDR_USER_MARSHAL_INFO typedef NDR_USER_MARSHAL_INFO
    if  not Defined(RC_INVOKED)
      if _MSC_VER ge 1200
      else
      endif
    endif
    NdrGetUserMarshalInfo proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr NDR_USER_MARSHAL_INFO
    NdrCreateServerInterfaceFromStub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr RPC_SERVER_INTERFACE
    NdrClientCall3 proto c :ptr MIDL_STUBLESS_PROXY_INFO, :DWORD, :ptr, :vararg
    Ndr64AsyncClientCall proto c :ptr MIDL_STUBLESS_PROXY_INFO, :DWORD, :ptr, :vararg
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    Ndr64DcomAsyncClientCall proto c :ptr MIDL_STUBLESS_PROXY_INFO, :DWORD, :ptr, :vararg
    @DefProto DllImport, Ndr64AsyncServerCall, WIN_STD_CALL_CONV,, <:PRPC_MESSAGE>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, Ndr64AsyncServerCall64, WIN_STD_CALL_CONV,, <:PRPC_MESSAGE>, 4
    @DefProto DllImport, Ndr64AsyncServerCallAll, WIN_STD_CALL_CONV,, <:PRPC_MESSAGE>, 4
    @DefProto DllImport, Ndr64AsyncStubCall, WIN_STD_CALL_CONV,, <:ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD>, 16
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, Ndr64DcomAsyncStubCall, WIN_STD_CALL_CONV,, <:ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD>, 16
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, NdrStubCall3, WIN_STD_CALL_CONV,, <:ptr, :ptr, :PRPC_MESSAGE, :ptr DWORD>, 16
    @DefProto DllImport, NdrServerCallAll, WIN_STD_CALL_CONV,, <:PRPC_MESSAGE>, 4
    @DefProto DllImport, NdrServerCallNdr64, WIN_STD_CALL_CONV,, <:PRPC_MESSAGE>, 4
    @DefProto DllImport, NdrServerCall3, WIN_STD_CALL_CONV,, <:PRPC_MESSAGE>, 4
    @DefProto DllImport, NdrPartialIgnoreClientMarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr>, 8
    @DefProto DllImport, NdrPartialIgnoreServerUnmarshall, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr ptr>, 8
    @DefProto DllImport, NdrPartialIgnoreClientBufferSize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr>, 8
    @DefProto DllImport, NdrPartialIgnoreServerInitialize, WIN_STD_CALL_CONV,, <:PMIDL_STUB_MESSAGE, :ptr ptr, :PFORMAT_STRING>, 12
    RpcUserFree proto WIN_STD_CALL_CONV :handle_t, :ptr
  endif
  ifdef __cplusplus
    ;[...]
  endif
  include poppack.inc
endif
if _MSC_VER ge 1200
endif
