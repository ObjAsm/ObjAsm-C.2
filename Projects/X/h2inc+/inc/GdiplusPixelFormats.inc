;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdipluspixelformats.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 16/12/2023 11:07:10

;\**************************************************************************
ifndef _GDIPLUSPIXELFORMATS_H
  _GDIPLUSPIXELFORMATS_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if _MSC_VER ge 1200
      ;* nonstandard extension: single line comment *
      ;* member function does not override any base class virtual member function *
      ;* no override available for virtual member function from base 'class'; function is hidden *
      if _MSC_VER ge 1400
        ;* signed/unsigned mismatch *
      endif
    endif
    ARGB typedef DWORD
    ARGB64 typedef DWORDLONG
    ALPHA_SHIFT equ 24
    RED_SHIFT equ 16
    GREEN_SHIFT equ 8
    BLUE_SHIFT equ 0
    ALPHA_MASK equ ((ARGB) 0ffh shl ALPHA_SHIFT)
    ; In-memory pixel data formats:
    ; bits 0-7 = format index
    ; bits 8-15 = pixel size (in bits)
    ; bits 16-23 = flags
    ; bits 24-31 = reserved
    PixelFormat typedef INT_
    PixelFormatIndexed equ 00010000h; Indexes into a palette

    PixelFormatGDI equ 00020000h; Is a GDI-supported format

    PixelFormatAlpha equ 00040000h; Has an alpha component

    PixelFormatPAlpha equ 00080000h; Pre-multiplied alpha

    PixelFormatExtended equ 00100000h; Extended color 16 bits/channel

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
    ;--------------------------------------------------------------------------
    ; Determine if the Pixel Format is Canonical format:
    ;   PixelFormat32bppARGB
    ;   PixelFormat32bppPARGB
    ;   PixelFormat64bppARGB
    ;   PixelFormat64bppPARGB
    ;--------------------------------------------------------------------------
    IsCanonicalPixelFormat proto WIN_STD_CALL_CONV :PixelFormat
    if (GDIPVER ge 0110h)
      ;----------------------------------------------------------------------------
      ; Color format conversion parameters
      ;----------------------------------------------------------------------------
      PaletteType typedef SDWORD
      ; Arbitrary custom palette provided by caller.
      PaletteTypeCustom equ 0
      ; Optimal palette generated using a median-cut algorithm.
      PaletteTypeOptimal equ 1
      ; Black and white palette.
      PaletteTypeFixedBW equ 2
      ; Symmetric halftone palettes.
      ; Each of these halftone palettes will be a superset of the system palette.
      ; E.g. Halftone8 will have it's 8-color on-off primaries and the 16 system
      ; colors added. With duplicates removed, that leaves 16 colors.
      PaletteTypeFixedHalftone8 equ 3
      ; 8-color, on-off primaries
      PaletteTypeFixedHalftone27 equ 4
      ; 3 intensity levels of each color
      PaletteTypeFixedHalftone64 equ 5
      ; 4 intensity levels of each color
      PaletteTypeFixedHalftone125 equ 6
      ; 5 intensity levels of each color
      PaletteTypeFixedHalftone216 equ 7
      ; 6 intensity levels of each color
      ; Assymetric halftone palettes.
      ; These are somewhat less useful than the symmetric ones, but are 
      ; included for completeness. These do not include all of the system
      ; colors.
      PaletteTypeFixedHalftone252 equ 8
      ; 6-red, 7-green, 6-blue intensities
      PaletteTypeFixedHalftone256 equ 9
      ; 8-red, 8-green, 4-blue intensities

      DitherType typedef SDWORD
      DitherTypeNone equ 0
      ; Solid color - picks the nearest matching color with no attempt to 
      ; halftone or dither. May be used on an arbitrary palette.
      DitherTypeSolid equ 1
      ; Ordered dithers and spiral dithers must be used with a fixed palette.
      ; NOTE: DitherOrdered4x4 is unique in that it may apply to 16bpp 
      ; conversions also.
      DitherTypeOrdered4x4 equ 2
      DitherTypeOrdered8x8 equ 3
      DitherTypeOrdered16x16 equ 4
      DitherTypeSpiral4x4 equ 5
      DitherTypeSpiral8x8 equ 6
      DitherTypeDualSpiral4x4 equ 7
      DitherTypeDualSpiral8x8 equ 8
      ; Error diffusion. May be used with any palette.
      DitherTypeErrorDiffusion equ 9
      DitherTypeMax equ 10

    endif
    ;(GDIPVER >= 0x0110)
    PaletteFlags typedef SDWORD
    PaletteFlagsHasAlpha equ 0001h
    PaletteFlagsGrayScale equ 0002h
    PaletteFlagsHalftone equ 0004h

    ColorPalette struct
      Flags DWORD ?
      ; Palette flags
      Count DWORD ?
      ; Number of color entries
      Entries ARGB 1 dup (?)
      ; Palette color entries
    ColorPalette ends
    if _MSC_VER ge 1200
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
endif
