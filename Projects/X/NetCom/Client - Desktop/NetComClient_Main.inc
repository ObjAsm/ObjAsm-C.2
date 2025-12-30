; ==================================================================================================
; Title:      NetComClient_Main.inc
; Author:     G. Friedrich
; Version:    See NetComClient.asm
; Purpose:    NetCom Client Application
; ==================================================================================================


CLSSTYLE equ CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW ;Window styles

CStr szNetComClient, "OAC_NetComClient"                 ;Creates szNetComClient string in .const

; --------------------------------------------------------------------------------------------------
; Object:     SendDlg
; Purpose:    Modal dialog used to configure and control outbound network connections.
;             This dialog allows the user to specify a remote address and service,
;             initiate and terminate a TCP connection, and manage the transmission
;             of captured desktop image data to a remote endpoint.
;
;             The dialog maintains the resolved server address and active connection
;             state, enables or disables UI controls based on connection status, and
;             uses a timer event to drive periodic data transmission.
; --------------------------------------------------------------------------------------------------

Object SendDlg,, DialogModal
  VirtualMethod     CtlsEnable,     DWORD               ;Enable/disable UI controls
  RedefineMethod    CtlsGet                             ;Redefine ancestor method
  RedefineMethod    CtlsSet                             ;Redefine ancestor method
  RedefineMethod    OnInitDialog,   WPARAM, LPARAM      ;Redefine ancestor method
  RedefineMethod    OnCommand,      WPARAM, LPARAM      ;Redefine ancestor method
  VirtualEvent      OnTimer,        WM_TIMER            ;Timer event handler

  DefineVariable    ServerAddr,     NETCOMADDR, {}      ;Remote server network address
  DefineVariable    pConnection,    $ObjPtr(NetComConnection),  NULL ;Pointer to connection object
  DefineVariable    dFlags,         DWORD,      0       ;Dialog flags
ObjectEnd


; --------------------------------------------------------------------------------------------------
; Object:     NetComClient
; Purpose:    Main application object implementing a Windows SDI client using the
;             NetCom networking framework.
;
;             This object owns the NetComEngine instance, manages the application
;             window lifecycle, processes user commands, displays runtime status
;             information, and hosts the SendDlg dialog used for outbound connections.
; --------------------------------------------------------------------------------------------------

Object NetComClient, ApplicationID, SdiApp              ;Single Document Interface application
  RedefineMethod    Done                                ;Redefine base method
  RedefineMethod    Init                                ;Init method redefinition
  StaticMethod      Startup                             ;Static class startup method

  VirtualEvent      OnCommand,  WM_COMMAND              ;Command message event
  VirtualEvent      OnClose,    WM_CLOSE, WM_QUERYENDSESSION ;Close event
  VirtualEvent      OnTimer,    WM_TIMER                ;Timer event

  Embed  Client,    NetComEngine                        ;Embed NetComEngine object
  Embed  SndDlg,    SendDlg                             ;Embed SendDlg dialog
ObjectEnd


include NetComClient_Protocol.inc


.code

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Procedure:  CaptureDesktopImage
; Purpose:    Return a memory block containing the desktop image
; Arguments:  None
; Return:     xax -> Memory block, must be released using MemFree.
;             ecx = Memory block size.
; Note:       The memory layout is as follows:
;               DWORD  - Total transmission size in bytes (dMemSize)
;               BMI    - BITMAPINFO structure including RGBQUAD color entries
;               DATA   - Bitmap pixel data

