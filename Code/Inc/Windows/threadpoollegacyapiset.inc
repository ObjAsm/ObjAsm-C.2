;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\threadpoollegacyapiset.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 21/02/2024 18:13:14

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
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, QueueUserWorkItem, WIN_STD_CALL_CONV,, <:LPTHREAD_START_ROUTINE, :PVOID, :ULONG>, 12
    @DefProto DllImport, UnregisterWaitEx, WIN_STD_CALL_CONV,, <:HANDLE, :HANDLE>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, CreateTimerQueue, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, CreateTimerQueueTimer, WIN_STD_CALL_CONV,, <:PHANDLE, :HANDLE, :WAITORTIMERCALLBACK, :PVOID, :DWORD, :DWORD, :ULONG>, 28
    @DefProto DllImport, ChangeTimerQueueTimer, WIN_STD_CALL_CONV,, <:HANDLE, :HANDLE, :ULONG, :ULONG>, 16
    @DefProto DllImport, DeleteTimerQueueTimer, WIN_STD_CALL_CONV,, <:HANDLE, :HANDLE, :HANDLE>, 12
    @DefProto DllImport, DeleteTimerQueue, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    @DefProto DllImport, DeleteTimerQueueEx, WIN_STD_CALL_CONV,, <:HANDLE, :HANDLE>, 8
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
