;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdipluscachedbitmap.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 16/12/2023 11:07:10

;**************************************************************************
ifndef _GDIPLUSCACHEDBITMAP_H
  _GDIPLUSCACHEDBITMAP_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    CachedBitmap proto WIN_STD_CALL_CONV :ptr Bitmap, :ptr Graphics
    CachedBitmap proto WIN_STD_CALL_CONV
    GetLastStatus proto WIN_STD_CALL_CONV
    return proto WIN_STD_CALL_CONV :lastStatus
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
endif
