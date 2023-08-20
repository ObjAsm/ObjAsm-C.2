; ==================================================================================================
; Title:      MemLeak.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    Memory Leakage test program.
; ==================================================================================================


CLSSTYLE    equ     CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW

TBSTYLE     equ     WS_CHILD or WS_VISIBLE or WS_CLIPCHILDREN or TBSTYLE_TOOLTIPS or \
                    CCS_NORESIZE or CCS_NODIVIDER or CCS_ADJUSTABLE or TBSTYLE_FLAT or TBSTYLE_LIST

SBSTYLE     equ     WS_CHILD or WS_VISIBLE or SBARS_TOOLTIPS or SBARS_SIZEGRIP

.const
ToolbarFile TbDef {IDC_TOOLBARFILE, TBSTYLE, TBSTYLE_EX_MIXEDBUTTONS, $OfsTStr("File operations"), 0, 0, 0, 0, 5}
  TBBUTTON {IDB_FILE_NEW,    IDM_FILE_NEW,    TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, $OfsTStr("New")}
  TBBUTTON {0,               -1,              TBSTATE_ENABLED, TBSTYLE_SEP}
  TBBUTTON {IDB_FILE_OPEN,   IDM_FILE_OPEN,   TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, $OfsTStr("Open")}
  TBBUTTON {IDB_FILE_SAVE,   IDM_FILE_SAVE,   TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, $OfsTStr("Save")}
  TBBUTTON {IDB_FILE_SAVEAS, IDM_FILE_SAVEAS, TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, $OfsTStr("Save as")}

ToolbarEdit TbDef {IDC_TOOLBAREDIT, TBSTYLE, TBSTYLE_EX_MIXEDBUTTONS, $OfsTStr("Edit operations"), 0, 0, 0, 0, 3}
  TBBUTTON {IDB_EDIT_CUT,    IDM_EDIT_CUT,    TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, $OfsTStr("Cut")}
  TBBUTTON {IDB_EDIT_COPY,   IDM_EDIT_COPY,   TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, $OfsTStr("Copy")}
  TBBUTTON {IDB_EDIT_PASTE,  IDM_EDIT_PASTE,  TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, $OfsTStr("Paste")}

AppStatusbar SbDef {IDC_STATUSBAR, SBSTYLE, 0, NULL, 0, 0, 0, 0, 4}
  SbPartDef {120,  50, 3, SBT_NOBORDERS, $OfsTStr("Help")}
  SbPartDef {120,  20, 1, SBT_NOBORDERS or SBT_OWNERDRAW, NULL}
  SbPartDef {120,  -2, 0, SBT_SUNKEN, NULL}         ;Spring
  SbPartDef {120, 100, 2, SBT_SUNKEN, NULL}

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CStr szMemLeak, "MemLeak"

Object MemLeak, MySdiAppID, SdiApp                  ;Single Document Interface App.
  RedefineMethod    Done
  RedefineMethod    Init
  StaticMethod      Startup

  VirtualEvent      OnClose,        WM_CLOSE, WM_QUERYENDSESSION
  VirtualEvent      OnCommand,      WM_COMMAND
  VirtualEvent      OnCreate,       WM_CREATE
  VirtualEvent      OnPaint,        WM_PAINT
  VirtualEvent      OnSize,         WM_SIZE

  DefineVariable    pIconImageList, Pointer,    NULL
  DefineVariable    pRebar,         Pointer,    NULL
  DefineVariable    pStatusbar,     Pointer,    NULL
  DefineVariable    pToolbar1,      Pointer,    NULL
  DefineVariable    pToolbar2,      Pointer,    NULL
  DefineVariable    pXMenu,         Pointer,  NULL
ObjectEnd


.code
; ==================================================================================================
;    MemLeak implementation
; ==================================================================================================

P2 proc Arg1:dword
  MemAlloc 100
  invoke CreateSolidBrush, $RGB(250, 125, 45)
;  invoke DeleteObject, eax
  invoke CreateFile, $OfsCStr("c:\objasm32.ini"), GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0
  invoke LoadCursor, hInstance, $OfsCStr("CURSOR_HAND")
;  invoke DestroyCursor, eax
  invoke DeleteObject, eax
  invoke CreateSolidBrush, 12345678
  invoke CreateBitmap, 10, 10, 1, 8, NULL
;  invoke DeleteObject, eax
  invoke CreateRectRgn, 0,1,0,10
  invoke StrNew, $OfsCStr("Hello")
  ret
P2 endp

P1 proc Arg1:dword
  invoke P2, 12345678h
  ret
P1 endp

