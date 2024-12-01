; ==================================================================================================
; Title:      XTreeViewDemo_Main.asm
; Author:     G. Friedrich
; Version:    See XTreeViewDemo.asm
; Purpose:    ObjAsm XTreeview Demo Application.
; ==================================================================================================


CLSSTYLE equ CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW; or CS_DROPSHADOW

CStr szXTVDemoApp, "OAC_XTVDemoApp"

.const
XTV_Def DEF_XTV {100, WS_CLIPSIBLINGS, WS_EX_ACCEPTFILES or WS_EX_NOPARENTNOTIFY or WS_EX_CONTROLPARENT,
                 $OfsTStr("Title"), {<0,0,200,300>}}


Object Application, ApplicationID, SdiApp
  RedefineMethod    Done
  RedefineMethod    Init
  RedefineMethod    OnSize,             WPARAM, LPARAM
  StaticMethod      Startup
  RedefineMethod    WndProc,            DWORD, WPARAM, LPARAM

  VirtualEvent      OnCommand,          WM_COMMAND
;  VirtualEvent      OnClose,            WM_CLOSE, WM_QUERYENDSESSION
  VirtualEvent      OnCreate,           WM_CREATE
  VirtualEvent      OnPaint,            WM_PAINT
  VirtualEvent      OnFocus,            WM_KILLFOCUS, WM_SETFOCUS
  VirtualEvent      OnMouseWheel,       WM_MOUSEWHEEL
  VirtualEvent      OnKeyDown,          WM_KEYDOWN
  VirtualEvent      OnKeyUp,            WM_KEYUP


  Embed  XTV,   XCustomTreeView

ObjectEnd

HEIGHT_LEVEL_1  equ  35
HEIGHT_LEVEL_2  equ  20
HEIGHT_LEVEL_3  equ  16
WIDTH_LEVEL_1   equ  265
WIDTH_LEVEL_2   equ  WIDTH_LEVEL_1
WIDTH_LEVEL_3   equ  WIDTH_LEVEL_1

;Object TVDialog, 0, DialogModal
;  RedefineMethod    CtlsSet
;ObjectEnd

.code

; ==================================================================================================
;    Application implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Done
; Purpose:    Finalize the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Done, uses xsi
  SetObject xsi
  OCall [xsi].XTV::XCustomTreeView.Done
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Init
; Purpose:    Initialize the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Init, uses xsi
  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD
;  local Dlg:TVDialog

  SetObject xsi
  ACall xsi.Init

  mov dWndWidth, 450                                    ;Default creation width
  mov dWndHeight, 650                                   ;Default creation height
  mov dWndPosX, $32($invoke(CenterForm, dWndWidth, $32($invoke(GetSystemMetrics, SM_CXSCREEN))))
  mov dWndPosY, $32($invoke(CenterForm, dWndHeight, $32($invoke(GetSystemMetrics, SM_CYSCREEN))))

  invoke CreateWindowEx, WS_EX_LEFT or WS_EX_APPWINDOW, \
                         offset szXTVDemoApp, offset szAppTitle, WS_OVERLAPPEDWINDOW, \
                         dWndPosX, dWndPosY, dWndWidth, dWndHeight, NULL, NULL, hInstance, pSelf

  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL
  invoke UpdateWindow, [xsi].hWnd

