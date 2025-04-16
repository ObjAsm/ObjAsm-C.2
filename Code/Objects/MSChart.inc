; ==================================================================================================
; Title:      MSChartDemo_Main.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm hosting of MSChart objects.
; Notes:      Requires mschrt20.ocx.
;             Version C.1.0, October 2017
;               - First release.
; ==================================================================================================

; Links:
; ------
;http://msdn.microsoft.com/en-us/library/3ks53324(VS.71).aspx     MSChart control reference
;http://groups.google.com/group/comp.os.ms-windows.programmer.win32/msg/09b3e44b5eca25a6
;ATL71.DLL is distributed with the free .NET Framework 1.1.
;There is available a redistributable package:
;Microsoft .NET Framework Version 1.1 Redistributable Package
;http://www.microsoft.com/downloads/details.aspx?FamilyId=262D25E3- F589-4842-8157-034D1E7CF3A3&displaylang=en
;http://msdn.microsoft.com/en-us/library/ms692780(VS.85).aspx     COM ActiveX container
;http://www.developersdex.com/vb/message.asp?p=640&r=6546867      Bug report
;http://msdn.microsoft.com/de-de/library/bb979332.aspx
;C:\WINDOWS\HELP\MSCHRT98.chm                                     Help file
;http://msdn.microsoft.com/en-us/vbrun/ms788708.aspx              MS support commitment for Win7
;http://www.microsoft.com/downloads/details.aspx?familyid=CB824E35-0403-45C4-9E41-459F0EB89E36&displaylang=en
;http://support.microsoft.com/kb/194784                           Controls shipped with VB6.0
;regsvr32 c:\windows\system32\mschrt20.ocx

;Office 2007 => {00024502-0000-0000-C000-000000000046}

; ==================================================================================================
;     Object definitions
; ==================================================================================================

externdef IID_IConnectionPointContainer:GUID
externdef IID_IOleObject:GUID
externdef IID__DMSChart:GUID
externdef IID__DMSChartEvents:GUID

; --------------------------------------------------------------------------------------------------
; Object:  MSChart
; Purpose: Implement a host object for MSChart OCX component.

Object MSChart, MSChartID, WinPrimer
  RedefineMethod    Done
  RedefineMethod    Init,             POINTER

  DefineVariable    pIChart,          POINTER,  NULL
  DefineVariable    pIOleObject,      POINTER,  NULL
  DefineVariable    hATL,        POINTER,  NULL
  DefineVariable    pChartSink,       POINTER,  NULL
  DefineVariable    pIChartEvents,    POINTER,  NULL
  DefineVariable    pIEventsCP,       POINTER,  NULL
  DefineVariable    dEventsCookie,    DWORD,    0
ObjectEnd

; --------------------------------------------------------------------------------------------------
; Object:  IMSChartEvents
; Purpose: Implement a MSChart internally used interface.

