;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdiplus.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 16/12/2023 11:07:10

ifndef _GDIPLUS_H
  _GDIPLUS_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    INT16 typedef SWORD
    UINT16 typedef WORD
    ifndef GDIPVER
      GDIPVER equ 0100h
    endif
    include pshpack8.inc
    include GdiplusMem.inc
    include GdiplusBase.inc
    include GdiplusEnums.inc
    include GdiplusTypes.inc
    include GdiplusInit.inc
    include GdiplusPixelFormats.inc
    include GdiplusColor.inc
    include GdiplusMetaHeader.inc
    include GdiplusImaging.inc
    include GdiplusColorMatrix.inc
    if (GDIPVER ge 0110h)
      include GdiplusEffects.inc
    endif
    include GdiplusGpStubs.inc
    include GdiplusHeaders.inc
    include GdiplusFlat.inc
    include GdiplusImageAttributes.inc
    include GdiplusMatrix.inc
    include GdiplusBrush.inc
    include GdiplusPen.inc
    include GdiplusStringFormat.inc
    include GdiplusPath.inc
    include GdiplusLineCaps.inc
    include GdiplusGraphics.inc
    include GdiplusMetafile.inc
    include GdiplusCachedBitmap.inc
    include GdiplusRegion.inc
    include GdiplusFontCollection.inc
    include GdiplusFontFamily.inc
    include GdiplusFont.inc
    include GdiplusBitmap.inc
    include GdiplusImageCodec.inc
    include poppack.inc
  endif
endif