P0 proc Arg1:dword
  invoke P1, 12345678h
  ret
P0 endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    MemLeak.Done
; Purpose:   Finalizes the SDI application object. Objects associated with window controls are
;            destroyed by Windows automatically when WM_DESTROY is send.
; Arguments: None.
; Return:    Nothing.

Method MemLeak.Done, uses esi
    SetObject esi
    Destroy [esi].pIconImageList
    Destroy [esi].pXMenu
    ACall esi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    MemLeak.Init
; Purpose:   Initalizes the SDI application object.
; Arguments: None.
; Return:    Nothing.

Method MemLeak.Init, uses ebx esi
    local dWwd:dword, dWht:dword
    local dWtx:dword, dWty:dword

    SetObject esi
    ACall esi.Init

    invoke LoadCommonControls, ICC_COOL_CLASSES or ICC_BAR_CLASSES    ;Rebar & Statusbar

    mov [esi].hAccelerators, $invoke(LoadAccelerators, hInstance, $OfsCStr("SDIACCEL"))

    mov ebx, $New(MaskedImageList.Init, esi, 16, 16, 1)
    mov [esi].pIconImageList, ebx
    OCall ebx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_NEW")
    OCall ebx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_OPEN")
    OCall ebx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_SAVE")
    OCall ebx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_SAVEAS")
    OCall ebx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_CUT")
    OCall ebx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_COPY")
    OCall ebx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_PASTE")

    mov dWwd, 500
    mov dWht, 350
    mov dWtx, $invoke(CenterForm, dWwd, $invoke(GetSystemMetrics, SM_CXSCREEN))
    mov dWty, $invoke(CenterForm, dWht, $invoke(GetSystemMetrics, SM_CYSCREEN))

    invoke CreateWindowEx, WS_EX_LEFT or WS_EX_APPWINDOW, \
           offset szMemLeak, offset szAppTitle, WS_OVERLAPPEDWINDOW, \
           dWtx, dWty, dWwd, dWht, NULL, NULL, hInstance, esi

    mov [esi].pXMenu, $New(XMenu.Init, esi, [esi].hWnd, 0, 0, ebx, 0, 0)

    invoke ShowWindow, [esi].hWnd, SW_SHOWNORMAL
    invoke UpdateWindow, [esi].hWnd
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    MemLeak.OnClose
; Purpose:   Event procedure for WM_CLOSE message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    Zero if handled.

Method MemLeak.OnClose, uses esi, wParam:dword, lParam:dword
    SetObject esi
    invoke MessageBox, [esi].hWnd, $OfsCStr("Are you sure ?"), \
                       $OfsCStr("Application exit"), MB_YESNO or MB_ICONQUESTION
    .if eax == IDNO
      xor eax, eax
    .else
      invoke DefWindowProc, [esi].hWnd, WM_CLOSE, wParam, lParam
    .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    MemLeak.OnCommand
; Purpose:   Event procedure for WM_COMMAND message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    Zero if handled.

Method MemLeak.OnCommand, uses esi, wParam:dword, lParam:dword
    local AboutDlg:DialogAbout

    SetObject esi
    mov eax, wParam
    .if ax == IDM_FILE_NEW
      OCall [esi].pStatusbar::Statusbar.SetPartText, 0, $OfsCStr("New File"), SBT_NOBORDERS
      OCall [esi].pIconImageList::MaskedImageList.IconCreate, 0, ILD_TRANSPARENT
      push eax
      OCall [esi].pStatusbar::Statusbar.SetPartIcon, 0, eax
      pop eax
      invoke DeleteObject, eax
      xor eax, eax
    .elseif ax == IDM_FILE_OPEN
      OCall [esi].pStatusbar::Statusbar.SetPartText, 0, $OfsCStr("Open File"), SBT_SUNKEN
      OCall [esi].pIconImageList::MaskedImageList.IconCreate, 1, ILD_TRANSPARENT
      push eax
      OCall [esi].pStatusbar::Statusbar.SetPartIcon, 0, eax
      pop eax
      invoke DeleteObject, eax
      xor eax, eax
    .elseif ax == IDM_EXIT
      invoke SendMessage, [esi].hWnd, WM_SYSCOMMAND, SC_CLOSE, NULL
      xor eax, eax
    .elseif ax == IDM_ABOUT
      invoke LoadIcon, hInstance, $OfsCStr("ICON_APP_32")
      New AboutDlg::DialogAbout.Init, esi, [esi].hWnd, eax, offset szAboutText
      OCall AboutDlg::DialogAbout.Show
      OCall AboutDlg::DialogAbout.Done
      xor eax, eax
    .else
      invoke DefWindowProc, [esi].hWnd, WM_COMMAND, wParam, lParam
    .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    MemLeak.OnCreate
