;Include file created by h2inc+ version C.2.0 on (UTC) 19/05/2024 07:52:23
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdipluspixelformats.h\gdipluspixelformats.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 16/12/2023 11:07:10

ifndef _GDIPLUSPIXELFORMATS_H
  _GDIPLUSPIXELFORMATS_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if _MSC_VER ge 1200
      if _MSC_VER ge 1400
      endif
    endif
    ARGB typedef DWORD
    ARGB64 typedef DWORDLONG
    ALPHA_SHIFT equ 24
    RED_SHIFT equ 16
    GREEN_SHIFT equ 8
    BLUE_SHIFT equ 0
    ALPHA_MASK equ ((ARGB) 0ffh shl ALPHA_SHIFT)
    PixelFormat typedef INT_
    PixelFormatIndexed equ 00010000h
    PixelFormatGDI equ 00020000h
    PixelFormatAlpha equ 00040000h
    PixelFormatPAlpha equ 00080000h
    PixelFormatExtended equ 00100000h
    PixelFormatCanonical equ 00200000h
    PixelFormatUndefined equ 0
    PixelFormatDontCare equ 0
    PixelFormat1bppIndexed equ (1 or (1 shl 8) or PixelFormatIndexed or PixelFormatGDI)
    PixelFormat4bppIndexed equ (2 or (4 shl 8) or PixelFormatIndexed or PixelFormatGDI)
    PixelFormat8bppIndexed equ (3 or (8 shl 8) or PixelFormatIndexed or PixelFormatGDI)
    PixelFormat16bppGrayScale equ (4 or (16 shl 8) or PixelFormatExtended)
    PixelFormat16bppRGB555 equ (5 or (16 shl 8) or PixelFormatGDI)
    PixelFormat16bppRGB565 equ (6 or (16 shl 8) or PixelFormatGDI)
    PixelFormat16bppARGB1555 equ (7 or (16 shl 8) or PixelFormatAlpha or PixelFormatGDI)
    PixelFormat24bppRGB equ (8 or (24 shl 8) or PixelFormatGDI)
    PixelFormat32bppRGB equ (9 or (32 shl 8) or PixelFormatGDI)
    PixelFormat32bppARGB equ (10 or (32 shl 8) or PixelFormatAlpha or PixelFormatGDI or PixelFormatCanonical)
    PixelFormat32bppPARGB equ (11 or (32 shl 8) or PixelFormatAlpha or PixelFormatPAlpha or PixelFormatGDI)
    PixelFormat48bppRGB equ (12 or (48 shl 8) or PixelFormatExtended)
    PixelFormat64bppARGB equ (13 or (64 shl 8) or PixelFormatAlpha or PixelFormatCanonical or PixelFormatExtended)
    PixelFormat64bppPARGB equ (14 or (64 shl 8) or PixelFormatAlpha or PixelFormatPAlpha or PixelFormatExtended)
    PixelFormat32bppCMYK equ (15 or (32 shl 8))
    PixelFormatMax equ 16
    GetPixelFormatSize proto WIN_STD_CALL_CONV :PixelFormat
    IsIndexedPixelFormat proto WIN_STD_CALL_CONV :PixelFormat
    IsAlphaPixelFormat proto WIN_STD_CALL_CONV :PixelFormat
    IsExtendedPixelFormat proto WIN_STD_CALL_CONV :PixelFormat
    IsCanonicalPixelFormat proto WIN_STD_CALL_CONV :PixelFormat
    if (GDIPVER ge 0110h)
      PaletteType typedef SDWORD
      PaletteTypeCustom equ 0
      PaletteTypeOptimal equ 1
      PaletteTypeFixedBW equ 2
      PaletteTypeFixedHalftone8 equ 3
      PaletteTypeFixedHalftone27 equ 4
      PaletteTypeFixedHalftone64 equ 5
      PaletteTypeFixedHalftone125 equ 6
      PaletteTypeFixedHalftone216 equ 7
      PaletteTypeFixedHalftone252 equ 8
      PaletteTypeFixedHalftone256 equ 9

      DitherType typedef SDWORD
      DitherTypeNone equ 0
      DitherTypeSolid equ 1
      DitherTypeOrdered4x4 equ 2
      DitherTypeOrdered8x8 equ 3
      DitherTypeOrdered16x16 equ 4
      DitherTypeSpiral4x4 equ 5
      DitherTypeSpiral8x8 equ 6
      DitherTypeDualSpiral4x4 equ 7
      DitherTypeDualSpiral8x8 equ 8
      DitherTypeErrorDiffusion equ 9
      DitherTypeMax equ 10

    endif
    PaletteFlags typedef SDWORD
    PaletteFlagsHasAlpha equ 0001h
    PaletteFlagsGrayScale equ 0002h
    PaletteFlagsHalftone equ 0004h

    ColorPalette struct
      Flags UINT ?
      Count UINT ?
      Entries ARGB 1 dup (?)
    ColorPalette ends
    if _MSC_VER ge 1200
    endif
  endif
endif
