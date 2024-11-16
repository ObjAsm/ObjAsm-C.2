; ==================================================================================================
; Title:      Demo06_Main.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm demonstration program 6.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


TB_STYLE  equ   WS_CHILD or WS_VISIBLE or WS_CLIPCHILDREN or TBSTYLE_TOOLTIPS or \
                CCS_NORESIZE or CCS_NODIVIDER or CCS_ADJUSTABLE or TBSTYLE_FLAT or TBSTYLE_LIST

SB_STYLE  equ   WS_CHILD or WS_VISIBLE or SBARS_TOOLTIPS or SBARS_SIZEGRIP

.const
ToolbarFile DEF_TOOLBAR {IDC_TOOLBARFILE, TB_STYLE, TBSTYLE_EX_MIXEDBUTTONS, \
                         $OfsTStr("File operations"), {<0,0,0,0>}, 2}
  TBBUTTON {IDB_FILE_NEW,   IDM_FILE_NEW,   TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, $OfsTStr("New")}
  TBBUTTON {IDB_FILE_CLOSE, IDM_FILE_CLOSE, TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, $OfsTStr("Close")}

ToolbarWindow DEF_TOOLBAR {IDC_TOOLBARWINDOW, TB_STYLE, TBSTYLE_EX_MIXEDBUTTONS, \
                           $OfsTStr("Window operations"), {<0,0,0,0>}, 6}
  TBBUTTON {IDB_WINDOW_CASCADE,  IDM_WINDOW_CASCADE,  TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, \
            $OfsTStr("Cascade")}
  TBBUTTON {IDB_WINDOW_TILE_HOR, IDM_WINDOW_TILE_HOR, TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, \
            $OfsTStr("Tile horizontal")}
  TBBUTTON {IDB_WINDOW_TILE_VER, IDM_WINDOW_TILE_VER, TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, \
            $OfsTStr("Tile vertical")}
  TBBUTTON {IDB_WINDOW_ARRANGE,  IDM_WINDOW_ARRANGE,  TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, \
            $OfsTStr("Arrange")}
  TBBUTTON {IDB_WINDOW_ARRANGE,  -1                ,  TBSTATE_ENABLED, TBSTYLE_SEP}

  TBBUTTON {IDB_WINDOW_CLOSEALL, IDM_WINDOW_CLOSEALL, TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, \
            $OfsTStr("Close All")}

AppStatusbar DEF_STATUSBAR {IDC_STATUSBAR, SB_STYLE, 0, 4}
  DEF_STATUSBAR_PART {220, 100, 3, SBT_NOBORDERS, NULL}
  DEF_STATUSBAR_PART {120,  20, 1, SBT_SUNKEN,    NULL}
  DEF_STATUSBAR_PART {120,  -2, 0, SBT_SUNKEN,    NULL}   ;Spring type
  DEF_STATUSBAR_PART {120, 100, 2, SBT_SUNKEN,    NULL}

CloseEnumProc    proto :HWND, :DWORD

; ——————————————————————————————————————————————————————————————————————————————————————————————————

Object MyChildWnd, , MdiChildWnd                          ;MDI child window.
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, PSTRING  ;-> Owner, -> Title
  StaticMethod      Startup

  VirtualEvent      OnCommand,          WM_COMMAND
  VirtualEvent      OnMdiActivate,      WM_MDIACTIVATE
  VirtualEvent      OnPaint,            WM_PAINT

  DefineVariable    dColorIndex,        DWORD,      0
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

Object MyClientWnd, , MdiClientWnd  ;MDI client window.
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER           ;-> Owner

  VirtualEvent      OnPaint,            WM_PAINT

  DefineVariable    hBGBrush,           HBRUSH,     0     ;Background brush
  DefineVariable    dChildCount,        DWORD,      0
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

Object Application, , MdiApp                              ;MDI application.
  VirtualMethod     ChangeLanguage,     DWORD             ;IDLANG_XXX
  RedefineMethod    Done
  VirtualMethod     EnableActions,      DWORD             ;TRUE/FALSE
  RedefineMethod    Init
  RedefineMethod    OnSize,             WPARAM, LPARAM
  StaticMethod      Startup
  VirtualMethod     StatusbarHelp,      POINTER           ;-> Help string

  VirtualEvent      OnClose,            WM_CLOSE
  VirtualEvent      OnCommand,          WM_COMMAND
  VirtualEvent      OnCreate,           WM_CREATE
  VirtualEvent      OnDestroy,          WM_DESTROY
  VirtualEvent      OnKeyUp,            WM_KEYUP

  DefineVariable    dChildNumber,       DWORD,      0
  DefineVariable    dLangID,            DWORD,      IDLANG_ENGLISH
  DefineVariable    hMenuChild,         HWND,       0
  DefineVariable    hMenuChildWnd,      HWND,       0
  DefineVariable    hMenuInit,          HMENU,      0
  DefineVariable    pIconImageList,     $ObjPtr(MaskedImageList),  NULL
  DefineVariable    pRebar,             $ObjPtr(Rebar),            NULL
  DefineVariable    pStatusbar,         $ObjPtr(Statusbar),        NULL
  DefineVariable    pToolbarFile,       $ObjPtr(Toolbar),          NULL
  DefineVariable    pToolbarWindow,     $ObjPtr(Toolbar),          NULL
  DefineVariable    pXMenu,             $ObjPtr(XMenu),            NULL
