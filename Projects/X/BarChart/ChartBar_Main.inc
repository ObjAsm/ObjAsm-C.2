; ==================================================================================================
; Title:      ChartBar_Main.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm chart demonstration program.
; Notes:      Version C.1.0, August 2021
;               - First release.
; ==================================================================================================



TB_STYLE    equ   WS_CHILD or WS_VISIBLE or WS_CLIPCHILDREN or TBSTYLE_TOOLTIPS or \
                  CCS_NORESIZE or CCS_NODIVIDER or CCS_ADJUSTABLE or TBSTYLE_FLAT or TBSTYLE_LIST

SB_STYLE    equ   WS_CHILD or WS_VISIBLE or SBARS_TOOLTIPS or SBARS_SIZEGRIP

.const
ToolbarFile DEF_TOOLBAR {IDC_TOOLBARFILE, TB_STYLE, TBSTYLE_EX_MIXEDBUTTONS, $OfsTStr("File operations"), {<0,0,0,0>}, 2}
  TBBUTTON {IDB_FILE_NEW,   IDM_FILE_NEW,   TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, $OfsTStr("New")}
  TBBUTTON {IDB_FILE_CLOSE, IDM_FILE_CLOSE, TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, $OfsTStr("Close")}

ToolbarWindow DEF_TOOLBAR {IDC_TOOLBARWINDOW, TB_STYLE, TBSTYLE_EX_MIXEDBUTTONS, $OfsTStr("Window operations"), {<0,0,0,0>}, 6}
  TBBUTTON {IDB_WINDOW_CASCADE,  IDM_WINDOW_CASCADE,  TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, $OfsTStr("Cascade")}
  TBBUTTON {IDB_WINDOW_TILE_HOR, IDM_WINDOW_TILE_HOR, TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, $OfsTStr("Tile horizontal")}
  TBBUTTON {IDB_WINDOW_TILE_VER, IDM_WINDOW_TILE_VER, TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, $OfsTStr("Tile vertical")}
  TBBUTTON {IDB_WINDOW_ARRANGE,  IDM_WINDOW_ARRANGE,  TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, $OfsTStr("Arrange")}
  TBBUTTON {IDB_WINDOW_ARRANGE,  -1                ,  TBSTATE_ENABLED, TBSTYLE_SEP}
  TBBUTTON {IDB_WINDOW_CLOSEALL, IDM_WINDOW_CLOSEALL, TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, $OfsTStr("Close all")}

AppStatusbar DEF_STATUSBAR {IDC_STATUSBAR, SB_STYLE, 0, 4}
  DEF_STATUSBAR_PART {220, 100, 3, SBT_NOBORDERS, NULL}
  DEF_STATUSBAR_PART {120,  20, 1, SBT_SUNKEN,    NULL}
  DEF_STATUSBAR_PART {120,  -2, 0, SBT_SUNKEN,    NULL} ;Spring
  DEF_STATUSBAR_PART {120, 100, 2, SBT_SUNKEN,    NULL}

CloseEnumProc    proto :HWND, :LPARAM

CStr szApplication,   "OAC_Application"                 ;Used by Startup and Shutdown
CStr szChildWnd,      "OAC_Child"                       ;Used by Startup and Shutdown

; ——————————————————————————————————————————————————————————————————————————————————————————————————

Object ChildWnd, , MdiChildWnd                          ;MDI child window.
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, PSTRING  ;-> Owner, -> Caption
  RedefineMethod    OnGetMinMaxInfo,    WPARAM, LPARAM
  RedefineMethod    OnSize,             WPARAM, LPARAM
  StaticMethod      Startup

  VirtualEvent      OnCreate,           WM_CREATE
  VirtualEvent      OnMouseWheel,       WM_MOUSEWHEEL

  Embed     Chart,    ChartWnd
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

Object ClientWnd, MyClientWndID, MdiClientWnd           ;MDI client window.
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER         ;-> Owner

  VirtualEvent      OnPaint,            WM_PAINT

  DefineVariable    hBGBrush,           HBRUSH,     0   ;Background brush
  DefineVariable    dChildCount,        DWORD,      0
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

Object Application, , MdiApp                            ;MDI application = Frame window.
  RedefineMethod    Done
  VirtualMethod     EnableActions,      DWORD           ;TRUE/FALSE
  RedefineMethod    Init
  RedefineMethod    OnSize,             WPARAM, LPARAM
  StaticMethod      StatusbarHelp,      POINTER         ;-> Help string
  StaticMethod      Startup

