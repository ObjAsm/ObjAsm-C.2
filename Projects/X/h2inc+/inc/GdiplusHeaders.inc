;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdiplusheaders.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 12/02/2024 17:06:00

ifndef _GDIPLUSHEADERS_H
  _GDIPLUSHEADERS_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if _MSC_VER ge 1200
    endif
    if (GDIPVER ge 0110h)
    endif
    if (GDIPVER ge 0110h)
    endif
    if (GDIPVER ge 0110h)
    endif
    if _MSC_VER ge 1200
    endif
  endif
endif