; ==================================================================================================
; Title:      MSChartDemo_Main.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm charting demo with MSChart.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


CLSSTYLE equ CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW; or CS_DROPSHADOW

CStr szMSChartDemoApp, "Application"                    ;Creates szMSChartDemoApp string in .const


Object Application, ApplicationID, SdiApp               ;Single Document Interface App.
  RedefineMethod    Done
  RedefineMethod    Init                                ;Init method redefinition
  RedefineMethod    OnSize,         WPARAM, LPARAM
  StaticMethod      Startup

  VirtualEvent      OnCommand,      WM_COMMAND
  VirtualEvent      OnClose,        WM_CLOSE, WM_QUERYENDSESSION
  VirtualEvent      OnPaint,        WM_PAINT
  VirtualEvent      OnEraseBkgnd,   WM_ERASEBKGND

  Embed Chart, MSChart

ObjectEnd                                               ;Ends object definition


Object MSChartAxisFormatDlg, , DialogModal
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    Init,           POINTER, DWORD
  RedefineMethod    OnCommand,      WPARAM, LPARAM
  RedefineMethod    OnDestroy,      WPARAM, LPARAM

  DefineVariable    dAxisID,        DWORD,      0
ObjectEnd


.code

if IMPLEMENT

; ==================================================================================================
;    IMSChartEvents redefinition
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     IMSChartEvents.AxisLabelActivated2
; Purpose:    MSChart event handler.
; Arguments:  Arg1: [in] -> Axis ID.
;             Arg2: [in] -> Axis Index.
;             Arg3: [in] -> Labelset Index.
;             Arg4: [in] -> Label Index.
;             Arg5: [in] -> Mouse flags.
;             Arg6: [out] -> Cancel flag.
; Return:     eax = HRESULT.

Method IMSChartEvents.AxisLabelActivated2, uses xsi, pAxisID:ptr SWORD, pAxisIndex:ptr SWORD, \
                                                     pLabelsetIndex:ptr SWORD, pLabelIndex:ptr SWORD, \
                                                     pMouseFlags:ptr SWORD, pCancel:ptr SWORD
  local AxisFormatDlg:$Obj(MSChartAxisFormatDlg)

  SetObject xsi
  DbgText "IMSChartEvents.AxisLabelActivated2"
  New AxisFormatDlg::MSChartAxisFormatDlg
  mov xdx, [xsi].pOwner
  mov xcx, pAxisID
  movzx eax, WORD ptr [xcx]
  OCall AxisFormatDlg::MSChartAxisFormatDlg.Init, [xdx].$Obj(Component).pOwner, eax
  OCall AxisFormatDlg::MSChartAxisFormatDlg.Show
  OCall AxisFormatDlg::MSChartAxisFormatDlg.Done
  xor eax, eax                                          ;S_OK
MethodEnd

;; --------------------------------------------------------------------------------------------------
;; Method:    IMSChartEvents.DblClick2
;; Purpose:   MSChart event handler.
;; Arguments: None.
;; Return:    eax = HRESULT.
;
;Method IMSChartEvents.DblClick2, uses xbx
;  local CRect:RECT
;
;  DbgText "IMSChartEvents.DblClick"
;  mov xcx, pSelf
;  mov xdx, [xcx].$Obj(IMSChartEvents).pOwner            ;pChartSink
;  mov xbx, [xdx].$Obj(Component).pOwner                 ;MSChart
;  invoke GetClientRect, [xbx].MSChart.hWnd, addr CRect
;  ;This call to show the chart properties only work if the container is in design mode.
;  ;Design mode is checked when the control is created inspecting the container.
;  ICall [xbx].MSChart.pIOleObject::IOleObject.DoVerb, 1, NULL, NULL, 0, [xbx].MSChart.hWnd, \
;                                                      addr CRect
;  DbgComError eax
;  xor eax, eax                                          ;S_OK
;MethodEnd


