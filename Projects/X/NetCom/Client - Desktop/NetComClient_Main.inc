; ==================================================================================================
; Title:      NetComClient.inc
; Author:     G. Friedrich
; Version:    See NetComClient.asm
; Purpose:    NetCom Client Application.
; ==================================================================================================


CLSSTYLE equ CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW; or CS_DROPSHADOW

CStr szNetComClient, "OAC_NetComClient"                 ;Creates szNetComClient string in .const

Object SendDlg,, DialogModal
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    OnInitDialog,   WPARAM, LPARAM
  RedefineMethod    OnCommand,      WPARAM, LPARAM
  VirtualEvent      OnTimer,        WM_TIMER

  DefineVariable    ServerAddr,     NETCOMADDR, {}      ;Local Host
  DefineVariable    pConnection,    $ObjPtr(NetComConnection),  NULL
  DefineVariable    dFlags,         DWORD,      0
ObjectEnd


Object NetComClient, MySdiAppID, SdiApp                 ;Single Document Interface App.
  RedefineMethod    Done
  RedefineMethod    Init                                ;Init method redefinition
  StaticMethod      Startup

  VirtualEvent      OnCommand,  WM_COMMAND
  VirtualEvent      OnClose,    WM_CLOSE, WM_QUERYENDSESSION
  VirtualEvent      OnTimer,    WM_TIMER

  Embed  Client,    NetComEngine
  Embed  SndDlg,    SendDlg
ObjectEnd


include NetComClient_Protocol.inc


.code

if IMPLEMENT

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  CaptureDesktopImage
; Purpose:    Return a memory block containing the image of the Desktop.
; Arguments:  None.
; Return:     xax -> Memory block. Must be released using MemFree
;             ecx = Memory block size.
; Note:       Memory layout:
;               DWORD  - BITMAPINFO -  RGBQUADs
;             dMemSize -     BMI    -  [pMem]

CaptureDesktopImage proc uses xbx
  local hNewBmp:HBITMAP, hPrvBmp:HBITMAP, hScreenDC:HDC, hMemDC:HANDLE
  local dSizeX:DWORD, dSizeY:DWORD, BMI:BITMAPINFO, pMem:POINTER, dMemSize:DWORD

  mov hScreenDC, $invoke(GetDC, 0)                        ;Get the DC of desktop
  mov hMemDC, $invoke(CreateCompatibleDC, hScreenDC)      ;Create a DC compatible with hScreenDC
  mov dSizeX, $32($invoke(GetSystemMetrics, SM_CXSCREEN)) ;Get the width and height of the desktop
  mov dSizeY, $32($invoke(GetSystemMetrics, SM_CYSCREEN))
  mov hNewBmp, $invoke(CreateCompatibleBitmap, hScreenDC, dSizeX, dSizeY) ;Create a compatible bmp
  mov hPrvBmp, $invoke(SelectObject, hMemDC, hNewBmp)
  invoke BitBlt, hMemDC, 0, 0, dSizeX, dSizeY, hScreenDC, 0, 0, SRCCOPY   ;Copy screen to the MemDC

  ;Get the Bitmap attributes
  mov BMI.bmiHeader.biSize, sizeof(BITMAPINFOHEADER)
  m2z BMI.bmiHeader.biBitCount
  lea xbx, BMI
  invoke GetDIBits, hMemDC, hNewBmp, 0, 1, NULL, xbx, DIB_RGB_COLORS ;Fill only BITMAPINFO
  ;Get memory to get bitmap bits and set DIB properties we want (32 bit per pixel)
  mov eax, BMI.bmiHeader.biWidth
  mul BMI.bmiHeader.biHeight
  shl eax, $Log2(sizeof(RGBQUAD))
  mov BMI.bmiHeader.biSizeImage, eax
  add eax, sizeof DWORD + sizeof BMI
  mov dMemSize, eax
  MemAlloc eax
  .if xax != NULL
    mov pMem, xax
    m2m [xax], dMemSize, ecx
    mov BMI.bmiHeader.biBitCount, 32
    mov BMI.bmiHeader.biCompression, BI_RGB
    mov xcx, pMem
    add xcx, sizeof DWORD
    invoke MemClone, xcx, xbx, sizeof BMI
    mov xax, pMem
    add xax, sizeof DWORD + sizeof BMI
    invoke GetDIBits, hMemDC, hNewBmp, 0, BMI.bmiHeader.biHeight, xax, xbx, DIB_RGB_COLORS
  .else
    DbgWarning "Out of Memory"
  .endif
  invoke SelectObject, hMemDC, hPrvBmp                  ;Return the previous HANDLE
  invoke DeleteDC, hMemDC
  invoke ReleaseDC, 0, hScreenDC
  invoke DeleteObject, hNewBmp
  mov xax, pMem
  mov ecx, dMemSize
  ret
