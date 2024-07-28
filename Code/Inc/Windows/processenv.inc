;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\processenv.h', last modified: 19/04/2018 10:43
;Creation parameters: 

ifdef _MSC_VER
endif
ifndef _PROCESSENV_
  _PROCESSENV_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, SetEnvironmentStringsW, WIN_STD_CALL_CONV,, <:LPWCH>, 4
    ifdef UNICODE
      SetEnvironmentStrings equ <SetEnvironmentStringsW>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_PC_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetStdHandle, WIN_STD_CALL_CONV,, <:DWORD>, 4
    @DefProto DllImport, SetStdHandle, WIN_STD_CALL_CONV,, <:DWORD, :HANDLE>, 8
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, SetStdHandleEx, WIN_STD_CALL_CONV,, <:DWORD, :HANDLE, :PHANDLE>, 12
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetCommandLineA, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, GetCommandLineW, WIN_STD_CALL_CONV,, <>, 0
    ifdef UNICODE
      GetCommandLine equ <GetCommandLineW>
    else
      GetCommandLine equ <GetCommandLineA>
    endif
    @DefProto DllImport, GetEnvironmentStrings, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, GetEnvironmentStringsW, WIN_STD_CALL_CONV,, <>, 0
    ifdef UNICODE
      GetEnvironmentStrings equ <GetEnvironmentStringsW>
    else
      GetEnvironmentStringsA equ <GetEnvironmentStrings>
    endif
    @DefProto DllImport, FreeEnvironmentStringsA, WIN_STD_CALL_CONV,, <:LPCH>, 4
    @DefProto DllImport, FreeEnvironmentStringsW, WIN_STD_CALL_CONV,, <:LPWCH>, 4
    ifdef UNICODE
      FreeEnvironmentStrings equ <FreeEnvironmentStringsW>
    else
      FreeEnvironmentStrings equ <FreeEnvironmentStringsA>
    endif
    @DefProto DllImport, GetEnvironmentVariableA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPSTR, :DWORD>, 12
    @DefProto DllImport, GetEnvironmentVariableW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPWSTR, :DWORD>, 12
    ifdef UNICODE
      GetEnvironmentVariable equ <GetEnvironmentVariableW>
    else
      GetEnvironmentVariable equ <GetEnvironmentVariableA>
    endif
    @DefProto DllImport, SetEnvironmentVariableA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR>, 8
    @DefProto DllImport, SetEnvironmentVariableW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR>, 8
    ifdef UNICODE
      SetEnvironmentVariable equ <SetEnvironmentVariableW>
    else
      SetEnvironmentVariable equ <SetEnvironmentVariableA>
    endif
    @DefProto DllImport, ExpandEnvironmentStringsA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPSTR, :DWORD>, 12
    @DefProto DllImport, ExpandEnvironmentStringsW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPWSTR, :DWORD>, 12
    ifdef UNICODE
      ExpandEnvironmentStrings equ <ExpandEnvironmentStringsW>
    else
      ExpandEnvironmentStrings equ <ExpandEnvironmentStringsA>
    endif
    @DefProto DllImport, SetCurrentDirectoryA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
    @DefProto DllImport, SetCurrentDirectoryW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
    ifdef UNICODE
      SetCurrentDirectory equ <SetCurrentDirectoryW>
    else
      SetCurrentDirectory equ <SetCurrentDirectoryA>
    endif
    @DefProto DllImport, GetCurrentDirectoryA, WIN_STD_CALL_CONV,, <:DWORD, :LPSTR>, 8
    @DefProto DllImport, GetCurrentDirectoryW, WIN_STD_CALL_CONV,, <:DWORD, :LPWSTR>, 8
    ifdef UNICODE
      GetCurrentDirectory equ <GetCurrentDirectoryW>
    else
      GetCurrentDirectory equ <GetCurrentDirectoryA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, SearchPathW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPCWSTR, :DWORD, :LPWSTR, :ptr LPWSTR>, 24
    ifdef UNICODE
      SearchPath equ <SearchPathW>
    else
      SearchPath equ <SearchPathA>
    endif
    @DefProto DllImport, SearchPathA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :LPCSTR, :DWORD, :LPSTR, :ptr LPSTR>, 24
    if _WIN32_WINNT ge 0502h
      @DefProto DllImport, NeedCurrentDirectoryForExePathA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
      @DefProto DllImport, NeedCurrentDirectoryForExePathW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
      ifdef UNICODE
        NeedCurrentDirectoryForExePath equ <NeedCurrentDirectoryForExePathW>
      else
        NeedCurrentDirectoryForExePath equ <NeedCurrentDirectoryForExePathA>
      endif
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

