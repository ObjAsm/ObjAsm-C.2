;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\winver.h
;             Created on (UTC) 06/04/2024 06:16:03
;             Last modified on (UTC) 21/02/2024 18:17:28

include winapifamily.inc
;*****************************************************************************\
;*                                                                             *
;* winver.h -    Version management functions, types, and definitions          *
;*                                                                             *
;*               Include file for VER.DLL.  This library is                    *
;*               designed to allow version stamping of Windows executable files*
;*               and of special .VER files for DOS executable files.           *
;*                                                                             *
;*               Copyright (c) Microsoft Corporation. All rights reserved.     *
;*                                                                             *
;\*****************************************************************************
ifndef VER_H
  VER_H equ <>
  include SpecStrings.inc
  include verrsrc.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    ;* RC doesn't need to see the rest of this *
    ifndef RC_INVOKED
      ;* ----- Function prototypes ----- *
      VerFindFileA proto WIN_STD_CALL_CONV :DWORD, :LPCSTR, :LPCSTR, :LPCSTR, :LPSTR, :PUINT, :LPSTR, :PUINT
      VerFindFileW proto WIN_STD_CALL_CONV :DWORD, :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPWSTR, :PUINT, :LPWSTR, :PUINT
      ifdef UNICODE
        VerFindFile equ <VerFindFileW>
      else
        VerFindFile equ <VerFindFileA>
      endif
      ; !UNICODE
    endif
    ; RC_INVOKED
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef RC_INVOKED
      VerInstallFileA proto WIN_STD_CALL_CONV :DWORD, :LPCSTR, :LPCSTR, :LPCSTR, :LPCSTR, :LPCSTR, :LPSTR, :PUINT
      VerInstallFileW proto WIN_STD_CALL_CONV :DWORD, :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPWSTR, :PUINT
      ifdef UNICODE
        VerInstallFile equ <VerInstallFileW>
      else
        VerInstallFile equ <VerInstallFileA>
      endif
      ; !UNICODE
    endif
    ; RC_INVOKED
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    ifndef RC_INVOKED
      ;* Returns size of version info in bytes *
      GetFileVersionInfoSizeA proto WIN_STD_CALL_CONV :LPCSTR, :LPDWORD
      ;* Information for use by GetFileVersionInfo *
      ;* Returns size of version info in bytes *
      GetFileVersionInfoSizeW proto WIN_STD_CALL_CONV :LPCWSTR, :LPDWORD
      ;* Information for use by GetFileVersionInfo *
      ifdef UNICODE
        GetFileVersionInfoSize equ <GetFileVersionInfoSizeW>
      else
        GetFileVersionInfoSize equ <GetFileVersionInfoSizeA>
      endif
      ; !UNICODE
      ;* Read version info into buffer *
      GetFileVersionInfoA proto WIN_STD_CALL_CONV :LPCSTR, :DWORD, :DWORD, :LPVOID
      ;* Buffer to place the data structure *
      ;* Read version info into buffer *
      GetFileVersionInfoW proto WIN_STD_CALL_CONV :LPCWSTR, :DWORD, :DWORD, :LPVOID
      ;* Buffer to place the data structure *
      ifdef UNICODE
        GetFileVersionInfo equ <GetFileVersionInfoW>
      else
        GetFileVersionInfo equ <GetFileVersionInfoA>
      endif
      ; !UNICODE
      GetFileVersionInfoSizeExA proto WIN_STD_CALL_CONV :DWORD, :LPCSTR, :LPDWORD
      GetFileVersionInfoSizeExW proto WIN_STD_CALL_CONV :DWORD, :LPCWSTR, :LPDWORD
      ifdef UNICODE
        GetFileVersionInfoSizeEx equ <GetFileVersionInfoSizeExW>
      else
        GetFileVersionInfoSizeEx equ <GetFileVersionInfoSizeExA>
      endif
      ; !UNICODE
      GetFileVersionInfoExA proto WIN_STD_CALL_CONV :DWORD, :LPCSTR, :DWORD, :DWORD, :LPVOID
      GetFileVersionInfoExW proto WIN_STD_CALL_CONV :DWORD, :LPCWSTR, :DWORD, :DWORD, :LPVOID
      ifdef UNICODE
        GetFileVersionInfoEx equ <GetFileVersionInfoExW>
      else
        GetFileVersionInfoEx equ <GetFileVersionInfoExA>
      endif
      ; !UNICODE
    endif
    ; RC_INVOKED
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef RC_INVOKED
      ;* !RC_INVOKED *
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    ifndef RC_INVOKED
      VerLanguageNameA proto WIN_STD_CALL_CONV :DWORD, :LPSTR, :DWORD
      VerLanguageNameW proto WIN_STD_CALL_CONV :DWORD, :LPWSTR, :DWORD
      ifdef UNICODE
        VerLanguageName equ <VerLanguageNameW>
      else
        VerLanguageName equ <VerLanguageNameA>
      endif
      ; !UNICODE
      VerQueryValueA proto WIN_STD_CALL_CONV :LPCVOID, :LPCSTR, :ptr LPVOID, :PUINT
      VerQueryValueW proto WIN_STD_CALL_CONV :LPCVOID, :LPCWSTR, :ptr LPVOID, :PUINT
      ifdef UNICODE
        VerQueryValue equ <VerQueryValueW>
      else
        VerQueryValue equ <VerQueryValueA>
      endif
      ; !UNICODE
      ;* !RC_INVOKED *
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
  endif
  ifdef __cplusplus
    ;[...]
  endif
  ;* !VER_H *
endif