; ==================================================================================================
;    Application implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     Application.Done
; Purpose:    Finalize the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Done, uses xsi
  SetObject xsi
  OCall [xsi].Chart::MSChart.Done
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.Init
; Purpose:    Initialize the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Init, uses xbx xsi
  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD

  local pIVcPlot:POINTER, pIVcTitle:POINTER
  local pIVcAxis:POINTER, vArg:VARIANT, pIVcAxisTitle:POINTER
  local pIVcFont:POINTER

  local vChartArray:VARIANT, vChartDataX:VARIANT, vChartDataY:VARIANT
  local SAB2:SAFEARRAYBOUND, SAB1:SAFEARRAYBOUND      ;Don't change this order!
  local dIndex2:DWORD, dIndex1:DWORD                  ;Don't change this order!

  SetObject xsi
  ACall xsi.Init

  mov dWndWidth, 500                                  ;Default creation width
  mov dWndHeight, 450                                 ;Default creation height
  mov dWndPosX, $32($invoke(CenterForm, dWndWidth, $32($invoke(GetSystemMetrics, SM_CXSCREEN))))
  mov dWndPosY, $32($invoke(CenterForm, dWndHeight, $32($invoke(GetSystemMetrics, SM_CYSCREEN))))

  invoke CreateWindowEx, WS_EX_LEFT or WS_EX_APPWINDOW, \
                         offset szMSChartDemoApp, offset szAppTitle, WS_OVERLAPPEDWINDOW, \
                         dWndPosX, dWndPosY, dWndWidth, dWndHeight, NULL, NULL, hInstance, pSelf

  OCall [xsi].Chart::MSChart.Init, xsi
  .if eax == OBJ_OK
    ICall [xsi].Chart.pIChart::_DMSChart.put_Repaint, FALSE
;    ICall [xsi].Chart.pIChart::_DMSChart.put_DrawMode, VtChDrawModeBlit

    ;We redefine the AxisLabelActivated method of this MSChart instance
    ;  to provide a new functionality... Axis scale setting.
    Override [xsi].Chart.pIChartEvents::IMSChartEvents.AxisLabelActivated, \
                                        IMSChartEvents.AxisLabelActivated2

    ;To define the data of the Chart, we have to pass to the Chart object a
    ;  SAFEARRAY of VARIANTS containing the data (REAL4)
    m2z SAB1.lLbound
    mov SAB1.cElements, 10
    m2z SAB2.lLbound
    mov SAB2.cElements, 4
    invoke SafeArrayCreate, VT_VARIANT, 2, addr SAB1    ;SafeArrayDestroy
    mov vChartArray.vt, VT_ARRAY or VT_VARIANT
    mov vChartArray.parray, xax

    mov vChartDataX.vt, VT_I4
    mov vChartDataY.vt, VT_I4

    xor ebx, ebx
    .while ebx < 10
      mov dIndex1, ebx

      ;First line - red
      m2z dIndex2
      mov vChartDataX.lVal, ebx
      invoke SafeArrayPutElement, vChartArray.parray, addr dIndex1, addr vChartDataX

      mov dIndex2, 1
      mov vChartDataY.lVal, ebx
      invoke SafeArrayPutElement, vChartArray.parray, addr dIndex1, addr vChartDataY

      ;Second line - blue
      mov dIndex2, 2
      mov vChartDataX.lVal, ebx
      invoke SafeArrayPutElement, vChartArray.parray, addr dIndex1, addr vChartDataX

      mov dIndex2, 3
      lea eax, [2*ebx]
      mov vChartDataY.lVal, eax
      invoke SafeArrayPutElement, vChartArray.parray, addr dIndex1, addr vChartDataY

      inc ebx
    .endw

    ICall [xsi].Chart.pIChart::_DMSChart.put_ChartData, vChartArray
    invoke SafeArrayDestroy, vChartArray.parray

    ;Now we do a bit of customization of our chart
    ICall [xsi].Chart.pIChart::_DMSChart.put_chartType, VtChChartType2dXY  ;VtChChartType3dLine
