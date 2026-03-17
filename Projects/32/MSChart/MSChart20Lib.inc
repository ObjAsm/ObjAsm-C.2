; ==================================================================================================
; Title:   MSChart20Lib.inc
; Author:  G. Friedrich
; Version: 1.0.0
; Purpose: MSChart using ObjAsm32.
; Notes:   Generated .INC file by COMView
;          typelib name=MSChart20Lib
;          documentation=Microsoft Chart Control 6.0 (OLEDB)
;          GUID={65E121D4-0C60-11D2-A9FC-0000F8754DA1}
;          Version 2.0, LCID 0
;
;          Version 1.0.0, March 2009
;            - Initial release.
; ==================================================================================================


sTLBID_MSChart20Lib textequ <65E121D4-0C60-11D2-A9FC-0000F8754DA1>

_MajorVer_MSChart20Lib equ 2
_MinorVer_MSChart20Lib equ 0


OLE_XPOS_PIXELS typedef SDWORD
OLE_YPOS_PIXELS typedef SDWORD


;ErrorConstants
ErrorConstants typedef SDWORD
VtOk                              equ  0
VtFail                            equ  1000          ;=03E8h
VtErrorDeletingUsedObject         equ  1001          ;=03E9h
VtErrorDeletingDeletedObject      equ  1002          ;=03EAh
VtErrorCorruptData                equ  1003          ;=03EBh
VtErrorNotImplemented             equ  1004          ;=03ECh
VtErrorNoMemory                   equ  1100          ;=044Ch
VtErrorInvalidArgument            equ  1101          ;=044Dh
VtErrorNotFound                   equ  1102          ;=044Eh
VtErrorTooSmall                   equ  1103          ;=044Fh
VtErrorInvalidRequest             equ  1104          ;=0450h
VtErrorStreamIo                   equ  1105          ;=0451h
VtErrorUserIo                     equ  1106          ;=0452h
VtErrorCorruptArchive             equ  1107          ;=0453h
VtErrorArchiveVersion             equ  1108          ;=0454h
VtErrorArchiveTypeMismatch        equ  1109          ;=0455h
VtErrorArchivePointerMismatch     equ  1110          ;=0456h
VtErrorCannotOpenFile             equ  1111          ;=0457h
VtErrorUnableToLoadString         equ  1112          ;=0458h
VtErrorBufferTooSmall             equ  1113          ;=0459h
VtErrorCopyingObject              equ  1114          ;=045Ah
VtErrorDuplicateObject            equ  1115          ;=045Bh
VtErrorActionCanceled             equ  1116          ;=045Ch
VtErrorInvalidIndex               equ  1117          ;=045Dh
VtErrorInvalidTypeConversion      equ  1118          ;=045Eh
VtErrorInvalidObject              equ  1119          ;=045Fh
VtErrorCreateWindow               equ  1120          ;=0460h
VtErrorOSVersion                  equ  1121          ;=0461h
VtErrorLoadPicture                equ  1122          ;=0462h
VtErrorInvalidSyntax              equ  1200          ;=04B0h
VtErrorIdentifierTooBig           equ  1201          ;=04B1h
VtErrorUnrecongizedFunction       equ  1202          ;=04B2h
VtErrorUnrecongizedSymbol         equ  1203          ;=04B3h
VtErrorUnexpectedEOS              equ  1204          ;=04B4h
VtErrorDuplicateSymbol            equ  1205          ;=04B5h
VtErrorDisplay                    equ  1500          ;=05DCh
VtErrorInvalidFontName            equ  1501          ;=05DDh
VtErrorInvalidFont                equ  1502          ;=05DEh
VtErrorNoDisplayResources         equ  1503          ;=05DFh
VtErrorDefaultFontSubstituted     equ  1504          ;=05E0h
VtChError                         equ  2000          ;=07D0h
VtChErrorInvalidHandle            equ  2001          ;=07D1h
VtChErrorNoData                   equ  2002          ;=07D2h
VtChErrorInvalidSeriesNumber      equ  2003          ;=07D3h
VtChErrorInvalidAxis              equ  2004          ;=07D4h
VtChErrorRestrictedVersion        equ  2005          ;=07D5h
InvalidPropertyValue              equ  380           ;=017Ch
GetNotSupported                   equ  394           ;=018Ah
SetNotSupported                   equ  383           ;=017Fh
InvalidProcedureCall              equ  5
InvalidObjectUse                  equ  425           ;=01A9h
WrongClipboardFormat              equ  461           ;=01CDh
DataObjectLocked                  equ  672           ;=02A0h
ExpectedAnArgument                equ  673           ;=02A1h
RecursiveOleDrag                  equ  674           ;=02A2h
FormatNotByteArray                equ  675           ;=02A3h
DataNotSetForFormat               equ  676           ;=02A4h

;OLEDropConstants
OLEDropConstants typedef SDWORD
chOLEDropNone                     equ  0
chOLEDropManual                   equ  1
chOLEDropAutomatic                equ  2

;OLEDragConstants
OLEDragConstants typedef SDWORD
chOLEDragManual                   equ  0
chOLEDragAutomatic                equ  1

;VtHorizontalAlignment
VtHorizontalAlignment typedef SDWORD
VtHorizontalAlignmentLeft         equ  0
VtHorizontalAlignmentRight        equ  1
VtHorizontalAlignmentCenter       equ  2
VtHorizontalAlignmentFill         equ  3
VtHorizontalAlignmentFlush        equ  4

;VtVerticalAlignment
VtVerticalAlignment typedef SDWORD
VtVerticalAlignmentTop            equ  0
VtVerticalAlignmentBottom         equ  1
VtVerticalAlignmentCenter         equ  2

;VtOrientation
VtOrientation typedef SDWORD
VtOrientationHorizontal           equ  0
VtOrientationVertical             equ  1
VtOrientationUp                   equ  2
VtOrientationDown                 equ  3

;VtSortType
VtSortType typedef SDWORD
VtSortTypeNone                    equ  0
VtSortTypeAscending               equ  1
VtSortTypeDescending              equ  2

;VtAngleUnits
VtAngleUnits typedef SDWORD
VtAngleUnitsDegrees               equ  0
VtAngleUnitsRadians               equ  1
VtAngleUnitsGrads                 equ  2

;VtPrintScaleType
VtPrintScaleType typedef SDWORD
VtPrintScaleTypeActual            equ  0
VtPrintScaleTypeFitted            equ  1
VtPrintScaleTypeStretched         equ  2

;VtPrintOrientation
VtPrintOrientation typedef SDWORD
VtPrintOrientationPortrait        equ  0
VtPrintOrientationLandscape       equ  1

;VtFontStyle
VtFontStyle typedef SDWORD
VtFontStyleBold                   equ  1
VtFontStyleItalic                 equ  2
VtFontStyleOutline                equ  4

;VtFontEffect
VtFontEffect typedef SDWORD
VtFontEffectStrikeThrough         equ  256          ;=0100h
VtFontEffectUnderline             equ  512          ;=0200h

;VtBrushStyle
VtBrushStyle typedef SDWORD
VtBrushStyleNull                  equ  0
VtBrushStyleSolid                 equ  1
VtBrushStylePattern               equ  2
VtBrushStyleHatched               equ  3

;VtBrushPatterns
VtBrushPatterns typedef SDWORD
VtBrushPattern94Percent           equ  0
VtBrushPattern88Percent           equ  1
VtBrushPattern75Percent           equ  2
VtBrushPattern50Percent           equ  3
VtBrushPattern25Percent           equ  4
VtBrushPatternBoldHorizontal      equ  5
VtBrushPatternBoldVertical        equ  6
VtBrushPatternBoldDownDiagonal    equ  7
VtBrushPatternBoldUpDiagonal      equ  8
VtBrushPatternChecks              equ  9
VtBrushPatternWeave               equ  10
VtBrushPatternHorizontal          equ  11
VtBrushPatternVertical            equ  12
VtBrushPatternDownDiagonal        equ  13
VtBrushPatternUpDiagonal          equ  14
VtBrushPatternGrid                equ  15
VtBrushPatternTrellis             equ  16          ;=010h
VtBrushPatternInvertedTrellis     equ  17          ;=011h
VtBrushPatternCount               equ  18          ;=012h

;--- VtBrushHatches, Type=ENUM, GUID={B8CC5B9B-BD29-11D1-B137-0000F8753F5D}

VtBrushHatches typedef SDWORD
VtBrushHatchHorizontal            equ  0
VtBrushHatchVertical              equ  1
VtBrushHatchDownDiagonal          equ  2
VtBrushHatchUpDiagonal            equ  3
VtBrushHatchCross                 equ  4
VtBrushHatchDiagonalCross         equ  5
VtBrushHatchCount                 equ  6

;--- VtShadowStyle, Type=ENUM, GUID={B8CC5B9C-BD29-11D1-B137-0000F8753F5D}

VtShadowStyle typedef SDWORD
VtShadowStyleNull                 equ  0
VtShadowStyleDrop                 equ  1

;--- VtPenStyle, Type=ENUM, GUID={B8CC5B9D-BD29-11D1-B137-0000F8753F5D}

VtPenStyle typedef SDWORD
VtPenStyleNull                    equ  0
VtPenStyleSolid                   equ  1
VtPenStyleDashed                  equ  2
VtPenStyleDotted                  equ  3
VtPenStyleDashDot                 equ  4
VtPenStyleDashDotDot              equ  5
VtPenStyleDitted                  equ  6
VtPenStyleDashDit                 equ  7
VtPenStyleDashDitDit              equ  8
VtPenStyleNative                  equ  9

;--- VtPenJoin, Type=ENUM, GUID={B8CC5B9E-BD29-11D1-B137-0000F8753F5D}

VtPenJoin typedef SDWORD
VtPenJoinMiter                    equ  0
VtPenJoinRound                    equ  1
VtPenJoinBevel                    equ  2

;--- VtPenCap, Type=ENUM, GUID={B8CC5B9F-BD29-11D1-B137-0000F8753F5D}

