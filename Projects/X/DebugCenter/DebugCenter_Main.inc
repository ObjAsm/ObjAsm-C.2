; ==================================================================================================
; Title:      DebugCenter_Main.inc
; Author:     G. Friedrich
; Version:    See DebugCenter.asm
; Purpose:    ObjAsm DebugCenter application.
; ==================================================================================================


CLSSTYLE  equ   CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW

TBSTYLE   equ   WS_CHILD or WS_VISIBLE or WS_CLIPCHILDREN or TBSTYLE_TOOLTIPS or \
                CCS_NORESIZE or CCS_NODIVIDER or CCS_ADJUSTABLE or TBSTYLE_FLAT or TBSTYLE_LIST

WAIT_TIMEOUT  equ   102h

.const
ToolbarFile DEF_TOOLBAR {IDC_TOOLBARFILE, TBSTYLE, TBSTYLE_EX_MIXEDBUTTONS, \
                         $OfsTStr("File operations"), {<0,0,0,0>}, 8}
  TBBUTTON {IDB_FILE_OPEN,        IDM_FILE_OPEN,        TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_FILE_SAVE,        IDM_FILE_SAVE,        TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_FILE_SAVEAS,      IDM_FILE_SAVEAS,      TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_FILE_CLOSE,       IDM_FILE_CLOSE,       TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {0,                    -1,                   TBSTATE_ENABLED, TBSTYLE_SEP}
  TBBUTTON {IDB_FILE_PRINT,       IDM_FILE_PRINT,       TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {0,                    -2,                   TBSTATE_ENABLED, TBSTYLE_SEP}
  TBBUTTON {IDB_FILE_PIN,         IDM_FILE_PIN,         TBSTATE_ENABLED, TBSTYLE_BUTTON or \
                                                                         TBSTYLE_CHECK}

ToolbarEdit DEF_TOOLBAR {IDC_TOOLBAREDIT, TBSTYLE, TBSTYLE_EX_MIXEDBUTTONS, \
                         $OfsTStr("Edit operations"), {<0,0,0,0>}, 7}
  TBBUTTON {IDB_EDIT_CUT,         IDM_EDIT_CUT,         TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_EDIT_COPY,        IDM_EDIT_COPY,        TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_EDIT_PASTE,       IDM_EDIT_PASTE,       TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {0,                    -3,                   TBSTATE_ENABLED, TBSTYLE_SEP}
  TBBUTTON {IDB_EDIT_ERASE,       IDM_EDIT_ERASE,       TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_EDIT_ERASEALL,    IDM_EDIT_ERASEALL,    TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_EDIT_FIND,        IDM_EDIT_FIND,        TBSTATE_ENABLED, TBSTYLE_BUTTON}

ToolbarWindow DEF_TOOLBAR {IDC_TOOLBARWINDOW, TBSTYLE, TBSTYLE_EX_MIXEDBUTTONS, \
                           $OfsTStr("Window operations"), {<0,0,0,0>}, 8}
  TBBUTTON {IDB_WINDOW_CASCADE,   IDM_WINDOW_CASCADE,   TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_WINDOW_TILE_HOR,  IDM_WINDOW_TILE_HOR,  TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_WINDOW_TILE_VER,  IDM_WINDOW_TILE_VER,  TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_WINDOW_ARRANGE,   IDM_WINDOW_ARRANGE,   TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_WINDOW_CLOSEALL,  IDM_WINDOW_CLOSEALL,  TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {0,                    -4,                   TBSTATE_ENABLED, TBSTYLE_SEP}
  TBBUTTON {IDB_WINDOW_ZOOMIN,    IDM_WINDOW_ZOOMIN,    TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_WINDOW_ZOOMOUT,   IDM_WINDOW_ZOOMOUT,   TBSTATE_ENABLED, TBSTYLE_BUTTON}

SBSTYLE     equ     WS_CHILD or WS_VISIBLE or SBARS_TOOLTIPS or SBARS_SIZEGRIP

AppStatusbar DEF_STATUSBAR {IDC_STATUSBAR, SBSTYLE, 0, 4}
  DEF_STATUSBAR_PART {320, 100, 3, SBT_NOBORDERS, NULL}
  DEF_STATUSBAR_PART {120,  20, 1, SBT_SUNKEN,    NULL}
  DEF_STATUSBAR_PART {120,  -2, 0, SBT_SUNKEN,    NULL} ;Spring
  DEF_STATUSBAR_PART {120, 100, 2, SBT_SUNKEN,    NULL}

;##\ Not used yet
;TextFlags  record  TF_Unused:24=0, TF_FILTERACT:1=FALSE, \
;                   TF_FILTERTEXT:1=FALSE, TF_FILTERMSGID:1=FALSE, TF_FILTERLNNR:1=FALSE, \
;                   TF_FILTERTIME:1=FALSE, \
;                   TF_HIDEMSGID:1=FALSE, TF_HIDETIME:1=FALSE, TF_HIDELNNR:1=FALSE
;##/

; ——————————————————————————————————————————————————————————————————————————————————————————————————

Object DbgMdiClient, DBG_MDI_CLIENT_ID, MdiClientWnd               ;MDI client window.
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER                 ;-> Owner

  VirtualEvent      OnDropFiles,        WM_DROPFILES
  VirtualEvent      OnEraseBkgnd,       WM_ERASEBKGND
  VirtualEvent      OnPaint,            WM_PAINT

  DefineVariable    hBGBrush,           HBRUSH,     0           ;Background brush
  DefineVariable    dChildCount,        DWORD,      0
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

Object DebugCenter, DEBUG_CENTER_ID, MdiApp                     ;MDI application.
  VirtualMethod     ChangeLanguage,     DWORD                   ;IDLANG_XXX
  RedefineMethod    Done
  VirtualMethod     EnableActions,      DWORD                   ;TRUE / FALSE
  RedefineMethod    Init
  VirtualMethod     ManageOptions,      DWORD
  RedefineMethod    OnSize,             WPARAM, LPARAM
  StaticMethod      Startup
  VirtualMethod     StatusbarHelp,      PSTRING                 ;-> Help string

  VirtualEvent      OnClose,            WM_CLOSE
  VirtualEvent      OnCommand,          WM_COMMAND
  VirtualEvent      OnCopyData,         WM_COPYDATA
  VirtualEvent      OnCreate,           WM_CREATE
  VirtualEvent      OnDestroy,          WM_DESTROY
  VirtualEvent      OnEraseBkgnd,       WM_ERASEBKGND
  VirtualEvent      OnNotify,           WM_NOTIFY
  VirtualEvent      OnShellNotify,      WM_SHELLNOTIFY

  DefineVariable    dChildNumber,       DWORD,      0
  DefineVariable    dLanguage,          DWORD,      IDLANG_ENGLISH
  DefineVariable    hMenuInit,          HMENU,      0
  DefineVariable    hMenuChild,         HMENU,      0
  DefineVariable    hMenuChildWnd,      HMENU,      0
  DefineVariable    hMenuContext,       HMENU,      0
  DefineVariable    hMenuSysTray,       HMENU,      0
  DefineVariable    pDirectory,         PSTRING,    NULL

  DefineVariable    pIconImageList,     $ObjPtr(MaskedImageList),  NULL
  DefineVariable    pRebar,             $ObjPtr(Rebar),            NULL
  DefineVariable    pStatusbar,         $ObjPtr(Statusbar),        NULL
  DefineVariable    pToolbarFile,       $ObjPtr(Toolbar),          NULL
  DefineVariable    pToolbarEdit,       $ObjPtr(Toolbar),          NULL
  DefineVariable    pToolbarWindow,     $ObjPtr(Toolbar),          NULL
  DefineVariable    pXMenu,             $ObjPtr(XMenu),            NULL
  DefineVariable    pMagnetism,         $ObjPtr(Magnetism),        NULL

  DefineVariable    NotifyIconData,     NOTIFYICONDATA, {}

  DefineVariable    hFont,              HFONT,      0
  DefineVariable    dTxtZoomFactor,     DWORD,      TXT_ZOOM_DEFAULT
  DefineVariable    dBmpZoomFactor,     DWORD,      BMP_ZOOM_DEFAULT

  DefineVariable    PrintMargin,        RECT,       {2500, 1000, 1000, 1000}
  DefineVariable    hDevMode,           HANDLE,     0
  DefineVariable    hDevNames,          HANDLE,     0
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

include DebugCenter_Child.inc
include DebugCenter_ChildTxt.inc
include DebugCenter_ChildBmp.inc
include DebugCenter_About.inc

% CStrW cDbgRegKey, DEBUG_CENTER_REGKEY

.data?
hCBTProc  HANDLE  ?


.code
; ==================================================================================================
;    DebugCenter implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DebugCenter.ChangeLanguage
; Purpose:    Switch the application language.
; Arguments:  Arg1: Language ID.
; Return:     Nothing.

SetButtonText macro ButtonCommand:req, TextIndex:req
  mov eax, dLangID
  add eax, TextIndex
  invoke LoadString, hInstance, eax, xdi, lengthof cButtonText - 1
  invoke StrLScan, xdi, MENU_CHAR_LITERAL
  .if xax != NULL
    m2z CHR ptr [xax]
  .endif
  invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_SETBUTTONINFO, ButtonCommand, addr tbbi
endm

Method DebugCenter.ChangeLanguage, uses xbx xdi xsi, dLangID:DWORD
  local MenuInfo:MENUITEMINFO, tbbi:TBBUTTONINFO, cButtonText[256]:CHR

  SetObject xsi
  m2m [xsi].dLanguage, dLangID, eax                     ;Save setting

  ;Keep updated both menus!
  ;Calculate the corresponding IDM_???? (= xdi)
  mov eax, dLangID
  cdiv LANGUAGE_STEP
  lea xdi, [xdx + IDM_LANGUAGE_ENGLISH]

  ;The IDM_LANGUAGE popup menu has to be found in the ChildMenu using GetMenuItemInfo since
  ;  it can have position 2 or 3 depending if a MDI child is maximized or not.
  mov MenuInfo.cbSize, sizeof(MenuInfo)
  mov MenuInfo.fMask, MIIM_SUBMENU
  invoke GetMenuItemInfo, [xsi].hMenuChild, IDM_LANGUAGE, FALSE, addr MenuInfo
  invoke CheckMenuRadioItem, MenuInfo.hSubMenu, IDM_LANGUAGE_ENGLISH, IDM_LANGUAGE_SPANISH, \
                             edi, MF_BYCOMMAND

  ;IDM_LANGUAGE popup menu has only positon 2 in the InitMenu.
  invoke GetSubMenu, [xsi].hMenuInit, 2
  invoke CheckMenuRadioItem, xax, IDM_LANGUAGE_ENGLISH, IDM_LANGUAGE_SPANISH, edi, MF_BYCOMMAND

  ;XMenu language switch
  mov xbx, $invoke(GetMenu, [xsi].hWnd)                 ;Get the current menu
  OCall [xsi].pXMenu::XMenu.ChangeLanguage, xbx, dLangID    ;Active menu is converted

  ;Set Toolbar button texts
  mov tbbi.TBBUTTONINFO.cbSize, sizeof(TBBUTTONINFO)
  mov tbbi.TBBUTTONINFO.dwMask, TBIF_TEXT
  lea xdi, cButtonText
  mov tbbi.TBBUTTONINFO.pszText, xdi
  mov tbbi.TBBUTTONINFO.cchText, lengthof cButtonText - 1

  mov xbx, [xsi].pToolbarFile
  SetButtonText IDM_FILE_OPEN, 1
  SetButtonText IDM_FILE_SAVE, 2
  SetButtonText IDM_FILE_SAVEAS, 3
  SetButtonText IDM_FILE_CLOSE, 4
  SetButtonText IDM_FILE_PRINT, 5
  SetButtonText IDM_FILE_PIN, 10

  mov xbx, [xsi].pToolbarEdit
  SetButtonText IDM_EDIT_CUT, 21
  SetButtonText IDM_EDIT_COPY, 22
  SetButtonText IDM_EDIT_PASTE, 23
  SetButtonText IDM_EDIT_ERASE, 24
  SetButtonText IDM_EDIT_ERASEALL, 26
  SetButtonText IDM_EDIT_FIND, 28

  mov xbx, [xsi].pToolbarWindow
  SetButtonText IDM_WINDOW_CASCADE, 51
  SetButtonText IDM_WINDOW_TILE_HOR, 52
  SetButtonText IDM_WINDOW_TILE_VER, 53
  SetButtonText IDM_WINDOW_ARRANGE, 54
  SetButtonText IDM_WINDOW_CLOSEALL, 59
  SetButtonText IDM_WINDOW_ZOOMIN, 57
  SetButtonText IDM_WINDOW_ZOOMOUT, 58
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DebugCenter.Done
; Purpose:    Finalize the MDI application object. Objects associated with window controls are
;             destroyed by Windows automatically when WM_DESTROY is send.
; Arguments:  None.
; Return:     Nothing.

Method DebugCenter.Done, uses xsi
  SetObject xsi
  invoke DeleteObject, [xsi].hFont
  invoke StrDispose, [xsi].pDirectory
  .if [xsi].hDevMode != 0
    invoke GlobalFree, [xsi].hDevMode
  .endif
  .if [xsi].hDevNames != 0
    invoke GlobalFree, [xsi].hDevNames
  .endif

  Destroy [xsi].pClientWnd
  Destroy [xsi].pIconImageList
  Destroy [xsi].pRebar
  Destroy [xsi].pStatusbar
  Destroy [xsi].pToolbarFile
  Destroy [xsi].pToolbarEdit
  Destroy [xsi].pToolbarWindow
  Destroy [xsi].pXMenu
  Destroy [xsi].pMagnetism

  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DebugCenter.EnableActions
; Purpose:    Enable or disable MDI child actions.
; Arguments:  Arg1: Enable TRUE/False.
; Return:     Nothing.

Method DebugCenter.EnableActions, uses xsi, dAction:DWORD
  SetObject xsi
  OCall [xsi].pToolbarFile::Toolbar.BtnEnable, IDM_FILE_CLOSE, dAction

  OCall [xsi].pToolbarWindow::Toolbar.BtnEnable, IDM_WINDOW_CASCADE,  dAction
  OCall [xsi].pToolbarWindow::Toolbar.BtnEnable, IDM_WINDOW_TILE_HOR, dAction
  OCall [xsi].pToolbarWindow::Toolbar.BtnEnable, IDM_WINDOW_TILE_VER, dAction
  OCall [xsi].pToolbarWindow::Toolbar.BtnEnable, IDM_WINDOW_ARRANGE,  dAction
  OCall [xsi].pToolbarWindow::Toolbar.BtnEnable, IDM_WINDOW_CLOSEALL, dAction
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DebugCenter.Init
; Purpose:    Initialize the MDI application object.
; Arguments:  None.
; Return:     Nothing.

Method DebugCenter.Init, uses xbx xdi xsi
  local WP:WINDOWPLACEMENT, pRegKey:POINTER, dState:DWORD, cBuffer[MAX_PATH]:CHR

  SetObject xsi
  ACall xsi.Init

  ;Startup
  mov [xsi].pCommandLine, $invoke(GetCommandLine)
  invoke LoadCommonControls, ICC_COOL_CLASSES or ICC_BAR_CLASSES  ;Rebar & Statusbar

  ;Load Icons
  mov xbx, $New(MaskedImageList)
  OCall xbx::MaskedImageList.Init, xsi, 16, 16, 1
  mov [xsi].pIconImageList, xbx
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_APP")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_APP_CHILD_TXT")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_APP_CHILD_BMP")

  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_OPEN")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_SAVE")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_SAVEAS")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_CLOSE")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_PAGESETUP")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_PRINTERSETUP")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_PRINT")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_PIN")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_SETUP")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_EXIT")

  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_EDIT_CUT")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_EDIT_COPY")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_EDIT_PASTE")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_EDIT_CLEAR")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_EDIT_ERASE")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_EDIT_ERASEALL")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_EDIT_FIND")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_EDIT_CALC")

  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_CASCADE")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_TILE_HOR")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_TILE_VER")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_ARRANGE")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_NEXT")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_PREV")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_ZOOMIN")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_ZOOMOUT")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_CLOSEALL")

  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_HELP_HELP")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_HELP_ABOUT")

  ;Obtain handles for possible menus and submenus
  mov [xsi].hMenuInit, $invoke(LoadMenu, hInstance, $OfsCStr("MDIMENUINIT"))
  mov [xsi].hMenuChild, $invoke(LoadMenu, hInstance, $OfsCStr("MDIMENUCHILD"))
  mov [xsi].hMenuChildWnd, $invoke(GetSubMenu, [xsi].hMenuChild, 3)
  mov [xsi].hMenuSysTray, $invoke(LoadMenu, hInstance, $OfsCStr("SYSTRAYMENU"))
  mov [xsi].hMenuContext, $invoke(LoadMenu, hInstance, $OfsCStr("CONTEXTMENU"))

  ;Load accelerators
  mov [xsi].hAccelerators, $invoke(LoadAccelerators, hInstance, $OfsCStr("HOTKEYS"))

  ;Recover settings from previous session
  mov WP.length_, sizeof(WINDOWPLACEMENT)
  xor eax, eax
  mov WP.flags, eax
  dec eax
  mov WP.ptMinPosition.x, eax
  mov WP.ptMinPosition.y, eax
  mov WP.ptMaxPosition.x, eax
  mov WP.ptMaxPosition.y, eax

  mov pRegKey, $New(RegKey)
  OCall pRegKey::RegKey.Init, xsi, offset cDbgRegKey, HKEY_CURRENT_USER
  OCall pRegKey::RegKey.Open
  .if [xsi].dErrorCode != OBJ_OK
    OCall xsi.ErrorClear
    OCall pRegKey::RegKey.Create
  .endif
  invoke Parse, addr cBuffer, [xsi].pCommandLine, 0
  OCall pRegKey::RegKey.ValueSetStr, offset szPath, addr cBuffer

  OCall pRegKey::RegKey.ValueGetDW, offset szState
  .if [xsi].dErrorCode == OBJ_OK
    mov dState, eax
    BitClr eax, DBG_PINNED or DBG_BMP
  .else
    OCall xsi.ErrorClear
    mov eax, SW_SHOWNORMAL
    mov dState, eax
  .endif
  mov WP.showCmd, eax

  OCall pRegKey::RegKey.ValueGetDW, offset szLeftPos
  .if [xsi].dErrorCode != OBJ_OK
    OCall xsi.ErrorClear
    invoke CenterForm, DEFAULT_WIDTH, $32($invoke(GetSystemMetrics, SM_CXSCREEN))
  .endif
  mov WP.rcNormalPosition.left, eax

  OCall pRegKey::RegKey.ValueGetDW, offset szTopPos
  .if [xsi].dErrorCode != OBJ_OK
    OCall xsi.ErrorClear
    invoke CenterForm, DEFAULT_HEIGHT, $32($invoke(GetSystemMetrics, SM_CYSCREEN))
  .endif
  mov WP.rcNormalPosition.top, eax

  OCall pRegKey::RegKey.ValueGetDW, offset szRightPos
  .if [xsi].dErrorCode != OBJ_OK
    OCall xsi.ErrorClear
    mov eax, WP.rcNormalPosition.left
    add eax, DEFAULT_WIDTH
  .endif
  mov WP.rcNormalPosition.right, eax

  OCall pRegKey::RegKey.ValueGetDW, offset szBottomPos
  .if [xsi].dErrorCode != OBJ_OK
    OCall xsi.ErrorClear
    mov eax, WP.rcNormalPosition.top
    add eax, DEFAULT_HEIGHT
  .endif
  mov WP.rcNormalPosition.bottom, eax

  OCall pRegKey::RegKey.ValueGetDW, offset szLanguage
  .if [xsi].dErrorCode != OBJ_OK
    OCall xsi.ErrorClear
    mov eax, IDLANG_ENGLISH
  .endif
  mov [xsi].dLanguage, eax

  OCall pRegKey::RegKey.ValueGetDW, offset szTxtZoom
  .if [xsi].dErrorCode != OBJ_OK
    OCall xsi.ErrorClear
    mov eax, TXT_ZOOM_DEFAULT
  .else
    .if eax < TXT_ZOOM_MIN
      mov eax, TXT_ZOOM_MIN
    .elseif eax > TXT_ZOOM_MAX
      mov eax, TXT_ZOOM_MAX
    .endif
  .endif
  mov [xsi].dTxtZoomFactor, eax

  OCall pRegKey::RegKey.ValueGetDW, offset szBmpZoom
  .if [xsi].dErrorCode != OBJ_OK
    OCall xsi.ErrorClear
    mov eax, BMP_ZOOM_DEFAULT
  .else
    .if eax < BMP_ZOOM_MIN
      mov eax, BMP_ZOOM_MIN
    .elseif eax > BMP_ZOOM_MAX
      mov eax, BMP_ZOOM_MAX
    .endif
  .endif

  OCall pRegKey::RegKey.ValueGetStr, offset szDirectory, NULL, 0
  .if [xsi].dErrorCode == OBJ_OK
    mov edi, eax
    mov [xsi].pDirectory, $invoke(StrAlloc, eax)
    OCall pRegKey::RegKey.ValueGetStr, offset szDirectory, xax, edi
  .else
    OCall xsi.ErrorClear
    .if $invoke(GetEnvironmentVariable, offset szOAPath, addr cBuffer, lengthof cBuffer) == 0
      mov [xsi].pDirectory, $invoke(StrNew, offset szDefDirectory)
    .else
      mov [xsi].pDirectory, $invoke(StrNew, addr cBuffer)
    .endif
  .endif

  OCall pRegKey::RegKey.Close

  Destroy pRegKey

  ;Create the MDI Frame Window
  invoke CreateWindowEx, WS_EX_APPWINDOW or WS_EX_WINDOWEDGE,
                         offset szDbgCtrCls, \
                         offset szAppTitle, WS_OVERLAPPEDWINDOW or WS_CLIPCHILDREN, \
                         0, 0, DEFAULT_WIDTH, DEFAULT_HEIGHT, \
                         NULL, [xsi].hMenuInit, hInstance, pSelf
  .if eax != 0                                          ;Check if we could create the main window
    ;Create Client window
    mov [xsi].pClientWnd, $New(DbgMdiClient)
    OCall [xsi].pClientWnd::DbgMdiClient.Init, xsi

    ;Create XMenu
    mov [xsi].pXMenu, $New(XMenu)
    mov xdi, $MethodAddr(DebugCenter.StatusbarHelp)
    mov xax, [xsi].pClientWnd
    OCall [xsi].pXMenu::XMenu.Init, xsi, [xsi].hWnd, [xax].$Obj(DbgMdiClient).hWnd, \
                                    [xsi].hMenuChildWnd, xbx, \
                                    xdi, IDLANG_ENGLISH
    OCall xsi.ChangeLanguage, [xsi].dLanguage           ;Update Language menu

    ;Reposition main window
    invoke SetWindowPlacement, [xsi].hWnd, addr WP
    invoke UpdateWindow, [xsi].hWnd

    ;Set Z order
    .ifBitSet dState, DBG_PINNED
      mov xbx, HWND_TOPMOST
      mov eax, BST_PUSHED or BST_CHECKED
    .else
      mov xbx, HWND_NOTOPMOST
      mov eax, BST_PUSHED
    .endif
    mov xcx, [xsi].pToolbarFile
    invoke SendMessage, [xcx].$Obj(Toolbar).hWnd, TB_SETSTATE, IDM_FILE_PIN, eax
    invoke SetWindowPos, [xsi].hWnd, xbx, 0, 0, 0, 0, SWP_NOSIZE or SWP_NOMOVE

    mov [xsi].pMagnetism, $New(Magnetism)
    OCall [xsi].pMagnetism::Magnetism.Init, xsi, [xsi].hWnd, 10

    OCall xsi.ManageOptions, 0
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DebugCenter.ManageOptions
; Purpose:    Manage menu and toolbar buttons.
; Arguments:  Arg1: ObjectID activated, zero for none.
; Return:     Nothing.

