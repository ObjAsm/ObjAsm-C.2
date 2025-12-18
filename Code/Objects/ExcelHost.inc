; ==================================================================================================
; Title:      ExcelHost.inc
; Author:     G. Friedrich
; Version:    C.2.0
; Purpose:    ObjAsm support of Excel Host objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.2.0, February 2023
;               - PrintSheet added.
; ==================================================================================================


; ==================================================================================================
;     Object definitions
; ==================================================================================================


XLH_CLSID     equ   1
XLH_INSTANCE  equ   2
XLH_QI_APP    equ   3

externdef IID_NULL:GUID
externdef IID_IUnknown:GUID

; --------------------------------------------------------------------------------------------------
; Object:     ExcelHost
; Purpose:    Implement a Host object for Excel automation.

Object ExcelHost, ExcelHostID, Primer
  StaticMethod      CloseBook,                POINTER
  StaticMethod      DeleteSheet,              POINTER
  RedefineMethod    Done
  StaticMethod      GetBook,                  DWORD
  StaticMethod      GetCell,                  POINTER, DWORD, DWORD, POINTER, WORD
  StaticMethod      GetRange,                 POINTER, BSTR
  StaticMethod      GetSheet,                 POINTER, BSTR
  StaticMethod      GetSheetName,             POINTER
  RedefineMethod    Init,                     POINTER
  StaticMethod      NewBook
  StaticMethod      NewChart,                 DWORD, DWORD, BSTR
  StaticMethod      NewSheet,                 POINTER, BSTR
  StaticMethod      Open,                     BSTR
  StaticMethod      PrintSheet,               POINTER, BSTR
  StaticMethod      SaveAs,                   POINTER, BSTR
  StaticMethod      SelectRange,              POINTER
  StaticMethod      SetCalculation,           SDWORD
  StaticMethod      SetCell,                  POINTER, DWORD, DWORD, BSTR
  StaticMethod      SetColumnWidth,           POINTER, BSTR, REAL4
  StaticMethod      SetDisplayAlerts,         BOOL
  StaticMethod      SetScreenUpdating,        BOOL

  StaticMethod      GetBorder,                POINTER
  StaticMethod      SetBorderAttr,            POINTER, DWORD, DWORD, COLORREF

  StaticMethod      GetFont,                  POINTER
  StaticMethod      SetFontAttr,              POINTER, BSTR, DWORD, DWORD, COLORREF, DWORD

  StaticMethod      GetInterior,              POINTER
  StaticMethod      SetInteriorAttr,          POINTER, COLORREF, DWORD, COLORREF

  StaticMethod      SetChartData,             POINTER, POINTER, DWORD
  StaticMethod      HasChartTitle,            POINTER, DWORD
  StaticMethod      GetChartTitle,            POINTER
  StaticMethod      SetChartTitleText,        POINTER, BSTR
  StaticMethod      GetChartAxis,             POINTER, DWORD, DWORD
  StaticMethod      SetChartAxisAttr,         POINTER, DWORD, DWORD, DWORD, DWORD
  StaticMethod      SetChartAxisValues,       POINTER, DWORD, REAL8, DWORD, REAL8
  StaticMethod      SetChartAxisTicks,        POINTER, DWORD, DWORD, REAL8, DWORD, DWORD, REAL8
  StaticMethod      SetChartAxisGridlines,    POINTER, DWORD, DWORD, DWORD, DWORD, COLORREF
  StaticMethod      GetChartLegend,           POINTER
  StaticMethod      GetChartArea,             POINTER
  StaticMethod      GetChartPlotArea,         POINTER
  StaticMethod      GetChartSeries,           POINTER, DWORD
  StaticMethod      SetChartSeriesAttr,       POINTER, DWORD, DWORD, COLORREF, COLORREF, DWORD, DWORD
  StaticMethod      SetChartSeriesData,       POINTER, BSTR, POINTER, POINTER

  StaticMethod      SetRangeAlignHor,         POINTER, DWORD
  StaticMethod      SetRangeAlignVer,         POINTER, DWORD
  StaticMethod      GetRangeBorder,           POINTER, DWORD
  StaticMethod      GetRangeArray,            POINTER, POINTER
  StaticMethod      CreateArray,              DWORD, DWORD, POINTER

  StaticMethod      SetRowHeight,             POINTER, BSTR, REAL4
  StaticMethod      SetSavedFlag,             POINTER, DWORD
  StaticMethod      SetSheetName,             POINTER, BSTR
  StaticMethod      SetVisible,               DWORD
  StaticMethod      Quit

  DefineVariable    pIExcelApp,               POINTER,  NULL
ObjectEnd

XlFontStyleItalic         equ BIT00
XlFontStyleBold           equ BIT01
XlFontStyleStrikethrough  equ BIT02
XlFontStyleSuperscript    equ BIT03
XlFontStyleSubscript      equ BIT04
XlFontStyleOutlineFont    equ BIT05
XlFontStyleShadow         equ BIT06

% include &OA_PATH&Projects\X\Office\ExcelHost\Excel.inc
% include &OA_PATH&Projects\X\Office\ExcelHost\Excelc.inc


if IMPLEMENT

.const                                                  ;GUID local constants
DefGUID IID_Application, %sIID__Application


; ==================================================================================================
;     ExcelHost implementation
; ==================================================================================================

.code

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.GetChartSeries
; Purpose:    Return the Series interface of a specified Chart.
; Arguments:  Arg1: -> Chart interface.
;             Arg2: Series index [1..n].
; Return:     xax -> Series interface.

Method ExcelHost.GetChartSeries,, pIXlChart:POINTER, dXlSeriesIndex:DWORD
  local vArg:VARIANT, pIXlCurChart:POINTER
  local vXlSeries:VARIANT, pIXlSeries:POINTER

  .if pIXlChart == NULL
    SetObject xcx
    ICall [xcx].pIExcelApp::_Application.get_ActiveChart, addr pIXlCurChart
    .if FAILED(eax) || (pIXlCurChart == NULL)
      xor eax, eax
      ExitMethod
    .endif
    ReleaseObject
  .else
    m2m pIXlCurChart, pIXlChart, xax
  .endif

  mov vArg.vt, VT_I4
  m2m vArg.lVal, dXlSeriesIndex, edx
  invoke VariantInit, addr vXlSeries
  COM_Dispatch pIXlCurChart::_Chart.SeriesCollection, addr vArg, addr vXlSeries
  .if SUCCEEDED(eax) && (vXlSeries.pdispVal != NULL)
    m2m pIXlSeries, vXlSeries.pdispVal, xax
  .else
    m2z pIXlSeries
  .endif

  .if pIXlChart == NULL
    ICall pIXlCurChart::_Chart.Release
  .endif

  mov xax, pIXlSeries
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.SetChartSeriesAttr
; Purpose:    Set the properties of a specified Chart Series object.
; Arguments:  Arg1: -> ChartSeries interface.
;             Arg2: Marker Style.
;             Arg3: Marker Size.
;             Arg4: Marker foreground color (RGB).
;             Arg5: Marker background color (RGB).
;             Arg6: Smooth (TRUE, FALSE).
;             Arg7: Shadow (TRUE, FALSE).
; Return:     eax = Error code.

Method ExcelHost.SetChartSeriesAttr,, pIXlSeries:POINTER, dXlStyle:DWORD, dXlSize:DWORD, \
                                      dXlForeColor:COLORREF, dXlBackColor:COLORREF, \
                                      dXlSmooth:DWORD, dXlShadow:DWORD
  local vArg:VARIANT

  .if pIXlSeries == NULL
    mov eax, 080000005h                                 ;Invalid POINTER
  .else
    mov vArg.vt, VT_I4
    m2m vArg.lVal, dXlStyle, edx
    COM_Dispatch pIXlSeries::Series.put_MarkerStyle, addr vArg
    .if SUCCEEDED(eax)
      mov vArg.vt, VT_I4
      m2m vArg.lVal, dXlSize, edx
      COM_Dispatch pIXlSeries::Series.put_MarkerSize, addr vArg
      .if SUCCEEDED(eax)
        mov vArg.vt, VT_I4
        m2m vArg.lVal, dXlForeColor, edx
        COM_Dispatch pIXlSeries::Series.put_MarkerForegroundColor, addr vArg
        .if SUCCEEDED(eax)
          mov vArg.vt, VT_I4
          m2m vArg.lVal, dXlBackColor, edx
          COM_Dispatch pIXlSeries::Series.put_MarkerBackgroundColor, addr vArg
          .if SUCCEEDED(eax)
            mov vArg.vt, VT_BOOL
            m2m vArg.lVal, dXlSmooth, edx
            COM_Dispatch pIXlSeries::Series.put_Smooth, addr vArg
            .if SUCCEEDED(eax)
              mov vArg.vt, VT_BOOL
              m2m vArg.lVal, dXlShadow, edx
              COM_Dispatch pIXlSeries::Series.put_Shadow, addr vArg
            .endif
          .endif
        .endif
      .endif
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.SetChartSeriesData
; Purpose:    Set the data of a specified Chart Series object.
; Arguments:  Arg1: -> ChartSeries interface.
;             Arg2: -> Name (BSTR).
;             Arg3: -> XValue SafeArray.
;             Arg4: -> YValue SafeArray.
; Return:     eax = Error code.

