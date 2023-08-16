; ==================================================================================================
; Title:      ChartBar.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm cluster to support Bar-chart objects and their setup.
; Notes:      Version C.1.0, August 2021
;               - First release.
; ==================================================================================================



SeriesSetupBar struct
  dBarWidth          DWORD      ?
  sdBarOffset        SDWORD     ?
  dBorderWidth       DWORD      ?
  dBorderStyle       DWORD      ?
  BorderColor        COLORREF   ?
  FillColorFore      COLORREF   ?
  FillColorBack      COLORREF   ?
  dFillStyle         DWORD      ?
SeriesSetupBar ends

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     ChartBarTabSeries
; Purpose:    Series Tab of ChartSetup.

ifdef INCLUDE_CHART_SETUP_DIALOG
Object ChartBarTabSeries, , ChartTabSeries
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    Init,               POINTER, HWND, $ObjPtr(MaskedImageList)
  RedefineMethod    OnCommand,          WPARAM, LPARAM
  RedefineMethod    OnInitDialog,       WPARAM, LPARAM
  RedefineMethod    Restore

  DefineVariable    LocalSetup,         SeriesSetupBar,   {}
ObjectEnd
endif

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:  ChartBarSeries
; Purpose: Implement a data series for plot usage.
; Note:    - Data must be floating point numbers (REAL4 or REAL8). See CHT_FLOAT.
;          - The generic memory layout is [(x0, y0), (x1, y1), (x2, y2), ...]

Object ChartBarSeries, ChartBarSeriesID, ChartSeries
  RedefineMethod    Draw,               HDC
  ifdef INCLUDE_CHART_SETUP_DIALOG
  RedefineMethod    GetSetupDialogTab,  HWND, $ObjPtr(MaskedImageList)
  endif
  RedefineMethod    Load,               $ObjPtr(Stream)             ;-> Stream
  RedefineMethod    Store,              $ObjPtr(Stream)             ;-> Stream

  DefineVariable    Setup,    SeriesSetupBar,     {20, 0, 1, PS_SOLID, 0, 00FFFFFFh, 00FFFFFFh, -1}
ObjectEnd


; ==================================================================================================


if IMPLEMENT

BAR_FILL_STYLE_SOLID  equ   HS_DIAGCROSS + 1            ;HS_DIAGCROSS is the last item in the enum.

ifdef INCLUDE_CHART_SETUP_DIALOG
% include &ObjPath&ChartBarTabSeries.inc
endif
% include &ObjPath&ChartBarSeries.inc

endif
