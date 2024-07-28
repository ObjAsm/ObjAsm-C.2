;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\timezoneapi.h', last modified: 19/04/2018 10:43
;Creation parameters: 

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
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
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
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, SetTimeZoneInformation, WIN_STD_CALL_CONV,, <:ptr TIME_ZONE_INFORMATION>, 4
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, SetDynamicTimeZoneInformation, WIN_STD_CALL_CONV,, <:ptr DYNAMIC_TIME_ZONE_INFORMATION>, 4
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
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
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

