;Include file created by h2incX, Version B.01.01, 19/04/2018 10:43
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\stdlib.h', last modified: 01/10/2012 08:50
;Creation parameters: 

ifndef _INC_STDLIB
  _INC_STDLIB equ <>
  include crtdefs.inc
  include limits.inc
  ifdef __cplusplus
    ;[...]
  endif
  ifndef NULL
    ifdef __cplusplus
      ;[...]
    else
      NULL equ (0)
    endif
  endif
  EXIT_SUCCESS equ 0
  EXIT_FAILURE equ 1
  ifndef _ONEXIT_T_DEFINED
    if  not Defined(_M_CEE_PURE)
      TYPE__onexit_t typedef proto c
      _onexit_t typedef ptr TYPE__onexit_t
    else
      ;[...]
    endif
    if Defined(_M_CEE_MIXED)
      ;[...]
    endif
    if  not __STDC__
      onexit_t equ <_onexit_t>
    endif
    _ONEXIT_T_DEFINED equ <>
  endif
  ifndef _DIV_T_DEFINED
    div_t struct
      quot SDWORD ?
      rem SDWORD ?
    div_t ends
    _div_t typedef div_t
    ldiv_t struct
      quot SDWORD ?
      rem SDWORD ?
    ldiv_t ends
    _ldiv_t typedef ldiv_t
    lldiv_t struct
      quot SQWORD ?
      rem SQWORD ?
    lldiv_t ends
    _lldiv_t typedef lldiv_t
    _DIV_T_DEFINED equ <>
  endif
  ifndef _CRT_DOUBLE_DEC
    ifndef _LDSUPPORT
      _LDOUBLE struct
        ld BYTE 10 dup (?)
      _LDOUBLE ends
      _PTR_LD macro x
        exitm <((and (x) - ld))>
      endm
    else
      _LDOUBLE typedef REAL10
      _PTR_LD macro x
        exitm <((x))>
      endm
    endif
    _CRT_DOUBLE struct
      x REAL8 ?
    _CRT_DOUBLE ends
    _CRT_FLOAT struct
      f REAL4 ?
    _CRT_FLOAT ends
    _LONGDOUBLE struct
      x REAL10 ?
    _LONGDOUBLE ends
    _LDBL12 struct
      ld12 BYTE 12 dup (?)
    _LDBL12 ends
    _CRT_DOUBLE_DEC equ <>
  endif
  RAND_MAX equ 7fffh
  ifndef MB_CUR_MAX
    MB_CUR_MAX equ <___mb_cur_max_func ()>
    if  not Defined(_M_CEE_PURE)
      externdef __mb_cur_max:SDWORD
    else
      ;[...]
    endif
    @DefProto DllImport, ___mb_cur_max_func, c,, <>
    @DefProto DllImport, ___mb_cur_max_l_func, c,, <:_locale_t>
  endif
  __max macro a, b
    exitm <(((a) > (b)) ? (a) : (b))>
  endm
  __min macro a, b
    exitm <(((a) < (b)) ? (a) : (b))>
  endm
  _MAX_PATH equ 260
  _MAX_DRIVE equ 3
  _MAX_DIR equ 256
  _MAX_FNAME equ 256
  _MAX_EXT equ 256
  _OUT_TO_DEFAULT equ 0
  _OUT_TO_STDERR equ 1
  _OUT_TO_MSGBOX equ 2
  _REPORT_ERRMODE equ 3
  _WRITE_ABORT_MSG equ 1h
  _CALL_REPORTFAULT equ 2h
  _MAX_ENV equ 32767
  if  not Defined(_M_CEE_PURE)
    TYPE__purecall_handler typedef proto c
    _purecall_handler typedef ptr TYPE__purecall_handler
    @DefProto DllImport, _set_purecall_handler, c,, <:_purecall_handler>
    @DefProto DllImport, _get_purecall_handler, c,, <>
  endif
  if Defined(__cplusplus)
    ;[...]
  endif
  if  not Defined(_M_CEE_PURE)
    TYPE__invalid_parameter_handler typedef proto c :ptr wchar_t, :ptr wchar_t, :ptr wchar_t, :DWORD, :uintptr_t
    _invalid_parameter_handler typedef ptr TYPE__invalid_parameter_handler
    @DefProto DllImport, _set_invalid_parameter_handler, c,, <:_invalid_parameter_handler>
    @DefProto DllImport, _get_invalid_parameter_handler, c,, <>
  endif
  ifndef _CRT_ERRNO_DEFINED
    _CRT_ERRNO_DEFINED equ <>
    @DefProto DllImport, _errno, c,, <>
    errno equ <(* _errno ())>
    _set_errno proto c :SDWORD
    _get_errno proto c :ptr SDWORD
  endif
  @DefProto DllImport, __doserrno, c,, <>
  _doserrno equ <(* __doserrno ())>
  _set_doserrno proto c :DWORD
  _get_doserrno proto c :ptr DWORD
  @DefProto DllImport, __sys_errlist, c,, <>
  _sys_errlist equ <(__sys_errlist ())>
  @DefProto DllImport, __sys_nerr, c,, <>
  _sys_nerr equ <(* __sys_nerr ())>
  if Defined(_DLL) and Defined(_M_IX86)
    ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
      @DefProto DllImport, __p___argc, c,, <>
      @DefProto DllImport, __p___argv, c,, <>
      @DefProto DllImport, __p___wargv, c,, <>
      @DefProto DllImport, __p__environ, c,, <>
      @DefProto DllImport, __p__wenviron, c,, <>
    endif
    @DefProto DllImport, __p__pgmptr, c,, <>
    @DefProto DllImport, __p__wpgmptr, c,, <>
  endif
  ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
    if  not Defined(_M_CEE_PURE)
      externdef __argc:SDWORD
    else
      ;[...]
    endif
  endif
  if  not Defined(_M_CEE_PURE)
    ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
      ifdef _POSIX_
        ;[...]
      else
      endif
    endif
  else
    ;[...]
  endif
  _get_pgmptr proto c :ptr ptr SBYTE
  _get_wpgmptr proto c :ptr ptr wchar_t
  if  not Defined(_M_CEE_PURE)
    externdef _fmode:SDWORD
  else
    ;[...]
  endif
  @DefProto DllImport, _set_fmode, c,, <:SDWORD>
  @DefProto DllImport, _get_fmode, c,, <:ptr SDWORD>
  if  not Defined(_countof)
    if  not Defined(__cplusplus)
      _countof macro _Array
        exitm <(sizeof(_Array) / sizeof(_Array [ 0 ]))>
      endm
    else
      ;[...]
    endif
  endif
  ifndef _CRT_TERMINATE_DEFINED
    _CRT_TERMINATE_DEFINED equ <>
    @DefProto DllImport, exit, c,, <:SDWORD>
    @DefProto DllImport, _exit, c,, <:SDWORD>
    @DefProto DllImport, abort, c,, <>
  endif
  @DefProto DllImport, _set_abort_behavior, c,, <:DWORD, :DWORD>
  ifndef _CRT_ABS_DEFINED
    _CRT_ABS_DEFINED equ <>
    abs_ proto c :SDWORD
    labs proto c :SDWORD
    llabs proto c :SQWORD
  endif
  _abs64 proto c :SQWORD
  if Defined(_M_CEE)
    ;[...]
  endif
  if Defined(_M_CEE_PURE)
    ;[...]
  else
    atexit proto c :ptr
  endif
  ifndef _CRT_ATOF_DEFINED
    _CRT_ATOF_DEFINED equ <>
    @DefProto DllImport, atof, c,, <:ptr SBYTE>
    @DefProto DllImport, _atof_l, c,, <:ptr SBYTE, :_locale_t>
  endif
  @DefProto DllImport, atoi, c,, <:ptr SBYTE>
  @DefProto DllImport, _atoi_l, c,, <:ptr SBYTE, :_locale_t>
  @DefProto DllImport, atol, c,, <:ptr SBYTE>
  @DefProto DllImport, _atol_l, c,, <:ptr SBYTE, :_locale_t>
  ifndef _CRT_ALGO_DEFINED
    _CRT_ALGO_DEFINED equ <>
    if __STDC_WANT_SECURE_LIB__
      @DefProto DllImport, bsearch_s, c,, <:ptr, :ptr, :rsize_t, :rsize_t, :ptr, :ptr>
    endif
    @DefProto DllImport, bsearch, c,, <:ptr, :ptr, :size_t, :size_t, :ptr>
    if __STDC_WANT_SECURE_LIB__
      @DefProto DllImport, qsort_s, c,, <:ptr, :rsize_t, :rsize_t, :ptr, :ptr>
    endif
    @DefProto DllImport, qsort, c,, <:ptr, :size_t, :size_t, :ptr>
  endif
  _byteswap_ushort proto c :WORD
  _byteswap_ulong proto c :DWORD
  _byteswap_uint64 proto c :QWORD
  @DefProto DllImport, div, c, _, <:SDWORD, :SDWORD>
  ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
    @DefProto DllImport, getenv, c,, <:ptr SBYTE>
    if __STDC_WANT_SECURE_LIB__
      @DefProto DllImport, getenv_s, c,, <:ptr size_t, :ptr SBYTE, :rsize_t, :ptr SBYTE>
    endif
    if Defined(_DEBUG) and Defined(_CRTDBG_MAP_ALLOC)
    endif
    @DefProto DllImport, _dupenv_s, c,, <:ptr ptr SBYTE, :ptr size_t, :ptr SBYTE>
    if Defined(_DEBUG) and Defined(_CRTDBG_MAP_ALLOC)
    endif
  endif
  @DefProto DllImport, _itoa_s, c,, <:SDWORD, :ptr SBYTE, :size_t, :SDWORD>
  @DefProto DllImport, _i64toa_s, c,, <:SQWORD, :ptr SBYTE, :size_t, :SDWORD>
  @DefProto DllImport, _i64toa, c,, <:SQWORD, :ptr SBYTE, :SDWORD>
  @DefProto DllImport, _ui64toa_s, c,, <:QWORD, :ptr SBYTE, :size_t, :SDWORD>
  @DefProto DllImport, _ui64toa, c,, <:QWORD, :ptr SBYTE, :SDWORD>
  @DefProto DllImport, _atoi64, c,, <:ptr SBYTE>
  @DefProto DllImport, _atoi64_l, c,, <:ptr SBYTE, :_locale_t>
  @DefProto DllImport, _strtoi64, c,, <:ptr SBYTE, :ptr ptr SBYTE, :SDWORD>
  @DefProto DllImport, _strtoi64_l, c,, <:ptr SBYTE, :ptr ptr SBYTE, :SDWORD, :_locale_t>
  @DefProto DllImport, _strtoui64, c,, <:ptr SBYTE, :ptr ptr SBYTE, :SDWORD>
  @DefProto DllImport, _strtoui64_l, c,, <:ptr SBYTE, :ptr ptr SBYTE, :SDWORD, :_locale_t>
  @DefProto DllImport, ldiv, c,, <:SDWORD, :SDWORD>
  @DefProto DllImport, lldiv, c,, <:SQWORD, :SQWORD>
  ifdef __cplusplus
    ;[...]
  endif
  @DefProto DllImport, _ltoa_s, c,, <:SDWORD, :ptr SBYTE, :size_t, :SDWORD>
  @DefProto DllImport, mblen, c,, <:ptr SBYTE, :size_t>
  @DefProto DllImport, _mblen_l, c,, <:ptr SBYTE, :size_t, :_locale_t>
  @DefProto DllImport, _mbstrlen, c,, <:ptr SBYTE>
  @DefProto DllImport, _mbstrlen_l, c,, <:ptr SBYTE, :_locale_t>
  @DefProto DllImport, _mbstrnlen, c,, <:ptr SBYTE, :size_t>
  @DefProto DllImport, _mbstrnlen_l, c,, <:ptr SBYTE, :size_t, :_locale_t>
  @DefProto DllImport, mbtowc, c,, <:ptr wchar_t, :ptr SBYTE, :size_t>
  @DefProto DllImport, _mbtowc_l, c,, <:ptr wchar_t, :ptr SBYTE, :size_t, :_locale_t>
  @DefProto DllImport, mbstowcs_s, c,, <:ptr size_t, :ptr wchar_t, :size_t, :ptr SBYTE, :size_t>
  @DefProto DllImport, _mbstowcs_s_l, c,, <:ptr size_t, :ptr wchar_t, :size_t, :ptr SBYTE, :size_t, :_locale_t>
  @DefProto DllImport, rand, c,, <>
  if Defined(_CRT_RAND_S)
    @DefProto DllImport, rand_s, c,, <:ptr DWORD>
  endif
  @DefProto DllImport, _set_error_mode, c,, <:SDWORD>
  @DefProto DllImport, srand, c,, <:DWORD>
  @DefProto DllImport, strtod, c,, <:ptr SBYTE, :ptr ptr SBYTE>
  @DefProto DllImport, _strtod_l, c,, <:ptr SBYTE, :ptr ptr SBYTE, :_locale_t>
  @DefProto DllImport, strtol, c,, <:ptr SBYTE, :ptr ptr SBYTE, :SDWORD>
  @DefProto DllImport, _strtol_l, c,, <:ptr SBYTE, :ptr ptr SBYTE, :SDWORD, :_locale_t>
  @DefProto DllImport, strtoul, c,, <:ptr SBYTE, :ptr ptr SBYTE, :SDWORD>
  @DefProto DllImport, _strtoul_l, c,, <:ptr SBYTE, :ptr ptr SBYTE, :SDWORD, :_locale_t>
  ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
    ifndef _CRT_SYSTEM_DEFINED
      _CRT_SYSTEM_DEFINED equ <>
      @DefProto DllImport, system, c,, <:ptr SBYTE>
    endif
  endif
  @DefProto DllImport, _ultoa_s, c,, <:DWORD, :ptr SBYTE, :size_t, :SDWORD>
  wctomb proto c :ptr SBYTE, :wchar_t
  @DefProto DllImport, _wctomb_l, c,, <:ptr SBYTE, :wchar_t, :_locale_t>
  if __STDC_WANT_SECURE_LIB__
    @DefProto DllImport, wctomb_s, c,, <:ptr SDWORD, :ptr SBYTE, :rsize_t, :wchar_t>
  endif
  @DefProto DllImport, _wctomb_s_l, c,, <:ptr SDWORD, :ptr SBYTE, :size_t, :wchar_t, :_locale_t>
  @DefProto DllImport, wcstombs_s, c,, <:ptr size_t, :ptr SBYTE, :size_t, :ptr wchar_t, :size_t>
  @DefProto DllImport, _wcstombs_s_l, c,, <:ptr size_t, :ptr SBYTE, :size_t, :ptr wchar_t, :size_t, :_locale_t>
  if Defined(__cplusplus) and Defined(_M_CEE)
    ;[...]
  endif
  ifndef _CRT_ALLOCATION_DEFINED
    _CRT_ALLOCATION_DEFINED equ <>
    if Defined(_DEBUG) and Defined(_CRTDBG_MAP_ALLOC)
    endif
    @DefProto DllImport, calloc, c,, <:size_t, :size_t>
    @DefProto DllImport, free, c,, <:ptr>
    @DefProto DllImport, malloc, c,, <:size_t>
    @DefProto DllImport, realloc, c,, <:ptr, :size_t>
    @DefProto DllImport, _recalloc, c,, <:ptr, :size_t, :size_t>
    @DefProto DllImport, _aligned_free, c,, <:ptr>
    @DefProto DllImport, _aligned_malloc, c,, <:size_t, :size_t>
    @DefProto DllImport, _aligned_offset_malloc, c,, <:size_t, :size_t, :size_t>
    @DefProto DllImport, _aligned_realloc, c,, <:ptr, :size_t, :size_t>
    @DefProto DllImport, _aligned_recalloc, c,, <:ptr, :size_t, :size_t, :size_t>
    @DefProto DllImport, _aligned_offset_realloc, c,, <:ptr, :size_t, :size_t, :size_t>
    @DefProto DllImport, _aligned_offset_recalloc, c,, <:ptr, :size_t, :size_t, :size_t, :size_t>
    @DefProto DllImport, _aligned_msize, c,, <:ptr, :size_t, :size_t>
    if Defined(_DEBUG) and Defined(_CRTDBG_MAP_ALLOC)
    endif
  endif
  ifndef _WSTDLIB_DEFINED
    @DefProto DllImport, _itow_s, c,, <:SDWORD, :ptr wchar_t, :size_t, :SDWORD>
    @DefProto DllImport, _ltow_s, c,, <:SDWORD, :ptr wchar_t, :size_t, :SDWORD>
    @DefProto DllImport, _ultow_s, c,, <:DWORD, :ptr wchar_t, :size_t, :SDWORD>
    @DefProto DllImport, wcstod, c,, <:ptr wchar_t, :ptr ptr wchar_t>
    @DefProto DllImport, _wcstod_l, c,, <:ptr wchar_t, :ptr ptr wchar_t, :_locale_t>
    @DefProto DllImport, wcstol, c,, <:ptr wchar_t, :ptr ptr wchar_t, :SDWORD>
    @DefProto DllImport, _wcstol_l, c,, <:ptr wchar_t, :ptr ptr wchar_t, :SDWORD, :_locale_t>
    @DefProto DllImport, wcstoul, c,, <:ptr wchar_t, :ptr ptr wchar_t, :SDWORD>
    @DefProto DllImport, _wcstoul_l, c,, <:ptr wchar_t, :ptr ptr wchar_t, :SDWORD, :_locale_t>
    ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
      @DefProto DllImport, _wgetenv, c,, <:ptr wchar_t>
      @DefProto DllImport, _wgetenv_s, c,, <:ptr size_t, :ptr wchar_t, :size_t, :ptr wchar_t>
      if Defined(_DEBUG) and Defined(_CRTDBG_MAP_ALLOC)
      endif
      @DefProto DllImport, _wdupenv_s, c,, <:ptr ptr wchar_t, :ptr size_t, :ptr wchar_t>
      if Defined(_DEBUG) and Defined(_CRTDBG_MAP_ALLOC)
      endif
      ifndef _CRT_WSYSTEM_DEFINED
        _CRT_WSYSTEM_DEFINED equ <>
        @DefProto DllImport, _wsystem, c,, <:ptr wchar_t>
      endif
    endif
    @DefProto DllImport, _wtof, c,, <:ptr wchar_t>
    @DefProto DllImport, _wtof_l, c,, <:ptr wchar_t, :_locale_t>
    @DefProto DllImport, _wtoi, c,, <:ptr wchar_t>
    @DefProto DllImport, _wtoi_l, c,, <:ptr wchar_t, :_locale_t>
    @DefProto DllImport, _wtol, c,, <:ptr wchar_t>
    @DefProto DllImport, _wtol_l, c,, <:ptr wchar_t, :_locale_t>
    @DefProto DllImport, _i64tow_s, c,, <:SQWORD, :ptr wchar_t, :size_t, :SDWORD>
    @DefProto DllImport, _i64tow, c,, <:SQWORD, :ptr wchar_t, :SDWORD>
    @DefProto DllImport, _ui64tow_s, c,, <:QWORD, :ptr wchar_t, :size_t, :SDWORD>
    @DefProto DllImport, _ui64tow, c,, <:QWORD, :ptr wchar_t, :SDWORD>
    @DefProto DllImport, _wtoi64, c,, <:ptr wchar_t>
    @DefProto DllImport, _wtoi64_l, c,, <:ptr wchar_t, :_locale_t>
    @DefProto DllImport, _wcstoi64, c,, <:ptr wchar_t, :ptr ptr wchar_t, :SDWORD>
    @DefProto DllImport, _wcstoi64_l, c,, <:ptr wchar_t, :ptr ptr wchar_t, :SDWORD, :_locale_t>
    @DefProto DllImport, _wcstoui64, c,, <:ptr wchar_t, :ptr ptr wchar_t, :SDWORD>
    @DefProto DllImport, _wcstoui64_l, c,, <:ptr wchar_t, :ptr ptr wchar_t, :SDWORD, :_locale_t>
    _WSTDLIB_DEFINED equ <>
  endif
  ifndef _POSIX_
    _CVTBUFSIZE equ (309 + 40)
    if Defined(_DEBUG) and Defined(_CRTDBG_MAP_ALLOC)
    endif
    @DefProto DllImport, _fullpath, c,, <:ptr SBYTE, :ptr SBYTE, :size_t>
    if Defined(_DEBUG) and Defined(_CRTDBG_MAP_ALLOC)
    endif
    @DefProto DllImport, _ecvt_s, c,, <:ptr SBYTE, :size_t, :REAL8, :SDWORD, :ptr SDWORD, :ptr SDWORD>
    @DefProto DllImport, _ecvt, c,, <:REAL8, :SDWORD, :ptr SDWORD, :ptr SDWORD>
    @DefProto DllImport, _fcvt_s, c,, <:ptr SBYTE, :size_t, :REAL8, :SDWORD, :ptr SDWORD, :ptr SDWORD>
    @DefProto DllImport, _fcvt, c,, <:REAL8, :SDWORD, :ptr SDWORD, :ptr SDWORD>
    @DefProto DllImport, _gcvt_s, c,, <:ptr SBYTE, :size_t, :REAL8, :SDWORD>
    _gcvt proto c :REAL8, :SDWORD, :ptr SBYTE
    @DefProto DllImport, _atodbl, c,, <:ptr _CRT_DOUBLE, :ptr SBYTE>
    @DefProto DllImport, _atoldbl, c,, <:ptr _LDOUBLE, :ptr SBYTE>
    @DefProto DllImport, _atoflt, c,, <:ptr _CRT_FLOAT, :ptr SBYTE>
    @DefProto DllImport, _atodbl_l, c,, <:ptr _CRT_DOUBLE, :ptr SBYTE, :_locale_t>
    @DefProto DllImport, _atoldbl_l, c,, <:ptr _LDOUBLE, :ptr SBYTE, :_locale_t>
    @DefProto DllImport, _atoflt_l, c,, <:ptr _CRT_FLOAT, :ptr SBYTE, :_locale_t>
    _lrotl proto c :DWORD, :SDWORD
    _lrotr proto c :DWORD, :SDWORD
    @DefProto DllImport, _makepath_s, c,, <:ptr SBYTE, :size_t, :ptr SBYTE, :ptr SBYTE, :ptr SBYTE, :ptr SBYTE>
    if Defined(_M_CEE)
      ;[...]
    endif
    if Defined(_M_CEE_PURE)
      ;[...]
    else
      _onexit proto c :_onexit_t
    endif
    ifndef _CRT_PERROR_DEFINED
      _CRT_PERROR_DEFINED equ <>
      @DefProto DllImport, perror, c,, <:ptr SBYTE>
    endif
    ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
      @DefProto DllImport, _putenv, c,, <:ptr SBYTE>
      @DefProto DllImport, _putenv_s, c,, <:ptr SBYTE, :ptr SBYTE>
    endif
