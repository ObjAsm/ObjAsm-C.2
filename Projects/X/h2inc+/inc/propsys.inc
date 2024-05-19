;Include file created by h2inc+ version C.2.0 on (UTC) 19/05/2024 07:52:23
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\propsys.h\propsys.h
;             Created on (UTC) 06/04/2024 06:15:57
;             Last modified on (UTC) 21/02/2024 18:17:12

ifndef __REQUIRED_RPCNDR_H_VERSION__
  __REQUIRED_RPCNDR_H_VERSION__ equ 501
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
ifndef __propsys_h__
  __propsys_h__ equ <>
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
  ifndef __IInitializeWithFile_FWD_DEFINED__
    __IInitializeWithFile_FWD_DEFINED__ equ <>
  endif
  ifndef __IInitializeWithStream_FWD_DEFINED__
    __IInitializeWithStream_FWD_DEFINED__ equ <>
  endif
  ifndef __IPropertyStore_FWD_DEFINED__
    __IPropertyStore_FWD_DEFINED__ equ <>
  endif
  ifndef __INamedPropertyStore_FWD_DEFINED__
    __INamedPropertyStore_FWD_DEFINED__ equ <>
  endif
  ifndef __IObjectWithPropertyKey_FWD_DEFINED__
    __IObjectWithPropertyKey_FWD_DEFINED__ equ <>
  endif
  ifndef __IPropertyChange_FWD_DEFINED__
    __IPropertyChange_FWD_DEFINED__ equ <>
  endif
  ifndef __IPropertyChangeArray_FWD_DEFINED__
    __IPropertyChangeArray_FWD_DEFINED__ equ <>
  endif
  ifndef __IPropertyStoreCapabilities_FWD_DEFINED__
    __IPropertyStoreCapabilities_FWD_DEFINED__ equ <>
  endif
  ifndef __IPropertyStoreCache_FWD_DEFINED__
    __IPropertyStoreCache_FWD_DEFINED__ equ <>
  endif
  ifndef __IPropertyEnumType_FWD_DEFINED__
    __IPropertyEnumType_FWD_DEFINED__ equ <>
  endif
  ifndef __IPropertyEnumType2_FWD_DEFINED__
    __IPropertyEnumType2_FWD_DEFINED__ equ <>
  endif
  ifndef __IPropertyEnumTypeList_FWD_DEFINED__
    __IPropertyEnumTypeList_FWD_DEFINED__ equ <>
  endif
  ifndef __IPropertyDescription_FWD_DEFINED__
    __IPropertyDescription_FWD_DEFINED__ equ <>
  endif
  ifndef __IPropertyDescription2_FWD_DEFINED__
    __IPropertyDescription2_FWD_DEFINED__ equ <>
  endif
  ifndef __IPropertyDescriptionAliasInfo_FWD_DEFINED__
    __IPropertyDescriptionAliasInfo_FWD_DEFINED__ equ <>
  endif
  ifndef __IPropertyDescriptionSearchInfo_FWD_DEFINED__
    __IPropertyDescriptionSearchInfo_FWD_DEFINED__ equ <>
  endif
  ifndef __IPropertyDescriptionRelatedPropertyInfo_FWD_DEFINED__
    __IPropertyDescriptionRelatedPropertyInfo_FWD_DEFINED__ equ <>
  endif
  ifndef __IPropertySystem_FWD_DEFINED__
    __IPropertySystem_FWD_DEFINED__ equ <>
  endif
  ifndef __IPropertyDescriptionList_FWD_DEFINED__
    __IPropertyDescriptionList_FWD_DEFINED__ equ <>
  endif
  ifndef __IPropertyStoreFactory_FWD_DEFINED__
    __IPropertyStoreFactory_FWD_DEFINED__ equ <>
  endif
  ifndef __IDelayedPropertyStoreFactory_FWD_DEFINED__
    __IDelayedPropertyStoreFactory_FWD_DEFINED__ equ <>
  endif
  ifndef __IPersistSerializedPropStorage_FWD_DEFINED__
    __IPersistSerializedPropStorage_FWD_DEFINED__ equ <>
  endif
  ifndef __IPersistSerializedPropStorage2_FWD_DEFINED__
    __IPersistSerializedPropStorage2_FWD_DEFINED__ equ <>
  endif
  ifndef __IPropertySystemChangeNotify_FWD_DEFINED__
    __IPropertySystemChangeNotify_FWD_DEFINED__ equ <>
  endif
  ifndef __ICreateObject_FWD_DEFINED__
    __ICreateObject_FWD_DEFINED__ equ <>
  endif
  ifndef __InMemoryPropertyStore_FWD_DEFINED__
    __InMemoryPropertyStore_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __InMemoryPropertyStoreMarshalByValue_FWD_DEFINED__
    __InMemoryPropertyStoreMarshalByValue_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  ifndef __PropertySystem_FWD_DEFINED__
    __PropertySystem_FWD_DEFINED__ equ <>
    ifdef __cplusplus
      ;[...]
    else
    endif
  endif
  include objidl.inc
  include oleidl.inc
  include ocidl.inc
  include shtypes.inc
  include StructuredQueryCondition.inc
  ifdef __cplusplus
    ;[...]
  endif
  include winapifamily.inc
  ifndef PSSTDAPI
    if Defined(_PROPSYS_)
      PSSTDAPI equ <STDAPI>
      PSSTDAPI_ macro type_
        exitm <STDAPI_(type_)>
      endm
    else
      PSSTDAPI equ <EXTERN_C DECLSPEC_IMPORT HRESULT STDAPICALLTYPE>
      PSSTDAPI_ macro type_
        exitm <EXTERN_C DECLSPEC_IMPORT type_ STDAPICALLTYPE>
      endm
    endif
  endif
  if 0
    ;[...]
  endif
  include propkeydef.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if _MSC_VER ge 1200
      ifndef _MSC_EXTENSIONS
      endif
    endif
    externdef __MIDL_itf_propsys_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_propsys_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IInitializeWithFile_INTERFACE_DEFINED__
      __IInitializeWithFile_INTERFACE_DEFINED__ equ <>
      externdef IID_IInitializeWithFile:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IInitializeWithFileVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IInitializeWithFileVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IInitializeWithFile, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IInitializeWithFile
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IInitializeWithFile
          DECLSPEC_XFGVIRT(IInitializeWithFile, Initialize)
          STD_METHOD Initialize, :ptr IInitializeWithFile, :LPCWSTR, :DWORD
          ??Interface equ <>
          END_INTERFACE
        IInitializeWithFileVtbl ends
        IInitializeWithFile struct
          lpVtbl POINTER ?
        IInitializeWithFile ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IInitializeWithStream_INTERFACE_DEFINED__
      __IInitializeWithStream_INTERFACE_DEFINED__ equ <>
      externdef IID_IInitializeWithStream:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IInitializeWithStreamVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IInitializeWithStreamVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IInitializeWithStream, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IInitializeWithStream
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IInitializeWithStream
          DECLSPEC_XFGVIRT(IInitializeWithStream, Initialize)
          STD_METHOD Initialize, :ptr IInitializeWithStream, :ptr IStream, :DWORD
          ??Interface equ <>
          END_INTERFACE
        IInitializeWithStreamVtbl ends
        IInitializeWithStream struct
          lpVtbl POINTER ?
        IInitializeWithStream ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
      IInitializeWithStream_RemoteInitialize_Proxy proto WIN_STD_CALL_CONV :ptr IInitializeWithStream, :ptr IStream, :DWORD
      IInitializeWithStream_RemoteInitialize_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_GAMES)
    externdef __MIDL_itf_propsys_0000_0002_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_propsys_0000_0002_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IPropertyStore_INTERFACE_DEFINED__
      __IPropertyStore_INTERFACE_DEFINED__ equ <>
      externdef IID_IPropertyStore:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPropertyStoreVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPropertyStoreVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IPropertyStore, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPropertyStore
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPropertyStore
          DECLSPEC_XFGVIRT(IPropertyStore, GetCount)
          STD_METHOD GetCount, :ptr IPropertyStore, :ptr DWORD
          DECLSPEC_XFGVIRT(IPropertyStore, GetAt)
          STD_METHOD GetAt, :ptr IPropertyStore, :DWORD, :ptr PROPERTYKEY
          DECLSPEC_XFGVIRT(IPropertyStore, GetValue)
          STD_METHOD GetValue, :ptr IPropertyStore, :REFPROPERTYKEY, :ptr PROPVARIANT
          DECLSPEC_XFGVIRT(IPropertyStore, SetValue)
          STD_METHOD SetValue, :ptr IPropertyStore, :REFPROPERTYKEY, :REFPROPVARIANT
          DECLSPEC_XFGVIRT(IPropertyStore, Commit)
          STD_METHOD Commit, :ptr IPropertyStore
          ??Interface equ <>
          END_INTERFACE
        IPropertyStoreVtbl ends
        IPropertyStore struct
          lpVtbl POINTER ?
        IPropertyStore ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    LPPROPERTYSTORE typedef ptr IPropertyStore
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
    @DefProto DllImport, PropVariantToWinRTPropertyValue, WIN_STD_CALL_CONV,, <:REFPROPVARIANT, :REFIID, :ptr ptr>, 12
    @DefProto DllImport, WinRTPropertyValueToPropVariant, WIN_STD_CALL_CONV,, <:ptr IUnknown, :ptr PROPVARIANT>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    externdef __MIDL_itf_propsys_0000_0003_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_propsys_0000_0003_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __INamedPropertyStore_INTERFACE_DEFINED__
      __INamedPropertyStore_INTERFACE_DEFINED__ equ <>
      externdef IID_INamedPropertyStore:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        INamedPropertyStoreVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <INamedPropertyStoreVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr INamedPropertyStore, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr INamedPropertyStore
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr INamedPropertyStore
          DECLSPEC_XFGVIRT(INamedPropertyStore, GetNamedValue)
          STD_METHOD GetNamedValue, :ptr INamedPropertyStore, :LPCWSTR, :ptr PROPVARIANT
          DECLSPEC_XFGVIRT(INamedPropertyStore, SetNamedValue)
          STD_METHOD SetNamedValue, :ptr INamedPropertyStore, :LPCWSTR, :REFPROPVARIANT
          DECLSPEC_XFGVIRT(INamedPropertyStore, GetNameCount)
          STD_METHOD GetNameCount, :ptr INamedPropertyStore, :ptr DWORD
          DECLSPEC_XFGVIRT(INamedPropertyStore, GetNameAt)
          STD_METHOD GetNameAt, :ptr INamedPropertyStore, :DWORD, :ptr BSTR
          ??Interface equ <>
          END_INTERFACE
        INamedPropertyStoreVtbl ends
        INamedPropertyStore struct
          lpVtbl POINTER ?
        INamedPropertyStore ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    GETPROPERTYSTOREFLAGS typedef SDWORD
    GPS_DEFAULT equ 0
    GPS_HANDLERPROPERTIESONLY equ 1h
    GPS_READWRITE equ 2h
    GPS_TEMPORARY equ 4h
    GPS_FASTPROPERTIESONLY equ 8h
    GPS_OPENSLOWITEM equ 10h
    GPS_DELAYCREATION equ 20h
    GPS_BESTEFFORT equ 40h
    GPS_NO_OPLOCK equ 80h
    GPS_PREFERQUERYPROPERTIES equ 100h
    GPS_EXTRINSICPROPERTIES equ 200h
    GPS_EXTRINSICPROPERTIESONLY equ 400h
    GPS_VOLATILEPROPERTIES equ 800h
    GPS_VOLATILEPROPERTIESONLY equ 1000h
    GPS_MASK_VALID equ 1fffh

    DEFINE_ENUM_FLAG_OPERATORS(GETPROPERTYSTOREFLAGS)
    externdef __MIDL_itf_propsys_0000_0004_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_propsys_0000_0004_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IObjectWithPropertyKey_INTERFACE_DEFINED__
      __IObjectWithPropertyKey_INTERFACE_DEFINED__ equ <>
      externdef IID_IObjectWithPropertyKey:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IObjectWithPropertyKeyVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IObjectWithPropertyKeyVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IObjectWithPropertyKey, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IObjectWithPropertyKey
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IObjectWithPropertyKey
          DECLSPEC_XFGVIRT(IObjectWithPropertyKey, SetPropertyKey)
          STD_METHOD SetPropertyKey, :ptr IObjectWithPropertyKey, :REFPROPERTYKEY
          DECLSPEC_XFGVIRT(IObjectWithPropertyKey, GetPropertyKey)
          STD_METHOD GetPropertyKey, :ptr IObjectWithPropertyKey, :ptr PROPERTYKEY
          ??Interface equ <>
          END_INTERFACE
        IObjectWithPropertyKeyVtbl ends
        IObjectWithPropertyKey struct
          lpVtbl POINTER ?
        IObjectWithPropertyKey ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    PKA_FLAGS typedef SDWORD
    PKA_SET equ 0
    PKA_APPEND equ
    PKA_DELETE equ

    externdef __MIDL_itf_propsys_0000_0005_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_propsys_0000_0005_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IPropertyChange_INTERFACE_DEFINED__
      __IPropertyChange_INTERFACE_DEFINED__ equ <>
      externdef IID_IPropertyChange:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPropertyChangeVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPropertyChangeVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IPropertyChange, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPropertyChange
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPropertyChange
          DECLSPEC_XFGVIRT(IObjectWithPropertyKey, SetPropertyKey)
          STD_METHOD SetPropertyKey, :ptr IPropertyChange, :REFPROPERTYKEY
          DECLSPEC_XFGVIRT(IObjectWithPropertyKey, GetPropertyKey)
          STD_METHOD GetPropertyKey, :ptr IPropertyChange, :ptr PROPERTYKEY
          DECLSPEC_XFGVIRT(IPropertyChange, ApplyToPropVariant)
          STD_METHOD ApplyToPropVariant, :ptr IPropertyChange, :REFPROPVARIANT, :ptr PROPVARIANT
          ??Interface equ <>
          END_INTERFACE
        IPropertyChangeVtbl ends
        IPropertyChange struct
          lpVtbl POINTER ?
        IPropertyChange ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IPropertyChangeArray_INTERFACE_DEFINED__
      __IPropertyChangeArray_INTERFACE_DEFINED__ equ <>
      externdef IID_IPropertyChangeArray:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPropertyChangeArrayVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPropertyChangeArrayVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IPropertyChangeArray, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPropertyChangeArray
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPropertyChangeArray
          DECLSPEC_XFGVIRT(IPropertyChangeArray, GetCount)
          STD_METHOD GetCount, :ptr IPropertyChangeArray, :ptr UINT
          DECLSPEC_XFGVIRT(IPropertyChangeArray, GetAt)
          STD_METHOD GetAt, :ptr IPropertyChangeArray, :UINT, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IPropertyChangeArray, InsertAt)
          STD_METHOD InsertAt, :ptr IPropertyChangeArray, :UINT, :ptr IPropertyChange
          DECLSPEC_XFGVIRT(IPropertyChangeArray, Append)
          STD_METHOD Append, :ptr IPropertyChangeArray, :ptr IPropertyChange
          DECLSPEC_XFGVIRT(IPropertyChangeArray, AppendOrReplace)
          STD_METHOD AppendOrReplace, :ptr IPropertyChangeArray, :ptr IPropertyChange
          DECLSPEC_XFGVIRT(IPropertyChangeArray, RemoveAt)
          STD_METHOD RemoveAt, :ptr IPropertyChangeArray, :UINT
          DECLSPEC_XFGVIRT(IPropertyChangeArray, IsKeyInArray)
          STD_METHOD IsKeyInArray, :ptr IPropertyChangeArray, :REFPROPERTYKEY
          ??Interface equ <>
          END_INTERFACE
        IPropertyChangeArrayVtbl ends
        IPropertyChangeArray struct
          lpVtbl POINTER ?
        IPropertyChangeArray ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IPropertyStoreCapabilities_INTERFACE_DEFINED__
      __IPropertyStoreCapabilities_INTERFACE_DEFINED__ equ <>
      externdef IID_IPropertyStoreCapabilities:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPropertyStoreCapabilitiesVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPropertyStoreCapabilitiesVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IPropertyStoreCapabilities, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPropertyStoreCapabilities
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPropertyStoreCapabilities
          DECLSPEC_XFGVIRT(IPropertyStoreCapabilities, IsPropertyWritable)
          STD_METHOD IsPropertyWritable, :ptr IPropertyStoreCapabilities, :REFPROPERTYKEY
          ??Interface equ <>
          END_INTERFACE
        IPropertyStoreCapabilitiesVtbl ends
        IPropertyStoreCapabilities struct
          lpVtbl POINTER ?
        IPropertyStoreCapabilities ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IPropertyStoreCache_INTERFACE_DEFINED__
      __IPropertyStoreCache_INTERFACE_DEFINED__ equ <>
      PSC_STATE typedef SDWORD
      PSC_NORMAL equ 0
      PSC_NOTINSOURCE equ 1
      PSC_DIRTY equ 2
      PSC_READONLY equ 3

      externdef IID_IPropertyStoreCache:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPropertyStoreCacheVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPropertyStoreCacheVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IPropertyStoreCache, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPropertyStoreCache
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPropertyStoreCache
          DECLSPEC_XFGVIRT(IPropertyStore, GetCount)
          STD_METHOD GetCount, :ptr IPropertyStoreCache, :ptr DWORD
          DECLSPEC_XFGVIRT(IPropertyStore, GetAt)
          STD_METHOD GetAt, :ptr IPropertyStoreCache, :DWORD, :ptr PROPERTYKEY
          DECLSPEC_XFGVIRT(IPropertyStore, GetValue)
          STD_METHOD GetValue, :ptr IPropertyStoreCache, :REFPROPERTYKEY, :ptr PROPVARIANT
          DECLSPEC_XFGVIRT(IPropertyStore, SetValue)
          STD_METHOD SetValue, :ptr IPropertyStoreCache, :REFPROPERTYKEY, :REFPROPVARIANT
          DECLSPEC_XFGVIRT(IPropertyStore, Commit)
          STD_METHOD Commit, :ptr IPropertyStoreCache
          DECLSPEC_XFGVIRT(IPropertyStoreCache, GetState)
          STD_METHOD GetState, :ptr IPropertyStoreCache, :REFPROPERTYKEY, :ptr PSC_STATE
          DECLSPEC_XFGVIRT(IPropertyStoreCache, GetValueAndState)
          STD_METHOD GetValueAndState, :ptr IPropertyStoreCache, :REFPROPERTYKEY, :ptr PROPVARIANT, :ptr PSC_STATE
          DECLSPEC_XFGVIRT(IPropertyStoreCache, SetState)
          STD_METHOD SetState, :ptr IPropertyStoreCache, :REFPROPERTYKEY, :PSC_STATE
          DECLSPEC_XFGVIRT(IPropertyStoreCache, SetValueAndState)
          STD_METHOD SetValueAndState, :ptr IPropertyStoreCache, :REFPROPERTYKEY, :ptr PROPVARIANT, :PSC_STATE
          ??Interface equ <>
          END_INTERFACE
        IPropertyStoreCacheVtbl ends
        IPropertyStoreCache struct
          lpVtbl POINTER ?
        IPropertyStoreCache ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IPropertyEnumType_INTERFACE_DEFINED__
      __IPropertyEnumType_INTERFACE_DEFINED__ equ <>
      PROPENUMTYPE typedef SDWORD
      PET_DISCRETEVALUE equ 0
      PET_RANGEDVALUE equ 1
      PET_DEFAULTVALUE equ 2
      PET_ENDRANGE equ 3

      externdef IID_IPropertyEnumType:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPropertyEnumTypeVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPropertyEnumTypeVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IPropertyEnumType, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPropertyEnumType
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPropertyEnumType
          DECLSPEC_XFGVIRT(IPropertyEnumType, GetEnumType)
          STD_METHOD GetEnumType, :ptr IPropertyEnumType, :ptr PROPENUMTYPE
          DECLSPEC_XFGVIRT(IPropertyEnumType, GetValue)
          STD_METHOD GetValue, :ptr IPropertyEnumType, :ptr PROPVARIANT
          DECLSPEC_XFGVIRT(IPropertyEnumType, GetRangeMinValue)
          STD_METHOD GetRangeMinValue, :ptr IPropertyEnumType, :ptr PROPVARIANT
          DECLSPEC_XFGVIRT(IPropertyEnumType, GetRangeSetValue)
          STD_METHOD GetRangeSetValue, :ptr IPropertyEnumType, :ptr PROPVARIANT
          DECLSPEC_XFGVIRT(IPropertyEnumType, GetDisplayText)
          STD_METHOD GetDisplayText, :ptr IPropertyEnumType, :ptr LPWSTR
          ??Interface equ <>
          END_INTERFACE
        IPropertyEnumTypeVtbl ends
        IPropertyEnumType struct
          lpVtbl POINTER ?
        IPropertyEnumType ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IPropertyEnumType2_INTERFACE_DEFINED__
      __IPropertyEnumType2_INTERFACE_DEFINED__ equ <>
      externdef IID_IPropertyEnumType2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPropertyEnumType2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPropertyEnumType2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IPropertyEnumType2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPropertyEnumType2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPropertyEnumType2
          DECLSPEC_XFGVIRT(IPropertyEnumType, GetEnumType)
          STD_METHOD GetEnumType, :ptr IPropertyEnumType2, :ptr PROPENUMTYPE
          DECLSPEC_XFGVIRT(IPropertyEnumType, GetValue)
          STD_METHOD GetValue, :ptr IPropertyEnumType2, :ptr PROPVARIANT
          DECLSPEC_XFGVIRT(IPropertyEnumType, GetRangeMinValue)
          STD_METHOD GetRangeMinValue, :ptr IPropertyEnumType2, :ptr PROPVARIANT
          DECLSPEC_XFGVIRT(IPropertyEnumType, GetRangeSetValue)
          STD_METHOD GetRangeSetValue, :ptr IPropertyEnumType2, :ptr PROPVARIANT
          DECLSPEC_XFGVIRT(IPropertyEnumType, GetDisplayText)
          STD_METHOD GetDisplayText, :ptr IPropertyEnumType2, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IPropertyEnumType2, GetImageReference)
          STD_METHOD GetImageReference, :ptr IPropertyEnumType2, :ptr LPWSTR
          ??Interface equ <>
          END_INTERFACE
        IPropertyEnumType2Vtbl ends
        IPropertyEnumType2 struct
          lpVtbl POINTER ?
        IPropertyEnumType2 ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IPropertyEnumTypeList_INTERFACE_DEFINED__
      __IPropertyEnumTypeList_INTERFACE_DEFINED__ equ <>
      externdef IID_IPropertyEnumTypeList:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPropertyEnumTypeListVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPropertyEnumTypeListVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IPropertyEnumTypeList, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPropertyEnumTypeList
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPropertyEnumTypeList
          DECLSPEC_XFGVIRT(IPropertyEnumTypeList, GetCount)
          STD_METHOD GetCount, :ptr IPropertyEnumTypeList, :ptr UINT
          DECLSPEC_XFGVIRT(IPropertyEnumTypeList, GetAt)
          STD_METHOD GetAt, :ptr IPropertyEnumTypeList, :UINT, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IPropertyEnumTypeList, GetConditionAt)
          STD_METHOD GetConditionAt, :ptr IPropertyEnumTypeList, :UINT, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IPropertyEnumTypeList, FindMatchingIndex)
          STD_METHOD FindMatchingIndex, :ptr IPropertyEnumTypeList, :REFPROPVARIANT, :ptr UINT
          ??Interface equ <>
          END_INTERFACE
        IPropertyEnumTypeListVtbl ends
        IPropertyEnumTypeList struct
          lpVtbl POINTER ?
        IPropertyEnumTypeList ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IPropertyDescription_INTERFACE_DEFINED__
      __IPropertyDescription_INTERFACE_DEFINED__ equ <>
      PROPDESC_TYPE_FLAGS typedef SDWORD
      PDTF_DEFAULT equ 0
      PDTF_MULTIPLEVALUES equ 1h
      PDTF_ISINNATE equ 2h
      PDTF_ISGROUP equ 4h
      PDTF_CANGROUPBY equ 8h
      PDTF_CANSTACKBY equ 10h
      PDTF_ISTREEPROPERTY equ 20h
      PDTF_INCLUDEINFULLTEXTQUERY equ 40h
      PDTF_ISVIEWABLE equ 80h
      PDTF_ISQUERYABLE equ 100h
      PDTF_CANBEPURGED equ 200h
      PDTF_SEARCHRAWVALUE equ 400h
      PDTF_DONTCOERCEEMPTYSTRINGS equ 800h
      PDTF_ALWAYSINSUPPLEMENTALSTORE equ 1000h
      PDTF_ISSYSTEMPROPERTY equ 80000000h
      PDTF_MASK_ALL equ 80001fffh

      DEFINE_ENUM_FLAG_OPERATORS(PROPDESC_TYPE_FLAGS)
      PROPDESC_VIEW_FLAGS typedef SDWORD
      PDVF_DEFAULT equ 0
      PDVF_CENTERALIGN equ 1h
      PDVF_RIGHTALIGN equ 2h
      PDVF_BEGINNEWGROUP equ 4h
      PDVF_FILLAREA equ 8h
      PDVF_SORTDESCENDING equ 10h
      PDVF_SHOWONLYIFPRESENT equ 20h
      PDVF_SHOWBYDEFAULT equ 40h
      PDVF_SHOWINPRIMARYLIST equ 80h
      PDVF_SHOWINSECONDARYLIST equ 100h
      PDVF_HIDELABEL equ 200h
      PDVF_HIDDEN equ 800h
      PDVF_CANWRAP equ 1000h
      PDVF_MASK_ALL equ 1bffh

      DEFINE_ENUM_FLAG_OPERATORS(PROPDESC_VIEW_FLAGS)
      PROPDESC_DISPLAYTYPE typedef SDWORD
      PDDT_STRING equ 0
      PDDT_NUMBER equ 1
      PDDT_BOOLEAN equ 2
      PDDT_DATETIME equ 3
      PDDT_ENUMERATED equ 4

      PROPDESC_GROUPING_RANGE typedef SDWORD
      PDGR_DISCRETE equ 0
      PDGR_ALPHANUMERIC equ 1
      PDGR_SIZE equ 2
      PDGR_DYNAMIC equ 3
      PDGR_DATE equ 4
      PDGR_PERCENT equ 5
      PDGR_ENUMERATED equ 6

      PROPDESC_FORMAT_FLAGS typedef SDWORD
      PDFF_DEFAULT equ 0
      PDFF_PREFIXNAME equ 1h
      PDFF_FILENAME equ 2h
      PDFF_ALWAYSKB equ 4h
      PDFF_RESERVED_RIGHTTOLEFT equ 8h
      PDFF_SHORTTIME equ 10h
      PDFF_LONGTIME equ 20h
      PDFF_HIDETIME equ 40h
      PDFF_SHORTDATE equ 80h
      PDFF_LONGDATE equ 100h
      PDFF_HIDEDATE equ 200h
      PDFF_RELATIVEDATE equ 400h
      PDFF_USEEDITINVITATION equ 800h
      PDFF_READONLY equ 1000h
      PDFF_NOAUTOREADINGORDER equ 2000h

      PDFF_PREFERFRIENDLY equ static_cast lt PROPDESC_FORMAT_FLAGS gt (10000000h)
      DEFINE_ENUM_FLAG_OPERATORS(PROPDESC_FORMAT_FLAGS)
      PROPDESC_SORTDESCRIPTION typedef SDWORD
      PDSD_GENERAL equ 0
      PDSD_A_Z equ 1
      PDSD_LOWEST_HIGHEST equ 2
      PDSD_SMALLEST_BIGGEST equ 3
      PDSD_OLDEST_NEWEST equ 4

      PROPDESC_RELATIVEDESCRIPTION_TYPE typedef SDWORD
      PDRDT_GENERAL equ 0
      PDRDT_DATE equ 1
      PDRDT_SIZE equ 2
      PDRDT_COUNT equ 3
      PDRDT_REVISION equ 4
      PDRDT_LENGTH equ 5
      PDRDT_DURATION equ 6
      PDRDT_SPEED equ 7
      PDRDT_RATE equ 8
      PDRDT_RATING equ 9
      PDRDT_PRIORITY equ 10

      PROPDESC_AGGREGATION_TYPE typedef SDWORD
      PDAT_DEFAULT equ 0
      PDAT_FIRST equ 1
      PDAT_SUM equ 2
      PDAT_AVERAGE equ 3
      PDAT_DATERANGE equ 4
      PDAT_UNION equ 5
      PDAT_MAX equ 6
      PDAT_MIN equ 7

      PROPDESC_CONDITION_TYPE typedef SDWORD
      PDCOT_NONE equ 0
      PDCOT_STRING equ 1
      PDCOT_SIZE equ 2
      PDCOT_DATETIME equ 3
      PDCOT_BOOLEAN equ 4
      PDCOT_NUMBER equ 5

      externdef IID_IPropertyDescription:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPropertyDescriptionVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPropertyDescriptionVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IPropertyDescription, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPropertyDescription
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPropertyDescription
          DECLSPEC_XFGVIRT(IPropertyDescription, GetPropertyKey)
          STD_METHOD GetPropertyKey, :ptr IPropertyDescription, :ptr PROPERTYKEY
          DECLSPEC_XFGVIRT(IPropertyDescription, GetCanonicalName)
          STD_METHOD GetCanonicalName, :ptr IPropertyDescription, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IPropertyDescription, GetPropertyType)
          STD_METHOD GetPropertyType, :ptr IPropertyDescription, :ptr VARTYPE
          DECLSPEC_XFGVIRT(IPropertyDescription, GetDisplayName)
          STD_METHOD GetDisplayName, :ptr IPropertyDescription, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IPropertyDescription, GetEditInvitation)
          STD_METHOD GetEditInvitation, :ptr IPropertyDescription, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IPropertyDescription, GetTypeFlags)
          STD_METHOD GetTypeFlags, :ptr IPropertyDescription, :PROPDESC_TYPE_FLAGS, :ptr PROPDESC_TYPE_FLAGS
          DECLSPEC_XFGVIRT(IPropertyDescription, GetViewFlags)
          STD_METHOD GetViewFlags, :ptr IPropertyDescription, :ptr PROPDESC_VIEW_FLAGS
          DECLSPEC_XFGVIRT(IPropertyDescription, GetDefaultColumnWidth)
          STD_METHOD GetDefaultColumnWidth, :ptr IPropertyDescription, :ptr UINT
          DECLSPEC_XFGVIRT(IPropertyDescription, GetDisplayType)
          STD_METHOD GetDisplayType, :ptr IPropertyDescription, :ptr PROPDESC_DISPLAYTYPE
          DECLSPEC_XFGVIRT(IPropertyDescription, GetColumnState)
          STD_METHOD GetColumnState, :ptr IPropertyDescription, :ptr SHCOLSTATEF
          DECLSPEC_XFGVIRT(IPropertyDescription, GetGroupingRange)
          STD_METHOD GetGroupingRange, :ptr IPropertyDescription, :ptr PROPDESC_GROUPING_RANGE
          DECLSPEC_XFGVIRT(IPropertyDescription, GetRelativeDescriptionType)
          STD_METHOD GetRelativeDescriptionType, :ptr IPropertyDescription, :ptr PROPDESC_RELATIVEDESCRIPTION_TYPE
          DECLSPEC_XFGVIRT(IPropertyDescription, GetRelativeDescription)
          STD_METHOD GetRelativeDescription, :ptr IPropertyDescription, :REFPROPVARIANT, :REFPROPVARIANT, :ptr LPWSTR, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IPropertyDescription, GetSortDescription)
          STD_METHOD GetSortDescription, :ptr IPropertyDescription, :ptr PROPDESC_SORTDESCRIPTION
          DECLSPEC_XFGVIRT(IPropertyDescription, GetSortDescriptionLabel)
          STD_METHOD GetSortDescriptionLabel, :ptr IPropertyDescription, :BOOL, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IPropertyDescription, GetAggregationType)
          STD_METHOD GetAggregationType, :ptr IPropertyDescription, :ptr PROPDESC_AGGREGATION_TYPE
          DECLSPEC_XFGVIRT(IPropertyDescription, GetConditionType)
          STD_METHOD GetConditionType, :ptr IPropertyDescription, :ptr PROPDESC_CONDITION_TYPE, :ptr CONDITION_OPERATION
          DECLSPEC_XFGVIRT(IPropertyDescription, GetEnumTypeList)
          STD_METHOD GetEnumTypeList, :ptr IPropertyDescription, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IPropertyDescription, CoerceToCanonicalValue)
          STD_METHOD CoerceToCanonicalValue, :ptr IPropertyDescription, :ptr PROPVARIANT
          DECLSPEC_XFGVIRT(IPropertyDescription, FormatForDisplay)
          STD_METHOD FormatForDisplay, :ptr IPropertyDescription, :REFPROPVARIANT, :PROPDESC_FORMAT_FLAGS, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IPropertyDescription, IsValueCanonical)
          STD_METHOD IsValueCanonical, :ptr IPropertyDescription, :REFPROPVARIANT
          ??Interface equ <>
          END_INTERFACE
        IPropertyDescriptionVtbl ends
        IPropertyDescription struct
          lpVtbl POINTER ?
        IPropertyDescription ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
      IPropertyDescription_RemoteCoerceToCanonicalValue_Proxy proto WIN_STD_CALL_CONV :ptr IPropertyDescription, :REFPROPVARIANT, :ptr PROPVARIANT
      IPropertyDescription_RemoteCoerceToCanonicalValue_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
    endif
    ifndef __IPropertyDescription2_INTERFACE_DEFINED__
      __IPropertyDescription2_INTERFACE_DEFINED__ equ <>
      externdef IID_IPropertyDescription2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPropertyDescription2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPropertyDescription2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IPropertyDescription2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPropertyDescription2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPropertyDescription2
          DECLSPEC_XFGVIRT(IPropertyDescription, GetPropertyKey)
          STD_METHOD GetPropertyKey, :ptr IPropertyDescription2, :ptr PROPERTYKEY
          DECLSPEC_XFGVIRT(IPropertyDescription, GetCanonicalName)
          STD_METHOD GetCanonicalName, :ptr IPropertyDescription2, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IPropertyDescription, GetPropertyType)
          STD_METHOD GetPropertyType, :ptr IPropertyDescription2, :ptr VARTYPE
          DECLSPEC_XFGVIRT(IPropertyDescription, GetDisplayName)
          STD_METHOD GetDisplayName, :ptr IPropertyDescription2, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IPropertyDescription, GetEditInvitation)
          STD_METHOD GetEditInvitation, :ptr IPropertyDescription2, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IPropertyDescription, GetTypeFlags)
          STD_METHOD GetTypeFlags, :ptr IPropertyDescription2, :PROPDESC_TYPE_FLAGS, :ptr PROPDESC_TYPE_FLAGS
          DECLSPEC_XFGVIRT(IPropertyDescription, GetViewFlags)
          STD_METHOD GetViewFlags, :ptr IPropertyDescription2, :ptr PROPDESC_VIEW_FLAGS
          DECLSPEC_XFGVIRT(IPropertyDescription, GetDefaultColumnWidth)
          STD_METHOD GetDefaultColumnWidth, :ptr IPropertyDescription2, :ptr UINT
          DECLSPEC_XFGVIRT(IPropertyDescription, GetDisplayType)
          STD_METHOD GetDisplayType, :ptr IPropertyDescription2, :ptr PROPDESC_DISPLAYTYPE
          DECLSPEC_XFGVIRT(IPropertyDescription, GetColumnState)
          STD_METHOD GetColumnState, :ptr IPropertyDescription2, :ptr SHCOLSTATEF
          DECLSPEC_XFGVIRT(IPropertyDescription, GetGroupingRange)
          STD_METHOD GetGroupingRange, :ptr IPropertyDescription2, :ptr PROPDESC_GROUPING_RANGE
          DECLSPEC_XFGVIRT(IPropertyDescription, GetRelativeDescriptionType)
          STD_METHOD GetRelativeDescriptionType, :ptr IPropertyDescription2, :ptr PROPDESC_RELATIVEDESCRIPTION_TYPE
          DECLSPEC_XFGVIRT(IPropertyDescription, GetRelativeDescription)
          STD_METHOD GetRelativeDescription, :ptr IPropertyDescription2, :REFPROPVARIANT, :REFPROPVARIANT, :ptr LPWSTR, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IPropertyDescription, GetSortDescription)
          STD_METHOD GetSortDescription, :ptr IPropertyDescription2, :ptr PROPDESC_SORTDESCRIPTION
          DECLSPEC_XFGVIRT(IPropertyDescription, GetSortDescriptionLabel)
          STD_METHOD GetSortDescriptionLabel, :ptr IPropertyDescription2, :BOOL, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IPropertyDescription, GetAggregationType)
          STD_METHOD GetAggregationType, :ptr IPropertyDescription2, :ptr PROPDESC_AGGREGATION_TYPE
          DECLSPEC_XFGVIRT(IPropertyDescription, GetConditionType)
          STD_METHOD GetConditionType, :ptr IPropertyDescription2, :ptr PROPDESC_CONDITION_TYPE, :ptr CONDITION_OPERATION
          DECLSPEC_XFGVIRT(IPropertyDescription, GetEnumTypeList)
          STD_METHOD GetEnumTypeList, :ptr IPropertyDescription2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IPropertyDescription, CoerceToCanonicalValue)
          STD_METHOD CoerceToCanonicalValue, :ptr IPropertyDescription2, :ptr PROPVARIANT
          DECLSPEC_XFGVIRT(IPropertyDescription, FormatForDisplay)
          STD_METHOD FormatForDisplay, :ptr IPropertyDescription2, :REFPROPVARIANT, :PROPDESC_FORMAT_FLAGS, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IPropertyDescription, IsValueCanonical)
          STD_METHOD IsValueCanonical, :ptr IPropertyDescription2, :REFPROPVARIANT
          DECLSPEC_XFGVIRT(IPropertyDescription2, GetImageReferenceForValue)
          STD_METHOD GetImageReferenceForValue, :ptr IPropertyDescription2, :REFPROPVARIANT, :ptr LPWSTR
          ??Interface equ <>
          END_INTERFACE
        IPropertyDescription2Vtbl ends
        IPropertyDescription2 struct
          lpVtbl POINTER ?
        IPropertyDescription2 ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IPropertyDescriptionAliasInfo_INTERFACE_DEFINED__
      __IPropertyDescriptionAliasInfo_INTERFACE_DEFINED__ equ <>
      externdef IID_IPropertyDescriptionAliasInfo:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPropertyDescriptionAliasInfoVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPropertyDescriptionAliasInfoVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IPropertyDescriptionAliasInfo, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPropertyDescriptionAliasInfo
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPropertyDescriptionAliasInfo
          DECLSPEC_XFGVIRT(IPropertyDescription, GetPropertyKey)
          STD_METHOD GetPropertyKey, :ptr IPropertyDescriptionAliasInfo, :ptr PROPERTYKEY
          DECLSPEC_XFGVIRT(IPropertyDescription, GetCanonicalName)
          STD_METHOD GetCanonicalName, :ptr IPropertyDescriptionAliasInfo, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IPropertyDescription, GetPropertyType)
          STD_METHOD GetPropertyType, :ptr IPropertyDescriptionAliasInfo, :ptr VARTYPE
          DECLSPEC_XFGVIRT(IPropertyDescription, GetDisplayName)
          STD_METHOD GetDisplayName, :ptr IPropertyDescriptionAliasInfo, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IPropertyDescription, GetEditInvitation)
          STD_METHOD GetEditInvitation, :ptr IPropertyDescriptionAliasInfo, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IPropertyDescription, GetTypeFlags)
          STD_METHOD GetTypeFlags, :ptr IPropertyDescriptionAliasInfo, :PROPDESC_TYPE_FLAGS, :ptr PROPDESC_TYPE_FLAGS
          DECLSPEC_XFGVIRT(IPropertyDescription, GetViewFlags)
          STD_METHOD GetViewFlags, :ptr IPropertyDescriptionAliasInfo, :ptr PROPDESC_VIEW_FLAGS
          DECLSPEC_XFGVIRT(IPropertyDescription, GetDefaultColumnWidth)
          STD_METHOD GetDefaultColumnWidth, :ptr IPropertyDescriptionAliasInfo, :ptr UINT
          DECLSPEC_XFGVIRT(IPropertyDescription, GetDisplayType)
          STD_METHOD GetDisplayType, :ptr IPropertyDescriptionAliasInfo, :ptr PROPDESC_DISPLAYTYPE
          DECLSPEC_XFGVIRT(IPropertyDescription, GetColumnState)
          STD_METHOD GetColumnState, :ptr IPropertyDescriptionAliasInfo, :ptr SHCOLSTATEF
          DECLSPEC_XFGVIRT(IPropertyDescription, GetGroupingRange)
          STD_METHOD GetGroupingRange, :ptr IPropertyDescriptionAliasInfo, :ptr PROPDESC_GROUPING_RANGE
          DECLSPEC_XFGVIRT(IPropertyDescription, GetRelativeDescriptionType)
          STD_METHOD GetRelativeDescriptionType, :ptr IPropertyDescriptionAliasInfo, :ptr PROPDESC_RELATIVEDESCRIPTION_TYPE
          DECLSPEC_XFGVIRT(IPropertyDescription, GetRelativeDescription)
          STD_METHOD GetRelativeDescription, :ptr IPropertyDescriptionAliasInfo, :REFPROPVARIANT, :REFPROPVARIANT, :ptr LPWSTR, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IPropertyDescription, GetSortDescription)
          STD_METHOD GetSortDescription, :ptr IPropertyDescriptionAliasInfo, :ptr PROPDESC_SORTDESCRIPTION
          DECLSPEC_XFGVIRT(IPropertyDescription, GetSortDescriptionLabel)
          STD_METHOD GetSortDescriptionLabel, :ptr IPropertyDescriptionAliasInfo, :BOOL, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IPropertyDescription, GetAggregationType)
          STD_METHOD GetAggregationType, :ptr IPropertyDescriptionAliasInfo, :ptr PROPDESC_AGGREGATION_TYPE
          DECLSPEC_XFGVIRT(IPropertyDescription, GetConditionType)
          STD_METHOD GetConditionType, :ptr IPropertyDescriptionAliasInfo, :ptr PROPDESC_CONDITION_TYPE, :ptr CONDITION_OPERATION
          DECLSPEC_XFGVIRT(IPropertyDescription, GetEnumTypeList)
          STD_METHOD GetEnumTypeList, :ptr IPropertyDescriptionAliasInfo, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IPropertyDescription, CoerceToCanonicalValue)
          STD_METHOD CoerceToCanonicalValue, :ptr IPropertyDescriptionAliasInfo, :ptr PROPVARIANT
          DECLSPEC_XFGVIRT(IPropertyDescription, FormatForDisplay)
          STD_METHOD FormatForDisplay, :ptr IPropertyDescriptionAliasInfo, :REFPROPVARIANT, :PROPDESC_FORMAT_FLAGS, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IPropertyDescription, IsValueCanonical)
          STD_METHOD IsValueCanonical, :ptr IPropertyDescriptionAliasInfo, :REFPROPVARIANT
          DECLSPEC_XFGVIRT(IPropertyDescriptionAliasInfo, GetSortByAlias)
          STD_METHOD GetSortByAlias, :ptr IPropertyDescriptionAliasInfo, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IPropertyDescriptionAliasInfo, GetAdditionalSortByAliases)
          STD_METHOD GetAdditionalSortByAliases, :ptr IPropertyDescriptionAliasInfo, :REFIID, :ptr ptr
          ??Interface equ <>
          END_INTERFACE
        IPropertyDescriptionAliasInfoVtbl ends
        IPropertyDescriptionAliasInfo struct
          lpVtbl POINTER ?
        IPropertyDescriptionAliasInfo ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IPropertyDescriptionSearchInfo_INTERFACE_DEFINED__
      __IPropertyDescriptionSearchInfo_INTERFACE_DEFINED__ equ <>
      PROPDESC_SEARCHINFO_FLAGS typedef SDWORD
      PDSIF_DEFAULT equ 0
      PDSIF_ININVERTEDINDEX equ 1h
      PDSIF_ISCOLUMN equ 2h
      PDSIF_ISCOLUMNSPARSE equ 4h
      PDSIF_ALWAYSINCLUDE equ 8h
      PDSIF_USEFORTYPEAHEAD equ 10h

      DEFINE_ENUM_FLAG_OPERATORS(PROPDESC_SEARCHINFO_FLAGS)
      PROPDESC_COLUMNINDEX_TYPE typedef SDWORD
      PDCIT_NONE equ 0
      PDCIT_ONDISK equ 1
      PDCIT_INMEMORY equ 2
      PDCIT_ONDEMAND equ 3
      PDCIT_ONDISKALL equ 4
      PDCIT_ONDISKVECTOR equ 5

      externdef IID_IPropertyDescriptionSearchInfo:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPropertyDescriptionSearchInfoVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPropertyDescriptionSearchInfoVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IPropertyDescriptionSearchInfo, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPropertyDescriptionSearchInfo
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPropertyDescriptionSearchInfo
          DECLSPEC_XFGVIRT(IPropertyDescription, GetPropertyKey)
          STD_METHOD GetPropertyKey, :ptr IPropertyDescriptionSearchInfo, :ptr PROPERTYKEY
          DECLSPEC_XFGVIRT(IPropertyDescription, GetCanonicalName)
          STD_METHOD GetCanonicalName, :ptr IPropertyDescriptionSearchInfo, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IPropertyDescription, GetPropertyType)
          STD_METHOD GetPropertyType, :ptr IPropertyDescriptionSearchInfo, :ptr VARTYPE
          DECLSPEC_XFGVIRT(IPropertyDescription, GetDisplayName)
          STD_METHOD GetDisplayName, :ptr IPropertyDescriptionSearchInfo, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IPropertyDescription, GetEditInvitation)
          STD_METHOD GetEditInvitation, :ptr IPropertyDescriptionSearchInfo, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IPropertyDescription, GetTypeFlags)
          STD_METHOD GetTypeFlags, :ptr IPropertyDescriptionSearchInfo, :PROPDESC_TYPE_FLAGS, :ptr PROPDESC_TYPE_FLAGS
          DECLSPEC_XFGVIRT(IPropertyDescription, GetViewFlags)
          STD_METHOD GetViewFlags, :ptr IPropertyDescriptionSearchInfo, :ptr PROPDESC_VIEW_FLAGS
          DECLSPEC_XFGVIRT(IPropertyDescription, GetDefaultColumnWidth)
          STD_METHOD GetDefaultColumnWidth, :ptr IPropertyDescriptionSearchInfo, :ptr UINT
          DECLSPEC_XFGVIRT(IPropertyDescription, GetDisplayType)
          STD_METHOD GetDisplayType, :ptr IPropertyDescriptionSearchInfo, :ptr PROPDESC_DISPLAYTYPE
          DECLSPEC_XFGVIRT(IPropertyDescription, GetColumnState)
          STD_METHOD GetColumnState, :ptr IPropertyDescriptionSearchInfo, :ptr SHCOLSTATEF
          DECLSPEC_XFGVIRT(IPropertyDescription, GetGroupingRange)
          STD_METHOD GetGroupingRange, :ptr IPropertyDescriptionSearchInfo, :ptr PROPDESC_GROUPING_RANGE
          DECLSPEC_XFGVIRT(IPropertyDescription, GetRelativeDescriptionType)
          STD_METHOD GetRelativeDescriptionType, :ptr IPropertyDescriptionSearchInfo, :ptr PROPDESC_RELATIVEDESCRIPTION_TYPE
          DECLSPEC_XFGVIRT(IPropertyDescription, GetRelativeDescription)
          STD_METHOD GetRelativeDescription, :ptr IPropertyDescriptionSearchInfo, :REFPROPVARIANT, :REFPROPVARIANT, :ptr LPWSTR, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IPropertyDescription, GetSortDescription)
          STD_METHOD GetSortDescription, :ptr IPropertyDescriptionSearchInfo, :ptr PROPDESC_SORTDESCRIPTION
          DECLSPEC_XFGVIRT(IPropertyDescription, GetSortDescriptionLabel)
          STD_METHOD GetSortDescriptionLabel, :ptr IPropertyDescriptionSearchInfo, :BOOL, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IPropertyDescription, GetAggregationType)
          STD_METHOD GetAggregationType, :ptr IPropertyDescriptionSearchInfo, :ptr PROPDESC_AGGREGATION_TYPE
          DECLSPEC_XFGVIRT(IPropertyDescription, GetConditionType)
          STD_METHOD GetConditionType, :ptr IPropertyDescriptionSearchInfo, :ptr PROPDESC_CONDITION_TYPE, :ptr CONDITION_OPERATION
          DECLSPEC_XFGVIRT(IPropertyDescription, GetEnumTypeList)
          STD_METHOD GetEnumTypeList, :ptr IPropertyDescriptionSearchInfo, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IPropertyDescription, CoerceToCanonicalValue)
          STD_METHOD CoerceToCanonicalValue, :ptr IPropertyDescriptionSearchInfo, :ptr PROPVARIANT
          DECLSPEC_XFGVIRT(IPropertyDescription, FormatForDisplay)
          STD_METHOD FormatForDisplay, :ptr IPropertyDescriptionSearchInfo, :REFPROPVARIANT, :PROPDESC_FORMAT_FLAGS, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IPropertyDescription, IsValueCanonical)
          STD_METHOD IsValueCanonical, :ptr IPropertyDescriptionSearchInfo, :REFPROPVARIANT
          DECLSPEC_XFGVIRT(IPropertyDescriptionSearchInfo, GetSearchInfoFlags)
          STD_METHOD GetSearchInfoFlags, :ptr IPropertyDescriptionSearchInfo, :ptr PROPDESC_SEARCHINFO_FLAGS
          DECLSPEC_XFGVIRT(IPropertyDescriptionSearchInfo, GetColumnIndexType)
          STD_METHOD GetColumnIndexType, :ptr IPropertyDescriptionSearchInfo, :ptr PROPDESC_COLUMNINDEX_TYPE
          DECLSPEC_XFGVIRT(IPropertyDescriptionSearchInfo, GetProjectionString)
          STD_METHOD GetProjectionString, :ptr IPropertyDescriptionSearchInfo, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IPropertyDescriptionSearchInfo, GetMaxSize)
          STD_METHOD GetMaxSize, :ptr IPropertyDescriptionSearchInfo, :ptr UINT
          ??Interface equ <>
          END_INTERFACE
        IPropertyDescriptionSearchInfoVtbl ends
        IPropertyDescriptionSearchInfo struct
          lpVtbl POINTER ?
        IPropertyDescriptionSearchInfo ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IPropertyDescriptionRelatedPropertyInfo_INTERFACE_DEFINED__
      __IPropertyDescriptionRelatedPropertyInfo_INTERFACE_DEFINED__ equ <>
      externdef IID_IPropertyDescriptionRelatedPropertyInfo:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPropertyDescriptionRelatedPropertyInfoVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPropertyDescriptionRelatedPropertyInfoVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IPropertyDescriptionRelatedPropertyInfo, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPropertyDescriptionRelatedPropertyInfo
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPropertyDescriptionRelatedPropertyInfo
          DECLSPEC_XFGVIRT(IPropertyDescription, GetPropertyKey)
          STD_METHOD GetPropertyKey, :ptr IPropertyDescriptionRelatedPropertyInfo, :ptr PROPERTYKEY
          DECLSPEC_XFGVIRT(IPropertyDescription, GetCanonicalName)
          STD_METHOD GetCanonicalName, :ptr IPropertyDescriptionRelatedPropertyInfo, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IPropertyDescription, GetPropertyType)
          STD_METHOD GetPropertyType, :ptr IPropertyDescriptionRelatedPropertyInfo, :ptr VARTYPE
          DECLSPEC_XFGVIRT(IPropertyDescription, GetDisplayName)
          STD_METHOD GetDisplayName, :ptr IPropertyDescriptionRelatedPropertyInfo, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IPropertyDescription, GetEditInvitation)
          STD_METHOD GetEditInvitation, :ptr IPropertyDescriptionRelatedPropertyInfo, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IPropertyDescription, GetTypeFlags)
          STD_METHOD GetTypeFlags, :ptr IPropertyDescriptionRelatedPropertyInfo, :PROPDESC_TYPE_FLAGS, :ptr PROPDESC_TYPE_FLAGS
          DECLSPEC_XFGVIRT(IPropertyDescription, GetViewFlags)
          STD_METHOD GetViewFlags, :ptr IPropertyDescriptionRelatedPropertyInfo, :ptr PROPDESC_VIEW_FLAGS
          DECLSPEC_XFGVIRT(IPropertyDescription, GetDefaultColumnWidth)
          STD_METHOD GetDefaultColumnWidth, :ptr IPropertyDescriptionRelatedPropertyInfo, :ptr UINT
          DECLSPEC_XFGVIRT(IPropertyDescription, GetDisplayType)
          STD_METHOD GetDisplayType, :ptr IPropertyDescriptionRelatedPropertyInfo, :ptr PROPDESC_DISPLAYTYPE
          DECLSPEC_XFGVIRT(IPropertyDescription, GetColumnState)
          STD_METHOD GetColumnState, :ptr IPropertyDescriptionRelatedPropertyInfo, :ptr SHCOLSTATEF
          DECLSPEC_XFGVIRT(IPropertyDescription, GetGroupingRange)
          STD_METHOD GetGroupingRange, :ptr IPropertyDescriptionRelatedPropertyInfo, :ptr PROPDESC_GROUPING_RANGE
          DECLSPEC_XFGVIRT(IPropertyDescription, GetRelativeDescriptionType)
          STD_METHOD GetRelativeDescriptionType, :ptr IPropertyDescriptionRelatedPropertyInfo, :ptr PROPDESC_RELATIVEDESCRIPTION_TYPE
          DECLSPEC_XFGVIRT(IPropertyDescription, GetRelativeDescription)
          STD_METHOD GetRelativeDescription, :ptr IPropertyDescriptionRelatedPropertyInfo, :REFPROPVARIANT, :REFPROPVARIANT, :ptr LPWSTR, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IPropertyDescription, GetSortDescription)
          STD_METHOD GetSortDescription, :ptr IPropertyDescriptionRelatedPropertyInfo, :ptr PROPDESC_SORTDESCRIPTION
          DECLSPEC_XFGVIRT(IPropertyDescription, GetSortDescriptionLabel)
          STD_METHOD GetSortDescriptionLabel, :ptr IPropertyDescriptionRelatedPropertyInfo, :BOOL, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IPropertyDescription, GetAggregationType)
          STD_METHOD GetAggregationType, :ptr IPropertyDescriptionRelatedPropertyInfo, :ptr PROPDESC_AGGREGATION_TYPE
          DECLSPEC_XFGVIRT(IPropertyDescription, GetConditionType)
          STD_METHOD GetConditionType, :ptr IPropertyDescriptionRelatedPropertyInfo, :ptr PROPDESC_CONDITION_TYPE, :ptr CONDITION_OPERATION
          DECLSPEC_XFGVIRT(IPropertyDescription, GetEnumTypeList)
          STD_METHOD GetEnumTypeList, :ptr IPropertyDescriptionRelatedPropertyInfo, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IPropertyDescription, CoerceToCanonicalValue)
          STD_METHOD CoerceToCanonicalValue, :ptr IPropertyDescriptionRelatedPropertyInfo, :ptr PROPVARIANT
          DECLSPEC_XFGVIRT(IPropertyDescription, FormatForDisplay)
          STD_METHOD FormatForDisplay, :ptr IPropertyDescriptionRelatedPropertyInfo, :REFPROPVARIANT, :PROPDESC_FORMAT_FLAGS, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IPropertyDescription, IsValueCanonical)
          STD_METHOD IsValueCanonical, :ptr IPropertyDescriptionRelatedPropertyInfo, :REFPROPVARIANT
          DECLSPEC_XFGVIRT(IPropertyDescriptionRelatedPropertyInfo, GetRelatedProperty)
          STD_METHOD GetRelatedProperty, :ptr IPropertyDescriptionRelatedPropertyInfo, :LPCWSTR, :REFIID, :ptr ptr
          ??Interface equ <>
          END_INTERFACE
        IPropertyDescriptionRelatedPropertyInfoVtbl ends
        IPropertyDescriptionRelatedPropertyInfo struct
          lpVtbl POINTER ?
        IPropertyDescriptionRelatedPropertyInfo ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    PROPDESC_ENUMFILTER typedef SDWORD
    PDEF_ALL equ 0
    PDEF_SYSTEM equ 1
    PDEF_NONSYSTEM equ 2
    PDEF_VIEWABLE equ 3
    PDEF_QUERYABLE equ 4
    PDEF_INFULLTEXTQUERY equ 5
    PDEF_COLUMN equ 6

    externdef __MIDL_itf_propsys_0000_0017_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_propsys_0000_0017_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IPropertySystem_INTERFACE_DEFINED__
      __IPropertySystem_INTERFACE_DEFINED__ equ <>
      externdef IID_IPropertySystem:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPropertySystemVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPropertySystemVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IPropertySystem, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPropertySystem
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPropertySystem
          DECLSPEC_XFGVIRT(IPropertySystem, GetPropertyDescription)
          STD_METHOD GetPropertyDescription, :ptr IPropertySystem, :REFPROPERTYKEY, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IPropertySystem, GetPropertyDescriptionByName)
          STD_METHOD GetPropertyDescriptionByName, :ptr IPropertySystem, :LPCWSTR, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IPropertySystem, GetPropertyDescriptionListFromString)
          STD_METHOD GetPropertyDescriptionListFromString, :ptr IPropertySystem, :LPCWSTR, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IPropertySystem, EnumeratePropertyDescriptions)
          STD_METHOD EnumeratePropertyDescriptions, :ptr IPropertySystem, :PROPDESC_ENUMFILTER, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IPropertySystem, FormatForDisplay)
          STD_METHOD FormatForDisplay, :ptr IPropertySystem, :REFPROPERTYKEY, :REFPROPVARIANT, :PROPDESC_FORMAT_FLAGS, :LPWSTR, :DWORD
          DECLSPEC_XFGVIRT(IPropertySystem, FormatForDisplayAlloc)
          STD_METHOD FormatForDisplayAlloc, :ptr IPropertySystem, :REFPROPERTYKEY, :REFPROPVARIANT, :PROPDESC_FORMAT_FLAGS, :ptr LPWSTR
          DECLSPEC_XFGVIRT(IPropertySystem, RegisterPropertySchema)
          STD_METHOD RegisterPropertySchema, :ptr IPropertySystem, :LPCWSTR
          DECLSPEC_XFGVIRT(IPropertySystem, UnregisterPropertySchema)
          STD_METHOD UnregisterPropertySchema, :ptr IPropertySystem, :LPCWSTR
          DECLSPEC_XFGVIRT(IPropertySystem, RefreshPropertySchema)
          STD_METHOD RefreshPropertySchema, :ptr IPropertySystem
          ??Interface equ <>
          END_INTERFACE
        IPropertySystemVtbl ends
        IPropertySystem struct
          lpVtbl POINTER ?
        IPropertySystem ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IPropertyDescriptionList_INTERFACE_DEFINED__
      __IPropertyDescriptionList_INTERFACE_DEFINED__ equ <>
      externdef IID_IPropertyDescriptionList:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPropertyDescriptionListVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPropertyDescriptionListVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IPropertyDescriptionList, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPropertyDescriptionList
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPropertyDescriptionList
          DECLSPEC_XFGVIRT(IPropertyDescriptionList, GetCount)
          STD_METHOD GetCount, :ptr IPropertyDescriptionList, :ptr UINT
          DECLSPEC_XFGVIRT(IPropertyDescriptionList, GetAt)
          STD_METHOD GetAt, :ptr IPropertyDescriptionList, :UINT, :REFIID, :ptr ptr
          ??Interface equ <>
          END_INTERFACE
        IPropertyDescriptionListVtbl ends
        IPropertyDescriptionList struct
          lpVtbl POINTER ?
        IPropertyDescriptionList ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IPropertyStoreFactory_INTERFACE_DEFINED__
      __IPropertyStoreFactory_INTERFACE_DEFINED__ equ <>
      externdef IID_IPropertyStoreFactory:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPropertyStoreFactoryVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPropertyStoreFactoryVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IPropertyStoreFactory, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPropertyStoreFactory
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPropertyStoreFactory
          DECLSPEC_XFGVIRT(IPropertyStoreFactory, GetPropertyStore)
          STD_METHOD GetPropertyStore, :ptr IPropertyStoreFactory, :GETPROPERTYSTOREFLAGS, :ptr IUnknown, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IPropertyStoreFactory, GetPropertyStoreForKeys)
          STD_METHOD GetPropertyStoreForKeys, :ptr IPropertyStoreFactory, :ptr PROPERTYKEY, :UINT, :GETPROPERTYSTOREFLAGS, :REFIID, :ptr ptr
          ??Interface equ <>
          END_INTERFACE
        IPropertyStoreFactoryVtbl ends
        IPropertyStoreFactory struct
          lpVtbl POINTER ?
        IPropertyStoreFactory ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IDelayedPropertyStoreFactory_INTERFACE_DEFINED__
      __IDelayedPropertyStoreFactory_INTERFACE_DEFINED__ equ <>
      externdef IID_IDelayedPropertyStoreFactory:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IDelayedPropertyStoreFactoryVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IDelayedPropertyStoreFactoryVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IDelayedPropertyStoreFactory, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IDelayedPropertyStoreFactory
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IDelayedPropertyStoreFactory
          DECLSPEC_XFGVIRT(IPropertyStoreFactory, GetPropertyStore)
          STD_METHOD GetPropertyStore, :ptr IDelayedPropertyStoreFactory, :GETPROPERTYSTOREFLAGS, :ptr IUnknown, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IPropertyStoreFactory, GetPropertyStoreForKeys)
          STD_METHOD GetPropertyStoreForKeys, :ptr IDelayedPropertyStoreFactory, :ptr PROPERTYKEY, :UINT, :GETPROPERTYSTOREFLAGS, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IDelayedPropertyStoreFactory, GetDelayedPropertyStore)
          STD_METHOD GetDelayedPropertyStore, :ptr IDelayedPropertyStoreFactory, :GETPROPERTYSTOREFLAGS, :DWORD, :REFIID, :ptr ptr
          ??Interface equ <>
          END_INTERFACE
        IDelayedPropertyStoreFactoryVtbl ends
        IDelayedPropertyStoreFactory struct
          lpVtbl POINTER ?
        IDelayedPropertyStoreFactory ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    _PERSIST_SPROPSTORE_FLAGS typedef SDWORD
    FPSPS_DEFAULT equ 0
    FPSPS_READONLY equ 1h
    FPSPS_TREAT_NEW_VALUES_AS_DIRTY equ 2h

    PERSIST_SPROPSTORE_FLAGS typedef SDWORD
    SERIALIZEDPROPSTORAGE typedef tagSERIALIZEDPROPSTORAGE
    PUSERIALIZEDPROPSTORAGE typedef ptr SERIALIZEDPROPSTORAGE
    PCUSERIALIZEDPROPSTORAGE typedef ptr SERIALIZEDPROPSTORAGE
    externdef __MIDL_itf_propsys_0000_0021_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_propsys_0000_0021_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IPersistSerializedPropStorage_INTERFACE_DEFINED__
      __IPersistSerializedPropStorage_INTERFACE_DEFINED__ equ <>
      externdef IID_IPersistSerializedPropStorage:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPersistSerializedPropStorageVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPersistSerializedPropStorageVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IPersistSerializedPropStorage, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPersistSerializedPropStorage
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPersistSerializedPropStorage
          DECLSPEC_XFGVIRT(IPersistSerializedPropStorage, SetFlags)
          STD_METHOD SetFlags, :ptr IPersistSerializedPropStorage, :PERSIST_SPROPSTORE_FLAGS
          DECLSPEC_XFGVIRT(IPersistSerializedPropStorage, SetPropertyStorage)
          STD_METHOD SetPropertyStorage, :ptr IPersistSerializedPropStorage, :PCUSERIALIZEDPROPSTORAGE, :DWORD
          DECLSPEC_XFGVIRT(IPersistSerializedPropStorage, GetPropertyStorage)
          STD_METHOD GetPropertyStorage, :ptr IPersistSerializedPropStorage, :ptr ptr SERIALIZEDPROPSTORAGE, :ptr DWORD
          ??Interface equ <>
          END_INTERFACE
        IPersistSerializedPropStorageVtbl ends
        IPersistSerializedPropStorage struct
          lpVtbl POINTER ?
        IPersistSerializedPropStorage ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IPersistSerializedPropStorage2_INTERFACE_DEFINED__
      __IPersistSerializedPropStorage2_INTERFACE_DEFINED__ equ <>
      externdef IID_IPersistSerializedPropStorage2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPersistSerializedPropStorage2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPersistSerializedPropStorage2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IPersistSerializedPropStorage2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPersistSerializedPropStorage2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPersistSerializedPropStorage2
          DECLSPEC_XFGVIRT(IPersistSerializedPropStorage, SetFlags)
          STD_METHOD SetFlags, :ptr IPersistSerializedPropStorage2, :PERSIST_SPROPSTORE_FLAGS
          DECLSPEC_XFGVIRT(IPersistSerializedPropStorage, SetPropertyStorage)
          STD_METHOD SetPropertyStorage, :ptr IPersistSerializedPropStorage2, :PCUSERIALIZEDPROPSTORAGE, :DWORD
          DECLSPEC_XFGVIRT(IPersistSerializedPropStorage, GetPropertyStorage)
          STD_METHOD GetPropertyStorage, :ptr IPersistSerializedPropStorage2, :ptr ptr SERIALIZEDPROPSTORAGE, :ptr DWORD
          DECLSPEC_XFGVIRT(IPersistSerializedPropStorage2, GetPropertyStorageSize)
          STD_METHOD GetPropertyStorageSize, :ptr IPersistSerializedPropStorage2, :ptr DWORD
          DECLSPEC_XFGVIRT(IPersistSerializedPropStorage2, GetPropertyStorageBuffer)
          STD_METHOD GetPropertyStorageBuffer, :ptr IPersistSerializedPropStorage2, :ptr SERIALIZEDPROPSTORAGE, :DWORD, :ptr DWORD
          ??Interface equ <>
          END_INTERFACE
        IPersistSerializedPropStorage2Vtbl ends
        IPersistSerializedPropStorage2 struct
          lpVtbl POINTER ?
        IPersistSerializedPropStorage2 ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IPropertySystemChangeNotify_INTERFACE_DEFINED__
      __IPropertySystemChangeNotify_INTERFACE_DEFINED__ equ <>
      externdef IID_IPropertySystemChangeNotify:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPropertySystemChangeNotifyVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPropertySystemChangeNotifyVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IPropertySystemChangeNotify, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPropertySystemChangeNotify
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPropertySystemChangeNotify
          DECLSPEC_XFGVIRT(IPropertySystemChangeNotify, SchemaRefreshed)
          STD_METHOD SchemaRefreshed, :ptr IPropertySystemChangeNotify
          ??Interface equ <>
          END_INTERFACE
        IPropertySystemChangeNotifyVtbl ends
        IPropertySystemChangeNotify struct
          lpVtbl POINTER ?
        IPropertySystemChangeNotify ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __ICreateObject_INTERFACE_DEFINED__
      __ICreateObject_INTERFACE_DEFINED__ equ <>
      externdef IID_ICreateObject:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ICreateObjectVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ICreateObjectVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ICreateObject, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ICreateObject
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ICreateObject
          DECLSPEC_XFGVIRT(ICreateObject, CreateObject)
          STD_METHOD CreateObject, :ptr ICreateObject, :REFCLSID, :ptr IUnknown, :REFIID, :ptr ptr
          ??Interface equ <>
          END_INTERFACE
        ICreateObjectVtbl ends
        ICreateObject struct
          lpVtbl POINTER ?
        ICreateObject ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    @DefProto DllImport, PSFormatForDisplay, WIN_STD_CALL_CONV,, <:REFPROPERTYKEY, :REFPROPVARIANT, :PROPDESC_FORMAT_FLAGS, :LPWSTR, :DWORD>, 20
    @DefProto DllImport, PSFormatForDisplayAlloc, WIN_STD_CALL_CONV,, <:REFPROPERTYKEY, :REFPROPVARIANT, :PROPDESC_FORMAT_FLAGS, :ptr PWSTR>, 16
    @DefProto DllImport, PSFormatPropertyValue, WIN_STD_CALL_CONV,, <:ptr IPropertyStore, :ptr IPropertyDescription, :PROPDESC_FORMAT_FLAGS, :ptr LPWSTR>, 16
    @DefProto DllImport, PSGetImageReferenceForValue, WIN_STD_CALL_CONV,, <:REFPROPERTYKEY, :REFPROPVARIANT, :ptr PWSTR>, 12
    PKEY_PIDSTR_MAX equ 10
    GUIDSTRING_MAX equ (1 + 8 + 1 + 4 + 1 + 4 + 1 + 4 + 1 + 12 + 1 + 1)
    PKEYSTR_MAX equ (GUIDSTRING_MAX + 1 + PKEY_PIDSTR_MAX)
    @DefProto DllImport, PSStringFromPropertyKey, WIN_STD_CALL_CONV,, <:REFPROPERTYKEY, :LPWSTR, :UINT>, 12
    @DefProto DllImport, PSPropertyKeyFromString, WIN_STD_CALL_CONV,, <:LPCWSTR, :ptr PROPERTYKEY>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
    @DefProto DllImport, PSCreateMemoryPropertyStore, WIN_STD_CALL_CONV,, <:REFIID, :ptr ptr>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    @DefProto DllImport, PSCreateDelayedMultiplexPropertyStore, WIN_STD_CALL_CONV,, <:GETPROPERTYSTOREFLAGS, :ptr IDelayedPropertyStoreFactory, :ptr DWORD, :DWORD, :REFIID, :ptr ptr>, 24
    @DefProto DllImport, PSCreateMultiplexPropertyStore, WIN_STD_CALL_CONV,, <:ptr ptr IUnknown, :DWORD, :REFIID, :ptr ptr>, 16
    @DefProto DllImport, PSCreatePropertyChangeArray, WIN_STD_CALL_CONV,, <:ptr PROPERTYKEY, :ptr PKA_FLAGS, :ptr PROPVARIANT, :UINT, :REFIID, :ptr ptr>, 24
    @DefProto DllImport, PSCreateSimplePropertyChange, WIN_STD_CALL_CONV,, <:PKA_FLAGS, :REFPROPERTYKEY, :REFPROPVARIANT, :REFIID, :ptr ptr>, 20
    @DefProto DllImport, PSGetPropertyDescription, WIN_STD_CALL_CONV,, <:REFPROPERTYKEY, :REFIID, :ptr ptr>, 12
    @DefProto DllImport, PSGetPropertyDescriptionByName, WIN_STD_CALL_CONV,, <:LPCWSTR, :REFIID, :ptr ptr>, 12
    @DefProto DllImport, PSLookupPropertyHandlerCLSID, WIN_STD_CALL_CONV,, <:PCWSTR, :ptr CLSID>, 8
    @DefProto DllImport, PSGetItemPropertyHandler, WIN_STD_CALL_CONV,, <:ptr IUnknown, :BOOL, :REFIID, :ptr ptr>, 16
    @DefProto DllImport, PSGetItemPropertyHandlerWithCreateObject, WIN_STD_CALL_CONV,, <:ptr IUnknown, :BOOL, :ptr IUnknown, :REFIID, :ptr ptr>, 20
    @DefProto DllImport, PSGetPropertyValue, WIN_STD_CALL_CONV,, <:ptr IPropertyStore, :ptr IPropertyDescription, :ptr PROPVARIANT>, 12
    @DefProto DllImport, PSSetPropertyValue, WIN_STD_CALL_CONV,, <:ptr IPropertyStore, :ptr IPropertyDescription, :REFPROPVARIANT>, 12
    @DefProto DllImport, PSRegisterPropertySchema, WIN_STD_CALL_CONV,, <:PCWSTR>, 4
    @DefProto DllImport, PSUnregisterPropertySchema, WIN_STD_CALL_CONV,, <:PCWSTR>, 4
    @DefProto DllImport, PSRefreshPropertySchema, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, PSEnumeratePropertyDescriptions, WIN_STD_CALL_CONV,, <:PROPDESC_ENUMFILTER, :REFIID, :ptr ptr>, 12
    @DefProto DllImport, PSGetPropertyKeyFromName, WIN_STD_CALL_CONV,, <:PCWSTR, :ptr PROPERTYKEY>, 8
    @DefProto DllImport, PSGetNameFromPropertyKey, WIN_STD_CALL_CONV,, <:REFPROPERTYKEY, :ptr PWSTR>, 8
    @DefProto DllImport, PSCoerceToCanonicalValue, WIN_STD_CALL_CONV,, <:REFPROPERTYKEY, :ptr PROPVARIANT>, 8
    @DefProto DllImport, PSGetPropertyDescriptionListFromString, WIN_STD_CALL_CONV,, <:LPCWSTR, :REFIID, :ptr ptr>, 12
    @DefProto DllImport, PSCreatePropertyStoreFromPropertySetStorage, WIN_STD_CALL_CONV,, <:ptr IPropertySetStorage, :DWORD, :REFIID, :ptr ptr>, 16
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
    @DefProto DllImport, PSCreatePropertyStoreFromObject, WIN_STD_CALL_CONV,, <:ptr IUnknown, :DWORD, :REFIID, :ptr ptr>, 16
    @DefProto DllImport, PSCreateAdapterFromPropertyStore, WIN_STD_CALL_CONV,, <:ptr IPropertyStore, :REFIID, :ptr ptr>, 12
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    @DefProto DllImport, PSGetPropertySystem, WIN_STD_CALL_CONV,, <:REFIID, :ptr ptr>, 8
    @DefProto DllImport, PSGetPropertyFromPropertyStorage, WIN_STD_CALL_CONV,, <:PCUSERIALIZEDPROPSTORAGE, :DWORD, :REFPROPERTYKEY, :ptr PROPVARIANT>, 16
    @DefProto DllImport, PSGetNamedPropertyFromPropertyStorage, WIN_STD_CALL_CONV,, <:PCUSERIALIZEDPROPSTORAGE, :DWORD, :LPCWSTR, :ptr PROPVARIANT>, 16
    @DefProto DllImport, PSPropertyBag_ReadType, WIN_STD_CALL_CONV,, <:ptr IPropertyBag, :LPCWSTR, :ptr VARIANT, :VARTYPE>, 16
    @DefProto DllImport, PSPropertyBag_ReadStr, WIN_STD_CALL_CONV,, <:ptr IPropertyBag, :LPCWSTR, :LPWSTR, :SDWORD>, 16
    @DefProto DllImport, PSPropertyBag_ReadStrAlloc, WIN_STD_CALL_CONV,, <:ptr IPropertyBag, :LPCWSTR, :ptr PWSTR>, 12
    @DefProto DllImport, PSPropertyBag_ReadBSTR, WIN_STD_CALL_CONV,, <:ptr IPropertyBag, :LPCWSTR, :ptr BSTR>, 12
    @DefProto DllImport, PSPropertyBag_WriteStr, WIN_STD_CALL_CONV,, <:ptr IPropertyBag, :LPCWSTR, :LPCWSTR>, 12
    @DefProto DllImport, PSPropertyBag_WriteBSTR, WIN_STD_CALL_CONV,, <:ptr IPropertyBag, :LPCWSTR, :BSTR>, 12
    @DefProto DllImport, PSPropertyBag_ReadInt, WIN_STD_CALL_CONV,, <:ptr IPropertyBag, :LPCWSTR, :ptr INT_>, 12
    @DefProto DllImport, PSPropertyBag_WriteInt, WIN_STD_CALL_CONV,, <:ptr IPropertyBag, :LPCWSTR, :INT_>, 12
    @DefProto DllImport, PSPropertyBag_ReadSHORT, WIN_STD_CALL_CONV,, <:ptr IPropertyBag, :LPCWSTR, :ptr SHORT_>, 12
    @DefProto DllImport, PSPropertyBag_WriteSHORT, WIN_STD_CALL_CONV,, <:ptr IPropertyBag, :LPCWSTR, :SHORT_>, 12
    @DefProto DllImport, PSPropertyBag_ReadLONG, WIN_STD_CALL_CONV,, <:ptr IPropertyBag, :LPCWSTR, :ptr LONG>, 12
    @DefProto DllImport, PSPropertyBag_WriteLONG, WIN_STD_CALL_CONV,, <:ptr IPropertyBag, :LPCWSTR, :LONG>, 12
    @DefProto DllImport, PSPropertyBag_ReadDWORD, WIN_STD_CALL_CONV,, <:ptr IPropertyBag, :LPCWSTR, :ptr DWORD>, 12
    @DefProto DllImport, PSPropertyBag_WriteDWORD, WIN_STD_CALL_CONV,, <:ptr IPropertyBag, :LPCWSTR, :DWORD>, 12
    @DefProto DllImport, PSPropertyBag_ReadBOOL, WIN_STD_CALL_CONV,, <:ptr IPropertyBag, :LPCWSTR, :ptr BOOL>, 12
    @DefProto DllImport, PSPropertyBag_WriteBOOL, WIN_STD_CALL_CONV,, <:ptr IPropertyBag, :LPCWSTR, :BOOL>, 12
    @DefProto DllImport, PSPropertyBag_ReadPOINTL, WIN_STD_CALL_CONV,, <:ptr IPropertyBag, :LPCWSTR, :ptr POINTL>, 12
    @DefProto DllImport, PSPropertyBag_WritePOINTL, WIN_STD_CALL_CONV,, <:ptr IPropertyBag, :LPCWSTR, :ptr POINTL>, 12
    @DefProto DllImport, PSPropertyBag_ReadPOINTS, WIN_STD_CALL_CONV,, <:ptr IPropertyBag, :LPCWSTR, :ptr POINTS>, 12
    @DefProto DllImport, PSPropertyBag_WritePOINTS, WIN_STD_CALL_CONV,, <:ptr IPropertyBag, :LPCWSTR, :ptr POINTS>, 12
    @DefProto DllImport, PSPropertyBag_ReadRECTL, WIN_STD_CALL_CONV,, <:ptr IPropertyBag, :LPCWSTR, :ptr RECTL>, 12
    @DefProto DllImport, PSPropertyBag_WriteRECTL, WIN_STD_CALL_CONV,, <:ptr IPropertyBag, :LPCWSTR, :ptr RECTL>, 12
    @DefProto DllImport, PSPropertyBag_ReadStream, WIN_STD_CALL_CONV,, <:ptr IPropertyBag, :LPCWSTR, :ptr ptr IStream>, 12
    @DefProto DllImport, PSPropertyBag_WriteStream, WIN_STD_CALL_CONV,, <:ptr IPropertyBag, :LPCWSTR, :ptr IStream>, 12
    @DefProto DllImport, PSPropertyBag_Delete, WIN_STD_CALL_CONV,, <:ptr IPropertyBag, :LPCWSTR>, 8
    @DefProto DllImport, PSPropertyBag_ReadULONGLONG, WIN_STD_CALL_CONV,, <:ptr IPropertyBag, :LPCWSTR, :ptr ULONGLONG>, 12
    @DefProto DllImport, PSPropertyBag_WriteULONGLONG, WIN_STD_CALL_CONV,, <:ptr IPropertyBag, :LPCWSTR, :ULONGLONG>, 12
    @DefProto DllImport, PSPropertyBag_ReadUnknown, WIN_STD_CALL_CONV,, <:ptr IPropertyBag, :LPCWSTR, :REFIID, :ptr ptr>, 16
    @DefProto DllImport, PSPropertyBag_WriteUnknown, WIN_STD_CALL_CONV,, <:ptr IPropertyBag, :LPCWSTR, :ptr IUnknown>, 12
    @DefProto DllImport, PSPropertyBag_ReadGUID, WIN_STD_CALL_CONV,, <:ptr IPropertyBag, :LPCWSTR, :ptr GUID>, 12
    @DefProto DllImport, PSPropertyBag_WriteGUID, WIN_STD_CALL_CONV,, <:ptr IPropertyBag, :LPCWSTR, :ptr GUID>, 12
    @DefProto DllImport, PSPropertyBag_ReadPropertyKey, WIN_STD_CALL_CONV,, <:ptr IPropertyBag, :LPCWSTR, :ptr PROPERTYKEY>, 12
    @DefProto DllImport, PSPropertyBag_WritePropertyKey, WIN_STD_CALL_CONV,, <:ptr IPropertyBag, :LPCWSTR, :REFPROPERTYKEY>, 12
    externdef __MIDL_itf_propsys_0000_0025_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_propsys_0000_0025_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __PropSysObjects_LIBRARY_DEFINED__
      __PropSysObjects_LIBRARY_DEFINED__ equ <>
      externdef LIBID_PropSysObjects:IID
      externdef CLSID_InMemoryPropertyStore:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_InMemoryPropertyStoreMarshalByValue:CLSID
      ifdef __cplusplus
        ;[...]
      endif
      externdef CLSID_PropertySystem:CLSID
      ifdef __cplusplus
        ;[...]
      endif
    endif
    if _MSC_VER ge 1200
    endif
  endif
  externdef __MIDL_itf_propsys_0000_0026_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_propsys_0000_0026_v0_0_s_ifspec:RPC_IF_HANDLE
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
  IInitializeWithStream_Initialize_Proxy proto WIN_STD_CALL_CONV :ptr IInitializeWithStream, :ptr IStream, :DWORD
  IInitializeWithStream_Initialize_Stub proto WIN_STD_CALL_CONV :ptr IInitializeWithStream, :ptr IStream, :DWORD
  IPropertyDescription_CoerceToCanonicalValue_Proxy proto WIN_STD_CALL_CONV :ptr IPropertyDescription, :ptr PROPVARIANT
  IPropertyDescription_CoerceToCanonicalValue_Stub proto WIN_STD_CALL_CONV :ptr IPropertyDescription, :REFPROPVARIANT, :ptr PROPVARIANT
  ifdef __cplusplus
    ;[...]
  endif
endif