Object IMSChartEvents, IMSChartEventsID, IDispatch
  IDispEvent   OLEStartDrag,         00000060Eh,    DISPATCH_METHOD
  IDispEvent   OLEGiveFeedback,      00000060Fh,    DISPATCH_METHOD
  IDispEvent   OLESetData,           000000610h,    DISPATCH_METHOD
  IDispEvent   OLECompleteDrag,      000000611h,    DISPATCH_METHOD
  IDispEvent   OLEDragOver,          000000612h,    DISPATCH_METHOD
  IDispEvent   OLEDragDrop,          000000613h,    DISPATCH_METHOD
  IDispEvent   ChartSelected,        000000001h,    DISPATCH_METHOD
  IDispEvent   TitleSelected,        000000002h,    DISPATCH_METHOD
  IDispEvent   FootnoteSelected,     000000003h,    DISPATCH_METHOD
  IDispEvent   LegendSelected,       000000004h,    DISPATCH_METHOD
  IDispEvent   PlotSelected,         000000005h,    DISPATCH_METHOD
  IDispEvent   AxisSelected,         000000006h,    DISPATCH_METHOD
  IDispEvent   AxisLabelSelected,    000000007h,    DISPATCH_METHOD
  IDispEvent   AxisTitleSelected,    000000008h,    DISPATCH_METHOD
  IDispEvent   PointSelected,        000000009h,    DISPATCH_METHOD
  IDispEvent   PointLabelSelected,   00000000Ah,    DISPATCH_METHOD
  IDispEvent   SeriesSelected,       00000000Bh,    DISPATCH_METHOD
  IDispEvent   ChartActivated,       00000000Dh,    DISPATCH_METHOD
  IDispEvent   TitleActivated,       00000000Eh,    DISPATCH_METHOD
  IDispEvent   FootnoteActivated,    00000000Fh,    DISPATCH_METHOD
  IDispEvent   LegendActivated,      000000010h,    DISPATCH_METHOD
  IDispEvent   PlotActivated,        000000011h,    DISPATCH_METHOD
  IDispEvent   AxisActivated,        000000012h,    DISPATCH_METHOD
  IDispEvent   AxisLabelActivated,   000000013h,    DISPATCH_METHOD
  IDispEvent   AxisTitleActivated,   000000014h,    DISPATCH_METHOD
  IDispEvent   PointActivated,       000000015h,    DISPATCH_METHOD
  IDispEvent   PointLabelActivated,  000000016h,    DISPATCH_METHOD
  IDispEvent   SeriesActivated,      000000017h,    DISPATCH_METHOD
  IDispEvent   AxisUpdated,          00000001Ah,    DISPATCH_METHOD
  IDispEvent   AxisLabelUpdated,     00000001Bh,    DISPATCH_METHOD
  IDispEvent   AxisTitleUpdated,     00000001Ch,    DISPATCH_METHOD
  IDispEvent   ChartUpdated,         00000001Dh,    DISPATCH_METHOD
  IDispEvent   FootnoteUpdated,      00000001Eh,    DISPATCH_METHOD
  IDispEvent   LegendUpdated,        00000001Fh,    DISPATCH_METHOD
  IDispEvent   PlotUpdated,          000000020h,    DISPATCH_METHOD
  IDispEvent   PointUpdated,         000000021h,    DISPATCH_METHOD
  IDispEvent   PointLabelUpdated,    000000022h,    DISPATCH_METHOD
  IDispEvent   SeriesUpdated,        000000023h,    DISPATCH_METHOD
  IDispEvent   TitleUpdated,         000000025h,    DISPATCH_METHOD
  IDispEvent   DataUpdated,          000000026h,    DISPATCH_METHOD
  IDispEvent   DonePainting,         000000027h,    DISPATCH_METHOD
  IDispEvent   Click,                0FFFFFDA8h,    DISPATCH_METHOD
  IDispEvent   DblClick,             0FFFFFDA7h,    DISPATCH_METHOD
  IDispEvent   KeyDown,              0FFFFFDA6h,    DISPATCH_METHOD
  IDispEvent   KeyPress,             0FFFFFDA5h,    DISPATCH_METHOD
  IDispEvent   KeyUp,                0FFFFFDA4h,    DISPATCH_METHOD
  IDispEvent   MouseDown,            0FFFFFDA3h,    DISPATCH_METHOD
  IDispEvent   MouseMove,            0FFFFFDA2h,    DISPATCH_METHOD
  IDispEvent   MouseUp,              0FFFFFDA1h,    DISPATCH_METHOD

  InterfaceMethod   OLEStartDrag,        ptr ptr DataObject, ptr SDWORD
  InterfaceMethod   OLEGiveFeedback,     ptr SDWORD, ptr BOOL
  InterfaceMethod   OLESetData,          ptr ptr DataObject, ptr SWORD
  InterfaceMethod   OLECompleteDrag,     ptr SDWORD
  InterfaceMethod   OLEDragOver,         ptr ptr DataObject, ptr SDWORD, ptr SWORD, ptr SWORD, ptr REAL4, ptr REAL4, ptr SWORD
  InterfaceMethod   OLEDragDrop,         ptr ptr DataObject, ptr SDWORD, ptr SWORD, ptr SWORD, ptr REAL4, ptr REAL4
  InterfaceMethod   ChartSelected,       ptr SWORD, ptr SWORD
  InterfaceMethod   TitleSelected,       ptr SWORD, ptr SWORD
  InterfaceMethod   FootnoteSelected,    ptr SWORD, ptr SWORD
  InterfaceMethod   LegendSelected,      ptr SWORD, ptr SWORD
  InterfaceMethod   PlotSelected,        ptr SWORD, ptr SWORD
  InterfaceMethod   AxisSelected,        ptr SWORD, ptr SWORD, ptr SWORD, ptr SWORD
  InterfaceMethod   AxisLabelSelected,   ptr SWORD, ptr SWORD, ptr SWORD, ptr SWORD, ptr SWORD, ptr SWORD
  InterfaceMethod   AxisTitleSelected,   ptr SWORD, ptr SWORD, ptr SWORD, ptr SWORD
  InterfaceMethod   PointSelected,       ptr SWORD, ptr SWORD, ptr SWORD, ptr SWORD
  InterfaceMethod   PointLabelSelected,  ptr SWORD, ptr SWORD, ptr SWORD, ptr SWORD
  InterfaceMethod   SeriesSelected,      ptr SWORD, ptr SWORD, ptr SWORD
  InterfaceMethod   ChartActivated,      ptr SWORD, ptr SWORD
  InterfaceMethod   TitleActivated,      ptr SWORD, ptr SWORD
  InterfaceMethod   FootnoteActivated,   ptr SWORD, ptr SWORD
  InterfaceMethod   LegendActivated,     ptr SWORD, ptr SWORD
  InterfaceMethod   PlotActivated,       ptr SWORD, ptr SWORD
  InterfaceMethod   AxisActivated,       ptr SWORD, ptr SWORD, ptr SWORD, ptr SWORD
  InterfaceMethod   AxisLabelActivated,  ptr SWORD, ptr SWORD, ptr SWORD, ptr SWORD, ptr SWORD, ptr SWORD
  InterfaceMethod   AxisTitleActivated,  ptr SWORD, ptr SWORD, ptr SWORD, ptr SWORD
  InterfaceMethod   PointActivated,      ptr SWORD, ptr SWORD, ptr SWORD, ptr SWORD
  InterfaceMethod   PointLabelActivated, ptr SWORD, ptr SWORD, ptr SWORD, ptr SWORD
  InterfaceMethod   SeriesActivated,     ptr SWORD, ptr SWORD, ptr SWORD
  InterfaceMethod   AxisUpdated,         ptr SWORD, ptr SWORD, ptr SWORD
  InterfaceMethod   AxisLabelUpdated,    ptr SWORD, ptr SWORD, ptr SWORD, ptr SWORD, ptr SWORD
  InterfaceMethod   AxisTitleUpdated,    ptr SWORD, ptr SWORD, ptr SWORD
  InterfaceMethod   ChartUpdated,        ptr SWORD
  InterfaceMethod   FootnoteUpdated,     ptr SWORD
  InterfaceMethod   LegendUpdated,       ptr SWORD
  InterfaceMethod   PlotUpdated,         ptr SWORD
  InterfaceMethod   PointUpdated,        ptr SWORD, ptr SWORD, ptr SWORD
  InterfaceMethod   PointLabelUpdated,   ptr SWORD, ptr SWORD, ptr SWORD
  InterfaceMethod   SeriesUpdated,       ptr SWORD, ptr SWORD
  InterfaceMethod   TitleUpdated,        ptr SWORD
  InterfaceMethod   DataUpdated,         ptr SWORD, ptr SWORD, ptr SWORD, ptr SWORD, ptr SWORD, ptr SWORD
  InterfaceMethod   DonePainting
  InterfaceMethod   Click
  InterfaceMethod   DblClick
  InterfaceMethod   KeyDown,             ptr SWORD,SWORD
  InterfaceMethod   KeyPress,            ptr SWORD
  InterfaceMethod   KeyUp,               ptr SWORD,SWORD
  InterfaceMethod   MouseDown,           SWORD, SWORD, OLE_XPOS_PIXELS, OLE_YPOS_PIXELS
  InterfaceMethod   MouseMove,           SWORD, SWORD, OLE_XPOS_PIXELS, OLE_YPOS_PIXELS
  InterfaceMethod   MouseUp,             SWORD, SWORD, OLE_XPOS_PIXELS, OLE_YPOS_PIXELS
