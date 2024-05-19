;Include file created by h2inc+ version C.2.0 on (UTC) 19/05/2024 07:52:23
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\fileapifromapp.h\fileapifromapp.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 21/02/2024 18:13:22

ifndef _FILEAPIFROMAPP_H_
  _FILEAPIFROMAPP_H_ equ <>
  ifdef _MSC_VER
  endif
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  include minwinbase.inc
  include fileapi.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
    if ((_WIN32_WINNT ge _WIN32_WINNT_WIN10) and (NTDDI_VERSION ge NTDDI_WIN10_RS3))
      CopyFileFromAppW proto WIN_STD_CALL_CONV :LPCWSTR, :LPCWSTR, :BOOL
      if Defined(__cplusplus) and _MSC_VER ge 1900
        ;[...]
      endif
      CreateDirectoryFromAppW proto WIN_STD_CALL_CONV :LPCWSTR, :LPSECURITY_ATTRIBUTES
      if Defined(__cplusplus) and _MSC_VER ge 1900
        ;[...]
      endif
      CreateFileFromAppW proto WIN_STD_CALL_CONV :LPCWSTR, :DWORD, :DWORD, :LPSECURITY_ATTRIBUTES, :DWORD, :DWORD, :HANDLE
      if Defined(__cplusplus) and _MSC_VER ge 1900
        ;[...]
      endif
      CreateFile2FromAppW proto WIN_STD_CALL_CONV :LPCWSTR, :DWORD, :DWORD, :DWORD, :LPCREATEFILE2_EXTENDED_PARAMETERS
      if Defined(__cplusplus) and _MSC_VER ge 1900
        ;[...]
      endif
      DeleteFileFromAppW proto WIN_STD_CALL_CONV :LPCWSTR
      if Defined(__cplusplus) and _MSC_VER ge 1900
        ;[...]
      endif
      FindFirstFileExFromAppW proto WIN_STD_CALL_CONV :LPCWSTR, :FINDEX_INFO_LEVELS, :LPVOID, :FINDEX_SEARCH_OPS, :LPVOID, :DWORD
      if Defined(__cplusplus) and _MSC_VER ge 1900
        ;[...]
      endif
      GetFileAttributesExFromAppW proto WIN_STD_CALL_CONV :LPCWSTR, :GET_FILEEX_INFO_LEVELS, :LPVOID
      if Defined(__cplusplus) and _MSC_VER ge 1900
        ;[...]
      endif
      MoveFileFromAppW proto WIN_STD_CALL_CONV :LPCWSTR, :LPCWSTR
      if Defined(__cplusplus) and _MSC_VER ge 1900
        ;[...]
      endif
      RemoveDirectoryFromAppW proto WIN_STD_CALL_CONV :LPCWSTR
      if Defined(__cplusplus) and _MSC_VER ge 1900
        ;[...]
      endif
      ReplaceFileFromAppW proto WIN_STD_CALL_CONV :LPCWSTR, :LPCWSTR, :LPCWSTR, :DWORD, :LPVOID, :LPVOID
      if Defined(__cplusplus) and _MSC_VER ge 1900
        ;[...]
      endif
      SetFileAttributesFromAppW proto WIN_STD_CALL_CONV :LPCWSTR, :DWORD
      if Defined(__cplusplus) and _MSC_VER ge 1900
        ;[...]
      endif
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
