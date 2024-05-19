;Include file created by h2inc+ version C.2.0 on (UTC) 19/05/2024 07:52:23
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdiplusfont.h\gdiplusfont.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 16/12/2023 11:07:10

ifndef _GDIPLUSFONT_H
  _GDIPLUSFONT_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    Font proto WIN_STD_CALL_CONV :HDC
    Font proto WIN_STD_CALL_CONV :HDC, :HFONT
    Font proto WIN_STD_CALL_CONV :HDC, :ptr LOGFONTW
    Font proto WIN_STD_CALL_CONV :HDC, :ptr LOGFONTA
    Font proto WIN_STD_CALL_CONV :ptr FontFamily, :REAL, :INT_, :Unit
    Font proto WIN_STD_CALL_CONV :ptr WCHAR, :REAL, :INT_, :Unit, :ptr FontCollection
    GetLogFontA proto WIN_STD_CALL_CONV :ptr Graphics, :ptr LOGFONTA
    SetStatus proto WIN_STD_CALL_CONV :DllExports, :g, :logfontA
    GetLogFontW proto WIN_STD_CALL_CONV :ptr Graphics, :ptr LOGFONTW
    SetStatus proto WIN_STD_CALL_CONV :DllExports, :g, :logfontW
    Clone proto WIN_STD_CALL_CONV
    SetStatus proto WIN_STD_CALL_CONV :DllExports, :ptr cloneFont
    Font proto WIN_STD_CALL_CONV :cloneFont, :lastResult
    Font proto WIN_STD_CALL_CONV
    IsAvailable proto WIN_STD_CALL_CONV
    return proto WIN_STD_CALL_CONV :nativeFont
    GetFamily proto WIN_STD_CALL_CONV :ptr FontFamily
    if_ proto WIN_STD_CALL_CONV :family
    SetStatus proto WIN_STD_CALL_CONV :InvalidParameter
    GdipGetFamily proto WIN_STD_CALL_CONV :nativeFont, :ptr family
    SetStatus proto WIN_STD_CALL_CONV :status
    SetStatus proto WIN_STD_CALL_CONV :status
    GetStyle proto WIN_STD_CALL_CONV
    SetStatus proto WIN_STD_CALL_CONV :DllExports, :ptr style
    GetSize proto WIN_STD_CALL_CONV
    SetStatus proto WIN_STD_CALL_CONV :DllExports, :ptr size_
    GetUnit proto WIN_STD_CALL_CONV
    SetStatus proto WIN_STD_CALL_CONV :DllExports, :ptr unit
    GetHeight proto WIN_STD_CALL_CONV :ptr Graphics
    SetStatus proto WIN_STD_CALL_CONV :DllExports, :graphics, :ptr height
    GetHeight proto WIN_STD_CALL_CONV :REAL
    SetStatus proto WIN_STD_CALL_CONV :DllExports, :dpi, :ptr height
    Font proto WIN_STD_CALL_CONV :ptr GpFont, :Status
    SetNativeFont proto WIN_STD_CALL_CONV :ptr GpFont
    GetLastStatus proto WIN_STD_CALL_CONV
    SetStatus proto WIN_STD_CALL_CONV :Status
    if_ proto WIN_STD_CALL_CONV :status
    return proto WIN_STD_CALL_CONV :lastResult
  endif
endif