Method DebugCenter.ManageOptions, uses xbx xdi xsi, dObjID:DWORD
  local hMenu:HMENU

  SetObject xsi
  mov hMenu, $invoke(GetMenu, [xsi].hWnd)     ;Get the current menu
  .if dObjID == 0
    mov xbx, [xsi].pToolbarFile
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_FILE_SAVE, FALSE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_FILE_SAVEAS, FALSE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_FILE_CLOSE, FALSE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_FILE_PRINT, FALSE

    mov xbx, [xsi].pToolbarEdit
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_CUT, FALSE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_COPY, FALSE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_PASTE, FALSE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_ERASE, FALSE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_ERASEALL, FALSE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_FIND, FALSE

    mov xbx, [xsi].pToolbarWindow
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_WINDOW_ZOOMIN, FALSE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_WINDOW_ZOOMOUT, FALSE

    mov xdi, hMenu
    invoke EnableMenuItem, xdi, IDM_FILE_SAVE,      MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xdi, IDM_FILE_SAVEAS,    MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xdi, IDM_FILE_CLOSE,     MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xdi, IDM_FILE_PAGESETUP, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xdi, IDM_FILE_PRINT,     MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xdi, IDM_EDIT_CUT,       MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xdi, IDM_EDIT_COPY,      MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xdi, IDM_EDIT_PASTE,     MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xdi, IDM_EDIT_CLEAR,     MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xdi, IDM_EDIT_SELECTALL, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xdi, IDM_EDIT_ERASE,     MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xdi, IDM_EDIT_ERASEALL,  MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xdi, IDM_EDIT_FIND,      MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xdi, IDM_EDIT_CALC,      MF_BYCOMMAND or MF_GRAYED

    mov xdi, [xsi].hMenuContext
    invoke EnableMenuItem, xdi, IDM_EDIT_CUT,       MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xdi, IDM_EDIT_COPY,      MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xdi, IDM_EDIT_PASTE,     MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xdi, IDM_EDIT_CLEAR,     MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xdi, IDM_EDIT_SELECTALL, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xdi, IDM_EDIT_ERASE,     MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xdi, IDM_EDIT_ERASEALL,  MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xdi, IDM_EDIT_FIND,      MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xdi, IDM_EDIT_CALC,      MF_BYCOMMAND or MF_GRAYED

  .elseif dObjID == DBG_MDI_CHILD_TXT_ID
    mov xbx, [xsi].pToolbarFile
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_FILE_SAVE, TRUE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_FILE_SAVEAS, TRUE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_FILE_CLOSE, TRUE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_FILE_PRINT, TRUE

    mov xbx, [xsi].pToolbarEdit
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_ERASE, TRUE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_ERASEALL, TRUE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_FIND, TRUE

    mov xbx, [xsi].pToolbarWindow
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_WINDOW_ZOOMIN, TRUE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_WINDOW_ZOOMOUT, TRUE

    mov xdi, hMenu
    invoke EnableMenuItem, xdi, IDM_FILE_SAVE,      MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xdi, IDM_FILE_SAVEAS,    MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xdi, IDM_FILE_CLOSE,     MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xdi, IDM_FILE_PAGESETUP, MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xdi, IDM_FILE_PRINT,     MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xdi, IDM_EDIT_SELECTALL, MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xdi, IDM_EDIT_ERASE,     MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xdi, IDM_EDIT_ERASEALL,  MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xdi, IDM_EDIT_FIND,      MF_BYCOMMAND or MF_ENABLED

    mov xdi, [xsi].hMenuContext
    invoke EnableMenuItem, xdi, IDM_EDIT_SELECTALL, MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xdi, IDM_EDIT_ERASE,     MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xdi, IDM_EDIT_ERASEALL,  MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xdi, IDM_EDIT_FIND,      MF_BYCOMMAND or MF_ENABLED

  .else                                                 ;DbgMdiChildBmp
    mov xbx, [xsi].pToolbarFile
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_FILE_SAVE, TRUE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_FILE_SAVEAS, TRUE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_FILE_CLOSE, TRUE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_FILE_PRINT, TRUE

    mov xbx, [xsi].pToolbarEdit
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_ERASE, TRUE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_ERASEALL, TRUE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_EDIT_FIND, FALSE

    mov xbx, [xsi].pToolbarWindow
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_WINDOW_ZOOMIN, TRUE
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_ENABLEBUTTON, IDM_WINDOW_ZOOMOUT, TRUE

    mov xdi, hMenu
    invoke EnableMenuItem, xdi, IDM_FILE_OPEN,      MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xdi, IDM_FILE_SAVE,      MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xdi, IDM_FILE_SAVEAS,    MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xdi, IDM_FILE_CLOSE,     MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xdi, IDM_FILE_PAGESETUP, MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xdi, IDM_FILE_PRINT,     MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xdi, IDM_EDIT_SELECTALL, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xdi, IDM_EDIT_ERASE,     MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xdi, IDM_EDIT_ERASEALL,  MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xdi, IDM_EDIT_FIND,      MF_BYCOMMAND or MF_GRAYED

    mov xdi, [xsi].hMenuContext
    invoke EnableMenuItem, xdi, IDM_EDIT_SELECTALL, MF_BYCOMMAND or MF_GRAYED
    invoke EnableMenuItem, xdi, IDM_EDIT_ERASE,     MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xdi, IDM_EDIT_ERASEALL,  MF_BYCOMMAND or MF_ENABLED
    invoke EnableMenuItem, xdi, IDM_EDIT_FIND,      MF_BYCOMMAND or MF_GRAYED
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  CBTProc
; Purpose:    Customization procedure using SetWindowsHookEx.
; Arguments:  Arg1: Hook code.
;             Arg2: Depends on hook code. For HCBT_ACTIVATE, wParam = hWnd.
;             Arg3: Depends on hook code. For HCBT_ACTIVATE, lParam -> CBTACTIVATESTRUCT.
; Return:     eax = Zero if handled.

