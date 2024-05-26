;Include file created by h2inc+ version C.2.0 on (UTC) 26/05/2024 13:31:25
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\minwindef.h
;             Created on (UTC) 22/05/2024 17:57:07
;             Last modified on (UTC) 21/02/2024 18:13:36

ifndef _MINWINDEF_
  _MINWINDEF_ equ <>
  include specstrings.inc
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    ifndef NO_STRICT
      ifndef STRICT
        STRICT equ 1
      endif
    endif
    ifdef _MAC
      ;[...]
    endif
    ifndef WIN32
      WIN32 equ <>
    endif
    ifdef __cplusplus
      ;[...]
    endif
    ifndef BASETYPES
      BASETYPES equ <>
      ULONG typedef DWORD
      PULONG typedef ptr ULONG
      USHORT typedef WORD
      PUSHORT typedef ptr USHORT
      UCHAR typedef BYTE
      PUCHAR typedef ptr UCHAR
      PSZ typedef ptr SBYTE
    endif
    MAX_PATH equ 260
    ifndef NULL
      ifdef __cplusplus
        ;[...]
      else
        NULL equ (0)
      endif
    endif
    ifndef FALSE
      FALSE equ 0
    endif
    ifndef TRUE
      TRUE equ 1
    endif
    ifndef IN_
      IN_ equ <>
    endif
    ifndef OUT_
      OUT_ equ <>
    endif
    ifndef OPTIONAL
      OPTIONAL equ <>
    endif
    far_ equ <>
    near_ equ <>
    if ( not Defined(_MAC)) and ((_MSC_VER ge 800) or Defined(_STDCALL_SUPPORTED))
      pascal_ equ <__stdcall>
    else
      pascal_ equ <>
    endif
    if Defined(DOSWIN32) or Defined(_MAC)
      cdecl equ <_cdecl>
      ifndef CDECL
        CDECL equ <_cdecl>
      endif
    else
      cdecl equ <>
      ifndef CDECL
        CDECL equ <>
      endif
    endif
    ifdef _MAC
      ;[...]
    elseif (_MSC_VER ge 800) or Defined(_STDCALL_SUPPORTED)
      CALLBACK equ <__stdcall>
      WINAPI equ <__stdcall>
      WINAPIV equ <__cdecl>
      APIENTRY equ <WINAPI>
      APIPRIVATE equ <__stdcall>
      PASCAL_ equ <__stdcall>
    else
      CALLBACK equ <>
      WINAPI equ <>
      WINAPIV equ <>
      APIENTRY equ <WINAPI>
      APIPRIVATE equ <>
      PASCAL_ equ <pascal>
    endif
    ifndef _M_CEE_PURE
      ifndef WINAPI_INLINE
        WINAPI_INLINE equ <WINAPI>
      endif
    endif
    FAR_ equ <far>
    NEAR_ equ <near>
    ifndef CONST
      CONST equ <const>
    endif
    BOOL typedef SDWORD
    FLOAT typedef REAL4
    PFLOAT typedef ptr FLOAT
    PBOOL typedef ptr BOOL
    LPBOOL typedef ptr BOOL
    PBYTE typedef ptr BYTE
    LPBYTE typedef ptr BYTE
    PINT typedef ptr SDWORD
    LPINT typedef ptr SDWORD
    PWORD typedef ptr WORD
    LPWORD typedef ptr WORD
    LPLONG typedef ptr SDWORD
    PDWORD typedef ptr DWORD
    LPDWORD typedef ptr DWORD
    LPVOID typedef ptr
    LPCVOID typedef ptr
    INT_ typedef SDWORD
    UINT typedef DWORD
    PUINT typedef ptr DWORD
    ifndef NT_INCLUDED
      include winnt.inc
    endif
    WPARAM typedef UINT_PTR
    LPARAM typedef LONG_PTR
    LRESULT typedef LONG_PTR
    ifndef NOMINMAX
      ifndef max
        max macro a, b
          exitm <(((a) > (b)) ? (a) : (b))>
        endm
      endif
      ifndef min
        min macro a, b
          exitm <(((a) < (b)) ? (a) : (b))>
        endm
      endif
    endif
    MAKEWORD macro a, b
      exitm <((((((a)) and 0ffh)) or (((((b)) and 0ffh))) shl 8))>
    endm
    MAKELONG macro a, b
      exitm <((((((a)) and 0ffffh)) or (((((b)) and 0ffffh))) shl 16))>
    endm
    LOWORD macro l
      exitm <((((l)) and 0ffffh))>
    endm
    HIWORD macro l
      exitm <(((((l)) shr 16) and 0ffffh))>
    endm
    LOBYTE macro w
      exitm <((((w)) and 0ffh))>
    endm
    HIBYTE macro w
      exitm <(((((w)) shr 8) and 0ffh))>
    endm
    SPHANDLE typedef ptr HANDLE
    LPHANDLE typedef ptr HANDLE
    HGLOBAL typedef HANDLE
    HLOCAL typedef HANDLE
    GLOBALHANDLE typedef HANDLE
    LOCALHANDLE typedef HANDLE
    ifndef _MANAGED
      if _MSC_VER ge 1200
      endif
      ifndef _MAC
        ifdef _WIN64
          TYPE_FARPROC typedef proto WIN_STD_CALL_CONV
          FARPROC typedef ptr TYPE_FARPROC

          TYPE_NEARPROC typedef proto WIN_STD_CALL_CONV
          NEARPROC typedef ptr TYPE_NEARPROC

          TYPE_PROC typedef proto WIN_STD_CALL_CONV
          PROC_ typedef ptr TYPE_PROC

        else
          TYPE_FARPROC typedef proto WIN_STD_CALL_CONV
          FARPROC typedef ptr TYPE_FARPROC

          TYPE_NEARPROC typedef proto WIN_STD_CALL_CONV
          NEARPROC typedef ptr TYPE_NEARPROC

          TYPE_PROC typedef proto WIN_STD_CALL_CONV
          PROC_ typedef ptr TYPE_PROC

        endif
      else
        ;[...]
      endif
      if _MSC_VER ge 1200
      endif
    else
      ;[...]
    endif
    ATOM typedef WORD
    DECLARE_HANDLE HKEY
    PHKEY typedef ptr HKEY
    DECLARE_HANDLE HMETAFILE
    DECLARE_HANDLE HINSTANCE
    HMODULE typedef HINSTANCE
    DECLARE_HANDLE HRGN
    DECLARE_HANDLE HRSRC
    DECLARE_HANDLE HSPRITE
    DECLARE_HANDLE HLSURF
    DECLARE_HANDLE HSTR
    DECLARE_HANDLE HTASK
    DECLARE_HANDLE HWINSTA
    DECLARE_HANDLE HKL
    ifndef _MAC
      HFILE typedef SDWORD
    else
      ;[...]
    endif
    FILETIME struct
      dwLowDateTime DWORD ?
      dwHighDateTime DWORD ?
    FILETIME ends
    _FILETIME typedef FILETIME
    PFILETIME typedef ptr FILETIME
    LPFILETIME typedef ptr FILETIME
    _FILETIME_ equ <>
    ifdef __cplusplus
      ;[...]
    endif
  endif
endif
