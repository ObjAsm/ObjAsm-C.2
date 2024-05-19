;Include file created by h2inc+ version C.2.0 on (UTC) 19/05/2024 07:52:23
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\handleapi.h\handleapi.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 21/02/2024 18:13:14

ifdef _MSC_VER
endif
ifndef _APISETHANDLE_
  _APISETHANDLE_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  ifdef __cplusplus
    ;[...]
  endif
  INVALID_HANDLE_VALUE equ (- 1)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, CloseHandle, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    @DefProto DllImport, DuplicateHandle, WIN_STD_CALL_CONV,, <:HANDLE, :HANDLE, :HANDLE, :LPHANDLE, :DWORD, :BOOL, :DWORD>, 28
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, CompareObjectHandles, WIN_STD_CALL_CONV,, <:HANDLE, :HANDLE>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, GetHandleInformation, WIN_STD_CALL_CONV,, <:HANDLE, :LPDWORD>, 8
    @DefProto DllImport, SetHandleInformation, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :DWORD>, 12
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
