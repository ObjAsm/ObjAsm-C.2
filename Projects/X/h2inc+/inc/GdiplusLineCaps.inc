;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdipluslinecaps.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 16/12/2023 11:07:10

ifndef _GDIPLUSLINECAPS_H
  _GDIPLUSLINECAPS_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    CustomLineCap proto WIN_STD_CALL_CONV :ptr GraphicsPath, :ptr GraphicsPath, :LineCap, :REAL
    CustomLineCap proto WIN_STD_CALL_CONV
    CustomLineCap proto WIN_STD_CALL_CONV
    SetStrokeCaps proto WIN_STD_CALL_CONV :LineCap, :LineCap
    GetStrokeCaps proto WIN_STD_CALL_CONV :ptr LineCap, :ptr LineCap
    SetStatus proto WIN_STD_CALL_CONV :DllExports, :startCap, :endCap
    SetStrokeJoin proto WIN_STD_CALL_CONV :LineJoin
    GetStrokeJoin proto WIN_STD_CALL_CONV
    SetStatus proto WIN_STD_CALL_CONV :DllExports, :ptr lineJoin
    SetBaseCap proto WIN_STD_CALL_CONV :LineCap
    GetBaseCap proto WIN_STD_CALL_CONV
    SetStatus proto WIN_STD_CALL_CONV :DllExports, :ptr baseCap
    SetBaseInset proto WIN_STD_CALL_CONV :REAL
    GetBaseInset proto WIN_STD_CALL_CONV
    SetStatus proto WIN_STD_CALL_CONV :DllExports, :ptr inset
    SetWidthScale proto WIN_STD_CALL_CONV :REAL
    GetWidthScale proto WIN_STD_CALL_CONV
    SetStatus proto WIN_STD_CALL_CONV :DllExports, :ptr widthScale
    Clone proto WIN_STD_CALL_CONV
    SetStatus proto WIN_STD_CALL_CONV :DllExports, :ptr newNativeLineCap
    if_ proto WIN_STD_CALL_CONV :lastResult
    CustomLineCap proto WIN_STD_CALL_CONV :newNativeLineCap, :lastResult
    if_ proto WIN_STD_CALL_CONV :newLineCap
    SetStatus proto WIN_STD_CALL_CONV :DllExports
    GetLastStatus proto WIN_STD_CALL_CONV
    return proto WIN_STD_CALL_CONV :lastStatus
  endif
endif