;  VirtualEvent      OnClose,            WM_CLOSE, WM_QUERYENDSESSION
  VirtualEvent      OnCommand,          WM_COMMAND
  VirtualEvent      OnCreate,           WM_CREATE
  VirtualEvent      OnDestroy,          WM_DESTROY
  VirtualEvent      OnKeyUp,            WM_KEYUP

  DefineVariable    pRebar,             $ObjPtr(Rebar),            NULL
  DefineVariable    pStatusbar,         $ObjPtr(Statusbar),        NULL
  DefineVariable    pToolbarFile,       $ObjPtr(Toolbar),          NULL
  DefineVariable    pToolbarWindow,     $ObjPtr(Toolbar),          NULL
  DefineVariable    pIconImageList,     $ObjPtr(MaskedImageList),  NULL
  DefineVariable    pXMenu,             $ObjPtr(XMenu),            NULL

  DefineVariable    hMenuInit,          HMENU,      0
  DefineVariable    hMenuChild,         HMENU,      0
  DefineVariable    hMenuChildWnd,      HMENU,      0
  DefineVariable    dChildNumber,       DWORD,      0
  DefineVariable    dLanguage,          DWORD,      IDLANG_ENGLISH
ObjectEnd



; ==================================================================================================
;    Application implementation
; ==================================================================================================

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Done
; Purpose:    Finalize the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Done, uses xsi
  SetObject xsi
  Destroy [xsi].pRebar
  Destroy [xsi].pStatusbar
  Destroy [xsi].pToolbarFile
  Destroy [xsi].pToolbarWindow
  Destroy [xsi].pIconImageList
  Destroy [xsi].pXMenu
  Destroy [xsi].pClientWnd
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.EnableActions
; Purpose:    Enable or disable MDI child actions.
; Arguments:  Enable TRUE/FALSE.
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
; Method:    Application.Init
; Purpose:   Initialize the SDI application object.
; Arguments: None.
; Return:    Nothing.