;  New Dlg::TVDialog.Init, esi, [xsi].hWnd, $OfsCStr("DIALOGTEST")
;  OCall Dlg::DialogModal.Show
;  OCall Dlg::DialogModal.Done
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
; Method:     Application.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[MAX_PATH]:CHR, Dlg:$Obj(DialogAbout), hIcon:HICON

  SetObject xsi
  mov xax, wParam
  .if ax == IDM_EXIT
    invoke SendMessage, [xsi].hWnd, WM_SYSCOMMAND, SC_CLOSE, NULL
    xor eax, eax

  .elseif ax == IDM_ABOUT
    New Dlg::DialogAbout
    mov hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
    OCall Dlg::DialogAbout.Init, xsi, [xsi].hWnd, hIcon, offset szAboutText
    OCall Dlg::DialogAbout.Show
    OCall Dlg::DialogAbout.Done
    invoke DestroyIcon, hIcon
    xor eax, eax

  .elseif ax == IDM_HELP
    invoke ExpandEnvironmentStrings, $OfsCStr("%OBJASM_PATH%\Help\ObjAsm_Reference_Volume-I.pdf"), \
                                     addr cBuffer, lengthof(cBuffer)
    invoke PdfView, [xsi].hWnd, addr cBuffer, NULL
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
; Return:     eax = Zero.

Method Application.OnCreate, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local pNode0:$ObjPtr(XCustomNode), pNodeX:$ObjPtr(XCustomNode), pNodeY:$ObjPtr(XCustomNode)

  SetObject xsi
  lea xbx, [xsi].XTV
  OCall xbx::XCustomTreeView.Init, xsi, [xsi].hWnd, offset XTV_Def
  ReleaseObject xsi

  mov pNode0, $New(XCustomNode)
  OCall pNode0::XCustomNode.Init, xbx, WIDTH_LEVEL_1, HEIGHT_LEVEL_1, XTVNS_EXPANDED
  OCall xbx::XCustomTreeView.Insert, pNode0, NULL, XTVN_INSERT_AS_LAST_CHILD
