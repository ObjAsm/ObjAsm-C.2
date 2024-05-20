;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\mmiscapi2.h
;             Created on (UTC) 06/04/2024 06:15:56
;             Last modified on (UTC) 21/02/2024 18:13:22

;********************************************************************************
ifdef _MSC_VER
endif
; _MSC_VER
ifndef _MMISCAPI2_H_
  _MMISCAPI2_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include mmsyscom.inc
  ; mm common definitions
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    TYPE_TIMECALLBACK typedef proto WIN_STD_CALL_CONV :UINT, :UINT, :DWORD_PTR, :DWORD_PTR, :DWORD_PTR
    TIMECALLBACK typedef ptr TYPE_TIMECALLBACK

    LPTIMECALLBACK typedef ptr TIMECALLBACK
    ;* flags for fuEvent parameter of timeSetEvent() function *
    ;* program timer for single event *
    TIME_ONESHOT equ 0000h
    ;* program for continuous periodic event *
    TIME_PERIODIC equ 0001h
    ifdef _WIN32
      ;* callback is function *
      TIME_CALLBACK_FUNCTION equ 0000h
      ;* callback is event - use SetEvent *
      TIME_CALLBACK_EVENT_SET equ 0010h
      ;* callback is event - use PulseEvent *
      TIME_CALLBACK_EVENT_PULSE equ 0020h
    endif
    if WINVER ge 0501h
      ;* This flag prevents the event from occurring *
      TIME_KILL_SYNCHRONOUS equ 0100h
      ;* after the user calls timeKillEvent() to *
      ;* destroy it. *
    endif
    ; WINVER >= 0x0501
    @DefProto DllImport, timeSetEvent, WIN_STD_CALL_CONV,, <:UINT, :UINT, :LPTIMECALLBACK, :DWORD_PTR, :UINT>, 20
    @DefProto DllImport, timeKillEvent, WIN_STD_CALL_CONV,, <:UINT>, 4
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
  ifdef __cplusplus
    ;[...]
  endif
endif
; _MMISCAPI2_H_
