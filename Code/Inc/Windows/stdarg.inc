;Include file created by h2inc+ version C.2.0 on (UTC) 24/05/2024 08:47:46
;(C) G. Friedrich April 2024
;Source file: \objasm\projects\x\h2inc+\h\um_10.0.22621.0\stdarg.h
;             Created on (UTC) 22/05/2024 17:57:06
;             Last modified on (UTC) 12/02/2024 17:05:46

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