CBTProc proc uses xbx dCode:DWORD, wParam:WPARAM, lParam:LPARAM
  local cText[16]:CHR

  .if dCode == HCBT_ACTIVATE
    lea xbx, cText

    mov edx, $ObjTmpl(DebugCenter).dLanguage
    add edx, 102
    invoke LoadString, hInstance, edx, xbx, lengthof cText
    invoke GetDlgItem, wParam, IDYES
    invoke SetWindowText, xax, xbx

    mov edx, $ObjTmpl(DebugCenter).dLanguage
    add edx, 103
    invoke LoadString, hInstance, edx, xbx, lengthof cText
    invoke GetDlgItem, wParam, IDNO
    invoke SetWindowText, xax, xbx

    invoke UnhookWindowsHookEx, hCBTProc

    xor eax, eax
  .else
    invoke CallNextHookEx, hCBTProc, dCode, wParam, lParam
  .endif
  ret
CBTProc endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DebugCenter.OnClose
; Purpose:    Event procedure for WM_CLOSE (and WM_QUERYENDSESSION) message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DebugCenter.OnClose, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local dMsg:DWORD
  local cCaption[512]:CHR, cText[1024]:CHR

  SetObject xsi
  mov dMsg, eax                                         ;Save windows message passed in eax
  invoke GetKeyState, VK_CONTROL
  mov xbx, [xsi].pClientWnd
  and ax, BIT15
  .if ZERO? || dMsg != WM_CLOSE                         ;If CTRL pressed => close without asking
    .if [xbx].$Obj(DbgMdiClient).dChildCount != 0       ;Ask only if a child window is open
      mov edx, [xsi].dLanguage
      add edx, 100
      invoke LoadString, hInstance, edx, addr cCaption, lengthof cCaption
      mov edx, [xsi].dLanguage
      add edx, 101
      invoke LoadString, hInstance, edx, addr cText, lengthof cText

      ;MessageBox customization
      invoke SetWindowsHookEx, WH_CBT, offset CBTProc, hInstance, $32($invoke(GetCurrentThreadId))
      mov hCBTProc, xax
      invoke MessageBox, [xsi].hWnd, addr cText, addr cCaption, MB_YESNO + MB_ICONQUESTION
      .if eax == IDNO
        xor eax, eax
        ExitMethod
      .endif
    .endif
  .endif
  invoke Shell_NotifyIcon, NIM_DELETE, addr [xsi].NotifyIconData  ;If exist, delete Tray Icon
  invoke DefFrameProc, [xsi].hWnd, [xbx].$Obj(DbgMdiClient).hWnd, dMsg, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DebugCenter.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

