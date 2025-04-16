; ==================================================================================================
; Title:      ChartBarTabSeries.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of ChartBarTabSeries objects.
; Notes:      Version 1.0.0, August 2021
;               - First release.
;               - https://devblogs.microsoft.com/oldnewthing/20190221-00/?p=101062
; ==================================================================================================



; ==================================================================================================
;    ChartBarTabSeries implementation
; ==================================================================================================


IDD_CHT_SER_BAR_TAB             equ 5400
IDC_CHT_SER_BAR_NAME_STC        equ 5401
IDC_CHT_SER_BAR_NAME_EDT        equ 5402
IDC_CHT_SER_BAR_DESC_STC        equ 5403
IDC_CHT_SER_BAR_DESC_EDT        equ 5404
IDC_CHT_SER_BAR_WIDTH_STC       equ 5405
IDC_CHT_SER_BAR_WIDTH_EDT       equ 5406
IDC_CHT_SER_BAR_WIDTH_UDN       equ 5407
IDC_CHT_SER_BAR_OFFSET_STC      equ 5408
IDC_CHT_SER_BAR_OFFSET_EDT      equ 5409
IDC_CHT_SER_BAR_OFFSET_UDN      equ 5410
IDC_CHT_SER_BAR_SHOW_CHK        equ 5411
IDC_CHT_SER_BAR_Y2_CHK          equ 5412

IDC_CHT_SER_BAR_LINE_GRP        equ 5420
IDC_CHT_SER_BAR_LINE_COLOR_BTN  equ 5421
IDC_CHT_SER_BAR_LINE_WIDTH_STC  equ 5422
IDC_CHT_SER_BAR_LINE_WIDTH_EDT  equ 5423
IDC_CHT_SER_BAR_LINE_WIDTH_UDN  equ 5424
IDC_CHT_SER_BAR_LINE_STYLE_STC  equ 5425
IDC_CHT_SER_BAR_LINE_STYLE_CBO  equ 5426

IDC_CHT_SER_BAR_FILL_GRP        equ 5430
IDC_CHT_SER_BAR_FILL_FORE_BTN   equ 5431
IDC_CHT_SER_BAR_FILL_BACK_BTN   equ 5432

IDC_CHT_SER_BAR_FILL_STYLE_STC  equ 5433
IDC_CHT_SER_BAR_FILL_STYLE_CBO  equ 5434


BAR_LINE_WIDTH_MIN    equ   1
BAR_LINE_WIDTH_MAX    equ   10

BAR_WIDTH_MIN         equ   1
BAR_WIDTH_MAX         equ   200

BAR_OFFSET_MIN        equ   -1000
BAR_OFFSET_MAX        equ   1000


; --------------------------------------------------------------------------------------------------
; Method:     ChartBarTabSeries.CtlsGet
; Purpose:    Read the setting of all controls.
; Arguments:  None.
; Return:     Nothing.

