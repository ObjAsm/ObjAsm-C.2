; ==================================================================================================
; Title:      Demo10_Main.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm demonstration program 10.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


TB_STYLE  equ   WS_CHILD or WS_VISIBLE or WS_CLIPCHILDREN or TBSTYLE_TOOLTIPS or \
                CCS_NORESIZE or CCS_NODIVIDER or CCS_ADJUSTABLE or TBSTYLE_FLAT or TBSTYLE_LIST

SB_STYLE  equ   WS_CHILD or WS_VISIBLE or SBARS_TOOLTIPS or SBARS_SIZEGRIP

TC_STYLE  equ   WS_CHILD or WS_VISIBLE or WS_TABSTOP or TCS_TABS or TCS_FOCUSNEVER; or TCS_HOTTRACK

.const
ToolbarFile DEF_TOOLBAR {IDC_TOOLBARFILE, TB_STYLE, TBSTYLE_EX_MIXEDBUTTONS, \
                         $OfsTStr("File commands"), {<0,0,0,0>}, 2}
  TBBUTTON {IDB_FILE_NEW,   IDM_FILE_NEW,   TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_FILE_CLOSE, IDM_FILE_CLOSE, TBSTATE_ENABLED, TBSTYLE_BUTTON}

ToolbarWindow DEF_TOOLBAR {IDC_TOOLBARWINDOW, TB_STYLE, TBSTYLE_EX_MIXEDBUTTONS, \
                           $OfsTStr("Window commands"), {<0,0,0,0>}, 6}
  TBBUTTON {IDB_WINDOW_CASCADE,  IDM_WINDOW_CASCADE,  TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_WINDOW_TILE_HOR, IDM_WINDOW_TILE_HOR, TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_WINDOW_TILE_VER, IDM_WINDOW_TILE_VER, TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_WINDOW_ARRANGE,  IDM_WINDOW_ARRANGE,  TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_WINDOW_ARRANGE,  -1                ,  TBSTATE_ENABLED, TBSTYLE_SEP}
  TBBUTTON {IDB_WINDOW_CLOSEALL, IDM_WINDOW_CLOSEALL, TBSTATE_ENABLED, TBSTYLE_BUTTON}

AppStatusbar DEF_STATUSBAR {IDC_STATUSBAR, SB_STYLE, 0, 4}
  DEF_STATUSBAR_PART {220, 100, 3, SBT_NOBORDERS, NULL}
  DEF_STATUSBAR_PART {120,  20, 1, SBT_SUNKEN,    NULL}
  DEF_STATUSBAR_PART {120,  -2, 0, SBT_SUNKEN,    NULL} ;Spring
  DEF_STATUSBAR_PART {120, 100, 2, SBT_SUNKEN,    NULL}

SetupTabCtrl DEF_TABCONTROL {100, TC_STYLE, 0, NULL, {<2,2,295,180>}}

; --------------------------------------------------------------------------------------------------

Object MyChildWnd, , MdiChildWnd                        ;MDI child window.
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, PSTRING  ;-> Owner, -> Title
  StaticMethod      Startup

  VirtualEvent      OnCommand,          WM_COMMAND
  VirtualEvent      OnMdiActivate,      WM_MDIACTIVATE
  VirtualEvent      OnPaint,            WM_PAINT

  DefineVariable    dColorIndex,        DWORD,      0
ObjectEnd

; --------------------------------------------------------------------------------------------------

Object MyClientWnd, ClientWndID, MdiClientWnd         ;MDI client window.
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER         ;-> Owner

  VirtualEvent      OnEraseBkgnd,       WM_ERASEBKGND
  VirtualEvent      OnPaint,            WM_PAINT

  DefineVariable    hBGBrush,           HBRUSH,     0   ;Background brush
  DefineVariable    dChildCount,        DWORD,      0
ObjectEnd

; --------------------------------------------------------------------------------------------------

Object Application, , MdiApp                            ;MDI application.
  VirtualMethod     ChangeBtnLanguage,  DWORD           ;IDLANG_XXX
  VirtualMethod     ChangeLanguage,     DWORD           ;IDLANG_XXX
  RedefineMethod    Done
  VirtualMethod     EnableActions,      DWORD           ;TRUE/FALSE
  RedefineMethod    Init
  RedefineMethod    OnSize,             WPARAM, LPARAM
  StaticMethod      Startup
  VirtualMethod     StatusbarHelp,      PSTRING         ;-> Help string

  VirtualEvent      OnClose,            WM_CLOSE
  VirtualEvent      OnCommand,          WM_COMMAND
  VirtualEvent      OnCreate,           WM_CREATE
  VirtualEvent      OnDestroy,          WM_DESTROY
  VirtualEvent      OnEraseBkgnd,       WM_ERASEBKGND

  DefineVariable    dChildNumber,       DWORD,      0
  DefineVariable    dLangID,            DWORD,      IDLANG_ENGLISH
  DefineVariable    hMenuChild,         HMENU,      0
  DefineVariable    hMenuChildWnd,      HMENU,      0
  DefineVariable    hMenuInit,          HMENU,      0

  Embed     IconImageList,    MaskedImageList
  Embed     RBar,             Rebar
  Embed     Status,           Statusbar
  Embed     TbFile,           Toolbar
  Embed     TbWindow,         Toolbar
  Embed     Menu,             XMenu
  Embed     PropWnd,          PropertiesWnd
  Embed     ProjWnd,          ProjectWnd
  Embed     SplitterVer,      Splitter
  Embed     SplitterHor,      Splitter
ObjectEnd

; --------------------------------------------------------------------------------------------------

Object Tab1, , DialogModeless
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, HWND, POINTER

  VirtualEvent      OnCtlColorStatic,   WM_CTLCOLORSTATIC

  DefineVariable    hBackBrush,         HBRUSH,   0
