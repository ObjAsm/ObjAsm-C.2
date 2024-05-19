;Include file created by h2inc+ version C.2.0 on (UTC) 19/05/2024 07:52:23
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdipluscolormatrix.h\gdipluscolormatrix.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 16/12/2023 11:07:10

ifndef _GDIPLUSCOLORMATRIX_H
  _GDIPLUSCOLORMATRIX_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if (GDIPVER ge 0110h)
      ColorChannelLUT struct
        BYTE 256 dup (?)
      ColorChannelLUT ends
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
    ColorMatrix struct
      m REAL 5 * 5 dup (?)
    ColorMatrix ends
    ColorMatrixFlags typedef SDWORD
    ColorMatrixFlagsDefault equ 0
    ColorMatrixFlagsSkipGrays equ 1
    ColorMatrixFlagsAltGray equ 2

    ColorAdjustType typedef SDWORD
    ColorAdjustTypeDefault equ 0
    ColorAdjustTypeBitmap equ 1
    ColorAdjustTypeBrush equ 2
    ColorAdjustTypePen equ 3
    ColorAdjustTypeText equ 4
    ColorAdjustTypeCount equ 5
    ColorAdjustTypeAny equ 6

    ColorMap struct
      oldColor Color ?
      newColor Color ?
    ColorMap ends
  endif
endif
