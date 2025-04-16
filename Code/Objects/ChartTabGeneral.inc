; ==================================================================================================
; Title:      ChartTabGeneral.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of ChartTabGeneral objects.
; Notes:      Version C.1.0, August 2021
;               - First release.
; ==================================================================================================



; ==================================================================================================
;    ChartTabGeneral implementation
; ==================================================================================================


IDD_CHT_GRL_TAB                 equ   5100
IDC_CHT_GRL_COL_GRP             equ   5110
IDC_CHT_GRL_COL_MJR_GRID_BTN    equ   5111
IDC_CHT_GRL_COL_MNR_GRID_BTN    equ   5112
IDC_CHT_GRL_COL_PLOT_AREA_BTN   equ   5113
IDC_CHT_GRL_COL_PLOT_BORDER_BTN equ   5114
IDC_CHT_GRL_COL_SCALES_BTN      equ   5115
IDC_CHT_GRL_COL_PLOT_BCKGND_BTN equ   5116

IDC_CHT_GRL_HELP_TVC            equ   5120


; --------------------------------------------------------------------------------------------------
; Method:     ChartTabGeneral.CtlsGet
; Purpose:    Read the setting of all controls.
; Arguments:  None.
; Return:     Nothing.

Method ChartTabGeneral.CtlsGet, uses xdi xsi
  SetObject xsi
  mov xcx, [xsi].pChartWnd
  lea xdi, [xcx].$Obj(ChartWnd).Colors
  assume xdi:PCHT_COLOR_CONFIG
  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_GRL_COL_MJR_GRID_BTN
  mov [xdi].MjrGrid, $32($invoke(SendMessage, xax, BM_GETCOLOR, 0, 0))
  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_GRL_COL_MNR_GRID_BTN
  mov [xdi].MnrGrid, $32($invoke(SendMessage, xax, BM_GETCOLOR, 0, 0))
  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_GRL_COL_PLOT_AREA_BTN
  mov [xdi].PlotArea, $32($invoke(SendMessage, xax, BM_GETCOLOR, 0, 0))
  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_GRL_COL_PLOT_BORDER_BTN
  mov [xdi].PlotBorder, $32($invoke(SendMessage, xax, BM_GETCOLOR, 0, 0))
  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_GRL_COL_SCALES_BTN
  mov [xdi].Scales, $32($invoke(SendMessage, xax, BM_GETCOLOR, 0, 0))
  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_GRL_COL_PLOT_BCKGND_BTN
  mov [xdi].Background, $32($invoke(SendMessage, xax, BM_GETCOLOR, 0, 0))
  assume xdi:NOTHING
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ChartTabGeneral.CtlsSet
; Purpose:    Set the controls of the setup dialog.
; Arguments:  None.
; Return:     eax = this procedure should return TRUE to direct Windows to set the keyboard focus to
;                   the control specified by hwndFocus. Otherwise, it should return FALSE to prevent
;                   Windows from setting the default keyboard focus.

Method ChartTabGeneral.CtlsSet, uses xdi xsi
  SetObject xsi
  mov xcx, [xsi].pChartWnd
  lea xdi, [xcx].$Obj(ChartWnd).Colors
  assume xdi:PCHT_COLOR_CONFIG
  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_GRL_COL_MJR_GRID_BTN
  invoke SendMessage, xax, BM_SETCOLOR, 0, [xdi].MjrGrid
  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_GRL_COL_MNR_GRID_BTN
  invoke SendMessage, xax, BM_SETCOLOR, 0, [xdi].MnrGrid
  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_GRL_COL_PLOT_AREA_BTN
  invoke SendMessage, xax, BM_SETCOLOR, 0, [xdi].PlotArea
  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_GRL_COL_PLOT_BORDER_BTN
  invoke SendMessage, xax, BM_SETCOLOR, 0, [xdi].PlotBorder
  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_GRL_COL_SCALES_BTN
  invoke SendMessage, xax, BM_SETCOLOR, 0, [xdi].Scales
  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_GRL_COL_PLOT_BCKGND_BTN
  invoke SendMessage, xax, BM_SETCOLOR, 0, [xdi].Background
  assume xdi:NOTHING
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ChartTabGeneral.Init
; Purpose:    Initialize the ChartTabGeneral object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> ChartWnd.
; Return:     Nothing.

