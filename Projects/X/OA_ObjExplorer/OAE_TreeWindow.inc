; ==================================================================================================
; Title:      OAE_TreeWindow.inc
; Author:     G. Friedrich
; Version:    Check OA_ObjExplorer.asm
; Purpose:    TreeWindow implementation for OA_ObjExplorer.
; ==================================================================================================


IDB_TREE_REFRESH  equ   0
IDB_TREE_SEARCH   equ   1
IDB_TREE_OBJ      equ   2
IDB_TREE_COM      equ   3
IDB_TREE_PRJ      equ   4
IDB_TREE_ERR      equ   5


Object TreeWindow, , Window
  RedefineMethod    Done
  RedefineMethod    Init,           POINTER, HANDLE, POINTER    ;-> Owner, Parent, -> Language
  StaticMethod      Startup
  RedefineMethod    OnSize,         WPARAM, LPARAM

  VirtualEvent      OnCommand,      WM_COMMAND
  VirtualEvent      OnCreate,       WM_CREATE
  VirtualEvent      OnNotify,       WM_NOTIFY

  DefineVariable    dToolbarHeight, DWORD,    0
  DefineVariable    pLanguage,      POINTER,  NULL      ;-> dLanguage

  Embed     IconList,  MaskedImageList
  Embed     TBar,      Toolbar
  Embed     Tree,      InfoTree
ObjectEnd


; =================================================================================================

if IMPLEMENT

ObjTreeDef DEF_XTV {100, WS_CLIPSIBLINGS, WS_EX_NOPARENTNOTIFY,; or WS_EX_ACCEPTFILES,
                    $OfsTStr("InfoTree"), {<0,0,200,300>}}

PROJTBSTYLE   equ   WS_CHILD or WS_VISIBLE or WS_CLIPCHILDREN or TBSTYLE_TOOLTIPS or \
                    CCS_NORESIZE or CCS_NODIVIDER or CCS_ADJUSTABLE or TBSTYLE_FLAT

CStr cTreeWindowClass, "TreeWindow"

.const

ProjToolbar DEF_TOOLBAR {101, PROJTBSTYLE, 0, NULL, {<0,0,0,0>}, 7}
  TBBUTTON {IDB_TREE_REFRESH, IDM_FILE_REFRESH,   TBSTATE_ENABLED,
                                                  TBSTYLE_BUTTON}
  TBBUTTON {IDB_TREE_SEARCH,  IDM_FILE_SEARCH,    TBSTATE_ENABLED,
                                                  TBSTYLE_BUTTON}
  TBBUTTON {0,                -1,                 TBSTATE_ENABLED,
                                                  TBSTYLE_SEP}
  TBBUTTON {IDB_TREE_OBJ,     IDM_TREE_SHOW_OBJ,  TBSTATE_ENABLED or TBSTATE_CHECKED,
                                                  TBSTYLE_BUTTON or TBSTYLE_CHECK}
  TBBUTTON {IDB_TREE_COM,     IDM_TREE_SHOW_INT,  TBSTATE_ENABLED or TBSTATE_CHECKED,
                                                  TBSTYLE_BUTTON or TBSTYLE_CHECK}
  TBBUTTON {0,                -1,                 TBSTATE_ENABLED,
                                                  TBSTYLE_SEP}
  TBBUTTON {IDB_TREE_ERR,     IDM_TREE_SHOW_ERR,  TBSTATE_ENABLED,
                                                  TBSTYLE_BUTTON or TBSTYLE_CHECK}

.code
; -------------------------------------------------------------------------------------------------
; Method:    TreeWindow.Done
; Purpose:   Finalizes the TreeWindow object, freeing allocated resources.
; Arguments: None.
; Return:    Nothing.

Method TreeWindow.Done, uses xsi
  SetObject xsi
  OCall [xsi].IconList::MaskedImageList.Done
  OCall [xsi].TBar::Toolbar.Done
  OCall [xsi].Tree::InfoTree.Done
  ACall xsi.Done
MethodEnd

; -------------------------------------------------------------------------------------------------
; Method:    TreeWindow.Init
; Purpose:   Initalizes the TreeWindow object.
; Arguments: Arg1: -> Owner object.
;            Arg2: HANDLE to a parent window.
;            Arg3: -> Language.
; Return:    Nothing.

Method TreeWindow.Init, uses xsi, pOwner:POINTER, hParent:HANDLE, pLanguage:POINTER
  ;DbgText "TreeWindow.Init"
  SetObject xsi
  ACall xsi.Init, pOwner, NULL    ;hWnd is set in WndProc
  m2m [xsi].pLanguage, pLanguage, xax

  invoke CreateWindowEx, WS_EX_CLIENTEDGE, offset cTreeWindowClass, \
                         $OfsCStr("TreeWindow"), WS_CHILD, \
                         CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                         hParent, NULL, hInstance, xsi
  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    TreeWindow.OnCommand
