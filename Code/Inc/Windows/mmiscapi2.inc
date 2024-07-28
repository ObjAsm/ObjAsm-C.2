;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\mmiscapi2.h', last modified: 19/04/2018 10:43
;Creation parameters: 

ifdef _MSC_VER
endif
ifndef _MMISCAPI2_H_
  _MMISCAPI2_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include mmsyscom.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    TYPE_TIMECALLBACK typedef proto WIN_STD_CALL_CONV :UINT, :UINT, :DWORD_PTR, :DWORD_PTR, :DWORD_PTR
    TIMECALLBACK typedef ptr TYPE_TIMECALLBACK
    LPTIMECALLBACK typedef ptr TIMECALLBACK
    TIME_ONESHOT equ 0000h
    TIME_PERIODIC equ 0001h
    ifdef _WIN32
      TIME_CALLBACK_FUNCTION equ 0000h
      TIME_CALLBACK_EVENT_SET equ 0010h
      TIME_CALLBACK_EVENT_PULSE equ 0020h
    endif
    if WINVER ge 0501h
      TIME_KILL_SYNCHRONOUS equ 0100h
    endif
    @DefProto DllImport, timeSetEvent, WIN_STD_CALL_CONV,, <:UINT, :UINT, :LPTIMECALLBACK, :DWORD_PTR, :UINT>, 20
    @DefProto DllImport, timeKillEvent, WIN_STD_CALL_CONV,, <:UINT>, 4
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

