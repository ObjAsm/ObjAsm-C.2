;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\Shlwapi.h', last modified: 19/04/2018 10:46
;Creation parameters: 

ifndef _INC_SHLWAPI
  _INC_SHLWAPI equ <>
  include winapifamily.inc
  ifndef NOSHLWAPI
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      include SpecStrings.inc
      include objbase.inc
      include shtypes.inc
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
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
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      if _MSC_VER ge 1200
      endif
      ifdef _WIN32
        include pshpack8.inc
      endif
      if Defined(DEPRECATE_SUPPORTED)
      endif
      ifndef __IBindCtx_FWD_DEFINED__
        __IBindCtx_FWD_DEFINED__ equ <>
        ;IBindCtx typedef IBindCtx
        
      endif
      ifdef __cplusplus
        ;[...]
      endif
      if Defined(__cplusplus) and Defined(STRICT_CONST)
        ;[...]
      endif
    endif
    ifndef NO_SHLWAPI_STRFCNS
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
        else
          @DefProto DllImport, StrChrA, WIN_STD_CALL_CONV,, <:PCSTR, :WORD>, 8
          @DefProto DllImport, StrChrW, WIN_STD_CALL_CONV,, <:PCWSTR, :WCHAR>, 8
          @DefProto DllImport, StrChrIA, WIN_STD_CALL_CONV,, <:PCSTR, :WORD>, 8
          @DefProto DllImport, StrChrIW, WIN_STD_CALL_CONV,, <:PCWSTR, :WCHAR>, 8
          if (_WIN32_IE ge _WIN32_IE_IE60)
            @DefProto DllImport, StrChrNW, WIN_STD_CALL_CONV,, <:PCWSTR, :WCHAR, :UINT>, 12
            @DefProto DllImport, StrChrNIW, WIN_STD_CALL_CONV,, <:PCWSTR, :WCHAR, :UINT>, 12
          endif
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
          tagSFBS_FLAGS typedef SDWORD
          SFBS_FLAGS_ROUND_TO_NEAREST_DISPLAYED_DIGIT equ 0001h
          SFBS_FLAGS_TRUNCATE_UNDISPLAYED_DECIMAL_DIGITS equ 0002h
          
          SFBS_FLAGS typedef SDWORD
          @DefProto DllImport, StrFormatByteSizeEx, WIN_STD_CALL_CONV,, <:ULONGLONG, :SFBS_FLAGS, :PWSTR, :UINT>, 20
        endif
        @DefProto DllImport, StrFormatByteSizeA, WIN_STD_CALL_CONV,, <:DWORD, :PSTR, :UINT>, 12
        @DefProto DllImport, StrFormatByteSize64A, WIN_STD_CALL_CONV,, <:LONGLONG, :PSTR, :UINT>, 16
        @DefProto DllImport, StrFormatByteSizeW, WIN_STD_CALL_CONV,, <:LONGLONG, :PWSTR, :UINT>, 16
        @DefProto DllImport, StrFormatKBSizeW, WIN_STD_CALL_CONV,, <:LONGLONG, :PWSTR, :UINT>, 16
        @DefProto DllImport, StrFormatKBSizeA, WIN_STD_CALL_CONV,, <:LONGLONG, :PSTR, :UINT>, 16
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
        else
          @DefProto DllImport, StrStrA, WIN_STD_CALL_CONV,, <:PCSTR, :PCSTR>, 8
          @DefProto DllImport, StrStrW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR>, 8
          @DefProto DllImport, StrStrIA, WIN_STD_CALL_CONV,, <:PCSTR, :PCSTR>, 8
          @DefProto DllImport, StrStrIW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR>, 8
          if (_WIN32_IE ge _WIN32_IE_IE60)
            @DefProto DllImport, StrStrNW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR, :UINT>, 12
            @DefProto DllImport, StrStrNIW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR, :UINT>, 12
          endif
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
        @DefProto DllImport, StrTrimA, WIN_STD_CALL_CONV,, <:PSTR, :PCSTR>, 8
        @DefProto DllImport, StrTrimW, WIN_STD_CALL_CONV,, <:PWSTR, :PCWSTR>, 8
        @DefProto DllImport, StrCatW_, WIN_STD_CALL_CONV,, <:PWSTR, :PCWSTR>, 8
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
        @DefProto DllImport, StrRetToBufA, WIN_STD_CALL_CONV,, <:ptr STRRET, :PCUITEMID_CHILD, :LPSTR, :UINT>, 16
        @DefProto DllImport, StrRetToBufW, WIN_STD_CALL_CONV,, <:ptr STRRET, :PCUITEMID_CHILD, :LPWSTR, :UINT>, 16
        ifdef UNICODE
          StrRetToBuf equ <StrRetToBufW>
        else
          StrRetToBuf equ <StrRetToBufA>
        endif
        @DefProto DllImport, SHStrDupA, WIN_STD_CALL_CONV,, <:LPCSTR, :ptr LPWSTR>, 8
        @DefProto DllImport, SHStrDupW, WIN_STD_CALL_CONV,, <:LPCWSTR, :ptr LPWSTR>, 8
        ifdef UNICODE
          SHStrDup equ <SHStrDupW>
        else
          SHStrDup equ <SHStrDupA>
        endif
        ifdef __cplusplus
          ;[...]
        endif
        @DefProto DllImport, StrCmpLogicalW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR>, 8
        @DefProto DllImport, StrCatChainW, WIN_STD_CALL_CONV,, <:PWSTR, :DWORD, :DWORD, :PCWSTR>, 16
        @DefProto DllImport, StrRetToBSTR, WIN_STD_CALL_CONV,, <:ptr STRRET, :PCUITEMID_CHILD, :ptr BSTR>, 12
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
        @DefProto DllImport, SHLoadIndirectString, WIN_STD_CALL_CONV,, <:PCWSTR, :PWSTR, :UINT, :ptr ptr>, 16
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
          @DefProto DllImport, StrCmpCA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR>, 8
          @DefProto DllImport, StrCmpCW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR>, 8
          ifdef UNICODE
            StrCmpC equ <StrCmpCW>
          else
            StrCmpC equ <StrCmpCA>
          endif
          @DefProto DllImport, StrCmpICA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR>, 8
          @DefProto DllImport, StrCmpICW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR>, 8
          ifdef UNICODE
            StrCmpIC equ <StrCmpICW>
          else
            StrCmpIC equ <StrCmpICA>
          endif
        endif
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
        @DefProto DllImport, StrCmpNCA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :SDWORD>, 12
        @DefProto DllImport, StrCmpNCW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :SDWORD>, 12
        ifdef UNICODE
          StrCmpNC equ <StrCmpNCW>
        else
          StrCmpNC equ <StrCmpNCA>
        endif
        @DefProto DllImport, StrCmpNICA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :SDWORD>, 12
        @DefProto DllImport, StrCmpNICW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :SDWORD>, 12
        ifdef UNICODE
          StrCmpNIC equ <StrCmpNICW>
        else
          StrCmpNIC equ <StrCmpNICA>
        endif
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
        StrCatA_ equ <lstrcatA>
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
      endif
    endif
    ifndef NO_SHLWAPI_PATH
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, PathAddBackslashA, WIN_STD_CALL_CONV,, <:LPSTR>, 4
        @DefProto DllImport, PathAddBackslashW, WIN_STD_CALL_CONV,, <:LPWSTR>, 4
        ifdef UNICODE
          PathAddBackslash equ <PathAddBackslashW>
        else
          PathAddBackslash equ <PathAddBackslashA>
        endif
        @DefProto DllImport, PathAddExtensionA, WIN_STD_CALL_CONV,, <:LPSTR, :LPCSTR>, 8
        @DefProto DllImport, PathAddExtensionW, WIN_STD_CALL_CONV,, <:LPWSTR, :LPCWSTR>, 8
        ifdef UNICODE
          PathAddExtension equ <PathAddExtensionW>
        else
          PathAddExtension equ <PathAddExtensionA>
        endif
        @DefProto DllImport, PathAppendA, WIN_STD_CALL_CONV,, <:LPSTR, :LPCSTR>, 8
        @DefProto DllImport, PathAppendW, WIN_STD_CALL_CONV,, <:LPWSTR, :LPCWSTR>, 8
        @DefProto DllImport, PathBuildRootA, WIN_STD_CALL_CONV,, <:LPSTR, :SDWORD>, 8
        @DefProto DllImport, PathBuildRootW, WIN_STD_CALL_CONV,, <:LPWSTR, :SDWORD>, 8
        ifdef UNICODE
          PathBuildRoot equ <PathBuildRootW>
        else
          PathBuildRoot equ <PathBuildRootA>
        endif
        @DefProto DllImport, PathCanonicalizeA, WIN_STD_CALL_CONV,, <:LPSTR, :LPCSTR>, 8
        @DefProto DllImport, PathCanonicalizeW, WIN_STD_CALL_CONV,, <:LPWSTR, :LPCWSTR>, 8
        @DefProto DllImport, PathCombineA, WIN_STD_CALL_CONV,, <:LPSTR, :LPCSTR, :LPCSTR>, 12
        @DefProto DllImport, PathCombineW, WIN_STD_CALL_CONV,, <:LPWSTR, :LPCWSTR, :LPCWSTR>, 12
        ifdef UNICODE
          PathCombine equ <PathCombineW>
        else
          PathCombine equ <PathCombineA>
        endif
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
        ifdef USE_STRICT_CONST
          @DefProto DllImport, PathFindExtensionA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
          @DefProto DllImport, PathFindExtensionW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
          ifdef UNICODE
            PathFindExtension equ <PathFindExtensionW>
          else
            PathFindExtension equ <PathFindExtensionA>
          endif
          @DefProto DllImport, PathFindFileNameA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
          @DefProto DllImport, PathFindFileNameW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
          ifdef UNICODE
            PathFindFileName equ <PathFindFileNameW>
          else
            PathFindFileName equ <PathFindFileNameA>
          endif
          @DefProto DllImport, PathFindNextComponentA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
          @DefProto DllImport, PathFindNextComponentW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
          ifdef UNICODE
            PathFindNextComponent equ <PathFindNextComponentW>
          else
            PathFindNextComponent equ <PathFindNextComponentA>
          endif
        else
          @DefProto DllImport, PathFindExtensionA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
          @DefProto DllImport, PathFindExtensionW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
          ifdef UNICODE
            PathFindExtension equ <PathFindExtensionW>
          else
            PathFindExtension equ <PathFindExtensionA>
          endif
          @DefProto DllImport, PathFindFileNameA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
          @DefProto DllImport, PathFindFileNameW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
          ifdef UNICODE
            PathFindFileName equ <PathFindFileNameW>
          else
            PathFindFileName equ <PathFindFileNameA>
          endif
          @DefProto DllImport, PathFindNextComponentA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
          @DefProto DllImport, PathFindNextComponentW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
          ifdef UNICODE
            PathFindNextComponent equ <PathFindNextComponentW>
          else
            PathFindNextComponent equ <PathFindNextComponentA>
          endif
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
        ifdef USE_STRICT_CONST
          @DefProto DllImport, PathGetArgsA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
          @DefProto DllImport, PathGetArgsW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
          ifdef UNICODE
            PathGetArgs equ <PathGetArgsW>
          else
            PathGetArgs equ <PathGetArgsA>
          endif
        else
          @DefProto DllImport, PathGetArgsA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
          @DefProto DllImport, PathGetArgsW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
          ifdef UNICODE
            PathGetArgs equ <PathGetArgsW>
          else
            PathGetArgs equ <PathGetArgsA>
          endif
        endif
        @DefProto DllImport, PathIsLFNFileSpecA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
        @DefProto DllImport, PathIsLFNFileSpecW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
        ifdef UNICODE
          PathIsLFNFileSpec equ <PathIsLFNFileSpecW>
        else
          PathIsLFNFileSpec equ <PathIsLFNFileSpecA>
        endif
        @DefProto DllImport, PathGetCharTypeA, WIN_STD_CALL_CONV,, <:UCHAR>, 4
        @DefProto DllImport, PathGetCharTypeW, WIN_STD_CALL_CONV,, <:WCHAR>, 4
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
        @DefProto DllImport, PathIsDirectoryA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
        @DefProto DllImport, PathIsDirectoryW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
        ifdef UNICODE
          PathIsDirectory equ <PathIsDirectoryW>
        else
          PathIsDirectory equ <PathIsDirectoryA>
        endif
        @DefProto DllImport, PathIsDirectoryEmptyA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
        @DefProto DllImport, PathIsDirectoryEmptyW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
        ifdef UNICODE
          PathIsDirectoryEmpty equ <PathIsDirectoryEmptyW>
        else
          PathIsDirectoryEmpty equ <PathIsDirectoryEmptyA>
        endif
        @DefProto DllImport, PathIsFileSpecA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
        @DefProto DllImport, PathIsFileSpecW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
        ifdef UNICODE
          PathIsFileSpec equ <PathIsFileSpecW>
        else
          PathIsFileSpec equ <PathIsFileSpecA>
        endif
        @DefProto DllImport, PathIsPrefixA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR>, 8
        @DefProto DllImport, PathIsPrefixW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR>, 8
        ifdef UNICODE
          PathIsPrefix equ <PathIsPrefixW>
        else
          PathIsPrefix equ <PathIsPrefixA>
        endif
        @DefProto DllImport, PathIsRelativeA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
        @DefProto DllImport, PathIsRelativeW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
        ifdef UNICODE
          PathIsRelative equ <PathIsRelativeW>
        else
          PathIsRelative equ <PathIsRelativeA>
        endif
        @DefProto DllImport, PathIsRootA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
        @DefProto DllImport, PathIsRootW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
        ifdef UNICODE
          PathIsRoot equ <PathIsRootW>
        else
          PathIsRoot equ <PathIsRootA>
        endif
        @DefProto DllImport, PathIsSameRootA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR>, 8
        @DefProto DllImport, PathIsSameRootW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR>, 8
        ifdef UNICODE
          PathIsSameRoot equ <PathIsSameRootW>
        else
          PathIsSameRoot equ <PathIsSameRootA>
        endif
        @DefProto DllImport, PathIsUNCA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
        @DefProto DllImport, PathIsUNCW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
        ifdef UNICODE
          PathIsUNC equ <PathIsUNCW>
        else
          PathIsUNC equ <PathIsUNCA>
        endif
        @DefProto DllImport, PathIsNetworkPathA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
        @DefProto DllImport, PathIsNetworkPathW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
        ifdef UNICODE
          PathIsNetworkPath equ <PathIsNetworkPathW>
        else
          PathIsNetworkPath equ <PathIsNetworkPathA>
        endif
        @DefProto DllImport, PathIsUNCServerA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
        @DefProto DllImport, PathIsUNCServerW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
        ifdef UNICODE
          PathIsUNCServer equ <PathIsUNCServerW>
        else
          PathIsUNCServer equ <PathIsUNCServerA>
        endif
        @DefProto DllImport, PathIsUNCServerShareA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
        @DefProto DllImport, PathIsUNCServerShareW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
        ifdef UNICODE
          PathIsUNCServerShare equ <PathIsUNCServerShareW>
        else
          PathIsUNCServerShare equ <PathIsUNCServerShareA>
        endif
        @DefProto DllImport, PathIsContentTypeA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR>, 8
        @DefProto DllImport, PathIsContentTypeW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR>, 8
        @DefProto DllImport, PathIsURLA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
        @DefProto DllImport, PathIsURLW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
        ifdef UNICODE
          PathIsURL equ <PathIsURLW>
        else
          PathIsURL equ <PathIsURLA>
        endif
        @DefProto DllImport, PathMakePrettyA, WIN_STD_CALL_CONV,, <:LPSTR>, 4
        @DefProto DllImport, PathMakePrettyW, WIN_STD_CALL_CONV,, <:LPWSTR>, 4
        @DefProto DllImport, PathMatchSpecA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR>, 8
        @DefProto DllImport, PathMatchSpecW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR>, 8
        if (_WIN32_IE ge _WIN32_IE_IE70)
          PMSF_NORMAL equ 00000000h
          PMSF_MULTIPLE equ 00000001h
          PMSF_DONT_STRIP_SPACES equ 00010000h
          @DefProto DllImport, PathMatchSpecExA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :DWORD>, 12
          @DefProto DllImport, PathMatchSpecExW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :DWORD>, 12
        endif
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
        else
          @DefProto DllImport, PathSkipRootA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
          @DefProto DllImport, PathSkipRootW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
          ifdef UNICODE
            PathSkipRoot equ <PathSkipRootW>
          else
            PathSkipRoot equ <PathSkipRootA>
          endif
        endif
        @DefProto DllImport, PathStripPathA, WIN_STD_CALL_CONV,, <:LPSTR>, 4
        @DefProto DllImport, PathStripPathW, WIN_STD_CALL_CONV,, <:LPWSTR>, 4
        ifdef UNICODE
          PathStripPath equ <PathStripPathW>
        else
          PathStripPath equ <PathStripPathA>
        endif
        @DefProto DllImport, PathStripToRootA, WIN_STD_CALL_CONV,, <:LPSTR>, 4
        @DefProto DllImport, PathStripToRootW, WIN_STD_CALL_CONV,, <:LPWSTR>, 4
        ifdef UNICODE
          PathStripToRoot equ <PathStripToRootW>
        else
          PathStripToRoot equ <PathStripToRootA>
        endif
        @DefProto DllImport, PathUnquoteSpacesA, WIN_STD_CALL_CONV,, <:LPSTR>, 4
        @DefProto DllImport, PathUnquoteSpacesW, WIN_STD_CALL_CONV,, <:LPWSTR>, 4
        @DefProto DllImport, PathMakeSystemFolderA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
        @DefProto DllImport, PathMakeSystemFolderW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
        ifdef UNICODE
          PathMakeSystemFolder equ <PathMakeSystemFolderW>
        else
          PathMakeSystemFolder equ <PathMakeSystemFolderA>
        endif
        @DefProto DllImport, PathUnmakeSystemFolderA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
        @DefProto DllImport, PathUnmakeSystemFolderW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
        ifdef UNICODE
          PathUnmakeSystemFolder equ <PathUnmakeSystemFolderW>
        else
          PathUnmakeSystemFolder equ <PathUnmakeSystemFolderA>
        endif
        @DefProto DllImport, PathIsSystemFolderA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD>, 8
        @DefProto DllImport, PathIsSystemFolderW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD>, 8
        ifdef UNICODE
          PathIsSystemFolder equ <PathIsSystemFolderW>
        else
          PathIsSystemFolder equ <PathIsSystemFolderA>
        endif
        @DefProto DllImport, PathUndecorateA, WIN_STD_CALL_CONV,, <:LPSTR>, 4
        @DefProto DllImport, PathUndecorateW, WIN_STD_CALL_CONV,, <:LPWSTR>, 4
        ifdef UNICODE
          PathUndecorate equ <PathUndecorateW>
        else
          PathUndecorate equ <PathUndecorateA>
        endif
        @DefProto DllImport, PathUnExpandEnvStringsA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPSTR, :UINT>, 12
        @DefProto DllImport, PathUnExpandEnvStringsW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPWSTR, :UINT>, 12
        ifdef UNICODE
          PathUnExpandEnvStrings equ <PathUnExpandEnvStringsW>
        else
          PathUnExpandEnvStrings equ <PathUnExpandEnvStringsA>
        endif
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
        if (_WIN32_IE ge _WIN32_IE_IE70)
          URL_SCHEME_MSSHELLDEVICE equ 22
          URL_SCHEME_WILDCARD equ 23
        endif
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
        URL_INTERNAL_PATH equ 00800000h
        URL_FILE_USE_PATHURL equ 00010000h
        if (_WIN32_IE ge _WIN32_IE_IE60SP2)
          URL_DONT_UNESCAPE equ 00020000h
        endif
        if (NTDDI_VERSION ge NTDDI_WIN7)
          URL_ESCAPE_AS_UTF8 equ 00040000h
        endif
        if (NTDDI_VERSION ge NTDDI_WIN8)
          URL_UNESCAPE_AS_UTF8 equ <URL_ESCAPE_AS_UTF8>
          URL_ESCAPE_ASCII_URI_COMPONENT equ 00080000h
          URL_ESCAPE_URI_COMPONENT equ <(URL_ESCAPE_ASCII_URI_COMPONENT or URL_ESCAPE_AS_UTF8)>
          URL_UNESCAPE_URI_COMPONENT equ <URL_UNESCAPE_AS_UTF8>
        endif
        URL_ESCAPE_PERCENT equ 00001000h
        URL_ESCAPE_SEGMENT_ONLY equ 00002000h
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
        endif
        UrlEscapeSpaces macro pszUrl, pszEscaped, pcchEscaped
          exitm <UrlCanonicalize (pszUrl, pszEscaped, pcchEscaped, URL_ESCAPE_SPACES_ONLY or URL_DONT_ESCAPE_EXTRA_INFO)>
        endm
        UrlUnescapeInPlace macro pszUrl, dwFlags
          exitm <UrlUnescape (pszUrl, NULL, NULL, dwFlags or URL_UNESCAPE_INPLACE)>
        endm
        PARSEDURLA struct
          cbSize DWORD ?
          pszProtocol LPCSTR ?
          cchProtocol UINT ?
          pszSuffix LPCSTR ?
          cchSuffix UINT ?
          nScheme UINT ?
        PARSEDURLA ends

        tagPARSEDURLA typedef PARSEDURLA
        PPARSEDURLA typedef ptr PARSEDURLA
        
        PARSEDURLW struct
          cbSize DWORD ?
          pszProtocol LPCWSTR ?
          cchProtocol UINT ?
          pszSuffix LPCWSTR ?
          cchSuffix UINT ?
          nScheme UINT ?
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
        @DefProto DllImport, ParseURLA, WIN_STD_CALL_CONV,, <:LPCSTR, :ptr PARSEDURLA>, 8
        @DefProto DllImport, ParseURLW, WIN_STD_CALL_CONV,, <:LPCWSTR, :ptr PARSEDURLW>, 8
        ifdef UNICODE
          ParseURL equ <ParseURLW>
        else
          ParseURL equ <ParseURLA>
        endif
      endif
    endif
    ifndef NO_SHLWAPI_REG
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, SHDeleteEmptyKeyA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR>, 8
        @DefProto DllImport, SHDeleteEmptyKeyW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR>, 8
        ifdef UNICODE
          SHDeleteEmptyKey equ <SHDeleteEmptyKeyW>
        else
          SHDeleteEmptyKey equ <SHDeleteEmptyKeyA>
        endif
        @DefProto DllImport, SHDeleteKeyA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR>, 8
        @DefProto DllImport, SHDeleteKeyW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR>, 8
        ifdef UNICODE
          SHDeleteKey equ <SHDeleteKeyW>
        else
          SHDeleteKey equ <SHDeleteKeyA>
        endif
        @DefProto DllImport, SHRegDuplicateHKey, WIN_STD_CALL_CONV,, <:HKEY>, 4
        @DefProto DllImport, SHDeleteValueA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :LPCSTR>, 12
        @DefProto DllImport, SHDeleteValueW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :LPCWSTR>, 12
        ifdef UNICODE
          SHDeleteValue equ <SHDeleteValueW>
        else
          SHDeleteValue equ <SHDeleteValueA>
        endif
        @DefProto DllImport, SHGetValueA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :LPCSTR, :ptr DWORD, :ptr, :ptr DWORD>, 24
        @DefProto DllImport, SHGetValueW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :LPCWSTR, :ptr DWORD, :ptr, :ptr DWORD>, 24
        ifdef UNICODE
          SHGetValue equ <SHGetValueW>
        else
          SHGetValue equ <SHGetValueA>
        endif
        @DefProto DllImport, SHSetValueA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :LPCSTR, :DWORD, :LPCVOID, :DWORD>, 24
        @DefProto DllImport, SHSetValueW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :LPCWSTR, :DWORD, :LPCVOID, :DWORD>, 24
        ifdef UNICODE
          SHSetValue equ <SHSetValueW>
        else
          SHSetValue equ <SHSetValueA>
        endif
        if (_WIN32_IE ge 0602h)
          SRRF typedef SDWORD
          SRRF_RT_REG_NONE equ 00000001h
          SRRF_RT_REG_SZ equ 00000002h
          SRRF_RT_REG_EXPAND_SZ equ 00000004h
          SRRF_RT_REG_BINARY equ 00000008h
          SRRF_RT_REG_DWORD equ 00000010h
          SRRF_RT_REG_MULTI_SZ equ 00000020h
          SRRF_RT_REG_QWORD equ 00000040h
          SRRF_RT_DWORD equ <(SRRF_RT_REG_BINARY or SRRF_RT_REG_DWORD)>
          SRRF_RT_QWORD equ <(SRRF_RT_REG_BINARY or SRRF_RT_REG_QWORD)>
          SRRF_RT_ANY equ 0000ffffh
          SRRF_RM_ANY equ 00000000h
          SRRF_RM_NORMAL equ 00010000h
          SRRF_RM_SAFE equ 00020000h
          SRRF_RM_SAFENETWORK equ 00040000h
          SRRF_NOEXPAND equ 10000000h
          SRRF_ZEROONFAILURE equ 20000000h
          SRRF_NOVIRT equ 40000000h
          @DefProto DllImport, SHRegGetValueA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :LPCSTR, :SRRF, :ptr DWORD, :ptr, :ptr DWORD>, 28
          @DefProto DllImport, SHRegGetValueW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :LPCWSTR, :SRRF, :ptr DWORD, :ptr, :ptr DWORD>, 28
          ifdef UNICODE
            SHRegGetValue equ <SHRegGetValueW>
          else
            SHRegGetValue equ <SHRegGetValueA>
          endif
          @DefProto DllImport, SHRegSetValue, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :LPCWSTR, :SRRF, :DWORD, :LPCVOID, :DWORD>, 28
          @DefProto DllImport, SHRegGetValueFromHKCUHKLM, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR, :SRRF, :ptr DWORD, :ptr, :ptr DWORD>, 24
          @DefProto DllImport, SHRegGetBoolValueFromHKCUHKLM, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR, :BOOL>, 12
        endif
        @DefProto DllImport, SHQueryValueExA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :ptr DWORD, :ptr DWORD, :ptr, :ptr DWORD>, 24
        @DefProto DllImport, SHQueryValueExW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :ptr DWORD, :ptr DWORD, :ptr, :ptr DWORD>, 24
        ifdef UNICODE
          SHQueryValueEx equ <SHQueryValueExW>
        else
          SHQueryValueEx equ <SHQueryValueExA>
        endif
        @DefProto DllImport, SHEnumKeyExA, WIN_STD_CALL_CONV,, <:HKEY, :DWORD, :LPSTR, :LPDWORD>, 16
        @DefProto DllImport, SHEnumKeyExW, WIN_STD_CALL_CONV,, <:HKEY, :DWORD, :LPWSTR, :LPDWORD>, 16
        @DefProto DllImport, SHEnumValueA, WIN_STD_CALL_CONV,, <:HKEY, :DWORD, :PSTR, :LPDWORD, :LPDWORD, :ptr, :LPDWORD>, 28
        @DefProto DllImport, SHEnumValueW, WIN_STD_CALL_CONV,, <:HKEY, :DWORD, :PWSTR, :LPDWORD, :LPDWORD, :ptr, :LPDWORD>, 28
        @DefProto DllImport, SHQueryInfoKeyA, WIN_STD_CALL_CONV,, <:HKEY, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD>, 20
        @DefProto DllImport, SHQueryInfoKeyW, WIN_STD_CALL_CONV,, <:HKEY, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD>, 20
        @DefProto DllImport, SHCopyKeyA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :HKEY, :DWORD>, 16
        @DefProto DllImport, SHCopyKeyW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :HKEY, :DWORD>, 16
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
        SHREGDEL_FLAGS typedef SDWORD
        SHREGDEL_DEFAULT equ 00000000h
        SHREGDEL_HKCU equ 00000001h
        SHREGDEL_HKLM equ 00000010h
        SHREGDEL_BOTH equ 00000011h
        
        SHREGENUM_FLAGS typedef SDWORD
        SHREGENUM_DEFAULT equ 00000000h
        SHREGENUM_HKCU equ 00000001h
        SHREGENUM_HKLM equ 00000010h
        SHREGENUM_BOTH equ 00000011h
        
        SHREGSET_HKCU equ 00000001h
        SHREGSET_FORCE_HKCU equ 00000002h
        SHREGSET_HKLM equ 00000004h
        SHREGSET_FORCE_HKLM equ 00000008h
        SHREGSET_DEFAULT equ <(SHREGSET_FORCE_HKCU or SHREGSET_HKLM)>
        HUSKEY typedef HANDLE
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
        ASSOCF_NONE equ 00000000h
        ASSOCF_INIT_NOREMAPCLSID equ 00000001h
        ASSOCF_INIT_BYEXENAME equ 00000002h
        ASSOCF_OPEN_BYEXENAME equ 00000002h
        ASSOCF_INIT_DEFAULTTOSTAR equ 00000004h
        ASSOCF_INIT_DEFAULTTOFOLDER equ 00000008h
        ASSOCF_NOUSERSETTINGS equ 00000010h
        ASSOCF_NOTRUNCATE equ 00000020h
        ASSOCF_VERIFY equ 00000040h
        ASSOCF_REMAPRUNDLL equ 00000080h
        ASSOCF_NOFIXUPS equ 00000100h
        ASSOCF_IGNOREBASECLASS equ 00000200h
        ASSOCF_INIT_IGNOREUNKNOWN equ 00000400h
        if (NTDDI_VERSION ge NTDDI_WIN8)
          ASSOCF_INIT_FIXED_PROGID equ 00000800h
          ASSOCF_IS_PROTOCOL equ 00001000h
          ASSOCF_INIT_FOR_FILE equ 00002000h
        endif
        if (NTDDI_VERSION ge NTDDI_WIN10_RS1)
          ASSOCF_IS_FULL_URI equ 00004000h
          ASSOCF_PER_MACHINE_ONLY equ 00008000h
        endif
        if (NTDDI_VERSION ge NTDDI_WIN10_RS4)
          ASSOCF_APP_TO_APP equ 00010000h
        endif
        
        ASSOCF typedef DWORD
        ASSOCSTR typedef SDWORD
        ASSOCSTR_COMMAND equ 1
        ASSOCSTR_EXECUTABLE equ 2
        ASSOCSTR_FRIENDLYDOCNAME equ 3
        ASSOCSTR_FRIENDLYAPPNAME equ 4
        ASSOCSTR_NOOPEN equ 5
        ASSOCSTR_SHELLNEWVALUE equ 6
        ASSOCSTR_DDECOMMAND equ 7
        ASSOCSTR_DDEIFEXEC equ 8
        ASSOCSTR_DDEAPPLICATION equ 9
        ASSOCSTR_DDETOPIC equ 10
        ASSOCSTR_INFOTIP equ 11
        if (_WIN32_IE ge _WIN32_IE_IE60)
          ASSOCSTR_QUICKTIP equ 12
          ASSOCSTR_TILEINFO equ 13
          ASSOCSTR_CONTENTTYPE equ 14
          ASSOCSTR_DEFAULTICON equ 15
          ASSOCSTR_SHELLEXTENSION equ 16
        endif
        if (_WIN32_IE ge _WIN32_IE_IE80)
          ASSOCSTR_DROPTARGET equ 17
          ASSOCSTR_DELEGATEEXECUTE equ 18
        endif
        ASSOCSTR_SUPPORTED_URI_PROTOCOLS equ 19
        if (NTDDI_VERSION ge NTDDI_WIN10)
          ASSOCSTR_PROGID equ 20
          ASSOCSTR_APPID equ 21
          ASSOCSTR_APPPUBLISHER equ 22
          ASSOCSTR_APPICONREFERENCE equ 23
        endif
        ASSOCSTR_MAX equ 24
        
        ASSOCKEY typedef SDWORD
        ASSOCKEY_SHELLEXECCLASS equ 1
        ASSOCKEY_APP equ 2
        ASSOCKEY_CLASS equ 3
        ASSOCKEY_BASECLASS equ 4
        ASSOCKEY_MAX equ 5
        
        ASSOCDATA typedef SDWORD
        ASSOCDATA_MSIDESCRIPTOR equ 1
        ASSOCDATA_NOACTIVATEHANDLER equ 2
        ASSOCDATA_UNUSED1 equ 3
        ASSOCDATA_HASPERUSERASSOC equ 4
        if (_WIN32_IE ge _WIN32_IE_IE60)
          ASSOCDATA_EDITFLAGS equ 5
          ASSOCDATA_VALUE equ 6
        endif
        ASSOCDATA_MAX equ 7
        
        ASSOCENUM typedef SDWORD
        ASSOCENUM_NONE equ 0
        
        FILETYPEATTRIBUTEFLAGS typedef SDWORD
        FTA_None equ 00000000h
        FTA_Exclude equ 00000001h
        FTA_Show equ 00000002h
        FTA_HasExtension equ 00000004h
        FTA_NoEdit equ 00000008h
        FTA_NoRemove equ 00000010h
        FTA_NoNewVerb equ 00000020h
        FTA_NoEditVerb equ 00000040h
        FTA_NoRemoveVerb equ 00000080h
        FTA_NoEditDesc equ 00000100h
        FTA_NoEditIcon equ 00000200h
        FTA_NoEditDflt equ 00000400h
        FTA_NoEditVerbCmd equ 00000800h
        FTA_NoEditVerbExe equ 00001000h
        FTA_NoDDE equ 00002000h
        FTA_NoEditMIME equ 00008000h
        FTA_OpenIsSafe equ 00010000h
        FTA_AlwaysUnsafe equ 00020000h
        FTA_NoRecentDocs equ 00100000h
        FTA_SafeForElevation equ 00200000h
        FTA_AlwaysUseDirectInvoke equ 00400000h
        
        DEFINE_ENUM_FLAG_OPERATORS(FILETYPEATTRIBUTEFLAGS)
        INTERFACE equ <IQueryAssociations>
        DECLARE_INTERFACE_IID_ IQueryAssociations, IUnknown, "c46ca590-3c3f-11d2-bee6-0000f805ca57"
          STD_METHOD Init, :THIS_, :LPCWSTR, :HKEY, :HWND
          STD_METHOD GetString, :THIS_, :ASSOCSTR, :LPCWSTR, :LPWSTR, :ptr DWORD
          STD_METHOD GetKey, :THIS_, :ASSOCKEY, :LPCWSTR, :ptr HKEY
          STD_METHOD GetData, :THIS_, :ASSOCDATA, :LPCWSTR, :ptr, :ptr DWORD
          STD_METHOD GetEnum, :THIS_, :ASSOCENUM, :LPCWSTR, :REFIID, :ptr ptr
        END_DECLARE_INTERFACE_IID_
        @DefProto DllImport, AssocCreate, WIN_STD_CALL_CONV,, <:CLSID, :REFIID, :ptr ptr>, 12
        @DefProto DllImport, SHGetAssocKeys, WIN_STD_CALL_CONV,, <:ptr IQueryAssociations, :ptr HKEY, :DWORD>, 12
        @DefProto DllImport, AssocQueryStringA, WIN_STD_CALL_CONV,, <:ASSOCF, :ASSOCSTR, :LPCSTR, :LPCSTR, :LPSTR, :ptr DWORD>, 24
        @DefProto DllImport, AssocQueryStringW, WIN_STD_CALL_CONV,, <:ASSOCF, :ASSOCSTR, :LPCWSTR, :LPCWSTR, :LPWSTR, :ptr DWORD>, 24
        ifdef UNICODE
          AssocQueryString equ <AssocQueryStringW>
        else
          AssocQueryString equ <AssocQueryStringA>
        endif
        @DefProto DllImport, AssocQueryStringByKeyA, WIN_STD_CALL_CONV,, <:ASSOCF, :ASSOCSTR, :HKEY, :LPCSTR, :LPSTR, :ptr DWORD>, 24
        @DefProto DllImport, AssocQueryStringByKeyW, WIN_STD_CALL_CONV,, <:ASSOCF, :ASSOCSTR, :HKEY, :LPCWSTR, :LPWSTR, :ptr DWORD>, 24
        ifdef UNICODE
          AssocQueryStringByKey equ <AssocQueryStringByKeyW>
        else
          AssocQueryStringByKey equ <AssocQueryStringByKeyA>
        endif
        @DefProto DllImport, AssocQueryKeyA, WIN_STD_CALL_CONV,, <:ASSOCF, :ASSOCKEY, :LPCSTR, :LPCSTR, :ptr HKEY>, 20
        @DefProto DllImport, AssocQueryKeyW, WIN_STD_CALL_CONV,, <:ASSOCF, :ASSOCKEY, :LPCWSTR, :LPCWSTR, :ptr HKEY>, 20
        ifdef UNICODE
          AssocQueryKey equ <AssocQueryKeyW>
        else
          AssocQueryKey equ <AssocQueryKeyA>
        endif
        if (_WIN32_IE ge 0601h)
          @DefProto DllImport, AssocIsDangerous, WIN_STD_CALL_CONV,, <:PCWSTR>, 4
        endif
        if (_WIN32_IE ge _WIN32_IE_IE60SP2)
          @DefProto DllImport, AssocGetPerceivedType, WIN_STD_CALL_CONV,, <:PCWSTR, :ptr PERCEIVED, :ptr PERCEIVEDFLAG, :ptr PWSTR>, 16
        endif
      endif
    endif
    ifndef NO_SHLWAPI_STREAM
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        ifndef __IStream_FWD_DEFINED__
          __IStream_FWD_DEFINED__ equ <>
          ;IStream typedef IStream
          
        endif
        @DefProto DllImport, SHOpenRegStreamA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :LPCSTR, :DWORD>, 16
        @DefProto DllImport, SHOpenRegStreamW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :LPCWSTR, :DWORD>, 16
        ifdef UNICODE
          SHOpenRegStream equ <SHOpenRegStreamW>
        else
          SHOpenRegStream equ <SHOpenRegStreamA>
        endif
        @DefProto DllImport, SHOpenRegStream2A, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :LPCSTR, :DWORD>, 16
        @DefProto DllImport, SHOpenRegStream2W, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :LPCWSTR, :DWORD>, 16
        ifdef UNICODE
          SHOpenRegStream2 equ <SHOpenRegStream2W>
        else
          SHOpenRegStream2 equ <SHOpenRegStream2A>
        endif
        SHOpenRegStream equ <SHOpenRegStream2>
        @DefProto DllImport, SHCreateStreamOnFileA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :ptr ptr IStream>, 12
        @DefProto DllImport, SHCreateStreamOnFileW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :ptr ptr IStream>, 12
        ifdef UNICODE
          SHCreateStreamOnFile equ <SHCreateStreamOnFileW>
        else
          SHCreateStreamOnFile equ <SHCreateStreamOnFileA>
        endif
        if (_WIN32_IE ge 0600h)
          @DefProto DllImport, SHCreateStreamOnFileEx, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :DWORD, :BOOL, :ptr IStream, :ptr ptr IStream>, 24
        endif
        @DefProto DllImport, SHCreateMemStream, WIN_STD_CALL_CONV,, <:ptr BYTE, :UINT>, 8
      endif
    endif
    ifndef NO_SHLWAPI_HTTP
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
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
        endif
      endif
    endif
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
          SPMODE_EVENTTRACE equ 00008000h
        endif
        StopWatchMode proto WIN_STD_CALL_CONV
        StopWatchFlush proto WIN_STD_CALL_CONV
      endif
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
      ifndef __IConnectionPoint_FWD_DEFINED__
        __IConnectionPoint_FWD_DEFINED__ equ <>
        ;IConnectionPoint typedef IConnectionPoint
        
      endif
      @DefProto DllImport, ConnectToConnectionPoint, WIN_STD_CALL_CONV,, <:ptr IUnknown, :REFIID, :BOOL, :ptr IUnknown, :ptr DWORD, :ptr ptr IConnectionPoint>, 24
      if (NTDDI_VERSION ge NTDDI_VISTA)
        @DefProto DllImport, IStream_ReadPidl, WIN_STD_CALL_CONV,, <:ptr IStream, :ptr PIDLIST_RELATIVE>, 8
        @DefProto DllImport, IStream_WritePidl, WIN_STD_CALL_CONV,, <:ptr IStream, :PCUIDLIST_RELATIVE>, 8
      endif
      if (_WIN32_IE ge _WIN32_IE_IE70)
        @DefProto DllImport, IStream_ReadStr, WIN_STD_CALL_CONV,, <:ptr IStream, :ptr PWSTR>, 8
        @DefProto DllImport, IStream_WriteStr, WIN_STD_CALL_CONV,, <:ptr IStream, :PCWSTR>, 8
        @DefProto DllImport, IStream_Copy, WIN_STD_CALL_CONV,, <:ptr IStream, :ptr IStream, :DWORD>, 12
      endif
      if (_WIN32_IE ge 0600h)
        SHGVSPB_PERUSER equ 00000001h
        SHGVSPB_ALLUSERS equ 00000002h
        SHGVSPB_PERFOLDER equ 00000004h
        SHGVSPB_ALLFOLDERS equ 00000008h
        SHGVSPB_INHERIT equ 00000010h
        SHGVSPB_ROAM equ 00000020h
        SHGVSPB_NOAUTODEFAULTS equ 80000000h
        SHGVSPB_FOLDER equ <(SHGVSPB_PERUSER or SHGVSPB_PERFOLDER)>
        SHGVSPB_FOLDERNODEFAULTS equ <(SHGVSPB_PERUSER or SHGVSPB_PERFOLDER or SHGVSPB_NOAUTODEFAULTS)>
        SHGVSPB_USERDEFAULTS equ <(SHGVSPB_PERUSER or SHGVSPB_ALLFOLDERS)>
        SHGVSPB_GLOBALDEFAULTS equ <(SHGVSPB_ALLUSERS or SHGVSPB_ALLFOLDERS)>
        @DefProto DllImport, SHGetViewStatePropertyBag, WIN_STD_CALL_CONV,, <:PCIDLIST_ABSOLUTE, :PCWSTR, :DWORD, :REFIID, :ptr ptr>, 20
      endif
      FDTF_SHORTTIME equ 00000001h
      FDTF_SHORTDATE equ 00000002h
      FDTF_DEFAULT equ <(FDTF_SHORTDATE or FDTF_SHORTTIME)>
      FDTF_LONGDATE equ 00000004h
      FDTF_LONGTIME equ 00000008h
      FDTF_RELATIVE equ 00000010h
      FDTF_LTRDATE equ 00000100h
      FDTF_RTLDATE equ 00000200h
      FDTF_NOAUTOREADINGORDER equ 00000400h
      @DefProto DllImport, SHFormatDateTimeA, WIN_STD_CALL_CONV,, <:ptr FILETIME, :ptr DWORD, :LPSTR, :UINT>, 16
      @DefProto DllImport, SHFormatDateTimeW, WIN_STD_CALL_CONV,, <:ptr FILETIME, :ptr DWORD, :LPWSTR, :UINT>, 16
      ifdef UNICODE
        SHFormatDateTime equ <SHFormatDateTimeW>
      else
        SHFormatDateTime equ <SHFormatDateTimeA>
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, SHAnsiToUnicode, WIN_STD_CALL_CONV,, <:PCSTR, :PWSTR, :SDWORD>, 12
      @DefProto DllImport, SHAnsiToAnsi, WIN_STD_CALL_CONV,, <:PCSTR, :PSTR, :SDWORD>, 12
      @DefProto DllImport, SHUnicodeToAnsi, WIN_STD_CALL_CONV,, <:PCWSTR, :PSTR, :SDWORD>, 12
      @DefProto DllImport, SHUnicodeToUnicode, WIN_STD_CALL_CONV,, <:PCWSTR, :PWSTR, :SDWORD>, 12
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
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, SHMessageBoxCheckA, WIN_STD_CALL_CONV,, <:HWND, :LPCSTR, :LPCSTR, :UINT, :SDWORD, :LPCSTR>, 24
      @DefProto DllImport, SHMessageBoxCheckW, WIN_STD_CALL_CONV,, <:HWND, :LPCWSTR, :LPCWSTR, :UINT, :SDWORD, :LPCWSTR>, 24
      ifdef UNICODE
        SHMessageBoxCheck equ <SHMessageBoxCheckW>
      else
        SHMessageBoxCheck equ <SHMessageBoxCheckA>
      endif
      @DefProto DllImport, SHSendMessageBroadcastA, WIN_STD_CALL_CONV,, <:UINT, :WPARAM, :LPARAM>, 12
      @DefProto DllImport, SHSendMessageBroadcastW, WIN_STD_CALL_CONV,, <:UINT, :WPARAM, :LPARAM>, 12
      ifdef UNICODE
        SHSendMessageBroadcast equ <SHSendMessageBroadcastW>
      else
        SHSendMessageBroadcast equ <SHSendMessageBroadcastA>
      endif
      @DefProto DllImport, SHStripMneumonicA, WIN_STD_CALL_CONV,, <:LPSTR>, 4
      @DefProto DllImport, SHStripMneumonicW, WIN_STD_CALL_CONV,, <:LPWSTR>, 4
      ifdef UNICODE
        SHStripMneumonic equ <SHStripMneumonicW>
      else
        SHStripMneumonic equ <SHStripMneumonicA>
      endif
      ifndef NO_SHLWAPI_ISOS
        OS_WINDOWS equ 0
        OS_NT equ 1
        OS_WIN95ORGREATER equ 2
        OS_NT4ORGREATER equ 3
        OS_WIN98ORGREATER equ 5
        OS_WIN98_GOLD equ 6
        OS_WIN2000ORGREATER equ 7
        OS_WIN2000PRO equ 8
        OS_WIN2000SERVER equ 9
        OS_WIN2000ADVSERVER equ 10
        OS_WIN2000DATACENTER equ 11
        OS_WIN2000TERMINAL equ 12
        OS_EMBEDDED equ 13
        OS_TERMINALCLIENT equ 14
        OS_TERMINALREMOTEADMIN equ 15
        OS_WIN95_GOLD equ 16
        OS_MEORGREATER equ 17
        OS_XPORGREATER equ 18
        OS_HOME equ 19
        OS_PROFESSIONAL equ 20
        OS_DATACENTER equ 21
        OS_ADVSERVER equ 22
        OS_SERVER equ 23
        OS_TERMINALSERVER equ 24
        OS_PERSONALTERMINALSERVER equ 25
        OS_FASTUSERSWITCHING equ 26
        OS_WELCOMELOGONUI equ 27
        OS_DOMAINMEMBER equ 28
        OS_ANYSERVER equ 29
        OS_WOW6432 equ 30
        OS_WEBSERVER equ 31
        OS_SMALLBUSINESSSERVER equ 32
        OS_TABLETPC equ 33
        OS_SERVERADMINUI equ 34
        OS_MEDIACENTER equ 35
        OS_APPLIANCE equ 36
        @DefProto DllImport, IsOS, WIN_STD_CALL_CONV,, <:DWORD>, 4
      endif
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
      if (NTDDI_VERSION ge NTDDI_WIN8)
        GLOBALCOUNTER_APP_ITEMS_STATE_STORE_CACHE equ 53
        GLOBALCOUNTER_SETTINGSYNC_ENABLED equ 54
        GLOBALCOUNTER_APPSFOLDER_FILETYPEASSOCIATION_COUNTER equ 55
        GLOBALCOUNTER_USERINFOCHANGED equ 56
        if (NTDDI_VERSION ge NTDDI_WINBLUE)
          GLOBALCOUNTER_SYNC_ENGINE_INFORMATION_CACHE_MACHINEWIDE equ 57
        endif
      endif
      if (NTDDI_VERSION ge NTDDI_WIN10_RS1)
        GLOBALCOUNTER_BANNERS_DATAMODEL_CACHE_MACHINEWIDE equ 58
      endif
      GLOBALCOUNTER_MAXIMUMVALUE equ 59
      
      if (NTDDI_VERSION ge NTDDI_WIN7)
        @DefProto DllImport, SHGlobalCounterGetValue, WIN_STD_CALL_CONV,, <:SHGLOBALCOUNTER>, 4
        @DefProto DllImport, SHGlobalCounterIncrement, WIN_STD_CALL_CONV,, <:SHGLOBALCOUNTER>, 4
        @DefProto DllImport, SHGlobalCounterDecrement, WIN_STD_CALL_CONV,, <:SHGLOBALCOUNTER>, 4
      endif
      if (_WIN32_IE ge 0603h)
        @DefProto DllImport, SHAllocShared, WIN_STD_CALL_CONV,, <:ptr, :DWORD, :DWORD>, 12
        @DefProto DllImport, SHFreeShared, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD>, 8
        @DefProto DllImport, SHLockShared, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD>, 8
        @DefProto DllImport, SHUnlockShared, WIN_STD_CALL_CONV,, <:ptr>, 4
      endif
      @DefProto DllImport, WhichPlatform, WIN_STD_CALL_CONV,, <>, 0
      PLATFORM_UNKNOWN equ 0
      PLATFORM_IE3 equ 1
      PLATFORM_BROWSERONLY equ 1
      PLATFORM_INTEGRATED equ 2
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
      QITABENTMULTI2 macro Cthis, Ifoo, Iimpl
        exitm <{ (IID *) and Ifoo, OFFSETOFCLASS(Iimpl, Cthis) }>
      endm
      QITABENT macro Cthis, Ifoo
        exitm <QITABENTMULTI(Cthis, Ifoo, Ifoo)>
      endm
      @DefProto DllImport, QISearch, WIN_STD_CALL_CONV,, <:ptr, :LPCQITAB, :REFIID, :ptr ptr>, 16
      ifndef STATIC_CAST
        STATIC_CAST macro typ
          exitm <static_cast < typ >>
        endm
        ifndef _X86_
          STATIC_CAST macro typ
            exitm <(typ)>
          endm
        endif
      endif
      ifndef OFFSETOFCLASS
        OFFSETOFCLASS macro base, derived
          exitm <((STATIC_CAST(base *) ((derived *) 8)) - 8)>
        endm
      endif
      ILMM_IE4 equ 0
      @DefProto DllImport, SHIsLowMemoryMachine, WIN_STD_CALL_CONV,, <:DWORD>, 4
      @DefProto DllImport, GetMenuPosFromID, WIN_STD_CALL_CONV,, <:HMENU, :UINT>, 8
      @DefProto DllImport, SHGetInverseCMAP, WIN_STD_CALL_CONV,, <:ptr BYTE, :ULONG>, 8
      SHACF_DEFAULT equ 00000000h
      SHACF_FILESYSTEM equ 00000001h
      SHACF_URLALL equ <(SHACF_URLHISTORY or SHACF_URLMRU)>
      SHACF_URLHISTORY equ 00000002h
      SHACF_URLMRU equ 00000004h
      SHACF_USETAB equ 00000008h
      SHACF_FILESYS_ONLY equ 00000010h
      if (_WIN32_IE ge 0600h)
        SHACF_FILESYS_DIRS equ 00000020h
      endif
      if (_WIN32_IE ge _WIN32_IE_IE70)
        SHACF_VIRTUAL_NAMESPACE equ 00000040h
      endif
      SHACF_AUTOSUGGEST_FORCE_ON equ 10000000h
      SHACF_AUTOSUGGEST_FORCE_OFF equ 20000000h
      SHACF_AUTOAPPEND_FORCE_ON equ 40000000h
      SHACF_AUTOAPPEND_FORCE_OFF equ 80000000h
      @DefProto DllImport, SHAutoComplete, WIN_STD_CALL_CONV,, <:HWND, :DWORD>, 8
      if (_WIN32_IE ge _WIN32_IE_IE60SP2)
        @DefProto DllImport, SHCreateThreadRef, WIN_STD_CALL_CONV,, <:ptr LONG, :ptr ptr IUnknown>, 8
      endif
      @DefProto DllImport, SHSetThreadRef, WIN_STD_CALL_CONV,, <:ptr IUnknown>, 4
      @DefProto DllImport, SHGetThreadRef, WIN_STD_CALL_CONV,, <:ptr ptr IUnknown>, 4
      @DefProto DllImport, SHSkipJunction, WIN_STD_CALL_CONV,, <:ptr IBindCtx, :ptr CLSID>, 8
      CTF_INSIST equ 00000001h
      CTF_THREAD_REF equ 00000002h
      CTF_PROCESS_REF equ 00000004h
      CTF_COINIT_STA equ 00000008h
      CTF_COINIT equ 00000008h
      if (_WIN32_IE ge _WIN32_IE_IE60)
        CTF_FREELIBANDEXIT equ 00000010h
        CTF_REF_COUNTED equ 00000020h
        CTF_WAIT_ALLOWCOM equ 00000040h
      endif
      if (_WIN32_IE ge _WIN32_IE_IE70)
        CTF_UNUSED equ 00000080h
        CTF_INHERITWOW64 equ 00000100h
      endif
      if (NTDDI_VERSION ge NTDDI_VISTA)
        CTF_WAIT_NO_REENTRANCY equ 00000200h
      endif
      if (NTDDI_VERSION ge NTDDI_WIN7)
        CTF_KEYBOARD_LOCALE equ 00000400h
        CTF_OLEINITIALIZE equ 00000800h
        CTF_COINIT_MTA equ 00001000h
        CTF_NOADDREFLIB equ 00002000h
      endif
      
      SHCT_FLAGS typedef DWORD
      @DefProto DllImport, SHCreateThread, WIN_STD_CALL_CONV,, <:LPTHREAD_START_ROUTINE, :ptr, :SHCT_FLAGS, :LPTHREAD_START_ROUTINE>, 16
      @DefProto DllImport, SHCreateThreadWithHandle, WIN_STD_CALL_CONV,, <:LPTHREAD_START_ROUTINE, :ptr, :SHCT_FLAGS, :LPTHREAD_START_ROUTINE, :ptr HANDLE>, 20
      if (NTDDI_VERSION ge NTDDI_WIN8)
        @DefProto DllImport, SetProcessReference, WIN_STD_CALL_CONV,, <:ptr IUnknown>, 4
        @DefProto DllImport, GetProcessReference, WIN_STD_CALL_CONV,, <:ptr ptr IUnknown>, 4
      endif
      if (_WIN32_IE ge _WIN32_IE_IE60)
        @DefProto DllImport, SHReleaseThreadRef, WIN_STD_CALL_CONV,, <>, 0
      endif
      ifndef NO_SHLWAPI_GDI
        @DefProto DllImport, SHCreateShellPalette, WIN_STD_CALL_CONV,, <:HDC>, 4
        @DefProto DllImport, ColorRGBToHLS, WIN_STD_CALL_CONV,, <:COLORREF, :ptr WORD, :ptr WORD, :ptr WORD>, 16
        @DefProto DllImport, ColorHLSToRGB, WIN_STD_CALL_CONV,, <:WORD, :WORD, :WORD>, 12
        @DefProto DllImport, ColorAdjustLuma, WIN_STD_CALL_CONV,, <:COLORREF, :SDWORD, :BOOL>, 12
      endif
      DLLVERSIONINFO struct
        cbSize DWORD ?
        dwMajorVersion DWORD ?
        dwMinorVersion DWORD ?
        dwBuildNumber DWORD ?
        dwPlatformID DWORD ?
      DLLVERSIONINFO ends

      _DLLVERSIONINFO typedef DLLVERSIONINFO
      DLLVER_PLATFORM_WINDOWS equ 00000001h
      DLLVER_PLATFORM_NT equ 00000002h
      DLLVERSIONINFO2 struct
        info1 DLLVERSIONINFO <>
        dwFlags DWORD ?
        ullVersion ULONGLONG ?
      DLLVERSIONINFO2 ends

      _DLLVERSIONINFO2 typedef DLLVERSIONINFO2
      DLLVER_MAJOR_MASK equ 0FFFF000000000000h
      DLLVER_MINOR_MASK equ 0000FFFF00000000h
      DLLVER_BUILD_MASK equ 00000000FFFF0000h
      DLLVER_QFE_MASK equ 000000000000FFFFh
      MAKEDLLVERULL macro major, minor, build, qfe
        exitm <(((major) shl 48) or ((minor) shl 32) or ((build) shl 16) or ((qfe) shl 0))>
      endm
      TYPE_DLLGETVERSIONPROC typedef proto WIN_STD_CALL_CONV :ptr DLLVERSIONINFO
      DLLGETVERSIONPROC typedef ptr TYPE_DLLGETVERSIONPROC
      @DefProto DllImport, DllInstall, WIN_STD_CALL_CONV,, <:BOOL, :PCWSTR>, 8
      if (_WIN32_IE ge 0602h)
        @DefProto DllImport, IsInternetESCEnabled, WIN_STD_CALL_CONV,, <>, 0
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      ifdef __cplusplus
        ;[...]
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ifdef __cplusplus
        ;[...]
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
    endif
  endif
endif

