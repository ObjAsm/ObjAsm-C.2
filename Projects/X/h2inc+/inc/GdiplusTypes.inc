;Include file created by h2inc+ version C.2.0 on (UTC) 19/05/2024 07:52:23
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdiplustypes.h\gdiplustypes.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 12/02/2024 17:06:00

ifndef _GDIPLUSTYPES_H
  _GDIPLUSTYPES_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if _MSC_VER ge 1200
    endif
    GDIPLUS_MIN macro a, b
      exitm <(((a) < (b)) ? (a) : (b))>
    endm
    GDIPLUS_MAX macro a, b
      exitm <(((a) > (b)) ? (a) : (b))>
    endm
    TYPE_ImageAbort typedef proto WIN_STD_CALL_CONV :ptr VOID
    ImageAbort typedef ptr TYPE_ImageAbort

    DrawImageAbort typedef ImageAbort
    GetThumbnailImageAbort typedef ImageAbort

    TYPE_EnumerateMetafileProc typedef proto WIN_STD_CALL_CONV :EmfPlusRecordType, :UINT, :UINT, :ptr BYTE, :ptr VOID
    EnumerateMetafileProc typedef ptr TYPE_EnumerateMetafileProc


    if (GDIPVER ge 0110h)
      Abort proto WIN_STD_CALL_CONV
    endif
    REAL typedef REAL4
    REAL_MAX equ <FLT_MAX>
    REAL_MIN equ <FLT_MIN>
    REAL_TOLERANCE equ (FLT_MIN * 100)
    REAL_EPSILON equ 1.192092896E-07
    if (GDIPVER ge 0110h)
    endif
    if _MSC_VER ge 1200
    endif
  endif
endif
