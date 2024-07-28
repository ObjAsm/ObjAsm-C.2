;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\string.h', last modified: 01/10/2012 08:50
;Creation parameters: 

ifndef _INC_STRING
  _INC_STRING equ <>
  include crtdefs.inc
  ifdef __cplusplus
    ;[...]
  endif
  ifndef _NLSCMP_DEFINED
    _NLSCMPERROR equ 2147483647
    _NLSCMP_DEFINED equ <>
  endif
  ifndef NULL
    ifdef __cplusplus
      ;[...]
    else
      NULL equ (0)
    endif
  endif
  _WConst_return equ <_CONST_RETURN>
  ifndef _CRT_MEMORY_DEFINED
    _CRT_MEMORY_DEFINED equ <>
    @DefProto DllImport, _memccpy, c,, <:ptr, :ptr, :SDWORD, :size_t>
    @DefProto DllImport, memchr, c,, <:ptr, :SDWORD, :size_t>
    @DefProto DllImport, _memicmp, c,, <:ptr, :ptr, :size_t>
    @DefProto DllImport, _memicmp_l, c,, <:ptr, :ptr, :size_t, :_locale_t>
    memcmp proto c :ptr, :ptr, :size_t
    memcpy proto c :ptr, :ptr, :size_t
    if __STDC_WANT_SECURE_LIB__
      @DefProto DllImport, memcpy_s, c,, <:ptr, :rsize_t, :ptr, :rsize_t>
      if Defined(__cplusplus) and _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_MEMORY
        ;[...]
      endif
      if Defined(__cplusplus) and _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES_MEMORY
        ;[...]
      endif
    endif
    memset proto c :ptr, :SDWORD, :size_t
    if  not __STDC__
      @DefProto DllImport, memccpy, c,, <:ptr, :ptr, :SDWORD, :size_t>
      @DefProto DllImport, memicmp, c,, <:ptr, :ptr, :size_t>
    endif
  endif
  @DefProto DllImport, _strset_s, c,, <:ptr SBYTE, :size_t, :SDWORD>
  if __STDC_WANT_SECURE_LIB__
    @DefProto DllImport, strcpy_s, c,, <:ptr SBYTE, :rsize_t, :ptr SBYTE>
  endif
  if __STDC_WANT_SECURE_LIB__
    @DefProto DllImport, strcat_s, c,, <:ptr SBYTE, :rsize_t, :ptr SBYTE>
  endif
  strcmp proto c :ptr SBYTE, :ptr SBYTE
  strlen proto c :ptr SBYTE
  @DefProto DllImport, strnlen, c,, <:ptr SBYTE, :size_t>
  if __STDC_WANT_SECURE_LIB__ and  not Defined(__midl)
    strnlen_s proto c :ptr SBYTE, :size_t
  endif
  if __STDC_WANT_SECURE_LIB__
    @DefProto DllImport, memmove_s, c,, <:ptr, :rsize_t, :ptr, :rsize_t>
  endif
  @DefProto DllImport, memmove, c,, <:ptr, :ptr, :size_t>
  if Defined(_DEBUG) and Defined(_CRTDBG_MAP_ALLOC)
  endif
  @DefProto DllImport, _strdup, c,, <:ptr SBYTE>
  if Defined(_DEBUG) and Defined(_CRTDBG_MAP_ALLOC)
  endif
  @DefProto DllImport, strchr, c,, <:ptr SBYTE, :SDWORD>
  @DefProto DllImport, _stricmp, c,, <:ptr SBYTE, :ptr SBYTE>
  @DefProto DllImport, _strcmpi, c,, <:ptr SBYTE, :ptr SBYTE>
  @DefProto DllImport, _stricmp_l, c,, <:ptr SBYTE, :ptr SBYTE, :_locale_t>
  @DefProto DllImport, strcoll, c,, <:ptr SBYTE, :ptr SBYTE>
  @DefProto DllImport, _strcoll_l, c,, <:ptr SBYTE, :ptr SBYTE, :_locale_t>
  @DefProto DllImport, _stricoll, c,, <:ptr SBYTE, :ptr SBYTE>
  @DefProto DllImport, _stricoll_l, c,, <:ptr SBYTE, :ptr SBYTE, :_locale_t>
  @DefProto DllImport, _strncoll, c,, <:ptr SBYTE, :ptr SBYTE, :size_t>
  @DefProto DllImport, _strncoll_l, c,, <:ptr SBYTE, :ptr SBYTE, :size_t, :_locale_t>
  @DefProto DllImport, _strnicoll, c,, <:ptr SBYTE, :ptr SBYTE, :size_t>
  @DefProto DllImport, _strnicoll_l, c,, <:ptr SBYTE, :ptr SBYTE, :size_t, :_locale_t>
  @DefProto DllImport, strcspn, c,, <:ptr SBYTE, :ptr SBYTE>
  @DefProto DllImport, _strerror, c,, <:ptr SBYTE>
  @DefProto DllImport, _strerror_s, c,, <:ptr SBYTE, :size_t, :ptr SBYTE>
  @DefProto DllImport, strerror, c,, <:SDWORD>
  if __STDC_WANT_SECURE_LIB__
    @DefProto DllImport, strerror_s, c,, <:ptr SBYTE, :size_t, :SDWORD>
  endif
  @DefProto DllImport, _strlwr_s, c,, <:ptr SBYTE, :size_t>
  @DefProto DllImport, _strlwr_s_l, c,, <:ptr SBYTE, :size_t, :_locale_t>
  if __STDC_WANT_SECURE_LIB__
    @DefProto DllImport, strncat_s, c,, <:ptr SBYTE, :rsize_t, :ptr SBYTE, :rsize_t>
  endif
  @DefProto DllImport, strncmp, c,, <:ptr SBYTE, :ptr SBYTE, :size_t>
  @DefProto DllImport, _strnicmp, c,, <:ptr SBYTE, :ptr SBYTE, :size_t>
  @DefProto DllImport, _strnicmp_l, c,, <:ptr SBYTE, :ptr SBYTE, :size_t, :_locale_t>
  if __STDC_WANT_SECURE_LIB__
    @DefProto DllImport, strncpy_s, c,, <:ptr SBYTE, :rsize_t, :ptr SBYTE, :rsize_t>
  endif
  @DefProto DllImport, _strnset_s, c,, <:ptr SBYTE, :size_t, :SDWORD, :size_t>
  @DefProto DllImport, strpbrk, c,, <:ptr SBYTE, :ptr SBYTE>
  @DefProto DllImport, strrchr, c,, <:ptr SBYTE, :SDWORD>
  @DefProto DllImport, _strrev, c,, <:ptr SBYTE>
  @DefProto DllImport, strspn, c,, <:ptr SBYTE, :ptr SBYTE>
  @DefProto DllImport, strstr, c,, <:ptr SBYTE, :ptr SBYTE>
  @DefProto DllImport, strtok, c,, <:ptr SBYTE, :ptr SBYTE>
  if __STDC_WANT_SECURE_LIB__
    @DefProto DllImport, strtok_s, c,, <:ptr SBYTE, :ptr SBYTE, :ptr ptr SBYTE>
  endif
  @DefProto DllImport, _strupr_s, c,, <:ptr SBYTE, :size_t>
  @DefProto DllImport, _strupr_s_l, c,, <:ptr SBYTE, :size_t, :_locale_t>
  @DefProto DllImport, strxfrm, c,, <:ptr SBYTE, :ptr SBYTE, :size_t>
  @DefProto DllImport, _strxfrm_l, c,, <:ptr SBYTE, :ptr SBYTE, :size_t, :_locale_t>
  ifdef __cplusplus
    ;[...]
  endif
  if  not __STDC__
    if Defined(_DEBUG) and Defined(_CRTDBG_MAP_ALLOC)
    endif
    @DefProto DllImport, strdup, c,, <:ptr SBYTE>
    if Defined(_DEBUG) and Defined(_CRTDBG_MAP_ALLOC)
    endif
    @DefProto DllImport, strcmpi, c,, <:ptr SBYTE, :ptr SBYTE>
    @DefProto DllImport, stricmp, c,, <:ptr SBYTE, :ptr SBYTE>
    @DefProto DllImport, strlwr, c,, <:ptr SBYTE>
    @DefProto DllImport, strnicmp, c,, <:ptr SBYTE, :ptr SBYTE, :size_t>
    @DefProto DllImport, strnset, c,, <:ptr SBYTE, :SDWORD, :size_t>
    @DefProto DllImport, strrev, c,, <:ptr SBYTE>
    strset proto c :ptr SBYTE, :SDWORD
    @DefProto DllImport, strupr, c,, <:ptr SBYTE>
  endif
  ifndef _WSTRING_DEFINED
    if Defined(_DEBUG) and Defined(_CRTDBG_MAP_ALLOC)
    endif
    @DefProto DllImport, _wcsdup, c,, <:ptr wchar_t>
    if Defined(_DEBUG) and Defined(_CRTDBG_MAP_ALLOC)
    endif
    if __STDC_WANT_SECURE_LIB__
      @DefProto DllImport, wcscat_s, c,, <:ptr wchar_t, :rsize_t, :ptr wchar_t>
    endif
    @DefProto DllImport, wcschr, c,, <:ptr wchar_t, :wchar_t>
    @DefProto DllImport, wcscmp, c,, <:ptr wchar_t, :ptr wchar_t>
    if __STDC_WANT_SECURE_LIB__
      @DefProto DllImport, wcscpy_s, c,, <:ptr wchar_t, :rsize_t, :ptr wchar_t>
    endif
    @DefProto DllImport, wcscspn, c,, <:ptr wchar_t, :ptr wchar_t>
    @DefProto DllImport, wcslen, c,, <:ptr wchar_t>
    @DefProto DllImport, wcsnlen, c,, <:ptr wchar_t, :size_t>
    if __STDC_WANT_SECURE_LIB__ and  not Defined(__midl)
      wcsnlen_s proto c :ptr wchar_t, :size_t
    endif
    if __STDC_WANT_SECURE_LIB__
      @DefProto DllImport, wcsncat_s, c,, <:ptr wchar_t, :rsize_t, :ptr wchar_t, :rsize_t>
    endif
    @DefProto DllImport, wcsncmp, c,, <:ptr wchar_t, :ptr wchar_t, :size_t>
    if __STDC_WANT_SECURE_LIB__
      @DefProto DllImport, wcsncpy_s, c,, <:ptr wchar_t, :rsize_t, :ptr wchar_t, :rsize_t>
    endif
    @DefProto DllImport, wcspbrk, c,, <:ptr wchar_t, :ptr wchar_t>
    @DefProto DllImport, wcsrchr, c,, <:ptr wchar_t, :wchar_t>
    @DefProto DllImport, wcsspn, c,, <:ptr wchar_t, :ptr wchar_t>
    @DefProto DllImport, wcsstr, c,, <:ptr wchar_t, :ptr wchar_t>
    @DefProto DllImport, wcstok, c,, <:ptr wchar_t, :ptr wchar_t>
    if __STDC_WANT_SECURE_LIB__
      @DefProto DllImport, wcstok_s, c,, <:ptr wchar_t, :ptr wchar_t, :ptr ptr wchar_t>
    endif
    @DefProto DllImport, _wcserror, c,, <:SDWORD>
    @DefProto DllImport, _wcserror_s, c,, <:ptr wchar_t, :size_t, :SDWORD>
    @DefProto DllImport, __wcserror, c,, <:ptr wchar_t>
    @DefProto DllImport, __wcserror_s, c,, <:ptr wchar_t, :size_t, :ptr wchar_t>
    @DefProto DllImport, _wcsicmp, c,, <:ptr wchar_t, :ptr wchar_t>
    @DefProto DllImport, _wcsicmp_l, c,, <:ptr wchar_t, :ptr wchar_t, :_locale_t>
    @DefProto DllImport, _wcsnicmp, c,, <:ptr wchar_t, :ptr wchar_t, :size_t>
    @DefProto DllImport, _wcsnicmp_l, c,, <:ptr wchar_t, :ptr wchar_t, :size_t, :_locale_t>
    @DefProto DllImport, _wcsnset_s, c,, <:ptr wchar_t, :size_t, :wchar_t, :size_t>
    _wcsrev proto c :ptr wchar_t
    @DefProto DllImport, _wcsset_s, c,, <:ptr wchar_t, :size_t, :wchar_t>
    @DefProto DllImport, _wcslwr_s, c,, <:ptr wchar_t, :size_t>
    @DefProto DllImport, _wcslwr_s_l, c,, <:ptr wchar_t, :size_t, :_locale_t>
    @DefProto DllImport, _wcsupr_s, c,, <:ptr wchar_t, :size_t>
    @DefProto DllImport, _wcsupr_s_l, c,, <:ptr wchar_t, :size_t, :_locale_t>
    @DefProto DllImport, wcsxfrm, c,, <:ptr wchar_t, :ptr wchar_t, :size_t>
    @DefProto DllImport, _wcsxfrm_l, c,, <:ptr wchar_t, :ptr wchar_t, :size_t, :_locale_t>
    @DefProto DllImport, wcscoll, c,, <:ptr wchar_t, :ptr wchar_t>
    @DefProto DllImport, _wcscoll_l, c,, <:ptr wchar_t, :ptr wchar_t, :_locale_t>
    @DefProto DllImport, _wcsicoll, c,, <:ptr wchar_t, :ptr wchar_t>
    @DefProto DllImport, _wcsicoll_l, c,, <:ptr wchar_t, :ptr wchar_t, :_locale_t>
    @DefProto DllImport, _wcsncoll, c,, <:ptr wchar_t, :ptr wchar_t, :size_t>
    @DefProto DllImport, _wcsncoll_l, c,, <:ptr wchar_t, :ptr wchar_t, :size_t, :_locale_t>
    @DefProto DllImport, _wcsnicoll, c,, <:ptr wchar_t, :ptr wchar_t, :size_t>
    @DefProto DllImport, _wcsnicoll_l, c,, <:ptr wchar_t, :ptr wchar_t, :size_t, :_locale_t>
    ifdef __cplusplus
      ;[...]
    endif
    if  not __STDC__
      if Defined(_DEBUG) and Defined(_CRTDBG_MAP_ALLOC)
      endif
      @DefProto DllImport, wcsdup, c,, <:ptr wchar_t>
      if Defined(_DEBUG) and Defined(_CRTDBG_MAP_ALLOC)
      endif
      wcswcs equ <wcsstr>
      @DefProto DllImport, wcsicmp, c,, <:ptr wchar_t, :ptr wchar_t>
      @DefProto DllImport, wcsnicmp, c,, <:ptr wchar_t, :ptr wchar_t, :size_t>
      @DefProto DllImport, wcsnset, c,, <:ptr wchar_t, :wchar_t, :size_t>
      @DefProto DllImport, wcsrev, c,, <:ptr wchar_t>
      @DefProto DllImport, wcsset, c,, <:ptr wchar_t, :wchar_t>
      @DefProto DllImport, wcslwr, c,, <:ptr wchar_t>
      @DefProto DllImport, wcsupr, c,, <:ptr wchar_t>
      @DefProto DllImport, wcsicoll, c,, <:ptr wchar_t, :ptr wchar_t>
    endif
    _WSTRING_DEFINED equ <>
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

