;Include file created by h2incX, Version B.01.02, 23/09/2018 18:52
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\StructuredQueryCondition.h', last modified: 19/04/2018 10:45
;Creation parameters:

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
ifndef __structuredquerycondition_h__
  __structuredquerycondition_h__ equ <>
  if Defined(_MSC_VER) and (_MSC_VER ge 1020)
  endif
  ifndef __IRichChunk_FWD_DEFINED__
    __IRichChunk_FWD_DEFINED__ equ <>
    ;IRichChunk typedef IRichChunk
  endif
  ifndef __ICondition_FWD_DEFINED__
    __ICondition_FWD_DEFINED__ equ <>
    ;ICondition typedef ICondition
  endif
  ifndef __ICondition2_FWD_DEFINED__
    __ICondition2_FWD_DEFINED__ equ <>
    ;ICondition2 typedef ICondition2
  endif
  include oaidl.inc
  include ocidl.inc
  include propidl.inc
  ifdef __cplusplus
    ;[...]
  endif
  include winapifamily.inc
  CONDITION_TYPE typedef SDWORD
  CT_AND_CONDITION equ 0
  CT_OR_CONDITION equ
  CT_NOT_CONDITION equ
  CT_LEAF_CONDITION equ
  tagCONDITION_TYPE typedef CONDITION_TYPE
  CONDITION_OPERATION typedef SDWORD
  COP_IMPLICIT equ 0
  COP_EQUAL equ
  COP_NOTEQUAL equ
  COP_LESSTHAN equ
  COP_GREATERTHAN equ
  COP_LESSTHANOREQUAL equ
  COP_GREATERTHANOREQUAL equ
  COP_VALUE_STARTSWITH equ
  COP_VALUE_ENDSWITH equ
  COP_VALUE_CONTAINS equ
  COP_VALUE_NOTCONTAINS equ
  COP_DOSWILDCARDS equ
  COP_WORD_EQUAL equ
  COP_WORD_STARTSWITH equ
  COP_APPLICATION_SPECIFIC equ
  tagCONDITION_OPERATION typedef CONDITION_OPERATION
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    externdef __MIDL_itf_structuredquerycondition_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_structuredquerycondition_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IRichChunk_INTERFACE_DEFINED__
      __IRichChunk_INTERFACE_DEFINED__ equ <>
      externdef IID_IRichChunk:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        TYPE_IRichChunkVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IRichChunk, :REFIID, :ptr ptr
        PIRichChunkVtbl_QueryInterface typedef ptr TYPE_IRichChunkVtbl_QueryInterface
        TYPE_IRichChunkVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IRichChunk
        PIRichChunkVtbl_AddRef typedef ptr TYPE_IRichChunkVtbl_AddRef
        TYPE_IRichChunkVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IRichChunk
        PIRichChunkVtbl_Release typedef ptr TYPE_IRichChunkVtbl_Release
        TYPE_IRichChunkVtbl_GetData typedef proto WIN_STD_CALL_CONV :ptr IRichChunk, :ptr ULONG, :ptr ULONG, :ptr LPWSTR, :ptr PROPVARIANT
        PIRichChunkVtbl_GetData typedef ptr TYPE_IRichChunkVtbl_GetData
        IRichChunkVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IRichChunk>
          QueryInterface PIRichChunkVtbl_QueryInterface ?
          AddRef PIRichChunkVtbl_AddRef ?
          Release PIRichChunkVtbl_Release ?
          GetData PIRichChunkVtbl_GetData ?
          ??Interface equ <>
          END_INTERFACE
        IRichChunkVtbl ends
        IRichChunk struct
          lpVtbl POINTER ?
        IRichChunk ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
      IRichChunk_RemoteGetData_Proxy proto WIN_STD_CALL_CONV :ptr IRichChunk, :ptr ULONG, :ptr ULONG, :ptr LPWSTR, :ptr PROPVARIANT
      IRichChunk_RemoteGetData_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
    endif
    ifndef __ICondition_INTERFACE_DEFINED__
      __ICondition_INTERFACE_DEFINED__ equ <>
      externdef IID_ICondition:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        TYPE_IConditionVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr ICondition, :REFIID, :ptr ptr
        PIConditionVtbl_QueryInterface typedef ptr TYPE_IConditionVtbl_QueryInterface
        TYPE_IConditionVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr ICondition
        PIConditionVtbl_AddRef typedef ptr TYPE_IConditionVtbl_AddRef
        TYPE_IConditionVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr ICondition
        PIConditionVtbl_Release typedef ptr TYPE_IConditionVtbl_Release
        TYPE_IConditionVtbl_GetClassID typedef proto WIN_STD_CALL_CONV :ptr ICondition, :ptr CLSID
        PIConditionVtbl_GetClassID typedef ptr TYPE_IConditionVtbl_GetClassID
        TYPE_IConditionVtbl_IsDirty typedef proto WIN_STD_CALL_CONV :ptr ICondition
        PIConditionVtbl_IsDirty typedef ptr TYPE_IConditionVtbl_IsDirty
        TYPE_IConditionVtbl_Load typedef proto WIN_STD_CALL_CONV :ptr ICondition, :ptr IStream
        PIConditionVtbl_Load typedef ptr TYPE_IConditionVtbl_Load
        TYPE_IConditionVtbl_Save typedef proto WIN_STD_CALL_CONV :ptr ICondition, :ptr IStream, :BOOL
        PIConditionVtbl_Save typedef ptr TYPE_IConditionVtbl_Save
        TYPE_IConditionVtbl_GetSizeMax typedef proto WIN_STD_CALL_CONV :ptr ICondition, :ptr ULARGE_INTEGER
        PIConditionVtbl_GetSizeMax typedef ptr TYPE_IConditionVtbl_GetSizeMax
        TYPE_IConditionVtbl_GetConditionType typedef proto WIN_STD_CALL_CONV :ptr ICondition, :ptr CONDITION_TYPE
        PIConditionVtbl_GetConditionType typedef ptr TYPE_IConditionVtbl_GetConditionType
        TYPE_IConditionVtbl_GetSubConditions typedef proto WIN_STD_CALL_CONV :ptr ICondition, :REFIID, :ptr ptr
        PIConditionVtbl_GetSubConditions typedef ptr TYPE_IConditionVtbl_GetSubConditions
        TYPE_IConditionVtbl_GetComparisonInfo typedef proto WIN_STD_CALL_CONV :ptr ICondition, :ptr LPWSTR, :ptr CONDITION_OPERATION, :ptr PROPVARIANT
        PIConditionVtbl_GetComparisonInfo typedef ptr TYPE_IConditionVtbl_GetComparisonInfo
        TYPE_IConditionVtbl_GetValueType typedef proto WIN_STD_CALL_CONV :ptr ICondition, :ptr LPWSTR
        PIConditionVtbl_GetValueType typedef ptr TYPE_IConditionVtbl_GetValueType
        TYPE_IConditionVtbl_GetValueNormalization typedef proto WIN_STD_CALL_CONV :ptr ICondition, :ptr LPWSTR
        PIConditionVtbl_GetValueNormalization typedef ptr TYPE_IConditionVtbl_GetValueNormalization
        TYPE_IConditionVtbl_GetInputTerms typedef proto WIN_STD_CALL_CONV :ptr ICondition, :ptr ptr IRichChunk, :ptr ptr IRichChunk, :ptr ptr IRichChunk
        PIConditionVtbl_GetInputTerms typedef ptr TYPE_IConditionVtbl_GetInputTerms
        TYPE_IConditionVtbl_Clone typedef proto WIN_STD_CALL_CONV :ptr ICondition, :ptr ptr ICondition
        PIConditionVtbl_Clone typedef ptr TYPE_IConditionVtbl_Clone
        IConditionVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ICondition>
          QueryInterface PIConditionVtbl_QueryInterface ?
          AddRef PIConditionVtbl_AddRef ?
          Release PIConditionVtbl_Release ?
          GetClassID PIConditionVtbl_GetClassID ?
          IsDirty PIConditionVtbl_IsDirty ?
          Load PIConditionVtbl_Load ?
          Save PIConditionVtbl_Save ?
          GetSizeMax PIConditionVtbl_GetSizeMax ?
          GetConditionType PIConditionVtbl_GetConditionType ?
          GetSubConditions PIConditionVtbl_GetSubConditions ?
          GetComparisonInfo PIConditionVtbl_GetComparisonInfo ?
          GetValueType PIConditionVtbl_GetValueType ?
          GetValueNormalization PIConditionVtbl_GetValueNormalization ?
          GetInputTerms PIConditionVtbl_GetInputTerms ?
          Clone PIConditionVtbl_Clone ?
          ??Interface equ <>
          END_INTERFACE
        IConditionVtbl ends
        ICondition struct
          lpVtbl POINTER ?
        ICondition ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
      ICondition_RemoteGetComparisonInfo_Proxy proto WIN_STD_CALL_CONV :ptr ICondition, :ptr LPWSTR, :ptr CONDITION_OPERATION, :ptr PROPVARIANT
      ICondition_RemoteGetComparisonInfo_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ICondition_RemoteGetInputTerms_Proxy proto WIN_STD_CALL_CONV :ptr ICondition, :ptr ptr IRichChunk, :ptr ptr IRichChunk, :ptr ptr IRichChunk
      ICondition_RemoteGetInputTerms_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
    endif
    ifndef __ICondition2_INTERFACE_DEFINED__
      __ICondition2_INTERFACE_DEFINED__ equ <>
      externdef IID_ICondition2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        TYPE_ICondition2Vtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr ICondition2, :REFIID, :ptr ptr
        PICondition2Vtbl_QueryInterface typedef ptr TYPE_ICondition2Vtbl_QueryInterface
        TYPE_ICondition2Vtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr ICondition2
        PICondition2Vtbl_AddRef typedef ptr TYPE_ICondition2Vtbl_AddRef
        TYPE_ICondition2Vtbl_Release typedef proto WIN_STD_CALL_CONV :ptr ICondition2
        PICondition2Vtbl_Release typedef ptr TYPE_ICondition2Vtbl_Release
        TYPE_ICondition2Vtbl_GetClassID typedef proto WIN_STD_CALL_CONV :ptr ICondition2, :ptr CLSID
        PICondition2Vtbl_GetClassID typedef ptr TYPE_ICondition2Vtbl_GetClassID
        TYPE_ICondition2Vtbl_IsDirty typedef proto WIN_STD_CALL_CONV :ptr ICondition2
        PICondition2Vtbl_IsDirty typedef ptr TYPE_ICondition2Vtbl_IsDirty
        TYPE_ICondition2Vtbl_Load typedef proto WIN_STD_CALL_CONV :ptr ICondition2, :ptr IStream
        PICondition2Vtbl_Load typedef ptr TYPE_ICondition2Vtbl_Load
        TYPE_ICondition2Vtbl_Save typedef proto WIN_STD_CALL_CONV :ptr ICondition2, :ptr IStream, :BOOL
        PICondition2Vtbl_Save typedef ptr TYPE_ICondition2Vtbl_Save
        TYPE_ICondition2Vtbl_GetSizeMax typedef proto WIN_STD_CALL_CONV :ptr ICondition2, :ptr ULARGE_INTEGER
        PICondition2Vtbl_GetSizeMax typedef ptr TYPE_ICondition2Vtbl_GetSizeMax
        TYPE_ICondition2Vtbl_GetConditionType typedef proto WIN_STD_CALL_CONV :ptr ICondition2, :ptr CONDITION_TYPE
        PICondition2Vtbl_GetConditionType typedef ptr TYPE_ICondition2Vtbl_GetConditionType
        TYPE_ICondition2Vtbl_GetSubConditions typedef proto WIN_STD_CALL_CONV :ptr ICondition2, :REFIID, :ptr ptr
        PICondition2Vtbl_GetSubConditions typedef ptr TYPE_ICondition2Vtbl_GetSubConditions
        TYPE_ICondition2Vtbl_GetComparisonInfo typedef proto WIN_STD_CALL_CONV :ptr ICondition2, :ptr LPWSTR, :ptr CONDITION_OPERATION, :ptr PROPVARIANT
        PICondition2Vtbl_GetComparisonInfo typedef ptr TYPE_ICondition2Vtbl_GetComparisonInfo
        TYPE_ICondition2Vtbl_GetValueType typedef proto WIN_STD_CALL_CONV :ptr ICondition2, :ptr LPWSTR
        PICondition2Vtbl_GetValueType typedef ptr TYPE_ICondition2Vtbl_GetValueType
        TYPE_ICondition2Vtbl_GetValueNormalization typedef proto WIN_STD_CALL_CONV :ptr ICondition2, :ptr LPWSTR
        PICondition2Vtbl_GetValueNormalization typedef ptr TYPE_ICondition2Vtbl_GetValueNormalization
        TYPE_ICondition2Vtbl_GetInputTerms typedef proto WIN_STD_CALL_CONV :ptr ICondition2, :ptr ptr IRichChunk, :ptr ptr IRichChunk, :ptr ptr IRichChunk
        PICondition2Vtbl_GetInputTerms typedef ptr TYPE_ICondition2Vtbl_GetInputTerms
        TYPE_ICondition2Vtbl_Clone typedef proto WIN_STD_CALL_CONV :ptr ICondition2, :ptr ptr ICondition
        PICondition2Vtbl_Clone typedef ptr TYPE_ICondition2Vtbl_Clone
        TYPE_ICondition2Vtbl_GetLocale typedef proto WIN_STD_CALL_CONV :ptr ICondition2, :ptr LPWSTR
        PICondition2Vtbl_GetLocale typedef ptr TYPE_ICondition2Vtbl_GetLocale
        TYPE_ICondition2Vtbl_GetLeafConditionInfo typedef proto WIN_STD_CALL_CONV :ptr ICondition2, :ptr PROPERTYKEY, :ptr CONDITION_OPERATION, :ptr PROPVARIANT
        PICondition2Vtbl_GetLeafConditionInfo typedef ptr TYPE_ICondition2Vtbl_GetLeafConditionInfo
        ICondition2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ICondition2>
          QueryInterface PICondition2Vtbl_QueryInterface ?
          AddRef PICondition2Vtbl_AddRef ?
          Release PICondition2Vtbl_Release ?
          GetClassID PICondition2Vtbl_GetClassID ?
          IsDirty PICondition2Vtbl_IsDirty ?
          Load PICondition2Vtbl_Load ?
          Save PICondition2Vtbl_Save ?
          GetSizeMax PICondition2Vtbl_GetSizeMax ?
          GetConditionType PICondition2Vtbl_GetConditionType ?
          GetSubConditions PICondition2Vtbl_GetSubConditions ?
          GetComparisonInfo PICondition2Vtbl_GetComparisonInfo ?
          GetValueType PICondition2Vtbl_GetValueType ?
          GetValueNormalization PICondition2Vtbl_GetValueNormalization ?
          GetInputTerms PICondition2Vtbl_GetInputTerms ?
          Clone PICondition2Vtbl_Clone ?
          GetLocale PICondition2Vtbl_GetLocale ?
          GetLeafConditionInfo PICondition2Vtbl_GetLeafConditionInfo ?
          ??Interface equ <>
          END_INTERFACE
        ICondition2Vtbl ends
        ICondition2 struct
          lpVtbl POINTER ?
        ICondition2 ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
      ICondition2_RemoteGetLeafConditionInfo_Proxy proto WIN_STD_CALL_CONV :ptr ICondition2, :ptr PROPERTYKEY, :ptr CONDITION_OPERATION, :ptr PROPVARIANT
      ICondition2_RemoteGetLeafConditionInfo_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
    endif
  endif
  externdef __MIDL_itf_structuredquerycondition_0000_0003_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_structuredquerycondition_0000_0003_v0_0_s_ifspec:RPC_IF_HANDLE
  ;Warning: duplicate proto = BSTR_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr BSTR
  ;Warning: duplicate proto = BSTR_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  ;Warning: duplicate proto = BSTR_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  ;Warning: duplicate proto = BSTR_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BSTR
  ;Warning: duplicate proto = LPSAFEARRAY_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr LPSAFEARRAY
  ;Warning: duplicate proto = LPSAFEARRAY_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr LPSAFEARRAY
  ;Warning: duplicate proto = LPSAFEARRAY_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr LPSAFEARRAY
  ;Warning: duplicate proto = LPSAFEARRAY_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr LPSAFEARRAY
  ;Warning: duplicate proto = BSTR_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr BSTR
  ;Warning: duplicate proto = BSTR_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  ;Warning: duplicate proto = BSTR_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  ;Warning: duplicate proto = BSTR_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BSTR
  ;Warning: duplicate proto = LPSAFEARRAY_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr LPSAFEARRAY
  ;Warning: duplicate proto = LPSAFEARRAY_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr LPSAFEARRAY
  ;Warning: duplicate proto = LPSAFEARRAY_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr LPSAFEARRAY
  ;Warning: duplicate proto = LPSAFEARRAY_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr LPSAFEARRAY
  IRichChunk_GetData_Proxy proto WIN_STD_CALL_CONV :ptr IRichChunk, :ptr ULONG, :ptr ULONG, :ptr LPWSTR, :ptr PROPVARIANT
  IRichChunk_GetData_Stub proto WIN_STD_CALL_CONV :ptr IRichChunk, :ptr ULONG, :ptr ULONG, :ptr LPWSTR, :ptr PROPVARIANT
  ICondition_GetComparisonInfo_Proxy proto WIN_STD_CALL_CONV :ptr ICondition, :ptr LPWSTR, :ptr CONDITION_OPERATION, :ptr PROPVARIANT
  ICondition_GetComparisonInfo_Stub proto WIN_STD_CALL_CONV :ptr ICondition, :ptr LPWSTR, :ptr CONDITION_OPERATION, :ptr PROPVARIANT
  ICondition_GetInputTerms_Proxy proto WIN_STD_CALL_CONV :ptr ICondition, :ptr ptr IRichChunk, :ptr ptr IRichChunk, :ptr ptr IRichChunk
  ICondition_GetInputTerms_Stub proto WIN_STD_CALL_CONV :ptr ICondition, :ptr ptr IRichChunk, :ptr ptr IRichChunk, :ptr ptr IRichChunk
  ICondition2_GetLeafConditionInfo_Proxy proto WIN_STD_CALL_CONV :ptr ICondition2, :ptr PROPERTYKEY, :ptr CONDITION_OPERATION, :ptr PROPVARIANT
  ICondition2_GetLeafConditionInfo_Stub proto WIN_STD_CALL_CONV :ptr ICondition2, :ptr PROPERTYKEY, :ptr CONDITION_OPERATION, :ptr PROPVARIANT
  ifdef __cplusplus
    ;[...]
  endif
endif

