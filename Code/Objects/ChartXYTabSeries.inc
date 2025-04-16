; ==================================================================================================
; Title:      ChartXYTabSeries.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of ChartXYTabSeries objects.
; Notes:      Version 1.0.0, August 2021
;               - First release.
; ==================================================================================================



; ==================================================================================================
;    ChartXYTabSeries implementation
; ==================================================================================================

IDD_CHT_SER_XY_TAB                equ   5300
IDC_CHT_SER_XY_NAME_STC           equ   5301
IDC_CHT_SER_XY_NAME_EDT           equ   5302
IDC_CHT_SER_XY_DESC_STC           equ   5303
IDC_CHT_SER_XY_DESC_EDT           equ   5304
IDC_CHT_SER_XY_Y2_CHK             equ   5305
IDC_CHT_SER_XY_LINE_GRP           equ   5310
IDC_CHT_SER_XY_LINE_SHOW_CHK      equ   5311
IDC_CHT_SER_XY_LINE_COLOR_BTN     equ   5312
IDC_CHT_SER_XY_LINE_WIDTH_STC     equ   5313
IDC_CHT_SER_XY_LINE_WIDTH_EDT     equ   5314
IDC_CHT_SER_XY_LINE_WIDTH_UDN     equ   5315
IDC_CHT_SER_XY_LINE_STYLE_STC     equ   5316
IDC_CHT_SER_XY_LINE_STYLE_CBO     equ   5317
IDC_CHT_SER_XY_MARK_GRP           equ   5320
IDC_CHT_SER_XY_MARK_SHOW_CHK      equ   5321
IDC_CHT_SER_XY_MARK_COLOR_B_BTN   equ   5322
IDC_CHT_SER_XY_MARK_COLOR_F_BTN   equ   5323
IDC_CHT_SER_XY_MARK_SIZE_STC      equ   5324
IDC_CHT_SER_XY_MARK_SIZE_EDT      equ   5325
IDC_CHT_SER_XY_MARK_SIZE_UDN      equ   5326
IDC_CHT_SER_XY_MARK_WIDTH_STC     equ   5327
IDC_CHT_SER_XY_MARK_WIDTH_EDT     equ   5328
IDC_CHT_SER_XY_MARK_WIDTH_UDN     equ   5329
IDC_CHT_SER_XY_MARK_TYPE_STC      equ   5330
IDC_CHT_SER_XY_MARK_TYPE_CBO      equ   5331

XY_LINE_WIDTH_MIN    equ   1
XY_LINE_WIDTH_MAX    equ   10

XY_MARKER_SIZE_MIN   equ   1
XY_MARKER_SIZE_MAX   equ   50

; --------------------------------------------------------------------------------------------------
; Method:     ChartXYTabSeries.CtlsGet
; Purpose:    Read the setting of all controls.
; Arguments:  None.
; Return:     Nothing.

