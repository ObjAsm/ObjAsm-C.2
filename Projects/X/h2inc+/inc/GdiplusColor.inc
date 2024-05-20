;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdipluscolor.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 16/12/2023 11:07:10

;\**************************************************************************
ifndef _GDIPLUSCOLOR_H
  _GDIPLUSCOLOR_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ;----------------------------------------------------------------------------
    ; Color mode
    ;----------------------------------------------------------------------------
    ColorMode typedef SDWORD
    ColorModeARGB32 equ 0
    ColorModeARGB64 equ 1

    ;----------------------------------------------------------------------------
    ; Color Channel flags
    ;----------------------------------------------------------------------------
    ColorChannelFlags typedef SDWORD
    ColorChannelFlagsC equ 0
    ColorChannelFlagsM equ 1
    ColorChannelFlagsY equ 2
    ColorChannelFlagsK equ 3
    ColorChannelFlagsLast equ 4

    ;----------------------------------------------------------------------------
    ; Color
    ;----------------------------------------------------------------------------
    ; Construct an opaque Color object with
    ; the specified Red, Green, Blue values.
    ; Color values are not premultiplied.
    ; Common color constants
    ; Shift count and bit mask for A, R, G, B components
    ; Assemble A, R, G, B values into a 32-bit integer
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
endif