VtPenCap typedef SDWORD
VtPenCapButt                      equ  0
VtPenCapRound                     equ  1
VtPenCapSquare                    equ  2

;--- VtFrameStyle, Type=ENUM, GUID={B8CC5BA0-BD29-11D1-B137-0000F8753F5D}

VtFrameStyle typedef SDWORD
VtFrameStyleNull                  equ  0
VtFrameStyleSingleLine            equ  1
VtFrameStyleDoubleLine            equ  2
VtFrameStyleThickInner            equ  3
VtFrameStyleThickOuter            equ  4

;--- VtPictureType, Type=ENUM, GUID={B8CC5BA1-BD29-11D1-B137-0000F8753F5D}

VtPictureType typedef SDWORD
VtPictureTypeNull                 equ  0
VtPictureTypeBitmap               equ  1
VtPictureTypeVector               equ  2
VtPictureTypeBMP                  equ  3
VtPictureTypeWMF                  equ  4

;--- VtPictureOption, Type=ENUM, GUID={B8CC5BA2-BD29-11D1-B137-0000F8753F5D}

VtPictureOption typedef SDWORD
VtPictureOptionNoSizeHeader       equ  1
VtPictureOptionTextAsCurves       equ  2

;--- VtPictureMapType, Type=ENUM, GUID={B8CC5BA3-BD29-11D1-B137-0000F8753F5D}

VtPictureMapType typedef SDWORD
VtPictureMapTypeActual            equ  0
VtPictureMapTypeFitted            equ  1
VtPictureMapTypeStretched         equ  2
VtPictureMapTypeTiled             equ  3
VtPictureMapTypeCropFitted        equ  4
VtPictureMapTypeHorizontalTile    equ  5
VtPictureMapTypeVerticalTile      equ  6

;--- VtGradientStyle, Type=ENUM, GUID={B8CC5BA4-BD29-11D1-B137-0000F8753F5D}

VtGradientStyle typedef SDWORD
VtGradientStyleHorizontal         equ  0
VtGradientStyleVertical           equ  1
VtGradientStyleRectangle          equ  2
VtGradientStyleOval               equ  3

;--- VtFillStyle, Type=ENUM, GUID={B8CC5BA5-BD29-11D1-B137-0000F8753F5D}

VtFillStyle typedef SDWORD
VtFillStyleNull                   equ  0
VtFillStyleBrush                  equ  1
VtFillStyleGradient               equ  2

;--- VtMarkerStyle, Type=ENUM, GUID={B8CC5BA6-BD29-11D1-B137-0000F8753F5D}

VtMarkerStyle typedef SDWORD
VtMarkerStyleDash                 equ  0
VtMarkerStylePlus                 equ  1
VtMarkerStyleX                    equ  2
VtMarkerStyleStar                 equ  3
VtMarkerStyleCircle               equ  4
VtMarkerStyleSquare               equ  5
VtMarkerStyleDiamond              equ  6
VtMarkerStyleUpTriangle           equ  7
VtMarkerStyleDownTriangle         equ  8
VtMarkerStyleFilledCircle         equ  9
VtMarkerStyleFilledSquare         equ  10
VtMarkerStyleFilledDiamond        equ  11
VtMarkerStyleFilledUpTriangle     equ  12
VtMarkerStyleFilledDownTriangle   equ  13
VtMarkerStyle3dBall               equ  14
VtMarkerStyleNull                 equ  15
VtMarkerStyleCount                equ  16          ;=010h

;--- VtProjectionType, Type=ENUM, GUID={B8CC5BA7-BD29-11D1-B137-0000F8753F5D}

VtProjectionType typedef SDWORD
VtProjectionTypePerspective       equ  0
VtProjectionTypeOblique           equ  1
VtProjectionTypeOrthogonal        equ  2
VtProjectionTypeFrontal           equ  3
VtProjectionTypeOverhead          equ  4

;--- VtSmoothingType, Type=ENUM, GUID={B8CC5BA8-BD29-11D1-B137-0000F8753F5D}

VtSmoothingType typedef SDWORD
VtSmoothingTypeNone               equ  0
VtSmoothingTypeQuadraticBSpline   equ  1
VtSmoothingTypeCubicBSpline       equ  2

;--- VtDcType, Type=ENUM, GUID={B8CC5BA9-BD29-11D1-B137-0000F8753F5D}

VtDcType typedef SDWORD
VtDcTypeNull                      equ  0
VtDcTypeDisplay                   equ  1
VtDcTypePrinter                   equ  2
VtDcTypeMetafile                  equ  3

;--- VtTextOutputType, Type=ENUM, GUID={B8CC5BAA-BD29-11D1-B137-0000F8753F5D}

VtTextOutputType typedef SDWORD
VtTextOutputTypeHardware          equ  0
VtTextOutputTypePolygon           equ  1

;--- VtTextLengthType, Type=ENUM, GUID={B8CC5BAB-BD29-11D1-B137-0000F8753F5D}

VtTextLengthType typedef SDWORD
VtTextLengthTypeVirtual           equ  0
VtTextLengthTypeDevice            equ  1

;--- VtChChartType, Type=ENUM, GUID={C091D289-BD43-11D1-B137-0000F8753F5D}

VtChChartType typedef SDWORD
VtChChartType3dBar                equ  0
VtChChartType2dBar                equ  1
VtChChartType3dLine               equ  2
VtChChartType2dLine               equ  3
VtChChartType3dArea               equ  4
VtChChartType2dArea               equ  5
VtChChartType3dStep               equ  6
VtChChartType2dStep               equ  7
VtChChartType3dCombination        equ  8
VtChChartType2dCombination        equ  9
VtChChartType3dHorizontalBar      equ  10
VtChChartType2dHorizontalBar      equ  11
VtChChartType3dClusteredBar       equ  12
VtChChartType3dPie                equ  13
VtChChartType2dPie                equ  14
VtChChartType3dDoughnut           equ  15
VtChChartType2dXY                 equ  16          ;=010h
VtChChartType2dPolar              equ  17          ;=011h
VtChChartType2dRadar              equ  18          ;=012h
VtChChartType2dBubble             equ  19          ;=013h
VtChChartType2dHiLo               equ  20          ;=014h
VtChChartType2dGantt              equ  21          ;=015h
VtChChartType3dGantt              equ  22          ;=016h
VtChChartType3dSurface            equ  23          ;=017h
VtChChartType2dContour            equ  24          ;=018h
VtChChartType3dScatter            equ  25          ;=019h
VtChChartType3dXYZ                equ  26          ;=01Ah
VtChChartTypeCount                equ  27          ;=01Bh

;--- VtChSeriesType, Type=ENUM, GUID={C091D28A-BD43-11D1-B137-0000F8753F5D}

VtChSeriesType typedef SDWORD
VtChSeriesTypeVaries              equ  -2          ;=0FFFFFFFEh
VtChSeriesTypeDefault             equ  -1
VtChSeriesType3dBar               equ  0
VtChSeriesType2dBar               equ  1
VtChSeriesType3dHorizontalBar     equ  2
VtChSeriesType2dHorizontalBar     equ  3
VtChSeriesType3dClusteredBar      equ  4
VtChSeriesType3dLine              equ  5
VtChSeriesType2dLine              equ  6
VtChSeriesType3dArea              equ  7
VtChSeriesType2dArea              equ  8
VtChSeriesType3dStep              equ  9
VtChSeriesType2dStep              equ  10
VtChSeriesType2dXY                equ  11
VtChSeriesType2dPolar             equ  12
VtChSeriesType2dRadarLine         equ  13
VtChSeriesType2dRadarArea         equ  14
VtChSeriesType2dBubble            equ  15
VtChSeriesType2dHiLo              equ  16          ;=010h
VtChSeriesType2dHLC               equ  17          ;=011h
VtChSeriesType2dHLCRight          equ  18          ;=012h
VtChSeriesType2dOHLC              equ  19          ;=013h
VtChSeriesType2dOHLCBar           equ  20          ;=014h
VtChSeriesType2dGantt             equ  21          ;=015h
VtChSeriesType3dGantt             equ  22          ;=016h
VtChSeriesType3dPie               equ  23          ;=017h
VtChSeriesType2dPie               equ  24          ;=018h
VtChSeriesType3dDoughnut          equ  25          ;=019h
VtChSeriesType2dDates             equ  26          ;=01Ah
VtChSeriesType3dBarHiLo           equ  27          ;=01Bh
VtChSeriesType2dBarHiLo           equ  28          ;=01Ch
VtChSeriesType3dHorizontalBarHiLo equ  29          ;=01Dh
VtChSeriesType2dHorizontalBarHiLo equ  30          ;=01Eh
VtChSeriesType3dClusteredBarHiLo  equ  31          ;=01Fh
VtChSeriesType3dSurface           equ  32          ;=020h
VtChSeriesType2dContour           equ  33          ;=021h
VtChSeriesType3dXYZ               equ  34          ;=022h
VtChSeriesTypeCount               equ  35          ;=023h

;--- VtChPartType, Type=ENUM, GUID={C091D28B-BD43-11D1-B137-0000F8753F5D}

VtChPartType typedef SDWORD
VtChPartTypeChart                 equ  0
VtChPartTypeTitle                 equ  1
VtChPartTypeFootnote              equ  2
VtChPartTypeLegend                equ  3
VtChPartTypePlot                  equ  4
VtChPartTypeSeries                equ  5
VtChPartTypeSeriesLabel           equ  6
VtChPartTypePoint                 equ  7
VtChPartTypePointLabel            equ  8
VtChPartTypeAxis                  equ  9
VtChPartTypeAxisLabel             equ  10
VtChPartTypeAxisTitle             equ  11
VtChPartTypeSeriesName            equ  12
VtChPartTypePointName             equ  13
VtChPartTypeCount                 equ  14

;--- VtChLocationType, Type=ENUM, GUID={C091D28C-BD43-11D1-B137-0000F8753F5D}