CaptureDesktopImage proc uses xbx
  local hNewBmp:HBITMAP, hPrvBmp:HBITMAP, hScreenDC:HDC, hMemDC:HANDLE
  local dSizeX:DWORD, dSizeY:DWORD, BMI:BITMAPINFO, pMem:POINTER, dMemSize:DWORD

  mov hScreenDC, $invoke(GetDC, 0)                        ;Get the DC of the desktop
  mov hMemDC, $invoke(CreateCompatibleDC, hScreenDC)      ;Create memory DC compatible with desktop
  mov dSizeX, $32($invoke(GetSystemMetrics, SM_CXSCREEN)) ;Get desktop width
  mov dSizeY, $32($invoke(GetSystemMetrics, SM_CYSCREEN)) ;Get desktop height
  mov hNewBmp, $invoke(CreateCompatibleBitmap, hScreenDC, dSizeX, dSizeY) ;Create compatible bitmap
  mov hPrvBmp, $invoke(SelectObject, hMemDC, hNewBmp)     ;Select bitmap into memory DC
  invoke BitBlt, hMemDC, 0, 0, dSizeX, dSizeY, hScreenDC, 0, 0, SRCCOPY   ;Copy screen to memory DC

  ;Get the Bitmap attributes
  mov BMI.bmiHeader.biSize, sizeof(BITMAPINFOHEADER)
  m2z BMI.bmiHeader.biBitCount
  lea xbx, BMI
  invoke GetDIBits, hMemDC, hNewBmp, 0, 1, NULL, xbx, DIB_RGB_COLORS ;Fill only BITMAPINFO structure
  ;Allocate memory for bitmap bits and set 32-bit DIB properties
  mov eax, BMI.bmiHeader.biWidth
  mul BMI.bmiHeader.biHeight
  shl eax, $Log2(sizeof(RGBQUAD))
  mov BMI.bmiHeader.biSizeImage, eax
  add eax, sizeof DWORD + sizeof BMI
  mov dMemSize, eax
  MemAlloc eax
  .if xax != NULL
    mov pMem, xax
    m2m [xax], dMemSize, ecx                             ;Copy total memory size
    mov BMI.bmiHeader.biBitCount, 32
    mov BMI.bmiHeader.biCompression, BI_RGB
    mov xcx, pMem
    add xcx, sizeof DWORD
    invoke MemClone, xcx, xbx, sizeof BMI                ;Copy BITMAPINFO to memory
    mov xax, pMem
    add xax, sizeof DWORD + sizeof BMI
    ;Retrieve bitmap bits
    invoke GetDIBits, hMemDC, hNewBmp, 0, BMI.bmiHeader.biHeight, xax, xbx, DIB_RGB_COLORS
  .else
    DbgWarning "Out of Memory"                           ;Failed memory allocation
  .endif
  invoke SelectObject, hMemDC, hPrvBmp                   ;Restore previous bitmap handle
  invoke DeleteDC, hMemDC                                ;Delete memory DC
  invoke ReleaseDC, 0, hScreenDC                         ;Release screen DC
  invoke DeleteObject, hNewBmp                           ;Delete created bitmap
  mov xax, pMem
  mov ecx, dMemSize
  ret
CaptureDesktopImage endp


; ==================================================================================================
;    NetComClient implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     NetComClient.Done
; Purpose:    Cleanup before application closes.
; Arguments:  None.
; Return:     Nothing.

Method NetComClient.Done, uses xsi
  SetObject xsi
  invoke KillTimer, [xsi].hWnd, 123                      ;Stop the timer
  OCall [xsi].Client::NetComEngine.Done                  ;Call embedded engine Done
  ACall xsi.Done                                         ;Call ancestor class Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComClient.Init
; Purpose:    Initializes the SDI application object
; Arguments:  None.
; Return:     Nothing.

