;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\ddraw.h', last modified: 19/04/2018 10:46
;Creation parameters: 

ifndef __DDRAW_INCLUDED__
  __DDRAW_INCLUDED__ equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if _MSC_VER ge 1200
    endif
    ifndef DIRECTDRAW_VERSION
      DIRECTDRAW_VERSION equ 0700h
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
    FOURCC_DXT1 equ <(MAKEFOURCC('D', 'X', 'T', '1'))>
    FOURCC_DXT2 equ <(MAKEFOURCC('D', 'X', 'T', '2'))>
    FOURCC_DXT3 equ <(MAKEFOURCC('D', 'X', 'T', '3'))>
    FOURCC_DXT4 equ <(MAKEFOURCC('D', 'X', 'T', '4'))>
    FOURCC_DXT5 equ <(MAKEFOURCC('D', 'X', 'T', '5'))>
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
    
    if (Defined(WIN32) or Defined(_WIN32)) and  not Defined(_NO_COM)
      TYPE_LPDDENUMCALLBACKA typedef proto WIN_STD_CALL_CONV :ptr GUID, :LPSTR, :LPSTR, :LPVOID
      LPDDENUMCALLBACKA typedef ptr TYPE_LPDDENUMCALLBACKA
      TYPE_LPDDENUMCALLBACKW typedef proto WIN_STD_CALL_CONV :ptr GUID, :LPWSTR, :LPWSTR, :LPVOID
      LPDDENUMCALLBACKW typedef ptr TYPE_LPDDENUMCALLBACKW
      DirectDrawEnumerateW proto WIN_STD_CALL_CONV :LPDDENUMCALLBACKW, :LPVOID
      DirectDrawEnumerateA proto WIN_STD_CALL_CONV :LPDDENUMCALLBACKA, :LPVOID
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
    DDENUM_ATTACHEDSECONDARYDEVICES equ 00000001h
    DDENUM_DETACHEDSECONDARYDEVICES equ 00000002h
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
    endif
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
    DDARGB struct
      blue BYTE ?
      green BYTE ?
      red BYTE ?
      alpha BYTE ?
    DDARGB ends

    _DDARGB typedef DDARGB
    LPDDARGB typedef ptr DDARGB
    DDRGBA struct
      red BYTE ?
      green BYTE ?
      blue BYTE ?
      alpha BYTE ?
    DDRGBA ends

    _DDRGBA typedef DDRGBA
    LPDDRGBA typedef ptr DDRGBA
    DDCOLORKEY struct
      dwColorSpaceLowValue DWORD ?
      dwColorSpaceHighValue DWORD ?
    DDCOLORKEY ends

    _DDCOLORKEY typedef DDCOLORKEY
    LPDDCOLORKEY typedef ptr DDCOLORKEY
    DDBLTFX struct
      dwSize DWORD ?
      dwDDFX DWORD ?
      dwROP DWORD ?
      dwDDROP DWORD ?
      dwRotationAngle DWORD ?
      dwZBufferOpCode DWORD ?
      dwZBufferLow DWORD ?
      dwZBufferHigh DWORD ?
      dwZBufferBaseDest DWORD ?
      dwZDestConstBitDepth DWORD ?
      union DUMMYUNIONNAMEN(1)
        dwZDestConst DWORD ?
        lpDDSZBufferDest LPDIRECTDRAWSURFACE ?
      ends
      dwZSrcConstBitDepth DWORD ?
      union DUMMYUNIONNAMEN(2)
        dwZSrcConst DWORD ?
        lpDDSZBufferSrc LPDIRECTDRAWSURFACE ?
      ends
      dwAlphaEdgeBlendBitDepth DWORD ?
      dwAlphaEdgeBlend DWORD ?
      dwReserved DWORD ?
      dwAlphaDestConstBitDepth DWORD ?
      union DUMMYUNIONNAMEN(3)
        dwAlphaDestConst DWORD ?
        lpDDSAlphaDest LPDIRECTDRAWSURFACE ?
      ends
      dwAlphaSrcConstBitDepth DWORD ?
      union DUMMYUNIONNAMEN(4)
        dwAlphaSrcConst DWORD ?
        lpDDSAlphaSrc LPDIRECTDRAWSURFACE ?
      ends
      union DUMMYUNIONNAMEN(5)
        dwFillColor DWORD ?
        dwFillDepth DWORD ?
        dwFillPixel DWORD ?
        lpDDSPattern LPDIRECTDRAWSURFACE ?
      ends
      ddckDestColorkey DDCOLORKEY <>
      ddckSrcColorkey DDCOLORKEY <>
    DDBLTFX ends

    _DDBLTFX typedef DDBLTFX
    LPDDBLTFX typedef ptr DDBLTFX
    DDSCAPS struct
      dwCaps DWORD ?
    DDSCAPS ends

    _DDSCAPS typedef DDSCAPS
    LPDDSCAPS typedef ptr DDSCAPS
    DDOSCAPS struct
      dwCaps DWORD ?
    DDOSCAPS ends

    _DDOSCAPS typedef DDOSCAPS
    LPDDOSCAPS typedef ptr DDOSCAPS
    DDSCAPSEX struct
      dwCaps2 DWORD ?
      dwCaps3 DWORD ?
      union DUMMYUNIONNAMEN(1)
        dwCaps4 DWORD ?
        dwVolumeDepth DWORD ?
      ends
    DDSCAPSEX ends

    _DDSCAPSEX typedef DDSCAPSEX
    LPDDSCAPSEX typedef ptr DDSCAPSEX
    
    DDSCAPS2 struct
      dwCaps DWORD ?
      dwCaps2 DWORD ?
      dwCaps3 DWORD ?
      union DUMMYUNIONNAMEN(1)
        dwCaps4 DWORD ?
        dwVolumeDepth DWORD ?
      ends
    DDSCAPS2 ends

    _DDSCAPS2 typedef DDSCAPS2
    LPDDSCAPS2 typedef ptr DDSCAPS2
    DD_ROP_SPACE equ (256 / 32)
    DDCAPS_DX1 struct
      dwSize DWORD ?
      dwCaps DWORD ?
      dwCaps2 DWORD ?
      dwCKeyCaps DWORD ?
      dwFXCaps DWORD ?
      dwFXAlphaCaps DWORD ?
      dwPalCaps DWORD ?
      dwSVCaps DWORD ?
      dwAlphaBltConstBitDepths DWORD ?
      dwAlphaBltPixelBitDepths DWORD ?
      dwAlphaBltSurfaceBitDepths DWORD ?
      dwAlphaOverlayConstBitDepths DWORD ?
      dwAlphaOverlayPixelBitDepths DWORD ?
      dwAlphaOverlaySurfaceBitDepths DWORD ?
      dwZBufferBitDepths DWORD ?
      dwVidMemTotal DWORD ?
      dwVidMemFree DWORD ?
      dwMaxVisibleOverlays DWORD ?
      dwCurrVisibleOverlays DWORD ?
      dwNumFourCCCodes DWORD ?
      dwAlignBoundarySrc DWORD ?
      dwAlignSizeSrc DWORD ?
      dwAlignBoundaryDest DWORD ?
      dwAlignSizeDest DWORD ?
      dwAlignStrideAlign DWORD ?
      dwRops DWORD DD_ROP_SPACE dup (?)
      ddsCaps DDSCAPS <>
      dwMinOverlayStretch DWORD ?
      dwMaxOverlayStretch DWORD ?
      dwMinLiveVideoStretch DWORD ?
      dwMaxLiveVideoStretch DWORD ?
      dwMinHwCodecStretch DWORD ?
      dwMaxHwCodecStretch DWORD ?
      dwReserved1 DWORD ?
      dwReserved2 DWORD ?
      dwReserved3 DWORD ?
    DDCAPS_DX1 ends

    _DDCAPS_DX1 typedef DDCAPS_DX1
    LPDDCAPS_DX1 typedef ptr DDCAPS_DX1
    DDCAPS_DX3 struct
      dwSize DWORD ?
      dwCaps DWORD ?
      dwCaps2 DWORD ?
      dwCKeyCaps DWORD ?
      dwFXCaps DWORD ?
      dwFXAlphaCaps DWORD ?
      dwPalCaps DWORD ?
      dwSVCaps DWORD ?
      dwAlphaBltConstBitDepths DWORD ?
      dwAlphaBltPixelBitDepths DWORD ?
      dwAlphaBltSurfaceBitDepths DWORD ?
      dwAlphaOverlayConstBitDepths DWORD ?
      dwAlphaOverlayPixelBitDepths DWORD ?
      dwAlphaOverlaySurfaceBitDepths DWORD ?
      dwZBufferBitDepths DWORD ?
      dwVidMemTotal DWORD ?
      dwVidMemFree DWORD ?
      dwMaxVisibleOverlays DWORD ?
      dwCurrVisibleOverlays DWORD ?
      dwNumFourCCCodes DWORD ?
      dwAlignBoundarySrc DWORD ?
      dwAlignSizeSrc DWORD ?
      dwAlignBoundaryDest DWORD ?
      dwAlignSizeDest DWORD ?
      dwAlignStrideAlign DWORD ?
      dwRops DWORD DD_ROP_SPACE dup (?)
      ddsCaps DDSCAPS <>
      dwMinOverlayStretch DWORD ?
      dwMaxOverlayStretch DWORD ?
      dwMinLiveVideoStretch DWORD ?
      dwMaxLiveVideoStretch DWORD ?
      dwMinHwCodecStretch DWORD ?
      dwMaxHwCodecStretch DWORD ?
      dwReserved1 DWORD ?
      dwReserved2 DWORD ?
      dwReserved3 DWORD ?
      dwSVBCaps DWORD ?
      dwSVBCKeyCaps DWORD ?
      dwSVBFXCaps DWORD ?
      dwSVBRops DWORD DD_ROP_SPACE dup (?)
      dwVSBCaps DWORD ?
      dwVSBCKeyCaps DWORD ?
      dwVSBFXCaps DWORD ?
      dwVSBRops DWORD DD_ROP_SPACE dup (?)
      dwSSBCaps DWORD ?
      dwSSBCKeyCaps DWORD ?
      dwSSBFXCaps DWORD ?
      dwSSBRops DWORD DD_ROP_SPACE dup (?)
      dwReserved4 DWORD ?
      dwReserved5 DWORD ?
      dwReserved6 DWORD ?
    DDCAPS_DX3 ends

    _DDCAPS_DX3 typedef DDCAPS_DX3
    LPDDCAPS_DX3 typedef ptr DDCAPS_DX3
    DDCAPS_DX5 struct
      dwSize DWORD ?
      dwCaps DWORD ?
      dwCaps2 DWORD ?
      dwCKeyCaps DWORD ?
      dwFXCaps DWORD ?
      dwFXAlphaCaps DWORD ?
      dwPalCaps DWORD ?
      dwSVCaps DWORD ?
      dwAlphaBltConstBitDepths DWORD ?
      dwAlphaBltPixelBitDepths DWORD ?
      dwAlphaBltSurfaceBitDepths DWORD ?
      dwAlphaOverlayConstBitDepths DWORD ?
      dwAlphaOverlayPixelBitDepths DWORD ?
      dwAlphaOverlaySurfaceBitDepths DWORD ?
      dwZBufferBitDepths DWORD ?
      dwVidMemTotal DWORD ?
      dwVidMemFree DWORD ?
      dwMaxVisibleOverlays DWORD ?
      dwCurrVisibleOverlays DWORD ?
      dwNumFourCCCodes DWORD ?
      dwAlignBoundarySrc DWORD ?
      dwAlignSizeSrc DWORD ?
      dwAlignBoundaryDest DWORD ?
      dwAlignSizeDest DWORD ?
      dwAlignStrideAlign DWORD ?
      dwRops DWORD DD_ROP_SPACE dup (?)
      ddsCaps DDSCAPS <>
      dwMinOverlayStretch DWORD ?
      dwMaxOverlayStretch DWORD ?
      dwMinLiveVideoStretch DWORD ?
      dwMaxLiveVideoStretch DWORD ?
      dwMinHwCodecStretch DWORD ?
      dwMaxHwCodecStretch DWORD ?
      dwReserved1 DWORD ?
      dwReserved2 DWORD ?
      dwReserved3 DWORD ?
      dwSVBCaps DWORD ?
      dwSVBCKeyCaps DWORD ?
      dwSVBFXCaps DWORD ?
      dwSVBRops DWORD DD_ROP_SPACE dup (?)
      dwVSBCaps DWORD ?
      dwVSBCKeyCaps DWORD ?
      dwVSBFXCaps DWORD ?
      dwVSBRops DWORD DD_ROP_SPACE dup (?)
      dwSSBCaps DWORD ?
      dwSSBCKeyCaps DWORD ?
      dwSSBFXCaps DWORD ?
      dwSSBRops DWORD DD_ROP_SPACE dup (?)
      dwMaxVideoPorts DWORD ?
      dwCurrVideoPorts DWORD ?
      dwSVBCaps2 DWORD ?
      dwNLVBCaps DWORD ?
      dwNLVBCaps2 DWORD ?
      dwNLVBCKeyCaps DWORD ?
      dwNLVBFXCaps DWORD ?
      dwNLVBRops DWORD DD_ROP_SPACE dup (?)
    DDCAPS_DX5 ends

    _DDCAPS_DX5 typedef DDCAPS_DX5
    LPDDCAPS_DX5 typedef ptr DDCAPS_DX5
    DDCAPS_DX6 struct
      dwSize DWORD ?
      dwCaps DWORD ?
      dwCaps2 DWORD ?
      dwCKeyCaps DWORD ?
      dwFXCaps DWORD ?
      dwFXAlphaCaps DWORD ?
      dwPalCaps DWORD ?
      dwSVCaps DWORD ?
      dwAlphaBltConstBitDepths DWORD ?
      dwAlphaBltPixelBitDepths DWORD ?
      dwAlphaBltSurfaceBitDepths DWORD ?
      dwAlphaOverlayConstBitDepths DWORD ?
      dwAlphaOverlayPixelBitDepths DWORD ?
      dwAlphaOverlaySurfaceBitDepths DWORD ?
      dwZBufferBitDepths DWORD ?
      dwVidMemTotal DWORD ?
      dwVidMemFree DWORD ?
      dwMaxVisibleOverlays DWORD ?
      dwCurrVisibleOverlays DWORD ?
      dwNumFourCCCodes DWORD ?
      dwAlignBoundarySrc DWORD ?
      dwAlignSizeSrc DWORD ?
      dwAlignBoundaryDest DWORD ?
      dwAlignSizeDest DWORD ?
      dwAlignStrideAlign DWORD ?
      dwRops DWORD DD_ROP_SPACE dup (?)
      ddsOldCaps DDSCAPS <>
      dwMinOverlayStretch DWORD ?
      dwMaxOverlayStretch DWORD ?
      dwMinLiveVideoStretch DWORD ?
      dwMaxLiveVideoStretch DWORD ?
      dwMinHwCodecStretch DWORD ?
      dwMaxHwCodecStretch DWORD ?
      dwReserved1 DWORD ?
      dwReserved2 DWORD ?
      dwReserved3 DWORD ?
      dwSVBCaps DWORD ?
      dwSVBCKeyCaps DWORD ?
      dwSVBFXCaps DWORD ?
      dwSVBRops DWORD DD_ROP_SPACE dup (?)
      dwVSBCaps DWORD ?
      dwVSBCKeyCaps DWORD ?
      dwVSBFXCaps DWORD ?
      dwVSBRops DWORD DD_ROP_SPACE dup (?)
      dwSSBCaps DWORD ?
      dwSSBCKeyCaps DWORD ?
      dwSSBFXCaps DWORD ?
      dwSSBRops DWORD DD_ROP_SPACE dup (?)
      dwMaxVideoPorts DWORD ?
      dwCurrVideoPorts DWORD ?
      dwSVBCaps2 DWORD ?
      dwNLVBCaps DWORD ?
      dwNLVBCaps2 DWORD ?
      dwNLVBCKeyCaps DWORD ?
      dwNLVBFXCaps DWORD ?
      dwNLVBRops DWORD DD_ROP_SPACE dup (?)
      ddsCaps DDSCAPS2 <>
    DDCAPS_DX6 ends

    _DDCAPS_DX6 typedef DDCAPS_DX6
    LPDDCAPS_DX6 typedef ptr DDCAPS_DX6
    DDCAPS_DX7 struct
      dwSize DWORD ?
      dwCaps DWORD ?
      dwCaps2 DWORD ?
      dwCKeyCaps DWORD ?
      dwFXCaps DWORD ?
      dwFXAlphaCaps DWORD ?
      dwPalCaps DWORD ?
      dwSVCaps DWORD ?
      dwAlphaBltConstBitDepths DWORD ?
      dwAlphaBltPixelBitDepths DWORD ?
      dwAlphaBltSurfaceBitDepths DWORD ?
      dwAlphaOverlayConstBitDepths DWORD ?
      dwAlphaOverlayPixelBitDepths DWORD ?
      dwAlphaOverlaySurfaceBitDepths DWORD ?
      dwZBufferBitDepths DWORD ?
      dwVidMemTotal DWORD ?
      dwVidMemFree DWORD ?
      dwMaxVisibleOverlays DWORD ?
      dwCurrVisibleOverlays DWORD ?
      dwNumFourCCCodes DWORD ?
      dwAlignBoundarySrc DWORD ?
      dwAlignSizeSrc DWORD ?
      dwAlignBoundaryDest DWORD ?
      dwAlignSizeDest DWORD ?
      dwAlignStrideAlign DWORD ?
      dwRops DWORD DD_ROP_SPACE dup (?)
      ddsOldCaps DDSCAPS <>
      dwMinOverlayStretch DWORD ?
      dwMaxOverlayStretch DWORD ?
      dwMinLiveVideoStretch DWORD ?
      dwMaxLiveVideoStretch DWORD ?
      dwMinHwCodecStretch DWORD ?
      dwMaxHwCodecStretch DWORD ?
      dwReserved1 DWORD ?
      dwReserved2 DWORD ?
      dwReserved3 DWORD ?
      dwSVBCaps DWORD ?
      dwSVBCKeyCaps DWORD ?
      dwSVBFXCaps DWORD ?
      dwSVBRops DWORD DD_ROP_SPACE dup (?)
      dwVSBCaps DWORD ?
      dwVSBCKeyCaps DWORD ?
      dwVSBFXCaps DWORD ?
      dwVSBRops DWORD DD_ROP_SPACE dup (?)
      dwSSBCaps DWORD ?
      dwSSBCKeyCaps DWORD ?
      dwSSBFXCaps DWORD ?
      dwSSBRops DWORD DD_ROP_SPACE dup (?)
      dwMaxVideoPorts DWORD ?
      dwCurrVideoPorts DWORD ?
      dwSVBCaps2 DWORD ?
      dwNLVBCaps DWORD ?
      dwNLVBCaps2 DWORD ?
      dwNLVBCKeyCaps DWORD ?
      dwNLVBFXCaps DWORD ?
      dwNLVBRops DWORD DD_ROP_SPACE dup (?)
      ddsCaps DDSCAPS2 <>
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
    ifndef _DDPIXELFORMAT_DEFINED
      _DDPIXELFORMAT_DEFINED equ <>
      DDPIXELFORMAT struct
        dwSize DWORD ?
        dwFlags DWORD ?
        dwFourCC DWORD ?
        union DUMMYUNIONNAMEN(1)
          dwRGBBitCount DWORD ?
          dwYUVBitCount DWORD ?
          dwZBufferBitDepth DWORD ?
          dwAlphaBitDepth DWORD ?
          dwLuminanceBitCount DWORD ?
          dwBumpBitCount DWORD ?
          dwPrivateFormatBitCount DWORD ?
        ends
        union DUMMYUNIONNAMEN(2)
          dwRBitMask DWORD ?
          dwYBitMask DWORD ?
          dwStencilBitDepth DWORD ?
          dwLuminanceBitMask DWORD ?
          dwBumpDuBitMask DWORD ?
          dwOperations DWORD ?
        ends
        union DUMMYUNIONNAMEN(3)
          dwGBitMask DWORD ?
          dwUBitMask DWORD ?
          dwZBitMask DWORD ?
          dwBumpDvBitMask DWORD ?
          struct MultiSampleCaps
            wFlipMSTypes WORD ?
            wBltMSTypes WORD ?
          ends
        ends
        union DUMMYUNIONNAMEN(4)
          dwBBitMask DWORD ?
          dwVBitMask DWORD ?
          dwStencilBitMask DWORD ?
          dwBumpLuminanceBitMask DWORD ?
        ends
        union DUMMYUNIONNAMEN(5)
          dwRGBAlphaBitMask DWORD ?
          dwYUVAlphaBitMask DWORD ?
          dwLuminanceAlphaBitMask DWORD ?
          dwRGBZBitMask DWORD ?
          dwYUVZBitMask DWORD ?
        ends
      DDPIXELFORMAT ends

      _DDPIXELFORMAT typedef DDPIXELFORMAT
    endif
    LPDDPIXELFORMAT typedef ptr DDPIXELFORMAT
    DDOVERLAYFX struct
      dwSize DWORD ?
      dwAlphaEdgeBlendBitDepth DWORD ?
      dwAlphaEdgeBlend DWORD ?
      dwReserved DWORD ?
      dwAlphaDestConstBitDepth DWORD ?
      union DUMMYUNIONNAMEN(1)
        dwAlphaDestConst DWORD ?
        lpDDSAlphaDest LPDIRECTDRAWSURFACE ?
      ends
      dwAlphaSrcConstBitDepth DWORD ?
      union DUMMYUNIONNAMEN(2)
        dwAlphaSrcConst DWORD ?
        lpDDSAlphaSrc LPDIRECTDRAWSURFACE ?
      ends
      dckDestColorkey DDCOLORKEY <>
      dckSrcColorkey DDCOLORKEY <>
      dwDDFX DWORD ?
      dwFlags DWORD ?
    DDOVERLAYFX ends

    _DDOVERLAYFX typedef DDOVERLAYFX
    LPDDOVERLAYFX typedef ptr DDOVERLAYFX
    DDBLTBATCH struct
      lprDest LPRECT ?
      lpDDSSrc LPDIRECTDRAWSURFACE ?
      lprSrc LPRECT ?
      dwFlags DWORD ?
      lpDDBltFx LPDDBLTFX ?
    DDBLTBATCH ends

    _DDBLTBATCH typedef DDBLTBATCH
    LPDDBLTBATCH typedef ptr DDBLTBATCH
    DDGAMMARAMP struct
      red WORD 256 dup (?)
      green WORD 256 dup (?)
      blue WORD 256 dup (?)
    DDGAMMARAMP ends

    _DDGAMMARAMP typedef DDGAMMARAMP
    LPDDGAMMARAMP typedef ptr DDGAMMARAMP
    MAX_DDDEVICEID_STRING equ 512
    DDDEVICEIDENTIFIER struct
      szDriver SBYTE MAX_DDDEVICEID_STRING dup (?)
      szDescription SBYTE MAX_DDDEVICEID_STRING dup (?)
      ifdef _WIN32
        liDriverVersion LARGE_INTEGER <>
      else
        ;[...]
      endif
      dwVendorId DWORD ?
      dwDeviceId DWORD ?
      dwSubSysId DWORD ?
      dwRevision DWORD ?
      guidDeviceIdentifier GUID <>
    DDDEVICEIDENTIFIER ends

    tagDDDEVICEIDENTIFIER typedef DDDEVICEIDENTIFIER
    LPDDDEVICEIDENTIFIER typedef ptr DDDEVICEIDENTIFIER
    
    DDDEVICEIDENTIFIER2 struct
      szDriver SBYTE MAX_DDDEVICEID_STRING dup (?)
      szDescription SBYTE MAX_DDDEVICEID_STRING dup (?)
      ifdef _WIN32
        liDriverVersion LARGE_INTEGER <>
      else
        ;[...]
      endif
      dwVendorId DWORD ?
      dwDeviceId DWORD ?
      dwSubSysId DWORD ?
      dwRevision DWORD ?
      guidDeviceIdentifier GUID <>
      dwWHQLLevel DWORD ?
    DDDEVICEIDENTIFIER2 ends

    tagDDDEVICEIDENTIFIER2 typedef DDDEVICEIDENTIFIER2
    LPDDDEVICEIDENTIFIER2 typedef ptr DDDEVICEIDENTIFIER2
    
    DDGDI_GETHOSTIDENTIFIER equ 00000001h
    GET_WHQL_YEAR macro dwWHQLLevel
      exitm <((dwWHQLLevel) / 10000h)>
    endm
    GET_WHQL_MONTH macro dwWHQLLevel
      exitm <(((dwWHQLLevel) / 100h) and 00ffh)>
    endm
    GET_WHQL_DAY macro dwWHQLLevel
      exitm <((dwWHQLLevel) and 0ffh)>
    endm
    TYPE_LPCLIPPERCALLBACK typedef proto WIN_STD_CALL_CONV :LPDIRECTDRAWCLIPPER, :HWND, :DWORD, :LPVOID
    LPCLIPPERCALLBACK typedef ptr TYPE_LPCLIPPERCALLBACK
    ifdef STREAMING
      TYPE_LPSURFACESTREAMINGCALLBACK typedef proto WIN_STD_CALL_CONV :DWORD
      LPSURFACESTREAMINGCALLBACK typedef ptr TYPE_LPSURFACESTREAMINGCALLBACK
    endif
    if Defined(_WIN32) and  not Defined(_NO_COM)
      INTERFACE equ <IDirectDraw>
      DECLARE_INTERFACE_ IDirectDraw, IUnknown
        STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD Compact_, :THIS_
        STD_METHOD CreateClipper, :THIS_, :ptr LPDIRECTDRAWCLIPPER, :ptr IUnknown
        STD_METHOD CreatePalette, :THIS_, :LPPALETTEENTRY, :ptr LPDIRECTDRAWPALETTE, :ptr IUnknown
        STD_METHOD CreateSurface, :THIS_, :ptr LPDIRECTDRAWSURFACE, :ptr IUnknown
        STD_METHOD DuplicateSurface, :THIS_, :ptr LPDIRECTDRAWSURFACE
        STD_METHOD EnumDisplayModes, :THIS_, :LPDDSURFACEDESC, :LPVOID, :LPDDENUMMODESCALLBACK
        STD_METHOD EnumSurfaces, :THIS_, :LPDDSURFACEDESC, :LPVOID, :LPDDENUMSURFACESCALLBACK
        STD_METHOD FlipToGDISurface, :THIS_
        STD_METHOD GetCaps, :THIS_, :LPDDCAPS
        STD_METHOD GetDisplayMode, :THIS_
        STD_METHOD GetFourCCCodes, :THIS_, :LPDWORD
        STD_METHOD GetGDISurface, :ptr THIS_
        STD_METHOD GetMonitorFrequency, :THIS_
        STD_METHOD GetScanLine, :THIS_
        STD_METHOD GetVerticalBlankStatus, :THIS_
        STD_METHOD Initialize, :ptr THIS_
        STD_METHOD RestoreDisplayMode, :THIS_
        STD_METHOD SetCooperativeLevel, :THIS_, :DWORD
        STD_METHOD SetDisplayMode, :THIS_, :DWORD, :DWORD
        STD_METHOD WaitForVerticalBlank, :THIS_, :HANDLE
      END_DECLARE_INTERFACE_
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
      DECLARE_INTERFACE_ IDirectDraw2, IUnknown
        STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD Compact_, :THIS_
        STD_METHOD CreateClipper, :THIS_, :ptr LPDIRECTDRAWCLIPPER, :ptr IUnknown
        STD_METHOD CreatePalette, :THIS_, :LPPALETTEENTRY, :ptr LPDIRECTDRAWPALETTE, :ptr IUnknown
        STD_METHOD CreateSurface, :THIS_, :ptr LPDIRECTDRAWSURFACE, :ptr IUnknown
        STD_METHOD DuplicateSurface, :THIS_, :ptr LPDIRECTDRAWSURFACE
        STD_METHOD EnumDisplayModes, :THIS_, :LPDDSURFACEDESC, :LPVOID, :LPDDENUMMODESCALLBACK
        STD_METHOD EnumSurfaces, :THIS_, :LPDDSURFACEDESC, :LPVOID, :LPDDENUMSURFACESCALLBACK
        STD_METHOD FlipToGDISurface, :THIS_
        STD_METHOD GetCaps, :THIS_, :LPDDCAPS
        STD_METHOD GetDisplayMode, :THIS_
        STD_METHOD GetFourCCCodes, :THIS_, :LPDWORD
        STD_METHOD GetGDISurface, :ptr THIS_
        STD_METHOD GetMonitorFrequency, :THIS_
        STD_METHOD GetScanLine, :THIS_
        STD_METHOD GetVerticalBlankStatus, :THIS_
        STD_METHOD Initialize, :ptr THIS_
        STD_METHOD RestoreDisplayMode, :THIS_
        STD_METHOD SetCooperativeLevel, :THIS_, :DWORD
        STD_METHOD SetDisplayMode, :THIS_, :DWORD, :DWORD, :DWORD, :DWORD
        STD_METHOD WaitForVerticalBlank, :THIS_, :HANDLE
        STD_METHOD GetAvailableVidMem, :THIS_, :LPDWORD, :LPDWORD
      END_DECLARE_INTERFACE_
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
      DECLARE_INTERFACE_ IDirectDraw4, IUnknown
        STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD Compact_, :THIS_
        STD_METHOD CreateClipper, :THIS_, :ptr LPDIRECTDRAWCLIPPER, :ptr IUnknown
        STD_METHOD CreatePalette, :THIS_, :LPPALETTEENTRY, :ptr LPDIRECTDRAWPALETTE, :ptr IUnknown
        STD_METHOD CreateSurface, :THIS_, :ptr LPDIRECTDRAWSURFACE4, :ptr IUnknown
        STD_METHOD DuplicateSurface, :THIS_, :ptr LPDIRECTDRAWSURFACE4
        STD_METHOD EnumDisplayModes, :THIS_, :LPDDSURFACEDESC2, :LPVOID, :LPDDENUMMODESCALLBACK2
        STD_METHOD EnumSurfaces, :THIS_, :LPDDSURFACEDESC2, :LPVOID, :LPDDENUMSURFACESCALLBACK2
        STD_METHOD FlipToGDISurface, :THIS_
        STD_METHOD GetCaps, :THIS_, :LPDDCAPS
        STD_METHOD GetDisplayMode, :THIS_
        STD_METHOD GetFourCCCodes, :THIS_, :LPDWORD
        STD_METHOD GetGDISurface, :ptr THIS_
        STD_METHOD GetMonitorFrequency, :THIS_
        STD_METHOD GetScanLine, :THIS_
        STD_METHOD GetVerticalBlankStatus, :THIS_
        STD_METHOD Initialize, :ptr THIS_
        STD_METHOD RestoreDisplayMode, :THIS_
        STD_METHOD SetCooperativeLevel, :THIS_, :DWORD
        STD_METHOD SetDisplayMode, :THIS_, :DWORD, :DWORD, :DWORD, :DWORD
        STD_METHOD WaitForVerticalBlank, :THIS_, :HANDLE
        STD_METHOD GetAvailableVidMem, :THIS_, :LPDWORD, :LPDWORD
        STD_METHOD GetSurfaceFromDC, :THIS_, :ptr LPDIRECTDRAWSURFACE4
        STD_METHOD RestoreAllSurfaces, :THIS_
        STD_METHOD TestCooperativeLevel, :THIS_
        STD_METHOD GetDeviceIdentifier, :THIS_, :DWORD
      END_DECLARE_INTERFACE_
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
      DECLARE_INTERFACE_ IDirectDraw7, IUnknown
        STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD Compact_, :THIS_
        STD_METHOD CreateClipper, :THIS_, :ptr LPDIRECTDRAWCLIPPER, :ptr IUnknown
        STD_METHOD CreatePalette, :THIS_, :LPPALETTEENTRY, :ptr LPDIRECTDRAWPALETTE, :ptr IUnknown
        STD_METHOD CreateSurface, :THIS_, :ptr LPDIRECTDRAWSURFACE7, :ptr IUnknown
        STD_METHOD DuplicateSurface, :THIS_, :ptr LPDIRECTDRAWSURFACE7
        STD_METHOD EnumDisplayModes, :THIS_, :LPDDSURFACEDESC2, :LPVOID, :LPDDENUMMODESCALLBACK2
        STD_METHOD EnumSurfaces, :THIS_, :LPDDSURFACEDESC2, :LPVOID, :LPDDENUMSURFACESCALLBACK7
        STD_METHOD FlipToGDISurface, :THIS_
        STD_METHOD GetCaps, :THIS_, :LPDDCAPS
        STD_METHOD GetDisplayMode, :THIS_
        STD_METHOD GetFourCCCodes, :THIS_, :LPDWORD
        STD_METHOD GetGDISurface, :ptr THIS_
        STD_METHOD GetMonitorFrequency, :THIS_
        STD_METHOD GetScanLine, :THIS_
        STD_METHOD GetVerticalBlankStatus, :THIS_
        STD_METHOD Initialize, :ptr THIS_
        STD_METHOD RestoreDisplayMode, :THIS_
        STD_METHOD SetCooperativeLevel, :THIS_, :DWORD
        STD_METHOD SetDisplayMode, :THIS_, :DWORD, :DWORD, :DWORD, :DWORD
        STD_METHOD WaitForVerticalBlank, :THIS_, :HANDLE
        STD_METHOD GetAvailableVidMem, :THIS_, :LPDWORD, :LPDWORD
        STD_METHOD GetSurfaceFromDC, :THIS_, :ptr LPDIRECTDRAWSURFACE7
        STD_METHOD RestoreAllSurfaces, :THIS_
        STD_METHOD TestCooperativeLevel, :THIS_
        STD_METHOD GetDeviceIdentifier, :THIS_, :DWORD
        STD_METHOD StartModeTest, :THIS_, :DWORD, :DWORD
        STD_METHOD EvaluateMode, :THIS_, :ptr DWORD
      END_DECLARE_INTERFACE_
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
    if Defined(_WIN32) and  not Defined(_NO_COM)
      INTERFACE equ <IDirectDrawPalette>
      DECLARE_INTERFACE_ IDirectDrawPalette, IUnknown
        STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD GetCaps, :THIS_
        STD_METHOD GetEntries, :THIS_, :DWORD, :DWORD, :LPPALETTEENTRY
        STD_METHOD Initialize, :THIS_, :DWORD, :LPPALETTEENTRY
        STD_METHOD SetEntries, :THIS_, :DWORD, :DWORD, :LPPALETTEENTRY
      END_DECLARE_INTERFACE_
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
    if Defined(_WIN32) and  not Defined(_NO_COM)
      INTERFACE equ <IDirectDrawClipper>
      DECLARE_INTERFACE_ IDirectDrawClipper, IUnknown
        STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD GetClipList, :THIS_, :LPRGNDATA, :LPDWORD
        STD_METHOD GetHWnd, :ptr THIS_
        STD_METHOD Initialize, :THIS_, :DWORD
        STD_METHOD IsClipListChanged, :ptr THIS_
        STD_METHOD SetClipList, :THIS_, :DWORD
        STD_METHOD SetHWnd, :THIS_, :HWND
      END_DECLARE_INTERFACE_
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
    if Defined(_WIN32) and  not Defined(_NO_COM)
      INTERFACE equ <IDirectDrawSurface>
      DECLARE_INTERFACE_ IDirectDrawSurface, IUnknown
        STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD AddAttachedSurface, :THIS_
        STD_METHOD AddOverlayDirtyRect, :THIS_
        STD_METHOD Blt, :THIS_, :LPDIRECTDRAWSURFACE, :LPRECT, :DWORD, :LPDDBLTFX
        STD_METHOD BltBatch, :THIS_, :DWORD, :DWORD
        STD_METHOD BltFast, :THIS_, :DWORD, :LPDIRECTDRAWSURFACE, :LPRECT, :DWORD
        STD_METHOD DeleteAttachedSurface, :THIS_, :LPDIRECTDRAWSURFACE
        STD_METHOD EnumAttachedSurfaces, :THIS_, :LPDDENUMSURFACESCALLBACK
        STD_METHOD EnumOverlayZOrders, :THIS_, :LPVOID, :LPDDENUMSURFACESCALLBACK
        STD_METHOD Flip, :THIS_, :DWORD
        STD_METHOD GetAttachedSurface, :THIS_, :ptr LPDIRECTDRAWSURFACE
        STD_METHOD GetBltStatus, :THIS_
        STD_METHOD GetCaps, :THIS_
        STD_METHOD GetClipper, :ptr THIS_
        STD_METHOD GetColorKey, :THIS_, :LPDDCOLORKEY
        STD_METHOD GetDC, :ptr THIS_
        STD_METHOD GetFlipStatus, :THIS_
        STD_METHOD GetOverlayPosition, :THIS_, :LPLONG
        STD_METHOD GetPalette, :ptr THIS_
        STD_METHOD GetPixelFormat, :THIS_
        STD_METHOD GetSurfaceDesc, :THIS_
        STD_METHOD Initialize, :THIS_, :LPDDSURFACEDESC
        STD_METHOD IsLost, :THIS_
        STD_METHOD Lock_, :THIS_, :LPDDSURFACEDESC, :DWORD, :HANDLE
        STD_METHOD ReleaseDC, :THIS_
        STD_METHOD Restore, :THIS_
        STD_METHOD SetClipper, :THIS_
        STD_METHOD SetColorKey, :THIS_, :LPDDCOLORKEY
        STD_METHOD SetOverlayPosition, :THIS_, :LONG
        STD_METHOD SetPalette, :THIS_
        STD_METHOD Unlock, :THIS_
        STD_METHOD UpdateOverlay, :THIS_, :LPDIRECTDRAWSURFACE, :LPRECT, :DWORD, :LPDDOVERLAYFX
        STD_METHOD UpdateOverlayDisplay, :THIS_
        STD_METHOD UpdateOverlayZOrder, :THIS_, :LPDIRECTDRAWSURFACE
      END_DECLARE_INTERFACE_
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
      INTERFACE equ <IDirectDrawSurface2>
      DECLARE_INTERFACE_ IDirectDrawSurface2, IUnknown
        STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD AddAttachedSurface, :THIS_
        STD_METHOD AddOverlayDirtyRect, :THIS_
        STD_METHOD Blt, :THIS_, :LPDIRECTDRAWSURFACE2, :LPRECT, :DWORD, :LPDDBLTFX
        STD_METHOD BltBatch, :THIS_, :DWORD, :DWORD
        STD_METHOD BltFast, :THIS_, :DWORD, :LPDIRECTDRAWSURFACE2, :LPRECT, :DWORD
        STD_METHOD DeleteAttachedSurface, :THIS_, :LPDIRECTDRAWSURFACE2
        STD_METHOD EnumAttachedSurfaces, :THIS_, :LPDDENUMSURFACESCALLBACK
        STD_METHOD EnumOverlayZOrders, :THIS_, :LPVOID, :LPDDENUMSURFACESCALLBACK
        STD_METHOD Flip, :THIS_, :DWORD
        STD_METHOD GetAttachedSurface, :THIS_, :ptr LPDIRECTDRAWSURFACE2
        STD_METHOD GetBltStatus, :THIS_
        STD_METHOD GetCaps, :THIS_
        STD_METHOD GetClipper, :ptr THIS_
        STD_METHOD GetColorKey, :THIS_, :LPDDCOLORKEY
        STD_METHOD GetDC, :ptr THIS_
        STD_METHOD GetFlipStatus, :THIS_
        STD_METHOD GetOverlayPosition, :THIS_, :LPLONG
        STD_METHOD GetPalette, :ptr THIS_
        STD_METHOD GetPixelFormat, :THIS_
        STD_METHOD GetSurfaceDesc, :THIS_
        STD_METHOD Initialize, :THIS_, :LPDDSURFACEDESC
        STD_METHOD IsLost, :THIS_
        STD_METHOD Lock_, :THIS_, :LPDDSURFACEDESC, :DWORD, :HANDLE
        STD_METHOD ReleaseDC, :THIS_
        STD_METHOD Restore, :THIS_
        STD_METHOD SetClipper, :THIS_
        STD_METHOD SetColorKey, :THIS_, :LPDDCOLORKEY
        STD_METHOD SetOverlayPosition, :THIS_, :LONG
        STD_METHOD SetPalette, :THIS_
        STD_METHOD Unlock, :THIS_
        STD_METHOD UpdateOverlay, :THIS_, :LPDIRECTDRAWSURFACE2, :LPRECT, :DWORD, :LPDDOVERLAYFX
        STD_METHOD UpdateOverlayDisplay, :THIS_
        STD_METHOD UpdateOverlayZOrder, :THIS_, :LPDIRECTDRAWSURFACE2
        STD_METHOD GetDDInterface, :ptr THIS_
        STD_METHOD PageLock, :THIS_
        STD_METHOD PageUnlock, :THIS_
      END_DECLARE_INTERFACE_
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
      INTERFACE equ <IDirectDrawSurface3>
      DECLARE_INTERFACE_ IDirectDrawSurface3, IUnknown
        STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD AddAttachedSurface, :THIS_
        STD_METHOD AddOverlayDirtyRect, :THIS_
        STD_METHOD Blt, :THIS_, :LPDIRECTDRAWSURFACE3, :LPRECT, :DWORD, :LPDDBLTFX
        STD_METHOD BltBatch, :THIS_, :DWORD, :DWORD
        STD_METHOD BltFast, :THIS_, :DWORD, :LPDIRECTDRAWSURFACE3, :LPRECT, :DWORD
        STD_METHOD DeleteAttachedSurface, :THIS_, :LPDIRECTDRAWSURFACE3
        STD_METHOD EnumAttachedSurfaces, :THIS_, :LPDDENUMSURFACESCALLBACK
        STD_METHOD EnumOverlayZOrders, :THIS_, :LPVOID, :LPDDENUMSURFACESCALLBACK
        STD_METHOD Flip, :THIS_, :DWORD
        STD_METHOD GetAttachedSurface, :THIS_, :ptr LPDIRECTDRAWSURFACE3
        STD_METHOD GetBltStatus, :THIS_
        STD_METHOD GetCaps, :THIS_
        STD_METHOD GetClipper, :ptr THIS_
        STD_METHOD GetColorKey, :THIS_, :LPDDCOLORKEY
        STD_METHOD GetDC, :ptr THIS_
        STD_METHOD GetFlipStatus, :THIS_
        STD_METHOD GetOverlayPosition, :THIS_, :LPLONG
        STD_METHOD GetPalette, :ptr THIS_
        STD_METHOD GetPixelFormat, :THIS_
        STD_METHOD GetSurfaceDesc, :THIS_
        STD_METHOD Initialize, :THIS_, :LPDDSURFACEDESC
        STD_METHOD IsLost, :THIS_
        STD_METHOD Lock_, :THIS_, :LPDDSURFACEDESC, :DWORD, :HANDLE
        STD_METHOD ReleaseDC, :THIS_
        STD_METHOD Restore, :THIS_
        STD_METHOD SetClipper, :THIS_
        STD_METHOD SetColorKey, :THIS_, :LPDDCOLORKEY
        STD_METHOD SetOverlayPosition, :THIS_, :LONG
        STD_METHOD SetPalette, :THIS_
        STD_METHOD Unlock, :THIS_
        STD_METHOD UpdateOverlay, :THIS_, :LPDIRECTDRAWSURFACE3, :LPRECT, :DWORD, :LPDDOVERLAYFX
        STD_METHOD UpdateOverlayDisplay, :THIS_
        STD_METHOD UpdateOverlayZOrder, :THIS_, :LPDIRECTDRAWSURFACE3
        STD_METHOD GetDDInterface, :ptr THIS_
        STD_METHOD PageLock, :THIS_
        STD_METHOD PageUnlock, :THIS_
        STD_METHOD SetSurfaceDesc, :THIS_, :DWORD
      END_DECLARE_INTERFACE_
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
      INTERFACE equ <IDirectDrawSurface4>
      DECLARE_INTERFACE_ IDirectDrawSurface4, IUnknown
        STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD AddAttachedSurface, :THIS_
        STD_METHOD AddOverlayDirtyRect, :THIS_
        STD_METHOD Blt, :THIS_, :LPDIRECTDRAWSURFACE4, :LPRECT, :DWORD, :LPDDBLTFX
        STD_METHOD BltBatch, :THIS_, :DWORD, :DWORD
        STD_METHOD BltFast, :THIS_, :DWORD, :LPDIRECTDRAWSURFACE4, :LPRECT, :DWORD
        STD_METHOD DeleteAttachedSurface, :THIS_, :LPDIRECTDRAWSURFACE4
        STD_METHOD EnumAttachedSurfaces, :THIS_, :LPDDENUMSURFACESCALLBACK2
        STD_METHOD EnumOverlayZOrders, :THIS_, :LPVOID, :LPDDENUMSURFACESCALLBACK2
        STD_METHOD Flip, :THIS_, :DWORD
        STD_METHOD GetAttachedSurface, :THIS_, :ptr LPDIRECTDRAWSURFACE4
        STD_METHOD GetBltStatus, :THIS_
        STD_METHOD GetCaps, :THIS_
        STD_METHOD GetClipper, :ptr THIS_
        STD_METHOD GetColorKey, :THIS_, :LPDDCOLORKEY
        STD_METHOD GetDC, :ptr THIS_
        STD_METHOD GetFlipStatus, :THIS_
        STD_METHOD GetOverlayPosition, :THIS_, :LPLONG
        STD_METHOD GetPalette, :ptr THIS_
        STD_METHOD GetPixelFormat, :THIS_
        STD_METHOD GetSurfaceDesc, :THIS_
        STD_METHOD Initialize, :THIS_, :LPDDSURFACEDESC2
        STD_METHOD IsLost, :THIS_
        STD_METHOD Lock_, :THIS_, :LPDDSURFACEDESC2, :DWORD, :HANDLE
        STD_METHOD ReleaseDC, :THIS_
        STD_METHOD Restore, :THIS_
        STD_METHOD SetClipper, :THIS_
        STD_METHOD SetColorKey, :THIS_, :LPDDCOLORKEY
        STD_METHOD SetOverlayPosition, :THIS_, :LONG
        STD_METHOD SetPalette, :THIS_
        STD_METHOD Unlock, :THIS_
        STD_METHOD UpdateOverlay, :THIS_, :LPDIRECTDRAWSURFACE4, :LPRECT, :DWORD, :LPDDOVERLAYFX
        STD_METHOD UpdateOverlayDisplay, :THIS_
        STD_METHOD UpdateOverlayZOrder, :THIS_, :LPDIRECTDRAWSURFACE4
        STD_METHOD GetDDInterface, :ptr THIS_
        STD_METHOD PageLock, :THIS_
        STD_METHOD PageUnlock, :THIS_
        STD_METHOD SetSurfaceDesc, :THIS_, :DWORD
        STD_METHOD SetPrivateData, :THIS_, :LPVOID, :DWORD, :DWORD
        STD_METHOD GetPrivateData, :THIS_, :LPVOID, :LPDWORD
        STD_METHOD FreePrivateData, :THIS_
        STD_METHOD GetUniquenessValue, :THIS_
        STD_METHOD ChangeUniquenessValue, :THIS_
      END_DECLARE_INTERFACE_
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
      INTERFACE equ <IDirectDrawSurface7>
      DECLARE_INTERFACE_ IDirectDrawSurface7, IUnknown
        STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
        STD_METHOD AddRef, :THIS_
        STD_METHOD Release, :THIS_
        STD_METHOD AddAttachedSurface, :THIS_
        STD_METHOD AddOverlayDirtyRect, :THIS_
        STD_METHOD Blt, :THIS_, :LPDIRECTDRAWSURFACE7, :LPRECT, :DWORD, :LPDDBLTFX
        STD_METHOD BltBatch, :THIS_, :DWORD, :DWORD
        STD_METHOD BltFast, :THIS_, :DWORD, :LPDIRECTDRAWSURFACE7, :LPRECT, :DWORD
        STD_METHOD DeleteAttachedSurface, :THIS_, :LPDIRECTDRAWSURFACE7
        STD_METHOD EnumAttachedSurfaces, :THIS_, :LPDDENUMSURFACESCALLBACK7
        STD_METHOD EnumOverlayZOrders, :THIS_, :LPVOID, :LPDDENUMSURFACESCALLBACK7
        STD_METHOD Flip, :THIS_, :DWORD
        STD_METHOD GetAttachedSurface, :THIS_, :ptr LPDIRECTDRAWSURFACE7
        STD_METHOD GetBltStatus, :THIS_
        STD_METHOD GetCaps, :THIS_
        STD_METHOD GetClipper, :ptr THIS_
        STD_METHOD GetColorKey, :THIS_, :LPDDCOLORKEY
        STD_METHOD GetDC, :ptr THIS_
        STD_METHOD GetFlipStatus, :THIS_
        STD_METHOD GetOverlayPosition, :THIS_, :LPLONG
        STD_METHOD GetPalette, :ptr THIS_
        STD_METHOD GetPixelFormat, :THIS_
        STD_METHOD GetSurfaceDesc, :THIS_
        STD_METHOD Initialize, :THIS_, :LPDDSURFACEDESC2
        STD_METHOD IsLost, :THIS_
        STD_METHOD Lock_, :THIS_, :LPDDSURFACEDESC2, :DWORD, :HANDLE
        STD_METHOD ReleaseDC, :THIS_
        STD_METHOD Restore, :THIS_
        STD_METHOD SetClipper, :THIS_
        STD_METHOD SetColorKey, :THIS_, :LPDDCOLORKEY
        STD_METHOD SetOverlayPosition, :THIS_, :LONG
        STD_METHOD SetPalette, :THIS_
        STD_METHOD Unlock, :THIS_
        STD_METHOD UpdateOverlay, :THIS_, :LPDIRECTDRAWSURFACE7, :LPRECT, :DWORD, :LPDDOVERLAYFX
        STD_METHOD UpdateOverlayDisplay, :THIS_
        STD_METHOD UpdateOverlayZOrder, :THIS_, :LPDIRECTDRAWSURFACE7
        STD_METHOD GetDDInterface, :ptr THIS_
        STD_METHOD PageLock, :THIS_
        STD_METHOD PageUnlock, :THIS_
        STD_METHOD SetSurfaceDesc, :THIS_, :DWORD
        STD_METHOD SetPrivateData, :THIS_, :LPVOID, :DWORD, :DWORD
        STD_METHOD GetPrivateData, :THIS_, :LPVOID, :LPDWORD
        STD_METHOD FreePrivateData, :THIS_
        STD_METHOD GetUniquenessValue, :THIS_
        STD_METHOD ChangeUniquenessValue, :THIS_
        STD_METHOD SetPriority, :THIS_
        STD_METHOD GetPriority, :THIS_
        STD_METHOD SetLOD, :THIS_
        STD_METHOD GetLOD, :THIS_
      END_DECLARE_INTERFACE_
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
      if Defined(_WIN32) and  not Defined(_NO_COM)
        INTERFACE equ <IDirectDrawColorControl>
        DECLARE_INTERFACE_ IDirectDrawColorControl, IUnknown
          STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
          STD_METHOD AddRef, :THIS_
          STD_METHOD Release, :THIS_
          STD_METHOD GetColorControls, :THIS_
          STD_METHOD SetColorControls, :THIS_
        END_DECLARE_INTERFACE_
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
      if Defined(_WIN32) and  not Defined(_NO_COM)
        INTERFACE equ <IDirectDrawGammaControl>
        DECLARE_INTERFACE_ IDirectDrawGammaControl, IUnknown
          STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
          STD_METHOD AddRef, :THIS_
          STD_METHOD Release, :THIS_
          STD_METHOD GetGammaRamp, :THIS_, :LPDDGAMMARAMP
          STD_METHOD SetGammaRamp, :THIS_, :LPDDGAMMARAMP
        END_DECLARE_INTERFACE_
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
    DDSURFACEDESC struct
      dwSize DWORD ?
      dwFlags DWORD ?
      dwHeight DWORD ?
      dwWidth DWORD ?
      union DUMMYUNIONNAMEN(1)
        lPitch LONG ?
        dwLinearSize DWORD ?
      ends
      dwBackBufferCount DWORD ?
      union DUMMYUNIONNAMEN(2)
        dwMipMapCount DWORD ?
        dwZBufferBitDepth DWORD ?
        dwRefreshRate DWORD ?
      ends
      dwAlphaBitDepth DWORD ?
      dwReserved DWORD ?
      lpSurface LPVOID ?
      ddckCKDestOverlay DDCOLORKEY <>
      ddckCKDestBlt DDCOLORKEY <>
      ddckCKSrcOverlay DDCOLORKEY <>
      ddckCKSrcBlt DDCOLORKEY <>
      ddpfPixelFormat DDPIXELFORMAT <>
      ddsCaps DDSCAPS <>
    DDSURFACEDESC ends

    _DDSURFACEDESC typedef DDSURFACEDESC
    DDSURFACEDESC2 struct
      dwSize DWORD ?
      dwFlags DWORD ?
      dwHeight DWORD ?
      dwWidth DWORD ?
      union DUMMYUNIONNAMEN(1)
        lPitch LONG ?
        dwLinearSize DWORD ?
      ends
      union DUMMYUNIONNAMEN(5)
        dwBackBufferCount DWORD ?
        dwDepth DWORD ?
      ends
      union DUMMYUNIONNAMEN(2)
        dwMipMapCount DWORD ?
        dwRefreshRate DWORD ?
        dwSrcVBHandle DWORD ?
      ends
      dwAlphaBitDepth DWORD ?
      dwReserved DWORD ?
      lpSurface LPVOID ?
      union DUMMYUNIONNAMEN(3)
        ddckCKDestOverlay DDCOLORKEY <>
        dwEmptyFaceColor DWORD ?
      ends
      ddckCKDestBlt DDCOLORKEY <>
      ddckCKSrcOverlay DDCOLORKEY <>
      ddckCKSrcBlt DDCOLORKEY <>
      union DUMMYUNIONNAMEN(4)
        ddpfPixelFormat DDPIXELFORMAT <>
        dwFVF DWORD ?
      ends
      ddsCaps DDSCAPS2 <>
      dwTextureStage DWORD ?
    DDSURFACEDESC2 ends

    _DDSURFACEDESC2 typedef DDSURFACEDESC2
    DDSD_CAPS equ 00000001h
    DDSD_HEIGHT equ 00000002h
    DDSD_WIDTH equ 00000004h
    DDSD_PITCH equ 00000008h
    DDSD_BACKBUFFERCOUNT equ 00000020h
    DDSD_ZBUFFERBITDEPTH equ 00000040h
    DDSD_ALPHABITDEPTH equ 00000080h
    DDSD_LPSURFACE equ 00000800h
    DDSD_PIXELFORMAT equ 00001000h
    DDSD_CKDESTOVERLAY equ 00002000h
    DDSD_CKDESTBLT equ 00004000h
    DDSD_CKSRCOVERLAY equ 00008000h
    DDSD_CKSRCBLT equ 00010000h
    DDSD_MIPMAPCOUNT equ 00020000h
    DDSD_REFRESHRATE equ 00040000h
    DDSD_LINEARSIZE equ 00080000h
    DDSD_TEXTURESTAGE equ 00100000h
    DDSD_FVF equ 00200000h
    DDSD_SRCVBHANDLE equ 00400000h
    DDSD_DEPTH equ 00800000h
    DDSD_ALL equ 00fff9eeh
    DDOPTSURFACEDESC struct
      dwSize DWORD ?
      dwFlags DWORD ?
      ddSCaps DDSCAPS2 <>
      ddOSCaps DDOSCAPS <>
      guid GUID <>
      dwCompressionRatio DWORD ?
    DDOPTSURFACEDESC ends

    _DDOPTSURFACEDESC typedef DDOPTSURFACEDESC
    DDOSD_GUID equ 00000001h
    DDOSD_COMPRESSION_RATIO equ 00000002h
    DDOSD_SCAPS equ 00000004h
    DDOSD_OSCAPS equ 00000008h
    DDOSD_ALL equ 0000000fh
    DDOSDCAPS_OPTCOMPRESSED equ 00000001h
    DDOSDCAPS_OPTREORDERED equ 00000002h
    DDOSDCAPS_MONOLITHICMIPMAP equ 00000004h
    DDOSDCAPS_VALIDSCAPS equ 30004800h
    DDOSDCAPS_VALIDOSCAPS equ 00000007h
    DDCOLORCONTROL struct
      dwSize DWORD ?
      dwFlags DWORD ?
      lBrightness LONG ?
      lContrast LONG ?
      lHue LONG ?
      lSaturation LONG ?
      lSharpness LONG ?
      lGamma LONG ?
      lColorEnable LONG ?
      dwReserved1 DWORD ?
    DDCOLORCONTROL ends

    _DDCOLORCONTROL typedef DDCOLORCONTROL
    DDCOLOR_BRIGHTNESS equ 00000001h
    DDCOLOR_CONTRAST equ 00000002h
    DDCOLOR_HUE equ 00000004h
    DDCOLOR_SATURATION equ 00000008h
    DDCOLOR_SHARPNESS equ 00000010h
    DDCOLOR_GAMMA equ 00000020h
    DDCOLOR_COLORENABLE equ 00000040h
    DDSCAPS_RESERVED1 equ 00000001h
    DDSCAPS_ALPHA equ 00000002h
    DDSCAPS_BACKBUFFER equ 00000004h
    DDSCAPS_COMPLEX equ 00000008h
    DDSCAPS_FLIP equ 00000010h
    DDSCAPS_FRONTBUFFER equ 00000020h
    DDSCAPS_OFFSCREENPLAIN equ 00000040h
    DDSCAPS_OVERLAY equ 00000080h
    DDSCAPS_PALETTE equ 00000100h
    DDSCAPS_PRIMARYSURFACE equ 00000200h
    DDSCAPS_RESERVED3 equ 00000400h
    DDSCAPS_PRIMARYSURFACELEFT equ 00000000h
    DDSCAPS_SYSTEMMEMORY equ 00000800h
    DDSCAPS_TEXTURE equ 00001000h
    DDSCAPS_3DDEVICE equ 00002000h
    DDSCAPS_VIDEOMEMORY equ 00004000h
    DDSCAPS_VISIBLE equ 00008000h
    DDSCAPS_WRITEONLY equ 00010000h
    DDSCAPS_ZBUFFER equ 00020000h
    DDSCAPS_OWNDC equ 00040000h
    DDSCAPS_LIVEVIDEO equ 00080000h
    DDSCAPS_HWCODEC equ 00100000h
    DDSCAPS_MODEX equ 00200000h
    DDSCAPS_MIPMAP equ 00400000h
    DDSCAPS_RESERVED2 equ 00800000h
    DDSCAPS_ALLOCONLOAD equ 04000000h
    DDSCAPS_VIDEOPORT equ 08000000h
    DDSCAPS_LOCALVIDMEM equ 10000000h
    DDSCAPS_NONLOCALVIDMEM equ 20000000h
    DDSCAPS_STANDARDVGAMODE equ 40000000h
    DDSCAPS_OPTIMIZED equ 80000000h
    DDSCAPS2_RESERVED4 equ 00000002h
    DDSCAPS2_HARDWAREDEINTERLACE equ 00000000h
    DDSCAPS2_HINTDYNAMIC equ 00000004h
    DDSCAPS2_HINTSTATIC equ 00000008h
    DDSCAPS2_TEXTUREMANAGE equ 00000010h
    DDSCAPS2_RESERVED1 equ 00000020h
    DDSCAPS2_RESERVED2 equ 00000040h
    DDSCAPS2_OPAQUE equ 00000080h
    DDSCAPS2_HINTANTIALIASING equ 00000100h
    DDSCAPS2_CUBEMAP equ 00000200h
    DDSCAPS2_CUBEMAP_POSITIVEX equ 00000400h
    DDSCAPS2_CUBEMAP_NEGATIVEX equ 00000800h
    DDSCAPS2_CUBEMAP_POSITIVEY equ 00001000h
    DDSCAPS2_CUBEMAP_NEGATIVEY equ 00002000h
    DDSCAPS2_CUBEMAP_POSITIVEZ equ 00004000h
    DDSCAPS2_CUBEMAP_NEGATIVEZ equ 00008000h
    DDSCAPS2_CUBEMAP_ALLFACES equ <(DDSCAPS2_CUBEMAP_POSITIVEX or DDSCAPS2_CUBEMAP_NEGATIVEX or DDSCAPS2_CUBEMAP_POSITIVEY or DDSCAPS2_CUBEMAP_NEGATIVEY or DDSCAPS2_CUBEMAP_POSITIVEZ or DDSCAPS2_CUBEMAP_NEGATIVEZ)>
    DDSCAPS2_MIPMAPSUBLEVEL equ 00010000h
    DDSCAPS2_D3DTEXTUREMANAGE equ 00020000h
    DDSCAPS2_DONOTPERSIST equ 00040000h
    DDSCAPS2_STEREOSURFACELEFT equ 00080000h
    DDSCAPS2_VOLUME equ 00200000h
    DDSCAPS2_NOTUSERLOCKABLE equ 00400000h
    DDSCAPS2_POINTS equ 00800000h
    DDSCAPS2_RTPATCHES equ 01000000h
    DDSCAPS2_NPATCHES equ 02000000h
    DDSCAPS2_RESERVED3 equ 04000000h
    DDSCAPS2_DISCARDBACKBUFFER equ 10000000h
    DDSCAPS2_ENABLEALPHACHANNEL equ 20000000h
    DDSCAPS2_EXTENDEDFORMATPRIMARY equ 40000000h
    DDSCAPS2_ADDITIONALPRIMARY equ 80000000h
    DDSCAPS3_MULTISAMPLE_MASK equ 0000001Fh
    DDSCAPS3_MULTISAMPLE_QUALITY_MASK equ 000000E0h
    DDSCAPS3_MULTISAMPLE_QUALITY_SHIFT equ 5
    DDSCAPS3_RESERVED1 equ 00000100h
    DDSCAPS3_RESERVED2 equ 00000200h
    DDSCAPS3_LIGHTWEIGHTMIPMAP equ 00000400h
    DDSCAPS3_AUTOGENMIPMAP equ 00000800h
    DDSCAPS3_DMAP equ 00001000h
    if  not Defined(D3D_DISABLE_9EX)
      DDSCAPS3_CREATESHAREDRESOURCE equ 00002000h
      DDSCAPS3_READONLYRESOURCE equ 00004000h
      DDSCAPS3_OPENSHAREDRESOURCE equ 00008000h
    endif
    DDCAPS_3D equ 00000001h
    DDCAPS_ALIGNBOUNDARYDEST equ 00000002h
    DDCAPS_ALIGNSIZEDEST equ 00000004h
    DDCAPS_ALIGNBOUNDARYSRC equ 00000008h
    DDCAPS_ALIGNSIZESRC equ 00000010h
    DDCAPS_ALIGNSTRIDE equ 00000020h
    DDCAPS_BLT equ 00000040h
    DDCAPS_BLTQUEUE equ 00000080h
    DDCAPS_BLTFOURCC equ 00000100h
    DDCAPS_BLTSTRETCH equ 00000200h
    DDCAPS_GDI equ 00000400h
    DDCAPS_OVERLAY equ 00000800h
    DDCAPS_OVERLAYCANTCLIP equ 00001000h
    DDCAPS_OVERLAYFOURCC equ 00002000h
    DDCAPS_OVERLAYSTRETCH equ 00004000h
    DDCAPS_PALETTE equ 00008000h
    DDCAPS_PALETTEVSYNC equ 00010000h
    DDCAPS_READSCANLINE equ 00020000h
    DDCAPS_RESERVED1 equ 00040000h
    DDCAPS_VBI equ 00080000h
    DDCAPS_ZBLTS equ 00100000h
    DDCAPS_ZOVERLAYS equ 00200000h
    DDCAPS_COLORKEY equ 00400000h
    DDCAPS_ALPHA equ 00800000h
    DDCAPS_COLORKEYHWASSIST equ 01000000h
    DDCAPS_NOHARDWARE equ 02000000h
    DDCAPS_BLTCOLORFILL equ 04000000h
    DDCAPS_BANKSWITCHED equ 08000000h
    DDCAPS_BLTDEPTHFILL equ 10000000h
    DDCAPS_CANCLIP equ 20000000h
    DDCAPS_CANCLIPSTRETCHED equ 40000000h
    DDCAPS_CANBLTSYSMEM equ 80000000h
    DDCAPS2_CERTIFIED equ 00000001h
    DDCAPS2_NO2DDURING3DSCENE equ 00000002h
    DDCAPS2_VIDEOPORT equ 00000004h
    DDCAPS2_AUTOFLIPOVERLAY equ 00000008h
    DDCAPS2_CANBOBINTERLEAVED equ 00000010h
    DDCAPS2_CANBOBNONINTERLEAVED equ 00000020h
    DDCAPS2_COLORCONTROLOVERLAY equ 00000040h
    DDCAPS2_COLORCONTROLPRIMARY equ 00000080h
    DDCAPS2_CANDROPZ16BIT equ 00000100h
    DDCAPS2_NONLOCALVIDMEM equ 00000200h
    DDCAPS2_NONLOCALVIDMEMCAPS equ 00000400h
    DDCAPS2_NOPAGELOCKREQUIRED equ 00000800h
    DDCAPS2_WIDESURFACES equ 00001000h
    DDCAPS2_CANFLIPODDEVEN equ 00002000h
    DDCAPS2_CANBOBHARDWARE equ 00004000h
    DDCAPS2_COPYFOURCC equ 00008000h
    DDCAPS2_PRIMARYGAMMA equ 00020000h
    DDCAPS2_CANRENDERWINDOWED equ 00080000h
    DDCAPS2_CANCALIBRATEGAMMA equ 00100000h
    DDCAPS2_FLIPINTERVAL equ 00200000h
    DDCAPS2_FLIPNOVSYNC equ 00400000h
    DDCAPS2_CANMANAGETEXTURE equ 00800000h
    DDCAPS2_TEXMANINNONLOCALVIDMEM equ 01000000h
    DDCAPS2_STEREO equ 02000000h
    DDCAPS2_SYSTONONLOCAL_AS_SYSTOLOCAL equ 04000000h
    DDCAPS2_RESERVED1 equ 08000000h
    DDCAPS2_CANMANAGERESOURCE equ 10000000h
    DDCAPS2_DYNAMICTEXTURES equ 20000000h
    DDCAPS2_CANAUTOGENMIPMAP equ 40000000h
    if  not Defined(D3D_DISABLE_9EX)
      DDCAPS2_CANSHARERESOURCE equ 80000000h
    endif
    DDFXALPHACAPS_BLTALPHAEDGEBLEND equ 00000001h
    DDFXALPHACAPS_BLTALPHAPIXELS equ 00000002h
    DDFXALPHACAPS_BLTALPHAPIXELSNEG equ 00000004h
    DDFXALPHACAPS_BLTALPHASURFACES equ 00000008h
    DDFXALPHACAPS_BLTALPHASURFACESNEG equ 00000010h
    DDFXALPHACAPS_OVERLAYALPHAEDGEBLEND equ 00000020h
    DDFXALPHACAPS_OVERLAYALPHAPIXELS equ 00000040h
    DDFXALPHACAPS_OVERLAYALPHAPIXELSNEG equ 00000080h
    DDFXALPHACAPS_OVERLAYALPHASURFACES equ 00000100h
    DDFXALPHACAPS_OVERLAYALPHASURFACESNEG equ 00000200h
    if DIRECTDRAW_VERSION lt 0600h
    endif
    DDFXCAPS_BLTARITHSTRETCHY equ 00000020h
    DDFXCAPS_BLTARITHSTRETCHYN equ 00000010h
    DDFXCAPS_BLTMIRRORLEFTRIGHT equ 00000040h
    DDFXCAPS_BLTMIRRORUPDOWN equ 00000080h
    DDFXCAPS_BLTROTATION equ 00000100h
    DDFXCAPS_BLTROTATION90 equ 00000200h
    DDFXCAPS_BLTSHRINKX equ 00000400h
    DDFXCAPS_BLTSHRINKXN equ 00000800h
    DDFXCAPS_BLTSHRINKY equ 00001000h
    DDFXCAPS_BLTSHRINKYN equ 00002000h
    DDFXCAPS_BLTSTRETCHX equ 00004000h
    DDFXCAPS_BLTSTRETCHXN equ 00008000h
    DDFXCAPS_BLTSTRETCHY equ 00010000h
    DDFXCAPS_BLTSTRETCHYN equ 00020000h
    DDFXCAPS_OVERLAYARITHSTRETCHY equ 00040000h
    DDFXCAPS_OVERLAYARITHSTRETCHYN equ 00000008h
    DDFXCAPS_OVERLAYSHRINKX equ 00080000h
    DDFXCAPS_OVERLAYSHRINKXN equ 00100000h
    DDFXCAPS_OVERLAYSHRINKY equ 00200000h
    DDFXCAPS_OVERLAYSHRINKYN equ 00400000h
    DDFXCAPS_OVERLAYSTRETCHX equ 00800000h
    DDFXCAPS_OVERLAYSTRETCHXN equ 01000000h
    DDFXCAPS_OVERLAYSTRETCHY equ 02000000h
    DDFXCAPS_OVERLAYSTRETCHYN equ 04000000h
    DDFXCAPS_OVERLAYMIRRORLEFTRIGHT equ 08000000h
    DDFXCAPS_OVERLAYMIRRORUPDOWN equ 10000000h
    DDFXCAPS_OVERLAYDEINTERLACE equ 20000000h
    DDFXCAPS_BLTALPHA equ 00000001h
    DDFXCAPS_BLTFILTER equ <DDFXCAPS_BLTARITHSTRETCHY>
    DDFXCAPS_OVERLAYALPHA equ 00000004h
    DDFXCAPS_OVERLAYFILTER equ <DDFXCAPS_OVERLAYARITHSTRETCHY>
    DDSVCAPS_RESERVED1 equ 00000001h
    DDSVCAPS_RESERVED2 equ 00000002h
    DDSVCAPS_RESERVED3 equ 00000004h
    DDSVCAPS_RESERVED4 equ 00000008h
    DDSVCAPS_STEREOSEQUENTIAL equ 00000010h
    DDPCAPS_4BIT equ 00000001h
    DDPCAPS_8BITENTRIES equ 00000002h
    DDPCAPS_8BIT equ 00000004h
    DDPCAPS_INITIALIZE equ 00000000h
    DDPCAPS_PRIMARYSURFACE equ 00000010h
    DDPCAPS_PRIMARYSURFACELEFT equ 00000020h
    DDPCAPS_ALLOW256 equ 00000040h
    DDPCAPS_VSYNC equ 00000080h
    DDPCAPS_1BIT equ 00000100h
    DDPCAPS_2BIT equ 00000200h
    DDPCAPS_ALPHA equ 00000400h
    DDSPD_IUNKNOWNPOINTER equ 00000001h
    DDSPD_VOLATILE equ 00000002h
    DDBD_1 equ 00004000h
    DDBD_2 equ 00002000h
    DDBD_4 equ 00001000h
    DDBD_8 equ 00000800h
    DDBD_16 equ 00000400h
    DDBD_24 equ 00000200h
    DDBD_32 equ 00000100h
    DDCKEY_COLORSPACE equ 00000001h
    DDCKEY_DESTBLT equ 00000002h
    DDCKEY_DESTOVERLAY equ 00000004h
    DDCKEY_SRCBLT equ 00000008h
    DDCKEY_SRCOVERLAY equ 00000010h
    DDCKEYCAPS_DESTBLT equ 00000001h
    DDCKEYCAPS_DESTBLTCLRSPACE equ 00000002h
    DDCKEYCAPS_DESTBLTCLRSPACEYUV equ 00000004h
    DDCKEYCAPS_DESTBLTYUV equ 00000008h
    DDCKEYCAPS_DESTOVERLAY equ 00000010h
    DDCKEYCAPS_DESTOVERLAYCLRSPACE equ 00000020h
    DDCKEYCAPS_DESTOVERLAYCLRSPACEYUV equ 00000040h
    DDCKEYCAPS_DESTOVERLAYONEACTIVE equ 00000080h
    DDCKEYCAPS_DESTOVERLAYYUV equ 00000100h
    DDCKEYCAPS_SRCBLT equ 00000200h
    DDCKEYCAPS_SRCBLTCLRSPACE equ 00000400h
    DDCKEYCAPS_SRCBLTCLRSPACEYUV equ 00000800h
    DDCKEYCAPS_SRCBLTYUV equ 00001000h
    DDCKEYCAPS_SRCOVERLAY equ 00002000h
    DDCKEYCAPS_SRCOVERLAYCLRSPACE equ 00004000h
    DDCKEYCAPS_SRCOVERLAYCLRSPACEYUV equ 00008000h
    DDCKEYCAPS_SRCOVERLAYONEACTIVE equ 00010000h
    DDCKEYCAPS_SRCOVERLAYYUV equ 00020000h
    DDCKEYCAPS_NOCOSTOVERLAY equ 00040000h
    DDPF_ALPHAPIXELS equ 00000001h
    DDPF_ALPHA equ 00000002h
    DDPF_FOURCC equ 00000004h
    DDPF_PALETTEINDEXED4 equ 00000008h
    DDPF_PALETTEINDEXEDTO8 equ 00000010h
    DDPF_PALETTEINDEXED8 equ 00000020h
    DDPF_RGB equ 00000040h
    DDPF_COMPRESSED equ 00000080h
    DDPF_RGBTOYUV equ 00000100h
    DDPF_YUV equ 00000200h
    DDPF_ZBUFFER equ 00000400h
    DDPF_PALETTEINDEXED1 equ 00000800h
    DDPF_PALETTEINDEXED2 equ 00001000h
    DDPF_ZPIXELS equ 00002000h
    DDPF_STENCILBUFFER equ 00004000h
    DDPF_ALPHAPREMULT equ 00008000h
    DDPF_LUMINANCE equ 00020000h
    DDPF_BUMPLUMINANCE equ 00040000h
    DDPF_BUMPDUDV equ 00080000h
    DDENUMSURFACES_ALL equ 00000001h
    DDENUMSURFACES_MATCH equ 00000002h
    DDENUMSURFACES_NOMATCH equ 00000004h
    DDENUMSURFACES_CANBECREATED equ 00000008h
    DDENUMSURFACES_DOESEXIST equ 00000010h
    DDSDM_STANDARDVGAMODE equ 00000001h
    DDEDM_REFRESHRATES equ 00000001h
    DDEDM_STANDARDVGAMODES equ 00000002h
    DDSCL_FULLSCREEN equ 00000001h
    DDSCL_ALLOWREBOOT equ 00000002h
    DDSCL_NOWINDOWCHANGES equ 00000004h
    DDSCL_NORMAL equ 00000008h
    DDSCL_EXCLUSIVE equ 00000010h
    DDSCL_ALLOWMODEX equ 00000040h
    DDSCL_SETFOCUSWINDOW equ 00000080h
    DDSCL_SETDEVICEWINDOW equ 00000100h
    DDSCL_CREATEDEVICEWINDOW equ 00000200h
    DDSCL_MULTITHREADED equ 00000400h
    DDSCL_FPUSETUP equ 00000800h
    DDSCL_FPUPRESERVE equ 00001000h
    DDBLT_ALPHADEST equ 00000001h
    DDBLT_ALPHADESTCONSTOVERRIDE equ 00000002h
    DDBLT_ALPHADESTNEG equ 00000004h
    DDBLT_ALPHADESTSURFACEOVERRIDE equ 00000008h
    DDBLT_ALPHAEDGEBLEND equ 00000010h
    DDBLT_ALPHASRC equ 00000020h
    DDBLT_ALPHASRCCONSTOVERRIDE equ 00000040h
    DDBLT_ALPHASRCNEG equ 00000080h
    DDBLT_ALPHASRCSURFACEOVERRIDE equ 00000100h
    DDBLT_ASYNC equ 00000200h
    DDBLT_COLORFILL equ 00000400h
    DDBLT_DDFX equ 00000800h
    DDBLT_DDROPS equ 00001000h
    DDBLT_KEYDEST equ 00002000h
    DDBLT_KEYDESTOVERRIDE equ 00004000h
    DDBLT_KEYSRC equ 00008000h
    DDBLT_KEYSRCOVERRIDE equ 00010000h
    DDBLT_ROP equ 00020000h
    DDBLT_ROTATIONANGLE equ 00040000h
    DDBLT_ZBUFFER equ 00080000h
    DDBLT_ZBUFFERDESTCONSTOVERRIDE equ 00100000h
    DDBLT_ZBUFFERDESTOVERRIDE equ 00200000h
    DDBLT_ZBUFFERSRCCONSTOVERRIDE equ 00400000h
    DDBLT_ZBUFFERSRCOVERRIDE equ 00800000h
    DDBLT_WAIT equ 01000000h
    DDBLT_DEPTHFILL equ 02000000h
    DDBLT_DONOTWAIT equ 08000000h
    DDBLT_PRESENTATION equ 10000000h
    DDBLT_LAST_PRESENTATION equ 20000000h
    DDBLT_EXTENDED_FLAGS equ 40000000h
    DDBLT_EXTENDED_LINEAR_CONTENT equ 00000004h
    DDBLTFAST_NOCOLORKEY equ 00000000h
    DDBLTFAST_SRCCOLORKEY equ 00000001h
    DDBLTFAST_DESTCOLORKEY equ 00000002h
    DDBLTFAST_WAIT equ 00000010h
    DDBLTFAST_DONOTWAIT equ 00000020h
    DDFLIP_WAIT equ 00000001h
    DDFLIP_EVEN equ 00000002h
    DDFLIP_ODD equ 00000004h
    DDFLIP_NOVSYNC equ 00000008h
    DDFLIP_INTERVAL2 equ 02000000h
    DDFLIP_INTERVAL3 equ 03000000h
    DDFLIP_INTERVAL4 equ 04000000h
    DDFLIP_STEREO equ 00000010h
    DDFLIP_DONOTWAIT equ 00000020h
    DDOVER_ALPHADEST equ 00000001h
    DDOVER_ALPHADESTCONSTOVERRIDE equ 00000002h
    DDOVER_ALPHADESTNEG equ 00000004h
    DDOVER_ALPHADESTSURFACEOVERRIDE equ 00000008h
    DDOVER_ALPHAEDGEBLEND equ 00000010h
    DDOVER_ALPHASRC equ 00000020h
    DDOVER_ALPHASRCCONSTOVERRIDE equ 00000040h
    DDOVER_ALPHASRCNEG equ 00000080h
    DDOVER_ALPHASRCSURFACEOVERRIDE equ 00000100h
    DDOVER_HIDE equ 00000200h
    DDOVER_KEYDEST equ 00000400h
    DDOVER_KEYDESTOVERRIDE equ 00000800h
    DDOVER_KEYSRC equ 00001000h
    DDOVER_KEYSRCOVERRIDE equ 00002000h
    DDOVER_SHOW equ 00004000h
    DDOVER_ADDDIRTYRECT equ 00008000h
    DDOVER_REFRESHDIRTYRECTS equ 00010000h
    DDOVER_REFRESHALL equ 00020000h
    DDOVER_DDFX equ 00080000h
    DDOVER_AUTOFLIP equ 00100000h
    DDOVER_BOB equ 00200000h
    DDOVER_OVERRIDEBOBWEAVE equ 00400000h
    DDOVER_INTERLEAVED equ 00800000h
    DDOVER_BOBHARDWARE equ 01000000h
    DDOVER_ARGBSCALEFACTORS equ 02000000h
    DDOVER_DEGRADEARGBSCALING equ 04000000h
    ifdef COMBOX_SANDBOX
      DX_LONGHORN_PRESERVEDC equ <>
    endif
    ifdef DX_LONGHORN_PRESERVEDC
      DDSETSURFACEDESC_RECREATEDC equ 00000000h
      DDSETSURFACEDESC_PRESERVEDC equ 00000001h
    endif
    DDLOCK_SURFACEMEMORYPTR equ 00000000h
    DDLOCK_WAIT equ 00000001h
    DDLOCK_EVENT equ 00000002h
    DDLOCK_READONLY equ 00000010h
    DDLOCK_WRITEONLY equ 00000020h
    DDLOCK_NOSYSLOCK equ 00000800h
    DDLOCK_NOOVERWRITE equ 00001000h
    DDLOCK_DISCARDCONTENTS equ 00002000h
    DDLOCK_OKTOSWAP equ 00002000h
    DDLOCK_DONOTWAIT equ 00004000h
    DDLOCK_HASVOLUMETEXTUREBOXRECT equ 00008000h
    DDLOCK_NODIRTYUPDATE equ 00010000h
    DDBLTFX_ARITHSTRETCHY equ 00000001h
    DDBLTFX_MIRRORLEFTRIGHT equ 00000002h
    DDBLTFX_MIRRORUPDOWN equ 00000004h
    DDBLTFX_NOTEARING equ 00000008h
    DDBLTFX_ROTATE180 equ 00000010h
    DDBLTFX_ROTATE270 equ 00000020h
    DDBLTFX_ROTATE90 equ 00000040h
    DDBLTFX_ZBUFFERRANGE equ 00000080h
    DDBLTFX_ZBUFFERBASEDEST equ 00000100h
    DDOVERFX_ARITHSTRETCHY equ 00000001h
    DDOVERFX_MIRRORLEFTRIGHT equ 00000002h
    DDOVERFX_MIRRORUPDOWN equ 00000004h
    DDOVERFX_DEINTERLACE equ 00000008h
    DDWAITVB_BLOCKBEGIN equ 00000001h
    DDWAITVB_BLOCKBEGINEVENT equ 00000002h
    DDWAITVB_BLOCKEND equ 00000004h
    DDGFS_CANFLIP equ 00000001h
    DDGFS_ISFLIPDONE equ 00000002h
    DDGBS_CANBLT equ 00000001h
    DDGBS_ISBLTDONE equ 00000002h
    DDENUMOVERLAYZ_BACKTOFRONT equ 00000000h
    DDENUMOVERLAYZ_FRONTTOBACK equ 00000001h
    DDOVERZ_SENDTOFRONT equ 00000000h
    DDOVERZ_SENDTOBACK equ 00000001h
    DDOVERZ_MOVEFORWARD equ 00000002h
    DDOVERZ_MOVEBACKWARD equ 00000003h
    DDOVERZ_INSERTINFRONTOF equ 00000004h
    DDOVERZ_INSERTINBACKOF equ 00000005h
    DDSGR_CALIBRATE equ 00000001h
    DDSMT_ISTESTREQUIRED equ 00000001h
    DDEM_MODEPASSED equ 00000001h
    DDEM_MODEFAILED equ 00000002h
    DD_OK equ <S_OK>
    DD_FALSE equ <S_FALSE>
    DDENUMRET_CANCEL equ 0
    DDENUMRET_OK equ 1
    DDERR_ALREADYINITIALIZED equ MAKE_DDHRESULT(5)
    DDERR_CANNOTATTACHSURFACE equ MAKE_DDHRESULT(10)
    DDERR_CANNOTDETACHSURFACE equ MAKE_DDHRESULT(20)
    DDERR_CURRENTLYNOTAVAIL equ MAKE_DDHRESULT(40)
    DDERR_EXCEPTION equ MAKE_DDHRESULT(55)
    DDERR_GENERIC equ <E_FAIL>
    DDERR_HEIGHTALIGN equ MAKE_DDHRESULT(90)
    DDERR_INCOMPATIBLEPRIMARY equ MAKE_DDHRESULT(95)
    DDERR_INVALIDCAPS equ MAKE_DDHRESULT(100)
    DDERR_INVALIDCLIPLIST equ MAKE_DDHRESULT(110)
    DDERR_INVALIDMODE equ MAKE_DDHRESULT(120)
    DDERR_INVALIDOBJECT equ MAKE_DDHRESULT(130)
    DDERR_INVALIDPARAMS equ <E_INVALIDARG>
    DDERR_INVALIDPIXELFORMAT equ MAKE_DDHRESULT(145)
    DDERR_INVALIDRECT equ MAKE_DDHRESULT(150)
    DDERR_LOCKEDSURFACES equ MAKE_DDHRESULT(160)
    DDERR_NO3D equ MAKE_DDHRESULT(170)
    DDERR_NOALPHAHW equ MAKE_DDHRESULT(180)
    DDERR_NOSTEREOHARDWARE equ MAKE_DDHRESULT(181)
    DDERR_NOSURFACELEFT equ MAKE_DDHRESULT(182)
    DDERR_NOCLIPLIST equ MAKE_DDHRESULT(205)
    DDERR_NOCOLORCONVHW equ MAKE_DDHRESULT(210)
    DDERR_NOCOOPERATIVELEVELSET equ MAKE_DDHRESULT(212)
    DDERR_NOCOLORKEY equ MAKE_DDHRESULT(215)
    DDERR_NOCOLORKEYHW equ MAKE_DDHRESULT(220)
    DDERR_NODIRECTDRAWSUPPORT equ MAKE_DDHRESULT(222)
    DDERR_NOEXCLUSIVEMODE equ MAKE_DDHRESULT(225)
    DDERR_NOFLIPHW equ MAKE_DDHRESULT(230)
    DDERR_NOGDI equ MAKE_DDHRESULT(240)
    DDERR_NOMIRRORHW equ MAKE_DDHRESULT(250)
    DDERR_NOTFOUND equ MAKE_DDHRESULT(255)
    DDERR_NOOVERLAYHW equ MAKE_DDHRESULT(260)
    DDERR_OVERLAPPINGRECTS equ MAKE_DDHRESULT(270)
    DDERR_NORASTEROPHW equ MAKE_DDHRESULT(280)
    DDERR_NOROTATIONHW equ MAKE_DDHRESULT(290)
    DDERR_NOSTRETCHHW equ MAKE_DDHRESULT(310)
    DDERR_NOT4BITCOLOR equ MAKE_DDHRESULT(316)
    DDERR_NOT4BITCOLORINDEX equ MAKE_DDHRESULT(317)
    DDERR_NOT8BITCOLOR equ MAKE_DDHRESULT(320)
    DDERR_NOTEXTUREHW equ MAKE_DDHRESULT(330)
    DDERR_NOVSYNCHW equ MAKE_DDHRESULT(335)
    DDERR_NOZBUFFERHW equ MAKE_DDHRESULT(340)
    DDERR_NOZOVERLAYHW equ MAKE_DDHRESULT(350)
    DDERR_OUTOFCAPS equ MAKE_DDHRESULT(360)
    DDERR_OUTOFMEMORY equ <E_OUTOFMEMORY>
    DDERR_OUTOFVIDEOMEMORY equ MAKE_DDHRESULT(380)
    DDERR_OVERLAYCANTCLIP equ MAKE_DDHRESULT(382)
    DDERR_OVERLAYCOLORKEYONLYONEACTIVE equ MAKE_DDHRESULT(384)
    DDERR_PALETTEBUSY equ MAKE_DDHRESULT(387)
    DDERR_COLORKEYNOTSET equ MAKE_DDHRESULT(400)
    DDERR_SURFACEALREADYATTACHED equ MAKE_DDHRESULT(410)
    DDERR_SURFACEALREADYDEPENDENT equ MAKE_DDHRESULT(420)
    DDERR_SURFACEBUSY equ MAKE_DDHRESULT(430)
    DDERR_CANTLOCKSURFACE equ MAKE_DDHRESULT(435)
    DDERR_SURFACEISOBSCURED equ MAKE_DDHRESULT(440)
    DDERR_SURFACELOST equ MAKE_DDHRESULT(450)
    DDERR_SURFACENOTATTACHED equ MAKE_DDHRESULT(460)
    DDERR_TOOBIGHEIGHT equ MAKE_DDHRESULT(470)
    DDERR_TOOBIGSIZE equ MAKE_DDHRESULT(480)
    DDERR_TOOBIGWIDTH equ MAKE_DDHRESULT(490)
    DDERR_UNSUPPORTED equ <E_NOTIMPL>
    DDERR_UNSUPPORTEDFORMAT equ MAKE_DDHRESULT(510)
    DDERR_UNSUPPORTEDMASK equ MAKE_DDHRESULT(520)
    DDERR_INVALIDSTREAM equ MAKE_DDHRESULT(521)
    DDERR_VERTICALBLANKINPROGRESS equ MAKE_DDHRESULT(537)
    DDERR_WASSTILLDRAWING equ MAKE_DDHRESULT(540)
    DDERR_DDSCAPSCOMPLEXREQUIRED equ MAKE_DDHRESULT(542)
    DDERR_XALIGN equ MAKE_DDHRESULT(560)
    DDERR_INVALIDDIRECTDRAWGUID equ MAKE_DDHRESULT(561)
    DDERR_DIRECTDRAWALREADYCREATED equ MAKE_DDHRESULT(562)
    DDERR_NODIRECTDRAWHW equ MAKE_DDHRESULT(563)
    DDERR_PRIMARYSURFACEALREADYEXISTS equ MAKE_DDHRESULT(564)
    DDERR_NOEMULATION equ MAKE_DDHRESULT(565)
    DDERR_REGIONTOOSMALL equ MAKE_DDHRESULT(566)
    DDERR_CLIPPERISUSINGHWND equ MAKE_DDHRESULT(567)
    DDERR_NOCLIPPERATTACHED equ MAKE_DDHRESULT(568)
    DDERR_NOHWND equ MAKE_DDHRESULT(569)
    DDERR_HWNDSUBCLASSED equ MAKE_DDHRESULT(570)
    DDERR_HWNDALREADYSET equ MAKE_DDHRESULT(571)
    DDERR_NOPALETTEATTACHED equ MAKE_DDHRESULT(572)
    DDERR_NOPALETTEHW equ MAKE_DDHRESULT(573)
    DDERR_BLTFASTCANTCLIP equ MAKE_DDHRESULT(574)
    DDERR_NOBLTHW equ MAKE_DDHRESULT(575)
    DDERR_NODDROPSHW equ MAKE_DDHRESULT(576)
    DDERR_OVERLAYNOTVISIBLE equ MAKE_DDHRESULT(577)
    DDERR_NOOVERLAYDEST equ MAKE_DDHRESULT(578)
    DDERR_INVALIDPOSITION equ MAKE_DDHRESULT(579)
    DDERR_NOTAOVERLAYSURFACE equ MAKE_DDHRESULT(580)
    DDERR_EXCLUSIVEMODEALREADYSET equ MAKE_DDHRESULT(581)
    DDERR_NOTFLIPPABLE equ MAKE_DDHRESULT(582)
    DDERR_CANTDUPLICATE equ MAKE_DDHRESULT(583)
    DDERR_NOTLOCKED equ MAKE_DDHRESULT(584)
    DDERR_CANTCREATEDC equ MAKE_DDHRESULT(585)
    DDERR_NODC equ MAKE_DDHRESULT(586)
    DDERR_WRONGMODE equ MAKE_DDHRESULT(587)
    DDERR_IMPLICITLYCREATED equ MAKE_DDHRESULT(588)
    DDERR_NOTPALETTIZED equ MAKE_DDHRESULT(589)
    DDERR_UNSUPPORTEDMODE equ MAKE_DDHRESULT(590)
    DDERR_NOMIPMAPHW equ MAKE_DDHRESULT(591)
    DDERR_INVALIDSURFACETYPE equ MAKE_DDHRESULT(592)
    DDERR_NOOPTIMIZEHW equ MAKE_DDHRESULT(600)
    DDERR_NOTLOADED equ MAKE_DDHRESULT(601)
    DDERR_NOFOCUSWINDOW equ MAKE_DDHRESULT(602)
    DDERR_NOTONMIPMAPSUBLEVEL equ MAKE_DDHRESULT(603)
    DDERR_DCALREADYCREATED equ MAKE_DDHRESULT(620)
    DDERR_NONONLOCALVIDMEM equ MAKE_DDHRESULT(630)
    DDERR_CANTPAGELOCK equ MAKE_DDHRESULT(640)
    DDERR_CANTPAGEUNLOCK equ MAKE_DDHRESULT(660)
    DDERR_NOTPAGELOCKED equ MAKE_DDHRESULT(680)
    DDERR_MOREDATA equ MAKE_DDHRESULT(690)
    DDERR_EXPIRED equ MAKE_DDHRESULT(691)
    DDERR_TESTFINISHED equ MAKE_DDHRESULT(692)
    DDERR_NEWMODE equ MAKE_DDHRESULT(693)
    DDERR_D3DNOTINITIALIZED equ MAKE_DDHRESULT(694)
    DDERR_VIDEONOTACTIVE equ MAKE_DDHRESULT(695)
    DDERR_NOMONITORINFORMATION equ MAKE_DDHRESULT(696)
    DDERR_NODRIVERSUPPORT equ MAKE_DDHRESULT(697)
    DDERR_DEVICEDOESNTOWNSURFACE equ MAKE_DDHRESULT(699)
    DDERR_NOTINITIALIZED equ <CO_E_NOTINITIALIZED>
    ifdef __cplusplus
      ;[...]
    endif
    if _MSC_VER ge 1200
    else
    endif
  endif
endif

