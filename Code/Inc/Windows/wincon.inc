;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\wincon.h
;             Created on (UTC) 06/04/2024 06:16:02
;             Last modified on (UTC) 21/02/2024 18:13:22

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
