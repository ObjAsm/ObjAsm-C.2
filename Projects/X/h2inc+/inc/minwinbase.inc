;Include file created by h2inc+ version C.2.0 on (UTC) 19/05/2024 07:52:23
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\minwinbase.h\minwinbase.h
;             Created on (UTC) 06/04/2024 06:15:56
;             Last modified on (UTC) 21/02/2024 18:13:36

ifndef _MINWINBASE_
  _MINWINBASE_ equ <>
  if (_MSC_VER ge 800)
    ifndef __WINDOWS_DONT_DISABLE_PRAGMA_PACK_WARNING__
    endif
    if _MSC_VER ge 1200
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
  MoveMemory equ <RtlMoveMemory>
  CopyMemory equ <RtlCopyMemory>
  FillMemory equ <RtlFillMemory>
  ZeroMemory equ <RtlZeroMemory>
  SECURITY_ATTRIBUTES struct
    nLength DWORD ?
    lpSecurityDescriptor LPVOID ?
    bInheritHandle BOOL ?
  SECURITY_ATTRIBUTES ends
  _SECURITY_ATTRIBUTES typedef SECURITY_ATTRIBUTES
  PSECURITY_ATTRIBUTES typedef ptr SECURITY_ATTRIBUTES
  LPSECURITY_ATTRIBUTES typedef ptr SECURITY_ATTRIBUTES
  OVERLAPPED struct
    Internal ULONG_PTR ?
    InternalHigh ULONG_PTR ?
    union
      struct
        Offset_ DWORD ?
        OffsetHigh DWORD ?
      ends
      Pointer PVOID ?
    ends
    hEvent HANDLE ?
  OVERLAPPED ends
  _OVERLAPPED typedef OVERLAPPED
  LPOVERLAPPED typedef ptr OVERLAPPED
  OVERLAPPED_ENTRY struct
    lpCompletionKey ULONG_PTR ?
    lpOverlapped LPOVERLAPPED ?
    Internal ULONG_PTR ?
    dwNumberOfBytesTransferred DWORD ?
  OVERLAPPED_ENTRY ends
  _OVERLAPPED_ENTRY typedef OVERLAPPED_ENTRY
  LPOVERLAPPED_ENTRY typedef ptr OVERLAPPED_ENTRY
  ifndef _FILETIME_
    _FILETIME_ equ <>
    FILETIME struct
      dwLowDateTime DWORD ?
      dwHighDateTime DWORD ?
    FILETIME ends
    _FILETIME typedef FILETIME
    PFILETIME typedef ptr FILETIME
    LPFILETIME typedef ptr FILETIME
  endif
  SYSTEMTIME struct
    wYear WORD ?
    wMonth WORD ?
    wDayOfWeek WORD ?
    wDay WORD ?
    wHour WORD ?
    wMinute WORD ?
    wSecond WORD ?
    wMilliseconds WORD ?
  SYSTEMTIME ends
  _SYSTEMTIME typedef SYSTEMTIME
  PSYSTEMTIME typedef ptr SYSTEMTIME
  LPSYSTEMTIME typedef ptr SYSTEMTIME
  WIN32_FIND_DATAA struct
    dwFileAttributes DWORD ?
    ftCreationTime FILETIME <>
    ftLastAccessTime FILETIME <>
    ftLastWriteTime FILETIME <>
    nFileSizeHigh DWORD ?
    nFileSizeLow DWORD ?
    dwReserved0 DWORD ?
    dwReserved1 DWORD ?
    cFileName CHAR MAX_PATH dup (?)
    cAlternateFileName CHAR 14 dup (?)
    ifdef _MAC
      ;[...]
    endif
  WIN32_FIND_DATAA ends
  _WIN32_FIND_DATAA typedef WIN32_FIND_DATAA
  PWIN32_FIND_DATAA typedef ptr WIN32_FIND_DATAA
  LPWIN32_FIND_DATAA typedef ptr WIN32_FIND_DATAA
  WIN32_FIND_DATAW struct
    dwFileAttributes DWORD ?
    ftCreationTime FILETIME <>
    ftLastAccessTime FILETIME <>
    ftLastWriteTime FILETIME <>
    nFileSizeHigh DWORD ?
    nFileSizeLow DWORD ?
    dwReserved0 DWORD ?
    dwReserved1 DWORD ?
    cFileName WCHAR MAX_PATH dup (?)
    cAlternateFileName WCHAR 14 dup (?)
    ifdef _MAC
      ;[...]
    endif
  WIN32_FIND_DATAW ends
  _WIN32_FIND_DATAW typedef WIN32_FIND_DATAW
  PWIN32_FIND_DATAW typedef ptr WIN32_FIND_DATAW
  LPWIN32_FIND_DATAW typedef ptr WIN32_FIND_DATAW
  ifdef UNICODE
    WIN32_FIND_DATA typedef WIN32_FIND_DATAW
    PWIN32_FIND_DATA typedef PWIN32_FIND_DATAW
    LPWIN32_FIND_DATA typedef LPWIN32_FIND_DATAW
  else
    WIN32_FIND_DATA typedef WIN32_FIND_DATAA
    PWIN32_FIND_DATA typedef PWIN32_FIND_DATAA
    LPWIN32_FIND_DATA typedef LPWIN32_FIND_DATAA
  endif
  if (_WIN32_WINNT ge 0400h)
    FINDEX_INFO_LEVELS typedef SDWORD
    FindExInfoStandard equ 0
    FindExInfoBasic equ 1
    FindExInfoMaxInfoLevel equ 2
    _FINDEX_INFO_LEVELS typedef FINDEX_INFO_LEVELS

    FIND_FIRST_EX_CASE_SENSITIVE equ 00000001h
    FIND_FIRST_EX_LARGE_FETCH equ 00000002h
    if (NTDDI_VERSION ge NTDDI_WIN10_RS4)
      FIND_FIRST_EX_ON_DISK_ENTRIES_ONLY equ 00000004h
    endif
    FINDEX_SEARCH_OPS typedef SDWORD
    FindExSearchNameMatch equ 0
    FindExSearchLimitToDirectories equ 1
    FindExSearchLimitToDevices equ 2
    FindExSearchMaxSearchOp equ 3
    _FINDEX_SEARCH_OPS typedef FINDEX_SEARCH_OPS

  endif
  if (_WIN32_WINNT ge 0400h)
    if (NTDDI_VERSION ge NTDDI_WIN10_RS3)
      READ_DIRECTORY_NOTIFY_INFORMATION_CLASS typedef SDWORD
      ReadDirectoryNotifyInformation equ 1
      ReadDirectoryNotifyExtendedInformation equ 2
      if (NTDDI_VERSION ge NTDDI_WIN10_NI)
        ReadDirectoryNotifyFullInformation equ 3
      endif
      ReadDirectoryNotifyMaximumInformation equ 4
      _READ_DIRECTORY_NOTIFY_INFORMATION_CLASS typedef READ_DIRECTORY_NOTIFY_INFORMATION_CLASS
      PREAD_DIRECTORY_NOTIFY_INFORMATION_CLASS typedef ptr READ_DIRECTORY_NOTIFY_INFORMATION_CLASS
    endif
  endif
  GET_FILEEX_INFO_LEVELS typedef SDWORD
  GetFileExInfoStandard equ 0
  GetFileExMaxInfoLevel equ 1
  _GET_FILEEX_INFO_LEVELS typedef GET_FILEEX_INFO_LEVELS

  if (NTDDI_VERSION ge NTDDI_LONGHORN)
    FILE_INFO_BY_HANDLE_CLASS typedef SDWORD
    FileBasicInfo equ 0
    FileStandardInfo equ 1
    FileNameInfo equ 2
    FileRenameInfo equ 3
    FileDispositionInfo equ 4
    FileAllocationInfo equ 5
    FileEndOfFileInfo equ 6
    FileStreamInfo equ 7
    FileCompressionInfo equ 8
    FileAttributeTagInfo equ 9
    FileIdBothDirectoryInfo equ 10
    FileIdBothDirectoryRestartInfo equ 11
    FileIoPriorityHintInfo equ 12
    FileRemoteProtocolInfo equ 13
    FileFullDirectoryInfo equ 14
    FileFullDirectoryRestartInfo equ 15
    if (NTDDI_VERSION ge NTDDI_WIN8)
      FileStorageInfo equ 16
      FileAlignmentInfo equ 17
      FileIdInfo equ 18
      FileIdExtdDirectoryInfo equ 19
      FileIdExtdDirectoryRestartInfo equ 20
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_RS1)
      FileDispositionInfoEx equ 21
      FileRenameInfoEx equ 22
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_19H1)
      FileCaseSensitiveInfo equ 23
      FileNormalizedNameInfo equ 24
    endif
    MaximumFileInfoByHandleClass equ 25
    _FILE_INFO_BY_HANDLE_CLASS typedef FILE_INFO_BY_HANDLE_CLASS
    PFILE_INFO_BY_HANDLE_CLASS typedef ptr FILE_INFO_BY_HANDLE_CLASS
  endif
  CRITICAL_SECTION typedef RTL_CRITICAL_SECTION
  PCRITICAL_SECTION typedef PRTL_CRITICAL_SECTION
  LPCRITICAL_SECTION typedef PRTL_CRITICAL_SECTION
  CRITICAL_SECTION_DEBUG typedef RTL_CRITICAL_SECTION_DEBUG
  PCRITICAL_SECTION_DEBUG typedef PRTL_CRITICAL_SECTION_DEBUG
  LPCRITICAL_SECTION_DEBUG typedef PRTL_CRITICAL_SECTION_DEBUG
  TYPE_LPOVERLAPPED_COMPLETION_ROUTINE typedef proto WIN_STD_CALL_CONV :DWORD, :DWORD, :LPOVERLAPPED
  LPOVERLAPPED_COMPLETION_ROUTINE typedef ptr TYPE_LPOVERLAPPED_COMPLETION_ROUTINE

  LOCKFILE_FAIL_IMMEDIATELY equ 00000001h
  LOCKFILE_EXCLUSIVE_LOCK equ 00000002h
  PROCESS_HEAP_ENTRY struct
    lpData PVOID ?
    cbData DWORD ?
    cbOverhead BYTE ?
    iRegionIndex BYTE ?
    wFlags WORD ?
    union
      struct Block
        hMem HANDLE ?
        dwReserved DWORD 3 dup (?)
      ends
      struct Region
        dwCommittedSize DWORD ?
        dwUnCommittedSize DWORD ?
        lpFirstBlock LPVOID ?
        lpLastBlock LPVOID ?
      ends
    ends
  PROCESS_HEAP_ENTRY ends
  _PROCESS_HEAP_ENTRY typedef PROCESS_HEAP_ENTRY
  LPPROCESS_HEAP_ENTRY typedef ptr PROCESS_HEAP_ENTRY
  PPROCESS_HEAP_ENTRY typedef ptr PROCESS_HEAP_ENTRY
  PROCESS_HEAP_REGION equ 0001h
  PROCESS_HEAP_UNCOMMITTED_RANGE equ 0002h
  PROCESS_HEAP_ENTRY_BUSY equ 0004h
  PROCESS_HEAP_SEG_ALLOC equ 0008h
  PROCESS_HEAP_ENTRY_MOVEABLE equ 0010h
  PROCESS_HEAP_ENTRY_DDESHARE equ 0020h
  REASON_CONTEXT struct
    Version ULONG ?
    Flags DWORD ?
    union Reason
      struct Detailed
        LocalizedReasonModule HMODULE ?
        LocalizedReasonId ULONG ?
        ReasonStringCount ULONG ?
        ReasonStrings POINTER ?
      ends
      SimpleReasonString LPWSTR ?
    ends
  REASON_CONTEXT ends
  _REASON_CONTEXT typedef REASON_CONTEXT
  PREASON_CONTEXT typedef ptr REASON_CONTEXT
  EXCEPTION_DEBUG_EVENT equ 1
  CREATE_THREAD_DEBUG_EVENT equ 2
  CREATE_PROCESS_DEBUG_EVENT equ 3
  EXIT_THREAD_DEBUG_EVENT equ 4
  EXIT_PROCESS_DEBUG_EVENT equ 5
  LOAD_DLL_DEBUG_EVENT equ 6
  UNLOAD_DLL_DEBUG_EVENT equ 7
  OUTPUT_DEBUG_STRING_EVENT equ 8
  RIP_EVENT equ 9
  TYPE_PTHREAD_START_ROUTINE typedef proto WIN_STD_CALL_CONV :LPVOID
  PTHREAD_START_ROUTINE typedef ptr TYPE_PTHREAD_START_ROUTINE

  LPTHREAD_START_ROUTINE typedef PTHREAD_START_ROUTINE
  TYPE_PENCLAVE_ROUTINE typedef proto WIN_STD_CALL_CONV :LPVOID
  PENCLAVE_ROUTINE typedef ptr TYPE_PENCLAVE_ROUTINE

  LPENCLAVE_ROUTINE typedef PENCLAVE_ROUTINE
  EXCEPTION_DEBUG_INFO struct
    ExceptionRecord EXCEPTION_RECORD <>
    dwFirstChance DWORD ?
  EXCEPTION_DEBUG_INFO ends
  _EXCEPTION_DEBUG_INFO typedef EXCEPTION_DEBUG_INFO
  LPEXCEPTION_DEBUG_INFO typedef ptr EXCEPTION_DEBUG_INFO
  CREATE_THREAD_DEBUG_INFO struct
    hThread HANDLE ?
    lpThreadLocalBase LPVOID ?
    lpStartAddress LPTHREAD_START_ROUTINE ?
  CREATE_THREAD_DEBUG_INFO ends
  _CREATE_THREAD_DEBUG_INFO typedef CREATE_THREAD_DEBUG_INFO
  LPCREATE_THREAD_DEBUG_INFO typedef ptr CREATE_THREAD_DEBUG_INFO
  CREATE_PROCESS_DEBUG_INFO struct
    hFile HANDLE ?
    hProcess HANDLE ?
    hThread HANDLE ?
    lpBaseOfImage LPVOID ?
    dwDebugInfoFileOffset DWORD ?
    nDebugInfoSize DWORD ?
    lpThreadLocalBase LPVOID ?
    lpStartAddress LPTHREAD_START_ROUTINE ?
    lpImageName LPVOID ?
    fUnicode WORD ?
  CREATE_PROCESS_DEBUG_INFO ends
  _CREATE_PROCESS_DEBUG_INFO typedef CREATE_PROCESS_DEBUG_INFO
  LPCREATE_PROCESS_DEBUG_INFO typedef ptr CREATE_PROCESS_DEBUG_INFO
  EXIT_THREAD_DEBUG_INFO struct
    dwExitCode DWORD ?
  EXIT_THREAD_DEBUG_INFO ends
  _EXIT_THREAD_DEBUG_INFO typedef EXIT_THREAD_DEBUG_INFO
  LPEXIT_THREAD_DEBUG_INFO typedef ptr EXIT_THREAD_DEBUG_INFO
  EXIT_PROCESS_DEBUG_INFO struct
    dwExitCode DWORD ?
  EXIT_PROCESS_DEBUG_INFO ends
  _EXIT_PROCESS_DEBUG_INFO typedef EXIT_PROCESS_DEBUG_INFO
  LPEXIT_PROCESS_DEBUG_INFO typedef ptr EXIT_PROCESS_DEBUG_INFO
  LOAD_DLL_DEBUG_INFO struct
    hFile HANDLE ?
    lpBaseOfDll LPVOID ?
    dwDebugInfoFileOffset DWORD ?
    nDebugInfoSize DWORD ?
    lpImageName LPVOID ?
    fUnicode WORD ?
  LOAD_DLL_DEBUG_INFO ends
  _LOAD_DLL_DEBUG_INFO typedef LOAD_DLL_DEBUG_INFO
  LPLOAD_DLL_DEBUG_INFO typedef ptr LOAD_DLL_DEBUG_INFO
  UNLOAD_DLL_DEBUG_INFO struct
    lpBaseOfDll LPVOID ?
  UNLOAD_DLL_DEBUG_INFO ends
  _UNLOAD_DLL_DEBUG_INFO typedef UNLOAD_DLL_DEBUG_INFO
  LPUNLOAD_DLL_DEBUG_INFO typedef ptr UNLOAD_DLL_DEBUG_INFO
  OUTPUT_DEBUG_STRING_INFO struct
    lpDebugStringData LPSTR ?
    fUnicode WORD ?
    nDebugStringLength WORD ?
  OUTPUT_DEBUG_STRING_INFO ends
  _OUTPUT_DEBUG_STRING_INFO typedef OUTPUT_DEBUG_STRING_INFO
  LPOUTPUT_DEBUG_STRING_INFO typedef ptr OUTPUT_DEBUG_STRING_INFO
  RIP_INFO struct
    dwError DWORD ?
    dwType DWORD ?
  RIP_INFO ends
  _RIP_INFO typedef RIP_INFO
  LPRIP_INFO typedef ptr RIP_INFO
  DEBUG_EVENT struct
    dwDebugEventCode DWORD ?
    dwProcessId DWORD ?
    dwThreadId DWORD ?
    union u
      Exception EXCEPTION_DEBUG_INFO <>
      CreateThread CREATE_THREAD_DEBUG_INFO <>
      CreateProcessInfo CREATE_PROCESS_DEBUG_INFO <>
      ExitThread EXIT_THREAD_DEBUG_INFO <>
      ExitProcess EXIT_PROCESS_DEBUG_INFO <>
      LoadDll LOAD_DLL_DEBUG_INFO <>
      UnloadDll UNLOAD_DLL_DEBUG_INFO <>
      DebugString OUTPUT_DEBUG_STRING_INFO <>
      RipInfo RIP_INFO <>
    ends
  DEBUG_EVENT ends
  _DEBUG_EVENT typedef DEBUG_EVENT
  LPDEBUG_EVENT typedef ptr DEBUG_EVENT
  if  not Defined(MIDL_PASS)
    LPCONTEXT typedef PCONTEXT
  endif
  STILL_ACTIVE equ <STATUS_PENDING>
  EXCEPTION_ACCESS_VIOLATION equ <STATUS_ACCESS_VIOLATION>
  EXCEPTION_DATATYPE_MISALIGNMENT equ <STATUS_DATATYPE_MISALIGNMENT>
  EXCEPTION_BREAKPOINT equ <STATUS_BREAKPOINT>
  EXCEPTION_SINGLE_STEP equ <STATUS_SINGLE_STEP>
  EXCEPTION_ARRAY_BOUNDS_EXCEEDED equ <STATUS_ARRAY_BOUNDS_EXCEEDED>
  EXCEPTION_FLT_DENORMAL_OPERAND equ <STATUS_FLOAT_DENORMAL_OPERAND>
  EXCEPTION_FLT_DIVIDE_BY_ZERO equ <STATUS_FLOAT_DIVIDE_BY_ZERO>
  EXCEPTION_FLT_INEXACT_RESULT equ <STATUS_FLOAT_INEXACT_RESULT>
  EXCEPTION_FLT_INVALID_OPERATION equ <STATUS_FLOAT_INVALID_OPERATION>
  EXCEPTION_FLT_OVERFLOW equ <STATUS_FLOAT_OVERFLOW>
  EXCEPTION_FLT_STACK_CHECK equ <STATUS_FLOAT_STACK_CHECK>
  EXCEPTION_FLT_UNDERFLOW equ <STATUS_FLOAT_UNDERFLOW>
  EXCEPTION_INT_DIVIDE_BY_ZERO equ <STATUS_INTEGER_DIVIDE_BY_ZERO>
  EXCEPTION_INT_OVERFLOW equ <STATUS_INTEGER_OVERFLOW>
  EXCEPTION_PRIV_INSTRUCTION equ <STATUS_PRIVILEGED_INSTRUCTION>
  EXCEPTION_IN_PAGE_ERROR equ <STATUS_IN_PAGE_ERROR>
  EXCEPTION_ILLEGAL_INSTRUCTION equ <STATUS_ILLEGAL_INSTRUCTION>
  EXCEPTION_NONCONTINUABLE_EXCEPTION equ <STATUS_NONCONTINUABLE_EXCEPTION>
  EXCEPTION_STACK_OVERFLOW equ <STATUS_STACK_OVERFLOW>
  EXCEPTION_INVALID_DISPOSITION equ <STATUS_INVALID_DISPOSITION>
  EXCEPTION_GUARD_PAGE equ <STATUS_GUARD_PAGE_VIOLATION>
  EXCEPTION_INVALID_HANDLE equ <STATUS_INVALID_HANDLE>
  EXCEPTION_POSSIBLE_DEADLOCK equ <STATUS_POSSIBLE_DEADLOCK>
  CONTROL_C_EXIT equ <STATUS_CONTROL_C_EXIT>
  LMEM_FIXED equ 0000h
  LMEM_MOVEABLE equ 0002h
  LMEM_NOCOMPACT equ 0010h
  LMEM_NODISCARD equ 0020h
  LMEM_ZEROINIT equ 0040h
  LMEM_MODIFY equ 0080h
  LMEM_DISCARDABLE equ 0F00h
  LMEM_VALID_FLAGS equ 0F72h
  LMEM_INVALID_HANDLE equ 8000h
  LHND equ <(LMEM_MOVEABLE or LMEM_ZEROINIT)>
  LPTR equ <(LMEM_FIXED or LMEM_ZEROINIT)>
  NONZEROLHND equ <(LMEM_MOVEABLE)>
  NONZEROLPTR equ <(LMEM_FIXED)>
  LocalDiscard macro h
    exitm <LocalReAlloc ((h), 0, LMEM_MOVEABLE)>
  endm
  LMEM_DISCARDED equ 4000h
  LMEM_LOCKCOUNT equ 00FFh
  NUMA_NO_PREFERRED_NODE equ (- 1)
  ifdef __cplusplus
    ;[...]
  endif
  if (_MSC_VER ge 800)
    if _MSC_VER ge 1200
    else
    endif
  endif
endif
