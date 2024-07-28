;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\threadpoollegacyapiset.h', last modified: 19/04/2018 10:43
;Creation parameters: 

ifdef _MSC_VER
endif
ifndef _THREADPOOLLEGACYAPISET_H_
  _THREADPOOLLEGACYAPISET_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  include minwinbase.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, QueueUserWorkItem, WIN_STD_CALL_CONV,, <:LPTHREAD_START_ROUTINE, :PVOID, :ULONG>, 12
    @DefProto DllImport, UnregisterWaitEx, WIN_STD_CALL_CONV,, <:HANDLE, :HANDLE>, 8
    @DefProto DllImport, CreateTimerQueue, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, CreateTimerQueueTimer, WIN_STD_CALL_CONV,, <:PHANDLE, :HANDLE, :WAITORTIMERCALLBACK, :PVOID, :DWORD, :DWORD, :ULONG>, 28
    @DefProto DllImport, ChangeTimerQueueTimer, WIN_STD_CALL_CONV,, <:HANDLE, :HANDLE, :ULONG, :ULONG>, 16
    @DefProto DllImport, DeleteTimerQueueTimer, WIN_STD_CALL_CONV,, <:HANDLE, :HANDLE, :HANDLE>, 12
    @DefProto DllImport, DeleteTimerQueueEx, WIN_STD_CALL_CONV,, <:HANDLE, :HANDLE>, 8
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