ObjectEnd

; --------------------------------------------------------------------------------------------------

Object Tab2, , DialogModeless
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
ObjectEnd

; --------------------------------------------------------------------------------------------------

Object DialogSetup, , DialogModal
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, HWND
  RedefineMethod    OnCommand,          WPARAM, LPARAM
  RedefineMethod    OnDestroy,          WPARAM, LPARAM
  RedefineMethod    OnInitDialog,       WPARAM, LPARAM

  Embed     TabControl,       TabCtrl
  Embed     TabDialog1,       Tab1
  Embed     TabDialog2,       Tab2
  Embed     IconImageList,    MaskedImageList
ObjectEnd



; ==================================================================================================
;    Application implementation
; ==================================================================================================

CStr szAppClassName,   "OAC_Application"
CStr szChildClassName, "OAC_Child"

;##\

CloseEnumProc    proto :HWND, :LPARAM

; --------------------------------------------------------------------------------------------------
; Method:     XMenu.DrawMenuBarBkgnd2
; Purpose:    Draw a MainBar menu background.
; Arguments:  Arg1: -> DRAWITEMSTRUCT.
; Return:     Nothing.
; Note:       The ODS_HOTLIGHT is not used on Win98, so no HotTracking is possible!

Method XMenu.DrawMenuBarBkgnd2, uses xdi xsi, pDIS:PDRAWITEMSTRUCT
  local Rect:RECT, hBrush:HBRUSH

;  DbgText "XMenu.DrawMainBarBkgnd2"
  SetObject xsi
  mov xdi, pDIS
  CloneRect Rect, [xdi].DRAWITEMSTRUCT.rcItem
  .ifBitSet [xdi].DRAWITEMSTRUCT.itemState, ODS_HOTLIGHT
    invoke GetSysColor, COLOR_HIGHLIGHT                 ;Don't use COLOR_MENUHILIGHT
    mov hBrush, $invoke(CreateSolidBrush, eax)
    invoke FillRect, [xdi].DRAWITEMSTRUCT.hDC, addr Rect, hBrush
  .else
    .ifBitSet [xdi].DRAWITEMSTRUCT.itemState, ODS_SELECTED
      invoke GetSysColor, COLOR_HIGHLIGHT               ;Don't use COLOR_MENUHILIGHT
      mov hBrush, $invoke(CreateSolidBrush, eax)
    .else
      mov xcx, [xdi].DRAWITEMSTRUCT.itemData
      mov xdx, [xcx].$Obj(XMenuItem).pMenuStr
      .if [xcx].$Obj(XMenuItem).dID == IDM_HELP
        .ifBitSet [xsi].dFlags, XMF_FLASHING
          mov eax, [xsi].MenuBarBkColor
        .else
          invoke GetSysColor, COLOR_GRADIENTACTIVECAPTION
        .endif
      .else
        mov eax, [xsi].MenuBarBkColor
      .endif
      mov hBrush, $invoke(CreateSolidBrush, eax)
    .endif
    invoke FillRect, [xdi].DRAWITEMSTRUCT.hDC, addr Rect, hBrush
  .endif
  invoke DeleteObject, hBrush
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.ChangeBtnLanguage
; Purpose:    Switch the toolbar button application language.
; Arguments:  Arg1: Language ID.
; Return:     Nothing.

Method Application.ChangeBtnLanguage, uses xbx xdi xsi, dLangID:DWORD

  SetButtonText macro ButtonCommand:req, TextIndex:req
    mov eax, dLangID
    add eax, TextIndex
    invoke LoadString, hInstance, eax, xdi, lengthof(cButtonText) - 1
    invoke StrLScan, xdi, MENU_CHAR_LITERAL
    .if xax == NULL
      mov [xdi], $SubReg(xax, sizeof CHR)               ;Set ZTC
    .else
      add xax, sizeof CHR                               ;Skip MENULITERALCHAR character
      mov pPos, xax
      invoke StrSize, xax
      invoke MemShift, xdi, pPos, eax
    .endif
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_SETBUTTONINFO, ButtonCommand, addr tbbi
  endm

  local tbbi:TBBUTTONINFO, cButtonText[256]:CHR, pPos:POINTER

  SetObject xsi

  ;Set Toolbar button texts
  mov tbbi.TBBUTTONINFO.cbSize, sizeof TBBUTTONINFO
  mov tbbi.TBBUTTONINFO.dwMask, TBIF_TEXT
  lea xdi, cButtonText
  mov tbbi.TBBUTTONINFO.pszText, xdi
  mov tbbi.TBBUTTONINFO.cchText, lengthof cButtonText - 1

  lea xbx, [xsi].TbFile
  SetButtonText IDM_FILE_NEW,        01
  SetButtonText IDM_FILE_CLOSE,      02

  lea xbx, [xsi].TbWindow
  SetButtonText IDM_WINDOW_CASCADE,  31
  SetButtonText IDM_WINDOW_TILE_HOR, 32
  SetButtonText IDM_WINDOW_TILE_VER, 33
  SetButtonText IDM_WINDOW_ARRANGE,  34
  SetButtonText IDM_WINDOW_CLOSEALL, 35
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.ChangeLanguage
; Purpose:    Switch the application language.
; Arguments:  Arg1: Language ID.
; Return:     Nothing.

