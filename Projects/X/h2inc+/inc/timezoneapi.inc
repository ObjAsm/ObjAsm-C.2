;Include file created by h2inc+ version C.2.0 on (UTC) 26/05/2024 13:31:25
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\timezoneapi.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 21/02/2024 18:13:16

ifdef _MSC_VER
endif
ifndef _TIMEZONEAPI_H_
  _TIMEZONEAPI_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  include minwinbase.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    TIME_ZONE_ID_INVALID equ (0FFFFFFFFh)
    TIME_ZONE_INFORMATION struct
      Bias LONG ?
      StandardName WCHAR 32 dup (?)
      StandardDate SYSTEMTIME <>
      StandardBias LONG ?
      DaylightName WCHAR 32 dup (?)
      DaylightDate SYSTEMTIME <>
      DaylightBias LONG ?
    TIME_ZONE_INFORMATION ends
    _TIME_ZONE_INFORMATION typedef TIME_ZONE_INFORMATION
    PTIME_ZONE_INFORMATION typedef ptr TIME_ZONE_INFORMATION
    LPTIME_ZONE_INFORMATION typedef ptr TIME_ZONE_INFORMATION
    DYNAMIC_TIME_ZONE_INFORMATION struct
      Bias LONG ?
      StandardName WCHAR 32 dup (?)
      StandardDate SYSTEMTIME <>
      StandardBias LONG ?
      DaylightName WCHAR 32 dup (?)
      DaylightDate SYSTEMTIME <>
      DaylightBias LONG ?
      TimeZoneKeyName WCHAR 128 dup (?)
      DynamicDaylightTimeDisabled BOOLEAN ?
    DYNAMIC_TIME_ZONE_INFORMATION ends
    _TIME_DYNAMIC_ZONE_INFORMATION typedef DYNAMIC_TIME_ZONE_INFORMATION
    PDYNAMIC_TIME_ZONE_INFORMATION typedef ptr DYNAMIC_TIME_ZONE_INFORMATION
    @DefProto DllImport, SystemTimeToTzSpecificLocalTime, WIN_STD_CALL_CONV,, <:ptr TIME_ZONE_INFORMATION, :ptr SYSTEMTIME, :LPSYSTEMTIME>, 12
    @DefProto DllImport, TzSpecificLocalTimeToSystemTime, WIN_STD_CALL_CONV,, <:ptr TIME_ZONE_INFORMATION, :ptr SYSTEMTIME, :LPSYSTEMTIME>, 12
    @DefProto DllImport, FileTimeToSystemTime, WIN_STD_CALL_CONV,, <:ptr FILETIME, :LPSYSTEMTIME>, 8
    @DefProto DllImport, SystemTimeToFileTime, WIN_STD_CALL_CONV,, <:ptr SYSTEMTIME, :LPFILETIME>, 8
    @DefProto DllImport, GetTimeZoneInformation, WIN_STD_CALL_CONV,, <:LPTIME_ZONE_INFORMATION>, 4
    @DefProto DllImport, SetTimeZoneInformation, WIN_STD_CALL_CONV,, <:ptr TIME_ZONE_INFORMATION>, 4
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, SetDynamicTimeZoneInformation, WIN_STD_CALL_CONV,, <:ptr DYNAMIC_TIME_ZONE_INFORMATION>, 4
    endif
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, GetDynamicTimeZoneInformation, WIN_STD_CALL_CONV,, <:PDYNAMIC_TIME_ZONE_INFORMATION>, 4
    endif
    if (_WIN32_WINNT ge 0601h)
      GetTimeZoneInformationForYear proto WIN_STD_CALL_CONV :USHORT, :PDYNAMIC_TIME_ZONE_INFORMATION, :LPTIME_ZONE_INFORMATION
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
      @DefProto DllImport, EnumDynamicTimeZoneInformation, WIN_STD_CALL_CONV,, <:DWORD, :PDYNAMIC_TIME_ZONE_INFORMATION>, 8
      @DefProto DllImport, GetDynamicTimeZoneInformationEffectiveYears, WIN_STD_CALL_CONV,, <:PDYNAMIC_TIME_ZONE_INFORMATION, :LPDWORD, :LPDWORD>, 12
      @DefProto DllImport, SystemTimeToTzSpecificLocalTimeEx, WIN_STD_CALL_CONV,, <:ptr DYNAMIC_TIME_ZONE_INFORMATION, :ptr SYSTEMTIME, :LPSYSTEMTIME>, 12
      @DefProto DllImport, TzSpecificLocalTimeToSystemTimeEx, WIN_STD_CALL_CONV,, <:ptr DYNAMIC_TIME_ZONE_INFORMATION, :ptr SYSTEMTIME, :LPSYSTEMTIME>, 12
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_RS5)
      @DefProto DllImport, LocalFileTimeToLocalSystemTime, WIN_STD_CALL_CONV,, <:ptr TIME_ZONE_INFORMATION, :ptr FILETIME, :ptr SYSTEMTIME>, 12
      @DefProto DllImport, LocalSystemTimeToLocalFileTime, WIN_STD_CALL_CONV,, <:ptr TIME_ZONE_INFORMATION, :ptr SYSTEMTIME, :ptr FILETIME>, 12
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
