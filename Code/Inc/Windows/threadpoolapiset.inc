;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\threadpoolapiset.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 21/02/2024 18:13:22

ifdef _MSC_VER
endif
ifndef _THREADPOOLAPISET_H_
  _THREADPOOLAPISET_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  include minwinbase.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    TYPE_PTP_WIN32_IO_CALLBACK typedef proto WIN_STD_CALL_CONV :PTP_CALLBACK_INSTANCE, :PVOID, :PVOID, :ULONG, :ULONG_PTR, :PTP_IO
    PTP_WIN32_IO_CALLBACK typedef ptr TYPE_PTP_WIN32_IO_CALLBACK

    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, CreateThreadpool, WIN_STD_CALL_CONV,, <:PVOID>, 4
      @DefProto DllImport, SetThreadpoolThreadMaximum, WIN_STD_CALL_CONV,, <:PTP_POOL, :DWORD>, 8
      @DefProto DllImport, SetThreadpoolThreadMinimum, WIN_STD_CALL_CONV,, <:PTP_POOL, :DWORD>, 8
      @DefProto DllImport, SetThreadpoolStackInformation, WIN_STD_CALL_CONV,, <:PTP_POOL, :PTP_POOL_STACK_INFORMATION>, 8
      @DefProto DllImport, QueryThreadpoolStackInformation, WIN_STD_CALL_CONV,, <:PTP_POOL, :PTP_POOL_STACK_INFORMATION>, 8
      @DefProto DllImport, CloseThreadpool, WIN_STD_CALL_CONV,, <:PTP_POOL>, 4
      @DefProto DllImport, CreateThreadpoolCleanupGroup, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, CloseThreadpoolCleanupGroupMembers, WIN_STD_CALL_CONV,, <:PTP_CLEANUP_GROUP, :BOOL, :PVOID>, 12
      @DefProto DllImport, CloseThreadpoolCleanupGroup, WIN_STD_CALL_CONV,, <:PTP_CLEANUP_GROUP>, 4
      @DefProto DllImport, SetEventWhenCallbackReturns, WIN_STD_CALL_CONV,, <:PTP_CALLBACK_INSTANCE, :HANDLE>, 8
      @DefProto DllImport, ReleaseSemaphoreWhenCallbackReturns, WIN_STD_CALL_CONV,, <:PTP_CALLBACK_INSTANCE, :HANDLE, :DWORD>, 12
      @DefProto DllImport, ReleaseMutexWhenCallbackReturns, WIN_STD_CALL_CONV,, <:PTP_CALLBACK_INSTANCE, :HANDLE>, 8
      @DefProto DllImport, LeaveCriticalSectionWhenCallbackReturns, WIN_STD_CALL_CONV,, <:PTP_CALLBACK_INSTANCE, :PCRITICAL_SECTION>, 8
      @DefProto DllImport, FreeLibraryWhenCallbackReturns, WIN_STD_CALL_CONV,, <:PTP_CALLBACK_INSTANCE, :HMODULE>, 8
      @DefProto DllImport, CallbackMayRunLong, WIN_STD_CALL_CONV,, <:PTP_CALLBACK_INSTANCE>, 4
      @DefProto DllImport, DisassociateCurrentThreadFromCallback, WIN_STD_CALL_CONV,, <:PTP_CALLBACK_INSTANCE>, 4
      @DefProto DllImport, TrySubmitThreadpoolCallback, WIN_STD_CALL_CONV,, <:PTP_SIMPLE_CALLBACK, :PVOID, :PTP_CALLBACK_ENVIRON>, 12
      @DefProto DllImport, CreateThreadpoolWork, WIN_STD_CALL_CONV,, <:PTP_WORK_CALLBACK, :PVOID, :PTP_CALLBACK_ENVIRON>, 12
      @DefProto DllImport, SubmitThreadpoolWork, WIN_STD_CALL_CONV,, <:PTP_WORK>, 4
      @DefProto DllImport, WaitForThreadpoolWorkCallbacks, WIN_STD_CALL_CONV,, <:PTP_WORK, :BOOL>, 8
      @DefProto DllImport, CloseThreadpoolWork, WIN_STD_CALL_CONV,, <:PTP_WORK>, 4
      @DefProto DllImport, CreateThreadpoolTimer, WIN_STD_CALL_CONV,, <:PTP_TIMER_CALLBACK, :PVOID, :PTP_CALLBACK_ENVIRON>, 12
      @DefProto DllImport, SetThreadpoolTimer, WIN_STD_CALL_CONV,, <:PTP_TIMER, :PFILETIME, :DWORD, :DWORD>, 16
      @DefProto DllImport, IsThreadpoolTimerSet, WIN_STD_CALL_CONV,, <:PTP_TIMER>, 4
      @DefProto DllImport, WaitForThreadpoolTimerCallbacks, WIN_STD_CALL_CONV,, <:PTP_TIMER, :BOOL>, 8
      @DefProto DllImport, CloseThreadpoolTimer, WIN_STD_CALL_CONV,, <:PTP_TIMER>, 4
      @DefProto DllImport, CreateThreadpoolWait, WIN_STD_CALL_CONV,, <:PTP_WAIT_CALLBACK, :PVOID, :PTP_CALLBACK_ENVIRON>, 12
      @DefProto DllImport, SetThreadpoolWait, WIN_STD_CALL_CONV,, <:PTP_WAIT, :HANDLE, :PFILETIME>, 12
      @DefProto DllImport, WaitForThreadpoolWaitCallbacks, WIN_STD_CALL_CONV,, <:PTP_WAIT, :BOOL>, 8
      @DefProto DllImport, CloseThreadpoolWait, WIN_STD_CALL_CONV,, <:PTP_WAIT>, 4
      @DefProto DllImport, CreateThreadpoolIo, WIN_STD_CALL_CONV,, <:HANDLE, :PTP_WIN32_IO_CALLBACK, :PVOID, :PTP_CALLBACK_ENVIRON>, 16
      @DefProto DllImport, StartThreadpoolIo, WIN_STD_CALL_CONV,, <:PTP_IO>, 4
      @DefProto DllImport, CancelThreadpoolIo, WIN_STD_CALL_CONV,, <:PTP_IO>, 4
      @DefProto DllImport, WaitForThreadpoolIoCallbacks, WIN_STD_CALL_CONV,, <:PTP_IO, :BOOL>, 8
      @DefProto DllImport, CloseThreadpoolIo, WIN_STD_CALL_CONV,, <:PTP_IO>, 4
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, SetThreadpoolTimerEx, WIN_STD_CALL_CONV,, <:PTP_TIMER, :PFILETIME, :DWORD, :DWORD>, 16
      @DefProto DllImport, SetThreadpoolWaitEx, WIN_STD_CALL_CONV,, <:PTP_WAIT, :HANDLE, :PFILETIME, :PVOID>, 16
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    if (_WIN32_WINNT ge 0600h)
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
