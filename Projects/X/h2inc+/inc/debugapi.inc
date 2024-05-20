;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\debugapi.h
;             Created on (UTC) 06/04/2024 06:15:53
;             Last modified on (UTC) 21/02/2024 18:13:14

;********************************************************************************
ifdef _MSC_VER
endif
; _MSC_VER
ifndef _APISETDEBUG_
  _APISETDEBUG_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  include minwinbase.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    if (_WIN32_WINNT ge 0400h) or (_WIN32_WINDOWS gt 0400h)
      @DefProto DllImport, IsDebuggerPresent, WIN_STD_CALL_CONV,, <>, 0
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, DebugBreak, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, OutputDebugStringA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
    @DefProto DllImport, OutputDebugStringW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
    ifdef UNICODE
      OutputDebugString equ <OutputDebugStringW>
    else
      OutputDebugString equ <OutputDebugStringA>
    endif
    ; !UNICODE
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, ContinueDebugEvent, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :DWORD>, 12
    @DefProto DllImport, WaitForDebugEvent, WIN_STD_CALL_CONV,, <:LPDEBUG_EVENT, :DWORD>, 8
    @DefProto DllImport, DebugActiveProcess, WIN_STD_CALL_CONV,, <:DWORD>, 4
    @DefProto DllImport, DebugActiveProcessStop, WIN_STD_CALL_CONV,, <:DWORD>, 4
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge 0501h)
      @DefProto DllImport, CheckRemoteDebuggerPresent, WIN_STD_CALL_CONV,, <:HANDLE, :PBOOL>, 8
    endif
    ; (_WIN32_WINNT >= 0x0501)
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, WaitForDebugEventEx, WIN_STD_CALL_CONV,, <:LPDEBUG_EVENT, :DWORD>, 8
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
; _APISETDEBUG_
