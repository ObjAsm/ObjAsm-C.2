; ==================================================================================================
; Title:      IcmpApp_Main.inc
; Author:     G. Friedrich
; Version:    C.2.0
; Purpose:    ObjAsm IcmpApp.
; Notes:      Version C.2.0, December 2022
;               - First release.
; ==================================================================================================


CLSSTYLE equ CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW; or CS_DROPSHADOW

CStr szApplication, "Application"                       ;Creates szApplication string in .const


Object Application, ApplicationID, SdiApp                  ;Single Document Interface App.
  RedefineMethod    Init                                ;Init method redefinition
  StaticMethod      Startup

  VirtualEvent      OnCommand,  WM_COMMAND
  VirtualEvent      OnClose,    WM_CLOSE, WM_QUERYENDSESSION
  VirtualEvent      OnPaint,    WM_PAINT

  DefineVariable    pDestStr,   PSTRINGA,     NULL
  DefineVariable    dDestType,  DWORD,        DSTTYPE_NONE

  Embed   IcmpMgr,  IcmpManager
ObjectEnd                                               ;Ends object definition


.code
; ==================================================================================================
;    Application implementation
; ==================================================================================================

PING_WINSOCK_INIT_FAILED equ  1

; --------------------------------------------------------------------------------------------------
; Method:     Application.Done
; Purpose:    Finalizes the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Done, uses xsi
  SetObject xsi
  OCall [xsi].IcmpMgr::IcmpManager.Done
  invoke StrDisposeA, [xsi].pDestStr
  ACall xsi.Done
  invoke WSACleanup                                     ;Shutdown WinSock
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.Init
; Purpose:    Initialize the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Init, uses xbx xsi
  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD
  local WsaData:WSADATA

  SetObject xsi
  ACall xsi.Init
  mov dWndWidth, 500                                    ;Default creation width
  mov dWndHeight, 350                                   ;Default creation height

  mov dWndPosX, $32($invoke(CenterForm, dWndWidth,  $32($invoke(GetSystemMetrics, SM_CXSCREEN))))
  mov dWndPosY, $32($invoke(CenterForm, dWndHeight, $32($invoke(GetSystemMetrics, SM_CYSCREEN))))

  invoke CreateWindowEx, WS_EX_LEFT or WS_EX_APPWINDOW, \
                         offset szApplication, offset szAppTitle, WS_OVERLAPPEDWINDOW, \
                         dWndPosX, dWndPosY, dWndWidth, dWndHeight, NULL, NULL, hInstance, pSelf

  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL          ;Show the window
  invoke UpdateWindow, [xsi].hWnd                       ;Update if necessary

  mov [xsi].pDestStr, $invoke(StrNew, $OfsCStrA("www.google.com"))
  mov [xsi].dDestType, DSTTYPE_URL


  invoke WSAStartup, 0202h, addr WsaData
  .if eax != 0
    OCall xsi.ErrorReport, NULL, PING_WINSOCK_INIT_FAILED
    DbgSockError "Failed to start WinSock 2.2"
  .else
    OCall [xsi].IcmpMgr::IcmpManager.Init, xsi
    mov xbx, $invoke(GetMenu, [xsi].hWnd)
    invoke EnableMenuItem, xbx, IDM_DESTINATION, MF_BYCOMMAND or MF_ENABLED
    invoke DrawMenuBar, [xsi].hWnd
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

.data
align ALIGN_DATA
DlgChildrenInfo label DL_HEADER
DL_HEADER     {DLF_LOAD_MIN or DLF_LOAD_MAX_Y or DLF_LIMIT_MINMAX or DLF_ADD_GRIPPER, {}, {600}}
DL_CHILD_INFO {{100, 100, 000, 000}}      ;IDOK
DL_CHILD_INFO {{000, 000, 000, 000}}      ;IDC_RBN_IPV4
DL_CHILD_INFO {{000, 000, 000, 000}}      ;IDC_RBN_IPV6
DL_CHILD_INFO {{000, 000, 000, 000}}      ;IDC_RBN_URL
DL_CHILD_INFO {{000, 000, 000, 000}}      ;IDC_STC_DEST
DL_CHILD_INFO {{000, 000, 100, 000}}      ;IDC_EDT_DESTINATION
DL_CHILD_INFO {{100, 100, 000, 000}}      ;IDCANCEL
DL_CHILD_INFO {{000, 100, 100, 000}}      ;IDC_GRP

