;Include file created by h2incX, Version C.01.00, 30/03/2019 18:59
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'D:\ObjAsm\Projects\32\h2IncX\header\GdiplusBitmap.h', last modified: 22/10/2018 20:35
;Creation parameters: 

ifndef _GDIPLUSBITMAP_H
  _GDIPLUSBITMAP_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
;    Image proto WIN_STD_CALL_CONV :ptr WCHAR, :BOOL
;    Image proto WIN_STD_CALL_CONV :ptr IStream, :BOOL
;    FromFile proto WIN_STD_CALL_CONV :ptr WCHAR, :BOOL
;    FromStream proto WIN_STD_CALL_CONV :ptr IStream, :BOOL
;    Image proto WIN_STD_CALL_CONV
;    Clone proto WIN_STD_CALL_CONV
;    GetEncoderParameterListSize proto WIN_STD_CALL_CONV :ptr CLSID
;    GetEncoderParameterList proto WIN_STD_CALL_CONV :ptr CLSID, :UINT, :ptr EncoderParameters
;    Save proto WIN_STD_CALL_CONV :ptr WCHAR, :ptr CLSID, :ptr EncoderParameters
;    Save proto WIN_STD_CALL_CONV :ptr IStream, :ptr CLSID, :ptr EncoderParameters
;    SaveAdd proto WIN_STD_CALL_CONV :ptr EncoderParameters
;    SaveAdd proto WIN_STD_CALL_CONV :ptr Image, :ptr EncoderParameters
;    GetType proto WIN_STD_CALL_CONV
;    SetStatus proto WIN_STD_CALL_CONV :DllExports, :ptr type_
;    GetPhysicalDimension proto WIN_STD_CALL_CONV :ptr SizeF
;    GetBounds proto WIN_STD_CALL_CONV :ptr RectF, :ptr Unit
;    GetWidth proto WIN_STD_CALL_CONV
;    GetHeight proto WIN_STD_CALL_CONV
;    GetHorizontalResolution proto WIN_STD_CALL_CONV
;    GetVerticalResolution proto WIN_STD_CALL_CONV
;    GetFlags proto WIN_STD_CALL_CONV
;    GetRawFormat proto WIN_STD_CALL_CONV :ptr GUID
;    GetPixelFormat proto WIN_STD_CALL_CONV
;    GetPaletteSize proto WIN_STD_CALL_CONV
;    GetPalette proto WIN_STD_CALL_CONV :ptr ColorPalette, :size_
;    SetPalette proto WIN_STD_CALL_CONV :ptr ColorPalette
;    GetThumbnailImage proto WIN_STD_CALL_CONV :UINT, :UINT, :GetThumbnailImageAbort, :ptr VOID
;    GetFrameDimensionsCount proto WIN_STD_CALL_CONV
;    GetFrameDimensionsList proto WIN_STD_CALL_CONV :ptr GUID, :UINT
;    GetFrameCount proto WIN_STD_CALL_CONV :ptr GUID
;    SelectActiveFrame proto WIN_STD_CALL_CONV :ptr GUID, :UINT
;    RotateFlip proto WIN_STD_CALL_CONV :RotateFlipType
;    GetPropertyCount proto WIN_STD_CALL_CONV
;    GetPropertyIdList proto WIN_STD_CALL_CONV :UINT, :ptr PROPID
;    GetPropertyItemSize proto WIN_STD_CALL_CONV :PROPID
;    GetPropertyItem proto WIN_STD_CALL_CONV :PROPID, :UINT, :ptr PropertyItem
;    GetPropertySize proto WIN_STD_CALL_CONV :ptr UINT, :ptr UINT
;    GetAllPropertyItems proto WIN_STD_CALL_CONV :UINT, :UINT, :ptr PropertyItem
;    RemovePropertyItem proto WIN_STD_CALL_CONV :PROPID
;    SetPropertyItem proto WIN_STD_CALL_CONV :ptr PropertyItem
;    if (GDIPVER ge 0110h)
;      FindFirstItem proto WIN_STD_CALL_CONV :ptr ImageItemData
;      FindNextItem proto WIN_STD_CALL_CONV :ptr ImageItemData
;      GetItemData proto WIN_STD_CALL_CONV :ptr ImageItemData
;    endif
;    GetLastStatus proto WIN_STD_CALL_CONV
;    Image proto WIN_STD_CALL_CONV :ptr GpImage, :Status
;    SetNativeImage proto WIN_STD_CALL_CONV :ptr GpImage
;    Bitmap proto WIN_STD_CALL_CONV :ptr WCHAR, :BOOL
;    Bitmap proto WIN_STD_CALL_CONV :ptr IStream, :BOOL
;    Bitmap proto WIN_STD_CALL_CONV :width_, :INT_, :INT_, :PixelFormat, :ptr BYTE
;    Bitmap proto WIN_STD_CALL_CONV :width_, :INT_, :PixelFormat
;    Bitmap proto WIN_STD_CALL_CONV :width_, :INT_, :ptr Graphics
;    Bitmap proto WIN_STD_CALL_CONV :ptr IDirectDrawSurface7
;    Bitmap proto WIN_STD_CALL_CONV :ptr BITMAPINFO, :ptr VOID
;    Bitmap proto WIN_STD_CALL_CONV :HBITMAP, :HPALETTE
;    Bitmap proto WIN_STD_CALL_CONV :HICON
;    Bitmap proto WIN_STD_CALL_CONV :HINSTANCE, :ptr WCHAR
;    FromFile proto WIN_STD_CALL_CONV :ptr WCHAR, :BOOL
;    FromStream proto WIN_STD_CALL_CONV :ptr IStream, :BOOL
;    FromDirectDrawSurface7 proto WIN_STD_CALL_CONV :ptr IDirectDrawSurface7
;    FromBITMAPINFO proto WIN_STD_CALL_CONV :ptr BITMAPINFO, :ptr VOID
;    FromHBITMAP proto WIN_STD_CALL_CONV :HBITMAP, :HPALETTE
;    FromHICON proto WIN_STD_CALL_CONV :HICON
;    FromResource proto WIN_STD_CALL_CONV :HINSTANCE, :ptr WCHAR
;    GetHBITMAP proto WIN_STD_CALL_CONV :ptr Color, :ptr HBITMAP
;    GetHICON proto WIN_STD_CALL_CONV :ptr HICON
;    Clone proto WIN_STD_CALL_CONV :ptr Rect, :PixelFormat
;    Clone proto WIN_STD_CALL_CONV :INT_, :INT_, :width_, :INT_, :PixelFormat
;    Clone proto WIN_STD_CALL_CONV :ptr RectF, :PixelFormat
;    Clone proto WIN_STD_CALL_CONV :REAL, :REAL, :REAL, :REAL, :PixelFormat
;    Bitmap proto WIN_STD_CALL_CONV :ptr GpBitmap
;    LockBits proto WIN_STD_CALL_CONV :ptr Rect, :UINT, :PixelFormat, :ptr BitmapData
;    UnlockBits proto WIN_STD_CALL_CONV :ptr BitmapData
;    GetPixel proto WIN_STD_CALL_CONV :INT_, :INT_, :ptr Color
;    SetPixel proto WIN_STD_CALL_CONV :INT_, :INT_, :ptr Color
;    if (GDIPVER ge 0110h)
;      SetAbort proto WIN_STD_CALL_CONV :ptr GdiplusAbort
;      ConvertFormat proto WIN_STD_CALL_CONV :PixelFormat, :DitherType, :PaletteType, :ptr ColorPalette, :REAL
;      InitializePalette proto WIN_STD_CALL_CONV :ptr ColorPalette, :PaletteType, :INT_, :BOOL, :ptr Bitmap
;      ApplyEffect proto WIN_STD_CALL_CONV :ptr ptr Bitmap, :INT_, :ptr Effect, :ptr RECT, :ptr RECT, :ptr ptr Bitmap
;      ApplyEffect proto WIN_STD_CALL_CONV :ptr Effect, :ptr RECT
;      GetHistogram proto WIN_STD_CALL_CONV :HistogramFormat, :UINT, :ptr UINT, :ptr UINT, :ptr UINT, :ptr UINT
;      GetHistogramSize proto WIN_STD_CALL_CONV :HistogramFormat, :ptr UINT
;    endif
;    SetResolution proto WIN_STD_CALL_CONV :REAL, :REAL
  endif
endif
 