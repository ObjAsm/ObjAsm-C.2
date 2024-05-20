;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdipluspen.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 12/02/2024 17:06:00

;\**************************************************************************
ifndef _GDIPLUSPEN_H
  _GDIPLUSPEN_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if _MSC_VER ge 1200
      ;* enumerator in switch of enum is not explicitly handled by a case label *
      ;* padding added after data member *
    endif
    ;--------------------------------------------------------------------------
    ; Pen class
    ;--------------------------------------------------------------------------
    ; Set/get line caps: start, end, and dash
    ; Line cap and join APIs by using LineCap and LineJoin enums.
    if _MSC_VER ge 1200
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
endif
