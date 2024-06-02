;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\minidumpapiset.h
;             Created on (UTC) 06/04/2024 06:15:56
;             Last modified on (UTC) 21/02/2024 18:13:14

if Defined(_MSC_VER)
endif
ifndef _MINIDUMP_H
  _MINIDUMP_H equ <>
  ifdef _CONTRACT_GEN
    include nt.inc
    include ntrtl.inc
    include nturtl.inc
    include windows.inc
  endif
  include apiset.inc
  include apisetcconv.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
    include pshpack4.inc
    if Defined(_MSC_VER)
      if _MSC_VER ge 800
        if _MSC_VER ge 1200
        endif
      endif
    endif
    ifdef __cplusplus
      ;[...]
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    MINIDUMP_SIGNATURE equ <('PMDM')>
    MINIDUMP_VERSION equ (42899)
    RVA typedef DWORD
    RVA64 typedef ULONG64
    MINIDUMP_LOCATION_DESCRIPTOR struct
      DataSize ULONG32 ?
      Rva RVA ?
    MINIDUMP_LOCATION_DESCRIPTOR ends
    _MINIDUMP_LOCATION_DESCRIPTOR typedef MINIDUMP_LOCATION_DESCRIPTOR
    MINIDUMP_LOCATION_DESCRIPTOR64 struct
      DataSize ULONG64 ?
      Rva RVA64 ?
    MINIDUMP_LOCATION_DESCRIPTOR64 ends
    _MINIDUMP_LOCATION_DESCRIPTOR64 typedef MINIDUMP_LOCATION_DESCRIPTOR64
    MINIDUMP_MEMORY_DESCRIPTOR struct
      StartOfMemoryRange ULONG64 ?
      Memory_ MINIDUMP_LOCATION_DESCRIPTOR <>
    MINIDUMP_MEMORY_DESCRIPTOR ends
    _MINIDUMP_MEMORY_DESCRIPTOR typedef MINIDUMP_MEMORY_DESCRIPTOR
    PMINIDUMP_MEMORY_DESCRIPTOR typedef ptr MINIDUMP_MEMORY_DESCRIPTOR
    MINIDUMP_MEMORY_DESCRIPTOR64 struct
      StartOfMemoryRange ULONG64 ?
      DataSize ULONG64 ?
    MINIDUMP_MEMORY_DESCRIPTOR64 ends
    _MINIDUMP_MEMORY_DESCRIPTOR64 typedef MINIDUMP_MEMORY_DESCRIPTOR64
    PMINIDUMP_MEMORY_DESCRIPTOR64 typedef ptr MINIDUMP_MEMORY_DESCRIPTOR64
    MINIDUMP_HEADER struct
      Signature ULONG32 ?
      Version ULONG32 ?
      NumberOfStreams ULONG32 ?
      StreamDirectoryRva RVA ?
      CheckSum ULONG32 ?
      union
        Reserved ULONG32 ?
        TimeDateStamp ULONG32 ?
      ends
      Flags ULONG64 ?
    MINIDUMP_HEADER ends
    _MINIDUMP_HEADER typedef MINIDUMP_HEADER
    PMINIDUMP_HEADER typedef ptr MINIDUMP_HEADER
    MINIDUMP_DIRECTORY struct
      StreamType ULONG32 ?
      Location MINIDUMP_LOCATION_DESCRIPTOR <>
    MINIDUMP_DIRECTORY ends
    _MINIDUMP_DIRECTORY typedef MINIDUMP_DIRECTORY
    PMINIDUMP_DIRECTORY typedef ptr MINIDUMP_DIRECTORY
    MINIDUMP_STRING struct
      Length_ ULONG32 ?
      Buffer WCHAR 0 dup (?)
    MINIDUMP_STRING ends
    _MINIDUMP_STRING typedef MINIDUMP_STRING
    PMINIDUMP_STRING typedef ptr MINIDUMP_STRING
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    MINIDUMP_STREAM_TYPE typedef SDWORD
    UnusedStream equ 0
    ReservedStream0 equ 1
    ReservedStream1 equ 2
    ThreadListStream equ 3
    ModuleListStream equ 4
    MemoryListStream equ 5
    ExceptionStream equ 6
    SystemInfoStream equ 7
    ThreadExListStream equ 8
    Memory64ListStream equ 9
    CommentStreamA equ 10
    CommentStreamW equ 11
    HandleDataStream equ 12
    FunctionTableStream equ 13
    UnloadedModuleListStream equ 14
    MiscInfoStream equ 15
    MemoryInfoListStream equ 16
    ThreadInfoListStream equ 17
    HandleOperationListStream equ 18
    TokenStream equ 19
    JavaScriptDataStream equ 20
    SystemMemoryInfoStream equ 21
    ProcessVmCountersStream equ 22
    IptTraceStream equ 23
    ThreadNamesStream equ 24
    ceStreamNull equ 8000h
    ceStreamSystemInfo equ 8001h
    ceStreamException equ 8002h
    ceStreamModuleList equ 8003h
    ceStreamProcessList equ 8004h
    ceStreamThreadList equ 8005h
    ceStreamThreadContextList equ 8006h
    ceStreamThreadCallStackList equ 8007h
    ceStreamMemoryVirtualList equ 8008h
    ceStreamMemoryPhysicalList equ 8009h
    ceStreamBucketParameters equ 800Ah
    ceStreamProcessModuleMap equ 800Bh
    ceStreamDiagnosisList equ 800Ch
    LastReservedStream equ 0ffffh
    _MINIDUMP_STREAM_TYPE typedef MINIDUMP_STREAM_TYPE

  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    CPU_INFORMATION union
      struct X86CpuInfo
        VendorId ULONG32 3 dup (?)
        VersionInformation ULONG32 ?
        FeatureInformation ULONG32 ?
        AMDExtendedCpuFeatures ULONG32 ?
      ends
      struct OtherCpuInfo
        ProcessorFeatures ULONG64 2 dup (?)
      ends
    CPU_INFORMATION ends
    _CPU_INFORMATION typedef CPU_INFORMATION
    PCPU_INFORMATION typedef ptr CPU_INFORMATION
    MINIDUMP_SYSTEM_INFO struct
      ProcessorArchitecture USHORT ?
      ProcessorLevel USHORT ?
      ProcessorRevision USHORT ?
      union
        Reserved0 USHORT ?
        struct
          NumberOfProcessors UCHAR ?
          ProductType UCHAR ?
        ends
      ends
      MajorVersion ULONG32 ?
      MinorVersion ULONG32 ?
      BuildNumber ULONG32 ?
      PlatformId ULONG32 ?
      CSDVersionRva RVA ?
      union
        Reserved1 ULONG32 ?
        struct
          SuiteMask USHORT ?
          Reserved2 USHORT ?
        ends
      ends
      Cpu_ CPU_INFORMATION <>
    MINIDUMP_SYSTEM_INFO ends
    _MINIDUMP_SYSTEM_INFO typedef MINIDUMP_SYSTEM_INFO
    PMINIDUMP_SYSTEM_INFO typedef ptr MINIDUMP_SYSTEM_INFO
    MINIDUMP_THREAD struct
      ThreadId ULONG32 ?
      SuspendCount ULONG32 ?
      PriorityClass ULONG32 ?
      Priority ULONG32 ?
      Teb ULONG64 ?
      Stack_ MINIDUMP_MEMORY_DESCRIPTOR <>
      ThreadContext MINIDUMP_LOCATION_DESCRIPTOR <>
    MINIDUMP_THREAD ends
    _MINIDUMP_THREAD typedef MINIDUMP_THREAD
    PMINIDUMP_THREAD typedef ptr MINIDUMP_THREAD
    MINIDUMP_THREAD_LIST struct
      NumberOfThreads ULONG32 ?
      Threads MINIDUMP_THREAD 0 dup (<>)
    MINIDUMP_THREAD_LIST ends
    _MINIDUMP_THREAD_LIST typedef MINIDUMP_THREAD_LIST
    PMINIDUMP_THREAD_LIST typedef ptr MINIDUMP_THREAD_LIST
    MINIDUMP_THREAD_EX struct
      ThreadId ULONG32 ?
      SuspendCount ULONG32 ?
      PriorityClass ULONG32 ?
      Priority ULONG32 ?
      Teb ULONG64 ?
      Stack_ MINIDUMP_MEMORY_DESCRIPTOR <>
      ThreadContext MINIDUMP_LOCATION_DESCRIPTOR <>
      BackingStore MINIDUMP_MEMORY_DESCRIPTOR <>
    MINIDUMP_THREAD_EX ends
    _MINIDUMP_THREAD_EX typedef MINIDUMP_THREAD_EX
    PMINIDUMP_THREAD_EX typedef ptr MINIDUMP_THREAD_EX
    MINIDUMP_THREAD_EX_LIST struct
      NumberOfThreads ULONG32 ?
      Threads MINIDUMP_THREAD_EX 0 dup (<>)
    MINIDUMP_THREAD_EX_LIST ends
    _MINIDUMP_THREAD_EX_LIST typedef MINIDUMP_THREAD_EX_LIST
    PMINIDUMP_THREAD_EX_LIST typedef ptr MINIDUMP_THREAD_EX_LIST
    MINIDUMP_EXCEPTION struct
      ExceptionCode ULONG32 ?
      ExceptionFlags ULONG32 ?
      ExceptionRecord ULONG64 ?
      ExceptionAddress ULONG64 ?
      NumberParameters ULONG32 ?
      __unusedAlignment ULONG32 ?
      ExceptionInformation ULONG64 EXCEPTION_MAXIMUM_PARAMETERS dup (?)
    MINIDUMP_EXCEPTION ends
    _MINIDUMP_EXCEPTION typedef MINIDUMP_EXCEPTION
    PMINIDUMP_EXCEPTION typedef ptr MINIDUMP_EXCEPTION
    MINIDUMP_EXCEPTION_STREAM struct
      ThreadId ULONG32 ?
      __alignment ULONG32 ?
      ExceptionRecord MINIDUMP_EXCEPTION <>
      ThreadContext MINIDUMP_LOCATION_DESCRIPTOR <>
    MINIDUMP_EXCEPTION_STREAM ends
    PMINIDUMP_EXCEPTION_STREAM typedef ptr MINIDUMP_EXCEPTION_STREAM
    MINIDUMP_MODULE struct
      BaseOfImage ULONG64 ?
      SizeOfImage ULONG32 ?
      CheckSum ULONG32 ?
      TimeDateStamp ULONG32 ?
      ModuleNameRva RVA ?
      VersionInfo VS_FIXEDFILEINFO <>
      CvRecord MINIDUMP_LOCATION_DESCRIPTOR <>
      MiscRecord MINIDUMP_LOCATION_DESCRIPTOR <>
      Reserved0 ULONG64 ?
      Reserved1 ULONG64 ?
    MINIDUMP_MODULE ends
    _MINIDUMP_MODULE typedef MINIDUMP_MODULE
    PMINIDUMP_MODULE typedef ptr MINIDUMP_MODULE
    MINIDUMP_MODULE_LIST struct
      NumberOfModules ULONG32 ?
      Modules MINIDUMP_MODULE 0 dup (<>)
    MINIDUMP_MODULE_LIST ends
    _MINIDUMP_MODULE_LIST typedef MINIDUMP_MODULE_LIST
    PMINIDUMP_MODULE_LIST typedef ptr MINIDUMP_MODULE_LIST
    MINIDUMP_MEMORY_LIST struct
      NumberOfMemoryRanges ULONG32 ?
      MemoryRanges MINIDUMP_MEMORY_DESCRIPTOR 0 dup (<>)
    MINIDUMP_MEMORY_LIST ends
    _MINIDUMP_MEMORY_LIST typedef MINIDUMP_MEMORY_LIST
    PMINIDUMP_MEMORY_LIST typedef ptr MINIDUMP_MEMORY_LIST
    MINIDUMP_MEMORY64_LIST struct
      NumberOfMemoryRanges ULONG64 ?
      BaseRva RVA64 ?
      MemoryRanges MINIDUMP_MEMORY_DESCRIPTOR64 0 dup (<>)
    MINIDUMP_MEMORY64_LIST ends
    _MINIDUMP_MEMORY64_LIST typedef MINIDUMP_MEMORY64_LIST
    PMINIDUMP_MEMORY64_LIST typedef ptr MINIDUMP_MEMORY64_LIST
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
    MINIDUMP_EXCEPTION_INFORMATION struct
      ThreadId DWORD ?
      ExceptionPointers PEXCEPTION_POINTERS ?
      ClientPointers BOOL ?
    MINIDUMP_EXCEPTION_INFORMATION ends
    _MINIDUMP_EXCEPTION_INFORMATION typedef MINIDUMP_EXCEPTION_INFORMATION
    PMINIDUMP_EXCEPTION_INFORMATION typedef ptr MINIDUMP_EXCEPTION_INFORMATION
    MINIDUMP_EXCEPTION_INFORMATION64 struct
      ThreadId DWORD ?
      ExceptionRecord ULONG64 ?
      ContextRecord ULONG64 ?
      ClientPointers BOOL ?
    MINIDUMP_EXCEPTION_INFORMATION64 ends
    _MINIDUMP_EXCEPTION_INFORMATION64 typedef MINIDUMP_EXCEPTION_INFORMATION64
    PMINIDUMP_EXCEPTION_INFORMATION64 typedef ptr MINIDUMP_EXCEPTION_INFORMATION64
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    MINIDUMP_HANDLE_OBJECT_INFORMATION_TYPE typedef SDWORD
    MiniHandleObjectInformationNone equ 0
    MiniThreadInformation1 equ 1
    MiniMutantInformation1 equ 2
    MiniMutantInformation2 equ 3
    MiniProcessInformation1 equ 4
    MiniProcessInformation2 equ 5
    MiniEventInformation1 equ 6
    MiniSectionInformation1 equ 7
    MiniSemaphoreInformation1 equ 8
    MiniHandleObjectInformationTypeMax equ 9
    _MINIDUMP_HANDLE_OBJECT_INFORMATION_TYPE typedef MINIDUMP_HANDLE_OBJECT_INFORMATION_TYPE

    MINIDUMP_HANDLE_OBJECT_INFORMATION struct
      NextInfoRva RVA ?
      InfoType ULONG32 ?
      SizeOfInfo ULONG32 ?
    MINIDUMP_HANDLE_OBJECT_INFORMATION ends
    _MINIDUMP_HANDLE_OBJECT_INFORMATION typedef MINIDUMP_HANDLE_OBJECT_INFORMATION
    MINIDUMP_HANDLE_DESCRIPTOR struct
      Handle ULONG64 ?
      TypeNameRva RVA ?
      ObjectNameRva RVA ?
      Attributes ULONG32 ?
      GrantedAccess ULONG32 ?
      HandleCount ULONG32 ?
      PointerCount ULONG32 ?
    MINIDUMP_HANDLE_DESCRIPTOR ends
    _MINIDUMP_HANDLE_DESCRIPTOR typedef MINIDUMP_HANDLE_DESCRIPTOR
    PMINIDUMP_HANDLE_DESCRIPTOR typedef ptr MINIDUMP_HANDLE_DESCRIPTOR
    MINIDUMP_HANDLE_DESCRIPTOR_2 struct
      Handle ULONG64 ?
      TypeNameRva RVA ?
      ObjectNameRva RVA ?
      Attributes ULONG32 ?
      GrantedAccess ULONG32 ?
      HandleCount ULONG32 ?
      PointerCount ULONG32 ?
      ObjectInfoRva RVA ?
      Reserved0 ULONG32 ?
    MINIDUMP_HANDLE_DESCRIPTOR_2 ends
    _MINIDUMP_HANDLE_DESCRIPTOR_2 typedef MINIDUMP_HANDLE_DESCRIPTOR_2
    PMINIDUMP_HANDLE_DESCRIPTOR_2 typedef ptr MINIDUMP_HANDLE_DESCRIPTOR_2
    MINIDUMP_HANDLE_DESCRIPTOR_N typedef MINIDUMP_HANDLE_DESCRIPTOR_2
    PMINIDUMP_HANDLE_DESCRIPTOR_N typedef ptr MINIDUMP_HANDLE_DESCRIPTOR_N
    MINIDUMP_HANDLE_DATA_STREAM struct
      SizeOfHeader ULONG32 ?
      SizeOfDescriptor ULONG32 ?
      NumberOfDescriptors ULONG32 ?
      Reserved ULONG32 ?
    MINIDUMP_HANDLE_DATA_STREAM ends
    _MINIDUMP_HANDLE_DATA_STREAM typedef MINIDUMP_HANDLE_DATA_STREAM
    PMINIDUMP_HANDLE_DATA_STREAM typedef ptr MINIDUMP_HANDLE_DATA_STREAM
    MINIDUMP_HANDLE_OPERATION_LIST struct
      SizeOfHeader ULONG32 ?
      SizeOfEntry ULONG32 ?
      NumberOfEntries ULONG32 ?
      Reserved ULONG32 ?
    MINIDUMP_HANDLE_OPERATION_LIST ends
    _MINIDUMP_HANDLE_OPERATION_LIST typedef MINIDUMP_HANDLE_OPERATION_LIST
    PMINIDUMP_HANDLE_OPERATION_LIST typedef ptr MINIDUMP_HANDLE_OPERATION_LIST
    MINIDUMP_FUNCTION_TABLE_DESCRIPTOR struct
      MinimumAddress ULONG64 ?
      MaximumAddress ULONG64 ?
      BaseAddress ULONG64 ?
      EntryCount ULONG32 ?
      SizeOfAlignPad ULONG32 ?
    MINIDUMP_FUNCTION_TABLE_DESCRIPTOR ends
    _MINIDUMP_FUNCTION_TABLE_DESCRIPTOR typedef MINIDUMP_FUNCTION_TABLE_DESCRIPTOR
    PMINIDUMP_FUNCTION_TABLE_DESCRIPTOR typedef ptr MINIDUMP_FUNCTION_TABLE_DESCRIPTOR
    MINIDUMP_FUNCTION_TABLE_STREAM struct
      SizeOfHeader ULONG32 ?
      SizeOfDescriptor ULONG32 ?
      SizeOfNativeDescriptor ULONG32 ?
      SizeOfFunctionEntry ULONG32 ?
      NumberOfDescriptors ULONG32 ?
      SizeOfAlignPad ULONG32 ?
    MINIDUMP_FUNCTION_TABLE_STREAM ends
    _MINIDUMP_FUNCTION_TABLE_STREAM typedef MINIDUMP_FUNCTION_TABLE_STREAM
    PMINIDUMP_FUNCTION_TABLE_STREAM typedef ptr MINIDUMP_FUNCTION_TABLE_STREAM
    MINIDUMP_UNLOADED_MODULE struct
      BaseOfImage ULONG64 ?
      SizeOfImage ULONG32 ?
      CheckSum ULONG32 ?
      TimeDateStamp ULONG32 ?
      ModuleNameRva RVA ?
    MINIDUMP_UNLOADED_MODULE ends
    _MINIDUMP_UNLOADED_MODULE typedef MINIDUMP_UNLOADED_MODULE
    PMINIDUMP_UNLOADED_MODULE typedef ptr MINIDUMP_UNLOADED_MODULE
    MINIDUMP_UNLOADED_MODULE_LIST struct
      SizeOfHeader ULONG32 ?
      SizeOfEntry ULONG32 ?
      NumberOfEntries ULONG32 ?
    MINIDUMP_UNLOADED_MODULE_LIST ends
    _MINIDUMP_UNLOADED_MODULE_LIST typedef MINIDUMP_UNLOADED_MODULE_LIST
    PMINIDUMP_UNLOADED_MODULE_LIST typedef ptr MINIDUMP_UNLOADED_MODULE_LIST
    XSTATE_CONFIG_FEATURE_MSC_INFO struct
      SizeOfInfo ULONG32 ?
      ContextSize ULONG32 ?
      EnabledFeatures ULONG64 ?
      Features XSTATE_FEATURE MAXIMUM_XSTATE_FEATURES dup (<>)
    XSTATE_CONFIG_FEATURE_MSC_INFO ends
    _XSTATE_CONFIG_FEATURE_MSC_INFO typedef XSTATE_CONFIG_FEATURE_MSC_INFO
    PXSTATE_CONFIG_FEATURE_MSC_INFO typedef ptr XSTATE_CONFIG_FEATURE_MSC_INFO
    MINIDUMP_MISC1_PROCESS_ID equ 00000001h
    MINIDUMP_MISC1_PROCESS_TIMES equ 00000002h
    MINIDUMP_MISC1_PROCESSOR_POWER_INFO equ 00000004h
    MINIDUMP_MISC3_PROCESS_INTEGRITY equ 00000010h
    MINIDUMP_MISC3_PROCESS_EXECUTE_FLAGS equ 00000020h
    MINIDUMP_MISC3_TIMEZONE equ 00000040h
    MINIDUMP_MISC3_PROTECTED_PROCESS equ 00000080h
    MINIDUMP_MISC4_BUILDSTRING equ 00000100h
    MINIDUMP_MISC5_PROCESS_COOKIE equ 00000200h
    MINIDUMP_MISC_INFO struct
      SizeOfInfo ULONG32 ?
      Flags1 ULONG32 ?
      ProcessId ULONG32 ?
      ProcessCreateTime ULONG32 ?
      ProcessUserTime ULONG32 ?
      ProcessKernelTime ULONG32 ?
    MINIDUMP_MISC_INFO ends
    _MINIDUMP_MISC_INFO typedef MINIDUMP_MISC_INFO
    PMINIDUMP_MISC_INFO typedef ptr MINIDUMP_MISC_INFO
    MINIDUMP_MISC_INFO_2 struct
      SizeOfInfo ULONG32 ?
      Flags1 ULONG32 ?
      ProcessId ULONG32 ?
      ProcessCreateTime ULONG32 ?
      ProcessUserTime ULONG32 ?
      ProcessKernelTime ULONG32 ?
      ProcessorMaxMhz ULONG32 ?
      ProcessorCurrentMhz ULONG32 ?
      ProcessorMhzLimit ULONG32 ?
      ProcessorMaxIdleState ULONG32 ?
      ProcessorCurrentIdleState ULONG32 ?
    MINIDUMP_MISC_INFO_2 ends
    _MINIDUMP_MISC_INFO_2 typedef MINIDUMP_MISC_INFO_2
    PMINIDUMP_MISC_INFO_2 typedef ptr MINIDUMP_MISC_INFO_2
    MINIDUMP_MISC_INFO_3 struct
      SizeOfInfo ULONG32 ?
      Flags1 ULONG32 ?
      ProcessId ULONG32 ?
      ProcessCreateTime ULONG32 ?
      ProcessUserTime ULONG32 ?
      ProcessKernelTime ULONG32 ?
      ProcessorMaxMhz ULONG32 ?
      ProcessorCurrentMhz ULONG32 ?
      ProcessorMhzLimit ULONG32 ?
      ProcessorMaxIdleState ULONG32 ?
      ProcessorCurrentIdleState ULONG32 ?
      ProcessIntegrityLevel ULONG32 ?
      ProcessExecuteFlags ULONG32 ?
      ProtectedProcess ULONG32 ?
      TimeZoneId ULONG32 ?
      TimeZone TIME_ZONE_INFORMATION <>
    MINIDUMP_MISC_INFO_3 ends
    _MINIDUMP_MISC_INFO_3 typedef MINIDUMP_MISC_INFO_3
    PMINIDUMP_MISC_INFO_3 typedef ptr MINIDUMP_MISC_INFO_3
    MINIDUMP_MISC_INFO_4 struct
      SizeOfInfo ULONG32 ?
      Flags1 ULONG32 ?
      ProcessId ULONG32 ?
      ProcessCreateTime ULONG32 ?
      ProcessUserTime ULONG32 ?
      ProcessKernelTime ULONG32 ?
      ProcessorMaxMhz ULONG32 ?
      ProcessorCurrentMhz ULONG32 ?
      ProcessorMhzLimit ULONG32 ?
      ProcessorMaxIdleState ULONG32 ?
      ProcessorCurrentIdleState ULONG32 ?
      ProcessIntegrityLevel ULONG32 ?
      ProcessExecuteFlags ULONG32 ?
      ProtectedProcess ULONG32 ?
      TimeZoneId ULONG32 ?
      TimeZone TIME_ZONE_INFORMATION <>
      BuildString WCHAR MAX_PATH dup (?)
      DbgBldStr WCHAR 40 dup (?)
    MINIDUMP_MISC_INFO_4 ends
    _MINIDUMP_MISC_INFO_4 typedef MINIDUMP_MISC_INFO_4
    PMINIDUMP_MISC_INFO_4 typedef ptr MINIDUMP_MISC_INFO_4
    MINIDUMP_MISC_INFO_5 struct
      SizeOfInfo ULONG32 ?
      Flags1 ULONG32 ?
      ProcessId ULONG32 ?
      ProcessCreateTime ULONG32 ?
      ProcessUserTime ULONG32 ?
      ProcessKernelTime ULONG32 ?
      ProcessorMaxMhz ULONG32 ?
      ProcessorCurrentMhz ULONG32 ?
      ProcessorMhzLimit ULONG32 ?
      ProcessorMaxIdleState ULONG32 ?
      ProcessorCurrentIdleState ULONG32 ?
      ProcessIntegrityLevel ULONG32 ?
      ProcessExecuteFlags ULONG32 ?
      ProtectedProcess ULONG32 ?
      TimeZoneId ULONG32 ?
      TimeZone TIME_ZONE_INFORMATION <>
      BuildString WCHAR MAX_PATH dup (?)
      DbgBldStr WCHAR 40 dup (?)
      XStateData XSTATE_CONFIG_FEATURE_MSC_INFO <>
      ProcessCookie ULONG32 ?
    MINIDUMP_MISC_INFO_5 ends
    _MINIDUMP_MISC_INFO_5 typedef MINIDUMP_MISC_INFO_5
    PMINIDUMP_MISC_INFO_5 typedef ptr MINIDUMP_MISC_INFO_5
    MINIDUMP_MISC_INFO_N typedef MINIDUMP_MISC_INFO_5
    PMINIDUMP_MISC_INFO_N typedef ptr MINIDUMP_MISC_INFO_N
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
    MINIDUMP_MEMORY_INFO struct
      BaseAddress ULONG64 ?
      AllocationBase ULONG64 ?
      AllocationProtect ULONG32 ?
      __alignment1 ULONG32 ?
      RegionSize ULONG64 ?
      State ULONG32 ?
      Protect ULONG32 ?
      Type_ ULONG32 ?
      __alignment2 ULONG32 ?
    MINIDUMP_MEMORY_INFO ends
    _MINIDUMP_MEMORY_INFO typedef MINIDUMP_MEMORY_INFO
    PMINIDUMP_MEMORY_INFO typedef ptr MINIDUMP_MEMORY_INFO
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    MINIDUMP_MEMORY_INFO_LIST struct
      SizeOfHeader ULONG ?
      SizeOfEntry ULONG ?
      NumberOfEntries ULONG64 ?
    MINIDUMP_MEMORY_INFO_LIST ends
    _MINIDUMP_MEMORY_INFO_LIST typedef MINIDUMP_MEMORY_INFO_LIST
    PMINIDUMP_MEMORY_INFO_LIST typedef ptr MINIDUMP_MEMORY_INFO_LIST
    MINIDUMP_THREAD_NAME struct
      ThreadId ULONG ?
      RvaOfThreadName RVA64 ?
    MINIDUMP_THREAD_NAME ends
    _MINIDUMP_THREAD_NAME typedef MINIDUMP_THREAD_NAME
    PMINIDUMP_THREAD_NAME typedef ptr MINIDUMP_THREAD_NAME
    MINIDUMP_THREAD_NAME_LIST struct
      NumberOfThreadNames ULONG ?
      ThreadNames MINIDUMP_THREAD_NAME 0 dup (<>)
    MINIDUMP_THREAD_NAME_LIST ends
    _MINIDUMP_THREAD_NAME_LIST typedef MINIDUMP_THREAD_NAME_LIST
    PMINIDUMP_THREAD_NAME_LIST typedef ptr MINIDUMP_THREAD_NAME_LIST
    MINIDUMP_THREAD_INFO_ERROR_THREAD equ 00000001h
    MINIDUMP_THREAD_INFO_WRITING_THREAD equ 00000002h
    MINIDUMP_THREAD_INFO_EXITED_THREAD equ 00000004h
    MINIDUMP_THREAD_INFO_INVALID_INFO equ 00000008h
    MINIDUMP_THREAD_INFO_INVALID_CONTEXT equ 00000010h
    MINIDUMP_THREAD_INFO_INVALID_TEB equ 00000020h
    MINIDUMP_THREAD_INFO struct
      ThreadId ULONG32 ?
      DumpFlags ULONG32 ?
      DumpError ULONG32 ?
      ExitStatus ULONG32 ?
      CreateTime ULONG64 ?
      ExitTime ULONG64 ?
      KernelTime ULONG64 ?
      UserTime ULONG64 ?
      StartAddress ULONG64 ?
      Affinity ULONG64 ?
    MINIDUMP_THREAD_INFO ends
    _MINIDUMP_THREAD_INFO typedef MINIDUMP_THREAD_INFO
    PMINIDUMP_THREAD_INFO typedef ptr MINIDUMP_THREAD_INFO
    MINIDUMP_THREAD_INFO_LIST struct
      SizeOfHeader ULONG ?
      SizeOfEntry ULONG ?
      NumberOfEntries ULONG ?
    MINIDUMP_THREAD_INFO_LIST ends
    _MINIDUMP_THREAD_INFO_LIST typedef MINIDUMP_THREAD_INFO_LIST
    PMINIDUMP_THREAD_INFO_LIST typedef ptr MINIDUMP_THREAD_INFO_LIST
    MINIDUMP_TOKEN_INFO_HEADER struct
      TokenSize ULONG ?
      TokenId ULONG ?
      TokenHandle ULONG64 ?
    MINIDUMP_TOKEN_INFO_HEADER ends
    _MINIDUMP_TOKEN_INFO_HEADER typedef MINIDUMP_TOKEN_INFO_HEADER
    PMINIDUMP_TOKEN_INFO_HEADER typedef ptr MINIDUMP_TOKEN_INFO_HEADER
    MINIDUMP_TOKEN_INFO_LIST struct
      TokenListSize ULONG ?
      TokenListEntries ULONG ?
      ListHeaderSize ULONG ?
      ElementHeaderSize ULONG ?
    MINIDUMP_TOKEN_INFO_LIST ends
    _MINIDUMP_TOKEN_INFO_LIST typedef MINIDUMP_TOKEN_INFO_LIST
    PMINIDUMP_TOKEN_INFO_LIST typedef ptr MINIDUMP_TOKEN_INFO_LIST
    MINIDUMP_SYSTEM_BASIC_INFORMATION struct
      TimerResolution ULONG ?
      PageSize ULONG ?
      NumberOfPhysicalPages ULONG ?
      LowestPhysicalPageNumber ULONG ?
      HighestPhysicalPageNumber ULONG ?
      AllocationGranularity ULONG ?
      MinimumUserModeAddress ULONG64 ?
      MaximumUserModeAddress ULONG64 ?
      ActiveProcessorsAffinityMask ULONG64 ?
      NumberOfProcessors ULONG ?
    MINIDUMP_SYSTEM_BASIC_INFORMATION ends
    _MINIDUMP_SYSTEM_BASIC_INFORMATION typedef MINIDUMP_SYSTEM_BASIC_INFORMATION
    PMINIDUMP_SYSTEM_BASIC_INFORMATION typedef ptr MINIDUMP_SYSTEM_BASIC_INFORMATION
    MINIDUMP_SYSTEM_FILECACHE_INFORMATION struct
      CurrentSize ULONG64 ?
      PeakSize ULONG64 ?
      PageFaultCount ULONG ?
      MinimumWorkingSet ULONG64 ?
      MaximumWorkingSet ULONG64 ?
      CurrentSizeIncludingTransitionInPages ULONG64 ?
      PeakSizeIncludingTransitionInPages ULONG64 ?
      TransitionRePurposeCount ULONG ?
      Flags ULONG ?
    MINIDUMP_SYSTEM_FILECACHE_INFORMATION ends
    _MINIDUMP_SYSTEM_FILECACHE_INFORMATION typedef MINIDUMP_SYSTEM_FILECACHE_INFORMATION
    PMINIDUMP_SYSTEM_FILECACHE_INFORMATION typedef ptr MINIDUMP_SYSTEM_FILECACHE_INFORMATION
    MINIDUMP_SYSTEM_BASIC_PERFORMANCE_INFORMATION struct
      AvailablePages ULONG64 ?
      CommittedPages ULONG64 ?
      CommitLimit ULONG64 ?
      PeakCommitment ULONG64 ?
    MINIDUMP_SYSTEM_BASIC_PERFORMANCE_INFORMATION ends
    _MINIDUMP_SYSTEM_BASIC_PERFORMANCE_INFORMATION typedef MINIDUMP_SYSTEM_BASIC_PERFORMANCE_INFORMATION
    PMINIDUMP_SYSTEM_BASIC_PERFORMANCE_INFORMATION typedef ptr MINIDUMP_SYSTEM_BASIC_PERFORMANCE_INFORMATION
    MINIDUMP_SYSTEM_PERFORMANCE_INFORMATION struct
      IdleProcessTime ULONG64 ?
      IoReadTransferCount ULONG64 ?
      IoWriteTransferCount ULONG64 ?
      IoOtherTransferCount ULONG64 ?
      IoReadOperationCount ULONG ?
      IoWriteOperationCount ULONG ?
      IoOtherOperationCount ULONG ?
      AvailablePages ULONG ?
      CommittedPages ULONG ?
      CommitLimit ULONG ?
      PeakCommitment ULONG ?
      PageFaultCount ULONG ?
      CopyOnWriteCount ULONG ?
      TransitionCount ULONG ?
      CacheTransitionCount ULONG ?
      DemandZeroCount ULONG ?
      PageReadCount ULONG ?
      PageReadIoCount ULONG ?
      CacheReadCount ULONG ?
      CacheIoCount ULONG ?
      DirtyPagesWriteCount ULONG ?
      DirtyWriteIoCount ULONG ?
      MappedPagesWriteCount ULONG ?
      MappedWriteIoCount ULONG ?
      PagedPoolPages ULONG ?
      NonPagedPoolPages ULONG ?
      PagedPoolAllocs ULONG ?
      PagedPoolFrees ULONG ?
      NonPagedPoolAllocs ULONG ?
      NonPagedPoolFrees ULONG ?
      FreeSystemPtes ULONG ?
      ResidentSystemCodePage ULONG ?
      TotalSystemDriverPages ULONG ?
      TotalSystemCodePages ULONG ?
      NonPagedPoolLookasideHits ULONG ?
      PagedPoolLookasideHits ULONG ?
      AvailablePagedPoolPages ULONG ?
      ResidentSystemCachePage ULONG ?
      ResidentPagedPoolPage ULONG ?
      ResidentSystemDriverPage ULONG ?
      CcFastReadNoWait ULONG ?
      CcFastReadWait ULONG ?
      CcFastReadResourceMiss ULONG ?
      CcFastReadNotPossible ULONG ?
      CcFastMdlReadNoWait ULONG ?
      CcFastMdlReadWait ULONG ?
      CcFastMdlReadResourceMiss ULONG ?
      CcFastMdlReadNotPossible ULONG ?
      CcMapDataNoWait ULONG ?
      CcMapDataWait ULONG ?
      CcMapDataNoWaitMiss ULONG ?
      CcMapDataWaitMiss ULONG ?
      CcPinMappedDataCount ULONG ?
      CcPinReadNoWait ULONG ?
      CcPinReadWait ULONG ?
      CcPinReadNoWaitMiss ULONG ?
      CcPinReadWaitMiss ULONG ?
      CcCopyReadNoWait ULONG ?
      CcCopyReadWait ULONG ?
      CcCopyReadNoWaitMiss ULONG ?
      CcCopyReadWaitMiss ULONG ?
      CcMdlReadNoWait ULONG ?
      CcMdlReadWait ULONG ?
      CcMdlReadNoWaitMiss ULONG ?
      CcMdlReadWaitMiss ULONG ?
      CcReadAheadIos ULONG ?
      CcLazyWriteIos ULONG ?
      CcLazyWritePages ULONG ?
      CcDataFlushes ULONG ?
      CcDataPages ULONG ?
      ContextSwitches ULONG ?
      FirstLevelTbFills ULONG ?
      SecondLevelTbFills ULONG ?
      SystemCalls ULONG ?
      CcTotalDirtyPages ULONG64 ?
      CcDirtyPageThreshold ULONG64 ?
      ResidentAvailablePages LONG64 ?
      SharedCommittedPages ULONG64 ?
    MINIDUMP_SYSTEM_PERFORMANCE_INFORMATION ends
    _MINIDUMP_SYSTEM_PERFORMANCE_INFORMATION typedef MINIDUMP_SYSTEM_PERFORMANCE_INFORMATION
    PMINIDUMP_SYSTEM_PERFORMANCE_INFORMATION typedef ptr MINIDUMP_SYSTEM_PERFORMANCE_INFORMATION
    MINIDUMP_SYSMEMINFO1_FILECACHE_TRANSITIONREPURPOSECOUNT_FLAGS equ 0001h
    MINIDUMP_SYSMEMINFO1_BASICPERF equ 0002h
    MINIDUMP_SYSMEMINFO1_PERF_CCTOTALDIRTYPAGES_CCDIRTYPAGETHRESHOLD equ 0004h
    MINIDUMP_SYSMEMINFO1_PERF_RESIDENTAVAILABLEPAGES_SHAREDCOMMITPAGES equ 0008h
    MINIDUMP_SYSTEM_MEMORY_INFO_1 struct
      Revision USHORT ?
      Flags USHORT ?
      BasicInfo MINIDUMP_SYSTEM_BASIC_INFORMATION <>
      FileCacheInfo MINIDUMP_SYSTEM_FILECACHE_INFORMATION <>
      BasicPerfInfo MINIDUMP_SYSTEM_BASIC_PERFORMANCE_INFORMATION <>
      PerfInfo MINIDUMP_SYSTEM_PERFORMANCE_INFORMATION <>
    MINIDUMP_SYSTEM_MEMORY_INFO_1 ends
    _MINIDUMP_SYSTEM_MEMORY_INFO_1 typedef MINIDUMP_SYSTEM_MEMORY_INFO_1
    PMINIDUMP_SYSTEM_MEMORY_INFO_1 typedef ptr MINIDUMP_SYSTEM_MEMORY_INFO_1
    MINIDUMP_SYSTEM_MEMORY_INFO_N typedef MINIDUMP_SYSTEM_MEMORY_INFO_1
    PMINIDUMP_SYSTEM_MEMORY_INFO_N typedef ptr MINIDUMP_SYSTEM_MEMORY_INFO_N
    MINIDUMP_PROCESS_VM_COUNTERS_1 struct
      Revision USHORT ?
      PageFaultCount ULONG ?
      PeakWorkingSetSize ULONG64 ?
      WorkingSetSize ULONG64 ?
      QuotaPeakPagedPoolUsage ULONG64 ?
      QuotaPagedPoolUsage ULONG64 ?
      QuotaPeakNonPagedPoolUsage ULONG64 ?
      QuotaNonPagedPoolUsage ULONG64 ?
      PagefileUsage ULONG64 ?
      PeakPagefileUsage ULONG64 ?
      PrivateUsage ULONG64 ?
    MINIDUMP_PROCESS_VM_COUNTERS_1 ends
    _MINIDUMP_PROCESS_VM_COUNTERS_1 typedef MINIDUMP_PROCESS_VM_COUNTERS_1
    PMINIDUMP_PROCESS_VM_COUNTERS_1 typedef ptr MINIDUMP_PROCESS_VM_COUNTERS_1
    MINIDUMP_PROCESS_VM_COUNTERS equ 0001h
    MINIDUMP_PROCESS_VM_COUNTERS_VIRTUALSIZE equ 0002h
    MINIDUMP_PROCESS_VM_COUNTERS_EX equ 0004h
    MINIDUMP_PROCESS_VM_COUNTERS_EX2 equ 0008h
    MINIDUMP_PROCESS_VM_COUNTERS_JOB equ 0010h
    MINIDUMP_PROCESS_VM_COUNTERS_2 struct
      Revision USHORT ?
      Flags USHORT ?
      PageFaultCount ULONG ?
      PeakWorkingSetSize ULONG64 ?
      WorkingSetSize ULONG64 ?
      QuotaPeakPagedPoolUsage ULONG64 ?
      QuotaPagedPoolUsage ULONG64 ?
      QuotaPeakNonPagedPoolUsage ULONG64 ?
      QuotaNonPagedPoolUsage ULONG64 ?
      PagefileUsage ULONG64 ?
      PeakPagefileUsage ULONG64 ?
      PeakVirtualSize ULONG64 ?
      VirtualSize ULONG64 ?
      PrivateUsage ULONG64 ?
      PrivateWorkingSetSize ULONG64 ?
      SharedCommitUsage ULONG64 ?
      JobSharedCommitUsage ULONG64 ?
      JobPrivateCommitUsage ULONG64 ?
      JobPeakPrivateCommitUsage ULONG64 ?
      JobPrivateCommitLimit ULONG64 ?
      JobTotalCommitLimit ULONG64 ?
    MINIDUMP_PROCESS_VM_COUNTERS_2 ends
    _MINIDUMP_PROCESS_VM_COUNTERS_2 typedef MINIDUMP_PROCESS_VM_COUNTERS_2
    PMINIDUMP_PROCESS_VM_COUNTERS_2 typedef ptr MINIDUMP_PROCESS_VM_COUNTERS_2
    MINIDUMP_PROCESS_VM_COUNTERS_N typedef MINIDUMP_PROCESS_VM_COUNTERS_2
    PMINIDUMP_PROCESS_VM_COUNTERS_N typedef ptr MINIDUMP_PROCESS_VM_COUNTERS_N
    MINIDUMP_USER_RECORD struct
      Type_ ULONG32 ?
      Memory_ MINIDUMP_LOCATION_DESCRIPTOR <>
    MINIDUMP_USER_RECORD ends
    _MINIDUMP_USER_RECORD typedef MINIDUMP_USER_RECORD
    PMINIDUMP_USER_RECORD typedef ptr MINIDUMP_USER_RECORD
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
    MINIDUMP_USER_STREAM struct
      Type_ ULONG32 ?
      BufferSize ULONG ?
      Buffer PVOID ?
    MINIDUMP_USER_STREAM ends
    _MINIDUMP_USER_STREAM typedef MINIDUMP_USER_STREAM
    PMINIDUMP_USER_STREAM typedef ptr MINIDUMP_USER_STREAM
    MINIDUMP_USER_STREAM_INFORMATION struct
      UserStreamCount ULONG ?
      UserStreamArray PMINIDUMP_USER_STREAM ?
    MINIDUMP_USER_STREAM_INFORMATION ends
    _MINIDUMP_USER_STREAM_INFORMATION typedef MINIDUMP_USER_STREAM_INFORMATION
    PMINIDUMP_USER_STREAM_INFORMATION typedef ptr MINIDUMP_USER_STREAM_INFORMATION
    MINIDUMP_CALLBACK_TYPE typedef SDWORD
    ModuleCallback equ 0
    ThreadCallback equ 1
    ThreadExCallback equ 2
    IncludeThreadCallback equ 3
    IncludeModuleCallback equ 4
    MemoryCallback equ 5
    CancelCallback equ 6
    WriteKernelMinidumpCallback equ 7
    KernelMinidumpStatusCallback equ 8
    RemoveMemoryCallback equ 9
    IncludeVmRegionCallback equ 10
    IoStartCallback equ 11
    IoWriteAllCallback equ 12
    IoFinishCallback equ 13
    ReadMemoryFailureCallback equ 14
    SecondaryFlagsCallback equ 15
    IsProcessSnapshotCallback equ 16
    VmStartCallback equ 17
    VmQueryCallback equ 18
    VmPreReadCallback equ 19
    VmPostReadCallback equ 20
    _MINIDUMP_CALLBACK_TYPE typedef MINIDUMP_CALLBACK_TYPE

    MINIDUMP_THREAD_CALLBACK struct
      ThreadId ULONG ?
      ThreadHandle HANDLE ?
      if Defined(_ARM64_)
        ;[...]
      endif
      Context CONTEXT <>
      SizeOfContext ULONG ?
      StackBase ULONG64 ?
      StackEnd ULONG64 ?
    MINIDUMP_THREAD_CALLBACK ends
    _MINIDUMP_THREAD_CALLBACK typedef MINIDUMP_THREAD_CALLBACK
    PMINIDUMP_THREAD_CALLBACK typedef ptr MINIDUMP_THREAD_CALLBACK
    MINIDUMP_THREAD_EX_CALLBACK struct
      ThreadId ULONG ?
      ThreadHandle HANDLE ?
      if Defined(_ARM64_)
        ;[...]
      endif
      Context CONTEXT <>
      SizeOfContext ULONG ?
      StackBase ULONG64 ?
      StackEnd ULONG64 ?
      BackingStoreBase ULONG64 ?
      BackingStoreEnd ULONG64 ?
    MINIDUMP_THREAD_EX_CALLBACK ends
    _MINIDUMP_THREAD_EX_CALLBACK typedef MINIDUMP_THREAD_EX_CALLBACK
    PMINIDUMP_THREAD_EX_CALLBACK typedef ptr MINIDUMP_THREAD_EX_CALLBACK
    MINIDUMP_INCLUDE_THREAD_CALLBACK struct
      ThreadId ULONG ?
    MINIDUMP_INCLUDE_THREAD_CALLBACK ends
    _MINIDUMP_INCLUDE_THREAD_CALLBACK typedef MINIDUMP_INCLUDE_THREAD_CALLBACK
    PMINIDUMP_INCLUDE_THREAD_CALLBACK typedef ptr MINIDUMP_INCLUDE_THREAD_CALLBACK
    THREAD_WRITE_FLAGS typedef SDWORD
    ThreadWriteThread equ 0001h
    ThreadWriteStack equ 0002h
    ThreadWriteContext equ 0004h
    ThreadWriteBackingStore equ 0008h
    ThreadWriteInstructionWindow equ 0010h
    ThreadWriteThreadData equ 0020h
    ThreadWriteThreadInfo equ 0040h
    _THREAD_WRITE_FLAGS typedef THREAD_WRITE_FLAGS

    MINIDUMP_MODULE_CALLBACK struct
      FullPath PWCHAR ?
      BaseOfImage ULONG64 ?
      SizeOfImage ULONG ?
      CheckSum ULONG ?
      TimeDateStamp ULONG ?
      VersionInfo VS_FIXEDFILEINFO <>
      CvRecord PVOID ?
      SizeOfCvRecord ULONG ?
      MiscRecord PVOID ?
      SizeOfMiscRecord ULONG ?
    MINIDUMP_MODULE_CALLBACK ends
    _MINIDUMP_MODULE_CALLBACK typedef MINIDUMP_MODULE_CALLBACK
    PMINIDUMP_MODULE_CALLBACK typedef ptr MINIDUMP_MODULE_CALLBACK
    MINIDUMP_INCLUDE_MODULE_CALLBACK struct
      BaseOfImage ULONG64 ?
    MINIDUMP_INCLUDE_MODULE_CALLBACK ends
    _MINIDUMP_INCLUDE_MODULE_CALLBACK typedef MINIDUMP_INCLUDE_MODULE_CALLBACK
    PMINIDUMP_INCLUDE_MODULE_CALLBACK typedef ptr MINIDUMP_INCLUDE_MODULE_CALLBACK
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    MODULE_WRITE_FLAGS typedef SDWORD
    ModuleWriteModule equ 0001h
    ModuleWriteDataSeg equ 0002h
    ModuleWriteMiscRecord equ 0004h
    ModuleWriteCvRecord equ 0008h
    ModuleReferencedByMemory equ 0010h
    ModuleWriteTlsData equ 0020h
    ModuleWriteCodeSegs equ 0040h
    _MODULE_WRITE_FLAGS typedef MODULE_WRITE_FLAGS

  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
    MINIDUMP_IO_CALLBACK struct
      Handle HANDLE ?
      Offset_ ULONG64 ?
      Buffer PVOID ?
      BufferBytes ULONG ?
    MINIDUMP_IO_CALLBACK ends
    _MINIDUMP_IO_CALLBACK typedef MINIDUMP_IO_CALLBACK
    PMINIDUMP_IO_CALLBACK typedef ptr MINIDUMP_IO_CALLBACK
    MINIDUMP_READ_MEMORY_FAILURE_CALLBACK struct
      Offset_ ULONG64 ?
      Bytes ULONG ?
      FailureStatus HRESULT ?
    MINIDUMP_READ_MEMORY_FAILURE_CALLBACK ends
    _MINIDUMP_READ_MEMORY_FAILURE_CALLBACK typedef MINIDUMP_READ_MEMORY_FAILURE_CALLBACK
    PMINIDUMP_READ_MEMORY_FAILURE_CALLBACK typedef ptr MINIDUMP_READ_MEMORY_FAILURE_CALLBACK
    MINIDUMP_VM_QUERY_CALLBACK struct
      Offset_ ULONG64 ?
    MINIDUMP_VM_QUERY_CALLBACK ends
    _MINIDUMP_VM_QUERY_CALLBACK typedef MINIDUMP_VM_QUERY_CALLBACK
    PMINIDUMP_VM_QUERY_CALLBACK typedef ptr MINIDUMP_VM_QUERY_CALLBACK
    MINIDUMP_VM_PRE_READ_CALLBACK struct
      Offset_ ULONG64 ?
      Buffer PVOID ?
      Size_ ULONG ?
    MINIDUMP_VM_PRE_READ_CALLBACK ends
    _MINIDUMP_VM_PRE_READ_CALLBACK typedef MINIDUMP_VM_PRE_READ_CALLBACK
    PMINIDUMP_VM_PRE_READ_CALLBACK typedef ptr MINIDUMP_VM_PRE_READ_CALLBACK
    MINIDUMP_VM_POST_READ_CALLBACK struct
      Offset_ ULONG64 ?
      Buffer PVOID ?
      Size_ ULONG ?
      Completed ULONG ?
      Status HRESULT ?
    MINIDUMP_VM_POST_READ_CALLBACK ends
    _MINIDUMP_VM_POST_READ_CALLBACK typedef MINIDUMP_VM_POST_READ_CALLBACK
    PMINIDUMP_VM_POST_READ_CALLBACK typedef ptr MINIDUMP_VM_POST_READ_CALLBACK
    MINIDUMP_CALLBACK_INPUT struct
      ProcessId ULONG ?
      ProcessHandle HANDLE ?
      CallbackType ULONG ?
      union
        Status HRESULT ?
        Thread MINIDUMP_THREAD_CALLBACK <>
        ThreadEx MINIDUMP_THREAD_EX_CALLBACK <>
        Module MINIDUMP_MODULE_CALLBACK <>
        IncludeThread MINIDUMP_INCLUDE_THREAD_CALLBACK <>
        IncludeModule MINIDUMP_INCLUDE_MODULE_CALLBACK <>
        Io MINIDUMP_IO_CALLBACK <>
        ReadMemoryFailure MINIDUMP_READ_MEMORY_FAILURE_CALLBACK <>
        SecondaryFlags ULONG ?
        VmQuery MINIDUMP_VM_QUERY_CALLBACK <>
        VmPreRead MINIDUMP_VM_PRE_READ_CALLBACK <>
        VmPostRead MINIDUMP_VM_POST_READ_CALLBACK <>
      ends
    MINIDUMP_CALLBACK_INPUT ends
    _MINIDUMP_CALLBACK_INPUT typedef MINIDUMP_CALLBACK_INPUT
    PMINIDUMP_CALLBACK_INPUT typedef ptr MINIDUMP_CALLBACK_INPUT
    MINIDUMP_CALLBACK_OUTPUT struct
      union
        ModuleWriteFlags ULONG ?
        ThreadWriteFlags ULONG ?
        SecondaryFlags ULONG ?
        struct
          MemoryBase ULONG64 ?
          MemorySize ULONG ?
        ends
        struct
          CheckCancel BOOL ?
          Cancel BOOL ?
        ends
        Handle HANDLE ?
        struct
          VmRegion MINIDUMP_MEMORY_INFO <>
          Continue BOOL ?
        ends
        struct
          VmQueryStatus HRESULT ?
          VmQueryResult MINIDUMP_MEMORY_INFO <>
        ends
        struct
          VmReadStatus HRESULT ?
          VmReadBytesCompleted ULONG ?
        ends
        Status HRESULT ?
      ends
    MINIDUMP_CALLBACK_OUTPUT ends
    _MINIDUMP_CALLBACK_OUTPUT typedef MINIDUMP_CALLBACK_OUTPUT
    PMINIDUMP_CALLBACK_OUTPUT typedef ptr MINIDUMP_CALLBACK_OUTPUT
    MINIDUMP_TYPE typedef SDWORD
    MiniDumpNormal equ 00000000h
    MiniDumpWithDataSegs equ 00000001h
    MiniDumpWithFullMemory equ 00000002h
    MiniDumpWithHandleData equ 00000004h
    MiniDumpFilterMemory equ 00000008h
    MiniDumpScanMemory equ 00000010h
    MiniDumpWithUnloadedModules equ 00000020h
    MiniDumpWithIndirectlyReferencedMemory equ 00000040h
    MiniDumpFilterModulePaths equ 00000080h
    MiniDumpWithProcessThreadData equ 00000100h
    MiniDumpWithPrivateReadWriteMemory equ 00000200h
    MiniDumpWithoutOptionalData equ 00000400h
    MiniDumpWithFullMemoryInfo equ 00000800h
    MiniDumpWithThreadInfo equ 00001000h
    MiniDumpWithCodeSegs equ 00002000h
    MiniDumpWithoutAuxiliaryState equ 00004000h
    MiniDumpWithFullAuxiliaryState equ 00008000h
    MiniDumpWithPrivateWriteCopyMemory equ 00010000h
    MiniDumpIgnoreInaccessibleMemory equ 00020000h
    MiniDumpWithTokenInformation equ 00040000h
    MiniDumpWithModuleHeaders equ 00080000h
    MiniDumpFilterTriage equ 00100000h
    MiniDumpWithAvxXStateContext equ 00200000h
    MiniDumpWithIptTrace equ 00400000h
    MiniDumpScanInaccessiblePartialPages equ 00800000h
    MiniDumpFilterWriteCombinedMemory equ 01000000h
    MiniDumpValidTypeFlags equ 01ffffffh
    _MINIDUMP_TYPE typedef MINIDUMP_TYPE

  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    MINIDUMP_SECONDARY_FLAGS typedef SDWORD
    MiniSecondaryWithoutPowerInfo equ 00000001h
    MiniSecondaryValidFlags equ 00000001h
    _MINIDUMP_SECONDARY_FLAGS typedef MINIDUMP_SECONDARY_FLAGS

  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
    TYPE_MINIDUMP_CALLBACK_ROUTINE typedef proto WIN_STD_CALL_CONV :PVOID, :PMINIDUMP_CALLBACK_INPUT, :PMINIDUMP_CALLBACK_OUTPUT
    MINIDUMP_CALLBACK_ROUTINE typedef ptr TYPE_MINIDUMP_CALLBACK_ROUTINE

    MINIDUMP_CALLBACK_INFORMATION struct
      CallbackRoutine MINIDUMP_CALLBACK_ROUTINE ?
      CallbackParam PVOID ?
    MINIDUMP_CALLBACK_INFORMATION ends
    _MINIDUMP_CALLBACK_INFORMATION typedef MINIDUMP_CALLBACK_INFORMATION
    PMINIDUMP_CALLBACK_INFORMATION typedef ptr MINIDUMP_CALLBACK_INFORMATION
    RVA_TO_ADDR macro Mapping, Rva
      exitm <((((Mapping)) + (Rva)))>
    endm
    MiniDumpWriteDump proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :HANDLE, :MINIDUMP_TYPE, :PMINIDUMP_EXCEPTION_INFORMATION, :PMINIDUMP_USER_STREAM_INFORMATION, :PMINIDUMP_CALLBACK_INFORMATION
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    MiniDumpReadDumpStream proto WIN_STD_CALL_CONV :PVOID, :ULONG, :ptr PMINIDUMP_DIRECTORY, :ptr PVOID, :ptr ULONG
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
    ifdef __cplusplus
      ;[...]
    endif
    if Defined(_MSC_VER)
      if _MSC_VER ge 800
        if _MSC_VER ge 1200
        else
        endif
      endif
    endif
    include poppack.inc
  endif
endif
