;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\namespaceapi.h
;             Created on (UTC) 06/04/2024 06:15:57
;             Last modified on (UTC) 21/02/2024 18:13:22

ifdef _MSC_VER
endif
ifndef _APISETNAMESPACE_
  _APISETNAMESPACE_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  include minwinbase.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    PRIVATE_NAMESPACE_FLAG_DESTROY equ 00000001h
    @DefProto DllImport, CreatePrivateNamespaceW, WIN_STD_CALL_CONV,, <:LPSECURITY_ATTRIBUTES, :LPVOID, :LPCWSTR>, 12
    @DefProto DllImport, OpenPrivateNamespaceW, WIN_STD_CALL_CONV,, <:LPVOID, :LPCWSTR>, 8
    @DefProto DllImport, ClosePrivateNamespace, WIN_STD_CALL_CONV,, <:HANDLE, :ULONG>, 8
    @DefProto DllImport, CreateBoundaryDescriptorW, WIN_STD_CALL_CONV,, <:LPCWSTR, :ULONG>, 8
    @DefProto DllImport, AddSIDToBoundaryDescriptor, WIN_STD_CALL_CONV,, <:ptr HANDLE, :PSID>, 8
    @DefProto DllImport, DeleteBoundaryDescriptor, WIN_STD_CALL_CONV,, <:HANDLE>, 4
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