VtChLocationType typedef SDWORD
VtChLocationTypeTopLeft           equ  0
VtChLocationTypeTop               equ  1
VtChLocationTypeTopRight          equ  2
VtChLocationTypeLeft              equ  3
VtChLocationTypeRight             equ  4
VtChLocationTypeBottomLeft        equ  5
VtChLocationTypeBottom            equ  6
VtChLocationTypeBottomRight       equ  7
VtChLocationTypeCustom            equ  8

;--- VtChLabelComponent, Type=ENUM, GUID={C091D28D-BD43-11D1-B137-0000F8753F5D}

VtChLabelComponent typedef SDWORD
VtChLabelComponentValue           equ  1
VtChLabelComponentPercent         equ  2
VtChLabelComponentSeriesName      equ  4
VtChLabelComponentPointName       equ  8

;--- VtChLabelLineStyle, Type=ENUM, GUID={C091D28E-BD43-11D1-B137-0000F8753F5D}

VtChLabelLineStyle typedef SDWORD
VtChLabelLineStyleNone            equ  0
VtChLabelLineStyleStraight        equ  1
VtChLabelLineStyleBent            equ  2

;--- VtChLabelLocationType, Type=ENUM, GUID={C091D28F-BD43-11D1-B137-0000F8753F5D}

VtChLabelLocationType typedef SDWORD
VtChLabelLocationTypeNone         equ  0
VtChLabelLocationTypeAbovePoint   equ  1
VtChLabelLocationTypeBelowPoint   equ  2
VtChLabelLocationTypeCenter       equ  3
VtChLabelLocationTypeBase         equ  4
VtChLabelLocationTypeInside       equ  5
VtChLabelLocationTypeOutside      equ  6
VtChLabelLocationTypeLeft         equ  7
VtChLabelLocationTypeRight        equ  8

;--- VtChSubPlotLabelLocationType, Type=ENUM, GUID={C091D290-BD43-11D1-B137-0000F8753F5D}

VtChSubPlotLabelLocationType typedef SDWORD
VtChSubPlotLabelLocationTypeNone  equ  0
VtChSubPlotLabelLocationTypeAbove equ  1
VtChSubPlotLabelLocationTypeBelow equ  2
VtChSubPlotLabelLocationTypeCenter  equ  3

;--- VtChPieWeightBasis, Type=ENUM, GUID={C091D291-BD43-11D1-B137-0000F8753F5D}

VtChPieWeightBasis typedef SDWORD
VtChPieWeightBasisNone            equ  0
VtChPieWeightBasisTotal           equ  1
VtChPieWeightBasisSeries          equ  2

;--- VtChPieWeightStyle, Type=ENUM, GUID={C091D292-BD43-11D1-B137-0000F8753F5D}

VtChPieWeightStyle typedef SDWORD
VtChPieWeightStyleArea            equ  0
VtChPieWeightStyleDiameter        equ  1

;--- VtChAxisId, Type=ENUM, GUID={C091D293-BD43-11D1-B137-0000F8753F5D}

VtChAxisId typedef SDWORD
VtChAxisIdX                       equ  0
VtChAxisIdY                       equ  1
VtChAxisIdY2                      equ  2
VtChAxisIdZ                       equ  3
VtChAxisIdNone                    equ  4

;--- VtChDateIntervalType, Type=ENUM, GUID={C091D294-BD43-11D1-B137-0000F8753F5D}

VtChDateIntervalType typedef SDWORD
VtChDateIntervalTypeNone          equ  0
VtChDateIntervalTypeDaily         equ  1
VtChDateIntervalTypeWeekly        equ  2
VtChDateIntervalTypeSemimonthly   equ  3
VtChDateIntervalTypeMonthly       equ  4
VtChDateIntervalTypeYearly        equ  5

;--- VtChScaleType, Type=ENUM, GUID={C091D295-BD43-11D1-B137-0000F8753F5D}

VtChScaleType typedef SDWORD
VtChScaleTypeLinear               equ  0
VtChScaleTypeLogarithmic          equ  1
VtChScaleTypePercent              equ  2

;--- VtChPercentAxisBasis, Type=ENUM, GUID={C091D296-BD43-11D1-B137-0000F8753F5D}

VtChPercentAxisBasis typedef SDWORD
VtChPercentAxisBasisMaxChart      equ  0
VtChPercentAxisBasisMaxRow        equ  1
VtChPercentAxisBasisMaxColumn     equ  2
VtChPercentAxisBasisSumChart      equ  3
VtChPercentAxisBasisSumRow        equ  4
VtChPercentAxisBasisSumColumn     equ  5

;--- VtChAxisTickStyle, Type=ENUM, GUID={C091D297-BD43-11D1-B137-0000F8753F5D}

VtChAxisTickStyle typedef SDWORD
VtChAxisTickStyleNone             equ  0
VtChAxisTickStyleCenter           equ  1
VtChAxisTickStyleInside           equ  2
VtChAxisTickStyleOutside          equ  3

;--- VtChStats, Type=ENUM, GUID={C091D298-BD43-11D1-B137-0000F8753F5D}

VtChStats typedef SDWORD
VtChStatsMinimum                  equ  1
VtChStatsMaximum                  equ  2
VtChStatsMean                     equ  4
VtChStatsStddev                   equ  8
VtChStatsRegression               equ  16          ;=010h

;--- VtChUpdateFlags, Type=ENUM, GUID={C091D299-BD43-11D1-B137-0000F8753F5D}

VtChUpdateFlags typedef SDWORD
VtChNoDisplay                     equ  0
VtChDisplayPlot                   equ  1
VtChLayoutPlot                    equ  2
VtChDisplayLegend                 equ  4
VtChLayoutLegend                  equ  8
VtChLayoutSeries                  equ  16          ;=010h
VtChPositionSection               equ  32          ;=020h

;--- VtChMouseFlag, Type=ENUM, GUID={C091D2A2-BD43-11D1-B137-0000F8753F5D}

VtChMouseFlag typedef SDWORD
VtChMouseFlagShiftKeyDown         equ  4
VtChMouseFlagControlKeyDown       equ  8

;--- VtChSsLinkMode, Type=ENUM, GUID={C091D29A-BD43-11D1-B137-0000F8753F5D}

VtChSsLinkMode typedef SDWORD
VtChSsLinkModeOff                 equ  0
VtChSsLinkModeOn                  equ  1
VtChSsLinkModeAutoParse           equ  2

;--- VtChDrawMode, Type=ENUM, GUID={C091D29B-BD43-11D1-B137-0000F8753F5D}

VtChDrawMode typedef SDWORD
VtChDrawModeDraw                  equ  0
VtChDrawModeBlit                  equ  1

;--- VtChContourColorType, Type=ENUM, GUID={C091D29C-BD43-11D1-B137-0000F8753F5D}

VtChContourColorType typedef SDWORD
VtChContourColorTypeAutomatic     equ  0
VtChContourColorTypeGradient      equ  1
VtChContourColorTypeManual        equ  2

;--- VtChContourDisplayType, Type=ENUM, GUID={C091D29D-BD43-11D1-B137-0000F8753F5D}

VtChContourDisplayType typedef SDWORD
VtChContourDisplayTypeCBands      equ  0
VtChContourDisplayTypeCLines      equ  1

;--- VtChSurfaceBaseType, Type=ENUM, GUID={C091D29E-BD43-11D1-B137-0000F8753F5D}

VtChSurfaceBaseType typedef SDWORD
VtChSurfaceBaseTypePedestal       equ  0
VtChSurfaceBaseTypeStandard       equ  1
VtChSurfaceBaseTypeStandardWithCBands  equ  2
VtChSurfaceBaseTypeStandardWithCLines  equ  3

;--- VtChSurfaceDisplayType, Type=ENUM, GUID={C091D29F-BD43-11D1-B137-0000F8753F5D}

VtChSurfaceDisplayType typedef SDWORD
VtChSurfaceDisplayTypeNone        equ  0
VtChSurfaceDisplayTypeCBands      equ  1
VtChSurfaceDisplayTypeCLines      equ  2
VtChSurfaceDisplayTypeSolid       equ  3
VtChSurfaceDisplayTypeSolidWithCLines  equ  4

;--- VtChSurfaceProjectionType, Type=ENUM, GUID={C091D2A0-BD43-11D1-B137-0000F8753F5D}

VtChSurfaceProjectionType typedef SDWORD
VtChSurfaceProjectionTypeNone     equ  0
VtChSurfaceProjectionTypeCBands   equ  1
VtChSurfaceProjectionTypeCLines   equ  2

;--- VtChSurfaceWireframeType, Type=ENUM, GUID={C091D2A1-BD43-11D1-B137-0000F8753F5D}

VtChSurfaceWireframeType typedef SDWORD
VtChSurfaceWireframeTypeNone      equ  0
VtChSurfaceWireframeTypeMajor     equ  1
VtChSurfaceWireframeTypeMajorAndMinor  equ  2

;--- VtBorderStyle, Type=ENUM, GUID={3A2B3708-BA0A-11D1-B137-0000F8753F5D}

VtBorderStyle typedef SDWORD
VtBorderStyleNone                 equ  0
VtBorderStyleFixedSingle          equ  1

;--- VtMousePointer, Type=ENUM, GUID={3A2B3709-BA0A-11D1-B137-0000F8753F5D}

VtMousePointer typedef SDWORD
VtMousePointerDefault             equ  0
VtMousePointerArrow               equ  1
VtMousePointerCross               equ  2
VtMousePointerIbeam               equ  3
VtMousePointerIcon                equ  4
VtMousePointerSize                equ  5
VtMousePointerSizeNESW            equ  6
VtMousePointerSizeNS              equ  7
VtMousePointerSizeNWSE            equ  8
VtMousePointerSizeWE              equ  9
VtMousePointerUpArrow             equ  10
VtMousePointerHourGlass           equ  11
VtMousePointerNoDrop              equ  12
VtMousePointerArrowHourGlass      equ  13
VtMousePointerArrowQuestion       equ  14
VtMousePointerSizeAll             equ  15


