;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\ioapiset.h', last modified: 19/04/2018 10:43
;Creation parameters: 

ifdef _MSC_VER
endif
ifndef _IO_APISET_H_
  _IO_APISET_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  include minwinbase.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, CreateIoCompletionPort, WIN_STD_CALL_CONV,, <:HANDLE, :HANDLE, :ULONG_PTR, :DWORD>, 16
    @DefProto DllImport, GetQueuedCompletionStatus, WIN_STD_CALL_CONV,, <:HANDLE, :LPDWORD, :PULONG_PTR, :ptr LPOVERLAPPED, :DWORD>, 20
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, GetQueuedCompletionStatusEx, WIN_STD_CALL_CONV,, <:HANDLE, :LPOVERLAPPED_ENTRY, :ULONG, :PULONG, :DWORD, :BOOL>, 24
    endif
    @DefProto DllImport, PostQueuedCompletionStatus, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :ULONG_PTR, :LPOVERLAPPED>, 16
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, DeviceIoControl, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :LPVOID, :DWORD, :LPVOID, :DWORD, :LPDWORD, :LPOVERLAPPED>, 32
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetOverlappedResult, WIN_STD_CALL_CONV,, <:HANDLE, :LPOVERLAPPED, :LPDWORD, :BOOL>, 16
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, CancelIoEx, WIN_STD_CALL_CONV,, <:HANDLE, :LPOVERLAPPED>, 8
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, CancelIo, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    @DefProto DllImport, GetOverlappedResultEx, WIN_STD_CALL_CONV,, <:HANDLE, :LPOVERLAPPED, :LPDWORD, :DWORD, :BOOL>, 20
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, CancelSynchronousIo, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