Method ExcelHost.SetChartSeriesData,, pIXlSeries:POINTER, pXlName:BSTR, \
                                      pXlXArray:POINTER, pXlYArray:POINTER
  local vArg:VARIANT

  .if pIXlSeries == NULL
    mov eax, 080000005h                                 ;Invalid POINTER
  .else
    mov vArg.vt, VT_BSTR
    m2m vArg.bstrVal, pXlName, xdx
    COM_Dispatch pIXlSeries::Series.put_Name, addr vArg
    .if SUCCEEDED(eax)
      COM_Dispatch pIXlSeries::Series.put_XValues, pXlXArray
      .if SUCCEEDED(eax)
        COM_Dispatch pIXlSeries::Series.put_Values, pXlYArray
      .endif
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.CreateArray
; Purpose:    Create a bidimentional SafeArray.
; Arguments:  Arg1: X-dimension size.
;             Arg2: Y-dimension size.
;             Arg3: -> Variant that will recieve the array info
; Return:     eax = Error code.

Method ExcelHost.CreateArray,, dXlXSize:DWORD, dXlYSize:DWORD, pXlArray:POINTER
  local sab_1:SAFEARRAYBOUND, sab_0:SAFEARRAYBOUND

  mov sab_0.lLbound, 1
  m2m sab_0.cElements, dXlXSize, edx
  mov sab_1.lLbound, 1
  m2m sab_1.cElements, dXlYSize, edx
;  invoke SafeArrayCreate, VT_VARIANT, 2, addr sab_0
  mov xcx, pXlArray
  mov [xcx].VARIANT.vt, VARTYPE ptr (VT_ARRAY or VT_VARIANT)
  mov [xcx].VARIANT.parray, xax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.GetBorder
; Purpose:    Return the Border interface of a specified object.
; Arguments:  Arg1: -> Object interface.
; Return:     xax -> Border interface.

Method ExcelHost.GetBorder,, pIXlObject:POINTER
  local vXlBorder:VARIANT

  .if pIXlObject == NULL
    xor eax, eax
    ExitMethod
  .endif

  invoke VariantInit, addr vXlBorder
  ;get_Border DispID = 80h
  invoke CallDispatch, pIXlObject, 080h, DISPATCH_PROPERTYGET, 0, NULL, addr vXlBorder
  .if SUCCEEDED(eax)
    mov xax, vXlBorder.pdispVal
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.SetBorderAttr
; Purpose:    Set the properties of a specified Border object.
; Arguments:  Arg1: -> Border interface.
;             Arg2: Line style.
;             Arg3: Weight.
;             Arg4: RGB color.
; Return:     eax = Error code.

Method ExcelHost.SetBorderAttr,, pIXlBorder:POINTER, dXlStyle:DWORD, dXlWeight:DWORD, dXlColor:COLORREF
  local vArg:VARIANT

  .if pIXlBorder == NULL
    mov eax, 080000005h                                 ;Invalid POINTER
  .else
    mov vArg.vt, VT_I4
    m2m vArg.lVal, dXlWeight, edx
    COM_Dispatch pIXlBorder::Border.put_Weight, addr vArg
    .if SUCCEEDED(eax)
      mov vArg.vt, VT_I4
      m2m vArg.lVal, dXlColor, edx
      COM_Dispatch pIXlBorder::Border.put_Color, addr vArg
      .if SUCCEEDED(eax)
        mov vArg.vt, VT_I4
        m2m vArg.lVal, dXlStyle, edx
        COM_Dispatch pIXlBorder::Border.put_LineStyle, addr vArg
      .endif
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.GetFont
; Purpose:    Return the Font interface of a specified object.
; Arguments:  Arg1: -> Object interface.
; Return:     xax -> Font interface.

Method ExcelHost.GetFont,, pIXlObject:POINTER
  local vXlFont:VARIANT

  .if pIXlObject == NULL
    xor eax, eax
    ExitMethod
  .endif

  invoke VariantInit, addr vXlFont
  ;get_Font DispID = 92h
  invoke CallDispatch, pIXlObject, 092h, DISPATCH_PROPERTYGET, 0, NULL, addr vXlFont
  .if SUCCEEDED(eax)
    mov xax, vXlFont.pdispVal
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.SetFontAttr
; Purpose:    Set font attributes
; Arguments:  Arg1: -> Font interface.
;             Arg2: -> Name.
;             Arg3: Style.
;             Arg4: Size.
;             Arg5: RGB color.
;             Arg6: Underline style.
; Return:     eax = Error code.

Method ExcelHost.SetFontAttr,, pIXlFont:POINTER, pXlName:BSTR, dXlStyle:DWORD, dXlSize:DWORD, \
                               dXlColor:COLORREF, dXlUnderlineStyle:DWORD
  local vArg:VARIANT

  .if pIXlFont == NULL
    mov eax, 080000005h                                 ;Invalid POINTER
  .else
    mov vArg.vt, VT_BSTR
    m2m vArg.bstrVal, pXlName, edx
    COM_Dispatch pIXlFont::Font.put_Name, addr vArg
    .if SUCCEEDED(eax)
      mov vArg.vt, VT_BOOL
      xor eax, eax
      .ifBitSet dXlStyle, XlFontStyleItalic
        inc eax
      .endif
      mov vArg.lVal, eax
      COM_Dispatch pIXlFont::Font.put_Italic, addr vArg
      .if SUCCEEDED(eax)
        xor eax, eax
        .ifBitSet dXlStyle, XlFontStyleBold
          inc eax
        .endif
        mov vArg.lVal, eax
        COM_Dispatch pIXlFont::Font.put_Bold, addr vArg
        .if SUCCEEDED(eax)
          xor eax, eax
          .ifBitSet dXlStyle, XlFontStyleStrikethrough
            inc eax
          .endif
          mov vArg.lVal, eax
          COM_Dispatch pIXlFont::Font.put_Strikethrough, addr vArg
          .if SUCCEEDED(eax)
            xor eax, eax
            .ifBitSet dXlStyle, XlFontStyleSuperscript
              inc eax
            .endif
            mov vArg.lVal, eax
            COM_Dispatch pIXlFont::Font.put_Superscript, addr vArg
            .if SUCCEEDED(eax)
              xor eax, eax
              .ifBitSet dXlStyle, XlFontStyleSubscript
                inc eax
              .endif
              mov vArg.lVal, eax
              COM_Dispatch pIXlFont::Font.put_Subscript, addr vArg
              .if SUCCEEDED(eax)
                xor eax, eax
                .ifBitSet dXlStyle, XlFontStyleOutlineFont
                  inc eax
                .endif
                mov vArg.lVal, eax
                COM_Dispatch pIXlFont::Font.put_OutlineFont, addr vArg
                .if SUCCEEDED(eax)
                  xor eax, eax
                  .ifBitSet dXlStyle, XlFontStyleShadow
                    inc eax
                  .endif
                  mov vArg.lVal, eax
                  COM_Dispatch pIXlFont::Font.put_Shadow, addr vArg
                  .if SUCCEEDED(eax)
                    mov vArg.vt, VT_I4
                    m2m vArg.bstrVal, dXlSize, edx
                    COM_Dispatch pIXlFont::Font.put_Size, addr vArg
                    .if SUCCEEDED(eax)
                      mov vArg.vt, VT_I4
                      m2m vArg.bstrVal, dXlColor, edx
                      COM_Dispatch pIXlFont::Font.put_Color, addr vArg
                      .if SUCCEEDED(eax)
                        mov vArg.vt, VT_I4
                        m2m vArg.bstrVal, dXlUnderlineStyle, edx
                        COM_Dispatch pIXlFont::Font.put_Underline, addr vArg
                      .endif
                    .endif
                  .endif
                .endif
              .endif
            .endif
          .endif
        .endif
      .endif
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.GetInterior
; Purpose:    Return the Interior interface of a specified object.
; Arguments:  Arg1: -> Object interface.
; Return:     xax -> Interior interface.

Method ExcelHost.GetInterior,, pIXlObject:POINTER
  local vXlInterior:VARIANT

  .if pIXlObject == NULL
    xor eax, eax
    ExitMethod
  .endif

  invoke VariantInit, addr vXlInterior
  ;get_Interior DispID = 81h
  invoke CallDispatch, pIXlObject, 081h, DISPATCH_PROPERTYGET, 0, NULL, addr vXlInterior
  .if SUCCEEDED(eax)
    mov xax, vXlInterior.pdispVal
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.SetInteriorAttr
; Purpose:    Set the properties of a specified Interior object.
; Arguments:  Arg1: -> Interior interface.
;             Arg2: RGB color value.
;             Arg3: Pattern value.
;             Arg4: Pattern RGB color value.
; Return:     eax = Error code.

