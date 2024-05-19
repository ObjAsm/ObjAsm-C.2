;Include file created by h2inc+ version C.2.0 on (UTC) 19/05/2024 07:52:23
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\synchapi.h\synchapi.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 21/02/2024 18:13:16

ifdef _MSC_VER
endif
ifndef _SYNCHAPI_H_
  _SYNCHAPI_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  include minwinbase.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    SRWLOCK_INIT equ <RTL_SRWLOCK_INIT>
    SRWLOCK typedef RTL_SRWLOCK
    PSRWLOCK typedef ptr RTL_SRWLOCK
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, InitializeSRWLock, WIN_STD_CALL_CONV,, <:PSRWLOCK>, 4
      @DefProto DllImport, ReleaseSRWLockExclusive, WIN_STD_CALL_CONV,, <:PSRWLOCK>, 4
      @DefProto DllImport, ReleaseSRWLockShared, WIN_STD_CALL_CONV,, <:PSRWLOCK>, 4
      @DefProto DllImport, AcquireSRWLockExclusive, WIN_STD_CALL_CONV,, <:PSRWLOCK>, 4
      @DefProto DllImport, AcquireSRWLockShared, WIN_STD_CALL_CONV,, <:PSRWLOCK>, 4
      @DefProto DllImport, TryAcquireSRWLockExclusive, WIN_STD_CALL_CONV,, <:PSRWLOCK>, 4
      @DefProto DllImport, TryAcquireSRWLockShared, WIN_STD_CALL_CONV,, <:PSRWLOCK>, 4
    endif
    if (_WIN32_WINNT lt 0600h)
      @DefProto DllImport, InitializeCriticalSection, WIN_STD_CALL_CONV,, <:LPCRITICAL_SECTION>, 4
    else
      @DefProto DllImport, InitializeCriticalSection, WIN_STD_CALL_CONV,, <:LPCRITICAL_SECTION>, 4
    endif
    @DefProto DllImport, EnterCriticalSection, WIN_STD_CALL_CONV,, <:LPCRITICAL_SECTION>, 4
    @DefProto DllImport, LeaveCriticalSection, WIN_STD_CALL_CONV,, <:LPCRITICAL_SECTION>, 4
    @DefProto DllImport, InitializeCriticalSectionAndSpinCount, WIN_STD_CALL_CONV,, <:LPCRITICAL_SECTION, :DWORD>, 8
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, InitializeCriticalSectionEx, WIN_STD_CALL_CONV,, <:LPCRITICAL_SECTION, :DWORD, :DWORD>, 12
    endif
    @DefProto DllImport, SetCriticalSectionSpinCount, WIN_STD_CALL_CONV,, <:LPCRITICAL_SECTION, :DWORD>, 8
    if (_WIN32_WINNT ge 0400h)
      @DefProto DllImport, TryEnterCriticalSection, WIN_STD_CALL_CONV,, <:LPCRITICAL_SECTION>, 4
    endif
    @DefProto DllImport, DeleteCriticalSection, WIN_STD_CALL_CONV,, <:LPCRITICAL_SECTION>, 4
    INIT_ONCE typedef RTL_RUN_ONCE
    PINIT_ONCE typedef PRTL_RUN_ONCE
    LPINIT_ONCE typedef PRTL_RUN_ONCE
    INIT_ONCE_STATIC_INIT equ <RTL_RUN_ONCE_INIT>
    INIT_ONCE_CHECK_ONLY equ <RTL_RUN_ONCE_CHECK_ONLY>
    INIT_ONCE_ASYNC equ <RTL_RUN_ONCE_ASYNC>
    INIT_ONCE_INIT_FAILED equ <RTL_RUN_ONCE_INIT_FAILED>
    INIT_ONCE_CTX_RESERVED_BITS equ <RTL_RUN_ONCE_CTX_RESERVED_BITS>
    TYPE_PINIT_ONCE_FN typedef proto WIN_STD_CALL_CONV :PINIT_ONCE, :PVOID, :ptr PVOID
    PINIT_ONCE_FN typedef ptr TYPE_PINIT_ONCE_FN

    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, InitOnceInitialize, WIN_STD_CALL_CONV,, <:PINIT_ONCE>, 4
      @DefProto DllImport, InitOnceExecuteOnce, WIN_STD_CALL_CONV,, <:PINIT_ONCE, :PINIT_ONCE_FN, :PVOID, :ptr LPVOID>, 16
      @DefProto DllImport, InitOnceBeginInitialize, WIN_STD_CALL_CONV,, <:LPINIT_ONCE, :DWORD, :PBOOL, :ptr LPVOID>, 16
      @DefProto DllImport, InitOnceComplete, WIN_STD_CALL_CONV,, <:LPINIT_ONCE, :DWORD, :LPVOID>, 12
    endif
    CONDITION_VARIABLE typedef RTL_CONDITION_VARIABLE
    PCONDITION_VARIABLE typedef ptr RTL_CONDITION_VARIABLE
    CONDITION_VARIABLE_INIT equ <RTL_CONDITION_VARIABLE_INIT>
    CONDITION_VARIABLE_LOCKMODE_SHARED equ <RTL_CONDITION_VARIABLE_LOCKMODE_SHARED>
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, InitializeConditionVariable, WIN_STD_CALL_CONV,, <:PCONDITION_VARIABLE>, 4
      @DefProto DllImport, WakeConditionVariable, WIN_STD_CALL_CONV,, <:PCONDITION_VARIABLE>, 4
      @DefProto DllImport, WakeAllConditionVariable, WIN_STD_CALL_CONV,, <:PCONDITION_VARIABLE>, 4
      @DefProto DllImport, SleepConditionVariableCS, WIN_STD_CALL_CONV,, <:PCONDITION_VARIABLE, :PCRITICAL_SECTION, :DWORD>, 12
      @DefProto DllImport, SleepConditionVariableSRW, WIN_STD_CALL_CONV,, <:PCONDITION_VARIABLE, :PSRWLOCK, :DWORD, :ULONG>, 16
    endif
    @DefProto DllImport, SetEvent, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    @DefProto DllImport, ResetEvent, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    @DefProto DllImport, ReleaseSemaphore, WIN_STD_CALL_CONV,, <:HANDLE, :LONG, :LPLONG>, 12
    @DefProto DllImport, ReleaseMutex, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    @DefProto DllImport, WaitForSingleObject, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD>, 8
    @DefProto DllImport, SleepEx, WIN_STD_CALL_CONV,, <:DWORD, :BOOL>, 8
    @DefProto DllImport, WaitForSingleObjectEx, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :BOOL>, 12
    @DefProto DllImport, WaitForMultipleObjectsEx, WIN_STD_CALL_CONV,, <:DWORD, :ptr HANDLE, :BOOL, :DWORD, :BOOL>, 20
    MUTEX_MODIFY_STATE equ <MUTANT_QUERY_STATE>
    MUTEX_ALL_ACCESS equ <MUTANT_ALL_ACCESS>
    @DefProto DllImport, CreateMutexA, WIN_STD_CALL_CONV,, <:LPSECURITY_ATTRIBUTES, :BOOL, :LPCSTR>, 12
    @DefProto DllImport, CreateMutexW, WIN_STD_CALL_CONV,, <:LPSECURITY_ATTRIBUTES, :BOOL, :LPCWSTR>, 12
    ifdef UNICODE
      CreateMutex equ <CreateMutexW>
    else
      CreateMutex equ <CreateMutexA>
    endif
    @DefProto DllImport, OpenMutexW, WIN_STD_CALL_CONV,, <:DWORD, :BOOL, :LPCWSTR>, 12
    ifdef UNICODE
      OpenMutex equ <OpenMutexW>
    endif
    @DefProto DllImport, CreateEventA, WIN_STD_CALL_CONV,, <:LPSECURITY_ATTRIBUTES, :BOOL, :BOOL, :LPCSTR>, 16
    @DefProto DllImport, CreateEventW, WIN_STD_CALL_CONV,, <:LPSECURITY_ATTRIBUTES, :BOOL, :BOOL, :LPCWSTR>, 16
    ifdef UNICODE
      CreateEvent equ <CreateEventW>
    else
      CreateEvent equ <CreateEventA>
    endif
    @DefProto DllImport, OpenEventA, WIN_STD_CALL_CONV,, <:DWORD, :BOOL, :LPCSTR>, 12
    @DefProto DllImport, OpenEventW, WIN_STD_CALL_CONV,, <:DWORD, :BOOL, :LPCWSTR>, 12
    ifdef UNICODE
      OpenEvent equ <OpenEventW>
    else
      OpenEvent equ <OpenEventA>
    endif
    @DefProto DllImport, OpenSemaphoreW, WIN_STD_CALL_CONV,, <:DWORD, :BOOL, :LPCWSTR>, 12
    ifdef UNICODE
      OpenSemaphore equ <OpenSemaphoreW>
    endif
    if (_WIN32_WINNT ge 0400h) or (_WIN32_WINDOWS gt 0400h)
      TYPE_PTIMERAPCROUTINE typedef proto WIN_STD_CALL_CONV :LPVOID, :DWORD, :DWORD
      PTIMERAPCROUTINE typedef ptr TYPE_PTIMERAPCROUTINE

      @DefProto DllImport, OpenWaitableTimerW, WIN_STD_CALL_CONV,, <:DWORD, :BOOL, :LPCWSTR>, 12
      ifdef UNICODE
        OpenWaitableTimer equ <OpenWaitableTimerW>
      endif
      if (_WIN32_WINNT ge _WIN32_WINNT_WIN7)
        SetWaitableTimerEx proto WIN_STD_CALL_CONV :HANDLE, :ptr LARGE_INTEGER, :LONG, :PTIMERAPCROUTINE, :LPVOID, :PREASON_CONTEXT, :ULONG
      endif
      @DefProto DllImport, SetWaitableTimer, WIN_STD_CALL_CONV,, <:HANDLE, :ptr LARGE_INTEGER, :LONG, :PTIMERAPCROUTINE, :LPVOID, :BOOL>, 24
      @DefProto DllImport, CancelWaitableTimer, WIN_STD_CALL_CONV,, <:HANDLE>, 4
      if (_WIN32_WINNT ge 0600h)
        CREATE_MUTEX_INITIAL_OWNER equ 00000001h
        @DefProto DllImport, CreateMutexExA, WIN_STD_CALL_CONV,, <:LPSECURITY_ATTRIBUTES, :LPCSTR, :DWORD, :DWORD>, 16
        @DefProto DllImport, CreateMutexExW, WIN_STD_CALL_CONV,, <:LPSECURITY_ATTRIBUTES, :LPCWSTR, :DWORD, :DWORD>, 16
        ifdef UNICODE
          CreateMutexEx equ <CreateMutexExW>
        else
          CreateMutexEx equ <CreateMutexExA>
        endif
        CREATE_EVENT_MANUAL_RESET equ 00000001h
        CREATE_EVENT_INITIAL_SET equ 00000002h
        @DefProto DllImport, CreateEventExA, WIN_STD_CALL_CONV,, <:LPSECURITY_ATTRIBUTES, :LPCSTR, :DWORD, :DWORD>, 16
        @DefProto DllImport, CreateEventExW, WIN_STD_CALL_CONV,, <:LPSECURITY_ATTRIBUTES, :LPCWSTR, :DWORD, :DWORD>, 16
        ifdef UNICODE
          CreateEventEx equ <CreateEventExW>
        else
          CreateEventEx equ <CreateEventExA>
        endif
        @DefProto DllImport, CreateSemaphoreExW, WIN_STD_CALL_CONV,, <:LPSECURITY_ATTRIBUTES, :LONG, :LONG, :LPCWSTR, :DWORD, :DWORD>, 24
        ifdef UNICODE
          CreateSemaphoreEx equ <CreateSemaphoreExW>
        endif
        CREATE_WAITABLE_TIMER_MANUAL_RESET equ 00000001h
        if (_WIN32_WINNT ge _NT_TARGET_VERSION_WIN10_RS4)
          CREATE_WAITABLE_TIMER_HIGH_RESOLUTION equ 00000002h
        endif
        @DefProto DllImport, CreateWaitableTimerExW, WIN_STD_CALL_CONV,, <:LPSECURITY_ATTRIBUTES, :LPCWSTR, :DWORD, :DWORD>, 16
        ifdef UNICODE
          CreateWaitableTimerEx equ <CreateWaitableTimerExW>
        endif
      endif
    endif
    SYNCHRONIZATION_BARRIER typedef RTL_BARRIER
    PSYNCHRONIZATION_BARRIER typedef PRTL_BARRIER
    LPSYNCHRONIZATION_BARRIER typedef PRTL_BARRIER
    SYNCHRONIZATION_BARRIER_FLAGS_SPIN_ONLY equ 01h
    SYNCHRONIZATION_BARRIER_FLAGS_BLOCK_ONLY equ 02h
    SYNCHRONIZATION_BARRIER_FLAGS_NO_DELETE equ 04h
    EnterSynchronizationBarrier proto WIN_STD_CALL_CONV :LPSYNCHRONIZATION_BARRIER, :DWORD
    InitializeSynchronizationBarrier proto WIN_STD_CALL_CONV :LPSYNCHRONIZATION_BARRIER, :LONG, :LONG
    DeleteSynchronizationBarrier proto WIN_STD_CALL_CONV :LPSYNCHRONIZATION_BARRIER
    @DefProto DllImport, Sleep, WIN_STD_CALL_CONV,, <:DWORD>, 4
    WaitOnAddress proto WIN_STD_CALL_CONV :ptr VOID, :PVOID, :SIZE_T, :DWORD
    WakeByAddressSingle proto WIN_STD_CALL_CONV :PVOID
    WakeByAddressAll proto WIN_STD_CALL_CONV :PVOID
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    ifndef MIDL_PASS
      @DefProto DllImport, SignalObjectAndWait, WIN_STD_CALL_CONV,, <:HANDLE, :HANDLE, :DWORD, :BOOL>, 16
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, WaitForMultipleObjects, WIN_STD_CALL_CONV,, <:DWORD, :ptr HANDLE, :BOOL, :DWORD>, 16
    @DefProto DllImport, CreateSemaphoreW, WIN_STD_CALL_CONV,, <:LPSECURITY_ATTRIBUTES, :LONG, :LONG, :LPCWSTR>, 16
    ifdef UNICODE
      CreateSemaphore equ <CreateSemaphoreW>
    endif
    @DefProto DllImport, CreateWaitableTimerW, WIN_STD_CALL_CONV,, <:LPSECURITY_ATTRIBUTES, :BOOL, :LPCWSTR>, 12
    ifdef UNICODE
      CreateWaitableTimer equ <CreateWaitableTimerW>
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