;      ICall [xsi].Chart.pIChart::_DMSChart.put_AllowSelections, FALSE

    ICall [xsi].Chart.pIChart::_DMSChart.put_TitleText, $OfsCBStr("Water flow")

    ICall [xsi].Chart.pIChart::_DMSChart.get_Title, addr pIVcTitle
    ICall pIVcTitle::IVcTitle.get_VtFont, addr pIVcFont
    ICall pIVcFont::IVcFont.put_Size, 12.0
    ICall pIVcFont::IVcFont.put_Style, VtFontStyleBold
    ICall pIVcFont::IVcFont.put_Effect, VtFontEffectUnderline
    ICall pIVcFont::IVcFont.Release
    ICall pIVcTitle::IVcTitle.Release

    ICall [xsi].Chart.pIChart::_DMSChart.get_Plot, addr pIVcPlot
    ICall pIVcPlot::IVcPlot.put_UniformAxis, FALSE

    ICall pIVcPlot::IVcPlot.get_Axis, VtChAxisIdX, vArg, addr pIVcAxis    ;vArg = dummy
    ICall pIVcAxis::IVcAxis.get_AxisTitle, addr pIVcAxisTitle
    ICall pIVcAxisTitle::IVcAxisTitle.put_Text, $OfsCBStr("Time")
    ICall pIVcAxisTitle::IVcAxisTitle.get_VtFont, addr pIVcFont
    ICall pIVcFont::IVcFont.put_Size, 10.0
    ICall pIVcFont::IVcFont.Release
    ICall pIVcAxisTitle::IVcAxisTitle.Release
    ICall pIVcAxis::IVcAxis.Release

    ICall pIVcPlot::IVcPlot.get_Axis, VtChAxisIdY, vArg, addr pIVcAxis    ;vArg = dummy
    ICall pIVcAxis::IVcAxis.get_AxisTitle, addr pIVcAxisTitle
    ICall pIVcAxisTitle::IVcAxisTitle.put_Text, $OfsCBStr("m^3/hs")
    ICall pIVcAxisTitle::IVcAxisTitle.get_VtFont, addr pIVcFont
    ICall pIVcFont::IVcFont.put_Size, 10.0
    ICall pIVcFont::IVcFont.Release
    ICall pIVcAxisTitle::IVcAxisTitle.Release
    ICall pIVcAxis::IVcAxis.Release

    ICall pIVcPlot::IVcPlot.Release

    ICall [xsi].Chart.pIChart::_DMSChart.put_Repaint, TRUE
    ICall [xsi].Chart.pIChart::_DMSChart.Refresh

  .else
    invoke MessageBox, 0, $OfsCStr("MSChart is not able to initialize"), offset szError, \
                       MB_OK or MB_ICONERROR
  .endif
  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL          ;Show the window
  invoke UpdateWindow, [xsi].hWnd                       ;Update if necessary
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[MAX_PATH]:CHR, Dlg:$Obj(DialogAbout), hIcon:HICON

  SetObject xsi
  mov xax, wParam
  .if ax == IDM_EXIT
    invoke SendMessage, [xsi].hWnd, WM_SYSCOMMAND, SC_CLOSE, NULL
    xor eax, eax

  .elseif ax == IDM_ABOUT
    New Dlg::DialogAbout
    mov hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
    OCall Dlg::DialogAbout.Init, xsi, [xsi].hWnd, hIcon, offset szAboutText
    OCall Dlg::DialogAbout.Show
    OCall Dlg::DialogAbout.Done
    invoke DestroyIcon, hIcon
    xor eax, eax

  .elseif ax == IDM_HELP
    invoke ExpandEnvironmentStrings, $OfsCStr("%OBJASM_PATH%\Help\ObjAsm_Reference_Volume-I.pdf"), \
                                     addr cBuffer, lengthof(cBuffer)
    invoke PdfView, [xsi].hWnd, addr cBuffer, NULL
    xor eax, eax

  .else
    invoke DefWindowProc, [xsi].hWnd, WM_COMMAND, wParam, lParam
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnClose
; Purpose:    Event procedure for WM_CLOSE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnClose, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke MessageBox, [xsi].hWnd, $OfsCStr("Are you sure ?"), $OfsCStr("Application exit"), \
                     MB_YESNO or MB_ICONQUESTION
  .if eax == IDNO
    xor eax, eax
  .else
    invoke DefWindowProc, [xsi].hWnd, WM_CLOSE, wParam, lParam
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnPaint, uses xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, hDC:HDC, Rct:RECT

  SetObject xsi
  mov hDC, $invoke(BeginPaint, [xsi].hWnd, addr PS)

  invoke GetClientRect, [xsi].hWnd, addr Rct
  invoke DrawEdge, hDC, addr Rct, EDGE_SUNKEN, BF_RECT

  invoke EndPaint, [xsi].hWnd, addr PS
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnEraseBkgnd
; Purpose:    Event procedure for WM_ERASEBKGND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = nonzero if the background was erased, otherwise zero.

Method Application.OnEraseBkgnd,, wParam:WPARAM, lParam:LPARAM
  local CRect:RECT

  SetObject xcx
  .if [xcx].Chart.dErrorCode != OBJ_OK
    invoke GetClientRect, [xcx].hWnd, addr CRect
    invoke GetStockObject, GRAY_BRUSH
    invoke FillRect, wParam, addr CRect, xax
  .endif
  mov eax, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnSize, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov xax, lParam
  mov ebx, eax
  and eax, 0000FFFFh
  shr ebx, 16
  invoke MoveWindow, [xsi].Chart.hWnd, 0, 0, eax, ebx, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.Startup
; Purpose:    Register the object class with the OS.
; Arguments:  None.
; Return:     Nothing.

Method Application.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CLSSTYLE
  m2m WC.lpfnWndProc, $MethodAddr(Application.WndProc), xdx
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xdx
  mov WC.hbrBackground, 0
  c2m WC.lpszMenuName, $OfsCStr("MENU_APP")
  c2m WC.lpszClassName, offset szMSChartDemoApp
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd


; ==================================================================================================
;    MSChartAxisFormatDlg implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     MSChartAxisFormatDlg.CtlsGet
; Purpose:    Read the setting of all controls.
; Arguments:  None.
; Return:     Nothing.