CaptureDesktopImage endp


; ==================================================================================================
;    NetComClient implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     NetComClient.Done
; Purpose:
; Arguments:  None.
; Return:

Method NetComClient.Done, uses xsi
  SetObject xsi
  invoke KillTimer, [xsi].hWnd, 123
  OCall [xsi].Client::NetComEngine.Done
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     NetComClient.Init
; Purpose:    Initalizes the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method NetComClient.Init, uses xsi
  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD
  local cCaption[512]:CHR, cAddrStr[100]:CHR, dLength:DWORD

  SetObject xsi
  ACall xsi.Init

  mov dWndWidth, 500                                    ;Default creation width
  mov dWndHeight, 350                                   ;Default creation height
  mov dWndPosX, $32($invoke(CenterForm, dWndWidth, $32($invoke(GetSystemMetrics, SM_CXSCREEN))))
  sub dWndPosX, 300
  mov dWndPosY, $32($invoke(CenterForm, dWndHeight, $32($invoke(GetSystemMetrics, SM_CYSCREEN))))

  invoke CreateWindowEx, WS_EX_LEFT or WS_EX_APPWINDOW, \
                         offset szNetComClient, offset szAppTitle, WS_OVERLAPPEDWINDOW, \
                         dWndPosX, dWndPosY, dWndWidth, dWndHeight, NULL, NULL, hInstance, xsi

  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL          ;Show the window
  invoke UpdateWindow, [xsi].hWnd                       ;Update if necessary

  OCall [xsi].Client::NetComEngine.Init, xsi, 3, 5, 5, MSS_ETHERNET_IPVX
  OCall $ObjTmpl(NetComClientProtocol)::NetComClientProtocol.Init, xsi, $OfsCStr("25773")

  ;For this test, we set the Server address (Remote Host) to the Local Host address.
  invoke MemClone, addr [xsi].SndDlg.ServerAddr, addr [xsi].Client.LocalHostAddr, sizeof NETCOMADDR

  ;Set application caption
  mov dLength, lengthof(cAddrStr)
  lea xcx, [xsi].Client
  invoke GetNameInfo, addr [xcx].$Obj(NetComEngine).LocalHostAddr, sizeof NETCOMADDR, \
                      addr cAddrStr, lengthof cAddrStr, \
                      NULL, 0, \
                      NI_NUMERICHOST
  invoke StrECopy, addr cCaption, offset szAppTitle
  invoke StrECopy, xax, $OfsCStr(" - ")
  lea xdx, [xsi].Client
  invoke StrECopy, xax, [xdx].$Obj(NetComEngine).pLocalHostName
  invoke StrECopy, xax, $OfsCStr(" at ")
  lea xdx, cAddrStr
  invoke StrCopy, xax, xdx
  invoke SetWindowText, [xsi].hWnd, addr cCaption

  invoke SetTimer, [xsi].hWnd, 123, 100, NULL
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     NetComClient.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax: Zero if handled.

Method NetComClient.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[MAX_PATH]:CHR, Dlg:$Obj(DialogAbout), hIcon:HICON

  SetObject xsi
  mov xax, wParam
  .if ax == IDM_EXIT
    invoke SendMessage, [xsi].hWnd, WM_SYSCOMMAND, SC_CLOSE, NULL
    xor eax, eax

  .elseif ax == IDM_SEND
    OCall [xsi].SndDlg::SendDlg.Init, xsi, [xsi].hWnd, IDD_DLG_SEND
    OCall [xsi].SndDlg::SendDlg.Show
    OCall [xsi].SndDlg::SendDlg.Done
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
                                     addr cBuffer, lengthof cBuffer
    invoke PdfView, [xsi].hWnd, addr cBuffer, $OfsCStr("Introduction")
    xor eax, eax

  .else
    invoke DefWindowProc, [xsi].hWnd, WM_COMMAND, wParam, lParam
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     NetComClient.OnClose
; Purpose:    Event procedure for WM_CLOSE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Zero if handled.