ObjectEnd


if IMPLEMENT

.code
; ==================================================================================================
;     MSChart implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     MSChart.Done
; Purpose:    Finalize the Host object.
; Arguments:  None.
; Return:     Nothing.

Method MSChart.Done, uses xsi
  SetObject xsi
  .if [xsi].pIEventsCP != NULL
    ICall [xsi].pIEventsCP::IConnectionPoint.Unadvise, [xsi].dEventsCookie
  .endif
  SAFE_RELEASE_AND_NULLIFY [xsi].pIOleObject
  SAFE_RELEASE_AND_NULLIFY [xsi].pIChart
  invoke FreeLibrary, [xsi].hATL
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MSChart.Init
; Purpose:    Initialize the Host object and creates an Excel Application instance.
; Arguments:  Arg1: -> Owner.
; Return:     eax = OBJ_OK if succeeded.

PAtlAxGetControl typedef proto :HWND, :POINTER
PAtlAxWinInit typedef proto

Method MSChart.Init, uses xbx xsi, pOwner:POINTER
  local ClsID:GUID, pIUnknown:POINTER, wCLSID[39]:CHRW, pICPC:POINTER, pAtlAxGetControl:POINTER

  SetObject xsi
  ACall xsi.Init, pOwner, NULL

  invoke LoadLibraryW, $OfsCStrW("Atl110.dll")           ;.NET distro 1.1
  .if xax != NULL
    mov [xsi].hATL, xax
    invoke CLSIDFromProgID, $OfsCStrW("MSChart20Lib.MSChart.2"), addr ClsID
    .if SUCCEEDED(eax)
      invoke StringFromGUID2, addr ClsID, addr wCLSID, lengthof wCLSID

      invoke GetProcAddress, [xsi].hATL, $OfsCStrA("AtlAxWinInit")
      ;Nonzero if the initialization of the control hosting code was successful; otherwise FALSE.
      invoke PAtlAxWinInit ptr xax
      mov xcx, [xsi].pOwner
      mov xbx, [xcx].$Obj(WinPrimer).hWnd
      ;The trick here is to pass the ClassID in form of a wide string as the title parameter
      invoke CreateWindowExW, 0, $OfsCStrW("AtlAxWin110"), addr wCLSID, \
                              WS_CHILD or WS_VISIBLE, 0,0,0,0, xbx, 0, hInstance, 0
      .if xax != 0
        mov [xsi].hWnd, xax
        mov pAtlAxGetControl, $invoke(GetProcAddress, [xsi].hATL, $OfsCStrA("AtlAxGetControl"))
        m2z pIUnknown
        lea xdx, pIUnknown
        invoke PAtlAxGetControl ptr xax, [xsi].hWnd, xdx
        .if SUCCEEDED(eax)
          ICall pIUnknown::IUnknown.QueryInterface, offset IID__DMSChart, addr [xsi].pIChart

          ;Now we need to create the event sink object to get notifications from the chart
          mov [xsi].pIChartEvents, $New(IMSChartEvents)
          mov [xsi].pChartSink, $New(Component)
          OCall xax::Component.Init, xsi, NULL
          mov xax, [xsi].pChartSink
          lea xcx, [xax].$Obj(Component).Interfaces
          OCall xcx::Collection.Insert, [xsi].pIChartEvents
          OCall xax::IMSChartEvents.Init, [xsi].pChartSink, NULL, NULL

          ICall [xsi].pIChart::_DMSChart.QueryInterface, offset IID_IConnectionPointContainer, \
                                                         addr pICPC
          ICall pICPC::IConnectionPointContainer.FindConnectionPoint, offset IID__DMSChartEvents,\
                                                                      addr [xsi].pIEventsCP
          ICall [xsi].pIEventsCP::IConnectionPoint.Advise, [xsi].pIChartEvents, addr [xsi].dEventsCookie
          ICall pICPC::IConnectionPointContainer.Release

          ;We also need an IOleObject interface
          ICall [xsi].pIChart::IUnknown.QueryInterface, offset IID_IOleObject, \
                                                        addr [xsi].pIOleObject
          mov eax, OBJ_OK
        .else
          OCall xsi.ErrorReport, NULL, MSC_INIT_FAILED
        .endif
      .else
        OCall xsi.ErrorReport, NULL, MSC_INIT_FAILED
      .endif
    .else
      OCall xsi.ErrorReport, NULL, MSC_INIT_FAILED
    .endif
  .else
    OCall xsi.ErrorReport, NULL, MSC_INIT_FAILED
  .endif