;    _rotl proto c :DWORD, :SDWORD
;    _rotl64 proto c :QWORD, :SDWORD
;    _rotr proto c :DWORD, :SDWORD
;    _rotr64 proto c :QWORD, :SDWORD
    ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
      @DefProto DllImport, _searchenv_s, c,, <:ptr SBYTE, :ptr SBYTE, :ptr SBYTE, :size_t>
    endif
    _splitpath proto c :ptr SBYTE, :ptr SBYTE, :ptr SBYTE, :ptr SBYTE, :ptr SBYTE
    @DefProto DllImport, _splitpath_s, c,, <:ptr SBYTE, :ptr SBYTE, :size_t, :ptr SBYTE, :size_t, :ptr SBYTE, :size_t, :ptr SBYTE, :size_t>
    _swab proto c :ptr SBYTE, :ptr SBYTE, :SDWORD
    ifndef _WSTDLIBP_DEFINED
      if Defined(_DEBUG) and Defined(_CRTDBG_MAP_ALLOC)
      endif
      @DefProto DllImport, _wfullpath, c,, <:ptr wchar_t, :ptr wchar_t, :size_t>
      if Defined(_DEBUG) and Defined(_CRTDBG_MAP_ALLOC)
      endif
      @DefProto DllImport, _wmakepath_s, c,, <:ptr wchar_t, :size_t, :ptr wchar_t, :ptr wchar_t, :ptr wchar_t, :ptr wchar_t>
      ifndef _CRT_WPERROR_DEFINED
        _CRT_WPERROR_DEFINED equ <>
        _wperror proto c :ptr wchar_t
      endif
      ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
        @DefProto DllImport, _wputenv, c,, <:ptr wchar_t>
        @DefProto DllImport, _wputenv_s, c,, <:ptr wchar_t, :ptr wchar_t>
        @DefProto DllImport, _wsearchenv_s, c,, <:ptr wchar_t, :ptr wchar_t, :ptr wchar_t, :size_t>
      endif
      _wsplitpath proto c :ptr wchar_t, :ptr wchar_t, :ptr wchar_t, :ptr wchar_t, :ptr wchar_t
      @DefProto DllImport, _wsplitpath_s, c,, <:ptr wchar_t, :ptr wchar_t, :size_t, :ptr wchar_t, :size_t, :ptr wchar_t, :size_t, :ptr wchar_t, :size_t>
      _WSTDLIBP_DEFINED equ <>
    endif
    ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
      _seterrormode proto c :SDWORD
      @DefProto DllImport, _beep, c,, <:DWORD, :DWORD>
      @DefProto DllImport, _sleep, c,, <:DWORD>
    endif
  endif
  if  not __STDC__
    ifndef _POSIX_
      ifndef __cplusplus
        max macro a, b
          exitm <(((a) > (b)) ? (a) : (b))>
        endm
        min macro a, b
          exitm <(((a) < (b)) ? (a) : (b))>
        endm
      endif
      sys_errlist equ <_sys_errlist>
      sys_nerr equ <_sys_nerr>
      ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
        environ equ <_environ>
      endif
      @DefProto DllImport, ecvt, c,, <:REAL8, :SDWORD, :ptr SDWORD, :ptr SDWORD>
      @DefProto DllImport, fcvt, c,, <:REAL8, :SDWORD, :ptr SDWORD, :ptr SDWORD>
      @DefProto DllImport, gcvt, c,, <:REAL8, :SDWORD, :ptr SBYTE>
      @DefProto DllImport, itoa, c,, <:SDWORD, :ptr SBYTE, :SDWORD>
      @DefProto DllImport, ltoa, c,, <:SDWORD, :ptr SBYTE, :SDWORD>
      ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
        @DefProto DllImport, putenv, c,, <:ptr SBYTE>
      endif
      @DefProto DllImport, swab, c,, <:ptr SBYTE, :ptr SBYTE, :SDWORD>
      @DefProto DllImport, ultoa, c,, <:DWORD, :ptr SBYTE, :SDWORD>
      onexit proto c :onexit_t
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
