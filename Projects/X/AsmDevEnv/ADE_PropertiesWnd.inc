; ==================================================================================================
; Title:      ADE_PropertiesWnd.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of Properties window objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


IDB_PROP_OPEN   equ   0
IDB_PROP_SAVE   equ   1
IDB_PROP_CLOSE  equ   2

IDM_PROP_OPEN   equ   200
IDM_PROP_SAVE   equ   201
IDM_PROP_CLOSE  equ   202

; --------------------------------------------------------------------------------------------------
; Object:   ProjectManager
; Purpose:  Implement a project window used as a control container on some apps.

Object PropertiesWnd,, Window
  RedefineMethod    Done
  RedefineMethod    Init,             POINTER, HWND     ;-> Owner, Parent
  StaticMethod      Startup

  VirtualEvent      OnCreate,         WM_CREATE
  VirtualEvent      OnPaint,          WM_PAINT

  DefineVariable    dToolbarHeight,   DWORD,    0

  Embed     TBar,           Toolbar
  Embed     LView,          ListView
  Embed     IconImageList,  MaskedImageList
  Embed     CBox,           ComboBox
ObjectEnd


; ==================================================================================================

if IMPLEMENT

CStr szPropertiesWnd, "PropertiesWnd"

PROPCBSTYLE     equ   CBS_DROPDOWNLIST or CBS_HASSTRINGS or CBS_NOINTEGRALHEIGHT or \
                      WS_VSCROLL; or CBS_DISABLENOSCROLL

PROPLVSTYLE     equ   WS_CHILD or WS_VISIBLE or WS_CLIPCHILDREN or \
                      LVS_REPORT or LVS_SHOWSELALWAYS; or LVS_NOCOLUMNHEADER

PROPLVEXSTYLE   equ   LVS_EX_FULLROWSELECT or LVS_EX_GRIDLINES or LVS_EX_CHECKBOXES or \
                      LVS_EX_HEADERDRAGDROP or LVS_EX_TRACKSELECT or LVS_EX_ONECLICKACTIVATE

PROPCOLUMNFLAG  equ   LVCF_FMT or LVCF_SUBITEM or LVCF_WIDTH or LVCF_TEXT

PROPTBSTYLE     equ   WS_CHILD or WS_VISIBLE or WS_CLIPCHILDREN or TBSTYLE_TOOLTIPS or \
                      CCS_NORESIZE or CCS_NODIVIDER or CCS_ADJUSTABLE or TBSTYLE_FLAT
.data
;This data must be in the data segment, because it is altered by the
;LVM_INSERTCOLUMN SendMessage proc when the text is converted to widechar!

PropListView DEF_LISTVIEW {101, PROPLVSTYLE, PROPLVEXSTYLE, NULL, {<0,0,0,0>}, 2}
  LV_COLUMN {PROPCOLUMNFLAG, LVCFMT_LEFT, 100, $OfsCStr("Property"), 0, 0}
  LV_COLUMN {PROPCOLUMNFLAG, LVCFMT_LEFT,  46, $OfsCStr("Value")   , 0, 1}

.const
PropToolbar DEF_TOOLBAR {102, PROPTBSTYLE, 0, NULL, {<0,0,0,0>}, 3}
  TBBUTTON {IDB_PROP_OPEN,  IDM_PROP_OPEN,  TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_PROP_SAVE,  IDM_PROP_SAVE,  TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_PROP_CLOSE, IDM_PROP_CLOSE, TBSTATE_ENABLED, TBSTYLE_BUTTON}

PropComboBox DEF_COMBOBOX {100, PROPCBSTYLE, 0, NULL, {<0,0,0,0>}}


.code
; --------------------------------------------------------------------------------------------------
; Method:     PropertiesWnd.Done
; Purpose:    Finalize the PropertiesWnd object, freeing allocated resources.
; Arguments:  None.
; Return:     Nothing.

Method PropertiesWnd.Done, uses xsi
  SetObject xsi
  OCall [xsi].IconImageList::MaskedImageList.Done
  OCall [xsi].CBox::ComboBox.Done
  OCall [xsi].LView::ListView.Done
  OCall [xsi].TBar::Toolbar.Done
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     PropertiesWnd.Init
; Purpose:    Initialize the PropertiesWnd object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
; Return:     Nothing.

