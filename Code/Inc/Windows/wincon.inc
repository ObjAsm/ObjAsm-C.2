;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\wincon.h', last modified: 19/04/2018 10:43
;Creation parameters: 

include winapifamily.inc
ifndef _WINCON_
  _WINCON_ equ <>
  ifdef __cplusplus
    ;[...]
  endif
  if _MSC_VER ge 1200
  endif
  include wincontypes.inc
  ifndef NOGDI
    include wingdi.inc
  endif
  ifndef NOAPISET
    include consoleapi.inc
    include consoleapi2.inc
    include consoleapi3.inc
  endif
  CONSOLE_REAL_OUTPUT_HANDLE equ ((- 2))
  CONSOLE_REAL_INPUT_HANDLE equ ((- 3))
  CONSOLE_TEXTMODE_BUFFER equ 1
  if (_WIN32_WINNT ge 0500h)
  endif
  if _MSC_VER ge 1200
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

