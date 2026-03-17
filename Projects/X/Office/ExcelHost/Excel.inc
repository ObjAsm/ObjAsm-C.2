; ==================================================================================================
; Title:      Excel.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    Excel interface for ObjAsm.
; Notes:      Version C.1.0, October 2017
;               - Initial release. Generated using COMView (www.japheth.de) and edited manually.
;               - Prototypes too complex for MASM may exist. If such ones reside in a vtable they
;                 were replaced by dummies. Search for occurances of ';+++' to have a closer look
;                 at these.
;               - In some COM_MTD_STD of Dual Interfaces appears a SDWORD. It is a LCID.
; ==================================================================================================


sTLBID_Excel    textequ <00020813-0000-0000-C000-000000000046>
_MajorVer_Excel equ 1
_MinorVer_Excel equ 4

MsoTriState                 typedef SDWORD
MsoGradientStyle            typedef SDWORD
MsoPatternType              typedef SDWORD
MsoPresetGradientType       typedef SDWORD
MsoPresetTexture            typedef SDWORD
MsoOrgChartLayoutType       typedef SDWORD
MsoCalloutAngleType         typedef SDWORD
MsoCalloutType              typedef SDWORD
MsoRGBType                  typedef SDWORD
MsoArrowheadLength          typedef SDWORD
MsoArrowheadStyle           typedef SDWORD
MsoArrowheadWidth           typedef SDWORD
MsoLineDashStyle            typedef SDWORD
MsoArrowheadLength          typedef SDWORD
MsoArrowheadStyle           typedef SDWORD
MsoArrowheadWidth           typedef SDWORD
MsoLineStyle                typedef SDWORD
MsoSegmentType              typedef SDWORD
MsoEditingType              typedef SDWORD
MsoEditingType              typedef SDWORD
MsoSegmentType              typedef SDWORD
MsoPictureColorType         typedef SDWORD
MsoRGBType                  typedef SDWORD
MsoShadowType               typedef SDWORD
MsoTextEffectAlignment      typedef SDWORD
MsoPresetTextEffectShape    typedef SDWORD
MsoPresetTextEffect         typedef SDWORD
MsoExtrusionColorType       typedef SDWORD
MsoPresetLightingDirection  typedef SDWORD
MsoPresetLightingSoftness   typedef SDWORD
MsoPresetMaterial           typedef SDWORD
MsoAutoShapeType            typedef SDWORD
MsoBlackWhiteMode           typedef SDWORD
MsoAutoShapeType            typedef SDWORD
MsoAutoShapeType            typedef SDWORD
MsoBlackWhiteMode           typedef SDWORD
MsoTextOrientation          typedef SDWORD
MsoConnectorType            typedef SDWORD
MsoScreenSize               typedef SDWORD
MsoEncoding                 typedef SDWORD
MsoTargetBrowser            typedef SDWORD
MsoScreenSize               typedef SDWORD
MsoEncoding                 typedef SDWORD
MsoTargetBrowser            typedef SDWORD
MsoDiagramType              typedef SDWORD
MsoFlipCmd                  typedef SDWORD
MsoZOrderCmd                typedef SDWORD
MsoAlignCmd                 typedef SDWORD
MsoDistributeCmd            typedef SDWORD
MsoFeatureInstall           typedef SDWORD
MsoAutomationSecurity       typedef SDWORD


Constants typedef SDWORD
xlAll                   equ      -4104           ;=0FFFFEFF8h
xlAutomatic             equ      -4105           ;=0FFFFEFF7h
xlBoth                  equ      1
xlCenter                equ      -4108           ;=0FFFFEFF4h
xlChecker               equ     9
xlCircle                equ     8
xlCorner                equ     2
xlCrissCross            equ     16               ;=010h
xlCross                 equ     4
xlDiamond               equ     2
xlDistributed           equ     -4117            ;=0FFFFEFEBh
xlDoubleAccounting      equ     5
xlFixedValue            equ     1
xlFormats               equ     -4122            ;=0FFFFEFE6h
xlGray16                equ     17               ;=011h
xlGray8                 equ     18               ;=012h
xlGrid                  equ     15
xlHigh                  equ     -4127            ;=0FFFFEFE1h
xlInside                equ     2
xlJustify               equ     -4130            ;=0FFFFEFDEh
xlLightDown             equ     13
xlLightHorizontal       equ     11
xlLightUp               equ     14
xlLightVertical         equ     12
xlLow                   equ     -4134            ;=0FFFFEFDAh
xlManual                equ     -4135            ;=0FFFFEFD9h
xlMinusValues           equ     3
xlModule                equ     -4141            ;=0FFFFEFD3h
xlNextToAxis            equ     4
xlNone                  equ     -4142            ;=0FFFFEFD2h
xlNotes                 equ     -4144            ;=0FFFFEFD0h
xlOff                   equ     -4146            ;=0FFFFEFCEh
xlOn                    equ     1
xlPercent               equ     2
xlPlus                  equ     9
xlPlusValues            equ     2
xlSemiGray75            equ     10
xlShowLabel             equ     4
xlShowLabelAndPercent   equ     5
xlShowPercent           equ     3
xlShowValue             equ     2
xlSimple                equ     -4154            ;=0FFFFEFC6h
xlSingle                equ     2
xlSingleAccounting      equ     4
xlSolid                 equ     1
xlSquare                equ     1
xlStar                  equ     5
xlStError               equ     4
xlToolbarButton         equ     2
xlTriangle              equ     3
xlGray25                equ     -4124            ;=0FFFFEFE4h
xlGray50                equ     -4125            ;=0FFFFEFE3h
xlGray75                equ     -4126            ;=0FFFFEFE2h
xlBottom                equ     -4107            ;=0FFFFEFF5h
xlLeft                  equ     -4131            ;=0FFFFEFDDh
xlRight                 equ     -4152            ;=0FFFFEFC8h
xlTop                   equ     -4160            ;=0FFFFEFC0h
xl3DBar                 equ     -4099            ;=0FFFFEFFDh
xl3DSurface             equ     -4103            ;=0FFFFEFF9h
xlBar                   equ     2
xlColumn                equ     3
xlCombination           equ     -4111            ;=0FFFFEFF1h
xlCustom                equ     -4114            ;=0FFFFEFEEh
xlDefaultAutoFormat     equ     -1
xlMaximum               equ     2
xlMinimum               equ     4
xlOpaque                equ     3
xlTransparent           equ     2
xlBidi                  equ     -5000            ;=0FFFFEC78h
xlLatin                 equ     -5001            ;=0FFFFEC77h
xlContext               equ     -5002            ;=0FFFFEC76h
xlLTR                   equ     -5003            ;=0FFFFEC75h
xlRTL                   equ     -5004            ;=0FFFFEC74h
xlFullScript            equ     1
xlPartialScript         equ     2
xlMixedScript           equ     3
xlMixedAuthorizedScript equ     4
xlVisualCursor          equ     2
xlLogicalCursor         equ     1
xlSystem                equ     1
xlPartial               equ     3
xlHindiNumerals         equ     3
xlBidiCalendar          equ     3
xlGregorian             equ     2
xlComplete              equ     4
xlScale                 equ     3
xlClosed                equ     3
xlColor1                equ     7
xlColor2                equ     8
xlColor3                equ     9
xlConstants             equ     2
xlContents              equ     2
xlBelow                 equ     1
xlCascade               equ     7
xlCenterAcrossSelection equ     7
xlChart4                equ     2
xlChartSeries           equ     17               ;=011h
xlChartShort            equ     6
xlChartTitles           equ     18               ;=012h
xlClassic1              equ     1
xlClassic2              equ     2
xlClassic3              equ     3
xl3DEffects1            equ     13
xl3DEffects2            equ     14
xlAbove                 equ     0
xlAccounting1           equ     4
xlAccounting2           equ     5
xlAccounting3           equ     6
xlAccounting4           equ     17               ;=011h
xlAdd                   equ     2
xlDebugCodePane         equ     13
xlDesktop               equ     9
xlDirect                equ     1
xlDivide                equ     5
xlDoubleClosed          equ     5
xlDoubleOpen            equ     4
xlDoubleQuote           equ     1
xlEntireChart           equ     20               ;=014h
xlExcelMenus            equ     1
xlExtended              equ     3
xlFill                  equ     5
xlFirst                 equ     0
xlFloating              equ     5
xlFormula               equ     5
xlGeneral               equ     1
xlGridline              equ     22               ;=016h
xlIcons                 equ     1
xlImmediatePane         equ     12
xlInteger               equ     2
xlLast                  equ     1
xlLastCell              equ     11
xlList1                 equ     10
xlList2                 equ     11
xlList3                 equ     12
xlLocalFormat1          equ     15
xlLocalFormat2          equ     16               ;=010h
xlLong                  equ     3
xlLotusHelp             equ     2
xlMacrosheetCell        equ     7
xlMixed                 equ     2
xlMultiply              equ     4
xlNarrow                equ     1
xlNoDocuments           equ     3
xlOpen                  equ     2
xlOutside               equ     3
xlReference             equ     4
xlSemiautomatic         equ     2
xlShort                 equ     1
xlSingleQuote           equ     2
xlStrict                equ     2
xlSubtract              equ     3
xlTextBox               equ     16               ;=010h
xlTiled                 equ     1
xlTitleBar              equ     8
xlToolbar               equ     1
xlVisible               equ     12
xlWatchPane             equ     11
xlWide                  equ     3
xlWorkbookTab           equ     6
xlWorksheet4            equ     1
xlWorksheetCell         equ     3
xlWorksheetShort        equ     5
xlAllExceptBorders      equ     7
xlLeftToRight           equ     2
xlTopToBottom           equ     1
xlVeryHidden            equ     2
xlDrawingObject         equ     14


XlCreator typedef SDWORD
xlCreatorCode           equ     1480803660       ;=05843454Ch


XlChartGallery typedef SDWORD
xlBuiltIn               equ     21               ;=015h
xlUserDefined           equ     22               ;=016h
xlAnyGallery            equ     23               ;=017h


XlColorIndex typedef SDWORD
xlColorIndexAutomatic   equ     -4105            ;=0FFFFEFF7h
xlColorIndexNone        equ     -4142            ;=0FFFFEFD2h


XlEndStyleCap typedef SDWORD
xlCap                   equ     1
xlNoCap                 equ     2


XlRowCol typedef SDWORD
xlColumns               equ     2
xlRows                  equ     1


XlScaleType typedef SDWORD
xlScaleLinear           equ     -4132            ;=0FFFFEFDCh
xlScaleLogarithmic      equ     -4133            ;=0FFFFEFDBh


XlDataSeriesType typedef SDWORD
xlAutoFill              equ     4
xlChronological         equ     3
xlGrowth                equ     2
xlDataSeriesLinear      equ     -4132            ;=0FFFFEFDCh


XlAxisCrosses typedef SDWORD
xlAxisCrossesAutomatic  equ     -4105            ;=0FFFFEFF7h
xlAxisCrossesCustom     equ     -4114            ;=0FFFFEFEEh
xlAxisCrossesMaximum    equ     2
xlAxisCrossesMinimum    equ     4


XlAxisGroup typedef SDWORD
xlPrimary               equ     1
xlSecondary             equ     2


XlBackground typedef SDWORD
xlBackgroundAutomatic   equ     -4105            ;=0FFFFEFF7h
xlBackgroundOpaque      equ     3
xlBackgroundTransparent equ     2


XlWindowState typedef SDWORD
xlMaximized             equ     -4137            ;=0FFFFEFD7h
xlMinimized             equ     -4140            ;=0FFFFEFD4h
xlNormal                equ     -4143            ;=0FFFFEFD1h


XlAxisType typedef SDWORD
xlCategory              equ     1                ;X-Axis
xlSeriesAxis            equ     3
xlValue                 equ     2                ;Y-Axis


XlArrowHeadLength typedef SDWORD
xlArrowHeadLengthLong   equ     3
xlArrowHeadLengthMedium equ     -4138            ;=0FFFFEFD6h
xlArrowHeadLengthShort  equ     1


XlVAlign typedef SDWORD
xlVAlignBottom          equ     -4107            ;=0FFFFEFF5h
xlVAlignCenter          equ     -4108            ;=0FFFFEFF4h
xlVAlignDistributed     equ     -4117            ;=0FFFFEFEBh
xlVAlignJustify         equ     -4130            ;=0FFFFEFDEh
xlVAlignTop             equ     -4160            ;=0FFFFEFC0h


XlTickMark typedef SDWORD
xlTickMarkCross         equ     4
xlTickMarkInside        equ     2
xlTickMarkNone          equ     -4142            ;=0FFFFEFD2h
xlTickMarkOutside       equ     3


XlErrorBarDirection typedef SDWORD
xlX                     equ     -4168            ;=0FFFFEFB8h
xlY                     equ     1


XlErrorBarInclude typedef SDWORD
xlErrorBarIncludeBoth   equ     1
xlErrorBarIncludeMinusValues  equ     3
xlErrorBarIncludeNone   equ     -4142            ;=0FFFFEFD2h
xlErrorBarIncludePlusValues   equ     2


XlDisplayBlanksAs typedef SDWORD
xlInterpolated          equ     3
xlNotPlotted            equ     1
xlZero                  equ     2


XlArrowHeadStyle typedef SDWORD
xlArrowHeadStyleClosed  equ     3
xlArrowHeadStyleDoubleClosed  equ     5
xlArrowHeadStyleDoubleOpen    equ     4
xlArrowHeadStyleNone    equ     -4142            ;=0FFFFEFD2h
xlArrowHeadStyleOpen    equ     2


XlArrowHeadWidth typedef SDWORD
xlArrowHeadWidthMedium  equ     -4138            ;=0FFFFEFD6h
xlArrowHeadWidthNarrow  equ     1
xlArrowHeadWidthWide    equ     3


XlHAlign typedef SDWORD
xlHAlignCenter          equ     -4108            ;=0FFFFEFF4h
xlHAlignCenterAcrossSelection equ     7
xlHAlignDistributed     equ     -4117            ;=0FFFFEFEBh
xlHAlignFill            equ     5
xlHAlignGeneral         equ     1
xlHAlignJustify         equ     -4130            ;=0FFFFEFDEh
xlHAlignLeft            equ     -4131            ;=0FFFFEFDDh
xlHAlignRight           equ     -4152            ;=0FFFFEFC8h


XlTickLabelPosition typedef SDWORD
xlTickLabelPositionHigh equ     -4127            ;=0FFFFEFE1h
xlTickLabelPositionLow  equ     -4134            ;=0FFFFEFDAh
xlTickLabelPositionNextToAxis equ     4
xlTickLabelPositionNone equ     -4142            ;=0FFFFEFD2h


XlLegendPosition typedef SDWORD
xlLegendPositionBottom  equ     -4107            ;=0FFFFEFF5h
xlLegendPositionCorner  equ     2
xlLegendPositionLeft    equ     -4131            ;=0FFFFEFDDh
xlLegendPositionRight   equ     -4152            ;=0FFFFEFC8h
xlLegendPositionTop     equ     -4160            ;=0FFFFEFC0h


XlChartPictureType typedef SDWORD
xlStackScale            equ     3
xlStack                 equ     2
xlStretch               equ     1


XlChartPicturePlacement typedef SDWORD
xlSides                 equ     1
xlEnd                   equ     2
xlEndSides              equ     3
xlFront                 equ     4
xlFrontSides            equ     5
xlFrontEnd              equ     6
xlAllFaces              equ     7


XlOrientation typedef SDWORD
xlDownward              equ     -4170            ;=0FFFFEFB6h
xlHorizontal            equ     -4128            ;=0FFFFEFE0h
xlUpward                equ     -4171            ;=0FFFFEFB5h
xlVertical              equ     -4166            ;=0FFFFEFBAh


XlTickLabelOrientation typedef SDWORD
xlTickLabelOrientationAutomatic   equ     -4105  ;=0FFFFEFF7h
xlTickLabelOrientationDownward    equ     -4170  ;=0FFFFEFB6h
xlTickLabelOrientationHorizontal  equ     -4128  ;=0FFFFEFE0h
xlTickLabelOrientationUpward      equ     -4171  ;=0FFFFEFB5h
xlTickLabelOrientationVertical    equ     -4166  ;=0FFFFEFBAh


XlBorderWeight typedef SDWORD
xlHairline              equ     1
xlMedium                equ     -4138            ;=0FFFFEFD6h
xlThick                 equ     4
xlThin                  equ     2


XlDataSeriesDate typedef SDWORD
xlDay                   equ     1
xlMonth                 equ     3
xlWeekday               equ     2
xlYear                  equ     4


XlUnderlineStyle typedef SDWORD
xlUnderlineStyleDouble            equ     -4119  ;=0FFFFEFE9h
xlUnderlineStyleDoubleAccounting  equ     5
xlUnderlineStyleNone              equ     -4142  ;=0FFFFEFD2h
xlUnderlineStyleSingle            equ     2
xlUnderlineStyleSingleAccounting  equ     4


XlErrorBarType typedef SDWORD
xlErrorBarTypeCustom      equ     -4114          ;=0FFFFEFEEh
xlErrorBarTypeFixedValue  equ     1
xlErrorBarTypePercent     equ     2
xlErrorBarTypeStDev       equ     -4155          ;=0FFFFEFC5h
xlErrorBarTypeStError     equ     4


XlTrendlineType typedef SDWORD
xlExponential           equ     5
xlLinear                equ     -4132            ;=0FFFFEFDCh
xlLogarithmic           equ     -4133            ;=0FFFFEFDBh
xlMovingAvg             equ     6
xlPolynomial            equ     3
xlPower                 equ     4


XlLineStyle typedef SDWORD
xlContinuous            equ     1
xlDash                  equ     -4115            ;=0FFFFEFEDh
xlDashDot               equ     4
xlDashDotDot            equ     5
xlDot                   equ     -4118            ;=0FFFFEFEAh
xlDouble                equ     -4119            ;=0FFFFEFE9h
xlSlantDashDot          equ     13
xlLineStyleNone         equ     -4142            ;=0FFFFEFD2h


XlDataLabelsType typedef SDWORD
xlDataLabelsShowNone    equ     -4142            ;=0FFFFEFD2h
xlDataLabelsShowValue   equ     2
xlDataLabelsShowPercent equ     3
xlDataLabelsShowLabel   equ     4
xlDataLabelsShowLabelAndPercent equ     5
xlDataLabelsShowBubbleSizes     equ     6


XlMarkerStyle typedef SDWORD
xlMarkerStyleAutomatic  equ     -4105            ;=0FFFFEFF7h
xlMarkerStyleCircle     equ     8
xlMarkerStyleDash       equ     -4115            ;=0FFFFEFEDh
xlMarkerStyleDiamond    equ     2
xlMarkerStyleDot        equ     -4118            ;=0FFFFEFEAh
xlMarkerStyleNone       equ     -4142            ;=0FFFFEFD2h
xlMarkerStylePicture    equ     -4147            ;=0FFFFEFCDh
xlMarkerStylePlus       equ     9
xlMarkerStyleSquare     equ     1
xlMarkerStyleStar       equ     5
xlMarkerStyleTriangle   equ     3
xlMarkerStyleX          equ     -4168            ;=0FFFFEFB8h


XlPictureConvertorType typedef SDWORD
xlBMP                   equ     1
xlCGM                   equ     7
xlDRW                   equ     4
xlDXF                   equ     5
xlEPS                   equ     8
xlHGL                   equ     6
xlPCT                   equ     13
xlPCX                   equ     10
xlPIC                   equ     11
xlPLT                   equ     12
xlTIF                   equ     9
xlWMF                   equ     2
xlWPG                   equ     3


XlPattern typedef SDWORD
xlPatternAutomatic      equ     -4105            ;=0FFFFEFF7h
xlPatternChecker        equ     9
xlPatternCrissCross     equ     16               ;=010h
xlPatternDown           equ     -4121            ;=0FFFFEFE7h
xlPatternGray16         equ     17               ;=011h
xlPatternGray25         equ     -4124            ;=0FFFFEFE4h
xlPatternGray50         equ     -4125            ;=0FFFFEFE3h
xlPatternGray75         equ     -4126            ;=0FFFFEFE2h
xlPatternGray8          equ     18               ;=012h
xlPatternGrid           equ     15
xlPatternHorizontal     equ     -4128            ;=0FFFFEFE0h
xlPatternLightDown      equ     13
xlPatternLightHorizontal  equ     11
xlPatternLightUp        equ     14
xlPatternLightVertical  equ     12
xlPatternNone           equ     -4142            ;=0FFFFEFD2h
xlPatternSemiGray75     equ     10
xlPatternSolid          equ     1
xlPatternUp             equ     -4162            ;=0FFFFEFBEh
xlPatternVertical       equ     -4166            ;=0FFFFEFBAh


XlChartSplitType typedef SDWORD
xlSplitByPosition       equ     1
xlSplitByPercentValue   equ     3
xlSplitByCustomSplit    equ     4
xlSplitByValue          equ     2


XlDisplayUnit typedef SDWORD
xlHundreds              equ     -2               ;=0FFFFFFFEh
xlThousands             equ     -3               ;=0FFFFFFFDh
xlTenThousands          equ     -4               ;=0FFFFFFFCh
xlHundredThousands      equ     -5               ;=0FFFFFFFBh
xlMillions              equ     -6               ;=0FFFFFFFAh
xlTenMillions           equ     -7               ;=0FFFFFFF9h
xlHundredMillions       equ     -8               ;=0FFFFFFF8h
xlThousandMillions      equ     -9               ;=0FFFFFFF7h
xlMillionMillions       equ     -10              ;=0FFFFFFF6h


XlDataLabelPosition typedef SDWORD
xlLabelPositionCenter   equ     -4108            ;=0FFFFEFF4h
xlLabelPositionAbove    equ     0
xlLabelPositionBelow    equ     1
xlLabelPositionLeft     equ     -4131            ;=0FFFFEFDDh
xlLabelPositionRight    equ     -4152            ;=0FFFFEFC8h
xlLabelPositionOutsideEnd equ   2
xlLabelPositionInsideEnd  equ   3
xlLabelPositionInsideBase equ   4
xlLabelPositionBestFit  equ     5
xlLabelPositionMixed    equ     6
xlLabelPositionCustom   equ     7


XlTimeUnit typedef SDWORD
xlDays                  equ     0
xlMonths                equ     1
xlYears                 equ     2


XlCategoryType typedef SDWORD
xlCategoryScale         equ     2
xlTimeScale             equ     3
xlAutomaticScale        equ     -4105            ;=0FFFFEFF7h


XlBarShape typedef SDWORD
xlBox                   equ     0
xlPyramidToPoint        equ     1
xlPyramidToMax          equ     2
xlCylinder              equ     3
xlConeToPoint           equ     4
xlConeToMax             equ     5


XlChartType typedef SDWORD
xlColumnClustered       equ     51               ;=033h
xlColumnStacked         equ     52               ;=034h
xlColumnStacked100      equ     53               ;=035h
xl3DColumnClustered     equ     54               ;=036h
xl3DColumnStacked       equ     55               ;=037h
xl3DColumnStacked100    equ     56               ;=038h
xlBarClustered          equ     57               ;=039h
xlBarStacked            equ     58               ;=03Ah
xlBarStacked100         equ     59               ;=03Bh
xl3DBarClustered        equ     60               ;=03Ch
xl3DBarStacked          equ     61               ;=03Dh
xl3DBarStacked100       equ     62               ;=03Eh
xlLineStacked           equ     63               ;=03Fh
xlLineStacked100        equ     64               ;=040h
xlLineMarkers           equ     65               ;=041h
xlLineMarkersStacked    equ     66               ;=042h
xlLineMarkersStacked100 equ     67               ;=043h
xlPieOfPie              equ     68               ;=044h
xlPieExploded           equ     69               ;=045h
xl3DPieExploded         equ     70               ;=046h
xlBarOfPie              equ     71               ;=047h
xlXYScatterSmooth       equ     72               ;=048h
xlXYScatterSmoothNoMarkers  equ 73               ;=049h
xlXYScatterLines        equ     74               ;=04Ah
xlXYScatterLinesNoMarkers   equ 75               ;=04Bh
xlAreaStacked           equ     76               ;=04Ch
xlAreaStacked100        equ     77               ;=04Dh
xl3DAreaStacked         equ     78               ;=04Eh
xl3DAreaStacked100      equ     79               ;=04Fh
xlDoughnutExploded      equ     80               ;=050h
xlRadarMarkers          equ     81               ;=051h
xlRadarFilled           equ     82               ;=052h
xlSurface               equ     83               ;=053h
xlSurfaceWireframe      equ     84               ;=054h
xlSurfaceTopView        equ     85               ;=055h
xlSurfaceTopViewWireframe equ   86               ;=056h
xlBubble                equ     15
xlBubble3DEffect        equ     87               ;=057h
xlStockHLC              equ     88               ;=058h
xlStockOHLC             equ     89               ;=059h
xlStockVHLC             equ     90               ;=05Ah
xlStockVOHLC            equ     91               ;=05Bh
xlCylinderColClustered  equ     92               ;=05Ch
xlCylinderColStacked    equ     93               ;=05Dh
xlCylinderColStacked100 equ     94               ;=05Eh
xlCylinderBarClustered  equ     95               ;=05Fh
xlCylinderBarStacked    equ     96               ;=060h
xlCylinderBarStacked100 equ     97               ;=061h
xlCylinderCol           equ     98               ;=062h
xlConeColClustered      equ     99               ;=063h
xlConeColStacked        equ     100              ;=064h
xlConeColStacked100     equ     101              ;=065h
xlConeBarClustered      equ     102              ;=066h
xlConeBarStacked        equ     103              ;=067h
xlConeBarStacked100     equ     104              ;=068h
xlConeCol               equ     105              ;=069h
xlPyramidColClustered   equ     106              ;=06Ah
xlPyramidColStacked     equ     107              ;=06Bh
xlPyramidColStacked100  equ     108              ;=06Ch
xlPyramidBarClustered   equ     109              ;=06Dh
xlPyramidBarStacked     equ     110              ;=06Eh
xlPyramidBarStacked100  equ     111              ;=06Fh
xlPyramidCol            equ     112              ;=070h
xl3DColumn              equ     -4100            ;=0FFFFEFFCh
xlLine                  equ     4
xl3DLine                equ     -4101            ;=0FFFFEFFBh
xl3DPie                 equ     -4102            ;=0FFFFEFFAh
xlPie                   equ     5
xlXYScatter             equ     -4169            ;=0FFFFEFB7h
xl3DArea                equ     -4098            ;=0FFFFEFFEh
xlArea                  equ     1
xlDoughnut              equ     -4120            ;=0FFFFEFE8h
xlRadar                 equ     -4151            ;=0FFFFEFC9h


XlChartItem typedef SDWORD
xlDataLabel             equ     0
xlChartArea             equ     2
xlSeries                equ     3
xlChartTitle            equ     4
xlWalls                 equ     5
xlCorners               equ     6
xlDataTable             equ     7
xlTrendline             equ     8
xlErrorBars             equ     9
xlXErrorBars            equ     10
xlYErrorBars            equ     11
xlLegendEntry           equ     12
xlLegendKey             equ     13
xlShape                 equ     14
xlMajorGridlines        equ     15
xlMinorGridlines        equ     16               ;=010h
xlAxisTitle             equ     17               ;=011h
xlUpBars                equ     18               ;=012h
xlPlotArea              equ     19               ;=013h
xlDownBars              equ     20               ;=014h
xlAxis                  equ     21               ;=015h
xlSeriesLines           equ     22               ;=016h
xlFloor                 equ     23               ;=017h
xlLegend                equ     24               ;=018h
xlHiLoLines             equ     25               ;=019h
xlDropLines             equ     26               ;=01Ah
xlRadarAxisLabels       equ     27               ;=01Bh
xlNothing               equ     28               ;=01Ch
xlLeaderLines           equ     29               ;=01Dh
xlDisplayUnitLabel      equ     30               ;=01Eh
xlPivotChartFieldButton equ     31               ;=01Fh
xlPivotChartDropZone    equ     32               ;=020h


XlSizeRepresents typedef SDWORD
xlSizeIsWidth           equ     2
xlSizeIsArea            equ     1


XlInsertShiftDirection typedef SDWORD
xlShiftDown             equ     -4121               ;=0FFFFEFE7h
xlShiftToRight          equ     -4161               ;=0FFFFEFBFh


XlDeleteShiftDirection typedef SDWORD
xlShiftToLeft           equ     -4159               ;=0FFFFEFC1h
xlShiftUp               equ     -4162               ;=0FFFFEFBEh


XlDirection typedef SDWORD
xlDown                  equ     -4121               ;=0FFFFEFE7h
xlToLeft                equ     -4159               ;=0FFFFEFC1h
xlToRight               equ     -4161               ;=0FFFFEFBFh
xlUp                    equ     -4162               ;=0FFFFEFBEh


XlConsolidationFunction typedef SDWORD
xlAverage               equ     -4106               ;=0FFFFEFF6h
xlCount                 equ     -4112               ;=0FFFFEFF0h
xlCountNums             equ     -4113               ;=0FFFFEFEFh
xlMax                   equ     -4136               ;=0FFFFEFD8h
xlMin                   equ     -4139               ;=0FFFFEFD5h
xlProduct               equ     -4149               ;=0FFFFEFCBh
xlStDev                 equ     -4155               ;=0FFFFEFC5h
xlStDevP                equ     -4156               ;=0FFFFEFC4h
xlSum                   equ     -4157               ;=0FFFFEFC3h
xlVar                   equ     -4164               ;=0FFFFEFBCh
xlVarP                  equ     -4165               ;=0FFFFEFBBh
xlUnknown               equ     1000                ;=03E8h


XlSheetType typedef SDWORD
xlChart                 equ     -4109               ;=0FFFFEFF3h
xlDialogSheet           equ     -4116               ;=0FFFFEFECh
xlExcel4IntlMacroSheet  equ     4
xlExcel4MacroSheet      equ     3
xlWorksheet             equ     -4167               ;=0FFFFEFB9h


XlLocationInTable typedef SDWORD
xlColumnHeader          equ     -4110               ;=0FFFFEFF2h
xlColumnItem            equ     5
xlDataHeader            equ     3
xlDataItem              equ     7
xlPageHeader            equ     2
xlPageItem              equ     6
xlRowHeader             equ     -4153               ;=0FFFFEFC7h
xlRowItem               equ     4
xlTableBody             equ     8


XlFindLookIn typedef SDWORD
xlFormulas              equ     -4123               ;=0FFFFEFE5h
xlComments              equ     -4144               ;=0FFFFEFD0h
xlValues                equ     -4163               ;=0FFFFEFBDh


XlWindowType typedef SDWORD
xlChartAsWindow         equ     5
xlChartInPlace          equ     4
xlClipboard             equ     3
xlInfo                  equ     -4129               ;=0FFFFEFDFh
xlWorkbook              equ     1


XlPivotFieldDataType typedef SDWORD
xlDate                  equ     2
xlNumber                equ     -4145               ;=0FFFFEFCFh
xlText                  equ     -4158               ;=0FFFFEFC2h


XlCopyPictureFormat typedef SDWORD
xlBitmap                equ     2
xlPicture               equ     -4147               ;=0FFFFEFCDh


XlPivotTableSourceType typedef SDWORD
xlScenario              equ     4
xlConsolidation         equ     3
xlDatabase              equ     1
xlExternal              equ     2
xlPivotTable            equ     -4148               ;=0FFFFEFCCh


XlReferenceStyle typedef SDWORD
xlA1                    equ     1
xlR1C1                  equ     -4150               ;=0FFFFEFCAh


XlMSApplication typedef SDWORD
xlMicrosoftAccess       equ     4
xlMicrosoftFoxPro       equ     5
xlMicrosoftMail         equ     3
xlMicrosoftPowerPoint   equ     2
xlMicrosoftProject      equ     6
xlMicrosoftSchedulePlus equ     7
xlMicrosoftWord         equ     1


XlMouseButton typedef SDWORD
xlNoButton              equ     0
xlPrimaryButton         equ     1
xlSecondaryButton       equ     2


XlCutCopyMode typedef SDWORD
xlCopy                  equ     1
xlCut                   equ     2


XlFillWith typedef SDWORD
xlFillWithAll           equ     -4104               ;=0FFFFEFF8h
xlFillWithContents      equ     2
xlFillWithFormats       equ     -4122               ;=0FFFFEFE6h


XlFilterAction typedef SDWORD
xlFilterCopy            equ     2
xlFilterInPlace         equ     1


XlOrder typedef SDWORD
xlDownThenOver          equ     1
xlOverThenDown          equ     2


XlLinkType typedef SDWORD
xlLinkTypeExcelLinks    equ     1
xlLinkTypeOLELinks      equ     2


XlApplyNamesOrder typedef SDWORD
xlColumnThenRow         equ     2
xlRowThenColumn         equ     1


XlEnableCancelKey typedef SDWORD
xlDisabled              equ     0
xlErrorHandler          equ     2
xlInterrupt             equ     1


XlPageBreak typedef SDWORD
xlPageBreakAutomatic    equ     -4105               ;=0FFFFEFF7h
xlPageBreakManual       equ     -4135               ;=0FFFFEFD9h
xlPageBreakNone         equ     -4142               ;=0FFFFEFD2h


XlOLEType typedef SDWORD
xlOLEControl            equ     2
xlOLEEmbed              equ     1
xlOLELink               equ     0


XlPageOrientation typedef SDWORD
xlLandscape             equ     2
xlPortrait              equ     1


XlLinkInfo typedef SDWORD
xlEditionDate           equ     2
xlUpdateState           equ     1
xlLinkInfoStatus        equ     3


XlCommandUnderlines typedef SDWORD
xlCommandUnderlinesAutomatic  equ -4105             ;=0FFFFEFF7h
xlCommandUnderlinesOff  equ     -4146               ;=0FFFFEFCEh
xlCommandUnderlinesOn   equ     1


XlOLEVerb typedef SDWORD
xlVerbOpen              equ     2
xlVerbPrimary           equ     1


XlCalculation typedef SDWORD
xlCalculationAutomatic  equ     -4105               ;=0FFFFEFF7h
xlCalculationManual     equ     -4135               ;=0FFFFEFD9h
xlCalculationSemiautomatic  equ 2


XlFileAccess typedef SDWORD
xlReadOnly              equ     3
xlReadWrite             equ     2


XlEditionType typedef SDWORD
xlPublisher             equ     1
xlSubscriber            equ     2


XlObjectSize typedef SDWORD
xlFitToPage             equ     2
xlFullPage              equ     3
xlScreenSize            equ     1


XlLookAt typedef SDWORD
xlPart                  equ     2
xlWhole                 equ     1


XlMailSystem typedef SDWORD
xlMAPI                  equ     1
xlNoMailSystem          equ     0
xlPowerTalk             equ     2


XlLinkInfoType typedef SDWORD
xlLinkInfoOLELinks      equ     2
xlLinkInfoPublishers    equ     5
xlLinkInfoSubscribers   equ     6


XlCVError typedef SDWORD
xlErrDiv0               equ     2007               ;=07D7h
xlErrNA                 equ     2042               ;=07FAh
xlErrName               equ     2029               ;=07EDh
xlErrNull               equ     2000               ;=07D0h
xlErrNum                equ     2036               ;=07F4h
xlErrRef                equ     2023               ;=07E7h
xlErrValue              equ     2015               ;=07DFh


XlEditionFormat typedef SDWORD
xlBIFF                  equ     2
xlPICT                  equ     1
xlRTF                   equ     4
xlVALU                  equ     8


XlLink typedef SDWORD
xlExcelLinks            equ     1
xlOLELinks              equ     2
xlPublishers            equ     5
xlSubscribers           equ     6


XlCellType typedef SDWORD
xlCellTypeBlanks        equ     4
xlCellTypeConstants     equ     2
xlCellTypeFormulas      equ     -4123               ;=0FFFFEFE5h
xlCellTypeLastCell      equ     11
xlCellTypeComments      equ     -4144               ;=0FFFFEFD0h
xlCellTypeVisible       equ     12
xlCellTypeAllFormatConditions   equ -4172           ;=0FFFFEFB4h
xlCellTypeSameFormatConditions  equ -4173           ;=0FFFFEFB3h
xlCellTypeAllValidation         equ -4174           ;=0FFFFEFB2h
xlCellTypeSameValidation        equ -4175           ;=0FFFFEFB1h


XlArrangeStyle typedef SDWORD
xlArrangeStyleCascade     equ     7
xlArrangeStyleHorizontal  equ     -4128               ;=0FFFFEFE0h
xlArrangeStyleTiled       equ     1
xlArrangeStyleVertical    equ     -4166               ;=0FFFFEFBAh


XlMousePointer typedef SDWORD
xlIBeam                 equ     3
xlDefault               equ     -4143                 ;=0FFFFEFD1h
xlNorthwestArrow        equ     1
xlWait                  equ     2


XlEditionOptionsOption typedef SDWORD
xlAutomaticUpdate       equ     4
xlCancel                equ     1
xlChangeAttributes      equ     6
xlManualUpdate          equ     5
xlOpenSource            equ     3
xlSelect                equ     3
xlSendPublisher         equ     2
xlUpdateSubscriber      equ     2


XlAutoFillType typedef SDWORD
xlFillCopy              equ     1
xlFillDays              equ     5
xlFillDefault           equ     0
xlFillFormats           equ     3
xlFillMonths            equ     7
xlFillSeries            equ     2
xlFillValues            equ     4
xlFillWeekdays          equ     6
xlFillYears             equ     8
xlGrowthTrend           equ     10
xlLinearTrend           equ     9


XlAutoFilterOperator typedef SDWORD
xlAnd                   equ     1
xlBottom10Items         equ     4
xlBottom10Percent       equ     6
xlOr                    equ     2
xlTop10Items            equ     3
xlTop10Percent          equ     5


XlClipboardFormat typedef SDWORD
xlClipboardFormatBIFF           equ     8
xlClipboardFormatBIFF2          equ     18               ;=012h
xlClipboardFormatBIFF3          equ     20               ;=014h
xlClipboardFormatBIFF4          equ     30               ;=01Eh
xlClipboardFormatBinary         equ     15
xlClipboardFormatBitmap         equ     9
xlClipboardFormatCGM            equ     13
xlClipboardFormatCSV            equ     5
xlClipboardFormatDIF            equ     4
xlClipboardFormatDspText        equ     12
xlClipboardFormatEmbeddedObject equ     21               ;=015h
xlClipboardFormatEmbedSource    equ     22               ;=016h
xlClipboardFormatLink           equ     11
xlClipboardFormatLinkSource     equ     23               ;=017h
xlClipboardFormatLinkSourceDesc equ     32               ;=020h
xlClipboardFormatMovie          equ     24               ;=018h
xlClipboardFormatNative         equ     14
xlClipboardFormatObjectDesc     equ     31               ;=01Fh
xlClipboardFormatObjectLink     equ     19               ;=013h
xlClipboardFormatOwnerLink      equ     17               ;=011h
xlClipboardFormatPICT           equ     2
xlClipboardFormatPrintPICT      equ     3
xlClipboardFormatRTF            equ     7
xlClipboardFormatScreenPICT     equ     29               ;=01Dh
xlClipboardFormatStandardFont   equ     28               ;=01Ch
xlClipboardFormatStandardScale  equ     27               ;=01Bh
xlClipboardFormatSYLK           equ     6
xlClipboardFormatTable          equ     16               ;=010h
xlClipboardFormatText           equ     0
xlClipboardFormatToolFace       equ     25               ;=019h
xlClipboardFormatToolFacePICT   equ     26               ;=01Ah
xlClipboardFormatVALU           equ     1
xlClipboardFormatWK1            equ     10


XlFileFormat typedef SDWORD
xlAddIn                 equ     18               ;=012h
xlCSV                   equ     6
xlCSVMac                equ     22               ;=016h
xlCSVMSDOS              equ     24               ;=018h
xlCSVWindows            equ     23               ;=017h
xlDBF2                  equ     7
xlDBF3                  equ     8
xlDBF4                  equ     11
xlDIF                   equ     9
xlExcel2                equ     16               ;=010h
xlExcel2FarEast         equ     27               ;=01Bh
xlExcel3                equ     29               ;=01Dh
xlExcel4                equ     33               ;=021h
xlExcel5                equ     39               ;=027h
xlExcel7                equ     39               ;=027h
xlExcel9795             equ     43               ;=02Bh
xlExcel4Workbook        equ     35               ;=023h
xlIntlAddIn             equ     26               ;=01Ah
xlIntlMacro             equ     25               ;=019h
xlWorkbookNormal        equ     -4143            ;=0FFFFEFD1h
xlSYLK                  equ     2
xlTemplate              equ     17               ;=011h
xlCurrentPlatformText   equ     -4158            ;=0FFFFEFC2h
xlTextMac               equ     19               ;=013h
xlTextMSDOS             equ     21               ;=015h
xlTextPrinter           equ     36               ;=024h
xlTextWindows           equ     20               ;=014h
xlWJ2WD1                equ     14
xlWK1                   equ     5
xlWK1ALL                equ     31               ;=01Fh
xlWK1FMT                equ     30               ;=01Eh
xlWK3                   equ     15
xlWK4                   equ     38               ;=026h
xlWK3FM3                equ     32               ;=020h
xlWKS                   equ     4
xlWorks2FarEast         equ     28               ;=01Ch
xlWQ1                   equ     34               ;=022h
xlWJ3                   equ     40               ;=028h
xlWJ3FJ3                equ     41               ;=029h
xlUnicodeText           equ     42               ;=02Ah
xlHtml                  equ     44               ;=02Ch
xlWebArchive            equ     45               ;=02Dh
xlXMLSpreadsheet        equ     46               ;=02Eh


XlApplicationInternational typedef SDWORD
xl24HourClock           equ     33               ;=021h
xl4DigitYears           equ     43               ;=02Bh
xlAlternateArraySeparator equ   16               ;=010h
xlColumnSeparator       equ     14
xlCountryCode           equ     1
xlCountrySetting        equ     2
xlCurrencyBefore        equ     37               ;=025h
xlCurrencyCode          equ     25               ;=019h
xlCurrencyDigits        equ     27               ;=01Bh
xlCurrencyLeadingZeros  equ     40               ;=028h
xlCurrencyMinusSign     equ     38               ;=026h
xlCurrencyNegative      equ     28               ;=01Ch
xlCurrencySpaceBefore   equ     36               ;=024h
xlCurrencyTrailingZeros equ     39               ;=027h
xlDateOrder             equ     32               ;=020h
xlDateSeparator         equ     17               ;=011h
xlDayCode               equ     21               ;=015h
xlDayLeadingZero        equ     42               ;=02Ah
xlDecimalSeparator      equ     3
xlGeneralFormatName     equ     26               ;=01Ah
xlHourCode              equ     22               ;=016h
xlLeftBrace             equ     12
xlLeftBracket           equ     10
xlListSeparator         equ     5
xlLowerCaseColumnLetter equ     9
xlLowerCaseRowLetter    equ     8
xlMDY                   equ     44               ;=02Ch
xlMetric                equ     35               ;=023h
xlMinuteCode            equ     23               ;=017h
xlMonthCode             equ     20               ;=014h
xlMonthLeadingZero      equ     41               ;=029h
xlMonthNameChars        equ     30               ;=01Eh
xlNoncurrencyDigits     equ     29               ;=01Dh
xlNonEnglishFunctions   equ     34               ;=022h
xlRightBrace            equ     13
xlRightBracket          equ     11
xlRowSeparator          equ     15
xlSecondCode            equ     24               ;=018h
xlThousandsSeparator    equ     4
xlTimeLeadingZero       equ     45               ;=02Dh
xlTimeSeparator         equ     18               ;=012h
xlUpperCaseColumnLetter equ     7
xlUpperCaseRowLetter    equ     6
xlWeekdayNameChars      equ     31               ;=01Fh
xlYearCode              equ     19               ;=013h


XlPageBreakExtent typedef SDWORD
xlPageBreakFull         equ     1
xlPageBreakPartial      equ     2


XlCellInsertionMode typedef SDWORD
xlOverwriteCells        equ     0
xlInsertDeleteCells     equ     1
xlInsertEntireRows      equ     2


XlFormulaLabel typedef SDWORD
xlNoLabels              equ     -4142               ;=0FFFFEFD2h
xlRowLabels             equ     1
xlColumnLabels          equ     2
xlMixedLabels           equ     3


XlHighlightChangesTime typedef SDWORD
xlSinceMyLastSave       equ     1
xlAllChanges            equ     2
xlNotYetReviewed        equ     3


XlCommentDisplayMode typedef SDWORD
xlNoIndicator           equ     0
xlCommentIndicatorOnly  equ     -1
xlCommentAndIndicator   equ     1


XlFormatConditionType typedef SDWORD
xlCellValue             equ     1
xlExpression            equ     2


XlFormatConditionOperator typedef SDWORD
xlBetween               equ     1
xlNotBetween            equ     2
xlEqual                 equ     3
xlNotEqual              equ     4
xlGreater               equ     5
xlLess                  equ     6
xlGreaterEqual          equ     7
xlLessEqual             equ     8


XlEnableSelection typedef SDWORD
xlNoRestrictions        equ     0
xlUnlockedCells         equ     1
xlNoSelection           equ     -4142               ;=0FFFFEFD2h


XlDVType typedef SDWORD
xlValidateInputOnly     equ     0
xlValidateWholeNumber   equ     1
xlValidateDecimal       equ     2
xlValidateList          equ     3
xlValidateDate          equ     4
xlValidateTime          equ     5
xlValidateTextLength    equ     6
xlValidateCustom        equ     7


XlIMEMode typedef SDWORD
xlIMEModeNoControl      equ     0
xlIMEModeOn             equ     1
xlIMEModeOff            equ     2
xlIMEModeDisable        equ     3
xlIMEModeHiragana       equ     4
xlIMEModeKatakana       equ     5
xlIMEModeKatakanaHalf   equ     6
xlIMEModeAlphaFull      equ     7
xlIMEModeAlpha          equ     8
xlIMEModeHangulFull     equ     9
xlIMEModeHangul         equ     10


XlDVAlertStyle typedef SDWORD
xlValidAlertStop        equ     1
xlValidAlertWarning     equ     2
xlValidAlertInformation equ     3


XlChartLocation typedef SDWORD
xlLocationAsNewSheet    equ     1
xlLocationAsObject      equ     2
xlLocationAutomatic     equ     3


XlPaperSize typedef SDWORD
xlPaper10x14            equ     16               ;=010h
xlPaper11x17            equ     17               ;=011h
xlPaperA3               equ     8
xlPaperA4               equ     9
xlPaperA4Small          equ     10
xlPaperA5               equ     11
xlPaperB4               equ     12
xlPaperB5               equ     13
xlPaperCsheet           equ     24               ;=018h
xlPaperDsheet           equ     25               ;=019h
xlPaperEnvelope10       equ     20               ;=014h
xlPaperEnvelope11       equ     21               ;=015h
xlPaperEnvelope12       equ     22               ;=016h
xlPaperEnvelope14       equ     23               ;=017h
xlPaperEnvelope9        equ     19               ;=013h
xlPaperEnvelopeB4       equ     33               ;=021h
xlPaperEnvelopeB5       equ     34               ;=022h
xlPaperEnvelopeB6       equ     35               ;=023h
xlPaperEnvelopeC3       equ     29               ;=01Dh
xlPaperEnvelopeC4       equ     30               ;=01Eh
xlPaperEnvelopeC5       equ     28               ;=01Ch
xlPaperEnvelopeC6       equ     31               ;=01Fh
xlPaperEnvelopeC65      equ     32               ;=020h
xlPaperEnvelopeDL       equ     27               ;=01Bh
xlPaperEnvelopeItaly    equ     36               ;=024h
xlPaperEnvelopeMonarch  equ     37               ;=025h
xlPaperEnvelopePersonal equ     38               ;=026h
xlPaperEsheet           equ     26               ;=01Ah
xlPaperExecutive        equ     7
xlPaperFanfoldLegalGerman equ   41               ;=029h
xlPaperFanfoldStdGerman   equ   40               ;=028h
xlPaperFanfoldUS        equ     39               ;=027h
xlPaperFolio            equ     14
xlPaperLedger           equ     4
xlPaperLegal            equ     5
xlPaperLetter           equ     1
xlPaperLetterSmall      equ     2
xlPaperNote             equ     18               ;=012h
xlPaperQuarto           equ     15
xlPaperStatement        equ     6
xlPaperTabloid          equ     3
xlPaperUser             equ     256              ;=0100h


XlPasteSpecialOperation typedef SDWORD
xlPasteSpecialOperationAdd      equ     2
xlPasteSpecialOperationDivide   equ     5
xlPasteSpecialOperationMultiply equ     4
xlPasteSpecialOperationNone     equ     -4142       ;=0FFFFEFD2h
xlPasteSpecialOperationSubtract equ     3


XlPasteType typedef SDWORD
xlPasteAll              equ     -4104               ;=0FFFFEFF8h
xlPasteAllExceptBorders equ     7
xlPasteFormats          equ     -4122               ;=0FFFFEFE6h
xlPasteFormulas         equ     -4123               ;=0FFFFEFE5h
xlPasteComments         equ     -4144               ;=0FFFFEFD0h
xlPasteValues           equ     -4163               ;=0FFFFEFBDh
xlPasteColumnWidths     equ     8
xlPasteValidation       equ     6
xlPasteFormulasAndNumberFormats equ     11
xlPasteValuesAndNumberFormats   equ     12


XlPhoneticCharacterType typedef SDWORD
xlKatakanaHalf          equ     0
xlKatakana              equ     1
xlHiragana              equ     2
xlNoConversion          equ     3


XlPhoneticAlignment typedef SDWORD
xlPhoneticAlignNoControl    equ     0
xlPhoneticAlignLeft         equ     1
xlPhoneticAlignCenter       equ     2
xlPhoneticAlignDistributed  equ     3


XlPictureAppearance typedef SDWORD
xlPrinter               equ     2
xlScreen                equ     1


XlPivotFieldOrientation typedef SDWORD
xlColumnField           equ     2
xlDataField             equ     4
xlHidden                equ     0
xlPageField             equ     3
xlRowField              equ     1


XlPivotFieldCalculation typedef SDWORD
xlDifferenceFrom        equ     2
xlIndex                 equ     9
xlNoAdditionalCalculation equ   -4143               ;=0FFFFEFD1h
xlPercentDifferenceFrom   equ   4
xlPercentOf             equ     3
xlPercentOfColumn       equ     7
xlPercentOfRow          equ     6
xlPercentOfTotal        equ     8
xlRunningTotal          equ     5


XlPlacement typedef SDWORD
xlFreeFloating          equ     3
xlMove                  equ     2
xlMoveAndSize           equ     1


XlPlatform typedef SDWORD
xlMacintosh             equ     1
xlMSDOS                 equ     3
xlWindows               equ     2


XlPrintLocation typedef SDWORD
xlPrintSheetEnd         equ     1
xlPrintInPlace          equ     16                  ;=010h
xlPrintNoComments       equ     -4142               ;=0FFFFEFD2h


XlPriority typedef SDWORD
xlPriorityHigh          equ     -4127               ;=0FFFFEFE1h
xlPriorityLow           equ     -4134               ;=0FFFFEFDAh
xlPriorityNormal        equ     -4143               ;=0FFFFEFD1h


XlPTSelectionMode typedef SDWORD
xlLabelOnly             equ     1
xlDataAndLabel          equ     0
xlDataOnly              equ     2
xlOrigin                equ     3
xlButton                equ     15
xlBlanks                equ     4
xlFirstRow              equ     256                 ;=0100h


XlRangeAutoFormat typedef SDWORD
xlRangeAutoFormat3DEffects1         equ     13
xlRangeAutoFormat3DEffects2         equ     14
xlRangeAutoFormatAccounting1        equ     4
xlRangeAutoFormatAccounting2        equ     5
xlRangeAutoFormatAccounting3        equ     6
xlRangeAutoFormatAccounting4        equ     17               ;=011h
xlRangeAutoFormatClassic1           equ     1
xlRangeAutoFormatClassic2           equ     2
xlRangeAutoFormatClassic3           equ     3
xlRangeAutoFormatColor1             equ     7
xlRangeAutoFormatColor2             equ     8
xlRangeAutoFormatColor3             equ     9
xlRangeAutoFormatList1              equ     10
xlRangeAutoFormatList2              equ     11
xlRangeAutoFormatList3              equ     12
xlRangeAutoFormatLocalFormat1       equ     15
xlRangeAutoFormatLocalFormat2       equ     16               ;=010h
xlRangeAutoFormatLocalFormat3       equ     19               ;=013h
xlRangeAutoFormatLocalFormat4       equ     20               ;=014h
xlRangeAutoFormatReport1            equ     21               ;=015h
xlRangeAutoFormatReport2            equ     22               ;=016h
xlRangeAutoFormatReport3            equ     23               ;=017h
xlRangeAutoFormatReport4            equ     24               ;=018h
xlRangeAutoFormatReport5            equ     25               ;=019h
xlRangeAutoFormatReport6            equ     26               ;=01Ah
xlRangeAutoFormatReport7            equ     27               ;=01Bh
xlRangeAutoFormatReport8            equ     28               ;=01Ch
xlRangeAutoFormatReport9            equ     29               ;=01Dh
xlRangeAutoFormatReport10           equ     30               ;=01Eh
xlRangeAutoFormatClassicPivotTable  equ     31               ;=01Fh
xlRangeAutoFormatTable1             equ     32               ;=020h
xlRangeAutoFormatTable2             equ     33               ;=021h
xlRangeAutoFormatTable3             equ     34               ;=022h
xlRangeAutoFormatTable4             equ     35               ;=023h
xlRangeAutoFormatTable5             equ     36               ;=024h
xlRangeAutoFormatTable6             equ     37               ;=025h
xlRangeAutoFormatTable7             equ     38               ;=026h
xlRangeAutoFormatTable8             equ     39               ;=027h
xlRangeAutoFormatTable9             equ     40               ;=028h
xlRangeAutoFormatTable10            equ     41               ;=029h
xlRangeAutoFormatPTNone             equ     42               ;=02Ah
xlRangeAutoFormatNone               equ     -4142            ;=0FFFFEFD2h
xlRangeAutoFormatSimple             equ     -4154            ;=0FFFFEFC6h


XlReferenceType typedef SDWORD
xlAbsolute              equ     1
xlAbsRowRelColumn       equ     2
xlRelative              equ     4
xlRelRowAbsColumn       equ     3


XlLayoutFormType typedef SDWORD
xlTabular               equ     0
xlOutline               equ     1


XlRoutingSlipDelivery typedef SDWORD
xlAllAtOnce             equ     2
xlOneAfterAnother       equ     1


XlRoutingSlipStatus typedef SDWORD
xlNotYetRouted          equ     0
xlRoutingComplete       equ     2
xlRoutingInProgress     equ     1


XlRunAutoMacro typedef SDWORD
xlAutoActivate          equ     3
xlAutoClose             equ     2
xlAutoDeactivate        equ     4
xlAutoOpen              equ     1


XlSaveAction typedef SDWORD
xlDoNotSaveChanges      equ     2
xlSaveChanges           equ     1


XlSaveAsAccessMode typedef SDWORD
xlExclusive             equ     3
xlNoChange              equ     1
xlShared                equ     2


XlSaveConflictResolution typedef SDWORD
xlLocalSessionChanges   equ     2
xlOtherSessionChanges   equ     3
xlUserResolution        equ     1


XlSearchDirection typedef SDWORD
xlNext                  equ     1
xlPrevious              equ     2


XlSearchOrder typedef SDWORD
xlByColumns             equ     2
xlByRows                equ     1


XlSheetVisibility typedef SDWORD
xlSheetVisible          equ     -1
xlSheetHidden           equ     0
xlSheetVeryHidden       equ     2


XlSortMethod typedef SDWORD
xlPinYin                equ     1
xlStroke                equ     2


XlSortMethodOld typedef SDWORD
xlCodePage              equ     2
xlSyllabary             equ     1


XlSortOrder typedef SDWORD
xlAscending             equ     1
xlDescending            equ     2


XlSortOrientation typedef SDWORD
xlSortRows              equ     2
xlSortColumns           equ     1


XlSortType typedef SDWORD
xlSortLabels            equ     2
xlSortValues            equ     1


XlSpecialCellsValue typedef SDWORD
xlErrors                equ     16                      ;=010h
xlLogical               equ     4
xlNumbers               equ     1
xlTextValues            equ     2


XlSubscribeToFormat typedef SDWORD
xlSubscribeToPicture    equ     -4147                   ;=0FFFFEFCDh
xlSubscribeToText       equ     -4158                   ;=0FFFFEFC2h


XlSummaryRow typedef SDWORD
xlSummaryAbove          equ     0
xlSummaryBelow          equ     1


XlSummaryColumn typedef SDWORD
xlSummaryOnLeft         equ     -4131                   ;=0FFFFEFDDh
xlSummaryOnRight        equ     -4152                   ;=0FFFFEFC8h


XlSummaryReportType typedef SDWORD
xlSummaryPivotTable     equ     -4148                   ;=0FFFFEFCCh
xlStandardSummary       equ     1


XlTabPosition typedef SDWORD
xlTabPositionFirst      equ     0
xlTabPositionLast       equ     1


XlTextParsingType typedef SDWORD
xlDelimited             equ     1
xlFixedWidth            equ     2


XlTextQualifier typedef SDWORD
xlTextQualifierDoubleQuote  equ     1
xlTextQualifierNone         equ     -4142               ;=0FFFFEFD2h
xlTextQualifierSingleQuote  equ     2


XlWBATemplate typedef SDWORD
xlWBATChart                 equ     -4109               ;=0FFFFEFF3h
xlWBATExcel4IntlMacroSheet  equ     4
xlWBATExcel4MacroSheet      equ     3
xlWBATWorksheet             equ     -4167               ;=0FFFFEFB9h


XlWindowView typedef SDWORD
xlNormalView            equ     1
xlPageBreakPreview      equ     2


XlXLMMacroType typedef SDWORD
xlCommand               equ     2
xlFunction              equ     1
xlNotXLM                equ     3


XlYesNoGuess typedef SDWORD
xlGuess                 equ     0
xlNo                    equ     2
xlYes                   equ     1


XlBordersIndex typedef SDWORD
xlInsideHorizontal      equ     12
xlInsideVertical        equ     11
xlDiagonalDown          equ     5
xlDiagonalUp            equ     6
xlEdgeBottom            equ     9
xlEdgeLeft              equ     7
xlEdgeRight             equ     10
xlEdgeTop               equ     8


XlToolbarProtection typedef SDWORD
xlNoButtonChanges       equ     1
xlNoChanges             equ     4
xlNoDockingChanges      equ     3
xlToolbarProtectionNone equ     -4143                   ;=0FFFFEFD1h
xlNoShapeChanges        equ     2


XlBuiltInDialog typedef SDWORD
xlDialogOpen                    equ     1
xlDialogOpenLinks               equ     2
xlDialogSaveAs                  equ     5
xlDialogFileDelete              equ     6
xlDialogPageSetup               equ     7
xlDialogPrint                   equ     8
xlDialogPrinterSetup            equ     9
xlDialogArrangeAll              equ     12
xlDialogWindowSize              equ     13
xlDialogWindowMove              equ     14
xlDialogRun                     equ     17          ;=011h
xlDialogSetPrintTitles          equ     23          ;=017h
xlDialogFont                    equ     26          ;=01Ah
xlDialogDisplay                 equ     27          ;=01Bh
xlDialogProtectDocument         equ     28          ;=01Ch
xlDialogCalculation             equ     32          ;=020h
xlDialogExtract                 equ     35          ;=023h
xlDialogDataDelete              equ     36          ;=024h
xlDialogSort                    equ     39          ;=027h
xlDialogDataSeries              equ     40          ;=028h
xlDialogTable                   equ     41          ;=029h
xlDialogFormatNumber            equ     42          ;=02Ah
xlDialogAlignment               equ     43          ;=02Bh
xlDialogStyle                   equ     44          ;=02Ch
xlDialogBorder                  equ     45          ;=02Dh
xlDialogCellProtection          equ     46          ;=02Eh
xlDialogColumnWidth             equ     47          ;=02Fh
xlDialogClear                   equ     52          ;=034h
xlDialogPasteSpecial            equ     53          ;=035h
xlDialogEditDelete              equ     54          ;=036h
xlDialogInsert                  equ     55          ;=037h
xlDialogPasteNames              equ     58          ;=03Ah
xlDialogDefineName              equ     61          ;=03Dh
xlDialogCreateNames             equ     62          ;=03Eh
xlDialogFormulaGoto             equ     63          ;=03Fh
xlDialogFormulaFind             equ     64          ;=040h
xlDialogGalleryArea             equ     67          ;=043h
xlDialogGalleryBar              equ     68          ;=044h
xlDialogGalleryColumn           equ     69          ;=045h
xlDialogGalleryLine             equ     70          ;=046h
xlDialogGalleryPie              equ     71          ;=047h
xlDialogGalleryScatter          equ     72          ;=048h
xlDialogCombination             equ     73          ;=049h
xlDialogGridlines               equ     76          ;=04Ch
xlDialogAxes                    equ     78          ;=04Eh
xlDialogAttachText              equ     80          ;=050h
xlDialogPatterns                equ     84          ;=054h
xlDialogMainChart               equ     85          ;=055h
xlDialogOverlay                 equ     86          ;=056h
xlDialogScale                   equ     87          ;=057h
xlDialogFormatLegend            equ     88          ;=058h
xlDialogFormatText              equ     89          ;=059h
xlDialogParse                   equ     91          ;=05Bh
xlDialogUnhide                  equ     94          ;=05Eh
xlDialogWorkspace               equ     95          ;=05Fh
xlDialogActivate                equ     103         ;=067h
xlDialogCopyPicture             equ     108         ;=06Ch
xlDialogDeleteName              equ     110         ;=06Eh
xlDialogDeleteFormat            equ     111         ;=06Fh
xlDialogNew                     equ     119         ;=077h
xlDialogRowHeight               equ     127         ;=07Fh
xlDialogFormatMove              equ     128         ;=080h
xlDialogFormatSize              equ     129         ;=081h
xlDialogFormulaReplace          equ     130         ;=082h
xlDialogSelectSpecial           equ     132         ;=084h
xlDialogApplyNames              equ     133         ;=085h
xlDialogReplaceFont             equ     134         ;=086h
xlDialogSplit                   equ     137         ;=089h
xlDialogOutline                 equ     142         ;=08Eh
xlDialogSaveWorkbook            equ     145         ;=091h
xlDialogCopyChart               equ     147         ;=093h
xlDialogFormatFont              equ     150         ;=096h
xlDialogNote                    equ     154         ;=09Ah
xlDialogSetUpdateStatus         equ     159         ;=09Fh
xlDialogColorPalette            equ     161         ;=0A1h
xlDialogChangeLink              equ     166         ;=0A6h
xlDialogAppMove                 equ     170         ;=0AAh
xlDialogAppSize                 equ     171         ;=0ABh
xlDialogMainChartType           equ     185         ;=0B9h
xlDialogOverlayChartType        equ     186         ;=0BAh
xlDialogOpenMail                equ     188         ;=0BCh
xlDialogSendMail                equ     189         ;=0BDh
xlDialogStandardFont            equ     190         ;=0BEh
xlDialogConsolidate             equ     191         ;=0BFh
xlDialogSortSpecial             equ     192         ;=0C0h
xlDialogGallery3dArea           equ     193         ;=0C1h
xlDialogGallery3dColumn         equ     194         ;=0C2h
xlDialogGallery3dLine           equ     195         ;=0C3h
xlDialogGallery3dPie            equ     196         ;=0C4h
xlDialogView3d                  equ     197         ;=0C5h
xlDialogGoalSeek                equ     198         ;=0C6h
xlDialogWorkgroup               equ     199         ;=0C7h
xlDialogFillGroup               equ     200         ;=0C8h
xlDialogUpdateLink              equ     201         ;=0C9h
xlDialogPromote                 equ     202         ;=0CAh
xlDialogDemote                  equ     203         ;=0CBh
xlDialogShowDetail              equ     204         ;=0CCh
xlDialogObjectProperties        equ     207         ;=0CFh
xlDialogSaveNewObject           equ     208         ;=0D0h
xlDialogApplyStyle              equ     212         ;=0D4h
xlDialogAssignToObject          equ     213         ;=0D5h
xlDialogObjectProtection        equ     214         ;=0D6h
xlDialogCreatePublisher         equ     217         ;=0D9h
xlDialogSubscribeTo             equ     218         ;=0DAh
xlDialogShowToolbar             equ     220         ;=0DCh
xlDialogPrintPreview            equ     222         ;=0DEh
xlDialogEditColor               equ     223         ;=0DFh
xlDialogFormatMain              equ     225         ;=0E1h
xlDialogFormatOverlay           equ     226         ;=0E2h
xlDialogEditSeries              equ     228         ;=0E4h
xlDialogDefineStyle             equ     229         ;=0E5h
xlDialogGalleryRadar            equ     249         ;=0F9h
xlDialogEditionOptions          equ     251         ;=0FBh
xlDialogZoom                    equ     256         ;=0100h
xlDialogInsertObject            equ     259         ;=0103h
xlDialogSize                    equ     261         ;=0105h
xlDialogMove                    equ     262         ;=0106h
xlDialogFormatAuto              equ     269         ;=010Dh
xlDialogGallery3dBar            equ     272         ;=0110h
xlDialogGallery3dSurface        equ     273         ;=0111h
xlDialogCustomizeToolbar        equ     276         ;=0114h
xlDialogWorkbookAdd             equ     281         ;=0119h
xlDialogWorkbookMove            equ     282         ;=011Ah
xlDialogWorkbookCopy            equ     283         ;=011Bh
xlDialogWorkbookOptions         equ     284         ;=011Ch
xlDialogSaveWorkspace           equ     285         ;=011Dh
xlDialogChartWizard             equ     288         ;=0120h
xlDialogAssignToTool            equ     293         ;=0125h
xlDialogPlacement               equ     300         ;=012Ch
xlDialogFillWorkgroup           equ     301         ;=012Dh
xlDialogWorkbookNew             equ     302         ;=012Eh
xlDialogScenarioCells           equ     305         ;=0131h
xlDialogScenarioAdd             equ     307         ;=0133h
xlDialogScenarioEdit            equ     308         ;=0134h
xlDialogScenarioSummary         equ     311         ;=0137h
xlDialogPivotTableWizard        equ     312         ;=0138h
xlDialogPivotFieldProperties    equ     313         ;=0139h
xlDialogOptionsCalculation      equ     318         ;=013Eh
xlDialogOptionsEdit             equ     319         ;=013Fh
xlDialogOptionsView             equ     320         ;=0140h
xlDialogAddinManager            equ     321         ;=0141h
xlDialogMenuEditor              equ     322         ;=0142h
xlDialogAttachToolbars          equ     323         ;=0143h
xlDialogOptionsChart            equ     325         ;=0145h
xlDialogVbaInsertFile           equ     328         ;=0148h
xlDialogVbaProcedureDefinition  equ     330         ;=014Ah
xlDialogRoutingSlip             equ     336         ;=0150h
xlDialogMailLogon               equ     339         ;=0153h
xlDialogInsertPicture           equ     342         ;=0156h
xlDialogGalleryDoughnut         equ     344         ;=0158h
xlDialogChartTrend              equ     350         ;=015Eh
xlDialogWorkbookInsert          equ     354         ;=0162h
xlDialogOptionsTransition       equ     355         ;=0163h
xlDialogOptionsGeneral          equ     356         ;=0164h
xlDialogFilterAdvanced          equ     370         ;=0172h
xlDialogMailNextLetter          equ     378         ;=017Ah
xlDialogDataLabel               equ     379         ;=017Bh
xlDialogInsertTitle             equ     380         ;=017Ch
xlDialogFontProperties          equ     381         ;=017Dh
xlDialogMacroOptions            equ     382         ;=017Eh
xlDialogWorkbookUnhide          equ     384         ;=0180h
xlDialogWorkbookName            equ     386         ;=0182h
xlDialogGalleryCustom           equ     388         ;=0184h
xlDialogAddChartAutoformat      equ     390         ;=0186h
xlDialogChartAddData            equ     392         ;=0188h
xlDialogTabOrder                equ     394         ;=018Ah
xlDialogSubtotalCreate          equ     398         ;=018Eh
xlDialogWorkbookTabSplit        equ     415         ;=019Fh
xlDialogWorkbookProtect         equ     417         ;=01A1h
xlDialogScrollbarProperties     equ     420         ;=01A4h
xlDialogPivotShowPages          equ     421         ;=01A5h
xlDialogTextToColumns           equ     422         ;=01A6h
xlDialogFormatCharttype         equ     423         ;=01A7h
xlDialogPivotFieldGroup         equ     433         ;=01B1h
xlDialogPivotFieldUngroup       equ     434         ;=01B2h
xlDialogCheckboxProperties      equ     435         ;=01B3h
xlDialogLabelProperties         equ     436         ;=01B4h
xlDialogListboxProperties       equ     437         ;=01B5h
xlDialogEditboxProperties       equ     438         ;=01B6h
xlDialogOpenText                equ     441         ;=01B9h
xlDialogPushbuttonProperties    equ     445         ;=01BDh
xlDialogFilter                  equ     447         ;=01BFh
xlDialogFunctionWizard          equ     450         ;=01C2h
xlDialogSaveCopyAs              equ     456         ;=01C8h
xlDialogOptionsListsAdd         equ     458         ;=01CAh
xlDialogSeriesAxes              equ     460         ;=01CCh
xlDialogSeriesX                 equ     461         ;=01CDh
xlDialogSeriesY                 equ     462         ;=01CEh
xlDialogErrorbarX               equ     463         ;=01CFh
xlDialogErrorbarY               equ     464         ;=01D0h
xlDialogFormatChart             equ     465         ;=01D1h
xlDialogSeriesOrder             equ     466         ;=01D2h
xlDialogMailEditMailer          equ     470         ;=01D6h
xlDialogStandardWidth           equ     472         ;=01D8h
xlDialogScenarioMerge           equ     473         ;=01D9h
xlDialogProperties              equ     474         ;=01DAh
xlDialogSummaryInfo             equ     474         ;=01DAh
xlDialogFindFile                equ     475         ;=01DBh
xlDialogActiveCellFont          equ     476         ;=01DCh
xlDialogVbaMakeAddin            equ     478         ;=01DEh
xlDialogFileSharing             equ     481         ;=01E1h
xlDialogAutoCorrect             equ     485         ;=01E5h
xlDialogCustomViews             equ     493         ;=01EDh
xlDialogInsertNameLabel         equ     496         ;=01F0h
xlDialogSeriesShape             equ     504         ;=01F8h
xlDialogChartOptionsDataLabels  equ     505         ;=01F9h
xlDialogChartOptionsDataTable   equ     506         ;=01FAh
xlDialogSetBackgroundPicture    equ     509         ;=01FDh
xlDialogDataValidation          equ     525         ;=020Dh
xlDialogChartType               equ     526         ;=020Eh
xlDialogChartLocation           equ     527         ;=020Fh
_xlDialogPhonetic               equ     538         ;=021Ah
xlDialogChartSourceData         equ     540         ;=021Ch
_xlDialogChartSourceData        equ     541         ;=021Dh
xlDialogSeriesOptions           equ     557         ;=022Dh
xlDialogPivotTableOptions       equ     567         ;=0237h
xlDialogPivotSolveOrder         equ     568         ;=0238h
xlDialogPivotCalculatedField    equ     570         ;=023Ah
xlDialogPivotCalculatedItem     equ     572         ;=023Ch
xlDialogConditionalFormatting   equ     583         ;=0247h
xlDialogInsertHyperlin          equ     596         ;=0254h
xlDialogProtectSharing          equ     620         ;=026Ch
xlDialogOptionsME               equ     647         ;=0287h
xlDialogPublishAsWebPage        equ     653         ;=028Dh
xlDialogPhonetic                equ     656         ;=0290h
xlDialogNewWebQuery             equ     667         ;=029Bh
xlDialogImportTextFile          equ     666         ;=029Ah
xlDialogExternalDataProperties  equ     530         ;=0212h
xlDialogWebOptionsGeneral       equ     683         ;=02ABh
xlDialogWebOptionsFiles         equ     684         ;=02ACh
xlDialogWebOptionsPictures      equ     685         ;=02ADh
xlDialogWebOptionsEncoding      equ     686         ;=02AEh
xlDialogWebOptionsFonts         equ     687         ;=02AFh
xlDialogPivotClientServerSet    equ     689         ;=02B1h
xlDialogPropertyFields          equ     754         ;=02F2h
xlDialogSearch                  equ     731         ;=02DBh
xlDialogEvaluateFormula         equ     709         ;=02C5h
xlDialogDataLabelMultiple       equ     723         ;=02D3h
xlDialogChartOptionsDataLabelMultiple equ 724       ;=02D4h
xlDialogErrorChecking           equ     732         ;=02DCh
xlDialogWebOptionsBrowsers      equ     773         ;=0305h


XlParameterType typedef SDWORD
xlPrompt                equ     0
xlConstant              equ     1
xlRange                 equ     2


XlParameterDataType typedef SDWORD
xlParamTypeUnknown      equ     0
xlParamTypeChar         equ     1
xlParamTypeNumeric      equ     2
xlParamTypeDecimal      equ     3
xlParamTypeInteger      equ     4
xlParamTypeSmallInt     equ     5
xlParamTypeFloat        equ     6
xlParamTypeReal         equ     7
xlParamTypeDouble       equ     8
xlParamTypeVarChar      equ     12
xlParamTypeDate         equ     9
xlParamTypeTime         equ     10
xlParamTypeTimestamp    equ     11
xlParamTypeLongVarChar  equ     -1
xlParamTypeBinary       equ     -2               ;=0FFFFFFFEh
xlParamTypeVarBinary    equ     -3               ;=0FFFFFFFDh
xlParamTypeLongVarBinary equ    -4               ;=0FFFFFFFCh
xlParamTypeBigInt       equ     -5               ;=0FFFFFFFBh
xlParamTypeTinyInt      equ     -6               ;=0FFFFFFFAh
xlParamTypeBit          equ     -7               ;=0FFFFFFF9h
xlParamTypeWChar        equ     -8               ;=0FFFFFFF8h


XlFormControl typedef SDWORD
xlButtonControl         equ     0
xlCheckBox              equ     1
xlDropDown              equ     2
xlEditBox               equ     3
xlGroupBox              equ     4
xlLabel                 equ     5
xlListBox               equ     6
xlOptionButton          equ     7
xlScrollBar             equ     8
xlSpinner               equ     9


XlSourceType typedef SDWORD
xlSourceWorkbook        equ     0
xlSourceSheet           equ     1
xlSourcePrintArea       equ     2
xlSourceAutoFilter      equ     3
xlSourceRange           equ     4
xlSourceChart           equ     5
xlSourcePivotTable      equ     6
xlSourceQuery           equ     7


XlHtmlType typedef SDWORD
xlHtmlStatic            equ     0
xlHtmlCalc              equ     1
xlHtmlList              equ     2
xlHtmlChart             equ     3


XlPivotFormatType typedef SDWORD
xlReport1               equ     0
xlReport2               equ     1
xlReport3               equ     2
xlReport4               equ     3
xlReport5               equ     4
xlReport6               equ     5
xlReport7               equ     6
xlReport8               equ     7
xlReport9               equ     8
xlReport10              equ     9
xlTable1                equ     10
xlTable2                equ     11
xlTable3                equ     12
xlTable4                equ     13
xlTable5                equ     14
xlTable6                equ     15
xlTable7                equ     16               ;=010h
xlTable8                equ     17               ;=011h
xlTable9                equ     18               ;=012h
xlTable10               equ     19               ;=013h
xlPTClassic             equ     20               ;=014h
xlPTNone                equ     21               ;=015h


XlCmdType typedef SDWORD
xlCmdCube               equ     1
xlCmdSql                equ     2
xlCmdTable              equ     3
xlCmdDefault            equ     4


XlColumnDataType typedef SDWORD
xlGeneralFormat         equ     1
xlTextFormat            equ     2
xlMDYFormat             equ     3
xlDMYFormat             equ     4
xlYMDFormat             equ     5
xlMYDFormat             equ     6
xlDYMFormat             equ     7
xlYDMFormat             equ     8
xlSkipColumn            equ     9
xlEMDFormat             equ     10


XlQueryType typedef SDWORD
xlODBCQuery             equ     1
xlDAORecordset          equ     2
xlWebQuery              equ     4
xlOLEDBQuery            equ     5
xlTextImport            equ     6
xlADORecordset          equ     7


XlWebSelectionType typedef SDWORD
xlEntirePage            equ     1
xlAllTables             equ     2
xlSpecifiedTables       equ     3


XlCubeFieldType typedef SDWORD
xlHierarchy             equ     1
xlMeasure               equ     2
xlSet                   equ     3


XlWebFormatting typedef SDWORD
xlWebFormattingAll      equ     1
xlWebFormattingRTF      equ     2
xlWebFormattingNone     equ     3


XlDisplayDrawingObjects typedef SDWORD
xlDisplayShapes         equ     -4104               ;=0FFFFEFF8h
xlHide                  equ     3
xlPlaceholders          equ     2


XlSubtototalLocationType typedef SDWORD
xlAtTop                 equ     1
xlAtBottom              equ     2


XlPivotTableVersionList typedef SDWORD
xlPivotTableVersion2000 equ     0
xlPivotTableVersion10   equ     1
xlPivotTableVersionCurrent  equ -1


XlPrintErrors typedef SDWORD
xlPrintErrorsDisplayed  equ     0
xlPrintErrorsBlank      equ     1
xlPrintErrorsDash       equ     2
xlPrintErrorsNA         equ     3


XlPivotCellType typedef SDWORD
xlPivotCellValue        equ     0
xlPivotCellPivotItem    equ     1
xlPivotCellSubtotal     equ     2
xlPivotCellGrandTotal   equ     3
xlPivotCellDataField    equ     4
xlPivotCellPivotField   equ     5
xlPivotCellPageFieldItem  equ   6
xlPivotCellCustomSubtotal equ   7
xlPivotCellDataPivotField equ   8
xlPivotCellBlankCell    equ     9


XlPivotTableMissingItems typedef SDWORD
xlMissingItemsDefault   equ     -1
xlMissingItemsNone      equ     0
xlMissingItemsMax       equ     32500               ;=07EF4h


XlCalculationState typedef SDWORD
xlDone                  equ     0
xlCalculating           equ     1
xlPending               equ     2


XlCalculationInterruptKey typedef SDWORD
xlNoKey                 equ     0
xlEscKey                equ     1
xlAnyKey                equ     2


XlSortDataOption typedef SDWORD
xlSortNormal            equ     0
xlSortTextAsNumbers     equ     1


XlUpdateLinks typedef SDWORD
xlUpdateLinksUserSetting  equ     1
xlUpdateLinksNever        equ     2
xlUpdateLinksAlways       equ     3


XlLinkStatus typedef SDWORD
xlLinkStatusOK            equ     0
xlLinkStatusMissingFile   equ     1
xlLinkStatusMissingSheet  equ     2
xlLinkStatusOld           equ     3
xlLinkStatusSourceNotCalculated equ 4
xlLinkStatusIndeterminate equ     5
xlLinkStatusNotStarted    equ     6
xlLinkStatusInvalidName   equ     7
xlLinkStatusSourceNotOpen equ     8
xlLinkStatusSourceOpen    equ     9
xlLinkStatusCopiedValues  equ     10


XlSearchWithin typedef SDWORD
xlWithinSheet           equ     1
xlWithinWorkbook        equ     2


XlCorruptLoad typedef SDWORD
xlNormalLoad            equ     0
xlRepairFile            equ     1
xlExtractData           equ     2


XlRobustConnect typedef SDWORD
xlAsRequired            equ     0
xlAlways                equ     1
xlNever                 equ     2


XlErrorChecks typedef SDWORD
xlEvaluateToError       equ     1
xlTextDate              equ     2
xlNumberAsText          equ     3
xlInconsistentFormula   equ     4
xlOmittedCells          equ     5
xlUnlockedFormulaCells  equ     6
xlEmptyCellReferences   equ     7


XlDataLabelSeparator typedef SDWORD
xlDataLabelSeparatorDefault     equ     1


XlSmartTagDisplayMode typedef SDWORD
xlIndicatorAndButton    equ     0
xlDisplayNone           equ     1
xlButtonOnly            equ     2


XlRangeValueDataType typedef SDWORD
xlRangeValueDefault         equ     10
xlRangeValueXMLSpreadsheet  equ     11
xlRangeValueMSPersistXML    equ     12


XlSpeakDirection typedef SDWORD
xlSpeakByRows           equ     0
xlSpeakByColumns        equ     1


XlInsertFormatOrigin typedef SDWORD
xlFormatFromLeftOrAbove   equ     0
xlFormatFromRightOrBelow  equ     1


XlArabicModes typedef SDWORD
xlArabicNone            equ     0
xlArabicStrictAlefHamza equ     1
xlArabicStrictFinalYaa  equ     2
xlArabicBothStrict      equ     3


XlImportDataAs typedef SDWORD
xlQueryTable            equ     0
xlPivotTableReport      equ     1


XlCalculatedMemberType typedef SDWORD
xlCalculatedMember      equ     0
xlCalculatedSet         equ     1


XlHebrewModes typedef SDWORD
xlHebrewFullScript      equ     0
xlHebrewPartialScript   equ     1
xlHebrewMixedScript     equ     2
xlHebrewMixedAuthorizedScript equ 3


COM_INTERFACE_BEG _IMsoDispObj, IDispatch, <000C0300-0000-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr LPDISPATCH
  COM_MTD_STD  get_Creator, ptr SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG FillFormat, _IMsoDispObj, <000C0314-0000-0000-C000-000000000046>
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Background
  COM_MTD_STD  OneColorGradient, MsoGradientStyle, SDWORD, REAL4
  COM_MTD_STD  Patterned, MsoPatternType
  COM_MTD_STD  PresetGradient, MsoGradientStyle, SDWORD, MsoPresetGradientType
  COM_MTD_STD  PresetTextured, MsoPresetTexture
  COM_MTD_STD  Solid
  COM_MTD_STD  TwoColorGradient, MsoGradientStyle, SDWORD
  COM_MTD_STD  UserPicture, BSTR
  COM_MTD_STD  UserTextured, BSTR
  COM_MTD_STD  get_BackColor, ptr ptr ColorFormat
  COM_MTD_STD  put_BackColor, ptr ColorFormat
  COM_MTD_STD  get_ForeColor, ptr ptr ColorFormat
  COM_MTD_STD  put_ForeColor, ptr ColorFormat
  COM_MTD_STD  get_GradientColorType, ptr MsoGradientColorType
  COM_MTD_STD  get_GradientDegree, ptr REAL4
  COM_MTD_STD  get_GradientStyle, ptr MsoGradientStyle
  COM_MTD_STD  get_GradientVariant, ptr SDWORD
  COM_MTD_STD  get_Pattern, ptr MsoPatternType
  COM_MTD_STD  get_PresetGradientType, ptr MsoPresetGradientType
  COM_MTD_STD  get_PresetTexture, ptr MsoPresetTexture
  COM_MTD_STD  get_TextureName, ptr BSTR
  COM_MTD_STD  get_TextureType, ptr MsoTextureType
  COM_MTD_STD  get_Transparency, ptr REAL4
  COM_MTD_STD  put_Transparency, REAL4
  COM_MTD_STD  get_Type, ptr MsoFillType
  COM_MTD_STD  get_Visible, ptr MsoTriState
  COM_MTD_STD  put_Visible, MsoTriState
COM_INTERFACE_END

COM_INTERFACE_BEG DiagramNodes, _IMsoDispObj, <000C036E-0000-0000-C000-000000000046>
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  Item, VARIANT, ptr ptr DiagramNode
  COM_MTD_STD  SelectAll
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG DiagramNodeChildren, _IMsoDispObj, <000C036F-0000-0000-C000-000000000046>
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  Item, VARIANT, ptr ptr DiagramNode
  COM_MTD_STD  AddNode;, VARIANT, MsoDiagramNodeType, ptr ptr DiagramNode
  COM_MTD_STD  SelectAll
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  get_FirstChild, ptr ptr DiagramNode
  COM_MTD_STD  get_LastChild, ptr ptr DiagramNode
COM_INTERFACE_END

COM_INTERFACE_BEG DiagramNode, _IMsoDispObj, <000C0370-0000-0000-C000-000000000046>
  COM_MTD_STD  AddNode;, MsoRelativeNodePosition, MsoDiagramNodeType, ptr ptr DiagramNode
  COM_MTD_STD  Delete
  COM_MTD_STD  MoveNode;, ptr DiagramNode, MsoRelativeNodePosition
  COM_MTD_STD  ReplaceNode, ptr DiagramNode
  COM_MTD_STD  SwapNode, ptr DiagramNode, BOOL
  COM_MTD_STD  CloneNode;, BOOL, ptr DiagramNode, MsoRelativeNodePosition, ptr ptr DiagramNode
  COM_MTD_STD  TransferChildren, ptr DiagramNode
  COM_MTD_STD  NextNode, ptr ptr DiagramNode
  COM_MTD_STD  PrevNode, ptr ptr DiagramNode
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Children, ptr ptr DiagramNodeChildren
  COM_MTD_STD  get_Shape, ptr ptr Shape
  COM_MTD_STD  get_Root, ptr ptr DiagramNode
  COM_MTD_STD  get_Diagram, ptr ptr IMsoDiagram
  COM_MTD_STD  get_Layout, ptr MsoOrgChartLayoutType
  COM_MTD_STD  put_Layout, MsoOrgChartLayoutType
  COM_MTD_STD  get_TextShape, ptr ptr Shape
COM_INTERFACE_END

COM_INTERFACE_BEG IRTDUpdateEvent, IDispatch, <A43788C1-D91B-11D3-8F39-00C04F3651B8>
  COM_MTD_STD  UpdateNotify
  COM_MTD_STD  get_HeartbeatInterval, ptr SDWORD
  COM_MTD_STD  put_HeartbeatInterval, SDWORD
  COM_MTD_STD  Disconnect
COM_INTERFACE_END

COM_INTERFACE_BEG IRtdServer, IDispatch, <EC0E6191-DB51-11D3-8F3E-00C04F3651B8>
  COM_MTD_STD  ServerStart, ptr IRTDUpdateEvent, ptr SDWORD
  COM_MTD_STD  ConnectData, SDWORD, ptr SAFEARRAY, ptr BOOL, ptr VARIANT
  COM_MTD_STD  RefreshData, ptr SDWORD, ptr SAFEARRAY
  COM_MTD_STD  DisconnectData, SDWORD
  COM_MTD_STD  Heartbeat, ptr SDWORD
  COM_MTD_STD  ServerTerminate
COM_INTERFACE_END

COM_INTERFACE_BEG Adjustments, _IMsoDispObj, <000C0310-0000-0000-C000-000000000046>
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  get_Item, SDWORD, ptr REAL4
  COM_MTD_STD  put_Item, SDWORD, REAL4
COM_INTERFACE_END

COM_INTERFACE_BEG CalloutFormat, _IMsoDispObj, <000C0311-0000-0000-C000-000000000046>
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  AutomaticLength
  COM_MTD_STD  CustomDrop, REAL4
  COM_MTD_STD  CustomLength, REAL4
  COM_MTD_STD  PresetDrop;, MsoCalloutDropType
  COM_MTD_STD  get_Accent, ptr MsoTriState
  COM_MTD_STD  put_Accent, MsoTriState
  COM_MTD_STD  get_Angle, ptr MsoCalloutAngleType
  COM_MTD_STD  put_Angle, MsoCalloutAngleType
  COM_MTD_STD  get_AutoAttach, ptr MsoTriState
  COM_MTD_STD  put_AutoAttach, MsoTriState
  COM_MTD_STD  get_AutoLength, ptr MsoTriState
  COM_MTD_STD  get_Border, ptr MsoTriState
  COM_MTD_STD  put_Border, MsoTriState
  COM_MTD_STD  get_Drop, ptr REAL4
  COM_MTD_STD  get_DropType, ptr MsoCalloutDropType
  COM_MTD_STD  get_Gap, ptr REAL4
  COM_MTD_STD  put_Gap, REAL4
  COM_MTD_STD  get_Length, ptr REAL4
  COM_MTD_STD  get_Type, ptr MsoCalloutType
  COM_MTD_STD  put_Type, MsoCalloutType
COM_INTERFACE_END

COM_INTERFACE_BEG ColorFormat, _IMsoDispObj, <000C0312-0000-0000-C000-000000000046>
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_RGB, ptr MsoRGBType
  COM_MTD_STD  put_RGB, MsoRGBType
  COM_MTD_STD  get_SchemeColor, ptr SDWORD
  COM_MTD_STD  put_SchemeColor, SDWORD
  COM_MTD_STD  get_Type, ptr MsoColorType
  COM_MTD_STD  get_TintAndShade, ptr REAL4
  COM_MTD_STD  put_TintAndShade, REAL4
COM_INTERFACE_END

COM_INTERFACE_BEG LineFormat, _IMsoDispObj, <000C0317-0000-0000-C000-000000000046>
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_BackColor, ptr ptr ColorFormat
  COM_MTD_STD  put_BackColor, ptr ColorFormat
  COM_MTD_STD  get_BeginArrowheadLength, ptr MsoArrowheadLength
  COM_MTD_STD  put_BeginArrowheadLength, MsoArrowheadLength
  COM_MTD_STD  get_BeginArrowheadStyle, ptr MsoArrowheadStyle
  COM_MTD_STD  put_BeginArrowheadStyle, MsoArrowheadStyle
  COM_MTD_STD  get_BeginArrowheadWidth, ptr MsoArrowheadWidth
  COM_MTD_STD  put_BeginArrowheadWidth, MsoArrowheadWidth
  COM_MTD_STD  get_DashStyle, ptr MsoLineDashStyle
  COM_MTD_STD  put_DashStyle, MsoLineDashStyle
  COM_MTD_STD  get_EndArrowheadLength, ptr MsoArrowheadLength
  COM_MTD_STD  put_EndArrowheadLength, MsoArrowheadLength
  COM_MTD_STD  get_EndArrowheadStyle, ptr MsoArrowheadStyle
  COM_MTD_STD  put_EndArrowheadStyle, MsoArrowheadStyle
  COM_MTD_STD  get_EndArrowheadWidth, ptr MsoArrowheadWidth
  COM_MTD_STD  put_EndArrowheadWidth, MsoArrowheadWidth
  COM_MTD_STD  get_ForeColor, ptr ptr ColorFormat
  COM_MTD_STD  put_ForeColor, ptr ColorFormat
  COM_MTD_STD  get_Pattern, ptr MsoPatternType
  COM_MTD_STD  put_Pattern, MsoPatternType
  COM_MTD_STD  get_Style, ptr MsoLineStyle
  COM_MTD_STD  put_Style, MsoLineStyle
  COM_MTD_STD  get_Transparency, ptr REAL4
  COM_MTD_STD  put_Transparency, REAL4
  COM_MTD_STD  get_Visible, ptr MsoTriState
  COM_MTD_STD  put_Visible, MsoTriState
  COM_MTD_STD  get_Weight, ptr REAL4
  COM_MTD_STD  put_Weight, REAL4
COM_INTERFACE_END

COM_INTERFACE_BEG ShapeNode, _IMsoDispObj, <000C0318-0000-0000-C000-000000000046>
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_EditingType, ptr MsoEditingType
  COM_MTD_STD  get_Points, ptr VARIANT
  COM_MTD_STD  get_SegmentType, ptr MsoSegmentType
COM_INTERFACE_END

COM_INTERFACE_BEG ShapeNodes, _IMsoDispObj, <000C0319-0000-0000-C000-000000000046>
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Item, VARIANT, ptr ptr ShapeNode
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  Delete, SDWORD
  COM_MTD_STD  Insert, SDWORD, MsoSegmentType, MsoEditingType, REAL4, REAL4, REAL4, REAL4, REAL4, REAL4
  COM_MTD_STD  SetEditingType, SDWORD, MsoEditingType
  COM_MTD_STD  SetPosition, SDWORD, REAL4, REAL4
  COM_MTD_STD  SetSegmentType, SDWORD, MsoSegmentType
COM_INTERFACE_END

COM_INTERFACE_BEG PictureFormat, _IMsoDispObj, <000C031A-0000-0000-C000-000000000046>
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  IncrementBrightness, REAL4
  COM_MTD_STD  IncrementContrast, REAL4
  COM_MTD_STD  get_Brightness, ptr REAL4
  COM_MTD_STD  put_Brightness, REAL4
  COM_MTD_STD  get_ColorType, ptr MsoPictureColorType
  COM_MTD_STD  put_ColorType, MsoPictureColorType
  COM_MTD_STD  get_Contrast, ptr REAL4
  COM_MTD_STD  put_Contrast, REAL4
  COM_MTD_STD  get_CropBottom, ptr REAL4
  COM_MTD_STD  put_CropBottom, REAL4
  COM_MTD_STD  get_CropLeft, ptr REAL4
  COM_MTD_STD  put_CropLeft, REAL4
  COM_MTD_STD  get_CropRight, ptr REAL4
  COM_MTD_STD  put_CropRight, REAL4
  COM_MTD_STD  get_CropTop, ptr REAL4
  COM_MTD_STD  put_CropTop, REAL4
  COM_MTD_STD  get_TransparencyColor, ptr MsoRGBType
  COM_MTD_STD  put_TransparencyColor, MsoRGBType
  COM_MTD_STD  get_TransparentBackground, ptr MsoTriState
  COM_MTD_STD  put_TransparentBackground, MsoTriState
COM_INTERFACE_END

COM_INTERFACE_BEG ShadowFormat, _IMsoDispObj, <000C031B-0000-0000-C000-000000000046>
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  IncrementOffsetX, REAL4
  COM_MTD_STD  IncrementOffsetY, REAL4
  COM_MTD_STD  get_ForeColor, ptr ptr ColorFormat
  COM_MTD_STD  put_ForeColor, ptr ColorFormat
  COM_MTD_STD  get_Obscured, ptr MsoTriState
  COM_MTD_STD  put_Obscured, MsoTriState
  COM_MTD_STD  get_OffsetX, ptr REAL4
  COM_MTD_STD  put_OffsetX, REAL4
  COM_MTD_STD  get_OffsetY, ptr REAL4
  COM_MTD_STD  put_OffsetY, REAL4
  COM_MTD_STD  get_Transparency, ptr REAL4
  COM_MTD_STD  put_Transparency, REAL4
  COM_MTD_STD  get_Type, ptr MsoShadowType
  COM_MTD_STD  put_Type, MsoShadowType
  COM_MTD_STD  get_Visible, ptr MsoTriState
  COM_MTD_STD  put_Visible, MsoTriState
COM_INTERFACE_END

COM_INTERFACE_BEG TextEffectFormat, _IMsoDispObj, <000C031F-0000-0000-C000-000000000046>
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  ToggleVerticalText
  COM_MTD_STD  get_Alignment, ptr MsoTextEffectAlignment
  COM_MTD_STD  put_Alignment, MsoTextEffectAlignment
  COM_MTD_STD  get_FontBold, ptr MsoTriState
  COM_MTD_STD  put_FontBold, MsoTriState
  COM_MTD_STD  get_FontItalic, ptr MsoTriState
  COM_MTD_STD  put_FontItalic, MsoTriState
  COM_MTD_STD  get_FontName, ptr BSTR
  COM_MTD_STD  put_FontName, BSTR
  COM_MTD_STD  get_FontSize, ptr REAL4
  COM_MTD_STD  put_FontSize, REAL4
  COM_MTD_STD  get_KernedPairs, ptr MsoTriState
  COM_MTD_STD  put_KernedPairs, MsoTriState
  COM_MTD_STD  get_NormalizedHeight, ptr MsoTriState
  COM_MTD_STD  put_NormalizedHeight, MsoTriState
  COM_MTD_STD  get_PresetShape, ptr MsoPresetTextEffectShape
  COM_MTD_STD  put_PresetShape, MsoPresetTextEffectShape
  COM_MTD_STD  get_PresetTextEffect, ptr MsoPresetTextEffect
  COM_MTD_STD  put_PresetTextEffect, MsoPresetTextEffect
  COM_MTD_STD  get_RotatedChars, ptr MsoTriState
  COM_MTD_STD  put_RotatedChars, MsoTriState
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
  COM_MTD_STD  get_Tracking, ptr REAL4
  COM_MTD_STD  put_Tracking, REAL4
COM_INTERFACE_END

COM_INTERFACE_BEG ThreeDFormat, _IMsoDispObj, <000C0321-0000-0000-C000-000000000046>
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  IncrementRotationX, REAL4
  COM_MTD_STD  IncrementRotationY, REAL4
  COM_MTD_STD  ResetRotation
  COM_MTD_STD  SetThreeDFormat;, MsoPresetThreeDFormat
  COM_MTD_STD  SetExtrusionDirection;, MsoPresetExtrusionDirection
  COM_MTD_STD  get_Depth, ptr REAL4
  COM_MTD_STD  put_Depth, REAL4
  COM_MTD_STD  get_ExtrusionColor, ptr ptr ColorFormat
  COM_MTD_STD  get_ExtrusionColorType, ptr MsoExtrusionColorType
  COM_MTD_STD  put_ExtrusionColorType, MsoExtrusionColorType
  COM_MTD_STD  get_Perspective, ptr MsoTriState
  COM_MTD_STD  put_Perspective, MsoTriState
  COM_MTD_STD  get_PresetExtrusionDirection, ptr MsoPresetExtrusionDirection
  COM_MTD_STD  get_PresetLightingDirection, ptr MsoPresetLightingDirection
  COM_MTD_STD  put_PresetLightingDirection, MsoPresetLightingDirection
  COM_MTD_STD  get_PresetLightingSoftness, ptr MsoPresetLightingSoftness
  COM_MTD_STD  put_PresetLightingSoftness, MsoPresetLightingSoftness
  COM_MTD_STD  get_PresetMaterial, ptr MsoPresetMaterial
  COM_MTD_STD  put_PresetMaterial, MsoPresetMaterial
  COM_MTD_STD  get_PresetThreeDFormat, ptr MsoPresetThreeDFormat
  COM_MTD_STD  get_RotationX, ptr REAL4
  COM_MTD_STD  put_RotationX, REAL4
  COM_MTD_STD  get_RotationY, ptr REAL4
  COM_MTD_STD  put_RotationY, REAL4
  COM_MTD_STD  get_Visible, ptr MsoTriState
  COM_MTD_STD  put_Visible, MsoTriState
COM_INTERFACE_END

;Rename from IFont to IExcelFont
COM_INTERFACE_BEG IExcelFont, IDispatch, <0002084D-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Background, ptr VARIANT
  COM_MTD_STD  put_Background, VARIANT
  COM_MTD_STD  get_Bold, ptr VARIANT
  COM_MTD_STD  put_Bold, VARIANT
  COM_MTD_STD  get_Color, ptr VARIANT
  COM_MTD_STD  put_Color, VARIANT
  COM_MTD_STD  get_ColorIndex, ptr VARIANT
  COM_MTD_STD  put_ColorIndex, VARIANT
  COM_MTD_STD  get_FontStyle, ptr VARIANT
  COM_MTD_STD  put_FontStyle, VARIANT
  COM_MTD_STD  get_Italic, ptr VARIANT
  COM_MTD_STD  put_Italic, VARIANT
  COM_MTD_STD  get_Name, ptr VARIANT
  COM_MTD_STD  put_Name, VARIANT
  COM_MTD_STD  get_OutlineFont, ptr VARIANT
  COM_MTD_STD  put_OutlineFont, VARIANT
  COM_MTD_STD  get_Shadow, ptr VARIANT
  COM_MTD_STD  put_Shadow, VARIANT
  COM_MTD_STD  get_Size, ptr VARIANT
  COM_MTD_STD  put_Size, VARIANT
  COM_MTD_STD  get_Strikethrough, ptr VARIANT
  COM_MTD_STD  put_Strikethrough, VARIANT
  COM_MTD_STD  get_Subscript, ptr VARIANT
  COM_MTD_STD  put_Subscript, VARIANT
  COM_MTD_STD  get_Superscript, ptr VARIANT
  COM_MTD_STD  put_Superscript, VARIANT
  COM_MTD_STD  get_Underline, ptr VARIANT
  COM_MTD_STD  put_Underline, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG IWindow, IDispatch, <00020893-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Activate, ptr VARIANT
  COM_MTD_STD  ActivateNext, ptr VARIANT
  COM_MTD_STD  ActivatePrevious, ptr VARIANT
  COM_MTD_STD  get_ActiveCell, ptr ptr Range
  COM_MTD_STD  get_ActiveChart, ptr ptr Chart
  COM_MTD_STD  get_ActivePane, ptr ptr Pane
  COM_MTD_STD  get_ActiveSheet, ptr LPDISPATCH
  COM_MTD_STD  get_Caption, ptr VARIANT
  COM_MTD_STD  put_Caption, VARIANT
  COM_MTD_STD  Close, VARIANT, VARIANT, VARIANT, ptr BOOL
  COM_MTD_STD  get_DisplayFormulas, ptr BOOL
  COM_MTD_STD  put_DisplayFormulas, BOOL
  COM_MTD_STD  get_DisplayGridlines, ptr BOOL
  COM_MTD_STD  put_DisplayGridlines, BOOL
  COM_MTD_STD  get_DisplayHeadings, ptr BOOL
  COM_MTD_STD  put_DisplayHeadings, BOOL
  COM_MTD_STD  get_DisplayHorizontalScrollBar, ptr BOOL
  COM_MTD_STD  put_DisplayHorizontalScrollBar, BOOL
  COM_MTD_STD  get_DisplayOutline, ptr BOOL
  COM_MTD_STD  put_DisplayOutline, BOOL
  COM_MTD_STD  get__DisplayRightToLeft, ptr BOOL
  COM_MTD_STD  put__DisplayRightToLeft, BOOL
  COM_MTD_STD  get_DisplayVerticalScrollBar, ptr BOOL
  COM_MTD_STD  put_DisplayVerticalScrollBar, BOOL
  COM_MTD_STD  get_DisplayWorkbookTabs, ptr BOOL
  COM_MTD_STD  put_DisplayWorkbookTabs, BOOL
  COM_MTD_STD  get_DisplayZeros, ptr BOOL
  COM_MTD_STD  put_DisplayZeros, BOOL
  COM_MTD_STD  get_EnableResize, ptr BOOL
  COM_MTD_STD  put_EnableResize, BOOL
  COM_MTD_STD  get_FreezePanes, ptr BOOL
  COM_MTD_STD  put_FreezePanes, BOOL
  COM_MTD_STD  get_GridlineColor, ptr SDWORD
  COM_MTD_STD  put_GridlineColor, SDWORD
  COM_MTD_STD  get_GridlineColorIndex, ptr XlColorIndex
  COM_MTD_STD  put_GridlineColorIndex, XlColorIndex
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  get_Index, ptr SDWORD
  COM_MTD_STD  LargeScroll, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  NewWindow, ptr ptr Window
  COM_MTD_STD  get_OnWindow, ptr BSTR
  COM_MTD_STD  put_OnWindow, BSTR
  COM_MTD_STD  get_Panes, ptr ptr Panes
  COM_MTD_STD  PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  PrintPreview, VARIANT, ptr VARIANT
  COM_MTD_STD  get_RangeSelection, ptr ptr Range
  COM_MTD_STD  get_ScrollColumn, ptr SDWORD
  COM_MTD_STD  put_ScrollColumn, SDWORD
  COM_MTD_STD  get_ScrollRow, ptr SDWORD
  COM_MTD_STD  put_ScrollRow, SDWORD
  COM_MTD_STD  ScrollWorkbookTabs, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_SelectedSheets, ptr ptr Sheets
  COM_MTD_STD  get_Selection, ptr LPDISPATCH
  COM_MTD_STD  SmallScroll, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_Split, ptr BOOL
  COM_MTD_STD  put_Split, BOOL
  COM_MTD_STD  get_SplitColumn, ptr SDWORD
  COM_MTD_STD  put_SplitColumn, SDWORD
  COM_MTD_STD  get_SplitHorizontal, ptr REAL8
  COM_MTD_STD  put_SplitHorizontal, REAL8
  COM_MTD_STD  get_SplitRow, ptr SDWORD
  COM_MTD_STD  put_SplitRow, SDWORD
  COM_MTD_STD  get_SplitVertical, ptr REAL8
  COM_MTD_STD  put_SplitVertical, REAL8
  COM_MTD_STD  get_TabRatio, ptr REAL8
  COM_MTD_STD  put_TabRatio, REAL8
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  get_Type, ptr XlWindowType
  COM_MTD_STD  get_UsableHeight, ptr REAL8
  COM_MTD_STD  get_UsableWidth, ptr REAL8
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_VisibleRange, ptr ptr Range
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_WindowNumber, ptr SDWORD
  COM_MTD_STD  get_WindowState, ptr XlWindowState
  COM_MTD_STD  put_WindowState, XlWindowState
  COM_MTD_STD  get_Zoom, ptr VARIANT
  COM_MTD_STD  put_Zoom, VARIANT
  COM_MTD_STD  get_View, ptr XlWindowView
  COM_MTD_STD  put_View, XlWindowView
  COM_MTD_STD  get_DisplayRightToLeft, ptr BOOL
  COM_MTD_STD  put_DisplayRightToLeft, BOOL
  COM_MTD_STD  PointsToScreenPixelsX, SDWORD, ptr SDWORD
  COM_MTD_STD  PointsToScreenPixelsY, SDWORD, ptr SDWORD
  COM_MTD_STD  RangeFromPoint, SDWORD, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  ScrollIntoView, SDWORD, SDWORD, SDWORD, SDWORD, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG IWindows, IDispatch, <00020892-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Arrange, XlArrangeStyle, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  get_Item, VARIANT, ptr ptr Window
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  get__Default, VARIANT, ptr ptr Window
COM_INTERFACE_END

COM_INTERFACE_BEG IAppEvents, IDispatch, <00024413-0001-0000-C000-000000000046>
  COM_MTD_STD  NewWorkbook, ptr Workbook
  COM_MTD_STD  SheetSelectionChange, LPDISPATCH, ptr Range
  COM_MTD_STD  SheetBeforeDoubleClick, LPDISPATCH, ptr Range, ptr BOOL
  COM_MTD_STD  SheetBeforeRightClick, LPDISPATCH, ptr Range, ptr BOOL
  COM_MTD_STD  SheetActivate, LPDISPATCH
  COM_MTD_STD  SheetDeactivate, LPDISPATCH
  COM_MTD_STD  SheetCalculate, LPDISPATCH
  COM_MTD_STD  SheetChange, LPDISPATCH, ptr Range
  COM_MTD_STD  WorkbookOpen, ptr Workbook
  COM_MTD_STD  WorkbookActivate, ptr Workbook
  COM_MTD_STD  WorkbookDeactivate, ptr Workbook
  COM_MTD_STD  WorkbookBeforeClose, ptr Workbook, ptr BOOL
  COM_MTD_STD  WorkbookBeforeSave, ptr Workbook, BOOL, ptr BOOL
  COM_MTD_STD  WorkbookBeforePrint, ptr Workbook, ptr BOOL
  COM_MTD_STD  WorkbookNewSheet, ptr Workbook, LPDISPATCH
  COM_MTD_STD  WorkbookAddinInstall, ptr Workbook
  COM_MTD_STD  WorkbookAddinUninstall, ptr Workbook
  COM_MTD_STD  WindowResize, ptr Workbook, ptr Window
  COM_MTD_STD  WindowActivate, ptr Workbook, ptr Window
  COM_MTD_STD  WindowDeactivate, ptr Workbook, ptr Window
  COM_MTD_STD  SheetFollowHyperlink, LPDISPATCH, ptr Hyperlink
  COM_MTD_STD  SheetPivotTableUpdate, LPDISPATCH, ptr PivotTable
  COM_MTD_STD  WorkbookPivotTableCloseConnection, ptr Workbook, ptr PivotTable
  COM_MTD_STD  WorkbookPivotTableOpenConnection, ptr Workbook, ptr PivotTable
COM_INTERFACE_END

COM_INTERFACE_BEG _Application, IDispatch, <000208D5-0000-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr ptr Application
  COM_MTD_STD  get_ActiveCell, ptr ptr Range
  COM_MTD_STD  get_ActiveChart, ptr ptr Chart
  COM_MTD_STD  get_ActiveDialog, ptr ptr DialogSheet
  COM_MTD_STD  get_ActiveMenuBar, ptr ptr MenuBar
  COM_MTD_STD  get_ActivePrinter, SDWORD, ptr BSTR
  COM_MTD_STD  put_ActivePrinter, SDWORD, BSTR
  COM_MTD_STD  get_ActiveSheet, ptr LPDISPATCH
  COM_MTD_STD  get_ActiveWindow, ptr ptr Window
  COM_MTD_STD  get_ActiveWorkbook, ptr ptr Workbook
  COM_MTD_STD  get_AddIns, ptr ptr AddIns
  COM_MTD_STD  get_Assistant, ptr ptr Assistant
  COM_MTD_STD  Calculate, SDWORD
  COM_MTD_STD  get_Cells, ptr ptr Range
  COM_MTD_STD  get_Charts, ptr ptr Sheets
  COM_MTD_STD  get_Columns, ptr ptr Range
  COM_MTD_STD  get_CommandBars, ptr ptr CommandBars
  COM_MTD_STD  get_DDEAppReturnCode, SDWORD, ptr SDWORD
  COM_MTD_STD  DDEExecute, SDWORD, BSTR, SDWORD
  COM_MTD_STD  DDEInitiate, BSTR, BSTR, SDWORD, ptr SDWORD
  COM_MTD_STD  DDEPoke, SDWORD, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  DDERequest, SDWORD, BSTR, SDWORD, ptr VARIANT
  COM_MTD_STD  DDETerminate, SDWORD, SDWORD
  COM_MTD_STD  get_DialogSheets, ptr ptr Sheets
  COM_MTD_STD  Evaluate, VARIANT, SDWORD, ptr VARIANT
  COM_MTD_STD  _Evaluate, VARIANT, SDWORD, ptr VARIANT
  COM_MTD_STD  ExecuteExcel4Macro, BSTR, SDWORD, ptr VARIANT
;+++   COM_MTD_STD  Intersect, ptr Range, ptr Range, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD, ptr ptr Range
  COM_MTD_STD  Intersect, DWORD
  COM_MTD_STD  get_MenuBars, ptr ptr MenuBars
  COM_MTD_STD  get_Modules, ptr ptr Modules
  COM_MTD_STD  get_Names, ptr ptr Names
  COM_MTD_STD  get_Range, VARIANT, VARIANT, ptr ptr Range
  COM_MTD_STD  get_Rows, ptr ptr Range
;+++   COM_MTD_STD  Run, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  Run, DWORD
;+++   COM_MTD_STD  _Run2, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD, ptr VARIANT
  COM_MTD_STD  _Run2, DWORD
  COM_MTD_STD  get_Selection, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  SendKeys, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get_Sheets, ptr ptr Sheets
  COM_MTD_STD  get_ShortcutMenus, SDWORD, ptr ptr Menu
  COM_MTD_STD  get_ThisWorkbook, SDWORD, ptr ptr Workbook
  COM_MTD_STD  get_Toolbars, ptr ptr Toolbars
;+++   COM_MTD_STD  Union_, ptr Range, ptr Range, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD, ptr ptr Range
  COM_MTD_STD  Union_, DWORD
  COM_MTD_STD  get_Windows, ptr ptr Windows
  COM_MTD_STD  get_Workbooks, ptr ptr Workbooks
  COM_MTD_STD  get_WorksheetFunction, ptr ptr WorksheetFunction
  COM_MTD_STD  get_Worksheets, ptr ptr Sheets
  COM_MTD_STD  get_Excel4IntlMacroSheets, ptr ptr Sheets
  COM_MTD_STD  get_Excel4MacroSheets, ptr ptr Sheets
  COM_MTD_STD  ActivateMicrosoftApp, XlMSApplication, SDWORD
  COM_MTD_STD  AddChartAutoFormat, VARIANT, BSTR, VARIANT, SDWORD
  COM_MTD_STD  AddCustomList, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get_AlertBeforeOverwriting, SDWORD, ptr BOOL
  COM_MTD_STD  put_AlertBeforeOverwriting, SDWORD, BOOL
  COM_MTD_STD  get_AltStartupPath, SDWORD, ptr BSTR
  COM_MTD_STD  put_AltStartupPath, SDWORD, BSTR
  COM_MTD_STD  get_AskToUpdateLinks, SDWORD, ptr BOOL
  COM_MTD_STD  put_AskToUpdateLinks, SDWORD, BOOL
  COM_MTD_STD  get_EnableAnimations, SDWORD, ptr BOOL
  COM_MTD_STD  put_EnableAnimations, SDWORD, BOOL
  COM_MTD_STD  get_AutoCorrect, ptr ptr AutoCorrect
  COM_MTD_STD  get_Build, SDWORD, ptr SDWORD
  COM_MTD_STD  get_CalculateBeforeSave, SDWORD, ptr BOOL
  COM_MTD_STD  put_CalculateBeforeSave, SDWORD, BOOL
  COM_MTD_STD  get_Calculation, SDWORD, ptr XlCalculation
  COM_MTD_STD  put_Calculation, SDWORD, XlCalculation
  COM_MTD_STD  get_Caller, VARIANT, SDWORD, ptr VARIANT
  COM_MTD_STD  get_CanPlaySounds, SDWORD, ptr BOOL
  COM_MTD_STD  get_CanRecordSounds, SDWORD, ptr BOOL
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_CellDragAndDrop, SDWORD, ptr BOOL
  COM_MTD_STD  put_CellDragAndDrop, SDWORD, BOOL
  COM_MTD_STD  CentimetersToPoints, REAL8, SDWORD, ptr REAL8
  COM_MTD_STD  CheckSpelling, BSTR, VARIANT, VARIANT, SDWORD, ptr BOOL
  COM_MTD_STD  get_ClipboardFormats, VARIANT, SDWORD, ptr VARIANT
  COM_MTD_STD  get_DisplayClipboardWindow, SDWORD, ptr BOOL
  COM_MTD_STD  put_DisplayClipboardWindow, SDWORD, BOOL
  COM_MTD_STD  get_ColorButtons, ptr BOOL
  COM_MTD_STD  put_ColorButtons, BOOL
  COM_MTD_STD  get_CommandUnderlines, SDWORD, ptr XlCommandUnderlines
  COM_MTD_STD  put_CommandUnderlines, SDWORD, XlCommandUnderlines
  COM_MTD_STD  get_ConstrainNumeric, SDWORD, ptr BOOL
  COM_MTD_STD  put_ConstrainNumeric, SDWORD, BOOL
  COM_MTD_STD  ConvertFormula, VARIANT, XlReferenceStyle, VARIANT, VARIANT, VARIANT, SDWORD, ptr VARIANT
  COM_MTD_STD  get_CopyObjectsWithCells, SDWORD, ptr BOOL
  COM_MTD_STD  put_CopyObjectsWithCells, SDWORD, BOOL
  COM_MTD_STD  get_Cursor, SDWORD, ptr XlMousePointer
  COM_MTD_STD  put_Cursor, SDWORD, XlMousePointer
  COM_MTD_STD  get_CustomListCount, SDWORD, ptr SDWORD
  COM_MTD_STD  get_CutCopyMode, SDWORD, ptr XlCutCopyMode
  COM_MTD_STD  put_CutCopyMode, SDWORD, XlCutCopyMode
  COM_MTD_STD  get_DataEntryMode, SDWORD, ptr SDWORD
  COM_MTD_STD  put_DataEntryMode, SDWORD, SDWORD
  COM_MTD_STD  Dummy1, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  Dummy2, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  Dummy3, ptr VARIANT
  COM_MTD_STD  Dummy4, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  Dummy5, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  Dummy6, ptr VARIANT
  COM_MTD_STD  Dummy7, ptr VARIANT
  COM_MTD_STD  Dummy8, VARIANT, ptr VARIANT
  COM_MTD_STD  Dummy9, ptr VARIANT
  COM_MTD_STD  Dummy10, VARIANT, ptr BOOL
  COM_MTD_STD  Dummy11
  COM_MTD_STD  get__Default, ptr BSTR
  COM_MTD_STD  get_DefaultFilePath, SDWORD, ptr BSTR
  COM_MTD_STD  put_DefaultFilePath, SDWORD, BSTR
  COM_MTD_STD  DeleteChartAutoFormat, BSTR, SDWORD
  COM_MTD_STD  DeleteCustomList, SDWORD, SDWORD
  COM_MTD_STD  get_Dialogs, ptr ptr Dialogs
  COM_MTD_STD  get_DisplayAlerts, SDWORD, ptr BOOL
  COM_MTD_STD  put_DisplayAlerts, SDWORD, BOOL
  COM_MTD_STD  get_DisplayFormulaBar, SDWORD, ptr BOOL
  COM_MTD_STD  put_DisplayFormulaBar, SDWORD, BOOL
  COM_MTD_STD  get_DisplayFullScreen, SDWORD, ptr BOOL
  COM_MTD_STD  put_DisplayFullScreen, SDWORD, BOOL
  COM_MTD_STD  get_DisplayNoteIndicator, ptr BOOL
  COM_MTD_STD  put_DisplayNoteIndicator, BOOL
  COM_MTD_STD  get_DisplayCommentIndicator, ptr XlCommentDisplayMode
  COM_MTD_STD  put_DisplayCommentIndicator, XlCommentDisplayMode
  COM_MTD_STD  get_DisplayExcel4Menus, SDWORD, ptr BOOL
  COM_MTD_STD  put_DisplayExcel4Menus, SDWORD, BOOL
  COM_MTD_STD  get_DisplayRecentFiles, ptr BOOL
  COM_MTD_STD  put_DisplayRecentFiles, BOOL
  COM_MTD_STD  get_DisplayScrollBars, SDWORD, ptr BOOL
  COM_MTD_STD  put_DisplayScrollBars, SDWORD, BOOL
  COM_MTD_STD  get_DisplayStatusBar, SDWORD, ptr BOOL
  COM_MTD_STD  put_DisplayStatusBar, SDWORD, BOOL
  COM_MTD_STD  DoubleClick, SDWORD
  COM_MTD_STD  get_EditDirectlyInCell, SDWORD, ptr BOOL
  COM_MTD_STD  put_EditDirectlyInCell, SDWORD, BOOL
  COM_MTD_STD  get_EnableAutoComplete, ptr BOOL
  COM_MTD_STD  put_EnableAutoComplete, BOOL
  COM_MTD_STD  get_EnableCancelKey, SDWORD, ptr XlEnableCancelKey
  COM_MTD_STD  put_EnableCancelKey, SDWORD, XlEnableCancelKey
  COM_MTD_STD  get_EnableSound, ptr BOOL
  COM_MTD_STD  put_EnableSound, BOOL
  COM_MTD_STD  get_EnableTipWizard, SDWORD, ptr BOOL
  COM_MTD_STD  put_EnableTipWizard, SDWORD, BOOL
  COM_MTD_STD  get_FileConverters, VARIANT, VARIANT, SDWORD, ptr VARIANT
  COM_MTD_STD  get_FileSearch, ptr ptr FileSearch
  COM_MTD_STD  get_FileFind, ptr ptr IFind
  COM_MTD_STD  _FindFile, SDWORD
  COM_MTD_STD  get_FixedDecimal, SDWORD, ptr BOOL
  COM_MTD_STD  put_FixedDecimal, SDWORD, BOOL
  COM_MTD_STD  get_FixedDecimalPlaces, SDWORD, ptr SDWORD
  COM_MTD_STD  put_FixedDecimalPlaces, SDWORD, SDWORD
  COM_MTD_STD  GetCustomListContents, SDWORD, SDWORD, ptr VARIANT
  COM_MTD_STD  GetCustomListNum, VARIANT, SDWORD, ptr SDWORD
  COM_MTD_STD  GetOpenFilename, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD, ptr VARIANT
  COM_MTD_STD  GetSaveAsFilename, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD, ptr VARIANT
  COM_MTD_STD  Goto_, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get_Height, SDWORD, ptr REAL8
  COM_MTD_STD  put_Height, SDWORD, REAL8
  COM_MTD_STD  Help, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get_IgnoreRemoteRequests, SDWORD, ptr BOOL
  COM_MTD_STD  put_IgnoreRemoteRequests, SDWORD, BOOL
  COM_MTD_STD  InchesToPoints, REAL8, SDWORD, ptr REAL8
  COM_MTD_STD  InputBox, BSTR, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD, ptr VARIANT
  COM_MTD_STD  get_Interactive, SDWORD, ptr BOOL
  COM_MTD_STD  put_Interactive, SDWORD, BOOL
  COM_MTD_STD  get_International, VARIANT, SDWORD, ptr VARIANT
  COM_MTD_STD  get_Iteration, SDWORD, ptr BOOL
  COM_MTD_STD  put_Iteration, SDWORD, BOOL
  COM_MTD_STD  get_LargeButtons, ptr BOOL
  COM_MTD_STD  put_LargeButtons, BOOL
  COM_MTD_STD  get_Left, SDWORD, ptr REAL8
  COM_MTD_STD  put_Left, SDWORD, REAL8
  COM_MTD_STD  get_LibraryPath, SDWORD, ptr BSTR
  COM_MTD_STD  MacroOptions, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  MailLogoff, SDWORD
  COM_MTD_STD  MailLogon, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get_MailSession, SDWORD, ptr VARIANT
  COM_MTD_STD  get_MailSystem, SDWORD, ptr XlMailSystem
  COM_MTD_STD  get_MathCoprocessorAvailable, SDWORD, ptr BOOL
  COM_MTD_STD  get_MaxChange, SDWORD, ptr REAL8
  COM_MTD_STD  put_MaxChange, SDWORD, REAL8
  COM_MTD_STD  get_MaxIterations, SDWORD, ptr SDWORD
  COM_MTD_STD  put_MaxIterations, SDWORD, SDWORD
  COM_MTD_STD  get_MemoryFree, SDWORD, ptr SDWORD
  COM_MTD_STD  get_MemoryTotal, SDWORD, ptr SDWORD
  COM_MTD_STD  get_MemoryUsed, SDWORD, ptr SDWORD
  COM_MTD_STD  get_MouseAvailable, SDWORD, ptr BOOL
  COM_MTD_STD  get_MoveAfterReturn, SDWORD, ptr BOOL
  COM_MTD_STD  put_MoveAfterReturn, SDWORD, BOOL
  COM_MTD_STD  get_MoveAfterReturnDirection, SDWORD, ptr XlDirection
  COM_MTD_STD  put_MoveAfterReturnDirection, SDWORD, XlDirection
  COM_MTD_STD  get_RecentFiles, ptr ptr RecentFiles
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  NextLetter, SDWORD, ptr ptr Workbook
  COM_MTD_STD  get_NetworkTemplatesPath, SDWORD, ptr BSTR
  COM_MTD_STD  get_ODBCErrors, ptr ptr ODBCErrors
  COM_MTD_STD  get_ODBCTimeout, ptr SDWORD
  COM_MTD_STD  put_ODBCTimeout, SDWORD
  COM_MTD_STD  get_OnCalculate, SDWORD, ptr BSTR
  COM_MTD_STD  put_OnCalculate, SDWORD, BSTR
  COM_MTD_STD  get_OnData, SDWORD, ptr BSTR
  COM_MTD_STD  put_OnData, SDWORD, BSTR
  COM_MTD_STD  get_OnDoubleClick, SDWORD, ptr BSTR
  COM_MTD_STD  put_OnDoubleClick, SDWORD, BSTR
  COM_MTD_STD  get_OnEntry, SDWORD, ptr BSTR
  COM_MTD_STD  put_OnEntry, SDWORD, BSTR
  COM_MTD_STD  OnKey, BSTR, VARIANT, SDWORD
  COM_MTD_STD  OnRepeat, BSTR, BSTR, SDWORD
  COM_MTD_STD  get_OnSheetActivate, SDWORD, ptr BSTR
  COM_MTD_STD  put_OnSheetActivate, SDWORD, BSTR
  COM_MTD_STD  get_OnSheetDeactivate, SDWORD, ptr BSTR
  COM_MTD_STD  put_OnSheetDeactivate, SDWORD, BSTR
  COM_MTD_STD  OnTime, VARIANT, BSTR, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  OnUndo, BSTR, BSTR, SDWORD
  COM_MTD_STD  get_OnWindow, SDWORD, ptr BSTR
  COM_MTD_STD  put_OnWindow, SDWORD, BSTR
  COM_MTD_STD  get_OperatingSystem, SDWORD, ptr BSTR
  COM_MTD_STD  get_OrganizationName, SDWORD, ptr BSTR
  COM_MTD_STD  get_Path, SDWORD, ptr BSTR
  COM_MTD_STD  get_PathSeparator, SDWORD, ptr BSTR
  COM_MTD_STD  get_PreviousSelections, VARIANT, SDWORD, ptr VARIANT
  COM_MTD_STD  get_PivotTableSelection, ptr BOOL
  COM_MTD_STD  put_PivotTableSelection, BOOL
  COM_MTD_STD  get_PromptForSummaryInfo, SDWORD, ptr BOOL
  COM_MTD_STD  put_PromptForSummaryInfo, SDWORD, BOOL
  COM_MTD_STD  Quit
  COM_MTD_STD  RecordMacro, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get_RecordRelative, SDWORD, ptr BOOL
  COM_MTD_STD  get_ReferenceStyle, SDWORD, ptr XlReferenceStyle
  COM_MTD_STD  put_ReferenceStyle, SDWORD, XlReferenceStyle
  COM_MTD_STD  get_RegisteredFunctions, VARIANT, VARIANT, SDWORD, ptr VARIANT
  COM_MTD_STD  RegisterXLL, BSTR, SDWORD, ptr BOOL
  COM_MTD_STD  Repeat_, SDWORD
  COM_MTD_STD  ResetTipWizard, SDWORD
  COM_MTD_STD  get_RollZoom, ptr BOOL
  COM_MTD_STD  put_RollZoom, BOOL
  COM_MTD_STD  Save, VARIANT, SDWORD
  COM_MTD_STD  SaveWorkspace, VARIANT, SDWORD
  COM_MTD_STD  get_ScreenUpdating, SDWORD, ptr BOOL
  COM_MTD_STD  put_ScreenUpdating, SDWORD, BOOL
  COM_MTD_STD  SetDefaultChart, VARIANT, VARIANT
  COM_MTD_STD  get_SheetsInNewWorkbook, SDWORD, ptr SDWORD
  COM_MTD_STD  put_SheetsInNewWorkbook, SDWORD, SDWORD
  COM_MTD_STD  get_ShowChartTipNames, ptr BOOL
  COM_MTD_STD  put_ShowChartTipNames, BOOL
  COM_MTD_STD  get_ShowChartTipValues, ptr BOOL
  COM_MTD_STD  put_ShowChartTipValues, BOOL
  COM_MTD_STD  get_StandardFont, SDWORD, ptr BSTR
  COM_MTD_STD  put_StandardFont, SDWORD, BSTR
  COM_MTD_STD  get_StandardFontSize, SDWORD, ptr REAL8
  COM_MTD_STD  put_StandardFontSize, SDWORD, REAL8
  COM_MTD_STD  get_StartupPath, SDWORD, ptr BSTR
  COM_MTD_STD  get_StatusBar, SDWORD, ptr VARIANT
  COM_MTD_STD  put_StatusBar, SDWORD, VARIANT
  COM_MTD_STD  get_TemplatesPath, SDWORD, ptr BSTR
  COM_MTD_STD  get_ShowToolTips, ptr BOOL
  COM_MTD_STD  put_ShowToolTips, BOOL
  COM_MTD_STD  get_Top, SDWORD, ptr REAL8
  COM_MTD_STD  put_Top, SDWORD, REAL8
  COM_MTD_STD  get_DefaultSaveFormat, ptr XlFileFormat
  COM_MTD_STD  put_DefaultSaveFormat, XlFileFormat
  COM_MTD_STD  get_TransitionMenuKey, SDWORD, ptr BSTR
  COM_MTD_STD  put_TransitionMenuKey, SDWORD, BSTR
  COM_MTD_STD  get_TransitionMenuKeyAction, SDWORD, ptr SDWORD
  COM_MTD_STD  put_TransitionMenuKeyAction, SDWORD, SDWORD
  COM_MTD_STD  get_TransitionNavigKeys, SDWORD, ptr BOOL
  COM_MTD_STD  put_TransitionNavigKeys, SDWORD, BOOL
  COM_MTD_STD  Undo, SDWORD
  COM_MTD_STD  get_UsableHeight, SDWORD, ptr REAL8
  COM_MTD_STD  get_UsableWidth, SDWORD, ptr REAL8
  COM_MTD_STD  get_UserControl, ptr BOOL
  COM_MTD_STD  put_UserControl, BOOL
  COM_MTD_STD  get_UserName, SDWORD, ptr BSTR
  COM_MTD_STD  put_UserName, SDWORD, BSTR
  COM_MTD_STD  get_Value, ptr BSTR
  COM_MTD_STD  get_VBE, ptr ptr VBE
  COM_MTD_STD  get_Version, SDWORD, ptr BSTR
  COM_MTD_STD  get_Visible, SDWORD, ptr BOOL
  COM_MTD_STD  put_Visible, SDWORD, BOOL
  COM_MTD_STD  Volatile, VARIANT, SDWORD
  COM_MTD_STD  _Wait, VARIANT, SDWORD
  COM_MTD_STD  get_Width, SDWORD, ptr REAL8
  COM_MTD_STD  put_Width, SDWORD, REAL8
  COM_MTD_STD  get_WindowsForPens, SDWORD, ptr BOOL
  COM_MTD_STD  get_WindowState, SDWORD, ptr XlWindowState
  COM_MTD_STD  put_WindowState, SDWORD, XlWindowState
  COM_MTD_STD  get_UILanguage, SDWORD, ptr SDWORD
  COM_MTD_STD  put_UILanguage, SDWORD, SDWORD
  COM_MTD_STD  get_DefaultSheetDirection, SDWORD, ptr SDWORD
  COM_MTD_STD  put_DefaultSheetDirection, SDWORD, SDWORD
  COM_MTD_STD  get_CursorMovement, SDWORD, ptr SDWORD
  COM_MTD_STD  put_CursorMovement, SDWORD, SDWORD
  COM_MTD_STD  get_ControlCharacters, SDWORD, ptr BOOL
  COM_MTD_STD  put_ControlCharacters, SDWORD, BOOL
;+++   COM_MTD_STD  _WSFunction, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD, ptr VARIANT
  COM_MTD_STD  _WSFunction, DWORD
  COM_MTD_STD  get_EnableEvents, ptr BOOL
  COM_MTD_STD  put_EnableEvents, BOOL
  COM_MTD_STD  get_DisplayInfoWindow, ptr BOOL
  COM_MTD_STD  put_DisplayInfoWindow, BOOL
  COM_MTD_STD  Wait_, VARIANT, SDWORD, ptr BOOL
  COM_MTD_STD  get_ExtendList, ptr BOOL
  COM_MTD_STD  put_ExtendList, BOOL
  COM_MTD_STD  get_OLEDBErrors, ptr ptr OLEDBErrors
  COM_MTD_STD  GetPhonetic, VARIANT, ptr BSTR
  COM_MTD_STD  get_COMAddIns, ptr ptr COMAddIns
  COM_MTD_STD  get_DefaultWebOptions, ptr ptr DefaultWebOptions
  COM_MTD_STD  get_ProductCode, ptr BSTR
  COM_MTD_STD  get_UserLibraryPath, ptr BSTR
  COM_MTD_STD  get_AutoPercentEntry, ptr BOOL
  COM_MTD_STD  put_AutoPercentEntry, BOOL
  COM_MTD_STD  get_LanguageSettings, ptr ptr LanguageSettings
  COM_MTD_STD  get_Dummy101, ptr LPDISPATCH
  COM_MTD_STD  Dummy12, ptr PivotTable, ptr PivotTable
  COM_MTD_STD  get_AnswerWizard, ptr ptr AnswerWizard
  COM_MTD_STD  CalculateFull
  COM_MTD_STD  FindFile, SDWORD, ptr BOOL
  COM_MTD_STD  get_CalculationVersion, ptr SDWORD
  COM_MTD_STD  get_ShowWindowsInTaskbar, ptr BOOL
  COM_MTD_STD  put_ShowWindowsInTaskbar, BOOL
  COM_MTD_STD  get_FeatureInstall, ptr MsoFeatureInstall
  COM_MTD_STD  put_FeatureInstall, MsoFeatureInstall
  COM_MTD_STD  get_Ready, ptr BOOL
;+++   COM_MTD_STD  Dummy13, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  Dummy13, DWORD
  COM_MTD_STD  get_FindFormat, ptr ptr CellFormat
  COM_MTD_STD  putref_FindFormat, ptr CellFormat
  COM_MTD_STD  get_ReplaceFormat, ptr ptr CellFormat
  COM_MTD_STD  putref_ReplaceFormat, ptr CellFormat
  COM_MTD_STD  get_UsedObjects, ptr ptr UsedObjects
  COM_MTD_STD  get_CalculationState, ptr XlCalculationState
  COM_MTD_STD  get_CalculationInterruptKey, ptr XlCalculationInterruptKey
  COM_MTD_STD  put_CalculationInterruptKey, XlCalculationInterruptKey
  COM_MTD_STD  get_Watches, ptr ptr Watches
  COM_MTD_STD  get_DisplayFunctionToolTips, ptr BOOL
  COM_MTD_STD  put_DisplayFunctionToolTips, BOOL
  COM_MTD_STD  get_AutomationSecurity, ptr MsoAutomationSecurity
  COM_MTD_STD  put_AutomationSecurity, MsoAutomationSecurity
  COM_MTD_STD  get_FileDialog;, MsoFileDialogType, ptr ptr FileDialog
  COM_MTD_STD  Dummy14
  COM_MTD_STD  CalculateFullRebuild
  COM_MTD_STD  get_DisplayPasteOptions, ptr BOOL
  COM_MTD_STD  put_DisplayPasteOptions, BOOL
  COM_MTD_STD  get_DisplayInsertOptions, ptr BOOL
  COM_MTD_STD  put_DisplayInsertOptions, BOOL
  COM_MTD_STD  get_GenerateGetPivotData, ptr BOOL
  COM_MTD_STD  put_GenerateGetPivotData, BOOL
  COM_MTD_STD  get_AutoRecover, ptr ptr AutoRecover
  COM_MTD_STD  get_Hwnd, ptr SDWORD
  COM_MTD_STD  get_Hinstance, ptr SDWORD
  COM_MTD_STD  CheckAbort, VARIANT
  COM_MTD_STD  get_ErrorCheckingOptions, ptr ptr ErrorCheckingOptions
  COM_MTD_STD  get_AutoFormatAsYouTypeReplaceHyperlinks, ptr BOOL
  COM_MTD_STD  put_AutoFormatAsYouTypeReplaceHyperlinks, BOOL
  COM_MTD_STD  get_SmartTagRecognizers, ptr ptr SmartTagRecognizers
  COM_MTD_STD  get_NewWorkbook, ptr ptr NewFile
  COM_MTD_STD  get_SpellingOptions, ptr ptr SpellingOptions
  COM_MTD_STD  get_Speech, ptr ptr Speech
  COM_MTD_STD  get_MapPaperSize, ptr BOOL
  COM_MTD_STD  put_MapPaperSize, BOOL
  COM_MTD_STD  get_ShowStartupDialog, ptr BOOL
  COM_MTD_STD  put_ShowStartupDialog, BOOL
  COM_MTD_STD  get_DecimalSeparator, ptr BSTR
  COM_MTD_STD  put_DecimalSeparator, BSTR
  COM_MTD_STD  get_ThousandsSeparator, ptr BSTR
  COM_MTD_STD  put_ThousandsSeparator, BSTR
  COM_MTD_STD  get_UseSystemSeparators, ptr BOOL
  COM_MTD_STD  put_UseSystemSeparators, BOOL
  COM_MTD_STD  get_ThisCell, ptr ptr Range
  COM_MTD_STD  get_RTD, ptr ptr RTD
COM_INTERFACE_END

COM_INTERFACE_BEG IWorksheetFunction, IDispatch, <00020845-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
;+++   COM_MTD_STD  _WSFunction, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  _WSFunction, DWORD
;+++   COM_MTD_STD  Count, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  Count, DWORD
  COM_MTD_STD  IsNA, VARIANT, ptr BOOL
  COM_MTD_STD  IsError, VARIANT, ptr BOOL
;+++   COM_MTD_STD  Sum, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  Sum, DWORD
;+++   COM_MTD_STD  Average, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  Average, DWORD
;+++   COM_MTD_STD  Min, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  _Min, DWORD
;+++   COM_MTD_STD  Max, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  _Max, DWORD
;+++   COM_MTD_STD  Npv, REAL8, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  Npv, DWORD
;+++   COM_MTD_STD  StDev, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  StDev, DWORD
  COM_MTD_STD  Dollar, REAL8, VARIANT, ptr BSTR
  COM_MTD_STD  Fixed, REAL8, VARIANT, VARIANT, ptr BSTR
  COM_MTD_STD  Pi, ptr REAL8
  COM_MTD_STD  Ln, REAL8, ptr REAL8
  COM_MTD_STD  Log10, REAL8, ptr REAL8
  COM_MTD_STD  Round, REAL8, REAL8, ptr REAL8
  COM_MTD_STD  Lookup, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  Index_, VARIANT, REAL8, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  Rept_, BSTR, REAL8, ptr BSTR
;+++   COM_MTD_STD  And_, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr BOOL
  COM_MTD_STD  And_, DWORD
;+++   COM_MTD_STD  Or_, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr BOOL
  COM_MTD_STD  Or_, DWORD
  COM_MTD_STD  DCount, ptr Range, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  DSum, ptr Range, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  DAverage, ptr Range, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  DMin, ptr Range, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  DMax, ptr Range, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  DStDev, ptr Range, VARIANT, VARIANT, ptr REAL8
;+++   COM_MTD_STD  Var, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  Var, DWORD
  COM_MTD_STD  DVar, ptr Range, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  Text, VARIANT, BSTR, ptr BSTR
  COM_MTD_STD  LinEst, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  Trend, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  LogEst, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  Growth, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  Pv, REAL8, REAL8, REAL8, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  Fv, REAL8, REAL8, REAL8, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  NPer, REAL8, REAL8, REAL8, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  Pmt, REAL8, REAL8, REAL8, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  Rate, REAL8, REAL8, REAL8, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  MIrr, VARIANT, REAL8, REAL8, ptr REAL8
  COM_MTD_STD  Irr, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  Match, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  Weekday, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  Search, BSTR, BSTR, VARIANT, ptr REAL8
  COM_MTD_STD  Transpose, VARIANT, ptr VARIANT
  COM_MTD_STD  Atan2, REAL8, REAL8, ptr REAL8
  COM_MTD_STD  Asin, REAL8, ptr REAL8
  COM_MTD_STD  Acos, REAL8, ptr REAL8
;+++   COM_MTD_STD  Choose, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  _Choose, DWORD
  COM_MTD_STD  HLookup, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  VLookup, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  Log, REAL8, VARIANT, ptr REAL8
  COM_MTD_STD  Proper, BSTR, ptr BSTR
  COM_MTD_STD  Trim, BSTR, ptr BSTR
  COM_MTD_STD  Replace, BSTR, REAL8, REAL8, BSTR, ptr BSTR
  COM_MTD_STD  Substitute, BSTR, BSTR, BSTR, VARIANT, ptr BSTR
  COM_MTD_STD  Find, BSTR, BSTR, VARIANT, ptr REAL8
  COM_MTD_STD  IsErr, VARIANT, ptr BOOL
  COM_MTD_STD  IsText, VARIANT, ptr BOOL
  COM_MTD_STD  IsNumber, VARIANT, ptr BOOL
  COM_MTD_STD  Sln, REAL8, REAL8, REAL8, ptr REAL8
  COM_MTD_STD  Syd, REAL8, REAL8, REAL8, REAL8, ptr REAL8
  COM_MTD_STD  Ddb, REAL8, REAL8, REAL8, REAL8, VARIANT, ptr REAL8
  COM_MTD_STD  Clean, BSTR, ptr BSTR
  COM_MTD_STD  MDeterm, VARIANT, ptr REAL8
  COM_MTD_STD  MInverse, VARIANT, ptr VARIANT
  COM_MTD_STD  MMult, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  Ipmt, REAL8, REAL8, REAL8, REAL8, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  Ppmt, REAL8, REAL8, REAL8, REAL8, VARIANT, VARIANT, ptr REAL8
;+++   COM_MTD_STD  CountA, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  CountA, DWORD
;+++   COM_MTD_STD  Product, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  Product, DWORD
  COM_MTD_STD  Fact, REAL8, ptr REAL8
  COM_MTD_STD  DProduct, ptr Range, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  IsNonText, VARIANT, ptr BOOL
;+++   COM_MTD_STD  StDevP, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  StDevP, DWORD
;+++   COM_MTD_STD  VarP, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  VarP, DWORD
  COM_MTD_STD  DStDevP, ptr Range, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  DVarP, ptr Range, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  IsLogical, VARIANT, ptr BOOL
  COM_MTD_STD  DCountA, ptr Range, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  USDollar, REAL8, REAL8, ptr BSTR
  COM_MTD_STD  FindB, BSTR, BSTR, VARIANT, ptr REAL8
  COM_MTD_STD  SearchB, BSTR, BSTR, VARIANT, ptr REAL8
  COM_MTD_STD  ReplaceB, BSTR, REAL8, REAL8, BSTR, ptr BSTR
  COM_MTD_STD  RoundUp, REAL8, REAL8, ptr REAL8
  COM_MTD_STD  RoundDown, REAL8, REAL8, ptr REAL8
  COM_MTD_STD  Rank, REAL8, ptr Range, VARIANT, ptr REAL8
  COM_MTD_STD  Days360, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  Vdb, REAL8, REAL8, REAL8, REAL8, REAL8, VARIANT, VARIANT, ptr REAL8
;+++   COM_MTD_STD  Median, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  Median, DWORD
;+++   COM_MTD_STD  SumProduct, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  SumProduct, DWORD
  COM_MTD_STD  Sinh, REAL8, ptr REAL8
  COM_MTD_STD  Cosh, REAL8, ptr REAL8
  COM_MTD_STD  Tanh, REAL8, ptr REAL8
  COM_MTD_STD  Asinh, REAL8, ptr REAL8
  COM_MTD_STD  Acosh, REAL8, ptr REAL8
  COM_MTD_STD  Atanh, REAL8, ptr REAL8
  COM_MTD_STD  DGet, ptr Range, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  Db_, REAL8, REAL8, REAL8, REAL8, VARIANT, ptr REAL8
  COM_MTD_STD  Frequency, VARIANT, VARIANT, ptr VARIANT
;+++   COM_MTD_STD  AveDev, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  AveDev, DWORD
  COM_MTD_STD  BetaDist, REAL8, REAL8, REAL8, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  GammaLn, REAL8, ptr REAL8
  COM_MTD_STD  BetaInv, REAL8, REAL8, REAL8, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  BinomDist, REAL8, REAL8, REAL8, BOOL, ptr REAL8
  COM_MTD_STD  ChiDist, REAL8, REAL8, ptr REAL8
  COM_MTD_STD  ChiInv, REAL8, REAL8, ptr REAL8
  COM_MTD_STD  Combin, REAL8, REAL8, ptr REAL8
  COM_MTD_STD  Confidence, REAL8, REAL8, REAL8, ptr REAL8
  COM_MTD_STD  CritBinom, REAL8, REAL8, REAL8, ptr REAL8
  COM_MTD_STD  Even_, REAL8, ptr REAL8
  COM_MTD_STD  ExponDist, REAL8, REAL8, BOOL, ptr REAL8
  COM_MTD_STD  FDist, REAL8, REAL8, REAL8, ptr REAL8
  COM_MTD_STD  FInv, REAL8, REAL8, REAL8, ptr REAL8
  COM_MTD_STD  Fisher, REAL8, ptr REAL8
  COM_MTD_STD  FisherInv, REAL8, ptr REAL8
  COM_MTD_STD  Floor, REAL8, REAL8, ptr REAL8
  COM_MTD_STD  GammaDist, REAL8, REAL8, REAL8, BOOL, ptr REAL8
  COM_MTD_STD  GammaInv, REAL8, REAL8, REAL8, ptr REAL8
  COM_MTD_STD  Ceiling, REAL8, REAL8, ptr REAL8
  COM_MTD_STD  HypGeomDist, REAL8, REAL8, REAL8, REAL8, ptr REAL8
  COM_MTD_STD  LogNormDist, REAL8, REAL8, REAL8, ptr REAL8
  COM_MTD_STD  LogInv, REAL8, REAL8, REAL8, ptr REAL8
  COM_MTD_STD  NegBinomDist, REAL8, REAL8, REAL8, ptr REAL8
  COM_MTD_STD  NormDist, REAL8, REAL8, REAL8, BOOL, ptr REAL8
  COM_MTD_STD  NormSDist, REAL8, ptr REAL8
  COM_MTD_STD  NormInv, REAL8, REAL8, REAL8, ptr REAL8
  COM_MTD_STD  NormSInv, REAL8, ptr REAL8
  COM_MTD_STD  Standardize, REAL8, REAL8, REAL8, ptr REAL8
  COM_MTD_STD  Odd, REAL8, ptr REAL8
  COM_MTD_STD  Permut, REAL8, REAL8, ptr REAL8
  COM_MTD_STD  Poisson, REAL8, REAL8, BOOL, ptr REAL8
  COM_MTD_STD  TDist, REAL8, REAL8, REAL8, ptr REAL8
  COM_MTD_STD  Weibull, REAL8, REAL8, REAL8, BOOL, ptr REAL8
  COM_MTD_STD  SumXMY2, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  SumX2MY2, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  SumX2PY2, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  ChiTest, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  Correl, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  Covar, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  Forecast, REAL8, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  FTest, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  Intercept, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  Pearson, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  RSq, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  StEyx, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  Slope, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  TTest, VARIANT, VARIANT, REAL8, REAL8, ptr REAL8
  COM_MTD_STD  Prob, VARIANT, VARIANT, REAL8, VARIANT, ptr REAL8
;+++   COM_MTD_STD  DevSq, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  DevSq, DWORD
;+++   COM_MTD_STD  GeoMean, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  GeoMean, DWORD
;+++   COM_MTD_STD  HarMean, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  HarMean, DWORD
;+++   COM_MTD_STD  SumSq, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  SumSq, DWORD
;+++   COM_MTD_STD  Kurt, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  Kurt, DWORD
;+++   COM_MTD_STD  Skew, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  Skew, DWORD
  COM_MTD_STD  ZTest, VARIANT, REAL8, VARIANT, ptr REAL8
  COM_MTD_STD  Large, VARIANT, REAL8, ptr REAL8
  COM_MTD_STD  Small, VARIANT, REAL8, ptr REAL8
  COM_MTD_STD  Quartile, VARIANT, REAL8, ptr REAL8
  COM_MTD_STD  Percentile, VARIANT, REAL8, ptr REAL8
  COM_MTD_STD  PercentRank, VARIANT, REAL8, VARIANT, ptr REAL8
;+++   COM_MTD_STD  Mode, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  Mode, DWORD
  COM_MTD_STD  TrimMean, VARIANT, REAL8, ptr REAL8
  COM_MTD_STD  TInv, REAL8, REAL8, ptr REAL8
  COM_MTD_STD  Power, REAL8, REAL8, ptr REAL8
  COM_MTD_STD  Radians, REAL8, ptr REAL8
  COM_MTD_STD  Degrees, REAL8, ptr REAL8
;+++   COM_MTD_STD  Subtotal, REAL8, ptr Range, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  Subtotal, DWORD
  COM_MTD_STD  SumIf, ptr Range, VARIANT, VARIANT, ptr REAL8
  COM_MTD_STD  CountIf, ptr Range, VARIANT, ptr REAL8
  COM_MTD_STD  CountBlank, ptr Range, ptr REAL8
  COM_MTD_STD  Ispmt, REAL8, REAL8, REAL8, REAL8, ptr REAL8
  COM_MTD_STD  Roman, REAL8, VARIANT, ptr BSTR
  COM_MTD_STD  Asc, BSTR, ptr BSTR
  COM_MTD_STD  Dbcs, BSTR, ptr BSTR
  COM_MTD_STD  Phonetic, ptr Range, ptr BSTR
  COM_MTD_STD  BahtText, REAL8, ptr BSTR
  COM_MTD_STD  ThaiDayOfWeek, REAL8, ptr BSTR
  COM_MTD_STD  ThaiDigit, BSTR, ptr BSTR
  COM_MTD_STD  ThaiMonthOfYear, REAL8, ptr BSTR
  COM_MTD_STD  ThaiNumSound, REAL8, ptr BSTR
  COM_MTD_STD  ThaiNumString, REAL8, ptr BSTR
  COM_MTD_STD  ThaiStringLength, BSTR, ptr REAL8
  COM_MTD_STD  IsThaiDigit, BSTR, ptr BOOL
  COM_MTD_STD  RoundBahtDown, REAL8, ptr REAL8
  COM_MTD_STD  RoundBahtUp, REAL8, ptr REAL8
  COM_MTD_STD  ThaiYear, REAL8, ptr REAL8
;+++   COM_MTD_STD  RTD, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  RTD, DWORD
COM_INTERFACE_END

COM_INTERFACE_BEG IRange, IDispatch, <00020846-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Activate, ptr VARIANT
  COM_MTD_STD  get_AddIndent, ptr VARIANT
  COM_MTD_STD  put_AddIndent, VARIANT
  COM_MTD_STD  get_Address, VARIANT, VARIANT, XlReferenceStyle, VARIANT, VARIANT, SDWORD, ptr BSTR
  COM_MTD_STD  get_AddressLocal, VARIANT, VARIANT, XlReferenceStyle, VARIANT, VARIANT, ptr BSTR
  COM_MTD_STD  AdvancedFilter, XlFilterAction, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  ApplyNames, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, XlApplyNamesOrder, VARIANT, ptr VARIANT
  COM_MTD_STD  ApplyOutlineStyles, ptr VARIANT
  COM_MTD_STD  get_Areas, ptr ptr Areas
  COM_MTD_STD  AutoComplete, BSTR, ptr BSTR
  COM_MTD_STD  AutoFill, ptr Range, XlAutoFillType, ptr VARIANT
  COM_MTD_STD  AutoFilter, VARIANT, VARIANT, XlAutoFilterOperator, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  AutoFit, ptr VARIANT
  COM_MTD_STD  AutoFormat, XlRangeAutoFormat, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  AutoOutline, ptr VARIANT
  COM_MTD_STD  BorderAround, VARIANT, XlBorderWeight, XlColorIndex, VARIANT, ptr VARIANT
  COM_MTD_STD  get_Borders, ptr ptr Borders
  COM_MTD_STD  Calculate, ptr VARIANT
  COM_MTD_STD  get_Cells, ptr ptr Range
  COM_MTD_STD  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_STD  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  Clear, ptr VARIANT
  COM_MTD_STD  ClearContents, ptr VARIANT
  COM_MTD_STD  ClearFormats, ptr VARIANT
  COM_MTD_STD  ClearNotes, ptr VARIANT
  COM_MTD_STD  ClearOutline, ptr VARIANT
  COM_MTD_STD  get_Column, ptr SDWORD
  COM_MTD_STD  ColumnDifferences, VARIANT, ptr ptr Range
  COM_MTD_STD  get_Columns, ptr ptr Range
  COM_MTD_STD  get_ColumnWidth, ptr VARIANT
  COM_MTD_STD  put_ColumnWidth, VARIANT
  COM_MTD_STD  Consolidate, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  Copy, VARIANT, ptr VARIANT
  COM_MTD_STD  CopyFromRecordset, LPUNKNOWN, VARIANT, VARIANT, ptr SDWORD
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  CreateNames, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  CreatePublisher, VARIANT, XlPictureAppearance, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_CurrentArray, ptr ptr Range
  COM_MTD_STD  get_CurrentRegion, ptr ptr Range
  COM_MTD_STD  Cut, VARIANT, ptr VARIANT
  COM_MTD_STD  DataSeries, VARIANT, XlDataSeriesType, XlDataSeriesDate, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get__Default, VARIANT, VARIANT, SDWORD, ptr VARIANT
  COM_MTD_STD  put__Default, VARIANT, VARIANT, SDWORD, VARIANT
  COM_MTD_STD  Delete, VARIANT, ptr VARIANT
  COM_MTD_STD  get_Dependents, ptr ptr Range
  COM_MTD_STD  DialogBox, ptr VARIANT
  COM_MTD_STD  get_DirectDependents, ptr ptr Range
  COM_MTD_STD  get_DirectPrecedents, ptr ptr Range
  COM_MTD_STD  EditionOptions, XlEditionType, XlEditionOptionsOption, VARIANT, VARIANT, XlPictureAppearance, XlPictureAppearance, VARIANT, ptr VARIANT
  COM_MTD_STD  get_End, XlDirection, ptr ptr Range
  COM_MTD_STD  get_EntireColumn, ptr ptr Range
  COM_MTD_STD  get_EntireRow, ptr ptr Range
  COM_MTD_STD  FillDown, ptr VARIANT
  COM_MTD_STD  FillLeft, ptr VARIANT
  COM_MTD_STD  FillRight, ptr VARIANT
  COM_MTD_STD  FillUp, ptr VARIANT
  COM_MTD_STD  Find, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, XlSearchDirection, VARIANT, VARIANT, VARIANT, ptr ptr Range
  COM_MTD_STD  FindNext, VARIANT, ptr ptr Range
  COM_MTD_STD  FindPrevious, VARIANT, ptr ptr Range
  COM_MTD_STD  get_Font, ptr ptr Font
  COM_MTD_STD  get_Formula, SDWORD, ptr VARIANT
  COM_MTD_STD  put_Formula, SDWORD, VARIANT
  COM_MTD_STD  get_FormulaArray, ptr VARIANT
  COM_MTD_STD  put_FormulaArray, VARIANT
  COM_MTD_STD  get_FormulaLabel, ptr XlFormulaLabel
  COM_MTD_STD  put_FormulaLabel, XlFormulaLabel
  COM_MTD_STD  get_FormulaHidden, ptr VARIANT
  COM_MTD_STD  put_FormulaHidden, VARIANT
  COM_MTD_STD  get_FormulaLocal, ptr VARIANT
  COM_MTD_STD  put_FormulaLocal, VARIANT
  COM_MTD_STD  get_FormulaR1C1, SDWORD, ptr VARIANT
  COM_MTD_STD  put_FormulaR1C1, SDWORD, VARIANT
  COM_MTD_STD  get_FormulaR1C1Local, ptr VARIANT
  COM_MTD_STD  put_FormulaR1C1Local, VARIANT
  COM_MTD_STD  FunctionWizard, ptr VARIANT
  COM_MTD_STD  GoalSeek, VARIANT, ptr Range, ptr BOOL
  COM_MTD_STD  Group_, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_HasArray, ptr VARIANT
  COM_MTD_STD  get_HasFormula, ptr VARIANT
  COM_MTD_STD  get_Height, ptr VARIANT
  COM_MTD_STD  get_Hidden, ptr VARIANT
  COM_MTD_STD  put_Hidden, VARIANT
  COM_MTD_STD  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_STD  put_HorizontalAlignment, VARIANT
  COM_MTD_STD  get_IndentLevel, ptr VARIANT
  COM_MTD_STD  put_IndentLevel, VARIANT
  COM_MTD_STD  InsertIndent, SDWORD
  COM_MTD_STD  Insert, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_Item, VARIANT, VARIANT, SDWORD, ptr VARIANT
  COM_MTD_STD  put_Item, VARIANT, VARIANT, SDWORD, VARIANT
  COM_MTD_STD  Justify, ptr VARIANT
  COM_MTD_STD  get_Left, ptr VARIANT
  COM_MTD_STD  get_ListHeaderRows, ptr SDWORD
  COM_MTD_STD  ListNames, ptr VARIANT
  COM_MTD_STD  get_LocationInTable, ptr XlLocationInTable
  COM_MTD_STD  get_Locked, ptr VARIANT
  COM_MTD_STD  put_Locked, VARIANT
  COM_MTD_STD  Merge, VARIANT
  COM_MTD_STD  UnMerge
  COM_MTD_STD  get_MergeArea, ptr ptr Range
  COM_MTD_STD  get_MergeCells, ptr VARIANT
  COM_MTD_STD  put_MergeCells, VARIANT
  COM_MTD_STD  get_Name, ptr VARIANT
  COM_MTD_STD  put_Name, VARIANT
  COM_MTD_STD  NavigateArrow, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  get_Next, ptr ptr Range
  COM_MTD_STD  NoteText, VARIANT, VARIANT, VARIANT, ptr BSTR
  COM_MTD_STD  get_NumberFormat, ptr VARIANT
  COM_MTD_STD  put_NumberFormat, VARIANT
  COM_MTD_STD  get_NumberFormatLocal, ptr VARIANT
  COM_MTD_STD  put_NumberFormatLocal, VARIANT
  COM_MTD_STD  get_Offset, VARIANT, VARIANT, ptr ptr Range
  COM_MTD_STD  get_Orientation, ptr VARIANT
  COM_MTD_STD  put_Orientation, VARIANT
  COM_MTD_STD  get_OutlineLevel, ptr VARIANT
  COM_MTD_STD  put_OutlineLevel, VARIANT
  COM_MTD_STD  get_PageBreak, ptr SDWORD
  COM_MTD_STD  put_PageBreak, SDWORD
  COM_MTD_STD  Parse, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  _PasteSpecial, XlPasteType, XlPasteSpecialOperation, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_PivotField, ptr ptr PivotField
  COM_MTD_STD  get_PivotItem, ptr ptr PivotItem
  COM_MTD_STD  get_PivotTable, ptr ptr PivotTable
  COM_MTD_STD  get_Precedents, ptr ptr Range
  COM_MTD_STD  get_PrefixCharacter, ptr VARIANT
  COM_MTD_STD  get_Previous, ptr ptr Range
  COM_MTD_STD  _PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  PrintPreview, VARIANT, ptr VARIANT
  COM_MTD_STD  get_QueryTable, ptr ptr QueryTable
  COM_MTD_STD  get_Range, VARIANT, VARIANT, ptr ptr Range
  COM_MTD_STD  RemoveSubtotal, ptr VARIANT
  COM_MTD_STD  Replace, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr BOOL
  COM_MTD_STD  get_Resize, VARIANT, VARIANT, ptr ptr Range
  COM_MTD_STD  get_Row, ptr SDWORD
  COM_MTD_STD  RowDifferences, VARIANT, ptr ptr Range
  COM_MTD_STD  get_RowHeight, ptr VARIANT
  COM_MTD_STD  put_RowHeight, VARIANT
  COM_MTD_STD  get_Rows, ptr ptr Range
;+++   COM_MTD_STD  Run, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  Run, DWORD
  COM_MTD_STD  Select, ptr VARIANT
  COM_MTD_STD  Show, ptr VARIANT
  COM_MTD_STD  ShowDependents, VARIANT, ptr VARIANT
  COM_MTD_STD  get_ShowDetail, ptr VARIANT
  COM_MTD_STD  put_ShowDetail, VARIANT
  COM_MTD_STD  ShowErrors, ptr VARIANT
  COM_MTD_STD  ShowPrecedents, VARIANT, ptr VARIANT
  COM_MTD_STD  get_ShrinkToFit, ptr VARIANT
  COM_MTD_STD  put_ShrinkToFit, VARIANT
;+++  COM_MTD_STD  Sort, VARIANT, XlSortOrder, VARIANT, VARIANT, XlSortOrder, VARIANT, XlSortOrder, XlYesNoGuess, VARIANT, VARIANT, XlSortOrientation, XlSortMethod, XlSortDataOption, XlSortDataOption, XlSortDataOption, ptr VARIANT
  COM_MTD_STD  Sort
;+++  COM_MTD_STD  SortSpecial, XlSortMethod, VARIANT, XlSortOrder, VARIANT, VARIANT, XlSortOrder, VARIANT, XlSortOrder, XlYesNoGuess, VARIANT, VARIANT, XlSortOrientation, XlSortDataOption, XlSortDataOption, XlSortDataOption, ptr VARIANT
  COM_MTD_STD  SortSpecial
  COM_MTD_STD  get_SoundNote, ptr ptr SoundNote
  COM_MTD_STD  SpecialCells, XlCellType, VARIANT, ptr ptr Range
  COM_MTD_STD  get_Style, ptr VARIANT
  COM_MTD_STD  put_Style, VARIANT
  COM_MTD_STD  SubscribeTo, BSTR, XlSubscribeToFormat, ptr VARIANT
  COM_MTD_STD  Subtotal, SDWORD, XlConsolidationFunction, VARIANT, VARIANT, VARIANT, XlSummaryRow, ptr VARIANT
  COM_MTD_STD  get_Summary, ptr VARIANT
  COM_MTD_STD  Table, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_Text, ptr VARIANT
  COM_MTD_STD  TextToColumns, VARIANT, XlTextParsingType, XlTextQualifier, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_Top, ptr VARIANT
  COM_MTD_STD  Ungroup, ptr VARIANT
  COM_MTD_STD  get_UseStandardHeight, ptr VARIANT
  COM_MTD_STD  put_UseStandardHeight, VARIANT
  COM_MTD_STD  get_UseStandardWidth, ptr VARIANT
  COM_MTD_STD  put_UseStandardWidth, VARIANT
  COM_MTD_STD  get_Validation, ptr ptr Validation
  COM_MTD_STD  get_Value, VARIANT, SDWORD, ptr VARIANT
  COM_MTD_STD  put_Value, VARIANT, SDWORD, VARIANT
  COM_MTD_STD  get_Value2, SDWORD, ptr VARIANT
  COM_MTD_STD  put_Value2, SDWORD, VARIANT
  COM_MTD_STD  get_VerticalAlignment, ptr VARIANT
  COM_MTD_STD  put_VerticalAlignment, VARIANT
  COM_MTD_STD  get_Width, ptr VARIANT
  COM_MTD_STD  get_Worksheet, ptr ptr Worksheet
  COM_MTD_STD  get_WrapText, ptr VARIANT
  COM_MTD_STD  put_WrapText, VARIANT
  COM_MTD_STD  AddComment, VARIANT, ptr ptr Comment_
  COM_MTD_STD  get_Comment, ptr ptr Comment_
  COM_MTD_STD  ClearComments
  COM_MTD_STD  get_Phonetic, ptr ptr Phonetic
  COM_MTD_STD  get_FormatConditions, ptr ptr FormatConditions
  COM_MTD_STD  get_ReadingOrder, ptr SDWORD
  COM_MTD_STD  put_ReadingOrder, SDWORD
  COM_MTD_STD  get_Hyperlinks, ptr ptr Hyperlinks
  COM_MTD_STD  get_Phonetics, ptr ptr Phonetics
  COM_MTD_STD  SetPhonetic
  COM_MTD_STD  get_ID, ptr BSTR
  COM_MTD_STD  put_ID, BSTR
  COM_MTD_STD  PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_PivotCell, ptr ptr PivotCell
  COM_MTD_STD  Dirty
  COM_MTD_STD  get_Errors, ptr ptr Errors
  COM_MTD_STD  get_SmartTags, ptr ptr SmartTags
  COM_MTD_STD  Speak, VARIANT, VARIANT
  COM_MTD_STD  PasteSpecial, XlPasteType, XlPasteSpecialOperation, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_AllowEdit, ptr BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG IChartEvents, IDispatch, <0002440F-0001-0000-C000-000000000046>
  COM_MTD_STD  Activate
  COM_MTD_STD  Deactivate
  COM_MTD_STD  Resize
  COM_MTD_STD  MouseDown, SDWORD, SDWORD, SDWORD, SDWORD
  COM_MTD_STD  MouseUp, SDWORD, SDWORD, SDWORD, SDWORD
  COM_MTD_STD  MouseMove, SDWORD, SDWORD, SDWORD, SDWORD
  COM_MTD_STD  BeforeRightClick, ptr BOOL
  COM_MTD_STD  DragPlot
  COM_MTD_STD  DragOver
  COM_MTD_STD  BeforeDoubleClick, SDWORD, SDWORD, SDWORD, ptr BOOL
  COM_MTD_STD  Select, SDWORD, SDWORD, SDWORD
  COM_MTD_STD  SeriesChange, SDWORD, SDWORD
  COM_MTD_STD  Calculate
COM_INTERFACE_END

COM_INTERFACE_BEG _Chart, IDispatch, <000208D6-0000-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Activate, SDWORD
  COM_MTD_STD  Copy, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  Delete, SDWORD
  COM_MTD_STD  get_CodeName, ptr BSTR
  COM_MTD_STD  get__CodeName, ptr BSTR
  COM_MTD_STD  put__CodeName, BSTR
  COM_MTD_STD  get_Index, SDWORD, ptr SDWORD
  COM_MTD_STD  Move, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_Next, ptr LPDISPATCH
  COM_MTD_STD  get_OnDoubleClick, SDWORD, ptr BSTR
  COM_MTD_STD  put_OnDoubleClick, SDWORD, BSTR
  COM_MTD_STD  get_OnSheetActivate, SDWORD, ptr BSTR
  COM_MTD_STD  put_OnSheetActivate, SDWORD, BSTR
  COM_MTD_STD  get_OnSheetDeactivate, SDWORD, ptr BSTR
  COM_MTD_STD  put_OnSheetDeactivate, SDWORD, BSTR
  COM_MTD_STD  get_PageSetup, ptr ptr PageSetup
  COM_MTD_STD  get_Previous, ptr LPDISPATCH
  COM_MTD_STD  _PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  PrintPreview, VARIANT, SDWORD
  COM_MTD_STD  _Protect, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get_ProtectContents, SDWORD, ptr BOOL
  COM_MTD_STD  get_ProtectDrawingObjects, SDWORD, ptr BOOL
  COM_MTD_STD  get_ProtectionMode, SDWORD, ptr BOOL
  COM_MTD_STD  _Dummy23
  COM_MTD_STD  _SaveAs, BSTR, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  Select, VARIANT, SDWORD
  COM_MTD_STD  Unprotect, VARIANT, SDWORD
  COM_MTD_STD  get_Visible, SDWORD, ptr XlSheetVisibility
  COM_MTD_STD  put_Visible, SDWORD, XlSheetVisibility
  COM_MTD_STD  get_Shapes, ptr ptr Shapes
  COM_MTD_STD  _ApplyDataLabels, XlDataLabelsType, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  Arcs, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  get_Area3DGroup, SDWORD, ptr ptr ChartGroup
  COM_MTD_STD  AreaGroups, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  AutoFormat, SDWORD, VARIANT
  COM_MTD_STD  get_AutoScaling, SDWORD, ptr BOOL
  COM_MTD_STD  put_AutoScaling, SDWORD, BOOL
  COM_MTD_STD  Axes, VARIANT, XlAxisGroup, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  SetBackgroundPicture, BSTR
  COM_MTD_STD  get_Bar3DGroup, SDWORD, ptr ptr ChartGroup
  COM_MTD_STD  BarGroups, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  Buttons, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  get_ChartArea, SDWORD, ptr ptr ChartArea
  COM_MTD_STD  ChartGroups, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  ChartObjects, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  get_ChartTitle, SDWORD, ptr ptr ChartTitle
  COM_MTD_STD  ChartWizard, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  CheckBoxes, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get_Column3DGroup, SDWORD, ptr ptr ChartGroup
  COM_MTD_STD  ColumnGroups, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, XlPictureAppearance, SDWORD
  COM_MTD_STD  get_Corners, SDWORD, ptr ptr Corners
  COM_MTD_STD  CreatePublisher, VARIANT, XlPictureAppearance, XlPictureAppearance, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get_DataTable, ptr ptr DataTable
  COM_MTD_STD  get_DepthPercent, SDWORD, ptr SDWORD
  COM_MTD_STD  put_DepthPercent, SDWORD, SDWORD
  COM_MTD_STD  Deselect, SDWORD
  COM_MTD_STD  get_DisplayBlanksAs, SDWORD, ptr XlDisplayBlanksAs
  COM_MTD_STD  put_DisplayBlanksAs, SDWORD, XlDisplayBlanksAs
  COM_MTD_STD  DoughnutGroups, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  Drawings, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  DrawingObjects, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  DropDowns, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  get_Elevation, SDWORD, ptr SDWORD
  COM_MTD_STD  put_Elevation, SDWORD, SDWORD
  COM_MTD_STD  Evaluate, VARIANT, SDWORD, ptr VARIANT
  COM_MTD_STD  _Evaluate, VARIANT, SDWORD, ptr VARIANT
  COM_MTD_STD  get_Floor, SDWORD, ptr ptr Floor
  COM_MTD_STD  get_GapDepth, SDWORD, ptr SDWORD
  COM_MTD_STD  put_GapDepth, SDWORD, SDWORD
  COM_MTD_STD  GroupBoxes, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  GroupObjects, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  get_HasAxis, VARIANT, VARIANT, SDWORD, ptr VARIANT
  COM_MTD_STD  put_HasAxis, VARIANT, VARIANT, SDWORD, VARIANT
  COM_MTD_STD  get_HasDataTable, ptr BOOL
  COM_MTD_STD  put_HasDataTable, BOOL
  COM_MTD_STD  get_HasLegend, SDWORD, ptr BOOL
  COM_MTD_STD  put_HasLegend, SDWORD, BOOL
  COM_MTD_STD  get_HasTitle, SDWORD, ptr BOOL
  COM_MTD_STD  put_HasTitle, SDWORD, BOOL
  COM_MTD_STD  get_HeightPercent, SDWORD, ptr SDWORD
  COM_MTD_STD  put_HeightPercent, SDWORD, SDWORD
  COM_MTD_STD  get_Hyperlinks, ptr ptr Hyperlinks
  COM_MTD_STD  Labels, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  get_Legend, SDWORD, ptr ptr Legend
  COM_MTD_STD  get_Line3DGroup, SDWORD, ptr ptr ChartGroup
  COM_MTD_STD  LineGroups, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  Lines, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  ListBoxes, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  Location, XlChartLocation, VARIANT, ptr ptr Chart
  COM_MTD_STD  OLEObjects, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  OptionButtons, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  Ovals, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  Paste, VARIANT, SDWORD
  COM_MTD_STD  get_Perspective, SDWORD, ptr SDWORD
  COM_MTD_STD  put_Perspective, SDWORD, SDWORD
  COM_MTD_STD  Pictures, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  get_Pie3DGroup, SDWORD, ptr ptr ChartGroup
  COM_MTD_STD  PieGroups, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  get_PlotArea, SDWORD, ptr ptr PlotArea
  COM_MTD_STD  get_PlotVisibleOnly, SDWORD, ptr BOOL
  COM_MTD_STD  put_PlotVisibleOnly, SDWORD, BOOL
  COM_MTD_STD  RadarGroups, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  Rectangles, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  get_RightAngleAxes, SDWORD, ptr VARIANT
  COM_MTD_STD  put_RightAngleAxes, SDWORD, VARIANT
  COM_MTD_STD  get_Rotation, SDWORD, ptr VARIANT
  COM_MTD_STD  put_Rotation, SDWORD, VARIANT
  COM_MTD_STD  ScrollBars, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  SeriesCollection, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  get_SizeWithWindow, SDWORD, ptr BOOL
  COM_MTD_STD  put_SizeWithWindow, SDWORD, BOOL
  COM_MTD_STD  get_ShowWindow, ptr BOOL
  COM_MTD_STD  put_ShowWindow, BOOL
  COM_MTD_STD  Spinners, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  get_SubType, SDWORD, ptr SDWORD
  COM_MTD_STD  put_SubType, SDWORD, SDWORD
  COM_MTD_STD  get_SurfaceGroup, SDWORD, ptr ptr ChartGroup
  COM_MTD_STD  TextBoxes, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  get_Type, SDWORD, ptr SDWORD
  COM_MTD_STD  put_Type, SDWORD, SDWORD
  COM_MTD_STD  get_ChartType, ptr XlChartType
  COM_MTD_STD  put_ChartType, XlChartType
  COM_MTD_STD  ApplyCustomType, XlChartType, VARIANT
  COM_MTD_STD  get_Walls, SDWORD, ptr ptr Walls
  COM_MTD_STD  get_WallsAndGridlines2D, SDWORD, ptr BOOL
  COM_MTD_STD  put_WallsAndGridlines2D, SDWORD, BOOL
  COM_MTD_STD  XYGroups, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  get_BarShape, ptr XlBarShape
  COM_MTD_STD  put_BarShape, XlBarShape
  COM_MTD_STD  get_PlotBy, ptr XlRowCol
  COM_MTD_STD  put_PlotBy, XlRowCol
  COM_MTD_STD  CopyChartBuild
  COM_MTD_STD  get_ProtectFormatting, ptr BOOL
  COM_MTD_STD  put_ProtectFormatting, BOOL
  COM_MTD_STD  get_ProtectData, ptr BOOL
  COM_MTD_STD  put_ProtectData, BOOL
  COM_MTD_STD  get_ProtectGoalSeek, ptr BOOL
  COM_MTD_STD  put_ProtectGoalSeek, BOOL
  COM_MTD_STD  get_ProtectSelection, ptr BOOL
  COM_MTD_STD  put_ProtectSelection, BOOL
  COM_MTD_STD  GetChartElement, SDWORD, SDWORD, ptr SDWORD, ptr SDWORD, ptr SDWORD
  COM_MTD_STD  SetSourceData, ptr Range, VARIANT
  COM_MTD_STD  Export, BSTR, VARIANT, VARIANT, ptr BOOL
  COM_MTD_STD  Refresh
  COM_MTD_STD  get_PivotLayout, ptr ptr PivotLayout
  COM_MTD_STD  get_HasPivotFields, ptr BOOL
  COM_MTD_STD  put_HasPivotFields, BOOL
  COM_MTD_STD  get_Scripts, ptr ptr Scripts
  COM_MTD_STD  PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get_Tab, ptr ptr Tab
  COM_MTD_STD  get_MailEnvelope, ptr ptr MsoEnvelope
  COM_MTD_STD  ApplyDataLabels, XlDataLabelsType, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  SaveAs, BSTR, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_STD  Protect, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG Sheets, IDispatch, <000208D7-0000-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Add_, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  Copy, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Delete, SDWORD
  COM_MTD_STD  FillAcrossSheets, ptr Range, XlFillWith, SDWORD
  COM_MTD_STD  get_Item, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  Move, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  _PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  PrintPreview, VARIANT, SDWORD
  COM_MTD_STD  Select, VARIANT, SDWORD
  COM_MTD_STD  get_HPageBreaks, ptr ptr HPageBreaks
  COM_MTD_STD  get_VPageBreaks, ptr ptr VPageBreaks
  COM_MTD_STD  get_Visible, SDWORD, ptr VARIANT
  COM_MTD_STD  put_Visible, SDWORD, VARIANT
  COM_MTD_STD  get__Default, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG IVPageBreak, IDispatch, <00024402-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr ptr Worksheet
  COM_MTD_STD  Delete
  COM_MTD_STD  DragOff, XlDirection, SDWORD
  COM_MTD_STD  get_Type, ptr XlPageBreak
  COM_MTD_STD  put_Type, XlPageBreak
  COM_MTD_STD  get_Extent, ptr XlPageBreakExtent
  COM_MTD_STD  get_Location, ptr ptr Range
  COM_MTD_STD  putref_Location, ptr Range
COM_INTERFACE_END

COM_INTERFACE_BEG IHPageBreak, IDispatch, <00024401-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr ptr Worksheet
  COM_MTD_STD  Delete
  COM_MTD_STD  DragOff, XlDirection, SDWORD
  COM_MTD_STD  get_Type, ptr XlPageBreak
  COM_MTD_STD  put_Type, XlPageBreak
  COM_MTD_STD  get_Extent, ptr XlPageBreakExtent
  COM_MTD_STD  get_Location, ptr ptr Range
  COM_MTD_STD  putref_Location, ptr Range
COM_INTERFACE_END

COM_INTERFACE_BEG IHPageBreaks, IDispatch, <00024404-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  get_Item, SDWORD, ptr ptr HPageBreak
  COM_MTD_STD  get__Default, SDWORD, ptr ptr HPageBreak
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  Add_, LPDISPATCH, ptr ptr HPageBreak
COM_INTERFACE_END

COM_INTERFACE_BEG IVPageBreaks, IDispatch, <00024405-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  get_Item, SDWORD, ptr ptr VPageBreak
  COM_MTD_STD  get__Default, SDWORD, ptr ptr VPageBreak
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  Add_, LPDISPATCH, ptr ptr VPageBreak
COM_INTERFACE_END

COM_INTERFACE_BEG IRecentFile, IDispatch, <00024407-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  get_Path, ptr BSTR
  COM_MTD_STD  get_Index, ptr SDWORD
  COM_MTD_STD  Open, ptr ptr Workbook
  COM_MTD_STD  Delete
COM_INTERFACE_END

COM_INTERFACE_BEG IRecentFiles, IDispatch, <00024406-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Maximum, ptr SDWORD
  COM_MTD_STD  put_Maximum, SDWORD
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  get_Item, SDWORD, ptr ptr RecentFile
  COM_MTD_STD  get__Default, SDWORD, ptr ptr RecentFile
  COM_MTD_STD  Add_, BSTR, ptr ptr RecentFile
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IDocEvents, IDispatch, <00024411-0001-0000-C000-000000000046>
  COM_MTD_STD  SelectionChange, ptr Range
  COM_MTD_STD  BeforeDoubleClick, ptr Range, ptr BOOL
  COM_MTD_STD  BeforeRightClick, ptr Range, ptr BOOL
  COM_MTD_STD  Activate
  COM_MTD_STD  Deactivate
  COM_MTD_STD  Calculate
  COM_MTD_STD  Change, ptr Range
  COM_MTD_STD  FollowHyperlink, ptr Hyperlink
  COM_MTD_STD  PivotTableUpdate, ptr PivotTable
COM_INTERFACE_END

COM_INTERFACE_BEG _Worksheet, IDispatch, <000208D8-0000-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Activate, SDWORD
  COM_MTD_STD  Copy, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  Delete, SDWORD
  COM_MTD_STD  get_CodeName, ptr BSTR
  COM_MTD_STD  get__CodeName, ptr BSTR
  COM_MTD_STD  put__CodeName, BSTR
  COM_MTD_STD  get_Index, SDWORD, ptr SDWORD
  COM_MTD_STD  Move, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_Next, ptr LPDISPATCH
  COM_MTD_STD  get_OnDoubleClick, SDWORD, ptr BSTR
  COM_MTD_STD  put_OnDoubleClick, SDWORD, BSTR
  COM_MTD_STD  get_OnSheetActivate, SDWORD, ptr BSTR
  COM_MTD_STD  put_OnSheetActivate, SDWORD, BSTR
  COM_MTD_STD  get_OnSheetDeactivate, SDWORD, ptr BSTR
  COM_MTD_STD  put_OnSheetDeactivate, SDWORD, BSTR
  COM_MTD_STD  get_PageSetup, ptr ptr PageSetup
  COM_MTD_STD  get_Previous, ptr LPDISPATCH
  COM_MTD_STD  _PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  PrintPreview, VARIANT, SDWORD
  COM_MTD_STD  _Protect, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get_ProtectContents, SDWORD, ptr BOOL
  COM_MTD_STD  get_ProtectDrawingObjects, SDWORD, ptr BOOL
  COM_MTD_STD  get_ProtectionMode, SDWORD, ptr BOOL
  COM_MTD_STD  get_ProtectScenarios, SDWORD, ptr BOOL
  COM_MTD_STD  _SaveAs, BSTR, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  Select, VARIANT, SDWORD
  COM_MTD_STD  Unprotect, VARIANT, SDWORD
  COM_MTD_STD  get_Visible, SDWORD, ptr XlSheetVisibility
  COM_MTD_STD  put_Visible, SDWORD, XlSheetVisibility
  COM_MTD_STD  get_Shapes, ptr ptr Shapes
  COM_MTD_STD  get_TransitionExpEval, SDWORD, ptr BOOL
  COM_MTD_STD  put_TransitionExpEval, SDWORD, BOOL
  COM_MTD_STD  Arcs, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  get_AutoFilterMode, SDWORD, ptr BOOL
  COM_MTD_STD  put_AutoFilterMode, SDWORD, BOOL
  COM_MTD_STD  SetBackgroundPicture, BSTR
  COM_MTD_STD  Buttons, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  Calculate, SDWORD
  COM_MTD_STD  get_EnableCalculation, ptr BOOL
  COM_MTD_STD  put_EnableCalculation, BOOL
  COM_MTD_STD  get_Cells, ptr ptr Range
  COM_MTD_STD  ChartObjects, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  CheckBoxes, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get_CircularReference, SDWORD, ptr ptr Range
  COM_MTD_STD  ClearArrows, SDWORD
  COM_MTD_STD  get_Columns, ptr ptr Range
  COM_MTD_STD  get_ConsolidationFunction, SDWORD, ptr XlConsolidationFunction
  COM_MTD_STD  get_ConsolidationOptions, SDWORD, ptr VARIANT
  COM_MTD_STD  get_ConsolidationSources, SDWORD, ptr VARIANT
  COM_MTD_STD  get_DisplayAutomaticPageBreaks, SDWORD, ptr BOOL
  COM_MTD_STD  put_DisplayAutomaticPageBreaks, SDWORD, BOOL
  COM_MTD_STD  Drawings, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  DrawingObjects, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  DropDowns, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  get_EnableAutoFilter, SDWORD, ptr BOOL
  COM_MTD_STD  put_EnableAutoFilter, SDWORD, BOOL
  COM_MTD_STD  get_EnableSelection, ptr XlEnableSelection
  COM_MTD_STD  put_EnableSelection, XlEnableSelection
  COM_MTD_STD  get_EnableOutlining, SDWORD, ptr BOOL
  COM_MTD_STD  put_EnableOutlining, SDWORD, BOOL
  COM_MTD_STD  get_EnablePivotTable, SDWORD, ptr BOOL
  COM_MTD_STD  put_EnablePivotTable, SDWORD, BOOL
  COM_MTD_STD  Evaluate, VARIANT, SDWORD, ptr VARIANT
  COM_MTD_STD  _Evaluate, VARIANT, SDWORD, ptr VARIANT
  COM_MTD_STD  get_FilterMode, SDWORD, ptr BOOL
  COM_MTD_STD  ResetAllPageBreaks
  COM_MTD_STD  GroupBoxes, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  GroupObjects, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  Labels, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  Lines, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  ListBoxes, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  get_Names, ptr ptr Names
  COM_MTD_STD  OLEObjects, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  get_OnCalculate, SDWORD, ptr BSTR
  COM_MTD_STD  put_OnCalculate, SDWORD, BSTR
  COM_MTD_STD  get_OnData, SDWORD, ptr BSTR
  COM_MTD_STD  put_OnData, SDWORD, BSTR
  COM_MTD_STD  get_OnEntry, SDWORD, ptr BSTR
  COM_MTD_STD  put_OnEntry, SDWORD, BSTR
  COM_MTD_STD  OptionButtons, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  get_Outline, ptr ptr Outline
  COM_MTD_STD  Ovals, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  Paste, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  _PasteSpecial, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  Pictures, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  PivotTables, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  PivotTableWizard, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD, ptr ptr PivotTable
  COM_MTD_STD  get_Range, VARIANT, VARIANT, ptr ptr Range
  COM_MTD_STD  Rectangles, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  get_Rows, ptr ptr Range
  COM_MTD_STD  Scenarios, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  get_ScrollArea, ptr BSTR
  COM_MTD_STD  put_ScrollArea, BSTR
  COM_MTD_STD  ScrollBars, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  ShowAllData, SDWORD
  COM_MTD_STD  ShowDataForm, SDWORD
  COM_MTD_STD  Spinners, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  get_StandardHeight, SDWORD, ptr REAL8
  COM_MTD_STD  get_StandardWidth, SDWORD, ptr REAL8
  COM_MTD_STD  put_StandardWidth, SDWORD, REAL8
  COM_MTD_STD  TextBoxes, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  get_TransitionFormEntry, SDWORD, ptr BOOL
  COM_MTD_STD  put_TransitionFormEntry, SDWORD, BOOL
  COM_MTD_STD  get_Type, SDWORD, ptr XlSheetType
  COM_MTD_STD  get_UsedRange, SDWORD, ptr ptr Range
  COM_MTD_STD  get_HPageBreaks, ptr ptr HPageBreaks
  COM_MTD_STD  get_VPageBreaks, ptr ptr VPageBreaks
  COM_MTD_STD  get_QueryTables, ptr ptr QueryTables
  COM_MTD_STD  get_DisplayPageBreaks, ptr BOOL
  COM_MTD_STD  put_DisplayPageBreaks, BOOL
  COM_MTD_STD  get_Comments, ptr ptr Comments
  COM_MTD_STD  get_Hyperlinks, ptr ptr Hyperlinks
  COM_MTD_STD  ClearCircles
  COM_MTD_STD  CircleInvalid
  COM_MTD_STD  get__DisplayRightToLeft, SDWORD, ptr SDWORD
  COM_MTD_STD  put__DisplayRightToLeft, SDWORD, SDWORD
  COM_MTD_STD  get_AutoFilter, ptr ptr AutoFilter
  COM_MTD_STD  get_DisplayRightToLeft, SDWORD, ptr BOOL
  COM_MTD_STD  put_DisplayRightToLeft, SDWORD, BOOL
  COM_MTD_STD  get_Scripts, ptr ptr Scripts
  COM_MTD_STD  PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  _CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get_Tab, ptr ptr Tab
  COM_MTD_STD  get_MailEnvelope, ptr ptr MsoEnvelope
  COM_MTD_STD  SaveAs, BSTR, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_STD  get_CustomProperties, ptr ptr CustomProperties
  COM_MTD_STD  get_SmartTags, ptr ptr SmartTags
  COM_MTD_STD  get_Protection, ptr ptr Protection
  COM_MTD_STD  PasteSpecial, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  Protect, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG IStyle, IDispatch, <00020852-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_AddIndent, ptr BOOL
  COM_MTD_STD  put_AddIndent, BOOL
  COM_MTD_STD  get_BuiltIn, ptr BOOL
  COM_MTD_STD  get_Borders, ptr ptr Borders
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  get_Font, ptr ptr Font
  COM_MTD_STD  get_FormulaHidden, ptr BOOL
  COM_MTD_STD  put_FormulaHidden, BOOL
  COM_MTD_STD  get_HorizontalAlignment, ptr XlHAlign
  COM_MTD_STD  put_HorizontalAlignment, XlHAlign
  COM_MTD_STD  get_IncludeAlignment, ptr BOOL
  COM_MTD_STD  put_IncludeAlignment, BOOL
  COM_MTD_STD  get_IncludeBorder, ptr BOOL
  COM_MTD_STD  put_IncludeBorder, BOOL
  COM_MTD_STD  get_IncludeFont, ptr BOOL
  COM_MTD_STD  put_IncludeFont, BOOL
  COM_MTD_STD  get_IncludeNumber, ptr BOOL
  COM_MTD_STD  put_IncludeNumber, BOOL
  COM_MTD_STD  get_IncludePatterns, ptr BOOL
  COM_MTD_STD  put_IncludePatterns, BOOL
  COM_MTD_STD  get_IncludeProtection, ptr BOOL
  COM_MTD_STD  put_IncludeProtection, BOOL
  COM_MTD_STD  get_IndentLevel, ptr SDWORD
  COM_MTD_STD  put_IndentLevel, SDWORD
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  get_MergeCells, ptr VARIANT
  COM_MTD_STD  put_MergeCells, VARIANT
  COM_MTD_STD  get_Name, SDWORD, ptr BSTR
  COM_MTD_STD  get_NameLocal, ptr BSTR
  COM_MTD_STD  get_NumberFormat, ptr BSTR
  COM_MTD_STD  put_NumberFormat, BSTR
  COM_MTD_STD  get_NumberFormatLocal, ptr BSTR
  COM_MTD_STD  put_NumberFormatLocal, BSTR
  COM_MTD_STD  get_Orientation, ptr XlOrientation
  COM_MTD_STD  put_Orientation, XlOrientation
  COM_MTD_STD  get_ShrinkToFit, ptr BOOL
  COM_MTD_STD  put_ShrinkToFit, BOOL
  COM_MTD_STD  get_Value, SDWORD, ptr BSTR
  COM_MTD_STD  get_VerticalAlignment, ptr XlVAlign
  COM_MTD_STD  put_VerticalAlignment, XlVAlign
  COM_MTD_STD  get_WrapText, ptr BOOL
  COM_MTD_STD  put_WrapText, BOOL
  COM_MTD_STD  get__Default, SDWORD, ptr BSTR
  COM_MTD_STD  get_ReadingOrder, ptr SDWORD
  COM_MTD_STD  put_ReadingOrder, SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG IStyles, IDispatch, <00020853-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Add_, BSTR, VARIANT, ptr ptr Style
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  get_Item, VARIANT, SDWORD, ptr ptr Style
  COM_MTD_STD  Merge, VARIANT, ptr VARIANT
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  get__Default, VARIANT, SDWORD, ptr ptr Style
COM_INTERFACE_END

COM_INTERFACE_BEG IBorders, IDispatch, <00020855-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Color, ptr VARIANT
  COM_MTD_STD  put_Color, VARIANT
  COM_MTD_STD  get_ColorIndex, ptr VARIANT
  COM_MTD_STD  put_ColorIndex, VARIANT
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  get_Item, XlBordersIndex, ptr ptr Border
  COM_MTD_STD  get_LineStyle, ptr VARIANT
  COM_MTD_STD  put_LineStyle, VARIANT
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  get_Value, ptr VARIANT
  COM_MTD_STD  put_Value, VARIANT
  COM_MTD_STD  get_Weight, ptr VARIANT
  COM_MTD_STD  put_Weight, VARIANT
  COM_MTD_STD  get__Default, XlBordersIndex, ptr ptr Border
COM_INTERFACE_END

COM_INTERFACE_BEG _Global, IDispatch, <000208D9-0000-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr ptr Application
  COM_MTD_STD  get_ActiveCell, ptr ptr Range
  COM_MTD_STD  get_ActiveChart, ptr ptr Chart
  COM_MTD_STD  get_ActiveDialog, ptr ptr DialogSheet
  COM_MTD_STD  get_ActiveMenuBar, ptr ptr MenuBar
  COM_MTD_STD  get_ActivePrinter, SDWORD, ptr BSTR
  COM_MTD_STD  put_ActivePrinter, SDWORD, BSTR
  COM_MTD_STD  get_ActiveSheet, ptr LPDISPATCH
  COM_MTD_STD  get_ActiveWindow, ptr ptr Window
  COM_MTD_STD  get_ActiveWorkbook, ptr ptr Workbook
  COM_MTD_STD  get_AddIns, ptr ptr AddIns
  COM_MTD_STD  get_Assistant, ptr ptr Assistant
  COM_MTD_STD  Calculate, SDWORD
  COM_MTD_STD  get_Cells, ptr ptr Range
  COM_MTD_STD  get_Charts, ptr ptr Sheets
  COM_MTD_STD  get_Columns, ptr ptr Range
  COM_MTD_STD  get_CommandBars, ptr ptr CommandBars
  COM_MTD_STD  get_DDEAppReturnCode, SDWORD, ptr SDWORD
  COM_MTD_STD  DDEExecute, SDWORD, BSTR, SDWORD
  COM_MTD_STD  DDEInitiate, BSTR, BSTR, SDWORD, ptr SDWORD
  COM_MTD_STD  DDEPoke, SDWORD, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  DDERequest, SDWORD, BSTR, SDWORD, ptr VARIANT
  COM_MTD_STD  DDETerminate, SDWORD, SDWORD
  COM_MTD_STD  get_DialogSheets, ptr ptr Sheets
  COM_MTD_STD  Evaluate, VARIANT, SDWORD, ptr VARIANT
  COM_MTD_STD  _Evaluate, VARIANT, SDWORD, ptr VARIANT
  COM_MTD_STD  ExecuteExcel4Macro, BSTR, SDWORD, ptr VARIANT
;+++   COM_MTD_STD  Intersect, ptr Range, ptr Range, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD, ptr ptr Range
  COM_MTD_STD  Intersect, DWORD
  COM_MTD_STD  get_MenuBars, ptr ptr MenuBars
  COM_MTD_STD  get_Modules, ptr ptr Modules
  COM_MTD_STD  get_Names, ptr ptr Names
  COM_MTD_STD  get_Range, VARIANT, VARIANT, ptr ptr Range
  COM_MTD_STD  get_Rows, ptr ptr Range
;+++   COM_MTD_STD  Run, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  Run, DWORD
;+++   COM_MTD_STD  _Run2, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD, ptr VARIANT
  COM_MTD_STD  _Run2, DWORD
  COM_MTD_STD  get_Selection, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  SendKeys, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get_Sheets, ptr ptr Sheets
  COM_MTD_STD  get_ShortcutMenus, SDWORD, ptr ptr Menu
  COM_MTD_STD  get_ThisWorkbook, SDWORD, ptr ptr Workbook
  COM_MTD_STD  get_Toolbars, ptr ptr Toolbars
;+++   COM_MTD_STD  Union_, ptr Range, ptr Range, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD, ptr ptr Range
  COM_MTD_STD  Union_, DWORD
  COM_MTD_STD  get_Windows, ptr ptr Windows
  COM_MTD_STD  get_Workbooks, ptr ptr Workbooks
  COM_MTD_STD  get_WorksheetFunction, ptr ptr WorksheetFunction
  COM_MTD_STD  get_Worksheets, ptr ptr Sheets
  COM_MTD_STD  get_Excel4IntlMacroSheets, ptr ptr Sheets
  COM_MTD_STD  get_Excel4MacroSheets, ptr ptr Sheets
COM_INTERFACE_END

COM_INTERFACE_BEG IAddIn, IDispatch, <00020857-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Author, ptr BSTR
  COM_MTD_STD  get_Comments, ptr BSTR
  COM_MTD_STD  get_FullName, ptr BSTR
  COM_MTD_STD  get_Installed, ptr BOOL
  COM_MTD_STD  put_Installed, BOOL
  COM_MTD_STD  get_Keywords, ptr BSTR
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  get_Path, ptr BSTR
  COM_MTD_STD  get_Subject, ptr BSTR
  COM_MTD_STD  get_Title, ptr BSTR
  COM_MTD_STD  get_progID, ptr BSTR
  COM_MTD_STD  get_CLSID, ptr BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG IAddIns, IDispatch, <00020858-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Add_, BSTR, VARIANT, ptr ptr AddIn
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  get_Item, VARIANT, ptr ptr AddIn
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  get__Default, VARIANT, ptr ptr AddIn
COM_INTERFACE_END

COM_INTERFACE_BEG IToolbar, IDispatch, <0002085C-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_BuiltIn, ptr BOOL
  COM_MTD_STD  Delete
  COM_MTD_STD  get_Height, ptr SDWORD
  COM_MTD_STD  put_Height, SDWORD
  COM_MTD_STD  get_Left, ptr SDWORD
  COM_MTD_STD  put_Left, SDWORD
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  get_Position, ptr SDWORD
  COM_MTD_STD  put_Position, SDWORD
  COM_MTD_STD  get_Protection, ptr XlToolbarProtection
  COM_MTD_STD  put_Protection, XlToolbarProtection
  COM_MTD_STD  Reset
  COM_MTD_STD  get_ToolbarButtons, ptr ptr ToolbarButtons
  COM_MTD_STD  get_Top, ptr SDWORD
  COM_MTD_STD  put_Top, SDWORD
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr SDWORD
  COM_MTD_STD  put_Width, SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG IToolbars, IDispatch, <0002085D-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Add_, VARIANT, ptr ptr Toolbar
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  get__Default, VARIANT, ptr ptr Toolbar
  COM_MTD_STD  get_Item, VARIANT, ptr ptr Toolbar
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IToolbarButton, IDispatch, <0002085E-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_BuiltIn, ptr BOOL
  COM_MTD_STD  get_BuiltInFace, ptr BOOL
  COM_MTD_STD  put_BuiltInFace, BOOL
  COM_MTD_STD  Copy, ptr Toolbar, SDWORD
  COM_MTD_STD  CopyFace
  COM_MTD_STD  Delete
  COM_MTD_STD  Edit
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_HelpContextID, ptr SDWORD
  COM_MTD_STD  put_HelpContextID, SDWORD
  COM_MTD_STD  get_HelpFile, ptr BSTR
  COM_MTD_STD  put_HelpFile, BSTR
  COM_MTD_STD  get_ID, ptr SDWORD
  COM_MTD_STD  get_IsGap, ptr BOOL
  COM_MTD_STD  Move, ptr Toolbar, SDWORD
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  PasteFace
  COM_MTD_STD  get_Pushed, ptr BOOL
  COM_MTD_STD  put_Pushed, BOOL
  COM_MTD_STD  Reset
  COM_MTD_STD  get_StatusBar, ptr BSTR
  COM_MTD_STD  put_StatusBar, BSTR
  COM_MTD_STD  get_Width, ptr SDWORD
  COM_MTD_STD  put_Width, SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG IToolbarButtons, IDispatch, <0002085F-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Add_, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr ptr ToolbarButton
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  get_Item, SDWORD, ptr ptr ToolbarButton
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  get__Default, SDWORD, ptr ptr ToolbarButton
COM_INTERFACE_END

COM_INTERFACE_BEG IAreas, IDispatch, <00020860-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  get_Item, SDWORD, ptr ptr Range
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  get__Default, SDWORD, ptr ptr Range
COM_INTERFACE_END

COM_INTERFACE_BEG IWorkbookEvents, IDispatch, <00024412-0001-0000-C000-000000000046>
  COM_MTD_STD  Open
  COM_MTD_STD  Activate
  COM_MTD_STD  Deactivate
  COM_MTD_STD  BeforeClose, ptr BOOL
  COM_MTD_STD  BeforeSave, BOOL, ptr BOOL
  COM_MTD_STD  BeforePrint, ptr BOOL
  COM_MTD_STD  NewSheet, LPDISPATCH
  COM_MTD_STD  AddinInstall
  COM_MTD_STD  AddinUninstall
  COM_MTD_STD  WindowResize, ptr Window
  COM_MTD_STD  WindowActivate, ptr Window
  COM_MTD_STD  WindowDeactivate, ptr Window
  COM_MTD_STD  SheetSelectionChange, LPDISPATCH, ptr Range
  COM_MTD_STD  SheetBeforeDoubleClick, LPDISPATCH, ptr Range, ptr BOOL
  COM_MTD_STD  SheetBeforeRightClick, LPDISPATCH, ptr Range, ptr BOOL
  COM_MTD_STD  SheetActivate, LPDISPATCH
  COM_MTD_STD  SheetDeactivate, LPDISPATCH
  COM_MTD_STD  SheetCalculate, LPDISPATCH
  COM_MTD_STD  SheetChange, LPDISPATCH, ptr Range
  COM_MTD_STD  SheetFollowHyperlink, LPDISPATCH, ptr Hyperlink
  COM_MTD_STD  SheetPivotTableUpdate, LPDISPATCH, ptr PivotTable
  COM_MTD_STD  PivotTableCloseConnection, ptr PivotTable
  COM_MTD_STD  PivotTableOpenConnection, ptr PivotTable
COM_INTERFACE_END

COM_INTERFACE_BEG _Workbook, IDispatch, <000208DA-0000-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_AcceptLabelsInFormulas, ptr BOOL
  COM_MTD_STD  put_AcceptLabelsInFormulas, BOOL
  COM_MTD_STD  Activate, SDWORD
  COM_MTD_STD  get_ActiveChart, ptr ptr Chart
  COM_MTD_STD  get_ActiveSheet, ptr LPDISPATCH
  COM_MTD_STD  get_Author, SDWORD, ptr BSTR
  COM_MTD_STD  put_Author, SDWORD, BSTR
  COM_MTD_STD  get_AutoUpdateFrequency, ptr SDWORD
  COM_MTD_STD  put_AutoUpdateFrequency, SDWORD
  COM_MTD_STD  get_AutoUpdateSaveChanges, ptr BOOL
  COM_MTD_STD  put_AutoUpdateSaveChanges, BOOL
  COM_MTD_STD  get_ChangeHistoryDuration, ptr SDWORD
  COM_MTD_STD  put_ChangeHistoryDuration, SDWORD
  COM_MTD_STD  get_BuiltinDocumentProperties, ptr LPDISPATCH
  COM_MTD_STD  ChangeFileAccess, XlFileAccess, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  ChangeLink, BSTR, BSTR, XlLinkType, SDWORD
  COM_MTD_STD  get_Charts, ptr ptr Sheets
  COM_MTD_STD  Close, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get_CodeName, ptr BSTR
  COM_MTD_STD  get__CodeName, ptr BSTR
  COM_MTD_STD  put__CodeName, BSTR
  COM_MTD_STD  get_Colors, VARIANT, SDWORD, ptr VARIANT
  COM_MTD_STD  put_Colors, VARIANT, SDWORD, VARIANT
  COM_MTD_STD  get_CommandBars, ptr ptr CommandBars
  COM_MTD_STD  get_Comments, SDWORD, ptr BSTR
  COM_MTD_STD  put_Comments, SDWORD, BSTR
  COM_MTD_STD  get_ConflictResolution, ptr XlSaveConflictResolution
  COM_MTD_STD  put_ConflictResolution, XlSaveConflictResolution
  COM_MTD_STD  get_Container, ptr LPDISPATCH
  COM_MTD_STD  get_CreateBackup, SDWORD, ptr BOOL
  COM_MTD_STD  get_CustomDocumentProperties, ptr LPDISPATCH
  COM_MTD_STD  get_Date1904, SDWORD, ptr BOOL
  COM_MTD_STD  put_Date1904, SDWORD, BOOL
  COM_MTD_STD  DeleteNumberFormat, BSTR, SDWORD
  COM_MTD_STD  get_DialogSheets, ptr ptr Sheets
  COM_MTD_STD  get_DisplayDrawingObjects, SDWORD, ptr XlDisplayDrawingObjects
  COM_MTD_STD  put_DisplayDrawingObjects, SDWORD, XlDisplayDrawingObjects
  COM_MTD_STD  ExclusiveAccess, SDWORD, ptr BOOL
  COM_MTD_STD  get_FileFormat, SDWORD, ptr XlFileFormat
  COM_MTD_STD  ForwardMailer, SDWORD
  COM_MTD_STD  get_FullName, SDWORD, ptr BSTR
  COM_MTD_STD  get_HasMailer, SDWORD, ptr BOOL
  COM_MTD_STD  put_HasMailer, SDWORD, BOOL
  COM_MTD_STD  get_HasPassword, SDWORD, ptr BOOL
  COM_MTD_STD  get_HasRoutingSlip, SDWORD, ptr BOOL
  COM_MTD_STD  put_HasRoutingSlip, SDWORD, BOOL
  COM_MTD_STD  get_IsAddin, ptr BOOL
  COM_MTD_STD  put_IsAddin, BOOL
  COM_MTD_STD  get_Keywords, SDWORD, ptr BSTR
  COM_MTD_STD  put_Keywords, SDWORD, BSTR
  COM_MTD_STD  LinkInfo, BSTR, XlLinkInfo, VARIANT, VARIANT, SDWORD, ptr VARIANT
  COM_MTD_STD  LinkSources, VARIANT, SDWORD, ptr VARIANT
  COM_MTD_STD  get_Mailer, ptr ptr Mailer
  COM_MTD_STD  MergeWorkbook, VARIANT
  COM_MTD_STD  get_Modules, ptr ptr Sheets
  COM_MTD_STD  get_MultiUserEditing, SDWORD, ptr BOOL
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  get_Names, ptr ptr Names
  COM_MTD_STD  NewWindow, SDWORD, ptr ptr Window
  COM_MTD_STD  get_OnSave, SDWORD, ptr BSTR
  COM_MTD_STD  put_OnSave, SDWORD, BSTR
  COM_MTD_STD  get_OnSheetActivate, SDWORD, ptr BSTR
  COM_MTD_STD  put_OnSheetActivate, SDWORD, BSTR
  COM_MTD_STD  get_OnSheetDeactivate, SDWORD, ptr BSTR
  COM_MTD_STD  put_OnSheetDeactivate, SDWORD, BSTR
  COM_MTD_STD  OpenLinks, BSTR, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get_Path, SDWORD, ptr BSTR
  COM_MTD_STD  get_PersonalViewListSettings, ptr BOOL
  COM_MTD_STD  put_PersonalViewListSettings, BOOL
  COM_MTD_STD  get_PersonalViewPrintSettings, ptr BOOL
  COM_MTD_STD  put_PersonalViewPrintSettings, BOOL
  COM_MTD_STD  PivotCaches, ptr ptr PivotCaches
  COM_MTD_STD  Post, VARIANT, SDWORD
  COM_MTD_STD  get_PrecisionAsDisplayed, SDWORD, ptr BOOL
  COM_MTD_STD  put_PrecisionAsDisplayed, SDWORD, BOOL
  COM_MTD_STD  _PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  PrintPreview, VARIANT, SDWORD
  COM_MTD_STD  _Protect, VARIANT, VARIANT, VARIANT
  COM_MTD_STD  ProtectSharing, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_STD  get_ProtectStructure, ptr BOOL
  COM_MTD_STD  get_ProtectWindows, ptr BOOL
  COM_MTD_STD  get_ReadOnly, SDWORD, ptr BOOL
  COM_MTD_STD  get__ReadOnlyRecommended, SDWORD, ptr BOOL
  COM_MTD_STD  RefreshAll
  COM_MTD_STD  Reply, SDWORD
  COM_MTD_STD  ReplyAll, SDWORD
  COM_MTD_STD  RemoveUser, SDWORD
  COM_MTD_STD  get_RevisionNumber, SDWORD, ptr SDWORD
  COM_MTD_STD  Route, SDWORD
  COM_MTD_STD  get_Routed, SDWORD, ptr BOOL
  COM_MTD_STD  get_RoutingSlip, ptr ptr RoutingSlip
  COM_MTD_STD  RunAutoMacros, XlRunAutoMacro, SDWORD
  COM_MTD_STD  Save, SDWORD
  COM_MTD_STD  _SaveAs, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, XlSaveAsAccessMode, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  SaveCopyAs, VARIANT, SDWORD
  COM_MTD_STD  get_Saved, SDWORD, ptr BOOL
  COM_MTD_STD  put_Saved, SDWORD, BOOL
  COM_MTD_STD  get_SaveLinkValues, SDWORD, ptr BOOL
  COM_MTD_STD  put_SaveLinkValues, SDWORD, BOOL
  COM_MTD_STD  SendMail, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  SendMailer, VARIANT, XlPriority, SDWORD
  COM_MTD_STD  SetLinkOnData, BSTR, VARIANT, SDWORD
  COM_MTD_STD  get_Sheets, ptr ptr Sheets
  COM_MTD_STD  get_ShowConflictHistory, SDWORD, ptr BOOL
  COM_MTD_STD  put_ShowConflictHistory, SDWORD, BOOL
  COM_MTD_STD  get_Styles, ptr ptr Styles
  COM_MTD_STD  get_Subject, SDWORD, ptr BSTR
  COM_MTD_STD  put_Subject, SDWORD, BSTR
  COM_MTD_STD  get_Title, SDWORD, ptr BSTR
  COM_MTD_STD  put_Title, SDWORD, BSTR
  COM_MTD_STD  Unprotect, VARIANT, SDWORD
  COM_MTD_STD  UnprotectSharing, VARIANT
  COM_MTD_STD  UpdateFromFile, SDWORD
  COM_MTD_STD  UpdateLink, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get_UpdateRemoteReferences, SDWORD, ptr BOOL
  COM_MTD_STD  put_UpdateRemoteReferences, SDWORD, BOOL
  COM_MTD_STD  get_UserControl, ptr BOOL
  COM_MTD_STD  put_UserControl, BOOL
  COM_MTD_STD  get_UserStatus, SDWORD, ptr VARIANT
  COM_MTD_STD  get_CustomViews, ptr ptr CustomViews
  COM_MTD_STD  get_Windows, ptr ptr Windows
  COM_MTD_STD  get_Worksheets, ptr ptr Sheets
  COM_MTD_STD  get_WriteReserved, SDWORD, ptr BOOL
  COM_MTD_STD  get_WriteReservedBy, SDWORD, ptr BSTR
  COM_MTD_STD  get_Excel4IntlMacroSheets, ptr ptr Sheets
  COM_MTD_STD  get_Excel4MacroSheets, ptr ptr Sheets
  COM_MTD_STD  get_TemplateRemoveExtData, ptr BOOL
  COM_MTD_STD  put_TemplateRemoveExtData, BOOL
  COM_MTD_STD  HighlightChangesOptions, VARIANT, VARIANT, VARIANT
  COM_MTD_STD  get_HighlightChangesOnScreen, ptr BOOL
  COM_MTD_STD  put_HighlightChangesOnScreen, BOOL
  COM_MTD_STD  get_KeepChangeHistory, ptr BOOL
  COM_MTD_STD  put_KeepChangeHistory, BOOL
  COM_MTD_STD  get_ListChangesOnNewSheet, ptr BOOL
  COM_MTD_STD  put_ListChangesOnNewSheet, BOOL
  COM_MTD_STD  PurgeChangeHistoryNow, SDWORD, VARIANT
  COM_MTD_STD  AcceptAllChanges, VARIANT, VARIANT, VARIANT
  COM_MTD_STD  RejectAllChanges, VARIANT, VARIANT, VARIANT
  COM_MTD_STD  PivotTableWizard, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  ResetColors
  COM_MTD_STD  get_VBProject, ptr ptr VBProject
  COM_MTD_STD  FollowHyperlink, BSTR, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_STD  AddToFavorites
  COM_MTD_STD  get_IsInplace, ptr BOOL
  COM_MTD_STD  PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  WebPagePreview
  COM_MTD_STD  get_PublishObjects, ptr ptr PublishObjects
  COM_MTD_STD  get_WebOptions, ptr ptr WebOptions
  COM_MTD_STD  ReloadAs;, MsoEncoding
  COM_MTD_STD  get_HTMLProject, ptr ptr HTMLProject
  COM_MTD_STD  get_EnvelopeVisible, ptr BOOL
  COM_MTD_STD  put_EnvelopeVisible, BOOL
  COM_MTD_STD  get_CalculationVersion, ptr SDWORD
  COM_MTD_STD  Dummy17, SDWORD
  COM_MTD_STD  sblt, BSTR
  COM_MTD_STD  get_VBASigned, ptr BOOL
  COM_MTD_STD  get_ShowPivotTableFieldList, ptr BOOL
  COM_MTD_STD  put_ShowPivotTableFieldList, BOOL
  COM_MTD_STD  get_UpdateLinks, ptr XlUpdateLinks
  COM_MTD_STD  put_UpdateLinks, XlUpdateLinks
  COM_MTD_STD  BreakLink, BSTR, XlLinkType
  COM_MTD_STD  Dummy16
  COM_MTD_STD  SaveAs, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, XlSaveAsAccessMode, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get_EnableAutoRecover, ptr BOOL
  COM_MTD_STD  put_EnableAutoRecover, BOOL
  COM_MTD_STD  get_RemovePersonalInformation, ptr BOOL
  COM_MTD_STD  put_RemovePersonalInformation, BOOL
  COM_MTD_STD  get_FullNameURLEncoded, SDWORD, ptr BSTR
  COM_MTD_STD  CheckIn, VARIANT, VARIANT, VARIANT
  COM_MTD_STD  CanCheckIn, ptr BOOL
  COM_MTD_STD  SendForReview, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_STD  ReplyWithChanges, VARIANT
  COM_MTD_STD  EndReview
  COM_MTD_STD  get_Password, ptr BSTR
  COM_MTD_STD  put_Password, BSTR
  COM_MTD_STD  get_WritePassword, ptr BSTR
  COM_MTD_STD  put_WritePassword, BSTR
  COM_MTD_STD  get_PasswordEncryptionProvider, ptr BSTR
  COM_MTD_STD  get_PasswordEncryptionAlgorithm, ptr BSTR
  COM_MTD_STD  get_PasswordEncryptionKeyLength, ptr SDWORD
  COM_MTD_STD  SetPasswordEncryptionOptions, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_STD  get_PasswordEncryptionFileProperties, ptr BOOL
  COM_MTD_STD  get_ReadOnlyRecommended, ptr BOOL
  COM_MTD_STD  put_ReadOnlyRecommended, BOOL
  COM_MTD_STD  Protect, VARIANT, VARIANT, VARIANT
  COM_MTD_STD  get_SmartTagOptions, ptr ptr SmartTagOptions
  COM_MTD_STD  RecheckSmartTags
COM_INTERFACE_END

COM_INTERFACE_BEG Workbooks, IDispatch, <000208DB-0000-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Add_, VARIANT, SDWORD, ptr ptr Workbook
  COM_MTD_STD  Close, SDWORD
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  get_Item, VARIANT, ptr ptr Workbook
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  _Open, BSTR, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD, ptr ptr Workbook
  COM_MTD_STD  __OpenText, BSTR, VARIANT, VARIANT, VARIANT, XlTextQualifier, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get__Default, VARIANT, ptr ptr Workbook
  COM_MTD_STD  _OpenText, BSTR, VARIANT, VARIANT, VARIANT, XlTextQualifier, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  Open, BSTR, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD, ptr ptr Workbook
  COM_MTD_STD  OpenText, BSTR, VARIANT, VARIANT, VARIANT, XlTextQualifier, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  OpenDatabase, BSTR, VARIANT, VARIANT, VARIANT, VARIANT, ptr ptr Workbook
  COM_MTD_STD  CheckOut, BSTR
  COM_MTD_STD  CanCheckOut, BSTR, ptr BOOL
  COM_MTD_STD  OpenXML, BSTR, VARIANT, ptr ptr Workbook
COM_INTERFACE_END

COM_INTERFACE_BEG IMenuBars, IDispatch, <00020863-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Add_, VARIANT, ptr ptr MenuBar
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  get__Default, VARIANT, ptr ptr MenuBar
  COM_MTD_STD  get_Item, VARIANT, ptr ptr MenuBar
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IMenuBar, IDispatch, <00020864-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Activate
  COM_MTD_STD  get_BuiltIn, ptr BOOL
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  Delete
  COM_MTD_STD  get_Index, ptr SDWORD
  COM_MTD_STD  get_Menus, ptr ptr Menus
  COM_MTD_STD  Reset
COM_INTERFACE_END

COM_INTERFACE_BEG IMenus, IDispatch, <00020865-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Add_, BSTR, VARIANT, VARIANT, ptr ptr Menu
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  get__Default, VARIANT, ptr ptr Menu
  COM_MTD_STD  get_Item, VARIANT, ptr ptr Menu
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IMenu, IDispatch, <00020866-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  Delete
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Index, ptr SDWORD
  COM_MTD_STD  get_MenuItems, ptr ptr MenuItems
COM_INTERFACE_END

COM_INTERFACE_BEG IMenuItems, IDispatch, <00020867-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Add_, BSTR, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr ptr MenuItem
  COM_MTD_STD  AddMenu, BSTR, VARIANT, VARIANT, ptr ptr Menu
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  get__Default, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  get_Item, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IMenuItem, IDispatch, <00020868-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_Checked, ptr BOOL
  COM_MTD_STD  put_Checked, BOOL
  COM_MTD_STD  Delete
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_HelpContextID, ptr SDWORD
  COM_MTD_STD  put_HelpContextID, SDWORD
  COM_MTD_STD  get_HelpFile, ptr BSTR
  COM_MTD_STD  put_HelpFile, BSTR
  COM_MTD_STD  get_Index, ptr SDWORD
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_StatusBar, ptr BSTR
  COM_MTD_STD  put_StatusBar, BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG ICharts, IDispatch, <0002086D-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Add_, VARIANT, VARIANT, VARIANT, ptr ptr Chart
  COM_MTD_STD  Copy, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Delete, SDWORD
  COM_MTD_STD  _Dummy7
  COM_MTD_STD  get_Item, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  Move, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  _PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  PrintPreview, VARIANT, SDWORD
  COM_MTD_STD  Select, VARIANT, SDWORD
  COM_MTD_STD  get_HPageBreaks, ptr ptr HPageBreaks
  COM_MTD_STD  get_VPageBreaks, ptr ptr VPageBreaks
  COM_MTD_STD  get_Visible, SDWORD, ptr VARIANT
  COM_MTD_STD  put_Visible, SDWORD, VARIANT
  COM_MTD_STD  get__Default, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG IDrawingObjects, IDispatch, <0002086F-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  _Dummy3
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  _Dummy12
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  _Dummy15
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  _Dummy22
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get_Accelerator, ptr VARIANT
  COM_MTD_STD  put_Accelerator, VARIANT
  COM_MTD_STD  _Dummy28
  COM_MTD_STD  get_AddIndent, ptr BOOL
  COM_MTD_STD  put_AddIndent, BOOL
  COM_MTD_STD  AddItem, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_ArrowHeadLength, ptr VARIANT
  COM_MTD_STD  put_ArrowHeadLength, VARIANT
  COM_MTD_STD  get_ArrowHeadStyle, ptr VARIANT
  COM_MTD_STD  put_ArrowHeadStyle, VARIANT
  COM_MTD_STD  get_ArrowHeadWidth, ptr VARIANT
  COM_MTD_STD  put_ArrowHeadWidth, VARIANT
  COM_MTD_STD  get_AutoSize, ptr BOOL
  COM_MTD_STD  put_AutoSize, BOOL
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  get_CancelButton, ptr BOOL
  COM_MTD_STD  put_CancelButton, BOOL
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_STD  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get__Default, ptr SDWORD
  COM_MTD_STD  put__Default, SDWORD
  COM_MTD_STD  get_DefaultButton, ptr BOOL
  COM_MTD_STD  put_DefaultButton, BOOL
  COM_MTD_STD  get_DismissButton, ptr BOOL
  COM_MTD_STD  put_DismissButton, BOOL
  COM_MTD_STD  get_Display3DShading, ptr BOOL
  COM_MTD_STD  put_Display3DShading, BOOL
  COM_MTD_STD  get_DisplayVerticalScrollBar, ptr BOOL
  COM_MTD_STD  put_DisplayVerticalScrollBar, BOOL
  COM_MTD_STD  get_DropDownLines, ptr SDWORD
  COM_MTD_STD  put_DropDownLines, SDWORD
  COM_MTD_STD  get_Font, ptr ptr Font
  COM_MTD_STD  _Dummy47
  COM_MTD_STD  get_HelpButton, ptr BOOL
  COM_MTD_STD  put_HelpButton, BOOL
  COM_MTD_STD  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_STD  put_HorizontalAlignment, VARIANT
  COM_MTD_STD  get_InputType, ptr SDWORD
  COM_MTD_STD  put_InputType, SDWORD
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_LargeChange, ptr SDWORD
  COM_MTD_STD  put_LargeChange, SDWORD
  COM_MTD_STD  get_LinkedCell, ptr BSTR
  COM_MTD_STD  put_LinkedCell, BSTR
  COM_MTD_STD  _Dummy54
  COM_MTD_STD  List, VARIANT, ptr VARIANT
  COM_MTD_STD  _Dummy56
  COM_MTD_STD  get_ListFillRange, ptr BSTR
  COM_MTD_STD  put_ListFillRange, BSTR
  COM_MTD_STD  get_ListIndex, ptr SDWORD
  COM_MTD_STD  put_ListIndex, SDWORD
  COM_MTD_STD  get_LockedText, ptr BOOL
  COM_MTD_STD  put_LockedText, BOOL
  COM_MTD_STD  get_Max, ptr SDWORD
  COM_MTD_STD  put_Max, SDWORD
  COM_MTD_STD  get_Min, ptr SDWORD
  COM_MTD_STD  put_Min, SDWORD
  COM_MTD_STD  get_MultiLine, ptr BOOL
  COM_MTD_STD  put_MultiLine, BOOL
  COM_MTD_STD  get_MultiSelect, ptr BOOL
  COM_MTD_STD  put_MultiSelect, BOOL
  COM_MTD_STD  get_Orientation, ptr VARIANT
  COM_MTD_STD  put_Orientation, VARIANT
  COM_MTD_STD  get_PhoneticAccelerator, ptr VARIANT
  COM_MTD_STD  put_PhoneticAccelerator, VARIANT
  COM_MTD_STD  RemoveAllItems, ptr VARIANT
  COM_MTD_STD  RemoveItem, SDWORD, VARIANT, ptr VARIANT
  COM_MTD_STD  Reshape, SDWORD, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_RoundedCorners, ptr BOOL
  COM_MTD_STD  put_RoundedCorners, BOOL
  COM_MTD_STD  Selected, VARIANT, ptr VARIANT
  COM_MTD_STD  get_Shadow, ptr BOOL
  COM_MTD_STD  put_Shadow, BOOL
  COM_MTD_STD  get_SmallChange, ptr SDWORD
  COM_MTD_STD  put_SmallChange, SDWORD
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
  COM_MTD_STD  Ungroup, ptr LPDISPATCH
  COM_MTD_STD  get_Value, ptr SDWORD
  COM_MTD_STD  put_Value, SDWORD
  COM_MTD_STD  get_VerticalAlignment, ptr VARIANT
  COM_MTD_STD  put_VerticalAlignment, VARIANT
  COM_MTD_STD  Vertices, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_ReadingOrder, ptr SDWORD
  COM_MTD_STD  put_ReadingOrder, SDWORD
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  Group_, ptr ptr GroupObject
  COM_MTD_STD  LinkCombo, VARIANT, ptr VARIANT
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IPivotCache, IDispatch, <0002441C-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_BackgroundQuery, ptr BOOL
  COM_MTD_STD  put_BackgroundQuery, BOOL
  COM_MTD_STD  get_Connection, ptr VARIANT
  COM_MTD_STD  put_Connection, VARIANT
  COM_MTD_STD  get_EnableRefresh, ptr BOOL
  COM_MTD_STD  put_EnableRefresh, BOOL
  COM_MTD_STD  get_Index, ptr SDWORD
  COM_MTD_STD  get_MemoryUsed, ptr SDWORD
  COM_MTD_STD  get_OptimizeCache, ptr BOOL
  COM_MTD_STD  put_OptimizeCache, BOOL
  COM_MTD_STD  get_RecordCount, ptr SDWORD
  COM_MTD_STD  Refresh
  COM_MTD_STD  get_RefreshDate, ptr Date
  COM_MTD_STD  get_RefreshName, ptr BSTR
  COM_MTD_STD  get_RefreshOnFileOpen, ptr BOOL
  COM_MTD_STD  put_RefreshOnFileOpen, BOOL
  COM_MTD_STD  get_Sql, ptr VARIANT
  COM_MTD_STD  put_Sql, VARIANT
  COM_MTD_STD  get_SavePassword, ptr BOOL
  COM_MTD_STD  put_SavePassword, BOOL
  COM_MTD_STD  get_SourceData, ptr VARIANT
  COM_MTD_STD  put_SourceData, VARIANT
  COM_MTD_STD  get_CommandText, ptr VARIANT
  COM_MTD_STD  put_CommandText, VARIANT
  COM_MTD_STD  get_CommandType, ptr XlCmdType
  COM_MTD_STD  put_CommandType, XlCmdType
  COM_MTD_STD  get_QueryType, ptr XlQueryType
  COM_MTD_STD  get_MaintainConnection, ptr BOOL
  COM_MTD_STD  put_MaintainConnection, BOOL
  COM_MTD_STD  get_RefreshPeriod, ptr SDWORD
  COM_MTD_STD  put_RefreshPeriod, SDWORD
  COM_MTD_STD  get_Recordset, ptr LPDISPATCH
  COM_MTD_STD  putref_Recordset, LPDISPATCH
  COM_MTD_STD  ResetTimer
  COM_MTD_STD  get_LocalConnection, ptr VARIANT
  COM_MTD_STD  put_LocalConnection, VARIANT
  COM_MTD_STD  CreatePivotTable, VARIANT, VARIANT, VARIANT, VARIANT, ptr ptr PivotTable
  COM_MTD_STD  get_UseLocalConnection, ptr BOOL
  COM_MTD_STD  put_UseLocalConnection, BOOL
  COM_MTD_STD  get_ADOConnection, ptr LPDISPATCH
  COM_MTD_STD  get_IsConnected, ptr BOOL
  COM_MTD_STD  MakeConnection
  COM_MTD_STD  get_OLAP, ptr BOOL
  COM_MTD_STD  get_SourceType, ptr XlPivotTableSourceType
  COM_MTD_STD  get_MissingItemsLimit, ptr XlPivotTableMissingItems
  COM_MTD_STD  put_MissingItemsLimit, XlPivotTableMissingItems
  COM_MTD_STD  get_SourceConnectionFile, ptr BSTR
  COM_MTD_STD  put_SourceConnectionFile, BSTR
  COM_MTD_STD  get_SourceDataFile, ptr BSTR
  COM_MTD_STD  get_RobustConnect, ptr XlRobustConnect
  COM_MTD_STD  put_RobustConnect, XlRobustConnect
  COM_MTD_STD  SaveAsODC, BSTR, VARIANT, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG IPivotCaches, IDispatch, <0002441D-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Item, VARIANT, ptr ptr PivotCache
  COM_MTD_STD  get__Default, VARIANT, ptr ptr PivotCache
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  Add_, XlPivotTableSourceType, VARIANT, ptr ptr PivotCache
COM_INTERFACE_END

COM_INTERFACE_BEG IPivotFormula, IDispatch, <0002441E-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Delete
  COM_MTD_STD  get__Default, ptr BSTR
  COM_MTD_STD  put__Default, BSTR
  COM_MTD_STD  get_Formula, ptr BSTR
  COM_MTD_STD  put_Formula, BSTR
  COM_MTD_STD  get_Value, ptr BSTR
  COM_MTD_STD  put_Value, BSTR
  COM_MTD_STD  get_Index, ptr SDWORD
  COM_MTD_STD  put_Index, SDWORD
  COM_MTD_STD  get_StandardFormula, ptr BSTR
  COM_MTD_STD  put_StandardFormula, BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG IPivotFormulas, IDispatch, <0002441F-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  _Add, BSTR, ptr ptr PivotFormula
  COM_MTD_STD  Item, VARIANT, ptr ptr PivotFormula
  COM_MTD_STD  get__Default, VARIANT, ptr ptr PivotFormula
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  Add_, BSTR, VARIANT, ptr ptr PivotFormula
COM_INTERFACE_END

COM_INTERFACE_BEG IPivotTable, IDispatch, <00020872-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  AddFields, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_ColumnFields, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  get_ColumnGrand, ptr BOOL
  COM_MTD_STD  put_ColumnGrand, BOOL
  COM_MTD_STD  get_ColumnRange, ptr ptr Range
  COM_MTD_STD  ShowPages, VARIANT, ptr VARIANT
  COM_MTD_STD  get_DataBodyRange, ptr ptr Range
  COM_MTD_STD  get_DataFields, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  get_DataLabelRange, ptr ptr Range
  COM_MTD_STD  get__Default, ptr BSTR
  COM_MTD_STD  put__Default, BSTR
  COM_MTD_STD  get_HasAutoFormat, ptr BOOL
  COM_MTD_STD  put_HasAutoFormat, BOOL
  COM_MTD_STD  get_HiddenFields, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  get_InnerDetail, ptr BSTR
  COM_MTD_STD  put_InnerDetail, BSTR
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_PageFields, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  get_PageRange, ptr ptr Range
  COM_MTD_STD  get_PageRangeCells, ptr ptr Range
  COM_MTD_STD  PivotFields, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  get_RefreshDate, ptr Date
  COM_MTD_STD  get_RefreshName, ptr BSTR
  COM_MTD_STD  RefreshTable, ptr BOOL
  COM_MTD_STD  get_RowFields, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  get_RowGrand, ptr BOOL
  COM_MTD_STD  put_RowGrand, BOOL
  COM_MTD_STD  get_RowRange, ptr ptr Range
  COM_MTD_STD  get_SaveData, ptr BOOL
  COM_MTD_STD  put_SaveData, BOOL
  COM_MTD_STD  get_SourceData, ptr VARIANT
  COM_MTD_STD  put_SourceData, VARIANT
  COM_MTD_STD  get_TableRange1, ptr ptr Range
  COM_MTD_STD  get_TableRange2, ptr ptr Range
  COM_MTD_STD  get_Value, ptr BSTR
  COM_MTD_STD  put_Value, BSTR
  COM_MTD_STD  get_VisibleFields, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  get_CacheIndex, ptr SDWORD
  COM_MTD_STD  put_CacheIndex, SDWORD
  COM_MTD_STD  CalculatedFields, ptr ptr CalculatedFields
  COM_MTD_STD  get_DisplayErrorString, ptr BOOL
  COM_MTD_STD  put_DisplayErrorString, BOOL
  COM_MTD_STD  get_DisplayNullString, ptr BOOL
  COM_MTD_STD  put_DisplayNullString, BOOL
  COM_MTD_STD  get_EnableDrilldown, ptr BOOL
  COM_MTD_STD  put_EnableDrilldown, BOOL
  COM_MTD_STD  get_EnableFieldDialog, ptr BOOL
  COM_MTD_STD  put_EnableFieldDialog, BOOL
  COM_MTD_STD  get_EnableWizard, ptr BOOL
  COM_MTD_STD  put_EnableWizard, BOOL
  COM_MTD_STD  get_ErrorString, ptr BSTR
  COM_MTD_STD  put_ErrorString, BSTR
  COM_MTD_STD  GetData, BSTR, ptr REAL8
  COM_MTD_STD  ListFormulas
  COM_MTD_STD  get_ManualUpdate, ptr BOOL
  COM_MTD_STD  put_ManualUpdate, BOOL
  COM_MTD_STD  get_MergeLabels, ptr BOOL
  COM_MTD_STD  put_MergeLabels, BOOL
  COM_MTD_STD  get_NullString, ptr BSTR
  COM_MTD_STD  put_NullString, BSTR
  COM_MTD_STD  PivotCache, ptr ptr PivotCache
  COM_MTD_STD  get_PivotFormulas, ptr ptr PivotFormulas
  COM_MTD_STD  PivotTableWizard, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_STD  get_SubtotalHiddenPageItems, ptr BOOL
  COM_MTD_STD  put_SubtotalHiddenPageItems, BOOL
  COM_MTD_STD  get_PageFieldOrder, ptr SDWORD
  COM_MTD_STD  put_PageFieldOrder, SDWORD
  COM_MTD_STD  get_PageFieldStyle, ptr BSTR
  COM_MTD_STD  put_PageFieldStyle, BSTR
  COM_MTD_STD  get_PageFieldWrapCount, ptr SDWORD
  COM_MTD_STD  put_PageFieldWrapCount, SDWORD
  COM_MTD_STD  get_PreserveFormatting, ptr BOOL
  COM_MTD_STD  put_PreserveFormatting, BOOL
  COM_MTD_STD  _PivotSelect, BSTR, XlPTSelectionMode
  COM_MTD_STD  get_PivotSelection, ptr BSTR
  COM_MTD_STD  put_PivotSelection, BSTR
  COM_MTD_STD  get_SelectionMode, ptr XlPTSelectionMode
  COM_MTD_STD  put_SelectionMode, XlPTSelectionMode
  COM_MTD_STD  get_TableStyle, ptr BSTR
  COM_MTD_STD  put_TableStyle, BSTR
  COM_MTD_STD  get_Tag, ptr BSTR
  COM_MTD_STD  put_Tag, BSTR
  COM_MTD_STD  Update
  COM_MTD_STD  get_VacatedStyle, ptr BSTR
  COM_MTD_STD  put_VacatedStyle, BSTR
  COM_MTD_STD  Format, XlPivotFormatType
  COM_MTD_STD  get_PrintTitles, ptr BOOL
  COM_MTD_STD  put_PrintTitles, BOOL
  COM_MTD_STD  get_CubeFields, ptr ptr CubeFields
  COM_MTD_STD  get_GrandTotalName, ptr BSTR
  COM_MTD_STD  put_GrandTotalName, BSTR
  COM_MTD_STD  get_SmallGrid, ptr BOOL
  COM_MTD_STD  put_SmallGrid, BOOL
  COM_MTD_STD  get_RepeatItemsOnEachPrintedPage, ptr BOOL
  COM_MTD_STD  put_RepeatItemsOnEachPrintedPage, BOOL
  COM_MTD_STD  get_TotalsAnnotation, ptr BOOL
  COM_MTD_STD  put_TotalsAnnotation, BOOL
  COM_MTD_STD  PivotSelect, BSTR, XlPTSelectionMode, VARIANT
  COM_MTD_STD  get_PivotSelectionStandard, ptr BSTR
  COM_MTD_STD  put_PivotSelectionStandard, BSTR
;+++   COM_MTD_STD  GetPivotData, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr ptr Range
  COM_MTD_STD  GetPivotData, DWORD
  COM_MTD_STD  get_DataPivotField, ptr ptr PivotField
  COM_MTD_STD  get_EnableDataValueEditing, ptr BOOL
  COM_MTD_STD  put_EnableDataValueEditing, BOOL
  COM_MTD_STD  AddDataField, LPDISPATCH, VARIANT, VARIANT, ptr ptr PivotField
  COM_MTD_STD  get_MDX, ptr BSTR
  COM_MTD_STD  get_ViewCalculatedMembers, ptr BOOL
  COM_MTD_STD  put_ViewCalculatedMembers, BOOL
  COM_MTD_STD  get_CalculatedMembers, ptr ptr CalculatedMembers
  COM_MTD_STD  get_DisplayImmediateItems, ptr BOOL
  COM_MTD_STD  put_DisplayImmediateItems, BOOL
;+++   COM_MTD_STD  Dummy15, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  Dummy15, DWORD
  COM_MTD_STD  get_EnableFieldList, ptr BOOL
  COM_MTD_STD  put_EnableFieldList, BOOL
  COM_MTD_STD  get_VisualTotals, ptr BOOL
  COM_MTD_STD  put_VisualTotals, BOOL
  COM_MTD_STD  get_ShowPageMultipleItemLabel, ptr BOOL
  COM_MTD_STD  put_ShowPageMultipleItemLabel, BOOL
  COM_MTD_STD  get_Version, ptr XlPivotTableVersionList
  COM_MTD_STD  CreateCubeFile, BSTR, VARIANT, VARIANT, VARIANT, VARIANT, ptr BSTR
  COM_MTD_STD  get_DisplayEmptyRow, ptr BOOL
  COM_MTD_STD  put_DisplayEmptyRow, BOOL
  COM_MTD_STD  get_DisplayEmptyColumn, ptr BOOL
  COM_MTD_STD  put_DisplayEmptyColumn, BOOL
  COM_MTD_STD  get_ShowCellBackgroundFromOLAP, ptr BOOL
  COM_MTD_STD  put_ShowCellBackgroundFromOLAP, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG IPivotTables, IDispatch, <00020873-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Item, VARIANT, ptr ptr PivotTable
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  Add_, ptr PivotCache, VARIANT, VARIANT, VARIANT, VARIANT, ptr ptr PivotTable
COM_INTERFACE_END

COM_INTERFACE_BEG IPivotField, IDispatch, <00020874-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Calculation, ptr XlPivotFieldCalculation
  COM_MTD_STD  put_Calculation, XlPivotFieldCalculation
  COM_MTD_STD  get_ChildField, ptr ptr PivotField
  COM_MTD_STD  get_ChildItems, VARIANT, ptr VARIANT
  COM_MTD_STD  get_CurrentPage, ptr VARIANT
  COM_MTD_STD  put_CurrentPage, VARIANT
  COM_MTD_STD  get_DataRange, ptr ptr Range
  COM_MTD_STD  get_DataType, ptr XlPivotFieldDataType
  COM_MTD_STD  get__Default, ptr BSTR
  COM_MTD_STD  put__Default, BSTR
  COM_MTD_STD  get_Function, ptr XlConsolidationFunction
  COM_MTD_STD  put_Function, XlConsolidationFunction
  COM_MTD_STD  get_GroupLevel, ptr VARIANT
  COM_MTD_STD  get_HiddenItems, VARIANT, ptr VARIANT
  COM_MTD_STD  get_LabelRange, ptr ptr Range
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_NumberFormat, ptr BSTR
  COM_MTD_STD  put_NumberFormat, BSTR
  COM_MTD_STD  get_Orientation, ptr XlPivotFieldOrientation
  COM_MTD_STD  put_Orientation, XlPivotFieldOrientation
  COM_MTD_STD  get_ShowAllItems, ptr BOOL
  COM_MTD_STD  put_ShowAllItems, BOOL
  COM_MTD_STD  get_ParentField, ptr ptr PivotField
  COM_MTD_STD  get_ParentItems, VARIANT, ptr VARIANT
  COM_MTD_STD  PivotItems, VARIANT, ptr VARIANT
  COM_MTD_STD  get_Position, ptr VARIANT
  COM_MTD_STD  put_Position, VARIANT
  COM_MTD_STD  get_SourceName, ptr BSTR
  COM_MTD_STD  get_Subtotals, VARIANT, ptr VARIANT
  COM_MTD_STD  put_Subtotals, VARIANT, VARIANT
  COM_MTD_STD  get_BaseField, ptr VARIANT
  COM_MTD_STD  put_BaseField, VARIANT
  COM_MTD_STD  get_BaseItem, ptr VARIANT
  COM_MTD_STD  put_BaseItem, VARIANT
  COM_MTD_STD  get_TotalLevels, ptr VARIANT
  COM_MTD_STD  get_Value, ptr BSTR
  COM_MTD_STD  put_Value, BSTR
  COM_MTD_STD  get_VisibleItems, VARIANT, ptr VARIANT
  COM_MTD_STD  CalculatedItems, ptr ptr CalculatedItems
  COM_MTD_STD  Delete
  COM_MTD_STD  get_DragToColumn, ptr BOOL
  COM_MTD_STD  put_DragToColumn, BOOL
  COM_MTD_STD  get_DragToHide, ptr BOOL
  COM_MTD_STD  put_DragToHide, BOOL
  COM_MTD_STD  get_DragToPage, ptr BOOL
  COM_MTD_STD  put_DragToPage, BOOL
  COM_MTD_STD  get_DragToRow, ptr BOOL
  COM_MTD_STD  put_DragToRow, BOOL
  COM_MTD_STD  get_DragToData, ptr BOOL
  COM_MTD_STD  put_DragToData, BOOL
  COM_MTD_STD  get_Formula, ptr BSTR
  COM_MTD_STD  put_Formula, BSTR
  COM_MTD_STD  get_IsCalculated, ptr BOOL
  COM_MTD_STD  get_MemoryUsed, ptr SDWORD
  COM_MTD_STD  get_ServerBased, ptr BOOL
  COM_MTD_STD  put_ServerBased, BOOL
  COM_MTD_STD  AutoSort, SDWORD, BSTR
  COM_MTD_STD  AutoShow, SDWORD, SDWORD, SDWORD, BSTR
  COM_MTD_STD  get_AutoSortOrder, ptr SDWORD
  COM_MTD_STD  get_AutoSortField, ptr BSTR
  COM_MTD_STD  get_AutoShowType, ptr SDWORD
  COM_MTD_STD  get_AutoShowRange, ptr SDWORD
  COM_MTD_STD  get_AutoShowCount, ptr SDWORD
  COM_MTD_STD  get_AutoShowField, ptr BSTR
  COM_MTD_STD  get_LayoutBlankLine, ptr BOOL
  COM_MTD_STD  put_LayoutBlankLine, BOOL
  COM_MTD_STD  get_LayoutSubtotalLocation, ptr XlSubtototalLocationType
  COM_MTD_STD  put_LayoutSubtotalLocation, XlSubtototalLocationType
  COM_MTD_STD  get_LayoutPageBreak, ptr BOOL
  COM_MTD_STD  put_LayoutPageBreak, BOOL
  COM_MTD_STD  get_LayoutForm, ptr XlLayoutFormType
  COM_MTD_STD  put_LayoutForm, XlLayoutFormType
  COM_MTD_STD  get_SubtotalName, ptr BSTR
  COM_MTD_STD  put_SubtotalName, BSTR
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_DrilledDown, ptr BOOL
  COM_MTD_STD  put_DrilledDown, BOOL
  COM_MTD_STD  get_CubeField, ptr ptr CubeField
  COM_MTD_STD  get_CurrentPageName, ptr BSTR
  COM_MTD_STD  put_CurrentPageName, BSTR
  COM_MTD_STD  get_StandardFormula, ptr BSTR
  COM_MTD_STD  put_StandardFormula, BSTR
  COM_MTD_STD  get_HiddenItemsList, ptr VARIANT
  COM_MTD_STD  put_HiddenItemsList, VARIANT
  COM_MTD_STD  get_DatabaseSort, ptr BOOL
  COM_MTD_STD  put_DatabaseSort, BOOL
  COM_MTD_STD  get_IsMemberProperty, ptr BOOL
  COM_MTD_STD  get_PropertyParentField, ptr ptr PivotField
  COM_MTD_STD  get_PropertyOrder, ptr SDWORD
  COM_MTD_STD  put_PropertyOrder, SDWORD
  COM_MTD_STD  get_EnableItemSelection, ptr BOOL
  COM_MTD_STD  put_EnableItemSelection, BOOL
  COM_MTD_STD  get_CurrentPageList, ptr VARIANT
  COM_MTD_STD  put_CurrentPageList, VARIANT
  COM_MTD_STD  AddPageItem, BSTR, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG IPivotFields, IDispatch, <00020875-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr ptr PivotTable
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG ICalculatedFields, IDispatch, <00024420-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  _Add, BSTR, BSTR, ptr ptr PivotField
  COM_MTD_STD  Item, VARIANT, ptr ptr PivotField
  COM_MTD_STD  get__Default, VARIANT, ptr ptr PivotField
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  Add_, BSTR, BSTR, VARIANT, ptr ptr PivotField
COM_INTERFACE_END

COM_INTERFACE_BEG IPivotItem, IDispatch, <00020876-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr ptr PivotField
  COM_MTD_STD  get_ChildItems, VARIANT, ptr VARIANT
  COM_MTD_STD  get_DataRange, ptr ptr Range
  COM_MTD_STD  get__Default, ptr BSTR
  COM_MTD_STD  put__Default, BSTR
  COM_MTD_STD  get_LabelRange, ptr ptr Range
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_ParentItem, ptr ptr PivotItem
  COM_MTD_STD  get_ParentShowDetail, ptr BOOL
  COM_MTD_STD  get_Position, ptr SDWORD
  COM_MTD_STD  put_Position, SDWORD
  COM_MTD_STD  get_ShowDetail, ptr BOOL
  COM_MTD_STD  put_ShowDetail, BOOL
  COM_MTD_STD  get_SourceName, ptr VARIANT
  COM_MTD_STD  get_Value, ptr BSTR
  COM_MTD_STD  put_Value, BSTR
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  Delete
  COM_MTD_STD  get_IsCalculated, ptr BOOL
  COM_MTD_STD  get_RecordCount, ptr SDWORD
  COM_MTD_STD  get_Formula, ptr BSTR
  COM_MTD_STD  put_Formula, BSTR
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_DrilledDown, ptr BOOL
  COM_MTD_STD  put_DrilledDown, BOOL
  COM_MTD_STD  get_StandardFormula, ptr BSTR
  COM_MTD_STD  put_StandardFormula, BSTR
  COM_MTD_STD  get_SourceNameStandard, ptr BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG IPivotItems, IDispatch, <00020877-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr ptr PivotField
  COM_MTD_STD  Add_, BSTR
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG ICalculatedItems, IDispatch, <00024421-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  _Add, BSTR, BSTR, ptr ptr PivotItem
  COM_MTD_STD  Item, VARIANT, ptr ptr PivotItem
  COM_MTD_STD  get__Default, VARIANT, ptr ptr PivotItem
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  Add_, BSTR, BSTR, VARIANT, ptr ptr PivotItem
COM_INTERFACE_END

COM_INTERFACE_BEG ICharacters, IDispatch, <00020878-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  get_Font, ptr ptr Font
  COM_MTD_STD  Insert, BSTR, ptr VARIANT
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
  COM_MTD_STD  get_PhoneticCharacters, ptr BSTR
  COM_MTD_STD  put_PhoneticCharacters, BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG IDialogs, IDispatch, <00020879-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  get_Item, XlBuiltInDialog, ptr ptr Dialog
  COM_MTD_STD  get__Default, XlBuiltInDialog, ptr ptr Dialog
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IDialog, IDispatch, <0002087A-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
;+++   COM_MTD_STD  Show, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr BOOL
  COM_MTD_STD  Show, DWORD
COM_INTERFACE_END

COM_INTERFACE_BEG ISoundNote, IDispatch, <0002087B-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Import, BSTR, ptr VARIANT
  COM_MTD_STD  Play, ptr VARIANT
  COM_MTD_STD  Record_, ptr VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG IButton, IDispatch, <0002087D-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_BottomRightCell, ptr ptr Range
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  get_Index, ptr SDWORD
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  get_TopLeftCell, ptr ptr Range
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get_AddIndent, ptr BOOL
  COM_MTD_STD  put_AddIndent, BOOL
  COM_MTD_STD  get_AutoScaleFont, ptr VARIANT
  COM_MTD_STD  put_AutoScaleFont, VARIANT
  COM_MTD_STD  get_AutoSize, ptr BOOL
  COM_MTD_STD  put_AutoSize, BOOL
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_STD  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_Font, ptr ptr Font
  COM_MTD_STD  get_Formula, ptr BSTR
  COM_MTD_STD  put_Formula, BSTR
  COM_MTD_STD  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_STD  put_HorizontalAlignment, VARIANT
  COM_MTD_STD  get_LockedText, ptr BOOL
  COM_MTD_STD  put_LockedText, BOOL
  COM_MTD_STD  get_Orientation, ptr VARIANT
  COM_MTD_STD  put_Orientation, VARIANT
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
  COM_MTD_STD  get_VerticalAlignment, ptr VARIANT
  COM_MTD_STD  put_VerticalAlignment, VARIANT
  COM_MTD_STD  get_ReadingOrder, ptr SDWORD
  COM_MTD_STD  put_ReadingOrder, SDWORD
  COM_MTD_STD  get_Accelerator, ptr VARIANT
  COM_MTD_STD  put_Accelerator, VARIANT
  COM_MTD_STD  get_CancelButton, ptr BOOL
  COM_MTD_STD  put_CancelButton, BOOL
  COM_MTD_STD  get_DefaultButton, ptr BOOL
  COM_MTD_STD  put_DefaultButton, BOOL
  COM_MTD_STD  get_DismissButton, ptr BOOL
  COM_MTD_STD  put_DismissButton, BOOL
  COM_MTD_STD  get_HelpButton, ptr BOOL
  COM_MTD_STD  put_HelpButton, BOOL
  COM_MTD_STD  get_PhoneticAccelerator, ptr VARIANT
  COM_MTD_STD  put_PhoneticAccelerator, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG IButtons, IDispatch, <0002087E-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  _Dummy3
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  _Dummy12
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  _Dummy15
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  _Dummy22
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get_AddIndent, ptr BOOL
  COM_MTD_STD  put_AddIndent, BOOL
  COM_MTD_STD  get_AutoScaleFont, ptr VARIANT
  COM_MTD_STD  put_AutoScaleFont, VARIANT
  COM_MTD_STD  get_AutoSize, ptr BOOL
  COM_MTD_STD  put_AutoSize, BOOL
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_STD  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_Font, ptr ptr Font
  COM_MTD_STD  get_Formula, ptr BSTR
  COM_MTD_STD  put_Formula, BSTR
  COM_MTD_STD  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_STD  put_HorizontalAlignment, VARIANT
  COM_MTD_STD  get_LockedText, ptr BOOL
  COM_MTD_STD  put_LockedText, BOOL
  COM_MTD_STD  get_Orientation, ptr VARIANT
  COM_MTD_STD  put_Orientation, VARIANT
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
  COM_MTD_STD  get_VerticalAlignment, ptr VARIANT
  COM_MTD_STD  put_VerticalAlignment, VARIANT
  COM_MTD_STD  get_ReadingOrder, ptr SDWORD
  COM_MTD_STD  put_ReadingOrder, SDWORD
  COM_MTD_STD  get_Accelerator, ptr VARIANT
  COM_MTD_STD  put_Accelerator, VARIANT
  COM_MTD_STD  get_CancelButton, ptr BOOL
  COM_MTD_STD  put_CancelButton, BOOL
  COM_MTD_STD  get_DefaultButton, ptr BOOL
  COM_MTD_STD  put_DefaultButton, BOOL
  COM_MTD_STD  get_DismissButton, ptr BOOL
  COM_MTD_STD  put_DismissButton, BOOL
  COM_MTD_STD  get_HelpButton, ptr BOOL
  COM_MTD_STD  put_HelpButton, BOOL
  COM_MTD_STD  get_PhoneticAccelerator, ptr VARIANT
  COM_MTD_STD  put_PhoneticAccelerator, VARIANT
  COM_MTD_STD  Add_, REAL8, REAL8, REAL8, REAL8, ptr ptr Button
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Group_, ptr ptr GroupObject
  COM_MTD_STD  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG ICheckBox, IDispatch, <0002087F-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_BottomRightCell, ptr ptr Range
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  get_Index, ptr SDWORD
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  get_TopLeftCell, ptr ptr Range
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_STD  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_LockedText, ptr BOOL
  COM_MTD_STD  put_LockedText, BOOL
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
  COM_MTD_STD  get_Accelerator, ptr VARIANT
  COM_MTD_STD  put_Accelerator, VARIANT
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  get__Default, ptr SDWORD
  COM_MTD_STD  put__Default, SDWORD
  COM_MTD_STD  get_Display3DShading, ptr BOOL
  COM_MTD_STD  put_Display3DShading, BOOL
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_LinkedCell, ptr BSTR
  COM_MTD_STD  put_LinkedCell, BSTR
  COM_MTD_STD  get_PhoneticAccelerator, ptr VARIANT
  COM_MTD_STD  put_PhoneticAccelerator, VARIANT
  COM_MTD_STD  get_Value, ptr VARIANT
  COM_MTD_STD  put_Value, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG ICheckBoxes, IDispatch, <00020880-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  _Dummy3
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  _Dummy12
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  _Dummy15
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  _Dummy22
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_STD  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_LockedText, ptr BOOL
  COM_MTD_STD  put_LockedText, BOOL
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
  COM_MTD_STD  get_Accelerator, ptr VARIANT
  COM_MTD_STD  put_Accelerator, VARIANT
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  get__Default, ptr SDWORD
  COM_MTD_STD  put__Default, SDWORD
  COM_MTD_STD  get_Display3DShading, ptr BOOL
  COM_MTD_STD  put_Display3DShading, BOOL
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_LinkedCell, ptr BSTR
  COM_MTD_STD  put_LinkedCell, BSTR
  COM_MTD_STD  get_PhoneticAccelerator, ptr VARIANT
  COM_MTD_STD  put_PhoneticAccelerator, VARIANT
  COM_MTD_STD  get_Value, ptr VARIANT
  COM_MTD_STD  put_Value, VARIANT
  COM_MTD_STD  Add_, REAL8, REAL8, REAL8, REAL8, ptr ptr CheckBox
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Group_, ptr ptr GroupObject
  COM_MTD_STD  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IOptionButton, IDispatch, <00020881-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_BottomRightCell, ptr ptr Range
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  get_Index, ptr SDWORD
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  get_TopLeftCell, ptr ptr Range
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_STD  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_LockedText, ptr BOOL
  COM_MTD_STD  put_LockedText, BOOL
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
  COM_MTD_STD  get_Accelerator, ptr VARIANT
  COM_MTD_STD  put_Accelerator, VARIANT
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  get__Default, ptr SDWORD
  COM_MTD_STD  put__Default, SDWORD
  COM_MTD_STD  get_Display3DShading, ptr BOOL
  COM_MTD_STD  put_Display3DShading, BOOL
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_LinkedCell, ptr BSTR
  COM_MTD_STD  put_LinkedCell, BSTR
  COM_MTD_STD  get_PhoneticAccelerator, ptr VARIANT
  COM_MTD_STD  put_PhoneticAccelerator, VARIANT
  COM_MTD_STD  get_Value, ptr VARIANT
  COM_MTD_STD  put_Value, VARIANT
  COM_MTD_STD  get_GroupBox, ptr ptr GroupBox
COM_INTERFACE_END

COM_INTERFACE_BEG IOptionButtons, IDispatch, <00020882-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  _Dummy3
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  _Dummy12
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  _Dummy15
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  _Dummy22
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_STD  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_LockedText, ptr BOOL
  COM_MTD_STD  put_LockedText, BOOL
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
  COM_MTD_STD  get_Accelerator, ptr VARIANT
  COM_MTD_STD  put_Accelerator, VARIANT
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  get__Default, ptr SDWORD
  COM_MTD_STD  put__Default, SDWORD
  COM_MTD_STD  get_Display3DShading, ptr BOOL
  COM_MTD_STD  put_Display3DShading, BOOL
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_LinkedCell, ptr BSTR
  COM_MTD_STD  put_LinkedCell, BSTR
  COM_MTD_STD  get_PhoneticAccelerator, ptr VARIANT
  COM_MTD_STD  put_PhoneticAccelerator, VARIANT
  COM_MTD_STD  get_Value, ptr VARIANT
  COM_MTD_STD  put_Value, VARIANT
  COM_MTD_STD  get_GroupBox, ptr ptr GroupBox
  COM_MTD_STD  Add_, REAL8, REAL8, REAL8, REAL8, ptr ptr OptionButton
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Group_, ptr ptr GroupObject
  COM_MTD_STD  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IEditBox, IDispatch, <00020883-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_BottomRightCell, ptr ptr Range
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  get_Index, ptr SDWORD
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  get_TopLeftCell, ptr ptr Range
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_STD  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_LockedText, ptr BOOL
  COM_MTD_STD  put_LockedText, BOOL
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
  COM_MTD_STD  get_DisplayVerticalScrollBar, ptr BOOL
  COM_MTD_STD  put_DisplayVerticalScrollBar, BOOL
  COM_MTD_STD  get_InputType, ptr SDWORD
  COM_MTD_STD  put_InputType, SDWORD
  COM_MTD_STD  get_LinkedObject, ptr BSTR
  COM_MTD_STD  get_MultiLine, ptr BOOL
  COM_MTD_STD  put_MultiLine, BOOL
  COM_MTD_STD  get_PasswordEdit, ptr BOOL
  COM_MTD_STD  put_PasswordEdit, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG IEditBoxes, IDispatch, <00020884-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  _Dummy3
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  _Dummy12
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  _Dummy15
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  _Dummy22
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_STD  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_LockedText, ptr BOOL
  COM_MTD_STD  put_LockedText, BOOL
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
  COM_MTD_STD  get_DisplayVerticalScrollBar, ptr BOOL
  COM_MTD_STD  put_DisplayVerticalScrollBar, BOOL
  COM_MTD_STD  get_InputType, ptr SDWORD
  COM_MTD_STD  put_InputType, SDWORD
  COM_MTD_STD  _Dummy34
  COM_MTD_STD  get_MultiLine, ptr BOOL
  COM_MTD_STD  put_MultiLine, BOOL
  COM_MTD_STD  get_PasswordEdit, ptr BOOL
  COM_MTD_STD  put_PasswordEdit, BOOL
  COM_MTD_STD  Add_, REAL8, REAL8, REAL8, REAL8, ptr ptr EditBox
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Group_, ptr ptr GroupObject
  COM_MTD_STD  Item, VARIANT, ptr VARIANT
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IScrollBar, IDispatch, <00020885-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_BottomRightCell, ptr ptr Range
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  get_Index, ptr SDWORD
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  get_TopLeftCell, ptr ptr Range
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get__Default, ptr SDWORD
  COM_MTD_STD  put__Default, SDWORD
  COM_MTD_STD  get_Display3DShading, ptr BOOL
  COM_MTD_STD  put_Display3DShading, BOOL
  COM_MTD_STD  get_LinkedCell, ptr BSTR
  COM_MTD_STD  put_LinkedCell, BSTR
  COM_MTD_STD  get_Max, ptr SDWORD
  COM_MTD_STD  put_Max, SDWORD
  COM_MTD_STD  get_Min, ptr SDWORD
  COM_MTD_STD  put_Min, SDWORD
  COM_MTD_STD  get_SmallChange, ptr SDWORD
  COM_MTD_STD  put_SmallChange, SDWORD
  COM_MTD_STD  get_Value, ptr SDWORD
  COM_MTD_STD  put_Value, SDWORD
  COM_MTD_STD  get_LargeChange, ptr SDWORD
  COM_MTD_STD  put_LargeChange, SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG IScrollBars, IDispatch, <00020886-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  _Dummy3
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  _Dummy12
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  _Dummy15
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  _Dummy22
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get__Default, ptr SDWORD
  COM_MTD_STD  put__Default, SDWORD
  COM_MTD_STD  get_Display3DShading, ptr BOOL
  COM_MTD_STD  put_Display3DShading, BOOL
  COM_MTD_STD  get_LinkedCell, ptr BSTR
  COM_MTD_STD  put_LinkedCell, BSTR
  COM_MTD_STD  get_Max, ptr SDWORD
  COM_MTD_STD  put_Max, SDWORD
  COM_MTD_STD  get_Min, ptr SDWORD
  COM_MTD_STD  put_Min, SDWORD
  COM_MTD_STD  get_SmallChange, ptr SDWORD
  COM_MTD_STD  put_SmallChange, SDWORD
  COM_MTD_STD  get_Value, ptr SDWORD
  COM_MTD_STD  put_Value, SDWORD
  COM_MTD_STD  get_LargeChange, ptr SDWORD
  COM_MTD_STD  put_LargeChange, SDWORD
  COM_MTD_STD  Add_, REAL8, REAL8, REAL8, REAL8, ptr ptr ScrollBar
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Group_, ptr ptr GroupObject
  COM_MTD_STD  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IListBox, IDispatch, <00020887-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_BottomRightCell, ptr ptr Range
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  get_Index, ptr SDWORD
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  get_TopLeftCell, ptr ptr Range
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  AddItem, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_Display3DShading, ptr BOOL
  COM_MTD_STD  put_Display3DShading, BOOL
  COM_MTD_STD  get__Default, ptr SDWORD
  COM_MTD_STD  put__Default, SDWORD
  COM_MTD_STD  get_LinkedCell, ptr BSTR
  COM_MTD_STD  put_LinkedCell, BSTR
  COM_MTD_STD  get_LinkedObject, ptr VARIANT
  COM_MTD_STD  get_List, VARIANT, ptr VARIANT
  COM_MTD_STD  put_List, VARIANT, VARIANT
  COM_MTD_STD  get_ListCount, ptr SDWORD
  COM_MTD_STD  get_ListFillRange, ptr BSTR
  COM_MTD_STD  put_ListFillRange, BSTR
  COM_MTD_STD  get_ListIndex, ptr SDWORD
  COM_MTD_STD  put_ListIndex, SDWORD
  COM_MTD_STD  get_MultiSelect, ptr SDWORD
  COM_MTD_STD  put_MultiSelect, SDWORD
  COM_MTD_STD  RemoveAllItems, ptr VARIANT
  COM_MTD_STD  RemoveItem, SDWORD, VARIANT, ptr VARIANT
  COM_MTD_STD  get_Selected, VARIANT, ptr VARIANT
  COM_MTD_STD  put_Selected, VARIANT, VARIANT
  COM_MTD_STD  get_Value, ptr SDWORD
  COM_MTD_STD  put_Value, SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG IListBoxes, IDispatch, <00020888-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  _Dummy3
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  _Dummy12
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  _Dummy15
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  _Dummy22
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  AddItem, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_Display3DShading, ptr BOOL
  COM_MTD_STD  put_Display3DShading, BOOL
  COM_MTD_STD  get__Default, ptr SDWORD
  COM_MTD_STD  put__Default, SDWORD
  COM_MTD_STD  get_LinkedCell, ptr BSTR
  COM_MTD_STD  put_LinkedCell, BSTR
  COM_MTD_STD  _Dummy31
  COM_MTD_STD  get_List, VARIANT, ptr VARIANT
  COM_MTD_STD  put_List, VARIANT, VARIANT
  COM_MTD_STD  _Dummy33
  COM_MTD_STD  get_ListFillRange, ptr BSTR
  COM_MTD_STD  put_ListFillRange, BSTR
  COM_MTD_STD  get_ListIndex, ptr SDWORD
  COM_MTD_STD  put_ListIndex, SDWORD
  COM_MTD_STD  get_MultiSelect, ptr SDWORD
  COM_MTD_STD  put_MultiSelect, SDWORD
  COM_MTD_STD  RemoveAllItems, ptr VARIANT
  COM_MTD_STD  RemoveItem, SDWORD, VARIANT, ptr VARIANT
  COM_MTD_STD  get_Selected, VARIANT, ptr VARIANT
  COM_MTD_STD  put_Selected, VARIANT, VARIANT
  COM_MTD_STD  get_Value, ptr SDWORD
  COM_MTD_STD  put_Value, SDWORD
  COM_MTD_STD  Add_, REAL8, REAL8, REAL8, REAL8, ptr ptr ListBox
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Group_, ptr ptr GroupObject
  COM_MTD_STD  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IGroupBox, IDispatch, <00020889-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_BottomRightCell, ptr ptr Range
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  get_Index, ptr SDWORD
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  get_TopLeftCell, ptr ptr Range
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_STD  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_LockedText, ptr BOOL
  COM_MTD_STD  put_LockedText, BOOL
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
  COM_MTD_STD  get_Accelerator, ptr VARIANT
  COM_MTD_STD  put_Accelerator, VARIANT
  COM_MTD_STD  get_Display3DShading, ptr BOOL
  COM_MTD_STD  put_Display3DShading, BOOL
  COM_MTD_STD  get_PhoneticAccelerator, ptr VARIANT
  COM_MTD_STD  put_PhoneticAccelerator, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG IGroupBoxes, IDispatch, <0002088A-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  _Dummy3
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  _Dummy12
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  _Dummy15
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  _Dummy22
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_STD  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_LockedText, ptr BOOL
  COM_MTD_STD  put_LockedText, BOOL
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
  COM_MTD_STD  get_Accelerator, ptr VARIANT
  COM_MTD_STD  put_Accelerator, VARIANT
  COM_MTD_STD  get_Display3DShading, ptr BOOL
  COM_MTD_STD  put_Display3DShading, BOOL
  COM_MTD_STD  get_PhoneticAccelerator, ptr VARIANT
  COM_MTD_STD  put_PhoneticAccelerator, VARIANT
  COM_MTD_STD  Add_, REAL8, REAL8, REAL8, REAL8, ptr ptr GroupBox
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Group_, ptr ptr GroupObject
  COM_MTD_STD  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IDropDown, IDispatch, <0002088B-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_BottomRightCell, ptr ptr Range
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  get_Index, ptr SDWORD
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  get_TopLeftCell, ptr ptr Range
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  AddItem, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_Display3DShading, ptr BOOL
  COM_MTD_STD  put_Display3DShading, BOOL
  COM_MTD_STD  get__Default, ptr SDWORD
  COM_MTD_STD  put__Default, SDWORD
  COM_MTD_STD  get_LinkedCell, ptr BSTR
  COM_MTD_STD  put_LinkedCell, BSTR
  COM_MTD_STD  get_LinkedObject, ptr VARIANT
  COM_MTD_STD  get_List, VARIANT, ptr VARIANT
  COM_MTD_STD  put_List, VARIANT, VARIANT
  COM_MTD_STD  get_ListCount, ptr SDWORD
  COM_MTD_STD  get_ListFillRange, ptr BSTR
  COM_MTD_STD  put_ListFillRange, BSTR
  COM_MTD_STD  get_ListIndex, ptr SDWORD
  COM_MTD_STD  put_ListIndex, SDWORD
  COM_MTD_STD  _Dummy36
  COM_MTD_STD  RemoveAllItems, ptr VARIANT
  COM_MTD_STD  RemoveItem, SDWORD, VARIANT, ptr VARIANT
  COM_MTD_STD  get_Selected, VARIANT, ptr VARIANT
  COM_MTD_STD  put_Selected, VARIANT, VARIANT
  COM_MTD_STD  get_Value, ptr SDWORD
  COM_MTD_STD  put_Value, SDWORD
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_STD  get_DropDownLines, ptr SDWORD
  COM_MTD_STD  put_DropDownLines, SDWORD
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG IDropDowns, IDispatch, <0002088C-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  _Dummy3
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  _Dummy12
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  _Dummy15
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  _Dummy22
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  AddItem, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_Display3DShading, ptr BOOL
  COM_MTD_STD  put_Display3DShading, BOOL
  COM_MTD_STD  get__Default, ptr SDWORD
  COM_MTD_STD  put__Default, SDWORD
  COM_MTD_STD  get_LinkedCell, ptr BSTR
  COM_MTD_STD  put_LinkedCell, BSTR
  COM_MTD_STD  _Dummy31
  COM_MTD_STD  get_List, VARIANT, ptr VARIANT
  COM_MTD_STD  put_List, VARIANT, VARIANT
  COM_MTD_STD  _Dummy33
  COM_MTD_STD  get_ListFillRange, ptr BSTR
  COM_MTD_STD  put_ListFillRange, BSTR
  COM_MTD_STD  get_ListIndex, ptr SDWORD
  COM_MTD_STD  put_ListIndex, SDWORD
  COM_MTD_STD  _Dummy36
  COM_MTD_STD  RemoveAllItems, ptr VARIANT
  COM_MTD_STD  RemoveItem, SDWORD, VARIANT, ptr VARIANT
  COM_MTD_STD  get_Selected, VARIANT, ptr VARIANT
  COM_MTD_STD  put_Selected, VARIANT, VARIANT
  COM_MTD_STD  get_Value, ptr SDWORD
  COM_MTD_STD  put_Value, SDWORD
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_STD  get_DropDownLines, ptr SDWORD
  COM_MTD_STD  put_DropDownLines, SDWORD
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
  COM_MTD_STD  Add_, REAL8, REAL8, REAL8, REAL8, VARIANT, ptr ptr DropDown
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Group_, ptr ptr GroupObject
  COM_MTD_STD  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG ISpinner, IDispatch, <0002088D-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_BottomRightCell, ptr ptr Range
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  get_Index, ptr SDWORD
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  get_TopLeftCell, ptr ptr Range
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get__Default, ptr SDWORD
  COM_MTD_STD  put__Default, SDWORD
  COM_MTD_STD  get_Display3DShading, ptr BOOL
  COM_MTD_STD  put_Display3DShading, BOOL
  COM_MTD_STD  get_LinkedCell, ptr BSTR
  COM_MTD_STD  put_LinkedCell, BSTR
  COM_MTD_STD  get_Max, ptr SDWORD
  COM_MTD_STD  put_Max, SDWORD
  COM_MTD_STD  get_Min, ptr SDWORD
  COM_MTD_STD  put_Min, SDWORD
  COM_MTD_STD  get_SmallChange, ptr SDWORD
  COM_MTD_STD  put_SmallChange, SDWORD
  COM_MTD_STD  get_Value, ptr SDWORD
  COM_MTD_STD  put_Value, SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG ISpinners, IDispatch, <0002088E-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  _Dummy3
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  _Dummy12
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  _Dummy15
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  _Dummy22
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get__Default, ptr SDWORD
  COM_MTD_STD  put__Default, SDWORD
  COM_MTD_STD  get_Display3DShading, ptr BOOL
  COM_MTD_STD  put_Display3DShading, BOOL
  COM_MTD_STD  get_LinkedCell, ptr BSTR
  COM_MTD_STD  put_LinkedCell, BSTR
  COM_MTD_STD  get_Max, ptr SDWORD
  COM_MTD_STD  put_Max, SDWORD
  COM_MTD_STD  get_Min, ptr SDWORD
  COM_MTD_STD  put_Min, SDWORD
  COM_MTD_STD  get_SmallChange, ptr SDWORD
  COM_MTD_STD  put_SmallChange, SDWORD
  COM_MTD_STD  get_Value, ptr SDWORD
  COM_MTD_STD  put_Value, SDWORD
  COM_MTD_STD  Add_, REAL8, REAL8, REAL8, REAL8, ptr ptr Spinner
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Group_, ptr ptr GroupObject
  COM_MTD_STD  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IDialogFrame, IDispatch, <0002088F-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  _Dummy3
  COM_MTD_STD  _Dummy4
  COM_MTD_STD  _Dummy5
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  _Dummy7
  COM_MTD_STD  _Dummy8
  COM_MTD_STD  _Dummy9
  COM_MTD_STD  _Dummy10
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  _Dummy12
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  _Dummy17
  COM_MTD_STD  _Dummy18
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  _Dummy20
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  _Dummy22
  COM_MTD_STD  _Dummy23
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  _Dummy25
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_STD  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_LockedText, ptr BOOL
  COM_MTD_STD  put_LockedText, BOOL
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG ILabel, IDispatch, <00020890-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_BottomRightCell, ptr ptr Range
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  get_Index, ptr SDWORD
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  get_TopLeftCell, ptr ptr Range
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_STD  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_LockedText, ptr BOOL
  COM_MTD_STD  put_LockedText, BOOL
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
  COM_MTD_STD  get_Accelerator, ptr VARIANT
  COM_MTD_STD  put_Accelerator, VARIANT
  COM_MTD_STD  _Dummy33
  COM_MTD_STD  get_PhoneticAccelerator, ptr VARIANT
  COM_MTD_STD  put_PhoneticAccelerator, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG ILabels, IDispatch, <00020891-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  _Dummy3
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  _Dummy12
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  _Dummy15
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  _Dummy22
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_STD  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_LockedText, ptr BOOL
  COM_MTD_STD  put_LockedText, BOOL
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
  COM_MTD_STD  get_Accelerator, ptr VARIANT
  COM_MTD_STD  put_Accelerator, VARIANT
  COM_MTD_STD  _Dummy33
  COM_MTD_STD  get_PhoneticAccelerator, ptr VARIANT
  COM_MTD_STD  put_PhoneticAccelerator, VARIANT
  COM_MTD_STD  Add_, REAL8, REAL8, REAL8, REAL8, ptr ptr Label_
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Group_, ptr ptr GroupObject
  COM_MTD_STD  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IPanes, IDispatch, <00020894-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  get_Item, SDWORD, ptr ptr Pane
  COM_MTD_STD  get__Default, SDWORD, ptr ptr Pane
COM_INTERFACE_END

COM_INTERFACE_BEG IPane, IDispatch, <00020895-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Activate, ptr BOOL
  COM_MTD_STD  get_Index, ptr SDWORD
  COM_MTD_STD  LargeScroll, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_ScrollColumn, ptr SDWORD
  COM_MTD_STD  put_ScrollColumn, SDWORD
  COM_MTD_STD  get_ScrollRow, ptr SDWORD
  COM_MTD_STD  put_ScrollRow, SDWORD
  COM_MTD_STD  SmallScroll, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_VisibleRange, ptr ptr Range
  COM_MTD_STD  ScrollIntoView, SDWORD, SDWORD, SDWORD, SDWORD, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG IScenarios, IDispatch, <00020896-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Add_, BSTR, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr ptr Scenario
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  CreateSummary, XlSummaryReportType, VARIANT, ptr VARIANT
  COM_MTD_STD  Item, VARIANT, ptr ptr Scenario
  COM_MTD_STD  Merge, VARIANT, ptr VARIANT
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IScenario, IDispatch, <00020897-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  ChangeScenario, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_ChangingCells, ptr ptr Range
  COM_MTD_STD  get_Comment, ptr BSTR
  COM_MTD_STD  put_Comment, BSTR
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  get_Hidden, ptr BOOL
  COM_MTD_STD  put_Hidden, BOOL
  COM_MTD_STD  get_Index, ptr SDWORD
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  Show, ptr VARIANT
  COM_MTD_STD  get_Values, VARIANT, ptr VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG IGroupObject, IDispatch, <00020898-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_BottomRightCell, ptr ptr Range
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  get_Index, ptr SDWORD
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  get_TopLeftCell, ptr ptr Range
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  _Dummy27
  COM_MTD_STD  _Dummy28
  COM_MTD_STD  get_AddIndent, ptr BOOL
  COM_MTD_STD  put_AddIndent, BOOL
  COM_MTD_STD  _Dummy30
  COM_MTD_STD  get_ArrowHeadLength, ptr VARIANT
  COM_MTD_STD  put_ArrowHeadLength, VARIANT
  COM_MTD_STD  get_ArrowHeadStyle, ptr VARIANT
  COM_MTD_STD  put_ArrowHeadStyle, VARIANT
  COM_MTD_STD  get_ArrowHeadWidth, ptr VARIANT
  COM_MTD_STD  put_ArrowHeadWidth, VARIANT
  COM_MTD_STD  get_AutoSize, ptr BOOL
  COM_MTD_STD  put_AutoSize, BOOL
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  _Dummy36
  COM_MTD_STD  _Dummy37
  COM_MTD_STD  _Dummy38
  COM_MTD_STD  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get__Default, ptr SDWORD
  COM_MTD_STD  put__Default, SDWORD
  COM_MTD_STD  _Dummy41
  COM_MTD_STD  _Dummy42
  COM_MTD_STD  _Dummy43
  COM_MTD_STD  _Dummy44
  COM_MTD_STD  _Dummy45
  COM_MTD_STD  get_Font, ptr ptr Font
  COM_MTD_STD  _Dummy47
  COM_MTD_STD  _Dummy48
  COM_MTD_STD  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_STD  put_HorizontalAlignment, VARIANT
  COM_MTD_STD  _Dummy50
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  _Dummy52
  COM_MTD_STD  _Dummy53
  COM_MTD_STD  _Dummy54
  COM_MTD_STD  _Dummy55
  COM_MTD_STD  _Dummy56
  COM_MTD_STD  _Dummy57
  COM_MTD_STD  _Dummy58
  COM_MTD_STD  _Dummy59
  COM_MTD_STD  _Dummy60
  COM_MTD_STD  _Dummy61
  COM_MTD_STD  _Dummy62
  COM_MTD_STD  _Dummy63
  COM_MTD_STD  get_Orientation, ptr VARIANT
  COM_MTD_STD  put_Orientation, VARIANT
  COM_MTD_STD  _Dummy65
  COM_MTD_STD  _Dummy66
  COM_MTD_STD  _Dummy67
  COM_MTD_STD  _Dummy68
  COM_MTD_STD  get_RoundedCorners, ptr BOOL
  COM_MTD_STD  put_RoundedCorners, BOOL
  COM_MTD_STD  _Dummy70
  COM_MTD_STD  get_Shadow, ptr BOOL
  COM_MTD_STD  put_Shadow, BOOL
  COM_MTD_STD  _Dummy72
  COM_MTD_STD  _Dummy73
  COM_MTD_STD  Ungroup, ptr LPDISPATCH
  COM_MTD_STD  _Dummy75
  COM_MTD_STD  get_VerticalAlignment, ptr VARIANT
  COM_MTD_STD  put_VerticalAlignment, VARIANT
  COM_MTD_STD  _Dummy77
  COM_MTD_STD  get_ReadingOrder, ptr SDWORD
  COM_MTD_STD  put_ReadingOrder, SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG IGroupObjects, IDispatch, <00020899-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  _Dummy3
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  _Dummy12
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  _Dummy15
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  _Dummy22
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  _Dummy27
  COM_MTD_STD  _Dummy28
  COM_MTD_STD  get_AddIndent, ptr BOOL
  COM_MTD_STD  put_AddIndent, BOOL
  COM_MTD_STD  _Dummy30
  COM_MTD_STD  get_ArrowHeadLength, ptr VARIANT
  COM_MTD_STD  put_ArrowHeadLength, VARIANT
  COM_MTD_STD  get_ArrowHeadStyle, ptr VARIANT
  COM_MTD_STD  put_ArrowHeadStyle, VARIANT
  COM_MTD_STD  get_ArrowHeadWidth, ptr VARIANT
  COM_MTD_STD  put_ArrowHeadWidth, VARIANT
  COM_MTD_STD  get_AutoSize, ptr BOOL
  COM_MTD_STD  put_AutoSize, BOOL
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  _Dummy36
  COM_MTD_STD  _Dummy37
  COM_MTD_STD  _Dummy38
  COM_MTD_STD  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get__Default, ptr SDWORD
  COM_MTD_STD  put__Default, SDWORD
  COM_MTD_STD  _Dummy41
  COM_MTD_STD  _Dummy42
  COM_MTD_STD  _Dummy43
  COM_MTD_STD  _Dummy44
  COM_MTD_STD  _Dummy45
  COM_MTD_STD  get_Font, ptr ptr Font
  COM_MTD_STD  _Dummy47
  COM_MTD_STD  _Dummy48
  COM_MTD_STD  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_STD  put_HorizontalAlignment, VARIANT
  COM_MTD_STD  _Dummy50
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  _Dummy52
  COM_MTD_STD  _Dummy53
  COM_MTD_STD  _Dummy54
  COM_MTD_STD  _Dummy55
  COM_MTD_STD  _Dummy56
  COM_MTD_STD  _Dummy57
  COM_MTD_STD  _Dummy58
  COM_MTD_STD  _Dummy59
  COM_MTD_STD  _Dummy60
  COM_MTD_STD  _Dummy61
  COM_MTD_STD  _Dummy62
  COM_MTD_STD  _Dummy63
  COM_MTD_STD  get_Orientation, ptr VARIANT
  COM_MTD_STD  put_Orientation, VARIANT
  COM_MTD_STD  _Dummy65
  COM_MTD_STD  _Dummy66
  COM_MTD_STD  _Dummy67
  COM_MTD_STD  _Dummy68
  COM_MTD_STD  get_RoundedCorners, ptr BOOL
  COM_MTD_STD  put_RoundedCorners, BOOL
  COM_MTD_STD  _Dummy70
  COM_MTD_STD  get_Shadow, ptr BOOL
  COM_MTD_STD  put_Shadow, BOOL
  COM_MTD_STD  _Dummy72
  COM_MTD_STD  _Dummy73
  COM_MTD_STD  Ungroup, ptr LPDISPATCH
  COM_MTD_STD  _Dummy75
  COM_MTD_STD  get_VerticalAlignment, ptr VARIANT
  COM_MTD_STD  put_VerticalAlignment, VARIANT
  COM_MTD_STD  _Dummy77
  COM_MTD_STD  get_ReadingOrder, ptr SDWORD
  COM_MTD_STD  put_ReadingOrder, SDWORD
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Group_, ptr ptr GroupObject
  COM_MTD_STD  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG ILine, IDispatch, <0002089A-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_BottomRightCell, ptr ptr Range
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  get_Index, ptr SDWORD
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  get_TopLeftCell, ptr ptr Range
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get_ArrowHeadLength, ptr VARIANT
  COM_MTD_STD  put_ArrowHeadLength, VARIANT
  COM_MTD_STD  get_ArrowHeadStyle, ptr VARIANT
  COM_MTD_STD  put_ArrowHeadStyle, VARIANT
  COM_MTD_STD  get_ArrowHeadWidth, ptr VARIANT
  COM_MTD_STD  put_ArrowHeadWidth, VARIANT
  COM_MTD_STD  get_Border, ptr ptr Border
COM_INTERFACE_END

COM_INTERFACE_BEG ILines, IDispatch, <0002089B-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  _Dummy3
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  _Dummy12
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  _Dummy15
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  _Dummy22
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get_ArrowHeadLength, ptr VARIANT
  COM_MTD_STD  put_ArrowHeadLength, VARIANT
  COM_MTD_STD  get_ArrowHeadStyle, ptr VARIANT
  COM_MTD_STD  put_ArrowHeadStyle, VARIANT
  COM_MTD_STD  get_ArrowHeadWidth, ptr VARIANT
  COM_MTD_STD  put_ArrowHeadWidth, VARIANT
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  Add_, REAL8, REAL8, REAL8, REAL8, ptr ptr Line
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Group_, ptr ptr GroupObject
  COM_MTD_STD  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IRectangle, IDispatch, <0002089C-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_BottomRightCell, ptr ptr Range
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  get_Index, ptr SDWORD
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  get_TopLeftCell, ptr ptr Range
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get_AddIndent, ptr BOOL
  COM_MTD_STD  put_AddIndent, BOOL
  COM_MTD_STD  get_AutoScaleFont, ptr VARIANT
  COM_MTD_STD  put_AutoScaleFont, VARIANT
  COM_MTD_STD  get_AutoSize, ptr BOOL
  COM_MTD_STD  put_AutoSize, BOOL
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_STD  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_Font, ptr ptr Font
  COM_MTD_STD  get_Formula, ptr BSTR
  COM_MTD_STD  put_Formula, BSTR
  COM_MTD_STD  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_STD  put_HorizontalAlignment, VARIANT
  COM_MTD_STD  get_LockedText, ptr BOOL
  COM_MTD_STD  put_LockedText, BOOL
  COM_MTD_STD  get_Orientation, ptr VARIANT
  COM_MTD_STD  put_Orientation, VARIANT
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
  COM_MTD_STD  get_VerticalAlignment, ptr VARIANT
  COM_MTD_STD  put_VerticalAlignment, VARIANT
  COM_MTD_STD  get_ReadingOrder, ptr SDWORD
  COM_MTD_STD  put_ReadingOrder, SDWORD
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_Shadow, ptr BOOL
  COM_MTD_STD  put_Shadow, BOOL
  COM_MTD_STD  get_RoundedCorners, ptr BOOL
  COM_MTD_STD  put_RoundedCorners, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG IRectangles, IDispatch, <0002089D-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  _Dummy3
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  _Dummy12
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  _Dummy15
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  _Dummy22
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get_AddIndent, ptr BOOL
  COM_MTD_STD  put_AddIndent, BOOL
  COM_MTD_STD  get_AutoScaleFont, ptr VARIANT
  COM_MTD_STD  put_AutoScaleFont, VARIANT
  COM_MTD_STD  get_AutoSize, ptr BOOL
  COM_MTD_STD  put_AutoSize, BOOL
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_STD  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_Font, ptr ptr Font
  COM_MTD_STD  get_Formula, ptr BSTR
  COM_MTD_STD  put_Formula, BSTR
  COM_MTD_STD  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_STD  put_HorizontalAlignment, VARIANT
  COM_MTD_STD  get_LockedText, ptr BOOL
  COM_MTD_STD  put_LockedText, BOOL
  COM_MTD_STD  get_Orientation, ptr VARIANT
  COM_MTD_STD  put_Orientation, VARIANT
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
  COM_MTD_STD  get_VerticalAlignment, ptr VARIANT
  COM_MTD_STD  put_VerticalAlignment, VARIANT
  COM_MTD_STD  get_ReadingOrder, ptr SDWORD
  COM_MTD_STD  put_ReadingOrder, SDWORD
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_Shadow, ptr BOOL
  COM_MTD_STD  put_Shadow, BOOL
  COM_MTD_STD  get_RoundedCorners, ptr BOOL
  COM_MTD_STD  put_RoundedCorners, BOOL
  COM_MTD_STD  Add_, REAL8, REAL8, REAL8, REAL8, POINTER;ptr ptr Rectangle
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Group_, ptr ptr GroupObject
  COM_MTD_STD  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IOval, IDispatch, <0002089E-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_BottomRightCell, ptr ptr Range
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  get_Index, ptr SDWORD
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  get_TopLeftCell, ptr ptr Range
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get_AddIndent, ptr BOOL
  COM_MTD_STD  put_AddIndent, BOOL
  COM_MTD_STD  get_AutoScaleFont, ptr VARIANT
  COM_MTD_STD  put_AutoScaleFont, VARIANT
  COM_MTD_STD  get_AutoSize, ptr BOOL
  COM_MTD_STD  put_AutoSize, BOOL
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_STD  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_Font, ptr ptr Font
  COM_MTD_STD  get_Formula, ptr BSTR
  COM_MTD_STD  put_Formula, BSTR
  COM_MTD_STD  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_STD  put_HorizontalAlignment, VARIANT
  COM_MTD_STD  get_LockedText, ptr BOOL
  COM_MTD_STD  put_LockedText, BOOL
  COM_MTD_STD  get_Orientation, ptr VARIANT
  COM_MTD_STD  put_Orientation, VARIANT
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
  COM_MTD_STD  get_VerticalAlignment, ptr VARIANT
  COM_MTD_STD  put_VerticalAlignment, VARIANT
  COM_MTD_STD  get_ReadingOrder, ptr SDWORD
  COM_MTD_STD  put_ReadingOrder, SDWORD
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_Shadow, ptr BOOL
  COM_MTD_STD  put_Shadow, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG IOvals, IDispatch, <0002089F-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  _Dummy3
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  _Dummy12
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  _Dummy15
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  _Dummy22
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get_AddIndent, ptr BOOL
  COM_MTD_STD  put_AddIndent, BOOL
  COM_MTD_STD  get_AutoScaleFont, ptr VARIANT
  COM_MTD_STD  put_AutoScaleFont, VARIANT
  COM_MTD_STD  get_AutoSize, ptr BOOL
  COM_MTD_STD  put_AutoSize, BOOL
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_STD  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_Font, ptr ptr Font
  COM_MTD_STD  get_Formula, ptr BSTR
  COM_MTD_STD  put_Formula, BSTR
  COM_MTD_STD  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_STD  put_HorizontalAlignment, VARIANT
  COM_MTD_STD  get_LockedText, ptr BOOL
  COM_MTD_STD  put_LockedText, BOOL
  COM_MTD_STD  get_Orientation, ptr VARIANT
  COM_MTD_STD  put_Orientation, VARIANT
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
  COM_MTD_STD  get_VerticalAlignment, ptr VARIANT
  COM_MTD_STD  put_VerticalAlignment, VARIANT
  COM_MTD_STD  get_ReadingOrder, ptr SDWORD
  COM_MTD_STD  put_ReadingOrder, SDWORD
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_Shadow, ptr BOOL
  COM_MTD_STD  put_Shadow, BOOL
  COM_MTD_STD  Add_, REAL8, REAL8, REAL8, REAL8, ptr ptr Oval
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Group_, ptr ptr GroupObject
  COM_MTD_STD  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IArc, IDispatch, <000208A0-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_BottomRightCell, ptr ptr Range
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  get_Index, ptr SDWORD
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  get_TopLeftCell, ptr ptr Range
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get_AddIndent, ptr BOOL
  COM_MTD_STD  put_AddIndent, BOOL
  COM_MTD_STD  get_AutoScaleFont, ptr VARIANT
  COM_MTD_STD  put_AutoScaleFont, VARIANT
  COM_MTD_STD  get_AutoSize, ptr BOOL
  COM_MTD_STD  put_AutoSize, BOOL
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_STD  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_Font, ptr ptr Font
  COM_MTD_STD  get_Formula, ptr BSTR
  COM_MTD_STD  put_Formula, BSTR
  COM_MTD_STD  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_STD  put_HorizontalAlignment, VARIANT
  COM_MTD_STD  get_LockedText, ptr BOOL
  COM_MTD_STD  put_LockedText, BOOL
  COM_MTD_STD  get_Orientation, ptr VARIANT
  COM_MTD_STD  put_Orientation, VARIANT
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
  COM_MTD_STD  get_VerticalAlignment, ptr VARIANT
  COM_MTD_STD  put_VerticalAlignment, VARIANT
  COM_MTD_STD  get_ReadingOrder, ptr SDWORD
  COM_MTD_STD  put_ReadingOrder, SDWORD
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  _Dummy43
COM_INTERFACE_END

COM_INTERFACE_BEG IArcs, IDispatch, <000208A1-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  _Dummy3
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  _Dummy12
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  _Dummy15
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  _Dummy22
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get_AddIndent, ptr BOOL
  COM_MTD_STD  put_AddIndent, BOOL
  COM_MTD_STD  get_AutoScaleFont, ptr VARIANT
  COM_MTD_STD  put_AutoScaleFont, VARIANT
  COM_MTD_STD  get_AutoSize, ptr BOOL
  COM_MTD_STD  put_AutoSize, BOOL
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_STD  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_Font, ptr ptr Font
  COM_MTD_STD  get_Formula, ptr BSTR
  COM_MTD_STD  put_Formula, BSTR
  COM_MTD_STD  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_STD  put_HorizontalAlignment, VARIANT
  COM_MTD_STD  get_LockedText, ptr BOOL
  COM_MTD_STD  put_LockedText, BOOL
  COM_MTD_STD  get_Orientation, ptr VARIANT
  COM_MTD_STD  put_Orientation, VARIANT
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
  COM_MTD_STD  get_VerticalAlignment, ptr VARIANT
  COM_MTD_STD  put_VerticalAlignment, VARIANT
  COM_MTD_STD  get_ReadingOrder, ptr SDWORD
  COM_MTD_STD  put_ReadingOrder, SDWORD
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  _Dummy43
  COM_MTD_STD  Add_, REAL8, REAL8, REAL8, REAL8, POINTER;ptr ptr Arc
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Group_, ptr ptr GroupObject
  COM_MTD_STD  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IOLEObjectEvents, IDispatch, <00024410-0001-0000-C000-000000000046>
  COM_MTD_STD  GotFocus
  COM_MTD_STD  LostFocus
COM_INTERFACE_END

COM_INTERFACE_BEG _IOLEObject, IDispatch, <000208A2-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_BottomRightCell, ptr ptr Range
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  get_Index, ptr SDWORD
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  get_TopLeftCell, ptr ptr Range
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_Shadow, ptr BOOL
  COM_MTD_STD  put_Shadow, BOOL
  COM_MTD_STD  Activate, ptr VARIANT
  COM_MTD_STD  get_AutoLoad, ptr BOOL
  COM_MTD_STD  put_AutoLoad, BOOL
  COM_MTD_STD  get_AutoUpdate, ptr BOOL
  COM_MTD_STD  put_AutoUpdate, BOOL
  COM_MTD_STD  get_Object, ptr LPDISPATCH
  COM_MTD_STD  get_OLEType, ptr VARIANT
  COM_MTD_STD  get_SourceName, ptr BSTR
  COM_MTD_STD  put_SourceName, BSTR
  COM_MTD_STD  Update, ptr VARIANT
  COM_MTD_STD  Verb, XlOLEVerb, ptr VARIANT
  COM_MTD_STD  get_LinkedCell, ptr BSTR
  COM_MTD_STD  put_LinkedCell, BSTR
  COM_MTD_STD  get_ListFillRange, ptr BSTR
  COM_MTD_STD  put_ListFillRange, BSTR
  COM_MTD_STD  get_progID, ptr BSTR
  COM_MTD_STD  get_AltHTML, ptr BSTR
  COM_MTD_STD  put_AltHTML, BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG IOLEObjects, IDispatch, <000208A3-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  _Dummy3
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  _Dummy12
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  _Dummy15
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  _Dummy22
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_Shadow, ptr BOOL
  COM_MTD_STD  put_Shadow, BOOL
  COM_MTD_STD  _Dummy30
  COM_MTD_STD  get_AutoLoad, ptr BOOL
  COM_MTD_STD  put_AutoLoad, BOOL
  COM_MTD_STD  _Dummy32
  COM_MTD_STD  _Dummy33
  COM_MTD_STD  _Dummy34
  COM_MTD_STD  get_SourceName, ptr BSTR
  COM_MTD_STD  put_SourceName, BSTR
  COM_MTD_STD  _Dummy36
  COM_MTD_STD  _Dummy37
  COM_MTD_STD  _Dummy38
  COM_MTD_STD  _Dummy39
  COM_MTD_STD  _Dummy40
  COM_MTD_STD  _Dummy41
  COM_MTD_STD  Add_, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr ptr OLEObject
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Group_, ptr ptr GroupObject
  COM_MTD_STD  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG ITextBox, IDispatch, <000208A4-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_BottomRightCell, ptr ptr Range
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  get_Index, ptr SDWORD
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  get_TopLeftCell, ptr ptr Range
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get_AddIndent, ptr BOOL
  COM_MTD_STD  put_AddIndent, BOOL
  COM_MTD_STD  get_AutoScaleFont, ptr VARIANT
  COM_MTD_STD  put_AutoScaleFont, VARIANT
  COM_MTD_STD  get_AutoSize, ptr BOOL
  COM_MTD_STD  put_AutoSize, BOOL
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_STD  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_Font, ptr ptr Font
  COM_MTD_STD  get_Formula, ptr BSTR
  COM_MTD_STD  put_Formula, BSTR
  COM_MTD_STD  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_STD  put_HorizontalAlignment, VARIANT
  COM_MTD_STD  get_LockedText, ptr BOOL
  COM_MTD_STD  put_LockedText, BOOL
  COM_MTD_STD  get_Orientation, ptr VARIANT
  COM_MTD_STD  put_Orientation, VARIANT
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
  COM_MTD_STD  get_VerticalAlignment, ptr VARIANT
  COM_MTD_STD  put_VerticalAlignment, VARIANT
  COM_MTD_STD  get_ReadingOrder, ptr SDWORD
  COM_MTD_STD  put_ReadingOrder, SDWORD
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_RoundedCorners, ptr BOOL
  COM_MTD_STD  put_RoundedCorners, BOOL
  COM_MTD_STD  get_Shadow, ptr BOOL
  COM_MTD_STD  put_Shadow, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG ITextBoxes, IDispatch, <000208A5-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  _Dummy3
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  _Dummy12
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  _Dummy15
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  _Dummy22
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get_AddIndent, ptr BOOL
  COM_MTD_STD  put_AddIndent, BOOL
  COM_MTD_STD  get_AutoScaleFont, ptr VARIANT
  COM_MTD_STD  put_AutoScaleFont, VARIANT
  COM_MTD_STD  get_AutoSize, ptr BOOL
  COM_MTD_STD  put_AutoSize, BOOL
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_STD  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_Font, ptr ptr Font
  COM_MTD_STD  get_Formula, ptr BSTR
  COM_MTD_STD  put_Formula, BSTR
  COM_MTD_STD  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_STD  put_HorizontalAlignment, VARIANT
  COM_MTD_STD  get_LockedText, ptr BOOL
  COM_MTD_STD  put_LockedText, BOOL
  COM_MTD_STD  get_Orientation, ptr VARIANT
  COM_MTD_STD  put_Orientation, VARIANT
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
  COM_MTD_STD  get_VerticalAlignment, ptr VARIANT
  COM_MTD_STD  put_VerticalAlignment, VARIANT
  COM_MTD_STD  get_ReadingOrder, ptr SDWORD
  COM_MTD_STD  put_ReadingOrder, SDWORD
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_RoundedCorners, ptr BOOL
  COM_MTD_STD  put_RoundedCorners, BOOL
  COM_MTD_STD  get_Shadow, ptr BOOL
  COM_MTD_STD  put_Shadow, BOOL
  COM_MTD_STD  Add_, REAL8, REAL8, REAL8, REAL8, ptr ptr TextBox
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Group_, ptr ptr GroupObject
  COM_MTD_STD  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

;Renamed from IPicture to IExcelPicture
COM_INTERFACE_BEG IExcelPicture, IDispatch, <000208A6-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_BottomRightCell, ptr ptr Range
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  get_Index, ptr SDWORD
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  get_TopLeftCell, ptr ptr Range
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_Shadow, ptr BOOL
  COM_MTD_STD  put_Shadow, BOOL
  COM_MTD_STD  get_Formula, ptr BSTR
  COM_MTD_STD  put_Formula, BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG IPictures, IDispatch, <000208A7-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  _Dummy3
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  _Dummy12
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  _Dummy15
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  _Dummy22
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_Shadow, ptr BOOL
  COM_MTD_STD  put_Shadow, BOOL
  COM_MTD_STD  get_Formula, ptr BSTR
  COM_MTD_STD  put_Formula, BSTR
  COM_MTD_STD  Add_, REAL8, REAL8, REAL8, REAL8, ptr ptr Picture
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Group_, ptr ptr GroupObject
  COM_MTD_STD  Insert, BSTR, VARIANT, ptr ptr Picture
  COM_MTD_STD  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  Paste, VARIANT, ptr ptr Picture
COM_INTERFACE_END

COM_INTERFACE_BEG IDrawing, IDispatch, <000208A8-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_BottomRightCell, ptr ptr Range
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  get_Index, ptr SDWORD
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  get_TopLeftCell, ptr ptr Range
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get_AddIndent, ptr BOOL
  COM_MTD_STD  put_AddIndent, BOOL
  COM_MTD_STD  get_AutoScaleFont, ptr VARIANT
  COM_MTD_STD  put_AutoScaleFont, VARIANT
  COM_MTD_STD  get_AutoSize, ptr BOOL
  COM_MTD_STD  put_AutoSize, BOOL
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_STD  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_Font, ptr ptr Font
  COM_MTD_STD  get_Formula, ptr BSTR
  COM_MTD_STD  put_Formula, BSTR
  COM_MTD_STD  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_STD  put_HorizontalAlignment, VARIANT
  COM_MTD_STD  get_LockedText, ptr BOOL
  COM_MTD_STD  put_LockedText, BOOL
  COM_MTD_STD  get_Orientation, ptr VARIANT
  COM_MTD_STD  put_Orientation, VARIANT
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
  COM_MTD_STD  get_VerticalAlignment, ptr VARIANT
  COM_MTD_STD  put_VerticalAlignment, VARIANT
  COM_MTD_STD  get_ReadingOrder, ptr SDWORD
  COM_MTD_STD  put_ReadingOrder, SDWORD
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_Shadow, ptr BOOL
  COM_MTD_STD  put_Shadow, BOOL
  COM_MTD_STD  AddVertex, REAL8, REAL8, ptr VARIANT
  COM_MTD_STD  Reshape, SDWORD, BOOL, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_Vertices, VARIANT, VARIANT, ptr VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG IDrawings, IDispatch, <000208A9-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  _Dummy3
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  _Dummy12
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  _Dummy15
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  _Dummy22
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  get_AddIndent, ptr BOOL
  COM_MTD_STD  put_AddIndent, BOOL
  COM_MTD_STD  get_AutoScaleFont, ptr VARIANT
  COM_MTD_STD  put_AutoScaleFont, VARIANT
  COM_MTD_STD  get_AutoSize, ptr BOOL
  COM_MTD_STD  put_AutoSize, BOOL
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_STD  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_Font, ptr ptr Font
  COM_MTD_STD  get_Formula, ptr BSTR
  COM_MTD_STD  put_Formula, BSTR
  COM_MTD_STD  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_STD  put_HorizontalAlignment, VARIANT
  COM_MTD_STD  get_LockedText, ptr BOOL
  COM_MTD_STD  put_LockedText, BOOL
  COM_MTD_STD  get_Orientation, ptr VARIANT
  COM_MTD_STD  put_Orientation, VARIANT
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
  COM_MTD_STD  get_VerticalAlignment, ptr VARIANT
  COM_MTD_STD  put_VerticalAlignment, VARIANT
  COM_MTD_STD  get_ReadingOrder, ptr SDWORD
  COM_MTD_STD  put_ReadingOrder, SDWORD
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_Shadow, ptr BOOL
  COM_MTD_STD  put_Shadow, BOOL
  COM_MTD_STD  _Dummy44
  COM_MTD_STD  Reshape, SDWORD, BOOL, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  _Dummy46
  COM_MTD_STD  Add_, REAL8, REAL8, REAL8, REAL8, BOOL, ptr ptr Drawing
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Group_, ptr ptr GroupObject
  COM_MTD_STD  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IRoutingSlip, IDispatch, <000208AA-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Delivery, ptr XlRoutingSlipDelivery
  COM_MTD_STD  put_Delivery, XlRoutingSlipDelivery
  COM_MTD_STD  get_Message, ptr VARIANT
  COM_MTD_STD  put_Message, VARIANT
  COM_MTD_STD  get_Recipients, VARIANT, ptr VARIANT
  COM_MTD_STD  put_Recipients, VARIANT, VARIANT
  COM_MTD_STD  Reset, ptr VARIANT
  COM_MTD_STD  get_ReturnWhenDone, ptr BOOL
  COM_MTD_STD  put_ReturnWhenDone, BOOL
  COM_MTD_STD  get_Status, ptr XlRoutingSlipStatus
  COM_MTD_STD  get_Subject, ptr VARIANT
  COM_MTD_STD  put_Subject, VARIANT
  COM_MTD_STD  get_TrackStatus, ptr BOOL
  COM_MTD_STD  put_TrackStatus, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG IOutline, IDispatch, <000208AB-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_AutomaticStyles, ptr BOOL
  COM_MTD_STD  put_AutomaticStyles, BOOL
  COM_MTD_STD  ShowLevels, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_SummaryColumn, ptr XlSummaryColumn
  COM_MTD_STD  put_SummaryColumn, XlSummaryColumn
  COM_MTD_STD  get_SummaryRow, ptr XlSummaryRow
  COM_MTD_STD  put_SummaryRow, XlSummaryRow
COM_INTERFACE_END

COM_INTERFACE_BEG IModule, IDispatch, <000208AD-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Activate, SDWORD
  COM_MTD_STD  Copy, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  Delete, SDWORD
  COM_MTD_STD  get_CodeName, ptr BSTR
  COM_MTD_STD  get__CodeName, ptr BSTR
  COM_MTD_STD  put__CodeName, BSTR
  COM_MTD_STD  get_Index, SDWORD, ptr SDWORD
  COM_MTD_STD  Move, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_Next, ptr LPDISPATCH
  COM_MTD_STD  get_OnDoubleClick, SDWORD, ptr BSTR
  COM_MTD_STD  put_OnDoubleClick, SDWORD, BSTR
  COM_MTD_STD  get_OnSheetActivate, SDWORD, ptr BSTR
  COM_MTD_STD  put_OnSheetActivate, SDWORD, BSTR
  COM_MTD_STD  get_OnSheetDeactivate, SDWORD, ptr BSTR
  COM_MTD_STD  put_OnSheetDeactivate, SDWORD, BSTR
  COM_MTD_STD  get_PageSetup, ptr ptr PageSetup
  COM_MTD_STD  get_Previous, ptr LPDISPATCH
  COM_MTD_STD  _PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  _Dummy18
  COM_MTD_STD  _Protect, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get_ProtectContents, SDWORD, ptr BOOL
  COM_MTD_STD  _Dummy21
  COM_MTD_STD  get_ProtectionMode, SDWORD, ptr BOOL
  COM_MTD_STD  _Dummy23
  COM_MTD_STD  _SaveAs, BSTR, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  Select, VARIANT, SDWORD
  COM_MTD_STD  Unprotect, VARIANT, SDWORD
  COM_MTD_STD  get_Visible, SDWORD, ptr XlSheetVisibility
  COM_MTD_STD  put_Visible, SDWORD, XlSheetVisibility
  COM_MTD_STD  get_Shapes, ptr ptr Shapes
  COM_MTD_STD  InsertFile, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  SaveAs, BSTR, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_STD  Protect, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG IModules, IDispatch, <000208AE-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Add_, VARIANT, VARIANT, VARIANT, ptr ptr Module
  COM_MTD_STD  Copy, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Delete, SDWORD
  COM_MTD_STD  _Dummy7
  COM_MTD_STD  get_Item, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  Move, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  _PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  _Dummy12
  COM_MTD_STD  Select, VARIANT, SDWORD
  COM_MTD_STD  get_HPageBreaks, ptr ptr HPageBreaks
  COM_MTD_STD  get_VPageBreaks, ptr ptr VPageBreaks
  COM_MTD_STD  get_Visible, SDWORD, ptr VARIANT
  COM_MTD_STD  put_Visible, SDWORD, VARIANT
  COM_MTD_STD  get__Default, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG IDialogSheet, IDispatch, <000208AF-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Activate, SDWORD
  COM_MTD_STD  Copy, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  Delete, SDWORD
  COM_MTD_STD  get_CodeName, ptr BSTR
  COM_MTD_STD  get__CodeName, ptr BSTR
  COM_MTD_STD  put__CodeName, BSTR
  COM_MTD_STD  get_Index, SDWORD, ptr SDWORD
  COM_MTD_STD  Move, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_Next, ptr LPDISPATCH
  COM_MTD_STD  get_OnDoubleClick, SDWORD, ptr BSTR
  COM_MTD_STD  put_OnDoubleClick, SDWORD, BSTR
  COM_MTD_STD  get_OnSheetActivate, SDWORD, ptr BSTR
  COM_MTD_STD  put_OnSheetActivate, SDWORD, BSTR
  COM_MTD_STD  get_OnSheetDeactivate, SDWORD, ptr BSTR
  COM_MTD_STD  put_OnSheetDeactivate, SDWORD, BSTR
  COM_MTD_STD  get_PageSetup, ptr ptr PageSetup
  COM_MTD_STD  get_Previous, ptr LPDISPATCH
  COM_MTD_STD  _PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  PrintPreview, VARIANT, SDWORD
  COM_MTD_STD  _Protect, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get_ProtectContents, SDWORD, ptr BOOL
  COM_MTD_STD  get_ProtectDrawingObjects, SDWORD, ptr BOOL
  COM_MTD_STD  get_ProtectionMode, SDWORD, ptr BOOL
  COM_MTD_STD  get_ProtectScenarios, SDWORD, ptr BOOL
  COM_MTD_STD  _SaveAs, BSTR, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  Select, VARIANT, SDWORD
  COM_MTD_STD  Unprotect, VARIANT, SDWORD
  COM_MTD_STD  get_Visible, SDWORD, ptr XlSheetVisibility
  COM_MTD_STD  put_Visible, SDWORD, XlSheetVisibility
  COM_MTD_STD  get_Shapes, ptr ptr Shapes
  COM_MTD_STD  _Dummy29
  COM_MTD_STD  Arcs, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  _Dummy31
  COM_MTD_STD  _Dummy32
  COM_MTD_STD  Buttons, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  _Dummy34
  COM_MTD_STD  get_EnableCalculation, ptr BOOL
  COM_MTD_STD  put_EnableCalculation, BOOL
  COM_MTD_STD  _Dummy36
  COM_MTD_STD  ChartObjects, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  CheckBoxes, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  _Dummy40
  COM_MTD_STD  _Dummy41
  COM_MTD_STD  _Dummy42
  COM_MTD_STD  _Dummy43
  COM_MTD_STD  _Dummy44
  COM_MTD_STD  _Dummy45
  COM_MTD_STD  get_DisplayAutomaticPageBreaks, SDWORD, ptr BOOL
  COM_MTD_STD  put_DisplayAutomaticPageBreaks, SDWORD, BOOL
  COM_MTD_STD  Drawings, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  DrawingObjects, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  DropDowns, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  get_EnableAutoFilter, SDWORD, ptr BOOL
  COM_MTD_STD  put_EnableAutoFilter, SDWORD, BOOL
  COM_MTD_STD  get_EnableSelection, ptr XlEnableSelection
  COM_MTD_STD  put_EnableSelection, XlEnableSelection
  COM_MTD_STD  get_EnableOutlining, SDWORD, ptr BOOL
  COM_MTD_STD  put_EnableOutlining, SDWORD, BOOL
  COM_MTD_STD  get_EnablePivotTable, SDWORD, ptr BOOL
  COM_MTD_STD  put_EnablePivotTable, SDWORD, BOOL
  COM_MTD_STD  Evaluate, VARIANT, SDWORD, ptr VARIANT
  COM_MTD_STD  _Evaluate, VARIANT, SDWORD, ptr VARIANT
  COM_MTD_STD  _Dummy56
  COM_MTD_STD  ResetAllPageBreaks
  COM_MTD_STD  GroupBoxes, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  GroupObjects, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  Labels, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  Lines, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  ListBoxes, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  get_Names, ptr ptr Names
  COM_MTD_STD  OLEObjects, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  _Dummy65
  COM_MTD_STD  _Dummy66
  COM_MTD_STD  _Dummy67
  COM_MTD_STD  OptionButtons, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  _Dummy69
  COM_MTD_STD  Ovals, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  Paste, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  _PasteSpecial, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  Pictures, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  _Dummy74
  COM_MTD_STD  _Dummy75
  COM_MTD_STD  _Dummy76
  COM_MTD_STD  Rectangles, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  _Dummy78
  COM_MTD_STD  _Dummy79
  COM_MTD_STD  get_ScrollArea, ptr BSTR
  COM_MTD_STD  put_ScrollArea, BSTR
  COM_MTD_STD  ScrollBars, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  _Dummy82
  COM_MTD_STD  _Dummy83
  COM_MTD_STD  Spinners, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  _Dummy85
  COM_MTD_STD  _Dummy86
  COM_MTD_STD  TextBoxes, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  _Dummy88
  COM_MTD_STD  _Dummy89
  COM_MTD_STD  _Dummy90
  COM_MTD_STD  get_HPageBreaks, ptr ptr HPageBreaks
  COM_MTD_STD  get_VPageBreaks, ptr ptr VPageBreaks
  COM_MTD_STD  get_QueryTables, ptr ptr QueryTables
  COM_MTD_STD  get_DisplayPageBreaks, ptr BOOL
  COM_MTD_STD  put_DisplayPageBreaks, BOOL
  COM_MTD_STD  get_Comments, ptr ptr Comments
  COM_MTD_STD  get_Hyperlinks, ptr ptr Hyperlinks
  COM_MTD_STD  ClearCircles
  COM_MTD_STD  CircleInvalid
  COM_MTD_STD  get__DisplayRightToLeft, SDWORD, ptr SDWORD
  COM_MTD_STD  put__DisplayRightToLeft, SDWORD, SDWORD
  COM_MTD_STD  get_AutoFilter, ptr ptr AutoFilter
  COM_MTD_STD  get_DisplayRightToLeft, SDWORD, ptr BOOL
  COM_MTD_STD  put_DisplayRightToLeft, SDWORD, BOOL
  COM_MTD_STD  get_Scripts, ptr ptr Scripts
  COM_MTD_STD  PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  _CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get_Tab, ptr ptr Tab
  COM_MTD_STD  get_MailEnvelope, ptr ptr MsoEnvelope
  COM_MTD_STD  SaveAs, BSTR, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_STD  get_CustomProperties, ptr ptr CustomProperties
  COM_MTD_STD  get_SmartTags, ptr ptr SmartTags
  COM_MTD_STD  get_Protection, ptr ptr Protection
  COM_MTD_STD  PasteSpecial, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  Protect, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_STD  get_DefaultButton, ptr VARIANT
  COM_MTD_STD  put_DefaultButton, VARIANT
  COM_MTD_STD  get_DialogFrame, ptr ptr DialogFrame
  COM_MTD_STD  EditBoxes, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  get_Focus, ptr VARIANT
  COM_MTD_STD  put_Focus, VARIANT
  COM_MTD_STD  Hide, VARIANT, ptr BOOL
  COM_MTD_STD  Show, ptr BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG IDialogSheets, IDispatch, <000208B0-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Add_, VARIANT, VARIANT, VARIANT, ptr ptr DialogSheet
  COM_MTD_STD  Copy, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Delete, SDWORD
  COM_MTD_STD  _Dummy7
  COM_MTD_STD  get_Item, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  Move, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  _PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  PrintPreview, VARIANT, SDWORD
  COM_MTD_STD  Select, VARIANT, SDWORD
  COM_MTD_STD  get_HPageBreaks, ptr ptr HPageBreaks
  COM_MTD_STD  get_VPageBreaks, ptr ptr VPageBreaks
  COM_MTD_STD  get_Visible, SDWORD, ptr VARIANT
  COM_MTD_STD  put_Visible, SDWORD, VARIANT
  COM_MTD_STD  get__Default, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG IWorksheets, IDispatch, <000208B1-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Add_, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  Copy, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Delete, SDWORD
  COM_MTD_STD  FillAcrossSheets, ptr Range, XlFillWith, SDWORD
  COM_MTD_STD  get_Item, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  Move, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  _PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
  COM_MTD_STD  PrintPreview, VARIANT, SDWORD
  COM_MTD_STD  Select, VARIANT, SDWORD
  COM_MTD_STD  get_HPageBreaks, ptr ptr HPageBreaks
  COM_MTD_STD  get_VPageBreaks, ptr ptr VPageBreaks
  COM_MTD_STD  get_Visible, SDWORD, ptr VARIANT
  COM_MTD_STD  put_Visible, SDWORD, VARIANT
  COM_MTD_STD  get__Default, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG IPageSetup, IDispatch, <000208B4-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_BlackAndWhite, ptr BOOL
  COM_MTD_STD  put_BlackAndWhite, BOOL
  COM_MTD_STD  get_BottomMargin, ptr REAL8
  COM_MTD_STD  put_BottomMargin, REAL8
  COM_MTD_STD  get_CenterFooter, ptr BSTR
  COM_MTD_STD  put_CenterFooter, BSTR
  COM_MTD_STD  get_CenterHeader, ptr BSTR
  COM_MTD_STD  put_CenterHeader, BSTR
  COM_MTD_STD  get_CenterHorizontally, ptr BOOL
  COM_MTD_STD  put_CenterHorizontally, BOOL
  COM_MTD_STD  get_CenterVertically, ptr BOOL
  COM_MTD_STD  put_CenterVertically, BOOL
  COM_MTD_STD  get_ChartSize, ptr XlObjectSize
  COM_MTD_STD  put_ChartSize, XlObjectSize
  COM_MTD_STD  get_Draft, ptr BOOL
  COM_MTD_STD  put_Draft, BOOL
  COM_MTD_STD  get_FirstPageNumber, ptr SDWORD
  COM_MTD_STD  put_FirstPageNumber, SDWORD
  COM_MTD_STD  get_FitToPagesTall, ptr VARIANT
  COM_MTD_STD  put_FitToPagesTall, VARIANT
  COM_MTD_STD  get_FitToPagesWide, ptr VARIANT
  COM_MTD_STD  put_FitToPagesWide, VARIANT
  COM_MTD_STD  get_FooterMargin, ptr REAL8
  COM_MTD_STD  put_FooterMargin, REAL8
  COM_MTD_STD  get_HeaderMargin, ptr REAL8
  COM_MTD_STD  put_HeaderMargin, REAL8
  COM_MTD_STD  get_LeftFooter, ptr BSTR
  COM_MTD_STD  put_LeftFooter, BSTR
  COM_MTD_STD  get_LeftHeader, ptr BSTR
  COM_MTD_STD  put_LeftHeader, BSTR
  COM_MTD_STD  get_LeftMargin, ptr REAL8
  COM_MTD_STD  put_LeftMargin, REAL8
  COM_MTD_STD  get_Order, ptr XlOrder
  COM_MTD_STD  put_Order, XlOrder
  COM_MTD_STD  get_Orientation, ptr XlPageOrientation
  COM_MTD_STD  put_Orientation, XlPageOrientation
  COM_MTD_STD  get_PaperSize, ptr XlPaperSize
  COM_MTD_STD  put_PaperSize, XlPaperSize
  COM_MTD_STD  get_PrintArea, ptr BSTR
  COM_MTD_STD  put_PrintArea, BSTR
  COM_MTD_STD  get_PrintGridlines, ptr BOOL
  COM_MTD_STD  put_PrintGridlines, BOOL
  COM_MTD_STD  get_PrintHeadings, ptr BOOL
  COM_MTD_STD  put_PrintHeadings, BOOL
  COM_MTD_STD  get_PrintNotes, ptr BOOL
  COM_MTD_STD  put_PrintNotes, BOOL
  COM_MTD_STD  get_PrintQuality, VARIANT, ptr VARIANT
  COM_MTD_STD  put_PrintQuality, VARIANT, VARIANT
  COM_MTD_STD  get_PrintTitleColumns, ptr BSTR
  COM_MTD_STD  put_PrintTitleColumns, BSTR
  COM_MTD_STD  get_PrintTitleRows, ptr BSTR
  COM_MTD_STD  put_PrintTitleRows, BSTR
  COM_MTD_STD  get_RightFooter, ptr BSTR
  COM_MTD_STD  put_RightFooter, BSTR
  COM_MTD_STD  get_RightHeader, ptr BSTR
  COM_MTD_STD  put_RightHeader, BSTR
  COM_MTD_STD  get_RightMargin, ptr REAL8
  COM_MTD_STD  put_RightMargin, REAL8
  COM_MTD_STD  get_TopMargin, ptr REAL8
  COM_MTD_STD  put_TopMargin, REAL8
  COM_MTD_STD  get_Zoom, ptr VARIANT
  COM_MTD_STD  put_Zoom, VARIANT
  COM_MTD_STD  get_PrintComments, ptr XlPrintLocation
  COM_MTD_STD  put_PrintComments, XlPrintLocation
  COM_MTD_STD  get_PrintErrors, ptr XlPrintErrors
  COM_MTD_STD  put_PrintErrors, XlPrintErrors
  COM_MTD_STD  get_CenterHeaderPicture, ptr ptr Graphic
  COM_MTD_STD  get_CenterFooterPicture, ptr ptr Graphic
  COM_MTD_STD  get_LeftHeaderPicture, ptr ptr Graphic
  COM_MTD_STD  get_LeftFooterPicture, ptr ptr Graphic
  COM_MTD_STD  get_RightHeaderPicture, ptr ptr Graphic
  COM_MTD_STD  get_RightFooterPicture, ptr ptr Graphic
COM_INTERFACE_END

COM_INTERFACE_BEG INames, IDispatch, <000208B8-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Add_, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr ptr Name_
  COM_MTD_STD  Item, VARIANT, VARIANT, VARIANT, SDWORD, ptr ptr Name_
  COM_MTD_STD  _Default, VARIANT, VARIANT, VARIANT, SDWORD, ptr ptr Name_
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IName, IDispatch, <000208B9-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get__Default, ptr BSTR
  COM_MTD_STD  get_Index, ptr SDWORD
  COM_MTD_STD  get_Category, SDWORD, ptr BSTR
  COM_MTD_STD  put_Category, SDWORD, BSTR
  COM_MTD_STD  get_CategoryLocal, ptr BSTR
  COM_MTD_STD  put_CategoryLocal, BSTR
  COM_MTD_STD  Delete
  COM_MTD_STD  get_MacroType, ptr XlXLMMacroType
  COM_MTD_STD  put_MacroType, XlXLMMacroType
  COM_MTD_STD  get_Name, SDWORD, ptr BSTR
  COM_MTD_STD  put_Name, SDWORD, BSTR
  COM_MTD_STD  get_RefersTo, SDWORD, ptr VARIANT
  COM_MTD_STD  put_RefersTo, SDWORD, VARIANT
  COM_MTD_STD  get_ShortcutKey, ptr BSTR
  COM_MTD_STD  put_ShortcutKey, BSTR
  COM_MTD_STD  get_Value, ptr BSTR
  COM_MTD_STD  put_Value, BSTR
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_NameLocal, ptr BSTR
  COM_MTD_STD  put_NameLocal, BSTR
  COM_MTD_STD  get_RefersToLocal, ptr VARIANT
  COM_MTD_STD  put_RefersToLocal, VARIANT
  COM_MTD_STD  get_RefersToR1C1, SDWORD, ptr VARIANT
  COM_MTD_STD  put_RefersToR1C1, SDWORD, VARIANT
  COM_MTD_STD  get_RefersToR1C1Local, ptr VARIANT
  COM_MTD_STD  put_RefersToR1C1Local, VARIANT
  COM_MTD_STD  get_RefersToRange, ptr ptr Range
COM_INTERFACE_END

COM_INTERFACE_BEG IChartObject, IDispatch, <000208CF-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_BottomRightCell, ptr ptr Range
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  get_Index, ptr SDWORD
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  get_TopLeftCell, ptr ptr Range
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_ZOrder, ptr SDWORD
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  Activate, ptr VARIANT
  COM_MTD_STD  get_Chart, ptr ptr Chart
  COM_MTD_STD  get_ProtectChartObject, ptr BOOL
  COM_MTD_STD  put_ProtectChartObject, BOOL
  COM_MTD_STD  get_RoundedCorners, ptr BOOL
  COM_MTD_STD  put_RoundedCorners, BOOL
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_Shadow, ptr BOOL
  COM_MTD_STD  put_Shadow, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG IChartObjects, IDispatch, <000208D0-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  _Dummy3
  COM_MTD_STD  BringToFront, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_STD  Cut, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  Duplicate, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  _Dummy12
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  _Dummy15
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Placement, ptr VARIANT
  COM_MTD_STD  put_Placement, VARIANT
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  Select, VARIANT, ptr VARIANT
  COM_MTD_STD  SendToBack, ptr VARIANT
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  _Dummy22
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  _Dummy25
  COM_MTD_STD  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_STD  _Dummy27
  COM_MTD_STD  _Dummy28
  COM_MTD_STD  _Dummy29
  COM_MTD_STD  get_RoundedCorners, ptr BOOL
  COM_MTD_STD  put_RoundedCorners, BOOL
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_Shadow, ptr BOOL
  COM_MTD_STD  put_Shadow, BOOL
  COM_MTD_STD  Add_, REAL8, REAL8, REAL8, REAL8, ptr ptr ChartObject
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Group_, ptr ptr GroupObject
  COM_MTD_STD  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IMailer, IDispatch, <000208D1-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_BCCRecipients, ptr VARIANT
  COM_MTD_STD  put_BCCRecipients, VARIANT
  COM_MTD_STD  get_CCRecipients, ptr VARIANT
  COM_MTD_STD  put_CCRecipients, VARIANT
  COM_MTD_STD  get_Enclosures, ptr VARIANT
  COM_MTD_STD  put_Enclosures, VARIANT
  COM_MTD_STD  get_Received, ptr BOOL
  COM_MTD_STD  get_SendDateTime, ptr Date
  COM_MTD_STD  get_Sender, ptr BSTR
  COM_MTD_STD  get_Subject, ptr BSTR
  COM_MTD_STD  put_Subject, BSTR
  COM_MTD_STD  get_ToRecipients, ptr VARIANT
  COM_MTD_STD  put_ToRecipients, VARIANT
  COM_MTD_STD  get_WhichAddress, ptr VARIANT
  COM_MTD_STD  put_WhichAddress, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG ICustomViews, IDispatch, <00024422-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Item, VARIANT, ptr ptr CustomView
  COM_MTD_STD  Add_, BSTR, VARIANT, VARIANT, ptr ptr CustomView
  COM_MTD_STD  get__Default, VARIANT, ptr ptr CustomView
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG ICustomView, IDispatch, <00024423-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  get_PrintSettings, ptr BOOL
  COM_MTD_STD  get_RowColSettings, ptr BOOL
  COM_MTD_STD  Show
  COM_MTD_STD  Delete
COM_INTERFACE_END

COM_INTERFACE_BEG IFormatConditions, IDispatch, <00024424-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Item, VARIANT, ptr ptr FormatCondition
  COM_MTD_STD  Add_, XlFormatConditionType, VARIANT, VARIANT, VARIANT, ptr ptr FormatCondition
  COM_MTD_STD  get__Default, VARIANT, ptr ptr FormatCondition
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  Delete
COM_INTERFACE_END

COM_INTERFACE_BEG IFormatCondition, IDispatch, <00024425-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Modify, XlFormatConditionType, VARIANT, VARIANT, VARIANT
  COM_MTD_STD  get_Type, ptr SDWORD
  COM_MTD_STD  get_Operator, ptr SDWORD
  COM_MTD_STD  get_Formula1, ptr BSTR
  COM_MTD_STD  get_Formula2, ptr BSTR
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_Borders, ptr ptr Borders
  COM_MTD_STD  get_Font, ptr ptr Font
  COM_MTD_STD  Delete
COM_INTERFACE_END

COM_INTERFACE_BEG IComments, IDispatch, <00024426-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Item, SDWORD, ptr ptr Comment_
  COM_MTD_STD  get__Default, SDWORD, ptr ptr Comment_
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IComment, IDispatch, <00024427-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Author, ptr BSTR
  COM_MTD_STD  get_Shape, ptr ptr Shape
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  Text, VARIANT, VARIANT, VARIANT, ptr BSTR
  COM_MTD_STD  Delete
  COM_MTD_STD  Next, ptr ptr Comment_
  COM_MTD_STD  Previous, ptr ptr Comment_
COM_INTERFACE_END

COM_INTERFACE_BEG IRefreshEvents, IDispatch, <0002441B-0001-0000-C000-000000000046>
  COM_MTD_STD  BeforeRefresh, ptr BOOL
  COM_MTD_STD  AfterRefresh, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG _IQueryTable, IDispatch, <00024428-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_FieldNames, ptr BOOL
  COM_MTD_STD  put_FieldNames, BOOL
  COM_MTD_STD  get_RowNumbers, ptr BOOL
  COM_MTD_STD  put_RowNumbers, BOOL
  COM_MTD_STD  get_FillAdjacentFormulas, ptr BOOL
  COM_MTD_STD  put_FillAdjacentFormulas, BOOL
  COM_MTD_STD  get_HasAutoFormat, ptr BOOL
  COM_MTD_STD  put_HasAutoFormat, BOOL
  COM_MTD_STD  get_RefreshOnFileOpen, ptr BOOL
  COM_MTD_STD  put_RefreshOnFileOpen, BOOL
  COM_MTD_STD  get_Refreshing, ptr BOOL
  COM_MTD_STD  get_FetchedRowOverflow, ptr BOOL
  COM_MTD_STD  get_BackgroundQuery, ptr BOOL
  COM_MTD_STD  put_BackgroundQuery, BOOL
  COM_MTD_STD  CancelRefresh
  COM_MTD_STD  get_RefreshStyle, ptr XlCellInsertionMode
  COM_MTD_STD  put_RefreshStyle, XlCellInsertionMode
  COM_MTD_STD  get_EnableRefresh, ptr BOOL
  COM_MTD_STD  put_EnableRefresh, BOOL
  COM_MTD_STD  get_SavePassword, ptr BOOL
  COM_MTD_STD  put_SavePassword, BOOL
  COM_MTD_STD  get_Destination, ptr ptr Range
  COM_MTD_STD  get_Connection, ptr VARIANT
  COM_MTD_STD  put_Connection, VARIANT
  COM_MTD_STD  get_Sql, ptr VARIANT
  COM_MTD_STD  put_Sql, VARIANT
  COM_MTD_STD  get_PostText, ptr BSTR
  COM_MTD_STD  put_PostText, BSTR
  COM_MTD_STD  get_ResultRange, ptr ptr Range
  COM_MTD_STD  Delete
  COM_MTD_STD  Refresh, VARIANT, ptr BOOL
  COM_MTD_STD  get_Parameters, ptr ptr Parameters
  COM_MTD_STD  get_Recordset, ptr LPDISPATCH
  COM_MTD_STD  putref_Recordset, LPDISPATCH
  COM_MTD_STD  get_SaveData, ptr BOOL
  COM_MTD_STD  put_SaveData, BOOL
  COM_MTD_STD  get_TablesOnlyFromHTML, ptr BOOL
  COM_MTD_STD  put_TablesOnlyFromHTML, BOOL
  COM_MTD_STD  get_EnableEditing, ptr BOOL
  COM_MTD_STD  put_EnableEditing, BOOL
  COM_MTD_STD  get_TextFilePlatform, ptr SDWORD
  COM_MTD_STD  put_TextFilePlatform, SDWORD
  COM_MTD_STD  get_TextFileStartRow, ptr SDWORD
  COM_MTD_STD  put_TextFileStartRow, SDWORD
  COM_MTD_STD  get_TextFileParseType, ptr XlTextParsingType
  COM_MTD_STD  put_TextFileParseType, XlTextParsingType
  COM_MTD_STD  get_TextFileTextQualifier, ptr XlTextQualifier
  COM_MTD_STD  put_TextFileTextQualifier, XlTextQualifier
  COM_MTD_STD  get_TextFileConsecutiveDelimiter, ptr BOOL
  COM_MTD_STD  put_TextFileConsecutiveDelimiter, BOOL
  COM_MTD_STD  get_TextFileTabDelimiter, ptr BOOL
  COM_MTD_STD  put_TextFileTabDelimiter, BOOL
  COM_MTD_STD  get_TextFileSemicolonDelimiter, ptr BOOL
  COM_MTD_STD  put_TextFileSemicolonDelimiter, BOOL
  COM_MTD_STD  get_TextFileCommaDelimiter, ptr BOOL
  COM_MTD_STD  put_TextFileCommaDelimiter, BOOL
  COM_MTD_STD  get_TextFileSpaceDelimiter, ptr BOOL
  COM_MTD_STD  put_TextFileSpaceDelimiter, BOOL
  COM_MTD_STD  get_TextFileOtherDelimiter, ptr BSTR
  COM_MTD_STD  put_TextFileOtherDelimiter, BSTR
  COM_MTD_STD  get_TextFileColumnDataTypes, ptr VARIANT
  COM_MTD_STD  put_TextFileColumnDataTypes, VARIANT
  COM_MTD_STD  get_TextFileFixedColumnWidths, ptr VARIANT
  COM_MTD_STD  put_TextFileFixedColumnWidths, VARIANT
  COM_MTD_STD  get_PreserveColumnInfo, ptr BOOL
  COM_MTD_STD  put_PreserveColumnInfo, BOOL
  COM_MTD_STD  get_PreserveFormatting, ptr BOOL
  COM_MTD_STD  put_PreserveFormatting, BOOL
  COM_MTD_STD  get_AdjustColumnWidth, ptr BOOL
  COM_MTD_STD  put_AdjustColumnWidth, BOOL
  COM_MTD_STD  get_CommandText, ptr VARIANT
  COM_MTD_STD  put_CommandText, VARIANT
  COM_MTD_STD  get_CommandType, ptr XlCmdType
  COM_MTD_STD  put_CommandType, XlCmdType
  COM_MTD_STD  get_TextFilePromptOnRefresh, ptr BOOL
  COM_MTD_STD  put_TextFilePromptOnRefresh, BOOL
  COM_MTD_STD  get_QueryType, ptr XlQueryType
  COM_MTD_STD  get_MaintainConnection, ptr BOOL
  COM_MTD_STD  put_MaintainConnection, BOOL
  COM_MTD_STD  get_TextFileDecimalSeparator, ptr BSTR
  COM_MTD_STD  put_TextFileDecimalSeparator, BSTR
  COM_MTD_STD  get_TextFileThousandsSeparator, ptr BSTR
  COM_MTD_STD  put_TextFileThousandsSeparator, BSTR
  COM_MTD_STD  get_RefreshPeriod, ptr SDWORD
  COM_MTD_STD  put_RefreshPeriod, SDWORD
  COM_MTD_STD  ResetTimer
  COM_MTD_STD  get_WebSelectionType, ptr XlWebSelectionType
  COM_MTD_STD  put_WebSelectionType, XlWebSelectionType
  COM_MTD_STD  get_WebFormatting, ptr XlWebFormatting
  COM_MTD_STD  put_WebFormatting, XlWebFormatting
  COM_MTD_STD  get_WebTables, ptr BSTR
  COM_MTD_STD  put_WebTables, BSTR
  COM_MTD_STD  get_WebPreFormattedTextToColumns, ptr BOOL
  COM_MTD_STD  put_WebPreFormattedTextToColumns, BOOL
  COM_MTD_STD  get_WebSingleBlockTextImport, ptr BOOL
  COM_MTD_STD  put_WebSingleBlockTextImport, BOOL
  COM_MTD_STD  get_WebDisableDateRecognition, ptr BOOL
  COM_MTD_STD  put_WebDisableDateRecognition, BOOL
  COM_MTD_STD  get_WebConsecutiveDelimitersAsOne, ptr BOOL
  COM_MTD_STD  put_WebConsecutiveDelimitersAsOne, BOOL
  COM_MTD_STD  get_WebDisableRedirections, ptr BOOL
  COM_MTD_STD  put_WebDisableRedirections, BOOL
  COM_MTD_STD  get_EditWebPage, ptr VARIANT
  COM_MTD_STD  put_EditWebPage, VARIANT
  COM_MTD_STD  get_SourceConnectionFile, ptr BSTR
  COM_MTD_STD  put_SourceConnectionFile, BSTR
  COM_MTD_STD  get_SourceDataFile, ptr BSTR
  COM_MTD_STD  put_SourceDataFile, BSTR
  COM_MTD_STD  get_RobustConnect, ptr XlRobustConnect
  COM_MTD_STD  put_RobustConnect, XlRobustConnect
  COM_MTD_STD  get_TextFileTrailingMinusNumbers, ptr BOOL
  COM_MTD_STD  put_TextFileTrailingMinusNumbers, BOOL
  COM_MTD_STD  SaveAsODC, BSTR, VARIANT, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG IQueryTables, IDispatch, <00024429-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Add_, VARIANT, ptr Range, VARIANT, ptr ptr QueryTable
  COM_MTD_STD  Item, VARIANT, ptr ptr QueryTable
  COM_MTD_STD  get__Default, VARIANT, ptr ptr QueryTable
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IParameter, IDispatch, <0002442A-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_DataType, ptr XlParameterDataType
  COM_MTD_STD  put_DataType, XlParameterDataType
  COM_MTD_STD  get_Type, ptr XlParameterType
  COM_MTD_STD  get_PromptString, ptr BSTR
  COM_MTD_STD  get_Value, ptr VARIANT
  COM_MTD_STD  get_SourceRange, ptr ptr Range
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  SetParam, XlParameterType, VARIANT
  COM_MTD_STD  get_RefreshOnChange, ptr BOOL
  COM_MTD_STD  put_RefreshOnChange, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG IParameters, IDispatch, <0002442B-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Add_, BSTR, VARIANT, ptr ptr Parameter
  COM_MTD_STD  get_Count, ptr SDWORD

  COM_MTD_STD  Item, VARIANT, ptr ptr Parameter
  COM_MTD_STD  get__Default, VARIANT, ptr ptr Parameter
  COM_MTD_STD  Delete
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IODBCError, IDispatch, <0002442C-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_SqlState, ptr BSTR
  COM_MTD_STD  get_ErrorString, ptr BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG IODBCErrors, IDispatch, <0002442D-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Item, SDWORD, ptr ptr ODBCError
  COM_MTD_STD  get__Default, SDWORD, ptr ptr ODBCError
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IValidation, IDispatch, <0002442F-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Add_, XlDVType, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_STD  get_AlertStyle, ptr SDWORD
  COM_MTD_STD  get_IgnoreBlank, ptr BOOL
  COM_MTD_STD  put_IgnoreBlank, BOOL
  COM_MTD_STD  get_IMEMode, ptr SDWORD
  COM_MTD_STD  put_IMEMode, SDWORD
  COM_MTD_STD  get_InCellDropdown, ptr BOOL
  COM_MTD_STD  put_InCellDropdown, BOOL
  COM_MTD_STD  Delete
  COM_MTD_STD  get_ErrorMessage, ptr BSTR
  COM_MTD_STD  put_ErrorMessage, BSTR
  COM_MTD_STD  get_ErrorTitle, ptr BSTR
  COM_MTD_STD  put_ErrorTitle, BSTR
  COM_MTD_STD  get_InputMessage, ptr BSTR
  COM_MTD_STD  put_InputMessage, BSTR
  COM_MTD_STD  get_InputTitle, ptr BSTR
  COM_MTD_STD  put_InputTitle, BSTR
  COM_MTD_STD  get_Formula1, ptr BSTR
  COM_MTD_STD  get_Formula2, ptr BSTR
  COM_MTD_STD  Modify, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_STD  get_Operator, ptr SDWORD
  COM_MTD_STD  get_ShowError, ptr BOOL
  COM_MTD_STD  put_ShowError, BOOL
  COM_MTD_STD  get_ShowInput, ptr BOOL
  COM_MTD_STD  put_ShowInput, BOOL
  COM_MTD_STD  get_Type, ptr SDWORD
  COM_MTD_STD  get_Value, ptr BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG IHyperlinks, IDispatch, <00024430-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Add_, LPDISPATCH, BSTR, VARIANT, VARIANT, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  get_Item, VARIANT, ptr ptr Hyperlink
  COM_MTD_STD  get__Default, VARIANT, ptr ptr Hyperlink
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  Delete
COM_INTERFACE_END

COM_INTERFACE_BEG IHyperlink, IDispatch, <00024431-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  get_Range, ptr ptr Range
  COM_MTD_STD  get_Shape, ptr ptr Shape
  COM_MTD_STD  get_SubAddress, ptr BSTR
  COM_MTD_STD  put_SubAddress, BSTR
  COM_MTD_STD  get_Address, ptr BSTR
  COM_MTD_STD  put_Address, BSTR
  COM_MTD_STD  get_Type, ptr SDWORD
  COM_MTD_STD  AddToFavorites
  COM_MTD_STD  Delete
  COM_MTD_STD  Follow, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_STD  get_EmailSubject, ptr BSTR
  COM_MTD_STD  put_EmailSubject, BSTR
  COM_MTD_STD  get_ScreenTip, ptr BSTR
  COM_MTD_STD  put_ScreenTip, BSTR
  COM_MTD_STD  get_TextToDisplay, ptr BSTR
  COM_MTD_STD  put_TextToDisplay, BSTR
  COM_MTD_STD  CreateNewDocument, BSTR, BOOL, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG IAutoFilter, IDispatch, <00024432-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Range, ptr ptr Range
  COM_MTD_STD  get_Filters, ptr ptr Filters
COM_INTERFACE_END

COM_INTERFACE_BEG IFilters, IDispatch, <00024433-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  get__Default, SDWORD, ptr ptr Filter
  COM_MTD_STD  get_Item, SDWORD, ptr ptr Filter
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IFilter, IDispatch, <00024434-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_On, ptr BOOL
  COM_MTD_STD  get_Criteria1, ptr VARIANT
  COM_MTD_STD  get_Operator, ptr XlAutoFilterOperator
  COM_MTD_STD  get_Criteria2, ptr VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG IAutoCorrect, IDispatch, <000208D4-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  AddReplacement, BSTR, BSTR, ptr VARIANT
  COM_MTD_STD  get_CapitalizeNamesOfDays, ptr BOOL
  COM_MTD_STD  put_CapitalizeNamesOfDays, BOOL
  COM_MTD_STD  DeleteReplacement, BSTR, ptr VARIANT
  COM_MTD_STD  get_ReplacementList, VARIANT, ptr VARIANT
  COM_MTD_STD  put_ReplacementList, VARIANT, VARIANT
  COM_MTD_STD  get_ReplaceText, ptr BOOL
  COM_MTD_STD  put_ReplaceText, BOOL
  COM_MTD_STD  get_TwoInitialCapitals, ptr BOOL
  COM_MTD_STD  put_TwoInitialCapitals, BOOL
  COM_MTD_STD  get_CorrectSentenceCap, ptr BOOL
  COM_MTD_STD  put_CorrectSentenceCap, BOOL
  COM_MTD_STD  get_CorrectCapsLock, ptr BOOL
  COM_MTD_STD  put_CorrectCapsLock, BOOL
  COM_MTD_STD  get_DisplayAutoCorrectOptions, ptr BOOL
  COM_MTD_STD  put_DisplayAutoCorrectOptions, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG IBorder, IDispatch, <00020854-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Color, ptr VARIANT
  COM_MTD_STD  put_Color, VARIANT
  COM_MTD_STD  get_ColorIndex, ptr VARIANT
  COM_MTD_STD  put_ColorIndex, VARIANT
  COM_MTD_STD  get_LineStyle, ptr VARIANT
  COM_MTD_STD  put_LineStyle, VARIANT
  COM_MTD_STD  get_Weight, ptr VARIANT
  COM_MTD_STD  put_Weight, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG IInterior, IDispatch, <00020870-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Color, ptr VARIANT
  COM_MTD_STD  put_Color, VARIANT
  COM_MTD_STD  get_ColorIndex, ptr VARIANT
  COM_MTD_STD  put_ColorIndex, VARIANT
  COM_MTD_STD  get_InvertIfNegative, ptr VARIANT
  COM_MTD_STD  put_InvertIfNegative, VARIANT
  COM_MTD_STD  get_Pattern, ptr VARIANT
  COM_MTD_STD  put_Pattern, VARIANT
  COM_MTD_STD  get_PatternColor, ptr VARIANT
  COM_MTD_STD  put_PatternColor, VARIANT
  COM_MTD_STD  get_PatternColorIndex, ptr VARIANT
  COM_MTD_STD  put_PatternColorIndex, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG IChartFillFormat, IDispatch, <00024435-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  OneColorGradient, MsoGradientStyle, SDWORD, REAL4
  COM_MTD_STD  TwoColorGradient, MsoGradientStyle, SDWORD
  COM_MTD_STD  PresetTextured, MsoPresetTexture
  COM_MTD_STD  Solid
  COM_MTD_STD  Patterned, MsoPatternType
  COM_MTD_STD  UserPicture, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_STD  UserTextured, BSTR
  COM_MTD_STD  PresetGradient, MsoGradientStyle, SDWORD, MsoPresetGradientType
  COM_MTD_STD  get_BackColor, ptr ptr ChartColorFormat
  COM_MTD_STD  get_ForeColor, ptr ptr ChartColorFormat
  COM_MTD_STD  get_GradientColorType, ptr MsoGradientColorType
  COM_MTD_STD  get_GradientDegree, ptr REAL4
  COM_MTD_STD  get_GradientStyle, ptr MsoGradientStyle
  COM_MTD_STD  get_GradientVariant, ptr SDWORD
  COM_MTD_STD  get_Pattern, ptr MsoPatternType
  COM_MTD_STD  get_PresetGradientType, ptr MsoPresetGradientType
  COM_MTD_STD  get_PresetTexture, ptr MsoPresetTexture
  COM_MTD_STD  get_TextureName, ptr BSTR
  COM_MTD_STD  get_TextureType, ptr MsoTextureType
  COM_MTD_STD  get_Type, ptr MsoFillType
  COM_MTD_STD  get_Visible, ptr MsoTriState
  COM_MTD_STD  put_Visible, MsoTriState
COM_INTERFACE_END

COM_INTERFACE_BEG IChartColorFormat, IDispatch, <00024436-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_SchemeColor, ptr SDWORD
  COM_MTD_STD  put_SchemeColor, SDWORD
  COM_MTD_STD  get_RGB, ptr SDWORD
  COM_MTD_STD  get__Default, ptr SDWORD
  COM_MTD_STD  get_Type, ptr SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG IAxis, IDispatch, <00020848-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_AxisBetweenCategories, ptr BOOL
  COM_MTD_STD  put_AxisBetweenCategories, BOOL
  COM_MTD_STD  get_AxisGroup, ptr XlAxisGroup
  COM_MTD_STD  get_AxisTitle, ptr ptr AxisTitle
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  get_CategoryNames, ptr VARIANT
  COM_MTD_STD  put_CategoryNames, VARIANT
  COM_MTD_STD  get_Crosses, ptr XlAxisCrosses
  COM_MTD_STD  put_Crosses, XlAxisCrosses
  COM_MTD_STD  get_CrossesAt, ptr REAL8
  COM_MTD_STD  put_CrossesAt, REAL8
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  get_HasMajorGridlines, ptr BOOL
  COM_MTD_STD  put_HasMajorGridlines, BOOL
  COM_MTD_STD  get_HasMinorGridlines, ptr BOOL
  COM_MTD_STD  put_HasMinorGridlines, BOOL
  COM_MTD_STD  get_HasTitle, ptr BOOL
  COM_MTD_STD  put_HasTitle, BOOL
  COM_MTD_STD  get_MajorGridlines, ptr ptr Gridlines
  COM_MTD_STD  get_MajorTickMark, ptr XlTickMark
  COM_MTD_STD  put_MajorTickMark, XlTickMark
  COM_MTD_STD  get_MajorUnit, ptr REAL8
  COM_MTD_STD  put_MajorUnit, REAL8
  COM_MTD_STD  get_MajorUnitIsAuto, ptr BOOL
  COM_MTD_STD  put_MajorUnitIsAuto, BOOL
  COM_MTD_STD  get_MaximumScale, ptr REAL8
  COM_MTD_STD  put_MaximumScale, REAL8
  COM_MTD_STD  get_MaximumScaleIsAuto, ptr BOOL
  COM_MTD_STD  put_MaximumScaleIsAuto, BOOL
  COM_MTD_STD  get_MinimumScale, ptr REAL8
  COM_MTD_STD  put_MinimumScale, REAL8
  COM_MTD_STD  get_MinimumScaleIsAuto, ptr BOOL
  COM_MTD_STD  put_MinimumScaleIsAuto, BOOL
  COM_MTD_STD  get_MinorGridlines, ptr ptr Gridlines
  COM_MTD_STD  get_MinorTickMark, ptr XlTickMark
  COM_MTD_STD  put_MinorTickMark, XlTickMark
  COM_MTD_STD  get_MinorUnit, ptr REAL8
  COM_MTD_STD  put_MinorUnit, REAL8
  COM_MTD_STD  get_MinorUnitIsAuto, ptr BOOL
  COM_MTD_STD  put_MinorUnitIsAuto, BOOL
  COM_MTD_STD  get_ReversePlotOrder, ptr BOOL
  COM_MTD_STD  put_ReversePlotOrder, BOOL
  COM_MTD_STD  get_ScaleType, ptr XlScaleType
  COM_MTD_STD  put_ScaleType, XlScaleType
  COM_MTD_STD  Select, ptr VARIANT
  COM_MTD_STD  get_TickLabelPosition, ptr XlTickLabelPosition
  COM_MTD_STD  put_TickLabelPosition, XlTickLabelPosition
  COM_MTD_STD  get_TickLabels, ptr ptr TickLabels
  COM_MTD_STD  get_TickLabelSpacing, ptr SDWORD
  COM_MTD_STD  put_TickLabelSpacing, SDWORD
  COM_MTD_STD  get_TickMarkSpacing, ptr SDWORD
  COM_MTD_STD  put_TickMarkSpacing, SDWORD
  COM_MTD_STD  get_Type, ptr XlAxisType
  COM_MTD_STD  put_Type, XlAxisType
  COM_MTD_STD  get_BaseUnit, ptr XlTimeUnit
  COM_MTD_STD  put_BaseUnit, XlTimeUnit
  COM_MTD_STD  get_BaseUnitIsAuto, ptr BOOL
  COM_MTD_STD  put_BaseUnitIsAuto, BOOL
  COM_MTD_STD  get_MajorUnitScale, ptr XlTimeUnit
  COM_MTD_STD  put_MajorUnitScale, XlTimeUnit
  COM_MTD_STD  get_MinorUnitScale, ptr XlTimeUnit
  COM_MTD_STD  put_MinorUnitScale, XlTimeUnit
  COM_MTD_STD  get_CategoryType, ptr XlCategoryType
  COM_MTD_STD  put_CategoryType, XlCategoryType
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  get_DisplayUnit, ptr XlDisplayUnit
  COM_MTD_STD  put_DisplayUnit, XlDisplayUnit
  COM_MTD_STD  get_DisplayUnitCustom, ptr REAL8
  COM_MTD_STD  put_DisplayUnitCustom, REAL8
  COM_MTD_STD  get_HasDisplayUnitLabel, ptr BOOL
  COM_MTD_STD  put_HasDisplayUnitLabel, BOOL
  COM_MTD_STD  get_DisplayUnitLabel, ptr ptr DisplayUnitLabel
COM_INTERFACE_END

COM_INTERFACE_BEG IChartTitle, IDispatch, <00020849-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  Select, ptr VARIANT
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_Fill, ptr ptr ChartFillFormat
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_STD  get_Font, ptr ptr Font
  COM_MTD_STD  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_STD  put_HorizontalAlignment, VARIANT
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Orientation, ptr VARIANT
  COM_MTD_STD  put_Orientation, VARIANT
  COM_MTD_STD  get_Shadow, ptr BOOL
  COM_MTD_STD  put_Shadow, BOOL
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  get_VerticalAlignment, ptr VARIANT
  COM_MTD_STD  put_VerticalAlignment, VARIANT
  COM_MTD_STD  get_ReadingOrder, ptr SDWORD
  COM_MTD_STD  put_ReadingOrder, SDWORD
  COM_MTD_STD  get_AutoScaleFont, ptr VARIANT
  COM_MTD_STD  put_AutoScaleFont, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG IAxisTitle, IDispatch, <0002084A-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  Select, ptr VARIANT
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_Fill, ptr ptr ChartFillFormat
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_STD  get_Font, ptr ptr Font
  COM_MTD_STD  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_STD  put_HorizontalAlignment, VARIANT
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Orientation, ptr VARIANT
  COM_MTD_STD  put_Orientation, VARIANT
  COM_MTD_STD  get_Shadow, ptr BOOL
  COM_MTD_STD  put_Shadow, BOOL
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  get_VerticalAlignment, ptr VARIANT
  COM_MTD_STD  put_VerticalAlignment, VARIANT
  COM_MTD_STD  get_ReadingOrder, ptr SDWORD
  COM_MTD_STD  put_ReadingOrder, SDWORD
  COM_MTD_STD  get_AutoScaleFont, ptr VARIANT
  COM_MTD_STD  put_AutoScaleFont, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG IChartGroup, IDispatch, <00020859-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_AxisGroup, ptr XlAxisGroup
  COM_MTD_STD  put_AxisGroup, XlAxisGroup
  COM_MTD_STD  get_DoughnutHoleSize, ptr SDWORD
  COM_MTD_STD  put_DoughnutHoleSize, SDWORD
  COM_MTD_STD  get_DownBars, ptr ptr DownBars
  COM_MTD_STD  get_DropLines, ptr ptr DropLines
  COM_MTD_STD  get_FirstSliceAngle, ptr SDWORD
  COM_MTD_STD  put_FirstSliceAngle, SDWORD
  COM_MTD_STD  get_GapWidth, ptr SDWORD
  COM_MTD_STD  put_GapWidth, SDWORD
  COM_MTD_STD  get_HasDropLines, ptr BOOL
  COM_MTD_STD  put_HasDropLines, BOOL
  COM_MTD_STD  get_HasHiLoLines, ptr BOOL
  COM_MTD_STD  put_HasHiLoLines, BOOL
  COM_MTD_STD  get_HasRadarAxisLabels, ptr BOOL
  COM_MTD_STD  put_HasRadarAxisLabels, BOOL
  COM_MTD_STD  get_HasSeriesLines, ptr BOOL
  COM_MTD_STD  put_HasSeriesLines, BOOL
  COM_MTD_STD  get_HasUpDownBars, ptr BOOL
  COM_MTD_STD  put_HasUpDownBars, BOOL
  COM_MTD_STD  get_HiLoLines, ptr ptr HiLoLines
  COM_MTD_STD  get_Index, ptr SDWORD
  COM_MTD_STD  get_Overlap, ptr SDWORD
  COM_MTD_STD  put_Overlap, SDWORD
  COM_MTD_STD  get_RadarAxisLabels, ptr ptr TickLabels
  COM_MTD_STD  SeriesCollection, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  get_SeriesLines, ptr ptr SeriesLines
  COM_MTD_STD  get_SubType, ptr SDWORD
  COM_MTD_STD  put_SubType, SDWORD
  COM_MTD_STD  get_Type, ptr SDWORD
  COM_MTD_STD  put_Type, SDWORD
  COM_MTD_STD  get_UpBars, ptr ptr UpBars
  COM_MTD_STD  get_VaryByCategories, ptr BOOL
  COM_MTD_STD  put_VaryByCategories, BOOL
  COM_MTD_STD  get_SizeRepresents, ptr XlSizeRepresents
  COM_MTD_STD  put_SizeRepresents, XlSizeRepresents
  COM_MTD_STD  get_BubbleScale, ptr SDWORD
  COM_MTD_STD  put_BubbleScale, SDWORD
  COM_MTD_STD  get_ShowNegativeBubbles, ptr BOOL
  COM_MTD_STD  put_ShowNegativeBubbles, BOOL
  COM_MTD_STD  get_SplitType, ptr XlChartSplitType
  COM_MTD_STD  put_SplitType, XlChartSplitType
  COM_MTD_STD  get_SplitValue, ptr VARIANT
  COM_MTD_STD  put_SplitValue, VARIANT
  COM_MTD_STD  get_SecondPlotSize, ptr SDWORD
  COM_MTD_STD  put_SecondPlotSize, SDWORD
  COM_MTD_STD  get_Has3DShading, ptr BOOL
  COM_MTD_STD  put_Has3DShading, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG IChartGroups, IDispatch, <0002085A-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Item, VARIANT, ptr ptr ChartGroup
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IAxes, IDispatch, <0002085B-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Item, XlAxisType, XlAxisGroup, ptr ptr Axis
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IPoints, IDispatch, <00020869-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Item, SDWORD, ptr ptr Point
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IPoint, IDispatch, <0002086A-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  ApplyDataLabels, XlDataLabelsType, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  ClearFormats, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  get_DataLabel, ptr ptr DataLabel
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  get_Explosion, ptr SDWORD
  COM_MTD_STD  put_Explosion, SDWORD
  COM_MTD_STD  get_HasDataLabel, ptr BOOL
  COM_MTD_STD  put_HasDataLabel, BOOL
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_InvertIfNegative, ptr BOOL
  COM_MTD_STD  put_InvertIfNegative, BOOL
  COM_MTD_STD  get_MarkerBackgroundColor, ptr SDWORD
  COM_MTD_STD  put_MarkerBackgroundColor, SDWORD
  COM_MTD_STD  get_MarkerBackgroundColorIndex, ptr XlColorIndex
  COM_MTD_STD  put_MarkerBackgroundColorIndex, XlColorIndex
  COM_MTD_STD  get_MarkerForegroundColor, ptr SDWORD
  COM_MTD_STD  put_MarkerForegroundColor, SDWORD
  COM_MTD_STD  get_MarkerForegroundColorIndex, ptr XlColorIndex
  COM_MTD_STD  put_MarkerForegroundColorIndex, XlColorIndex
  COM_MTD_STD  get_MarkerSize, ptr SDWORD
  COM_MTD_STD  put_MarkerSize, SDWORD
  COM_MTD_STD  get_MarkerStyle, ptr XlMarkerStyle
  COM_MTD_STD  put_MarkerStyle, XlMarkerStyle
  COM_MTD_STD  Paste, ptr VARIANT
  COM_MTD_STD  get_PictureType, ptr XlChartPictureType
  COM_MTD_STD  put_PictureType, XlChartPictureType
  COM_MTD_STD  get_PictureUnit, ptr SDWORD
  COM_MTD_STD  put_PictureUnit, SDWORD
  COM_MTD_STD  Select, ptr VARIANT
  COM_MTD_STD  get_ApplyPictToSides, ptr BOOL
  COM_MTD_STD  put_ApplyPictToSides, BOOL
  COM_MTD_STD  get_ApplyPictToFront, ptr BOOL
  COM_MTD_STD  put_ApplyPictToFront, BOOL
  COM_MTD_STD  get_ApplyPictToEnd, ptr BOOL
  COM_MTD_STD  put_ApplyPictToEnd, BOOL
  COM_MTD_STD  get_Shadow, ptr BOOL
  COM_MTD_STD  put_Shadow, BOOL
  COM_MTD_STD  get_SecondaryPlot, ptr BOOL
  COM_MTD_STD  put_SecondaryPlot, BOOL
  COM_MTD_STD  get_Fill, ptr ptr ChartFillFormat
COM_INTERFACE_END

COM_INTERFACE_BEG ISeries, IDispatch, <0002086B-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  ApplyDataLabels, XlDataLabelsType, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_AxisGroup, ptr XlAxisGroup
  COM_MTD_STD  put_AxisGroup, XlAxisGroup
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  ClearFormats, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  DataLabels, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  ErrorBar, XlErrorBarDirection, XlErrorBarInclude, XlErrorBarType, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  get_ErrorBars, ptr ptr ErrorBars
  COM_MTD_STD  get_Explosion, ptr SDWORD
  COM_MTD_STD  put_Explosion, SDWORD
  COM_MTD_STD  get_Formula, ptr BSTR
  COM_MTD_STD  put_Formula, BSTR
  COM_MTD_STD  get_FormulaLocal, ptr BSTR
  COM_MTD_STD  put_FormulaLocal, BSTR
  COM_MTD_STD  get_FormulaR1C1, ptr BSTR
  COM_MTD_STD  put_FormulaR1C1, BSTR
  COM_MTD_STD  get_FormulaR1C1Local, ptr BSTR
  COM_MTD_STD  put_FormulaR1C1Local, BSTR
  COM_MTD_STD  get_HasDataLabels, ptr BOOL
  COM_MTD_STD  put_HasDataLabels, BOOL
  COM_MTD_STD  get_HasErrorBars, ptr BOOL
  COM_MTD_STD  put_HasErrorBars, BOOL
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_Fill, ptr ptr ChartFillFormat
  COM_MTD_STD  get_InvertIfNegative, ptr BOOL
  COM_MTD_STD  put_InvertIfNegative, BOOL
  COM_MTD_STD  get_MarkerBackgroundColor, ptr SDWORD
  COM_MTD_STD  put_MarkerBackgroundColor, SDWORD
  COM_MTD_STD  get_MarkerBackgroundColorIndex, ptr XlColorIndex
  COM_MTD_STD  put_MarkerBackgroundColorIndex, XlColorIndex
  COM_MTD_STD  get_MarkerForegroundColor, ptr SDWORD
  COM_MTD_STD  put_MarkerForegroundColor, SDWORD
  COM_MTD_STD  get_MarkerForegroundColorIndex, ptr XlColorIndex
  COM_MTD_STD  put_MarkerForegroundColorIndex, XlColorIndex
  COM_MTD_STD  get_MarkerSize, ptr SDWORD
  COM_MTD_STD  put_MarkerSize, SDWORD
  COM_MTD_STD  get_MarkerStyle, ptr XlMarkerStyle
  COM_MTD_STD  put_MarkerStyle, XlMarkerStyle
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  Paste, ptr VARIANT
  COM_MTD_STD  get_PictureType, ptr XlChartPictureType
  COM_MTD_STD  put_PictureType, XlChartPictureType
  COM_MTD_STD  get_PictureUnit, ptr SDWORD
  COM_MTD_STD  put_PictureUnit, SDWORD
  COM_MTD_STD  get_PlotOrder, ptr SDWORD
  COM_MTD_STD  put_PlotOrder, SDWORD
  COM_MTD_STD  Points, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  Select, ptr VARIANT
  COM_MTD_STD  get_Smooth, ptr BOOL
  COM_MTD_STD  put_Smooth, BOOL
  COM_MTD_STD  Trendlines, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  get_Type, ptr SDWORD
  COM_MTD_STD  put_Type, SDWORD
  COM_MTD_STD  get_ChartType, ptr XlChartType
  COM_MTD_STD  put_ChartType, XlChartType
  COM_MTD_STD  ApplyCustomType, XlChartType
  COM_MTD_STD  get_Values, ptr VARIANT
  COM_MTD_STD  put_Values, VARIANT
  COM_MTD_STD  get_XValues, ptr VARIANT
  COM_MTD_STD  put_XValues, VARIANT
  COM_MTD_STD  get_BubbleSizes, ptr VARIANT
  COM_MTD_STD  put_BubbleSizes, VARIANT
  COM_MTD_STD  get_BarShape, ptr XlBarShape
  COM_MTD_STD  put_BarShape, XlBarShape
  COM_MTD_STD  get_ApplyPictToSides, ptr BOOL
  COM_MTD_STD  put_ApplyPictToSides, BOOL
  COM_MTD_STD  get_ApplyPictToFront, ptr BOOL
  COM_MTD_STD  put_ApplyPictToFront, BOOL
  COM_MTD_STD  get_ApplyPictToEnd, ptr BOOL
  COM_MTD_STD  put_ApplyPictToEnd, BOOL
  COM_MTD_STD  get_Has3DEffect, ptr BOOL
  COM_MTD_STD  put_Has3DEffect, BOOL
  COM_MTD_STD  get_Shadow, ptr BOOL
  COM_MTD_STD  put_Shadow, BOOL
  COM_MTD_STD  get_HasLeaderLines, ptr BOOL
  COM_MTD_STD  put_HasLeaderLines, BOOL
  COM_MTD_STD  get_LeaderLines, ptr ptr LeaderLines
COM_INTERFACE_END

COM_INTERFACE_BEG ISeriesCollection, IDispatch, <0002086C-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Add_, VARIANT, XlRowCol, VARIANT, VARIANT, VARIANT, ptr ptr Series
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Extend, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  Item, VARIANT, ptr ptr Series
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  Paste, XlRowCol, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_STD  NewSeries, ptr ptr Series
COM_INTERFACE_END

COM_INTERFACE_BEG IDataLabel, IDispatch, <000208B2-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  Select, ptr VARIANT
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_Fill, ptr ptr ChartFillFormat
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_STD  get_Font, ptr ptr Font
  COM_MTD_STD  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_STD  put_HorizontalAlignment, VARIANT
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Orientation, ptr VARIANT
  COM_MTD_STD  put_Orientation, VARIANT
  COM_MTD_STD  get_Shadow, ptr BOOL
  COM_MTD_STD  put_Shadow, BOOL
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  get_VerticalAlignment, ptr VARIANT
  COM_MTD_STD  put_VerticalAlignment, VARIANT
  COM_MTD_STD  get_ReadingOrder, ptr SDWORD
  COM_MTD_STD  put_ReadingOrder, SDWORD
  COM_MTD_STD  get_AutoScaleFont, ptr VARIANT
  COM_MTD_STD  put_AutoScaleFont, VARIANT
  COM_MTD_STD  get_AutoText, ptr BOOL
  COM_MTD_STD  put_AutoText, BOOL
  COM_MTD_STD  get_NumberFormat, ptr BSTR
  COM_MTD_STD  put_NumberFormat, BSTR
  COM_MTD_STD  get_NumberFormatLinked, ptr BOOL
  COM_MTD_STD  put_NumberFormatLinked, BOOL
  COM_MTD_STD  get_NumberFormatLocal, ptr VARIANT
  COM_MTD_STD  put_NumberFormatLocal, VARIANT
  COM_MTD_STD  get_ShowLegendKey, ptr BOOL
  COM_MTD_STD  put_ShowLegendKey, BOOL
  COM_MTD_STD  get_Type, ptr VARIANT
  COM_MTD_STD  put_Type, VARIANT
  COM_MTD_STD  get_Position, ptr XlDataLabelPosition
  COM_MTD_STD  put_Position, XlDataLabelPosition
  COM_MTD_STD  get_ShowSeriesName, ptr BOOL
  COM_MTD_STD  put_ShowSeriesName, BOOL
  COM_MTD_STD  get_ShowCategoryName, ptr BOOL
  COM_MTD_STD  put_ShowCategoryName, BOOL
  COM_MTD_STD  get_ShowValue, ptr BOOL
  COM_MTD_STD  put_ShowValue, BOOL
  COM_MTD_STD  get_ShowPercentage, ptr BOOL
  COM_MTD_STD  put_ShowPercentage, BOOL
  COM_MTD_STD  get_ShowBubbleSize, ptr BOOL
  COM_MTD_STD  put_ShowBubbleSize, BOOL
  COM_MTD_STD  get_Separator, ptr VARIANT
  COM_MTD_STD  put_Separator, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG IDataLabels, IDispatch, <000208B3-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  Select, ptr VARIANT
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_Fill, ptr ptr ChartFillFormat
  COM_MTD_STD  _Dummy9
  COM_MTD_STD  _Dummy10
  COM_MTD_STD  get_Font, ptr ptr Font
  COM_MTD_STD  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_STD  put_HorizontalAlignment, VARIANT
  COM_MTD_STD  _Dummy13
  COM_MTD_STD  get_Orientation, ptr VARIANT
  COM_MTD_STD  put_Orientation, VARIANT
  COM_MTD_STD  get_Shadow, ptr BOOL
  COM_MTD_STD  put_Shadow, BOOL
  COM_MTD_STD  _Dummy16
  COM_MTD_STD  _Dummy17
  COM_MTD_STD  get_VerticalAlignment, ptr VARIANT
  COM_MTD_STD  put_VerticalAlignment, VARIANT
  COM_MTD_STD  get_ReadingOrder, ptr SDWORD
  COM_MTD_STD  put_ReadingOrder, SDWORD
  COM_MTD_STD  get_AutoScaleFont, ptr VARIANT
  COM_MTD_STD  put_AutoScaleFont, VARIANT
  COM_MTD_STD  get_AutoText, ptr BOOL
  COM_MTD_STD  put_AutoText, BOOL
  COM_MTD_STD  get_NumberFormat, ptr BSTR
  COM_MTD_STD  put_NumberFormat, BSTR
  COM_MTD_STD  get_NumberFormatLinked, ptr BOOL
  COM_MTD_STD  put_NumberFormatLinked, BOOL
  COM_MTD_STD  get_NumberFormatLocal, ptr VARIANT
  COM_MTD_STD  put_NumberFormatLocal, VARIANT
  COM_MTD_STD  get_ShowLegendKey, ptr BOOL
  COM_MTD_STD  put_ShowLegendKey, BOOL
  COM_MTD_STD  get_Type, ptr VARIANT
  COM_MTD_STD  put_Type, VARIANT
  COM_MTD_STD  get_Position, ptr XlDataLabelPosition
  COM_MTD_STD  put_Position, XlDataLabelPosition
  COM_MTD_STD  get_ShowSeriesName, ptr BOOL
  COM_MTD_STD  put_ShowSeriesName, BOOL
  COM_MTD_STD  get_ShowCategoryName, ptr BOOL
  COM_MTD_STD  put_ShowCategoryName, BOOL
  COM_MTD_STD  get_ShowValue, ptr BOOL
  COM_MTD_STD  put_ShowValue, BOOL
  COM_MTD_STD  get_ShowPercentage, ptr BOOL
  COM_MTD_STD  put_ShowPercentage, BOOL
  COM_MTD_STD  get_ShowBubbleSize, ptr BOOL
  COM_MTD_STD  put_ShowBubbleSize, BOOL
  COM_MTD_STD  get_Separator, ptr VARIANT
  COM_MTD_STD  put_Separator, VARIANT
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Item, VARIANT, ptr ptr DataLabel
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG ILegendEntry, IDispatch, <000208BA-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  get_Font, ptr ptr Font
  COM_MTD_STD  get_Index, ptr SDWORD
  COM_MTD_STD  get_LegendKey, ptr ptr LegendKey
  COM_MTD_STD  Select, ptr VARIANT
  COM_MTD_STD  get_AutoScaleFont, ptr VARIANT
  COM_MTD_STD  put_AutoScaleFont, VARIANT
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  get_Height, ptr REAL8
COM_INTERFACE_END

COM_INTERFACE_BEG ILegendEntries, IDispatch, <000208BB-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Item, VARIANT, ptr ptr LegendEntry
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG ILegendKey, IDispatch, <000208BC-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  ClearFormats, ptr VARIANT
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_Fill, ptr ptr ChartFillFormat
  COM_MTD_STD  get_InvertIfNegative, ptr BOOL
  COM_MTD_STD  put_InvertIfNegative, BOOL
  COM_MTD_STD  get_MarkerBackgroundColor, ptr SDWORD
  COM_MTD_STD  put_MarkerBackgroundColor, SDWORD
  COM_MTD_STD  get_MarkerBackgroundColorIndex, ptr XlColorIndex
  COM_MTD_STD  put_MarkerBackgroundColorIndex, XlColorIndex
  COM_MTD_STD  get_MarkerForegroundColor, ptr SDWORD
  COM_MTD_STD  put_MarkerForegroundColor, SDWORD
  COM_MTD_STD  get_MarkerForegroundColorIndex, ptr XlColorIndex
  COM_MTD_STD  put_MarkerForegroundColorIndex, XlColorIndex
  COM_MTD_STD  get_MarkerSize, ptr SDWORD
  COM_MTD_STD  put_MarkerSize, SDWORD
  COM_MTD_STD  get_MarkerStyle, ptr XlMarkerStyle
  COM_MTD_STD  put_MarkerStyle, XlMarkerStyle
  COM_MTD_STD  get_PictureType, ptr SDWORD
  COM_MTD_STD  put_PictureType, SDWORD
  COM_MTD_STD  get_PictureUnit, ptr SDWORD
  COM_MTD_STD  put_PictureUnit, SDWORD
  COM_MTD_STD  Select, ptr VARIANT
  COM_MTD_STD  get_Smooth, ptr BOOL
  COM_MTD_STD  put_Smooth, BOOL
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  get_Shadow, ptr BOOL
  COM_MTD_STD  put_Shadow, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG ITrendlines, IDispatch, <000208BD-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Add_, XlTrendlineType, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr ptr Trendline
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Item, VARIANT, ptr ptr Trendline
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG ITrendline, IDispatch, <000208BE-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Backward, ptr SDWORD
  COM_MTD_STD  put_Backward, SDWORD
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  ClearFormats, ptr VARIANT
  COM_MTD_STD  get_DataLabel, ptr ptr DataLabel
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  get_DisplayEquation, ptr BOOL
  COM_MTD_STD  put_DisplayEquation, BOOL
  COM_MTD_STD  get_DisplayRSquared, ptr BOOL
  COM_MTD_STD  put_DisplayRSquared, BOOL
  COM_MTD_STD  get_Forward, ptr SDWORD
  COM_MTD_STD  put_Forward, SDWORD
  COM_MTD_STD  get_Index, ptr SDWORD
  COM_MTD_STD  get_Intercept, ptr REAL8
  COM_MTD_STD  put_Intercept, REAL8
  COM_MTD_STD  get_InterceptIsAuto, ptr BOOL
  COM_MTD_STD  put_InterceptIsAuto, BOOL
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_NameIsAuto, ptr BOOL
  COM_MTD_STD  put_NameIsAuto, BOOL
  COM_MTD_STD  get_Order, ptr SDWORD
  COM_MTD_STD  put_Order, SDWORD
  COM_MTD_STD  get_Period, ptr SDWORD
  COM_MTD_STD  put_Period, SDWORD
  COM_MTD_STD  Select, ptr VARIANT
  COM_MTD_STD  get_Type, ptr XlTrendlineType
  COM_MTD_STD  put_Type, XlTrendlineType
COM_INTERFACE_END

COM_INTERFACE_BEG ICorners, IDispatch, <000208C0-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  Select, ptr VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG ISeriesLines, IDispatch, <000208C1-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  Select, ptr VARIANT
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  Delete, ptr VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG IHiLoLines, IDispatch, <000208C2-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  Select, ptr VARIANT
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  Delete, ptr VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG IGridlines, IDispatch, <000208C3-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  Select, ptr VARIANT
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  Delete, ptr VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG IDropLines, IDispatch, <000208C4-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  Select, ptr VARIANT
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  Delete, ptr VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG ILeaderLines, IDispatch, <00024437-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  Delete
  COM_MTD_STD  Select
COM_INTERFACE_END

COM_INTERFACE_BEG IUpBars, IDispatch, <000208C5-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  Select, ptr VARIANT
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_Fill, ptr ptr ChartFillFormat
COM_INTERFACE_END

COM_INTERFACE_BEG IDownBars, IDispatch, <000208C6-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  Select, ptr VARIANT
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_Fill, ptr ptr ChartFillFormat
COM_INTERFACE_END

COM_INTERFACE_BEG IFloor, IDispatch, <000208C7-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  Select, ptr VARIANT
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  ClearFormats, ptr VARIANT
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_Fill, ptr ptr ChartFillFormat
  COM_MTD_STD  get_PictureType, ptr VARIANT
  COM_MTD_STD  put_PictureType, VARIANT
  COM_MTD_STD  Paste
COM_INTERFACE_END

COM_INTERFACE_BEG IWalls, IDispatch, <000208C8-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  Select, ptr VARIANT
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  ClearFormats, ptr VARIANT
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_Fill, ptr ptr ChartFillFormat
  COM_MTD_STD  get_PictureType, ptr VARIANT
  COM_MTD_STD  put_PictureType, VARIANT
  COM_MTD_STD  Paste
  COM_MTD_STD  get_PictureUnit, ptr VARIANT
  COM_MTD_STD  put_PictureUnit, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG ITickLabels, IDispatch, <000208C9-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  get_Font, ptr ptr Font
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  get_NumberFormat, ptr BSTR
  COM_MTD_STD  put_NumberFormat, BSTR
  COM_MTD_STD  get_NumberFormatLinked, ptr BOOL
  COM_MTD_STD  put_NumberFormatLinked, BOOL
  COM_MTD_STD  get_NumberFormatLocal, ptr VARIANT
  COM_MTD_STD  put_NumberFormatLocal, VARIANT
  COM_MTD_STD  get_Orientation, ptr XlTickLabelOrientation
  COM_MTD_STD  put_Orientation, XlTickLabelOrientation
  COM_MTD_STD  Select, ptr VARIANT
  COM_MTD_STD  get_ReadingOrder, ptr SDWORD
  COM_MTD_STD  put_ReadingOrder, SDWORD
  COM_MTD_STD  get_AutoScaleFont, ptr VARIANT
  COM_MTD_STD  put_AutoScaleFont, VARIANT
  COM_MTD_STD  get_Depth, ptr SDWORD
  COM_MTD_STD  get_Offset, ptr SDWORD
  COM_MTD_STD  put_Offset, SDWORD
  COM_MTD_STD  get_Alignment, ptr SDWORD
  COM_MTD_STD  put_Alignment, SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG IPlotArea, IDispatch, <000208CB-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  Select, ptr VARIANT
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  ClearFormats, ptr VARIANT
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_Fill, ptr ptr ChartFillFormat
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_InsideLeft, ptr REAL8
  COM_MTD_STD  get_InsideTop, ptr REAL8
  COM_MTD_STD  get_InsideWidth, ptr REAL8
  COM_MTD_STD  get_InsideHeight, ptr REAL8
COM_INTERFACE_END

COM_INTERFACE_BEG IChartArea, IDispatch, <000208CC-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  Select, ptr VARIANT
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  Clear, ptr VARIANT
  COM_MTD_STD  ClearContents, ptr VARIANT
  COM_MTD_STD  Copy, ptr VARIANT
  COM_MTD_STD  get_Font, ptr ptr Font
  COM_MTD_STD  get_Shadow, ptr BOOL
  COM_MTD_STD  put_Shadow, BOOL
  COM_MTD_STD  ClearFormats, ptr VARIANT
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_Fill, ptr ptr ChartFillFormat
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_AutoScaleFont, ptr VARIANT
  COM_MTD_STD  put_AutoScaleFont, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG ILegend, IDispatch, <000208CD-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  Select, ptr VARIANT
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  get_Font, ptr ptr Font
  COM_MTD_STD  LegendEntries, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  get_Position, ptr XlLegendPosition
  COM_MTD_STD  put_Position, XlLegendPosition
  COM_MTD_STD  get_Shadow, ptr BOOL
  COM_MTD_STD  put_Shadow, BOOL
  COM_MTD_STD  Clear, ptr VARIANT
  COM_MTD_STD  get_Height, ptr REAL8
  COM_MTD_STD  put_Height, REAL8
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_Fill, ptr ptr ChartFillFormat
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  get_Width, ptr REAL8
  COM_MTD_STD  put_Width, REAL8
  COM_MTD_STD  get_AutoScaleFont, ptr VARIANT
  COM_MTD_STD  put_AutoScaleFont, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG IErrorBars, IDispatch, <000208CE-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  Select, ptr VARIANT
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  ClearFormats, ptr VARIANT
  COM_MTD_STD  get_EndStyle, ptr XlEndStyleCap
  COM_MTD_STD  put_EndStyle, XlEndStyleCap
COM_INTERFACE_END

COM_INTERFACE_BEG IDataTable, IDispatch, <00020843-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_ShowLegendKey, ptr BOOL
  COM_MTD_STD  put_ShowLegendKey, BOOL
  COM_MTD_STD  get_HasBorderHorizontal, ptr BOOL
  COM_MTD_STD  put_HasBorderHorizontal, BOOL
  COM_MTD_STD  get_HasBorderVertical, ptr BOOL
  COM_MTD_STD  put_HasBorderVertical, BOOL
  COM_MTD_STD  get_HasBorderOutline, ptr BOOL
  COM_MTD_STD  put_HasBorderOutline, BOOL
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  get_Font, ptr ptr Font
  COM_MTD_STD  Select
  COM_MTD_STD  Delete
  COM_MTD_STD  get_AutoScaleFont, ptr VARIANT
  COM_MTD_STD  put_AutoScaleFont, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG IPhonetic, IDispatch, <00024438-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_CharacterType, ptr SDWORD
  COM_MTD_STD  put_CharacterType, SDWORD
  COM_MTD_STD  get_Alignment, ptr SDWORD
  COM_MTD_STD  put_Alignment, SDWORD
  COM_MTD_STD  get_Font, ptr ptr Font
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG IShape, IDispatch, <00024439-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Apply
  COM_MTD_STD  Delete
  COM_MTD_STD  Duplicate, ptr ptr Shape
  COM_MTD_STD  Flip;, MsoFlipCmd
  COM_MTD_STD  IncrementLeft, REAL4
  COM_MTD_STD  IncrementRotation, REAL4
  COM_MTD_STD  IncrementTop, REAL4
  COM_MTD_STD  PickUp
  COM_MTD_STD  RerouteConnections
  COM_MTD_STD  ScaleHeight, REAL4, MsoTriState, VARIANT
  COM_MTD_STD  ScaleWidth, REAL4, MsoTriState, VARIANT
  COM_MTD_STD  Select, VARIANT
  COM_MTD_STD  SetShapesDefaultProperties
  COM_MTD_STD  Ungroup, ptr ptr ShapeRange
  COM_MTD_STD  ZOrder;, MsoZOrderCmd
  COM_MTD_STD  get_Adjustments, ptr ptr Adjustments
  COM_MTD_STD  get_TextFrame, ptr ptr TextFrame
  COM_MTD_STD  get_AutoShapeType, ptr MsoAutoShapeType
  COM_MTD_STD  put_AutoShapeType, MsoAutoShapeType
  COM_MTD_STD  get_Callout, ptr ptr CalloutFormat
  COM_MTD_STD  get_ConnectionSiteCount, ptr SDWORD
  COM_MTD_STD  get_Connector, ptr MsoTriState
  COM_MTD_STD  get_ConnectorFormat, ptr ptr ConnectorFormat
  COM_MTD_STD  get_Fill, ptr ptr FillFormat
  COM_MTD_STD  get_GroupItems, ptr ptr GroupShapes
  COM_MTD_STD  get_Height, ptr REAL4
  COM_MTD_STD  put_Height, REAL4
  COM_MTD_STD  get_HorizontalFlip, ptr MsoTriState
  COM_MTD_STD  get_Left, ptr REAL4
  COM_MTD_STD  put_Left, REAL4
  COM_MTD_STD  get_Line, ptr ptr LineFormat
  COM_MTD_STD  get_LockAspectRatio, ptr MsoTriState
  COM_MTD_STD  put_LockAspectRatio, MsoTriState
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_Nodes, ptr ptr ShapeNodes
  COM_MTD_STD  get_Rotation, ptr REAL4
  COM_MTD_STD  put_Rotation, REAL4
  COM_MTD_STD  get_PictureFormat, ptr ptr PictureFormat
  COM_MTD_STD  get_Shadow, ptr ptr ShadowFormat
  COM_MTD_STD  get_TextEffect, ptr ptr TextEffectFormat
  COM_MTD_STD  get_ThreeD, ptr ptr ThreeDFormat
  COM_MTD_STD  get_Top, ptr REAL4
  COM_MTD_STD  put_Top, REAL4
  COM_MTD_STD  get_Type, ptr MsoShapeType
  COM_MTD_STD  get_VerticalFlip, ptr MsoTriState
  COM_MTD_STD  get_Vertices, ptr VARIANT
  COM_MTD_STD  get_Visible, ptr MsoTriState
  COM_MTD_STD  put_Visible, MsoTriState
  COM_MTD_STD  get_Width, ptr REAL4
  COM_MTD_STD  put_Width, REAL4
  COM_MTD_STD  get_ZOrderPosition, ptr SDWORD
  COM_MTD_STD  get_Hyperlink, ptr ptr Hyperlink
  COM_MTD_STD  get_BlackWhiteMode, ptr MsoBlackWhiteMode
  COM_MTD_STD  put_BlackWhiteMode, MsoBlackWhiteMode
  COM_MTD_STD  get_DrawingObject, ptr LPDISPATCH
  COM_MTD_STD  get_OnAction, ptr BSTR
  COM_MTD_STD  put_OnAction, BSTR
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  get_TopLeftCell, ptr ptr Range
  COM_MTD_STD  get_BottomRightCell, ptr ptr Range
  COM_MTD_STD  get_Placement, ptr XlPlacement
  COM_MTD_STD  put_Placement, XlPlacement
  COM_MTD_STD  Copy
  COM_MTD_STD  Cut
  COM_MTD_STD  CopyPicture, VARIANT, VARIANT
  COM_MTD_STD  get_ControlFormat, ptr ptr ControlFormat
  COM_MTD_STD  get_LinkFormat, ptr ptr LinkFormat
  COM_MTD_STD  get_OLEFormat, ptr ptr OLEFormat
  COM_MTD_STD  get_FormControlType, ptr XlFormControl
  COM_MTD_STD  get_AlternativeText, ptr BSTR
  COM_MTD_STD  put_AlternativeText, BSTR
  COM_MTD_STD  get_Script, ptr ptr Script
  COM_MTD_STD  get_DiagramNode, ptr ptr DiagramNode
  COM_MTD_STD  get_HasDiagramNode, ptr MsoTriState
  COM_MTD_STD  get_Diagram, ptr ptr Diagram
  COM_MTD_STD  get_HasDiagram, ptr MsoTriState
  COM_MTD_STD  get_Child, ptr MsoTriState
  COM_MTD_STD  get_ParentGroup, ptr ptr Shape
  COM_MTD_STD  get_CanvasItems, ptr ptr CanvasShapes
  COM_MTD_STD  get_ID, ptr SDWORD
  COM_MTD_STD  CanvasCropLeft, REAL4
  COM_MTD_STD  CanvasCropTop, REAL4
  COM_MTD_STD  CanvasCropRight, REAL4
  COM_MTD_STD  CanvasCropBottom, REAL4
COM_INTERFACE_END

COM_INTERFACE_BEG IShapes, IDispatch, <0002443A-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Item, VARIANT, ptr ptr Shape
  COM_MTD_STD  _Default, VARIANT, ptr ptr Shape
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  AddCallout, MsoCalloutType, REAL4, REAL4, REAL4, REAL4, ptr ptr Shape
  COM_MTD_STD  AddConnector, MsoConnectorType, REAL4, REAL4, REAL4, REAL4, ptr ptr Shape
  COM_MTD_STD  AddCurve, VARIANT, ptr ptr Shape
  COM_MTD_STD  AddLabel, MsoTextOrientation, REAL4, REAL4, REAL4, REAL4, ptr ptr Shape
  COM_MTD_STD  AddLine, REAL4, REAL4, REAL4, REAL4, ptr ptr Shape
  COM_MTD_STD  AddPicture, BSTR, MsoTriState, MsoTriState, REAL4, REAL4, REAL4, REAL4, ptr ptr Shape
  COM_MTD_STD  AddPolyline, VARIANT, ptr ptr Shape
  COM_MTD_STD  AddShape, MsoAutoShapeType, REAL4, REAL4, REAL4, REAL4, ptr ptr Shape
  COM_MTD_STD  AddTextEffect, MsoPresetTextEffect, BSTR, BSTR, REAL4, MsoTriState, MsoTriState, REAL4, REAL4, ptr ptr Shape
  COM_MTD_STD  AddTextbox, MsoTextOrientation, REAL4, REAL4, REAL4, REAL4, ptr ptr Shape
  COM_MTD_STD  BuildFreeform, MsoEditingType, REAL4, REAL4, ptr ptr FreeformBuilder
  COM_MTD_STD  get_Range, VARIANT, ptr ptr ShapeRange
  COM_MTD_STD  SelectAll
  COM_MTD_STD  AddFormControl, XlFormControl, SDWORD, SDWORD, SDWORD, SDWORD, ptr ptr Shape
  COM_MTD_STD  AddOLEObject, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr ptr Shape
  COM_MTD_STD  AddDiagram, MsoDiagramType, REAL4, REAL4, REAL4, REAL4, ptr ptr Shape
  COM_MTD_STD  AddCanvas, REAL4, REAL4, REAL4, REAL4, ptr ptr Shape
COM_INTERFACE_END

COM_INTERFACE_BEG IShapeRange, IDispatch, <0002443B-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Item, VARIANT, ptr ptr Shape
  COM_MTD_STD  _Default, VARIANT, ptr ptr Shape
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  Align_, MsoAlignCmd, MsoTriState
  COM_MTD_STD  Apply
  COM_MTD_STD  Delete
  COM_MTD_STD  Distribute, MsoDistributeCmd, MsoTriState
  COM_MTD_STD  Duplicate, ptr ptr ShapeRange
  COM_MTD_STD  Flip, MsoFlipCmd
  COM_MTD_STD  IncrementLeft, REAL4
  COM_MTD_STD  IncrementRotation, REAL4
  COM_MTD_STD  IncrementTop, REAL4
  COM_MTD_STD  Group_, ptr ptr Shape
  COM_MTD_STD  PickUp
  COM_MTD_STD  RerouteConnections
  COM_MTD_STD  Regroup, ptr ptr Shape
  COM_MTD_STD  ScaleHeight, REAL4, MsoTriState, VARIANT
  COM_MTD_STD  ScaleWidth, REAL4, MsoTriState, VARIANT
  COM_MTD_STD  Select, VARIANT
  COM_MTD_STD  SetShapesDefaultProperties
  COM_MTD_STD  Ungroup, ptr ptr ShapeRange
  COM_MTD_STD  ZOrder, MsoZOrderCmd
  COM_MTD_STD  get_Adjustments, ptr ptr Adjustments
  COM_MTD_STD  get_TextFrame, ptr ptr TextFrame
  COM_MTD_STD  get_AutoShapeType, ptr MsoAutoShapeType
  COM_MTD_STD  put_AutoShapeType, MsoAutoShapeType
  COM_MTD_STD  get_Callout, ptr ptr CalloutFormat
  COM_MTD_STD  get_ConnectionSiteCount, ptr SDWORD
  COM_MTD_STD  get_Connector, ptr MsoTriState
  COM_MTD_STD  get_ConnectorFormat, ptr ptr ConnectorFormat
  COM_MTD_STD  get_Fill, ptr ptr FillFormat
  COM_MTD_STD  get_GroupItems, ptr ptr GroupShapes
  COM_MTD_STD  get_Height, ptr REAL4
  COM_MTD_STD  put_Height, REAL4
  COM_MTD_STD  get_HorizontalFlip, ptr MsoTriState
  COM_MTD_STD  get_Left, ptr REAL4
  COM_MTD_STD  put_Left, REAL4
  COM_MTD_STD  get_Line, ptr ptr LineFormat
  COM_MTD_STD  get_LockAspectRatio, ptr MsoTriState
  COM_MTD_STD  put_LockAspectRatio, MsoTriState
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_Nodes, ptr ptr ShapeNodes
  COM_MTD_STD  get_Rotation, ptr REAL4
  COM_MTD_STD  put_Rotation, REAL4
  COM_MTD_STD  get_PictureFormat, ptr ptr PictureFormat
  COM_MTD_STD  get_Shadow, ptr ptr ShadowFormat
  COM_MTD_STD  get_TextEffect, ptr ptr TextEffectFormat
  COM_MTD_STD  get_ThreeD, ptr ptr ThreeDFormat
  COM_MTD_STD  get_Top, ptr REAL4
  COM_MTD_STD  put_Top, REAL4
  COM_MTD_STD  get_Type, ptr MsoShapeType
  COM_MTD_STD  get_VerticalFlip, ptr MsoTriState
  COM_MTD_STD  get_Vertices, ptr VARIANT
  COM_MTD_STD  get_Visible, ptr MsoTriState
  COM_MTD_STD  put_Visible, MsoTriState
  COM_MTD_STD  get_Width, ptr REAL4
  COM_MTD_STD  put_Width, REAL4
  COM_MTD_STD  get_ZOrderPosition, ptr SDWORD
  COM_MTD_STD  get_BlackWhiteMode, ptr MsoBlackWhiteMode
  COM_MTD_STD  put_BlackWhiteMode, MsoBlackWhiteMode
  COM_MTD_STD  get_AlternativeText, ptr BSTR
  COM_MTD_STD  put_AlternativeText, BSTR
  COM_MTD_STD  get_DiagramNode, ptr ptr DiagramNode
  COM_MTD_STD  get_HasDiagramNode, ptr MsoTriState
  COM_MTD_STD  get_Diagram, ptr ptr Diagram
  COM_MTD_STD  get_HasDiagram, ptr MsoTriState
  COM_MTD_STD  get_Child, ptr MsoTriState
  COM_MTD_STD  get_ParentGroup, ptr ptr Shape
  COM_MTD_STD  get_CanvasItems, ptr ptr CanvasShapes
  COM_MTD_STD  get_ID, ptr SDWORD
  COM_MTD_STD  CanvasCropLeft, REAL4
  COM_MTD_STD  CanvasCropTop, REAL4
  COM_MTD_STD  CanvasCropRight, REAL4
  COM_MTD_STD  CanvasCropBottom, REAL4
COM_INTERFACE_END

COM_INTERFACE_BEG IGroupShapes, IDispatch, <0002443C-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Item, VARIANT, ptr ptr Shape
  COM_MTD_STD  _Default, VARIANT, ptr ptr Shape
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  get_Range, VARIANT, ptr ptr ShapeRange
COM_INTERFACE_END

COM_INTERFACE_BEG ITextFrame, IDispatch, <0002443D-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_MarginBottom, ptr REAL4
  COM_MTD_STD  put_MarginBottom, REAL4
  COM_MTD_STD  get_MarginLeft, ptr REAL4
  COM_MTD_STD  put_MarginLeft, REAL4
  COM_MTD_STD  get_MarginRight, ptr REAL4
  COM_MTD_STD  put_MarginRight, REAL4
  COM_MTD_STD  get_MarginTop, ptr REAL4
  COM_MTD_STD  put_MarginTop, REAL4
  COM_MTD_STD  get_Orientation, ptr MsoTextOrientation
  COM_MTD_STD  put_Orientation, MsoTextOrientation
  COM_MTD_STD  Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_STD  get_HorizontalAlignment, ptr XlHAlign
  COM_MTD_STD  put_HorizontalAlignment, XlHAlign
  COM_MTD_STD  get_VerticalAlignment, ptr XlVAlign
  COM_MTD_STD  put_VerticalAlignment, XlVAlign
  COM_MTD_STD  get_AutoSize, ptr BOOL
  COM_MTD_STD  put_AutoSize, BOOL
  COM_MTD_STD  get_ReadingOrder, ptr SDWORD
  COM_MTD_STD  put_ReadingOrder, SDWORD
  COM_MTD_STD  get_AutoMargins, ptr BOOL
  COM_MTD_STD  put_AutoMargins, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG IConnectorFormat, IDispatch, <0002443E-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  BeginConnect, ptr Shape, SDWORD
  COM_MTD_STD  BeginDisconnect
  COM_MTD_STD  EndConnect, ptr Shape, SDWORD
  COM_MTD_STD  EndDisconnect
  COM_MTD_STD  get_BeginConnected, ptr MsoTriState
  COM_MTD_STD  get_BeginConnectedShape, ptr ptr Shape
  COM_MTD_STD  get_BeginConnectionSite, ptr SDWORD
  COM_MTD_STD  get_EndConnected, ptr MsoTriState
  COM_MTD_STD  get_EndConnectedShape, ptr ptr Shape
  COM_MTD_STD  get_EndConnectionSite, ptr SDWORD
  COM_MTD_STD  get_Type, ptr MsoConnectorType
  COM_MTD_STD  put_Type, MsoConnectorType
COM_INTERFACE_END

COM_INTERFACE_BEG IFreeformBuilder, IDispatch, <0002443F-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  AddNodes, MsoSegmentType, MsoEditingType, REAL4, REAL4, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_STD  ConvertToShape, ptr ptr Shape
COM_INTERFACE_END

COM_INTERFACE_BEG IControlFormat, IDispatch, <00024440-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  AddItem, BSTR, VARIANT
  COM_MTD_STD  RemoveAllItems
  COM_MTD_STD  RemoveItem, SDWORD, VARIANT
  COM_MTD_STD  get_DropDownLines, ptr SDWORD
  COM_MTD_STD  put_DropDownLines, SDWORD
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_LargeChange, ptr SDWORD
  COM_MTD_STD  put_LargeChange, SDWORD
  COM_MTD_STD  get_LinkedCell, ptr BSTR
  COM_MTD_STD  put_LinkedCell, BSTR
  COM_MTD_STD  List, VARIANT, ptr VARIANT
  COM_MTD_STD  get_ListCount, ptr SDWORD
  COM_MTD_STD  put_ListCount, SDWORD
  COM_MTD_STD  get_ListFillRange, ptr BSTR
  COM_MTD_STD  put_ListFillRange, BSTR
  COM_MTD_STD  get_ListIndex, ptr SDWORD
  COM_MTD_STD  put_ListIndex, SDWORD
  COM_MTD_STD  get_LockedText, ptr BOOL
  COM_MTD_STD  put_LockedText, BOOL
  COM_MTD_STD  get_Max, ptr SDWORD
  COM_MTD_STD  put_Max, SDWORD
  COM_MTD_STD  get_Min, ptr SDWORD
  COM_MTD_STD  put_Min, SDWORD
  COM_MTD_STD  get_MultiSelect, ptr SDWORD
  COM_MTD_STD  put_MultiSelect, SDWORD
  COM_MTD_STD  get_PrintObject, ptr BOOL
  COM_MTD_STD  put_PrintObject, BOOL
  COM_MTD_STD  get_SmallChange, ptr SDWORD
  COM_MTD_STD  put_SmallChange, SDWORD
  COM_MTD_STD  get__Default, ptr SDWORD
  COM_MTD_STD  put__Default, SDWORD
  COM_MTD_STD  get_Value, ptr SDWORD
  COM_MTD_STD  put_Value, SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG IOLEFormat, IDispatch, <00024441-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Activate
  COM_MTD_STD  get_Object, ptr LPDISPATCH
  COM_MTD_STD  get_progID, ptr BSTR
  COM_MTD_STD  Verb, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG ILinkFormat, IDispatch, <00024442-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_AutoUpdate, ptr BOOL
  COM_MTD_STD  put_AutoUpdate, BOOL
  COM_MTD_STD  get_Locked, ptr BOOL
  COM_MTD_STD  put_Locked, BOOL
  COM_MTD_STD  Update
COM_INTERFACE_END

COM_INTERFACE_BEG IPublishObjects, IDispatch, <00024443-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Add_, XlSourceType, BSTR, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr ptr PublishObject
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  get_Item, VARIANT, ptr ptr PublishObject
  COM_MTD_STD  get__Default, VARIANT, ptr ptr PublishObject
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  Delete
  COM_MTD_STD  Publish
COM_INTERFACE_END

COM_INTERFACE_BEG PublishObject, IDispatch, <00024444-0000-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Delete
  COM_MTD_STD  Publish, VARIANT
  COM_MTD_STD  get_DivID, ptr BSTR
  COM_MTD_STD  get_Sheet, ptr BSTR
  COM_MTD_STD  get_SourceType, ptr XlSourceType
  COM_MTD_STD  get_Source, ptr BSTR
  COM_MTD_STD  get_HtmlType, ptr XlHtmlType
  COM_MTD_STD  put_HtmlType, XlHtmlType
  COM_MTD_STD  get_Title, ptr BSTR
  COM_MTD_STD  put_Title, BSTR
  COM_MTD_STD  get_Filename, ptr BSTR
  COM_MTD_STD  put_Filename, BSTR
  COM_MTD_STD  get_AutoRepublish, ptr BOOL
  COM_MTD_STD  put_AutoRepublish, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG IOLEDBError, IDispatch, <00024445-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_SqlState, ptr BSTR
  COM_MTD_STD  get_ErrorString, ptr BSTR
  COM_MTD_STD  get_Native, ptr SDWORD
  COM_MTD_STD  get_Number, ptr SDWORD
  COM_MTD_STD  get_Stage, ptr SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG IOLEDBErrors, IDispatch, <00024446-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Item, SDWORD, ptr ptr OLEDBError
  COM_MTD_STD  get__Default, SDWORD, ptr ptr OLEDBError
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IPhonetics, IDispatch, <00024447-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  get_Start, ptr SDWORD
  COM_MTD_STD  get_Length, ptr SDWORD
  COM_MTD_STD  get_Visible, ptr BOOL
  COM_MTD_STD  put_Visible, BOOL
  COM_MTD_STD  get_CharacterType, ptr SDWORD
  COM_MTD_STD  put_CharacterType, SDWORD
  COM_MTD_STD  get_Alignment, ptr SDWORD
  COM_MTD_STD  put_Alignment, SDWORD
  COM_MTD_STD  get_Font, ptr ptr Font
  COM_MTD_STD  get_Item, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  Delete
  COM_MTD_STD  Add_, SDWORD, SDWORD, BSTR
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
  COM_MTD_STD  get__Default, SDWORD, ptr LPDISPATCH
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG DefaultWebOptions, IDispatch, <00024448-0000-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_RelyOnCSS, ptr BOOL
  COM_MTD_STD  put_RelyOnCSS, BOOL
  COM_MTD_STD  get_SaveHiddenData, ptr BOOL
  COM_MTD_STD  put_SaveHiddenData, BOOL
  COM_MTD_STD  get_LoadPictures, ptr BOOL
  COM_MTD_STD  put_LoadPictures, BOOL
  COM_MTD_STD  get_OrganizeInFolder, ptr BOOL
  COM_MTD_STD  put_OrganizeInFolder, BOOL
  COM_MTD_STD  get_UpdateLinksOnSave, ptr BOOL
  COM_MTD_STD  put_UpdateLinksOnSave, BOOL
  COM_MTD_STD  get_UseLongFileNames, ptr BOOL
  COM_MTD_STD  put_UseLongFileNames, BOOL
  COM_MTD_STD  get_CheckIfOfficeIsHTMLEditor, ptr BOOL
  COM_MTD_STD  put_CheckIfOfficeIsHTMLEditor, BOOL
  COM_MTD_STD  get_DownloadComponents, ptr BOOL
  COM_MTD_STD  put_DownloadComponents, BOOL
  COM_MTD_STD  get_RelyOnVML, ptr BOOL
  COM_MTD_STD  put_RelyOnVML, BOOL
  COM_MTD_STD  get_AllowPNG, ptr BOOL
  COM_MTD_STD  put_AllowPNG, BOOL
  COM_MTD_STD  get_ScreenSize, ptr MsoScreenSize
  COM_MTD_STD  put_ScreenSize, MsoScreenSize
  COM_MTD_STD  get_PixelsPerInch, ptr SDWORD
  COM_MTD_STD  put_PixelsPerInch, SDWORD
  COM_MTD_STD  get_LocationOfComponents, ptr BSTR
  COM_MTD_STD  put_LocationOfComponents, BSTR
  COM_MTD_STD  get_Encoding, ptr MsoEncoding
  COM_MTD_STD  put_Encoding, MsoEncoding
  COM_MTD_STD  get_AlwaysSaveInDefaultEncoding, ptr BOOL
  COM_MTD_STD  put_AlwaysSaveInDefaultEncoding, BOOL
  COM_MTD_STD  get_Fonts, ptr ptr WebPageFonts
  COM_MTD_STD  get_FolderSuffix, ptr BSTR
  COM_MTD_STD  get_TargetBrowser, ptr MsoTargetBrowser
  COM_MTD_STD  put_TargetBrowser, MsoTargetBrowser
  COM_MTD_STD  get_SaveNewWebPagesAsWebArchives, ptr BOOL
  COM_MTD_STD  put_SaveNewWebPagesAsWebArchives, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG WebOptions, IDispatch, <00024449-0000-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_RelyOnCSS, ptr BOOL
  COM_MTD_STD  put_RelyOnCSS, BOOL
  COM_MTD_STD  get_OrganizeInFolder, ptr BOOL
  COM_MTD_STD  put_OrganizeInFolder, BOOL
  COM_MTD_STD  get_UseLongFileNames, ptr BOOL
  COM_MTD_STD  put_UseLongFileNames, BOOL
  COM_MTD_STD  get_DownloadComponents, ptr BOOL
  COM_MTD_STD  put_DownloadComponents, BOOL
  COM_MTD_STD  get_RelyOnVML, ptr BOOL
  COM_MTD_STD  put_RelyOnVML, BOOL
  COM_MTD_STD  get_AllowPNG, ptr BOOL
  COM_MTD_STD  put_AllowPNG, BOOL
  COM_MTD_STD  get_ScreenSize, ptr MsoScreenSize
  COM_MTD_STD  put_ScreenSize, MsoScreenSize
  COM_MTD_STD  get_PixelsPerInch, ptr SDWORD
  COM_MTD_STD  put_PixelsPerInch, SDWORD
  COM_MTD_STD  get_LocationOfComponents, ptr BSTR
  COM_MTD_STD  put_LocationOfComponents, BSTR
  COM_MTD_STD  get_Encoding, ptr MsoEncoding
  COM_MTD_STD  put_Encoding, MsoEncoding
  COM_MTD_STD  get_FolderSuffix, ptr BSTR
  COM_MTD_STD  UseDefaultFolderSuffix
  COM_MTD_STD  get_TargetBrowser, ptr MsoTargetBrowser
  COM_MTD_STD  put_TargetBrowser, MsoTargetBrowser
COM_INTERFACE_END

COM_INTERFACE_BEG IPivotLayout, IDispatch, <0002444A-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_ColumnFields, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  get_DataFields, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  get_PageFields, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  get_RowFields, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  get_HiddenFields, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  get_VisibleFields, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  get_PivotFields, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  get_CubeFields, ptr ptr CubeFields
  COM_MTD_STD  get_PivotCache, ptr ptr PivotCache
  COM_MTD_STD  get_PivotTable, ptr ptr PivotTable
  COM_MTD_STD  get_InnerDetail, ptr BSTR
  COM_MTD_STD  put_InnerDetail, BSTR
  COM_MTD_STD  AddFields, VARIANT, VARIANT, VARIANT, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG TreeviewControl, IDispatch, <0002444B-0000-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Hidden, ptr VARIANT
  COM_MTD_STD  put_Hidden, VARIANT
  COM_MTD_STD  get_Drilled, ptr VARIANT
  COM_MTD_STD  put_Drilled, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG CubeField, IDispatch, <0002444C-0000-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_CubeFieldType, ptr XlCubeFieldType
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  get_Value, ptr BSTR
  COM_MTD_STD  get_Orientation, ptr XlPivotFieldOrientation
  COM_MTD_STD  put_Orientation, XlPivotFieldOrientation
  COM_MTD_STD  get_Position, ptr SDWORD
  COM_MTD_STD  put_Position, SDWORD
  COM_MTD_STD  get_TreeviewControl, ptr ptr TreeviewControl
  COM_MTD_STD  get_DragToColumn, ptr BOOL
  COM_MTD_STD  put_DragToColumn, BOOL
  COM_MTD_STD  get_DragToHide, ptr BOOL
  COM_MTD_STD  put_DragToHide, BOOL
  COM_MTD_STD  get_DragToPage, ptr BOOL
  COM_MTD_STD  put_DragToPage, BOOL
  COM_MTD_STD  get_DragToRow, ptr BOOL
  COM_MTD_STD  put_DragToRow, BOOL
  COM_MTD_STD  get_DragToData, ptr BOOL
  COM_MTD_STD  put_DragToData, BOOL
  COM_MTD_STD  get_HiddenLevels, ptr SDWORD
  COM_MTD_STD  put_HiddenLevels, SDWORD
  COM_MTD_STD  get_HasMemberProperties, ptr BOOL
  COM_MTD_STD  get_LayoutForm, ptr XlLayoutFormType
  COM_MTD_STD  put_LayoutForm, XlLayoutFormType
  COM_MTD_STD  get_PivotFields, ptr ptr PivotFields
  COM_MTD_STD  AddMemberPropertyField, BSTR, VARIANT
  COM_MTD_STD  get_EnableMultiplePageItems, ptr BOOL
  COM_MTD_STD  put_EnableMultiplePageItems, BOOL
  COM_MTD_STD  get_LayoutSubtotalLocation, ptr XlSubtototalLocationType
  COM_MTD_STD  put_LayoutSubtotalLocation, XlSubtototalLocationType
  COM_MTD_STD  get_ShowInFieldList, ptr BOOL
  COM_MTD_STD  put_ShowInFieldList, BOOL
  COM_MTD_STD  Delete
COM_INTERFACE_END

COM_INTERFACE_BEG CubeFields, IDispatch, <0002444D-0000-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  get_Item, VARIANT, ptr ptr CubeField
  COM_MTD_STD  get__Default, VARIANT, ptr ptr CubeField
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  AddSet, BSTR, BSTR, ptr ptr CubeField
COM_INTERFACE_END

COM_INTERFACE_BEG IDisplayUnitLabel, IDispatch, <0002084C-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  Select, ptr VARIANT
  COM_MTD_STD  get_Border, ptr ptr Border
  COM_MTD_STD  Delete, ptr VARIANT
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  get_Fill, ptr ptr ChartFillFormat
  COM_MTD_STD  get_Caption, ptr BSTR
  COM_MTD_STD  put_Caption, BSTR
  COM_MTD_STD  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_STD  get_Font, ptr ptr Font
  COM_MTD_STD  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_STD  put_HorizontalAlignment, VARIANT
  COM_MTD_STD  get_Left, ptr REAL8
  COM_MTD_STD  put_Left, REAL8
  COM_MTD_STD  get_Orientation, ptr VARIANT
  COM_MTD_STD  put_Orientation, VARIANT
  COM_MTD_STD  get_Shadow, ptr BOOL
  COM_MTD_STD  put_Shadow, BOOL
  COM_MTD_STD  get_Text, ptr BSTR
  COM_MTD_STD  put_Text, BSTR
  COM_MTD_STD  get_Top, ptr REAL8
  COM_MTD_STD  put_Top, REAL8
  COM_MTD_STD  get_VerticalAlignment, ptr VARIANT
  COM_MTD_STD  put_VerticalAlignment, VARIANT
  COM_MTD_STD  get_ReadingOrder, ptr SDWORD
  COM_MTD_STD  put_ReadingOrder, SDWORD
  COM_MTD_STD  get_AutoScaleFont, ptr VARIANT
  COM_MTD_STD  put_AutoScaleFont, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG ICellFormat, IDispatch, <00024450-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Borders, ptr ptr Borders
  COM_MTD_STD  putref_Borders, ptr Borders
  COM_MTD_STD  get_Font, ptr ptr Font
  COM_MTD_STD  putref_Font, ptr Font
  COM_MTD_STD  get_Interior, ptr ptr Interior
  COM_MTD_STD  putref_Interior, ptr Interior
  COM_MTD_STD  get_NumberFormat, SDWORD, ptr VARIANT
  COM_MTD_STD  put_NumberFormat, SDWORD, VARIANT
  COM_MTD_STD  get_NumberFormatLocal, ptr VARIANT
  COM_MTD_STD  put_NumberFormatLocal, VARIANT
  COM_MTD_STD  get_AddIndent, ptr VARIANT
  COM_MTD_STD  put_AddIndent, VARIANT
  COM_MTD_STD  get_IndentLevel, ptr VARIANT
  COM_MTD_STD  put_IndentLevel, VARIANT
  COM_MTD_STD  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_STD  put_HorizontalAlignment, VARIANT
  COM_MTD_STD  get_VerticalAlignment, ptr VARIANT
  COM_MTD_STD  put_VerticalAlignment, VARIANT
  COM_MTD_STD  get_Orientation, ptr VARIANT
  COM_MTD_STD  put_Orientation, VARIANT
  COM_MTD_STD  get_ShrinkToFit, ptr VARIANT
  COM_MTD_STD  put_ShrinkToFit, VARIANT
  COM_MTD_STD  get_WrapText, ptr VARIANT
  COM_MTD_STD  put_WrapText, VARIANT
  COM_MTD_STD  get_Locked, ptr VARIANT
  COM_MTD_STD  put_Locked, VARIANT
  COM_MTD_STD  get_FormulaHidden, ptr VARIANT
  COM_MTD_STD  put_FormulaHidden, VARIANT
  COM_MTD_STD  get_MergeCells, ptr VARIANT
  COM_MTD_STD  put_MergeCells, VARIANT
  COM_MTD_STD  Clear
COM_INTERFACE_END

COM_INTERFACE_BEG IUsedObjects, IDispatch, <00024451-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  get__Default, VARIANT, ptr LPDISPATCH
  COM_MTD_STD  get_Item, VARIANT, ptr LPDISPATCH
COM_INTERFACE_END

COM_INTERFACE_BEG ICustomProperties, IDispatch, <00024452-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Add_, BSTR, VARIANT, ptr ptr CustomProperty
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  get__Default, VARIANT, ptr ptr CustomProperty
  COM_MTD_STD  get_Item, VARIANT, ptr ptr CustomProperty
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG ICustomProperty, IDispatch, <00024453-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  put_Name, BSTR
  COM_MTD_STD  get_Value, ptr VARIANT
  COM_MTD_STD  put_Value, VARIANT
  COM_MTD_STD  get__Default, ptr VARIANT
  COM_MTD_STD  Delete
COM_INTERFACE_END

COM_INTERFACE_BEG ICalculatedMembers, IDispatch, <00024454-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  get_Item, VARIANT, ptr ptr CalculatedMember
  COM_MTD_STD  get__Default, VARIANT, ptr ptr CalculatedMember
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  Add_, BSTR, BSTR, VARIANT, VARIANT, ptr ptr CalculatedMember
COM_INTERFACE_END

COM_INTERFACE_BEG ICalculatedMember, IDispatch, <00024455-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  get_Formula, ptr BSTR
  COM_MTD_STD  get_SourceName, ptr BSTR
  COM_MTD_STD  get_SolveOrder, ptr SDWORD
  COM_MTD_STD  get_IsValid, ptr BOOL
  COM_MTD_STD  get__Default, ptr BSTR
  COM_MTD_STD  Delete
  COM_MTD_STD  get_Type, ptr XlCalculatedMemberType
COM_INTERFACE_END

COM_INTERFACE_BEG IWatches, IDispatch, <00024456-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Add_, VARIANT, ptr ptr Watch
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  get__Default, VARIANT, ptr ptr Watch
  COM_MTD_STD  get_Item, VARIANT, ptr ptr Watch
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  Delete
COM_INTERFACE_END

COM_INTERFACE_BEG IWatch, IDispatch, <00024457-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Delete
  COM_MTD_STD  get_Source, ptr VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG IPivotCell, IDispatch, <00024458-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_PivotCellType, ptr XlPivotCellType
  COM_MTD_STD  get_PivotTable, ptr ptr PivotTable
  COM_MTD_STD  get_DataField, ptr ptr PivotField
  COM_MTD_STD  get_PivotField, ptr ptr PivotField
  COM_MTD_STD  get_PivotItem, ptr ptr PivotItem
  COM_MTD_STD  get_RowItems, ptr ptr PivotItemList
  COM_MTD_STD  get_ColumnItems, ptr ptr PivotItemList
  COM_MTD_STD  get_Range, ptr ptr Range
  COM_MTD_STD  get_Dummy18, ptr BSTR
  COM_MTD_STD  get_CustomSubtotalFunction, ptr XlConsolidationFunction
COM_INTERFACE_END

COM_INTERFACE_BEG IGraphic, IDispatch, <00024459-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Brightness, ptr REAL4
  COM_MTD_STD  put_Brightness, REAL4
  COM_MTD_STD  get_ColorType, ptr MsoPictureColorType
  COM_MTD_STD  put_ColorType, MsoPictureColorType
  COM_MTD_STD  get_Contrast, ptr REAL4
  COM_MTD_STD  put_Contrast, REAL4
  COM_MTD_STD  get_CropBottom, ptr REAL4
  COM_MTD_STD  put_CropBottom, REAL4
  COM_MTD_STD  get_CropLeft, ptr REAL4
  COM_MTD_STD  put_CropLeft, REAL4
  COM_MTD_STD  get_CropRight, ptr REAL4
  COM_MTD_STD  put_CropRight, REAL4
  COM_MTD_STD  get_CropTop, ptr REAL4
  COM_MTD_STD  put_CropTop, REAL4
  COM_MTD_STD  get_Filename, ptr BSTR
  COM_MTD_STD  put_Filename, BSTR
  COM_MTD_STD  get_Height, ptr REAL4
  COM_MTD_STD  put_Height, REAL4
  COM_MTD_STD  get_LockAspectRatio, ptr MsoTriState
  COM_MTD_STD  put_LockAspectRatio, MsoTriState
  COM_MTD_STD  get_Width, ptr REAL4
  COM_MTD_STD  put_Width, REAL4
COM_INTERFACE_END

COM_INTERFACE_BEG IAutoRecover, IDispatch, <0002445A-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_Time, ptr SDWORD
  COM_MTD_STD  put_Time, SDWORD
  COM_MTD_STD  get_Path, ptr BSTR
  COM_MTD_STD  put_Path, BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG IErrorCheckingOptions, IDispatch, <0002445B-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_BackgroundChecking, ptr BOOL
  COM_MTD_STD  put_BackgroundChecking, BOOL
  COM_MTD_STD  get_IndicatorColorIndex, ptr XlColorIndex
  COM_MTD_STD  put_IndicatorColorIndex, XlColorIndex
  COM_MTD_STD  get_EvaluateToError, ptr BOOL
  COM_MTD_STD  put_EvaluateToError, BOOL
  COM_MTD_STD  get_TextDate, ptr BOOL
  COM_MTD_STD  put_TextDate, BOOL
  COM_MTD_STD  get_NumberAsText, ptr BOOL
  COM_MTD_STD  put_NumberAsText, BOOL
  COM_MTD_STD  get_InconsistentFormula, ptr BOOL
  COM_MTD_STD  put_InconsistentFormula, BOOL
  COM_MTD_STD  get_OmittedCells, ptr BOOL
  COM_MTD_STD  put_OmittedCells, BOOL
  COM_MTD_STD  get_UnlockedFormulaCells, ptr BOOL
  COM_MTD_STD  put_UnlockedFormulaCells, BOOL
  COM_MTD_STD  get_EmptyCellReferences, ptr BOOL
  COM_MTD_STD  put_EmptyCellReferences, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG IErrors, IDispatch, <0002445C-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Item, VARIANT, ptr ptr Error
  COM_MTD_STD  get__Default, VARIANT, ptr ptr Error
COM_INTERFACE_END

COM_INTERFACE_BEG IError, IDispatch, <0002445D-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Value, ptr BOOL
  COM_MTD_STD  get_Ignore, ptr BOOL
  COM_MTD_STD  put_Ignore, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG ISmartTagAction, IDispatch, <0002445E-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  Execute
  COM_MTD_STD  get__Default, ptr BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG ISmartTagActions, IDispatch, <0002445F-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  get__Default, VARIANT, ptr ptr SmartTagAction
  COM_MTD_STD  get_Item, VARIANT, ptr ptr SmartTagAction
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG ISmartTag, IDispatch, <00024460-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_DownloadURL, ptr BSTR
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  get__Default, ptr BSTR
  COM_MTD_STD  get_XML, ptr BSTR
  COM_MTD_STD  get_Range, ptr ptr Range
  COM_MTD_STD  Delete
  COM_MTD_STD  get_SmartTagActions, ptr ptr SmartTagActions
  COM_MTD_STD  get_Properties, ptr ptr CustomProperties
COM_INTERFACE_END

COM_INTERFACE_BEG ISmartTags, IDispatch, <00024461-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  Add_, BSTR, ptr ptr SmartTag
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  get__Default, VARIANT, ptr ptr SmartTag
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG ISmartTagRecognizer, IDispatch, <00024462-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Enabled, ptr BOOL
  COM_MTD_STD  put_Enabled, BOOL
  COM_MTD_STD  get_progID, ptr BSTR
  COM_MTD_STD  get__Default, ptr BSTR
  COM_MTD_STD  get_FullName, ptr BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG ISmartTagRecognizers, IDispatch, <00024463-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  get_Item, VARIANT, ptr ptr SmartTagRecognizer
  COM_MTD_STD  get__Default, VARIANT, ptr ptr SmartTagRecognizer
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_STD  get_Recognize, ptr BOOL
  COM_MTD_STD  put_Recognize, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG ISmartTagOptions, IDispatch, <00024464-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_DisplaySmartTags, ptr XlSmartTagDisplayMode
  COM_MTD_STD  put_DisplaySmartTags, XlSmartTagDisplayMode
  COM_MTD_STD  get_EmbedSmartTags, ptr BOOL
  COM_MTD_STD  put_EmbedSmartTags, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG ISpellingOptions, IDispatch, <00024465-0001-0000-C000-000000000046>
  COM_MTD_STD  get_DictLang, ptr SDWORD
  COM_MTD_STD  put_DictLang, SDWORD
  COM_MTD_STD  get_UserDict, ptr BSTR
  COM_MTD_STD  put_UserDict, BSTR
  COM_MTD_STD  get_IgnoreCaps, ptr BOOL
  COM_MTD_STD  put_IgnoreCaps, BOOL
  COM_MTD_STD  get_SuggestMainOnly, ptr BOOL
  COM_MTD_STD  put_SuggestMainOnly, BOOL
  COM_MTD_STD  get_IgnoreMixedDigits, ptr BOOL
  COM_MTD_STD  put_IgnoreMixedDigits, BOOL
  COM_MTD_STD  get_IgnoreFileNames, ptr BOOL
  COM_MTD_STD  put_IgnoreFileNames, BOOL
  COM_MTD_STD  get_GermanPostReform, ptr BOOL
  COM_MTD_STD  put_GermanPostReform, BOOL
  COM_MTD_STD  get_KoreanCombineAux, ptr BOOL
  COM_MTD_STD  put_KoreanCombineAux, BOOL
  COM_MTD_STD  get_KoreanUseAutoChangeList, ptr BOOL
  COM_MTD_STD  put_KoreanUseAutoChangeList, BOOL
  COM_MTD_STD  get_KoreanProcessCompound, ptr BOOL
  COM_MTD_STD  put_KoreanProcessCompound, BOOL
  COM_MTD_STD  get_HebrewModes, ptr XlHebrewModes
  COM_MTD_STD  put_HebrewModes, XlHebrewModes
  COM_MTD_STD  get_ArabicModes, ptr XlArabicModes
  COM_MTD_STD  put_ArabicModes, XlArabicModes
COM_INTERFACE_END

COM_INTERFACE_BEG ISpeech, IDispatch, <00024466-0001-0000-C000-000000000046>
  COM_MTD_STD  Speak, BSTR, VARIANT, VARIANT, VARIANT
  COM_MTD_STD  get_Direction, ptr XlSpeakDirection
  COM_MTD_STD  put_Direction, XlSpeakDirection
  COM_MTD_STD  get_SpeakCellOnEnter, ptr BOOL
  COM_MTD_STD  put_SpeakCellOnEnter, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG IProtection, IDispatch, <00024467-0001-0000-C000-000000000046>
  COM_MTD_STD  get_AllowFormattingCells, ptr BOOL
  COM_MTD_STD  get_AllowFormattingColumns, ptr BOOL
  COM_MTD_STD  get_AllowFormattingRows, ptr BOOL
  COM_MTD_STD  get_AllowInsertingColumns, ptr BOOL
  COM_MTD_STD  get_AllowInsertingRows, ptr BOOL
  COM_MTD_STD  get_AllowInsertingHyperlinks, ptr BOOL
  COM_MTD_STD  get_AllowDeletingColumns, ptr BOOL
  COM_MTD_STD  get_AllowDeletingRows, ptr BOOL
  COM_MTD_STD  get_AllowSorting, ptr BOOL
  COM_MTD_STD  get_AllowFiltering, ptr BOOL
  COM_MTD_STD  get_AllowUsingPivotTables, ptr BOOL
  COM_MTD_STD  get_AllowEditRanges, ptr ptr AllowEditRanges
COM_INTERFACE_END

COM_INTERFACE_BEG IPivotItemList, IDispatch, <00024468-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  Item, VARIANT, ptr ptr PivotItem
  COM_MTD_STD  get__Default, VARIANT, ptr ptr PivotItem
  COM_MTD_STD  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG ITab, IDispatch, <00024469-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Color, ptr VARIANT
  COM_MTD_STD  put_Color, VARIANT
  COM_MTD_STD  get_ColorIndex, ptr XlColorIndex
  COM_MTD_STD  put_ColorIndex, XlColorIndex
COM_INTERFACE_END

COM_INTERFACE_BEG IAllowEditRanges, IDispatch, <0002446A-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  get_Item, VARIANT, ptr ptr AllowEditRange
  COM_MTD_STD  Add_, BSTR, ptr Range, VARIANT, ptr ptr AllowEditRange
  COM_MTD_STD  get__Default, VARIANT, ptr ptr AllowEditRange
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IAllowEditRange, IDispatch, <0002446B-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Title, ptr BSTR
  COM_MTD_STD  put_Title, BSTR
  COM_MTD_STD  get_Range, ptr ptr Range
  COM_MTD_STD  putref_Range, ptr Range
  COM_MTD_STD  ChangePassword, BSTR
  COM_MTD_STD  Delete
  COM_MTD_STD  Unprotect, VARIANT
  COM_MTD_STD  get_Users, ptr ptr UserAccessList
COM_INTERFACE_END

COM_INTERFACE_BEG IUserAccessList, IDispatch, <0002446C-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Count, ptr SDWORD
  COM_MTD_STD  get_Item, VARIANT, ptr ptr UserAccess
  COM_MTD_STD  Add_, BSTR, BOOL, ptr ptr UserAccess
  COM_MTD_STD  DeleteAll
  COM_MTD_STD  get__Default, VARIANT, ptr ptr UserAccess
  COM_MTD_STD  get__NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IUserAccess, IDispatch, <0002446D-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Name, ptr BSTR
  COM_MTD_STD  get_AllowEdit, ptr BOOL
  COM_MTD_STD  put_AllowEdit, BOOL
  COM_MTD_STD  Delete
COM_INTERFACE_END

COM_INTERFACE_BEG IRTD, IDispatch, <0002446E-0001-0000-C000-000000000046>
  COM_MTD_STD  get_ThrottleInterval, ptr SDWORD
  COM_MTD_STD  put_ThrottleInterval, SDWORD
  COM_MTD_STD  RefreshData
  COM_MTD_STD  RestartServers
COM_INTERFACE_END

COM_INTERFACE_BEG IDiagram, IDispatch, <0002446F-0001-0000-C000-000000000046>
  COM_MTD_STD  get_Application, ptr ptr Application
  COM_MTD_STD  get_Creator, ptr XlCreator
  COM_MTD_STD  get_Parent, ptr LPDISPATCH
  COM_MTD_STD  get_Nodes, ptr ptr DiagramNodes
  COM_MTD_STD  get_Type, ptr MsoDiagramType
  COM_MTD_STD  get_AutoLayout, ptr MsoTriState
  COM_MTD_STD  put_AutoLayout, MsoTriState
  COM_MTD_STD  get_Reverse, ptr MsoTriState
  COM_MTD_STD  put_Reverse, MsoTriState
  COM_MTD_STD  get_AutoFormat, ptr MsoTriState
  COM_MTD_STD  put_AutoFormat, MsoTriState
  COM_MTD_STD  Convert, MsoDiagramType
COM_INTERFACE_END

COM_INTERFACE_BEG IDummy, IDispatch, <0002442E-0001-0000-C000-000000000046>
  COM_MTD_STD  _ActiveSheetOrChart
  COM_MTD_STD  RGB
  COM_MTD_STD  ChDir
  COM_MTD_STD  DoScript
  COM_MTD_STD  DirectObject
  COM_MTD_STD  RefreshDocument
COM_INTERFACE_END

COM_INTERFACE_BEG ICanvasShapes, IDispatch, <0002444F-0001-0000-C000-000000000046>
COM_INTERFACE_END

COM_INTERFACE_BEG Windows, IDispatch, <00020892-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Arrange, XlArrangeStyle, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  get_Item, VARIANT, ptr ptr Window
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_DSP  get__Default, VARIANT, ptr ptr Window
COM_INTERFACE_END

COM_INTERFACE_BEG AppEvents, IDispatch, <00024413-0000-0000-C000-000000000046>
  COM_MTD_DSP  NewWorkbook, ptr Workbook
  COM_MTD_DSP  SheetSelectionChange, LPDISPATCH, ptr Range
  COM_MTD_DSP  SheetBeforeDoubleClick, LPDISPATCH, ptr Range, ptr BOOL
  COM_MTD_DSP  SheetBeforeRightClick, LPDISPATCH, ptr Range, ptr BOOL
  COM_MTD_DSP  SheetActivate, LPDISPATCH
  COM_MTD_DSP  SheetDeactivate, LPDISPATCH
  COM_MTD_DSP  SheetCalculate, LPDISPATCH
  COM_MTD_DSP  SheetChange, LPDISPATCH, ptr Range
  COM_MTD_DSP  WorkbookOpen, ptr Workbook
  COM_MTD_DSP  WorkbookActivate, ptr Workbook
  COM_MTD_DSP  WorkbookDeactivate, ptr Workbook
  COM_MTD_DSP  WorkbookBeforeClose, ptr Workbook, ptr BOOL
  COM_MTD_DSP  WorkbookBeforeSave, ptr Workbook, BOOL, ptr BOOL
  COM_MTD_DSP  WorkbookBeforePrint, ptr Workbook, ptr BOOL
  COM_MTD_DSP  WorkbookNewSheet, ptr Workbook, LPDISPATCH
  COM_MTD_DSP  WorkbookAddinInstall, ptr Workbook
  COM_MTD_DSP  WorkbookAddinUninstall, ptr Workbook
  COM_MTD_DSP  WindowResize, ptr Workbook, ptr Window
  COM_MTD_DSP  WindowActivate, ptr Workbook, ptr Window
  COM_MTD_DSP  WindowDeactivate, ptr Workbook, ptr Window
  COM_MTD_DSP  SheetFollowHyperlink, LPDISPATCH, ptr Hyperlink
  COM_MTD_DSP  SheetPivotTableUpdate, LPDISPATCH, ptr PivotTable
  COM_MTD_DSP  WorkbookPivotTableCloseConnection, ptr Workbook, ptr PivotTable
  COM_MTD_DSP  WorkbookPivotTableOpenConnection, ptr Workbook, ptr PivotTable
COM_INTERFACE_END

COM_INTERFACE_BEG WorksheetFunction, IDispatch, <00020845-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
;+++   COM_MTD_DSP  _WSFunction, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
;+++   COM_MTD_DSP  Count, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  IsNA, VARIANT, ptr BOOL
  COM_MTD_DSP  IsError, VARIANT, ptr BOOL
;+++   COM_MTD_DSP  Sum, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
;+++   COM_MTD_DSP  Average, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
;+++   COM_MTD_DSP  Min, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
;+++   COM_MTD_DSP  Max, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
;+++   COM_MTD_DSP  Npv, REAL8, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
;+++   COM_MTD_DSP  StDev, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  Dollar, REAL8, VARIANT, ptr BSTR
  COM_MTD_DSP  Fixed, REAL8, VARIANT, VARIANT, ptr BSTR
  COM_MTD_DSP  Pi, ptr REAL8
  COM_MTD_DSP  Ln, REAL8, ptr REAL8
  COM_MTD_DSP  Log10, REAL8, ptr REAL8
  COM_MTD_DSP  Round, REAL8, REAL8, ptr REAL8
  COM_MTD_DSP  Lookup, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  Index, VARIANT, REAL8, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  Rept_, BSTR, REAL8, ptr BSTR
;+++   COM_MTD_DSP  And_, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr BOOL
;+++   COM_MTD_DSP  Or_, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr BOOL
  COM_MTD_DSP  DCount, ptr Range, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  DSum, ptr Range, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  DAverage, ptr Range, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  DMin, ptr Range, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  DMax, ptr Range, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  DStDev, ptr Range, VARIANT, VARIANT, ptr REAL8
;+++   COM_MTD_DSP  Var, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  DVar, ptr Range, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  Text, VARIANT, BSTR, ptr BSTR
  COM_MTD_DSP  LinEst, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  Trend, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  LogEst, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  Growth, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  Pv, REAL8, REAL8, REAL8, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  Fv, REAL8, REAL8, REAL8, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  NPer, REAL8, REAL8, REAL8, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  Pmt, REAL8, REAL8, REAL8, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  Rate, REAL8, REAL8, REAL8, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  MIrr, VARIANT, REAL8, REAL8, ptr REAL8
  COM_MTD_DSP  Irr, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  Match, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  Weekday, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  Search, BSTR, BSTR, VARIANT, ptr REAL8
  COM_MTD_DSP  Transpose, VARIANT, ptr VARIANT
  COM_MTD_DSP  Atan2, REAL8, REAL8, ptr REAL8
  COM_MTD_DSP  Asin, REAL8, ptr REAL8
  COM_MTD_DSP  Acos, REAL8, ptr REAL8
;+++   COM_MTD_DSP  Choose, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  HLookup, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  VLookup, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  Log, REAL8, VARIANT, ptr REAL8
  COM_MTD_DSP  Proper, BSTR, ptr BSTR
  COM_MTD_DSP  Trim, BSTR, ptr BSTR
  COM_MTD_DSP  Replace, BSTR, REAL8, REAL8, BSTR, ptr BSTR
  COM_MTD_DSP  Substitute, BSTR, BSTR, BSTR, VARIANT, ptr BSTR
  COM_MTD_DSP  Find, BSTR, BSTR, VARIANT, ptr REAL8
  COM_MTD_DSP  IsErr, VARIANT, ptr BOOL
  COM_MTD_DSP  IsText, VARIANT, ptr BOOL
  COM_MTD_DSP  IsNumber, VARIANT, ptr BOOL
  COM_MTD_DSP  Sln, REAL8, REAL8, REAL8, ptr REAL8
  COM_MTD_DSP  Syd, REAL8, REAL8, REAL8, REAL8, ptr REAL8
  COM_MTD_DSP  Ddb, REAL8, REAL8, REAL8, REAL8, VARIANT, ptr REAL8
  COM_MTD_DSP  Clean, BSTR, ptr BSTR
  COM_MTD_DSP  MDeterm, VARIANT, ptr REAL8
  COM_MTD_DSP  MInverse, VARIANT, ptr VARIANT
  COM_MTD_DSP  MMult, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  Ipmt, REAL8, REAL8, REAL8, REAL8, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  Ppmt, REAL8, REAL8, REAL8, REAL8, VARIANT, VARIANT, ptr REAL8
;+++   COM_MTD_DSP  CountA, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
;+++   COM_MTD_DSP  Product, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  Fact, REAL8, ptr REAL8
  COM_MTD_DSP  DProduct, ptr Range, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  IsNonText, VARIANT, ptr BOOL
;+++   COM_MTD_DSP  StDevP, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
;+++   COM_MTD_DSP  VarP, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  DStDevP, ptr Range, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  DVarP, ptr Range, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  IsLogical, VARIANT, ptr BOOL
  COM_MTD_DSP  DCountA, ptr Range, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  USDollar, REAL8, REAL8, ptr BSTR
  COM_MTD_DSP  FindB, BSTR, BSTR, VARIANT, ptr REAL8
  COM_MTD_DSP  SearchB, BSTR, BSTR, VARIANT, ptr REAL8
  COM_MTD_DSP  ReplaceB, BSTR, REAL8, REAL8, BSTR, ptr BSTR
  COM_MTD_DSP  RoundUp, REAL8, REAL8, ptr REAL8
  COM_MTD_DSP  RoundDown, REAL8, REAL8, ptr REAL8
  COM_MTD_DSP  Rank, REAL8, ptr Range, VARIANT, ptr REAL8
  COM_MTD_DSP  Days360, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  Vdb, REAL8, REAL8, REAL8, REAL8, REAL8, VARIANT, VARIANT, ptr REAL8
;+++   COM_MTD_DSP  Median, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
;+++   COM_MTD_DSP  SumProduct, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  Sinh, REAL8, ptr REAL8
  COM_MTD_DSP  Cosh, REAL8, ptr REAL8
  COM_MTD_DSP  Tanh, REAL8, ptr REAL8
  COM_MTD_DSP  Asinh, REAL8, ptr REAL8
  COM_MTD_DSP  Acosh, REAL8, ptr REAL8
  COM_MTD_DSP  Atanh, REAL8, ptr REAL8
  COM_MTD_DSP  DGet, ptr Range, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  Db, REAL8, REAL8, REAL8, REAL8, VARIANT, ptr REAL8
  COM_MTD_DSP  Frequency, VARIANT, VARIANT, ptr VARIANT
;+++   COM_MTD_DSP  AveDev, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  BetaDist, REAL8, REAL8, REAL8, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  GammaLn, REAL8, ptr REAL8
  COM_MTD_DSP  BetaInv, REAL8, REAL8, REAL8, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  BinomDist, REAL8, REAL8, REAL8, BOOL, ptr REAL8
  COM_MTD_DSP  ChiDist, REAL8, REAL8, ptr REAL8
  COM_MTD_DSP  ChiInv, REAL8, REAL8, ptr REAL8
  COM_MTD_DSP  Combin, REAL8, REAL8, ptr REAL8
  COM_MTD_DSP  Confidence, REAL8, REAL8, REAL8, ptr REAL8
  COM_MTD_DSP  CritBinom, REAL8, REAL8, REAL8, ptr REAL8
  COM_MTD_DSP  Even_, REAL8, ptr REAL8
  COM_MTD_DSP  ExponDist, REAL8, REAL8, BOOL, ptr REAL8
  COM_MTD_DSP  FDist, REAL8, REAL8, REAL8, ptr REAL8
  COM_MTD_DSP  FInv, REAL8, REAL8, REAL8, ptr REAL8
  COM_MTD_DSP  Fisher, REAL8, ptr REAL8
  COM_MTD_DSP  FisherInv, REAL8, ptr REAL8
  COM_MTD_DSP  Floor, REAL8, REAL8, ptr REAL8
  COM_MTD_DSP  GammaDist, REAL8, REAL8, REAL8, BOOL, ptr REAL8
  COM_MTD_DSP  GammaInv, REAL8, REAL8, REAL8, ptr REAL8
  COM_MTD_DSP  Ceiling, REAL8, REAL8, ptr REAL8
  COM_MTD_DSP  HypGeomDist, REAL8, REAL8, REAL8, REAL8, ptr REAL8
  COM_MTD_DSP  LogNormDist, REAL8, REAL8, REAL8, ptr REAL8
  COM_MTD_DSP  LogInv, REAL8, REAL8, REAL8, ptr REAL8
  COM_MTD_DSP  NegBinomDist, REAL8, REAL8, REAL8, ptr REAL8
  COM_MTD_DSP  NormDist, REAL8, REAL8, REAL8, BOOL, ptr REAL8
  COM_MTD_DSP  NormSDist, REAL8, ptr REAL8
  COM_MTD_DSP  NormInv, REAL8, REAL8, REAL8, ptr REAL8
  COM_MTD_DSP  NormSInv, REAL8, ptr REAL8
  COM_MTD_DSP  Standardize, REAL8, REAL8, REAL8, ptr REAL8
  COM_MTD_DSP  Odd, REAL8, ptr REAL8
  COM_MTD_DSP  Permut, REAL8, REAL8, ptr REAL8
  COM_MTD_DSP  Poisson, REAL8, REAL8, BOOL, ptr REAL8
  COM_MTD_DSP  TDist, REAL8, REAL8, REAL8, ptr REAL8
  COM_MTD_DSP  Weibull, REAL8, REAL8, REAL8, BOOL, ptr REAL8
  COM_MTD_DSP  SumXMY2, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  SumX2MY2, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  SumX2PY2, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  ChiTest, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  Correl, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  Covar, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  Forecast, REAL8, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  FTest, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  Intercept, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  Pearson, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  RSq, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  StEyx, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  Slope, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  TTest, VARIANT, VARIANT, REAL8, REAL8, ptr REAL8
  COM_MTD_DSP  Prob, VARIANT, VARIANT, REAL8, VARIANT, ptr REAL8
;+++   COM_MTD_DSP  DevSq, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
;+++   COM_MTD_DSP  GeoMean, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
;+++   COM_MTD_DSP  HarMean, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
;+++   COM_MTD_DSP  SumSq, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
;+++   COM_MTD_DSP  Kurt, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
;+++   COM_MTD_DSP  Skew, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  ZTest, VARIANT, REAL8, VARIANT, ptr REAL8
  COM_MTD_DSP  Large, VARIANT, REAL8, ptr REAL8
  COM_MTD_DSP  Small, VARIANT, REAL8, ptr REAL8
  COM_MTD_DSP  Quartile, VARIANT, REAL8, ptr REAL8
  COM_MTD_DSP  Percentile, VARIANT, REAL8, ptr REAL8
  COM_MTD_DSP  PercentRank, VARIANT, REAL8, VARIANT, ptr REAL8
;+++   COM_MTD_DSP  Mode, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  TrimMean, VARIANT, REAL8, ptr REAL8
  COM_MTD_DSP  TInv, REAL8, REAL8, ptr REAL8
  COM_MTD_DSP  Power, REAL8, REAL8, ptr REAL8
  COM_MTD_DSP  Radians, REAL8, ptr REAL8
  COM_MTD_DSP  Degrees, REAL8, ptr REAL8
;+++   COM_MTD_DSP  Subtotal, REAL8, ptr Range, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  SumIf, ptr Range, VARIANT, VARIANT, ptr REAL8
  COM_MTD_DSP  CountIf, ptr Range, VARIANT, ptr REAL8
  COM_MTD_DSP  CountBlank, ptr Range, ptr REAL8
  COM_MTD_DSP  Ispmt, REAL8, REAL8, REAL8, REAL8, ptr REAL8
  COM_MTD_DSP  Roman, REAL8, VARIANT, ptr BSTR
  COM_MTD_DSP  Asc, BSTR, ptr BSTR
  COM_MTD_DSP  Dbcs, BSTR, ptr BSTR
  COM_MTD_DSP  Phonetic, ptr Range, ptr BSTR
  COM_MTD_DSP  BahtText, REAL8, ptr BSTR
  COM_MTD_DSP  ThaiDayOfWeek, REAL8, ptr BSTR
  COM_MTD_DSP  ThaiDigit, BSTR, ptr BSTR
  COM_MTD_DSP  ThaiMonthOfYear, REAL8, ptr BSTR
  COM_MTD_DSP  ThaiNumSound, REAL8, ptr BSTR
  COM_MTD_DSP  ThaiNumString, REAL8, ptr BSTR
  COM_MTD_DSP  ThaiStringLength, BSTR, ptr REAL8
  COM_MTD_DSP  IsThaiDigit, BSTR, ptr BOOL
  COM_MTD_DSP  RoundBahtDown, REAL8, ptr REAL8
  COM_MTD_DSP  RoundBahtUp, REAL8, ptr REAL8
  COM_MTD_DSP  ThaiYear, REAL8, ptr REAL8
;+++   COM_MTD_DSP  RTD, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG Range, IDispatch, <00020846-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Activate, ptr VARIANT
  COM_MTD_DSP  get_AddIndent, ptr VARIANT
  COM_MTD_DSP  put_AddIndent, VARIANT
  COM_MTD_DSP  get_Address, VARIANT, VARIANT, XlReferenceStyle, VARIANT, VARIANT, ptr BSTR
  COM_MTD_DSP  get_AddressLocal, VARIANT, VARIANT, XlReferenceStyle, VARIANT, VARIANT, ptr BSTR
  COM_MTD_DSP  AdvancedFilter, XlFilterAction, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  ApplyNames, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, XlApplyNamesOrder, VARIANT, ptr VARIANT
  COM_MTD_DSP  ApplyOutlineStyles, ptr VARIANT
  COM_MTD_DSP  get_Areas, ptr ptr Areas
  COM_MTD_DSP  AutoComplete, BSTR, ptr BSTR
  COM_MTD_DSP  AutoFill, ptr Range, XlAutoFillType, ptr VARIANT
  COM_MTD_DSP  AutoFilter, VARIANT, VARIANT, XlAutoFilterOperator, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  AutoFit, ptr VARIANT
  COM_MTD_DSP  AutoFormat, XlRangeAutoFormat, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  AutoOutline, ptr VARIANT
  COM_MTD_DSP  BorderAround, VARIANT, XlBorderWeight, XlColorIndex, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_Borders, ptr ptr Borders
  COM_MTD_DSP  Calculate, ptr VARIANT
  COM_MTD_DSP  get_Cells, ptr ptr Range
  COM_MTD_DSP  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_DSP  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  Clear, ptr VARIANT
  COM_MTD_DSP  ClearContents, ptr VARIANT
  COM_MTD_DSP  ClearFormats, ptr VARIANT
  COM_MTD_DSP  ClearNotes, ptr VARIANT
  COM_MTD_DSP  ClearOutline, ptr VARIANT
  COM_MTD_DSP  get_Column, ptr SDWORD
  COM_MTD_DSP  ColumnDifferences, VARIANT, ptr ptr Range
  COM_MTD_DSP  get_Columns, ptr ptr Range
  COM_MTD_DSP  get_ColumnWidth, ptr VARIANT
  COM_MTD_DSP  put_ColumnWidth, VARIANT
  COM_MTD_DSP  Consolidate, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  Copy, VARIANT, ptr VARIANT
  COM_MTD_DSP  CopyFromRecordset, LPUNKNOWN, VARIANT, VARIANT, ptr SDWORD
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  CreateNames, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  CreatePublisher, VARIANT, XlPictureAppearance, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_CurrentArray, ptr ptr Range
  COM_MTD_DSP  get_CurrentRegion, ptr ptr Range
  COM_MTD_DSP  Cut, VARIANT, ptr VARIANT
  COM_MTD_DSP  DataSeries, VARIANT, XlDataSeriesType, XlDataSeriesDate, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get__Default, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  put__Default, VARIANT, VARIANT, VARIANT
  COM_MTD_DSP  Delete, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_Dependents, ptr ptr Range
  COM_MTD_DSP  DialogBox, ptr VARIANT
  COM_MTD_DSP  get_DirectDependents, ptr ptr Range
  COM_MTD_DSP  get_DirectPrecedents, ptr ptr Range
  COM_MTD_DSP  EditionOptions, XlEditionType, XlEditionOptionsOption, VARIANT, VARIANT, XlPictureAppearance, XlPictureAppearance, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_End, XlDirection, ptr ptr Range
  COM_MTD_DSP  get_EntireColumn, ptr ptr Range
  COM_MTD_DSP  get_EntireRow, ptr ptr Range
  COM_MTD_DSP  FillDown, ptr VARIANT
  COM_MTD_DSP  FillLeft, ptr VARIANT
  COM_MTD_DSP  FillRight, ptr VARIANT
  COM_MTD_DSP  FillUp, ptr VARIANT
  COM_MTD_DSP  Find, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, XlSearchDirection, VARIANT, VARIANT, VARIANT, ptr ptr Range
  COM_MTD_DSP  FindNext, VARIANT, ptr ptr Range
  COM_MTD_DSP  FindPrevious, VARIANT, ptr ptr Range
  COM_MTD_DSP  get_Font, ptr ptr Font
  COM_MTD_DSP  get_Formula, ptr VARIANT
  COM_MTD_DSP  put_Formula, VARIANT
  COM_MTD_DSP  get_FormulaArray, ptr VARIANT
  COM_MTD_DSP  put_FormulaArray, VARIANT
  COM_MTD_DSP  get_FormulaLabel, ptr XlFormulaLabel
  COM_MTD_DSP  put_FormulaLabel, XlFormulaLabel
  COM_MTD_DSP  get_FormulaHidden, ptr VARIANT
  COM_MTD_DSP  put_FormulaHidden, VARIANT
  COM_MTD_DSP  get_FormulaLocal, ptr VARIANT
  COM_MTD_DSP  put_FormulaLocal, VARIANT
  COM_MTD_DSP  get_FormulaR1C1, ptr VARIANT
  COM_MTD_DSP  put_FormulaR1C1, VARIANT
  COM_MTD_DSP  get_FormulaR1C1Local, ptr VARIANT
  COM_MTD_DSP  put_FormulaR1C1Local, VARIANT
  COM_MTD_DSP  FunctionWizard, ptr VARIANT
  COM_MTD_DSP  GoalSeek, VARIANT, ptr Range, ptr BOOL
  COM_MTD_DSP  Group_, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_HasArray, ptr VARIANT
  COM_MTD_DSP  get_HasFormula, ptr VARIANT
  COM_MTD_DSP  get_Height, ptr VARIANT
  COM_MTD_DSP  get_Hidden, ptr VARIANT
  COM_MTD_DSP  put_Hidden, VARIANT
  COM_MTD_DSP  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_DSP  put_HorizontalAlignment, VARIANT
  COM_MTD_DSP  get_IndentLevel, ptr VARIANT
  COM_MTD_DSP  put_IndentLevel, VARIANT
  COM_MTD_DSP  InsertIndent, SDWORD
  COM_MTD_DSP  Insert, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_Item, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  put_Item, VARIANT, VARIANT, VARIANT
  COM_MTD_DSP  Justify, ptr VARIANT
  COM_MTD_DSP  get_Left, ptr VARIANT
  COM_MTD_DSP  get_ListHeaderRows, ptr SDWORD
  COM_MTD_DSP  ListNames, ptr VARIANT
  COM_MTD_DSP  get_LocationInTable, ptr XlLocationInTable
  COM_MTD_DSP  get_Locked, ptr VARIANT
  COM_MTD_DSP  put_Locked, VARIANT
  COM_MTD_DSP  Merge, VARIANT
  COM_MTD_DSP  UnMerge
  COM_MTD_DSP  get_MergeArea, ptr ptr Range
  COM_MTD_DSP  get_MergeCells, ptr VARIANT
  COM_MTD_DSP  put_MergeCells, VARIANT
  COM_MTD_DSP  get_Name, ptr VARIANT
  COM_MTD_DSP  put_Name, VARIANT
  COM_MTD_DSP  NavigateArrow, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_DSP  get_Next, ptr ptr Range
  COM_MTD_DSP  NoteText, VARIANT, VARIANT, VARIANT, ptr BSTR
  COM_MTD_DSP  get_NumberFormat, ptr VARIANT
  COM_MTD_DSP  put_NumberFormat, VARIANT
  COM_MTD_DSP  get_NumberFormatLocal, ptr VARIANT
  COM_MTD_DSP  put_NumberFormatLocal, VARIANT
  COM_MTD_DSP  get_Offset, VARIANT, VARIANT, ptr ptr Range
  COM_MTD_DSP  get_Orientation, ptr VARIANT
  COM_MTD_DSP  put_Orientation, VARIANT
  COM_MTD_DSP  get_OutlineLevel, ptr VARIANT
  COM_MTD_DSP  put_OutlineLevel, VARIANT
  COM_MTD_DSP  get_PageBreak, ptr SDWORD
  COM_MTD_DSP  put_PageBreak, SDWORD
  COM_MTD_DSP  Parse, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  _PasteSpecial, XlPasteType, XlPasteSpecialOperation, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_PivotField, ptr ptr PivotField
  COM_MTD_DSP  get_PivotItem, ptr ptr PivotItem
  COM_MTD_DSP  get_PivotTable, ptr ptr PivotTable
  COM_MTD_DSP  get_Precedents, ptr ptr Range
  COM_MTD_DSP  get_PrefixCharacter, ptr VARIANT
  COM_MTD_DSP  get_Previous, ptr ptr Range
  COM_MTD_DSP  _PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  PrintPreview, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_QueryTable, ptr ptr QueryTable
  COM_MTD_DSP  get_Range, VARIANT, VARIANT, ptr ptr Range
  COM_MTD_DSP  RemoveSubtotal, ptr VARIANT
  COM_MTD_DSP  Replace, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr BOOL
  COM_MTD_DSP  get_Resize, VARIANT, VARIANT, ptr ptr Range
  COM_MTD_DSP  get_Row, ptr SDWORD
  COM_MTD_DSP  RowDifferences, VARIANT, ptr ptr Range
  COM_MTD_DSP  get_RowHeight, ptr VARIANT
  COM_MTD_DSP  put_RowHeight, VARIANT
  COM_MTD_DSP  get_Rows, ptr ptr Range
;+++   COM_MTD_DSP  Run, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  Select, ptr VARIANT
  COM_MTD_DSP  Show, ptr VARIANT
  COM_MTD_DSP  ShowDependents, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_ShowDetail, ptr VARIANT
  COM_MTD_DSP  put_ShowDetail, VARIANT
  COM_MTD_DSP  ShowErrors, ptr VARIANT
  COM_MTD_DSP  ShowPrecedents, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_ShrinkToFit, ptr VARIANT
  COM_MTD_DSP  put_ShrinkToFit, VARIANT
  COM_MTD_DSP  Sort, VARIANT, XlSortOrder, VARIANT, VARIANT, XlSortOrder, VARIANT, XlSortOrder, XlYesNoGuess, VARIANT, VARIANT, XlSortOrientation, XlSortMethod, XlSortDataOption, XlSortDataOption, XlSortDataOption, ptr VARIANT
  COM_MTD_DSP  SortSpecial, XlSortMethod, VARIANT, XlSortOrder, VARIANT, VARIANT, XlSortOrder, VARIANT, XlSortOrder, XlYesNoGuess, VARIANT, VARIANT, XlSortOrientation, XlSortDataOption, XlSortDataOption, XlSortDataOption, ptr VARIANT
  COM_MTD_DSP  get_SoundNote, ptr ptr SoundNote
  COM_MTD_DSP  SpecialCells, XlCellType, VARIANT, ptr ptr Range
  COM_MTD_DSP  get_Style, ptr VARIANT
  COM_MTD_DSP  put_Style, VARIANT
  COM_MTD_DSP  SubscribeTo, BSTR, XlSubscribeToFormat, ptr VARIANT
  COM_MTD_DSP  Subtotal, SDWORD, XlConsolidationFunction, VARIANT, VARIANT, VARIANT, XlSummaryRow, ptr VARIANT
  COM_MTD_DSP  get_Summary, ptr VARIANT
  COM_MTD_DSP  Table, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_Text, ptr VARIANT
  COM_MTD_DSP  TextToColumns, VARIANT, XlTextParsingType, XlTextQualifier, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr VARIANT
  COM_MTD_DSP  Ungroup, ptr VARIANT
  COM_MTD_DSP  get_UseStandardHeight, ptr VARIANT
  COM_MTD_DSP  put_UseStandardHeight, VARIANT
  COM_MTD_DSP  get_UseStandardWidth, ptr VARIANT
  COM_MTD_DSP  put_UseStandardWidth, VARIANT
  COM_MTD_DSP  get_Validation, ptr ptr Validation
  COM_MTD_DSP  get_Value, VARIANT, ptr VARIANT
  COM_MTD_DSP  put_Value, VARIANT, VARIANT
  COM_MTD_DSP  get_Value2, ptr VARIANT
  COM_MTD_DSP  put_Value2, VARIANT
  COM_MTD_DSP  get_VerticalAlignment, ptr VARIANT
  COM_MTD_DSP  put_VerticalAlignment, VARIANT
  COM_MTD_DSP  get_Width, ptr VARIANT
  COM_MTD_DSP  get_Worksheet, ptr ptr Worksheet
  COM_MTD_DSP  get_WrapText, ptr VARIANT
  COM_MTD_DSP  put_WrapText, VARIANT
  COM_MTD_DSP  AddComment, VARIANT, ptr ptr Comment_
  COM_MTD_DSP  get_Comment, ptr ptr Comment_
  COM_MTD_DSP  ClearComments
  COM_MTD_DSP  get_Phonetic, ptr ptr Phonetic
  COM_MTD_DSP  get_FormatConditions, ptr ptr FormatConditions
  COM_MTD_DSP  get_ReadingOrder, ptr SDWORD
  COM_MTD_DSP  put_ReadingOrder, SDWORD
  COM_MTD_DSP  get_Hyperlinks, ptr ptr Hyperlinks
  COM_MTD_DSP  get_Phonetics, ptr ptr Phonetics
  COM_MTD_DSP  SetPhonetic
  COM_MTD_DSP  get_ID, ptr BSTR
  COM_MTD_DSP  put_ID, BSTR
  COM_MTD_DSP  PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_PivotCell, ptr ptr PivotCell
  COM_MTD_DSP  Dirty
  COM_MTD_DSP  get_Errors, ptr ptr Errors
  COM_MTD_DSP  get_SmartTags, ptr ptr SmartTags
  COM_MTD_DSP  Speak, VARIANT, VARIANT
  COM_MTD_DSP  PasteSpecial, XlPasteType, XlPasteSpecialOperation, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_AllowEdit, ptr BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG ChartEvents, IDispatch, <0002440F-0000-0000-C000-000000000046>
  COM_MTD_DSP  Activate
  COM_MTD_DSP  Deactivate
  COM_MTD_DSP  Resize
  COM_MTD_DSP  MouseDown, SDWORD, SDWORD, SDWORD, SDWORD
  COM_MTD_DSP  MouseUp, SDWORD, SDWORD, SDWORD, SDWORD
  COM_MTD_DSP  MouseMove, SDWORD, SDWORD, SDWORD, SDWORD
  COM_MTD_DSP  BeforeRightClick, ptr BOOL
  COM_MTD_DSP  DragPlot
  COM_MTD_DSP  DragOver
  COM_MTD_DSP  BeforeDoubleClick, SDWORD, SDWORD, SDWORD, ptr BOOL
  COM_MTD_DSP  Select, SDWORD, SDWORD, SDWORD
  COM_MTD_DSP  SeriesChange, SDWORD, SDWORD
  COM_MTD_DSP  Calculate
COM_INTERFACE_END

COM_INTERFACE_BEG VPageBreak, IDispatch, <00024402-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr ptr Worksheet
  COM_MTD_DSP  Delete
  COM_MTD_DSP  DragOff, XlDirection, SDWORD
  COM_MTD_DSP  get_Type, ptr XlPageBreak
  COM_MTD_DSP  put_Type, XlPageBreak
  COM_MTD_DSP  get_Extent, ptr XlPageBreakExtent
  COM_MTD_DSP  get_Location, ptr ptr Range
  COM_MTD_DSP  putref_Location, ptr Range
COM_INTERFACE_END

COM_INTERFACE_BEG HPageBreak, IDispatch, <00024401-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr ptr Worksheet
  COM_MTD_DSP  Delete
  COM_MTD_DSP  DragOff, XlDirection, SDWORD
  COM_MTD_DSP  get_Type, ptr XlPageBreak
  COM_MTD_DSP  put_Type, XlPageBreak
  COM_MTD_DSP  get_Extent, ptr XlPageBreakExtent
  COM_MTD_DSP  get_Location, ptr ptr Range
  COM_MTD_DSP  putref_Location, ptr Range
COM_INTERFACE_END

COM_INTERFACE_BEG HPageBreaks, IDispatch, <00024404-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  get_Item, SDWORD, ptr ptr HPageBreak
  COM_MTD_DSP  get__Default, SDWORD, ptr ptr HPageBreak
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_DSP  Add_, LPDISPATCH, ptr ptr HPageBreak
COM_INTERFACE_END

COM_INTERFACE_BEG VPageBreaks, IDispatch, <00024405-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  get_Item, SDWORD, ptr ptr VPageBreak
  COM_MTD_DSP  get__Default, SDWORD, ptr ptr VPageBreak
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_DSP  Add_, LPDISPATCH, ptr ptr VPageBreak
COM_INTERFACE_END

COM_INTERFACE_BEG RecentFile, IDispatch, <00024407-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  get_Path, ptr BSTR
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  Open, ptr ptr Workbook
  COM_MTD_DSP  Delete
COM_INTERFACE_END

COM_INTERFACE_BEG RecentFiles, IDispatch, <00024406-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Maximum, ptr SDWORD
  COM_MTD_DSP  put_Maximum, SDWORD
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  get_Item, SDWORD, ptr ptr RecentFile
  COM_MTD_DSP  get__Default, SDWORD, ptr ptr RecentFile
  COM_MTD_DSP  Add_, BSTR, ptr ptr RecentFile
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG DocEvents, IDispatch, <00024411-0000-0000-C000-000000000046>
  COM_MTD_DSP  SelectionChange, ptr Range
  COM_MTD_DSP  BeforeDoubleClick, ptr Range, ptr BOOL
  COM_MTD_DSP  BeforeRightClick, ptr Range, ptr BOOL
  COM_MTD_DSP  Activate
  COM_MTD_DSP  Deactivate
  COM_MTD_DSP  Calculate
  COM_MTD_DSP  Change, ptr Range
  COM_MTD_DSP  FollowHyperlink, ptr Hyperlink
  COM_MTD_DSP  PivotTableUpdate, ptr PivotTable
COM_INTERFACE_END

COM_INTERFACE_BEG Style, IDispatch, <00020852-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_AddIndent, ptr BOOL
  COM_MTD_DSP  put_AddIndent, BOOL
  COM_MTD_DSP  get_BuiltIn, ptr BOOL
  COM_MTD_DSP  get_Borders, ptr ptr Borders
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  get_Font, ptr ptr Font
  COM_MTD_DSP  get_FormulaHidden, ptr BOOL
  COM_MTD_DSP  put_FormulaHidden, BOOL
  COM_MTD_DSP  get_HorizontalAlignment, ptr XlHAlign
  COM_MTD_DSP  put_HorizontalAlignment, XlHAlign
  COM_MTD_DSP  get_IncludeAlignment, ptr BOOL
  COM_MTD_DSP  put_IncludeAlignment, BOOL
  COM_MTD_DSP  get_IncludeBorder, ptr BOOL
  COM_MTD_DSP  put_IncludeBorder, BOOL
  COM_MTD_DSP  get_IncludeFont, ptr BOOL
  COM_MTD_DSP  put_IncludeFont, BOOL
  COM_MTD_DSP  get_IncludeNumber, ptr BOOL
  COM_MTD_DSP  put_IncludeNumber, BOOL
  COM_MTD_DSP  get_IncludePatterns, ptr BOOL
  COM_MTD_DSP  put_IncludePatterns, BOOL
  COM_MTD_DSP  get_IncludeProtection, ptr BOOL
  COM_MTD_DSP  put_IncludeProtection, BOOL
  COM_MTD_DSP  get_IndentLevel, ptr SDWORD
  COM_MTD_DSP  put_IndentLevel, SDWORD
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  get_MergeCells, ptr VARIANT
  COM_MTD_DSP  put_MergeCells, VARIANT
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  get_NameLocal, ptr BSTR
  COM_MTD_DSP  get_NumberFormat, ptr BSTR
  COM_MTD_DSP  put_NumberFormat, BSTR
  COM_MTD_DSP  get_NumberFormatLocal, ptr BSTR
  COM_MTD_DSP  put_NumberFormatLocal, BSTR
  COM_MTD_DSP  get_Orientation, ptr XlOrientation
  COM_MTD_DSP  put_Orientation, XlOrientation
  COM_MTD_DSP  get_ShrinkToFit, ptr BOOL
  COM_MTD_DSP  put_ShrinkToFit, BOOL
  COM_MTD_DSP  get_Value, ptr BSTR
  COM_MTD_DSP  get_VerticalAlignment, ptr XlVAlign
  COM_MTD_DSP  put_VerticalAlignment, XlVAlign
  COM_MTD_DSP  get_WrapText, ptr BOOL
  COM_MTD_DSP  put_WrapText, BOOL
  COM_MTD_DSP  get__Default, ptr BSTR
  COM_MTD_DSP  get_ReadingOrder, ptr SDWORD
  COM_MTD_DSP  put_ReadingOrder, SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG Styles, IDispatch, <00020853-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Add_, BSTR, VARIANT, ptr ptr Style
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  get_Item, VARIANT, ptr ptr Style
  COM_MTD_DSP  Merge, VARIANT, ptr VARIANT
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_DSP  get__Default, VARIANT, ptr ptr Style
COM_INTERFACE_END

COM_INTERFACE_BEG Borders, IDispatch, <00020855-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Color, ptr VARIANT
  COM_MTD_DSP  put_Color, VARIANT
  COM_MTD_DSP  get_ColorIndex, ptr VARIANT
  COM_MTD_DSP  put_ColorIndex, VARIANT
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  get_Item, XlBordersIndex, ptr ptr Border
  COM_MTD_DSP  get_LineStyle, ptr VARIANT
  COM_MTD_DSP  put_LineStyle, VARIANT
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_DSP  get_Value, ptr VARIANT
  COM_MTD_DSP  put_Value, VARIANT
  COM_MTD_DSP  get_Weight, ptr VARIANT
  COM_MTD_DSP  put_Weight, VARIANT
  COM_MTD_DSP  get__Default, XlBordersIndex, ptr ptr Border
COM_INTERFACE_END

COM_INTERFACE_BEG AddIn, IDispatch, <00020857-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Author, ptr BSTR
  COM_MTD_DSP  get_Comments, ptr BSTR
  COM_MTD_DSP  get_FullName, ptr BSTR
  COM_MTD_DSP  get_Installed, ptr BOOL
  COM_MTD_DSP  put_Installed, BOOL
  COM_MTD_DSP  get_Keywords, ptr BSTR
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  get_Path, ptr BSTR
  COM_MTD_DSP  get_Subject, ptr BSTR
  COM_MTD_DSP  get_Title, ptr BSTR
  COM_MTD_DSP  get_progID, ptr BSTR
  COM_MTD_DSP  get_CLSID, ptr BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG AddIns, IDispatch, <00020858-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Add_, BSTR, VARIANT, ptr ptr AddIn
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  get_Item, VARIANT, ptr ptr AddIn
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_DSP  get__Default, VARIANT, ptr ptr AddIn
COM_INTERFACE_END

COM_INTERFACE_BEG Toolbar, IDispatch, <0002085C-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_BuiltIn, ptr BOOL
  COM_MTD_DSP  Delete
  COM_MTD_DSP  get_Height, ptr SDWORD
  COM_MTD_DSP  put_Height, SDWORD
  COM_MTD_DSP  get_Left, ptr SDWORD
  COM_MTD_DSP  put_Left, SDWORD
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  get_Position, ptr SDWORD
  COM_MTD_DSP  put_Position, SDWORD
  COM_MTD_DSP  get_Protection, ptr XlToolbarProtection
  COM_MTD_DSP  put_Protection, XlToolbarProtection
  COM_MTD_DSP  Reset

  COM_MTD_DSP  get_ToolbarButtons, ptr ptr ToolbarButtons
  COM_MTD_DSP  get_Top, ptr SDWORD
  COM_MTD_DSP  put_Top, SDWORD
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr SDWORD
  COM_MTD_DSP  put_Width, SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG Toolbars, IDispatch, <0002085D-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Add_, VARIANT, ptr ptr Toolbar
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  get__Default, VARIANT, ptr ptr Toolbar
  COM_MTD_DSP  get_Item, VARIANT, ptr ptr Toolbar
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG ToolbarButton, IDispatch, <0002085E-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_BuiltIn, ptr BOOL
  COM_MTD_DSP  get_BuiltInFace, ptr BOOL
  COM_MTD_DSP  put_BuiltInFace, BOOL
  COM_MTD_DSP  Copy, ptr Toolbar, SDWORD
  COM_MTD_DSP  CopyFace
  COM_MTD_DSP  Delete
  COM_MTD_DSP  Edit
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_HelpContextID, ptr SDWORD
  COM_MTD_DSP  put_HelpContextID, SDWORD
  COM_MTD_DSP  get_HelpFile, ptr BSTR
  COM_MTD_DSP  put_HelpFile, BSTR
  COM_MTD_DSP  get_ID, ptr SDWORD
  COM_MTD_DSP  get_IsGap, ptr BOOL
  COM_MTD_DSP  Move, ptr Toolbar, SDWORD
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  PasteFace
  COM_MTD_DSP  get_Pushed, ptr BOOL
  COM_MTD_DSP  put_Pushed, BOOL
  COM_MTD_DSP  Reset
  COM_MTD_DSP  get_StatusBar, ptr BSTR
  COM_MTD_DSP  put_StatusBar, BSTR
  COM_MTD_DSP  get_Width, ptr SDWORD
  COM_MTD_DSP  put_Width, SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG ToolbarButtons, IDispatch, <0002085F-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Add_, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr ptr ToolbarButton
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  get_Item, SDWORD, ptr ptr ToolbarButton
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_DSP  get__Default, SDWORD, ptr ptr ToolbarButton
COM_INTERFACE_END

COM_INTERFACE_BEG Areas, IDispatch, <00020860-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  get_Item, SDWORD, ptr ptr Range
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_DSP  get__Default, SDWORD, ptr ptr Range
COM_INTERFACE_END

COM_INTERFACE_BEG WorkbookEvents, IDispatch, <00024412-0000-0000-C000-000000000046>
  COM_MTD_DSP  Open
  COM_MTD_DSP  Activate
  COM_MTD_DSP  Deactivate
  COM_MTD_DSP  BeforeClose, ptr BOOL
  COM_MTD_DSP  BeforeSave, BOOL, ptr BOOL
  COM_MTD_DSP  BeforePrint, ptr BOOL
  COM_MTD_DSP  NewSheet, LPDISPATCH
  COM_MTD_DSP  AddinInstall
  COM_MTD_DSP  AddinUninstall
  COM_MTD_DSP  WindowResize, ptr Window
  COM_MTD_DSP  WindowActivate, ptr Window
  COM_MTD_DSP  WindowDeactivate, ptr Window
  COM_MTD_DSP  SheetSelectionChange, LPDISPATCH, ptr Range
  COM_MTD_DSP  SheetBeforeDoubleClick, LPDISPATCH, ptr Range, ptr BOOL
  COM_MTD_DSP  SheetBeforeRightClick, LPDISPATCH, ptr Range, ptr BOOL
  COM_MTD_DSP  SheetActivate, LPDISPATCH
  COM_MTD_DSP  SheetDeactivate, LPDISPATCH
  COM_MTD_DSP  SheetCalculate, LPDISPATCH
  COM_MTD_DSP  SheetChange, LPDISPATCH, ptr Range
  COM_MTD_DSP  SheetFollowHyperlink, LPDISPATCH, ptr Hyperlink
  COM_MTD_DSP  SheetPivotTableUpdate, LPDISPATCH, ptr PivotTable
  COM_MTD_DSP  PivotTableCloseConnection, ptr PivotTable
  COM_MTD_DSP  PivotTableOpenConnection, ptr PivotTable
COM_INTERFACE_END

COM_INTERFACE_BEG MenuBars, IDispatch, <00020863-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Add_, VARIANT, ptr ptr MenuBar
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  get__Default, VARIANT, ptr ptr MenuBar
  COM_MTD_DSP  get_Item, VARIANT, ptr ptr MenuBar
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG MenuBar, IDispatch, <00020864-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Activate
  COM_MTD_DSP  get_BuiltIn, ptr BOOL
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  Delete
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  get_Menus, ptr ptr Menus
  COM_MTD_DSP  Reset
COM_INTERFACE_END

COM_INTERFACE_BEG Menus, IDispatch, <00020865-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Add_, BSTR, VARIANT, VARIANT, ptr ptr Menu
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  get__Default, VARIANT, ptr ptr Menu
  COM_MTD_DSP  get_Item, VARIANT, ptr ptr Menu
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG Menu, IDispatch, <00020866-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  Delete
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  get_MenuItems, ptr ptr MenuItems
COM_INTERFACE_END

COM_INTERFACE_BEG MenuItems, IDispatch, <00020867-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Add_, BSTR, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr ptr MenuItem
  COM_MTD_DSP  AddMenu, BSTR, VARIANT, VARIANT, ptr ptr Menu
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  get__Default, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  get_Item, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG MenuItem, IDispatch, <00020868-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_Checked, ptr BOOL
  COM_MTD_DSP  put_Checked, BOOL
  COM_MTD_DSP  Delete
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_HelpContextID, ptr SDWORD
  COM_MTD_DSP  put_HelpContextID, SDWORD
  COM_MTD_DSP  get_HelpFile, ptr BSTR
  COM_MTD_DSP  put_HelpFile, BSTR
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_StatusBar, ptr BSTR
  COM_MTD_DSP  put_StatusBar, BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG Charts, IDispatch, <0002086D-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Add_, VARIANT, VARIANT, VARIANT, ptr ptr Chart
  COM_MTD_DSP  Copy, VARIANT, VARIANT
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Delete
  COM_MTD_DSP  _Dummy7
  COM_MTD_DSP  get_Item, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  Move, VARIANT, VARIANT
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_DSP  _PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_DSP  PrintPreview, VARIANT
  COM_MTD_DSP  Select, VARIANT
  COM_MTD_DSP  get_HPageBreaks, ptr ptr HPageBreaks
  COM_MTD_DSP  get_VPageBreaks, ptr ptr VPageBreaks
  COM_MTD_DSP  get_Visible, ptr VARIANT
  COM_MTD_DSP  put_Visible, VARIANT
  COM_MTD_DSP  get__Default, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG DrawingObjects, IDispatch, <0002086F-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  _Dummy3
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  _Dummy12
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  _Dummy15
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  _Dummy22
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get_Accelerator, ptr VARIANT
  COM_MTD_DSP  put_Accelerator, VARIANT
  COM_MTD_DSP  _Dummy28
  COM_MTD_DSP  get_AddIndent, ptr BOOL
  COM_MTD_DSP  put_AddIndent, BOOL
  COM_MTD_DSP  AddItem, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_ArrowHeadLength, ptr VARIANT
  COM_MTD_DSP  put_ArrowHeadLength, VARIANT
  COM_MTD_DSP  get_ArrowHeadStyle, ptr VARIANT
  COM_MTD_DSP  put_ArrowHeadStyle, VARIANT
  COM_MTD_DSP  get_ArrowHeadWidth, ptr VARIANT
  COM_MTD_DSP  put_ArrowHeadWidth, VARIANT
  COM_MTD_DSP  get_AutoSize, ptr BOOL
  COM_MTD_DSP  put_AutoSize, BOOL
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  get_CancelButton, ptr BOOL
  COM_MTD_DSP  put_CancelButton, BOOL
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_DSP  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get__Default, ptr SDWORD
  COM_MTD_DSP  put__Default, SDWORD
  COM_MTD_DSP  get_DefaultButton, ptr BOOL
  COM_MTD_DSP  put_DefaultButton, BOOL
  COM_MTD_DSP  get_DismissButton, ptr BOOL
  COM_MTD_DSP  put_DismissButton, BOOL
  COM_MTD_DSP  get_Display3DShading, ptr BOOL
  COM_MTD_DSP  put_Display3DShading, BOOL
  COM_MTD_DSP  get_DisplayVerticalScrollBar, ptr BOOL
  COM_MTD_DSP  put_DisplayVerticalScrollBar, BOOL
  COM_MTD_DSP  get_DropDownLines, ptr SDWORD
  COM_MTD_DSP  put_DropDownLines, SDWORD
  COM_MTD_DSP  get_Font, ptr ptr Font
  COM_MTD_DSP  _Dummy47
  COM_MTD_DSP  get_HelpButton, ptr BOOL
  COM_MTD_DSP  put_HelpButton, BOOL
  COM_MTD_DSP  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_DSP  put_HorizontalAlignment, VARIANT
  COM_MTD_DSP  get_InputType, ptr SDWORD
  COM_MTD_DSP  put_InputType, SDWORD
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_LargeChange, ptr SDWORD
  COM_MTD_DSP  put_LargeChange, SDWORD
  COM_MTD_DSP  get_LinkedCell, ptr BSTR
  COM_MTD_DSP  put_LinkedCell, BSTR
  COM_MTD_DSP  _Dummy54
  COM_MTD_DSP  List, VARIANT, ptr VARIANT
  COM_MTD_DSP  _Dummy56
  COM_MTD_DSP  get_ListFillRange, ptr BSTR
  COM_MTD_DSP  put_ListFillRange, BSTR
  COM_MTD_DSP  get_ListIndex, ptr SDWORD
  COM_MTD_DSP  put_ListIndex, SDWORD
  COM_MTD_DSP  get_LockedText, ptr BOOL
  COM_MTD_DSP  put_LockedText, BOOL
  COM_MTD_DSP  get_Max, ptr SDWORD
  COM_MTD_DSP  put_Max, SDWORD
  COM_MTD_DSP  get_Min, ptr SDWORD
  COM_MTD_DSP  put_Min, SDWORD
  COM_MTD_DSP  get_MultiLine, ptr BOOL
  COM_MTD_DSP  put_MultiLine, BOOL
  COM_MTD_DSP  get_MultiSelect, ptr BOOL
  COM_MTD_DSP  put_MultiSelect, BOOL
  COM_MTD_DSP  get_Orientation, ptr VARIANT
  COM_MTD_DSP  put_Orientation, VARIANT
  COM_MTD_DSP  get_PhoneticAccelerator, ptr VARIANT
  COM_MTD_DSP  put_PhoneticAccelerator, VARIANT
  COM_MTD_DSP  RemoveAllItems, ptr VARIANT
  COM_MTD_DSP  RemoveItem, SDWORD, VARIANT, ptr VARIANT
  COM_MTD_DSP  Reshape, SDWORD, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_RoundedCorners, ptr BOOL
  COM_MTD_DSP  put_RoundedCorners, BOOL
  COM_MTD_DSP  Selected, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_Shadow, ptr BOOL
  COM_MTD_DSP  put_Shadow, BOOL
  COM_MTD_DSP  get_SmallChange, ptr SDWORD
  COM_MTD_DSP  put_SmallChange, SDWORD
  COM_MTD_DSP  get_Text, ptr BSTR
  COM_MTD_DSP  put_Text, BSTR
  COM_MTD_DSP  Ungroup, ptr LPDISPATCH
  COM_MTD_DSP  get_Value, ptr SDWORD
  COM_MTD_DSP  put_Value, SDWORD
  COM_MTD_DSP  get_VerticalAlignment, ptr VARIANT
  COM_MTD_DSP  put_VerticalAlignment, VARIANT
  COM_MTD_DSP  Vertices, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_ReadingOrder, ptr SDWORD
  COM_MTD_DSP  put_ReadingOrder, SDWORD
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  Group_, ptr ptr GroupObject
  COM_MTD_DSP  LinkCombo, VARIANT, ptr VARIANT
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG PivotCache, IDispatch, <0002441C-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_BackgroundQuery, ptr BOOL
  COM_MTD_DSP  put_BackgroundQuery, BOOL
  COM_MTD_DSP  get_Connection, ptr VARIANT
  COM_MTD_DSP  put_Connection, VARIANT
  COM_MTD_DSP  get_EnableRefresh, ptr BOOL
  COM_MTD_DSP  put_EnableRefresh, BOOL
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  get_MemoryUsed, ptr SDWORD
  COM_MTD_DSP  get_OptimizeCache, ptr BOOL
  COM_MTD_DSP  put_OptimizeCache, BOOL
  COM_MTD_DSP  get_RecordCount, ptr SDWORD
  COM_MTD_DSP  Refresh
  COM_MTD_DSP  get_RefreshDate, ptr Date
  COM_MTD_DSP  get_RefreshName, ptr BSTR
  COM_MTD_DSP  get_RefreshOnFileOpen, ptr BOOL
  COM_MTD_DSP  put_RefreshOnFileOpen, BOOL
  COM_MTD_DSP  get_Sql, ptr VARIANT
  COM_MTD_DSP  put_Sql, VARIANT
  COM_MTD_DSP  get_SavePassword, ptr BOOL
  COM_MTD_DSP  put_SavePassword, BOOL
  COM_MTD_DSP  get_SourceData, ptr VARIANT
  COM_MTD_DSP  put_SourceData, VARIANT
  COM_MTD_DSP  get_CommandText, ptr VARIANT
  COM_MTD_DSP  put_CommandText, VARIANT
  COM_MTD_DSP  get_CommandType, ptr XlCmdType
  COM_MTD_DSP  put_CommandType, XlCmdType
  COM_MTD_DSP  get_QueryType, ptr XlQueryType
  COM_MTD_DSP  get_MaintainConnection, ptr BOOL
  COM_MTD_DSP  put_MaintainConnection, BOOL
  COM_MTD_DSP  get_RefreshPeriod, ptr SDWORD
  COM_MTD_DSP  put_RefreshPeriod, SDWORD
  COM_MTD_DSP  get_Recordset, ptr LPDISPATCH
  COM_MTD_DSP  putref_Recordset, LPDISPATCH
  COM_MTD_DSP  ResetTimer
  COM_MTD_DSP  get_LocalConnection, ptr VARIANT
  COM_MTD_DSP  put_LocalConnection, VARIANT
  COM_MTD_DSP  CreatePivotTable, VARIANT, VARIANT, VARIANT, VARIANT, ptr ptr PivotTable
  COM_MTD_DSP  get_UseLocalConnection, ptr BOOL
  COM_MTD_DSP  put_UseLocalConnection, BOOL
  COM_MTD_DSP  get_ADOConnection, ptr LPDISPATCH
  COM_MTD_DSP  get_IsConnected, ptr BOOL
  COM_MTD_DSP  MakeConnection
  COM_MTD_DSP  get_OLAP, ptr BOOL
  COM_MTD_DSP  get_SourceType, ptr XlPivotTableSourceType
  COM_MTD_DSP  get_MissingItemsLimit, ptr XlPivotTableMissingItems
  COM_MTD_DSP  put_MissingItemsLimit, XlPivotTableMissingItems
  COM_MTD_DSP  get_SourceConnectionFile, ptr BSTR
  COM_MTD_DSP  put_SourceConnectionFile, BSTR
  COM_MTD_DSP  get_SourceDataFile, ptr BSTR
  COM_MTD_DSP  get_RobustConnect, ptr XlRobustConnect
  COM_MTD_DSP  put_RobustConnect, XlRobustConnect
  COM_MTD_DSP  SaveAsODC, BSTR, VARIANT, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG PivotCaches, IDispatch, <0002441D-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Item, VARIANT, ptr ptr PivotCache
  COM_MTD_DSP  get__Default, VARIANT, ptr ptr PivotCache
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
  COM_MTD_DSP  Add_, XlPivotTableSourceType, VARIANT, ptr ptr PivotCache
COM_INTERFACE_END

COM_INTERFACE_BEG PivotFormula, IDispatch, <0002441E-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Delete
  COM_MTD_DSP  get__Default, ptr BSTR
  COM_MTD_DSP  put__Default, BSTR
  COM_MTD_DSP  get_Formula, ptr BSTR
  COM_MTD_DSP  put_Formula, BSTR
  COM_MTD_DSP  get_Value, ptr BSTR
  COM_MTD_DSP  put_Value, BSTR
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  put_Index, SDWORD
  COM_MTD_DSP  get_StandardFormula, ptr BSTR
  COM_MTD_DSP  put_StandardFormula, BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG PivotFormulas, IDispatch, <0002441F-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  _Add, BSTR, ptr ptr PivotFormula
  COM_MTD_DSP  Item, VARIANT, ptr ptr PivotFormula
  COM_MTD_DSP  get__Default, VARIANT, ptr ptr PivotFormula
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
  COM_MTD_DSP  Add_, BSTR, VARIANT, ptr ptr PivotFormula
COM_INTERFACE_END

COM_INTERFACE_BEG PivotTable, IDispatch, <00020872-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  AddFields, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_ColumnFields, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  get_ColumnGrand, ptr BOOL
  COM_MTD_DSP  put_ColumnGrand, BOOL
  COM_MTD_DSP  get_ColumnRange, ptr ptr Range
  COM_MTD_DSP  ShowPages, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_DataBodyRange, ptr ptr Range
  COM_MTD_DSP  get_DataFields, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  get_DataLabelRange, ptr ptr Range
  COM_MTD_DSP  get__Default, ptr BSTR
  COM_MTD_DSP  put__Default, BSTR
  COM_MTD_DSP  get_HasAutoFormat, ptr BOOL
  COM_MTD_DSP  put_HasAutoFormat, BOOL
  COM_MTD_DSP  get_HiddenFields, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  get_InnerDetail, ptr BSTR
  COM_MTD_DSP  put_InnerDetail, BSTR
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  get_PageFields, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  get_PageRange, ptr ptr Range
  COM_MTD_DSP  get_PageRangeCells, ptr ptr Range
  COM_MTD_DSP  PivotFields, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  get_RefreshDate, ptr Date
  COM_MTD_DSP  get_RefreshName, ptr BSTR
  COM_MTD_DSP  RefreshTable, ptr BOOL
  COM_MTD_DSP  get_RowFields, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  get_RowGrand, ptr BOOL
  COM_MTD_DSP  put_RowGrand, BOOL
  COM_MTD_DSP  get_RowRange, ptr ptr Range
  COM_MTD_DSP  get_SaveData, ptr BOOL
  COM_MTD_DSP  put_SaveData, BOOL
  COM_MTD_DSP  get_SourceData, ptr VARIANT
  COM_MTD_DSP  put_SourceData, VARIANT
  COM_MTD_DSP  get_TableRange1, ptr ptr Range
  COM_MTD_DSP  get_TableRange2, ptr ptr Range
  COM_MTD_DSP  get_Value, ptr BSTR
  COM_MTD_DSP  put_Value, BSTR
  COM_MTD_DSP  get_VisibleFields, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  get_CacheIndex, ptr SDWORD
  COM_MTD_DSP  put_CacheIndex, SDWORD
  COM_MTD_DSP  CalculatedFields, ptr ptr CalculatedFields
  COM_MTD_DSP  get_DisplayErrorString, ptr BOOL
  COM_MTD_DSP  put_DisplayErrorString, BOOL
  COM_MTD_DSP  get_DisplayNullString, ptr BOOL
  COM_MTD_DSP  put_DisplayNullString, BOOL
  COM_MTD_DSP  get_EnableDrilldown, ptr BOOL
  COM_MTD_DSP  put_EnableDrilldown, BOOL
  COM_MTD_DSP  get_EnableFieldDialog, ptr BOOL
  COM_MTD_DSP  put_EnableFieldDialog, BOOL
  COM_MTD_DSP  get_EnableWizard, ptr BOOL
  COM_MTD_DSP  put_EnableWizard, BOOL
  COM_MTD_DSP  get_ErrorString, ptr BSTR
  COM_MTD_DSP  put_ErrorString, BSTR
  COM_MTD_DSP  GetData, BSTR, ptr REAL8
  COM_MTD_DSP  ListFormulas
  COM_MTD_DSP  get_ManualUpdate, ptr BOOL
  COM_MTD_DSP  put_ManualUpdate, BOOL
  COM_MTD_DSP  get_MergeLabels, ptr BOOL
  COM_MTD_DSP  put_MergeLabels, BOOL
  COM_MTD_DSP  get_NullString, ptr BSTR
  COM_MTD_DSP  put_NullString, BSTR
  COM_MTD_DSP  PivotCache, ptr ptr PivotCache
  COM_MTD_DSP  get_PivotFormulas, ptr ptr PivotFormulas
  COM_MTD_DSP  PivotTableWizard, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_DSP  get_SubtotalHiddenPageItems, ptr BOOL
  COM_MTD_DSP  put_SubtotalHiddenPageItems, BOOL
  COM_MTD_DSP  get_PageFieldOrder, ptr SDWORD
  COM_MTD_DSP  put_PageFieldOrder, SDWORD
  COM_MTD_DSP  get_PageFieldStyle, ptr BSTR
  COM_MTD_DSP  put_PageFieldStyle, BSTR
  COM_MTD_DSP  get_PageFieldWrapCount, ptr SDWORD
  COM_MTD_DSP  put_PageFieldWrapCount, SDWORD
  COM_MTD_DSP  get_PreserveFormatting, ptr BOOL
  COM_MTD_DSP  put_PreserveFormatting, BOOL
  COM_MTD_DSP  _PivotSelect, BSTR, XlPTSelectionMode
  COM_MTD_DSP  get_PivotSelection, ptr BSTR
  COM_MTD_DSP  put_PivotSelection, BSTR
  COM_MTD_DSP  get_SelectionMode, ptr XlPTSelectionMode
  COM_MTD_DSP  put_SelectionMode, XlPTSelectionMode
  COM_MTD_DSP  get_TableStyle, ptr BSTR
  COM_MTD_DSP  put_TableStyle, BSTR
  COM_MTD_DSP  get_Tag, ptr BSTR
  COM_MTD_DSP  put_Tag, BSTR
  COM_MTD_DSP  Update
  COM_MTD_DSP  get_VacatedStyle, ptr BSTR
  COM_MTD_DSP  put_VacatedStyle, BSTR
  COM_MTD_DSP  Format, XlPivotFormatType
  COM_MTD_DSP  get_PrintTitles, ptr BOOL
  COM_MTD_DSP  put_PrintTitles, BOOL
  COM_MTD_DSP  get_CubeFields, ptr ptr CubeFields
  COM_MTD_DSP  get_GrandTotalName, ptr BSTR
  COM_MTD_DSP  put_GrandTotalName, BSTR
  COM_MTD_DSP  get_SmallGrid, ptr BOOL
  COM_MTD_DSP  put_SmallGrid, BOOL
  COM_MTD_DSP  get_RepeatItemsOnEachPrintedPage, ptr BOOL
  COM_MTD_DSP  put_RepeatItemsOnEachPrintedPage, BOOL
  COM_MTD_DSP  get_TotalsAnnotation, ptr BOOL
  COM_MTD_DSP  put_TotalsAnnotation, BOOL
  COM_MTD_DSP  PivotSelect, BSTR, XlPTSelectionMode, VARIANT
  COM_MTD_DSP  get_PivotSelectionStandard, ptr BSTR
  COM_MTD_DSP  put_PivotSelectionStandard, BSTR
;+++   COM_MTD_DSP  GetPivotData, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr ptr Range
  COM_MTD_DSP  get_DataPivotField, ptr ptr PivotField
  COM_MTD_DSP  get_EnableDataValueEditing, ptr BOOL
  COM_MTD_DSP  put_EnableDataValueEditing, BOOL
  COM_MTD_DSP  AddDataField, LPDISPATCH, VARIANT, VARIANT, ptr ptr PivotField
  COM_MTD_DSP  get_MDX, ptr BSTR
  COM_MTD_DSP  get_ViewCalculatedMembers, ptr BOOL
  COM_MTD_DSP  put_ViewCalculatedMembers, BOOL
  COM_MTD_DSP  get_CalculatedMembers, ptr ptr CalculatedMembers
  COM_MTD_DSP  get_DisplayImmediateItems, ptr BOOL
  COM_MTD_DSP  put_DisplayImmediateItems, BOOL
;+++   COM_MTD_DSP  Dummy15, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_EnableFieldList, ptr BOOL
  COM_MTD_DSP  put_EnableFieldList, BOOL
  COM_MTD_DSP  get_VisualTotals, ptr BOOL
  COM_MTD_DSP  put_VisualTotals, BOOL
  COM_MTD_DSP  get_ShowPageMultipleItemLabel, ptr BOOL
  COM_MTD_DSP  put_ShowPageMultipleItemLabel, BOOL
  COM_MTD_DSP  get_Version, ptr XlPivotTableVersionList
  COM_MTD_DSP  CreateCubeFile, BSTR, VARIANT, VARIANT, VARIANT, VARIANT, ptr BSTR
  COM_MTD_DSP  get_DisplayEmptyRow, ptr BOOL
  COM_MTD_DSP  put_DisplayEmptyRow, BOOL
  COM_MTD_DSP  get_DisplayEmptyColumn, ptr BOOL
  COM_MTD_DSP  put_DisplayEmptyColumn, BOOL
  COM_MTD_DSP  get_ShowCellBackgroundFromOLAP, ptr BOOL
  COM_MTD_DSP  put_ShowCellBackgroundFromOLAP, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG PivotTables, IDispatch, <00020873-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Item, VARIANT, ptr ptr PivotTable
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
  COM_MTD_DSP  Add_, ptr PivotCache, VARIANT, VARIANT, VARIANT, VARIANT, ptr ptr PivotTable
COM_INTERFACE_END

COM_INTERFACE_BEG PivotField, IDispatch, <00020874-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Calculation, ptr XlPivotFieldCalculation
  COM_MTD_DSP  put_Calculation, XlPivotFieldCalculation
  COM_MTD_DSP  get_ChildField, ptr ptr PivotField
  COM_MTD_DSP  get_ChildItems, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_CurrentPage, ptr VARIANT
  COM_MTD_DSP  put_CurrentPage, VARIANT
  COM_MTD_DSP  get_DataRange, ptr ptr Range
  COM_MTD_DSP  get_DataType, ptr XlPivotFieldDataType
  COM_MTD_DSP  get__Default, ptr BSTR
  COM_MTD_DSP  put__Default, BSTR
  COM_MTD_DSP  get_Function, ptr XlConsolidationFunction
  COM_MTD_DSP  put_Function, XlConsolidationFunction
  COM_MTD_DSP  get_GroupLevel, ptr VARIANT
  COM_MTD_DSP  get_HiddenItems, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_LabelRange, ptr ptr Range
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  get_NumberFormat, ptr BSTR
  COM_MTD_DSP  put_NumberFormat, BSTR
  COM_MTD_DSP  get_Orientation, ptr XlPivotFieldOrientation
  COM_MTD_DSP  put_Orientation, XlPivotFieldOrientation
  COM_MTD_DSP  get_ShowAllItems, ptr BOOL
  COM_MTD_DSP  put_ShowAllItems, BOOL
  COM_MTD_DSP  get_ParentField, ptr ptr PivotField
  COM_MTD_DSP  get_ParentItems, VARIANT, ptr VARIANT
  COM_MTD_DSP  PivotItems, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_Position, ptr VARIANT
  COM_MTD_DSP  put_Position, VARIANT
  COM_MTD_DSP  get_SourceName, ptr BSTR
  COM_MTD_DSP  get_Subtotals, VARIANT, ptr VARIANT
  COM_MTD_DSP  put_Subtotals, VARIANT, VARIANT
  COM_MTD_DSP  get_BaseField, ptr VARIANT
  COM_MTD_DSP  put_BaseField, VARIANT
  COM_MTD_DSP  get_BaseItem, ptr VARIANT
  COM_MTD_DSP  put_BaseItem, VARIANT
  COM_MTD_DSP  get_TotalLevels, ptr VARIANT
  COM_MTD_DSP  get_Value, ptr BSTR
  COM_MTD_DSP  put_Value, BSTR
  COM_MTD_DSP  get_VisibleItems, VARIANT, ptr VARIANT
  COM_MTD_DSP  CalculatedItems, ptr ptr CalculatedItems
  COM_MTD_DSP  Delete
  COM_MTD_DSP  get_DragToColumn, ptr BOOL
  COM_MTD_DSP  put_DragToColumn, BOOL
  COM_MTD_DSP  get_DragToHide, ptr BOOL
  COM_MTD_DSP  put_DragToHide, BOOL
  COM_MTD_DSP  get_DragToPage, ptr BOOL
  COM_MTD_DSP  put_DragToPage, BOOL
  COM_MTD_DSP  get_DragToRow, ptr BOOL
  COM_MTD_DSP  put_DragToRow, BOOL
  COM_MTD_DSP  get_DragToData, ptr BOOL
  COM_MTD_DSP  put_DragToData, BOOL
  COM_MTD_DSP  get_Formula, ptr BSTR
  COM_MTD_DSP  put_Formula, BSTR
  COM_MTD_DSP  get_IsCalculated, ptr BOOL
  COM_MTD_DSP  get_MemoryUsed, ptr SDWORD
  COM_MTD_DSP  get_ServerBased, ptr BOOL
  COM_MTD_DSP  put_ServerBased, BOOL
  COM_MTD_DSP  AutoSort, SDWORD, BSTR
  COM_MTD_DSP  AutoShow, SDWORD, SDWORD, SDWORD, BSTR
  COM_MTD_DSP  get_AutoSortOrder, ptr SDWORD
  COM_MTD_DSP  get_AutoSortField, ptr BSTR
  COM_MTD_DSP  get_AutoShowType, ptr SDWORD
  COM_MTD_DSP  get_AutoShowRange, ptr SDWORD
  COM_MTD_DSP  get_AutoShowCount, ptr SDWORD
  COM_MTD_DSP  get_AutoShowField, ptr BSTR
  COM_MTD_DSP  get_LayoutBlankLine, ptr BOOL
  COM_MTD_DSP  put_LayoutBlankLine, BOOL
  COM_MTD_DSP  get_LayoutSubtotalLocation, ptr XlSubtototalLocationType
  COM_MTD_DSP  put_LayoutSubtotalLocation, XlSubtototalLocationType
  COM_MTD_DSP  get_LayoutPageBreak, ptr BOOL
  COM_MTD_DSP  put_LayoutPageBreak, BOOL
  COM_MTD_DSP  get_LayoutForm, ptr XlLayoutFormType
  COM_MTD_DSP  put_LayoutForm, XlLayoutFormType
  COM_MTD_DSP  get_SubtotalName, ptr BSTR
  COM_MTD_DSP  put_SubtotalName, BSTR
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_DrilledDown, ptr BOOL
  COM_MTD_DSP  put_DrilledDown, BOOL
  COM_MTD_DSP  get_CubeField, ptr ptr CubeField
  COM_MTD_DSP  get_CurrentPageName, ptr BSTR
  COM_MTD_DSP  put_CurrentPageName, BSTR
  COM_MTD_DSP  get_StandardFormula, ptr BSTR
  COM_MTD_DSP  put_StandardFormula, BSTR
  COM_MTD_DSP  get_HiddenItemsList, ptr VARIANT
  COM_MTD_DSP  put_HiddenItemsList, VARIANT
  COM_MTD_DSP  get_DatabaseSort, ptr BOOL
  COM_MTD_DSP  put_DatabaseSort, BOOL
  COM_MTD_DSP  get_IsMemberProperty, ptr BOOL
  COM_MTD_DSP  get_PropertyParentField, ptr ptr PivotField
  COM_MTD_DSP  get_PropertyOrder, ptr SDWORD
  COM_MTD_DSP  put_PropertyOrder, SDWORD
  COM_MTD_DSP  get_EnableItemSelection, ptr BOOL
  COM_MTD_DSP  put_EnableItemSelection, BOOL
  COM_MTD_DSP  get_CurrentPageList, ptr VARIANT
  COM_MTD_DSP  put_CurrentPageList, VARIANT
  COM_MTD_DSP  AddPageItem, BSTR, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG PivotFields, IDispatch, <00020875-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr ptr PivotTable
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG CalculatedFields, IDispatch, <00024420-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  _Add, BSTR, BSTR, ptr ptr PivotField
  COM_MTD_DSP  Item, VARIANT, ptr ptr PivotField
  COM_MTD_DSP  get__Default, VARIANT, ptr ptr PivotField
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
  COM_MTD_DSP  Add_, BSTR, BSTR, VARIANT, ptr ptr PivotField
COM_INTERFACE_END

COM_INTERFACE_BEG PivotItem, IDispatch, <00020876-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr ptr PivotField
  COM_MTD_DSP  get_ChildItems, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_DataRange, ptr ptr Range
  COM_MTD_DSP  get__Default, ptr BSTR
  COM_MTD_DSP  put__Default, BSTR
  COM_MTD_DSP  get_LabelRange, ptr ptr Range
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  get_ParentItem, ptr ptr PivotItem
  COM_MTD_DSP  get_ParentShowDetail, ptr BOOL
  COM_MTD_DSP  get_Position, ptr SDWORD
  COM_MTD_DSP  put_Position, SDWORD
  COM_MTD_DSP  get_ShowDetail, ptr BOOL
  COM_MTD_DSP  put_ShowDetail, BOOL
  COM_MTD_DSP  get_SourceName, ptr VARIANT
  COM_MTD_DSP  get_Value, ptr BSTR
  COM_MTD_DSP  put_Value, BSTR
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  Delete
  COM_MTD_DSP  get_IsCalculated, ptr BOOL
  COM_MTD_DSP  get_RecordCount, ptr SDWORD
  COM_MTD_DSP  get_Formula, ptr BSTR
  COM_MTD_DSP  put_Formula, BSTR
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_DrilledDown, ptr BOOL
  COM_MTD_DSP  put_DrilledDown, BOOL
  COM_MTD_DSP  get_StandardFormula, ptr BSTR
  COM_MTD_DSP  put_StandardFormula, BSTR
  COM_MTD_DSP  get_SourceNameStandard, ptr BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG PivotItems, IDispatch, <00020877-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr ptr PivotField
  COM_MTD_DSP  Add_, BSTR
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG CalculatedItems, IDispatch, <00024421-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  _Add, BSTR, BSTR, ptr ptr PivotItem
  COM_MTD_DSP  Item, VARIANT, ptr ptr PivotItem
  COM_MTD_DSP  get__Default, VARIANT, ptr ptr PivotItem
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
  COM_MTD_DSP  Add_, BSTR, BSTR, VARIANT, ptr ptr PivotItem
COM_INTERFACE_END

COM_INTERFACE_BEG Characters, IDispatch, <00020878-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  get_Font, ptr ptr Font
  COM_MTD_DSP  Insert, BSTR, ptr VARIANT
  COM_MTD_DSP  get_Text, ptr BSTR
  COM_MTD_DSP  put_Text, BSTR
  COM_MTD_DSP  get_PhoneticCharacters, ptr BSTR
  COM_MTD_DSP  put_PhoneticCharacters, BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG Dialogs, IDispatch, <00020879-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  get_Item, XlBuiltInDialog, ptr ptr Dialog
  COM_MTD_DSP  get__Default, XlBuiltInDialog, ptr ptr Dialog
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG Dialog, IDispatch, <0002087A-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
;+++   COM_MTD_DSP  Show, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG SoundNote, IDispatch, <0002087B-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Import, BSTR, ptr VARIANT
  COM_MTD_DSP  Play, ptr VARIANT
  COM_MTD_DSP  Record_, ptr VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG Button, IDispatch, <0002087D-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_BottomRightCell, ptr ptr Range
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  get_TopLeftCell, ptr ptr Range
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get_AddIndent, ptr BOOL
  COM_MTD_DSP  put_AddIndent, BOOL
  COM_MTD_DSP  get_AutoScaleFont, ptr VARIANT
  COM_MTD_DSP  put_AutoScaleFont, VARIANT
  COM_MTD_DSP  get_AutoSize, ptr BOOL
  COM_MTD_DSP  put_AutoSize, BOOL
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_DSP  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_Font, ptr ptr Font
  COM_MTD_DSP  get_Formula, ptr BSTR
  COM_MTD_DSP  put_Formula, BSTR
  COM_MTD_DSP  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_DSP  put_HorizontalAlignment, VARIANT
  COM_MTD_DSP  get_LockedText, ptr BOOL
  COM_MTD_DSP  put_LockedText, BOOL
  COM_MTD_DSP  get_Orientation, ptr VARIANT
  COM_MTD_DSP  put_Orientation, VARIANT
  COM_MTD_DSP  get_Text, ptr BSTR
  COM_MTD_DSP  put_Text, BSTR
  COM_MTD_DSP  get_VerticalAlignment, ptr VARIANT
  COM_MTD_DSP  put_VerticalAlignment, VARIANT
  COM_MTD_DSP  get_ReadingOrder, ptr SDWORD
  COM_MTD_DSP  put_ReadingOrder, SDWORD
  COM_MTD_DSP  get_Accelerator, ptr VARIANT
  COM_MTD_DSP  put_Accelerator, VARIANT
  COM_MTD_DSP  get_CancelButton, ptr BOOL
  COM_MTD_DSP  put_CancelButton, BOOL
  COM_MTD_DSP  get_DefaultButton, ptr BOOL
  COM_MTD_DSP  put_DefaultButton, BOOL
  COM_MTD_DSP  get_DismissButton, ptr BOOL
  COM_MTD_DSP  put_DismissButton, BOOL
  COM_MTD_DSP  get_HelpButton, ptr BOOL
  COM_MTD_DSP  put_HelpButton, BOOL
  COM_MTD_DSP  get_PhoneticAccelerator, ptr VARIANT
  COM_MTD_DSP  put_PhoneticAccelerator, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG Buttons, IDispatch, <0002087E-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  _Dummy3
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  _Dummy12
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  _Dummy15
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  _Dummy22
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get_AddIndent, ptr BOOL
  COM_MTD_DSP  put_AddIndent, BOOL
  COM_MTD_DSP  get_AutoScaleFont, ptr VARIANT
  COM_MTD_DSP  put_AutoScaleFont, VARIANT
  COM_MTD_DSP  get_AutoSize, ptr BOOL
  COM_MTD_DSP  put_AutoSize, BOOL
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_DSP  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_Font, ptr ptr Font
  COM_MTD_DSP  get_Formula, ptr BSTR
  COM_MTD_DSP  put_Formula, BSTR
  COM_MTD_DSP  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_DSP  put_HorizontalAlignment, VARIANT
  COM_MTD_DSP  get_LockedText, ptr BOOL
  COM_MTD_DSP  put_LockedText, BOOL
  COM_MTD_DSP  get_Orientation, ptr VARIANT
  COM_MTD_DSP  put_Orientation, VARIANT
  COM_MTD_DSP  get_Text, ptr BSTR
  COM_MTD_DSP  put_Text, BSTR
  COM_MTD_DSP  get_VerticalAlignment, ptr VARIANT
  COM_MTD_DSP  put_VerticalAlignment, VARIANT
  COM_MTD_DSP  get_ReadingOrder, ptr SDWORD
  COM_MTD_DSP  put_ReadingOrder, SDWORD
  COM_MTD_DSP  get_Accelerator, ptr VARIANT
  COM_MTD_DSP  put_Accelerator, VARIANT
  COM_MTD_DSP  get_CancelButton, ptr BOOL
  COM_MTD_DSP  put_CancelButton, BOOL
  COM_MTD_DSP  get_DefaultButton, ptr BOOL
  COM_MTD_DSP  put_DefaultButton, BOOL
  COM_MTD_DSP  get_DismissButton, ptr BOOL
  COM_MTD_DSP  put_DismissButton, BOOL
  COM_MTD_DSP  get_HelpButton, ptr BOOL
  COM_MTD_DSP  put_HelpButton, BOOL
  COM_MTD_DSP  get_PhoneticAccelerator, ptr VARIANT
  COM_MTD_DSP  put_PhoneticAccelerator, VARIANT
  COM_MTD_DSP  Add_, REAL8, REAL8, REAL8, REAL8, ptr ptr Button
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Group_, ptr ptr GroupObject
  COM_MTD_DSP  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG CheckBox, IDispatch, <0002087F-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_BottomRightCell, ptr ptr Range
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  get_TopLeftCell, ptr ptr Range
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_DSP  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_LockedText, ptr BOOL
  COM_MTD_DSP  put_LockedText, BOOL
  COM_MTD_DSP  get_Text, ptr BSTR
  COM_MTD_DSP  put_Text, BSTR
  COM_MTD_DSP  get_Accelerator, ptr VARIANT
  COM_MTD_DSP  put_Accelerator, VARIANT
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  get__Default, ptr SDWORD
  COM_MTD_DSP  put__Default, SDWORD
  COM_MTD_DSP  get_Display3DShading, ptr BOOL
  COM_MTD_DSP  put_Display3DShading, BOOL
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_LinkedCell, ptr BSTR
  COM_MTD_DSP  put_LinkedCell, BSTR
  COM_MTD_DSP  get_PhoneticAccelerator, ptr VARIANT
  COM_MTD_DSP  put_PhoneticAccelerator, VARIANT
  COM_MTD_DSP  get_Value, ptr VARIANT
  COM_MTD_DSP  put_Value, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG CheckBoxes, IDispatch, <00020880-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  _Dummy3
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  _Dummy12
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  _Dummy15
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  _Dummy22
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_DSP  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_LockedText, ptr BOOL
  COM_MTD_DSP  put_LockedText, BOOL
  COM_MTD_DSP  get_Text, ptr BSTR
  COM_MTD_DSP  put_Text, BSTR
  COM_MTD_DSP  get_Accelerator, ptr VARIANT
  COM_MTD_DSP  put_Accelerator, VARIANT
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  get__Default, ptr SDWORD
  COM_MTD_DSP  put__Default, SDWORD
  COM_MTD_DSP  get_Display3DShading, ptr BOOL
  COM_MTD_DSP  put_Display3DShading, BOOL
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_LinkedCell, ptr BSTR
  COM_MTD_DSP  put_LinkedCell, BSTR
  COM_MTD_DSP  get_PhoneticAccelerator, ptr VARIANT
  COM_MTD_DSP  put_PhoneticAccelerator, VARIANT
  COM_MTD_DSP  get_Value, ptr VARIANT
  COM_MTD_DSP  put_Value, VARIANT
  COM_MTD_DSP  Add_, REAL8, REAL8, REAL8, REAL8, ptr ptr CheckBox
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Group_, ptr ptr GroupObject
  COM_MTD_DSP  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG OptionButton, IDispatch, <00020881-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_BottomRightCell, ptr ptr Range
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  get_TopLeftCell, ptr ptr Range
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_DSP  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_LockedText, ptr BOOL
  COM_MTD_DSP  put_LockedText, BOOL
  COM_MTD_DSP  get_Text, ptr BSTR
  COM_MTD_DSP  put_Text, BSTR
  COM_MTD_DSP  get_Accelerator, ptr VARIANT
  COM_MTD_DSP  put_Accelerator, VARIANT
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  get__Default, ptr SDWORD
  COM_MTD_DSP  put__Default, SDWORD
  COM_MTD_DSP  get_Display3DShading, ptr BOOL
  COM_MTD_DSP  put_Display3DShading, BOOL
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_LinkedCell, ptr BSTR
  COM_MTD_DSP  put_LinkedCell, BSTR
  COM_MTD_DSP  get_PhoneticAccelerator, ptr VARIANT
  COM_MTD_DSP  put_PhoneticAccelerator, VARIANT
  COM_MTD_DSP  get_Value, ptr VARIANT
  COM_MTD_DSP  put_Value, VARIANT
  COM_MTD_DSP  get_GroupBox, ptr ptr GroupBox
COM_INTERFACE_END

COM_INTERFACE_BEG OptionButtons, IDispatch, <00020882-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  _Dummy3
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  _Dummy12
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  _Dummy15
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  _Dummy22
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_DSP  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_LockedText, ptr BOOL
  COM_MTD_DSP  put_LockedText, BOOL
  COM_MTD_DSP  get_Text, ptr BSTR
  COM_MTD_DSP  put_Text, BSTR
  COM_MTD_DSP  get_Accelerator, ptr VARIANT
  COM_MTD_DSP  put_Accelerator, VARIANT
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  get__Default, ptr SDWORD
  COM_MTD_DSP  put__Default, SDWORD
  COM_MTD_DSP  get_Display3DShading, ptr BOOL
  COM_MTD_DSP  put_Display3DShading, BOOL
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_LinkedCell, ptr BSTR
  COM_MTD_DSP  put_LinkedCell, BSTR
  COM_MTD_DSP  get_PhoneticAccelerator, ptr VARIANT
  COM_MTD_DSP  put_PhoneticAccelerator, VARIANT
  COM_MTD_DSP  get_Value, ptr VARIANT
  COM_MTD_DSP  put_Value, VARIANT
  COM_MTD_DSP  get_GroupBox, ptr ptr GroupBox
  COM_MTD_DSP  Add_, REAL8, REAL8, REAL8, REAL8, ptr ptr OptionButton
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Group_, ptr ptr GroupObject
  COM_MTD_DSP  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG EditBox, IDispatch, <00020883-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_BottomRightCell, ptr ptr Range
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  get_TopLeftCell, ptr ptr Range
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_DSP  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_LockedText, ptr BOOL
  COM_MTD_DSP  put_LockedText, BOOL
  COM_MTD_DSP  get_Text, ptr BSTR
  COM_MTD_DSP  put_Text, BSTR
  COM_MTD_DSP  get_DisplayVerticalScrollBar, ptr BOOL
  COM_MTD_DSP  put_DisplayVerticalScrollBar, BOOL
  COM_MTD_DSP  get_InputType, ptr SDWORD
  COM_MTD_DSP  put_InputType, SDWORD
  COM_MTD_DSP  get_LinkedObject, ptr BSTR
  COM_MTD_DSP  get_MultiLine, ptr BOOL
  COM_MTD_DSP  put_MultiLine, BOOL
  COM_MTD_DSP  get_PasswordEdit, ptr BOOL
  COM_MTD_DSP  put_PasswordEdit, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG EditBoxes, IDispatch, <00020884-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  _Dummy3
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  _Dummy12
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  _Dummy15
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  _Dummy22
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_DSP  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_LockedText, ptr BOOL
  COM_MTD_DSP  put_LockedText, BOOL
  COM_MTD_DSP  get_Text, ptr BSTR
  COM_MTD_DSP  put_Text, BSTR
  COM_MTD_DSP  get_DisplayVerticalScrollBar, ptr BOOL
  COM_MTD_DSP  put_DisplayVerticalScrollBar, BOOL
  COM_MTD_DSP  get_InputType, ptr SDWORD
  COM_MTD_DSP  put_InputType, SDWORD
  COM_MTD_DSP  _Dummy34
  COM_MTD_DSP  get_MultiLine, ptr BOOL
  COM_MTD_DSP  put_MultiLine, BOOL
  COM_MTD_DSP  get_PasswordEdit, ptr BOOL
  COM_MTD_DSP  put_PasswordEdit, BOOL
  COM_MTD_DSP  Add_, REAL8, REAL8, REAL8, REAL8, ptr ptr EditBox
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Group_, ptr ptr GroupObject
  COM_MTD_DSP  Item, VARIANT, ptr VARIANT
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG ScrollBar, IDispatch, <00020885-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_BottomRightCell, ptr ptr Range
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  get_TopLeftCell, ptr ptr Range
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get__Default, ptr SDWORD
  COM_MTD_DSP  put__Default, SDWORD
  COM_MTD_DSP  get_Display3DShading, ptr BOOL
  COM_MTD_DSP  put_Display3DShading, BOOL
  COM_MTD_DSP  get_LinkedCell, ptr BSTR
  COM_MTD_DSP  put_LinkedCell, BSTR
  COM_MTD_DSP  get_Max, ptr SDWORD
  COM_MTD_DSP  put_Max, SDWORD
  COM_MTD_DSP  get_Min, ptr SDWORD
  COM_MTD_DSP  put_Min, SDWORD
  COM_MTD_DSP  get_SmallChange, ptr SDWORD
  COM_MTD_DSP  put_SmallChange, SDWORD
  COM_MTD_DSP  get_Value, ptr SDWORD
  COM_MTD_DSP  put_Value, SDWORD
  COM_MTD_DSP  get_LargeChange, ptr SDWORD
  COM_MTD_DSP  put_LargeChange, SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG ScrollBars, IDispatch, <00020886-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  _Dummy3
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  _Dummy12
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  _Dummy15
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  _Dummy22
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get__Default, ptr SDWORD
  COM_MTD_DSP  put__Default, SDWORD
  COM_MTD_DSP  get_Display3DShading, ptr BOOL
  COM_MTD_DSP  put_Display3DShading, BOOL
  COM_MTD_DSP  get_LinkedCell, ptr BSTR
  COM_MTD_DSP  put_LinkedCell, BSTR
  COM_MTD_DSP  get_Max, ptr SDWORD
  COM_MTD_DSP  put_Max, SDWORD
  COM_MTD_DSP  get_Min, ptr SDWORD
  COM_MTD_DSP  put_Min, SDWORD
  COM_MTD_DSP  get_SmallChange, ptr SDWORD
  COM_MTD_DSP  put_SmallChange, SDWORD
  COM_MTD_DSP  get_Value, ptr SDWORD
  COM_MTD_DSP  put_Value, SDWORD
  COM_MTD_DSP  get_LargeChange, ptr SDWORD
  COM_MTD_DSP  put_LargeChange, SDWORD
  COM_MTD_DSP  Add_, REAL8, REAL8, REAL8, REAL8, ptr ptr ScrollBar
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Group_, ptr ptr GroupObject
  COM_MTD_DSP  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG ListBox, IDispatch, <00020887-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_BottomRightCell, ptr ptr Range
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  get_TopLeftCell, ptr ptr Range
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  AddItem, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_Display3DShading, ptr BOOL
  COM_MTD_DSP  put_Display3DShading, BOOL
  COM_MTD_DSP  get__Default, ptr SDWORD
  COM_MTD_DSP  put__Default, SDWORD
  COM_MTD_DSP  get_LinkedCell, ptr BSTR
  COM_MTD_DSP  put_LinkedCell, BSTR
  COM_MTD_DSP  get_LinkedObject, ptr VARIANT
  COM_MTD_DSP  get_List, VARIANT, ptr VARIANT
  COM_MTD_DSP  put_List, VARIANT, VARIANT
  COM_MTD_DSP  get_ListCount, ptr SDWORD
  COM_MTD_DSP  get_ListFillRange, ptr BSTR
  COM_MTD_DSP  put_ListFillRange, BSTR
  COM_MTD_DSP  get_ListIndex, ptr SDWORD
  COM_MTD_DSP  put_ListIndex, SDWORD
  COM_MTD_DSP  get_MultiSelect, ptr SDWORD
  COM_MTD_DSP  put_MultiSelect, SDWORD
  COM_MTD_DSP  RemoveAllItems, ptr VARIANT
  COM_MTD_DSP  RemoveItem, SDWORD, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_Selected, VARIANT, ptr VARIANT
  COM_MTD_DSP  put_Selected, VARIANT, VARIANT
  COM_MTD_DSP  get_Value, ptr SDWORD
  COM_MTD_DSP  put_Value, SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG ListBoxes, IDispatch, <00020888-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  _Dummy3
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  _Dummy12
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  _Dummy15
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  _Dummy22
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  AddItem, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_Display3DShading, ptr BOOL
  COM_MTD_DSP  put_Display3DShading, BOOL
  COM_MTD_DSP  get__Default, ptr SDWORD
  COM_MTD_DSP  put__Default, SDWORD
  COM_MTD_DSP  get_LinkedCell, ptr BSTR
  COM_MTD_DSP  put_LinkedCell, BSTR
  COM_MTD_DSP  _Dummy31
  COM_MTD_DSP  get_List, VARIANT, ptr VARIANT
  COM_MTD_DSP  put_List, VARIANT, VARIANT
  COM_MTD_DSP  _Dummy33
  COM_MTD_DSP  get_ListFillRange, ptr BSTR
  COM_MTD_DSP  put_ListFillRange, BSTR
  COM_MTD_DSP  get_ListIndex, ptr SDWORD
  COM_MTD_DSP  put_ListIndex, SDWORD
  COM_MTD_DSP  get_MultiSelect, ptr SDWORD
  COM_MTD_DSP  put_MultiSelect, SDWORD
  COM_MTD_DSP  RemoveAllItems, ptr VARIANT
  COM_MTD_DSP  RemoveItem, SDWORD, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_Selected, VARIANT, ptr VARIANT
  COM_MTD_DSP  put_Selected, VARIANT, VARIANT
  COM_MTD_DSP  get_Value, ptr SDWORD
  COM_MTD_DSP  put_Value, SDWORD
  COM_MTD_DSP  Add_, REAL8, REAL8, REAL8, REAL8, ptr ptr ListBox
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Group_, ptr ptr GroupObject
  COM_MTD_DSP  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG GroupBox, IDispatch, <00020889-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_BottomRightCell, ptr ptr Range
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  get_TopLeftCell, ptr ptr Range
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_DSP  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_LockedText, ptr BOOL
  COM_MTD_DSP  put_LockedText, BOOL
  COM_MTD_DSP  get_Text, ptr BSTR
  COM_MTD_DSP  put_Text, BSTR
  COM_MTD_DSP  get_Accelerator, ptr VARIANT
  COM_MTD_DSP  put_Accelerator, VARIANT
  COM_MTD_DSP  get_Display3DShading, ptr BOOL
  COM_MTD_DSP  put_Display3DShading, BOOL
  COM_MTD_DSP  get_PhoneticAccelerator, ptr VARIANT
  COM_MTD_DSP  put_PhoneticAccelerator, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG GroupBoxes, IDispatch, <0002088A-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  _Dummy3
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  _Dummy12
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  _Dummy15
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  _Dummy22
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_DSP  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_LockedText, ptr BOOL
  COM_MTD_DSP  put_LockedText, BOOL
  COM_MTD_DSP  get_Text, ptr BSTR
  COM_MTD_DSP  put_Text, BSTR
  COM_MTD_DSP  get_Accelerator, ptr VARIANT
  COM_MTD_DSP  put_Accelerator, VARIANT
  COM_MTD_DSP  get_Display3DShading, ptr BOOL
  COM_MTD_DSP  put_Display3DShading, BOOL
  COM_MTD_DSP  get_PhoneticAccelerator, ptr VARIANT
  COM_MTD_DSP  put_PhoneticAccelerator, VARIANT
  COM_MTD_DSP  Add_, REAL8, REAL8, REAL8, REAL8, ptr ptr GroupBox
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Group_, ptr ptr GroupObject
  COM_MTD_DSP  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG DropDown, IDispatch, <0002088B-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_BottomRightCell, ptr ptr Range
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  get_TopLeftCell, ptr ptr Range
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  AddItem, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_Display3DShading, ptr BOOL
  COM_MTD_DSP  put_Display3DShading, BOOL
  COM_MTD_DSP  get__Default, ptr SDWORD
  COM_MTD_DSP  put__Default, SDWORD
  COM_MTD_DSP  get_LinkedCell, ptr BSTR
  COM_MTD_DSP  put_LinkedCell, BSTR
  COM_MTD_DSP  get_LinkedObject, ptr VARIANT
  COM_MTD_DSP  get_List, VARIANT, ptr VARIANT
  COM_MTD_DSP  put_List, VARIANT, VARIANT
  COM_MTD_DSP  get_ListCount, ptr SDWORD
  COM_MTD_DSP  get_ListFillRange, ptr BSTR
  COM_MTD_DSP  put_ListFillRange, BSTR
  COM_MTD_DSP  get_ListIndex, ptr SDWORD
  COM_MTD_DSP  put_ListIndex, SDWORD
  COM_MTD_DSP  _Dummy36
  COM_MTD_DSP  RemoveAllItems, ptr VARIANT
  COM_MTD_DSP  RemoveItem, SDWORD, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_Selected, VARIANT, ptr VARIANT
  COM_MTD_DSP  put_Selected, VARIANT, VARIANT
  COM_MTD_DSP  get_Value, ptr SDWORD
  COM_MTD_DSP  put_Value, SDWORD
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_DSP  get_DropDownLines, ptr SDWORD
  COM_MTD_DSP  put_DropDownLines, SDWORD
  COM_MTD_DSP  get_Text, ptr BSTR
  COM_MTD_DSP  put_Text, BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG DropDowns, IDispatch, <0002088C-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  _Dummy3
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  _Dummy12
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  _Dummy15
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  _Dummy22
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  AddItem, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_Display3DShading, ptr BOOL
  COM_MTD_DSP  put_Display3DShading, BOOL
  COM_MTD_DSP  get__Default, ptr SDWORD
  COM_MTD_DSP  put__Default, SDWORD
  COM_MTD_DSP  get_LinkedCell, ptr BSTR
  COM_MTD_DSP  put_LinkedCell, BSTR
  COM_MTD_DSP  _Dummy31
  COM_MTD_DSP  get_List, VARIANT, ptr VARIANT
  COM_MTD_DSP  put_List, VARIANT, VARIANT
  COM_MTD_DSP  _Dummy33
  COM_MTD_DSP  get_ListFillRange, ptr BSTR
  COM_MTD_DSP  put_ListFillRange, BSTR
  COM_MTD_DSP  get_ListIndex, ptr SDWORD
  COM_MTD_DSP  put_ListIndex, SDWORD
  COM_MTD_DSP  _Dummy36
  COM_MTD_DSP  RemoveAllItems, ptr VARIANT
  COM_MTD_DSP  RemoveItem, SDWORD, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_Selected, VARIANT, ptr VARIANT
  COM_MTD_DSP  put_Selected, VARIANT, VARIANT
  COM_MTD_DSP  get_Value, ptr SDWORD
  COM_MTD_DSP  put_Value, SDWORD
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_DSP  get_DropDownLines, ptr SDWORD
  COM_MTD_DSP  put_DropDownLines, SDWORD
  COM_MTD_DSP  get_Text, ptr BSTR
  COM_MTD_DSP  put_Text, BSTR
  COM_MTD_DSP  Add_, REAL8, REAL8, REAL8, REAL8, VARIANT, ptr ptr DropDown
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Group_, ptr ptr GroupObject
  COM_MTD_DSP  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG Spinner, IDispatch, <0002088D-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_BottomRightCell, ptr ptr Range
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  get_TopLeftCell, ptr ptr Range
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get__Default, ptr SDWORD
  COM_MTD_DSP  put__Default, SDWORD
  COM_MTD_DSP  get_Display3DShading, ptr BOOL
  COM_MTD_DSP  put_Display3DShading, BOOL
  COM_MTD_DSP  get_LinkedCell, ptr BSTR
  COM_MTD_DSP  put_LinkedCell, BSTR
  COM_MTD_DSP  get_Max, ptr SDWORD
  COM_MTD_DSP  put_Max, SDWORD
  COM_MTD_DSP  get_Min, ptr SDWORD
  COM_MTD_DSP  put_Min, SDWORD
  COM_MTD_DSP  get_SmallChange, ptr SDWORD
  COM_MTD_DSP  put_SmallChange, SDWORD
  COM_MTD_DSP  get_Value, ptr SDWORD
  COM_MTD_DSP  put_Value, SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG Spinners, IDispatch, <0002088E-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  _Dummy3
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  _Dummy12
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  _Dummy15
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  _Dummy22
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get__Default, ptr SDWORD
  COM_MTD_DSP  put__Default, SDWORD
  COM_MTD_DSP  get_Display3DShading, ptr BOOL
  COM_MTD_DSP  put_Display3DShading, BOOL
  COM_MTD_DSP  get_LinkedCell, ptr BSTR
  COM_MTD_DSP  put_LinkedCell, BSTR
  COM_MTD_DSP  get_Max, ptr SDWORD
  COM_MTD_DSP  put_Max, SDWORD
  COM_MTD_DSP  get_Min, ptr SDWORD
  COM_MTD_DSP  put_Min, SDWORD
  COM_MTD_DSP  get_SmallChange, ptr SDWORD
  COM_MTD_DSP  put_SmallChange, SDWORD
  COM_MTD_DSP  get_Value, ptr SDWORD
  COM_MTD_DSP  put_Value, SDWORD
  COM_MTD_DSP  Add_, REAL8, REAL8, REAL8, REAL8, ptr ptr Spinner
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Group_, ptr ptr GroupObject
  COM_MTD_DSP  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG DialogFrame, IDispatch, <0002088F-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  _Dummy3
  COM_MTD_DSP  _Dummy4
  COM_MTD_DSP  _Dummy5
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  _Dummy7
  COM_MTD_DSP  _Dummy8
  COM_MTD_DSP  _Dummy9
  COM_MTD_DSP  _Dummy10
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  _Dummy12
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  _Dummy17
  COM_MTD_DSP  _Dummy18
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  _Dummy20
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  _Dummy22
  COM_MTD_DSP  _Dummy23
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  _Dummy25
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_DSP  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_LockedText, ptr BOOL
  COM_MTD_DSP  put_LockedText, BOOL
  COM_MTD_DSP  get_Text, ptr BSTR
  COM_MTD_DSP  put_Text, BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG Label_, IDispatch, <00020890-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_BottomRightCell, ptr ptr Range
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  get_TopLeftCell, ptr ptr Range
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_DSP  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_LockedText, ptr BOOL
  COM_MTD_DSP  put_LockedText, BOOL
  COM_MTD_DSP  get_Text, ptr BSTR
  COM_MTD_DSP  put_Text, BSTR
  COM_MTD_DSP  get_Accelerator, ptr VARIANT
  COM_MTD_DSP  put_Accelerator, VARIANT
  COM_MTD_DSP  _Dummy33
  COM_MTD_DSP  get_PhoneticAccelerator, ptr VARIANT
  COM_MTD_DSP  put_PhoneticAccelerator, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG Labels, IDispatch, <00020891-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  _Dummy3
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  _Dummy12
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  _Dummy15
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  _Dummy22
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_DSP  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_LockedText, ptr BOOL
  COM_MTD_DSP  put_LockedText, BOOL
  COM_MTD_DSP  get_Text, ptr BSTR
  COM_MTD_DSP  put_Text, BSTR
  COM_MTD_DSP  get_Accelerator, ptr VARIANT
  COM_MTD_DSP  put_Accelerator, VARIANT
  COM_MTD_DSP  _Dummy33
  COM_MTD_DSP  get_PhoneticAccelerator, ptr VARIANT
  COM_MTD_DSP  put_PhoneticAccelerator, VARIANT
  COM_MTD_DSP  Add_, REAL8, REAL8, REAL8, REAL8, ptr ptr Label_
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Group_, ptr ptr GroupObject
  COM_MTD_DSP  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG Panes, IDispatch, <00020894-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  get_Item, SDWORD, ptr ptr Pane
  COM_MTD_DSP  get__Default, SDWORD, ptr ptr Pane
COM_INTERFACE_END

COM_INTERFACE_BEG Pane, IDispatch, <00020895-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Activate, ptr BOOL
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  LargeScroll, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_ScrollColumn, ptr SDWORD
  COM_MTD_DSP  put_ScrollColumn, SDWORD
  COM_MTD_DSP  get_ScrollRow, ptr SDWORD
  COM_MTD_DSP  put_ScrollRow, SDWORD
  COM_MTD_DSP  SmallScroll, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_VisibleRange, ptr ptr Range
  COM_MTD_DSP  ScrollIntoView, SDWORD, SDWORD, SDWORD, SDWORD, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG Scenarios, IDispatch, <00020896-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Add_, BSTR, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr ptr Scenario
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  CreateSummary, XlSummaryReportType, VARIANT, ptr VARIANT
  COM_MTD_DSP  Item, VARIANT, ptr ptr Scenario
  COM_MTD_DSP  Merge, VARIANT, ptr VARIANT
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG Scenario, IDispatch, <00020897-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  ChangeScenario, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_ChangingCells, ptr ptr Range
  COM_MTD_DSP  get_Comment, ptr BSTR
  COM_MTD_DSP  put_Comment, BSTR
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  get_Hidden, ptr BOOL
  COM_MTD_DSP  put_Hidden, BOOL
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  Show, ptr VARIANT
  COM_MTD_DSP  get_Values, VARIANT, ptr VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG GroupObject, IDispatch, <00020898-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_BottomRightCell, ptr ptr Range
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  get_TopLeftCell, ptr ptr Range
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  _Dummy27
  COM_MTD_DSP  _Dummy28
  COM_MTD_DSP  get_AddIndent, ptr BOOL
  COM_MTD_DSP  put_AddIndent, BOOL
  COM_MTD_DSP  _Dummy30
  COM_MTD_DSP  get_ArrowHeadLength, ptr VARIANT
  COM_MTD_DSP  put_ArrowHeadLength, VARIANT
  COM_MTD_DSP  get_ArrowHeadStyle, ptr VARIANT
  COM_MTD_DSP  put_ArrowHeadStyle, VARIANT
  COM_MTD_DSP  get_ArrowHeadWidth, ptr VARIANT
  COM_MTD_DSP  put_ArrowHeadWidth, VARIANT
  COM_MTD_DSP  get_AutoSize, ptr BOOL
  COM_MTD_DSP  put_AutoSize, BOOL
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  _Dummy36
  COM_MTD_DSP  _Dummy37
  COM_MTD_DSP  _Dummy38
  COM_MTD_DSP  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get__Default, ptr SDWORD
  COM_MTD_DSP  put__Default, SDWORD
  COM_MTD_DSP  _Dummy41
  COM_MTD_DSP  _Dummy42
  COM_MTD_DSP  _Dummy43
  COM_MTD_DSP  _Dummy44
  COM_MTD_DSP  _Dummy45
  COM_MTD_DSP  get_Font, ptr ptr Font
  COM_MTD_DSP  _Dummy47
  COM_MTD_DSP  _Dummy48
  COM_MTD_DSP  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_DSP  put_HorizontalAlignment, VARIANT
  COM_MTD_DSP  _Dummy50
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  _Dummy52
  COM_MTD_DSP  _Dummy53
  COM_MTD_DSP  _Dummy54
  COM_MTD_DSP  _Dummy55
  COM_MTD_DSP  _Dummy56
  COM_MTD_DSP  _Dummy57
  COM_MTD_DSP  _Dummy58
  COM_MTD_DSP  _Dummy59
  COM_MTD_DSP  _Dummy60
  COM_MTD_DSP  _Dummy61
  COM_MTD_DSP  _Dummy62
  COM_MTD_DSP  _Dummy63
  COM_MTD_DSP  get_Orientation, ptr VARIANT
  COM_MTD_DSP  put_Orientation, VARIANT
  COM_MTD_DSP  _Dummy65
  COM_MTD_DSP  _Dummy66
  COM_MTD_DSP  _Dummy67
  COM_MTD_DSP  _Dummy68
  COM_MTD_DSP  get_RoundedCorners, ptr BOOL
  COM_MTD_DSP  put_RoundedCorners, BOOL
  COM_MTD_DSP  _Dummy70
  COM_MTD_DSP  get_Shadow, ptr BOOL
  COM_MTD_DSP  put_Shadow, BOOL
  COM_MTD_DSP  _Dummy72
  COM_MTD_DSP  _Dummy73
  COM_MTD_DSP  Ungroup, ptr LPDISPATCH
  COM_MTD_DSP  _Dummy75
  COM_MTD_DSP  get_VerticalAlignment, ptr VARIANT
  COM_MTD_DSP  put_VerticalAlignment, VARIANT
  COM_MTD_DSP  _Dummy77
  COM_MTD_DSP  get_ReadingOrder, ptr SDWORD
  COM_MTD_DSP  put_ReadingOrder, SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG GroupObjects, IDispatch, <00020899-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  _Dummy3
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  _Dummy12
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  _Dummy15
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  _Dummy22
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  _Dummy27
  COM_MTD_DSP  _Dummy28
  COM_MTD_DSP  get_AddIndent, ptr BOOL
  COM_MTD_DSP  put_AddIndent, BOOL
  COM_MTD_DSP  _Dummy30
  COM_MTD_DSP  get_ArrowHeadLength, ptr VARIANT
  COM_MTD_DSP  put_ArrowHeadLength, VARIANT
  COM_MTD_DSP  get_ArrowHeadStyle, ptr VARIANT
  COM_MTD_DSP  put_ArrowHeadStyle, VARIANT
  COM_MTD_DSP  get_ArrowHeadWidth, ptr VARIANT
  COM_MTD_DSP  put_ArrowHeadWidth, VARIANT
  COM_MTD_DSP  get_AutoSize, ptr BOOL
  COM_MTD_DSP  put_AutoSize, BOOL
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  _Dummy36
  COM_MTD_DSP  _Dummy37
  COM_MTD_DSP  _Dummy38
  COM_MTD_DSP  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get__Default, ptr SDWORD
  COM_MTD_DSP  put__Default, SDWORD
  COM_MTD_DSP  _Dummy41
  COM_MTD_DSP  _Dummy42
  COM_MTD_DSP  _Dummy43
  COM_MTD_DSP  _Dummy44
  COM_MTD_DSP  _Dummy45
  COM_MTD_DSP  get_Font, ptr ptr Font
  COM_MTD_DSP  _Dummy47
  COM_MTD_DSP  _Dummy48
  COM_MTD_DSP  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_DSP  put_HorizontalAlignment, VARIANT
  COM_MTD_DSP  _Dummy50
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  _Dummy52
  COM_MTD_DSP  _Dummy53
  COM_MTD_DSP  _Dummy54
  COM_MTD_DSP  _Dummy55
  COM_MTD_DSP  _Dummy56
  COM_MTD_DSP  _Dummy57
  COM_MTD_DSP  _Dummy58
  COM_MTD_DSP  _Dummy59
  COM_MTD_DSP  _Dummy60
  COM_MTD_DSP  _Dummy61
  COM_MTD_DSP  _Dummy62
  COM_MTD_DSP  _Dummy63
  COM_MTD_DSP  get_Orientation, ptr VARIANT
  COM_MTD_DSP  put_Orientation, VARIANT
  COM_MTD_DSP  _Dummy65
  COM_MTD_DSP  _Dummy66
  COM_MTD_DSP  _Dummy67
  COM_MTD_DSP  _Dummy68
  COM_MTD_DSP  get_RoundedCorners, ptr BOOL
  COM_MTD_DSP  put_RoundedCorners, BOOL
  COM_MTD_DSP  _Dummy70
  COM_MTD_DSP  get_Shadow, ptr BOOL
  COM_MTD_DSP  put_Shadow, BOOL
  COM_MTD_DSP  _Dummy72
  COM_MTD_DSP  _Dummy73
  COM_MTD_DSP  Ungroup, ptr LPDISPATCH
  COM_MTD_DSP  _Dummy75
  COM_MTD_DSP  get_VerticalAlignment, ptr VARIANT
  COM_MTD_DSP  put_VerticalAlignment, VARIANT
  COM_MTD_DSP  _Dummy77
  COM_MTD_DSP  get_ReadingOrder, ptr SDWORD
  COM_MTD_DSP  put_ReadingOrder, SDWORD
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Group_, ptr ptr GroupObject
  COM_MTD_DSP  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG Line, IDispatch, <0002089A-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_BottomRightCell, ptr ptr Range
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  get_TopLeftCell, ptr ptr Range
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get_ArrowHeadLength, ptr VARIANT
  COM_MTD_DSP  put_ArrowHeadLength, VARIANT
  COM_MTD_DSP  get_ArrowHeadStyle, ptr VARIANT
  COM_MTD_DSP  put_ArrowHeadStyle, VARIANT
  COM_MTD_DSP  get_ArrowHeadWidth, ptr VARIANT
  COM_MTD_DSP  put_ArrowHeadWidth, VARIANT
  COM_MTD_DSP  get_Border, ptr ptr Border
COM_INTERFACE_END

COM_INTERFACE_BEG Lines, IDispatch, <0002089B-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  _Dummy3
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  _Dummy12
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  _Dummy15
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  _Dummy22
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get_ArrowHeadLength, ptr VARIANT
  COM_MTD_DSP  put_ArrowHeadLength, VARIANT
  COM_MTD_DSP  get_ArrowHeadStyle, ptr VARIANT
  COM_MTD_DSP  put_ArrowHeadStyle, VARIANT
  COM_MTD_DSP  get_ArrowHeadWidth, ptr VARIANT
  COM_MTD_DSP  put_ArrowHeadWidth, VARIANT
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  Add_, REAL8, REAL8, REAL8, REAL8, ptr ptr Line
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Group_, ptr ptr GroupObject
  COM_MTD_DSP  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG Rectangle_, IDispatch, <0002089C-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_BottomRightCell, ptr ptr Range
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  get_TopLeftCell, ptr ptr Range
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get_AddIndent, ptr BOOL
  COM_MTD_DSP  put_AddIndent, BOOL
  COM_MTD_DSP  get_AutoScaleFont, ptr VARIANT
  COM_MTD_DSP  put_AutoScaleFont, VARIANT
  COM_MTD_DSP  get_AutoSize, ptr BOOL
  COM_MTD_DSP  put_AutoSize, BOOL
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_DSP  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_Font, ptr ptr Font
  COM_MTD_DSP  get_Formula, ptr BSTR
  COM_MTD_DSP  put_Formula, BSTR
  COM_MTD_DSP  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_DSP  put_HorizontalAlignment, VARIANT
  COM_MTD_DSP  get_LockedText, ptr BOOL
  COM_MTD_DSP  put_LockedText, BOOL
  COM_MTD_DSP  get_Orientation, ptr VARIANT
  COM_MTD_DSP  put_Orientation, VARIANT
  COM_MTD_DSP  get_Text, ptr BSTR
  COM_MTD_DSP  put_Text, BSTR
  COM_MTD_DSP  get_VerticalAlignment, ptr VARIANT
  COM_MTD_DSP  put_VerticalAlignment, VARIANT
  COM_MTD_DSP  get_ReadingOrder, ptr SDWORD
  COM_MTD_DSP  put_ReadingOrder, SDWORD
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_Shadow, ptr BOOL
  COM_MTD_DSP  put_Shadow, BOOL
  COM_MTD_DSP  get_RoundedCorners, ptr BOOL
  COM_MTD_DSP  put_RoundedCorners, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG Rectangles, IDispatch, <0002089D-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  _Dummy3
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  _Dummy12
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  _Dummy15
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  _Dummy22
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get_AddIndent, ptr BOOL
  COM_MTD_DSP  put_AddIndent, BOOL
  COM_MTD_DSP  get_AutoScaleFont, ptr VARIANT
  COM_MTD_DSP  put_AutoScaleFont, VARIANT
  COM_MTD_DSP  get_AutoSize, ptr BOOL
  COM_MTD_DSP  put_AutoSize, BOOL
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_DSP  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_Font, ptr ptr Font
  COM_MTD_DSP  get_Formula, ptr BSTR
  COM_MTD_DSP  put_Formula, BSTR
  COM_MTD_DSP  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_DSP  put_HorizontalAlignment, VARIANT
  COM_MTD_DSP  get_LockedText, ptr BOOL
  COM_MTD_DSP  put_LockedText, BOOL
  COM_MTD_DSP  get_Orientation, ptr VARIANT
  COM_MTD_DSP  put_Orientation, VARIANT
  COM_MTD_DSP  get_Text, ptr BSTR
  COM_MTD_DSP  put_Text, BSTR
  COM_MTD_DSP  get_VerticalAlignment, ptr VARIANT
  COM_MTD_DSP  put_VerticalAlignment, VARIANT
  COM_MTD_DSP  get_ReadingOrder, ptr SDWORD
  COM_MTD_DSP  put_ReadingOrder, SDWORD
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_Shadow, ptr BOOL
  COM_MTD_DSP  put_Shadow, BOOL
  COM_MTD_DSP  get_RoundedCorners, ptr BOOL
  COM_MTD_DSP  put_RoundedCorners, BOOL
  COM_MTD_DSP  Add_, REAL8, REAL8, REAL8, REAL8, ptr ptr Rectangle_
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Group_, ptr ptr GroupObject
  COM_MTD_DSP  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG Oval, IDispatch, <0002089E-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_BottomRightCell, ptr ptr Range
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  get_TopLeftCell, ptr ptr Range
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get_AddIndent, ptr BOOL
  COM_MTD_DSP  put_AddIndent, BOOL
  COM_MTD_DSP  get_AutoScaleFont, ptr VARIANT
  COM_MTD_DSP  put_AutoScaleFont, VARIANT
  COM_MTD_DSP  get_AutoSize, ptr BOOL
  COM_MTD_DSP  put_AutoSize, BOOL
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_DSP  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_Font, ptr ptr Font
  COM_MTD_DSP  get_Formula, ptr BSTR
  COM_MTD_DSP  put_Formula, BSTR
  COM_MTD_DSP  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_DSP  put_HorizontalAlignment, VARIANT
  COM_MTD_DSP  get_LockedText, ptr BOOL
  COM_MTD_DSP  put_LockedText, BOOL
  COM_MTD_DSP  get_Orientation, ptr VARIANT
  COM_MTD_DSP  put_Orientation, VARIANT
  COM_MTD_DSP  get_Text, ptr BSTR
  COM_MTD_DSP  put_Text, BSTR
  COM_MTD_DSP  get_VerticalAlignment, ptr VARIANT
  COM_MTD_DSP  put_VerticalAlignment, VARIANT
  COM_MTD_DSP  get_ReadingOrder, ptr SDWORD
  COM_MTD_DSP  put_ReadingOrder, SDWORD
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_Shadow, ptr BOOL
  COM_MTD_DSP  put_Shadow, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG Ovals, IDispatch, <0002089F-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  _Dummy3
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  _Dummy12
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  _Dummy15
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  _Dummy22
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get_AddIndent, ptr BOOL
  COM_MTD_DSP  put_AddIndent, BOOL
  COM_MTD_DSP  get_AutoScaleFont, ptr VARIANT
  COM_MTD_DSP  put_AutoScaleFont, VARIANT
  COM_MTD_DSP  get_AutoSize, ptr BOOL
  COM_MTD_DSP  put_AutoSize, BOOL
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_DSP  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_Font, ptr ptr Font
  COM_MTD_DSP  get_Formula, ptr BSTR
  COM_MTD_DSP  put_Formula, BSTR
  COM_MTD_DSP  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_DSP  put_HorizontalAlignment, VARIANT
  COM_MTD_DSP  get_LockedText, ptr BOOL
  COM_MTD_DSP  put_LockedText, BOOL
  COM_MTD_DSP  get_Orientation, ptr VARIANT
  COM_MTD_DSP  put_Orientation, VARIANT
  COM_MTD_DSP  get_Text, ptr BSTR
  COM_MTD_DSP  put_Text, BSTR
  COM_MTD_DSP  get_VerticalAlignment, ptr VARIANT
  COM_MTD_DSP  put_VerticalAlignment, VARIANT
  COM_MTD_DSP  get_ReadingOrder, ptr SDWORD
  COM_MTD_DSP  put_ReadingOrder, SDWORD
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_Shadow, ptr BOOL
  COM_MTD_DSP  put_Shadow, BOOL
  COM_MTD_DSP  Add_, REAL8, REAL8, REAL8, REAL8, ptr ptr Oval
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Group_, ptr ptr GroupObject
  COM_MTD_DSP  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG Arc_, IDispatch, <000208A0-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_BottomRightCell, ptr ptr Range
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  get_TopLeftCell, ptr ptr Range
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get_AddIndent, ptr BOOL
  COM_MTD_DSP  put_AddIndent, BOOL
  COM_MTD_DSP  get_AutoScaleFont, ptr VARIANT
  COM_MTD_DSP  put_AutoScaleFont, VARIANT
  COM_MTD_DSP  get_AutoSize, ptr BOOL
  COM_MTD_DSP  put_AutoSize, BOOL
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_DSP  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_Font, ptr ptr Font
  COM_MTD_DSP  get_Formula, ptr BSTR
  COM_MTD_DSP  put_Formula, BSTR
  COM_MTD_DSP  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_DSP  put_HorizontalAlignment, VARIANT
  COM_MTD_DSP  get_LockedText, ptr BOOL
  COM_MTD_DSP  put_LockedText, BOOL
  COM_MTD_DSP  get_Orientation, ptr VARIANT
  COM_MTD_DSP  put_Orientation, VARIANT
  COM_MTD_DSP  get_Text, ptr BSTR
  COM_MTD_DSP  put_Text, BSTR
  COM_MTD_DSP  get_VerticalAlignment, ptr VARIANT
  COM_MTD_DSP  put_VerticalAlignment, VARIANT
  COM_MTD_DSP  get_ReadingOrder, ptr SDWORD
  COM_MTD_DSP  put_ReadingOrder, SDWORD
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  _Dummy43
COM_INTERFACE_END

COM_INTERFACE_BEG Arcs, IDispatch, <000208A1-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  _Dummy3
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  _Dummy12
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  _Dummy15
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  _Dummy22
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get_AddIndent, ptr BOOL
  COM_MTD_DSP  put_AddIndent, BOOL
  COM_MTD_DSP  get_AutoScaleFont, ptr VARIANT
  COM_MTD_DSP  put_AutoScaleFont, VARIANT
  COM_MTD_DSP  get_AutoSize, ptr BOOL
  COM_MTD_DSP  put_AutoSize, BOOL
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_DSP  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_Font, ptr ptr Font
  COM_MTD_DSP  get_Formula, ptr BSTR
  COM_MTD_DSP  put_Formula, BSTR
  COM_MTD_DSP  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_DSP  put_HorizontalAlignment, VARIANT
  COM_MTD_DSP  get_LockedText, ptr BOOL
  COM_MTD_DSP  put_LockedText, BOOL
  COM_MTD_DSP  get_Orientation, ptr VARIANT
  COM_MTD_DSP  put_Orientation, VARIANT
  COM_MTD_DSP  get_Text, ptr BSTR
  COM_MTD_DSP  put_Text, BSTR
  COM_MTD_DSP  get_VerticalAlignment, ptr VARIANT
  COM_MTD_DSP  put_VerticalAlignment, VARIANT
  COM_MTD_DSP  get_ReadingOrder, ptr SDWORD
  COM_MTD_DSP  put_ReadingOrder, SDWORD
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  _Dummy43
  COM_MTD_DSP  Add_, REAL8, REAL8, REAL8, REAL8, ptr ptr Arc_
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Group_, ptr ptr GroupObject
  COM_MTD_DSP  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG OLEObjectEvents, IDispatch, <00024410-0000-0000-C000-000000000046>
  COM_MTD_DSP  GotFocus
  COM_MTD_DSP  LostFocus
COM_INTERFACE_END

COM_INTERFACE_BEG _OLEObject, IDispatch, <000208A2-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_BottomRightCell, ptr ptr Range
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  get_TopLeftCell, ptr ptr Range
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_Shadow, ptr BOOL
  COM_MTD_DSP  put_Shadow, BOOL
  COM_MTD_DSP  Activate, ptr VARIANT
  COM_MTD_DSP  get_AutoLoad, ptr BOOL
  COM_MTD_DSP  put_AutoLoad, BOOL
  COM_MTD_DSP  get_AutoUpdate, ptr BOOL
  COM_MTD_DSP  put_AutoUpdate, BOOL
  COM_MTD_DSP  get_Object, ptr LPDISPATCH
  COM_MTD_DSP  get_OLEType, ptr VARIANT
  COM_MTD_DSP  get_SourceName, ptr BSTR
  COM_MTD_DSP  put_SourceName, BSTR
  COM_MTD_DSP  Update, ptr VARIANT
  COM_MTD_DSP  Verb, XlOLEVerb, ptr VARIANT
  COM_MTD_DSP  get_LinkedCell, ptr BSTR
  COM_MTD_DSP  put_LinkedCell, BSTR
  COM_MTD_DSP  get_ListFillRange, ptr BSTR
  COM_MTD_DSP  put_ListFillRange, BSTR
  COM_MTD_DSP  get_progID, ptr BSTR
  COM_MTD_DSP  get_AltHTML, ptr BSTR
  COM_MTD_DSP  put_AltHTML, BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG OLEObjects, IDispatch, <000208A3-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  _Dummy3
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  _Dummy12
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  _Dummy15
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  _Dummy22
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_Shadow, ptr BOOL
  COM_MTD_DSP  put_Shadow, BOOL
  COM_MTD_DSP  _Dummy30
  COM_MTD_DSP  get_AutoLoad, ptr BOOL
  COM_MTD_DSP  put_AutoLoad, BOOL
  COM_MTD_DSP  _Dummy32
  COM_MTD_DSP  _Dummy33
  COM_MTD_DSP  _Dummy34
  COM_MTD_DSP  get_SourceName, ptr BSTR
  COM_MTD_DSP  put_SourceName, BSTR
  COM_MTD_DSP  _Dummy36
  COM_MTD_DSP  _Dummy37
  COM_MTD_DSP  _Dummy38
  COM_MTD_DSP  _Dummy39
  COM_MTD_DSP  _Dummy40
  COM_MTD_DSP  _Dummy41
  COM_MTD_DSP  Add_, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr ptr OLEObject
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Group_, ptr ptr GroupObject
  COM_MTD_DSP  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG TextBox, IDispatch, <000208A4-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_BottomRightCell, ptr ptr Range
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  get_TopLeftCell, ptr ptr Range
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get_AddIndent, ptr BOOL
  COM_MTD_DSP  put_AddIndent, BOOL
  COM_MTD_DSP  get_AutoScaleFont, ptr VARIANT
  COM_MTD_DSP  put_AutoScaleFont, VARIANT
  COM_MTD_DSP  get_AutoSize, ptr BOOL
  COM_MTD_DSP  put_AutoSize, BOOL
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_DSP  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_Font, ptr ptr Font
  COM_MTD_DSP  get_Formula, ptr BSTR
  COM_MTD_DSP  put_Formula, BSTR
  COM_MTD_DSP  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_DSP  put_HorizontalAlignment, VARIANT
  COM_MTD_DSP  get_LockedText, ptr BOOL
  COM_MTD_DSP  put_LockedText, BOOL
  COM_MTD_DSP  get_Orientation, ptr VARIANT
  COM_MTD_DSP  put_Orientation, VARIANT
  COM_MTD_DSP  get_Text, ptr BSTR
  COM_MTD_DSP  put_Text, BSTR
  COM_MTD_DSP  get_VerticalAlignment, ptr VARIANT
  COM_MTD_DSP  put_VerticalAlignment, VARIANT
  COM_MTD_DSP  get_ReadingOrder, ptr SDWORD
  COM_MTD_DSP  put_ReadingOrder, SDWORD
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_RoundedCorners, ptr BOOL
  COM_MTD_DSP  put_RoundedCorners, BOOL
  COM_MTD_DSP  get_Shadow, ptr BOOL
  COM_MTD_DSP  put_Shadow, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG TextBoxes, IDispatch, <000208A5-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  _Dummy3
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  _Dummy12
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  _Dummy15
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  _Dummy22
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get_AddIndent, ptr BOOL
  COM_MTD_DSP  put_AddIndent, BOOL
  COM_MTD_DSP  get_AutoScaleFont, ptr VARIANT
  COM_MTD_DSP  put_AutoScaleFont, VARIANT
  COM_MTD_DSP  get_AutoSize, ptr BOOL
  COM_MTD_DSP  put_AutoSize, BOOL
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_DSP  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_Font, ptr ptr Font
  COM_MTD_DSP  get_Formula, ptr BSTR
  COM_MTD_DSP  put_Formula, BSTR
  COM_MTD_DSP  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_DSP  put_HorizontalAlignment, VARIANT
  COM_MTD_DSP  get_LockedText, ptr BOOL
  COM_MTD_DSP  put_LockedText, BOOL
  COM_MTD_DSP  get_Orientation, ptr VARIANT
  COM_MTD_DSP  put_Orientation, VARIANT
  COM_MTD_DSP  get_Text, ptr BSTR
  COM_MTD_DSP  put_Text, BSTR
  COM_MTD_DSP  get_VerticalAlignment, ptr VARIANT
  COM_MTD_DSP  put_VerticalAlignment, VARIANT
  COM_MTD_DSP  get_ReadingOrder, ptr SDWORD
  COM_MTD_DSP  put_ReadingOrder, SDWORD
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_RoundedCorners, ptr BOOL
  COM_MTD_DSP  put_RoundedCorners, BOOL
  COM_MTD_DSP  get_Shadow, ptr BOOL
  COM_MTD_DSP  put_Shadow, BOOL
  COM_MTD_DSP  Add_, REAL8, REAL8, REAL8, REAL8, ptr ptr TextBox
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Group_, ptr ptr GroupObject
  COM_MTD_DSP  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG Picture, IDispatch, <000208A6-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_BottomRightCell, ptr ptr Range
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  get_TopLeftCell, ptr ptr Range
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD

  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_Shadow, ptr BOOL
  COM_MTD_DSP  put_Shadow, BOOL
  COM_MTD_DSP  get_Formula, ptr BSTR
  COM_MTD_DSP  put_Formula, BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG Pictures, IDispatch, <000208A7-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  _Dummy3
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  _Dummy12
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  _Dummy15
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  _Dummy22
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_Shadow, ptr BOOL
  COM_MTD_DSP  put_Shadow, BOOL
  COM_MTD_DSP  get_Formula, ptr BSTR
  COM_MTD_DSP  put_Formula, BSTR
  COM_MTD_DSP  Add_, REAL8, REAL8, REAL8, REAL8, ptr ptr Picture
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Group_, ptr ptr GroupObject
  COM_MTD_DSP  Insert, BSTR, VARIANT, ptr ptr Picture
  COM_MTD_DSP  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
  COM_MTD_DSP  Paste, VARIANT, ptr ptr Picture
COM_INTERFACE_END

COM_INTERFACE_BEG Drawing, IDispatch, <000208A8-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_BottomRightCell, ptr ptr Range
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  get_TopLeftCell, ptr ptr Range
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get_AddIndent, ptr BOOL
  COM_MTD_DSP  put_AddIndent, BOOL
  COM_MTD_DSP  get_AutoScaleFont, ptr VARIANT
  COM_MTD_DSP  put_AutoScaleFont, VARIANT
  COM_MTD_DSP  get_AutoSize, ptr BOOL
  COM_MTD_DSP  put_AutoSize, BOOL
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_DSP  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_Font, ptr ptr Font
  COM_MTD_DSP  get_Formula, ptr BSTR
  COM_MTD_DSP  put_Formula, BSTR
  COM_MTD_DSP  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_DSP  put_HorizontalAlignment, VARIANT
  COM_MTD_DSP  get_LockedText, ptr BOOL
  COM_MTD_DSP  put_LockedText, BOOL
  COM_MTD_DSP  get_Orientation, ptr VARIANT
  COM_MTD_DSP  put_Orientation, VARIANT
  COM_MTD_DSP  get_Text, ptr BSTR
  COM_MTD_DSP  put_Text, BSTR
  COM_MTD_DSP  get_VerticalAlignment, ptr VARIANT
  COM_MTD_DSP  put_VerticalAlignment, VARIANT
  COM_MTD_DSP  get_ReadingOrder, ptr SDWORD
  COM_MTD_DSP  put_ReadingOrder, SDWORD
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_Shadow, ptr BOOL
  COM_MTD_DSP  put_Shadow, BOOL
  COM_MTD_DSP  AddVertex, REAL8, REAL8, ptr VARIANT
  COM_MTD_DSP  Reshape, SDWORD, BOOL, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_Vertices, VARIANT, VARIANT, ptr VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG Drawings, IDispatch, <000208A9-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  _Dummy3
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  _Dummy12
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  _Dummy15
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  _Dummy22
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  get_AddIndent, ptr BOOL
  COM_MTD_DSP  put_AddIndent, BOOL
  COM_MTD_DSP  get_AutoScaleFont, ptr VARIANT
  COM_MTD_DSP  put_AutoScaleFont, VARIANT
  COM_MTD_DSP  get_AutoSize, ptr BOOL
  COM_MTD_DSP  put_AutoSize, BOOL
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_DSP  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_Font, ptr ptr Font
  COM_MTD_DSP  get_Formula, ptr BSTR
  COM_MTD_DSP  put_Formula, BSTR
  COM_MTD_DSP  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_DSP  put_HorizontalAlignment, VARIANT
  COM_MTD_DSP  get_LockedText, ptr BOOL
  COM_MTD_DSP  put_LockedText, BOOL
  COM_MTD_DSP  get_Orientation, ptr VARIANT
  COM_MTD_DSP  put_Orientation, VARIANT
  COM_MTD_DSP  get_Text, ptr BSTR
  COM_MTD_DSP  put_Text, BSTR
  COM_MTD_DSP  get_VerticalAlignment, ptr VARIANT
  COM_MTD_DSP  put_VerticalAlignment, VARIANT
  COM_MTD_DSP  get_ReadingOrder, ptr SDWORD
  COM_MTD_DSP  put_ReadingOrder, SDWORD
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_Shadow, ptr BOOL
  COM_MTD_DSP  put_Shadow, BOOL
  COM_MTD_DSP  _Dummy44
  COM_MTD_DSP  Reshape, SDWORD, BOOL, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  _Dummy46
  COM_MTD_DSP  Add_, REAL8, REAL8, REAL8, REAL8, BOOL, ptr ptr Drawing
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Group_, ptr ptr GroupObject
  COM_MTD_DSP  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG RoutingSlip, IDispatch, <000208AA-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Delivery, ptr XlRoutingSlipDelivery
  COM_MTD_DSP  put_Delivery, XlRoutingSlipDelivery
  COM_MTD_DSP  get_Message, ptr VARIANT
  COM_MTD_DSP  put_Message, VARIANT
  COM_MTD_DSP  get_Recipients, VARIANT, ptr VARIANT
  COM_MTD_DSP  put_Recipients, VARIANT, VARIANT
  COM_MTD_DSP  Reset, ptr VARIANT
  COM_MTD_DSP  get_ReturnWhenDone, ptr BOOL
  COM_MTD_DSP  put_ReturnWhenDone, BOOL
  COM_MTD_DSP  get_Status, ptr XlRoutingSlipStatus
  COM_MTD_DSP  get_Subject, ptr VARIANT
  COM_MTD_DSP  put_Subject, VARIANT
  COM_MTD_DSP  get_TrackStatus, ptr BOOL
  COM_MTD_DSP  put_TrackStatus, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG Outline, IDispatch, <000208AB-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_AutomaticStyles, ptr BOOL
  COM_MTD_DSP  put_AutomaticStyles, BOOL
  COM_MTD_DSP  ShowLevels, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_SummaryColumn, ptr XlSummaryColumn
  COM_MTD_DSP  put_SummaryColumn, XlSummaryColumn
  COM_MTD_DSP  get_SummaryRow, ptr XlSummaryRow
  COM_MTD_DSP  put_SummaryRow, XlSummaryRow
COM_INTERFACE_END

COM_INTERFACE_BEG Module, IDispatch, <000208AD-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Activate
  COM_MTD_DSP  Copy, VARIANT, VARIANT
  COM_MTD_DSP  Delete
  COM_MTD_DSP  get_CodeName, ptr BSTR
  COM_MTD_DSP  get__CodeName, ptr BSTR
  COM_MTD_DSP  put__CodeName, BSTR
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  Move, VARIANT, VARIANT
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  get_Next, ptr LPDISPATCH
  COM_MTD_DSP  get_OnDoubleClick, ptr BSTR
  COM_MTD_DSP  put_OnDoubleClick, BSTR
  COM_MTD_DSP  get_OnSheetActivate, ptr BSTR
  COM_MTD_DSP  put_OnSheetActivate, BSTR
  COM_MTD_DSP  get_OnSheetDeactivate, ptr BSTR
  COM_MTD_DSP  put_OnSheetDeactivate, BSTR
  COM_MTD_DSP  get_PageSetup, ptr ptr PageSetup
  COM_MTD_DSP  get_Previous, ptr LPDISPATCH
  COM_MTD_DSP  _PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_DSP  _Dummy18
  COM_MTD_DSP  _Protect, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_DSP  get_ProtectContents, ptr BOOL
  COM_MTD_DSP  _Dummy21
  COM_MTD_DSP  get_ProtectionMode, ptr BOOL
  COM_MTD_DSP  _Dummy23
  COM_MTD_DSP  _SaveAs, BSTR, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_DSP  Select, VARIANT
  COM_MTD_DSP  Unprotect, VARIANT
  COM_MTD_DSP  get_Visible, ptr XlSheetVisibility
  COM_MTD_DSP  put_Visible, XlSheetVisibility
  COM_MTD_DSP  get_Shapes, ptr ptr Shapes
  COM_MTD_DSP  InsertFile, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  SaveAs, BSTR, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_DSP  Protect, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG Modules, IDispatch, <000208AE-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Add_, VARIANT, VARIANT, VARIANT, ptr ptr Module
  COM_MTD_DSP  Copy, VARIANT, VARIANT
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Delete
  COM_MTD_DSP  _Dummy7
  COM_MTD_DSP  get_Item, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  Move, VARIANT, VARIANT
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_DSP  _PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_DSP  _Dummy12
  COM_MTD_DSP  Select, VARIANT
  COM_MTD_DSP  get_HPageBreaks, ptr ptr HPageBreaks
  COM_MTD_DSP  get_VPageBreaks, ptr ptr VPageBreaks
  COM_MTD_DSP  get_Visible, ptr VARIANT
  COM_MTD_DSP  put_Visible, VARIANT
  COM_MTD_DSP  get__Default, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG DialogSheet, IDispatch, <000208AF-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Activate
  COM_MTD_DSP  Copy, VARIANT, VARIANT
  COM_MTD_DSP  Delete
  COM_MTD_DSP  get_CodeName, ptr BSTR
  COM_MTD_DSP  get__CodeName, ptr BSTR
  COM_MTD_DSP  put__CodeName, BSTR
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  Move, VARIANT, VARIANT
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  get_Next, ptr LPDISPATCH
  COM_MTD_DSP  get_OnDoubleClick, ptr BSTR
  COM_MTD_DSP  put_OnDoubleClick, BSTR
  COM_MTD_DSP  get_OnSheetActivate, ptr BSTR
  COM_MTD_DSP  put_OnSheetActivate, BSTR
  COM_MTD_DSP  get_OnSheetDeactivate, ptr BSTR
  COM_MTD_DSP  put_OnSheetDeactivate, BSTR
  COM_MTD_DSP  get_PageSetup, ptr ptr PageSetup
  COM_MTD_DSP  get_Previous, ptr LPDISPATCH
  COM_MTD_DSP  _PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_DSP  PrintPreview, VARIANT
  COM_MTD_DSP  _Protect, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_DSP  get_ProtectContents, ptr BOOL
  COM_MTD_DSP  get_ProtectDrawingObjects, ptr BOOL
  COM_MTD_DSP  get_ProtectionMode, ptr BOOL
  COM_MTD_DSP  get_ProtectScenarios, ptr BOOL
  COM_MTD_DSP  _SaveAs, BSTR, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_DSP  Select, VARIANT
  COM_MTD_DSP  Unprotect, VARIANT
  COM_MTD_DSP  get_Visible, ptr XlSheetVisibility
  COM_MTD_DSP  put_Visible, XlSheetVisibility
  COM_MTD_DSP  get_Shapes, ptr ptr Shapes
  COM_MTD_DSP  _Dummy29
  COM_MTD_DSP  Arcs, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  _Dummy31
  COM_MTD_DSP  _Dummy32
  COM_MTD_DSP  Buttons, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  _Dummy34
  COM_MTD_DSP  get_EnableCalculation, ptr BOOL
  COM_MTD_DSP  put_EnableCalculation, BOOL
  COM_MTD_DSP  _Dummy36
  COM_MTD_DSP  ChartObjects, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  CheckBoxes, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_DSP  _Dummy40
  COM_MTD_DSP  _Dummy41
  COM_MTD_DSP  _Dummy42
  COM_MTD_DSP  _Dummy43
  COM_MTD_DSP  _Dummy44
  COM_MTD_DSP  _Dummy45
  COM_MTD_DSP  get_DisplayAutomaticPageBreaks, ptr BOOL
  COM_MTD_DSP  put_DisplayAutomaticPageBreaks, BOOL
  COM_MTD_DSP  Drawings, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  DrawingObjects, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  DropDowns, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  get_EnableAutoFilter, ptr BOOL
  COM_MTD_DSP  put_EnableAutoFilter, BOOL
  COM_MTD_DSP  get_EnableSelection, ptr XlEnableSelection
  COM_MTD_DSP  put_EnableSelection, XlEnableSelection
  COM_MTD_DSP  get_EnableOutlining, ptr BOOL
  COM_MTD_DSP  put_EnableOutlining, BOOL
  COM_MTD_DSP  get_EnablePivotTable, ptr BOOL
  COM_MTD_DSP  put_EnablePivotTable, BOOL
  COM_MTD_DSP  Evaluate, VARIANT, ptr VARIANT
  COM_MTD_DSP  _Evaluate, VARIANT, ptr VARIANT
  COM_MTD_DSP  _Dummy56
  COM_MTD_DSP  ResetAllPageBreaks
  COM_MTD_DSP  GroupBoxes, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  GroupObjects, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  Labels, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  Lines, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  ListBoxes, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  get_Names, ptr ptr Names
  COM_MTD_DSP  OLEObjects, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  _Dummy65
  COM_MTD_DSP  _Dummy66
  COM_MTD_DSP  _Dummy67
  COM_MTD_DSP  OptionButtons, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  _Dummy69
  COM_MTD_DSP  Ovals, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  Paste, VARIANT, VARIANT
  COM_MTD_DSP  _PasteSpecial, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_DSP  Pictures, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  _Dummy74
  COM_MTD_DSP  _Dummy75
  COM_MTD_DSP  _Dummy76
  COM_MTD_DSP  Rectangles, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  _Dummy78
  COM_MTD_DSP  _Dummy79
  COM_MTD_DSP  get_ScrollArea, ptr BSTR
  COM_MTD_DSP  put_ScrollArea, BSTR
  COM_MTD_DSP  ScrollBars, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  _Dummy82
  COM_MTD_DSP  _Dummy83
  COM_MTD_DSP  Spinners, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  _Dummy85
  COM_MTD_DSP  _Dummy86
  COM_MTD_DSP  TextBoxes, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  _Dummy88
  COM_MTD_DSP  _Dummy89
  COM_MTD_DSP  _Dummy90
  COM_MTD_DSP  get_HPageBreaks, ptr ptr HPageBreaks
  COM_MTD_DSP  get_VPageBreaks, ptr ptr VPageBreaks
  COM_MTD_DSP  get_QueryTables, ptr ptr QueryTables
  COM_MTD_DSP  get_DisplayPageBreaks, ptr BOOL
  COM_MTD_DSP  put_DisplayPageBreaks, BOOL
  COM_MTD_DSP  get_Comments, ptr ptr Comments
  COM_MTD_DSP  get_Hyperlinks, ptr ptr Hyperlinks
  COM_MTD_DSP  ClearCircles
  COM_MTD_DSP  CircleInvalid
  COM_MTD_DSP  get__DisplayRightToLeft, ptr SDWORD
  COM_MTD_DSP  put__DisplayRightToLeft, SDWORD
  COM_MTD_DSP  get_AutoFilter, ptr ptr AutoFilter
  COM_MTD_DSP  get_DisplayRightToLeft, ptr BOOL
  COM_MTD_DSP  put_DisplayRightToLeft, BOOL
  COM_MTD_DSP  get_Scripts, ptr ptr Scripts
  COM_MTD_DSP  PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_DSP  _CheckSpelling, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_DSP  get_Tab, ptr ptr Tab
  COM_MTD_DSP  get_MailEnvelope, ptr ptr MsoEnvelope
  COM_MTD_DSP  SaveAs, BSTR, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_DSP  get_CustomProperties, ptr ptr CustomProperties
  COM_MTD_DSP  get_SmartTags, ptr ptr SmartTags
  COM_MTD_DSP  get_Protection, ptr ptr Protection
  COM_MTD_DSP  PasteSpecial, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_DSP  Protect, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_DSP  get_DefaultButton, ptr VARIANT
  COM_MTD_DSP  put_DefaultButton, VARIANT
  COM_MTD_DSP  get_DialogFrame, ptr ptr DialogFrame
  COM_MTD_DSP  EditBoxes, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  get_Focus, ptr VARIANT
  COM_MTD_DSP  put_Focus, VARIANT
  COM_MTD_DSP  Hide, VARIANT, ptr BOOL
  COM_MTD_DSP  Show, ptr BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG DialogSheets, IDispatch, <000208B0-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Add_, VARIANT, VARIANT, VARIANT, ptr ptr DialogSheet
  COM_MTD_DSP  Copy, VARIANT, VARIANT
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Delete
  COM_MTD_DSP  _Dummy7
  COM_MTD_DSP  get_Item, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  Move, VARIANT, VARIANT
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_DSP  _PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_DSP  PrintPreview, VARIANT
  COM_MTD_DSP  Select, VARIANT
  COM_MTD_DSP  get_HPageBreaks, ptr ptr HPageBreaks
  COM_MTD_DSP  get_VPageBreaks, ptr ptr VPageBreaks
  COM_MTD_DSP  get_Visible, ptr VARIANT
  COM_MTD_DSP  put_Visible, VARIANT
  COM_MTD_DSP  get__Default, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG Worksheets, IDispatch, <000208B1-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Add_, VARIANT, VARIANT, VARIANT, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  Copy, VARIANT, VARIANT
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Delete
  COM_MTD_DSP  FillAcrossSheets, ptr Range, XlFillWith
  COM_MTD_DSP  get_Item, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  Move, VARIANT, VARIANT
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_DSP  _PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_DSP  PrintPreview, VARIANT
  COM_MTD_DSP  Select, VARIANT
  COM_MTD_DSP  get_HPageBreaks, ptr ptr HPageBreaks
  COM_MTD_DSP  get_VPageBreaks, ptr ptr VPageBreaks
  COM_MTD_DSP  get_Visible, ptr VARIANT
  COM_MTD_DSP  put_Visible, VARIANT
  COM_MTD_DSP  get__Default, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG PageSetup, IDispatch, <000208B4-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_BlackAndWhite, ptr BOOL
  COM_MTD_DSP  put_BlackAndWhite, BOOL
  COM_MTD_DSP  get_BottomMargin, ptr REAL8
  COM_MTD_DSP  put_BottomMargin, REAL8
  COM_MTD_DSP  get_CenterFooter, ptr BSTR
  COM_MTD_DSP  put_CenterFooter, BSTR
  COM_MTD_DSP  get_CenterHeader, ptr BSTR
  COM_MTD_DSP  put_CenterHeader, BSTR
  COM_MTD_DSP  get_CenterHorizontally, ptr BOOL
  COM_MTD_DSP  put_CenterHorizontally, BOOL
  COM_MTD_DSP  get_CenterVertically, ptr BOOL
  COM_MTD_DSP  put_CenterVertically, BOOL
  COM_MTD_DSP  get_ChartSize, ptr XlObjectSize
  COM_MTD_DSP  put_ChartSize, XlObjectSize
  COM_MTD_DSP  get_Draft, ptr BOOL
  COM_MTD_DSP  put_Draft, BOOL
  COM_MTD_DSP  get_FirstPageNumber, ptr SDWORD
  COM_MTD_DSP  put_FirstPageNumber, SDWORD
  COM_MTD_DSP  get_FitToPagesTall, ptr VARIANT
  COM_MTD_DSP  put_FitToPagesTall, VARIANT
  COM_MTD_DSP  get_FitToPagesWide, ptr VARIANT
  COM_MTD_DSP  put_FitToPagesWide, VARIANT
  COM_MTD_DSP  get_FooterMargin, ptr REAL8
  COM_MTD_DSP  put_FooterMargin, REAL8
  COM_MTD_DSP  get_HeaderMargin, ptr REAL8
  COM_MTD_DSP  put_HeaderMargin, REAL8
  COM_MTD_DSP  get_LeftFooter, ptr BSTR
  COM_MTD_DSP  put_LeftFooter, BSTR
  COM_MTD_DSP  get_LeftHeader, ptr BSTR
  COM_MTD_DSP  put_LeftHeader, BSTR
  COM_MTD_DSP  get_LeftMargin, ptr REAL8
  COM_MTD_DSP  put_LeftMargin, REAL8
  COM_MTD_DSP  get_Order, ptr XlOrder
  COM_MTD_DSP  put_Order, XlOrder
  COM_MTD_DSP  get_Orientation, ptr XlPageOrientation
  COM_MTD_DSP  put_Orientation, XlPageOrientation
  COM_MTD_DSP  get_PaperSize, ptr XlPaperSize
  COM_MTD_DSP  put_PaperSize, XlPaperSize
  COM_MTD_DSP  get_PrintArea, ptr BSTR
  COM_MTD_DSP  put_PrintArea, BSTR
  COM_MTD_DSP  get_PrintGridlines, ptr BOOL
  COM_MTD_DSP  put_PrintGridlines, BOOL
  COM_MTD_DSP  get_PrintHeadings, ptr BOOL
  COM_MTD_DSP  put_PrintHeadings, BOOL
  COM_MTD_DSP  get_PrintNotes, ptr BOOL
  COM_MTD_DSP  put_PrintNotes, BOOL
  COM_MTD_DSP  get_PrintQuality, VARIANT, ptr VARIANT
  COM_MTD_DSP  put_PrintQuality, VARIANT, VARIANT
  COM_MTD_DSP  get_PrintTitleColumns, ptr BSTR
  COM_MTD_DSP  put_PrintTitleColumns, BSTR
  COM_MTD_DSP  get_PrintTitleRows, ptr BSTR
  COM_MTD_DSP  put_PrintTitleRows, BSTR
  COM_MTD_DSP  get_RightFooter, ptr BSTR
  COM_MTD_DSP  put_RightFooter, BSTR
  COM_MTD_DSP  get_RightHeader, ptr BSTR
  COM_MTD_DSP  put_RightHeader, BSTR
  COM_MTD_DSP  get_RightMargin, ptr REAL8
  COM_MTD_DSP  put_RightMargin, REAL8
  COM_MTD_DSP  get_TopMargin, ptr REAL8
  COM_MTD_DSP  put_TopMargin, REAL8
  COM_MTD_DSP  get_Zoom, ptr VARIANT
  COM_MTD_DSP  put_Zoom, VARIANT
  COM_MTD_DSP  get_PrintComments, ptr XlPrintLocation
  COM_MTD_DSP  put_PrintComments, XlPrintLocation
  COM_MTD_DSP  get_PrintErrors, ptr XlPrintErrors
  COM_MTD_DSP  put_PrintErrors, XlPrintErrors
  COM_MTD_DSP  get_CenterHeaderPicture, ptr ptr Graphic
  COM_MTD_DSP  get_CenterFooterPicture, ptr ptr Graphic
  COM_MTD_DSP  get_LeftHeaderPicture, ptr ptr Graphic
  COM_MTD_DSP  get_LeftFooterPicture, ptr ptr Graphic
  COM_MTD_DSP  get_RightHeaderPicture, ptr ptr Graphic
  COM_MTD_DSP  get_RightFooterPicture, ptr ptr Graphic
COM_INTERFACE_END

COM_INTERFACE_BEG Names, IDispatch, <000208B8-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Add_, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr ptr Name_
  COM_MTD_DSP  Item, VARIANT, VARIANT, VARIANT, ptr ptr Name_
  COM_MTD_DSP  _Default, VARIANT, VARIANT, VARIANT, ptr ptr Name_
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG Name_, IDispatch, <000208B9-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get__Default, ptr BSTR
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  get_Category, ptr BSTR
  COM_MTD_DSP  put_Category, BSTR
  COM_MTD_DSP  get_CategoryLocal, ptr BSTR
  COM_MTD_DSP  put_CategoryLocal, BSTR
  COM_MTD_DSP  Delete
  COM_MTD_DSP  get_MacroType, ptr XlXLMMacroType
  COM_MTD_DSP  put_MacroType, XlXLMMacroType
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  get_RefersTo, ptr VARIANT
  COM_MTD_DSP  put_RefersTo, VARIANT
  COM_MTD_DSP  get_ShortcutKey, ptr BSTR
  COM_MTD_DSP  put_ShortcutKey, BSTR
  COM_MTD_DSP  get_Value, ptr BSTR
  COM_MTD_DSP  put_Value, BSTR
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_NameLocal, ptr BSTR
  COM_MTD_DSP  put_NameLocal, BSTR
  COM_MTD_DSP  get_RefersToLocal, ptr VARIANT
  COM_MTD_DSP  put_RefersToLocal, VARIANT
  COM_MTD_DSP  get_RefersToR1C1, ptr VARIANT
  COM_MTD_DSP  put_RefersToR1C1, VARIANT
  COM_MTD_DSP  get_RefersToR1C1Local, ptr VARIANT
  COM_MTD_DSP  put_RefersToR1C1Local, VARIANT
  COM_MTD_DSP  get_RefersToRange, ptr ptr Range
COM_INTERFACE_END

COM_INTERFACE_BEG ChartObject, IDispatch, <000208CF-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_BottomRightCell, ptr ptr Range
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  get_TopLeftCell, ptr ptr Range
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_ZOrder, ptr SDWORD
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  Activate, ptr VARIANT
  COM_MTD_DSP  get_Chart, ptr ptr Chart
  COM_MTD_DSP  get_ProtectChartObject, ptr BOOL
  COM_MTD_DSP  put_ProtectChartObject, BOOL
  COM_MTD_DSP  get_RoundedCorners, ptr BOOL
  COM_MTD_DSP  put_RoundedCorners, BOOL
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_Shadow, ptr BOOL
  COM_MTD_DSP  put_Shadow, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG ChartObjects, IDispatch, <000208D0-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  _Dummy3
  COM_MTD_DSP  BringToFront, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  CopyPicture, XlPictureAppearance, XlCopyPictureFormat, ptr VARIANT
  COM_MTD_DSP  Cut, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  Duplicate, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  _Dummy12
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  _Dummy15
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Placement, ptr VARIANT
  COM_MTD_DSP  put_Placement, VARIANT
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  Select, VARIANT, ptr VARIANT
  COM_MTD_DSP  SendToBack, ptr VARIANT
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  _Dummy22
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  _Dummy25
  COM_MTD_DSP  get_ShapeRange, ptr ptr ShapeRange
  COM_MTD_DSP  _Dummy27
  COM_MTD_DSP  _Dummy28
  COM_MTD_DSP  _Dummy29
  COM_MTD_DSP  get_RoundedCorners, ptr BOOL
  COM_MTD_DSP  put_RoundedCorners, BOOL
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_Shadow, ptr BOOL
  COM_MTD_DSP  put_Shadow, BOOL
  COM_MTD_DSP  Add_, REAL8, REAL8, REAL8, REAL8, ptr ptr ChartObject
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Group_, ptr ptr GroupObject
  COM_MTD_DSP  Item, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG Mailer, IDispatch, <000208D1-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_BCCRecipients, ptr VARIANT
  COM_MTD_DSP  put_BCCRecipients, VARIANT
  COM_MTD_DSP  get_CCRecipients, ptr VARIANT
  COM_MTD_DSP  put_CCRecipients, VARIANT
  COM_MTD_DSP  get_Enclosures, ptr VARIANT
  COM_MTD_DSP  put_Enclosures, VARIANT
  COM_MTD_DSP  get_Received, ptr BOOL
  COM_MTD_DSP  get_SendDateTime, ptr Date
  COM_MTD_DSP  get_Sender, ptr BSTR
  COM_MTD_DSP  get_Subject, ptr BSTR
  COM_MTD_DSP  put_Subject, BSTR
  COM_MTD_DSP  get_ToRecipients, ptr VARIANT
  COM_MTD_DSP  put_ToRecipients, VARIANT
  COM_MTD_DSP  get_WhichAddress, ptr VARIANT
  COM_MTD_DSP  put_WhichAddress, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG CustomViews, IDispatch, <00024422-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Item, VARIANT, ptr ptr CustomView
  COM_MTD_DSP  Add_, BSTR, VARIANT, VARIANT, ptr ptr CustomView
  COM_MTD_DSP  get__Default, VARIANT, ptr ptr CustomView
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG CustomView, IDispatch, <00024423-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  get_PrintSettings, ptr BOOL
  COM_MTD_DSP  get_RowColSettings, ptr BOOL
  COM_MTD_DSP  Show
  COM_MTD_DSP  Delete
COM_INTERFACE_END

COM_INTERFACE_BEG FormatConditions, IDispatch, <00024424-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Item, VARIANT, ptr ptr FormatCondition
  COM_MTD_DSP  Add_, XlFormatConditionType, VARIANT, VARIANT, VARIANT, ptr ptr FormatCondition
  COM_MTD_DSP  get__Default, VARIANT, ptr ptr FormatCondition
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_DSP  Delete
COM_INTERFACE_END

COM_INTERFACE_BEG FormatCondition, IDispatch, <00024425-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Modify, XlFormatConditionType, VARIANT, VARIANT, VARIANT
  COM_MTD_DSP  get_Type, ptr SDWORD
  COM_MTD_DSP  get_Operator, ptr SDWORD
  COM_MTD_DSP  get_Formula1, ptr BSTR
  COM_MTD_DSP  get_Formula2, ptr BSTR
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_Borders, ptr ptr Borders
  COM_MTD_DSP  get_Font, ptr ptr Font
  COM_MTD_DSP  Delete
COM_INTERFACE_END

COM_INTERFACE_BEG Comments, IDispatch, <00024426-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Item, SDWORD, ptr ptr Comment_
  COM_MTD_DSP  get__Default, SDWORD, ptr ptr Comment_
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG Comment_, IDispatch, <00024427-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Author, ptr BSTR
  COM_MTD_DSP  get_Shape, ptr ptr Shape
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  Text, VARIANT, VARIANT, VARIANT, ptr BSTR
  COM_MTD_DSP  Delete
  COM_MTD_DSP  Next, ptr ptr Comment_
  COM_MTD_DSP  Previous, ptr ptr Comment_
COM_INTERFACE_END

COM_INTERFACE_BEG RefreshEvents, IDispatch, <0002441B-0000-0000-C000-000000000046>
  COM_MTD_DSP  BeforeRefresh, ptr BOOL
  COM_MTD_DSP  AfterRefresh, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG _QueryTable, IDispatch, <00024428-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  get_FieldNames, ptr BOOL
  COM_MTD_DSP  put_FieldNames, BOOL
  COM_MTD_DSP  get_RowNumbers, ptr BOOL
  COM_MTD_DSP  put_RowNumbers, BOOL
  COM_MTD_DSP  get_FillAdjacentFormulas, ptr BOOL
  COM_MTD_DSP  put_FillAdjacentFormulas, BOOL
  COM_MTD_DSP  get_HasAutoFormat, ptr BOOL
  COM_MTD_DSP  put_HasAutoFormat, BOOL
  COM_MTD_DSP  get_RefreshOnFileOpen, ptr BOOL
  COM_MTD_DSP  put_RefreshOnFileOpen, BOOL
  COM_MTD_DSP  get_Refreshing, ptr BOOL
  COM_MTD_DSP  get_FetchedRowOverflow, ptr BOOL
  COM_MTD_DSP  get_BackgroundQuery, ptr BOOL
  COM_MTD_DSP  put_BackgroundQuery, BOOL
  COM_MTD_DSP  CancelRefresh
  COM_MTD_DSP  get_RefreshStyle, ptr XlCellInsertionMode
  COM_MTD_DSP  put_RefreshStyle, XlCellInsertionMode
  COM_MTD_DSP  get_EnableRefresh, ptr BOOL
  COM_MTD_DSP  put_EnableRefresh, BOOL
  COM_MTD_DSP  get_SavePassword, ptr BOOL
  COM_MTD_DSP  put_SavePassword, BOOL
  COM_MTD_DSP  get_Destination, ptr ptr Range
  COM_MTD_DSP  get_Connection, ptr VARIANT
  COM_MTD_DSP  put_Connection, VARIANT
  COM_MTD_DSP  get_Sql, ptr VARIANT
  COM_MTD_DSP  put_Sql, VARIANT
  COM_MTD_DSP  get_PostText, ptr BSTR
  COM_MTD_DSP  put_PostText, BSTR
  COM_MTD_DSP  get_ResultRange, ptr ptr Range
  COM_MTD_DSP  Delete
  COM_MTD_DSP  Refresh, VARIANT, ptr BOOL
  COM_MTD_DSP  get_Parameters, ptr ptr Parameters
  COM_MTD_DSP  get_Recordset, ptr LPDISPATCH
  COM_MTD_DSP  putref_Recordset, LPDISPATCH
  COM_MTD_DSP  get_SaveData, ptr BOOL
  COM_MTD_DSP  put_SaveData, BOOL
  COM_MTD_DSP  get_TablesOnlyFromHTML, ptr BOOL
  COM_MTD_DSP  put_TablesOnlyFromHTML, BOOL
  COM_MTD_DSP  get_EnableEditing, ptr BOOL
  COM_MTD_DSP  put_EnableEditing, BOOL
  COM_MTD_DSP  get_TextFilePlatform, ptr SDWORD
  COM_MTD_DSP  put_TextFilePlatform, SDWORD
  COM_MTD_DSP  get_TextFileStartRow, ptr SDWORD
  COM_MTD_DSP  put_TextFileStartRow, SDWORD
  COM_MTD_DSP  get_TextFileParseType, ptr XlTextParsingType
  COM_MTD_DSP  put_TextFileParseType, XlTextParsingType
  COM_MTD_DSP  get_TextFileTextQualifier, ptr XlTextQualifier
  COM_MTD_DSP  put_TextFileTextQualifier, XlTextQualifier
  COM_MTD_DSP  get_TextFileConsecutiveDelimiter, ptr BOOL
  COM_MTD_DSP  put_TextFileConsecutiveDelimiter, BOOL
  COM_MTD_DSP  get_TextFileTabDelimiter, ptr BOOL
  COM_MTD_DSP  put_TextFileTabDelimiter, BOOL
  COM_MTD_DSP  get_TextFileSemicolonDelimiter, ptr BOOL
  COM_MTD_DSP  put_TextFileSemicolonDelimiter, BOOL
  COM_MTD_DSP  get_TextFileCommaDelimiter, ptr BOOL
  COM_MTD_DSP  put_TextFileCommaDelimiter, BOOL
  COM_MTD_DSP  get_TextFileSpaceDelimiter, ptr BOOL
  COM_MTD_DSP  put_TextFileSpaceDelimiter, BOOL
  COM_MTD_DSP  get_TextFileOtherDelimiter, ptr BSTR
  COM_MTD_DSP  put_TextFileOtherDelimiter, BSTR
  COM_MTD_DSP  get_TextFileColumnDataTypes, ptr VARIANT
  COM_MTD_DSP  put_TextFileColumnDataTypes, VARIANT
  COM_MTD_DSP  get_TextFileFixedColumnWidths, ptr VARIANT
  COM_MTD_DSP  put_TextFileFixedColumnWidths, VARIANT
  COM_MTD_DSP  get_PreserveColumnInfo, ptr BOOL
  COM_MTD_DSP  put_PreserveColumnInfo, BOOL
  COM_MTD_DSP  get_PreserveFormatting, ptr BOOL
  COM_MTD_DSP  put_PreserveFormatting, BOOL
  COM_MTD_DSP  get_AdjustColumnWidth, ptr BOOL
  COM_MTD_DSP  put_AdjustColumnWidth, BOOL
  COM_MTD_DSP  get_CommandText, ptr VARIANT
  COM_MTD_DSP  put_CommandText, VARIANT
  COM_MTD_DSP  get_CommandType, ptr XlCmdType
  COM_MTD_DSP  put_CommandType, XlCmdType
  COM_MTD_DSP  get_TextFilePromptOnRefresh, ptr BOOL
  COM_MTD_DSP  put_TextFilePromptOnRefresh, BOOL
  COM_MTD_DSP  get_QueryType, ptr XlQueryType
  COM_MTD_DSP  get_MaintainConnection, ptr BOOL
  COM_MTD_DSP  put_MaintainConnection, BOOL
  COM_MTD_DSP  get_TextFileDecimalSeparator, ptr BSTR
  COM_MTD_DSP  put_TextFileDecimalSeparator, BSTR
  COM_MTD_DSP  get_TextFileThousandsSeparator, ptr BSTR
  COM_MTD_DSP  put_TextFileThousandsSeparator, BSTR
  COM_MTD_DSP  get_RefreshPeriod, ptr SDWORD
  COM_MTD_DSP  put_RefreshPeriod, SDWORD
  COM_MTD_DSP  ResetTimer
  COM_MTD_DSP  get_WebSelectionType, ptr XlWebSelectionType
  COM_MTD_DSP  put_WebSelectionType, XlWebSelectionType
  COM_MTD_DSP  get_WebFormatting, ptr XlWebFormatting
  COM_MTD_DSP  put_WebFormatting, XlWebFormatting
  COM_MTD_DSP  get_WebTables, ptr BSTR
  COM_MTD_DSP  put_WebTables, BSTR
  COM_MTD_DSP  get_WebPreFormattedTextToColumns, ptr BOOL
  COM_MTD_DSP  put_WebPreFormattedTextToColumns, BOOL
  COM_MTD_DSP  get_WebSingleBlockTextImport, ptr BOOL
  COM_MTD_DSP  put_WebSingleBlockTextImport, BOOL
  COM_MTD_DSP  get_WebDisableDateRecognition, ptr BOOL
  COM_MTD_DSP  put_WebDisableDateRecognition, BOOL
  COM_MTD_DSP  get_WebConsecutiveDelimitersAsOne, ptr BOOL
  COM_MTD_DSP  put_WebConsecutiveDelimitersAsOne, BOOL
  COM_MTD_DSP  get_WebDisableRedirections, ptr BOOL
  COM_MTD_DSP  put_WebDisableRedirections, BOOL
  COM_MTD_DSP  get_EditWebPage, ptr VARIANT
  COM_MTD_DSP  put_EditWebPage, VARIANT
  COM_MTD_DSP  get_SourceConnectionFile, ptr BSTR
  COM_MTD_DSP  put_SourceConnectionFile, BSTR
  COM_MTD_DSP  get_SourceDataFile, ptr BSTR
  COM_MTD_DSP  put_SourceDataFile, BSTR
  COM_MTD_DSP  get_RobustConnect, ptr XlRobustConnect
  COM_MTD_DSP  put_RobustConnect, XlRobustConnect
  COM_MTD_DSP  get_TextFileTrailingMinusNumbers, ptr BOOL
  COM_MTD_DSP  put_TextFileTrailingMinusNumbers, BOOL
  COM_MTD_DSP  SaveAsODC, BSTR, VARIANT, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG QueryTables, IDispatch, <00024429-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Add_, VARIANT, ptr Range, VARIANT, ptr ptr QueryTable
  COM_MTD_DSP  Item, VARIANT, ptr ptr QueryTable
  COM_MTD_DSP  get__Default, VARIANT, ptr ptr QueryTable
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG Parameter, IDispatch, <0002442A-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_DataType, ptr XlParameterDataType
  COM_MTD_DSP  put_DataType, XlParameterDataType
  COM_MTD_DSP  get_Type, ptr XlParameterType
  COM_MTD_DSP  get_PromptString, ptr BSTR
  COM_MTD_DSP  get_Value, ptr VARIANT
  COM_MTD_DSP  get_SourceRange, ptr ptr Range
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  SetParam, XlParameterType, VARIANT
  COM_MTD_DSP  get_RefreshOnChange, ptr BOOL
  COM_MTD_DSP  put_RefreshOnChange, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG Parameters, IDispatch, <0002442B-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Add_, BSTR, VARIANT, ptr ptr Parameter
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Item, VARIANT, ptr ptr Parameter
  COM_MTD_DSP  get__Default, VARIANT, ptr ptr Parameter
  COM_MTD_DSP  Delete
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG ODBCError, IDispatch, <0002442C-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_SqlState, ptr BSTR
  COM_MTD_DSP  get_ErrorString, ptr BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG ODBCErrors, IDispatch, <0002442D-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Item, SDWORD, ptr ptr ODBCError
  COM_MTD_DSP  get__Default, SDWORD, ptr ptr ODBCError
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG Validation, IDispatch, <0002442F-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Add_, XlDVType, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_DSP  get_AlertStyle, ptr SDWORD
  COM_MTD_DSP  get_IgnoreBlank, ptr BOOL
  COM_MTD_DSP  put_IgnoreBlank, BOOL
  COM_MTD_DSP  get_IMEMode, ptr SDWORD
  COM_MTD_DSP  put_IMEMode, SDWORD
  COM_MTD_DSP  get_InCellDropdown, ptr BOOL
  COM_MTD_DSP  put_InCellDropdown, BOOL
  COM_MTD_DSP  Delete
  COM_MTD_DSP  get_ErrorMessage, ptr BSTR
  COM_MTD_DSP  put_ErrorMessage, BSTR
  COM_MTD_DSP  get_ErrorTitle, ptr BSTR
  COM_MTD_DSP  put_ErrorTitle, BSTR
  COM_MTD_DSP  get_InputMessage, ptr BSTR
  COM_MTD_DSP  put_InputMessage, BSTR
  COM_MTD_DSP  get_InputTitle, ptr BSTR
  COM_MTD_DSP  put_InputTitle, BSTR
  COM_MTD_DSP  get_Formula1, ptr BSTR
  COM_MTD_DSP  get_Formula2, ptr BSTR
  COM_MTD_DSP  Modify, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_DSP  get_Operator, ptr SDWORD
  COM_MTD_DSP  get_ShowError, ptr BOOL
  COM_MTD_DSP  put_ShowError, BOOL
  COM_MTD_DSP  get_ShowInput, ptr BOOL
  COM_MTD_DSP  put_ShowInput, BOOL
  COM_MTD_DSP  get_Type, ptr SDWORD
  COM_MTD_DSP  get_Value, ptr BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG Hyperlinks, IDispatch, <00024430-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Add_, LPDISPATCH, BSTR, VARIANT, VARIANT, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  get_Item, VARIANT, ptr ptr Hyperlink
  COM_MTD_DSP  get__Default, VARIANT, ptr ptr Hyperlink
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_DSP  Delete
COM_INTERFACE_END

COM_INTERFACE_BEG Hyperlink, IDispatch, <00024431-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  get_Range, ptr ptr Range
  COM_MTD_DSP  get_Shape, ptr ptr Shape
  COM_MTD_DSP  get_SubAddress, ptr BSTR
  COM_MTD_DSP  put_SubAddress, BSTR
  COM_MTD_DSP  get_Address, ptr BSTR
  COM_MTD_DSP  put_Address, BSTR
  COM_MTD_DSP  get_Type, ptr SDWORD
  COM_MTD_DSP  AddToFavorites
  COM_MTD_DSP  Delete
  COM_MTD_DSP  Follow, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_DSP  get_EmailSubject, ptr BSTR
  COM_MTD_DSP  put_EmailSubject, BSTR
  COM_MTD_DSP  get_ScreenTip, ptr BSTR
  COM_MTD_DSP  put_ScreenTip, BSTR
  COM_MTD_DSP  get_TextToDisplay, ptr BSTR
  COM_MTD_DSP  put_TextToDisplay, BSTR
  COM_MTD_DSP  CreateNewDocument, BSTR, BOOL, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG AutoFilter, IDispatch, <00024432-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Range, ptr ptr Range
  COM_MTD_DSP  get_Filters, ptr ptr Filters
COM_INTERFACE_END

COM_INTERFACE_BEG Filters, IDispatch, <00024433-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  get__Default, SDWORD, ptr ptr Filter
  COM_MTD_DSP  get_Item, SDWORD, ptr ptr Filter
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG Filter, IDispatch, <00024434-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_On, ptr BOOL
  COM_MTD_DSP  get_Criteria1, ptr VARIANT
  COM_MTD_DSP  get_Operator, ptr XlAutoFilterOperator
  COM_MTD_DSP  get_Criteria2, ptr VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG AutoCorrect, IDispatch, <000208D4-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  AddReplacement, BSTR, BSTR, ptr VARIANT
  COM_MTD_DSP  get_CapitalizeNamesOfDays, ptr BOOL
  COM_MTD_DSP  put_CapitalizeNamesOfDays, BOOL
  COM_MTD_DSP  DeleteReplacement, BSTR, ptr VARIANT
  COM_MTD_DSP  get_ReplacementList, VARIANT, ptr VARIANT
  COM_MTD_DSP  put_ReplacementList, VARIANT, VARIANT
  COM_MTD_DSP  get_ReplaceText, ptr BOOL
  COM_MTD_DSP  put_ReplaceText, BOOL
  COM_MTD_DSP  get_TwoInitialCapitals, ptr BOOL
  COM_MTD_DSP  put_TwoInitialCapitals, BOOL
  COM_MTD_DSP  get_CorrectSentenceCap, ptr BOOL
  COM_MTD_DSP  put_CorrectSentenceCap, BOOL
  COM_MTD_DSP  get_CorrectCapsLock, ptr BOOL
  COM_MTD_DSP  put_CorrectCapsLock, BOOL
  COM_MTD_DSP  get_DisplayAutoCorrectOptions, ptr BOOL
  COM_MTD_DSP  put_DisplayAutoCorrectOptions, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG Border, IDispatch, <00020854-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Color, ptr VARIANT
  COM_MTD_DSP  put_Color, VARIANT
  COM_MTD_DSP  get_ColorIndex, ptr VARIANT
  COM_MTD_DSP  put_ColorIndex, VARIANT
  COM_MTD_DSP  get_LineStyle, ptr VARIANT
  COM_MTD_DSP  put_LineStyle, VARIANT
  COM_MTD_DSP  get_Weight, ptr VARIANT
  COM_MTD_DSP  put_Weight, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG Interior, IDispatch, <00020870-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Color, ptr VARIANT
  COM_MTD_DSP  put_Color, VARIANT
  COM_MTD_DSP  get_ColorIndex, ptr VARIANT
  COM_MTD_DSP  put_ColorIndex, VARIANT
  COM_MTD_DSP  get_InvertIfNegative, ptr VARIANT
  COM_MTD_DSP  put_InvertIfNegative, VARIANT
  COM_MTD_DSP  get_Pattern, ptr VARIANT
  COM_MTD_DSP  put_Pattern, VARIANT
  COM_MTD_DSP  get_PatternColor, ptr VARIANT
  COM_MTD_DSP  put_PatternColor, VARIANT
  COM_MTD_DSP  get_PatternColorIndex, ptr VARIANT
  COM_MTD_DSP  put_PatternColorIndex, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG ChartFillFormat, IDispatch, <00024435-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  OneColorGradient, MsoGradientStyle, SDWORD, REAL4
  COM_MTD_DSP  TwoColorGradient, MsoGradientStyle, SDWORD
  COM_MTD_DSP  PresetTextured, MsoPresetTexture
  COM_MTD_DSP  Solid
  COM_MTD_DSP  Patterned, MsoPatternType
  COM_MTD_DSP  UserPicture, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_DSP  UserTextured, BSTR
  COM_MTD_DSP  PresetGradient, MsoGradientStyle, SDWORD, MsoPresetGradientType
  COM_MTD_DSP  get_BackColor, ptr ptr ChartColorFormat
  COM_MTD_DSP  get_ForeColor, ptr ptr ChartColorFormat
  COM_MTD_DSP  get_GradientColorType, ptr MsoGradientColorType
  COM_MTD_DSP  get_GradientDegree, ptr REAL4
  COM_MTD_DSP  get_GradientStyle, ptr MsoGradientStyle
  COM_MTD_DSP  get_GradientVariant, ptr SDWORD
  COM_MTD_DSP  get_Pattern, ptr MsoPatternType
  COM_MTD_DSP  get_PresetGradientType, ptr MsoPresetGradientType
  COM_MTD_DSP  get_PresetTexture, ptr MsoPresetTexture
  COM_MTD_DSP  get_TextureName, ptr BSTR
  COM_MTD_DSP  get_TextureType, ptr MsoTextureType
  COM_MTD_DSP  get_Type, ptr MsoFillType
  COM_MTD_DSP  get_Visible, ptr MsoTriState
  COM_MTD_DSP  put_Visible, MsoTriState
COM_INTERFACE_END

COM_INTERFACE_BEG ChartColorFormat, IDispatch, <00024436-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_SchemeColor, ptr SDWORD
  COM_MTD_DSP  put_SchemeColor, SDWORD
  COM_MTD_DSP  get_RGB, ptr SDWORD
  COM_MTD_DSP  get__Default, ptr SDWORD
  COM_MTD_DSP  get_Type, ptr SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG Axis, IDispatch, <00020848-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_AxisBetweenCategories, ptr BOOL
  COM_MTD_DSP  put_AxisBetweenCategories, BOOL
  COM_MTD_DSP  get_AxisGroup, ptr XlAxisGroup
  COM_MTD_DSP  get_AxisTitle, ptr ptr AxisTitle
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  get_CategoryNames, ptr VARIANT
  COM_MTD_DSP  put_CategoryNames, VARIANT
  COM_MTD_DSP  get_Crosses, ptr XlAxisCrosses
  COM_MTD_DSP  put_Crosses, XlAxisCrosses
  COM_MTD_DSP  get_CrossesAt, ptr REAL8
  COM_MTD_DSP  put_CrossesAt, REAL8
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  get_HasMajorGridlines, ptr BOOL
  COM_MTD_DSP  put_HasMajorGridlines, BOOL
  COM_MTD_DSP  get_HasMinorGridlines, ptr BOOL
  COM_MTD_DSP  put_HasMinorGridlines, BOOL
  COM_MTD_DSP  get_HasTitle, ptr BOOL
  COM_MTD_DSP  put_HasTitle, BOOL
  COM_MTD_DSP  get_MajorGridlines, ptr ptr Gridlines
  COM_MTD_DSP  get_MajorTickMark, ptr XlTickMark
  COM_MTD_DSP  put_MajorTickMark, XlTickMark
  COM_MTD_DSP  get_MajorUnit, ptr REAL8
  COM_MTD_DSP  put_MajorUnit, REAL8
  COM_MTD_DSP  get_MajorUnitIsAuto, ptr BOOL
  COM_MTD_DSP  put_MajorUnitIsAuto, BOOL
  COM_MTD_DSP  get_MaximumScale, ptr REAL8
  COM_MTD_DSP  put_MaximumScale, REAL8
  COM_MTD_DSP  get_MaximumScaleIsAuto, ptr BOOL
  COM_MTD_DSP  put_MaximumScaleIsAuto, BOOL
  COM_MTD_DSP  get_MinimumScale, ptr REAL8
  COM_MTD_DSP  put_MinimumScale, REAL8
  COM_MTD_DSP  get_MinimumScaleIsAuto, ptr BOOL
  COM_MTD_DSP  put_MinimumScaleIsAuto, BOOL
  COM_MTD_DSP  get_MinorGridlines, ptr ptr Gridlines
  COM_MTD_DSP  get_MinorTickMark, ptr XlTickMark
  COM_MTD_DSP  put_MinorTickMark, XlTickMark
  COM_MTD_DSP  get_MinorUnit, ptr REAL8
  COM_MTD_DSP  put_MinorUnit, REAL8
  COM_MTD_DSP  get_MinorUnitIsAuto, ptr BOOL
  COM_MTD_DSP  put_MinorUnitIsAuto, BOOL
  COM_MTD_DSP  get_ReversePlotOrder, ptr BOOL
  COM_MTD_DSP  put_ReversePlotOrder, BOOL
  COM_MTD_DSP  get_ScaleType, ptr XlScaleType
  COM_MTD_DSP  put_ScaleType, XlScaleType
  COM_MTD_DSP  Select, ptr VARIANT
  COM_MTD_DSP  get_TickLabelPosition, ptr XlTickLabelPosition
  COM_MTD_DSP  put_TickLabelPosition, XlTickLabelPosition
  COM_MTD_DSP  get_TickLabels, ptr ptr TickLabels
  COM_MTD_DSP  get_TickLabelSpacing, ptr SDWORD
  COM_MTD_DSP  put_TickLabelSpacing, SDWORD
  COM_MTD_DSP  get_TickMarkSpacing, ptr SDWORD
  COM_MTD_DSP  put_TickMarkSpacing, SDWORD
  COM_MTD_DSP  get_Type, ptr XlAxisType
  COM_MTD_DSP  put_Type, XlAxisType
  COM_MTD_DSP  get_BaseUnit, ptr XlTimeUnit
  COM_MTD_DSP  put_BaseUnit, XlTimeUnit
  COM_MTD_DSP  get_BaseUnitIsAuto, ptr BOOL
  COM_MTD_DSP  put_BaseUnitIsAuto, BOOL
  COM_MTD_DSP  get_MajorUnitScale, ptr XlTimeUnit
  COM_MTD_DSP  put_MajorUnitScale, XlTimeUnit
  COM_MTD_DSP  get_MinorUnitScale, ptr XlTimeUnit
  COM_MTD_DSP  put_MinorUnitScale, XlTimeUnit
  COM_MTD_DSP  get_CategoryType, ptr XlCategoryType
  COM_MTD_DSP  put_CategoryType, XlCategoryType
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  get_DisplayUnit, ptr XlDisplayUnit
  COM_MTD_DSP  put_DisplayUnit, XlDisplayUnit
  COM_MTD_DSP  get_DisplayUnitCustom, ptr REAL8
  COM_MTD_DSP  put_DisplayUnitCustom, REAL8
  COM_MTD_DSP  get_HasDisplayUnitLabel, ptr BOOL
  COM_MTD_DSP  put_HasDisplayUnitLabel, BOOL
  COM_MTD_DSP  get_DisplayUnitLabel, ptr ptr DisplayUnitLabel
COM_INTERFACE_END

COM_INTERFACE_BEG ChartTitle, IDispatch, <00020849-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  Select, ptr VARIANT
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_Fill, ptr ptr ChartFillFormat
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_DSP  get_Font, ptr ptr Font
  COM_MTD_DSP  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_DSP  put_HorizontalAlignment, VARIANT
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Orientation, ptr VARIANT
  COM_MTD_DSP  put_Orientation, VARIANT
  COM_MTD_DSP  get_Shadow, ptr BOOL
  COM_MTD_DSP  put_Shadow, BOOL
  COM_MTD_DSP  get_Text, ptr BSTR
  COM_MTD_DSP  put_Text, BSTR
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  get_VerticalAlignment, ptr VARIANT
  COM_MTD_DSP  put_VerticalAlignment, VARIANT
  COM_MTD_DSP  get_ReadingOrder, ptr SDWORD
  COM_MTD_DSP  put_ReadingOrder, SDWORD
  COM_MTD_DSP  get_AutoScaleFont, ptr VARIANT
  COM_MTD_DSP  put_AutoScaleFont, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG AxisTitle, IDispatch, <0002084A-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  Select, ptr VARIANT
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_Fill, ptr ptr ChartFillFormat
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_DSP  get_Font, ptr ptr Font
  COM_MTD_DSP  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_DSP  put_HorizontalAlignment, VARIANT
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Orientation, ptr VARIANT
  COM_MTD_DSP  put_Orientation, VARIANT
  COM_MTD_DSP  get_Shadow, ptr BOOL
  COM_MTD_DSP  put_Shadow, BOOL
  COM_MTD_DSP  get_Text, ptr BSTR
  COM_MTD_DSP  put_Text, BSTR
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  get_VerticalAlignment, ptr VARIANT
  COM_MTD_DSP  put_VerticalAlignment, VARIANT
  COM_MTD_DSP  get_ReadingOrder, ptr SDWORD
  COM_MTD_DSP  put_ReadingOrder, SDWORD
  COM_MTD_DSP  get_AutoScaleFont, ptr VARIANT
  COM_MTD_DSP  put_AutoScaleFont, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG ChartGroup, IDispatch, <00020859-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_AxisGroup, ptr XlAxisGroup
  COM_MTD_DSP  put_AxisGroup, XlAxisGroup
  COM_MTD_DSP  get_DoughnutHoleSize, ptr SDWORD
  COM_MTD_DSP  put_DoughnutHoleSize, SDWORD
  COM_MTD_DSP  get_DownBars, ptr ptr DownBars
  COM_MTD_DSP  get_DropLines, ptr ptr DropLines
  COM_MTD_DSP  get_FirstSliceAngle, ptr SDWORD
  COM_MTD_DSP  put_FirstSliceAngle, SDWORD
  COM_MTD_DSP  get_GapWidth, ptr SDWORD
  COM_MTD_DSP  put_GapWidth, SDWORD
  COM_MTD_DSP  get_HasDropLines, ptr BOOL
  COM_MTD_DSP  put_HasDropLines, BOOL
  COM_MTD_DSP  get_HasHiLoLines, ptr BOOL
  COM_MTD_DSP  put_HasHiLoLines, BOOL
  COM_MTD_DSP  get_HasRadarAxisLabels, ptr BOOL
  COM_MTD_DSP  put_HasRadarAxisLabels, BOOL
  COM_MTD_DSP  get_HasSeriesLines, ptr BOOL
  COM_MTD_DSP  put_HasSeriesLines, BOOL
  COM_MTD_DSP  get_HasUpDownBars, ptr BOOL
  COM_MTD_DSP  put_HasUpDownBars, BOOL
  COM_MTD_DSP  get_HiLoLines, ptr ptr HiLoLines
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  get_Overlap, ptr SDWORD
  COM_MTD_DSP  put_Overlap, SDWORD
  COM_MTD_DSP  get_RadarAxisLabels, ptr ptr TickLabels
  COM_MTD_DSP  SeriesCollection, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  get_SeriesLines, ptr ptr SeriesLines
  COM_MTD_DSP  get_SubType, ptr SDWORD
  COM_MTD_DSP  put_SubType, SDWORD
  COM_MTD_DSP  get_Type, ptr SDWORD
  COM_MTD_DSP  put_Type, SDWORD
  COM_MTD_DSP  get_UpBars, ptr ptr UpBars
  COM_MTD_DSP  get_VaryByCategories, ptr BOOL
  COM_MTD_DSP  put_VaryByCategories, BOOL
  COM_MTD_DSP  get_SizeRepresents, ptr XlSizeRepresents
  COM_MTD_DSP  put_SizeRepresents, XlSizeRepresents
  COM_MTD_DSP  get_BubbleScale, ptr SDWORD
  COM_MTD_DSP  put_BubbleScale, SDWORD
  COM_MTD_DSP  get_ShowNegativeBubbles, ptr BOOL
  COM_MTD_DSP  put_ShowNegativeBubbles, BOOL
  COM_MTD_DSP  get_SplitType, ptr XlChartSplitType
  COM_MTD_DSP  put_SplitType, XlChartSplitType
  COM_MTD_DSP  get_SplitValue, ptr VARIANT
  COM_MTD_DSP  put_SplitValue, VARIANT
  COM_MTD_DSP  get_SecondPlotSize, ptr SDWORD
  COM_MTD_DSP  put_SecondPlotSize, SDWORD
  COM_MTD_DSP  get_Has3DShading, ptr BOOL
  COM_MTD_DSP  put_Has3DShading, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG ChartGroups, IDispatch, <0002085A-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Item, VARIANT, ptr ptr ChartGroup
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG Axes, IDispatch, <0002085B-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Item, XlAxisType, XlAxisGroup, ptr ptr Axis
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG Points_, IDispatch, <00020869-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Item, SDWORD, ptr ptr Point
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG Point_, IDispatch, <0002086A-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  ApplyDataLabels, XlDataLabelsType, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  ClearFormats, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  get_DataLabel, ptr ptr DataLabel
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  get_Explosion, ptr SDWORD
  COM_MTD_DSP  put_Explosion, SDWORD
  COM_MTD_DSP  get_HasDataLabel, ptr BOOL
  COM_MTD_DSP  put_HasDataLabel, BOOL
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_InvertIfNegative, ptr BOOL
  COM_MTD_DSP  put_InvertIfNegative, BOOL
  COM_MTD_DSP  get_MarkerBackgroundColor, ptr SDWORD
  COM_MTD_DSP  put_MarkerBackgroundColor, SDWORD
  COM_MTD_DSP  get_MarkerBackgroundColorIndex, ptr XlColorIndex
  COM_MTD_DSP  put_MarkerBackgroundColorIndex, XlColorIndex
  COM_MTD_DSP  get_MarkerForegroundColor, ptr SDWORD
  COM_MTD_DSP  put_MarkerForegroundColor, SDWORD
  COM_MTD_DSP  get_MarkerForegroundColorIndex, ptr XlColorIndex
  COM_MTD_DSP  put_MarkerForegroundColorIndex, XlColorIndex
  COM_MTD_DSP  get_MarkerSize, ptr SDWORD
  COM_MTD_DSP  put_MarkerSize, SDWORD
  COM_MTD_DSP  get_MarkerStyle, ptr XlMarkerStyle
  COM_MTD_DSP  put_MarkerStyle, XlMarkerStyle
  COM_MTD_DSP  Paste, ptr VARIANT
  COM_MTD_DSP  get_PictureType, ptr XlChartPictureType
  COM_MTD_DSP  put_PictureType, XlChartPictureType
  COM_MTD_DSP  get_PictureUnit, ptr SDWORD
  COM_MTD_DSP  put_PictureUnit, SDWORD
  COM_MTD_DSP  Select, ptr VARIANT
  COM_MTD_DSP  get_ApplyPictToSides, ptr BOOL
  COM_MTD_DSP  put_ApplyPictToSides, BOOL
  COM_MTD_DSP  get_ApplyPictToFront, ptr BOOL
  COM_MTD_DSP  put_ApplyPictToFront, BOOL
  COM_MTD_DSP  get_ApplyPictToEnd, ptr BOOL
  COM_MTD_DSP  put_ApplyPictToEnd, BOOL
  COM_MTD_DSP  get_Shadow, ptr BOOL
  COM_MTD_DSP  put_Shadow, BOOL
  COM_MTD_DSP  get_SecondaryPlot, ptr BOOL
  COM_MTD_DSP  put_SecondaryPlot, BOOL
  COM_MTD_DSP  get_Fill, ptr ptr ChartFillFormat
COM_INTERFACE_END

COM_INTERFACE_BEG Series, IDispatch, <0002086B-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  ApplyDataLabels, XlDataLabelsType, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_AxisGroup, ptr XlAxisGroup
  COM_MTD_DSP  put_AxisGroup, XlAxisGroup
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  ClearFormats, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  DataLabels, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  ErrorBar, XlErrorBarDirection, XlErrorBarInclude, XlErrorBarType, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_ErrorBars, ptr ptr ErrorBars
  COM_MTD_DSP  get_Explosion, ptr SDWORD
  COM_MTD_DSP  put_Explosion, SDWORD
  COM_MTD_DSP  get_Formula, ptr BSTR
  COM_MTD_DSP  put_Formula, BSTR
  COM_MTD_DSP  get_FormulaLocal, ptr BSTR
  COM_MTD_DSP  put_FormulaLocal, BSTR
  COM_MTD_DSP  get_FormulaR1C1, ptr BSTR
  COM_MTD_DSP  put_FormulaR1C1, BSTR
  COM_MTD_DSP  get_FormulaR1C1Local, ptr BSTR
  COM_MTD_DSP  put_FormulaR1C1Local, BSTR
  COM_MTD_DSP  get_HasDataLabels, ptr BOOL
  COM_MTD_DSP  put_HasDataLabels, BOOL
  COM_MTD_DSP  get_HasErrorBars, ptr BOOL
  COM_MTD_DSP  put_HasErrorBars, BOOL
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_Fill, ptr ptr ChartFillFormat
  COM_MTD_DSP  get_InvertIfNegative, ptr BOOL
  COM_MTD_DSP  put_InvertIfNegative, BOOL
  COM_MTD_DSP  get_MarkerBackgroundColor, ptr SDWORD
  COM_MTD_DSP  put_MarkerBackgroundColor, SDWORD
  COM_MTD_DSP  get_MarkerBackgroundColorIndex, ptr XlColorIndex
  COM_MTD_DSP  put_MarkerBackgroundColorIndex, XlColorIndex
  COM_MTD_DSP  get_MarkerForegroundColor, ptr SDWORD
  COM_MTD_DSP  put_MarkerForegroundColor, SDWORD
  COM_MTD_DSP  get_MarkerForegroundColorIndex, ptr XlColorIndex
  COM_MTD_DSP  put_MarkerForegroundColorIndex, XlColorIndex
  COM_MTD_DSP  get_MarkerSize, ptr SDWORD
  COM_MTD_DSP  put_MarkerSize, SDWORD
  COM_MTD_DSP  get_MarkerStyle, ptr XlMarkerStyle
  COM_MTD_DSP  put_MarkerStyle, XlMarkerStyle
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  Paste, ptr VARIANT
  COM_MTD_DSP  get_PictureType, ptr XlChartPictureType
  COM_MTD_DSP  put_PictureType, XlChartPictureType
  COM_MTD_DSP  get_PictureUnit, ptr SDWORD
  COM_MTD_DSP  put_PictureUnit, SDWORD
  COM_MTD_DSP  get_PlotOrder, ptr SDWORD
  COM_MTD_DSP  put_PlotOrder, SDWORD
  COM_MTD_DSP  Points, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  Select, ptr VARIANT
  COM_MTD_DSP  get_Smooth, ptr BOOL
  COM_MTD_DSP  put_Smooth, BOOL
  COM_MTD_DSP  Trendlines, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  get_Type, ptr SDWORD
  COM_MTD_DSP  put_Type, SDWORD
  COM_MTD_DSP  get_ChartType, ptr XlChartType
  COM_MTD_DSP  put_ChartType, XlChartType
  COM_MTD_DSP  ApplyCustomType, XlChartType
  COM_MTD_DSP  get_Values, ptr VARIANT
  COM_MTD_DSP  put_Values, VARIANT
  COM_MTD_DSP  get_XValues, ptr VARIANT
  COM_MTD_DSP  put_XValues, VARIANT
  COM_MTD_DSP  get_BubbleSizes, ptr VARIANT
  COM_MTD_DSP  put_BubbleSizes, VARIANT
  COM_MTD_DSP  get_BarShape, ptr XlBarShape
  COM_MTD_DSP  put_BarShape, XlBarShape
  COM_MTD_DSP  get_ApplyPictToSides, ptr BOOL
  COM_MTD_DSP  put_ApplyPictToSides, BOOL
  COM_MTD_DSP  get_ApplyPictToFront, ptr BOOL
  COM_MTD_DSP  put_ApplyPictToFront, BOOL
  COM_MTD_DSP  get_ApplyPictToEnd, ptr BOOL
  COM_MTD_DSP  put_ApplyPictToEnd, BOOL
  COM_MTD_DSP  get_Has3DEffect, ptr BOOL
  COM_MTD_DSP  put_Has3DEffect, BOOL
  COM_MTD_DSP  get_Shadow, ptr BOOL
  COM_MTD_DSP  put_Shadow, BOOL
  COM_MTD_DSP  get_HasLeaderLines, ptr BOOL
  COM_MTD_DSP  put_HasLeaderLines, BOOL
  COM_MTD_DSP  get_LeaderLines, ptr ptr LeaderLines
COM_INTERFACE_END

COM_INTERFACE_BEG SeriesCollection, IDispatch, <0002086C-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Add_, VARIANT, XlRowCol, VARIANT, VARIANT, VARIANT, ptr ptr Series
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Extend, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  Item, VARIANT, ptr ptr Series
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
  COM_MTD_DSP  Paste, XlRowCol, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  NewSeries, ptr ptr Series
COM_INTERFACE_END

COM_INTERFACE_BEG DataLabel, IDispatch, <000208B2-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  Select, ptr VARIANT
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_Fill, ptr ptr ChartFillFormat
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_DSP  get_Font, ptr ptr Font
  COM_MTD_DSP  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_DSP  put_HorizontalAlignment, VARIANT
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Orientation, ptr VARIANT
  COM_MTD_DSP  put_Orientation, VARIANT
  COM_MTD_DSP  get_Shadow, ptr BOOL
  COM_MTD_DSP  put_Shadow, BOOL
  COM_MTD_DSP  get_Text, ptr BSTR
  COM_MTD_DSP  put_Text, BSTR
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  get_VerticalAlignment, ptr VARIANT
  COM_MTD_DSP  put_VerticalAlignment, VARIANT
  COM_MTD_DSP  get_ReadingOrder, ptr SDWORD
  COM_MTD_DSP  put_ReadingOrder, SDWORD
  COM_MTD_DSP  get_AutoScaleFont, ptr VARIANT
  COM_MTD_DSP  put_AutoScaleFont, VARIANT
  COM_MTD_DSP  get_AutoText, ptr BOOL
  COM_MTD_DSP  put_AutoText, BOOL
  COM_MTD_DSP  get_NumberFormat, ptr BSTR
  COM_MTD_DSP  put_NumberFormat, BSTR
  COM_MTD_DSP  get_NumberFormatLinked, ptr BOOL
  COM_MTD_DSP  put_NumberFormatLinked, BOOL
  COM_MTD_DSP  get_NumberFormatLocal, ptr VARIANT
  COM_MTD_DSP  put_NumberFormatLocal, VARIANT
  COM_MTD_DSP  get_ShowLegendKey, ptr BOOL
  COM_MTD_DSP  put_ShowLegendKey, BOOL
  COM_MTD_DSP  get_Type, ptr VARIANT
  COM_MTD_DSP  put_Type, VARIANT
  COM_MTD_DSP  get_Position, ptr XlDataLabelPosition
  COM_MTD_DSP  put_Position, XlDataLabelPosition
  COM_MTD_DSP  get_ShowSeriesName, ptr BOOL
  COM_MTD_DSP  put_ShowSeriesName, BOOL
  COM_MTD_DSP  get_ShowCategoryName, ptr BOOL
  COM_MTD_DSP  put_ShowCategoryName, BOOL
  COM_MTD_DSP  get_ShowValue, ptr BOOL
  COM_MTD_DSP  put_ShowValue, BOOL
  COM_MTD_DSP  get_ShowPercentage, ptr BOOL
  COM_MTD_DSP  put_ShowPercentage, BOOL
  COM_MTD_DSP  get_ShowBubbleSize, ptr BOOL
  COM_MTD_DSP  put_ShowBubbleSize, BOOL
  COM_MTD_DSP  get_Separator, ptr VARIANT
  COM_MTD_DSP  put_Separator, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG DataLabels, IDispatch, <000208B3-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  Select, ptr VARIANT
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_Fill, ptr ptr ChartFillFormat
  COM_MTD_DSP  _Dummy9
  COM_MTD_DSP  _Dummy10
  COM_MTD_DSP  get_Font, ptr ptr Font
  COM_MTD_DSP  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_DSP  put_HorizontalAlignment, VARIANT
  COM_MTD_DSP  _Dummy13
  COM_MTD_DSP  get_Orientation, ptr VARIANT
  COM_MTD_DSP  put_Orientation, VARIANT
  COM_MTD_DSP  get_Shadow, ptr BOOL
  COM_MTD_DSP  put_Shadow, BOOL
  COM_MTD_DSP  _Dummy16
  COM_MTD_DSP  _Dummy17
  COM_MTD_DSP  get_VerticalAlignment, ptr VARIANT
  COM_MTD_DSP  put_VerticalAlignment, VARIANT
  COM_MTD_DSP  get_ReadingOrder, ptr SDWORD
  COM_MTD_DSP  put_ReadingOrder, SDWORD
  COM_MTD_DSP  get_AutoScaleFont, ptr VARIANT
  COM_MTD_DSP  put_AutoScaleFont, VARIANT
  COM_MTD_DSP  get_AutoText, ptr BOOL
  COM_MTD_DSP  put_AutoText, BOOL
  COM_MTD_DSP  get_NumberFormat, ptr BSTR
  COM_MTD_DSP  put_NumberFormat, BSTR
  COM_MTD_DSP  get_NumberFormatLinked, ptr BOOL
  COM_MTD_DSP  put_NumberFormatLinked, BOOL
  COM_MTD_DSP  get_NumberFormatLocal, ptr VARIANT
  COM_MTD_DSP  put_NumberFormatLocal, VARIANT
  COM_MTD_DSP  get_ShowLegendKey, ptr BOOL
  COM_MTD_DSP  put_ShowLegendKey, BOOL
  COM_MTD_DSP  get_Type, ptr VARIANT
  COM_MTD_DSP  put_Type, VARIANT
  COM_MTD_DSP  get_Position, ptr XlDataLabelPosition
  COM_MTD_DSP  put_Position, XlDataLabelPosition
  COM_MTD_DSP  get_ShowSeriesName, ptr BOOL
  COM_MTD_DSP  put_ShowSeriesName, BOOL
  COM_MTD_DSP  get_ShowCategoryName, ptr BOOL
  COM_MTD_DSP  put_ShowCategoryName, BOOL
  COM_MTD_DSP  get_ShowValue, ptr BOOL
  COM_MTD_DSP  put_ShowValue, BOOL
  COM_MTD_DSP  get_ShowPercentage, ptr BOOL
  COM_MTD_DSP  put_ShowPercentage, BOOL
  COM_MTD_DSP  get_ShowBubbleSize, ptr BOOL
  COM_MTD_DSP  put_ShowBubbleSize, BOOL
  COM_MTD_DSP  get_Separator, ptr VARIANT
  COM_MTD_DSP  put_Separator, VARIANT
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Item, VARIANT, ptr ptr DataLabel
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG LegendEntry, IDispatch, <000208BA-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  get_Font, ptr ptr Font
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  get_LegendKey, ptr ptr LegendKey
  COM_MTD_DSP  Select, ptr VARIANT
  COM_MTD_DSP  get_AutoScaleFont, ptr VARIANT
  COM_MTD_DSP  put_AutoScaleFont, VARIANT
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  get_Height, ptr REAL8
COM_INTERFACE_END

COM_INTERFACE_BEG LegendEntries, IDispatch, <000208BB-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Item, VARIANT, ptr ptr LegendEntry
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG LegendKey, IDispatch, <000208BC-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  ClearFormats, ptr VARIANT
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_Fill, ptr ptr ChartFillFormat
  COM_MTD_DSP  get_InvertIfNegative, ptr BOOL
  COM_MTD_DSP  put_InvertIfNegative, BOOL
  COM_MTD_DSP  get_MarkerBackgroundColor, ptr SDWORD
  COM_MTD_DSP  put_MarkerBackgroundColor, SDWORD
  COM_MTD_DSP  get_MarkerBackgroundColorIndex, ptr XlColorIndex
  COM_MTD_DSP  put_MarkerBackgroundColorIndex, XlColorIndex
  COM_MTD_DSP  get_MarkerForegroundColor, ptr SDWORD
  COM_MTD_DSP  put_MarkerForegroundColor, SDWORD
  COM_MTD_DSP  get_MarkerForegroundColorIndex, ptr XlColorIndex
  COM_MTD_DSP  put_MarkerForegroundColorIndex, XlColorIndex
  COM_MTD_DSP  get_MarkerSize, ptr SDWORD
  COM_MTD_DSP  put_MarkerSize, SDWORD
  COM_MTD_DSP  get_MarkerStyle, ptr XlMarkerStyle
  COM_MTD_DSP  put_MarkerStyle, XlMarkerStyle
  COM_MTD_DSP  get_PictureType, ptr SDWORD
  COM_MTD_DSP  put_PictureType, SDWORD
  COM_MTD_DSP  get_PictureUnit, ptr SDWORD
  COM_MTD_DSP  put_PictureUnit, SDWORD
  COM_MTD_DSP  Select, ptr VARIANT
  COM_MTD_DSP  get_Smooth, ptr BOOL
  COM_MTD_DSP  put_Smooth, BOOL
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  get_Shadow, ptr BOOL
  COM_MTD_DSP  put_Shadow, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG Trendlines, IDispatch, <000208BD-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Add_, XlTrendlineType, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr ptr Trendline
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Item, VARIANT, ptr ptr Trendline
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG Trendline, IDispatch, <000208BE-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Backward, ptr SDWORD
  COM_MTD_DSP  put_Backward, SDWORD
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  ClearFormats, ptr VARIANT
  COM_MTD_DSP  get_DataLabel, ptr ptr DataLabel
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  get_DisplayEquation, ptr BOOL
  COM_MTD_DSP  put_DisplayEquation, BOOL
  COM_MTD_DSP  get_DisplayRSquared, ptr BOOL
  COM_MTD_DSP  put_DisplayRSquared, BOOL
  COM_MTD_DSP  get_Forward, ptr SDWORD
  COM_MTD_DSP  put_Forward, SDWORD
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  get_Intercept, ptr REAL8
  COM_MTD_DSP  put_Intercept, REAL8
  COM_MTD_DSP  get_InterceptIsAuto, ptr BOOL
  COM_MTD_DSP  put_InterceptIsAuto, BOOL
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  get_NameIsAuto, ptr BOOL
  COM_MTD_DSP  put_NameIsAuto, BOOL
  COM_MTD_DSP  get_Order, ptr SDWORD
  COM_MTD_DSP  put_Order, SDWORD
  COM_MTD_DSP  get_Period, ptr SDWORD
  COM_MTD_DSP  put_Period, SDWORD
  COM_MTD_DSP  Select, ptr VARIANT
  COM_MTD_DSP  get_Type, ptr XlTrendlineType
  COM_MTD_DSP  put_Type, XlTrendlineType
COM_INTERFACE_END

COM_INTERFACE_BEG Corners, IDispatch, <000208C0-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  Select, ptr VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG SeriesLines, IDispatch, <000208C1-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  Select, ptr VARIANT
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  Delete, ptr VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG HiLoLines, IDispatch, <000208C2-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  Select, ptr VARIANT
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  Delete, ptr VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG Gridlines, IDispatch, <000208C3-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  Select, ptr VARIANT
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  Delete, ptr VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG DropLines, IDispatch, <000208C4-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  Select, ptr VARIANT
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  Delete, ptr VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG LeaderLines, IDispatch, <00024437-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  Delete
  COM_MTD_DSP  Select
COM_INTERFACE_END

COM_INTERFACE_BEG UpBars, IDispatch, <000208C5-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  Select, ptr VARIANT
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_Fill, ptr ptr ChartFillFormat
COM_INTERFACE_END

COM_INTERFACE_BEG DownBars, IDispatch, <000208C6-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  Select, ptr VARIANT
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_Fill, ptr ptr ChartFillFormat
COM_INTERFACE_END

COM_INTERFACE_BEG Floor, IDispatch, <000208C7-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  Select, ptr VARIANT
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  ClearFormats, ptr VARIANT
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_Fill, ptr ptr ChartFillFormat
  COM_MTD_DSP  get_PictureType, ptr VARIANT
  COM_MTD_DSP  put_PictureType, VARIANT
  COM_MTD_DSP  Paste
COM_INTERFACE_END

COM_INTERFACE_BEG Walls, IDispatch, <000208C8-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  Select, ptr VARIANT
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  ClearFormats, ptr VARIANT
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_Fill, ptr ptr ChartFillFormat
  COM_MTD_DSP  get_PictureType, ptr VARIANT
  COM_MTD_DSP  put_PictureType, VARIANT
  COM_MTD_DSP  Paste
  COM_MTD_DSP  get_PictureUnit, ptr VARIANT
  COM_MTD_DSP  put_PictureUnit, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG TickLabels, IDispatch, <000208C9-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  get_Font, ptr ptr Font
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  get_NumberFormat, ptr BSTR
  COM_MTD_DSP  put_NumberFormat, BSTR
  COM_MTD_DSP  get_NumberFormatLinked, ptr BOOL
  COM_MTD_DSP  put_NumberFormatLinked, BOOL
  COM_MTD_DSP  get_NumberFormatLocal, ptr VARIANT
  COM_MTD_DSP  put_NumberFormatLocal, VARIANT
  COM_MTD_DSP  get_Orientation, ptr XlTickLabelOrientation
  COM_MTD_DSP  put_Orientation, XlTickLabelOrientation
  COM_MTD_DSP  Select, ptr VARIANT
  COM_MTD_DSP  get_ReadingOrder, ptr SDWORD
  COM_MTD_DSP  put_ReadingOrder, SDWORD
  COM_MTD_DSP  get_AutoScaleFont, ptr VARIANT
  COM_MTD_DSP  put_AutoScaleFont, VARIANT
  COM_MTD_DSP  get_Depth, ptr SDWORD
  COM_MTD_DSP  get_Offset, ptr SDWORD
  COM_MTD_DSP  put_Offset, SDWORD
  COM_MTD_DSP  get_Alignment, ptr SDWORD
  COM_MTD_DSP  put_Alignment, SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG PlotArea, IDispatch, <000208CB-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  Select, ptr VARIANT
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  ClearFormats, ptr VARIANT
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_Fill, ptr ptr ChartFillFormat
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_InsideLeft, ptr REAL8
  COM_MTD_DSP  get_InsideTop, ptr REAL8
  COM_MTD_DSP  get_InsideWidth, ptr REAL8
  COM_MTD_DSP  get_InsideHeight, ptr REAL8
COM_INTERFACE_END

COM_INTERFACE_BEG ChartArea, IDispatch, <000208CC-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  Select, ptr VARIANT
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  Clear, ptr VARIANT
  COM_MTD_DSP  ClearContents, ptr VARIANT
  COM_MTD_DSP  Copy, ptr VARIANT
  COM_MTD_DSP  get_Font, ptr ptr Font
  COM_MTD_DSP  get_Shadow, ptr BOOL
  COM_MTD_DSP  put_Shadow, BOOL
  COM_MTD_DSP  ClearFormats, ptr VARIANT
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_Fill, ptr ptr ChartFillFormat
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_AutoScaleFont, ptr VARIANT
  COM_MTD_DSP  put_AutoScaleFont, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG Legend, IDispatch, <000208CD-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  Select, ptr VARIANT
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  get_Font, ptr ptr Font
  COM_MTD_DSP  LegendEntries, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  get_Position, ptr XlLegendPosition
  COM_MTD_DSP  put_Position, XlLegendPosition
  COM_MTD_DSP  get_Shadow, ptr BOOL
  COM_MTD_DSP  put_Shadow, BOOL
  COM_MTD_DSP  Clear, ptr VARIANT
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_Fill, ptr ptr ChartFillFormat
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_AutoScaleFont, ptr VARIANT
  COM_MTD_DSP  put_AutoScaleFont, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG ErrorBars, IDispatch, <000208CE-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  Select, ptr VARIANT
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  ClearFormats, ptr VARIANT
  COM_MTD_DSP  get_EndStyle, ptr XlEndStyleCap
  COM_MTD_DSP  put_EndStyle, XlEndStyleCap
COM_INTERFACE_END

COM_INTERFACE_BEG DataTable, IDispatch, <00020843-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_ShowLegendKey, ptr BOOL
  COM_MTD_DSP  put_ShowLegendKey, BOOL
  COM_MTD_DSP  get_HasBorderHorizontal, ptr BOOL
  COM_MTD_DSP  put_HasBorderHorizontal, BOOL
  COM_MTD_DSP  get_HasBorderVertical, ptr BOOL
  COM_MTD_DSP  put_HasBorderVertical, BOOL
  COM_MTD_DSP  get_HasBorderOutline, ptr BOOL
  COM_MTD_DSP  put_HasBorderOutline, BOOL
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  get_Font, ptr ptr Font
  COM_MTD_DSP  Select
  COM_MTD_DSP  Delete
  COM_MTD_DSP  get_AutoScaleFont, ptr VARIANT
  COM_MTD_DSP  put_AutoScaleFont, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG Phonetic, IDispatch, <00024438-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_CharacterType, ptr SDWORD
  COM_MTD_DSP  put_CharacterType, SDWORD
  COM_MTD_DSP  get_Alignment, ptr SDWORD
  COM_MTD_DSP  put_Alignment, SDWORD
  COM_MTD_DSP  get_Font, ptr ptr Font
  COM_MTD_DSP  get_Text, ptr BSTR
  COM_MTD_DSP  put_Text, BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG Shape, IDispatch, <00024439-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Apply
  COM_MTD_DSP  Delete
  COM_MTD_DSP  Duplicate, ptr ptr Shape
  COM_MTD_DSP  Flip, MsoFlipCmd
  COM_MTD_DSP  IncrementLeft, REAL4
  COM_MTD_DSP  IncrementRotation, REAL4
  COM_MTD_DSP  IncrementTop, REAL4
  COM_MTD_DSP  PickUp
  COM_MTD_DSP  RerouteConnections
  COM_MTD_DSP  ScaleHeight, REAL4, MsoTriState, VARIANT
  COM_MTD_DSP  ScaleWidth, REAL4, MsoTriState, VARIANT
  COM_MTD_DSP  Select, VARIANT
  COM_MTD_DSP  SetShapesDefaultProperties
  COM_MTD_DSP  Ungroup, ptr ptr ShapeRange
  COM_MTD_DSP  ZOrder, MsoZOrderCmd
  COM_MTD_DSP  get_Adjustments, ptr ptr Adjustments
  COM_MTD_DSP  get_TextFrame, ptr ptr TextFrame
  COM_MTD_DSP  get_AutoShapeType, ptr MsoAutoShapeType
  COM_MTD_DSP  put_AutoShapeType, MsoAutoShapeType
  COM_MTD_DSP  get_Callout, ptr ptr CalloutFormat
  COM_MTD_DSP  get_ConnectionSiteCount, ptr SDWORD
  COM_MTD_DSP  get_Connector, ptr MsoTriState
  COM_MTD_DSP  get_ConnectorFormat, ptr ptr ConnectorFormat
  COM_MTD_DSP  get_Fill, ptr ptr FillFormat
  COM_MTD_DSP  get_GroupItems, ptr ptr GroupShapes
  COM_MTD_DSP  get_Height, ptr REAL4
  COM_MTD_DSP  put_Height, REAL4
  COM_MTD_DSP  get_HorizontalFlip, ptr MsoTriState
  COM_MTD_DSP  get_Left, ptr REAL4
  COM_MTD_DSP  put_Left, REAL4
  COM_MTD_DSP  get_Line, ptr ptr LineFormat
  COM_MTD_DSP  get_LockAspectRatio, ptr MsoTriState
  COM_MTD_DSP  put_LockAspectRatio, MsoTriState
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  get_Nodes, ptr ptr ShapeNodes
  COM_MTD_DSP  get_Rotation, ptr REAL4
  COM_MTD_DSP  put_Rotation, REAL4
  COM_MTD_DSP  get_PictureFormat, ptr ptr PictureFormat
  COM_MTD_DSP  get_Shadow, ptr ptr ShadowFormat
  COM_MTD_DSP  get_TextEffect, ptr ptr TextEffectFormat
  COM_MTD_DSP  get_ThreeD, ptr ptr ThreeDFormat
  COM_MTD_DSP  get_Top, ptr REAL4
  COM_MTD_DSP  put_Top, REAL4
  COM_MTD_DSP  get_Type, ptr MsoShapeType
  COM_MTD_DSP  get_VerticalFlip, ptr MsoTriState
  COM_MTD_DSP  get_Vertices, ptr VARIANT
  COM_MTD_DSP  get_Visible, ptr MsoTriState
  COM_MTD_DSP  put_Visible, MsoTriState
  COM_MTD_DSP  get_Width, ptr REAL4
  COM_MTD_DSP  put_Width, REAL4
  COM_MTD_DSP  get_ZOrderPosition, ptr SDWORD
  COM_MTD_DSP  get_Hyperlink, ptr ptr Hyperlink
  COM_MTD_DSP  get_BlackWhiteMode, ptr MsoBlackWhiteMode
  COM_MTD_DSP  put_BlackWhiteMode, MsoBlackWhiteMode
  COM_MTD_DSP  get_DrawingObject, ptr LPDISPATCH
  COM_MTD_DSP  get_OnAction, ptr BSTR
  COM_MTD_DSP  put_OnAction, BSTR
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  get_TopLeftCell, ptr ptr Range
  COM_MTD_DSP  get_BottomRightCell, ptr ptr Range
  COM_MTD_DSP  get_Placement, ptr XlPlacement
  COM_MTD_DSP  put_Placement, XlPlacement
  COM_MTD_DSP  Copy
  COM_MTD_DSP  Cut
  COM_MTD_DSP  CopyPicture, VARIANT, VARIANT
  COM_MTD_DSP  get_ControlFormat, ptr ptr ControlFormat
  COM_MTD_DSP  get_LinkFormat, ptr ptr LinkFormat
  COM_MTD_DSP  get_OLEFormat, ptr ptr OLEFormat
  COM_MTD_DSP  get_FormControlType, ptr XlFormControl
  COM_MTD_DSP  get_AlternativeText, ptr BSTR
  COM_MTD_DSP  put_AlternativeText, BSTR
  COM_MTD_DSP  get_Script, ptr ptr Script
  COM_MTD_DSP  get_DiagramNode, ptr ptr DiagramNode
  COM_MTD_DSP  get_HasDiagramNode, ptr MsoTriState
  COM_MTD_DSP  get_Diagram, ptr ptr Diagram
  COM_MTD_DSP  get_HasDiagram, ptr MsoTriState
  COM_MTD_DSP  get_Child, ptr MsoTriState
  COM_MTD_DSP  get_ParentGroup, ptr ptr Shape
  COM_MTD_DSP  get_CanvasItems, ptr ptr CanvasShapes
  COM_MTD_DSP  get_ID, ptr SDWORD
  COM_MTD_DSP  CanvasCropLeft, REAL4
  COM_MTD_DSP  CanvasCropTop, REAL4
  COM_MTD_DSP  CanvasCropRight, REAL4
  COM_MTD_DSP  CanvasCropBottom, REAL4
COM_INTERFACE_END

COM_INTERFACE_BEG Shapes, IDispatch, <0002443A-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Item, VARIANT, ptr ptr Shape
  COM_MTD_DSP  _Default, VARIANT, ptr ptr Shape
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_DSP  AddCallout, MsoCalloutType, REAL4, REAL4, REAL4, REAL4, ptr ptr Shape
  COM_MTD_DSP  AddConnector, MsoConnectorType, REAL4, REAL4, REAL4, REAL4, ptr ptr Shape
  COM_MTD_DSP  AddCurve, VARIANT, ptr ptr Shape
  COM_MTD_DSP  AddLabel, MsoTextOrientation, REAL4, REAL4, REAL4, REAL4, ptr ptr Shape
  COM_MTD_DSP  AddLine, REAL4, REAL4, REAL4, REAL4, ptr ptr Shape
  COM_MTD_DSP  AddPicture, BSTR, MsoTriState, MsoTriState, REAL4, REAL4, REAL4, REAL4, ptr ptr Shape
  COM_MTD_DSP  AddPolyline, VARIANT, ptr ptr Shape
  COM_MTD_DSP  AddShape, MsoAutoShapeType, REAL4, REAL4, REAL4, REAL4, ptr ptr Shape
  COM_MTD_DSP  AddTextEffect, MsoPresetTextEffect, BSTR, BSTR, REAL4, MsoTriState, MsoTriState, REAL4, REAL4, ptr ptr Shape
  COM_MTD_DSP  AddTextbox, MsoTextOrientation, REAL4, REAL4, REAL4, REAL4, ptr ptr Shape
  COM_MTD_DSP  BuildFreeform, MsoEditingType, REAL4, REAL4, ptr ptr FreeformBuilder
  COM_MTD_DSP  get_Range, VARIANT, ptr ptr ShapeRange
  COM_MTD_DSP  SelectAll
  COM_MTD_DSP  AddFormControl, XlFormControl, SDWORD, SDWORD, SDWORD, SDWORD, ptr ptr Shape
  COM_MTD_DSP  AddOLEObject, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr ptr Shape
  COM_MTD_DSP  AddDiagram, MsoDiagramType, REAL4, REAL4, REAL4, REAL4, ptr ptr Shape
  COM_MTD_DSP  AddCanvas, REAL4, REAL4, REAL4, REAL4, ptr ptr Shape
COM_INTERFACE_END

COM_INTERFACE_BEG ShapeRange, IDispatch, <0002443B-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Item, VARIANT, ptr ptr Shape
  COM_MTD_DSP  _Default, VARIANT, ptr ptr Shape
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_DSP  Align_, MsoAlignCmd, MsoTriState
  COM_MTD_DSP  Apply
  COM_MTD_DSP  Delete
  COM_MTD_DSP  Distribute, MsoDistributeCmd, MsoTriState
  COM_MTD_DSP  Duplicate, ptr ptr ShapeRange
  COM_MTD_DSP  Flip, MsoFlipCmd
  COM_MTD_DSP  IncrementLeft, REAL4
  COM_MTD_DSP  IncrementRotation, REAL4
  COM_MTD_DSP  IncrementTop, REAL4
  COM_MTD_DSP  Group_, ptr ptr Shape
  COM_MTD_DSP  PickUp
  COM_MTD_DSP  RerouteConnections
  COM_MTD_DSP  Regroup, ptr ptr Shape
  COM_MTD_DSP  ScaleHeight, REAL4, MsoTriState, VARIANT
  COM_MTD_DSP  ScaleWidth, REAL4, MsoTriState, VARIANT
  COM_MTD_DSP  Select, VARIANT
  COM_MTD_DSP  SetShapesDefaultProperties
  COM_MTD_DSP  Ungroup, ptr ptr ShapeRange
  COM_MTD_DSP  ZOrder, MsoZOrderCmd
  COM_MTD_DSP  get_Adjustments, ptr ptr Adjustments
  COM_MTD_DSP  get_TextFrame, ptr ptr TextFrame
  COM_MTD_DSP  get_AutoShapeType, ptr MsoAutoShapeType
  COM_MTD_DSP  put_AutoShapeType, MsoAutoShapeType
  COM_MTD_DSP  get_Callout, ptr ptr CalloutFormat
  COM_MTD_DSP  get_ConnectionSiteCount, ptr SDWORD
  COM_MTD_DSP  get_Connector, ptr MsoTriState
  COM_MTD_DSP  get_ConnectorFormat, ptr ptr ConnectorFormat
  COM_MTD_DSP  get_Fill, ptr ptr FillFormat
  COM_MTD_DSP  get_GroupItems, ptr ptr GroupShapes
  COM_MTD_DSP  get_Height, ptr REAL4
  COM_MTD_DSP  put_Height, REAL4
  COM_MTD_DSP  get_HorizontalFlip, ptr MsoTriState
  COM_MTD_DSP  get_Left, ptr REAL4
  COM_MTD_DSP  put_Left, REAL4
  COM_MTD_DSP  get_Line, ptr ptr LineFormat
  COM_MTD_DSP  get_LockAspectRatio, ptr MsoTriState
  COM_MTD_DSP  put_LockAspectRatio, MsoTriState
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  get_Nodes, ptr ptr ShapeNodes
  COM_MTD_DSP  get_Rotation, ptr REAL4
  COM_MTD_DSP  put_Rotation, REAL4
  COM_MTD_DSP  get_PictureFormat, ptr ptr PictureFormat
  COM_MTD_DSP  get_Shadow, ptr ptr ShadowFormat
  COM_MTD_DSP  get_TextEffect, ptr ptr TextEffectFormat
  COM_MTD_DSP  get_ThreeD, ptr ptr ThreeDFormat
  COM_MTD_DSP  get_Top, ptr REAL4
  COM_MTD_DSP  put_Top, REAL4
  COM_MTD_DSP  get_Type, ptr MsoShapeType
  COM_MTD_DSP  get_VerticalFlip, ptr MsoTriState
  COM_MTD_DSP  get_Vertices, ptr VARIANT
  COM_MTD_DSP  get_Visible, ptr MsoTriState
  COM_MTD_DSP  put_Visible, MsoTriState
  COM_MTD_DSP  get_Width, ptr REAL4
  COM_MTD_DSP  put_Width, REAL4
  COM_MTD_DSP  get_ZOrderPosition, ptr SDWORD
  COM_MTD_DSP  get_BlackWhiteMode, ptr MsoBlackWhiteMode
  COM_MTD_DSP  put_BlackWhiteMode, MsoBlackWhiteMode
  COM_MTD_DSP  get_AlternativeText, ptr BSTR
  COM_MTD_DSP  put_AlternativeText, BSTR
  COM_MTD_DSP  get_DiagramNode, ptr ptr DiagramNode
  COM_MTD_DSP  get_HasDiagramNode, ptr MsoTriState
  COM_MTD_DSP  get_Diagram, ptr ptr Diagram
  COM_MTD_DSP  get_HasDiagram, ptr MsoTriState
  COM_MTD_DSP  get_Child, ptr MsoTriState
  COM_MTD_DSP  get_ParentGroup, ptr ptr Shape
  COM_MTD_DSP  get_CanvasItems, ptr ptr CanvasShapes
  COM_MTD_DSP  get_ID, ptr SDWORD
  COM_MTD_DSP  CanvasCropLeft, REAL4
  COM_MTD_DSP  CanvasCropTop, REAL4
  COM_MTD_DSP  CanvasCropRight, REAL4
  COM_MTD_DSP  CanvasCropBottom, REAL4
COM_INTERFACE_END

COM_INTERFACE_BEG GroupShapes, IDispatch, <0002443C-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Item, VARIANT, ptr ptr Shape
  COM_MTD_DSP  _Default, VARIANT, ptr ptr Shape
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_DSP  get_Range, VARIANT, ptr ptr ShapeRange
COM_INTERFACE_END

COM_INTERFACE_BEG TextFrame, IDispatch, <0002443D-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_MarginBottom, ptr REAL4
  COM_MTD_DSP  put_MarginBottom, REAL4
  COM_MTD_DSP  get_MarginLeft, ptr REAL4
  COM_MTD_DSP  put_MarginLeft, REAL4
  COM_MTD_DSP  get_MarginRight, ptr REAL4
  COM_MTD_DSP  put_MarginRight, REAL4
  COM_MTD_DSP  get_MarginTop, ptr REAL4
  COM_MTD_DSP  put_MarginTop, REAL4
  COM_MTD_DSP  get_Orientation, ptr MsoTextOrientation
  COM_MTD_DSP  put_Orientation, MsoTextOrientation
  COM_MTD_DSP  Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_DSP  get_HorizontalAlignment, ptr XlHAlign
  COM_MTD_DSP  put_HorizontalAlignment, XlHAlign
  COM_MTD_DSP  get_VerticalAlignment, ptr XlVAlign
  COM_MTD_DSP  put_VerticalAlignment, XlVAlign
  COM_MTD_DSP  get_AutoSize, ptr BOOL
  COM_MTD_DSP  put_AutoSize, BOOL
  COM_MTD_DSP  get_ReadingOrder, ptr SDWORD
  COM_MTD_DSP  put_ReadingOrder, SDWORD
  COM_MTD_DSP  get_AutoMargins, ptr BOOL
  COM_MTD_DSP  put_AutoMargins, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG ConnectorFormat, IDispatch, <0002443E-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  BeginConnect, ptr Shape, SDWORD
  COM_MTD_DSP  BeginDisconnect
  COM_MTD_DSP  EndConnect, ptr Shape, SDWORD
  COM_MTD_DSP  EndDisconnect
  COM_MTD_DSP  get_BeginConnected, ptr MsoTriState
  COM_MTD_DSP  get_BeginConnectedShape, ptr ptr Shape
  COM_MTD_DSP  get_BeginConnectionSite, ptr SDWORD
  COM_MTD_DSP  get_EndConnected, ptr MsoTriState
  COM_MTD_DSP  get_EndConnectedShape, ptr ptr Shape
  COM_MTD_DSP  get_EndConnectionSite, ptr SDWORD
  COM_MTD_DSP  get_Type, ptr MsoConnectorType
  COM_MTD_DSP  put_Type, MsoConnectorType
COM_INTERFACE_END

COM_INTERFACE_BEG FreeformBuilder, IDispatch, <0002443F-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  AddNodes, MsoSegmentType, MsoEditingType, REAL4, REAL4, VARIANT, VARIANT, VARIANT, VARIANT
  COM_MTD_DSP  ConvertToShape, ptr ptr Shape
COM_INTERFACE_END

COM_INTERFACE_BEG ControlFormat, IDispatch, <00024440-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  AddItem, BSTR, VARIANT
  COM_MTD_DSP  RemoveAllItems
  COM_MTD_DSP  RemoveItem, SDWORD, VARIANT
  COM_MTD_DSP  get_DropDownLines, ptr SDWORD
  COM_MTD_DSP  put_DropDownLines, SDWORD
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_LargeChange, ptr SDWORD
  COM_MTD_DSP  put_LargeChange, SDWORD
  COM_MTD_DSP  get_LinkedCell, ptr BSTR
  COM_MTD_DSP  put_LinkedCell, BSTR
  COM_MTD_DSP  List, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_ListCount, ptr SDWORD
  COM_MTD_DSP  put_ListCount, SDWORD
  COM_MTD_DSP  get_ListFillRange, ptr BSTR
  COM_MTD_DSP  put_ListFillRange, BSTR
  COM_MTD_DSP  get_ListIndex, ptr SDWORD
  COM_MTD_DSP  put_ListIndex, SDWORD
  COM_MTD_DSP  get_LockedText, ptr BOOL
  COM_MTD_DSP  put_LockedText, BOOL
  COM_MTD_DSP  get_Max, ptr SDWORD
  COM_MTD_DSP  put_Max, SDWORD
  COM_MTD_DSP  get_Min, ptr SDWORD
  COM_MTD_DSP  put_Min, SDWORD
  COM_MTD_DSP  get_MultiSelect, ptr SDWORD
  COM_MTD_DSP  put_MultiSelect, SDWORD
  COM_MTD_DSP  get_PrintObject, ptr BOOL
  COM_MTD_DSP  put_PrintObject, BOOL
  COM_MTD_DSP  get_SmallChange, ptr SDWORD
  COM_MTD_DSP  put_SmallChange, SDWORD
  COM_MTD_DSP  get__Default, ptr SDWORD
  COM_MTD_DSP  put__Default, SDWORD
  COM_MTD_DSP  get_Value, ptr SDWORD
  COM_MTD_DSP  put_Value, SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG OLEFormat, IDispatch, <00024441-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Activate
  COM_MTD_DSP  get_Object, ptr LPDISPATCH
  COM_MTD_DSP  get_progID, ptr BSTR
  COM_MTD_DSP  Verb, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG LinkFormat, IDispatch, <00024442-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_AutoUpdate, ptr BOOL
  COM_MTD_DSP  put_AutoUpdate, BOOL
  COM_MTD_DSP  get_Locked, ptr BOOL
  COM_MTD_DSP  put_Locked, BOOL
  COM_MTD_DSP  Update
COM_INTERFACE_END

COM_INTERFACE_BEG PublishObjects, IDispatch, <00024443-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Add_, XlSourceType, BSTR, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr ptr PublishObject
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  get_Item, VARIANT, ptr ptr PublishObject
  COM_MTD_DSP  get__Default, VARIANT, ptr ptr PublishObject
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_DSP  Delete
  COM_MTD_DSP  Publish
COM_INTERFACE_END

COM_INTERFACE_BEG OLEDBError, IDispatch, <00024445-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_SqlState, ptr BSTR
  COM_MTD_DSP  get_ErrorString, ptr BSTR
  COM_MTD_DSP  get_Native, ptr SDWORD
  COM_MTD_DSP  get_Number, ptr SDWORD
  COM_MTD_DSP  get_Stage, ptr SDWORD
COM_INTERFACE_END

COM_INTERFACE_BEG OLEDBErrors, IDispatch, <00024446-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Item, SDWORD, ptr ptr OLEDBError
  COM_MTD_DSP  get__Default, SDWORD, ptr ptr OLEDBError
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG Phonetics, IDispatch, <00024447-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  get_Start, ptr SDWORD
  COM_MTD_DSP  get_Length, ptr SDWORD
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_CharacterType, ptr SDWORD
  COM_MTD_DSP  put_CharacterType, SDWORD
  COM_MTD_DSP  get_Alignment, ptr SDWORD
  COM_MTD_DSP  put_Alignment, SDWORD
  COM_MTD_DSP  get_Font, ptr ptr Font
  COM_MTD_DSP  get_Item, SDWORD, ptr LPDISPATCH
  COM_MTD_DSP  Delete
  COM_MTD_DSP  Add_, SDWORD, SDWORD, BSTR
  COM_MTD_DSP  get_Text, ptr BSTR
  COM_MTD_DSP  put_Text, BSTR
  COM_MTD_DSP  get__Default, SDWORD, ptr LPDISPATCH
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG PivotLayout, IDispatch, <0002444A-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_ColumnFields, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  get_DataFields, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  get_PageFields, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  get_RowFields, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  get_HiddenFields, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  get_VisibleFields, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  get_PivotFields, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  get_CubeFields, ptr ptr CubeFields
  COM_MTD_DSP  get_PivotCache, ptr ptr PivotCache
  COM_MTD_DSP  get_PivotTable, ptr ptr PivotTable
  COM_MTD_DSP  get_InnerDetail, ptr BSTR
  COM_MTD_DSP  put_InnerDetail, BSTR
  COM_MTD_DSP  AddFields, VARIANT, VARIANT, VARIANT, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG DisplayUnitLabel, IDispatch, <0002084C-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  Select, ptr VARIANT
  COM_MTD_DSP  get_Border, ptr ptr Border
  COM_MTD_DSP  Delete, ptr VARIANT
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  get_Fill, ptr ptr ChartFillFormat
  COM_MTD_DSP  get_Caption, ptr BSTR
  COM_MTD_DSP  put_Caption, BSTR
  COM_MTD_DSP  get_Characters, VARIANT, VARIANT, ptr ptr Characters
  COM_MTD_DSP  get_Font, ptr ptr Font
  COM_MTD_DSP  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_DSP  put_HorizontalAlignment, VARIANT
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  get_Orientation, ptr VARIANT
  COM_MTD_DSP  put_Orientation, VARIANT
  COM_MTD_DSP  get_Shadow, ptr BOOL
  COM_MTD_DSP  put_Shadow, BOOL
  COM_MTD_DSP  get_Text, ptr BSTR
  COM_MTD_DSP  put_Text, BSTR
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  get_VerticalAlignment, ptr VARIANT
  COM_MTD_DSP  put_VerticalAlignment, VARIANT
  COM_MTD_DSP  get_ReadingOrder, ptr SDWORD
  COM_MTD_DSP  put_ReadingOrder, SDWORD
  COM_MTD_DSP  get_AutoScaleFont, ptr VARIANT
  COM_MTD_DSP  put_AutoScaleFont, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG CellFormat, IDispatch, <00024450-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Borders, ptr ptr Borders
  COM_MTD_DSP  putref_Borders, ptr Borders
  COM_MTD_DSP  get_Font, ptr ptr Font
  COM_MTD_DSP  putref_Font, ptr Font
  COM_MTD_DSP  get_Interior, ptr ptr Interior
  COM_MTD_DSP  putref_Interior, ptr Interior
  COM_MTD_DSP  get_NumberFormat, ptr VARIANT
  COM_MTD_DSP  put_NumberFormat, VARIANT
  COM_MTD_DSP  get_NumberFormatLocal, ptr VARIANT
  COM_MTD_DSP  put_NumberFormatLocal, VARIANT
  COM_MTD_DSP  get_AddIndent, ptr VARIANT
  COM_MTD_DSP  put_AddIndent, VARIANT
  COM_MTD_DSP  get_IndentLevel, ptr VARIANT
  COM_MTD_DSP  put_IndentLevel, VARIANT
  COM_MTD_DSP  get_HorizontalAlignment, ptr VARIANT
  COM_MTD_DSP  put_HorizontalAlignment, VARIANT
  COM_MTD_DSP  get_VerticalAlignment, ptr VARIANT
  COM_MTD_DSP  put_VerticalAlignment, VARIANT
  COM_MTD_DSP  get_Orientation, ptr VARIANT
  COM_MTD_DSP  put_Orientation, VARIANT
  COM_MTD_DSP  get_ShrinkToFit, ptr VARIANT
  COM_MTD_DSP  put_ShrinkToFit, VARIANT
  COM_MTD_DSP  get_WrapText, ptr VARIANT
  COM_MTD_DSP  put_WrapText, VARIANT
  COM_MTD_DSP  get_Locked, ptr VARIANT
  COM_MTD_DSP  put_Locked, VARIANT
  COM_MTD_DSP  get_FormulaHidden, ptr VARIANT
  COM_MTD_DSP  put_FormulaHidden, VARIANT
  COM_MTD_DSP  get_MergeCells, ptr VARIANT
  COM_MTD_DSP  put_MergeCells, VARIANT
  COM_MTD_DSP  Clear
COM_INTERFACE_END

COM_INTERFACE_BEG UsedObjects, IDispatch, <00024451-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_DSP  get__Default, VARIANT, ptr LPDISPATCH
  COM_MTD_DSP  get_Item, VARIANT, ptr LPDISPATCH
COM_INTERFACE_END

COM_INTERFACE_BEG CustomProperties, IDispatch, <00024452-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Add_, BSTR, VARIANT, ptr ptr CustomProperty
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  get__Default, VARIANT, ptr ptr CustomProperty
  COM_MTD_DSP  get_Item, VARIANT, ptr ptr CustomProperty
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG CustomProperty, IDispatch, <00024453-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  put_Name, BSTR
  COM_MTD_DSP  get_Value, ptr VARIANT
  COM_MTD_DSP  put_Value, VARIANT
  COM_MTD_DSP  get__Default, ptr VARIANT
  COM_MTD_DSP  Delete
COM_INTERFACE_END

COM_INTERFACE_BEG CalculatedMembers, IDispatch, <00024454-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  get_Item, VARIANT, ptr ptr CalculatedMember
  COM_MTD_DSP  get__Default, VARIANT, ptr ptr CalculatedMember
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_DSP  Add_, BSTR, BSTR, VARIANT, VARIANT, ptr ptr CalculatedMember
COM_INTERFACE_END

COM_INTERFACE_BEG CalculatedMember, IDispatch, <00024455-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  get_Formula, ptr BSTR
  COM_MTD_DSP  get_SourceName, ptr BSTR
  COM_MTD_DSP  get_SolveOrder, ptr SDWORD
  COM_MTD_DSP  get_IsValid, ptr BOOL
  COM_MTD_DSP  get__Default, ptr BSTR
  COM_MTD_DSP  Delete
  COM_MTD_DSP  get_Type, ptr XlCalculatedMemberType
COM_INTERFACE_END

COM_INTERFACE_BEG Watches, IDispatch, <00024456-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Add_, VARIANT, ptr ptr Watch
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  get__Default, VARIANT, ptr ptr Watch
  COM_MTD_DSP  get_Item, VARIANT, ptr ptr Watch
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_DSP  Delete
COM_INTERFACE_END

COM_INTERFACE_BEG Watch, IDispatch, <00024457-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Delete
  COM_MTD_DSP  get_Source, ptr VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG PivotCell, IDispatch, <00024458-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_PivotCellType, ptr XlPivotCellType
  COM_MTD_DSP  get_PivotTable, ptr ptr PivotTable
  COM_MTD_DSP  get_DataField, ptr ptr PivotField
  COM_MTD_DSP  get_PivotField, ptr ptr PivotField
  COM_MTD_DSP  get_PivotItem, ptr ptr PivotItem
  COM_MTD_DSP  get_RowItems, ptr ptr PivotItemList
  COM_MTD_DSP  get_ColumnItems, ptr ptr PivotItemList
  COM_MTD_DSP  get_Range, ptr ptr Range
  COM_MTD_DSP  get_Dummy18, ptr BSTR
  COM_MTD_DSP  get_CustomSubtotalFunction, ptr XlConsolidationFunction
COM_INTERFACE_END

COM_INTERFACE_BEG Graphic, IDispatch, <00024459-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Brightness, ptr REAL4
  COM_MTD_DSP  put_Brightness, REAL4
  COM_MTD_DSP  get_ColorType, ptr MsoPictureColorType
  COM_MTD_DSP  put_ColorType, MsoPictureColorType
  COM_MTD_DSP  get_Contrast, ptr REAL4
  COM_MTD_DSP  put_Contrast, REAL4
  COM_MTD_DSP  get_CropBottom, ptr REAL4
  COM_MTD_DSP  put_CropBottom, REAL4
  COM_MTD_DSP  get_CropLeft, ptr REAL4
  COM_MTD_DSP  put_CropLeft, REAL4
  COM_MTD_DSP  get_CropRight, ptr REAL4
  COM_MTD_DSP  put_CropRight, REAL4
  COM_MTD_DSP  get_CropTop, ptr REAL4
  COM_MTD_DSP  put_CropTop, REAL4
  COM_MTD_DSP  get_Filename, ptr BSTR
  COM_MTD_DSP  put_Filename, BSTR
  COM_MTD_DSP  get_Height, ptr REAL4
  COM_MTD_DSP  put_Height, REAL4
  COM_MTD_DSP  get_LockAspectRatio, ptr MsoTriState
  COM_MTD_DSP  put_LockAspectRatio, MsoTriState
  COM_MTD_DSP  get_Width, ptr REAL4
  COM_MTD_DSP  put_Width, REAL4
COM_INTERFACE_END

COM_INTERFACE_BEG AutoRecover, IDispatch, <0002445A-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_Time, ptr SDWORD
  COM_MTD_DSP  put_Time, SDWORD
  COM_MTD_DSP  get_Path, ptr BSTR
  COM_MTD_DSP  put_Path, BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG ErrorCheckingOptions, IDispatch, <0002445B-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_BackgroundChecking, ptr BOOL
  COM_MTD_DSP  put_BackgroundChecking, BOOL
  COM_MTD_DSP  get_IndicatorColorIndex, ptr XlColorIndex
  COM_MTD_DSP  put_IndicatorColorIndex, XlColorIndex
  COM_MTD_DSP  get_EvaluateToError, ptr BOOL
  COM_MTD_DSP  put_EvaluateToError, BOOL
  COM_MTD_DSP  get_TextDate, ptr BOOL
  COM_MTD_DSP  put_TextDate, BOOL
  COM_MTD_DSP  get_NumberAsText, ptr BOOL
  COM_MTD_DSP  put_NumberAsText, BOOL
  COM_MTD_DSP  get_InconsistentFormula, ptr BOOL
  COM_MTD_DSP  put_InconsistentFormula, BOOL
  COM_MTD_DSP  get_OmittedCells, ptr BOOL
  COM_MTD_DSP  put_OmittedCells, BOOL
  COM_MTD_DSP  get_UnlockedFormulaCells, ptr BOOL
  COM_MTD_DSP  put_UnlockedFormulaCells, BOOL
  COM_MTD_DSP  get_EmptyCellReferences, ptr BOOL
  COM_MTD_DSP  put_EmptyCellReferences, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG Errors, IDispatch, <0002445C-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Item, VARIANT, ptr ptr Error
  COM_MTD_DSP  get__Default, VARIANT, ptr ptr Error
COM_INTERFACE_END

COM_INTERFACE_BEG Error, IDispatch, <0002445D-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Value, ptr BOOL
  COM_MTD_DSP  get_Ignore, ptr BOOL
  COM_MTD_DSP  put_Ignore, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG SmartTagAction, IDispatch, <0002445E-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  Execute
  COM_MTD_DSP  get__Default, ptr BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG SmartTagActions, IDispatch, <0002445F-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  get__Default, VARIANT, ptr ptr SmartTagAction
  COM_MTD_DSP  get_Item, VARIANT, ptr ptr SmartTagAction
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG SmartTag, IDispatch, <00024460-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_DownloadURL, ptr BSTR
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  get__Default, ptr BSTR
  COM_MTD_DSP  get_XML, ptr BSTR
  COM_MTD_DSP  get_Range, ptr ptr Range
  COM_MTD_DSP  Delete
  COM_MTD_DSP  get_SmartTagActions, ptr ptr SmartTagActions
  COM_MTD_DSP  get_Properties, ptr ptr CustomProperties
COM_INTERFACE_END

COM_INTERFACE_BEG SmartTags, IDispatch, <00024461-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Add_, BSTR, ptr ptr SmartTag
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  get__Default, VARIANT, ptr ptr SmartTag
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG SmartTagRecognizer, IDispatch, <00024462-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Enabled, ptr BOOL
  COM_MTD_DSP  put_Enabled, BOOL
  COM_MTD_DSP  get_progID, ptr BSTR
  COM_MTD_DSP  get__Default, ptr BSTR
  COM_MTD_DSP  get_FullName, ptr BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG SmartTagRecognizers, IDispatch, <00024463-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  get_Item, VARIANT, ptr ptr SmartTagRecognizer
  COM_MTD_DSP  get__Default, VARIANT, ptr ptr SmartTagRecognizer
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
  COM_MTD_DSP  get_Recognize, ptr BOOL
  COM_MTD_DSP  put_Recognize, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG SmartTagOptions, IDispatch, <00024464-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_DisplaySmartTags, ptr XlSmartTagDisplayMode
  COM_MTD_DSP  put_DisplaySmartTags, XlSmartTagDisplayMode
  COM_MTD_DSP  get_EmbedSmartTags, ptr BOOL
  COM_MTD_DSP  put_EmbedSmartTags, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG SpellingOptions, IDispatch, <00024465-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_DictLang, ptr SDWORD
  COM_MTD_DSP  put_DictLang, SDWORD
  COM_MTD_DSP  get_UserDict, ptr BSTR
  COM_MTD_DSP  put_UserDict, BSTR
  COM_MTD_DSP  get_IgnoreCaps, ptr BOOL
  COM_MTD_DSP  put_IgnoreCaps, BOOL
  COM_MTD_DSP  get_SuggestMainOnly, ptr BOOL
  COM_MTD_DSP  put_SuggestMainOnly, BOOL
  COM_MTD_DSP  get_IgnoreMixedDigits, ptr BOOL
  COM_MTD_DSP  put_IgnoreMixedDigits, BOOL
  COM_MTD_DSP  get_IgnoreFileNames, ptr BOOL
  COM_MTD_DSP  put_IgnoreFileNames, BOOL
  COM_MTD_DSP  get_GermanPostReform, ptr BOOL
  COM_MTD_DSP  put_GermanPostReform, BOOL
  COM_MTD_DSP  get_KoreanCombineAux, ptr BOOL
  COM_MTD_DSP  put_KoreanCombineAux, BOOL
  COM_MTD_DSP  get_KoreanUseAutoChangeList, ptr BOOL
  COM_MTD_DSP  put_KoreanUseAutoChangeList, BOOL
  COM_MTD_DSP  get_KoreanProcessCompound, ptr BOOL
  COM_MTD_DSP  put_KoreanProcessCompound, BOOL
  COM_MTD_DSP  get_HebrewModes, ptr XlHebrewModes
  COM_MTD_DSP  put_HebrewModes, XlHebrewModes
  COM_MTD_DSP  get_ArabicModes, ptr XlArabicModes
  COM_MTD_DSP  put_ArabicModes, XlArabicModes
COM_INTERFACE_END

COM_INTERFACE_BEG Speech, IDispatch, <00024466-0000-0000-C000-000000000046>
  COM_MTD_DSP  Speak, BSTR, VARIANT, VARIANT, VARIANT
  COM_MTD_DSP  get_Direction, ptr XlSpeakDirection
  COM_MTD_DSP  put_Direction, XlSpeakDirection
  COM_MTD_DSP  get_SpeakCellOnEnter, ptr BOOL
  COM_MTD_DSP  put_SpeakCellOnEnter, BOOL
COM_INTERFACE_END

COM_INTERFACE_BEG Protection, IDispatch, <00024467-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_AllowFormattingCells, ptr BOOL
  COM_MTD_DSP  get_AllowFormattingColumns, ptr BOOL
  COM_MTD_DSP  get_AllowFormattingRows, ptr BOOL
  COM_MTD_DSP  get_AllowInsertingColumns, ptr BOOL
  COM_MTD_DSP  get_AllowInsertingRows, ptr BOOL
  COM_MTD_DSP  get_AllowInsertingHyperlinks, ptr BOOL
  COM_MTD_DSP  get_AllowDeletingColumns, ptr BOOL
  COM_MTD_DSP  get_AllowDeletingRows, ptr BOOL
  COM_MTD_DSP  get_AllowSorting, ptr BOOL
  COM_MTD_DSP  get_AllowFiltering, ptr BOOL
  COM_MTD_DSP  get_AllowUsingPivotTables, ptr BOOL
  COM_MTD_DSP  get_AllowEditRanges, ptr ptr AllowEditRanges
COM_INTERFACE_END

COM_INTERFACE_BEG PivotItemList, IDispatch, <00024468-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  Item, VARIANT, ptr ptr PivotItem
  COM_MTD_DSP  get__Default, VARIANT, ptr ptr PivotItem
  COM_MTD_DSP  _NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG Tab, IDispatch, <00024469-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Color, ptr VARIANT
  COM_MTD_DSP  put_Color, VARIANT
  COM_MTD_DSP  get_ColorIndex, ptr XlColorIndex
  COM_MTD_DSP  put_ColorIndex, XlColorIndex
COM_INTERFACE_END

COM_INTERFACE_BEG AllowEditRanges, IDispatch, <0002446A-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  get_Item, VARIANT, ptr ptr AllowEditRange
  COM_MTD_DSP  Add_, BSTR, ptr Range, VARIANT, ptr ptr AllowEditRange
  COM_MTD_DSP  get__Default, VARIANT, ptr ptr AllowEditRange
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG AllowEditRange, IDispatch, <0002446B-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Title, ptr BSTR
  COM_MTD_DSP  put_Title, BSTR
  COM_MTD_DSP  get_Range, ptr ptr Range
  COM_MTD_DSP  putref_Range, ptr Range
  COM_MTD_DSP  ChangePassword, BSTR
  COM_MTD_DSP  Delete
  COM_MTD_DSP  Unprotect, VARIANT
  COM_MTD_DSP  get_Users, ptr ptr UserAccessList
COM_INTERFACE_END

COM_INTERFACE_BEG UserAccessList, IDispatch, <0002446C-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Count, ptr SDWORD
  COM_MTD_DSP  get_Item, VARIANT, ptr ptr UserAccess
  COM_MTD_DSP  Add_, BSTR, BOOL, ptr ptr UserAccess
  COM_MTD_DSP  DeleteAll
  COM_MTD_DSP  get__Default, VARIANT, ptr ptr UserAccess
  COM_MTD_DSP  get__NewEnum, ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG UserAccess, IDispatch, <0002446D-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Name, ptr BSTR
  COM_MTD_DSP  get_AllowEdit, ptr BOOL
  COM_MTD_DSP  put_AllowEdit, BOOL
  COM_MTD_DSP  Delete
COM_INTERFACE_END

COM_INTERFACE_BEG RTD, IDispatch, <0002446E-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_ThrottleInterval, ptr SDWORD
  COM_MTD_DSP  put_ThrottleInterval, SDWORD
  COM_MTD_DSP  RefreshData
  COM_MTD_DSP  RestartServers
COM_INTERFACE_END

COM_INTERFACE_BEG Diagram, IDispatch, <0002446F-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Nodes, ptr ptr DiagramNodes
  COM_MTD_DSP  get_Type, ptr MsoDiagramType
  COM_MTD_DSP  get_AutoLayout, ptr MsoTriState
  COM_MTD_DSP  put_AutoLayout, MsoTriState
  COM_MTD_DSP  get_Reverse, ptr MsoTriState
  COM_MTD_DSP  put_Reverse, MsoTriState
  COM_MTD_DSP  get_AutoFormat, ptr MsoTriState
  COM_MTD_DSP  put_AutoFormat, MsoTriState
  COM_MTD_DSP  Convert, MsoDiagramType
COM_INTERFACE_END

COM_INTERFACE_BEG Font, IDispatch, <0002084D-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  get_Background, ptr VARIANT
  COM_MTD_DSP  put_Background, VARIANT
  COM_MTD_DSP  get_Bold, ptr VARIANT
  COM_MTD_DSP  put_Bold, VARIANT
  COM_MTD_DSP  get_Color, ptr VARIANT
  COM_MTD_DSP  put_Color, VARIANT
  COM_MTD_DSP  get_ColorIndex, ptr VARIANT
  COM_MTD_DSP  put_ColorIndex, VARIANT
  COM_MTD_DSP  get_FontStyle, ptr VARIANT
  COM_MTD_DSP  put_FontStyle, VARIANT
  COM_MTD_DSP  get_Italic, ptr VARIANT
  COM_MTD_DSP  put_Italic, VARIANT
  COM_MTD_DSP  get_Name, ptr VARIANT
  COM_MTD_DSP  put_Name, VARIANT
  COM_MTD_DSP  get_OutlineFont, ptr VARIANT
  COM_MTD_DSP  put_OutlineFont, VARIANT
  COM_MTD_DSP  get_Shadow, ptr VARIANT
  COM_MTD_DSP  put_Shadow, VARIANT
  COM_MTD_DSP  get_Size, ptr VARIANT
  COM_MTD_DSP  put_Size, VARIANT
  COM_MTD_DSP  get_Strikethrough, ptr VARIANT
  COM_MTD_DSP  put_Strikethrough, VARIANT
  COM_MTD_DSP  get_Subscript, ptr VARIANT
  COM_MTD_DSP  put_Subscript, VARIANT
  COM_MTD_DSP  get_Superscript, ptr VARIANT
  COM_MTD_DSP  put_Superscript, VARIANT
  COM_MTD_DSP  get_Underline, ptr VARIANT
  COM_MTD_DSP  put_Underline, VARIANT
COM_INTERFACE_END

COM_INTERFACE_BEG Window, IDispatch, <00020893-0000-0000-C000-000000000046>
  COM_MTD_DSP  get_Application, ptr ptr Application
  COM_MTD_DSP  get_Creator, ptr XlCreator
  COM_MTD_DSP  get_Parent, ptr LPDISPATCH
  COM_MTD_DSP  Activate, ptr VARIANT
  COM_MTD_DSP  ActivateNext, ptr VARIANT
  COM_MTD_DSP  ActivatePrevious, ptr VARIANT
  COM_MTD_DSP  get_ActiveCell, ptr ptr Range
  COM_MTD_DSP  get_ActiveChart, ptr ptr Chart
  COM_MTD_DSP  get_ActivePane, ptr ptr Pane
  COM_MTD_DSP  get_ActiveSheet, ptr LPDISPATCH
  COM_MTD_DSP  get_Caption, ptr VARIANT
  COM_MTD_DSP  put_Caption, VARIANT
  COM_MTD_DSP  Close, VARIANT, VARIANT, VARIANT, ptr BOOL
  COM_MTD_DSP  get_DisplayFormulas, ptr BOOL
  COM_MTD_DSP  put_DisplayFormulas, BOOL
  COM_MTD_DSP  get_DisplayGridlines, ptr BOOL
  COM_MTD_DSP  put_DisplayGridlines, BOOL
  COM_MTD_DSP  get_DisplayHeadings, ptr BOOL
  COM_MTD_DSP  put_DisplayHeadings, BOOL
  COM_MTD_DSP  get_DisplayHorizontalScrollBar, ptr BOOL
  COM_MTD_DSP  put_DisplayHorizontalScrollBar, BOOL
  COM_MTD_DSP  get_DisplayOutline, ptr BOOL
  COM_MTD_DSP  put_DisplayOutline, BOOL
  COM_MTD_DSP  get__DisplayRightToLeft, ptr BOOL
  COM_MTD_DSP  put__DisplayRightToLeft, BOOL
  COM_MTD_DSP  get_DisplayVerticalScrollBar, ptr BOOL
  COM_MTD_DSP  put_DisplayVerticalScrollBar, BOOL
  COM_MTD_DSP  get_DisplayWorkbookTabs, ptr BOOL
  COM_MTD_DSP  put_DisplayWorkbookTabs, BOOL
  COM_MTD_DSP  get_DisplayZeros, ptr BOOL
  COM_MTD_DSP  put_DisplayZeros, BOOL
  COM_MTD_DSP  get_EnableResize, ptr BOOL
  COM_MTD_DSP  put_EnableResize, BOOL
  COM_MTD_DSP  get_FreezePanes, ptr BOOL
  COM_MTD_DSP  put_FreezePanes, BOOL
  COM_MTD_DSP  get_GridlineColor, ptr SDWORD
  COM_MTD_DSP  put_GridlineColor, SDWORD
  COM_MTD_DSP  get_GridlineColorIndex, ptr XlColorIndex
  COM_MTD_DSP  put_GridlineColorIndex, XlColorIndex
  COM_MTD_DSP  get_Height, ptr REAL8
  COM_MTD_DSP  put_Height, REAL8
  COM_MTD_DSP  get_Index, ptr SDWORD
  COM_MTD_DSP  LargeScroll, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_Left, ptr REAL8
  COM_MTD_DSP  put_Left, REAL8
  COM_MTD_DSP  NewWindow, ptr ptr Window
  COM_MTD_DSP  get_OnWindow, ptr BSTR
  COM_MTD_DSP  put_OnWindow, BSTR
  COM_MTD_DSP  get_Panes, ptr ptr Panes
  COM_MTD_DSP  PrintOut, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  PrintPreview, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_RangeSelection, ptr ptr Range
  COM_MTD_DSP  get_ScrollColumn, ptr SDWORD
  COM_MTD_DSP  put_ScrollColumn, SDWORD
  COM_MTD_DSP  get_ScrollRow, ptr SDWORD
  COM_MTD_DSP  put_ScrollRow, SDWORD
  COM_MTD_DSP  ScrollWorkbookTabs, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_SelectedSheets, ptr ptr Sheets
  COM_MTD_DSP  get_Selection, ptr LPDISPATCH
  COM_MTD_DSP  SmallScroll, VARIANT, VARIANT, VARIANT, VARIANT, ptr VARIANT
  COM_MTD_DSP  get_Split, ptr BOOL
  COM_MTD_DSP  put_Split, BOOL
  COM_MTD_DSP  get_SplitColumn, ptr SDWORD
  COM_MTD_DSP  put_SplitColumn, SDWORD
  COM_MTD_DSP  get_SplitHorizontal, ptr REAL8
  COM_MTD_DSP  put_SplitHorizontal, REAL8
  COM_MTD_DSP  get_SplitRow, ptr SDWORD
  COM_MTD_DSP  put_SplitRow, SDWORD
  COM_MTD_DSP  get_SplitVertical, ptr REAL8
  COM_MTD_DSP  put_SplitVertical, REAL8
  COM_MTD_DSP  get_TabRatio, ptr REAL8
  COM_MTD_DSP  put_TabRatio, REAL8
  COM_MTD_DSP  get_Top, ptr REAL8
  COM_MTD_DSP  put_Top, REAL8
  COM_MTD_DSP  get_Type, ptr XlWindowType
  COM_MTD_DSP  get_UsableHeight, ptr REAL8
  COM_MTD_DSP  get_UsableWidth, ptr REAL8
  COM_MTD_DSP  get_Visible, ptr BOOL
  COM_MTD_DSP  put_Visible, BOOL
  COM_MTD_DSP  get_VisibleRange, ptr ptr Range
  COM_MTD_DSP  get_Width, ptr REAL8
  COM_MTD_DSP  put_Width, REAL8
  COM_MTD_DSP  get_WindowNumber, ptr SDWORD
  COM_MTD_DSP  get_WindowState, ptr XlWindowState
  COM_MTD_DSP  put_WindowState, XlWindowState
  COM_MTD_DSP  get_Zoom, ptr VARIANT
  COM_MTD_DSP  put_Zoom, VARIANT
  COM_MTD_DSP  get_View, ptr XlWindowView
  COM_MTD_DSP  put_View, XlWindowView
  COM_MTD_DSP  get_DisplayRightToLeft, ptr BOOL
  COM_MTD_DSP  put_DisplayRightToLeft, BOOL
  COM_MTD_DSP  PointsToScreenPixelsX, SDWORD, ptr SDWORD
  COM_MTD_DSP  PointsToScreenPixelsY, SDWORD, ptr SDWORD
  COM_MTD_DSP  RangeFromPoint, SDWORD, SDWORD, ptr LPDISPATCH
  COM_MTD_DSP  ScrollIntoView, SDWORD, SDWORD, SDWORD, SDWORD, VARIANT
COM_INTERFACE_END


sCLSID_QueryTable   textequ <59191DA1-EA47-11CE-A51F-00AA0061507F>
sCLSID_Application  textequ <00024500-0000-0000-C000-000000000046>
sCLSID_Chart        textequ <00020821-0000-0000-C000-000000000046>
sCLSID_Worksheet    textequ <00020820-0000-0000-C000-000000000046>
sCLSID_Global       textequ <00020812-0000-0000-C000-000000000046>
sCLSID_Workbook     textequ <00020819-0000-0000-C000-000000000046>
sCLSID_OLEObject    textequ <00020818-0000-0000-C000-000000000046>
