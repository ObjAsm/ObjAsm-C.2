;Include file created by h2incX, Version C.01.00, 30/03/2019 18:59
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'D:\ObjAsm\Projects\32\h2IncX\header\GdiplusImageCodec.h', last modified: 22/10/2018 20:35
;Creation parameters: 

ifndef _GDIPLUSIMAGECODEC_H
  _GDIPLUSIMAGECODEC_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    GetImageDecodersSize proto WIN_STD_CALL_CONV :ptr UINT, :ptr UINT
    GetImageDecoders proto WIN_STD_CALL_CONV :UINT, :UINT, :ptr ImageCodecInfo
    GetImageEncodersSize proto WIN_STD_CALL_CONV :ptr UINT, :ptr UINT
    GetImageEncoders proto WIN_STD_CALL_CONV :UINT, :UINT, :ptr ImageCodecInfo
  endif
endif
 