Method Application.OnCommand, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[MAX_PATH]:CHR, Dlg:$Obj(DialogAbout), hIcon:HICON, DstDlg:$Obj(DstDialog)

  SetObject xsi
  mov xax, wParam
  .if ax == IDM_EXIT
    invoke SendMessage, [xsi].hWnd, WM_SYSCOMMAND, SC_CLOSE, NULL
    xor eax, eax

  .elseif ax == IDM_PING
    OCall [xsi].IcmpMgr::IcmpManager.Ping

  .elseif ax == IDM_TRACE
    OCall [xsi].IcmpMgr::IcmpManager.Trace

  .elseif ax == IDM_DESTINATION
    @@:
    New DstDlg::DstDialog
    OCall DstDlg::DstDialog.Init, xsi, [xsi].hWnd, addr [xsi].pDestStr, addr [xsi].dDestType
    c2m DstDlg.pDynamicLayout, offset DlgChildrenInfo, xcx
    OCall DstDlg::DstDialog.Show
    mov ebx, eax
    OCall DstDlg::DstDialog.Done
    .if ebx == IDOK
      mov xbx, $invoke(GetMenu, [xsi].hWnd)
      .if [xsi].dDestType == DSTTYPE_NONE
        xor eax, eax
      .elseif [xsi].dDestType == DSTTYPE_IPV4
        OCall [xsi].IcmpMgr::IcmpManager.SetDstFromIPv4, [xsi].pDestStr
      .elseif [xsi].dDestType == DSTTYPE_IPV6
;        OCall [xsi].IcmpMgr::IcmpManager.SetDstFromIPv6, [xsi].pDestStr
        xor eax, eax
      .elseif [xsi].dDestType == DSTTYPE_URL
        OCall [xsi].IcmpMgr::IcmpManager.SetDstFromURL, [xsi].pDestStr
      .endif

      .if eax == 0
        invoke EnableMenuItem, xbx, IDM_PING, MF_BYCOMMAND or MF_DISABLED
        invoke EnableMenuItem, xbx, IDM_TRACE, MF_BYCOMMAND or MF_DISABLED
        invoke DrawMenuBar, [xsi].hWnd
        invoke MsgBox, [xsi].hWnd, offset cErrDestMsg, offset cErrDestCpt, \
                       MB_RETRYCANCEL or MB_ICONWARNING
        cmp eax, IDRETRY
        jz @B
      .else
        invoke EnableMenuItem, xbx, IDM_PING, MF_BYCOMMAND or MF_ENABLED
        invoke EnableMenuItem, xbx, IDM_TRACE, MF_BYCOMMAND or MF_ENABLED
        invoke DrawMenuBar, [xsi].hWnd
      .endif
    .endif

    xor eax, eax

  .elseif ax == IDM_ABOUT
    New Dlg::DialogAbout
    mov hIcon, $invoke(LoadIcon, hInstance, offset szIcoName)
    OCall Dlg::DialogAbout.Init, xsi, [xsi].hWnd, hIcon, offset szAboutText
    OCall Dlg::DialogAbout.Show
    OCall Dlg::DialogAbout.Done
    invoke DestroyIcon, hIcon
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

; --------------------------------------------------------------------------------------------------
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

; --------------------------------------------------------------------------------------------------
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
  invoke DrawEdge, hDC, addr Rct, EDGE_SUNKEN, BF_RECT

  invoke EndPaint, [xsi].hWnd, addr PS
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.Startup
; Purpose:    Register the Application window class with the operating system.
; Arguments:  None.
; Return:     Nothing.

Method Application.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof(WNDCLASSEX)
  mov WC.style, CLSSTYLE
  m2m WC.lpfnWndProc, $MethodAddr(Application.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  invoke LoadBitmap, hInstance, $OfsCStr("BMP_BACKGROUND")
  mov WC.hbrBackground, $invoke(CreatePatternBrush, xax)
  c2m WC.lpszMenuName, $OfsCStr("MENU_APP"), rax
  c2m WC.lpszClassName, offset szApplication, rax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, offset szIcoName)
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd
