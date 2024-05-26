;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdiplusflat.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 16/12/2023 11:07:10

ifndef _FLATAPI_H
  _FLATAPI_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    WINGDIPAPI equ <__stdcall>
    GDIPCONST equ <const>
    ifdef __cplusplus
      ;[...]
    endif
    GdipCreatePath proto WIN_STD_CALL_CONV :GpFillMode, :ptr ptr GpPath
    GdipCreatePath2 proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr GDIPCONST, :INT_, :GpFillMode, :ptr ptr GpPath
    GdipCreatePath2I proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr GDIPCONST, :INT_, :GpFillMode, :ptr ptr GpPath
    GdipClonePath proto WIN_STD_CALL_CONV :ptr GpPath, :ptr ptr GpPath
    GdipDeletePath proto WIN_STD_CALL_CONV :ptr GpPath
    GdipResetPath proto WIN_STD_CALL_CONV :ptr GpPath
    GdipGetPointCount proto WIN_STD_CALL_CONV :ptr GpPath, :ptr INT_
    GdipGetPathTypes proto WIN_STD_CALL_CONV :ptr GpPath, :ptr BYTE, :INT_
    GdipGetPathPoints proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GpPointF, :INT_
    GdipGetPathPointsI proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GpPoint, :INT_
    GdipGetPathFillMode proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GpFillMode
    GdipSetPathFillMode proto WIN_STD_CALL_CONV :ptr GpPath, :GpFillMode
    GdipGetPathData proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GpPathData
    GdipStartPathFigure proto WIN_STD_CALL_CONV :ptr GpPath
    GdipClosePathFigure proto WIN_STD_CALL_CONV :ptr GpPath
    GdipClosePathFigures proto WIN_STD_CALL_CONV :ptr GpPath
    GdipSetPathMarker proto WIN_STD_CALL_CONV :ptr GpPath
    GdipClearPathMarkers proto WIN_STD_CALL_CONV :ptr GpPath
    GdipReversePath proto WIN_STD_CALL_CONV :ptr GpPath
    GdipGetPathLastPoint proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GpPointF
    GdipAddPathLine proto WIN_STD_CALL_CONV :ptr GpPath, :REAL, :REAL, :REAL, :REAL
    GdipAddPathLine2 proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GDIPCONST, :INT_
    GdipAddPathArc proto WIN_STD_CALL_CONV :ptr GpPath, :REAL, :REAL, :REAL, :REAL, :REAL, :REAL
    GdipAddPathBezier proto WIN_STD_CALL_CONV :ptr GpPath, :REAL, :REAL, :REAL, :REAL, :REAL, :REAL, :REAL, :REAL
    GdipAddPathBeziers proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GDIPCONST, :INT_
    GdipAddPathCurve proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GDIPCONST, :INT_
    GdipAddPathCurve2 proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GDIPCONST, :INT_, :REAL
    GdipAddPathCurve3 proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GDIPCONST, :INT_, :offset_, :INT_, :REAL
    GdipAddPathClosedCurve proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GDIPCONST, :INT_
    GdipAddPathClosedCurve2 proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GDIPCONST, :INT_, :REAL
    GdipAddPathRectangle proto WIN_STD_CALL_CONV :ptr GpPath, :REAL, :REAL, :REAL, :REAL
    GdipAddPathRectangles proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GDIPCONST, :INT_
    GdipAddPathEllipse proto WIN_STD_CALL_CONV :ptr GpPath, :REAL, :REAL, :REAL, :REAL
    GdipAddPathPie proto WIN_STD_CALL_CONV :ptr GpPath, :REAL, :REAL, :REAL, :REAL, :REAL, :REAL
    GdipAddPathPolygon proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GDIPCONST, :INT_
    GdipAddPathPath proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GDIPCONST, :BOOL
    GdipAddPathString proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GDIPCONST, :length_, :ptr GDIPCONST, :INT_, :REAL, :ptr GDIPCONST, :ptr GDIPCONST
    GdipAddPathStringI proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GDIPCONST, :length_, :ptr GDIPCONST, :INT_, :REAL, :ptr GDIPCONST, :ptr GDIPCONST
    GdipAddPathLineI proto WIN_STD_CALL_CONV :ptr GpPath, :INT_, :INT_, :INT_, :INT_
    GdipAddPathLine2I proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GDIPCONST, :INT_
    GdipAddPathArcI proto WIN_STD_CALL_CONV :ptr GpPath, :INT_, :INT_, :width_, :INT_, :REAL, :REAL
    GdipAddPathBezierI proto WIN_STD_CALL_CONV :ptr GpPath, :INT_, :INT_, :INT_, :INT_, :INT_, :INT_, :INT_, :INT_
    GdipAddPathBeziersI proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GDIPCONST, :INT_
    GdipAddPathCurveI proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GDIPCONST, :INT_
    GdipAddPathCurve2I proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GDIPCONST, :INT_, :REAL
    GdipAddPathCurve3I proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GDIPCONST, :INT_, :offset_, :INT_, :REAL
    GdipAddPathClosedCurveI proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GDIPCONST, :INT_
    GdipAddPathClosedCurve2I proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GDIPCONST, :INT_, :REAL
    GdipAddPathRectangleI proto WIN_STD_CALL_CONV :ptr GpPath, :INT_, :INT_, :width_, :INT_
    GdipAddPathRectanglesI proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GDIPCONST, :INT_
    GdipAddPathEllipseI proto WIN_STD_CALL_CONV :ptr GpPath, :INT_, :INT_, :width_, :INT_
    GdipAddPathPieI proto WIN_STD_CALL_CONV :ptr GpPath, :INT_, :INT_, :width_, :INT_, :REAL, :REAL
    GdipAddPathPolygonI proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GDIPCONST, :INT_
    GdipFlattenPath proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GpMatrix, :REAL
    GdipWindingModeOutline proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GpMatrix, :REAL
    GdipWidenPath proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GpPen, :ptr GpMatrix, :REAL
    GdipWarpPath proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GpMatrix, :ptr GDIPCONST, :INT_, :REAL, :REAL, :REAL, :REAL, :WarpMode, :REAL
    GdipTransformPath proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GpMatrix
    GdipGetPathWorldBounds proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GpRectF, :ptr GDIPCONST, :ptr GDIPCONST
    GdipGetPathWorldBoundsI proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GpRect, :ptr GDIPCONST, :ptr GDIPCONST
    GdipIsVisiblePathPoint proto WIN_STD_CALL_CONV :ptr GpPath, :REAL, :REAL, :ptr GpGraphics, :ptr BOOL
    GdipIsVisiblePathPointI proto WIN_STD_CALL_CONV :ptr GpPath, :INT_, :INT_, :ptr GpGraphics, :ptr BOOL
    GdipIsOutlineVisiblePathPoint proto WIN_STD_CALL_CONV :ptr GpPath, :REAL, :REAL, :ptr GpPen, :ptr GpGraphics, :ptr BOOL
    GdipIsOutlineVisiblePathPointI proto WIN_STD_CALL_CONV :ptr GpPath, :INT_, :INT_, :ptr GpPen, :ptr GpGraphics, :ptr BOOL
    GdipCreatePathIter proto WIN_STD_CALL_CONV :ptr ptr GpPathIterator, :ptr GpPath
    GdipDeletePathIter proto WIN_STD_CALL_CONV :ptr GpPathIterator
    GdipPathIterNextSubpath proto WIN_STD_CALL_CONV :ptr GpPathIterator, :ptr INT_, :ptr INT_, :ptr INT_, :ptr BOOL
    GdipPathIterNextSubpathPath proto WIN_STD_CALL_CONV :ptr GpPathIterator, :ptr INT_, :ptr GpPath, :ptr BOOL
    GdipPathIterNextPathType proto WIN_STD_CALL_CONV :ptr GpPathIterator, :ptr INT_, :ptr BYTE, :ptr INT_, :ptr INT_
    GdipPathIterNextMarker proto WIN_STD_CALL_CONV :ptr GpPathIterator, :ptr INT_, :ptr INT_, :ptr INT_
    GdipPathIterNextMarkerPath proto WIN_STD_CALL_CONV :ptr GpPathIterator, :ptr INT_, :ptr GpPath
    GdipPathIterGetCount proto WIN_STD_CALL_CONV :ptr GpPathIterator, :ptr INT_
    GdipPathIterGetSubpathCount proto WIN_STD_CALL_CONV :ptr GpPathIterator, :ptr INT_
    GdipPathIterIsValid proto WIN_STD_CALL_CONV :ptr GpPathIterator, :ptr BOOL
    GdipPathIterHasCurve proto WIN_STD_CALL_CONV :ptr GpPathIterator, :ptr BOOL
    GdipPathIterRewind proto WIN_STD_CALL_CONV :ptr GpPathIterator
    GdipPathIterEnumerate proto WIN_STD_CALL_CONV :ptr GpPathIterator, :ptr INT_, :ptr GpPointF, :ptr BYTE, :INT_
    GdipPathIterCopyData proto WIN_STD_CALL_CONV :ptr GpPathIterator, :ptr INT_, :ptr GpPointF, :ptr BYTE, :INT_, :INT_
    GdipCreateMatrix proto WIN_STD_CALL_CONV :ptr ptr GpMatrix
    GdipCreateMatrix2 proto WIN_STD_CALL_CONV :REAL, :REAL, :REAL, :REAL, :REAL, :REAL, :ptr ptr GpMatrix
    GdipCreateMatrix3 proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr GDIPCONST, :ptr ptr GpMatrix
    GdipCreateMatrix3I proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr GDIPCONST, :ptr ptr GpMatrix
    GdipCloneMatrix proto WIN_STD_CALL_CONV :ptr GpMatrix, :ptr ptr GpMatrix
    GdipDeleteMatrix proto WIN_STD_CALL_CONV :ptr GpMatrix
    GdipSetMatrixElements proto WIN_STD_CALL_CONV :ptr GpMatrix, :REAL, :REAL, :REAL, :REAL, :REAL, :REAL
    GdipMultiplyMatrix proto WIN_STD_CALL_CONV :ptr GpMatrix, :ptr GpMatrix, :GpMatrixOrder
    GdipTranslateMatrix proto WIN_STD_CALL_CONV :ptr GpMatrix, :REAL, :REAL, :GpMatrixOrder
    GdipScaleMatrix proto WIN_STD_CALL_CONV :ptr GpMatrix, :REAL, :REAL, :GpMatrixOrder
    GdipRotateMatrix proto WIN_STD_CALL_CONV :ptr GpMatrix, :REAL, :GpMatrixOrder
    GdipShearMatrix proto WIN_STD_CALL_CONV :ptr GpMatrix, :REAL, :REAL, :GpMatrixOrder
    GdipInvertMatrix proto WIN_STD_CALL_CONV :ptr GpMatrix
    GdipTransformMatrixPoints proto WIN_STD_CALL_CONV :ptr GpMatrix, :ptr GpPointF, :INT_
    GdipTransformMatrixPointsI proto WIN_STD_CALL_CONV :ptr GpMatrix, :ptr GpPoint, :INT_
    GdipVectorTransformMatrixPoints proto WIN_STD_CALL_CONV :ptr GpMatrix, :ptr GpPointF, :INT_
    GdipVectorTransformMatrixPointsI proto WIN_STD_CALL_CONV :ptr GpMatrix, :ptr GpPoint, :INT_
    GdipGetMatrixElements proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr REAL
    GdipIsMatrixInvertible proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr BOOL
    GdipIsMatrixIdentity proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr BOOL
    GdipIsMatrixEqual proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr GDIPCONST, :ptr BOOL
    GdipCreateRegion proto WIN_STD_CALL_CONV :ptr ptr GpRegion
    GdipCreateRegionRect proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr ptr GpRegion
    GdipCreateRegionRectI proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr ptr GpRegion
    GdipCreateRegionPath proto WIN_STD_CALL_CONV :ptr GpPath, :ptr ptr GpRegion
    GdipCreateRegionRgnData proto WIN_STD_CALL_CONV :ptr GDIPCONST, :size_, :ptr ptr GpRegion
    GdipCreateRegionHrgn proto WIN_STD_CALL_CONV :HRGN, :ptr ptr GpRegion
    GdipCloneRegion proto WIN_STD_CALL_CONV :ptr GpRegion, :ptr ptr GpRegion
    GdipDeleteRegion proto WIN_STD_CALL_CONV :ptr GpRegion
    GdipSetInfinite proto WIN_STD_CALL_CONV :ptr GpRegion
    GdipSetEmpty proto WIN_STD_CALL_CONV :ptr GpRegion
    GdipCombineRegionRect proto WIN_STD_CALL_CONV :ptr GpRegion, :ptr GDIPCONST, :CombineMode
    GdipCombineRegionRectI proto WIN_STD_CALL_CONV :ptr GpRegion, :ptr GDIPCONST, :CombineMode
    GdipCombineRegionPath proto WIN_STD_CALL_CONV :ptr GpRegion, :ptr GpPath, :CombineMode
    GdipCombineRegionRegion proto WIN_STD_CALL_CONV :ptr GpRegion, :ptr GpRegion, :CombineMode
    GdipTranslateRegion proto WIN_STD_CALL_CONV :ptr GpRegion, :REAL, :REAL
    GdipTranslateRegionI proto WIN_STD_CALL_CONV :ptr GpRegion, :dx_, :INT_
    GdipTransformRegion proto WIN_STD_CALL_CONV :ptr GpRegion, :ptr GpMatrix
    GdipGetRegionBounds proto WIN_STD_CALL_CONV :ptr GpRegion, :ptr GpGraphics, :ptr GpRectF
    GdipGetRegionBoundsI proto WIN_STD_CALL_CONV :ptr GpRegion, :ptr GpGraphics, :ptr GpRect
    GdipGetRegionHRgn proto WIN_STD_CALL_CONV :ptr GpRegion, :ptr GpGraphics, :ptr HRGN
    GdipIsEmptyRegion proto WIN_STD_CALL_CONV :ptr GpRegion, :ptr GpGraphics, :ptr BOOL
    GdipIsInfiniteRegion proto WIN_STD_CALL_CONV :ptr GpRegion, :ptr GpGraphics, :ptr BOOL
    GdipIsEqualRegion proto WIN_STD_CALL_CONV :ptr GpRegion, :ptr GpRegion, :ptr GpGraphics, :ptr BOOL
    GdipGetRegionDataSize proto WIN_STD_CALL_CONV :ptr GpRegion, :ptr UINT
    GdipGetRegionData proto WIN_STD_CALL_CONV :ptr GpRegion, :ptr BYTE, :UINT, :ptr UINT
    GdipIsVisibleRegionPoint proto WIN_STD_CALL_CONV :ptr GpRegion, :REAL, :REAL, :ptr GpGraphics, :ptr BOOL
    GdipIsVisibleRegionPointI proto WIN_STD_CALL_CONV :ptr GpRegion, :INT_, :INT_, :ptr GpGraphics, :ptr BOOL
    GdipIsVisibleRegionRect proto WIN_STD_CALL_CONV :ptr GpRegion, :REAL, :REAL, :REAL, :REAL, :ptr GpGraphics, :ptr BOOL
    GdipIsVisibleRegionRectI proto WIN_STD_CALL_CONV :ptr GpRegion, :INT_, :INT_, :width_, :INT_, :ptr GpGraphics, :ptr BOOL
    GdipGetRegionScansCount proto WIN_STD_CALL_CONV :ptr GpRegion, :ptr UINT, :ptr GpMatrix
    GdipGetRegionScans proto WIN_STD_CALL_CONV :ptr GpRegion, :ptr GpRectF, :ptr INT_, :ptr GpMatrix
    GdipGetRegionScansI proto WIN_STD_CALL_CONV :ptr GpRegion, :ptr GpRect, :ptr INT_, :ptr GpMatrix
    GdipCloneBrush proto WIN_STD_CALL_CONV :ptr GpBrush, :ptr ptr GpBrush
    GdipDeleteBrush proto WIN_STD_CALL_CONV :ptr GpBrush
    GdipGetBrushType proto WIN_STD_CALL_CONV :ptr GpBrush, :ptr GpBrushType
    GdipCreateHatchBrush proto WIN_STD_CALL_CONV :GpHatchStyle, :ARGB, :ARGB, :ptr ptr GpHatch
    GdipGetHatchStyle proto WIN_STD_CALL_CONV :ptr GpHatch, :ptr GpHatchStyle
    GdipGetHatchForegroundColor proto WIN_STD_CALL_CONV :ptr GpHatch, :ptr ARGB
    GdipGetHatchBackgroundColor proto WIN_STD_CALL_CONV :ptr GpHatch, :ptr ARGB
    GdipCreateTexture proto WIN_STD_CALL_CONV :ptr GpImage, :GpWrapMode, :ptr ptr GpTexture
    GdipCreateTexture2 proto WIN_STD_CALL_CONV :ptr GpImage, :GpWrapMode, :REAL, :REAL, :REAL, :REAL, :ptr ptr GpTexture
    GdipCreateTextureIA proto WIN_STD_CALL_CONV :ptr GpImage, :ptr GDIPCONST, :REAL, :REAL, :REAL, :REAL, :ptr ptr GpTexture
    GdipCreateTexture2I proto WIN_STD_CALL_CONV :ptr GpImage, :GpWrapMode, :INT_, :INT_, :width_, :INT_, :ptr ptr GpTexture
    GdipCreateTextureIAI proto WIN_STD_CALL_CONV :ptr GpImage, :ptr GDIPCONST, :INT_, :INT_, :width_, :INT_, :ptr ptr GpTexture
    GdipGetTextureTransform proto WIN_STD_CALL_CONV :ptr GpTexture, :ptr GpMatrix
    GdipSetTextureTransform proto WIN_STD_CALL_CONV :ptr GpTexture, :ptr GDIPCONST
    GdipResetTextureTransform proto WIN_STD_CALL_CONV :ptr GpTexture
    GdipMultiplyTextureTransform proto WIN_STD_CALL_CONV :ptr GpTexture, :ptr GDIPCONST, :GpMatrixOrder
    GdipTranslateTextureTransform proto WIN_STD_CALL_CONV :ptr GpTexture, :REAL, :REAL, :GpMatrixOrder
    GdipScaleTextureTransform proto WIN_STD_CALL_CONV :ptr GpTexture, :REAL, :REAL, :GpMatrixOrder
    GdipRotateTextureTransform proto WIN_STD_CALL_CONV :ptr GpTexture, :REAL, :GpMatrixOrder
    GdipSetTextureWrapMode proto WIN_STD_CALL_CONV :ptr GpTexture, :GpWrapMode
    GdipGetTextureWrapMode proto WIN_STD_CALL_CONV :ptr GpTexture, :ptr GpWrapMode
    GdipGetTextureImage proto WIN_STD_CALL_CONV :ptr GpTexture, :ptr ptr GpImage
    GdipCreateSolidFill proto WIN_STD_CALL_CONV :ARGB, :ptr ptr GpSolidFill
    GdipSetSolidFillColor proto WIN_STD_CALL_CONV :ptr GpSolidFill, :ARGB
    GdipGetSolidFillColor proto WIN_STD_CALL_CONV :ptr GpSolidFill, :ptr ARGB
    GdipCreateLineBrush proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr GDIPCONST, :ARGB, :ARGB, :GpWrapMode, :ptr ptr GpLineGradient
    GdipCreateLineBrushI proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr GDIPCONST, :ARGB, :ARGB, :GpWrapMode, :ptr ptr GpLineGradient
    GdipCreateLineBrushFromRect proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ARGB, :ARGB, :LinearGradientMode, :GpWrapMode, :ptr ptr GpLineGradient
    GdipCreateLineBrushFromRectI proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ARGB, :ARGB, :LinearGradientMode, :GpWrapMode, :ptr ptr GpLineGradient
    GdipCreateLineBrushFromRectWithAngle proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ARGB, :ARGB, :REAL, :BOOL, :GpWrapMode, :ptr ptr GpLineGradient
    GdipCreateLineBrushFromRectWithAngleI proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ARGB, :ARGB, :REAL, :BOOL, :GpWrapMode, :ptr ptr GpLineGradient
    GdipSetLineColors proto WIN_STD_CALL_CONV :ptr GpLineGradient, :ARGB, :ARGB
    GdipGetLineColors proto WIN_STD_CALL_CONV :ptr GpLineGradient, :ptr ARGB
    GdipGetLineRect proto WIN_STD_CALL_CONV :ptr GpLineGradient, :ptr GpRectF
    GdipGetLineRectI proto WIN_STD_CALL_CONV :ptr GpLineGradient, :ptr GpRect
    GdipSetLineGammaCorrection proto WIN_STD_CALL_CONV :ptr GpLineGradient, :BOOL
    GdipGetLineGammaCorrection proto WIN_STD_CALL_CONV :ptr GpLineGradient, :ptr BOOL
    GdipGetLineBlendCount proto WIN_STD_CALL_CONV :ptr GpLineGradient, :ptr INT_
    GdipGetLineBlend proto WIN_STD_CALL_CONV :ptr GpLineGradient, :ptr REAL, :ptr REAL, :INT_
    GdipSetLineBlend proto WIN_STD_CALL_CONV :ptr GpLineGradient, :ptr GDIPCONST, :ptr GDIPCONST, :INT_
    GdipGetLinePresetBlendCount proto WIN_STD_CALL_CONV :ptr GpLineGradient, :ptr INT_
    GdipGetLinePresetBlend proto WIN_STD_CALL_CONV :ptr GpLineGradient, :ptr ARGB, :ptr REAL, :INT_
    GdipSetLinePresetBlend proto WIN_STD_CALL_CONV :ptr GpLineGradient, :ptr GDIPCONST, :ptr GDIPCONST, :INT_
    GdipSetLineSigmaBlend proto WIN_STD_CALL_CONV :ptr GpLineGradient, :REAL, :REAL
    GdipSetLineLinearBlend proto WIN_STD_CALL_CONV :ptr GpLineGradient, :REAL, :REAL
    GdipSetLineWrapMode proto WIN_STD_CALL_CONV :ptr GpLineGradient, :GpWrapMode
    GdipGetLineWrapMode proto WIN_STD_CALL_CONV :ptr GpLineGradient, :ptr GpWrapMode
    GdipGetLineTransform proto WIN_STD_CALL_CONV :ptr GpLineGradient, :ptr GpMatrix
    GdipSetLineTransform proto WIN_STD_CALL_CONV :ptr GpLineGradient, :ptr GDIPCONST
    GdipResetLineTransform proto WIN_STD_CALL_CONV :ptr GpLineGradient
    GdipMultiplyLineTransform proto WIN_STD_CALL_CONV :ptr GpLineGradient, :ptr GDIPCONST, :GpMatrixOrder
    GdipTranslateLineTransform proto WIN_STD_CALL_CONV :ptr GpLineGradient, :REAL, :REAL, :GpMatrixOrder
    GdipScaleLineTransform proto WIN_STD_CALL_CONV :ptr GpLineGradient, :REAL, :REAL, :GpMatrixOrder
    GdipRotateLineTransform proto WIN_STD_CALL_CONV :ptr GpLineGradient, :REAL, :GpMatrixOrder
    GdipCreatePathGradient proto WIN_STD_CALL_CONV :ptr GDIPCONST, :INT_, :GpWrapMode, :ptr ptr GpPathGradient
    GdipCreatePathGradientI proto WIN_STD_CALL_CONV :ptr GDIPCONST, :INT_, :GpWrapMode, :ptr ptr GpPathGradient
    GdipCreatePathGradientFromPath proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr ptr GpPathGradient
    GdipGetPathGradientCenterColor proto WIN_STD_CALL_CONV :ptr GpPathGradient, :ptr ARGB
    GdipSetPathGradientCenterColor proto WIN_STD_CALL_CONV :ptr GpPathGradient, :ARGB
    GdipGetPathGradientSurroundColorsWithCount proto WIN_STD_CALL_CONV :ptr GpPathGradient, :ptr ARGB, :ptr INT_
    GdipSetPathGradientSurroundColorsWithCount proto WIN_STD_CALL_CONV :ptr GpPathGradient, :ptr GDIPCONST, :ptr INT_
    GdipGetPathGradientPath proto WIN_STD_CALL_CONV :ptr GpPathGradient, :ptr GpPath
    GdipSetPathGradientPath proto WIN_STD_CALL_CONV :ptr GpPathGradient, :ptr GDIPCONST
    GdipGetPathGradientCenterPoint proto WIN_STD_CALL_CONV :ptr GpPathGradient, :ptr GpPointF
    GdipGetPathGradientCenterPointI proto WIN_STD_CALL_CONV :ptr GpPathGradient, :ptr GpPoint
    GdipSetPathGradientCenterPoint proto WIN_STD_CALL_CONV :ptr GpPathGradient, :ptr GDIPCONST
    GdipSetPathGradientCenterPointI proto WIN_STD_CALL_CONV :ptr GpPathGradient, :ptr GDIPCONST
    GdipGetPathGradientRect proto WIN_STD_CALL_CONV :ptr GpPathGradient, :ptr GpRectF
    GdipGetPathGradientRectI proto WIN_STD_CALL_CONV :ptr GpPathGradient, :ptr GpRect
    GdipGetPathGradientPointCount proto WIN_STD_CALL_CONV :ptr GpPathGradient, :ptr INT_
    GdipGetPathGradientSurroundColorCount proto WIN_STD_CALL_CONV :ptr GpPathGradient, :ptr INT_
    GdipSetPathGradientGammaCorrection proto WIN_STD_CALL_CONV :ptr GpPathGradient, :BOOL
    GdipGetPathGradientGammaCorrection proto WIN_STD_CALL_CONV :ptr GpPathGradient, :ptr BOOL
    GdipGetPathGradientBlendCount proto WIN_STD_CALL_CONV :ptr GpPathGradient, :ptr INT_
    GdipGetPathGradientBlend proto WIN_STD_CALL_CONV :ptr GpPathGradient, :ptr REAL, :ptr REAL, :INT_
    GdipSetPathGradientBlend proto WIN_STD_CALL_CONV :ptr GpPathGradient, :ptr GDIPCONST, :ptr GDIPCONST, :INT_
    GdipGetPathGradientPresetBlendCount proto WIN_STD_CALL_CONV :ptr GpPathGradient, :ptr INT_
    GdipGetPathGradientPresetBlend proto WIN_STD_CALL_CONV :ptr GpPathGradient, :ptr ARGB, :ptr REAL, :INT_
    GdipSetPathGradientPresetBlend proto WIN_STD_CALL_CONV :ptr GpPathGradient, :ptr GDIPCONST, :ptr GDIPCONST, :INT_
    GdipSetPathGradientSigmaBlend proto WIN_STD_CALL_CONV :ptr GpPathGradient, :REAL, :REAL
    GdipSetPathGradientLinearBlend proto WIN_STD_CALL_CONV :ptr GpPathGradient, :REAL, :REAL
    GdipGetPathGradientWrapMode proto WIN_STD_CALL_CONV :ptr GpPathGradient, :ptr GpWrapMode
    GdipSetPathGradientWrapMode proto WIN_STD_CALL_CONV :ptr GpPathGradient, :GpWrapMode
    GdipGetPathGradientTransform proto WIN_STD_CALL_CONV :ptr GpPathGradient, :ptr GpMatrix
    GdipSetPathGradientTransform proto WIN_STD_CALL_CONV :ptr GpPathGradient, :ptr GpMatrix
    GdipResetPathGradientTransform proto WIN_STD_CALL_CONV :ptr GpPathGradient
    GdipMultiplyPathGradientTransform proto WIN_STD_CALL_CONV :ptr GpPathGradient, :ptr GDIPCONST, :GpMatrixOrder
    GdipTranslatePathGradientTransform proto WIN_STD_CALL_CONV :ptr GpPathGradient, :REAL, :REAL, :GpMatrixOrder
    GdipScalePathGradientTransform proto WIN_STD_CALL_CONV :ptr GpPathGradient, :REAL, :REAL, :GpMatrixOrder
    GdipRotatePathGradientTransform proto WIN_STD_CALL_CONV :ptr GpPathGradient, :REAL, :GpMatrixOrder
    GdipGetPathGradientFocusScales proto WIN_STD_CALL_CONV :ptr GpPathGradient, :ptr REAL, :ptr REAL
    GdipSetPathGradientFocusScales proto WIN_STD_CALL_CONV :ptr GpPathGradient, :REAL, :REAL
    GdipCreatePen1 proto WIN_STD_CALL_CONV :ARGB, :REAL, :GpUnit, :ptr ptr GpPen
    GdipCreatePen2 proto WIN_STD_CALL_CONV :ptr GpBrush, :REAL, :GpUnit, :ptr ptr GpPen
    GdipClonePen proto WIN_STD_CALL_CONV :ptr GpPen, :ptr ptr GpPen
    GdipDeletePen proto WIN_STD_CALL_CONV :ptr GpPen
    GdipSetPenWidth proto WIN_STD_CALL_CONV :ptr GpPen, :REAL
    GdipGetPenWidth proto WIN_STD_CALL_CONV :ptr GpPen, :ptr REAL
    GdipSetPenUnit proto WIN_STD_CALL_CONV :ptr GpPen, :GpUnit
    GdipGetPenUnit proto WIN_STD_CALL_CONV :ptr GpPen, :ptr GpUnit
    GdipSetPenLineCap197819 proto WIN_STD_CALL_CONV :ptr GpPen, :GpLineCap, :GpLineCap, :GpDashCap
    GdipSetPenStartCap proto WIN_STD_CALL_CONV :ptr GpPen, :GpLineCap
    GdipSetPenEndCap proto WIN_STD_CALL_CONV :ptr GpPen, :GpLineCap
    GdipSetPenDashCap197819 proto WIN_STD_CALL_CONV :ptr GpPen, :GpDashCap
    GdipGetPenStartCap proto WIN_STD_CALL_CONV :ptr GpPen, :ptr GpLineCap
    GdipGetPenEndCap proto WIN_STD_CALL_CONV :ptr GpPen, :ptr GpLineCap
    GdipGetPenDashCap197819 proto WIN_STD_CALL_CONV :ptr GpPen, :ptr GpDashCap
    GdipSetPenLineJoin proto WIN_STD_CALL_CONV :ptr GpPen, :GpLineJoin
    GdipGetPenLineJoin proto WIN_STD_CALL_CONV :ptr GpPen, :ptr GpLineJoin
    GdipSetPenCustomStartCap proto WIN_STD_CALL_CONV :ptr GpPen, :ptr GpCustomLineCap
    GdipGetPenCustomStartCap proto WIN_STD_CALL_CONV :ptr GpPen, :ptr ptr GpCustomLineCap
    GdipSetPenCustomEndCap proto WIN_STD_CALL_CONV :ptr GpPen, :ptr GpCustomLineCap
    GdipGetPenCustomEndCap proto WIN_STD_CALL_CONV :ptr GpPen, :ptr ptr GpCustomLineCap
    GdipSetPenMiterLimit proto WIN_STD_CALL_CONV :ptr GpPen, :REAL
    GdipGetPenMiterLimit proto WIN_STD_CALL_CONV :ptr GpPen, :ptr REAL
    GdipSetPenMode proto WIN_STD_CALL_CONV :ptr GpPen, :GpPenAlignment
    GdipGetPenMode proto WIN_STD_CALL_CONV :ptr GpPen, :ptr GpPenAlignment
    GdipSetPenTransform proto WIN_STD_CALL_CONV :ptr GpPen, :ptr GpMatrix
    GdipGetPenTransform proto WIN_STD_CALL_CONV :ptr GpPen, :ptr GpMatrix
    GdipResetPenTransform proto WIN_STD_CALL_CONV :ptr GpPen
    GdipMultiplyPenTransform proto WIN_STD_CALL_CONV :ptr GpPen, :ptr GDIPCONST, :GpMatrixOrder
    GdipTranslatePenTransform proto WIN_STD_CALL_CONV :ptr GpPen, :REAL, :REAL, :GpMatrixOrder
    GdipScalePenTransform proto WIN_STD_CALL_CONV :ptr GpPen, :REAL, :REAL, :GpMatrixOrder
    GdipRotatePenTransform proto WIN_STD_CALL_CONV :ptr GpPen, :REAL, :GpMatrixOrder
    GdipSetPenColor proto WIN_STD_CALL_CONV :ptr GpPen, :ARGB
    GdipGetPenColor proto WIN_STD_CALL_CONV :ptr GpPen, :ptr ARGB
    GdipSetPenBrushFill proto WIN_STD_CALL_CONV :ptr GpPen, :ptr GpBrush
    GdipGetPenBrushFill proto WIN_STD_CALL_CONV :ptr GpPen, :ptr ptr GpBrush
    GdipGetPenFillType proto WIN_STD_CALL_CONV :ptr GpPen, :ptr GpPenType
    GdipGetPenDashStyle proto WIN_STD_CALL_CONV :ptr GpPen, :ptr GpDashStyle
    GdipSetPenDashStyle proto WIN_STD_CALL_CONV :ptr GpPen, :GpDashStyle
    GdipGetPenDashOffset proto WIN_STD_CALL_CONV :ptr GpPen, :ptr REAL
    GdipSetPenDashOffset proto WIN_STD_CALL_CONV :ptr GpPen, :REAL
    GdipGetPenDashCount proto WIN_STD_CALL_CONV :ptr GpPen, :ptr INT_
    GdipSetPenDashArray proto WIN_STD_CALL_CONV :ptr GpPen, :ptr GDIPCONST, :INT_
    GdipGetPenDashArray proto WIN_STD_CALL_CONV :ptr GpPen, :ptr REAL, :INT_
    GdipGetPenCompoundCount proto WIN_STD_CALL_CONV :ptr GpPen, :ptr INT_
    GdipSetPenCompoundArray proto WIN_STD_CALL_CONV :ptr GpPen, :ptr GDIPCONST, :INT_
    GdipGetPenCompoundArray proto WIN_STD_CALL_CONV :ptr GpPen, :ptr REAL, :INT_
    GdipCreateCustomLineCap proto WIN_STD_CALL_CONV :ptr GpPath, :ptr GpPath, :GpLineCap, :REAL, :ptr ptr GpCustomLineCap
    GdipDeleteCustomLineCap proto WIN_STD_CALL_CONV :ptr GpCustomLineCap
    GdipCloneCustomLineCap proto WIN_STD_CALL_CONV :ptr GpCustomLineCap, :ptr ptr GpCustomLineCap
    GdipGetCustomLineCapType proto WIN_STD_CALL_CONV :ptr GpCustomLineCap, :ptr CustomLineCapType
    GdipSetCustomLineCapStrokeCaps proto WIN_STD_CALL_CONV :ptr GpCustomLineCap, :GpLineCap, :GpLineCap
    GdipGetCustomLineCapStrokeCaps proto WIN_STD_CALL_CONV :ptr GpCustomLineCap, :ptr GpLineCap, :ptr GpLineCap
    GdipSetCustomLineCapStrokeJoin proto WIN_STD_CALL_CONV :ptr GpCustomLineCap, :GpLineJoin
    GdipGetCustomLineCapStrokeJoin proto WIN_STD_CALL_CONV :ptr GpCustomLineCap, :ptr GpLineJoin
    GdipSetCustomLineCapBaseCap proto WIN_STD_CALL_CONV :ptr GpCustomLineCap, :GpLineCap
    GdipGetCustomLineCapBaseCap proto WIN_STD_CALL_CONV :ptr GpCustomLineCap, :ptr GpLineCap
    GdipSetCustomLineCapBaseInset proto WIN_STD_CALL_CONV :ptr GpCustomLineCap, :REAL
    GdipGetCustomLineCapBaseInset proto WIN_STD_CALL_CONV :ptr GpCustomLineCap, :ptr REAL
    GdipSetCustomLineCapWidthScale proto WIN_STD_CALL_CONV :ptr GpCustomLineCap, :REAL
    GdipGetCustomLineCapWidthScale proto WIN_STD_CALL_CONV :ptr GpCustomLineCap, :ptr REAL
    GdipCreateAdjustableArrowCap proto WIN_STD_CALL_CONV :REAL, :REAL, :BOOL, :ptr ptr GpAdjustableArrowCap
    GdipSetAdjustableArrowCapHeight proto WIN_STD_CALL_CONV :ptr GpAdjustableArrowCap, :REAL
    GdipGetAdjustableArrowCapHeight proto WIN_STD_CALL_CONV :ptr GpAdjustableArrowCap, :ptr REAL
    GdipSetAdjustableArrowCapWidth proto WIN_STD_CALL_CONV :ptr GpAdjustableArrowCap, :REAL
    GdipGetAdjustableArrowCapWidth proto WIN_STD_CALL_CONV :ptr GpAdjustableArrowCap, :ptr REAL
    GdipSetAdjustableArrowCapMiddleInset proto WIN_STD_CALL_CONV :ptr GpAdjustableArrowCap, :REAL
    GdipGetAdjustableArrowCapMiddleInset proto WIN_STD_CALL_CONV :ptr GpAdjustableArrowCap, :ptr REAL
    GdipSetAdjustableArrowCapFillState proto WIN_STD_CALL_CONV :ptr GpAdjustableArrowCap, :BOOL
    GdipGetAdjustableArrowCapFillState proto WIN_STD_CALL_CONV :ptr GpAdjustableArrowCap, :ptr BOOL
    GdipLoadImageFromStream proto WIN_STD_CALL_CONV :ptr IStream, :ptr ptr GpImage
    GdipLoadImageFromFile proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr ptr GpImage
    GdipLoadImageFromStreamICM proto WIN_STD_CALL_CONV :ptr IStream, :ptr ptr GpImage
    GdipLoadImageFromFileICM proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr ptr GpImage
    GdipCloneImage proto WIN_STD_CALL_CONV :ptr GpImage, :ptr ptr GpImage
    GdipDisposeImage proto WIN_STD_CALL_CONV :ptr GpImage
    GdipSaveImageToFile proto WIN_STD_CALL_CONV :ptr GpImage, :ptr GDIPCONST, :ptr GDIPCONST, :ptr GDIPCONST
    GdipSaveImageToStream proto WIN_STD_CALL_CONV :ptr GpImage, :ptr IStream, :ptr GDIPCONST, :ptr GDIPCONST
    GdipSaveAdd proto WIN_STD_CALL_CONV :ptr GpImage, :ptr GDIPCONST
    GdipSaveAddImage proto WIN_STD_CALL_CONV :ptr GpImage, :ptr GpImage, :ptr GDIPCONST
    GdipGetImageGraphicsContext proto WIN_STD_CALL_CONV :ptr GpImage, :ptr ptr GpGraphics
    GdipGetImageBounds proto WIN_STD_CALL_CONV :ptr GpImage, :ptr GpRectF, :ptr GpUnit
    GdipGetImageDimension proto WIN_STD_CALL_CONV :ptr GpImage, :ptr REAL, :ptr REAL
    GdipGetImageType proto WIN_STD_CALL_CONV :ptr GpImage, :ptr ImageType
    GdipGetImageWidth proto WIN_STD_CALL_CONV :ptr GpImage, :ptr UINT
    GdipGetImageHeight proto WIN_STD_CALL_CONV :ptr GpImage, :ptr UINT
    GdipGetImageHorizontalResolution proto WIN_STD_CALL_CONV :ptr GpImage, :ptr REAL
    GdipGetImageVerticalResolution proto WIN_STD_CALL_CONV :ptr GpImage, :ptr REAL
    GdipGetImageFlags proto WIN_STD_CALL_CONV :ptr GpImage, :ptr UINT
    GdipGetImageRawFormat proto WIN_STD_CALL_CONV :ptr GpImage, :ptr GUID
    GdipGetImagePixelFormat proto WIN_STD_CALL_CONV :ptr GpImage, :ptr PixelFormat
    GdipGetImageThumbnail proto WIN_STD_CALL_CONV :ptr GpImage, :UINT, :UINT, :ptr ptr GpImage, :GetThumbnailImageAbort, :ptr VOID
    GdipGetEncoderParameterListSize proto WIN_STD_CALL_CONV :ptr GpImage, :ptr GDIPCONST, :ptr UINT
    GdipGetEncoderParameterList proto WIN_STD_CALL_CONV :ptr GpImage, :ptr GDIPCONST, :UINT, :ptr EncoderParameters
    GdipImageGetFrameDimensionsCount proto WIN_STD_CALL_CONV :ptr GpImage, :ptr UINT
    GdipImageGetFrameDimensionsList proto WIN_STD_CALL_CONV :ptr GpImage, :ptr GUID, :UINT
    GdipImageGetFrameCount proto WIN_STD_CALL_CONV :ptr GpImage, :ptr GDIPCONST, :ptr UINT
    GdipImageSelectActiveFrame proto WIN_STD_CALL_CONV :ptr GpImage, :ptr GDIPCONST, :UINT
    GdipImageRotateFlip proto WIN_STD_CALL_CONV :ptr GpImage, :RotateFlipType
    GdipGetImagePalette proto WIN_STD_CALL_CONV :ptr GpImage, :ptr ColorPalette, :size_
    GdipSetImagePalette proto WIN_STD_CALL_CONV :ptr GpImage, :ptr GDIPCONST
    GdipGetImagePaletteSize proto WIN_STD_CALL_CONV :ptr GpImage, :ptr size_
    GdipGetPropertyCount proto WIN_STD_CALL_CONV :ptr GpImage, :ptr UINT
    GdipGetPropertyIdList proto WIN_STD_CALL_CONV :ptr GpImage, :UINT, :ptr PROPID
    GdipGetPropertyItemSize proto WIN_STD_CALL_CONV :ptr GpImage, :PROPID, :ptr UINT
    GdipGetPropertyItem proto WIN_STD_CALL_CONV :ptr GpImage, :PROPID, :UINT, :ptr PropertyItem
    GdipGetPropertySize proto WIN_STD_CALL_CONV :ptr GpImage, :ptr UINT, :ptr UINT
    GdipGetAllPropertyItems proto WIN_STD_CALL_CONV :ptr GpImage, :UINT, :UINT, :ptr PropertyItem
    GdipRemovePropertyItem proto WIN_STD_CALL_CONV :ptr GpImage, :PROPID
    GdipSetPropertyItem proto WIN_STD_CALL_CONV :ptr GpImage, :ptr GDIPCONST
    if (GDIPVER ge 0110h)
      GdipFindFirstImageItem proto WIN_STD_CALL_CONV :ptr GpImage, :ptr ImageItemData
      GdipFindNextImageItem proto WIN_STD_CALL_CONV :ptr GpImage, :ptr ImageItemData
      GdipGetImageItemData proto WIN_STD_CALL_CONV :ptr GpImage, :ptr ImageItemData
    endif
    GdipImageForceValidation proto WIN_STD_CALL_CONV :ptr GpImage
    GdipCreateBitmapFromStream proto WIN_STD_CALL_CONV :ptr IStream, :ptr ptr GpBitmap
    GdipCreateBitmapFromFile proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr ptr GpBitmap
    GdipCreateBitmapFromStreamICM proto WIN_STD_CALL_CONV :ptr IStream, :ptr ptr GpBitmap
    GdipCreateBitmapFromFileICM proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr ptr GpBitmap
    GdipCreateBitmapFromScan0 proto WIN_STD_CALL_CONV :width_, :INT_, :INT_, :PixelFormat, :ptr BYTE, :ptr ptr GpBitmap
    GdipCreateBitmapFromGraphics proto WIN_STD_CALL_CONV :width_, :INT_, :ptr GpGraphics, :ptr ptr GpBitmap
    GdipCreateBitmapFromDirectDrawSurface proto WIN_STD_CALL_CONV :ptr IDirectDrawSurface7, :ptr ptr GpBitmap
    GdipCreateBitmapFromGdiDib proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr VOID, :ptr ptr GpBitmap
    GdipCreateBitmapFromHBITMAP proto WIN_STD_CALL_CONV :HBITMAP, :HPALETTE, :ptr ptr GpBitmap
    GdipCreateHBITMAPFromBitmap proto WIN_STD_CALL_CONV :ptr GpBitmap, :ptr HBITMAP, :ARGB
    GdipCreateBitmapFromHICON proto WIN_STD_CALL_CONV :HICON, :ptr ptr GpBitmap
    GdipCreateHICONFromBitmap proto WIN_STD_CALL_CONV :ptr GpBitmap, :ptr HICON
    GdipCreateBitmapFromResource proto WIN_STD_CALL_CONV :HINSTANCE, :ptr GDIPCONST, :ptr ptr GpBitmap
    GdipCloneBitmapArea proto WIN_STD_CALL_CONV :REAL, :REAL, :REAL, :REAL, :PixelFormat, :ptr GpBitmap, :ptr ptr GpBitmap
    GdipCloneBitmapAreaI proto WIN_STD_CALL_CONV :INT_, :INT_, :width_, :INT_, :PixelFormat, :ptr GpBitmap, :ptr ptr GpBitmap
    GdipBitmapLockBits proto WIN_STD_CALL_CONV :ptr GpBitmap, :ptr GDIPCONST, :UINT, :PixelFormat, :ptr BitmapData
    GdipBitmapUnlockBits proto WIN_STD_CALL_CONV :ptr GpBitmap, :ptr BitmapData
    GdipBitmapGetPixel proto WIN_STD_CALL_CONV :ptr GpBitmap, :INT_, :INT_, :ptr ARGB
    GdipBitmapSetPixel proto WIN_STD_CALL_CONV :ptr GpBitmap, :INT_, :INT_, :ARGB
    if (GDIPVER ge 0110h)
      GdipImageSetAbort proto WIN_STD_CALL_CONV :ptr GpImage, :ptr GdiplusAbort
      GdipGraphicsSetAbort proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GdiplusAbort
      GdipBitmapConvertFormat proto WIN_STD_CALL_CONV :ptr GpBitmap, :PixelFormat, :DitherType, :PaletteType, :ptr ColorPalette, :REAL
      GdipInitializePalette proto WIN_STD_CALL_CONV :ptr ColorPalette, :PaletteType, :INT_, :BOOL, :ptr GpBitmap
      GdipBitmapApplyEffect proto WIN_STD_CALL_CONV :ptr GpBitmap, :ptr CGpEffect, :ptr RECT, :BOOL, :ptr ptr VOID, :ptr INT_
      GdipBitmapCreateApplyEffect proto WIN_STD_CALL_CONV :ptr ptr GpBitmap, :INT_, :ptr CGpEffect, :ptr RECT, :ptr RECT, :ptr ptr GpBitmap, :BOOL, :ptr ptr VOID, :ptr INT_
      GdipBitmapGetHistogram proto WIN_STD_CALL_CONV :ptr GpBitmap, :HistogramFormat, :UINT, :ptr UINT, :ptr UINT, :ptr UINT, :ptr UINT
      GdipBitmapGetHistogramSize proto WIN_STD_CALL_CONV :HistogramFormat, :ptr UINT
    endif
    GdipBitmapSetResolution proto WIN_STD_CALL_CONV :ptr GpBitmap, :REAL, :REAL
    GdipCreateImageAttributes proto WIN_STD_CALL_CONV :ptr ptr GpImageAttributes
    GdipCloneImageAttributes proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr ptr GpImageAttributes
    GdipDisposeImageAttributes proto WIN_STD_CALL_CONV :ptr GpImageAttributes
    GdipSetImageAttributesToIdentity proto WIN_STD_CALL_CONV :ptr GpImageAttributes, :ColorAdjustType
    GdipResetImageAttributes proto WIN_STD_CALL_CONV :ptr GpImageAttributes, :ColorAdjustType
    GdipSetImageAttributesColorMatrix proto WIN_STD_CALL_CONV :ptr GpImageAttributes, :ColorAdjustType, :BOOL, :ptr GDIPCONST, :ptr GDIPCONST, :ColorMatrixFlags
    GdipSetImageAttributesThreshold proto WIN_STD_CALL_CONV :ptr GpImageAttributes, :ColorAdjustType, :BOOL, :REAL
    GdipSetImageAttributesGamma proto WIN_STD_CALL_CONV :ptr GpImageAttributes, :ColorAdjustType, :BOOL, :REAL
    GdipSetImageAttributesNoOp proto WIN_STD_CALL_CONV :ptr GpImageAttributes, :ColorAdjustType, :BOOL
    GdipSetImageAttributesColorKeys proto WIN_STD_CALL_CONV :ptr GpImageAttributes, :ColorAdjustType, :BOOL, :ARGB, :ARGB
    GdipSetImageAttributesOutputChannel proto WIN_STD_CALL_CONV :ptr GpImageAttributes, :ColorAdjustType, :BOOL, :ColorChannelFlags
    GdipSetImageAttributesOutputChannelColorProfile proto WIN_STD_CALL_CONV :ptr GpImageAttributes, :ColorAdjustType, :BOOL, :ptr GDIPCONST
    GdipSetImageAttributesRemapTable proto WIN_STD_CALL_CONV :ptr GpImageAttributes, :ColorAdjustType, :BOOL, :UINT, :ptr GDIPCONST
    GdipSetImageAttributesWrapMode proto WIN_STD_CALL_CONV :ptr GpImageAttributes, :WrapMode, :ARGB, :BOOL
    GdipSetImageAttributesICMMode proto WIN_STD_CALL_CONV :ptr GpImageAttributes, :BOOL
    GdipGetImageAttributesAdjustedPalette proto WIN_STD_CALL_CONV :ptr GpImageAttributes, :ptr ColorPalette, :ColorAdjustType
    GdipFlush proto WIN_STD_CALL_CONV :ptr GpGraphics, :GpFlushIntention
    GdipCreateFromHDC proto WIN_STD_CALL_CONV :HDC, :ptr ptr GpGraphics
    GdipCreateFromHDC2 proto WIN_STD_CALL_CONV :HDC, :HANDLE, :ptr ptr GpGraphics
    GdipCreateFromHWND proto WIN_STD_CALL_CONV :HWND, :ptr ptr GpGraphics
    GdipCreateFromHWNDICM proto WIN_STD_CALL_CONV :HWND, :ptr ptr GpGraphics
    GdipDeleteGraphics proto WIN_STD_CALL_CONV :ptr GpGraphics
    GdipGetDC proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr HDC
    GdipReleaseDC proto WIN_STD_CALL_CONV :ptr GpGraphics, :HDC
    GdipSetCompositingMode proto WIN_STD_CALL_CONV :ptr GpGraphics, :CompositingMode
    GdipGetCompositingMode proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr CompositingMode
    GdipSetRenderingOrigin proto WIN_STD_CALL_CONV :ptr GpGraphics, :INT_, :INT_
    GdipGetRenderingOrigin proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr INT_, :ptr INT_
    GdipSetCompositingQuality proto WIN_STD_CALL_CONV :ptr GpGraphics, :CompositingQuality
    GdipGetCompositingQuality proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr CompositingQuality
    GdipSetSmoothingMode proto WIN_STD_CALL_CONV :ptr GpGraphics, :SmoothingMode
    GdipGetSmoothingMode proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr SmoothingMode
    GdipSetPixelOffsetMode proto WIN_STD_CALL_CONV :ptr GpGraphics, :PixelOffsetMode
    GdipGetPixelOffsetMode proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr PixelOffsetMode
    GdipSetTextRenderingHint proto WIN_STD_CALL_CONV :ptr GpGraphics, :TextRenderingHint
    GdipGetTextRenderingHint proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr TextRenderingHint
    GdipSetTextContrast proto WIN_STD_CALL_CONV :ptr GpGraphics, :UINT
    GdipGetTextContrast proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr UINT
    GdipSetInterpolationMode proto WIN_STD_CALL_CONV :ptr GpGraphics, :InterpolationMode
    GdipGetInterpolationMode proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr InterpolationMode
    GdipSetWorldTransform proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpMatrix
    GdipResetWorldTransform proto WIN_STD_CALL_CONV :ptr GpGraphics
    GdipMultiplyWorldTransform proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GDIPCONST, :GpMatrixOrder
    GdipTranslateWorldTransform proto WIN_STD_CALL_CONV :ptr GpGraphics, :REAL, :REAL, :GpMatrixOrder
    GdipScaleWorldTransform proto WIN_STD_CALL_CONV :ptr GpGraphics, :REAL, :REAL, :GpMatrixOrder
    GdipRotateWorldTransform proto WIN_STD_CALL_CONV :ptr GpGraphics, :REAL, :GpMatrixOrder
    GdipGetWorldTransform proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpMatrix
    GdipResetPageTransform proto WIN_STD_CALL_CONV :ptr GpGraphics
    GdipGetPageUnit proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpUnit
    GdipGetPageScale proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr REAL
    GdipSetPageUnit proto WIN_STD_CALL_CONV :ptr GpGraphics, :GpUnit
    GdipSetPageScale proto WIN_STD_CALL_CONV :ptr GpGraphics, :REAL
    GdipGetDpiX proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr REAL
    GdipGetDpiY proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr REAL
    GdipTransformPoints proto WIN_STD_CALL_CONV :ptr GpGraphics, :GpCoordinateSpace, :GpCoordinateSpace, :ptr GpPointF, :INT_
    GdipTransformPointsI proto WIN_STD_CALL_CONV :ptr GpGraphics, :GpCoordinateSpace, :GpCoordinateSpace, :ptr GpPoint, :INT_
    GdipGetNearestColor proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr ARGB
    GdipCreateHalftonePalette proto WIN_STD_CALL_CONV
    GdipDrawLine proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpPen, :REAL, :REAL, :REAL, :REAL
    GdipDrawLineI proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpPen, :INT_, :INT_, :INT_, :INT_
    GdipDrawLines proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpPen, :ptr GDIPCONST, :INT_
    GdipDrawLinesI proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpPen, :ptr GDIPCONST, :INT_
    GdipDrawArc proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpPen, :REAL, :REAL, :REAL, :REAL, :REAL, :REAL
    GdipDrawArcI proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpPen, :INT_, :INT_, :width_, :INT_, :REAL, :REAL
    GdipDrawBezier proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpPen, :REAL, :REAL, :REAL, :REAL, :REAL, :REAL, :REAL, :REAL
    GdipDrawBezierI proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpPen, :INT_, :INT_, :INT_, :INT_, :INT_, :INT_, :INT_, :INT_
    GdipDrawBeziers proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpPen, :ptr GDIPCONST, :INT_
    GdipDrawBeziersI proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpPen, :ptr GDIPCONST, :INT_
    GdipDrawRectangle proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpPen, :REAL, :REAL, :REAL, :REAL
    GdipDrawRectangleI proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpPen, :INT_, :INT_, :width_, :INT_
    GdipDrawRectangles proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpPen, :ptr GDIPCONST, :INT_
    GdipDrawRectanglesI proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpPen, :ptr GDIPCONST, :INT_
    GdipDrawEllipse proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpPen, :REAL, :REAL, :REAL, :REAL
    GdipDrawEllipseI proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpPen, :INT_, :INT_, :width_, :INT_
    GdipDrawPie proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpPen, :REAL, :REAL, :REAL, :REAL, :REAL, :REAL
    GdipDrawPieI proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpPen, :INT_, :INT_, :width_, :INT_, :REAL, :REAL
    GdipDrawPolygon proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpPen, :ptr GDIPCONST, :INT_
    GdipDrawPolygonI proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpPen, :ptr GDIPCONST, :INT_
    GdipDrawPath proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpPen, :ptr GpPath
    GdipDrawCurve proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpPen, :ptr GDIPCONST, :INT_
    GdipDrawCurveI proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpPen, :ptr GDIPCONST, :INT_
    GdipDrawCurve2 proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpPen, :ptr GDIPCONST, :INT_, :REAL
    GdipDrawCurve2I proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpPen, :ptr GDIPCONST, :INT_, :REAL
    GdipDrawCurve3 proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpPen, :ptr GDIPCONST, :INT_, :offset_, :INT_, :REAL
    GdipDrawCurve3I proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpPen, :ptr GDIPCONST, :INT_, :offset_, :INT_, :REAL
    GdipDrawClosedCurve proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpPen, :ptr GDIPCONST, :INT_
    GdipDrawClosedCurveI proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpPen, :ptr GDIPCONST, :INT_
    GdipDrawClosedCurve2 proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpPen, :ptr GDIPCONST, :INT_, :REAL
    GdipDrawClosedCurve2I proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpPen, :ptr GDIPCONST, :INT_, :REAL
    GdipGraphicsClear proto WIN_STD_CALL_CONV :ptr GpGraphics, :ARGB
    GdipFillRectangle proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpBrush, :REAL, :REAL, :REAL, :REAL
    GdipFillRectangleI proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpBrush, :INT_, :INT_, :width_, :INT_
    GdipFillRectangles proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpBrush, :ptr GDIPCONST, :INT_
    GdipFillRectanglesI proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpBrush, :ptr GDIPCONST, :INT_
    GdipFillPolygon proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpBrush, :ptr GDIPCONST, :INT_, :GpFillMode
    GdipFillPolygonI proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpBrush, :ptr GDIPCONST, :INT_, :GpFillMode
    GdipFillPolygon2 proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpBrush, :ptr GDIPCONST, :INT_
    GdipFillPolygon2I proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpBrush, :ptr GDIPCONST, :INT_
    GdipFillEllipse proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpBrush, :REAL, :REAL, :REAL, :REAL
    GdipFillEllipseI proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpBrush, :INT_, :INT_, :width_, :INT_
    GdipFillPie proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpBrush, :REAL, :REAL, :REAL, :REAL, :REAL, :REAL
    GdipFillPieI proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpBrush, :INT_, :INT_, :width_, :INT_, :REAL, :REAL
    GdipFillPath proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpBrush, :ptr GpPath
    GdipFillClosedCurve proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpBrush, :ptr GDIPCONST, :INT_
    GdipFillClosedCurveI proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpBrush, :ptr GDIPCONST, :INT_
    GdipFillClosedCurve2 proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpBrush, :ptr GDIPCONST, :INT_, :REAL, :GpFillMode
    GdipFillClosedCurve2I proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpBrush, :ptr GDIPCONST, :INT_, :REAL, :GpFillMode
    GdipFillRegion proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpBrush, :ptr GpRegion
    if (GDIPVER ge 0110h)
      GdipDrawImageFX proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpImage, :ptr GpRectF, :ptr GpMatrix, :ptr CGpEffect, :ptr GpImageAttributes, :GpUnit
    endif
    GdipDrawImage proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpImage, :REAL, :REAL
    GdipDrawImageI proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpImage, :INT_, :INT_
    GdipDrawImageRect proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpImage, :REAL, :REAL, :REAL, :REAL
    GdipDrawImageRectI proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpImage, :INT_, :INT_, :width_, :INT_
    GdipDrawImagePoints proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpImage, :ptr GDIPCONST, :INT_
    GdipDrawImagePointsI proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpImage, :ptr GDIPCONST, :INT_
    GdipDrawImagePointRect proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpImage, :REAL, :REAL, :REAL, :REAL, :REAL, :REAL, :GpUnit
    GdipDrawImagePointRectI proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpImage, :INT_, :INT_, :INT_, :INT_, :INT_, :INT_, :GpUnit
    GdipDrawImageRectRect proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpImage, :REAL, :REAL, :REAL, :REAL, :REAL, :REAL, :REAL, :REAL, :GpUnit, :ptr GDIPCONST, :DrawImageAbort, :ptr VOID
    GdipDrawImageRectRectI proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpImage, :INT_, :INT_, :INT_, :INT_, :INT_, :INT_, :INT_, :INT_, :GpUnit, :ptr GDIPCONST, :DrawImageAbort, :ptr VOID
    GdipDrawImagePointsRect proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpImage, :ptr GDIPCONST, :INT_, :REAL, :REAL, :REAL, :REAL, :GpUnit, :ptr GDIPCONST, :DrawImageAbort, :ptr VOID
    GdipDrawImagePointsRectI proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpImage, :ptr GDIPCONST, :INT_, :INT_, :INT_, :INT_, :INT_, :GpUnit, :ptr GDIPCONST, :DrawImageAbort, :ptr VOID
    GdipEnumerateMetafileDestPoint proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GDIPCONST, :ptr GDIPCONST, :EnumerateMetafileProc, :ptr VOID, :ptr GDIPCONST
    GdipEnumerateMetafileDestPointI proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GDIPCONST, :ptr GDIPCONST, :EnumerateMetafileProc, :ptr VOID, :ptr GDIPCONST
    GdipEnumerateMetafileDestRect proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GDIPCONST, :ptr GDIPCONST, :EnumerateMetafileProc, :ptr VOID, :ptr GDIPCONST
    GdipEnumerateMetafileDestRectI proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GDIPCONST, :ptr GDIPCONST, :EnumerateMetafileProc, :ptr VOID, :ptr GDIPCONST
    GdipEnumerateMetafileDestPoints proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GDIPCONST, :ptr GDIPCONST, :INT_, :EnumerateMetafileProc, :ptr VOID, :ptr GDIPCONST
    GdipEnumerateMetafileDestPointsI proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GDIPCONST, :ptr GDIPCONST, :INT_, :EnumerateMetafileProc, :ptr VOID, :ptr GDIPCONST
    GdipEnumerateMetafileSrcRectDestPoint proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GDIPCONST, :ptr GDIPCONST, :ptr GDIPCONST, :Unit, :EnumerateMetafileProc, :ptr VOID, :ptr GDIPCONST
    GdipEnumerateMetafileSrcRectDestPointI proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GDIPCONST, :ptr GDIPCONST, :ptr GDIPCONST, :Unit, :EnumerateMetafileProc, :ptr VOID, :ptr GDIPCONST
    GdipEnumerateMetafileSrcRectDestRect proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GDIPCONST, :ptr GDIPCONST, :ptr GDIPCONST, :Unit, :EnumerateMetafileProc, :ptr VOID, :ptr GDIPCONST
    GdipEnumerateMetafileSrcRectDestRectI proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GDIPCONST, :ptr GDIPCONST, :ptr GDIPCONST, :Unit, :EnumerateMetafileProc, :ptr VOID, :ptr GDIPCONST
    GdipEnumerateMetafileSrcRectDestPoints proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GDIPCONST, :ptr GDIPCONST, :INT_, :ptr GDIPCONST, :Unit, :EnumerateMetafileProc, :ptr VOID, :ptr GDIPCONST
    GdipEnumerateMetafileSrcRectDestPointsI proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GDIPCONST, :ptr GDIPCONST, :INT_, :ptr GDIPCONST, :Unit, :EnumerateMetafileProc, :ptr VOID, :ptr GDIPCONST
    GdipPlayMetafileRecord proto WIN_STD_CALL_CONV :ptr GDIPCONST, :EmfPlusRecordType, :UINT, :UINT, :ptr GDIPCONST
    GdipSetClipGraphics proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpGraphics, :CombineMode
    GdipSetClipRect proto WIN_STD_CALL_CONV :ptr GpGraphics, :REAL, :REAL, :REAL, :REAL, :CombineMode
    GdipSetClipRectI proto WIN_STD_CALL_CONV :ptr GpGraphics, :INT_, :INT_, :width_, :INT_, :CombineMode
    GdipSetClipPath proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpPath, :CombineMode
    GdipSetClipRegion proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpRegion, :CombineMode
    GdipSetClipHrgn proto WIN_STD_CALL_CONV :ptr GpGraphics, :HRGN, :CombineMode
    GdipResetClip proto WIN_STD_CALL_CONV :ptr GpGraphics
    GdipTranslateClip proto WIN_STD_CALL_CONV :ptr GpGraphics, :REAL, :REAL
    GdipTranslateClipI proto WIN_STD_CALL_CONV :ptr GpGraphics, :dx_, :INT_
    GdipGetClip proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpRegion
    GdipGetClipBounds proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpRectF
    GdipGetClipBoundsI proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpRect
    GdipIsClipEmpty proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr BOOL
    GdipGetVisibleClipBounds proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpRectF
    GdipGetVisibleClipBoundsI proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpRect
    GdipIsVisibleClipEmpty proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr BOOL
    GdipIsVisiblePoint proto WIN_STD_CALL_CONV :ptr GpGraphics, :REAL, :REAL, :ptr BOOL
    GdipIsVisiblePointI proto WIN_STD_CALL_CONV :ptr GpGraphics, :INT_, :INT_, :ptr BOOL
    GdipIsVisibleRect proto WIN_STD_CALL_CONV :ptr GpGraphics, :REAL, :REAL, :REAL, :REAL, :ptr BOOL
    GdipIsVisibleRectI proto WIN_STD_CALL_CONV :ptr GpGraphics, :INT_, :INT_, :width_, :INT_, :ptr BOOL
    GdipSaveGraphics proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GraphicsState
    GdipRestoreGraphics proto WIN_STD_CALL_CONV :ptr GpGraphics, :GraphicsState
    GdipBeginContainer proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GDIPCONST, :ptr GDIPCONST, :GpUnit, :ptr GraphicsContainer
    GdipBeginContainerI proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GDIPCONST, :ptr GDIPCONST, :GpUnit, :ptr GraphicsContainer
    GdipBeginContainer2 proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GraphicsContainer
    GdipEndContainer proto WIN_STD_CALL_CONV :ptr GpGraphics, :GraphicsContainer
    GdipGetMetafileHeaderFromWmf proto WIN_STD_CALL_CONV :HMETAFILE, :ptr GDIPCONST, :ptr MetafileHeader
    GdipGetMetafileHeaderFromEmf proto WIN_STD_CALL_CONV :HENHMETAFILE, :ptr MetafileHeader
    GdipGetMetafileHeaderFromFile proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr MetafileHeader
    GdipGetMetafileHeaderFromStream proto WIN_STD_CALL_CONV :ptr IStream, :ptr MetafileHeader
    GdipGetMetafileHeaderFromMetafile proto WIN_STD_CALL_CONV :ptr GpMetafile, :ptr MetafileHeader
    GdipGetHemfFromMetafile proto WIN_STD_CALL_CONV :ptr GpMetafile, :ptr HENHMETAFILE
    GdipCreateStreamOnFile proto WIN_STD_CALL_CONV :ptr GDIPCONST, :UINT, :ptr ptr IStream
    GdipCreateMetafileFromWmf proto WIN_STD_CALL_CONV :HMETAFILE, :BOOL, :ptr GDIPCONST, :ptr ptr GpMetafile
    GdipCreateMetafileFromEmf proto WIN_STD_CALL_CONV :HENHMETAFILE, :BOOL, :ptr ptr GpMetafile
    GdipCreateMetafileFromFile proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr ptr GpMetafile
    GdipCreateMetafileFromWmfFile proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr GDIPCONST, :ptr ptr GpMetafile
    GdipCreateMetafileFromStream proto WIN_STD_CALL_CONV :ptr IStream, :ptr ptr GpMetafile
    GdipRecordMetafile proto WIN_STD_CALL_CONV :HDC, :EmfType, :ptr GDIPCONST, :MetafileFrameUnit, :ptr GDIPCONST, :ptr ptr GpMetafile
    GdipRecordMetafileI proto WIN_STD_CALL_CONV :HDC, :EmfType, :ptr GDIPCONST, :MetafileFrameUnit, :ptr GDIPCONST, :ptr ptr GpMetafile
    GdipRecordMetafileFileName proto WIN_STD_CALL_CONV :ptr GDIPCONST, :HDC, :EmfType, :ptr GDIPCONST, :MetafileFrameUnit, :ptr GDIPCONST, :ptr ptr GpMetafile
    GdipRecordMetafileFileNameI proto WIN_STD_CALL_CONV :ptr GDIPCONST, :HDC, :EmfType, :ptr GDIPCONST, :MetafileFrameUnit, :ptr GDIPCONST, :ptr ptr GpMetafile
    GdipRecordMetafileStream proto WIN_STD_CALL_CONV :ptr IStream, :HDC, :EmfType, :ptr GDIPCONST, :MetafileFrameUnit, :ptr GDIPCONST, :ptr ptr GpMetafile
    GdipRecordMetafileStreamI proto WIN_STD_CALL_CONV :ptr IStream, :HDC, :EmfType, :ptr GDIPCONST, :MetafileFrameUnit, :ptr GDIPCONST, :ptr ptr GpMetafile
    GdipSetMetafileDownLevelRasterizationLimit proto WIN_STD_CALL_CONV :ptr GpMetafile, :UINT
    GdipGetMetafileDownLevelRasterizationLimit proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr UINT
    GdipGetImageDecodersSize proto WIN_STD_CALL_CONV :ptr UINT, :ptr UINT
    GdipGetImageDecoders proto WIN_STD_CALL_CONV :UINT, :UINT, :ptr ImageCodecInfo
    GdipGetImageEncodersSize proto WIN_STD_CALL_CONV :ptr UINT, :ptr UINT
    GdipGetImageEncoders proto WIN_STD_CALL_CONV :UINT, :UINT, :ptr ImageCodecInfo
    GdipComment proto WIN_STD_CALL_CONV :ptr GpGraphics, :UINT, :ptr GDIPCONST
    GdipCreateFontFamilyFromName proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr GpFontCollection, :ptr ptr GpFontFamily
    GdipDeleteFontFamily proto WIN_STD_CALL_CONV :ptr GpFontFamily
    GdipCloneFontFamily proto WIN_STD_CALL_CONV :ptr GpFontFamily, :ptr ptr GpFontFamily
    GdipGetGenericFontFamilySansSerif proto WIN_STD_CALL_CONV :ptr ptr GpFontFamily
    GdipGetGenericFontFamilySerif proto WIN_STD_CALL_CONV :ptr ptr GpFontFamily
    GdipGetGenericFontFamilyMonospace proto WIN_STD_CALL_CONV :ptr ptr GpFontFamily
    GdipGetFamilyName proto WIN_STD_CALL_CONV :ptr GDIPCONST, :LPWSTR, :LANGID
    GdipIsStyleAvailable proto WIN_STD_CALL_CONV :ptr GDIPCONST, :INT_, :ptr BOOL
    GdipFontCollectionEnumerable proto WIN_STD_CALL_CONV :ptr GpFontCollection, :ptr GpGraphics, :ptr INT_
    GdipFontCollectionEnumerate proto WIN_STD_CALL_CONV :ptr GpFontCollection, :INT_, :ptr ptr GpFontFamily, :ptr INT_, :ptr GpGraphics
    GdipGetEmHeight proto WIN_STD_CALL_CONV :ptr GDIPCONST, :INT_, :ptr UINT16
    GdipGetCellAscent proto WIN_STD_CALL_CONV :ptr GDIPCONST, :INT_, :ptr UINT16
    GdipGetCellDescent proto WIN_STD_CALL_CONV :ptr GDIPCONST, :INT_, :ptr UINT16
    GdipGetLineSpacing proto WIN_STD_CALL_CONV :ptr GDIPCONST, :INT_, :ptr UINT16
    GdipCreateFontFromDC proto WIN_STD_CALL_CONV :HDC, :ptr ptr GpFont
    GdipCreateFontFromLogfontA proto WIN_STD_CALL_CONV :HDC, :ptr GDIPCONST, :ptr ptr GpFont
    GdipCreateFontFromLogfontW proto WIN_STD_CALL_CONV :HDC, :ptr GDIPCONST, :ptr ptr GpFont
    GdipCreateFont proto WIN_STD_CALL_CONV :ptr GDIPCONST, :REAL, :INT_, :Unit, :ptr ptr GpFont
    GdipCloneFont proto WIN_STD_CALL_CONV :ptr GpFont, :ptr ptr GpFont
    GdipDeleteFont proto WIN_STD_CALL_CONV :ptr GpFont
    GdipGetFamily proto WIN_STD_CALL_CONV :ptr GpFont, :ptr ptr GpFontFamily
    GdipGetFontStyle proto WIN_STD_CALL_CONV :ptr GpFont, :ptr INT_
    GdipGetFontSize proto WIN_STD_CALL_CONV :ptr GpFont, :ptr REAL
    GdipGetFontUnit proto WIN_STD_CALL_CONV :ptr GpFont, :ptr Unit
    GdipGetFontHeight proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr GDIPCONST, :ptr REAL
    GdipGetFontHeightGivenDPI proto WIN_STD_CALL_CONV :ptr GDIPCONST, :REAL, :ptr REAL
    GdipGetLogFontA proto WIN_STD_CALL_CONV :ptr GpFont, :ptr GpGraphics, :ptr LOGFONTA
    GdipGetLogFontW proto WIN_STD_CALL_CONV :ptr GpFont, :ptr GpGraphics, :ptr LOGFONTW
    GdipNewInstalledFontCollection proto WIN_STD_CALL_CONV :ptr ptr GpFontCollection
    GdipNewPrivateFontCollection proto WIN_STD_CALL_CONV :ptr ptr GpFontCollection
    GdipDeletePrivateFontCollection proto WIN_STD_CALL_CONV :ptr ptr GpFontCollection
    GdipGetFontCollectionFamilyCount proto WIN_STD_CALL_CONV :ptr GpFontCollection, :ptr INT_
    GdipGetFontCollectionFamilyList proto WIN_STD_CALL_CONV :ptr GpFontCollection, :INT_, :ptr ptr GpFontFamily, :ptr INT_
    GdipPrivateAddFontFile proto WIN_STD_CALL_CONV :ptr GpFontCollection, :ptr GDIPCONST
    GdipPrivateAddMemoryFont proto WIN_STD_CALL_CONV :ptr GpFontCollection, :ptr GDIPCONST, :length_
    GdipDrawString proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GDIPCONST, :length_, :ptr GDIPCONST, :ptr GDIPCONST, :ptr GDIPCONST, :ptr GDIPCONST
    GdipMeasureString proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GDIPCONST, :length_, :ptr GDIPCONST, :ptr GDIPCONST, :ptr GDIPCONST, :ptr RectF, :ptr INT_, :ptr INT_
    GdipMeasureCharacterRanges proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GDIPCONST, :length_, :ptr GDIPCONST, :ptr GDIPCONST, :ptr GDIPCONST, :INT_, :ptr ptr GpRegion
    GdipDrawDriverString proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GDIPCONST, :length_, :ptr GDIPCONST, :ptr GDIPCONST, :ptr GDIPCONST, :INT_, :ptr GDIPCONST
    GdipMeasureDriverString proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GDIPCONST, :length_, :ptr GDIPCONST, :ptr GDIPCONST, :INT_, :ptr GDIPCONST, :ptr RectF
    GdipCreateStringFormat proto WIN_STD_CALL_CONV :INT_, :LANGID, :ptr ptr GpStringFormat
    GdipStringFormatGetGenericDefault proto WIN_STD_CALL_CONV :ptr ptr GpStringFormat
    GdipStringFormatGetGenericTypographic proto WIN_STD_CALL_CONV :ptr ptr GpStringFormat
    GdipDeleteStringFormat proto WIN_STD_CALL_CONV :ptr GpStringFormat
    GdipCloneStringFormat proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr ptr GpStringFormat
    GdipSetStringFormatFlags proto WIN_STD_CALL_CONV :ptr GpStringFormat, :INT_
    GdipGetStringFormatFlags proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr INT_
    GdipSetStringFormatAlign proto WIN_STD_CALL_CONV :ptr GpStringFormat, :StringAlignment
    GdipGetStringFormatAlign proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr StringAlignment
    GdipSetStringFormatLineAlign proto WIN_STD_CALL_CONV :ptr GpStringFormat, :StringAlignment
    GdipGetStringFormatLineAlign proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr StringAlignment
    GdipSetStringFormatTrimming proto WIN_STD_CALL_CONV :ptr GpStringFormat, :StringTrimming
    GdipGetStringFormatTrimming proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr StringTrimming
    GdipSetStringFormatHotkeyPrefix proto WIN_STD_CALL_CONV :ptr GpStringFormat, :INT_
    GdipGetStringFormatHotkeyPrefix proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr INT_
    GdipSetStringFormatTabStops proto WIN_STD_CALL_CONV :ptr GpStringFormat, :REAL, :INT_, :ptr GDIPCONST
    GdipGetStringFormatTabStops proto WIN_STD_CALL_CONV :ptr GDIPCONST, :INT_, :ptr REAL, :ptr REAL
    GdipGetStringFormatTabStopCount proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr INT_
    GdipSetStringFormatDigitSubstitution proto WIN_STD_CALL_CONV :ptr GpStringFormat, :LANGID, :StringDigitSubstitute
    GdipGetStringFormatDigitSubstitution proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr LANGID, :ptr StringDigitSubstitute
    GdipGetStringFormatMeasurableCharacterRangeCount proto WIN_STD_CALL_CONV :ptr GDIPCONST, :ptr INT_
    GdipSetStringFormatMeasurableCharacterRanges proto WIN_STD_CALL_CONV :ptr GpStringFormat, :INT_, :ptr GDIPCONST
    GdipCreateCachedBitmap proto WIN_STD_CALL_CONV :ptr GpBitmap, :ptr GpGraphics, :ptr ptr GpCachedBitmap
    GdipDeleteCachedBitmap proto WIN_STD_CALL_CONV :ptr GpCachedBitmap
    GdipDrawCachedBitmap proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpCachedBitmap, :INT_, :INT_
    GdipEmfToWmfBits proto WIN_STD_CALL_CONV :HENHMETAFILE, :UINT, :LPBYTE, :INT_, :eFlags_
    GdipSetImageAttributesCachedBackground proto WIN_STD_CALL_CONV :ptr GpImageAttributes, :BOOL
    GdipTestControl proto WIN_STD_CALL_CONV :GpTestControlEnum, :ptr
    GdiplusNotificationHook proto WIN_STD_CALL_CONV :ptr ULONG_PTR
    GdiplusNotificationUnhook proto WIN_STD_CALL_CONV :ULONG_PTR
    if (GDIPVER ge 0110h)
      GdipConvertToEmfPlus proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpMetafile, :ptr INT_, :EmfType, :ptr WCHAR, :ptr ptr GpMetafile
      GdipConvertToEmfPlusToFile proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpMetafile, :ptr INT_, :ptr WCHAR, :EmfType, :ptr WCHAR, :ptr ptr GpMetafile
      GdipConvertToEmfPlusToStream proto WIN_STD_CALL_CONV :ptr GpGraphics, :ptr GpMetafile, :ptr INT_, :ptr IStream, :EmfType, :ptr WCHAR, :ptr ptr GpMetafile
    endif
    ifdef __cplusplus
      ;[...]
    endif
  endif
endif
