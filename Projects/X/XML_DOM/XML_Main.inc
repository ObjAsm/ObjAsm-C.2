; ==================================================================================================
; Title:      XML_Main.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm XML Test.
; Notes:      Version C.1.0, November 2024
;               - First release.
; ==================================================================================================


CLSSTYLE equ CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW; or CS_DROPSHADOW

CStr szApplication, "Application"


Object Application, MySdiAppID, SdiApp
  VirtualMethod     AddTreeViewNode,        HTREEITEM, HTREEITEM, PSTRING
  VirtualMethod     Clear
  RedefineMethod    Done
  VirtualMethod     ExpandAllSubItemsFrom,  HTREEITEM
  VirtualMethod     FinalExceptionHandler,  POINTER
  RedefineMethod    Init
  VirtualMethod     ParseXML,               $ObjPtr(XmlNode), HTREEITEM
  RedefineMethod    OnSize,                 WPARAM, LPARAM
  StaticMethod      Startup

  VirtualEvent      OnCreate,   WM_CREATE
  VirtualEvent      OnCommand,  WM_COMMAND
  VirtualEvent      OnClose,    WM_CLOSE, WM_QUERYENDSESSION
  VirtualEvent      OnPaint,    WM_PAINT

  DefineVariable    hTreeView,  HWND,       0
  DefineVariable    hRootItem,  HTREEITEM,  0

  Embed   RootNode,             XmlNode
  Embed   WriteXmlDocument,     XmlDocument
  Embed   ReadXmlDocument,      XmlDocument
ObjectEnd


.code


; ==================================================================================================
;    Application implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Clear
; Purpose:    Add a new item to the TreeView
; Arguments:  Arg1: Parent HTREEITEM.
;             Arg2: HTREEITEM item after the insertion should take place.
; Return:     Nothing.

Method Application.AddTreeViewNode, uses xsi, hParent:HTREEITEM, hAfter:HTREEITEM, pText:PSTRING
  local tvins:TV_INSERTSTRUCT

  SetObject xsi
  ?mov xdx, hParent
  mov tvins.hParent, xdx
  m2m tvins.hInsertAfter, hAfter, xax
  mov tvins.item.mask_, TVIF_TEXT
  m2m tvins.item.pszText, pText, xax
  invoke SendMessage, [xsi].hTreeView, TVM_INSERTITEM, 0, addr tvins
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Clear
; Purpose:    Reset WriteXmlDocument and ReadXmlDocument.
; Arguments:  None.
; Return:     Nothing.

Method Application.Clear, uses xsi
  SetObject xsi
  OCall [xsi].WriteXmlDocument::XmlDocument.Clear
  OCall [xsi].ReadXmlDocument::XmlDocument.Clear
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Done
; Purpose:    Finalizes the Application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Done
  SetObject xcx
  ACall xcx.Done
  invoke CoUninitialize
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.ExpandAllSubItemsFrom
; Purpose:    Expand all sub items starting from an item. E.g. the root item.
; Arguments:  Arg1: Starting HTREEITEM.
; Return:     xax = Starting HTREEITEM.

Method Application.ExpandAllSubItemsFrom, uses xsi, hStartItem:HTREEITEM
  SetObject xsi
  invoke SendMessage, [xsi].hTreeView, TVM_EXPAND, TVE_EXPAND, hStartItem
  .if xax != 0
    invoke SendMessage, [xsi].hTreeView, TVM_GETNEXTITEM, TVGN_CHILD, hStartItem
    OCall xsi.ExpandAllSubItemsFrom, xax
    .while TRUE
      invoke SendMessage, [xsi].hTreeView, TVM_GETNEXTITEM, TVGN_NEXT, xax
      .break .if xax == 0
      OCall xsi.ExpandAllSubItemsFrom, xax
    .endw
  .endif
  mov xax, hStartItem
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Init
; Purpose:    Initialize the SDI application object.
; Arguments:  Arg1: -> Exeption.
; Return:     Nothing.