ObjectEnd


.code
; ==================================================================================================
;    Application implementation
; ==================================================================================================

CStr szAppClassName,   "OAC_Application"
CStr szChildClassName, "OAC_Child"

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.ChangeLanguage
; Purpose:    Switch the application language.
; Arguments:  Arg1: Language ID.
; Return:     Nothing.

Method Application.ChangeLanguage, uses xbx xdi xsi, dLangID:DWORD
  local MenuInfo:MENUITEMINFO

  SetObject xsi
  mrm [xsi].dLangID, dLangID, eax                       ;Save setting

  ;Keep updated both menus!
  mov eax, dLangID
  cdiv LANGUAGE_STEP
  lea edi, [edx + IDM_LANGUAGE_ENGLISH]

  ;The IDM_LANGUAGE popup menu has to be found in the ChildMenu using GetMenuItemInfo since
  ;  it can have position 2 or 3 depending if a MDI child is maximized or not.
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
  OCall [xsi].pXMenu::XMenu.ChangeLanguage, xbx, dLangID  ;Active menu is converted

  ;Convert remaining main menu
  .if xbx == [xsi].hMenuInit
    OCall [xsi].pXMenu::XMenu.Convert, [xsi].hMenuChild, TRUE
  .else
    OCall [xsi].pXMenu::XMenu.Convert, [xsi].hMenuInit, TRUE
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Done
; Purpose:    Finalize the application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Done, uses xsi
  SetObject xsi
  Destroy [xsi].pIconImageList
  Destroy [xsi].pClientWnd
  Destroy [xsi].pRebar
  Destroy [xsi].pStatusbar
  Destroy [xsi].pToolbarFile
  Destroy [xsi].pToolbarWindow
  Destroy [xsi].pXMenu
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.EnableActions
; Purpose:    Enable or disable MDI child actions.
; Arguments:  Arg1: Enable TRUE/FALSE.
; Return:     Nothing.

