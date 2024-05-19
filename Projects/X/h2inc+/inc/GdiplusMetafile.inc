;Include file created by h2inc+ version C.2.0 on (UTC) 19/05/2024 07:52:23
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdiplusmetafile.h\gdiplusmetafile.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 16/12/2023 11:07:10

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
    GetHENHMETAFILE proto WIN_STD_CALL_CONV
    PlayRecord proto WIN_STD_CALL_CONV :EmfPlusRecordType, :UINT, :UINT, :ptr BYTE
    SetStatus proto WIN_STD_CALL_CONV :ptr DllExports :nativeImage, :recordType, :flags, :dataSize, :data
    SetDownLevelRasterizationLimit proto WIN_STD_CALL_CONV :UINT
    GetDownLevelRasterizationLimit proto WIN_STD_CALL_CONV
    SetStatus proto WIN_STD_CALL_CONV :ptr DllExports :nativeImage, :ptr metafileRasterizationLimitDpi
    EmfToWmfBits proto WIN_STD_CALL_CONV :HENHMETAFILE, :UINT, :LPBYTE, :INT_, :eFlags_
    if (GDIPVER ge 0110h)
      ConvertToEmfPlus proto WIN_STD_CALL_CONV :ptr Graphics, :ptr INT_, :EmfType, :ptr WCHAR
      ConvertToEmfPlus proto WIN_STD_CALL_CONV :ptr Graphics, :ptr WCHAR, :ptr INT_, :EmfType, :ptr WCHAR
      ConvertToEmfPlus proto WIN_STD_CALL_CONV :ptr Graphics, :ptr IStream, :ptr INT_, :EmfType, :ptr WCHAR
    endif
  endif
endif
