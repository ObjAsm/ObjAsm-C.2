;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\enclaveapi.h', last modified: 19/04/2018 10:43
;Creation parameters: 

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

