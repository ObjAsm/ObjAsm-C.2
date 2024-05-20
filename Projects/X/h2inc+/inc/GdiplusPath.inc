;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdipluspath.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 12/02/2024 17:06:00

;\**************************************************************************
ifndef _GDIPLUSPATH_H
  _GDIPLUSPATH_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if _MSC_VER ge 1200
      if _MSC_VER ge 1400
        ;* signed/unsigned mismatch *
      endif
      ;* padding added after data member *
    endif
    ; Reset the path object to empty (and fill mode to FillModeAlternate)
    ; World units
    ; World units
    ; World units
    ; World units
    ; This is not always the tightest bounds.
    ; Once flattened, the resultant path is made of line segments and
    ; the original path information is lost.  When matrix is NULL the
    ; identity matrix is assumed.
    ; Once this is called, the resultant path is made of line segments and
    ; the original path information is lost.  When matrix is NULL, the 
    ; identity matrix is assumed.
    ;--------------------------------------------------------------------------
    ; GraphisPathIterator class
    ;--------------------------------------------------------------------------
    ; Uses SetStatus()/GetStatus() pattern rather than return codes so PREfast gets confused
    ;--------------------------------------------------------------------------
    ; Path Gradient Brush
    ;--------------------------------------------------------------------------
    ; Uses SetStatus()/GetStatus() pattern rather than return codes so PREfast gets confused
    ; Tool bug, doesn't see that *numFound > numSought
    if _MSC_VER ge 1200
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
endif
; !_GRAPHICSPATH_HPP
