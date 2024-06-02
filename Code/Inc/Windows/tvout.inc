;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\tvout.h
;             Created on (UTC) 22/05/2024 17:57:06
;             Last modified on (UTC) 16/12/2023 11:07:04

include winapifamily.inc
ifndef __TVOUT__
  __TVOUT__ equ <>
  if _MSC_VER gt 1000
  endif
  ifndef GUID_DEFINED
    include guiddef.inc
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    VIDEOPARAMETERS struct
      Guid GUID <>
      dwOffset ULONG ?
      dwCommand ULONG ?
      dwFlags ULONG ?
      dwMode ULONG ?
      dwTVStandard ULONG ?
      dwAvailableModes ULONG ?
      dwAvailableTVStandard ULONG ?
      dwFlickerFilter ULONG ?
      dwOverScanX ULONG ?
      dwOverScanY ULONG ?
      dwMaxUnscaledX ULONG ?
      dwMaxUnscaledY ULONG ?
      dwPositionX ULONG ?
      dwPositionY ULONG ?
      dwBrightness ULONG ?
      dwContrast ULONG ?
      dwCPType ULONG ?
      dwCPCommand ULONG ?
      dwCPStandard ULONG ?
      dwCPKey ULONG ?
      bCP_APSTriggerBits ULONG ?
      bOEMCopyProtection UCHAR 256 dup (?)
    VIDEOPARAMETERS ends
    _VIDEOPARAMETERS typedef VIDEOPARAMETERS
    PVIDEOPARAMETERS typedef ptr VIDEOPARAMETERS
    LPVIDEOPARAMETERS typedef ptr VIDEOPARAMETERS
    VP_COMMAND_GET equ 0001h
    VP_COMMAND_SET equ 0002h
    VP_FLAGS_TV_MODE equ 0001h
    VP_FLAGS_TV_STANDARD equ 0002h
    VP_FLAGS_FLICKER equ 0004h
    VP_FLAGS_OVERSCAN equ 0008h
    VP_FLAGS_MAX_UNSCALED equ 0010h
    VP_FLAGS_POSITION equ 0020h
    VP_FLAGS_BRIGHTNESS equ 0040h
    VP_FLAGS_CONTRAST equ 0080h
    VP_FLAGS_COPYPROTECT equ 0100h
    VP_MODE_WIN_GRAPHICS equ 0001h
    VP_MODE_TV_PLAYBACK equ 0002h
    VP_TV_STANDARD_NTSC_M equ 0001h
    VP_TV_STANDARD_NTSC_M_J equ 0002h
    VP_TV_STANDARD_PAL_B equ 0004h
    VP_TV_STANDARD_PAL_D equ 0008h
    VP_TV_STANDARD_PAL_H equ 0010h
    VP_TV_STANDARD_PAL_I equ 0020h
    VP_TV_STANDARD_PAL_M equ 0040h
    VP_TV_STANDARD_PAL_N equ 0080h
    VP_TV_STANDARD_SECAM_B equ 0100h
    VP_TV_STANDARD_SECAM_D equ 0200h
    VP_TV_STANDARD_SECAM_G equ 0400h
    VP_TV_STANDARD_SECAM_H equ 0800h
    VP_TV_STANDARD_SECAM_K equ 1000h
    VP_TV_STANDARD_SECAM_K1 equ 2000h
    VP_TV_STANDARD_SECAM_L equ 4000h
    VP_TV_STANDARD_WIN_VGA equ 8000h
    VP_TV_STANDARD_NTSC_433 equ 00010000h
    VP_TV_STANDARD_PAL_G equ 00020000h
    VP_TV_STANDARD_PAL_60 equ 00040000h
    VP_TV_STANDARD_SECAM_L1 equ 00080000h
    VP_CP_TYPE_APS_TRIGGER equ 0001h
    VP_CP_TYPE_MACROVISION equ 0002h
    VP_CP_CMD_ACTIVATE equ 0001h
    VP_CP_CMD_DEACTIVATE equ 0002h
    VP_CP_CMD_CHANGE equ 0004h
  endif
endif
