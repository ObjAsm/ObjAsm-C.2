; ==================================================================================================
; Title:      NetComServer_Main.inc
; Author:     G. Friedrich
; Version:    See NetComServer.asm
; Purpose:    NetCom Server application.
; ==================================================================================================


CLSSTYLE equ CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW ;Window styles

CStr szNetComServer, "OAC_NetComServer"                 ;Creates szNetComServer string in .const


; --------------------------------------------------------------------------------------------------
; Object:     NetComServer
; Purpose:    Main application object implementing a Windows SDI server using the
;             NetCom networking framework.
;
;             This object owns the NetComEngine instance, manages the application
;             window lifecycle, processes user commands, displays real-time statistics,
;             and handles incoming client connections.
;
; Connection Handling:
;   - Each accepted connection is wrapped in a NetComConnection object.
;   - Incoming client data is queued and processed asynchronously by worker threads.
;   - The server maintains a listener array for multiple endpoints.
;   - Disconnects are performed gracefully using the SD_SEND flag to flush outbound data.
;   - Connection objects are freed after disconnection to release resources.
;
; Transmission Protocol:
;   - Each data block from a client starts with a DWORD indicating the block size.
;   - Payload is processed according to the server protocol defined in NetComServerProtocol.

Object NetComServer, ApplicationID, SdiApp              ;Single Document Interface App.
  RedefineMethod    Done
  RedefineMethod    Init                                ;Init method redefinition
  StaticMethod      Startup

  VirtualEvent      OnCommand,  WM_COMMAND              ;Command message event
  VirtualEvent      OnClose,    WM_CLOSE, WM_QUERYENDSESSION ;Close event
  VirtualEvent      OnTimer,    WM_TIMER                ;Timer event

  Embed  Server,    NetComEngine                        ;Embed NetComEngine object

ObjectEnd                                               ;Ends object definition


include NetComServer_Protocol.inc


.code
; ==================================================================================================
;    NetComServer implementation
; ==================================================================================================

if IMPLEMENT

TimerID equ 5361783                                     ;Unique timer ID for status updates

; --------------------------------------------------------------------------------------------------
; Method:    NetComServer.Done
; Purpose:   Cleanup before application closes.
; Arguments: None.
; Return:    Nothing.

Method NetComServer.Done, uses xsi
  SetObject xsi
  invoke KillTimer, [xsi].hWnd, TimerID                 ;Stop the timer
  OCall [xsi].Server::NetComEngine.Done                 ;Call embedded engine Done
  ACall xsi.Done                                        ;Call ancestor class Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    NetComServer.Init
; Purpose:   Initializes the SDI application object
; Arguments: None.
; Return:    Nothing.

Method NetComServer.Init, uses xsi
  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD
  local cCaption[512]:CHR, cAddrStr[100]:CHR, dLength:DWORD
;  local HostileHostAddr:NETCOMADDR

  SetObject xsi
  ACall xsi.Init                                        ;Call ancestor Init

  mov dWndWidth, 550                                    ;Default window width
  mov dWndHeight, 350                                   ;Default window height
  mov dWndPosX, $32($invoke(CenterForm, dWndWidth, $32($invoke(GetSystemMetrics, SM_CXSCREEN))))
  add dWndPosX, 300                                     ;Offset for demonstration
  mov dWndPosY, $32($invoke(CenterForm, dWndHeight, $32($invoke(GetSystemMetrics, SM_CYSCREEN))))

  invoke CreateWindowEx, WS_EX_LEFT or WS_EX_APPWINDOW, \
                         offset szNetComServer, offset szAppTitle, WS_OVERLAPPEDWINDOW, \
                         dWndPosX, dWndPosY, dWndWidth, dWndHeight, NULL, NULL, hInstance, xsi

  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL          ;Show the window
  invoke UpdateWindow, [xsi].hWnd                       ;Force window update

  OCall [xsi].Server::NetComEngine.Init, xsi, 3, 50, 1000, MSS_ETHERNET_IPVX ;Initialize engine
  .if eax == 0
    OCall $ObjTmpl(NetComServerProtocol)::NetComServerProtocol.Init, xsi, $OfsCStr("25773")
    .if eax == 0
      OCall [xsi].Server::NetComEngine.Listen, offset $ObjTmpl(NetComServerProtocol)
      DbgText "NetCom Server is running..."
    .else
      DbgWarning "NetComSvrProtocol initialization failed"
    .endif
  .else
    DbgWarning "NetComEngine initialization failed"
  .endif

  ;Set application caption including host and listening info
  mov dLength, lengthof(cAddrStr)
  lea xcx, [xsi].Server
  invoke GetNameInfo, addr [xcx].$Obj(NetComEngine).LocalHostAddr, sizeof NETCOMADDR, \
                      addr cAddrStr, lengthof cAddrStr, \
                      NULL, 0, \
                      NI_NUMERICHOST
  invoke StrECopy, addr cCaption, offset szAppTitle
  invoke StrECopy, xax, $OfsCStr(" on ")
  lea xdx, [xsi].Server
  invoke StrECopy, xax, [xdx].$Obj(NetComEngine).pLocalHostName
  invoke StrECopy, xax, $OfsCStr(", listening at ")
  lea xdx, cAddrStr
  invoke StrECopy, xax, xdx
  invoke StrECopy, xax, $OfsCStr(":")
  invoke StrCopy, xax, $ObjTmpl(NetComServerProtocol).pServiceName
  invoke SetWindowText, [xsi].hWnd, addr cCaption       ;Set window caption

  ;Start status update timer
  invoke SetTimer, [xsi].hWnd, TimerID, 500, NULL
  DbgLine
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    NetComServer.OnCommand
; Purpose:   Event procedure for WM_COMMAND message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    eax = Zero if handled.

