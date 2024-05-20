;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\verrsrc.h
;             Created on (UTC) 06/04/2024 06:16:02
;             Last modified on (UTC) 08/01/2024 17:04:28

include winapifamily.inc
;*****************************************************************************\
;*                                                                             *
;* verrsrc.h -   Version Resource definitions                                  *
;*                                                                             *
;*               Include file declaring version resources in rc files          *
;*                                                                             *
;*               Copyright (c) Microsoft Corporation. All rights reserved.     *
;*                                                                             *
;\*****************************************************************************
if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
  ;* ----- Symbols ----- *
  VS_FILE_INFO equ <RT_VERSION>
  VS_VERSION_INFO equ 1
  VS_USER_DEFINED equ 100
  ;* ----- VS_VERSION.dwFileFlags ----- *
  ifndef _MAC
    VS_FFI_SIGNATURE equ 0FEEF04BDh
  else
    ;[...]
  endif
  VS_FFI_STRUCVERSION equ 00010000h
  VS_FFI_FILEFLAGSMASK equ 0000003Fh
  ;* ----- VS_VERSION.dwFileFlags ----- *
  VS_FF_DEBUG equ 00000001h
  VS_FF_PRERELEASE equ 00000002h
  VS_FF_PATCHED equ 00000004h
  VS_FF_PRIVATEBUILD equ 00000008h
  VS_FF_INFOINFERRED equ 00000010h
  VS_FF_SPECIALBUILD equ 00000020h
  ;* ----- VS_VERSION.dwFileOS ----- *
  VOS_UNKNOWN equ 00000000h
  VOS_DOS equ 00010000h
  VOS_OS216 equ 00020000h
  VOS_OS232 equ 00030000h
  VOS_NT equ 00040000h
  VOS_WINCE equ 00050000h
  VOS__BASE equ 00000000h
  VOS__WINDOWS16 equ 00000001h
  VOS__PM16 equ 00000002h
  VOS__PM32 equ 00000003h
  VOS__WINDOWS32 equ 00000004h
  VOS_DOS_WINDOWS16 equ 00010001h
  VOS_DOS_WINDOWS32 equ 00010004h
  VOS_OS216_PM16 equ 00020002h
  VOS_OS232_PM32 equ 00030003h
  VOS_NT_WINDOWS32 equ 00040004h
  ;* ----- VS_VERSION.dwFileType ----- *
  VFT_UNKNOWN equ 00000000h
  VFT_APP equ 00000001h
  VFT_DLL equ 00000002h
  VFT_DRV equ 00000003h
  VFT_FONT equ 00000004h
  VFT_VXD equ 00000005h
  VFT_STATIC_LIB equ 00000007h
  ;* ----- VS_VERSION.dwFileSubtype for VFT_WINDOWS_DRV ----- *
  VFT2_UNKNOWN equ 00000000h
  VFT2_DRV_PRINTER equ 00000001h
  VFT2_DRV_KEYBOARD equ 00000002h
  VFT2_DRV_LANGUAGE equ 00000003h
  VFT2_DRV_DISPLAY equ 00000004h
  VFT2_DRV_MOUSE equ 00000005h
  VFT2_DRV_NETWORK equ 00000006h
  VFT2_DRV_SYSTEM equ 00000007h
  VFT2_DRV_INSTALLABLE equ 00000008h
  VFT2_DRV_SOUND equ 00000009h
  VFT2_DRV_COMM equ 0000000Ah
  VFT2_DRV_INPUTMETHOD equ 0000000Bh
  VFT2_DRV_VERSIONED_PRINTER equ 0000000Ch
  ;* ----- VS_VERSION.dwFileSubtype for VFT_WINDOWS_FONT ----- *
  VFT2_FONT_RASTER equ 00000001h
  VFT2_FONT_VECTOR equ 00000002h
  VFT2_FONT_TRUETYPE equ 00000003h
  ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
endif
if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
  ;* ----- VerFindFile() flags ----- *
  VFFF_ISSHAREDFILE equ 0001h
  VFF_CURNEDEST equ 0001h
  VFF_FILEINUSE equ 0002h
  VFF_BUFFTOOSMALL equ 0004h
  ;* ----- VerInstallFile() flags ----- *
  VIFF_FORCEINSTALL equ 0001h
  VIFF_DONTDELETEOLD equ 0002h
  VIF_TEMPFILE equ 00000001h
  VIF_MISMATCH equ 00000002h
  VIF_SRCOLD equ 00000004h
  VIF_DIFFLANG equ 00000008h
  VIF_DIFFCODEPG equ 00000010h
  VIF_DIFFTYPE equ 00000020h
  VIF_WRITEPROT equ 00000040h
  VIF_FILEINUSE equ 00000080h
  VIF_OUTOFSPACE equ 00000100h
  VIF_ACCESSVIOLATION equ 00000200h
  VIF_SHARINGVIOLATION equ 00000400h
  VIF_CANNOTCREATE equ 00000800h
  VIF_CANNOTDELETE equ 00001000h
  VIF_CANNOTRENAME equ 00002000h
  VIF_CANNOTDELETECUR equ 00004000h
  VIF_OUTOFMEMORY equ 00008000h
  VIF_CANNOTREADSRC equ 00010000h
  VIF_CANNOTREADDST equ 00020000h
  VIF_BUFFTOOSMALL equ 00040000h
  VIF_CANNOTLOADLZ32 equ 00080000h
  VIF_CANNOTLOADCABINET equ 00100000h
  ;* RC doesn't need to see the rest of this *
  ifndef RC_INVOKED
    ifdef __cplusplus
      ;[...]
    endif
    ;* 
    ;FILE_VER_GET_... flags are for use by 
    ;GetFileVersionInfoSizeEx
    ;GetFileVersionInfoExW
    ;*
    FILE_VER_GET_LOCALISED equ 01h
    FILE_VER_GET_NEUTRAL equ 02h
    FILE_VER_GET_PREFETCHED equ 04h
    ;* ----- Types and structures ----- *
    VS_FIXEDFILEINFO struct
      dwSignature DWORD ?
      ;* e.g. 0xfeef04bd *
      dwStrucVersion DWORD ?
      ;* e.g. 0x00000042 = "0.42" *
      dwFileVersionMS DWORD ?
      ;* e.g. 0x00030075 = "3.75" *
      dwFileVersionLS DWORD ?
      ;* e.g. 0x00000031 = "0.31" *
      dwProductVersionMS DWORD ?
      ;* e.g. 0x00030010 = "3.10" *
      dwProductVersionLS DWORD ?
      ;* e.g. 0x00000031 = "0.31" *
      dwFileFlagsMask DWORD ?
      ;* = 0x3F for version "0.42" *
      dwFileFlags DWORD ?
      ;* e.g. VFF_DEBUG | VFF_PRERELEASE *
      dwFileOS DWORD ?
      ;* e.g. VOS_DOS_WINDOWS16 *
      dwFileType DWORD ?
      ;* e.g. VFT_DRIVER *
      dwFileSubtype DWORD ?
      ;* e.g. VFT2_DRV_KEYBOARD *
      dwFileDateMS DWORD ?
      ;* e.g. 0 *
      dwFileDateLS DWORD ?
      ;* e.g. 0 *
    VS_FIXEDFILEINFO ends
    tagVS_FIXEDFILEINFO typedef VS_FIXEDFILEINFO
    ifdef __cplusplus
      ;[...]
    endif
    ;* !RC_INVOKED *
  endif
  ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
endif