Method ChartXYTabSeries.CtlsGet, uses xbx xdi xsi
  local cBuffer[1024]:CHR, dTranslated:DWORD

  SetObject xsi
  lea xbx, cBuffer
  mov xdi, [xsi].pOwner
  assume xdi:$ObjPtr(ChartXYSeries)

  invoke StrDispose, [xdi].pName
  invoke GetDlgItemText, [xsi].hWnd, IDC_CHT_SER_XY_NAME_EDT, xbx, lengthof cBuffer
  .if eax == 0
    xor eax, eax
  .else
    invoke StrNew, xbx
  .endif
  mov [xdi].pName, xax

  invoke StrDispose, [xdi].pDescription
  invoke GetDlgItemText, [xsi].hWnd, IDC_CHT_SER_XY_DESC_EDT, xbx, lengthof cBuffer
  .if eax == 0
    xor eax, eax
  .else
    invoke StrNew, xbx
  .endif
  mov [xdi].pDescription, xax

  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_CHT_SER_XY_Y2_CHK
  .if eax == BST_CHECKED
    BitSet [xdi].dFlags, CHT_SERIES_USE_Y2
  .else
    BitClr [xdi].dFlags, CHT_SERIES_USE_Y2
  .endif

  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_CHT_SER_XY_LINE_SHOW_CHK
  .if eax == BST_CHECKED
    BitSet [xdi].dFlags, CHT_SERIES_SHOW_DEPICTION
  .else
    BitClr [xdi].dFlags, CHT_SERIES_SHOW_DEPICTION
  .endif

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_XY_LINE_COLOR_BTN
  mov [xdi].Setup.LineColor, $32($invoke(SendMessage, xax, BM_GETCOLOR, 0, 0))

  invoke GetDlgItemInt, [xsi].hWnd, IDC_CHT_SER_XY_LINE_WIDTH_EDT, addr dTranslated, FALSE
  .if dTranslated != FALSE
    .if (SDWORD ptr eax >= XY_LINE_WIDTH_MIN) && (SDWORD ptr eax <= XY_LINE_WIDTH_MAX)
      mov [xdi].Setup.dLineWidth, eax
    .endif
  .endif

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_XY_LINE_STYLE_CBO
  mov [xdi].Setup.dLineStyle, $32($invoke(SendMessage, xax, CB_GETCURSEL, 0, 0))

  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_CHT_SER_XY_MARK_SHOW_CHK
  .if eax == BST_CHECKED
    BitSet [xdi].dFlags, CHT_SERIES_SHOW_MARKER
  .else
    BitClr [xdi].dFlags, CHT_SERIES_SHOW_MARKER
  .endif

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_XY_MARK_COLOR_B_BTN
  mov [xdi].Setup.MarkerBorderColor, $32($invoke(SendMessage, xax, BM_GETCOLOR, 0, 0))

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_XY_MARK_COLOR_F_BTN
  mov [xdi].Setup.MarkerFillColor, $32($invoke(SendMessage, xax, BM_GETCOLOR, 0, 0))

  invoke GetDlgItemInt, [xsi].hWnd, IDC_CHT_SER_XY_MARK_SIZE_EDT, addr dTranslated, FALSE
  .if dTranslated != FALSE
    .if (SDWORD ptr eax >= XY_MARKER_SIZE_MIN) && (SDWORD ptr eax <= XY_MARKER_SIZE_MAX)
      mov [xdi].Setup.dMarkerSize, eax
    .endif
  .endif

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_XY_MARK_TYPE_CBO
  mov [xdi].Setup.dMarkerShape, $32($invoke(SendMessage, xax, CB_GETCURSEL, 0, 0))

  invoke GetDlgItemInt, [xsi].hWnd, IDC_CHT_SER_XY_MARK_WIDTH_EDT, addr dTranslated, FALSE
  .if dTranslated != FALSE
    .if (eax >= XY_LINE_WIDTH_MIN) && (eax <= XY_LINE_WIDTH_MAX)
      mov [xdi].Setup.dMarkerBorderWidth, eax
    .endif
  .endif

  assume xdi:NOTHING
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ChartXYTabSeries.CtlsSet
; Purpose:    Set the controls of the setup dialog.
; Arguments:  None.
; Return:     Nothing.