; Purpose:   Event procedure for WM_CREATE message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    Zero.

Method MemLeak.OnCreate, uses ebx esi, wParam:dword, lParam:dword
    SetObject esi

    mov [esi].pStatusbar, $New(Statusbar.Init, esi, [esi].hWnd, offset AppStatusbar)
    mov [esi].pRebar, $New(Rebar.Init, esi, [esi].hWnd)

    mov [esi].pToolbar2, $New(Toolbar)
    OCall [esi].pToolbar2::Toolbar.Init, esi, [esi].hWnd, offset ToolbarEdit, \
               [esi].pIconImageList, NULL, NULL

    mov ebx, $OCall([esi].pToolbar2::Toolbar.GetHeight)
    OCall [esi].pToolbar2::Toolbar.GetWidth
    mov ecx, [esi].pToolbar2
    OCall [esi].pRebar::Rebar.InsertBand, [ecx].Toolbar.hWnd, eax, ebx

    mov [esi].pToolbar1, $New(Toolbar)
    OCall [esi].pToolbar1::Toolbar.Init, esi, [esi].hWnd, offset ToolbarFile, \
               [esi].pIconImageList, NULL, NULL
    mov ebx, $OCall([esi].pToolbar1::Toolbar.GetHeight)
    OCall [esi].pToolbar1::Toolbar.GetWidth
    mov ecx, [esi].pToolbar1
    OCall [esi].pRebar::Rebar.InsertBand, [ecx].Toolbar.hWnd, eax, ebx

    xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    MemLeak.OnPaint
; Purpose:   Event procedure for WM_PAINT message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    Zero if handled.

Method MemLeak.OnPaint, uses esi, wParam:dword, lParam:dword
    local PS:PAINTSTRUCT, hDC:Handle, Rct:RECT

    SetObject esi
    invoke BeginPaint, [esi].hWnd, addr PS
    mov hDC, eax

    mov ecx, [esi].pRebar
    invoke GetWindowRect, [ecx].Rebar.hWnd, addr Rct
    mov eax, Rct.bottom
    sub eax, Rct.top
    push eax
    mov ecx, [esi].pStatusbar
    invoke GetWindowRect, [ecx].Statusbar.hWnd, addr Rct
    mov eax, Rct.bottom
    sub eax, Rct.top
    push eax
    invoke GetClientRect, [esi].hWnd, addr Rct
    pop eax
    sub Rct.bottom, eax
    pop Rct.top
    invoke DrawEdge, hDC, addr Rct, EDGE_SUNKEN, BF_RECT

    invoke EndPaint, [esi].hWnd, addr PS
    mov eax, TRUE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    MemLeak.OnSize
; Purpose:   Event procedure for WM_SIZE message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    Zero if handled.

Method MemLeak.OnSize, uses ebx esi, wParam:dword, lParam:dword
    local Rct:RECT

    .if wParam != SIZE_MINIMIZED
      SetObject esi
      invoke DefWindowProc, [esi].hWnd, WM_SIZE, wParam, lParam
      invoke GetClientRect, [esi].hWnd, addr Rct
      mov ebx, [esi].pStatusbar
      invoke MoveWindow, [ebx].Statusbar.hWnd, 0, 0, 0, 0, TRUE
      invoke UpdateWindow, [ebx].Statusbar.hWnd

      mov ecx, [esi].pRebar
      invoke MoveWindow, [ecx].Rebar.hWnd, 0, 0, Rct.right, Rct.bottom, TRUE
    .endif

    xor eax, eax                ;Return zero
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    MemLeak.Startup
; Purpose:   Registers the object class with the OS.
; Arguments: None.
; Return:    Nothing.

Method MemLeak.Startup
    local WC:WNDCLASSEX

    mov WC.cbSize, sizeof WNDCLASSEX
    mov WC.style, CLSSTYLE
    m2m WC.lpfnWndProc, $MethodAddr(MemLeak.WndProc), edx
    mov WC.cbClsExtra, 0
    mov WC.cbWndExtra, 0
    m2m WC.hInstance, hInstance, edx
    invoke LoadBitmap, hInstance, $OfsCStr("BMP_BACKGROUND")
    mov WC.hbrBackground, $invoke(CreatePatternBrush, eax)
    mov WC.lpszMenuName, $OfsCStr("MENU_APP")
    mov WC.lpszClassName, offset szMemLeak
    mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP_32"))
    mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
    mov WC.hIconSm, 0

    invoke RegisterClassEx, addr WC
MethodEnd
