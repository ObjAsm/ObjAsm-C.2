;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\handleapi.h', last modified: 19/04/2018 10:43
;Creation parameters: 

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
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, CloseHandle, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    @DefProto DllImport, DuplicateHandle, WIN_STD_CALL_CONV,, <:HANDLE, :HANDLE, :HANDLE, :LPHANDLE, :DWORD, :BOOL, :DWORD>, 28
    @DefProto DllImport, CompareObjectHandles, WIN_STD_CALL_CONV,, <:HANDLE, :HANDLE>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetHandleInformation, WIN_STD_CALL_CONV,, <:HANDLE, :LPDWORD>, 8
    @DefProto DllImport, SetHandleInformation, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :DWORD>, 12
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

