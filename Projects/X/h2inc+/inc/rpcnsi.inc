;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\rpcnsi.h
;             Created on (UTC) 06/04/2024 06:15:57
;             Last modified on (UTC) 16/12/2023 11:07:04

include winapifamily.inc
ifndef __RPCNSI_H__
  __RPCNSI_H__ equ <>
  if _MSC_VER gt 1000
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    RPC_NS_HANDLE typedef ptr
    RPC_C_NS_SYNTAX_DEFAULT equ 0
    RPC_C_NS_SYNTAX_DCE equ 3
    RPC_C_PROFILE_DEFAULT_ELT equ 0
    RPC_C_PROFILE_ALL_ELT equ 1
    RPC_C_PROFILE_ALL_ELTS equ <RPC_C_PROFILE_ALL_ELT>
    RPC_C_PROFILE_MATCH_BY_IF equ 2
    RPC_C_PROFILE_MATCH_BY_MBR equ 3
    RPC_C_PROFILE_MATCH_BY_BOTH equ 4
    RPC_C_NS_DEFAULT_EXP_AGE equ -1
    @DefProto DllImport, RpcNsBindingExportA, WIN_STD_CALL_CONV,, <:DWORD, :RPC_CSTR, :RPC_IF_HANDLE, :ptr RPC_BINDING_VECTOR, :ptr UUID_VECTOR>, 20
    @DefProto DllImport, RpcNsBindingUnexportA, WIN_STD_CALL_CONV,, <:DWORD, :RPC_CSTR, :RPC_IF_HANDLE, :ptr UUID_VECTOR>, 16
    ifdef RPC_UNICODE_SUPPORTED
      @DefProto DllImport, RpcNsBindingExportW, WIN_STD_CALL_CONV,, <:DWORD, :RPC_WSTR, :RPC_IF_HANDLE, :ptr RPC_BINDING_VECTOR, :ptr UUID_VECTOR>, 20
      @DefProto DllImport, RpcNsBindingUnexportW, WIN_STD_CALL_CONV,, <:DWORD, :RPC_WSTR, :RPC_IF_HANDLE, :ptr UUID_VECTOR>, 16
    endif
    RpcNsBindingExportPnPA proto WIN_STD_CALL_CONV :DWORD, :RPC_CSTR, :RPC_IF_HANDLE, :ptr UUID_VECTOR
    RpcNsBindingUnexportPnPA proto WIN_STD_CALL_CONV :DWORD, :RPC_CSTR, :RPC_IF_HANDLE, :ptr UUID_VECTOR
    ifdef RPC_UNICODE_SUPPORTED
      RpcNsBindingExportPnPW proto WIN_STD_CALL_CONV :DWORD, :RPC_WSTR, :RPC_IF_HANDLE, :ptr UUID_VECTOR
      RpcNsBindingUnexportPnPW proto WIN_STD_CALL_CONV :DWORD, :RPC_WSTR, :RPC_IF_HANDLE, :ptr UUID_VECTOR
    endif
    @DefProto DllImport, RpcNsBindingLookupBeginA, WIN_STD_CALL_CONV,, <:DWORD, :RPC_CSTR, :RPC_IF_HANDLE, :ptr UUID, :DWORD, :ptr RPC_NS_HANDLE>, 24
    ifdef RPC_UNICODE_SUPPORTED
      @DefProto DllImport, RpcNsBindingLookupBeginW, WIN_STD_CALL_CONV,, <:DWORD, :RPC_WSTR, :RPC_IF_HANDLE, :ptr UUID, :DWORD, :ptr RPC_NS_HANDLE>, 24
    endif
    @DefProto DllImport, RpcNsBindingLookupNext, WIN_STD_CALL_CONV,, <:RPC_NS_HANDLE, :ptr ptr RPC_BINDING_VECTOR>, 8
    @DefProto DllImport, RpcNsBindingLookupDone, WIN_STD_CALL_CONV,, <:ptr RPC_NS_HANDLE>, 4
    @DefProto DllImport, RpcNsGroupDeleteA, WIN_STD_CALL_CONV,, <:DWORD, :RPC_CSTR>, 8
    @DefProto DllImport, RpcNsGroupMbrAddA, WIN_STD_CALL_CONV,, <:DWORD, :RPC_CSTR, :DWORD, :RPC_CSTR>, 16
    @DefProto DllImport, RpcNsGroupMbrRemoveA, WIN_STD_CALL_CONV,, <:DWORD, :RPC_CSTR, :DWORD, :RPC_CSTR>, 16
    @DefProto DllImport, RpcNsGroupMbrInqBeginA, WIN_STD_CALL_CONV,, <:DWORD, :RPC_CSTR, :DWORD, :ptr RPC_NS_HANDLE>, 16
    @DefProto DllImport, RpcNsGroupMbrInqNextA, WIN_STD_CALL_CONV,, <:RPC_NS_HANDLE, :ptr RPC_CSTR>, 8
    ifdef RPC_UNICODE_SUPPORTED
      @DefProto DllImport, RpcNsGroupDeleteW, WIN_STD_CALL_CONV,, <:DWORD, :RPC_WSTR>, 8
      @DefProto DllImport, RpcNsGroupMbrAddW, WIN_STD_CALL_CONV,, <:DWORD, :RPC_WSTR, :DWORD, :RPC_WSTR>, 16
      @DefProto DllImport, RpcNsGroupMbrRemoveW, WIN_STD_CALL_CONV,, <:DWORD, :RPC_WSTR, :DWORD, :RPC_WSTR>, 16
      @DefProto DllImport, RpcNsGroupMbrInqBeginW, WIN_STD_CALL_CONV,, <:DWORD, :RPC_WSTR, :DWORD, :ptr RPC_NS_HANDLE>, 16
      @DefProto DllImport, RpcNsGroupMbrInqNextW, WIN_STD_CALL_CONV,, <:RPC_NS_HANDLE, :ptr RPC_WSTR>, 8
    endif
    @DefProto DllImport, RpcNsGroupMbrInqDone, WIN_STD_CALL_CONV,, <:ptr RPC_NS_HANDLE>, 4
    @DefProto DllImport, RpcNsProfileDeleteA, WIN_STD_CALL_CONV,, <:DWORD, :RPC_CSTR>, 8
    @DefProto DllImport, RpcNsProfileEltAddA, WIN_STD_CALL_CONV,, <:DWORD, :RPC_CSTR, :ptr RPC_IF_ID, :DWORD, :RPC_CSTR, :DWORD, :RPC_CSTR>, 28
    @DefProto DllImport, RpcNsProfileEltRemoveA, WIN_STD_CALL_CONV,, <:DWORD, :RPC_CSTR, :ptr RPC_IF_ID, :DWORD, :RPC_CSTR>, 20
    @DefProto DllImport, RpcNsProfileEltInqBeginA, WIN_STD_CALL_CONV,, <:DWORD, :RPC_CSTR, :DWORD, :ptr RPC_IF_ID, :DWORD, :DWORD, :RPC_CSTR, :ptr RPC_NS_HANDLE>, 32
    @DefProto DllImport, RpcNsProfileEltInqNextA, WIN_STD_CALL_CONV,, <:RPC_NS_HANDLE, :ptr RPC_IF_ID, :ptr RPC_CSTR, :ptr DWORD, :ptr RPC_CSTR>, 20
    ifdef RPC_UNICODE_SUPPORTED
      @DefProto DllImport, RpcNsProfileDeleteW, WIN_STD_CALL_CONV,, <:DWORD, :RPC_WSTR>, 8
      @DefProto DllImport, RpcNsProfileEltAddW, WIN_STD_CALL_CONV,, <:DWORD, :RPC_WSTR, :ptr RPC_IF_ID, :DWORD, :RPC_WSTR, :DWORD, :RPC_WSTR>, 28
      @DefProto DllImport, RpcNsProfileEltRemoveW, WIN_STD_CALL_CONV,, <:DWORD, :RPC_WSTR, :ptr RPC_IF_ID, :DWORD, :RPC_WSTR>, 20
      @DefProto DllImport, RpcNsProfileEltInqBeginW, WIN_STD_CALL_CONV,, <:DWORD, :RPC_WSTR, :DWORD, :ptr RPC_IF_ID, :DWORD, :DWORD, :RPC_WSTR, :ptr RPC_NS_HANDLE>, 32
      @DefProto DllImport, RpcNsProfileEltInqNextW, WIN_STD_CALL_CONV,, <:RPC_NS_HANDLE, :ptr RPC_IF_ID, :ptr RPC_WSTR, :ptr DWORD, :ptr RPC_WSTR>, 20
    endif
    @DefProto DllImport, RpcNsProfileEltInqDone, WIN_STD_CALL_CONV,, <:ptr RPC_NS_HANDLE>, 4
    @DefProto DllImport, RpcNsEntryObjectInqBeginA, WIN_STD_CALL_CONV,, <:DWORD, :RPC_CSTR, :ptr RPC_NS_HANDLE>, 12
    ifdef RPC_UNICODE_SUPPORTED
      @DefProto DllImport, RpcNsEntryObjectInqBeginW, WIN_STD_CALL_CONV,, <:DWORD, :RPC_WSTR, :ptr RPC_NS_HANDLE>, 12
    endif
    @DefProto DllImport, RpcNsEntryObjectInqNext, WIN_STD_CALL_CONV,, <:RPC_NS_HANDLE, :ptr UUID>, 8
    @DefProto DllImport, RpcNsEntryObjectInqDone, WIN_STD_CALL_CONV,, <:ptr RPC_NS_HANDLE>, 4
    @DefProto DllImport, RpcNsEntryExpandNameA, WIN_STD_CALL_CONV,, <:DWORD, :RPC_CSTR, :ptr RPC_CSTR>, 12
    @DefProto DllImport, RpcNsMgmtBindingUnexportA, WIN_STD_CALL_CONV,, <:DWORD, :RPC_CSTR, :ptr RPC_IF_ID, :DWORD, :ptr UUID_VECTOR>, 20
    @DefProto DllImport, RpcNsMgmtEntryCreateA, WIN_STD_CALL_CONV,, <:DWORD, :RPC_CSTR>, 8
    @DefProto DllImport, RpcNsMgmtEntryDeleteA, WIN_STD_CALL_CONV,, <:DWORD, :RPC_CSTR>, 8
    @DefProto DllImport, RpcNsMgmtEntryInqIfIdsA, WIN_STD_CALL_CONV,, <:DWORD, :RPC_CSTR, :ptr ptr RPC_IF_ID_VECTOR>, 12
    @DefProto DllImport, RpcNsMgmtHandleSetExpAge, WIN_STD_CALL_CONV,, <:RPC_NS_HANDLE, :DWORD>, 8
    @DefProto DllImport, RpcNsMgmtInqExpAge, WIN_STD_CALL_CONV,, <:ptr DWORD>, 4
    @DefProto DllImport, RpcNsMgmtSetExpAge, WIN_STD_CALL_CONV,, <:DWORD>, 4
    ifdef RPC_UNICODE_SUPPORTED
      @DefProto DllImport, RpcNsEntryExpandNameW, WIN_STD_CALL_CONV,, <:DWORD, :RPC_WSTR, :ptr RPC_WSTR>, 12
      @DefProto DllImport, RpcNsMgmtBindingUnexportW, WIN_STD_CALL_CONV,, <:DWORD, :RPC_WSTR, :ptr RPC_IF_ID, :DWORD, :ptr UUID_VECTOR>, 20
      @DefProto DllImport, RpcNsMgmtEntryCreateW, WIN_STD_CALL_CONV,, <:DWORD, :RPC_WSTR>, 8
      @DefProto DllImport, RpcNsMgmtEntryDeleteW, WIN_STD_CALL_CONV,, <:DWORD, :RPC_WSTR>, 8
      @DefProto DllImport, RpcNsMgmtEntryInqIfIdsW, WIN_STD_CALL_CONV,, <:DWORD, :RPC_WSTR, :ptr ptr RPC_IF_ID_VECTOR>, 12
    endif
    @DefProto DllImport, RpcNsBindingImportBeginA, WIN_STD_CALL_CONV,, <:DWORD, :RPC_CSTR, :RPC_IF_HANDLE, :ptr UUID, :ptr RPC_NS_HANDLE>, 20
    ifdef RPC_UNICODE_SUPPORTED
      @DefProto DllImport, RpcNsBindingImportBeginW, WIN_STD_CALL_CONV,, <:DWORD, :RPC_WSTR, :RPC_IF_HANDLE, :ptr UUID, :ptr RPC_NS_HANDLE>, 20
    endif
    @DefProto DllImport, RpcNsBindingImportNext, WIN_STD_CALL_CONV,, <:RPC_NS_HANDLE, :ptr RPC_BINDING_HANDLE>, 8
    @DefProto DllImport, RpcNsBindingImportDone, WIN_STD_CALL_CONV,, <:ptr RPC_NS_HANDLE>, 4
    @DefProto DllImport, RpcNsBindingSelect, WIN_STD_CALL_CONV,, <:ptr RPC_BINDING_VECTOR, :ptr RPC_BINDING_HANDLE>, 8
    ifdef UNICODE
      RpcNsBindingLookupBegin equ <RpcNsBindingLookupBeginW>
      RpcNsBindingImportBegin equ <RpcNsBindingImportBeginW>
      RpcNsBindingExport equ <RpcNsBindingExportW>
      RpcNsBindingUnexport equ <RpcNsBindingUnexportW>
      RpcNsGroupDelete equ <RpcNsGroupDeleteW>
      RpcNsGroupMbrAdd equ <RpcNsGroupMbrAddW>
      RpcNsGroupMbrRemove equ <RpcNsGroupMbrRemoveW>
      RpcNsGroupMbrInqBegin equ <RpcNsGroupMbrInqBeginW>
      RpcNsGroupMbrInqNext equ <RpcNsGroupMbrInqNextW>
      RpcNsEntryExpandName equ <RpcNsEntryExpandNameW>
      RpcNsEntryObjectInqBegin equ <RpcNsEntryObjectInqBeginW>
      RpcNsMgmtBindingUnexport equ <RpcNsMgmtBindingUnexportW>
      RpcNsMgmtEntryCreate equ <RpcNsMgmtEntryCreateW>
      RpcNsMgmtEntryDelete equ <RpcNsMgmtEntryDeleteW>
      RpcNsMgmtEntryInqIfIds equ <RpcNsMgmtEntryInqIfIdsW>
      RpcNsProfileDelete equ <RpcNsProfileDeleteW>
      RpcNsProfileEltAdd equ <RpcNsProfileEltAddW>
      RpcNsProfileEltRemove equ <RpcNsProfileEltRemoveW>
      RpcNsProfileEltInqBegin equ <RpcNsProfileEltInqBeginW>
      RpcNsProfileEltInqNext equ <RpcNsProfileEltInqNextW>
      RpcNsBindingExportPnP equ <RpcNsBindingExportPnPW>
      RpcNsBindingUnexportPnP equ <RpcNsBindingUnexportPnPW>
    else
      RpcNsBindingLookupBegin equ <RpcNsBindingLookupBeginA>
      RpcNsBindingImportBegin equ <RpcNsBindingImportBeginA>
      RpcNsBindingExport equ <RpcNsBindingExportA>
      RpcNsBindingUnexport equ <RpcNsBindingUnexportA>
      RpcNsGroupDelete equ <RpcNsGroupDeleteA>
      RpcNsGroupMbrAdd equ <RpcNsGroupMbrAddA>
      RpcNsGroupMbrRemove equ <RpcNsGroupMbrRemoveA>
      RpcNsGroupMbrInqBegin equ <RpcNsGroupMbrInqBeginA>
      RpcNsGroupMbrInqNext equ <RpcNsGroupMbrInqNextA>
      RpcNsEntryExpandName equ <RpcNsEntryExpandNameA>
      RpcNsEntryObjectInqBegin equ <RpcNsEntryObjectInqBeginA>
      RpcNsMgmtBindingUnexport equ <RpcNsMgmtBindingUnexportA>
      RpcNsMgmtEntryCreate equ <RpcNsMgmtEntryCreateA>
      RpcNsMgmtEntryDelete equ <RpcNsMgmtEntryDeleteA>
      RpcNsMgmtEntryInqIfIds equ <RpcNsMgmtEntryInqIfIdsA>
      RpcNsProfileDelete equ <RpcNsProfileDeleteA>
      RpcNsProfileEltAdd equ <RpcNsProfileEltAddA>
      RpcNsProfileEltRemove equ <RpcNsProfileEltRemoveA>
      RpcNsProfileEltInqBegin equ <RpcNsProfileEltInqBeginA>
      RpcNsProfileEltInqNext equ <RpcNsProfileEltInqNextA>
      RpcNsBindingExportPnP equ <RpcNsBindingExportPnPA>
      RpcNsBindingUnexportPnP equ <RpcNsBindingUnexportPnPA>
    endif
  endif
endif
