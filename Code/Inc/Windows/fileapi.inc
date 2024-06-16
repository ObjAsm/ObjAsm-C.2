;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\fileapi.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 21/02/2024 18:13:14

ifdef _MSC_VER
endif
ifndef _APISETFILE_
  _APISETFILE_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  include minwinbase.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    CREATE_NEW equ 1
    CREATE_ALWAYS equ 2
    OPEN_EXISTING equ 3
    OPEN_ALWAYS equ 4
    TRUNCATE_EXISTING equ 5
    INVALID_FILE_SIZE equ (0FFFFFFFFh)
    INVALID_SET_FILE_POINTER equ (- 1)
    INVALID_FILE_ATTRIBUTES equ (- 1)
    @DefProto DllImport, CompareFileTime, WIN_STD_CALL_CONV,, <:ptr FILETIME, :ptr FILETIME>, 8
    @DefProto DllImport, CreateDirectoryA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPSECURITY_ATTRIBUTES>, 8
    @DefProto DllImport, CreateDirectoryW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPSECURITY_ATTRIBUTES>, 8
    ifdef UNICODE
      CreateDirectory equ <CreateDirectoryW>
    else
      CreateDirectory equ <CreateDirectoryA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, CreateFileA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :DWORD, :LPSECURITY_ATTRIBUTES, :DWORD, :DWORD, :HANDLE>, 28
    @DefProto DllImport, CreateFileW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :DWORD, :LPSECURITY_ATTRIBUTES, :DWORD, :DWORD, :HANDLE>, 28
    ifdef UNICODE
      CreateFile equ <CreateFileW>
    else
      CreateFile equ <CreateFileA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, DefineDosDeviceW, WIN_STD_CALL_CONV,, <:DWORD, :LPCWSTR, :LPCWSTR>, 12
    ifdef UNICODE
      DefineDosDevice equ <DefineDosDeviceW>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, DeleteFileA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
    @DefProto DllImport, DeleteFileW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
    ifdef UNICODE
      DeleteFile equ <DeleteFileW>
    else
      DeleteFile equ <DeleteFileA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, DeleteVolumeMountPointW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
    ifdef UNICODE
      DeleteVolumeMountPoint equ <DeleteVolumeMountPointW>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, FileTimeToLocalFileTime, WIN_STD_CALL_CONV,, <:ptr FILETIME, :LPFILETIME>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, FindClose, WIN_STD_CALL_CONV,, <:HANDLE>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, FindCloseChangeNotification, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    @DefProto DllImport, FindFirstChangeNotificationA, WIN_STD_CALL_CONV,, <:LPCSTR, :BOOL, :DWORD>, 12
    @DefProto DllImport, FindFirstChangeNotificationW, WIN_STD_CALL_CONV,, <:LPCWSTR, :BOOL, :DWORD>, 12
    ifdef UNICODE
      FindFirstChangeNotification equ <FindFirstChangeNotificationW>
    else
      FindFirstChangeNotification equ <FindFirstChangeNotificationA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, FindFirstFileA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPWIN32_FIND_DATAA>, 8
    @DefProto DllImport, FindFirstFileW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPWIN32_FIND_DATAW>, 8
    ifdef UNICODE
      FindFirstFile equ <FindFirstFileW>
    else
      FindFirstFile equ <FindFirstFileA>
    endif
    if (_WIN32_WINNT ge 0400h)
      @DefProto DllImport, FindFirstFileExA, WIN_STD_CALL_CONV,, <:LPCSTR, :FINDEX_INFO_LEVELS, :LPVOID, :FINDEX_SEARCH_OPS, :LPVOID, :DWORD>, 24
      @DefProto DllImport, FindFirstFileExW, WIN_STD_CALL_CONV,, <:LPCWSTR, :FINDEX_INFO_LEVELS, :LPVOID, :FINDEX_SEARCH_OPS, :LPVOID, :DWORD>, 24
      ifdef UNICODE
        FindFirstFileEx equ <FindFirstFileExW>
      else
        FindFirstFileEx equ <FindFirstFileExA>
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, FindFirstVolumeW, WIN_STD_CALL_CONV,, <:LPWSTR, :DWORD>, 8
    ifdef UNICODE
      FindFirstVolume equ <FindFirstVolumeW>
    endif
    @DefProto DllImport, FindNextChangeNotification, WIN_STD_CALL_CONV,, <:HANDLE>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, FindNextFileA, WIN_STD_CALL_CONV,, <:HANDLE, :LPWIN32_FIND_DATAA>, 8
    @DefProto DllImport, FindNextFileW, WIN_STD_CALL_CONV,, <:HANDLE, :LPWIN32_FIND_DATAW>, 8
    ifdef UNICODE
      FindNextFile equ <FindNextFileW>
    else
      FindNextFile equ <FindNextFileA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, FindNextVolumeW, WIN_STD_CALL_CONV,, <:HANDLE, :LPWSTR, :DWORD>, 12
    ifdef UNICODE
      FindNextVolume equ <FindNextVolumeW>
    endif
    @DefProto DllImport, FindVolumeClose, WIN_STD_CALL_CONV,, <:HANDLE>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, FlushFileBuffers, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    @DefProto DllImport, GetDiskFreeSpaceA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD>, 20
    @DefProto DllImport, GetDiskFreeSpaceW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD>, 20
    ifdef UNICODE
      GetDiskFreeSpace equ <GetDiskFreeSpaceW>
    else
      GetDiskFreeSpace equ <GetDiskFreeSpaceA>
    endif
    @DefProto DllImport, GetDiskFreeSpaceExA, WIN_STD_CALL_CONV,, <:LPCSTR, :PULARGE_INTEGER, :PULARGE_INTEGER, :PULARGE_INTEGER>, 16
    @DefProto DllImport, GetDiskFreeSpaceExW, WIN_STD_CALL_CONV,, <:LPCWSTR, :PULARGE_INTEGER, :PULARGE_INTEGER, :PULARGE_INTEGER>, 16
    ifdef UNICODE
      GetDiskFreeSpaceEx equ <GetDiskFreeSpaceExW>
    else
      GetDiskFreeSpaceEx equ <GetDiskFreeSpaceExA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    DISK_SPACE_INFORMATION struct
      ActualTotalAllocationUnits ULONGLONG ?
      ActualAvailableAllocationUnits ULONGLONG ?
      ActualPoolUnavailableAllocationUnits ULONGLONG ?
      CallerTotalAllocationUnits ULONGLONG ?
      CallerAvailableAllocationUnits ULONGLONG ?
      CallerPoolUnavailableAllocationUnits ULONGLONG ?
      UsedAllocationUnits ULONGLONG ?
      TotalReservedAllocationUnits ULONGLONG ?
      VolumeStorageReserveAllocationUnits ULONGLONG ?
      AvailableCommittedAllocationUnits ULONGLONG ?
      PoolAvailableAllocationUnits ULONGLONG ?
      SectorsPerAllocationUnit DWORD ?
      BytesPerSector DWORD ?
    DISK_SPACE_INFORMATION ends
    @DefProto DllImport, GetDiskSpaceInformationA, WIN_STD_CALL_CONV,, <:LPCSTR, :ptr DISK_SPACE_INFORMATION>, 8
    @DefProto DllImport, GetDiskSpaceInformationW, WIN_STD_CALL_CONV,, <:LPCWSTR, :ptr DISK_SPACE_INFORMATION>, 8
    ifdef UNICODE
      GetDiskSpaceInformation equ <GetDiskSpaceInformationW>
    else
      GetDiskSpaceInformation equ <GetDiskSpaceInformationA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, GetDriveTypeA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
    @DefProto DllImport, GetDriveTypeW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
    ifdef UNICODE
      GetDriveType equ <GetDriveTypeW>
    else
      GetDriveType equ <GetDriveTypeA>
    endif
    WIN32_FILE_ATTRIBUTE_DATA struct
      dwFileAttributes DWORD ?
      ftCreationTime FILETIME <>
      ftLastAccessTime FILETIME <>
      ftLastWriteTime FILETIME <>
      nFileSizeHigh DWORD ?
      nFileSizeLow DWORD ?
    WIN32_FILE_ATTRIBUTE_DATA ends
    _WIN32_FILE_ATTRIBUTE_DATA typedef WIN32_FILE_ATTRIBUTE_DATA
    LPWIN32_FILE_ATTRIBUTE_DATA typedef ptr WIN32_FILE_ATTRIBUTE_DATA
    @DefProto DllImport, GetFileAttributesA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
    @DefProto DllImport, GetFileAttributesW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
    ifdef UNICODE
      GetFileAttributes equ <GetFileAttributesW>
    else
      GetFileAttributes equ <GetFileAttributesA>
    endif
    @DefProto DllImport, GetFileAttributesExA, WIN_STD_CALL_CONV,, <:LPCSTR, :GET_FILEEX_INFO_LEVELS, :LPVOID>, 12
    @DefProto DllImport, GetFileAttributesExW, WIN_STD_CALL_CONV,, <:LPCWSTR, :GET_FILEEX_INFO_LEVELS, :LPVOID>, 12
    ifdef UNICODE
      GetFileAttributesEx equ <GetFileAttributesExW>
    else
      GetFileAttributesEx equ <GetFileAttributesExA>
    endif
    BY_HANDLE_FILE_INFORMATION struct
      dwFileAttributes DWORD ?
      ftCreationTime FILETIME <>
      ftLastAccessTime FILETIME <>
      ftLastWriteTime FILETIME <>
      dwVolumeSerialNumber DWORD ?
      nFileSizeHigh DWORD ?
      nFileSizeLow DWORD ?
      nNumberOfLinks DWORD ?
      nFileIndexHigh DWORD ?
      nFileIndexLow DWORD ?
    BY_HANDLE_FILE_INFORMATION ends
    _BY_HANDLE_FILE_INFORMATION typedef BY_HANDLE_FILE_INFORMATION
    PBY_HANDLE_FILE_INFORMATION typedef ptr BY_HANDLE_FILE_INFORMATION
    LPBY_HANDLE_FILE_INFORMATION typedef ptr BY_HANDLE_FILE_INFORMATION
    @DefProto DllImport, GetFileInformationByHandle, WIN_STD_CALL_CONV,, <:HANDLE, :LPBY_HANDLE_FILE_INFORMATION>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, GetFileSize, WIN_STD_CALL_CONV,, <:HANDLE, :LPDWORD>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, GetFileSizeEx, WIN_STD_CALL_CONV,, <:HANDLE, :PLARGE_INTEGER>, 8
    @DefProto DllImport, GetFileType, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, GetFinalPathNameByHandleA, WIN_STD_CALL_CONV,, <:HANDLE, :LPSTR, :DWORD, :DWORD>, 16
      @DefProto DllImport, GetFinalPathNameByHandleW, WIN_STD_CALL_CONV,, <:HANDLE, :LPWSTR, :DWORD, :DWORD>, 16
      ifdef UNICODE
        GetFinalPathNameByHandle equ <GetFinalPathNameByHandleW>
      else
        GetFinalPathNameByHandle equ <GetFinalPathNameByHandleA>
      endif
    endif
    @DefProto DllImport, GetFileTime, WIN_STD_CALL_CONV,, <:HANDLE, :LPFILETIME, :LPFILETIME, :LPFILETIME>, 16
    @DefProto DllImport, GetFullPathNameW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :LPWSTR, :ptr LPWSTR>, 16
    ifdef UNICODE
      GetFullPathName equ <GetFullPathNameW>
    endif
    @DefProto DllImport, GetFullPathNameA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :LPSTR, :ptr LPSTR>, 16
    ifndef UNICODE
      GetFullPathName equ <GetFullPathNameA>
    endif
    @DefProto DllImport, GetLogicalDrives, WIN_STD_CALL_CONV,, <>, 0
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetLogicalDriveStringsW, WIN_STD_CALL_CONV,, <:DWORD, :LPWSTR>, 8
    ifdef UNICODE
      GetLogicalDriveStrings equ <GetLogicalDriveStringsW>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetLongPathNameA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPSTR, :DWORD>, 12
    ifndef UNICODE
      GetLongPathName equ <GetLongPathNameA>
    endif
    @DefProto DllImport, GetLongPathNameW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPWSTR, :DWORD>, 12
    ifdef UNICODE
      GetLongPathName equ <GetLongPathNameW>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (NTDDI_VERSION ge NTDDI_WIN10_FE)
      @DefProto DllImport, AreShortNamesEnabled, WIN_STD_CALL_CONV,, <:HANDLE, :ptr BOOL>, 8
    endif
    @DefProto DllImport, GetShortPathNameW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPWSTR, :DWORD>, 12
    ifdef UNICODE
      GetShortPathName equ <GetShortPathNameW>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetTempFileNameW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :UINT, :LPWSTR>, 16
    ifdef UNICODE
      GetTempFileName equ <GetTempFileNameW>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, GetVolumeInformationByHandleW, WIN_STD_CALL_CONV,, <:HANDLE, :LPWSTR, :DWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPWSTR, :DWORD>, 32
    endif
    @DefProto DllImport, GetVolumeInformationW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPWSTR, :DWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPWSTR, :DWORD>, 32
    ifdef UNICODE
      GetVolumeInformation equ <GetVolumeInformationW>
    endif
    @DefProto DllImport, GetVolumePathNameW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPWSTR, :DWORD>, 12
    ifdef UNICODE
      GetVolumePathName equ <GetVolumePathNameW>
    endif
    @DefProto DllImport, LocalFileTimeToFileTime, WIN_STD_CALL_CONV,, <:ptr FILETIME, :LPFILETIME>, 8
    @DefProto DllImport, LockFile, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :DWORD, :DWORD, :DWORD>, 20
    @DefProto DllImport, LockFileEx, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :DWORD, :DWORD, :DWORD, :LPOVERLAPPED>, 24
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, QueryDosDeviceW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPWSTR, :DWORD>, 12
    ifdef UNICODE
      QueryDosDevice equ <QueryDosDeviceW>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, ReadFile, WIN_STD_CALL_CONV,, <:HANDLE, :LPVOID, :DWORD, :LPDWORD, :LPOVERLAPPED>, 20
    @DefProto DllImport, ReadFileEx, WIN_STD_CALL_CONV,, <:HANDLE, :LPVOID, :DWORD, :LPOVERLAPPED, :LPOVERLAPPED_COMPLETION_ROUTINE>, 20
    @DefProto DllImport, ReadFileScatter, WIN_STD_CALL_CONV,, <:HANDLE, :ptr FILE_SEGMENT_ELEMENT, :DWORD, :LPDWORD, :LPOVERLAPPED>, 20
    @DefProto DllImport, RemoveDirectoryA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
    @DefProto DllImport, RemoveDirectoryW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
    ifdef UNICODE
      RemoveDirectory equ <RemoveDirectoryW>
    else
      RemoveDirectory equ <RemoveDirectoryA>
    endif
    @DefProto DllImport, SetEndOfFile, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    @DefProto DllImport, SetFileAttributesA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD>, 8
    @DefProto DllImport, SetFileAttributesW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD>, 8
    ifdef UNICODE
      SetFileAttributes equ <SetFileAttributesW>
    else
      SetFileAttributes equ <SetFileAttributesA>
    endif
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, SetFileInformationByHandle, WIN_STD_CALL_CONV,, <:HANDLE, :FILE_INFO_BY_HANDLE_CLASS, :LPVOID, :DWORD>, 16
    endif
    @DefProto DllImport, SetFilePointer, WIN_STD_CALL_CONV,, <:HANDLE, :LONG, :PLONG, :DWORD>, 16
    @DefProto DllImport, SetFilePointerEx, WIN_STD_CALL_CONV,, <:HANDLE, :LARGE_INTEGER, :PLARGE_INTEGER, :DWORD>, 20
    @DefProto DllImport, SetFileTime, WIN_STD_CALL_CONV,, <:HANDLE, :ptr FILETIME, :ptr FILETIME, :ptr FILETIME>, 16
    if _WIN32_WINNT ge 0501h
      @DefProto DllImport, SetFileValidData, WIN_STD_CALL_CONV,, <:HANDLE, :LONGLONG>, 8
    endif
    @DefProto DllImport, UnlockFile, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :DWORD, :DWORD, :DWORD>, 20
    @DefProto DllImport, UnlockFileEx, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :DWORD, :DWORD, :LPOVERLAPPED>, 20
    @DefProto DllImport, WriteFile, WIN_STD_CALL_CONV,, <:HANDLE, :LPCVOID, :DWORD, :LPDWORD, :LPOVERLAPPED>, 20
    @DefProto DllImport, WriteFileEx, WIN_STD_CALL_CONV,, <:HANDLE, :LPCVOID, :DWORD, :LPOVERLAPPED, :LPOVERLAPPED_COMPLETION_ROUTINE>, 20
    @DefProto DllImport, WriteFileGather, WIN_STD_CALL_CONV,, <:HANDLE, :ptr FILE_SEGMENT_ELEMENT, :DWORD, :LPDWORD, :LPOVERLAPPED>, 20
    @DefProto DllImport, GetTempPathW, WIN_STD_CALL_CONV,, <:DWORD, :LPWSTR>, 8
    ifdef UNICODE
      GetTempPath equ <GetTempPathW>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetVolumeNameForVolumeMountPointW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPWSTR, :DWORD>, 12
    ifdef UNICODE
      GetVolumeNameForVolumeMountPoint equ <GetVolumeNameForVolumeMountPointW>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge 0501h)
      @DefProto DllImport, GetVolumePathNamesForVolumeNameW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPWCH, :DWORD, :PDWORD>, 16
      ifdef UNICODE
        GetVolumePathNamesForVolumeName equ <GetVolumePathNamesForVolumeNameW>
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    if (_WIN32_WINNT ge 0602h)
      CREATEFILE2_EXTENDED_PARAMETERS struct
        dwSize DWORD ?
        dwFileAttributes DWORD ?
        dwFileFlags DWORD ?
        dwSecurityQosFlags DWORD ?
        lpSecurityAttributes LPSECURITY_ATTRIBUTES ?
        hTemplateFile HANDLE ?
      CREATEFILE2_EXTENDED_PARAMETERS ends
      _CREATEFILE2_EXTENDED_PARAMETERS typedef CREATEFILE2_EXTENDED_PARAMETERS
      PCREATEFILE2_EXTENDED_PARAMETERS typedef ptr CREATEFILE2_EXTENDED_PARAMETERS
      LPCREATEFILE2_EXTENDED_PARAMETERS typedef ptr CREATEFILE2_EXTENDED_PARAMETERS
      @DefProto DllImport, CreateFile2, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :DWORD, :DWORD, :LPCREATEFILE2_EXTENDED_PARAMETERS>, 20
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, SetFileIoOverlappedRange, WIN_STD_CALL_CONV,, <:HANDLE, :PUCHAR, :ULONG>, 12
    endif
    if _WIN32_WINNT ge 0501h
      @DefProto DllImport, GetCompressedFileSizeA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPDWORD>, 8
      @DefProto DllImport, GetCompressedFileSizeW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPDWORD>, 8
      ifdef UNICODE
        GetCompressedFileSize equ <GetCompressedFileSizeW>
      else
        GetCompressedFileSize equ <GetCompressedFileSizeA>
      endif
    endif
    if (_WIN32_WINNT ge 0501h)
      STREAM_INFO_LEVELS typedef SDWORD
      FindStreamInfoStandard equ 0
      FindStreamInfoMaxInfoLevel equ 1
      _STREAM_INFO_LEVELS typedef STREAM_INFO_LEVELS

      WIN32_FIND_STREAM_DATA struct
        StreamSize LARGE_INTEGER <>
        cStreamName WCHAR MAX_PATH + 36 dup (?)
      WIN32_FIND_STREAM_DATA ends
      _WIN32_FIND_STREAM_DATA typedef WIN32_FIND_STREAM_DATA
      PWIN32_FIND_STREAM_DATA typedef ptr WIN32_FIND_STREAM_DATA
      @DefProto DllImport, FindFirstStreamW, WIN_STD_CALL_CONV,, <:LPCWSTR, :STREAM_INFO_LEVELS, :LPVOID, :DWORD>, 16
      @DefProto DllImport, FindNextStreamW, WIN_STD_CALL_CONV,, <:HANDLE, :LPVOID>, 8
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, AreFileApisANSI, WIN_STD_CALL_CONV,, <>, 0
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, GetTempPathA, WIN_STD_CALL_CONV,, <:DWORD, :LPSTR>, 8
    ifndef UNICODE
      GetTempPath equ <GetTempPathA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if _WIN32_WINNT ge 0600h
      @DefProto DllImport, FindFirstFileNameW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :LPDWORD, :PWSTR>, 16
      @DefProto DllImport, FindNextFileNameW, WIN_STD_CALL_CONV,, <:HANDLE, :LPDWORD, :PWSTR>, 12
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, GetVolumeInformationA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPSTR, :DWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPSTR, :DWORD>, 32
    ifndef UNICODE
      GetVolumeInformation equ <GetVolumeInformationA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetTempFileNameA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :UINT, :LPSTR>, 16
    ifndef UNICODE
      GetTempFileName equ <GetTempFileNameA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, SetFileApisToOEM, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, SetFileApisToANSI, WIN_STD_CALL_CONV,, <>, 0
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    if (NTDDI_VERSION ge NTDDI_WIN10_FE)
      @DefProto DllImport, GetTempPath2W, WIN_STD_CALL_CONV,, <:DWORD, :LPWSTR>, 8
      ifdef UNICODE
        GetTempPath2 equ <GetTempPath2W>
      endif
      @DefProto DllImport, GetTempPath2A, WIN_STD_CALL_CONV,, <:DWORD, :LPSTR>, 8
      ifndef UNICODE
        GetTempPath2 equ <GetTempPath2A>
      endif
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