CloseChild proc hWnd:HWND, lParam:DWORD
  invoke SendMessage, hWnd, WM_GETOBJECTINSTANCE, 0, 0
  .if eax != NULL
    invoke SendMessage, hWnd, WM_CLOSE, 0, 0
  .endif
  mov eax, TRUE                                         ;Continue enumeration
  ret
CloseChild endp

EraseChild proc hWnd:HWND, lParam:DWORD
  invoke SendMessage, hWnd, WM_GETOBJECTINSTANCE, 0, 0
  .if xax != NULL
    OCall xax::DbgMdiChild.Erase
  .endif
  mov eax, TRUE                                         ;Continue enumeration
  ret
EraseChild endp

Method DebugCenter.OnCommand, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local hChildWnd:HWND, pDlg:POINTER, pChild:POINTER, cMsg[1024]:CHR
  local OpenFileName:OPENFILENAME, cInitDir[MAX_PATH]:CHR, cFileName[MAX_PATH]:CHR
  local PageSetup:PAGESETUPDLG, AboutDlg:$Obj(DialogAbout)

  SetObject xsi
  mov xcx, [xsi].pClientWnd
  mov xax, wParam
  mov xbx, [xcx].$Obj(DbgMdiClient).hWnd

  ; %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

  .if ax == IDM_FILE_OPEN
    mov OpenFileName.lStructSize, sizeof(OPENFILENAME)
    m2m OpenFileName.hwndOwner, [xsi].hWnd, xax
    m2m OpenFileName.hInstance, hInstance, xcx
    m2m OpenFileName.lpstrFilter, offset szLoadFilter, eax
    m2z OpenFileName.lpstrCustomFilter
    m2z OpenFileName.nMaxCustFilter
    m2z OpenFileName.nFilterIndex
    lea xax, cFileName
    m2z CHR ptr [xax]
    mov OpenFileName.lpstrFile, xax
    mov OpenFileName.nMaxFile, lengthof cFileName - 1
    m2z OpenFileName.lpstrFileTitle
    m2z OpenFileName.nMaxFileTitle
    lea xax, cInitDir
    m2z CHR ptr [xax]
    m2m OpenFileName.lpstrInitialDir, [xsi].pDirectory, eax
    c2m OpenFileName.lpstrTitle, $OfsCStr("Open file..."), xcx
    m2m OpenFileName.lpstrDefExt, offset szRtfExt, xax
    mov OpenFileName.Flags, OFN_EXPLORER or OFN_FILEMUSTEXIST or OFN_LONGNAMES or OFN_HIDEREADONLY
    invoke GetOpenFileName, addr OpenFileName

    .if eax != 0
      inc [xsi].dChildNumber
      invoke StrRScan, addr cFileName, "."
      .if xax != NULL
        mov xdi, xax
        invoke StrIComp, xdi, offset szRtfExt
        .if eax == 0
          mov xdi, $New(DbgMdiChildTxt)
          OCall xdi::DbgMdiChildTxt.Init, [xsi].pClientWnd, addr cFileName, [xsi].hFont, DBG_COLOR_FOREGROUND_WND_LIGHT
          OCall xdi::DbgMdiChildTxt.Open, addr cFileName
        .else
          invoke StrIComp, xdi, offset szBmpExt
          .if eax == 0
            mov xdi, $New(DbgMdiChildBmp)
            OCall xdi::DbgMdiChildBmp.Init, [xsi].pClientWnd, addr cFileName, DBG_COLOR_BACKGROUND_WND_LIGHT
            OCall xdi::DbgMdiChildBmp.Open, addr cFileName
          .else
            mov edx, $ObjTmpl(DebugCenter).dLanguage
            add edx, 123
            invoke LoadString, hInstance, edx, addr cMsg, lengthof cMsg - 1
            invoke MessageBox, [xsi].hWnd, addr cMsg, offset szDebugCenter, MB_OK or MB_ICONERROR
          .endif
        .endif
        ;Remember this new path
        invoke StrRScan, addr cFileName, "\"
        .if xax != NULL
          m2z CHR ptr [xax]
          invoke StrDispose, [xsi].pDirectory
          mov [xsi].pDirectory, $invoke(StrNew, addr cFileName)
        .endif
      .endif
    .endif
    xor eax, eax

  .elseif ax == IDM_FILE_SAVE
    invoke SendMessage, xbx, WM_MDIGETACTIVE, 0, 0
    .if xax
      invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
      OCall xax::DbgMdiChild.Save
    .endif
    xor eax, eax

  .elseif ax == IDM_FILE_SAVEAS
    invoke SendMessage, xbx, WM_MDIGETACTIVE, 0, 0
    .if xax
      invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
      OCall xax::DbgMdiChild.SaveAs, NULL, NULL
    .endif
    xor eax, eax

  .elseif (ax == IDM_FILE_CLOSE) || (ax == SC_CLOSE)    ;Close the active window
    mov hChildWnd, $invoke(SendMessage, xbx, WM_MDIGETACTIVE, 0, 0)
    invoke SendMessage, hChildWnd, WM_CLOSE, 0, 0
    xor eax, eax

  .elseif ax == IDM_FILE_PAGESETUP
    mov PageSetup.lStructSize, sizeof(PageSetup)
    m2m PageSetup.hwndOwner, [xsi].hWnd, xax
    m2m PageSetup.hDevMode, [xsi].hDevMode, xcx
    m2m PageSetup.hDevNames, [xsi].hDevNames, xax
    mov PageSetup.Flags, PSD_INHUNDREDTHSOFMILLIMETERS or PSD_MARGINS or PSD_MINMARGINS
    m2z PageSetup.ptPaperSize.x
    m2z PageSetup.ptPaperSize.y
    m2z PageSetup.rtMinMargin.left
    m2z PageSetup.rtMinMargin.top
    m2z PageSetup.rtMinMargin.right
    m2z PageSetup.rtMinMargin.bottom
    s2s PageSetup.rtMargin, [xsi].PrintMargin, xax, xcx
    m2m PageSetup.hInstance, hInstance, xax
    m2z PageSetup.lCustData
    m2z PageSetup.lpfnPageSetupHook
    m2z PageSetup.lpfnPagePaintHook
    m2z PageSetup.lpPageSetupTemplateName
    m2z PageSetup.hPageSetupTemplate
    .if $invoke(PageSetupDlg, addr PageSetup)
      m2m [xsi].hDevMode, PageSetup.hDevMode, xax
      m2m [xsi].hDevNames, PageSetup.hDevNames, xcx
      s2s [xsi].PrintMargin, PageSetup.rtMargin, xax, xcx
    .endif
    xor eax, eax

  .elseif ax == IDM_FILE_PRINT
    invoke SendMessage, xbx, WM_MDIGETACTIVE, 0, 0
    .if xax
      invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
      OCall xax::DbgMdiChild.Print
    .endif
    xor eax, eax

  .elseif ax == IDM_FILE_PIN
    mov xdi, [xsi].pToolbarFile
    invoke SendMessage, [xdi].$Obj(Toolbar).hWnd, TB_GETSTATE, IDM_FILE_PIN, 0
    .if lParam == 0                 ;Message comes from a menu item => toolbar has to be informed!
      .ifBitSet eax, TBSTATE_CHECKED
        BitClr eax, TBSTATE_CHECKED
        invoke SendMessage, [xdi].$Obj(Toolbar).hWnd, TB_SETSTATE, IDM_FILE_PIN, eax
        invoke SetWindowPos, [xsi].hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOSIZE or SWP_NOMOVE
      .else
        BitSet eax, TBSTATE_CHECKED
        invoke SendMessage, [xdi].$Obj(Toolbar).hWnd, TB_SETSTATE, IDM_FILE_PIN, eax
        invoke SetWindowPos, [xsi].hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOSIZE or SWP_NOMOVE
      .endif
    .else
      .ifBitSet eax, TBSTATE_CHECKED
        invoke SetWindowPos, [xsi].hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOSIZE or SWP_NOMOVE
      .else
        invoke SetWindowPos, [xsi].hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOSIZE or SWP_NOMOVE
      .endif
    .endif
    xor eax, eax


  .elseif ax == IDM_FILE_EXIT
    invoke SendMessage, [xsi].hWnd, WM_CLOSE, 0, 0
    xor eax, eax

  ; %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

  .elseif ax == IDM_EDIT_COPY
    invoke SendMessage, xbx, WM_MDIGETACTIVE, 0, 0
    .if xax
      invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
      OCall xax::DbgMdiChild.ClpBrdCopy                 ;Polymorphic call
    .endif
    xor eax, eax

  .elseif ax == IDM_EDIT_CUT
    invoke SendMessage, xbx, WM_MDIGETACTIVE, 0, 0
    .if xax
      invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
      OCall xax::DbgMdiChild.ClpBrdCut                  ;Polymorphic call
    .endif
    xor eax, eax

  .elseif ax == IDM_EDIT_PASTE
    invoke SendMessage, xbx, WM_MDIGETACTIVE, 0, 0
    .if xax
      invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
      OCall xax::DbgMdiChild.ClpBrdPaste                ;Polymorphic call
    .endif
    xor eax, eax

  .elseif ax == IDM_EDIT_CLEAR
    invoke SendMessage, xbx, WM_MDIGETACTIVE, 0, 0
    .if xax
      invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
      OCall xax::DbgMdiChild.ClpBrdClear                ;Polymorphic call
    .endif
    xor eax, eax

  .elseif ax == IDM_EDIT_ERASE
    invoke SendMessage, xbx, WM_MDIGETACTIVE, 0, 0
    .if xax
      invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
      OCall xax::DbgMdiChild.Erase                      ;Polymorphic call
    .endif
    xor eax, eax

  .elseif ax == IDM_EDIT_ERASEALL
    invoke EnumChildWindows, xbx, offset EraseChild, 0
    xor eax, eax

  .elseif ax == IDM_EDIT_SELECTALL
    invoke SendMessage, xbx, WM_MDIGETACTIVE, 0, 0
    .if xax
      mov xdi, $invoke(SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0)
      invoke GetObjectID, xdi
      .if eax == DBG_MDI_CHILD_TXT_ID
        OCall xdi::DbgMdiChildTxt.SelectAll
        mov xcx, [xdi].$Obj(DbgMdiChildTxt).hEdit
        invoke SetFocus, xcx
        xor eax, eax
      .endif
    .endif
    xor eax, eax

  .elseif ax == IDM_EDIT_FIND
    invoke SendMessage, xbx, WM_MDIGETACTIVE, 0, 0
    mov pChild, $invoke(SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0)
    invoke GetObjectID, xax
    .if eax == DBG_MDI_CHILD_TXT_ID
      mov xcx, pChild
      mov xdi, [xcx].$Obj(DbgMdiChildTxt).pEdtIptor
      .if [xdi].$Obj(REdtIptor).pFindDialog == NULL
        invoke SendMessage, [xdi].$Obj(REdtIptor).hWnd, EM_SETSEL, 0, 0 ;Move caret to 1st position
        mov pDlg, $New(DialogFindText)
        OCall pDlg::DialogFindText.Init, xsi, [xdi].$Obj(REdtIptor).hWnd, NULL
        OCall pDlg::DialogFindText.Show
        mov xcx, pChild
        mov xax, [xcx].$Obj(DbgMdiChildTxt).pEdtIptor
        m2m [xax].$Obj(REdtIptor).pFindDialog, pDlg, xdx
      .else
        mov xax, [xdi].$Obj(REdtIptor).pFindDialog
        invoke SetFocus, [xax].$Obj(DialogFindText).hWnd
      .endif
    .endif
    xor eax, eax


  .elseif ax == IDM_EDIT_CALC
    invoke SendMessage, xbx, WM_MDIGETACTIVE, 0, 0
    mov pChild, $invoke(SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0)
    invoke GetObjectID, xax
    .if eax == DBG_MDI_CHILD_TXT_ID
      mov xcx, pChild
      OCall [xcx].$Obj(DbgMdiChildTxt).pEdtIptor::REdtIptor.SendToCalc
    .endif
    xor eax, eax

  ; %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

  .elseif (ax >= IDM_LANGUAGE_ENGLISH) && (ax <= IDM_LANGUAGE_SPANISH)
    ;Calculate IDLANG_XXX
    sub eax, IDM_LANGUAGE_ENGLISH
    mov ecx, LANGUAGE_STEP
    mul ecx
    OCall xsi.ChangeLanguage, eax
    xor eax, eax

  ; %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

  .elseif ax == IDM_WINDOW_TILE_HOR
    invoke SendMessage, xbx, WM_MDITILE, MDITILE_HORIZONTAL, 0
    xor eax, eax

  .elseif ax == IDM_WINDOW_TILE_VER
    invoke SendMessage, xbx, WM_MDITILE, MDITILE_VERTICAL, 0
    xor eax, eax

  .elseif ax == IDM_WINDOW_CASCADE
    invoke SendMessage, xbx, WM_MDICASCADE, 0, 0
    xor eax, eax

  .elseif ax == IDM_WINDOW_ARRANGE
    invoke SendMessage, xbx, WM_MDIICONARRANGE, 0, 0
    xor eax, eax

  .elseif ax == IDM_WINDOW_NEXT
    invoke SendMessage, xbx, WM_MDINEXT, 0, 0
    xor eax, eax

  .elseif ax == IDM_WINDOW_PREV
    invoke SendMessage, xbx, WM_MDINEXT, 0, -1
    xor eax, eax

  .elseif ax == IDM_WINDOW_CLOSEALL                     ;Attempt to close all windows
    invoke EnumChildWindows, xbx, offset CloseChild, 0
    xor eax, eax

  .elseif ax == SC_RESTORE                              ;Restore the active window
    mov hChildWnd, $invoke(SendMessage, xbx, WM_MDIGETACTIVE, 0, 0)
    invoke SendMessage, xbx, WM_MDIRESTORE, hChildWnd, 0
    xor eax, eax

  .elseif ax == SC_MINIMIZE                             ;Minimize the active window
    mov hChildWnd, $invoke(SendMessage, xbx, WM_MDIGETACTIVE, 0, 0)
    invoke ShowWindow, xax, SW_MINIMIZE
    xor eax, eax

  .elseif ax == SC_MAXIMIZE                             ;Maximize the active window
    mov hChildWnd, $invoke(SendMessage, xbx, WM_MDIGETACTIVE, 0, 0)
    invoke ShowWindow, xax, SW_MAXIMIZE
    xor eax, eax

  .elseif ax == IDM_WINDOW_ZOOMIN
    invoke SendMessage, xbx, WM_MDIGETACTIVE, 0, 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      OCall xax::DbgMdiChild.ZoomIn                     ;Polymorphic call
    .endif
    xor eax, eax

  .elseif ax == IDM_WINDOW_ZOOMOUT
    invoke SendMessage, xbx, WM_MDIGETACTIVE, 0, 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      OCall xax::DbgMdiChild.ZoomOut                    ;Polymorphic call
    .endif
    xor eax, eax

  ; %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

  .elseif ax == IDM_HELP_HELP
    invoke ExpandEnvironmentStrings, $OfsCStr("%OBJASM_PATH%\Help\ObjAsm_Reference_Volume-I.pdf"), \
                                     addr cFileName, lengthof(cFileName)
    invoke PdfView, [xsi].hWnd, addr cFileName, $OfsCStr("Debugging")
    xor eax, eax

  .elseif ax == IDM_HELP_ABOUT
    New AboutDlg::DialogAbout
    OCall AboutDlg::DialogAbout.Init, xsi, [xsi].hWnd
    OCall AboutDlg::DialogAbout.Show
    OCall AboutDlg::DialogAbout.Done
    xor eax, eax

  ; %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

  .elseif ax == IDM_DEBUG_CENTER_RESTORE
    .if lParam == 0
      invoke Shell_NotifyIcon, NIM_DELETE, addr [xsi].NotifyIconData
      invoke ShowWindow, [xsi].hWnd, SW_RESTORE
    .endif
    xor eax, eax

  ; %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

  ;Pass to active child
  .else
    invoke SendMessage, xbx, WM_MDIGETACTIVE, 0, 0
    invoke SendMessage, xax, WM_COMMAND, wParam, lParam
  .endif

MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DebugCenter.OnCopyData
; Purpose:    Event procedure for WM_COPYDATA message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = TRUE if handled.

DBG_CHILD_INFO struc
  pCaption    PSTRINGW              ?
  pChild      $ObjPtr(DbgMdiChild)  ?
  dObjID      DWORD                 ?                   ;DBG_MDI_CHILD_TXT_ID or DbgMdiClhildBmpID
DBG_CHILD_INFO ends
PDBG_CHILD_INFO typedef ptr DBG_CHILD_INFO

ChildSearch proc uses xbx xdi hWnd:HWND, lParam:PDBG_CHILD_INFO
  local cBuffer[1024]:CHR

  mov xbx, lParam
  invoke SendMessage, hWnd, WM_GETTEXT, lengthof cBuffer, addr cBuffer
  .if $invoke(StrComp, addr cBuffer, [xbx].DBG_CHILD_INFO.pCaption) == 0
    invoke SendMessage, hWnd, WM_GETOBJECTINSTANCE, 0, 0
    .if [xbx].DBG_CHILD_INFO.dObjID != 0
      mov xdi, xax
      invoke GetObjectID, xdi
      .if eax == [xbx].DBG_CHILD_INFO.dObjID
        mov [xbx].DBG_CHILD_INFO.pChild, xdi
        xor eax, eax                                    ;Stop enumeration
      .else
        mov eax, TRUE                                   ;Continue enumeration
      .endif
    .else
      mov [xbx].DBG_CHILD_INFO.pChild, xax
      xor eax, eax                                      ;Stop enumeration
    .endif
  .else
    mov eax, TRUE                                       ;Continue enumeration
  .endif
  ret
ChildSearch endp