Method NetComClient.Init, uses xsi
  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD
  local cCaption[512]:CHR, cAddrStr[100]:CHR, dLength:DWORD

  SetObject xsi
  ACall xsi.Init                                        ;Call ancestor Init method

  mov dWndWidth, 550                                    ;Default window width
  mov dWndHeight, 350                                   ;Default window height
  mov dWndPosX, $32($invoke(CenterForm, dWndWidth, $32($invoke(GetSystemMetrics, SM_CXSCREEN))))
  sub dWndPosX, 300                                     ;Offset for demonstration
  mov dWndPosY, $32($invoke(CenterForm, dWndHeight, $32($invoke(GetSystemMetrics, SM_CYSCREEN))))

  invoke CreateWindowEx, WS_EX_LEFT or WS_EX_APPWINDOW, \
                         offset szNetComClient, offset szAppTitle, WS_OVERLAPPEDWINDOW, \
                         dWndPosX, dWndPosY, dWndWidth, dWndHeight, NULL, NULL, hInstance, xsi

  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL          ;Show the window
  invoke UpdateWindow, [xsi].hWnd                       ;Force window update

  OCall [xsi].Client::NetComEngine.Init, xsi, 3, 5, 5, MSS_ETHERNET_IPVX ;Initialize engine
  OCall $ObjTmpl(NetComClientProtocol)::NetComClientProtocol.Init, xsi, $OfsCStr("25773") ;Init protocol

  ;For this test, set ServerAddr (remote host) to LocalHostAddr
  invoke MemClone, addr [xsi].SndDlg.ServerAddr, addr [xsi].Client.LocalHostAddr, sizeof NETCOMADDR

  ;Set application caption
  mov dLength, lengthof(cAddrStr)
  lea xcx, [xsi].Client
  invoke GetNameInfo, addr [xcx].$Obj(NetComEngine).LocalHostAddr, sizeof NETCOMADDR, \
                      addr cAddrStr, lengthof cAddrStr, \
                      NULL, 0, \
                      NI_NUMERICHOST
  invoke StrECopy, addr cCaption, offset szAppTitle     ;Copy base title
  invoke StrECopy, xax, $OfsCStr(" on ")                ;Append string
  lea xdx, [xsi].Client
  invoke StrECopy, xax, [xdx].$Obj(NetComEngine).pLocalHostName ;Append hostname
  invoke StrECopy, xax, $OfsCStr(" at ")                ;Append string
  lea xdx, cAddrStr
  invoke StrCopy, xax, xdx                              ;Append IP address
  invoke SetWindowText, [xsi].hWnd, addr cCaption       ;Set window caption

  invoke SetTimer, [xsi].hWnd, 123, 500, NULL           ;Start timer
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComClient.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax: Zero if handled.

Method NetComClient.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[MAX_PATH]:CHR, Dlg:$Obj(DialogAbout), hIcon:HICON

  SetObject xsi                                         ;Bind object context
  mov xax, wParam
  .if ax == IDM_EXIT
    invoke SendMessage, [xsi].hWnd, WM_SYSCOMMAND, SC_CLOSE, NULL   ;Send close command
    xor eax, eax                                        ;Handled

  .elseif ax == IDM_SEND
    OCall [xsi].SndDlg::SendDlg.Init, xsi, [xsi].hWnd, IDD_DLG_SEND ;Init Send dialog
    OCall [xsi].SndDlg::SendDlg.Show                    ;Show dialog
    OCall [xsi].SndDlg::SendDlg.Done                    ;Cleanup dialog
    xor eax, eax                                        ;Handled

  .elseif ax == IDM_ABOUT
    New Dlg::DialogAbout                                ;Create About dialog
    mov hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))   ;Load application icon
    OCall Dlg::DialogAbout.Init, xsi, [xsi].hWnd, hIcon, offset szAboutText ;Init dialog
    OCall Dlg::DialogAbout.Show                         ;Show About dialog
    OCall Dlg::DialogAbout.Done                         ;Cleanup dialog
    invoke DestroyIcon, hIcon                           ;Free icon resource
    xor eax, eax                                        ;Handled

  .elseif ax == IDM_HELP
    invoke ExpandEnvironmentStrings, $OfsCStr("%OBJASM_PATH%\Help\ObjAsm_Reference_Volume-I.pdf"), \
                                     addr cBuffer, lengthof cBuffer     ;Resolve help path
    invoke PdfView, [xsi].hWnd, addr cBuffer, $OfsCStr("Introduction")  ;Open PDF help
    xor eax, eax                                        ;Handled

  .else
    invoke DefWindowProc, [xsi].hWnd, WM_COMMAND, wParam, lParam        ;Default processing
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComClient.OnClose
; Purpose:    Event procedure for WM_CLOSE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method NetComClient.OnClose, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi                                         ;Bind object context
  invoke MessageBox, [xsi].hWnd, $OfsCStr("Are you sure?"), $OfsCStr("Application exit"), \
                     MB_YESNO or MB_ICONQUESTION        ;Ask for confirmation
  .if eax == IDNO
    xor eax, eax                                        ;Cancel close
  .else
    invoke DefWindowProc, [xsi].hWnd, WM_CLOSE, wParam, lParam  ;Proceed with close
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComClient.OnTimer
; Purpose:    Handles WM_TIMER messages.
;             Refreshes runtime statistics in the client area, such as number of
;             connections, I/O jobs, bytes transmitted, and throughput rates.
; Arguments:  wParam: Timer identifier.
;             lParam: Unused.
; Return:     eax: Always zero (message handled).