Method ExcelHost.SetInteriorAttr,, pIXlInterior:POINTER, dXlColor:COLORREF, dXlPatternStyle:DWORD, \
                                   dXlPatternColor:COLORREF
  local vArg:VARIANT

  .if pIXlInterior == NULL
    mov eax, 080000005h                                 ;Invalid POINTER
  .else
    mov vArg.vt, VT_I4                                  ;Setup argument Variant
    m2m vArg.lVal, dXlColor, edx
    COM_Dispatch pIXlInterior::Interior.put_Color, addr vArg
    .if SUCCEEDED(eax)
      mov vArg.vt, VT_I4                                ;Setup argument Variant
      m2m vArg.lVal, dXlPatternStyle, edx
      COM_Dispatch pIXlInterior::Interior.put_Pattern, addr vArg
      .if SUCCEEDED(eax)
        mov vArg.vt, VT_I4                              ;Setup argument Variant
        m2m vArg.lVal, dXlPatternColor, edx
        COM_Dispatch pIXlInterior::Interior.put_PatternColor, addr vArg
      .endif
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.CloseBook
; Purpose:    Close a specified Workbook.
; Arguments:  Arg1: -> Workbook interface.
; Return:     eax = Error code.

XLH_CLOSE_BOOK_ARG struc   ;Arguments are passed in REVERSE order
  vArg3   VARIANT   {}
  vArg2   VARIANT   {}
  vArg1   VARIANT   {}
XLH_CLOSE_BOOK_ARG ends

Method ExcelHost.CloseBook, uses xbx, pIXlWorkbook:POINTER
  local XCB:XLH_CLOSE_BOOK_ARG, pICurWorkbook:POINTER

  .if pIXlWorkbook == NULL
    SetObject xcx
    ICall [xcx].pIExcelApp::_Application.get_ActiveWorkbook, addr pICurWorkbook
    .if FAILED(eax) || (pICurWorkbook == NULL)
      ExitMethod
    .endif
    ReleaseObject
  .else
    m2m pICurWorkbook, pIXlWorkbook, xdx
  .endif

  TypeMissing XCB.vArg1, XCB.vArg2, XCB.vArg3
  COM_Dispatch pICurWorkbook::_Workbook.Close, addr XCB

  .if pIXlWorkbook == NULL
    mov ebx, eax
    ICall pICurWorkbook::_Workbook.Release
    mov eax, ebx
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.DeleteSheet
; Purpose:    Delete a specified Worksheet.
; Arguments:  Arg1: -> Worksheet interface.
; Return:     eax = Error code.

Method ExcelHost.DeleteSheet, uses xbx, pIXlWorksheet:POINTER
  local pICurWorksheet:POINTER

  .if pIXlWorksheet == NULL
    SetObject xcx
    ICall [xcx].pIExcelApp::_Application.get_ActiveSheet, addr pICurWorksheet
    .if FAILED(eax) || (pICurWorksheet == NULL)
      ExitMethod
    .endif
    ReleaseObject
  .else
    m2m pICurWorksheet, pIXlWorksheet, xax
  .endif

  COM_Dispatch pICurWorksheet::_Worksheet.Delete, NULL, NULL

  .if pIXlWorksheet == NULL
    mov ebx, eax
    ICall pICurWorksheet::_Worksheet.Release
    mov eax, ebx
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.Done
; Purpose:    Finalize the ExcelHost object.
; Arguments:  None.
; Return:     Nothing.

Method ExcelHost.Done, uses xsi
  SetObject xsi
  .if [xsi].pIExcelApp != NULL
    ICall [xsi].pIExcelApp::_Application.Release
  .endif
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.GetBook
; Purpose:    Get an existing Workbook from the Excel Application.
; Arguments:  Arg1: Workbook index.
; Return:     xax -> Workbook interface or NULL.

Method ExcelHost.GetBook, uses xbx, dIndex:DWORD
  local pIXlWorkbooks:POINTER, pIXlWorkbook:POINTER, vArg:VARIANT

  SetObject xcx
  ICall [xcx].pIExcelApp::_Application.get_Workbooks, addr pIXlWorkbooks
  .if SUCCEEDED(eax)
    mov vArg.vt, VT_I4
    m2m vArg.lVal, dIndex, edx
    ICall pIXlWorkbooks::Workbooks.get_Item, vArg, addr pIXlWorkbook
    .if SUCCEEDED(eax)
      mov xbx, pIXlWorkbook
    .else
      xor ebx, ebx
    .endif
    ICall pIXlWorkbooks::Workbooks.Release
    mov xax, xbx
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.GetCell
; Purpose:    Return the value from a specific Cell.
; Arguments:  Arg1: -> Range interface.
;             Arg2: Row.
;             Arg3: Column.
;             Arg4: -> return Variant.
;             Arg5: Desired return type (VT_xxx).
; Return:     eax = Error code.

XLH_GET_CELL_ARG struc    ;Arguments are passed in REVERSE order
  vCol  VARIANT   {}
  vRow  VARIANT   {}
XLH_GET_CELL_ARG ends

Method ExcelHost.GetCell, uses xbx, pIXlRange:POINTER, dXlRow:DWORD, dXlCol:DWORD, pvRet:POINTER, wRetType:WORD
  local XGC:XLH_GET_CELL_ARG, pIXlCurRange:POINTER

  .if pIXlRange == NULL
    SetObject xcx
    ICall [xcx].pIExcelApp::_Application.get_ActiveCell, addr pIXlCurRange
    .if FAILED(eax) || (pIXlCurRange == NULL)
      ExitMethod
    .endif
    ReleaseObject
  .else
    m2m pIXlCurRange, pIXlRange, xax
  .endif

  mov XGC.vRow.vt, VT_I4                                ;Setup argument Variants
  m2m XGC.vRow.lVal, dXlRow, edx
  mov XGC.vCol.vt, VT_I4
  m2m XGC.vCol.lVal, dXlCol, edx
  COM_Dispatch pIXlCurRange::Range.get_Item, addr XGC, pvRet
  .if SUCCEEDED(eax)
    invoke VariantChangeType, pvRet, pvRet, NULL, wRetType
  .endif

  .if pIXlRange == NULL
    mov ebx, eax
    ICall pIXlCurRange::Range.Release
    mov eax, ebx
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.GetRange
; Purpose:    Return a Range interface from a specified Worksheet.
; Arguments:  Arg1: -> WorkSheet interface.
;             Arg2: -> Range address string.
; Return:     xax -> Range interface or NULL.

XLH_GET_RANGE_ARG struc     ;Arguments are passed in REVERSE order
  vDummy  VARIANT   {}
  vAddr   VARIANT   {}
XLH_GET_RANGE_ARG ends

Method ExcelHost.GetRange,, pIXlWorksheet:POINTER, pCellStr:BSTR
  local XGR:XLH_GET_RANGE_ARG, vRet:VARIANT
  local pICurWorksheet:POINTER

  .if pIXlWorksheet == NULL
    SetObject xcx
    ICall [xcx].pIExcelApp::_Application.get_ActiveSheet, addr pICurWorksheet
    .if FAILED(eax) || (pICurWorksheet == NULL)
      xor eax, eax
      ExitMethod
    .endif
    ReleaseObject
  .else
    m2m pICurWorksheet, pIXlWorksheet, xax
  .endif

  mov XGR.vAddr.vt, VT_BSTR                             ;Setup argument Variants
  m2m XGR.vAddr.bstrVal, pCellStr, xax
  mov XGR.vDummy.vt, VT_BSTR
  m2m XGR.vDummy.bstrVal, pCellStr, xax

  COM_Dispatch pICurWorksheet::_Worksheet.get_Range, addr XGR, addr vRet

  .if pIXlWorksheet == NULL
    ICall pICurWorksheet::_Worksheet.Release
  .endif

  mov xax, vRet.punkVal
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.GetSheet
; Purpose:    Return the Sheet interface from a specified Workbook.
; Arguments:  Arg1: -> Workbook interface.
;             Arg2: -> Worksheet name.
; Return:     xax -> Worksheet or NULL.

Method ExcelHost.GetSheet,, pIXlWorkbook:POINTER, pName:BSTR
  local vName:VARIANT, pIXlWorksheets:POINTER, pIXlWorksheet:POINTER
  local pICurWorkbook:POINTER

  .if pIXlWorkbook == NULL
    SetObject xcx
    ICall [xcx].pIExcelApp::_Application.get_ActiveWorkbook, addr pICurWorkbook
    .if FAILED(eax) || (pICurWorkbook == NULL)
      xor eax, eax
      ExitMethod
    .endif
    ReleaseObject
  .else
    m2m pICurWorkbook, pIXlWorkbook, xax
  .endif

  ICall pICurWorkbook::_Workbook.get_Sheets, addr pIXlWorksheets

  mov vName.vt, VT_BSTR                                 ;Setup argument Variant
  m2m vName.bstrVal, pName, xax
  ICall pIXlWorksheets::Sheets.get_Item, vName, addr pIXlWorksheet

  ICall pIXlWorksheets::Sheets.Release

  .if pIXlWorkbook == NULL
    ICall pICurWorkbook::_Workbook.Release
  .endif

  mov xax, pIXlWorksheet
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.GetSheetName
; Purpose:    Return the name of a specified Worksheet.
; Arguments:  Arg1: -> Worksheet interface.
; Return:     xax -> Name string or NULL.

Method ExcelHost.GetSheetName,, pIXlWorksheet:POINTER
  local vRet:VARIANT, pICurWorksheet:POINTER

  .if pIXlWorksheet == NULL
    SetObject xcx
    ICall [xcx].pIExcelApp::_Application.get_ActiveSheet, addr pICurWorksheet
    .if FAILED(eax) || (pICurWorksheet == NULL)
      xor eax, eax
      ExitMethod
    .endif
    ReleaseObject
  .else
    m2m pICurWorksheet, pIXlWorksheet, xax
  .endif

  TypeMissing vRet                                    ;Setup argument Variant
  COM_Dispatch pICurWorksheet::_Worksheet.get_Name, NULL, addr vRet

  .if pIXlWorksheet == NULL
    ICall pICurWorksheet::_Worksheet.Release
  .endif

  mov xax, vRet.bstrVal
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.Init
; Purpose:    Initialize the ExcelHost object and create an Excel Application instance.
; Arguments:  Arg1: -> Owner object.
; Return:     Nothing.

Method ExcelHost.Init, uses xsi, pOwner:POINTER
  local ClsID:GUID

  SetObject xsi
  ACall xsi.Init, pOwner

  invoke CLSIDFromProgID, $OfsCStrW("Excel.Application"), addr ClsID
  .if FAILED(eax)
    OCall xsi.ErrorReport, NULL, XLH_CLSID
  .else

    invoke CoCreateInstance, addr ClsID, 0, CLSCTX_SERVER, offset IID_Application, \
                             addr [xsi].pIExcelApp
    .if FAILED(eax)
      OCall xsi.ErrorReport, NULL, XLH_INSTANCE
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.NewBook
; Purpose:    Add a new Workbook to the Excel Application.
; Arguments:  None.
; Return:     xax -> Workbook interface or NULL.

Method ExcelHost.NewBook, uses xbx
  local pIXlWorkbooks:POINTER, pIXlWorkbook:POINTER, vArg:VARIANT

  SetObject xcx
  ICall [xcx].pIExcelApp::_Application.get_Workbooks, addr pIXlWorkbooks
  .if SUCCEEDED(eax)
    TypeMissing vArg
    ICall pIXlWorkbooks::Workbooks.Add_, vArg, 0, addr pIXlWorkbook
    .if SUCCEEDED(eax)
      mov xbx, pIXlWorkbook
    .else
      xor ebx, ebx
    .endif
    ICall pIXlWorkbooks::Workbooks.Release
    mov xax, xbx
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.NewChart
; Purpose:    Create a new chart.
; Arguments:  Arg1: Chart type (xlXYScatterLinesNoMarkers, etc.).
;             Arg2: Chart location (xlLocationAsObject, etc.).
;             Arg3: BSTR where to position the chart ("My Worksheet").
; Return:     xax -> Chart interface or NULL.

XLH_NEW_CHART_ARG struc                                 ;Arguments are passed in REVERSE order
  vArg3   VARIANT   {}
  vArg2   VARIANT   {}
  vArg1   VARIANT   {}
XLH_NEW_CHART_ARG ends

Method ExcelHost.NewChart, uses xbx, dXlChartType:DWORD, dXlLocationType:DWORD, pXlLocationWhere:BSTR
  local XNC:XLH_NEW_CHART_ARG
  local pXlCharts:POINTER, vXlChart:VARIANT

  SetObject xcx
  ICall [xcx].pIExcelApp::_Application.get_Charts, addr pXlCharts
  .if SUCCEEDED(eax)
    TypeMissing XNC.vArg1, XNC.vArg2, XNC.vArg3
    COM_Dispatch pXlCharts::Charts.Add_, addr XNC, addr vXlChart
    .if SUCCEEDED(eax)
      mov XNC.vArg1.vt, VT_I4
      m2m XNC.vArg1.lVal, dXlChartType, eax
      COM_Dispatch vXlChart.pdispVal::_Chart.put_ChartType, addr XNC.vArg1, NULL

      mov XNC.vArg1.vt, VT_I4
      m2m XNC.vArg1.lVal, dXlLocationType, eax
      mov XNC.vArg2.vt, VT_BSTR
      m2m XNC.vArg2.bstrVal, pXlLocationWhere, xax
      TypeMissing XNC.vArg3
      COM_Dispatch vXlChart.pdispVal::_Chart.Location, addr XNC.vArg2, addr XNC.vArg3
      ICall vXlChart.pdispVal::IUnknown.Release
      mov xbx, XNC.vArg3.pdispVal
    .else
      xor ebx, ebx
    .endif
    ICall pXlCharts::Charts.Release
    mov xax, xbx
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.NewSheet
; Purpose:    Add a new Worksheet to a specified book.
; Arguments:  Arg1: -> Workbook interface.
;             Arg2: BSTR Name.
; Return:     xax -> Worksheet interface.

XLH_NEW_SHEET_ARG struc                                 ;Arguments are passed in REVERSE order
  vArg4   VARIANT   {}
  vArg3   VARIANT   {}
  vArg2   VARIANT   {}
  vArg1   VARIANT   {}
XLH_NEW_SHEET_ARG ends

Method ExcelHost.NewSheet,, pIXlWorkbook:POINTER, pName:BSTR
  local XNS:XLH_NEW_SHEET_ARG, vRet:VARIANT
  local pIXlWorksheets:POINTER, pICurWorkbook:POINTER

  m2z pICurWorkbook
  .if pIXlWorkbook == NULL
    SetObject xcx
    ICall [xcx].pIExcelApp::_Application.get_ActiveWorkbook, addr pICurWorkbook
    ReleaseObject
    .if FAILED(eax)
      DbgComError eax
      xor eax, eax
      ExitMethod
    .elseif pICurWorkbook == NULL
      xor eax, eax
      ExitMethod
    .endif
  .else
    m2m pICurWorkbook, pIXlWorkbook, xax
  .endif

  ICall pICurWorkbook::_Workbook.get_Sheets, addr pIXlWorksheets
  TypeMissing XNS.vArg1, XNS.vArg2, XNS.vArg3, XNS.vArg4
  COM_Dispatch pIXlWorksheets::Sheets.Add_, addr XNS, addr vRet
  .if FAILED(eax)
    DbgComError eax
    xor eax, eax
    ExitMethod
  .elseif pName != NULL
    OCall pSelf::ExcelHost.SetSheetName, vRet.pdispVal, pName
  .endif

  ICall pIXlWorksheets::Sheets.Release
  .if pIXlWorkbook == NULL
    ICall pICurWorkbook::_Workbook.Release
  .endif

  mov xax, vRet.pdispVal
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.Open
; Purpose:    Open a Workbook from a file.
; Arguments:  Arg1: -> Filename.
; Return:     xax -> Workbook interface or NULL. CAUTION: the returned interface may be of another
;             thing. Instead, get the active book.
;             https://stackoverflow.com/questions/13019981/workbooks-open-returns-different-file
;             -than-filename

XLH_OPEN_ARG struc                                      ;Arguments are passed in REVERSE order
  vCorruptLoad  VARIANT   {}
  vLocal        VARIANT   {}
  vAddToMru     VARIANT   {}
  vConverter    VARIANT   {}
  vNotify       VARIANT   {}
  vEditable     VARIANT   {}
  vDelimiter    VARIANT   {}
  vOrigin       VARIANT   {}
  vIgnoreReadOnly   VARIANT   {}
  vWriteResPassword VARIANT   {}
  vPassword     VARIANT   {}
  vFormat       VARIANT   {}
  vReadOnly     VARIANT   {}
  vUpdateLinks  VARIANT   {}
  vFileName     VARIANT   {}
XLH_OPEN_ARG ends

Method ExcelHost.Open,, pXlFileName:BSTR
  local Args:XLH_OPEN_ARG, vWorkbook:VARIANT, pIXlWorkbooks:POINTER

  SetObject xcx
  ICall [xcx].pIExcelApp::_Application.get_Workbooks, addr pIXlWorkbooks
  .if SUCCEEDED(eax)
    mov Args.vFileName.vt, VT_BSTR
    m2m Args.vFileName.bstrVal, pXlFileName, xax
    mov Args.vReadOnly.vt, VT_BOOL
    m2z Args.vReadOnly.boolVal
    TypeMissing Args.vUpdateLinks, Args.vFormat, Args.vPassword, Args.vWriteResPassword
    TypeMissing Args.vIgnoreReadOnly, Args.vOrigin, Args.vDelimiter, Args.vEditable
    TypeMissing Args.vNotify, Args.vConverter, Args.vAddToMru, Args.vLocal, Args.vCorruptLoad
    m2z vWorkbook.punkVal
    COM_Dispatch pIXlWorkbooks::Workbooks.Open, addr Args, addr vWorkbook
    ICall pIXlWorkbooks::Workbooks.Release
    mov xax, vWorkbook.punkVal                            ;Return -> _Workbook interface
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.PrintSheet
; Purpose:    Print the sheet onto the printer.
; Arguments:  Arg1: -> Sheet.
;             Arg2: -> BSTR Printer name. NULL to use the default printer.
; Return:

XLH_PRINT_ARG struc                                     ;Arguments are passed in REVERSE order
  vFrom             VARIANT   {}                        ;DISPID = 0x389!!!
  vTo               VARIANT   {}
  vCopies           VARIANT   {}
  vPreview          VARIANT   {}
  vActivePrinter    VARIANT   {}
  vPrintToFile      VARIANT   {}
  vCollate          VARIANT   {}
XLH_PRINT_ARG ends

