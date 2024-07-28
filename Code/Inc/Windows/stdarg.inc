;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\stdarg.h', last modified: 01/10/2012 08:50
;Creation parameters: 

ifndef _INC_STDARG
  _INC_STDARG equ <>
  if  not Defined(_WIN32)
    ;[...]
  endif
  include vadefs.inc
  va_start equ <_crt_va_start>
  va_arg equ <_crt_va_arg>
  va_end equ <_crt_va_end>
endif

