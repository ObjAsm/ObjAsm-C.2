;Include file created by h2inc+ version C.2.0 on (UTC) 19/05/2024 07:52:23
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdiplusgraphics.h\gdiplusgraphics.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 16/12/2023 11:07:10

ifndef _GDIPLUSGRAPHICS_H
  _GDIPLUSGRAPHICS_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if _MSC_VER ge 1200
      if _MSC_VER ge 1400
      endif
    endif
    if (GDIPVER ge 0110h)
    endif
    if (GDIPVER ge 0110h)
    endif
    if _MSC_VER ge 1200
    endif
  endif
endif
