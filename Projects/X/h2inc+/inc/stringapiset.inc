;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\stringapiset.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 21/02/2024 18:13:16

;********************************************************************************
ifdef _MSC_VER
endif
; _MSC_VER
ifndef _APISETSTRING_
  _APISETSTRING_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  include winnls.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_APP or WINAPI_PARTITION_GAMES)
    if (WINVER ge 0600h)
      @DefProto DllImport, CompareStringEx, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :LPCWCH, :SDWORD, :LPCWCH, :SDWORD, :LPNLSVERSIONINFO, :LPVOID, :LPARAM>, 36
      @DefProto DllImport, CompareStringOrdinal, WIN_STD_CALL_CONV,, <:LPCWCH, :SDWORD, :LPCWCH, :SDWORD, :BOOL>, 20
    endif
    ;(WINVER >= 0x0600)
    @DefProto DllImport, CompareStringW, WIN_STD_CALL_CONV,, <:LCID, :DWORD, :PCNZWCH, :SDWORD, :PCNZWCH, :SDWORD>, 24
    ifdef UNICODE
      CompareString equ <CompareStringW>
    endif
    @DefProto DllImport, FoldStringW, WIN_STD_CALL_CONV,, <:DWORD, :LPCWCH, :SDWORD, :LPWSTR, :SDWORD>, 20
    ifdef UNICODE
      FoldString equ <FoldStringW>
    endif
    @DefProto DllImport, GetStringTypeExW, WIN_STD_CALL_CONV,, <:LCID, :DWORD, :LPCWCH, :SDWORD, :LPWORD>, 20
    ifdef UNICODE
      GetStringTypeEx equ <GetStringTypeExW>
    endif
    @DefProto DllImport, GetStringTypeW, WIN_STD_CALL_CONV,, <:DWORD, :LPCWCH, :SDWORD, :LPWORD>, 16
    ;  NLS Code Page Dependent APIs.
    @DefProto DllImport, MultiByteToWideChar, WIN_STD_CALL_CONV,, <:UINT, :DWORD, :LPCCH, :SDWORD, :LPWSTR, :SDWORD>, 24
    @DefProto DllImport, WideCharToMultiByte, WIN_STD_CALL_CONV,, <:UINT, :DWORD, :LPCWCH, :SDWORD, :LPSTR, :SDWORD, :LPCCH, :LPBOOL>, 32
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_APP | WINAPI_PARTITION_GAMES) *
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
; _APISETSTRING_