Method Application.Init, uses xbx xdi xsi
  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD

  SetObject xsi
  ACall xsi.Init

  ;Startup
  mov [xsi].pCommandLine, $invoke(GetCommandLine)
  invoke LoadCommonControls, ICC_COOL_CLASSES or ICC_BAR_CLASSES  ;Rebar + Statusbar

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
  mov [xsi].hMenuChildWnd, $invoke(GetSubMenu, [xsi].hMenuChild, 1)

  ;Create the MDI Frame window
  mov dWndWidth, 600
  mov dWndHeight, 450
  mov dWndPosX, $32($invoke(CenterForm, dWndWidth, $32($invoke(GetSystemMetrics, SM_CXSCREEN))))
  mov dWndPosY, $32($invoke(CenterForm, dWndHeight, $32($invoke(GetSystemMetrics, SM_CYSCREEN))))

  invoke CreateWindowEx, WS_EX_APPWINDOW or WS_EX_WINDOWEDGE,
         offset szApplication, offset szAppTitle, WS_OVERLAPPEDWINDOW or WS_CLIPCHILDREN, \
         dWndPosX, dWndPosY, dWndWidth, dWndHeight, 0, [xsi].hMenuInit, hInstance, pSelf
  .if xax != 0
    ;Create Client window (subclass MDICLIENT)
    mov [xsi].pClientWnd, $New(ClientWnd)
    OCall xax::ClientWnd.Init, xsi

    ;Create XMenu
    mov [xsi].pXMenu, $New(XMenu)
    mov xdi, [xsi].pClientWnd
    OCall [xsi].pXMenu::XMenu.Init, xsi, [xsi].hWnd, [xdi].$Obj(ClientWnd).hWnd, \
                                    [xsi].hMenuChildWnd, xbx, \
                                    $MethodAddr(Application.StatusbarHelp), IDLANG_ENGLISH
    invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL
    invoke UpdateWindow, [xsi].hWnd
  .endif
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
  mov dMsg, eax
  mov xbx, [xsi].pClientWnd
  .if [xbx].$Obj(ClientWnd).dChildCount == 0            ;Ask only if a child window is open
    invoke DefFrameProc, [xsi].hWnd, [xbx].$Obj(ClientWnd).hWnd, dMsg, wParam, lParam
  .else
    invoke MessageBox, [xsi].hWnd, $OfsCStr("Are you sure ?"), $OfsCStr("Application exit"), \
                       MB_YESNO + MB_ICONQUESTION
    .if eax == IDNO
      xor eax, eax
    .else
      invoke DefFrameProc, [xsi].hWnd, [xbx].$Obj(ClientWnd).hWnd, dMsg, wParam, lParam
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
  local hChildWnd:HWND, Dlg:$Obj(DialogAbout)
  local cBuffer[MAX_PATH]:CHR, cNumber[20]:CHR, hIcon:HICON

  SetObject xsi
  mov xax, wParam
  mov xbx, [xsi].pClientWnd
  .if ax == IDM_FILE_NEW                                ;Create a child window
    inc [xsi].dChildNumber
    invoke MemClone, addr cBuffer, $OfsCStr("Child "), 7*sizeof CHR
    invoke dword2dec, addr cNumber, [xsi].dChildNumber
    invoke StrLRTrim, addr cNumber, addr cNumber
    invoke StrCCat, addr cBuffer, addr cNumber, lengthof cBuffer
    New ChildWnd
    mov xcx, xax
    OCall xcx::ChildWnd.Init, xbx, addr cBuffer
    xor eax, eax

  .elseif ax == IDM_HELP_HELP
    invoke ExpandEnvironmentStrings, $OfsCStr("%OBJASM_PATH%\Help\ObjAsm_Reference_Volume-I.pdf"), \
                                     addr cBuffer, lengthof(cBuffer)
    invoke PdfView, [xsi].hWnd, addr cBuffer, $OfsCStr("Introduction")
    xor eax, eax

  .elseif ax == IDM_HELP_ABOUT
    New Dlg::DialogAbout
    mov hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
    OCall Dlg::DialogAbout.Init, xsi, [xsi].hWnd, hIcon, offset szAboutText
    OCall Dlg::DialogAbout.Show
    OCall Dlg::DialogAbout.Done
    invoke DestroyIcon, hIcon
    xor eax, eax

  .elseif (ax == IDM_FILE_CLOSE) || (ax == SC_CLOSE)    ;Close the active window
    mov hChildWnd, $invoke(SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0)
    invoke SendMessage, hChildWnd, WM_CLOSE, 0, 0

  .elseif ax == SC_RESTORE                              ;Restore the active window
    mov hChildWnd, $invoke(SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0)
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDIRESTORE, hChildWnd, 0

  .elseif ax == SC_MINIMIZE                             ;Minimize the active window
    mov hChildWnd, $invoke(SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0)
    invoke ShowWindow, xax, SW_MINIMIZE
    xor eax, eax

  .elseif ax == IDM_FILE_EXIT
    invoke SendMessage, [xsi].hWnd, WM_CLOSE, 0, 0

  ;Messages for arranging windows
  .elseif ax == IDM_WINDOW_TILE_HOR
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDITILE, MDITILE_HORIZONTAL, 0
  .elseif ax == IDM_WINDOW_TILE_VER
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDITILE, MDITILE_VERTICAL, 0
  .elseif ax == IDM_WINDOW_CASCADE
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDICASCADE, 0, 0
  .elseif ax == IDM_WINDOW_ARRANGE
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDIICONARRANGE, 0, 0
  .elseif ax == IDM_WINDOW_CLOSEALL                     ;Attempt to close all windows
    invoke EnumChildWindows, [xbx].$Obj(ClientWnd).hWnd, addr CloseEnumProc, \
                             [xbx].$Obj(ClientWnd).hWnd
    xor eax, eax

  ;Pass to active child
  .else
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
    invoke SendMessage, xax, WM_COMMAND, wParam, lParam
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero to continue creation of the window, otherwise -1 to abort.