Method DebugCenter.OnCopyData, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local CFD:CHARFORMAT, DCI:DBG_CHILD_INFO, dDbgCmd:DWORD, dParam1:DWORD, dParam2:DWORD, FWI:FLASHWINFO

  SetObject xsi
  mov xcx, lParam
  .if [xcx].COPYDATASTRUCT.dwData == DGB_MSG_ID         ;Yes!, our message...
    mov xbx, [xcx].COPYDATASTRUCT.lpData
    .if xbx != NULL
      mov xdi, [xsi].pClientWnd
      mov xcx, xbx
      mov eax, [xbx].DBG_HEADER_INFO.dBlockLen
      add xcx, xax
      .if [xcx].DBG_HEADER_INFO.bBlockID == DBG_MSG_CMD    ;Command
        movzx eax, [xcx].DBG_CMD_INFO.bInfo
        .if eax == DBG_CMD_CLEAR_TXT || eax == DBG_CMD_CLEAR_BMP
          m2m dParam1, [xcx].DBG_CMD_INFO.dParam1, edx
          .if eax == DBG_CMD_CLEAR_TXT
            mov DCI.dObjID, DBG_MDI_CHILD_TXT_ID
          .else
            mov DCI.dObjID, DBG_MDI_CHILD_BMP_ID
          .endif
          m2z DCI.pChild
          mov DCI.pCaption, $addr(xbx + DBG_HEADER_INFO)
          invoke EnumChildWindows, [xdi].$Obj(DbgMdiClient).hWnd, offset ChildSearch, addr DCI
          .if DCI.pChild != NULL
            OCall DCI.pChild::DbgMdiChild.Erase
          .endif

        .elseif eax ==  DBG_CMD_CLEAR_ALL
          invoke EnumChildWindows, [xdi].$Obj(DbgMdiClient).hWnd, offset EraseChild, 0

        .elseif eax == DBG_CMD_CLOSE_TXT || eax == DBG_CMD_CLOSE_BMP
          .if eax == DBG_CMD_CLEAR_TXT
            mov DCI.dObjID, DBG_MDI_CHILD_TXT_ID
          .else
            mov DCI.dObjID, DBG_MDI_CHILD_BMP_ID
          .endif
          m2z DCI.pChild
          mov DCI.pCaption, $addr(xbx + DBG_HEADER_INFO)
          invoke EnumChildWindows, [xdi].$Obj(DbgMdiClient).hWnd, offset ChildSearch, addr DCI
          .if DCI.pChild != NULL
            mov xcx, DCI.pChild
            invoke SendMessage, [xcx].$Obj(DbgMdiChild).hWnd, WM_CLOSE, 0, 0
          .endif

        .elseif eax == DBG_CMD_CLOSE_ALL
          invoke EnumChildWindows, [xdi].$Obj(DbgMdiClient).hWnd, offset CloseChild, 0

        .elseif eax == DBG_CMD_SINGLE_LINE || eax == DBG_CMD_DOUBLE_LINE
          mov dDbgCmd, eax
          m2m dParam1, [xcx].DBG_CMD_INFO.dParam1, edx
          m2m dParam2, [xcx].DBG_CMD_INFO.dParam2, eax
          mov DCI.pCaption, $addr(xbx + DBG_HEADER_INFO)
          m2z DCI.pChild
          mov DCI.dObjID, DBG_MDI_CHILD_TXT_ID
          invoke EnumChildWindows, [xdi].$Obj(DbgMdiClient).hWnd, offset ChildSearch, addr DCI
          .if DCI.pChild == NULL
            mov xdi, $New(DbgMdiChildTxt)
            OCall xdi::DbgMdiChildTxt.Init, [xsi].pClientWnd, addr [xbx + DBG_HEADER_INFO], [xsi].hFont, dParam2
          .else
            mov xdi, DCI.pChild
          .endif
          invoke ShowWindow, [xdi].$Obj(DbgMdiChildTxt).hEdit, SW_SHOW
          invoke SendMessage, [xdi].$Obj(DbgMdiChildTxt).hEdit, EM_SETSEL, -1, -1   ;Move caret to last position
          mov CFD.cbSize, sizeof(CFD)
          mov CFD.dwMask, CFM_COLOR or CFM_BOLD or CFM_ITALIC or CFM_STRIKEOUT or CFM_UNDERLINE

          ;m2z CFD.crTextColor
          m2m CFD.crTextColor, dParam1, eax

          m2z CFD.dwEffects
          invoke SendMessage, [xdi].$Obj(DbgMdiChildTxt).hEdit, EM_SETCHARFORMAT, SCF_SELECTION, addr CFD
          .if dDbgCmd == DBG_CMD_SINGLE_LINE
            invoke SendMessageW, [xdi].$Obj(DbgMdiChildTxt).hEdit, EM_REPLACESEL, FALSE, offset cSingleLine
          .elseif dDbgCmd == DBG_CMD_DOUBLE_LINE
            invoke SendMessageW, [xdi].$Obj(DbgMdiChildTxt).hEdit, EM_REPLACESEL, FALSE, offset cDoubleLine
          .endif
          invoke SendMessageW, [xdi].$Obj(DbgMdiChildTxt).hEdit, EM_REPLACESEL, FALSE, offset wCRLF

        .elseif eax == DBG_CMD_SET_BKGND_TXT
          m2m dParam1, [xcx].DBG_CMD_INFO.dParam1, edx
          mov DCI.pCaption, $addr(xbx + DBG_HEADER_INFO)
          m2z DCI.pChild
          mov DCI.dObjID, DBG_MDI_CHILD_TXT_ID
          invoke EnumChildWindows, [xdi].$Obj(DbgMdiClient).hWnd, offset ChildSearch, addr DCI
          .if DCI.pChild != NULL
            mov xdi, DCI.pChild
            invoke SendMessage, [xdi].$Obj(DbgMdiChildTxt).hEdit, EM_SETBKGNDCOLOR, 0, dParam1
            invoke InvalidateRect, [xdi].$Obj(DbgMdiChildTxt).hEdit, NULL, TRUE
          .endif

        .elseif eax == DBG_CMD_SET_BKGND_BMP
          m2m dParam1, [xcx].DBG_CMD_INFO.dParam1, edx
          mov DCI.pCaption, $addr(xbx + DBG_HEADER_INFO)
          m2z DCI.pChild
          mov DCI.dObjID, DBG_MDI_CHILD_BMP_ID
          invoke EnumChildWindows, [xdi].$Obj(DbgMdiClient).hWnd, offset ChildSearch, addr DCI
          .if DCI.pChild != NULL
            mov xdi, DCI.pChild
            m2m [xdi].$Obj(DbgMdiChildBmp).dBackColor, dParam1, edx
            invoke InvalidateRect, [xdi].$Obj(DbgMdiChildBmp).hWnd, NULL, TRUE
          .endif

        .elseif eax == DBG_CMD_ZOOM_IN_TXT
          mov DCI.pCaption, $addr(xbx + DBG_HEADER_INFO)
          m2z DCI.pChild
          mov DCI.dObjID, DBG_MDI_CHILD_TXT_ID
          invoke EnumChildWindows, [xdi].$Obj(DbgMdiClient).hWnd, offset ChildSearch, addr DCI
          .if DCI.pChild != NULL
            OCall DCI.pChild::DbgMdiChild.ZoomIn        ;Polymorphic call
          .endif

        .elseif eax == DBG_CMD_ZOOM_IN_BMP
          mov DCI.pCaption, $addr(xbx + DBG_HEADER_INFO)
          m2z DCI.pChild
          mov DCI.dObjID, DBG_MDI_CHILD_BMP_ID
          invoke EnumChildWindows, [xdi].$Obj(DbgMdiClient).hWnd, offset ChildSearch, addr DCI
          .if DCI.pChild != NULL
            OCall DCI.pChild::DbgMdiChild.ZoomIn        ;Polymorphic call
          .endif

        .elseif eax == DBG_CMD_ZOOM_OUT_TXT
          mov DCI.pCaption, $addr(xbx + DBG_HEADER_INFO)
          m2z DCI.pChild
          mov DCI.dObjID, DBG_MDI_CHILD_TXT_ID
          invoke EnumChildWindows, [xdi].$Obj(DbgMdiClient).hWnd, offset ChildSearch, addr DCI
          .if DCI.pChild != NULL
            OCall DCI.pChild::DbgMdiChild.ZoomOut       ;Polymorphic call
          .endif

        .elseif eax == DBG_CMD_ZOOM_OUT_BMP
          mov DCI.pCaption, $addr(xbx + DBG_HEADER_INFO)
          m2z DCI.pChild
          mov DCI.dObjID, DBG_MDI_CHILD_BMP_ID
          invoke EnumChildWindows, [xdi].$Obj(DbgMdiClient).hWnd, offset ChildSearch, addr DCI
          .if DCI.pChild != NULL
            OCall DCI.pChild::DbgMdiChild.ZoomOut       ;Polymorphic call
          .endif

        .elseif eax == DBG_CMD_FRONT_WND
          invoke SetForegroundWindow, [xsi].hWnd

        .elseif eax == DBG_CMD_FRONT_TXT
          mov DCI.pCaption, $addr(xbx + DBG_HEADER_INFO)
          m2z DCI.pChild
          mov DCI.dObjID, DBG_MDI_CHILD_TXT_ID
          invoke EnumChildWindows, [xdi].$Obj(DbgMdiClient).hWnd, offset ChildSearch, addr DCI
          .if DCI.pChild != NULL
            mov xax, DCI.pChild
            mov xdx, [xsi].pClientWnd
            mov xcx, [xdx].$Obj(DbgMdiClient).hWnd
            invoke SendMessage, xcx, WM_MDIACTIVATE, [xax].$Obj(DbgMdiChild).hWnd, 0
          .endif

        .elseif eax == DBG_CMD_FRONT_BMP
          mov DCI.pCaption, $addr(xbx + DBG_HEADER_INFO)
          m2z DCI.pChild
          mov DCI.dObjID, DBG_MDI_CHILD_BMP_ID
          invoke EnumChildWindows, [xdi].$Obj(DbgMdiClient).hWnd, offset ChildSearch, addr DCI
          .if DCI.pChild != NULL
            mov xax, DCI.pChild
            mov xdx, [xsi].pClientWnd
            mov xcx, [xdx].$Obj(DbgMdiClient).hWnd
            invoke SendMessage, xcx, WM_MDIACTIVATE, [xax].$Obj(DbgMdiChild).hWnd, 0
          .endif

        .elseif eax == DBG_CMD_CHILDREN_TILE_HOR
          invoke SendMessage, [xdi].$Obj(DbgMdiClient).hWnd, WM_MDITILE, MDITILE_HORIZONTAL, 0

        .elseif eax == DBG_CMD_CHILDREN_TILE_VER
          invoke SendMessage, [xdi].$Obj(DbgMdiClient).hWnd, WM_MDITILE, MDITILE_VERTICAL, 0

        .elseif eax == DBG_CMD_CHILDREN_CASCADE
          invoke SendMessage, [xdi].$Obj(DbgMdiClient).hWnd, WM_MDICASCADE, 0, 0

        .elseif eax == DBG_CMD_ICONS_ARRANGE
          invoke SendMessage, [xdi].$Obj(DbgMdiClient).hWnd, WM_MDIICONARRANGE, 0, 0

        .elseif eax == DBG_CMD_FLASH_MENU
          mov edx, [xcx].DBG_CMD_INFO.dParam1
          mov eax, [xcx].DBG_CMD_INFO.dParam2
          OCall [xsi].pXMenu::XMenu.FlashMenuBar, edx, eax

        .elseif eax == DBG_CMD_FLASH_WINDOW
          mov FWI.cbSize, sizeof(FWI)
          m2m FWI.hwnd, [xsi].hWnd, xax
          m2m FWI.dwFlags, [xcx].DBG_CMD_INFO.dParam1, edx
          m2m FWI.uCount, [xcx].DBG_CMD_INFO.dParam2, eax
          mov FWI.dwTimeout, 0
          invoke FlashWindowEx, addr FWI

        .elseif eax == DBG_CMD_PIN_WND
          m2m dParam1, [xcx].DBG_CMD_INFO.dParam1, edx
          mov xbx, [xsi].pToolbarFile
          invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_GETSTATE, IDM_FILE_PIN, 0
          .ifBitSet eax, TBSTATE_CHECKED
            .if dParam1 == FALSE
              BitClr eax, TBSTATE_CHECKED
              invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_SETSTATE, IDM_FILE_PIN, eax
              invoke SetWindowPos, [xsi].hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOSIZE or SWP_NOMOVE
            .endif
          .else
            .if dParam1 != FALSE
              BitSet eax, TBSTATE_CHECKED
              invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_SETSTATE, IDM_FILE_PIN, eax
              invoke SetWindowPos, [xsi].hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOSIZE or SWP_NOMOVE
            .endif
          .endif

        .elseif eax == DBG_CMD_CLOSE_WND
          invoke Shell_NotifyIcon, NIM_DELETE, addr [xsi].NotifyIconData  ;If exist, delete Tray Icon
          invoke DefFrameProc, [xsi].hWnd, [xdi].$Obj(DbgMdiClient).hWnd, WM_CLOSE, 0, 0

        .endif

      .elseif [xcx].DBG_HEADER_INFO.bBlockID == DBG_MSG_STR             ;Text (ANSI or WIDE)
        m2m dParam2, [xcx].DBG_STR_INFO.dBackColor, eax                       
        mov DCI.pCaption, $addr(xbx + DBG_HEADER_INFO)
        m2z DCI.pChild
        mov DCI.dObjID, DBG_MDI_CHILD_TXT_ID
        invoke EnumChildWindows, [xdi].$Obj(DbgMdiClient).hWnd, offset ChildSearch, addr DCI
        .if DCI.pChild == NULL
          mov xdi, $New(DbgMdiChildTxt)
          OCall xdi::DbgMdiChildTxt.Init, [xsi].pClientWnd, addr [xbx + DBG_HEADER_INFO], [xsi].hFont, dParam2
        .else
          mov xdi, DCI.pChild
        .endif
        invoke ShowWindow, [xdi].$Obj(DbgMdiChildTxt).hEdit, SW_SHOW
        invoke SendMessage, [xdi].$Obj(DbgMdiChildTxt).hEdit, EM_SETSEL, -1, -1   ;Move caret to last position
        mov eax, [xbx].DBG_HEADER_INFO.dBlockLen
        add xbx, xax
        mov CFD.cbSize, sizeof(CFD)
        mov CFD.dwMask, CFM_COLOR or CFM_BOLD or CFM_ITALIC or CFM_STRIKEOUT or CFM_UNDERLINE
        m2m CFD.crTextColor, [xbx].DBG_STR_INFO.dForeColor, eax
        mov eax, [xbx].DBG_STR_INFO.dEffects
        BitClr eax, DBG_CHARTYPE_WIDE
        mov CFD.dwEffects, eax
        invoke SendMessage, [xdi].$Obj(DbgMdiChildTxt).hEdit, EM_SETCHARFORMAT, SCF_SELECTION, addr CFD
        .ifBitSet [xbx].DBG_STR_INFO.dEffects, DBG_CHARTYPE_WIDE
          invoke SendMessageW, [xdi].$Obj(DbgMdiChildTxt).hEdit, EM_REPLACESEL, FALSE, addr [xbx + sizeof(DBG_STR_INFO)]
          mov eax, [xbx].DBG_STR_INFO.dEffects
          .ifBitSet eax, DBG_EFFECT_NEWLINE
            invoke SendMessageW, [xdi].$Obj(DbgMdiChildTxt).hEdit, EM_REPLACESEL, FALSE, offset wCRLF
          .endif
        .else
          invoke SendMessageA, [xdi].$Obj(DbgMdiChildTxt).hEdit, EM_REPLACESEL, FALSE, addr [xbx + sizeof(DBG_STR_INFO)]
          mov eax, [xbx].DBG_STR_INFO.dEffects
          .ifBitSet eax, DBG_EFFECT_NEWLINE
            invoke SendMessageA, [xdi].$Obj(DbgMdiChildTxt).hEdit, EM_REPLACESEL, FALSE, offset bCRLF
          .endif
        .endif
        xor eax, eax
        mov CFD.crTextColor, eax
        mov CFD.dwEffects, eax
        invoke SendMessage, [xdi].$Obj(DbgMdiChildTxt).hEdit, EM_SETCHARFORMAT, SCF_SELECTION, addr CFD
        invoke SendMessage, [xdi].$Obj(DbgMdiChildTxt).hEdit, EM_SCROLL, SB_LINEDOWN, 0 ;Scroll down
        invoke SendMessage, [xdi].$Obj(DbgMdiChildTxt).hEdit, EM_SETSEL, -1, -1         ;Move caret to last position
        invoke SendMessage, [xdi].$Obj(DbgMdiChildTxt).hEdit, EM_SCROLLCARET, 0, 0      ;Make caret visible

      .elseif [xcx].DBG_HEADER_INFO.bBlockID == DBG_MSG_BMP     ;Bitmap
        m2m dParam2, [xcx].DBG_BMP_INFO.dBackColor, eax                       
        mov DCI.pCaption, $addr(xbx + DBG_HEADER_INFO)
        m2z DCI.pChild
        mov DCI.dObjID, DBG_MDI_CHILD_BMP_ID
        invoke EnumChildWindows, [xdi].$Obj(DbgMdiClient).hWnd, offset ChildSearch, addr DCI
        .if DCI.pChild == NULL
          mov xdi, $New(DbgMdiChildBmp)
          OCall xdi::DbgMdiChildBmp.Init, [xsi].pClientWnd, addr [xbx + DBG_HEADER_INFO], dParam2
        .else
          mov xdi, DCI.pChild
        .endif
        mov xdx, xbx
        mov eax, [xbx].DBG_HEADER_INFO.dBlockLen
        add xdx, xax
        OCall xdi::DbgMdiChildBmp.SetBitmap, xdx
        invoke RedrawWindow, [xdi].$Obj(DbgMdiChildBmp).hWnd, NULL, NULL, RDW_INVALIDATE or RDW_UPDATENOW
      .else
        ;Not implemented features
      .endif

      xor eax, eax
      inc eax                                           ;Return TRUE
    .else
      xor eax, eax
    .endif
  .else
    invoke DefWindowProc, [xsi].hWnd, WM_COPYDATA, wParam, lParam
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DebugCenter.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DebugCenter.OnCreate, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local LogFnt:LOGFONT, hDC:HDC

  SetObject xsi

  mov [xsi].pStatusbar, $New(Statusbar)
  OCall xax::Statusbar.Init, xsi, [xsi].hWnd, offset AppStatusbar

  mov [xsi].pRebar, $New(Rebar)
  OCall xax::Rebar.Init, xsi, [xsi].hWnd

  ;Create Window Toolbar
  mov [xsi].pToolbarWindow, $New(Toolbar)
  OCall [xsi].pToolbarWindow::Toolbar.Init, xsi, [xsi].hWnd, offset ToolbarWindow, \
             [xsi].pIconImageList, NULL, NULL
  mov ebx, $32($OCall([xsi].pToolbarWindow::Toolbar.GetWidth))
  OCall [xsi].pToolbarWindow::Toolbar.GetHeight
  mov xdx, [xsi].pToolbarWindow
  OCall [xsi].pRebar::Rebar.InsertBand, [xdx].$Obj(Toolbar).hWnd, ebx, eax

  ;Create Edit Toolbar
  mov [xsi].pToolbarEdit, $New(Toolbar)
  OCall [xsi].pToolbarEdit::Toolbar.Init, xsi, [xsi].hWnd, offset ToolbarEdit, \
             [xsi].pIconImageList, NULL, NULL
  mov ebx, $32($OCall([xsi].pToolbarEdit::Toolbar.GetWidth))
  OCall [xsi].pToolbarEdit::Toolbar.GetHeight
  mov xdx, [xsi].pToolbarEdit
  OCall [xsi].pRebar::Rebar.InsertBand, [xdx].$Obj(Toolbar).hWnd, ebx, eax

  ;Create File Toolbar
  mov [xsi].pToolbarFile, $New(Toolbar)
  OCall [xsi].pToolbarFile::Toolbar.Init, xsi, [xsi].hWnd, offset ToolbarFile, \
             [xsi].pIconImageList, NULL, NULL
  mov ebx, $32($OCall([xsi].pToolbarFile::Toolbar.GetWidth))
  OCall [xsi].pToolbarFile::Toolbar.GetHeight
  mov xdx, [xsi].pToolbarFile
  OCall [xsi].pRebar::Rebar.InsertBand, [xdx].$Obj(Toolbar).hWnd, ebx, eax

  FillString LogFnt.lfFaceName, <DBG_FONT_TEXT>

  mov hDC, $invoke(GetDC, [xsi].hWnd)
  invoke GetDeviceCaps, hDC, LOGPIXELSY
  invoke MulDiv, 8, eax, -72
  mov LogFnt.lfHeight, eax
  m2z LogFnt.lfWidth
  m2z LogFnt.lfEscapement
  m2z LogFnt.lfOrientation
  mov LogFnt.lfWeight, FW_DONTCARE
  m2z LogFnt.lfItalic
  m2z LogFnt.lfUnderline
  m2z LogFnt.lfStrikeOut
  mov LogFnt.lfCharSet, DEFAULT_CHARSET
  mov LogFnt.lfOutPrecision, OUT_DEFAULT_PRECIS
  mov LogFnt.lfClipPrecision, CLIP_DEFAULT_PRECIS
  mov LogFnt.lfQuality, CLEARTYPE_QUALITY
  mov LogFnt.lfPitchAndFamily, DEFAULT_PITCH or FF_DONTCARE
  mov [xsi].hFont, $invoke(CreateFontIndirect, addr LogFnt)
  invoke ReleaseDC, [xsi].hWnd, hDC

  OCall xsi.EnableActions, FALSE

  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DebugCenter.OnDestroy