Method NetComServer.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[MAX_PATH]:CHR, Dlg:$Obj(DialogAbout), hIcon:HICON

  SetObject xsi
  mov xax, wParam
  .if ax == IDM_EXIT
    invoke SendMessage, [xsi].hWnd, WM_SYSCOMMAND, SC_CLOSE, NULL ;Send close command
    xor eax, eax

  .elseif ax == IDM_ABOUT
    New Dlg::DialogAbout                                ;Create About dialog
    mov hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP")) ;Load icon
    OCall Dlg::DialogAbout.Init, xsi, [xsi].hWnd, hIcon, offset szAboutText ;Init dialog
    OCall Dlg::DialogAbout.Show                         ;Show About dialog
    OCall Dlg::DialogAbout.Done                         ;Cleanup dialog
    invoke DestroyIcon, hIcon                           ;Release icon resource
    xor eax, eax

  .elseif ax == IDM_HELP
    invoke ExpandEnvironmentStrings, $OfsCStr("%OBJASM_PATH%\Help\ObjAsm_Reference_Volume-I.pdf"), \
                                     addr cBuffer, lengthof(cBuffer) ;Resolve help path
    invoke PdfView, [xsi].hWnd, addr cBuffer, NULL      ;Open PDF help
    xor eax, eax

  .else
    invoke DefWindowProc, [xsi].hWnd, WM_COMMAND, wParam, lParam ;Default processing
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    NetComServer.OnClose
; Purpose:   Event procedure for WM_CLOSE message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    eax = Zero if handled.

Method NetComServer.OnClose, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke MessageBox, [xsi].hWnd, $OfsCStr("Are you sure ?"), $OfsCStr("Application exit"), \
                     MB_YESNO or MB_ICONQUESTION        ;Confirm close
  .if eax == IDNO
    xor eax, eax                                        ;Cancel close
  .else
    invoke DefWindowProc, [xsi].hWnd, WM_CLOSE, wParam, lParam ;Proceed with close
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    NetComServer.OnTimer
; Purpose:   Display runtime status information on the window client area.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    eax = Zero if handled.

Method NetComServer.OnTimer, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[1024]:CHR

  SetObject xsi
  mov xbx, $invoke(GetDC, [xsi].hWnd)                   ;Get device context
  invoke GetSysColor, COLOR_WINDOWTEXT
  invoke SetTextColor, xbx, eax                         ;Set text color

  lea xdi, cBuffer

  XPOS = 20
  YPOS = -10

  YPOS = YPOS + 30
  invoke wsprintf, xdi, $OfsCStr("#Workers = %lu         "), [xsi].Server.dWorkerCount
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax

  YPOS = YPOS + 30
  invoke wsprintf, xdi, $OfsCStr("#Listeners = %lu         "), [xsi].Server.Listeners.dCount
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax

  YPOS = YPOS + 20
  invoke wsprintf, xdi, $OfsCStr("#Connections = %lu       "), [xsi].Server.Connections.dCount
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax

  YPOS = YPOS + 30
  invoke wsprintf, xdi, $OfsCStr("#IOJobs = %lu            "), [xsi].Server.IOJobs.dCount
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax

  YPOS = YPOS + 30
  invoke wsprintf, xdi, $OfsCStr("#In Bytes = %lu          "), [xsi].Server.dBytesIn
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax

  YPOS = YPOS + 20
  invoke wsprintf, xdi, $OfsCStr("#In Rate = %lu kbit/s           "), [xsi].Server.dRateIn
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax

  YPOS = YPOS + 30
  invoke wsprintf, xdi, $OfsCStr("#Out Bytes = %lu          "), [xsi].Server.dBytesOut
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax

  YPOS = YPOS + 20
  invoke wsprintf, xdi, $OfsCStr("#Out Rate = %lu kbit/s           "), [xsi].Server.dRateOut
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax

  invoke ReleaseDC, [xsi].hWnd, xbx                     ;Release device context
  xor eax, eax                                          ;Return zero
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    NetComServer.Startup
; Purpose:   Registers the object class with the OS.
; Arguments: None.
; Return:    Nothing.

Method NetComServer.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CLSSTYLE
  m2m WC.lpfnWndProc, $MethodAddr(NetComServer.WndProc), xax ;Set window procedure
  and WC.cbClsExtra, 0
  and WC.cbWndExtra, 0
  m2m WC.hInstance, hInstance, xax
  mov WC.hbrBackground, COLOR_WINDOW + 1
  c2m WC.lpszMenuName, $OfsCStr("MENU_APP"), xax
  c2m WC.lpszClassName, offset szNetComServer, xax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
  mov WC.hCursor, $invoke(LoadCursor, NULL, IDC_ARROW)
  and WC.hIconSm, 0

  invoke RegisterClassEx, addr WC                       ;Register window class
MethodEnd

endif
