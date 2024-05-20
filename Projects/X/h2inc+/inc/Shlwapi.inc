;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\shlwapi.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 21/02/2024 18:17:26

;\*****************************************************************************
ifndef _INC_SHLWAPI
  _INC_SHLWAPI equ <>
  include winapifamily.inc
  ifndef NOSHLWAPI
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      include SpecStrings.inc
      include objbase.inc
      include shtypes.inc
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      ; Define API decoration for direct importing of DLL references.
      ifndef WINSHLWAPI
        if  not Defined(_SHLWAPI_)
          LWSTDAPI equ <EXTERN_C DECLSPEC_IMPORT HRESULT STDAPICALLTYPE>
          LWSTDAPI_ macro type_
            exitm <EXTERN_C DECLSPEC_IMPORT type_ STDAPICALLTYPE>
          endm
          LWSTDAPIV equ <EXTERN_C DECLSPEC_IMPORT HRESULT STDAPIVCALLTYPE>
          LWSTDAPIV_ macro type_
            exitm <EXTERN_C DECLSPEC_IMPORT type_ STDAPIVCALLTYPE>
          endm
        else
          LWSTDAPI equ <STDAPI>
          LWSTDAPI_ macro type_
            exitm <STDAPI_(type_)>
          endm
          LWSTDAPIV equ <STDAPIV>
          LWSTDAPIV_ macro type_
            exitm <STDAPIV_(type_)>
          endm
        endif
      endif
      ; WINSHLWAPI
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      if _MSC_VER ge 1200
        ; padding added after data member
      endif
      ifdef _WIN32
        include pshpack8.inc
      endif
      if Defined(DEPRECATE_SUPPORTED)
      endif
      ; objidl.h
      ifndef __IBindCtx_FWD_DEFINED__
        __IBindCtx_FWD_DEFINED__ equ <>
        ;* __IBindCtx_FWD_DEFINED__ *
      endif
      ifdef __cplusplus
        ;[...]
      endif
      if Defined(__cplusplus) and Defined(STRICT_CONST)
        ;[...]
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
    endif
    ; Users of this header may define any number of these constants to avoid
    ; the definitions of each functional group.
    ;    NO_SHLWAPI_STRFCNS    String functions
    ;    NO_SHLWAPI_PATH       Path functions
    ;    NO_SHLWAPI_REG        Registry functions
    ;    NO_SHLWAPI_STREAM     Stream functions
    ;    NO_SHLWAPI_GDI        GDI helper functions
    ifndef NO_SHLWAPI_STRFCNS
      ;=============== String Routines ===================================
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        ifdef USE_STRICT_CONST
          @DefProto DllImport, StrChrA, WIN_STD_CALL_CONV,, <:PCSTR, :WORD>, 8
          @DefProto DllImport, StrChrW, WIN_STD_CALL_CONV,, <:PCWSTR, :WCHAR>, 8
          @DefProto DllImport, StrChrIA, WIN_STD_CALL_CONV,, <:PCSTR, :WORD>, 8
          @DefProto DllImport, StrChrIW, WIN_STD_CALL_CONV,, <:PCWSTR, :WCHAR>, 8
          if (_WIN32_IE ge _WIN32_IE_IE60)
            @DefProto DllImport, StrChrNW, WIN_STD_CALL_CONV,, <:PCWSTR, :WCHAR, :UINT>, 12
            @DefProto DllImport, StrChrNIW, WIN_STD_CALL_CONV,, <:PCWSTR, :WCHAR, :UINT>, 12
          endif
          ; _WIN32_IE_IE60
        else
          @DefProto DllImport, StrChrA, WIN_STD_CALL_CONV,, <:PCSTR, :WORD>, 8
          @DefProto DllImport, StrChrW, WIN_STD_CALL_CONV,, <:PCWSTR, :WCHAR>, 8
          @DefProto DllImport, StrChrIA, WIN_STD_CALL_CONV,, <:PCSTR, :WORD>, 8
          @DefProto DllImport, StrChrIW, WIN_STD_CALL_CONV,, <:PCWSTR, :WCHAR>, 8
          if (_WIN32_IE ge _WIN32_IE_IE60)
            @DefProto DllImport, StrChrNW, WIN_STD_CALL_CONV,, <:PCWSTR, :WCHAR, :UINT>, 12
            @DefProto DllImport, StrChrNIW, WIN_STD_CALL_CONV,, <:PCWSTR, :WCHAR, :UINT>, 12
          endif
          ; _WIN32_IE_IE60
        endif
        @DefProto DllImport, StrCmpNA, WIN_STD_CALL_CONV,, <:PCSTR, :PCSTR, :SDWORD>, 12
        @DefProto DllImport, StrCmpNW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR, :SDWORD>, 12
        @DefProto DllImport, StrCmpNIA, WIN_STD_CALL_CONV,, <:PCSTR, :PCSTR, :SDWORD>, 12
        @DefProto DllImport, StrCmpNIW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR, :SDWORD>, 12
        @DefProto DllImport, StrCSpnA, WIN_STD_CALL_CONV,, <:PCSTR, :PCSTR>, 8
        @DefProto DllImport, StrCSpnW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR>, 8
        @DefProto DllImport, StrCSpnIA, WIN_STD_CALL_CONV,, <:PCSTR, :PCSTR>, 8
        @DefProto DllImport, StrCSpnIW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR>, 8
        @DefProto DllImport, StrDupA, WIN_STD_CALL_CONV,, <:PCSTR>, 4
        @DefProto DllImport, StrDupW, WIN_STD_CALL_CONV,, <:PCWSTR>, 4
        if (NTDDI_VERSION ge NTDDI_VISTASP1)
          ; StrFormatByteSizeEx takes a ULONGLONG as a byte count and formats a string
          ; representing that number of bytes in an appropriately concise manner, where
          ; "appropriate manner" is determine by several factors:
          ; 1) order - is this most appropriately expressed as KB? MB? GB?
          ;    for example: 1039 -> "1.01 KB", 5454608466 -> "5.08 GB", etc
          ; 2) number of whole number places shown - if there are more than a few whole
          ;    number places to display, decimal places are omitted.
          ;    for example: 1024 -> "1.00 KB", 12288 -> "12.0 KB", 125952 -> "123 KB"
          ; 3) the caller can specify whether the result should involve rounding to the
          ;    nearest displayed digit, or truncation of undisplayed digits. the caller
          ;    must specify either rounding or truncation when calling the API.
          ;    for example: with rounding,   2147483647 -> "2.00 GB"
          ;                 with truncation, 2147483647 -> "1.99 GB"
          tagSFBS_FLAGS typedef SDWORD
          SFBS_FLAGS_ROUND_TO_NEAREST_DISPLAYED_DIGIT equ 0001h
          ; round to the nearest displayed digit
          SFBS_FLAGS_TRUNCATE_UNDISPLAYED_DECIMAL_DIGITS equ 0002h
          ; discard undisplayed digits

          SFBS_FLAGS typedef SDWORD
          @DefProto DllImport, StrFormatByteSizeEx, WIN_STD_CALL_CONV,, <:ULONGLONG, :SFBS_FLAGS, :PWSTR, :UINT>, 16
        endif
        ; (NTDDI_VERSION >= NTDDI_VISTASP1)
        @DefProto DllImport, StrFormatByteSizeA, WIN_STD_CALL_CONV,, <:DWORD, :PSTR, :UINT>, 12
        @DefProto DllImport, StrFormatByteSize64A, WIN_STD_CALL_CONV,, <:LONGLONG, :PSTR, :UINT>, 12
        @DefProto DllImport, StrFormatByteSizeW, WIN_STD_CALL_CONV,, <:LONGLONG, :PWSTR, :UINT>, 12
        @DefProto DllImport, StrFormatKBSizeW, WIN_STD_CALL_CONV,, <:LONGLONG, :PWSTR, :UINT>, 12
        @DefProto DllImport, StrFormatKBSizeA, WIN_STD_CALL_CONV,, <:LONGLONG, :PSTR, :UINT>, 12
        @DefProto DllImport, StrFromTimeIntervalA, WIN_STD_CALL_CONV,, <:PSTR, :UINT, :DWORD, :SDWORD>, 16
        @DefProto DllImport, StrFromTimeIntervalW, WIN_STD_CALL_CONV,, <:PWSTR, :UINT, :DWORD, :SDWORD>, 16
        @DefProto DllImport, StrIsIntlEqualA, WIN_STD_CALL_CONV,, <:BOOL, :PCSTR, :PCSTR, :SDWORD>, 16
        @DefProto DllImport, StrIsIntlEqualW, WIN_STD_CALL_CONV,, <:BOOL, :PCWSTR, :PCWSTR, :SDWORD>, 16
        @DefProto DllImport, StrNCatA, WIN_STD_CALL_CONV,, <:PSTR, :PCSTR, :SDWORD>, 12
        @DefProto DllImport, StrNCatW, WIN_STD_CALL_CONV,, <:PWSTR, :PCWSTR, :SDWORD>, 12
        ifdef USE_STRICT_CONST
          @DefProto DllImport, StrPBrkA, WIN_STD_CALL_CONV,, <:PCSTR, :PCSTR>, 8
          @DefProto DllImport, StrPBrkW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR>, 8
          @DefProto DllImport, StrRChrA, WIN_STD_CALL_CONV,, <:PCSTR, :PCSTR, :WORD>, 12
          @DefProto DllImport, StrRChrW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR, :WCHAR>, 12
          @DefProto DllImport, StrRChrIA, WIN_STD_CALL_CONV,, <:PCSTR, :PCSTR, :WORD>, 12
          @DefProto DllImport, StrRChrIW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR, :WCHAR>, 12
          @DefProto DllImport, StrRStrIA, WIN_STD_CALL_CONV,, <:PCSTR, :PCSTR, :PCSTR>, 12
          @DefProto DllImport, StrRStrIW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR, :PCWSTR>, 12
        else
          @DefProto DllImport, StrPBrkA, WIN_STD_CALL_CONV,, <:PCSTR, :PCSTR>, 8
          @DefProto DllImport, StrPBrkW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR>, 8
          @DefProto DllImport, StrRChrA, WIN_STD_CALL_CONV,, <:PCSTR, :PCSTR, :WORD>, 12
          @DefProto DllImport, StrRChrW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR, :WCHAR>, 12
          @DefProto DllImport, StrRChrIA, WIN_STD_CALL_CONV,, <:PCSTR, :PCSTR, :WORD>, 12
          @DefProto DllImport, StrRChrIW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR, :WCHAR>, 12
          @DefProto DllImport, StrRStrIA, WIN_STD_CALL_CONV,, <:PCSTR, :PCSTR, :PCSTR>, 12
          @DefProto DllImport, StrRStrIW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR, :PCWSTR>, 12
        endif
        @DefProto DllImport, StrSpnA, WIN_STD_CALL_CONV,, <:PCSTR, :PCSTR>, 8
        @DefProto DllImport, StrSpnW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR>, 8
        ifdef USE_STRICT_CONST
          @DefProto DllImport, StrStrA, WIN_STD_CALL_CONV,, <:PCSTR, :PCSTR>, 8
          @DefProto DllImport, StrStrW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR>, 8
          @DefProto DllImport, StrStrIA, WIN_STD_CALL_CONV,, <:PCSTR, :PCSTR>, 8
          @DefProto DllImport, StrStrIW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR>, 8
          if (_WIN32_IE ge _WIN32_IE_IE6)
            @DefProto DllImport, StrStrNW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR, :UINT>, 12
            @DefProto DllImport, StrStrNIW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR, :UINT>, 12
          endif
          ; _WIN32_IE_IE6
        else
          @DefProto DllImport, StrStrA, WIN_STD_CALL_CONV,, <:PCSTR, :PCSTR>, 8
          @DefProto DllImport, StrStrW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR>, 8
          @DefProto DllImport, StrStrIA, WIN_STD_CALL_CONV,, <:PCSTR, :PCSTR>, 8
          @DefProto DllImport, StrStrIW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR>, 8
          if (_WIN32_IE ge _WIN32_IE_IE60)
            @DefProto DllImport, StrStrNW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR, :UINT>, 12
            @DefProto DllImport, StrStrNIW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR, :UINT>, 12
          endif
          ; _WIN32_IE_IE60
        endif
        STIF_DEFAULT equ 00000000h
        STIF_SUPPORT_HEX equ 00000001h
        STIF_FLAGS typedef SDWORD
        @DefProto DllImport, StrToIntA, WIN_STD_CALL_CONV,, <:PCSTR>, 4
        @DefProto DllImport, StrToIntW, WIN_STD_CALL_CONV,, <:PCWSTR>, 4
        @DefProto DllImport, StrToIntExA, WIN_STD_CALL_CONV,, <:PCSTR, :STIF_FLAGS, :ptr SDWORD>, 12
        @DefProto DllImport, StrToIntExW, WIN_STD_CALL_CONV,, <:PCWSTR, :STIF_FLAGS, :ptr SDWORD>, 12
        if (_WIN32_IE ge _WIN32_IE_IE60)
          @DefProto DllImport, StrToInt64ExA, WIN_STD_CALL_CONV,, <:PCSTR, :STIF_FLAGS, :ptr LONGLONG>, 12
          @DefProto DllImport, StrToInt64ExW, WIN_STD_CALL_CONV,, <:PCWSTR, :STIF_FLAGS, :ptr LONGLONG>, 12
        endif
        ; _WIN32_IE_IE60
        @DefProto DllImport, StrTrimA, WIN_STD_CALL_CONV,, <:PSTR, :PCSTR>, 8
        @DefProto DllImport, StrTrimW, WIN_STD_CALL_CONV,, <:PWSTR, :PCWSTR>, 8
        @DefProto DllImport, StrCatW, WIN_STD_CALL_CONV,, <:PWSTR, :PCWSTR>, 8
        @DefProto DllImport, StrCmpW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR>, 8
        @DefProto DllImport, StrCmpIW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR>, 8
        @DefProto DllImport, StrCpyW, WIN_STD_CALL_CONV,, <:PWSTR, :PCWSTR>, 8
        @DefProto DllImport, StrCpyNW, WIN_STD_CALL_CONV,, <:PWSTR, :PCWSTR, :SDWORD>, 12
        @DefProto DllImport, StrCatBuffW, WIN_STD_CALL_CONV,, <:PWSTR, :PCWSTR, :SDWORD>, 12
        @DefProto DllImport, StrCatBuffA, WIN_STD_CALL_CONV,, <:PSTR, :PCSTR, :SDWORD>, 12
        @DefProto DllImport, ChrCmpIA, WIN_STD_CALL_CONV,, <:WORD, :WORD>, 8
        @DefProto DllImport, ChrCmpIW, WIN_STD_CALL_CONV,, <:WCHAR, :WCHAR>, 8
        @DefProto DllImport, wvnsprintfA, WIN_STD_CALL_CONV,, <:PSTR, :SDWORD, :PCSTR, :va_list>, 16
        @DefProto DllImport, wvnsprintfW, WIN_STD_CALL_CONV,, <:PWSTR, :SDWORD, :PCWSTR, :va_list>, 16
        @DefProto DllImport, wnsprintfA, c,, <:PSTR, :SDWORD, :PCSTR, :vararg>
        @DefProto DllImport, wnsprintfW, c,, <:PWSTR, :SDWORD, :PCWSTR, :vararg>
        StrIntlEqNA macro s1, s2, nChar
          exitm <StrIsIntlEqualA (TRUE, s1, s2, nChar)>
        endm
        StrIntlEqNW macro s1, s2, nChar
          exitm <StrIsIntlEqualW (TRUE, s1, s2, nChar)>
        endm
        StrIntlEqNIA macro s1, s2, nChar
          exitm <StrIsIntlEqualA (FALSE, s1, s2, nChar)>
        endm
        StrIntlEqNIW macro s1, s2, nChar
          exitm <StrIsIntlEqualW (FALSE, s1, s2, nChar)>
        endm
        @DefProto DllImport, StrRetToStrA, WIN_STD_CALL_CONV,, <:ptr STRRET, :PCUITEMID_CHILD, :ptr LPSTR>, 12
        @DefProto DllImport, StrRetToStrW, WIN_STD_CALL_CONV,, <:ptr STRRET, :PCUITEMID_CHILD, :ptr LPWSTR>, 12
        ifdef UNICODE
          StrRetToStr equ <StrRetToStrW>
        else
          StrRetToStr equ <StrRetToStrA>
        endif
        ; !UNICODE
        @DefProto DllImport, StrRetToBufA, WIN_STD_CALL_CONV,, <:ptr STRRET, :PCUITEMID_CHILD, :LPSTR, :UINT>, 16
        @DefProto DllImport, StrRetToBufW, WIN_STD_CALL_CONV,, <:ptr STRRET, :PCUITEMID_CHILD, :LPWSTR, :UINT>, 16
        ifdef UNICODE
          StrRetToBuf equ <StrRetToBufW>
        else
          StrRetToBuf equ <StrRetToBufA>
        endif
        ; !UNICODE
        ; helper to duplicate a string using the task allocator
        @DefProto DllImport, SHStrDupA, WIN_STD_CALL_CONV,, <:LPCSTR, :ptr LPWSTR>, 8
        @DefProto DllImport, SHStrDupW, WIN_STD_CALL_CONV,, <:LPCWSTR, :ptr LPWSTR>, 8
        ifdef UNICODE
          SHStrDup equ <SHStrDupW>
        else
          SHStrDup equ <SHStrDupA>
        endif
        ; !UNICODE
        ifdef __cplusplus
          ;[...]
          ; C6387
        endif
        ; __cplusplus
        @DefProto DllImport, StrCmpLogicalW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR>, 8
        @DefProto DllImport, StrCatChainW, WIN_STD_CALL_CONV,, <:PWSTR, :DWORD, :DWORD, :PCWSTR>, 16
        @DefProto DllImport, StrRetToBSTR, WIN_STD_CALL_CONV,, <:ptr STRRET, :PCUITEMID_CHILD, :ptr BSTR>, 12
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
        @DefProto DllImport, SHLoadIndirectString, WIN_STD_CALL_CONV,, <:PCWSTR, :PWSTR, :UINT, :ptr ptr>, 16
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        if (_WIN32_IE ge _WIN32_IE_IE60SP2)
          @DefProto DllImport, IsCharSpaceA, WIN_STD_CALL_CONV,, <:CHAR>, 4
          @DefProto DllImport, IsCharSpaceW, WIN_STD_CALL_CONV,, <:WCHAR>, 4
          ifdef UNICODE
            IsCharSpace equ <IsCharSpaceW>
          else
            IsCharSpace equ <IsCharSpaceA>
          endif
          ; !UNICODE
          @DefProto DllImport, StrCmpCA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR>, 8
          @DefProto DllImport, StrCmpCW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR>, 8
          ifdef UNICODE
            StrCmpC equ <StrCmpCW>
          else
            StrCmpC equ <StrCmpCA>
          endif
          ; !UNICODE
          @DefProto DllImport, StrCmpICA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR>, 8
          @DefProto DllImport, StrCmpICW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR>, 8
          ifdef UNICODE
            StrCmpIC equ <StrCmpICW>
          else
            StrCmpIC equ <StrCmpICA>
          endif
          ; !UNICODE
        endif
        ; _WIN32_IE_IE60SP2
        ifdef UNICODE
          StrChr equ <StrChrW>
          StrRChr equ <StrRChrW>
          StrChrI equ <StrChrIW>
          StrRChrI equ <StrRChrIW>
          StrCmpN equ <StrCmpNW>
          StrCmpNI equ <StrCmpNIW>
          StrStr equ <StrStrW>
          StrStrI equ <StrStrIW>
          StrDup equ <StrDupW>
          StrRStrI equ <StrRStrIW>
          StrCSpn equ <StrCSpnW>
          StrCSpnI equ <StrCSpnIW>
          StrSpn equ <StrSpnW>
          StrToInt equ <StrToIntW>
          StrPBrk equ <StrPBrkW>
          StrToIntEx equ <StrToIntExW>
          if (_WIN32_IE ge 0600h)
            StrToInt64Ex equ <StrToInt64ExW>
          endif
          StrFromTimeInterval equ <StrFromTimeIntervalW>
          StrIntlEqN equ <StrIntlEqNW>
          StrIntlEqNI equ <StrIntlEqNIW>
          StrFormatByteSize equ <StrFormatByteSizeW>
          StrFormatByteSize64 equ <StrFormatByteSizeW>
          StrFormatKBSize equ <StrFormatKBSizeW>
          StrNCat equ <StrNCatW>
          StrTrim equ <StrTrimW>
          StrCatBuff equ <StrCatBuffW>
          ChrCmpI equ <ChrCmpIW>
          wvnsprintf equ <wvnsprintfW>
          wnsprintf equ <wnsprintfW>
          StrIsIntlEqual equ <StrIsIntlEqualW>
        else
          StrChr equ <StrChrA>
          StrRChr equ <StrRChrA>
          StrChrI equ <StrChrIA>
          StrRChrI equ <StrRChrIA>
          StrCmpN equ <StrCmpNA>
          StrCmpNI equ <StrCmpNIA>
          StrStr equ <StrStrA>
          StrStrI equ <StrStrIA>
          StrDup equ <StrDupA>
          StrRStrI equ <StrRStrIA>
          StrCSpn equ <StrCSpnA>
          StrCSpnI equ <StrCSpnIA>
          StrSpn equ <StrSpnA>
          StrToInt equ <StrToIntA>
          StrPBrk equ <StrPBrkA>
          StrToIntEx equ <StrToIntExA>
          if (_WIN32_IE ge 0600h)
            StrToInt64Ex equ <StrToInt64ExA>
          endif
          StrFromTimeInterval equ <StrFromTimeIntervalA>
          StrIntlEqN equ <StrIntlEqNA>
          StrIntlEqNI equ <StrIntlEqNIA>
          StrFormatByteSize equ <StrFormatByteSizeA>
          StrFormatByteSize64 equ <StrFormatByteSize64A>
          StrFormatKBSize equ <StrFormatKBSizeA>
          StrNCat equ <StrNCatA>
          StrTrim equ <StrTrimA>
          StrCatBuff equ <StrCatBuffA>
          ChrCmpI equ <ChrCmpIA>
          wvnsprintf equ <wvnsprintfA>
          wnsprintf equ <wnsprintfA>
          StrIsIntlEqual equ <StrIsIntlEqualA>
        endif
        ; StrCmp*C* - Compare strings using C runtime collation rules.
        @DefProto DllImport, StrCmpNCA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :SDWORD>, 12
        ; StrCmp*C* - Compare strings using C runtime collation rules.
        @DefProto DllImport, StrCmpNCW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :SDWORD>, 12
        ifdef UNICODE
          StrCmpNC equ <StrCmpNCW>
        else
          StrCmpNC equ <StrCmpNCA>
        endif
        ; !UNICODE
        @DefProto DllImport, StrCmpNICA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :SDWORD>, 12
        @DefProto DllImport, StrCmpNICW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :SDWORD>, 12
        ifdef UNICODE
          StrCmpNIC equ <StrCmpNICW>
        else
          StrCmpNIC equ <StrCmpNICA>
        endif
        ; !UNICODE
        ; Backward compatible to NT's non-standard naming (strictly
        ; for comctl32)
        @DefProto DllImport, IntlStrEqWorkerA, WIN_STD_CALL_CONV,, <:BOOL, :LPCSTR, :LPCSTR, :SDWORD>, 16
        @DefProto DllImport, IntlStrEqWorkerW, WIN_STD_CALL_CONV,, <:BOOL, :LPCWSTR, :LPCWSTR, :SDWORD>, 16
        IntlStrEqNA macro s1, s2, nChar
          exitm <IntlStrEqWorkerA (TRUE, s1, s2, nChar)>
        endm
        IntlStrEqNW macro s1, s2, nChar
          exitm <IntlStrEqWorkerW (TRUE, s1, s2, nChar)>
        endm
        IntlStrEqNIA macro s1, s2, nChar
          exitm <IntlStrEqWorkerA (FALSE, s1, s2, nChar)>
        endm
        IntlStrEqNIW macro s1, s2, nChar
          exitm <IntlStrEqWorkerW (FALSE, s1, s2, nChar)>
        endm
        ifdef UNICODE
          IntlStrEqN equ <IntlStrEqNW>
          IntlStrEqNI equ <IntlStrEqNIW>
        else
          IntlStrEqN equ <IntlStrEqNA>
          IntlStrEqNI equ <IntlStrEqNIA>
        endif
        SZ_CONTENTTYPE_HTMLA equ <"text/html">
        SZ_CONTENTTYPE_HTMLW equ <L("text/html")>
        SZ_CONTENTTYPE_CDFA equ <"application/x-cdf">
        SZ_CONTENTTYPE_CDFW equ <L("application/x-cdf")>
        ifdef UNICODE
          SZ_CONTENTTYPE_HTML equ <SZ_CONTENTTYPE_HTMLW>
          SZ_CONTENTTYPE_CDF equ <SZ_CONTENTTYPE_CDFW>
        else
          SZ_CONTENTTYPE_HTML equ <SZ_CONTENTTYPE_HTMLA>
          SZ_CONTENTTYPE_CDF equ <SZ_CONTENTTYPE_CDFA>
        endif
        PathIsHTMLFileA macro pszPath
          exitm <PathIsContentTypeA (pszPath, SZ_CONTENTTYPE_HTMLA)>
        endm
        PathIsHTMLFileW macro pszPath
          exitm <PathIsContentTypeW (pszPath, SZ_CONTENTTYPE_HTMLW)>
        endm
        StrCatA equ <lstrcatA>
        StrCmpA equ <lstrcmpA>
        StrCmpIA equ <lstrcmpiA>
        StrCpyA equ <lstrcpyA>
        StrCpyNA equ <lstrcpynA>
        StrToLong equ <StrToInt>
        StrNCmp equ <StrCmpN>
        StrNCmpI equ <StrCmpNI>
        StrNCpy equ <StrCpyN>
        StrCatN equ <StrNCat>
        ifdef UNICODE
          StrCat equ <StrCatW>
          StrCmp equ <StrCmpW>
          StrCmpI equ <StrCmpIW>
          StrCpy equ <StrCpyW>
          StrCpyN equ <StrCpyNW>
          StrCatBuff equ <StrCatBuffW>
        else
          StrCat equ <lstrcatA>
          StrCmp equ <lstrcmpA>
          StrCmpI equ <lstrcmpiA>
          StrCpy equ <lstrcpyA>
          StrCpyN equ <lstrcpynA>
          StrCatBuff equ <StrCatBuffA>
        endif
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
    endif
    ;  NO_SHLWAPI_STRFCNS
    ifndef NO_SHLWAPI_PATH
      ;=============== Path Routines ===================================
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, PathAddBackslashA, WIN_STD_CALL_CONV,, <:LPSTR>, 4
        @DefProto DllImport, PathAddBackslashW, WIN_STD_CALL_CONV,, <:LPWSTR>, 4
        ifdef UNICODE
          PathAddBackslash equ <PathAddBackslashW>
        else
          PathAddBackslash equ <PathAddBackslashA>
        endif
        ; !UNICODE
        @DefProto DllImport, PathAddExtensionA, WIN_STD_CALL_CONV,, <:LPSTR, :LPCSTR>, 8
        @DefProto DllImport, PathAddExtensionW, WIN_STD_CALL_CONV,, <:LPWSTR, :LPCWSTR>, 8
        ifdef UNICODE
          PathAddExtension equ <PathAddExtensionW>
        else
          PathAddExtension equ <PathAddExtensionA>
        endif
        ; !UNICODE
        @DefProto DllImport, PathAppendA, WIN_STD_CALL_CONV,, <:LPSTR, :LPCSTR>, 8
        @DefProto DllImport, PathAppendW, WIN_STD_CALL_CONV,, <:LPWSTR, :LPCWSTR>, 8
        @DefProto DllImport, PathBuildRootA, WIN_STD_CALL_CONV,, <:LPSTR, :SDWORD>, 8
        @DefProto DllImport, PathBuildRootW, WIN_STD_CALL_CONV,, <:LPWSTR, :SDWORD>, 8
        ifdef UNICODE
          PathBuildRoot equ <PathBuildRootW>
        else
          PathBuildRoot equ <PathBuildRootA>
        endif
        ; !UNICODE
        @DefProto DllImport, PathCanonicalizeA, WIN_STD_CALL_CONV,, <:LPSTR, :LPCSTR>, 8
        @DefProto DllImport, PathCanonicalizeW, WIN_STD_CALL_CONV,, <:LPWSTR, :LPCWSTR>, 8
        @DefProto DllImport, PathCombineA, WIN_STD_CALL_CONV,, <:LPSTR, :LPCSTR, :LPCSTR>, 12
        @DefProto DllImport, PathCombineW, WIN_STD_CALL_CONV,, <:LPWSTR, :LPCWSTR, :LPCWSTR>, 12
        ifdef UNICODE
          PathCombine equ <PathCombineW>
        else
          PathCombine equ <PathCombineA>
        endif
        ; !UNICODE
        @DefProto DllImport, PathCompactPathA, WIN_STD_CALL_CONV,, <:HDC, :LPSTR, :UINT>, 12
        @DefProto DllImport, PathCompactPathW, WIN_STD_CALL_CONV,, <:HDC, :LPWSTR, :UINT>, 12
        @DefProto DllImport, PathCompactPathExA, WIN_STD_CALL_CONV,, <:LPSTR, :LPCSTR, :UINT, :DWORD>, 16
        @DefProto DllImport, PathCompactPathExW, WIN_STD_CALL_CONV,, <:LPWSTR, :LPCWSTR, :UINT, :DWORD>, 16
        @DefProto DllImport, PathCommonPrefixA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :LPSTR>, 12
        @DefProto DllImport, PathCommonPrefixW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPWSTR>, 12
        @DefProto DllImport, PathFileExistsA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
        @DefProto DllImport, PathFileExistsW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
        ifdef UNICODE
          PathFileExists equ <PathFileExistsW>
        else
          PathFileExists equ <PathFileExistsA>
        endif
        ; !UNICODE
        ifdef USE_STRICT_CONST
          @DefProto DllImport, PathFindExtensionA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
          @DefProto DllImport, PathFindExtensionW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
          ifdef UNICODE
            PathFindExtension equ <PathFindExtensionW>
          else
            PathFindExtension equ <PathFindExtensionA>
          endif
          ; !UNICODE
          @DefProto DllImport, PathFindFileNameA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
          @DefProto DllImport, PathFindFileNameW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
          ifdef UNICODE
            PathFindFileName equ <PathFindFileNameW>
          else
            PathFindFileName equ <PathFindFileNameA>
          endif
          ; !UNICODE
          @DefProto DllImport, PathFindNextComponentA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
          @DefProto DllImport, PathFindNextComponentW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
          ifdef UNICODE
            PathFindNextComponent equ <PathFindNextComponentW>
          else
            PathFindNextComponent equ <PathFindNextComponentA>
          endif
          ; !UNICODE
        else
          @DefProto DllImport, PathFindExtensionA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
          @DefProto DllImport, PathFindExtensionW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
          ifdef UNICODE
            PathFindExtension equ <PathFindExtensionW>
          else
            PathFindExtension equ <PathFindExtensionA>
          endif
          ; !UNICODE
          @DefProto DllImport, PathFindFileNameA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
          @DefProto DllImport, PathFindFileNameW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
          ifdef UNICODE
            PathFindFileName equ <PathFindFileNameW>
          else
            PathFindFileName equ <PathFindFileNameA>
          endif
          ; !UNICODE
          @DefProto DllImport, PathFindNextComponentA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
          @DefProto DllImport, PathFindNextComponentW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
          ifdef UNICODE
            PathFindNextComponent equ <PathFindNextComponentW>
          else
            PathFindNextComponent equ <PathFindNextComponentA>
          endif
          ; !UNICODE
        endif
        @DefProto DllImport, PathFindOnPathA, WIN_STD_CALL_CONV,, <:LPSTR, :PZPCSTR>, 8
        @DefProto DllImport, PathFindOnPathW, WIN_STD_CALL_CONV,, <:LPWSTR, :PZPCWSTR>, 8
        @DefProto DllImport, PathFindSuffixArrayA, WIN_STD_CALL_CONV,, <:LPCSTR, :ptr LPCSTR, :SDWORD>, 12
        @DefProto DllImport, PathFindSuffixArrayW, WIN_STD_CALL_CONV,, <:LPCWSTR, :ptr LPCWSTR, :SDWORD>, 12
        ifdef UNICODE
          PathFindSuffixArray equ <PathFindSuffixArrayW>
        else
          PathFindSuffixArray equ <PathFindSuffixArrayA>
        endif
        ; !UNICODE
        ifdef USE_STRICT_CONST
          @DefProto DllImport, PathGetArgsA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
          @DefProto DllImport, PathGetArgsW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
          ifdef UNICODE
            PathGetArgs equ <PathGetArgsW>
          else
            PathGetArgs equ <PathGetArgsA>
          endif
          ; !UNICODE
        else
          @DefProto DllImport, PathGetArgsA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
          @DefProto DllImport, PathGetArgsW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
          ifdef UNICODE
            PathGetArgs equ <PathGetArgsW>
          else
            PathGetArgs equ <PathGetArgsA>
          endif
          ; !UNICODE
        endif
        @DefProto DllImport, PathIsLFNFileSpecA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
        @DefProto DllImport, PathIsLFNFileSpecW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
        ifdef UNICODE
          PathIsLFNFileSpec equ <PathIsLFNFileSpecW>
        else
          PathIsLFNFileSpec equ <PathIsLFNFileSpecA>
        endif
        ; !UNICODE
        @DefProto DllImport, PathGetCharTypeA, WIN_STD_CALL_CONV,, <:UCHAR>, 4
        @DefProto DllImport, PathGetCharTypeW, WIN_STD_CALL_CONV,, <:WCHAR>, 4
        ; Return flags for PathGetCharType
        GCT_INVALID equ 0000h
        GCT_LFNCHAR equ 0001h
        GCT_SHORTCHAR equ 0002h
        GCT_WILD equ 0004h
        GCT_SEPARATOR equ 0008h
        @DefProto DllImport, PathGetDriveNumberA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
        @DefProto DllImport, PathGetDriveNumberW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
        ifdef UNICODE
          PathGetDriveNumber equ <PathGetDriveNumberW>
        else
          PathGetDriveNumber equ <PathGetDriveNumberA>
        endif
        ; !UNICODE
        @DefProto DllImport, PathIsDirectoryA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
        @DefProto DllImport, PathIsDirectoryW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
        ifdef UNICODE
          PathIsDirectory equ <PathIsDirectoryW>
        else
          PathIsDirectory equ <PathIsDirectoryA>
        endif
        ; !UNICODE
        @DefProto DllImport, PathIsDirectoryEmptyA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
        @DefProto DllImport, PathIsDirectoryEmptyW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
        ifdef UNICODE
          PathIsDirectoryEmpty equ <PathIsDirectoryEmptyW>
        else
          PathIsDirectoryEmpty equ <PathIsDirectoryEmptyA>
        endif
        ; !UNICODE
        @DefProto DllImport, PathIsFileSpecA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
        @DefProto DllImport, PathIsFileSpecW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
        ifdef UNICODE
          PathIsFileSpec equ <PathIsFileSpecW>
        else
          PathIsFileSpec equ <PathIsFileSpecA>
        endif
        ; !UNICODE
        @DefProto DllImport, PathIsPrefixA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR>, 8
        @DefProto DllImport, PathIsPrefixW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR>, 8
        ifdef UNICODE
          PathIsPrefix equ <PathIsPrefixW>
        else
          PathIsPrefix equ <PathIsPrefixA>
        endif
        ; !UNICODE
        @DefProto DllImport, PathIsRelativeA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
        @DefProto DllImport, PathIsRelativeW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
        ifdef UNICODE
          PathIsRelative equ <PathIsRelativeW>
        else
          PathIsRelative equ <PathIsRelativeA>
        endif
        ; !UNICODE
        @DefProto DllImport, PathIsRootA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
        @DefProto DllImport, PathIsRootW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
        ifdef UNICODE
          PathIsRoot equ <PathIsRootW>
        else
          PathIsRoot equ <PathIsRootA>
        endif
        ; !UNICODE
        @DefProto DllImport, PathIsSameRootA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR>, 8
        @DefProto DllImport, PathIsSameRootW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR>, 8
        ifdef UNICODE
          PathIsSameRoot equ <PathIsSameRootW>
        else
          PathIsSameRoot equ <PathIsSameRootA>
        endif
        ; !UNICODE
        @DefProto DllImport, PathIsUNCA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
        @DefProto DllImport, PathIsUNCW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
        ifdef UNICODE
          PathIsUNC equ <PathIsUNCW>
        else
          PathIsUNC equ <PathIsUNCA>
        endif
        ; !UNICODE
        @DefProto DllImport, PathIsNetworkPathA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
        @DefProto DllImport, PathIsNetworkPathW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
        ifdef UNICODE
          PathIsNetworkPath equ <PathIsNetworkPathW>
        else
          PathIsNetworkPath equ <PathIsNetworkPathA>
        endif
        ; !UNICODE
        @DefProto DllImport, PathIsUNCServerA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
        @DefProto DllImport, PathIsUNCServerW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
        ifdef UNICODE
          PathIsUNCServer equ <PathIsUNCServerW>
        else
          PathIsUNCServer equ <PathIsUNCServerA>
        endif
        ; !UNICODE
        @DefProto DllImport, PathIsUNCServerShareA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
        @DefProto DllImport, PathIsUNCServerShareW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
        ifdef UNICODE
          PathIsUNCServerShare equ <PathIsUNCServerShareW>
        else
          PathIsUNCServerShare equ <PathIsUNCServerShareA>
        endif
        ; !UNICODE
        @DefProto DllImport, PathIsContentTypeA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR>, 8
        @DefProto DllImport, PathIsContentTypeW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR>, 8
        @DefProto DllImport, PathIsURLA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
        @DefProto DllImport, PathIsURLW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
        ifdef UNICODE
          PathIsURL equ <PathIsURLW>
        else
          PathIsURL equ <PathIsURLA>
        endif
        ; !UNICODE
        @DefProto DllImport, PathMakePrettyA, WIN_STD_CALL_CONV,, <:LPSTR>, 4
        @DefProto DllImport, PathMakePrettyW, WIN_STD_CALL_CONV,, <:LPWSTR>, 4
        @DefProto DllImport, PathMatchSpecA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR>, 8
        @DefProto DllImport, PathMatchSpecW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR>, 8
        if (_WIN32_IE ge _WIN32_IE_IE70)
          ; Flags for PathMatchSpecEx
          PMSF_NORMAL equ 00000000h
          PMSF_MULTIPLE equ 00000001h
          PMSF_DONT_STRIP_SPACES equ 00010000h; modifies either of the above

          @DefProto DllImport, PathMatchSpecExA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :DWORD>, 12
          @DefProto DllImport, PathMatchSpecExW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :DWORD>, 12
        endif
        ; _WIN32_IE_IE70
        @DefProto DllImport, PathParseIconLocationA, WIN_STD_CALL_CONV,, <:LPSTR>, 4
        @DefProto DllImport, PathParseIconLocationW, WIN_STD_CALL_CONV,, <:LPWSTR>, 4
        @DefProto DllImport, PathQuoteSpacesA, WIN_STD_CALL_CONV,, <:LPSTR>, 4
        @DefProto DllImport, PathQuoteSpacesW, WIN_STD_CALL_CONV,, <:LPWSTR>, 4
        @DefProto DllImport, PathRelativePathToA, WIN_STD_CALL_CONV,, <:LPSTR, :LPCSTR, :DWORD, :LPCSTR, :DWORD>, 20
        @DefProto DllImport, PathRelativePathToW, WIN_STD_CALL_CONV,, <:LPWSTR, :LPCWSTR, :DWORD, :LPCWSTR, :DWORD>, 20
        @DefProto DllImport, PathRemoveArgsA, WIN_STD_CALL_CONV,, <:LPSTR>, 4
        @DefProto DllImport, PathRemoveArgsW, WIN_STD_CALL_CONV,, <:LPWSTR>, 4
        @DefProto DllImport, PathRemoveBackslashA, WIN_STD_CALL_CONV,, <:LPSTR>, 4
        @DefProto DllImport, PathRemoveBackslashW, WIN_STD_CALL_CONV,, <:LPWSTR>, 4
        ifdef UNICODE
          PathRemoveBackslash equ <PathRemoveBackslashW>
        else
          PathRemoveBackslash equ <PathRemoveBackslashA>
        endif
        ; !UNICODE
        @DefProto DllImport, PathRemoveBlanksA, WIN_STD_CALL_CONV,, <:LPSTR>, 4
        @DefProto DllImport, PathRemoveBlanksW, WIN_STD_CALL_CONV,, <:LPWSTR>, 4
        @DefProto DllImport, PathRemoveExtensionA, WIN_STD_CALL_CONV,, <:LPSTR>, 4
        @DefProto DllImport, PathRemoveExtensionW, WIN_STD_CALL_CONV,, <:LPWSTR>, 4
        @DefProto DllImport, PathRemoveFileSpecA, WIN_STD_CALL_CONV,, <:LPSTR>, 4
        @DefProto DllImport, PathRemoveFileSpecW, WIN_STD_CALL_CONV,, <:LPWSTR>, 4
        @DefProto DllImport, PathRenameExtensionA, WIN_STD_CALL_CONV,, <:LPSTR, :LPCSTR>, 8
        @DefProto DllImport, PathRenameExtensionW, WIN_STD_CALL_CONV,, <:LPWSTR, :LPCWSTR>, 8
        @DefProto DllImport, PathSearchAndQualifyA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPSTR, :UINT>, 12
        @DefProto DllImport, PathSearchAndQualifyW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPWSTR, :UINT>, 12
        @DefProto DllImport, PathSetDlgItemPathA, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LPCSTR>, 12
        @DefProto DllImport, PathSetDlgItemPathW, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LPCWSTR>, 12
        ifdef USE_STRICT_CONST
          @DefProto DllImport, PathSkipRootA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
          @DefProto DllImport, PathSkipRootW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
          ifdef UNICODE
            PathSkipRoot equ <PathSkipRootW>
          else
            PathSkipRoot equ <PathSkipRootA>
          endif
          ; !UNICODE
        else
          @DefProto DllImport, PathSkipRootA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
          @DefProto DllImport, PathSkipRootW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
          ifdef UNICODE
            PathSkipRoot equ <PathSkipRootW>
          else
            PathSkipRoot equ <PathSkipRootA>
          endif
          ; !UNICODE
        endif
        @DefProto DllImport, PathStripPathA, WIN_STD_CALL_CONV,, <:LPSTR>, 4
        @DefProto DllImport, PathStripPathW, WIN_STD_CALL_CONV,, <:LPWSTR>, 4
        ifdef UNICODE
          PathStripPath equ <PathStripPathW>
        else
          PathStripPath equ <PathStripPathA>
        endif
        ; !UNICODE
        @DefProto DllImport, PathStripToRootA, WIN_STD_CALL_CONV,, <:LPSTR>, 4
        @DefProto DllImport, PathStripToRootW, WIN_STD_CALL_CONV,, <:LPWSTR>, 4
        ifdef UNICODE
          PathStripToRoot equ <PathStripToRootW>
        else
          PathStripToRoot equ <PathStripToRootA>
        endif
        ; !UNICODE
        @DefProto DllImport, PathUnquoteSpacesA, WIN_STD_CALL_CONV,, <:LPSTR>, 4
        @DefProto DllImport, PathUnquoteSpacesW, WIN_STD_CALL_CONV,, <:LPWSTR>, 4
        @DefProto DllImport, PathMakeSystemFolderA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
        @DefProto DllImport, PathMakeSystemFolderW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
        ifdef UNICODE
          PathMakeSystemFolder equ <PathMakeSystemFolderW>
        else
          PathMakeSystemFolder equ <PathMakeSystemFolderA>
        endif
        ; !UNICODE
        @DefProto DllImport, PathUnmakeSystemFolderA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
        @DefProto DllImport, PathUnmakeSystemFolderW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
        ifdef UNICODE
          PathUnmakeSystemFolder equ <PathUnmakeSystemFolderW>
        else
          PathUnmakeSystemFolder equ <PathUnmakeSystemFolderA>
        endif
        ; !UNICODE
        @DefProto DllImport, PathIsSystemFolderA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD>, 8
        @DefProto DllImport, PathIsSystemFolderW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD>, 8
        ifdef UNICODE
          PathIsSystemFolder equ <PathIsSystemFolderW>
        else
          PathIsSystemFolder equ <PathIsSystemFolderA>
        endif
        ; !UNICODE
        @DefProto DllImport, PathUndecorateA, WIN_STD_CALL_CONV,, <:LPSTR>, 4
        @DefProto DllImport, PathUndecorateW, WIN_STD_CALL_CONV,, <:LPWSTR>, 4
        ifdef UNICODE
          PathUndecorate equ <PathUndecorateW>
        else
          PathUndecorate equ <PathUndecorateA>
        endif
        ; !UNICODE
        @DefProto DllImport, PathUnExpandEnvStringsA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPSTR, :UINT>, 12
        @DefProto DllImport, PathUnExpandEnvStringsW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPWSTR, :UINT>, 12
        ifdef UNICODE
          PathUnExpandEnvStrings equ <PathUnExpandEnvStringsW>
        else
          PathUnExpandEnvStrings equ <PathUnExpandEnvStringsA>
        endif
        ; !UNICODE
        ifdef UNICODE
          PathAppend equ <PathAppendW>
          PathCanonicalize equ <PathCanonicalizeW>
          PathCompactPath equ <PathCompactPathW>
          PathCompactPathEx equ <PathCompactPathExW>
          PathCommonPrefix equ <PathCommonPrefixW>
          PathFindOnPath equ <PathFindOnPathW>
          PathGetCharType equ <PathGetCharTypeW>
          PathIsContentType equ <PathIsContentTypeW>
          PathIsHTMLFile equ <PathIsHTMLFileW>
          PathMakePretty equ <PathMakePrettyW>
          PathMatchSpec equ <PathMatchSpecW>
          if (_WIN32_IE ge _WIN32_IE_IE70)
            PathMatchSpecEx equ <PathMatchSpecExW>
          endif
          ; _WIN32_IE_IE70
          PathParseIconLocation equ <PathParseIconLocationW>
          PathQuoteSpaces equ <PathQuoteSpacesW>
          PathRelativePathTo equ <PathRelativePathToW>
          PathRemoveArgs equ <PathRemoveArgsW>
          PathRemoveBlanks equ <PathRemoveBlanksW>
          PathRemoveExtension equ <PathRemoveExtensionW>
          PathRemoveFileSpec equ <PathRemoveFileSpecW>
          PathRenameExtension equ <PathRenameExtensionW>
          PathSearchAndQualify equ <PathSearchAndQualifyW>
          PathSetDlgItemPath equ <PathSetDlgItemPathW>
          PathUnquoteSpaces equ <PathUnquoteSpacesW>
        else
          PathAppend equ <PathAppendA>
          PathCanonicalize equ <PathCanonicalizeA>
          PathCompactPath equ <PathCompactPathA>
          PathCompactPathEx equ <PathCompactPathExA>
          PathCommonPrefix equ <PathCommonPrefixA>
          PathFindOnPath equ <PathFindOnPathA>
          PathGetCharType equ <PathGetCharTypeA>
          PathIsContentType equ <PathIsContentTypeA>
          PathIsHTMLFile equ <PathIsHTMLFileA>
          PathMakePretty equ <PathMakePrettyA>
          PathMatchSpec equ <PathMatchSpecA>
          if (_WIN32_IE ge _WIN32_IE_IE70)
            PathMatchSpecEx equ <PathMatchSpecExA>
          endif
          ; _WIN32_IE_IE70
          PathParseIconLocation equ <PathParseIconLocationA>
          PathQuoteSpaces equ <PathQuoteSpacesA>
          PathRelativePathTo equ <PathRelativePathToA>
          PathRemoveArgs equ <PathRemoveArgsA>
          PathRemoveBlanks equ <PathRemoveBlanksA>
          PathRemoveExtension equ <PathRemoveExtensionA>
          PathRemoveFileSpec equ <PathRemoveFileSpecA>
          PathRenameExtension equ <PathRenameExtensionA>
          PathSearchAndQualify equ <PathSearchAndQualifyA>
          PathSetDlgItemPath equ <PathSetDlgItemPathA>
          PathUnquoteSpaces equ <PathUnquoteSpacesA>
        endif
        ; _WIN32_IE_IE60
        ; _WIN32_IE_IE70
        URL_SCHEME typedef SDWORD
        URL_SCHEME_INVALID equ -1
        URL_SCHEME_UNKNOWN equ 0
        URL_SCHEME_FTP equ 1
        URL_SCHEME_HTTP equ 2
        URL_SCHEME_GOPHER equ 3
        URL_SCHEME_MAILTO equ 4
        URL_SCHEME_NEWS equ 5
        URL_SCHEME_NNTP equ 6
        URL_SCHEME_TELNET equ 7
        URL_SCHEME_WAIS equ 8
        URL_SCHEME_FILE equ 9
        URL_SCHEME_MK equ 10
        URL_SCHEME_HTTPS equ 11
        URL_SCHEME_SHELL equ 12
        URL_SCHEME_SNEWS equ 13
        URL_SCHEME_LOCAL equ 14
        URL_SCHEME_JAVASCRIPT equ 15
        URL_SCHEME_VBSCRIPT equ 16
        URL_SCHEME_ABOUT equ 17
        URL_SCHEME_RES equ 18
        if (_WIN32_IE ge _WIN32_IE_IE60)
          URL_SCHEME_MSSHELLROOTED equ 19
          URL_SCHEME_MSSHELLIDLIST equ 20
          URL_SCHEME_MSHELP equ 21
        endif
        ; _WIN32_IE_IE60
        if (_WIN32_IE ge _WIN32_IE_IE70)
          URL_SCHEME_MSSHELLDEVICE equ 22
          URL_SCHEME_WILDCARD equ 23
        endif
        ; _WIN32_IE_IE70
        if (NTDDI_VERSION ge NTDDI_VISTA)
          URL_SCHEME_SEARCH_MS equ 24
        endif
        if (NTDDI_VERSION ge NTDDI_VISTASP1)
          URL_SCHEME_SEARCH equ 25
        endif
        if (NTDDI_VERSION ge NTDDI_WIN7)
          URL_SCHEME_KNOWNFOLDER equ 26
        endif
        URL_SCHEME_MAXVALUE equ 27

        URL_PART typedef SDWORD
        URL_PART_NONE equ 0
        URL_PART_SCHEME equ 1
        URL_PART_HOSTNAME equ 2
        URL_PART_USERNAME equ 3
        URL_PART_PASSWORD equ 4
        URL_PART_PORT equ 5
        URL_PART_QUERY equ 6

        URLIS typedef SDWORD
        URLIS_URL equ 0
        URLIS_OPAQUE equ 1
        URLIS_NOHISTORY equ 2
        URLIS_FILEURL equ 3
        URLIS_APPLIABLE equ 4
        URLIS_DIRECTORY equ 5
        URLIS_HASQUERY equ 6

        URL_UNESCAPE equ 10000000h
        URL_ESCAPE_UNSAFE equ 20000000h
        URL_PLUGGABLE_PROTOCOL equ 40000000h
        URL_WININET_COMPATIBILITY equ 80000000h
        URL_DONT_ESCAPE_EXTRA_INFO equ 02000000h
        URL_DONT_UNESCAPE_EXTRA_INFO equ <URL_DONT_ESCAPE_EXTRA_INFO>
        URL_BROWSER_MODE equ <URL_DONT_ESCAPE_EXTRA_INFO>
        URL_ESCAPE_SPACES_ONLY equ 04000000h
        URL_DONT_SIMPLIFY equ 08000000h
        URL_NO_META equ <URL_DONT_SIMPLIFY>
        URL_UNESCAPE_INPLACE equ 00100000h
        URL_CONVERT_IF_DOSPATH equ 00200000h
        URL_UNESCAPE_HIGH_ANSI_ONLY equ 00400000h
        URL_INTERNAL_PATH equ 00800000h; Will escape #'s in paths

        URL_FILE_USE_PATHURL equ 00010000h
        if (_WIN32_IE ge _WIN32_IE_IE60SP2)
          URL_DONT_UNESCAPE equ 00020000h; Do not unescape the path/url at all

        endif
        ; _WIN32_IE_IE60SP2
        if (NTDDI_VERSION ge NTDDI_WIN7)
          URL_ESCAPE_AS_UTF8 equ 00040000h; Percent-encode all non-ASCII characters as their UTF-8 equivalents.

        endif
        ; (NTDDI_VERSION >= NTDDI_WIN7)
        if (NTDDI_VERSION ge NTDDI_WIN8)
          URL_UNESCAPE_AS_UTF8 equ <URL_ESCAPE_AS_UTF8>
          URL_ESCAPE_ASCII_URI_COMPONENT equ 00080000h; Percent-encode all ASCII characters outside of the unreserved set from URI RFC 3986 (a-zA-Z0-9-.~_) (i.e.) No need for URL_ESCAPE_PERCENT along with this.

          URL_ESCAPE_URI_COMPONENT equ <(URL_ESCAPE_ASCII_URI_COMPONENT or URL_ESCAPE_AS_UTF8)>
          URL_UNESCAPE_URI_COMPONENT equ <URL_UNESCAPE_AS_UTF8>
        endif
        ; (NTDDI_VERSION >= NTDDI_WIN8)
        URL_ESCAPE_PERCENT equ 00001000h
        URL_ESCAPE_SEGMENT_ONLY equ 00002000h; Treat the entire URL param as one URL segment.

        URL_PARTFLAG_KEEPSCHEME equ 00000001h
        URL_APPLY_DEFAULT equ 00000001h
        URL_APPLY_GUESSSCHEME equ 00000002h
        URL_APPLY_GUESSFILE equ 00000004h
        URL_APPLY_FORCEAPPLY equ 00000008h
        @DefProto DllImport, UrlCompareA, WIN_STD_CALL_CONV,, <:PCSTR, :PCSTR, :BOOL>, 12
        @DefProto DllImport, UrlCompareW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR, :BOOL>, 12
        @DefProto DllImport, UrlCombineA, WIN_STD_CALL_CONV,, <:PCSTR, :PCSTR, :PSTR, :ptr DWORD, :DWORD>, 20
        @DefProto DllImport, UrlCombineW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR, :PWSTR, :ptr DWORD, :DWORD>, 20
        @DefProto DllImport, UrlCanonicalizeA, WIN_STD_CALL_CONV,, <:PCSTR, :PSTR, :ptr DWORD, :DWORD>, 16
        @DefProto DllImport, UrlCanonicalizeW, WIN_STD_CALL_CONV,, <:PCWSTR, :PWSTR, :ptr DWORD, :DWORD>, 16
        @DefProto DllImport, UrlIsOpaqueA, WIN_STD_CALL_CONV,, <:PCSTR>, 4
        @DefProto DllImport, UrlIsOpaqueW, WIN_STD_CALL_CONV,, <:PCWSTR>, 4
        @DefProto DllImport, UrlIsNoHistoryA, WIN_STD_CALL_CONV,, <:PCSTR>, 4
        @DefProto DllImport, UrlIsNoHistoryW, WIN_STD_CALL_CONV,, <:PCWSTR>, 4
        UrlIsFileUrlA macro pszURL
          exitm <UrlIsA (pszURL, URLIS_FILEURL)>
        endm
        UrlIsFileUrlW macro pszURL
          exitm <UrlIsW (pszURL, URLIS_FILEURL)>
        endm
        @DefProto DllImport, UrlIsA, WIN_STD_CALL_CONV,, <:PCSTR, :URLIS>, 8
        @DefProto DllImport, UrlIsW, WIN_STD_CALL_CONV,, <:PCWSTR, :URLIS>, 8
        @DefProto DllImport, UrlGetLocationA, WIN_STD_CALL_CONV,, <:PCSTR>, 4
        @DefProto DllImport, UrlGetLocationW, WIN_STD_CALL_CONV,, <:PCWSTR>, 4
        @DefProto DllImport, UrlUnescapeA, WIN_STD_CALL_CONV,, <:PSTR, :PSTR, :ptr DWORD, :DWORD>, 16
        @DefProto DllImport, UrlUnescapeW, WIN_STD_CALL_CONV,, <:PWSTR, :PWSTR, :ptr DWORD, :DWORD>, 16
        @DefProto DllImport, UrlEscapeA, WIN_STD_CALL_CONV,, <:PCSTR, :PSTR, :ptr DWORD, :DWORD>, 16
        @DefProto DllImport, UrlEscapeW, WIN_STD_CALL_CONV,, <:PCWSTR, :PWSTR, :ptr DWORD, :DWORD>, 16
        @DefProto DllImport, UrlCreateFromPathA, WIN_STD_CALL_CONV,, <:PCSTR, :PSTR, :ptr DWORD, :DWORD>, 16
        @DefProto DllImport, UrlCreateFromPathW, WIN_STD_CALL_CONV,, <:PCWSTR, :PWSTR, :ptr DWORD, :DWORD>, 16
        @DefProto DllImport, PathCreateFromUrlA, WIN_STD_CALL_CONV,, <:PCSTR, :PSTR, :ptr DWORD, :DWORD>, 16
        @DefProto DllImport, PathCreateFromUrlW, WIN_STD_CALL_CONV,, <:PCWSTR, :PWSTR, :ptr DWORD, :DWORD>, 16
        if (_WIN32_IE ge _WIN32_IE_IE70)
          @DefProto DllImport, PathCreateFromUrlAlloc, WIN_STD_CALL_CONV,, <:PCWSTR, :ptr PWSTR, :DWORD>, 12
        endif
        ; _WIN32_IE_IE70
        @DefProto DllImport, UrlHashA, WIN_STD_CALL_CONV,, <:PCSTR, :ptr BYTE, :DWORD>, 12
        @DefProto DllImport, UrlHashW, WIN_STD_CALL_CONV,, <:PCWSTR, :ptr BYTE, :DWORD>, 12
        @DefProto DllImport, UrlGetPartW, WIN_STD_CALL_CONV,, <:PCWSTR, :PWSTR, :ptr DWORD, :DWORD, :DWORD>, 20
        @DefProto DllImport, UrlGetPartA, WIN_STD_CALL_CONV,, <:PCSTR, :PSTR, :ptr DWORD, :DWORD, :DWORD>, 20
        @DefProto DllImport, UrlApplySchemeA, WIN_STD_CALL_CONV,, <:PCSTR, :PSTR, :ptr DWORD, :DWORD>, 16
        @DefProto DllImport, UrlApplySchemeW, WIN_STD_CALL_CONV,, <:PCWSTR, :PWSTR, :ptr DWORD, :DWORD>, 16
        @DefProto DllImport, HashData, WIN_STD_CALL_CONV,, <:ptr BYTE, :DWORD, :ptr BYTE, :DWORD>, 16
        @DefProto DllImport, UrlFixupW, WIN_STD_CALL_CONV,, <:PCWSTR, :PWSTR, :DWORD>, 12
        ifdef UNICODE
          UrlCompare equ <UrlCompareW>
          UrlCombine equ <UrlCombineW>
          UrlCanonicalize equ <UrlCanonicalizeW>
          UrlIsOpaque equ <UrlIsOpaqueW>
          UrlIsFileUrl equ <UrlIsFileUrlW>
          UrlGetLocation equ <UrlGetLocationW>
          UrlUnescape equ <UrlUnescapeW>
          UrlEscape equ <UrlEscapeW>
          UrlCreateFromPath equ <UrlCreateFromPathW>
          PathCreateFromUrl equ <PathCreateFromUrlW>
          UrlHash equ <UrlHashW>
          UrlGetPart equ <UrlGetPartW>
          UrlApplyScheme equ <UrlApplySchemeW>
          UrlIs equ <UrlIsW>
          UrlFixup equ <UrlFixupW>
        else
        ;!UNICODE
          UrlCompare equ <UrlCompareA>
          UrlCombine equ <UrlCombineA>
          UrlCanonicalize equ <UrlCanonicalizeA>
          UrlIsOpaque equ <UrlIsOpaqueA>
          UrlIsFileUrl equ <UrlIsFileUrlA>
          UrlGetLocation equ <UrlGetLocationA>
          UrlUnescape equ <UrlUnescapeA>
          UrlEscape equ <UrlEscapeA>
          UrlCreateFromPath equ <UrlCreateFromPathA>
          PathCreateFromUrl equ <PathCreateFromUrlA>
          UrlHash equ <UrlHashA>
          UrlGetPart equ <UrlGetPartA>
          UrlApplyScheme equ <UrlApplySchemeA>
          UrlIs equ <UrlIsA>
          ; no UrlFixupA
        endif
        ;UNICODE
        UrlEscapeSpaces macro pszUrl, pszEscaped, pcchEscaped
          exitm <UrlCanonicalize (pszUrl, pszEscaped, pcchEscaped, URL_ESCAPE_SPACES_ONLY or URL_DONT_ESCAPE_EXTRA_INFO)>
        endm
        UrlUnescapeInPlace macro pszUrl, dwFlags
          exitm <UrlUnescape (pszUrl, NULL, NULL, dwFlags or URL_UNESCAPE_INPLACE)>
        endm
        PARSEDURLA struct
          cbSize DWORD ?
          ; Pointers into the buffer that was provided to ParseURL
          pszProtocol =POINTER ?
          cchProtocol DWORD ?
          pszSuffix =POINTER ?
          cchSuffix DWORD ?
          nScheme DWORD ?
          ; One of URL_SCHEME_*
        PARSEDURLA ends
        tagPARSEDURLA typedef PARSEDURLA
        PPARSEDURLA typedef ptr PARSEDURLA
        PARSEDURLW struct
          cbSize DWORD ?
          ; Pointers into the buffer that was provided to ParseURL
          pszProtocol =POINTER ?
          cchProtocol DWORD ?
          pszSuffix =POINTER ?
          cchSuffix DWORD ?
          nScheme DWORD ?
          ; One of URL_SCHEME_*
        PARSEDURLW ends
        tagPARSEDURLW typedef PARSEDURLW
        PPARSEDURLW typedef ptr PARSEDURLW
        ifdef UNICODE
          PARSEDURL typedef PARSEDURLW
          PPARSEDURL typedef PPARSEDURLW
        else
          PARSEDURL typedef PARSEDURLA
          PPARSEDURL typedef PPARSEDURLA
        endif
        ; UNICODE
        @DefProto DllImport, ParseURLA, WIN_STD_CALL_CONV,, <:LPCSTR, :ptr PARSEDURLA>, 8
        @DefProto DllImport, ParseURLW, WIN_STD_CALL_CONV,, <:LPCWSTR, :ptr PARSEDURLW>, 8
        ifdef UNICODE
          ParseURL equ <ParseURLW>
        else
          ParseURL equ <ParseURLA>
        endif
        ; !UNICODE
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
    endif
    ;  NO_SHLWAPI_PATH
    ifndef NO_SHLWAPI_REG
      ;=============== Registry Routines ===================================
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        ; SHDeleteEmptyKey mimics RegDeleteKey as it behaves on NT.
        ; SHDeleteKey mimics RegDeleteKey as it behaves on Win95.
        @DefProto DllImport, SHDeleteEmptyKeyA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR>, 8
        @DefProto DllImport, SHDeleteEmptyKeyW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR>, 8
        ifdef UNICODE
          SHDeleteEmptyKey equ <SHDeleteEmptyKeyW>
        else
          SHDeleteEmptyKey equ <SHDeleteEmptyKeyA>
        endif
        ; !UNICODE
        @DefProto DllImport, SHDeleteKeyA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR>, 8
        @DefProto DllImport, SHDeleteKeyW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR>, 8
        ifdef UNICODE
          SHDeleteKey equ <SHDeleteKeyW>
        else
          SHDeleteKey equ <SHDeleteKeyA>
        endif
        ; !UNICODE
        @DefProto DllImport, SHRegDuplicateHKey, WIN_STD_CALL_CONV,, <:HKEY>, 4
        ; These functions open the key, get/set/delete the value, then close
        ; the key.
        @DefProto DllImport, SHDeleteValueA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :LPCSTR>, 12
        @DefProto DllImport, SHDeleteValueW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :LPCWSTR>, 12
        ifdef UNICODE
          SHDeleteValue equ <SHDeleteValueW>
        else
          SHDeleteValue equ <SHDeleteValueA>
        endif
        ; !UNICODE
        @DefProto DllImport, SHGetValueA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :LPCSTR, :ptr DWORD, :ptr, :ptr DWORD>, 24
        @DefProto DllImport, SHGetValueW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :LPCWSTR, :ptr DWORD, :ptr, :ptr DWORD>, 24
        ifdef UNICODE
          SHGetValue equ <SHGetValueW>
        else
          SHGetValue equ <SHGetValueA>
        endif
        ; !UNICODE
        @DefProto DllImport, SHSetValueA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :LPCSTR, :DWORD, :LPCVOID, :DWORD>, 24
        @DefProto DllImport, SHSetValueW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :LPCWSTR, :DWORD, :LPCVOID, :DWORD>, 24
        ifdef UNICODE
          SHSetValue equ <SHSetValueW>
        else
          SHSetValue equ <SHSetValueA>
        endif
        ; !UNICODE
        if (_WIN32_IE ge 0602h)
          ; SRRF - Shell Registry Routine Flags (for SHRegGetValue)
          SRRF typedef SDWORD
          SRRF_RT_REG_NONE equ 00000001h; restrict type to REG_NONE      (other data types will not return ERROR_SUCCESS)

          SRRF_RT_REG_SZ equ 00000002h; restrict type to REG_SZ        (other data types will not return ERROR_SUCCESS) (automatically converts REG_EXPAND_SZ to REG_SZ unless SRRF_NOEXPAND is specified)

          SRRF_RT_REG_EXPAND_SZ equ 00000004h; restrict type to REG_EXPAND_SZ (other data types will not return ERROR_SUCCESS) (must specify SRRF_NOEXPAND or SHRegGetValue will fail with ERROR_INVALID_PARAMETER)

          SRRF_RT_REG_BINARY equ 00000008h; restrict type to REG_BINARY    (other data types will not return ERROR_SUCCESS)

          SRRF_RT_REG_DWORD equ 00000010h; restrict type to REG_DWORD     (other data types will not return ERROR_SUCCESS)

          SRRF_RT_REG_MULTI_SZ equ 00000020h; restrict type to REG_MULTI_SZ  (other data types will not return ERROR_SUCCESS)

          SRRF_RT_REG_QWORD equ 00000040h; restrict type to REG_QWORD     (other data types will not return ERROR_SUCCESS)

          SRRF_RT_DWORD equ <(SRRF_RT_REG_BINARY or SRRF_RT_REG_DWORD)>; restrict type to *32-bit* SRRF_RT_REG_BINARY or SRRF_RT_REG_DWORD (other data types will not return ERROR_SUCCESS)

          SRRF_RT_QWORD equ <(SRRF_RT_REG_BINARY or SRRF_RT_REG_QWORD)>; restrict type to *64-bit* SRRF_RT_REG_BINARY or SRRF_RT_REG_DWORD (other data types will not return ERROR_SUCCESS)

          SRRF_RT_ANY equ 0000ffffh; no type restriction

          SRRF_RM_ANY equ 00000000h; no mode restriction (default is to allow any mode)

          SRRF_RM_NORMAL equ 00010000h; restrict system startup mode to "normal boot"               (other startup modes will not return ERROR_SUCCESS)

          SRRF_RM_SAFE equ 00020000h; restrict system startup mode to "safe mode"                 (other startup modes will not return ERROR_SUCCESS)

          SRRF_RM_SAFENETWORK equ 00040000h; restrict system startup mode to "safe mode with networking" (other startup modes will not return ERROR_SUCCESS)

          SRRF_NOEXPAND equ 10000000h; do not automatically expand environment strings if value is of type REG_EXPAND_SZ

          SRRF_ZEROONFAILURE equ 20000000h; if pvData is not NULL, set content to all zeros on failure

          SRRF_NOVIRT equ 40000000h; if the requested key is virtualized, then fail with ERROR_FILE_NOT_FOUND

          ; Function:
          ;  SHRegGetValue()
          ; Purpose:
          ;  Gets a registry value.  SHRegGetValue() provides the following benefits:
          ;  - data type checking
          ;  - boot mode checking
          ;  - auto-expansion of REG_EXPAND_SZ data
          ;  - guaranteed NULL termination of REG_SZ, REG_EXPAND_SZ, REG_MULTI_SZ data
          ; Parameters:
          ;  hkey        - handle to a currently open key.
          ;  pszSubKey   - pointer to a null-terminated string specifying the relative
          ;                path from hkey to one of its subkeys from which the data is
          ;                to be retrieved.  this will be opened with KEY_READ sam.
          ;                Note1: pszSubKey can be NULL or "".  In either of these two
          ;                       cases, the data is retrieved from the hkey itself.
          ;                Note2: *** PERF ***
          ;                       If pszSubKey is not NULL or "", the subkey will be
          ;                       automatically be opened and closed by this routine
          ;                       in order to obtain the data.  If you are retrieving
          ;                       multiple values from the same subkey, it is better
          ;                       for perf to open the subkey via RegOpenKeyEx() prior
          ;                       to calling this method, and using this opened key as
          ;                       hkey with pszSubKey set to NULL.
          ;  pszValue    - pointer to a null-terminated string specifying the name of
          ;                the value to query for data
          ;                Note1: pszValue can be NULL or "".  In either of these two
          ;                       cases, the data is retrieved from the unnamed or
          ;                       default value.
          ;  srrfFlags   - bitwise or of SRRF_ flags, which cannot be 0:  at least one
          ;                type restriction must be specified (SRRF_RT_...), or if any
          ;                type is desired then SRRF_RT_ANY can be specified
          ;                Note1: SRRF_RT_ANY will allow any data type to be returned.
          ;                Note2: The following two type restrictions have special
          ;                       handling semantics:
          ;                         SRRF_RT_DWORD == SRRF_RT_REG_BINARY | SRRF_RT_REG_DWORD
          ;                         SRRF_RT_QWORD == SRRF_RT_REG_BINARY | SRRF_RT_REG_QWORD
          ;                       If either of these are specified, with no other type
          ;                       restrictions, then in the prior case the restriction
          ;                       will limit "valid" returned data to either REG_DWORD
          ;                       or 32-bit REG_BINARY data, and in the latter case
          ;                       the restriction will limit "valid" returned data to
          ;                       either REG_QWORD or 64-bit REG_BINARY.
          ;  pdwType     - pointer to a dword which receives a code indicating the
          ;                type of data stored in the specified value
          ;                Note1: pdwType can be NULL if no type information is wanted
          ;                Note2: If pdwType is not NULL, and the SRRF_NOEXPAND flag
          ;                       has not been set, data types of REG_EXPAND_SZ will
          ;                       be returned as REG_SZ since they are automatically
          ;                       expanded in this method.
          ;  pvData      - pointer to a buffer that receives the value's data
          ;                Note1: pvData can be NULL if the data is not required.
          ;                       pvData is usually NULL if doing either a simple
          ;                       existence test, or if interested in the size only.
          ;                Note2: *** PERF ***
          ;                       Reference 'perf' note for pcbData.
          ;  pcbData     - when pvData is NULL:
          ;                  optional pointer to a dword that receives a size in bytes
          ;                  which would be sufficient to hold the registry data (note
          ;                  this size is not guaranteed to be exact, merely sufficient)
          ;                when pvData is not NULL:
          ;                  required pointer to a dword that specifies the size in
          ;                  bytes of the buffer pointed to by the pvData parameter
          ;                  and receives a size in bytes of:
          ;                  a) the number of bytes read into pvData on ERROR_SUCCESS
          ;                     (note this size is guaranteed to be exact)
          ;                  b) the number of bytes which would be sufficient to hold
          ;                     the registry data on ERROR_MORE_DATA -- pvData was of
          ;                     insufficient size (note this size is not guaranteed to
          ;                     be exact, merely sufficient)
          ;                Note1: pcbData can be NULL only if pvData is NULL.
          ;                Note2: *** PERF ***
          ;                       The potential for an 'extra' call to the registry to
          ;                       read (or re-read) in the data exists when the data
          ;                       type is REG_EXPAND_SZ and the SRRF_NOEXPAND flag has
          ;                       not been set.  The following conditions will result
          ;                       in this 'extra' read operation:
          ;                       i)  when pvData is NULL and pcbData is not NULL
          ;                           we must read in the data from the registry
          ;                           anyway in order to obtain the string and perform
          ;                           an expand on it to obtain and return the total
          ;                           required size in pcbData
          ;                       ii) when pvData is not NULL but is of insufficient
          ;                           size we must re-read in the data from the
          ;                           registry in order to obtain the entire string
          ;                           and perform an expand on it to obtain and return
          ;                           the total required size in pcbData
          ; Remarks:
          ;  The key identified by hkey must have been opened with KEY_QUERY_VALUE
          ;  access.  If pszSubKey is not NULL or "", it must be able to be opened
          ;  with KEY_QUERY_VALUE access in the current calling context.
          ;  If the data type is REG_SZ, REG_EXPAND_SZ or REG_MULTI_SZ then any
          ;  returned data is guaranteed to take into account proper null termination.
          ;  For example:  if pcbData is not NULL, its returned size will include the
          ;  bytes for a null terminator  if pvData is not NULL, its returned data
          ;  will be properly null terminated.
          ;  If the data type is REG_EXPAND_SZ, then unless the SRRF_NOEXPAND flag
          ;  is set the data will be automatically expanded prior to being returned.
          ;  For example:  if pdwType is not NULL, its returned type will be changed
          ;  to REG_SZ,  if pcbData is not NULL, its returned size will include the
          ;  bytes for a properly expanded string.  if pvData is not NULL, its
          ;  returned data will be the expanded version of the string.
          ;  Reference MSDN documentation for RegQueryValueEx() for more information
          ;  of the behaviour when pdwType, pvData, and/or pcbData are equal to NULL.
          ; Return Values:
          ;  If the function succeeds, the return value is ERROR_SUCCESS and all out
          ;  parameters requested (pdwType, pvData, pcbData) are valid.
          ;  If the function fails due to insufficient space in a provided non-NULL
          ;  pvData, the return value is ERROR_MORE_DATA and only pdwType and pcbData
          ;  can contain valid data.  The content of pvData in this case is undefined.
          ; Examples:
          ;  1) read REG_SZ (or REG_EXPAND_SZ as REG_SZ) "string" data from the (default) value of an open hkey
          ;      TCHAR szData[128]
          ;      DWORD cbData = sizeof(pszData)
          ;      if (ERROR_SUCCESS == SHRegGetValue(hkey, NULL, NULL, SRRF_RT_REG_SZ, NULL, szData, &cbData))
          ;      {
          ;          // use sz (successful read)
          ;      }
          ;  2) read REG_SZ (or REG_EXPAND_SZ as REG_SZ) "string" data of unknown size from the "MyValue" value of an open hkey
          ;      DWORD cbData
          ;      if (ERROR_SUCCESS == SHRegGetValue(hkey, NULL, TEXT("MyValue"), SRRF_RT_REG_SZ, NULL, NULL, &cbData))
          ;      {
          ;          TCHAR *pszData = new TCHAR[cbData/sizeof(TCHAR)]
          ;          if (pszData)
          ;          {
          ;              if (ERROR_SUCCESS == SHRegGetValue(hkey, NULL, TEXT("MyValue"), SRRF_RT_REG_SZ, NULL, pszData, &cbData))
          ;              {
          ;                  // use pszData (successful read)
          ;              }
          ;              delete[] pszData
          ;          }
          ;      }
          ;  3) read "dword" data from the "MyValue" value of the "MySubKey" subkey of an open hkey
          ;      DWORD dwData
          ;      DWORD cbData = sizeof(dwData)
          ;      if (ERROR_SUCCESS == SHRegGetValue(hkey, TEXT("MySubKey"), TEXT("MyValue"), SRRF_RT_REG_DWORD, NULL, &dwData, &cbData))
          ;      {
          ;          // use dwData (successful read)
          ;      }
          ;  4) read "dword" data from the "MyValue" value of the "MySubKey" subkey of an open hkey (32-bit binary data also ok)
          ;      DWORD dwData
          ;      DWORD cbData = sizeof(dwData)
          ;      if (ERROR_SUCCESS == SHRegGetValue(hkey, TEXT("MySubKey"), TEXT("MyValue"), SRRF_RT_DWORD, NULL, &dwData, &cbData))
          ;      {
          ;          // use dwData (successful read)
          ;      }
          ;  5) determine existence of "MyValue" value of an open hkey
          ;      BOOL bExists = ERROR_SUCCESS == SHRegGetValue(hkey, NULL, TEXT("MyValue"), SRRF_RT_ANY, NULL, NULL, NULL)
          @DefProto DllImport, SHRegGetValueA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :LPCSTR, :SRRF, :ptr DWORD, :ptr, :ptr DWORD>, 28
          @DefProto DllImport, SHRegGetValueW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :LPCWSTR, :SRRF, :ptr DWORD, :ptr, :ptr DWORD>, 28
          ifdef UNICODE
            SHRegGetValue equ <SHRegGetValueW>
          else
            SHRegGetValue equ <SHRegGetValueA>
          endif
          ; !UNICODE
          @DefProto DllImport, SHRegSetValue, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :LPCWSTR, :SRRF, :DWORD, :LPCVOID, :DWORD>, 28
          @DefProto DllImport, SHRegGetValueFromHKCUHKLM, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR, :SRRF, :ptr DWORD, :ptr, :ptr DWORD>, 24
          @DefProto DllImport, SHRegGetBoolValueFromHKCUHKLM, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR, :BOOL>, 12
        endif
        ; (_WIN32_IE >= 0x0602)
        ; These functions behave just like RegQueryValueEx(), except if the data
        ; type is REG_SZ, REG_EXPAND_SZ or REG_MULTI_SZ then the string is
        ; guaranteed to be properly null terminated.
        ; Additionally, if the data type is REG_EXPAND_SZ these functions will
        ; go ahead and expand out the string, and "massage" the returned *pdwType
        ; to be REG_SZ.
        @DefProto DllImport, SHQueryValueExA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :ptr DWORD, :ptr DWORD, :ptr, :ptr DWORD>, 24
        ; These functions behave just like RegQueryValueEx(), except if the data
        ; type is REG_SZ, REG_EXPAND_SZ or REG_MULTI_SZ then the string is
        ; guaranteed to be properly null terminated.
        ; Additionally, if the data type is REG_EXPAND_SZ these functions will
        ; go ahead and expand out the string, and "massage" the returned *pdwType
        ; to be REG_SZ.
        @DefProto DllImport, SHQueryValueExW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :ptr DWORD, :ptr DWORD, :ptr, :ptr DWORD>, 24
        ifdef UNICODE
          SHQueryValueEx equ <SHQueryValueExW>
        else
          SHQueryValueEx equ <SHQueryValueExA>
        endif
        ; !UNICODE
        ; Enumeration functions support.
        @DefProto DllImport, SHEnumKeyExA, WIN_STD_CALL_CONV,, <:HKEY, :DWORD, :LPSTR, :LPDWORD>, 16
        @DefProto DllImport, SHEnumKeyExW, WIN_STD_CALL_CONV,, <:HKEY, :DWORD, :LPWSTR, :LPDWORD>, 16
        @DefProto DllImport, SHEnumValueA, WIN_STD_CALL_CONV,, <:HKEY, :DWORD, :PSTR, :LPDWORD, :LPDWORD, :ptr, :LPDWORD>, 28
        @DefProto DllImport, SHEnumValueW, WIN_STD_CALL_CONV,, <:HKEY, :DWORD, :PWSTR, :LPDWORD, :LPDWORD, :ptr, :LPDWORD>, 28
        @DefProto DllImport, SHQueryInfoKeyA, WIN_STD_CALL_CONV,, <:HKEY, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD>, 20
        @DefProto DllImport, SHQueryInfoKeyW, WIN_STD_CALL_CONV,, <:HKEY, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD>, 20
        ; recursive key copy
        @DefProto DllImport, SHCopyKeyA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :HKEY, :DWORD>, 16
        @DefProto DllImport, SHCopyKeyW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :HKEY, :DWORD>, 16
        ; Getting and setting file system paths with environment variables
        @DefProto DllImport, SHRegGetPathA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :LPCSTR, :LPSTR, :DWORD>, 20
        @DefProto DllImport, SHRegGetPathW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :LPCWSTR, :LPWSTR, :DWORD>, 20
        @DefProto DllImport, SHRegSetPathA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :LPCSTR, :LPCSTR, :DWORD>, 20
        @DefProto DllImport, SHRegSetPathW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :LPCWSTR, :LPCWSTR, :DWORD>, 20
        ifdef UNICODE
          SHEnumKeyEx equ <SHEnumKeyExW>
          SHEnumValue equ <SHEnumValueW>
          SHQueryInfoKey equ <SHQueryInfoKeyW>
          SHCopyKey equ <SHCopyKeyW>
          SHRegGetPath equ <SHRegGetPathW>
          SHRegSetPath equ <SHRegSetPathW>
        else
          SHEnumKeyEx equ <SHEnumKeyExA>
          SHEnumValue equ <SHEnumValueA>
          SHQueryInfoKey equ <SHQueryInfoKeyA>
          SHCopyKey equ <SHCopyKeyA>
          SHRegGetPath equ <SHRegGetPathA>
          SHRegSetPath equ <SHRegSetPathA>
        endif
        ;////////////////////////////////////////////
        ; User Specific Registry Access Functions
        ;////////////////////////////////////////////
        SHREGDEL_FLAGS typedef SDWORD
        SHREGDEL_DEFAULT equ 00000000h
        ; Delete's HKCU, or HKLM if HKCU is not found.
        SHREGDEL_HKCU equ 00000001h
        ; Delete HKCU only
        SHREGDEL_HKLM equ 00000010h
        ; Delete HKLM only.
        SHREGDEL_BOTH equ 00000011h
        ; Delete both HKCU and HKLM.

        SHREGENUM_FLAGS typedef SDWORD
        SHREGENUM_DEFAULT equ 00000000h
        ; Enumerates HKCU or HKLM if not found.
        SHREGENUM_HKCU equ 00000001h
        ; Enumerates HKCU only
        SHREGENUM_HKLM equ 00000010h
        ; Enumerates HKLM only.
        SHREGENUM_BOTH equ 00000011h
        ; Enumerates both HKCU and HKLM without duplicates.
        ; This option is NYI.

        SHREGSET_HKCU equ 00000001h; Write to HKCU if empty.

        SHREGSET_FORCE_HKCU equ 00000002h; Write to HKCU.

        SHREGSET_HKLM equ 00000004h; Write to HKLM if empty.

        SHREGSET_FORCE_HKLM equ 00000008h; Write to HKLM.

        SHREGSET_DEFAULT equ <(SHREGSET_FORCE_HKCU or SHREGSET_HKLM)>; Default is SHREGSET_FORCE_HKCU | SHREGSET_HKLM.

        HUSKEY typedef HANDLE
        ; HUSKEY is a Handle to a User Specific KEY.
        PHUSKEY typedef ptr HUSKEY
        @DefProto DllImport, SHRegCreateUSKeyA, WIN_STD_CALL_CONV,, <:LPCSTR, :REGSAM, :HUSKEY, :PHUSKEY, :DWORD>, 20
        @DefProto DllImport, SHRegCreateUSKeyW, WIN_STD_CALL_CONV,, <:LPCWSTR, :REGSAM, :HUSKEY, :PHUSKEY, :DWORD>, 20
        @DefProto DllImport, SHRegOpenUSKeyA, WIN_STD_CALL_CONV,, <:LPCSTR, :REGSAM, :HUSKEY, :PHUSKEY, :BOOL>, 20
        @DefProto DllImport, SHRegOpenUSKeyW, WIN_STD_CALL_CONV,, <:LPCWSTR, :REGSAM, :HUSKEY, :PHUSKEY, :BOOL>, 20
        @DefProto DllImport, SHRegQueryUSValueA, WIN_STD_CALL_CONV,, <:HUSKEY, :LPCSTR, :ptr DWORD, :ptr, :ptr DWORD, :BOOL, :ptr, :DWORD>, 32
        @DefProto DllImport, SHRegQueryUSValueW, WIN_STD_CALL_CONV,, <:HUSKEY, :LPCWSTR, :ptr DWORD, :ptr, :ptr DWORD, :BOOL, :ptr, :DWORD>, 32
        @DefProto DllImport, SHRegWriteUSValueA, WIN_STD_CALL_CONV,, <:HUSKEY, :LPCSTR, :DWORD, :ptr, :DWORD, :DWORD>, 24
        @DefProto DllImport, SHRegWriteUSValueW, WIN_STD_CALL_CONV,, <:HUSKEY, :LPCWSTR, :DWORD, :ptr, :DWORD, :DWORD>, 24
        @DefProto DllImport, SHRegDeleteUSValueA, WIN_STD_CALL_CONV,, <:HUSKEY, :LPCSTR, :SHREGDEL_FLAGS>, 12
        @DefProto DllImport, SHRegDeleteUSValueW, WIN_STD_CALL_CONV,, <:HUSKEY, :LPCWSTR, :SHREGDEL_FLAGS>, 12
        @DefProto DllImport, SHRegDeleteEmptyUSKeyW, WIN_STD_CALL_CONV,, <:HUSKEY, :LPCWSTR, :SHREGDEL_FLAGS>, 12
        @DefProto DllImport, SHRegDeleteEmptyUSKeyA, WIN_STD_CALL_CONV,, <:HUSKEY, :LPCSTR, :SHREGDEL_FLAGS>, 12
        @DefProto DllImport, SHRegEnumUSKeyA, WIN_STD_CALL_CONV,, <:HUSKEY, :DWORD, :LPSTR, :LPDWORD, :SHREGENUM_FLAGS>, 20
        @DefProto DllImport, SHRegEnumUSKeyW, WIN_STD_CALL_CONV,, <:HUSKEY, :DWORD, :LPWSTR, :LPDWORD, :SHREGENUM_FLAGS>, 20
        @DefProto DllImport, SHRegEnumUSValueA, WIN_STD_CALL_CONV,, <:HUSKEY, :DWORD, :LPSTR, :LPDWORD, :LPDWORD, :ptr, :LPDWORD, :SHREGENUM_FLAGS>, 32
        @DefProto DllImport, SHRegEnumUSValueW, WIN_STD_CALL_CONV,, <:HUSKEY, :DWORD, :LPWSTR, :LPDWORD, :LPDWORD, :ptr, :LPDWORD, :SHREGENUM_FLAGS>, 32
        @DefProto DllImport, SHRegQueryInfoUSKeyA, WIN_STD_CALL_CONV,, <:HUSKEY, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :SHREGENUM_FLAGS>, 24
        @DefProto DllImport, SHRegQueryInfoUSKeyW, WIN_STD_CALL_CONV,, <:HUSKEY, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :SHREGENUM_FLAGS>, 24
        @DefProto DllImport, SHRegCloseUSKey, WIN_STD_CALL_CONV,, <:HUSKEY>, 4
        ; These calls are equal to an SHRegOpenUSKey, SHRegQueryUSValue, and then a SHRegCloseUSKey.
        @DefProto DllImport, SHRegGetUSValueA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :ptr DWORD, :ptr, :ptr DWORD, :BOOL, :ptr, :DWORD>, 32
        @DefProto DllImport, SHRegGetUSValueW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :ptr DWORD, :ptr, :ptr DWORD, :BOOL, :ptr, :DWORD>, 32
        @DefProto DllImport, SHRegSetUSValueA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :DWORD, :ptr, :DWORD, :DWORD>, 24
        @DefProto DllImport, SHRegSetUSValueW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :DWORD, :ptr, :DWORD, :DWORD>, 24
        @DefProto DllImport, SHRegGetIntW, WIN_STD_CALL_CONV,, <:HKEY, :PCWSTR, :SDWORD>, 12
        ifdef UNICODE
          SHRegCreateUSKey equ <SHRegCreateUSKeyW>
          SHRegOpenUSKey equ <SHRegOpenUSKeyW>
          SHRegQueryUSValue equ <SHRegQueryUSValueW>
          SHRegWriteUSValue equ <SHRegWriteUSValueW>
          SHRegDeleteUSValue equ <SHRegDeleteUSValueW>
          SHRegDeleteEmptyUSKey equ <SHRegDeleteEmptyUSKeyW>
          SHRegEnumUSKey equ <SHRegEnumUSKeyW>
          SHRegEnumUSValue equ <SHRegEnumUSValueW>
          SHRegQueryInfoUSKey equ <SHRegQueryInfoUSKeyW>
          SHRegGetUSValue equ <SHRegGetUSValueW>
          SHRegSetUSValue equ <SHRegSetUSValueW>
          SHRegGetInt equ <SHRegGetIntW>
        else
          SHRegCreateUSKey equ <SHRegCreateUSKeyA>
          SHRegOpenUSKey equ <SHRegOpenUSKeyA>
          SHRegQueryUSValue equ <SHRegQueryUSValueA>
          SHRegWriteUSValue equ <SHRegWriteUSValueA>
          SHRegDeleteUSValue equ <SHRegDeleteUSValueA>
          SHRegDeleteEmptyUSKey equ <SHRegDeleteEmptyUSKeyA>
          SHRegEnumUSKey equ <SHRegEnumUSKeyA>
          SHRegEnumUSValue equ <SHRegEnumUSValueA>
          SHRegQueryInfoUSKey equ <SHRegQueryInfoUSKeyA>
          SHRegGetUSValue equ <SHRegGetUSValueA>
          SHRegSetUSValue equ <SHRegSetUSValueA>
        endif
        @DefProto DllImport, SHRegGetBoolUSValueA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :BOOL, :BOOL>, 16
        @DefProto DllImport, SHRegGetBoolUSValueW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :BOOL, :BOOL>, 16
        ifdef UNICODE
          SHRegGetBoolUSValue equ <SHRegGetBoolUSValueW>
        else
          SHRegGetBoolUSValue equ <SHRegGetBoolUSValueA>
        endif
        ; !UNICODE
        ;  Association APIs
        ;  these APIs are to assist in accessing the data in HKCR
        ;  getting the Command strings and exe paths
        ;  for different verbs and extensions are simplified this way
        ASSOCF_NONE equ 00000000h
        ASSOCF_INIT_NOREMAPCLSID equ 00000001h
        ;  do not remap clsids to progids
        ASSOCF_INIT_BYEXENAME equ 00000002h
        ;  executable is being passed in
        ASSOCF_OPEN_BYEXENAME equ 00000002h
        ;  executable is being passed in
        ASSOCF_INIT_DEFAULTTOSTAR equ 00000004h
        ;  treat "*" as the BaseClass
        ASSOCF_INIT_DEFAULTTOFOLDER equ 00000008h
        ;  treat "Folder" as the BaseClass
        ASSOCF_NOUSERSETTINGS equ 00000010h
        ;  dont use HKCU
        ASSOCF_NOTRUNCATE equ 00000020h
        ;  dont truncate the return string
        ASSOCF_VERIFY equ 00000040h
        ;  verify data is accurate (DISK HITS)
        ASSOCF_REMAPRUNDLL equ 00000080h
        ;  actually gets info about rundlls target if applicable
        ASSOCF_NOFIXUPS equ 00000100h
        ;  attempt to fix errors if found
        ASSOCF_IGNOREBASECLASS equ 00000200h
        ;  dont recurse into the baseclass
        ASSOCF_INIT_IGNOREUNKNOWN equ 00000400h
        ;  dont use the "Unknown" progid, instead fail
        if (NTDDI_VERSION ge NTDDI_WIN8)
          ASSOCF_INIT_FIXED_PROGID equ 00000800h
          ;  the Init() pszAssoc value is a ProgId that should not be mapped using the current user defaults
          ASSOCF_IS_PROTOCOL equ 00001000h
          ;  the Init() pszAssoc value is an uri scheme (not including the ":") that should be mapped using the current user defaults
          ASSOCF_INIT_FOR_FILE equ 00002000h
          ;  use this flag when specifying ASSOCF_INIT_FIXED_PROGID if the ProgId corresponds with a file extension based association
        endif
        if (NTDDI_VERSION ge NTDDI_WIN10_RS1)
          ASSOCF_IS_FULL_URI equ 00004000h
          ;  Used to specify that full http/https URI is being passed for target resolution
          ;  Only one of ASSOCF_INIT_FIXED_PROGID, ASSOCF_IS_PROTOCOL or ASSOCF_IS_FULL_URI can be specified at a time.
          ASSOCF_PER_MACHINE_ONLY equ 00008000h
          ;  Enforces per-machine association look-up only and avoid HKCU.
        endif
        if (NTDDI_VERSION ge NTDDI_WIN10_RS4)
          ; For http/https uri associations, this enables selecting the OS default browser, that is a controlled by
          ; policy settings, instead of the default browser.
          ASSOCF_APP_TO_APP equ 00010000h
        endif

        ASSOCF typedef DWORD
        ; _WIN32_IE_IE60
        ; _WIN32_IE_IE80
        ; NTDDI_WIN10
        ASSOCSTR typedef SDWORD
        ASSOCSTR_COMMAND equ 1
        ;  shell\verb\command string
        ASSOCSTR_EXECUTABLE equ 2
        ;  the executable part of command string
        ASSOCSTR_FRIENDLYDOCNAME equ 3
        ;  friendly name of the document type
        ASSOCSTR_FRIENDLYAPPNAME equ 4
        ;  friendly name of executable
        ASSOCSTR_NOOPEN equ 5
        ;  noopen value
        ASSOCSTR_SHELLNEWVALUE equ 6
        ;  query values under the shellnew key
        ASSOCSTR_DDECOMMAND equ 7
        ;  template for DDE commands
        ASSOCSTR_DDEIFEXEC equ 8
        ;  DDECOMMAND to use if just create a process
        ASSOCSTR_DDEAPPLICATION equ 9
        ;  Application name in DDE broadcast
        ASSOCSTR_DDETOPIC equ 10
        ;  Topic Name in DDE broadcast
        ASSOCSTR_INFOTIP equ 11
        ;  info tip for an item, or list of properties to create info tip from
        if (_WIN32_IE ge _WIN32_IE_IE60)
          ASSOCSTR_QUICKTIP equ 12
          ;  same as ASSOCSTR_INFOTIP, except, this list contains only quickly retrievable properties
          ASSOCSTR_TILEINFO equ 13
          ;  similar to ASSOCSTR_INFOTIP - lists important properties for tileview
          ASSOCSTR_CONTENTTYPE equ 14
          ;  MIME Content type
          ASSOCSTR_DEFAULTICON equ 15
          ;  Default icon source
          ASSOCSTR_SHELLEXTENSION equ 16
          ;  Guid string pointing to the Shellex\Shellextensionhandler value.
        endif
        ; _WIN32_IE_IE60
        if (_WIN32_IE ge _WIN32_IE_IE80)
          ASSOCSTR_DROPTARGET equ 17
          ;  The CLSID of DropTarget
          ASSOCSTR_DELEGATEEXECUTE equ 18
          ;  The CLSID of DelegateExecute
        endif
        ; _WIN32_IE_IE80
        ; a string value of the uri protocol schemes, for example "http:https:ftp:file:" or "*" indicating all
        ASSOCSTR_SUPPORTED_URI_PROTOCOLS equ 19
        if (NTDDI_VERSION ge NTDDI_WIN10)
          ASSOCSTR_PROGID equ 20
          ; The ProgId provided by the app associated with the file type or uri scheme based on user default settings.
          ASSOCSTR_APPID equ 21
          ; The AppUserModelID of the app associated with the file type or uri scheme based on user default settings.
          ASSOCSTR_APPPUBLISHER equ 22
          ; THe publisher of the app associated with the file type or uri scheme based on user default settings.
          ASSOCSTR_APPICONREFERENCE equ 23
          ; The icon reference of the app associated with the file type or uri scheme based on user default settings.
        endif
        ; NTDDI_WIN10
        ASSOCSTR_MAX equ 24

        ;  last item in enum...
        ASSOCKEY typedef SDWORD
        ASSOCKEY_SHELLEXECCLASS equ 1
        ;  the key that should be passed to ShellExec(hkeyClass)
        ASSOCKEY_APP equ 2
        ;  the "Application" key for the association
        ASSOCKEY_CLASS equ 3
        ;  the progid or class key
        ASSOCKEY_BASECLASS equ 4
        ;  the BaseClass key
        ASSOCKEY_MAX equ 5

        ;  last item in enum...
        ; _WIN32_IE_IE60
        ASSOCDATA typedef SDWORD
        ASSOCDATA_MSIDESCRIPTOR equ 1
        ;  Component Descriptor to pass to MSI APIs
        ASSOCDATA_NOACTIVATEHANDLER equ 2
        ;  restrict attempts to activate window
        ASSOCDATA_UNUSED1 equ 3
        ;  removed QUERYCLASSSTORE, dead code
        ASSOCDATA_HASPERUSERASSOC equ 4
        ;  defaults to user specified association
        if (_WIN32_IE ge _WIN32_IE_IE60)
          ASSOCDATA_EDITFLAGS equ 5
          ;  Edit flags.
          ASSOCDATA_VALUE equ 6
          ;  use pszExtra as the Value name
        endif
        ; _WIN32_IE_IE60
        ASSOCDATA_MAX equ 7

        ASSOCENUM typedef SDWORD
        ASSOCENUM_NONE equ 0

        ; Stored under HKCR\<progId> EditFlags(REG_DWORD)
        ; Retrieve these values using IQueryAssociations::GetData as follows
        ; DWORD editFlags, size = sizeof(editFlags);
        ; queryAssoc->GetData(nullptr, ASSOCDATA_EDITFLAGS, nullptr, &editFlags, &size);
        ; Some of these flags are no longer used since editing file type associations has been
        ; removed from Explorer's folder options UI.
        FILETYPEATTRIBUTEFLAGS typedef SDWORD
        FTA_None equ 00000000h
        FTA_Exclude equ 00000001h
        ; used to exclude (hide) types like drvfile
        FTA_Show equ 00000002h
        ; used to show types like folder that don't have associations
        FTA_HasExtension equ 00000004h
        ; type has a file name extension
        FTA_NoEdit equ 00000008h
        ; no editing of file type
        FTA_NoRemove equ 00000010h
        ; no removing of the file type
        FTA_NoNewVerb equ 00000020h
        ; no adding of verbs
        FTA_NoEditVerb equ 00000040h
        ; no editing of predefined verbs
        FTA_NoRemoveVerb equ 00000080h
        ; no removing of predefined verbs
        FTA_NoEditDesc equ 00000100h
        ; no editing of file type description
        FTA_NoEditIcon equ 00000200h
        ; no editing of doc icon
        FTA_NoEditDflt equ 00000400h
        ; no changing of default verb
        FTA_NoEditVerbCmd equ 00000800h
        ; no modification of the commnds associated with the verbs
        FTA_NoEditVerbExe equ 00001000h
        ; no editing of the verb's exe
        FTA_NoDDE equ 00002000h
        ; no editing of the DDE fields
        FTA_NoEditMIME equ 00008000h
        ; no editing of the Content Type or Default Extension fields
        FTA_OpenIsSafe equ 00010000h
        ; the open verb should be invoked automaticaly for downloaded files
        FTA_AlwaysUnsafe equ 00020000h
        ; don't allow the "Never ask me" checkbox to be enabled; File Type dialog still allows user to turn this off
        FTA_NoRecentDocs equ 00100000h
        ; don't add this file type to the Recent Documents folder
        FTA_SafeForElevation equ 00200000h
        ; Win8: can be launched in medium IL by a process running in AppContainer
        FTA_AlwaysUseDirectInvoke equ 00400000h
        ; Win8: when downloading use the direct invoke feature even if the server headers are not provided

        DEFINE_ENUM_FLAG_OPERATORS(FILETYPEATTRIBUTEFLAGS)
        INTERFACE equ <IQueryAssociations>
        ??Interface equ <>
        DECLARE_INTERFACE_IID_(IQueryAssociations, IUnknown, "c46ca590-3c3f-11d2-bee6-0000f805ca57")
          ; IQueryAssociations methods
          STDMETHOD Init, :ASSOCF, :=POINTER, :HKEY, :HWND
          STDMETHOD GetString, :ASSOCF, :ASSOCSTR, :=POINTER, :POINTER, :ptr DWORD
          STDMETHOD GetKey, :ASSOCF, :ASSOCKEY, :=POINTER, :ptr HKEY
          STDMETHOD GetData, :ASSOCF, :ASSOCDATA, :=POINTER, :ptr , :ptr DWORD
          STDMETHOD GetEnum, :ASSOCF, :ASSOCENUM, :=POINTER, :REFIID, :ptr ptr 
        DECLARE_INTERFACE_IID__END

        ; use CLSID_QueryAssociations for clsid, object implements IQueryAssociations
        ; AssocCreateForClasses() is the more functional version of this API
        @DefProto DllImport, AssocCreate, WIN_STD_CALL_CONV,, <:CLSID, :REFIID, :ptr ptr>, 12
        ; Retrieve an array of class keys from an IQueryAssociations object
        ; if the caller is just interested in the primary class key,
        ; call with cKeys == 1.  the return value is the number of keys
        ; inserted into the array.
        @DefProto DllImport, SHGetAssocKeys, WIN_STD_CALL_CONV,, <:ptr IQueryAssociations, :ptr HKEY, :DWORD>, 12
        ;  wrappers for the interface
        @DefProto DllImport, AssocQueryStringA, WIN_STD_CALL_CONV,, <:ASSOCF, :ASSOCSTR, :LPCSTR, :LPCSTR, :LPSTR, :ptr DWORD>, 24
        ;  wrappers for the interface
        @DefProto DllImport, AssocQueryStringW, WIN_STD_CALL_CONV,, <:ASSOCF, :ASSOCSTR, :LPCWSTR, :LPCWSTR, :LPWSTR, :ptr DWORD>, 24
        ifdef UNICODE
          AssocQueryString equ <AssocQueryStringW>
        else
          AssocQueryString equ <AssocQueryStringA>
        endif
        ; !UNICODE
        @DefProto DllImport, AssocQueryStringByKeyA, WIN_STD_CALL_CONV,, <:ASSOCF, :ASSOCSTR, :HKEY, :LPCSTR, :LPSTR, :ptr DWORD>, 24
        @DefProto DllImport, AssocQueryStringByKeyW, WIN_STD_CALL_CONV,, <:ASSOCF, :ASSOCSTR, :HKEY, :LPCWSTR, :LPWSTR, :ptr DWORD>, 24
        ifdef UNICODE
          AssocQueryStringByKey equ <AssocQueryStringByKeyW>
        else
          AssocQueryStringByKey equ <AssocQueryStringByKeyA>
        endif
        ; !UNICODE
        @DefProto DllImport, AssocQueryKeyA, WIN_STD_CALL_CONV,, <:ASSOCF, :ASSOCKEY, :LPCSTR, :LPCSTR, :ptr HKEY>, 20
        @DefProto DllImport, AssocQueryKeyW, WIN_STD_CALL_CONV,, <:ASSOCF, :ASSOCKEY, :LPCWSTR, :LPCWSTR, :ptr HKEY>, 20
        ifdef UNICODE
          AssocQueryKey equ <AssocQueryKeyW>
        else
          AssocQueryKey equ <AssocQueryKeyA>
        endif
        ; !UNICODE
        if (_WIN32_IE ge 0601h)
          ;  AssocIsDangerous() checks a file type to determine whether it is "Dangerous"
          ;      this maps to the IE download dialog's forcing a prompt to open or save.
          ;      dangerous file types should be handled more carefully than other file types.
          ;  Parameter:  pszAssoc - type to check.  may be an extension or progid.  (".exe" or "exefile" would both be valid)
          ;  Returns: TRUE if the file type is dangerous.
          ;  NOTES:
          ;      this API first checks a hardcoded list of known dangerous types.
          ;      then it checks the editflags for the file type looking for the FTA_AlwaysUnsafe bit.
          ;      then it checks Safer policies.
          @DefProto DllImport, AssocIsDangerous, WIN_STD_CALL_CONV,, <:PCWSTR>, 4
        endif
        ; _WIN32_IE >= 0x0601
        if (_WIN32_IE ge _WIN32_IE_IE60SP2)
          @DefProto DllImport, AssocGetPerceivedType, WIN_STD_CALL_CONV,, <:PCWSTR, :ptr PERCEIVED, :ptr PERCEIVEDFLAG, :ptr PWSTR>, 16
        endif
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
    endif
    ;  NO_SHLWAPI_REG
    ifndef NO_SHLWAPI_STREAM
      ;=============== Stream Routines ===================================
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        ; objidl.h
        ifndef __IStream_FWD_DEFINED__
          __IStream_FWD_DEFINED__ equ <>
          ;* __IStream_FWD_DEFINED__ *
        endif
        @DefProto DllImport, SHOpenRegStreamA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :LPCSTR, :DWORD>, 16
        @DefProto DllImport, SHOpenRegStreamW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :LPCWSTR, :DWORD>, 16
        ifdef UNICODE
          SHOpenRegStream equ <SHOpenRegStreamW>
        else
          SHOpenRegStream equ <SHOpenRegStreamA>
        endif
        ; !UNICODE
        @DefProto DllImport, SHOpenRegStream2A, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :LPCSTR, :DWORD>, 16
        @DefProto DllImport, SHOpenRegStream2W, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :LPCWSTR, :DWORD>, 16
        ifdef UNICODE
          SHOpenRegStream2 equ <SHOpenRegStream2W>
        else
          SHOpenRegStream2 equ <SHOpenRegStream2A>
        endif
        ; !UNICODE
        ; New code always wants new implementation...
        SHOpenRegStream equ <SHOpenRegStream2>
        @DefProto DllImport, SHCreateStreamOnFileA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :ptr ptr IStream>, 12
        @DefProto DllImport, SHCreateStreamOnFileW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :ptr ptr IStream>, 12
        ifdef UNICODE
          SHCreateStreamOnFile equ <SHCreateStreamOnFileW>
        else
          SHCreateStreamOnFile equ <SHCreateStreamOnFileA>
        endif
        ; !UNICODE
        if (_WIN32_IE ge 0600h)
          @DefProto DllImport, SHCreateStreamOnFileEx, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :DWORD, :BOOL, :ptr IStream, :ptr ptr IStream>, 24
        endif
        ; (_WIN32_IE >= 0x0600)
        @DefProto DllImport, SHCreateMemStream, WIN_STD_CALL_CONV,, <:ptr BYTE, :UINT>, 8
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
    endif
    ; NO_SHLWAPI_STREAM
    ifndef NO_SHLWAPI_HTTP
      ;=============== HTTP helper Routines ===================================
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
        if (_WIN32_IE ge 0603h)
          @DefProto DllImport, GetAcceptLanguagesA, WIN_STD_CALL_CONV,, <:LPSTR, :ptr DWORD>, 8
          @DefProto DllImport, GetAcceptLanguagesW, WIN_STD_CALL_CONV,, <:LPWSTR, :ptr DWORD>, 8
          ifdef UNICODE
            GetAcceptLanguages equ <GetAcceptLanguagesW>
          else
            GetAcceptLanguages equ <GetAcceptLanguagesA>
          endif
          ; !UNICODE
        endif
        ; (_WIN32_IE >= 0x0603)
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) *
      endif
    endif
    ; NO_SHLWAPI_HTTP
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      if (_WIN32_IE lt _WIN32_IE_IE70) and  not Defined(NO_SHLWAPI_STOPWATCH)
        SPMODE_SHELL equ 00000001h
        SPMODE_DEBUGOUT equ 00000002h
        SPMODE_TEST equ 00000004h
        SPMODE_BROWSER equ 00000008h
        SPMODE_FLUSH equ 00000010h
        SPMODE_EVENT equ 00000020h
        SPMODE_MSVM equ 00000040h
        SPMODE_FORMATTEXT equ 00000080h
        SPMODE_PROFILE equ 00000100h
        SPMODE_DEBUGBREAK equ 00000200h
        SPMODE_MSGTRACE equ 00000400h
        SPMODE_PERFTAGS equ 00000800h
        SPMODE_MEMWATCH equ 00001000h
        SPMODE_DBMON equ 00002000h
        SPMODE_MULTISTOP equ 00004000h
        ifndef NO_ETW_TRACING
          SPMODE_EVENTTRACE equ 00008000h; Event Tracing for Windows Enabled

        endif
        StopWatchMode proto WIN_STD_CALL_CONV
        StopWatchFlush proto WIN_STD_CALL_CONV
      endif
      ; (_WIN32_IE < _WIN32_IE_IE70) && !defined(NO_SHLWAPI_STOPWATCH)
      @DefProto DllImport, IUnknown_Set, WIN_STD_CALL_CONV,, <:ptr ptr IUnknown, :ptr IUnknown>, 8
      @DefProto DllImport, IUnknown_AtomicRelease, WIN_STD_CALL_CONV,, <:ptr ptr>, 4
      @DefProto DllImport, IUnknown_GetWindow, WIN_STD_CALL_CONV,, <:ptr IUnknown, :ptr HWND>, 8
      @DefProto DllImport, IUnknown_SetSite, WIN_STD_CALL_CONV,, <:ptr IUnknown, :ptr IUnknown>, 8
      @DefProto DllImport, IUnknown_GetSite, WIN_STD_CALL_CONV,, <:ptr IUnknown, :REFIID, :ptr ptr>, 12
      @DefProto DllImport, IUnknown_QueryService, WIN_STD_CALL_CONV,, <:ptr IUnknown, :REFGUID, :REFIID, :ptr ptr>, 16
      if  not Defined(__cplusplus) and Defined(COBJMACROS)
        ;[...]
      endif
      @DefProto DllImport, IStream_Read, WIN_STD_CALL_CONV,, <:ptr IStream, :ptr, :ULONG>, 12
      @DefProto DllImport, IStream_Write, WIN_STD_CALL_CONV,, <:ptr IStream, :ptr, :ULONG>, 12
      @DefProto DllImport, IStream_Reset, WIN_STD_CALL_CONV,, <:ptr IStream>, 4
      @DefProto DllImport, IStream_Size, WIN_STD_CALL_CONV,, <:ptr IStream, :ptr ULARGE_INTEGER>, 8
      ; ocidl.h
      ifndef __IConnectionPoint_FWD_DEFINED__
        __IConnectionPoint_FWD_DEFINED__ equ <>
        ;* __IConnectionPoint_FWD_DEFINED__ *
      endif
      @DefProto DllImport, ConnectToConnectionPoint, WIN_STD_CALL_CONV,, <:ptr IUnknown, :REFIID, :BOOL, :ptr IUnknown, :ptr DWORD, :ptr ptr IConnectionPoint>, 24
      if (NTDDI_VERSION ge NTDDI_VISTA)
        @DefProto DllImport, IStream_ReadPidl, WIN_STD_CALL_CONV,, <:ptr IStream, :ptr PIDLIST_RELATIVE>, 8
        @DefProto DllImport, IStream_WritePidl, WIN_STD_CALL_CONV,, <:ptr IStream, :PCUIDLIST_RELATIVE>, 8
      endif
      ; (NTDDI_VERSION >= NTDDI_VISTA)
      if (_WIN32_IE ge _WIN32_IE_IE70)
        @DefProto DllImport, IStream_ReadStr, WIN_STD_CALL_CONV,, <:ptr IStream, :ptr PWSTR>, 8
        @DefProto DllImport, IStream_WriteStr, WIN_STD_CALL_CONV,, <:ptr IStream, :PCWSTR>, 8
        @DefProto DllImport, IStream_Copy, WIN_STD_CALL_CONV,, <:ptr IStream, :ptr IStream, :DWORD>, 12
      endif
      ; (_WIN32_IE >= _WIN32_IE_IE70)
      if (_WIN32_IE ge 0600h)
        SHGVSPB_PERUSER equ 00000001h; must have one of PERUSER or ALLUSERS

        SHGVSPB_ALLUSERS equ 00000002h
        SHGVSPB_PERFOLDER equ 00000004h; must have one of PERFOLDER ALLFOLDERS or INHERIT

        SHGVSPB_ALLFOLDERS equ 00000008h
        SHGVSPB_INHERIT equ 00000010h
        SHGVSPB_ROAM equ 00000020h; modifies the above

        SHGVSPB_NOAUTODEFAULTS equ 80000000h; turns off read delegation to more general property bags

        SHGVSPB_FOLDER equ <(SHGVSPB_PERUSER or SHGVSPB_PERFOLDER)>
        SHGVSPB_FOLDERNODEFAULTS equ <(SHGVSPB_PERUSER or SHGVSPB_PERFOLDER or SHGVSPB_NOAUTODEFAULTS)>
        SHGVSPB_USERDEFAULTS equ <(SHGVSPB_PERUSER or SHGVSPB_ALLFOLDERS)>
        SHGVSPB_GLOBALDEFAULTS equ <(SHGVSPB_ALLUSERS or SHGVSPB_ALLFOLDERS)>
        @DefProto DllImport, SHGetViewStatePropertyBag, WIN_STD_CALL_CONV,, <:PCIDLIST_ABSOLUTE, :PCWSTR, :DWORD, :REFIID, :ptr ptr>, 20
      endif
      ; (_WIN32_IE >= 0x0600)
      ; SHFormatDateTime flags
      ;  (FDTF_SHORTDATE and FDTF_LONGDATE are mutually exclusive, as is
      ;   FDTF_SHORTIME and FDTF_LONGTIME.)
      FDTF_SHORTTIME equ 00000001h; eg, "7:48 PM"

      FDTF_SHORTDATE equ 00000002h; eg, "3/29/98"

      FDTF_DEFAULT equ <(FDTF_SHORTDATE or FDTF_SHORTTIME)>; eg, "3/29/98 7:48 PM"

      FDTF_LONGDATE equ 00000004h; eg, "Monday, March 29, 1998"

      FDTF_LONGTIME equ 00000008h; eg. "7:48:33 PM"

      FDTF_RELATIVE equ 00000010h; uses "Yesterday", etc. if possible

      FDTF_LTRDATE equ 00000100h; Left To Right reading order

      FDTF_RTLDATE equ 00000200h; Right To Left reading order

      FDTF_NOAUTOREADINGORDER equ 00000400h; Don't detect reading order automatically. Useful if you will be converting to Ansi and don't want Unicode reading order characters

      @DefProto DllImport, SHFormatDateTimeA, WIN_STD_CALL_CONV,, <:ptr FILETIME, :ptr DWORD, :LPSTR, :UINT>, 16
      @DefProto DllImport, SHFormatDateTimeW, WIN_STD_CALL_CONV,, <:ptr FILETIME, :ptr DWORD, :LPWSTR, :UINT>, 16
      ifdef UNICODE
        SHFormatDateTime equ <SHFormatDateTimeW>
      else
        SHFormatDateTime equ <SHFormatDateTimeA>
      endif
      ; !UNICODE
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, SHAnsiToUnicode, WIN_STD_CALL_CONV,, <:PCSTR, :PWSTR, :SDWORD>, 12
      @DefProto DllImport, SHAnsiToAnsi, WIN_STD_CALL_CONV,, <:PCSTR, :PSTR, :SDWORD>, 12
      @DefProto DllImport, SHUnicodeToAnsi, WIN_STD_CALL_CONV,, <:PCWSTR, :PSTR, :SDWORD>, 12
      @DefProto DllImport, SHUnicodeToUnicode, WIN_STD_CALL_CONV,, <:PCWSTR, :PWSTR, :SDWORD>, 12
      ; The return value from all SH<Type>To<Type> is the size of szDest including the terminater.
      ifdef UNICODE
        SHTCharToUnicode macro wzSrc, wzDest, cchSize
          exitm <SHUnicodeToUnicode (wzSrc, wzDest, cchSize)>
        endm
        SHTCharToAnsi macro wzSrc, szDest, cchSize
          exitm <SHUnicodeToAnsi (wzSrc, szDest, cchSize)>
        endm
        SHUnicodeToTChar macro wzSrc, wzDest, cchSize
          exitm <SHUnicodeToUnicode (wzSrc, wzDest, cchSize)>
        endm
        SHAnsiToTChar macro szSrc, wzDest, cchSize
          exitm <SHAnsiToUnicode (szSrc, wzDest, cchSize)>
        endm
      else
      ; UNICODE
        SHTCharToUnicode macro szSrc, wzDest, cchSize
          exitm <SHAnsiToUnicode (szSrc, wzDest, cchSize)>
        endm
        SHTCharToAnsi macro szSrc, szDest, cchSize
          exitm <SHAnsiToAnsi (szSrc, szDest, cchSize)>
        endm
        SHUnicodeToTChar macro wzSrc, szDest, cchSize
          exitm <SHUnicodeToAnsi (wzSrc, szDest, cchSize)>
        endm
        SHAnsiToTChar macro szSrc, szDest, cchSize
          exitm <SHAnsiToAnsi (szSrc, szDest, cchSize)>
        endm
      endif
      ; UNICODE
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, SHMessageBoxCheckA, WIN_STD_CALL_CONV,, <:HWND, :LPCSTR, :LPCSTR, :UINT, :SDWORD, :LPCSTR>, 24
      @DefProto DllImport, SHMessageBoxCheckW, WIN_STD_CALL_CONV,, <:HWND, :LPCWSTR, :LPCWSTR, :UINT, :SDWORD, :LPCWSTR>, 24
      ifdef UNICODE
        SHMessageBoxCheck equ <SHMessageBoxCheckW>
      else
        SHMessageBoxCheck equ <SHMessageBoxCheckA>
      endif
      ; !UNICODE
      ; Prevents hang do to hung window on broadcast
      @DefProto DllImport, SHSendMessageBroadcastA, WIN_STD_CALL_CONV,, <:UINT, :WPARAM, :LPARAM>, 12
      ; Prevents hang do to hung window on broadcast
      @DefProto DllImport, SHSendMessageBroadcastW, WIN_STD_CALL_CONV,, <:UINT, :WPARAM, :LPARAM>, 12
      ifdef UNICODE
        SHSendMessageBroadcast equ <SHSendMessageBroadcastW>
      else
        SHSendMessageBroadcast equ <SHSendMessageBroadcastA>
      endif
      ; !UNICODE
      @DefProto DllImport, SHStripMneumonicA, WIN_STD_CALL_CONV,, <:LPSTR>, 4
      @DefProto DllImport, SHStripMneumonicW, WIN_STD_CALL_CONV,, <:LPWSTR>, 4
      ifdef UNICODE
        SHStripMneumonic equ <SHStripMneumonicW>
      else
        SHStripMneumonic equ <SHStripMneumonicA>
      endif
      ; !UNICODE
      ifndef NO_SHLWAPI_ISOS
        ; Returns TRUE/FALSE depending on question
        OS_WINDOWS equ 0; Windows 9x vs. NT

        OS_NT equ 1; Windows 9x vs. NT

        OS_WIN95ORGREATER equ 2; Win95 or greater

        OS_NT4ORGREATER equ 3; NT4 or greater

        OS_WIN98ORGREATER equ 5; Win98 or greater

        OS_WIN98_GOLD equ 6; Win98 Gold (Version 4.10 build 1998)

        OS_WIN2000ORGREATER equ 7; Some derivative of Win2000

        ; NOTE: these flags check explicitly for (dwMajorVersion == 5)
        OS_WIN2000PRO equ 8; Windows 2000 Professional (Workstation)

        OS_WIN2000SERVER equ 9; Windows 2000 Server

        OS_WIN2000ADVSERVER equ 10; Windows 2000 Advanced Server

        OS_WIN2000DATACENTER equ 11; Windows 2000 Data Center Server

        OS_WIN2000TERMINAL equ 12; Windows 2000 Terminal Server in "Application Server" mode (now simply called "Terminal Server")

        OS_EMBEDDED equ 13; Embedded Windows Edition

        OS_TERMINALCLIENT equ 14; Windows Terminal Client (eg user is comming in via tsclient)

        OS_TERMINALREMOTEADMIN equ 15; Terminal Server in "Remote Administration" mode

        OS_WIN95_GOLD equ 16; Windows 95 Gold (Version 4.0 Build 1995)

        OS_MEORGREATER equ 17; Windows Millennium (Version 5.0)

        OS_XPORGREATER equ 18; Windows XP or greater

        OS_HOME equ 19; Home Edition (eg NOT Professional, Server, Advanced Server, or Datacenter)

        OS_PROFESSIONAL equ 20; Professional     (aka Workstation; eg NOT Server, Advanced Server, or Datacenter)

        OS_DATACENTER equ 21; Datacenter       (eg NOT Server, Advanced Server, Professional, or Personal)

        OS_ADVSERVER equ 22; Advanced Server  (eg NOT Datacenter, Server, Professional, or Personal)

        OS_SERVER equ 23; Server           (eg NOT Datacenter, Advanced Server, Professional, or Personal)

        OS_TERMINALSERVER equ 24; Terminal Server - server running in what used to be called "Application Server" mode (now simply called "Terminal Server")

        OS_PERSONALTERMINALSERVER equ 25; Personal Terminal Server - per/pro machine running in single user TS mode

        OS_FASTUSERSWITCHING equ 26; Fast User Switching

        OS_WELCOMELOGONUI equ 27; New friendly logon UI

        OS_DOMAINMEMBER equ 28; Is this machine a member of a domain (eg NOT a workgroup)

        OS_ANYSERVER equ 29; is this machine any type of server? (eg datacenter or advanced server or server)?

        OS_WOW6432 equ 30; Is this process a 32-bit process running on an 64-bit platform?

        OS_WEBSERVER equ 31; Web Edition Server

        OS_SMALLBUSINESSSERVER equ 32; SBS Server

        OS_TABLETPC equ 33; Are we running on a TabletPC?

        OS_SERVERADMINUI equ 34; Should defaults lean towards those preferred by server administrators?

        OS_MEDIACENTER equ 35; eHome Freestyle Project

        OS_APPLIANCE equ 36; Windows .NET Appliance Server

        @DefProto DllImport, IsOS, WIN_STD_CALL_CONV,, <:DWORD>, 4
      endif
      ; NO_SHLWAPI_ISOS
      ; (NTDDI_VERSION >= NTDDI_WINBLUE)
      ; (NTDDI_VERSION >= NTDDI_WIN8)
      ; (NTDDI_VERSION >= NTDDI_WIN10_RS1)
      SHGLOBALCOUNTER typedef SDWORD
      GLOBALCOUNTER_SEARCHMANAGER equ 0
      GLOBALCOUNTER_SEARCHOPTIONS equ 1
      GLOBALCOUNTER_FOLDERSETTINGSCHANGE equ 2
      GLOBALCOUNTER_RATINGS equ 3
      GLOBALCOUNTER_APPROVEDSITES equ 4
      GLOBALCOUNTER_RESTRICTIONS equ 5
      GLOBALCOUNTER_SHELLSETTINGSCHANGED equ 6
      GLOBALCOUNTER_SYSTEMPIDLCHANGE equ 7
      GLOBALCOUNTER_OVERLAYMANAGER equ 8
      GLOBALCOUNTER_QUERYASSOCIATIONS equ 9
      GLOBALCOUNTER_IESESSIONS equ 10
      GLOBALCOUNTER_IEONLY_SESSIONS equ 11
      GLOBALCOUNTER_APPLICATION_DESTINATIONS equ 12
      __UNUSED_RECYCLE_WAS_GLOBALCOUNTER_CSCSYNCINPROGRESS equ 13
      GLOBALCOUNTER_BITBUCKETNUMDELETERS equ 14
      GLOBALCOUNTER_RECYCLEDIRTYCOUNT_SHARES equ 15
      GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_A equ 16
      GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_B equ 17
      GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_C equ 18
      GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_D equ 19
      GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_E equ 20
      GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_F equ 21
      GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_G equ 22
      GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_H equ 23
      GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_I equ 24
      GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_J equ 25
      GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_K equ 26
      GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_L equ 27
      GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_M equ 28
      GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_N equ 29
      GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_O equ 30
      GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_P equ 31
      GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_Q equ 32
      GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_R equ 33
      GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_S equ 34
      GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_T equ 35
      GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_U equ 36
      GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_V equ 37
      GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_W equ 38
      GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_X equ 39
      GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_Y equ 40
      GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_Z equ 41
      __UNUSED_RECYCLE_WAS_GLOBALCOUNTER_RECYCLEDIRTYCOUNT_SERVERDRIVE equ 42
      __UNUSED_RECYCLE_WAS_GLOBALCOUNTER_RECYCLEGLOBALDIRTYCOUNT equ 43
      GLOBALCOUNTER_RECYCLEBINENUM equ 44
      GLOBALCOUNTER_RECYCLEBINCORRUPTED equ 45
      GLOBALCOUNTER_RATINGS_STATECOUNTER equ 46
      GLOBALCOUNTER_PRIVATE_PROFILE_CACHE equ 47
      GLOBALCOUNTER_INTERNETTOOLBAR_LAYOUT equ 48
      GLOBALCOUNTER_FOLDERDEFINITION_CACHE equ 49
      GLOBALCOUNTER_COMMONPLACES_LIST_CACHE equ 50
      GLOBALCOUNTER_PRIVATE_PROFILE_CACHE_MACHINEWIDE equ 51
      GLOBALCOUNTER_ASSOCCHANGED equ 52
      ; throttles reading of the registry value "GlobalAssocChangedCounter" from HKLM\Software\Microsoft\Windows\CurrentVersion\Explorer
      if (NTDDI_VERSION ge NTDDI_WIN8)
        GLOBALCOUNTER_APP_ITEMS_STATE_STORE_CACHE equ 53
        GLOBALCOUNTER_SETTINGSYNC_ENABLED equ 54
        GLOBALCOUNTER_APPSFOLDER_FILETYPEASSOCIATION_COUNTER equ 55
        GLOBALCOUNTER_USERINFOCHANGED equ 56
        if (NTDDI_VERSION ge NTDDI_WINBLUE)
          GLOBALCOUNTER_SYNC_ENGINE_INFORMATION_CACHE_MACHINEWIDE equ 57
        endif
        ; (NTDDI_VERSION >= NTDDI_WINBLUE)
      endif
      ; (NTDDI_VERSION >= NTDDI_WIN8)
      if (NTDDI_VERSION ge NTDDI_WIN10_RS1)
        GLOBALCOUNTER_BANNERS_DATAMODEL_CACHE_MACHINEWIDE equ 58
      endif
      ; (NTDDI_VERSION >= NTDDI_WIN10_RS1)
      GLOBALCOUNTER_MAXIMUMVALUE equ 59

      ; should always be last value
      if (NTDDI_VERSION ge NTDDI_WIN7)
        @DefProto DllImport, SHGlobalCounterGetValue, WIN_STD_CALL_CONV,, <:SHGLOBALCOUNTER>, 4
        @DefProto DllImport, SHGlobalCounterIncrement, WIN_STD_CALL_CONV,, <:SHGLOBALCOUNTER>, 4
        @DefProto DllImport, SHGlobalCounterDecrement, WIN_STD_CALL_CONV,, <:SHGLOBALCOUNTER>, 4
      endif
      ; (NTDDI_VERSION >= NTDDI_WIN7)
      ; Shared memory apis
      if (_WIN32_IE ge 0603h)
        @DefProto DllImport, SHAllocShared, WIN_STD_CALL_CONV,, <:ptr, :DWORD, :DWORD>, 12
        @DefProto DllImport, SHFreeShared, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD>, 8
        @DefProto DllImport, SHLockShared, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD>, 8
        @DefProto DllImport, SHUnlockShared, WIN_STD_CALL_CONV,, <:ptr>, 4
      endif
      ; _WIN32_IE >= 0x0603
      @DefProto DllImport, WhichPlatform, WIN_STD_CALL_CONV,, <>, 0
      ; Return values of WhichPlatform
      PLATFORM_UNKNOWN equ 0
      PLATFORM_IE3 equ 1; obsolete: use PLATFORM_BROWSERONLY

      PLATFORM_BROWSERONLY equ 1; browser-only (no new shell)

      PLATFORM_INTEGRATED equ 2; integrated shell

      ;***   QueryInterface helpers
      ; NOTES
      ;  ATL has a fancier version of this.  if we need to extend ours, we
      ;  should probably just switch to ATL's rather than reinvent.
      ; EXAMPLE
      ;  Cfoo::QI(REFIID riid, void **ppv)
      ;  {
      ;      // (the IID_xxx comments make grep'ing work!)
      ;      static const QITAB qit = {
      ;          QITABENT(Cfoo, Iiface1),    // IID_Iiface1
      ;          ...
      ;          QITABENT(Cfoo, IifaceN),    // IID_IifaceN
      ;          { 0 },                      // n.b. don't forget the 0
      ;      };
      ;      // n.b. make sure you don't cast 'this'
      ;      hr = QISearch(this, qit, riid, ppv);
      ;      if (FAILED(hr))
      ;          hr = SUPER::QI(riid, ppv);
      ;      // custom code could be added here for FAILED() case
      ;      return hr;
      ;  }
      ;  If you have an interface that is implemented multiple times,
      ;  the compiler will claim an ambiguous cast, so you need to give
      ;  some help.  For example, if your class is defined as
      ;  class CClass : public IPersistStream, public IPersistFile
      ;  then you need to say
      ;      QITABENTMULTI(CClass, IPersist, IPersistStream)
      ;      QITABENT(CClass, IPersistStream)
      ;      QITABENT(CClass, IPersistFile)
      ;  The MULTI is needed for IPersist because the compiler doesn't
      ;  know whether you wanted the IPersist from IPersistStream
      ;  or the IPersist from IPersistFile.  Unless you have played weird
      ;  compiler tricks, they are the same implementation, so you can
      ;  just pick either one, doesn't matter.
      ;  Common mistake: You do not need to use MULTI if the base interface
      ;  can be unambiguously determined.  E.g.,
      ;  class CSimple : public IContextMenu3
      ;      QITABENT(CClass, IContextMenu)      // do not need MULTI
      ;      QITABENT(CClass, IContextMenu2)     // do not need MULTI
      ;      QITABENT(CClass, IContextMenu3)
      ;  Do not create an entry for IUnknown; the first entry in the
      ;  table will be used for IUnknown.
      QITAB struct
        piid POINTER ?
        dwOffset DWORD ?
      QITAB ends
      LPQITAB typedef ptr QITAB
      LPCQITAB typedef ptr QITAB
      ifdef __cplusplus
        ;[...]
      else
        QITABENTMULTI macro Cthis, Ifoo, Iimpl
          exitm <{ (IID *) and IID_ ## Ifoo, OFFSETOFCLASS(Iimpl, Cthis) }>
        endm
      endif
      ; __cplusplus
      QITABENTMULTI2 macro Cthis, Ifoo, Iimpl
        exitm <{ (IID *) and Ifoo, OFFSETOFCLASS(Iimpl, Cthis) }>
      endm
      QITABENT macro Cthis, Ifoo
        exitm <QITABENTMULTI(Cthis, Ifoo, Ifoo)>
      endm
      @DefProto DllImport, QISearch, WIN_STD_CALL_CONV,, <:ptr, :LPCQITAB, :REFIID, :ptr ptr>, 16
      ifndef STATIC_CAST
        ;***   STATIC_CAST -- 'portable' static_cast<>
        ; NOTES
        ;  do *not* use SAFE_CAST (see comment in OFFSETOFCLASS)
        STATIC_CAST macro typ
          exitm <static_cast < typ >>
        endm
        ifndef _X86_
          ; assume only intel compiler (>=vc5) supports static_cast for now
          ; we could key off of _MSC_VER >= 1100 but i'm not sure that will work
          ; a straight cast will give the correct result but no error checking,
          ; so we'll have to catch errors on intel.
          STATIC_CAST macro typ
            exitm <(typ)>
          endm
        endif
      endif
      ifndef OFFSETOFCLASS
        ;***   OFFSETOFCLASS -- (stolen from ATL)
        ; we use STATIC_CAST not SAFE_CAST because the compiler gets confused
        ; (it doesn't constant-fold the ,-op in SAFE_CAST so we end up generating
        ; code for the table!)
        OFFSETOFCLASS macro base, derived
          exitm <((STATIC_CAST(base *) ((derived *) 8)) - 8)>
        endm
      endif
      ; Types for SHIsLowMemoryMachine
      ILMM_IE4 equ 0; 1997-era machine

      @DefProto DllImport, SHIsLowMemoryMachine, WIN_STD_CALL_CONV,, <:DWORD>, 4
      ; Menu Helpers
      @DefProto DllImport, GetMenuPosFromID, WIN_STD_CALL_CONV,, <:HMENU, :UINT>, 8
      @DefProto DllImport, SHGetInverseCMAP, WIN_STD_CALL_CONV,, <:ptr BYTE, :ULONG>, 8
      ; SHAutoComplete
      ;      hwndEdit - HWND of editbox, ComboBox or ComboBoxEx.
      ;      dwFlags - Flags to indicate what to AutoAppend or AutoSuggest for the editbox.
      ; WARNING:
      ;    Caller needs to have called CoInitialize() or OleInitialize()
      ;    and cannot call CoUninit/OleUninit until after
      ;    WM_DESTROY on hwndEdit.
      ;  dwFlags values:
      SHACF_DEFAULT equ 00000000h; Currently (SHACF_FILESYSTEM | SHACF_URLALL)

      SHACF_FILESYSTEM equ 00000001h; This includes the File System as well as the rest of the shell (Desktop\My Computer\Control Panel\)

      SHACF_URLALL equ <(SHACF_URLHISTORY or SHACF_URLMRU)>
      SHACF_URLHISTORY equ 00000002h; URLs in the User's History

      SHACF_URLMRU equ 00000004h; URLs in the User's Recently Used list.

      SHACF_USETAB equ 00000008h; Use the tab to move thru the autocomplete possibilities instead of to the next dialog/window control.

      SHACF_FILESYS_ONLY equ 00000010h; This includes the File System

      if (_WIN32_IE ge 0600h)
        SHACF_FILESYS_DIRS equ 00000020h; Same as SHACF_FILESYS_ONLY except it only includes directories, UNC servers, and UNC server shares.

      endif
      ; (_WIN32_IE >= 0x0600)
      if (_WIN32_IE ge _WIN32_IE_IE70)
        SHACF_VIRTUAL_NAMESPACE equ 00000040h; Also include the virtual namespace

      endif
      ; _WIN32_IE_IE70
      SHACF_AUTOSUGGEST_FORCE_ON equ 10000000h; Ignore the registry default and force the feature on.

      SHACF_AUTOSUGGEST_FORCE_OFF equ 20000000h; Ignore the registry default and force the feature off.

      SHACF_AUTOAPPEND_FORCE_ON equ 40000000h; Ignore the registry default and force the feature on. (Also know as AutoComplete)

      SHACF_AUTOAPPEND_FORCE_OFF equ 80000000h; Ignore the registry default and force the feature off. (Also know as AutoComplete)

      @DefProto DllImport, SHAutoComplete, WIN_STD_CALL_CONV,, <:HWND, :DWORD>, 8
      if (_WIN32_IE ge _WIN32_IE_IE60SP2)
        @DefProto DllImport, SHCreateThreadRef, WIN_STD_CALL_CONV,, <:ptr LONG, :ptr ptr IUnknown>, 8
      endif
      ; _WIN32_IE_IE60SP2
      @DefProto DllImport, SHSetThreadRef, WIN_STD_CALL_CONV,, <:ptr IUnknown>, 4
      @DefProto DllImport, SHGetThreadRef, WIN_STD_CALL_CONV,, <:ptr ptr IUnknown>, 4
      @DefProto DllImport, SHSkipJunction, WIN_STD_CALL_CONV,, <:ptr IBindCtx, :ptr CLSID>, 8
      ; _WIN32_IE_IE60
      ; _WIN32_IE_IE70
      ; (NTDDI_VERSION >= NTDDI_VISTA)
      ; (NTDDI_VERSION >= NTDDI_WIN7)
      CTF_INSIST equ 00000001h
      ; call pfnThreadProc synchronously if CreateThread() fails
      CTF_THREAD_REF equ 00000002h
      ; hold a reference to the creating thread
      CTF_PROCESS_REF equ 00000004h
      ; hold a reference to the creating process
      CTF_COINIT_STA equ 00000008h
      ; init COM as STA for the created thread
      CTF_COINIT equ 00000008h
      ; init COM as STA for the created thread
      if (_WIN32_IE ge _WIN32_IE_IE60)
        CTF_FREELIBANDEXIT equ 00000010h
        ; hold a ref to the DLL and call FreeLibraryAndExitThread() when done
        CTF_REF_COUNTED equ 00000020h
        ; thread supports ref counting via SHGetThreadRef() or CTF_THREAD_REF so that child threads can keep this thread alive
        CTF_WAIT_ALLOWCOM equ 00000040h
        ; while waiting for pfnCallback, allow COM marshaling to the blocked calling thread
      endif
      ; _WIN32_IE_IE60
      if (_WIN32_IE ge _WIN32_IE_IE70)
        CTF_UNUSED equ 00000080h
        CTF_INHERITWOW64 equ 00000100h
        ; new thread should inherit the wow64 disable state for the file system redirector
      endif
      ; _WIN32_IE_IE70
      if (NTDDI_VERSION ge NTDDI_VISTA)
        CTF_WAIT_NO_REENTRANCY equ 00000200h
        ; don't allow re-entrancy when waiting for the sync proc, this won't work with marshalled objects or SendMessages() from the sync proc
      endif
      ; (NTDDI_VERSION >= NTDDI_VISTA)
      if (NTDDI_VERSION ge NTDDI_WIN7)
        CTF_KEYBOARD_LOCALE equ 00000400h
        ; carry the keyboard locale from creating to created thread
        CTF_OLEINITIALIZE equ 00000800h
        ; init OLE on the created thread (this will also init COM as STA)
        CTF_COINIT_MTA equ 00001000h
        ; init COM as MTA for the created thread
        CTF_NOADDREFLIB equ 00002000h
        ; this flag is the opposite of CTF_FREELIBANDEXIT that is now implicit as of Vista
        ; this avoids the LoadLibrary/FreeLibraryAndExitThread calls that result in contention for the loader lock
        ; only use this when the thread being created has some other means to ensure that the code
        ; of the thread proc will remain loaded. This should not be used in the context of COM objects as those
        ; need to ensure that the DLL stays loaded as COM will unload DLLs
      endif
      ; (NTDDI_VERSION >= NTDDI_WIN7)

      SHCT_FLAGS typedef DWORD
      ; SHCreateThread flags values
      @DefProto DllImport, SHCreateThread, WIN_STD_CALL_CONV,, <:LPTHREAD_START_ROUTINE, :ptr, :SHCT_FLAGS, :LPTHREAD_START_ROUTINE>, 16
      @DefProto DllImport, SHCreateThreadWithHandle, WIN_STD_CALL_CONV,, <:LPTHREAD_START_ROUTINE, :ptr, :SHCT_FLAGS, :LPTHREAD_START_ROUTINE, :ptr HANDLE>, 20
      if (NTDDI_VERSION ge NTDDI_WIN8)
        @DefProto DllImport, SetProcessReference, WIN_STD_CALL_CONV,, <:ptr IUnknown>, 4
        @DefProto DllImport, GetProcessReference, WIN_STD_CALL_CONV,, <:ptr ptr IUnknown>, 4
      endif
      ; (NTDDI_VERSION >= NTDDI_WIN8)
      if (_WIN32_IE ge _WIN32_IE_IE60)
        @DefProto DllImport, SHReleaseThreadRef, WIN_STD_CALL_CONV,, <>, 0
        ; release a CTF_THREAD_REF reference earlier than the return of pfnThreadProc
      endif
      ; _WIN32_IE_IE60
      ifndef NO_SHLWAPI_GDI
        ;====== GDI helper functions  ================================================
        @DefProto DllImport, SHCreateShellPalette, WIN_STD_CALL_CONV,, <:HDC>, 4
        @DefProto DllImport, ColorRGBToHLS, WIN_STD_CALL_CONV,, <:COLORREF, :ptr WORD, :ptr WORD, :ptr WORD>, 16
        @DefProto DllImport, ColorHLSToRGB, WIN_STD_CALL_CONV,, <:WORD, :WORD, :WORD>, 12
        @DefProto DllImport, ColorAdjustLuma, WIN_STD_CALL_CONV,, <:COLORREF, :SDWORD, :BOOL>, 12
      endif
      ; NO_SHLWAPI_GDI
      ;====== DllGetVersion  =======================================================
      DLLVERSIONINFO struct
        cbSize DWORD ?
        dwMajorVersion DWORD ?
        ; Major version
        dwMinorVersion DWORD ?
        ; Minor version
        dwBuildNumber DWORD ?
        ; Build number
        dwPlatformID DWORD ?
        ; DLLVER_PLATFORM_*
      DLLVERSIONINFO ends
      _DLLVERSIONINFO typedef DLLVERSIONINFO
      ; Platform IDs for DLLVERSIONINFO
      DLLVER_PLATFORM_WINDOWS equ 00000001h; Windows 95

      DLLVER_PLATFORM_NT equ 00000002h; Windows NT

      DLLVERSIONINFO2 struct
        info1 DLLVERSIONINFO <>
        dwFlags DWORD ?
        ; No flags currently defined
        ullVersion QWORD ?
        ; Encoded as:
        ; Major 0xFFFF 0000 0000 0000
        ; Minor 0x0000 FFFF 0000 0000
        ; Build 0x0000 0000 FFFF 0000
        ; QFE   0x0000 0000 0000 FFFF
      DLLVERSIONINFO2 ends
      _DLLVERSIONINFO2 typedef DLLVERSIONINFO2
      DLLVER_MAJOR_MASK equ 0FFFF000000000000h
      DLLVER_MINOR_MASK equ 0000FFFF00000000h
      DLLVER_BUILD_MASK equ 00000000FFFF0000h
      DLLVER_QFE_MASK equ 000000000000FFFFh
      MAKEDLLVERULL macro major, minor, build, qfe
        exitm <(((major) shl 48) or ((minor) shl 32) or ((build) shl 16) or ((qfe) shl 0))>
      endm
      ; The caller should always GetProcAddress("DllGetVersion"), not
      ; implicitly link to it.
      TYPE_DLLGETVERSIONPROC typedef proto WIN_STD_CALL_CONV :ptr DLLVERSIONINFO
      DLLGETVERSIONPROC typedef ptr TYPE_DLLGETVERSIONPROC

      ; DllInstall (to be implemented by self-installing DLLs)
      @DefProto DllImport, DllInstall, WIN_STD_CALL_CONV,, <:BOOL, :PCWSTR>, 8
      if (_WIN32_IE ge 0602h)
        ; Function to see if Internet Explorer Enhanced Security Configuration is active for the current user
        @DefProto DllImport, IsInternetESCEnabled, WIN_STD_CALL_CONV,, <>, 0
      endif
      ; (_WIN32_IE >= 0x0602)
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      ifdef __cplusplus
        ;[...]
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ifdef __cplusplus
        ;[...]
          ; _WIN32_IE_IE60
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      endif
      if Defined(DEPRECATE_SUPPORTED)
      endif
      ifdef _WIN32
        include poppack.inc
      endif
      if _MSC_VER ge 1200
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
    endif
    ; NOSHLWAPI
  endif
endif
; _INC_SHLWAPI
