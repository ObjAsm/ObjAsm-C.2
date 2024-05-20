;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdiplustypes.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 12/02/2024 17:06:00

;\**************************************************************************
ifndef _GDIPLUSTYPES_H
  _GDIPLUSTYPES_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if _MSC_VER ge 1200
      ;* padding added after data member *
    endif
    ; Support NOMINMAX by defining local min max macros 
    GDIPLUS_MIN macro a, b
      exitm <(((a) < (b)) ? (a) : (b))>
    endm
    GDIPLUS_MAX macro a, b
      exitm <(((a) > (b)) ? (a) : (b))>
    endm
    ;--------------------------------------------------------------------------
    ; Callback functions
    ;--------------------------------------------------------------------------
    TYPE_ImageAbort typedef proto WIN_STD_CALL_CONV :ptr VOID
    ImageAbort typedef ptr TYPE_ImageAbort

    DrawImageAbort typedef ImageAbort
    GetThumbnailImageAbort typedef ImageAbort

    ; Callback for EnumerateMetafile methods.  The parameters are:
    ;      recordType      WMF, EMF, or EMF+ record type
    ;      flags           (always 0 for WMF/EMF records)
    ;      dataSize        size of the record data (in bytes), or 0 if no data
    ;      data            pointer to the record data, or NULL if no data
    ;      callbackData    pointer to callbackData, if any
    ; This method can then call Metafile::PlayRecord to play the
    ; record that was just enumerated.  If this method  returns
    ; FALSE, the enumeration process is aborted.  Otherwise, it continues.
    TYPE_EnumerateMetafileProc typedef proto WIN_STD_CALL_CONV :EmfPlusRecordType, :UINT, :UINT, :ptr BYTE, :ptr VOID
    EnumerateMetafileProc typedef ptr TYPE_EnumerateMetafileProc


    if (GDIPVER ge 0110h)
      ; This is the main GDI+ Abort interface
      Abort proto WIN_STD_CALL_CONV
    endif
    ;(GDIPVER >= 0x0110)
    ;--------------------------------------------------------------------------
    ; Primitive data types
    ; NOTE:
    ;  Types already defined in standard header files:
    ;      INT8
    ;      UINT8
    ;      INT16
    ;      UINT16
    ;      INT32
    ;      UINT32
    ;      INT64
    ;      UINT64
    ;  Avoid using the following types:
    ;      LONG - use INT
    ;      ULONG - use UINT
    ;      DWORD - use UINT32
    ;--------------------------------------------------------------------------
    REAL typedef REAL4
    REAL_MAX equ <FLT_MAX>
    REAL_MIN equ <FLT_MIN>
    REAL_TOLERANCE equ (FLT_MIN * 100)
    ;* FLT_EPSILON *
    REAL_EPSILON equ 1.192092896E-07
    ;--------------------------------------------------------------------------
    ; Forward declarations of common classes
    ;--------------------------------------------------------------------------
    ;--------------------------------------------------------------------------
    ; Status return values from GDI+ methods
    ;--------------------------------------------------------------------------
    if (GDIPVER ge 0110h)
    endif
    ;(GDIPVER >= 0x0110)
    ;--------------------------------------------------------------------------
    ; Represents a dimension in a 2D coordinate system (floating-point coordinates)
    ;--------------------------------------------------------------------------
    ;--------------------------------------------------------------------------
    ; Represents a dimension in a 2D coordinate system (integer coordinates)
    ;--------------------------------------------------------------------------
    ;--------------------------------------------------------------------------
    ; Represents a location in a 2D coordinate system (floating-point coordinates)
    ;--------------------------------------------------------------------------
    ;--------------------------------------------------------------------------
    ; Represents a location in a 2D coordinate system (integer coordinates)
    ;--------------------------------------------------------------------------
    ;--------------------------------------------------------------------------
    ; Represents a rectangle in a 2D coordinate system (floating-point coordinates)
    ;--------------------------------------------------------------------------
    ;--------------------------------------------------------------------------
    ; Represents a rectangle in a 2D coordinate system (integer coordinates)
    ;--------------------------------------------------------------------------
    if _MSC_VER ge 1200
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
endif
; !_GDIPLUSTYPES_HPP