Method Application.ChangeLanguage, uses xbx xdi xsi, dLangID:DWORD
  local MenuInfo:MENUITEMINFO, pPos:POINTER

  SetObject xsi
  m2m [xsi].dLangID, dLangID, eax                       ;Save setting

  ;Keep updated both menus!
  mov eax, dLangID
  cdiv LANGUAGE_STEP
  lea edi, [edx + IDM_LANGUAGE_ENGLISH]

  ;The IDM_LANGUAGE popup menu has to be found in the ChildMenu using GetMenuItemInfo since
  ;  it can have position 1 or 2 depending if a MDI child is maximized or not.
  mov MenuInfo.cbSize, sizeof MenuInfo
  mov MenuInfo.fMask, MIIM_SUBMENU
  invoke GetMenuItemInfo, [xsi].hMenuChild, IDM_LANGUAGE, FALSE, addr MenuInfo
  invoke CheckMenuRadioItem, MenuInfo.hSubMenu, IDM_LANGUAGE_ENGLISH, IDM_LANGUAGE_SPANISH, \
                             edi, MF_BYCOMMAND

  ;IDM_LANGUAGE popup menu has only positon 1 in the InitMenu.
  invoke GetSubMenu, [xsi].hMenuInit, 1
  invoke CheckMenuRadioItem, xax, IDM_LANGUAGE_ENGLISH, IDM_LANGUAGE_SPANISH, edi, MF_BYCOMMAND

  ;Language switch
  mov xbx, $invoke(GetMenu, [xsi].hWnd)                 ;Get the current menu
  OCall [xsi].Menu::XMenu.ChangeLanguage, xbx, dLangID  ;Active menu is converted

  ;Convert remaining main menu
  .if xbx == [xsi].hMenuInit
    OCall [xsi].Menu::XMenu.Convert, [xsi].hMenuChild, TRUE
  .else
    OCall [xsi].Menu::XMenu.Convert, [xsi].hMenuInit, TRUE
  .endif

  OCall xsi.ChangeBtnLanguage, dLangID
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.Done
; Purpose:    Finalize the application object. Objects associated with window controls are
;             destroyed by Windows automatically when WM_DESTROY is send.
; Arguments:  None.
; Return:     Nothing.

Method Application.Done, uses xsi
  SetObject xsi
  OCall [xsi].IconImageList::MaskedImageList.Done
  OCall [xsi].RBar::Rebar.Done
  OCall [xsi].Status::Statusbar.Done
  OCall [xsi].TbFile::Toolbar.Done
  OCall [xsi].TbWindow::Toolbar.Done
  OCall [xsi].PropWnd::PropertiesWnd.Done
  OCall [xsi].ProjWnd::ProjectWnd.Done
  OCall [xsi].SplitterVer::Splitter.Done
  OCall [xsi].SplitterHor::Splitter.Done
  OCall [xsi].Menu::XMenu.Done
  OCall [xsi].pClientWnd::MyClientWnd.Done
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.EnableActions
; Purpose:    Enable or disable MDI child actions.
; Arguments:  Arg1: Enable TRUE/FALSE.
; Return:     Nothing.

Method Application.EnableActions, uses xsi, dAction:DWORD
  SetObject xsi
  OCall [xsi].TbFile::Toolbar.BtnEnable, IDM_FILE_CLOSE, dAction
  OCall [xsi].TbWindow::Toolbar.BtnEnable, IDM_WINDOW_CASCADE,  dAction
  OCall [xsi].TbWindow::Toolbar.BtnEnable, IDM_WINDOW_TILE_HOR, dAction
  OCall [xsi].TbWindow::Toolbar.BtnEnable, IDM_WINDOW_TILE_VER, dAction
  OCall [xsi].TbWindow::Toolbar.BtnEnable, IDM_WINDOW_ARRANGE,  dAction
  OCall [xsi].TbWindow::Toolbar.BtnEnable, IDM_WINDOW_CLOSEALL, dAction
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.Init
; Purpose:    Initialize the application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Init, uses xbx xdi xsi
  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD, pSBHelp:POINTER

  SetObject xsi
  ACall xsi.Init

  ;Startup
  mov [xsi].pCommandLine, $invoke(GetCommandLine)

  ;Rebar + Statusbar + ListView + TabControl + ComboBoxEx
  invoke LoadCommonControls, ICC_COOL_CLASSES or ICC_BAR_CLASSES or \
                             ICC_LISTVIEW_CLASSES or ICC_TAB_CLASSES or ICC_USEREX_CLASSES

  ;Load application & menu icons
  lea xbx, [xsi].IconImageList
  OCall xbx::MaskedImageList.Init, xsi, 16, 16, 1
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_APP")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_APP_CHILD")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_NEW")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_CLOSE")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_ERROR")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_SETUP")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_EXIT")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_CASCADE")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_TILE_HOR")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_TILE_VER")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_ARRANGE")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_CLOSEALL")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_HELP_HELP")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_HELP_ABOUT")

  mov [xsi].hAccelerators, $invoke(LoadAccelerators, hInstance, $OfsCStr("MDIACCEL"))

  ;Obtain handles for possible menus and submenus
  mov [xsi].hMenuInit, $invoke(LoadMenu, hInstance, $OfsCStr("MDIMENUINIT"))

  mov [xsi].hMenuChild, $invoke(LoadMenu, hInstance, $OfsCStr("MDIMENUCHILD"))
  mov [xsi].hMenuChildWnd, $invoke(GetSubMenu, [xsi].hMenuChild, 3)

  ;Create the MDI Frame window
  mov dWndWidth, 600
  mov dWndHeight, 450
  mov dWndPosX, $32($invoke(CenterForm, dWndWidth, $32($invoke(GetSystemMetrics, SM_CXSCREEN))))
  mov dWndPosY, $32($invoke(CenterForm, dWndHeight, $32($invoke(GetSystemMetrics, SM_CYSCREEN))))

  invoke CreateWindowEx, WS_EX_APPWINDOW or WS_EX_WINDOWEDGE,
                         offset szAppClassName, offset szAppTitle, \
                         WS_OVERLAPPEDWINDOW or WS_CLIPCHILDREN, \
                         dWndPosX, dWndPosY, dWndWidth, dWndHeight, \
                         NULL, [xsi].hMenuInit, hInstance, pSelf

  ;Initialize Client window
  mrm [xsi].pClientWnd, offset $ObjTmpl(MyClientWnd), xdi
  OCall xdi::MyClientWnd.Init, xsi
  mov xdi, [xdi].$Obj(MyClientWnd).hWnd

  ;Create and initialize XMenu
  m2m pSBHelp, $MethodAddr(Application.StatusbarHelp), xax
  OCall [xsi].Menu::XMenu.Init, xsi, [xsi].hWnd, xdi, [xsi].hMenuChildWnd, \
                                xbx, pSBHelp, IDLANG_ENGLISH

  Override [xsi].Menu::XMenu.DrawMenuBarBkgnd, XMenu.DrawMenuBarBkgnd2
  OCall xsi.ChangeBtnLanguage, IDLANG_ENGLISH

  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL
  invoke UpdateWindow, [xsi].hWnd
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnClose
; Purpose:    Event procedure for WM_CLOSE and WM_QUERYENDSESSION message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnClose, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local dMsg:DWORD

  SetObject xsi
  mov dMsg, eax
  mov xbx, [xsi].pClientWnd
  .if [xbx].$Obj(MyClientWnd).dChildCount == 0          ;Ask only if a child window is open
    invoke DefFrameProc, [xsi].hWnd, [xbx].$Obj(MyClientWnd).hWnd, dMsg, wParam, lParam
  .else
    invoke MessageBox, [xsi].hWnd, $OfsCStr("Are you sure ?"), $OfsCStr("Application exit"), \
                       MB_YESNO + MB_ICONQUESTION
    .if eax == IDNO
      xor eax, eax
      ExitMethod
    .else
      invoke DefFrameProc, [xsi].hWnd, [xbx].$Obj(MyClientWnd).hWnd, dMsg, wParam, lParam
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnCommand, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local hChildWnd:HWND, AboutDlg:$Obj(DialogAbout), SetupDlg:$Obj(DialogSetup)
  local cBuffer[MAX_PATH]:CHR, cNumber[20]:CHR, hIcon:HICON

  SetObject xsi
  mov xax, wParam
  mov xbx, [xsi].pClientWnd
  .if ax == IDM_FILE_NEW                                ;Create a child window
    inc [xsi].dChildNumber
    lea xbx, cBuffer
    invoke wsprintf, xbx, $OfsCStr("Child %I32u"), [xsi].dChildNumber
    New MyChildWnd
    OCall xax::MyChildWnd.Init, [xsi].pClientWnd, xbx