Method ExcelHost.PrintSheet,, pIXlWorksheet:POINTER, pPrinterName:BSTR
  local Args:XLH_PRINT_ARG, vRet:VARIANT

  TypeMissing Args.vFrom, Args.vTo, Args.vCopies, Args.vPreview, \
              Args.vPrintToFile, Args.vCollate

  .if pPrinterName == NULL
    TypeMissing Args.vActivePrinter
  .else
    mov Args.vActivePrinter.vt, VT_BSTR
    m2m Args.vActivePrinter.bstrVal, pPrinterName, xax
  .endif

  COM_Dispatch pIXlWorksheet::_Worksheet._PrintOut, addr Args, addr vRet
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.SaveAs
; Purpose:    Save a specified Workbook.
; Arguments:  Arg1: -> Workbook.
;             Arg2: -> File name.
; Return:     eax = Error code.

XLH_SAVEAS_ARG struc                                      ;Arguments are passed in REVERSE order
  vLocal            VARIANT   {}
  vTextVisualLayout VARIANT   {}
  vTextCodepage     VARIANT   {}
  vAddToMru         VARIANT   {}
  vConflictResol    VARIANT   {}
  vAccessMode       VARIANT   {}
  vCreateBackup     VARIANT   {}
  vReadOnlyRecom    VARIANT   {}
  vWriteResPassword VARIANT   {}
  vPassword         VARIANT   {}
  vFileFormat       VARIANT   {}
  vFileName         VARIANT   {}
XLH_SAVEAS_ARG ends

Method ExcelHost.SaveAs, uses xbx, pIXlWorkbook:POINTER, pFileName:BSTR
  local Args:XLH_SAVEAS_ARG, pICurWorkbook:POINTER

  .if pIXlWorkbook == NULL
    SetObject xcx
    ICall [xcx].pIExcelApp::_Application.get_ActiveWorkbook, addr pICurWorkbook
    .if FAILED(eax) || (pICurWorkbook == NULL)
      ExitMethod
    .endif
    ReleaseObject
  .else
    m2m pICurWorkbook, pIXlWorkbook, xax
  .endif

  mov Args.vFileName.vt, VT_BSTR
  m2m Args.vFileName.bstrVal, pFileName, xax
  mov Args.vConflictResol.vt, VT_I4
  mov Args.vConflictResol.lVal, xlLocalSessionChanges

  TypeMissing Args.vLocal, Args.vTextVisualLayout, Args.vTextCodepage, Args.vAddToMru
  TypeMissing Args.vAccessMode, Args.vCreateBackup, Args.vReadOnlyRecom
  TypeMissing Args.vWriteResPassword, Args.vPassword, Args.vFileFormat

  COM_Dispatch pICurWorkbook::_Workbook.SaveAs, addr Args

  .if pIXlWorkbook == NULL
    mov ebx, eax
    ICall pICurWorkbook::_Workbook.Release
    mov eax, ebx
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.SelectRange
; Purpose:    Select a give range.
; Arguments:  Arg1: -> Range interface.
; Return:     eax = Success/failure.

Method ExcelHost.SelectRange,, pIXlRange:POINTER
  local vBool:VARIANT

  .if pIXlRange == NULL
    mov eax, -1
    ExitMethod
  .endif

  COM_Dispatch pIXlRange::Range.Select, NULL, addr vBool
  movsx eax, vBool.boolVal
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.SetCalculation
; Purpose:    Sets Calculation property.
; Arguments:  Arg1: xlCalculationAutomatic, xlCalculationManual, xlCalculationSemiautomatic
; Return:     eax = Error code.

Method ExcelHost.SetCalculation,, sdCalcMode:SDWORD
  SetObject xcx
  ICall [xcx].pIExcelApp::_Application.put_Calculation, LOCALE_SYSTEM_DEFAULT, sdCalcMode
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.SetCell
; Purpose:    Write a string into a specific Cell.
; Arguments:  Arg1: Column.
;             Arg2: Row.
;             Arg3: -> string
; Return:     eax = Error code.

XLH_SET_CELL_ARG struc                                  ;Arguments are passed in REVERSE order
  vArg  VARIANT   {}
  vCol  VARIANT   {}
  vRow  VARIANT   {}
XLH_SET_CELL_ARG ends

Method ExcelHost.SetCell, uses xbx, pIXlRange:POINTER, dXlRow:DWORD, dXlCol:DWORD, pBStr:BSTR
  local Args:XLH_SET_CELL_ARG, pIXlCurRange:POINTER

  .if pIXlRange == NULL
    SetObject xcx
    ICall [xcx].pIExcelApp::_Application.get_ActiveCell, addr pIXlCurRange
    .if FAILED(eax) || (pIXlCurRange == NULL)
      ExitMethod
    .endif
    ReleaseObject
  .else
    m2m pIXlCurRange, pIXlRange, xax
  .endif

  mov Args.vRow.vt, VT_I4                                  ;Setup argument Variants
  m2m Args.vRow.lVal, dXlRow, eax
  mov Args.vCol.vt, VT_I4
  m2m Args.vCol.lVal, dXlCol, eax
  mov Args.vArg.vt, VT_BSTR
  m2m Args.vArg.bstrVal, pBStr, xax
  COM_Dispatch pIXlCurRange::Range.put_Item, addr Args

  .if pIXlRange == NULL
    mov ebx, eax
    ICall pIXlCurRange::Range.Release
    mov eax, ebx
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.SetColumnWidth
; Purpose:    Set the column width of a specified column range.
; Arguments:  Arg1: -> Worksheet interface.
;             Arg2: Column range string (i.e. "G:k").
;             Arg2: Column width.
; Return:     eax = Error code.

XLH_SET_COL_WIDTH_ARG struc                             ;Arguments are passed in REVERSE order
  vWidth    VARIANT   {}
  vColRange VARIANT   {}
  vDummy    VARIANT   {}
  vColStr   VARIANT   {}
XLH_SET_COL_WIDTH_ARG ends

Method ExcelHost.SetColumnWidth, uses xbx, pIXlWorksheet:POINTER, pXlColStr:BSTR, r4XlWidth:REAL4
  local Args:XLH_SET_COL_WIDTH_ARG, pICurWorksheet:POINTER

  .if pIXlWorksheet == NULL
    SetObject xcx
    ICall [xcx].pIExcelApp::_Application.get_ActiveSheet, addr pICurWorksheet
    .if FAILED(eax) || (pICurWorksheet == NULL)
      ExitMethod
    .endif
    ReleaseObject
  .else
    m2m pICurWorksheet, pIXlWorksheet, xax
  .endif

  mov Args.vColStr.vt, VT_BSTR                        ;Setup argument Variants
  m2m Args.vColStr.bstrVal, pXlColStr, xax
  mov Args.vDummy.vt, VT_BSTR
  m2m Args.vDummy.bstrVal, pXlColStr, xax
  mov Args.vColRange.vt, VT_EMPTY
  COM_Dispatch pICurWorksheet::_Worksheet.get_Range, addr Args.vDummy, addr Args.vColRange
  .if SUCCEEDED(eax)
    mov Args.vWidth.vt, VT_R4
    m2m Args.vWidth.fltVal, r4XlWidth, eax
    COM_Dispatch Args.vColRange.pdispVal::Range.put_ColumnWidth, addr Args.vWidth
    mov ebx, eax
    ICall Args.vColRange.pdispVal::IUnknown.Release
    mov eax, ebx
  .endif

  .if pIXlWorksheet == NULL
    ICall pICurWorksheet::_Worksheet.Release
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.SetDisplayAlerts
; Purpose:    Sets DisplayAlerts.
; Arguments:  Arg1: TRUE/FALSE
; Return:     eax = Error code.

Method ExcelHost.SetDisplayAlerts,, dSwitch:BOOL
  SetObject xcx
  ICall [xcx].pIExcelApp::_Application.put_DisplayAlerts, LOCALE_SYSTEM_DEFAULT, dSwitch
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.SetScreenUpdating
; Purpose:    Sets ScreenUpdating.
; Arguments:  Arg1: TRUE/FALSE
; Return:     eax = Error code.

Method ExcelHost.SetScreenUpdating,, dSwitch:BOOL
  SetObject xcx
  ICall [xcx].pIExcelApp::_Application.put_ScreenUpdating, LOCALE_SYSTEM_DEFAULT, dSwitch
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.GetChartTitle
; Purpose:    Set the title of a chart.
; Arguments:  Arg1: -> Chart interface.
; Return:     xax -> Chart Title interface.

Method ExcelHost.GetChartTitle,, pIXlChart:POINTER
  local vArg:VARIANT, pIXlCurChart:POINTER, pIXlChartTitle:POINTER

  .if pIXlChart == NULL
    SetObject xcx
    ICall [xcx].pIExcelApp::_Application.get_ActiveChart, addr pIXlCurChart
    .if FAILED(eax) || (pIXlCurChart == NULL)
      xor eax, eax
      ExitMethod
    .endif
    ReleaseObject
  .else
    m2m pIXlCurChart, pIXlChart, xax
  .endif

  invoke VariantInit, addr vArg
  COM_Dispatch pIXlCurChart::_Chart.get_ChartTitle, NULL, addr vArg
  .if SUCCEEDED(eax) && (vArg.pdispVal != NULL)
    m2m pIXlChartTitle, vArg.pdispVal, xax
  .else
    m2z pIXlChartTitle
  .endif

  .if pIXlChart == NULL
    ICall pIXlCurChart::_Chart.Release
  .endif

  mov xax, pIXlChartTitle
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.HasChartTitle
; Purpose:    Display or hides the chart title..
; Arguments:  Arg1: -> Chart interface.
;             Arg2: TRUE/FALSE
; Return:     eax = Error code.