Method NetComClient.OnTimer, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[1024]:CHR

;  DbgText "NetComClient.OnTimer"
  SetObject xsi                                         ;Bind object context
  mov xbx, $invoke(GetDC, [xsi].hWnd)                   ;Get device context
  invoke GetSysColor, COLOR_WINDOWTEXT
  invoke SetTextColor, xbx, eax                         ;Set text color

  lea xdi, cBuffer

  XPOS = 20
  YPOS = -10

  YPOS = YPOS + 30
  invoke wsprintf, xdi, $OfsCStr("#Workers = %lu         "), [xsi].Client.dWorkerCount
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax             ;Draw text

  YPOS = YPOS + 30
  invoke wsprintf, xdi, $OfsCStr("#Listeners = %lu         "), [xsi].Client.Listeners.dCount
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax             ;Draw text

  YPOS = YPOS + 20
  invoke wsprintf, xdi, $OfsCStr("#Connections = %lu       "), [xsi].Client.Connections.dCount
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax             ;Draw text

  YPOS = YPOS + 30
  invoke wsprintf, xdi, $OfsCStr("#IOJobs = %lu            "), [xsi].Client.IOJobs.dCount
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax             ;Draw text

  YPOS = YPOS + 30
  invoke wsprintf, xdi, $OfsCStr("#In Bytes = %lu          "), [xsi].Client.dBytesIn
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax             ;Draw text

  YPOS = YPOS + 20
  invoke wsprintf, xdi, $OfsCStr("#In Rate = %lu kbit/s           "), [xsi].Client.dRateIn
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax             ;Draw text

  YPOS = YPOS + 30
  invoke wsprintf, xdi, $OfsCStr("#Out Bytes = %lu          "), [xsi].Client.dBytesOut
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax             ;Draw text

  YPOS = YPOS + 20
  invoke wsprintf, xdi, $OfsCStr("#Out Rate = %lu kbit/s           "), [xsi].Client.dRateOut
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax             ;Draw text

  invoke ReleaseDC, [xsi].hWnd, xbx                     ;Release device context
  xor eax, eax                                          ;Return zero
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComClient.Startup
; Purpose:    Registers the object class with the OS.
; Arguments:  None.
; Return:     Nothing.

Method NetComClient.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CLSSTYLE
  m2m WC.lpfnWndProc, $MethodAddr(NetComClient.WndProc), xax  ;Set window procedure
  mov WC.cbClsExtra, 0
  mov WC.cbWndExtra, 0
  m2m WC.hInstance, hInstance, xax
  mov WC.hbrBackground, COLOR_WINDOW + 1
  c2m WC.lpszMenuName, $OfsCStr("MENU_APP"), xax        ;Set menu
  c2m WC.lpszClassName, offset szNetComClient, xax      ;Set class name
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))  ;Load icon
  mov WC.hCursor, $invoke(LoadCursor, NULL, IDC_ARROW)  ;Load cursor
  mov WC.hIconSm, 0                                     ;No small icon

  invoke RegisterClassEx, addr WC                       ;Register window class
MethodEnd

; ==================================================================================================
;    SendDlg implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     SendDlg.CtlsEnable
; Purpose:    Enables or disables the dialog controls.
; Arguments:  Arg1: TRUE = enabled, FALSE = disabled.
; Return:     Nothing.

