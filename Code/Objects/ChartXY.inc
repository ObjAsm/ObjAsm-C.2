; ==================================================================================================
; Title:      ChartXY.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm cluster to support XY-chart objects and their setup.
; Notes:      Version C.1.0, August 2021
;               - First release.
;                 Line clipping is implemented using the Liang-Barsky algorithm.
;                 https://www.skytopia.com/project/articles/compsci/clipping.html
;                 https://arxiv.org/pdf/1908.01350.pdf
;                 To speedup the line rendering, line clipping is implemented using an algorithm
;                 described here https://arxiv.org/pdf/1908.01350.pdf
; ==================================================================================================



;Marker type enumeration
CHTXY_MARKER_SQUARE       equ   0
CHTXY_MARKER_RECT_HOR     equ   1
CHTXY_MARKER_RECT_VER     equ   2
CHTXY_MARKER_CIRCLE       equ   3
CHTXY_MARKER_ELLIPSE_HOR  equ   4
CHTXY_MARKER_ELLIPSE_VER  equ   5
CHTXY_MARKER_RHOMBUS      equ   6
CHTXY_MARKER_RHOMBUS_HOR  equ   7
CHTXY_MARKER_RHOMBUS_VER  equ   8
CHTXY_MARKER_CROSS        equ   9
CHTXY_MARKER_STAR_4       equ   10
CHTXY_MARKER_STAR_8       equ   11

SeriesSetupXY struct
  dLineWidth          DWORD       ?
  dLineStyle          DWORD       ?
  LineColor           COLORREF    ?
  dMarkerSize         DWORD       ?
  dMarkerShape        DWORD       ?
  MarkerFillColor     COLORREF    ?
  MarkerBorderColor   COLORREF    ?
  dMarkerBorderWidth  DWORD       ?
SeriesSetupXY ends

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     ChartXYTabSeries
; Purpose:    Series Tab of ChartSetup.

ifdef INCLUDE_CHART_SETUP_DIALOG
Object ChartXYTabSeries, , ChartTabSeries
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    Init,               POINTER, HWND, $ObjPtr(MaskedImageList)
  RedefineMethod    OnCommand,          WPARAM, LPARAM
  RedefineMethod    OnInitDialog,       WPARAM, LPARAM
  RedefineMethod    Restore

  DefineVariable    LocalSetup,         SeriesSetupXY,    {}
ObjectEnd
endif

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:  ChartXYSeries
; Purpose: Implement a data series for plot usage.
; Note:    - Data must be floating point numbers (REAL4 or REAL8). See CHT_FLOAT.
;          - The generic memory layout is [(x0, y0), (x1, y1), (x2, y2), ...]

Object ChartXYSeries, ChartXYSeriesID, ChartSeries
  RedefineMethod    Draw,               HDC
  VirtualMethod     DrawMarkerAt,       HDC, SDWORD, SDWORD
  ifdef INCLUDE_CHART_SETUP_DIALOG
    RedefineMethod    GetSetupDialogTab,  HWND, $ObjPtr(MaskedImageList)
  endif
  RedefineMethod    Load,               $ObjPtr(Stream)             ;-> Stream
  RedefineMethod    Store,              $ObjPtr(Stream)             ;-> Stream

  DefineVariable    Setup,              SeriesSetupXY,    {1, PS_SOLID, 0, 11, 0, 00FFFFFFh, 0, 1}
ObjectEnd


; ==================================================================================================


if IMPLEMENT

ifdef INCLUDE_CHART_SETUP_DIALOG
% include &ObjPath&ChartXYTabSeries.inc
endif
% include &ObjPath&ChartXYSeries.inc

endif