MethodEnd


; ==================================================================================================
;     IMSChartEvents implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.OLEStartDrag
; Purpose:    MSChart event handler.
; Arguments:  Arg1: -> DataObject.
;             Arg2: Allowed effects.
; Return:     eax = HRESULT.

Method IMSChartEvents.OLEStartDrag, , pDataObject:ptr ptr DataObject, \
                                    pAllowedEffects:ptr SDWORD
  DbgText "IMSChartEvents.OLEStartDrag"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.OLEGiveFeedback
; Purpose:    MSChart event handler.
; Arguments:  Arg1: -> Effect.
;             Arg2: Default cursors.
; Return:     eax = HRESULT.

Method IMSChartEvents.OLEGiveFeedback, , pEffect:ptr SDWORD, pDefaultCursors:ptr BOOL
  DbgText "IMSChartEvents.OLEGiveFeedback"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.OLESetData
; Purpose:    MSChart event handler.
; Arguments:  Arg1: -> DataObject.
;             Arg2: Data format.
; Return:     eax = HRESULT.

Method IMSChartEvents.OLESetData, , pDataObject:ptr ptr DataObject, pDataFormat:ptr SWORD
  DbgText "IMSChartEvents.OLESetData"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.OLECompleteDrag
; Purpose:    MSChart event handler.
; Arguments:  Arg1: -> Effect.
; Return:     eax = HRESULT.

