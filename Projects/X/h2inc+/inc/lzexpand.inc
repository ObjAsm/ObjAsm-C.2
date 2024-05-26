;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\lzexpand.h
;             Created on (UTC) 06/04/2024 06:15:56
;             Last modified on (UTC) 21/02/2024 18:17:06

ifndef _LZEXPAND_
  _LZEXPAND_ equ <>
  include winapifamily.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    LZERROR_BADINHANDLE equ (- 1)
    LZERROR_BADOUTHANDLE equ (- 2)
    LZERROR_READ equ (- 3)
    LZERROR_WRITE equ (- 4)
    LZERROR_GLOBALLOC equ (- 5)
    LZERROR_GLOBLOCK equ (- 6)
    LZERROR_BADVALUE equ (- 7)
    LZERROR_UNKNOWNALG equ (- 8)
    LZStart proto WIN_STD_CALL_CONV
    LZDone proto WIN_STD_CALL_CONV
    CopyLZFile proto WIN_STD_CALL_CONV :INT_, :INT_
    LZCopy proto WIN_STD_CALL_CONV :INT_, :INT_
    LZInit proto WIN_STD_CALL_CONV :INT_
    GetExpandedNameA proto WIN_STD_CALL_CONV :LPSTR, :LPSTR
    GetExpandedNameW proto WIN_STD_CALL_CONV :LPWSTR, :LPWSTR
    ifdef UNICODE
      GetExpandedName equ <GetExpandedNameW>
    else
      GetExpandedName equ <GetExpandedNameA>
    endif
    LZOpenFileA proto WIN_STD_CALL_CONV :LPSTR, :LPOFSTRUCT, :WORD
    LZOpenFileW proto WIN_STD_CALL_CONV :LPWSTR, :LPOFSTRUCT, :WORD
    ifdef UNICODE
      LZOpenFile equ <LZOpenFileW>
    else
      LZOpenFile equ <LZOpenFileA>
    endif
    LZSeek proto WIN_STD_CALL_CONV :INT_, :LONG, :INT_
    LZRead proto WIN_STD_CALL_CONV :INT_, :ptr CHAR, :INT_
    LZClose proto WIN_STD_CALL_CONV :INT_
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