; Purpose:    Event procedure for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method DebugCenter.OnDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  local WP:WINDOWPLACEMENT, pRegKey:POINTER

  SetObject xsi
  .if [xsi].hMenuChild
    invoke DestroyMenu, [xsi].hMenuChild
  .endif
  .if [xsi].hMenuSysTray
    invoke DestroyMenu, [xsi].hMenuSysTray
  .endif
  .if [xsi].hMenuContext
    invoke DestroyMenu, [xsi].hMenuContext
  .endif

  mov WP.length_, sizeof(WINDOWPLACEMENT)
  invoke GetWindowPlacement, [xsi].hWnd, addr WP
  mov pRegKey, $New(RegKey)
  OCall pRegKey::RegKey.Init, xsi, offset cDbgRegKey, HKEY_CURRENT_USER
  OCall pRegKey::RegKey.Create

  ;Save settings for next session
  mov xcx, [xsi].pToolbarFile
  invoke SendMessage, [xcx].$Obj(Toolbar).hWnd, TB_GETSTATE, IDM_FILE_PIN, 0
  .ifBitSet eax, BST_CHECKED
    BitSet WP.showCmd, DBG_PINNED
  .endif
  OCall pRegKey::RegKey.ValueSetDW, offset szState,     WP.showCmd
  OCall pRegKey::RegKey.ValueSetDW, offset szLeftPos,   WP.rcNormalPosition.left
  OCall pRegKey::RegKey.ValueSetDW, offset szTopPos,    WP.rcNormalPosition.top
  OCall pRegKey::RegKey.ValueSetDW, offset szRightPos,  WP.rcNormalPosition.right
  OCall pRegKey::RegKey.ValueSetDW, offset szBottomPos, WP.rcNormalPosition.bottom
  OCall pRegKey::RegKey.ValueSetDW, offset szLanguage, [xsi].dLanguage
  OCall pRegKey::RegKey.ValueSetDW, offset szTxtZoom,  [xsi].dTxtZoomFactor
  OCall pRegKey::RegKey.ValueSetDW, offset szBmpZoom,  [xsi].dBmpZoomFactor
  OCall pRegKey::RegKey.ValueSetStr, offset szDirectory, [xsi].pDirectory
  OCall pRegKey::RegKey.ValueSetStr, offset szVersion, $OfsCStr("&VER_PRODUCTVERSION_STR")
  OCall pRegKey::RegKey.Close
  Destroy pRegKey
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DebugCenter.OnEraseBkgnd
; Purpose:    Event procedure for WM_ERASEBKGND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Non zero => we do the job.

