; ==================================================================================================
; Title:      OA_Tools_Setup_Tab1.inc
; Author:     G. Friedrich
; Version:    See OA_Tools.asm
; Purpose:    ObjAsm Tools.
; ==================================================================================================



; ==================================================================================================
;    Tab1 implementation
; ==================================================================================================

ArgsEnumFontFam struc
  hComboBox   HANDLE    ?
  dHeight     DWORD     ?
ArgsEnumFontFam ends

AddFonts proc hComboBox:HANDLE
  local hScreenDC:HDC, lf:LOGFONT, Args:ArgsEnumFontFam

  mov lf.lfHeight, 0
  mov hScreenDC, $invoke(GetDC, 0)                      ;Grab a HANDLE to the screen's DC

  ;Fix the size of the shown font to 12 points
  invoke GetDeviceCaps, hScreenDC, LOGPIXELSY
  invoke MulDiv, 10, eax, -72
  mov Args.dHeight, eax

  m2m Args.hComboBox, hComboBox, xax

  ;NOTE: Windows 95, 98 and Me requires that the lpLogfont (second) parameter of the
  ;EnumFontFamiliesEx function is non-NULL. This parameter can be NULL on Windows NT/2000.

  mov lf.lfCharSet, DEFAULT_CHARSET
  mov lf.lfFaceName, NULL
  mov lf.lfPitchAndFamily, 0

  ;Enumerate the current screen fonts
  invoke EnumFontFamiliesEx, hScreenDC, addr lf, addr MyEnumFontFamExProc, addr Args, 0

  ;Release the screen's DC
  invoke ReleaseDC, 0, hScreenDC
  ret
AddFonts endp

CB_FontData struc
  cFaceName   CHR LF_FULLFACESIZE dup(?)
  hFont       HANDLE    ?
CB_FontData ends

MyEnumFontFamExProc proc uses xbx xdi xsi, lpelfe:ptr LOGFONT, lpntme:ptr TEXTMETRIC, \
                                           FontType:DWORD, lParam:LPARAM
  mov xbx, lpelfe                                       ;xbx -> ENUMLOGFONTEX structure
  mov xdi, lParam                                       ;xdi -> ArgsEnumFontFam
  .if FontType == TRUETYPE_FONTTYPE
    ;Filter only monospaced fonts (FF_MODERN) and horizontally-oriented fonts (without leading @)
    mov al, [xbx].ENUMLOGFONTEX.elfLogFont.lfPitchAndFamily
    and al, BIT04 or BIT05 or BIT06 or BIT07
    .if al == FF_MODERN
      .if CHR ptr [xbx].ENUMLOGFONTEX.elfFullName != "@"
        ;If the typeface name is not already in the list
        invoke SendMessage, [xdi].ArgsEnumFontFam.hComboBox, CB_FINDSTRINGEXACT, -1, \
                            addr [xbx].ENUMLOGFONTEX.elfFullName
        .if eax == CB_ERR
          ;Add each font to the list box
          mov xsi, $MemAlloc(sizeof CB_FontData)          ;xsi -> CB_FontData
          invoke MemClone, addr [xsi].CB_FontData.cFaceName, \
                           addr [xbx].ENUMLOGFONTEX.elfFullName, LF_FULLFACESIZE

          ;Setup font creation parameters
          m2m [xbx].ENUMLOGFONTEX.elfLogFont.lfHeight, [xdi].ArgsEnumFontFam.dHeight, eax
          mov [xbx].ENUMLOGFONTEX.elfLogFont.lfWidth, 0

          ;Create a new font & store its handle
          invoke CreateFontIndirect, addr [xbx].ENUMLOGFONTEX.elfLogFont
          mov [xsi].CB_FontData.hFont, xax
          invoke SendMessage, [xdi].ArgsEnumFontFam.hComboBox, CB_ADDSTRING, \
                              0, addr [xsi].CB_FontData.cFaceName
        .endif
      .endif
    .endif
  .endif
  mov eax, TRUE
  ret