Method Application.OnCreate, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi

  mov [xsi].pStatusbar, $New(Statusbar)
  OCall xax::Statusbar.Init, xsi, [xsi].hWnd, offset AppStatusbar

  mov [xsi].pRebar, $New(Rebar)
  OCall xax::Rebar.Init, xsi, [xsi].hWnd

  mov [xsi].pToolbarWindow, $New(Toolbar)
  OCall [xsi].pToolbarWindow::Toolbar.Init, xsi, [xsi].hWnd, offset ToolbarWindow, \
                                            [xsi].pIconImageList, NULL, NULL
  mov ebx, $32($OCall([xsi].pToolbarWindow::Toolbar.GetHeight))
  OCall [xsi].pToolbarWindow::Toolbar.GetWidth
  mov xdx, [xsi].pToolbarWindow
  OCall [xsi].pRebar::Rebar.InsertBand, [xdx].$Obj(Toolbar).hWnd, eax, ebx

  mov [xsi].pToolbarFile, $New(Toolbar)
  OCall [xsi].pToolbarFile::Toolbar.Init, xsi, [xsi].hWnd, offset ToolbarFile, \
                                          [xsi].pIconImageList, NULL, NULL
  mov ebx, $32($OCall([xsi].pToolbarFile::Toolbar.GetHeight))
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
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnKeyUp
; Purpose:    Event procedure for WM_KEYUP message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnKeyUp, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov xbx, [xsi].pClientWnd
  .if wParam == VK_F6
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd ,WM_MDINEXT, NULL, 0
  .endif
  invoke DefFrameProc, [xsi].hWnd, [xbx].$Obj(ClientWnd).hWnd, WM_KEYUP, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnSize, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local dHeight:DWORD, dWidth:DWORD, dTop:DWORD
  local SbRect:RECT, RbRect:RECT, CRect:RECT

  .if wParam != SIZE_MINIMIZED
    SetObject xsi
    invoke GetClientRect, [xsi].hWnd, addr CRect
    mrm dHeight, CRect.bottom, eax
    mrm dWidth, CRect.right, ecx

    mov xbx, [xsi].pRebar
    invoke GetWindowRect, [xbx].$Obj(Rebar).hWnd, addr RbRect
    mov eax, RbRect.bottom
    sub eax, RbRect.top
    mov dTop, eax
    invoke MoveWindow, [xbx].$Obj(Rebar).hWnd, 0, 0, dWidth, eax, TRUE

    mov xbx, [xsi].pStatusbar
    invoke GetWindowRect, [xbx].$Obj(Statusbar).hWnd, addr SbRect
    mov eax, SbRect.bottom
    sub eax, SbRect.top
    sub dHeight, eax
    invoke MoveWindow, [xbx].$Obj(Statusbar).hWnd, 0, dHeight, dWidth, eax, TRUE

    mov xbx, [xsi].pClientWnd
    .if xbx != NULL
      mov ecx, dTop
      sub dHeight, ecx
      invoke InvalidateRect, [xbx].$Obj(ClientWnd).hWnd, NULL, FALSE
      invoke MoveWindow, [xbx].$Obj(ClientWnd).hWnd, 0, dTop, dWidth, dHeight, TRUE
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

CloseEnumProc proc hWnd:HWND, lParam:LPARAM
  invoke GetParent, hWnd
  .if xax == lParam
    invoke SendMessage, hWnd, WM_CLOSE, 0, 0
  .endif
  mov eax, TRUE                                         ;TRUE => next window
  ret
CloseEnumProc endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.StatusbarHelp
; Purpose:    Display a help string on panel 0 of the statusbar.
; Arguments:  Arg1: -> Help string.
; Return:     Nothing.

Method Application.StatusbarHelp,, pHelpStr:POINTER
  SetObject xax
  OCall [xax].pStatusbar::Statusbar.SetPartText, 0, pHelpStr, SBT_NOBORDERS
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Startup
; Purpose:    Register the object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method Application.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, 0
  m2m WC.lpfnWndProc, $MethodAddr(Application.WndProc), xdx
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xdx
  m2z WC.hbrBackground
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szApplication, xdx
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd



; ==================================================================================================
;    ClientWnd implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ClientWnd.Done
; Purpose:    Finalize the ClientWnd object.
; Arguments:  None.
; Return:     Nothing.

Method ClientWnd.Done, uses xsi
  SetObject xsi
  invoke DeleteObject, [xsi].hBGBrush
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ClientWnd.Init
; Purpose:    Initialize the MdiClientWnd object.
; Arguments:  Arg1 -> Owner object.
; Return:     Nothing.

