;Include file created by h2inc+ version C.2.0 on (UTC) 19/05/2024 07:52:23
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\memoryapi.h\memoryapi.h
;             Created on (UTC) 06/04/2024 06:15:56
;             Last modified on (UTC) 21/02/2024 18:13:14

ifdef _MSC_VER
endif
ifndef _MEMORYAPI_H_
  _MEMORYAPI_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  include minwinbase.inc
  ifdef __cplusplus
    ;[...]
  endif
  if _MSC_VER ge 1200
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    FILE_MAP_WRITE equ <SECTION_MAP_WRITE>
    FILE_MAP_READ equ <SECTION_MAP_READ>
    FILE_MAP_ALL_ACCESS equ <SECTION_ALL_ACCESS>
    FILE_MAP_EXECUTE equ <SECTION_MAP_EXECUTE_EXPLICIT>
    FILE_MAP_COPY equ 00000001h
    FILE_MAP_RESERVE equ 80000000h
    FILE_MAP_TARGETS_INVALID equ 40000000h
    FILE_MAP_LARGE_PAGES equ 20000000h
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, VirtualAlloc, WIN_STD_CALL_CONV,, <:LPVOID, :SIZE_T, :DWORD, :DWORD>, 16
    @DefProto DllImport, VirtualProtect, WIN_STD_CALL_CONV,, <:LPVOID, :SIZE_T, :DWORD, :PDWORD>, 16
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, VirtualFree, WIN_STD_CALL_CONV,, <:LPVOID, :SIZE_T, :DWORD>, 12
    @DefProto DllImport, VirtualQuery, WIN_STD_CALL_CONV,, <:LPCVOID, :PMEMORY_BASIC_INFORMATION, :SIZE_T>, 12
    @DefProto DllImport, VirtualAllocEx, WIN_STD_CALL_CONV,, <:HANDLE, :LPVOID, :SIZE_T, :DWORD, :DWORD>, 20
    @DefProto DllImport, VirtualProtectEx, WIN_STD_CALL_CONV,, <:HANDLE, :LPVOID, :SIZE_T, :DWORD, :PDWORD>, 20
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, VirtualQueryEx, WIN_STD_CALL_CONV,, <:HANDLE, :LPCVOID, :PMEMORY_BASIC_INFORMATION, :SIZE_T>, 16
    @DefProto DllImport, ReadProcessMemory, WIN_STD_CALL_CONV,, <:HANDLE, :LPCVOID, :LPVOID, :SIZE_T, :ptr SIZE_T>, 20
    @DefProto DllImport, WriteProcessMemory, WIN_STD_CALL_CONV,, <:HANDLE, :LPVOID, :LPCVOID, :SIZE_T, :ptr SIZE_T>, 20
    @DefProto DllImport, CreateFileMappingW, WIN_STD_CALL_CONV,, <:HANDLE, :LPSECURITY_ATTRIBUTES, :DWORD, :DWORD, :DWORD, :LPCWSTR>, 24
    ifdef UNICODE
      CreateFileMapping equ <CreateFileMappingW>
    endif
    @DefProto DllImport, OpenFileMappingW, WIN_STD_CALL_CONV,, <:DWORD, :BOOL, :LPCWSTR>, 12
    ifdef UNICODE
      OpenFileMapping equ <OpenFileMappingW>
    endif
    @DefProto DllImport, MapViewOfFile, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :DWORD, :DWORD, :SIZE_T>, 20
    @DefProto DllImport, MapViewOfFileEx, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :DWORD, :DWORD, :SIZE_T, :LPVOID>, 24
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, VirtualFreeEx, WIN_STD_CALL_CONV,, <:HANDLE, :LPVOID, :SIZE_T, :DWORD>, 16
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, FlushViewOfFile, WIN_STD_CALL_CONV,, <:LPCVOID, :SIZE_T>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, UnmapViewOfFile, WIN_STD_CALL_CONV,, <:LPCVOID>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetLargePageMinimum, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, GetProcessWorkingSetSize, WIN_STD_CALL_CONV,, <:HANDLE, :PSIZE_T, :PSIZE_T>, 12
    @DefProto DllImport, GetProcessWorkingSetSizeEx, WIN_STD_CALL_CONV,, <:HANDLE, :PSIZE_T, :PSIZE_T, :PDWORD>, 16
    @DefProto DllImport, SetProcessWorkingSetSize, WIN_STD_CALL_CONV,, <:HANDLE, :SIZE_T, :SIZE_T>, 12
    @DefProto DllImport, SetProcessWorkingSetSizeEx, WIN_STD_CALL_CONV,, <:HANDLE, :SIZE_T, :SIZE_T, :DWORD>, 16
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, VirtualLock, WIN_STD_CALL_CONV,, <:LPVOID, :SIZE_T>, 8
    @DefProto DllImport, VirtualUnlock, WIN_STD_CALL_CONV,, <:LPVOID, :SIZE_T>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetWriteWatch, WIN_STD_CALL_CONV,, <:DWORD, :PVOID, :SIZE_T, :ptr PVOID, :ptr ULONG_PTR, :LPDWORD>, 24
    @DefProto DllImport, ResetWriteWatch, WIN_STD_CALL_CONV,, <:LPVOID, :SIZE_T>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge _WIN32_WINNT_WINXP)
      MEMORY_RESOURCE_NOTIFICATION_TYPE typedef SDWORD
      LowMemoryResourceNotification equ 0
      HighMemoryResourceNotification equ 1
      _MEMORY_RESOURCE_NOTIFICATION_TYPE typedef MEMORY_RESOURCE_NOTIFICATION_TYPE

      @DefProto DllImport, CreateMemoryResourceNotification, WIN_STD_CALL_CONV,, <:MEMORY_RESOURCE_NOTIFICATION_TYPE>, 4
      @DefProto DllImport, QueryMemoryResourceNotification, WIN_STD_CALL_CONV,, <:HANDLE, :PBOOL>, 8
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    if (_WIN32_WINNT ge _WIN32_WINNT_WS03)
      FILE_CACHE_FLAGS_DEFINED equ <>
      FILE_CACHE_MAX_HARD_ENABLE equ 00000001h
      FILE_CACHE_MAX_HARD_DISABLE equ 00000002h
      FILE_CACHE_MIN_HARD_ENABLE equ 00000004h
      FILE_CACHE_MIN_HARD_DISABLE equ 00000008h
      @DefProto DllImport, GetSystemFileCacheSize, WIN_STD_CALL_CONV,, <:PSIZE_T, :PSIZE_T, :PDWORD>, 12
      @DefProto DllImport, SetSystemFileCacheSize, WIN_STD_CALL_CONV,, <:SIZE_T, :SIZE_T, :DWORD>, 12
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge _WIN32_WINNT_VISTA)
      @DefProto DllImport, CreateFileMappingNumaW, WIN_STD_CALL_CONV,, <:HANDLE, :LPSECURITY_ATTRIBUTES, :DWORD, :DWORD, :DWORD, :LPCWSTR, :DWORD>, 28
      ifdef UNICODE
        CreateFileMappingNuma equ <CreateFileMappingNumaW>
      endif
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
      WIN32_MEMORY_RANGE_ENTRY struct
        VirtualAddress PVOID ?
        NumberOfBytes SIZE_T ?
      WIN32_MEMORY_RANGE_ENTRY ends
      _WIN32_MEMORY_RANGE_ENTRY typedef WIN32_MEMORY_RANGE_ENTRY
      PWIN32_MEMORY_RANGE_ENTRY typedef ptr WIN32_MEMORY_RANGE_ENTRY
      @DefProto DllImport, PrefetchVirtualMemory, WIN_STD_CALL_CONV,, <:HANDLE, :ULONG_PTR, :PWIN32_MEMORY_RANGE_ENTRY, :ULONG>, 16
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
      @DefProto DllImport, CreateFileMappingFromApp, WIN_STD_CALL_CONV,, <:HANDLE, :PSECURITY_ATTRIBUTES, :ULONG, :ULONG64, :PCWSTR>, 20
      @DefProto DllImport, MapViewOfFileFromApp, WIN_STD_CALL_CONV,, <:HANDLE, :ULONG, :ULONG64, :SIZE_T>, 16
      @DefProto DllImport, UnmapViewOfFileEx, WIN_STD_CALL_CONV,, <:PVOID, :ULONG>, 8
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge _WIN32_WINNT_WINXP)
      @DefProto DllImport, AllocateUserPhysicalPages, WIN_STD_CALL_CONV,, <:HANDLE, :PULONG_PTR, :PULONG_PTR>, 12
      @DefProto DllImport, FreeUserPhysicalPages, WIN_STD_CALL_CONV,, <:HANDLE, :PULONG_PTR, :PULONG_PTR>, 12
      @DefProto DllImport, MapUserPhysicalPages, WIN_STD_CALL_CONV,, <:PVOID, :ULONG_PTR, :PULONG_PTR>, 12
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_VISTA)
      @DefProto DllImport, AllocateUserPhysicalPagesNuma, WIN_STD_CALL_CONV,, <:HANDLE, :PULONG_PTR, :PULONG_PTR, :DWORD>, 16
      @DefProto DllImport, VirtualAllocExNuma, WIN_STD_CALL_CONV,, <:HANDLE, :LPVOID, :SIZE_T, :DWORD, :DWORD, :DWORD>, 24
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
      MEHC_PATROL_SCRUBBER_PRESENT equ 1h
      @DefProto DllImport, GetMemoryErrorHandlingCapabilities, WIN_STD_CALL_CONV,, <:PULONG>, 4
      PBAD_MEMORY_CALLBACK_ROUTINE typedef ptr BAD_MEMORY_CALLBACK_ROUTINE
      @DefProto DllImport, RegisterBadMemoryNotification, WIN_STD_CALL_CONV,, <:PBAD_MEMORY_CALLBACK_ROUTINE>, 4
      @DefProto DllImport, UnregisterBadMemoryNotification, WIN_STD_CALL_CONV,, <:PVOID>, 4
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge _WIN32_WINNT_WINBLUE)
      if ((NTDDI_VERSION gt NTDDI_WINBLUE) or (NTDDI_VERSION eq NTDDI_WINBLUE and Defined(WINBLUE_KBSPRING14)))
        OFFER_PRIORITY typedef SDWORD
        VmOfferPriorityVeryLow equ 1
        VmOfferPriorityLow equ 2
        VmOfferPriorityBelowNormal equ 3
        VmOfferPriorityNormal equ 4

        OfferVirtualMemory proto WIN_STD_CALL_CONV :PVOID, :SIZE_T, :OFFER_PRIORITY
        ReclaimVirtualMemory proto WIN_STD_CALL_CONV :ptr, :SIZE_T
        DiscardVirtualMemory proto WIN_STD_CALL_CONV :PVOID, :SIZE_T
      endif
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN10)
      @DefProto DllImport, SetProcessValidCallTargets, WIN_STD_CALL_CONV,, <:HANDLE, :PVOID, :SIZE_T, :ULONG, :PCFG_CALL_TARGET_INFO>, 20
      @DefProto DllImport, SetProcessValidCallTargetsForMappedView, WIN_STD_CALL_CONV,, <:HANDLE, :PVOID, :SIZE_T, :ULONG, :PCFG_CALL_TARGET_INFO, :HANDLE, :ULONG64>, 28
      @DefProto DllImport, VirtualAllocFromApp, WIN_STD_CALL_CONV,, <:PVOID, :SIZE_T, :ULONG, :ULONG>, 16
      @DefProto DllImport, VirtualProtectFromApp, WIN_STD_CALL_CONV,, <:PVOID, :SIZE_T, :ULONG, :PULONG>, 16
      @DefProto DllImport, OpenFileMappingFromApp, WIN_STD_CALL_CONV,, <:ULONG, :BOOL, :PCWSTR>, 12
    endif
  endif
  if WINAPI_PARTITION_APP and  not (WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
      CreateFileMapping equ <CreateFileMappingW>
      CreateFileMappingW proto WIN_STD_CALL_CONV :HANDLE, :LPSECURITY_ATTRIBUTES, :DWORD, :DWORD, :DWORD, :LPCWSTR
      MapViewOfFile proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :DWORD, :DWORD, :SIZE_T
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN10)
      VirtualAlloc proto WIN_STD_CALL_CONV :LPVOID, :SIZE_T, :DWORD, :DWORD
      VirtualProtect proto WIN_STD_CALL_CONV :LPVOID, :SIZE_T, :DWORD, :PDWORD
      OpenFileMapping equ <OpenFileMappingW>
      OpenFileMappingW proto WIN_STD_CALL_CONV :DWORD, :BOOL, :LPCWSTR
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (NTDDI_VERSION ge NTDDI_WIN10_RS1)
      WIN32_MEMORY_INFORMATION_CLASS typedef SDWORD
      MemoryRegionInfo equ 0

      if _MSC_VER ge 1200
      endif
      WIN32_MEMORY_REGION_INFORMATION struct
        AllocationBase PVOID ?
        AllocationProtect ULONG ?
        union
          Flags ULONG ?
          struct
            ANONYMOUS_REC0 record ANONYMOUS_REC0_Reserved:26, ANONYMOUS_REC0_DirectMapped:1, ANONYMOUS_REC0_MappedPhysical:1, ANONYMOUS_REC0_MappedPageFile:1, ANONYMOUS_REC0_MappedImage:1, ANONYMOUS_REC0_MappedDataFile:1, ANONYMOUS_REC0_Private:1
            ANONYMOUS_REC0 <>
          ends
        ends
        RegionSize SIZE_T ?
        CommitSize SIZE_T ?
      WIN32_MEMORY_REGION_INFORMATION ends
      if _MSC_VER ge 1200
      endif
      @DefProto DllImport, QueryVirtualMemoryInformation, WIN_STD_CALL_CONV,, <:HANDLE, :ptr VOID, :WIN32_MEMORY_INFORMATION_CLASS, :PVOID, :SIZE_T, :PSIZE_T>, 24
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_RS2)
      @DefProto DllImport, MapViewOfFileNuma2, WIN_STD_CALL_CONV,, <:HANDLE, :HANDLE, :ULONG64, :PVOID, :SIZE_T, :ULONG, :ULONG, :ULONG>, 32
      if  not Defined(MIDL_PASS)
        MapViewOfFile2 proto WIN_STD_CALL_CONV :HANDLE, :HANDLE, :ULONG64, :PVOID, :SIZE_T, :ULONG, :ULONG
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, UnmapViewOfFile2, WIN_STD_CALL_CONV,, <:HANDLE, :PVOID, :ULONG>, 12
    @DefProto DllImport, VirtualUnlockEx, WIN_STD_CALL_CONV,, <:HANDLE, :LPVOID, :SIZE_T>, 12
  endif
  if (NTDDI_VERSION ge NTDDI_WIN10_RS4)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, VirtualAlloc2, WIN_STD_CALL_CONV,, <:HANDLE, :PVOID, :SIZE_T, :ULONG, :ULONG, :ptr MEM_EXTENDED_PARAMETER, :ULONG>, 28
      @DefProto DllImport, MapViewOfFile3, WIN_STD_CALL_CONV,, <:HANDLE, :HANDLE, :PVOID, :ULONG64, :SIZE_T, :ULONG, :ULONG, :ptr MEM_EXTENDED_PARAMETER, :ULONG>, 36
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, VirtualAlloc2FromApp, WIN_STD_CALL_CONV,, <:HANDLE, :PVOID, :SIZE_T, :ULONG, :ULONG, :ptr MEM_EXTENDED_PARAMETER, :ULONG>, 28
      @DefProto DllImport, MapViewOfFile3FromApp, WIN_STD_CALL_CONV,, <:HANDLE, :HANDLE, :PVOID, :ULONG64, :SIZE_T, :ULONG, :ULONG, :ptr MEM_EXTENDED_PARAMETER, :ULONG>, 36
    endif
  endif
  if (NTDDI_VERSION ge NTDDI_WIN10_RS5)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, CreateFileMapping2, WIN_STD_CALL_CONV,, <:HANDLE, :ptr SECURITY_ATTRIBUTES, :ULONG, :ULONG, :ULONG, :ULONG64, :PCWSTR, :ptr MEM_EXTENDED_PARAMETER, :ULONG>, 36
    endif
  endif
  if (NTDDI_VERSION ge NTDDI_WIN10_FE)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, AllocateUserPhysicalPages2, WIN_STD_CALL_CONV,, <:HANDLE, :PULONG_PTR, :PULONG_PTR, :PMEM_EXTENDED_PARAMETER, :ULONG>, 20
      WIN32_MEMORY_PARTITION_INFORMATION_CLASS typedef SDWORD
      MemoryPartitionInfo equ 0
      MemoryPartitionDedicatedMemoryInfo equ 1

      WIN32_MEMORY_PARTITION_INFORMATION struct
        Flags ULONG ?
        NumaNode ULONG ?
        Channel ULONG ?
        NumberOfNumaNodes ULONG ?
        ResidentAvailablePages ULONG64 ?
        CommittedPages ULONG64 ?
        CommitLimit ULONG64 ?
        PeakCommitment ULONG64 ?
        TotalNumberOfPages ULONG64 ?
        AvailablePages ULONG64 ?
        ZeroPages ULONG64 ?
        FreePages ULONG64 ?
        StandbyPages ULONG64 ?
        Reserved ULONG64 16 dup (?)
        MaximumCommitLimit ULONG64 ?
        Reserved2 ULONG64 ?
        PartitionId ULONG ?
      WIN32_MEMORY_PARTITION_INFORMATION ends
      @DefProto DllImport, OpenDedicatedMemoryPartition, WIN_STD_CALL_CONV,, <:HANDLE, :ULONG64, :ACCESS_MASK, :BOOL>, 16
      @DefProto DllImport, QueryPartitionInformation, WIN_STD_CALL_CONV,, <:HANDLE, :WIN32_MEMORY_PARTITION_INFORMATION_CLASS, :PVOID, :ULONG>, 16
    endif
  endif
  if _MSC_VER ge 1200
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
