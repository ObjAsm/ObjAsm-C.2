;Include file created by h2incX, Version C.01.00, 30/03/2019 18:59
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'D:\ObjAsm\Projects\32\h2IncX\header\GdiplusPath.h', last modified: 22/10/2018 20:35
;Creation parameters: 

ifndef _GDIPLUSPATH_H
  _GDIPLUSPATH_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if _MSC_VER ge 1200
      if _MSC_VER ge 1400
      endif
    endif
;    GraphicsPath struct
;      ;public:
;       GdiplusBase <>
;    GraphicsPath ends
;    GraphicsPathIterator struct
;      ;public:
;       GdiplusBase <>
;    GraphicsPathIterator ends
;    PathGradientBrush struct
;      ;public:
;       Brush <>
;    PathGradientBrush ends
;    if _MSC_VER ge 1200
;    endif
  endif
endif
 