Method IMSChartEvents.OLECompleteDrag, , pEffect:ptr SDWORD
  DbgText "IMSChartEvents.OLECompleteDrag"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.OLEDragOver
; Purpose:    MSChart event handler.
; Arguments:  Arg1: -> DataObject.
;             Arg2: Effect.
;             Arg3: -> Button.
;             Arg4: -> Shift.
; Return:     eax = HRESULT.

Method IMSChartEvents.OLEDragOver, , pDataObject:ptr ptr DataObject, pEffect:ptr SDWORD, \
                                     pButton:ptr SWORD, pShift:ptr SWORD, \
                                     pX:ptr REAL4, pY:ptr REAL4, pState:ptr SWORD
  DbgText "IMSChartEvents.OLEDragOver"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.OLEDragDrop
; Purpose:    MSChart event handler.
; Arguments:  Arg1: -> DataObject.
;             Arg2: Effect.
;             Arg3: -> Button.
;             Arg4: -> Shift.
; Return:     eax = HRESULT.

Method IMSChartEvents.OLEDragDrop, , pDataObject:ptr ptr DataObject, pEffect:ptr SDWORD, \
                                     pButton:ptr SWORD, pShift:ptr SWORD, \
                                     pX:ptr REAL4, pY:ptr REAL4
  DbgText "IMSChartEvents.OLEDragDrop"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.ChartSelected
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Mouse flags.
;             Arg2: [out] -> Cancel flag.
; Return:     eax = HRESULT.

Method IMSChartEvents.ChartSelected, , pMouseFlags:ptr SWORD, pCancel:ptr SWORD
  DbgText "IMSChartEvents.ChartSelected"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.TitleSelected
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Mouse flags.
;             Arg2: [out] -> Cancel flag.
; Return:     eax = HRESULT.

Method IMSChartEvents.TitleSelected, , pMouseFlags:ptr SWORD, pCancel:ptr SWORD
  DbgText "IMSChartEvents.TitleSelected"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.FootnoteSelected
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Mouse flags.
;             Arg2: [out] -> Cancel flag.
; Return:     eax = HRESULT.

Method IMSChartEvents.FootnoteSelected, , pMouseFlags:ptr SWORD, pCancel:ptr SWORD
  DbgText "IMSChartEvents.FootnoteSelected"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.LegendSelected
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Mouse flags.
;             Arg2: [out] -> Cancel flag.
; Return:     eax = HRESULT.

Method IMSChartEvents.LegendSelected, , pMouseFlags:ptr SWORD, pCancel:ptr SWORD
  DbgText "IMSChartEvents.LegendSelected"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.PlotSelected
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Mouse flags.
;             Arg2: [out] -> Cancel flag.
; Return:     eax = HRESULT.

Method IMSChartEvents.PlotSelected, , pMouseFlags:ptr SWORD, pCancel:ptr SWORD
  DbgText "IMSChartEvents.PlotSelected"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.AxisSelected
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Axis ID.
;             Arg2: [in] -> Axis Index.
;             Arg3: [in] -> Mouse flags.
;             Arg4: [out] -> Cancel flag.
; Return:     eax = HRESULT.

Method IMSChartEvents.AxisSelected, , pAxisID:ptr SWORD, pAxisIndex:ptr SWORD, \
                                      pMouseFlags:ptr SWORD, pCancel:ptr SWORD
  DbgText "IMSChartEvents.AxisSelected"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.AxisLabelSelected
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Axis ID.
;             Arg2: [in] -> Axis Index.
;             Arg3: [in] -> Labelset Index.
;             Arg4: [in] -> Label Index.
;             Arg5: [in] -> Mouse flags.
;             Arg6: [out] -> Cancel flag.
; Return:     eax = HRESULT.

Method IMSChartEvents.AxisLabelSelected, , pAxisID:ptr SWORD, pAxisIndex:ptr SWORD, \
                                           pLabelsetIndex:ptr SWORD, pLabelIndex:ptr SWORD, \
                                           pMouseFlags:ptr SWORD, pCancel:ptr SWORD
  DbgText "IMSChartEvents.AxisLabelSelected"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.AxisTitleSelected
; Purpose:    MSChart event handler.
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Axis ID.
;             Arg2: [in] -> Axis Index.
;             Arg3: [in] -> Mouse flags.
;             Arg4: [out] -> Cancel flag.
; Return:     eax = HRESULT.