Method ExcelHost.HasChartTitle, uses xbx, pIXlChart:POINTER, dXlShowFlag:DWORD
  local vArg:VARIANT, pIXlCurChart:POINTER

  .if pIXlChart == NULL
    SetObject xcx
    ICall [xcx].pIExcelApp::_Application.get_ActiveChart, addr pIXlCurChart
    .if FAILED(eax) || (pIXlCurChart == NULL)
      ExitMethod
    .endif
    ReleaseObject
  .else
    m2m pIXlCurChart, pIXlChart, xax
  .endif

  mov vArg.vt, VT_BOOL
  m2m vArg.lVal, dXlShowFlag, eax                       ;Attention: boolVal doesn't do the job!
  COM_Dispatch pIXlCurChart::_Chart.put_HasTitle, addr vArg

  .if pIXlChart == NULL
    mov ebx, eax
    ICall pIXlCurChart::_Chart.Release
    mov eax, ebx
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.SetChartTitleText
; Purpose:    Set the title of a chart.
; Arguments:  Arg1: -> ChartTitle interface.
;             Arg2: -> String.
; Return:     eax = Error code.

Method ExcelHost.SetChartTitleText,, pIXlChartTitle:POINTER, pXlTitleText:BSTR
  local vArg:VARIANT

  .if pIXlChartTitle != NULL
    mov vArg.vt, VT_BSTR
    m2m vArg.pbstrVal, pXlTitleText, xax
    COM_Dispatch pIXlChartTitle::ChartTitle.put_Text, addr vArg
  .else
    mov eax, 080000005h                                 ;Invalid POINTER
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.GetChartAxis
; Purpose:    Return the Axis interface of a specified chart.
; Arguments:  Arg1: -> Chat interface.
;             Arg2: Axis type.
;             Arg3: Axis group.
; Return:     xax -> Axis interface.

XLH_GET_CHART_AXIS_ARG struc                            ;Arguments are passed in REVERSE order
  vXlAxisGroup  VARIANT   {}
  vXlAxisType   VARIANT   {}
XLH_GET_CHART_AXIS_ARG ends

Method ExcelHost.GetChartAxis,, pIXlChart:POINTER, dXlAxisType:DWORD, dXlAxisGroup:DWORD
  local Args:XLH_GET_CHART_AXIS_ARG, pIXlCurChart:POINTER, vXlAxis:VARIANT

  .if pIXlChart == NULL
    SetObject xcx
    ICall [xcx].pIExcelApp::_Application.get_ActiveChart, addr pIXlCurChart
    .if FAILED(eax) || (pIXlCurChart == NULL)
      xor eax, eax
      ExitMethod
    .endif
    ReleaseObject
  .else
    m2m pIXlCurChart, pIXlChart, xax
  .endif

  mov Args.vXlAxisType.vt, VT_I4
  m2m Args.vXlAxisType.lVal, dXlAxisType, eax
  mov Args.vXlAxisGroup.vt, VT_I4
  m2m Args.vXlAxisGroup.lVal, dXlAxisGroup, eax
  COM_Dispatch pIXlCurChart::_Chart.Axes, addr Args, addr vXlAxis
  .if SUCCEEDED(eax)
    mov xax, vXlAxis.pdispVal
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.SetChartAxisValues
; Purpose:    Set the Chat Axis attributes.
; Arguments:  Arg1: -> Axis interface.
;             Arg2: Minimum Automatic.
;             Arg3: Minimum Value.
;             Arg3: Maximum Automatic.
;             Arg3: Maximum Value.
; Return:     eax = Error code.

Method ExcelHost.SetChartAxisValues,, pIXlAxis:POINTER, dXlMinAuto:DWORD, r8XlMin:REAL8, \
                                                        dXlMaxAuto:DWORD, r8XlMax:REAL8
  local vArg:VARIANT

  .if pIXlAxis == NULL
    mov eax, 080000005h                               ;Invalid POINTER
  .else
    mov vArg.vt, VT_BOOL
    m2m vArg.lVal, dXlMinAuto, eax
    COM_Dispatch pIXlAxis::Axis.put_MinimumScaleIsAuto, addr vArg
    mov vArg.vt, VT_R8
    if TARGET_BITNESS eq 32
      m2m DWORD ptr [vArg.dblVal], DWORD ptr [r8XlMin], eax
      m2m DWORD ptr [vArg.dblVal + sizeof DWORD], DWORD ptr [r8XlMin + sizeof DWORD], eax
    else
      m2m QWORD ptr [vArg.dblVal], QWORD ptr [r8XlMin], rax
    endif
    COM_Dispatch pIXlAxis::Axis.put_MinimumScale, addr vArg

    mov vArg.vt, VT_BOOL
    m2m vArg.lVal, dXlMaxAuto, eax
    COM_Dispatch pIXlAxis::Axis.put_MaximumScaleIsAuto, addr vArg
    mov vArg.vt, VT_R8
    if TARGET_BITNESS eq 32
      m2m DWORD ptr [vArg.dblVal], DWORD ptr [r8XlMax], eax
      m2m DWORD ptr [vArg.dblVal + sizeof DWORD], DWORD ptr [r8XlMax + sizeof DWORD], eax
    else
      m2m QWORD ptr [vArg.dblVal], QWORD ptr [r8XlMax], rax
    endif
    COM_Dispatch pIXlAxis::Axis.put_MaximumScale, addr vArg
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.SetChartAxisTicks
; Purpose:    Set the Chat Axis attributes.
; Arguments:  Arg1: -> Axis interface.
;             Arg2: Minor Mark style (xlInside, xlOutside, ...)
;             Arg3: Minor Automatic (TRUE, FALSE).
;             Arg4: Minor Value.
;             Arg5: Major Mark style (xlInside, xlOutside, ...)
;             Arg6: Major Automatic (TRUE, FALSE).
;             Arg7: Major Value.
; Return:     eax = Error code.

Method ExcelHost.SetChartAxisTicks,, pIXlAxis:POINTER, \
                                     dXlMnrMarkStyle:DWORD, dXlMnrAuto:DWORD, r8XlMnr:REAL8, \
                                     dXlMjrMarkStyle:DWORD, dXlMjrAuto:DWORD, r8XlMjr:REAL8
  local vArg:VARIANT

  .if pIXlAxis == NULL
    mov eax, 080000005h                               ;Invalid POINTER
  .else
    mov vArg.vt, VT_I4
    m2m vArg.lVal, dXlMnrMarkStyle, eax
    COM_Dispatch pIXlAxis::Axis.put_MinorTickMark, addr vArg
    mov vArg.vt, VT_BOOL
    m2m vArg.lVal, dXlMnrAuto, eax
    COM_Dispatch pIXlAxis::Axis.put_MinorUnitIsAuto, addr vArg
    mov vArg.vt, VT_R8
    if TARGET_BITNESS eq 32
      m2m DWORD ptr [vArg.dblVal], DWORD ptr [r8XlMnr], eax
      m2m DWORD ptr [vArg.dblVal + sizeof DWORD], DWORD ptr [r8XlMnr + sizeof DWORD], eax
    else
      m2m QWORD ptr [vArg.dblVal], QWORD ptr [r8XlMnr], rax
    endif
    COM_Dispatch pIXlAxis::Axis.put_MinorUnit, addr vArg

    mov vArg.vt, VT_I4
    m2m vArg.lVal, dXlMjrMarkStyle, eax
    COM_Dispatch pIXlAxis::Axis.put_MajorTickMark, addr vArg
    mov vArg.vt, VT_BOOL
    m2m vArg.lVal, dXlMjrAuto, eax
    COM_Dispatch pIXlAxis::Axis.put_MajorUnitIsAuto, addr vArg
    mov vArg.vt, VT_R8
    if TARGET_BITNESS eq 32
      m2m DWORD ptr [vArg.dblVal], DWORD ptr [r8XlMjr], eax
      m2m DWORD ptr [vArg.dblVal + sizeof DWORD], DWORD ptr [r8XlMjr + sizeof DWORD], eax
    else
      m2m QWORD ptr [vArg.dblVal], QWORD ptr [r8XlMjr], rax
    endif
    COM_Dispatch pIXlAxis::Axis.put_MajorUnit, addr vArg
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.SetChartAxisGridlines
; Purpose:    Set the Chat Axis attributes.
; Arguments:  Arg1: -> Axis interface.
;             Arg2: GridLine type (xlMajorGridlines, xlMinorGridlines).
;             Arg3: Has line (TRUE, FALSE).
;             Arg4: Line style.
;             Arg5: Line weight.
;             Arg6: RGB color value.
; Return:     eax = Error code.