Method ChartTabGeneral.Init, uses xbx xsi, pOwner:POINTER, pChartWnd:$ObjPtr(ChartWnd)
  SetObject xsi
  mov xbx, pOwner
  ACall xsi.Init, xbx, [xbx].$Obj(TabCtrl).hWnd, IDD_CHT_GRL_TAB, \
                  offset $ObjTmpl(Application).hActiveMlsDlg
  mrm [xsi].pChartWnd, pChartWnd, xbx

  ;Create local copy
  s2s [xsi].LocalColors, [xbx].$Obj(ChartWnd).Colors, xax, xcx, xdx, xmm0, xmm1, xmm3
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ChartTabGeneral.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ChartTabGeneral.OnCommand, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local ChooseClr:CHOOSECOLOR, ColorRef[16]:DWORD

  SetObject xsi
  .if (WORD ptr wParam >= IDC_CHT_GRL_COL_MJR_GRID_BTN) && \
      (WORD ptr wParam <= IDC_CHT_GRL_COL_PLOT_BCKGND_BTN)
    mov xbx, [xsi].pChartWnd

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
    s2s CHT_COLOR_CONFIG ptr [xdi], [xbx].$Obj(ChartWnd).Colors, xcx, xdx, xmm0, xmm1, xmm3

    ;Fill the 2 remaining colors with pink
    mov eax, $RGB(255,000,255)
    mov ColorRef[06*sizeof(COLORREF)], eax
    mov ColorRef[07*sizeof(COLORREF)], eax

    ;Fill 2nd part with a gray scale
    mov ColorRef[08*sizeof(COLORREF)], $RGB(000,000,000)
    mov ColorRef[09*sizeof(COLORREF)], $RGB(036,036,036)
    mov ColorRef[10*sizeof(COLORREF)], $RGB(073,073,073)
    mov ColorRef[11*sizeof(COLORREF)], $RGB(109,109,109)
    mov ColorRef[12*sizeof(COLORREF)], $RGB(146,146,146)
    mov ColorRef[13*sizeof(COLORREF)], $RGB(182,182,182)
    mov ColorRef[14*sizeof(COLORREF)], $RGB(219,219,219)
    mov ColorRef[15*sizeof(COLORREF)], $RGB(255,255,255)

    .if DWORD ptr wParam == IDC_CHT_GRL_COL_MJR_GRID_BTN
      lea xbx, [xbx].$Obj(ChartWnd).Colors.MjrGrid
    .elseif DWORD ptr wParam ==  IDC_CHT_GRL_COL_MNR_GRID_BTN
      lea xbx, [xbx].$Obj(ChartWnd).Colors.MnrGrid
    .elseif DWORD ptr wParam ==  IDC_CHT_GRL_COL_PLOT_AREA_BTN
      lea xbx, [xbx].$Obj(ChartWnd).Colors.PlotArea
    .elseif DWORD ptr wParam == IDC_CHT_GRL_COL_PLOT_BORDER_BTN
      lea xbx, [xbx].$Obj(ChartWnd).Colors.PlotBorder
    .elseif DWORD ptr wParam == IDC_CHT_GRL_COL_SCALES_BTN
      lea xbx, [xbx].$Obj(ChartWnd).Colors.Scales
    .elseif DWORD ptr wParam == IDC_CHT_GRL_COL_PLOT_BCKGND_BTN
      lea xbx, [xbx].$Obj(ChartWnd).Colors.Background
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
; Method:     ChartTabGeneral.OnCtlColorDlg
; Purpose:    Event procedure for WM_CTLCOLORDLG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Brush to paint the background.

Method ChartTabGeneral.OnCtlColorDlg,, wParam:WPARAM, lParam:LPARAM
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
; Method:     ChartTabGeneral.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = FALSE.

.const
String szHelp,  "[H+2,C#%s,N#%s]", \
                  "General Information{P}", \
                  "[H-2,C#7F7F7F,I]", \
                  "  This setup dialog allows you to{B}", \
                  "modify the chart properties.{P}", \
                  "  Select a tab to get access to{B}", \
                  "each category.{P}"
ExtendString      "  On the bottom of this dialog box {B}", \
                  "you have 3 button. Click the [C#5F5F5F,B]Preview[~]{B}", \
                  "button to visualize your changes.{B}", \
                  "They are not persistant until you{B}", \
                  "hit the [C#5F5F5F,B]OK[~] button.{P}", \
                  "Pressing the [C#5F5F5F,B]Cancel[~] button{B}", \
                  "discards all changes and closes this{B}", \
                  "dialog box.{B}", \
                  "[~]", \
                "[~]"

.code
Method ChartTabGeneral.OnInitDialog, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[1024]:CHR, HC:HIGHCONTRAST
  local cForeColor[DWORD2HEX_MAX_CHARS]:CHR, cBackColor[DWORD2HEX_MAX_CHARS]:CHR
  
  SetObject xsi
  mov HC.cbSize, sizeof HIGHCONTRAST
  invoke SystemParametersInfo, SPI_GETHIGHCONTRAST, sizeof(HIGHCONTRAST), addr HC, 0
  .ifBitSet HC.dwFlags, HCF_HIGHCONTRASTON
    invoke GetSysColor, COLOR_WINDOW
  .else
    mov eax, -1                                         ;White (Tabdialog background ccolor)
  .endif
  invoke dword2hex, addr cBackColor, eax
  invoke GetSysColor, COLOR_WINDOWTEXT
  invoke dword2hex, addr cForeColor, eax
  
  invoke wsprintf, addr cBuffer, addr szHelp, \
                   addr [cForeColor + 2*sizeof(CHR)], addr [cBackColor + 2*sizeof(CHR)]

  mov xbx, $invoke(GetDlgItem, [xsi].hWnd, IDC_CHT_GRL_HELP_TVC)
  invoke SendMessage, xbx, WM_SETTEXT, 0, addr cBuffer

  ACall xsi.OnInitDialog, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ChartTabGeneral.Restore
; Purpose:    Restore original values.
; Arguments:  None.
; Return:     Nothing.

Method ChartTabGeneral.Restore, uses xsi
  ;DbgText "ChartTabGeneral.Restore"
  SetObject xsi
  ;Restore from local copy
  mov xax, [xsi].pChartWnd
  s2s [xax].$Obj(ChartWnd).Colors, [xsi].LocalColors, xcx, xdx, xmm0, xmm1, xmm3
MethodEnd