Method IMSChartEvents.AxisTitleSelected, , pAxisID:ptr SWORD, pAxisIndex:ptr SWORD, \
                                           pMouseFlags:ptr SWORD, pCancel:ptr SWORD
  DbgText "IMSChartEvents.AxisTitleSelected"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.PointSelected
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Series.
;             Arg2: [in] -> Data Point.
;             Arg3: [in] -> Mouse flags.
;             Arg4: [out] -> Cancel flag.
; Return:     eax = HRESULT.

Method IMSChartEvents.PointSelected, , pSeries:ptr SWORD, pDataPoint:ptr SWORD, \
                                       pMouseFlags:ptr SWORD, pCancel:ptr SWORD
  DbgText "IMSChartEvents.PointSelected"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.PointLabelSelected
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Series.
;             Arg2: [in] -> Data Point.
;             Arg3: [in] -> Mouse flags.
;             Arg4: [out] -> Cancel flag.
; Return:     eax = HRESULT.

Method IMSChartEvents.PointLabelSelected, , pSeries:ptr SWORD, pDataPoint:ptr SWORD, \
                                            pMouseFlags:ptr SWORD, pCancel:ptr SWORD
  DbgText "IMSChartEvents.PointLabelSelected"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.SeriesSelected
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Series.
;             Arg2: [in] -> Mouse flags.
;             Arg3: [out] -> Cancel flag.
; Return:     eax = HRESULT.

Method IMSChartEvents.SeriesSelected, , pSeries:ptr SWORD, pMouseFlags:ptr SWORD, pCancel:ptr SWORD
  DbgText "IMSChartEvents.SeriesSelected"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.ChartActivated
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Mouse flags.
;             Arg2: [out] -> Cancel flag.
; Return:     eax = HRESULT.

Method IMSChartEvents.ChartActivated, , pMouseFlags:ptr SWORD, pCancel:ptr SWORD
  DbgText "IMSChartEvents.ChartActivated"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.TitleActivated
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Mouse flags.
;             Arg2: [out] -> Cancel flag.
; Return:     eax = HRESULT.

Method IMSChartEvents.TitleActivated, , pMouseFlags:ptr SWORD, pCancel:ptr SWORD
  DbgText "IMSChartEvents.TitleActivated"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.FootnoteActivated
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Mouse flags.
;             Arg2: [out] -> Cancel flag.
; Return:     eax = HRESULT.

Method IMSChartEvents.FootnoteActivated, , pMouseFlags:ptr SWORD, pCancel:ptr SWORD
  DbgText "IMSChartEvents.FootnoteActivated"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.LegendActivated
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Mouse flags.
;             Arg2: [out] -> Cancel flag.
; Return:     eax = HRESULT.

Method IMSChartEvents.LegendActivated, , pMouseFlags:ptr SWORD, pCancel:ptr SWORD
  DbgText "IMSChartEvents.LegendActivated"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.PlotActivated
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Mouse flags.
;             Arg2: [out] -> Cancel flag.
; Return:     eax = HRESULT.

Method IMSChartEvents.PlotActivated, , pMouseFlags:ptr SWORD, pCancel:ptr SWORD
  DbgText "IMSChartEvents.PlotActivated"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.AxisActivated
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Axis ID.
;             Arg2: [in] -> Axis Index.
;             Arg3: [in] -> Mouse flags.
;             Arg4: [out] -> Cancel flag.
; Return:     eax = HRESULT.

Method IMSChartEvents.AxisActivated, , pAxisID:ptr SWORD, pAxisIndex:ptr SWORD, \
                                       pMouseFlags:ptr SWORD, pCancel:ptr SWORD
  DbgText "IMSChartEvents.AxisActivated"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.AxisLabelActivated
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Axis ID.
;             Arg2: [in] -> Axis Index.
;             Arg3: [in] -> Labelset Index.
;             Arg4: [in] -> Label Index.
;             Arg5: [in] -> Mouse flags.
;             Arg6: [out] -> Cancel flag.
; Return:     eax = HRESULT.

Method IMSChartEvents.AxisLabelActivated, , pAxisID:ptr SWORD, pAxisIndex:ptr SWORD, \
                                            pLabelsetIndex:ptr SWORD, pLabelIndex:ptr SWORD, \
                                            pMouseFlags:ptr SWORD, pCancel:ptr SWORD
  DbgText "IMSChartEvents.AxisLabelActivated"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.AxisTitleActivated
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Axis ID.
;             Arg2: [in] -> Axis Index.
;             Arg3: [in] -> Mouse flags.
;             Arg4: [out] -> Cancel flag.
; Return:     eax = HRESULT.