MyEnumFontFamExProc endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Tab1.CtlsGet
; Purpose:    Read the setting of all controls.
; Arguments:  None.
; Return:     Nothing.

Method Tab1.CtlsGet, uses xbx xdi xsi
  local cBuffer[MAX_PATH]:CHR

  SetObject xsi

  mov xbx, [xsi].hWnd
  mov xcx, [xsi].pOwner                                 ;xcx -> TabControl
  mov xax, [xcx].$Obj(TabCtrl).pOwner                   ;xax -> OAT_Setup
  mov xdi, [xax].$Obj(OAT_Setup).pOwner                 ;xdi -> Application

  .if [xdi].$Obj(Application).Setup.pExternalEditor != NULL
    invoke StrDispose, [xdi].$Obj(Application).Setup.pExternalEditor
  .endif
  invoke GetDlgItemText, xbx, IDC_EDT_EXTERNAL_EDITOR, addr cBuffer, lengthof cBuffer
  mov [xdi].$Obj(Application).Setup.pExternalEditor, $invoke(StrNew, addr cBuffer)

  invoke IsDlgButtonChecked, xbx, IDC_RBN_CRLF
  .if eax != FALSE
    mov eax, 0                                          ;CRLF
  .else
    invoke IsDlgButtonChecked, xbx, IDC_RBN_LF
    .if eax != FALSE
      mov eax, 1                                        ;LF
    .else
      mov eax, 2                                        ;CF
    .endif
  .endif
  mov [xdi].$Obj(Application).Setup.dLineTerminator, eax


  invoke GetDlgItemInt, xbx, IDC_EDT_ZOOM, NULL, FALSE
  mov [xdi].$Obj(Application).Setup.dZoomfactor, eax

  invoke SendMessage, [xsi].hComboBox, CB_GETCURSEL, 0, 0
  .if eax != CB_ERR
    invoke SendMessage, [xsi].hComboBox, CB_GETITEMDATA, eax, 0
    .if xax != CB_ERR
      invoke StrCopy, addr [xdi].$Obj(Application).Setup.cFontFaceName, addr [xax].CB_FontData.cFaceName
    .endif
  .endif

  invoke GetDlgItemInt, xbx, IDC_EDT_FONT_SIZE, NULL, FALSE
  mov [xdi].$Obj(Application).Setup.dFontSize, eax

  invoke IsDlgButtonChecked, xbx, IDC_CHK_CLOSE_NO_FINDING
  mov [xdi].$Obj(Application).Setup.dCloseIfNoFinding, eax

  invoke IsDlgButtonChecked, xbx, IDC_CHK_USE_ANNOTATIONS
  mov [xdi].$Obj(Application).Setup.dUseAnnotations, eax

  invoke IsDlgButtonChecked, xbx, IDC_RBN_32BIT
  .if eax != FALSE
    mov [xdi].$Obj(Application).Setup.dTestBitness, OATF_TEST_32
  .else
    invoke IsDlgButtonChecked, xbx, IDC_RBN_64BIT
    .if eax != FALSE
      mov [xdi].$Obj(Application).Setup.dTestBitness, OATF_TEST_64
    .else
      mov [xdi].$Obj(Application).Setup.dTestBitness, OATF_TEST_MX
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Tab1.CtlsSet
; Purpose:    Set the controls of the setup dialog.
; Arguments:  None.
; Return:     eax = this procedure should return TRUE to direct Windows to set the keyboard focus to
;                   the control specified by hwndFocus. Otherwise, it should return FALSE to prevent
;                   Windows from setting the default keyboard focus.

Method Tab1.CtlsSet, uses xbx xdi xsi
  SetObject xsi

  mov xbx, [xsi].hWnd
  mov xcx, [xsi].pOwner                                 ;xcx -> TabControl
  mov xax, [xcx].$Obj(TabCtrl).pOwner                   ;xax -> OAT_Setup
  mov xdi, [xax].$Obj(OAT_Setup).pOwner                 ;xdi -> Application

  invoke SetDlgItemText, xbx, IDC_EDT_EXTERNAL_EDITOR, [xdi].$Obj(Application).Setup.pExternalEditor
  .if [xdi].$Obj(Application).Setup.dLineTerminator == 1
    mov eax, IDC_RBN_LF
  .elseif [xdi].$Obj(Application).Setup.dLineTerminator == 2
    mov eax, IDC_RBN_CR
  .else
    mov eax, IDC_RBN_CRLF
  .endif
  invoke CheckRadioButton, xbx, IDC_RBN_CRLF, IDC_RBN_CR, eax
  invoke SetDlgItemInt, xbx, IDC_EDT_ZOOM, [xdi].$Obj(Application).Setup.dZoomfactor, FALSE
  invoke SendMessage, [xsi].hComboBox, CB_SELECTSTRING, -1, addr [xdi].$Obj(Application).Setup.cFontFaceName
  invoke SetDlgItemInt, xbx, IDC_EDT_FONT_SIZE, [xdi].$Obj(Application).Setup.dFontSize, FALSE
  invoke CheckDlgButton, xbx, IDC_CHK_CLOSE_NO_FINDING, [xdi].$Obj(Application).Setup.dCloseIfNoFinding
  invoke CheckDlgButton, xbx, IDC_CHK_USE_ANNOTATIONS, [xdi].$Obj(Application).Setup.dUseAnnotations
  xor eax, eax
  .ifBitSet [xdi].$Obj(Application).Setup.dTestBitness, OATF_TEST_32
    mov eax, IDC_RBN_32BIT
  .elseIfBitSet [xdi].$Obj(Application).Setup.dTestBitness, OATF_TEST_64
    mov eax, IDC_RBN_64BIT
  .elseIfBitSet [xdi].$Obj(Application).Setup.dTestBitness, OATF_TEST_MX
    mov eax, IDC_RBN_MIXED
  .endif
  invoke CheckRadioButton, xbx, IDC_RBN_32BIT, IDC_RBN_MIXED, eax
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Tab1.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Tab1.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  local pIShellItem:POINTER, pFileName:PSTRING

  SetObject xsi
  ACall xsi.OnCommand, wParam, lParam
  LoWord(wParam)
  .if ax == IDC_BTN_SEARCH_EDITOR
    mov xdx, [xsi].pOwner                                 ;xcx -> TabCtrl
    mov xcx, [xdx].$Obj(TabCtrl).pOwner                   ;xdx -> OAT_Setup
    OCall xcx::OAT_Setup.GetFileName
    .if xax != NULL
      mov pIShellItem, xax
      ICall pIShellItem::IShellItem.GetDisplayName, SIGDN_FILESYSPATH, addr pFileName
      invoke SetDlgItemText, [xsi].hWnd, IDC_EDT_EXTERNAL_EDITOR, pFileName
      ICall pIShellItem::IShellItem.Release
    .endif
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Tab1.OnCompareItem
; Purpose:    Event procedure for WM_COMPAREITEM message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = comparison result. MUST be -1, 0 or 1 only!

Method Tab1.OnCompareItem,, wParam:WPARAM, lParam:LPARAM
  mov xax, lParam
  invoke StrComp, [xax].COMPAREITEMSTRUCT.itemData1, [xax].COMPAREITEMSTRUCT.itemData2
  test eax, eax
  .if SIGN?
    mov eax, -1
  .elseif !ZERO?
    mov eax, 1
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Tab1.OnCtlColorDlg
; Purpose:    Event procedure for WM_CTLCOLORDLG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Brush to paint the background.

Method Tab1.OnCtlColorDlg,, wParam:WPARAM, lParam:LPARAM
  local HC:HIGHCONTRAST
  
  mov HC.cbSize, sizeof HIGHCONTRAST
  invoke SystemParametersInfo, SPI_GETHIGHCONTRAST, sizeof(HIGHCONTRAST), addr HC, 0
  .ifBitSet HC.dwFlags, HCF_HIGHCONTRASTON
    xor eax, eax
  .else
    invoke GetStockObject, WHITE_BRUSH
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Tab1.OnDestroy
; Purpose:    Event procedure for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Tab1.OnDestroy, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi

  ;Delete each created font object
  invoke SendMessage, [xsi].hComboBox, CB_GETCOUNT, 0, 0
  lea ebx, [eax - 1]
  test ebx, ebx
  .while !SIGN?
    mov xdi, $invoke(SendMessage, [xsi].hComboBox, CB_GETITEMDATA, ebx, 0)
    invoke DeleteObject, [xdi].CB_FontData.hFont
    MemFree xdi
    dec ebx
  .endw

  ACall xsi.OnDestroy, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Tab1.OnDrawItem
; Purpose:    Event procedure for WM_DRAWITEM message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = If message was handled, returns TRUE.

Method Tab1.OnDrawItem, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local hBrush:HBRUSH, hPrevFont:HFONT, dPrevBkMode:DWORD, dPrevColor:DWORD

  SetObject xsi
  mov xdi, lParam                                       ;xdi -> the DRAWITEMSTRUCT structure
  ;Test the identifier of the control that the message is meant for
  .if [xdi].DRAWITEMSTRUCT.CtlID == IDC_CBO_FONTFACE_NAME
    mov xbx, [xdi].DRAWITEMSTRUCT.itemData              ;xbx -> CB_FontData

    ;Erase the background
    .ifBitSet [xdi].DRAWITEMSTRUCT.itemState, ODS_SELECTED
      mov eax, COLOR_HIGHLIGHT
    .else
      mov eax, COLOR_WINDOW
    .endif
    invoke GetSysColor, eax
    mov hBrush, $invoke(CreateSolidBrush, eax)
    invoke FillRect, [xdi].DRAWITEMSTRUCT.hDC, addr [xdi].DRAWITEMSTRUCT.rcItem, hBrush
    invoke DeleteObject, hBrush

    ;Draw the font name
    .if xbx != -1
      mov hPrevFont, $invoke(SelectObject, [xdi].DRAWITEMSTRUCT.hDC, [xbx].CB_FontData.hFont)
      mov dPrevBkMode, $32($invoke(SetBkMode, [xdi].DRAWITEMSTRUCT.hDC, TRANSPARENT))
      .ifBitSet [xdi].DRAWITEMSTRUCT.itemState, ODS_SELECTED
        mov eax, COLOR_HIGHLIGHTTEXT
      .else
        mov eax, COLOR_WINDOWTEXT
      .endif
      invoke GetSysColor, eax
      mov dPrevColor, $32($invoke(SetTextColor, [xdi].DRAWITEMSTRUCT.hDC, eax))

      invoke DrawText, [xdi].DRAWITEMSTRUCT.hDC, addr [xbx].CB_FontData.cFaceName, -1, \
                       addr [xdi].DRAWITEMSTRUCT.rcItem, DT_LEFT or DT_VCENTER or DT_SINGLELINE

      invoke SetTextColor, [xdi].DRAWITEMSTRUCT.hDC, dPrevColor
      invoke SetBkMode, [xdi].DRAWITEMSTRUCT.hDC, dPrevBkMode
      invoke SelectObject, [xdi].DRAWITEMSTRUCT.hDC, hPrevFont
    .endif
    mov eax, TRUE
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Tab1.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Tab1.OnInitDialog, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[MAX_PATH]:CHR

  SetObject xsi
  mov [xsi].hComboBox, $invoke(GetDlgItem, [xsi].hWnd, IDC_CBO_FONTFACE_NAME)
  invoke AddFonts, [xsi].hComboBox

  mov xbx, [xsi].hWnd
  mov xcx, [xsi].pOwner                                 ;xcx -> TabControl
  mov xax, [xcx].$Obj(TabCtrl).pOwner                   ;xax -> OAT_Setup
  mov xdx, [xax].$Obj(OAT_Setup).pOwner                 ;xdi -> Application
  mov edi, [xdx].$Obj(Application).dLanguage
  lea xbx, cBuffer

  SetItemString IDC_GRP_APPLICATION,      IDS_TAB1_APPLICATION
  SetItemString IDC_STC_EXTERNAL_EDITOR,  IDS_TAB1_EXTERNAL_EDITOR
  SetItemString IDC_GRP_LINE_TERMINATOR,  IDS_TAB1_LINE_TERMINATOR
  SetItemString IDC_GRP_WINDOW,           IDS_TAB1_WINDOW
  SetItemString IDC_STC_ZOOM,             IDS_TAB1_ZOOM_FACTOR
  SetItemString IDC_STC_FONTFACE_NAME,    IDS_TAB1_FONTFACE_NAME
  SetItemString IDC_STC_FONT_SIZE,        IDS_TAB1_FONT_SIZE
  SetItemString IDC_GRP_CHECKS,           IDS_TAB1_CHECKS
  SetItemString IDC_CHK_CLOSE_NO_FINDING, IDS_TAB1_CLOSE_NO_FINDINGS
  SetItemString IDC_CHK_USE_ANNOTATIONS,  IDS_TAB1_USE_ANNOTATIONS
  SetItemString IDC_RBN_MIXED,            IDS_TAB1_MIXED

  OCall xsi.CtlsSet

  xor eax, eax                                          ;Return FALSE to prevent Windows from