Method PropertiesWnd.Init, uses xsi, pOwner:POINTER, hParent:HWND
  SetObject xsi
  ACall xsi.Init, pOwner, NULL                          ;hWnd is set in WndProc
  invoke CreateWindowEx, WS_EX_CLIENTEDGE, offset szPropertiesWnd, $OfsCStr("Properties"), \
                         WS_CHILD, 0, 0, 0, 0, hParent, 0, hInstance, xsi
  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     PropertiesWnd.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method PropertiesWnd.OnCreate, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local LVI:LV_ITEM

  SetObject xsi
  lea xbx, [xsi].IconImageList
  OCall xbx::MaskedImageList.Init, xsi, 16, 16, 3
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_OPEN")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_SAVE")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_CLOSE")

  lea xdi, [xsi].LView
  OCall xdi::ListView.Init, xsi, [xsi].hWnd, offset PropListView
  OCall xdi::ListView.HeaderSetFontStyle, LVHDRFONTBOLD; or LVHDRFONTITALIC
  OCall xdi::ListView.HeaderSetFlatStyle, TRUE

  lea xdi, [xsi].TBar
  OCall xdi::Toolbar.Init, xsi, [xsi].hWnd, offset PropToolbar, xbx, NULL, NULL
  mov [xsi].dToolbarHeight, $32($OCall(xdi::Toolbar.GetHeight))

  mov LVI.mask_, LVIF_TEXT
  m2z LVI.iItem
  m2z LVI.iSubItem
  c2m LVI.pszText, $OfsCStr("Width"), xax
  invoke SendMessage, [xsi].LView.hWnd, LVM_INSERTITEM, 0, addr LVI
  mov LVI.iSubItem, 1
  c2m LVI.pszText, $OfsCStr("10"), xax
  invoke SendMessage, [xsi].LView.hWnd, LVM_SETITEM, 0, addr LVI

  mov LVI.iItem, 1
  m2z LVI.iSubItem
  c2m LVI.pszText, $OfsCStr("Heigth"), xax
  invoke SendMessage, [xsi].LView.hWnd, LVM_INSERTITEM, 0, addr LVI
  mov LVI.iSubItem, 1
  c2m LVI.pszText, $OfsCStr("20"), xax
  invoke SendMessage, [xsi].LView.hWnd, LVM_SETITEM, 0, addr LVI

  OCall [xsi].LView::ListView.CheckItem, 1, TRUE

  OCall [xsi].CBox::ComboBox.Init, xsi, [xsi].hWnd, offset PropComboBox
  invoke SendMessage, [xsi].LView.hWnd, WM_GETFONT, 0, 0
  invoke SendMessage, [xsi].CBox.hWnd, WM_SETFONT, eax, FALSE

  invoke SendMessage, [xsi].CBox.hWnd, CB_ADDSTRING, 0, $OfsCStr("First string")
  invoke SendMessage, [xsi].CBox.hWnd, CB_ADDSTRING, 0, $OfsCStr("Second string")
  invoke SendMessage, [xsi].CBox.hWnd, CB_ADDSTRING, 0, $OfsCStr("Third string")

  invoke SendMessage, [xsi].CBox.hWnd, CB_SETCURSEL, 0, 0

  invoke DefWindowProc, [xsi].hWnd, WM_CREATE, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     PropertiesWnd.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method PropertiesWnd.OnPaint, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, CtRect:RECT

  SetObject xsi
  invoke BeginPaint, [xsi].hWnd, addr PS
  invoke GetClientRect, [xsi].hWnd, addr CtRect

  mov eax, CtRect.right
  sub eax, CtRect.left
  invoke MoveWindow, [xsi].CBox.hWnd, CtRect.left, CtRect.top, eax, 250, FALSE
  OCall [xsi].CBox::ComboBox.GetHeight
  add CtRect.top, eax

  mov ebx, CtRect.right
  sub ebx, CtRect.left
  mov eax, CtRect.bottom
  sub eax, CtRect.top
  sub eax, [xsi].dToolbarHeight                     ;Let space for buttons
  dec eax
  dec eax
  invoke MoveWindow, [xsi].LView.hWnd, CtRect.left, CtRect.top, ebx, eax, TRUE

  mov eax, CtRect.bottom
  sub eax, [xsi].dToolbarHeight
  inc CtRect.left
  dec eax
  invoke MoveWindow, [xsi].TBar.hWnd, CtRect.left, eax, ebx, [xsi].dToolbarHeight, TRUE

  invoke EndPaint, [xsi].hWnd, addr PS
  invoke DefWindowProc,[xsi].hWnd, WM_PAINT, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     PropertiesWnd.Startup
; Purpose:    Register the object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method PropertiesWnd.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CS_HREDRAW or CS_VREDRAW
  m2m WC.lpfnWndProc, $MethodAddr(PropertiesWnd.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  mov WC.hbrBackground, COLOR_BTNFACE + 1
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szPropertiesWnd, xax
  m2z WC.hIcon
  m2z WC.hIconSm
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)

  invoke RegisterClassEx, addr WC
MethodEnd

endif
