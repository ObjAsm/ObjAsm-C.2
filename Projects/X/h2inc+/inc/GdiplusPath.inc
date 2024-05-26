;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdipluspath.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 12/02/2024 17:06:00

ifndef _GDIPLUSPATH_H
  _GDIPLUSPATH_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if _MSC_VER ge 1200
      if _MSC_VER ge 1400
      endif
    endif
    if _MSC_VER ge 1200
    endif
  endif
endif
