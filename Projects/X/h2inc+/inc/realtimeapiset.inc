;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\realtimeapiset.h
;             Created on (UTC) 06/04/2024 06:15:57
;             Last modified on (UTC) 21/02/2024 18:13:14

;********************************************************************************
ifdef _MSC_VER
endif
; _MSC_VER
ifndef _APISETREALTIME_
  _APISETREALTIME_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, QueryThreadCycleTime, WIN_STD_CALL_CONV,, <:HANDLE, :PULONG64>, 8
      @DefProto DllImport, QueryProcessCycleTime, WIN_STD_CALL_CONV,, <:HANDLE, :PULONG64>, 8
      @DefProto DllImport, QueryIdleProcessorCycleTime, WIN_STD_CALL_CONV,, <:PULONG, :PULONG64>, 8
    endif
    if (_WIN32_WINNT ge 0601h)
      @DefProto DllImport, QueryIdleProcessorCycleTimeEx, WIN_STD_CALL_CONV,, <:USHORT, :PULONG, :PULONG64>, 12
    endif
    ; (_WIN32_WINNT >= 0x0601)
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, QueryInterruptTimePrecise, WIN_STD_CALL_CONV,, <:PULONGLONG>, 4
    @DefProto DllImport, QueryUnbiasedInterruptTimePrecise, WIN_STD_CALL_CONV,, <:PULONGLONG>, 4
    @DefProto DllImport, QueryInterruptTime, WIN_STD_CALL_CONV,, <:PULONGLONG>, 4
    if (_WIN32_WINNT ge 0601h)
      @DefProto DllImport, QueryUnbiasedInterruptTime, WIN_STD_CALL_CONV,, <:PULONGLONG>, 4
    endif
    ; (_WIN32_WINNT >= 0x0601)
    @DefProto DllImport, QueryAuxiliaryCounterFrequency, WIN_STD_CALL_CONV,, <:PULONGLONG>, 4
    @DefProto DllImport, ConvertAuxiliaryCounterToPerformanceCounter, WIN_STD_CALL_CONV,, <:ULONGLONG, :PULONGLONG, :PULONGLONG>, 12
    @DefProto DllImport, ConvertPerformanceCounterToAuxiliaryCounter, WIN_STD_CALL_CONV,, <:ULONGLONG, :PULONGLONG, :PULONGLONG>, 12
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
; _APISETREALTIME_
