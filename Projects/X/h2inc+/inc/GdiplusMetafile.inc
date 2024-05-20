;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdiplusmetafile.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 16/12/2023 11:07:10

;\**************************************************************************
ifndef _GDIPLUSMETAFILE_H
  _GDIPLUSMETAFILE_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    Metafile proto WIN_STD_CALL_CONV :HMETAFILE, :ptr WmfPlaceableFileHeader, :BOOL
    Metafile proto WIN_STD_CALL_CONV :HENHMETAFILE, :BOOL
    Metafile proto WIN_STD_CALL_CONV :ptr WCHAR
    Metafile proto WIN_STD_CALL_CONV :ptr WCHAR, :ptr WmfPlaceableFileHeader
    Metafile proto WIN_STD_CALL_CONV :ptr IStream
    Metafile proto WIN_STD_CALL_CONV :HDC, :EmfType, :ptr WCHAR
    Metafile proto WIN_STD_CALL_CONV :HDC, :ptr RectF, :MetafileFrameUnit, :EmfType, :ptr WCHAR
    Metafile proto WIN_STD_CALL_CONV :HDC, :ptr Rect, :MetafileFrameUnit, :EmfType, :ptr WCHAR
    Metafile proto WIN_STD_CALL_CONV :ptr WCHAR, :HDC, :EmfType, :ptr WCHAR
    Metafile proto WIN_STD_CALL_CONV :ptr WCHAR, :HDC, :ptr RectF, :MetafileFrameUnit, :EmfType, :ptr WCHAR
    Metafile proto WIN_STD_CALL_CONV :ptr WCHAR, :HDC, :ptr Rect, :MetafileFrameUnit, :EmfType, :ptr WCHAR
    Metafile proto WIN_STD_CALL_CONV :ptr IStream, :HDC, :EmfType, :ptr WCHAR
    Metafile proto WIN_STD_CALL_CONV :ptr IStream, :HDC, :ptr RectF, :MetafileFrameUnit, :EmfType, :ptr WCHAR
    Metafile proto WIN_STD_CALL_CONV :ptr IStream, :HDC, :ptr Rect, :MetafileFrameUnit, :EmfType, :ptr WCHAR
    GetMetafileHeader proto WIN_STD_CALL_CONV :HMETAFILE, :ptr WmfPlaceableFileHeader, :ptr MetafileHeader
    GetMetafileHeader proto WIN_STD_CALL_CONV :HENHMETAFILE, :ptr MetafileHeader
    GetMetafileHeader proto WIN_STD_CALL_CONV :ptr WCHAR, :ptr MetafileHeader
    GetMetafileHeader proto WIN_STD_CALL_CONV :ptr IStream, :ptr MetafileHeader
    GetMetafileHeader proto WIN_STD_CALL_CONV :ptr MetafileHeader
    SetStatus proto WIN_STD_CALL_CONV :ptr DllExports :nativeImage, :header
    ; Once this method is called, the Metafile object is in an invalid state
    ; and can no longer be used.  It is the responsiblity of the caller to
    ; invoke DeleteEnhMetaFile to delete this hEmf.
    GetHENHMETAFILE proto WIN_STD_CALL_CONV
    ; Used in conjuction with Graphics::EnumerateMetafile to play an EMF+
    ; The data must be DWORD aligned if it's an EMF or EMF+.  It must be
    ; WORD aligned if it's a WMF.
    PlayRecord proto WIN_STD_CALL_CONV :EmfPlusRecordType, :UINT, :UINT, :ptr BYTE
    SetStatus proto WIN_STD_CALL_CONV :ptr DllExports :nativeImage, :recordType, :flags, :dataSize, :data
    ; If you're using a printer HDC for the metafile, but you want the
    ; metafile rasterized at screen resolution, then use this API to set
    ; the rasterization dpi of the metafile to the screen resolution,
    ; e.g. 96 dpi or 120 dpi.
    SetDownLevelRasterizationLimit proto WIN_STD_CALL_CONV :UINT
    GetDownLevelRasterizationLimit proto WIN_STD_CALL_CONV
    SetStatus proto WIN_STD_CALL_CONV :ptr DllExports :nativeImage, :ptr metafileRasterizationLimitDpi
    EmfToWmfBits proto WIN_STD_CALL_CONV :HENHMETAFILE, :UINT, :LPBYTE, :INT_, :eFlags_
    if (GDIPVER ge 0110h)
      ConvertToEmfPlus proto WIN_STD_CALL_CONV :ptr Graphics, :ptr INT_, :EmfType, :ptr WCHAR
      ConvertToEmfPlus proto WIN_STD_CALL_CONV :ptr Graphics, :ptr WCHAR, :ptr INT_, :EmfType, :ptr WCHAR
      ConvertToEmfPlus proto WIN_STD_CALL_CONV :ptr Graphics, :ptr IStream, :ptr INT_, :EmfType, :ptr WCHAR
    endif
    ;(GDIPVER >= 0x0110)
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
endif
; !_METAFILE_H
