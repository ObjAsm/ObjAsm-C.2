;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\realtimeapiset.h', last modified: 19/04/2018 10:43
;Creation parameters: 

ifdef _MSC_VER
endif
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
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, QueryInterruptTimePrecise, WIN_STD_CALL_CONV,, <:PULONGLONG>, 4
    @DefProto DllImport, QueryUnbiasedInterruptTimePrecise, WIN_STD_CALL_CONV,, <:PULONGLONG>, 4
    @DefProto DllImport, QueryInterruptTime, WIN_STD_CALL_CONV,, <:PULONGLONG>, 4
    if (_WIN32_WINNT ge 0601h)
      @DefProto DllImport, QueryUnbiasedInterruptTime, WIN_STD_CALL_CONV,, <:PULONGLONG>, 4
    endif
    @DefProto DllImport, QueryAuxiliaryCounterFrequency, WIN_STD_CALL_CONV,, <:PULONGLONG>, 4
    @DefProto DllImport, ConvertAuxiliaryCounterToPerformanceCounter, WIN_STD_CALL_CONV,, <:ULONGLONG, :PULONGLONG, :PULONGLONG>, 16
    @DefProto DllImport, ConvertPerformanceCounterToAuxiliaryCounter, WIN_STD_CALL_CONV,, <:ULONGLONG, :PULONGLONG, :PULONGLONG>, 16
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

