; ==================================================================================================
; Title:      Demo03_Main.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Demonstration program 3.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


TB_STYLE    equ     WS_CHILD or WS_VISIBLE or WS_CLIPCHILDREN or TBSTYLE_TOOLTIPS or \
                    CCS_NORESIZE or CCS_NODIVIDER or CCS_ADJUSTABLE or TBSTYLE_FLAT or TBSTYLE_LIST

SB_STYLE    equ     WS_CHILD or WS_VISIBLE or SBARS_SIZEGRIP or SBARS_TOOLTIPS

.const
ToolbarFile DEF_TOOLBAR {IDC_TOOLBARFILE, TB_STYLE, TBSTYLE_EX_MIXEDBUTTONS, \
                         $OfsTStr("File operations"), {<0,0,0,0>}, 5}
  TBBUTTON {IDB_FILE_NEW,    IDM_FILE_NEW,    TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, $OfsTStr("New")}
  TBBUTTON {0,               -1,              TBSTATE_ENABLED, TBSTYLE_SEP}
  TBBUTTON {IDB_FILE_OPEN,   IDM_FILE_OPEN,   TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, $OfsTStr("Open")}
  TBBUTTON {IDB_FILE_SAVE,   IDM_FILE_SAVE,   TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, $OfsTStr("Save")}
  TBBUTTON {IDB_FILE_SAVEAS, IDM_FILE_SAVEAS, TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, $OfsTStr("Save as")}

ToolbarEdit DEF_TOOLBAR {IDC_TOOLBAREDIT, TB_STYLE, TBSTYLE_EX_MIXEDBUTTONS, \
                         $OfsTStr("Edit operations"), {<0,0,0,0>}, 3}
  TBBUTTON {IDB_EDIT_CUT,    IDM_EDIT_CUT,    TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, $OfsTStr("Cut")}
  TBBUTTON {IDB_EDIT_COPY,   IDM_EDIT_COPY,   TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, $OfsTStr("Copy")}
  TBBUTTON {IDB_EDIT_PASTE,  IDM_EDIT_PASTE,  TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, $OfsTStr("Paste")}

AppStatusbar DEF_STATUSBAR {IDC_STATUSBAR, SB_STYLE, 0, 4}
  DEF_STATUSBAR_PART {120,  50, 3, SBT_SUNKEN, $OfsTStr("Help")}
  DEF_STATUSBAR_PART {120,  20, 1, SBT_SUNKEN, NULL}
  DEF_STATUSBAR_PART {120,  -2, 0, SBT_SUNKEN, NULL}         ;Spring
  DEF_STATUSBAR_PART {120, 100, 2, SBT_SUNKEN, NULL}

;  DEF_STATUSBAR_PART {120,  50, 3, SBT_NOBORDERS, $OfsTStr("Help")}
;  DEF_STATUSBAR_PART {120,  20, 1, SBT_NOBORDERS or SBT_OWNERDRAW, NULL}
;  DEF_STATUSBAR_PART {120,  -2, 0, SBT_SUNKEN, NULL}         ;Spring
;  DEF_STATUSBAR_PART {120, 100, 2, SBT_SUNKEN, NULL}
; ——————————————————————————————————————————————————————————————————————————————————————————————————

Object Application, MySdiAppID, SdiApp                ;Single Document Interface App.
  RedefineMethod    Done
  RedefineMethod    Init
  StaticMethod      Startup
  RedefineMethod    OnSize,         WPARAM, LPARAM
;  VirtualEvent      OnSize,         WM_SIZE

  VirtualEvent      OnClose,        WM_CLOSE, WM_QUERYENDSESSION
  VirtualEvent      OnCommand,      WM_COMMAND
  VirtualEvent      OnCreate,       WM_CREATE
  VirtualEvent      OnNotify,       WM_NOTIFY
  VirtualEvent      OnPaint,        WM_PAINT

  DefineVariable    pIconImageList, $ObjPtr(MaskedImageList),  NULL
  DefineVariable    pModelessDlg,   $ObjPtr(DialogModeless),   NULL
  DefineVariable    pRebar,         $ObjPtr(Rebar),            NULL
  DefineVariable    pStatusbar,     $ObjPtr(Statusbar),        NULL
  DefineVariable    pToolbar1,      $ObjPtr(Toolbar),          NULL
  DefineVariable    pToolbar2,      $ObjPtr(Toolbar),          NULL
  DefineVariable    pTooltip,       $ObjPtr(Tooltip),          NULL

  DefineVariable    hIcon1,         HANDLE,   0
  DefineVariable    hIcon2,         HANDLE,   0

ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

