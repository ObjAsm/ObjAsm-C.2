; ==================================================================================================
; Title:      ProjectWnd.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of project window objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


IDB_PROJ_OPEN     equ   0
IDB_PROJ_SAVE     equ   1
IDB_PROJ_CLOSE    equ   2

IDM_PROJ_OPEN     equ   200
IDM_PROJ_SAVE     equ   201
IDM_PROJ_CLOSE    equ   202

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:  ProjectWnd
; Purpose: Implement a project window used as a control container on some apps.

Object ProjectWnd,, Window
  RedefineMethod    Done
  RedefineMethod    Init,           POINTER, HWND       ;-> Owner, Parent
  StaticMethod      Startup

  VirtualEvent      OnCreate,       WM_CREATE
  VirtualEvent      OnPaint,        WM_PAINT

  DefineVariable    dToolbarHeight, DWORD,    0

  Embed     TBar,           Toolbar
  Embed     TView,          TreeView
  Embed     IconImageList,  MaskedImageList
ObjectEnd


; ==================================================================================================

if IMPLEMENT

PROJTVSTYLE   equ   TVS_HASBUTTONS or TVS_HASLINES or TVS_LINESATROOT

PROJTBSTYLE   equ   WS_CHILD or WS_VISIBLE or WS_CLIPCHILDREN or TBSTYLE_TOOLTIPS or \
                    CCS_NORESIZE or CCS_NODIVIDER or CCS_ADJUSTABLE or TBSTYLE_FLAT

CStr szProjectWnd, "ProjectWnd"

.const
ProjTreeView DEF_TREEVIEW {100, PROJTVSTYLE, 0, NULL, {<0,0,0,0>}}

ProjToolbar DEF_TOOLBAR {101, PROJTBSTYLE, 0, NULL, {<0,0,0,0>}, 3}
  TBBUTTON {IDB_PROJ_OPEN,  IDM_PROJ_OPEN,  TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_PROJ_SAVE,  IDM_PROJ_SAVE,  TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_PROJ_CLOSE, IDM_PROJ_CLOSE, TBSTATE_ENABLED, TBSTYLE_BUTTON}


.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ProjectWnd.Done
; Purpose:    Finalize the ProjectWnd object, freeing allocated resources.
; Arguments:  None.
; Return:     Nothing.

Method ProjectWnd.Done, uses xsi
  SetObject xsi
  OCall [xsi].IconImageList::MaskedImageList.Done
  OCall [xsi].TBar::Toolbar.Done
  OCall [xsi].TView::TreeView.Done
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ProjectWnd.Init
; Purpose:    Initialize the ProjectWnd object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
; Return:     Nothing.

Method ProjectWnd.Init, uses xsi, pOwner:POINTER, hParent:HWND
  SetObject xsi
  ACall xsi.Init, pOwner, NULL                          ;hWnd is set in WndProc
  invoke CreateWindowEx, WS_EX_CLIENTEDGE, offset szProjectWnd, $OfsCStr("Project"), \
                         WS_CHILD, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                         hParent, 0, hInstance, xsi
  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ProjectWnd.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ProjectWnd.OnCreate, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local hRoot:HANDLE, hFolder1:HANDLE

  SetObject xsi
  lea xbx, [xsi].IconImageList
  OCall xbx::MaskedImageList.Init, xsi, 16, 16, 8
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_OPEN")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_SAVE")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_CLOSE")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FOLDER_CLOSE")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FOLDER_OPEN")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_ARROW_BLUE")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_ARROW_GREEN")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_ARROW_YELLOW")

  lea xdi, [xsi].TView
  OCall xdi::TreeView.Init, xsi, [xsi].hWnd, xbx, offset ProjTreeView
  OCall xdi::TreeView.NodeInsert, TVI_ROOT, TVI_FIRST, $OfsCStr("Root"), 3, 4
  mov hRoot, xax
  OCall xdi::TreeView.NodeInsert, hRoot, TVI_FIRST, $OfsCStr("Item1"), 5, 7
  OCall xdi::TreeView.NodeInsert, hRoot, xax, $OfsCStr("Item2"), 5, 7
  OCall xdi::TreeView.NodeInsert, hRoot, xax, $OfsCStr("Folder1"), 3, 4
  mov hFolder1, xax
  OCall xdi::TreeView.NodeInsert, hFolder1, TVI_FIRST, $OfsCStr("Item1"), 6, 7
  OCall xdi::TreeView.NodeInsert, hFolder1, xax, $OfsCStr("Item2"), 6, 7

  lea xdi, [xsi].TBar
  OCall xdi::Toolbar.Init, xsi, [xsi].hWnd, offset ProjToolbar, xbx, NULL, NULL
  mov [xsi].dToolbarHeight, $32($OCall(xdi::Toolbar.GetHeight))

  invoke DefWindowProc, [xsi].hWnd, WM_CREATE, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ProjectWnd.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ProjectWnd.OnPaint, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, CtRect:RECT

  SetObject xsi
  invoke BeginPaint, [xsi].hWnd, addr PS
  invoke GetClientRect, [xsi].hWnd, addr CtRect

  mov ebx, CtRect.right
  sub ebx, CtRect.left
  mov eax, CtRect.bottom
  sub eax, CtRect.top
  sub eax, [xsi].dToolbarHeight                         ;Let space for buttons
  dec eax
  dec eax
  invoke MoveWindow, [xsi].TView.hWnd, CtRect.left, CtRect.top, ebx, eax, TRUE

  mov eax, CtRect.bottom
  sub eax, [xsi].dToolbarHeight
  inc CtRect.left
  dec eax
  invoke MoveWindow, [xsi].TBar.hWnd, CtRect.left, eax, ebx, [xsi].dToolbarHeight, TRUE

  invoke EndPaint, [xsi].hWnd, addr PS
  invoke DefWindowProc,[xsi].hWnd, WM_PAINT, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ProjectWnd.Startup
; Purpose:    Register the object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method ProjectWnd.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CS_HREDRAW or CS_VREDRAW
  m2m WC.lpfnWndProc, $MethodAddr(ProjectWnd.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  mov WC.hbrBackground, COLOR_BTNFACE + 1
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szProjectWnd, xax
  m2z WC.hIcon
  m2z WC.hIconSm
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)

  invoke RegisterClassEx, addr WC
MethodEnd

endif
