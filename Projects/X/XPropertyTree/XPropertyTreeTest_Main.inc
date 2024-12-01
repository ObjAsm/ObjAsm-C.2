; ==================================================================================================
; Title:      XPropertyTreeTest_Main.inc
; Author:     G. Friedrich
; Version:    XPropertyTreeTest.asm
; Purpose:    ObjAsm XPropertyTree Test Application.
; ==================================================================================================


CLSSTYLE equ CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW; or CS_DROPSHADOW

CStr cAppClassName, "OAC_Application"

.const
XPT_Def DEF_XTV {100, WS_CLIPSIBLINGS, WS_EX_ACCEPTFILES or WS_EX_NOPARENTNOTIFY,
                 $OfsTStr("XControl"), {<0,0,200,300>}}


Object Application, ApplicationID, SdiApp
  RedefineMethod    Done
  RedefineMethod    Init
  RedefineMethod    OnSize,             WPARAM, LPARAM
  StaticMethod      Startup
  RedefineMethod    WndProc,            DWORD, WPARAM, LPARAM

  VirtualEvent      OnCommand,          WM_COMMAND
  VirtualEvent      OnClose,            WM_CLOSE, WM_QUERYENDSESSION
  VirtualEvent      OnCreate,           WM_CREATE
  VirtualEvent      OnFocus,            WM_KILLFOCUS, WM_SETFOCUS
  VirtualEvent      OnMouseWheel,       WM_MOUSEWHEEL
  VirtualEvent      OnKeyDown,          WM_KEYDOWN
  VirtualEvent      OnKeyUp,            WM_KEYUP

  Embed  XPT,   XPropertyTree

  DefineVariable      cCaption,         CHR,      50 dup(0)
  DefineVariable      cDescription,     CHR,      200 dup(0)

  DefineVariable      dWidth,           DWORD,    200
  DefineVariable      dHeight,          DWORD,    25
  DefineVariable      r4Average,        REAL4,    0.25
  DefineVariable      dColor,           DWORD,    $RGB(255,255,0)
  DefineVariable      dSysColor,        DWORD,    27
  DefineVariable      dMode,            DWORD,    1
  DefineVariable      dAutoRedraw,      DWORD,    FALSE
  DefineVariable      dClipCtrls,       DWORD,    3
  DefineVariable      dDrawStyle,       DWORD,    1
  DefineVariable      cMainDirPath,     CHR,      MAX_PATH dup(0)
  DefineVariable      cConfigFile,      CHR,      MAX_PATH dup(0)
ObjectEnd

HEIGHT_LEVEL_1  equ  25
HEIGHT_LEVEL_2  equ  24
DIVIDER_WIDTH   equ  120

.data
OFN         OPENFILENAME    {}                          ;OPENFILENAMEW = OPENFILENAMEA
BI_Main     BROWSEINFO      {}                          ;BROWSEINFOW = BROWSEINFOA
BI_Setting  BROWSEINFO      {}                          ;BROWSEINFOW = BROWSEINFOA
CC          CHOOSECOLOR     {}                          ;CHOOSECOLORW = CHOOSECOLORA
ColorRef    DWORD           16 dup(0)



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
  OCall [xsi].XPT::XPropertyTree.Done
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Init
; Purpose:    Initialize the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Init, uses xsi
  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD

  SetObject xsi

  invoke InitCommonControls

  mov dWndWidth, 500                                  ;Default creation width
  mov dWndHeight, 550                                 ;Default creation height
  mov dWndPosX, $32($invoke(CenterForm, dWndWidth, $32($invoke(GetSystemMetrics, SM_CXSCREEN))))
  mov dWndPosY, $32($invoke(CenterForm, dWndHeight, $32($invoke(GetSystemMetrics, SM_CYSCREEN))))

  invoke CreateWindowEx, WS_EX_LEFT or WS_EX_APPWINDOW, \
                         offset cAppClassName, offset cAppCaption, WS_OVERLAPPEDWINDOW, \
                         dWndPosX, dWndPosY, dWndWidth, dWndHeight, NULL, NULL, hInstance, pSelf

  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL
  invoke UpdateWindow, [xsi].hWnd
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  Validate
; Purpose:    Helper procedure to validate numeric input.
; Arguments:  Arg1: Edit window HANDLE.
; Return:     Nothing.