Method ClientWnd.Init, uses xsi, pOwner:POINTER
  local hBmp:HBITMAP

  SetObject xsi
  ACall xsi.Init, pOwner
  mov hBmp, $invoke(LoadBitmap, hInstance, $OfsCStr("BMP_BACKGROUND"))
  mov [xsi].hBGBrush, $invoke(CreatePatternBrush, hBmp)
  invoke DeleteObject, hBmp
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ClientWnd.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ClientWnd.OnPaint, uses xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, Rct:RECT

  SetObject xsi
  invoke BeginPaint, [xsi].hWnd, addr PS
  invoke GetClientRect, [xsi].hWnd, addr Rct
  invoke FillRect, PS.hdc, addr Rct, [xsi].hBGBrush
  invoke EndPaint, [xsi].hWnd, addr PS
  xor eax, eax
  invoke CallWindowProc, [xsi].$Obj(ClientWnd).pPrevWndProc, \
                         [xsi].$Obj(ClientWnd).hWnd, \
                         WM_PAINT, wParam, lParam
MethodEnd



; ==================================================================================================
;    ChildWnd implementation
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChildWnd.Done
; Purpose:    Finalize the ChildWnd object.
; Arguments:  None.
; Return:     Nothing.

Method ChildWnd.Done, uses xbx xdi xsi
  SetObject xsi
  mov xdi, [xsi].pOwner
  dec [xdi].$Obj(ClientWnd).dChildCount

  .if ZERO?
    mov xbx, [xdi].$Obj(ClientWnd).pOwner
    OCall xbx::Application.EnableActions, FALSE
    invoke SendMessage, [xdi].$Obj(ClientWnd).hWnd, WM_MDISETMENU, \
                        [xbx].$Obj(Application).hMenuInit, NULL
    invoke DrawMenuBar, [xbx].$Obj(Application).hWnd    ;Redraw the new menu bar
  .endif

  OCall [xsi].Chart::ChartWnd.Done
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChildWnd.Init
; Purpose:    Initialize the ChildWnd object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> Title string.
; Return:     Nothing.

Method ChildWnd.Init, uses xbx xdi xsi, pOwner:POINTER, pTitle:PSTRING
  SetObject xsi
  ACall xsi.Init, pOwner, NULL                          ;hWnd is set in WndProc

  mov xdi, pOwner
  inc [xdi].$Obj(ClientWnd).dChildCount

  invoke CreateMDIWindow, offset szChildWnd, pTitle, \
                          0 , CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                          [xdi].$Obj(ClientWnd).hWnd, hInstance, pSelf
  mov xbx, [xdi].$Obj(ClientWnd).pOwner
  .if xax != NULL
    ;Manage the main Menu
    .if [xdi].$Obj(ClientWnd).dChildCount == 1          ;First child window ?
      OCall xbx::Application.EnableActions, TRUE
      invoke SendMessage, [xdi].$Obj(ClientWnd).hWnd, WM_MDISETMENU, \
                          [xbx].$Obj(Application).hMenuChild, \
                          [xbx].$Obj(Application).hMenuChildWnd
      invoke DrawMenuBar, [xbx].$Obj(Application).hWnd  ;Redraw the new menu bar
    .endif

    invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL
  .else
    invoke MessageBox, [xbx].$Obj(Application).hWnd, \
                       $OfsCStr("Window creation error"), offset szError, MB_OK or MB_ICONERROR
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChildWnd.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

$CFloat macro Value
  if type CHT_FLOAT eq 4
    exitm $CReal4(Value)
  else
    exitm $CReal8(Value)
  endif
endm

Method ChildWnd.OnCreate, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local dDataBuff:DWORD, ChartDef:DEF_CHART

  SetObject xsi

  mov ChartDef.xCtlID, 123456
  mov ChartDef.dStyle, WS_BORDER or WS_CHILD
  mov ChartDef.dExStyle, 0
  invoke GetClientRect, [xsi].hWnd, addr ChartDef.rect

  OCall [xsi].Chart::ChartWnd.Init, xsi, [xsi].hWnd, addr ChartDef

