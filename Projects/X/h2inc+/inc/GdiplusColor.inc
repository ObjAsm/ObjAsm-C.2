;Include file created by h2inc+ version C.2.0 on (UTC) 19/05/2024 07:52:23
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdipluscolor.h\gdipluscolor.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 16/12/2023 11:07:10

ifndef _GDIPLUSCOLOR_H
  _GDIPLUSCOLOR_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ColorMode typedef SDWORD
    ColorModeARGB32 equ 0
    ColorModeARGB64 equ 1

    ColorChannelFlags typedef SDWORD
    ColorChannelFlagsC equ 0
    ColorChannelFlagsM equ 1
    ColorChannelFlagsY equ 2
    ColorChannelFlagsK equ 3
    ColorChannelFlagsLast equ 4

  endif
endif
