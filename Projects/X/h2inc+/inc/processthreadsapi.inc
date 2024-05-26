;Include file created by h2inc+ version C.2.0 on (UTC) 26/05/2024 13:31:25
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\processthreadsapi.h
;             Created on (UTC) 06/04/2024 06:15:57
;             Last modified on (UTC) 21/02/2024 18:13:14

ifdef _MSC_VER
endif
ifndef _PROCESSTHREADSAPI_H_
  _PROCESSTHREADSAPI_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  include minwinbase.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    PROCESS_INFORMATION struct
      hProcess HANDLE ?
      hThread HANDLE ?
      dwProcessId DWORD ?
      dwThreadId DWORD ?
    PROCESS_INFORMATION ends
    _PROCESS_INFORMATION typedef PROCESS_INFORMATION
    PPROCESS_INFORMATION typedef ptr PROCESS_INFORMATION
    LPPROCESS_INFORMATION typedef ptr PROCESS_INFORMATION
    STARTUPINFOA struct
      cb DWORD ?
      lpReserved LPSTR ?
      lpDesktop LPSTR ?
      lpTitle LPSTR ?
      dwX DWORD ?
      dwY DWORD ?
      dwXSize DWORD ?
      dwYSize DWORD ?
      dwXCountChars DWORD ?
      dwYCountChars DWORD ?
      dwFillAttribute DWORD ?
      dwFlags DWORD ?
      wShowWindow WORD ?
      cbReserved2 WORD ?
      lpReserved2 LPBYTE ?
      hStdInput HANDLE ?
      hStdOutput HANDLE ?
      hStdError HANDLE ?
    STARTUPINFOA ends
    _STARTUPINFOA typedef STARTUPINFOA
    LPSTARTUPINFOA typedef ptr STARTUPINFOA
    STARTUPINFOW struct
      cb DWORD ?
      lpReserved LPWSTR ?
      lpDesktop LPWSTR ?
      lpTitle LPWSTR ?
      dwX DWORD ?
      dwY DWORD ?
      dwXSize DWORD ?
      dwYSize DWORD ?
      dwXCountChars DWORD ?
      dwYCountChars DWORD ?
      dwFillAttribute DWORD ?
      dwFlags DWORD ?
      wShowWindow WORD ?
      cbReserved2 WORD ?
      lpReserved2 LPBYTE ?
      hStdInput HANDLE ?
      hStdOutput HANDLE ?
      hStdError HANDLE ?
    STARTUPINFOW ends
    _STARTUPINFOW typedef STARTUPINFOW
    LPSTARTUPINFOW typedef ptr STARTUPINFOW
    ifdef UNICODE
      STARTUPINFO typedef STARTUPINFOW
      LPSTARTUPINFO typedef LPSTARTUPINFOW
    else
      STARTUPINFO typedef STARTUPINFOA
      LPSTARTUPINFO typedef LPSTARTUPINFOA
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    if (_WIN32_WINNT ge 0400h) or (_WIN32_WINDOWS gt 0400h)
      @DefProto DllImport, QueueUserAPC, WIN_STD_CALL_CONV,, <:PAPCFUNC, :HANDLE, :ULONG_PTR>, 12
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_MN)
      QUEUE_USER_APC_FLAGS typedef SDWORD
      QUEUE_USER_APC_FLAGS_NONE equ 00000000h
      QUEUE_USER_APC_FLAGS_SPECIAL_USER_APC equ 00000001h
      QUEUE_USER_APC_CALLBACK_DATA_CONTEXT equ 00010000h
      _QUEUE_USER_APC_FLAGS typedef QUEUE_USER_APC_FLAGS

      APC_CALLBACK_DATA struct
        Parameter ULONG_PTR ?
        ContextRecord PCONTEXT ?
        Reserved0 ULONG_PTR ?
        Reserved1 ULONG_PTR ?
      APC_CALLBACK_DATA ends
      _APC_CALLBACK_DATA typedef APC_CALLBACK_DATA
      PAPC_CALLBACK_DATA typedef ptr APC_CALLBACK_DATA
      @DefProto DllImport, QueueUserAPC2, WIN_STD_CALL_CONV,, <:PAPCFUNC, :HANDLE, :ULONG_PTR, :QUEUE_USER_APC_FLAGS>, 16
    endif
    @DefProto DllImport, GetProcessTimes, WIN_STD_CALL_CONV,, <:HANDLE, :LPFILETIME, :LPFILETIME, :LPFILETIME, :LPFILETIME>, 20
    @DefProto DllImport, GetCurrentProcess, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, GetCurrentProcessId, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, ExitProcess, WIN_STD_CALL_CONV,, <:UINT>, 4
    @DefProto DllImport, TerminateProcess, WIN_STD_CALL_CONV,, <:HANDLE, :UINT>, 8
    @DefProto DllImport, GetExitCodeProcess, WIN_STD_CALL_CONV,, <:HANDLE, :LPDWORD>, 8
    @DefProto DllImport, SwitchToThread, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, CreateThread, WIN_STD_CALL_CONV,, <:LPSECURITY_ATTRIBUTES, :SIZE_T, :LPTHREAD_START_ROUTINE, :LPVOID, :DWORD, :LPDWORD>, 24
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, CreateRemoteThread, WIN_STD_CALL_CONV,, <:HANDLE, :LPSECURITY_ATTRIBUTES, :SIZE_T, :LPTHREAD_START_ROUTINE, :LPVOID, :DWORD, :LPDWORD>, 28
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, GetCurrentThread, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, GetCurrentThreadId, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, OpenThread, WIN_STD_CALL_CONV,, <:DWORD, :BOOL, :DWORD>, 12
    @DefProto DllImport, SetThreadPriority, WIN_STD_CALL_CONV,, <:HANDLE, :SDWORD>, 8
    @DefProto DllImport, SetThreadPriorityBoost, WIN_STD_CALL_CONV,, <:HANDLE, :BOOL>, 8
    @DefProto DllImport, GetThreadPriorityBoost, WIN_STD_CALL_CONV,, <:HANDLE, :PBOOL>, 8
    @DefProto DllImport, GetThreadPriority, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    @DefProto DllImport, ExitThread, WIN_STD_CALL_CONV,, <:DWORD>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, TerminateThread, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, GetExitCodeThread, WIN_STD_CALL_CONV,, <:HANDLE, :LPDWORD>, 8
    @DefProto DllImport, SuspendThread, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    @DefProto DllImport, ResumeThread, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    ifndef TLS_OUT_OF_INDEXES
      TLS_OUT_OF_INDEXES equ (0FFFFFFFFh)
    endif
    @DefProto DllImport, TlsAlloc, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, TlsGetValue, WIN_STD_CALL_CONV,, <:DWORD>, 4
    @DefProto DllImport, TlsSetValue, WIN_STD_CALL_CONV,, <:DWORD, :LPVOID>, 8
    @DefProto DllImport, TlsFree, WIN_STD_CALL_CONV,, <:DWORD>, 4
    @DefProto DllImport, CreateProcessA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPSTR, :LPSECURITY_ATTRIBUTES, :LPSECURITY_ATTRIBUTES, :BOOL, :DWORD, :LPVOID, :LPCSTR, :LPSTARTUPINFOA, :LPPROCESS_INFORMATION>, 40
    @DefProto DllImport, CreateProcessW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPWSTR, :LPSECURITY_ATTRIBUTES, :LPSECURITY_ATTRIBUTES, :BOOL, :DWORD, :LPVOID, :LPCWSTR, :LPSTARTUPINFOW, :LPPROCESS_INFORMATION>, 40
    ifdef UNICODE
      CreateProcess equ <CreateProcessW>
    else
      CreateProcess equ <CreateProcessA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, SetProcessShutdownParameters, WIN_STD_CALL_CONV,, <:DWORD, :DWORD>, 8
    @DefProto DllImport, GetProcessVersion, WIN_STD_CALL_CONV,, <:DWORD>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, GetStartupInfoW, WIN_STD_CALL_CONV,, <:LPSTARTUPINFOW>, 4
    ifdef UNICODE
      GetStartupInfo equ <GetStartupInfoW>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, CreateProcessAsUserW, WIN_STD_CALL_CONV,, <:HANDLE, :LPCWSTR, :LPWSTR, :LPSECURITY_ATTRIBUTES, :LPSECURITY_ATTRIBUTES, :BOOL, :DWORD, :LPVOID, :LPCWSTR, :LPSTARTUPINFOW, :LPPROCESS_INFORMATION>, 44
    ifdef UNICODE
      CreateProcessAsUser equ <CreateProcessAsUserW>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    if  not Defined(MIDL_PASS)
      if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
        GetCurrentProcessToken proto WIN_STD_CALL_CONV
        GetCurrentThreadToken proto WIN_STD_CALL_CONV
        GetCurrentThreadEffectiveToken proto WIN_STD_CALL_CONV
      endif
    endif
    @DefProto DllImport, SetThreadToken, WIN_STD_CALL_CONV,, <:PHANDLE, :HANDLE>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, OpenProcessToken, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :PHANDLE>, 12
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, OpenThreadToken, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :BOOL, :PHANDLE>, 16
    @DefProto DllImport, SetPriorityClass, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD>, 8
    @DefProto DllImport, GetPriorityClass, WIN_STD_CALL_CONV,, <:HANDLE>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, SetThreadStackGuarantee, WIN_STD_CALL_CONV,, <:PULONG>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, ProcessIdToSessionId, WIN_STD_CALL_CONV,, <:DWORD, :ptr DWORD>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    PPROC_THREAD_ATTRIBUTE_LIST typedef ptr _PROC_THREAD_ATTRIBUTE_LIST
    LPPROC_THREAD_ATTRIBUTE_LIST typedef ptr _PROC_THREAD_ATTRIBUTE_LIST
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    if (_WIN32_WINNT ge 0501h)
      @DefProto DllImport, GetProcessId, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    endif
    if (_WIN32_WINNT ge 0502h)
      @DefProto DllImport, GetThreadId, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    endif
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, FlushProcessWriteBuffers, WIN_STD_CALL_CONV,, <>, 0
    endif
  endif
  if (_WIN32_WINNT ge 0600h)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, GetProcessIdOfThread, WIN_STD_CALL_CONV,, <:HANDLE>, 4
      @DefProto DllImport, InitializeProcThreadAttributeList, WIN_STD_CALL_CONV,, <:LPPROC_THREAD_ATTRIBUTE_LIST, :DWORD, :DWORD, :PSIZE_T>, 16
      @DefProto DllImport, DeleteProcThreadAttributeList, WIN_STD_CALL_CONV,, <:LPPROC_THREAD_ATTRIBUTE_LIST>, 4
      PROC_THREAD_ATTRIBUTE_REPLACE_VALUE equ 00000001h
      @DefProto DllImport, UpdateProcThreadAttribute, WIN_STD_CALL_CONV,, <:LPPROC_THREAD_ATTRIBUTE_LIST, :DWORD, :DWORD_PTR, :PVOID, :SIZE_T, :PVOID, :PSIZE_T>, 28
      if (NTDDI_VERSION ge NTDDI_WIN10_VB)
        @DefProto DllImport, SetProcessDynamicEHContinuationTargets, WIN_STD_CALL_CONV,, <:HANDLE, :USHORT, :PPROCESS_DYNAMIC_EH_CONTINUATION_TARGET>, 12
      endif
      if (NTDDI_VERSION ge NTDDI_WIN10_FE)
        @DefProto DllImport, SetProcessDynamicEnforcedCetCompatibleRanges, WIN_STD_CALL_CONV,, <:HANDLE, :USHORT, :PPROCESS_DYNAMIC_ENFORCED_ADDRESS_RANGE>, 12
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      PROCESS_AFFINITY_ENABLE_AUTO_UPDATE equ 00000001h
      @DefProto DllImport, SetProcessAffinityUpdateMode, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD>, 8
      @DefProto DllImport, QueryProcessAffinityUpdateMode, WIN_STD_CALL_CONV,, <:HANDLE, :LPDWORD>, 8
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, CreateRemoteThreadEx, WIN_STD_CALL_CONV,, <:HANDLE, :LPSECURITY_ATTRIBUTES, :SIZE_T, :LPTHREAD_START_ROUTINE, :LPVOID, :DWORD, :LPPROC_THREAD_ATTRIBUTE_LIST, :LPDWORD>, 32
  endif
  if  not Defined(MIDL_PASS)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      if (_WIN32_WINNT ge 0602h)
        @DefProto DllImport, GetCurrentThreadStackLimits, WIN_STD_CALL_CONV,, <:PULONG_PTR, :PULONG_PTR>, 8
      endif
      @DefProto DllImport, GetThreadContext, WIN_STD_CALL_CONV,, <:HANDLE, :LPCONTEXT>, 8
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      if (_WIN32_WINNT ge 0602h)
        @DefProto DllImport, GetProcessMitigationPolicy, WIN_STD_CALL_CONV,, <:HANDLE, :PROCESS_MITIGATION_POLICY, :PVOID, :SIZE_T>, 16
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, SetThreadContext, WIN_STD_CALL_CONV,, <:HANDLE, :ptr CONTEXT>, 8
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      if (_WIN32_WINNT ge 0602h)
        @DefProto DllImport, SetProcessMitigationPolicy, WIN_STD_CALL_CONV,, <:PROCESS_MITIGATION_POLICY, :PVOID, :SIZE_T>, 12
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, FlushInstructionCache, WIN_STD_CALL_CONV,, <:HANDLE, :LPCVOID, :SIZE_T>, 12
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, GetThreadTimes, WIN_STD_CALL_CONV,, <:HANDLE, :LPFILETIME, :LPFILETIME, :LPFILETIME, :LPFILETIME>, 20
    @DefProto DllImport, OpenProcess, WIN_STD_CALL_CONV,, <:DWORD, :BOOL, :DWORD>, 12
    @DefProto DllImport, IsProcessorFeaturePresent, WIN_STD_CALL_CONV,, <:DWORD>, 4
  endif
  if (_WIN32_WINNT ge 0501h)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, GetProcessHandleCount, WIN_STD_CALL_CONV,, <:HANDLE, :PDWORD>, 8
    endif
  endif
  if (_WIN32_WINNT ge 0502h)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, GetCurrentProcessorNumber, WIN_STD_CALL_CONV,, <>, 0
    endif
  endif
  if (_WIN32_WINNT ge 0601h)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, SetThreadIdealProcessorEx, WIN_STD_CALL_CONV,, <:HANDLE, :PPROCESSOR_NUMBER, :PPROCESSOR_NUMBER>, 12
      @DefProto DllImport, GetThreadIdealProcessorEx, WIN_STD_CALL_CONV,, <:HANDLE, :PPROCESSOR_NUMBER>, 8
      @DefProto DllImport, GetCurrentProcessorNumberEx, WIN_STD_CALL_CONV,, <:PPROCESSOR_NUMBER>, 4
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    if (_WIN32_WINNT ge _WIN32_WINNT_WINXP)
      @DefProto DllImport, GetProcessPriorityBoost, WIN_STD_CALL_CONV,, <:HANDLE, :PBOOL>, 8
      @DefProto DllImport, SetProcessPriorityBoost, WIN_STD_CALL_CONV,, <:HANDLE, :BOOL>, 8
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge _WIN32_WINNT_WINXP)
      @DefProto DllImport, GetThreadIOPendingFlag, WIN_STD_CALL_CONV,, <:HANDLE, :PBOOL>, 8
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge _WIN32_WINNT_WINXP)
      @DefProto DllImport, GetSystemTimes, WIN_STD_CALL_CONV,, <:PFILETIME, :PFILETIME, :PFILETIME>, 12
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    THREAD_INFORMATION_CLASS typedef SDWORD
    ThreadMemoryPriority equ 0
    ThreadAbsoluteCpuPriority equ 1
    ThreadDynamicCodePolicy equ 2
    ThreadPowerThrottling equ 3
    ThreadInformationClassMax equ 4
    _THREAD_INFORMATION_CLASS typedef THREAD_INFORMATION_CLASS

    if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
      MEMORY_PRIORITY_INFORMATION struct
        MemoryPriority ULONG ?
      MEMORY_PRIORITY_INFORMATION ends
      _MEMORY_PRIORITY_INFORMATION typedef MEMORY_PRIORITY_INFORMATION
      PMEMORY_PRIORITY_INFORMATION typedef ptr MEMORY_PRIORITY_INFORMATION
      @DefProto DllImport, GetThreadInformation, WIN_STD_CALL_CONV,, <:HANDLE, :THREAD_INFORMATION_CLASS, :LPVOID, :DWORD>, 16
      @DefProto DllImport, SetThreadInformation, WIN_STD_CALL_CONV,, <:HANDLE, :THREAD_INFORMATION_CLASS, :LPVOID, :DWORD>, 16
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN10_RS3)
      THREAD_POWER_THROTTLING_CURRENT_VERSION equ 1
      THREAD_POWER_THROTTLING_EXECUTION_SPEED equ 1h
      THREAD_POWER_THROTTLING_VALID_FLAGS equ <(THREAD_POWER_THROTTLING_EXECUTION_SPEED)>
      THREAD_POWER_THROTTLING_STATE struct
        Version ULONG ?
        ControlMask ULONG ?
        StateMask ULONG ?
      THREAD_POWER_THROTTLING_STATE ends
      _THREAD_POWER_THROTTLING_STATE typedef THREAD_POWER_THROTTLING_STATE
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge _WIN32_WINNT_WINBLUE)
      @DefProto DllImport, IsProcessCritical, WIN_STD_CALL_CONV,, <:HANDLE, :PBOOL>, 8
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN10)
      @DefProto DllImport, SetProtectedPolicy, WIN_STD_CALL_CONV,, <:LPCGUID, :ULONG_PTR, :PULONG_PTR>, 12
      @DefProto DllImport, QueryProtectedPolicy, WIN_STD_CALL_CONV,, <:LPCGUID, :PULONG_PTR>, 8
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, SetThreadIdealProcessor, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    PROCESS_INFORMATION_CLASS typedef SDWORD
    ProcessMemoryPriority equ 0
    ProcessMemoryExhaustionInfo equ 1
    ProcessAppMemoryInfo equ 2
    ProcessInPrivateInfo equ 3
    ProcessPowerThrottling equ 4
    ProcessReservedValue1 equ 5
    ProcessTelemetryCoverageInfo equ 6
    ProcessProtectionLevelInfo equ 7
    ProcessLeapSecondInfo equ 8
    ProcessMachineTypeInfo equ 9
    ProcessOverrideSubsequentPrefetchParameter equ 10
    ProcessMaxOverridePrefetchParameter equ 11
    ProcessInformationClassMax equ 12
    _PROCESS_INFORMATION_CLASS typedef PROCESS_INFORMATION_CLASS

    APP_MEMORY_INFORMATION struct
      AvailableCommit ULONG64 ?
      PrivateCommitUsage ULONG64 ?
      PeakPrivateCommitUsage ULONG64 ?
      TotalCommitUsage ULONG64 ?
    APP_MEMORY_INFORMATION ends
    _APP_MEMORY_INFORMATION typedef APP_MEMORY_INFORMATION
    PAPP_MEMORY_INFORMATION typedef ptr APP_MEMORY_INFORMATION
    MACHINE_ATTRIBUTES typedef SDWORD
    UserEnabled equ 00000001h
    KernelEnabled equ 00000002h
    Wow64Container equ 00000004h
    _MACHINE_ATTRIBUTES typedef MACHINE_ATTRIBUTES

    if  not Defined(MIDL_PASS)
      DEFINE_ENUM_FLAG_OPERATORS(MACHINE_ATTRIBUTES)
    endif
    PROCESS_MACHINE_INFORMATION struct
      ProcessMachine USHORT ?
      Res0 USHORT ?
      MachineAttributes MACHINE_ATTRIBUTES ?
    PROCESS_MACHINE_INFORMATION ends
    _PROCESS_MACHINE_INFORMATION typedef PROCESS_MACHINE_INFORMATION
    OVERRIDE_PREFETCH_PARAMETER struct
      Value UINT32 ?
    OVERRIDE_PREFETCH_PARAMETER ends
    PME_CURRENT_VERSION equ 1
    PROCESS_MEMORY_EXHAUSTION_TYPE typedef SDWORD
    PMETypeFailFastOnCommitFailure equ 0
    PMETypeMax equ 1
    _PROCESS_MEMORY_EXHAUSTION_TYPE typedef PROCESS_MEMORY_EXHAUSTION_TYPE
    PPROCESS_MEMORY_EXHAUSTION_TYPE typedef ptr PROCESS_MEMORY_EXHAUSTION_TYPE
    PME_FAILFAST_ON_COMMIT_FAIL_DISABLE equ 0h
    PME_FAILFAST_ON_COMMIT_FAIL_ENABLE equ 1h
    PROCESS_MEMORY_EXHAUSTION_INFO struct
      Version USHORT ?
      Reserved USHORT ?
      Type_ PROCESS_MEMORY_EXHAUSTION_TYPE ?
      Value ULONG_PTR ?
    PROCESS_MEMORY_EXHAUSTION_INFO ends
    _PROCESS_MEMORY_EXHAUSTION_INFO typedef PROCESS_MEMORY_EXHAUSTION_INFO
    PPROCESS_MEMORY_EXHAUSTION_INFO typedef ptr PROCESS_MEMORY_EXHAUSTION_INFO
    PROCESS_POWER_THROTTLING_CURRENT_VERSION equ 1
    PROCESS_POWER_THROTTLING_EXECUTION_SPEED equ 1h
    PROCESS_POWER_THROTTLING_IGNORE_TIMER_RESOLUTION equ 4h
    PROCESS_POWER_THROTTLING_VALID_FLAGS equ <((PROCESS_POWER_THROTTLING_EXECUTION_SPEED or PROCESS_POWER_THROTTLING_IGNORE_TIMER_RESOLUTION))>
    PROCESS_POWER_THROTTLING_STATE struct
      Version ULONG ?
      ControlMask ULONG ?
      StateMask ULONG ?
    PROCESS_POWER_THROTTLING_STATE ends
    _PROCESS_POWER_THROTTLING_STATE typedef PROCESS_POWER_THROTTLING_STATE
    PPROCESS_POWER_THROTTLING_STATE typedef ptr PROCESS_POWER_THROTTLING_STATE
    PROCESS_PROTECTION_LEVEL_INFORMATION struct
      ProtectionLevel DWORD ?
    PROCESS_PROTECTION_LEVEL_INFORMATION ends
    PROCESS_LEAP_SECOND_INFO_FLAG_ENABLE_SIXTY_SECOND equ 1h
    PROCESS_LEAP_SECOND_INFO_VALID_FLAGS equ <(PROCESS_LEAP_SECOND_INFO_FLAG_ENABLE_SIXTY_SECOND)>
    PROCESS_LEAP_SECOND_INFO struct
      Flags ULONG ?
      Reserved ULONG ?
    PROCESS_LEAP_SECOND_INFO ends
    _PROCESS_LEAP_SECOND_INFO typedef PROCESS_LEAP_SECOND_INFO
    PPROCESS_LEAP_SECOND_INFO typedef ptr PROCESS_LEAP_SECOND_INFO
    if (_WIN32_WINNT ge 0602h)
      @DefProto DllImport, SetProcessInformation, WIN_STD_CALL_CONV,, <:HANDLE, :PROCESS_INFORMATION_CLASS, :LPVOID, :DWORD>, 16
      @DefProto DllImport, GetProcessInformation, WIN_STD_CALL_CONV,, <:HANDLE, :PROCESS_INFORMATION_CLASS, :LPVOID, :DWORD>, 16
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN10)
      GetSystemCpuSetInformation proto WIN_STD_CALL_CONV :PSYSTEM_CPU_SET_INFORMATION, :ULONG, :PULONG, :HANDLE, :ULONG
      GetProcessDefaultCpuSets proto WIN_STD_CALL_CONV :HANDLE, :PULONG, :ULONG, :PULONG
      SetProcessDefaultCpuSets proto WIN_STD_CALL_CONV :HANDLE, :ptr ULONG, :ULONG
      GetThreadSelectedCpuSets proto WIN_STD_CALL_CONV :HANDLE, :PULONG, :ULONG, :PULONG
      SetThreadSelectedCpuSets proto WIN_STD_CALL_CONV :HANDLE, :ptr ULONG, :ULONG
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, CreateProcessAsUserA, WIN_STD_CALL_CONV,, <:HANDLE, :LPCSTR, :LPSTR, :LPSECURITY_ATTRIBUTES, :LPSECURITY_ATTRIBUTES, :BOOL, :DWORD, :LPVOID, :LPCSTR, :LPSTARTUPINFOA, :LPPROCESS_INFORMATION>, 44
    ifndef UNICODE
      CreateProcessAsUser equ <CreateProcessAsUserA>
    endif
    @DefProto DllImport, GetProcessShutdownParameters, WIN_STD_CALL_CONV,, <:LPDWORD, :LPDWORD>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN10_FE)
      GetProcessDefaultCpuSetMasks proto WIN_STD_CALL_CONV :HANDLE, :PGROUP_AFFINITY, :USHORT, :PUSHORT
      SetProcessDefaultCpuSetMasks proto WIN_STD_CALL_CONV :HANDLE, :PGROUP_AFFINITY, :USHORT
      GetThreadSelectedCpuSetMasks proto WIN_STD_CALL_CONV :HANDLE, :PGROUP_AFFINITY, :USHORT, :PUSHORT
      SetThreadSelectedCpuSetMasks proto WIN_STD_CALL_CONV :HANDLE, :PGROUP_AFFINITY, :USHORT
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN10)
      GetMachineTypeAttributes proto WIN_STD_CALL_CONV :USHORT, :ptr MACHINE_ATTRIBUTES
    endif
  endif
  @DefProto DllImport, SetThreadDescription, WIN_STD_CALL_CONV,, <:HANDLE, :PCWSTR>, 8
  @DefProto DllImport, GetThreadDescription, WIN_STD_CALL_CONV,, <:HANDLE, :ptr PWSTR>, 8
  ifdef __cplusplus
    ;[...]
  endif
endif
