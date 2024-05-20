;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\profileapi.h
;             Created on (UTC) 06/04/2024 06:15:57
;             Last modified on (UTC) 21/02/2024 18:13:14

;********************************************************************************
ifdef _MSC_VER
endif
; _MSC_VER
ifndef _PROFILEAPI_H_
  _PROFILEAPI_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    ; Performance counter API's
    @DefProto DllImport, QueryPerformanceCounter, WIN_STD_CALL_CONV,, <:ptr LARGE_INTEGER>, 4
    @DefProto DllImport, QueryPerformanceFrequency, WIN_STD_CALL_CONV,, <:ptr LARGE_INTEGER>, 4
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
  ifdef __cplusplus
    ;[...]
  endif
endif
; _PROFILEAPI_H_