Method SendDlg.CtlsEnable, uses xbx xsi, dEnable:DWORD
  SetObject xsi                                         ;Bind object context

  ;Handle inner controls - enable/disable them
  invoke GetDlgItem, [xsi].hWnd, IDC_EDT_ADDRESS        ;Get address edit control
  invoke EnableWindow, xax, dEnable                     ;Enable/disable control
  invoke GetDlgItem, [xsi].hWnd, IDC_EDT_PORT           ;Get port edit control
  invoke EnableWindow, xax, dEnable                     ;Enable/disable control
  invoke GetDlgItem, [xsi].hWnd, IDC_UDN_PORT           ;Get port Up/Down control
  invoke EnableWindow, xax, dEnable                     ;Enable/disable control

  ;Handle buttons - switch between connect and disconnect
  .if dEnable != FALSE
    mov ebx, IDC_BTN_CONNECT                            ;Enable Connect button
    mov edx, IDC_BTN_DISCONNECT                         ;Disable Disconnect button
  .else
    mov ebx, IDC_BTN_DISCONNECT                         ;Enable Disconnect button
    mov edx, IDC_BTN_CONNECT                            ;Disable Connect button
  .endif
  invoke GetDlgItem, [xsi].hWnd, edx
  invoke EnableWindow, xax, FALSE                       ;Disable inactive button
  invoke GetDlgItem, [xsi].hWnd, ebx
  invoke EnableWindow, xax, TRUE                        ;Enable active button
  invoke SendMessage, [xsi].hWnd, DM_SETDEFID, ebx, 0   ;Set default dialog button
  invoke GetDlgItem, [xsi].hWnd, ebx
  invoke SetFocus, xax                                  ;Move keyboard focus
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:       SendDlg.CtlsGet
; Purpose:      Gets the controls in this dialog window.
; Arguments:    None.
; Return:       eax: TRUE if the dialog can be closed, otherwise FALSE.

Method SendDlg.CtlsGet, uses xsi
  local cAddress[100]:CHR, cServiceName[100]:CHR, Hints:ADDRINFOT, pResult:PADDRINFOT

  SetObject xsi                                         ;Bind object context
  invoke GetDlgItemText, [xsi].hWnd, IDC_EDT_ADDRESS, addr cAddress, lengthof cAddress
  invoke GetDlgItemText, [xsi].hWnd, IDC_EDT_PORT, addr cServiceName, lengthof cServiceName

  mov Hints.ai_flags, AI_NUMERICHOST                    ;Numeric host only
  mov Hints.ai_family, AF_INETX                         ;IPv4/IPv6
  mov Hints.ai_socktype, SOCK_STREAM                    ;TCP socket
  mov Hints.ai_protocol, IPPROTO_TCP
  mov Hints.ai_addrlen, 0
  mov Hints.ai_canonname, NULL
  mov Hints.ai_addr, NULL
  mov Hints.ai_next, NULL
  invoke GetAddrInfo, addr cAddress, addr cServiceName, addr Hints, addr pResult  ;Resolve address
  mov xax, pResult
  lea xcx, [xsi].ServerAddr
  invoke MemClone, xcx, [xax].ADDRINFOT.ai_addr, DWORD ptr [xax].ADDRINFOT.ai_addrlen ;Copy address
  invoke FreeAddrInfo, pResult                          ;Free memory

  invoke StrDispose, $ObjTmpl(NetComClientProtocol).pServiceName  ;Dispose previous string
  mov $ObjTmpl(NetComClientProtocol).pServiceName, $invoke(StrNew, addr cServiceName) ;Store string

  xor eax, eax
  inc eax                                               ;Return TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SendDlg.CtlsSet
; Purpose:    Sets the controls in this dialog window.
; Arguments:  None.
; Return:     Nothing.
; Note:       dServerAddr and dServerAddr have to convert back to little endian.

