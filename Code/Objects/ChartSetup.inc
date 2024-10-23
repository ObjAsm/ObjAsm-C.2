; ==================================================================================================
; Title:      ChartSetup.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of ChartSetup objects.
; Notes:      Version C.1.0, August 2021
;               - First release.
; ==================================================================================================



; ==================================================================================================
;    ChartSetup implementation
; ==================================================================================================

STSTYLE   equ   WS_CHILD or WS_VISIBLE or WS_TABSTOP or TCS_TABS or TCS_HOTTRACK

.const
ChartSetupTabCtrl DEF_TABCONTROL {100, STSTYLE, WS_EX_CONTROLPARENT, NULL, {<4,3,268,200>}}

IDD_CHT_SETUP               equ   5000
IDC_CHT_SETUP_BTN_PREVIEW   equ   5001

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartSetup.CtlsGet
; Purpose:    Read the setting of all controls.
; Arguments:  None.
; Return:     Nothing.

Method ChartSetup.CtlsGet, uses xbx xdi xsi
  SetObject xsi
  mov xdi, [xsi].pOwner
  ACall xsi.CtlsGet
  .ifBitSet [xdi].$Obj(ChartWnd).dFlags, CHT_WND_SHOW_GENERAL_TAB
    OCall [xsi].TabGeneral::ChartTabGeneral.CtlsGet
  .endif
  .ifBitSet [xdi].$Obj(ChartWnd).ScaleX.dFlags, CHT_SCALE_SHOW_TAB
    OCall [xsi].TabScaleX::ChartTabScale.CtlsGet
  .endif
  .ifBitSet [xdi].$Obj(ChartWnd).ScaleY1.dFlags, CHT_SCALE_SHOW_TAB
    OCall [xsi].TabScaleY1::ChartTabScale.CtlsGet
  .endif
  .ifBitSet [xdi].$Obj(ChartWnd).ScaleY2.dFlags, CHT_SCALE_SHOW_TAB
    OCall [xsi].TabScaleY2::ChartTabScale.CtlsGet
  .endif
  .ColForEach [xsi].TabSeriesColl, ebx
    OCall xax::ChartTabSeries.CtlsGet
  .ColNext
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartSetup.CtlsSet
; Purpose:    Set the controls of the setup dialog.
; Arguments:  None.
; Return:     eax = this procedure should return TRUE to direct Windows to set the keyboard focus to
;                   the control specified by hwndFocus. Otherwise, it should return FALSE to prevent
;                   Windows from setting the default keyboard focus.

Method ChartSetup.CtlsSet, uses xbx xdi xsi
  SetObject xsi
  ACall xsi.CtlsSet
  mov xdi, [xsi].pOwner
  .ifBitSet [xdi].$Obj(ChartWnd).dFlags, CHT_WND_SHOW_GENERAL_TAB
    OCall [xsi].TabGeneral::ChartTabGeneral.CtlsSet
  .endif
  .ifBitSet [xdi].$Obj(ChartWnd).ScaleX.dFlags, CHT_SCALE_SHOW_TAB
    OCall [xsi].TabScaleX::ChartTabScale.CtlsSet
  .endif
  .ifBitSet [xdi].$Obj(ChartWnd).ScaleY1.dFlags, CHT_SCALE_SHOW_TAB
    OCall [xsi].TabScaleY1::ChartTabScale.CtlsSet
  .endif
  .ifBitSet [xdi].$Obj(ChartWnd).ScaleY2.dFlags, CHT_SCALE_SHOW_TAB
    OCall [xsi].TabScaleY2::ChartTabScale.CtlsSet
  .endif
  .ColForEach [xsi].TabSeriesColl, ebx
    OCall xax::ChartTabSeries.CtlsSet
  .ColNext
  mov eax, TRUE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartSetup.Done
; Purpose:    Finalize the ChartSetup object.
; Arguments:  None.
; Return:     Nothing.

Method ChartSetup.Done, uses xsi
  SetObject xsi
  OCall [xsi].IconImageList::MaskedImageList.Done
  OCall [xsi].TabGeneral::ChartTabGeneral.Done
  OCall [xsi].TabScaleX::ChartTabScale.Done
  OCall [xsi].TabScaleY1::ChartTabScale.Done
  OCall [xsi].TabScaleY2::ChartTabScale.Done
  OCall [xsi].TabSeriesColl::Collection.Done
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartSetup.Init
; Purpose:    Initialaize a ChartSetup object.
; Arguments:  Arg1: -> Owner object (ChartWnd).
;             Arg2: -> Parent window HANDLE.
;             Arg3: ID of the selected chart element.
; Return:     Nothing.