COM_INTERFACE_BEG IVBDataObject, IDispatch, <2334D2B1-713E-11CF-8AE5-00AA00C00905>
  COM_MTD_STD  Clear
  COM_MTD_STD  GetData, :SWORD,:ptr VARIANT
  COM_MTD_STD  GetFormat, :SWORD,:ptr BOOL
  COM_MTD_STD  SetData, :VARIANT,:VARIANT
  COM_MTD_STD  get_Files, :ptr ptr IVBDataObjectFiles
COM_INTERFACE_END


COM_INTERFACE_BEG IVBDataObjectFiles, IDispatch, <2334D2B3-713E-11CF-8AE5-00AA00C00905>
  COM_MTD_STD  get_Item, :SDWORD,:ptr BSTR
  COM_MTD_STD  get_Count, :ptr SDWORD
  COM_MTD_STD  Add_, :BSTR,:VARIANT
  COM_MTD_STD  Clear
  COM_MTD_STD  Remove, :VARIANT
  COM_MTD_STD  _NewEnum, :ptr LPUNKNOWN
COM_INTERFACE_END


COM_INTERFACE_BEG IVcCoor, IDispatch, <E9E074C9-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_X, :ptr REAL4
  COM_MTD_STD  put_X, :REAL4
  COM_MTD_STD  get_Y, :ptr REAL4
  COM_MTD_STD  put_Y, :REAL4
  COM_MTD_STD  Set, :REAL4,:REAL4
COM_INTERFACE_END


COM_INTERFACE_BEG IVcLCoor, IDispatch, <E9E074CB-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_X, :ptr SDWORD
  COM_MTD_STD  put_X, :SDWORD
  COM_MTD_STD  get_Y, :ptr SDWORD
  COM_MTD_STD  put_Y, :SDWORD
  COM_MTD_STD  Set, :SDWORD,:SDWORD
COM_INTERFACE_END


COM_INTERFACE_BEG IVcRect, IDispatch, <E9E074CD-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_Min, :ptr ptr IVcCoor
  COM_MTD_STD  get_Max, :ptr ptr IVcCoor
COM_INTERFACE_END


COM_INTERFACE_BEG IVcColor, IDispatch, <E9E074CF-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_Red, :ptr SWORD
  COM_MTD_STD  put_Red, :SWORD
  COM_MTD_STD  get_Green, :ptr SWORD
  COM_MTD_STD  put_Green, :SWORD
  COM_MTD_STD  get_Blue, :ptr SWORD
  COM_MTD_STD  put_Blue, :SWORD
  COM_MTD_STD  get_Automatic, :ptr BOOL
  COM_MTD_STD  put_Automatic, :BOOL
  COM_MTD_STD  Set, :SWORD,:SWORD,:SWORD
COM_INTERFACE_END


COM_INTERFACE_BEG IVcPen, IDispatch, <E9E074D1-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_Style, :ptr VtPenStyle
  COM_MTD_STD  put_Style, :VtPenStyle
  COM_MTD_STD  get_Join, :ptr VtPenJoin
  COM_MTD_STD  put_Join, :VtPenJoin
  COM_MTD_STD  get_Cap, :ptr VtPenCap
  COM_MTD_STD  put_Cap, :VtPenCap
  COM_MTD_STD  get_VtColor, :ptr ptr IVcColor
  COM_MTD_STD  get_Width, :ptr REAL4
  COM_MTD_STD  put_Width, :REAL4
  COM_MTD_STD  get_Limit, :ptr REAL4
  COM_MTD_STD  put_Limit, :REAL4
COM_INTERFACE_END


COM_INTERFACE_BEG IVcMarker, IDispatch, <E9E074D3-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_Visible, :ptr BOOL
  COM_MTD_STD  put_Visible, :BOOL
  COM_MTD_STD  get_Style, :ptr VtMarkerStyle
  COM_MTD_STD  put_Style, :VtMarkerStyle
  COM_MTD_STD  get_Pen, :ptr ptr IVcPen
  COM_MTD_STD  get_Size, :ptr REAL4
  COM_MTD_STD  put_Size, :REAL4
  COM_MTD_STD  get_FillColor, :ptr ptr IVcColor
COM_INTERFACE_END


COM_INTERFACE_BEG IVcTextLayout, IDispatch, <E9E074D5-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_HorzAlignment, :ptr VtHorizontalAlignment
  COM_MTD_STD  put_HorzAlignment, :VtHorizontalAlignment
  COM_MTD_STD  get_VertAlignment, :ptr VtVerticalAlignment
  COM_MTD_STD  put_VertAlignment, :VtVerticalAlignment
  COM_MTD_STD  get_Orientation, :ptr VtOrientation
  COM_MTD_STD  put_Orientation, :VtOrientation
  COM_MTD_STD  get_WordWrap, :ptr BOOL
  COM_MTD_STD  put_WordWrap, :BOOL
COM_INTERFACE_END


COM_INTERFACE_BEG IVcLocation, IDispatch, <E9E074D6-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_Rect, :ptr ptr IVcRect
  COM_MTD_STD  get_Visible, :ptr BOOL
  COM_MTD_STD  put_Visible, :BOOL
  COM_MTD_STD  get_LocationType, :ptr VtChLocationType
  COM_MTD_STD  put_LocationType, :VtChLocationType
COM_INTERFACE_END


COM_INTERFACE_BEG IVcFont, IDispatch, <E9E074D8-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_Name, :ptr BSTR
  COM_MTD_STD  put_Name, :BSTR
  COM_MTD_STD  get_Size, :ptr REAL4
  COM_MTD_STD  put_Size, :REAL4
  COM_MTD_STD  get_Style, :ptr SWORD
  COM_MTD_STD  put_Style, :SWORD
  COM_MTD_STD  get_Effect, :ptr SWORD
  COM_MTD_STD  put_Effect, :SWORD
  COM_MTD_STD  get_VtColor, :ptr ptr IVcColor
COM_INTERFACE_END


COM_INTERFACE_BEG IVcBrush, IDispatch, <E9E074DA-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_Style, :ptr VtBrushStyle
  COM_MTD_STD  put_Style, :VtBrushStyle
  COM_MTD_STD  get_FillColor, :ptr ptr IVcColor
  COM_MTD_STD  get_PatternColor, :ptr ptr IVcColor
  COM_MTD_STD  get_Index, :ptr VtBrushPatterns
  COM_MTD_STD  put_Index, :VtBrushPatterns
COM_INTERFACE_END


COM_INTERFACE_BEG IVcShadow, IDispatch, <E9E074DC-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_Style, :ptr VtShadowStyle
  COM_MTD_STD  put_Style, :VtShadowStyle
  COM_MTD_STD  get_Brush, :ptr ptr IVcBrush
  COM_MTD_STD  get_Offset, :ptr ptr IVcCoor
COM_INTERFACE_END


COM_INTERFACE_BEG IVcFill, IDispatch, <E9E074DE-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_Style, :ptr VtFillStyle
  COM_MTD_STD  put_Style, :VtFillStyle
  COM_MTD_STD  get_Brush, :ptr ptr IVcBrush
COM_INTERFACE_END


COM_INTERFACE_BEG IVcFrame, IDispatch, <E9E074E0-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_Style, :ptr VtFrameStyle
  COM_MTD_STD  put_Style, :VtFrameStyle
  COM_MTD_STD  get_FrameColor, :ptr ptr IVcColor
  COM_MTD_STD  get_SpaceColor, :ptr ptr IVcColor
  COM_MTD_STD  get_Width, :ptr REAL4
  COM_MTD_STD  put_Width, :REAL4
COM_INTERFACE_END


COM_INTERFACE_BEG IVcBackdrop, IDispatch, <E9E074E2-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_Shadow, :ptr ptr IVcShadow
  COM_MTD_STD  get_Frame, :ptr ptr IVcFrame
  COM_MTD_STD  get_Fill, :ptr ptr IVcFill
COM_INTERFACE_END


COM_INTERFACE_BEG IVcTitle, IDispatch, <E9E074E4-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get__Text, :ptr BSTR
  COM_MTD_STD  put__Text, :BSTR
  COM_MTD_STD  get_TextLayout, :ptr ptr IVcTextLayout
  COM_MTD_STD  get_Text, :ptr BSTR
  COM_MTD_STD  put_Text, :BSTR
  COM_MTD_STD  get_Location, :ptr ptr IVcLocation
  COM_MTD_STD  get_Backdrop, :ptr ptr IVcBackdrop
  COM_MTD_STD  get_VtFont, :ptr ptr IVcFont
  COM_MTD_STD  get_TextLength, :ptr SWORD
  COM_MTD_STD  putref_Font, :ptr IFontDisp
  COM_MTD_STD  get_Font, :ptr ptr IFontDisp
  COM_MTD_STD  Select
COM_INTERFACE_END


COM_INTERFACE_BEG IVcFootnote, IDispatch, <E9E074E6-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get__Text, :ptr BSTR
  COM_MTD_STD  put__Text, :BSTR
  COM_MTD_STD  get_TextLayout, :ptr ptr IVcTextLayout
  COM_MTD_STD  get_Location, :ptr ptr IVcLocation
  COM_MTD_STD  get_Backdrop, :ptr ptr IVcBackdrop
  COM_MTD_STD  get_VtFont, :ptr ptr IVcFont
  COM_MTD_STD  get_Text, :ptr BSTR
  COM_MTD_STD  put_Text, :BSTR
  COM_MTD_STD  get_TextLength, :ptr SWORD
  COM_MTD_STD  putref_Font, :ptr IFontDisp
  COM_MTD_STD  get_Font, :ptr ptr IFontDisp
  COM_MTD_STD  Select
COM_INTERFACE_END