;  mov [xsi].Chart.Colors.PlotArea,    $RGB(255,255,255)
;  mov [xsi].Chart.Colors.PlotBorder,  $RGB(000,000,000)
;  mov [xsi].Chart.Colors.Background,  $RGB(223,223,223)
;  mov [xsi].Chart.Colors.Scales,      $RGB(000,000,000)

  ;Set paddings
  mov [xsi].Chart.Padding.left, 20
  mov [xsi].Chart.Padding.top, 20
  mov [xsi].Chart.Padding.right, 20
  mov [xsi].Chart.Padding.bottom, 20

  ;Scale X axis
  s2s [xsi].Chart.ScaleX.fSetupMax, $CFloat(3.0), xax, xcx
  s2s [xsi].Chart.ScaleX.fSetupMin, $CFloat(0.0), xax, xcx

  mov [xsi].Chart.ScaleX.dSetupMjrDiv, 3
  mov [xsi].Chart.ScaleX.dSetupMnrDiv, 0
  mov [xsi].Chart.ScaleX.dDataMjrDiv, 3
  mov [xsi].Chart.ScaleX.dDataMnrDiv, 0

  mov [xsi].Chart.ScaleX.pDescription, $invoke(StrNew, $OfsCStr("Time"))
  mov [xsi].Chart.ScaleX.pUnit, $invoke(StrNew, $OfsCStr("Months"))
