; ==================================================================================================
; Title:      ExcelHost.asm
; Author:     G. Friedrich
; Version:    1.0.0
; Purpose:    ObjAsm ExcelHost Application.
; Notes:      Version 1.0.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, NUI64, WIDE_STRING;, DEBUG(WND)           ;Load OOP files and OS related objects

% include &MacPath&BStrings.inc                         ;BSTR support
% include &COMPath&COM.inc                              ;COM basic support
% include &COMPath&COM_Dispatch.inc                     ;Dispatch definitions and macros
% include &COMPath&OAIDL.inc
% include &IncPath&Windows\Ole2.inc
% include &IncPath&Windows\sGUID.inc

% includelib &LibPath&Windows\ole32.lib
% includelib &LibPath&Windows\OleAut32.lib

.code
% include &COMPath&COM_Dispatch.asm                     ;Dispatch procedures

.const                                                  ;Global GUIDs
DefGUID IID_NULL, %sGUID_NULL
DefGUID IID_IUnknown, %sIID_IUnknown

MakeObjects Primer, ExcelHost

MyBStr struct
  dByteSize DWORD ?
  cBuffer   CHR 20 dup(?)  
MyBStr ends

.code
start proc uses xbx xdi
  local pIBook:POINTER, pISheet:POINTER, pIRange:POINTER, pIChart:POINTER
  local vString:VARIANT, vArray1:VARIANT, vArray2:VARIANT, BStrBuffer:MyBStr
  local hWnd:HANDLE, dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD

  ;***** ObjAsm initialization *****
  SysInit

  ;***** OLE / COM initialization *****
  invoke OleInitialize, 0

  ;***** ExcelHost initialization *****
  OCall $ObjTmpl(ExcelHost)::ExcelHost.Init, NULL
  .if $ObjTmpl(ExcelHost).dErrorCode == OBJ_OK
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetVisible, TRUE

    ICall $ObjTmpl(ExcelHost).pIExcelApp::_Application.get_Hwnd, addr hWnd
    mov dWndWidth, 1500
    mov dWndHeight, 900
    mov dWndPosX, $32($invoke(CenterForm, dWndWidth,  $32($invoke(GetSystemMetrics, SM_CXSCREEN))))
    mov dWndPosY, $32($invoke(CenterForm, dWndHeight, $32($invoke(GetSystemMetrics, SM_CYSCREEN))))
    invoke SetWindowPos, hWnd, HWND_TOPMOST, dWndPosX, dWndPosY, dWndWidth, dWndHeight, SWP_SHOWWINDOW
    invoke SetWindowPos, hWnd, HWND_NOTOPMOST, dWndPosX, dWndPosY, dWndWidth, dWndHeight, SWP_SHOWWINDOW

    ;***** Create a new WorkBook and a new WorkSheet *****
    mov pIBook, $OCall($ObjTmpl(ExcelHost)::ExcelHost.NewBook)
    mov pISheet, $OCall($ObjTmpl(ExcelHost)::ExcelHost.NewSheet, pIBook, $OfsCBStr("My Worksheet"))

    ;***** Get a Range and format it *****
    mov pIRange, $OCall($ObjTmpl(ExcelHost)::ExcelHost.GetRange, pISheet, $OfsCBStr("C3:E5"))
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetCell, pIRange, 2, 2, $OfsCBStr("Hello Excel")
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetRangeAlignHor, pIRange, xlHAlignCenter
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetRangeAlignVer, pIRange, xlHAlignCenter

    ;***** Make a Border arround the Range *****
    mov xbx, $OCall($ObjTmpl(ExcelHost)::ExcelHost.GetRangeBorder, pIRange, xlEdgeTop)
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetBorderAttr, xbx, xlDouble, xlThick, $RGB(255,0,0)
    ICall xbx::Border.Release
    mov xbx, $OCall($ObjTmpl(ExcelHost)::ExcelHost.GetRangeBorder, pIRange, xlEdgeRight)
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetBorderAttr, xbx, xlDouble, xlThick, $RGB(255,0,0)
    ICall xbx::Border.Release
    mov xbx, $OCall($ObjTmpl(ExcelHost)::ExcelHost.GetRangeBorder, pIRange, xlEdgeBottom)
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetBorderAttr, xbx, xlDouble, xlThick, $RGB(255,0,0)
    ICall xbx::Border.Release
    mov xbx, $OCall($ObjTmpl(ExcelHost)::ExcelHost.GetRangeBorder, pIRange, xlEdgeLeft)
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetBorderAttr, xbx, xlDouble, xlThick, $RGB(255,0,0)
    ICall xbx::Border.Release

    ;***** Set the Range Interior *****
    mov xbx, $OCall($ObjTmpl(ExcelHost)::ExcelHost.GetInterior, pIRange)
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetInteriorAttr, xbx, $RGB(250,128,128), xlPatternLightDown, $RGB(0,0,255)
    ICall xbx::Interior.Release

    ;***** Set the Range Font *****
    mov xbx, $OCall($ObjTmpl(ExcelHost)::ExcelHost.GetFont, pIRange)
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetFontAttr, xbx, $OfsCBStr("Arial"), XlFontStyleItalic or XlFontStyleBold, 20, $RGB(255,0,0), xlUnderlineStyleSingle
    ICall xbx::Font.Release

    ICall pIRange::IUnknown.Release

    ;***** Format Rows and Columns *****
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetColumnWidth, pISheet, $OfsCBStr("C:E"), 20.0
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetRowHeight, pISheet, $OfsCBStr("3:5"), 40.0

    ;******************************
    ;***** Create a new Chart *****
    ;******************************
    mov pIChart, $OCall($ObjTmpl(ExcelHost)::ExcelHost.NewChart, xlXYScatterLinesNoMarkers, xlLocationAsObject, $OfsCBStr("My Worksheet"))

    ;***** Fill the Chart data range *****
    mov pIRange, $OCall($ObjTmpl(ExcelHost)::ExcelHost.GetRange, pISheet, $OfsCBStr("A7:B36"))
    mov ebx, 1
    lea xdi, BStrBuffer.cBuffer
    .while ebx <= 30
      invoke dword2dec, xdi, ebx
      mov BStrBuffer.dByteSize, eax                     ;Set BStr size
      OCall $ObjTmpl(ExcelHost)::ExcelHost.SetCell, pIRange, ebx, 1, xdi
      lea eax, [2*ebx]
      invoke dword2dec, xdi, eax
      mov BStrBuffer.dByteSize, eax                     ;Set BStr size
      OCall $ObjTmpl(ExcelHost)::ExcelHost.SetCell, pIRange, ebx, 2, xdi
      inc ebx
    .endw

    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetChartData, pIChart, pIRange, xlColumns

    ;***** Set Chart Title *****
    OCall $ObjTmpl(ExcelHost)::ExcelHost.HasChartTitle, pIChart, TRUE
    mov xdi, $OCall($ObjTmpl(ExcelHost)::ExcelHost.GetChartTitle, pIChart)
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetChartTitleText, xdi, $OfsCBStr("My Chart")

    ;***** Format Chart Title *****
    mov xbx, $OCall($ObjTmpl(ExcelHost)::ExcelHost.GetFont, xdi)
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetFontAttr, xbx, $OfsCBStr("Arial"), 0, 14, $RGB(127,127,127), xlUnderlineStyleSingle
    ICall xbx::Font.Release
    mov xbx, $OCall($ObjTmpl(ExcelHost)::ExcelHost.GetInterior, xdi)
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetInteriorAttr, xbx, $RGB(210,210,210), xlPatternSolid, $RGB(0,0,0)
    ICall xbx::Interior.Release
    mov xbx, $OCall($ObjTmpl(ExcelHost)::ExcelHost.GetBorder, xdi)
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetBorderAttr, xbx, xlNone, xlThin, $RGB(127,127,127)
    ICall xbx::Border.Release
    ICall xdi::ChartTitle.Release

    ;***** Format Chart Area *****
    mov xdi, $OCall($ObjTmpl(ExcelHost)::ExcelHost.GetChartArea, pIChart)
    mov xbx, $OCall($ObjTmpl(ExcelHost)::ExcelHost.GetInterior, xdi)
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetInteriorAttr, xbx, $RGB(200,200,200), xlPatternSolid, $RGB(0,0,0)
    ICall xbx::Interior.Release
    mov xbx, $OCall($ObjTmpl(ExcelHost)::ExcelHost.GetBorder, xdi)
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetBorderAttr, xbx, xlContinuous, xlThin, $RGB(127,127,127)
    ICall xbx::Border.Release
    ICall xdi::ChartArea.Release

    ;***** Format Chart Plot Area *****
    mov xdi, $OCall($ObjTmpl(ExcelHost)::ExcelHost.GetChartPlotArea, pIChart)
    mov xbx, $OCall($ObjTmpl(ExcelHost)::ExcelHost.GetInterior, xdi)
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetInteriorAttr, xbx, $RGB(255,255,255), xlPatternSolid, $RGB(0,0,0)
    ICall xbx::Interior.Release
    mov xbx, $OCall($ObjTmpl(ExcelHost)::ExcelHost.GetBorder, xdi)
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetBorderAttr, xbx, xlContinuous, xlNormal, $RGB(127,127,127)
    ICall xbx::Border.Release
    ICall xdi::ChartArea.Release

    ;***** Format Chart X-Axis *****
    mov xbx, $OCall($ObjTmpl(ExcelHost)::ExcelHost.GetChartAxis, pIChart, xlCategory, xlPrimary)
    mov xdi, $OCall($ObjTmpl(ExcelHost)::ExcelHost.GetBorder, xbx)
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetBorderAttr, xdi, xlContinuous, xlThin, $RGB(0,0,255)
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetChartAxisValues, xbx, FALSE, $CReal8(0.0), FALSE, $CReal8(10.0)
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetChartAxisAttr, xbx, xlLinear, xlNone, FALSE, xlLow
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetChartAxisTicks, xbx, xlOutside, FALSE, $CReal8(2.0), xlOutside, FALSE, $CReal8(5.0)
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetChartAxisGridlines, xbx, xlMajorGridlines, TRUE, xlContinuous, xlThick, $RGB(0,255,0)
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetChartAxisGridlines, xbx, xlMinorGridlines, TRUE, xlDot, xlThin, $RGB(128,128,128)
    ICall xdi::Border.Release
    ICall xbx::Axis.Release

    ;***** Format Chart Y-Axis *****
    mov xbx, $OCall($ObjTmpl(ExcelHost)::ExcelHost.GetChartAxis, pIChart, xlValue, xlPrimary)
    mov xdi, $OCall($ObjTmpl(ExcelHost)::ExcelHost.GetBorder, xbx)
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetBorderAttr, xdi, xlContinuous, xlThin, $RGB(0,0,255)
    ICall xdi::Border.Release
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetChartAxisValues, xbx, FALSE, $CReal8(0.0), FALSE, $CReal8(15.0)
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetChartAxisAttr, xbx, xlLinear, xlNone, FALSE, xlRight
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetChartAxisTicks, xbx, xlOutside, FALSE, $CReal8(1.0), xlOutside, FALSE, $CReal8(5.0)
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetChartAxisGridlines, xbx, xlMajorGridlines, TRUE, xlContinuous, xlThick, $RGB(0,255,0)
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetChartAxisGridlines, xbx, xlMinorGridlines, TRUE, xlDot, xlThin, $RGB(128,128,128)
    ICall xbx::Axis.Release

    ;***** Format Chart Legend *****
    mov xbx, $OCall($ObjTmpl(ExcelHost)::ExcelHost.GetChartLegend, pIChart)
    mov xdi, $OCall($ObjTmpl(ExcelHost)::ExcelHost.GetBorder, xbx)
    ICall xdi::Border.Release
    mov xdi, $OCall($ObjTmpl(ExcelHost)::ExcelHost.GetInterior, xbx)
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetInteriorAttr, xdi, $RGB(255,255,255), xlPatternSolid, $RGB(0,0,0)
    ICall xdi::Interior.Release
    mov xdi, $OCall($ObjTmpl(ExcelHost)::ExcelHost.GetFont, xbx)
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetFontAttr, xdi, $OfsCBStr("Arial"), 0, 10, $RGB(128,128,128), xlUnderlineStyleNone
    ICall xdi::Font.Release
    ICall xbx::Legend.Release

    ;***** Format Chart Series *****
    mov xbx, $OCall($ObjTmpl(ExcelHost)::ExcelHost.GetChartSeries, pIChart, 1)
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetChartSeriesAttr, xbx, xlDiamond, 7, $RGB(0,127,0), $RGB(0,255,0), TRUE, FALSE
    mov xdi, $OCall($ObjTmpl(ExcelHost)::ExcelHost.GetBorder, xbx)
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetBorderAttr, xdi, xlContinuous, xlNormal, $RGB(0,127,0)
    ICall xdi::Border.Release

    ;***** Set new Chart Series *****
    mov pIRange, $OCall($ObjTmpl(ExcelHost)::ExcelHost.GetRange, pISheet, $OfsCBStr("A7:A36"))
    invoke VariantInit, addr vArray1
    OCall $ObjTmpl(ExcelHost)::ExcelHost.GetRangeArray, pIRange, addr vArray1
    ICall pIRange::Range.Release
    mov pIRange, $OCall($ObjTmpl(ExcelHost)::ExcelHost.GetRange, pISheet, $OfsCBStr("B7:B36"))
    invoke VariantInit, addr vArray2
    OCall $ObjTmpl(ExcelHost)::ExcelHost.GetRangeArray, pIRange, addr vArray2
    ICall pIRange::Range.Release
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetChartSeriesData, xbx, $OfsCBStr('="My Series"'), addr vArray1, addr vArray2
    invoke SafeArrayDestroy, vArray1.pdispVal
    invoke SafeArrayDestroy, vArray2.pdispVal
    ICall xbx::Series.Release

    ;***** Chart Cleanup *****
    ICall pIChart::IUnknown.Release

    ;***** Set Saved flag ******
;      OCall $ObjTmpl(ExcelHost)::ExcelHost.SaveAs, pIBook, $OfsCBStr("TestBook.xls")
    OCall $ObjTmpl(ExcelHost)::ExcelHost.SetSavedFlag, pIBook, TRUE

    invoke MessageBox, 0, $OfsCStr("Press OK to close Excel"), $OfsCStr("Pause"), MB_OK
    ;***** Cleanup *****
    ICall pISheet::IUnknown.Release
    ICall pIBook::IUnknown.Release

    ;***** Quit Excel application *****
    OCall $ObjTmpl(ExcelHost)::ExcelHost.Quit

    ;***** Terminate ExcelHost object *****
    OCall $ObjTmpl(ExcelHost)::ExcelHost.Done
  .else
    invoke MessageBox, 0, $OfsCStr("Failed to open Excel"), offset szError, MB_OK
  .endif

  ;***** OLE / COM cleanup *****
  invoke OleUninitialize

  ;***** ObjAsm cleanup *****
  SysDone

  invoke ExitProcess, 0
start endp

end
