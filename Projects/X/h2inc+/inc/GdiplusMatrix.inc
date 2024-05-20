;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdiplusmatrix.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 12/02/2024 17:06:00

;\**************************************************************************
include winapifamily.inc
if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
  if _MSC_VER ge 1200
    ;* padding added after data member *
  endif
  ; Default constructor is set to identity matrix.
  ; set identity matrix elements 
  ; float version
  if _MSC_VER ge 1200
  endif
  ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
endif
