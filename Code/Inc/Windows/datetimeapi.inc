;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\datetimeapi.h', last modified: 19/04/2018 10:43
;Creation parameters: 

ifdef _MSC_VER
endif
ifndef _DATETIMEAPI_H_
  _DATETIMEAPI_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  include minwinbase.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetDateFormatA, WIN_STD_CALL_CONV,, <:LCID, :DWORD, :ptr SYSTEMTIME, :LPCSTR, :LPSTR, :SDWORD>, 24
    @DefProto DllImport, GetDateFormatW, WIN_STD_CALL_CONV,, <:LCID, :DWORD, :ptr SYSTEMTIME, :LPCWSTR, :LPWSTR, :SDWORD>, 24
    ifdef UNICODE
      GetDateFormat equ <GetDateFormatW>
    else
      GetDateFormat equ <GetDateFormatA>
    endif
    @DefProto DllImport, GetTimeFormatA, WIN_STD_CALL_CONV,, <:LCID, :DWORD, :ptr SYSTEMTIME, :LPCSTR, :LPSTR, :SDWORD>, 24
    @DefProto DllImport, GetTimeFormatW, WIN_STD_CALL_CONV,, <:LCID, :DWORD, :ptr SYSTEMTIME, :LPCWSTR, :LPWSTR, :SDWORD>, 24
    ifdef UNICODE
      GetTimeFormat equ <GetTimeFormatW>
    else
      GetTimeFormat equ <GetTimeFormatA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetTimeFormatEx, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :ptr SYSTEMTIME, :LPCWSTR, :LPWSTR, :SDWORD>, 24
    @DefProto DllImport, GetDateFormatEx, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :ptr SYSTEMTIME, :LPCWSTR, :LPWSTR, :SDWORD, :LPCWSTR>, 28
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    GetDurationFormatEx_DEFINED equ <>
    @DefProto DllImport, GetDurationFormatEx, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :ptr SYSTEMTIME, :ULONGLONG, :LPCWSTR, :LPWSTR, :SDWORD>, 32
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

