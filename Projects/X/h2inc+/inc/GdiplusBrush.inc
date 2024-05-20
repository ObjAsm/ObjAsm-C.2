;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdiplusbrush.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 12/02/2024 17:06:00

;\**************************************************************************
ifndef _GDIPLUSBRUSH_H
  _GDIPLUSBRUSH_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if _MSC_VER ge 1200
      ;* padding added after data member *
    endif
    ;--------------------------------------------------------------------------
    ; Abstract base class for various brush types
    ;--------------------------------------------------------------------------
    ;--------------------------------------------------------------------------
    ; Solid Fill Brush Object
    ;--------------------------------------------------------------------------
    ;--------------------------------------------------------------------------
    ; Texture Brush Fill Object
    ;--------------------------------------------------------------------------
    ; When creating a texture brush from a metafile image, the dstRect
    ; is used to specify the size that the metafile image should be
    ; rendered at in the device units of the destination graphics.
    ; It is NOT used to crop the metafile image, so only the width 
    ; and height values matter for metafiles.
    ;--------------------------------------------------------------------------
    ; Linear Gradient Brush Object
    ;--------------------------------------------------------------------------
    ; use bitwise copy operator for Color copy
    ;--------------------------------------------------------------------------
    ; PathGradientBrush object is defined
    ; in gdipluspath.h.
    ;--------------------------------------------------------------------------
    ;--------------------------------------------------------------------------
    ; Hatch Brush Object
    ;--------------------------------------------------------------------------
    if _MSC_VER ge 1200
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
endif