Method ChartSetup.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND, sdSelElementID:DWORD
  SetObject xsi
  ACall xsi.Init, pOwner, hParent, IDD_CHT_SETUP
  m2m [xsi].sdSelElementID, sdSelElementID, eax

  lea xbx, [xsi].IconImageList
  OCall xbx::MaskedImageList.Init, xsi, 16, 16, 10
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_SETUP")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_SCALEX")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_SCALEY1")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_SCALEY2")

  OCall [xsi].TabSeriesColl::Collection.Init, xsi, 2, 1, COL_MAX_CAPACITY
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartSetup.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ChartSetup.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  .if wParam == IDOK
    ;Set current values and exit
    OCall xsi.CtlsGet
    OCall xsi.DestroyDialog, wParam
    OCall [xsi].pOwner::ChartWnd.Refresh

  .elseif wParam == IDCANCEL
    ;Restore previous values and exit
    OCall xsi.Restore
    OCall xsi.DestroyDialog, wParam
    OCall [xsi].pOwner::ChartWnd.Refresh

  .elseif wParam == IDC_CHT_SETUP_BTN_PREVIEW
    ;Set current values and exit
    OCall xsi.CtlsGet
    OCall xsi.CtlsSet                                   ;In case of an invalid setting
    OCall [xsi].pOwner::ChartWnd.Refresh
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartSetup.OnDestroy
; Purpose:    Event procedure for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method ChartSetup.OnDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke SetWindowLongPtr, [xsi].hWnd, DWLP_USER, NULL
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartSetup.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = FALSE.