;  BitSet [xax].XCustomNode.dState, XTVNS_DISABLED

  mov edi, 500
  test edi, edi
  .while !ZERO?
    mov pNodeX, $New(XCustomNode)
    OCall pNodeX::XCustomNode.Init, xbx, WIDTH_LEVEL_2, HEIGHT_LEVEL_2, XTVNS_EXPANDED
    OCall xbx::XCustomTreeView.Insert, pNodeX, pNode0, XTVN_INSERT_AS_LAST_CHILD

    mov esi, 10
    test esi, esi
    .while !ZERO?
      mov pNodeY, $New(XCustomNode)
      OCall xax::XCustomNode.Init, xbx, WIDTH_LEVEL_2, HEIGHT_LEVEL_2, XTVNS_EXPANDED
      OCall xbx::XCustomTreeView.Insert, pNodeY, pNodeX, XTVN_INSERT_AS_LAST_CHILD
      dec esi
    .endw

    dec edi
  .endw

  mov pNodeX, $New(XCustomNode)
  OCall pNodeX::XCustomNode.Init, xbx, WIDTH_LEVEL_1, HEIGHT_LEVEL_1, XTVNS_EXPANDED
  OCall xbx::XCustomTreeView.Insert, pNodeX, NULL, XTVN_INSERT_AS_LAST_CHILD

    mov pNodeY, $New(XCustomNode)
    OCall pNodeY::XCustomNode.Init, xbx, WIDTH_LEVEL_2, HEIGHT_LEVEL_2, XTVNS_EXPANDED
    OCall xbx::XCustomTreeView.Insert, pNodeY, pNodeX, XTVN_INSERT_AS_LAST_CHILD

    mov pNodeY, $New(XCustomNode)
    OCall pNodeY::XCustomNode.Init, xbx, WIDTH_LEVEL_3, HEIGHT_LEVEL_3, XTVNS_EXPANDED
    OCall xbx::XCustomTreeView.Insert, pNodeY, pNodeX, XTVN_INSERT_AS_LAST_CHILD

    mov pNodeY, $New(XCustomNode)
    OCall pNodeY::XCustomNode.Init, xbx, WIDTH_LEVEL_2, HEIGHT_LEVEL_2, XTVNS_EXPANDED
    OCall xbx::XCustomTreeView.Insert, pNodeY, pNodeX, XTVN_INSERT_AS_LAST_CHILD

    mov edi, 3000;0000
    test edi, edi
    .while !ZERO?
      mov pNodeY, $New(XCustomNode)
      OCall pNodeY::XCustomNode.Init, xbx, WIDTH_LEVEL_3, HEIGHT_LEVEL_3, XTVNS_EXPANDED
      OCall xbx::XCustomTreeView.Insert, pNodeY, pNodeX, XTVN_INSERT_AS_LAST_CHILD
      dec edi
    .endw

  mov edi, 500;0000
  test edi, edi
  .while !ZERO?
    mov pNodeY, $New(XCustomNode)
    OCall pNodeY::XCustomNode.Init, xbx, WIDTH_LEVEL_2, HEIGHT_LEVEL_2, XTVNS_EXPANDED
    OCall xbx::XCustomTreeView.Insert, pNodeY, pNodeX, XTVN_INSERT_AS_LAST_CHILD
    dec edi
  .endw

  mov pNodeY, $New(XCustomNode)
  OCall pNodeY::XCustomNode.Init, xbx, WIDTH_LEVEL_1, HEIGHT_LEVEL_1, XTVNS_EXPANDED
  mov pNodeX, $OCall(xbx::XCustomTreeView.Insert, pNodeY, NULL, XTVN_INSERT_AS_LAST_CHILD)

  mov edi, 30;00
  test edi, edi
  .while !ZERO?
    mov pNodeY, $New(XCustomNode)
    OCall pNodeY::XCustomNode.Init, xbx, WIDTH_LEVEL_2, HEIGHT_LEVEL_2, XTVNS_EXPANDED
    OCall xbx::XCustomTreeView.Insert, pNodeY, pNodeX, XTVN_INSERT_AS_LAST_CHILD
    dec edi
  .endw
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnFocus
; Purpose:    Event procedure for WM_KILLFOCUS and WM_SETFOCUS messages.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Application.OnFocus,, wParam:WPARAM, lParam:LPARAM
  SetObject xcx
  invoke SendMessage, [xcx].XTV.hWnd, eax, wParam, lParam     ;eax = Message
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnMouseWheel
; Purpose:    Forward the message WM_MOUSEWHEEL to the focused window.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnMouseWheel,, wParam:WPARAM, lParam:LPARAM
  SetObject xcx
  invoke SendMessage, [xcx].XTV.hWnd, WM_MOUSEWHEEL, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnPaint, uses xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, hDC:HDC, Rct:RECT

  SetObject xsi
  mov hDC, $invoke(BeginPaint, [xsi].hWnd, addr PS)

  invoke GetClientRect, [xsi].hWnd, addr Rct

  invoke EndPaint, [xsi].hWnd, addr PS
  mov eax, TRUE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Application.OnSize, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "Application.OnSize"
  SetObject xsi
  .if [xsi].XTV.hWnd != 0
    PntS2Regs lParam, ebx
    invoke MoveWindow, [xsi].XTV.hWnd, 0, 0, eax, ebx, TRUE
    OCall [xsi].XTV::XCustomTreeView.Draw
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnSettingChange
; Purpose:    Event handler for WM_SETTINGCHANGE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Application.OnSettingChange,, wParam:WPARAM, lParam:LPARAM
;  DbgText "Application.OnSettingChange"
  SetObject xcx
  invoke SendMessage, [xcx].XTV.hWnd, WM_SETTINGCHANGE, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnSysColorChange
; Purpose:    Event handler for WM_SYSCOLORCHANGE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Application.OnSysColorChange,, wParam:WPARAM, lParam:LPARAM
;  DbgText "Application.OnSysColorChange"
  SetObject xcx
  invoke SendMessage, [xcx].XTV.hWnd, WM_SYSCOLORCHANGE, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnKeyDown
; Purpose:    Forward this message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Message return value.

Method Application.OnKeyDown,, wParam:WPARAM, lParam:LPARAM
  SetObject xcx
  invoke SendMessage, [xcx].XTV.hWnd, WM_KEYDOWN, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnKeyUp
; Purpose:    Forward this message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Message return value.

Method Application.OnKeyUp,, wParam:WPARAM, lParam:LPARAM
  SetObject xcx
  invoke SendMessage, [xcx].XTV.hWnd, WM_KEYUP, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Startup
; Purpose:    Register the object class with the OS.
; Arguments:  None.
; Return:     Nothing.

Method Application.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CLSSTYLE
  m2m WC.lpfnWndProc, $MethodAddr(Application.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  mov WC.hbrBackground, NULL
  c2m WC.lpszMenuName, $OfsCStr("MENU_APP"), xax
  c2m WC.lpszClassName, offset szXTVDemoApp, xax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.WindowProc
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = Result of the message processing and depends on the message.

Method Application.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg
  .if uMsg == WM_NCCREATE
    mov xax, lParam
    mov xsi, [xax].CREATESTRUCT.lpCreateParams
    or xsi, xsi
    jz @@DefProc                                        ;Goto handler defined in DispatchEvent
    m2m [xsi].$Obj(SdiApp).hWnd, pSelf, xax             ;pSelf = hWnd
    invoke SetWindowLongPtr, pSelf, GWLP_USERDATA, xsi
  .elseif uMsg == WM_INITDIALOG                         ;Added for Dialog applications
    mov xsi, lParam
    or xsi, xsi
    jz @@DefProc                                        ;Goto handler defined in DispatchEvent
    m2m [xsi].$Obj(SdiApp).hWnd, pSelf, xax             ;pSelf = hWnd
    invoke SetWindowLongPtr, pSelf, DWLP_USER, xsi
  .else
    invoke GetWindowLongPtr, pSelf, GWLP_USERDATA       ;If GWL_USERDATA wasn't set,
    .if xax == 0                                        ;  it returns NULL
      invoke GetWindowLongPtr, pSelf, DWLP_USER
      test eax, eax
      jz @@DefProc                                      ;Goto handler defined in DispatchEvent
    .endif
    mov xsi, xax
  .endif

  DispatchEvent <DefWindowProc, pSelf>                  ;xsi -> Object Instance
MethodEnd


;; ==================================================================================================
;;    TVDialog implementation
;; ==================================================================================================
;
;; ——————————————————————————————————————————————————————————————————————————————————————————————————
;; Method:     TVDialog.CtlsSet
;; Purpose:    Insert some nodes.
;; Arguments:  None.
;; Return:     Nothing.
;
;Method TVDialog.CtlsSet, uses ebx edi esi
;  local pNode:$ObjPtr(XCustomNode)
;
;  SetObject esi
;  invoke GetDlgItem, [xsi].hWnd, 1234
;  invoke SendMessage, eax, WM_GETOBJECTINSTANCE, 0, 0
;  SetObject ebx, XCustomTreeView, eax
;
;  New XCustomNode.Init, ebx, WIDTH_LEVEL_1, HEIGHT_LEVEL_1, XTVNS_EXPANDED
;  mov pNode, $OCall(ebx.Insert, eax, NULL, XTVN_INSERT_AS_LAST_CHILD)
;
;    mov edi, 8;00000
;    test edi, edi
;    .while !ZERO?
;      New XCustomNode.Init, ebx, WIDTH_LEVEL_2, HEIGHT_LEVEL_2, XTVNS_EXPANDED
;      OCall ebx.Insert, eax, pNode, XTVN_INSERT_AS_LAST_CHILD
;      dec edi
;    .endw
;
;  New XCustomNode.Init, ebx, WIDTH_LEVEL_1, HEIGHT_LEVEL_1, XTVNS_EXPANDED
;  OCall ebx.Insert, eax, NULL, XTVN_INSERT_AS_LAST_CHILD
;
;  OCall ebx.Draw
;MethodEnd
;MethodEnd