Method ChartBarTabSeries.CtlsGet, uses xbx xdi xsi
  local cBuffer[1024]:CHR, dTranslated:DWORD

  SetObject xsi
  lea xbx, cBuffer
  mov xdi, [xsi].pOwner
  assume xdi:$ObjPtr(ChartBarSeries)

  invoke StrDispose, [xdi].pName
  invoke GetDlgItemText, [xsi].hWnd, IDC_CHT_SER_BAR_NAME_EDT, xbx, lengthof cBuffer
  .if eax == 0
    xor eax, eax
  .else
    invoke StrNew, xbx
  .endif
  mov [xdi].pName, xax

  invoke StrDispose, [xdi].pDescription
  invoke GetDlgItemText, [xsi].hWnd, IDC_CHT_SER_BAR_DESC_EDT, xbx, lengthof cBuffer
  .if eax == 0
    xor eax, eax
  .else
    invoke StrNew, xbx
  .endif
  mov [xdi].pDescription, xax

  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_CHT_SER_BAR_Y2_CHK
  .if eax == BST_CHECKED
    BitSet [xdi].dFlags, CHT_SERIES_USE_Y2
  .else
    BitClr [xdi].dFlags, CHT_SERIES_USE_Y2
  .endif

  invoke GetDlgItemInt, [xsi].hWnd, IDC_CHT_SER_BAR_WIDTH_EDT, addr dTranslated, FALSE
  .if dTranslated != FALSE
    .if (SDWORD ptr eax >= BAR_WIDTH_MIN) && (SDWORD ptr eax <= BAR_WIDTH_MAX)
      mov [xdi].Setup.dBarWidth, eax
    .endif
  .endif

  invoke GetDlgItemInt, [xsi].hWnd, IDC_CHT_SER_BAR_OFFSET_EDT, addr dTranslated, TRUE
  .if dTranslated != FALSE
    .if (SDWORD ptr eax >= BAR_OFFSET_MIN) && (SDWORD ptr eax <= BAR_OFFSET_MAX)
      mov [xdi].Setup.sdBarOffset, eax
    .endif
  .endif

  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_CHT_SER_BAR_SHOW_CHK
  .if eax == BST_CHECKED
    BitSet [xdi].dFlags, CHT_SERIES_SHOW_DEPICTION
  .else
    BitClr [xdi].dFlags, CHT_SERIES_SHOW_DEPICTION
  .endif

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_BAR_LINE_COLOR_BTN
  mov [xdi].Setup.BorderColor, $32($invoke(SendMessage, xax, BM_GETCOLOR, 0, 0))

  invoke GetDlgItemInt, [xsi].hWnd, IDC_CHT_SER_BAR_LINE_WIDTH_EDT, addr dTranslated, FALSE
  .if dTranslated != FALSE
    .if (SDWORD ptr eax >= BAR_LINE_WIDTH_MIN) && (SDWORD ptr eax <= BAR_LINE_WIDTH_MAX)
      mov [xdi].Setup.dBorderWidth, eax
    .endif
  .endif

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_BAR_LINE_STYLE_CBO
  mov [xdi].Setup.dBorderStyle, $32($invoke(SendMessage, xax, CB_GETCURSEL, 0, 0))

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_BAR_FILL_FORE_BTN
  mov [xdi].Setup.FillColorFore, $32($invoke(SendMessage, xax, BM_GETCOLOR, 0, 0))

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_BAR_FILL_BACK_BTN
  mov [xdi].Setup.FillColorBack, $32($invoke(SendMessage, xax, BM_GETCOLOR, 0, 0))

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_BAR_FILL_STYLE_CBO
  mov [xdi].Setup.dFillStyle, $32($invoke(SendMessage, xax, CB_GETCURSEL, 0, 0))

  assume xdi:NOTHING
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ChartBarTabSeries.CtlsSet
; Purpose:    Set the controls of the setup dialog.
; Arguments:  None.
; Return:     Nothing.

