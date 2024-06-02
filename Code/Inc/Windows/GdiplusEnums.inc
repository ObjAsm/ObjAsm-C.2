;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdiplusenums.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 16/12/2023 11:07:10

ifndef _GDIPLUSENUMS_H
  _GDIPLUSENUMS_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    GraphicsState typedef UINT
    GraphicsContainer typedef UINT
    FillMode typedef SDWORD
    FillModeAlternate equ 0
    FillModeWinding equ 1

    QualityMode typedef SDWORD
    QualityModeInvalid equ -1
    QualityModeDefault equ 0
    QualityModeLow equ 1
    QualityModeHigh equ 2

    CompositingMode typedef SDWORD
    CompositingModeSourceOver equ 0
    CompositingModeSourceCopy equ 1

    CompositingQuality typedef SDWORD
    CompositingQualityInvalid equ QualityModeInvalid
    CompositingQualityDefault equ QualityModeDefault
    CompositingQualityHighSpeed equ QualityModeLow
    CompositingQualityHighQuality equ QualityModeHigh
    CompositingQualityGammaCorrected equ 1
    CompositingQualityAssumeLinear equ 2

    Unit typedef SDWORD
    UnitWorld equ 0
    UnitDisplay equ 1
    UnitPixel equ 2
    UnitPoint equ 3
    UnitInch equ 4
    UnitDocument equ 5
    UnitMillimeter equ 6

    MetafileFrameUnit typedef SDWORD
    MetafileFrameUnitPixel equ UnitPixel
    MetafileFrameUnitPoint equ UnitPoint
    MetafileFrameUnitInch equ UnitInch
    MetafileFrameUnitDocument equ UnitDocument
    MetafileFrameUnitMillimeter equ UnitMillimeter
    MetafileFrameUnitGdi equ 1

    CoordinateSpace typedef SDWORD
    CoordinateSpaceWorld equ 0
    CoordinateSpacePage equ 1
    CoordinateSpaceDevice equ 2

    WrapMode typedef SDWORD
    WrapModeTile equ 0
    WrapModeTileFlipX equ 1
    WrapModeTileFlipY equ 2
    WrapModeTileFlipXY equ 3
    WrapModeClamp equ 4

    HatchStyle typedef SDWORD
    HatchStyleHorizontal equ 0
    HatchStyleVertical equ 1
    HatchStyleForwardDiagonal equ 2
    HatchStyleBackwardDiagonal equ 3
    HatchStyleCross equ 4
    HatchStyleDiagonalCross equ 5
    HatchStyle05Percent equ 6
    HatchStyle10Percent equ 7
    HatchStyle20Percent equ 8
    HatchStyle25Percent equ 9
    HatchStyle30Percent equ 10
    HatchStyle40Percent equ 11
    HatchStyle50Percent equ 12
    HatchStyle60Percent equ 13
    HatchStyle70Percent equ 14
    HatchStyle75Percent equ 15
    HatchStyle80Percent equ 16
    HatchStyle90Percent equ 17
    HatchStyleLightDownwardDiagonal equ 18
    HatchStyleLightUpwardDiagonal equ 19
    HatchStyleDarkDownwardDiagonal equ 20
    HatchStyleDarkUpwardDiagonal equ 21
    HatchStyleWideDownwardDiagonal equ 22
    HatchStyleWideUpwardDiagonal equ 23
    HatchStyleLightVertical equ 24
    HatchStyleLightHorizontal equ 25
    HatchStyleNarrowVertical equ 26
    HatchStyleNarrowHorizontal equ 27
    HatchStyleDarkVertical equ 28
    HatchStyleDarkHorizontal equ 29
    HatchStyleDashedDownwardDiagonal equ 30
    HatchStyleDashedUpwardDiagonal equ 31
    HatchStyleDashedHorizontal equ 32
    HatchStyleDashedVertical equ 33
    HatchStyleSmallConfetti equ 34
    HatchStyleLargeConfetti equ 35
    HatchStyleZigZag equ 36
    HatchStyleWave equ 37
    HatchStyleDiagonalBrick equ 38
    HatchStyleHorizontalBrick equ 39
    HatchStyleWeave equ 40
    HatchStylePlaid equ 41
    HatchStyleDivot equ 42
    HatchStyleDottedGrid equ 43
    HatchStyleDottedDiamond equ 44
    HatchStyleShingle equ 45
    HatchStyleTrellis equ 46
    HatchStyleSphere equ 47
    HatchStyleSmallGrid equ 48
    HatchStyleSmallCheckerBoard equ 49
    HatchStyleLargeCheckerBoard equ 50
    HatchStyleOutlinedDiamond equ 51
    HatchStyleSolidDiamond equ 52
    HatchStyleTotal equ 53
    HatchStyleLargeGrid equ HatchStyleCross
    HatchStyleMin equ HatchStyleHorizontal
    HatchStyleMax equ HatchStyleTotal - 1

    DashStyle typedef SDWORD
    DashStyleSolid equ 0
    DashStyleDash equ 1
    DashStyleDot equ 2
    DashStyleDashDot equ 3
    DashStyleDashDotDot equ 4
    DashStyleCustom equ 5

    DashCap typedef SDWORD
    DashCapFlat equ 0
    DashCapRound equ 2
    DashCapTriangle equ 3

    LineCap typedef SDWORD
    LineCapFlat equ 0
    LineCapSquare equ 1
    LineCapRound equ 2
    LineCapTriangle equ 3
    LineCapNoAnchor equ 10h
    LineCapSquareAnchor equ 11h
    LineCapRoundAnchor equ 12h
    LineCapDiamondAnchor equ 13h
    LineCapArrowAnchor equ 14h
    LineCapCustom equ 0ffh
    LineCapAnchorMask equ 0f0h

    CustomLineCapType typedef SDWORD
    CustomLineCapTypeDefault equ 0
    CustomLineCapTypeAdjustableArrow equ 1

    LineJoin typedef SDWORD
    LineJoinMiter equ 0
    LineJoinBevel equ 1
    LineJoinRound equ 2
    LineJoinMiterClipped equ 3

    PathPointType typedef SDWORD
    PathPointTypeStart equ 0
    PathPointTypeLine equ 1
    PathPointTypeBezier equ 3
    PathPointTypePathTypeMask equ 07h
    PathPointTypeDashMode equ 10h
    PathPointTypePathMarker equ 20h
    PathPointTypeCloseSubpath equ 80h
    PathPointTypeBezier3 equ 3

    WarpMode typedef SDWORD
    WarpModePerspective equ 0
    WarpModeBilinear equ 1

    LinearGradientMode typedef SDWORD
    LinearGradientModeHorizontal equ 0
    LinearGradientModeVertical equ 1
    LinearGradientModeForwardDiagonal equ 2
    LinearGradientModeBackwardDiagonal equ 3

    CombineMode typedef SDWORD
    CombineModeReplace equ 0
    CombineModeIntersect equ 1
    CombineModeUnion equ 2
    CombineModeXor equ 3
    CombineModeExclude equ 4
    CombineModeComplement equ 5

    ImageType typedef SDWORD
    ImageTypeUnknown equ 0
    ImageTypeBitmap equ 1
    ImageTypeMetafile equ 2

    InterpolationMode typedef SDWORD
    InterpolationModeInvalid equ QualityModeInvalid
    InterpolationModeDefault equ QualityModeDefault
    InterpolationModeLowQuality equ QualityModeLow
    InterpolationModeHighQuality equ QualityModeHigh
    InterpolationModeBilinear equ 1
    InterpolationModeBicubic equ 2
    InterpolationModeNearestNeighbor equ 3
    InterpolationModeHighQualityBilinear equ 4
    InterpolationModeHighQualityBicubic equ 5

    PenAlignment typedef SDWORD
    PenAlignmentCenter equ 0
    PenAlignmentInset equ 1

    BrushType typedef SDWORD
    BrushTypeSolidColor equ 0
    BrushTypeHatchFill equ 1
    BrushTypeTextureFill equ 2
    BrushTypePathGradient equ 3
    BrushTypeLinearGradient equ 4

    PenType typedef SDWORD
    PenTypeSolidColor equ BrushTypeSolidColor
    PenTypeHatchFill equ BrushTypeHatchFill
    PenTypeTextureFill equ BrushTypeTextureFill
    PenTypePathGradient equ BrushTypePathGradient
    PenTypeLinearGradient equ BrushTypeLinearGradient
    PenTypeUnknown equ -1

    MatrixOrder typedef SDWORD
    MatrixOrderPrepend equ 0
    MatrixOrderAppend equ 1

    GenericFontFamily typedef SDWORD
    GenericFontFamilySerif equ 0
    GenericFontFamilySansSerif equ 1
    GenericFontFamilyMonospace equ 2

    FontStyle typedef SDWORD
    FontStyleRegular equ 0
    FontStyleBold equ 1
    FontStyleItalic equ 2
    FontStyleBoldItalic equ 3
    FontStyleUnderline equ 4
    FontStyleStrikeout equ 8

    SmoothingMode typedef SDWORD
    SmoothingModeInvalid equ QualityModeInvalid
    SmoothingModeDefault equ QualityModeDefault
    SmoothingModeHighSpeed equ QualityModeLow
    SmoothingModeHighQuality equ QualityModeHigh
    SmoothingModeNone equ 3
    SmoothingModeAntiAlias equ 4
    if (GDIPVER ge 0110h)
      SmoothingModeAntiAlias8x4 equ SmoothingModeAntiAlias
      SmoothingModeAntiAlias8x8 equ 5
    endif

    PixelOffsetMode typedef SDWORD
    PixelOffsetModeInvalid equ QualityModeInvalid
    PixelOffsetModeDefault equ QualityModeDefault
    PixelOffsetModeHighSpeed equ QualityModeLow
    PixelOffsetModeHighQuality equ QualityModeHigh
    PixelOffsetModeNone equ 1
    PixelOffsetModeHalf equ 2

    TextRenderingHint typedef SDWORD
    TextRenderingHintSystemDefault equ 0
    TextRenderingHintSingleBitPerPixelGridFit equ 1
    TextRenderingHintSingleBitPerPixel equ 2
    TextRenderingHintAntiAliasGridFit equ 3
    TextRenderingHintAntiAlias equ 4
    TextRenderingHintClearTypeGridFit equ 5

    MetafileType typedef SDWORD
    MetafileTypeInvalid equ 0
    MetafileTypeWmf equ 1
    MetafileTypeWmfPlaceable equ 2
    MetafileTypeEmf equ 3
    MetafileTypeEmfPlusOnly equ 4
    MetafileTypeEmfPlusDual equ 5

    EmfType typedef SDWORD
    EmfTypeEmfOnly equ MetafileTypeEmf
    EmfTypeEmfPlusOnly equ MetafileTypeEmfPlusOnly
    EmfTypeEmfPlusDual equ MetafileTypeEmfPlusDual

    ObjectType typedef SDWORD
    ObjectTypeInvalid equ 0
    ObjectTypeBrush equ 1
    ObjectTypePen equ 2
    ObjectTypePath equ 3
    ObjectTypeRegion equ 4
    ObjectTypeImage equ 5
    ObjectTypeFont equ 6
    ObjectTypeStringFormat equ 7
    ObjectTypeImageAttributes equ 8
    ObjectTypeCustomLineCap equ 9
    if (GDIPVER ge 0110h)
      ObjectTypeGraphics equ 10
      ObjectTypeMax equ ObjectTypeGraphics
    else
      ObjectTypeMax equ ObjectTypeCustomLineCap
    endif
    ObjectTypeMin equ ObjectTypeBrush

    ObjectTypeIsValid proto WIN_STD_CALL_CONV :ObjectType
    GDIP_EMFPLUS_RECORD_BASE equ 00004000h
    GDIP_WMF_RECORD_BASE equ 00010000h
    GDIP_WMF_RECORD_TO_EMFPLUS macro n
      exitm <((EmfPlusRecordType) ((n) or GDIP_WMF_RECORD_BASE))>
    endm
    GDIP_EMFPLUS_RECORD_TO_WMF macro n
      exitm <((n) and (not GDIP_WMF_RECORD_BASE))>
    endm
    GDIP_IS_WMF_RECORDTYPE macro n
      exitm <(((n) and GDIP_WMF_RECORD_BASE) != 0)>
    endm
    EmfPlusRecordType typedef SDWORD
    WmfRecordTypeSetBkColor equ GDIP_WMF_RECORD_TO_EMFPLUS(META_SETBKCOLOR)
    WmfRecordTypeSetBkMode equ GDIP_WMF_RECORD_TO_EMFPLUS(META_SETBKMODE)
    WmfRecordTypeSetMapMode equ GDIP_WMF_RECORD_TO_EMFPLUS(META_SETMAPMODE)
    WmfRecordTypeSetROP2 equ GDIP_WMF_RECORD_TO_EMFPLUS(META_SETROP2)
    WmfRecordTypeSetRelAbs equ GDIP_WMF_RECORD_TO_EMFPLUS(META_SETRELABS)
    WmfRecordTypeSetPolyFillMode equ GDIP_WMF_RECORD_TO_EMFPLUS(META_SETPOLYFILLMODE)
    WmfRecordTypeSetStretchBltMode equ GDIP_WMF_RECORD_TO_EMFPLUS(META_SETSTRETCHBLTMODE)
    WmfRecordTypeSetTextCharExtra equ GDIP_WMF_RECORD_TO_EMFPLUS(META_SETTEXTCHAREXTRA)
    WmfRecordTypeSetTextColor equ GDIP_WMF_RECORD_TO_EMFPLUS(META_SETTEXTCOLOR)
    WmfRecordTypeSetTextJustification equ GDIP_WMF_RECORD_TO_EMFPLUS(META_SETTEXTJUSTIFICATION)
    WmfRecordTypeSetWindowOrg equ GDIP_WMF_RECORD_TO_EMFPLUS(META_SETWINDOWORG)
    WmfRecordTypeSetWindowExt equ GDIP_WMF_RECORD_TO_EMFPLUS(META_SETWINDOWEXT)
    WmfRecordTypeSetViewportOrg equ GDIP_WMF_RECORD_TO_EMFPLUS(META_SETVIEWPORTORG)
    WmfRecordTypeSetViewportExt equ GDIP_WMF_RECORD_TO_EMFPLUS(META_SETVIEWPORTEXT)
    WmfRecordTypeOffsetWindowOrg equ GDIP_WMF_RECORD_TO_EMFPLUS(META_OFFSETWINDOWORG)
    WmfRecordTypeScaleWindowExt equ GDIP_WMF_RECORD_TO_EMFPLUS(META_SCALEWINDOWEXT)
    WmfRecordTypeOffsetViewportOrg equ GDIP_WMF_RECORD_TO_EMFPLUS(META_OFFSETVIEWPORTORG)
    WmfRecordTypeScaleViewportExt equ GDIP_WMF_RECORD_TO_EMFPLUS(META_SCALEVIEWPORTEXT)
    WmfRecordTypeLineTo equ GDIP_WMF_RECORD_TO_EMFPLUS(META_LINETO)
    WmfRecordTypeMoveTo equ GDIP_WMF_RECORD_TO_EMFPLUS(META_MOVETO)
    WmfRecordTypeExcludeClipRect equ GDIP_WMF_RECORD_TO_EMFPLUS(META_EXCLUDECLIPRECT)
    WmfRecordTypeIntersectClipRect equ GDIP_WMF_RECORD_TO_EMFPLUS(META_INTERSECTCLIPRECT)
    WmfRecordTypeArc equ GDIP_WMF_RECORD_TO_EMFPLUS(META_ARC)
    WmfRecordTypeEllipse equ GDIP_WMF_RECORD_TO_EMFPLUS(META_ELLIPSE)
    WmfRecordTypeFloodFill equ GDIP_WMF_RECORD_TO_EMFPLUS(META_FLOODFILL)
    WmfRecordTypePie equ GDIP_WMF_RECORD_TO_EMFPLUS(META_PIE)
    WmfRecordTypeRectangle equ GDIP_WMF_RECORD_TO_EMFPLUS(META_RECTANGLE)
    WmfRecordTypeRoundRect equ GDIP_WMF_RECORD_TO_EMFPLUS(META_ROUNDRECT)
    WmfRecordTypePatBlt equ GDIP_WMF_RECORD_TO_EMFPLUS(META_PATBLT)
    WmfRecordTypeSaveDC equ GDIP_WMF_RECORD_TO_EMFPLUS(META_SAVEDC)
    WmfRecordTypeSetPixel equ GDIP_WMF_RECORD_TO_EMFPLUS(META_SETPIXEL)
    WmfRecordTypeOffsetClipRgn equ GDIP_WMF_RECORD_TO_EMFPLUS(META_OFFSETCLIPRGN)
    WmfRecordTypeTextOut equ GDIP_WMF_RECORD_TO_EMFPLUS(META_TEXTOUT)
    WmfRecordTypeBitBlt equ GDIP_WMF_RECORD_TO_EMFPLUS(META_BITBLT)
    WmfRecordTypeStretchBlt equ GDIP_WMF_RECORD_TO_EMFPLUS(META_STRETCHBLT)
    WmfRecordTypePolygon equ GDIP_WMF_RECORD_TO_EMFPLUS(META_POLYGON)
    WmfRecordTypePolyline equ GDIP_WMF_RECORD_TO_EMFPLUS(META_POLYLINE)
    WmfRecordTypeEscape equ GDIP_WMF_RECORD_TO_EMFPLUS(META_ESCAPE)
    WmfRecordTypeRestoreDC equ GDIP_WMF_RECORD_TO_EMFPLUS(META_RESTOREDC)
    WmfRecordTypeFillRegion equ GDIP_WMF_RECORD_TO_EMFPLUS(META_FILLREGION)
    WmfRecordTypeFrameRegion equ GDIP_WMF_RECORD_TO_EMFPLUS(META_FRAMEREGION)
    WmfRecordTypeInvertRegion equ GDIP_WMF_RECORD_TO_EMFPLUS(META_INVERTREGION)
    WmfRecordTypePaintRegion equ GDIP_WMF_RECORD_TO_EMFPLUS(META_PAINTREGION)
    WmfRecordTypeSelectClipRegion equ GDIP_WMF_RECORD_TO_EMFPLUS(META_SELECTCLIPREGION)
    WmfRecordTypeSelectObject equ GDIP_WMF_RECORD_TO_EMFPLUS(META_SELECTOBJECT)
    WmfRecordTypeSetTextAlign equ GDIP_WMF_RECORD_TO_EMFPLUS(META_SETTEXTALIGN)
    WmfRecordTypeDrawText equ GDIP_WMF_RECORD_TO_EMFPLUS(062Fh)
    WmfRecordTypeChord equ GDIP_WMF_RECORD_TO_EMFPLUS(META_CHORD)
    WmfRecordTypeSetMapperFlags equ GDIP_WMF_RECORD_TO_EMFPLUS(META_SETMAPPERFLAGS)
    WmfRecordTypeExtTextOut equ GDIP_WMF_RECORD_TO_EMFPLUS(META_EXTTEXTOUT)
    WmfRecordTypeSetDIBToDev equ GDIP_WMF_RECORD_TO_EMFPLUS(META_SETDIBTODEV)
    WmfRecordTypeSelectPalette equ GDIP_WMF_RECORD_TO_EMFPLUS(META_SELECTPALETTE)
    WmfRecordTypeRealizePalette equ GDIP_WMF_RECORD_TO_EMFPLUS(META_REALIZEPALETTE)
    WmfRecordTypeAnimatePalette equ GDIP_WMF_RECORD_TO_EMFPLUS(META_ANIMATEPALETTE)
    WmfRecordTypeSetPalEntries equ GDIP_WMF_RECORD_TO_EMFPLUS(META_SETPALENTRIES)
    WmfRecordTypePolyPolygon equ GDIP_WMF_RECORD_TO_EMFPLUS(META_POLYPOLYGON)
    WmfRecordTypeResizePalette equ GDIP_WMF_RECORD_TO_EMFPLUS(META_RESIZEPALETTE)
    WmfRecordTypeDIBBitBlt equ GDIP_WMF_RECORD_TO_EMFPLUS(META_DIBBITBLT)
    WmfRecordTypeDIBStretchBlt equ GDIP_WMF_RECORD_TO_EMFPLUS(META_DIBSTRETCHBLT)
    WmfRecordTypeDIBCreatePatternBrush equ GDIP_WMF_RECORD_TO_EMFPLUS(META_DIBCREATEPATTERNBRUSH)
    WmfRecordTypeStretchDIB equ GDIP_WMF_RECORD_TO_EMFPLUS(META_STRETCHDIB)
    WmfRecordTypeExtFloodFill equ GDIP_WMF_RECORD_TO_EMFPLUS(META_EXTFLOODFILL)
    WmfRecordTypeSetLayout equ GDIP_WMF_RECORD_TO_EMFPLUS(0149h)
    WmfRecordTypeResetDC equ GDIP_WMF_RECORD_TO_EMFPLUS(014Ch)
    WmfRecordTypeStartDoc equ GDIP_WMF_RECORD_TO_EMFPLUS(014Dh)
    WmfRecordTypeStartPage equ GDIP_WMF_RECORD_TO_EMFPLUS(004Fh)
    WmfRecordTypeEndPage equ GDIP_WMF_RECORD_TO_EMFPLUS(0050h)
    WmfRecordTypeAbortDoc equ GDIP_WMF_RECORD_TO_EMFPLUS(0052h)
    WmfRecordTypeEndDoc equ GDIP_WMF_RECORD_TO_EMFPLUS(005Eh)
    WmfRecordTypeDeleteObject equ GDIP_WMF_RECORD_TO_EMFPLUS(META_DELETEOBJECT)
    WmfRecordTypeCreatePalette equ GDIP_WMF_RECORD_TO_EMFPLUS(META_CREATEPALETTE)
    WmfRecordTypeCreateBrush equ GDIP_WMF_RECORD_TO_EMFPLUS(00F8h)
    WmfRecordTypeCreatePatternBrush equ GDIP_WMF_RECORD_TO_EMFPLUS(META_CREATEPATTERNBRUSH)
    WmfRecordTypeCreatePenIndirect equ GDIP_WMF_RECORD_TO_EMFPLUS(META_CREATEPENINDIRECT)
    WmfRecordTypeCreateFontIndirect equ GDIP_WMF_RECORD_TO_EMFPLUS(META_CREATEFONTINDIRECT)
    WmfRecordTypeCreateBrushIndirect equ GDIP_WMF_RECORD_TO_EMFPLUS(META_CREATEBRUSHINDIRECT)
    WmfRecordTypeCreateBitmapIndirect equ GDIP_WMF_RECORD_TO_EMFPLUS(02FDh)
    WmfRecordTypeCreateBitmap equ GDIP_WMF_RECORD_TO_EMFPLUS(06FEh)
    WmfRecordTypeCreateRegion equ GDIP_WMF_RECORD_TO_EMFPLUS(META_CREATEREGION)
    EmfRecordTypeHeader equ EMR_HEADER
    EmfRecordTypePolyBezier equ EMR_POLYBEZIER
    EmfRecordTypePolygon equ EMR_POLYGON
    EmfRecordTypePolyline equ EMR_POLYLINE
    EmfRecordTypePolyBezierTo equ EMR_POLYBEZIERTO
    EmfRecordTypePolyLineTo equ EMR_POLYLINETO
    EmfRecordTypePolyPolyline equ EMR_POLYPOLYLINE
    EmfRecordTypePolyPolygon equ EMR_POLYPOLYGON
    EmfRecordTypeSetWindowExtEx equ EMR_SETWINDOWEXTEX
    EmfRecordTypeSetWindowOrgEx equ EMR_SETWINDOWORGEX
    EmfRecordTypeSetViewportExtEx equ EMR_SETVIEWPORTEXTEX
    EmfRecordTypeSetViewportOrgEx equ EMR_SETVIEWPORTORGEX
    EmfRecordTypeSetBrushOrgEx equ EMR_SETBRUSHORGEX
    EmfRecordTypeEOF equ EMR_EOF
    EmfRecordTypeSetPixelV equ EMR_SETPIXELV
    EmfRecordTypeSetMapperFlags equ EMR_SETMAPPERFLAGS
    EmfRecordTypeSetMapMode equ EMR_SETMAPMODE
    EmfRecordTypeSetBkMode equ EMR_SETBKMODE
    EmfRecordTypeSetPolyFillMode equ EMR_SETPOLYFILLMODE
    EmfRecordTypeSetROP2 equ EMR_SETROP2
    EmfRecordTypeSetStretchBltMode equ EMR_SETSTRETCHBLTMODE
    EmfRecordTypeSetTextAlign equ EMR_SETTEXTALIGN
    EmfRecordTypeSetColorAdjustment equ EMR_SETCOLORADJUSTMENT
    EmfRecordTypeSetTextColor equ EMR_SETTEXTCOLOR
    EmfRecordTypeSetBkColor equ EMR_SETBKCOLOR
    EmfRecordTypeOffsetClipRgn equ EMR_OFFSETCLIPRGN
    EmfRecordTypeMoveToEx equ EMR_MOVETOEX
    EmfRecordTypeSetMetaRgn equ EMR_SETMETARGN
    EmfRecordTypeExcludeClipRect equ EMR_EXCLUDECLIPRECT
    EmfRecordTypeIntersectClipRect equ EMR_INTERSECTCLIPRECT
    EmfRecordTypeScaleViewportExtEx equ EMR_SCALEVIEWPORTEXTEX
    EmfRecordTypeScaleWindowExtEx equ EMR_SCALEWINDOWEXTEX
    EmfRecordTypeSaveDC equ EMR_SAVEDC
    EmfRecordTypeRestoreDC equ EMR_RESTOREDC
    EmfRecordTypeSetWorldTransform equ EMR_SETWORLDTRANSFORM
    EmfRecordTypeModifyWorldTransform equ EMR_MODIFYWORLDTRANSFORM
    EmfRecordTypeSelectObject equ EMR_SELECTOBJECT
    EmfRecordTypeCreatePen equ EMR_CREATEPEN
    EmfRecordTypeCreateBrushIndirect equ EMR_CREATEBRUSHINDIRECT
    EmfRecordTypeDeleteObject equ EMR_DELETEOBJECT
    EmfRecordTypeAngleArc equ EMR_ANGLEARC
    EmfRecordTypeEllipse equ EMR_ELLIPSE
    EmfRecordTypeRectangle equ EMR_RECTANGLE
    EmfRecordTypeRoundRect equ EMR_ROUNDRECT
    EmfRecordTypeArc equ EMR_ARC
    EmfRecordTypeChord equ EMR_CHORD
    EmfRecordTypePie equ EMR_PIE
    EmfRecordTypeSelectPalette equ EMR_SELECTPALETTE
    EmfRecordTypeCreatePalette equ EMR_CREATEPALETTE
    EmfRecordTypeSetPaletteEntries equ EMR_SETPALETTEENTRIES
    EmfRecordTypeResizePalette equ EMR_RESIZEPALETTE
    EmfRecordTypeRealizePalette equ EMR_REALIZEPALETTE
    EmfRecordTypeExtFloodFill equ EMR_EXTFLOODFILL
    EmfRecordTypeLineTo equ EMR_LINETO
    EmfRecordTypeArcTo equ EMR_ARCTO
    EmfRecordTypePolyDraw equ EMR_POLYDRAW
    EmfRecordTypeSetArcDirection equ EMR_SETARCDIRECTION
    EmfRecordTypeSetMiterLimit equ EMR_SETMITERLIMIT
    EmfRecordTypeBeginPath equ EMR_BEGINPATH
    EmfRecordTypeEndPath equ EMR_ENDPATH
    EmfRecordTypeCloseFigure equ EMR_CLOSEFIGURE
    EmfRecordTypeFillPath equ EMR_FILLPATH
    EmfRecordTypeStrokeAndFillPath equ EMR_STROKEANDFILLPATH
    EmfRecordTypeStrokePath equ EMR_STROKEPATH
    EmfRecordTypeFlattenPath equ EMR_FLATTENPATH
    EmfRecordTypeWidenPath equ EMR_WIDENPATH
    EmfRecordTypeSelectClipPath equ EMR_SELECTCLIPPATH
    EmfRecordTypeAbortPath equ EMR_ABORTPATH
    EmfRecordTypeReserved_069 equ 69
    EmfRecordTypeGdiComment equ EMR_GDICOMMENT
    EmfRecordTypeFillRgn equ EMR_FILLRGN
    EmfRecordTypeFrameRgn equ EMR_FRAMERGN
    EmfRecordTypeInvertRgn equ EMR_INVERTRGN
    EmfRecordTypePaintRgn equ EMR_PAINTRGN
    EmfRecordTypeExtSelectClipRgn equ EMR_EXTSELECTCLIPRGN
    EmfRecordTypeBitBlt equ EMR_BITBLT
    EmfRecordTypeStretchBlt equ EMR_STRETCHBLT
    EmfRecordTypeMaskBlt equ EMR_MASKBLT
    EmfRecordTypePlgBlt equ EMR_PLGBLT
    EmfRecordTypeSetDIBitsToDevice equ EMR_SETDIBITSTODEVICE
    EmfRecordTypeStretchDIBits equ EMR_STRETCHDIBITS
    EmfRecordTypeExtCreateFontIndirect equ EMR_EXTCREATEFONTINDIRECTW
    EmfRecordTypeExtTextOutA equ EMR_EXTTEXTOUTA
    EmfRecordTypeExtTextOutW equ EMR_EXTTEXTOUTW
    EmfRecordTypePolyBezier16 equ EMR_POLYBEZIER16
    EmfRecordTypePolygon16 equ EMR_POLYGON16
    EmfRecordTypePolyline16 equ EMR_POLYLINE16
    EmfRecordTypePolyBezierTo16 equ EMR_POLYBEZIERTO16
    EmfRecordTypePolylineTo16 equ EMR_POLYLINETO16
    EmfRecordTypePolyPolyline16 equ EMR_POLYPOLYLINE16
    EmfRecordTypePolyPolygon16 equ EMR_POLYPOLYGON16
    EmfRecordTypePolyDraw16 equ EMR_POLYDRAW16
    EmfRecordTypeCreateMonoBrush equ EMR_CREATEMONOBRUSH
    EmfRecordTypeCreateDIBPatternBrushPt equ EMR_CREATEDIBPATTERNBRUSHPT
    EmfRecordTypeExtCreatePen equ EMR_EXTCREATEPEN
    EmfRecordTypePolyTextOutA equ EMR_POLYTEXTOUTA
    EmfRecordTypePolyTextOutW equ EMR_POLYTEXTOUTW
    EmfRecordTypeSetICMMode equ 98
    EmfRecordTypeCreateColorSpace equ 99
    EmfRecordTypeSetColorSpace equ 100
    EmfRecordTypeDeleteColorSpace equ 101
    EmfRecordTypeGLSRecord equ 102
    EmfRecordTypeGLSBoundedRecord equ 103
    EmfRecordTypePixelFormat equ 104
    EmfRecordTypeDrawEscape equ 105
    EmfRecordTypeExtEscape equ 106
    EmfRecordTypeStartDoc equ 107
    EmfRecordTypeSmallTextOut equ 108
    EmfRecordTypeForceUFIMapping equ 109
    EmfRecordTypeNamedEscape equ 110
    EmfRecordTypeColorCorrectPalette equ 111
    EmfRecordTypeSetICMProfileA equ 112
    EmfRecordTypeSetICMProfileW equ 113
    EmfRecordTypeAlphaBlend equ 114
    EmfRecordTypeSetLayout equ 115
    EmfRecordTypeTransparentBlt equ 116
    EmfRecordTypeReserved_117 equ 117
    EmfRecordTypeGradientFill equ 118
    EmfRecordTypeSetLinkedUFIs equ 119
    EmfRecordTypeSetTextJustification equ 120
    EmfRecordTypeColorMatchToTargetW equ 121
    EmfRecordTypeCreateColorSpaceW equ 122
    EmfRecordTypeMax equ 122
    EmfRecordTypeMin equ 1
    EmfPlusRecordTypeInvalid equ GDIP_EMFPLUS_RECORD_BASE
    EmfPlusRecordTypeHeader equ 1
    EmfPlusRecordTypeEndOfFile equ 2
    EmfPlusRecordTypeComment equ 3
    EmfPlusRecordTypeGetDC equ 4
    EmfPlusRecordTypeMultiFormatStart equ 5
    EmfPlusRecordTypeMultiFormatSection equ 6
    EmfPlusRecordTypeMultiFormatEnd equ 7
    EmfPlusRecordTypeObject equ 8
    EmfPlusRecordTypeClear equ 9
    EmfPlusRecordTypeFillRects equ 10
    EmfPlusRecordTypeDrawRects equ 11
    EmfPlusRecordTypeFillPolygon equ 12
    EmfPlusRecordTypeDrawLines equ 13
    EmfPlusRecordTypeFillEllipse equ 14
    EmfPlusRecordTypeDrawEllipse equ 15
    EmfPlusRecordTypeFillPie equ 16
    EmfPlusRecordTypeDrawPie equ 17
    EmfPlusRecordTypeDrawArc equ 18
    EmfPlusRecordTypeFillRegion equ 19
    EmfPlusRecordTypeFillPath equ 20
    EmfPlusRecordTypeDrawPath equ 21
    EmfPlusRecordTypeFillClosedCurve equ 22
    EmfPlusRecordTypeDrawClosedCurve equ 23
    EmfPlusRecordTypeDrawCurve equ 24
    EmfPlusRecordTypeDrawBeziers equ 25
    EmfPlusRecordTypeDrawImage equ 26
    EmfPlusRecordTypeDrawImagePoints equ 27
    EmfPlusRecordTypeDrawString equ 28
    EmfPlusRecordTypeSetRenderingOrigin equ 29
    EmfPlusRecordTypeSetAntiAliasMode equ 30
    EmfPlusRecordTypeSetTextRenderingHint equ 31
    EmfPlusRecordTypeSetTextContrast equ 32
    EmfPlusRecordTypeSetInterpolationMode equ 33
    EmfPlusRecordTypeSetPixelOffsetMode equ 34
    EmfPlusRecordTypeSetCompositingMode equ 35
    EmfPlusRecordTypeSetCompositingQuality equ 36
    EmfPlusRecordTypeSave equ 37
    EmfPlusRecordTypeRestore equ 38
    EmfPlusRecordTypeBeginContainer equ 39
    EmfPlusRecordTypeBeginContainerNoParams equ 40
    EmfPlusRecordTypeEndContainer equ 41
    EmfPlusRecordTypeSetWorldTransform equ 42
    EmfPlusRecordTypeResetWorldTransform equ 43
    EmfPlusRecordTypeMultiplyWorldTransform equ 44
    EmfPlusRecordTypeTranslateWorldTransform equ 45
    EmfPlusRecordTypeScaleWorldTransform equ 46
    EmfPlusRecordTypeRotateWorldTransform equ 47
    EmfPlusRecordTypeSetPageTransform equ 48
    EmfPlusRecordTypeResetClip equ 49
    EmfPlusRecordTypeSetClipRect equ 50
    EmfPlusRecordTypeSetClipPath equ 51
    EmfPlusRecordTypeSetClipRegion equ 52
    EmfPlusRecordTypeOffsetClip equ 53
    EmfPlusRecordTypeDrawDriverString equ 54
    if (GDIPVER ge 0110h)
      EmfPlusRecordTypeStrokeFillPath equ 55
      EmfPlusRecordTypeSerializableObject equ 56
      EmfPlusRecordTypeSetTSGraphics equ 57
      EmfPlusRecordTypeSetTSClip equ 58
    endif
    EmfPlusRecordTotal equ 59
    EmfPlusRecordTypeMax equ EmfPlusRecordTotal - 1
    EmfPlusRecordTypeMin equ EmfPlusRecordTypeHeader

    StringFormatFlags typedef SDWORD
    StringFormatFlagsDirectionRightToLeft equ 00000001h
    StringFormatFlagsDirectionVertical equ 00000002h
    StringFormatFlagsNoFitBlackBox equ 00000004h
    StringFormatFlagsDisplayFormatControl equ 00000020h
    StringFormatFlagsNoFontFallback equ 00000400h
    StringFormatFlagsMeasureTrailingSpaces equ 00000800h
    StringFormatFlagsNoWrap equ 00001000h
    StringFormatFlagsLineLimit equ 00002000h
    StringFormatFlagsNoClip equ 00004000h
    StringFormatFlagsBypassGDI equ 80000000h

    StringTrimming typedef SDWORD
    StringTrimmingNone equ 0
    StringTrimmingCharacter equ 1
    StringTrimmingWord equ 2
    StringTrimmingEllipsisCharacter equ 3
    StringTrimmingEllipsisWord equ 4
    StringTrimmingEllipsisPath equ 5

    StringDigitSubstitute typedef SDWORD
    StringDigitSubstituteUser equ 0
    StringDigitSubstituteNone equ 1
    StringDigitSubstituteNational equ 2
    StringDigitSubstituteTraditional equ 3

    HotkeyPrefix typedef SDWORD
    HotkeyPrefixNone equ 0
    HotkeyPrefixShow equ 1
    HotkeyPrefixHide equ 2

    StringAlignment typedef SDWORD
    StringAlignmentNear equ 0
    StringAlignmentCenter equ 1
    StringAlignmentFar equ 2

    DriverStringOptions typedef SDWORD
    DriverStringOptionsCmapLookup equ 1
    DriverStringOptionsVertical equ 2
    DriverStringOptionsRealizedAdvance equ 4
    DriverStringOptionsLimitSubpixel equ 8

    FlushIntention typedef SDWORD
    FlushIntentionFlush equ 0
    FlushIntentionSync equ 1

    EncoderParameterValueType typedef SDWORD
    EncoderParameterValueTypeByte equ 1
    EncoderParameterValueTypeASCII equ 2
    EncoderParameterValueTypeShort equ 3
    EncoderParameterValueTypeLong equ 4
    EncoderParameterValueTypeRational equ 5
    EncoderParameterValueTypeLongRange equ 6
    EncoderParameterValueTypeUndefined equ 7
    EncoderParameterValueTypeRationalRange equ 8
    if (GDIPVER ge 0110h)
      EncoderParameterValueTypePointer equ 9
    endif

    EncoderValue typedef SDWORD
    EncoderValueColorTypeCMYK equ 0
    EncoderValueColorTypeYCCK equ 1
    EncoderValueCompressionLZW equ 2
    EncoderValueCompressionCCITT3 equ 3
    EncoderValueCompressionCCITT4 equ 4
    EncoderValueCompressionRle equ 5
    EncoderValueCompressionNone equ 6
    EncoderValueScanMethodInterlaced equ 7
    EncoderValueScanMethodNonInterlaced equ 8
    EncoderValueVersionGif87 equ 9
    EncoderValueVersionGif89 equ 10
    EncoderValueRenderProgressive equ 11
    EncoderValueRenderNonProgressive equ 12
    EncoderValueTransformRotate90 equ 13
    EncoderValueTransformRotate180 equ 14
    EncoderValueTransformRotate270 equ 15
    EncoderValueTransformFlipHorizontal equ 16
    EncoderValueTransformFlipVertical equ 17
    EncoderValueMultiFrame equ 18
    EncoderValueLastFrame equ 19
    EncoderValueFlush equ 20
    EncoderValueFrameDimensionTime equ 21
    EncoderValueFrameDimensionResolution equ 22
    EncoderValueFrameDimensionPage equ 23
    if (GDIPVER ge 0110h)
      EncoderValueColorTypeGray equ 24
      EncoderValueColorTypeRGB equ 25
    endif

    EmfToWmfBitsFlags typedef SDWORD
    EmfToWmfBitsFlagsDefault equ 00000000h
    EmfToWmfBitsFlagsEmbedEmf equ 00000001h
    EmfToWmfBitsFlagsIncludePlaceable equ 00000002h
    EmfToWmfBitsFlagsNoXORClip equ 00000004h

    if (GDIPVER ge 0110h)
      ConvertToEmfPlusFlags typedef SDWORD
      ConvertToEmfPlusFlagsDefault equ 00000000h
      ConvertToEmfPlusFlagsRopUsed equ 00000001h
      ConvertToEmfPlusFlagsText equ 00000002h
      ConvertToEmfPlusFlagsInvalidRecord equ 00000004h
    endif
    GpTestControlEnum typedef SDWORD
    TestControlForceBilinear equ 0
    TestControlNoICM equ 1
    TestControlGetBuildNumber equ 2

  endif
endif
