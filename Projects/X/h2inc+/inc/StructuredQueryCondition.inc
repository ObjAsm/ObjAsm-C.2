;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\structuredquerycondition.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 21/02/2024 18:17:08

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
ifndef __structuredquerycondition_h__
  __structuredquerycondition_h__ equ <>
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
  ifndef __IRichChunk_FWD_DEFINED__
    __IRichChunk_FWD_DEFINED__ equ <>
    ;* __IRichChunk_FWD_DEFINED__ *
  endif
  ifndef __ICondition_FWD_DEFINED__
    __ICondition_FWD_DEFINED__ equ <>
    ;* __ICondition_FWD_DEFINED__ *
  endif
  ifndef __ICondition2_FWD_DEFINED__
    __ICondition2_FWD_DEFINED__ equ <>
    ;* __ICondition2_FWD_DEFINED__ *
  endif
  ;* header files for imported files *
  include oaidl.inc
  include ocidl.inc
  include propidl.inc
  ifdef __cplusplus
    ;[...]
  endif
  ;* interface __MIDL_itf_structuredquerycondition_0000_0000 *
  ;* [local] *
  include winapifamily.inc
  ;* [v1_enum] *
  CONDITION_TYPE typedef SDWORD
  CT_AND_CONDITION equ 0
  CT_OR_CONDITION equ
  CT_NOT_CONDITION equ
  CT_LEAF_CONDITION equ
  tagCONDITION_TYPE typedef CONDITION_TYPE

  ;* [v1_enum] *
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
      ;* interface IRichChunk *
      ;* [unique][uuid][object] *
      externdef IID_IRichChunk:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IRichChunkVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IRichChunkVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IRichChunk, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IRichChunk
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IRichChunk
          DECLSPEC_XFGVIRT(IRichChunk, GetData)
          ;* [local] *
          ;* [annotation][unique][out] *
          ;* [annotation][unique][out] *
          ;* [annotation][unique][out] *
          ;* [annotation][unique][out] *
          STD_METHOD GetData, :ptr IRichChunk, :ptr ULONG, :ptr ULONG, :ptr LPWSTR, :ptr PROPVARIANT
          ??Interface equ <>
          END_INTERFACE
        IRichChunkVtbl ends
        IRichChunk struct
          lpVtbl POINTER ?
        IRichChunk ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      IRichChunk_RemoteGetData_Proxy proto WIN_STD_CALL_CONV :ptr IRichChunk, :ptr ULONG, :ptr ULONG, :ptr LPWSTR, :ptr PROPVARIANT
      ;* [out] *
      IRichChunk_RemoteGetData_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __IRichChunk_INTERFACE_DEFINED__ *
    endif
    ifndef __ICondition_INTERFACE_DEFINED__
      __ICondition_INTERFACE_DEFINED__ equ <>
      ;* interface ICondition *
      ;* [unique][uuid][object] *
      externdef IID_ICondition:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IConditionVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IConditionVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ICondition, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ICondition
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ICondition
          DECLSPEC_XFGVIRT(IPersist, GetClassID)
          STD_METHOD GetClassID, :ptr ICondition, :ptr CLSID
          ;* [out] *
          DECLSPEC_XFGVIRT(IPersistStream, IsDirty)
          STD_METHOD IsDirty, :ptr ICondition
          DECLSPEC_XFGVIRT(IPersistStream, Load)
          STD_METHOD Load, :ptr ICondition, :ptr IStream
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IPersistStream, Save)
          ;* [unique][in] *
          STD_METHOD Save, :ptr ICondition, :ptr IStream, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IPersistStream, GetSizeMax)
          STD_METHOD GetSizeMax, :ptr ICondition, :ptr ULARGE_INTEGER
          ;* [out] *
          DECLSPEC_XFGVIRT(ICondition, GetConditionType)
          STD_METHOD GetConditionType, :ptr ICondition, :ptr CONDITION_TYPE
          ;* [retval][out] *
          DECLSPEC_XFGVIRT(ICondition, GetSubConditions)
          ;* [in] *
          STD_METHOD GetSubConditions, :ptr ICondition, :REFIID, :ptr ptr
          ;* [iid_is][retval][out] *
          DECLSPEC_XFGVIRT(ICondition, GetComparisonInfo)
          ;* [local] *
          ;* [annotation][unique][out] *
          ;* [annotation][unique][out] *
          ;* [annotation][unique][out] *
          STD_METHOD GetComparisonInfo, :ptr ICondition, :ptr LPWSTR, :ptr CONDITION_OPERATION, :ptr PROPVARIANT
          DECLSPEC_XFGVIRT(ICondition, GetValueType)
          STD_METHOD GetValueType, :ptr ICondition, :ptr LPWSTR
          ;* [retval][out] *
          DECLSPEC_XFGVIRT(ICondition, GetValueNormalization)
          STD_METHOD GetValueNormalization, :ptr ICondition, :ptr LPWSTR
          ;* [retval][out] *
          DECLSPEC_XFGVIRT(ICondition, GetInputTerms)
          ;* [local] *
          ;* [annotation][unique][out] *
          ;* [annotation][unique][out] *
          ;* [annotation][unique][out] *
          STD_METHOD GetInputTerms, :ptr ICondition, :ptr ptr IRichChunk, :ptr ptr IRichChunk, :ptr ptr IRichChunk
          DECLSPEC_XFGVIRT(ICondition, Clone)
          STD_METHOD Clone, :ptr ICondition, :ptr ptr ICondition
          ;* [retval][out] *
          ??Interface equ <>
          END_INTERFACE
        IConditionVtbl ends
        ICondition struct
          lpVtbl POINTER ?
        ICondition ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      ICondition_RemoteGetComparisonInfo_Proxy proto WIN_STD_CALL_CONV :ptr ICondition, :ptr LPWSTR, :ptr CONDITION_OPERATION, :ptr PROPVARIANT
      ;* [out] *
      ICondition_RemoteGetComparisonInfo_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      ICondition_RemoteGetInputTerms_Proxy proto WIN_STD_CALL_CONV :ptr ICondition, :ptr ptr IRichChunk, :ptr ptr IRichChunk, :ptr ptr IRichChunk
      ;* [out] *
      ICondition_RemoteGetInputTerms_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __ICondition_INTERFACE_DEFINED__ *
    endif
    ifndef __ICondition2_INTERFACE_DEFINED__
      __ICondition2_INTERFACE_DEFINED__ equ <>
      ;* interface ICondition2 *
      ;* [unique][object][uuid] *
      externdef IID_ICondition2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ICondition2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ICondition2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ICondition2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ICondition2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ICondition2
          DECLSPEC_XFGVIRT(IPersist, GetClassID)
          STD_METHOD GetClassID, :ptr ICondition2, :ptr CLSID
          ;* [out] *
          DECLSPEC_XFGVIRT(IPersistStream, IsDirty)
          STD_METHOD IsDirty, :ptr ICondition2
          DECLSPEC_XFGVIRT(IPersistStream, Load)
          STD_METHOD Load, :ptr ICondition2, :ptr IStream
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IPersistStream, Save)
          ;* [unique][in] *
          STD_METHOD Save, :ptr ICondition2, :ptr IStream, :BOOL
          ;* [in] *
          DECLSPEC_XFGVIRT(IPersistStream, GetSizeMax)
          STD_METHOD GetSizeMax, :ptr ICondition2, :ptr ULARGE_INTEGER
          ;* [out] *
          DECLSPEC_XFGVIRT(ICondition, GetConditionType)
          STD_METHOD GetConditionType, :ptr ICondition2, :ptr CONDITION_TYPE
          ;* [retval][out] *
          DECLSPEC_XFGVIRT(ICondition, GetSubConditions)
          ;* [in] *
          STD_METHOD GetSubConditions, :ptr ICondition2, :REFIID, :ptr ptr
          ;* [iid_is][retval][out] *
          DECLSPEC_XFGVIRT(ICondition, GetComparisonInfo)
          ;* [local] *
          ;* [annotation][unique][out] *
          ;* [annotation][unique][out] *
          ;* [annotation][unique][out] *
          STD_METHOD GetComparisonInfo, :ptr ICondition2, :ptr LPWSTR, :ptr CONDITION_OPERATION, :ptr PROPVARIANT
          DECLSPEC_XFGVIRT(ICondition, GetValueType)
          STD_METHOD GetValueType, :ptr ICondition2, :ptr LPWSTR
          ;* [retval][out] *
          DECLSPEC_XFGVIRT(ICondition, GetValueNormalization)
          STD_METHOD GetValueNormalization, :ptr ICondition2, :ptr LPWSTR
          ;* [retval][out] *
          DECLSPEC_XFGVIRT(ICondition, GetInputTerms)
          ;* [local] *
          ;* [annotation][unique][out] *
          ;* [annotation][unique][out] *
          ;* [annotation][unique][out] *
          STD_METHOD GetInputTerms, :ptr ICondition2, :ptr ptr IRichChunk, :ptr ptr IRichChunk, :ptr ptr IRichChunk
          DECLSPEC_XFGVIRT(ICondition, Clone)
          STD_METHOD Clone, :ptr ICondition2, :ptr ptr ICondition
          ;* [retval][out] *
          DECLSPEC_XFGVIRT(ICondition2, GetLocale)
          STD_METHOD GetLocale, :ptr ICondition2, :ptr LPWSTR
          ;* [out] *
          DECLSPEC_XFGVIRT(ICondition2, GetLeafConditionInfo)
          ;* [local] *
          ;* [annotation][out] *
          ;* [annotation][out] *
          ;* [annotation][out] *
          STD_METHOD GetLeafConditionInfo, :ptr ICondition2, :ptr PROPERTYKEY, :ptr CONDITION_OPERATION, :ptr PROPVARIANT
          ??Interface equ <>
          END_INTERFACE
        ICondition2Vtbl ends
        ICondition2 struct
          lpVtbl POINTER ?
        ICondition2 ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      ICondition2_RemoteGetLeafConditionInfo_Proxy proto WIN_STD_CALL_CONV :ptr ICondition2, :ptr PROPERTYKEY, :ptr CONDITION_OPERATION, :ptr PROPVARIANT
      ;* [out] *
      ICondition2_RemoteGetLeafConditionInfo_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __ICondition2_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_structuredquerycondition_0000_0003 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  externdef __MIDL_itf_structuredquerycondition_0000_0003_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_structuredquerycondition_0000_0003_v0_0_s_ifspec:RPC_IF_HANDLE
  ;* Additional Prototypes for ALL interfaces *
  BSTR_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr BSTR
  BSTR_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BSTR
  LPSAFEARRAY_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr LPSAFEARRAY
  LPSAFEARRAY_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr LPSAFEARRAY
  LPSAFEARRAY_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr LPSAFEARRAY
  LPSAFEARRAY_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr LPSAFEARRAY
  BSTR_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr BSTR
  BSTR_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BSTR
  LPSAFEARRAY_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr LPSAFEARRAY
  LPSAFEARRAY_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr LPSAFEARRAY
  LPSAFEARRAY_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr LPSAFEARRAY
  LPSAFEARRAY_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr LPSAFEARRAY
  ;* [local] *
  IRichChunk_GetData_Proxy proto WIN_STD_CALL_CONV :ptr IRichChunk, :ptr ULONG, :ptr ULONG, :ptr LPWSTR, :ptr PROPVARIANT
  ;* [annotation][unique][out] *
  ;* [call_as] *
  IRichChunk_GetData_Stub proto WIN_STD_CALL_CONV :ptr IRichChunk, :ptr ULONG, :ptr ULONG, :ptr LPWSTR, :ptr PROPVARIANT
  ;* [out] *
  ;* [local] *
  ICondition_GetComparisonInfo_Proxy proto WIN_STD_CALL_CONV :ptr ICondition, :ptr LPWSTR, :ptr CONDITION_OPERATION, :ptr PROPVARIANT
  ;* [annotation][unique][out] *
  ;* [call_as] *
  ICondition_GetComparisonInfo_Stub proto WIN_STD_CALL_CONV :ptr ICondition, :ptr LPWSTR, :ptr CONDITION_OPERATION, :ptr PROPVARIANT
  ;* [out] *
  ;* [local] *
  ICondition_GetInputTerms_Proxy proto WIN_STD_CALL_CONV :ptr ICondition, :ptr ptr IRichChunk, :ptr ptr IRichChunk, :ptr ptr IRichChunk
  ;* [annotation][unique][out] *
  ;* [call_as] *
  ICondition_GetInputTerms_Stub proto WIN_STD_CALL_CONV :ptr ICondition, :ptr ptr IRichChunk, :ptr ptr IRichChunk, :ptr ptr IRichChunk
  ;* [out] *
  ;* [local] *
  ICondition2_GetLeafConditionInfo_Proxy proto WIN_STD_CALL_CONV :ptr ICondition2, :ptr PROPERTYKEY, :ptr CONDITION_OPERATION, :ptr PROPVARIANT
  ;* [annotation][out] *
  ;* [call_as] *
  ICondition2_GetLeafConditionInfo_Stub proto WIN_STD_CALL_CONV :ptr ICondition2, :ptr PROPERTYKEY, :ptr CONDITION_OPERATION, :ptr PROPVARIANT
  ;* [out] *
  ;* end of Additional Prototypes *
  ifdef __cplusplus
    ;[...]
  endif
endif