Method Application.FinalExceptionHandler,, pException:POINTER
  ;ClearUp
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Init
; Purpose:    Initialize the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Init, uses xsi
  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD
  local icex: INITCOMMONCONTROLSEX

  SetObject xsi
  ACall xsi.Init

  invoke InitCommonControls
  mov icex.dwSize, sizeof INITCOMMONCONTROLSEX
  mov  icex.dwICC, ICC_DATE_CLASSES or ICC_USEREX_CLASSES or ICC_INTERNET_CLASSES or \
                   ICC_ANIMATE_CLASS or ICC_HOTKEY_CLASS or ICC_PAGESCROLLER_CLASS or \
                   ICC_COOL_CLASSES
  invoke InitCommonControlsEx, addr icex
  invoke CoInitialize, NULL
  invoke SetUnhandledExceptionFilter, $MethodAddr(xsi::Application.FinalExceptionHandler)

  mov dWndWidth, 500                                    ;Default creation width
  mov dWndHeight, 350                                   ;Default creation height

  mov dWndPosX, $32($invoke(CenterForm, dWndWidth,  $32($invoke(GetSystemMetrics, SM_CXSCREEN))))
  mov dWndPosY, $32($invoke(CenterForm, dWndHeight, $32($invoke(GetSystemMetrics, SM_CYSCREEN))))

  invoke CreateWindowEx, WS_EX_LEFT or WS_EX_APPWINDOW, \
                         offset szApplication, offset szAppTitle, WS_OVERLAPPEDWINDOW, \
                         dWndPosX, dWndPosY, dWndWidth, dWndHeight, NULL, NULL, hInstance, pSelf

  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL          ;Show the window
  invoke UpdateWindow, [xsi].hWnd                       ;Update if necessary
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[MAX_PATH]:CHR, Dlg:$Obj(DialogAbout)

  SetObject xsi
  mov xax, wParam
  .if ax == IDM_EXIT
    invoke SendMessage, [xsi].hWnd, WM_SYSCOMMAND, SC_CLOSE, NULL
    xor eax, eax

  .elseif ax == IDM_ABOUT
    New Dlg::DialogAbout
    invoke LoadIcon, hInstance, offset szIcoName
    OCall Dlg::DialogAbout.Init, xsi, [xsi].hWnd, xax, offset szAboutText
    OCall Dlg::DialogAbout.Show
    OCall Dlg::DialogAbout.Done
    xor eax, eax

  .elseif ax == IDM_HELP
    invoke ExpandEnvironmentStrings, $OfsCStr("%OBJASM_PATH%\Help\ObjAsm_Reference_Volume-I.pdf"), \
                                     addr cBuffer, lengthof(cBuffer)
    invoke PdfView, [xsi].hWnd, addr cBuffer, $OfsCStr("Introduction")
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
; Return:     eax = Zero if handled.

Method Application.OnCreate, uses xsi, wParam:WPARAM, lParam:LPARAM
  local TempNode:$Obj(XmlNode), pXML:PSTRING

  SetObject xsi
  invoke CreateWindowEx, 0, $OfsCStr("SysTreeView32"), 0,\
                         WS_CHILD or WS_VISIBLE or TVS_HASLINES or TVS_HASBUTTONS or TVS_LINESATROOT, \
                         CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                         [xsi].hWnd, 0, hInstance, xsi
  mov [xsi].hTreeView, xax

  OCall [xsi].WriteXmlDocument::XmlDocument.Init, xsi
  OCall [xsi].ReadXmlDocument::XmlDocument.Init, xsi
  OCall [xsi].RootNode::XmlNode.Init, xsi

  New TempNode::XmlNode
  OCall TempNode::XmlNode.Init, xsi

  ;Create the XML tree
  OCall [xsi].WriteXmlDocument::XmlDocument.AddChild, $OfsCStr("Root")
  OCall [xsi].RootNode::XmlNode.SetNode, xax
  OCall [xsi].RootNode::XmlNode.SetAttribute, $OfsCStr("Created"), $OfsCStr("Using XML Object")

  OCall [xsi].RootNode::XmlNode.AddChild, $OfsCStr("Node1")
  OCall TempNode::XmlNode.SetNode, xax
  OCall TempNode::XmlNode.SetText, $OfsCStr("Text1")

  OCall [xsi].RootNode::XmlNode.AddChild, $OfsCStr("Node2")
  OCall TempNode::XmlNode.SetNode, xax
  OCall TempNode::XmlNode.SetText, $OfsCStr("Text2")

  OCall [xsi].RootNode::XmlNode.AddChild, $OfsCStr("Node3")
  OCall TempNode::XmlNode.SetNode, xax
  OCall TempNode::XmlNode.AddChild, $OfsCStr("SubNode1")
  OCall TempNode::XmlNode.AddChild, $OfsCStr("SubNode2")
  OCall TempNode::XmlNode.AddChild, $OfsCStr("SubNode3")

  ;Save the XML content
  OCall [xsi].WriteXmlDocument::XmlDocument.SaveToFile, offset szFileName
  mov pXML, $OCall([xsi].WriteXmlDocument::XmlDocument.GetXML)
  invoke MessageBox, [xsi].hWnd, pXML, $OfsCStr("Saved XML content"), MB_OK
  invoke StrDispose, pXML

  ;Read the XML content back
  OCall [xsi].ReadXmlDocument::XmlDocument.LoadFromFile, offset szFileName
  mov pXML, $OCall([xsi].ReadXmlDocument::XmlDocument.GetXML)
  invoke MessageBox, [xsi].hWnd, pXML, $OfsCStr("Read XML content"), MB_OK
  invoke StrDispose, pXML

  ;Fill the TreeView
  mov [xsi].hRootItem, $OCall(xsi.AddTreeViewNode, NULL, TVI_ROOT, $OfsCStr("XML Document"))
  OCall [xsi].ReadXmlDocument::XmlDocument.GetDocumentElement
  OCall TempNode::XmlNode.SetNode, xax
  OCall xsi.ParseXML, addr TempNode, [xsi].hRootItem

  ;Expand all TreeView items starting from the root item
  OCall xsi.ExpandAllSubItemsFrom, [xsi].hRootItem
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
; Method:     Application.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnPaint, uses xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, hDC:HDC, CRect:RECT

  SetObject xsi
  mov hDC, $invoke(BeginPaint, [xsi].hWnd, addr PS)

  invoke GetClientRect, [xsi].hWnd, addr CRect
  invoke DrawEdge, hDC, addr CRect, EDGE_SUNKEN, BF_RECT

  invoke EndPaint, [xsi].hWnd, addr PS
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnSize, uses xsi, wParam:WPARAM, lParam:LPARAM
  local CRect:RECT

  SetObject xsi
  invoke GetClientRect, [xsi].hWnd, addr CRect
  GrowRect CRect, -2, -2                                ;EDGE_SUNKEN rquires 2 pixels width
  invoke MoveWindow, [xsi].hTreeView, CRect.left, CRect.top, CRect.right, CRect.bottom, FALSE
  ACall xsi.OnSize, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.ParseXML