COM_INTERFACE_BEG IVcLegend, IDispatch, <E9E074E8-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_Location, :ptr ptr IVcLocation
  COM_MTD_STD  get_Backdrop, :ptr ptr IVcBackdrop
  COM_MTD_STD  get_VtFont, :ptr ptr IVcFont
  COM_MTD_STD  get_TextLayout, :ptr ptr IVcTextLayout
  COM_MTD_STD  putref_Font, :ptr IFontDisp
  COM_MTD_STD  get_Font, :ptr ptr IFontDisp
  COM_MTD_STD  Select
COM_INTERFACE_END


COM_INTERFACE_BEG IVcDataGrid, IDispatch, <E9E074EA-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_ColumnCount, :ptr SWORD
  COM_MTD_STD  put_ColumnCount, :SWORD
  COM_MTD_STD  get_ColumnLabelCount, :ptr SWORD
  COM_MTD_STD  put_ColumnLabelCount, :SWORD
  COM_MTD_STD  get_RowLabelCount, :ptr SWORD
  COM_MTD_STD  put_RowLabelCount, :SWORD
  COM_MTD_STD  get_RowCount, :ptr SWORD
  COM_MTD_STD  put_RowCount, :SWORD
  COM_MTD_STD  DeleteColumns, :SWORD,:SWORD
  COM_MTD_STD  InsertColumns, :SWORD,:SWORD
  COM_MTD_STD  DeleteColumnLabels, :SWORD,:SWORD
  COM_MTD_STD  InsertColumnLabels, :SWORD,:SWORD
  COM_MTD_STD  DeleteRows, :SWORD,:SWORD
  COM_MTD_STD  InsertRows, :SWORD,:SWORD
  COM_MTD_STD  DeleteRowLabels, :SWORD,:SWORD
  COM_MTD_STD  InsertRowLabels, :SWORD,:SWORD
  COM_MTD_STD  RandomDataFill
  COM_MTD_STD  SetSize, :SWORD,:SWORD,:SWORD,:SWORD
  COM_MTD_STD  InitializeLabels
  COM_MTD_STD  RandomFillColumns, :SWORD,:SWORD
  COM_MTD_STD  RandomFillRows, :SWORD,:SWORD
  COM_MTD_STD  MoveData, :SWORD,:SWORD,:SWORD,:SWORD,:SWORD,:SWORD
  COM_MTD_STD  GetData, :SWORD,:SWORD,:ptr REAL8,:ptr SWORD
  COM_MTD_STD  SetData, :SWORD,:SWORD,:REAL8,:SWORD
  COM_MTD_STD  get_ColumnLabel, :SWORD,:SWORD,:ptr BSTR
  COM_MTD_STD  put_ColumnLabel, :SWORD,:SWORD,:BSTR
  COM_MTD_STD  get_CompositeColumnLabel, :SWORD,:ptr BSTR
  COM_MTD_STD  get_CompositeRowLabel, :SWORD,:ptr BSTR
  COM_MTD_STD  get_RowLabel, :SWORD,:SWORD,:ptr BSTR
  COM_MTD_STD  put_RowLabel, :SWORD,:SWORD,:BSTR
COM_INTERFACE_END


COM_INTERFACE_BEG IVcLightSource, IDispatch, <E9E074EC-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get__Intensity, :ptr REAL4
  COM_MTD_STD  put__Intensity, :REAL4
  COM_MTD_STD  get_Intensity, :ptr REAL4
  COM_MTD_STD  put_Intensity, :REAL4
  COM_MTD_STD  get_X, :ptr REAL4
  COM_MTD_STD  put_X, :REAL4
  COM_MTD_STD  get_Y, :ptr REAL4
  COM_MTD_STD  put_Y, :REAL4
  COM_MTD_STD  get_Z, :ptr REAL4
  COM_MTD_STD  put_Z, :REAL4
  COM_MTD_STD  Set, :REAL4,:REAL4,:REAL4,:REAL4
COM_INTERFACE_END


COM_INTERFACE_BEG IVcLightSources, IDispatch, <E9E074EE-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get__NewEnum, :ptr LPUNKNOWN
  COM_MTD_STD  get_Count, :ptr SDWORD
  COM_MTD_STD  Add_, :REAL4,:REAL4,:REAL4,:REAL4,:ptr ptr IVcLightSource
  COM_MTD_STD  Remove, :SWORD
  COM_MTD_STD  get_Item, :SWORD,:ptr ptr IVcLightSource
  COM_MTD_STD  get__Item, :SWORD,:ptr ptr IVcLightSource
COM_INTERFACE_END


COM_INTERFACE_BEG IVcLight, IDispatch, <E9E074F0-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_AmbientIntensity, :ptr REAL4
  COM_MTD_STD  put_AmbientIntensity, :REAL4
  COM_MTD_STD  get_EdgeIntensity, :ptr REAL4
  COM_MTD_STD  put_EdgeIntensity, :REAL4
  COM_MTD_STD  get_EdgeVisible, :ptr BOOL
  COM_MTD_STD  put_EdgeVisible, :BOOL
  COM_MTD_STD  get_LightSources, :ptr ptr IVcLightSources
COM_INTERFACE_END


COM_INTERFACE_BEG IVcView3d, IDispatch, <E9E074F2-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_Rotation, :ptr REAL4
  COM_MTD_STD  put_Rotation, :REAL4
  COM_MTD_STD  get_Elevation, :ptr REAL4
  COM_MTD_STD  put_Elevation, :REAL4
  COM_MTD_STD  Set, :REAL4,:REAL4
COM_INTERFACE_END


COM_INTERFACE_BEG IVcPlotBase, IDispatch, <E9E074F4-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_BaseHeight, :ptr REAL4
  COM_MTD_STD  put_BaseHeight, :REAL4
  COM_MTD_STD  get_Brush, :ptr ptr IVcBrush
  COM_MTD_STD  get_Pen, :ptr ptr IVcPen
COM_INTERFACE_END


COM_INTERFACE_BEG IVcWeighting, IDispatch, <E9E074FA-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_Basis, :ptr VtChPieWeightBasis
  COM_MTD_STD  put_Basis, :VtChPieWeightBasis
  COM_MTD_STD  get_Style, :ptr VtChPieWeightStyle
  COM_MTD_STD  put_Style, :VtChPieWeightStyle
  COM_MTD_STD  Set, :VtChPieWeightBasis,:VtChPieWeightStyle
COM_INTERFACE_END


COM_INTERFACE_BEG IVcWall, IDispatch, <E9E074FC-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_Width, :ptr REAL4
  COM_MTD_STD  put_Width, :REAL4
  COM_MTD_STD  get_Brush, :ptr ptr IVcBrush
  COM_MTD_STD  get_Pen, :ptr ptr IVcPen
COM_INTERFACE_END


COM_INTERFACE_BEG IVcSeriesPosition, IDispatch, <E9E07502-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_Excluded, :ptr BOOL
  COM_MTD_STD  put_Excluded, :BOOL
  COM_MTD_STD  get_Hidden, :ptr BOOL
  COM_MTD_STD  put_Hidden, :BOOL
  COM_MTD_STD  get_Order, :ptr SWORD
  COM_MTD_STD  put_Order, :SWORD
  COM_MTD_STD  get_StackOrder, :ptr SWORD
  COM_MTD_STD  put_StackOrder, :SWORD
COM_INTERFACE_END


COM_INTERFACE_BEG IVcSeriesMarker, IDispatch, <E9E07504-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_Auto, :ptr BOOL
  COM_MTD_STD  put_Auto, :BOOL
  COM_MTD_STD  get_Show, :ptr BOOL
  COM_MTD_STD  put_Show, :BOOL
COM_INTERFACE_END


COM_INTERFACE_BEG IVcStatLine, IDispatch, <E9E07506-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_Flag, :ptr SWORD
  COM_MTD_STD  put_Flag, :SWORD
  COM_MTD_STD  get_VtColor, :ptr ptr IVcColor
  COM_MTD_STD  get_Width, :ptr REAL4
  COM_MTD_STD  put_Width, :REAL4
  COM_MTD_STD  get_Style, :VtChStats,:ptr VtPenStyle
  COM_MTD_STD  put_Style, :VtChStats,:VtPenStyle
COM_INTERFACE_END


COM_INTERFACE_BEG IVcLabel, IDispatch, <E9E07508-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_Backdrop, :ptr ptr IVcBackdrop
  COM_MTD_STD  get_Format, :ptr BSTR
  COM_MTD_STD  put_Format, :BSTR
  COM_MTD_STD  get_VtFont, :ptr ptr IVcFont
  COM_MTD_STD  get_Auto, :ptr BOOL
  COM_MTD_STD  put_Auto, :BOOL
  COM_MTD_STD  get_Standing, :ptr BOOL
  COM_MTD_STD  put_Standing, :BOOL
  COM_MTD_STD  get_TextLayout, :ptr ptr IVcTextLayout
  COM_MTD_STD  get_FormatLength, :ptr SWORD
  COM_MTD_STD  putref_Font, :ptr IFontDisp
  COM_MTD_STD  get_Font, :ptr ptr IFontDisp
COM_INTERFACE_END


COM_INTERFACE_BEG IVcLabels, IDispatch, <E9E0750A-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get__NewEnum, :ptr LPUNKNOWN
  COM_MTD_STD  get_Count, :ptr SDWORD
  COM_MTD_STD  get__Item, :SWORD,:ptr ptr IVcLabel
  COM_MTD_STD  get_Item, :SWORD,:ptr ptr IVcLabel
COM_INTERFACE_END