Method MSChartAxisFormatDlg.CtlsGet, uses xsi
  local pIVcPlot:POINTER, vArg:VARIANT, pIVcAxis:POINTER, pIVcValueScale:POINTER
  local cNumberBuffer[100]:CHR, r8Value:REAL8

  SetObject xsi
  mov xcx, [xsi].pOwner
  ICall [xcx].$Obj(MSChart).pIChart::_DMSChart.get_Plot, addr pIVcPlot
  ICall pIVcPlot::IVcPlot.get_Axis, [xsi].dAxisID, vArg, addr pIVcAxis
  ICall pIVcAxis::IVcAxis.get_ValueScale, addr pIVcValueScale

  invoke GetDlgItemText, [xsi].hWnd, 1002, addr cNumberBuffer, lengthof cNumberBuffer
  invoke StrToSt0, addr cNumberBuffer
  fstp r8Value
  ICall pIVcValueScale::IVcValueScale.put_Auto, FALSE
  ICall pIVcValueScale::IVcValueScale.put_Minimum, r8Value

  invoke GetDlgItemText, [xsi].hWnd, 1003, addr cNumberBuffer, lengthof cNumberBuffer
  invoke StrToSt0, addr cNumberBuffer
  fstp r8Value
  ICall pIVcValueScale::IVcValueScale.put_Auto, FALSE
  ICall pIVcValueScale::IVcValueScale.put_Maximum, r8Value

  ICall pIVcValueScale::IUnknown.Release
  ICall pIVcAxis::IUnknown.Release
  ICall pIVcPlot::IUnknown.Release

  mov xcx, [xsi].pOwner
  ICall [xcx].$Obj(MSChart).pIChart::_DMSChart.Refresh
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MSChartAxisFormatDlg.CtlsSet
; Purpose:    Set the controls of the setup dialog.
; Arguments:  None.
; Return:     eax = This procedure should return TRUE to direct Windows to set the keyboard focus
;             to the control specified by hwndFocus. Otherwise, it should return FALSE to prevent
;             Windows from setting the default keyboard focus.

Method MSChartAxisFormatDlg.CtlsSet, uses xsi
  local pIVcPlot:POINTER, vArg:VARIANT, pIVcAxis:POINTER, pIVcValueScale:POINTER
  local r8ScaleVal:REAL8, cNumberBuffer[100]:CHR

  SetObject xsi
  mov xcx, [xsi].pOwner
  ICall [xcx].$Obj(MSChart).pIChart::_DMSChart.get_Plot, addr pIVcPlot
  ICall pIVcPlot::IVcPlot.get_Axis, [xsi].dAxisID, vArg, addr pIVcAxis
  ICall pIVcAxis::IVcAxis.get_ValueScale, addr pIVcValueScale

  ICall pIVcValueScale::IVcValueScale.get_Minimum, addr r8ScaleVal
  fld r8ScaleVal
  invoke St0ToStr, addr cNumberBuffer, 0, 8, f_NOR or f_TRIM
  fUnload
  invoke SetDlgItemText, [xsi].hWnd, 1002, addr cNumberBuffer

  ICall pIVcValueScale::IVcValueScale.get_Maximum, addr r8ScaleVal
  fld r8ScaleVal
  invoke St0ToStr, addr cNumberBuffer, 0, 8, f_NOR or f_TRIM
  fUnload
  invoke SetDlgItemText, [xsi].hWnd, 1003, addr cNumberBuffer

  ICall pIVcValueScale::IUnknown.Release
  ICall pIVcAxis::IUnknown.Release
  ICall pIVcPlot::IUnknown.Release

  mov eax, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MSChartAxisFormatDlg.Init
; Purpose:    Initialize a dialog.
; Arguments:  Arg1: -> MSChart object.
;             Arg2: Axis ID.
; Return:     Nothing.

Method MSChartAxisFormatDlg.Init, uses xsi, pOwner:POINTER, dAxisID:DWORD
  SetObject xsi
  m2m [xsi].dAxisID, dAxisID, eax
  mov xax, pOwner
  ACall xsi.Init, xax, [xax].$Obj(MSChart).hWnd, 1000
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MSChartAxisFormatDlg.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method MSChartAxisFormatDlg.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  LoWord(wParam)
  .if ax == IDOK
    OCall xsi.CtlsGet
    OCall xsi.DestroyDialog, wParam
  .elseif ax == IDCANCEL
    OCall xsi.DestroyDialog, wParam
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MSChartAxisFormatDlg.OnDestroy
; Purpose:    Event procedure for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method MSChartAxisFormatDlg.OnDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke SetWindowLongPtr, [xsi].hWnd, DWLP_USER, NULL
MethodEnd

endif
