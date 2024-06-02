;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\wingdi.h
;             Created on (UTC) 06/04/2024 06:16:03
;             Last modified on (UTC) 21/02/2024 18:18:30

include winapifamily.inc
ifndef _WINGDI_
  _WINGDI_ equ <>
  if _MSC_VER ge 1200
    ifndef _MSC_EXTENSIONS
    endif
  endif
  ifdef _MAC
    ;[...]
  endif
  if  not Defined(_GDI32_)
    WINGDIAPI equ <DECLSPEC_IMPORT>
  else
    WINGDIAPI equ <>
  endif
  if  not Defined(_SPOOL32_)
    WINSPOOLAPI equ <DECLSPEC_IMPORT>
  else
    WINSPOOLAPI equ <>
  endif
  ifdef __cplusplus
    ;[...]
  endif
  ifndef WINVER
    WINVER equ 0500h
  endif
  ifndef NOGDI
    ifndef NORASTEROPS
      R2_BLACK equ 1
      R2_NOTMERGEPEN equ 2
      R2_MASKNOTPEN equ 3
      R2_NOTCOPYPEN equ 4
      R2_MASKPENNOT equ 5
      R2_NOT equ 6
      R2_XORPEN equ 7
      R2_NOTMASKPEN equ 8
      R2_MASKPEN equ 9
      R2_NOTXORPEN equ 10
      R2_NOP equ 11
      R2_MERGENOTPEN equ 12
      R2_COPYPEN equ 13
      R2_MERGEPENNOT equ 14
      R2_MERGEPEN equ 15
      R2_WHITE equ 16
      R2_LAST equ 16
      SRCCOPY equ 00CC0020h
      SRCPAINT equ 00EE0086h
      SRCAND equ 008800C6h
      SRCINVERT equ 00660046h
      SRCERASE equ 00440328h
      NOTSRCCOPY equ 00330008h
      NOTSRCERASE equ 001100A6h
      MERGECOPY equ 00C000CAh
      MERGEPAINT equ 00BB0226h
      PATCOPY equ 00F00021h
      PATPAINT equ 00FB0A09h
      PATINVERT equ 005A0049h
      DSTINVERT equ 00550009h
      BLACKNESS equ 00000042h
      WHITENESS equ 00FF0062h
      if (WINVER ge 0500h)
        NOMIRRORBITMAP equ 80000000h
        CAPTUREBLT equ 40000000h
      endif
      MAKEROP4 macro fore, back
        exitm <((((back) shl 8) and 0FF000000h) or (fore))>
      endm
    endif
    GDI_ERROR equ (0FFFFFFFFh)
    if (_WIN32_WINNT ge _WIN32_WINNT_WINXP)
      HGDI_ERROR equ ((0FFFFFFFFh))
    else
      HGDI_ERROR equ (- 1)
    endif
    ERROR_ equ 0
    NULLREGION equ 1
    SIMPLEREGION equ 2
    COMPLEXREGION equ 3
    RGN_ERROR equ <ERROR>
    RGN_AND equ 1
    RGN_OR equ 2
    RGN_XOR equ 3
    RGN_DIFF equ 4
    RGN_COPY equ 5
    RGN_MIN equ <RGN_AND>
    RGN_MAX equ <RGN_COPY>
    BLACKONWHITE equ 1
    WHITEONBLACK equ 2
    COLORONCOLOR equ 3
    HALFTONE equ 4
    MAXSTRETCHBLTMODE equ 4
    if (WINVER ge 0400h)
      STRETCH_ANDSCANS equ <BLACKONWHITE>
      STRETCH_ORSCANS equ <WHITEONBLACK>
      STRETCH_DELETESCANS equ <COLORONCOLOR>
      STRETCH_HALFTONE equ <HALFTONE>
    endif
    ALTERNATE equ 1
    WINDING equ 2
    POLYFILL_LAST equ 2
    if (WINVER ge 0500h)
      LAYOUT_RTL equ 00000001h
      LAYOUT_BTT equ 00000002h
      LAYOUT_VBH equ 00000004h
      LAYOUT_ORIENTATIONMASK equ <(LAYOUT_RTL or LAYOUT_BTT or LAYOUT_VBH)>
      LAYOUT_BITMAPORIENTATIONPRESERVED equ 00000008h
    endif
    TA_NOUPDATECP equ 0
    TA_UPDATECP equ 1
    TA_LEFT equ 0
    TA_RIGHT equ 2
    TA_CENTER equ 6
    TA_TOP equ 0
    TA_BOTTOM equ 8
    TA_BASELINE equ 24
    if (WINVER ge 0400h)
      TA_RTLREADING equ 256
      TA_MASK equ <(TA_BASELINE + TA_CENTER + TA_UPDATECP + TA_RTLREADING)>
    else
      TA_MASK equ <(TA_BASELINE + TA_CENTER + TA_UPDATECP)>
    endif
    VTA_BASELINE equ <TA_BASELINE>
    VTA_LEFT equ <TA_BOTTOM>
    VTA_RIGHT equ <TA_TOP>
    VTA_CENTER equ <TA_CENTER>
    VTA_BOTTOM equ <TA_RIGHT>
    VTA_TOP equ <TA_LEFT>
    ETO_OPAQUE equ 0002h
    ETO_CLIPPED equ 0004h
    if (WINVER ge 0400h)
      ETO_GLYPH_INDEX equ 0010h
      ETO_RTLREADING equ 0080h
      ETO_NUMERICSLOCAL equ 0400h
      ETO_NUMERICSLATIN equ 0800h
      ETO_IGNORELANGUAGE equ 1000h
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN2K)
      ETO_PDY equ 2000h
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_LONGHORN)
      ETO_REVERSE_INDEX_MAP equ 10000h
    endif
    ASPECT_FILTERING equ 0001h
    DCB_RESET equ 0001h
    DCB_ACCUMULATE equ 0002h
    DCB_DIRTY equ <DCB_ACCUMULATE>
    DCB_SET equ <(DCB_RESET or DCB_ACCUMULATE)>
    DCB_ENABLE equ 0004h
    DCB_DISABLE equ 0008h
    ifndef NOMETAFILE
      META_SETBKCOLOR equ 0201h
      META_SETBKMODE equ 0102h
      META_SETMAPMODE equ 0103h
      META_SETROP2 equ 0104h
      META_SETRELABS equ 0105h
      META_SETPOLYFILLMODE equ 0106h
      META_SETSTRETCHBLTMODE equ 0107h
      META_SETTEXTCHAREXTRA equ 0108h
      META_SETTEXTCOLOR equ 0209h
      META_SETTEXTJUSTIFICATION equ 020Ah
      META_SETWINDOWORG equ 020Bh
      META_SETWINDOWEXT equ 020Ch
      META_SETVIEWPORTORG equ 020Dh
      META_SETVIEWPORTEXT equ 020Eh
      META_OFFSETWINDOWORG equ 020Fh
      META_SCALEWINDOWEXT equ 0410h
      META_OFFSETVIEWPORTORG equ 0211h
      META_SCALEVIEWPORTEXT equ 0412h
      META_LINETO equ 0213h
      META_MOVETO equ 0214h
      META_EXCLUDECLIPRECT equ 0415h
      META_INTERSECTCLIPRECT equ 0416h
      META_ARC equ 0817h
      META_ELLIPSE equ 0418h
      META_FLOODFILL equ 0419h
      META_PIE equ 081Ah
      META_RECTANGLE equ 041Bh
      META_ROUNDRECT equ 061Ch
      META_PATBLT equ 061Dh
      META_SAVEDC equ 001Eh
      META_SETPIXEL equ 041Fh
      META_OFFSETCLIPRGN equ 0220h
      META_TEXTOUT equ 0521h
      META_BITBLT equ 0922h
      META_STRETCHBLT equ 0B23h
      META_POLYGON equ 0324h
      META_POLYLINE equ 0325h
      META_ESCAPE equ 0626h
      META_RESTOREDC equ 0127h
      META_FILLREGION equ 0228h
      META_FRAMEREGION equ 0429h
      META_INVERTREGION equ 012Ah
      META_PAINTREGION equ 012Bh
      META_SELECTCLIPREGION equ 012Ch
      META_SELECTOBJECT equ 012Dh
      META_SETTEXTALIGN equ 012Eh
      META_CHORD equ 0830h
      META_SETMAPPERFLAGS equ 0231h
      META_EXTTEXTOUT equ 0a32h
      META_SETDIBTODEV equ 0d33h
      META_SELECTPALETTE equ 0234h
      META_REALIZEPALETTE equ 0035h
      META_ANIMATEPALETTE equ 0436h
      META_SETPALENTRIES equ 0037h
      META_POLYPOLYGON equ 0538h
      META_RESIZEPALETTE equ 0139h
      META_DIBBITBLT equ 0940h
      META_DIBSTRETCHBLT equ 0b41h
      META_DIBCREATEPATTERNBRUSH equ 0142h
      META_STRETCHDIB equ 0f43h
      META_EXTFLOODFILL equ 0548h
      if (WINVER ge 0500h)
        META_SETLAYOUT equ 0149h
      endif
      META_DELETEOBJECT equ 01f0h
      META_CREATEPALETTE equ 00f7h
      META_CREATEPATTERNBRUSH equ 01F9h
      META_CREATEPENINDIRECT equ 02FAh
      META_CREATEFONTINDIRECT equ 02FBh
      META_CREATEBRUSHINDIRECT equ 02FCh
      META_CREATEREGION equ 06FFh
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        if (WINVER ge 0400h)
          DRAWPATRECT struct
            ptPosition POINT <>
            ptSize POINT <>
            wStyle WORD ?
            wPattern WORD ?
          DRAWPATRECT ends
          _DRAWPATRECT typedef DRAWPATRECT
          PDRAWPATRECT typedef ptr DRAWPATRECT
        endif
      endif
    endif
    NEWFRAME equ 1
    ABORTDOC equ 2
    NEXTBAND equ 3
    SETCOLORTABLE equ 4
    GETCOLORTABLE equ 5
    FLUSHOUTPUT equ 6
    DRAFTMODE equ 7
    QUERYESCSUPPORT equ 8
    SETABORTPROC equ 9
    STARTDOC equ 10
    ENDDOC equ 11
    GETPHYSPAGESIZE equ 12
    GETPRINTINGOFFSET equ 13
    GETSCALINGFACTOR equ 14
    MFCOMMENT equ 15
    GETPENWIDTH equ 16
    SETCOPYCOUNT equ 17
    SELECTPAPERSOURCE equ 18
    DEVICEDATA equ 19
    PASSTHROUGH equ 19
    GETTECHNOLGY equ 20
    GETTECHNOLOGY equ 20
    SETLINECAP equ 21
    SETLINEJOIN equ 22
    SETMITERLIMIT equ 23
    BANDINFO equ 24
    DRAWPATTERNRECT equ 25
    GETVECTORPENSIZE equ 26
    GETVECTORBRUSHSIZE equ 27
    ENABLEDUPLEX equ 28
    GETSETPAPERBINS equ 29
    GETSETPRINTORIENT equ 30
    ENUMPAPERBINS equ 31
    SETDIBSCALING equ 32
    EPSPRINTING equ 33
    ENUMPAPERMETRICS equ 34
    GETSETPAPERMETRICS equ 35
    POSTSCRIPT_DATA equ 37
    POSTSCRIPT_IGNORE equ 38
    MOUSETRAILS equ 39
    GETDEVICEUNITS equ 42
    GETEXTENDEDTEXTMETRICS equ 256
    GETEXTENTTABLE equ 257
    GETPAIRKERNTABLE equ 258
    GETTRACKKERNTABLE equ 259
    EXTTEXTOUT equ 512
    GETFACENAME equ 513
    DOWNLOADFACE equ 514
    ENABLERELATIVEWIDTHS equ 768
    ENABLEPAIRKERNING equ 769
    SETKERNTRACK equ 770
    SETALLJUSTVALUES equ 771
    SETCHARSET equ 772
    STRETCHBLT equ 2048
    METAFILE_DRIVER equ 2049
    GETSETSCREENPARAMS equ 3072
    QUERYDIBSUPPORT equ 3073
    BEGIN_PATH equ 4096
    CLIP_TO_PATH equ 4097
    END_PATH equ 4098
    EXT_DEVICE_CAPS equ 4099
    RESTORE_CTM equ 4100
    SAVE_CTM equ 4101
    SET_ARC_DIRECTION equ 4102
    SET_BACKGROUND_COLOR equ 4103
    SET_POLY_MODE equ 4104
    SET_SCREEN_ANGLE equ 4105
    SET_SPREAD equ 4106
    TRANSFORM_CTM equ 4107
    SET_CLIP_BOX equ 4108
    SET_BOUNDS equ 4109
    SET_MIRROR_MODE equ 4110
    OPENCHANNEL equ 4110
    DOWNLOADHEADER equ 4111
    CLOSECHANNEL equ 4112
    POSTSCRIPT_PASSTHROUGH equ 4115
    ENCAPSULATED_POSTSCRIPT equ 4116
    POSTSCRIPT_IDENTIFY equ 4117
    POSTSCRIPT_INJECTION equ 4118
    CHECKJPEGFORMAT equ 4119
    CHECKPNGFORMAT equ 4120
    GET_PS_FEATURESETTING equ 4121
    GDIPLUS_TS_QUERYVER equ 4122
    GDIPLUS_TS_RECORD equ 4123
    if (_WIN32_WINNT ge _WIN32_WINNT_LONGHORN)
      MILCORE_TS_QUERYVER_RESULT_FALSE equ 0h
      MILCORE_TS_QUERYVER_RESULT_TRUE equ 7FFFFFFFh
    endif
    SPCLPASSTHROUGH2 equ 4568
    PSIDENT_GDICENTRIC equ 0
    PSIDENT_PSCENTRIC equ 1
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      PSINJECTDATA struct
        DataBytes DWORD ?
        InjectionPoint WORD ?
        PageNumber WORD ?
      PSINJECTDATA ends
      _PSINJECTDATA typedef PSINJECTDATA
      PPSINJECTDATA typedef ptr PSINJECTDATA
    endif
    PSINJECT_BEGINSTREAM equ 1
    PSINJECT_PSADOBE equ 2
    PSINJECT_PAGESATEND equ 3
    PSINJECT_PAGES equ 4
    PSINJECT_DOCNEEDEDRES equ 5
    PSINJECT_DOCSUPPLIEDRES equ 6
    PSINJECT_PAGEORDER equ 7
    PSINJECT_ORIENTATION equ 8
    PSINJECT_BOUNDINGBOX equ 9
    PSINJECT_DOCUMENTPROCESSCOLORS equ 10
    PSINJECT_COMMENTS equ 11
    PSINJECT_BEGINDEFAULTS equ 12
    PSINJECT_ENDDEFAULTS equ 13
    PSINJECT_BEGINPROLOG equ 14
    PSINJECT_ENDPROLOG equ 15
    PSINJECT_BEGINSETUP equ 16
    PSINJECT_ENDSETUP equ 17
    PSINJECT_TRAILER equ 18
    PSINJECT_EOF equ 19
    PSINJECT_ENDSTREAM equ 20
    PSINJECT_DOCUMENTPROCESSCOLORSATEND equ 21
    PSINJECT_PAGENUMBER equ 100
    PSINJECT_BEGINPAGESETUP equ 101
    PSINJECT_ENDPAGESETUP equ 102
    PSINJECT_PAGETRAILER equ 103
    PSINJECT_PLATECOLOR equ 104
    PSINJECT_SHOWPAGE equ 105
    PSINJECT_PAGEBBOX equ 106
    PSINJECT_ENDPAGECOMMENTS equ 107
    PSINJECT_VMSAVE equ 200
    PSINJECT_VMRESTORE equ 201
    PSINJECT_DLFONT equ 0ddddddddh
    FEATURESETTING_NUP equ 0
    FEATURESETTING_OUTPUT equ 1
    FEATURESETTING_PSLEVEL equ 2
    FEATURESETTING_CUSTPAPER equ 3
    FEATURESETTING_MIRROR equ 4
    FEATURESETTING_NEGATIVE equ 5
    FEATURESETTING_PROTOCOL equ 6
    if (_WIN32_WINNT ge _WIN32_WINNT_WINXP)
      FEATURESETTING_PRIVATE_BEGIN equ 1000h
      FEATURESETTING_PRIVATE_END equ 1FFFh
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      PSFEATURE_OUTPUT struct
        bPageIndependent BOOL ?
        bSetPageDevice BOOL ?
      PSFEATURE_OUTPUT ends
      _PSFEATURE_OUTPUT typedef PSFEATURE_OUTPUT
      PPSFEATURE_OUTPUT typedef ptr PSFEATURE_OUTPUT
      PSFEATURE_CUSTPAPER struct
        lOrientation LONG ?
        lWidth LONG ?
        lHeight LONG ?
        lWidthOffset LONG ?
        lHeightOffset LONG ?
      PSFEATURE_CUSTPAPER ends
      _PSFEATURE_CUSTPAPER typedef PSFEATURE_CUSTPAPER
      PPSFEATURE_CUSTPAPER typedef ptr PSFEATURE_CUSTPAPER
    endif
    PSPROTOCOL_ASCII equ 0
    PSPROTOCOL_BCP equ 1
    PSPROTOCOL_TBCP equ 2
    PSPROTOCOL_BINARY equ 3
    QDI_SETDIBITS equ 1
    QDI_GETDIBITS equ 2
    QDI_DIBTOSCREEN equ 4
    QDI_STRETCHDIB equ 8
    SP_NOTREPORTED equ 4000h
    SP_ERROR equ (- 1)
    SP_APPABORT equ (- 2)
    SP_USERABORT equ (- 3)
    SP_OUTOFDISK equ (- 4)
    SP_OUTOFMEMORY equ (- 5)
    PR_JOBSTATUS equ 0000h
    OBJ_PEN equ 1
    OBJ_BRUSH equ 2
    OBJ_DC equ 3
    OBJ_METADC equ 4
    OBJ_PAL equ 5
    OBJ_FONT equ 6
    OBJ_BITMAP equ 7
    OBJ_REGION equ 8
    OBJ_METAFILE equ 9
    OBJ_MEMDC equ 10
    OBJ_EXTPEN equ 11
    OBJ_ENHMETADC equ 12
    OBJ_ENHMETAFILE equ 13
    OBJ_COLORSPACE equ 14
    GDI_OBJ_LAST equ <OBJ_COLORSPACE>
    GDI_MIN_OBJ_TYPE equ <OBJ_PEN>
    GDI_MAX_OBJ_TYPE equ <GDI_OBJ_LAST>
    MWT_IDENTITY equ 1
    MWT_LEFTMULTIPLY equ 2
    MWT_RIGHTMULTIPLY equ 3
    MWT_MIN equ <MWT_IDENTITY>
    MWT_MAX equ <MWT_RIGHTMULTIPLY>
    _XFORM_ equ <>
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      XFORM struct
        eM11 FLOAT ?
        eM12 FLOAT ?
        eM21 FLOAT ?
        eM22 FLOAT ?
        eDx_ FLOAT ?
        eDy FLOAT ?
      XFORM ends
      tagXFORM typedef XFORM
      PXFORM typedef ptr XFORM
      LPXFORM typedef ptr XFORM
      BITMAP struct
        bmType LONG ?
        bmWidth LONG ?
        bmHeight LONG ?
        bmWidthBytes LONG ?
        bmPlanes WORD ?
        bmBitsPixel WORD ?
        bmBits LPVOID ?
      BITMAP ends
      tagBITMAP typedef BITMAP
      PBITMAP typedef ptr BITMAP
      NPBITMAP typedef ptr BITMAP
      LPBITMAP typedef ptr BITMAP
    endif
    include pshpack1.inc
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      RGBTRIPLE struct
        rgbtBlue BYTE ?
        rgbtGreen BYTE ?
        rgbtRed BYTE ?
      RGBTRIPLE ends
      tagRGBTRIPLE typedef RGBTRIPLE
      PRGBTRIPLE typedef ptr RGBTRIPLE
      NPRGBTRIPLE typedef ptr RGBTRIPLE
      LPRGBTRIPLE typedef ptr RGBTRIPLE
    endif
    include poppack.inc
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      RGBQUAD struct
        rgbBlue BYTE ?
        rgbGreen BYTE ?
        rgbRed BYTE ?
        rgbReserved BYTE ?
      RGBQUAD ends
      tagRGBQUAD typedef RGBQUAD
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      LPRGBQUAD typedef ptr RGBQUAD
    endif
    if (WINVER ge 0400h)
      CS_ENABLE equ 00000001h
      CS_DISABLE equ 00000002h
      CS_DELETE_TRANSFORM equ 00000003h
      LCS_SIGNATURE equ <'PSOC'>
      LCS_sRGB equ <'sRGB'>
      LCS_WINDOWS_COLOR_SPACE equ <'Win '>
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        LCSCSTYPE typedef LONG
        LCS_CALIBRATED_RGB equ 00000000h
        LCSGAMUTMATCH typedef LONG
        LCS_GM_BUSINESS equ 00000001h
        LCS_GM_GRAPHICS equ 00000002h
        LCS_GM_IMAGES equ 00000004h
        LCS_GM_ABS_COLORIMETRIC equ 00000008h
        CM_OUT_OF_GAMUT equ 255
        CM_IN_GAMUT equ 0
        ICM_ADDPROFILE equ 1
        ICM_DELETEPROFILE equ 2
        ICM_QUERYPROFILE equ 3
        ICM_SETDEFAULTPROFILE equ 4
        ICM_REGISTERICMATCHER equ 5
        ICM_UNREGISTERICMATCHER equ 6
        ICM_QUERYMATCH equ 7
        GetKValue macro cmyk
          exitm <((cmyk))>
        endm
        GetYValue macro cmyk
          exitm <(((cmyk) shr 8))>
        endm
        GetMValue macro cmyk
          exitm <(((cmyk) shr 16))>
        endm
        GetCValue macro cmyk
          exitm <(((cmyk) shr 24))>
        endm
        CMYK macro c_, m, y, k
          exitm <(((((k) or (((y)) shl 8)) or (((m)) shl 16)) or (((c_)) shl 24)))>
        endm
        FXPT16DOT16 typedef SDWORD
        LPFXPT16DOT16 typedef ptr SDWORD
        FXPT2DOT30 typedef SDWORD
        LPFXPT2DOT30 typedef ptr SDWORD
        CIEXYZ struct
          ciexyzX FXPT2DOT30 ?
          ciexyzY FXPT2DOT30 ?
          ciexyzZ FXPT2DOT30 ?
        CIEXYZ ends
        tagCIEXYZ typedef CIEXYZ
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        LPCIEXYZ typedef ptr CIEXYZ
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        CIEXYZTRIPLE struct
          ciexyzRed CIEXYZ <>
          ciexyzGreen CIEXYZ <>
          ciexyzBlue CIEXYZ <>
        CIEXYZTRIPLE ends
        tagICEXYZTRIPLE typedef CIEXYZTRIPLE
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        LPCIEXYZTRIPLE typedef ptr CIEXYZTRIPLE
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        LOGCOLORSPACEA struct
          lcsSignature DWORD ?
          lcsVersion DWORD ?
          lcsSize DWORD ?
          lcsCSType LCSCSTYPE ?
          lcsIntent LCSGAMUTMATCH ?
          lcsEndpoints CIEXYZTRIPLE <>
          lcsGammaRed DWORD ?
          lcsGammaGreen DWORD ?
          lcsGammaBlue DWORD ?
          lcsFilename CHAR MAX_PATH dup (?)
        LOGCOLORSPACEA ends
        tagLOGCOLORSPACEA typedef LOGCOLORSPACEA
        LPLOGCOLORSPACEA typedef ptr LOGCOLORSPACEA
        LOGCOLORSPACEW struct
          lcsSignature DWORD ?
          lcsVersion DWORD ?
          lcsSize DWORD ?
          lcsCSType LCSCSTYPE ?
          lcsIntent LCSGAMUTMATCH ?
          lcsEndpoints CIEXYZTRIPLE <>
          lcsGammaRed DWORD ?
          lcsGammaGreen DWORD ?
          lcsGammaBlue DWORD ?
          lcsFilename WCHAR MAX_PATH dup (?)
        LOGCOLORSPACEW ends
        tagLOGCOLORSPACEW typedef LOGCOLORSPACEW
        LPLOGCOLORSPACEW typedef ptr LOGCOLORSPACEW
        ifdef UNICODE
          LOGCOLORSPACE typedef LOGCOLORSPACEW
          LPLOGCOLORSPACE typedef LPLOGCOLORSPACEW
        else
          LOGCOLORSPACE typedef LOGCOLORSPACEA
          LPLOGCOLORSPACE typedef LPLOGCOLORSPACEA
        endif
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      BITMAPCOREHEADER struct
        bcSize DWORD ?
        bcWidth WORD ?
        bcHeight WORD ?
        bcPlanes WORD ?
        bcBitCount WORD ?
      BITMAPCOREHEADER ends
      tagBITMAPCOREHEADER typedef BITMAPCOREHEADER
      LPBITMAPCOREHEADER typedef ptr BITMAPCOREHEADER
      PBITMAPCOREHEADER typedef ptr BITMAPCOREHEADER
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      BITMAPINFOHEADER struct
        biSize DWORD ?
        biWidth LONG ?
        biHeight LONG ?
        biPlanes WORD ?
        biBitCount WORD ?
        biCompression DWORD ?
        biSizeImage DWORD ?
        biXPelsPerMeter LONG ?
        biYPelsPerMeter LONG ?
        biClrUsed DWORD ?
        biClrImportant DWORD ?
      BITMAPINFOHEADER ends
      tagBITMAPINFOHEADER typedef BITMAPINFOHEADER
      LPBITMAPINFOHEADER typedef ptr BITMAPINFOHEADER
      PBITMAPINFOHEADER typedef ptr BITMAPINFOHEADER
    endif
    if (WINVER ge 0400h)
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        BITMAPV4HEADER struct
          bV4Size DWORD ?
          bV4Width LONG ?
          bV4Height LONG ?
          bV4Planes WORD ?
          bV4BitCount WORD ?
          bV4V4Compression DWORD ?
          bV4SizeImage DWORD ?
          bV4XPelsPerMeter LONG ?
          bV4YPelsPerMeter LONG ?
          bV4ClrUsed DWORD ?
          bV4ClrImportant DWORD ?
          bV4RedMask DWORD ?
          bV4GreenMask DWORD ?
          bV4BlueMask DWORD ?
          bV4AlphaMask DWORD ?
          bV4CSType DWORD ?
          bV4Endpoints CIEXYZTRIPLE <>
          bV4GammaRed DWORD ?
          bV4GammaGreen DWORD ?
          bV4GammaBlue DWORD ?
        BITMAPV4HEADER ends
        LPBITMAPV4HEADER typedef ptr BITMAPV4HEADER
        PBITMAPV4HEADER typedef ptr BITMAPV4HEADER
      endif
    endif
    if (WINVER ge 0500h)
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        BITMAPV5HEADER struct
          bV5Size DWORD ?
          bV5Width LONG ?
          bV5Height LONG ?
          bV5Planes WORD ?
          bV5BitCount WORD ?
          bV5Compression DWORD ?
          bV5SizeImage DWORD ?
          bV5XPelsPerMeter LONG ?
          bV5YPelsPerMeter LONG ?
          bV5ClrUsed DWORD ?
          bV5ClrImportant DWORD ?
          bV5RedMask DWORD ?
          bV5GreenMask DWORD ?
          bV5BlueMask DWORD ?
          bV5AlphaMask DWORD ?
          bV5CSType DWORD ?
          bV5Endpoints CIEXYZTRIPLE <>
          bV5GammaRed DWORD ?
          bV5GammaGreen DWORD ?
          bV5GammaBlue DWORD ?
          bV5Intent DWORD ?
          bV5ProfileData DWORD ?
          bV5ProfileSize DWORD ?
          bV5Reserved DWORD ?
        BITMAPV5HEADER ends
        LPBITMAPV5HEADER typedef ptr BITMAPV5HEADER
        PBITMAPV5HEADER typedef ptr BITMAPV5HEADER
      endif
      PROFILE_LINKED equ <'LINK'>
      PROFILE_EMBEDDED equ <'MBED'>
    endif
    BI_RGB equ 0
    BI_RLE8 equ 1
    BI_RLE4 equ 2
    BI_BITFIELDS equ 3
    BI_JPEG equ 4
    BI_PNG equ 5
    if (_WIN32_WINNT ge _WIN32_WINNT_NT4)
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      BITMAPINFO struct
        bmiHeader BITMAPINFOHEADER <>
        bmiColors RGBQUAD 1 dup (<>)
      BITMAPINFO ends
      tagBITMAPINFO typedef BITMAPINFO
      LPBITMAPINFO typedef ptr BITMAPINFO
      PBITMAPINFO typedef ptr BITMAPINFO
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      BITMAPCOREINFO struct
        bmciHeader BITMAPCOREHEADER <>
        bmciColors RGBTRIPLE 1 dup (<>)
      BITMAPCOREINFO ends
      tagBITMAPCOREINFO typedef BITMAPCOREINFO
      LPBITMAPCOREINFO typedef ptr BITMAPCOREINFO
      PBITMAPCOREINFO typedef ptr BITMAPCOREINFO
    endif
    include pshpack2.inc
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      BITMAPFILEHEADER struct 2
        bfType WORD ?
        bfSize DWORD ?
        bfReserved1 WORD ?
        bfReserved2 WORD ?
        bfOffBits DWORD ?
      BITMAPFILEHEADER ends
      tagBITMAPFILEHEADER typedef BITMAPFILEHEADER
      LPBITMAPFILEHEADER typedef ptr BITMAPFILEHEADER
      PBITMAPFILEHEADER typedef ptr BITMAPFILEHEADER
    endif
    include poppack.inc
    MAKEPOINTS macro l
      exitm <(* ((POINTS FAR *) and (l)))>
    endm
    if (WINVER ge 0400h)
      ifndef NOFONTSIG
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          FONTSIGNATURE struct
            fsUsb DWORD 4 dup (?)
            fsCsb DWORD 2 dup (?)
          FONTSIGNATURE ends
          tagFONTSIGNATURE typedef FONTSIGNATURE
          PFONTSIGNATURE typedef ptr FONTSIGNATURE
          LPFONTSIGNATURE typedef ptr FONTSIGNATURE
        endif
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
          CHARSETINFO struct
            ciCharset UINT ?
            ciACP UINT ?
            fs_ FONTSIGNATURE <>
          CHARSETINFO ends
          tagCHARSETINFO typedef CHARSETINFO
          PCHARSETINFO typedef ptr CHARSETINFO
          NPCHARSETINFO typedef ptr CHARSETINFO
          LPCHARSETINFO typedef ptr CHARSETINFO
        endif
        TCI_SRCCHARSET equ 1
        TCI_SRCCODEPAGE equ 2
        TCI_SRCFONTSIG equ 3
        if (_WIN32_WINNT ge _WIN32_WINNT_WINXP)
          TCI_SRCLOCALE equ 1000h
        endif
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          LOCALESIGNATURE struct
            lsUsb DWORD 4 dup (?)
            lsCsbDefault DWORD 2 dup (?)
            lsCsbSupported DWORD 2 dup (?)
          LOCALESIGNATURE ends
          tagLOCALESIGNATURE typedef LOCALESIGNATURE
          PLOCALESIGNATURE typedef ptr LOCALESIGNATURE
          LPLOCALESIGNATURE typedef ptr LOCALESIGNATURE
        endif
      endif
    endif
    ifndef NOMETAFILE
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        HANDLETABLE struct
          objectHandle HGDIOBJ 1 dup (?)
        HANDLETABLE ends
        tagHANDLETABLE typedef HANDLETABLE
        PHANDLETABLE typedef ptr HANDLETABLE
        LPHANDLETABLE typedef ptr HANDLETABLE
        METARECORD struct
          rdSize DWORD ?
          rdFunction WORD ?
          rdParm WORD 1 dup (?)
        METARECORD ends
        tagMETARECORD typedef METARECORD
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        PMETARECORD typedef ptr tagMETARECORD
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        LPMETARECORD typedef ptr tagMETARECORD
        METAFILEPICT struct
          mm_ LONG ?
          xExt LONG ?
          yExt LONG ?
          hMF HMETAFILE ?
        METAFILEPICT ends
        tagMETAFILEPICT typedef METAFILEPICT
        LPMETAFILEPICT typedef ptr METAFILEPICT
      endif
      include pshpack2.inc
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        METAHEADER struct
          mtType WORD ?
          mtHeaderSize WORD ?
          mtVersion WORD ?
          mtSize DWORD ?
          mtNoObjects WORD ?
          mtMaxRecord DWORD ?
          mtNoParameters WORD ?
        METAHEADER ends
        tagMETAHEADER typedef METAHEADER
        PMETAHEADER typedef ptr tagMETAHEADER
        LPMETAHEADER typedef ptr tagMETAHEADER
      endif
      include poppack.inc
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        ENHMETARECORD struct
          iType DWORD ?
          nSize DWORD ?
          dParm DWORD 1 dup (?)
        ENHMETARECORD ends
        tagENHMETARECORD typedef ENHMETARECORD
        PENHMETARECORD typedef ptr ENHMETARECORD
        LPENHMETARECORD typedef ptr ENHMETARECORD
        ENHMETAHEADER struct
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
          if (WINVER ge 0400h)
            cbPixelFormat DWORD ?
            offPixelFormat DWORD ?
            bOpenGL DWORD ?
          endif
          if (WINVER ge 0500h)
            szlMicrometers SIZEL <>
          endif
        ENHMETAHEADER ends
        tagENHMETAHEADER typedef ENHMETAHEADER
        PENHMETAHEADER typedef ptr ENHMETAHEADER
        LPENHMETAHEADER typedef ptr ENHMETAHEADER
      endif
    endif
    ifndef NOTEXTMETRIC
      TMPF_FIXED_PITCH equ 01h
      TMPF_VECTOR equ 02h
      TMPF_DEVICE equ 08h
      TMPF_TRUETYPE equ 04h
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        ifdef UNICODE
          BCHAR typedef WCHAR
        else
          BCHAR typedef BYTE
        endif
      endif
      ifndef _TEXTMETRIC_DEFINED
        _TEXTMETRIC_DEFINED equ <>
        include pshpack4.inc
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
          TEXTMETRICA struct 4
            tmHeight LONG ?
            tmAscent LONG ?
            tmDescent LONG ?
            tmInternalLeading LONG ?
            tmExternalLeading LONG ?
            tmAveCharWidth LONG ?
            tmMaxCharWidth LONG ?
            tmWeight LONG ?
            tmOverhang LONG ?
            tmDigitizedAspectX LONG ?
            tmDigitizedAspectY LONG ?
            tmFirstChar BYTE ?
            tmLastChar BYTE ?
            tmDefaultChar BYTE ?
            tmBreakChar BYTE ?
            tmItalic BYTE ?
            tmUnderlined BYTE ?
            tmStruckOut BYTE ?
            tmPitchAndFamily BYTE ?
            tmCharSet BYTE ?
          TEXTMETRICA ends
          tagTEXTMETRICA typedef TEXTMETRICA
          PTEXTMETRICA typedef ptr TEXTMETRICA
          NPTEXTMETRICA typedef ptr TEXTMETRICA
          LPTEXTMETRICA typedef ptr TEXTMETRICA
          TEXTMETRICW struct 4
            tmHeight LONG ?
            tmAscent LONG ?
            tmDescent LONG ?
            tmInternalLeading LONG ?
            tmExternalLeading LONG ?
            tmAveCharWidth LONG ?
            tmMaxCharWidth LONG ?
            tmWeight LONG ?
            tmOverhang LONG ?
            tmDigitizedAspectX LONG ?
            tmDigitizedAspectY LONG ?
            tmFirstChar WCHAR ?
            tmLastChar WCHAR ?
            tmDefaultChar WCHAR ?
            tmBreakChar WCHAR ?
            tmItalic BYTE ?
            tmUnderlined BYTE ?
            tmStruckOut BYTE ?
            tmPitchAndFamily BYTE ?
            tmCharSet BYTE ?
          TEXTMETRICW ends
          tagTEXTMETRICW typedef TEXTMETRICW
          PTEXTMETRICW typedef ptr TEXTMETRICW
          NPTEXTMETRICW typedef ptr TEXTMETRICW
          LPTEXTMETRICW typedef ptr TEXTMETRICW
          ifdef UNICODE
            TEXTMETRIC typedef TEXTMETRICW
            PTEXTMETRIC typedef PTEXTMETRICW
            NPTEXTMETRIC typedef NPTEXTMETRICW
            LPTEXTMETRIC typedef LPTEXTMETRICW
          else
            TEXTMETRIC typedef TEXTMETRICA
            PTEXTMETRIC typedef PTEXTMETRICA
            NPTEXTMETRIC typedef NPTEXTMETRICA
            LPTEXTMETRIC typedef LPTEXTMETRICA
          endif
        endif
        include poppack.inc
      endif
      NTM_REGULAR equ 00000040h
      NTM_BOLD equ 00000020h
      NTM_ITALIC equ 00000001h
      NTM_NONNEGATIVE_AC equ 00010000h
      NTM_PS_OPENTYPE equ 00020000h
      NTM_TT_OPENTYPE equ 00040000h
      NTM_MULTIPLEMASTER equ 00080000h
      NTM_TYPE1 equ 00100000h
      NTM_DSIG equ 00200000h
      include pshpack4.inc
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        NEWTEXTMETRICA struct 4
          tmHeight LONG ?
          tmAscent LONG ?
          tmDescent LONG ?
          tmInternalLeading LONG ?
          tmExternalLeading LONG ?
          tmAveCharWidth LONG ?
          tmMaxCharWidth LONG ?
          tmWeight LONG ?
          tmOverhang LONG ?
          tmDigitizedAspectX LONG ?
          tmDigitizedAspectY LONG ?
          tmFirstChar BYTE ?
          tmLastChar BYTE ?
          tmDefaultChar BYTE ?
          tmBreakChar BYTE ?
          tmItalic BYTE ?
          tmUnderlined BYTE ?
          tmStruckOut BYTE ?
          tmPitchAndFamily BYTE ?
          tmCharSet BYTE ?
          ntmFlags DWORD ?
          ntmSizeEM UINT ?
          ntmCellHeight UINT ?
          ntmAvgWidth UINT ?
        NEWTEXTMETRICA ends
        tagNEWTEXTMETRICA typedef NEWTEXTMETRICA
        PNEWTEXTMETRICA typedef ptr NEWTEXTMETRICA
        NPNEWTEXTMETRICA typedef ptr NEWTEXTMETRICA
        LPNEWTEXTMETRICA typedef ptr NEWTEXTMETRICA
        NEWTEXTMETRICW struct 4
          tmHeight LONG ?
          tmAscent LONG ?
          tmDescent LONG ?
          tmInternalLeading LONG ?
          tmExternalLeading LONG ?
          tmAveCharWidth LONG ?
          tmMaxCharWidth LONG ?
          tmWeight LONG ?
          tmOverhang LONG ?
          tmDigitizedAspectX LONG ?
          tmDigitizedAspectY LONG ?
          tmFirstChar WCHAR ?
          tmLastChar WCHAR ?
          tmDefaultChar WCHAR ?
          tmBreakChar WCHAR ?
          tmItalic BYTE ?
          tmUnderlined BYTE ?
          tmStruckOut BYTE ?
          tmPitchAndFamily BYTE ?
          tmCharSet BYTE ?
          ntmFlags DWORD ?
          ntmSizeEM UINT ?
          ntmCellHeight UINT ?
          ntmAvgWidth UINT ?
        NEWTEXTMETRICW ends
        tagNEWTEXTMETRICW typedef NEWTEXTMETRICW
        PNEWTEXTMETRICW typedef ptr NEWTEXTMETRICW
        NPNEWTEXTMETRICW typedef ptr NEWTEXTMETRICW
        LPNEWTEXTMETRICW typedef ptr NEWTEXTMETRICW
        ifdef UNICODE
          NEWTEXTMETRIC typedef NEWTEXTMETRICW
          PNEWTEXTMETRIC typedef PNEWTEXTMETRICW
          NPNEWTEXTMETRIC typedef NPNEWTEXTMETRICW
          LPNEWTEXTMETRIC typedef LPNEWTEXTMETRICW
        else
          NEWTEXTMETRIC typedef NEWTEXTMETRICA
          PNEWTEXTMETRIC typedef PNEWTEXTMETRICA
          NPNEWTEXTMETRIC typedef NPNEWTEXTMETRICA
          LPNEWTEXTMETRIC typedef LPNEWTEXTMETRICA
        endif
      endif
      include poppack.inc
      if (WINVER ge 0400h)
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
          NEWTEXTMETRICEXA struct 4
            ntmTm NEWTEXTMETRICA <>
            ntmFontSig FONTSIGNATURE <>
          NEWTEXTMETRICEXA ends
          tagNEWTEXTMETRICEXA typedef NEWTEXTMETRICEXA
          NEWTEXTMETRICEXW struct 4
            ntmTm NEWTEXTMETRICW <>
            ntmFontSig FONTSIGNATURE <>
          NEWTEXTMETRICEXW ends
          tagNEWTEXTMETRICEXW typedef NEWTEXTMETRICEXW
          ifdef UNICODE
            NEWTEXTMETRICEX typedef NEWTEXTMETRICEXW
          else
            NEWTEXTMETRICEX typedef NEWTEXTMETRICEXA
          endif
        endif
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      PELARRAY struct
        paXCount LONG ?
        paYCount LONG ?
        paXExt LONG ?
        paYExt LONG ?
        paRGBs BYTE ?
      PELARRAY ends
      tagPELARRAY typedef PELARRAY
      PPELARRAY typedef ptr PELARRAY
      NPPELARRAY typedef ptr PELARRAY
      LPPELARRAY typedef ptr PELARRAY
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      LOGBRUSH struct
        lbStyle UINT ?
        lbColor COLORREF ?
        lbHatch ULONG_PTR ?
      LOGBRUSH ends
      tagLOGBRUSH typedef LOGBRUSH
      PLOGBRUSH typedef ptr LOGBRUSH
      NPLOGBRUSH typedef ptr LOGBRUSH
      LPLOGBRUSH typedef ptr LOGBRUSH
      LOGBRUSH32 struct
        lbStyle UINT ?
        lbColor COLORREF ?
        lbHatch ULONG ?
      LOGBRUSH32 ends
      tagLOGBRUSH32 typedef LOGBRUSH32
      PLOGBRUSH32 typedef ptr LOGBRUSH32
      NPLOGBRUSH32 typedef ptr LOGBRUSH32
      LPLOGBRUSH32 typedef ptr LOGBRUSH32
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      PATTERN typedef LOGBRUSH
      PPATTERN typedef ptr PATTERN
      NPPATTERN typedef ptr PATTERN
      LPPATTERN typedef ptr PATTERN
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      LOGPEN struct
        lopnStyle UINT ?
        lopnWidth POINT <>
        lopnColor COLORREF ?
      LOGPEN ends
      tagLOGPEN typedef LOGPEN
      PLOGPEN typedef ptr LOGPEN
      NPLOGPEN typedef ptr LOGPEN
      LPLOGPEN typedef ptr LOGPEN
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      EXTLOGPEN struct
        elpPenStyle DWORD ?
        elpWidth DWORD ?
        elpBrushStyle UINT ?
        elpColor COLORREF ?
        elpHatch ULONG_PTR ?
        elpNumEntries DWORD ?
        elpStyleEntry DWORD 1 dup (?)
      EXTLOGPEN ends
      tagEXTLOGPEN typedef EXTLOGPEN
      PEXTLOGPEN typedef ptr EXTLOGPEN
      NPEXTLOGPEN typedef ptr EXTLOGPEN
      LPEXTLOGPEN typedef ptr EXTLOGPEN
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      EXTLOGPEN32 struct
        elpPenStyle DWORD ?
        elpWidth DWORD ?
        elpBrushStyle UINT ?
        elpColor COLORREF ?
        elpHatch ULONG ?
        elpNumEntries DWORD ?
        elpStyleEntry DWORD 1 dup (?)
      EXTLOGPEN32 ends
      tagEXTLOGPEN32 typedef EXTLOGPEN32
      PEXTLOGPEN32 typedef ptr EXTLOGPEN32
      NPEXTLOGPEN32 typedef ptr EXTLOGPEN32
      LPEXTLOGPEN32 typedef ptr EXTLOGPEN32
      ifndef _PALETTEENTRY_DEFINED
        _PALETTEENTRY_DEFINED equ <>
        PALETTEENTRY struct
          peRed BYTE ?
          peGreen BYTE ?
          peBlue BYTE ?
          peFlags BYTE ?
        PALETTEENTRY ends
        tagPALETTEENTRY typedef PALETTEENTRY
        PPALETTEENTRY typedef ptr PALETTEENTRY
        LPPALETTEENTRY typedef ptr PALETTEENTRY
      endif
      ifndef _LOGPALETTE_DEFINED
        _LOGPALETTE_DEFINED equ <>
        LOGPALETTE struct
          palVersion WORD ?
          palNumEntries WORD ?
          palPalEntry PALETTEENTRY 1 dup (<>)
        LOGPALETTE ends
        tagLOGPALETTE typedef LOGPALETTE
        PLOGPALETTE typedef ptr LOGPALETTE
        NPLOGPALETTE typedef ptr LOGPALETTE
        LPLOGPALETTE typedef ptr LOGPALETTE
      endif
      LF_FACESIZE equ 32
      LOGFONTA struct
        lfHeight LONG ?
        lfWidth LONG ?
        lfEscapement LONG ?
        lfOrientation LONG ?
        lfWeight LONG ?
        lfItalic BYTE ?
        lfUnderline BYTE ?
        lfStrikeOut BYTE ?
        lfCharSet BYTE ?
        lfOutPrecision BYTE ?
        lfClipPrecision BYTE ?
        lfQuality BYTE ?
        lfPitchAndFamily BYTE ?
        lfFaceName CHAR LF_FACESIZE dup (?)
      LOGFONTA ends
      tagLOGFONTA typedef LOGFONTA
      PLOGFONTA typedef ptr LOGFONTA
      NPLOGFONTA typedef ptr LOGFONTA
      LPLOGFONTA typedef ptr LOGFONTA
      LOGFONTW struct
        lfHeight LONG ?
        lfWidth LONG ?
        lfEscapement LONG ?
        lfOrientation LONG ?
        lfWeight LONG ?
        lfItalic BYTE ?
        lfUnderline BYTE ?
        lfStrikeOut BYTE ?
        lfCharSet BYTE ?
        lfOutPrecision BYTE ?
        lfClipPrecision BYTE ?
        lfQuality BYTE ?
        lfPitchAndFamily BYTE ?
        lfFaceName WCHAR LF_FACESIZE dup (?)
      LOGFONTW ends
      tagLOGFONTW typedef LOGFONTW
      PLOGFONTW typedef ptr LOGFONTW
      NPLOGFONTW typedef ptr LOGFONTW
      LPLOGFONTW typedef ptr LOGFONTW
      ifdef UNICODE
        LOGFONT typedef LOGFONTW
        PLOGFONT typedef PLOGFONTW
        NPLOGFONT typedef NPLOGFONTW
        LPLOGFONT typedef LPLOGFONTW
      else
        LOGFONT typedef LOGFONTA
        PLOGFONT typedef PLOGFONTA
        NPLOGFONT typedef NPLOGFONTA
        LPLOGFONT typedef LPLOGFONTA
      endif
    endif
    LF_FULLFACESIZE equ 64
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ENUMLOGFONTA struct
        elfLogFont LOGFONTA <>
        elfFullName BYTE LF_FULLFACESIZE dup (?)
        elfStyle BYTE LF_FACESIZE dup (?)
      ENUMLOGFONTA ends
      tagENUMLOGFONTA typedef ENUMLOGFONTA
      LPENUMLOGFONTA typedef ptr ENUMLOGFONTA
      ENUMLOGFONTW struct
        elfLogFont LOGFONTW <>
        elfFullName WCHAR LF_FULLFACESIZE dup (?)
        elfStyle WCHAR LF_FACESIZE dup (?)
      ENUMLOGFONTW ends
      tagENUMLOGFONTW typedef ENUMLOGFONTW
      LPENUMLOGFONTW typedef ptr ENUMLOGFONTW
      ifdef UNICODE
        ENUMLOGFONT typedef ENUMLOGFONTW
        LPENUMLOGFONT typedef LPENUMLOGFONTW
      else
        ENUMLOGFONT typedef ENUMLOGFONTA
        LPENUMLOGFONT typedef LPENUMLOGFONTA
      endif
      if (WINVER ge 0400h)
        ENUMLOGFONTEXA struct
          elfLogFont LOGFONTA <>
          elfFullName BYTE LF_FULLFACESIZE dup (?)
          elfStyle BYTE LF_FACESIZE dup (?)
          elfScript BYTE LF_FACESIZE dup (?)
        ENUMLOGFONTEXA ends
        tagENUMLOGFONTEXA typedef ENUMLOGFONTEXA
        LPENUMLOGFONTEXA typedef ptr ENUMLOGFONTEXA
        ENUMLOGFONTEXW struct
          elfLogFont LOGFONTW <>
          elfFullName WCHAR LF_FULLFACESIZE dup (?)
          elfStyle WCHAR LF_FACESIZE dup (?)
          elfScript WCHAR LF_FACESIZE dup (?)
        ENUMLOGFONTEXW ends
        tagENUMLOGFONTEXW typedef ENUMLOGFONTEXW
        LPENUMLOGFONTEXW typedef ptr ENUMLOGFONTEXW
        ifdef UNICODE
          ENUMLOGFONTEX typedef ENUMLOGFONTEXW
          LPENUMLOGFONTEX typedef LPENUMLOGFONTEXW
        else
          ENUMLOGFONTEX typedef ENUMLOGFONTEXA
          LPENUMLOGFONTEX typedef LPENUMLOGFONTEXA
        endif
      endif
    endif
    OUT_DEFAULT_PRECIS equ 0
    OUT_STRING_PRECIS equ 1
    OUT_CHARACTER_PRECIS equ 2
    OUT_STROKE_PRECIS equ 3
    OUT_TT_PRECIS equ 4
    OUT_DEVICE_PRECIS equ 5
    OUT_RASTER_PRECIS equ 6
    OUT_TT_ONLY_PRECIS equ 7
    OUT_OUTLINE_PRECIS equ 8
    OUT_SCREEN_OUTLINE_PRECIS equ 9
    OUT_PS_ONLY_PRECIS equ 10
    CLIP_DEFAULT_PRECIS equ 0
    CLIP_CHARACTER_PRECIS equ 1
    CLIP_STROKE_PRECIS equ 2
    CLIP_MASK equ 0fh
    CLIP_LH_ANGLES equ (1 shl 4)
    CLIP_TT_ALWAYS equ (2 shl 4)
    if (_WIN32_WINNT ge _WIN32_WINNT_LONGHORN)
      CLIP_DFA_DISABLE equ (4 shl 4)
    endif
    CLIP_EMBEDDED equ (8 shl 4)
    DEFAULT_QUALITY equ 0
    DRAFT_QUALITY equ 1
    PROOF_QUALITY equ 2
    if (WINVER ge 0400h)
      NONANTIALIASED_QUALITY equ 3
      ANTIALIASED_QUALITY equ 4
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WINXP)
      CLEARTYPE_QUALITY equ 5
      CLEARTYPE_NATURAL_QUALITY equ 6
    endif
    DEFAULT_PITCH equ 0
    FIXED_PITCH equ 1
    VARIABLE_PITCH equ 2
    if (WINVER ge 0400h)
      MONO_FONT equ 8
    endif
    ANSI_CHARSET equ 0
    DEFAULT_CHARSET equ 1
    SYMBOL_CHARSET equ 2
    SHIFTJIS_CHARSET equ 128
    HANGEUL_CHARSET equ 129
    HANGUL_CHARSET equ 129
    GB2312_CHARSET equ 134
    CHINESEBIG5_CHARSET equ 136
    OEM_CHARSET equ 255
    if (WINVER ge 0400h)
      JOHAB_CHARSET equ 130
      HEBREW_CHARSET equ 177
      ARABIC_CHARSET equ 178
      GREEK_CHARSET equ 161
      TURKISH_CHARSET equ 162
      VIETNAMESE_CHARSET equ 163
      THAI_CHARSET equ 222
      EASTEUROPE_CHARSET equ 238
      RUSSIAN_CHARSET equ 204
      MAC_CHARSET equ 77
      BALTIC_CHARSET equ 186
      FS_LATIN1 equ 00000001h
      FS_LATIN2 equ 00000002h
      FS_CYRILLIC equ 00000004h
      FS_GREEK equ 00000008h
      FS_TURKISH equ 00000010h
      FS_HEBREW equ 00000020h
      FS_ARABIC equ 00000040h
      FS_BALTIC equ 00000080h
      FS_VIETNAMESE equ 00000100h
      FS_THAI equ 00010000h
      FS_JISJAPAN equ 00020000h
      FS_CHINESESIMP equ 00040000h
      FS_WANSUNG equ 00080000h
      FS_CHINESETRAD equ 00100000h
      FS_JOHAB equ 00200000h
      FS_SYMBOL equ 80000000h
    endif
    FF_DONTCARE equ (0 shl 4)
    FF_ROMAN equ (1 shl 4)
    FF_SWISS equ (2 shl 4)
    FF_MODERN equ (3 shl 4)
    FF_SCRIPT equ (4 shl 4)
    FF_DECORATIVE equ (5 shl 4)
    FW_DONTCARE equ 0
    FW_THIN equ 100
    FW_EXTRALIGHT equ 200
    FW_LIGHT equ 300
    FW_NORMAL equ 400
    FW_MEDIUM equ 500
    FW_SEMIBOLD equ 600
    FW_BOLD equ 700
    FW_EXTRABOLD equ 800
    FW_HEAVY equ 900
    FW_ULTRALIGHT equ <FW_EXTRALIGHT>
    FW_REGULAR equ <FW_NORMAL>
    FW_DEMIBOLD equ <FW_SEMIBOLD>
    FW_ULTRABOLD equ <FW_EXTRABOLD>
    FW_BLACK equ <FW_HEAVY>
    PANOSE_COUNT equ 10
    PAN_FAMILYTYPE_INDEX equ 0
    PAN_SERIFSTYLE_INDEX equ 1
    PAN_WEIGHT_INDEX equ 2
    PAN_PROPORTION_INDEX equ 3
    PAN_CONTRAST_INDEX equ 4
    PAN_STROKEVARIATION_INDEX equ 5
    PAN_ARMSTYLE_INDEX equ 6
    PAN_LETTERFORM_INDEX equ 7
    PAN_MIDLINE_INDEX equ 8
    PAN_XHEIGHT_INDEX equ 9
    PAN_CULTURE_LATIN equ 0
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      PANOSE struct
        bFamilyType BYTE ?
        bSerifStyle BYTE ?
        bWeight BYTE ?
        bProportion BYTE ?
        bContrast BYTE ?
        bStrokeVariation BYTE ?
        bArmStyle BYTE ?
        bLetterform BYTE ?
        bMidline BYTE ?
        bXHeight BYTE ?
      PANOSE ends
      tagPANOSE typedef PANOSE
      LPPANOSE typedef ptr PANOSE
      PAN_ANY equ 0
      PAN_NO_FIT equ 1
      PAN_FAMILY_TEXT_DISPLAY equ 2
      PAN_FAMILY_SCRIPT equ 3
      PAN_FAMILY_DECORATIVE equ 4
      PAN_FAMILY_PICTORIAL equ 5
      PAN_SERIF_COVE equ 2
      PAN_SERIF_OBTUSE_COVE equ 3
      PAN_SERIF_SQUARE_COVE equ 4
      PAN_SERIF_OBTUSE_SQUARE_COVE equ 5
      PAN_SERIF_SQUARE equ 6
      PAN_SERIF_THIN equ 7
      PAN_SERIF_BONE equ 8
      PAN_SERIF_EXAGGERATED equ 9
      PAN_SERIF_TRIANGLE equ 10
      PAN_SERIF_NORMAL_SANS equ 11
      PAN_SERIF_OBTUSE_SANS equ 12
      PAN_SERIF_PERP_SANS equ 13
      PAN_SERIF_FLARED equ 14
      PAN_SERIF_ROUNDED equ 15
      PAN_WEIGHT_VERY_LIGHT equ 2
      PAN_WEIGHT_LIGHT equ 3
      PAN_WEIGHT_THIN equ 4
      PAN_WEIGHT_BOOK equ 5
      PAN_WEIGHT_MEDIUM equ 6
      PAN_WEIGHT_DEMI equ 7
      PAN_WEIGHT_BOLD equ 8
      PAN_WEIGHT_HEAVY equ 9
      PAN_WEIGHT_BLACK equ 10
      PAN_WEIGHT_NORD equ 11
      PAN_PROP_OLD_STYLE equ 2
      PAN_PROP_MODERN equ 3
      PAN_PROP_EVEN_WIDTH equ 4
      PAN_PROP_EXPANDED equ 5
      PAN_PROP_CONDENSED equ 6
      PAN_PROP_VERY_EXPANDED equ 7
      PAN_PROP_VERY_CONDENSED equ 8
      PAN_PROP_MONOSPACED equ 9
      PAN_CONTRAST_NONE equ 2
      PAN_CONTRAST_VERY_LOW equ 3
      PAN_CONTRAST_LOW equ 4
      PAN_CONTRAST_MEDIUM_LOW equ 5
      PAN_CONTRAST_MEDIUM equ 6
      PAN_CONTRAST_MEDIUM_HIGH equ 7
      PAN_CONTRAST_HIGH equ 8
      PAN_CONTRAST_VERY_HIGH equ 9
      PAN_STROKE_GRADUAL_DIAG equ 2
      PAN_STROKE_GRADUAL_TRAN equ 3
      PAN_STROKE_GRADUAL_VERT equ 4
      PAN_STROKE_GRADUAL_HORZ equ 5
      PAN_STROKE_RAPID_VERT equ 6
      PAN_STROKE_RAPID_HORZ equ 7
      PAN_STROKE_INSTANT_VERT equ 8
      PAN_STRAIGHT_ARMS_HORZ equ 2
      PAN_STRAIGHT_ARMS_WEDGE equ 3
      PAN_STRAIGHT_ARMS_VERT equ 4
      PAN_STRAIGHT_ARMS_SINGLE_SERIF equ 5
      PAN_STRAIGHT_ARMS_DOUBLE_SERIF equ 6
      PAN_BENT_ARMS_HORZ equ 7
      PAN_BENT_ARMS_WEDGE equ 8
      PAN_BENT_ARMS_VERT equ 9
      PAN_BENT_ARMS_SINGLE_SERIF equ 10
      PAN_BENT_ARMS_DOUBLE_SERIF equ 11
      PAN_LETT_NORMAL_CONTACT equ 2
      PAN_LETT_NORMAL_WEIGHTED equ 3
      PAN_LETT_NORMAL_BOXED equ 4
      PAN_LETT_NORMAL_FLATTENED equ 5
      PAN_LETT_NORMAL_ROUNDED equ 6
      PAN_LETT_NORMAL_OFF_CENTER equ 7
      PAN_LETT_NORMAL_SQUARE equ 8
      PAN_LETT_OBLIQUE_CONTACT equ 9
      PAN_LETT_OBLIQUE_WEIGHTED equ 10
      PAN_LETT_OBLIQUE_BOXED equ 11
      PAN_LETT_OBLIQUE_FLATTENED equ 12
      PAN_LETT_OBLIQUE_ROUNDED equ 13
      PAN_LETT_OBLIQUE_OFF_CENTER equ 14
      PAN_LETT_OBLIQUE_SQUARE equ 15
      PAN_MIDLINE_STANDARD_TRIMMED equ 2
      PAN_MIDLINE_STANDARD_POINTED equ 3
      PAN_MIDLINE_STANDARD_SERIFED equ 4
      PAN_MIDLINE_HIGH_TRIMMED equ 5
      PAN_MIDLINE_HIGH_POINTED equ 6
      PAN_MIDLINE_HIGH_SERIFED equ 7
      PAN_MIDLINE_CONSTANT_TRIMMED equ 8
      PAN_MIDLINE_CONSTANT_POINTED equ 9
      PAN_MIDLINE_CONSTANT_SERIFED equ 10
      PAN_MIDLINE_LOW_TRIMMED equ 11
      PAN_MIDLINE_LOW_POINTED equ 12
      PAN_MIDLINE_LOW_SERIFED equ 13
      PAN_XHEIGHT_CONSTANT_SMALL equ 2
      PAN_XHEIGHT_CONSTANT_STD equ 3
      PAN_XHEIGHT_CONSTANT_LARGE equ 4
      PAN_XHEIGHT_DUCKING_SMALL equ 5
      PAN_XHEIGHT_DUCKING_STD equ 6
      PAN_XHEIGHT_DUCKING_LARGE equ 7
      ELF_VENDOR_SIZE equ 4
      EXTLOGFONTA struct
        elfLogFont LOGFONTA <>
        elfFullName BYTE LF_FULLFACESIZE dup (?)
        elfStyle BYTE LF_FACESIZE dup (?)
        elfVersion DWORD ?
        elfStyleSize DWORD ?
        elfMatch DWORD ?
        elfReserved DWORD ?
        elfVendorId BYTE ELF_VENDOR_SIZE dup (?)
        elfCulture DWORD ?
        elfPanose PANOSE <>
      EXTLOGFONTA ends
      tagEXTLOGFONTA typedef EXTLOGFONTA
      PEXTLOGFONTA typedef ptr EXTLOGFONTA
      NPEXTLOGFONTA typedef ptr EXTLOGFONTA
      LPEXTLOGFONTA typedef ptr EXTLOGFONTA
      EXTLOGFONTW struct
        elfLogFont LOGFONTW <>
        elfFullName WCHAR LF_FULLFACESIZE dup (?)
        elfStyle WCHAR LF_FACESIZE dup (?)
        elfVersion DWORD ?
        elfStyleSize DWORD ?
        elfMatch DWORD ?
        elfReserved DWORD ?
        elfVendorId BYTE ELF_VENDOR_SIZE dup (?)
        elfCulture DWORD ?
        elfPanose PANOSE <>
      EXTLOGFONTW ends
      tagEXTLOGFONTW typedef EXTLOGFONTW
      PEXTLOGFONTW typedef ptr EXTLOGFONTW
      NPEXTLOGFONTW typedef ptr EXTLOGFONTW
      LPEXTLOGFONTW typedef ptr EXTLOGFONTW
      ifdef UNICODE
        EXTLOGFONT typedef EXTLOGFONTW
        PEXTLOGFONT typedef PEXTLOGFONTW
        NPEXTLOGFONT typedef NPEXTLOGFONTW
        LPEXTLOGFONT typedef LPEXTLOGFONTW
      else
        EXTLOGFONT typedef EXTLOGFONTA
        PEXTLOGFONT typedef PEXTLOGFONTA
        NPEXTLOGFONT typedef NPEXTLOGFONTA
        LPEXTLOGFONT typedef LPEXTLOGFONTA
      endif
    endif
    ELF_VERSION equ 0
    ELF_CULTURE_LATIN equ 0
    RASTER_FONTTYPE equ 0001h
    DEVICE_FONTTYPE equ 0002h
    TRUETYPE_FONTTYPE equ 0004h
    RGB macro r, g, b
      exitm <((((r) or (((g)) shl 8)) or (((b)) shl 16)))>
    endm
    PALETTERGB macro r, g, b
      exitm <(02000000h or RGB(r, g, b))>
    endm
    PALETTEINDEX macro i
      exitm <((01000000h or (i)))>
    endm
    PC_RESERVED equ 01h
    PC_EXPLICIT equ 02h
    PC_NOCOLLAPSE equ 04h
    GetRValue macro rgb
      exitm <(LOBYTE(rgb))>
    endm
    GetGValue macro rgb
      exitm <(LOBYTE(((rgb)) shr 8))>
    endm
    GetBValue macro rgb
      exitm <(LOBYTE((rgb) shr 16))>
    endm
    TRANSPARENT equ 1
    OPAQUE equ 2
    BKMODE_LAST equ 2
    GM_COMPATIBLE equ 1
    GM_ADVANCED equ 2
    GM_LAST equ 2
    PT_CLOSEFIGURE equ 01h
    PT_LINETO equ 02h
    PT_BEZIERTO equ 04h
    PT_MOVETO equ 06h
    MM_TEXT equ 1
    MM_LOMETRIC equ 2
    MM_HIMETRIC equ 3
    MM_LOENGLISH equ 4
    MM_HIENGLISH equ 5
    MM_TWIPS equ 6
    MM_ISOTROPIC equ 7
    MM_ANISOTROPIC equ 8
    MM_MIN equ <MM_TEXT>
    MM_MAX equ <MM_ANISOTROPIC>
    MM_MAX_FIXEDSCALE equ <MM_TWIPS>
    ABSOLUTE equ 1
    RELATIVE equ 2
    WHITE_BRUSH equ 0
    LTGRAY_BRUSH equ 1
    GRAY_BRUSH equ 2
    DKGRAY_BRUSH equ 3
    BLACK_BRUSH equ 4
    NULL_BRUSH equ 5
    HOLLOW_BRUSH equ <NULL_BRUSH>
    WHITE_PEN equ 6
    BLACK_PEN equ 7
    NULL_PEN equ 8
    OEM_FIXED_FONT equ 10
    ANSI_FIXED_FONT equ 11
    ANSI_VAR_FONT equ 12
    SYSTEM_FONT equ 13
    DEVICE_DEFAULT_FONT equ 14
    DEFAULT_PALETTE equ 15
    SYSTEM_FIXED_FONT equ 16
    if (WINVER ge 0400h)
      DEFAULT_GUI_FONT equ 17
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN2K)
      DC_BRUSH equ 18
      DC_PEN equ 19
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN2K)
      STOCK_LAST equ 19
    elseif (WINVER ge 0400h)
      STOCK_LAST equ 17
    else
      STOCK_LAST equ 16
    endif
    CLR_INVALID equ 0FFFFFFFFh
    BS_SOLID equ 0
    BS_NULL equ 1
    BS_HOLLOW equ <BS_NULL>
    BS_HATCHED equ 2
    BS_PATTERN equ 3
    BS_INDEXED equ 4
    BS_DIBPATTERN equ 5
    BS_DIBPATTERNPT equ 6
    BS_PATTERN8X8 equ 7
    BS_DIBPATTERN8X8 equ 8
    BS_MONOPATTERN equ 9
    HS_HORIZONTAL equ 0
    HS_VERTICAL equ 1
    HS_FDIAGONAL equ 2
    HS_BDIAGONAL equ 3
    HS_CROSS equ 4
    HS_DIAGCROSS equ 5
    HS_API_MAX equ 12
    PS_SOLID equ 0
    PS_DASH equ 1
    PS_DOT equ 2
    PS_DASHDOT equ 3
    PS_DASHDOTDOT equ 4
    PS_NULL equ 5
    PS_INSIDEFRAME equ 6
    PS_USERSTYLE equ 7
    PS_ALTERNATE equ 8
    PS_STYLE_MASK equ 0000000Fh
    PS_ENDCAP_ROUND equ 00000000h
    PS_ENDCAP_SQUARE equ 00000100h
    PS_ENDCAP_FLAT equ 00000200h
    PS_ENDCAP_MASK equ 00000F00h
    PS_JOIN_ROUND equ 00000000h
    PS_JOIN_BEVEL equ 00001000h
    PS_JOIN_MITER equ 00002000h
    PS_JOIN_MASK equ 0000F000h
    PS_COSMETIC equ 00000000h
    PS_GEOMETRIC equ 00010000h
    PS_TYPE_MASK equ 000F0000h
    AD_COUNTERCLOCKWISE equ 1
    AD_CLOCKWISE equ 2
    DRIVERVERSION equ 0
    TECHNOLOGY equ 2
    HORZSIZE equ 4
    VERTSIZE equ 6
    HORZRES equ 8
    VERTRES equ 10
    BITSPIXEL equ 12
    PLANES equ 14
    NUMBRUSHES equ 16
    NUMPENS equ 18
    NUMMARKERS equ 20
    NUMFONTS equ 22
    NUMCOLORS equ 24
    PDEVICESIZE equ 26
    CURVECAPS equ 28
    LINECAPS equ 30
    POLYGONALCAPS equ 32
    TEXTCAPS equ 34
    CLIPCAPS equ 36
    RASTERCAPS equ 38
    ASPECTX equ 40
    ASPECTY equ 42
    ASPECTXY equ 44
    LOGPIXELSX equ 88
    LOGPIXELSY equ 90
    SIZEPALETTE equ 104
    NUMRESERVED equ 106
    COLORRES equ 108
    PHYSICALWIDTH equ 110
    PHYSICALHEIGHT equ 111
    PHYSICALOFFSETX equ 112
    PHYSICALOFFSETY equ 113
    SCALINGFACTORX equ 114
    SCALINGFACTORY equ 115
    VREFRESH equ 116
    DESKTOPVERTRES equ 117
    DESKTOPHORZRES equ 118
    BLTALIGNMENT equ 119
    if (WINVER ge 0500h)
      SHADEBLENDCAPS equ 120
      COLORMGMTCAPS equ 121
    endif
    ifndef NOGDICAPMASKS
      DT_PLOTTER equ 0
      DT_RASDISPLAY equ 1
      DT_RASPRINTER equ 2
      DT_RASCAMERA equ 3
      DT_CHARSTREAM equ 4
      DT_METAFILE equ 5
      DT_DISPFILE equ 6
      CC_NONE equ 0
      CC_CIRCLES equ 1
      CC_PIE equ 2
      CC_CHORD equ 4
      CC_ELLIPSES equ 8
      CC_WIDE equ 16
      CC_STYLED equ 32
      CC_WIDESTYLED equ 64
      CC_INTERIORS equ 128
      CC_ROUNDRECT equ 256
      LC_NONE equ 0
      LC_POLYLINE equ 2
      LC_MARKER equ 4
      LC_POLYMARKER equ 8
      LC_WIDE equ 16
      LC_STYLED equ 32
      LC_WIDESTYLED equ 64
      LC_INTERIORS equ 128
      PC_NONE equ 0
      PC_POLYGON equ 1
      PC_RECTANGLE equ 2
      PC_WINDPOLYGON equ 4
      PC_TRAPEZOID equ 4
      PC_SCANLINE equ 8
      PC_WIDE equ 16
      PC_STYLED equ 32
      PC_WIDESTYLED equ 64
      PC_INTERIORS equ 128
      PC_POLYPOLYGON equ 256
      PC_PATHS equ 512
      CP_NONE equ 0
      CP_RECTANGLE equ 1
      CP_REGION equ 2
      TC_OP_CHARACTER equ 00000001h
      TC_OP_STROKE equ 00000002h
      TC_CP_STROKE equ 00000004h
      TC_CR_90 equ 00000008h
      TC_CR_ANY equ 00000010h
      TC_SF_X_YINDEP equ 00000020h
      TC_SA_DOUBLE equ 00000040h
      TC_SA_INTEGER equ 00000080h
      TC_SA_CONTIN equ 00000100h
      TC_EA_DOUBLE equ 00000200h
      TC_IA_ABLE equ 00000400h
      TC_UA_ABLE equ 00000800h
      TC_SO_ABLE equ 00001000h
      TC_RA_ABLE equ 00002000h
      TC_VA_ABLE equ 00004000h
      TC_RESERVED equ 00008000h
      TC_SCROLLBLT equ 00010000h
    endif
    RC_NONE equ <>
    RC_BITBLT equ 1
    RC_BANDING equ 2
    RC_SCALING equ 4
    RC_BITMAP64 equ 8
    RC_GDI20_OUTPUT equ 0010h
    RC_GDI20_STATE equ 0020h
    RC_SAVEBITMAP equ 0040h
    RC_DI_BITMAP equ 0080h
    RC_PALETTE equ 0100h
    RC_DIBTODEV equ 0200h
    RC_BIGFONT equ 0400h
    RC_STRETCHBLT equ 0800h
    RC_FLOODFILL equ 1000h
    RC_STRETCHDIB equ 2000h
    RC_OP_DX_OUTPUT equ 4000h
    RC_DEVBITS equ 8000h
    if (WINVER ge 0500h)
      SB_NONE equ 00000000h
      SB_CONST_ALPHA equ 00000001h
      SB_PIXEL_ALPHA equ 00000002h
      SB_PREMULT_ALPHA equ 00000004h
      SB_GRAD_RECT equ 00000010h
      SB_GRAD_TRI equ 00000020h
      CM_NONE equ 00000000h
      CM_DEVICE_ICM equ 00000001h
      CM_GAMMA_RAMP equ 00000002h
      CM_CMYK_COLOR equ 00000004h
    endif
    DIB_RGB_COLORS equ 0
    DIB_PAL_COLORS equ 1
    SYSPAL_ERROR equ 0
    SYSPAL_STATIC equ 1
    SYSPAL_NOSTATIC equ 2
    SYSPAL_NOSTATIC256 equ 3
    CBM_INIT equ 04h
    FLOODFILLBORDER equ 0
    FLOODFILLSURFACE equ 1
    CCHDEVICENAME equ 32
    CCHFORMNAME equ 32
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      if (_WIN32_WINNT ge ((OSVER(NTDDI_WINXPSP2)) shr 16))
        DEVMODEA struct
          dmDeviceName BYTE CCHDEVICENAME dup (?)
          dmSpecVersion WORD ?
          dmDriverVersion WORD ?
          dmSize WORD ?
          dmDriverExtra WORD ?
          dmFields DWORD ?
          union
            struct
              dmOrientation SWORD ?
              dmPaperSize SWORD ?
              dmPaperLength SWORD ?
              dmPaperWidth SWORD ?
              dmScale SWORD ?
              dmCopies SWORD ?
              dmDefaultSource SWORD ?
              dmPrintQuality SWORD ?
            ends
            struct
              dmPosition POINTL <>
              dmDisplayOrientation DWORD ?
              dmDisplayFixedOutput DWORD ?
            ends
          ends
          dmColor SWORD ?
          dmDuplex SWORD ?
          dmYResolution SWORD ?
          dmTTOption SWORD ?
          dmCollate SWORD ?
          dmFormName BYTE CCHFORMNAME dup (?)
          dmLogPixels WORD ?
          dmBitsPerPel DWORD ?
          dmPelsWidth DWORD ?
          dmPelsHeight DWORD ?
          union
            dmDisplayFlags DWORD ?
            dmNup DWORD ?
          ends
          dmDisplayFrequency DWORD ?
          if (WINVER ge 0400h)
            dmICMMethod DWORD ?
            dmICMIntent DWORD ?
            dmMediaType DWORD ?
            dmDitherType DWORD ?
            dmReserved1 DWORD ?
            dmReserved2 DWORD ?
            if (WINVER ge 0500h) or (_WIN32_WINNT ge _WIN32_WINNT_NT4)
              dmPanningWidth DWORD ?
              dmPanningHeight DWORD ?
            endif
          endif
        DEVMODEA ends
        _devicemodeA typedef DEVMODEA
        PDEVMODEA typedef ptr DEVMODEA
        NPDEVMODEA typedef ptr DEVMODEA
        LPDEVMODEA typedef ptr DEVMODEA
        DEVMODEW struct
          dmDeviceName WCHAR CCHDEVICENAME dup (?)
          dmSpecVersion WORD ?
          dmDriverVersion WORD ?
          dmSize WORD ?
          dmDriverExtra WORD ?
          dmFields DWORD ?
          union
            struct
              dmOrientation SWORD ?
              dmPaperSize SWORD ?
              dmPaperLength SWORD ?
              dmPaperWidth SWORD ?
              dmScale SWORD ?
              dmCopies SWORD ?
              dmDefaultSource SWORD ?
              dmPrintQuality SWORD ?
            ends
            struct
              dmPosition POINTL <>
              dmDisplayOrientation DWORD ?
              dmDisplayFixedOutput DWORD ?
            ends
          ends
          dmColor SWORD ?
          dmDuplex SWORD ?
          dmYResolution SWORD ?
          dmTTOption SWORD ?
          dmCollate SWORD ?
          dmFormName WCHAR CCHFORMNAME dup (?)
          dmLogPixels WORD ?
          dmBitsPerPel DWORD ?
          dmPelsWidth DWORD ?
          dmPelsHeight DWORD ?
          union
            dmDisplayFlags DWORD ?
            dmNup DWORD ?
          ends
          dmDisplayFrequency DWORD ?
          if (WINVER ge 0400h)
            dmICMMethod DWORD ?
            dmICMIntent DWORD ?
            dmMediaType DWORD ?
            dmDitherType DWORD ?
            dmReserved1 DWORD ?
            dmReserved2 DWORD ?
            if (WINVER ge 0500h) or (_WIN32_WINNT ge _WIN32_WINNT_NT4)
              dmPanningWidth DWORD ?
              dmPanningHeight DWORD ?
            endif
          endif
        DEVMODEW ends
        _devicemodeW typedef DEVMODEW
        PDEVMODEW typedef ptr DEVMODEW
        NPDEVMODEW typedef ptr DEVMODEW
        LPDEVMODEW typedef ptr DEVMODEW
        ifdef UNICODE
          DEVMODE typedef DEVMODEW
          PDEVMODE typedef PDEVMODEW
          NPDEVMODE typedef NPDEVMODEW
          LPDEVMODE typedef LPDEVMODEW
        else
          DEVMODE typedef DEVMODEA
          PDEVMODE typedef PDEVMODEA
          NPDEVMODE typedef NPDEVMODEA
          LPDEVMODE typedef LPDEVMODEA
        endif
      else
        DEVMODEA struct
          dmDeviceName BYTE CCHDEVICENAME dup (?)
          dmSpecVersion WORD ?
          dmDriverVersion WORD ?
          dmSize WORD ?
          dmDriverExtra WORD ?
          dmFields DWORD ?
          union
            struct
              dmOrientation SWORD ?
              dmPaperSize SWORD ?
              dmPaperLength SWORD ?
              dmPaperWidth SWORD ?
            ends
            dmPosition POINTL <>
          ends
          dmScale SWORD ?
          dmCopies SWORD ?
          dmDefaultSource SWORD ?
          dmPrintQuality SWORD ?
          dmColor SWORD ?
          dmDuplex SWORD ?
          dmYResolution SWORD ?
          dmTTOption SWORD ?
          dmCollate SWORD ?
          dmFormName BYTE CCHFORMNAME dup (?)
          dmLogPixels WORD ?
          dmBitsPerPel DWORD ?
          dmPelsWidth DWORD ?
          dmPelsHeight DWORD ?
          union
            dmDisplayFlags DWORD ?
            dmNup DWORD ?
          ends
          dmDisplayFrequency DWORD ?
          if (WINVER ge 0400h)
            dmICMMethod DWORD ?
            dmICMIntent DWORD ?
            dmMediaType DWORD ?
            dmDitherType DWORD ?
            dmReserved1 DWORD ?
            dmReserved2 DWORD ?
            if (WINVER ge 0500h) or (_WIN32_WINNT ge _WIN32_WINNT_NT4)
              dmPanningWidth DWORD ?
              dmPanningHeight DWORD ?
            endif
          endif
        DEVMODEA ends
        _devicemodeA typedef DEVMODEA
        PDEVMODEA typedef ptr DEVMODEA
        NPDEVMODEA typedef ptr DEVMODEA
        LPDEVMODEA typedef ptr DEVMODEA
        DEVMODEW struct
          dmDeviceName WCHAR CCHDEVICENAME dup (?)
          dmSpecVersion WORD ?
          dmDriverVersion WORD ?
          dmSize WORD ?
          dmDriverExtra WORD ?
          dmFields DWORD ?
          union
            struct
              dmOrientation SWORD ?
              dmPaperSize SWORD ?
              dmPaperLength SWORD ?
              dmPaperWidth SWORD ?
            ends
            dmPosition POINTL <>
          ends
          dmScale SWORD ?
          dmCopies SWORD ?
          dmDefaultSource SWORD ?
          dmPrintQuality SWORD ?
          dmColor SWORD ?
          dmDuplex SWORD ?
          dmYResolution SWORD ?
          dmTTOption SWORD ?
          dmCollate SWORD ?
          dmFormName WCHAR CCHFORMNAME dup (?)
          dmLogPixels WORD ?
          dmBitsPerPel DWORD ?
          dmPelsWidth DWORD ?
          dmPelsHeight DWORD ?
          union
            dmDisplayFlags DWORD ?
            dmNup DWORD ?
          ends
          dmDisplayFrequency DWORD ?
          if (WINVER ge 0400h)
            dmICMMethod DWORD ?
            dmICMIntent DWORD ?
            dmMediaType DWORD ?
            dmDitherType DWORD ?
            dmReserved1 DWORD ?
            dmReserved2 DWORD ?
            if (WINVER ge 0500h) or (_WIN32_WINNT ge _WIN32_WINNT_NT4)
              dmPanningWidth DWORD ?
              dmPanningHeight DWORD ?
            endif
          endif
        DEVMODEW ends
        _devicemodeW typedef DEVMODEW
        PDEVMODEW typedef ptr DEVMODEW
        NPDEVMODEW typedef ptr DEVMODEW
        LPDEVMODEW typedef ptr DEVMODEW
        ifdef UNICODE
          DEVMODE typedef DEVMODEW
          PDEVMODE typedef PDEVMODEW
          NPDEVMODE typedef NPDEVMODEW
          LPDEVMODE typedef LPDEVMODEW
        else
          DEVMODE typedef DEVMODEA
          PDEVMODE typedef PDEVMODEA
          NPDEVMODE typedef NPDEVMODEA
          LPDEVMODE typedef LPDEVMODEA
        endif
      endif
    endif
    if (WINVER ge 0500h) or (_WIN32_WINNT ge _WIN32_WINNT_NT4)
      DM_SPECVERSION equ 0401h
    elseif (WINVER ge 0400h)
      DM_SPECVERSION equ 0400h
    else
      DM_SPECVERSION equ 0320h
    endif
    DM_ORIENTATION equ 00000001h
    DM_PAPERSIZE equ 00000002h
    DM_PAPERLENGTH equ 00000004h
    DM_PAPERWIDTH equ 00000008h
    DM_SCALE equ 00000010h
    if (WINVER ge 0500h)
      DM_POSITION equ 00000020h
      DM_NUP equ 00000040h
    endif
    if (WINVER ge 0501h)
      DM_DISPLAYORIENTATION equ 00000080h
    endif
    DM_COPIES equ 00000100h
    DM_DEFAULTSOURCE equ 00000200h
    DM_PRINTQUALITY equ 00000400h
    DM_COLOR equ 00000800h
    DM_DUPLEX equ 00001000h
    DM_YRESOLUTION equ 00002000h
    DM_TTOPTION equ 00004000h
    DM_COLLATE equ 00008000h
    DM_FORMNAME equ 00010000h
    DM_LOGPIXELS equ 00020000h
    DM_BITSPERPEL equ 00040000h
    DM_PELSWIDTH equ 00080000h
    DM_PELSHEIGHT equ 00100000h
    DM_DISPLAYFLAGS equ 00200000h
    DM_DISPLAYFREQUENCY equ 00400000h
    if (WINVER ge 0400h)
      DM_ICMMETHOD equ 00800000h
      DM_ICMINTENT equ 01000000h
      DM_MEDIATYPE equ 02000000h
      DM_DITHERTYPE equ 04000000h
      DM_PANNINGWIDTH equ 08000000h
      DM_PANNINGHEIGHT equ 10000000h
    endif
    if (WINVER ge 0501h)
      DM_DISPLAYFIXEDOUTPUT equ 20000000h
    endif
    DMORIENT_PORTRAIT equ 1
    DMORIENT_LANDSCAPE equ 2
    DMPAPER_FIRST equ <DMPAPER_LETTER>
    DMPAPER_LETTER equ 1
    DMPAPER_LETTERSMALL equ 2
    DMPAPER_TABLOID equ 3
    DMPAPER_LEDGER equ 4
    DMPAPER_LEGAL equ 5
    DMPAPER_STATEMENT equ 6
    DMPAPER_EXECUTIVE equ 7
    DMPAPER_A3 equ 8
    DMPAPER_A4 equ 9
    DMPAPER_A4SMALL equ 10
    DMPAPER_A5 equ 11
    DMPAPER_B4 equ 12
    DMPAPER_B5 equ 13
    DMPAPER_FOLIO equ 14
    DMPAPER_QUARTO equ 15
    DMPAPER_10X14 equ 16
    DMPAPER_11X17 equ 17
    DMPAPER_NOTE equ 18
    DMPAPER_ENV_9 equ 19
    DMPAPER_ENV_10 equ 20
    DMPAPER_ENV_11 equ 21
    DMPAPER_ENV_12 equ 22
    DMPAPER_ENV_14 equ 23
    DMPAPER_CSHEET equ 24
    DMPAPER_DSHEET equ 25
    DMPAPER_ESHEET equ 26
    DMPAPER_ENV_DL equ 27
    DMPAPER_ENV_C5 equ 28
    DMPAPER_ENV_C3 equ 29
    DMPAPER_ENV_C4 equ 30
    DMPAPER_ENV_C6 equ 31
    DMPAPER_ENV_C65 equ 32
    DMPAPER_ENV_B4 equ 33
    DMPAPER_ENV_B5 equ 34
    DMPAPER_ENV_B6 equ 35
    DMPAPER_ENV_ITALY equ 36
    DMPAPER_ENV_MONARCH equ 37
    DMPAPER_ENV_PERSONAL equ 38
    DMPAPER_FANFOLD_US equ 39
    DMPAPER_FANFOLD_STD_GERMAN equ 40
    DMPAPER_FANFOLD_LGL_GERMAN equ 41
    if (WINVER ge 0400h)
      DMPAPER_ISO_B4 equ 42
      DMPAPER_JAPANESE_POSTCARD equ 43
      DMPAPER_9X11 equ 44
      DMPAPER_10X11 equ 45
      DMPAPER_15X11 equ 46
      DMPAPER_ENV_INVITE equ 47
      DMPAPER_RESERVED_48 equ 48
      DMPAPER_RESERVED_49 equ 49
      DMPAPER_LETTER_EXTRA equ 50
      DMPAPER_LEGAL_EXTRA equ 51
      DMPAPER_TABLOID_EXTRA equ 52
      DMPAPER_A4_EXTRA equ 53
      DMPAPER_LETTER_TRANSVERSE equ 54
      DMPAPER_A4_TRANSVERSE equ 55
      DMPAPER_LETTER_EXTRA_TRANSVERSE equ 56
      DMPAPER_A_PLUS equ 57
      DMPAPER_B_PLUS equ 58
      DMPAPER_LETTER_PLUS equ 59
      DMPAPER_A4_PLUS equ 60
      DMPAPER_A5_TRANSVERSE equ 61
      DMPAPER_B5_TRANSVERSE equ 62
      DMPAPER_A3_EXTRA equ 63
      DMPAPER_A5_EXTRA equ 64
      DMPAPER_B5_EXTRA equ 65
      DMPAPER_A2 equ 66
      DMPAPER_A3_TRANSVERSE equ 67
      DMPAPER_A3_EXTRA_TRANSVERSE equ 68
    endif
    if (WINVER ge 0500h)
      DMPAPER_DBL_JAPANESE_POSTCARD equ 69
      DMPAPER_A6 equ 70
      DMPAPER_JENV_KAKU2 equ 71
      DMPAPER_JENV_KAKU3 equ 72
      DMPAPER_JENV_CHOU3 equ 73
      DMPAPER_JENV_CHOU4 equ 74
      DMPAPER_LETTER_ROTATED equ 75
      DMPAPER_A3_ROTATED equ 76
      DMPAPER_A4_ROTATED equ 77
      DMPAPER_A5_ROTATED equ 78
      DMPAPER_B4_JIS_ROTATED equ 79
      DMPAPER_B5_JIS_ROTATED equ 80
      DMPAPER_JAPANESE_POSTCARD_ROTATED equ 81
      DMPAPER_DBL_JAPANESE_POSTCARD_ROTATED equ 82
      DMPAPER_A6_ROTATED equ 83
      DMPAPER_JENV_KAKU2_ROTATED equ 84
      DMPAPER_JENV_KAKU3_ROTATED equ 85
      DMPAPER_JENV_CHOU3_ROTATED equ 86
      DMPAPER_JENV_CHOU4_ROTATED equ 87
      DMPAPER_B6_JIS equ 88
      DMPAPER_B6_JIS_ROTATED equ 89
      DMPAPER_12X11 equ 90
      DMPAPER_JENV_YOU4 equ 91
      DMPAPER_JENV_YOU4_ROTATED equ 92
      DMPAPER_P16K equ 93
      DMPAPER_P32K equ 94
      DMPAPER_P32KBIG equ 95
      DMPAPER_PENV_1 equ 96
      DMPAPER_PENV_2 equ 97
      DMPAPER_PENV_3 equ 98
      DMPAPER_PENV_4 equ 99
      DMPAPER_PENV_5 equ 100
      DMPAPER_PENV_6 equ 101
      DMPAPER_PENV_7 equ 102
      DMPAPER_PENV_8 equ 103
      DMPAPER_PENV_9 equ 104
      DMPAPER_PENV_10 equ 105
      DMPAPER_P16K_ROTATED equ 106
      DMPAPER_P32K_ROTATED equ 107
      DMPAPER_P32KBIG_ROTATED equ 108
      DMPAPER_PENV_1_ROTATED equ 109
      DMPAPER_PENV_2_ROTATED equ 110
      DMPAPER_PENV_3_ROTATED equ 111
      DMPAPER_PENV_4_ROTATED equ 112
      DMPAPER_PENV_5_ROTATED equ 113
      DMPAPER_PENV_6_ROTATED equ 114
      DMPAPER_PENV_7_ROTATED equ 115
      DMPAPER_PENV_8_ROTATED equ 116
      DMPAPER_PENV_9_ROTATED equ 117
      DMPAPER_PENV_10_ROTATED equ 118
    endif
    if (WINVER ge 0500h)
      DMPAPER_LAST equ <DMPAPER_PENV_10_ROTATED>
    elseif (WINVER ge 0400h)
      DMPAPER_LAST equ <DMPAPER_A3_EXTRA_TRANSVERSE>
    else
      DMPAPER_LAST equ <DMPAPER_FANFOLD_LGL_GERMAN>
    endif
    DMPAPER_USER equ 256
    DMBIN_FIRST equ <DMBIN_UPPER>
    DMBIN_UPPER equ 1
    DMBIN_ONLYONE equ 1
    DMBIN_LOWER equ 2
    DMBIN_MIDDLE equ 3
    DMBIN_MANUAL equ 4
    DMBIN_ENVELOPE equ 5
    DMBIN_ENVMANUAL equ 6
    DMBIN_AUTO equ 7
    DMBIN_TRACTOR equ 8
    DMBIN_SMALLFMT equ 9
    DMBIN_LARGEFMT equ 10
    DMBIN_LARGECAPACITY equ 11
    DMBIN_CASSETTE equ 14
    DMBIN_FORMSOURCE equ 15
    DMBIN_LAST equ <DMBIN_FORMSOURCE>
    DMBIN_USER equ 256
    DMRES_DRAFT equ (- 1)
    DMRES_LOW equ (- 2)
    DMRES_MEDIUM equ (- 3)
    DMRES_HIGH equ (- 4)
    DMCOLOR_MONOCHROME equ 1
    DMCOLOR_COLOR equ 2
    DMDUP_SIMPLEX equ 1
    DMDUP_VERTICAL equ 2
    DMDUP_HORIZONTAL equ 3
    DMTT_BITMAP equ 1
    DMTT_DOWNLOAD equ 2
    DMTT_SUBDEV equ 3
    if (WINVER ge 0400h)
      DMTT_DOWNLOAD_OUTLINE equ 4
    endif
    DMCOLLATE_FALSE equ 0
    DMCOLLATE_TRUE equ 1
    if (WINVER ge 0501h)
      DMDO_DEFAULT equ 0
      DMDO_90 equ 1
      DMDO_180 equ 2
      DMDO_270 equ 3
      DMDFO_DEFAULT equ 0
      DMDFO_STRETCH equ 1
      DMDFO_CENTER equ 2
    endif
    DM_INTERLACED equ 00000002h
    DMDISPLAYFLAGS_TEXTMODE equ 00000004h
    DMNUP_SYSTEM equ 1
    DMNUP_ONEUP equ 2
    if (WINVER ge 0400h)
      DMICMMETHOD_NONE equ 1
      DMICMMETHOD_SYSTEM equ 2
      DMICMMETHOD_DRIVER equ 3
      DMICMMETHOD_DEVICE equ 4
      DMICMMETHOD_USER equ 256
      DMICM_SATURATE equ 1
      DMICM_CONTRAST equ 2
      DMICM_COLORIMETRIC equ 3
      DMICM_ABS_COLORIMETRIC equ 4
      DMICM_USER equ 256
      DMMEDIA_STANDARD equ 1
      DMMEDIA_TRANSPARENCY equ 2
      DMMEDIA_GLOSSY equ 3
      DMMEDIA_USER equ 256
      DMDITHER_NONE equ 1
      DMDITHER_COARSE equ 2
      DMDITHER_FINE equ 3
      DMDITHER_LINEART equ 4
      DMDITHER_ERRORDIFFUSION equ 5
      DMDITHER_RESERVED6 equ 6
      DMDITHER_RESERVED7 equ 7
      DMDITHER_RESERVED8 equ 8
      DMDITHER_RESERVED9 equ 9
      DMDITHER_GRAYSCALE equ 10
      DMDITHER_USER equ 256
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      DISPLAY_DEVICEA struct
        cb DWORD ?
        DeviceName CHAR 32 dup (?)
        DeviceString CHAR 128 dup (?)
        StateFlags DWORD ?
        DeviceID CHAR 128 dup (?)
        DeviceKey CHAR 128 dup (?)
      DISPLAY_DEVICEA ends
      _DISPLAY_DEVICEA typedef DISPLAY_DEVICEA
      PDISPLAY_DEVICEA typedef ptr DISPLAY_DEVICEA
      LPDISPLAY_DEVICEA typedef ptr DISPLAY_DEVICEA
      DISPLAY_DEVICEW struct
        cb DWORD ?
        DeviceName WCHAR 32 dup (?)
        DeviceString WCHAR 128 dup (?)
        StateFlags DWORD ?
        DeviceID WCHAR 128 dup (?)
        DeviceKey WCHAR 128 dup (?)
      DISPLAY_DEVICEW ends
      _DISPLAY_DEVICEW typedef DISPLAY_DEVICEW
      PDISPLAY_DEVICEW typedef ptr DISPLAY_DEVICEW
      LPDISPLAY_DEVICEW typedef ptr DISPLAY_DEVICEW
      ifdef UNICODE
        DISPLAY_DEVICE typedef DISPLAY_DEVICEW
        PDISPLAY_DEVICE typedef PDISPLAY_DEVICEW
        LPDISPLAY_DEVICE typedef LPDISPLAY_DEVICEW
      else
        DISPLAY_DEVICE typedef DISPLAY_DEVICEA
        PDISPLAY_DEVICE typedef PDISPLAY_DEVICEA
        LPDISPLAY_DEVICE typedef LPDISPLAY_DEVICEA
      endif
    endif
    DISPLAY_DEVICE_ATTACHED_TO_DESKTOP equ 00000001h
    DISPLAY_DEVICE_MULTI_DRIVER equ 00000002h
    DISPLAY_DEVICE_PRIMARY_DEVICE equ 00000004h
    DISPLAY_DEVICE_MIRRORING_DRIVER equ 00000008h
    DISPLAY_DEVICE_VGA_COMPATIBLE equ 00000010h
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN2K)
      DISPLAY_DEVICE_REMOVABLE equ 00000020h
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
      DISPLAY_DEVICE_ACC_DRIVER equ 00000040h
    endif
    DISPLAY_DEVICE_MODESPRUNED equ 08000000h
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN2K)
      DISPLAY_DEVICE_RDPUDD equ 01000000h
      DISPLAY_DEVICE_REMOTE equ 04000000h
      DISPLAY_DEVICE_DISCONNECT equ 02000000h
    endif
    DISPLAY_DEVICE_TS_COMPATIBLE equ 00200000h
    if (_WIN32_WINNT ge _WIN32_WINNT_LONGHORN)
      DISPLAY_DEVICE_UNSAFE_MODES_ON equ 00080000h
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN2K)
      DISPLAY_DEVICE_ACTIVE equ 00000001h
      DISPLAY_DEVICE_ATTACHED equ 00000002h
    endif
    if (WINVER ge 0601h)
      DISPLAYCONFIG_MAXPATH equ 1024
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        DISPLAYCONFIG_RATIONAL struct
          Numerator UINT32 ?
          Denominator UINT32 ?
        DISPLAYCONFIG_RATIONAL ends
        DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY typedef SDWORD
        DISPLAYCONFIG_OUTPUT_TECHNOLOGY_OTHER equ -1
        DISPLAYCONFIG_OUTPUT_TECHNOLOGY_HD15 equ 0
        DISPLAYCONFIG_OUTPUT_TECHNOLOGY_SVIDEO equ 1
        DISPLAYCONFIG_OUTPUT_TECHNOLOGY_COMPOSITE_VIDEO equ 2
        DISPLAYCONFIG_OUTPUT_TECHNOLOGY_COMPONENT_VIDEO equ 3
        DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DVI equ 4
        DISPLAYCONFIG_OUTPUT_TECHNOLOGY_HDMI equ 5
        DISPLAYCONFIG_OUTPUT_TECHNOLOGY_LVDS equ 6
        DISPLAYCONFIG_OUTPUT_TECHNOLOGY_D_JPN equ 8
        DISPLAYCONFIG_OUTPUT_TECHNOLOGY_SDI equ 9
        DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DISPLAYPORT_EXTERNAL equ 10
        DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DISPLAYPORT_EMBEDDED equ 11
        DISPLAYCONFIG_OUTPUT_TECHNOLOGY_UDI_EXTERNAL equ 12
        DISPLAYCONFIG_OUTPUT_TECHNOLOGY_UDI_EMBEDDED equ 13
        DISPLAYCONFIG_OUTPUT_TECHNOLOGY_SDTVDONGLE equ 14
        DISPLAYCONFIG_OUTPUT_TECHNOLOGY_MIRACAST equ 15
        DISPLAYCONFIG_OUTPUT_TECHNOLOGY_INDIRECT_WIRED equ 16
        DISPLAYCONFIG_OUTPUT_TECHNOLOGY_INDIRECT_VIRTUAL equ 17
        DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DISPLAYPORT_USB_TUNNEL equ 18
        DISPLAYCONFIG_OUTPUT_TECHNOLOGY_INTERNAL equ 80000000h
        DISPLAYCONFIG_OUTPUT_TECHNOLOGY_FORCE_UINT32 equ 0FFFFFFFFh

        DISPLAYCONFIG_SCANLINE_ORDERING typedef SDWORD
        DISPLAYCONFIG_SCANLINE_ORDERING_UNSPECIFIED equ 0
        DISPLAYCONFIG_SCANLINE_ORDERING_PROGRESSIVE equ 1
        DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED equ 2
        DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED_UPPERFIELDFIRST equ DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED
        DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED_LOWERFIELDFIRST equ 3
        DISPLAYCONFIG_SCANLINE_ORDERING_FORCE_UINT32 equ 0FFFFFFFFh

        DISPLAYCONFIG_2DREGION struct
          cx_ UINT32 ?
          cy UINT32 ?
        DISPLAYCONFIG_2DREGION ends
        DISPLAYCONFIG_VIDEO_SIGNAL_INFO struct
          pixelRate UINT64 ?
          hSyncFreq DISPLAYCONFIG_RATIONAL <>
          vSyncFreq DISPLAYCONFIG_RATIONAL <>
          activeSize DISPLAYCONFIG_2DREGION <>
          totalSize DISPLAYCONFIG_2DREGION <>
          union
            struct AdditionalSignalInfo
              AdditionalSignalInfo_REC record AdditionalSignalInfo_REC_reserved:10, AdditionalSignalInfo_REC_vSyncFreqDivider:6, AdditionalSignalInfo_REC_videoStandard:16
              AdditionalSignalInfo_BITS AdditionalSignalInfo_REC <>
            ends
            videoStandard UINT32 ?
          ends
          scanLineOrdering DISPLAYCONFIG_SCANLINE_ORDERING ?
        DISPLAYCONFIG_VIDEO_SIGNAL_INFO ends
        DISPLAYCONFIG_SCALING typedef SDWORD
        DISPLAYCONFIG_SCALING_IDENTITY equ 1
        DISPLAYCONFIG_SCALING_CENTERED equ 2
        DISPLAYCONFIG_SCALING_STRETCHED equ 3
        DISPLAYCONFIG_SCALING_ASPECTRATIOCENTEREDMAX equ 4
        DISPLAYCONFIG_SCALING_CUSTOM equ 5
        DISPLAYCONFIG_SCALING_PREFERRED equ 128
        DISPLAYCONFIG_SCALING_FORCE_UINT32 equ 0FFFFFFFFh

        DISPLAYCONFIG_ROTATION typedef SDWORD
        DISPLAYCONFIG_ROTATION_IDENTITY equ 1
        DISPLAYCONFIG_ROTATION_ROTATE90 equ 2
        DISPLAYCONFIG_ROTATION_ROTATE180 equ 3
        DISPLAYCONFIG_ROTATION_ROTATE270 equ 4
        DISPLAYCONFIG_ROTATION_FORCE_UINT32 equ 0FFFFFFFFh

        DISPLAYCONFIG_MODE_INFO_TYPE typedef SDWORD
        DISPLAYCONFIG_MODE_INFO_TYPE_SOURCE equ 1
        DISPLAYCONFIG_MODE_INFO_TYPE_TARGET equ 2
        DISPLAYCONFIG_MODE_INFO_TYPE_DESKTOP_IMAGE equ 3
        DISPLAYCONFIG_MODE_INFO_TYPE_FORCE_UINT32 equ 0FFFFFFFFh

        DISPLAYCONFIG_PIXELFORMAT typedef SDWORD
        DISPLAYCONFIG_PIXELFORMAT_8BPP equ 1
        DISPLAYCONFIG_PIXELFORMAT_16BPP equ 2
        DISPLAYCONFIG_PIXELFORMAT_24BPP equ 3
        DISPLAYCONFIG_PIXELFORMAT_32BPP equ 4
        DISPLAYCONFIG_PIXELFORMAT_NONGDI equ 5
        DISPLAYCONFIG_PIXELFORMAT_FORCE_UINT32 equ 0ffffffffh

        DISPLAYCONFIG_SOURCE_MODE struct
          width_ UINT32 ?
          height UINT32 ?
          pixelFormat DISPLAYCONFIG_PIXELFORMAT ?
          position POINTL <>
        DISPLAYCONFIG_SOURCE_MODE ends
        DISPLAYCONFIG_TARGET_MODE struct
          targetVideoSignalInfo DISPLAYCONFIG_VIDEO_SIGNAL_INFO <>
        DISPLAYCONFIG_TARGET_MODE ends
        DISPLAYCONFIG_DESKTOP_IMAGE_INFO struct
          PathSourceSize POINTL <>
          DesktopImageRegion RECTL <>
          DesktopImageClip RECTL <>
        DISPLAYCONFIG_DESKTOP_IMAGE_INFO ends
        DISPLAYCONFIG_MODE_INFO struct
          infoType DISPLAYCONFIG_MODE_INFO_TYPE ?
          id UINT32 ?
          adapterId LUID <>
          union
            targetMode DISPLAYCONFIG_TARGET_MODE <>
            sourceMode DISPLAYCONFIG_SOURCE_MODE <>
            desktopImageInfo DISPLAYCONFIG_DESKTOP_IMAGE_INFO <>
          ends
        DISPLAYCONFIG_MODE_INFO ends
        DISPLAYCONFIG_PATH_MODE_IDX_INVALID equ 0ffffffffh
        DISPLAYCONFIG_PATH_TARGET_MODE_IDX_INVALID equ 0ffffh
        DISPLAYCONFIG_PATH_DESKTOP_IMAGE_IDX_INVALID equ 0ffffh
        DISPLAYCONFIG_PATH_SOURCE_MODE_IDX_INVALID equ 0ffffh
        DISPLAYCONFIG_PATH_CLONE_GROUP_INVALID equ 0ffffh
        DISPLAYCONFIG_PATH_SOURCE_INFO struct
          adapterId LUID <>
          id UINT32 ?
          union
            modeInfoIdx UINT32 ?
            struct
              ANONYMOUS_REC36 record ANONYMOUS_REC36_sourceModeInfoIdx:16, ANONYMOUS_REC36_cloneGroupId:16
              ANONYMOUS_REC36 <>
            ends
          ends
          statusFlags UINT32 ?
        DISPLAYCONFIG_PATH_SOURCE_INFO ends
        DISPLAYCONFIG_SOURCE_IN_USE equ 00000001h
        DISPLAYCONFIG_PATH_TARGET_INFO struct
          adapterId LUID <>
          id UINT32 ?
          union
            modeInfoIdx UINT32 ?
            struct
              ANONYMOUS_REC37 record ANONYMOUS_REC37_targetModeInfoIdx:16, ANONYMOUS_REC37_desktopModeInfoIdx:16
              ANONYMOUS_REC37 <>
            ends
          ends
          outputTechnology DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY ?
          rotation DISPLAYCONFIG_ROTATION ?
          scaling DISPLAYCONFIG_SCALING ?
          refreshRate DISPLAYCONFIG_RATIONAL <>
          scanLineOrdering DISPLAYCONFIG_SCANLINE_ORDERING ?
          targetAvailable BOOL ?
          statusFlags UINT32 ?
        DISPLAYCONFIG_PATH_TARGET_INFO ends
        DISPLAYCONFIG_TARGET_IN_USE equ 00000001h
        DISPLAYCONFIG_TARGET_FORCIBLE equ 00000002h
        DISPLAYCONFIG_TARGET_FORCED_AVAILABILITY_BOOT equ 00000004h
        DISPLAYCONFIG_TARGET_FORCED_AVAILABILITY_PATH equ 00000008h
        DISPLAYCONFIG_TARGET_FORCED_AVAILABILITY_SYSTEM equ 00000010h
        DISPLAYCONFIG_TARGET_IS_HMD equ 00000020h
        DISPLAYCONFIG_PATH_INFO struct
          sourceInfo DISPLAYCONFIG_PATH_SOURCE_INFO <>
          targetInfo DISPLAYCONFIG_PATH_TARGET_INFO <>
          flags UINT32 ?
        DISPLAYCONFIG_PATH_INFO ends
        DISPLAYCONFIG_PATH_ACTIVE equ 00000001h
        DISPLAYCONFIG_PATH_PREFERRED_UNSCALED equ 00000004h
        DISPLAYCONFIG_PATH_SUPPORT_VIRTUAL_MODE equ 00000008h
        DISPLAYCONFIG_PATH_VALID_FLAGS equ 0000001Dh
        DISPLAYCONFIG_TOPOLOGY_ID typedef SDWORD
        DISPLAYCONFIG_TOPOLOGY_INTERNAL equ 00000001h
        DISPLAYCONFIG_TOPOLOGY_CLONE equ 00000002h
        DISPLAYCONFIG_TOPOLOGY_EXTEND equ 00000004h
        DISPLAYCONFIG_TOPOLOGY_EXTERNAL equ 00000008h
        DISPLAYCONFIG_TOPOLOGY_FORCE_UINT32 equ 0FFFFFFFFh

        DISPLAYCONFIG_DEVICE_INFO_TYPE typedef SDWORD
        DISPLAYCONFIG_DEVICE_INFO_GET_SOURCE_NAME equ 1
        DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_NAME equ 2
        DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_PREFERRED_MODE equ 3
        DISPLAYCONFIG_DEVICE_INFO_GET_ADAPTER_NAME equ 4
        DISPLAYCONFIG_DEVICE_INFO_SET_TARGET_PERSISTENCE equ 5
        DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_BASE_TYPE equ 6
        DISPLAYCONFIG_DEVICE_INFO_GET_SUPPORT_VIRTUAL_RESOLUTION equ 7
        DISPLAYCONFIG_DEVICE_INFO_SET_SUPPORT_VIRTUAL_RESOLUTION equ 8
        DISPLAYCONFIG_DEVICE_INFO_GET_ADVANCED_COLOR_INFO equ 9
        DISPLAYCONFIG_DEVICE_INFO_SET_ADVANCED_COLOR_STATE equ 10
        DISPLAYCONFIG_DEVICE_INFO_GET_SDR_WHITE_LEVEL equ 11
        DISPLAYCONFIG_DEVICE_INFO_GET_MONITOR_SPECIALIZATION equ 12
        DISPLAYCONFIG_DEVICE_INFO_SET_MONITOR_SPECIALIZATION equ 13
        DISPLAYCONFIG_DEVICE_INFO_FORCE_UINT32 equ 0FFFFFFFFh

      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        DISPLAYCONFIG_DEVICE_INFO_HEADER struct
          type_ DISPLAYCONFIG_DEVICE_INFO_TYPE ?
          size_ UINT32 ?
          adapterId LUID <>
          id UINT32 ?
        DISPLAYCONFIG_DEVICE_INFO_HEADER ends
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        DISPLAYCONFIG_SOURCE_DEVICE_NAME struct
          header DISPLAYCONFIG_DEVICE_INFO_HEADER <>
          viewGdiDeviceName WCHAR CCHDEVICENAME dup (?)
        DISPLAYCONFIG_SOURCE_DEVICE_NAME ends
        DISPLAYCONFIG_TARGET_DEVICE_NAME_FLAGS struct
          union
            struct
              ANONYMOUS_REC38 record ANONYMOUS_REC38_reserved:29, ANONYMOUS_REC38_edidIdsValid:1, ANONYMOUS_REC38_friendlyNameForced:1, ANONYMOUS_REC38_friendlyNameFromEdid:1
              ANONYMOUS_REC38 <>
            ends
            value UINT32 ?
          ends
        DISPLAYCONFIG_TARGET_DEVICE_NAME_FLAGS ends
        DISPLAYCONFIG_TARGET_DEVICE_NAME struct
          header DISPLAYCONFIG_DEVICE_INFO_HEADER <>
          flags DISPLAYCONFIG_TARGET_DEVICE_NAME_FLAGS <>
          outputTechnology DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY ?
          edidManufactureId UINT16 ?
          edidProductCodeId UINT16 ?
          connectorInstance UINT32 ?
          monitorFriendlyDeviceName WCHAR 64 dup (?)
          monitorDevicePath WCHAR 128 dup (?)
        DISPLAYCONFIG_TARGET_DEVICE_NAME ends
        DISPLAYCONFIG_TARGET_PREFERRED_MODE struct
          header DISPLAYCONFIG_DEVICE_INFO_HEADER <>
          width_ UINT32 ?
          height UINT32 ?
          targetMode DISPLAYCONFIG_TARGET_MODE <>
        DISPLAYCONFIG_TARGET_PREFERRED_MODE ends
        DISPLAYCONFIG_ADAPTER_NAME struct
          header DISPLAYCONFIG_DEVICE_INFO_HEADER <>
          adapterDevicePath WCHAR 128 dup (?)
        DISPLAYCONFIG_ADAPTER_NAME ends
        DISPLAYCONFIG_TARGET_BASE_TYPE struct
          header DISPLAYCONFIG_DEVICE_INFO_HEADER <>
          baseOutputTechnology DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY ?
        DISPLAYCONFIG_TARGET_BASE_TYPE ends
        DISPLAYCONFIG_SET_TARGET_PERSISTENCE struct
          header DISPLAYCONFIG_DEVICE_INFO_HEADER <>
          union
            struct
              ANONYMOUS_REC39 record ANONYMOUS_REC39_reserved:31, ANONYMOUS_REC39_bootPersistenceOn:1
              ANONYMOUS_REC39 <>
            ends
            value UINT32 ?
          ends
        DISPLAYCONFIG_SET_TARGET_PERSISTENCE ends
        DISPLAYCONFIG_SUPPORT_VIRTUAL_RESOLUTION struct
          header DISPLAYCONFIG_DEVICE_INFO_HEADER <>
          union
            struct
              ANONYMOUS_REC40 record ANONYMOUS_REC40_reserved:31, ANONYMOUS_REC40_disableMonitorVirtualResolution:1
              ANONYMOUS_REC40 <>
            ends
            value UINT32 ?
          ends
        DISPLAYCONFIG_SUPPORT_VIRTUAL_RESOLUTION ends
        DISPLAYCONFIG_COLOR_ENCODING typedef SDWORD
        DISPLAYCONFIG_COLOR_ENCODING_RGB equ 0
        DISPLAYCONFIG_COLOR_ENCODING_YCBCR444 equ 1
        DISPLAYCONFIG_COLOR_ENCODING_YCBCR422 equ 2
        DISPLAYCONFIG_COLOR_ENCODING_YCBCR420 equ 3
        DISPLAYCONFIG_COLOR_ENCODING_INTENSITY equ 4
        DISPLAYCONFIG_COLOR_ENCODING_FORCE_UINT32 equ 0FFFFFFFFh
        _DISPLAYCONFIG_COLOR_ENCODING typedef DISPLAYCONFIG_COLOR_ENCODING

        DISPLAYCONFIG_GET_ADVANCED_COLOR_INFO struct
          header DISPLAYCONFIG_DEVICE_INFO_HEADER <>
          union
            struct
              ANONYMOUS_REC41 record ANONYMOUS_REC41_reserved:28, ANONYMOUS_REC41_advancedColorForceDisabled:1, ANONYMOUS_REC41_wideColorEnforced:1, ANONYMOUS_REC41_advancedColorEnabled:1, ANONYMOUS_REC41_advancedColorSupported:1
              ANONYMOUS_REC41 <>
            ends
            value UINT32 ?
          ends
          colorEncoding DISPLAYCONFIG_COLOR_ENCODING ?
          bitsPerColorChannel UINT32 ?
        DISPLAYCONFIG_GET_ADVANCED_COLOR_INFO ends
        _DISPLAYCONFIG_GET_ADVANCED_COLOR_INFO typedef DISPLAYCONFIG_GET_ADVANCED_COLOR_INFO
        DISPLAYCONFIG_SET_ADVANCED_COLOR_STATE struct
          header DISPLAYCONFIG_DEVICE_INFO_HEADER <>
          union
            struct
              ANONYMOUS_REC42 record ANONYMOUS_REC42_reserved:31, ANONYMOUS_REC42_enableAdvancedColor:1
              ANONYMOUS_REC42 <>
            ends
            value UINT32 ?
          ends
        DISPLAYCONFIG_SET_ADVANCED_COLOR_STATE ends
        _DISPLAYCONFIG_SET_ADVANCED_COLOR_STATE typedef DISPLAYCONFIG_SET_ADVANCED_COLOR_STATE
        DISPLAYCONFIG_SDR_WHITE_LEVEL struct
          header DISPLAYCONFIG_DEVICE_INFO_HEADER <>
          SDRWhiteLevel ULONG ?
        DISPLAYCONFIG_SDR_WHITE_LEVEL ends
        _DISPLAYCONFIG_SDR_WHITE_LEVEL typedef DISPLAYCONFIG_SDR_WHITE_LEVEL
        DISPLAYCONFIG_GET_MONITOR_SPECIALIZATION struct
          header DISPLAYCONFIG_DEVICE_INFO_HEADER <>
          union
            struct
              ANONYMOUS_REC43 record ANONYMOUS_REC43_reserved:29, ANONYMOUS_REC43_isSpecializationAvailableForSystem:1, ANONYMOUS_REC43_isSpecializationAvailableForMonitor:1, ANONYMOUS_REC43_isSpecializationEnabled:1
              ANONYMOUS_REC43 <>
            ends
            value UINT32 ?
          ends
        DISPLAYCONFIG_GET_MONITOR_SPECIALIZATION ends
        _DISPLAYCONFIG_GET_MONITOR_SPECIALIZATION typedef DISPLAYCONFIG_GET_MONITOR_SPECIALIZATION
        DISPLAYCONFIG_SET_MONITOR_SPECIALIZATION struct
          header DISPLAYCONFIG_DEVICE_INFO_HEADER <>
          union
            struct
              ANONYMOUS_REC44 record ANONYMOUS_REC44_reserved:31, ANONYMOUS_REC44_isSpecializationEnabled:1
              ANONYMOUS_REC44 <>
            ends
            value UINT32 ?
          ends
          specializationType GUID <>
          specializationSubType GUID <>
          specializationApplicationName WCHAR 128 dup (?)
        DISPLAYCONFIG_SET_MONITOR_SPECIALIZATION ends
        _DISPLAYCONFIG_SET_MONITOR_SPECIALIZATION typedef DISPLAYCONFIG_SET_MONITOR_SPECIALIZATION
      endif
      QDC_ALL_PATHS equ 00000001h
      QDC_ONLY_ACTIVE_PATHS equ 00000002h
      QDC_DATABASE_CURRENT equ 00000004h
      QDC_VIRTUAL_MODE_AWARE equ 00000010h
      QDC_INCLUDE_HMD equ 00000020h
      QDC_VIRTUAL_REFRESH_RATE_AWARE equ 00000040h
      SDC_TOPOLOGY_INTERNAL equ 00000001h
      SDC_TOPOLOGY_CLONE equ 00000002h
      SDC_TOPOLOGY_EXTEND equ 00000004h
      SDC_TOPOLOGY_EXTERNAL equ 00000008h
      SDC_TOPOLOGY_SUPPLIED equ 00000010h
      SDC_USE_DATABASE_CURRENT equ <(SDC_TOPOLOGY_INTERNAL or SDC_TOPOLOGY_CLONE or SDC_TOPOLOGY_EXTEND or SDC_TOPOLOGY_EXTERNAL)>
      SDC_USE_SUPPLIED_DISPLAY_CONFIG equ 00000020h
      SDC_VALIDATE equ 00000040h
      SDC_APPLY equ 00000080h
      SDC_NO_OPTIMIZATION equ 00000100h
      SDC_SAVE_TO_DATABASE equ 00000200h
      SDC_ALLOW_CHANGES equ 00000400h
      SDC_PATH_PERSIST_IF_REQUIRED equ 00000800h
      SDC_FORCE_MODE_ENUMERATION equ 00001000h
      SDC_ALLOW_PATH_ORDER_CHANGES equ 00002000h
      SDC_VIRTUAL_MODE_AWARE equ 00008000h
      SDC_VIRTUAL_REFRESH_RATE_AWARE equ 00020000h
    endif
    RDH_RECTANGLES equ 1
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      RGNDATAHEADER struct
        dwSize DWORD ?
        iType DWORD ?
        nCount DWORD ?
        nRgnSize DWORD ?
        rcBound RECT <>
      RGNDATAHEADER ends
      _RGNDATAHEADER typedef RGNDATAHEADER
      PRGNDATAHEADER typedef ptr RGNDATAHEADER
      RGNDATA struct
        rdh RGNDATAHEADER <>
        Buffer SBYTE 1 dup (?)
      RGNDATA ends
      _RGNDATA typedef RGNDATA
      PRGNDATA typedef ptr RGNDATA
      NPRGNDATA typedef ptr RGNDATA
      LPRGNDATA typedef ptr RGNDATA
    endif
    SYSRGN equ 4
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ABC struct
        abcA SDWORD ?
        abcB UINT ?
        abcC SDWORD ?
      ABC ends
      _ABC typedef ABC
      PABC typedef ptr ABC
      NPABC typedef ptr ABC
      LPABC typedef ptr ABC
      ABCFLOAT struct
        abcfA FLOAT ?
        abcfB FLOAT ?
        abcfC FLOAT ?
      ABCFLOAT ends
      _ABCFLOAT typedef ABCFLOAT
      PABCFLOAT typedef ptr ABCFLOAT
      NPABCFLOAT typedef ptr ABCFLOAT
      LPABCFLOAT typedef ptr ABCFLOAT
    endif
    ifndef NOTEXTMETRIC
      ifdef _MAC
        ;[...]
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        OUTLINETEXTMETRICA struct
          otmSize UINT ?
          otmTextMetrics TEXTMETRICA <>
          otmFiller BYTE ?
          otmPanoseNumber PANOSE <>
          otmfsSelection UINT ?
          otmfsType UINT ?
          otmsCharSlopeRise SDWORD ?
          otmsCharSlopeRun SDWORD ?
          otmItalicAngle SDWORD ?
          otmEMSquare UINT ?
          otmAscent SDWORD ?
          otmDescent SDWORD ?
          otmLineGap UINT ?
          otmsCapEmHeight UINT ?
          otmsXHeight UINT ?
          otmrcFontBox RECT <>
          otmMacAscent SDWORD ?
          otmMacDescent SDWORD ?
          otmMacLineGap UINT ?
          otmusMinimumPPEM UINT ?
          otmptSubscriptSize POINT <>
          otmptSubscriptOffset POINT <>
          otmptSuperscriptSize POINT <>
          otmptSuperscriptOffset POINT <>
          otmsStrikeoutSize UINT ?
          otmsStrikeoutPosition SDWORD ?
          otmsUnderscoreSize SDWORD ?
          otmsUnderscorePosition SDWORD ?
          otmpFamilyName PSTR ?
          otmpFaceName PSTR ?
          otmpStyleName PSTR ?
          otmpFullName PSTR ?
        OUTLINETEXTMETRICA ends
        _OUTLINETEXTMETRICA typedef OUTLINETEXTMETRICA
        POUTLINETEXTMETRICA typedef ptr OUTLINETEXTMETRICA
        NPOUTLINETEXTMETRICA typedef ptr OUTLINETEXTMETRICA
        LPOUTLINETEXTMETRICA typedef ptr OUTLINETEXTMETRICA
        OUTLINETEXTMETRICW struct
          otmSize UINT ?
          otmTextMetrics TEXTMETRICW <>
          otmFiller BYTE ?
          otmPanoseNumber PANOSE <>
          otmfsSelection UINT ?
          otmfsType UINT ?
          otmsCharSlopeRise SDWORD ?
          otmsCharSlopeRun SDWORD ?
          otmItalicAngle SDWORD ?
          otmEMSquare UINT ?
          otmAscent SDWORD ?
          otmDescent SDWORD ?
          otmLineGap UINT ?
          otmsCapEmHeight UINT ?
          otmsXHeight UINT ?
          otmrcFontBox RECT <>
          otmMacAscent SDWORD ?
          otmMacDescent SDWORD ?
          otmMacLineGap UINT ?
          otmusMinimumPPEM UINT ?
          otmptSubscriptSize POINT <>
          otmptSubscriptOffset POINT <>
          otmptSuperscriptSize POINT <>
          otmptSuperscriptOffset POINT <>
          otmsStrikeoutSize UINT ?
          otmsStrikeoutPosition SDWORD ?
          otmsUnderscoreSize SDWORD ?
          otmsUnderscorePosition SDWORD ?
          otmpFamilyName PSTR ?
          otmpFaceName PSTR ?
          otmpStyleName PSTR ?
          otmpFullName PSTR ?
        OUTLINETEXTMETRICW ends
        _OUTLINETEXTMETRICW typedef OUTLINETEXTMETRICW
        POUTLINETEXTMETRICW typedef ptr OUTLINETEXTMETRICW
        NPOUTLINETEXTMETRICW typedef ptr OUTLINETEXTMETRICW
        LPOUTLINETEXTMETRICW typedef ptr OUTLINETEXTMETRICW
        ifdef UNICODE
          OUTLINETEXTMETRIC typedef OUTLINETEXTMETRICW
          POUTLINETEXTMETRIC typedef POUTLINETEXTMETRICW
          NPOUTLINETEXTMETRIC typedef NPOUTLINETEXTMETRICW
          LPOUTLINETEXTMETRIC typedef LPOUTLINETEXTMETRICW
        else
          OUTLINETEXTMETRIC typedef OUTLINETEXTMETRICA
          POUTLINETEXTMETRIC typedef POUTLINETEXTMETRICA
          NPOUTLINETEXTMETRIC typedef NPOUTLINETEXTMETRICA
          LPOUTLINETEXTMETRIC typedef LPOUTLINETEXTMETRICA
        endif
      endif
      ifdef _MAC
        ;[...]
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      POLYTEXTA struct
        x SDWORD ?
        y SDWORD ?
        n UINT ?
        lpstr LPCSTR ?
        uiFlags UINT ?
        rcl_ RECT <>
        pdx POINTER ?
      POLYTEXTA ends
      tagPOLYTEXTA typedef POLYTEXTA
      PPOLYTEXTA typedef ptr POLYTEXTA
      NPPOLYTEXTA typedef ptr POLYTEXTA
      LPPOLYTEXTA typedef ptr POLYTEXTA
      POLYTEXTW struct
        x SDWORD ?
        y SDWORD ?
        n UINT ?
        lpstr LPCWSTR ?
        uiFlags UINT ?
        rcl_ RECT <>
        pdx POINTER ?
      POLYTEXTW ends
      tagPOLYTEXTW typedef POLYTEXTW
      PPOLYTEXTW typedef ptr POLYTEXTW
      NPPOLYTEXTW typedef ptr POLYTEXTW
      LPPOLYTEXTW typedef ptr POLYTEXTW
      ifdef UNICODE
        POLYTEXT typedef POLYTEXTW
        PPOLYTEXT typedef PPOLYTEXTW
        NPPOLYTEXT typedef NPPOLYTEXTW
        LPPOLYTEXT typedef LPPOLYTEXTW
      else
        POLYTEXT typedef POLYTEXTA
        PPOLYTEXT typedef PPOLYTEXTA
        NPPOLYTEXT typedef NPPOLYTEXTA
        LPPOLYTEXT typedef LPPOLYTEXTA
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      FIXED struct
        ifndef _MAC
          fract WORD ?
          value SWORD ?
        else
          ;[...]
        endif
      FIXED ends
      _FIXED typedef FIXED
      MAT2 struct
        eM11 FIXED <>
        eM12 FIXED <>
        eM21 FIXED <>
        eM22 FIXED <>
      MAT2 ends
      _MAT2 typedef MAT2
      LPMAT2 typedef ptr MAT2
      GLYPHMETRICS struct
        gmBlackBoxX UINT ?
        gmBlackBoxY UINT ?
        gmptGlyphOrigin POINT <>
        gmCellIncX SWORD ?
        gmCellIncY SWORD ?
      GLYPHMETRICS ends
      _GLYPHMETRICS typedef GLYPHMETRICS
      LPGLYPHMETRICS typedef ptr GLYPHMETRICS
    endif
    GGO_METRICS equ 0
    GGO_BITMAP equ 1
    GGO_NATIVE equ 2
    GGO_BEZIER equ 3
    if (WINVER ge 0400h)
      GGO_GRAY2_BITMAP equ 4
      GGO_GRAY4_BITMAP equ 5
      GGO_GRAY8_BITMAP equ 6
      GGO_GLYPH_INDEX equ 0080h
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN2K)
      GGO_UNHINTED equ 0100h
    endif
    TT_POLYGON_TYPE equ 24
    TT_PRIM_LINE equ 1
    TT_PRIM_QSPLINE equ 2
    TT_PRIM_CSPLINE equ 3
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      POINTFX struct
        x FIXED <>
        y FIXED <>
      POINTFX ends
      tagPOINTFX typedef POINTFX
      LPPOINTFX typedef ptr POINTFX
      TTPOLYCURVE struct
        wType WORD ?
        cpfx WORD ?
        apfx POINTFX 1 dup (<>)
      TTPOLYCURVE ends
      tagTTPOLYCURVE typedef TTPOLYCURVE
      LPTTPOLYCURVE typedef ptr TTPOLYCURVE
      TTPOLYGONHEADER struct
        cb DWORD ?
        dwType DWORD ?
        pfxStart POINTFX <>
      TTPOLYGONHEADER ends
      tagTTPOLYGONHEADER typedef TTPOLYGONHEADER
      LPTTPOLYGONHEADER typedef ptr TTPOLYGONHEADER
    endif
    if (WINVER ge 0400h)
      GCP_DBCS equ 0001h
      GCP_REORDER equ 0002h
      GCP_USEKERNING equ 0008h
      GCP_GLYPHSHAPE equ 0010h
      GCP_LIGATE equ 0020h
      GCP_DIACRITIC equ 0100h
      GCP_KASHIDA equ 0400h
      GCP_ERROR equ 8000h
      FLI_MASK equ 103Bh
      GCP_JUSTIFY equ 00010000h
      FLI_GLYPHS equ 00040000h
      GCP_CLASSIN equ 00080000h
      GCP_MAXEXTENT equ 00100000h
      GCP_JUSTIFYIN equ 00200000h
      GCP_DISPLAYZWG equ 00400000h
      GCP_SYMSWAPOFF equ 00800000h
      GCP_NUMERICOVERRIDE equ 01000000h
      GCP_NEUTRALOVERRIDE equ 02000000h
      GCP_NUMERICSLATIN equ 04000000h
      GCP_NUMERICSLOCAL equ 08000000h
      GCPCLASS_LATIN equ 1
      GCPCLASS_HEBREW equ 2
      GCPCLASS_ARABIC equ 2
      GCPCLASS_NEUTRAL equ 3
      GCPCLASS_LOCALNUMBER equ 4
      GCPCLASS_LATINNUMBER equ 5
      GCPCLASS_LATINNUMERICTERMINATOR equ 6
      GCPCLASS_LATINNUMERICSEPARATOR equ 7
      GCPCLASS_NUMERICSEPARATOR equ 8
      GCPCLASS_PREBOUNDLTR equ 80h
      GCPCLASS_PREBOUNDRTL equ 40h
      GCPCLASS_POSTBOUNDLTR equ 20h
      GCPCLASS_POSTBOUNDRTL equ 10h
      GCPGLYPH_LINKBEFORE equ 8000h
      GCPGLYPH_LINKAFTER equ 4000h
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        GCP_RESULTSA struct
          lStructSize DWORD ?
          lpOutString LPSTR ?
          lpOrder POINTER ?
          lpDx POINTER ?
          lpCaretPos POINTER ?
          lpClass LPSTR ?
          lpGlyphs LPWSTR ?
          nGlyphs UINT ?
          nMaxFit SDWORD ?
        GCP_RESULTSA ends
        tagGCP_RESULTSA typedef GCP_RESULTSA
        LPGCP_RESULTSA typedef ptr GCP_RESULTSA
        GCP_RESULTSW struct
          lStructSize DWORD ?
          lpOutString LPWSTR ?
          lpOrder POINTER ?
          lpDx POINTER ?
          lpCaretPos POINTER ?
          lpClass LPSTR ?
          lpGlyphs LPWSTR ?
          nGlyphs UINT ?
          nMaxFit SDWORD ?
        GCP_RESULTSW ends
        tagGCP_RESULTSW typedef GCP_RESULTSW
        LPGCP_RESULTSW typedef ptr GCP_RESULTSW
        ifdef UNICODE
          GCP_RESULTS typedef GCP_RESULTSW
          LPGCP_RESULTS typedef LPGCP_RESULTSW
        else
          GCP_RESULTS typedef GCP_RESULTSA
          LPGCP_RESULTS typedef LPGCP_RESULTSA
        endif
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      RASTERIZER_STATUS struct
        nSize SWORD ?
        wFlags SWORD ?
        nLanguageID SWORD ?
      RASTERIZER_STATUS ends
      _RASTERIZER_STATUS typedef RASTERIZER_STATUS
      LPRASTERIZER_STATUS typedef ptr RASTERIZER_STATUS
    endif
    TT_AVAILABLE equ 0001h
    TT_ENABLED equ 0002h
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      PIXELFORMATDESCRIPTOR struct
        nSize WORD ?
        nVersion WORD ?
        dwFlags DWORD ?
        iPixelType BYTE ?
        cColorBits BYTE ?
        cRedBits BYTE ?
        cRedShift BYTE ?
        cGreenBits BYTE ?
        cGreenShift BYTE ?
        cBlueBits BYTE ?
        cBlueShift BYTE ?
        cAlphaBits BYTE ?
        cAlphaShift BYTE ?
        cAccumBits BYTE ?
        cAccumRedBits BYTE ?
        cAccumGreenBits BYTE ?
        cAccumBlueBits BYTE ?
        cAccumAlphaBits BYTE ?
        cDepthBits BYTE ?
        cStencilBits BYTE ?
        cAuxBuffers BYTE ?
        iLayerType BYTE ?
        bReserved BYTE ?
        dwLayerMask DWORD ?
        dwVisibleMask DWORD ?
        dwDamageMask DWORD ?
      PIXELFORMATDESCRIPTOR ends
      tagPIXELFORMATDESCRIPTOR typedef PIXELFORMATDESCRIPTOR
      PPIXELFORMATDESCRIPTOR typedef ptr PIXELFORMATDESCRIPTOR
      LPPIXELFORMATDESCRIPTOR typedef ptr PIXELFORMATDESCRIPTOR
    endif
    PFD_TYPE_RGBA equ 0
    PFD_TYPE_COLORINDEX equ 1
    PFD_MAIN_PLANE equ 0
    PFD_OVERLAY_PLANE equ 1
    PFD_UNDERLAY_PLANE equ (- 1)
    PFD_DOUBLEBUFFER equ 00000001h
    PFD_STEREO equ 00000002h
    PFD_DRAW_TO_WINDOW equ 00000004h
    PFD_DRAW_TO_BITMAP equ 00000008h
    PFD_SUPPORT_GDI equ 00000010h
    PFD_SUPPORT_OPENGL equ 00000020h
    PFD_GENERIC_FORMAT equ 00000040h
    PFD_NEED_PALETTE equ 00000080h
    PFD_NEED_SYSTEM_PALETTE equ 00000100h
    PFD_SWAP_EXCHANGE equ 00000200h
    PFD_SWAP_COPY equ 00000400h
    PFD_SWAP_LAYER_BUFFERS equ 00000800h
    PFD_GENERIC_ACCELERATED equ 00001000h
    PFD_SUPPORT_DIRECTDRAW equ 00002000h
    PFD_DIRECT3D_ACCELERATED equ 00004000h
    PFD_SUPPORT_COMPOSITION equ 00008000h
    PFD_DEPTH_DONTCARE equ 20000000h
    PFD_DOUBLEBUFFER_DONTCARE equ 40000000h
    PFD_STEREO_DONTCARE equ 80000000h
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ifdef STRICT
        if  not Defined(NOTEXTMETRIC)
          TYPE_OLDFONTENUMPROCA typedef proto WIN_STD_CALL_CONV :ptr LOGFONTA, :ptr TEXTMETRICA, :DWORD, :LPARAM
          OLDFONTENUMPROCA typedef ptr TYPE_OLDFONTENUMPROCA

          TYPE_OLDFONTENUMPROCW typedef proto WIN_STD_CALL_CONV :ptr LOGFONTW, :ptr TEXTMETRICW, :DWORD, :LPARAM
          OLDFONTENUMPROCW typedef ptr TYPE_OLDFONTENUMPROCW

          ifdef UNICODE
            OLDFONTENUMPROC equ <OLDFONTENUMPROCW>
          else
            OLDFONTENUMPROC equ <OLDFONTENUMPROCA>
          endif
        else
          TYPE_OLDFONTENUMPROCA typedef proto WIN_STD_CALL_CONV :ptr LOGFONTA, :ptr VOID, :DWORD, :LPARAM
          OLDFONTENUMPROCA typedef ptr TYPE_OLDFONTENUMPROCA

          TYPE_OLDFONTENUMPROCW typedef proto WIN_STD_CALL_CONV :ptr LOGFONTW, :ptr VOID, :DWORD, :LPARAM
          OLDFONTENUMPROCW typedef ptr TYPE_OLDFONTENUMPROCW

          ifdef UNICODE
            OLDFONTENUMPROC equ <OLDFONTENUMPROCW>
          else
            OLDFONTENUMPROC equ <OLDFONTENUMPROCA>
          endif
        endif
        FONTENUMPROCA typedef OLDFONTENUMPROCA
        FONTENUMPROCW typedef OLDFONTENUMPROCW
        ifdef UNICODE
          FONTENUMPROC typedef FONTENUMPROCW
        else
          FONTENUMPROC typedef FONTENUMPROCA
        endif
        TYPE_GOBJENUMPROC typedef proto WIN_STD_CALL_CONV :LPVOID, :LPARAM
        GOBJENUMPROC typedef ptr TYPE_GOBJENUMPROC

        TYPE_LINEDDAPROC typedef proto WIN_STD_CALL_CONV :SDWORD, :SDWORD, :LPARAM
        LINEDDAPROC typedef ptr TYPE_LINEDDAPROC

      else
        OLDFONTENUMPROC typedef FARPROC
        FONTENUMPROCA typedef FARPROC
        FONTENUMPROCW typedef FARPROC
        ifdef UNICODE
          FONTENUMPROC typedef FONTENUMPROCW
        else
          FONTENUMPROC typedef FONTENUMPROCA
        endif
        GOBJENUMPROC typedef FARPROC
        LINEDDAPROC typedef FARPROC
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, AddFontResourceA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
      @DefProto DllImport, AddFontResourceW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
      ifdef UNICODE
        AddFontResource equ <AddFontResourceW>
      else
        AddFontResource equ <AddFontResourceA>
      endif
      @DefProto DllImport, AnimatePalette, WIN_STD_CALL_CONV,, <:HPALETTE, :UINT, :UINT, :ptr PALETTEENTRY>, 16
      @DefProto DllImport, Arc, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD>, 36
      @DefProto DllImport, BitBlt, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :HDC, :SDWORD, :SDWORD, :DWORD>, 36
      @DefProto DllImport, CancelDC, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, Chord, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD>, 36
      @DefProto DllImport, ChoosePixelFormat, WIN_STD_CALL_CONV,, <:HDC, :ptr PIXELFORMATDESCRIPTOR>, 8
      @DefProto DllImport, CloseMetaFile, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, CombineRgn, WIN_STD_CALL_CONV,, <:HRGN, :HRGN, :HRGN, :SDWORD>, 16
      @DefProto DllImport, CopyMetaFileA, WIN_STD_CALL_CONV,, <:HMETAFILE, :LPCSTR>, 8
      @DefProto DllImport, CopyMetaFileW, WIN_STD_CALL_CONV,, <:HMETAFILE, :LPCWSTR>, 8
      ifdef UNICODE
        CopyMetaFile equ <CopyMetaFileW>
      else
        CopyMetaFile equ <CopyMetaFileA>
      endif
      @DefProto DllImport, CreateBitmap, WIN_STD_CALL_CONV,, <:SDWORD, :SDWORD, :UINT, :UINT, :ptr VOID>, 20
      @DefProto DllImport, CreateBitmapIndirect, WIN_STD_CALL_CONV,, <:ptr BITMAP>, 4
      @DefProto DllImport, CreateBrushIndirect, WIN_STD_CALL_CONV,, <:ptr LOGBRUSH>, 4
      @DefProto DllImport, CreateCompatibleBitmap, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD>, 12
      @DefProto DllImport, CreateDiscardableBitmap, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD>, 12
      @DefProto DllImport, CreateCompatibleDC, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, CreateDCA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :LPCSTR, :ptr DEVMODEA>, 16
      @DefProto DllImport, CreateDCW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPCWSTR, :ptr DEVMODEW>, 16
      ifdef UNICODE
        CreateDC equ <CreateDCW>
      else
        CreateDC equ <CreateDCA>
      endif
      @DefProto DllImport, CreateDIBitmap, WIN_STD_CALL_CONV,, <:HDC, :ptr BITMAPINFOHEADER, :DWORD, :ptr VOID, :ptr BITMAPINFO, :UINT>, 24
      @DefProto DllImport, CreateDIBPatternBrush, WIN_STD_CALL_CONV,, <:HGLOBAL, :UINT>, 8
      @DefProto DllImport, CreateDIBPatternBrushPt, WIN_STD_CALL_CONV,, <:ptr VOID, :UINT>, 8
      @DefProto DllImport, CreateEllipticRgn, WIN_STD_CALL_CONV,, <:SDWORD, :SDWORD, :SDWORD, :SDWORD>, 16
      @DefProto DllImport, CreateEllipticRgnIndirect, WIN_STD_CALL_CONV,, <:ptr RECT>, 4
      @DefProto DllImport, CreateFontIndirectA, WIN_STD_CALL_CONV,, <:ptr LOGFONTA>, 4
      @DefProto DllImport, CreateFontIndirectW, WIN_STD_CALL_CONV,, <:ptr LOGFONTW>, 4
      ifdef UNICODE
        CreateFontIndirect equ <CreateFontIndirectW>
      else
        CreateFontIndirect equ <CreateFontIndirectA>
      endif
      @DefProto DllImport, CreateFontA, WIN_STD_CALL_CONV,, <:SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :LPCSTR>, 56
      @DefProto DllImport, CreateFontW, WIN_STD_CALL_CONV,, <:SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :LPCWSTR>, 56
      ifdef UNICODE
        CreateFont equ <CreateFontW>
      else
        CreateFont equ <CreateFontA>
      endif
      @DefProto DllImport, CreateHatchBrush, WIN_STD_CALL_CONV,, <:SDWORD, :COLORREF>, 8
      @DefProto DllImport, CreateICA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :LPCSTR, :ptr DEVMODEA>, 16
      @DefProto DllImport, CreateICW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPCWSTR, :ptr DEVMODEW>, 16
      ifdef UNICODE
        CreateIC equ <CreateICW>
      else
        CreateIC equ <CreateICA>
      endif
      @DefProto DllImport, CreateMetaFileA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
      @DefProto DllImport, CreateMetaFileW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
      ifdef UNICODE
        CreateMetaFile equ <CreateMetaFileW>
      else
        CreateMetaFile equ <CreateMetaFileA>
      endif
      @DefProto DllImport, CreatePalette, WIN_STD_CALL_CONV,, <:ptr LOGPALETTE>, 4
      @DefProto DllImport, CreatePen, WIN_STD_CALL_CONV,, <:SDWORD, :SDWORD, :COLORREF>, 12
      @DefProto DllImport, CreatePenIndirect, WIN_STD_CALL_CONV,, <:ptr LOGPEN>, 4
      @DefProto DllImport, CreatePolyPolygonRgn, WIN_STD_CALL_CONV,, <:ptr POINT, :ptr INT_, :SDWORD, :SDWORD>, 16
      @DefProto DllImport, CreatePatternBrush, WIN_STD_CALL_CONV,, <:HBITMAP>, 4
      @DefProto DllImport, CreateRectRgn, WIN_STD_CALL_CONV,, <:SDWORD, :SDWORD, :SDWORD, :SDWORD>, 16
      @DefProto DllImport, CreateRectRgnIndirect, WIN_STD_CALL_CONV,, <:ptr RECT>, 4
      @DefProto DllImport, CreateRoundRectRgn, WIN_STD_CALL_CONV,, <:SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD>, 24
      @DefProto DllImport, CreateScalableFontResourceA, WIN_STD_CALL_CONV,, <:DWORD, :LPCSTR, :LPCSTR, :LPCSTR>, 16
      @DefProto DllImport, CreateScalableFontResourceW, WIN_STD_CALL_CONV,, <:DWORD, :LPCWSTR, :LPCWSTR, :LPCWSTR>, 16
      ifdef UNICODE
        CreateScalableFontResource equ <CreateScalableFontResourceW>
      else
        CreateScalableFontResource equ <CreateScalableFontResourceA>
      endif
      @DefProto DllImport, CreateSolidBrush, WIN_STD_CALL_CONV,, <:COLORREF>, 4
      @DefProto DllImport, DeleteDC, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, DeleteMetaFile, WIN_STD_CALL_CONV,, <:HMETAFILE>, 4
      @DefProto DllImport, DeleteObject, WIN_STD_CALL_CONV,, <:HGDIOBJ>, 4
      @DefProto DllImport, DescribePixelFormat, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :UINT, :LPPIXELFORMATDESCRIPTOR>, 16
      TYPE_LPFNDEVMODE typedef proto WIN_STD_CALL_CONV :HWND, :HMODULE, :LPDEVMODE, :LPSTR, :LPSTR, :LPDEVMODE, :LPSTR, :UINT
      LPFNDEVMODE typedef ptr TYPE_LPFNDEVMODE

      TYPE_LPFNDEVCAPS typedef proto WIN_STD_CALL_CONV :LPSTR, :LPSTR, :UINT, :LPSTR, :LPDEVMODE
      LPFNDEVCAPS typedef ptr TYPE_LPFNDEVCAPS

    endif
    DM_UPDATE equ 1
    DM_COPY equ 2
    DM_PROMPT equ 4
    DM_MODIFY equ 8
    DM_IN_BUFFER equ <DM_MODIFY>
    DM_IN_PROMPT equ <DM_PROMPT>
    DM_OUT_BUFFER equ <DM_COPY>
    DM_OUT_DEFAULT equ <DM_UPDATE>
    DC_FIELDS equ 1
    DC_PAPERS equ 2
    DC_PAPERSIZE equ 3
    DC_MINEXTENT equ 4
    DC_MAXEXTENT equ 5
    DC_BINS equ 6
    DC_DUPLEX equ 7
    DC_SIZE equ 8
    DC_EXTRA equ 9
    DC_VERSION equ 10
    DC_DRIVER equ 11
    DC_BINNAMES equ 12
    DC_ENUMRESOLUTIONS equ 13
    DC_FILEDEPENDENCIES equ 14
    DC_TRUETYPE equ 15
    DC_PAPERNAMES equ 16
    DC_ORIENTATION equ 17
    DC_COPIES equ 18
    if (WINVER ge 0400h)
      DC_BINADJUST equ 19
      DC_EMF_COMPLIANT equ 20
      DC_DATATYPE_PRODUCED equ 21
      DC_COLLATE equ 22
      DC_MANUFACTURER equ 23
      DC_MODEL equ 24
    endif
    if (WINVER ge 0500h)
      DC_PERSONALITY equ 25
      DC_PRINTRATE equ 26
      DC_PRINTRATEUNIT equ 27
      PRINTRATEUNIT_PPM equ 1
      PRINTRATEUNIT_CPS equ 2
      PRINTRATEUNIT_LPM equ 3
      PRINTRATEUNIT_IPM equ 4
      DC_PRINTERMEM equ 28
      DC_MEDIAREADY equ 29
      DC_STAPLE equ 30
      DC_PRINTRATEPPM equ 31
      DC_COLORDEVICE equ 32
      DC_NUP equ 33
      if (_WIN32_WINNT ge _WIN32_WINNT_WIN2K)
        DC_MEDIATYPENAMES equ 34
        DC_MEDIATYPES equ 35
      endif
    endif
    DCTT_BITMAP equ 0000001h
    DCTT_DOWNLOAD equ 0000002h
    DCTT_SUBDEV equ 0000004h
    if (WINVER ge 0400h)
      DCTT_DOWNLOAD_OUTLINE equ 0000008h
      DCBA_FACEUPNONE equ 0000h
      DCBA_FACEUPCENTER equ 0001h
      DCBA_FACEUPLEFT equ 0002h
      DCBA_FACEUPRIGHT equ 0003h
      DCBA_FACEDOWNNONE equ 0100h
      DCBA_FACEDOWNCENTER equ 0101h
      DCBA_FACEDOWNLEFT equ 0102h
      DCBA_FACEDOWNRIGHT equ 0103h
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, DeviceCapabilitiesA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :WORD, :LPSTR, :ptr DEVMODEA>, 20
      @DefProto DllImport, DeviceCapabilitiesW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :WORD, :LPWSTR, :ptr DEVMODEW>, 20
      ifdef UNICODE
        DeviceCapabilities equ <DeviceCapabilitiesW>
      else
        DeviceCapabilities equ <DeviceCapabilitiesA>
      endif
      @DefProto DllImport, DrawEscape, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :LPCSTR>, 16
      @DefProto DllImport, Ellipse, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :SDWORD, :SDWORD>, 20
      if (WINVER ge 0400h)
        @DefProto DllImport, EnumFontFamiliesExA, WIN_STD_CALL_CONV,, <:HDC, :LPLOGFONTA, :FONTENUMPROCA, :LPARAM, :DWORD>, 20
        @DefProto DllImport, EnumFontFamiliesExW, WIN_STD_CALL_CONV,, <:HDC, :LPLOGFONTW, :FONTENUMPROCW, :LPARAM, :DWORD>, 20
        ifdef UNICODE
          EnumFontFamiliesEx equ <EnumFontFamiliesExW>
        else
          EnumFontFamiliesEx equ <EnumFontFamiliesExA>
        endif
      endif
      @DefProto DllImport, EnumFontFamiliesA, WIN_STD_CALL_CONV,, <:HDC, :LPCSTR, :FONTENUMPROCA, :LPARAM>, 16
      @DefProto DllImport, EnumFontFamiliesW, WIN_STD_CALL_CONV,, <:HDC, :LPCWSTR, :FONTENUMPROCW, :LPARAM>, 16
      ifdef UNICODE
        EnumFontFamilies equ <EnumFontFamiliesW>
      else
        EnumFontFamilies equ <EnumFontFamiliesA>
      endif
      @DefProto DllImport, EnumFontsA, WIN_STD_CALL_CONV,, <:HDC, :LPCSTR, :FONTENUMPROCA, :LPARAM>, 16
      @DefProto DllImport, EnumFontsW, WIN_STD_CALL_CONV,, <:HDC, :LPCWSTR, :FONTENUMPROCW, :LPARAM>, 16
      ifdef UNICODE
        EnumFonts equ <EnumFontsW>
      else
        EnumFonts equ <EnumFontsA>
      endif
      ifdef STRICT
        @DefProto DllImport, EnumObjects, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :GOBJENUMPROC, :LPARAM>, 16
      else
        @DefProto DllImport, EnumObjects, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :GOBJENUMPROC, :LPVOID>, 16
      endif
      @DefProto DllImport, EqualRgn, WIN_STD_CALL_CONV,, <:HRGN, :HRGN>, 8
      @DefProto DllImport, Escape, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :LPCSTR, :LPVOID>, 20
      @DefProto DllImport, ExtEscape, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :LPCSTR, :SDWORD, :LPSTR>, 24
      @DefProto DllImport, ExcludeClipRect, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :SDWORD, :SDWORD>, 20
      @DefProto DllImport, ExtCreateRegion, WIN_STD_CALL_CONV,, <:ptr XFORM, :DWORD, :ptr RGNDATA>, 12
      @DefProto DllImport, ExtFloodFill, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :COLORREF, :UINT>, 20
      @DefProto DllImport, FillRgn, WIN_STD_CALL_CONV,, <:HDC, :HRGN, :HBRUSH>, 12
      @DefProto DllImport, FloodFill, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :COLORREF>, 16
      @DefProto DllImport, FrameRgn, WIN_STD_CALL_CONV,, <:HDC, :HRGN, :HBRUSH, :SDWORD, :SDWORD>, 20
      @DefProto DllImport, GetROP2, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, GetAspectRatioFilterEx, WIN_STD_CALL_CONV,, <:HDC, :LPSIZE>, 8
      @DefProto DllImport, GetBkColor, WIN_STD_CALL_CONV,, <:HDC>, 4
      if (_WIN32_WINNT ge _WIN32_WINNT_WIN2K)
        @DefProto DllImport, GetDCBrushColor, WIN_STD_CALL_CONV,, <:HDC>, 4
        @DefProto DllImport, GetDCPenColor, WIN_STD_CALL_CONV,, <:HDC>, 4
      endif
      @DefProto DllImport, GetBkMode, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, GetBitmapBits, WIN_STD_CALL_CONV,, <:HBITMAP, :LONG, :LPVOID>, 12
      @DefProto DllImport, GetBitmapDimensionEx, WIN_STD_CALL_CONV,, <:HBITMAP, :LPSIZE>, 8
      @DefProto DllImport, GetBoundsRect, WIN_STD_CALL_CONV,, <:HDC, :LPRECT, :UINT>, 12
      @DefProto DllImport, GetBrushOrgEx, WIN_STD_CALL_CONV,, <:HDC, :LPPOINT>, 8
      @DefProto DllImport, GetCharWidthA, WIN_STD_CALL_CONV,, <:HDC, :UINT, :UINT, :LPINT>, 16
      @DefProto DllImport, GetCharWidthW, WIN_STD_CALL_CONV,, <:HDC, :UINT, :UINT, :LPINT>, 16
      ifdef UNICODE
        GetCharWidth equ <GetCharWidthW>
      else
        GetCharWidth equ <GetCharWidthA>
      endif
      @DefProto DllImport, GetCharWidth32A, WIN_STD_CALL_CONV,, <:HDC, :UINT, :UINT, :LPINT>, 16
      @DefProto DllImport, GetCharWidth32W, WIN_STD_CALL_CONV,, <:HDC, :UINT, :UINT, :LPINT>, 16
      ifdef UNICODE
        GetCharWidth32 equ <GetCharWidth32W>
      else
        GetCharWidth32 equ <GetCharWidth32A>
      endif
      @DefProto DllImport, GetCharWidthFloatA, WIN_STD_CALL_CONV,, <:HDC, :UINT, :UINT, :PFLOAT>, 16
      @DefProto DllImport, GetCharWidthFloatW, WIN_STD_CALL_CONV,, <:HDC, :UINT, :UINT, :PFLOAT>, 16
      ifdef UNICODE
        GetCharWidthFloat equ <GetCharWidthFloatW>
      else
        GetCharWidthFloat equ <GetCharWidthFloatA>
      endif
      @DefProto DllImport, GetCharABCWidthsA, WIN_STD_CALL_CONV,, <:HDC, :UINT, :UINT, :LPABC>, 16
      @DefProto DllImport, GetCharABCWidthsW, WIN_STD_CALL_CONV,, <:HDC, :UINT, :UINT, :LPABC>, 16
      ifdef UNICODE
        GetCharABCWidths equ <GetCharABCWidthsW>
      else
        GetCharABCWidths equ <GetCharABCWidthsA>
      endif
      @DefProto DllImport, GetCharABCWidthsFloatA, WIN_STD_CALL_CONV,, <:HDC, :UINT, :UINT, :LPABCFLOAT>, 16
      @DefProto DllImport, GetCharABCWidthsFloatW, WIN_STD_CALL_CONV,, <:HDC, :UINT, :UINT, :LPABCFLOAT>, 16
      ifdef UNICODE
        GetCharABCWidthsFloat equ <GetCharABCWidthsFloatW>
      else
        GetCharABCWidthsFloat equ <GetCharABCWidthsFloatA>
      endif
      @DefProto DllImport, GetClipBox, WIN_STD_CALL_CONV,, <:HDC, :LPRECT>, 8
      @DefProto DllImport, GetClipRgn, WIN_STD_CALL_CONV,, <:HDC, :HRGN>, 8
      @DefProto DllImport, GetMetaRgn, WIN_STD_CALL_CONV,, <:HDC, :HRGN>, 8
      @DefProto DllImport, GetCurrentObject, WIN_STD_CALL_CONV,, <:HDC, :UINT>, 8
      @DefProto DllImport, GetCurrentPositionEx, WIN_STD_CALL_CONV,, <:HDC, :LPPOINT>, 8
      @DefProto DllImport, GetDeviceCaps, WIN_STD_CALL_CONV,, <:HDC, :SDWORD>, 8
      @DefProto DllImport, GetDIBits, WIN_STD_CALL_CONV,, <:HDC, :HBITMAP, :UINT, :UINT, :LPVOID, :LPBITMAPINFO, :UINT>, 28
      @DefProto DllImport, GetFontData, WIN_STD_CALL_CONV,, <:HDC, :DWORD, :DWORD, :PVOID, :DWORD>, 20
      @DefProto DllImport, GetGlyphOutlineA, WIN_STD_CALL_CONV,, <:HDC, :UINT, :UINT, :LPGLYPHMETRICS, :DWORD, :LPVOID, :ptr MAT2>, 28
      @DefProto DllImport, GetGlyphOutlineW, WIN_STD_CALL_CONV,, <:HDC, :UINT, :UINT, :LPGLYPHMETRICS, :DWORD, :LPVOID, :ptr MAT2>, 28
      ifdef UNICODE
        GetGlyphOutline equ <GetGlyphOutlineW>
      else
        GetGlyphOutline equ <GetGlyphOutlineA>
      endif
      @DefProto DllImport, GetGraphicsMode, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, GetMapMode, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, GetMetaFileBitsEx, WIN_STD_CALL_CONV,, <:HMETAFILE, :UINT, :LPVOID>, 12
      @DefProto DllImport, GetMetaFileA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
      @DefProto DllImport, GetMetaFileW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
      ifdef UNICODE
        GetMetaFile equ <GetMetaFileW>
      else
        GetMetaFile equ <GetMetaFileA>
      endif
      @DefProto DllImport, GetNearestColor, WIN_STD_CALL_CONV,, <:HDC, :COLORREF>, 8
      @DefProto DllImport, GetNearestPaletteIndex, WIN_STD_CALL_CONV,, <:HPALETTE, :COLORREF>, 8
      @DefProto DllImport, GetObjectType, WIN_STD_CALL_CONV,, <:HGDIOBJ>, 4
      ifndef NOTEXTMETRIC
        @DefProto DllImport, GetOutlineTextMetricsA, WIN_STD_CALL_CONV,, <:HDC, :UINT, :LPOUTLINETEXTMETRICA>, 12
        @DefProto DllImport, GetOutlineTextMetricsW, WIN_STD_CALL_CONV,, <:HDC, :UINT, :LPOUTLINETEXTMETRICW>, 12
        ifdef UNICODE
          GetOutlineTextMetrics equ <GetOutlineTextMetricsW>
        else
          GetOutlineTextMetrics equ <GetOutlineTextMetricsA>
        endif
      endif
      @DefProto DllImport, GetPaletteEntries, WIN_STD_CALL_CONV,, <:HPALETTE, :UINT, :UINT, :LPPALETTEENTRY>, 16
      @DefProto DllImport, GetPixel, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD>, 12
      @DefProto DllImport, GetPixelFormat, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, GetPolyFillMode, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, GetRasterizerCaps, WIN_STD_CALL_CONV,, <:LPRASTERIZER_STATUS, :UINT>, 8
      @DefProto DllImport, GetRandomRgn, WIN_STD_CALL_CONV,, <:HDC, :HRGN, :INT_>, 12
      @DefProto DllImport, GetRegionData, WIN_STD_CALL_CONV,, <:HRGN, :DWORD, :LPRGNDATA>, 12
      @DefProto DllImport, GetRgnBox, WIN_STD_CALL_CONV,, <:HRGN, :LPRECT>, 8
      @DefProto DllImport, GetStockObject, WIN_STD_CALL_CONV,, <:SDWORD>, 4
      @DefProto DllImport, GetStretchBltMode, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, GetSystemPaletteEntries, WIN_STD_CALL_CONV,, <:HDC, :UINT, :UINT, :LPPALETTEENTRY>, 16
      @DefProto DllImport, GetSystemPaletteUse, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, GetTextCharacterExtra, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, GetTextAlign, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, GetTextColor, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, GetTextExtentPointA, WIN_STD_CALL_CONV,, <:HDC, :LPCSTR, :SDWORD, :LPSIZE>, 16
      @DefProto DllImport, GetTextExtentPointW, WIN_STD_CALL_CONV,, <:HDC, :LPCWSTR, :SDWORD, :LPSIZE>, 16
      ifdef UNICODE
        GetTextExtentPoint equ <GetTextExtentPointW>
      else
        GetTextExtentPoint equ <GetTextExtentPointA>
      endif
      @DefProto DllImport, GetTextExtentPoint32A, WIN_STD_CALL_CONV,, <:HDC, :LPCSTR, :SDWORD, :LPSIZE>, 16
      @DefProto DllImport, GetTextExtentPoint32W, WIN_STD_CALL_CONV,, <:HDC, :LPCWSTR, :SDWORD, :LPSIZE>, 16
      ifdef UNICODE
        GetTextExtentPoint32 equ <GetTextExtentPoint32W>
      else
        GetTextExtentPoint32 equ <GetTextExtentPoint32A>
      endif
      @DefProto DllImport, GetTextExtentExPointA, WIN_STD_CALL_CONV,, <:HDC, :LPCSTR, :SDWORD, :SDWORD, :LPINT, :LPINT, :LPSIZE>, 28
      @DefProto DllImport, GetTextExtentExPointW, WIN_STD_CALL_CONV,, <:HDC, :LPCWSTR, :SDWORD, :SDWORD, :LPINT, :LPINT, :LPSIZE>, 28
      ifdef UNICODE
        GetTextExtentExPoint equ <GetTextExtentExPointW>
      else
        GetTextExtentExPoint equ <GetTextExtentExPointA>
      endif
      if (WINVER ge 0400h)
        @DefProto DllImport, GetTextCharset, WIN_STD_CALL_CONV,, <:HDC>, 4
        @DefProto DllImport, GetTextCharsetInfo, WIN_STD_CALL_CONV,, <:HDC, :LPFONTSIGNATURE, :DWORD>, 12
        @DefProto DllImport, TranslateCharsetInfo, WIN_STD_CALL_CONV,, <:ptr DWORD, :LPCHARSETINFO, :DWORD>, 12
        @DefProto DllImport, GetFontLanguageInfo, WIN_STD_CALL_CONV,, <:HDC>, 4
        @DefProto DllImport, GetCharacterPlacementA, WIN_STD_CALL_CONV,, <:HDC, :LPCSTR, :SDWORD, :SDWORD, :LPGCP_RESULTSA, :DWORD>, 24
        @DefProto DllImport, GetCharacterPlacementW, WIN_STD_CALL_CONV,, <:HDC, :LPCWSTR, :SDWORD, :SDWORD, :LPGCP_RESULTSW, :DWORD>, 24
        ifdef UNICODE
          GetCharacterPlacement equ <GetCharacterPlacementW>
        else
          GetCharacterPlacement equ <GetCharacterPlacementA>
        endif
      endif
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN2K)
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        WCRANGE struct
          wcLow WCHAR ?
          cGlyphs USHORT ?
        WCRANGE ends
        tagWCRANGE typedef WCRANGE
        PWCRANGE typedef ptr WCRANGE
        LPWCRANGE typedef ptr WCRANGE
        GLYPHSET struct
          cbThis DWORD ?
          flAccel DWORD ?
          cGlyphsSupported DWORD ?
          cRanges DWORD ?
          ranges WCRANGE 1 dup (<>)
        GLYPHSET ends
        tagGLYPHSET typedef GLYPHSET
        PGLYPHSET typedef ptr GLYPHSET
        LPGLYPHSET typedef ptr GLYPHSET
        GS_8BIT_INDICES equ 00000001h
        GGI_MARK_NONEXISTING_GLYPHS equ 0001h
        @DefProto DllImport, GetFontUnicodeRanges, WIN_STD_CALL_CONV,, <:HDC, :LPGLYPHSET>, 8
        @DefProto DllImport, GetGlyphIndicesA, WIN_STD_CALL_CONV,, <:HDC, :LPCSTR, :SDWORD, :LPWORD, :DWORD>, 20
        @DefProto DllImport, GetGlyphIndicesW, WIN_STD_CALL_CONV,, <:HDC, :LPCWSTR, :SDWORD, :LPWORD, :DWORD>, 20
        ifdef UNICODE
          GetGlyphIndices equ <GetGlyphIndicesW>
        else
          GetGlyphIndices equ <GetGlyphIndicesA>
        endif
        @DefProto DllImport, GetTextExtentPointI, WIN_STD_CALL_CONV,, <:HDC, :LPWORD, :SDWORD, :LPSIZE>, 16
        @DefProto DllImport, GetTextExtentExPointI, WIN_STD_CALL_CONV,, <:HDC, :LPWORD, :SDWORD, :SDWORD, :LPINT, :LPINT, :LPSIZE>, 28
        @DefProto DllImport, GetCharWidthI, WIN_STD_CALL_CONV,, <:HDC, :UINT, :UINT, :LPWORD, :LPINT>, 20
        @DefProto DllImport, GetCharABCWidthsI, WIN_STD_CALL_CONV,, <:HDC, :UINT, :UINT, :LPWORD, :LPABC>, 20
        STAMP_DESIGNVECTOR equ (8000000h + 'd' + ('v' shl 8))
        STAMP_AXESLIST equ (8000000h + 'a' + ('l' shl 8))
        STAMP_TRUETYPE_VARIATION equ (8000000h + 't' + ('v' shl 8))
        STAMP_CFF2 equ (8000000h + 'c' + ('v' shl 8))
        MM_MAX_NUMAXES equ 16
        DESIGNVECTOR struct
          dvReserved DWORD ?
          dvNumAxes DWORD ?
          dvValues LONG MM_MAX_NUMAXES dup (?)
        DESIGNVECTOR ends
        tagDESIGNVECTOR typedef DESIGNVECTOR
        PDESIGNVECTOR typedef ptr DESIGNVECTOR
        LPDESIGNVECTOR typedef ptr DESIGNVECTOR
        @DefProto DllImport, AddFontResourceExA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :PVOID>, 12
        @DefProto DllImport, AddFontResourceExW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :PVOID>, 12
        ifdef UNICODE
          AddFontResourceEx equ <AddFontResourceExW>
        else
          AddFontResourceEx equ <AddFontResourceExA>
        endif
        @DefProto DllImport, RemoveFontResourceExA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :PVOID>, 12
        @DefProto DllImport, RemoveFontResourceExW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :PVOID>, 12
        ifdef UNICODE
          RemoveFontResourceEx equ <RemoveFontResourceExW>
        else
          RemoveFontResourceEx equ <RemoveFontResourceExA>
        endif
        @DefProto DllImport, AddFontMemResourceEx, WIN_STD_CALL_CONV,, <:PVOID, :DWORD, :PVOID, :ptr DWORD>, 16
        @DefProto DllImport, RemoveFontMemResourceEx, WIN_STD_CALL_CONV,, <:HANDLE>, 4
        FR_PRIVATE equ 10h
        FR_NOT_ENUM equ 20h
        MM_MAX_AXES_NAMELEN equ 16
        AXISINFOA struct
          axMinValue LONG ?
          axMaxValue LONG ?
          axAxisName BYTE MM_MAX_AXES_NAMELEN dup (?)
        AXISINFOA ends
        tagAXISINFOA typedef AXISINFOA
        PAXISINFOA typedef ptr AXISINFOA
        LPAXISINFOA typedef ptr AXISINFOA
        AXISINFOW struct
          axMinValue LONG ?
          axMaxValue LONG ?
          axAxisName WCHAR MM_MAX_AXES_NAMELEN dup (?)
        AXISINFOW ends
        tagAXISINFOW typedef AXISINFOW
        PAXISINFOW typedef ptr AXISINFOW
        LPAXISINFOW typedef ptr AXISINFOW
        ifdef UNICODE
          AXISINFO typedef AXISINFOW
          PAXISINFO typedef PAXISINFOW
          LPAXISINFO typedef LPAXISINFOW
        else
          AXISINFO typedef AXISINFOA
          PAXISINFO typedef PAXISINFOA
          LPAXISINFO typedef LPAXISINFOA
        endif
        AXESLISTA struct
          axlReserved DWORD ?
          axlNumAxes DWORD ?
          axlAxisInfo AXISINFOA MM_MAX_NUMAXES dup (<>)
        AXESLISTA ends
        tagAXESLISTA typedef AXESLISTA
        PAXESLISTA typedef ptr AXESLISTA
        LPAXESLISTA typedef ptr AXESLISTA
        AXESLISTW struct
          axlReserved DWORD ?
          axlNumAxes DWORD ?
          axlAxisInfo AXISINFOW MM_MAX_NUMAXES dup (<>)
        AXESLISTW ends
        tagAXESLISTW typedef AXESLISTW
        PAXESLISTW typedef ptr AXESLISTW
        LPAXESLISTW typedef ptr AXESLISTW
        ifdef UNICODE
          AXESLIST typedef AXESLISTW
          PAXESLIST typedef PAXESLISTW
          LPAXESLIST typedef LPAXESLISTW
        else
          AXESLIST typedef AXESLISTA
          PAXESLIST typedef PAXESLISTA
          LPAXESLIST typedef LPAXESLISTA
        endif
        ENUMLOGFONTEXDVA struct
          elfEnumLogfontEx ENUMLOGFONTEXA <>
          elfDesignVector DESIGNVECTOR <>
        ENUMLOGFONTEXDVA ends
        tagENUMLOGFONTEXDVA typedef ENUMLOGFONTEXDVA
        PENUMLOGFONTEXDVA typedef ptr ENUMLOGFONTEXDVA
        LPENUMLOGFONTEXDVA typedef ptr ENUMLOGFONTEXDVA
        ENUMLOGFONTEXDVW struct
          elfEnumLogfontEx ENUMLOGFONTEXW <>
          elfDesignVector DESIGNVECTOR <>
        ENUMLOGFONTEXDVW ends
        tagENUMLOGFONTEXDVW typedef ENUMLOGFONTEXDVW
        PENUMLOGFONTEXDVW typedef ptr ENUMLOGFONTEXDVW
        LPENUMLOGFONTEXDVW typedef ptr ENUMLOGFONTEXDVW
        ifdef UNICODE
          ENUMLOGFONTEXDV typedef ENUMLOGFONTEXDVW
          PENUMLOGFONTEXDV typedef PENUMLOGFONTEXDVW
          LPENUMLOGFONTEXDV typedef LPENUMLOGFONTEXDVW
        else
          ENUMLOGFONTEXDV typedef ENUMLOGFONTEXDVA
          PENUMLOGFONTEXDV typedef PENUMLOGFONTEXDVA
          LPENUMLOGFONTEXDV typedef LPENUMLOGFONTEXDVA
        endif
        @DefProto DllImport, CreateFontIndirectExA, WIN_STD_CALL_CONV,, <:ptr ENUMLOGFONTEXDVA>, 4
        @DefProto DllImport, CreateFontIndirectExW, WIN_STD_CALL_CONV,, <:ptr ENUMLOGFONTEXDVW>, 4
        ifdef UNICODE
          CreateFontIndirectEx equ <CreateFontIndirectExW>
        else
          CreateFontIndirectEx equ <CreateFontIndirectExA>
        endif
        ifndef NOTEXTMETRIC
          ENUMTEXTMETRICA struct
            etmNewTextMetricEx NEWTEXTMETRICEXA <>
            etmAxesList AXESLISTA <>
          ENUMTEXTMETRICA ends
          tagENUMTEXTMETRICA typedef ENUMTEXTMETRICA
          PENUMTEXTMETRICA typedef ptr ENUMTEXTMETRICA
          LPENUMTEXTMETRICA typedef ptr ENUMTEXTMETRICA
          ENUMTEXTMETRICW struct
            etmNewTextMetricEx NEWTEXTMETRICEXW <>
            etmAxesList AXESLISTW <>
          ENUMTEXTMETRICW ends
          tagENUMTEXTMETRICW typedef ENUMTEXTMETRICW
          PENUMTEXTMETRICW typedef ptr ENUMTEXTMETRICW
          LPENUMTEXTMETRICW typedef ptr ENUMTEXTMETRICW
          ifdef UNICODE
            ENUMTEXTMETRIC typedef ENUMTEXTMETRICW
            PENUMTEXTMETRIC typedef PENUMTEXTMETRICW
            LPENUMTEXTMETRIC typedef LPENUMTEXTMETRICW
          else
            ENUMTEXTMETRIC typedef ENUMTEXTMETRICA
            PENUMTEXTMETRIC typedef PENUMTEXTMETRICA
            LPENUMTEXTMETRIC typedef LPENUMTEXTMETRICA
          endif
        endif
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, GetViewportExtEx, WIN_STD_CALL_CONV,, <:HDC, :LPSIZE>, 8
      @DefProto DllImport, GetViewportOrgEx, WIN_STD_CALL_CONV,, <:HDC, :LPPOINT>, 8
      @DefProto DllImport, GetWindowExtEx, WIN_STD_CALL_CONV,, <:HDC, :LPSIZE>, 8
      @DefProto DllImport, GetWindowOrgEx, WIN_STD_CALL_CONV,, <:HDC, :LPPOINT>, 8
      @DefProto DllImport, IntersectClipRect, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :SDWORD, :SDWORD>, 20
      @DefProto DllImport, InvertRgn, WIN_STD_CALL_CONV,, <:HDC, :HRGN>, 8
      @DefProto DllImport, LineDDA, WIN_STD_CALL_CONV,, <:SDWORD, :SDWORD, :SDWORD, :SDWORD, :LINEDDAPROC, :LPARAM>, 24
      @DefProto DllImport, LineTo, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD>, 12
      @DefProto DllImport, MaskBlt, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :HDC, :SDWORD, :SDWORD, :HBITMAP, :SDWORD, :SDWORD, :DWORD>, 48
      @DefProto DllImport, PlgBlt, WIN_STD_CALL_CONV,, <:HDC, :ptr POINT, :HDC, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :HBITMAP, :SDWORD, :SDWORD>, 40
      @DefProto DllImport, OffsetClipRgn, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD>, 12
      @DefProto DllImport, OffsetRgn, WIN_STD_CALL_CONV,, <:HRGN, :SDWORD, :SDWORD>, 12
      @DefProto DllImport, PatBlt, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :DWORD>, 24
      @DefProto DllImport, Pie, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD>, 36
      @DefProto DllImport, PlayMetaFile, WIN_STD_CALL_CONV,, <:HDC, :HMETAFILE>, 8
      @DefProto DllImport, PaintRgn, WIN_STD_CALL_CONV,, <:HDC, :HRGN>, 8
      @DefProto DllImport, PolyPolygon, WIN_STD_CALL_CONV,, <:HDC, :ptr POINT, :ptr INT_, :SDWORD>, 16
      @DefProto DllImport, PtInRegion, WIN_STD_CALL_CONV,, <:HRGN, :SDWORD, :SDWORD>, 12
      @DefProto DllImport, PtVisible, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD>, 12
      @DefProto DllImport, RectInRegion, WIN_STD_CALL_CONV,, <:HRGN, :ptr RECT>, 8
      @DefProto DllImport, RectVisible, WIN_STD_CALL_CONV,, <:HDC, :ptr RECT>, 8
      @DefProto DllImport, Rectangle, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :SDWORD, :SDWORD>, 20
      @DefProto DllImport, RestoreDC, WIN_STD_CALL_CONV,, <:HDC, :SDWORD>, 8
      @DefProto DllImport, ResetDCA, WIN_STD_CALL_CONV,, <:HDC, :ptr DEVMODEA>, 8
      @DefProto DllImport, ResetDCW, WIN_STD_CALL_CONV,, <:HDC, :ptr DEVMODEW>, 8
      ifdef UNICODE
        ResetDC equ <ResetDCW>
      else
        ResetDC equ <ResetDCA>
      endif
      @DefProto DllImport, RealizePalette, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, RemoveFontResourceA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
      @DefProto DllImport, RemoveFontResourceW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
      ifdef UNICODE
        RemoveFontResource equ <RemoveFontResourceW>
      else
        RemoveFontResource equ <RemoveFontResourceA>
      endif
      @DefProto DllImport, RoundRect, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD>, 28
      @DefProto DllImport, ResizePalette, WIN_STD_CALL_CONV,, <:HPALETTE, :UINT>, 8
      @DefProto DllImport, SaveDC, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, SelectClipRgn, WIN_STD_CALL_CONV,, <:HDC, :HRGN>, 8
      @DefProto DllImport, ExtSelectClipRgn, WIN_STD_CALL_CONV,, <:HDC, :HRGN, :SDWORD>, 12
      @DefProto DllImport, SetMetaRgn, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, SelectObject, WIN_STD_CALL_CONV,, <:HDC, :HGDIOBJ>, 8
      @DefProto DllImport, SelectPalette, WIN_STD_CALL_CONV,, <:HDC, :HPALETTE, :BOOL>, 12
      @DefProto DllImport, SetBkColor, WIN_STD_CALL_CONV,, <:HDC, :COLORREF>, 8
      if (_WIN32_WINNT ge _WIN32_WINNT_WIN2K)
        @DefProto DllImport, SetDCBrushColor, WIN_STD_CALL_CONV,, <:HDC, :COLORREF>, 8
        @DefProto DllImport, SetDCPenColor, WIN_STD_CALL_CONV,, <:HDC, :COLORREF>, 8
      endif
      @DefProto DllImport, SetBkMode, WIN_STD_CALL_CONV,, <:HDC, :SDWORD>, 8
      @DefProto DllImport, SetBitmapBits, WIN_STD_CALL_CONV,, <:HBITMAP, :DWORD, :ptr VOID>, 12
      @DefProto DllImport, SetBoundsRect, WIN_STD_CALL_CONV,, <:HDC, :ptr RECT, :UINT>, 12
      @DefProto DllImport, SetDIBits, WIN_STD_CALL_CONV,, <:HDC, :HBITMAP, :UINT, :UINT, :ptr VOID, :ptr BITMAPINFO, :UINT>, 28
      @DefProto DllImport, SetDIBitsToDevice, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :DWORD, :DWORD, :SDWORD, :SDWORD, :UINT, :UINT, :ptr VOID, :ptr BITMAPINFO, :UINT>, 48
      @DefProto DllImport, SetMapperFlags, WIN_STD_CALL_CONV,, <:HDC, :DWORD>, 8
      @DefProto DllImport, SetGraphicsMode, WIN_STD_CALL_CONV,, <:HDC, :SDWORD>, 8
      @DefProto DllImport, SetMapMode, WIN_STD_CALL_CONV,, <:HDC, :SDWORD>, 8
      if (WINVER ge 0500h)
        @DefProto DllImport, SetLayout, WIN_STD_CALL_CONV,, <:HDC, :DWORD>, 8
        @DefProto DllImport, GetLayout, WIN_STD_CALL_CONV,, <:HDC>, 4
      endif
      @DefProto DllImport, SetMetaFileBitsEx, WIN_STD_CALL_CONV,, <:UINT, :ptr BYTE>, 8
      @DefProto DllImport, SetPaletteEntries, WIN_STD_CALL_CONV,, <:HPALETTE, :UINT, :UINT, :ptr PALETTEENTRY>, 16
      @DefProto DllImport, SetPixel, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :COLORREF>, 16
      @DefProto DllImport, SetPixelV, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :COLORREF>, 16
      @DefProto DllImport, SetPixelFormat, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :ptr PIXELFORMATDESCRIPTOR>, 12
      @DefProto DllImport, SetPolyFillMode, WIN_STD_CALL_CONV,, <:HDC, :SDWORD>, 8
      @DefProto DllImport, StretchBlt, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :HDC, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :DWORD>, 44
      @DefProto DllImport, SetRectRgn, WIN_STD_CALL_CONV,, <:HRGN, :SDWORD, :SDWORD, :SDWORD, :SDWORD>, 20
      @DefProto DllImport, StretchDIBits, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :ptr VOID, :ptr BITMAPINFO, :UINT, :DWORD>, 52
      @DefProto DllImport, SetROP2, WIN_STD_CALL_CONV,, <:HDC, :SDWORD>, 8
      @DefProto DllImport, SetStretchBltMode, WIN_STD_CALL_CONV,, <:HDC, :SDWORD>, 8
      @DefProto DllImport, SetSystemPaletteUse, WIN_STD_CALL_CONV,, <:HDC, :UINT>, 8
      @DefProto DllImport, SetTextCharacterExtra, WIN_STD_CALL_CONV,, <:HDC, :SDWORD>, 8
      @DefProto DllImport, SetTextColor, WIN_STD_CALL_CONV,, <:HDC, :COLORREF>, 8
      @DefProto DllImport, SetTextAlign, WIN_STD_CALL_CONV,, <:HDC, :UINT>, 8
      @DefProto DllImport, SetTextJustification, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD>, 12
      @DefProto DllImport, UpdateColors, WIN_STD_CALL_CONV,, <:HDC>, 4
    endif
    ifdef COMBOX_SANDBOX
      if (_WIN32_WINNT ge 0600h)
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
          TYPE_GDIMARSHALLOC typedef proto WIN_STD_CALL_CONV :DWORD, :LPVOID
          GDIMARSHALLOC typedef ptr TYPE_GDIMARSHALLOC

          TYPE_DDRAWMARSHCALLBACKMARSHAL typedef proto WIN_STD_CALL_CONV :HGDIOBJ, :LPVOID, :ptr LPVOID
          DDRAWMARSHCALLBACKMARSHAL typedef ptr TYPE_DDRAWMARSHCALLBACKMARSHAL

          TYPE_DDRAWMARSHCALLBACKUNMARSHAL typedef proto WIN_STD_CALL_CONV :LPVOID, :ptr HDC, :ptr LPVOID
          DDRAWMARSHCALLBACKUNMARSHAL typedef ptr TYPE_DDRAWMARSHCALLBACKUNMARSHAL

          TYPE_DDRAWMARSHCALLBACKRELEASE typedef proto WIN_STD_CALL_CONV :LPVOID
          DDRAWMARSHCALLBACKRELEASE typedef ptr TYPE_DDRAWMARSHCALLBACKRELEASE

          GDIREGISTERDDRAWPACKETVERSION equ 1h
          GDIREGISTERDDRAWPACKET struct
            dwSize DWORD ?
            dwVersion DWORD ?
            pfnDdMarshal DDRAWMARSHCALLBACKMARSHAL ?
            pfnDdUnmarshal DDRAWMARSHCALLBACKUNMARSHAL ?
            pfnDdRelease DDRAWMARSHCALLBACKRELEASE ?
          GDIREGISTERDDRAWPACKET ends
          PGDIREGISTERDDRAWPACKET typedef ptr GDIREGISTERDDRAWPACKET
          @DefProto DllImport, GdiRegisterDdraw, WIN_STD_CALL_CONV,, <:PGDIREGISTERDDRAWPACKET, :ptr GDIMARSHALLOC>, 8
          @DefProto DllImport, GdiMarshalSize, WIN_STD_CALL_CONV,, <>, 0
          @DefProto DllImport, GdiMarshal, WIN_STD_CALL_CONV,, <:DWORD, :HGDIOBJ, :PVOID, :ULONG>, 16
          @DefProto DllImport, GdiUnmarshal, WIN_STD_CALL_CONV,, <:PVOID, :ULONG>, 8
        endif
      endif
    endif
    if (WINVER ge 0400h)
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        COLOR16 typedef USHORT
        TRIVERTEX struct
          x LONG ?
          y LONG ?
          Red COLOR16 ?
          Green COLOR16 ?
          Blue COLOR16 ?
          Alpha COLOR16 ?
        TRIVERTEX ends
        _TRIVERTEX typedef TRIVERTEX
        PTRIVERTEX typedef ptr TRIVERTEX
        LPTRIVERTEX typedef ptr TRIVERTEX
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        GRADIENT_TRIANGLE struct
          Vertex1 ULONG ?
          Vertex2 ULONG ?
          Vertex3 ULONG ?
        GRADIENT_TRIANGLE ends
        _GRADIENT_TRIANGLE typedef GRADIENT_TRIANGLE
        PGRADIENT_TRIANGLE typedef ptr GRADIENT_TRIANGLE
        LPGRADIENT_TRIANGLE typedef ptr GRADIENT_TRIANGLE
        GRADIENT_RECT struct
          UpperLeft ULONG ?
          LowerRight ULONG ?
        GRADIENT_RECT ends
        _GRADIENT_RECT typedef GRADIENT_RECT
        PGRADIENT_RECT typedef ptr GRADIENT_RECT
        LPGRADIENT_RECT typedef ptr GRADIENT_RECT
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        BLENDFUNCTION struct
          BlendOp BYTE ?
          BlendFlags BYTE ?
          SourceConstantAlpha BYTE ?
          AlphaFormat BYTE ?
        BLENDFUNCTION ends
        _BLENDFUNCTION typedef BLENDFUNCTION
        PBLENDFUNCTION typedef ptr BLENDFUNCTION
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        AC_SRC_OVER equ 00h
        AC_SRC_ALPHA equ 01h
        @DefProto DllImport, AlphaBlend, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :HDC, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :BLENDFUNCTION>, 44
        @DefProto DllImport, TransparentBlt, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :HDC, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :UINT>, 44
        GRADIENT_FILL_RECT_H equ 00000000h
        GRADIENT_FILL_RECT_V equ 00000001h
        GRADIENT_FILL_TRIANGLE equ 00000002h
        GRADIENT_FILL_OP_FLAG equ 000000ffh
        @DefProto DllImport, GradientFill, WIN_STD_CALL_CONV,, <:HDC, :PTRIVERTEX, :ULONG, :PVOID, :ULONG, :ULONG>, 24
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      if (_WIN32_WINNT ge _WIN32_WINNT_WIN2K)
        @DefProto DllImport, GdiAlphaBlend, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :HDC, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :BLENDFUNCTION>, 44
        @DefProto DllImport, GdiTransparentBlt, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :HDC, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :UINT>, 44
        @DefProto DllImport, GdiGradientFill, WIN_STD_CALL_CONV,, <:HDC, :PTRIVERTEX, :ULONG, :PVOID, :ULONG, :ULONG>, 24
      endif
      ifndef NOMETAFILE
        @DefProto DllImport, PlayMetaFileRecord, WIN_STD_CALL_CONV,, <:HDC, :LPHANDLETABLE, :LPMETARECORD, :UINT>, 16
        TYPE_MFENUMPROC typedef proto WIN_STD_CALL_CONV :HDC, :ptr HANDLETABLE, :ptr METARECORD, :SDWORD, :LPARAM
        MFENUMPROC typedef ptr TYPE_MFENUMPROC

        @DefProto DllImport, EnumMetaFile, WIN_STD_CALL_CONV,, <:HDC, :HMETAFILE, :MFENUMPROC, :LPARAM>, 16
        TYPE_ENHMFENUMPROC typedef proto WIN_STD_CALL_CONV :HDC, :ptr HANDLETABLE, :ptr ENHMETARECORD, :SDWORD, :LPARAM
        ENHMFENUMPROC typedef ptr TYPE_ENHMFENUMPROC

        @DefProto DllImport, CloseEnhMetaFile, WIN_STD_CALL_CONV,, <:HDC>, 4
        @DefProto DllImport, CopyEnhMetaFileA, WIN_STD_CALL_CONV,, <:HENHMETAFILE, :LPCSTR>, 8
        @DefProto DllImport, CopyEnhMetaFileW, WIN_STD_CALL_CONV,, <:HENHMETAFILE, :LPCWSTR>, 8
        ifdef UNICODE
          CopyEnhMetaFile equ <CopyEnhMetaFileW>
        else
          CopyEnhMetaFile equ <CopyEnhMetaFileA>
        endif
        @DefProto DllImport, CreateEnhMetaFileA, WIN_STD_CALL_CONV,, <:HDC, :LPCSTR, :ptr RECT, :LPCSTR>, 16
        @DefProto DllImport, CreateEnhMetaFileW, WIN_STD_CALL_CONV,, <:HDC, :LPCWSTR, :ptr RECT, :LPCWSTR>, 16
        ifdef UNICODE
          CreateEnhMetaFile equ <CreateEnhMetaFileW>
        else
          CreateEnhMetaFile equ <CreateEnhMetaFileA>
        endif
        @DefProto DllImport, DeleteEnhMetaFile, WIN_STD_CALL_CONV,, <:HENHMETAFILE>, 4
        @DefProto DllImport, EnumEnhMetaFile, WIN_STD_CALL_CONV,, <:HDC, :HENHMETAFILE, :ENHMFENUMPROC, :LPVOID, :ptr RECT>, 20
        @DefProto DllImport, GetEnhMetaFileA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
        @DefProto DllImport, GetEnhMetaFileW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
        ifdef UNICODE
          GetEnhMetaFile equ <GetEnhMetaFileW>
        else
          GetEnhMetaFile equ <GetEnhMetaFileA>
        endif
        @DefProto DllImport, GetEnhMetaFileBits, WIN_STD_CALL_CONV,, <:HENHMETAFILE, :UINT, :LPBYTE>, 12
        @DefProto DllImport, GetEnhMetaFileDescriptionA, WIN_STD_CALL_CONV,, <:HENHMETAFILE, :UINT, :LPSTR>, 12
        @DefProto DllImport, GetEnhMetaFileDescriptionW, WIN_STD_CALL_CONV,, <:HENHMETAFILE, :UINT, :LPWSTR>, 12
        ifdef UNICODE
          GetEnhMetaFileDescription equ <GetEnhMetaFileDescriptionW>
        else
          GetEnhMetaFileDescription equ <GetEnhMetaFileDescriptionA>
        endif
        @DefProto DllImport, GetEnhMetaFileHeader, WIN_STD_CALL_CONV,, <:HENHMETAFILE, :UINT, :LPENHMETAHEADER>, 12
        @DefProto DllImport, GetEnhMetaFilePaletteEntries, WIN_STD_CALL_CONV,, <:HENHMETAFILE, :UINT, :LPPALETTEENTRY>, 12
        @DefProto DllImport, GetEnhMetaFilePixelFormat, WIN_STD_CALL_CONV,, <:HENHMETAFILE, :UINT, :ptr PIXELFORMATDESCRIPTOR>, 12
        @DefProto DllImport, GetWinMetaFileBits, WIN_STD_CALL_CONV,, <:HENHMETAFILE, :UINT, :LPBYTE, :INT_, :HDC>, 20
        @DefProto DllImport, PlayEnhMetaFile, WIN_STD_CALL_CONV,, <:HDC, :HENHMETAFILE, :ptr RECT>, 12
        @DefProto DllImport, PlayEnhMetaFileRecord, WIN_STD_CALL_CONV,, <:HDC, :LPHANDLETABLE, :ptr ENHMETARECORD, :UINT>, 16
        @DefProto DllImport, SetEnhMetaFileBits, WIN_STD_CALL_CONV,, <:UINT, :ptr BYTE>, 8
        @DefProto DllImport, SetWinMetaFileBits, WIN_STD_CALL_CONV,, <:UINT, :ptr BYTE, :HDC, :ptr METAFILEPICT>, 16
        @DefProto DllImport, GdiComment, WIN_STD_CALL_CONV,, <:HDC, :UINT, :ptr BYTE>, 12
      endif
      ifndef NOTEXTMETRIC
        @DefProto DllImport, GetTextMetricsA, WIN_STD_CALL_CONV,, <:HDC, :LPTEXTMETRICA>, 8
        @DefProto DllImport, GetTextMetricsW, WIN_STD_CALL_CONV,, <:HDC, :LPTEXTMETRICW>, 8
        ifdef UNICODE
          GetTextMetrics equ <GetTextMetricsW>
        else
          GetTextMetrics equ <GetTextMetricsA>
        endif
        if Defined(_M_CEE)
          ;[...]
        endif
      endif
      DIBSECTION struct
        dsBm BITMAP <>
        dsBmih BITMAPINFOHEADER <>
        dsBitfields DWORD 3 dup (?)
        dshSection HANDLE ?
        dsOffset DWORD ?
      DIBSECTION ends
      tagDIBSECTION typedef DIBSECTION
      LPDIBSECTION typedef ptr DIBSECTION
      PDIBSECTION typedef ptr DIBSECTION
      @DefProto DllImport, AngleArc, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :DWORD, :FLOAT, :FLOAT>, 24
      @DefProto DllImport, PolyPolyline, WIN_STD_CALL_CONV,, <:HDC, :ptr POINT, :ptr DWORD, :DWORD>, 16
      @DefProto DllImport, GetWorldTransform, WIN_STD_CALL_CONV,, <:HDC, :LPXFORM>, 8
      @DefProto DllImport, SetWorldTransform, WIN_STD_CALL_CONV,, <:HDC, :ptr XFORM>, 8
      @DefProto DllImport, ModifyWorldTransform, WIN_STD_CALL_CONV,, <:HDC, :ptr XFORM, :DWORD>, 12
      @DefProto DllImport, CombineTransform, WIN_STD_CALL_CONV,, <:LPXFORM, :ptr XFORM, :ptr XFORM>, 12
      GDI_WIDTHBYTES macro bits
        exitm <((((bits) + 31) and (not 31)) / 8)>
      endm
      GDI_DIBWIDTHBYTES macro bi
        exitm <GDI_WIDTHBYTES((bi).biWidth * (bi).biBitCount)>
      endm
      GDI__DIBSIZE macro bi
        exitm <(GDI_DIBWIDTHBYTES(bi) * (bi).biHeight)>
      endm
      GDI_DIBSIZE macro bi
        exitm <((bi).biHeight < 0 ? (- 1) * (GDI__DIBSIZE(bi)) : GDI__DIBSIZE(bi))>
      endm
      @DefProto DllImport, CreateDIBSection, WIN_STD_CALL_CONV,, <:HDC, :ptr BITMAPINFO, :UINT, :ptr ptr VOID, :HANDLE, :DWORD>, 24
      @DefProto DllImport, GetDIBColorTable, WIN_STD_CALL_CONV,, <:HDC, :UINT, :UINT, :ptr RGBQUAD>, 16
      @DefProto DllImport, SetDIBColorTable, WIN_STD_CALL_CONV,, <:HDC, :UINT, :UINT, :ptr RGBQUAD>, 16
      CA_NEGATIVE equ 0001h
      CA_LOG_FILTER equ 0002h
      ILLUMINANT_DEVICE_DEFAULT equ 0
      ILLUMINANT_A equ 1
      ILLUMINANT_B equ 2
      ILLUMINANT_C equ 3
      ILLUMINANT_D50 equ 4
      ILLUMINANT_D55 equ 5
      ILLUMINANT_D65 equ 6
      ILLUMINANT_D75 equ 7
      ILLUMINANT_F2 equ 8
      ILLUMINANT_MAX_INDEX equ <ILLUMINANT_F2>
      ILLUMINANT_TUNGSTEN equ <ILLUMINANT_A>
      ILLUMINANT_DAYLIGHT equ <ILLUMINANT_C>
      ILLUMINANT_FLUORESCENT equ <ILLUMINANT_F2>
      ILLUMINANT_NTSC equ <ILLUMINANT_C>
      RGB_GAMMA_MIN equ 02500
      RGB_GAMMA_MAX equ 65000
      REFERENCE_WHITE_MIN equ 6000
      REFERENCE_WHITE_MAX equ 10000
      REFERENCE_BLACK_MIN equ 0
      REFERENCE_BLACK_MAX equ 4000
      COLOR_ADJ_MIN equ -100
      COLOR_ADJ_MAX equ 100
      COLORADJUSTMENT struct
        caSize WORD ?
        caFlags WORD ?
        caIlluminantIndex WORD ?
        caRedGamma WORD ?
        caGreenGamma WORD ?
        caBlueGamma WORD ?
        caReferenceBlack WORD ?
        caReferenceWhite WORD ?
        caContrast SHORT_ ?
        caBrightness SHORT_ ?
        caColorfulness SHORT_ ?
        caRedGreenTint SHORT_ ?
      COLORADJUSTMENT ends
      tagCOLORADJUSTMENT typedef COLORADJUSTMENT
      PCOLORADJUSTMENT typedef ptr COLORADJUSTMENT
      LPCOLORADJUSTMENT typedef ptr COLORADJUSTMENT
      @DefProto DllImport, SetColorAdjustment, WIN_STD_CALL_CONV,, <:HDC, :ptr COLORADJUSTMENT>, 8
      @DefProto DllImport, GetColorAdjustment, WIN_STD_CALL_CONV,, <:HDC, :LPCOLORADJUSTMENT>, 8
      @DefProto DllImport, CreateHalftonePalette, WIN_STD_CALL_CONV,, <:HDC>, 4
      ifdef STRICT
        TYPE_ABORTPROC typedef proto WIN_STD_CALL_CONV :HDC, :SDWORD
        ABORTPROC typedef ptr TYPE_ABORTPROC

      else
        ABORTPROC typedef FARPROC
      endif
      DOCINFOA struct
        cbSize SDWORD ?
        lpszDocName LPCSTR ?
        lpszOutput LPCSTR ?
        if (WINVER ge 0400h)
          lpszDatatype LPCSTR ?
          fwType DWORD ?
        endif
      DOCINFOA ends
      _DOCINFOA typedef DOCINFOA
      LPDOCINFOA typedef ptr DOCINFOA
      DOCINFOW struct
        cbSize SDWORD ?
        lpszDocName LPCWSTR ?
        lpszOutput LPCWSTR ?
        if (WINVER ge 0400h)
          lpszDatatype LPCWSTR ?
          fwType DWORD ?
        endif
      DOCINFOW ends
      _DOCINFOW typedef DOCINFOW
      LPDOCINFOW typedef ptr DOCINFOW
      ifdef UNICODE
        DOCINFO typedef DOCINFOW
        LPDOCINFO typedef LPDOCINFOW
      else
        DOCINFO typedef DOCINFOA
        LPDOCINFO typedef LPDOCINFOA
      endif
      if (WINVER ge 0400h)
        DI_APPBANDING equ 00000001h
        DI_ROPS_READ_DESTINATION equ 00000002h
      endif
      @DefProto DllImport, StartDocA, WIN_STD_CALL_CONV,, <:HDC, :ptr DOCINFOA>, 8
      @DefProto DllImport, StartDocW, WIN_STD_CALL_CONV,, <:HDC, :ptr DOCINFOW>, 8
      ifdef UNICODE
        StartDoc equ <StartDocW>
      else
        StartDoc equ <StartDocA>
      endif
      @DefProto DllImport, EndDoc, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, StartPage, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, EndPage, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, AbortDoc, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, SetAbortProc, WIN_STD_CALL_CONV,, <:HDC, :ABORTPROC>, 8
      @DefProto DllImport, AbortPath, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, ArcTo, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD>, 36
      @DefProto DllImport, BeginPath, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, CloseFigure, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, EndPath, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, FillPath, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, FlattenPath, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, GetPath, WIN_STD_CALL_CONV,, <:HDC, :LPPOINT, :LPBYTE, :SDWORD>, 16
      @DefProto DllImport, PathToRegion, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, PolyDraw, WIN_STD_CALL_CONV,, <:HDC, :ptr POINT, :ptr BYTE, :SDWORD>, 16
      @DefProto DllImport, SelectClipPath, WIN_STD_CALL_CONV,, <:HDC, :SDWORD>, 8
      @DefProto DllImport, SetArcDirection, WIN_STD_CALL_CONV,, <:HDC, :SDWORD>, 8
      @DefProto DllImport, SetMiterLimit, WIN_STD_CALL_CONV,, <:HDC, :FLOAT, :PFLOAT>, 12
      @DefProto DllImport, StrokeAndFillPath, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, StrokePath, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, WidenPath, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, ExtCreatePen, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :ptr LOGBRUSH, :DWORD, :ptr DWORD>, 20
      @DefProto DllImport, GetMiterLimit, WIN_STD_CALL_CONV,, <:HDC, :PFLOAT>, 8
      @DefProto DllImport, GetArcDirection, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, GetObjectA, WIN_STD_CALL_CONV,, <:HANDLE, :SDWORD, :LPVOID>, 12
      @DefProto DllImport, GetObjectW, WIN_STD_CALL_CONV,, <:HANDLE, :SDWORD, :LPVOID>, 12
      ifdef UNICODE
        GetObject equ <GetObjectW>
      else
        GetObject equ <GetObjectA>
      endif
      if Defined(_M_CEE)
        ;[...]
      endif
      @DefProto DllImport, MoveToEx, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :LPPOINT>, 16
      @DefProto DllImport, TextOutA, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :LPCSTR, :SDWORD>, 20
      @DefProto DllImport, TextOutW, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :LPCWSTR, :SDWORD>, 20
      ifdef UNICODE
        TextOut equ <TextOutW>
      else
        TextOut equ <TextOutA>
      endif
      @DefProto DllImport, ExtTextOutA, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :UINT, :ptr RECT, :LPCSTR, :UINT, :ptr INT_>, 32
      @DefProto DllImport, ExtTextOutW, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :UINT, :ptr RECT, :LPCWSTR, :UINT, :ptr INT_>, 32
      ifdef UNICODE
        ExtTextOut equ <ExtTextOutW>
      else
        ExtTextOut equ <ExtTextOutA>
      endif
      @DefProto DllImport, PolyTextOutA, WIN_STD_CALL_CONV,, <:HDC, :ptr POLYTEXTA, :SDWORD>, 12
      @DefProto DllImport, PolyTextOutW, WIN_STD_CALL_CONV,, <:HDC, :ptr POLYTEXTW, :SDWORD>, 12
      ifdef UNICODE
        PolyTextOut equ <PolyTextOutW>
      else
        PolyTextOut equ <PolyTextOutA>
      endif
      @DefProto DllImport, CreatePolygonRgn, WIN_STD_CALL_CONV,, <:ptr POINT, :SDWORD, :SDWORD>, 12
      @DefProto DllImport, DPtoLP, WIN_STD_CALL_CONV,, <:HDC, :LPPOINT, :SDWORD>, 12
      @DefProto DllImport, LPtoDP, WIN_STD_CALL_CONV,, <:HDC, :LPPOINT, :SDWORD>, 12
      @DefProto DllImport, Polygon, WIN_STD_CALL_CONV,, <:HDC, :ptr POINT, :SDWORD>, 12
      @DefProto DllImport, Polyline, WIN_STD_CALL_CONV,, <:HDC, :ptr POINT, :SDWORD>, 12
      @DefProto DllImport, PolyBezier, WIN_STD_CALL_CONV,, <:HDC, :ptr POINT, :DWORD>, 12
      @DefProto DllImport, PolyBezierTo, WIN_STD_CALL_CONV,, <:HDC, :ptr POINT, :DWORD>, 12
      @DefProto DllImport, PolylineTo, WIN_STD_CALL_CONV,, <:HDC, :ptr POINT, :DWORD>, 12
      @DefProto DllImport, SetViewportExtEx, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :LPSIZE>, 16
      @DefProto DllImport, SetViewportOrgEx, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :LPPOINT>, 16
      @DefProto DllImport, SetWindowExtEx, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :LPSIZE>, 16
      @DefProto DllImport, SetWindowOrgEx, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :LPPOINT>, 16
      @DefProto DllImport, OffsetViewportOrgEx, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :LPPOINT>, 16
      @DefProto DllImport, OffsetWindowOrgEx, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :LPPOINT>, 16
      @DefProto DllImport, ScaleViewportExtEx, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :LPSIZE>, 24
      @DefProto DllImport, ScaleWindowExtEx, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :LPSIZE>, 24
      @DefProto DllImport, SetBitmapDimensionEx, WIN_STD_CALL_CONV,, <:HBITMAP, :SDWORD, :SDWORD, :LPSIZE>, 16
      @DefProto DllImport, SetBrushOrgEx, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :LPPOINT>, 16
      @DefProto DllImport, GetTextFaceA, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :LPSTR>, 12
      @DefProto DllImport, GetTextFaceW, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :LPWSTR>, 12
      ifdef UNICODE
        GetTextFace equ <GetTextFaceW>
      else
        GetTextFace equ <GetTextFaceA>
      endif
      FONTMAPPER_MAX equ 10
      KERNINGPAIR struct
        wFirst WORD ?
        wSecond WORD ?
        iKernAmount SDWORD ?
      KERNINGPAIR ends
      tagKERNINGPAIR typedef KERNINGPAIR
      LPKERNINGPAIR typedef ptr KERNINGPAIR
      @DefProto DllImport, GetKerningPairsA, WIN_STD_CALL_CONV,, <:HDC, :DWORD, :LPKERNINGPAIR>, 12
      @DefProto DllImport, GetKerningPairsW, WIN_STD_CALL_CONV,, <:HDC, :DWORD, :LPKERNINGPAIR>, 12
      ifdef UNICODE
        GetKerningPairs equ <GetKerningPairsW>
      else
        GetKerningPairs equ <GetKerningPairsA>
      endif
      @DefProto DllImport, GetDCOrgEx, WIN_STD_CALL_CONV,, <:HDC, :LPPOINT>, 8
      @DefProto DllImport, FixBrushOrgEx, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :LPPOINT>, 16
      @DefProto DllImport, UnrealizeObject, WIN_STD_CALL_CONV,, <:HGDIOBJ>, 4
      @DefProto DllImport, GdiFlush, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, GdiSetBatchLimit, WIN_STD_CALL_CONV,, <:DWORD>, 4
      @DefProto DllImport, GdiGetBatchLimit, WIN_STD_CALL_CONV,, <>, 0
      if (WINVER ge 0400h)
        ICM_OFF equ 1
        ICM_ON equ 2
        ICM_QUERY equ 3
        ICM_DONE_OUTSIDEDC equ 4
        TYPE_ICMENUMPROCA typedef proto WIN_STD_CALL_CONV :LPSTR, :LPARAM
        ICMENUMPROCA typedef ptr TYPE_ICMENUMPROCA

        TYPE_ICMENUMPROCW typedef proto WIN_STD_CALL_CONV :LPWSTR, :LPARAM
        ICMENUMPROCW typedef ptr TYPE_ICMENUMPROCW

        ifdef UNICODE
          ICMENUMPROC equ <ICMENUMPROCW>
        else
          ICMENUMPROC equ <ICMENUMPROCA>
        endif
        @DefProto DllImport, SetICMMode, WIN_STD_CALL_CONV,, <:HDC, :SDWORD>, 8
        @DefProto DllImport, CheckColorsInGamut, WIN_STD_CALL_CONV,, <:HDC, :LPRGBTRIPLE, :LPVOID, :DWORD>, 16
        @DefProto DllImport, GetColorSpace, WIN_STD_CALL_CONV,, <:HDC>, 4
        @DefProto DllImport, GetLogColorSpaceA, WIN_STD_CALL_CONV,, <:HCOLORSPACE, :LPLOGCOLORSPACEA, :DWORD>, 12
        @DefProto DllImport, GetLogColorSpaceW, WIN_STD_CALL_CONV,, <:HCOLORSPACE, :LPLOGCOLORSPACEW, :DWORD>, 12
        ifdef UNICODE
          GetLogColorSpace equ <GetLogColorSpaceW>
        else
          GetLogColorSpace equ <GetLogColorSpaceA>
        endif
        @DefProto DllImport, CreateColorSpaceA, WIN_STD_CALL_CONV,, <:LPLOGCOLORSPACEA>, 4
        @DefProto DllImport, CreateColorSpaceW, WIN_STD_CALL_CONV,, <:LPLOGCOLORSPACEW>, 4
        ifdef UNICODE
          CreateColorSpace equ <CreateColorSpaceW>
        else
          CreateColorSpace equ <CreateColorSpaceA>
        endif
        @DefProto DllImport, SetColorSpace, WIN_STD_CALL_CONV,, <:HDC, :HCOLORSPACE>, 8
        @DefProto DllImport, DeleteColorSpace, WIN_STD_CALL_CONV,, <:HCOLORSPACE>, 4
        @DefProto DllImport, GetICMProfileA, WIN_STD_CALL_CONV,, <:HDC, :LPDWORD, :LPSTR>, 12
        @DefProto DllImport, GetICMProfileW, WIN_STD_CALL_CONV,, <:HDC, :LPDWORD, :LPWSTR>, 12
        ifdef UNICODE
          GetICMProfile equ <GetICMProfileW>
        else
          GetICMProfile equ <GetICMProfileA>
        endif
        @DefProto DllImport, SetICMProfileA, WIN_STD_CALL_CONV,, <:HDC, :LPSTR>, 8
        @DefProto DllImport, SetICMProfileW, WIN_STD_CALL_CONV,, <:HDC, :LPWSTR>, 8
        ifdef UNICODE
          SetICMProfile equ <SetICMProfileW>
        else
          SetICMProfile equ <SetICMProfileA>
        endif
        @DefProto DllImport, GetDeviceGammaRamp, WIN_STD_CALL_CONV,, <:HDC, :LPVOID>, 8
        @DefProto DllImport, SetDeviceGammaRamp, WIN_STD_CALL_CONV,, <:HDC, :LPVOID>, 8
        @DefProto DllImport, ColorMatchToTarget, WIN_STD_CALL_CONV,, <:HDC, :HDC, :DWORD>, 12
        @DefProto DllImport, EnumICMProfilesA, WIN_STD_CALL_CONV,, <:HDC, :ICMENUMPROCA, :LPARAM>, 12
        @DefProto DllImport, EnumICMProfilesW, WIN_STD_CALL_CONV,, <:HDC, :ICMENUMPROCW, :LPARAM>, 12
        ifdef UNICODE
          EnumICMProfiles equ <EnumICMProfilesW>
        else
          EnumICMProfiles equ <EnumICMProfilesA>
        endif
        @DefProto DllImport, UpdateICMRegKeyA, WIN_STD_CALL_CONV,, <:DWORD, :LPSTR, :LPSTR, :UINT>, 16
        @DefProto DllImport, UpdateICMRegKeyW, WIN_STD_CALL_CONV,, <:DWORD, :LPWSTR, :LPWSTR, :UINT>, 16
        ifdef UNICODE
          UpdateICMRegKey equ <UpdateICMRegKeyW>
        else
          UpdateICMRegKey equ <UpdateICMRegKeyA>
        endif
        ifndef _CONTRACT_GEN
        endif
      endif
      if (WINVER ge 0500h)
        @DefProto DllImport, ColorCorrectPalette, WIN_STD_CALL_CONV,, <:HDC, :HPALETTE, :DWORD, :DWORD>, 16
      endif
      ifndef NOMETAFILE
        ifndef _MAC
          ENHMETA_SIGNATURE equ 464D4520h
        else
          ;[...]
        endif
        ENHMETA_STOCK_OBJECT equ 80000000h
        EMR_HEADER equ 1
        EMR_POLYBEZIER equ 2
        EMR_POLYGON equ 3
        EMR_POLYLINE equ 4
        EMR_POLYBEZIERTO equ 5
        EMR_POLYLINETO equ 6
        EMR_POLYPOLYLINE equ 7
        EMR_POLYPOLYGON equ 8
        EMR_SETWINDOWEXTEX equ 9
        EMR_SETWINDOWORGEX equ 10
        EMR_SETVIEWPORTEXTEX equ 11
        EMR_SETVIEWPORTORGEX equ 12
        EMR_SETBRUSHORGEX equ 13
        EMR_EOF equ 14
        EMR_SETPIXELV equ 15
        EMR_SETMAPPERFLAGS equ 16
        EMR_SETMAPMODE equ 17
        EMR_SETBKMODE equ 18
        EMR_SETPOLYFILLMODE equ 19
        EMR_SETROP2 equ 20
        EMR_SETSTRETCHBLTMODE equ 21
        EMR_SETTEXTALIGN equ 22
        EMR_SETCOLORADJUSTMENT equ 23
        EMR_SETTEXTCOLOR equ 24
        EMR_SETBKCOLOR equ 25
        EMR_OFFSETCLIPRGN equ 26
        EMR_MOVETOEX equ 27
        EMR_SETMETARGN equ 28
        EMR_EXCLUDECLIPRECT equ 29
        EMR_INTERSECTCLIPRECT equ 30
        EMR_SCALEVIEWPORTEXTEX equ 31
        EMR_SCALEWINDOWEXTEX equ 32
        EMR_SAVEDC equ 33
        EMR_RESTOREDC equ 34
        EMR_SETWORLDTRANSFORM equ 35
        EMR_MODIFYWORLDTRANSFORM equ 36
        EMR_SELECTOBJECT equ 37
        EMR_CREATEPEN equ 38
        EMR_CREATEBRUSHINDIRECT equ 39
        EMR_DELETEOBJECT equ 40
        EMR_ANGLEARC equ 41
        EMR_ELLIPSE equ 42
        EMR_RECTANGLE equ 43
        EMR_ROUNDRECT equ 44
        EMR_ARC equ 45
        EMR_CHORD equ 46
        EMR_PIE equ 47
        EMR_SELECTPALETTE equ 48
        EMR_CREATEPALETTE equ 49
        EMR_SETPALETTEENTRIES equ 50
        EMR_RESIZEPALETTE equ 51
        EMR_REALIZEPALETTE equ 52
        EMR_EXTFLOODFILL equ 53
        EMR_LINETO equ 54
        EMR_ARCTO equ 55
        EMR_POLYDRAW equ 56
        EMR_SETARCDIRECTION equ 57
        EMR_SETMITERLIMIT equ 58
        EMR_BEGINPATH equ 59
        EMR_ENDPATH equ 60
        EMR_CLOSEFIGURE equ 61
        EMR_FILLPATH equ 62
        EMR_STROKEANDFILLPATH equ 63
        EMR_STROKEPATH equ 64
        EMR_FLATTENPATH equ 65
        EMR_WIDENPATH equ 66
        EMR_SELECTCLIPPATH equ 67
        EMR_ABORTPATH equ 68
        EMR_GDICOMMENT equ 70
        EMR_FILLRGN equ 71
        EMR_FRAMERGN equ 72
        EMR_INVERTRGN equ 73
        EMR_PAINTRGN equ 74
        EMR_EXTSELECTCLIPRGN equ 75
        EMR_BITBLT equ 76
        EMR_STRETCHBLT equ 77
        EMR_MASKBLT equ 78
        EMR_PLGBLT equ 79
        EMR_SETDIBITSTODEVICE equ 80
        EMR_STRETCHDIBITS equ 81
        EMR_EXTCREATEFONTINDIRECTW equ 82
        EMR_EXTTEXTOUTA equ 83
        EMR_EXTTEXTOUTW equ 84
        EMR_POLYBEZIER16 equ 85
        EMR_POLYGON16 equ 86
        EMR_POLYLINE16 equ 87
        EMR_POLYBEZIERTO16 equ 88
        EMR_POLYLINETO16 equ 89
        EMR_POLYPOLYLINE16 equ 90
        EMR_POLYPOLYGON16 equ 91
        EMR_POLYDRAW16 equ 92
        EMR_CREATEMONOBRUSH equ 93
        EMR_CREATEDIBPATTERNBRUSHPT equ 94
        EMR_EXTCREATEPEN equ 95
        EMR_POLYTEXTOUTA equ 96
        EMR_POLYTEXTOUTW equ 97
        if (WINVER ge 0400h)
          EMR_SETICMMODE equ 98
          EMR_CREATECOLORSPACE equ 99
          EMR_SETCOLORSPACE equ 100
          EMR_DELETECOLORSPACE equ 101
          EMR_GLSRECORD equ 102
          EMR_GLSBOUNDEDRECORD equ 103
          EMR_PIXELFORMAT equ 104
        endif
        if (WINVER ge 0500h)
          EMR_RESERVED_105 equ 105
          EMR_RESERVED_106 equ 106
          EMR_RESERVED_107 equ 107
          EMR_RESERVED_108 equ 108
          EMR_RESERVED_109 equ 109
          EMR_RESERVED_110 equ 110
          EMR_COLORCORRECTPALETTE equ 111
          EMR_SETICMPROFILEA equ 112
          EMR_SETICMPROFILEW equ 113
          EMR_ALPHABLEND equ 114
          EMR_SETLAYOUT equ 115
          EMR_TRANSPARENTBLT equ 116
          if (_WIN32_WINNT ge _WIN32_WINNT_WIN2K)
            EMR_RESERVED_117 equ 117
          endif
          EMR_GRADIENTFILL equ 118
          EMR_RESERVED_119 equ 119
          EMR_RESERVED_120 equ 120
          EMR_COLORMATCHTOTARGETW equ 121
          EMR_CREATECOLORSPACEW equ 122
        endif
        EMR_MIN equ 1
        if (WINVER ge 0500h)
          EMR_MAX equ 122
        elseif (WINVER ge 0400h)
          EMR_MAX equ 104
        else
          EMR_MAX equ 97
        endif
        EMR struct
          iType DWORD ?
          nSize DWORD ?
        EMR ends
        tagEMR typedef EMR
        PEMR typedef ptr EMR
        EMRTEXT struct
          ptlReference POINTL <>
          nChars DWORD ?
          offString DWORD ?
          fOptions DWORD ?
          rcl_ RECTL <>
          offDx DWORD ?
        EMRTEXT ends
        tagEMRTEXT typedef EMRTEXT
        PEMRTEXT typedef ptr EMRTEXT
        EMRABORTPATH struct
          emr EMR <>
        EMRABORTPATH ends
        tagABORTPATH typedef EMRABORTPATH
        PEMRABORTPATH typedef ptr EMRABORTPATH
        EMRBEGINPATH typedef EMRABORTPATH
        PEMRBEGINPATH typedef ptr EMRABORTPATH
        EMRENDPATH typedef EMRABORTPATH
        PEMRENDPATH typedef ptr EMRABORTPATH
        EMRCLOSEFIGURE typedef EMRABORTPATH
        PEMRCLOSEFIGURE typedef ptr EMRABORTPATH
        EMRFLATTENPATH typedef EMRABORTPATH
        PEMRFLATTENPATH typedef ptr EMRABORTPATH
        EMRWIDENPATH typedef EMRABORTPATH
        PEMRWIDENPATH typedef ptr EMRABORTPATH
        EMRSETMETARGN typedef EMRABORTPATH
        PEMRSETMETARGN typedef ptr EMRABORTPATH
        EMRSAVEDC typedef EMRABORTPATH
        PEMRSAVEDC typedef ptr EMRABORTPATH
        EMRREALIZEPALETTE typedef EMRABORTPATH
        PEMRREALIZEPALETTE typedef ptr EMRABORTPATH
        EMRSELECTCLIPPATH struct
          emr EMR <>
          iMode DWORD ?
        EMRSELECTCLIPPATH ends
        tagEMRSELECTCLIPPATH typedef EMRSELECTCLIPPATH
        PEMRSELECTCLIPPATH typedef ptr EMRSELECTCLIPPATH
        EMRSETBKMODE typedef EMRSELECTCLIPPATH
        PEMRSETBKMODE typedef ptr EMRSELECTCLIPPATH
        EMRSETMAPMODE typedef EMRSELECTCLIPPATH
        PEMRSETMAPMODE typedef ptr EMRSELECTCLIPPATH
        if (WINVER ge 0500h)
          EMRSETLAYOUT typedef EMRSELECTCLIPPATH
          PEMRSETLAYOUT typedef ptr EMRSELECTCLIPPATH
        endif
        EMRSETPOLYFILLMODE typedef EMRSELECTCLIPPATH
        PEMRSETPOLYFILLMODE typedef ptr EMRSELECTCLIPPATH
        EMRSETROP2 typedef EMRSELECTCLIPPATH
        PEMRSETROP2 typedef ptr EMRSELECTCLIPPATH
        EMRSETSTRETCHBLTMODE typedef EMRSELECTCLIPPATH
        PEMRSETSTRETCHBLTMODE typedef ptr EMRSELECTCLIPPATH
        EMRSETICMMODE typedef EMRSELECTCLIPPATH
        PEMRSETICMMODE typedef ptr EMRSELECTCLIPPATH
        EMRSETTEXTALIGN typedef EMRSELECTCLIPPATH
        PEMRSETTEXTALIGN typedef ptr EMRSELECTCLIPPATH
        EMRSETMITERLIMIT struct
          emr EMR <>
          eMiterLimit FLOAT ?
        EMRSETMITERLIMIT ends
        tagEMRSETMITERLIMIT typedef EMRSETMITERLIMIT
        PEMRSETMITERLIMIT typedef ptr EMRSETMITERLIMIT
        EMRRESTOREDC struct
          emr EMR <>
          iRelative LONG ?
        EMRRESTOREDC ends
        tagEMRRESTOREDC typedef EMRRESTOREDC
        PEMRRESTOREDC typedef ptr EMRRESTOREDC
        EMRSETARCDIRECTION struct
          emr EMR <>
          iArcDirection DWORD ?
        EMRSETARCDIRECTION ends
        tagEMRSETARCDIRECTION typedef EMRSETARCDIRECTION
        PEMRSETARCDIRECTION typedef ptr EMRSETARCDIRECTION
        EMRSETMAPPERFLAGS struct
          emr EMR <>
          dwFlags DWORD ?
        EMRSETMAPPERFLAGS ends
        tagEMRSETMAPPERFLAGS typedef EMRSETMAPPERFLAGS
        PEMRSETMAPPERFLAGS typedef ptr EMRSETMAPPERFLAGS
        EMRSETBKCOLOR struct
          emr EMR <>
          crColor COLORREF ?
        EMRSETBKCOLOR ends
        tagEMRSETTEXTCOLOR typedef EMRSETBKCOLOR
        PEMRSETBKCOLOR typedef ptr EMRSETBKCOLOR
        EMRSETTEXTCOLOR typedef EMRSETBKCOLOR
        PEMRSETTEXTCOLOR typedef ptr EMRSETBKCOLOR
        EMRSELECTOBJECT struct
          emr EMR <>
          ihObject DWORD ?
        EMRSELECTOBJECT ends
        tagEMRSELECTOBJECT typedef EMRSELECTOBJECT
        PEMRSELECTOBJECT typedef ptr EMRSELECTOBJECT
        EMRDELETEOBJECT typedef EMRSELECTOBJECT
        PEMRDELETEOBJECT typedef ptr EMRSELECTOBJECT
        EMRSELECTPALETTE struct
          emr EMR <>
          ihPal DWORD ?
        EMRSELECTPALETTE ends
        tagEMRSELECTPALETTE typedef EMRSELECTPALETTE
        PEMRSELECTPALETTE typedef ptr EMRSELECTPALETTE
        EMRRESIZEPALETTE struct
          emr EMR <>
          ihPal DWORD ?
          cEntries DWORD ?
        EMRRESIZEPALETTE ends
        tagEMRRESIZEPALETTE typedef EMRRESIZEPALETTE
        PEMRRESIZEPALETTE typedef ptr EMRRESIZEPALETTE
        EMRSETPALETTEENTRIES struct
          emr EMR <>
          ihPal DWORD ?
          iStart DWORD ?
          cEntries DWORD ?
          aPalEntries PALETTEENTRY 1 dup (<>)
        EMRSETPALETTEENTRIES ends
        tagEMRSETPALETTEENTRIES typedef EMRSETPALETTEENTRIES
        PEMRSETPALETTEENTRIES typedef ptr EMRSETPALETTEENTRIES
        EMRSETCOLORADJUSTMENT struct
          emr EMR <>
          ColorAdjustment COLORADJUSTMENT <>
        EMRSETCOLORADJUSTMENT ends
        tagEMRSETCOLORADJUSTMENT typedef EMRSETCOLORADJUSTMENT
        PEMRSETCOLORADJUSTMENT typedef ptr EMRSETCOLORADJUSTMENT
        EMRGDICOMMENT struct
          emr EMR <>
          cbData DWORD ?
          Data BYTE 1 dup (?)
        EMRGDICOMMENT ends
        tagEMRGDICOMMENT typedef EMRGDICOMMENT
        PEMRGDICOMMENT typedef ptr EMRGDICOMMENT
        EMREOF struct
          emr EMR <>
          nPalEntries DWORD ?
          offPalEntries DWORD ?
          nSizeLast DWORD ?
        EMREOF ends
        tagEMREOF typedef EMREOF
        PEMREOF typedef ptr EMREOF
        EMRLINETO struct
          emr EMR <>
          ptl POINTL <>
        EMRLINETO ends
        tagEMRLINETO typedef EMRLINETO
        PEMRLINETO typedef ptr EMRLINETO
        EMRMOVETOEX typedef EMRLINETO
        PEMRMOVETOEX typedef ptr EMRLINETO
        EMROFFSETCLIPRGN struct
          emr EMR <>
          ptlOffset POINTL <>
        EMROFFSETCLIPRGN ends
        tagEMROFFSETCLIPRGN typedef EMROFFSETCLIPRGN
        PEMROFFSETCLIPRGN typedef ptr EMROFFSETCLIPRGN
        EMRFILLPATH struct
          emr EMR <>
          rclBounds RECTL <>
        EMRFILLPATH ends
        tagEMRFILLPATH typedef EMRFILLPATH
        PEMRFILLPATH typedef ptr EMRFILLPATH
        EMRSTROKEANDFILLPATH typedef EMRFILLPATH
        PEMRSTROKEANDFILLPATH typedef ptr EMRFILLPATH
        EMRSTROKEPATH typedef EMRFILLPATH
        PEMRSTROKEPATH typedef ptr EMRFILLPATH
        EMREXCLUDECLIPRECT struct
          emr EMR <>
          rclClip RECTL <>
        EMREXCLUDECLIPRECT ends
        tagEMREXCLUDECLIPRECT typedef EMREXCLUDECLIPRECT
        PEMREXCLUDECLIPRECT typedef ptr EMREXCLUDECLIPRECT
        EMRINTERSECTCLIPRECT typedef EMREXCLUDECLIPRECT
        PEMRINTERSECTCLIPRECT typedef ptr EMREXCLUDECLIPRECT
        EMRSETVIEWPORTORGEX struct
          emr EMR <>
          ptlOrigin POINTL <>
        EMRSETVIEWPORTORGEX ends
        tagEMRSETVIEWPORTORGEX typedef EMRSETVIEWPORTORGEX
        PEMRSETVIEWPORTORGEX typedef ptr EMRSETVIEWPORTORGEX
        EMRSETWINDOWORGEX typedef EMRSETVIEWPORTORGEX
        PEMRSETWINDOWORGEX typedef ptr EMRSETVIEWPORTORGEX
        EMRSETBRUSHORGEX typedef EMRSETVIEWPORTORGEX
        PEMRSETBRUSHORGEX typedef ptr EMRSETVIEWPORTORGEX
        EMRSETVIEWPORTEXTEX struct
          emr EMR <>
          szlExtent SIZEL <>
        EMRSETVIEWPORTEXTEX ends
        tagEMRSETVIEWPORTEXTEX typedef EMRSETVIEWPORTEXTEX
        PEMRSETVIEWPORTEXTEX typedef ptr EMRSETVIEWPORTEXTEX
        EMRSETWINDOWEXTEX typedef EMRSETVIEWPORTEXTEX
        PEMRSETWINDOWEXTEX typedef ptr EMRSETVIEWPORTEXTEX
        EMRSCALEVIEWPORTEXTEX struct
          emr EMR <>
          xNum LONG ?
          xDenom LONG ?
          yNum LONG ?
          yDenom LONG ?
        EMRSCALEVIEWPORTEXTEX ends
        tagEMRSCALEVIEWPORTEXTEX typedef EMRSCALEVIEWPORTEXTEX
        PEMRSCALEVIEWPORTEXTEX typedef ptr EMRSCALEVIEWPORTEXTEX
        EMRSCALEWINDOWEXTEX typedef EMRSCALEVIEWPORTEXTEX
        PEMRSCALEWINDOWEXTEX typedef ptr EMRSCALEVIEWPORTEXTEX
        EMRSETWORLDTRANSFORM struct
          emr EMR <>
          xform XFORM <>
        EMRSETWORLDTRANSFORM ends
        tagEMRSETWORLDTRANSFORM typedef EMRSETWORLDTRANSFORM
        PEMRSETWORLDTRANSFORM typedef ptr EMRSETWORLDTRANSFORM
        EMRMODIFYWORLDTRANSFORM struct
          emr EMR <>
          xform XFORM <>
          iMode DWORD ?
        EMRMODIFYWORLDTRANSFORM ends
        tagEMRMODIFYWORLDTRANSFORM typedef EMRMODIFYWORLDTRANSFORM
        PEMRMODIFYWORLDTRANSFORM typedef ptr EMRMODIFYWORLDTRANSFORM
        EMRSETPIXELV struct
          emr EMR <>
          ptlPixel POINTL <>
          crColor COLORREF ?
        EMRSETPIXELV ends
        tagEMRSETPIXELV typedef EMRSETPIXELV
        PEMRSETPIXELV typedef ptr EMRSETPIXELV
        EMREXTFLOODFILL struct
          emr EMR <>
          ptlStart POINTL <>
          crColor COLORREF ?
          iMode DWORD ?
        EMREXTFLOODFILL ends
        tagEMREXTFLOODFILL typedef EMREXTFLOODFILL
        PEMREXTFLOODFILL typedef ptr EMREXTFLOODFILL
        EMRELLIPSE struct
          emr EMR <>
          rclBox RECTL <>
        EMRELLIPSE ends
        tagEMRELLIPSE typedef EMRELLIPSE
        PEMRELLIPSE typedef ptr EMRELLIPSE
        EMRRECTANGLE typedef EMRELLIPSE
        PEMRRECTANGLE typedef ptr EMRELLIPSE
        EMRROUNDRECT struct
          emr EMR <>
          rclBox RECTL <>
          szlCorner SIZEL <>
        EMRROUNDRECT ends
        tagEMRROUNDRECT typedef EMRROUNDRECT
        PEMRROUNDRECT typedef ptr EMRROUNDRECT
        EMRARC struct
          emr EMR <>
          rclBox RECTL <>
          ptlStart POINTL <>
          ptlEnd POINTL <>
        EMRARC ends
        tagEMRARC typedef EMRARC
        PEMRARC typedef ptr EMRARC
        EMRARCTO typedef EMRARC
        PEMRARCTO typedef ptr EMRARC
        EMRCHORD typedef EMRARC
        PEMRCHORD typedef ptr EMRARC
        EMRPIE typedef EMRARC
        PEMRPIE typedef ptr EMRARC
        EMRANGLEARC struct
          emr EMR <>
          ptlCenter POINTL <>
          nRadius DWORD ?
          eStartAngle FLOAT ?
          eSweepAngle FLOAT ?
        EMRANGLEARC ends
        tagEMRANGLEARC typedef EMRANGLEARC
        PEMRANGLEARC typedef ptr EMRANGLEARC
        EMRPOLYLINE struct
          emr EMR <>
          rclBounds RECTL <>
          cptl DWORD ?
          aptl POINTL 1 dup (<>)
        EMRPOLYLINE ends
        tagEMRPOLYLINE typedef EMRPOLYLINE
        PEMRPOLYLINE typedef ptr EMRPOLYLINE
        EMRPOLYBEZIER typedef EMRPOLYLINE
        PEMRPOLYBEZIER typedef ptr EMRPOLYLINE
        EMRPOLYGON typedef EMRPOLYLINE
        PEMRPOLYGON typedef ptr EMRPOLYLINE
        EMRPOLYBEZIERTO typedef EMRPOLYLINE
        PEMRPOLYBEZIERTO typedef ptr EMRPOLYLINE
        EMRPOLYLINETO typedef EMRPOLYLINE
        PEMRPOLYLINETO typedef ptr EMRPOLYLINE
        EMRPOLYLINE16 struct
          emr EMR <>
          rclBounds RECTL <>
          cpts DWORD ?
          apts POINTS 1 dup (<>)
        EMRPOLYLINE16 ends
        tagEMRPOLYLINE16 typedef EMRPOLYLINE16
        PEMRPOLYLINE16 typedef ptr EMRPOLYLINE16
        EMRPOLYBEZIER16 typedef EMRPOLYLINE16
        PEMRPOLYBEZIER16 typedef ptr EMRPOLYLINE16
        EMRPOLYGON16 typedef EMRPOLYLINE16
        PEMRPOLYGON16 typedef ptr EMRPOLYLINE16
        EMRPOLYBEZIERTO16 typedef EMRPOLYLINE16
        PEMRPOLYBEZIERTO16 typedef ptr EMRPOLYLINE16
        EMRPOLYLINETO16 typedef EMRPOLYLINE16
        PEMRPOLYLINETO16 typedef ptr EMRPOLYLINE16
        EMRPOLYDRAW struct
          emr EMR <>
          rclBounds RECTL <>
          cptl DWORD ?
          aptl POINTL 1 dup (<>)
          abTypes BYTE 1 dup (?)
        EMRPOLYDRAW ends
        tagEMRPOLYDRAW typedef EMRPOLYDRAW
        PEMRPOLYDRAW typedef ptr EMRPOLYDRAW
        EMRPOLYDRAW16 struct
          emr EMR <>
          rclBounds RECTL <>
          cpts DWORD ?
          apts POINTS 1 dup (<>)
          abTypes BYTE 1 dup (?)
        EMRPOLYDRAW16 ends
        tagEMRPOLYDRAW16 typedef EMRPOLYDRAW16
        PEMRPOLYDRAW16 typedef ptr EMRPOLYDRAW16
        EMRPOLYPOLYLINE struct
          emr EMR <>
          rclBounds RECTL <>
          nPolys DWORD ?
          cptl DWORD ?
          aPolyCounts DWORD 1 dup (?)
          aptl POINTL 1 dup (<>)
        EMRPOLYPOLYLINE ends
        tagEMRPOLYPOLYLINE typedef EMRPOLYPOLYLINE
        PEMRPOLYPOLYLINE typedef ptr EMRPOLYPOLYLINE
        EMRPOLYPOLYGON typedef EMRPOLYPOLYLINE
        PEMRPOLYPOLYGON typedef ptr EMRPOLYPOLYLINE
        EMRPOLYPOLYLINE16 struct
          emr EMR <>
          rclBounds RECTL <>
          nPolys DWORD ?
          cpts DWORD ?
          aPolyCounts DWORD 1 dup (?)
          apts POINTS 1 dup (<>)
        EMRPOLYPOLYLINE16 ends
        tagEMRPOLYPOLYLINE16 typedef EMRPOLYPOLYLINE16
        PEMRPOLYPOLYLINE16 typedef ptr EMRPOLYPOLYLINE16
        EMRPOLYPOLYGON16 typedef EMRPOLYPOLYLINE16
        PEMRPOLYPOLYGON16 typedef ptr EMRPOLYPOLYLINE16
        EMRINVERTRGN struct
          emr EMR <>
          rclBounds RECTL <>
          cbRgnData DWORD ?
          RgnData BYTE 1 dup (?)
        EMRINVERTRGN ends
        tagEMRINVERTRGN typedef EMRINVERTRGN
        PEMRINVERTRGN typedef ptr EMRINVERTRGN
        EMRPAINTRGN typedef EMRINVERTRGN
        PEMRPAINTRGN typedef ptr EMRINVERTRGN
        EMRFILLRGN struct
          emr EMR <>
          rclBounds RECTL <>
          cbRgnData DWORD ?
          ihBrush DWORD ?
          RgnData BYTE 1 dup (?)
        EMRFILLRGN ends
        tagEMRFILLRGN typedef EMRFILLRGN
        PEMRFILLRGN typedef ptr EMRFILLRGN
        EMRFRAMERGN struct
          emr EMR <>
          rclBounds RECTL <>
          cbRgnData DWORD ?
          ihBrush DWORD ?
          szlStroke SIZEL <>
          RgnData BYTE 1 dup (?)
        EMRFRAMERGN ends
        tagEMRFRAMERGN typedef EMRFRAMERGN
        PEMRFRAMERGN typedef ptr EMRFRAMERGN
        EMREXTSELECTCLIPRGN struct
          emr EMR <>
          cbRgnData DWORD ?
          iMode DWORD ?
          RgnData BYTE 1 dup (?)
        EMREXTSELECTCLIPRGN ends
        tagEMREXTSELECTCLIPRGN typedef EMREXTSELECTCLIPRGN
        PEMREXTSELECTCLIPRGN typedef ptr EMREXTSELECTCLIPRGN
        EMREXTTEXTOUTA struct
          emr EMR <>
          rclBounds RECTL <>
          iGraphicsMode DWORD ?
          exScale FLOAT ?
          eyScale FLOAT ?
          emrtext EMRTEXT <>
        EMREXTTEXTOUTA ends
        tagEMREXTTEXTOUTA typedef EMREXTTEXTOUTA
        PEMREXTTEXTOUTA typedef ptr EMREXTTEXTOUTA
        EMREXTTEXTOUTW typedef EMREXTTEXTOUTA
        PEMREXTTEXTOUTW typedef ptr EMREXTTEXTOUTA
        EMRPOLYTEXTOUTA struct
          emr EMR <>
          rclBounds RECTL <>
          iGraphicsMode DWORD ?
          exScale FLOAT ?
          eyScale FLOAT ?
          cStrings LONG ?
          aemrtext EMRTEXT 1 dup (<>)
        EMRPOLYTEXTOUTA ends
        tagEMRPOLYTEXTOUTA typedef EMRPOLYTEXTOUTA
        PEMRPOLYTEXTOUTA typedef ptr EMRPOLYTEXTOUTA
        EMRPOLYTEXTOUTW typedef EMRPOLYTEXTOUTA
        PEMRPOLYTEXTOUTW typedef ptr EMRPOLYTEXTOUTA
        EMRBITBLT struct
          emr EMR <>
          rclBounds RECTL <>
          xDest LONG ?
          yDest LONG ?
          cxDest LONG ?
          cyDest LONG ?
          dwRop DWORD ?
          xSrc LONG ?
          ySrc LONG ?
          xformSrc XFORM <>
          crBkColorSrc COLORREF ?
          iUsageSrc DWORD ?
          offBmiSrc DWORD ?
          cbBmiSrc DWORD ?
          offBitsSrc DWORD ?
          cbBitsSrc DWORD ?
        EMRBITBLT ends
        tagEMRBITBLT typedef EMRBITBLT
        PEMRBITBLT typedef ptr EMRBITBLT
        EMRSTRETCHBLT struct
          emr EMR <>
          rclBounds RECTL <>
          xDest LONG ?
          yDest LONG ?
          cxDest LONG ?
          cyDest LONG ?
          dwRop DWORD ?
          xSrc LONG ?
          ySrc LONG ?
          xformSrc XFORM <>
          crBkColorSrc COLORREF ?
          iUsageSrc DWORD ?
          offBmiSrc DWORD ?
          cbBmiSrc DWORD ?
          offBitsSrc DWORD ?
          cbBitsSrc DWORD ?
          cxSrc LONG ?
          cySrc LONG ?
        EMRSTRETCHBLT ends
        tagEMRSTRETCHBLT typedef EMRSTRETCHBLT
        PEMRSTRETCHBLT typedef ptr EMRSTRETCHBLT
        EMRMASKBLT struct
          emr EMR <>
          rclBounds RECTL <>
          xDest LONG ?
          yDest LONG ?
          cxDest LONG ?
          cyDest LONG ?
          dwRop DWORD ?
          xSrc LONG ?
          ySrc LONG ?
          xformSrc XFORM <>
          crBkColorSrc COLORREF ?
          iUsageSrc DWORD ?
          offBmiSrc DWORD ?
          cbBmiSrc DWORD ?
          offBitsSrc DWORD ?
          cbBitsSrc DWORD ?
          xMask LONG ?
          yMask LONG ?
          iUsageMask DWORD ?
          offBmiMask DWORD ?
          cbBmiMask DWORD ?
          offBitsMask DWORD ?
          cbBitsMask DWORD ?
        EMRMASKBLT ends
        tagEMRMASKBLT typedef EMRMASKBLT
        PEMRMASKBLT typedef ptr EMRMASKBLT
        EMRPLGBLT struct
          emr EMR <>
          rclBounds RECTL <>
          aptlDest POINTL 3 dup (<>)
          xSrc LONG ?
          ySrc LONG ?
          cxSrc LONG ?
          cySrc LONG ?
          xformSrc XFORM <>
          crBkColorSrc COLORREF ?
          iUsageSrc DWORD ?
          offBmiSrc DWORD ?
          cbBmiSrc DWORD ?
          offBitsSrc DWORD ?
          cbBitsSrc DWORD ?
          xMask LONG ?
          yMask LONG ?
          iUsageMask DWORD ?
          offBmiMask DWORD ?
          cbBmiMask DWORD ?
          offBitsMask DWORD ?
          cbBitsMask DWORD ?
        EMRPLGBLT ends
        tagEMRPLGBLT typedef EMRPLGBLT
        PEMRPLGBLT typedef ptr EMRPLGBLT
        EMRSETDIBITSTODEVICE struct
          emr EMR <>
          rclBounds RECTL <>
          xDest LONG ?
          yDest LONG ?
          xSrc LONG ?
          ySrc LONG ?
          cxSrc LONG ?
          cySrc LONG ?
          offBmiSrc DWORD ?
          cbBmiSrc DWORD ?
          offBitsSrc DWORD ?
          cbBitsSrc DWORD ?
          iUsageSrc DWORD ?
          iStartScan DWORD ?
          cScans DWORD ?
        EMRSETDIBITSTODEVICE ends
        tagEMRSETDIBITSTODEVICE typedef EMRSETDIBITSTODEVICE
        PEMRSETDIBITSTODEVICE typedef ptr EMRSETDIBITSTODEVICE
        EMRSTRETCHDIBITS struct
          emr EMR <>
          rclBounds RECTL <>
          xDest LONG ?
          yDest LONG ?
          xSrc LONG ?
          ySrc LONG ?
          cxSrc LONG ?
          cySrc LONG ?
          offBmiSrc DWORD ?
          cbBmiSrc DWORD ?
          offBitsSrc DWORD ?
          cbBitsSrc DWORD ?
          iUsageSrc DWORD ?
          dwRop DWORD ?
          cxDest LONG ?
          cyDest LONG ?
        EMRSTRETCHDIBITS ends
        tagEMRSTRETCHDIBITS typedef EMRSTRETCHDIBITS
        PEMRSTRETCHDIBITS typedef ptr EMRSTRETCHDIBITS
        EMREXTCREATEFONTINDIRECTW struct
          emr EMR <>
          ihFont DWORD ?
          elfw EXTLOGFONTW <>
        EMREXTCREATEFONTINDIRECTW ends
        tagEMREXTCREATEFONTINDIRECTW typedef EMREXTCREATEFONTINDIRECTW
        PEMREXTCREATEFONTINDIRECTW typedef ptr EMREXTCREATEFONTINDIRECTW
        EMRCREATEPALETTE struct
          emr EMR <>
          ihPal DWORD ?
          lgpl LOGPALETTE <>
        EMRCREATEPALETTE ends
        tagEMRCREATEPALETTE typedef EMRCREATEPALETTE
        PEMRCREATEPALETTE typedef ptr EMRCREATEPALETTE
        EMRCREATEPEN struct
          emr EMR <>
          ihPen DWORD ?
          lopn LOGPEN <>
        EMRCREATEPEN ends
        tagEMRCREATEPEN typedef EMRCREATEPEN
        PEMRCREATEPEN typedef ptr EMRCREATEPEN
        EMREXTCREATEPEN struct
          emr EMR <>
          ihPen DWORD ?
          offBmi DWORD ?
          cbBmi DWORD ?
          offBits DWORD ?
          cbBits DWORD ?
          elp EXTLOGPEN32 <>
        EMREXTCREATEPEN ends
        tagEMREXTCREATEPEN typedef EMREXTCREATEPEN
        PEMREXTCREATEPEN typedef ptr EMREXTCREATEPEN
        EMRCREATEBRUSHINDIRECT struct
          emr EMR <>
          ihBrush DWORD ?
          lb LOGBRUSH32 <>
        EMRCREATEBRUSHINDIRECT ends
        tagEMRCREATEBRUSHINDIRECT typedef EMRCREATEBRUSHINDIRECT
        PEMRCREATEBRUSHINDIRECT typedef ptr EMRCREATEBRUSHINDIRECT
        EMRCREATEMONOBRUSH struct
          emr EMR <>
          ihBrush DWORD ?
          iUsage DWORD ?
          offBmi DWORD ?
          cbBmi DWORD ?
          offBits DWORD ?
          cbBits DWORD ?
        EMRCREATEMONOBRUSH ends
        tagEMRCREATEMONOBRUSH typedef EMRCREATEMONOBRUSH
        PEMRCREATEMONOBRUSH typedef ptr EMRCREATEMONOBRUSH
        EMRCREATEDIBPATTERNBRUSHPT struct
          emr EMR <>
          ihBrush DWORD ?
          iUsage DWORD ?
          offBmi DWORD ?
          cbBmi DWORD ?
          offBits DWORD ?
          cbBits DWORD ?
        EMRCREATEDIBPATTERNBRUSHPT ends
        tagEMRCREATEDIBPATTERNBRUSHPT typedef EMRCREATEDIBPATTERNBRUSHPT
        PEMRCREATEDIBPATTERNBRUSHPT typedef ptr EMRCREATEDIBPATTERNBRUSHPT
        EMRFORMAT struct
          dSignature DWORD ?
          nVersion DWORD ?
          cbData DWORD ?
          offData DWORD ?
        EMRFORMAT ends
        tagEMRFORMAT typedef EMRFORMAT
        PEMRFORMAT typedef ptr EMRFORMAT
        if (WINVER ge 0400h)
          EMRGLSRECORD struct
            emr EMR <>
            cbData DWORD ?
            Data BYTE 1 dup (?)
          EMRGLSRECORD ends
          tagEMRGLSRECORD typedef EMRGLSRECORD
          PEMRGLSRECORD typedef ptr EMRGLSRECORD
          EMRGLSBOUNDEDRECORD struct
            emr EMR <>
            rclBounds RECTL <>
            cbData DWORD ?
            Data BYTE 1 dup (?)
          EMRGLSBOUNDEDRECORD ends
          tagEMRGLSBOUNDEDRECORD typedef EMRGLSBOUNDEDRECORD
          PEMRGLSBOUNDEDRECORD typedef ptr EMRGLSBOUNDEDRECORD
          EMRPIXELFORMAT struct
            emr EMR <>
            pfd PIXELFORMATDESCRIPTOR <>
          EMRPIXELFORMAT ends
          tagEMRPIXELFORMAT typedef EMRPIXELFORMAT
          PEMRPIXELFORMAT typedef ptr EMRPIXELFORMAT
          EMRCREATECOLORSPACE struct
            emr EMR <>
            ihCS DWORD ?
            lcs LOGCOLORSPACEA <>
          EMRCREATECOLORSPACE ends
          tagEMRCREATECOLORSPACE typedef EMRCREATECOLORSPACE
          PEMRCREATECOLORSPACE typedef ptr EMRCREATECOLORSPACE
          EMRSETCOLORSPACE struct
            emr EMR <>
            ihCS DWORD ?
          EMRSETCOLORSPACE ends
          tagEMRSETCOLORSPACE typedef EMRSETCOLORSPACE
          PEMRSETCOLORSPACE typedef ptr EMRSETCOLORSPACE
          EMRSELECTCOLORSPACE typedef EMRSETCOLORSPACE
          PEMRSELECTCOLORSPACE typedef ptr EMRSETCOLORSPACE
          EMRDELETECOLORSPACE typedef EMRSETCOLORSPACE
          PEMRDELETECOLORSPACE typedef ptr EMRSETCOLORSPACE
        endif
        if (WINVER ge 0500h)
          EMREXTESCAPE struct
            emr EMR <>
            iEscape INT_ ?
            cbEscData INT_ ?
            EscData BYTE 1 dup (?)
          EMREXTESCAPE ends
          tagEMREXTESCAPE typedef EMREXTESCAPE
          PEMREXTESCAPE typedef ptr EMREXTESCAPE
          EMRDRAWESCAPE typedef EMREXTESCAPE
          PEMRDRAWESCAPE typedef ptr EMREXTESCAPE
          EMRNAMEDESCAPE struct
            emr EMR <>
            iEscape INT_ ?
            cbDriver INT_ ?
            cbEscData INT_ ?
            EscData BYTE 1 dup (?)
          EMRNAMEDESCAPE ends
          tagEMRNAMEDESCAPE typedef EMRNAMEDESCAPE
          PEMRNAMEDESCAPE typedef ptr EMRNAMEDESCAPE
          SETICMPROFILE_EMBEDED equ 00000001h
          EMRSETICMPROFILE struct
            emr EMR <>
            dwFlags DWORD ?
            cbName DWORD ?
            cbData DWORD ?
            Data BYTE 1 dup (?)
          EMRSETICMPROFILE ends
          tagEMRSETICMPROFILE typedef EMRSETICMPROFILE
          PEMRSETICMPROFILE typedef ptr EMRSETICMPROFILE
          EMRSETICMPROFILEA typedef EMRSETICMPROFILE
          PEMRSETICMPROFILEA typedef ptr EMRSETICMPROFILE
          EMRSETICMPROFILEW typedef EMRSETICMPROFILE
          PEMRSETICMPROFILEW typedef ptr EMRSETICMPROFILE
          CREATECOLORSPACE_EMBEDED equ 00000001h
          EMRCREATECOLORSPACEW struct
            emr EMR <>
            ihCS DWORD ?
            lcs LOGCOLORSPACEW <>
            dwFlags DWORD ?
            cbData DWORD ?
            Data BYTE 1 dup (?)
          EMRCREATECOLORSPACEW ends
          tagEMRCREATECOLORSPACEW typedef EMRCREATECOLORSPACEW
          PEMRCREATECOLORSPACEW typedef ptr EMRCREATECOLORSPACEW
          COLORMATCHTOTARGET_EMBEDED equ 00000001h
          EMRCOLORMATCHTOTARGET struct
            emr EMR <>
            dwAction DWORD ?
            dwFlags DWORD ?
            cbName DWORD ?
            cbData DWORD ?
            Data BYTE 1 dup (?)
          EMRCOLORMATCHTOTARGET ends
          tagCOLORMATCHTOTARGET typedef EMRCOLORMATCHTOTARGET
          PEMRCOLORMATCHTOTARGET typedef ptr EMRCOLORMATCHTOTARGET
          EMRCOLORCORRECTPALETTE struct
            emr EMR <>
            ihPalette DWORD ?
            nFirstEntry DWORD ?
            nPalEntries DWORD ?
            nReserved DWORD ?
          EMRCOLORCORRECTPALETTE ends
          tagCOLORCORRECTPALETTE typedef EMRCOLORCORRECTPALETTE
          PEMRCOLORCORRECTPALETTE typedef ptr EMRCOLORCORRECTPALETTE
          EMRALPHABLEND struct
            emr EMR <>
            rclBounds RECTL <>
            xDest LONG ?
            yDest LONG ?
            cxDest LONG ?
            cyDest LONG ?
            dwRop DWORD ?
            xSrc LONG ?
            ySrc LONG ?
            xformSrc XFORM <>
            crBkColorSrc COLORREF ?
            iUsageSrc DWORD ?
            offBmiSrc DWORD ?
            cbBmiSrc DWORD ?
            offBitsSrc DWORD ?
            cbBitsSrc DWORD ?
            cxSrc LONG ?
            cySrc LONG ?
          EMRALPHABLEND ends
          tagEMRALPHABLEND typedef EMRALPHABLEND
          PEMRALPHABLEND typedef ptr EMRALPHABLEND
          EMRGRADIENTFILL struct
            emr EMR <>
            rclBounds RECTL <>
            nVer DWORD ?
            nTri DWORD ?
            ulMode ULONG ?
            Ver TRIVERTEX 1 dup (<>)
          EMRGRADIENTFILL ends
          tagEMRGRADIENTFILL typedef EMRGRADIENTFILL
          PEMRGRADIENTFILL typedef ptr EMRGRADIENTFILL
          EMRTRANSPARENTBLT struct
            emr EMR <>
            rclBounds RECTL <>
            xDest LONG ?
            yDest LONG ?
            cxDest LONG ?
            cyDest LONG ?
            dwRop DWORD ?
            xSrc LONG ?
            ySrc LONG ?
            xformSrc XFORM <>
            crBkColorSrc COLORREF ?
            iUsageSrc DWORD ?
            offBmiSrc DWORD ?
            cbBmiSrc DWORD ?
            offBitsSrc DWORD ?
            cbBitsSrc DWORD ?
            cxSrc LONG ?
            cySrc LONG ?
          EMRTRANSPARENTBLT ends
          tagEMRTRANSPARENTBLT typedef EMRTRANSPARENTBLT
          PEMRTRANSPARENTBLT typedef ptr EMRTRANSPARENTBLT
        endif
        GDICOMMENT_IDENTIFIER equ 43494447h
        GDICOMMENT_WINDOWS_METAFILE equ 80000001h
        GDICOMMENT_BEGINGROUP equ 00000002h
        GDICOMMENT_ENDGROUP equ 00000003h
        GDICOMMENT_MULTIFORMATS equ 40000004h
        EPS_SIGNATURE equ 46535045h
        GDICOMMENT_UNICODE_STRING equ 00000040h
        GDICOMMENT_UNICODE_END equ 00000080h
      endif
      @DefProto DllImport, wglCopyContext, WIN_STD_CALL_CONV,, <:HGLRC, :HGLRC, :UINT>, 12
      @DefProto DllImport, wglCreateContext, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, wglCreateLayerContext, WIN_STD_CALL_CONV,, <:HDC, :SDWORD>, 8
      @DefProto DllImport, wglDeleteContext, WIN_STD_CALL_CONV,, <:HGLRC>, 4
      @DefProto DllImport, wglGetCurrentContext, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, wglGetCurrentDC, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, wglGetProcAddress, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
      @DefProto DllImport, wglMakeCurrent, WIN_STD_CALL_CONV,, <:HDC, :HGLRC>, 8
      @DefProto DllImport, wglShareLists, WIN_STD_CALL_CONV,, <:HGLRC, :HGLRC>, 8
      @DefProto DllImport, wglUseFontBitmapsA, WIN_STD_CALL_CONV,, <:HDC, :DWORD, :DWORD, :DWORD>, 16
      @DefProto DllImport, wglUseFontBitmapsW, WIN_STD_CALL_CONV,, <:HDC, :DWORD, :DWORD, :DWORD>, 16
      ifdef UNICODE
        wglUseFontBitmaps equ <wglUseFontBitmapsW>
      else
        wglUseFontBitmaps equ <wglUseFontBitmapsA>
      endif
      @DefProto DllImport, SwapBuffers, WIN_STD_CALL_CONV,, <:HDC>, 4
      POINTFLOAT struct
        x FLOAT ?
        y FLOAT ?
      POINTFLOAT ends
      _POINTFLOAT typedef POINTFLOAT
      PPOINTFLOAT typedef ptr POINTFLOAT
      GLYPHMETRICSFLOAT struct
        gmfBlackBoxX FLOAT ?
        gmfBlackBoxY FLOAT ?
        gmfptGlyphOrigin POINTFLOAT <>
        gmfCellIncX FLOAT ?
        gmfCellIncY FLOAT ?
      GLYPHMETRICSFLOAT ends
      _GLYPHMETRICSFLOAT typedef GLYPHMETRICSFLOAT
      PGLYPHMETRICSFLOAT typedef ptr GLYPHMETRICSFLOAT
      LPGLYPHMETRICSFLOAT typedef ptr GLYPHMETRICSFLOAT
      WGL_FONT_LINES equ 0
      WGL_FONT_POLYGONS equ 1
      @DefProto DllImport, wglUseFontOutlinesA, WIN_STD_CALL_CONV,, <:HDC, :DWORD, :DWORD, :DWORD, :FLOAT, :FLOAT, :SDWORD, :LPGLYPHMETRICSFLOAT>, 32
      @DefProto DllImport, wglUseFontOutlinesW, WIN_STD_CALL_CONV,, <:HDC, :DWORD, :DWORD, :DWORD, :FLOAT, :FLOAT, :SDWORD, :LPGLYPHMETRICSFLOAT>, 32
      ifdef UNICODE
        wglUseFontOutlines equ <wglUseFontOutlinesW>
      else
        wglUseFontOutlines equ <wglUseFontOutlinesA>
      endif
      LAYERPLANEDESCRIPTOR struct
        nSize WORD ?
        nVersion WORD ?
        dwFlags DWORD ?
        iPixelType BYTE ?
        cColorBits BYTE ?
        cRedBits BYTE ?
        cRedShift BYTE ?
        cGreenBits BYTE ?
        cGreenShift BYTE ?
        cBlueBits BYTE ?
        cBlueShift BYTE ?
        cAlphaBits BYTE ?
        cAlphaShift BYTE ?
        cAccumBits BYTE ?
        cAccumRedBits BYTE ?
        cAccumGreenBits BYTE ?
        cAccumBlueBits BYTE ?
        cAccumAlphaBits BYTE ?
        cDepthBits BYTE ?
        cStencilBits BYTE ?
        cAuxBuffers BYTE ?
        iLayerPlane BYTE ?
        bReserved BYTE ?
        crTransparent COLORREF ?
      LAYERPLANEDESCRIPTOR ends
      tagLAYERPLANEDESCRIPTOR typedef LAYERPLANEDESCRIPTOR
      PLAYERPLANEDESCRIPTOR typedef ptr LAYERPLANEDESCRIPTOR
      LPLAYERPLANEDESCRIPTOR typedef ptr LAYERPLANEDESCRIPTOR
      LPD_DOUBLEBUFFER equ 00000001h
      LPD_STEREO equ 00000002h
      LPD_SUPPORT_GDI equ 00000010h
      LPD_SUPPORT_OPENGL equ 00000020h
      LPD_SHARE_DEPTH equ 00000040h
      LPD_SHARE_STENCIL equ 00000080h
      LPD_SHARE_ACCUM equ 00000100h
      LPD_SWAP_EXCHANGE equ 00000200h
      LPD_SWAP_COPY equ 00000400h
      LPD_TRANSPARENT equ 00001000h
      LPD_TYPE_RGBA equ 0
      LPD_TYPE_COLORINDEX equ 1
      WGL_SWAP_MAIN_PLANE equ 00000001h
      WGL_SWAP_OVERLAY1 equ 00000002h
      WGL_SWAP_OVERLAY2 equ 00000004h
      WGL_SWAP_OVERLAY3 equ 00000008h
      WGL_SWAP_OVERLAY4 equ 00000010h
      WGL_SWAP_OVERLAY5 equ 00000020h
      WGL_SWAP_OVERLAY6 equ 00000040h
      WGL_SWAP_OVERLAY7 equ 00000080h
      WGL_SWAP_OVERLAY8 equ 00000100h
      WGL_SWAP_OVERLAY9 equ 00000200h
      WGL_SWAP_OVERLAY10 equ 00000400h
      WGL_SWAP_OVERLAY11 equ 00000800h
      WGL_SWAP_OVERLAY12 equ 00001000h
      WGL_SWAP_OVERLAY13 equ 00002000h
      WGL_SWAP_OVERLAY14 equ 00004000h
      WGL_SWAP_OVERLAY15 equ 00008000h
      WGL_SWAP_UNDERLAY1 equ 00010000h
      WGL_SWAP_UNDERLAY2 equ 00020000h
      WGL_SWAP_UNDERLAY3 equ 00040000h
      WGL_SWAP_UNDERLAY4 equ 00080000h
      WGL_SWAP_UNDERLAY5 equ 00100000h
      WGL_SWAP_UNDERLAY6 equ 00200000h
      WGL_SWAP_UNDERLAY7 equ 00400000h
      WGL_SWAP_UNDERLAY8 equ 00800000h
      WGL_SWAP_UNDERLAY9 equ 01000000h
      WGL_SWAP_UNDERLAY10 equ 02000000h
      WGL_SWAP_UNDERLAY11 equ 04000000h
      WGL_SWAP_UNDERLAY12 equ 08000000h
      WGL_SWAP_UNDERLAY13 equ 10000000h
      WGL_SWAP_UNDERLAY14 equ 20000000h
      WGL_SWAP_UNDERLAY15 equ 40000000h
      @DefProto DllImport, wglDescribeLayerPlane, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :UINT, :LPLAYERPLANEDESCRIPTOR>, 20
      @DefProto DllImport, wglSetLayerPaletteEntries, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :SDWORD, :ptr COLORREF>, 20
      @DefProto DllImport, wglGetLayerPaletteEntries, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :SDWORD, :ptr COLORREF>, 20
      @DefProto DllImport, wglRealizeLayerPalette, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :BOOL>, 12
      @DefProto DllImport, wglSwapLayerBuffers, WIN_STD_CALL_CONV,, <:HDC, :UINT>, 8
      if (WINVER ge 0500h)
        WGLSWAP struct
          hdc HDC ?
          uiFlags UINT ?
        WGLSWAP ends
        _WGLSWAP typedef WGLSWAP
        PWGLSWAP typedef ptr WGLSWAP
        LPWGLSWAP typedef ptr WGLSWAP
        WGL_SWAPMULTIPLE_MAX equ 16
        @DefProto DllImport, wglSwapMultipleBuffers, WIN_STD_CALL_CONV,, <:UINT, :ptr WGLSWAP>, 8
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if _MSC_VER ge 1200
  endif
endif