Method DebugCenter.OnEraseBkgnd,, wParam:WPARAM, lParam:LPARAM
  mov eax, 1
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DebugCenter.OnNotify
; Purpose:    Event procedure for WM_NOTIFY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DebugCenter.OnNotify,, wParam:WPARAM, lParam:LPARAM
;  DbgText "DebugCenter.OnNotify"
  SetObject xcx
  mov xax, lParam
  assume xax: ptr TOOLTIPTEXT
  .if [xax].hdr.code == TTN_NEEDTEXT
    mov edx, [xcx].dLanguage
    .if [xax].hdr.idFrom == IDM_FILE_OPEN
      add edx, 80
    .elseif [xax].hdr.idFrom == IDM_FILE_SAVE
      add edx, 81
    .elseif [xax].hdr.idFrom == IDM_FILE_SAVEAS
      add edx, 82
    .elseif [xax].hdr.idFrom == IDM_FILE_CLOSE
      add edx, 83
    .elseif [xax].hdr.idFrom == IDM_FILE_PRINT
      add edx, 84
    .elseif [xax].hdr.idFrom == IDM_FILE_PIN
      add edx, 85
    .elseif [xax].hdr.idFrom == IDM_EDIT_CUT
      add edx, 86
    .elseif [xax].hdr.idFrom == IDM_EDIT_COPY
      add edx, 87
    .elseif [xax].hdr.idFrom == IDM_EDIT_PASTE
      add edx, 88
    .elseif [xax].hdr.idFrom == IDM_EDIT_ERASE
      add edx, 89
    .elseif [xax].hdr.idFrom == IDM_EDIT_ERASEALL
      add edx, 90
    .elseif [xax].hdr.idFrom == IDM_EDIT_FIND
      add edx, 91
    .elseif [xax].hdr.idFrom == IDM_WINDOW_CASCADE
      add edx, 92
    .elseif [xax].hdr.idFrom == IDM_WINDOW_TILE_HOR
      add edx, 93
    .elseif [xax].hdr.idFrom == IDM_WINDOW_TILE_VER
      add edx, 94
    .elseif [xax].hdr.idFrom == IDM_WINDOW_ARRANGE
      add edx, 95
    .elseif [xax].hdr.idFrom == IDM_WINDOW_CLOSEALL
      add edx, 96
    .elseif [xax].hdr.idFrom == IDM_WINDOW_ZOOMIN
      add edx, 97
    .elseif [xax].hdr.idFrom == IDM_WINDOW_ZOOMOUT
      add edx, 98
    .else
      xor eax, eax
      inc eax
      ExitMethod
    .endif
    mov [xax].lpszText, xdx
    m2m [xax].hinst, hInstance, xcx

    xor eax, eax
  .else
    invoke DefWindowProc, [xcx].hWnd, WM_NOTIFY, wParam, lParam
  .endif
  assume xax:NOTHING
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DebugCenter.OnShellNotify
; Purpose:    Event procedure for WM_SHELLNOTIFY message.
; Arguments:  None.
; Return:     Nothing.

Method DebugCenter.OnShellNotify, uses xsi, wParam:WPARAM, lParam:LPARAM
  local Pnt:POINT

  SetObject xsi
  .if wParam == IDI_TRAY
    .if lParam == WM_RBUTTONDOWN
      invoke GetCursorPos, addr Pnt
      invoke SetForegroundWindow, [xsi].hWnd
      invoke GetSubMenu, [xsi].hMenuSysTray, 0
      invoke TrackPopupMenu, xax, TPM_RIGHTALIGN, Pnt.x, Pnt.y, 0, [xsi].hWnd, NULL
      invoke PostMessage, [xsi].hWnd, WM_NULL, 0, 0
    .elseif lParam == WM_LBUTTONDBLCLK
      invoke SendMessage, [xsi].hWnd, WM_COMMAND, IDM_DEBUG_CENTER_RESTORE, 0
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DebugCenter.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method DebugCenter.OnSize, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local CRect:RECT, RbRect:RECT, SbRect:RECT
  local dTop:DWORD, dHeight:DWORD, dCWidth:DWORD

  SetObject xsi
  .if wParam == SIZE_MINIMIZED
    mov [xsi].NotifyIconData.cbSize, sizeof(NOTIFYICONDATA)
    m2m [xsi].NotifyIconData.hWnd, [xsi].hWnd, xax
    mov [xsi].NotifyIconData.uID, IDI_TRAY
    mov [xsi].NotifyIconData.uFlags, NIF_ICON + NIF_MESSAGE + NIF_TIP
    mov [xsi].NotifyIconData.uCallbackMessage, WM_SHELLNOTIFY
    mov [xsi].NotifyIconData.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
    invoke StrCCopy, addr [xsi].NotifyIconData.szTip, offset szAppTitle, 63   ;Limit to 64-1 chars
    invoke ShowWindow, [xsi].hWnd, SW_HIDE
    invoke Shell_NotifyIcon, NIM_ADD, addr [xsi].NotifyIconData
  .else
    invoke GetClientRect, [xsi].hWnd, addr CRect
    m2m dHeight, CRect.bottom, eax
    m2m dCWidth, CRect.right, ecx

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
      invoke InvalidateRect, [xbx].$Obj(DbgMdiClient).hWnd, NULL, FALSE
      invoke MoveWindow, [xbx].$Obj(DbgMdiClient).hWnd, 0, dTop, dCWidth, dHeight, TRUE
    .endif

  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DebugCenter.Startup
; Purpose:    Register the object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method DebugCenter.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof(WNDCLASSEX)
  mov WC.style, CLSSTYLE
  m2m WC.lpfnWndProc, $MethodAddr(DebugCenter.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  m2z WC.hbrBackground
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szDbgCtrCls, xax
  invoke LoadImage, hInstance, $OfsCStr("ICON_APP"), IMAGE_ICON, 0, 0, LR_LOADREALSIZE
  mov WC.hIcon, xax
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DebugCenter.StatusbarHelp
; Purpose:    Display a help string on panel 0 of the statusbar.
; Arguments:  Arg1: -> Help string.
; Return:     Nothing.

Method DebugCenter.StatusbarHelp,, pHelpStr:PSTRING
  SetObject xcx
  OCall [xcx].pStatusbar::Statusbar.SetPartText, 0, pHelpStr, SBT_NOBORDERS
MethodEnd



; ==================================================================================================
;    DbgMdiClient implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiClient.Done
; Purpose:    Finalize the DbgMdiClient object.
; Arguments:  None.
; Return:     Nothing.

Method DbgMdiClient.Done
  SetObject xcx
  invoke DeleteObject, [xcx].hBGBrush
  ACall Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiClient.Init
; Purpose:    Initialize the MdiClientWnd object.
; Arguments:  Arg1: -> Owner object.
; Return:     Nothing.

Method DbgMdiClient.Init, uses xsi, pOwner:POINTER
  local hBmp:HBITMAP

  SetObject xsi
  ACall xsi.Init, pOwner
  mov hBmp, $invoke(LoadBitmap, hInstance, $OfsCStr("BMP_BACKGROUND"))
  mov [xsi].hBGBrush, $invoke(CreatePatternBrush, hBmp)
  invoke DeleteObject, hBmp
  invoke DragAcceptFiles, [xsi].hWnd, TRUE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiClient.OnDropFiles
; Purpose:    Event procedure for WM_DROPFILES message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method DbgMdiClient.OnDropFiles, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local pFileName:PSTRING, cMsg[1024]:CHR

  SetObject xsi
  mov xbx, $invoke(DragQueryFile, wParam, -1, NULL, 0)
  .while xbx > 0
    dec xbx
    invoke DragQueryFile, wParam, ebx, NULL, 0
    inc eax                                             ;Include ZTC
    mov edi, eax
    mov pFileName, $invoke(StrAlloc, eax)
    invoke DragQueryFile, wParam, ebx, xax, edi
    mov xdi, $invoke(StrRScan, pFileName, '.')
    .if xdi != NULL
      .if $invoke(StrComp, xdi, offset szRtfExt) == 0
        mov xdi, $New(DbgMdiChildTxt)
        mov xax, [xsi].pOwner
        OCall xdi::DbgMdiChildTxt.Init, xsi, pFileName, [xax].$Obj(DebugCenter).hFont, DBG_COLOR_FOREGROUND_WND_LIGHT
        OCall xdi::DbgMdiChildTxt.Open, pFileName
      .else
        .if $invoke(StrComp, xdi, offset szBmpExt) == 0
          mov xdi, $New(DbgMdiChildBmp)
          mov xax, [xsi].pOwner
          OCall xdi::DbgMdiChildBmp.Init, xsi, pFileName, DBG_COLOR_BACKGROUND_WND_LIGHT
          OCall xdi::DbgMdiChildBmp.Open, pFileName
        .else
          jmp @@Error
        .endif
      .endif
    .else
      jmp @@Error
    .endif
    jmp @@OK
  @@Error:
    mov edx, $ObjTmpl(DebugCenter).dLanguage
    add edx, 123
    invoke LoadString, hInstance, edx, addr cMsg, lengthof cMsg - 1
    invoke MessageBox, [xsi].hWnd, addr cMsg, \
                       offset szDebugCenter, MB_OK or MB_ICONEXCLAMATION
  @@OK:
    invoke StrDispose, pFileName
  .endw
  invoke DragFinish, wParam
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiClient.OnEraseBkgnd
; Purpose:    Event procedure for WM_ERASEBKGND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Non zero => we do the job.

Method DbgMdiClient.OnEraseBkgnd,, wParam:WPARAM, lParam:LPARAM
  mov eax, 1
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DbgMdiClient.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DbgMdiClient.OnPaint, uses xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, Rct:RECT

  SetObject xsi
  invoke BeginPaint, [xsi].hWnd, addr PS
  invoke GetClientRect, [xsi].hWnd, addr Rct
  invoke FillRect, PS.hdc, addr Rct, [xsi].hBGBrush
  invoke EndPaint, [xsi].hWnd, addr PS
  invoke CallWindowProc, [xsi].pPrevWndProc, [xsi].hWnd, WM_PAINT, wParam, lParam
MethodEnd