Method Application.EnableActions, uses xsi, dAction:DWORD
  SetObject xsi
  OCall [xsi].pToolbarFile::Toolbar.BtnEnable, IDM_FILE_CLOSE, dAction

  OCall [xsi].pToolbarWindow::Toolbar.BtnEnable, IDM_WINDOW_CASCADE,  dAction
  OCall [xsi].pToolbarWindow::Toolbar.BtnEnable, IDM_WINDOW_TILE_HOR, dAction
  OCall [xsi].pToolbarWindow::Toolbar.BtnEnable, IDM_WINDOW_TILE_VER, dAction
  OCall [xsi].pToolbarWindow::Toolbar.BtnEnable, IDM_WINDOW_ARRANGE,  dAction
  OCall [xsi].pToolbarWindow::Toolbar.BtnEnable, IDM_WINDOW_CLOSEALL, dAction
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Init
; Purpose:    Initialize the application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Init, uses xbx xdi xsi
  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD

  SetObject xsi
  ACall xsi.Init

  ;Startup
  mov [xsi].pCommandLine, $invoke(GetCommandLine)
  invoke LoadCommonControls, ICC_COOL_CLASSES or ICC_BAR_CLASSES    ;Rebar + Statusbar

  ;Load application & menu icons
  mov xbx, $New(MaskedImageList)
  OCall xbx::MaskedImageList.Init, xsi, 16, 16, 1
  mov [xsi].pIconImageList, xbx
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_APP")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_APP_CHILD")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_NEW")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_CLOSE")
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
  invoke GetSystemMetrics, SM_CXSCREEN
  invoke CenterForm, dWndWidth, eax
  mov dWndPosX, eax
  invoke GetSystemMetrics, SM_CYSCREEN
  invoke CenterForm, dWndHeight, eax
  mov dWndPosY, eax

  invoke CreateWindowEx, WS_EX_APPWINDOW or WS_EX_WINDOWEDGE,
                         offset szAppClassName, offset szAppTitle, \
                         WS_OVERLAPPEDWINDOW or WS_CLIPCHILDREN, \
                         dWndPosX, dWndPosY, dWndWidth, dWndHeight, \
                         NULL, [xsi].hMenuInit, hInstance, pSelf

  ;Create and initialize Client window
  mov [xsi].pClientWnd, $New(MyClientWnd)
  OCall xax::MyClientWnd.Init, xsi

  ;Create and initialize XMenu
  mov [xsi].pXMenu, $New(XMenu)
  mov xdi, $MethodAddr(Application.StatusbarHelp)
  mov xax, [xsi].pClientWnd
  OCall [xsi].pXMenu::XMenu.Init, xsi, [xsi].hWnd, [xax].$Obj(MyClientWnd).hWnd, \
                                  [xsi].hMenuChildWnd, xbx, xdi, IDLANG_ENGLISH

  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL
  invoke UpdateWindow, [xsi].hWnd
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnClose
; Purpose:    Event procedure for WM_CLOSE and WM_QUERYENDSESSION message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnClose, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local dMsg:DWORD

  SetObject xsi
  mov dMsg, eax                                         ;Save windows message
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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnCommand, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local hChildWnd:HWND, AboutDlg:$Obj(DialogAbout)
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
    invoke EnumChildWindows, [xbx].$Obj(MyClientWnd).hWnd, offset CloseEnumProc, \
                             [xbx].$Obj(MyClientWnd).hWnd
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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnCreate, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi

  mov [xsi].pStatusbar, $New(Statusbar)
  OCall xax::Statusbar.Init, xsi, [xsi].hWnd, offset AppStatusbar

  mov [xsi].pRebar, $New(Rebar)
  OCall xax::Rebar.Init, xsi, [xsi].hWnd

  mov [xsi].pToolbarWindow, $New(Toolbar)
  OCall [xsi].pToolbarWindow::Toolbar.Init, xsi, [xsi].hWnd, offset ToolbarWindow, \
             [xsi].pIconImageList, NULL, NULL
  mov xbx, $OCall([xsi].pToolbarWindow::Toolbar.GetHeight)
  OCall [xsi].pToolbarWindow::Toolbar.GetWidth
  mov xdx, [xsi].pToolbarWindow
  OCall [xsi].pRebar::Rebar.InsertBand, [xdx].$Obj(Toolbar).hWnd, eax, ebx

  mov [xsi].pToolbarFile, $New(Toolbar)
  OCall [xsi].pToolbarFile::Toolbar.Init, xsi, [xsi].hWnd, offset ToolbarFile, \
             [xsi].pIconImageList, NULL, NULL
  mov xbx, $OCall([xsi].pToolbarFile::Toolbar.GetHeight)
  OCall [xsi].pToolbarFile::Toolbar.GetWidth
  mov xdx, [xsi].pToolbarFile
  OCall [xsi].pRebar::Rebar.InsertBand, [xdx].$Obj(Toolbar).hWnd, eax, ebx

  OCall xsi.EnableActions, FALSE

  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnDestroy
; Purpose:    Event procedure for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Application.OnDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke DestroyMenu, [xsi].hMenuInit
  invoke DestroyMenu, [xsi].hMenuChild
  invoke DestroyAcceleratorTable, [xsi].hAccelerators
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnKeyUp
; Purpose:    Event procedure for WM_KEYUP message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnKeyUp, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  DbgText "Application.OnKeyUp"
  SetObject xsi
  mov xbx, [xsi].pClientWnd
  .if wParam == VK_F6
    DbgText "Application.OnKeyUp F6"
    invoke SendMessage, [xbx].$Obj(MyClientWnd).hWnd, WM_MDINEXT, NULL, 0
  .endif
  invoke DefFrameProc, [xsi].hWnd, [xbx].$Obj(MyClientWnd).hWnd, WM_KEYUP, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnSize, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local dHeight:DWORD, dCWidth:DWORD, dTop:DWORD
  local SbRect:RECT, RbRect:RECT, CRect:RECT