Method ExcelHost.SetChartAxisGridlines,, pIXlAxis:POINTER, dXlGridLineType:DWORD, dXlHasLine:DWORD, \
                                     dXlStyle:DWORD, dXlWeight:DWORD, dXlColor:COLORREF
  local vArg:VARIANT, vGridlines:VARIANT

  .if pIXlAxis == NULL
    mov eax, 080000005h                                 ;Invalid POINTER
  .else
    .if dXlGridLineType == xlMajorGridlines
      mov vArg.vt, VT_BOOL
      m2m vArg.lVal, dXlHasLine, eax
      COM_Dispatch pIXlAxis::Axis.put_HasMajorGridlines, addr vArg
      invoke VariantInit, addr vGridlines
      COM_Dispatch pIXlAxis::Axis.get_MajorGridlines, NULL, addr vGridlines
      invoke VariantInit, addr vArg
      COM_Dispatch vGridlines.pdispVal::Gridlines.get_Border, NULL, addr vArg
      OCall SetBorderAttr, vArg.pdispVal, dXlStyle, dXlWeight, dXlColor
      ICall vArg.pdispVal::Border.Release
      ICall vGridlines.pdispVal::Gridlines.Release
    .elseif dXlGridLineType == xlMinorGridlines
      mov vArg.vt, VT_BOOL
      m2m vArg.lVal, dXlHasLine, eax
      COM_Dispatch pIXlAxis::Axis.put_HasMinorGridlines, addr vArg
      invoke VariantInit, addr vGridlines
      COM_Dispatch pIXlAxis::Axis.get_MinorGridlines, NULL, addr vGridlines
      invoke VariantInit, addr vArg
      COM_Dispatch vGridlines.pdispVal::Gridlines.get_Border, NULL, addr vArg
      OCall SetBorderAttr, vArg.pdispVal, dXlStyle, dXlWeight, dXlColor
      ICall vArg.pdispVal::Border.Release
      ICall vGridlines.pdispVal::Gridlines.Release
    .else
      mov eax, 08002802Bh                               ;Element not found
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.SetChartAxisAttr
; Purpose:    Set the Chat Axis attributes.
; Arguments:  Arg1: -> Axis interface.
;             Arg2: Scale type.
;             Arg3: Display Unit.
;             Arg4: Reverse plot order.
;             Arg5: Label position (xlLow, xlHight, ...).
; Return:     eax = Error code.

Method ExcelHost.SetChartAxisAttr,, pIXlAxis:POINTER, dXlScaleType:DWORD, dXlDispUnit:DWORD, \
                                    dXlRevOrder:DWORD, dXlLabelPosition:DWORD
  local vArg:VARIANT

  .if pIXlAxis == NULL
    mov eax, 080000005h                                 ;Invalid POINTER
  .else
    mov vArg.vt, VT_I4
    m2m vArg.lVal, dXlScaleType, eax
    COM_Dispatch pIXlAxis::Axis.put_ScaleType, addr vArg
    mov vArg.vt, VT_I4
    m2m vArg.lVal, dXlDispUnit, eax
    COM_Dispatch pIXlAxis::Axis.put_DisplayUnit, addr vArg
    mov vArg.vt, VT_BOOL
    m2m vArg.lVal, dXlRevOrder, eax
    COM_Dispatch pIXlAxis::Axis.put_ReversePlotOrder, addr vArg
    mov vArg.vt, VT_I4
    m2m vArg.lVal, dXlLabelPosition, eax
    COM_Dispatch pIXlAxis::Axis.put_TickLabelPosition, addr vArg
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.GetChartLegend
; Purpose:    Return the legend interface of a chart.
; Arguments:  Arg1: -> Chart interface.
; Return:     xax -> Chart Legend interface.

Method ExcelHost.GetChartLegend,, pIXlChart:POINTER
  local vArg:VARIANT, pIXlCurChart:POINTER, pIXlChartLegend:POINTER

  .if pIXlChart == NULL
    SetObject xcx
    ICall [xcx].pIExcelApp::_Application.get_ActiveChart, addr pIXlCurChart
    .if FAILED(eax) || (pIXlCurChart == NULL)
      xor eax, eax
      ExitMethod
    .endif
    ReleaseObject
  .else
    m2m pIXlCurChart, pIXlChart, xax
  .endif

  invoke VariantInit, addr vArg
  COM_Dispatch pIXlCurChart::_Chart.get_Legend, NULL, addr vArg
  .if SUCCEEDED(eax) && (vArg.pdispVal != NULL)
    m2m pIXlChartLegend, vArg.pdispVal, xax
  .else
    m2z pIXlChartLegend
  .endif

  .if pIXlChart == NULL
    ICall pIXlCurChart::_Chart.Release
  .endif

  mov xax, pIXlChartLegend
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.GetChartArea
; Purpose:    Return the ChartArea interface of a chart.
; Arguments:  Arg1: -> Chart interface.
; Return:     xax -> ChartArea interface.

Method ExcelHost.GetChartArea,, pIXlChart:POINTER
  local vArg:VARIANT, pIXlCurChart:POINTER, pIXlChartArea:POINTER

  .if pIXlChart == NULL
    SetObject xcx
    ICall [xcx].pIExcelApp::_Application.get_ActiveChart, addr pIXlCurChart
    .if FAILED(eax) || (pIXlCurChart == NULL)
      xor eax, eax
      ExitMethod
    .endif
    ReleaseObject
  .else
    m2m pIXlCurChart, pIXlChart, xax
  .endif

  invoke VariantInit, addr vArg
  COM_Dispatch pIXlCurChart::_Chart.get_ChartArea, NULL, addr vArg
  .if SUCCEEDED(eax) && (vArg.pdispVal != NULL)
    m2m pIXlChartArea, vArg.pdispVal, xax
  .else
    m2z pIXlChartArea
  .endif

  .if pIXlChart == NULL
    ICall pIXlCurChart::_Chart.Release
  .endif

  mov xax, pIXlChartArea
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.GetChartPlotArea
; Purpose:    Return the PlotArea interface of a chart.
; Arguments:  Arg1: -> Chart interface.
; Return:     xax -> PlotArea interface.

Method ExcelHost.GetChartPlotArea,, pIXlChart:POINTER
  local vArg:VARIANT, pIXlCurChart:POINTER, pIXlPlotArea:POINTER

  .if pIXlChart == NULL
    SetObject xcx
    ICall [xcx].pIExcelApp::_Application.get_ActiveChart, addr pIXlCurChart
    .if FAILED(eax) || (pIXlCurChart == NULL)
      xor eax, eax
      ExitMethod
    .endif
    ReleaseObject
  .else
    m2m pIXlCurChart, pIXlChart, xax
  .endif

  invoke VariantInit, addr vArg
  COM_Dispatch pIXlCurChart::_Chart.get_PlotArea, NULL, addr vArg
  .if SUCCEEDED(eax) && (vArg.pdispVal != NULL)
    m2m pIXlPlotArea, vArg.pdispVal, xax
  .else
    m2z pIXlPlotArea
  .endif

  .if pIXlChart == NULL
    ICall pIXlCurChart::_Chart.Release
  .endif

  mov xax, pIXlPlotArea
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.SetChartData
; Purpose:    Create a new chart.
; Arguments:  Arg1: -> Chart interface.
;             Arg2: -> data range.
;             Arg3: Data orientation (xlColumns, etc.).
; Return:     eax = Error code.

XLH_SET_CHART_DATA_ARG struc   ;Arguments are passed in REVERSE order
  vArg2   VARIANT   {}
  vArg1   VARIANT   {}
XLH_SET_CHART_DATA_ARG ends

Method ExcelHost.SetChartData, uses xbx, pIXlChart:POINTER, pIXlDataRange:POINTER, dXlDataOrientation:DWORD
  local Args:XLH_SET_CHART_DATA_ARG, pIXlCurChart:POINTER

  .if pIXlChart == NULL
    SetObject xcx
    ICall [xcx].pIExcelApp::_Application.get_ActiveChart, addr pIXlCurChart
    .if FAILED(eax) || (pIXlCurChart == NULL)
      ExitMethod
    .endif
    ReleaseObject
  .else
    m2m pIXlCurChart, pIXlChart, xax
  .endif

  mov Args.vArg1.vt, VT_DISPATCH
  m2m Args.vArg1.pdispVal, pIXlDataRange, xax
  mov Args.vArg2.vt, VT_I4
  m2m Args.vArg2.lVal, dXlDataOrientation, eax
  COM_Dispatch pIXlCurChart::_Chart.SetSourceData, addr Args

  .if pIXlChart == NULL
    mov ebx, eax
    ICall pIXlCurChart::_Chart.Release
    mov eax, ebx
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.GetRangeBorder
; Purpose:    Return a border interface of a specified range.
; Arguments:  Arg1: -> Range.
;             Arg2: Border location (xlEdgeBottom, ...).
; Return:     xax -> Border interface.