Method IMSChartEvents.AxisTitleActivated, , pAxisID:ptr SWORD, pAxisIndex:ptr SWORD, \
                                            pMouseFlags:ptr SWORD, pCancel:ptr SWORD
  DbgText "IMSChartEvents.AxisTitleActivated"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.PointActivated
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Series.
;             Arg2: [in] -> Data Point.
;             Arg3: [in] -> Mouse flags.
;             Arg4: [out] -> Cancel flag.
; Return:     eax = HRESULT.

Method IMSChartEvents.PointActivated, , pSeries:ptr SWORD, pDataPoint:ptr SWORD, \
                                        pMouseFlags:ptr SWORD, pCancel:ptr SWORD
  DbgText "IMSChartEvents.PointActivated"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.PointLabelActivated
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Series.
;             Arg2: [in] -> Data Point.
;             Arg3: [in] -> Mouse flags.
;             Arg4: [out] -> Cancel flag.
; Return:     eax = HRESULT.

Method IMSChartEvents.PointLabelActivated, , pSeries:ptr SWORD, pDataPoint:ptr SWORD, \
                                             pMouseFlags:ptr SWORD, pCancel:ptr SWORD
  DbgText "IMSChartEvents.PointLabelActivated"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.SeriesActivated
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Series.
;             Arg2: [in] -> Mouse flags.
;             Arg3: [out] -> Cancel flag.
; Return:     eax = HRESULT.

Method IMSChartEvents.SeriesActivated, , pSeries:ptr SWORD, pMouseFlags:ptr SWORD, \
                                         pCancel:ptr SWORD
  DbgText "IMSChartEvents.SeriesActivated"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.AxisUpdated
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Axis ID.
;             Arg2: [in] -> Axis Index.
;             Arg3: [in] -> Update Flags.
; Return:     eax = HRESULT.

Method IMSChartEvents.AxisUpdated, , pAxisID:ptr SWORD, pAxisIndex:ptr SWORD, \
                                     pUpdateFlags:ptr SWORD
  DbgText "IMSChartEvents.AxisUpdated"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.AxisLabelUpdated
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Axis ID.
;             Arg2: [in] -> Axis Index.
;             Arg3: [in] -> Labelset Index.
;             Arg4: [in] -> Label Index.
;             Arg5: [in] -> Update flags.
; Return:     eax = HRESULT.

Method IMSChartEvents.AxisLabelUpdated, , pAxisID:ptr SWORD, pAxisIndex:ptr SWORD, \
                                          pLabelsetIndex:ptr SWORD, pLabelIndex:ptr SWORD, \
                                          pUpdateFlags:ptr SWORD
  DbgText "IMSChartEvents.AxisLabelUpdated"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.AxisTitleUpdated
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Axis ID.
;             Arg2: [in] -> Axis Index.
;             Arg3: [in] -> Update Flags.
; Return:     eax = HRESULT.

Method IMSChartEvents.AxisTitleUpdated, , pAxisID:ptr SWORD, pAxisIndex:ptr SWORD, \
                                          pUpdateFlags:ptr SWORD
  DbgText "IMSChartEvents.AxisTitleUpdated"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.ChartUpdated
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Update Flags.
; Return:     eax = HRESULT.

Method IMSChartEvents.ChartUpdated, , pUpdateFlags:ptr SWORD
  DbgText "IMSChartEvents.ChartUpdated"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.FootnoteUpdated
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Update Flags.
; Return:     eax = HRESULT.

Method IMSChartEvents.FootnoteUpdated, , pUpdateFlags:ptr SWORD
  DbgText "IMSChartEvents.FootnoteUpdated"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.LegendUpdated
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Update Flags.
; Return:     eax = HRESULT.

Method IMSChartEvents.LegendUpdated, , pUpdateFlags:ptr SWORD
  DbgText "IMSChartEvents.LegendUpdated"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.PlotUpdated
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Update Flags.
; Return:     eax = HRESULT.

Method IMSChartEvents.PlotUpdated, , pUpdateFlags:ptr SWORD
  DbgText "IMSChartEvents.PlotUpdated"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.PointUpdated
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Series.
;             Arg2: [in] -> Data Point.
;             Arg3: [in] -> Update Flags.
; Return:     eax = HRESULT.