CStr VALID_CHARS, " +-.0123456789Ee"

LR_LOADREALSIZE equ 00000080h

Validate proc uses xbx xdi xsi hEdit:HWND
  local cBuffer[1024]:CHR, dCursorPosition:DWORD

  lea xsi, cBuffer                                      ;xsi -> cBuffer
  mov xdi, xsi                                          ;xdi = xsi
  xor ebx, ebx                                          ;ebx = 0
  invoke SendMessage, hEdit, EM_GETSEL, addr dCursorPosition, NULL    ;Get cursor position
  invoke SendMessage, hEdit, WM_GETTEXT, lengthof cBuffer, xsi
  .while CHR ptr [xsi] != 0
    invoke StrLScan, offset VALID_CHARS, CHR ptr [xsi]
    .if xax != NULL
      movzx eax, CHR ptr [xsi]
      mov [xdi], $SubReg(xax, sizeof CHR)
      add xdi, sizeof CHR
    .elseif ebx < dCursorPosition
      dec dCursorPosition
    .endif
    add xsi, sizeof CHR
    inc ebx
  .endw

  m2z CHR ptr [xdi]
  invoke SetWindowText, hEdit, addr cBuffer
  invoke SendMessage, hEdit, EM_SETSEL, dCursorPosition, dCursorPosition    ;Set cursor position
  ret
