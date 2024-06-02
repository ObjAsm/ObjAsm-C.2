;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\timeapi.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 21/02/2024 18:13:22

ifdef _MSC_VER
endif
ifndef _TIMERAPI_H_
  _TIMERAPI_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include mmsyscom.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    ifndef MMNOTIMER
      TIMERR_NOERROR equ (0)
      TIMERR_NOCANDO equ (TIMERR_BASE + 1)
      TIMERR_STRUCT equ (TIMERR_BASE + 33)
      TIMECAPS struct
        wPeriodMin UINT ?
        wPeriodMax UINT ?
      TIMECAPS ends
      timecaps_tag typedef TIMECAPS
      PTIMECAPS typedef ptr TIMECAPS
      NPTIMECAPS typedef ptr TIMECAPS
      LPTIMECAPS typedef ptr TIMECAPS
      @DefProto DllImport, timeGetSystemTime, WIN_STD_CALL_CONV,, <:LPMMTIME, :UINT>, 8
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, timeGetTime, WIN_STD_CALL_CONV,, <>, 0
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, timeGetDevCaps, WIN_STD_CALL_CONV,, <:LPTIMECAPS, :UINT>, 8
      @DefProto DllImport, timeBeginPeriod, WIN_STD_CALL_CONV,, <:UINT>, 4
      @DefProto DllImport, timeEndPeriod, WIN_STD_CALL_CONV,, <:UINT>, 4
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
