;Include file created by h2incX, Version C.01.00, 30/03/2019 18:59
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'D:\ObjAsm\Projects\32\h2IncX\header\strsafe.h', last modified: 22/10/2018 20:36
;Creation parameters: 

ifndef _STRSAFE_H_INCLUDED_
  _STRSAFE_H_INCLUDED_ equ <>
  if (_MSC_VER gt 1000)
  endif
  include stdio.inc
  include string.inc
  include stdarg.inc
  include specstrings.inc
  include winapifamily.inc
  if  not Defined(_W64)
    if  not Defined(__midl) and (Defined(_X86_) or Defined(_M_IX86) or Defined(_ARM_) or Defined(_M_ARM)) and (_MSC_VER ge 1300)
      _W64 equ <__w64>
    else
      _W64 equ <>
    endif
  endif
  if Defined(_M_MRX000) or Defined(_M_ALPHA) or Defined(_M_PPC) or Defined(_M_IA64) or Defined(_M_AMD64) or Defined(_M_ARM) or Defined(_M_ARM64)
    ALIGNMENT_MACHINE equ <>
    UNALIGNED equ <__unaligned>
    if Defined(_WIN64)
      UNALIGNED64 equ <__unaligned>
    else
      UNALIGNED64 equ <>
    endif
  else
    UNALIGNED equ <>
    UNALIGNED64 equ <>
  endif
  ifdef _WIN64
    size_t typedef QWORD
  else
    size_t typedef _W64
  endif
  ifndef _HRESULT_DEFINED
    _HRESULT_DEFINED equ <>
    HRESULT typedef SDWORD
  endif
  SUCCEEDED macro hr
    exitm <(((hr)) >= 0)>
  endm
  FAILED macro hr
    exitm <(((hr)) < 0)>
  endm
  S_OK equ (0)
  ifndef SORTPP_PASS
    C_ASSERT macro e
      exitm <typedef char __C_ASSERT__ [ (e) ?1 : - 1 ]>
    endm
  else
    ;[...]
  endif
  ifdef __cplusplus
    ;[...]
  else
    EXTERN_C equ <extern>
  endif
  ifndef STRSAFE_USE_SECURE_CRT
    if Defined(__GOT_SECURE_LIB__) and (__GOT_SECURE_LIB__ ge 200402)
      STRSAFE_USE_SECURE_CRT equ 0
    else
      STRSAFE_USE_SECURE_CRT equ 0
    endif
  endif
  ifdef _M_CEE_PURE
    ;[...]
  else
    STRSAFEAPI equ <__inline HRESULT __stdcall>
  endif
  if Defined(STRSAFE_LIB_IMPL) or Defined(STRSAFE_LIB)
    STRSAFEWORKERAPI equ <EXTERN_C HRESULT __stdcall>
  else
    STRSAFEWORKERAPI equ <static STRSAFEAPI>
  endif
  ifdef STRSAFE_LOCALE_FUNCTIONS
    if Defined(STRSAFE_LOCALE_LIB_IMPL) or Defined(STRSAFE_LIB)
      STRSAFELOCALEWORKERAPI equ <EXTERN_C HRESULT __stdcall>
    else
      STRSAFELOCALEWORKERAPI equ <static STRSAFEAPI>
    endif
  endif
  if Defined(STRSAFE_LIB)
  endif
  if Defined(STRSAFE_NO_CB_FUNCTIONS) and Defined(STRSAFE_NO_CCH_FUNCTIONS)
    .err <cannot specify both STRSAFE_NO_CB_FUNCTIONS and STRSAFE_NO_CCH_FUNCTIONS ! !>
  endif
  ifndef STRSAFE_MAX_CCH
    STRSAFE_MAX_CCH equ 2147483647
  endif
  STRSAFE_MAX_LENGTH equ (STRSAFE_MAX_CCH - 1)
  STRSAFE_IGNORE_NULLS equ 00000100h
  STRSAFE_FILL_BEHIND_NULL equ 00000200h
  STRSAFE_FILL_ON_FAILURE equ 00000400h
  STRSAFE_NULL_ON_FAILURE equ 00000800h
  STRSAFE_NO_TRUNCATION equ 00001000h
  STRSAFE_VALID_FLAGS equ (000000FFh or STRSAFE_IGNORE_NULLS or STRSAFE_FILL_BEHIND_NULL or STRSAFE_FILL_ON_FAILURE or STRSAFE_NULL_ON_FAILURE or STRSAFE_NO_TRUNCATION)
  STRSAFE_FILL_BYTE macro x
    exitm <(((x and 000000FFh) or STRSAFE_FILL_BEHIND_NULL))>
  endm
  STRSAFE_FAILURE_BYTE macro x
    exitm <(((x and 000000FFh) or STRSAFE_FILL_ON_FAILURE))>
  endm
  STRSAFE_GET_FILL_PATTERN macro dwFlags
    exitm <((dwFlags and 000000FFh))>
  endm
  STRSAFE_E_INSUFFICIENT_BUFFER equ (8007007Ah)
  STRSAFE_E_INVALID_PARAMETER equ (80070057h)
  STRSAFE_E_END_OF_FILE equ (80070026h)
  STRSAFE_LPSTR typedef ptr SBYTE
  STRSAFE_LPCSTR typedef ptr SBYTE
  STRSAFE_LPWSTR typedef ptr wchar_t
  STRSAFE_LPCWSTR typedef ptr wchar_t
  STRSAFE_LPCUWSTR typedef ptr wchar_t
  STRSAFE_PCNZCH typedef ptr SBYTE
  STRSAFE_PCNZWCH typedef ptr wchar_t
  STRSAFE_PCUNZWCH typedef ptr wchar_t
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    StringLengthWorkerA proto WIN_STD_CALL_CONV :STRSAFE_PCNZCH, :size_t, :ptr size_t
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    StringLengthWorkerW proto WIN_STD_CALL_CONV :STRSAFE_PCNZWCH, :size_t, :ptr size_t
    ifdef ALIGNMENT_MACHINE
      UnalignedStringLengthWorkerW proto WIN_STD_CALL_CONV :STRSAFE_PCUNZWCH, :size_t, :ptr size_t
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    StringExValidateSrcA proto WIN_STD_CALL_CONV :ptr STRSAFE_PCNZCH, :ptr size_t, :size_t, :DWORD
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    StringExValidateSrcW proto WIN_STD_CALL_CONV :ptr STRSAFE_PCNZWCH, :ptr size_t, :size_t, :DWORD
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    StringValidateDestA proto WIN_STD_CALL_CONV :STRSAFE_PCNZCH, :size_t, :size_t
    StringValidateDestAndLengthA proto WIN_STD_CALL_CONV :STRSAFE_LPCSTR, :size_t, :ptr size_t, :size_t
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    StringValidateDestW proto WIN_STD_CALL_CONV :STRSAFE_PCNZWCH, :size_t, :size_t
    StringValidateDestAndLengthW proto WIN_STD_CALL_CONV :STRSAFE_LPCWSTR, :size_t, :ptr size_t, :size_t
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    StringExValidateDestA proto WIN_STD_CALL_CONV :STRSAFE_PCNZCH, :size_t, :size_t, :DWORD
    StringExValidateDestAndLengthA proto WIN_STD_CALL_CONV :STRSAFE_LPCSTR, :size_t, :ptr size_t, :size_t, :DWORD
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    StringExValidateDestW proto WIN_STD_CALL_CONV :STRSAFE_PCNZWCH, :size_t, :size_t, :DWORD
    StringExValidateDestAndLengthW proto WIN_STD_CALL_CONV :STRSAFE_LPCWSTR, :size_t, :ptr size_t, :size_t, :DWORD
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    StringCopyWorkerA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr size_t, :STRSAFE_PCNZCH, :size_t
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    StringCopyWorkerW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr size_t, :STRSAFE_PCNZWCH, :size_t
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    StringVPrintfWorkerA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr size_t, :STRSAFE_LPCSTR, :va_list
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    ifdef STRSAFE_LOCALE_FUNCTIONS
      StringVPrintf_lWorkerA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr size_t, :STRSAFE_LPCSTR, :_locale_t, :va_list
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    StringVPrintfWorkerW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr size_t, :STRSAFE_LPCWSTR, :va_list
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    ifdef STRSAFE_LOCALE_FUNCTIONS
      StringVPrintf_lWorkerW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr size_t, :STRSAFE_LPCWSTR, :_locale_t, :va_list
    endif
  endif
  ifndef STRSAFE_LIB_IMPL
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      StringGetsWorkerA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr size_t
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      StringGetsWorkerW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr size_t
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    StringExHandleFillBehindNullA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :DWORD
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    StringExHandleFillBehindNullW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :DWORD
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    StringExHandleOtherFlagsA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :size_t, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    StringExHandleOtherFlagsW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :size_t, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD
  endif
  __WARNING_CYCLOMATIC_COMPLEXITY equ 28734
  __WARNING_USING_UNINIT_VAR equ 6001
  __WARNING_RETURN_UNINIT_VAR equ 6101
  __WARNING_DEREF_NULL_PTR equ 6011
  __WARNING_MISSING_ZERO_TERMINATION2 equ 6054
  __WARNING_INVALID_PARAM_VALUE_1 equ 6387
  __WARNING_INCORRECT_ANNOTATION equ 26007
  __WARNING_POTENTIAL_BUFFER_OVERFLOW_HIGH_PRIORITY equ 26015
  __WARNING_PRECONDITION_NULLTERMINATION_VIOLATION equ 26035
  __WARNING_POSTCONDITION_NULLTERMINATION_VIOLATION equ 26036
  __WARNING_HIGH_PRIORITY_OVERFLOW_POSTCONDITION equ 26045
  __WARNING_RANGE_POSTCONDITION_VIOLATION equ 26061
  __WARNING_POTENTIAL_RANGE_POSTCONDITION_VIOLATION equ 26071
  __WARNING_INVALID_PARAM_VALUE_3 equ 28183
  __WARNING_RETURNING_BAD_RESULT equ 28196
  __WARNING_BANNED_API_USAGE equ 28719
  __WARNING_POST_EXPECTED equ 28210
  if _MSC_VER le 1400
  endif
  ifndef STRSAFE_LIB_IMPL
    ifndef STRSAFE_NO_CCH_FUNCTIONS
      ifdef UNICODE
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCchCopy equ <StringCchCopyW>
        endif
      else
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCchCopy equ <StringCchCopyA>
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
        StringCchCopyA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_LPCSTR
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        StringCchCopyW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_LPCWSTR
      endif
    endif
    ifndef STRSAFE_NO_CB_FUNCTIONS
      ifdef UNICODE
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCbCopy equ <StringCbCopyW>
        endif
      else
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCbCopy equ <StringCbCopyA>
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
        StringCbCopyA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_LPCSTR
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        StringCbCopyW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_LPCWSTR
      endif
    endif
    ifndef STRSAFE_NO_CCH_FUNCTIONS
      ifdef UNICODE
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCchCopyEx equ <StringCchCopyExW>
        endif
      else
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCchCopyEx equ <StringCchCopyExA>
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
        StringCchCopyExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_LPCSTR, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        StringCchCopyExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_LPCWSTR, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD
      endif
    endif
    ifndef STRSAFE_NO_CB_FUNCTIONS
      ifdef UNICODE
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCbCopyEx equ <StringCbCopyExW>
        endif
      else
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCbCopyEx equ <StringCbCopyExA>
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
        StringCbCopyExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_LPCSTR, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        StringCbCopyExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_LPCWSTR, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD
      endif
    endif
    ifndef STRSAFE_NO_CCH_FUNCTIONS
      ifdef UNICODE
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCchCopyN equ <StringCchCopyNW>
        endif
      else
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCchCopyN equ <StringCchCopyNA>
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
        StringCchCopyNA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_PCNZCH, :size_t
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        StringCchCopyNW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_PCNZWCH, :size_t
      endif
    endif
    ifndef STRSAFE_NO_CB_FUNCTIONS
      ifdef UNICODE
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCbCopyN equ <StringCbCopyNW>
        endif
      else
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCbCopyN equ <StringCbCopyNA>
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
        StringCbCopyNA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_PCNZCH, :size_t
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        StringCbCopyNW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_PCNZWCH, :size_t
      endif
    endif
    ifndef STRSAFE_NO_CCH_FUNCTIONS
      ifdef UNICODE
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCchCopyNEx equ <StringCchCopyNExW>
        endif
      else
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCchCopyNEx equ <StringCchCopyNExA>
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
        StringCchCopyNExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_PCNZCH, :size_t, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        StringCchCopyNExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_PCNZWCH, :size_t, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD
      endif
    endif
    ifndef STRSAFE_NO_CB_FUNCTIONS
      ifdef UNICODE
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCbCopyNEx equ <StringCbCopyNExW>
        endif
      else
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCbCopyNEx equ <StringCbCopyNExA>
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
        StringCbCopyNExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_PCNZCH, :size_t, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        StringCbCopyNExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_PCNZWCH, :size_t, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD
      endif
    endif
    ifndef STRSAFE_NO_CCH_FUNCTIONS
      ifdef UNICODE
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCchCat equ <StringCchCatW>
        endif
      else
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCchCat equ <StringCchCatA>
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
        StringCchCatA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_LPCSTR
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        StringCchCatW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_LPCWSTR
      endif
    endif
    ifndef STRSAFE_NO_CB_FUNCTIONS
      ifdef UNICODE
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCbCat equ <StringCbCatW>
        endif
      else
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCbCat equ <StringCbCatA>
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
        StringCbCatA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_LPCSTR
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        StringCbCatW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_LPCWSTR
      endif
    endif
    ifndef STRSAFE_NO_CCH_FUNCTIONS
      ifdef UNICODE
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCchCatEx equ <StringCchCatExW>
        endif
      else
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCchCatEx equ <StringCchCatExA>
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
        StringCchCatExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_LPCSTR, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        StringCchCatExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_LPCWSTR, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD
      endif
    endif
    ifndef STRSAFE_NO_CB_FUNCTIONS
      ifdef UNICODE
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCbCatEx equ <StringCbCatExW>
        endif
      else
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCbCatEx equ <StringCbCatExA>
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
        StringCbCatExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_LPCSTR, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        StringCbCatExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_LPCWSTR, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD
      endif
    endif
    ifndef STRSAFE_NO_CCH_FUNCTIONS
      ifdef UNICODE
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCchCatN equ <StringCchCatNW>
        endif
      else
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCchCatN equ <StringCchCatNA>
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
        StringCchCatNA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_PCNZCH, :size_t
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        StringCchCatNW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_PCNZWCH, :size_t
      endif
    endif
    ifndef STRSAFE_NO_CB_FUNCTIONS
      ifdef UNICODE
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCbCatN equ <StringCbCatNW>
        endif
      else
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCbCatN equ <StringCbCatNA>
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
        StringCbCatNA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_PCNZCH, :size_t
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        StringCbCatNW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_PCNZWCH, :size_t
      endif
    endif
    ifndef STRSAFE_NO_CCH_FUNCTIONS
      ifdef UNICODE
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCchCatNEx equ <StringCchCatNExW>
        endif
      else
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCchCatNEx equ <StringCchCatNExA>
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
        StringCchCatNExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_PCNZCH, :size_t, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        StringCchCatNExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_PCNZWCH, :size_t, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD
      endif
    endif
    ifndef STRSAFE_NO_CB_FUNCTIONS
      ifdef UNICODE
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCbCatNEx equ <StringCbCatNExW>
        endif
      else
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCbCatNEx equ <StringCbCatNExA>
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
        StringCbCatNExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_PCNZCH, :size_t, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        StringCbCatNExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_PCNZWCH, :size_t, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD
      endif
    endif
    ifndef STRSAFE_NO_CCH_FUNCTIONS
      ifdef UNICODE
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCchVPrintf equ <StringCchVPrintfW>
        endif
      else
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCchVPrintf equ <StringCchVPrintfA>
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
        StringCchVPrintfA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_LPCSTR, :va_list
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        StringCchVPrintfW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_LPCWSTR, :va_list
      endif
    endif
    if Defined(STRSAFE_LOCALE_FUNCTIONS) and  not Defined(STRSAFE_NO_CCH_FUNCTIONS)
      ifdef UNICODE
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCchVPrintf_l equ <StringCchVPrintf_lW>
        endif
      else
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCchVPrintf_l equ <StringCchVPrintf_lA>
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
        StringCchVPrintf_lA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_LPCSTR, :_locale_t, :va_list
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        StringCchVPrintf_lW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_LPCWSTR, :_locale_t, :va_list
      endif
    endif
    ifndef STRSAFE_NO_CB_FUNCTIONS
      ifdef UNICODE
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCbVPrintf equ <StringCbVPrintfW>
        endif
      else
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCbVPrintf equ <StringCbVPrintfA>
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
        StringCbVPrintfA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_LPCSTR, :va_list
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        StringCbVPrintfW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_LPCWSTR, :va_list
      endif
    endif
    if Defined(STRSAFE_LOCALE_FUNCTIONS) and  not Defined(STRSAFE_NO_CB_FUNCTIONS)
      ifdef UNICODE
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCbVPrintf_l equ <StringCbVPrintf_lW>
        endif
      else
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCbVPrintf_l equ <StringCbVPrintf_lA>
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
        StringCbVPrintf_lA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_LPCSTR, :_locale_t, :va_list
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        StringCbVPrintf_lW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_LPCWSTR, :_locale_t, :va_list
      endif
    endif
    ifndef _M_CEE_PURE
      ifndef STRSAFE_NO_CCH_FUNCTIONS
        ifdef UNICODE
          if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
            StringCchPrintf equ <StringCchPrintfW>
          endif
        else
          if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
            StringCchPrintf equ <StringCchPrintfA>
          endif
        endif
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCchPrintfA proto c :STRSAFE_LPSTR, :size_t, :STRSAFE_LPCSTR, :vararg
        endif
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCchPrintfW proto c :STRSAFE_LPWSTR, :size_t, :STRSAFE_LPCWSTR, :vararg
        endif
      endif
      if Defined(STRSAFE_LOCALE_FUNCTIONS) and  not Defined(STRSAFE_NO_CCH_FUNCTIONS)
        ifdef UNICODE
          if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
            StringCchPrintf_l equ <StringCchPrintf_lW>
          endif
        else
          if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
            StringCchPrintf_l equ <StringCchPrintf_lA>
          endif
        endif
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCchPrintf_lA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_LPCSTR, :_locale_t, :vararg
        endif
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCchPrintf_lW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_LPCWSTR, :_locale_t, :vararg
        endif
      endif
      ifndef STRSAFE_NO_CB_FUNCTIONS
        ifdef UNICODE
          if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
            StringCbPrintf equ <StringCbPrintfW>
          endif
        else
          if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
            StringCbPrintf equ <StringCbPrintfA>
          endif
        endif
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCbPrintfA proto c :STRSAFE_LPSTR, :size_t, :STRSAFE_LPCSTR, :vararg
        endif
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCbPrintfW proto c :STRSAFE_LPWSTR, :size_t, :STRSAFE_LPCWSTR, :vararg
        endif
      endif
      if Defined(STRSAFE_LOCALE_FUNCTIONS) and  not Defined(STRSAFE_NO_CB_FUNCTIONS)
        ifdef UNICODE
          if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
            StringCbPrintf_l equ <StringCbPrintf_lW>
          endif
        else
          if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
            StringCbPrintf_l equ <StringCbPrintf_lA>
          endif
        endif
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCbPrintf_lA proto c :STRSAFE_LPSTR, :size_t, :STRSAFE_LPCSTR, :_locale_t, :vararg
        endif
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCbPrintf_lW proto c :STRSAFE_LPWSTR, :size_t, :STRSAFE_LPCWSTR, :_locale_t, :vararg
        endif
      endif
      ifndef STRSAFE_NO_CCH_FUNCTIONS
        ifdef UNICODE
          if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
            StringCchPrintfEx equ <StringCchPrintfExW>
          endif
        else
          if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
            StringCchPrintfEx equ <StringCchPrintfExA>
          endif
        endif
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCchPrintfExA proto c :STRSAFE_LPSTR, :size_t, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD, :STRSAFE_LPCSTR, :vararg
        endif
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCchPrintfExW proto c :STRSAFE_LPWSTR, :size_t, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD, :STRSAFE_LPCWSTR, :vararg
        endif
      endif
      if Defined(STRSAFE_LOCALE_FUNCTIONS) and  not Defined(STRSAFE_NO_CCH_FUNCTIONS)
        ifdef UNICODE
          if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
            StringCchPrintf_lEx equ <StringCchPrintf_lExW>
          endif
        else
          if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
            StringCchPrintf_lEx equ <StringCchPrintf_lExA>
          endif
        endif
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCchPrintf_lExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD, :STRSAFE_LPCSTR, :_locale_t, :vararg
        endif
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCchPrintf_lExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD, :STRSAFE_LPCWSTR, :_locale_t, :vararg
        endif
      endif
      ifndef STRSAFE_NO_CB_FUNCTIONS
        ifdef UNICODE
          if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
            StringCbPrintfEx equ <StringCbPrintfExW>
          endif
        else
          if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
            StringCbPrintfEx equ <StringCbPrintfExA>
          endif
        endif
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCbPrintfExA proto c :STRSAFE_LPSTR, :size_t, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD, :STRSAFE_LPCSTR, :vararg
        endif
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCbPrintfExW proto c :STRSAFE_LPWSTR, :size_t, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD, :STRSAFE_LPCWSTR, :vararg
        endif
      endif
      if Defined(STRSAFE_LOCALE_FUNCTIONS) and  not Defined(STRSAFE_NO_CB_FUNCTIONS)
        ifdef UNICODE
          if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
            StringCbPrintf_lEx equ <StringCbPrintf_lExW>
          endif
        else
          if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
            StringCbPrintf_lEx equ <StringCbPrintf_lExA>
          endif
        endif
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCbPrintf_lExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD, :STRSAFE_LPCSTR, :_locale_t, :vararg
        endif
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCbPrintf_lExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD, :STRSAFE_LPCWSTR, :_locale_t, :vararg
        endif
      endif
    endif
    ifndef STRSAFE_NO_CCH_FUNCTIONS
      ifdef UNICODE
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCchVPrintfEx equ <StringCchVPrintfExW>
        endif
      else
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCchVPrintfEx equ <StringCchVPrintfExA>
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
        StringCchVPrintfExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD, :STRSAFE_LPCSTR, :va_list
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        StringCchVPrintfExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD, :STRSAFE_LPCWSTR, :va_list
      endif
    endif
    if Defined(STRSAFE_LOCALE_FUNCTIONS) and  not Defined(STRSAFE_NO_CCH_FUNCTIONS)
      ifdef UNICODE
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCchVPrintf_lEx equ <StringCchVPrintf_lExW>
        endif
      else
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCchVPrintf_lEx equ <StringCchVPrintf_lExA>
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
        StringCchVPrintf_lExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD, :STRSAFE_LPCSTR, :_locale_t, :va_list
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        StringCchVPrintf_lExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD, :STRSAFE_LPCWSTR, :_locale_t, :va_list
      endif
    endif
    ifndef STRSAFE_NO_CB_FUNCTIONS
      ifdef UNICODE
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCbVPrintfEx equ <StringCbVPrintfExW>
        endif
      else
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCbVPrintfEx equ <StringCbVPrintfExA>
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
        StringCbVPrintfExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD, :STRSAFE_LPCSTR, :va_list
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        StringCbVPrintfExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD, :STRSAFE_LPCWSTR, :va_list
      endif
    endif
    if Defined(STRSAFE_LOCALE_FUNCTIONS) and  not Defined(STRSAFE_NO_CB_FUNCTIONS)
      ifdef UNICODE
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCbVPrintf_lEx equ <StringCbVPrintf_lExW>
        endif
      else
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCbVPrintf_lEx equ <StringCbVPrintf_lExA>
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
        StringCbVPrintf_lExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD, :STRSAFE_LPCSTR, :_locale_t, :va_list
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        StringCbVPrintf_lExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD, :STRSAFE_LPCWSTR, :_locale_t, :va_list
      endif
    endif
    ifndef STRSAFE_LIB_IMPL
      ifndef STRSAFE_NO_CCH_FUNCTIONS
        ifdef UNICODE
          if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
            StringCchGets equ <StringCchGetsW>
          endif
        else
          if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
            StringCchGets equ <StringCchGetsA>
          endif
        endif
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCchGetsA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t
        endif
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCchGetsW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t
        endif
      endif
      ifndef STRSAFE_NO_CB_FUNCTIONS
        ifdef UNICODE
          if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
            StringCbGets equ <StringCbGetsW>
          endif
        else
          if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
            StringCbGets equ <StringCbGetsA>
          endif
        endif
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCbGetsA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t
        endif
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCbGetsW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t
        endif
      endif
      ifndef STRSAFE_NO_CCH_FUNCTIONS
        ifdef UNICODE
          if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
            StringCchGetsEx equ <StringCchGetsExW>
          endif
        else
          if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
            StringCchGetsEx equ <StringCchGetsExA>
          endif
        endif
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCchGetsExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD
        endif
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCchGetsExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD
        endif
      endif
      ifndef STRSAFE_NO_CB_FUNCTIONS
        ifdef UNICODE
          if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
            StringCbGetsEx equ <StringCbGetsExW>
          endif
        else
          if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
            StringCbGetsEx equ <StringCbGetsExA>
          endif
        endif
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCbGetsExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD
        endif
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCbGetsExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD
        endif
      endif
    endif
    ifndef STRSAFE_NO_CCH_FUNCTIONS
      ifdef UNICODE
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCchLength equ <StringCchLengthW>
        endif
      else
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCchLength equ <StringCchLengthA>
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
        StringCchLengthA proto WIN_STD_CALL_CONV :STRSAFE_PCNZCH, :size_t, :ptr size_t
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        StringCchLengthW proto WIN_STD_CALL_CONV :STRSAFE_PCNZWCH, :size_t, :ptr size_t
      endif
    endif
    ifndef STRSAFE_NO_CB_FUNCTIONS
      ifdef UNICODE
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          StringCbLength equ <StringCbLengthW>
        endif
      else
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          StringCbLength equ <StringCbLengthA>
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
        StringCbLengthA proto WIN_STD_CALL_CONV :STRSAFE_PCNZCH, :size_t, :ptr size_t
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        StringCbLengthW proto WIN_STD_CALL_CONV :STRSAFE_PCNZWCH, :size_t, :ptr size_t
      endif
    endif
    ifndef STRSAFE_NO_CCH_FUNCTIONS
      ifdef UNICODE
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          UnalignedStringCchLength equ <UnalignedStringCchLengthW>
        endif
      else
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          UnalignedStringCchLength equ <StringCchLengthA>
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        ifdef ALIGNMENT_MACHINE
          UnalignedStringCchLengthW proto WIN_STD_CALL_CONV :STRSAFE_PCUNZWCH, :size_t, :ptr size_t
        else
          UnalignedStringCchLengthW equ <StringCchLengthW>
        endif
      endif
    endif
    ifndef STRSAFE_NO_CB_FUNCTIONS
      ifdef UNICODE
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          UnalignedStringCbLength equ <UnalignedStringCbLengthW>
        endif
      else
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
          UnalignedStringCbLength equ <StringCbLengthA>
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        ifdef ALIGNMENT_MACHINE
          UnalignedStringCbLengthW proto WIN_STD_CALL_CONV :STRSAFE_PCUNZWCH, :size_t, :ptr size_t
        else
          UnalignedStringCbLengthW equ <StringCbLengthW>
        endif
      endif
    endif
  endif
  if Defined(STRSAFE_LIB_IMPL) or  not Defined(STRSAFE_LIB)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      StringLengthWorkerA proto WIN_STD_CALL_CONV :STRSAFE_PCNZCH, :size_t, :ptr size_t
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      StringLengthWorkerW proto WIN_STD_CALL_CONV :STRSAFE_PCNZWCH, :size_t, :ptr size_t
      ifdef ALIGNMENT_MACHINE
        UnalignedStringLengthWorkerW proto WIN_STD_CALL_CONV :STRSAFE_PCUNZWCH, :size_t, :ptr size_t
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      StringExValidateSrcA proto WIN_STD_CALL_CONV :ptr STRSAFE_PCNZCH, :ptr size_t, :size_t, :DWORD
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      StringExValidateSrcW proto WIN_STD_CALL_CONV :ptr STRSAFE_PCNZWCH, :ptr size_t, :size_t, :DWORD
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      StringValidateDestA proto WIN_STD_CALL_CONV :STRSAFE_PCNZCH, :size_t, :size_t
      StringValidateDestAndLengthA proto WIN_STD_CALL_CONV :STRSAFE_LPCSTR, :size_t, :ptr size_t, :size_t
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      StringValidateDestW proto WIN_STD_CALL_CONV :STRSAFE_PCNZWCH, :size_t, :size_t
      StringValidateDestAndLengthW proto WIN_STD_CALL_CONV :STRSAFE_LPCWSTR, :size_t, :ptr size_t, :size_t
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      StringExValidateDestA proto WIN_STD_CALL_CONV :STRSAFE_PCNZCH, :size_t, :size_t, :DWORD
      StringExValidateDestAndLengthA proto WIN_STD_CALL_CONV :STRSAFE_LPCSTR, :size_t, :ptr size_t, :size_t, :DWORD
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      StringExValidateDestW proto WIN_STD_CALL_CONV :STRSAFE_PCNZWCH, :size_t, :size_t, :DWORD
      StringExValidateDestAndLengthW proto WIN_STD_CALL_CONV :STRSAFE_LPCWSTR, :size_t, :ptr size_t, :size_t, :DWORD
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      StringCopyWorkerA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr size_t, :STRSAFE_PCNZCH, :size_t
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      StringCopyWorkerW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr size_t, :STRSAFE_PCNZWCH, :size_t
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      StringVPrintfWorkerA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr size_t, :STRSAFE_LPCSTR, :va_list
      if (STRSAFE_USE_SECURE_CRT eq 1) and  not Defined(STRSAFE_LIB_IMPL)
      else
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      ifdef STRSAFE_LOCALE_FUNCTIONS
        StringVPrintf_lWorkerA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr size_t, :STRSAFE_LPCSTR, :_locale_t, :va_list
        if (STRSAFE_USE_SECURE_CRT eq 1) and  not Defined(STRSAFE_LIB_IMPL)
        else
        endif
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      StringVPrintfWorkerW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr size_t, :STRSAFE_LPCWSTR, :va_list
      if (STRSAFE_USE_SECURE_CRT eq 1) and  not Defined(STRSAFE_LIB_IMPL)
      else
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      ifdef STRSAFE_LOCALE_FUNCTIONS
        StringVPrintf_lWorkerW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr size_t, :STRSAFE_LPCWSTR, :_locale_t, :va_list
        if (STRSAFE_USE_SECURE_CRT eq 1) and  not Defined(STRSAFE_LIB_IMPL)
        else
        endif
      endif
    endif
  endif
  ifndef STRSAFE_LIB_IMPL
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      StringGetsWorkerA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr size_t
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      StringGetsWorkerW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr size_t
    endif
  endif
  if Defined(STRSAFE_LIB_IMPL) or  not Defined(STRSAFE_LIB)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      StringExHandleFillBehindNullA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :DWORD
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      StringExHandleFillBehindNullW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :DWORD
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      StringExHandleOtherFlagsA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :size_t, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      StringExHandleOtherFlagsW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :size_t, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    ifdef DEPRECATE_SUPPORTED
    else
      StringLengthWorkerA equ <StringLengthWorkerA_instead_use_StringCchLengthA_or_StringCbLengthA>
      StringLengthWorkerW equ <StringLengthWorkerW_instead_use_StringCchLengthW_or_StringCbLengthW>
      UnalignedStringLengthWorkerW equ <UnalignedStringLengthWorkerW_instead_use_UnalignedStringCchLengthW>
      StringExValidateSrcA equ <StringExValidateSrcA_do_not_call_this_function>
      StringExValidateSrcW equ <StringExValidateSrcW_do_not_call_this_function>
      StringValidateDestA equ <StringValidateDestA_do_not_call_this_function>
      StringValidateDestAndLengthA equ <StringValidateDestAndLengthA_do_not_call_this_function>
      StringValidateDestW equ <StringValidateDestW_do_not_call_this_function>
      StringValidateDestAndLengthW equ <StringValidateDestAndLengthW_do_not_call_this_function>
      StringExValidateDestA equ <StringExValidateDestA_do_not_call_this_function>
      StringExValidateDestAndLengthA equ <StringExValidateDestAndLengthA_do_not_call_this_function>
      StringExValidateDestW equ <StringExValidateDestW_do_not_call_this_function>
      StringExValidateDestAndLengthW equ <StringExValidateDestAndLengthW_do_not_call_this_function>
      StringCopyWorkerA equ <StringCopyWorkerA_instead_use_StringCchCopyA_or_StringCbCopyA>
      StringCopyWorkerW equ <StringCopyWorkerW_instead_use_StringCchCopyW_or_StringCbCopyW>
      StringVPrintfWorkerA equ <StringVPrintfWorkerA_instead_use_StringCchVPrintfA_or_StringCbVPrintfA>
      StringVPrintfWorkerW equ <StringVPrintfWorkerW_instead_use_StringCchVPrintfW_or_StringCbVPrintfW>
      StringGetsWorkerA equ <StringGetsWorkerA_instead_use_StringCchGetsA_or_StringCbGetsA>
      StringGetsWorkerW equ <StringGetsWorkerW_instead_use_StringCchGetsW_or_StringCbGetsW>
      StringExHandleFillBehindNullA equ <StringExHandleFillBehindNullA_do_not_call_this_function>
      StringExHandleFillBehindNullW equ <StringExHandleFillBehindNullW_do_not_call_this_function>
      StringExHandleOtherFlagsA equ <StringExHandleOtherFlagsA_do_not_call_this_function>
      StringExHandleOtherFlagsW equ <StringExHandleOtherFlagsW_do_not_call_this_function>
    endif
  endif
endif
 