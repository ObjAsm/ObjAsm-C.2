; ==================================================================================================
; Title:      OA_Tools_Setup_Tab2.inc
; Author:     G. Friedrich
; Version:    See OA_Tools.asm
; Purpose:    ObjAsm Tools.
; ==================================================================================================



; ==================================================================================================
;    Tab2 implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     Tab2.CtlsGet
; Purpose:    Read the setting of all controls.
; Arguments:  None.
; Return:     Nothing.

Method Tab2.CtlsGet, uses xbx xdi xsi
  local cBuffer[MAX_PATH]:CHR

  ANNOTATION use:cBuffer

  SetObject xsi
  mov xbx, [xsi].hWnd
  mov xcx, [xsi].pOwner                                 ;xcx -> TabControl
  mov xax, [xcx].$Obj(TabCtrl).pOwner                   ;xax -> OAT_Setup
  mov xdi, [xax].$Obj(OAT_Setup).pOwner                 ;xdi -> Application
  GetTool 0
  GetTool 1
  GetTool 2
  GetTool 3
  GetTool 4
  GetTool 5
  GetTool 6
  GetTool 7
  GetTool 8
  GetTool 9
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Tab2.CtlsSet
; Purpose:    Set the controls of the setup dialog.
; Arguments:  None.
; Return:     eax = this procedure should return TRUE to direct Windows to set the keyboard focus to
;                   the control specified by hwndFocus. Otherwise, it should return FALSE to prevent
;                   Windows from setting the default keyboard focus.

SetTool macro ID:req
  %invoke SetDlgItemText, xbx, IDC_EDT_NAME_&ID, [xdi].$Obj(Application).Setup.Tool&ID.pName
  %invoke SetDlgItemText, xbx, IDC_EDT_CMD_&ID, [xdi].$Obj(Application).Setup.Tool&ID.pCommand
endm

Method Tab2.CtlsSet, uses xbx xdi xsi
  SetObject xsi
  mov xbx, [xsi].hWnd
  mov xcx, [xsi].pOwner                                 ;xcx -> TabControl
  mov xax, [xcx].$Obj(TabCtrl).pOwner                   ;xax -> OAT_Setup
  mov xdi, [xax].$Obj(OAT_Setup).pOwner                 ;xdi -> Application
  SetTool 0
  SetTool 1
  SetTool 2
  SetTool 3
  SetTool 4
  SetTool 5
  SetTool 6
  SetTool 7
  SetTool 8
  SetTool 9
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Tab2.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

SetToolCommand macro CtlID
  OCall xcx::OAT_Setup.GetFileName
  .if xax != NULL
    mov pIShellItem, xax
    ICall pIShellItem::IShellItem.GetDisplayName, SIGDN_FILESYSPATH, addr pFileName
    invoke SetDlgItemText, [xsi].hWnd, IDC_EDT_CMD_&CtlID, pFileName
    ICall pIShellItem::IShellItem.Release
  .endif
endm

Method Tab2.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  local pIShellItem:POINTER, pFileName:PSTRING
  
  ANNOTATION use:pIShellItem pFileName

  SetObject xsi
  mov xdx, [xsi].pOwner                                 ;xcx -> TabCtrl
  mov xcx, [xdx].$Obj(TabCtrl).pOwner                   ;xdx -> OAT_Setup

  LoWord(wParam)
  .if ax == IDC_BTN_SEARCH_0
    SetToolCommand 0
  .elseif ax == IDC_BTN_SEARCH_1
    SetToolCommand 1
  .elseif ax == IDC_BTN_SEARCH_2
    SetToolCommand 2
  .elseif ax == IDC_BTN_SEARCH_3
    SetToolCommand 3
  .elseif ax == IDC_BTN_SEARCH_4
    SetToolCommand 4
  .elseif ax == IDC_BTN_SEARCH_5
    SetToolCommand 5
  .elseif ax == IDC_BTN_SEARCH_6
    SetToolCommand 6
  .elseif ax == IDC_BTN_SEARCH_7
    SetToolCommand 7
  .elseif ax == IDC_BTN_SEARCH_8
    SetToolCommand 8
  .elseif ax == IDC_BTN_SEARCH_9
    SetToolCommand 9
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Tab2.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Tab2.OnInitDialog, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[MAX_PATH]:CHR

  SetObject xsi
  mov xbx, [xsi].hWnd
  mov xcx, [xsi].pOwner                                 ;xcx -> TabControl
  mov xax, [xcx].$Obj(TabCtrl).pOwner                   ;xax -> OAT_Setup
  mov xdx, [xax].$Obj(OAT_Setup).pOwner                 ;xdi -> Application
  mov edi, [xdx].$Obj(Application).dLanguage
  lea xbx, cBuffer

  SetItemString IDC_STC_TOOL,   IDS_TAB2_TOOL
  SetItemString IDC_STC_NAME,   IDS_TAB2_NAME
  SetItemString IDC_STC_CMD,    IDS_TAB2_COMMAND
  SetItemString IDC_STC_NOTE2,  IDS_TAB2_NOTE

  OCall xsi.CtlsSet

  xor eax, eax                                          ;Return FALSE to prevent Windows from
MethodEnd                                               ;  setting the default keyboard focus.

; --------------------------------------------------------------------------------------------------
; Method:     Tab2.OnCtlColorDlg
; Purpose:    Event procedure for WM_CTLCOLORDLG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Brush to paint the background.

Method Tab2.OnCtlColorDlg,, wParam:WPARAM, lParam:LPARAM
  local HC:HIGHCONTRAST
  
  mov HC.cbSize, sizeof HIGHCONTRAST
  invoke SystemParametersInfo, SPI_GETHIGHCONTRAST, sizeof(HIGHCONTRAST), addr HC, 0
  .ifBitSet HC.dwFlags, HCF_HIGHCONTRASTON
    xor eax, eax
  .else
    invoke GetStockObject, WHITE_BRUSH
  .endif
MethodEnd
