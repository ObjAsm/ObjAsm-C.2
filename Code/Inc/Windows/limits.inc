;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\limits.h', last modified: 01/10/2012 08:50
;Creation parameters: 

include crtdefs.inc
ifndef _INC_LIMITS
  _INC_LIMITS equ <>
  CHAR_BIT equ 8
  SCHAR_MIN equ -128
  SCHAR_MAX equ 127
  UCHAR_MAX equ 0ffh
  ifndef _CHAR_UNSIGNED
    CHAR_MIN equ <SCHAR_MIN>
    CHAR_MAX equ <SCHAR_MAX>
  else
    CHAR_MIN equ 0
    CHAR_MAX equ <UCHAR_MAX>
  endif
  MB_LEN_MAX equ 5
  SHRT_MIN equ -32768
  SHRT_MAX equ 32767
  USHRT_MAX equ 0ffffh
  INT_MIN equ (- 2147483647 - 1)
  INT_MAX equ 2147483647
  UINT_MAX equ 0ffffffffh
  LONG_MIN equ (- 2147483647 - 1)
  LONG_MAX equ 2147483647
  ULONG_MAX equ 0ffffffffh
  LLONG_MAX equ 9223372036854775807
  LLONG_MIN equ (- 9223372036854775807 - 1)
  ULLONG_MAX equ 0ffffffffffffffffh
  _I8_MIN equ (- 127 - 1)
  _I8_MAX equ 127
  _UI8_MAX equ 0ffh
  _I16_MIN equ (- 32767 - 1)
  _I16_MAX equ 32767
  _UI16_MAX equ 0ffffh
  _I32_MIN equ (- 2147483647 - 1)
  _I32_MAX equ 2147483647
  _UI32_MAX equ 0ffffffffh
  _I64_MIN equ (- 9223372036854775807 - 1)
  _I64_MAX equ 9223372036854775807
  _UI64_MAX equ 0ffffffffffffffffh
  if _INTEGRAL_MAX_BITS ge 128
    _I128_MIN equ (- 170141183460469231731687303715884105727 - 1)
    _I128_MAX equ 170141183460469231731687303715884105727
    _UI128_MAX equ 0ffffffffffffffffffffffffffffffffh
  endif
  ifndef SIZE_MAX
    ifdef _WIN64
      SIZE_MAX equ <_UI64_MAX>
    else
      SIZE_MAX equ <UINT_MAX>
    endif
  endif
  if __STDC_WANT_SECURE_LIB__
    ifndef RSIZE_MAX
      RSIZE_MAX equ (SIZE_MAX shr 1)
    endif
  endif
  ifdef _POSIX_
    ;[...]
  endif
endif

