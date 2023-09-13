; ==================================================================================================
; Title:      OA_Tools_Main.inc
; Author:     G. Friedrich
; Version:    See OA_Tools.asm
; Purpose:    ObjAsm Tools.
; ==================================================================================================



CLSSTYLE  equ   CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW

TBSTYLE   equ   WS_CHILD or WS_VISIBLE or WS_CLIPCHILDREN or TBSTYLE_TOOLTIPS or \
                CCS_NORESIZE or CCS_NODIVIDER or CCS_ADJUSTABLE or TBSTYLE_FLAT or TBSTYLE_LIST

SBSTYLE   equ   WS_CHILD or WS_VISIBLE or SBARS_TOOLTIPS or SBARS_SIZEGRIP

.const
ToolbarEdit DEF_TOOLBAR {IDC_TOOLBAR_EDIT, TBSTYLE, TBSTYLE_EX_MIXEDBUTTONS, \
                         $OfsTStr("Edit commands"), {<0,0,0,0>}, 6}
  TBBUTTON {IDB_EDIT_CUT,         IDM_EDIT_CUT,         TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_EDIT_COPY,        IDM_EDIT_COPY,        TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_EDIT_PASTE,       IDM_EDIT_PASTE,       TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_EDIT_DELETE,      IDM_EDIT_DELETE,      TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {-1,                   -1,                   TBSTATE_ENABLED, TBSTYLE_SEP}
  TBBUTTON {IDB_OPEN_EDITOR,      IDM_OPEN_EDITOR,      TBSTATE_ENABLED, TBSTYLE_BUTTON}

ToolbarWindow DEF_TOOLBAR {IDC_TOOLBAR_WINDOW, TBSTYLE, TBSTYLE_EX_MIXEDBUTTONS, \
                           $OfsTStr("Window commands"), {<0,0,0,0>}, 10}
  TBBUTTON {IDB_WINDOW_CASCADE,   IDM_WINDOW_CASCADE,   TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_WINDOW_TILE_HOR,  IDM_WINDOW_TILE_HOR,  TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_WINDOW_TILE_VER,  IDM_WINDOW_TILE_VER,  TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_WINDOW_ARRANGE,   IDM_WINDOW_ARRANGE,   TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {-1,                   -1,                   TBSTATE_ENABLED, TBSTYLE_SEP}
  TBBUTTON {IDB_WINDOW_CLOSE,     IDM_WINDOW_CLOSE,     TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_WINDOW_CLOSE_ALL, IDM_WINDOW_CLOSE_ALL, TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {-1,                   -1,                   TBSTATE_ENABLED, TBSTYLE_SEP}
  TBBUTTON {IDB_ZOOM_IN,          IDM_ZOOM_IN,          TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_ZOOM_OUT,         IDM_ZOOM_OUT,         TBSTATE_ENABLED, TBSTYLE_BUTTON}

AppStatusbar DEF_STATUSBAR {IDC_STATUSBAR, SBSTYLE, 0, 4}
  DEF_STATUSBAR_PART {220, 100, 3, SBT_NOBORDERS, NULL}
  DEF_STATUSBAR_PART {120,  20, 1, SBT_SUNKEN,    NULL}
  DEF_STATUSBAR_PART {120,  -2, 0, SBT_SUNKEN,    NULL} ;Spring
  DEF_STATUSBAR_PART {120, 100, 2, SBT_SUNKEN,    NULL}

DEFAULT_WIDTH     equ     250
DEFAULT_HEIGHT    equ     350


OATF_TEST_MX      equ     BIT00                         ;Mixed mode, can be 32 bit or 64 bit mode
OATF_TEST_32      equ     BIT01                         ;Only BIT00, BIT01 or BIT02 can be set simultaniouly
OATF_TEST_64      equ     BIT02

OATF_TEST_MTD     equ     BIT03                         ;Only BIT03, BIT04 or BIT05 can be set simultaniouly
OATF_TEST_PRC     equ     BIT04
OATF_TEST_MAC     equ     BIT05

OATF_TEST_ARG     equ     BIT06
OATF_TEST_LOC     equ     BIT07
OATF_TEST_REG     equ     BIT08

OATF_TEST_CRLF    equ     BIT09                         ;Only BIT09, BIT10 or BIT11 can be set simultaniouly
OATF_TEST_LF      equ     BIT10
OATF_TEST_CR      equ     BIT11

OATF_TEST_ANNOT   equ     BIT12


Command typedef proto :POINTER, :POINTER, :POINTER

ColorData struc
  Notification      RGBQUAD   {}
  Information       RGBQUAD   {}
  RegError          RGBQUAD   {}
  RegWarning        RGBQUAD   {}
  ArgWarning        RGBQUAD   {}
  LocWarning        RGBQUAD   {}
  Warning           RGBQUAD   {}
  Failure           RGBQUAD   {}
  Bkground          RGBQUAD   {}
ColorData ends

ToolData struct
  pName             PSTRING   ?
  pCommand          PSTRING   ?
ToolData ends

OAT_SETUP struc
  dCloseIfNoFinding DWORD     ?       ;TRUE/FALSE
  dUseAnnotations   DWORD     ?       ;TRUE/FALSE
  dTestBitness      DWORD     ?       ;OATF_TEST_XX (x, e, r)
  dZoomfactor       DWORD     ?       ;Initial value for the OAT_Child
  dLineTerminator   DWORD     ?       ;CRLF = 0, LF = 1, CR = 2
  dFontSize         DWORD     ?       ;10
  cFontFaceName     CHR LF_FULLFACESIZE dup(?)
  pExternalEditor   PSTRING   ?
  Color             ColorData {}
  Tool0             ToolData  {}
  Tool1             ToolData  {}
  Tool2             ToolData  {}
  Tool3             ToolData  {}
  Tool4             ToolData  {}
  Tool5             ToolData  {}
  Tool6             ToolData  {}
  Tool7             ToolData  {}
  Tool8             ToolData  {}
  Tool9             ToolData  {}
OAT_SETUP ends

; ——————————————————————————————————————————————————————————————————————————————————————————————————

Object EditIptor, REDIT_IPTOR_ID, MsgInterceptor
  RedefineMethod    WndProc,            DWORD, WPARAM, LPARAM

  VirtualEvent      OnRButtonDown,      WM_RBUTTONDOWN
  VirtualEvent      OnRButtonUp,        WM_RBUTTONUP
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

Object OAT_Child, OAT_CHILD_ID, MdiChildWnd             ;MDI child window.
  VirtualMethod     AnalyseFile
  VirtualMethod     CheckMtdArg
  VirtualMethod     CheckMtdReg
  VirtualMethod     CheckMtdLoc
  VirtualMethod     CheckPrcArg
  VirtualMethod     CheckPrcLoc
  VirtualMethod     CheckPrcReg
  VirtualMethod     CheckMacArg
  VirtualMethod     CheckMacLoc

  VirtualMethod     ClpBrdClear
  VirtualMethod     ClpBrdCopy
  VirtualMethod     ClpBrdCut
  VirtualMethod     ClpBrdPaste
  VirtualMethod     ClpBrdSetBtns
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, PSTRING, DWORD    ;-> Owner, -> FileName, Flags
  RedefineMethod    OnSize,             WPARAM, LPARAM
  VirtualMethod     Run
  VirtualMethod     SelectAll
  StaticMethod      Startup
  VirtualMethod     WriteA,             PSTRINGA, COLORREF, DWORD  ;-> ANSI string, Color, Effects
  VirtualMethod     WriteW,             PSTRINGW, COLORREF, DWORD  ;-> WIDE string, Color, Effects
  VirtualMethod     WriteLineNumber,    DWORD                      ;Linenumber
  VirtualMethod     WriteResStr,        DWORD, COLORREF, DWORD     ;Resource ID, Color, Effects
  VirtualMethod     ZoomIn
  VirtualMethod     ZoomOut

  VirtualEvent      OnCreate,           WM_CREATE
  VirtualEvent      OnEraseBkgnd,       WM_ERASEBKGND
  VirtualEvent      OnNotify,           WM_NOTIFY


  DefineVariable    pFileName,          PSTRING
  DefineVariable    dFlags,             DWORD,      0

  DefineVariable    dZoom,              DWORD,      ZOOM_BASE
  DefineVariable    hEdit,              HWND,       0
  DefineVariable    hFont,              HFONT,      0
  DefineVariable    Color,              ColorData,  {}

  Embed     EdtIptor,         EditIptor
  Embed     DskStream,        DiskStream                ;-> Source file stream
  Embed     LineLengths,      DataCollection
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

Object OAT_Client, OAT_CLIENT_ID, MdiClientWnd          ;MDI client window.
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER         ;-> Owner

  VirtualEvent      OnDropFiles,        WM_DROPFILES
  VirtualEvent      OnEraseBkgnd,       WM_ERASEBKGND
  VirtualEvent      OnPaint,            WM_PAINT

  DefineVariable    hBGBrush,           HBRUSH,     0   ;Background brush
  DefineVariable    dChildCount,        DWORD,      0
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

Object OAT_App, OAT_APP_ID, MdiApp                      ;MDI application.
  VirtualMethod     ChangeBtnLanguage,  DWORD           ;IDLANG_XXX
  VirtualMethod     ChangeMnuLanguage,  DWORD           ;IDLANG_XXX
  VirtualMethod     ChangeLanguage,     DWORD           ;IDLANG_XXX

  VirtualMethod     CheckDroppedFiles,  DWORD                             ;Flags
  VirtualMethod     CheckSelectedFiles, DWORD                             ;Flags
  RedefineMethod    Done
  VirtualMethod     EnableActions,      DWORD                             ;TRUE/FALSE
  VirtualMethod     ExecuteCommand,     PSTRING, $ObjPtr(OAT_Child)       ;-> Command, -> Child
  VirtualMethod     ExecuteChecks,      PSTRING, DWORD                    ;-> FileName, Flags
  RedefineMethod    Init
  RedefineMethod    OnSize,             WPARAM, LPARAM
  VirtualMethod     SetToolMenu
  StaticMethod      Startup
  VirtualMethod     StatusbarHelp,      PSTRING         ;-> Help string

  VirtualEvent      OnClose,            WM_CLOSE
  VirtualEvent      OnCommand,          WM_COMMAND
  VirtualEvent      OnCreate,           WM_CREATE
  VirtualEvent      OnDestroy,          WM_DESTROY
  VirtualEvent      OnEraseBkgnd,       WM_ERASEBKGND
  VirtualEvent      OnKeyUp,            WM_KEYUP
  VirtualEvent      OnNotify,           WM_NOTIFY

  DefineVariable    dLanguage,          DWORD,      IDLANG_ENGLISH
  DefineVariable    hMenuInit,          HMENU,      0
  DefineVariable    hMenuChild,         HMENU,      0
  DefineVariable    hMenuChildWnd,      HMENU,      0
  DefineVariable    hMenuChildContext,  HMENU,      0
  DefineVariable    hMenuDropContext,   HMENU,      0
  DefineVariable    hDrop,              HDROP,      0

  DefineVariable    pWorkDirectoryW,    PSTRINGW,         NULL  ;-> Work directory (WIDE string) 

  DefineVariable    Setup,              OAT_SETUP,  {}

  Embed     IconImageList,    MaskedImageList
  Embed     RBar,             Rebar
  Embed     Status,           Statusbar
  Embed     TbEdit,           Toolbar
  Embed     TbWindow,         Toolbar
  Embed     Menu,             XMenu
ObjectEnd


; ==================================================================================================
;    OAT_App implementation
; ==================================================================================================

include OA_Tools_Child.inc
include OA_Tools_Client.inc
include OA_Tools_Setup.inc
include OA_Tools_Checks.inc
include OA_Tools_About.inc

.data?
hCBTProc  HANDLE  ?

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  CloseEnumProc (Callback)
; Purpose:    Close all open child windows.
; Arguments:  Arg1: Child window handle.
;             Arg2: Parameter passed from the enumeration procedure.
; Return:     eax = TRUE.

CloseEnumProc proc hWnd:HWND, lParam:LPARAM
  invoke SendMessage, hWnd, WM_CLOSE, 0, 0
  mov eax, TRUE                                         ;TRUE => next window
  ret
CloseEnumProc endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OAT_App.ChangeBtnLanguage
; Purpose:    Switch the toolbar button application language.
; Arguments:  Arg1: Language ID.
; Return:     Nothing.

Method OAT_App.ChangeBtnLanguage, uses xbx xdi xsi, dLanguage:DWORD
  SetButtonText macro ButtonCommand:req, TextIndex:req
    mov eax, dLanguage
    add eax, TextIndex
    invoke LoadString, hInstance, eax, xdi, lengthof cButtonText - 1
    invoke StrLScan, xdi, MENU_CHAR_LITERAL
    .if xax != NULL
      m2z CHR ptr [xax]
    .endif
    invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_SETBUTTONINFO, ButtonCommand, addr tbbi
  endm

  local tbbi:TBBUTTONINFO, cButtonText[256]:CHR, pPos:POINTER

  SetObject xsi

  ANNOTATION use:pPos

  ;Set Toolbar button texts
  mov tbbi.TBBUTTONINFO.cbSize, sizeof TBBUTTONINFO
  mov tbbi.TBBUTTONINFO.dwMask, TBIF_TEXT
  lea xdi, cButtonText
  mov tbbi.TBBUTTONINFO.pszText, xdi
  mov tbbi.TBBUTTONINFO.cchText, lengthof cButtonText - 1

  lea xbx, [xsi].TbEdit
  SetButtonText IDM_EDIT_CUT,      IDS_EDIT_CUT
  SetButtonText IDM_EDIT_COPY,     IDS_EDIT_COPY
  SetButtonText IDM_EDIT_PASTE,    IDS_EDIT_PASTE
  SetButtonText IDM_EDIT_DELETE,   IDS_EDIT_DELETE
  SetButtonText IDM_OPEN_EDITOR,   IDS_OPEN_EDITOR

  lea xbx, [xsi].TbWindow
  SetButtonText IDM_WINDOW_CASCADE,  IDS_WINDOW_CASCADE
  SetButtonText IDM_WINDOW_TILE_HOR, IDS_WINDOW_TILE_HOR
  SetButtonText IDM_WINDOW_TILE_VER, IDS_WINDOW_TILE_VER
  SetButtonText IDM_WINDOW_ARRANGE,  IDS_WINDOW_ARRANGE
  SetButtonText IDM_WINDOW_CLOSE,    IDS_WINDOW_CLOSE
  SetButtonText IDM_WINDOW_CLOSE_ALL, IDS_WINDOW_CLOSE_ALL
  SetButtonText IDM_ZOOM_IN,       IDS_HINT_ZOOM_IN
  SetButtonText IDM_ZOOM_OUT,      IDS_HINT_ZOOM_OUT
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OAT_App.ChangeMnuLanguage
; Purpose:    Set the language radiobutton on the menu.
; Arguments:  Arg1: Language ID.
; Return:     Nothing.

Method OAT_App.ChangeMnuLanguage, uses xdi xsi, dLanguage:DWORD
  SetObject xsi
  mov eax, dLanguage
  cdiv LANGUAGE_STEP
  lea edi, [edx + IDM_LANG_ENGLISH]

  invoke GetMenu, [xsi].hWnd                            ;Get the actual main menu
  invoke GetSubMenu, xax, 0
  invoke GetSubMenu, xax, 1
  invoke CheckMenuRadioItem, xax, IDM_LANG_ENGLISH, IDM_LANG_CHINESE, edi, MF_BYCOMMAND
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OAT_App.ChangeLanguage
; Purpose:    Switch the application language.
; Arguments:  Arg1: Language ID.
; Return:     Nothing.

Method OAT_App.ChangeLanguage, uses xsi, dLanguage:DWORD
  SetObject xsi
  m2m [xsi].dLanguage, dLanguage, eax                   ;Save setting

  OCall xsi.ChangeMnuLanguage, dLanguage
  OCall xsi.ChangeBtnLanguage, dLanguage

  invoke GetMenu, [xsi].hWnd                            ;Get the current menu
  OCall [xsi].Menu::XMenu.ChangeLanguage, xax, dLanguage  ;Active menu is converted
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OAT_App.CheckDroppedFiles
; Purpose:    Perform a check specified by the flags on the dropped files.
; Arguments:  Arg1: Flags: Checks to perform.
; Return:     eax = TRUE if the command was executed or FALSE if the operation was aborted.

Method OAT_App.CheckDroppedFiles, uses xbx xdi xsi, dFlags:DWORD
  local pFileName:PSTRING, MenuBkColor:RGBQUAD
  
  SetObject xsi
  ;Change the color of the MenuBar to signal that the application is working
  m2m MenuBkColor, [xsi].Menu.MenuBarBkColor, ecx
  OCall [xsi].Menu::XMenu.SetMenuBarBkColor, OAT_COLOR_APP_LOCK
  invoke DrawMenuBar, [xsi].Menu.hWnd
  invoke SendMessage, [xsi].hWnd, WM_SETREDRAW, FALSE, 0
  OCall [xsi].Menu::XMenu.SetMenuBarBkColor, MenuBkColor
  invoke DrawMenuBar, [xsi].Menu.hWnd

  mov xbx, $invoke(DragQueryFile, [xsi].hDrop, -1, NULL, 0)
  .while xbx > 0
    dec xbx
    invoke DragQueryFile, [xsi].hDrop, ebx, NULL, 0
    inc eax                                             ;Include ZTC
    mov edi, eax
    mov pFileName, $invoke(StrAlloc, eax)
    invoke DragQueryFile, [xsi].hDrop, ebx, xax, edi
    OCall xsi.ExecuteChecks, pFileName, dFlags
    invoke StrDispose, pFileName
  .endw
  invoke DragFinish, [xsi].hDrop

  mov xax, [xsi].pClientWnd
  invoke SendMessage, [xax].$Obj(OAT_Client).hWnd, WM_MDICASCADE, 0, 0
  invoke SendMessage, [xsi].hWnd, WM_SETREDRAW, TRUE, 0
  invoke RedrawWindow, [xsi].hWnd, NULL, NULL, \
                       RDW_ERASE or RDW_FRAME or RDW_INVALIDATE or RDW_ALLCHILDREN
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OAT_App.CheckSelectedFiles
; Purpose:    Select one or more files and perform a check specified by the flags.
; Arguments:  Arg1: Flags: Checks to perform.
; Return:     eax = TRUE if the command was executed or FALSE if the operation was aborted.

GetResText macro ResID
  lea edx, [ebx + ResID]
  invoke LoadString, hInstance, edx, xdi, lengthof cBuffer
endm

MultiFileSpec_OAT_App struc
  FS0 COMDLG_FILTERSPEC {}
  FS1 COMDLG_FILTERSPEC {}
  FS2 COMDLG_FILTERSPEC {}
MultiFileSpec_OAT_App ends

Method OAT_App.CheckSelectedFiles, uses xbx xdi xsi, dFlags:DWORD
  local pIFODlg: POINTER, MFS:MultiFileSpec_OAT_App, pIFileDialog2:POINTER
  local pISIArr:POINTER, dCount:DWORD, pIShellItem:POINTER, pFileName:POINTER
  local cBuffer[MAX_PATH]:CHR, MenuBkColor:RGBQUAD

  SetObject xsi
  invoke CoCreateInstance, offset CLSID_FileOpenDialog, NULL, CLSCTX_INPROC_SERVER, \
                           offset IID_IFileOpenDialog, addr pIFODlg
  .if SUCCEEDED(eax)
    lea xdi, cBuffer
    mov ebx, [xsi].dLanguage

    GetResText IDS_SELECTION_FILTER_NAME_0
    mov MFS.FS0.pszName, $invoke(StrNew, xdi)
    c2m MFS.FS0.pszSpec, $OfsCStr("*.asm; *.inc"), xax
    GetResText IDS_SELECTION_FILTER_NAME_1
    mov MFS.FS1.pszName, $invoke(StrNew, xdi)
    c2m MFS.FS1.pszSpec, $OfsCStr("*.txt"), xax
    GetResText IDS_SELECTION_FILTER_NAME_2
    mov MFS.FS2.pszName, $invoke(StrNew, xdi)
    c2m MFS.FS2.pszSpec, $OfsCStr("*.*"), xax
  
    ICall pIFODlg::IFileOpenDialog.SetFileTypes, sizeof(MultiFileSpec_OAT_App)/sizeof(COMDLG_FILTERSPEC), \
                                                 addr MFS
    ICall pIFODlg::IFileOpenDialog.SetFileTypeIndex, 0
    ICall pIFODlg::IFileOpenDialog.SetOptions, FOS_ALLOWMULTISELECT or FOS_FILEMUSTEXIST
  
    GetResText IDS_SELECT_FILE
    ICall pIFODlg::IFileOpenDialog.SetTitle, xdi
    GetResText IDS_SELECTION_OPEN
    ICall pIFODlg::IFileOpenDialog.SetOkButtonLabel, xdi
    GetResText IDS_SELECTION_FILE_NAME
    ICall pIFODlg::IFileOpenDialog.SetFileNameLabel, xdi
    
    ICall pIFODlg::IFileOpenDialog.QueryInterface, offset IID_IFileDialog2, addr pIFileDialog2
    .if SUCCEEDED(eax)
      GetResText IDS_CANCEL
      ICall pIFileDialog2::IFileDialog2.SetCancelButtonLabel, xdi
      ICall pIFileDialog2::IFileDialog2.Release
    .endif
    
    invoke SHCreateItemFromParsingName, [xsi].pWorkDirectoryW, NULL, \
                                        offset IID_IShellItem, addr pIShellItem
    ICall pIFODlg::IFileOpenDialog.SetDefaultFolder, pIShellItem
    ICall pIShellItem::IShellItem.Release

    ICall pIFODlg::IFileOpenDialog.Show, [xsi].hWnd
    .if SUCCEEDED(eax)
      ;Change the color of the MenuBar to signal that the application is working
      m2m MenuBkColor, [xsi].Menu.MenuBarBkColor, ecx
      OCall [xsi].Menu::XMenu.SetMenuBarBkColor, OAT_COLOR_APP_LOCK
      invoke DrawMenuBar, [xsi].Menu.hWnd
      invoke SendMessage, [xsi].hWnd, WM_SETREDRAW, FALSE, 0
      OCall [xsi].Menu::XMenu.SetMenuBarBkColor, MenuBkColor
      invoke DrawMenuBar, [xsi].Menu.hWnd
  
      ICall pIFODlg::IFileOpenDialog.GetResults, addr pISIArr
      ICall pISIArr::IShellItemArray.GetCount, addr dCount
      xor ebx, ebx
      .while ebx < dCount
        ICall pISIArr::IShellItemArray.GetItemAt, ebx, addr pIShellItem
        ICall pIShellItem::IShellItem.GetDisplayName, SIGDN_FILESYSPATH, addr pFileName
        OCall xsi.ExecuteChecks, pFileName, dFlags
        ICall pIShellItem::IShellItem.Release
        inc ebx
      .endw
      ICall pISIArr::IShellItemArray.Release
      mov xax, [xsi].pClientWnd
      invoke SendMessage, [xax].$Obj(OAT_Client).hWnd, WM_MDICASCADE, 0, 0
      invoke SendMessage, [xsi].hWnd, WM_SETREDRAW, TRUE, 0
      invoke RedrawWindow, [xsi].hWnd, NULL, NULL, \
                           RDW_ERASE or RDW_FRAME or RDW_INVALIDATE or RDW_ALLCHILDREN
      ICall pIFODlg::IFileOpenDialog.GetFolder, addr pIShellItem
      ICall pIShellItem::IShellItem.GetDisplayName, SIGDN_FILESYSPATH, addr pFileName
      .if [xsi].pWorkDirectoryW != NULL
        invoke StrDispose, [xsi].pWorkDirectoryW
      .endif
      mov [xsi].pWorkDirectoryW, $invoke(StrNewW, pFileName)
      ICall pIShellItem::IShellItem.Release
    .endif
    ICall pIFODlg::IFileOpenDialog.Release
    invoke StrDispose, MFS.FS0.pszName
    invoke StrDispose, MFS.FS1.pszName
    invoke StrDispose, MFS.FS2.pszName
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OAT_App.Done
; Purpose:    Finalize the application object. Objects associated with window controls are
;             destroyed by Windows automatically when WM_DESTROY is send.
; Arguments:  None.
; Return:     Nothing.

Method OAT_App.Done, uses xsi
  SetObject xsi
  .if [xsi].pWorkDirectoryW != NULL
    invoke StrDispose, [xsi].pWorkDirectoryW
  .endif

  OCall [xsi].IconImageList::MaskedImageList.Done
  OCall [xsi].RBar::Rebar.Done
  OCall [xsi].Status::Statusbar.Done
  OCall [xsi].TbEdit::Toolbar.Done
  OCall [xsi].TbWindow::Toolbar.Done

  Destroy [xsi].pClientWnd

  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OAT_App.EnableActions
; Purpose:    Enable or disable MDI child actions.
; Arguments:  Arg1: Enable TRUE/FALSE.
; Return:     Nothing.

Method OAT_App.EnableActions, uses xbx xdi xsi, dAction:DWORD
  SetObject xsi
  OCall [xsi].TbEdit::Toolbar.BtnEnable, IDM_EDIT_CUT,        dAction
  OCall [xsi].TbEdit::Toolbar.BtnEnable, IDM_EDIT_COPY,       dAction
  OCall [xsi].TbEdit::Toolbar.BtnEnable, IDM_EDIT_PASTE,      dAction
  OCall [xsi].TbEdit::Toolbar.BtnEnable, IDM_EDIT_DELETE,     dAction
  OCall [xsi].TbEdit::Toolbar.BtnEnable, IDM_OPEN_EDITOR,     dAction

  OCall [xsi].TbWindow::Toolbar.BtnEnable, IDM_WINDOW_CASCADE,  dAction
  OCall [xsi].TbWindow::Toolbar.BtnEnable, IDM_WINDOW_TILE_HOR, dAction
  OCall [xsi].TbWindow::Toolbar.BtnEnable, IDM_WINDOW_TILE_VER, dAction
  OCall [xsi].TbWindow::Toolbar.BtnEnable, IDM_WINDOW_ARRANGE,  dAction
  OCall [xsi].TbWindow::Toolbar.BtnEnable, IDM_WINDOW_CLOSE,    dAction
  OCall [xsi].TbWindow::Toolbar.BtnEnable, IDM_WINDOW_CLOSE_ALL, dAction
  OCall [xsi].TbWindow::Toolbar.BtnEnable, IDM_ZOOM_IN,       dAction
  OCall [xsi].TbWindow::Toolbar.BtnEnable, IDM_ZOOM_OUT,      dAction

  mov xdi, $invoke(GetMenu, [xsi].hWnd)     ;Get the current menu
  .if dAction == FALSE
    mov ebx, MF_BYCOMMAND or MF_GRAYED
  .else
    mov ebx, MF_BYCOMMAND or MF_ENABLED
  .endif
  invoke EnableMenuItem, xdi, IDM_EDIT_CUT, ebx
  invoke EnableMenuItem, xdi, IDM_EDIT_COPY, ebx
  invoke EnableMenuItem, xdi, IDM_EDIT_PASTE, ebx
  invoke EnableMenuItem, xdi, IDM_EDIT_DELETE, ebx
  invoke EnableMenuItem, xdi, IDM_EDIT_SELECT_ALL, ebx

  mov xdi, [xsi].hMenuChildContext
  invoke EnableMenuItem, xdi, IDM_EDIT_CUT, ebx
  invoke EnableMenuItem, xdi, IDM_EDIT_COPY, ebx
  invoke EnableMenuItem, xdi, IDM_EDIT_PASTE, ebx
  invoke EnableMenuItem, xdi, IDM_EDIT_DELETE, ebx
  invoke EnableMenuItem, xdi, IDM_EDIT_SELECT_ALL, ebx
  invoke EnableMenuItem, xdi, IDM_OPEN_EDITOR, ebx
  invoke EnableMenuItem, xdi, IDM_CHECK_AGAIN, ebx
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OAT_App.Init
; Purpose:    Initialize the application object.
; Arguments:  None.
; Return:     Nothing.

ReadDW macro RegName:req, VarName:req, Default:req
  %OCall pRegKey::RegKey.ValueGetDW, offset sz&RegName
  .if [xsi].dErrorCode != OBJ_OK
    OCall xsi.ErrorClear
    %mov eax, Default
  .endif
  %mov [xsi].Setup.&VarName, eax
endm

ReadStr macro ID:req, Default:req
  %OCall pRegKey::RegKey.ValueGetStr, offset szMain&ID, addr cBuffer, lengthof cBuffer
  .if [xsi].dErrorCode != OBJ_OK
    OCall xsi.ErrorClear
    %invoke StrNew, $OfsCStr("&Default")
  .else
    invoke StrNew, addr cBuffer
  .endif
  %mov [xsi].Setup.p&ID, xax
endm

ReadToolData macro ID:req
  %OCall pRegKey::RegKey.ValueGetStr, offset szTool&ID&Name, addr cBuffer, lengthof cBuffer
  .if [xsi].dErrorCode != OBJ_OK
    OCall xsi.ErrorClear
    invoke StrNew, offset szNULL
  .else
    invoke StrNew, addr(cBuffer)
  .endif
  %mov [xsi].Setup.Tool&ID.pName, xax
  %OCall pRegKey::RegKey.ValueGetStr, offset szTool&ID&Cmd, addr cBuffer, lengthof cBuffer
  .if [xsi].dErrorCode != OBJ_OK
    OCall xsi.ErrorClear
    invoke StrNew, offset szNULL
  .else
    invoke StrNew, addr(cBuffer)
  .endif
  %mov [xsi].Setup.Tool&ID.pCommand, xax
endm

Method OAT_App.Init, uses xbx xdi xsi
  local pSBHelp:POINTER, WP:WINDOWPLACEMENT, pRegKey:POINTER, cBuffer[2*MAX_PATH]:CHR

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
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_APP")             ;00
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_CHILD")           ;01
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_APPL_SETUP")      ;02
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_APPL_EXIT")       ;03
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_EDIT_CUT")        ;04
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_EDIT_COPY")       ;05
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_EDIT_PASTE")      ;06
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_EDIT_DELETE")     ;07
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_CHECK")           ;08
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_CHECK_ALL")       ;09
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WIND_CASCADE")    ;10
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WIND_TILE_HOR")   ;11
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WIND_TILE_VER")   ;12
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WIND_ARRANGE")    ;13
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WIND_NEXT")       ;14
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WIND_PREV")       ;15
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WIND_CLOSE")      ;16
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WIND_CLOSE_ALL")   ;17
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_HELP_HELP")       ;18
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_HELP_ABOUT")      ;19
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_EDITOR")          ;20
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_ZOOM_IN")         ;21
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_ZOOM_OUT")        ;22

  mov [xsi].hAccelerators, $invoke(LoadAccelerators, hInstance, $OfsCStr("MDIACCEL"))

  ;Obtain handles for possible menus and submenus
  mov [xsi].hMenuInit, $invoke(LoadMenu, hInstance, $OfsCStr("MDIMENUINIT"))

  mov [xsi].hMenuChild, $invoke(LoadMenu, hInstance, $OfsCStr("MDIMENUCHILD"))
  mov [xsi].hMenuChildWnd, $invoke(GetSubMenu, [xsi].hMenuChild, 4)
  mov [xsi].hMenuChildContext, $invoke(LoadMenu, hInstance, $OfsCStr("CHILDCONTEXTMENU"))
  mov [xsi].hMenuDropContext, $invoke(LoadMenu, hInstance, $OfsCStr("DROPCONTEXTMENU"))

  ;Create the MDI Frame window
  mov WP.length_, sizeof WINDOWPLACEMENT
  xor eax, eax
  mov WP.flags, eax
  dec eax
  mov WP.ptMinPosition.x, eax
  mov WP.ptMinPosition.y, eax
  mov WP.ptMaxPosition.x, eax
  mov WP.ptMaxPosition.y, eax

  mov pRegKey, $New(RegKey)
  OCall xax::RegKey.Init, xsi, offset szRegKey, HKEY_CURRENT_USER
  OCall pRegKey::RegKey.Open
  OCall xsi.ErrorClear                                  ;If any...

  OCall pRegKey::RegKey.ValueGetDW, offset szWinState
  .if [xsi].dErrorCode != OBJ_OK
    OCall xsi.ErrorClear
    mov eax, SW_SHOWNORMAL
  .endif
  mov WP.showCmd, eax

  OCall pRegKey::RegKey.ValueGetDW, offset szWinLeft
  .if [xsi].dErrorCode != OBJ_OK
    OCall xsi.ErrorClear
    invoke CenterForm, DEFAULT_WIDTH, $32($invoke(GetSystemMetrics, SM_CXSCREEN))
  .endif
  mov WP.rcNormalPosition.left, eax

  OCall pRegKey::RegKey.ValueGetDW, offset szWinTop
  .if [xsi].dErrorCode != OBJ_OK
    OCall xsi.ErrorClear
    invoke CenterForm, DEFAULT_HEIGHT, $32($invoke(GetSystemMetrics, SM_CYSCREEN))
  .endif
  mov WP.rcNormalPosition.top, eax

  OCall pRegKey::RegKey.ValueGetDW, offset szWinRight
  .if [xsi].dErrorCode != OBJ_OK
    OCall xsi.ErrorClear
    mov eax, WP.rcNormalPosition.left
    add eax, DEFAULT_WIDTH
  .endif
  mov WP.rcNormalPosition.right, eax

  OCall pRegKey::RegKey.ValueGetDW, offset szWinBottom
  .if [xsi].dErrorCode != OBJ_OK
    OCall xsi.ErrorClear
    mov eax, WP.rcNormalPosition.top
    add eax, DEFAULT_HEIGHT
  .endif
  mov WP.rcNormalPosition.bottom, eax

  OCall pRegKey::RegKey.ValueGetStrW, offset szWinWorkDirectoryW, NULL, 0
  .if [xsi].dErrorCode == OBJ_OK
    mov edi, eax
    mov [xsi].pWorkDirectoryW, $invoke(StrAllocW, eax)
    OCall pRegKey::RegKey.ValueGetStrW, offset szWinWorkDirectoryW, [xsi].pWorkDirectoryW, edi
  .else
    OCall xsi.ErrorClear
    m2z CHRW ptr [cBuffer]
    invoke GetEnvironmentVariableW, $OfsCStrW("ProgramFiles"), addr cBuffer, \
                                    sizeof(cBuffer)/sizeof(CHRW)
    mov [xsi].pWorkDirectoryW, $invoke(StrNewW, addr cBuffer)
  .endif

  OCall pRegKey::RegKey.ValueGetDW, offset szMainLanguage
  .if [xsi].dErrorCode != OBJ_OK
    OCall xsi.ErrorClear
    mov eax, IDLANG_ENGLISH
  .endif
  mov [xsi].dLanguage, eax

  ;Setup information
  ReadDW MainCloseIfNoFinding, dCloseIfNoFinding, TRUE
  ReadDW MainUseAnnotations, dUseAnnotations, TRUE
  ReadDW MainTestBitness, dTestBitness, OATF_TEST_MX
  ReadDW MainZoomfactor, dZoomfactor, ZOOM_BASE
  ReadDW MainLineTerminator, dLineTerminator, 0
  ReadDW MainFontSize, dFontSize, 10
  OCall pRegKey::RegKey.ValueGetStr, offset szMainFontFaceName, addr [xsi].Setup.cFontFaceName, \
                                     LF_FULLFACESIZE
  .if [xsi].dErrorCode != OBJ_OK
    OCall xsi.ErrorClear
    invoke StrCCopy, addr [xsi].Setup.cFontFaceName, $OfsCStr("Courier New"), LF_FULLFACESIZE
  .endif
  ReadStr <ExternalEditor>, <!%SystemRoot!%\System32\notepad.exe>
  ReadToolData 0
  ReadToolData 1
  ReadToolData 2
  ReadToolData 3
  ReadToolData 4
  ReadToolData 5
  ReadToolData 6
  ReadToolData 7
  ReadToolData 8
  ReadToolData 9

  ReadDW ColorNotification, Color.Notification, OAT_COLOR_NOTIFICATION
  ReadDW ColorInformation, Color.Information, OAT_COLOR_INFORMATION
  ReadDW ColorFailure, Color.Failure, OAT_COLOR_FAILURE
  ReadDW ColorBkground, Color.Bkground, OAT_COLOR_BKGROUND
  ReadDW ColorRegError, Color.RegError, OAT_COLOR_REG_ERROR
  ReadDW ColorRegWarning, Color.RegWarning, OAT_COLOR_REG_WARNING
  ReadDW ColorArgWarning, Color.ArgWarning, OAT_COLOR_ARG_WARNING
  ReadDW ColorLocWarning, Color.LocWarning, OAT_COLOR_LOC_WARNING

  OCall pRegKey::RegKey.Close
  Destroy pRegKey

  invoke CreateWindowEx, WS_EX_LEFT or WS_EX_APPWINDOW, \
                         offset szOAT_App, offset szAppTitle, WS_OVERLAPPEDWINDOW, \
                         0, 0, DEFAULT_WIDTH, DEFAULT_HEIGHT, \
                         NULL, [xsi].hMenuInit, hInstance, xsi

  ;Create and Initialize Client window
  mov [xsi].pClientWnd, $New(OAT_Client)
  OCall xax::OAT_Client.Init, xsi
  mov xax, [xsi].pClientWnd
  mov xdi, [xax].$Obj(OAT_Client).hWnd

  ;Create and initialize XMenu
  m2m pSBHelp, $MethodAddr(OAT_App.StatusbarHelp), xax
  OCall [xsi].Menu::XMenu.Init, xsi, [xsi].hWnd, xdi, [xsi].hMenuChildWnd, \
                                xbx, pSBHelp, [xsi].dLanguage

  OCall xsi.ChangeMnuLanguage, [xsi].dLanguage
  OCall xsi.ChangeBtnLanguage, [xsi].dLanguage

  invoke SetWindowPlacement, [xsi].hWnd, addr WP
  invoke UpdateWindow, [xsi].hWnd

  OCall xsi.SetToolMenu
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OAT_App.ExecuteCommand
; Purpose:    Execute a Shell Command.
; Arguments:  Arg1: -> Command string.
;             Arg2: -> Output child.
; Return:     eax = Command termination code.

Method OAT_App.ExecuteCommand, uses xbx xsi, pCommand:PSTRING, pChild:$ObjPtr(OAT_Child)
  local SecAtt:SECURITY_ATTRIBUTES
  local StartupInfo:STARTUPINFO
  local ProcessInfo:PROCESS_INFORMATION
  local hRead:HANDLE, hWrite:HANDLE
  local dBytesRead:DWORD, dExitCode:DWORD, bBuffer[1024]:BYTE

  SetObject xsi
  xor eax, eax
  mov dExitCode, eax
  invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
  mov SecAtt.nLength, sizeof SecAtt
  mov SecAtt.lpSecurityDescriptor, NULL
  mov SecAtt.bInheritHandle, TRUE
  invoke CreatePipe, addr hRead, addr hWrite, addr SecAtt, NULL
  .if eax == NULL
    invoke MessageBox, [xsi].hWnd, $OfsCStr("CreatePipe Error") , offset szAppTitle, \
                       MB_ICONERROR + MB_OK
  .else
    mov StartupInfo.cb, sizeof STARTUPINFO
    invoke GetStartupInfo, addr StartupInfo
    mov xax, hWrite
    mov StartupInfo.hStdOutput, xax
    mov StartupInfo.hStdError, xax
    mov StartupInfo.dwFlags, STARTF_USESHOWWINDOW + STARTF_USESTDHANDLES
    mov StartupInfo.wShowWindow, SW_HIDE
    invoke CreateProcess, NULL, pCommand, NULL, NULL, TRUE, NULL, NULL, NULL, \
                          addr StartupInfo, addr ProcessInfo
    .if eax == NULL
      invoke MessageBox, [xsi].hWnd, $OfsCStr("CreateProcess Error"), offset szAppTitle, \
                         MB_ICONERROR + MB_OK
    .else
      invoke CloseHandle, hWrite
      lea xbx, bBuffer
      .while TRUE
        invoke ReadFile, hRead, xbx, sizeof bBuffer - 1, addr dBytesRead, NULL
        mov ecx, dBytesRead
        add xcx, xbx
        m2z BYTE ptr [xcx]
        .if eax == NULL
          .break
        .else
          OCall pChild::OAT_Child.WriteA, xbx, [xsi].Setup.Color.Notification, 0
        .endif
      .endw
      invoke GetExitCodeProcess, ProcessInfo.hProcess, addr dExitCode
    .endif
    invoke CloseHandle, hRead
    invoke CloseHandle, ProcessInfo.hProcess
  .endif
  invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
  mov eax, dExitCode
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OAT_App.ExecuteChecks
; Purpose:    Execute the give commands.
; Arguments:  Arg1: -> File name.
;             Arg2: Flags = Checks to perform.
; Return:     Nothing.

Method OAT_App.ExecuteChecks, uses xbx xsi, pFileName:PSTRING, dFlags:DWORD
  SetObject xsi

  ;Create child window
  mov xbx, $New(OAT_Child)
  OCall xbx::OAT_Child.Init, [xsi].pClientWnd, pFileName, dFlags
  .if eax != FALSE
    OCall xbx::OAT_Child.Run                            ;Returns # of findings

    ;Close child window if no finding and flag is set acordingly
    .if eax == 0 && [xsi].Setup.dCloseIfNoFinding != FALSE
      invoke SendMessage, [xbx].$Obj(OAT_Child).hWnd, WM_CLOSE, 0, 0
    .endif
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

    mov edx, $ObjTmpl(OAT_App).dLanguage
    add edx, IDS_DLG_EXIT_YES
    invoke LoadString, hInstance, edx, xbx, lengthof cText
    invoke GetDlgItem, wParam, IDYES
    invoke SetWindowText, xax, xbx

    mov edx, $ObjTmpl(OAT_App).dLanguage
    add edx, IDS_DLG_EXIT_NO
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
; Method:    OAT_App.OnClose
; Purpose:   Event procedure for WM_CLOSE (and WM_QUERYENDSESSION) message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    eax = Zero if handled.

Method OAT_App.OnClose, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local dMsg:DWORD
  local cCaption[512]:CHR, cText[1024]:CHR

  SetObject xsi
  mov dMsg, eax                                         ;Save windows message passed in eax
  invoke GetKeyState, VK_CONTROL
  mov xbx, [xsi].pClientWnd
  and ax, BIT15
  .if ZERO? || dMsg != WM_CLOSE                         ;If CTRL pressed => close without asking
    .if [xbx].$Obj(OAT_Client).dChildCount != 0         ;Ask only if a child window is open
      mov edx, [xsi].dLanguage
      add edx, IDS_DLG_EXIT_CAPTION
      invoke LoadString, hInstance, edx, addr cCaption, lengthof cCaption
      mov edx, [xsi].dLanguage
      add edx, IDS_DLG_EXIT_QUESTION
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
  invoke DefFrameProc, [xsi].hWnd, [xbx].$Obj(OAT_Client).hWnd, dMsg, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OAT_App.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

CloseAllChildren macro
  invoke EnumChildWindows, [xbx].$Obj(OAT_Client).hWnd, offset CloseEnumProc, 0
endm

SetChildFlags macro Reg32, MoreFlags
  mov Reg32, [xsi].Setup.dTestBitness
  mov eax, [xsi].Setup.dLineTerminator
  .if eax == 0
    or Reg32, OATF_TEST_CRLF
  .elseif eax == 1
    or Reg32, OATF_TEST_LF
  .elseif eax == 2
    or Reg32, OATF_TEST_CR
  .endif
  .if [xsi].Setup.dUseAnnotations != FALSE
    or Reg32, OATF_TEST_ANNOT
  .endif
  ifnb <MoreFlags>
    or Reg32, MoreFlags
  endif
endm

ExecuteTool macro ID:req
  .if [xsi].Setup.Tool&ID.pCommand != NULL
    lea xdi, cBuffer
    %invoke ExpandEnvironmentStrings, [xsi].Setup.Tool&ID.pCommand, xdi, lengthof(cBuffer)
    invoke StrRTrim, xdi, xdi
    invoke StrEnd, xdi
    .if CHR ptr [xax - sizeof CHR] == "$"                 ;Check last character
      mov CHR ptr [xax - sizeof CHR], 0                   ;Set ZTC
      invoke SendMessage, [xbx].$Obj(OAT_Client).hWnd, WM_MDIGETACTIVE, 0, 0
      .if xax != 0
        invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
        lea xbx, cParam
        mov DCHR ptr [xbx], '"'
        invoke StrCCat, xbx, [xax].$Obj(OAT_Child).pFileName, lengthof(cParam)
        invoke StrCCatChar, xbx, '"', lengthof(cParam)
      .else
        xor ebx, ebx
      .endif
    .else
      xor ebx, ebx
    .endif
    invoke ShellExecute, [xsi].hWnd, offset szOpen, xdi, xbx, NULL, SW_SHOWNORMAL
  .endif
endm

Method OAT_App.OnCommand, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local hChildWnd:HWND, AboutDlg:$Obj(OAT_About), SetupDlg:$Obj(OAT_Setup)
  local dMemSize:DWORD, hGlobalMem:HANDLE, pGlobalMem:POINTER
  local cBuffer[MAX_PATH]:CHR, cParam[MAX_PATH]:CHR, MenuBkColor:RGBQUAD

  SetObject xsi
  mov xax, wParam
  mov xbx, [xsi].pClientWnd

  .if (ax == IDM_WINDOW_CLOSE) || (ax == SC_CLOSE)        ;Close the active window
    mov hChildWnd, $invoke(SendMessage, [xbx].$Obj(OAT_Client).hWnd, WM_MDIGETACTIVE, 0, 0)
    invoke SendMessage, hChildWnd, WM_CLOSE, 0, 0
    xor eax, eax
  .elseif ax == SC_RESTORE                              ;Restore the active window
    mov hChildWnd, $invoke(SendMessage, [xbx].$Obj(OAT_Client).hWnd, WM_MDIGETACTIVE, 0, 0)
    invoke SendMessage, [xbx].$Obj(OAT_Client).hWnd, WM_MDIRESTORE, hChildWnd, 0
    xor eax, eax
  .elseif ax == SC_MINIMIZE                             ;Minimize the active window
    mov hChildWnd, $invoke(SendMessage, [xbx].$Obj(OAT_Client).hWnd, WM_MDIGETACTIVE, 0, 0)
    invoke ShowWindow, xax, SW_MINIMIZE
    xor eax, eax

  .elseif ax == IDM_APPL_SETUP
    New SetupDlg::OAT_Setup
    OCall SetupDlg::OAT_Setup.Init, xsi, [xsi].hWnd
    OCall SetupDlg::OAT_Setup.Show
    OCall SetupDlg::OAT_Setup.Done
    xor eax, eax

  .elseif ax == IDM_APPL_EXIT
    invoke SendMessage, [xsi].hWnd, WM_CLOSE, 0, 0
    xor eax, eax

  ;Messages for language selection
  .elseif (ax >= IDM_LANG_ENGLISH) && (ax <= IDM_LANG_CHINESE)
    ;Calculate IDLANG_XXX
    sub eax, IDM_LANG_ENGLISH
    mov ecx, LANGUAGE_STEP
    mul ecx
    OCall xsi.ChangeLanguage, eax
    xor eax, eax

  ; --------------------------------------------------------------------------------------
  ;Method check commands from main menu
  .elseif ax == IDM_MENU_CHECK_MTD_ALL
    CloseAllChildren
    SetChildFlags ebx, OATF_TEST_MTD or OATF_TEST_ARG or OATF_TEST_LOC or OATF_TEST_REG
    OCall CheckSelectedFiles, ebx
    xor eax, eax
  .elseif ax == IDM_MENU_CHECK_MTD_ARG
    CloseAllChildren
    SetChildFlags ebx, OATF_TEST_MTD or OATF_TEST_ARG
    OCall CheckSelectedFiles, ebx
    xor eax, eax
  .elseif ax == IDM_MENU_CHECK_MTD_LOC
    CloseAllChildren
    SetChildFlags ebx, OATF_TEST_MTD or OATF_TEST_LOC
    OCall CheckSelectedFiles, ebx
    xor eax, eax
  .elseif ax == IDM_MENU_CHECK_MTD_REG
    CloseAllChildren
    SetChildFlags ebx, OATF_TEST_MTD or OATF_TEST_REG
    OCall CheckSelectedFiles, ebx
    xor eax, eax

  ;Procedure check commands from main menu
  .elseif ax == IDM_MENU_CHECK_PRC_ALL
    CloseAllChildren
    SetChildFlags ebx, OATF_TEST_PRC or OATF_TEST_ARG or OATF_TEST_LOC or OATF_TEST_REG
    OCall CheckSelectedFiles, ebx
    xor eax, eax
  .elseif ax == IDM_MENU_CHECK_PRC_ARG
    CloseAllChildren
    SetChildFlags ebx, OATF_TEST_PRC or OATF_TEST_ARG
    OCall CheckSelectedFiles, ebx
    xor eax, eax
  .elseif ax == IDM_MENU_CHECK_PRC_LOC
    CloseAllChildren
    SetChildFlags ebx, OATF_TEST_PRC or OATF_TEST_LOC
    OCall CheckSelectedFiles, ebx
    xor eax, eax
  .elseif ax == IDM_MENU_CHECK_PRC_REG
    CloseAllChildren
    SetChildFlags ebx, OATF_TEST_PRC or OATF_TEST_REG
    OCall CheckSelectedFiles, ebx
    xor eax, eax

  ;Macro check commands from main menu
  .elseif ax == IDM_MENU_CHECK_MAC_ALL
    CloseAllChildren
    SetChildFlags ebx, OATF_TEST_MAC or OATF_TEST_ARG or OATF_TEST_LOC
    OCall CheckSelectedFiles, ebx
    xor eax, eax
  .elseif ax == IDM_MENU_CHECK_MAC_ARG
    CloseAllChildren
    SetChildFlags ebx, OATF_TEST_MAC or OATF_TEST_ARG
    OCall CheckSelectedFiles, ebx
    xor eax, eax
  .elseif ax == IDM_MENU_CHECK_MAC_LOC
    CloseAllChildren
    SetChildFlags ebx, OATF_TEST_MAC or OATF_TEST_LOC
    OCall CheckSelectedFiles, ebx
    xor eax, eax

  ; --------------------------------------------------------------------------------------
  ;Method check commands from drop context menu
  .elseif ax == IDM_DROP_CHECK_MTD_ALL
    CloseAllChildren
    SetChildFlags ebx, OATF_TEST_MTD or OATF_TEST_ARG or OATF_TEST_LOC or OATF_TEST_REG
    OCall CheckDroppedFiles, ebx
    xor eax, eax
  .elseif ax == IDM_DROP_CHECK_MTD_ARG
    CloseAllChildren
    SetChildFlags ebx, OATF_TEST_MTD or OATF_TEST_ARG
    OCall CheckDroppedFiles, ebx
    xor eax, eax
  .elseif ax == IDM_DROP_CHECK_MTD_LOC
    CloseAllChildren
    SetChildFlags ebx, OATF_TEST_MTD or OATF_TEST_LOC
    OCall CheckDroppedFiles, ebx
    xor eax, eax
  .elseif ax == IDM_DROP_CHECK_MTD_REG
    CloseAllChildren
    SetChildFlags ebx, OATF_TEST_MTD or OATF_TEST_REG
    OCall CheckDroppedFiles, ebx
    xor eax, eax

  ;Procedure check commands from drop context menu
  .elseif ax == IDM_DROP_CHECK_PRC_ALL
    CloseAllChildren
    SetChildFlags ebx, OATF_TEST_PRC or OATF_TEST_ARG or OATF_TEST_LOC or OATF_TEST_REG
    OCall CheckDroppedFiles, ebx
    xor eax, eax
  .elseif ax == IDM_DROP_CHECK_PRC_ARG
    CloseAllChildren
    SetChildFlags ebx, OATF_TEST_PRC or OATF_TEST_ARG
    OCall CheckDroppedFiles, ebx
    xor eax, eax
  .elseif ax == IDM_DROP_CHECK_PRC_LOC
    CloseAllChildren
    SetChildFlags ebx, OATF_TEST_PRC or OATF_TEST_LOC
    OCall CheckDroppedFiles, ebx
    xor eax, eax
  .elseif ax == IDM_DROP_CHECK_PRC_REG
    CloseAllChildren
    SetChildFlags ebx, OATF_TEST_PRC or OATF_TEST_REG
    OCall CheckDroppedFiles, ebx
    xor eax, eax

  ;Macro check commands from drop context menu
  .elseif ax == IDM_DROP_CHECK_MAC_ALL
    CloseAllChildren
    SetChildFlags ebx, OATF_TEST_MAC or OATF_TEST_ARG or OATF_TEST_LOC
    OCall CheckDroppedFiles, ebx
    xor eax, eax
  .elseif ax == IDM_DROP_CHECK_MAC_ARG
    CloseAllChildren
    SetChildFlags ebx, OATF_TEST_MAC or OATF_TEST_ARG
    OCall CheckDroppedFiles, ebx
    xor eax, eax
  .elseif ax == IDM_DROP_CHECK_MAC_LOC
    CloseAllChildren
    SetChildFlags ebx, OATF_TEST_MAC or OATF_TEST_LOC
    OCall CheckDroppedFiles, ebx
    xor eax, eax


  .elseif ax == IDM_OPEN_EDITOR
    .if [xsi].Setup.pExternalEditor != NULL
      invoke ExpandEnvironmentStrings, [xsi].Setup.pExternalEditor, addr cBuffer, lengthof(cBuffer)
      invoke SendMessage, [xbx].$Obj(OAT_Client).hWnd, WM_MDIGETACTIVE, 0, 0
      .if xax != 0
        mov xbx, $invoke(SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0)
        lea xdi, cParam
        mov DCHR ptr [xdi], '"'
        invoke StrCCat, xdi, [xbx].$Obj(OAT_Child).pFileName, lengthof(cParam)
        invoke StrCCatChar, xdi, '"', lengthof(cParam)
        invoke ShellExecute, [xsi].hWnd, offset szOpen, addr cBuffer, xdi, NULL, SW_SHOWNORMAL
      .endif
    .endif
    xor eax, eax

  .elseif ax == IDM_COPY_FILENAME
    invoke SendMessage, [xbx].$Obj(OAT_Client).hWnd, WM_MDIGETACTIVE, 0, 0
    .if xax != 0
      mov xbx, $invoke(SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0)
      invoke OpenClipboard, [xsi].hWnd
      invoke EmptyClipboard
      mov dMemSize, $32($invoke(StrSize, [xbx].$Obj(OAT_Child).pFileName))
      mov hGlobalMem, $invoke(GlobalAlloc, GMEM_MOVEABLE or GMEM_DISCARDABLE or GMEM_SHARE, eax)
      mov pGlobalMem, $invoke(GlobalLock, hGlobalMem)
      invoke MemClone, pGlobalMem, [xbx].$Obj(OAT_Child).pFileName, dMemSize
      invoke GlobalUnlock, hGlobalMem
      if TARGET_STR_TYPE eq STR_TYPE_ANSI
        invoke SetClipboardData, CF_TEXT, hGlobalMem
      else
        invoke SetClipboardData, CF_UNICODETEXT, hGlobalMem
      endif
      invoke CloseClipboard
    .endif

  .elseif ax == IDM_CHECK_AGAIN
    invoke SendMessage, [xbx].$Obj(OAT_Client).hWnd, WM_MDIGETACTIVE, 0, 0
    .if xax != 0
      invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
      mov xbx, xax
      ;Erase previous window content
      invoke SendMessage, [xbx].$Obj(OAT_Child).hEdit, EM_SETSEL, 0, -1
      invoke SendMessage, [xbx].$Obj(OAT_Child).hEdit, WM_CLEAR, 0, 0

      ;Change the color of the MenuBar to signal that the application is working
      m2m MenuBkColor, [xsi].Menu.MenuBarBkColor, ecx
      OCall [xsi].Menu::XMenu.SetMenuBarBkColor, OAT_COLOR_APP_LOCK
      invoke DrawMenuBar, [xsi].Menu.hWnd
      invoke SendMessage, [xsi].hWnd, WM_SETREDRAW, FALSE, 0
      OCall [xsi].Menu::XMenu.SetMenuBarBkColor, MenuBkColor
      invoke DrawMenuBar, [xsi].Menu.hWnd

      OCall [xbx].$Obj(OAT_Child).DskStream::DiskStream.Done
      OCall [xbx].$Obj(OAT_Child).LineLengths::DataCollection.Done
      OCall xbx::OAT_Child.AnalyseFile
      OCall xbx::OAT_Child.Run

      invoke SendMessage, [xsi].hWnd, WM_SETREDRAW, TRUE, 0
      invoke RedrawWindow, [xsi].hWnd, NULL, NULL, \
                           RDW_ERASE or RDW_FRAME or RDW_INVALIDATE or RDW_ALLCHILDREN
    .endif
    xor eax, eax

  ;Clipboard messages
  .elseif ax == IDM_EDIT_CUT
    invoke SendMessage, [xbx].$Obj(OAT_Client).hWnd, WM_MDIGETACTIVE, 0, 0
    .if xax != 0
      invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
      OCall xax::OAT_Child.ClpBrdCut
      xor eax, eax
    .endif
  .elseif ax == IDM_EDIT_COPY
    invoke SendMessage, [xbx].$Obj(OAT_Client).hWnd, WM_MDIGETACTIVE, 0, 0
    .if xax
      invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
      OCall xax::OAT_Child.ClpBrdCopy
      xor eax, eax
    .endif
  .elseif ax == IDM_EDIT_PASTE
    invoke SendMessage, [xbx].$Obj(OAT_Client).hWnd, WM_MDIGETACTIVE, 0, 0
    .if xax
      invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
      OCall xax::OAT_Child.ClpBrdPaste
      xor eax, eax
    .endif
  .elseif ax == IDM_EDIT_DELETE
    invoke SendMessage, [xbx].$Obj(OAT_Client).hWnd, WM_MDIGETACTIVE, 0, 0
    .if xax
      invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
      OCall xax::OAT_Child.ClpBrdClear
      xor eax, eax
    .endif
  .elseif ax == IDM_EDIT_SELECT_ALL
    invoke SendMessage, [xbx].$Obj(OAT_Client).hWnd, WM_MDIGETACTIVE, 0, 0
    .if xax
      mov xdi, $invoke(SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0)
      OCall xdi::OAT_Child.SelectAll
      invoke SetFocus, [xdi].$Obj(OAT_Child).hEdit
      xor eax, eax
    .endif
    xor eax, eax

  ;Messages for arranging child windows
  .elseif ax == IDM_WINDOW_TILE_HOR
    invoke SendMessage, [xbx].$Obj(OAT_Client).hWnd, WM_MDITILE, MDITILE_HORIZONTAL, 0
    xor eax, eax
  .elseif ax == IDM_WINDOW_TILE_VER
    invoke SendMessage, [xbx].$Obj(OAT_Client).hWnd, WM_MDITILE, MDITILE_VERTICAL, 0
    xor eax, eax
  .elseif ax == IDM_WINDOW_CASCADE
    invoke SendMessage, [xbx].$Obj(OAT_Client).hWnd, WM_MDICASCADE, 0, 0
    xor eax, eax
  .elseif ax == IDM_WINDOW_ARRANGE
    invoke SendMessage, [xbx].$Obj(OAT_Client).hWnd, WM_MDIICONARRANGE, 0, 0
    xor eax, eax
  .elseif ax == IDM_WINDOW_CLOSE_ALL                    ;Attempt to close all windows
    CloseAllChildren
    xor eax, eax
  .elseif ax == IDM_WINDOW_NEXT
    invoke SendMessage, [xbx].$Obj(OAT_Client).hWnd, WM_MDINEXT, 0, 0
    xor eax, eax
  .elseif ax == IDM_WINDOW_PREV
    invoke SendMessage, [xbx].$Obj(OAT_Client).hWnd, WM_MDINEXT, 0, -1
    xor eax, eax
  .elseif ax == SC_RESTORE                              ;Restore the active window
    invoke SendMessage, [xbx].$Obj(OAT_Client).hWnd, WM_MDIGETACTIVE, 0, 0
    invoke SendMessage, [xbx].$Obj(OAT_Client).hWnd, WM_MDIRESTORE, xax, 0
    xor eax, eax
  .elseif ax == SC_MINIMIZE                             ;Minimize the active window
    invoke SendMessage, [xbx].$Obj(OAT_Client).hWnd, WM_MDIGETACTIVE, 0, 0
    invoke ShowWindow, xax, SW_MINIMIZE
    xor eax, eax
  .elseif ax == IDM_ZOOM_IN
    invoke SendMessage, [xbx].$Obj(OAT_Client).hWnd, WM_MDIGETACTIVE, 0, 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      OCall xax::OAT_Child.ZoomIn
    .endif
    xor eax, eax
  .elseif ax == IDM_ZOOM_OUT
    invoke SendMessage, [xbx].$Obj(OAT_Client).hWnd, WM_MDIGETACTIVE, 0, 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      OCall xax::OAT_Child.ZoomOut
    .endif
    xor eax, eax
  .elseif ax == IDM_TOOL_0
    ExecuteTool 0
  .elseif ax == IDM_TOOL_1
    ExecuteTool 1
  .elseif ax == IDM_TOOL_2
    ExecuteTool 2
  .elseif ax == IDM_TOOL_3
    ExecuteTool 3
  .elseif ax == IDM_TOOL_4
    ExecuteTool 4
  .elseif ax == IDM_TOOL_5
    ExecuteTool 5
  .elseif ax == IDM_TOOL_6
    ExecuteTool 6
  .elseif ax == IDM_TOOL_7
    ExecuteTool 7
  .elseif ax == IDM_TOOL_8
    ExecuteTool 8
  .elseif ax == IDM_TOOL_9
    ExecuteTool 9

  ;Messages for help menu
  .elseif ax == IDM_HELP_SYSINFO
    invoke ShellExecute, [xsi].hWnd, offset szOpen, $OfsCStr("MSInfo32.exe"), \
                         NULL, NULL, SW_SHOWNORMAL
    xor eax, eax
  .elseif ax == IDM_HELP_HELP
    lea xbx, cBuffer
    invoke GetModuleFileName, 0, xbx, lengthof cBuffer
    invoke PathRemoveFileSpec, xbx
    invoke StrCCat, xbx, $OfsCStr("\OA_Tools.pdf"), lengthof cBuffer
    invoke PdfView, [xsi].hWnd, xbx, $OfsCStr("Introduction")
    .if eax <= 32
      invoke MessageBox, [xsi].hWnd, $OfsCStr("PDF viewer failed to show the document"), \
                         offset szError, MB_ICONERROR or MB_OK
    .endif
    xor eax, eax
  .elseif ax == IDM_HELP_ABOUT
    New AboutDlg::OAT_About
    OCall AboutDlg::OAT_About.Init, xsi, [xsi].hWnd
    OCall AboutDlg::OAT_About.Show
    OCall AboutDlg::OAT_About.Done
    xor eax, eax

  ;Pass to active child
  .else
    invoke SendMessage, [xbx].$Obj(OAT_Client).hWnd, WM_MDIGETACTIVE, 0, 0
    invoke SendMessage, xax, WM_COMMAND, wParam, lParam
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OAT_App.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method OAT_App.OnCreate, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi

  ;Initialize statusbar
  OCall [xsi].Status::Statusbar.Init, xsi, [xsi].hWnd, offset AppStatusbar

  ;Create rebar, toolbars
  OCall [xsi].RBar::Rebar.Init, xsi, [xsi].hWnd

  OCall [xsi].TbWindow::Toolbar.Init, xsi, [xsi].hWnd, offset ToolbarWindow, \
             addr [xsi].IconImageList, NULL, NULL
  mov ebx, $32($OCall([xsi].TbWindow::Toolbar.GetHeight))
  OCall [xsi].TbWindow::Toolbar.GetWidth
  OCall [xsi].RBar::Rebar.InsertBand, [xsi].TbWindow.hWnd, eax, ebx

  OCall [xsi].TbEdit::Toolbar.Init, xsi, [xsi].hWnd, offset ToolbarEdit, \
                                    addr [xsi].IconImageList, NULL, NULL
  mov ebx, $32($OCall([xsi].TbEdit::Toolbar.GetHeight))
  OCall [xsi].TbEdit::Toolbar.GetWidth
  OCall [xsi].RBar::Rebar.InsertBand, [xsi].TbEdit.hWnd, eax, ebx

  ;Disable toolbar buttons
  OCall xsi.EnableActions, FALSE

  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OAT_App.OnDestroy
; Purpose:    Event procedure for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method OAT_App.OnDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  local WP:WINDOWPLACEMENT, pRegKey:POINTER

  SetObject xsi
  ;Save settings for next session
  mov WP.length_, sizeof WINDOWPLACEMENT
  invoke GetWindowPlacement, [xsi].hWnd, addr WP
  mov pRegKey, $New(RegKey)
  OCall xax::RegKey.Init, xsi, offset szRegKey, HKEY_CURRENT_USER
  OCall pRegKey::RegKey.Create
  OCall pRegKey::RegKey.ValueSetDW,   offset szWinState,              WP.showCmd
  OCall pRegKey::RegKey.ValueSetDW,   offset szWinLeft,               WP.rcNormalPosition.left
  OCall pRegKey::RegKey.ValueSetDW,   offset szWinTop,                WP.rcNormalPosition.top
  OCall pRegKey::RegKey.ValueSetDW,   offset szWinRight,              WP.rcNormalPosition.right
  OCall pRegKey::RegKey.ValueSetDW,   offset szWinBottom,             WP.rcNormalPosition.bottom
  OCall pRegKey::RegKey.ValueSetStrW, offset szWinWorkDirectoryW,     [xsi].pWorkDirectoryW

  ;Setup
  OCall pRegKey::RegKey.ValueSetDW,   offset szMainLanguage,          [xsi].dLanguage
  OCall pRegKey::RegKey.ValueSetDW,   offset szMainCloseIfNoFinding,  [xsi].Setup.dCloseIfNoFinding
  OCall pRegKey::RegKey.ValueSetDW,   offset szMainUseAnnotations,    [xsi].Setup.dUseAnnotations
  OCall pRegKey::RegKey.ValueSetDW,   offset szMainTestBitness,       [xsi].Setup.dTestBitness
  OCall pRegKey::RegKey.ValueSetDW,   offset szMainZoomfactor,        [xsi].Setup.dZoomfactor
  OCall pRegKey::RegKey.ValueSetDW,   offset szMainLineTerminator,    [xsi].Setup.dLineTerminator
  OCall pRegKey::RegKey.ValueSetDW,   offset szMainFontSize,          [xsi].Setup.dFontSize
  OCall pRegKey::RegKey.ValueSetStr,  offset szMainFontFaceName,      addr [xsi].Setup.cFontFaceName
  OCall pRegKey::RegKey.ValueSetStr,  offset szMainExternalEditor,    [xsi].Setup.pExternalEditor

  OCall pRegKey::RegKey.ValueSetStr,  offset szTool0Name,             [xsi].Setup.Tool0.pName
  OCall pRegKey::RegKey.ValueSetStr,  offset szTool0Cmd,              [xsi].Setup.Tool0.pCommand
  OCall pRegKey::RegKey.ValueSetStr,  offset szTool1Name,             [xsi].Setup.Tool1.pName
  OCall pRegKey::RegKey.ValueSetStr,  offset szTool1Cmd,              [xsi].Setup.Tool1.pCommand
  OCall pRegKey::RegKey.ValueSetStr,  offset szTool2Name,             [xsi].Setup.Tool2.pName
  OCall pRegKey::RegKey.ValueSetStr,  offset szTool2Cmd,              [xsi].Setup.Tool2.pCommand
  OCall pRegKey::RegKey.ValueSetStr,  offset szTool3Name,             [xsi].Setup.Tool3.pName
  OCall pRegKey::RegKey.ValueSetStr,  offset szTool3Cmd,              [xsi].Setup.Tool3.pCommand
  OCall pRegKey::RegKey.ValueSetStr,  offset szTool4Name,             [xsi].Setup.Tool4.pName
  OCall pRegKey::RegKey.ValueSetStr,  offset szTool4Cmd,              [xsi].Setup.Tool4.pCommand
  OCall pRegKey::RegKey.ValueSetStr,  offset szTool5Name,             [xsi].Setup.Tool5.pName
  OCall pRegKey::RegKey.ValueSetStr,  offset szTool5Cmd,              [xsi].Setup.Tool5.pCommand
  OCall pRegKey::RegKey.ValueSetStr,  offset szTool6Name,             [xsi].Setup.Tool6.pName
  OCall pRegKey::RegKey.ValueSetStr,  offset szTool6Cmd,              [xsi].Setup.Tool6.pCommand
  OCall pRegKey::RegKey.ValueSetStr,  offset szTool7Name,             [xsi].Setup.Tool7.pName
  OCall pRegKey::RegKey.ValueSetStr,  offset szTool7Cmd,              [xsi].Setup.Tool7.pCommand
  OCall pRegKey::RegKey.ValueSetStr,  offset szTool8Name,             [xsi].Setup.Tool8.pName
  OCall pRegKey::RegKey.ValueSetStr,  offset szTool8Cmd,              [xsi].Setup.Tool8.pCommand
  OCall pRegKey::RegKey.ValueSetStr,  offset szTool9Name,             [xsi].Setup.Tool9.pName
  OCall pRegKey::RegKey.ValueSetStr,  offset szTool9Cmd,              [xsi].Setup.Tool9.pCommand

  OCall pRegKey::RegKey.ValueSetDW,  offset szColorNotification,      [xsi].Setup.Color.Notification
  OCall pRegKey::RegKey.ValueSetDW,  offset szColorInformation,       [xsi].Setup.Color.Information
  OCall pRegKey::RegKey.ValueSetDW,  offset szColorFailure,           [xsi].Setup.Color.Failure
  OCall pRegKey::RegKey.ValueSetDW,  offset szColorBkground,          [xsi].Setup.Color.Bkground
  OCall pRegKey::RegKey.ValueSetDW,  offset szColorRegError,          [xsi].Setup.Color.RegError
  OCall pRegKey::RegKey.ValueSetDW,  offset szColorRegWarning,        [xsi].Setup.Color.RegWarning
  OCall pRegKey::RegKey.ValueSetDW,  offset szColorArgWarning,        [xsi].Setup.Color.ArgWarning
  OCall pRegKey::RegKey.ValueSetDW,  offset szColorLocWarning,        [xsi].Setup.Color.LocWarning

  OCall pRegKey::RegKey.Close
  Destroy pRegKey

  invoke StrDispose, [xsi].Setup.pExternalEditor
  invoke StrDispose, [xsi].Setup.Tool0.pName
  invoke StrDispose, [xsi].Setup.Tool0.pCommand
  invoke StrDispose, [xsi].Setup.Tool1.pName
  invoke StrDispose, [xsi].Setup.Tool1.pCommand
  invoke StrDispose, [xsi].Setup.Tool2.pName
  invoke StrDispose, [xsi].Setup.Tool2.pCommand
  invoke StrDispose, [xsi].Setup.Tool3.pName
  invoke StrDispose, [xsi].Setup.Tool3.pCommand
  invoke StrDispose, [xsi].Setup.Tool4.pName
  invoke StrDispose, [xsi].Setup.Tool4.pCommand
  invoke StrDispose, [xsi].Setup.Tool5.pName
  invoke StrDispose, [xsi].Setup.Tool5.pCommand
  invoke StrDispose, [xsi].Setup.Tool6.pName
  invoke StrDispose, [xsi].Setup.Tool6.pCommand
  invoke StrDispose, [xsi].Setup.Tool7.pName
  invoke StrDispose, [xsi].Setup.Tool7.pCommand
  invoke StrDispose, [xsi].Setup.Tool8.pName
  invoke StrDispose, [xsi].Setup.Tool8.pCommand
  invoke StrDispose, [xsi].Setup.Tool9.pName
  invoke StrDispose, [xsi].Setup.Tool9.pCommand

  OCall [xsi].Menu::XMenu.Done

  .if [xsi].hMenuInit
    invoke DestroyMenu, [xsi].hMenuInit
  .endif
  .if [xsi].hMenuChild
    invoke DestroyMenu, [xsi].hMenuChild
  .endif
  .if [xsi].hMenuChildContext
    invoke DestroyMenu, [xsi].hMenuChildContext
  .endif
  .if [xsi].hMenuDropContext
    invoke DestroyMenu, [xsi].hMenuDropContext
  .endif

  .if [xsi].hAccelerators
    invoke DestroyAcceleratorTable, [xsi].hAccelerators
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OAT_App.OnKeyUp
; Purpose:    Event procedure for WM_KEYUP message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method OAT_App.OnKeyUp, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov xbx, [xsi].pClientWnd
  .if wParam == VK_F6
    invoke SendMessage, [xbx].$Obj(OAT_Client).hWnd, WM_MDINEXT, NULL, 0
  .endif
  invoke DefFrameProc, [xsi].hWnd, [xbx].$Obj(OAT_Client).hWnd, WM_KEYUP, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OAT_App.OnEraseBkgnd
; Purpose:    Event procedure for WM_ERASEBKGND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Non zero => we do the job.

Method OAT_App.OnEraseBkgnd,, wParam:WPARAM, lParam:LPARAM
  mov eax, -1
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OAT_App.OnNotify
; Purpose:    Event procedure for WM_NOTIFY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method OAT_App.OnNotify, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local cToolTipText[256]:CHR

  SetObject xsi
  mov xdi, lParam
  .if [xdi].NMHDR.code == TTN_NEEDTEXT
    assume xdi:ptr TOOLTIPTEXT
    mov edx, [xsi].dLanguage
    .if [xdi].hdr.idFrom == IDM_EDIT_CUT
      add edx, IDS_HINT_CUT
    .elseif [xdi].hdr.idFrom == IDM_EDIT_COPY
      add edx, IDS_HINT_COPY
    .elseif [xdi].hdr.idFrom == IDM_EDIT_PASTE
      add edx, IDS_HINT_PASTE
    .elseif [xdi].hdr.idFrom == IDM_EDIT_DELETE
      add edx, IDS_HINT_DELETE
    .elseif [xdi].hdr.idFrom == IDM_OPEN_EDITOR
      add edx, IDS_HINT_OPEN_EDITOR

    .elseif [xdi].hdr.idFrom == IDM_WINDOW_CASCADE
      add edx, IDS_HINT_CASCADE
    .elseif [xdi].hdr.idFrom == IDM_WINDOW_TILE_HOR
      add edx, IDS_HINT_TILE_HOR
    .elseif [xdi].hdr.idFrom == IDM_WINDOW_TILE_VER
      add edx, IDS_HINT_TILE_VER
    .elseif [xdi].hdr.idFrom == IDM_WINDOW_ARRANGE
      add edx, IDS_HINT_ARRANGE
    .elseif [xdi].hdr.idFrom == IDM_WINDOW_CLOSE
      add edx, IDS_HINT_CLOSE
    .elseif [xdi].hdr.idFrom == IDM_WINDOW_CLOSE_ALL
      add edx, IDS_HINT_CLOSE_ALL
    .elseif [xdi].hdr.idFrom == IDM_ZOOM_IN
      add edx, IDS_HINT_ZOOM_IN
    .elseif [xdi].hdr.idFrom == IDM_ZOOM_OUT
      add edx, IDS_HINT_ZOOM_OUT
    .endif

    lea xbx, cToolTipText
    invoke LoadString, hInstance, edx, xbx, sizeof cToolTipText
    mov [xdi].lpszText, xbx
    assume xdi:NOTHING
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OAT_App.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method OAT_App.OnSize, uses xsi, wParam:WPARAM, lParam:LPARAM
  local dHeight:DWORD, dTop:DWORD, CtRect:RECT, SbRect:RECT, RbRect:RECT

  .if wParam != SIZE_MINIMIZED
    SetObject xsi
    invoke GetClientRect, [xsi].hWnd, addr CtRect
    m2m dHeight, CtRect.bottom, eax

    ;Place rebar
    invoke GetWindowRect, [xsi].RBar.hWnd, addr RbRect
    mov eax, RbRect.bottom
    sub eax, RbRect.top
    mov dTop, eax
    invoke MoveWindow, [xsi].RBar.hWnd, 0, 0, CtRect.right, eax, FALSE

    ;Place statusbar
    invoke GetWindowRect, [xsi].Status.hWnd, addr SbRect
    mov eax, SbRect.bottom
    sub eax, SbRect.top
    sub dHeight, eax
    invoke MoveWindow, [xsi].Status.hWnd, 0, dHeight, CtRect.right, eax, FALSE
    mov ecx, dTop
    sub dHeight, ecx

    ;Place client window
    mov xcx, [xsi].pClientWnd
    .if xcx != NULL
      invoke MoveWindow, [xcx].$Obj(OAT_Client).hWnd, 0, dTop, CtRect.right, dHeight, FALSE
    .endif

    ;Redraw all child windows
    invoke RedrawWindow, [xsi].hWnd, NULL, NULL, \
                         RDW_ERASE or RDW_INVALIDATE or RDW_UPDATENOW or RDW_ALLCHILDREN
    xor eax, eax                                        ;Return zero
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OAT_App.SetToolMenu
; Purpose:    Updates the Tool Menu.
; Arguments:  None.
; Return:     Nothing.

InsertToolItem macro ID:req
  %FillString [xdi], <&&ID >
  %.if [xsi].Setup.Tool&ID.pName != NULL
    %invoke StrLength, [xsi].Setup.Tool&ID.pName
    .if eax != 0
      %invoke StrCat, xdi, [xsi].Setup.Tool&ID.pName
      mov MenuInfo.dwTypeData, xdi
      mov MenuInfo.wID, IDM_TOOL_0 + &ID
      %invoke InsertMenuItem, xbx, &ID, TRUE, addr MenuInfo
    .endif
  .endif
endm

Method OAT_App.SetToolMenu, uses xbx xdi xsi
  local MenuInfo:MENUITEMINFO, cBuffer[MAX_PATH]:CHR

  SetObject xsi
  lea xdi, cBuffer
  mov MenuInfo.cbSize, sizeof MenuInfo
  mov MenuInfo.fMask, MIIM_STRING or MIIM_ID
  invoke GetMenu, [xsi].hWnd                            ;Get the actual main menu
  mov edx, 2
  .if xax != [xsi].hMenuInit
    inc edx
  .endif

  invoke GetSubMenu, xax, edx
  mov xbx, xax
  repeat 10
    invoke DeleteMenu, xbx, 0, MF_BYPOSITION
  endm
  $$Count = 0
  repeat 10
    InsertToolItem %$$Count
    $$Count = $$Count + 1
  endm
  OCall [xsi].Menu::XMenu.Convert, xbx, FALSE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OAT_App.Startup
; Purpose:    Register the object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method OAT_App.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CLSSTYLE
  m2m WC.lpfnWndProc, $MethodAddr(OAT_App.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  m2z WC.hbrBackground
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szOAT_App, xax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OAT_App.StatusbarHelp
; Purpose:    Display a help string on panel 0 of the statusbar.
; Arguments:  Arg1: -> Help string.
; Return:     Nothing.

Method OAT_App.StatusbarHelp,, pHelpStr:PSTRING
  SetObject xcx
  OCall [xcx].Status::Statusbar.SetPartText, 0, pHelpStr, SBT_NOBORDERS
MethodEnd
