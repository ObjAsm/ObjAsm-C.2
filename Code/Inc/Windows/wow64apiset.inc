;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\wow64apiset.h', last modified: 19/04/2018 10:43
;Creation parameters: 

ifdef _MSC_VER
endif
ifndef _WOW64APISET_H_
  _WOW64APISET_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  include minwinbase.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if  not Defined(RC_INVOKED)
      if _WIN32_WINNT ge 0501h or Defined(WINBASE_DECLARE_GET_SYSTEM_WOW64_DIRECTORY)
        @DefProto DllImport, Wow64DisableWow64FsRedirection, WIN_STD_CALL_CONV,, <:ptr PVOID>, 4
        @DefProto DllImport, Wow64RevertWow64FsRedirection, WIN_STD_CALL_CONV,, <:PVOID>, 4
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge 0501h)
      @DefProto DllImport, IsWow64Process, WIN_STD_CALL_CONV,, <:HANDLE, :PBOOL>, 8
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if  not Defined(RC_INVOKED)
      if _WIN32_WINNT ge 0501h or Defined(WINBASE_DECLARE_GET_SYSTEM_WOW64_DIRECTORY)
        @DefProto DllImport, GetSystemWow64DirectoryA, WIN_STD_CALL_CONV,, <:LPSTR, :UINT>, 8
        @DefProto DllImport, GetSystemWow64DirectoryW, WIN_STD_CALL_CONV,, <:LPWSTR, :UINT>, 8
        ifdef UNICODE
          GetSystemWow64Directory equ <GetSystemWow64DirectoryW>
        else
          GetSystemWow64Directory equ <GetSystemWow64DirectoryA>
        endif
      endif
    endif
    if (_WIN32_WINNT ge 0A00h)
      @DefProto DllImport, Wow64SetThreadDefaultGuestMachine, WIN_STD_CALL_CONV,, <:USHORT>, 4
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge 0A00h)
      @DefProto DllImport, IsWow64Process2, WIN_STD_CALL_CONV,, <:HANDLE, :ptr USHORT, :ptr USHORT>, 12
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge 0A00h)
      @DefProto DllImport, GetSystemWow64Directory2A, WIN_STD_CALL_CONV,, <:LPSTR, :UINT, :WORD>, 12
      @DefProto DllImport, GetSystemWow64Directory2W, WIN_STD_CALL_CONV,, <:LPWSTR, :UINT, :WORD>, 12
      ifdef UNICODE
        GetSystemWow64Directory2 equ <GetSystemWow64Directory2W>
      else
        GetSystemWow64Directory2 equ <GetSystemWow64Directory2A>
      endif
    endif
    if (_WIN32_WINNT ge 0A00h)
      @DefProto DllImport, IsWow64GuestMachineSupported, WIN_STD_CALL_CONV,, <:USHORT, :ptr BOOL>, 8
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