Method ChartXYTabSeries.CtlsSet, uses xbx xdi xsi
  SetObject xsi
  mov xdi, [xsi].pOwner
  assume xdi:$ObjPtr(ChartXYSeries)

  invoke SetDlgItemText, [xsi].hWnd, IDC_CHT_SER_XY_NAME_EDT, [xdi].pName
  invoke SetDlgItemText, [xsi].hWnd, IDC_CHT_SER_XY_DESC_EDT, [xdi].pDescription

  .ifBitSet [xdi].dFlags, CHT_SERIES_USE_Y2
    invoke CheckDlgButton, [xsi].hWnd, IDC_CHT_SER_XY_Y2_CHK, BST_CHECKED
  .else
    invoke CheckDlgButton, [xsi].hWnd, IDC_CHT_SER_XY_Y2_CHK, BST_UNCHECKED
  .endif

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_XY_Y2_CHK
  .ifBitSet [xdi].dFlags, CHT_SERIES_SHOW_Y2_CHK
    invoke ShowWindow, xax, SW_SHOW
  .else
    invoke ShowWindow, xax, SW_HIDE
  .endif

  .ifBitSet [xdi].dFlags, CHT_SERIES_SHOW_DEPICTION
    invoke CheckDlgButton, [xsi].hWnd, IDC_CHT_SER_XY_LINE_SHOW_CHK, BST_CHECKED
  .else
    invoke CheckDlgButton, [xsi].hWnd, IDC_CHT_SER_XY_LINE_SHOW_CHK, BST_UNCHECKED
  .endif
  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_XY_LINE_COLOR_BTN
  invoke SendMessage, xax, BM_SETCOLOR, 0, [xdi].Setup.LineColor

  invoke SetDlgItemInt, [xsi].hWnd, IDC_CHT_SER_XY_LINE_WIDTH_EDT, [xdi].Setup.dLineWidth, FALSE

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_XY_LINE_STYLE_CBO
  mov xbx, xax
  invoke SendMessage, xbx, CB_RESETCONTENT, 0, 0
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Solid")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Dash")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Dot")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Dash-Dot")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Dash-Dot-Dot")
  invoke SendMessage, xbx, CB_SETCURSEL, [xdi].Setup.dLineStyle, 0

  .ifBitSet [xdi].dFlags, CHT_SERIES_SHOW_MARKER
    invoke CheckDlgButton, [xsi].hWnd, IDC_CHT_SER_XY_MARK_SHOW_CHK, BST_CHECKED
  .else
    invoke CheckDlgButton, [xsi].hWnd, IDC_CHT_SER_XY_MARK_SHOW_CHK, BST_UNCHECKED
  .endif

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_XY_MARK_COLOR_B_BTN
  invoke SendMessage, xax, BM_SETCOLOR, 0, [xdi].Setup.MarkerBorderColor

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_XY_MARK_COLOR_F_BTN
  invoke SendMessage, xax, BM_SETCOLOR, 0, [xdi].Setup.MarkerFillColor

  invoke SetDlgItemInt, [xsi].hWnd, IDC_CHT_SER_XY_MARK_SIZE_EDT, [xdi].Setup.dMarkerSize, FALSE

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_XY_MARK_TYPE_CBO
  mov xbx, xax
  invoke SendMessage, xbx, CB_RESETCONTENT, 0, 0
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Square")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Rectangle Horizontal")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Rectangle Vertical")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Circle")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Ellipse Horizontal")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Ellipse Vertical")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Rhombus")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Rhombus Horizontal")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Rhombus Vertical")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Cross")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("4 Point Star")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("8 Point Star")
  invoke SendMessage, xbx, CB_SETCURSEL, [xdi].Setup.dMarkerShape, 0

  invoke SetDlgItemInt, [xsi].hWnd, IDC_CHT_SER_XY_MARK_WIDTH_EDT, [xdi].Setup.dMarkerBorderWidth, FALSE

  assume xdi:NOTHING
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ChartXYTabSeries.Init
; Purpose:    Initialize the ChartXYTabSeries object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> MaskedImageList.
; Return:     Nothing.