Method ChartSetup.OnInitDialog, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local CtrlSetup:DEF_TABCONTROL, hWnd:HWND, cBuffer[20]:CHR, pBuffer:PSTRING
  local pSeriesTab:$ObjPtr(ChartTabSeries), pIconImageList:$ObjPtr(MaskedImageList)

  SetObject xsi
  lea xbx, [xsi].TabControl
  mov xdi, [xsi].pOwner
  mov [xsi].dSelTabIndex, 0
  mov [xsi].hSelTabWnd, 0
  mov [xsi].dTabCount, 0
  invoke MemClone, addr CtrlSetup, offset ChartSetupTabCtrl, sizeof DEF_TABCONTROL
  invoke MapDialogRect, [xsi].hWnd, addr CtrlSetup.sdPosX
  OCall xbx::TabCtrl.Init, xsi, [xsi].hWnd, addr [xsi].IconImageList, addr CtrlSetup

  .ifBitSet [xdi].$Obj(ChartWnd).dFlags, CHT_WND_SHOW_GENERAL_TAB
    OCall [xsi].TabGeneral::ChartTabGeneral.Init, xbx, [xsi].pOwner
    OCall [xsi].TabGeneral::ChartTabGeneral.Show
    invoke ShowWindow, [xsi].TabGeneral.hWnd, SW_HIDE
    OCall [xsi].TabControl::TabCtrl.Insert, [xsi].dTabCount, [xsi].TabGeneral.hWnd, \
                                            $OfsCStr("General"), 0
    .if [xsi].sdSelElementID == CHT_ID_NONE || [xsi].sdSelElementID == CHT_ID_PLOT
      mov [xsi].dSelTabIndex, eax
      m2m [xsi].hSelTabWnd, [xsi].TabGeneral.hWnd, ecx
    .endif
    .if eax != -1
      inc [xsi].dTabCount
    .endif
  .endif

  .ifBitSet [xdi].$Obj(ChartWnd).ScaleX.dFlags, CHT_SCALE_SHOW_TAB
    OCall [xsi].TabScaleX::ChartTabScale.Init, xbx, addr [xdi].$Obj(ChartWnd).ScaleX
    OCall [xsi].TabScaleX::ChartTabScale.Show
    invoke ShowWindow, [xsi].TabScaleX.hWnd, SW_HIDE
    OCall [xsi].TabControl::TabCtrl.Insert, [xsi].dTabCount, [xsi].TabScaleX.hWnd, \
                                            $OfsCStr("X"), 1
    .if [xsi].sdSelElementID == CHT_ID_SCALEX
      mov [xsi].dSelTabIndex, eax
      m2m [xsi].hSelTabWnd, [xsi].TabScaleX.hWnd, ecx
    .endif
    .if eax != -1
      inc [xsi].dTabCount
    .endif
  .endif

  .ifBitSet [xdi].$Obj(ChartWnd).ScaleY1.dFlags, CHT_SCALE_SHOW_TAB
    OCall [xsi].TabScaleY1::ChartTabScale.Init, xbx, addr [xdi].$Obj(ChartWnd).ScaleY1
    OCall [xsi].TabScaleY1::ChartTabScale.Show
    invoke ShowWindow, [xsi].TabScaleY1.hWnd, SW_HIDE
    OCall [xsi].TabControl::TabCtrl.Insert, [xsi].dTabCount, [xsi].TabScaleY1.hWnd, \
                                            $OfsCStr("Y1"), 2
    .if [xsi].sdSelElementID == CHT_ID_SCALEY1
      mov [xsi].dSelTabIndex, eax
      m2m [xsi].hSelTabWnd, [xsi].TabScaleY1.hWnd, ecx
    .endif
    .if eax != -1
      inc [xsi].dTabCount
    .endif
  .endif

  .ifBitSet [xdi].$Obj(ChartWnd).ScaleY2.dFlags, CHT_SCALE_SHOW_TAB
    OCall [xsi].TabScaleY2::ChartTabScale.Init, xbx, addr [xdi].$Obj(ChartWnd).ScaleY2
    OCall [xsi].TabScaleY2::ChartTabScale.Show
    invoke ShowWindow, [xsi].TabScaleY2.hWnd, SW_HIDE
    OCall [xsi].TabControl::TabCtrl.Insert, [xsi].dTabCount, [xsi].TabScaleY2.hWnd, \
                                            $OfsCStr("Y2"), 3
    .if [xsi].sdSelElementID == CHT_ID_SCALEY2
      mov [xsi].dSelTabIndex, eax
      m2m [xsi].hSelTabWnd, [xsi].TabScaleY2.hWnd, ecx
    .endif
    .if eax != -1
      inc [xsi].dTabCount
    .endif
  .endif

  mov xcx, [xsi].pOwner
  lea xdi, [xcx].$Obj(ChartWnd).Data
  lea xax, [xsi].IconImageList
  lea xdx, cBuffer
  mov pIconImageList, xax
  mov pBuffer, xdx
  xor ebx, ebx
  .ColForEach [xdi], ebx
    .ifBitSet [xax].$Obj(ChartSeries).dFlags, CHT_SERIES_SHOW_TAB
      OCall xax::ChartSeries.GetSetupDialogTab, [xsi].TabControl.hWnd, pIconImageList
      mov pSeriesTab, xax
      OCall xax::ChartTabSeries.Show
      OCall [xsi].TabSeriesColl::Collection.Insert, pSeriesTab
      invoke ShowWindow, [xax].$Obj(ChartTabSeries).hWnd, SW_HIDE
      lea edx, [ebx + 1]
      invoke dword2dec, pBuffer, edx
      mov xax, pSeriesTab
      OCall [xsi].TabControl::TabCtrl.Insert, [xsi].dTabCount, [xax].$Obj(ChartTabSeries).hWnd, \
                                              pBuffer, [xax].$Obj(ChartTabSeries).dIconIndex
      .if [xsi].sdSelElementID == ebx
        mov [xsi].dSelTabIndex, eax
        mov xcx, pSeriesTab
        m2m [xsi].hSelTabWnd, [xcx].$Obj(ChartTabSeries).hWnd, edx
      .endif
      .if eax != -1
        inc [xsi].dTabCount
      .endif
    .endif
  .ColNext

  .if [xsi].dTabCount != 0
    invoke SendMessage, [xsi].TabControl.hWnd, TCM_SETCURSEL, [xsi].dSelTabIndex, 0
    invoke ShowWindow, [xsi].hSelTabWnd, SW_SHOWDEFAULT
  .endif

  ACall xsi.OnInitDialog, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartSetup.Restore
; Purpose:    Restore original values.
; Arguments:  None.
; Return:     Nothing.

Method ChartSetup.Restore, uses xbx xdi xsi
  SetObject xsi
  mov xdi, [xsi].pOwner
  .ifBitSet [xdi].$Obj(ChartWnd).dFlags, CHT_WND_SHOW_GENERAL_TAB
    OCall [xsi].TabGeneral::ChartTabGeneral.Restore
  .endif
  .ifBitSet [xdi].$Obj(ChartWnd).ScaleX.dFlags, CHT_SCALE_SHOW_TAB
    OCall [xsi].TabScaleX::ChartTabScale.Restore
  .endif
  .ifBitSet [xdi].$Obj(ChartWnd).ScaleY1.dFlags, CHT_SCALE_SHOW_TAB
    OCall [xsi].TabScaleY1::ChartTabScale.Restore
  .endif
  .ifBitSet [xdi].$Obj(ChartWnd).ScaleY2.dFlags, CHT_SCALE_SHOW_TAB
    OCall [xsi].TabScaleY2::ChartTabScale.Restore
  .endif
  .ColForEach [xsi].TabSeriesColl, ebx
    OCall xax::ChartTabSeries.Restore
  .ColNext
MethodEnd