Method ExcelHost.GetRangeBorder,, pIXlRange:POINTER, dXlLocation:DWORD
  local vXlBorders:VARIANT, vXlBorder:VARIANT, pIXlBorder:POINTER
  local vArg:VARIANT, pIXlCurRange:POINTER

  .if pIXlRange == NULL
    SetObject xcx
    ICall [xcx].pIExcelApp::_Application.get_ActiveCell, addr pIXlCurRange
    .if FAILED(eax) || (pIXlCurRange == NULL)
      xor eax, eax
      ExitMethod
    .endif
    ReleaseObject
  .else
    m2m pIXlCurRange, pIXlRange, xax
  .endif

  COM_Dispatch pIXlCurRange::Range.get_Borders, NULL, addr vXlBorders
  .if FAILED(eax)
    m2z pIXlBorder
  .else
    invoke VariantInit, addr vXlBorder
    mov vArg.vt, VT_I4                                  ;Setup argument Variants
    m2m vArg.lVal, dXlLocation, eax                     ;border location
    COM_Dispatch vXlBorders.punkVal::Borders.get_Item, addr vArg, addr vXlBorder
    .if FAILED(eax)
      m2z pIXlBorder
    .else
      m2m pIXlBorder, vXlBorder.pdispVal, xdx
    .endif
    ICall vXlBorders.punkVal::Borders.Release
  .endif

  .if pIXlRange == NULL
    ICall pIXlCurRange::Range.Release
  .endif

  mov xax, pIXlBorder
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.GetRangeArray
; Purpose:    Return a SafeArray of a specified range.
; Arguments:  Arg1: -> Range.
;             Arg2: -> Variant containig a SafeArray .
; Return:     eax = Error code.

Method ExcelHost.GetRangeArray,, pIXlRange:POINTER, pXlArrayVariant:POINTER
  local pIXlCurRange:POINTER, vArg:VARIANT

  .if pIXlRange == NULL
    SetObject xcx
    ICall [xcx].pIExcelApp::_Application.get_ActiveCell, addr pIXlCurRange
    .if FAILED(eax) || (pIXlCurRange == NULL)
      ExitMethod
    .endif
    ReleaseObject
  .else
    m2m pIXlCurRange, pIXlRange, xax
  .endif

  mov vArg.vt, VT_I4
  mov vArg.lVal, xlRangeValueDefault
  COM_Dispatch pIXlCurRange::Range.get_Value, addr vArg, pXlArrayVariant
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.SetRangeAlignHor
; Purpose:    Set a range horizontal alignment.
; Arguments:  Arg1: -> Range interface.
;             Arg2: Alignment value.
; Return:     eax = Error code.

Method ExcelHost.SetRangeAlignHor, uses xbx, pIXlRange:POINTER, dXlAlignment:DWORD
  local vArg:VARIANT, pIXlCurRange:POINTER

  .if pIXlRange == NULL
    SetObject xcx
    ICall [xcx].pIExcelApp::_Application.get_ActiveCell, addr pIXlCurRange
    .if FAILED(eax) || (pIXlCurRange == NULL)
      ExitMethod
    .endif
    ReleaseObject
  .else
    m2m pIXlCurRange, pIXlRange, xax
  .endif

  mov vArg.vt, VT_I4                                ;Setup argument Variant
  m2m vArg.lVal, dXlAlignment, eax
  COM_Dispatch pIXlCurRange::Range.put_HorizontalAlignment, addr vArg

  .if pIXlRange == NULL
    mov ebx, eax
    ICall pIXlCurRange::Range.Release
    mov eax, ebx
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.SetRowHeight
; Purpose:    Set the row height of a specified row range.
; Arguments:  Arg1: -> Worksheet interface.
;             Arg2: row range string (i.e. "3:5").
;             Arg3: row width.
; Return:     eax = Error code.

XLH_SET_ROW_HEIGHT_ARG struc                            ;Arguments are passed in REVERSE order
  vHeight   VARIANT   {}
  vRowRange VARIANT   {}
  vDummy    VARIANT   {}
  vRowStr   VARIANT   {}
XLH_SET_ROW_HEIGHT_ARG ends

Method ExcelHost.SetRowHeight, uses xbx, pIXlWorksheet:POINTER, pXlRowStr:BSTR, dXlHeight:REAL4
  local Args:XLH_SET_ROW_HEIGHT_ARG, pICurWorksheet:POINTER

  .if pIXlWorksheet == NULL
    SetObject xcx
    ICall [xcx].pIExcelApp::_Application.get_ActiveSheet, addr pICurWorksheet
    .if FAILED(eax) || (pICurWorksheet == NULL)
      ExitMethod
    .endif
    ReleaseObject
  .else
    m2m pICurWorksheet, pIXlWorksheet, xax
  .endif

  mov Args.vRowStr.vt, VT_BSTR                         ;Setup argument Variants
  m2m Args.vRowStr.bstrVal, pXlRowStr, xax
  mov Args.vDummy.vt, VT_BSTR
  m2m Args.vDummy.bstrVal, pXlRowStr, xax
  mov Args.vRowRange.vt, VT_EMPTY
  COM_Dispatch pICurWorksheet::_Worksheet.get_Range, addr Args.vDummy, addr Args.vRowRange
  .if SUCCEEDED(eax)
    mov Args.vHeight.vt, VT_R4
    m2m Args.vHeight.fltVal, dXlHeight, eax
    COM_Dispatch Args.vRowRange.pdispVal::Range.put_RowHeight, addr Args.vHeight
    mov ebx, eax
    ICall Args.vRowRange.pdispVal::IUnknown.Release
    mov eax, ebx
  .endif

  .if pIXlWorksheet == NULL
    mov ebx, eax
    ICall pICurWorksheet::_Worksheet.Release
    mov eax, ebx
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.SetSavedFlag
; Purpose:    Set Workbook "Saved" internal flag, so Excel doesn't ask to save.
; Arguments:  Arg1: -> Workbook interface.
;             Arg2: TRUE/FALSE.
; Return:     eax = Error code.

Method ExcelHost.SetSavedFlag, uses xbx, pIXlWorkbook:POINTER, dXlSaveFlag:DWORD
  local vArg:VARIANT, pICurWorkbook:POINTER

  .if pIXlWorkbook == NULL
    SetObject xcx
    ICall [xcx].pIExcelApp::_Application.get_ActiveWorkbook, addr pICurWorkbook
    .if FAILED(eax) || (pICurWorkbook == NULL)
      ExitMethod
    .endif
    ReleaseObject
  .else
    m2m pICurWorkbook, pIXlWorkbook, xax
  .endif

  mov vArg.vt, VT_BOOL                                  ;Setup argument Variant
  m2m vArg.lVal, dXlSaveFlag, eax
  COM_Dispatch pICurWorkbook::_Workbook.put_Saved, addr vArg

  .if pIXlWorkbook == NULL
    mov ebx, eax
    ICall pICurWorkbook::_Workbook.Release
    mov eax, ebx
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.SetSheetName
; Purpose:    Set the Worksheet name.
; Arguments:  Arg1: -> Worksheet interface.
;             Arg2: -> New name.
; Return:     eax = Error code.

Method ExcelHost.SetSheetName, uses xbx, pIXlWorksheet:POINTER, pXlName:BSTR
  local vArg:VARIANT, pICurWorksheet:POINTER

  .if pIXlWorksheet == NULL
    SetObject xcx
    ICall [xcx].pIExcelApp::_Application.get_ActiveSheet, addr pICurWorksheet
    .if FAILED(eax) || (pICurWorksheet == NULL)
      ExitMethod
    .endif
    ReleaseObject
  .else
    m2m pICurWorksheet, pIXlWorksheet, xax
  .endif

  mov vArg.vt, VT_BSTR                                  ;Setup argument Variant
  m2m vArg.bstrVal, pXlName, xax
  COM_Dispatch pICurWorksheet::_Worksheet.put_Name, addr vArg, NULL

  .if pIXlWorksheet == NULL
    mov ebx, eax
    ICall pICurWorksheet::_Worksheet.Release
    mov eax, ebx
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.SetRangeAlignVer
; Purpose:    Set a range vertical alignment.
; Arguments:  Arg1: -> Range interface.
;             Arg2: Alignment value.
; Return:     eax = Error code.

Method ExcelHost.SetRangeAlignVer, uses xbx, pIXlRange:POINTER, dXlAlignment:DWORD
  local vArg:VARIANT, pIXlCurRange:POINTER

  .if pIXlRange == NULL
    SetObject xcx
    ICall [xcx].pIExcelApp::_Application.get_ActiveCell, addr pIXlCurRange
    .if FAILED(eax) || (pIXlCurRange == NULL)
      ExitMethod
    .endif
    ReleaseObject
  .else
    m2m pIXlCurRange, pIXlRange, xax
  .endif

  mov vArg.vt, VT_I4                                    ;Setup argument Variant
  m2m vArg.lVal, dXlAlignment, eax
  COM_Dispatch pIXlCurRange::Range.put_VerticalAlignment, addr vArg

  .if pIXlRange == NULL
    mov ebx, eax
    ICall pIXlCurRange::Range.Release
    mov eax, ebx
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.SetVisible
; Purpose:    Toggle visibility of the Excel Application.
; Arguments:  Arg1: TRUE/FALSE.
; Return:     Nothing.

Method ExcelHost.SetVisible,, dVisibility:DWORD
  SetObject xcx
  ICall [xcx].pIExcelApp::_Application.put_Visible, LOCALE_SYSTEM_DEFAULT, dVisibility
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ExcelHost.Quit
; Purpose:    Quit Excel Application.
; Arguments:  None.
; Return:     Nothing.

Method ExcelHost.Quit
  SetObject xcx
  ICall [xcx].pIExcelApp::_Application.Quit
MethodEnd

endif
