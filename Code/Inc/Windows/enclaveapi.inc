;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\enclaveapi.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 21/02/2024 18:13:14

ifdef _MSC_VER
endif
ifndef _ENCLAVEAPI_H_
  _ENCLAVEAPI_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  include minwinbase.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_APP)
    @DefProto DllImport, IsEnclaveTypeSupported, WIN_STD_CALL_CONV,, <:DWORD>, 4
    @DefProto DllImport, CreateEnclave, WIN_STD_CALL_CONV,, <:HANDLE, :LPVOID, :SIZE_T, :SIZE_T, :DWORD, :LPCVOID, :DWORD, :LPDWORD>, 32
    @DefProto DllImport, LoadEnclaveData, WIN_STD_CALL_CONV,, <:HANDLE, :LPVOID, :LPCVOID, :SIZE_T, :DWORD, :LPCVOID, :DWORD, :PSIZE_T, :LPDWORD>, 36
    @DefProto DllImport, InitializeEnclave, WIN_STD_CALL_CONV,, <:HANDLE, :LPVOID, :LPCVOID, :DWORD, :LPDWORD>, 20
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, LoadEnclaveImageA, WIN_STD_CALL_CONV,, <:LPVOID, :LPCSTR>, 8
    @DefProto DllImport, LoadEnclaveImageW, WIN_STD_CALL_CONV,, <:LPVOID, :LPCWSTR>, 8
    ifdef UNICODE
      LoadEnclaveImage equ <LoadEnclaveImageW>
    else
      LoadEnclaveImage equ <LoadEnclaveImageA>
    endif
    @DefProto DllImport, CallEnclave, WIN_STD_CALL_CONV,, <:LPENCLAVE_ROUTINE, :LPVOID, :BOOL, :ptr LPVOID>, 16
    @DefProto DllImport, TerminateEnclave, WIN_STD_CALL_CONV,, <:LPVOID, :BOOL>, 8
    @DefProto DllImport, DeleteEnclave, WIN_STD_CALL_CONV,, <:LPVOID>, 4
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