Method NetComClient.OnClose, uses xsi, wParam:WPARAM, lParam:LPARAM
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
; Method:     NetComClient.OnTimer
; Purpose:    Display status information on the window client area.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Zero if handled.

Method NetComClient.OnTimer, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[1024]:CHR

  SetObject xsi
  mov xbx, $invoke(GetDC, [xsi].hWnd)
  invoke GetSysColor, COLOR_WINDOWTEXT
  invoke SetTextColor, xbx, eax
;  invoke SetBkMode, xbx, TRANSPARENT

  lea xdi, cBuffer

  XPOS = 20
  YPOS = -10

  YPOS = YPOS + 30
  invoke wsprintf, xdi, $OfsCStr("#Workers = %lu         "), [xsi].Client.dWorkerCount
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax

  YPOS = YPOS + 30
  invoke wsprintf, xdi, $OfsCStr("#Listeners = %lu         "), [xsi].Client.Listeners.dCount
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax

  YPOS = YPOS + 20
  invoke wsprintf, xdi, $OfsCStr("#Connections = %lu       "), [xsi].Client.Connections.dCount
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax

  YPOS = YPOS + 30
  invoke wsprintf, xdi, $OfsCStr("#IOJobs = %lu            "), [xsi].Client.IOJobs.dCount
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax

  YPOS = YPOS + 30
  invoke wsprintf, xdi, $OfsCStr("#In Bytes = %lu          "), [xsi].Client.dBytesIn
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax

  YPOS = YPOS + 20
  invoke wsprintf, xdi, $OfsCStr("#In Rate = %lu kbit/s           "), [xsi].Client.dRateIn
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax

  YPOS = YPOS + 30
  invoke wsprintf, xdi, $OfsCStr("#Out Bytes = %lu          "), [xsi].Client.dBytesOut
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax

  YPOS = YPOS + 20
  invoke wsprintf, xdi, $OfsCStr("#Out Rate = %lu kbit/s           "), [xsi].Client.dRateOut
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax

  invoke ReleaseDC, [xsi].hWnd, xbx
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     NetComClient.Startup
; Purpose:    Registers the object class with the OS.
; Arguments:  None.
; Return:     Nothing.

Method NetComClient.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CLSSTYLE
  m2m WC.lpfnWndProc, $MethodAddr(NetComClient.WndProc), xax
  mov WC.cbClsExtra, 0
  mov WC.cbWndExtra, 0
  m2m WC.hInstance, hInstance, xax
  mov WC.hbrBackground, COLOR_WINDOW + 1
  c2m WC.lpszMenuName, $OfsCStr("MENU_APP"), xax
  c2m WC.lpszClassName, offset szNetComClient, xax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
  mov WC.hCursor, $invoke(LoadCursor, NULL, IDC_ARROW)
  mov WC.hIconSm, 0

  invoke RegisterClassEx, addr WC
MethodEnd


; ==================================================================================================
;    SendDlg implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:       SendDlg.CtlsGet
; Purpose:      Gets the controls in this dialog window.
; Arguments:    None.
; Return:       eax: TRUE if the dialog can be closed, otherwise FALSE.

