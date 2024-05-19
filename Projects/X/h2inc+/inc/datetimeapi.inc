;Include file created by h2inc+ version C.2.0 on (UTC) 19/05/2024 07:52:23
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\datetimeapi.h\datetimeapi.h
;             Created on (UTC) 06/04/2024 06:15:53
;             Last modified on (UTC) 21/02/2024 18:13:14

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
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
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
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, GetTimeFormatEx, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :ptr SYSTEMTIME, :LPCWSTR, :LPWSTR, :SDWORD>, 24
    @DefProto DllImport, GetDateFormatEx, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :ptr SYSTEMTIME, :LPCWSTR, :LPWSTR, :SDWORD, :LPCWSTR>, 28
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    GetDurationFormatEx_DEFINED equ <>
    @DefProto DllImport, GetDurationFormatEx, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :ptr SYSTEMTIME, :ULONGLONG, :LPCWSTR, :LPWSTR, :SDWORD>, 28
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