Validate endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Application.OnCreate, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local pNodeCat:ptr $Obj(XPT_CategoryNode), pNodePrp:ptr $Obj(XPT_PropertyNode)
  local hIconStrMain:HICON, hIconStrItem:HICON, hIconStrItem2:HICON
  local hIconSize:HICON, hIconWidth:HICON, hIconHeight:HICON, hIconAverage:HICON
  local hIconStyle:HICON, hIconColor:HICON, hIconBorder:HICON, hIconMode:HICON
  local hIconBehavior:HICON, hIconRedraw:HICON, hIconClip:HICON, hIconDrawStyle:HICON
  local hIconPath:HICON, hIconMain:HICON, hIconConfig:HICON
  local cBuffer[1024]:CHR

  SetObject xsi

  lea xbx, [xsi].XPT
  OCall xbx::XPropertyTree.Init, xsi, [xsi].hWnd, offset XPT_Def

  mov hIconStrMain,   $invoke(LoadImage, hInstance, $OfsCStr("ICON_STR_MAIN"),  IMAGE_ICON, 0, 0, LR_LOADREALSIZE)
  mov hIconStrItem,   $invoke(LoadImage, hInstance, $OfsCStr("ICON_STR_ITEM"),  IMAGE_ICON, 0, 0, LR_LOADREALSIZE)

  mov hIconSize,      $invoke(LoadImage, hInstance, $OfsCStr("ICON_SIZE"),      IMAGE_ICON, 0, 0, LR_LOADREALSIZE)
  mov hIconWidth,     $invoke(LoadImage, hInstance, $OfsCStr("ICON_WIDTH"),     IMAGE_ICON, 0, 0, LR_LOADREALSIZE)
  mov hIconHeight,    $invoke(LoadImage, hInstance, $OfsCStr("ICON_HEIGHT"),    IMAGE_ICON, 0, 0, LR_LOADREALSIZE)
  mov hIconAverage,   $invoke(LoadImage, hInstance, $OfsCStr("ICON_AVERAGE"),   IMAGE_ICON, 0, 0, LR_LOADREALSIZE)

  mov hIconStyle,     $invoke(LoadImage, hInstance, $OfsCStr("ICON_STYLE"),     IMAGE_ICON, 0, 0, LR_LOADREALSIZE)
  mov hIconColor,     $invoke(LoadImage, hInstance, $OfsCStr("ICON_COLOR"),     IMAGE_ICON, 0, 0, LR_LOADREALSIZE)
  mov hIconBorder,    $invoke(LoadImage, hInstance, $OfsCStr("ICON_BORDER"),    IMAGE_ICON, 0, 0, LR_LOADREALSIZE)
  mov hIconMode,      $invoke(LoadImage, hInstance, $OfsCStr("ICON_MODE"),      IMAGE_ICON, 0, 0, LR_LOADREALSIZE)

  mov hIconBehavior,  $invoke(LoadImage, hInstance, $OfsCStr("ICON_BEHAVIOR"),  IMAGE_ICON, 0, 0, LR_LOADREALSIZE)
  mov hIconRedraw,    $invoke(LoadImage, hInstance, $OfsCStr("ICON_REDRAW"),    IMAGE_ICON, 0, 0, LR_LOADREALSIZE)
  mov hIconClip,      $invoke(LoadImage, hInstance, $OfsCStr("ICON_CLIP"),      IMAGE_ICON, 0, 0, LR_LOADREALSIZE)
  mov hIconDrawStyle, $invoke(LoadImage, hInstance, $OfsCStr("ICON_DRAWSTYLE"), IMAGE_ICON, 0, 0, LR_LOADREALSIZE)

  mov hIconPath,      $invoke(LoadImage, hInstance, $OfsCStr("ICON_PATH"),      IMAGE_ICON, 0, 0, LR_LOADREALSIZE)
  mov hIconMain,      $invoke(LoadImage, hInstance, $OfsCStr("ICON_MAIN"),      IMAGE_ICON, 0, 0, LR_LOADREALSIZE)
  mov hIconConfig,    $invoke(LoadImage, hInstance, $OfsCStr("ICON_CONFIG"),    IMAGE_ICON, 0, 0, LR_LOADREALSIZE)


  mov pNodeCat, $New(XPT_CategoryNode)
  OCall xbx::XPropertyTree.Insert, xax, NULL, XTVN_INSERT_AS_LAST_CHILD
  OCall pNodeCat::XPT_CategoryNode.Init, xbx, hIconStrMain, $OfsCStr("Strings"), \
                                         HEIGHT_LEVEL_1, XTVNS_EXPANDED

    mov pNodePrp, $New(XPT_PropertyNode)
    OCall xbx::XPropertyTree.Insert, xax, pNodeCat, XTVN_INSERT_AS_LAST_CHILD
    OCall pNodePrp::XPT_PropertyNode.Init, xbx, hIconStrItem, $OfsCStr("Caption"), \
                                           HEIGHT_LEVEL_2, DIVIDER_WIDTH, XTVNS_EXPANDED, \
                                           addr [xsi].cCaption, XPT_VAR_TYPE_STRING, 50
    mov xax, pNodePrp
    BitSet [xax].$Obj(XPT_PropertyNode).dState, XTVNS_DISABLED
    mov hIconStrItem2, $invoke(CopyIcon, hIconStrItem)

    mov pNodePrp, $New(XPT_PropertyNode)
    OCall xbx::XPropertyTree.Insert, xax, pNodeCat, XTVN_INSERT_AS_LAST_CHILD
    OCall pNodePrp::XPT_PropertyNode.Init, xbx, hIconStrItem2, $OfsCStr("Description"), \
                                           HEIGHT_LEVEL_2, DIVIDER_WIDTH, XTVNS_EXPANDED, \
                                           addr [xsi].cDescription, XPT_VAR_TYPE_STRING, 200

  mov pNodeCat, $New(XPT_CategoryNode)
  OCall xbx::XPropertyTree.Insert, xax, NULL, XTVN_INSERT_AS_LAST_CHILD
  OCall pNodeCat::XPT_CategoryNode.Init, xbx, hIconSize, $OfsCStr("Size"), \
                                         HEIGHT_LEVEL_1, XTVNS_EXPANDED

    mov pNodePrp, $New(XPT_PropertyNode)
    OCall xbx::XPropertyTree.Insert, xax, pNodeCat, XTVN_INSERT_AS_LAST_CHILD
    OCall pNodePrp::XPT_PropertyNode.Init, xbx, hIconWidth, $OfsCStr("Width"), \
                                           HEIGHT_LEVEL_2, DIVIDER_WIDTH, XTVNS_EXPANDED, \
                                           addr [xsi].dWidth, XPT_VAR_TYPE_INTEGER, NULL

    mov pNodePrp, $New(XPT_PropertyNode)
    OCall xbx::XPropertyTree.Insert, xax, pNodeCat, XTVN_INSERT_AS_LAST_CHILD
    OCall pNodePrp::XPT_PropertyNode.Init, xbx, hIconHeight, $OfsCStr("Height"), \
                                           HEIGHT_LEVEL_2, DIVIDER_WIDTH, XTVNS_EXPANDED, \
                                           addr [xsi].dHeight, XPT_VAR_TYPE_INTEGER, NULL

    mov pNodePrp, $New(XPT_PropertyNode)
    OCall xbx::XPropertyTree.Insert, xax, pNodeCat, XTVN_INSERT_AS_LAST_CHILD
    OCall pNodePrp::XPT_PropertyNode.Init, xbx, hIconAverage, $OfsCStr("Average"), \
                                           HEIGHT_LEVEL_2, DIVIDER_WIDTH, XTVNS_EXPANDED, \
                                           addr [xsi].r4Average, XPT_VAR_TYPE_REAL4, offset Validate

  mov pNodeCat, $New(XPT_CategoryNode)
  OCall xbx::XPropertyTree.Insert, xax, NULL, XTVN_INSERT_AS_LAST_CHILD
  OCall pNodeCat::XPT_CategoryNode.Init, xbx, hIconStyle, $OfsCStr("Style"), \
                                         HEIGHT_LEVEL_1, XTVNS_EXPANDED

    mov pNodePrp, $New(XPT_PropertyNode)
    OCall xbx::XPropertyTree.Insert, xax, pNodeCat, XTVN_INSERT_AS_LAST_CHILD
    OCall pNodePrp::XPT_PropertyNode.Init, xbx, hIconColor, $OfsCStr("Custom color"), \
                                           HEIGHT_LEVEL_2, DIVIDER_WIDTH, XTVNS_EXPANDED, \
                                           addr [xsi].dColor, XPT_VAR_TYPE_COLOR, offset CC

    mov pNodePrp, $New(XPT_PropertyNode)
    OCall xbx::XPropertyTree.Insert, xax, pNodeCat, XTVN_INSERT_AS_LAST_CHILD
    OCall pNodePrp::XPT_PropertyNode.Init, xbx, hIconBorder, $OfsCStr("Border color"), \
                                           HEIGHT_LEVEL_2, DIVIDER_WIDTH, XTVNS_EXPANDED, \
                                           addr [xsi].dSysColor, XPT_VAR_TYPE_SYS_COLOR, NULL

    mov pNodePrp, $New(XPT_PropertyNode)
    OCall xbx::XPropertyTree.Insert, xax, pNodeCat, XTVN_INSERT_AS_LAST_CHILD
    OCall pNodePrp::XPT_PropertyNode.Init, xbx, hIconMode, $OfsCStr("Mode"), \
                                           HEIGHT_LEVEL_2, DIVIDER_WIDTH, XTVNS_EXPANDED, \
                                           addr [xsi].dMode, XPT_VAR_TYPE_LIST, \
                                           $OfsCStr("Automatic", 0, "Manual", 0)


  mov pNodeCat, $New(XPT_CategoryNode)
  OCall xbx::XPropertyTree.Insert, xax, NULL, XTVN_INSERT_AS_LAST_CHILD
  OCall pNodeCat::XPT_CategoryNode.Init, xbx, hIconBehavior, $OfsCStr("Behavior"), \
                                         HEIGHT_LEVEL_1, XTVNS_EXPANDED

    mov pNodePrp, $New(XPT_PropertyNode)
    OCall xbx::XPropertyTree.Insert, xax, pNodeCat, XTVN_INSERT_AS_LAST_CHILD
    OCall pNodePrp::XPT_PropertyNode.Init, xbx, hIconRedraw, $OfsCStr("Autoredraw"), \
                                           HEIGHT_LEVEL_2, DIVIDER_WIDTH, XTVNS_EXPANDED, \
                                           addr [xsi].dAutoRedraw, XPT_VAR_TYPE_LIST, \
                                           $OfsCStr("False", 0, "True", 0)

    mov pNodePrp, $New(XPT_PropertyNode)
    OCall xbx::XPropertyTree.Insert, xax, pNodeCat, XTVN_INSERT_AS_LAST_CHILD
    OCall pNodePrp::XPT_PropertyNode.Init, xbx, hIconClip, $OfsCStr("Clip Controls"), \
                                           HEIGHT_LEVEL_2, DIVIDER_WIDTH, XTVNS_EXPANDED, \
                                           addr [xsi].dClipCtrls, XPT_VAR_TYPE_LIST, \
                                           $OfsCStr("0", 0, "1", 0, "2", 0, "3", 0)

    mov pNodePrp, $New(XPT_PropertyNode)
    OCall xbx::XPropertyTree.Insert, xax, pNodeCat, XTVN_INSERT_AS_LAST_CHILD
    OCall pNodePrp::XPT_PropertyNode.Init, xbx, hIconDrawStyle, $OfsCStr("Draw Style"), \
                                           HEIGHT_LEVEL_2, DIVIDER_WIDTH, XTVNS_EXPANDED, \
                                           addr [xsi].dDrawStyle, XPT_VAR_TYPE_LIST, \
                                           $OfsCStr("Invisible", 0, "Thin", 0, "Fat", 0)

  mov pNodeCat, $New(XPT_CategoryNode)
  OCall xbx::XPropertyTree.Insert, xax, NULL, XTVN_INSERT_AS_LAST_CHILD
  OCall pNodeCat::XPT_CategoryNode.Init, xbx, hIconPath, $OfsCStr("Paths"), \
                                         HEIGHT_LEVEL_1, XTVNS_EXPANDED
  mov xax, pNodeCat
  BitSet [xax].$Obj(XPT_PropertyNode).dState, XTVNS_DISABLED

    mov pNodePrp, $New(XPT_PropertyNode)
    OCall xbx::XPropertyTree.Insert, xax, pNodeCat, XTVN_INSERT_AS_LAST_CHILD
    OCall pNodePrp::XPT_PropertyNode.Init, xbx, hIconMain, $OfsCStr("Main directory"), \
                                           HEIGHT_LEVEL_2, DIVIDER_WIDTH, XTVNS_EXPANDED, \
                                           addr [xsi].cMainDirPath, XPT_VAR_TYPE_PATH, offset BI_Main

    mov pNodePrp, $New(XPT_PropertyNode)
    OCall xbx::XPropertyTree.Insert, xax, pNodeCat, XTVN_INSERT_AS_LAST_CHILD
    OCall pNodePrp::XPT_PropertyNode.Init, xbx, hIconConfig, $OfsCStr("Configuration file"), \
                                           HEIGHT_LEVEL_2, DIVIDER_WIDTH, XTVNS_EXPANDED, \
                                           addr [xsi].cConfigFile, XPT_VAR_TYPE_FILE, offset OFN

  invoke StrCopy, addr [xsi].cCaption,     $OfsCStr("XPropertyTree")
  invoke StrCopy, addr [xsi].cDescription, $OfsCStr("Demo application showing the use of the XPropertyTree object")

  invoke ExpandEnvironmentStrings, $OfsCStr("%OBJASM_PATH%\Projects"), \
                                   addr cBuffer, lengthof(cBuffer)
  invoke StrCopy, addr [xsi].cMainDirPath, addr cBuffer
  invoke ExpandEnvironmentStrings, $OfsCStr("%OBJASM_PATH%\Config.txt"), \
                                   addr cBuffer, lengthof(cBuffer)
  invoke StrCopy, addr [xsi].cConfigFile, addr cBuffer

  ;Initialize some structures
  m2m OFN.hInstance, hInstance, xdx
  c2m OFN.lpstrFilter, $OfsCStr("Text files (*.txt)", 0, "*.txt", 0), xax
  m2z OFN.lpstrCustomFilter
  m2z OFN.nMaxCustFilter
  mov OFN.nFilterIndex, 1
  lea xcx, [xsi].cConfigFile
  mov OFN.lpstrFile, xcx
  mov OFN.nMaxFile, lengthof $Obj(Application).cConfigFile
  m2z OFN.lpstrFileTitle
  m2z OFN.nMaxFileTitle
  invoke ExpandEnvironmentStrings, $OfsCStr("%OBJASM_PATH%"), addr cBuffer, lengthof(cBuffer)
  lea xax, cBuffer
  mov OFN.lpstrInitialDir, xax
  c2m OFN.lpstrTitle, $OfsCStr("Select a setting file..."), xax
  mov OFN.Flags, OFN_EXPLORER or OFN_EXTENSIONDIFFERENT or OFN_LONGNAMES or \
                 OFN_OVERWRITEPROMPT or OFN_HIDEREADONLY
  c2m OFN.lpstrDefExt, $OfsCStr("txt"), xax

  m2z BI_Main.pidlRoot
  c2m BI_Main.lpszTitle, $OfsCStr("Browse and select a directory..."), xax
  mov BI_Main.ulFlags, BIF_NEWDIALOGSTYLE or BIF_RETURNONLYFSDIRS

  m2z BI_Setting.pidlRoot
  c2m BI_Setting.lpszTitle, $OfsCStr("Browse and select a directory..."), xax
  mov BI_Setting.ulFlags, BIF_NEWDIALOGSTYLE or BIF_RETURNONLYFSDIRS

  m2m CC.hInstance, hInstance, xdx
  mov CC.Flags, CC_RGBINIT or CC_FULLOPEN
  m2z CC.lCustData
  m2z CC.lpfnHook
  m2z CC.lpTemplateName

  ;Fill with gray scale
  lea xdi, ColorRef
  mov CC.lpCustColors, xdi
  mov edx, 255 * 256
  .repeat
    mov eax, edx
    shr eax, 8                                          ;/256
    mov ecx, 3
    rep stosb                                           ;Store B = G = R = eax
    xor eax, eax
    stosb                                               ;Store alpha = 0
    sub edx, 4352                                       ;int(255 * 256 / 15)
  .until SIGN?
  
  
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
; Method:     Application.OnFocus
; Purpose:    Event procedure for WM_KILLFOCUS and WM_SETFOCUS messages.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Application.OnFocus,, wParam:WPARAM, lParam:LPARAM
  ;DbgText "Application.OnFocus"
  SetObject xcx
  invoke SendMessage, [xcx].XPT.hWnd, eax, wParam, lParam
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
  invoke SendMessage, [xcx].XPT.hWnd, WM_MOUSEWHEEL, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Application.OnSize, uses xsi, wParam:WPARAM, lParam:LPARAM
  local WndSize:POINT

  ;DbgText "Application.OnSize"
  SetObject xsi
  .if [xsi].XPT.hWnd != 0
    PntS2Pnt WndSize, lParam
    invoke MoveWindow, [xsi].XPT.hWnd, 0, 0, WndSize.x, WndSize.y, TRUE
    OCall [xsi].XPT::XPropertyTree.Draw
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnKeyDown
; Purpose:    Forward this message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Message return value.