Method ChartBarTabSeries.CtlsSet, uses xbx xdi xsi
  SetObject xsi
  mov xdi, [xsi].pOwner
  assume xdi:$ObjPtr(ChartBarSeries)

  invoke SetDlgItemText, [xsi].hWnd, IDC_CHT_SER_BAR_NAME_EDT, [xdi].pName
  invoke SetDlgItemText, [xsi].hWnd, IDC_CHT_SER_BAR_DESC_EDT, [xdi].pDescription

  .ifBitSet [xdi].dFlags, CHT_SERIES_USE_Y2
    invoke CheckDlgButton, [xsi].hWnd, IDC_CHT_SER_BAR_Y2_CHK, BST_CHECKED
  .else
    invoke CheckDlgButton, [xsi].hWnd, IDC_CHT_SER_BAR_Y2_CHK, BST_UNCHECKED
  .endif

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_BAR_Y2_CHK
  .ifBitSet [xdi].dFlags, CHT_SERIES_SHOW_Y2_CHK
    invoke ShowWindow, xax, SW_SHOW
  .else
    invoke ShowWindow, xax, SW_HIDE
  .endif

  invoke SetDlgItemInt, [xsi].hWnd, IDC_CHT_SER_BAR_WIDTH_EDT, [xdi].Setup.dBarWidth, FALSE

  invoke SetDlgItemInt, [xsi].hWnd, IDC_CHT_SER_BAR_OFFSET_EDT, [xdi].Setup.sdBarOffset, TRUE

  .ifBitSet [xdi].dFlags, CHT_SERIES_SHOW_DEPICTION
    invoke CheckDlgButton, [xsi].hWnd, IDC_CHT_SER_BAR_SHOW_CHK, BST_CHECKED
  .else
    invoke CheckDlgButton, [xsi].hWnd, IDC_CHT_SER_BAR_SHOW_CHK, BST_UNCHECKED
  .endif

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_BAR_LINE_COLOR_BTN
  invoke SendMessage, xax, BM_SETCOLOR, 0, [xdi].Setup.BorderColor

  invoke SetDlgItemInt, [xsi].hWnd, IDC_CHT_SER_BAR_LINE_WIDTH_EDT, [xdi].Setup.dBorderWidth, FALSE

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_BAR_LINE_STYLE_CBO
  mov xbx, xax
  invoke SendMessage, xbx, CB_RESETCONTENT, 0, 0
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Solid")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Dash")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Dot")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Dash-Dot")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Dash-Dot-Dot")
  invoke SendMessage, xbx, CB_SETCURSEL, [xdi].Setup.dBorderStyle, 0

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_BAR_FILL_FORE_BTN
  invoke SendMessage, xax, BM_SETCOLOR, 0, [xdi].Setup.FillColorFore

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_BAR_FILL_BACK_BTN
  invoke SendMessage, xax, BM_SETCOLOR, 0, [xdi].Setup.FillColorBack

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_BAR_FILL_STYLE_CBO
  mov xbx, xax
  invoke SendMessage, xbx, CB_RESETCONTENT, 0, 0
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Hatch Horizontal --")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Hatch Vertical ||||")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Hatch Diagonal \\\")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Hatch Diagonal ///")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Hatch Cross ++")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Hatch Diagonals XX")
  invoke SendMessage, xbx, CB_ADDSTRING, 0, $OfsCStr("Solid")
  invoke SendMessage, xbx, CB_SETCURSEL, [xdi].Setup.dFillStyle, 0

  assume xdi:NOTHING
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ChartBarTabSeries.Init
; Purpose:    Initialize the ChartBarTabSeries object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> MaskedImageList.
; Return:     Nothing.

Method ChartBarTabSeries.Init, uses xsi, pOwner:POINTER, hParent:HWND, pImageList:$ObjPtr(MaskedImageList)
  SetObject xsi
  TCall xsi::DialogModeless.Init, pOwner, hParent, IDD_CHT_SER_BAR_TAB, \
                                  offset $ObjTmpl(Application).hActiveMlsDlg

  OCall pImageList::MaskedImageList.IconLoadResource, $OfsCStr("ICON_SERIESBAR")
  mov [xsi].dIconIndex, eax

  ;Create local copies
  ACall xsi.Init, pOwner
  mov xcx, pOwner
  s2s [xsi].LocalSetup, [xcx].$Obj(ChartBarSeries).Setup, xax, xdx, xmm0, xmm1, xmm2
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ChartBarTabSeries.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ChartBarTabSeries.OnCommand, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local ChooseClr:CHOOSECOLOR, ColorRef[16]:DWORD

  SetObject xsi
  .if (WORD ptr wParam == IDC_CHT_SER_BAR_LINE_COLOR_BTN) || \
      (WORD ptr wParam == IDC_CHT_SER_BAR_FILL_FORE_BTN) || \
      (WORD ptr wParam == IDC_CHT_SER_BAR_FILL_BACK_BTN)
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

    .if DWORD ptr wParam == IDC_CHT_SER_BAR_LINE_COLOR_BTN
      lea xbx, [xbx].$Obj(ChartBarSeries).Setup.BorderColor
    .elseif DWORD ptr wParam ==  IDC_CHT_SER_BAR_FILL_FORE_BTN
      lea xbx, [xbx].$Obj(ChartBarSeries).Setup.FillColorFore
    .else
      lea xbx, [xbx].$Obj(ChartBarSeries).Setup.FillColorBack
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
; Method:     ChartBarTabSeries.OnCtlColorDlg
; Purpose:    Event procedure for WM_CTLCOLORDLG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Brush to paint the background.