Method SendDlg.CtlsSet, uses xbx xsi
  local cAddrStr[100]:CHR

  SetObject xsi                                         ;Bind object context
  invoke GetNameInfo, addr [xsi].ServerAddr, sizeof NETCOMADDR, \
                      addr cAddrStr, lengthof cAddrStr, \
                      NULL, 0, \
                      NI_NUMERICHOST                    ;Get numeric address string
  ;Set address, port and up/down controls
  invoke SetDlgItemText, [xsi].hWnd, IDC_EDT_ADDRESS, addr cAddrStr
  invoke SetDlgItemText, [xsi].hWnd, IDC_EDT_PORT, $ObjTmpl(NetComClientProtocol).pServiceName

  mov xbx, $invoke(GetDlgItem, [xsi].hWnd, IDC_UDN_PORT)
  invoke SendMessage, xbx, UDM_SETBASE, 10, 0
  invoke SendMessage, xbx, UDM_SETRANGE32, 1, 0FFFFh
  invoke dec2dword, $ObjTmpl(NetComClientProtocol).pServiceName
  invoke SendMessage, xbx, UDM_SETPOS32, 0, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SendDlg.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method SendDlg.OnInitDialog, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi                                         ;Bind object context
  ACall xsi.OnInitDialog, wParam, lParam                ;Call base implementation
  invoke SetTimer, [xsi].hWnd, 123, 500, NULL           ;Set refresh timer to 0.5s
  xor eax, eax                                          ;Return zero
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SendDlg.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method SendDlg.OnCommand, uses xdi xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi                                         ;Bind object context
  mov xdi, [xsi].pOwner                                 ;Parent object
  LoWord wParam                                         ;Get command ID
  .if eax == IDC_BTN_CONNECT
    .if $OCall(xsi.CtlsGet) != FALSE                    ;Get input values
      OCall [xdi].$Obj(NetComClient).Client::NetComEngine.ConnectTo, \
                                                          offset $ObjTmpl(NetComClientProtocol), \
                                                          addr [xsi].ServerAddr ;Connect
      mov [xsi].pConnection, xax                        ;Store connection
      OCall xsi.CtlsEnable, FALSE                       ;Disable controls
    .endif
    xor eax, eax                                        ;Handled

  .elseif eax == IDC_BTN_DISCONNECT
    .if [xsi].pConnection != NULL
      OCall [xsi].pConnection::NetComConnection.Disconnect, SD_SEND  ;Disconnect gracefully
      invoke Sleep, 1000
      OCall [xsi].pConnection::NetComConnection.QueueFree            ;Free connection object
      mov [xsi].pConnection, NULL
    .endif
    OCall xsi.CtlsEnable, TRUE                          ;Enable controls
    xor eax, eax                                        ;Handled

  .elseif eax == IDCANCEL
    .if [xsi].pConnection != NULL
      OCall [xsi].pConnection::NetComConnection.Disconnect, SD_SEND  ;Be gentle and disconnect :-)
      invoke Sleep, 1000
      OCall [xsi].pConnection::NetComConnection.QueueFree            ;Free connection object
      mov [xsi].pConnection, NULL
    .endif
    OCall xsi.DestroyDialog, wParam                     ;Close dialog
    xor eax, eax                                        ;Handled

  .else
    xor eax, eax
    inc eax                                             ;Not handled
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SendDlg.OnTimer
; Purpose:    Display status information on the window client area.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method SendDlg.OnTimer, uses xdi xsi, wParam:WPARAM, lParam:LPARAM
  local pMem:POINTER, dMemSize:DWORD

  DbgText "SendDlg.OnTimer"
  SetObject xsi                                         ;Bind object context
  mov xdi, [xsi].pConnection                            ;Get connection
  .if xdi != NULL
    .if [xdi].$Obj(NetComConnection).dErrorCode == OBJ_OK
      mov xcx, [xsi].pOwner                             ;Owner object
      invoke CaptureDesktopImage                        ;Capture desktop
      mov pMem, xax                                     ;Pointer to image
      mov dMemSize, ecx                                 ;Image size
      OCall xdi::NetComConnection.QueueWrite, pMem, dMemSize  ;Send image
      MemFree pMem                                      ;Free memory
    .else
      .ifBitClr [xdi].$Obj(NetComConnection).dFlags, NCC_CLOSED
        OCall xdi::NetComConnection.Disconnect, SD_SEND ;Disconnect
        invoke Sleep, 1000
        OCall xdi::NetComConnection.QueueFree           ;Free connection
        mov [xsi].pConnection, NULL
      .endif
    .endif
  .endif
  xor eax, eax                                          ;Return zero
MethodEnd

endif
