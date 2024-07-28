;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\namespaceapi.h', last modified: 19/04/2018 10:43
;Creation parameters: 

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