COM_INTERFACE_BEG IVcDataPointLabel, IDispatch, <E9E0750C-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get__Text, :ptr BSTR
  COM_MTD_STD  put__Text, :BSTR
  COM_MTD_STD  get_Text, :ptr BSTR
  COM_MTD_STD  put_Text, :BSTR
  COM_MTD_STD  get_Backdrop, :ptr ptr IVcBackdrop
  COM_MTD_STD  get_VtFont, :ptr ptr IVcFont
  COM_MTD_STD  get_Offset, :ptr ptr IVcLCoor
  COM_MTD_STD  get_TextLayout, :ptr ptr IVcTextLayout
  COM_MTD_STD  get_LocationType, :ptr VtChLabelLocationType
  COM_MTD_STD  put_LocationType, :VtChLabelLocationType
  COM_MTD_STD  get_Custom, :ptr BOOL
  COM_MTD_STD  put_Custom, :BOOL
  COM_MTD_STD  get_Component, :ptr SWORD
  COM_MTD_STD  put_Component, :SWORD
  COM_MTD_STD  get_LineStyle, :ptr VtChLabelLineStyle
  COM_MTD_STD  put_LineStyle, :VtChLabelLineStyle
  COM_MTD_STD  get_ValueFormat, :ptr BSTR
  COM_MTD_STD  put_ValueFormat, :BSTR
  COM_MTD_STD  get_PercentFormat, :ptr BSTR
  COM_MTD_STD  put_PercentFormat, :BSTR
  COM_MTD_STD  get_TextLength, :ptr SWORD
  COM_MTD_STD  putref_Font, :ptr IFontDisp
  COM_MTD_STD  get_Font, :ptr ptr IFontDisp
  COM_MTD_STD  ResetCustomLabel
  COM_MTD_STD  Select
COM_INTERFACE_END


COM_INTERFACE_BEG IVcDataPoint, IDispatch, <E9E0750E-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_DataPointLabel, :ptr ptr IVcDataPointLabel
  COM_MTD_STD  get_Brush, :ptr ptr IVcBrush
  COM_MTD_STD  get_EdgePen, :ptr ptr IVcPen
  COM_MTD_STD  get_Marker, :ptr ptr IVcMarker
  COM_MTD_STD  get_Offset, :ptr REAL4
  COM_MTD_STD  put_Offset, :REAL4
  COM_MTD_STD  ResetCustom
  COM_MTD_STD  Select
COM_INTERFACE_END


COM_INTERFACE_BEG IVcDataPoints, IDispatch, <E9E0752A-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get__NewEnum, :ptr LPUNKNOWN
  COM_MTD_STD  get_Count, :ptr SDWORD
  COM_MTD_STD  get_Item, :SWORD,:ptr ptr IVcDataPoint
  COM_MTD_STD  get__Item, :SWORD,:ptr ptr IVcDataPoint
COM_INTERFACE_END


COM_INTERFACE_BEG IVcSeries, IDispatch, <E9E07511-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get__LegendText, :ptr BSTR
  COM_MTD_STD  put__LegendText, :BSTR
  COM_MTD_STD  get_SecondaryAxis, :ptr BOOL
  COM_MTD_STD  put_SecondaryAxis, :BOOL
  COM_MTD_STD  get_SeriesType, :ptr VtChSeriesType
  COM_MTD_STD  put_SeriesType, :VtChSeriesType
  COM_MTD_STD  get_GuideLinePen, :ptr ptr IVcPen
  COM_MTD_STD  get_ShowLine, :ptr BOOL
  COM_MTD_STD  put_ShowLine, :BOOL
  COM_MTD_STD  get_Pen, :ptr ptr IVcPen
  COM_MTD_STD  get_Position, :ptr ptr IVcSeriesPosition
  COM_MTD_STD  get_SeriesMarker, :ptr ptr IVcSeriesMarker
  COM_MTD_STD  get_StatLine, :ptr ptr IVcStatLine
  COM_MTD_STD  get_DataPoints, :ptr ptr IVcDataPoints
  COM_MTD_STD  get_LegendText, :ptr BSTR
  COM_MTD_STD  put_LegendText, :BSTR
  COM_MTD_STD  Select
  COM_MTD_STD  get_ShowGuideLine, :VtChAxisId,:ptr BOOL
  COM_MTD_STD  put_ShowGuideLine, :VtChAxisId,:BOOL
  COM_MTD_STD  get_TypeByChartType, :VtChChartType,:ptr VtChSeriesType
COM_INTERFACE_END


COM_INTERFACE_BEG IVcSeriesCollection, IDispatch, <E9E07513-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get__NewEnum, :ptr LPUNKNOWN
  COM_MTD_STD  Count, :ptr SDWORD
  COM_MTD_STD  get_Item, :SWORD,:ptr ptr IVcSeries
  COM_MTD_STD  get__Item, :SWORD,:ptr ptr IVcSeries
COM_INTERFACE_END

COM_INTERFACE_BEG IVcAxisTitle, IDispatch, <E9E07515-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get__Text, :ptr BSTR
  COM_MTD_STD  put__Text, :BSTR
  COM_MTD_STD  get_Text, :ptr BSTR
  COM_MTD_STD  put_Text, :BSTR
  COM_MTD_STD  get_Backdrop, :ptr ptr IVcBackdrop
  COM_MTD_STD  get_VtFont, :ptr ptr IVcFont
  COM_MTD_STD  get_Visible, :ptr BOOL
  COM_MTD_STD  put_Visible, :BOOL
  COM_MTD_STD  get_TextLayout, :ptr ptr IVcTextLayout
  COM_MTD_STD  get_TextLength, :ptr SWORD
  COM_MTD_STD  putref_Font, :ptr IFontDisp
  COM_MTD_STD  get_Font, :ptr ptr IFontDisp
COM_INTERFACE_END

COM_INTERFACE_BEG IVcCategoryScale, IDispatch, <E9E07517-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_Auto, :ptr BOOL
  COM_MTD_STD  put_Auto, :BOOL
  COM_MTD_STD  get_DivisionsPerLabel, :ptr SWORD
  COM_MTD_STD  put_DivisionsPerLabel, :SWORD
  COM_MTD_STD  get_DivisionsPerTick, :ptr SWORD
  COM_MTD_STD  put_DivisionsPerTick, :SWORD
  COM_MTD_STD  get_LabelTick, :ptr BOOL
  COM_MTD_STD  put_LabelTick, :BOOL
COM_INTERFACE_END


COM_INTERFACE_BEG IVcAxisGrid, IDispatch, <E9E0751B-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_MinorPen, :ptr ptr IVcPen
  COM_MTD_STD  get_MajorPen, :ptr ptr IVcPen
COM_INTERFACE_END


COM_INTERFACE_BEG IVcIntersection, IDispatch, <E9E0751D-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_Auto, :ptr BOOL
  COM_MTD_STD  put_Auto, :BOOL
  COM_MTD_STD  get_Point, :ptr REAL8
  COM_MTD_STD  put_Point, :REAL8
  COM_MTD_STD  get_axisID, :ptr VtChAxisId
  COM_MTD_STD  get_Index, :ptr SWORD
  COM_MTD_STD  get_LabelsInsidePlot, :ptr BOOL
  COM_MTD_STD  put_LabelsInsidePlot, :BOOL
COM_INTERFACE_END


COM_INTERFACE_BEG IVcTick, IDispatch, <E9E0751F-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_Length, :ptr REAL4
  COM_MTD_STD  put_Length, :REAL4
  COM_MTD_STD  get_Style, :ptr VtChAxisTickStyle
  COM_MTD_STD  put_Style, :VtChAxisTickStyle
COM_INTERFACE_END


COM_INTERFACE_BEG IVcAxisScale, IDispatch, <E9E07521-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_Hide, :ptr BOOL
  COM_MTD_STD  put_Hide, :BOOL
  COM_MTD_STD  get_type, :ptr VtChScaleType
  COM_MTD_STD  put_type, :VtChScaleType
  COM_MTD_STD  get_LogBase, :ptr SWORD
  COM_MTD_STD  put_LogBase, :SWORD
  COM_MTD_STD  get_PercentBasis, :ptr VtChPercentAxisBasis
  COM_MTD_STD  put_PercentBasis, :VtChPercentAxisBasis
COM_INTERFACE_END


COM_INTERFACE_BEG IVcValueScale, IDispatch, <E9E07523-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_Auto, :ptr BOOL
  COM_MTD_STD  put_Auto, :BOOL
  COM_MTD_STD  get_Minimum, :ptr REAL8
  COM_MTD_STD  put_Minimum, :REAL8
  COM_MTD_STD  get_Maximum, :ptr REAL8
  COM_MTD_STD  put_Maximum, :REAL8
  COM_MTD_STD  get_MajorDivision, :ptr SWORD
  COM_MTD_STD  put_MajorDivision, :SWORD
  COM_MTD_STD  get_MinorDivision, :ptr SWORD
  COM_MTD_STD  put_MinorDivision, :SWORD
COM_INTERFACE_END


COM_INTERFACE_BEG IVcAxis, IDispatch, <E9E07525-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_Pen, :ptr ptr IVcPen
  COM_MTD_STD  get_LabelLevelCount, :ptr SWORD
  COM_MTD_STD  get_CategoryScale, :ptr ptr IVcCategoryScale
  COM_MTD_STD  get_AxisGrid, :ptr ptr IVcAxisGrid
  COM_MTD_STD  get_Intersection, :ptr ptr IVcIntersection
  COM_MTD_STD  get_Tick, :ptr ptr IVcTick
  COM_MTD_STD  get_AxisScale, :ptr ptr IVcAxisScale
  COM_MTD_STD  get_ValueScale, :ptr ptr IVcValueScale
  COM_MTD_STD  get_AxisTitle, :ptr ptr IVcAxisTitle
  COM_MTD_STD  get_Labels, :ptr ptr IVcLabels
COM_INTERFACE_END


