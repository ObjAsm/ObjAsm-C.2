;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdipluscolormatrix.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 16/12/2023 11:07:10

;\**************************************************************************
ifndef _GDIPLUSCOLORMATRIX_H
  _GDIPLUSCOLORMATRIX_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if (GDIPVER ge 0110h)
      ;----------------------------------------------------------------------------
      ; Color channel look up table (LUT)
      ;----------------------------------------------------------------------------
      ColorChannelLUT struct
        BYTE 256 dup (?)
      ColorChannelLUT ends
      ;----------------------------------------------------------------------------
      ; Per-channel Histogram for 8bpp images.
      ;----------------------------------------------------------------------------
      HistogramFormat typedef SDWORD
      HistogramFormatARGB equ 0
      HistogramFormatPARGB equ 1
      HistogramFormatRGB equ 2
      HistogramFormatGray equ 3
      HistogramFormatB equ 4
      HistogramFormatG equ 5
      HistogramFormatR equ 6
      HistogramFormatA equ 7

    endif
    ;(GDIPVER >= 0x0110)
    ;----------------------------------------------------------------------------
    ; Color matrix
    ;----------------------------------------------------------------------------
    ColorMatrix struct
      m REAL 5 * 5 dup (?)
    ColorMatrix ends
    ;----------------------------------------------------------------------------
    ; Color Matrix flags
    ;----------------------------------------------------------------------------
    ColorMatrixFlags typedef SDWORD
    ColorMatrixFlagsDefault equ 0
    ColorMatrixFlagsSkipGrays equ 1
    ColorMatrixFlagsAltGray equ 2

    ;----------------------------------------------------------------------------
    ; Color Adjust Type
    ;----------------------------------------------------------------------------
    ColorAdjustType typedef SDWORD
    ColorAdjustTypeDefault equ 0
    ColorAdjustTypeBitmap equ 1
    ColorAdjustTypeBrush equ 2
    ColorAdjustTypePen equ 3
    ColorAdjustTypeText equ 4
    ColorAdjustTypeCount equ 5
    ColorAdjustTypeAny equ 6

    ; Reserved
    ;----------------------------------------------------------------------------
    ; Color Map
    ;----------------------------------------------------------------------------
    ColorMap struct
      oldColor Color ?
      newColor Color ?
    ColorMap ends
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
endif