; Purpose:   Event procedure for WM_COMMAND message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    eax = Zero if handled.

Method TreeWindow.OnCommand,, wParam:WPARAM, lParam:LPARAM
  SetObject xcx
  ;Forward messages to the owner window
  mov xax, [xcx].pOwner
  invoke SendMessage, [xax].$Obj(WinPrimer).hWnd, WM_COMMAND, wParam, lParam
MethodEnd

; -------------------------------------------------------------------------------------------------
; Method:    TreeWindow.OnCreate
; Purpose:   Event procedure for WM_CREATE message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    eax = Zero if handled.

Method TreeWindow.OnCreate, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  OCall [xsi].Tree::InfoTree.Init, xsi, [xsi].hWnd, offset ObjTreeDef
  lea xbx, [xsi].IconList
  OCall xbx::MaskedImageList.Init, xsi, 16, 16, 8
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_REFRESH")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_SEARCH")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_OBJ_STD")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_INT_STD")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_TREE_PRJ")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_TREE_ERR")

  lea xdi, [xsi].TBar
  OCall xdi::Toolbar.Init, xsi, [xsi].hWnd, offset ProjToolbar, xbx, NULL, NULL
  mov [xsi].dToolbarHeight, $32($OCall(xdi::Toolbar.GetHeight))
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    TreeWindow.OnNotify
; Purpose:   Event procedure for WM_NOTIFY message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    Nothing.

Method TreeWindow.OnNotify, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov xdi, lParam
  assume xdi: ptr TOOLTIPTEXT
  .if [xdi].hdr.code == TTN_NEEDTEXT
    mov xax, [xsi].pLanguage
    mov edx, DWORD ptr [xax]
    lea xbx, [xdi].szText
    .if [xdi].hdr.idFrom == IDM_FILE_REFRESH
      add edx, IDS_REFRESH
    .elseif [xdi].hdr.idFrom == IDM_FILE_SEARCH
      add edx, IDS_SEARCH
    .elseif [xdi].hdr.idFrom == IDM_TREE_SHOW_OBJ
      add edx, IDS_SHOW_OBJ
    .elseif [xdi].hdr.idFrom == IDM_TREE_SHOW_INT
      add edx, IDS_SHOW_INT
    .elseif [xdi].hdr.idFrom == IDM_TREE_SHOW_PRJ
      add edx, IDS_SHOW_PRJ
    .elseif [xdi].hdr.idFrom == IDM_TREE_SHOW_ERR
      add edx, IDS_SHOW_ERR
    .endif
    invoke LoadString, hInstance, edx, xbx, 80
    mov [xdi].lpszText, xbx
  .endif
  assume xdi:nothing
  xor eax, eax
MethodEnd

; -------------------------------------------------------------------------------------------------
; Method:    TreeWindow.OnSize
; Purpose:   Event procedure for WM_SIZE message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    eax = Zero if handled.

Method TreeWindow.OnSize, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local CtRect:RECT

  SetObject xsi
  invoke GetClientRect, [xsi].hWnd, addr CtRect

  mov edi, CtRect.right
  sub edi, CtRect.left
  mov eax, CtRect.bottom
  sub eax, CtRect.top
  sub eax, [xsi].dToolbarHeight             ;Let space for buttons
  invoke MoveWindow, [xsi].Tree.hWnd, CtRect.left, CtRect.top, edi, eax, FALSE
  OCall [xsi].Tree::InfoTree.Draw
  mov ebx, CtRect.bottom
  sub ebx, [xsi].dToolbarHeight
  invoke MoveWindow, [xsi].TBar.hWnd, CtRect.left, ebx, edi, [xsi].dToolbarHeight, FALSE
  xor eax, eax
MethodEnd

; -------------------------------------------------------------------------------------------------
; Method:    TreeWindow.Startup
; Purpose:   Registers the object with the OS.
; Arguments: None.
; Return:    Nothing.

Method TreeWindow.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  m2z WC.style
  m2m WC.lpfnWndProc, $MethodAddr(TreeWindow.WndProc), edx
  and WC.cbClsExtra, 0
  and WC.cbWndExtra, 0
  m2m WC.hInstance, hInstance, edx
  and WC.hbrBackground, 0
  and WC.lpszMenuName, NULL
  m2m WC.lpszClassName, offset cTreeWindowClass, xax
  and WC.hIcon, 0
  and WC.hIconSm, 0
  mov WC.hCursor, $invoke(LoadCursor, NULL, IDC_ARROW)

  invoke RegisterClassEx, addr WC
MethodEnd


endif