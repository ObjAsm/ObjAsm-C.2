;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\stringapiset.h', last modified: 19/04/2018 10:43
;Creation parameters: 

ifdef _MSC_VER
endif
ifndef _APISETSTRING_
  _APISETSTRING_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  include winnls.inc
  ifdef __cplusplus
    ;[...]
  endif
  if (WINVER ge 0600h)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, CompareStringEx, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :LPCWCH, :SDWORD, :LPCWCH, :SDWORD, :LPNLSVERSIONINFO, :LPVOID, :LPARAM>, 36
      @DefProto DllImport, CompareStringOrdinal, WIN_STD_CALL_CONV,, <:LPCWCH, :SDWORD, :LPCWCH, :SDWORD, :BOOL>, 20
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, CompareStringW, WIN_STD_CALL_CONV,, <:LCID, :DWORD, :PCNZWCH, :SDWORD, :PCNZWCH, :SDWORD>, 24
    ifdef UNICODE
      CompareString equ <CompareStringW>
    endif
    @DefProto DllImport, FoldStringW, WIN_STD_CALL_CONV,, <:DWORD, :LPCWCH, :SDWORD, :LPWSTR, :SDWORD>, 20
    ifdef UNICODE
      FoldString equ <FoldStringW>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetStringTypeExW, WIN_STD_CALL_CONV,, <:LCID, :DWORD, :LPCWCH, :SDWORD, :LPWORD>, 20
    ifdef UNICODE
      GetStringTypeEx equ <GetStringTypeExW>
    endif
    @DefProto DllImport, GetStringTypeW, WIN_STD_CALL_CONV,, <:DWORD, :LPCWCH, :SDWORD, :LPWORD>, 16
    @DefProto DllImport, MultiByteToWideChar, WIN_STD_CALL_CONV,, <:UINT, :DWORD, :LPCCH, :SDWORD, :LPWSTR, :SDWORD>, 24
    @DefProto DllImport, WideCharToMultiByte, WIN_STD_CALL_CONV,, <:UINT, :DWORD, :LPCWCH, :SDWORD, :LPSTR, :SDWORD, :LPCCH, :LPBOOL>, 32
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