COM_INTERFACE_BEG IVcPlot, IDispatch, <E9E07527-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_AngleUnit, :ptr VtAngleUnits
  COM_MTD_STD  put_AngleUnit, :VtAngleUnits
  COM_MTD_STD  get_Clockwise, :ptr BOOL
  COM_MTD_STD  put_Clockwise, :BOOL
  COM_MTD_STD  get_Sort, :ptr VtSortType
  COM_MTD_STD  put_Sort, :VtSortType
  COM_MTD_STD  get_Backdrop, :ptr ptr IVcBackdrop
  COM_MTD_STD  get_StartingAngle, :ptr REAL4
  COM_MTD_STD  put_StartingAngle, :REAL4
  COM_MTD_STD  get_SubPlotLabelPosition, :ptr VtChSubPlotLabelLocationType
  COM_MTD_STD  put_SubPlotLabelPosition, :VtChSubPlotLabelLocationType
  COM_MTD_STD  get_BarGap, :ptr REAL4
  COM_MTD_STD  put_BarGap, :REAL4
  COM_MTD_STD  get_xGap, :ptr REAL4
  COM_MTD_STD  put_xGap, :REAL4
  COM_MTD_STD  get_AutoLayout, :ptr BOOL
  COM_MTD_STD  put_AutoLayout, :BOOL
  COM_MTD_STD  get_WidthToHeightRatio, :ptr REAL4
  COM_MTD_STD  put_WidthToHeightRatio, :REAL4
  COM_MTD_STD  get_DepthToHeightRatio, :ptr REAL4
  COM_MTD_STD  put_DepthToHeightRatio, :REAL4
  COM_MTD_STD  get_LocationRect, :ptr ptr IVcRect
  COM_MTD_STD  get_Projection, :ptr VtProjectionType
  COM_MTD_STD  put_Projection, :VtProjectionType
  COM_MTD_STD  get_zGap, :ptr REAL4
  COM_MTD_STD  put_zGap, :REAL4
  COM_MTD_STD  get_View3d, :ptr ptr IVcView3d
  COM_MTD_STD  get_PlotBase, :ptr ptr IVcPlotBase
  COM_MTD_STD  get_Weighting, :ptr ptr IVcWeighting
  COM_MTD_STD  get_Wall, :ptr ptr IVcWall
  COM_MTD_STD  get_SeriesCollection, :ptr ptr IVcSeriesCollection
  COM_MTD_STD  get_DataSeriesInRow, :ptr BOOL
  COM_MTD_STD  put_DataSeriesInRow, :BOOL
  COM_MTD_STD  get_Light, :ptr ptr IVcLight
  COM_MTD_STD  get_DefaultPercentBasis, :ptr VtChPercentAxisBasis
  COM_MTD_STD  get_UniformAxis, :ptr BOOL
  COM_MTD_STD  put_UniformAxis, :BOOL
  COM_MTD_STD  get_Axis, :VtChAxisId,:VARIANT,:ptr ptr IVcAxis
COM_INTERFACE_END


COM_INTERFACE_BEG _DMSChart, IDispatch, <3A2B370A-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_STD  get_AutoIncrement, :ptr BOOL
  COM_MTD_STD  put_AutoIncrement, :BOOL
  COM_MTD_STD  get_RandomFill, :ptr BOOL
  COM_MTD_STD  put_RandomFill, :BOOL
  COM_MTD_STD  get_chartType, :ptr VtChChartType
  COM_MTD_STD  put_chartType, :VtChChartType
  COM_MTD_STD  get_Column, :ptr SWORD
  COM_MTD_STD  put_Column, :SWORD
  COM_MTD_STD  get_ColumnCount, :ptr SWORD
  COM_MTD_STD  put_ColumnCount, :SWORD
  COM_MTD_STD  get_ColumnLabel, :ptr BSTR
  COM_MTD_STD  put_ColumnLabel, :BSTR
  COM_MTD_STD  get_ColumnLabelCount, :ptr SWORD
  COM_MTD_STD  put_ColumnLabelCount, :SWORD
  COM_MTD_STD  get_ColumnLabelIndex, :ptr SWORD
  COM_MTD_STD  put_ColumnLabelIndex, :SWORD
  COM_MTD_STD  get_Data, :ptr BSTR
  COM_MTD_STD  put_Data, :BSTR
  COM_MTD_STD  get_FootnoteText, :ptr BSTR
  COM_MTD_STD  put_FootnoteText, :BSTR
  COM_MTD_STD  get_Repaint, :ptr BOOL
  COM_MTD_STD  put_Repaint, :BOOL
  COM_MTD_STD  get_Row, :ptr SWORD
  COM_MTD_STD  put_Row, :SWORD
  COM_MTD_STD  get_RowCount, :ptr SWORD
  COM_MTD_STD  put_RowCount, :SWORD
  COM_MTD_STD  get_RowLabel, :ptr BSTR
  COM_MTD_STD  put_RowLabel, :BSTR
  COM_MTD_STD  get_RowLabelCount, :ptr SWORD
  COM_MTD_STD  put_RowLabelCount, :SWORD
  COM_MTD_STD  get_RowLabelIndex, :ptr SWORD
  COM_MTD_STD  put_RowLabelIndex, :SWORD
  COM_MTD_STD  get_SeriesColumn, :ptr SWORD
  COM_MTD_STD  put_SeriesColumn, :SWORD
  COM_MTD_STD  get_SeriesType, :ptr VtChSeriesType
  COM_MTD_STD  put_SeriesType, :VtChSeriesType
  COM_MTD_STD  get_ShowLegend, :ptr BOOL
  COM_MTD_STD  put_ShowLegend, :BOOL
  COM_MTD_STD  get_DrawMode, :ptr VtChDrawMode
  COM_MTD_STD  put_DrawMode, :VtChDrawMode
  COM_MTD_STD  get_BorderStyle, :ptr VtBorderStyle
  COM_MTD_STD  put_BorderStyle, :VtBorderStyle
  COM_MTD_STD  get_Enabled, :ptr BOOL
  COM_MTD_STD  put_Enabled, :BOOL
  COM_MTD_STD  get_hWnd, :ptr SDWORD
  COM_MTD_STD  get_Title, :ptr ptr IVcTitle
  COM_MTD_STD  get_Footnote, :ptr ptr IVcFootnote
  COM_MTD_STD  get_TitleText, :ptr BSTR
  COM_MTD_STD  put_TitleText, :BSTR
  COM_MTD_STD  get_Stacking, :ptr BOOL
  COM_MTD_STD  put_Stacking, :BOOL
  COM_MTD_STD  get_TextLengthType, :ptr VtTextLengthType
  COM_MTD_STD  put_TextLengthType, :VtTextLengthType
  COM_MTD_STD  get_AllowSelections, :ptr BOOL
  COM_MTD_STD  put_AllowSelections, :BOOL
  COM_MTD_STD  get_AllowSeriesSelection, :ptr BOOL
  COM_MTD_STD  put_AllowSeriesSelection, :BOOL
  COM_MTD_STD  get_AllowDynamicRotation, :ptr BOOL
  COM_MTD_STD  put_AllowDynamicRotation, :BOOL
  COM_MTD_STD  get_ActiveSeriesCount, :ptr SWORD
  COM_MTD_STD  get_Backdrop, :ptr ptr IVcBackdrop
  COM_MTD_STD  get_Legend, :ptr ptr IVcLegend
  COM_MTD_STD  get_DataGrid, :ptr ptr IVcDataGrid
  COM_MTD_STD  get_Plot, :ptr ptr IVcPlot
  COM_MTD_STD  get_AllowDithering, :ptr BOOL
  COM_MTD_STD  put_AllowDithering, :BOOL
  COM_MTD_STD  get_DoSetCursor, :ptr BOOL
  COM_MTD_STD  put_DoSetCursor, :BOOL
  COM_MTD_STD  get_Chart3d, :ptr BOOL
  COM_MTD_STD  get_ChartData, :ptr VARIANT
  COM_MTD_STD  put_ChartData, :VARIANT
  COM_MTD_STD  get_Chart, :ptr SDWORD
  COM_MTD_STD  get_MousePointer, :ptr VtMousePointer
  COM_MTD_STD  put_MousePointer, :VtMousePointer
  COM_MTD_STD  AboutBox
  COM_MTD_STD  Refresh
  COM_MTD_STD  EditPaste
  COM_MTD_STD  EditCopy
  COM_MTD_STD  Layout
  COM_MTD_STD  ToDefaults
  COM_MTD_STD  SelectPart, :SWORD,:SWORD,:SWORD,:SWORD,:SWORD
  COM_MTD_STD  GetSelectedPart, :ptr SWORD,:ptr SWORD,:ptr SWORD,:ptr SWORD,:ptr SWORD
  COM_MTD_STD  TwipsToChartPart, :SDWORD,:SDWORD,:ptr SWORD,:ptr SWORD,:ptr SWORD,:ptr SWORD,:ptr SWORD
  COM_MTD_STD  get_OLEDragMode, :ptr OLEDragConstants
  COM_MTD_STD  put_OLEDragMode, :OLEDragConstants
  COM_MTD_STD  get_OLEDropMode, :ptr OLEDropConstants
  COM_MTD_STD  put_OLEDropMode, :OLEDropConstants
  COM_MTD_STD  OLEDrag
  COM_MTD_STD  get_DataSource, :ptr ptr DataSource
  COM_MTD_STD  putref_DataSource, :ptr DataSource
  COM_MTD_STD  get_DataMember, :POINTER;:ptr DataMember
  COM_MTD_STD  put_DataMember, :DWORD;:DataMember
COM_INTERFACE_END


