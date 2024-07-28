;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\utilapiset.h', last modified: 19/04/2018 10:43
;Creation parameters: 

ifdef _MSC_VER
endif
ifndef _APISETUTIL_
  _APISETUTIL_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, EncodePointer, WIN_STD_CALL_CONV,, <:PVOID>, 4
    @DefProto DllImport, DecodePointer, WIN_STD_CALL_CONV,, <:PVOID>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, EncodeSystemPointer, WIN_STD_CALL_CONV,, <:PVOID>, 4
    @DefProto DllImport, DecodeSystemPointer, WIN_STD_CALL_CONV,, <:PVOID>, 4
    @DefProto DllImport, EncodeRemotePointer, WIN_STD_CALL_CONV,, <:HANDLE, :PVOID, :ptr PVOID>, 12
    @DefProto DllImport, DecodeRemotePointer, WIN_STD_CALL_CONV,, <:HANDLE, :PVOID, :ptr PVOID>, 12
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_PC_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, Beep, WIN_STD_CALL_CONV,, <:DWORD, :DWORD>, 8
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