Object ModelessDlg, , DialogModeless
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    OnCommand,      WPARAM, LPARAM
ObjectEnd


.code
; ==================================================================================================
;    Application implementation
; ==================================================================================================

CStr szAppClassName, "OAC_Application"

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Done
; Purpose:    Finalize the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Done, uses xsi
  SetObject xsi
  .if [xsi].hIcon1 != 0
    invoke DestroyIcon, [xsi].hIcon1
  .endif
  .if [xsi].hIcon2 != 0
    invoke DestroyIcon, [xsi].hIcon2
  .endif
  Destroy [xsi].pRebar
  Destroy [xsi].pStatusbar
  Destroy [xsi].pToolbar1
  Destroy [xsi].pToolbar2
  Destroy [xsi].pTooltip
  Destroy [xsi].pIconImageList
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Init
; Purpose:    Initialize the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Init, uses xbx xsi
  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD

  SetObject xsi
  ACall xsi.Init
;  mov [xsi].pCommandLine, $invoke(GetCommandLine)
  invoke LoadCommonControls, ICC_COOL_CLASSES or ICC_BAR_CLASSES    ;Rebar + Statusbar

  mov xbx, $New(MaskedImageList)
  mov [xsi].pIconImageList, xbx
  OCall xbx::MaskedImageList.Init, xsi, 16, 16, 1
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_NEW")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_OPEN")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_SAVE")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_SAVEAS")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_CUT")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_COPY")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_PASTE")

  mov dWndWidth, 500
  mov dWndHeight, 350
  invoke GetSystemMetrics, SM_CXSCREEN
  invoke CenterForm, dWndWidth, eax
  mov dWndPosX, eax
  invoke GetSystemMetrics, SM_CYSCREEN
  invoke CenterForm, dWndHeight, eax
  mov dWndPosY, eax

  invoke CreateWindowEx, WS_EX_LEFT or WS_EX_APPWINDOW, \
                         offset szAppClassName, offset szAppTitle, WS_OVERLAPPEDWINDOW, \
                         dWndPosX, dWndPosY, dWndWidth, dWndHeight, NULL, NULL, hInstance, xsi
  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL
  invoke UpdateWindow, [xsi].hWnd
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  local Dlg:$Obj(DialogAbout), hIcon:HICON

  SetObject xsi
  mov xax, wParam
  .if ax == IDM_FILE_NEW
    OCall [xsi].pStatusbar::Statusbar.SetPartText, 0, $OfsCStr("New File"), SBT_NOBORDERS
    .if [xsi].hIcon1 != 0
      invoke DestroyIcon, [xsi].hIcon1
    .endif
    mov [xsi].hIcon1, $OCall([xsi].pIconImageList::MaskedImageList.IconCreate, 0, ILD_TRANSPARENT)
    OCall [xsi].pStatusbar::Statusbar.SetPartIcon, 0, xax
    xor eax, eax

  .elseif ax == IDM_FILE_OPEN
    OCall [xsi].pStatusbar::Statusbar.SetPartText, 0, $OfsCStr("Open File"), SBT_SUNKEN
    .if [xsi].hIcon2 != 0
      invoke DestroyIcon, [xsi].hIcon2
    .endif
    mov [xsi].hIcon2, $OCall([xsi].pIconImageList::MaskedImageList.IconCreate, 1, ILD_TRANSPARENT)
    OCall [xsi].pStatusbar::Statusbar.SetPartIcon, 0, xax
    xor eax, eax

  .elseif ax == IDM_EXIT
    invoke SendMessage, [xsi].hWnd, WM_SYSCOMMAND, SC_CLOSE, NULL
    xor eax, eax

  .elseif ax == IDM_HELLO
    .if [xsi].pModelessDlg == NULL
      New DialogModeless
      mov [xsi].pModelessDlg, xax
      OCall [xsi].pModelessDlg::DialogModeless.Init, xsi, [xsi].hWnd, $OfsCStr("DIALOG1"), \
                                                     addr [xsi].hActiveMlsDlg
      OCall [xsi].pModelessDlg::DialogModeless.Show
    .else
      mov xax, [xsi].pModelessDlg
      invoke SetFocus, [xax].$Obj(Dialog).hWnd
    .endif
    xor eax, eax

  .elseif ax == IDM_ABOUT
    New Dlg::DialogAbout
    mov hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
    OCall Dlg::DialogAbout.Init, xsi, [xsi].hWnd, hIcon, offset szAboutText
    OCall Dlg::DialogAbout.Show
    OCall Dlg::DialogAbout.Done
    invoke DestroyIcon, hIcon
    xor eax, eax

  .else
    invoke DefWindowProc, [xsi].hWnd, WM_COMMAND, wParam, lParam

  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Application.OnCreate, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi

  mov [xsi].pStatusbar, $New(Statusbar)
  OCall xax::Statusbar.Init, xsi, [xsi].hWnd, offset AppStatusbar
  mov [xsi].pRebar, $New(Rebar)
  OCall xax::Rebar.Init, xsi, [xsi].hWnd

  mov [xsi].pToolbar2, $New(Toolbar)
  OCall [xsi].pToolbar2::Toolbar.Init, xsi, [xsi].hWnd, offset ToolbarEdit, \
                                       [xsi].pIconImageList, NULL, NULL

  OCall [xsi].pToolbar2::Toolbar.GetHeight
  mov ebx, eax
  OCall [xsi].pToolbar2::Toolbar.GetWidth
  mov xdx, [xsi].pToolbar2
  OCall [xsi].pRebar::Rebar.InsertBand, [xdx].$Obj(Toolbar).hWnd, eax, ebx

  mov [xsi].pToolbar1, $New(Toolbar)
  OCall [xsi].pToolbar1::Toolbar.Init, xsi, [xsi].hWnd, offset ToolbarFile, \
                                       [xsi].pIconImageList, NULL, NULL
  OCall [xsi].pToolbar1::Toolbar.GetHeight
  mov ebx, eax
  OCall [xsi].pToolbar1::Toolbar.GetWidth
  mov xdx, [xsi].pToolbar1
  OCall [xsi].pRebar::Rebar.InsertBand, [xdx].$Obj(Toolbar).hWnd, eax, ebx

  mov xax, [xsi].pToolbar1
  mov xbx, [xax].$Obj(Toolbar).hWnd
  invoke SendMessage, xbx, TB_GETTOOLTIPS, 0, 0
  mov xbx, xax
  invoke SendMessage, xbx, TTM_SETDELAYTIME, TTDT_INITIAL, 0
  invoke SendMessage, xbx, TTM_SETDELAYTIME, TTDT_RESHOW, 0

  mov [xsi].pTooltip, $New(Tooltip)
  OCall xax::Tooltip.Init, xsi, [xsi].hWnd
  mov xcx, [xsi].pStatusbar
  OCall [xsi].pTooltip::Tooltip.AddWndTip, [xcx].$Obj(WinControl).hWnd, $OfsCStr("Hello")

  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnNotify
; Purpose:    Event procedure for WM_NOTIFY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnNotify, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov xax, wParam
  .if xax == [xsi].pModelessDlg
    mov xax, lParam
    .if [xax].NMHDR.code == DLGDESTROYED
      Destroy [xsi].pModelessDlg
      m2z [xsi].pModelessDlg                            ;Mark object pointer as destroyed
      xor eax, eax
      ExitMethod
    .endif
  .endif
  invoke DefWindowProc, [xsi].hWnd, WM_NOTIFY, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnPaint, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, hDC:HDC, Rct:RECT

  SetObject xsi
  invoke BeginPaint, [xsi].hWnd, addr PS
  mov hDC, xax

  mov xcx, [xsi].pRebar
  invoke GetWindowRect, [xcx].$Obj(Rebar).hWnd, addr Rct
  mov eax, Rct.bottom
  sub eax, Rct.top
  mov ebx, eax
  mov xcx, [xsi].pStatusbar
  invoke GetWindowRect, [xcx].$Obj(Statusbar).hWnd, addr Rct
  mov eax, Rct.bottom
  sub eax, Rct.top
  mov edi, eax
  invoke GetClientRect, [xsi].hWnd, addr Rct
  sub Rct.bottom, edi
  mov Rct.top, ebx
  invoke DrawEdge, hDC, addr Rct, EDGE_SUNKEN, BF_RECT
  
  invoke EndPaint, [xsi].hWnd, addr PS
  mov eax, TRUE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnSize, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local Rct:RECT

  .if wParam != SIZE_MINIMIZED
    SetObject xsi
    invoke DefWindowProc, [xsi].hWnd, WM_SIZE, wParam, lParam
    invoke GetClientRect, [xsi].hWnd, addr Rct
    mov xbx, [xsi].pStatusbar
    invoke MoveWindow, [xbx].$Obj(Statusbar).hWnd, 0, 0, 0, 0, TRUE
    invoke UpdateWindow, [xbx].$Obj(Statusbar).hWnd

    mov xcx, [xsi].pRebar
    invoke MoveWindow, [xcx].$Obj(Rebar).hWnd, 0, 0, Rct.right, Rct.bottom, TRUE
  .endif

  xor eax, eax                                          ;Return zero
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Startup
; Purpose:    Register the Application window class with the operating system.
; Arguments:  None.
; Return:     Nothing.

