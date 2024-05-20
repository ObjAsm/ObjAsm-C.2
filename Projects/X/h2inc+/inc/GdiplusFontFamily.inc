;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdiplusfontfamily.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 16/12/2023 11:07:10

;\**************************************************************************
ifndef _GDIPLUS_FONT_FAMILY_H
  _GDIPLUS_FONT_FAMILY_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    FontFamily proto WIN_STD_CALL_CONV
    nativeFamily proto WIN_STD_CALL_CONV :NULL
    lastResult proto WIN_STD_CALL_CONV :Ok
    FontFamily proto WIN_STD_CALL_CONV :ptr WCHAR, :ptr FontCollection
    FontFamily proto WIN_STD_CALL_CONV :ptr GpFontFamily, :Status
    GenericSansSerif proto WIN_STD_CALL_CONV
    GenericSerif proto WIN_STD_CALL_CONV
    GenericMonospace proto WIN_STD_CALL_CONV
    FontFamily proto WIN_STD_CALL_CONV
    Clone proto WIN_STD_CALL_CONV
    SetStatus proto WIN_STD_CALL_CONV :DllExports, :ptr clonedFamily
    FontFamily proto WIN_STD_CALL_CONV :clonedFamily, :lastResult
    GetFamilyName proto WIN_STD_CALL_CONV :LPWSTR, :LANGID
    SetStatus proto WIN_STD_CALL_CONV :DllExports, :name_, :language_
    IsStyleAvailable proto WIN_STD_CALL_CONV :INT_
    SetStatus proto WIN_STD_CALL_CONV :DllExports, :style, :ptr StyleAvailable
    if_ proto WIN_STD_CALL_CONV :status
    GetEmHeight proto WIN_STD_CALL_CONV :INT_
    SetStatus proto WIN_STD_CALL_CONV :DllExports, :style, :ptr EmHeight
    GetCellAscent proto WIN_STD_CALL_CONV :INT_
    SetStatus proto WIN_STD_CALL_CONV :DllExports, :style, :ptr CellAscent
    GetCellDescent proto WIN_STD_CALL_CONV :INT_
    SetStatus proto WIN_STD_CALL_CONV :DllExports, :style, :ptr CellDescent
    GetLineSpacing proto WIN_STD_CALL_CONV :INT_
    SetStatus proto WIN_STD_CALL_CONV :DllExports, :style, :ptr LineSpacing
    GetLastStatus proto WIN_STD_CALL_CONV
    SetStatus proto WIN_STD_CALL_CONV :Status
    if_ proto WIN_STD_CALL_CONV :status
    return proto WIN_STD_CALL_CONV :lastResult
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
endif