;  DbgText "Application.OnSize"
  .if wParam != SIZE_MINIMIZED
    SetObject xsi
    invoke GetClientRect, [xsi].hWnd, addr CRect
    mrm dHeight, CRect.bottom, eax
    mrm dCWidth, CRect.right, eax

    mov xbx, [xsi].pRebar
    invoke GetWindowRect, [xbx].$Obj(Rebar).hWnd, addr RbRect
    mov eax, RbRect.bottom
    sub eax, RbRect.top
    mov dTop, eax
    invoke MoveWindow, [xbx].$Obj(Rebar).hWnd, 0, 0, dCWidth, eax, TRUE

    mov xbx, [xsi].pStatusbar
    invoke GetWindowRect, [xbx].$Obj(Statusbar).hWnd, addr SbRect
    mov eax, SbRect.bottom
    sub eax, SbRect.top
    sub dHeight, eax
    invoke MoveWindow, [xbx].$Obj(Statusbar).hWnd, 0, dHeight, dCWidth, eax, TRUE

    mov xbx, [xsi].pClientWnd
    .if xbx != NULL
      mov ecx, dTop
      sub dHeight, ecx
      invoke InvalidateRect, [xbx].$Obj(MyClientWnd).hWnd, NULL, FALSE
      invoke MoveWindow, [xbx].$Obj(MyClientWnd).hWnd, 0, dTop, dCWidth, dHeight, TRUE
    .endif

  .endif
  xor eax, eax                                          ;Return zero
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  CloseEnumProc (Callback)
; Purpose:    Close all open child windows.
; Arguments:  Arg1: Child window handle.
;             Arg2: Parameter passed to the enumeration procedure.
; Return:     eax = Exit code passed to PostQuitMessage.

CloseEnumProc proc hWnd:HWND, lParam:DWORD
  invoke GetParent, hWnd
  .if eax == lParam
    invoke SendMessage, hWnd, WM_CLOSE, 0, lParam
  .endif
  mov eax, TRUE                                         ;TRUE => next window
  ret
CloseEnumProc endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Startup
; Purpose:    Register the Application window class with the operating system.
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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.StatusbarHelp
; Purpose:    Display a help string on panel 0 of the statusbar.
; Arguments:  Arg1: -> Help string.
; Return:     Nothing.

Method Application.StatusbarHelp,, pHelpStr:POINTER
  SetObject xcx
  OCall [xcx].pStatusbar::Statusbar.SetPartText, 0, pHelpStr, SBT_NOBORDERS
MethodEnd



; ==================================================================================================
;    MyClientWnd implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     MyClientWnd.Done
; Purpose:    Finalize MyClientWnd object.
; Arguments:  None.
; Return:     Nothing.

Method MyClientWnd.Done, uses xsi
  SetObject xsi
  invoke DeleteObject, [xsi].hBGBrush
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     MyClientWnd.Init
; Purpose:    Initialize MdiClientWnd object.
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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     MyClientWnd.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method MyClientWnd.OnPaint, uses xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, Rct:RECT

  SetObject xsi
  invoke BeginPaint, [xsi].hWnd, addr PS
  invoke GetClientRect, [xsi].hWnd, addr Rct
  invoke FillRect, PS.hdc, addr Rct, [xsi].hBGBrush
  invoke EndPaint, [xsi].hWnd, addr PS
  invoke CallWindowProc, [xsi].$Obj(MyClientWnd).pPrevWndProc, \
                         [xsi].$Obj(MyClientWnd).hWnd, \
                         WM_PAINT, wParam, lParam
MethodEnd



; ==================================================================================================
;    MyChildWnd implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     MyChildWnd.Done
; Purpose:    Finalize MyChildWnd object.
; Arguments:  None.
; Return:     Nothing.

Method MyChildWnd.Done, uses xbx xdi xsi
  SetObject xsi
  mov xdi, [xsi].pOwner
  mov xbx, [xdi].$Obj(MyClientWnd).pOwner

  dec [xdi].$Obj(MyClientWnd).dChildCount

  .if ZERO?
    OCall xbx::Application.EnableActions, FALSE
    invoke SendMessage, [xdi].$Obj(MyClientWnd).hWnd, WM_MDISETMENU, \
                        [xbx].$Obj(Application).hMenuInit, NULL
    invoke DrawMenuBar, [xbx].$Obj(MdiApp).hWnd         ;Redraw the new menu bar
  .endif
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     MyChildWnd.Init
; Purpose:    Initialize MyChildWnd object.
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
      invoke DrawMenuBar, [xbx].$Obj(MdiApp).hWnd       ;Redraw the new menu bar
    .endif
    invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL
  .else
    invoke MessageBox, [xdi].$Obj(Application).hWnd, $OfsCStr("Window creation error"), \
                       offset szError, MB_OK or MB_ICONERROR
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
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
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     MyChildWnd.Startup
; Purpose:    Register the MyChildWnd window class with the operating system.
; Arguments:  None.
; Return:     Nothing.

Method MyChildWnd.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, 0
  mrm WC.lpfnWndProc, $MethodAddr(MyChildWnd.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  mrm WC.hInstance, hInstance, xax
  mov WC.hbrBackground, COLOR_WINDOW + 1
  m2z WC.lpszMenuName
  mrm WC.lpszClassName, offset szChildClassName, xax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP_CHILD"))
  m2z WC.hIconSm
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)

  invoke RegisterClassEx, addr WC
MethodEnd