Method SendDlg.CtlsGet, uses xsi
  local cAddress[100]:CHR, cServiceName[100]:CHR, Hints:ADDRINFOT, pResult:PADDRINFOT

  SetObject xsi
  invoke GetDlgItemText, [xsi].hWnd, IDC_EDT_ADDRESS, addr cAddress, lengthof cAddress
  invoke GetDlgItemText, [xsi].hWnd, IDC_EDT_PORT, addr cServiceName, lengthof cServiceName

  mov Hints.ai_flags, AI_NUMERICHOST
  mov Hints.ai_family, AF_INETX
  mov Hints.ai_socktype, SOCK_STREAM
  mov Hints.ai_protocol, IPPROTO_TCP
  mov Hints.ai_addrlen, 0
  mov Hints.ai_canonname, NULL
  mov Hints.ai_addr, NULL
  mov Hints.ai_next, NULL
  invoke GetAddrInfo, addr cAddress, addr cServiceName, addr Hints, addr pResult
  mov xax, pResult
  invoke MemClone, addr [xsi].ServerAddr, [xax].ADDRINFOT.ai_addr, \
                   DWORD ptr [xax].ADDRINFOT.ai_addrlen
  invoke FreeAddrInfo, pResult

  invoke StrDispose, $ObjTmpl(NetComClientProtocol).pServiceName
  mov $ObjTmpl(NetComClientProtocol).pServiceName, $invoke(StrNew, addr cServiceName)

  xor eax, eax
  inc eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SendDlg.CtlsSet
; Purpose:    Sets the controls in this dialog window.
; Arguments:  None.
; Return:     Nothing.
; Note:       dServerAddr and dServerAddr have to convert back to little endian.

Method SendDlg.CtlsSet, uses xsi
  local cAddrStr[100]:CHR

  SetObject xsi
  invoke GetNameInfo, addr [xsi].ServerAddr, sizeof NETCOMADDR, \
                      addr cAddrStr, lengthof cAddrStr, \
                      NULL, 0, \
                      NI_NUMERICHOST
  invoke SetDlgItemText, [xsi].hWnd, IDC_EDT_ADDRESS, addr cAddrStr
  invoke SetDlgItemText, [xsi].hWnd, IDC_EDT_PORT, $ObjTmpl(NetComClientProtocol).pServiceName
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SendDlg.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Zero.

Method SendDlg.OnInitDialog, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  ACall xsi.OnInitDialog, wParam, lParam
  invoke SetTimer, [xsi].hWnd, 123, 50, NULL
  xor eax, eax                                          ;Return zero
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SendDlg.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Zero if handled.

Method SendDlg.OnCommand, uses xdi xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov xdi, [xsi].pOwner
  LoWord wParam
  .if eax == IDC_BTN_CONNECT
    .if $OCall(xsi.CtlsGet) != FALSE
      OCall [xdi].$Obj(NetComClient).Client::NetComEngine.ConnectTo, \
                                                          offset $ObjTmpl(NetComClientProtocol), \
                                                          addr [xsi].ServerAddr
      mov [xsi].pConnection, xax
    .endif
    xor eax, eax

  .elseif eax == IDC_BTN_DISCONNECT
    .if [xsi].pConnection != NULL
      OCall [xsi].pConnection::NetComConnection.Disconnect, SD_SEND
      OCall [xsi].pConnection::NetComConnection.QueueFree
      mov [xsi].pConnection, NULL
    .endif

  .elseif eax == IDCANCEL
    .if [xsi].pConnection != NULL
      OCall [xsi].pConnection::NetComConnection.Disconnect, SD_SEND   ;Be gentle and disconnect :-)
      OCall [xsi].pConnection::NetComConnection.QueueFree
      mov [xsi].pConnection, NULL
    .endif
    OCall xsi.DestroyDialog, wParam
    xor eax, eax

  .else
    xor eax, eax
    inc eax

  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SendDlg.OnTimer
; Purpose:    Display status information on the window client area.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Zero if handled.

Method SendDlg.OnTimer, uses xdi xsi, wParam:WPARAM, lParam:LPARAM
  local pMem:POINTER, dMemSize:DWORD

  SetObject xsi
  mov xdi, [xsi].pConnection
  .if xdi != NULL
    .if [xdi].$Obj(NetComConnection).dErrorCode == OBJ_OK
      mov xcx, [xsi].pOwner
      invoke CaptureDesktopImage
      mov pMem, xax
      mov dMemSize, ecx
      OCall xdi::NetComConnection.QueueWrite, pMem, dMemSize
      MemFree pMem
    .else
      .ifBitClr [xdi].$Obj(NetComConnection).dFlags, NCC_CLOSED
        OCall xdi::NetComConnection.Disconnect, SD_SEND
        OCall xdi::NetComConnection.QueueFree
        mov [xsi].pConnection, NULL
      .endif
    .endif
  .endif
  xor eax, eax
MethodEnd

endif