; Purpose:    Parse the XML node and create TV items that represent it.
; Arguments:  Arg1: -> XmlNode.
;             Arg2: HTREEITEM parent item.
; Return:     Nothing.

Method Application.ParseXML, uses xbx xsi, pInitNode:$ObjPtr(XmlNode), hParentItem:HTREEITEM
  local ChildNode:$Obj(XmlNode), dNodeCount:DWORD, hNewItem:HTREEITEM
  local pType:PSTRING, pName:PSTRING, pText:PSTRING

  SetObject xsi
  OCall pInitNode::XmlNode.GetType
  mov pType, xax
  invoke StrComp, pType, offset szElement
  .if eax == 0
    mov pName, $OCall(pInitNode::XmlNode.GetName)
    mov hNewItem, $OCall(xsi.AddTreeViewNode, hParentItem, TVI_LAST, pName)
    invoke StrDispose, pName
  .else
    invoke StrComp, pType, addr szText
    .if eax == 0
      mov pText, $OCall(pInitNode::XmlNode.GetText)
      mov hNewItem, $OCall(xsi.AddTreeViewNode, hParentItem, TVI_LAST, pText)
      invoke StrDispose, pText
    .else
      mov pName, $OCall(pInitNode::XmlNode.GetName)
      mov hNewItem, $OCall(xsi.AddTreeViewNode, hParentItem, TVI_LAST, pName)
      invoke StrDispose, pName
    .endif
  .endif
  invoke StrDispose, pType

  OCall pInitNode::XmlNode.HasChildNodes
  .if eax != 0
    OCall pInitNode::XmlNode.GetChildNodesCount
    mov dNodeCount, eax
    New ChildNode::XmlNode
    OCall ChildNode::XmlNode.Init, NULL
    xor ebx, ebx
    .while ebx < dNodeCount
      OCall pInitNode::XmlNode.GetChildNode, ebx
      OCall ChildNode::XmlNode.SetNode, xax
      OCall xsi.ParseXML, addr ChildNode, hNewItem
      inc ebx
    .endw
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Startup
; Purpose:    Register the Application window class with the operating system.
; Arguments:  None.
; Return:     Nothing.

Method Application.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof(WNDCLASSEX)
  mov WC.style, CLSSTYLE
  m2m WC.lpfnWndProc, $MethodAddr(SdiApp.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  m2z WC.hbrBackground
  c2m WC.lpszMenuName, $OfsCStr("MENU_APP"), rax
  c2m WC.lpszClassName, offset szApplication, rax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, offset szIcoName)
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd
