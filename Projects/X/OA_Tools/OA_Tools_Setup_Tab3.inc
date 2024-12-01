; ==================================================================================================
; Title:      OA_Tools_Setup_Tab3.inc
; Author:     G. Friedrich
; Version:    See OA_Tools.asm
; Purpose:    ObjAsm Tools.
; ==================================================================================================



; ==================================================================================================
;    Tab3 implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Tab3.CtlsGet
; Purpose:    Read the setting of all controls.
; Arguments:  None.
; Return:     Nothing.

Method Tab3.CtlsGet, uses xbx xdi xsi
  SetObject xsi
  mov xbx, [xsi].hWnd
  mov xcx, [xsi].pOwner                                 ;xcx -> TabControl
  mov xax, [xcx].$Obj(TabCtrl).pOwner                   ;xax -> OAT_Setup
  mov xdi, [xax].$Obj(OAT_Setup).pOwner                 ;xdi -> Application
  invoke SendDlgItemMessage, xbx, IDC_UDC_NOTIFICATION, BM_GETCOLOR, 0, 0
  mov [xdi].$Obj(Application).Setup.Color.Notification, eax
  invoke SendDlgItemMessage, xbx, IDC_UDC_COMMENT,      BM_GETCOLOR, 0, 0
  mov [xdi].$Obj(Application).Setup.Color.Information, eax
  invoke SendDlgItemMessage, xbx, IDC_UDC_FAILIURE,     BM_GETCOLOR, 0, 0
  mov [xdi].$Obj(Application).Setup.Color.Failure, eax
  invoke SendDlgItemMessage, xbx, IDC_UDC_BKGROUND,     BM_GETCOLOR, 0, 0
  mov [xdi].$Obj(Application).Setup.Color.Bkground, eax

  invoke SendDlgItemMessage, xbx, IDC_UDC_REG_ERROR,    BM_GETCOLOR, 0, 0
  mov [xdi].$Obj(Application).Setup.Color.RegError, eax
  invoke SendDlgItemMessage, xbx, IDC_UDC_REG_WARNING,  BM_GETCOLOR, 0, 0
  mov [xdi].$Obj(Application).Setup.Color.RegWarning, eax
  invoke SendDlgItemMessage, xbx, IDC_UDC_ARG_WARNING,  BM_GETCOLOR, 0, 0
  mov [xdi].$Obj(Application).Setup.Color.ArgWarning, eax
  invoke SendDlgItemMessage, xbx, IDC_UDC_LOC_WARNING,  BM_GETCOLOR, 0, 0
  mov [xdi].$Obj(Application).Setup.Color.LocWarning, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Tab3.CtlsSet
; Purpose:    Set the controls of the setup dialog.
; Arguments:  None.
; Return:     eax = this procedure should return TRUE to direct Windows to set the keyboard focus to
;                   the control specified by hwndFocus. Otherwise, it should return FALSE to prevent
;                   Windows from setting the default keyboard focus.

Method Tab3.CtlsSet, uses xbx xdi xsi
  SetObject xsi
  mov xbx, [xsi].hWnd
  mov xcx, [xsi].pOwner                                 ;xcx -> TabControl
  mov xax, [xcx].$Obj(TabCtrl).pOwner                   ;xax -> OAT_Setup
  mov xdi, [xax].$Obj(OAT_Setup).pOwner                 ;xdi -> Application

  mov eax, [xdi].$Obj(Application).Setup.Color.Notification
  invoke SendDlgItemMessage, xbx, IDC_UDC_NOTIFICATION, BM_SETCOLOR, 0, xax
  mov eax, [xdi].$Obj(Application).Setup.Color.Information
  invoke SendDlgItemMessage, xbx, IDC_UDC_COMMENT,      BM_SETCOLOR, 0, xax
  mov eax, [xdi].$Obj(Application).Setup.Color.Failure
  invoke SendDlgItemMessage, xbx, IDC_UDC_FAILIURE,     BM_SETCOLOR, 0, xax
  mov eax, [xdi].$Obj(Application).Setup.Color.Bkground
  invoke SendDlgItemMessage, xbx, IDC_UDC_BKGROUND,     BM_SETCOLOR, 0, xax

  mov eax, [xdi].$Obj(Application).Setup.Color.RegError
  invoke SendDlgItemMessage, xbx, IDC_UDC_REG_ERROR,    BM_SETCOLOR, 0, xax
  mov eax, [xdi].$Obj(Application).Setup.Color.RegWarning
  invoke SendDlgItemMessage, xbx, IDC_UDC_REG_WARNING,  BM_SETCOLOR, 0, xax
  mov eax, [xdi].$Obj(Application).Setup.Color.ArgWarning
  invoke SendDlgItemMessage, xbx, IDC_UDC_ARG_WARNING,  BM_SETCOLOR, 0, xax
  mov eax, [xdi].$Obj(Application).Setup.Color.LocWarning
  invoke SendDlgItemMessage, xbx, IDC_UDC_LOC_WARNING,  BM_SETCOLOR, 0, xax
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Tab3.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Tab3.OnInitDialog, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[MAX_PATH]:CHR

  SetObject xsi
  mov xbx, [xsi].hWnd
  mov xcx, [xsi].pOwner                                 ;xcx -> TabControl
  mov xax, [xcx].$Obj(TabCtrl).pOwner                   ;xax -> OAT_Setup
  mov xdx, [xax].$Obj(OAT_Setup).pOwner                 ;xdi -> Application
  mov edi, [xdx].$Obj(Application).dLanguage
  lea xbx, cBuffer

  SetItemString IDC_UDC_NOTIFICATION, IDS_TAB3_COLOR_NOTIF
  SetItemString IDC_UDC_COMMENT,      IDS_TAB3_COLOR_COMMENT
  SetItemString IDC_UDC_REG_ERROR,    IDS_TAB3_COLOR_REG_ERROR
  SetItemString IDC_UDC_REG_WARNING,  IDS_TAB3_COLOR_REG_WARNING
  SetItemString IDC_UDC_ARG_WARNING,  IDS_TAB3_COLOR_ARG_WARNING
  SetItemString IDC_UDC_LOC_WARNING,  IDS_TAB3_COLOR_LOC_WARNING
  SetItemString IDC_UDC_FAILIURE,     IDS_TAB3_COLOR_FAILIURE
  SetItemString IDC_UDC_BKGROUND,     IDS_TAB3_COLOR_BKGROUND

  SetItemString IDC_STC_NOTE3,  IDS_TAB3_NOTE

  OCall xsi.CtlsSet

  xor eax, eax                                          ;Return FALSE to prevent Windows from
MethodEnd                                               ;  setting the default keyboard focus.

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Tab3.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Tab3.OnCommand, uses xdi xsi, wParam:WPARAM, lParam:LPARAM
  local CC:CHOOSECOLOR, ColorRef[16]:RGBQUAD

  SetObject xsi
  mov CC.lStructSize, sizeof CC
  m2m CC.hwndOwner, [xsi].hWnd, xax
  m2m CC.hInstance, hInstance, xcx
  mov CC.Flags, CC_RGBINIT; or CC_FULLOPEN
  m2z CC.lCustData
  m2z CC.lpfnHook
  m2z CC.lpTemplateName

  ;Fill 1st part with the COLOR_CONFIG colors
  lea xdi, ColorRef
  mov CC.lpCustColors, xdi
  mov xcx, [xsi].pOwner                                 ;xcx -> TabControl
  mov xdx, [xcx].$Obj(TabCtrl).pOwner                   ;xax -> OAT_Dialog
  mov xax, [xdx].$Obj(OAT_Setup).pOwner                 ;xdi -> Application

  lea xdx, [xax].$Obj(Application).Setup.Color
  invoke MemClone, xdi, xdx, sizeof ColorData

  ;Fill the 2 remaining colors with white
  lea xdi, ColorRef + 6*sizeof DWORD
  mov eax, 255
  mov ecx, 3
  rep stosb                                             ;Store B = G = R = eax
  xor eax, eax
  stosb                                                 ;Store alpha = 0
  mov eax, 255
  mov ecx, 3
  rep stosb                                             ;Store B = G = R = eax
  xor eax, eax
  stosb                                                 ;Store alpha = 0

  ;Fill 2nd part with a gray scale
  mov edx, 255*256
  .repeat
    mov eax, edx
    shr eax, 8                                          ;/256
    mov ecx, 3
    rep stosb                                           ;Store B = G = R = eax
    xor eax, eax
    stosb                                               ;Store alpha = 0
    sub edx, 9325                                       ;int(255 * 256 / 7)
  .until SIGN?

  invoke ChooseColor, addr CC
  .if eax != FALSE
    mov eax, CC.rgbResult
    invoke SendDlgItemMessage, [xsi].hWnd, DWORD ptr wParam, BM_SETCOLOR, 0, xax
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Tab3.OnCtlColorDlg
; Purpose:    Event procedure for WM_CTLCOLORDLG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Brush to paint the background.

Method Tab3.OnCtlColorDlg,, wParam:WPARAM, lParam:LPARAM
  local HC:HIGHCONTRAST
  
  mov HC.cbSize, sizeof HIGHCONTRAST
  invoke SystemParametersInfo, SPI_GETHIGHCONTRAST, sizeof(HIGHCONTRAST), addr HC, 0
  .ifBitSet HC.dwFlags, HCF_HIGHCONTRASTON
    xor eax, eax
  .else
    invoke GetStockObject, WHITE_BRUSH
  .endif
MethodEnd
