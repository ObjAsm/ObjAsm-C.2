;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\timeapi.h', last modified: 19/04/2018 10:43
;Creation parameters: 

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
      TIMERR_NOERROR equ 0
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
      @DefProto DllImport, timeGetTime, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, timeGetDevCaps, WIN_STD_CALL_CONV,, <:LPTIMECAPS, :UINT>, 8
      @DefProto DllImport, timeBeginPeriod, WIN_STD_CALL_CONV,, <:UINT>, 4
      @DefProto DllImport, timeEndPeriod, WIN_STD_CALL_CONV,, <:UINT>, 4
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