Method Application.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof(WNDCLASSEX)
  m2z WC.style
  m2m WC.lpfnWndProc, $MethodAddr(Application.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  invoke LoadBitmap, hInstance, $OfsCStr("BMP_BACKGROUND")
  mov WC.hbrBackground, $invoke(CreatePatternBrush, xax)
  c2m WC.lpszMenuName, $OfsCStr("MENU_APP"), xax
  c2m WC.lpszClassName, offset szAppClassName, xax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd



; ==================================================================================================
;    ModelessDlg implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ModelessDlg.CtlsGet
; Purpose:    Read the controls in the dialog.
; Arguments:  None.
; Return:     Nothing.

Method ModelessDlg.CtlsGet
  SetObject xcx
  invoke IsDlgButtonChecked, [xcx].hWnd, IDC_CHECK1
  .if eax == BST_UNCHECKED
    invoke Beep, 1000, 500
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ModelessDlg.CtlsSet
; Purpose:    Set the controls in the dialog.
; Arguments:  None.
; Return:     Nothing.

Method ModelessDlg.CtlsSet, uses xsi
  SetObject xsi
  invoke CheckRadioButton, [xsi].hWnd, IDC_RADIO1, IDC_RADIO3, IDC_RADIO2
  invoke CheckDlgButton, [xsi].hWnd, IDC_CHECK1, BST_CHECKED
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ModelessDlg.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method ModelessDlg.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov xax, wParam
  .if ax == IDOK
    OCall xsi.CtlsGet
    OCall xsi.DestroyDialog, wParam
  .elseif ax == IDCANCEL
    OCall xsi.DestroyDialog, wParam
  .elseif ax == IDC_CHECK1
    invoke IsDlgButtonChecked, [xsi].hWnd, IDC_CHECK1
    .if eax == BST_CHECKED
      EnableDlgControl [xsi].hWnd, IDC_RADIO1
      EnableDlgControl [xsi].hWnd, IDC_RADIO2
      EnableDlgControl [xsi].hWnd, IDC_RADIO3
    .else
      EnableDlgControl [xsi].hWnd, IDC_RADIO1, FALSE
      EnableDlgControl [xsi].hWnd, IDC_RADIO2, FALSE
      EnableDlgControl [xsi].hWnd, IDC_RADIO3, FALSE
    .endif
  .endif
MethodEnd