;  BitSet [xsi].Chart.ScaleX.dFlags, CHT_SCALE_SHOW_AS_DATEDIFF
;  BitClr [xsi].Chart.ScaleX.dFlags, CHT_SCALE_AUTO_MJR_DIV
;  BitClr [xsi].Chart.ScaleX.dFlags, CHT_SCALE_AUTO_MNR_DIV

  ;Scale Y1 axis
  s2s [xsi].Chart.ScaleY1.fSetupMax, $CFloat(6.0), xax, xcx
  s2s [xsi].Chart.ScaleY1.fSetupMin, $CFloat(0.0), xax, xcx

  mov [xsi].Chart.ScaleY1.dSetupMjrDiv, 2
  mov [xsi].Chart.ScaleY1.dSetupMnrDiv, 1
  mov [xsi].Chart.ScaleY1.dDataMjrDiv, 2
  mov [xsi].Chart.ScaleY1.dDataMnrDiv, 1

  mov [xsi].Chart.ScaleY1.pDescription, $invoke(StrNew, $OfsCStr("Sales"))
  mov [xsi].Chart.ScaleY1.pUnit, $invoke(StrNew, $OfsCStr("M$"))

  BitClr [xsi].Chart.ScaleY1.dFlags, CHT_SCALE_AUTO_MIN

  ;Scale Y2 axis
  s2s [xsi].Chart.ScaleY2.fSetupMax, $CFloat(10.0), xax, xcx
  s2s [xsi].Chart.ScaleY2.fSetupMin, $CFloat(0.0), xax, xcx

  mov [xsi].Chart.ScaleY2.dSetupMjrDiv, 2
  mov [xsi].Chart.ScaleY2.dSetupMnrDiv, 1
  mov [xsi].Chart.ScaleY2.dDataMjrDiv, 2
  mov [xsi].Chart.ScaleY2.dDataMnrDiv, 1

  BitClr [xsi].Chart.ScaleY2.dFlags, CHT_SCALE_SHOW_MJR_GRID or CHT_SCALE_SHOW_MNR_GRID

  mov [xsi].Chart.ScaleY2.pDescription, $invoke(StrNew, $OfsCStr("Sales Rate"))
  mov [xsi].Chart.ScaleY2.pUnit, $invoke(StrNew, $OfsCStr("M$/Quarter"))

  ;Create chart series 1
  mov xdi, $New(ChartBarSeries)
  OCall xdi::ChartBarSeries.Init, addr [xsi].Chart.Data, DATAPOINTS
  mov [xdi].$Obj(ChartBarSeries).dDataFrom, 0
  mov [xdi].$Obj(ChartBarSeries).dDataCount, DATAPOINTS
  mov [xdi].$Obj(ChartBarSeries).pName, $invoke(StrNew, $OfsCStr("Sales America"))
  mov [xdi].$Obj(ChartBarSeries).pDescription, $invoke(StrNew, $OfsCStr("Sales in America"))
  mov [xdi].$Obj(ChartBarSeries).Setup.dBarWidth, 20
  mov [xdi].$Obj(ChartBarSeries).Setup.dBorderWidth, 2
  mov [xdi].$Obj(ChartBarSeries).Setup.BorderColor,   $RGB(255,000,000)
  mov [xdi].$Obj(ChartBarSeries).Setup.FillColorBack, $RGB(127,000,000)
  mov [xdi].$Obj(ChartBarSeries).Setup.FillColorFore, $RGB(255,000,000)
  mov [xdi].$Obj(ChartBarSeries).Setup.dFillStyle, 5
  mov [xdi].$Obj(ChartBarSeries).dFlags, CHT_SERIES_SHOW_DEPICTION or CHT_SERIES_SHOW_TAB
  mov [xdi].$Obj(ChartBarSeries).Setup.sdBarOffset, -12

  OCall xdi::ChartSeries.ItemAt, 0, 0                   ;Return a pointer to a CHT_FLOAT
  s2s CHT_FLOAT ptr [xax], $CFloat(1.0), xcx, xdx
  OCall xdi::ChartSeries.ItemAt, 1, 0                   ;Return a pointer to a CHT_FLOAT
  s2s CHT_FLOAT ptr [xax], $CFloat(3.0), xcx, xdx

  OCall xdi::ChartSeries.ItemAt, 0, 1                   ;Return a pointer to a CHT_FLOAT
  s2s CHT_FLOAT ptr [xax], $CFloat(2.0), xcx, xdx
  OCall xdi::ChartSeries.ItemAt, 1, 1                   ;Return a pointer to a CHT_FLOAT
  s2s CHT_FLOAT ptr [xax], $CFloat(5.0), xcx, xdx

  ;Create chart series 2
  mov xdi, $New(ChartBarSeries)
  OCall xdi::ChartBarSeries.Init, addr [xsi].Chart.Data, DATAPOINTS
  mov [xdi].$Obj(ChartBarSeries).dDataFrom, 0
  mov [xdi].$Obj(ChartBarSeries).dDataCount, DATAPOINTS
  mov [xdi].$Obj(ChartBarSeries).pName, $invoke(StrNew, $OfsCStr("Sales Europe"))
  mov [xdi].$Obj(ChartBarSeries).pDescription, $invoke(StrNew, $OfsCStr("Sales in Europe"))
  mov [xdi].$Obj(ChartBarSeries).Setup.dBarWidth, 20
  mov [xdi].$Obj(ChartBarSeries).Setup.dBorderWidth, 2
  mov [xdi].$Obj(ChartBarSeries).Setup.BorderColor,   $RGB(000,255,000)
  mov [xdi].$Obj(ChartBarSeries).Setup.FillColorBack, $RGB(000,127,000)
  mov [xdi].$Obj(ChartBarSeries).Setup.FillColorFore, $RGB(000,255,000)
  mov [xdi].$Obj(ChartBarSeries).Setup.dFillStyle, 2
  mov [xdi].$Obj(ChartBarSeries).dFlags, CHT_SERIES_SHOW_DEPICTION or CHT_SERIES_SHOW_TAB
  mov [xdi].$Obj(ChartBarSeries).Setup.sdBarOffset, +12

  OCall xdi::ChartSeries.ItemAt, 0, 0                   ;Return a pointer to a CHT_FLOAT
  s2s CHT_FLOAT ptr [xax], $CFloat(1.0), xcx, xdx
  OCall xdi::ChartSeries.ItemAt, 1, 0                   ;Return a pointer to a CHT_FLOAT
  s2s CHT_FLOAT ptr [xax], $CFloat(1.0), xcx, xdx

  OCall xdi::ChartSeries.ItemAt, 0, 1                   ;Return a pointer to a CHT_FLOAT
  s2s CHT_FLOAT ptr [xax], $CFloat(2.0), xcx, xdx
  OCall xdi::ChartSeries.ItemAt, 1, 1                   ;Return a pointer to a CHT_FLOAT
  s2s CHT_FLOAT ptr [xax], $CFloat(4.0), xcx, xdx

  ;Create chart series 3
  mov xdi, $New(ChartXYSeries)
  OCall xdi::ChartXYSeries.Init, addr [xsi].Chart.Data, 4
  mov [xdi].$Obj(ChartXYSeries).dDataFrom, 0
  mov [xdi].$Obj(ChartXYSeries).dDataCount, 4
  mov [xdi].$Obj(ChartXYSeries).pName, $invoke(StrNew, $OfsCStr("Sales Rate"))
  mov [xdi].$Obj(ChartXYSeries).pDescription, $invoke(StrNew, $OfsCStr("Global Sales Rate"))
  mov [xdi].$Obj(ChartXYSeries).Setup.LineColor, $RGB(000,000,192)
  mov [xdi].$Obj(ChartXYSeries).Setup.dLineWidth, 2
  mov [xdi].$Obj(ChartXYSeries).Setup.MarkerFillColor, $RGB(127,255,127)
  mov [xdi].$Obj(ChartXYSeries).Setup.MarkerBorderColor, $RGB(000,000,192)
  mov [xdi].$Obj(ChartXYSeries).Setup.dMarkerSize, 9
  mov [xdi].$Obj(ChartXYSeries).Setup.dMarkerBorderWidth, 2
  mov [xdi].$Obj(ChartXYSeries).Setup.dMarkerShape, CHTXY_MARKER_SQUARE
  mov [xdi].$Obj(ChartXYSeries).dFlags, CHT_SERIES_SHOW_DEPICTION or CHT_SERIES_SHOW_MARKER or CHT_SERIES_SHOW_TAB or CHT_SERIES_USE_Y2 or CHT_SERIES_SHOW_Y2_CHK

  OCall xdi::ChartSeries.ItemAt, 0, 0                   ;Return a pointer to a CHT_FLOAT
  s2s CHT_FLOAT ptr [xax], $CFloat(0.0), xcx, xdx
  OCall xdi::ChartSeries.ItemAt, 1, 0                   ;Return a pointer to a CHT_FLOAT
  s2s CHT_FLOAT ptr [xax], $CFloat(2.0), xcx, xdx

  OCall xdi::ChartSeries.ItemAt, 0, 1                   ;Return a pointer to a CHT_FLOAT
  s2s CHT_FLOAT ptr [xax], $CFloat(1.0), xcx, xdx
  OCall xdi::ChartSeries.ItemAt, 1, 1                   ;Return a pointer to a CHT_FLOAT
  s2s CHT_FLOAT ptr [xax], $CFloat(3.0), xcx, xdx

  OCall xdi::ChartSeries.ItemAt, 0, 2                   ;Return a pointer to a CHT_FLOAT
  s2s CHT_FLOAT ptr [xax], $CFloat(2.0), xcx, xdx
  OCall xdi::ChartSeries.ItemAt, 1, 2                   ;Return a pointer to a CHT_FLOAT
  s2s CHT_FLOAT ptr [xax], $CFloat(4.5), xcx, xdx

  OCall xdi::ChartSeries.ItemAt, 0, 3                   ;Return a pointer to a CHT_FLOAT
  s2s CHT_FLOAT ptr [xax], $CFloat(3.0), xcx, xdx
  OCall xdi::ChartSeries.ItemAt, 1, 3                   ;Return a pointer to a CHT_FLOAT
  s2s CHT_FLOAT ptr [xax], $CFloat(3.0), xcx, xdx

MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChildWnd.OnGetMinMaxInfo
; Purpose:    Event procedure for WM_GETMINMAXINFO message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ChildWnd.OnGetMinMaxInfo, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke DefMDIChildProc, [xsi].hWnd, WM_GETMINMAXINFO, wParam, lParam
  mov xcx, lParam
  mov [xcx].MINMAXINFO.ptMinTrackSize.x, 150
  mov [xcx].MINMAXINFO.ptMinTrackSize.y, 120
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChildWnd.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ChildWnd.OnSize, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  ;DbgText "ChildWnd.OnSize"
  ACall xsi.OnSize, wParam, lParam
  .if wParam != SIZE_MINIMIZED
    LoWord lParam, xax
    HiWord lParam, xbx
    invoke MoveWindow, [xsi].Chart.hWnd, 0, 0, eax, ebx, TRUE
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChildWnd.OnMouseWheel
; Purpose:    Event procedure for WM_MOUSEWHEEL message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ChildWnd.OnMouseWheel, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  ;DbgText "ChildWnd.OnMouseWheel"
  invoke SendMessage, [xsi].Chart.hWnd, WM_MOUSEWHEEL, wParam, lParam
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChildWnd.Startup
; Purpose:    Register the object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method ChildWnd.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CS_DBLCLKS
  mrm WC.lpfnWndProc, $MethodAddr(ChildWnd.WndProc), xdx
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  mrm WC.hInstance, hInstance, xdx
  mov WC.hbrBackground, 0                               ;No background drawing to avoid flickering
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szChildWnd, xdx
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP_CHILD"))
  m2z WC.hIconSm
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)

  invoke RegisterClassEx, addr WC
MethodEnd