Method ChartXYTabSeries.Init, uses xsi, pOwner:POINTER, hParent:HWND, pImageList:$ObjPtr(MaskedImageList)
  SetObject xsi
  TCall xsi::DialogModeless.Init, pOwner, hParent, IDD_CHT_SER_XY_TAB, \
                                  offset $ObjTmpl(Application).hActiveMlsDlg

  OCall pImageList::MaskedImageList.IconLoadResource, $OfsCStr("ICON_SERIESXY")
  mov [xsi].dIconIndex, eax

  ;Create local copies
  ACall xsi.Init, pOwner
  mov xcx, pOwner
  s2s [xsi].LocalSetup, [xcx].$Obj(ChartXYSeries).Setup, xax, xdx, xmm0, xmm1, xmm2
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ChartXYTabSeries.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ChartXYTabSeries.OnCommand, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local ChooseClr:CHOOSECOLOR, ColorRef[16]:DWORD

  SetObject xsi
  .if (WORD ptr wParam == IDC_CHT_SER_XY_LINE_COLOR_BTN) || \
      (WORD ptr wParam == IDC_CHT_SER_XY_MARK_COLOR_B_BTN) || \
      (WORD ptr wParam == IDC_CHT_SER_XY_MARK_COLOR_F_BTN)
    mov xbx, [xsi].pOwner

    ;Launch ChooseColor system dialog
    mov ChooseClr.lStructSize, sizeof ChooseClr
    m2m ChooseClr.hwndOwner, [xsi].hWnd, xdx
    m2m ChooseClr.hInstance, hInstance, xdx
    mov ChooseClr.Flags, CC_RGBINIT; or CC_FULLOPEN
    m2z ChooseClr.lCustData
    m2z ChooseClr.lpfnHook
    m2z ChooseClr.lpTemplateName

    ;Fill 1st part with the CHT_COLOR_CONFIG colors
    lea xdi, ColorRef
    mov ChooseClr.lpCustColors, xdi

    ;Fill other colors
    mov eax, $RGB(255,000,255)
    mov ColorRef[00*sizeof(COLORREF)], $RGB(000,000,000)
    mov ColorRef[01*sizeof(COLORREF)], $RGB(017,017,017)
    mov ColorRef[02*sizeof(COLORREF)], $RGB(034,034,034)
    mov ColorRef[03*sizeof(COLORREF)], $RGB(051,051,051)
    mov ColorRef[04*sizeof(COLORREF)], $RGB(068,068,068)
    mov ColorRef[05*sizeof(COLORREF)], $RGB(085,085,085)
    mov ColorRef[06*sizeof(COLORREF)], $RGB(102,102,102)
    mov ColorRef[07*sizeof(COLORREF)], $RGB(119,119,119)
    mov ColorRef[08*sizeof(COLORREF)], $RGB(136,136,136)
    mov ColorRef[09*sizeof(COLORREF)], $RGB(153,153,153)
    mov ColorRef[10*sizeof(COLORREF)], $RGB(170,170,170)
    mov ColorRef[11*sizeof(COLORREF)], $RGB(187,187,187)
    mov ColorRef[12*sizeof(COLORREF)], $RGB(204,204,204)
    mov ColorRef[13*sizeof(COLORREF)], $RGB(221,221,221)
    mov ColorRef[14*sizeof(COLORREF)], $RGB(239,239,239)
    mov ColorRef[15*sizeof(COLORREF)], $RGB(255,255,255)

    .if DWORD ptr wParam == IDC_CHT_SER_XY_LINE_COLOR_BTN
      lea xbx, [xbx].$Obj(ChartXYSeries).Setup.LineColor
    .elseif DWORD ptr wParam ==  IDC_CHT_SER_XY_MARK_COLOR_B_BTN
      lea xbx, [xbx].$Obj(ChartXYSeries).Setup.MarkerBorderColor
    .else
      lea xbx, [xbx].$Obj(ChartXYSeries).Setup.MarkerFillColor
    .endif

    m2m ChooseClr.rgbResult, COLORREF ptr [xbx], edx
    invoke ChooseColor, addr ChooseClr
    .if eax != FALSE
      invoke GetDlgItem, [xsi].hWnd, DWORD ptr wParam
      mov xcx, xax
      mrm COLORREF ptr [xbx], ChooseClr.rgbResult, eax
      invoke SendMessage, xcx, BM_SETCOLOR, 0, eax
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ChartXYTabSeries.OnCtlColorDlg
; Purpose:    Event procedure for WM_CTLCOLORDLG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Brush to paint the background.

Method ChartXYTabSeries.OnCtlColorDlg,, wParam:WPARAM, lParam:LPARAM
  local HC:HIGHCONTRAST
  
  mov HC.cbSize, sizeof HIGHCONTRAST
  invoke SystemParametersInfo, SPI_GETHIGHCONTRAST, sizeof(HIGHCONTRAST), addr HC, 0
  .ifBitSet HC.dwFlags, HCF_HIGHCONTRASTON
    xor eax, eax
  .else
    invoke GetStockObject, WHITE_BRUSH
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ChartXYTabSeries.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = FALSE.

Method ChartXYTabSeries.OnInitDialog, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi

  ;Set UDN-Controls
  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_XY_LINE_WIDTH_UDN
  invoke SendMessage, xax, UDM_SETRANGE32, XY_LINE_WIDTH_MIN, XY_LINE_WIDTH_MAX

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_XY_MARK_SIZE_UDN
  invoke SendMessage, xax, UDM_SETRANGE32, XY_MARKER_SIZE_MIN, XY_MARKER_SIZE_MAX

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_XY_MARK_WIDTH_UDN
  invoke SendMessage, xax, UDM_SETRANGE32, XY_LINE_WIDTH_MIN, XY_LINE_WIDTH_MAX

  ACall xsi.OnInitDialog, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ChartXYTabSeries.Restore
; Purpose:    Restore original values.
; Arguments:  None.
; Return:     Nothing.

Method ChartXYTabSeries.Restore, uses xsi
  SetObject xsi

  ;Restore from local copies
  ACall xsi.Restore
  mov xcx, [xsi].pOwner
  s2s [xcx].$Obj(ChartXYSeries).Setup, [xsi].LocalSetup, xax, xdx, xmm0, xmm1, xmm2
MethodEnd
