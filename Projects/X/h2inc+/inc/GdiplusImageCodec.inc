;Include file created by h2inc+ version C.2.0 on (UTC) 19/05/2024 07:52:23
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdiplusimagecodec.h\gdiplusimagecodec.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 16/12/2023 11:07:10

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