COM_INTERFACE_BEG _DMSChartEvents, IDispatch, <3A2B370B-BA0A-11D1-B137-0000F8753F5D>
  COM_MTD_DSP  OLEStartDrag, :ptr ptr DataObject,:ptr SDWORD
  COM_MTD_DSP  OLEGiveFeedback, :ptr SDWORD,:ptr BOOL
  COM_MTD_DSP  OLESetData, :ptr ptr DataObject,:ptr SWORD
  COM_MTD_DSP  OLECompleteDrag, :ptr SDWORD
  COM_MTD_DSP  OLEDragOver, :ptr ptr DataObject,:ptr SDWORD,:ptr SWORD,:ptr SWORD,:ptr REAL4,:ptr REAL4,:ptr SWORD
  COM_MTD_DSP  OLEDragDrop, :ptr ptr DataObject,:ptr SDWORD,:ptr SWORD,:ptr SWORD,:ptr REAL4,:ptr REAL4
  COM_MTD_DSP  ChartSelected, :ptr SWORD,:ptr SWORD
  COM_MTD_DSP  TitleSelected, :ptr SWORD,:ptr SWORD
  COM_MTD_DSP  FootnoteSelected, :ptr SWORD,:ptr SWORD
  COM_MTD_DSP  LegendSelected, :ptr SWORD,:ptr SWORD
  COM_MTD_DSP  PlotSelected, :ptr SWORD,:ptr SWORD
  COM_MTD_DSP  AxisSelected, :ptr SWORD,:ptr SWORD,:ptr SWORD,:ptr SWORD
  COM_MTD_DSP  AxisLabelSelected, :ptr SWORD,:ptr SWORD,:ptr SWORD,:ptr SWORD,:ptr SWORD,:ptr SWORD
  COM_MTD_DSP  AxisTitleSelected, :ptr SWORD,:ptr SWORD,:ptr SWORD,:ptr SWORD
  COM_MTD_DSP  PointSelected, :ptr SWORD,:ptr SWORD,:ptr SWORD,:ptr SWORD
  COM_MTD_DSP  PointLabelSelected, :ptr SWORD,:ptr SWORD,:ptr SWORD,:ptr SWORD
  COM_MTD_DSP  SeriesSelected, :ptr SWORD,:ptr SWORD,:ptr SWORD
  COM_MTD_DSP  ChartActivated, :ptr SWORD,:ptr SWORD
  COM_MTD_DSP  TitleActivated, :ptr SWORD,:ptr SWORD
  COM_MTD_DSP  FootnoteActivated, :ptr SWORD,:ptr SWORD
  COM_MTD_DSP  LegendActivated, :ptr SWORD,:ptr SWORD
  COM_MTD_DSP  PlotActivated, :ptr SWORD,:ptr SWORD
  COM_MTD_DSP  AxisActivated, :ptr SWORD,:ptr SWORD,:ptr SWORD,:ptr SWORD
  COM_MTD_DSP  AxisLabelActivated, :ptr SWORD,:ptr SWORD,:ptr SWORD,:ptr SWORD,:ptr SWORD,:ptr SWORD
  COM_MTD_DSP  AxisTitleActivated, :ptr SWORD,:ptr SWORD,:ptr SWORD,:ptr SWORD
  COM_MTD_DSP  PointActivated, :ptr SWORD,:ptr SWORD,:ptr SWORD,:ptr SWORD
  COM_MTD_DSP  PointLabelActivated, :ptr SWORD,:ptr SWORD,:ptr SWORD,:ptr SWORD
  COM_MTD_DSP  SeriesActivated, :ptr SWORD,:ptr SWORD,:ptr SWORD
  COM_MTD_DSP  AxisUpdated, :ptr SWORD,:ptr SWORD,:ptr SWORD
  COM_MTD_DSP  AxisLabelUpdated, :ptr SWORD,:ptr SWORD,:ptr SWORD,:ptr SWORD,:ptr SWORD
  COM_MTD_DSP  AxisTitleUpdated, :ptr SWORD,:ptr SWORD,:ptr SWORD
  COM_MTD_DSP  ChartUpdated, :ptr SWORD
  COM_MTD_DSP  FootnoteUpdated, :ptr SWORD
  COM_MTD_DSP  LegendUpdated, :ptr SWORD
  COM_MTD_DSP  PlotUpdated, :ptr SWORD
  COM_MTD_DSP  PointUpdated, :ptr SWORD,:ptr SWORD,:ptr SWORD
  COM_MTD_DSP  PointLabelUpdated, :ptr SWORD,:ptr SWORD,:ptr SWORD
  COM_MTD_DSP  SeriesUpdated, :ptr SWORD,:ptr SWORD
  COM_MTD_DSP  TitleUpdated, :ptr SWORD
  COM_MTD_DSP  DataUpdated, :ptr SWORD,:ptr SWORD,:ptr SWORD,:ptr SWORD,:ptr SWORD,:ptr SWORD
  COM_MTD_DSP  DonePainting
  COM_MTD_DSP  Click
  COM_MTD_DSP  DblClick
  COM_MTD_DSP  KeyDown, :ptr SWORD,:SWORD
  COM_MTD_DSP  KeyPress, :ptr SWORD
  COM_MTD_DSP  KeyUp, :ptr SWORD,:SWORD
  COM_MTD_DSP  MouseDown, :SWORD,:SWORD,:OLE_XPOS_PIXELS,:OLE_YPOS_PIXELS
  COM_MTD_DSP  MouseMove, :SWORD,:SWORD,:OLE_XPOS_PIXELS,:OLE_YPOS_PIXELS
  COM_MTD_DSP  MouseUp, :SWORD,:SWORD,:OLE_XPOS_PIXELS,:OLE_YPOS_PIXELS
COM_INTERFACE_END


sCLSID_DataObjectFiles  textequ <2334D2B4-713E-11CF-8AE5-00AA00C00905>
sCLSID_PlotBase         textequ <E9E074F5-BA0A-11D1-B137-0000F8753F5D>
sCLSID_Shadow           textequ <E9E074DD-BA0A-11D1-B137-0000F8753F5D>
sCLSID_Weighting        textequ <E9E074FB-BA0A-11D1-B137-0000F8753F5D>
sCLSID_Pen              textequ <E9E074D2-BA0A-11D1-B137-0000F8753F5D>
sCLSID_Wall             textequ <E9E074FD-BA0A-11D1-B137-0000F8753F5D>
sCLSID_Fill             textequ <E9E074DF-BA0A-11D1-B137-0000F8753F5D>
sCLSID_SeriesPosition   textequ <E9E07503-BA0A-11D1-B137-0000F8753F5D>
sCLSID_LCoor            textequ <E9E074CC-BA0A-11D1-B137-0000F8753F5D>
sCLSID_SeriesMarker     textequ <E9E07505-BA0A-11D1-B137-0000F8753F5D>
sCLSID_Frame            textequ <E9E074E1-BA0A-11D1-B137-0000F8753F5D>
sCLSID_StatLine         textequ <E9E07507-BA0A-11D1-B137-0000F8753F5D>
sCLSID_Marker           textequ <E9E074D4-BA0A-11D1-B137-0000F8753F5D>
sCLSID_Label_           textequ <E9E07509-BA0A-11D1-B137-0000F8753F5D>
sCLSID_Backdrop         textequ <E9E074E3-BA0A-11D1-B137-0000F8753F5D>
sCLSID_Labels           textequ <E9E0750B-BA0A-11D1-B137-0000F8753F5D>
sCLSID_DataObject       textequ <2334D2B2-713E-11CF-8AE5-00AA00C00905>
sCLSID_DataPointLabel   textequ <E9E0750D-BA0A-11D1-B137-0000F8753F5D>
sCLSID_Title            textequ <E9E074E5-BA0A-11D1-B137-0000F8753F5D>
sCLSID_DataPoint        textequ <E9E0750F-BA0A-11D1-B137-0000F8753F5D>
sCLSID_TextLayout       textequ <E9E07529-BA0A-11D1-B137-0000F8753F5D>
sCLSID_DataPoints       textequ <E9E07510-BA0A-11D1-B137-0000F8753F5D>
sCLSID_Footnote         textequ <E9E074E7-BA0A-11D1-B137-0000F8753F5D>
sCLSID_Series           textequ <E9E07512-BA0A-11D1-B137-0000F8753F5D>
sCLSID_Rect             textequ <E9E074CE-BA0A-11D1-B137-0000F8753F5D>
sCLSID_SeriesCollection textequ <E9E07514-BA0A-11D1-B137-0000F8753F5D>
sCLSID_Legend           textequ <E9E074E9-BA0A-11D1-B137-0000F8753F5D>
sCLSID_AxisTitle        textequ <E9E07516-BA0A-11D1-B137-0000F8753F5D>
sCLSID_Location         textequ <E9E074D7-BA0A-11D1-B137-0000F8753F5D>
sCLSID_CategoryScale    textequ <E9E07518-BA0A-11D1-B137-0000F8753F5D>
sCLSID_DataGrid         textequ <E9E074EB-BA0A-11D1-B137-0000F8753F5D>
sCLSID_AxisGrid         textequ <E9E0751C-BA0A-11D1-B137-0000F8753F5D>
sCLSID_Coor             textequ <E9E074CA-BA0A-11D1-B137-0000F8753F5D>
sCLSID_Intersection     textequ <E9E0751E-BA0A-11D1-B137-0000F8753F5D>
sCLSID_LightSource      textequ <E9E074ED-BA0A-11D1-B137-0000F8753F5D>
sCLSID_Tick             textequ <E9E07520-BA0A-11D1-B137-0000F8753F5D>
sCLSID_VtFont           textequ <E9E074D9-BA0A-11D1-B137-0000F8753F5D>
sCLSID_AxisScale        textequ <E9E07522-BA0A-11D1-B137-0000F8753F5D>
sCLSID_LightSources     textequ <E9E074EF-BA0A-11D1-B137-0000F8753F5D>
sCLSID_ValueScale       textequ <E9E07524-BA0A-11D1-B137-0000F8753F5D>
sCLSID_VtColor          textequ <E9E074D0-BA0A-11D1-B137-0000F8753F5D>
sCLSID_Axis             textequ <E9E07526-BA0A-11D1-B137-0000F8753F5D>
sCLSID_Light            textequ <E9E074F1-BA0A-11D1-B137-0000F8753F5D>
sCLSID_Plot             textequ <E9E07528-BA0A-11D1-B137-0000F8753F5D>
sCLSID_Brush            textequ <E9E074DB-BA0A-11D1-B137-0000F8753F5D>
sCLSID_View3d           textequ <E9E074F3-BA0A-11D1-B137-0000F8753F5D>
sCLSID_MSChart          textequ <3A2B370C-BA0A-11D1-B137-0000F8753F5D>