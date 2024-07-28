;Include file created by h2incX, Version C.01.00, 01/10/2023 16:07
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'C:\Program Files (x86)\Windows Kits\10\Include\10.0.22621.0\um\winternl.h', last modified: 08/05/2023 18:07
;Creation parameters: 

ifndef _WINTERNL_
  _WINTERNL_ equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge 0500h)
      include windef.inc
      ifdef __cplusplus
        ;[...]
      endif
      NTSTATUS typedef LONG
      PCSZ typedef ptr SBYTE
      STRING struct
        Length_ USHORT ?
        MaximumLength USHORT ?
        Buffer PCHAR ?
      STRING ends
      _STRING typedef STRING
      PSTRING_ typedef ptr STRING
      ANSI_STRING typedef STRING
      PANSI_STRING typedef PSTRING_
      PCANSI_STRING typedef PSTRING_
      OEM_STRING typedef STRING
      POEM_STRING typedef PSTRING_
      PCOEM_STRING typedef ptr STRING
      UNICODE_STRING struct
        Length_ USHORT ?
        MaximumLength USHORT ?
        Buffer PWSTR ?
      UNICODE_STRING ends
      _UNICODE_STRING typedef UNICODE_STRING
      PUNICODE_STRING typedef ptr UNICODE_STRING
      PCUNICODE_STRING typedef ptr UNICODE_STRING
      KPRIORITY typedef LONG
      CLIENT_ID struct
        UniqueProcess HANDLE ?
        UniqueThread HANDLE ?
      CLIENT_ID ends
      _CLIENT_ID typedef CLIENT_ID
      PEB_LDR_DATA struct
        Reserved1 BYTE 8 dup (?)
        Reserved2 PVOID 3 dup (?)
        InMemoryOrderModuleList LIST_ENTRY <>
      PEB_LDR_DATA ends
      _PEB_LDR_DATA typedef PEB_LDR_DATA
      PPEB_LDR_DATA typedef ptr PEB_LDR_DATA
      
      LDR_DATA_TABLE_ENTRY struct
        Reserved1 PVOID 2 dup (?)
        InMemoryOrderLinks LIST_ENTRY <>
        Reserved2 PVOID 2 dup (?)
        DllBase PVOID ?
        Reserved3 PVOID 2 dup (?)
        FullDllName UNICODE_STRING <>
        Reserved4 BYTE 8 dup (?)
        Reserved5 PVOID 3 dup (?)
        union
          CheckSum ULONG ?
          Reserved6 PVOID ?
        ends
        TimeDateStamp ULONG ?
      LDR_DATA_TABLE_ENTRY ends
      _LDR_DATA_TABLE_ENTRY typedef LDR_DATA_TABLE_ENTRY
      PLDR_DATA_TABLE_ENTRY typedef ptr LDR_DATA_TABLE_ENTRY
      
      RTL_USER_PROCESS_PARAMETERS struct
        Reserved1 BYTE 16 dup (?)
        Reserved2 PVOID 10 dup (?)
        ImagePathName UNICODE_STRING <>
        CommandLine UNICODE_STRING <>
      RTL_USER_PROCESS_PARAMETERS ends
      _RTL_USER_PROCESS_PARAMETERS typedef RTL_USER_PROCESS_PARAMETERS
      PRTL_USER_PROCESS_PARAMETERS typedef ptr RTL_USER_PROCESS_PARAMETERS
      
      TYPE_PPS_POST_PROCESS_INIT_ROUTINE typedef proto WIN_STD_CALL_CONV :POINTER
      PPS_POST_PROCESS_INIT_ROUTINE typedef ptr TYPE_PPS_POST_PROCESS_INIT_ROUTINE
      PEB struct
        Reserved1 BYTE 2 dup (?)
        BeingDebugged BYTE ?
        Reserved2 BYTE 1 dup (?)
        Reserved3 POINTER 2 dup (?)
        Ldr PPEB_LDR_DATA ?
        ProcessParameters PRTL_USER_PROCESS_PARAMETERS ?
        Reserved4 PVOID 3 dup (?)
        AtlThunkSListPtr PVOID ?
        Reserved5 PVOID ?
        Reserved6 ULONG ?
        Reserved7 PVOID ?
        Reserved8 ULONG ?
        AtlThunkSListPtr32 ULONG ?
        Reserved9 PVOID 45 dup (?)
        Reserved10 BYTE 96 dup (?)
        PostProcessInitRoutine PPS_POST_PROCESS_INIT_ROUTINE ?
        Reserved11 BYTE 128 dup (?)
        Reserved12 PVOID 1 dup (?)
        SessionId ULONG ?
      PEB ends
      _PEB typedef PEB
      PPEB typedef ptr PEB
      
      TEB struct
        Reserved1 PVOID 12 dup (?)
        ProcessEnvironmentBlock PPEB ?
        Reserved2 PVOID 399 dup (?)
        Reserved3 BYTE 1952 dup (?)
        TlsSlots PVOID 64 dup (?)
        Reserved4 BYTE 8 dup (?)
        Reserved5 PVOID 26 dup (?)
        ReservedForOle PVOID ?
        Reserved6 PVOID 4 dup (?)
        TlsExpansionSlots PVOID ?
      TEB ends
      _TEB typedef TEB
      PTEB typedef ptr TEB
      
      OBJECT_ATTRIBUTES struct
        Length_ ULONG ?
        RootDirectory HANDLE ?
        ObjectName PUNICODE_STRING ?
        Attributes ULONG ?
        SecurityDescriptor PVOID ?
        SecurityQualityOfService PVOID ?
      OBJECT_ATTRIBUTES ends
      _OBJECT_ATTRIBUTES typedef OBJECT_ATTRIBUTES
      POBJECT_ATTRIBUTES typedef ptr OBJECT_ATTRIBUTES
      IO_STATUS_BLOCK struct
        union
          Status NTSTATUS ?
          Pointer PVOID ?
        ends
        Information ULONG_PTR ?
      IO_STATUS_BLOCK ends
      _IO_STATUS_BLOCK typedef IO_STATUS_BLOCK
      PIO_STATUS_BLOCK typedef ptr IO_STATUS_BLOCK
      
      TYPE_PIO_APC_ROUTINE typedef proto WIN_STD_CALL_CONV :PVOID, :PIO_STATUS_BLOCK, :ULONG
      PIO_APC_ROUTINE typedef ptr TYPE_PIO_APC_ROUTINE
      PROCESS_BASIC_INFORMATION struct
        Reserved1 PVOID ?
        PebBaseAddress PPEB ?
        Reserved2 PVOID 2 dup (?)
        UniqueProcessId ULONG_PTR ?
        Reserved3 PVOID ?
      PROCESS_BASIC_INFORMATION ends
      _PROCESS_BASIC_INFORMATION typedef PROCESS_BASIC_INFORMATION
      PPROCESS_BASIC_INFORMATION typedef ptr PROCESS_BASIC_INFORMATION
      SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION struct
        IdleTime LARGE_INTEGER <>
        KernelTime LARGE_INTEGER <>
        UserTime LARGE_INTEGER <>
        Reserved1 LARGE_INTEGER 2 dup (<>)
        Reserved2 ULONG ?
      SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION ends
      _SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION typedef SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION
      PSYSTEM_PROCESSOR_PERFORMANCE_INFORMATION typedef ptr SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION
      
      SYSTEM_PROCESS_INFORMATION struct
        NextEntryOffset ULONG ?
        NumberOfThreads ULONG ?
        Reserved1 BYTE 48 dup (?)
        ImageName UNICODE_STRING <>
        BasePriority KPRIORITY ?
        UniqueProcessId HANDLE ?
        Reserved2 PVOID ?
        HandleCount ULONG ?
        SessionId ULONG ?
        Reserved3 PVOID ?
        PeakVirtualSize SIZE_T ?
        VirtualSize SIZE_T ?
        Reserved4 ULONG ?
        PeakWorkingSetSize SIZE_T ?
        WorkingSetSize SIZE_T ?
        Reserved5 PVOID ?
        QuotaPagedPoolUsage SIZE_T ?
        Reserved6 PVOID ?
        QuotaNonPagedPoolUsage SIZE_T ?
        PagefileUsage SIZE_T ?
        PeakPagefileUsage SIZE_T ?
        PrivatePageCount SIZE_T ?
        Reserved7 LARGE_INTEGER 6 dup (<>)
      SYSTEM_PROCESS_INFORMATION ends
      _SYSTEM_PROCESS_INFORMATION typedef SYSTEM_PROCESS_INFORMATION
      PSYSTEM_PROCESS_INFORMATION typedef ptr SYSTEM_PROCESS_INFORMATION
      
      SYSTEM_THREAD_INFORMATION struct
        Reserved1 LARGE_INTEGER 3 dup (<>)
        Reserved2 ULONG ?
        StartAddress PVOID ?
        ClientId CLIENT_ID <>
        Priority KPRIORITY ?
        BasePriority LONG ?
        Reserved3 ULONG ?
        ThreadState ULONG ?
        WaitReason ULONG ?
      SYSTEM_THREAD_INFORMATION ends
      _SYSTEM_THREAD_INFORMATION typedef SYSTEM_THREAD_INFORMATION
      PSYSTEM_THREAD_INFORMATION typedef ptr SYSTEM_THREAD_INFORMATION
      
      SYSTEM_REGISTRY_QUOTA_INFORMATION struct
        RegistryQuotaAllowed ULONG ?
        RegistryQuotaUsed ULONG ?
        Reserved1 PVOID ?
      SYSTEM_REGISTRY_QUOTA_INFORMATION ends
      _SYSTEM_REGISTRY_QUOTA_INFORMATION typedef SYSTEM_REGISTRY_QUOTA_INFORMATION
      PSYSTEM_REGISTRY_QUOTA_INFORMATION typedef ptr SYSTEM_REGISTRY_QUOTA_INFORMATION
      
      SYSTEM_BASIC_INFORMATION struct
        Reserved1 BYTE 24 dup (?)
        Reserved2 PVOID 4 dup (?)
        NumberOfProcessors CCHAR ?
      SYSTEM_BASIC_INFORMATION ends
      _SYSTEM_BASIC_INFORMATION typedef SYSTEM_BASIC_INFORMATION
      PSYSTEM_BASIC_INFORMATION typedef ptr SYSTEM_BASIC_INFORMATION
      
      SYSTEM_TIMEOFDAY_INFORMATION struct
        Reserved1 BYTE 48 dup (?)
      SYSTEM_TIMEOFDAY_INFORMATION ends
      _SYSTEM_TIMEOFDAY_INFORMATION typedef SYSTEM_TIMEOFDAY_INFORMATION
      PSYSTEM_TIMEOFDAY_INFORMATION typedef ptr SYSTEM_TIMEOFDAY_INFORMATION
      
      SYSTEM_PERFORMANCE_INFORMATION struct
        Reserved1 BYTE 312 dup (?)
      SYSTEM_PERFORMANCE_INFORMATION ends
      _SYSTEM_PERFORMANCE_INFORMATION typedef SYSTEM_PERFORMANCE_INFORMATION
      PSYSTEM_PERFORMANCE_INFORMATION typedef ptr SYSTEM_PERFORMANCE_INFORMATION
      
      SYSTEM_EXCEPTION_INFORMATION struct
        Reserved1 BYTE 16 dup (?)
      SYSTEM_EXCEPTION_INFORMATION ends
      _SYSTEM_EXCEPTION_INFORMATION typedef SYSTEM_EXCEPTION_INFORMATION
      PSYSTEM_EXCEPTION_INFORMATION typedef ptr SYSTEM_EXCEPTION_INFORMATION
      
      SYSTEM_LOOKASIDE_INFORMATION struct
        Reserved1 BYTE 32 dup (?)
      SYSTEM_LOOKASIDE_INFORMATION ends
      _SYSTEM_LOOKASIDE_INFORMATION typedef SYSTEM_LOOKASIDE_INFORMATION
      PSYSTEM_LOOKASIDE_INFORMATION typedef ptr SYSTEM_LOOKASIDE_INFORMATION
      
      SYSTEM_INTERRUPT_INFORMATION struct
        Reserved1 BYTE 24 dup (?)
      SYSTEM_INTERRUPT_INFORMATION ends
      _SYSTEM_INTERRUPT_INFORMATION typedef SYSTEM_INTERRUPT_INFORMATION
      PSYSTEM_INTERRUPT_INFORMATION typedef ptr SYSTEM_INTERRUPT_INFORMATION
      
      SYSTEM_POLICY_INFORMATION struct
        Reserved1 PVOID 2 dup (?)
        Reserved2 ULONG 3 dup (?)
      SYSTEM_POLICY_INFORMATION ends
      _SYSTEM_POLICY_INFORMATION typedef SYSTEM_POLICY_INFORMATION
      PSYSTEM_POLICY_INFORMATION typedef ptr SYSTEM_POLICY_INFORMATION
      
      FILE_INFORMATION_CLASS typedef SDWORD
      FileDirectoryInformation equ 1
      _FILE_INFORMATION_CLASS typedef FILE_INFORMATION_CLASS
      
      PROCESSINFOCLASS typedef SDWORD
      ProcessBasicInformation equ 0
      ProcessDebugPort equ 7
      ProcessWow64Information equ 26
      ProcessImageFileName equ 27
      ProcessBreakOnTermination equ 29
      _PROCESSINFOCLASS typedef PROCESSINFOCLASS
      
      THREADINFOCLASS typedef SDWORD
      ThreadIsIoPending equ 16
      ThreadNameInformation equ 38
      _THREADINFOCLASS typedef THREADINFOCLASS
      
      THREAD_NAME_INFORMATION struct
        ThreadName UNICODE_STRING <>
      THREAD_NAME_INFORMATION ends
      _THREAD_NAME_INFORMATION typedef THREAD_NAME_INFORMATION
      PTHREAD_NAME_INFORMATION typedef ptr THREAD_NAME_INFORMATION
      
      CODEINTEGRITY_OPTION_ENABLED equ 01h
      CODEINTEGRITY_OPTION_TESTSIGN equ 02h
      CODEINTEGRITY_OPTION_UMCI_ENABLED equ 04h
      CODEINTEGRITY_OPTION_UMCI_AUDITMODE_ENABLED equ 08h
      CODEINTEGRITY_OPTION_UMCI_EXCLUSIONPATHS_ENABLED equ 10h
      CODEINTEGRITY_OPTION_TEST_BUILD equ 20h
      CODEINTEGRITY_OPTION_PREPRODUCTION_BUILD equ 40h
      CODEINTEGRITY_OPTION_DEBUGMODE_ENABLED equ 80h
      CODEINTEGRITY_OPTION_FLIGHT_BUILD equ 100h
      CODEINTEGRITY_OPTION_FLIGHTING_ENABLED equ 200h
      CODEINTEGRITY_OPTION_HVCI_KMCI_ENABLED equ 400h
      CODEINTEGRITY_OPTION_HVCI_KMCI_AUDITMODE_ENABLED equ 800h
      CODEINTEGRITY_OPTION_HVCI_KMCI_STRICTMODE_ENABLED equ 1000h
      CODEINTEGRITY_OPTION_HVCI_IUM_ENABLED equ 2000h
      SYSTEM_CODEINTEGRITY_INFORMATION struct
        Length_ ULONG ?
        CodeIntegrityOptions ULONG ?
      SYSTEM_CODEINTEGRITY_INFORMATION ends
      _SYSTEM_CODEINTEGRITY_INFORMATION typedef SYSTEM_CODEINTEGRITY_INFORMATION
      PSYSTEM_CODEINTEGRITY_INFORMATION typedef ptr SYSTEM_CODEINTEGRITY_INFORMATION
      
      SYSTEM_INFORMATION_CLASS typedef SDWORD
      SystemBasicInformation equ 0
      SystemPerformanceInformation equ 2
      SystemTimeOfDayInformation equ 3
      SystemProcessInformation equ 5
      SystemProcessorPerformanceInformation equ 8
      SystemInterruptInformation equ 23
      SystemExceptionInformation equ 33
      SystemRegistryQuotaInformation equ 37
      SystemLookasideInformation equ 45
      SystemCodeIntegrityInformation equ 103
      SystemPolicyInformation equ 134
      _SYSTEM_INFORMATION_CLASS typedef SYSTEM_INFORMATION_CLASS
      
      OBJECT_INFORMATION_CLASS typedef SDWORD
      ObjectBasicInformation equ 0
      ObjectTypeInformation equ 2
      _OBJECT_INFORMATION_CLASS typedef OBJECT_INFORMATION_CLASS
      
      PUBLIC_OBJECT_BASIC_INFORMATION struct
        Attributes ULONG ?
        GrantedAccess ACCESS_MASK ?
        HandleCount ULONG ?
        PointerCount ULONG ?
        Reserved ULONG 10 dup (?)
      PUBLIC_OBJECT_BASIC_INFORMATION ends
      _PUBLIC_OBJECT_BASIC_INFORMATION typedef PUBLIC_OBJECT_BASIC_INFORMATION
      PPUBLIC_OBJECT_BASIC_INFORMATION typedef ptr PUBLIC_OBJECT_BASIC_INFORMATION
      
      PUBLIC_OBJECT_TYPE_INFORMATION struct
        TypeName UNICODE_STRING <>
        Reserved ULONG 22 dup (?)
      PUBLIC_OBJECT_TYPE_INFORMATION ends
      __PUBLIC_OBJECT_TYPE_INFORMATION typedef PUBLIC_OBJECT_TYPE_INFORMATION
      PPUBLIC_OBJECT_TYPE_INFORMATION typedef ptr PUBLIC_OBJECT_TYPE_INFORMATION
      
      if (_WIN32_WINNT ge 0501h)
        INTERNAL_TS_ACTIVE_CONSOLE_ID equ (* ((volatile ULONG *) 7ffe02d8h))
      endif
      RtlMoveMemory macro Destination, Source, Length_
        exitm <memmove ((Destination), (Source), (Length_))>
      endm
      RtlFillMemory macro Destination, Length_, Fill
        exitm <memset ((Destination), (Fill), (Length_))>
      endm
      RtlZeroMemory macro Destination, Length_
        exitm <memset ((Destination), 0, (Length_))>
      endm
      NtClose proto WIN_STD_CALL_CONV :HANDLE
      NtCreateFile proto WIN_STD_CALL_CONV :PHANDLE, :ACCESS_MASK, :POBJECT_ATTRIBUTES, :PIO_STATUS_BLOCK, :PLARGE_INTEGER, :ULONG, :ULONG, :ULONG, :ULONG, :PVOID, :ULONG
      NtOpenFile proto WIN_STD_CALL_CONV :PHANDLE, :ACCESS_MASK, :POBJECT_ATTRIBUTES, :PIO_STATUS_BLOCK, :ULONG, :ULONG
      NtRenameKey proto WIN_STD_CALL_CONV :HANDLE, :PUNICODE_STRING
      NtNotifyChangeMultipleKeys proto WIN_STD_CALL_CONV :HANDLE, :ULONG, :ptr OBJECT_ATTRIBUTES, :HANDLE, :PIO_APC_ROUTINE, :PVOID, :PIO_STATUS_BLOCK, :ULONG, :BOOLEAN, :PVOID, :ULONG, :BOOLEAN
      KEY_VALUE_ENTRY struct
        ValueName PUNICODE_STRING ?
        DataLength ULONG ?
        DataOffset ULONG ?
        Type_ ULONG ?
      KEY_VALUE_ENTRY ends
      _KEY_VALUE_ENTRY typedef KEY_VALUE_ENTRY
      PKEY_VALUE_ENTRY typedef ptr KEY_VALUE_ENTRY
      
      NtQueryMultipleValueKey proto WIN_STD_CALL_CONV :HANDLE, :PKEY_VALUE_ENTRY, :ULONG, :PVOID, :PULONG, :PULONG
      KEY_SET_INFORMATION_CLASS typedef SDWORD
      KeyWriteTimeInformation equ 0
      KeyWow64FlagsInformation equ 1
      KeyControlFlagsInformation equ 2
      KeySetVirtualizationInformation equ 3
      KeySetDebugInformation equ 4
      KeySetHandleTagsInformation equ 5
      MaxKeySetInfoClass equ 6
      _KEY_SET_INFORMATION_CLASS typedef KEY_SET_INFORMATION_CLASS
      
      NtSetInformationKey proto WIN_STD_CALL_CONV :HANDLE, :KEY_SET_INFORMATION_CLASS, :PVOID, :ULONG
      NtDeviceIoControlFile proto WIN_STD_CALL_CONV :HANDLE, :HANDLE, :PIO_APC_ROUTINE, :PVOID, :PIO_STATUS_BLOCK, :ULONG, :PVOID, :ULONG, :PVOID, :ULONG
      NtWaitForSingleObject proto WIN_STD_CALL_CONV :HANDLE, :BOOLEAN, :PLARGE_INTEGER
      RtlIsNameLegalDOS8Dot3 proto WIN_STD_CALL_CONV :PUNICODE_STRING, :POEM_STRING, :PBOOLEAN
      RtlNtStatusToDosError proto WIN_STD_CALL_CONV :NTSTATUS
      NtQueryInformationProcess proto WIN_STD_CALL_CONV :HANDLE, :PROCESSINFOCLASS, :PVOID, :ULONG, :PULONG
      NtQueryInformationThread proto WIN_STD_CALL_CONV :HANDLE, :THREADINFOCLASS, :PVOID, :ULONG, :PULONG
      NtSetInformationThread proto WIN_STD_CALL_CONV :HANDLE, :THREADINFOCLASS, :PVOID, :ULONG
      @DefProto DllImport, NtQueryObject, WIN_STD_CALL_CONV,, <:HANDLE, :OBJECT_INFORMATION_CLASS, :PVOID, :ULONG, :PULONG>, 20
      NtQuerySystemInformation proto WIN_STD_CALL_CONV :SYSTEM_INFORMATION_CLASS, :PVOID, :ULONG, :PULONG
      NtQuerySystemTime proto WIN_STD_CALL_CONV :PLARGE_INTEGER
      NtQueryTimerResolution proto WIN_STD_CALL_CONV :PULONG, :PULONG, :PULONG
      RtlLocalTimeToSystemTime proto WIN_STD_CALL_CONV :PLARGE_INTEGER, :PLARGE_INTEGER
      RtlTimeToSecondsSince1970 proto WIN_STD_CALL_CONV :PLARGE_INTEGER, :PULONG
      RtlFreeAnsiString proto WIN_STD_CALL_CONV :PANSI_STRING
      RtlFreeUnicodeString proto WIN_STD_CALL_CONV :PUNICODE_STRING
      RtlFreeOemString proto WIN_STD_CALL_CONV :POEM_STRING
      RtlInitString proto WIN_STD_CALL_CONV :PSTRING_, :PCSZ
      RtlInitStringEx proto WIN_STD_CALL_CONV :PSTRING_, :PCSZ
      RtlInitAnsiString proto WIN_STD_CALL_CONV :PANSI_STRING, :PCSZ
      RtlInitAnsiStringEx proto WIN_STD_CALL_CONV :PANSI_STRING, :PCSZ
      RtlInitUnicodeString proto WIN_STD_CALL_CONV :PUNICODE_STRING, :PCWSTR
      RtlAnsiStringToUnicodeString proto WIN_STD_CALL_CONV :PUNICODE_STRING, :PCANSI_STRING, :BOOLEAN
      RtlUnicodeStringToAnsiString proto WIN_STD_CALL_CONV :PANSI_STRING, :PCUNICODE_STRING, :BOOLEAN
      RtlUnicodeStringToOemString proto WIN_STD_CALL_CONV :POEM_STRING, :PCUNICODE_STRING, :BOOLEAN
      RtlUnicodeToMultiByteSize proto WIN_STD_CALL_CONV :PULONG, :PWCH, :ULONG
      RtlCharToInteger proto WIN_STD_CALL_CONV :PCSZ, :ULONG, :PULONG
      RtlConvertSidToUnicodeString proto WIN_STD_CALL_CONV :PUNICODE_STRING, :PSID, :BOOLEAN
      RtlUniform proto WIN_STD_CALL_CONV :PULONG
      LOGONID_CURRENT equ (- 1)
      SERVERNAME_CURRENT equ <(NULL)>
      WINSTATIONINFOCLASS typedef SDWORD
      WinStationInformation equ 8
      _WINSTATIONINFOCLASS typedef WINSTATIONINFOCLASS
      
      WINSTATIONINFORMATIONW struct
        Reserved2 BYTE 70 dup (?)
        LogonId ULONG ?
        Reserved3 BYTE 1140 dup (?)
      WINSTATIONINFORMATIONW ends
      _WINSTATIONINFORMATIONW typedef WINSTATIONINFORMATIONW
      PWINSTATIONINFORMATIONW typedef ptr WINSTATIONINFORMATIONW
      
      TYPE_PWINSTATIONQUERYINFORMATIONW typedef proto WIN_STD_CALL_CONV :HANDLE, :ULONG, :WINSTATIONINFOCLASS, :PVOID, :ULONG, :PULONG
      PWINSTATIONQUERYINFORMATIONW typedef ptr TYPE_PWINSTATIONQUERYINFORMATIONW
      ifndef NT_SUCCESS
        NT_SUCCESS macro Status
          exitm <(((NTSTATUS) (Status)) >= 0)>
        endm
      endif
      ifndef NT_INFORMATION
        NT_INFORMATION macro Status
          exitm <((((Status)) shr 30) == 1)>
        endm
      endif
      ifndef NT_WARNING
        NT_WARNING macro Status
          exitm <((((Status)) shr 30) == 2)>
        endm
      endif
      ifndef NT_ERROR
        NT_ERROR macro Status
          exitm <((((Status)) shr 30) == 3)>
        endm
      endif
      ifndef InitializeObjectAttributes
        InitializeObjectAttributes macro p, n, a, r, s
          exitm <{ (p) - Length = sizeof(OBJECT_ATTRIBUTES) ; (p) - RootDirectory = r ; (p) - Attributes = a ; (p) - ObjectName = n ; (p) - SecurityDescriptor = s ; (p) - SecurityQualityOfService = NULL ; }>
        endm
      endif
      OBJ_INHERIT equ 00000002h
      OBJ_PERMANENT equ 00000010h
      OBJ_EXCLUSIVE equ 00000020h
      OBJ_CASE_INSENSITIVE equ 00000040h
      OBJ_OPENIF equ 00000080h
      OBJ_OPENLINK equ 00000100h
      OBJ_KERNEL_HANDLE equ 00000200h
      OBJ_FORCE_ACCESS_CHECK equ 00000400h
      OBJ_IGNORE_IMPERSONATED_DEVICEMAP equ 00000800h
      OBJ_DONT_REPARSE equ 00001000h
      OBJ_VALID_ATTRIBUTES equ 00001FF2h
      FILE_SUPERSEDE equ 00000000h
      FILE_OPEN equ 00000001h
      FILE_CREATE equ 00000002h
      FILE_OPEN_IF equ 00000003h
      FILE_OVERWRITE equ 00000004h
      FILE_OVERWRITE_IF equ 00000005h
      FILE_MAXIMUM_DISPOSITION equ 00000005h
      FILE_DIRECTORY_FILE equ 00000001h
      FILE_WRITE_THROUGH equ 00000002h
      FILE_SEQUENTIAL_ONLY equ 00000004h
      FILE_NO_INTERMEDIATE_BUFFERING equ 00000008h
      FILE_SYNCHRONOUS_IO_ALERT equ 00000010h
      FILE_SYNCHRONOUS_IO_NONALERT equ 00000020h
      FILE_NON_DIRECTORY_FILE equ 00000040h
      FILE_CREATE_TREE_CONNECTION equ 00000080h
      FILE_COMPLETE_IF_OPLOCKED equ 00000100h
      FILE_NO_EA_KNOWLEDGE equ 00000200h
      FILE_OPEN_REMOTE_INSTANCE equ 00000400h
      FILE_RANDOM_ACCESS equ 00000800h
      FILE_DELETE_ON_CLOSE equ 00001000h
      FILE_OPEN_BY_FILE_ID equ 00002000h
      FILE_OPEN_FOR_BACKUP_INTENT equ 00004000h
      FILE_NO_COMPRESSION equ 00008000h
      if (_WIN32_WINNT ge _WIN32_WINNT_WIN7)
        FILE_OPEN_REQUIRING_OPLOCK equ 00010000h
      endif
      FILE_RESERVE_OPFILTER equ 00100000h
      FILE_OPEN_REPARSE_POINT equ 00200000h
      FILE_OPEN_NO_RECALL equ 00400000h
      FILE_OPEN_FOR_FREE_SPACE_QUERY equ 00800000h
      FILE_VALID_OPTION_FLAGS equ 00ffffffh
      FILE_VALID_PIPE_OPTION_FLAGS equ 00000032h
      FILE_VALID_MAILSLOT_OPTION_FLAGS equ 00000032h
      FILE_VALID_SET_FLAGS equ 00000036h
      FILE_SUPERSEDED equ 00000000h
      FILE_OPENED equ 00000001h
      FILE_CREATED equ 00000002h
      FILE_OVERWRITTEN equ 00000003h
      FILE_EXISTS equ 00000004h
      FILE_DOES_NOT_EXIST equ 00000005h
      ifndef __os_arm64x_get_x64_information
        __os_arm64x_get_x64_information equ <__os_arm64x_rdtsc>
      endif
      ifndef __os_arm64x_set_x64_information
        __os_arm64x_set_x64_information equ <__os_arm64x_cpuidex>
      endif
      ifdef __cplusplus
        ;[...]
      endif
    endif
  endif
endif
 