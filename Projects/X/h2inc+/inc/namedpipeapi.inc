;Include file created by h2inc+ version C.2.0 on (UTC) 26/05/2024 13:31:25
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\namedpipeapi.h
;             Created on (UTC) 06/04/2024 06:15:57
;             Last modified on (UTC) 21/02/2024 18:13:16

ifdef _MSC_VER
endif
ifndef _NAMEDPIPE_H_
  _NAMEDPIPE_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  include minwinbase.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, CreatePipe, WIN_STD_CALL_CONV,, <:PHANDLE, :PHANDLE, :LPSECURITY_ATTRIBUTES, :DWORD>, 16
    @DefProto DllImport, ConnectNamedPipe, WIN_STD_CALL_CONV,, <:HANDLE, :LPOVERLAPPED>, 8
    @DefProto DllImport, DisconnectNamedPipe, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    @DefProto DllImport, SetNamedPipeHandleState, WIN_STD_CALL_CONV,, <:HANDLE, :LPDWORD, :LPDWORD, :LPDWORD>, 16
    @DefProto DllImport, PeekNamedPipe, WIN_STD_CALL_CONV,, <:HANDLE, :LPVOID, :DWORD, :LPDWORD, :LPDWORD, :LPDWORD>, 24
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, TransactNamedPipe, WIN_STD_CALL_CONV,, <:HANDLE, :LPVOID, :DWORD, :LPVOID, :DWORD, :LPDWORD, :LPOVERLAPPED>, 28
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, CreateNamedPipeW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :LPSECURITY_ATTRIBUTES>, 32
    ifdef UNICODE
      CreateNamedPipe equ <CreateNamedPipeW>
    endif
    @DefProto DllImport, WaitNamedPipeW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD>, 8
    ifdef UNICODE
      WaitNamedPipe equ <WaitNamedPipeW>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, GetNamedPipeClientComputerNameW, WIN_STD_CALL_CONV,, <:HANDLE, :LPWSTR, :ULONG>, 12
    endif
    ifdef UNICODE
      GetNamedPipeClientComputerName equ <GetNamedPipeClientComputerNameW>
    endif
    @DefProto DllImport, ImpersonateNamedPipeClient, WIN_STD_CALL_CONV,, <:HANDLE>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetNamedPipeInfo, WIN_STD_CALL_CONV,, <:HANDLE, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD>, 20
    @DefProto DllImport, GetNamedPipeHandleStateW, WIN_STD_CALL_CONV,, <:HANDLE, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPWSTR, :DWORD>, 28
    ifdef UNICODE
      GetNamedPipeHandleState equ <GetNamedPipeHandleStateW>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, CallNamedPipeW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPVOID, :DWORD, :LPVOID, :DWORD, :LPDWORD, :DWORD>, 28
    ifdef UNICODE
      CallNamedPipe equ <CallNamedPipeW>
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
