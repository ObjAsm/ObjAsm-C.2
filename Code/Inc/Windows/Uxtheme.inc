;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\Uxtheme.h', last modified: 19/04/2018 10:46
;Creation parameters: 

ifndef _UXTHEME_H_
  _UXTHEME_H_ equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    include commctrl.inc
    include SpecStrings.inc
    ifndef THEMEAPI
      if  not Defined(_UXTHEME_)
        THEMEAPI equ <EXTERN_C DECLSPEC_IMPORT HRESULT STDAPICALLTYPE>
        THEMEAPI_ macro type_
          exitm <EXTERN_C DECLSPEC_IMPORT type_ STDAPICALLTYPE>
        endm
      else
        THEMEAPI equ <STDAPI>
        THEMEAPI_ macro type_
          exitm <STDAPI_(type_)>
        endm
      endif
    endif
    HTHEME typedef HANDLE
    if (NTDDI_VERSION ge NTDDI_VISTA)
      MAX_THEMECOLOR equ 64
      MAX_THEMESIZE equ 64
    endif
    if (NTDDI_VERSION ge NTDDI_WIN7)
      BeginPanningFeedback proto WIN_STD_CALL_CONV :HWND
      UpdatePanningFeedback proto WIN_STD_CALL_CONV :HWND, :LONG, :LONG, :BOOL
      EndPanningFeedback proto WIN_STD_CALL_CONV :HWND, :BOOL
    endif
    if (NTDDI_VERSION ge NTDDI_WIN8)
      TA_PROPERTY typedef SDWORD
      TAP_FLAGS equ 0
      TAP_TRANSFORMCOUNT equ 1
      TAP_STAGGERDELAY equ 2
      TAP_STAGGERDELAYCAP equ 3
      TAP_STAGGERDELAYFACTOR equ 4
      TAP_ZORDER equ 5
      
      TA_PROPERTY_FLAG typedef SDWORD
      TAPF_NONE equ 0h
      TAPF_HASSTAGGER equ 1h
      TAPF_ISRTLAWARE equ 2h
      TAPF_ALLOWCOLLECTION equ 4h
      TAPF_HASBACKGROUND equ 8h
      TAPF_HASPERSPECTIVE equ 10h
      
      DEFINE_ENUM_FLAG_OPERATORS(TA_PROPERTY_FLAG)
      @DefProto DllImport, GetThemeAnimationProperty, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD, :TA_PROPERTY, :ptr VOID, :DWORD, :ptr DWORD>, 28
      TA_TRANSFORM_TYPE typedef SDWORD
      TATT_TRANSLATE_2D equ 0
      TATT_SCALE_2D equ 1
      TATT_OPACITY equ 2
      TATT_CLIP equ 3
      
      TA_TRANSFORM_FLAG typedef SDWORD
      TATF_NONE equ 0h
      TATF_TARGETVALUES_USER equ 1h
      TATF_HASINITIALVALUES equ 2h
      TATF_HASORIGINVALUES equ 4h
      
      DEFINE_ENUM_FLAG_OPERATORS(TA_TRANSFORM_FLAG)
      include pshpack8.inc
      TA_TRANSFORM struct
        eTransformType TA_TRANSFORM_TYPE ?
        dwTimingFunctionId DWORD ?
        dwStartTime DWORD ?
        dwDurationTime DWORD ?
        eFlags_ TA_TRANSFORM_FLAG ?
      TA_TRANSFORM ends

      PTA_TRANSFORM typedef ptr TA_TRANSFORM
      
      TA_TRANSFORM_2D struct
        header TA_TRANSFORM <>
        rX REAL4 ?
        rY REAL4 ?
        rInitialX REAL4 ?
        rInitialY REAL4 ?
        rOriginX REAL4 ?
        rOriginY REAL4 ?
      TA_TRANSFORM_2D ends

      PTA_TRANSFORM_2D typedef ptr TA_TRANSFORM_2D
      
      TA_TRANSFORM_OPACITY struct
        header TA_TRANSFORM <>
        rOpacity REAL4 ?
        rInitialOpacity REAL4 ?
      TA_TRANSFORM_OPACITY ends

      PTA_TRANSFORM_OPACITY typedef ptr TA_TRANSFORM_OPACITY
      
      TA_TRANSFORM_CLIP struct
        header TA_TRANSFORM <>
        rLeft REAL4 ?
        rTop REAL4 ?
        rRight REAL4 ?
        rBottom REAL4 ?
        rInitialLeft REAL4 ?
        rInitialTop REAL4 ?
        rInitialRight REAL4 ?
        rInitialBottom REAL4 ?
      TA_TRANSFORM_CLIP ends

      PTA_TRANSFORM_CLIP typedef ptr TA_TRANSFORM_CLIP
      
      include poppack.inc
      @DefProto DllImport, GetThemeAnimationTransform, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD, :DWORD, :ptr TA_TRANSFORM, :DWORD, :ptr DWORD>, 28
      TA_TIMINGFUNCTION_TYPE typedef SDWORD
      TTFT_UNDEFINED equ 0
      TTFT_CUBIC_BEZIER equ 1
      
      include pshpack8.inc
      TA_TIMINGFUNCTION struct
        eTimingFunctionType TA_TIMINGFUNCTION_TYPE ?
      TA_TIMINGFUNCTION ends

      PTA_TIMINGFUNCTION typedef ptr TA_TIMINGFUNCTION
      
      TA_CUBIC_BEZIER struct
        header TA_TIMINGFUNCTION <>
        rX0 REAL4 ?
        rY0 REAL4 ?
        rX1 REAL4 ?
        rY1 REAL4 ?
      TA_CUBIC_BEZIER ends

      PTA_CUBIC_BEZIER typedef ptr TA_CUBIC_BEZIER
      
      include poppack.inc
      @DefProto DllImport, GetThemeTimingFunction, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :ptr TA_TIMINGFUNCTION, :DWORD, :ptr DWORD>, 20
    endif
    @DefProto DllImport, OpenThemeData, WIN_STD_CALL_CONV,, <:HWND, :LPCWSTR>, 8
    OTD_FORCE_RECT_SIZING equ 00000001h
    OTD_NONCLIENT equ 00000002h
    OTD_VALIDBITS equ <(OTD_FORCE_RECT_SIZING or OTD_NONCLIENT)>
    @DefProto DllImport, OpenThemeDataForDpi, WIN_STD_CALL_CONV,, <:HWND, :LPCWSTR, :UINT>, 12
    @DefProto DllImport, OpenThemeDataEx, WIN_STD_CALL_CONV,, <:HWND, :LPCWSTR, :DWORD>, 12
    @DefProto DllImport, CloseThemeData, WIN_STD_CALL_CONV,, <:HTHEME>, 4
    @DefProto DllImport, DrawThemeBackground, WIN_STD_CALL_CONV,, <:HTHEME, :HDC, :SDWORD, :SDWORD, :LPCRECT, :LPCRECT>, 24
    DTBG_CLIPRECT equ 00000001h
    DTBG_DRAWSOLID equ 00000002h
    DTBG_OMITBORDER equ 00000004h
    DTBG_OMITCONTENT equ 00000008h
    DTBG_COMPUTINGREGION equ 00000010h
    DTBG_MIRRORDC equ 00000020h
    DTBG_NOMIRROR equ 00000040h
    DTBG_VALIDBITS equ <(DTBG_CLIPRECT or DTBG_DRAWSOLID or DTBG_OMITBORDER or DTBG_OMITCONTENT or DTBG_COMPUTINGREGION or DTBG_MIRRORDC or DTBG_NOMIRROR)>
    DTBGOPTS struct
      dwSize DWORD ?
      dwFlags DWORD ?
      rcClip RECT <>
    DTBGOPTS ends

    _DTBGOPTS typedef DTBGOPTS
    PDTBGOPTS typedef ptr DTBGOPTS
    
    @DefProto DllImport, DrawThemeBackgroundEx, WIN_STD_CALL_CONV,, <:HTHEME, :HDC, :SDWORD, :SDWORD, :LPCRECT, :ptr DTBGOPTS>, 24
    DTT_GRAYED equ 00000001h
    DTT_FLAGS2VALIDBITS equ <(DTT_GRAYED)>
    @DefProto DllImport, DrawThemeText, WIN_STD_CALL_CONV,, <:HTHEME, :HDC, :SDWORD, :SDWORD, :LPCWSTR, :SDWORD, :DWORD, :DWORD, :LPCRECT>, 36
    @DefProto DllImport, GetThemeBackgroundContentRect, WIN_STD_CALL_CONV,, <:HTHEME, :HDC, :SDWORD, :SDWORD, :LPCRECT, :LPRECT>, 24
    @DefProto DllImport, GetThemeBackgroundExtent, WIN_STD_CALL_CONV,, <:HTHEME, :HDC, :SDWORD, :SDWORD, :LPCRECT, :LPRECT>, 24
    @DefProto DllImport, GetThemeBackgroundRegion, WIN_STD_CALL_CONV,, <:HTHEME, :HDC, :SDWORD, :SDWORD, :LPCRECT, :ptr HRGN>, 24
    THEMESIZE typedef SDWORD
    TS_MIN equ 0
    TS_TRUE equ 1
    TS_DRAW equ 2
    
    @DefProto DllImport, GetThemePartSize, WIN_STD_CALL_CONV,, <:HTHEME, :HDC, :SDWORD, :SDWORD, :LPCRECT, :THEMESIZE, :ptr SIZE_>, 28
    @DefProto DllImport, GetThemeTextExtent, WIN_STD_CALL_CONV,, <:HTHEME, :HDC, :SDWORD, :SDWORD, :LPCWSTR, :SDWORD, :DWORD, :LPCRECT, :LPRECT>, 36
    @DefProto DllImport, GetThemeTextMetrics, WIN_STD_CALL_CONV,, <:HTHEME, :HDC, :SDWORD, :SDWORD, :ptr TEXTMETRICW>, 20
    HTTB_BACKGROUNDSEG equ 00000000h
    HTTB_FIXEDBORDER equ 00000002h
    HTTB_CAPTION equ 00000004h
    HTTB_RESIZINGBORDER_LEFT equ 00000010h
    HTTB_RESIZINGBORDER_TOP equ 00000020h
    HTTB_RESIZINGBORDER_RIGHT equ 00000040h
    HTTB_RESIZINGBORDER_BOTTOM equ 00000080h
    HTTB_RESIZINGBORDER equ <(HTTB_RESIZINGBORDER_LEFT or HTTB_RESIZINGBORDER_TOP or HTTB_RESIZINGBORDER_RIGHT or HTTB_RESIZINGBORDER_BOTTOM)>
    HTTB_SIZINGTEMPLATE equ 00000100h
    HTTB_SYSTEMSIZINGMARGINS equ 00000200h
    @DefProto DllImport, HitTestThemeBackground, WIN_STD_CALL_CONV,, <:HTHEME, :HDC, :SDWORD, :SDWORD, :DWORD, :LPCRECT, :HRGN, :POINT, :ptr WORD>, 40
    @DefProto DllImport, DrawThemeEdge, WIN_STD_CALL_CONV,, <:HTHEME, :HDC, :SDWORD, :SDWORD, :LPCRECT, :UINT, :UINT, :LPRECT>, 32
    @DefProto DllImport, DrawThemeIcon, WIN_STD_CALL_CONV,, <:HTHEME, :HDC, :SDWORD, :SDWORD, :LPCRECT, :HIMAGELIST, :SDWORD>, 28
    @DefProto DllImport, IsThemePartDefined, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD>, 12
    @DefProto DllImport, IsThemeBackgroundPartiallyTransparent, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD>, 12
    @DefProto DllImport, GetThemeColor, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD, :SDWORD, :ptr COLORREF>, 20
    @DefProto DllImport, GetThemeMetric, WIN_STD_CALL_CONV,, <:HTHEME, :HDC, :SDWORD, :SDWORD, :SDWORD, :ptr SDWORD>, 24
    @DefProto DllImport, GetThemeString, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD, :SDWORD, :LPWSTR, :SDWORD>, 24
    @DefProto DllImport, GetThemeBool, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD, :SDWORD, :ptr BOOL>, 20
    @DefProto DllImport, GetThemeInt, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD, :SDWORD, :ptr SDWORD>, 20
    @DefProto DllImport, GetThemeEnumValue, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD, :SDWORD, :ptr SDWORD>, 20
    @DefProto DllImport, GetThemePosition, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD, :SDWORD, :ptr POINT>, 20
    @DefProto DllImport, GetThemeFont, WIN_STD_CALL_CONV,, <:HTHEME, :HDC, :SDWORD, :SDWORD, :SDWORD, :ptr LOGFONTW>, 24
    @DefProto DllImport, GetThemeRect, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD, :SDWORD, :LPRECT>, 20
    MARGINS struct
      cxLeftWidth SDWORD ?
      cxRightWidth SDWORD ?
      cyTopHeight SDWORD ?
      cyBottomHeight SDWORD ?
    MARGINS ends

    _MARGINS typedef MARGINS
    PMARGINS typedef ptr MARGINS
    
    @DefProto DllImport, GetThemeMargins, WIN_STD_CALL_CONV,, <:HTHEME, :HDC, :SDWORD, :SDWORD, :SDWORD, :LPCRECT, :ptr MARGINS>, 28
    if (NTDDI_VERSION ge NTDDI_VISTA)
      MAX_INTLIST_COUNT equ 402
    else
      MAX_INTLIST_COUNT equ 10
    endif
    INTLIST struct
      iValueCount SDWORD ?
      iValues SDWORD MAX_INTLIST_COUNT dup (?)
    INTLIST ends

    _INTLIST typedef INTLIST
    PINTLIST typedef ptr INTLIST
    
    @DefProto DllImport, GetThemeIntList, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD, :SDWORD, :ptr INTLIST>, 20
    PROPERTYORIGIN typedef SDWORD
    PO_STATE equ 0
    PO_PART equ 1
    PO_CLASS equ 2
    PO_GLOBAL equ 3
    PO_NOTFOUND equ 4
    
    @DefProto DllImport, GetThemePropertyOrigin, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD, :SDWORD, :ptr PROPERTYORIGIN>, 20
    @DefProto DllImport, SetWindowTheme, WIN_STD_CALL_CONV,, <:HWND, :LPCWSTR, :LPCWSTR>, 12
    @DefProto DllImport, GetThemeFilename, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD, :SDWORD, :LPWSTR, :SDWORD>, 24
    @DefProto DllImport, GetThemeSysColor, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD>, 8
    @DefProto DllImport, GetThemeSysColorBrush, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD>, 8
    @DefProto DllImport, GetThemeSysBool, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD>, 8
    @DefProto DllImport, GetThemeSysSize, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD>, 8
    @DefProto DllImport, GetThemeSysFont, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :ptr LOGFONTW>, 12
    @DefProto DllImport, GetThemeSysString, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :LPWSTR, :SDWORD>, 16
    @DefProto DllImport, GetThemeSysInt, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :ptr SDWORD>, 12
    @DefProto DllImport, IsThemeActive, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, IsAppThemed, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, GetWindowTheme, WIN_STD_CALL_CONV,, <:HWND>, 4
    ETDT_DISABLE equ 00000001h
    ETDT_ENABLE equ 00000002h
    ETDT_USETABTEXTURE equ 00000004h
    ETDT_ENABLETAB equ <(ETDT_ENABLE or ETDT_USETABTEXTURE)>
    if (NTDDI_VERSION ge NTDDI_VISTA)
      ETDT_USEAEROWIZARDTABTEXTURE equ 00000008h
      ETDT_ENABLEAEROWIZARDTAB equ <(ETDT_ENABLE or ETDT_USEAEROWIZARDTABTEXTURE)>
      ETDT_VALIDBITS equ <(ETDT_DISABLE or ETDT_ENABLE or ETDT_USETABTEXTURE or ETDT_USEAEROWIZARDTABTEXTURE)>
    endif
    @DefProto DllImport, EnableThemeDialogTexture, WIN_STD_CALL_CONV,, <:HWND, :DWORD>, 8
    @DefProto DllImport, IsThemeDialogTextureEnabled, WIN_STD_CALL_CONV,, <:HWND>, 4
    STAP_ALLOW_NONCLIENT equ (1 shl 0)
    STAP_ALLOW_CONTROLS equ (1 shl 1)
    STAP_ALLOW_WEBCONTENT equ (1 shl 2)
    STAP_VALIDBITS equ <(STAP_ALLOW_NONCLIENT or STAP_ALLOW_CONTROLS or STAP_ALLOW_WEBCONTENT)>
    @DefProto DllImport, GetThemeAppProperties, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, SetThemeAppProperties, WIN_STD_CALL_CONV,, <:DWORD>, 4
    @DefProto DllImport, GetCurrentThemeName, WIN_STD_CALL_CONV,, <:LPWSTR, :SDWORD, :LPWSTR, :SDWORD, :LPWSTR, :SDWORD>, 24
    SZ_THDOCPROP_DISPLAYNAME equ <L("DisplayName")>
    SZ_THDOCPROP_CANONICALNAME equ <L("ThemeName")>
    SZ_THDOCPROP_TOOLTIP equ <L("ToolTip")>
    SZ_THDOCPROP_AUTHOR equ <L("author")>
    @DefProto DllImport, GetThemeDocumentationProperty, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPWSTR, :SDWORD>, 16
    @DefProto DllImport, DrawThemeParentBackground, WIN_STD_CALL_CONV,, <:HWND, :HDC, :ptr RECT>, 12
    @DefProto DllImport, EnableTheming, WIN_STD_CALL_CONV,, <:BOOL>, 4
    GBF_DIRECT equ 00000001h
    GBF_COPY equ 00000002h
    GBF_VALIDBITS equ <(GBF_DIRECT or GBF_COPY)>
    if (NTDDI_VERSION ge NTDDI_VISTA)
      DTPB_WINDOWDC equ 00000001h
      DTPB_USECTLCOLORSTATIC equ 00000002h
      DTPB_USEERASEBKGND equ 00000004h
      @DefProto DllImport, DrawThemeParentBackgroundEx, WIN_STD_CALL_CONV,, <:HWND, :HDC, :DWORD, :ptr RECT>, 16
      WINDOWTHEMEATTRIBUTETYPE typedef SDWORD
      WTA_NONCLIENT equ 1
      
      WTA_OPTIONS struct
        dwFlags DWORD ?
        dwMask DWORD ?
      WTA_OPTIONS ends

      _WTA_OPTIONS typedef WTA_OPTIONS
      PWTA_OPTIONS typedef ptr WTA_OPTIONS
      
      WTNCA_NODRAWCAPTION equ 00000001h
      WTNCA_NODRAWICON equ 00000002h
      WTNCA_NOSYSMENU equ 00000004h
      WTNCA_NOMIRRORHELP equ 00000008h
      WTNCA_VALIDBITS equ <(WTNCA_NODRAWCAPTION or WTNCA_NODRAWICON or WTNCA_NOSYSMENU or WTNCA_NOMIRRORHELP)>
      @DefProto DllImport, SetWindowThemeAttribute, WIN_STD_CALL_CONV,, <:HWND, :WINDOWTHEMEATTRIBUTETYPE, :PVOID, :DWORD>, 16
      SetWindowThemeNonClientAttributes proto WIN_STD_CALL_CONV :HWND, :DWORD, :DWORD
    endif
    TYPE_DTT_CALLBACK_PROC typedef proto WIN_STD_CALL_CONV :HDC, :LPWSTR, :SDWORD, :LPRECT, :UINT, :LPARAM
    DTT_CALLBACK_PROC typedef ptr TYPE_DTT_CALLBACK_PROC
    DTT_TEXTCOLOR equ (1 shl 0)
    DTT_BORDERCOLOR equ (1 shl 1)
    DTT_SHADOWCOLOR equ (1 shl 2)
    DTT_SHADOWTYPE equ (1 shl 3)
    DTT_SHADOWOFFSET equ (1 shl 4)
    DTT_BORDERSIZE equ (1 shl 5)
    DTT_FONTPROP equ (1 shl 6)
    DTT_COLORPROP equ (1 shl 7)
    DTT_STATEID equ (1 shl 8)
    DTT_CALCRECT equ (1 shl 9)
    DTT_APPLYOVERLAY equ (1 shl 10)
    DTT_GLOWSIZE equ (1 shl 11)
    DTT_CALLBACK equ (1 shl 12)
    DTT_COMPOSITED equ (1 shl 13)
    DTT_VALIDBITS equ <(DTT_TEXTCOLOR or DTT_BORDERCOLOR or DTT_SHADOWCOLOR or DTT_SHADOWTYPE or DTT_SHADOWOFFSET or DTT_BORDERSIZE or DTT_FONTPROP or DTT_COLORPROP or DTT_STATEID or DTT_CALCRECT or DTT_APPLYOVERLAY or DTT_GLOWSIZE or DTT_COMPOSITED)>
    DTTOPTS struct
      dwSize DWORD ?
      dwFlags DWORD ?
      crText COLORREF ?
      crBorder COLORREF ?
      crShadow COLORREF ?
      iTextShadowType SDWORD ?
      ptShadowOffset POINT <>
      iBorderSize SDWORD ?
      iFontPropId SDWORD ?
      iColorPropId SDWORD ?
      iStateId SDWORD ?
      fApplyOverlay BOOL ?
      iGlowSize SDWORD ?
      pfnDrawTextCallback DTT_CALLBACK_PROC ?
      lParam LPARAM ?
    DTTOPTS ends

    _DTTOPTS typedef DTTOPTS
    PDTTOPTS typedef ptr DTTOPTS
    
    if (NTDDI_VERSION ge NTDDI_VISTA)
      @DefProto DllImport, DrawThemeTextEx, WIN_STD_CALL_CONV,, <:HTHEME, :HDC, :SDWORD, :SDWORD, :LPCWSTR, :SDWORD, :DWORD, :LPRECT, :ptr DTTOPTS>, 36
      @DefProto DllImport, GetThemeBitmap, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD, :SDWORD, :ULONG, :ptr HBITMAP>, 24
      @DefProto DllImport, GetThemeStream, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD, :SDWORD, :ptr ptr VOID, :ptr DWORD, :HINSTANCE>, 28
      @DefProto DllImport, BufferedPaintInit, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, BufferedPaintUnInit, WIN_STD_CALL_CONV,, <>, 0
      HPAINTBUFFER typedef HANDLE
      BP_BUFFERFORMAT typedef SDWORD
      BPBF_COMPATIBLEBITMAP equ 0
      BPBF_DIB equ 1
      BPBF_TOPDOWNDIB equ 2
      BPBF_TOPDOWNMONODIB equ 3
      _BP_BUFFERFORMAT typedef BP_BUFFERFORMAT
      
      BPBF_COMPOSITED equ <BPBF_TOPDOWNDIB>
      BP_ANIMATIONSTYLE typedef SDWORD
      BPAS_NONE equ 0
      BPAS_LINEAR equ 1
      BPAS_CUBIC equ 2
      BPAS_SINE equ 3
      _BP_ANIMATIONSTYLE typedef BP_ANIMATIONSTYLE
      
      BP_ANIMATIONPARAMS struct
        cbSize DWORD ?
        dwFlags DWORD ?
        style BP_ANIMATIONSTYLE ?
        dwDuration DWORD ?
      BP_ANIMATIONPARAMS ends

      _BP_ANIMATIONPARAMS typedef BP_ANIMATIONPARAMS
      PBP_ANIMATIONPARAMS typedef ptr BP_ANIMATIONPARAMS
      
      BPPF_ERASE equ 0001h
      BPPF_NOCLIP equ 0002h
      BPPF_NONCLIENT equ 0004h
      BP_PAINTPARAMS struct
        cbSize DWORD ?
        dwFlags DWORD ?
        prcExclude POINTER ?
        pBlendFunction POINTER ?
      BP_PAINTPARAMS ends

      _BP_PAINTPARAMS typedef BP_PAINTPARAMS
      PBP_PAINTPARAMS typedef ptr BP_PAINTPARAMS
      
      @DefProto DllImport, BeginBufferedPaint, WIN_STD_CALL_CONV,, <:HDC, :ptr RECT, :BP_BUFFERFORMAT, :ptr BP_PAINTPARAMS, :ptr HDC>, 20
      @DefProto DllImport, EndBufferedPaint, WIN_STD_CALL_CONV,, <:HPAINTBUFFER, :BOOL>, 8
      @DefProto DllImport, GetBufferedPaintTargetRect, WIN_STD_CALL_CONV,, <:HPAINTBUFFER, :ptr RECT>, 8
      @DefProto DllImport, GetBufferedPaintTargetDC, WIN_STD_CALL_CONV,, <:HPAINTBUFFER>, 4
      @DefProto DllImport, GetBufferedPaintDC, WIN_STD_CALL_CONV,, <:HPAINTBUFFER>, 4
      @DefProto DllImport, GetBufferedPaintBits, WIN_STD_CALL_CONV,, <:HPAINTBUFFER, :ptr ptr RGBQUAD, :ptr SDWORD>, 12
      @DefProto DllImport, BufferedPaintClear, WIN_STD_CALL_CONV,, <:HPAINTBUFFER, :ptr RECT>, 8
      @DefProto DllImport, BufferedPaintSetAlpha, WIN_STD_CALL_CONV,, <:HPAINTBUFFER, :ptr RECT, :BYTE>, 12
      BufferedPaintMakeOpaque macro hBufferedPaint, prc
        exitm <BufferedPaintSetAlpha (hBufferedPaint, prc, 255)>
      endm
      @DefProto DllImport, BufferedPaintStopAllAnimations, WIN_STD_CALL_CONV,, <:HWND>, 4
      HANIMATIONBUFFER typedef HANDLE
      @DefProto DllImport, BeginBufferedAnimation, WIN_STD_CALL_CONV,, <:HWND, :HDC, :ptr RECT, :BP_BUFFERFORMAT, :ptr BP_PAINTPARAMS, :ptr BP_ANIMATIONPARAMS, :ptr HDC, :ptr HDC>, 32
      @DefProto DllImport, EndBufferedAnimation, WIN_STD_CALL_CONV,, <:HANIMATIONBUFFER, :BOOL>, 8
      @DefProto DllImport, BufferedPaintRenderAnimation, WIN_STD_CALL_CONV,, <:HWND, :HDC>, 8
      @DefProto DllImport, IsCompositionActive, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, GetThemeTransitionDuration, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :ptr DWORD>, 24
    endif
  endif
endif