Method IMSChartEvents.PointUpdated, , pSeries:ptr SWORD, pDataPoint:ptr SWORD, \
                                      pUpdateFlags:ptr SWORD
  DbgText "IMSChartEvents.PointUpdated"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.PointLabelUpdated
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Series.
;             Arg2: [in] -> Data Point.
;             Arg3: [in] -> Update Flags.
; Return:     eax = HRESULT.

Method IMSChartEvents.PointLabelUpdated, , pSeries:ptr SWORD, pDataPoint:ptr SWORD, \
                                           pUpdateFlags:ptr SWORD
  DbgText "IMSChartEvents.PointLabelUpdated"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.SeriesUpdated
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Series.
;             Arg2: [in] -> Update Flags.
; Return:     eax = HRESULT.

Method IMSChartEvents.SeriesUpdated, , pSeries:ptr SWORD, pUpdateFlags:ptr SWORD
  DbgText "IMSChartEvents.SeriesUpdated"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.TitleUpdated
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Update Flags.
; Return:     eax = HRESULT.

Method IMSChartEvents.TitleUpdated, , pUpdateFlags:ptr SWORD
  DbgText "IMSChartEvents.TitleUpdated"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.DataUpdated
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Row.
;             Arg2: [in] -> Column.
;             Arg3: [in] -> Label Row.
;             Arg4: [in] -> Label Column.
;             Arg5: [in] -> Labelset Index.
;             Arg6: [in] -> Update Flags.
; Return:     eax = HRESULT.

Method IMSChartEvents.DataUpdated, , pRow:ptr SWORD, pColumn:ptr SWORD, pLabelRow:ptr SWORD, \
                                     pLabelColumn:ptr SWORD, pLabelsetIndex:ptr SWORD, \
                                     pUdateFlags:ptr SWORD
  DbgText "IMSChartEvents.DataUpdated"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.DonePainting
; Purpose:    MSChart event handler.
; Arguments:  None.
; Return:     eax = HRESULT.

Method IMSChartEvents.DonePainting
  DbgText "IMSChartEvents.DonePainting"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.Click
; Purpose:    MSChart event handler.
; Arguments:  None.
; Return:     eax = HRESULT.

Method IMSChartEvents.Click
  DbgText "IMSChartEvents.Click"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.DblClick
; Purpose:    MSChart event handler.
; Arguments:  None.
; Return:     eax = HRESULT.

Method IMSChartEvents.DblClick
  DbgText "IMSChartEvents.DblClick"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.KeyDown
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Key Code.
;             Arg2: [in] -> Shift Flags.
; Return:     eax = HRESULT.

Method IMSChartEvents.KeyDown, , pKeyCode:ptr SWORD, pShift:SWORD
  DbgText "IMSChartEvents.KeyDown"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.KeyPress
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Key Ascii.
; Return:     eax = HRESULT.

Method IMSChartEvents.KeyPress, , pKeyAscii:ptr SWORD
  DbgText "IMSChartEvents.KeyPress"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.KeyUp
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Key Code.
;             Arg2: [in] -> Shift Flags.
; Return:     eax = HRESULT.

Method IMSChartEvents.KeyUp, , pKeyCode:ptr SWORD, pShift:SWORD
  DbgText "IMSChartEvents.KeyUp"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.MouseDown
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> pButton.
;             Arg2: [in] -> Shift Flags.
;             Arg3: [in] -> x Position.
;             Arg4: [in] -> y Position.
; Return:     eax = HRESULT.

Method IMSChartEvents.MouseDown, , pButton:SWORD, pShift:SWORD, r4XPos:OLE_XPOS_PIXELS, \
                                   r4YPos:OLE_YPOS_PIXELS
  DbgText "IMSChartEvents.MouseDown"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.MouseMove
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> pButton.
;             Arg2: [in] -> Shift Flags.
;             Arg3: [in] -> x Position.
;             Arg4: [in] -> y Position.
; Return:     eax = HRESULT.

Method IMSChartEvents.MouseMove, , pButton:SWORD, pShift:SWORD, r4XPos:OLE_XPOS_PIXELS, \
                                   r4YPos:OLE_YPOS_PIXELS
  DbgText "IMSChartEvents.MouseMove"
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.MouseUp
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> pButton.
;             Arg2: [in] -> Shift Flags.
;             Arg3: [in] -> x Position.
;             Arg4: [in] -> y Position.
; Return:     eax = HRESULT.

Method IMSChartEvents.MouseUp, , pButton:SWORD, pShift:SWORD, r4XPos:OLE_XPOS_PIXELS, \
                                 r4YPos:OLE_YPOS_PIXELS
  DbgText "IMSChartEvents.MouseUp"
  xor eax, eax                                          ;S_OK
MethodEnd

endif
