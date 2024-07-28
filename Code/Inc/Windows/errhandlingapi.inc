;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\errhandlingapi.h', last modified: 19/04/2018 10:43
;Creation parameters: 

ifdef _MSC_VER
endif
ifndef _ERRHANDLING_H_
  _ERRHANDLING_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    TYPE_PTOP_LEVEL_EXCEPTION_FILTER typedef proto WIN_STD_CALL_CONV :ptr _EXCEPTION_POINTERS
    PTOP_LEVEL_EXCEPTION_FILTER typedef ptr TYPE_PTOP_LEVEL_EXCEPTION_FILTER
    LPTOP_LEVEL_EXCEPTION_FILTER typedef PTOP_LEVEL_EXCEPTION_FILTER
    @DefProto DllImport, RaiseException, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :DWORD, :ptr ULONG_PTR>, 16
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, UnhandledExceptionFilter, WIN_STD_CALL_CONV,, <:ptr _EXCEPTION_POINTERS>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, SetUnhandledExceptionFilter, WIN_STD_CALL_CONV,, <:LPTOP_LEVEL_EXCEPTION_FILTER>, 4
    ifndef _M_CEE_PURE
      @DefProto DllImport, GetLastError, WIN_STD_CALL_CONV,, <>, 0
    endif
    @DefProto DllImport, SetLastError, WIN_STD_CALL_CONV,, <:DWORD>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, GetErrorMode, WIN_STD_CALL_CONV,, <>, 0
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, SetErrorMode, WIN_STD_CALL_CONV,, <:UINT>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (_WIN32_WINNT ge 0501h)
      @DefProto DllImport, AddVectoredExceptionHandler, WIN_STD_CALL_CONV,, <:ULONG, :PVECTORED_EXCEPTION_HANDLER>, 8
      @DefProto DllImport, RemoveVectoredExceptionHandler, WIN_STD_CALL_CONV,, <:PVOID>, 4
      @DefProto DllImport, AddVectoredContinueHandler, WIN_STD_CALL_CONV,, <:ULONG, :PVECTORED_EXCEPTION_HANDLER>, 8
      @DefProto DllImport, RemoveVectoredContinueHandler, WIN_STD_CALL_CONV,, <:PVOID>, 4
    endif
    if  not Defined(RC_INVOKED)
      if Defined(WINBASE_DECLARE_RESTORE_LAST_ERROR)
        @DefProto DllImport, RestoreLastError, WIN_STD_CALL_CONV,, <:DWORD>, 4
        TYPE_PRESTORE_LAST_ERROR typedef proto WIN_STD_CALL_CONV :DWORD
        PRESTORE_LAST_ERROR typedef ptr TYPE_PRESTORE_LAST_ERROR
        RESTORE_LAST_ERROR_NAME_A equ <"RestoreLastError">
        RESTORE_LAST_ERROR_NAME_W equ <L("RestoreLastError")>
        RESTORE_LAST_ERROR_NAME equ <TEXT("RestoreLastError")>
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, RaiseFailFastException, WIN_STD_CALL_CONV,, <:PEXCEPTION_RECORD, :PCONTEXT, :DWORD>, 12
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, FatalAppExitA, WIN_STD_CALL_CONV,, <:UINT, :LPCSTR>, 8
    @DefProto DllImport, FatalAppExitW, WIN_STD_CALL_CONV,, <:UINT, :LPCWSTR>, 8
    ifdef UNICODE
      FatalAppExit equ <FatalAppExitW>
    else
      FatalAppExit equ <FatalAppExitA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetThreadErrorMode, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, SetThreadErrorMode, WIN_STD_CALL_CONV,, <:DWORD, :LPDWORD>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, TerminateProcessOnMemoryExhaustion, WIN_STD_CALL_CONV,, <:SIZE_T>, 4
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

