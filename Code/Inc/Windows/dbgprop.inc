;Include file created by h2incX, Version C.01.00, 20/07/2019 16:32
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'D:\ObjAsm\Projects\32\h2IncX\Header_10.0.17763.0\dbgprop.h', last modified: 22/10/2018 21:37
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
ifndef __dbgprop_h__
  __dbgprop_h__ equ <>
  if Defined(_MSC_VER) and (_MSC_VER ge 1020)
  endif
  ifndef __IDebugProperty_FWD_DEFINED__
    __IDebugProperty_FWD_DEFINED__ equ <>
    ;IDebugProperty typedef IDebugProperty
    
  endif
  ifndef __IEnumDebugPropertyInfo_FWD_DEFINED__
    __IEnumDebugPropertyInfo_FWD_DEFINED__ equ <>
    ;IEnumDebugPropertyInfo typedef IEnumDebugPropertyInfo
    
  endif
  ifndef __IDebugExtendedProperty_FWD_DEFINED__
    __IDebugExtendedProperty_FWD_DEFINED__ equ <>
    ;IDebugExtendedProperty typedef IDebugExtendedProperty
    
  endif
  ifndef __IEnumDebugExtendedPropertyInfo_FWD_DEFINED__
    __IEnumDebugExtendedPropertyInfo_FWD_DEFINED__ equ <>
    ;IEnumDebugExtendedPropertyInfo typedef IEnumDebugExtendedPropertyInfo
    
  endif
  ifndef __IPerPropertyBrowsing2_FWD_DEFINED__
    __IPerPropertyBrowsing2_FWD_DEFINED__ equ <>
    ;IPerPropertyBrowsing2 typedef IPerPropertyBrowsing2
    
  endif
  ifndef __IDebugPropertyEnumType_All_FWD_DEFINED__
    __IDebugPropertyEnumType_All_FWD_DEFINED__ equ <>
    ;IDebugPropertyEnumType_All typedef IDebugPropertyEnumType_All
    
  endif
  ifndef __IDebugPropertyEnumType_Locals_FWD_DEFINED__
    __IDebugPropertyEnumType_Locals_FWD_DEFINED__ equ <>
    ;IDebugPropertyEnumType_Locals typedef IDebugPropertyEnumType_Locals
    
  endif
  ifndef __IDebugPropertyEnumType_Arguments_FWD_DEFINED__
    __IDebugPropertyEnumType_Arguments_FWD_DEFINED__ equ <>
    ;IDebugPropertyEnumType_Arguments typedef IDebugPropertyEnumType_Arguments
    
  endif
  ifndef __IDebugPropertyEnumType_LocalsPlusArgs_FWD_DEFINED__
    __IDebugPropertyEnumType_LocalsPlusArgs_FWD_DEFINED__ equ <>
    ;IDebugPropertyEnumType_LocalsPlusArgs typedef IDebugPropertyEnumType_LocalsPlusArgs
    
  endif
  ifndef __IDebugPropertyEnumType_Registers_FWD_DEFINED__
    __IDebugPropertyEnumType_Registers_FWD_DEFINED__ equ <>
    ;IDebugPropertyEnumType_Registers typedef IDebugPropertyEnumType_Registers
    
  endif
  include ocidl.inc
  ifdef __cplusplus
    ;[...]
  endif
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    externdef guidDocument:GUID
    externdef guidCodeContext:GUID
    __MIDL___MIDL_itf_dbgprop_0000_0000_0001 typedef SDWORD
    DBGPROP_ATTRIB_NO_ATTRIB equ 0
    DBGPROP_ATTRIB_VALUE_IS_INVALID equ 8h
    DBGPROP_ATTRIB_VALUE_IS_EXPANDABLE equ 10h
    DBGPROP_ATTRIB_VALUE_IS_FAKE equ 20h
    DBGPROP_ATTRIB_VALUE_IS_METHOD equ 100h
    DBGPROP_ATTRIB_VALUE_IS_EVENT equ 200h
    DBGPROP_ATTRIB_VALUE_IS_RAW_STRING equ 400h
    DBGPROP_ATTRIB_VALUE_READONLY equ 800h
    DBGPROP_ATTRIB_ACCESS_PUBLIC equ 1000h
    DBGPROP_ATTRIB_ACCESS_PRIVATE equ 2000h
    DBGPROP_ATTRIB_ACCESS_PROTECTED equ 4000h
    DBGPROP_ATTRIB_ACCESS_FINAL equ 8000h
    DBGPROP_ATTRIB_STORAGE_GLOBAL equ 10000h
    DBGPROP_ATTRIB_STORAGE_STATIC equ 20000h
    DBGPROP_ATTRIB_STORAGE_FIELD equ 40000h
    DBGPROP_ATTRIB_STORAGE_VIRTUAL equ 80000h
    DBGPROP_ATTRIB_TYPE_IS_CONSTANT equ 100000h
    DBGPROP_ATTRIB_TYPE_IS_SYNCHRONIZED equ 200000h
    DBGPROP_ATTRIB_TYPE_IS_VOLATILE equ 400000h
    DBGPROP_ATTRIB_HAS_EXTENDED_ATTRIBS equ 800000h
    DBGPROP_ATTRIB_FRAME_INTRYBLOCK equ 1000000h
    DBGPROP_ATTRIB_FRAME_INCATCHBLOCK equ 2000000h
    DBGPROP_ATTRIB_FRAME_INFINALLYBLOCK equ 4000000h
    DBGPROP_ATTRIB_VALUE_IS_RETURN_VALUE equ 8000000h
    DBGPROP_ATTRIB_VALUE_PENDING_MUTATION equ 10000000h
    
    DBGPROP_ATTRIB_FLAGS typedef DWORD
    __MIDL___MIDL_itf_dbgprop_0000_0000_0002 typedef SDWORD
    DBGPROP_INFO_NAME equ 1h
    DBGPROP_INFO_TYPE equ 2h
    DBGPROP_INFO_VALUE equ 4h
    DBGPROP_INFO_FULLNAME equ 20h
    DBGPROP_INFO_ATTRIBUTES equ 8h
    DBGPROP_INFO_DEBUGPROP equ 10h
    DBGPROP_INFO_BEAUTIFY equ 2000000h
    DBGPROP_INFO_CALLTOSTRING equ 4000000h
    DBGPROP_INFO_AUTOEXPAND equ 8000000h
    
    DBGPROP_INFO_FLAGS typedef DWORD
    DBGPROP_INFO_STANDARD equ <((((DBGPROP_INFO_NAME or DBGPROP_INFO_TYPE) or DBGPROP_INFO_VALUE) or DBGPROP_INFO_ATTRIBUTES))>
    DBGPROP_INFO_ALL equ <((((((DBGPROP_INFO_NAME or DBGPROP_INFO_TYPE) or DBGPROP_INFO_VALUE) or DBGPROP_INFO_FULLNAME) or DBGPROP_INFO_ATTRIBUTES) or DBGPROP_INFO_DEBUGPROP))>
    OBJECT_ATTRIB_FLAGS typedef SDWORD
    OBJECT_ATTRIB_NO_ATTRIB equ 0
    OBJECT_ATTRIB_NO_NAME equ 1h
    OBJECT_ATTRIB_NO_TYPE equ 2h
    OBJECT_ATTRIB_NO_VALUE equ 4h
    OBJECT_ATTRIB_VALUE_IS_INVALID equ 8h
    OBJECT_ATTRIB_VALUE_IS_OBJECT equ 10h
    OBJECT_ATTRIB_VALUE_IS_ENUM equ 20h
    OBJECT_ATTRIB_VALUE_IS_CUSTOM equ 40h
    OBJECT_ATTRIB_OBJECT_IS_EXPANDABLE equ 70h
    OBJECT_ATTRIB_VALUE_HAS_CODE equ 80h
    OBJECT_ATTRIB_TYPE_IS_OBJECT equ 100h
    OBJECT_ATTRIB_TYPE_HAS_CODE equ 200h
    OBJECT_ATTRIB_TYPE_IS_EXPANDABLE equ 100h
    OBJECT_ATTRIB_SLOT_IS_CATEGORY equ 400h
    OBJECT_ATTRIB_VALUE_READONLY equ 800h
    OBJECT_ATTRIB_ACCESS_PUBLIC equ 1000h
    OBJECT_ATTRIB_ACCESS_PRIVATE equ 2000h
    OBJECT_ATTRIB_ACCESS_PROTECTED equ 4000h
    OBJECT_ATTRIB_ACCESS_FINAL equ 8000h
    OBJECT_ATTRIB_STORAGE_GLOBAL equ 10000h
    OBJECT_ATTRIB_STORAGE_STATIC equ 20000h
    OBJECT_ATTRIB_STORAGE_FIELD equ 40000h
    OBJECT_ATTRIB_STORAGE_VIRTUAL equ 80000h
    OBJECT_ATTRIB_TYPE_IS_CONSTANT equ 100000h
    OBJECT_ATTRIB_TYPE_IS_SYNCHRONIZED equ 200000h
    OBJECT_ATTRIB_TYPE_IS_VOLATILE equ 400000h
    OBJECT_ATTRIB_HAS_EXTENDED_ATTRIBS equ 800000h
    OBJECT_ATTRIB_IS_CLASS equ 1000000h
    OBJECT_ATTRIB_IS_FUNCTION equ 2000000h
    OBJECT_ATTRIB_IS_VARIABLE equ 4000000h
    OBJECT_ATTRIB_IS_PROPERTY equ 8000000h
    OBJECT_ATTRIB_IS_MACRO equ 10000000h
    OBJECT_ATTRIB_IS_TYPE equ 20000000h
    OBJECT_ATTRIB_IS_INHERITED equ 40000000h
    OBJECT_ATTRIB_IS_INTERFACE equ 80000000h
    tagOBJECT_ATTRIB_FLAG typedef OBJECT_ATTRIB_FLAGS
    
    PROP_INFO_FLAGS typedef SDWORD
    PROP_INFO_NAME equ 1h
    PROP_INFO_TYPE equ 2h
    PROP_INFO_VALUE equ 4h
    PROP_INFO_FULLNAME equ 20h
    PROP_INFO_ATTRIBUTES equ 8h
    PROP_INFO_DEBUGPROP equ 10h
    PROP_INFO_AUTOEXPAND equ 8000000h
    tagPROP_INFO_FLAGS typedef PROP_INFO_FLAGS
    
    PROP_INFO_STANDARD equ <((((PROP_INFO_NAME or PROP_INFO_TYPE) or PROP_INFO_VALUE) or PROP_INFO_ATTRIBUTES))>
    PROP_INFO_ALL equ <((((((PROP_INFO_NAME or PROP_INFO_TYPE) or PROP_INFO_VALUE) or PROP_INFO_FULLNAME) or PROP_INFO_ATTRIBUTES) or PROP_INFO_DEBUGPROP))>
    DebugPropertyInfo struct
      m_dwValidFields DWORD ?
      m_bstrName BSTR ?
      m_bstrType BSTR ?
      m_bstrValue BSTR ?
      m_bstrFullName BSTR ?
      m_dwAttrib DWORD ?
      m_pDebugProp POINTER ?
    DebugPropertyInfo ends

    tagDebugPropertyInfo typedef DebugPropertyInfo
    EX_PROP_INFO_FLAGS typedef SDWORD
    EX_PROP_INFO_ID equ 100h
    EX_PROP_INFO_NTYPE equ 200h
    EX_PROP_INFO_NVALUE equ 400h
    EX_PROP_INFO_LOCKBYTES equ 800h
    EX_PROP_INFO_DEBUGEXTPROP equ 1000h
    tagEX_PROP_INFO_FLAGS typedef EX_PROP_INFO_FLAGS
    
    ExtendedDebugPropertyInfo struct
      dwValidFields DWORD ?
      pszName LPOLESTR ?
      pszType LPOLESTR ?
      pszValue LPOLESTR ?
      pszFullName LPOLESTR ?
      dwAttrib DWORD ?
      pDebugProp POINTER ?
      nDISPID DWORD ?
      nType DWORD ?
      varValue VARIANT <>
      plbValue POINTER ?
      pDebugExtProp POINTER ?
    ExtendedDebugPropertyInfo ends

    tagExtendedDebugPropertyInfo typedef ExtendedDebugPropertyInfo
    externdef __MIDL_itf_dbgprop_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_dbgprop_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IDebugProperty_INTERFACE_DEFINED__
      __IDebugProperty_INTERFACE_DEFINED__ equ <>
      externdef IID_IDebugProperty:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IDebugPropertyVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IDebugPropertyVtbl>
          STD_METHOD QueryInterface, :ptr IDebugProperty, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IDebugProperty
          STD_METHOD Release, :ptr IDebugProperty
          STD_METHOD GetPropertyInfo, :ptr IDebugProperty, :DWORD, :UINT, :ptr DebugPropertyInfo
          STD_METHOD GetExtendedInfo, :ptr IDebugProperty, :ULONG, :ptr GUID, :ptr VARIANT
          STD_METHOD SetValueAsString, :ptr IDebugProperty, :LPCOLESTR, :UINT
          STD_METHOD EnumMembers, :ptr IDebugProperty, :DWORD, :UINT, :REFIID, :ptr ptr IEnumDebugPropertyInfo
          STD_METHOD GetParent, :ptr IDebugProperty, :ptr ptr IDebugProperty
          ??Interface equ <>
          END_INTERFACE
        IDebugPropertyVtbl ends

        IDebugProperty struct
          lpVtbl POINTER ?
        IDebugProperty ends

        ifdef COBJMACROS
          ;[...]
        endif
      endif
      IDebugProperty_RemoteGetPropertyInfo_Proxy proto WIN_STD_CALL_CONV :ptr IDebugProperty, :DWORD, :UINT, :ptr DWORD, :ptr BSTR, :ptr BSTR, :ptr BSTR, :ptr BSTR, :ptr DWORD, :ptr ptr IDebugProperty
      IDebugProperty_RemoteGetPropertyInfo_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
    endif
    ifndef __IEnumDebugPropertyInfo_INTERFACE_DEFINED__
      __IEnumDebugPropertyInfo_INTERFACE_DEFINED__ equ <>
      externdef IID_IEnumDebugPropertyInfo:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IEnumDebugPropertyInfoVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IEnumDebugPropertyInfoVtbl>
          STD_METHOD QueryInterface, :ptr IEnumDebugPropertyInfo, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IEnumDebugPropertyInfo
          STD_METHOD Release, :ptr IEnumDebugPropertyInfo
          STD_METHOD Next, :ptr IEnumDebugPropertyInfo, :ULONG, :ptr DebugPropertyInfo, :ptr ULONG
          STD_METHOD Skip, :ptr IEnumDebugPropertyInfo, :ULONG
          STD_METHOD Reset, :ptr IEnumDebugPropertyInfo
          STD_METHOD Clone, :ptr IEnumDebugPropertyInfo, :ptr ptr IEnumDebugPropertyInfo
          STD_METHOD GetCount, :ptr IEnumDebugPropertyInfo, :ptr ULONG
          ??Interface equ <>
          END_INTERFACE
        IEnumDebugPropertyInfoVtbl ends

        IEnumDebugPropertyInfo struct
          lpVtbl POINTER ?
        IEnumDebugPropertyInfo ends

        ifdef COBJMACROS
          ;[...]
        endif
      endif
      IEnumDebugPropertyInfo_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumDebugPropertyInfo, :ULONG, :ptr DebugPropertyInfo, :ptr ULONG
      IEnumDebugPropertyInfo_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
    endif
    ifndef __IDebugExtendedProperty_INTERFACE_DEFINED__
      __IDebugExtendedProperty_INTERFACE_DEFINED__ equ <>
      externdef IID_IDebugExtendedProperty:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IDebugExtendedPropertyVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IDebugExtendedPropertyVtbl>
          STD_METHOD QueryInterface, :ptr IDebugExtendedProperty, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IDebugExtendedProperty
          STD_METHOD Release, :ptr IDebugExtendedProperty
          STD_METHOD GetPropertyInfo, :ptr IDebugExtendedProperty, :DWORD, :UINT, :ptr DebugPropertyInfo
          STD_METHOD GetExtendedInfo, :ptr IDebugExtendedProperty, :ULONG, :ptr GUID, :ptr VARIANT
          STD_METHOD SetValueAsString, :ptr IDebugExtendedProperty, :LPCOLESTR, :UINT
          STD_METHOD EnumMembers, :ptr IDebugExtendedProperty, :DWORD, :UINT, :REFIID, :ptr ptr IEnumDebugPropertyInfo
          STD_METHOD GetParent, :ptr IDebugExtendedProperty, :ptr ptr IDebugProperty
          STD_METHOD GetExtendedPropertyInfo, :ptr IDebugExtendedProperty, :DWORD, :UINT, :ptr ExtendedDebugPropertyInfo
          STD_METHOD EnumExtendedMembers, :ptr IDebugExtendedProperty, :DWORD, :UINT, :ptr ptr IEnumDebugExtendedPropertyInfo
          ??Interface equ <>
          END_INTERFACE
        IDebugExtendedPropertyVtbl ends

        IDebugExtendedProperty struct
          lpVtbl POINTER ?
        IDebugExtendedProperty ends

        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IEnumDebugExtendedPropertyInfo_INTERFACE_DEFINED__
      __IEnumDebugExtendedPropertyInfo_INTERFACE_DEFINED__ equ <>
      externdef IID_IEnumDebugExtendedPropertyInfo:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IEnumDebugExtendedPropertyInfoVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IEnumDebugExtendedPropertyInfoVtbl>
          STD_METHOD QueryInterface, :ptr IEnumDebugExtendedPropertyInfo, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IEnumDebugExtendedPropertyInfo
          STD_METHOD Release, :ptr IEnumDebugExtendedPropertyInfo
          STD_METHOD Next, :ptr IEnumDebugExtendedPropertyInfo, :ULONG, :ptr ExtendedDebugPropertyInfo, :ptr ULONG
          STD_METHOD Skip, :ptr IEnumDebugExtendedPropertyInfo, :ULONG
          STD_METHOD Reset, :ptr IEnumDebugExtendedPropertyInfo
          STD_METHOD Clone, :ptr IEnumDebugExtendedPropertyInfo, :ptr ptr IEnumDebugExtendedPropertyInfo
          STD_METHOD GetCount, :ptr IEnumDebugExtendedPropertyInfo, :ptr ULONG
          ??Interface equ <>
          END_INTERFACE
        IEnumDebugExtendedPropertyInfoVtbl ends

        IEnumDebugExtendedPropertyInfo struct
          lpVtbl POINTER ?
        IEnumDebugExtendedPropertyInfo ends

        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IPerPropertyBrowsing2_INTERFACE_DEFINED__
      __IPerPropertyBrowsing2_INTERFACE_DEFINED__ equ <>
      externdef IID_IPerPropertyBrowsing2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPerPropertyBrowsing2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPerPropertyBrowsing2Vtbl>
          STD_METHOD QueryInterface, :ptr IPerPropertyBrowsing2, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IPerPropertyBrowsing2
          STD_METHOD Release, :ptr IPerPropertyBrowsing2
          STD_METHOD GetDisplayString, :ptr IPerPropertyBrowsing2, :DISPID, :ptr BSTR
          STD_METHOD MapPropertyToPage, :ptr IPerPropertyBrowsing2, :DISPID, :ptr CLSID
          STD_METHOD GetPredefinedStrings, :ptr IPerPropertyBrowsing2, :DISPID, :ptr CALPOLESTR, :ptr CADWORD
          STD_METHOD SetPredefinedValue, :ptr IPerPropertyBrowsing2, :DISPID, :DWORD
          ??Interface equ <>
          END_INTERFACE
        IPerPropertyBrowsing2Vtbl ends

        IPerPropertyBrowsing2 struct
          lpVtbl POINTER ?
        IPerPropertyBrowsing2 ends

        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IDebugPropertyEnumType_All_INTERFACE_DEFINED__
      __IDebugPropertyEnumType_All_INTERFACE_DEFINED__ equ <>
      externdef IID_IDebugPropertyEnumType_All:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IDebugPropertyEnumType_AllVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IDebugPropertyEnumType_AllVtbl>
          STD_METHOD QueryInterface, :ptr IDebugPropertyEnumType_All, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IDebugPropertyEnumType_All
          STD_METHOD Release, :ptr IDebugPropertyEnumType_All
          STD_METHOD GetName, :ptr IDebugPropertyEnumType_All, :ptr BSTR
          ??Interface equ <>
          END_INTERFACE
        IDebugPropertyEnumType_AllVtbl ends

        IDebugPropertyEnumType_All struct
          lpVtbl POINTER ?
        IDebugPropertyEnumType_All ends

        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IDebugPropertyEnumType_Locals_INTERFACE_DEFINED__
      __IDebugPropertyEnumType_Locals_INTERFACE_DEFINED__ equ <>
      externdef IID_IDebugPropertyEnumType_Locals:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IDebugPropertyEnumType_LocalsVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IDebugPropertyEnumType_LocalsVtbl>
          STD_METHOD QueryInterface, :ptr IDebugPropertyEnumType_Locals, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IDebugPropertyEnumType_Locals
          STD_METHOD Release, :ptr IDebugPropertyEnumType_Locals
          STD_METHOD GetName, :ptr IDebugPropertyEnumType_Locals, :ptr BSTR
          ??Interface equ <>
          END_INTERFACE
        IDebugPropertyEnumType_LocalsVtbl ends

        IDebugPropertyEnumType_Locals struct
          lpVtbl POINTER ?
        IDebugPropertyEnumType_Locals ends

        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IDebugPropertyEnumType_Arguments_INTERFACE_DEFINED__
      __IDebugPropertyEnumType_Arguments_INTERFACE_DEFINED__ equ <>
      externdef IID_IDebugPropertyEnumType_Arguments:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IDebugPropertyEnumType_ArgumentsVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IDebugPropertyEnumType_ArgumentsVtbl>
          STD_METHOD QueryInterface, :ptr IDebugPropertyEnumType_Arguments, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IDebugPropertyEnumType_Arguments
          STD_METHOD Release, :ptr IDebugPropertyEnumType_Arguments
          STD_METHOD GetName, :ptr IDebugPropertyEnumType_Arguments, :ptr BSTR
          ??Interface equ <>
          END_INTERFACE
        IDebugPropertyEnumType_ArgumentsVtbl ends

        IDebugPropertyEnumType_Arguments struct
          lpVtbl POINTER ?
        IDebugPropertyEnumType_Arguments ends

        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IDebugPropertyEnumType_LocalsPlusArgs_INTERFACE_DEFINED__
      __IDebugPropertyEnumType_LocalsPlusArgs_INTERFACE_DEFINED__ equ <>
      externdef IID_IDebugPropertyEnumType_LocalsPlusArgs:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IDebugPropertyEnumType_LocalsPlusArgsVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IDebugPropertyEnumType_LocalsPlusArgsVtbl>
          STD_METHOD QueryInterface, :ptr IDebugPropertyEnumType_LocalsPlusArgs, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IDebugPropertyEnumType_LocalsPlusArgs
          STD_METHOD Release, :ptr IDebugPropertyEnumType_LocalsPlusArgs
          STD_METHOD GetName, :ptr IDebugPropertyEnumType_LocalsPlusArgs, :ptr BSTR
          ??Interface equ <>
          END_INTERFACE
        IDebugPropertyEnumType_LocalsPlusArgsVtbl ends

        IDebugPropertyEnumType_LocalsPlusArgs struct
          lpVtbl POINTER ?
        IDebugPropertyEnumType_LocalsPlusArgs ends

        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IDebugPropertyEnumType_Registers_INTERFACE_DEFINED__
      __IDebugPropertyEnumType_Registers_INTERFACE_DEFINED__ equ <>
      externdef IID_IDebugPropertyEnumType_Registers:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IDebugPropertyEnumType_RegistersVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IDebugPropertyEnumType_RegistersVtbl>
          STD_METHOD QueryInterface, :ptr IDebugPropertyEnumType_Registers, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IDebugPropertyEnumType_Registers
          STD_METHOD Release, :ptr IDebugPropertyEnumType_Registers
          STD_METHOD GetName, :ptr IDebugPropertyEnumType_Registers, :ptr BSTR
          ??Interface equ <>
          END_INTERFACE
        IDebugPropertyEnumType_RegistersVtbl ends

        IDebugPropertyEnumType_Registers struct
          lpVtbl POINTER ?
        IDebugPropertyEnumType_Registers ends

        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
  endif
  externdef __MIDL_itf_dbgprop_0000_0010_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_dbgprop_0000_0010_v0_0_s_ifspec:RPC_IF_HANDLE
  BSTR_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr BSTR
  BSTR_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BSTR
  VARIANT_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr VARIANT
  VARIANT_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr VARIANT
  VARIANT_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr VARIANT
  VARIANT_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr VARIANT
  BSTR_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr BSTR
  BSTR_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BSTR
  VARIANT_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr VARIANT
  VARIANT_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr VARIANT
  VARIANT_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr VARIANT
  VARIANT_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr VARIANT
  IDebugProperty_GetPropertyInfo_Proxy proto WIN_STD_CALL_CONV :ptr IDebugProperty, :DWORD, :UINT, :ptr DebugPropertyInfo
  IDebugProperty_GetPropertyInfo_Stub proto WIN_STD_CALL_CONV :ptr IDebugProperty, :DWORD, :UINT, :ptr DWORD, :ptr BSTR, :ptr BSTR, :ptr BSTR, :ptr BSTR, :ptr DWORD, :ptr ptr IDebugProperty
  IEnumDebugPropertyInfo_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumDebugPropertyInfo, :ULONG, :ptr DebugPropertyInfo, :ptr ULONG
  IEnumDebugPropertyInfo_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumDebugPropertyInfo, :ULONG, :ptr DebugPropertyInfo, :ptr ULONG
  ifdef __cplusplus
    ;[...]
  endif
endif
 