;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdiplusmetaheader.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 16/12/2023 11:07:10

;\**************************************************************************
ifndef _GDIPLUSMETAHEADER_H
  _GDIPLUSMETAHEADER_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ENHMETAHEADER3 struct
      iType DWORD ?
      ; Record type EMR_HEADER
      nSize DWORD ?
      ; Record size in bytes.  This may be greater
      ; than the sizeof(ENHMETAHEADER).
      rclBounds RECTL <>
      ; Inclusive-inclusive bounds in device units
      rclFrame RECTL <>
      ; Inclusive-inclusive Picture Frame .01mm unit
      dSignature DWORD ?
      ; Signature.  Must be ENHMETA_SIGNATURE.
      nVersion DWORD ?
      ; Version number
      nBytes DWORD ?
      ; Size of the metafile in bytes
      nRecords DWORD ?
      ; Number of records in the metafile
      nHandles WORD ?
      ; Number of handles in the handle table
      ; Handle index zero is reserved.
      sReserved WORD ?
      ; Reserved.  Must be zero.
      nDescription DWORD ?
      ; Number of chars in the unicode desc string
      ; This is 0 if there is no description string
      offDescription DWORD ?
      ; Offset to the metafile description record.
      ; This is 0 if there is no description string
      nPalEntries DWORD ?
      ; Number of entries in the metafile palette.
      szlDevice SIZEL <>
      ; Size of the reference device in pels
      szlMillimeters SIZEL <>
      ; Size of the reference device in millimeters
    ENHMETAHEADER3 ends
    ; Placeable WMFs
    ; Placeable Metafiles were created as a non-standard way of specifying how 
    ; a metafile is mapped and scaled on an output device.
    ; Placeable metafiles are quite wide-spread, but not directly supported by
    ; the Windows API. To playback a placeable metafile using the Windows API,
    ; you will first need to strip the placeable metafile header from the file.
    ; This is typically performed by copying the metafile to a temporary file
    ; starting at file offset 22 (0x16). The contents of the temporary file may
    ; then be used as input to the Windows GetMetaFile(), PlayMetaFile(),
    ; CopyMetaFile(), etc. GDI functions.
    ; Each placeable metafile begins with a 22-byte header,
    ;  followed by a standard metafile:
    include pshpack2.inc
    ; set structure packing to 2
    PWMFRect16 struct
      Left INT16 ?
      Top INT16 ?
      Right INT16 ?
      Bottom INT16 ?
    PWMFRect16 ends
    WmfPlaceableFileHeader struct
      Key DWORD ?
      ; GDIP_WMF_PLACEABLEKEY
      Hmf INT16 ?
      ; Metafile HANDLE number (always 0)
      BoundingBox PWMFRect16 <>
      ; Coordinates in metafile units
      Inch INT16 ?
      ; Number of metafile units per inch
      Reserved DWORD ?
      ; Reserved (always 0)
      Checksum INT16 ?
      ; Checksum value for previous 10 WORDs
    WmfPlaceableFileHeader ends
    include poppack.inc
    ; Key contains a special identification value that indicates the presence
    ; of a placeable metafile header and is always 0x9AC6CDD7.
    ; Handle is used to stored the handle of the metafile in memory. When written
    ; to disk, this field is not used and will always contains the value 0.
    ; Left, Top, Right, and Bottom contain the coordinates of the upper-left
    ; and lower-right corners of the image on the output device. These are
    ; measured in twips.
    ; A twip (meaning "twentieth of a point") is the logical unit of measurement
    ; used in Windows Metafiles. A twip is equal to 1/1440 of an inch. Thus 720
    ; twips equal 1/2 inch, while 32,768 twips is 22.75 inches.
    ; Inch contains the number of twips per inch used to represent the image.
    ; Normally, there are 1440 twips per inch; however, this number may be
    ; changed to scale the image. A value of 720 indicates that the image is
    ; double its normal size, or scaled to a factor of 2:1. A value of 360
    ; indicates a scale of 4:1, while a value of 2880 indicates that the image
    ; is scaled down in size by a factor of two. A value of 1440 indicates
    ; a 1:1 scale ratio.
    ; Reserved is not used and is always set to 0.
    ; Checksum contains a checksum value for the previous 10 WORDs in the header.
    ; This value can be used in an attempt to detect if the metafile has become
    ; corrupted. The checksum is calculated by XORing each WORD value to an
    ; initial value of 0.
    ; If the metafile was recorded with a reference Hdc that was a display.
    GDIP_EMFPLUSFLAGS_DISPLAY equ 00000001h
    ; Size of the metafile (in bytes)
    ; EMF+, EMF, or WMF version
    ; Bounds in device units
    ; size of the EMF+ header in file
    ; Logical Dpi of reference Hdc
    ; usually valid only for EMF+
    ; If IsEmfPlus, this is the EMF+ version; else it is the WMF or EMF ver
    ; Get the EMF+ flags associated with the metafile
    ; Is it any type of WMF (standard or Placeable Metafile)?
    ; Is this an Placeable Metafile?
    ; Is this an EMF (not an EMF+)?
    ; Is this an EMF or EMF+ file?
    ; Is this an EMF+ file?
    ; Is this an EMF+ dual (has dual, down-level records) file?
    ; Is this an EMF+ only (no dual records) file?
    ; If it's an EMF+ file, was it recorded against a display Hdc?
    ; Get the WMF header of the metafile (if it is a WMF)
    ; Get the EMF header of the metafile (if it is an EMF)
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
endif