;    OCall [xsi].Menu::XMenu.FlashMenuBar, $RGB(255,255,0), 3
    xor eax, eax

  .elseif (ax == IDM_FILE_CLOSE) || (ax == SC_CLOSE)    ;Close the active window
    mov hChildWnd, $invoke(SendMessage, [xbx].$Obj(MyClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0)
    invoke SendMessage, hChildWnd, WM_CLOSE, 0, 0
    xor eax, eax

  .elseif ax == SC_RESTORE                              ;Restore the active window
    mov hChildWnd, $invoke(SendMessage, [xbx].$Obj(MyClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0)
    invoke SendMessage, [xbx].$Obj(MyClientWnd).hWnd, WM_MDIRESTORE, hChildWnd, 0
    xor eax, eax

  .elseif ax == SC_MINIMIZE                             ;Minimize the active window
    mov hChildWnd, $invoke(SendMessage, [xbx].$Obj(MyClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0)
    invoke ShowWindow, xax, SW_MINIMIZE
    xor eax, eax

  .elseif ax == IDM_FILE_ERROR
    OCall [xsi].Menu::XMenu.FlashMenuBar, $RGB(255,0,0), 6
    xor eax, eax

  .elseif ax == IDM_FILE_SETUP
    New SetupDlg::DialogSetup
    OCall SetupDlg::DialogSetup.Init, xsi, [xsi].hWnd
    OCall SetupDlg::DialogSetup.Show
    OCall SetupDlg::DialogSetup.Done
    xor eax, eax

  .elseif ax == IDM_FILE_EXIT
    invoke SendMessage, [xsi].hWnd, WM_CLOSE, 0, 0
    xor eax, eax

  ;Messages for language selection
  .elseif (ax >= IDM_LANGUAGE_ENGLISH) && (ax <= IDM_LANGUAGE_SPANISH)
    ;Calculate IDLANG_XXX
    sub eax, IDM_LANGUAGE_ENGLISH
    mov ecx, LANGUAGE_STEP
    mul ecx
    OCall xsi.ChangeLanguage, eax
    xor eax, eax

  ;Messages for arranging child windows
  .elseif ax == IDM_WINDOW_TILE_HOR
    invoke SendMessage, [xbx].$Obj(MyClientWnd).hWnd, WM_MDITILE, MDITILE_HORIZONTAL, 0
    xor eax, eax
  .elseif ax == IDM_WINDOW_TILE_VER
    invoke SendMessage, [xbx].$Obj(MyClientWnd).hWnd, WM_MDITILE, MDITILE_VERTICAL, 0
    xor eax, eax
  .elseif ax == IDM_WINDOW_CASCADE
    invoke SendMessage, [xbx].$Obj(MyClientWnd).hWnd, WM_MDICASCADE, 0, 0
    xor eax, eax
  .elseif ax == IDM_WINDOW_ARRANGE
    invoke SendMessage, [xbx].$Obj(MyClientWnd).hWnd, WM_MDIICONARRANGE, 0, 0
    xor eax, eax
  .elseif ax == IDM_WINDOW_CLOSEALL                     ;Attempt to close all windows
    invoke EnumChildWindows, [xbx].$Obj(MyClientWnd).hWnd, offset CloseEnumProc, 0
    xor eax, eax

  ;Messages for help menu
  .elseif ax == IDM_HELP_HELP
    invoke ExpandEnvironmentStrings, $OfsCStr("%OBJASM_PATH%\Help\ObjAsm_Reference_Volume-I.pdf"), \
                                     addr cBuffer, lengthof(cBuffer)
    invoke PdfView, [xsi].hWnd, addr cBuffer, $OfsCStr("Introduction")
    xor eax, eax

  .elseif ax == IDM_HELP_ABOUT
    New AboutDlg::DialogAbout
    mov hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
    OCall AboutDlg::DialogAbout.Init, xsi, [xsi].hWnd, hIcon, offset szAboutText
    OCall AboutDlg::DialogAbout.Show
    OCall AboutDlg::DialogAbout.Done
    invoke DestroyIcon, hIcon
    xor eax, eax

  ;Pass to active child
  .else
    invoke SendMessage, [xbx].$Obj(MyClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
    invoke SendMessage, xax, WM_COMMAND, wParam, lParam
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnCreate, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local MenuInfo:MENUINFO, hBrush:HBRUSH

  SetObject xsi

  ;Initialize project window
  OCall [xsi].ProjWnd::ProjectWnd.Init, xsi, [xsi].hWnd

  ;Initialize properties window
  OCall [xsi].PropWnd::PropertiesWnd.Init, xsi, [xsi].hWnd

  ;Initialize splitters
  OCall [xsi].SplitterVer::Splitter.Init, xsi, [xsi].hWnd, SPT_FLAG_VERTICAL, 150, 10, 50
  OCall [xsi].SplitterHor::Splitter.Init, xsi, [xsi].hWnd, SPT_FLAG_HORIZONTAL, 200, 55, 75

  ;Initialize statusbar
  OCall [xsi].Status::Statusbar.Init, xsi, [xsi].hWnd, offset AppStatusbar

  ;Initialize rebar and toolbars
  OCall [xsi].RBar::Rebar.Init, xsi, [xsi].hWnd

  OCall [xsi].TbWindow::Toolbar.Init, xsi, [xsi].hWnd, offset ToolbarWindow, \
             addr [xsi].IconImageList, NULL, NULL
  mov ebx, $32($OCall([xsi].TbWindow::Toolbar.GetHeight))
  OCall [xsi].TbWindow::Toolbar.GetWidth
  OCall [xsi].RBar::Rebar.InsertBand, [xsi].TbWindow.hWnd, eax, ebx

  OCall [xsi].TbFile::Toolbar.Init, xsi, [xsi].hWnd, offset ToolbarFile, \
             addr [xsi].IconImageList, NULL, NULL
  mov ebx, $32($OCall([xsi].TbFile::Toolbar.GetHeight))
  OCall [xsi].TbFile::Toolbar.GetWidth
  OCall [xsi].RBar::Rebar.InsertBand, [xsi].TbFile.hWnd, eax, ebx

  ;Disable toolbar buttons
  OCall xsi.EnableActions, FALSE

  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnDestroy
; Purpose:    Event procedure for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  .if [xsi].hMenuInit
    invoke DestroyMenu, [xsi].hMenuInit
  .endif
  .if [xsi].hMenuChild
    invoke DestroyMenu, [xsi].hMenuChild
  .endif
  .if [xsi].hAccelerators
    invoke DestroyAcceleratorTable, [xsi].hAccelerators
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnEraseBkgnd
; Purpose:    Event procedure for WM_ERASEBKGND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Non zero => we do the job.

Method Application.OnEraseBkgnd,, wParam:WPARAM, lParam:LPARAM
  mov eax, -1
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnSize, uses xsi, wParam:WPARAM, lParam:LPARAM
  local dHeight:DWORD, dWidth:DWORD, dTop:DWORD
  local CtRect:RECT, SbRect:RECT, RbRect:RECT
  local ProjWndRect:RECT, PropWndRect:RECT, SpVerRect:RECT, SpHorRect:RECT

;  DbgText "Application.OnSize"
  .if wParam != SIZE_MINIMIZED
    SetObject xsi
    invoke GetClientRect, [xsi].hWnd, addr CtRect
    m2m dHeight, CtRect.bottom, eax
    m2m dWidth, CtRect.right, ecx

    ;Place rebar
    invoke GetWindowRect, [xsi].RBar.hWnd, addr RbRect
    mov eax, RbRect.bottom
    sub eax, RbRect.top
    mov dTop, eax
    invoke MoveWindow, [xsi].RBar.hWnd, 0, 0, dWidth, eax, FALSE

    ;Place statusbar
    invoke GetWindowRect, [xsi].Status.hWnd, addr SbRect
    mov eax, SbRect.bottom
    sub eax, SbRect.top
    sub dHeight, eax
    invoke MoveWindow, [xsi].Status.hWnd, 0, dHeight, dWidth, eax, FALSE
    mov ecx, dTop
    sub dHeight, ecx

    ;Place vertical splitter
    invoke GetWindowRect, [xsi].SplitterVer.hWnd, addr SpVerRect
    invoke ScreenToClient, [xsi].hWnd, addr SpVerRect.left
    invoke ScreenToClient, [xsi].hWnd, addr SpVerRect.right
    mov eax, SpVerRect.right
    sub eax, SpVerRect.left
    invoke MoveWindow, [xsi].SplitterVer.hWnd, SpVerRect.left, dTop, eax, dHeight, FALSE

    ;Place horizontal splitter
    invoke GetWindowRect, [xsi].SplitterHor.hWnd, addr SpHorRect
    invoke ScreenToClient, [xsi].hWnd, addr SpHorRect.left
    invoke ScreenToClient, [xsi].hWnd, addr SpHorRect.right
    mov eax, SpHorRect.bottom
    sub eax, SpHorRect.top
    invoke MoveWindow, [xsi].SplitterHor.hWnd, 0, SpHorRect.top, SpVerRect.left, eax, FALSE

    ;Place project window
    invoke GetWindowRect, [xsi].ProjWnd.hWnd, addr ProjWndRect
    invoke ScreenToClient, [xsi].hWnd, addr ProjWndRect.left
    invoke ScreenToClient, [xsi].hWnd, addr ProjWndRect.right
    mov eax, SpHorRect.top
    sub eax, dTop
    invoke MoveWindow, [xsi].ProjWnd.hWnd, 0, dTop, SpVerRect.left, eax, FALSE

    ;Place properties window
    invoke GetWindowRect, [xsi].PropWnd.hWnd, addr PropWndRect
    invoke ScreenToClient, [xsi].hWnd, addr PropWndRect.left
    invoke ScreenToClient, [xsi].hWnd, addr PropWndRect.right
    mov eax, dHeight
    add eax, dTop
    sub eax, SpHorRect.bottom
    invoke MoveWindow, [xsi].PropWnd.hWnd, 0, SpHorRect.bottom, SpVerRect.left, eax, FALSE

    ;Place client window
    mov xcx, [xsi].pClientWnd
    .if xcx != NULL
      mov eax, CtRect.right
      sub eax, SpVerRect.right
      invoke MoveWindow, [xcx].$Obj(MyClientWnd).hWnd, SpVerRect.right, dTop, eax, dHeight, FALSE
    .endif

    ;Redraw all child windows
    invoke RedrawWindow, [xsi].hWnd, NULL, NULL, \
                         RDW_ERASE or RDW_INVALIDATE or RDW_UPDATENOW or RDW_ALLCHILDREN
    xor eax, eax                                      ;Return zero
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Procedure:  CloseEnumProc (Callback)
; Purpose:    Close all open child windows.
; Arguments:  Arg1: Child window handle.
;             Arg2: Parameter passed to the enumeration procedure.
; Return:     eax = TRUE.

CloseEnumProc proc hWnd:HWND, lParam:LPARAM
  invoke SendMessage, hWnd, WM_CLOSE, 0, 0
  mov eax, TRUE                                         ;TRUE => next window
  ret
CloseEnumProc endp

; --------------------------------------------------------------------------------------------------
; Method:     Application.Startup
; Purpose:    Register the object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method Application.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  m2z WC.style
  m2m WC.lpfnWndProc, $MethodAddr(Application.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  m2z WC.hbrBackground
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szAppClassName, xax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.StatusbarHelp
; Purpose:    Display a help string on panel 0 of the statusbar.
; Arguments:  Arg1: -> Help string.
; Return:     Nothing.

Method Application.StatusbarHelp,, pHelpStr:PSTRING
  SetObject xcx
  OCall [xcx].Status::Statusbar.SetPartText, 0, pHelpStr, SBT_NOBORDERS
MethodEnd

;##/

; ==================================================================================================
;    MyClientWnd implementation
; ==================================================================================================

;##\

; --------------------------------------------------------------------------------------------------
; Method:     MyClientWnd.Done
; Purpose:    Finalize the MyClientWnd object.
; Arguments:  None.
; Return:     Nothing.

Method MyClientWnd.Done, uses xsi
  SetObject xsi
  invoke DeleteObject, [xsi].hBGBrush
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MyClientWnd.Init
; Purpose:    Initialize the MdiClientWnd object.
; Arguments:  Arg1: -> Owner object.
; Return:     Nothing.

Method MyClientWnd.Init, uses xsi, pOwner:POINTER
  local hBmp:HBITMAP

  SetObject xsi
  ACall xsi.Init, pOwner
  mov hBmp, $invoke(LoadBitmap, hInstance, $OfsCStr("BMP_BACKGROUND"))
  mov [xsi].hBGBrush, $invoke(CreatePatternBrush, hBmp)
  invoke DeleteObject, hBmp
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MyClientWnd.OnEraseBkgnd
; Purpose:    Event procedure for WM_ERASEBKGND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Non zero => we do the job.

Method MyClientWnd.OnEraseBkgnd,, wParam:WPARAM, lParam:LPARAM
  mov eax, -1
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MyClientWnd.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method MyClientWnd.OnPaint, uses xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, Rct:RECT

;  DbgWarning "MyClientWnd.OnPaint"
  SetObject xsi
  invoke BeginPaint, [xsi].hWnd, addr PS
  invoke GetClientRect, [xsi].hWnd, addr Rct
  invoke FillRect, PS.hdc, addr Rct, [xsi].hBGBrush
  invoke EndPaint, [xsi].hWnd, addr PS
  invoke CallWindowProc, [xsi].$Obj(MyClientWnd).pPrevWndProc, \
                         [xsi].$Obj(MyClientWnd).hWnd, \
                         WM_PAINT, wParam, lParam
MethodEnd

;##/

; ==================================================================================================
;    MyChildWnd implementation
; ==================================================================================================

;##\

; --------------------------------------------------------------------------------------------------
; Method:     MyChildWnd.Done
; Purpose:    Finalize the MyChildWnd object.
; Arguments:  None.
; Return:     Nothing.

Method MyChildWnd.Done, uses xbx xdi xsi
  SetObject xsi
  mov xdi, [xsi].pOwner
  mov xbx, [xdi].$Obj(MyClientWnd).pOwner

  dec [xdi].$Obj(MyClientWnd).dChildCount

  ;Main menu update
  .if ZERO?                                             ;No more child windows ?
    OCall xbx::Application.EnableActions, FALSE
    invoke SendMessage, [xdi].$Obj(MyClientWnd).hWnd, WM_MDISETMENU, \
                        [xbx].$Obj(Application).hMenuInit, NULL
    invoke DrawMenuBar, [xbx].$Obj(Application).hWnd      ;Redraw the new menu bar
  .endif
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MyChildWnd.Init
; Purpose:    Initialize the MyChildWnd object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> Title string.
; Return:     Nothing.

Method MyChildWnd.Init, uses xbx xdi xsi, pOwner:POINTER, pTitle:PSTRING
  SetObject xsi
  ACall xsi.Init, pOwner, NULL                          ;hWnd is set in WndProc

  mov xdi, pOwner                                       ;xdi -> MyClientWnd
  inc [xdi].$Obj(MyClientWnd).dChildCount
  invoke CreateMDIWindow, offset szChildClassName, pTitle, WS_HSCROLL or WS_VSCROLL, \
                          CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                          [xdi].$Obj(MyClientWnd).hWnd, hInstance, pSelf
  .if xax != NULL
    .if [xdi].$Obj(MyClientWnd).dChildCount == 1        ;First child window ?
      mov xbx, [xdi].$Obj(MyClientWnd).pOwner           ;xbx -> Application
      OCall xbx::Application.EnableActions, TRUE
      invoke SendMessage, [xdi].$Obj(MyClientWnd).hWnd, WM_MDISETMENU, \
                          [xbx].$Obj(Application).hMenuChild, \
                          [xbx].$Obj(Application).hMenuChildWnd
      OCall [xbx].$Obj(Application).Menu::XMenu.SetMenuBarBkColor, [xbx].$Obj(Application).Menu.MenuBarBkColor
      invoke DrawMenuBar, [xbx].$Obj(Application).hWnd    ;Redraw the new menu bar
    .endif

    invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL
  .else
    invoke MessageBox, [xdi].$Obj(MyClientWnd).hWnd, $OfsCStr("Window creation error"), \
                       offset szError, MB_OK or MB_ICONERROR
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MyChildWnd.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method MyChildWnd.OnCommand, uses xdi xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov xax, wParam
  .if (eax >= IDM_COLOR_BLACK) && (eax <= IDM_COLOR_WHITE)
    mov edi, eax
    sub eax, IDM_COLOR_BLACK
    mov [xsi].dColorIndex, eax
    invoke InvalidateRect, [xsi].hWnd, NULL, TRUE

    mov xax, [xsi].pOwner
    mov xcx, [xax].$Obj(MyClientWnd).pOwner
    mov xax, [xcx].$Obj(Application).hMenuChild
    invoke GetSubMenu, xax, IDMENUCOLOR
    invoke CheckMenuRadioItem, xax, IDM_COLOR_BLACK, IDM_COLOR_WHITE, edi, MF_BYCOMMAND
    xor eax, eax
  .else
    invoke DefMDIChildProc, [xsi].hWnd, WM_COMMAND, wParam, lParam
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MyChildWnd.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method MyChildWnd.OnPaint, uses xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, Rect:RECT

  SetObject xsi
  invoke BeginPaint, [xsi].hWnd, addr PS

  mov eax, [xsi].dColorIndex
  .if eax == 0
    mov edx, $RGB(000, 000, 000)
  .elseif eax == 1
    mov edx, $RGB(255, 000, 000)
  .elseif eax == 2
    mov edx, $RGB(000, 255, 000)
  .elseif eax == 3
    mov edx, $RGB(000, 000, 255)
  .elseif eax == 4
    mov edx, $RGB(255, 255, 255)
  .endif

  invoke SetTextColor, PS.hdc, edx
  invoke GetClientRect, [xsi].hWnd, addr Rect
  invoke DrawText, PS.hdc, $OfsCStr("Hello World"), -1, addr Rect, \
                   DT_SINGLELINE or DT_CENTER or DT_VCENTER
  invoke EndPaint, [xsi].hWnd, addr PS
  invoke DefWindowProc, [xsi].hWnd, WM_PAINT, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MyChildWnd.OnMdiActivate
; Purpose:    Event procedure for WM_MDIACTIVATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method MyChildWnd.OnMdiActivate, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov xcx, [xsi].pOwner
  mov xdx, [xcx].$Obj(MyClientWnd).pOwner
  mov xax, lParam
  .if xax == [xsi].hWnd                               ;Activate child window
    ;Color popup menu update
    invoke GetSubMenu, [xdx].$Obj(Application).hMenuChild, IDMENUCOLOR
    mov xcx, xax
    mov eax, [xsi].dColorIndex
    add eax, IDM_COLOR_BLACK
    invoke CheckMenuRadioItem, xcx, IDM_COLOR_BLACK, IDM_COLOR_WHITE, eax, MF_BYCOMMAND
  .endif

  invoke DefMDIChildProc, [xsi].hWnd, WM_MDIACTIVATE, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MyChildWnd.Startup
; Purpose:    Register the object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method MyChildWnd.Startup
  local WC:WNDCLASSEX


  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CS_HREDRAW or CS_VREDRAW or CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT
  m2m WC.lpfnWndProc, $MethodAddr(MyChildWnd.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  mov WC.hbrBackground, COLOR_WINDOW + 1
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szChildClassName, xax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP_CHILD"))
  m2z WC.hIconSm
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)

  invoke RegisterClassEx, addr WC
MethodEnd



; ==================================================================================================
;    DialogSetup implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     DialogSetup.CtlsGet
; Purpose:    Read the setting of all controls.
; Arguments:  None.
; Return:     Nothing.

Method DialogSetup.CtlsGet, uses xsi
  SetObject xsi
  OCall [xsi].TabDialog1::Tab1.CtlsGet
  OCall [xsi].TabDialog2::Tab2.CtlsGet
  mov eax, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DialogSetup.CtlsSet
; Purpose:    Set the controls of the setup dialog.
; Arguments:  None.
; Return:     eax = this procedure should return TRUE to direct Windows to set the keyboard focus to
;                   the control specified by hwndFocus. Otherwise, it should return FALSE to prevent
;                   Windows from setting the default keyboard focus.

Method DialogSetup.CtlsSet
  ;No controls to setup!
  mov eax, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DialogSetup.Done
; Purpose:    Finalize the DialogSetup object.
; Arguments:  None.
; Return:     Nothing.

Method DialogSetup.Done, uses xsi
  SetObject xsi
  OCall [xsi].IconImageList::MaskedImageList.Done
  OCall [xsi].TabDialog1::Tab1.Done
  OCall [xsi].TabDialog2::Tab2.Done
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DialogSetup.Init
; Purpose:    Initialaize a DialogSetup object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> Parent window HANDLE.
; Return:     Nothing.

Method DialogSetup.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND
  SetObject xsi
  ACall xsi.Init, pOwner, hParent, $OfsCStr("DialogSetup")

  lea xbx, [xsi].IconImageList
  OCall xbx::MaskedImageList.Init, xsi, 16, 16, 2
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_NEW")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_SETUP")
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DialogSetup.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DialogSetup.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
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
; Method:     DialogSetup.OnDestroy
; Purpose:    Event procedure for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method DialogSetup.OnDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke SetWindowLongPtr, [xsi].hWnd, DWLP_USER, NULL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DialogSetup.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = FALSE.

Method DialogSetup.OnInitDialog, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  lea xbx, [xsi].TabControl
  OCall xbx::TabCtrl.Init, xsi, [xsi].hWnd, addr [xsi].IconImageList, offset SetupTabCtrl

  OCall [xsi].TabDialog1::Tab1.Init, xbx, [xbx].$Obj(TabCtrl).hWnd, $OfsCStr("SETUPTAB1")
  OCall [xsi].TabDialog1::Tab1.Show
  invoke ShowWindow, [xsi].TabDialog1.hWnd, SW_SHOWDEFAULT

  OCall [xsi].TabDialog2::Tab2.Init, xbx, [xbx].$Obj(TabCtrl).hWnd, $OfsCStr("SETUPTAB2"), \
                                               addr $ObjTmpl(Application).hActiveMlsDlg

  OCall [xsi].TabDialog2::Tab2.Show
  invoke ShowWindow, [xsi].TabDialog2.hWnd, SW_HIDE

  OCall xbx::TabCtrl.Insert, 0, [xsi].TabDialog1.hWnd, $OfsCStr("Setup 1"), 0
  OCall xbx::TabCtrl.Insert, 1, [xsi].TabDialog2.hWnd, $OfsCStr("Setup 2"), 1
  ACall xsi.OnInitDialog, wParam, lParam
MethodEnd



; ==================================================================================================
;    Tab1 implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     Tab1.Init
; Purpose:    Initialize the Tab1 object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> Template name or Resource ID.
; Return:     Nothing.

Method Tab1.Init, uses xsi, pOwner:POINTER, hParent:HWND, pTemplate:POINTER
  SetObject xsi
  ACall xsi.Init, pOwner, hParent, pTemplate, addr $ObjTmpl(Application).hActiveMlsDlg
  mov [xsi].hBackBrush, $invoke(CreateHatchBrush, HS_DIAGCROSS, $RGB(0, 0, 255))
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Tab1.Done
; Purpose:    Finalize the Tab1 object.
; Arguments:  None.
; Return:     Nothing.

Method Tab1.Done, uses xsi
  SetObject xsi
  invoke DeleteObject, [xsi].hBackBrush
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Tab1.OnCtlColorStatic
; Purpose:    Event procedure for WM_CTLCOLORSTATIC message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Brush handle that Windows uses to paint the background of the static control.

Method Tab1.OnCtlColorStatic, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke GetDlgItem, [xsi].hWnd, IDC_CONTROL
  .if xax == lParam
    mov xax, [xsi].hBackBrush
  .else
    xor eax, eax
  .endif
MethodEnd



; ==================================================================================================
;    Tab2 implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     Tab2.CtlsGet
; Purpose:    Read the setting of all controls.
; Arguments:  None.
; Return:     Nothing.

Method Tab2.CtlsGet, uses xsi
  SetObject xsi
  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_CHOICE1
  .if eax == BST_CHECKED
    m2z dSetupOption1
  .else
    invoke IsDlgButtonChecked, [xsi].hWnd, IDC_CHOICE2
    .if eax == BST_CHECKED
      mov dSetupOption1, 1
    .else
      invoke IsDlgButtonChecked, [xsi].hWnd, IDC_CHOICE3
      .if eax == BST_CHECKED
        mov dSetupOption1, 2
      .else
        mov dSetupOption1, 3
      .endif
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Tab2.CtlsSet
; Purpose:    Set the controls of the setup dialog.
; Arguments:  None.
; Return:     eax = this procedure should return TRUE to direct Windows to set the keyboard focus to
;                   the control specified by hwndFocus. Otherwise, it should return FALSE to prevent
;                   Windows from setting the default keyboard focus.

Method Tab2.CtlsSet
  SetObject xcx
  mov eax, IDC_CHOICE1
  add eax, dSetupOption1
  invoke CheckRadioButton, [xcx].hWnd, IDC_CHOICE1, IDC_CHOICE4, eax
MethodEnd

;##/
