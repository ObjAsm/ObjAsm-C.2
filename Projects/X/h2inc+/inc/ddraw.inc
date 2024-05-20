;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\ddraw.h
;             Created on (UTC) 06/04/2024 06:15:53
;             Last modified on (UTC) 21/02/2024 18:14:20

;***************************************************************************
ifndef __DDRAW_INCLUDED__
  __DDRAW_INCLUDED__ equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ; Always disable warning C4201: "nonstandard extension used :
    ; nameless struct/union"
    if _MSC_VER ge 1200
    endif
    ;*
    ;* If you wish an application built against the newest version of DirectDraw
    ;* to run against an older DirectDraw run time then define DIRECTDRAW_VERSION
    ;* to be the earlies version of DirectDraw you wish to run against. For,
    ;* example if you wish an application to run against a DX 3 runtime define
    ;* DIRECTDRAW_VERSION to be 0x0300.
    ;*
    ifndef DIRECTDRAW_VERSION
      DIRECTDRAW_VERSION equ 0700h
      ;* DIRECTDRAW_VERSION *
    endif
    if Defined(_WIN32) and  not Defined(_NO_COM)
      COM_NO_WINDOWS_H equ <>
      include objbase.inc
    else
      ;[...]
    endif
    _FACDD equ 876h
    MAKE_DDHRESULT macro code
      exitm <MAKE_HRESULT(1, _FACDD, code)>
    endm
    ifdef __cplusplus
      ;[...]
    endif
    ; For compilers that don't support nameless unions, do a
    ; #define NONAMELESSUNION
    ; before #include <ddraw.h>
    ifndef DUMMYUNIONNAMEN
      if Defined(__cplusplus) or  not Defined(NONAMELESSUNION)
        DUMMYUNIONNAMEN macro n
          exitm <>
        endm
      else
        DUMMYUNIONNAMEN macro n
          exitm <u ## n>
        endm
      endif
    endif
    ifndef MAKEFOURCC
      MAKEFOURCC macro ch0, ch1, ch2, ch3
        exitm <((ch0) or ((ch1) shl 8) or ((ch2) shl 16) or ((ch3) shl 24))>
      endm
    endif
    ;defined(MAKEFOURCC)
    ;*
    ;* FOURCC codes for DX compressed-texture pixel formats
    ;*
    FOURCC_DXT1 equ <(MAKEFOURCC('D', 'X', 'T', '1'))>
    FOURCC_DXT2 equ <(MAKEFOURCC('D', 'X', 'T', '2'))>
    FOURCC_DXT3 equ <(MAKEFOURCC('D', 'X', 'T', '3'))>
    FOURCC_DXT4 equ <(MAKEFOURCC('D', 'X', 'T', '4'))>
    FOURCC_DXT5 equ <(MAKEFOURCC('D', 'X', 'T', '5'))>
    ;*
    ;* GUIDS used by DirectDraw objects
    ;*
    if Defined(_WIN32) and  not Defined(_NO_COM)
      DEFINE_GUID CLSID_DirectDraw, 0D7B70EE0h, 4340h, 11CFh, 0B0h, 63h, 00h, 20h, 0AFh, 0C2h, 0CDh, 35h
      DEFINE_GUID CLSID_DirectDraw7, 3c305196h, 50dbh, 11d3h, 9ch, 0feh, 00h, 0c0h, 4fh, 0d9h, 30h, 0c5h
      DEFINE_GUID CLSID_DirectDrawClipper, 593817A0h, 7DB3h, 11CFh, 0A2h, 0DEh, 00h, 0AAh, 00h, 0b9h, 33h, 56h
      DEFINE_GUID IID_IDirectDraw, 6C14DB80h, 0A733h, 11CEh, 0A5h, 21h, 00h, 20h, 0AFh, 0Bh, 0E5h, 60h
      DEFINE_GUID IID_IDirectDraw2, 0B3A6F3E0h, 2B43h, 11CFh, 0A2h, 0DEh, 00h, 0AAh, 00h, 0B9h, 33h, 56h
      DEFINE_GUID IID_IDirectDraw4, 9c59509ah, 39bdh, 11d1h, 8ch, 4ah, 00h, 0c0h, 4fh, 0d9h, 30h, 0c5h
      DEFINE_GUID IID_IDirectDraw7, 15e65ec0h, 3b9ch, 11d2h, 0b9h, 2fh, 00h, 60h, 97h, 97h, 0eah, 5bh
      DEFINE_GUID IID_IDirectDrawSurface, 6C14DB81h, 0A733h, 11CEh, 0A5h, 21h, 00h, 20h, 0AFh, 0Bh, 0E5h, 60h
      DEFINE_GUID IID_IDirectDrawSurface2, 57805885h, 6eech, 11cfh, 94h, 41h, 0a8h, 23h, 03h, 0c1h, 0eh, 27h
      DEFINE_GUID IID_IDirectDrawSurface3, 0DA044E00h, 69B2h, 11D0h, 0A1h, 0D5h, 00h, 0AAh, 00h, 0B8h, 0DFh, 0BBh
      DEFINE_GUID IID_IDirectDrawSurface4, 0B2B8630h, 0AD35h, 11D0h, 8Eh, 0A6h, 00h, 60h, 97h, 97h, 0EAh, 5Bh
      DEFINE_GUID IID_IDirectDrawSurface7, 06675a80h, 3b9bh, 11d2h, 0b9h, 2fh, 00h, 60h, 97h, 97h, 0eah, 5bh
      DEFINE_GUID IID_IDirectDrawPalette, 6C14DB84h, 0A733h, 11CEh, 0A5h, 21h, 00h, 20h, 0AFh, 0Bh, 0E5h, 60h
      DEFINE_GUID IID_IDirectDrawClipper, 6C14DB85h, 0A733h, 11CEh, 0A5h, 21h, 00h, 20h, 0AFh, 0Bh, 0E5h, 60h
      DEFINE_GUID IID_IDirectDrawColorControl, 4B9F0EE0h, 0D7Eh, 11D0h, 9Bh, 06h, 00h, 0A0h, 0C9h, 03h, 0A3h, 0B8h
      DEFINE_GUID IID_IDirectDrawGammaControl, 69C11C3Eh, 0B46Bh, 11D1h, 0ADh, 7Ah, 00h, 0C0h, 4Fh, 0C2h, 9Bh, 4Eh
    endif
    ;*============================================================================
    ;*
    ;* DirectDraw Structures
    ;*
    ;* Various structures used to invoke DirectDraw.
    ;*
    ;*==========================================================================*
    LPDIRECTDRAW typedef ptr IDirectDraw
    LPDIRECTDRAW2 typedef ptr IDirectDraw2
    LPDIRECTDRAW4 typedef ptr IDirectDraw4
    LPDIRECTDRAW7 typedef ptr IDirectDraw7
    LPDIRECTDRAWSURFACE typedef ptr IDirectDrawSurface
    LPDIRECTDRAWSURFACE2 typedef ptr IDirectDrawSurface2
    LPDIRECTDRAWSURFACE3 typedef ptr IDirectDrawSurface3
    LPDIRECTDRAWSURFACE4 typedef ptr IDirectDrawSurface4
    LPDIRECTDRAWSURFACE7 typedef ptr IDirectDrawSurface7
    LPDIRECTDRAWPALETTE typedef ptr IDirectDrawPalette
    LPDIRECTDRAWCLIPPER typedef ptr IDirectDrawClipper
    LPDIRECTDRAWCOLORCONTROL typedef ptr IDirectDrawColorControl
    LPDIRECTDRAWGAMMACONTROL typedef ptr IDirectDrawGammaControl
    LPDDFXROP typedef ptr _DDFXROP
    LPDDSURFACEDESC typedef ptr _DDSURFACEDESC
    LPDDSURFACEDESC2 typedef ptr _DDSURFACEDESC2
    LPDDCOLORCONTROL typedef ptr _DDCOLORCONTROL
    ;*
    ;* API's
    ;*
    if (Defined(WIN32) or Defined(_WIN32)) and  not Defined(_NO_COM)
      ;#if defined( _WIN32 ) && !defined( _NO_ENUM )
      TYPE_LPDDENUMCALLBACKA typedef proto WIN_STD_CALL_CONV :ptr GUID, :LPSTR, :LPSTR, :LPVOID
      LPDDENUMCALLBACKA typedef ptr TYPE_LPDDENUMCALLBACKA

      TYPE_LPDDENUMCALLBACKW typedef proto WIN_STD_CALL_CONV :ptr GUID, :LPWSTR, :LPWSTR, :LPVOID
      LPDDENUMCALLBACKW typedef ptr TYPE_LPDDENUMCALLBACKW

      DirectDrawEnumerateW proto WIN_STD_CALL_CONV :LPDDENUMCALLBACKW, :LPVOID
      DirectDrawEnumerateA proto WIN_STD_CALL_CONV :LPDDENUMCALLBACKA, :LPVOID
      ;*
      ;* Protect against old SDKs
      ;*
      if  not Defined(HMONITOR_DECLARED) and (WINVER lt 0500h)
        HMONITOR_DECLARED equ <>
        DECLARE_HANDLE HMONITOR
      endif
      TYPE_LPDDENUMCALLBACKEXA typedef proto WIN_STD_CALL_CONV :ptr GUID, :LPSTR, :LPSTR, :LPVOID, :HMONITOR
      LPDDENUMCALLBACKEXA typedef ptr TYPE_LPDDENUMCALLBACKEXA

      TYPE_LPDDENUMCALLBACKEXW typedef proto WIN_STD_CALL_CONV :ptr GUID, :LPWSTR, :LPWSTR, :LPVOID, :HMONITOR
      LPDDENUMCALLBACKEXW typedef ptr TYPE_LPDDENUMCALLBACKEXW

      DirectDrawEnumerateExW proto WIN_STD_CALL_CONV :LPDDENUMCALLBACKEXW, :LPVOID, :DWORD
      DirectDrawEnumerateExA proto WIN_STD_CALL_CONV :LPDDENUMCALLBACKEXA, :LPVOID, :DWORD
      TYPE_LPDIRECTDRAWENUMERATEEXA typedef proto WIN_STD_CALL_CONV :LPDDENUMCALLBACKEXA, :LPVOID, :DWORD
      LPDIRECTDRAWENUMERATEEXA typedef ptr TYPE_LPDIRECTDRAWENUMERATEEXA

      TYPE_LPDIRECTDRAWENUMERATEEXW typedef proto WIN_STD_CALL_CONV :LPDDENUMCALLBACKEXW, :LPVOID, :DWORD
      LPDIRECTDRAWENUMERATEEXW typedef ptr TYPE_LPDIRECTDRAWENUMERATEEXW

      ifdef UNICODE
        LPDDENUMCALLBACK typedef LPDDENUMCALLBACKW
        DirectDrawEnumerate equ <DirectDrawEnumerateW>
        LPDDENUMCALLBACKEX typedef LPDDENUMCALLBACKEXW
        LPDIRECTDRAWENUMERATEEX typedef LPDIRECTDRAWENUMERATEEXW
        DirectDrawEnumerateEx equ <DirectDrawEnumerateExW>
      else
        LPDDENUMCALLBACK typedef LPDDENUMCALLBACKA
        DirectDrawEnumerate equ <DirectDrawEnumerateA>
        LPDDENUMCALLBACKEX typedef LPDDENUMCALLBACKEXA
        LPDIRECTDRAWENUMERATEEX typedef LPDIRECTDRAWENUMERATEEXA
        DirectDrawEnumerateEx equ <DirectDrawEnumerateExA>
      endif
      DirectDrawCreate proto WIN_STD_CALL_CONV :ptr GUID, :ptr LPDIRECTDRAW, :ptr IUnknown
      DirectDrawCreateEx proto WIN_STD_CALL_CONV :ptr GUID, :ptr LPVOID, :REFIID, :ptr IUnknown
      DirectDrawCreateClipper proto WIN_STD_CALL_CONV :DWORD, :ptr LPDIRECTDRAWCLIPPER, :ptr IUnknown
    endif
    ;*
    ;* Flags for DirectDrawEnumerateEx
    ;* DirectDrawEnumerateEx supercedes DirectDrawEnumerate. You must use GetProcAddress to
    ;* obtain a function pointer (of type LPDIRECTDRAWENUMERATEEX) to DirectDrawEnumerateEx.
    ;* By default, only the primary display device is enumerated.
    ;* DirectDrawEnumerate is equivalent to DirectDrawEnumerate(,,DDENUM_NONDISPLAYDEVICES)
    ;*
    ;*
    ;* This flag causes enumeration of any GDI display devices which are part of
    ;* the Windows Desktop
    ;*
    DDENUM_ATTACHEDSECONDARYDEVICES equ 00000001h
    ;*
    ;* This flag causes enumeration of any GDI display devices which are not
    ;* part of the Windows Desktop
    ;*
    DDENUM_DETACHEDSECONDARYDEVICES equ 00000002h
    ;*
    ;* This flag causes enumeration of non-display devices
    ;*
    DDENUM_NONDISPLAYDEVICES equ 00000004h
    REGSTR_KEY_DDHW_DESCRIPTION equ <"Description">
    REGSTR_KEY_DDHW_DRIVERNAME equ <"DriverName">
    REGSTR_PATH_DDHW equ <"Hardware\DirectDrawDrivers">
    DDCREATE_HARDWAREONLY equ 00000001h
    DDCREATE_EMULATIONONLY equ 00000002h
    if Defined(WINNT) or  not Defined(WIN32)
      ifndef _HRESULT_DEFINED
        _HRESULT_DEFINED equ <>
        HRESULT typedef SDWORD
      endif
      ; !_HRESULT_DEFINED
    endif
    ;#ifndef WINNT
    TYPE_LPDDENUMMODESCALLBACK typedef proto WIN_STD_CALL_CONV :LPDDSURFACEDESC, :LPVOID
    LPDDENUMMODESCALLBACK typedef ptr TYPE_LPDDENUMMODESCALLBACK

    TYPE_LPDDENUMMODESCALLBACK2 typedef proto WIN_STD_CALL_CONV :LPDDSURFACEDESC2, :LPVOID
    LPDDENUMMODESCALLBACK2 typedef ptr TYPE_LPDDENUMMODESCALLBACK2

    TYPE_LPDDENUMSURFACESCALLBACK typedef proto WIN_STD_CALL_CONV :LPDIRECTDRAWSURFACE, :LPDDSURFACEDESC, :LPVOID
    LPDDENUMSURFACESCALLBACK typedef ptr TYPE_LPDDENUMSURFACESCALLBACK

    TYPE_LPDDENUMSURFACESCALLBACK2 typedef proto WIN_STD_CALL_CONV :LPDIRECTDRAWSURFACE4, :LPDDSURFACEDESC2, :LPVOID
    LPDDENUMSURFACESCALLBACK2 typedef ptr TYPE_LPDDENUMSURFACESCALLBACK2

    TYPE_LPDDENUMSURFACESCALLBACK7 typedef proto WIN_STD_CALL_CONV :LPDIRECTDRAWSURFACE7, :LPDDSURFACEDESC2, :LPVOID
    LPDDENUMSURFACESCALLBACK7 typedef ptr TYPE_LPDDENUMSURFACESCALLBACK7

    ;#endif
    ;*
    ;* Generic pixel format with 8-bit RGB and alpha components
    ;*
    DDARGB struct
      blue BYTE ?
      green BYTE ?
      red BYTE ?
      alpha BYTE ?
    DDARGB ends
    _DDARGB typedef DDARGB
    LPDDARGB typedef ptr DDARGB
    ;*
    ;* This version of the structure remains for backwards source compatibility.
    ;* The DDARGB structure is the one that should be used for all DirectDraw APIs.
    ;*
    DDRGBA struct
      red BYTE ?
      green BYTE ?
      blue BYTE ?
      alpha BYTE ?
    DDRGBA ends
    _DDRGBA typedef DDRGBA
    LPDDRGBA typedef ptr DDRGBA
    ;*
    ;* DDCOLORKEY
    ;*
    DDCOLORKEY struct
      dwColorSpaceLowValue DWORD ?
      ; low boundary of color space that is to
      ; be treated as Color Key, inclusive
      dwColorSpaceHighValue DWORD ?
      ; high boundary of color space that is
      ; to be treated as Color Key, inclusive
    DDCOLORKEY ends
    _DDCOLORKEY typedef DDCOLORKEY
    LPDDCOLORKEY typedef ptr DDCOLORKEY
    ;*
    ;* DDBLTFX
    ;* Used to pass override information to the DIRECTDRAWSURFACE callback Blt.
    ;*
    DDBLTFX struct
      dwSize DWORD ?
      ; size of structure
      dwDDFX DWORD ?
      ; FX operations
      dwROP DWORD ?
      ; Win32 raster operations
      dwDDROP DWORD ?
      ; Raster operations new for DirectDraw
      dwRotationAngle DWORD ?
      ; Rotation angle for blt
      dwZBufferOpCode DWORD ?
      ; ZBuffer compares
      dwZBufferLow DWORD ?
      ; Low limit of Z buffer
      dwZBufferHigh DWORD ?
      ; High limit of Z buffer
      dwZBufferBaseDest DWORD ?
      ; Destination base value
      dwZDestConstBitDepth DWORD ?
      ; Bit depth used to specify Z constant for destination
      union
        dwZDestConst DWORD ?
        ; Constant to use as Z buffer for dest
        lpDDSZBufferDest LPDIRECTDRAWSURFACE ?
        ; Surface to use as Z buffer for dest
      ends
      dwZSrcConstBitDepth DWORD ?
      ; Bit depth used to specify Z constant for source
      union
        dwZSrcConst DWORD ?
        ; Constant to use as Z buffer for src
        lpDDSZBufferSrc LPDIRECTDRAWSURFACE ?
        ; Surface to use as Z buffer for src
      ends
      dwAlphaEdgeBlendBitDepth DWORD ?
      ; Bit depth used to specify constant for alpha edge blend
      dwAlphaEdgeBlend DWORD ?
      ; Alpha for edge blending
      dwReserved DWORD ?
      dwAlphaDestConstBitDepth DWORD ?
      ; Bit depth used to specify alpha constant for destination
      union
        dwAlphaDestConst DWORD ?
        ; Constant to use as Alpha Channel
        lpDDSAlphaDest LPDIRECTDRAWSURFACE ?
        ; Surface to use as Alpha Channel
      ends
      dwAlphaSrcConstBitDepth DWORD ?
      ; Bit depth used to specify alpha constant for source
      union
        dwAlphaSrcConst DWORD ?
        ; Constant to use as Alpha Channel
        lpDDSAlphaSrc LPDIRECTDRAWSURFACE ?
        ; Surface to use as Alpha Channel
      ends
      union
        dwFillColor DWORD ?
        ; color in RGB or Palettized
        dwFillDepth DWORD ?
        ; depth value for z-buffer
        dwFillPixel DWORD ?
        ; pixel value for RGBA or RGBZ
        lpDDSPattern LPDIRECTDRAWSURFACE ?
        ; Surface to use as pattern
      ends
      ddckDestColorkey DDCOLORKEY <>
      ; DestColorkey override
      ddckSrcColorkey DDCOLORKEY <>
      ; SrcColorkey override
    DDBLTFX ends
    _DDBLTFX typedef DDBLTFX
    LPDDBLTFX typedef ptr DDBLTFX
    ;*
    ;* DDSCAPS
    ;*
    DDSCAPS struct
      dwCaps DWORD ?
      ; capabilities of surface wanted
    DDSCAPS ends
    _DDSCAPS typedef DDSCAPS
    LPDDSCAPS typedef ptr DDSCAPS
    ;*
    ;* DDOSCAPS
    ;*
    DDOSCAPS struct
      dwCaps DWORD ?
      ; capabilities of surface wanted
    DDOSCAPS ends
    _DDOSCAPS typedef DDOSCAPS
    LPDDOSCAPS typedef ptr DDOSCAPS
    ;*
    ;* This structure is used internally by DirectDraw.
    ;*
    DDSCAPSEX struct
      dwCaps2 DWORD ?
      dwCaps3 DWORD ?
      union
        dwCaps4 DWORD ?
        dwVolumeDepth DWORD ?
      ends
    DDSCAPSEX ends
    _DDSCAPSEX typedef DDSCAPSEX
    LPDDSCAPSEX typedef ptr DDSCAPSEX
    ;*
    ;* DDSCAPS2
    ;*
    DDSCAPS2 struct
      dwCaps DWORD ?
      ; capabilities of surface wanted
      dwCaps2 DWORD ?
      dwCaps3 DWORD ?
      union
        dwCaps4 DWORD ?
        dwVolumeDepth DWORD ?
      ends
    DDSCAPS2 ends
    _DDSCAPS2 typedef DDSCAPS2
    LPDDSCAPS2 typedef ptr DDSCAPS2
    ;*
    ;* DDCAPS
    ;*
    DD_ROP_SPACE equ (256 / 32); space required to store ROP array

    ;*
    ;* NOTE: Our choosen structure number scheme is to append a single digit to
    ;* the end of the structure giving the version that structure is associated
    ;* with.
    ;*
    ;*
    ;* This structure represents the DDCAPS structure released in DirectDraw 1.0.  It is used internally
    ;* by DirectDraw to interpret caps passed into ddraw by drivers written prior to the release of DirectDraw 2.0.
    ;* New applications should use the DDCAPS structure defined below.
    ;*
    DDCAPS_DX1 struct
      dwSize DWORD ?
      ; size of the DDDRIVERCAPS structure
      dwCaps DWORD ?
      ; driver specific capabilities
      dwCaps2 DWORD ?
      ; more driver specific capabilites
      dwCKeyCaps DWORD ?
      ; color key capabilities of the surface
      dwFXCaps DWORD ?
      ; driver specific stretching and effects capabilites
      dwFXAlphaCaps DWORD ?
      ; alpha driver specific capabilities
      dwPalCaps DWORD ?
      ; palette capabilities
      dwSVCaps DWORD ?
      ; stereo vision capabilities
      dwAlphaBltConstBitDepths DWORD ?
      ; DDBD_2,4,8
      dwAlphaBltPixelBitDepths DWORD ?
      ; DDBD_1,2,4,8
      dwAlphaBltSurfaceBitDepths DWORD ?
      ; DDBD_1,2,4,8
      dwAlphaOverlayConstBitDepths DWORD ?
      ; DDBD_2,4,8
      dwAlphaOverlayPixelBitDepths DWORD ?
      ; DDBD_1,2,4,8
      dwAlphaOverlaySurfaceBitDepths DWORD ?
      ; DDBD_1,2,4,8
      dwZBufferBitDepths DWORD ?
      ; DDBD_8,16,24,32
      dwVidMemTotal DWORD ?
      ; total amount of video memory
      dwVidMemFree DWORD ?
      ; amount of free video memory
      dwMaxVisibleOverlays DWORD ?
      ; maximum number of visible overlays
      dwCurrVisibleOverlays DWORD ?
      ; current number of visible overlays
      dwNumFourCCCodes DWORD ?
      ; number of four cc codes
      dwAlignBoundarySrc DWORD ?
      ; source rectangle alignment
      dwAlignSizeSrc DWORD ?
      ; source rectangle byte size
      dwAlignBoundaryDest DWORD ?
      ; dest rectangle alignment
      dwAlignSizeDest DWORD ?
      ; dest rectangle byte size
      dwAlignStrideAlign DWORD ?
      ; stride alignment
      dwRops DWORD DD_ROP_SPACE dup (?)
      ; ROPS supported
      ddsCaps DDSCAPS <>
      ; DDSCAPS structure has all the general capabilities
      dwMinOverlayStretch DWORD ?
      ; minimum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
      dwMaxOverlayStretch DWORD ?
      ; maximum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
      dwMinLiveVideoStretch DWORD ?
      ; OBSOLETE! This field remains for compatability reasons only
      dwMaxLiveVideoStretch DWORD ?
      ; OBSOLETE! This field remains for compatability reasons only
      dwMinHwCodecStretch DWORD ?
      ; OBSOLETE! This field remains for compatability reasons only
      dwMaxHwCodecStretch DWORD ?
      ; OBSOLETE! This field remains for compatability reasons only
      dwReserved1 DWORD ?
      ; reserved
      dwReserved2 DWORD ?
      ; reserved
      dwReserved3 DWORD ?
      ; reserved
    DDCAPS_DX1 ends
    _DDCAPS_DX1 typedef DDCAPS_DX1
    LPDDCAPS_DX1 typedef ptr DDCAPS_DX1
    ;*
    ;* This structure is the DDCAPS structure as it was in version 2 and 3 of Direct X.
    ;* It is present for back compatability.
    ;*
    DDCAPS_DX3 struct
      dwSize DWORD ?
      ; size of the DDDRIVERCAPS structure
      dwCaps DWORD ?
      ; driver specific capabilities
      dwCaps2 DWORD ?
      ; more driver specific capabilites
      dwCKeyCaps DWORD ?
      ; color key capabilities of the surface
      dwFXCaps DWORD ?
      ; driver specific stretching and effects capabilites
      dwFXAlphaCaps DWORD ?
      ; alpha driver specific capabilities
      dwPalCaps DWORD ?
      ; palette capabilities
      dwSVCaps DWORD ?
      ; stereo vision capabilities
      dwAlphaBltConstBitDepths DWORD ?
      ; DDBD_2,4,8
      dwAlphaBltPixelBitDepths DWORD ?
      ; DDBD_1,2,4,8
      dwAlphaBltSurfaceBitDepths DWORD ?
      ; DDBD_1,2,4,8
      dwAlphaOverlayConstBitDepths DWORD ?
      ; DDBD_2,4,8
      dwAlphaOverlayPixelBitDepths DWORD ?
      ; DDBD_1,2,4,8
      dwAlphaOverlaySurfaceBitDepths DWORD ?
      ; DDBD_1,2,4,8
      dwZBufferBitDepths DWORD ?
      ; DDBD_8,16,24,32
      dwVidMemTotal DWORD ?
      ; total amount of video memory
      dwVidMemFree DWORD ?
      ; amount of free video memory
      dwMaxVisibleOverlays DWORD ?
      ; maximum number of visible overlays
      dwCurrVisibleOverlays DWORD ?
      ; current number of visible overlays
      dwNumFourCCCodes DWORD ?
      ; number of four cc codes
      dwAlignBoundarySrc DWORD ?
      ; source rectangle alignment
      dwAlignSizeSrc DWORD ?
      ; source rectangle byte size
      dwAlignBoundaryDest DWORD ?
      ; dest rectangle alignment
      dwAlignSizeDest DWORD ?
      ; dest rectangle byte size
      dwAlignStrideAlign DWORD ?
      ; stride alignment
      dwRops DWORD DD_ROP_SPACE dup (?)
      ; ROPS supported
      ddsCaps DDSCAPS <>
      ; DDSCAPS structure has all the general capabilities
      dwMinOverlayStretch DWORD ?
      ; minimum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
      dwMaxOverlayStretch DWORD ?
      ; maximum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
      dwMinLiveVideoStretch DWORD ?
      ; minimum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
      dwMaxLiveVideoStretch DWORD ?
      ; maximum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
      dwMinHwCodecStretch DWORD ?
      ; minimum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
      dwMaxHwCodecStretch DWORD ?
      ; maximum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
      dwReserved1 DWORD ?
      ; reserved
      dwReserved2 DWORD ?
      ; reserved
      dwReserved3 DWORD ?
      ; reserved
      dwSVBCaps DWORD ?
      ; driver specific capabilities for System->Vmem blts
      dwSVBCKeyCaps DWORD ?
      ; driver color key capabilities for System->Vmem blts
      dwSVBFXCaps DWORD ?
      ; driver FX capabilities for System->Vmem blts
      dwSVBRops DWORD DD_ROP_SPACE dup (?)
      ; ROPS supported for System->Vmem blts
      dwVSBCaps DWORD ?
      ; driver specific capabilities for Vmem->System blts
      dwVSBCKeyCaps DWORD ?
      ; driver color key capabilities for Vmem->System blts
      dwVSBFXCaps DWORD ?
      ; driver FX capabilities for Vmem->System blts
      dwVSBRops DWORD DD_ROP_SPACE dup (?)
      ; ROPS supported for Vmem->System blts
      dwSSBCaps DWORD ?
      ; driver specific capabilities for System->System blts
      dwSSBCKeyCaps DWORD ?
      ; driver color key capabilities for System->System blts
      dwSSBFXCaps DWORD ?
      ; driver FX capabilities for System->System blts
      dwSSBRops DWORD DD_ROP_SPACE dup (?)
      ; ROPS supported for System->System blts
      dwReserved4 DWORD ?
      ; reserved
      dwReserved5 DWORD ?
      ; reserved
      dwReserved6 DWORD ?
      ; reserved
    DDCAPS_DX3 ends
    _DDCAPS_DX3 typedef DDCAPS_DX3
    LPDDCAPS_DX3 typedef ptr DDCAPS_DX3
    ;*
    ;* This structure is the DDCAPS structure as it was in version 5 of Direct X.
    ;* It is present for back compatability.
    ;*
    DDCAPS_DX5 struct
      dwSize DWORD ?
      ;*  0*
      ; size of the DDDRIVERCAPS structure
      dwCaps DWORD ?
      ;*  4*
      ; driver specific capabilities
      dwCaps2 DWORD ?
      ;*  8*
      ; more driver specific capabilites
      dwCKeyCaps DWORD ?
      ;*  c*
      ; color key capabilities of the surface
      dwFXCaps DWORD ?
      ;* 10*
      ; driver specific stretching and effects capabilites
      dwFXAlphaCaps DWORD ?
      ;* 14*
      ; alpha driver specific capabilities
      dwPalCaps DWORD ?
      ;* 18*
      ; palette capabilities
      dwSVCaps DWORD ?
      ;* 1c*
      ; stereo vision capabilities
      dwAlphaBltConstBitDepths DWORD ?
      ;* 20*
      ; DDBD_2,4,8
      dwAlphaBltPixelBitDepths DWORD ?
      ;* 24*
      ; DDBD_1,2,4,8
      dwAlphaBltSurfaceBitDepths DWORD ?
      ;* 28*
      ; DDBD_1,2,4,8
      dwAlphaOverlayConstBitDepths DWORD ?
      ;* 2c*
      ; DDBD_2,4,8
      dwAlphaOverlayPixelBitDepths DWORD ?
      ;* 30*
      ; DDBD_1,2,4,8
      dwAlphaOverlaySurfaceBitDepths DWORD ?
      ;* 34*
      ; DDBD_1,2,4,8
      dwZBufferBitDepths DWORD ?
      ;* 38*
      ; DDBD_8,16,24,32
      dwVidMemTotal DWORD ?
      ;* 3c*
      ; total amount of video memory
      dwVidMemFree DWORD ?
      ;* 40*
      ; amount of free video memory
      dwMaxVisibleOverlays DWORD ?
      ;* 44*
      ; maximum number of visible overlays
      dwCurrVisibleOverlays DWORD ?
      ;* 48*
      ; current number of visible overlays
      dwNumFourCCCodes DWORD ?
      ;* 4c*
      ; number of four cc codes
      dwAlignBoundarySrc DWORD ?
      ;* 50*
      ; source rectangle alignment
      dwAlignSizeSrc DWORD ?
      ;* 54*
      ; source rectangle byte size
      dwAlignBoundaryDest DWORD ?
      ;* 58*
      ; dest rectangle alignment
      dwAlignSizeDest DWORD ?
      ;* 5c*
      ; dest rectangle byte size
      dwAlignStrideAlign DWORD ?
      ;* 60*
      ; stride alignment
      dwRops DWORD DD_ROP_SPACE dup (?)
      ;* 64*
      ; ROPS supported
      ddsCaps DDSCAPS <>
      ;* 84*
      ; DDSCAPS structure has all the general capabilities
      dwMinOverlayStretch DWORD ?
      ;* 88*
      ; minimum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
      dwMaxOverlayStretch DWORD ?
      ;* 8c*
      ; maximum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
      dwMinLiveVideoStretch DWORD ?
      ;* 90*
      ; minimum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
      dwMaxLiveVideoStretch DWORD ?
      ;* 94*
      ; maximum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
      dwMinHwCodecStretch DWORD ?
      ;* 98*
      ; minimum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
      dwMaxHwCodecStretch DWORD ?
      ;* 9c*
      ; maximum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
      dwReserved1 DWORD ?
      ;* a0*
      ; reserved
      dwReserved2 DWORD ?
      ;* a4*
      ; reserved
      dwReserved3 DWORD ?
      ;* a8*
      ; reserved
      dwSVBCaps DWORD ?
      ;* ac*
      ; driver specific capabilities for System->Vmem blts
      dwSVBCKeyCaps DWORD ?
      ;* b0*
      ; driver color key capabilities for System->Vmem blts
      dwSVBFXCaps DWORD ?
      ;* b4*
      ; driver FX capabilities for System->Vmem blts
      dwSVBRops DWORD DD_ROP_SPACE dup (?)
      ;* b8*
      ; ROPS supported for System->Vmem blts
      dwVSBCaps DWORD ?
      ;* d8*
      ; driver specific capabilities for Vmem->System blts
      dwVSBCKeyCaps DWORD ?
      ;* dc*
      ; driver color key capabilities for Vmem->System blts
      dwVSBFXCaps DWORD ?
      ;* e0*
      ; driver FX capabilities for Vmem->System blts
      dwVSBRops DWORD DD_ROP_SPACE dup (?)
      ;* e4*
      ; ROPS supported for Vmem->System blts
      dwSSBCaps DWORD ?
      ;*104*
      ; driver specific capabilities for System->System blts
      dwSSBCKeyCaps DWORD ?
      ;*108*
      ; driver color key capabilities for System->System blts
      dwSSBFXCaps DWORD ?
      ;*10c*
      ; driver FX capabilities for System->System blts
      dwSSBRops DWORD DD_ROP_SPACE dup (?)
      ;*110*
      ; ROPS supported for System->System blts
      ; Members added for DX5:
      dwMaxVideoPorts DWORD ?
      ;*130*
      ; maximum number of usable video ports
      dwCurrVideoPorts DWORD ?
      ;*134*
      ; current number of video ports used
      dwSVBCaps2 DWORD ?
      ;*138*
      ; more driver specific capabilities for System->Vmem blts
      dwNLVBCaps DWORD ?
      ;*13c*
      ; driver specific capabilities for non-local->local vidmem blts
      dwNLVBCaps2 DWORD ?
      ;*140*
      ; more driver specific capabilities non-local->local vidmem blts
      dwNLVBCKeyCaps DWORD ?
      ;*144*
      ; driver color key capabilities for non-local->local vidmem blts
      dwNLVBFXCaps DWORD ?
      ;*148*
      ; driver FX capabilities for non-local->local blts
      dwNLVBRops DWORD DD_ROP_SPACE dup (?)
      ;*14c*
      ; ROPS supported for non-local->local blts
    DDCAPS_DX5 ends
    _DDCAPS_DX5 typedef DDCAPS_DX5
    LPDDCAPS_DX5 typedef ptr DDCAPS_DX5
    DDCAPS_DX6 struct
      dwSize DWORD ?
      ;*  0*
      ; size of the DDDRIVERCAPS structure
      dwCaps DWORD ?
      ;*  4*
      ; driver specific capabilities
      dwCaps2 DWORD ?
      ;*  8*
      ; more driver specific capabilites
      dwCKeyCaps DWORD ?
      ;*  c*
      ; color key capabilities of the surface
      dwFXCaps DWORD ?
      ;* 10*
      ; driver specific stretching and effects capabilites
      dwFXAlphaCaps DWORD ?
      ;* 14*
      ; alpha caps
      dwPalCaps DWORD ?
      ;* 18*
      ; palette capabilities
      dwSVCaps DWORD ?
      ;* 1c*
      ; stereo vision capabilities
      dwAlphaBltConstBitDepths DWORD ?
      ;* 20*
      ; DDBD_2,4,8
      dwAlphaBltPixelBitDepths DWORD ?
      ;* 24*
      ; DDBD_1,2,4,8
      dwAlphaBltSurfaceBitDepths DWORD ?
      ;* 28*
      ; DDBD_1,2,4,8
      dwAlphaOverlayConstBitDepths DWORD ?
      ;* 2c*
      ; DDBD_2,4,8
      dwAlphaOverlayPixelBitDepths DWORD ?
      ;* 30*
      ; DDBD_1,2,4,8
      dwAlphaOverlaySurfaceBitDepths DWORD ?
      ;* 34*
      ; DDBD_1,2,4,8
      dwZBufferBitDepths DWORD ?
      ;* 38*
      ; DDBD_8,16,24,32
      dwVidMemTotal DWORD ?
      ;* 3c*
      ; total amount of video memory
      dwVidMemFree DWORD ?
      ;* 40*
      ; amount of free video memory
      dwMaxVisibleOverlays DWORD ?
      ;* 44*
      ; maximum number of visible overlays
      dwCurrVisibleOverlays DWORD ?
      ;* 48*
      ; current number of visible overlays
      dwNumFourCCCodes DWORD ?
      ;* 4c*
      ; number of four cc codes
      dwAlignBoundarySrc DWORD ?
      ;* 50*
      ; source rectangle alignment
      dwAlignSizeSrc DWORD ?
      ;* 54*
      ; source rectangle byte size
      dwAlignBoundaryDest DWORD ?
      ;* 58*
      ; dest rectangle alignment
      dwAlignSizeDest DWORD ?
      ;* 5c*
      ; dest rectangle byte size
      dwAlignStrideAlign DWORD ?
      ;* 60*
      ; stride alignment
      dwRops DWORD DD_ROP_SPACE dup (?)
      ;* 64*
      ; ROPS supported
      ddsOldCaps DDSCAPS <>
      ;* 84*
      ; Was DDSCAPS  ddsCaps. ddsCaps is of type DDSCAPS2 for DX6
      dwMinOverlayStretch DWORD ?
      ;* 88*
      ; minimum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
      dwMaxOverlayStretch DWORD ?
      ;* 8c*
      ; maximum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
      dwMinLiveVideoStretch DWORD ?
      ;* 90*
      ; minimum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
      dwMaxLiveVideoStretch DWORD ?
      ;* 94*
      ; maximum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
      dwMinHwCodecStretch DWORD ?
      ;* 98*
      ; minimum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
      dwMaxHwCodecStretch DWORD ?
      ;* 9c*
      ; maximum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
      dwReserved1 DWORD ?
      ;* a0*
      ; reserved
      dwReserved2 DWORD ?
      ;* a4*
      ; reserved
      dwReserved3 DWORD ?
      ;* a8*
      ; reserved
      dwSVBCaps DWORD ?
      ;* ac*
      ; driver specific capabilities for System->Vmem blts
      dwSVBCKeyCaps DWORD ?
      ;* b0*
      ; driver color key capabilities for System->Vmem blts
      dwSVBFXCaps DWORD ?
      ;* b4*
      ; driver FX capabilities for System->Vmem blts
      dwSVBRops DWORD DD_ROP_SPACE dup (?)
      ;* b8*
      ; ROPS supported for System->Vmem blts
      dwVSBCaps DWORD ?
      ;* d8*
      ; driver specific capabilities for Vmem->System blts
      dwVSBCKeyCaps DWORD ?
      ;* dc*
      ; driver color key capabilities for Vmem->System blts
      dwVSBFXCaps DWORD ?
      ;* e0*
      ; driver FX capabilities for Vmem->System blts
      dwVSBRops DWORD DD_ROP_SPACE dup (?)
      ;* e4*
      ; ROPS supported for Vmem->System blts
      dwSSBCaps DWORD ?
      ;*104*
      ; driver specific capabilities for System->System blts
      dwSSBCKeyCaps DWORD ?
      ;*108*
      ; driver color key capabilities for System->System blts
      dwSSBFXCaps DWORD ?
      ;*10c*
      ; driver FX capabilities for System->System blts
      dwSSBRops DWORD DD_ROP_SPACE dup (?)
      ;*110*
      ; ROPS supported for System->System blts
      dwMaxVideoPorts DWORD ?
      ;*130*
      ; maximum number of usable video ports
      dwCurrVideoPorts DWORD ?
      ;*134*
      ; current number of video ports used
      dwSVBCaps2 DWORD ?
      ;*138*
      ; more driver specific capabilities for System->Vmem blts
      dwNLVBCaps DWORD ?
      ;*13c*
      ; driver specific capabilities for non-local->local vidmem blts
      dwNLVBCaps2 DWORD ?
      ;*140*
      ; more driver specific capabilities non-local->local vidmem blts
      dwNLVBCKeyCaps DWORD ?
      ;*144*
      ; driver color key capabilities for non-local->local vidmem blts
      dwNLVBFXCaps DWORD ?
      ;*148*
      ; driver FX capabilities for non-local->local blts
      dwNLVBRops DWORD DD_ROP_SPACE dup (?)
      ;*14c*
      ; ROPS supported for non-local->local blts
      ; Members added for DX6 release
      ddsCaps DDSCAPS2 <>
      ;*16c*
      ; Surface Caps
    DDCAPS_DX6 ends
    _DDCAPS_DX6 typedef DDCAPS_DX6
    LPDDCAPS_DX6 typedef ptr DDCAPS_DX6
    DDCAPS_DX7 struct
      dwSize DWORD ?
      ;*  0*
      ; size of the DDDRIVERCAPS structure
      dwCaps DWORD ?
      ;*  4*
      ; driver specific capabilities
      dwCaps2 DWORD ?
      ;*  8*
      ; more driver specific capabilites
      dwCKeyCaps DWORD ?
      ;*  c*
      ; color key capabilities of the surface
      dwFXCaps DWORD ?
      ;* 10*
      ; driver specific stretching and effects capabilites
      dwFXAlphaCaps DWORD ?
      ;* 14*
      ; alpha driver specific capabilities
      dwPalCaps DWORD ?
      ;* 18*
      ; palette capabilities
      dwSVCaps DWORD ?
      ;* 1c*
      ; stereo vision capabilities
      dwAlphaBltConstBitDepths DWORD ?
      ;* 20*
      ; DDBD_2,4,8
      dwAlphaBltPixelBitDepths DWORD ?
      ;* 24*
      ; DDBD_1,2,4,8
      dwAlphaBltSurfaceBitDepths DWORD ?
      ;* 28*
      ; DDBD_1,2,4,8
      dwAlphaOverlayConstBitDepths DWORD ?
      ;* 2c*
      ; DDBD_2,4,8
      dwAlphaOverlayPixelBitDepths DWORD ?
      ;* 30*
      ; DDBD_1,2,4,8
      dwAlphaOverlaySurfaceBitDepths DWORD ?
      ;* 34*
      ; DDBD_1,2,4,8
      dwZBufferBitDepths DWORD ?
      ;* 38*
      ; DDBD_8,16,24,32
      dwVidMemTotal DWORD ?
      ;* 3c*
      ; total amount of video memory
      dwVidMemFree DWORD ?
      ;* 40*
      ; amount of free video memory
      dwMaxVisibleOverlays DWORD ?
      ;* 44*
      ; maximum number of visible overlays
      dwCurrVisibleOverlays DWORD ?
      ;* 48*
      ; current number of visible overlays
      dwNumFourCCCodes DWORD ?
      ;* 4c*
      ; number of four cc codes
      dwAlignBoundarySrc DWORD ?
      ;* 50*
      ; source rectangle alignment
      dwAlignSizeSrc DWORD ?
      ;* 54*
      ; source rectangle byte size
      dwAlignBoundaryDest DWORD ?
      ;* 58*
      ; dest rectangle alignment
      dwAlignSizeDest DWORD ?
      ;* 5c*
      ; dest rectangle byte size
      dwAlignStrideAlign DWORD ?
      ;* 60*
      ; stride alignment
      dwRops DWORD DD_ROP_SPACE dup (?)
      ;* 64*
      ; ROPS supported
      ddsOldCaps DDSCAPS <>
      ;* 84*
      ; Was DDSCAPS  ddsCaps. ddsCaps is of type DDSCAPS2 for DX6
      dwMinOverlayStretch DWORD ?
      ;* 88*
      ; minimum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
      dwMaxOverlayStretch DWORD ?
      ;* 8c*
      ; maximum overlay stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
      dwMinLiveVideoStretch DWORD ?
      ;* 90*
      ; minimum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
      dwMaxLiveVideoStretch DWORD ?
      ;* 94*
      ; maximum live video stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
      dwMinHwCodecStretch DWORD ?
      ;* 98*
      ; minimum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
      dwMaxHwCodecStretch DWORD ?
      ;* 9c*
      ; maximum hardware codec stretch factor multiplied by 1000, eg 1000 == 1.0, 1300 == 1.3
      dwReserved1 DWORD ?
      ;* a0*
      ; reserved
      dwReserved2 DWORD ?
      ;* a4*
      ; reserved
      dwReserved3 DWORD ?
      ;* a8*
      ; reserved
      dwSVBCaps DWORD ?
      ;* ac*
      ; driver specific capabilities for System->Vmem blts
      dwSVBCKeyCaps DWORD ?
      ;* b0*
      ; driver color key capabilities for System->Vmem blts
      dwSVBFXCaps DWORD ?
      ;* b4*
      ; driver FX capabilities for System->Vmem blts
      dwSVBRops DWORD DD_ROP_SPACE dup (?)
      ;* b8*
      ; ROPS supported for System->Vmem blts
      dwVSBCaps DWORD ?
      ;* d8*
      ; driver specific capabilities for Vmem->System blts
      dwVSBCKeyCaps DWORD ?
      ;* dc*
      ; driver color key capabilities for Vmem->System blts
      dwVSBFXCaps DWORD ?
      ;* e0*
      ; driver FX capabilities for Vmem->System blts
      dwVSBRops DWORD DD_ROP_SPACE dup (?)
      ;* e4*
      ; ROPS supported for Vmem->System blts
      dwSSBCaps DWORD ?
      ;*104*
      ; driver specific capabilities for System->System blts
      dwSSBCKeyCaps DWORD ?
      ;*108*
      ; driver color key capabilities for System->System blts
      dwSSBFXCaps DWORD ?
      ;*10c*
      ; driver FX capabilities for System->System blts
      dwSSBRops DWORD DD_ROP_SPACE dup (?)
      ;*110*
      ; ROPS supported for System->System blts
      dwMaxVideoPorts DWORD ?
      ;*130*
      ; maximum number of usable video ports
      dwCurrVideoPorts DWORD ?
      ;*134*
      ; current number of video ports used
      dwSVBCaps2 DWORD ?
      ;*138*
      ; more driver specific capabilities for System->Vmem blts
      dwNLVBCaps DWORD ?
      ;*13c*
      ; driver specific capabilities for non-local->local vidmem blts
      dwNLVBCaps2 DWORD ?
      ;*140*
      ; more driver specific capabilities non-local->local vidmem blts
      dwNLVBCKeyCaps DWORD ?
      ;*144*
      ; driver color key capabilities for non-local->local vidmem blts
      dwNLVBFXCaps DWORD ?
      ;*148*
      ; driver FX capabilities for non-local->local blts
      dwNLVBRops DWORD DD_ROP_SPACE dup (?)
      ;*14c*
      ; ROPS supported for non-local->local blts
      ; Members added for DX6 release
      ddsCaps DDSCAPS2 <>
      ;*16c*
      ; Surface Caps
    DDCAPS_DX7 ends
    _DDCAPS_DX7 typedef DDCAPS_DX7
    LPDDCAPS_DX7 typedef ptr DDCAPS_DX7
    if DIRECTDRAW_VERSION le 300h
      DDCAPS typedef DDCAPS_DX3
    elseif DIRECTDRAW_VERSION le 500h
      DDCAPS typedef DDCAPS_DX5
    elseif DIRECTDRAW_VERSION le 600h
      DDCAPS typedef DDCAPS_DX6
    else
      DDCAPS typedef DDCAPS_DX7
    endif
    LPDDCAPS typedef ptr DDCAPS
    ;*
    ;* DDPIXELFORMAT
    ;*
    ifndef _DDPIXELFORMAT_DEFINED
      _DDPIXELFORMAT_DEFINED equ <>
      DDPIXELFORMAT struct
        dwSize DWORD ?
        ; size of structure
        dwFlags DWORD ?
        ; pixel format flags
        dwFourCC DWORD ?
        ; (FOURCC code)
        union
          dwRGBBitCount DWORD ?
          ; how many bits per pixel
          dwYUVBitCount DWORD ?
          ; how many bits per pixel
          dwZBufferBitDepth DWORD ?
          ; how many total bits/pixel in z buffer (including any stencil bits)
          dwAlphaBitDepth DWORD ?
          ; how many bits for alpha channels
          dwLuminanceBitCount DWORD ?
          ; how many bits per pixel
          dwBumpBitCount DWORD ?
          ; how many bits per "buxel", total
          dwPrivateFormatBitCount DWORD ?
          ; Bits per pixel of private driver formats. Only valid in texture
          ; format list and if DDPF_D3DFORMAT is set
        ends
        union
          dwRBitMask DWORD ?
          ; mask for red bit
          dwYBitMask DWORD ?
          ; mask for Y bits
          dwStencilBitDepth DWORD ?
          ; how many stencil bits (note: dwZBufferBitDepth-dwStencilBitDepth is total Z-only bits)
          dwLuminanceBitMask DWORD ?
          ; mask for luminance bits
          dwBumpDuBitMask DWORD ?
          ; mask for bump map U delta bits
          dwOperations DWORD ?
          ; DDPF_D3DFORMAT Operations
        ends
        union
          dwGBitMask DWORD ?
          ; mask for green bits
          dwUBitMask DWORD ?
          ; mask for U bits
          dwZBitMask DWORD ?
          ; mask for Z bits
          dwBumpDvBitMask DWORD ?
          ; mask for bump map V delta bits
          struct MultiSampleCaps
            wFlipMSTypes WORD ?
            ; Multisample methods supported via flip for this D3DFORMAT
            wBltMSTypes WORD ?
            ; Multisample methods supported via blt for this D3DFORMAT
          ends
        ends
        union
          dwBBitMask DWORD ?
          ; mask for blue bits
          dwVBitMask DWORD ?
          ; mask for V bits
          dwStencilBitMask DWORD ?
          ; mask for stencil bits
          dwBumpLuminanceBitMask DWORD ?
          ; mask for luminance in bump map
        ends
        union
          dwRGBAlphaBitMask DWORD ?
          ; mask for alpha channel
          dwYUVAlphaBitMask DWORD ?
          ; mask for alpha channel
          dwLuminanceAlphaBitMask DWORD ?
          ; mask for alpha channel
          dwRGBZBitMask DWORD ?
          ; mask for Z channel
          dwYUVZBitMask DWORD ?
          ; mask for Z channel
        ends
      DDPIXELFORMAT ends
      _DDPIXELFORMAT typedef DDPIXELFORMAT
    endif
    ; _DDPIXELFORMAT_DEFINED
    LPDDPIXELFORMAT typedef ptr DDPIXELFORMAT
    ;*
    ;* DDOVERLAYFX
    ;*
    DDOVERLAYFX struct
      dwSize DWORD ?
      ; size of structure
      dwAlphaEdgeBlendBitDepth DWORD ?
      ; Bit depth used to specify constant for alpha edge blend
      dwAlphaEdgeBlend DWORD ?
      ; Constant to use as alpha for edge blend
      dwReserved DWORD ?
      dwAlphaDestConstBitDepth DWORD ?
      ; Bit depth used to specify alpha constant for destination
      union
        dwAlphaDestConst DWORD ?
        ; Constant to use as alpha channel for dest
        lpDDSAlphaDest LPDIRECTDRAWSURFACE ?
        ; Surface to use as alpha channel for dest
      ends
      dwAlphaSrcConstBitDepth DWORD ?
      ; Bit depth used to specify alpha constant for source
      union
        dwAlphaSrcConst DWORD ?
        ; Constant to use as alpha channel for src
        lpDDSAlphaSrc LPDIRECTDRAWSURFACE ?
        ; Surface to use as alpha channel for src
      ends
      dckDestColorkey DDCOLORKEY <>
      ; DestColorkey override
      dckSrcColorkey DDCOLORKEY <>
      ; DestColorkey override
      dwDDFX DWORD ?
      ; Overlay FX
      dwFlags DWORD ?
      ; flags
    DDOVERLAYFX ends
    _DDOVERLAYFX typedef DDOVERLAYFX
    LPDDOVERLAYFX typedef ptr DDOVERLAYFX
    ;*
    ;* DDBLTBATCH: BltBatch entry structure
    ;*
    DDBLTBATCH struct
      lprDest LPRECT ?
      lpDDSSrc LPDIRECTDRAWSURFACE ?
      lprSrc LPRECT ?
      dwFlags DWORD ?
      lpDDBltFx LPDDBLTFX ?
    DDBLTBATCH ends
    _DDBLTBATCH typedef DDBLTBATCH
    LPDDBLTBATCH typedef ptr DDBLTBATCH
    ;*
    ;* DDGAMMARAMP
    ;*
    DDGAMMARAMP struct
      red WORD 256 dup (?)
      green WORD 256 dup (?)
      blue WORD 256 dup (?)
    DDGAMMARAMP ends
    _DDGAMMARAMP typedef DDGAMMARAMP
    LPDDGAMMARAMP typedef ptr DDGAMMARAMP
    ;*
    ;*  This is the structure within which DirectDraw returns data about the current graphics driver and chipset
    ;*
    MAX_DDDEVICEID_STRING equ 512
    DDDEVICEIDENTIFIER struct
      ;*
      ;* These elements are for presentation to the user only. They should not be used to identify particular
      ;* drivers, since this is unreliable and many different strings may be associated with the same
      ;* device, and the same driver from different vendors.
      ;*
      szDriver SBYTE MAX_DDDEVICEID_STRING dup (?)
      szDescription SBYTE MAX_DDDEVICEID_STRING dup (?)
      ;*
      ;* This element is the version of the DirectDraw/3D driver. It is legal to do <, > comparisons
      ;* on the whole 64 bits. Caution should be exercised if you use this element to identify problematic
      ;* drivers. It is recommended that guidDeviceIdentifier is used for this purpose.
      ;*
      ;* This version has the form:
      ;*  wProduct = HIWORD(liDriverVersion.HighPart)
      ;*  wVersion = LOWORD(liDriverVersion.HighPart)
      ;*  wSubVersion = HIWORD(liDriverVersion.LowPart)
      ;*  wBuild = LOWORD(liDriverVersion.LowPart)
      ;*
      ifdef _WIN32
        liDriverVersion LARGE_INTEGER <>
        ;* Defined for applications and other 32 bit components *
      else
        ;[...]
      endif
      ;*
      ;* These elements can be used to identify particular chipsets. Use with extreme caution.
      ;*   dwVendorId     Identifies the manufacturer. May be zero if unknown.
      ;*   dwDeviceId     Identifies the type of chipset. May be zero if unknown.
      ;*   dwSubSysId     Identifies the subsystem, typically this means the particular board. May be zero if unknown.
      ;*   dwRevision     Identifies the revision level of the chipset. May be zero if unknown.
      ;*
      dwVendorId DWORD ?
      dwDeviceId DWORD ?
      dwSubSysId DWORD ?
      dwRevision DWORD ?
      ;*
      ;* This element can be used to check changes in driver/chipset. This GUID is a unique identifier for the
      ;* driver/chipset pair. Use this element if you wish to track changes to the driver/chipset in order to
      ;* reprofile the graphics subsystem.
      ;* This element can also be used to identify particular problematic drivers.
      ;*
      guidDeviceIdentifier GUID <>
    DDDEVICEIDENTIFIER ends
    tagDDDEVICEIDENTIFIER typedef DDDEVICEIDENTIFIER
    LPDDDEVICEIDENTIFIER typedef ptr DDDEVICEIDENTIFIER
    DDDEVICEIDENTIFIER2 struct
      ;*
      ;* These elements are for presentation to the user only. They should not be used to identify particular
      ;* drivers, since this is unreliable and many different strings may be associated with the same
      ;* device, and the same driver from different vendors.
      ;*
      szDriver SBYTE MAX_DDDEVICEID_STRING dup (?)
      szDescription SBYTE MAX_DDDEVICEID_STRING dup (?)
      ;*
      ;* This element is the version of the DirectDraw/3D driver. It is legal to do <, > comparisons
      ;* on the whole 64 bits. Caution should be exercised if you use this element to identify problematic
      ;* drivers. It is recommended that guidDeviceIdentifier is used for this purpose.
      ;*
      ;* This version has the form:
      ;*  wProduct = HIWORD(liDriverVersion.HighPart)
      ;*  wVersion = LOWORD(liDriverVersion.HighPart)
      ;*  wSubVersion = HIWORD(liDriverVersion.LowPart)
      ;*  wBuild = LOWORD(liDriverVersion.LowPart)
      ;*
      ifdef _WIN32
        liDriverVersion LARGE_INTEGER <>
        ;* Defined for applications and other 32 bit components *
      else
        ;[...]
      endif
      ;*
      ;* These elements can be used to identify particular chipsets. Use with extreme caution.
      ;*   dwVendorId     Identifies the manufacturer. May be zero if unknown.
      ;*   dwDeviceId     Identifies the type of chipset. May be zero if unknown.
      ;*   dwSubSysId     Identifies the subsystem, typically this means the particular board. May be zero if unknown.
      ;*   dwRevision     Identifies the revision level of the chipset. May be zero if unknown.
      ;*
      dwVendorId DWORD ?
      dwDeviceId DWORD ?
      dwSubSysId DWORD ?
      dwRevision DWORD ?
      ;*
      ;* This element can be used to check changes in driver/chipset. This GUID is a unique identifier for the
      ;* driver/chipset pair. Use this element if you wish to track changes to the driver/chipset in order to
      ;* reprofile the graphics subsystem.
      ;* This element can also be used to identify particular problematic drivers.
      ;*
      guidDeviceIdentifier GUID <>
      ;*
      ;* This element is used to determine the Windows Hardware Quality Lab (WHQL)
      ;* certification level for this driver/device pair.
      ;*
      dwWHQLLevel DWORD ?
    DDDEVICEIDENTIFIER2 ends
    tagDDDEVICEIDENTIFIER2 typedef DDDEVICEIDENTIFIER2
    LPDDDEVICEIDENTIFIER2 typedef ptr DDDEVICEIDENTIFIER2
    ;*
    ;* Flags for the IDirectDraw4::GetDeviceIdentifier method
    ;*
    ;*
    ;* This flag causes GetDeviceIdentifier to return information about the host (typically 2D) adapter in a system equipped
    ;* with a stacked secondary 3D adapter. Such an adapter appears to the application as if it were part of the
    ;* host adapter, but is typically physcially located on a separate card. The stacked secondary's information is
    ;* returned when GetDeviceIdentifier's dwFlags field is zero, since this most accurately reflects the qualities
    ;* of the DirectDraw object involved.
    ;*
    DDGDI_GETHOSTIDENTIFIER equ 00000001h
    ;*
    ;* Macros for interpretting DDEVICEIDENTIFIER2.dwWHQLLevel
    ;*
    GET_WHQL_YEAR macro dwWHQLLevel
      exitm <((dwWHQLLevel) / 10000h)>
    endm
    GET_WHQL_MONTH macro dwWHQLLevel
      exitm <(((dwWHQLLevel) / 100h) and 00ffh)>
    endm
    GET_WHQL_DAY macro dwWHQLLevel
      exitm <((dwWHQLLevel) and 0ffh)>
    endm
    ;*
    ;* callbacks
    ;*
    TYPE_LPCLIPPERCALLBACK typedef proto WIN_STD_CALL_CONV :LPDIRECTDRAWCLIPPER, :HWND, :DWORD, :LPVOID
    LPCLIPPERCALLBACK typedef ptr TYPE_LPCLIPPERCALLBACK

    ifdef STREAMING
      TYPE_LPSURFACESTREAMINGCALLBACK typedef proto WIN_STD_CALL_CONV :DWORD
      LPSURFACESTREAMINGCALLBACK typedef ptr TYPE_LPSURFACESTREAMINGCALLBACK

    endif
    ;*
    ;* INTERACES FOLLOW:
    ;*      IDirectDraw
    ;*      IDirectDrawClipper
    ;*      IDirectDrawPalette
    ;*      IDirectDrawSurface
    ;*
    ;*
    ;* IDirectDraw
    ;*
    if Defined(_WIN32) and  not Defined(_NO_COM)
      INTERFACE equ <IDirectDraw>
      DECLARE_INTERFACE_(IDirectDraw, IUnknown)
        ??Interface equ <DDDEVICEIDENTIFIER2>
        ;*** IUnknown methods ***
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ;*** IDirectDraw methods ***
        STDMETHOD Compact_
        STDMETHOD CreateClipper, :DWORD, :ptr LPDIRECTDRAWCLIPPER, :ptr IUnknown
        STDMETHOD CreatePalette, :DWORD, :LPPALETTEENTRY, :ptr LPDIRECTDRAWPALETTE, :ptr IUnknown
        STDMETHOD CreateSurface, :LPDDSURFACEDESC, :ptr LPDIRECTDRAWSURFACE, :ptr IUnknown
        STDMETHOD DuplicateSurface, :LPDIRECTDRAWSURFACE, :ptr LPDIRECTDRAWSURFACE
        STDMETHOD EnumDisplayModes, :DWORD, :LPDDSURFACEDESC, :POINTER, :LPDDENUMMODESCALLBACK
        STDMETHOD EnumSurfaces, :DWORD, :LPDDSURFACEDESC, :POINTER, :LPDDENUMSURFACESCALLBACK
        STDMETHOD FlipToGDISurface
        STDMETHOD GetCaps, :LPDDCAPS, :LPDDCAPS
        STDMETHOD GetDisplayMode, :LPDDSURFACEDESC
        STDMETHOD GetFourCCCodes, :LPDWORD, :LPDWORD
        STDMETHOD GetGDISurface, :ptr LPDIRECTDRAWSURFACE
        STDMETHOD GetMonitorFrequency, :LPDWORD
        STDMETHOD GetScanLine, :LPDWORD
        STDMETHOD GetVerticalBlankStatus, :LPBOOL
        STDMETHOD Initialize, :ptr GUID
        STDMETHOD RestoreDisplayMode
        STDMETHOD SetCooperativeLevel, :HWND, :DWORD
        STDMETHOD SetDisplayMode, :DWORD, :DWORD, :DWORD
        STDMETHOD WaitForVerticalBlank, :DWORD, :HANDLE
      DECLARE_INTERFACE__END

      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirectDraw_QueryInterface macro p, a, b
          exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
        endm
        IDirectDraw_AddRef macro p
          exitm <(p) - lpVtbl - AddRef (p)>
        endm
        IDirectDraw_Release macro p
          exitm <(p) - lpVtbl - Release (p)>
        endm
        IDirectDraw_Compact macro p
          exitm <(p) - lpVtbl - Compact (p)>
        endm
        IDirectDraw_CreateClipper macro p, a, b, c_
          exitm <(p) - lpVtbl - CreateClipper (p, a, b, c_)>
        endm
        IDirectDraw_CreatePalette macro p, a, b, c_, d
          exitm <(p) - lpVtbl - CreatePalette (p, a, b, c_, d)>
        endm
        IDirectDraw_CreateSurface macro p, a, b, c_
          exitm <(p) - lpVtbl - CreateSurface (p, a, b, c_)>
        endm
        IDirectDraw_DuplicateSurface macro p, a, b
          exitm <(p) - lpVtbl - DuplicateSurface (p, a, b)>
        endm
        IDirectDraw_EnumDisplayModes macro p, a, b, c_, d
          exitm <(p) - lpVtbl - EnumDisplayModes (p, a, b, c_, d)>
        endm
        IDirectDraw_EnumSurfaces macro p, a, b, c_, d
          exitm <(p) - lpVtbl - EnumSurfaces (p, a, b, c_, d)>
        endm
        IDirectDraw_FlipToGDISurface macro p
          exitm <(p) - lpVtbl - FlipToGDISurface (p)>
        endm
        IDirectDraw_GetCaps macro p, a, b
          exitm <(p) - lpVtbl - GetCaps (p, a, b)>
        endm
        IDirectDraw_GetDisplayMode macro p, a
          exitm <(p) - lpVtbl - GetDisplayMode (p, a)>
        endm
        IDirectDraw_GetFourCCCodes macro p, a, b
          exitm <(p) - lpVtbl - GetFourCCCodes (p, a, b)>
        endm
        IDirectDraw_GetGDISurface macro p, a
          exitm <(p) - lpVtbl - GetGDISurface (p, a)>
        endm
        IDirectDraw_GetMonitorFrequency macro p, a
          exitm <(p) - lpVtbl - GetMonitorFrequency (p, a)>
        endm
        IDirectDraw_GetScanLine macro p, a
          exitm <(p) - lpVtbl - GetScanLine (p, a)>
        endm
        IDirectDraw_GetVerticalBlankStatus macro p, a
          exitm <(p) - lpVtbl - GetVerticalBlankStatus (p, a)>
        endm
        IDirectDraw_Initialize macro p, a
          exitm <(p) - lpVtbl - Initialize (p, a)>
        endm
        IDirectDraw_RestoreDisplayMode macro p
          exitm <(p) - lpVtbl - RestoreDisplayMode (p)>
        endm
        IDirectDraw_SetCooperativeLevel macro p, a, b
          exitm <(p) - lpVtbl - SetCooperativeLevel (p, a, b)>
        endm
        IDirectDraw_SetDisplayMode macro p, a, b, c_
          exitm <(p) - lpVtbl - SetDisplayMode (p, a, b, c_)>
        endm
        IDirectDraw_WaitForVerticalBlank macro p, a, b
          exitm <(p) - lpVtbl - WaitForVerticalBlank (p, a, b)>
        endm
      else
        ;[...]
      endif
    endif
    if Defined(_WIN32) and  not Defined(_NO_COM)
      INTERFACE equ <IDirectDraw2>
      DECLARE_INTERFACE_(IDirectDraw2, IUnknown)
        ??Interface equ <DDDEVICEIDENTIFIER2>
        ;*** IUnknown methods ***
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ;*** IDirectDraw methods ***
        STDMETHOD Compact_
        STDMETHOD CreateClipper, :DWORD, :ptr LPDIRECTDRAWCLIPPER, :ptr IUnknown
        STDMETHOD CreatePalette, :DWORD, :LPPALETTEENTRY, :ptr LPDIRECTDRAWPALETTE, :ptr IUnknown
        STDMETHOD CreateSurface, :LPDDSURFACEDESC, :ptr LPDIRECTDRAWSURFACE, :ptr IUnknown
        STDMETHOD DuplicateSurface, :LPDIRECTDRAWSURFACE, :ptr LPDIRECTDRAWSURFACE
        STDMETHOD EnumDisplayModes, :DWORD, :LPDDSURFACEDESC, :POINTER, :LPDDENUMMODESCALLBACK
        STDMETHOD EnumSurfaces, :DWORD, :LPDDSURFACEDESC, :POINTER, :LPDDENUMSURFACESCALLBACK
        STDMETHOD FlipToGDISurface
        STDMETHOD GetCaps, :LPDDCAPS, :LPDDCAPS
        STDMETHOD GetDisplayMode, :LPDDSURFACEDESC
        STDMETHOD GetFourCCCodes, :LPDWORD, :LPDWORD
        STDMETHOD GetGDISurface, :ptr LPDIRECTDRAWSURFACE
        STDMETHOD GetMonitorFrequency, :LPDWORD
        STDMETHOD GetScanLine, :LPDWORD
        STDMETHOD GetVerticalBlankStatus, :LPBOOL
        STDMETHOD Initialize, :ptr GUID
        STDMETHOD RestoreDisplayMode
        STDMETHOD SetCooperativeLevel, :HWND, :DWORD
        STDMETHOD SetDisplayMode, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
        STDMETHOD WaitForVerticalBlank, :DWORD, :HANDLE
        ;*** Added in the v2 interface ***
        STDMETHOD GetAvailableVidMem, :LPDDSCAPS, :LPDWORD, :LPDWORD
      DECLARE_INTERFACE__END

      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirectDraw2_QueryInterface macro p, a, b
          exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
        endm
        IDirectDraw2_AddRef macro p
          exitm <(p) - lpVtbl - AddRef (p)>
        endm
        IDirectDraw2_Release macro p
          exitm <(p) - lpVtbl - Release (p)>
        endm
        IDirectDraw2_Compact macro p
          exitm <(p) - lpVtbl - Compact (p)>
        endm
        IDirectDraw2_CreateClipper macro p, a, b, c_
          exitm <(p) - lpVtbl - CreateClipper (p, a, b, c_)>
        endm
        IDirectDraw2_CreatePalette macro p, a, b, c_, d
          exitm <(p) - lpVtbl - CreatePalette (p, a, b, c_, d)>
        endm
        IDirectDraw2_CreateSurface macro p, a, b, c_
          exitm <(p) - lpVtbl - CreateSurface (p, a, b, c_)>
        endm
        IDirectDraw2_DuplicateSurface macro p, a, b
          exitm <(p) - lpVtbl - DuplicateSurface (p, a, b)>
        endm
        IDirectDraw2_EnumDisplayModes macro p, a, b, c_, d
          exitm <(p) - lpVtbl - EnumDisplayModes (p, a, b, c_, d)>
        endm
        IDirectDraw2_EnumSurfaces macro p, a, b, c_, d
          exitm <(p) - lpVtbl - EnumSurfaces (p, a, b, c_, d)>
        endm
        IDirectDraw2_FlipToGDISurface macro p
          exitm <(p) - lpVtbl - FlipToGDISurface (p)>
        endm
        IDirectDraw2_GetCaps macro p, a, b
          exitm <(p) - lpVtbl - GetCaps (p, a, b)>
        endm
        IDirectDraw2_GetDisplayMode macro p, a
          exitm <(p) - lpVtbl - GetDisplayMode (p, a)>
        endm
        IDirectDraw2_GetFourCCCodes macro p, a, b
          exitm <(p) - lpVtbl - GetFourCCCodes (p, a, b)>
        endm
        IDirectDraw2_GetGDISurface macro p, a
          exitm <(p) - lpVtbl - GetGDISurface (p, a)>
        endm
        IDirectDraw2_GetMonitorFrequency macro p, a
          exitm <(p) - lpVtbl - GetMonitorFrequency (p, a)>
        endm
        IDirectDraw2_GetScanLine macro p, a
          exitm <(p) - lpVtbl - GetScanLine (p, a)>
        endm
        IDirectDraw2_GetVerticalBlankStatus macro p, a
          exitm <(p) - lpVtbl - GetVerticalBlankStatus (p, a)>
        endm
        IDirectDraw2_Initialize macro p, a
          exitm <(p) - lpVtbl - Initialize (p, a)>
        endm
        IDirectDraw2_RestoreDisplayMode macro p
          exitm <(p) - lpVtbl - RestoreDisplayMode (p)>
        endm
        IDirectDraw2_SetCooperativeLevel macro p, a, b
          exitm <(p) - lpVtbl - SetCooperativeLevel (p, a, b)>
        endm
        IDirectDraw2_SetDisplayMode macro p, a, b, c_, d, e
          exitm <(p) - lpVtbl - SetDisplayMode (p, a, b, c_, d, e)>
        endm
        IDirectDraw2_WaitForVerticalBlank macro p, a, b
          exitm <(p) - lpVtbl - WaitForVerticalBlank (p, a, b)>
        endm
        IDirectDraw2_GetAvailableVidMem macro p, a, b, c_
          exitm <(p) - lpVtbl - GetAvailableVidMem (p, a, b, c_)>
        endm
      else
        ;[...]
      endif
    endif
    if Defined(_WIN32) and  not Defined(_NO_COM)
      INTERFACE equ <IDirectDraw4>
      DECLARE_INTERFACE_(IDirectDraw4, IUnknown)
        ??Interface equ <DDDEVICEIDENTIFIER2>
        ;*** IUnknown methods ***
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ;*** IDirectDraw methods ***
        STDMETHOD Compact_
        STDMETHOD CreateClipper, :DWORD, :ptr LPDIRECTDRAWCLIPPER, :ptr IUnknown
        STDMETHOD CreatePalette, :DWORD, :LPPALETTEENTRY, :ptr LPDIRECTDRAWPALETTE, :ptr IUnknown
        STDMETHOD CreateSurface, :LPDDSURFACEDESC2, :ptr LPDIRECTDRAWSURFACE4, :ptr IUnknown
        STDMETHOD DuplicateSurface, :LPDIRECTDRAWSURFACE4, :ptr LPDIRECTDRAWSURFACE4
        STDMETHOD EnumDisplayModes, :DWORD, :LPDDSURFACEDESC2, :POINTER, :LPDDENUMMODESCALLBACK2
        STDMETHOD EnumSurfaces, :DWORD, :LPDDSURFACEDESC2, :POINTER, :LPDDENUMSURFACESCALLBACK2
        STDMETHOD FlipToGDISurface
        STDMETHOD GetCaps, :LPDDCAPS, :LPDDCAPS
        STDMETHOD GetDisplayMode, :LPDDSURFACEDESC2
        STDMETHOD GetFourCCCodes, :LPDWORD, :LPDWORD
        STDMETHOD GetGDISurface, :ptr LPDIRECTDRAWSURFACE4
        STDMETHOD GetMonitorFrequency, :LPDWORD
        STDMETHOD GetScanLine, :LPDWORD
        STDMETHOD GetVerticalBlankStatus, :LPBOOL
        STDMETHOD Initialize, :ptr GUID
        STDMETHOD RestoreDisplayMode
        STDMETHOD SetCooperativeLevel, :HWND, :DWORD
        STDMETHOD SetDisplayMode, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
        STDMETHOD WaitForVerticalBlank, :DWORD, :HANDLE
        ;*** Added in the v2 interface ***
        STDMETHOD GetAvailableVidMem, :LPDDSCAPS2, :LPDWORD, :LPDWORD
        ;*** Added in the V4 Interface ***
        STDMETHOD GetSurfaceFromDC, :HDC, :ptr LPDIRECTDRAWSURFACE4
        STDMETHOD RestoreAllSurfaces
        STDMETHOD TestCooperativeLevel
        STDMETHOD GetDeviceIdentifier, :LPDDDEVICEIDENTIFIER, :DWORD
      DECLARE_INTERFACE__END

      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirectDraw4_QueryInterface macro p, a, b
          exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
        endm
        IDirectDraw4_AddRef macro p
          exitm <(p) - lpVtbl - AddRef (p)>
        endm
        IDirectDraw4_Release macro p
          exitm <(p) - lpVtbl - Release (p)>
        endm
        IDirectDraw4_Compact macro p
          exitm <(p) - lpVtbl - Compact (p)>
        endm
        IDirectDraw4_CreateClipper macro p, a, b, c_
          exitm <(p) - lpVtbl - CreateClipper (p, a, b, c_)>
        endm
        IDirectDraw4_CreatePalette macro p, a, b, c_, d
          exitm <(p) - lpVtbl - CreatePalette (p, a, b, c_, d)>
        endm
        IDirectDraw4_CreateSurface macro p, a, b, c_
          exitm <(p) - lpVtbl - CreateSurface (p, a, b, c_)>
        endm
        IDirectDraw4_DuplicateSurface macro p, a, b
          exitm <(p) - lpVtbl - DuplicateSurface (p, a, b)>
        endm
        IDirectDraw4_EnumDisplayModes macro p, a, b, c_, d
          exitm <(p) - lpVtbl - EnumDisplayModes (p, a, b, c_, d)>
        endm
        IDirectDraw4_EnumSurfaces macro p, a, b, c_, d
          exitm <(p) - lpVtbl - EnumSurfaces (p, a, b, c_, d)>
        endm
        IDirectDraw4_FlipToGDISurface macro p
          exitm <(p) - lpVtbl - FlipToGDISurface (p)>
        endm
        IDirectDraw4_GetCaps macro p, a, b
          exitm <(p) - lpVtbl - GetCaps (p, a, b)>
        endm
        IDirectDraw4_GetDisplayMode macro p, a
          exitm <(p) - lpVtbl - GetDisplayMode (p, a)>
        endm
        IDirectDraw4_GetFourCCCodes macro p, a, b
          exitm <(p) - lpVtbl - GetFourCCCodes (p, a, b)>
        endm
        IDirectDraw4_GetGDISurface macro p, a
          exitm <(p) - lpVtbl - GetGDISurface (p, a)>
        endm
        IDirectDraw4_GetMonitorFrequency macro p, a
          exitm <(p) - lpVtbl - GetMonitorFrequency (p, a)>
        endm
        IDirectDraw4_GetScanLine macro p, a
          exitm <(p) - lpVtbl - GetScanLine (p, a)>
        endm
        IDirectDraw4_GetVerticalBlankStatus macro p, a
          exitm <(p) - lpVtbl - GetVerticalBlankStatus (p, a)>
        endm
        IDirectDraw4_Initialize macro p, a
          exitm <(p) - lpVtbl - Initialize (p, a)>
        endm
        IDirectDraw4_RestoreDisplayMode macro p
          exitm <(p) - lpVtbl - RestoreDisplayMode (p)>
        endm
        IDirectDraw4_SetCooperativeLevel macro p, a, b
          exitm <(p) - lpVtbl - SetCooperativeLevel (p, a, b)>
        endm
        IDirectDraw4_SetDisplayMode macro p, a, b, c_, d, e
          exitm <(p) - lpVtbl - SetDisplayMode (p, a, b, c_, d, e)>
        endm
        IDirectDraw4_WaitForVerticalBlank macro p, a, b
          exitm <(p) - lpVtbl - WaitForVerticalBlank (p, a, b)>
        endm
        IDirectDraw4_GetAvailableVidMem macro p, a, b, c_
          exitm <(p) - lpVtbl - GetAvailableVidMem (p, a, b, c_)>
        endm
        IDirectDraw4_GetSurfaceFromDC macro p, a, b
          exitm <(p) - lpVtbl - GetSurfaceFromDC (p, a, b)>
        endm
        IDirectDraw4_RestoreAllSurfaces macro p
          exitm <(p) - lpVtbl - RestoreAllSurfaces (p)>
        endm
        IDirectDraw4_TestCooperativeLevel macro p
          exitm <(p) - lpVtbl - TestCooperativeLevel (p)>
        endm
        IDirectDraw4_GetDeviceIdentifier macro p, a, b
          exitm <(p) - lpVtbl - GetDeviceIdentifier (p, a, b)>
        endm
      else
        ;[...]
      endif
    endif
    if Defined(_WIN32) and  not Defined(_NO_COM)
      INTERFACE equ <IDirectDraw7>
      DECLARE_INTERFACE_(IDirectDraw7, IUnknown)
        ??Interface equ <DDDEVICEIDENTIFIER2>
        ;*** IUnknown methods ***
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ;*** IDirectDraw methods ***
        STDMETHOD Compact_
        STDMETHOD CreateClipper, :DWORD, :ptr LPDIRECTDRAWCLIPPER, :ptr IUnknown
        STDMETHOD CreatePalette, :DWORD, :LPPALETTEENTRY, :ptr LPDIRECTDRAWPALETTE, :ptr IUnknown
        STDMETHOD CreateSurface, :LPDDSURFACEDESC2, :ptr LPDIRECTDRAWSURFACE7, :ptr IUnknown
        STDMETHOD DuplicateSurface, :LPDIRECTDRAWSURFACE7, :ptr LPDIRECTDRAWSURFACE7
        STDMETHOD EnumDisplayModes, :DWORD, :LPDDSURFACEDESC2, :POINTER, :LPDDENUMMODESCALLBACK2
        STDMETHOD EnumSurfaces, :DWORD, :LPDDSURFACEDESC2, :POINTER, :LPDDENUMSURFACESCALLBACK7
        STDMETHOD FlipToGDISurface
        STDMETHOD GetCaps, :LPDDCAPS, :LPDDCAPS
        STDMETHOD GetDisplayMode, :LPDDSURFACEDESC2
        STDMETHOD GetFourCCCodes, :LPDWORD, :LPDWORD
        STDMETHOD GetGDISurface, :ptr LPDIRECTDRAWSURFACE7
        STDMETHOD GetMonitorFrequency, :LPDWORD
        STDMETHOD GetScanLine, :LPDWORD
        STDMETHOD GetVerticalBlankStatus, :LPBOOL
        STDMETHOD Initialize, :ptr GUID
        STDMETHOD RestoreDisplayMode
        STDMETHOD SetCooperativeLevel, :HWND, :DWORD
        STDMETHOD SetDisplayMode, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
        STDMETHOD WaitForVerticalBlank, :DWORD, :HANDLE
        ;*** Added in the v2 interface ***
        STDMETHOD GetAvailableVidMem, :LPDDSCAPS2, :LPDWORD, :LPDWORD
        ;*** Added in the V4 Interface ***
        STDMETHOD GetSurfaceFromDC, :HDC, :ptr LPDIRECTDRAWSURFACE7
        STDMETHOD RestoreAllSurfaces
        STDMETHOD TestCooperativeLevel
        STDMETHOD GetDeviceIdentifier, :LPDDDEVICEIDENTIFIER2, :DWORD
        STDMETHOD StartModeTest, :LPSIZE, :DWORD, :DWORD
        STDMETHOD EvaluateMode, :DWORD, :ptr DWORD
      DECLARE_INTERFACE__END

      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirectDraw7_QueryInterface macro p, a, b
          exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
        endm
        IDirectDraw7_AddRef macro p
          exitm <(p) - lpVtbl - AddRef (p)>
        endm
        IDirectDraw7_Release macro p
          exitm <(p) - lpVtbl - Release (p)>
        endm
        IDirectDraw7_Compact macro p
          exitm <(p) - lpVtbl - Compact (p)>
        endm
        IDirectDraw7_CreateClipper macro p, a, b, c_
          exitm <(p) - lpVtbl - CreateClipper (p, a, b, c_)>
        endm
        IDirectDraw7_CreatePalette macro p, a, b, c_, d
          exitm <(p) - lpVtbl - CreatePalette (p, a, b, c_, d)>
        endm
        IDirectDraw7_CreateSurface macro p, a, b, c_
          exitm <(p) - lpVtbl - CreateSurface (p, a, b, c_)>
        endm
        IDirectDraw7_DuplicateSurface macro p, a, b
          exitm <(p) - lpVtbl - DuplicateSurface (p, a, b)>
        endm
        IDirectDraw7_EnumDisplayModes macro p, a, b, c_, d
          exitm <(p) - lpVtbl - EnumDisplayModes (p, a, b, c_, d)>
        endm
        IDirectDraw7_EnumSurfaces macro p, a, b, c_, d
          exitm <(p) - lpVtbl - EnumSurfaces (p, a, b, c_, d)>
        endm
        IDirectDraw7_FlipToGDISurface macro p
          exitm <(p) - lpVtbl - FlipToGDISurface (p)>
        endm
        IDirectDraw7_GetCaps macro p, a, b
          exitm <(p) - lpVtbl - GetCaps (p, a, b)>
        endm
        IDirectDraw7_GetDisplayMode macro p, a
          exitm <(p) - lpVtbl - GetDisplayMode (p, a)>
        endm
        IDirectDraw7_GetFourCCCodes macro p, a, b
          exitm <(p) - lpVtbl - GetFourCCCodes (p, a, b)>
        endm
        IDirectDraw7_GetGDISurface macro p, a
          exitm <(p) - lpVtbl - GetGDISurface (p, a)>
        endm
        IDirectDraw7_GetMonitorFrequency macro p, a
          exitm <(p) - lpVtbl - GetMonitorFrequency (p, a)>
        endm
        IDirectDraw7_GetScanLine macro p, a
          exitm <(p) - lpVtbl - GetScanLine (p, a)>
        endm
        IDirectDraw7_GetVerticalBlankStatus macro p, a
          exitm <(p) - lpVtbl - GetVerticalBlankStatus (p, a)>
        endm
        IDirectDraw7_Initialize macro p, a
          exitm <(p) - lpVtbl - Initialize (p, a)>
        endm
        IDirectDraw7_RestoreDisplayMode macro p
          exitm <(p) - lpVtbl - RestoreDisplayMode (p)>
        endm
        IDirectDraw7_SetCooperativeLevel macro p, a, b
          exitm <(p) - lpVtbl - SetCooperativeLevel (p, a, b)>
        endm
        IDirectDraw7_SetDisplayMode macro p, a, b, c_, d, e
          exitm <(p) - lpVtbl - SetDisplayMode (p, a, b, c_, d, e)>
        endm
        IDirectDraw7_WaitForVerticalBlank macro p, a, b
          exitm <(p) - lpVtbl - WaitForVerticalBlank (p, a, b)>
        endm
        IDirectDraw7_GetAvailableVidMem macro p, a, b, c_
          exitm <(p) - lpVtbl - GetAvailableVidMem (p, a, b, c_)>
        endm
        IDirectDraw7_GetSurfaceFromDC macro p, a, b
          exitm <(p) - lpVtbl - GetSurfaceFromDC (p, a, b)>
        endm
        IDirectDraw7_RestoreAllSurfaces macro p
          exitm <(p) - lpVtbl - RestoreAllSurfaces (p)>
        endm
        IDirectDraw7_TestCooperativeLevel macro p
          exitm <(p) - lpVtbl - TestCooperativeLevel (p)>
        endm
        IDirectDraw7_GetDeviceIdentifier macro p, a, b
          exitm <(p) - lpVtbl - GetDeviceIdentifier (p, a, b)>
        endm
        IDirectDraw7_StartModeTest macro p, a, b, c_
          exitm <(p) - lpVtbl - StartModeTest (p, a, b, c_)>
        endm
        IDirectDraw7_EvaluateMode macro p, a, b
          exitm <(p) - lpVtbl - EvaluateMode (p, a, b)>
        endm
      else
        ;[...]
      endif
    endif
    ;*
    ;* IDirectDrawPalette
    ;*
    if Defined(_WIN32) and  not Defined(_NO_COM)
      INTERFACE equ <IDirectDrawPalette>
      DECLARE_INTERFACE_(IDirectDrawPalette, IUnknown)
        ??Interface equ <DDDEVICEIDENTIFIER2>
        ;*** IUnknown methods ***
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ;*** IDirectDrawPalette methods ***
        STDMETHOD GetCaps, :LPDWORD
        STDMETHOD GetEntries, :DWORD, :DWORD, :DWORD, :LPPALETTEENTRY
        STDMETHOD Initialize, :LPDIRECTDRAW, :DWORD, :LPPALETTEENTRY
        STDMETHOD SetEntries, :DWORD, :DWORD, :DWORD, :LPPALETTEENTRY
      DECLARE_INTERFACE__END

      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirectDrawPalette_QueryInterface macro p, a, b
          exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
        endm
        IDirectDrawPalette_AddRef macro p
          exitm <(p) - lpVtbl - AddRef (p)>
        endm
        IDirectDrawPalette_Release macro p
          exitm <(p) - lpVtbl - Release (p)>
        endm
        IDirectDrawPalette_GetCaps macro p, a
          exitm <(p) - lpVtbl - GetCaps (p, a)>
        endm
        IDirectDrawPalette_GetEntries macro p, a, b, c_, d
          exitm <(p) - lpVtbl - GetEntries (p, a, b, c_, d)>
        endm
        IDirectDrawPalette_Initialize macro p, a, b, c_
          exitm <(p) - lpVtbl - Initialize (p, a, b, c_)>
        endm
        IDirectDrawPalette_SetEntries macro p, a, b, c_, d
          exitm <(p) - lpVtbl - SetEntries (p, a, b, c_, d)>
        endm
      else
        ;[...]
      endif
    endif
    ;*
    ;* IDirectDrawClipper
    ;*
    if Defined(_WIN32) and  not Defined(_NO_COM)
      INTERFACE equ <IDirectDrawClipper>
      DECLARE_INTERFACE_(IDirectDrawClipper, IUnknown)
        ??Interface equ <DDDEVICEIDENTIFIER2>
        ;*** IUnknown methods ***
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ;*** IDirectDrawClipper methods ***
        STDMETHOD GetClipList, :LPRECT, :LPRGNDATA, :LPDWORD
        STDMETHOD GetHWnd, :ptr HWND
        STDMETHOD Initialize, :LPDIRECTDRAW, :DWORD
        STDMETHOD IsClipListChanged, :ptr DWORD
        STDMETHOD SetClipList, :LPRGNDATA, :DWORD
        STDMETHOD SetHWnd, :DWORD, :HWND
      DECLARE_INTERFACE__END

      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirectDrawClipper_QueryInterface macro p, a, b
          exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
        endm
        IDirectDrawClipper_AddRef macro p
          exitm <(p) - lpVtbl - AddRef (p)>
        endm
        IDirectDrawClipper_Release macro p
          exitm <(p) - lpVtbl - Release (p)>
        endm
        IDirectDrawClipper_GetClipList macro p, a, b, c_
          exitm <(p) - lpVtbl - GetClipList (p, a, b, c_)>
        endm
        IDirectDrawClipper_GetHWnd macro p, a
          exitm <(p) - lpVtbl - GetHWnd (p, a)>
        endm
        IDirectDrawClipper_Initialize macro p, a, b
          exitm <(p) - lpVtbl - Initialize (p, a, b)>
        endm
        IDirectDrawClipper_IsClipListChanged macro p, a
          exitm <(p) - lpVtbl - IsClipListChanged (p, a)>
        endm
        IDirectDrawClipper_SetClipList macro p, a, b
          exitm <(p) - lpVtbl - SetClipList (p, a, b)>
        endm
        IDirectDrawClipper_SetHWnd macro p, a, b
          exitm <(p) - lpVtbl - SetHWnd (p, a, b)>
        endm
      else
        ;[...]
      endif
    endif
    ;*
    ;* IDirectDrawSurface and related interfaces
    ;*
    if Defined(_WIN32) and  not Defined(_NO_COM)
      INTERFACE equ <IDirectDrawSurface>
      DECLARE_INTERFACE_(IDirectDrawSurface, IUnknown)
        ??Interface equ <DDDEVICEIDENTIFIER2>
        ;*** IUnknown methods ***
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ;*** IDirectDrawSurface methods ***
        STDMETHOD AddAttachedSurface, :LPDIRECTDRAWSURFACE
        STDMETHOD AddOverlayDirtyRect, :LPRECT
        STDMETHOD Blt, :LPRECT, :LPDIRECTDRAWSURFACE, :LPRECT, :DWORD, :LPDDBLTFX
        STDMETHOD BltBatch, :LPDDBLTBATCH, :DWORD, :DWORD
        STDMETHOD BltFast, :DWORD, :DWORD, :LPDIRECTDRAWSURFACE, :LPRECT, :DWORD
        STDMETHOD DeleteAttachedSurface, :DWORD, :LPDIRECTDRAWSURFACE
        STDMETHOD EnumAttachedSurfaces, :POINTER, :LPDDENUMSURFACESCALLBACK
        STDMETHOD EnumOverlayZOrders, :DWORD, :POINTER, :LPDDENUMSURFACESCALLBACK
        STDMETHOD Flip, :LPDIRECTDRAWSURFACE, :DWORD
        STDMETHOD GetAttachedSurface, :LPDDSCAPS, :ptr LPDIRECTDRAWSURFACE
        STDMETHOD GetBltStatus, :DWORD
        STDMETHOD GetCaps, :LPDDSCAPS
        STDMETHOD GetClipper, :ptr LPDIRECTDRAWCLIPPER
        STDMETHOD GetColorKey, :DWORD, :LPDDCOLORKEY
        STDMETHOD GetDC, :ptr HDC
        STDMETHOD GetFlipStatus, :DWORD
        STDMETHOD GetOverlayPosition, :LPLONG, :LPLONG
        STDMETHOD GetPalette, :ptr LPDIRECTDRAWPALETTE
        STDMETHOD GetPixelFormat, :LPDDPIXELFORMAT
        STDMETHOD GetSurfaceDesc, :LPDDSURFACEDESC
        STDMETHOD Initialize, :LPDIRECTDRAW, :LPDDSURFACEDESC
        STDMETHOD IsLost
        STDMETHOD Lock_, :LPRECT, :LPDDSURFACEDESC, :DWORD, :HANDLE
        STDMETHOD ReleaseDC, :HDC
        STDMETHOD Restore
        STDMETHOD SetClipper, :LPDIRECTDRAWCLIPPER
        STDMETHOD SetColorKey, :DWORD, :LPDDCOLORKEY
        STDMETHOD SetOverlayPosition, :SDWORD, :SDWORD
        STDMETHOD SetPalette, :LPDIRECTDRAWPALETTE
        STDMETHOD Unlock, :POINTER
        STDMETHOD UpdateOverlay, :LPRECT, :LPDIRECTDRAWSURFACE, :LPRECT, :DWORD, :LPDDOVERLAYFX
        STDMETHOD UpdateOverlayDisplay, :DWORD
        STDMETHOD UpdateOverlayZOrder, :DWORD, :LPDIRECTDRAWSURFACE
      DECLARE_INTERFACE__END

      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirectDrawSurface_QueryInterface macro p, a, b
          exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
        endm
        IDirectDrawSurface_AddRef macro p
          exitm <(p) - lpVtbl - AddRef (p)>
        endm
        IDirectDrawSurface_Release macro p
          exitm <(p) - lpVtbl - Release (p)>
        endm
        IDirectDrawSurface_AddAttachedSurface macro p, a
          exitm <(p) - lpVtbl - AddAttachedSurface (p, a)>
        endm
        IDirectDrawSurface_AddOverlayDirtyRect macro p, a
          exitm <(p) - lpVtbl - AddOverlayDirtyRect (p, a)>
        endm
        IDirectDrawSurface_Blt macro p, a, b, c_, d, e
          exitm <(p) - lpVtbl - Blt (p, a, b, c_, d, e)>
        endm
        IDirectDrawSurface_BltBatch macro p, a, b, c_
          exitm <(p) - lpVtbl - BltBatch (p, a, b, c_)>
        endm
        IDirectDrawSurface_BltFast macro p, a, b, c_, d, e
          exitm <(p) - lpVtbl - BltFast (p, a, b, c_, d, e)>
        endm
        IDirectDrawSurface_DeleteAttachedSurface macro p, a, b
          exitm <(p) - lpVtbl - DeleteAttachedSurface (p, a, b)>
        endm
        IDirectDrawSurface_EnumAttachedSurfaces macro p, a, b
          exitm <(p) - lpVtbl - EnumAttachedSurfaces (p, a, b)>
        endm
        IDirectDrawSurface_EnumOverlayZOrders macro p, a, b, c_
          exitm <(p) - lpVtbl - EnumOverlayZOrders (p, a, b, c_)>
        endm
        IDirectDrawSurface_Flip macro p, a, b
          exitm <(p) - lpVtbl - Flip (p, a, b)>
        endm
        IDirectDrawSurface_GetAttachedSurface macro p, a, b
          exitm <(p) - lpVtbl - GetAttachedSurface (p, a, b)>
        endm
        IDirectDrawSurface_GetBltStatus macro p, a
          exitm <(p) - lpVtbl - GetBltStatus (p, a)>
        endm
        IDirectDrawSurface_GetCaps macro p, b
          exitm <(p) - lpVtbl - GetCaps (p, b)>
        endm
        IDirectDrawSurface_GetClipper macro p, a
          exitm <(p) - lpVtbl - GetClipper (p, a)>
        endm
        IDirectDrawSurface_GetColorKey macro p, a, b
          exitm <(p) - lpVtbl - GetColorKey (p, a, b)>
        endm
        IDirectDrawSurface_GetDC macro p, a
          exitm <(p) - lpVtbl - GetDC (p, a)>
        endm
        IDirectDrawSurface_GetFlipStatus macro p, a
          exitm <(p) - lpVtbl - GetFlipStatus (p, a)>
        endm
        IDirectDrawSurface_GetOverlayPosition macro p, a, b
          exitm <(p) - lpVtbl - GetOverlayPosition (p, a, b)>
        endm
        IDirectDrawSurface_GetPalette macro p, a
          exitm <(p) - lpVtbl - GetPalette (p, a)>
        endm
        IDirectDrawSurface_GetPixelFormat macro p, a
          exitm <(p) - lpVtbl - GetPixelFormat (p, a)>
        endm
        IDirectDrawSurface_GetSurfaceDesc macro p, a
          exitm <(p) - lpVtbl - GetSurfaceDesc (p, a)>
        endm
        IDirectDrawSurface_Initialize macro p, a, b
          exitm <(p) - lpVtbl - Initialize (p, a, b)>
        endm
        IDirectDrawSurface_IsLost macro p
          exitm <(p) - lpVtbl - IsLost (p)>
        endm
        IDirectDrawSurface_Lock macro p, a, b, c_, d
          exitm <(p) - lpVtbl - Lock (p, a, b, c_, d)>
        endm
        IDirectDrawSurface_ReleaseDC macro p, a
          exitm <(p) - lpVtbl - ReleaseDC (p, a)>
        endm
        IDirectDrawSurface_Restore macro p
          exitm <(p) - lpVtbl - Restore (p)>
        endm
        IDirectDrawSurface_SetClipper macro p, a
          exitm <(p) - lpVtbl - SetClipper (p, a)>
        endm
        IDirectDrawSurface_SetColorKey macro p, a, b
          exitm <(p) - lpVtbl - SetColorKey (p, a, b)>
        endm
        IDirectDrawSurface_SetOverlayPosition macro p, a, b
          exitm <(p) - lpVtbl - SetOverlayPosition (p, a, b)>
        endm
        IDirectDrawSurface_SetPalette macro p, a
          exitm <(p) - lpVtbl - SetPalette (p, a)>
        endm
        IDirectDrawSurface_Unlock macro p, b
          exitm <(p) - lpVtbl - Unlock (p, b)>
        endm
        IDirectDrawSurface_UpdateOverlay macro p, a, b, c_, d, e
          exitm <(p) - lpVtbl - UpdateOverlay (p, a, b, c_, d, e)>
        endm
        IDirectDrawSurface_UpdateOverlayDisplay macro p, a
          exitm <(p) - lpVtbl - UpdateOverlayDisplay (p, a)>
        endm
        IDirectDrawSurface_UpdateOverlayZOrder macro p, a, b
          exitm <(p) - lpVtbl - UpdateOverlayZOrder (p, a, b)>
        endm
      else
        ;[...]
      endif
      ;*
      ;* IDirectDrawSurface2 and related interfaces
      ;*
      INTERFACE equ <IDirectDrawSurface2>
      DECLARE_INTERFACE_(IDirectDrawSurface2, IUnknown)
        ??Interface equ <DDDEVICEIDENTIFIER2>
        ;*** IUnknown methods ***
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ;*** IDirectDrawSurface methods ***
        STDMETHOD AddAttachedSurface, :LPDIRECTDRAWSURFACE2
        STDMETHOD AddOverlayDirtyRect, :LPRECT
        STDMETHOD Blt, :LPRECT, :LPDIRECTDRAWSURFACE2, :LPRECT, :DWORD, :LPDDBLTFX
        STDMETHOD BltBatch, :LPDDBLTBATCH, :DWORD, :DWORD
        STDMETHOD BltFast, :DWORD, :DWORD, :LPDIRECTDRAWSURFACE2, :LPRECT, :DWORD
        STDMETHOD DeleteAttachedSurface, :DWORD, :LPDIRECTDRAWSURFACE2
        STDMETHOD EnumAttachedSurfaces, :POINTER, :LPDDENUMSURFACESCALLBACK
        STDMETHOD EnumOverlayZOrders, :DWORD, :POINTER, :LPDDENUMSURFACESCALLBACK
        STDMETHOD Flip, :LPDIRECTDRAWSURFACE2, :DWORD
        STDMETHOD GetAttachedSurface, :LPDDSCAPS, :ptr LPDIRECTDRAWSURFACE2
        STDMETHOD GetBltStatus, :DWORD
        STDMETHOD GetCaps, :LPDDSCAPS
        STDMETHOD GetClipper, :ptr LPDIRECTDRAWCLIPPER
        STDMETHOD GetColorKey, :DWORD, :LPDDCOLORKEY
        STDMETHOD GetDC, :ptr HDC
        STDMETHOD GetFlipStatus, :DWORD
        STDMETHOD GetOverlayPosition, :LPLONG, :LPLONG
        STDMETHOD GetPalette, :ptr LPDIRECTDRAWPALETTE
        STDMETHOD GetPixelFormat, :LPDDPIXELFORMAT
        STDMETHOD GetSurfaceDesc, :LPDDSURFACEDESC
        STDMETHOD Initialize, :LPDIRECTDRAW, :LPDDSURFACEDESC
        STDMETHOD IsLost
        STDMETHOD Lock_, :LPRECT, :LPDDSURFACEDESC, :DWORD, :HANDLE
        STDMETHOD ReleaseDC, :HDC
        STDMETHOD Restore
        STDMETHOD SetClipper, :LPDIRECTDRAWCLIPPER
        STDMETHOD SetColorKey, :DWORD, :LPDDCOLORKEY
        STDMETHOD SetOverlayPosition, :SDWORD, :SDWORD
        STDMETHOD SetPalette, :LPDIRECTDRAWPALETTE
        STDMETHOD Unlock, :POINTER
        STDMETHOD UpdateOverlay, :LPRECT, :LPDIRECTDRAWSURFACE2, :LPRECT, :DWORD, :LPDDOVERLAYFX
        STDMETHOD UpdateOverlayDisplay, :DWORD
        STDMETHOD UpdateOverlayZOrder, :DWORD, :LPDIRECTDRAWSURFACE2
        ;*** Added in the v2 interface ***
        STDMETHOD GetDDInterface, :ptr POINTER
        STDMETHOD PageLock, :DWORD
        STDMETHOD PageUnlock, :DWORD
      DECLARE_INTERFACE__END

      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirectDrawSurface2_QueryInterface macro p, a, b
          exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
        endm
        IDirectDrawSurface2_AddRef macro p
          exitm <(p) - lpVtbl - AddRef (p)>
        endm
        IDirectDrawSurface2_Release macro p
          exitm <(p) - lpVtbl - Release (p)>
        endm
        IDirectDrawSurface2_AddAttachedSurface macro p, a
          exitm <(p) - lpVtbl - AddAttachedSurface (p, a)>
        endm
        IDirectDrawSurface2_AddOverlayDirtyRect macro p, a
          exitm <(p) - lpVtbl - AddOverlayDirtyRect (p, a)>
        endm
        IDirectDrawSurface2_Blt macro p, a, b, c_, d, e
          exitm <(p) - lpVtbl - Blt (p, a, b, c_, d, e)>
        endm
        IDirectDrawSurface2_BltBatch macro p, a, b, c_
          exitm <(p) - lpVtbl - BltBatch (p, a, b, c_)>
        endm
        IDirectDrawSurface2_BltFast macro p, a, b, c_, d, e
          exitm <(p) - lpVtbl - BltFast (p, a, b, c_, d, e)>
        endm
        IDirectDrawSurface2_DeleteAttachedSurface macro p, a, b
          exitm <(p) - lpVtbl - DeleteAttachedSurface (p, a, b)>
        endm
        IDirectDrawSurface2_EnumAttachedSurfaces macro p, a, b
          exitm <(p) - lpVtbl - EnumAttachedSurfaces (p, a, b)>
        endm
        IDirectDrawSurface2_EnumOverlayZOrders macro p, a, b, c_
          exitm <(p) - lpVtbl - EnumOverlayZOrders (p, a, b, c_)>
        endm
        IDirectDrawSurface2_Flip macro p, a, b
          exitm <(p) - lpVtbl - Flip (p, a, b)>
        endm
        IDirectDrawSurface2_GetAttachedSurface macro p, a, b
          exitm <(p) - lpVtbl - GetAttachedSurface (p, a, b)>
        endm
        IDirectDrawSurface2_GetBltStatus macro p, a
          exitm <(p) - lpVtbl - GetBltStatus (p, a)>
        endm
        IDirectDrawSurface2_GetCaps macro p, b
          exitm <(p) - lpVtbl - GetCaps (p, b)>
        endm
        IDirectDrawSurface2_GetClipper macro p, a
          exitm <(p) - lpVtbl - GetClipper (p, a)>
        endm
        IDirectDrawSurface2_GetColorKey macro p, a, b
          exitm <(p) - lpVtbl - GetColorKey (p, a, b)>
        endm
        IDirectDrawSurface2_GetDC macro p, a
          exitm <(p) - lpVtbl - GetDC (p, a)>
        endm
        IDirectDrawSurface2_GetFlipStatus macro p, a
          exitm <(p) - lpVtbl - GetFlipStatus (p, a)>
        endm
        IDirectDrawSurface2_GetOverlayPosition macro p, a, b
          exitm <(p) - lpVtbl - GetOverlayPosition (p, a, b)>
        endm
        IDirectDrawSurface2_GetPalette macro p, a
          exitm <(p) - lpVtbl - GetPalette (p, a)>
        endm
        IDirectDrawSurface2_GetPixelFormat macro p, a
          exitm <(p) - lpVtbl - GetPixelFormat (p, a)>
        endm
        IDirectDrawSurface2_GetSurfaceDesc macro p, a
          exitm <(p) - lpVtbl - GetSurfaceDesc (p, a)>
        endm
        IDirectDrawSurface2_Initialize macro p, a, b
          exitm <(p) - lpVtbl - Initialize (p, a, b)>
        endm
        IDirectDrawSurface2_IsLost macro p
          exitm <(p) - lpVtbl - IsLost (p)>
        endm
        IDirectDrawSurface2_Lock macro p, a, b, c_, d
          exitm <(p) - lpVtbl - Lock (p, a, b, c_, d)>
        endm
        IDirectDrawSurface2_ReleaseDC macro p, a
          exitm <(p) - lpVtbl - ReleaseDC (p, a)>
        endm
        IDirectDrawSurface2_Restore macro p
          exitm <(p) - lpVtbl - Restore (p)>
        endm
        IDirectDrawSurface2_SetClipper macro p, a
          exitm <(p) - lpVtbl - SetClipper (p, a)>
        endm
        IDirectDrawSurface2_SetColorKey macro p, a, b
          exitm <(p) - lpVtbl - SetColorKey (p, a, b)>
        endm
        IDirectDrawSurface2_SetOverlayPosition macro p, a, b
          exitm <(p) - lpVtbl - SetOverlayPosition (p, a, b)>
        endm
        IDirectDrawSurface2_SetPalette macro p, a
          exitm <(p) - lpVtbl - SetPalette (p, a)>
        endm
        IDirectDrawSurface2_Unlock macro p, b
          exitm <(p) - lpVtbl - Unlock (p, b)>
        endm
        IDirectDrawSurface2_UpdateOverlay macro p, a, b, c_, d, e
          exitm <(p) - lpVtbl - UpdateOverlay (p, a, b, c_, d, e)>
        endm
        IDirectDrawSurface2_UpdateOverlayDisplay macro p, a
          exitm <(p) - lpVtbl - UpdateOverlayDisplay (p, a)>
        endm
        IDirectDrawSurface2_UpdateOverlayZOrder macro p, a, b
          exitm <(p) - lpVtbl - UpdateOverlayZOrder (p, a, b)>
        endm
        IDirectDrawSurface2_GetDDInterface macro p, a
          exitm <(p) - lpVtbl - GetDDInterface (p, a)>
        endm
        IDirectDrawSurface2_PageLock macro p, a
          exitm <(p) - lpVtbl - PageLock (p, a)>
        endm
        IDirectDrawSurface2_PageUnlock macro p, a
          exitm <(p) - lpVtbl - PageUnlock (p, a)>
        endm
      else
        ;[...]
      endif
      ;*
      ;* IDirectDrawSurface3 and related interfaces
      ;*
      INTERFACE equ <IDirectDrawSurface3>
      DECLARE_INTERFACE_(IDirectDrawSurface3, IUnknown)
        ??Interface equ <DDDEVICEIDENTIFIER2>
        ;*** IUnknown methods ***
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ;*** IDirectDrawSurface methods ***
        STDMETHOD AddAttachedSurface, :LPDIRECTDRAWSURFACE3
        STDMETHOD AddOverlayDirtyRect, :LPRECT
        STDMETHOD Blt, :LPRECT, :LPDIRECTDRAWSURFACE3, :LPRECT, :DWORD, :LPDDBLTFX
        STDMETHOD BltBatch, :LPDDBLTBATCH, :DWORD, :DWORD
        STDMETHOD BltFast, :DWORD, :DWORD, :LPDIRECTDRAWSURFACE3, :LPRECT, :DWORD
        STDMETHOD DeleteAttachedSurface, :DWORD, :LPDIRECTDRAWSURFACE3
        STDMETHOD EnumAttachedSurfaces, :POINTER, :LPDDENUMSURFACESCALLBACK
        STDMETHOD EnumOverlayZOrders, :DWORD, :POINTER, :LPDDENUMSURFACESCALLBACK
        STDMETHOD Flip, :LPDIRECTDRAWSURFACE3, :DWORD
        STDMETHOD GetAttachedSurface, :LPDDSCAPS, :ptr LPDIRECTDRAWSURFACE3
        STDMETHOD GetBltStatus, :DWORD
        STDMETHOD GetCaps, :LPDDSCAPS
        STDMETHOD GetClipper, :ptr LPDIRECTDRAWCLIPPER
        STDMETHOD GetColorKey, :DWORD, :LPDDCOLORKEY
        STDMETHOD GetDC, :ptr HDC
        STDMETHOD GetFlipStatus, :DWORD
        STDMETHOD GetOverlayPosition, :LPLONG, :LPLONG
        STDMETHOD GetPalette, :ptr LPDIRECTDRAWPALETTE
        STDMETHOD GetPixelFormat, :LPDDPIXELFORMAT
        STDMETHOD GetSurfaceDesc, :LPDDSURFACEDESC
        STDMETHOD Initialize, :LPDIRECTDRAW, :LPDDSURFACEDESC
        STDMETHOD IsLost
        STDMETHOD Lock_, :LPRECT, :LPDDSURFACEDESC, :DWORD, :HANDLE
        STDMETHOD ReleaseDC, :HDC
        STDMETHOD Restore
        STDMETHOD SetClipper, :LPDIRECTDRAWCLIPPER
        STDMETHOD SetColorKey, :DWORD, :LPDDCOLORKEY
        STDMETHOD SetOverlayPosition, :SDWORD, :SDWORD
        STDMETHOD SetPalette, :LPDIRECTDRAWPALETTE
        STDMETHOD Unlock, :POINTER
        STDMETHOD UpdateOverlay, :LPRECT, :LPDIRECTDRAWSURFACE3, :LPRECT, :DWORD, :LPDDOVERLAYFX
        STDMETHOD UpdateOverlayDisplay, :DWORD
        STDMETHOD UpdateOverlayZOrder, :DWORD, :LPDIRECTDRAWSURFACE3
        ;*** Added in the v2 interface ***
        STDMETHOD GetDDInterface, :ptr POINTER
        STDMETHOD PageLock, :DWORD
        STDMETHOD PageUnlock, :DWORD
        ;*** Added in the V3 interface ***
        STDMETHOD SetSurfaceDesc, :LPDDSURFACEDESC, :DWORD
      DECLARE_INTERFACE__END

      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirectDrawSurface3_QueryInterface macro p, a, b
          exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
        endm
        IDirectDrawSurface3_AddRef macro p
          exitm <(p) - lpVtbl - AddRef (p)>
        endm
        IDirectDrawSurface3_Release macro p
          exitm <(p) - lpVtbl - Release (p)>
        endm
        IDirectDrawSurface3_AddAttachedSurface macro p, a
          exitm <(p) - lpVtbl - AddAttachedSurface (p, a)>
        endm
        IDirectDrawSurface3_AddOverlayDirtyRect macro p, a
          exitm <(p) - lpVtbl - AddOverlayDirtyRect (p, a)>
        endm
        IDirectDrawSurface3_Blt macro p, a, b, c_, d, e
          exitm <(p) - lpVtbl - Blt (p, a, b, c_, d, e)>
        endm
        IDirectDrawSurface3_BltBatch macro p, a, b, c_
          exitm <(p) - lpVtbl - BltBatch (p, a, b, c_)>
        endm
        IDirectDrawSurface3_BltFast macro p, a, b, c_, d, e
          exitm <(p) - lpVtbl - BltFast (p, a, b, c_, d, e)>
        endm
        IDirectDrawSurface3_DeleteAttachedSurface macro p, a, b
          exitm <(p) - lpVtbl - DeleteAttachedSurface (p, a, b)>
        endm
        IDirectDrawSurface3_EnumAttachedSurfaces macro p, a, b
          exitm <(p) - lpVtbl - EnumAttachedSurfaces (p, a, b)>
        endm
        IDirectDrawSurface3_EnumOverlayZOrders macro p, a, b, c_
          exitm <(p) - lpVtbl - EnumOverlayZOrders (p, a, b, c_)>
        endm
        IDirectDrawSurface3_Flip macro p, a, b
          exitm <(p) - lpVtbl - Flip (p, a, b)>
        endm
        IDirectDrawSurface3_GetAttachedSurface macro p, a, b
          exitm <(p) - lpVtbl - GetAttachedSurface (p, a, b)>
        endm
        IDirectDrawSurface3_GetBltStatus macro p, a
          exitm <(p) - lpVtbl - GetBltStatus (p, a)>
        endm
        IDirectDrawSurface3_GetCaps macro p, b
          exitm <(p) - lpVtbl - GetCaps (p, b)>
        endm
        IDirectDrawSurface3_GetClipper macro p, a
          exitm <(p) - lpVtbl - GetClipper (p, a)>
        endm
        IDirectDrawSurface3_GetColorKey macro p, a, b
          exitm <(p) - lpVtbl - GetColorKey (p, a, b)>
        endm
        IDirectDrawSurface3_GetDC macro p, a
          exitm <(p) - lpVtbl - GetDC (p, a)>
        endm
        IDirectDrawSurface3_GetFlipStatus macro p, a
          exitm <(p) - lpVtbl - GetFlipStatus (p, a)>
        endm
        IDirectDrawSurface3_GetOverlayPosition macro p, a, b
          exitm <(p) - lpVtbl - GetOverlayPosition (p, a, b)>
        endm
        IDirectDrawSurface3_GetPalette macro p, a
          exitm <(p) - lpVtbl - GetPalette (p, a)>
        endm
        IDirectDrawSurface3_GetPixelFormat macro p, a
          exitm <(p) - lpVtbl - GetPixelFormat (p, a)>
        endm
        IDirectDrawSurface3_GetSurfaceDesc macro p, a
          exitm <(p) - lpVtbl - GetSurfaceDesc (p, a)>
        endm
        IDirectDrawSurface3_Initialize macro p, a, b
          exitm <(p) - lpVtbl - Initialize (p, a, b)>
        endm
        IDirectDrawSurface3_IsLost macro p
          exitm <(p) - lpVtbl - IsLost (p)>
        endm
        IDirectDrawSurface3_Lock macro p, a, b, c_, d
          exitm <(p) - lpVtbl - Lock (p, a, b, c_, d)>
        endm
        IDirectDrawSurface3_ReleaseDC macro p, a
          exitm <(p) - lpVtbl - ReleaseDC (p, a)>
        endm
        IDirectDrawSurface3_Restore macro p
          exitm <(p) - lpVtbl - Restore (p)>
        endm
        IDirectDrawSurface3_SetClipper macro p, a
          exitm <(p) - lpVtbl - SetClipper (p, a)>
        endm
        IDirectDrawSurface3_SetColorKey macro p, a, b
          exitm <(p) - lpVtbl - SetColorKey (p, a, b)>
        endm
        IDirectDrawSurface3_SetOverlayPosition macro p, a, b
          exitm <(p) - lpVtbl - SetOverlayPosition (p, a, b)>
        endm
        IDirectDrawSurface3_SetPalette macro p, a
          exitm <(p) - lpVtbl - SetPalette (p, a)>
        endm
        IDirectDrawSurface3_Unlock macro p, b
          exitm <(p) - lpVtbl - Unlock (p, b)>
        endm
        IDirectDrawSurface3_UpdateOverlay macro p, a, b, c_, d, e
          exitm <(p) - lpVtbl - UpdateOverlay (p, a, b, c_, d, e)>
        endm
        IDirectDrawSurface3_UpdateOverlayDisplay macro p, a
          exitm <(p) - lpVtbl - UpdateOverlayDisplay (p, a)>
        endm
        IDirectDrawSurface3_UpdateOverlayZOrder macro p, a, b
          exitm <(p) - lpVtbl - UpdateOverlayZOrder (p, a, b)>
        endm
        IDirectDrawSurface3_GetDDInterface macro p, a
          exitm <(p) - lpVtbl - GetDDInterface (p, a)>
        endm
        IDirectDrawSurface3_PageLock macro p, a
          exitm <(p) - lpVtbl - PageLock (p, a)>
        endm
        IDirectDrawSurface3_PageUnlock macro p, a
          exitm <(p) - lpVtbl - PageUnlock (p, a)>
        endm
        IDirectDrawSurface3_SetSurfaceDesc macro p, a, b
          exitm <(p) - lpVtbl - SetSurfaceDesc (p, a, b)>
        endm
      else
        ;[...]
      endif
      ;*
      ;* IDirectDrawSurface4 and related interfaces
      ;*
      INTERFACE equ <IDirectDrawSurface4>
      DECLARE_INTERFACE_(IDirectDrawSurface4, IUnknown)
        ??Interface equ <DDDEVICEIDENTIFIER2>
        ;*** IUnknown methods ***
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ;*** IDirectDrawSurface methods ***
        STDMETHOD AddAttachedSurface, :LPDIRECTDRAWSURFACE4
        STDMETHOD AddOverlayDirtyRect, :LPRECT
        STDMETHOD Blt, :LPRECT, :LPDIRECTDRAWSURFACE4, :LPRECT, :DWORD, :LPDDBLTFX
        STDMETHOD BltBatch, :LPDDBLTBATCH, :DWORD, :DWORD
        STDMETHOD BltFast, :DWORD, :DWORD, :LPDIRECTDRAWSURFACE4, :LPRECT, :DWORD
        STDMETHOD DeleteAttachedSurface, :DWORD, :LPDIRECTDRAWSURFACE4
        STDMETHOD EnumAttachedSurfaces, :POINTER, :LPDDENUMSURFACESCALLBACK2
        STDMETHOD EnumOverlayZOrders, :DWORD, :POINTER, :LPDDENUMSURFACESCALLBACK2
        STDMETHOD Flip, :LPDIRECTDRAWSURFACE4, :DWORD
        STDMETHOD GetAttachedSurface, :LPDDSCAPS2, :ptr LPDIRECTDRAWSURFACE4
        STDMETHOD GetBltStatus, :DWORD
        STDMETHOD GetCaps, :LPDDSCAPS2
        STDMETHOD GetClipper, :ptr LPDIRECTDRAWCLIPPER
        STDMETHOD GetColorKey, :DWORD, :LPDDCOLORKEY
        STDMETHOD GetDC, :ptr HDC
        STDMETHOD GetFlipStatus, :DWORD
        STDMETHOD GetOverlayPosition, :LPLONG, :LPLONG
        STDMETHOD GetPalette, :ptr LPDIRECTDRAWPALETTE
        STDMETHOD GetPixelFormat, :LPDDPIXELFORMAT
        STDMETHOD GetSurfaceDesc, :LPDDSURFACEDESC2
        STDMETHOD Initialize, :LPDIRECTDRAW, :LPDDSURFACEDESC2
        STDMETHOD IsLost
        STDMETHOD Lock_, :LPRECT, :LPDDSURFACEDESC2, :DWORD, :HANDLE
        STDMETHOD ReleaseDC, :HDC
        STDMETHOD Restore
        STDMETHOD SetClipper, :LPDIRECTDRAWCLIPPER
        STDMETHOD SetColorKey, :DWORD, :LPDDCOLORKEY
        STDMETHOD SetOverlayPosition, :SDWORD, :SDWORD
        STDMETHOD SetPalette, :LPDIRECTDRAWPALETTE
        STDMETHOD Unlock, :LPRECT
        STDMETHOD UpdateOverlay, :LPRECT, :LPDIRECTDRAWSURFACE4, :LPRECT, :DWORD, :LPDDOVERLAYFX
        STDMETHOD UpdateOverlayDisplay, :DWORD
        STDMETHOD UpdateOverlayZOrder, :DWORD, :LPDIRECTDRAWSURFACE4
        ;*** Added in the v2 interface ***
        STDMETHOD GetDDInterface, :ptr POINTER
        STDMETHOD PageLock, :DWORD
        STDMETHOD PageUnlock, :DWORD
        ;*** Added in the v3 interface ***
        STDMETHOD SetSurfaceDesc, :LPDDSURFACEDESC2, :DWORD
        ;*** Added in the v4 interface ***
        STDMETHOD SetPrivateData, :REFGUID, :POINTER, :DWORD, :DWORD
        STDMETHOD GetPrivateData, :REFGUID, :POINTER, :LPDWORD
        STDMETHOD FreePrivateData, :REFGUID
        STDMETHOD GetUniquenessValue, :LPDWORD
        STDMETHOD ChangeUniquenessValue
      DECLARE_INTERFACE__END

      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirectDrawSurface4_QueryInterface macro p, a, b
          exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
        endm
        IDirectDrawSurface4_AddRef macro p
          exitm <(p) - lpVtbl - AddRef (p)>
        endm
        IDirectDrawSurface4_Release macro p
          exitm <(p) - lpVtbl - Release (p)>
        endm
        IDirectDrawSurface4_AddAttachedSurface macro p, a
          exitm <(p) - lpVtbl - AddAttachedSurface (p, a)>
        endm
        IDirectDrawSurface4_AddOverlayDirtyRect macro p, a
          exitm <(p) - lpVtbl - AddOverlayDirtyRect (p, a)>
        endm
        IDirectDrawSurface4_Blt macro p, a, b, c_, d, e
          exitm <(p) - lpVtbl - Blt (p, a, b, c_, d, e)>
        endm
        IDirectDrawSurface4_BltBatch macro p, a, b, c_
          exitm <(p) - lpVtbl - BltBatch (p, a, b, c_)>
        endm
        IDirectDrawSurface4_BltFast macro p, a, b, c_, d, e
          exitm <(p) - lpVtbl - BltFast (p, a, b, c_, d, e)>
        endm
        IDirectDrawSurface4_DeleteAttachedSurface macro p, a, b
          exitm <(p) - lpVtbl - DeleteAttachedSurface (p, a, b)>
        endm
        IDirectDrawSurface4_EnumAttachedSurfaces macro p, a, b
          exitm <(p) - lpVtbl - EnumAttachedSurfaces (p, a, b)>
        endm
        IDirectDrawSurface4_EnumOverlayZOrders macro p, a, b, c_
          exitm <(p) - lpVtbl - EnumOverlayZOrders (p, a, b, c_)>
        endm
        IDirectDrawSurface4_Flip macro p, a, b
          exitm <(p) - lpVtbl - Flip (p, a, b)>
        endm
        IDirectDrawSurface4_GetAttachedSurface macro p, a, b
          exitm <(p) - lpVtbl - GetAttachedSurface (p, a, b)>
        endm
        IDirectDrawSurface4_GetBltStatus macro p, a
          exitm <(p) - lpVtbl - GetBltStatus (p, a)>
        endm
        IDirectDrawSurface4_GetCaps macro p, b
          exitm <(p) - lpVtbl - GetCaps (p, b)>
        endm
        IDirectDrawSurface4_GetClipper macro p, a
          exitm <(p) - lpVtbl - GetClipper (p, a)>
        endm
        IDirectDrawSurface4_GetColorKey macro p, a, b
          exitm <(p) - lpVtbl - GetColorKey (p, a, b)>
        endm
        IDirectDrawSurface4_GetDC macro p, a
          exitm <(p) - lpVtbl - GetDC (p, a)>
        endm
        IDirectDrawSurface4_GetFlipStatus macro p, a
          exitm <(p) - lpVtbl - GetFlipStatus (p, a)>
        endm
        IDirectDrawSurface4_GetOverlayPosition macro p, a, b
          exitm <(p) - lpVtbl - GetOverlayPosition (p, a, b)>
        endm
        IDirectDrawSurface4_GetPalette macro p, a
          exitm <(p) - lpVtbl - GetPalette (p, a)>
        endm
        IDirectDrawSurface4_GetPixelFormat macro p, a
          exitm <(p) - lpVtbl - GetPixelFormat (p, a)>
        endm
        IDirectDrawSurface4_GetSurfaceDesc macro p, a
          exitm <(p) - lpVtbl - GetSurfaceDesc (p, a)>
        endm
        IDirectDrawSurface4_Initialize macro p, a, b
          exitm <(p) - lpVtbl - Initialize (p, a, b)>
        endm
        IDirectDrawSurface4_IsLost macro p
          exitm <(p) - lpVtbl - IsLost (p)>
        endm
        IDirectDrawSurface4_Lock macro p, a, b, c_, d
          exitm <(p) - lpVtbl - Lock (p, a, b, c_, d)>
        endm
        IDirectDrawSurface4_ReleaseDC macro p, a
          exitm <(p) - lpVtbl - ReleaseDC (p, a)>
        endm
        IDirectDrawSurface4_Restore macro p
          exitm <(p) - lpVtbl - Restore (p)>
        endm
        IDirectDrawSurface4_SetClipper macro p, a
          exitm <(p) - lpVtbl - SetClipper (p, a)>
        endm
        IDirectDrawSurface4_SetColorKey macro p, a, b
          exitm <(p) - lpVtbl - SetColorKey (p, a, b)>
        endm
        IDirectDrawSurface4_SetOverlayPosition macro p, a, b
          exitm <(p) - lpVtbl - SetOverlayPosition (p, a, b)>
        endm
        IDirectDrawSurface4_SetPalette macro p, a
          exitm <(p) - lpVtbl - SetPalette (p, a)>
        endm
        IDirectDrawSurface4_Unlock macro p, b
          exitm <(p) - lpVtbl - Unlock (p, b)>
        endm
        IDirectDrawSurface4_UpdateOverlay macro p, a, b, c_, d, e
          exitm <(p) - lpVtbl - UpdateOverlay (p, a, b, c_, d, e)>
        endm
        IDirectDrawSurface4_UpdateOverlayDisplay macro p, a
          exitm <(p) - lpVtbl - UpdateOverlayDisplay (p, a)>
        endm
        IDirectDrawSurface4_UpdateOverlayZOrder macro p, a, b
          exitm <(p) - lpVtbl - UpdateOverlayZOrder (p, a, b)>
        endm
        IDirectDrawSurface4_GetDDInterface macro p, a
          exitm <(p) - lpVtbl - GetDDInterface (p, a)>
        endm
        IDirectDrawSurface4_PageLock macro p, a
          exitm <(p) - lpVtbl - PageLock (p, a)>
        endm
        IDirectDrawSurface4_PageUnlock macro p, a
          exitm <(p) - lpVtbl - PageUnlock (p, a)>
        endm
        IDirectDrawSurface4_SetSurfaceDesc macro p, a, b
          exitm <(p) - lpVtbl - SetSurfaceDesc (p, a, b)>
        endm
        IDirectDrawSurface4_SetPrivateData macro p, a, b, c_, d
          exitm <(p) - lpVtbl - SetPrivateData (p, a, b, c_, d)>
        endm
        IDirectDrawSurface4_GetPrivateData macro p, a, b, c_
          exitm <(p) - lpVtbl - GetPrivateData (p, a, b, c_)>
        endm
        IDirectDrawSurface4_FreePrivateData macro p, a
          exitm <(p) - lpVtbl - FreePrivateData (p, a)>
        endm
        IDirectDrawSurface4_GetUniquenessValue macro p, a
          exitm <(p) - lpVtbl - GetUniquenessValue (p, a)>
        endm
        IDirectDrawSurface4_ChangeUniquenessValue macro p
          exitm <(p) - lpVtbl - ChangeUniquenessValue (p)>
        endm
      else
        ;[...]
      endif
      ;*
      ;* IDirectDrawSurface7 and related interfaces
      ;*
      INTERFACE equ <IDirectDrawSurface7>
      DECLARE_INTERFACE_(IDirectDrawSurface7, IUnknown)
        ??Interface equ <DDDEVICEIDENTIFIER2>
        ;*** IUnknown methods ***
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ;*** IDirectDrawSurface methods ***
        STDMETHOD AddAttachedSurface, :LPDIRECTDRAWSURFACE7
        STDMETHOD AddOverlayDirtyRect, :LPRECT
        STDMETHOD Blt, :LPRECT, :LPDIRECTDRAWSURFACE7, :LPRECT, :DWORD, :LPDDBLTFX
        STDMETHOD BltBatch, :LPDDBLTBATCH, :DWORD, :DWORD
        STDMETHOD BltFast, :DWORD, :DWORD, :LPDIRECTDRAWSURFACE7, :LPRECT, :DWORD
        STDMETHOD DeleteAttachedSurface, :DWORD, :LPDIRECTDRAWSURFACE7
        STDMETHOD EnumAttachedSurfaces, :POINTER, :LPDDENUMSURFACESCALLBACK7
        STDMETHOD EnumOverlayZOrders, :DWORD, :POINTER, :LPDDENUMSURFACESCALLBACK7
        STDMETHOD Flip, :LPDIRECTDRAWSURFACE7, :DWORD
        STDMETHOD GetAttachedSurface, :LPDDSCAPS2, :ptr LPDIRECTDRAWSURFACE7
        STDMETHOD GetBltStatus, :DWORD
        STDMETHOD GetCaps, :LPDDSCAPS2
        STDMETHOD GetClipper, :ptr LPDIRECTDRAWCLIPPER
        STDMETHOD GetColorKey, :DWORD, :LPDDCOLORKEY
        STDMETHOD GetDC, :ptr HDC
        STDMETHOD GetFlipStatus, :DWORD
        STDMETHOD GetOverlayPosition, :LPLONG, :LPLONG
        STDMETHOD GetPalette, :ptr LPDIRECTDRAWPALETTE
        STDMETHOD GetPixelFormat, :LPDDPIXELFORMAT
        STDMETHOD GetSurfaceDesc, :LPDDSURFACEDESC2
        STDMETHOD Initialize, :LPDIRECTDRAW, :LPDDSURFACEDESC2
        STDMETHOD IsLost
        STDMETHOD Lock_, :LPRECT, :LPDDSURFACEDESC2, :DWORD, :HANDLE
        STDMETHOD ReleaseDC, :HDC
        STDMETHOD Restore
        STDMETHOD SetClipper, :LPDIRECTDRAWCLIPPER
        STDMETHOD SetColorKey, :DWORD, :LPDDCOLORKEY
        STDMETHOD SetOverlayPosition, :SDWORD, :SDWORD
        STDMETHOD SetPalette, :LPDIRECTDRAWPALETTE
        STDMETHOD Unlock, :LPRECT
        STDMETHOD UpdateOverlay, :LPRECT, :LPDIRECTDRAWSURFACE7, :LPRECT, :DWORD, :LPDDOVERLAYFX
        STDMETHOD UpdateOverlayDisplay, :DWORD
        STDMETHOD UpdateOverlayZOrder, :DWORD, :LPDIRECTDRAWSURFACE7
        ;*** Added in the v2 interface ***
        STDMETHOD GetDDInterface, :ptr POINTER
        STDMETHOD PageLock, :DWORD
        STDMETHOD PageUnlock, :DWORD
        ;*** Added in the v3 interface ***
        STDMETHOD SetSurfaceDesc, :LPDDSURFACEDESC2, :DWORD
        ;*** Added in the v4 interface ***
        STDMETHOD SetPrivateData, :REFGUID, :POINTER, :DWORD, :DWORD
        STDMETHOD GetPrivateData, :REFGUID, :POINTER, :LPDWORD
        STDMETHOD FreePrivateData, :REFGUID
        STDMETHOD GetUniquenessValue, :LPDWORD
        STDMETHOD ChangeUniquenessValue
        ;*** Moved Texture7 methods here ***
        STDMETHOD SetPriority, :DWORD
        STDMETHOD GetPriority, :LPDWORD
        STDMETHOD SetLOD, :DWORD
        STDMETHOD GetLOD, :LPDWORD
      DECLARE_INTERFACE__END

      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirectDrawSurface7_QueryInterface macro p, a, b
          exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
        endm
        IDirectDrawSurface7_AddRef macro p
          exitm <(p) - lpVtbl - AddRef (p)>
        endm
        IDirectDrawSurface7_Release macro p
          exitm <(p) - lpVtbl - Release (p)>
        endm
        IDirectDrawSurface7_AddAttachedSurface macro p, a
          exitm <(p) - lpVtbl - AddAttachedSurface (p, a)>
        endm
        IDirectDrawSurface7_AddOverlayDirtyRect macro p, a
          exitm <(p) - lpVtbl - AddOverlayDirtyRect (p, a)>
        endm
        IDirectDrawSurface7_Blt macro p, a, b, c_, d, e
          exitm <(p) - lpVtbl - Blt (p, a, b, c_, d, e)>
        endm
        IDirectDrawSurface7_BltBatch macro p, a, b, c_
          exitm <(p) - lpVtbl - BltBatch (p, a, b, c_)>
        endm
        IDirectDrawSurface7_BltFast macro p, a, b, c_, d, e
          exitm <(p) - lpVtbl - BltFast (p, a, b, c_, d, e)>
        endm
        IDirectDrawSurface7_DeleteAttachedSurface macro p, a, b
          exitm <(p) - lpVtbl - DeleteAttachedSurface (p, a, b)>
        endm
        IDirectDrawSurface7_EnumAttachedSurfaces macro p, a, b
          exitm <(p) - lpVtbl - EnumAttachedSurfaces (p, a, b)>
        endm
        IDirectDrawSurface7_EnumOverlayZOrders macro p, a, b, c_
          exitm <(p) - lpVtbl - EnumOverlayZOrders (p, a, b, c_)>
        endm
        IDirectDrawSurface7_Flip macro p, a, b
          exitm <(p) - lpVtbl - Flip (p, a, b)>
        endm
        IDirectDrawSurface7_GetAttachedSurface macro p, a, b
          exitm <(p) - lpVtbl - GetAttachedSurface (p, a, b)>
        endm
        IDirectDrawSurface7_GetBltStatus macro p, a
          exitm <(p) - lpVtbl - GetBltStatus (p, a)>
        endm
        IDirectDrawSurface7_GetCaps macro p, b
          exitm <(p) - lpVtbl - GetCaps (p, b)>
        endm
        IDirectDrawSurface7_GetClipper macro p, a
          exitm <(p) - lpVtbl - GetClipper (p, a)>
        endm
        IDirectDrawSurface7_GetColorKey macro p, a, b
          exitm <(p) - lpVtbl - GetColorKey (p, a, b)>
        endm
        IDirectDrawSurface7_GetDC macro p, a
          exitm <(p) - lpVtbl - GetDC (p, a)>
        endm
        IDirectDrawSurface7_GetFlipStatus macro p, a
          exitm <(p) - lpVtbl - GetFlipStatus (p, a)>
        endm
        IDirectDrawSurface7_GetOverlayPosition macro p, a, b
          exitm <(p) - lpVtbl - GetOverlayPosition (p, a, b)>
        endm
        IDirectDrawSurface7_GetPalette macro p, a
          exitm <(p) - lpVtbl - GetPalette (p, a)>
        endm
        IDirectDrawSurface7_GetPixelFormat macro p, a
          exitm <(p) - lpVtbl - GetPixelFormat (p, a)>
        endm
        IDirectDrawSurface7_GetSurfaceDesc macro p, a
          exitm <(p) - lpVtbl - GetSurfaceDesc (p, a)>
        endm
        IDirectDrawSurface7_Initialize macro p, a, b
          exitm <(p) - lpVtbl - Initialize (p, a, b)>
        endm
        IDirectDrawSurface7_IsLost macro p
          exitm <(p) - lpVtbl - IsLost (p)>
        endm
        IDirectDrawSurface7_Lock macro p, a, b, c_, d
          exitm <(p) - lpVtbl - Lock (p, a, b, c_, d)>
        endm
        IDirectDrawSurface7_ReleaseDC macro p, a
          exitm <(p) - lpVtbl - ReleaseDC (p, a)>
        endm
        IDirectDrawSurface7_Restore macro p
          exitm <(p) - lpVtbl - Restore (p)>
        endm
        IDirectDrawSurface7_SetClipper macro p, a
          exitm <(p) - lpVtbl - SetClipper (p, a)>
        endm
        IDirectDrawSurface7_SetColorKey macro p, a, b
          exitm <(p) - lpVtbl - SetColorKey (p, a, b)>
        endm
        IDirectDrawSurface7_SetOverlayPosition macro p, a, b
          exitm <(p) - lpVtbl - SetOverlayPosition (p, a, b)>
        endm
        IDirectDrawSurface7_SetPalette macro p, a
          exitm <(p) - lpVtbl - SetPalette (p, a)>
        endm
        IDirectDrawSurface7_Unlock macro p, b
          exitm <(p) - lpVtbl - Unlock (p, b)>
        endm
        IDirectDrawSurface7_UpdateOverlay macro p, a, b, c_, d, e
          exitm <(p) - lpVtbl - UpdateOverlay (p, a, b, c_, d, e)>
        endm
        IDirectDrawSurface7_UpdateOverlayDisplay macro p, a
          exitm <(p) - lpVtbl - UpdateOverlayDisplay (p, a)>
        endm
        IDirectDrawSurface7_UpdateOverlayZOrder macro p, a, b
          exitm <(p) - lpVtbl - UpdateOverlayZOrder (p, a, b)>
        endm
        IDirectDrawSurface7_GetDDInterface macro p, a
          exitm <(p) - lpVtbl - GetDDInterface (p, a)>
        endm
        IDirectDrawSurface7_PageLock macro p, a
          exitm <(p) - lpVtbl - PageLock (p, a)>
        endm
        IDirectDrawSurface7_PageUnlock macro p, a
          exitm <(p) - lpVtbl - PageUnlock (p, a)>
        endm
        IDirectDrawSurface7_SetSurfaceDesc macro p, a, b
          exitm <(p) - lpVtbl - SetSurfaceDesc (p, a, b)>
        endm
        IDirectDrawSurface7_SetPrivateData macro p, a, b, c_, d
          exitm <(p) - lpVtbl - SetPrivateData (p, a, b, c_, d)>
        endm
        IDirectDrawSurface7_GetPrivateData macro p, a, b, c_
          exitm <(p) - lpVtbl - GetPrivateData (p, a, b, c_)>
        endm
        IDirectDrawSurface7_FreePrivateData macro p, a
          exitm <(p) - lpVtbl - FreePrivateData (p, a)>
        endm
        IDirectDrawSurface7_GetUniquenessValue macro p, a
          exitm <(p) - lpVtbl - GetUniquenessValue (p, a)>
        endm
        IDirectDrawSurface7_ChangeUniquenessValue macro p
          exitm <(p) - lpVtbl - ChangeUniquenessValue (p)>
        endm
        IDirectDrawSurface7_SetPriority macro p, a
          exitm <(p) - lpVtbl - SetPriority (p, a)>
        endm
        IDirectDrawSurface7_GetPriority macro p, a
          exitm <(p) - lpVtbl - GetPriority (p, a)>
        endm
        IDirectDrawSurface7_SetLOD macro p, a
          exitm <(p) - lpVtbl - SetLOD (p, a)>
        endm
        IDirectDrawSurface7_GetLOD macro p, a
          exitm <(p) - lpVtbl - GetLOD (p, a)>
        endm
      else
        ;[...]
      endif
      ;*
      ;* IDirectDrawColorControl
      ;*
      if Defined(_WIN32) and  not Defined(_NO_COM)
        INTERFACE equ <IDirectDrawColorControl>
        DECLARE_INTERFACE_(IDirectDrawColorControl, IUnknown)
          ??Interface equ <DDDEVICEIDENTIFIER2>
          ;*** IUnknown methods ***
          STDMETHOD QueryInterface, :REFIID, :ptr POINTER
          STDMETHOD_ ULONG, AddRef
          STDMETHOD_ ULONG, Release
          ;*** IDirectDrawColorControl methods ***
          STDMETHOD GetColorControls, :LPDDCOLORCONTROL
          STDMETHOD SetColorControls, :LPDDCOLORCONTROL
        DECLARE_INTERFACE__END

        if  not Defined(__cplusplus) or Defined(CINTERFACE)
          IDirectDrawColorControl_QueryInterface macro p, a, b
            exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
          endm
          IDirectDrawColorControl_AddRef macro p
            exitm <(p) - lpVtbl - AddRef (p)>
          endm
          IDirectDrawColorControl_Release macro p
            exitm <(p) - lpVtbl - Release (p)>
          endm
          IDirectDrawColorControl_GetColorControls macro p, a
            exitm <(p) - lpVtbl - GetColorControls (p, a)>
          endm
          IDirectDrawColorControl_SetColorControls macro p, a
            exitm <(p) - lpVtbl - SetColorControls (p, a)>
          endm
        else
          ;[...]
        endif
      endif
      ;*
      ;* IDirectDrawGammaControl
      ;*
      if Defined(_WIN32) and  not Defined(_NO_COM)
        INTERFACE equ <IDirectDrawGammaControl>
        DECLARE_INTERFACE_(IDirectDrawGammaControl, IUnknown)
          ??Interface equ <DDDEVICEIDENTIFIER2>
          ;*** IUnknown methods ***
          STDMETHOD QueryInterface, :REFIID, :ptr POINTER
          STDMETHOD_ ULONG, AddRef
          STDMETHOD_ ULONG, Release
          ;*** IDirectDrawGammaControl methods ***
          STDMETHOD GetGammaRamp, :DWORD, :LPDDGAMMARAMP
          STDMETHOD SetGammaRamp, :DWORD, :LPDDGAMMARAMP
        DECLARE_INTERFACE__END

        if  not Defined(__cplusplus) or Defined(CINTERFACE)
          IDirectDrawGammaControl_QueryInterface macro p, a, b
            exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
          endm
          IDirectDrawGammaControl_AddRef macro p
            exitm <(p) - lpVtbl - AddRef (p)>
          endm
          IDirectDrawGammaControl_Release macro p
            exitm <(p) - lpVtbl - Release (p)>
          endm
          IDirectDrawGammaControl_GetGammaRamp macro p, a, b
            exitm <(p) - lpVtbl - GetGammaRamp (p, a, b)>
          endm
          IDirectDrawGammaControl_SetGammaRamp macro p, a, b
            exitm <(p) - lpVtbl - SetGammaRamp (p, a, b)>
          endm
        else
          ;[...]
        endif
      endif
    endif
    ;*
    ;* DDSURFACEDESC
    ;*
    DDSURFACEDESC struct
      dwSize DWORD ?
      ; size of the DDSURFACEDESC structure
      dwFlags DWORD ?
      ; determines what fields are valid
      dwHeight DWORD ?
      ; height of surface to be created
      dwWidth DWORD ?
      ; width of input surface
      union
        lPitch SDWORD ?
        ; distance to start of next line (return value only)
        dwLinearSize DWORD ?
        ; Formless late-allocated optimized surface size
      ends
      dwBackBufferCount DWORD ?
      ; number of back buffers requested
      union
        dwMipMapCount DWORD ?
        ; number of mip-map levels requested
        dwZBufferBitDepth DWORD ?
        ; depth of Z buffer requested
        dwRefreshRate DWORD ?
        ; refresh rate (used when display mode is described)
      ends
      dwAlphaBitDepth DWORD ?
      ; depth of alpha buffer requested
      dwReserved DWORD ?
      ; reserved
      lpSurface POINTER ?
      ; pointer to the associated surface memory
      ddckCKDestOverlay DDCOLORKEY <>
      ; color key for destination overlay use
      ddckCKDestBlt DDCOLORKEY <>
      ; color key for destination blt use
      ddckCKSrcOverlay DDCOLORKEY <>
      ; color key for source overlay use
      ddckCKSrcBlt DDCOLORKEY <>
      ; color key for source blt use
      ddpfPixelFormat DDPIXELFORMAT <>
      ; pixel format description of the surface
      ddsCaps DDSCAPS <>
      ; direct draw surface capabilities
    DDSURFACEDESC ends
    _DDSURFACEDESC typedef DDSURFACEDESC
    ;*
    ;* DDSURFACEDESC2
    ;*
    DDSURFACEDESC2 struct
      dwSize DWORD ?
      ; size of the DDSURFACEDESC structure
      dwFlags DWORD ?
      ; determines what fields are valid
      dwHeight DWORD ?
      ; height of surface to be created
      dwWidth DWORD ?
      ; width of input surface
      union
        lPitch SDWORD ?
        ; distance to start of next line (return value only)
        dwLinearSize DWORD ?
        ; Formless late-allocated optimized surface size
      ends
      union
        dwBackBufferCount DWORD ?
        ; number of back buffers requested
        dwDepth DWORD ?
        ; the depth if this is a volume texture 
      ends
      union
        dwMipMapCount DWORD ?
        ; number of mip-map levels requestde
        ; dwZBufferBitDepth removed, use ddpfPixelFormat one instead
        dwRefreshRate DWORD ?
        ; refresh rate (used when display mode is described)
        dwSrcVBHandle DWORD ?
        ; The source used in VB::Optimize
      ends
      dwAlphaBitDepth DWORD ?
      ; depth of alpha buffer requested
      dwReserved DWORD ?
      ; reserved
      lpSurface POINTER ?
      ; pointer to the associated surface memory
      union
        ddckCKDestOverlay DDCOLORKEY <>
        ; color key for destination overlay use
        dwEmptyFaceColor DWORD ?
        ; Physical color for empty cubemap faces
      ends
      ddckCKDestBlt DDCOLORKEY <>
      ; color key for destination blt use
      ddckCKSrcOverlay DDCOLORKEY <>
      ; color key for source overlay use
      ddckCKSrcBlt DDCOLORKEY <>
      ; color key for source blt use
      union
        ddpfPixelFormat DDPIXELFORMAT <>
        ; pixel format description of the surface
        dwFVF DWORD ?
        ; vertex format description of vertex buffers
      ends
      ddsCaps DDSCAPS2 <>
      ; direct draw surface capabilities
      dwTextureStage DWORD ?
      ; stage in multitexture cascade
    DDSURFACEDESC2 ends
    _DDSURFACEDESC2 typedef DDSURFACEDESC2
    ;*
    ;* ddsCaps field is valid.
    ;*
    DDSD_CAPS equ 00000001h; default

    ;*
    ;* dwHeight field is valid.
    ;*
    DDSD_HEIGHT equ 00000002h
    ;*
    ;* dwWidth field is valid.
    ;*
    DDSD_WIDTH equ 00000004h
    ;*
    ;* lPitch is valid.
    ;*
    DDSD_PITCH equ 00000008h
    ;*
    ;* dwBackBufferCount is valid.
    ;*
    DDSD_BACKBUFFERCOUNT equ 00000020h
    ;*
    ;* dwZBufferBitDepth is valid.  (shouldnt be used in DDSURFACEDESC2)
    ;*
    DDSD_ZBUFFERBITDEPTH equ 00000040h
    ;*
    ;* dwAlphaBitDepth is valid.
    ;*
    DDSD_ALPHABITDEPTH equ 00000080h
    ;*
    ;* lpSurface is valid.
    ;*
    DDSD_LPSURFACE equ 00000800h
    ;*
    ;* ddpfPixelFormat is valid.
    ;*
    DDSD_PIXELFORMAT equ 00001000h
    ;*
    ;* ddckCKDestOverlay is valid.
    ;*
    DDSD_CKDESTOVERLAY equ 00002000h
    ;*
    ;* ddckCKDestBlt is valid.
    ;*
    DDSD_CKDESTBLT equ 00004000h
    ;*
    ;* ddckCKSrcOverlay is valid.
    ;*
    DDSD_CKSRCOVERLAY equ 00008000h
    ;*
    ;* ddckCKSrcBlt is valid.
    ;*
    DDSD_CKSRCBLT equ 00010000h
    ;*
    ;* dwMipMapCount is valid.
    ;*
    DDSD_MIPMAPCOUNT equ 00020000h
    ;*
    ;* dwRefreshRate is valid
    ;*
    DDSD_REFRESHRATE equ 00040000h
    ;*
    ;* dwLinearSize is valid
    ;*
    DDSD_LINEARSIZE equ 00080000h
    ;*
    ;* dwTextureStage is valid
    ;*
    DDSD_TEXTURESTAGE equ 00100000h
    ;*
    ;* dwFVF is valid
    ;*
    DDSD_FVF equ 00200000h
    ;*
    ;* dwSrcVBHandle is valid
    ;*
    DDSD_SRCVBHANDLE equ 00400000h
    ;*
    ;* dwDepth is valid
    ;*
    DDSD_DEPTH equ 00800000h
    ;*
    ;* All input fields are valid.
    ;*
    DDSD_ALL equ 00fff9eeh
    ;*
    ;* DDOPTSURFACEDESC
    ;*
    DDOPTSURFACEDESC struct
      dwSize DWORD ?
      ; size of the DDOPTSURFACEDESC structure
      dwFlags DWORD ?
      ; determines what fields are valid
      ddSCaps DDSCAPS2 <>
      ; Common caps like: Memory type
      ddOSCaps DDOSCAPS <>
      ; Common caps like: Memory type
      guid GUID <>
      ; Compression technique GUID
      dwCompressionRatio DWORD ?
      ; Compression ratio
    DDOPTSURFACEDESC ends
    _DDOPTSURFACEDESC typedef DDOPTSURFACEDESC
    ;*
    ;* guid field is valid.
    ;*
    DDOSD_GUID equ 00000001h
    ;*
    ;* dwCompressionRatio field is valid.
    ;*
    DDOSD_COMPRESSION_RATIO equ 00000002h
    ;*
    ;* ddSCaps field is valid.
    ;*
    DDOSD_SCAPS equ 00000004h
    ;*
    ;* ddOSCaps field is valid.
    ;*
    DDOSD_OSCAPS equ 00000008h
    ;*
    ;* All input fields are valid.
    ;*
    DDOSD_ALL equ 0000000fh
    ;*
    ;* The surface's optimized pixelformat is compressed
    ;*
    DDOSDCAPS_OPTCOMPRESSED equ 00000001h
    ;*
    ;* The surface's optimized pixelformat is reordered
    ;*
    DDOSDCAPS_OPTREORDERED equ 00000002h
    ;*
    ;* The opt surface is a monolithic mipmap
    ;*
    DDOSDCAPS_MONOLITHICMIPMAP equ 00000004h
    ;*
    ;* The valid Surf caps:
    ;* #define DDSCAPS_SYSTEMMEMORY                 0x00000800l
    ;* #define DDSCAPS_VIDEOMEMORY          0x00004000l
    ;* #define DDSCAPS_LOCALVIDMEM          0x10000000l
    ;* #define DDSCAPS_NONLOCALVIDMEM       0x20000000l
    ;*
    DDOSDCAPS_VALIDSCAPS equ 30004800h
    ;*
    ;* The valid OptSurf caps
    ;*
    DDOSDCAPS_VALIDOSCAPS equ 00000007h
    ;*
    ;* DDCOLORCONTROL
    ;*
    DDCOLORCONTROL struct
      dwSize DWORD ?
      dwFlags DWORD ?
      lBrightness SDWORD ?
      lContrast SDWORD ?
      lHue SDWORD ?
      lSaturation SDWORD ?
      lSharpness SDWORD ?
      lGamma SDWORD ?
      lColorEnable SDWORD ?
      dwReserved1 DWORD ?
    DDCOLORCONTROL ends
    _DDCOLORCONTROL typedef DDCOLORCONTROL
    ;*
    ;* lBrightness field is valid.
    ;*
    DDCOLOR_BRIGHTNESS equ 00000001h
    ;*
    ;* lContrast field is valid.
    ;*
    DDCOLOR_CONTRAST equ 00000002h
    ;*
    ;* lHue field is valid.
    ;*
    DDCOLOR_HUE equ 00000004h
    ;*
    ;* lSaturation field is valid.
    ;*
    DDCOLOR_SATURATION equ 00000008h
    ;*
    ;* lSharpness field is valid.
    ;*
    DDCOLOR_SHARPNESS equ 00000010h
    ;*
    ;* lGamma field is valid.
    ;*
    DDCOLOR_GAMMA equ 00000020h
    ;*
    ;* lColorEnable field is valid.
    ;*
    DDCOLOR_COLORENABLE equ 00000040h
    ;*============================================================================
    ;*
    ;* Direct Draw Capability Flags
    ;*
    ;* These flags are used to describe the capabilities of a given Surface.
    ;* All flags are bit flags.
    ;*
    ;*==========================================================================*
    ;****************************************************************************
    ;*
    ;* DIRECTDRAWSURFACE CAPABILITY FLAGS
    ;*
    ;****************************************************************************
    ;*
    ;* This bit is reserved. It should not be specified.
    ;*
    DDSCAPS_RESERVED1 equ 00000001h
    ;*
    ;* Indicates that this surface contains alpha-only information.
    ;* (To determine if a surface is RGBA/YUVA, the pixel format must be
    ;* interrogated.)
    ;*
    DDSCAPS_ALPHA equ 00000002h
    ;*
    ;* Indicates that this surface is a backbuffer.  It is generally
    ;* set by CreateSurface when the DDSCAPS_FLIP capability bit is set.
    ;* It indicates that this surface is THE back buffer of a surface
    ;* flipping structure.  DirectDraw supports N surfaces in a
    ;* surface flipping structure.  Only the surface that immediately
    ;* precedeces the DDSCAPS_FRONTBUFFER has this capability bit set.
    ;* The other surfaces are identified as back buffers by the presence
    ;* of the DDSCAPS_FLIP capability, their attachment order, and the
    ;* absence of the DDSCAPS_FRONTBUFFER and DDSCAPS_BACKBUFFER
    ;* capabilities.  The bit is sent to CreateSurface when a standalone
    ;* back buffer is being created.  This surface could be attached to
    ;* a front buffer and/or back buffers to form a flipping surface
    ;* structure after the CreateSurface call.  See AddAttachments for
    ;* a detailed description of the behaviors in this case.
    ;*
    DDSCAPS_BACKBUFFER equ 00000004h
    ;*
    ;* Indicates a complex surface structure is being described.  A
    ;* complex surface structure results in the creation of more than
    ;* one surface.  The additional surfaces are attached to the root
    ;* surface.  The complex structure can only be destroyed by
    ;* destroying the root.
    ;*
    DDSCAPS_COMPLEX equ 00000008h
    ;*
    ;* Indicates that this surface is a part of a surface flipping structure.
    ;* When it is passed to CreateSurface the DDSCAPS_FRONTBUFFER and
    ;* DDSCAP_BACKBUFFER bits are not set.  They are set by CreateSurface
    ;* on the resulting creations.  The dwBackBufferCount field in the
    ;* DDSURFACEDESC structure must be set to at least 1 in order for
    ;* the CreateSurface call to succeed.  The DDSCAPS_COMPLEX capability
    ;* must always be set with creating multiple surfaces through CreateSurface.
    ;*
    DDSCAPS_FLIP equ 00000010h
    ;*
    ;* Indicates that this surface is THE front buffer of a surface flipping
    ;* structure.  It is generally set by CreateSurface when the DDSCAPS_FLIP
    ;* capability bit is set.
    ;* If this capability is sent to CreateSurface then a standalonw front buffer
    ;* is created.  This surface will not have the DDSCAPS_FLIP capability.
    ;* It can be attached to other back buffers to form a flipping structure.
    ;* See AddAttachments for a detailed description of the behaviors in this
    ;* case.
    ;*
    DDSCAPS_FRONTBUFFER equ 00000020h
    ;*
    ;* Indicates that this surface is any offscreen surface that is not an overlay,
    ;* texture, zbuffer, front buffer, back buffer, or alpha surface.  It is used
    ;* to identify plain vanilla surfaces.
    ;*
    DDSCAPS_OFFSCREENPLAIN equ 00000040h
    ;*
    ;* Indicates that this surface is an overlay.  It may or may not be directly visible
    ;* depending on whether or not it is currently being overlayed onto the primary
    ;* surface.  DDSCAPS_VISIBLE can be used to determine whether or not it is being
    ;* overlayed at the moment.
    ;*
    DDSCAPS_OVERLAY equ 00000080h
    ;*
    ;* Indicates that unique DirectDrawPalette objects can be created and
    ;* attached to this surface.
    ;*
    DDSCAPS_PALETTE equ 00000100h
    ;*
    ;* Indicates that this surface is the primary surface.  The primary
    ;* surface represents what the user is seeing at the moment.
    ;*
    DDSCAPS_PRIMARYSURFACE equ 00000200h
    ;*
    ;* This flag used to be DDSCAPS_PRIMARYSURFACELEFT, which is now
    ;* obsolete.
    ;*
    DDSCAPS_RESERVED3 equ 00000400h
    DDSCAPS_PRIMARYSURFACELEFT equ 00000000h
    ;*
    ;* Indicates that this surface memory was allocated in system memory
    ;*
    DDSCAPS_SYSTEMMEMORY equ 00000800h
    ;*
    ;* Indicates that this surface can be used as a 3D texture.  It does not
    ;* indicate whether or not the surface is being used for that purpose.
    ;*
    DDSCAPS_TEXTURE equ 00001000h
    ;*
    ;* Indicates that a surface may be a destination for 3D rendering.  This
    ;* bit must be set in order to query for a Direct3D Device Interface
    ;* from this surface.
    ;*
    DDSCAPS_3DDEVICE equ 00002000h
    ;*
    ;* Indicates that this surface exists in video memory.
    ;*
    DDSCAPS_VIDEOMEMORY equ 00004000h
    ;*
    ;* Indicates that changes made to this surface are immediately visible.
    ;* It is always set for the primary surface and is set for overlays while
    ;* they are being overlayed and texture maps while they are being textured.
    ;*
    DDSCAPS_VISIBLE equ 00008000h
    ;*
    ;* Indicates that only writes are permitted to the surface.  Read accesses
    ;* from the surface may or may not generate a protection fault, but the
    ;* results of a read from this surface will not be meaningful.  READ ONLY.
    ;*
    DDSCAPS_WRITEONLY equ 00010000h
    ;*
    ;* Indicates that this surface is a z buffer. A z buffer does not contain
    ;* displayable information.  Instead it contains bit depth information that is
    ;* used to determine which pixels are visible and which are obscured.
    ;*
    DDSCAPS_ZBUFFER equ 00020000h
    ;*
    ;* Indicates surface will have a DC associated long term
    ;*
    DDSCAPS_OWNDC equ 00040000h
    ;*
    ;* Indicates surface should be able to receive live video
    ;*
    DDSCAPS_LIVEVIDEO equ 00080000h
    ;*
    ;* Indicates surface should be able to have a stream decompressed
    ;* to it by the hardware.
    ;*
    DDSCAPS_HWCODEC equ 00100000h
    ;*
    ;* Surface is a ModeX surface.
    ;*
    ;*
    DDSCAPS_MODEX equ 00200000h
    ;*
    ;* Indicates surface is one level of a mip-map. This surface will
    ;* be attached to other DDSCAPS_MIPMAP surfaces to form the mip-map.
    ;* This can be done explicitly, by creating a number of surfaces and
    ;* attaching them with AddAttachedSurface or by implicitly by CreateSurface.
    ;* If this bit is set then DDSCAPS_TEXTURE must also be set.
    ;*
    DDSCAPS_MIPMAP equ 00400000h
    ;*
    ;* This bit is reserved. It should not be specified.
    ;*
    DDSCAPS_RESERVED2 equ 00800000h
    ;*
    ;* Indicates that memory for the surface is not allocated until the surface
    ;* is loaded (via the Direct3D texture Load() function).
    ;*
    DDSCAPS_ALLOCONLOAD equ 04000000h
    ;*
    ;* Indicates that the surface will recieve data from a video port.
    ;*
    DDSCAPS_VIDEOPORT equ 08000000h
    ;*
    ;* Indicates that a video memory surface is resident in true, local video
    ;* memory rather than non-local video memory. If this flag is specified then
    ;* so must DDSCAPS_VIDEOMEMORY. This flag is mutually exclusive with
    ;* DDSCAPS_NONLOCALVIDMEM.
    ;*
    DDSCAPS_LOCALVIDMEM equ 10000000h
    ;*
    ;* Indicates that a video memory surface is resident in non-local video
    ;* memory rather than true, local video memory. If this flag is specified
    ;* then so must DDSCAPS_VIDEOMEMORY. This flag is mutually exclusive with
    ;* DDSCAPS_LOCALVIDMEM.
    ;*
    DDSCAPS_NONLOCALVIDMEM equ 20000000h
    ;*
    ;* Indicates that this surface is a standard VGA mode surface, and not a
    ;* ModeX surface. (This flag will never be set in combination with the
    ;* DDSCAPS_MODEX flag).
    ;*
    DDSCAPS_STANDARDVGAMODE equ 40000000h
    ;*
    ;* Indicates that this surface will be an optimized surface. This flag is
    ;* currently only valid in conjunction with the DDSCAPS_TEXTURE flag. The surface
    ;* will be created without any underlying video memory until loaded.
    ;*
    DDSCAPS_OPTIMIZED equ 80000000h
    ;*
    ;* This bit is reserved
    ;*
    DDSCAPS2_RESERVED4 equ 00000002h
    DDSCAPS2_HARDWAREDEINTERLACE equ 00000000h
    ;*
    ;* Indicates to the driver that this surface will be locked very frequently
    ;* (for procedural textures, dynamic lightmaps, etc). Surfaces with this cap
    ;* set must also have DDSCAPS_TEXTURE. This cap cannot be used with
    ;* DDSCAPS2_HINTSTATIC and DDSCAPS2_OPAQUE.
    ;*
    DDSCAPS2_HINTDYNAMIC equ 00000004h
    ;*
    ;* Indicates to the driver that this surface can be re-ordered/retiled on
    ;* load. This operation will not change the size of the texture. It is
    ;* relatively fast and symmetrical, since the application may lock these
    ;* bits (although it will take a performance hit when doing so). Surfaces
    ;* with this cap set must also have DDSCAPS_TEXTURE. This cap cannot be
    ;* used with DDSCAPS2_HINTDYNAMIC and DDSCAPS2_OPAQUE.
    ;*
    DDSCAPS2_HINTSTATIC equ 00000008h
    ;*
    ;* Indicates that the client would like this texture surface to be managed by the
    ;* DirectDraw/Direct3D runtime. Surfaces with this cap set must also have
    ;* DDSCAPS_TEXTURE set.
    ;*
    DDSCAPS2_TEXTUREMANAGE equ 00000010h
    ;*
    ;* These bits are reserved for internal use *
    DDSCAPS2_RESERVED1 equ 00000020h
    DDSCAPS2_RESERVED2 equ 00000040h
    ;*
    ;* Indicates to the driver that this surface will never be locked again.
    ;* The driver is free to optimize this surface via retiling and actual compression.
    ;* All calls to Lock() or Blts from this surface will fail. Surfaces with this
    ;* cap set must also have DDSCAPS_TEXTURE. This cap cannot be used with
    ;* DDSCAPS2_HINTDYNAMIC and DDSCAPS2_HINTSTATIC.
    ;*
    DDSCAPS2_OPAQUE equ 00000080h
    ;*
    ;* Applications should set this bit at CreateSurface time to indicate that they
    ;* intend to use antialiasing. Only valid if DDSCAPS_3DDEVICE is also set.
    ;*
    DDSCAPS2_HINTANTIALIASING equ 00000100h
    ;*
    ;* This flag is used at CreateSurface time to indicate that this set of
    ;* surfaces is a cubic environment map
    ;*
    DDSCAPS2_CUBEMAP equ 00000200h
    ;*
    ;* These flags preform two functions:
    ;* - At CreateSurface time, they define which of the six cube faces are
    ;*   required by the application.
    ;* - After creation, each face in the cubemap will have exactly one of these
    ;*   bits set.
    ;*
    DDSCAPS2_CUBEMAP_POSITIVEX equ 00000400h
    DDSCAPS2_CUBEMAP_NEGATIVEX equ 00000800h
    DDSCAPS2_CUBEMAP_POSITIVEY equ 00001000h
    DDSCAPS2_CUBEMAP_NEGATIVEY equ 00002000h
    DDSCAPS2_CUBEMAP_POSITIVEZ equ 00004000h
    DDSCAPS2_CUBEMAP_NEGATIVEZ equ 00008000h
    ;*
    ;* This macro may be used to specify all faces of a cube map at CreateSurface time
    ;*
    DDSCAPS2_CUBEMAP_ALLFACES equ <(DDSCAPS2_CUBEMAP_POSITIVEX or DDSCAPS2_CUBEMAP_NEGATIVEX or DDSCAPS2_CUBEMAP_POSITIVEY or DDSCAPS2_CUBEMAP_NEGATIVEY or DDSCAPS2_CUBEMAP_POSITIVEZ or DDSCAPS2_CUBEMAP_NEGATIVEZ)>
    ;*
    ;* This flag is an additional flag which is present on mipmap sublevels from DX7 onwards
    ;* It enables easier use of GetAttachedSurface rather than EnumAttachedSurfaces for surface
    ;* constructs such as Cube Maps, wherein there are more than one mipmap surface attached
    ;* to the root surface.
    ;* This caps bit is ignored by CreateSurface
    ;*
    DDSCAPS2_MIPMAPSUBLEVEL equ 00010000h
    ;* This flag indicates that the texture should be managed by D3D only *
    DDSCAPS2_D3DTEXTUREMANAGE equ 00020000h
    ;* This flag indicates that the managed surface can be safely lost *
    DDSCAPS2_DONOTPERSIST equ 00040000h
    ;* indicates that this surface is part of a stereo flipping chain *
    DDSCAPS2_STEREOSURFACELEFT equ 00080000h
    ;*
    ;* Indicates that the surface is a volume.
    ;* Can be combined with DDSCAPS_MIPMAP to indicate a multi-level volume
    ;*
    DDSCAPS2_VOLUME equ 00200000h
    ;*
    ;* Indicates that the surface may be locked multiple times by the application.
    ;* This cap cannot be used with DDSCAPS2_OPAQUE.
    ;*
    DDSCAPS2_NOTUSERLOCKABLE equ 00400000h
    ;*
    ;* Indicates that the vertex buffer data can be used to render points and
    ;* point sprites.
    ;*
    DDSCAPS2_POINTS equ 00800000h
    ;*
    ;* Indicates that the vertex buffer data can be used to render rt pactches.
    ;*
    DDSCAPS2_RTPATCHES equ 01000000h
    ;*
    ;* Indicates that the vertex buffer data can be used to render n patches.
    ;*
    DDSCAPS2_NPATCHES equ 02000000h
    ;*
    ;* This bit is reserved for internal use 
    ;*
    DDSCAPS2_RESERVED3 equ 04000000h
    ;*
    ;* Indicates that the contents of the backbuffer do not have to be preserved
    ;* the contents of the backbuffer after they are presented.
    ;*
    DDSCAPS2_DISCARDBACKBUFFER equ 10000000h
    ;*
    ;* Indicates that all surfaces in this creation chain should be given an alpha channel.
    ;* This flag will be set on primary surface chains that may have no explicit pixel format
    ;* (and thus take on the format of the current display mode).
    ;* The driver should infer that all these surfaces have a format having an alpha channel.
    ;* (e.g. assume D3DFMT_A8R8G8B8 if the display mode is x888.)
    ;*
    DDSCAPS2_ENABLEALPHACHANNEL equ 20000000h
    ;*
    ;* Indicates that all surfaces in this creation chain is extended primary surface format.
    ;* This flag will be set on extended primary surface chains that always have explicit pixel
    ;* format and the pixel format is typically GDI (Graphics Device Interface) couldn't handle,
    ;* thus only used with fullscreen application. (e.g. D3DFMT_A2R10G10B10 format)
    ;*
    DDSCAPS2_EXTENDEDFORMATPRIMARY equ 40000000h
    ;*
    ;* Indicates that all surfaces in this creation chain is additional primary surface.
    ;* This flag will be set on primary surface chains which must present on the adapter
    ;* id provided on dwCaps4. Typically this will be used to create secondary primary surface
    ;* on DualView display adapter.
    ;*
    DDSCAPS2_ADDITIONALPRIMARY equ 80000000h
    ;*
    ;* This is a mask that indicates the set of bits that may be set
    ;* at createsurface time to indicate number of samples per pixel
    ;* when multisampling
    ;*
    DDSCAPS3_MULTISAMPLE_MASK equ 0000001Fh
    ;*
    ;* This is a mask that indicates the set of bits that may be set
    ;* at createsurface time to indicate the quality level of rendering
    ;* for the current number of samples per pixel
    ;*
    DDSCAPS3_MULTISAMPLE_QUALITY_MASK equ 000000E0h
    DDSCAPS3_MULTISAMPLE_QUALITY_SHIFT equ 5
    ;*
    ;* This bit is reserved for internal use 
    ;*
    DDSCAPS3_RESERVED1 equ 00000100h
    ;*
    ;* This bit is reserved for internal use 
    ;*
    DDSCAPS3_RESERVED2 equ 00000200h
    ;*
    ;* This indicates whether this surface has light-weight miplevels
    ;*
    DDSCAPS3_LIGHTWEIGHTMIPMAP equ 00000400h
    ;*
    ;* This indicates that the mipsublevels for this surface are auto-generated
    ;*
    DDSCAPS3_AUTOGENMIPMAP equ 00000800h
    ;*
    ;* This indicates that the mipsublevels for this surface are auto-generated
    ;*
    DDSCAPS3_DMAP equ 00001000h
    ;* D3D9Ex only -- *
    if  not Defined(D3D_DISABLE_9EX)
      ;*
      ;* This indicates that this surface is to be shared by processes
      ;*
      DDSCAPS3_CREATESHAREDRESOURCE equ 00002000h
      ;*
      ;* This indicates that this surface need to be initialized before being
      ;* shared, this bit implies that this surface is read only after initialization
      ;* absence of this bit implies that this surface allows both read and write
      ;*
      DDSCAPS3_READONLYRESOURCE equ 00004000h
      ;*
      ;* This indicates that this surface is to share an existing video memory with 
      ;* another surface created with DDSCAPS3_CREATESHAREDRESOURCE, This bit is never
      ;* used with DDSCAPS3_CREATESHAREDRESOURCE
      ;*
      DDSCAPS3_OPENSHAREDRESOURCE equ 00008000h
    endif
    ; !D3D_DISABLE_9EX
    ;* -- D3D9Ex only *
    ;****************************************************************************
    ;*
    ;* DIRECTDRAW DRIVER CAPABILITY FLAGS
    ;*
    ;****************************************************************************
    ;*
    ;* Display hardware has 3D acceleration.
    ;*
    DDCAPS_3D equ 00000001h
    ;*
    ;* Indicates that DirectDraw will support only dest rectangles that are aligned
    ;* on DIRECTDRAWCAPS.dwAlignBoundaryDest boundaries of the surface, respectively.
    ;* READ ONLY.
    ;*
    DDCAPS_ALIGNBOUNDARYDEST equ 00000002h
    ;*
    ;* Indicates that DirectDraw will support only source rectangles  whose sizes in
    ;* BYTEs are DIRECTDRAWCAPS.dwAlignSizeDest multiples, respectively.  READ ONLY.
    ;*
    DDCAPS_ALIGNSIZEDEST equ 00000004h
    ;*
    ;* Indicates that DirectDraw will support only source rectangles that are aligned
    ;* on DIRECTDRAWCAPS.dwAlignBoundarySrc boundaries of the surface, respectively.
    ;* READ ONLY.
    ;*
    DDCAPS_ALIGNBOUNDARYSRC equ 00000008h
    ;*
    ;* Indicates that DirectDraw will support only source rectangles  whose sizes in
    ;* BYTEs are DIRECTDRAWCAPS.dwAlignSizeSrc multiples, respectively.  READ ONLY.
    ;*
    DDCAPS_ALIGNSIZESRC equ 00000010h
    ;*
    ;* Indicates that DirectDraw will create video memory surfaces that have a stride
    ;* alignment equal to DIRECTDRAWCAPS.dwAlignStride.  READ ONLY.
    ;*
    DDCAPS_ALIGNSTRIDE equ 00000020h
    ;*
    ;* Display hardware is capable of blt operations.
    ;*
    DDCAPS_BLT equ 00000040h
    ;*
    ;* Display hardware is capable of asynchronous blt operations.
    ;*
    DDCAPS_BLTQUEUE equ 00000080h
    ;*
    ;* Display hardware is capable of color space conversions during the blt operation.
    ;*
    DDCAPS_BLTFOURCC equ 00000100h
    ;*
    ;* Display hardware is capable of stretching during blt operations.
    ;*
    DDCAPS_BLTSTRETCH equ 00000200h
    ;*
    ;* Display hardware is shared with GDI.
    ;*
    DDCAPS_GDI equ 00000400h
    ;*
    ;* Display hardware can overlay.
    ;*
    DDCAPS_OVERLAY equ 00000800h
    ;*
    ;* Set if display hardware supports overlays but can not clip them.
    ;*
    DDCAPS_OVERLAYCANTCLIP equ 00001000h
    ;*
    ;* Indicates that overlay hardware is capable of color space conversions during
    ;* the overlay operation.
    ;*
    DDCAPS_OVERLAYFOURCC equ 00002000h
    ;*
    ;* Indicates that stretching can be done by the overlay hardware.
    ;*
    DDCAPS_OVERLAYSTRETCH equ 00004000h
    ;*
    ;* Indicates that unique DirectDrawPalettes can be created for DirectDrawSurfaces
    ;* other than the primary surface.
    ;*
    DDCAPS_PALETTE equ 00008000h
    ;*
    ;* Indicates that palette changes can be syncd with the veritcal refresh.
    ;*
    DDCAPS_PALETTEVSYNC equ 00010000h
    ;*
    ;* Display hardware can return the current scan line.
    ;*
    DDCAPS_READSCANLINE equ 00020000h
    ;*
    ;* This flag used to bo DDCAPS_STEREOVIEW, which is now obsolete
    ;*
    DDCAPS_RESERVED1 equ 00040000h
    ;*
    ;* Display hardware is capable of generating a vertical blank interrupt.
    ;*
    DDCAPS_VBI equ 00080000h
    ;*
    ;* Supports the use of z buffers with blt operations.
    ;*
    DDCAPS_ZBLTS equ 00100000h
    ;*
    ;* Supports Z Ordering of overlays.
    ;*
    DDCAPS_ZOVERLAYS equ 00200000h
    ;*
    ;* Supports color key
    ;*
    DDCAPS_COLORKEY equ 00400000h
    ;*
    ;* Supports alpha surfaces
    ;*
    DDCAPS_ALPHA equ 00800000h
    ;*
    ;* colorkey is hardware assisted(DDCAPS_COLORKEY will also be set)
    ;*
    DDCAPS_COLORKEYHWASSIST equ 01000000h
    ;*
    ;* no hardware support at all
    ;*
    DDCAPS_NOHARDWARE equ 02000000h
    ;*
    ;* Display hardware is capable of color fill with bltter
    ;*
    DDCAPS_BLTCOLORFILL equ 04000000h
    ;*
    ;* Display hardware is bank switched, and potentially very slow at
    ;* random access to VRAM.
    ;*
    DDCAPS_BANKSWITCHED equ 08000000h
    ;*
    ;* Display hardware is capable of depth filling Z-buffers with bltter
    ;*
    DDCAPS_BLTDEPTHFILL equ 10000000h
    ;*
    ;* Display hardware is capable of clipping while bltting.
    ;*
    DDCAPS_CANCLIP equ 20000000h
    ;*
    ;* Display hardware is capable of clipping while stretch bltting.
    ;*
    DDCAPS_CANCLIPSTRETCHED equ 40000000h
    ;*
    ;* Display hardware is capable of bltting to or from system memory
    ;*
    DDCAPS_CANBLTSYSMEM equ 80000000h
    ;****************************************************************************
    ;*
    ;* MORE DIRECTDRAW DRIVER CAPABILITY FLAGS (dwCaps2)
    ;*
    ;****************************************************************************
    ;*
    ;* Display hardware is certified
    ;*
    DDCAPS2_CERTIFIED equ 00000001h
    ;*
    ;* Driver cannot interleave 2D operations (lock and blt) to surfaces with
    ;* Direct3D rendering operations between calls to BeginScene() and EndScene()
    ;*
    DDCAPS2_NO2DDURING3DSCENE equ 00000002h
    ;*
    ;* Display hardware contains a video port
    ;*
    DDCAPS2_VIDEOPORT equ 00000004h
    ;*
    ;* The overlay can be automatically flipped according to the video port
    ;* VSYNCs, providing automatic doubled buffered display of video port
    ;* data using an overlay
    ;*
    DDCAPS2_AUTOFLIPOVERLAY equ 00000008h
    ;*
    ;* Overlay can display each field of interlaced data individually while
    ;* it is interleaved in memory without causing jittery artifacts.
    ;*
    DDCAPS2_CANBOBINTERLEAVED equ 00000010h
    ;*
    ;* Overlay can display each field of interlaced data individually while
    ;* it is not interleaved in memory without causing jittery artifacts.
    ;*
    DDCAPS2_CANBOBNONINTERLEAVED equ 00000020h
    ;*
    ;* The overlay surface contains color controls (brightness, sharpness, etc.)
    ;*
    DDCAPS2_COLORCONTROLOVERLAY equ 00000040h
    ;*
    ;* The primary surface contains color controls (gamma, etc.)
    ;*
    DDCAPS2_COLORCONTROLPRIMARY equ 00000080h
    ;*
    ;* RGBZ -> RGB supported for 16:16 RGB:Z
    ;*
    DDCAPS2_CANDROPZ16BIT equ 00000100h
    ;*
    ;* Driver supports non-local video memory.
    ;*
    DDCAPS2_NONLOCALVIDMEM equ 00000200h
    ;*
    ;* Dirver supports non-local video memory but has different capabilities for
    ;* non-local video memory surfaces. If this bit is set then so must
    ;* DDCAPS2_NONLOCALVIDMEM.
    ;*
    DDCAPS2_NONLOCALVIDMEMCAPS equ 00000400h
    ;*
    ;* Driver neither requires nor prefers surfaces to be pagelocked when performing
    ;* blts involving system memory surfaces
    ;*
    DDCAPS2_NOPAGELOCKREQUIRED equ 00000800h
    ;*
    ;* Driver can create surfaces which are wider than the primary surface
    ;*
    DDCAPS2_WIDESURFACES equ 00001000h
    ;*
    ;* Driver supports bob without using a video port by handling the
    ;* DDFLIP_ODD and DDFLIP_EVEN flags specified in Flip.
    ;*
    DDCAPS2_CANFLIPODDEVEN equ 00002000h
    ;*
    ;* Driver supports bob using hardware
    ;*
    DDCAPS2_CANBOBHARDWARE equ 00004000h
    ;*
    ;* Driver supports bltting any FOURCC surface to another surface of the same FOURCC
    ;*
    DDCAPS2_COPYFOURCC equ 00008000h
    ;*
    ;* Driver supports loadable gamma ramps for the primary surface
    ;*
    DDCAPS2_PRIMARYGAMMA equ 00020000h
    ;*
    ;* Driver can render in windowed mode.
    ;*
    DDCAPS2_CANRENDERWINDOWED equ 00080000h
    ;*
    ;* A calibrator is available to adjust the gamma ramp according to the
    ;* physical display properties so that the result will be identical on
    ;* all calibrated systems.
    ;*
    DDCAPS2_CANCALIBRATEGAMMA equ 00100000h
    ;*
    ;* Indicates that the driver will respond to DDFLIP_INTERVALn flags
    ;*
    DDCAPS2_FLIPINTERVAL equ 00200000h
    ;*
    ;* Indicates that the driver will respond to DDFLIP_NOVSYNC
    ;*
    DDCAPS2_FLIPNOVSYNC equ 00400000h
    ;*
    ;* Driver supports management of video memory, if this flag is ON,
    ;* driver manages the texture if requested with DDSCAPS2_TEXTUREMANAGE on
    ;* DirectX manages the texture if this flag is OFF and surface has DDSCAPS2_TEXTUREMANAGE on
    ;*
    DDCAPS2_CANMANAGETEXTURE equ 00800000h
    ;*
    ;* The Direct3D texture manager uses this cap to decide whether to put managed
    ;* surfaces in non-local video memory. If the cap is set, the texture manager will
    ;* put managed surfaces in non-local vidmem. Drivers that cannot texture from
    ;* local vidmem SHOULD NOT set this cap.
    ;*
    DDCAPS2_TEXMANINNONLOCALVIDMEM equ 01000000h
    ;*
    ;* Indicates that the driver supports DX7 type of stereo in at least one mode (which may
    ;* not necessarily be the current mode). Applications should use IDirectDraw7 (or higher)
    ;* ::EnumDisplayModes and check the DDSURFACEDESC.ddsCaps.dwCaps2 field for the presence of
    ;* DDSCAPS2_STEREOSURFACELEFT to check if a particular mode supports stereo. The application
    ;* can also use IDirectDraw7(or higher)::GetDisplayMode to check the current mode.
    ;*
    DDCAPS2_STEREO equ 02000000h
    ;*
    ;* This caps bit is intended for internal DirectDraw use.
    ;* -It is only valid if DDCAPS2_NONLOCALVIDMEMCAPS is set.
    ;* -If this bit is set, then DDCAPS_CANBLTSYSMEM MUST be set by the driver (and
    ;*  all the assoicated system memory blt caps must be correct).
    ;* -It implies that the system->video blt caps in DDCAPS also apply to system to
    ;*  nonlocal blts. I.e. the dwSVBCaps, dwSVBCKeyCaps, dwSVBFXCaps and dwSVBRops
    ;*  members of DDCAPS (DDCORECAPS) are filled in correctly.
    ;* -Any blt from system to nonlocal memory that matches these caps bits will
    ;*  be passed to the driver.
    ;*
    ;* NOTE: This is intended to enable the driver itself to do efficient reordering
    ;* of textures. This is NOT meant to imply that hardware can write into AGP memory.
    ;* This operation is not currently supported.
    ;*
    DDCAPS2_SYSTONONLOCAL_AS_SYSTOLOCAL equ 04000000h
    ;*
    ;* was DDCAPS2_PUREHAL
    ;*
    DDCAPS2_RESERVED1 equ 08000000h
    ;*
    ;* Driver supports management of video memory, if this flag is ON,
    ;* driver manages the resource if requested with DDSCAPS2_TEXTUREMANAGE on
    ;* DirectX manages the resource if this flag is OFF and surface has DDSCAPS2_TEXTUREMANAGE on
    ;*
    DDCAPS2_CANMANAGERESOURCE equ 10000000h
    ;*
    ;* Driver supports dynamic textures. This will allow the application to set
    ;* D3DUSAGE_DYNAMIC (DDSCAPS2_HINTDYNAMIC for drivers) at texture create time.
    ;* Video memory dynamic textures WILL be lockable by applications. It is
    ;* expected that these locks will be very efficient (which implies that the
    ;* driver should always maintain a linear copy, a pointer to which can be
    ;* quickly handed out to the application).
    ;*
    DDCAPS2_DYNAMICTEXTURES equ 20000000h
    ;*
    ;* Driver supports auto-generation of mipmaps.
    ;*
    DDCAPS2_CANAUTOGENMIPMAP equ 40000000h
    ;* D3D9Ex only -- *
    if  not Defined(D3D_DISABLE_9EX)
      ;*
      ;* Driver supports sharing of cross process resouces
      ;*
      DDCAPS2_CANSHARERESOURCE equ 80000000h
    endif
    ; !D3D_DISABLE_9EX
    ;* -- D3D9Ex only *
    ;****************************************************************************
    ;*
    ;* DIRECTDRAW FX ALPHA CAPABILITY FLAGS
    ;*
    ;****************************************************************************
    ;*
    ;* Supports alpha blending around the edge of a source color keyed surface.
    ;* For Blt.
    ;*
    DDFXALPHACAPS_BLTALPHAEDGEBLEND equ 00000001h
    ;*
    ;* Supports alpha information in the pixel format.  The bit depth of alpha
    ;* information in the pixel format can be 1,2,4, or 8.  The alpha value becomes
    ;* more opaque as the alpha value increases.  (0 is transparent.)
    ;* For Blt.
    ;*
    DDFXALPHACAPS_BLTALPHAPIXELS equ 00000002h
    ;*
    ;* Supports alpha information in the pixel format.  The bit depth of alpha
    ;* information in the pixel format can be 1,2,4, or 8.  The alpha value
    ;* becomes more transparent as the alpha value increases.  (0 is opaque.)
    ;* This flag can only be set if DDCAPS_ALPHA is set.
    ;* For Blt.
    ;*
    DDFXALPHACAPS_BLTALPHAPIXELSNEG equ 00000004h
    ;*
    ;* Supports alpha only surfaces.  The bit depth of an alpha only surface can be
    ;* 1,2,4, or 8.  The alpha value becomes more opaque as the alpha value increases.
    ;* (0 is transparent.)
    ;* For Blt.
    ;*
    DDFXALPHACAPS_BLTALPHASURFACES equ 00000008h
    ;*
    ;* The depth of the alpha channel data can range can be 1,2,4, or 8.
    ;* The NEG suffix indicates that this alpha channel becomes more transparent
    ;* as the alpha value increases. (0 is opaque.)  This flag can only be set if
    ;* DDCAPS_ALPHA is set.
    ;* For Blt.
    ;*
    DDFXALPHACAPS_BLTALPHASURFACESNEG equ 00000010h
    ;*
    ;* Supports alpha blending around the edge of a source color keyed surface.
    ;* For Overlays.
    ;*
    DDFXALPHACAPS_OVERLAYALPHAEDGEBLEND equ 00000020h
    ;*
    ;* Supports alpha information in the pixel format.  The bit depth of alpha
    ;* information in the pixel format can be 1,2,4, or 8.  The alpha value becomes
    ;* more opaque as the alpha value increases.  (0 is transparent.)
    ;* For Overlays.
    ;*
    DDFXALPHACAPS_OVERLAYALPHAPIXELS equ 00000040h
    ;*
    ;* Supports alpha information in the pixel format.  The bit depth of alpha
    ;* information in the pixel format can be 1,2,4, or 8.  The alpha value
    ;* becomes more transparent as the alpha value increases.  (0 is opaque.)
    ;* This flag can only be set if DDCAPS_ALPHA is set.
    ;* For Overlays.
    ;*
    DDFXALPHACAPS_OVERLAYALPHAPIXELSNEG equ 00000080h
    ;*
    ;* Supports alpha only surfaces.  The bit depth of an alpha only surface can be
    ;* 1,2,4, or 8.  The alpha value becomes more opaque as the alpha value increases.
    ;* (0 is transparent.)
    ;* For Overlays.
    ;*
    DDFXALPHACAPS_OVERLAYALPHASURFACES equ 00000100h
    ;*
    ;* The depth of the alpha channel data can range can be 1,2,4, or 8.
    ;* The NEG suffix indicates that this alpha channel becomes more transparent
    ;* as the alpha value increases. (0 is opaque.)  This flag can only be set if
    ;* DDCAPS_ALPHA is set.
    ;* For Overlays.
    ;*
    DDFXALPHACAPS_OVERLAYALPHASURFACESNEG equ 00000200h
    if DIRECTDRAW_VERSION lt 0600h
    endif
    ;DIRECTDRAW_VERSION
    ;****************************************************************************
    ;*
    ;* DIRECTDRAW FX CAPABILITY FLAGS
    ;*
    ;****************************************************************************
    ;*
    ;* Uses arithmetic operations to stretch and shrink surfaces during blt
    ;* rather than pixel doubling techniques.  Along the Y axis.
    ;*
    DDFXCAPS_BLTARITHSTRETCHY equ 00000020h
    ;*
    ;* Uses arithmetic operations to stretch during blt
    ;* rather than pixel doubling techniques.  Along the Y axis. Only
    ;* works for x1, x2, etc.
    ;*
    DDFXCAPS_BLTARITHSTRETCHYN equ 00000010h
    ;*
    ;* Supports mirroring left to right in blt.
    ;*
    DDFXCAPS_BLTMIRRORLEFTRIGHT equ 00000040h
    ;*
    ;* Supports mirroring top to bottom in blt.
    ;*
    DDFXCAPS_BLTMIRRORUPDOWN equ 00000080h
    ;*
    ;* Supports arbitrary rotation for blts.
    ;*
    DDFXCAPS_BLTROTATION equ 00000100h
    ;*
    ;* Supports 90 degree rotations for blts.
    ;*
    DDFXCAPS_BLTROTATION90 equ 00000200h
    ;*
    ;* DirectDraw supports arbitrary shrinking of a surface along the
    ;* x axis (horizontal direction) for blts.
    ;*
    DDFXCAPS_BLTSHRINKX equ 00000400h
    ;*
    ;* DirectDraw supports integer shrinking (1x,2x,) of a surface
    ;* along the x axis (horizontal direction) for blts.
    ;*
    DDFXCAPS_BLTSHRINKXN equ 00000800h
    ;*
    ;* DirectDraw supports arbitrary shrinking of a surface along the
    ;* y axis (horizontal direction) for blts.
    ;*
    DDFXCAPS_BLTSHRINKY equ 00001000h
    ;*
    ;* DirectDraw supports integer shrinking (1x,2x,) of a surface
    ;* along the y axis (vertical direction) for blts.
    ;*
    DDFXCAPS_BLTSHRINKYN equ 00002000h
    ;*
    ;* DirectDraw supports arbitrary stretching of a surface along the
    ;* x axis (horizontal direction) for blts.
    ;*
    DDFXCAPS_BLTSTRETCHX equ 00004000h
    ;*
    ;* DirectDraw supports integer stretching (1x,2x,) of a surface
    ;* along the x axis (horizontal direction) for blts.
    ;*
    DDFXCAPS_BLTSTRETCHXN equ 00008000h
    ;*
    ;* DirectDraw supports arbitrary stretching of a surface along the
    ;* y axis (horizontal direction) for blts.
    ;*
    DDFXCAPS_BLTSTRETCHY equ 00010000h
    ;*
    ;* DirectDraw supports integer stretching (1x,2x,) of a surface
    ;* along the y axis (vertical direction) for blts.
    ;*
    DDFXCAPS_BLTSTRETCHYN equ 00020000h
    ;*
    ;* Uses arithmetic operations to stretch and shrink surfaces during
    ;* overlay rather than pixel doubling techniques.  Along the Y axis
    ;* for overlays.
    ;*
    DDFXCAPS_OVERLAYARITHSTRETCHY equ 00040000h
    ;*
    ;* Uses arithmetic operations to stretch surfaces during
    ;* overlay rather than pixel doubling techniques.  Along the Y axis
    ;* for overlays. Only works for x1, x2, etc.
    ;*
    DDFXCAPS_OVERLAYARITHSTRETCHYN equ 00000008h
    ;*
    ;* DirectDraw supports arbitrary shrinking of a surface along the
    ;* x axis (horizontal direction) for overlays.
    ;*
    DDFXCAPS_OVERLAYSHRINKX equ 00080000h
    ;*
    ;* DirectDraw supports integer shrinking (1x,2x,) of a surface
    ;* along the x axis (horizontal direction) for overlays.
    ;*
    DDFXCAPS_OVERLAYSHRINKXN equ 00100000h
    ;*
    ;* DirectDraw supports arbitrary shrinking of a surface along the
    ;* y axis (horizontal direction) for overlays.
    ;*
    DDFXCAPS_OVERLAYSHRINKY equ 00200000h
    ;*
    ;* DirectDraw supports integer shrinking (1x,2x,) of a surface
    ;* along the y axis (vertical direction) for overlays.
    ;*
    DDFXCAPS_OVERLAYSHRINKYN equ 00400000h
    ;*
    ;* DirectDraw supports arbitrary stretching of a surface along the
    ;* x axis (horizontal direction) for overlays.
    ;*
    DDFXCAPS_OVERLAYSTRETCHX equ 00800000h
    ;*
    ;* DirectDraw supports integer stretching (1x,2x,) of a surface
    ;* along the x axis (horizontal direction) for overlays.
    ;*
    DDFXCAPS_OVERLAYSTRETCHXN equ 01000000h
    ;*
    ;* DirectDraw supports arbitrary stretching of a surface along the
    ;* y axis (horizontal direction) for overlays.
    ;*
    DDFXCAPS_OVERLAYSTRETCHY equ 02000000h
    ;*
    ;* DirectDraw supports integer stretching (1x,2x,) of a surface
    ;* along the y axis (vertical direction) for overlays.
    ;*
    DDFXCAPS_OVERLAYSTRETCHYN equ 04000000h
    ;*
    ;* DirectDraw supports mirroring of overlays across the vertical axis
    ;*
    DDFXCAPS_OVERLAYMIRRORLEFTRIGHT equ 08000000h
    ;*
    ;* DirectDraw supports mirroring of overlays across the horizontal axis
    ;*
    DDFXCAPS_OVERLAYMIRRORUPDOWN equ 10000000h
    ;*
    ;* DirectDraw supports deinterlacing of overlay surfaces
    ;*
    DDFXCAPS_OVERLAYDEINTERLACE equ 20000000h
    ;*
    ;* Driver can do alpha blending for blits.
    ;*
    DDFXCAPS_BLTALPHA equ 00000001h
    ;*
    ;* Driver can do surface-reconstruction filtering for warped blits.
    ;*
    DDFXCAPS_BLTFILTER equ <DDFXCAPS_BLTARITHSTRETCHY>
    ;*
    ;* Driver can do alpha blending for overlays.
    ;*
    DDFXCAPS_OVERLAYALPHA equ 00000004h
    ;*
    ;* Driver can do surface-reconstruction filtering for warped overlays.
    ;*
    DDFXCAPS_OVERLAYFILTER equ <DDFXCAPS_OVERLAYARITHSTRETCHY>
    ;****************************************************************************
    ;*
    ;* DIRECTDRAW STEREO VIEW CAPABILITIES
    ;*
    ;****************************************************************************
    ;*
    ;* This flag used to be DDSVCAPS_ENIGMA, which is now obsolete
    ;*
    DDSVCAPS_RESERVED1 equ 00000001h
    ;*
    ;* This flag used to be DDSVCAPS_FLICKER, which is now obsolete
    ;*
    DDSVCAPS_RESERVED2 equ 00000002h
    ;*
    ;* This flag used to be DDSVCAPS_REDBLUE, which is now obsolete
    ;*
    DDSVCAPS_RESERVED3 equ 00000004h
    ;*
    ;* This flag used to be DDSVCAPS_SPLIT, which is now obsolete
    ;*
    DDSVCAPS_RESERVED4 equ 00000008h
    ;*
    ;* The stereo view is accomplished with switching technology
    ;*
    DDSVCAPS_STEREOSEQUENTIAL equ 00000010h
    ;****************************************************************************
    ;*
    ;* DIRECTDRAWPALETTE CAPABILITIES
    ;*
    ;****************************************************************************
    ;*
    ;* Index is 4 bits.  There are sixteen color entries in the palette table.
    ;*
    DDPCAPS_4BIT equ 00000001h
    ;*
    ;* Index is onto a 8 bit color index.  This field is only valid with the
    ;* DDPCAPS_1BIT, DDPCAPS_2BIT or DDPCAPS_4BIT capability and the target
    ;* surface is in 8bpp. Each color entry is one byte long and is an index
    ;* into destination surface's 8bpp palette.
    ;*
    DDPCAPS_8BITENTRIES equ 00000002h
    ;*
    ;* Index is 8 bits.  There are 256 color entries in the palette table.
    ;*
    DDPCAPS_8BIT equ 00000004h
    ;*
    ;* Indicates that this DIRECTDRAWPALETTE should use the palette color array
    ;* passed into the lpDDColorArray parameter to initialize the DIRECTDRAWPALETTE
    ;* object.
    ;* This flag is obsolete. DirectDraw always initializes the color array from
    ;* the lpDDColorArray parameter. The definition remains for source-level
    ;* compatibility.
    ;*
    DDPCAPS_INITIALIZE equ 00000000h
    ;*
    ;* This palette is the one attached to the primary surface.  Changing this
    ;* table has immediate effect on the display unless DDPSETPAL_VSYNC is specified
    ;* and supported.
    ;*
    DDPCAPS_PRIMARYSURFACE equ 00000010h
    ;*
    ;* This palette is the one attached to the primary surface left.  Changing
    ;* this table has immediate effect on the display for the left eye unless
    ;* DDPSETPAL_VSYNC is specified and supported.
    ;*
    DDPCAPS_PRIMARYSURFACELEFT equ 00000020h
    ;*
    ;* This palette can have all 256 entries defined
    ;*
    DDPCAPS_ALLOW256 equ 00000040h
    ;*
    ;* This palette can have modifications to it synced with the monitors
    ;* refresh rate.
    ;*
    DDPCAPS_VSYNC equ 00000080h
    ;*
    ;* Index is 1 bit.  There are two color entries in the palette table.
    ;*
    DDPCAPS_1BIT equ 00000100h
    ;*
    ;* Index is 2 bit.  There are four color entries in the palette table.
    ;*
    DDPCAPS_2BIT equ 00000200h
    ;*
    ;* The peFlags member of PALETTEENTRY denotes an 8 bit alpha value
    ;*
    DDPCAPS_ALPHA equ 00000400h
    ;****************************************************************************
    ;*
    ;* DIRECTDRAWPALETTE SETENTRY CONSTANTS
    ;*
    ;****************************************************************************
    ;****************************************************************************
    ;*
    ;* DIRECTDRAWPALETTE GETENTRY CONSTANTS
    ;*
    ;****************************************************************************
    ;* 0 is the only legal value *
    ;****************************************************************************
    ;*
    ;* DIRECTDRAWSURFACE SETPRIVATEDATA CONSTANTS
    ;*
    ;****************************************************************************
    ;*
    ;* The passed pointer is an IUnknown ptr. The cbData argument to SetPrivateData
    ;* must be set to sizeof(IUnknown*). DirectDraw will call AddRef through this
    ;* pointer and Release when the private data is destroyed. This includes when
    ;* the surface or palette is destroyed before such priovate data is destroyed.
    ;*
    DDSPD_IUNKNOWNPOINTER equ 00000001h
    ;*
    ;* Private data is only valid for the current state of the object,
    ;* as determined by the uniqueness value.
    ;*
    DDSPD_VOLATILE equ 00000002h
    ;****************************************************************************
    ;*
    ;* DIRECTDRAWSURFACE SETPALETTE CONSTANTS
    ;*
    ;****************************************************************************
    ;****************************************************************************
    ;*
    ;* DIRECTDRAW BITDEPTH CONSTANTS
    ;*
    ;* NOTE:  These are only used to indicate supported bit depths.   These
    ;* are flags only, they are not to be used as an actual bit depth.   The
    ;* absolute numbers 1, 2, 4, 8, 16, 24 and 32 are used to indicate actual
    ;* bit depths in a surface or for changing the display mode.
    ;*
    ;****************************************************************************
    ;*
    ;* 1 bit per pixel.
    ;*
    DDBD_1 equ 00004000h
    ;*
    ;* 2 bits per pixel.
    ;*
    DDBD_2 equ 00002000h
    ;*
    ;* 4 bits per pixel.
    ;*
    DDBD_4 equ 00001000h
    ;*
    ;* 8 bits per pixel.
    ;*
    DDBD_8 equ 00000800h
    ;*
    ;* 16 bits per pixel.
    ;*
    DDBD_16 equ 00000400h
    ;*
    ;* 24 bits per pixel.
    ;*
    DDBD_24 equ 00000200h
    ;*
    ;* 32 bits per pixel.
    ;*
    DDBD_32 equ 00000100h
    ;****************************************************************************
    ;*
    ;* DIRECTDRAWSURFACE SET/GET COLOR KEY FLAGS
    ;*
    ;****************************************************************************
    ;*
    ;* Set if the structure contains a color space.  Not set if the structure
    ;* contains a single color key.
    ;*
    DDCKEY_COLORSPACE equ 00000001h
    ;*
    ;* Set if the structure specifies a color key or color space which is to be
    ;* used as a destination color key for blt operations.
    ;*
    DDCKEY_DESTBLT equ 00000002h
    ;*
    ;* Set if the structure specifies a color key or color space which is to be
    ;* used as a destination color key for overlay operations.
    ;*
    DDCKEY_DESTOVERLAY equ 00000004h
    ;*
    ;* Set if the structure specifies a color key or color space which is to be
    ;* used as a source color key for blt operations.
    ;*
    DDCKEY_SRCBLT equ 00000008h
    ;*
    ;* Set if the structure specifies a color key or color space which is to be
    ;* used as a source color key for overlay operations.
    ;*
    DDCKEY_SRCOVERLAY equ 00000010h
    ;****************************************************************************
    ;*
    ;* DIRECTDRAW COLOR KEY CAPABILITY FLAGS
    ;*
    ;****************************************************************************
    ;*
    ;* Supports transparent blting using a color key to identify the replaceable
    ;* bits of the destination surface for RGB colors.
    ;*
    DDCKEYCAPS_DESTBLT equ 00000001h
    ;*
    ;* Supports transparent blting using a color space to identify the replaceable
    ;* bits of the destination surface for RGB colors.
    ;*
    DDCKEYCAPS_DESTBLTCLRSPACE equ 00000002h
    ;*
    ;* Supports transparent blting using a color space to identify the replaceable
    ;* bits of the destination surface for YUV colors.
    ;*
    DDCKEYCAPS_DESTBLTCLRSPACEYUV equ 00000004h
    ;*
    ;* Supports transparent blting using a color key to identify the replaceable
    ;* bits of the destination surface for YUV colors.
    ;*
    DDCKEYCAPS_DESTBLTYUV equ 00000008h
    ;*
    ;* Supports overlaying using colorkeying of the replaceable bits of the surface
    ;* being overlayed for RGB colors.
    ;*
    DDCKEYCAPS_DESTOVERLAY equ 00000010h
    ;*
    ;* Supports a color space as the color key for the destination for RGB colors.
    ;*
    DDCKEYCAPS_DESTOVERLAYCLRSPACE equ 00000020h
    ;*
    ;* Supports a color space as the color key for the destination for YUV colors.
    ;*
    DDCKEYCAPS_DESTOVERLAYCLRSPACEYUV equ 00000040h
    ;*
    ;* Supports only one active destination color key value for visible overlay
    ;* surfaces.
    ;*
    DDCKEYCAPS_DESTOVERLAYONEACTIVE equ 00000080h
    ;*
    ;* Supports overlaying using colorkeying of the replaceable bits of the
    ;* surface being overlayed for YUV colors.
    ;*
    DDCKEYCAPS_DESTOVERLAYYUV equ 00000100h
    ;*
    ;* Supports transparent blting using the color key for the source with
    ;* this surface for RGB colors.
    ;*
    DDCKEYCAPS_SRCBLT equ 00000200h
    ;*
    ;* Supports transparent blting using a color space for the source with
    ;* this surface for RGB colors.
    ;*
    DDCKEYCAPS_SRCBLTCLRSPACE equ 00000400h
    ;*
    ;* Supports transparent blting using a color space for the source with
    ;* this surface for YUV colors.
    ;*
    DDCKEYCAPS_SRCBLTCLRSPACEYUV equ 00000800h
    ;*
    ;* Supports transparent blting using the color key for the source with
    ;* this surface for YUV colors.
    ;*
    DDCKEYCAPS_SRCBLTYUV equ 00001000h
    ;*
    ;* Supports overlays using the color key for the source with this
    ;* overlay surface for RGB colors.
    ;*
    DDCKEYCAPS_SRCOVERLAY equ 00002000h
    ;*
    ;* Supports overlays using a color space as the source color key for
    ;* the overlay surface for RGB colors.
    ;*
    DDCKEYCAPS_SRCOVERLAYCLRSPACE equ 00004000h
    ;*
    ;* Supports overlays using a color space as the source color key for
    ;* the overlay surface for YUV colors.
    ;*
    DDCKEYCAPS_SRCOVERLAYCLRSPACEYUV equ 00008000h
    ;*
    ;* Supports only one active source color key value for visible
    ;* overlay surfaces.
    ;*
    DDCKEYCAPS_SRCOVERLAYONEACTIVE equ 00010000h
    ;*
    ;* Supports overlays using the color key for the source with this
    ;* overlay surface for YUV colors.
    ;*
    DDCKEYCAPS_SRCOVERLAYYUV equ 00020000h
    ;*
    ;* there are no bandwidth trade-offs for using colorkey with an overlay
    ;*
    DDCKEYCAPS_NOCOSTOVERLAY equ 00040000h
    ;****************************************************************************
    ;*
    ;* DIRECTDRAW PIXELFORMAT FLAGS
    ;*
    ;****************************************************************************
    ;*
    ;* The surface has alpha channel information in the pixel format.
    ;*
    DDPF_ALPHAPIXELS equ 00000001h
    ;*
    ;* The pixel format contains alpha only information
    ;*
    DDPF_ALPHA equ 00000002h
    ;*
    ;* The FourCC code is valid.
    ;*
    DDPF_FOURCC equ 00000004h
    ;*
    ;* The surface is 4-bit color indexed.
    ;*
    DDPF_PALETTEINDEXED4 equ 00000008h
    ;*
    ;* The surface is indexed into a palette which stores indices
    ;* into the destination surface's 8-bit palette.
    ;*
    DDPF_PALETTEINDEXEDTO8 equ 00000010h
    ;*
    ;* The surface is 8-bit color indexed.
    ;*
    DDPF_PALETTEINDEXED8 equ 00000020h
    ;*
    ;* The RGB data in the pixel format structure is valid.
    ;*
    DDPF_RGB equ 00000040h
    ;*
    ;* The surface will accept pixel data in the format specified
    ;* and compress it during the write.
    ;*
    DDPF_COMPRESSED equ 00000080h
    ;*
    ;* The surface will accept RGB data and translate it during
    ;* the write to YUV data.  The format of the data to be written
    ;* will be contained in the pixel format structure.  The DDPF_RGB
    ;* flag will be set.
    ;*
    DDPF_RGBTOYUV equ 00000100h
    ;*
    ;* pixel format is YUV - YUV data in pixel format struct is valid
    ;*
    DDPF_YUV equ 00000200h
    ;*
    ;* pixel format is a z buffer only surface
    ;*
    DDPF_ZBUFFER equ 00000400h
    ;*
    ;* The surface is 1-bit color indexed.
    ;*
    DDPF_PALETTEINDEXED1 equ 00000800h
    ;*
    ;* The surface is 2-bit color indexed.
    ;*
    DDPF_PALETTEINDEXED2 equ 00001000h
    ;*
    ;* The surface contains Z information in the pixels
    ;*
    DDPF_ZPIXELS equ 00002000h
    ;*
    ;* The surface contains stencil information along with Z
    ;*
    DDPF_STENCILBUFFER equ 00004000h
    ;*
    ;* Premultiplied alpha format -- the color components have been
    ;* premultiplied by the alpha component.
    ;*
    DDPF_ALPHAPREMULT equ 00008000h
    ;*
    ;* Luminance data in the pixel format is valid.
    ;* Use this flag for luminance-only or luminance+alpha surfaces,
    ;* the bit depth is then ddpf.dwLuminanceBitCount.
    ;*
    DDPF_LUMINANCE equ 00020000h
    ;*
    ;* Luminance data in the pixel format is valid.
    ;* Use this flag when hanging luminance off bumpmap surfaces,
    ;* the bit mask for the luminance portion of the pixel is then
    ;* ddpf.dwBumpLuminanceBitMask
    ;*
    DDPF_BUMPLUMINANCE equ 00040000h
    ;*
    ;* Bump map dUdV data in the pixel format is valid.
    ;*
    DDPF_BUMPDUDV equ 00080000h
    ;*===========================================================================
    ;*
    ;*
    ;* DIRECTDRAW CALLBACK FLAGS
    ;*
    ;*
    ;*==========================================================================*
    ;****************************************************************************
    ;*
    ;* DIRECTDRAW ENUMSURFACES FLAGS
    ;*
    ;****************************************************************************
    ;*
    ;* Enumerate all of the surfaces that meet the search criterion.
    ;*
    DDENUMSURFACES_ALL equ 00000001h
    ;*
    ;* A search hit is a surface that matches the surface description.
    ;*
    DDENUMSURFACES_MATCH equ 00000002h
    ;*
    ;* A search hit is a surface that does not match the surface description.
    ;*
    DDENUMSURFACES_NOMATCH equ 00000004h
    ;*
    ;* Enumerate the first surface that can be created which meets the search criterion.
    ;*
    DDENUMSURFACES_CANBECREATED equ 00000008h
    ;*
    ;* Enumerate the surfaces that already exist that meet the search criterion.
    ;*
    DDENUMSURFACES_DOESEXIST equ 00000010h
    ;****************************************************************************
    ;*
    ;* DIRECTDRAW SETDISPLAYMODE FLAGS
    ;*
    ;****************************************************************************
    ;*
    ;* The desired mode is a standard VGA mode
    ;*
    DDSDM_STANDARDVGAMODE equ 00000001h
    ;****************************************************************************
    ;*
    ;* DIRECTDRAW ENUMDISPLAYMODES FLAGS
    ;*
    ;****************************************************************************
    ;*
    ;* Enumerate Modes with different refresh rates.  EnumDisplayModes guarantees
    ;* that a particular mode will be enumerated only once.  This flag specifies whether
    ;* the refresh rate is taken into account when determining if a mode is unique.
    ;*
    DDEDM_REFRESHRATES equ 00000001h
    ;*
    ;* Enumerate VGA modes. Specify this flag if you wish to enumerate supported VGA
    ;* modes such as mode 0x13 in addition to the usual ModeX modes (which are always
    ;* enumerated if the application has previously called SetCooperativeLevel with the
    ;* DDSCL_ALLOWMODEX flag set).
    ;*
    DDEDM_STANDARDVGAMODES equ 00000002h
    ;****************************************************************************
    ;*
    ;* DIRECTDRAW SETCOOPERATIVELEVEL FLAGS
    ;*
    ;****************************************************************************
    ;*
    ;* Exclusive mode owner will be responsible for the entire primary surface.
    ;* GDI can be ignored. used with DD
    ;*
    DDSCL_FULLSCREEN equ 00000001h
    ;*
    ;* allow CTRL_ALT_DEL to work while in fullscreen exclusive mode
    ;*
    DDSCL_ALLOWREBOOT equ 00000002h
    ;*
    ;* prevents DDRAW from modifying the application window.
    ;* prevents DDRAW from minimize/restore the application window on activation.
    ;*
    DDSCL_NOWINDOWCHANGES equ 00000004h
    ;*
    ;* app wants to work as a regular Windows application
    ;*
    DDSCL_NORMAL equ 00000008h
    ;*
    ;* app wants exclusive access
    ;*
    DDSCL_EXCLUSIVE equ 00000010h
    ;*
    ;* app can deal with non-windows display modes
    ;*
    DDSCL_ALLOWMODEX equ 00000040h
    ;*
    ;* this window will receive the focus messages
    ;*
    DDSCL_SETFOCUSWINDOW equ 00000080h
    ;*
    ;* this window is associated with the DDRAW object and will
    ;* cover the screen in fullscreen mode
    ;*
    DDSCL_SETDEVICEWINDOW equ 00000100h
    ;*
    ;* app wants DDRAW to create a window to be associated with the
    ;* DDRAW object
    ;*
    DDSCL_CREATEDEVICEWINDOW equ 00000200h
    ;*
    ;* App explicitly asks DDRAW/D3D to be multithread safe. This makes D3D
    ;* take the global crtisec more frequently.
    ;*
    DDSCL_MULTITHREADED equ 00000400h
    ;*
    ;* App specifies that it would like to keep the FPU set up for optimal Direct3D
    ;* performance (single precision and exceptions disabled) so Direct3D
    ;* does not need to explicitly set the FPU each time. This is assumed by
    ;* default in DirectX 7. See also DDSCL_FPUPRESERVE
    ;*
    DDSCL_FPUSETUP equ 00000800h
    ;*
    ;* App specifies that it needs either double precision FPU or FPU exceptions
    ;* enabled. This makes Direct3D explicitly set the FPU state eah time it is
    ;* called. Setting the flag will reduce Direct3D performance. The flag is
    ;* assumed by default in DirectX 6 and earlier. See also DDSCL_FPUSETUP
    ;*
    DDSCL_FPUPRESERVE equ 00001000h
    ;****************************************************************************
    ;*
    ;* DIRECTDRAW BLT FLAGS
    ;*
    ;****************************************************************************
    ;*
    ;* Use the alpha information in the pixel format or the alpha channel surface
    ;* attached to the destination surface as the alpha channel for this blt.
    ;*
    DDBLT_ALPHADEST equ 00000001h
    ;*
    ;* Use the dwConstAlphaDest field in the DDBLTFX structure as the alpha channel
    ;* for the destination surface for this blt.
    ;*
    DDBLT_ALPHADESTCONSTOVERRIDE equ 00000002h
    ;*
    ;* The NEG suffix indicates that the destination surface becomes more
    ;* transparent as the alpha value increases. (0 is opaque)
    ;*
    DDBLT_ALPHADESTNEG equ 00000004h
    ;*
    ;* Use the lpDDSAlphaDest field in the DDBLTFX structure as the alpha
    ;* channel for the destination for this blt.
    ;*
    DDBLT_ALPHADESTSURFACEOVERRIDE equ 00000008h
    ;*
    ;* Use the dwAlphaEdgeBlend field in the DDBLTFX structure as the alpha channel
    ;* for the edges of the image that border the color key colors.
    ;*
    DDBLT_ALPHAEDGEBLEND equ 00000010h
    ;*
    ;* Use the alpha information in the pixel format or the alpha channel surface
    ;* attached to the source surface as the alpha channel for this blt.
    ;*
    DDBLT_ALPHASRC equ 00000020h
    ;*
    ;* Use the dwConstAlphaSrc field in the DDBLTFX structure as the alpha channel
    ;* for the source for this blt.
    ;*
    DDBLT_ALPHASRCCONSTOVERRIDE equ 00000040h
    ;*
    ;* The NEG suffix indicates that the source surface becomes more transparent
    ;* as the alpha value increases. (0 is opaque)
    ;*
    DDBLT_ALPHASRCNEG equ 00000080h
    ;*
    ;* Use the lpDDSAlphaSrc field in the DDBLTFX structure as the alpha channel
    ;* for the source for this blt.
    ;*
    DDBLT_ALPHASRCSURFACEOVERRIDE equ 00000100h
    ;*
    ;* Do this blt asynchronously through the FIFO in the order received.  If
    ;* there is no room in the hardware FIFO fail the call.
    ;*
    DDBLT_ASYNC equ 00000200h
    ;*
    ;* Uses the dwFillColor field in the DDBLTFX structure as the RGB color
    ;* to fill the destination rectangle on the destination surface with.
    ;*
    DDBLT_COLORFILL equ 00000400h
    ;*
    ;* Uses the dwDDFX field in the DDBLTFX structure to specify the effects
    ;* to use for the blt.
    ;*
    DDBLT_DDFX equ 00000800h
    ;*
    ;* Uses the dwDDROPS field in the DDBLTFX structure to specify the ROPS
    ;* that are not part of the Win32 API.
    ;*
    DDBLT_DDROPS equ 00001000h
    ;*
    ;* Use the color key associated with the destination surface.
    ;*
    DDBLT_KEYDEST equ 00002000h
    ;*
    ;* Use the dckDestColorkey field in the DDBLTFX structure as the color key
    ;* for the destination surface.
    ;*
    DDBLT_KEYDESTOVERRIDE equ 00004000h
    ;*
    ;* Use the color key associated with the source surface.
    ;*
    DDBLT_KEYSRC equ 00008000h
    ;*
    ;* Use the dckSrcColorkey field in the DDBLTFX structure as the color key
    ;* for the source surface.
    ;*
    DDBLT_KEYSRCOVERRIDE equ 00010000h
    ;*
    ;* Use the dwROP field in the DDBLTFX structure for the raster operation
    ;* for this blt.  These ROPs are the same as the ones defined in the Win32 API.
    ;*
    DDBLT_ROP equ 00020000h
    ;*
    ;* Use the dwRotationAngle field in the DDBLTFX structure as the angle
    ;* (specified in 1/100th of a degree) to rotate the surface.
    ;*
    DDBLT_ROTATIONANGLE equ 00040000h
    ;*
    ;* Z-buffered blt using the z-buffers attached to the source and destination
    ;* surfaces and the dwZBufferOpCode field in the DDBLTFX structure as the
    ;* z-buffer opcode.
    ;*
    DDBLT_ZBUFFER equ 00080000h
    ;*
    ;* Z-buffered blt using the dwConstDest Zfield and the dwZBufferOpCode field
    ;* in the DDBLTFX structure as the z-buffer and z-buffer opcode respectively
    ;* for the destination.
    ;*
    DDBLT_ZBUFFERDESTCONSTOVERRIDE equ 00100000h
    ;*
    ;* Z-buffered blt using the lpDDSDestZBuffer field and the dwZBufferOpCode
    ;* field in the DDBLTFX structure as the z-buffer and z-buffer opcode
    ;* respectively for the destination.
    ;*
    DDBLT_ZBUFFERDESTOVERRIDE equ 00200000h
    ;*
    ;* Z-buffered blt using the dwConstSrcZ field and the dwZBufferOpCode field
    ;* in the DDBLTFX structure as the z-buffer and z-buffer opcode respectively
    ;* for the source.
    ;*
    DDBLT_ZBUFFERSRCCONSTOVERRIDE equ 00400000h
    ;*
    ;* Z-buffered blt using the lpDDSSrcZBuffer field and the dwZBufferOpCode
    ;* field in the DDBLTFX structure as the z-buffer and z-buffer opcode
    ;* respectively for the source.
    ;*
    DDBLT_ZBUFFERSRCOVERRIDE equ 00800000h
    ;*
    ;* wait until the device is ready to handle the blt
    ;* this will cause blt to not return DDERR_WASSTILLDRAWING
    ;*
    DDBLT_WAIT equ 01000000h
    ;*
    ;* Uses the dwFillDepth field in the DDBLTFX structure as the depth value
    ;* to fill the destination rectangle on the destination Z-buffer surface
    ;* with.
    ;*
    DDBLT_DEPTHFILL equ 02000000h
    ;*
    ;* Return immediately (with DDERR_WASSTILLDRAWING) if the device is not
    ;* ready to schedule the blt at the time Blt() is called.
    ;*
    DDBLT_DONOTWAIT equ 08000000h
    ;*
    ;* These flags indicate a presentation blt (i.e. a blt
    ;* that moves surface contents from an offscreen back buffer to the primary
    ;* surface). The driver is not allowed to "queue"  more than three such blts.
    ;* The "end" of the presentation blt is indicated, since the
    ;* blt may be clipped, in which case the runtime will call the driver with 
    ;* several blts. All blts (even if not clipped) are tagged with DDBLT_PRESENTATION
    ;* and the last (even if not clipped) additionally with DDBLT_LAST_PRESENTATION.
    ;* Thus the true rule is that the driver must not schedule a DDBLT_PRESENTATION
    ;* blt if there are 3 or more DDBLT_PRESENTLAST blts in the hardware pipe.
    ;* If there are such blts in the pipe, the driver should return DDERR_WASSTILLDRAWING
    ;* until the oldest queued DDBLT_LAST_PRESENTATION blts has been retired (i.e. the
    ;* pixels have been actually written to the primary surface). Once the oldest blt
    ;* has been retired, the driver is free to schedule the current blt.
    ;* The goal is to provide a mechanism whereby the device's hardware queue never
    ;* gets more than 3 frames ahead of the frames being generated by the application.
    ;* When excessive queueing occurs, applications become unusable because the application
    ;* visibly lags user input, and such problems make windowed interactive applications impossible.
    ;* Some drivers may not have sufficient knowledge of their hardware's FIFO to know
    ;* when a certain blt has been retired. Such drivers should code cautiously, and 
    ;* simply not allow any frames to be queued at all. DDBLT_LAST_PRESENTATION should cause
    ;* such drivers to return DDERR_WASSTILLDRAWING until the accelerator is completely
    ;* finished- exactly as if the application had called Lock on the source surface
    ;* before calling Blt. 
    ;* In other words, the driver is allowed and encouraged to 
    ;* generate as much latency as it can, but never more than 3 frames worth.
    ;* Implementation detail: Drivers should count blts against the SOURCE surface, not
    ;* against the primary surface. This enables multiple parallel windowed application
    ;* to function more optimally.
    ;* This flag is passed only to DX8 or higher drivers.
    ;*
    ;* APPLICATIONS DO NOT SET THESE FLAGS. THEY ARE SET BY THE DIRECTDRAW RUNTIME.
    ;* 
    ;*
    DDBLT_PRESENTATION equ 10000000h
    DDBLT_LAST_PRESENTATION equ 20000000h
    ;*
    ;* If DDBLT_EXTENDED_FLAGS is set, then the driver should re-interpret
    ;* other flags according to the definitions that follow.
    ;* For example, bit 0 (0x00000001L) means DDBLT_ALPHADEST, unless
    ;* DDBLT_EXTENDED_FLAGS is also set, in which case bit 0 means
    ;* DDBLT_EXTENDED_LINEAR_CONTENT.
    ;* Only DirectX9 and higher drivers will be given extended blt flags.
    ;* Only flags explicitly mentioned here should be re-interpreted.
    ;* All other flags retain their original meanings.
    ;*
    ;* List of re-interpreted flags:
    ;*
    ;* Bit Hex value   New meaning                                  old meaning
    ;* ---------------------------------------------------------------
    ;*  2  0x00000004  DDBLT_EXTENDED_LINEAR_CONTENT                DDBLT_ALPHADESTNEG
    ;*  4  0x00000010  DDBLT_EXTENDED_PRESENTATION_STRETCHFACTOR    DDBLT_ALPHAEDGEBLEND
    ;*
    ;*
    ;* NOTE: APPLICATIONS SHOULD NOT SET THIS FLAG. THIS FLAG IS INTENDED
    ;* FOR USE BY THE DIRECT3D RUNTIME.
    ;*
    DDBLT_EXTENDED_FLAGS equ 40000000h
    ;*
    ;* EXTENDED FLAG. SEE DEFINITION OF DDBLT_EXTENDED_FLAGS.
    ;* This flag indidcates that the source surface contains content in a
    ;* linear color space. The driver may perform gamma correction to the
    ;* desktop color space (i.e. sRGB, gamma 2.2) as part of this blt.
    ;* If the device can perform such a conversion as part of the copy,
    ;* the driver should also set D3DCAPS3_LINEAR_TO_SRGB_PRESENTATION
    ;*
    ;* NOTE: APPLICATIONS SHOULD NOT SET THIS FLAG. THIS FLAG IS INTENDED
    ;* FOR USE BY THE DIRECT3D RUNTIME. Use IDirect3DSwapChain9::Present
    ;* and specify D3DPRESENT_LINEAR_CONTENT in order to use this functionality.
    ;*
    DDBLT_EXTENDED_LINEAR_CONTENT equ 00000004h
    ;****************************************************************************
    ;*
    ;* BLTFAST FLAGS
    ;*
    ;****************************************************************************
    DDBLTFAST_NOCOLORKEY equ 00000000h
    DDBLTFAST_SRCCOLORKEY equ 00000001h
    DDBLTFAST_DESTCOLORKEY equ 00000002h
    DDBLTFAST_WAIT equ 00000010h
    DDBLTFAST_DONOTWAIT equ 00000020h
    ;****************************************************************************
    ;*
    ;* FLIP FLAGS
    ;*
    ;****************************************************************************
    DDFLIP_WAIT equ 00000001h
    ;*
    ;* Indicates that the target surface contains the even field of video data.
    ;* This flag is only valid with an overlay surface.
    ;*
    DDFLIP_EVEN equ 00000002h
    ;*
    ;* Indicates that the target surface contains the odd field of video data.
    ;* This flag is only valid with an overlay surface.
    ;*
    DDFLIP_ODD equ 00000004h
    ;*
    ;* Causes DirectDraw to perform the physical flip immediately and return
    ;* to the application. Typically, what was the front buffer but is now the back
    ;* buffer will still be visible (depending on timing) until the next vertical
    ;* retrace. Subsequent operations involving the two flipped surfaces will
    ;* not check to see if the physical flip has finished (i.e. will not return
    ;* DDERR_WASSTILLDRAWING for that reason (but may for other reasons)).
    ;* This allows an application to perform Flips at a higher frequency than the
    ;* monitor refresh rate, but may introduce visible artifacts.
    ;* Only effective if DDCAPS2_FLIPNOVSYNC is set. If that bit is not set,
    ;* DDFLIP_NOVSYNC has no effect.
    ;*
    DDFLIP_NOVSYNC equ 00000008h
    ;*
    ;* Flip Interval Flags. These flags indicate how many vertical retraces to wait between
    ;* each flip. The default is one. DirectDraw will return DDERR_WASSTILLDRAWING for each
    ;* surface involved in the flip until the specified number of vertical retraces has
    ;* ocurred. Only effective if DDCAPS2_FLIPINTERVAL is set. If that bit is not set,
    ;* DDFLIP_INTERVALn has no effect.
    ;*
    ;*
    ;* DirectDraw will flip on every other vertical sync
    ;*
    DDFLIP_INTERVAL2 equ 02000000h
    ;*
    ;* DirectDraw will flip on every third vertical sync
    ;*
    DDFLIP_INTERVAL3 equ 03000000h
    ;*
    ;* DirectDraw will flip on every fourth vertical sync
    ;*
    DDFLIP_INTERVAL4 equ 04000000h
    ;*
    ;* DirectDraw will flip and display a main stereo surface
    ;*
    DDFLIP_STEREO equ 00000010h
    ;*
    ;* On IDirectDrawSurface7 and higher interfaces, the default is DDFLIP_WAIT. If you wish
    ;* to override the default and use time when the accelerator is busy (as denoted by
    ;* the DDERR_WASSTILLDRAWING return code) then use DDFLIP_DONOTWAIT.
    ;*
    DDFLIP_DONOTWAIT equ 00000020h
    ;****************************************************************************
    ;*
    ;* DIRECTDRAW SURFACE OVERLAY FLAGS
    ;*
    ;****************************************************************************
    ;*
    ;* Use the alpha information in the pixel format or the alpha channel surface
    ;* attached to the destination surface as the alpha channel for the
    ;* destination overlay.
    ;*
    DDOVER_ALPHADEST equ 00000001h
    ;*
    ;* Use the dwConstAlphaDest field in the DDOVERLAYFX structure as the
    ;* destination alpha channel for this overlay.
    ;*
    DDOVER_ALPHADESTCONSTOVERRIDE equ 00000002h
    ;*
    ;* The NEG suffix indicates that the destination surface becomes more
    ;* transparent as the alpha value increases.
    ;*
    DDOVER_ALPHADESTNEG equ 00000004h
    ;*
    ;* Use the lpDDSAlphaDest field in the DDOVERLAYFX structure as the alpha
    ;* channel destination for this overlay.
    ;*
    DDOVER_ALPHADESTSURFACEOVERRIDE equ 00000008h
    ;*
    ;* Use the dwAlphaEdgeBlend field in the DDOVERLAYFX structure as the alpha
    ;* channel for the edges of the image that border the color key colors.
    ;*
    DDOVER_ALPHAEDGEBLEND equ 00000010h
    ;*
    ;* Use the alpha information in the pixel format or the alpha channel surface
    ;* attached to the source surface as the source alpha channel for this overlay.
    ;*
    DDOVER_ALPHASRC equ 00000020h
    ;*
    ;* Use the dwConstAlphaSrc field in the DDOVERLAYFX structure as the source
    ;* alpha channel for this overlay.
    ;*
    DDOVER_ALPHASRCCONSTOVERRIDE equ 00000040h
    ;*
    ;* The NEG suffix indicates that the source surface becomes more transparent
    ;* as the alpha value increases.
    ;*
    DDOVER_ALPHASRCNEG equ 00000080h
    ;*
    ;* Use the lpDDSAlphaSrc field in the DDOVERLAYFX structure as the alpha channel
    ;* source for this overlay.
    ;*
    DDOVER_ALPHASRCSURFACEOVERRIDE equ 00000100h
    ;*
    ;* Turn this overlay off.
    ;*
    DDOVER_HIDE equ 00000200h
    ;*
    ;* Use the color key associated with the destination surface.
    ;*
    DDOVER_KEYDEST equ 00000400h
    ;*
    ;* Use the dckDestColorkey field in the DDOVERLAYFX structure as the color key
    ;* for the destination surface
    ;*
    DDOVER_KEYDESTOVERRIDE equ 00000800h
    ;*
    ;* Use the color key associated with the source surface.
    ;*
    DDOVER_KEYSRC equ 00001000h
    ;*
    ;* Use the dckSrcColorkey field in the DDOVERLAYFX structure as the color key
    ;* for the source surface.
    ;*
    DDOVER_KEYSRCOVERRIDE equ 00002000h
    ;*
    ;* Turn this overlay on.
    ;*
    DDOVER_SHOW equ 00004000h
    ;*
    ;* Add a dirty rect to an emulated overlayed surface.
    ;*
    DDOVER_ADDDIRTYRECT equ 00008000h
    ;*
    ;* Redraw all dirty rects on an emulated overlayed surface.
    ;*
    DDOVER_REFRESHDIRTYRECTS equ 00010000h
    ;*
    ;* Redraw the entire surface on an emulated overlayed surface.
    ;*
    DDOVER_REFRESHALL equ 00020000h
    ;*
    ;* Use the overlay FX flags to define special overlay FX
    ;*
    DDOVER_DDFX equ 00080000h
    ;*
    ;* Autoflip the overlay when ever the video port autoflips
    ;*
    DDOVER_AUTOFLIP equ 00100000h
    ;*
    ;* Display each field of video port data individually without
    ;* causing any jittery artifacts
    ;*
    DDOVER_BOB equ 00200000h
    ;*
    ;* Indicates that bob/weave decisions should not be overridden by other
    ;* interfaces.
    ;*
    DDOVER_OVERRIDEBOBWEAVE equ 00400000h
    ;*
    ;* Indicates that the surface memory is composed of interleaved fields.
    ;*
    DDOVER_INTERLEAVED equ 00800000h
    ;*
    ;* Indicates that bob will be performed using hardware rather than
    ;* software or emulated.
    ;*
    DDOVER_BOBHARDWARE equ 01000000h
    ;*
    ;* Indicates that overlay FX structure contains valid ARGB scaling factors.
    ;*
    DDOVER_ARGBSCALEFACTORS equ 02000000h
    ;*
    ;* Indicates that ARGB scaling factors can be degraded to fit driver capabilities.
    ;*
    DDOVER_DEGRADEARGBSCALING equ 04000000h
    ifdef COMBOX_SANDBOX
      DX_LONGHORN_PRESERVEDC equ <>
    endif
    ifdef DX_LONGHORN_PRESERVEDC
      ;****************************************************************************
      ;*
      ;* DIRECTDRAWSURFACE SETSURFACEDESC FLAGS
      ;*
      ;****************************************************************************
      ;*
      ;* The default.  The GDI DC will be tore down.
      ;*
      DDSETSURFACEDESC_RECREATEDC equ 00000000h; default

      ;*
      ;* The default.  The GDI DC will be kept.
      ;*
      DDSETSURFACEDESC_PRESERVEDC equ 00000001h
    endif
    ; DX_LONGHORN_PRESERVEDC
    ;****************************************************************************
    ;*
    ;* DIRECTDRAWSURFACE LOCK FLAGS
    ;*
    ;****************************************************************************
    ;*
    ;* The default.  Set to indicate that Lock should return a valid memory pointer
    ;* to the top of the specified rectangle.  If no rectangle is specified then a
    ;* pointer to the top of the surface is returned.
    ;*
    DDLOCK_SURFACEMEMORYPTR equ 00000000h; default

    ;*
    ;* Set to indicate that Lock should wait until it can obtain a valid memory
    ;* pointer before returning.  If this bit is set, Lock will never return
    ;* DDERR_WASSTILLDRAWING.
    ;*
    DDLOCK_WAIT equ 00000001h
    ;*
    ;* Set if an event handle is being passed to Lock.  Lock will trigger the event
    ;* when it can return the surface memory pointer requested.
    ;*
    DDLOCK_EVENT equ 00000002h
    ;*
    ;* Indicates that the surface being locked will only be read from.
    ;*
    DDLOCK_READONLY equ 00000010h
    ;*
    ;* Indicates that the surface being locked will only be written to
    ;*
    DDLOCK_WRITEONLY equ 00000020h
    ;*
    ;* Indicates that a system wide lock should not be taken when this surface
    ;* is locked. This has several advantages (cursor responsiveness, ability
    ;* to call more Windows functions, easier debugging) when locking video
    ;* memory surfaces. However, an application specifying this flag must
    ;* comply with a number of conditions documented in the help file.
    ;* Furthermore, this flag cannot be specified when locking the primary.
    ;*
    DDLOCK_NOSYSLOCK equ 00000800h
    ;*
    ;* Used only with Direct3D Vertex Buffer Locks. Indicates that no vertices
    ;* that were referred to in Draw*PrimtiveVB calls since the start of the
    ;* frame (or the last lock without this flag) will be modified during the
    ;* lock. This can be useful when one is only appending data to the vertex
    ;* buffer
    ;*
    DDLOCK_NOOVERWRITE equ 00001000h
    ;*
    ;* Indicates that no assumptions will be made about the contents of the
    ;* surface or vertex buffer during this lock.
    ;* This enables two things:
    ;* -    Direct3D or the driver may provide an alternative memory
    ;*      area as the vertex buffer. This is useful when one plans to clear the
    ;*      contents of the vertex buffer and fill in new data.
    ;* -    Drivers sometimes store surface data in a re-ordered format.
    ;*      When the application locks the surface, the driver is forced to un-re-order
    ;*      the surface data before allowing the application to see the surface contents.
    ;*      This flag is a hint to the driver that it can skip the un-re-ordering process
    ;*      since the application plans to overwrite every single pixel in the surface
    ;*      or locked rectangle (and so erase any un-re-ordered pixels anyway).
    ;*      Applications should always set this flag when they intend to overwrite the entire
    ;*      surface or locked rectangle.
    ;*
    DDLOCK_DISCARDCONTENTS equ 00002000h
    ;*
    ;* DDLOCK_OKTOSWAP is an older, less informative name for DDLOCK_DISCARDCONTENTS
    ;*
    DDLOCK_OKTOSWAP equ 00002000h
    ;*
    ;* On IDirectDrawSurface7 and higher interfaces, the default is DDLOCK_WAIT. If you wish
    ;* to override the default and use time when the accelerator is busy (as denoted by
    ;* the DDERR_WASSTILLDRAWING return code) then use DDLOCK_DONOTWAIT.
    ;*
    DDLOCK_DONOTWAIT equ 00004000h
    ;*
    ;* This indicates volume texture lock with front and back specified.
    ;*
    DDLOCK_HASVOLUMETEXTUREBOXRECT equ 00008000h
    ;*
    ;* This indicates that the driver should not update dirty rect information for this lock.
    ;*
    DDLOCK_NODIRTYUPDATE equ 00010000h
    ;****************************************************************************
    ;*
    ;* DIRECTDRAWSURFACE PAGELOCK FLAGS
    ;*
    ;****************************************************************************
    ;*
    ;* No flags defined at present
    ;*
    ;****************************************************************************
    ;*
    ;* DIRECTDRAWSURFACE PAGEUNLOCK FLAGS
    ;*
    ;****************************************************************************
    ;*
    ;* No flags defined at present
    ;*
    ;****************************************************************************
    ;*
    ;* DIRECTDRAWSURFACE BLT FX FLAGS
    ;*
    ;****************************************************************************
    ;*
    ;* If stretching, use arithmetic stretching along the Y axis for this blt.
    ;*
    DDBLTFX_ARITHSTRETCHY equ 00000001h
    ;*
    ;* Do this blt mirroring the surface left to right.  Spin the
    ;* surface around its y-axis.
    ;*
    DDBLTFX_MIRRORLEFTRIGHT equ 00000002h
    ;*
    ;* Do this blt mirroring the surface up and down.  Spin the surface
    ;* around its x-axis.
    ;*
    DDBLTFX_MIRRORUPDOWN equ 00000004h
    ;*
    ;* Schedule this blt to avoid tearing.
    ;*
    DDBLTFX_NOTEARING equ 00000008h
    ;*
    ;* Do this blt rotating the surface one hundred and eighty degrees.
    ;*
    DDBLTFX_ROTATE180 equ 00000010h
    ;*
    ;* Do this blt rotating the surface two hundred and seventy degrees.
    ;*
    DDBLTFX_ROTATE270 equ 00000020h
    ;*
    ;* Do this blt rotating the surface ninety degrees.
    ;*
    DDBLTFX_ROTATE90 equ 00000040h
    ;*
    ;* Do this z blt using dwZBufferLow and dwZBufferHigh as  range values
    ;* specified to limit the bits copied from the source surface.
    ;*
    DDBLTFX_ZBUFFERRANGE equ 00000080h
    ;*
    ;* Do this z blt adding the dwZBufferBaseDest to each of the sources z values
    ;* before comparing it with the desting z values.
    ;*
    DDBLTFX_ZBUFFERBASEDEST equ 00000100h
    ;****************************************************************************
    ;*
    ;* DIRECTDRAWSURFACE OVERLAY FX FLAGS
    ;*
    ;****************************************************************************
    ;*
    ;* If stretching, use arithmetic stretching along the Y axis for this overlay.
    ;*
    DDOVERFX_ARITHSTRETCHY equ 00000001h
    ;*
    ;* Mirror the overlay across the vertical axis
    ;*
    DDOVERFX_MIRRORLEFTRIGHT equ 00000002h
    ;*
    ;* Mirror the overlay across the horizontal axis
    ;*
    DDOVERFX_MIRRORUPDOWN equ 00000004h
    ;*
    ;* Deinterlace the overlay, if possible
    ;*
    DDOVERFX_DEINTERLACE equ 00000008h
    ;****************************************************************************
    ;*
    ;* DIRECTDRAW WAITFORVERTICALBLANK FLAGS
    ;*
    ;****************************************************************************
    ;*
    ;* return when the vertical blank interval begins
    ;*
    DDWAITVB_BLOCKBEGIN equ 00000001h
    ;*
    ;* set up an event to trigger when the vertical blank begins
    ;*
    DDWAITVB_BLOCKBEGINEVENT equ 00000002h
    ;*
    ;* return when the vertical blank interval ends and display begins
    ;*
    DDWAITVB_BLOCKEND equ 00000004h
    ;****************************************************************************
    ;*
    ;* DIRECTDRAW GETFLIPSTATUS FLAGS
    ;*
    ;****************************************************************************
    ;*
    ;* is it OK to flip now?
    ;*
    DDGFS_CANFLIP equ 00000001h
    ;*
    ;* is the last flip finished?
    ;*
    DDGFS_ISFLIPDONE equ 00000002h
    ;****************************************************************************
    ;*
    ;* DIRECTDRAW GETBLTSTATUS FLAGS
    ;*
    ;****************************************************************************
    ;*
    ;* is it OK to blt now?
    ;*
    DDGBS_CANBLT equ 00000001h
    ;*
    ;* is the blt to the surface finished?
    ;*
    DDGBS_ISBLTDONE equ 00000002h
    ;****************************************************************************
    ;*
    ;* DIRECTDRAW ENUMOVERLAYZORDER FLAGS
    ;*
    ;****************************************************************************
    ;*
    ;* Enumerate overlays back to front.
    ;*
    DDENUMOVERLAYZ_BACKTOFRONT equ 00000000h
    ;*
    ;* Enumerate overlays front to back
    ;*
    DDENUMOVERLAYZ_FRONTTOBACK equ 00000001h
    ;****************************************************************************
    ;*
    ;* DIRECTDRAW UPDATEOVERLAYZORDER FLAGS
    ;*
    ;****************************************************************************
    ;*
    ;* Send overlay to front
    ;*
    DDOVERZ_SENDTOFRONT equ 00000000h
    ;*
    ;* Send overlay to back
    ;*
    DDOVERZ_SENDTOBACK equ 00000001h
    ;*
    ;* Move Overlay forward
    ;*
    DDOVERZ_MOVEFORWARD equ 00000002h
    ;*
    ;* Move Overlay backward
    ;*
    DDOVERZ_MOVEBACKWARD equ 00000003h
    ;*
    ;* Move Overlay in front of relative surface
    ;*
    DDOVERZ_INSERTINFRONTOF equ 00000004h
    ;*
    ;* Move Overlay in back of relative surface
    ;*
    DDOVERZ_INSERTINBACKOF equ 00000005h
    ;****************************************************************************
    ;*
    ;* DIRECTDRAW SETGAMMARAMP FLAGS
    ;*
    ;****************************************************************************
    ;*
    ;* Request calibrator to adjust the gamma ramp according to the physical
    ;* properties of the display so that the result should appear identical
    ;* on all systems.
    ;*
    DDSGR_CALIBRATE equ 00000001h
    ;****************************************************************************
    ;*
    ;* DIRECTDRAW STARTMODETEST FLAGS
    ;*
    ;****************************************************************************
    ;*
    ;* Indicates that the mode being tested has passed
    ;*
    DDSMT_ISTESTREQUIRED equ 00000001h
    ;****************************************************************************
    ;*
    ;* DIRECTDRAW EVALUATEMODE FLAGS
    ;*
    ;****************************************************************************
    ;*
    ;* Indicates that the mode being tested has passed
    ;*
    DDEM_MODEPASSED equ 00000001h
    ;*
    ;* Indicates that the mode being tested has failed
    ;*
    DDEM_MODEFAILED equ 00000002h
    ;*===========================================================================
    ;*
    ;*
    ;* DIRECTDRAW RETURN CODES
    ;*
    ;* The return values from DirectDraw Commands and Surface that return an HRESULT
    ;* are codes from DirectDraw concerning the results of the action
    ;* requested by DirectDraw.
    ;*
    ;*==========================================================================*
    ;*
    ;* Status is OK
    ;*
    ;* Issued by: DirectDraw Commands and all callbacks
    ;*
    DD_OK equ <S_OK>
    DD_FALSE equ <S_FALSE>
    ;****************************************************************************
    ;*
    ;* DIRECTDRAW ENUMCALLBACK RETURN VALUES
    ;*
    ;* EnumCallback returns are used to control the flow of the DIRECTDRAW and
    ;* DIRECTDRAWSURFACE object enumerations.   They can only be returned by
    ;* enumeration callback routines.
    ;*
    ;****************************************************************************
    ;*
    ;* stop the enumeration
    ;*
    DDENUMRET_CANCEL equ 0
    ;*
    ;* continue the enumeration
    ;*
    DDENUMRET_OK equ 1
    ;****************************************************************************
    ;*
    ;* DIRECTDRAW ERRORS
    ;*
    ;* Errors are represented by negative values and cannot be combined.
    ;*
    ;****************************************************************************
    ;*
    ;* This object is already initialized
    ;*
    DDERR_ALREADYINITIALIZED equ MAKE_DDHRESULT(5)
    ;*
    ;* This surface can not be attached to the requested surface.
    ;*
    DDERR_CANNOTATTACHSURFACE equ MAKE_DDHRESULT(10)
    ;*
    ;* This surface can not be detached from the requested surface.
    ;*
    DDERR_CANNOTDETACHSURFACE equ MAKE_DDHRESULT(20)
    ;*
    ;* Support is currently not available.
    ;*
    DDERR_CURRENTLYNOTAVAIL equ MAKE_DDHRESULT(40)
    ;*
    ;* An exception was encountered while performing the requested operation
    ;*
    DDERR_EXCEPTION equ MAKE_DDHRESULT(55)
    ;*
    ;* Generic failure.
    ;*
    DDERR_GENERIC equ <E_FAIL>
    ;*
    ;* Height of rectangle provided is not a multiple of reqd alignment
    ;*
    DDERR_HEIGHTALIGN equ MAKE_DDHRESULT(90)
    ;*
    ;* Unable to match primary surface creation request with existing
    ;* primary surface.
    ;*
    DDERR_INCOMPATIBLEPRIMARY equ MAKE_DDHRESULT(95)
    ;*
    ;* One or more of the caps bits passed to the callback are incorrect.
    ;*
    DDERR_INVALIDCAPS equ MAKE_DDHRESULT(100)
    ;*
    ;* DirectDraw does not support provided Cliplist.
    ;*
    DDERR_INVALIDCLIPLIST equ MAKE_DDHRESULT(110)
    ;*
    ;* DirectDraw does not support the requested mode
    ;*
    DDERR_INVALIDMODE equ MAKE_DDHRESULT(120)
    ;*
    ;* DirectDraw received a pointer that was an invalid DIRECTDRAW object.
    ;*
    DDERR_INVALIDOBJECT equ MAKE_DDHRESULT(130)
    ;*
    ;* One or more of the parameters passed to the callback function are
    ;* incorrect.
    ;*
    DDERR_INVALIDPARAMS equ <E_INVALIDARG>
    ;*
    ;* pixel format was invalid as specified
    ;*
    DDERR_INVALIDPIXELFORMAT equ MAKE_DDHRESULT(145)
    ;*
    ;* Rectangle provided was invalid.
    ;*
    DDERR_INVALIDRECT equ MAKE_DDHRESULT(150)
    ;*
    ;* Operation could not be carried out because one or more surfaces are locked
    ;*
    DDERR_LOCKEDSURFACES equ MAKE_DDHRESULT(160)
    ;*
    ;* There is no 3D present.
    ;*
    DDERR_NO3D equ MAKE_DDHRESULT(170)
    ;*
    ;* Operation could not be carried out because there is no alpha accleration
    ;* hardware present or available.
    ;*
    DDERR_NOALPHAHW equ MAKE_DDHRESULT(180)
    ;*
    ;* Operation could not be carried out because there is no stereo
    ;* hardware present or available.
    ;*
    DDERR_NOSTEREOHARDWARE equ MAKE_DDHRESULT(181)
    ;*
    ;* Operation could not be carried out because there is no hardware
    ;* present which supports stereo surfaces
    ;*
    DDERR_NOSURFACELEFT equ MAKE_DDHRESULT(182)
    ;*
    ;* no clip list available
    ;*
    DDERR_NOCLIPLIST equ MAKE_DDHRESULT(205)
    ;*
    ;* Operation could not be carried out because there is no color conversion
    ;* hardware present or available.
    ;*
    DDERR_NOCOLORCONVHW equ MAKE_DDHRESULT(210)
    ;*
    ;* Create function called without DirectDraw object method SetCooperativeLevel
    ;* being called.
    ;*
    DDERR_NOCOOPERATIVELEVELSET equ MAKE_DDHRESULT(212)
    ;*
    ;* Surface doesn't currently have a color key
    ;*
    DDERR_NOCOLORKEY equ MAKE_DDHRESULT(215)
    ;*
    ;* Operation could not be carried out because there is no hardware support
    ;* of the dest color key.
    ;*
    DDERR_NOCOLORKEYHW equ MAKE_DDHRESULT(220)
    ;*
    ;* No DirectDraw support possible with current display driver
    ;*
    DDERR_NODIRECTDRAWSUPPORT equ MAKE_DDHRESULT(222)
    ;*
    ;* Operation requires the application to have exclusive mode but the
    ;* application does not have exclusive mode.
    ;*
    DDERR_NOEXCLUSIVEMODE equ MAKE_DDHRESULT(225)
    ;*
    ;* Flipping visible surfaces is not supported.
    ;*
    DDERR_NOFLIPHW equ MAKE_DDHRESULT(230)
    ;*
    ;* There is no GDI present.
    ;*
    DDERR_NOGDI equ MAKE_DDHRESULT(240)
    ;*
    ;* Operation could not be carried out because there is no hardware present
    ;* or available.
    ;*
    DDERR_NOMIRRORHW equ MAKE_DDHRESULT(250)
    ;*
    ;* Requested item was not found
    ;*
    DDERR_NOTFOUND equ MAKE_DDHRESULT(255)
    ;*
    ;* Operation could not be carried out because there is no overlay hardware
    ;* present or available.
    ;*
    DDERR_NOOVERLAYHW equ MAKE_DDHRESULT(260)
    ;*
    ;* Operation could not be carried out because the source and destination
    ;* rectangles are on the same surface and overlap each other.
    ;*
    DDERR_OVERLAPPINGRECTS equ MAKE_DDHRESULT(270)
    ;*
    ;* Operation could not be carried out because there is no appropriate raster
    ;* op hardware present or available.
    ;*
    DDERR_NORASTEROPHW equ MAKE_DDHRESULT(280)
    ;*
    ;* Operation could not be carried out because there is no rotation hardware
    ;* present or available.
    ;*
    DDERR_NOROTATIONHW equ MAKE_DDHRESULT(290)
    ;*
    ;* Operation could not be carried out because there is no hardware support
    ;* for stretching
    ;*
    DDERR_NOSTRETCHHW equ MAKE_DDHRESULT(310)
    ;*
    ;* DirectDrawSurface is not in 4 bit color palette and the requested operation
    ;* requires 4 bit color palette.
    ;*
    DDERR_NOT4BITCOLOR equ MAKE_DDHRESULT(316)
    ;*
    ;* DirectDrawSurface is not in 4 bit color index palette and the requested
    ;* operation requires 4 bit color index palette.
    ;*
    DDERR_NOT4BITCOLORINDEX equ MAKE_DDHRESULT(317)
    ;*
    ;* DirectDraw Surface is not in 8 bit color mode and the requested operation
    ;* requires 8 bit color.
    ;*
    DDERR_NOT8BITCOLOR equ MAKE_DDHRESULT(320)
    ;*
    ;* Operation could not be carried out because there is no texture mapping
    ;* hardware present or available.
    ;*
    DDERR_NOTEXTUREHW equ MAKE_DDHRESULT(330)
    ;*
    ;* Operation could not be carried out because there is no hardware support
    ;* for vertical blank synchronized operations.
    ;*
    DDERR_NOVSYNCHW equ MAKE_DDHRESULT(335)
    ;*
    ;* Operation could not be carried out because there is no hardware support
    ;* for zbuffer blting.
    ;*
    DDERR_NOZBUFFERHW equ MAKE_DDHRESULT(340)
    ;*
    ;* Overlay surfaces could not be z layered based on their BltOrder because
    ;* the hardware does not support z layering of overlays.
    ;*
    DDERR_NOZOVERLAYHW equ MAKE_DDHRESULT(350)
    ;*
    ;* The hardware needed for the requested operation has already been
    ;* allocated.
    ;*
    DDERR_OUTOFCAPS equ MAKE_DDHRESULT(360)
    ;*
    ;* DirectDraw does not have enough memory to perform the operation.
    ;*
    DDERR_OUTOFMEMORY equ <E_OUTOFMEMORY>
    ;*
    ;* DirectDraw does not have enough memory to perform the operation.
    ;*
    DDERR_OUTOFVIDEOMEMORY equ MAKE_DDHRESULT(380)
    ;*
    ;* hardware does not support clipped overlays
    ;*
    DDERR_OVERLAYCANTCLIP equ MAKE_DDHRESULT(382)
    ;*
    ;* Can only have ony color key active at one time for overlays
    ;*
    DDERR_OVERLAYCOLORKEYONLYONEACTIVE equ MAKE_DDHRESULT(384)
    ;*
    ;* Access to this palette is being refused because the palette is already
    ;* locked by another thread.
    ;*
    DDERR_PALETTEBUSY equ MAKE_DDHRESULT(387)
    ;*
    ;* No src color key specified for this operation.
    ;*
    DDERR_COLORKEYNOTSET equ MAKE_DDHRESULT(400)
    ;*
    ;* This surface is already attached to the surface it is being attached to.
    ;*
    DDERR_SURFACEALREADYATTACHED equ MAKE_DDHRESULT(410)
    ;*
    ;* This surface is already a dependency of the surface it is being made a
    ;* dependency of.
    ;*
    DDERR_SURFACEALREADYDEPENDENT equ MAKE_DDHRESULT(420)
    ;*
    ;* Access to this surface is being refused because the surface is already
    ;* locked by another thread.
    ;*
    DDERR_SURFACEBUSY equ MAKE_DDHRESULT(430)
    ;*
    ;* Access to this surface is being refused because no driver exists
    ;* which can supply a pointer to the surface.
    ;* This is most likely to happen when attempting to lock the primary
    ;* surface when no DCI provider is present.
    ;* Will also happen on attempts to lock an optimized surface.
    ;*
    DDERR_CANTLOCKSURFACE equ MAKE_DDHRESULT(435)
    ;*
    ;* Access to Surface refused because Surface is obscured.
    ;*
    DDERR_SURFACEISOBSCURED equ MAKE_DDHRESULT(440)
    ;*
    ;* Access to this surface is being refused because the surface is gone.
    ;* The DIRECTDRAWSURFACE object representing this surface should
    ;* have Restore called on it.
    ;*
    DDERR_SURFACELOST equ MAKE_DDHRESULT(450)
    ;*
    ;* The requested surface is not attached.
    ;*
    DDERR_SURFACENOTATTACHED equ MAKE_DDHRESULT(460)
    ;*
    ;* Height requested by DirectDraw is too large.
    ;*
    DDERR_TOOBIGHEIGHT equ MAKE_DDHRESULT(470)
    ;*
    ;* Size requested by DirectDraw is too large --  The individual height and
    ;* width are OK.
    ;*
    DDERR_TOOBIGSIZE equ MAKE_DDHRESULT(480)
    ;*
    ;* Width requested by DirectDraw is too large.
    ;*
    DDERR_TOOBIGWIDTH equ MAKE_DDHRESULT(490)
    ;*
    ;* Action not supported.
    ;*
    DDERR_UNSUPPORTED equ <E_NOTIMPL>
    ;*
    ;* Pixel format requested is unsupported by DirectDraw
    ;*
    DDERR_UNSUPPORTEDFORMAT equ MAKE_DDHRESULT(510)
    ;*
    ;* Bitmask in the pixel format requested is unsupported by DirectDraw
    ;*
    DDERR_UNSUPPORTEDMASK equ MAKE_DDHRESULT(520)
    ;*
    ;* The specified stream contains invalid data
    ;*
    DDERR_INVALIDSTREAM equ MAKE_DDHRESULT(521)
    ;*
    ;* vertical blank is in progress
    ;*
    DDERR_VERTICALBLANKINPROGRESS equ MAKE_DDHRESULT(537)
    ;*
    ;* Informs DirectDraw that the previous Blt which is transfering information
    ;* to or from this Surface is incomplete.
    ;*
    DDERR_WASSTILLDRAWING equ MAKE_DDHRESULT(540)
    ;*
    ;* The specified surface type requires specification of the COMPLEX flag
    ;*
    DDERR_DDSCAPSCOMPLEXREQUIRED equ MAKE_DDHRESULT(542)
    ;*
    ;* Rectangle provided was not horizontally aligned on reqd. boundary
    ;*
    DDERR_XALIGN equ MAKE_DDHRESULT(560)
    ;*
    ;* The GUID passed to DirectDrawCreate is not a valid DirectDraw driver
    ;* identifier.
    ;*
    DDERR_INVALIDDIRECTDRAWGUID equ MAKE_DDHRESULT(561)
    ;*
    ;* A DirectDraw object representing this driver has already been created
    ;* for this process.
    ;*
    DDERR_DIRECTDRAWALREADYCREATED equ MAKE_DDHRESULT(562)
    ;*
    ;* A hardware only DirectDraw object creation was attempted but the driver
    ;* did not support any hardware.
    ;*
    DDERR_NODIRECTDRAWHW equ MAKE_DDHRESULT(563)
    ;*
    ;* this process already has created a primary surface
    ;*
    DDERR_PRIMARYSURFACEALREADYEXISTS equ MAKE_DDHRESULT(564)
    ;*
    ;* software emulation not available.
    ;*
    DDERR_NOEMULATION equ MAKE_DDHRESULT(565)
    ;*
    ;* region passed to Clipper::GetClipList is too small.
    ;*
    DDERR_REGIONTOOSMALL equ MAKE_DDHRESULT(566)
    ;*
    ;* an attempt was made to set a clip list for a clipper objec that
    ;* is already monitoring an hwnd.
    ;*
    DDERR_CLIPPERISUSINGHWND equ MAKE_DDHRESULT(567)
    ;*
    ;* No clipper object attached to surface object
    ;*
    DDERR_NOCLIPPERATTACHED equ MAKE_DDHRESULT(568)
    ;*
    ;* Clipper notification requires an HWND or
    ;* no HWND has previously been set as the CooperativeLevel HWND.
    ;*
    DDERR_NOHWND equ MAKE_DDHRESULT(569)
    ;*
    ;* HWND used by DirectDraw CooperativeLevel has been subclassed,
    ;* this prevents DirectDraw from restoring state.
    ;*
    DDERR_HWNDSUBCLASSED equ MAKE_DDHRESULT(570)
    ;*
    ;* The CooperativeLevel HWND has already been set.
    ;* It can not be reset while the process has surfaces or palettes created.
    ;*
    DDERR_HWNDALREADYSET equ MAKE_DDHRESULT(571)
    ;*
    ;* No palette object attached to this surface.
    ;*
    DDERR_NOPALETTEATTACHED equ MAKE_DDHRESULT(572)
    ;*
    ;* No hardware support for 16 or 256 color palettes.
    ;*
    DDERR_NOPALETTEHW equ MAKE_DDHRESULT(573)
    ;*
    ;* If a clipper object is attached to the source surface passed into a
    ;* BltFast call.
    ;*
    DDERR_BLTFASTCANTCLIP equ MAKE_DDHRESULT(574)
    ;*
    ;* No blter.
    ;*
    DDERR_NOBLTHW equ MAKE_DDHRESULT(575)
    ;*
    ;* No DirectDraw ROP hardware.
    ;*
    DDERR_NODDROPSHW equ MAKE_DDHRESULT(576)
    ;*
    ;* returned when GetOverlayPosition is called on a hidden overlay
    ;*
    DDERR_OVERLAYNOTVISIBLE equ MAKE_DDHRESULT(577)
    ;*
    ;* returned when GetOverlayPosition is called on a overlay that UpdateOverlay
    ;* has never been called on to establish a destionation.
    ;*
    DDERR_NOOVERLAYDEST equ MAKE_DDHRESULT(578)
    ;*
    ;* returned when the position of the overlay on the destionation is no longer
    ;* legal for that destionation.
    ;*
    DDERR_INVALIDPOSITION equ MAKE_DDHRESULT(579)
    ;*
    ;* returned when an overlay member is called for a non-overlay surface
    ;*
    DDERR_NOTAOVERLAYSURFACE equ MAKE_DDHRESULT(580)
    ;*
    ;* An attempt was made to set the cooperative level when it was already
    ;* set to exclusive.
    ;*
    DDERR_EXCLUSIVEMODEALREADYSET equ MAKE_DDHRESULT(581)
    ;*
    ;* An attempt has been made to flip a surface that is not flippable.
    ;*
    DDERR_NOTFLIPPABLE equ MAKE_DDHRESULT(582)
    ;*
    ;* Can't duplicate primary & 3D surfaces, or surfaces that are implicitly
    ;* created.
    ;*
    DDERR_CANTDUPLICATE equ MAKE_DDHRESULT(583)
    ;*
    ;* Surface was not locked.  An attempt to unlock a surface that was not
    ;* locked at all, or by this process, has been attempted.
    ;*
    DDERR_NOTLOCKED equ MAKE_DDHRESULT(584)
    ;*
    ;* Windows can not create any more DCs, or a DC was requested for a paltte-indexed
    ;* surface when the surface had no palette AND the display mode was not palette-indexed
    ;* (in this case DirectDraw cannot select a proper palette into the DC)
    ;*
    DDERR_CANTCREATEDC equ MAKE_DDHRESULT(585)
    ;*
    ;* No DC was ever created for this surface.
    ;*
    DDERR_NODC equ MAKE_DDHRESULT(586)
    ;*
    ;* This surface can not be restored because it was created in a different
    ;* mode.
    ;*
    DDERR_WRONGMODE equ MAKE_DDHRESULT(587)
    ;*
    ;* This surface can not be restored because it is an implicitly created
    ;* surface.
    ;*
    DDERR_IMPLICITLYCREATED equ MAKE_DDHRESULT(588)
    ;*
    ;* The surface being used is not a palette-based surface
    ;*
    DDERR_NOTPALETTIZED equ MAKE_DDHRESULT(589)
    ;*
    ;* The display is currently in an unsupported mode
    ;*
    DDERR_UNSUPPORTEDMODE equ MAKE_DDHRESULT(590)
    ;*
    ;* Operation could not be carried out because there is no mip-map
    ;* texture mapping hardware present or available.
    ;*
    DDERR_NOMIPMAPHW equ MAKE_DDHRESULT(591)
    ;*
    ;* The requested action could not be performed because the surface was of
    ;* the wrong type.
    ;*
    DDERR_INVALIDSURFACETYPE equ MAKE_DDHRESULT(592)
    ;*
    ;* Device does not support optimized surfaces, therefore no video memory optimized surfaces
    ;*
    DDERR_NOOPTIMIZEHW equ MAKE_DDHRESULT(600)
    ;*
    ;* Surface is an optimized surface, but has not yet been allocated any memory
    ;*
    DDERR_NOTLOADED equ MAKE_DDHRESULT(601)
    ;*
    ;* Attempt was made to create or set a device window without first setting
    ;* the focus window
    ;*
    DDERR_NOFOCUSWINDOW equ MAKE_DDHRESULT(602)
    ;*
    ;* Attempt was made to set a palette on a mipmap sublevel
    ;*
    DDERR_NOTONMIPMAPSUBLEVEL equ MAKE_DDHRESULT(603)
    ;*
    ;* A DC has already been returned for this surface. Only one DC can be
    ;* retrieved per surface.
    ;*
    DDERR_DCALREADYCREATED equ MAKE_DDHRESULT(620)
    ;*
    ;* An attempt was made to allocate non-local video memory from a device
    ;* that does not support non-local video memory.
    ;*
    DDERR_NONONLOCALVIDMEM equ MAKE_DDHRESULT(630)
    ;*
    ;* The attempt to page lock a surface failed.
    ;*
    DDERR_CANTPAGELOCK equ MAKE_DDHRESULT(640)
    ;*
    ;* The attempt to page unlock a surface failed.
    ;*
    DDERR_CANTPAGEUNLOCK equ MAKE_DDHRESULT(660)
    ;*
    ;* An attempt was made to page unlock a surface with no outstanding page locks.
    ;*
    DDERR_NOTPAGELOCKED equ MAKE_DDHRESULT(680)
    ;*
    ;* There is more data available than the specified buffer size could hold
    ;*
    DDERR_MOREDATA equ MAKE_DDHRESULT(690)
    ;*
    ;* The data has expired and is therefore no longer valid.
    ;*
    DDERR_EXPIRED equ MAKE_DDHRESULT(691)
    ;*
    ;* The mode test has finished executing.
    ;*
    DDERR_TESTFINISHED equ MAKE_DDHRESULT(692)
    ;*
    ;* The mode test has switched to a new mode.
    ;*
    DDERR_NEWMODE equ MAKE_DDHRESULT(693)
    ;*
    ;* D3D has not yet been initialized.
    ;*
    DDERR_D3DNOTINITIALIZED equ MAKE_DDHRESULT(694)
    ;*
    ;* The video port is not active
    ;*
    DDERR_VIDEONOTACTIVE equ MAKE_DDHRESULT(695)
    ;*
    ;* The monitor does not have EDID data.
    ;*
    DDERR_NOMONITORINFORMATION equ MAKE_DDHRESULT(696)
    ;*
    ;* The driver does not enumerate display mode refresh rates.
    ;*
    DDERR_NODRIVERSUPPORT equ MAKE_DDHRESULT(697)
    ;*
    ;* Surfaces created by one direct draw device cannot be used directly by
    ;* another direct draw device.
    ;*
    DDERR_DEVICEDOESNTOWNSURFACE equ MAKE_DDHRESULT(699)
    ;*
    ;* An attempt was made to invoke an interface member of a DirectDraw object
    ;* created by CoCreateInstance() before it was initialized.
    ;*
    DDERR_NOTINITIALIZED equ <CO_E_NOTINITIALIZED>
    ;* Alpha bit depth constants *
    ifdef __cplusplus
      ;[...]
    endif
    if _MSC_VER ge 1200
    else
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
endif
;__DDRAW_INCLUDED__