Method Application.OnKeyDown,, wParam:WPARAM, lParam:LPARAM
  SetObject xcx
  invoke SendMessage, [xcx].XPT.hWnd, WM_KEYDOWN, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnKeyUp
; Purpose:    Forward this message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Message return value.

Method Application.OnKeyUp,, wParam:WPARAM, lParam:LPARAM
  SetObject xcx
  invoke SendMessage, [xcx].XPT.hWnd, WM_KEYUP, wParam, lParam
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
  m2m WC.lpfnWndProc, $MethodAddr(Application.WndProc), xdx
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xdx
  m2z WC.hbrBackground
  c2m WC.lpszMenuName, $OfsCStr("MENU_APP"), xax
  c2m WC.lpszClassName, offset cAppClassName, xax
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
;             Window handle is passed in pSelf.
; Return:     eax = Result of the message processing and depends on the message.

Method Application.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  ;DbgMessage uMsg,, "Application Messages"
  .if uMsg == WM_NCCREATE
    mov xax, lParam
    mov xsi, [xax].CREATESTRUCT.lpCreateParams
    test xsi, xsi
    jz @@DefProc                                        ;Goto handler defined in DispatchEvent
    m2m [xsi].$Obj(SdiApp).hWnd, pSelf, xax             ;pSelf = hWnd
    invoke SetWindowLongPtr, pSelf, GWLP_USERDATA, xsi
  .elseif uMsg == WM_INITDIALOG                         ;Added for Dialog applications
    mov xsi, lParam
    test xsi, xsi
    jz @@DefProc                                        ;Goto handler defined in DispatchEvent
    m2m [xsi].$Obj(SdiApp).hWnd, pSelf, xax             ;pSelf = hWnd
    invoke SetWindowLongPtr, pSelf, DWLP_USER, xsi
  .else
    invoke GetWindowLongPtr, pSelf, GWLP_USERDATA       ;If GWL_USERDATA wasn't set,
    .if eax == 0                                        ;  it returns NULL
      invoke GetWindowLongPtr, pSelf, DWLP_USER
      test xax, xax
      jz @@DefProc                                      ;Goto handler defined in DispatchEvent
    .endif
    mov xsi, xax
  .endif
  DispatchEvent <DefWindowProc, pSelf>                  ;xsi -> Object Instance
MethodEnd
