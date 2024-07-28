;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\debugapi.h', last modified: 19/04/2018 10:43
;Creation parameters: 

ifdef _MSC_VER
endif
ifndef _APISETDEBUG_
  _APISETDEBUG_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  include minwinbase.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge 0400h) or (_WIN32_WINDOWS gt 0400h)
      @DefProto DllImport, IsDebuggerPresent, WIN_STD_CALL_CONV,, <>, 0
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, DebugBreak, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, OutputDebugStringA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
    @DefProto DllImport, OutputDebugStringW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
    ifdef UNICODE
      OutputDebugString equ <OutputDebugStringW>
    else
      OutputDebugString equ <OutputDebugStringA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, ContinueDebugEvent, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :DWORD>, 12
    @DefProto DllImport, WaitForDebugEvent, WIN_STD_CALL_CONV,, <:LPDEBUG_EVENT, :DWORD>, 8
    @DefProto DllImport, DebugActiveProcess, WIN_STD_CALL_CONV,, <:DWORD>, 4
    @DefProto DllImport, DebugActiveProcessStop, WIN_STD_CALL_CONV,, <:DWORD>, 4
    if (_WIN32_WINNT ge 0501h)
      @DefProto DllImport, CheckRemoteDebuggerPresent, WIN_STD_CALL_CONV,, <:HANDLE, :PBOOL>, 8
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, WaitForDebugEventEx, WIN_STD_CALL_CONV,, <:LPDEBUG_EVENT, :DWORD>, 8
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

