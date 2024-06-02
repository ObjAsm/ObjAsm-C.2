;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\strsafe.h
;             Created on (UTC) 22/05/2024 17:57:06
;             Last modified on (UTC) 21/02/2024 18:13:38

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
  StringLengthWorkerA proto WIN_STD_CALL_CONV :STRSAFE_PCNZCH, :size_t, :ptr size_t
  StringLengthWorkerW proto WIN_STD_CALL_CONV :STRSAFE_PCNZWCH, :size_t, :ptr size_t
  ifdef ALIGNMENT_MACHINE
    UnalignedStringLengthWorkerW proto WIN_STD_CALL_CONV :STRSAFE_PCUNZWCH, :size_t, :ptr size_t
  endif
  StringExValidateSrcA proto WIN_STD_CALL_CONV :ptr STRSAFE_PCNZCH, :ptr size_t, :size_t, :DWORD
  StringExValidateSrcW proto WIN_STD_CALL_CONV :ptr STRSAFE_PCNZWCH, :ptr size_t, :size_t, :DWORD
  StringValidateDestA proto WIN_STD_CALL_CONV :STRSAFE_PCNZCH, :size_t, :size_t
  StringValidateDestAndLengthA proto WIN_STD_CALL_CONV :STRSAFE_LPCSTR, :size_t, :ptr size_t, :size_t
  StringValidateDestW proto WIN_STD_CALL_CONV :STRSAFE_PCNZWCH, :size_t, :size_t
  StringValidateDestAndLengthW proto WIN_STD_CALL_CONV :STRSAFE_LPCWSTR, :size_t, :ptr size_t, :size_t
  StringExValidateDestA proto WIN_STD_CALL_CONV :STRSAFE_PCNZCH, :size_t, :size_t, :DWORD
  StringExValidateDestAndLengthA proto WIN_STD_CALL_CONV :STRSAFE_LPCSTR, :size_t, :ptr size_t, :size_t, :DWORD
  StringExValidateDestW proto WIN_STD_CALL_CONV :STRSAFE_PCNZWCH, :size_t, :size_t, :DWORD
  StringExValidateDestAndLengthW proto WIN_STD_CALL_CONV :STRSAFE_LPCWSTR, :size_t, :ptr size_t, :size_t, :DWORD
  StringCopyWorkerA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr size_t, :STRSAFE_PCNZCH, :size_t
  StringCopyWorkerW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr size_t, :STRSAFE_PCNZWCH, :size_t
  StringVPrintfWorkerA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr size_t, :STRSAFE_LPCSTR, :va_list
  ifdef STRSAFE_LOCALE_FUNCTIONS
    StringVPrintf_lWorkerA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr size_t, :STRSAFE_LPCSTR, :_locale_t, :va_list
  endif
  StringVPrintfWorkerW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr size_t, :STRSAFE_LPCWSTR, :va_list
  ifdef STRSAFE_LOCALE_FUNCTIONS
    StringVPrintf_lWorkerW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr size_t, :STRSAFE_LPCWSTR, :_locale_t, :va_list
  endif
  ifndef STRSAFE_LIB_IMPL
    StringGetsWorkerA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr size_t
    StringGetsWorkerW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr size_t
  endif
  StringExHandleFillBehindNullA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :DWORD
  StringExHandleFillBehindNullW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :DWORD
  StringExHandleOtherFlagsA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :size_t, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD
  StringExHandleOtherFlagsW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :size_t, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD
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
        StringCchCopy equ <StringCchCopyW>
      else
        StringCchCopy equ <StringCchCopyA>
      endif
      StringCchCopyA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_LPCSTR
      StringValidateDestA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringCopyWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL, :pszSrc, :STRSAFE_MAX_LENGTH
      if_ proto WIN_STD_CALL_CONV :cchDest
      StringCchCopyW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_LPCWSTR
      StringValidateDestW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringCopyWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL, :pszSrc, :STRSAFE_MAX_LENGTH
      if_ proto WIN_STD_CALL_CONV :cchDest
    endif
    ifndef STRSAFE_NO_CB_FUNCTIONS
      ifdef UNICODE
        StringCbCopy equ <StringCbCopyW>
      else
        StringCbCopy equ <StringCbCopyA>
      endif
      StringCbCopyA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_LPCSTR
      sizeof(char)
      StringValidateDestA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringCopyWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL, :pszSrc, :STRSAFE_MAX_LENGTH
      if_ proto WIN_STD_CALL_CONV :cchDest
      StringCbCopyW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_LPCWSTR
      sizeof(wchar_t)
      StringValidateDestW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringCopyWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL, :pszSrc, :STRSAFE_MAX_LENGTH
      if_ proto WIN_STD_CALL_CONV :cchDest
    endif
    ifndef STRSAFE_NO_CCH_FUNCTIONS
      ifdef UNICODE
        StringCchCopyEx equ <StringCchCopyExW>
      else
        StringCchCopyEx equ <StringCchCopyExA>
      endif
      StringCchCopyExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_LPCSTR, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD
      StringExValidateDestA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringExValidateSrcA proto WIN_STD_CALL_CONV :ptr pszSrc, :NULL, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      if_ proto WIN_STD_CALL_CONV :ptr dwFlags
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :ptr pszSrc
      if_ proto WIN_STD_CALL_CONV :pszDest
      StringCopyWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchCopied, :pszSrc, :STRSAFE_MAX_LENGTH
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags :ptr cchRemaining
      sizeof(char)
      StringExHandleFillBehindNullA proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cchDest
      sizeof(char)
      StringExHandleOtherFlagsA proto WIN_STD_CALL_CONV :pszDest, :cbDest, :0, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_
      if_ proto WIN_STD_CALL_CONV :ppszDestEnd
      if_ proto WIN_STD_CALL_CONV :pcchRemaining
      if_ proto WIN_STD_CALL_CONV :cchDest
      StringCchCopyExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_LPCWSTR, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD
      StringExValidateDestW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringExValidateSrcW proto WIN_STD_CALL_CONV :ptr pszSrc, :NULL, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      if_ proto WIN_STD_CALL_CONV :ptr dwFlags
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :ptr pszSrc
      if_ proto WIN_STD_CALL_CONV :pszDest
      StringCopyWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchCopied, :pszSrc, :STRSAFE_MAX_LENGTH
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags :ptr cchRemaining
      sizeof(wchar_t)
      StringExHandleFillBehindNullW proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cchDest
      sizeof(wchar_t)
      StringExHandleOtherFlagsW proto WIN_STD_CALL_CONV :pszDest, :cbDest, :0, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_
      if_ proto WIN_STD_CALL_CONV :ppszDestEnd
      if_ proto WIN_STD_CALL_CONV :pcchRemaining
      if_ proto WIN_STD_CALL_CONV :cchDest
    endif
    ifndef STRSAFE_NO_CB_FUNCTIONS
      ifdef UNICODE
        StringCbCopyEx equ <StringCbCopyExW>
      else
        StringCbCopyEx equ <StringCbCopyExA>
      endif
      StringCbCopyExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_LPCSTR, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD
      sizeof(char)
      StringExValidateDestA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringExValidateSrcA proto WIN_STD_CALL_CONV :ptr pszSrc, :NULL, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      if_ proto WIN_STD_CALL_CONV :ptr dwFlags
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :ptr pszSrc
      if_ proto WIN_STD_CALL_CONV :pszDest
      __analysis_assume_nullterminated(pszDest)
      StringCopyWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchCopied, :pszSrc, :STRSAFE_MAX_LENGTH
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags :ptr cchRemaining
      cbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
      sizeof(char)
      StringExHandleFillBehindNullA proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cbDest
      StringExHandleOtherFlagsA proto WIN_STD_CALL_CONV :pszDest, :cbDest, :0, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_
      if_ proto WIN_STD_CALL_CONV :ppszDestEnd
      if_ proto WIN_STD_CALL_CONV :pcbRemaining
      pcbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
      sizeof(char)
      if_ proto WIN_STD_CALL_CONV :cchDest
      StringCbCopyExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_LPCWSTR, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD
      sizeof(wchar_t)
      StringExValidateDestW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringExValidateSrcW proto WIN_STD_CALL_CONV :ptr pszSrc, :NULL, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      if_ proto WIN_STD_CALL_CONV :ptr dwFlags
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :ptr pszSrc
      if_ proto WIN_STD_CALL_CONV :pszDest
      __analysis_assume_nullterminated(pszDest)
      StringCopyWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchCopied, :pszSrc, :STRSAFE_MAX_LENGTH
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags
      cbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
      sizeof(wchar_t)
      StringExHandleFillBehindNullW proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cbDest
      StringExHandleOtherFlagsW proto WIN_STD_CALL_CONV :pszDest, :cbDest, :0, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_
      if_ proto WIN_STD_CALL_CONV :ppszDestEnd
      if_ proto WIN_STD_CALL_CONV :pcbRemaining
      pcbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
      sizeof(wchar_t)
      if_ proto WIN_STD_CALL_CONV :cchDest
    endif
    ifndef STRSAFE_NO_CCH_FUNCTIONS
      ifdef UNICODE
        StringCchCopyN equ <StringCchCopyNW>
      else
        StringCchCopyN equ <StringCchCopyNA>
      endif
      StringCchCopyNA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_PCNZCH, :size_t
      StringValidateDestA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      if_ proto WIN_STD_CALL_CONV :cchToCopy
      StringCopyWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL, :pszSrc, :cchToCopy
      if_ proto WIN_STD_CALL_CONV :cchDest
      StringCchCopyNW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_PCNZWCH, :size_t
      StringValidateDestW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      if_ proto WIN_STD_CALL_CONV :cchToCopy
      StringCopyWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL, :pszSrc, :cchToCopy
      if_ proto WIN_STD_CALL_CONV :cchDest
    endif
    ifndef STRSAFE_NO_CB_FUNCTIONS
      ifdef UNICODE
        StringCbCopyN equ <StringCbCopyNW>
      else
        StringCbCopyN equ <StringCbCopyNA>
      endif
      StringCbCopyNA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_PCNZCH, :size_t
      sizeof(char)
      StringValidateDestA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      sizeof(char)
      if_ proto WIN_STD_CALL_CONV :cchToCopy
      StringCopyWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL, :pszSrc, :cchToCopy
      StringCbCopyNW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_PCNZWCH, :size_t
      sizeof(wchar_t)
      StringValidateDestW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      sizeof(wchar_t)
      if_ proto WIN_STD_CALL_CONV :cchToCopy
      StringCopyWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL, :pszSrc, :cchToCopy
    endif
    ifndef STRSAFE_NO_CCH_FUNCTIONS
      ifdef UNICODE
        StringCchCopyNEx equ <StringCchCopyNExW>
      else
        StringCchCopyNEx equ <StringCchCopyNExA>
      endif
      StringCchCopyNExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_PCNZCH, :size_t, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD
      StringExValidateDestA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringExValidateSrcA proto WIN_STD_CALL_CONV :ptr pszSrc, :ptr cchToCopy, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      if_ proto WIN_STD_CALL_CONV :ptr dwFlags
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :cchToCopy :ptr ptr pszSrc
      if_ proto WIN_STD_CALL_CONV :pszDest
      StringCopyWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchCopied, :pszSrc, :cchToCopy
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags :ptr cchRemaining
      sizeof(char)
      StringExHandleFillBehindNullA proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cchDest
      sizeof(char)
      StringExHandleOtherFlagsA proto WIN_STD_CALL_CONV :pszDest, :cbDest, :0, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_
      if_ proto WIN_STD_CALL_CONV :ppszDestEnd
      if_ proto WIN_STD_CALL_CONV :pcchRemaining
      if_ proto WIN_STD_CALL_CONV :cchDest
      StringCchCopyNExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_PCNZWCH, :size_t, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD
      StringExValidateDestW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringExValidateSrcW proto WIN_STD_CALL_CONV :ptr pszSrc, :ptr cchToCopy, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      if_ proto WIN_STD_CALL_CONV :ptr dwFlags
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :cchToCopy :ptr ptr pszSrc
      if_ proto WIN_STD_CALL_CONV :pszDest
      StringCopyWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchCopied, :pszSrc, :cchToCopy
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags :ptr cchRemaining
      sizeof(wchar_t)
      StringExHandleFillBehindNullW proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cchDest
      sizeof(wchar_t)
      StringExHandleOtherFlagsW proto WIN_STD_CALL_CONV :pszDest, :cbDest, :0, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_
      if_ proto WIN_STD_CALL_CONV :ppszDestEnd
      if_ proto WIN_STD_CALL_CONV :pcchRemaining
      if_ proto WIN_STD_CALL_CONV :cchDest
    endif
    ifndef STRSAFE_NO_CB_FUNCTIONS
      ifdef UNICODE
        StringCbCopyNEx equ <StringCbCopyNExW>
      else
        StringCbCopyNEx equ <StringCbCopyNExA>
      endif
      StringCbCopyNExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_PCNZCH, :size_t, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD
      sizeof(char)
      StringExValidateDestA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      sizeof(char)
      StringExValidateSrcA proto WIN_STD_CALL_CONV :ptr pszSrc, :ptr cchToCopy, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      if_ proto WIN_STD_CALL_CONV :ptr dwFlags
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :cchToCopy :ptr ptr pszSrc
      if_ proto WIN_STD_CALL_CONV :pszDest
      __analysis_assume_nullterminated(pszDest)
      StringCopyWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchCopied, :pszSrc, :cchToCopy
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags :ptr cchRemaining
      cbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
      sizeof(char)
      StringExHandleFillBehindNullA proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cbDest
      StringExHandleOtherFlagsA proto WIN_STD_CALL_CONV :pszDest, :cbDest, :0, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_
      if_ proto WIN_STD_CALL_CONV :ppszDestEnd
      if_ proto WIN_STD_CALL_CONV :pcbRemaining
      pcbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
      sizeof(char)
      StringCbCopyNExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_PCNZWCH, :size_t, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD
      sizeof(wchar_t)
      StringExValidateDestW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      sizeof(wchar_t)
      StringExValidateSrcW proto WIN_STD_CALL_CONV :ptr pszSrc, :ptr cchToCopy, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      if_ proto WIN_STD_CALL_CONV :ptr dwFlags
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :cchToCopy :ptr ptr pszSrc
      if_ proto WIN_STD_CALL_CONV :pszDest
      __analysis_assume_nullterminated(pszDest)
      StringCopyWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchCopied, :pszSrc, :cchToCopy
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags
      cbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
      sizeof(wchar_t)
      StringExHandleFillBehindNullW proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cbDest
      StringExHandleOtherFlagsW proto WIN_STD_CALL_CONV :pszDest, :cbDest, :0, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_
      if_ proto WIN_STD_CALL_CONV :ppszDestEnd
      if_ proto WIN_STD_CALL_CONV :pcbRemaining
      pcbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
      sizeof(wchar_t)
    endif
    ifndef STRSAFE_NO_CCH_FUNCTIONS
      ifdef UNICODE
        StringCchCat equ <StringCchCatW>
      else
        StringCchCat equ <StringCchCatA>
      endif
      StringCchCatA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_LPCSTR
      StringValidateDestAndLengthA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchDestLength, :STRSAFE_MAX_CCH
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringCopyWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL, :pszSrc, :STRSAFE_MAX_LENGTH
      StringCchCatW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_LPCWSTR
      StringValidateDestAndLengthW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchDestLength, :STRSAFE_MAX_CCH
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringCopyWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL, :pszSrc, :STRSAFE_MAX_LENGTH
    endif
    ifndef STRSAFE_NO_CB_FUNCTIONS
      ifdef UNICODE
        StringCbCat equ <StringCbCatW>
      else
        StringCbCat equ <StringCbCatA>
      endif
      StringCbCatA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_LPCSTR
      sizeof(char)
      StringValidateDestAndLengthA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchDestLength, :STRSAFE_MAX_CCH
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringCopyWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL, :pszSrc, :STRSAFE_MAX_LENGTH
      StringCbCatW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_LPCWSTR
      sizeof(wchar_t)
      StringValidateDestAndLengthW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchDestLength, :STRSAFE_MAX_CCH
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringCopyWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL, :pszSrc, :STRSAFE_MAX_LENGTH
    endif
    ifndef STRSAFE_NO_CCH_FUNCTIONS
      ifdef UNICODE
        StringCchCatEx equ <StringCchCatExW>
      else
        StringCchCatEx equ <StringCchCatExA>
      endif
      StringCchCatExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_LPCSTR, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD
      StringExValidateDestAndLengthA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchDestLength, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringExValidateSrcA proto WIN_STD_CALL_CONV :ptr pszSrc, :NULL, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      if_ proto WIN_STD_CALL_CONV :ptr dwFlags
      if_ proto WIN_STD_CALL_CONV :cchRemaining
      if_ proto WIN_STD_CALL_CONV :ptr pszSrc
      if_ proto WIN_STD_CALL_CONV :pszDest
      StringCopyWorkerA proto WIN_STD_CALL_CONV :pszDestEnd, :cchRemaining, :ptr cchCopied, :pszSrc, :STRSAFE_MAX_LENGTH
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags :ptr cchRemaining
      sizeof(char)
      StringExHandleFillBehindNullA proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cchDest
      sizeof(char)
      StringExHandleOtherFlagsA proto WIN_STD_CALL_CONV :pszDest, :cbDest, :cchDestLength, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_
      if_ proto WIN_STD_CALL_CONV :ppszDestEnd
      if_ proto WIN_STD_CALL_CONV :pcchRemaining
      StringCchCatExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_LPCWSTR, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD
      StringExValidateDestAndLengthW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchDestLength, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringExValidateSrcW proto WIN_STD_CALL_CONV :ptr pszSrc, :NULL, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      if_ proto WIN_STD_CALL_CONV :ptr dwFlags
      if_ proto WIN_STD_CALL_CONV :cchRemaining
      if_ proto WIN_STD_CALL_CONV :ptr pszSrc
      if_ proto WIN_STD_CALL_CONV :pszDest
      StringCopyWorkerW proto WIN_STD_CALL_CONV :pszDestEnd, :cchRemaining, :ptr cchCopied, :pszSrc, :STRSAFE_MAX_LENGTH
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags :ptr cchRemaining
      sizeof(wchar_t)
      StringExHandleFillBehindNullW proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cchDest
      sizeof(wchar_t)
      StringExHandleOtherFlagsW proto WIN_STD_CALL_CONV :pszDest, :cbDest, :cchDestLength, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_
      if_ proto WIN_STD_CALL_CONV :ppszDestEnd
      if_ proto WIN_STD_CALL_CONV :pcchRemaining
    endif
    ifndef STRSAFE_NO_CB_FUNCTIONS
      ifdef UNICODE
        StringCbCatEx equ <StringCbCatExW>
      else
        StringCbCatEx equ <StringCbCatExA>
      endif
      StringCbCatExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_LPCSTR, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD
      sizeof(char)
      StringExValidateDestAndLengthA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchDestLength, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringExValidateSrcA proto WIN_STD_CALL_CONV :ptr pszSrc, :NULL, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      if_ proto WIN_STD_CALL_CONV :ptr dwFlags
      if_ proto WIN_STD_CALL_CONV :cchRemaining
      if_ proto WIN_STD_CALL_CONV :ptr pszSrc
      if_ proto WIN_STD_CALL_CONV :pszDest
      StringCopyWorkerA proto WIN_STD_CALL_CONV :pszDestEnd, :cchRemaining, :ptr cchCopied, :pszSrc, :STRSAFE_MAX_LENGTH
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags :ptr cchRemaining
      cbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
      sizeof(char)
      StringExHandleFillBehindNullA proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cbDest
      StringExHandleOtherFlagsA proto WIN_STD_CALL_CONV :pszDest, :cbDest, :cchDestLength, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_
      if_ proto WIN_STD_CALL_CONV :ppszDestEnd
      if_ proto WIN_STD_CALL_CONV :pcbRemaining
      pcbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
      sizeof(char)
      StringCbCatExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_LPCWSTR, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD
      sizeof(wchar_t)
      StringExValidateDestAndLengthW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchDestLength, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringExValidateSrcW proto WIN_STD_CALL_CONV :ptr pszSrc, :NULL, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      if_ proto WIN_STD_CALL_CONV :ptr dwFlags
      if_ proto WIN_STD_CALL_CONV :cchRemaining
      if_ proto WIN_STD_CALL_CONV :ptr pszSrc
      if_ proto WIN_STD_CALL_CONV :pszDest
      StringCopyWorkerW proto WIN_STD_CALL_CONV :pszDestEnd, :cchRemaining, :ptr cchCopied, :pszSrc, :STRSAFE_MAX_LENGTH
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags
      cbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
      sizeof(wchar_t)
      StringExHandleFillBehindNullW proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cbDest
      StringExHandleOtherFlagsW proto WIN_STD_CALL_CONV :pszDest, :cbDest, :cchDestLength, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_
      if_ proto WIN_STD_CALL_CONV :ppszDestEnd
      if_ proto WIN_STD_CALL_CONV :pcbRemaining
      pcbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
      sizeof(wchar_t)
    endif
    ifndef STRSAFE_NO_CCH_FUNCTIONS
      ifdef UNICODE
        StringCchCatN equ <StringCchCatNW>
      else
        StringCchCatN equ <StringCchCatNA>
      endif
      StringCchCatNA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_PCNZCH, :size_t
      StringValidateDestAndLengthA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchDestLength, :STRSAFE_MAX_CCH
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      if_ proto WIN_STD_CALL_CONV :cchToAppend
      StringCopyWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL, :pszSrc, :cchToAppend
      StringCchCatNW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_PCNZWCH, :size_t
      StringValidateDestAndLengthW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchDestLength, :STRSAFE_MAX_CCH
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      if_ proto WIN_STD_CALL_CONV :cchToAppend
      StringCopyWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL, :pszSrc, :cchToAppend
    endif
    ifndef STRSAFE_NO_CB_FUNCTIONS
      ifdef UNICODE
        StringCbCatN equ <StringCbCatNW>
      else
        StringCbCatN equ <StringCbCatNA>
      endif
      StringCbCatNA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_PCNZCH, :size_t
      sizeof(char)
      StringValidateDestAndLengthA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchDestLength, :STRSAFE_MAX_CCH
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      sizeof(char)
      if_ proto WIN_STD_CALL_CONV :cchToAppend
      StringCopyWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL, :pszSrc, :cchToAppend
      StringCbCatNW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_PCNZWCH, :size_t
      sizeof(wchar_t)
      StringValidateDestAndLengthW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchDestLength, :STRSAFE_MAX_CCH
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      sizeof(wchar_t)
      if_ proto WIN_STD_CALL_CONV :cchToAppend
      StringCopyWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL, :pszSrc, :cchToAppend
    endif
    ifndef STRSAFE_NO_CCH_FUNCTIONS
      ifdef UNICODE
        StringCchCatNEx equ <StringCchCatNExW>
      else
        StringCchCatNEx equ <StringCchCatNExA>
      endif
      StringCchCatNExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_PCNZCH, :size_t, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD
      StringExValidateDestAndLengthA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchDestLength, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringExValidateSrcA proto WIN_STD_CALL_CONV :ptr pszSrc, :ptr cchToAppend, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      if_ proto WIN_STD_CALL_CONV :ptr dwFlags
      if_ proto WIN_STD_CALL_CONV :cchRemaining
      if_ proto WIN_STD_CALL_CONV :cchToAppend :ptr ptr pszSrc
      if_ proto WIN_STD_CALL_CONV :pszDest
      StringCopyWorkerA proto WIN_STD_CALL_CONV :pszDestEnd, :cchRemaining, :ptr cchCopied, :pszSrc, :cchToAppend
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags :ptr cchRemaining
      sizeof(char)
      StringExHandleFillBehindNullA proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cchDest
      sizeof(char)
      StringExHandleOtherFlagsA proto WIN_STD_CALL_CONV :pszDest, :cbDest, :cchDestLength, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_
      if_ proto WIN_STD_CALL_CONV :ppszDestEnd
      if_ proto WIN_STD_CALL_CONV :pcchRemaining
      StringCchCatNExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_PCNZWCH, :size_t, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD
      StringExValidateDestAndLengthW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchDestLength, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringExValidateSrcW proto WIN_STD_CALL_CONV :ptr pszSrc, :ptr cchToAppend, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      if_ proto WIN_STD_CALL_CONV :ptr dwFlags
      if_ proto WIN_STD_CALL_CONV :cchRemaining
      if_ proto WIN_STD_CALL_CONV :cchToAppend :ptr ptr pszSrc
      if_ proto WIN_STD_CALL_CONV :pszDest
      StringCopyWorkerW proto WIN_STD_CALL_CONV :pszDestEnd, :cchRemaining, :ptr cchCopied, :pszSrc, :cchToAppend
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags :ptr cchRemaining
      sizeof(wchar_t)
      StringExHandleFillBehindNullW proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cchDest
      sizeof(wchar_t)
      StringExHandleOtherFlagsW proto WIN_STD_CALL_CONV :pszDest, :cbDest, :cchDestLength, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_
      if_ proto WIN_STD_CALL_CONV :ppszDestEnd
      if_ proto WIN_STD_CALL_CONV :pcchRemaining
    endif
    ifndef STRSAFE_NO_CB_FUNCTIONS
      ifdef UNICODE
        StringCbCatNEx equ <StringCbCatNExW>
      else
        StringCbCatNEx equ <StringCbCatNExA>
      endif
      StringCbCatNExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_PCNZCH, :size_t, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD
      sizeof(char)
      StringExValidateDestAndLengthA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchDestLength, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      sizeof(char)
      StringExValidateSrcA proto WIN_STD_CALL_CONV :ptr pszSrc, :ptr cchToAppend, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      if_ proto WIN_STD_CALL_CONV :ptr dwFlags
      if_ proto WIN_STD_CALL_CONV :cchRemaining
      if_ proto WIN_STD_CALL_CONV :cchToAppend :ptr ptr pszSrc
      if_ proto WIN_STD_CALL_CONV :pszDest
      StringCopyWorkerA proto WIN_STD_CALL_CONV :pszDestEnd, :cchRemaining, :ptr cchCopied, :pszSrc, :cchToAppend
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags :ptr cchRemaining
      cbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
      sizeof(char)
      StringExHandleFillBehindNullA proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cbDest
      StringExHandleOtherFlagsA proto WIN_STD_CALL_CONV :pszDest, :cbDest, :cchDestLength, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_
      if_ proto WIN_STD_CALL_CONV :ppszDestEnd
      if_ proto WIN_STD_CALL_CONV :pcbRemaining
      pcbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
      sizeof(char)
      StringCbCatNExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_PCNZWCH, :size_t, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD
      sizeof(wchar_t)
      StringExValidateDestAndLengthW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchDestLength, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      sizeof(wchar_t)
      StringExValidateSrcW proto WIN_STD_CALL_CONV :ptr pszSrc, :ptr cchToAppend, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      if_ proto WIN_STD_CALL_CONV :ptr dwFlags
      if_ proto WIN_STD_CALL_CONV :cchRemaining
      if_ proto WIN_STD_CALL_CONV :cchToAppend :ptr ptr pszSrc
      if_ proto WIN_STD_CALL_CONV :pszDest
      StringCopyWorkerW proto WIN_STD_CALL_CONV :pszDestEnd, :cchRemaining, :ptr cchCopied, :pszSrc, :cchToAppend
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags
      cbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
      sizeof(wchar_t)
      StringExHandleFillBehindNullW proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cbDest
      StringExHandleOtherFlagsW proto WIN_STD_CALL_CONV :pszDest, :cbDest, :cchDestLength, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_
      if_ proto WIN_STD_CALL_CONV :ppszDestEnd
      if_ proto WIN_STD_CALL_CONV :pcbRemaining
      pcbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
      sizeof(wchar_t)
    endif
    ifndef STRSAFE_NO_CCH_FUNCTIONS
      ifdef UNICODE
        StringCchVPrintf equ <StringCchVPrintfW>
      else
        StringCchVPrintf equ <StringCchVPrintfA>
      endif
      StringCchVPrintfA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_LPCSTR, :va_list
      StringValidateDestA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringVPrintfWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL, :pszFormat, :argList
      if_ proto WIN_STD_CALL_CONV :cchDest
      StringCchVPrintfW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_LPCWSTR, :va_list
      StringValidateDestW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringVPrintfWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL, :pszFormat, :argList
      if_ proto WIN_STD_CALL_CONV :cchDest
    endif
    if Defined(STRSAFE_LOCALE_FUNCTIONS) and  not Defined(STRSAFE_NO_CCH_FUNCTIONS)
      ifdef UNICODE
        StringCchVPrintf_l equ <StringCchVPrintf_lW>
      else
        StringCchVPrintf_l equ <StringCchVPrintf_lA>
      endif
      StringCchVPrintf_lA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_LPCSTR, :_locale_t, :va_list
      StringValidateDestA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringVPrintf_lWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL, :pszFormat, :locale, :argList
      StringCchVPrintf_lW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_LPCWSTR, :_locale_t, :va_list
      StringValidateDestW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringVPrintf_lWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL, :pszFormat, :locale, :argList
    endif
    ifndef STRSAFE_NO_CB_FUNCTIONS
      ifdef UNICODE
        StringCbVPrintf equ <StringCbVPrintfW>
      else
        StringCbVPrintf equ <StringCbVPrintfA>
      endif
      StringCbVPrintfA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_LPCSTR, :va_list
      sizeof(char)
      StringValidateDestA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringVPrintfWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL, :pszFormat, :argList
      if_ proto WIN_STD_CALL_CONV :cchDest
      StringCbVPrintfW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_LPCWSTR, :va_list
      sizeof(wchar_t)
      StringValidateDestW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringVPrintfWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL, :pszFormat, :argList
      if_ proto WIN_STD_CALL_CONV :cchDest
    endif
    if Defined(STRSAFE_LOCALE_FUNCTIONS) and  not Defined(STRSAFE_NO_CB_FUNCTIONS)
      ifdef UNICODE
        StringCbVPrintf_l equ <StringCbVPrintf_lW>
      else
        StringCbVPrintf_l equ <StringCbVPrintf_lA>
      endif
      StringCbVPrintf_lA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_LPCSTR, :_locale_t, :va_list
      sizeof(char)
      StringValidateDestA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringVPrintf_lWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL, :pszFormat, :locale, :argList
      StringCbVPrintf_lW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_LPCWSTR, :_locale_t, :va_list
      sizeof(wchar_t)
      StringValidateDestW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringVPrintf_lWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL, :pszFormat, :locale, :argList
    endif
    ifndef _M_CEE_PURE
      ifndef STRSAFE_NO_CCH_FUNCTIONS
        ifdef UNICODE
          StringCchPrintf equ <StringCchPrintfW>
        else
          StringCchPrintf equ <StringCchPrintfA>
        endif
        StringCchPrintfA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_LPCSTR, :vararg
        StringValidateDestA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED
        va_start proto WIN_STD_CALL_CONV :argList, :pszFormat
        StringVPrintfWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL, :pszFormat, :argList
        va_end proto WIN_STD_CALL_CONV :argList
        if_ proto WIN_STD_CALL_CONV :cchDest
        StringCchPrintfW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_LPCWSTR, :vararg
        StringValidateDestW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED
        va_start proto WIN_STD_CALL_CONV :argList, :pszFormat
        StringVPrintfWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL, :pszFormat, :argList
        va_end proto WIN_STD_CALL_CONV :argList
        if_ proto WIN_STD_CALL_CONV :cchDest
      endif
      if Defined(STRSAFE_LOCALE_FUNCTIONS) and  not Defined(STRSAFE_NO_CCH_FUNCTIONS)
        ifdef UNICODE
          StringCchPrintf_l equ <StringCchPrintf_lW>
        else
          StringCchPrintf_l equ <StringCchPrintf_lA>
        endif
        StringCchPrintf_lA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_LPCSTR, :_locale_t, :vararg
        StringValidateDestA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED
        va_start proto WIN_STD_CALL_CONV :argList, :locale
        StringVPrintf_lWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL, :pszFormat, :locale, :argList
        va_end proto WIN_STD_CALL_CONV :argList
        StringCchPrintf_lW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_LPCWSTR, :_locale_t, :vararg
        StringValidateDestW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED
        va_start proto WIN_STD_CALL_CONV :argList, :locale
        StringVPrintf_lWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL, :pszFormat, :locale, :argList
        va_end proto WIN_STD_CALL_CONV :argList
      endif
      ifndef STRSAFE_NO_CB_FUNCTIONS
        ifdef UNICODE
          StringCbPrintf equ <StringCbPrintfW>
        else
          StringCbPrintf equ <StringCbPrintfA>
        endif
        StringCbPrintfA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_LPCSTR, :vararg
        sizeof(char)
        StringValidateDestA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED
        va_start proto WIN_STD_CALL_CONV :argList, :pszFormat
        StringVPrintfWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL, :pszFormat, :argList
        va_end proto WIN_STD_CALL_CONV :argList
        if_ proto WIN_STD_CALL_CONV :cchDest
        StringCbPrintfW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_LPCWSTR, :vararg
        sizeof(wchar_t)
        StringValidateDestW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED
        va_start proto WIN_STD_CALL_CONV :argList, :pszFormat
        StringVPrintfWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL, :pszFormat, :argList
        va_end proto WIN_STD_CALL_CONV :argList
        if_ proto WIN_STD_CALL_CONV :cchDest
      endif
      if Defined(STRSAFE_LOCALE_FUNCTIONS) and  not Defined(STRSAFE_NO_CB_FUNCTIONS)
        ifdef UNICODE
          StringCbPrintf_l equ <StringCbPrintf_lW>
        else
          StringCbPrintf_l equ <StringCbPrintf_lA>
        endif
        StringCbPrintf_lA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :STRSAFE_LPCSTR, :_locale_t, :vararg
        sizeof(char)
        StringValidateDestA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED
        va_start proto WIN_STD_CALL_CONV :argList, :locale
        StringVPrintf_lWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL, :pszFormat, :locale, :argList
        va_end proto WIN_STD_CALL_CONV :argList
        StringCbPrintf_lW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :STRSAFE_LPCWSTR, :_locale_t, :vararg
        sizeof(wchar_t)
        StringValidateDestW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED
        va_start proto WIN_STD_CALL_CONV :argList, :locale
        StringVPrintf_lWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL, :pszFormat, :locale, :argList
        va_end proto WIN_STD_CALL_CONV :argList
      endif
      ifndef STRSAFE_NO_CCH_FUNCTIONS
        ifdef UNICODE
          StringCchPrintfEx equ <StringCchPrintfExW>
        else
          StringCchPrintfEx equ <StringCchPrintfExA>
        endif
        StringCchPrintfExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD, :STRSAFE_LPCSTR, :vararg
        StringExValidateDestA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH, :dwFlags
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED
        StringExValidateSrcA proto WIN_STD_CALL_CONV :ptr pszFormat, :NULL, :STRSAFE_MAX_CCH, :dwFlags
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED
        if_ proto WIN_STD_CALL_CONV :ptr dwFlags
        if_ proto WIN_STD_CALL_CONV :cchDest
        if_ proto WIN_STD_CALL_CONV :cchDest
        if_ proto WIN_STD_CALL_CONV :ptr pszFormat
        if_ proto WIN_STD_CALL_CONV :pszDest
        va_start proto WIN_STD_CALL_CONV :argList, :pszFormat
        StringVPrintfWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchNewDestLength, :pszFormat, :argList
        va_end proto WIN_STD_CALL_CONV :argList
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags :ptr cchRemaining
        sizeof(char)
        StringExHandleFillBehindNullA proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
        if_ proto WIN_STD_CALL_CONV :cchDest
        if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cchDest
        sizeof(char)
        StringExHandleOtherFlagsA proto WIN_STD_CALL_CONV :pszDest, :cbDest, :0, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_
        if_ proto WIN_STD_CALL_CONV :ppszDestEnd
        if_ proto WIN_STD_CALL_CONV :pcchRemaining
        if_ proto WIN_STD_CALL_CONV :cchDest
        StringCchPrintfExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD, :STRSAFE_LPCWSTR, :vararg
        StringExValidateDestW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH, :dwFlags
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED
        StringExValidateSrcW proto WIN_STD_CALL_CONV :ptr pszFormat, :NULL, :STRSAFE_MAX_CCH, :dwFlags
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED
        if_ proto WIN_STD_CALL_CONV :ptr dwFlags
        if_ proto WIN_STD_CALL_CONV :cchDest
        if_ proto WIN_STD_CALL_CONV :cchDest
        if_ proto WIN_STD_CALL_CONV :ptr pszFormat
        if_ proto WIN_STD_CALL_CONV :pszDest
        va_start proto WIN_STD_CALL_CONV :argList, :pszFormat
        StringVPrintfWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchNewDestLength, :pszFormat, :argList
        va_end proto WIN_STD_CALL_CONV :argList
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags :ptr cchRemaining
        sizeof(wchar_t)
        StringExHandleFillBehindNullW proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
        if_ proto WIN_STD_CALL_CONV :cchDest
        if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cchDest
        sizeof(wchar_t)
        StringExHandleOtherFlagsW proto WIN_STD_CALL_CONV :pszDest, :cbDest, :0, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_
        if_ proto WIN_STD_CALL_CONV :ppszDestEnd
        if_ proto WIN_STD_CALL_CONV :pcchRemaining
        if_ proto WIN_STD_CALL_CONV :cchDest
      endif
      if Defined(STRSAFE_LOCALE_FUNCTIONS) and  not Defined(STRSAFE_NO_CCH_FUNCTIONS)
        ifdef UNICODE
          StringCchPrintf_lEx equ <StringCchPrintf_lExW>
        else
          StringCchPrintf_lEx equ <StringCchPrintf_lExA>
        endif
        StringCchPrintf_lExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD, :STRSAFE_LPCSTR, :_locale_t, :vararg
        StringExValidateDestA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH, :dwFlags
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED
        StringExValidateSrcA proto WIN_STD_CALL_CONV :ptr pszFormat, :NULL, :STRSAFE_MAX_CCH, :dwFlags
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED
        if_ proto WIN_STD_CALL_CONV :ptr dwFlags
        if_ proto WIN_STD_CALL_CONV :cchDest
        if_ proto WIN_STD_CALL_CONV :cchDest
        if_ proto WIN_STD_CALL_CONV :ptr pszFormat
        if_ proto WIN_STD_CALL_CONV :pszDest
        va_start proto WIN_STD_CALL_CONV :argList, :locale
        StringVPrintf_lWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchNewDestLength, :pszFormat, :locale, :argList
        va_end proto WIN_STD_CALL_CONV :argList
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags :ptr cchRemaining
        sizeof(char)
        StringExHandleFillBehindNullA proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
        if_ proto WIN_STD_CALL_CONV :cchDest
        if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cchDest
        sizeof(char)
        StringExHandleOtherFlagsA proto WIN_STD_CALL_CONV :pszDest, :cbDest, :0, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_
        if_ proto WIN_STD_CALL_CONV :ppszDestEnd
        if_ proto WIN_STD_CALL_CONV :pcchRemaining
        StringCchPrintf_lExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD, :STRSAFE_LPCWSTR, :_locale_t, :vararg
        StringExValidateDestW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH, :dwFlags
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED
        StringExValidateSrcW proto WIN_STD_CALL_CONV :ptr pszFormat, :NULL, :STRSAFE_MAX_CCH, :dwFlags
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED
        if_ proto WIN_STD_CALL_CONV :ptr dwFlags
        if_ proto WIN_STD_CALL_CONV :cchDest
        if_ proto WIN_STD_CALL_CONV :cchDest
        if_ proto WIN_STD_CALL_CONV :ptr pszFormat
        if_ proto WIN_STD_CALL_CONV :pszDest
        va_start proto WIN_STD_CALL_CONV :argList, :locale
        StringVPrintf_lWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchNewDestLength, :pszFormat, :locale, :argList
        va_end proto WIN_STD_CALL_CONV :argList
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags :ptr cchRemaining
        sizeof(wchar_t)
        StringExHandleFillBehindNullW proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
        if_ proto WIN_STD_CALL_CONV :cchDest
        if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cchDest
        sizeof(wchar_t)
        StringExHandleOtherFlagsW proto WIN_STD_CALL_CONV :pszDest, :cbDest, :0, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_
        if_ proto WIN_STD_CALL_CONV :ppszDestEnd
        if_ proto WIN_STD_CALL_CONV :pcchRemaining
      endif
      ifndef STRSAFE_NO_CB_FUNCTIONS
        ifdef UNICODE
          StringCbPrintfEx equ <StringCbPrintfExW>
        else
          StringCbPrintfEx equ <StringCbPrintfExA>
        endif
        StringCbPrintfExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD, :STRSAFE_LPCSTR, :vararg
        sizeof(char)
        StringExValidateDestA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH, :dwFlags
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED
        StringExValidateSrcA proto WIN_STD_CALL_CONV :ptr pszFormat, :NULL, :STRSAFE_MAX_CCH, :dwFlags
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED
        if_ proto WIN_STD_CALL_CONV :ptr dwFlags
        if_ proto WIN_STD_CALL_CONV :cchDest
        if_ proto WIN_STD_CALL_CONV :cchDest
        if_ proto WIN_STD_CALL_CONV :ptr pszFormat
        if_ proto WIN_STD_CALL_CONV :pszDest
        __analysis_assume_nullterminated(pszDest)
        va_start proto WIN_STD_CALL_CONV :argList, :pszFormat
        StringVPrintfWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchNewDestLength, :pszFormat, :argList
        va_end proto WIN_STD_CALL_CONV :argList
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags :ptr cchRemaining
        cbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
        sizeof(char)
        StringExHandleFillBehindNullA proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
        if_ proto WIN_STD_CALL_CONV :cchDest
        if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cbDest
        StringExHandleOtherFlagsA proto WIN_STD_CALL_CONV :pszDest, :cbDest, :0, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_
        if_ proto WIN_STD_CALL_CONV :ppszDestEnd
        if_ proto WIN_STD_CALL_CONV :pcbRemaining
        pcbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
        sizeof(char)
        if_ proto WIN_STD_CALL_CONV :cchDest
        StringCbPrintfExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD, :STRSAFE_LPCWSTR, :vararg
        sizeof(wchar_t)
        StringExValidateDestW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH, :dwFlags
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED
        StringExValidateSrcW proto WIN_STD_CALL_CONV :ptr pszFormat, :NULL, :STRSAFE_MAX_CCH, :dwFlags
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED
        if_ proto WIN_STD_CALL_CONV :ptr dwFlags
        if_ proto WIN_STD_CALL_CONV :cchDest
        if_ proto WIN_STD_CALL_CONV :cchDest
        if_ proto WIN_STD_CALL_CONV :ptr pszFormat
        if_ proto WIN_STD_CALL_CONV :pszDest
        __analysis_assume_nullterminated(pszDest)
        va_start proto WIN_STD_CALL_CONV :argList, :pszFormat
        StringVPrintfWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchNewDestLength, :pszFormat, :argList
        va_end proto WIN_STD_CALL_CONV :argList
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags
        cbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
        sizeof(wchar_t)
        StringExHandleFillBehindNullW proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
        if_ proto WIN_STD_CALL_CONV :cchDest
        if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cbDest
        StringExHandleOtherFlagsW proto WIN_STD_CALL_CONV :pszDest, :cbDest, :0, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_
        if_ proto WIN_STD_CALL_CONV :ppszDestEnd
        if_ proto WIN_STD_CALL_CONV :pcbRemaining
        pcbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
        sizeof(wchar_t)
        if_ proto WIN_STD_CALL_CONV :cchDest
      endif
      if Defined(STRSAFE_LOCALE_FUNCTIONS) and  not Defined(STRSAFE_NO_CB_FUNCTIONS)
        ifdef UNICODE
          StringCbPrintf_lEx equ <StringCbPrintf_lExW>
        else
          StringCbPrintf_lEx equ <StringCbPrintf_lExA>
        endif
        StringCbPrintf_lExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD, :STRSAFE_LPCSTR, :_locale_t, :vararg
        sizeof(char)
        StringExValidateDestA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH, :dwFlags
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED
        StringExValidateSrcA proto WIN_STD_CALL_CONV :ptr pszFormat, :NULL, :STRSAFE_MAX_CCH, :dwFlags
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED
        if_ proto WIN_STD_CALL_CONV :ptr dwFlags
        if_ proto WIN_STD_CALL_CONV :cchDest
        if_ proto WIN_STD_CALL_CONV :cchDest
        if_ proto WIN_STD_CALL_CONV :ptr pszFormat
        if_ proto WIN_STD_CALL_CONV :pszDest
        va_start proto WIN_STD_CALL_CONV :argList, :locale
        StringVPrintf_lWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchNewDestLength, :pszFormat, :locale, :argList
        va_end proto WIN_STD_CALL_CONV :argList
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags :ptr cchRemaining
        cbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
        sizeof(char)
        StringExHandleFillBehindNullA proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
        if_ proto WIN_STD_CALL_CONV :cchDest
        if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cbDest
        StringExHandleOtherFlagsA proto WIN_STD_CALL_CONV :pszDest, :cbDest, :0, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_
        if_ proto WIN_STD_CALL_CONV :ppszDestEnd
        if_ proto WIN_STD_CALL_CONV :pcbRemaining
        pcbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
        sizeof(char)
        StringCbPrintf_lExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD, :STRSAFE_LPCWSTR, :_locale_t, :vararg
        sizeof(wchar_t)
        StringExValidateDestW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH, :dwFlags
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED
        StringExValidateSrcW proto WIN_STD_CALL_CONV :ptr pszFormat, :NULL, :STRSAFE_MAX_CCH, :dwFlags
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED
        if_ proto WIN_STD_CALL_CONV :ptr dwFlags
        if_ proto WIN_STD_CALL_CONV :cchDest
        if_ proto WIN_STD_CALL_CONV :cchDest
        if_ proto WIN_STD_CALL_CONV :ptr pszFormat
        if_ proto WIN_STD_CALL_CONV :pszDest
        va_start proto WIN_STD_CALL_CONV :argList, :locale
        StringVPrintf_lWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchNewDestLength, :pszFormat, :locale, :argList
        va_end proto WIN_STD_CALL_CONV :argList
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags
        cbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
        sizeof(wchar_t)
        StringExHandleFillBehindNullW proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
        if_ proto WIN_STD_CALL_CONV :cchDest
        if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cbDest
        StringExHandleOtherFlagsW proto WIN_STD_CALL_CONV :pszDest, :cbDest, :0, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_
        if_ proto WIN_STD_CALL_CONV :ppszDestEnd
        if_ proto WIN_STD_CALL_CONV :pcbRemaining
        pcbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
        sizeof(wchar_t)
      endif
    endif
    ifndef STRSAFE_NO_CCH_FUNCTIONS
      ifdef UNICODE
        StringCchVPrintfEx equ <StringCchVPrintfExW>
      else
        StringCchVPrintfEx equ <StringCchVPrintfExA>
      endif
      StringCchVPrintfExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD, :STRSAFE_LPCSTR, :va_list
      StringExValidateDestA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringExValidateSrcA proto WIN_STD_CALL_CONV :ptr pszFormat, :NULL, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      if_ proto WIN_STD_CALL_CONV :ptr dwFlags
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :ptr pszFormat
      if_ proto WIN_STD_CALL_CONV :pszDest
      StringVPrintfWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchNewDestLength, :pszFormat, :argList
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags :ptr cchRemaining
      sizeof(char)
      StringExHandleFillBehindNullA proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cchDest
      sizeof(char)
      StringExHandleOtherFlagsA proto WIN_STD_CALL_CONV :pszDest, :cbDest, :0, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_
      if_ proto WIN_STD_CALL_CONV :ppszDestEnd
      if_ proto WIN_STD_CALL_CONV :pcchRemaining
      if_ proto WIN_STD_CALL_CONV :cchDest
      StringCchVPrintfExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD, :STRSAFE_LPCWSTR, :va_list
      StringExValidateDestW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringExValidateSrcW proto WIN_STD_CALL_CONV :ptr pszFormat, :NULL, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      if_ proto WIN_STD_CALL_CONV :ptr dwFlags
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :ptr pszFormat
      if_ proto WIN_STD_CALL_CONV :pszDest
      StringVPrintfWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchNewDestLength, :pszFormat, :argList
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags :ptr cchRemaining
      sizeof(wchar_t)
      StringExHandleFillBehindNullW proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cchDest
      sizeof(wchar_t)
      StringExHandleOtherFlagsW proto WIN_STD_CALL_CONV :pszDest, :cbDest, :0, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_
      if_ proto WIN_STD_CALL_CONV :ppszDestEnd
      if_ proto WIN_STD_CALL_CONV :pcchRemaining
      if_ proto WIN_STD_CALL_CONV :cchDest
    endif
    if Defined(STRSAFE_LOCALE_FUNCTIONS) and  not Defined(STRSAFE_NO_CCH_FUNCTIONS)
      ifdef UNICODE
        StringCchVPrintf_lEx equ <StringCchVPrintf_lExW>
      else
        StringCchVPrintf_lEx equ <StringCchVPrintf_lExA>
      endif
      StringCchVPrintf_lExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD, :STRSAFE_LPCSTR, :_locale_t, :va_list
      StringExValidateDestA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringExValidateSrcA proto WIN_STD_CALL_CONV :ptr pszFormat, :NULL, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      if_ proto WIN_STD_CALL_CONV :ptr dwFlags
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :ptr pszFormat
      if_ proto WIN_STD_CALL_CONV :pszDest
      StringVPrintf_lWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchNewDestLength, :pszFormat, :locale, :argList
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags :ptr cchRemaining
      sizeof(char)
      StringExHandleFillBehindNullA proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cchDest
      sizeof(char)
      StringExHandleOtherFlagsA proto WIN_STD_CALL_CONV :pszDest, :cbDest, :0, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_
      if_ proto WIN_STD_CALL_CONV :ppszDestEnd
      if_ proto WIN_STD_CALL_CONV :pcchRemaining
      StringCchVPrintf_lExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD, :STRSAFE_LPCWSTR, :_locale_t, :va_list
      StringExValidateDestW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringExValidateSrcW proto WIN_STD_CALL_CONV :ptr pszFormat, :NULL, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      if_ proto WIN_STD_CALL_CONV :ptr dwFlags
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :ptr pszFormat
      if_ proto WIN_STD_CALL_CONV :pszDest
      StringVPrintf_lWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchNewDestLength, :pszFormat, :locale, :argList
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags :ptr cchRemaining
      sizeof(wchar_t)
      StringExHandleFillBehindNullW proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cchDest
      sizeof(wchar_t)
      StringExHandleOtherFlagsW proto WIN_STD_CALL_CONV :pszDest, :cbDest, :0, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_
      if_ proto WIN_STD_CALL_CONV :ppszDestEnd
      if_ proto WIN_STD_CALL_CONV :pcchRemaining
    endif
    ifndef STRSAFE_NO_CB_FUNCTIONS
      ifdef UNICODE
        StringCbVPrintfEx equ <StringCbVPrintfExW>
      else
        StringCbVPrintfEx equ <StringCbVPrintfExA>
      endif
      StringCbVPrintfExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD, :STRSAFE_LPCSTR, :va_list
      sizeof(char)
      StringExValidateDestA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringExValidateSrcA proto WIN_STD_CALL_CONV :ptr pszFormat, :NULL, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      if_ proto WIN_STD_CALL_CONV :ptr dwFlags
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :ptr pszFormat
      if_ proto WIN_STD_CALL_CONV :pszDest
      __analysis_assume_nullterminated(pszDest)
      StringVPrintfWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchNewDestLength, :pszFormat, :argList
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags :ptr cchRemaining
      cbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
      sizeof(char)
      StringExHandleFillBehindNullA proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cbDest
      StringExHandleOtherFlagsA proto WIN_STD_CALL_CONV :pszDest, :cbDest, :0, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_
      if_ proto WIN_STD_CALL_CONV :ppszDestEnd
      if_ proto WIN_STD_CALL_CONV :pcbRemaining
      pcbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
      sizeof(char)
      StringCbVPrintfExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD, :STRSAFE_LPCWSTR, :va_list
      sizeof(wchar_t)
      StringExValidateDestW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringExValidateSrcW proto WIN_STD_CALL_CONV :ptr pszFormat, :NULL, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      if_ proto WIN_STD_CALL_CONV :ptr dwFlags
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :ptr pszFormat
      if_ proto WIN_STD_CALL_CONV :pszDest
      __analysis_assume_nullterminated(pszDest)
      StringVPrintfWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchNewDestLength, :pszFormat, :argList
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags
      cbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
      sizeof(wchar_t)
      StringExHandleFillBehindNullW proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cbDest
      StringExHandleOtherFlagsW proto WIN_STD_CALL_CONV :pszDest, :cbDest, :0, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_
      if_ proto WIN_STD_CALL_CONV :ppszDestEnd
      if_ proto WIN_STD_CALL_CONV :pcbRemaining
      pcbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
      sizeof(wchar_t)
    endif
    if Defined(STRSAFE_LOCALE_FUNCTIONS) and  not Defined(STRSAFE_NO_CB_FUNCTIONS)
      ifdef UNICODE
        StringCbVPrintf_lEx equ <StringCbVPrintf_lExW>
      else
        StringCbVPrintf_lEx equ <StringCbVPrintf_lExA>
      endif
      StringCbVPrintf_lExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD, :STRSAFE_LPCSTR, :_locale_t, :va_list
      sizeof(char)
      StringExValidateDestA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringExValidateSrcA proto WIN_STD_CALL_CONV :ptr pszFormat, :NULL, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      if_ proto WIN_STD_CALL_CONV :ptr dwFlags
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :ptr pszFormat
      if_ proto WIN_STD_CALL_CONV :pszDest
      StringVPrintf_lWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchNewDestLength, :pszFormat, :locale, :argList
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags :ptr cchRemaining
      cbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
      sizeof(char)
      StringExHandleFillBehindNullA proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cbDest
      StringExHandleOtherFlagsA proto WIN_STD_CALL_CONV :pszDest, :cbDest, :0, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_
      if_ proto WIN_STD_CALL_CONV :ppszDestEnd
      if_ proto WIN_STD_CALL_CONV :pcbRemaining
      pcbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
      sizeof(char)
      StringCbVPrintf_lExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD, :STRSAFE_LPCWSTR, :_locale_t, :va_list
      sizeof(wchar_t)
      StringExValidateDestW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      StringExValidateSrcW proto WIN_STD_CALL_CONV :ptr pszFormat, :NULL, :STRSAFE_MAX_CCH, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      if_ proto WIN_STD_CALL_CONV :ptr dwFlags
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :ptr pszFormat
      if_ proto WIN_STD_CALL_CONV :pszDest
      StringVPrintf_lWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchNewDestLength, :pszFormat, :locale, :argList
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags
      cbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
      sizeof(wchar_t)
      StringExHandleFillBehindNullW proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :cchDest
      if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cbDest
      StringExHandleOtherFlagsW proto WIN_STD_CALL_CONV :pszDest, :cbDest, :0, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_
      if_ proto WIN_STD_CALL_CONV :ppszDestEnd
      if_ proto WIN_STD_CALL_CONV :pcbRemaining
      pcbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
      sizeof(wchar_t)
    endif
    ifndef STRSAFE_LIB_IMPL
      ifndef STRSAFE_NO_CCH_FUNCTIONS
        ifdef UNICODE
          StringCchGets equ <StringCchGetsW>
        else
          StringCchGets equ <StringCchGetsA>
        endif
        StringCchGetsA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t
        StringValidateDestA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED
        StringGetsWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL
        if_ proto WIN_STD_CALL_CONV :cchDest
        StringCchGetsW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t
        StringValidateDestW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED
        StringGetsWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL
        if_ proto WIN_STD_CALL_CONV :cchDest
      endif
      ifndef STRSAFE_NO_CB_FUNCTIONS
        ifdef UNICODE
          StringCbGets equ <StringCbGetsW>
        else
          StringCbGets equ <StringCbGetsA>
        endif
        StringCbGetsA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t
        sizeof(char)
        StringValidateDestA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED
        StringGetsWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL
        if_ proto WIN_STD_CALL_CONV :cchDest
        StringCbGetsW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t
        sizeof(wchar_t)
        StringValidateDestW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED
        StringGetsWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :NULL
        if_ proto WIN_STD_CALL_CONV :cchDest
      endif
      ifndef STRSAFE_NO_CCH_FUNCTIONS
        ifdef UNICODE
          StringCchGetsEx equ <StringCchGetsExW>
        else
          StringCchGetsEx equ <StringCchGetsExA>
        endif
        StringCchGetsExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD
        StringExValidateDestA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH, :dwFlags
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED
        if_ proto WIN_STD_CALL_CONV :ptr dwFlags
        if_ proto WIN_STD_CALL_CONV :cchDest
        if_ proto WIN_STD_CALL_CONV :cchDest
        if_ proto WIN_STD_CALL_CONV :pszDest
        StringGetsWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchNewDestLength
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags :ptr cchRemaining
        sizeof(char)
        StringExHandleFillBehindNullA proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
        if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cchDest
        sizeof(char)
        StringExHandleOtherFlagsA proto WIN_STD_CALL_CONV :pszDest, :cbDest, :0, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_ :||_
        if_ proto WIN_STD_CALL_CONV :ppszDestEnd
        if_ proto WIN_STD_CALL_CONV :pcchRemaining
        if_ proto WIN_STD_CALL_CONV :cchDest
        StringCchGetsExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD
        StringExValidateDestW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH, :dwFlags
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED
        if_ proto WIN_STD_CALL_CONV :ptr dwFlags
        if_ proto WIN_STD_CALL_CONV :cchDest
        if_ proto WIN_STD_CALL_CONV :cchDest
        if_ proto WIN_STD_CALL_CONV :pszDest
        StringGetsWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchNewDestLength
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags :ptr cchRemaining
        sizeof(wchar_t)
        StringExHandleFillBehindNullW proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
        if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cchDest
        sizeof(wchar_t)
        StringExHandleOtherFlagsW proto WIN_STD_CALL_CONV :pszDest, :cbDest, :0, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_ :||_
        if_ proto WIN_STD_CALL_CONV :ppszDestEnd
        if_ proto WIN_STD_CALL_CONV :pcchRemaining
        if_ proto WIN_STD_CALL_CONV :cchDest
      endif
      ifndef STRSAFE_NO_CB_FUNCTIONS
        ifdef UNICODE
          StringCbGetsEx equ <StringCbGetsExW>
        else
          StringCbGetsEx equ <StringCbGetsExA>
        endif
        StringCbGetsExA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD
        sizeof(char)
        StringExValidateDestA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH, :dwFlags
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED
        if_ proto WIN_STD_CALL_CONV :ptr dwFlags
        if_ proto WIN_STD_CALL_CONV :cchDest
        if_ proto WIN_STD_CALL_CONV :cchDest
        if_ proto WIN_STD_CALL_CONV :pszDest
        StringGetsWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchNewDestLength
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags :ptr cchRemaining
        cbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
        sizeof(char)
        StringExHandleFillBehindNullA proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
        if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cbDest
        StringExHandleOtherFlagsA proto WIN_STD_CALL_CONV :pszDest, :cbDest, :0, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_ :||_
        if_ proto WIN_STD_CALL_CONV :ppszDestEnd
        if_ proto WIN_STD_CALL_CONV :pcbRemaining
        pcbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
        sizeof(char)
        if_ proto WIN_STD_CALL_CONV :cchDest
        StringCbGetsExW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD
        sizeof(wchar_t)
        StringExValidateDestW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :STRSAFE_MAX_CCH, :dwFlags
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED
        if_ proto WIN_STD_CALL_CONV :ptr dwFlags
        if_ proto WIN_STD_CALL_CONV :cchDest
        if_ proto WIN_STD_CALL_CONV :cchDest
        if_ proto WIN_STD_CALL_CONV :pszDest
        StringGetsWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :ptr cchNewDestLength
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED :ptr ptr dwFlags
        cbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
        sizeof(wchar_t)
        StringExHandleFillBehindNullW proto WIN_STD_CALL_CONV :pszDestEnd, :cbRemaining, :dwFlags
        if_ proto WIN_STD_CALL_CONV :FAILED :ptr ptr dwFlags :ptr cbDest
        StringExHandleOtherFlagsW proto WIN_STD_CALL_CONV :pszDest, :cbDest, :0, :ptr pszDestEnd, :ptr cchRemaining, :dwFlags
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED :||_ :||_
        if_ proto WIN_STD_CALL_CONV :ppszDestEnd
        if_ proto WIN_STD_CALL_CONV :pcbRemaining
        pcbRemaining proto WIN_STD_CALL_CONV :ptr cchRemaining
        sizeof(wchar_t)
        if_ proto WIN_STD_CALL_CONV :cchDest
      endif
    endif
    ifndef STRSAFE_NO_CCH_FUNCTIONS
      ifdef UNICODE
        StringCchLength equ <StringCchLengthW>
      else
        StringCchLength equ <StringCchLengthA>
      endif
      StringCchLengthA proto WIN_STD_CALL_CONV :STRSAFE_PCNZCH, :size_t, :ptr size_t
      if_ proto WIN_STD_CALL_CONV :psz :||_
      StringLengthWorkerA proto WIN_STD_CALL_CONV :psz, :cchMax, :pcchLength
      if_ proto WIN_STD_CALL_CONV :FAILED :ptr pcchLength
      StringCchLengthW proto WIN_STD_CALL_CONV :STRSAFE_PCNZWCH, :size_t, :ptr size_t
      if_ proto WIN_STD_CALL_CONV :psz :||_
      StringLengthWorkerW proto WIN_STD_CALL_CONV :psz, :cchMax, :pcchLength
      if_ proto WIN_STD_CALL_CONV :FAILED :ptr pcchLength
    endif
    ifndef STRSAFE_NO_CB_FUNCTIONS
      ifdef UNICODE
        StringCbLength equ <StringCbLengthW>
      else
        StringCbLength equ <StringCbLengthA>
      endif
      StringCbLengthA proto WIN_STD_CALL_CONV :STRSAFE_PCNZCH, :size_t, :ptr size_t
      sizeof(char)
      if_ proto WIN_STD_CALL_CONV :psz :||_
      StringLengthWorkerA proto WIN_STD_CALL_CONV :psz, :cchMax, :ptr cchLength
      if_ proto WIN_STD_CALL_CONV :pcbLength
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      sizeof(char)
      StringCbLengthW proto WIN_STD_CALL_CONV :STRSAFE_PCNZWCH, :size_t, :ptr size_t
      sizeof(wchar_t)
      if_ proto WIN_STD_CALL_CONV :psz :||_
      StringLengthWorkerW proto WIN_STD_CALL_CONV :psz, :cchMax, :ptr cchLength
      if_ proto WIN_STD_CALL_CONV :pcbLength
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
      sizeof(wchar_t)
    endif
    ifndef STRSAFE_NO_CCH_FUNCTIONS
      ifdef UNICODE
        UnalignedStringCchLength equ <UnalignedStringCchLengthW>
      else
        UnalignedStringCchLength equ <StringCchLengthA>
      endif
      ifdef ALIGNMENT_MACHINE
        UnalignedStringCchLengthW proto WIN_STD_CALL_CONV :STRSAFE_PCUNZWCH, :size_t, :ptr size_t
        if_ proto WIN_STD_CALL_CONV :psz :||_
        UnalignedStringLengthWorkerW proto WIN_STD_CALL_CONV :psz, :cchMax, :pcchLength
        if_ proto WIN_STD_CALL_CONV :FAILED :ptr pcchLength
      else
        UnalignedStringCchLengthW equ <StringCchLengthW>
      endif
    endif
    ifndef STRSAFE_NO_CB_FUNCTIONS
      ifdef UNICODE
        UnalignedStringCbLength equ <UnalignedStringCbLengthW>
      else
        UnalignedStringCbLength equ <StringCbLengthA>
      endif
      ifdef ALIGNMENT_MACHINE
        UnalignedStringCbLengthW proto WIN_STD_CALL_CONV :STRSAFE_PCUNZWCH, :size_t, :ptr size_t
        sizeof(wchar_t)
        if_ proto WIN_STD_CALL_CONV :psz :||_
        UnalignedStringLengthWorkerW proto WIN_STD_CALL_CONV :psz, :cchMax, :ptr cchLength
        if_ proto WIN_STD_CALL_CONV :pcbLength
        if_ proto WIN_STD_CALL_CONV :SUCCEEDED
        sizeof(wchar_t)
      else
        UnalignedStringCbLengthW equ <StringCbLengthW>
      endif
    endif
  endif
  if Defined(STRSAFE_LIB_IMPL) or  not Defined(STRSAFE_LIB)
    StringLengthWorkerA proto WIN_STD_CALL_CONV :STRSAFE_PCNZCH, :size_t, :ptr size_t
    while_ proto WIN_STD_CALL_CONV :ptr ptr cchMax
    if_ proto WIN_STD_CALL_CONV :cchMax
    if_ proto WIN_STD_CALL_CONV :pcchLength
    if_ proto WIN_STD_CALL_CONV :SUCCEEDED
    StringLengthWorkerW proto WIN_STD_CALL_CONV :STRSAFE_PCNZWCH, :size_t, :ptr size_t
    while_ proto WIN_STD_CALL_CONV :ptr ptr cchMax
    if_ proto WIN_STD_CALL_CONV :cchMax
    if_ proto WIN_STD_CALL_CONV :pcchLength
    if_ proto WIN_STD_CALL_CONV :SUCCEEDED
    ifdef ALIGNMENT_MACHINE
      UnalignedStringLengthWorkerW proto WIN_STD_CALL_CONV :STRSAFE_PCUNZWCH, :size_t, :ptr size_t
      while_ proto WIN_STD_CALL_CONV :ptr ptr cchMax
      if_ proto WIN_STD_CALL_CONV :cchMax
      if_ proto WIN_STD_CALL_CONV :pcchLength
      if_ proto WIN_STD_CALL_CONV :SUCCEEDED
    endif
    StringExValidateSrcA proto WIN_STD_CALL_CONV :ptr STRSAFE_PCNZCH, :ptr size_t, :size_t, :DWORD
    if_ proto WIN_STD_CALL_CONV :ptr ptr pcchToRead
    if_ proto WIN_STD_CALL_CONV :ptr dwFlags :ptr ptr ppszSrc
    if_ proto WIN_STD_CALL_CONV :pcchToRead
    StringExValidateSrcW proto WIN_STD_CALL_CONV :ptr STRSAFE_PCNZWCH, :ptr size_t, :size_t, :DWORD
    if_ proto WIN_STD_CALL_CONV :ptr ptr pcchToRead
    if_ proto WIN_STD_CALL_CONV :ptr dwFlags :ptr ptr ppszSrc
    if_ proto WIN_STD_CALL_CONV :pcchToRead
    StringValidateDestA proto WIN_STD_CALL_CONV :STRSAFE_PCNZCH, :size_t, :size_t
    if_ proto WIN_STD_CALL_CONV :cchDest :||_
    StringValidateDestAndLengthA proto WIN_STD_CALL_CONV :STRSAFE_LPCSTR, :size_t, :ptr size_t, :size_t
    StringValidateDestA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :cchMax
    if_ proto WIN_STD_CALL_CONV :SUCCEEDED
    StringLengthWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :pcchDestLength
    StringValidateDestW proto WIN_STD_CALL_CONV :STRSAFE_PCNZWCH, :size_t, :size_t
    if_ proto WIN_STD_CALL_CONV :cchDest :||_
    StringValidateDestAndLengthW proto WIN_STD_CALL_CONV :STRSAFE_LPCWSTR, :size_t, :ptr size_t, :size_t
    StringValidateDestW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :cchMax
    if_ proto WIN_STD_CALL_CONV :SUCCEEDED
    StringLengthWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :pcchDestLength
    StringExValidateDestA proto WIN_STD_CALL_CONV :STRSAFE_PCNZCH, :size_t, :size_t, :DWORD
    if_ proto WIN_STD_CALL_CONV :ptr dwFlags
    if_ proto WIN_STD_CALL_CONV :pszDest :ptr cchDest :||_
    StringValidateDestA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :cchMax
    StringExValidateDestAndLengthA proto WIN_STD_CALL_CONV :STRSAFE_LPCSTR, :size_t, :ptr size_t, :size_t, :DWORD
    if_ proto WIN_STD_CALL_CONV :ptr dwFlags
    StringExValidateDestA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :cchMax, :dwFlags
    if_ proto WIN_STD_CALL_CONV :FAILED :||_
    StringLengthWorkerA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :pcchDestLength
    StringValidateDestAndLengthA proto WIN_STD_CALL_CONV :pszDest, :cchDest, :pcchDestLength, :cchMax
    StringExValidateDestW proto WIN_STD_CALL_CONV :STRSAFE_PCNZWCH, :size_t, :size_t, :DWORD
    if_ proto WIN_STD_CALL_CONV :ptr dwFlags
    if_ proto WIN_STD_CALL_CONV :pszDest :ptr cchDest :||_
    StringValidateDestW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :cchMax
    StringExValidateDestAndLengthW proto WIN_STD_CALL_CONV :STRSAFE_LPCWSTR, :size_t, :ptr size_t, :size_t, :DWORD
    if_ proto WIN_STD_CALL_CONV :ptr dwFlags
    StringExValidateDestW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :cchMax, :dwFlags
    if_ proto WIN_STD_CALL_CONV :FAILED :||_
    StringLengthWorkerW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :pcchDestLength
    StringValidateDestAndLengthW proto WIN_STD_CALL_CONV :pszDest, :cchDest, :pcchDestLength, :cchMax
    StringCopyWorkerA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr size_t, :STRSAFE_PCNZCH, :size_t
    while_ proto WIN_STD_CALL_CONV :ptr ptr ptr cchDest
    if_ proto WIN_STD_CALL_CONV :cchDest
    if_ proto WIN_STD_CALL_CONV :pcchNewDestLength
    StringCopyWorkerW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr size_t, :STRSAFE_PCNZWCH, :size_t
    while_ proto WIN_STD_CALL_CONV :ptr ptr ptr cchDest
    if_ proto WIN_STD_CALL_CONV :cchDest
    if_ proto WIN_STD_CALL_CONV :pcchNewDestLength
    StringVPrintfWorkerA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr size_t, :STRSAFE_LPCSTR, :va_list
    if (STRSAFE_USE_SECURE_CRT eq 1) and  not Defined(STRSAFE_LIB_IMPL)
      _vsnprintf_s proto WIN_STD_CALL_CONV :pszDest, :cchDest, :cchMax, :pszFormat, :argList
    else
      _vsnprintf proto WIN_STD_CALL_CONV :pszDest, :cchMax, :pszFormat, :argList
    endif
    if_ proto WIN_STD_CALL_CONV :iRet_ :||_ :iRet_ :>
    if_ proto WIN_STD_CALL_CONV :size_t :iRet_ :==
    cchNewDestLength proto WIN_STD_CALL_CONV :size_t
    if_ proto WIN_STD_CALL_CONV :pcchNewDestLength
    ifdef STRSAFE_LOCALE_FUNCTIONS
      StringVPrintf_lWorkerA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr size_t, :STRSAFE_LPCSTR, :_locale_t, :va_list
      if (STRSAFE_USE_SECURE_CRT eq 1) and  not Defined(STRSAFE_LIB_IMPL)
        _vsnprintf_s_l proto WIN_STD_CALL_CONV :pszDest, :cchDest, :cchMax, :pszFormat, :locale, :argList
      else
        _vsnprintf_l proto WIN_STD_CALL_CONV :pszDest, :cchMax, :pszFormat, :locale, :argList
      endif
      if_ proto WIN_STD_CALL_CONV :iRet_ :||_ :iRet_ :>
      if_ proto WIN_STD_CALL_CONV :size_t :iRet_ :==
      cchNewDestLength proto WIN_STD_CALL_CONV :size_t
      if_ proto WIN_STD_CALL_CONV :pcchNewDestLength
    endif
    StringVPrintfWorkerW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr size_t, :STRSAFE_LPCWSTR, :va_list
    if (STRSAFE_USE_SECURE_CRT eq 1) and  not Defined(STRSAFE_LIB_IMPL)
      _vsnwprintf_s proto WIN_STD_CALL_CONV :pszDest, :cchDest, :cchMax, :pszFormat, :argList
    else
      _vsnwprintf proto WIN_STD_CALL_CONV :pszDest, :cchMax, :pszFormat, :argList
    endif
    if_ proto WIN_STD_CALL_CONV :iRet_ :||_ :iRet_ :>
    if_ proto WIN_STD_CALL_CONV :size_t :iRet_ :==
    cchNewDestLength proto WIN_STD_CALL_CONV :size_t
    if_ proto WIN_STD_CALL_CONV :pcchNewDestLength
    ifdef STRSAFE_LOCALE_FUNCTIONS
      StringVPrintf_lWorkerW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr size_t, :STRSAFE_LPCWSTR, :_locale_t, :va_list
      if (STRSAFE_USE_SECURE_CRT eq 1) and  not Defined(STRSAFE_LIB_IMPL)
        _vsnwprintf_s_l proto WIN_STD_CALL_CONV :pszDest, :cchDest, :cchMax, :pszFormat, :locale, :argList
      else
        _vsnwprintf_l proto WIN_STD_CALL_CONV :pszDest, :cchMax, :pszFormat, :locale, :argList
      endif
      if_ proto WIN_STD_CALL_CONV :iRet_ :||_ :iRet_ :>
      if_ proto WIN_STD_CALL_CONV :size_t :iRet_ :==
      cchNewDestLength proto WIN_STD_CALL_CONV :size_t
      if_ proto WIN_STD_CALL_CONV :pcchNewDestLength
    endif
  endif
  ifndef STRSAFE_LIB_IMPL
    StringGetsWorkerA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :ptr size_t
    if_ proto WIN_STD_CALL_CONV :cchDest
    while_ proto WIN_STD_CALL_CONV :cchDest
    getc(stdin)
    if_ proto WIN_STD_CALL_CONV :i
    if_ proto WIN_STD_CALL_CONV :cchNewDestLength
    ch_ proto WIN_STD_CALL_CONV :SBYTE
    if_ proto WIN_STD_CALL_CONV :ch_
    if_ proto WIN_STD_CALL_CONV :pcchNewDestLength
    StringGetsWorkerW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :ptr size_t
    if_ proto WIN_STD_CALL_CONV :cchDest
    while_ proto WIN_STD_CALL_CONV :cchDest
    getwc(stdin)
    if_ proto WIN_STD_CALL_CONV :ch_
    if_ proto WIN_STD_CALL_CONV :cchNewDestLength
    if_ proto WIN_STD_CALL_CONV :ch_
    if_ proto WIN_STD_CALL_CONV :pcchNewDestLength
  endif
  if Defined(STRSAFE_LIB_IMPL) or  not Defined(STRSAFE_LIB)
    StringExHandleFillBehindNullA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :DWORD
    if_ proto WIN_STD_CALL_CONV :cbRemaining
    memset proto WIN_STD_CALL_CONV :pszDestEnd, :STRSAFE_GET_FILL_PATTERN, :cbRemaining
    StringExHandleFillBehindNullW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :DWORD
    if_ proto WIN_STD_CALL_CONV :cbRemaining
    memset proto WIN_STD_CALL_CONV :pszDestEnd, :STRSAFE_GET_FILL_PATTERN, :cbRemaining
    StringExHandleOtherFlagsA proto WIN_STD_CALL_CONV :STRSAFE_LPSTR, :size_t, :size_t, :ptr STRSAFE_LPSTR, :ptr size_t, :DWORD
    sizeof(char)
    if_ proto WIN_STD_CALL_CONV :cchDest :ptr ptr dwFlags
    if_ proto WIN_STD_CALL_CONV :ptr dwFlags
    memset proto WIN_STD_CALL_CONV :pszDest, :STRSAFE_GET_FILL_PATTERN, :cbDest
    if_ proto WIN_STD_CALL_CONV :STRSAFE_GET_FILL_PATTERN :==
    if_ proto WIN_STD_CALL_CONV :cchDest
    if_ proto WIN_STD_CALL_CONV :cchDest :ptr ptr dwFlags
    StringExHandleOtherFlagsW proto WIN_STD_CALL_CONV :STRSAFE_LPWSTR, :size_t, :size_t, :ptr STRSAFE_LPWSTR, :ptr size_t, :DWORD
    sizeof(wchar_t)
    if_ proto WIN_STD_CALL_CONV :cchDest :ptr ptr dwFlags
    if_ proto WIN_STD_CALL_CONV :ptr dwFlags
    memset proto WIN_STD_CALL_CONV :pszDest, :STRSAFE_GET_FILL_PATTERN, :cbDest
    if_ proto WIN_STD_CALL_CONV :STRSAFE_GET_FILL_PATTERN :==
    if_ proto WIN_STD_CALL_CONV :cchDest
    if_ proto WIN_STD_CALL_CONV :cchDest :ptr ptr dwFlags
  endif
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
