;Include file created by h2inc+ version C.2.0 on (UTC) 19/05/2024 07:52:23
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdiplusfontcollection.h\gdiplusfontcollection.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 16/12/2023 11:07:10

ifndef _GDIPLUSFONTCOLL_H
  _GDIPLUSFONTCOLL_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if _MSC_VER ge 1200
      if _MSC_VER ge 1400
      endif
    endif
    FontCollection proto WIN_STD_CALL_CONV
    FontCollection proto WIN_STD_CALL_CONV
    GetFamilyCount proto WIN_STD_CALL_CONV
    GdipGetFontCollectionFamilyCount proto WIN_STD_CALL_CONV :nativeFontCollection, :ptr numFound
    GetFamilies proto WIN_STD_CALL_CONV :INT_, :ptr FontFamily, :ptr INT_
    if_ proto WIN_STD_CALL_CONV :numSought
    SetStatus proto WIN_STD_CALL_CONV :InvalidParameter
    if_ proto WIN_STD_CALL_CONV :nativeFamilyList
    SetStatus proto WIN_STD_CALL_CONV :OutOfMemory
    GdipGetFontCollectionFamilyList proto WIN_STD_CALL_CONV :nativeFontCollection, :numSought, :nativeFamilyList, :numFound
    if_ proto WIN_STD_CALL_CONV :status
    for_ proto WIN_STD_CALL_CONV
    GdipCloneFontFamily proto WIN_STD_CALL_CONV :ptr nativeFamilyList, :ptr ptr gpfamilies
    SetStatus proto WIN_STD_CALL_CONV :status
    GetLastStatus proto WIN_STD_CALL_CONV
    SetStatus proto WIN_STD_CALL_CONV :Status
    InstalledFontCollection proto WIN_STD_CALL_CONV
    InstalledFontCollection proto WIN_STD_CALL_CONV
    PrivateFontCollection proto WIN_STD_CALL_CONV
    PrivateFontCollection proto WIN_STD_CALL_CONV
    AddFontFile proto WIN_STD_CALL_CONV :ptr WCHAR
    AddMemoryFont proto WIN_STD_CALL_CONV :ptr, :length_
    if _MSC_VER ge 1200
    endif
  endif
endif
