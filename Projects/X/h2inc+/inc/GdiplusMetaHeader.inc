;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdiplusmetaheader.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 16/12/2023 11:07:10

ifndef _GDIPLUSMETAHEADER_H
  _GDIPLUSMETAHEADER_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ENHMETAHEADER3 struct
      iType DWORD ?
      nSize DWORD ?
      rclBounds RECTL <>
      rclFrame RECTL <>
      dSignature DWORD ?
      nVersion DWORD ?
      nBytes DWORD ?
      nRecords DWORD ?
      nHandles WORD ?
      sReserved WORD ?
      nDescription DWORD ?
      offDescription DWORD ?
      nPalEntries DWORD ?
      szlDevice SIZEL <>
      szlMillimeters SIZEL <>
    ENHMETAHEADER3 ends
    include pshpack2.inc
    PWMFRect16 struct
      Left INT16 ?
      Top INT16 ?
      Right INT16 ?
      Bottom INT16 ?
    PWMFRect16 ends
    WmfPlaceableFileHeader struct
      Key UINT32 ?
      Hmf INT16 ?
      BoundingBox PWMFRect16 <>
      Inch INT16 ?
      Reserved UINT32 ?
      Checksum INT16 ?
    WmfPlaceableFileHeader ends
    include poppack.inc
    GDIP_EMFPLUSFLAGS_DISPLAY equ 00000001h
  endif
endif