MethodEnd                                               ;  setting the default keyboard focus.

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Tab1.OnMeasureItem
; Purpose:    Event procedure for WM_MEASUREITEM message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = If message was handled, returns TRUE.

Method Tab1.OnMeasureItem, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local hScreenDC:HDC, hDC:HDC, hPrvFont:HANDLE, lf:LOGFONT, ItemSize:SIZE_

;  DbgText "Tab1.OnMeasureItem"
  mov xdi, lParam                                       ;xdi -> MEASUREITEMSTRUCT structure
  xor eax, eax                                          ;Set exit value

  ;Test the identifier of the control that the message is meant for
  .if [xdi].MEASUREITEMSTRUCT.CtlType == ODT_COMBOBOX
    .if [xdi].MEASUREITEMSTRUCT.CtlID == IDC_CBO_FONTFACE_NAME
      mov xbx, [xdi].MEASUREITEMSTRUCT.itemData         ;xbx -> CB_FontData
      .if [xdi].MEASUREITEMSTRUCT.itemID == -1          ;-1 => edit control
        ;Do nothing and return FALSE
      .else
        ;To measure the size of the text we must select it into a DC
        mov hScreenDC, $invoke(GetDC, 0)
        mov hDC, $invoke(CreateCompatibleDC, hScreenDC)
        mov hPrvFont, $invoke(SelectObject, hDC, [xbx].CB_FontData.hFont)
        invoke GetObject, [xdi].MEASUREITEMSTRUCT.itemData, sizeof LOGFONT, addr lf
        invoke StrLength, xbx
        mov esi, eax
        invoke GetTextExtentPoint32, hDC, xbx, esi, addr ItemSize
        invoke SelectObject, hDC, hPrvFont
        invoke DeleteDC, hDC
        invoke ReleaseDC, 0, hScreenDC

        ;Set the width & height of this item
        mov eax, ItemSize.cx_
        mov ecx, ItemSize.cy
        add ecx, 2                                      ;Add some extra vertical space
        mov [xdi].MEASUREITEMSTRUCT.itemWidth, eax
        mov [xdi].MEASUREITEMSTRUCT.itemHeight, ecx
        mov eax, TRUE                                   ;Return TRUE
      .endif
    .endif
  .endif
MethodEnd
