;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\wincon.h
;             Created on (UTC) 06/04/2024 06:16:02
;             Last modified on (UTC) 21/02/2024 18:13:22

include winapifamily.inc
;*++ BUILD Version: 0002    // Increment this if a change has global effects
;Copyright (c) Microsoft Corporation. All rights reserved.
;Module Name:
;wincon.h
;Abstract:
;This module contains the public data structures, data types,
;and procedures exported by the NT console subsystem.
;Created:
;26-Oct-1990
;Revision History:
;--*
ifndef _WINCON_
  _WINCON_ equ <>
  ifdef __cplusplus
    ;[...]
  endif
  if _MSC_VER ge 1200
    ; padding added after data member
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
    ;* _WIN32_WINNT >= 0x0500 *
  endif
  if _MSC_VER ge 1200
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
; _WINCON_
