;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\mmiscapi2.h
;             Created on (UTC) 06/04/2024 06:15:56
;             Last modified on (UTC) 21/02/2024 18:13:22

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
