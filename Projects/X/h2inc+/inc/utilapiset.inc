;Include file created by h2inc+ version C.2.0 on (UTC) 26/05/2024 13:31:25
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\utilapiset.h
;             Created on (UTC) 06/04/2024 06:16:02
;             Last modified on (UTC) 21/02/2024 18:13:16

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
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, EncodePointer, WIN_STD_CALL_CONV,, <:PVOID>, 4
    @DefProto DllImport, DecodePointer, WIN_STD_CALL_CONV,, <:PVOID>, 4
    @DefProto DllImport, EncodeSystemPointer, WIN_STD_CALL_CONV,, <:PVOID>, 4
    @DefProto DllImport, DecodeSystemPointer, WIN_STD_CALL_CONV,, <:PVOID>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, EncodeRemotePointer, WIN_STD_CALL_CONV,, <:HANDLE, :PVOID, :ptr PVOID>, 12
    @DefProto DllImport, DecodeRemotePointer, WIN_STD_CALL_CONV,, <:HANDLE, :PVOID, :ptr PVOID>, 12
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_PC_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, Beep, WIN_STD_CALL_CONV,, <:DWORD, :DWORD>, 8
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