Method ChartBarTabSeries.OnCtlColorDlg,, wParam:WPARAM, lParam:LPARAM
  invoke GetStockObject, WHITE_BRUSH
MethodEnd

; --------------------------------------------------------------------------------------------------
; Procedure:  Edit Window Proc
; Purpose:    Alter the default processing to only allow digits 0-9 and minus sign.
; Arguments:  Arg1: Window HANDLE
;             Arg2: Message
;             Arg3: First message parameter.
;             Arg4: Second message parameter.
;             Arg5: Subclass ID.
;             Arg6: Additional parameter.
; Return:     Message result.
; Note:       WM_PASTE is used to paste text from clipboard.

SignedIntegerSubclassProc proc hWnd:HWND, uMsg:UINT, wParam:WPARAM, lParam:LPARAM, \
                               uIdSubclass:UINT_PTR, dwRefData:DWORD_PTR
  local dFirstPos:DWORD, EBT:EDITBALLOONTIP

  ;DbgMessage uMsg
  .if uMsg == WM_NCDESTROY
    invoke RemoveWindowSubclass, hWnd, addr SignedIntegerSubclassProc, uIdSubclass
  .elseif uMsg == WM_CHAR
    invoke DefSubclassProc, hWnd, EM_GETSEL, addr dFirstPos, NULL
    mov xcx, wParam
    .if cx >= ' '                                       ;Let control character through
      .if !(dFirstPos == 0 && cx == '-') && \           ;Let minus through if it is the 1st char
          !(cx >= '0' && cx <= '9')                     ;Let digits pass through
        mov EBT.cbStruct, sizeof(EBT)                   ;Otherwise invalid
        m2m EBT.pszTitle, $OfsCStr("Error"), xax
        m2m EBT.pszText, $OfsCStr("Invalid character"), xax
        mov EBT.ttiIcon, TTI_ERROR
        invoke SendMessage, hWnd, EM_SHOWBALLOONTIP, 0, addr EBT
        invoke MessageBeep, 0
        xor eax, eax
        ret
      .endif
    .endif
  .endif
  invoke DefSubclassProc, hWnd, uMsg, wParam, lParam
  ret
SignedIntegerSubclassProc endp

; --------------------------------------------------------------------------------------------------
; Method:     ChartBarTabSeries.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = FALSE.

Method ChartBarTabSeries.OnInitDialog, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi

  ;Set UDN-Controls
  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_BAR_LINE_WIDTH_UDN
  invoke SendMessage, xax, UDM_SETRANGE32, BAR_LINE_WIDTH_MIN, BAR_LINE_WIDTH_MAX

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_BAR_WIDTH_UDN
  invoke SendMessage, xax, UDM_SETRANGE32, BAR_WIDTH_MIN, BAR_WIDTH_MAX

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_BAR_OFFSET_UDN
  invoke SendMessage, xax, UDM_SETRANGE32, BAR_OFFSET_MIN, BAR_OFFSET_MAX

  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SER_BAR_OFFSET_EDT
  lea xdx, SignedIntegerSubclassProc
  invoke SetWindowSubclass, xax, xdx, 0, 0              ;Allow negative integers

  ACall xsi.OnInitDialog, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ChartBarTabSeries.Restore
; Purpose:    Restore original values.
; Arguments:  None.
; Return:     Nothing.

Method ChartBarTabSeries.Restore, uses xsi
  SetObject xsi

  ;Restore from local copies
  ACall xsi.Restore
  mov xcx, [xsi].pOwner
  s2s [xcx].$Obj(ChartBarSeries).Setup, [xsi].LocalSetup, xax, xdx, xmm0, xmm1, xmm2
MethodEnd
