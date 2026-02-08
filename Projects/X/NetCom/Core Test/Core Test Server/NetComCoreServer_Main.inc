; ==================================================================================================
; Title:      NetComCoreServer.inc
; Author:     G. Friedrich
; Version:    See NetComCoreServer.asm
; Purpose:    NetCom Server Application.
; ==================================================================================================


;If you use a browser, use the following address to connect to the server: http://127.0.0.1:25773

CLSSTYLE equ CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW

CStr szNetComCoreServer, "OAC_NetComCoreServer"         ;Creates szNetComCoreServer string in .const


Object NetComCoreServer, ApplicationID, SdiApp          ;Single Document Interface App
  RedefineMethod    Done                                ;Finalize application object
  RedefineMethod    Init                                ;Initialize application object
  StaticMethod      Startup                             ;Registers object class with OS

  VirtualEvent      OnCommand,  WM_COMMAND              ;WM_COMMAND handler (menu and controls)
;  VirtualEvent      OnClose,    WM_CLOSE, WM_QUERYENDSESSION  ;WM_CLOSE handler
  VirtualEvent      OnTimer,    WM_TIMER                ;WM_TIMER handler for status updates

  Embed  Server,    NetComEngine                        ;Embedded NetCom engine instance

ObjectEnd


include NetComCoreServer_Protocol.inc                   ;Include server-specific protocol


.code
; ==================================================================================================
;    NetComCoreServer implementation
; ==================================================================================================

if IMPLEMENT

TimerID equ 5361783                                     ;Timer ID for periodic status updates

; --------------------------------------------------------------------------------------------------
; Method:    NetComCoreServer.Done
; Purpose:   Finalize the application object.
; Arguments: None.
; Return:    Nothing.

Method NetComCoreServer.Done, uses xsi
  SetObject xsi                                         ;Bind object context
  invoke KillTimer, [xsi].hWnd, TimerID                 ;Stop status update timer
  OCall [xsi].Server::NetComEngine.Done                 ;Shutdown NetCom engine
  ACall xsi.Done                                        ;Call ancestor Done method
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    NetComCoreServer.Init
; Purpose:   Initialize the SDI application object.
; Arguments: None.
; Return:    Nothing.

Method NetComCoreServer.Init, uses xsi
  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD
  local cCaption[512]:CHR, cPortStr[100]:CHR, dLength:DWORD

  SetObject xsi                                         ;Bind object context
  ACall xsi.Init                                        ;Call ancestor Init method

  mov dWndWidth, 550                                    ;Default window width
  mov dWndHeight, 350                                   ;Default window height
  mov dWndPosX, $32($invoke(CenterForm, dWndWidth, $32($invoke(GetSystemMetrics, SM_CXSCREEN))))
  add dWndPosX, 450                                     ;Offset to adjust window placement
  mov dWndPosY, $32($invoke(CenterForm, dWndHeight, $32($invoke(GetSystemMetrics, SM_CYSCREEN))))

  ;Create main window
  invoke CreateWindowEx, WS_EX_LEFT or WS_EX_APPWINDOW, \
                         offset szNetComCoreServer, offset szAppTitle, WS_OVERLAPPEDWINDOW, \
                         dWndPosX, dWndPosY, dWndWidth, dWndHeight, NULL, NULL, hInstance, xsi

  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL          ;Show application window
  invoke UpdateWindow, [xsi].hWnd                       ;Update window client area

  ;Initialize NetCom engine
  OCall [xsi].Server::NetComEngine.Init, xsi, offset $ObjTmpl(NetComSupervisor), \
                                              50, 1000, MSS_ETHERNET_IPVX
  .if eax == 0
    ;Initialize server protocol
    OCall $ObjTmpl(NetComCoreServerProtocol)::NetComCoreServerProtocol.Init, xsi
    .if eax == 0
      ;Start listening for connections
      OCall [xsi].Server::NetComEngine.StartListening, 3, addr $ObjTmpl(NetComCoreServerProtocol)
      DbgText "Server is running"                       ;Debug message: server started
    .else
      DbgWarning "NetComSvrProtocol initialization failed" ;Warn if protocol init failed
    .endif
  .else
    DbgWarning "NetComEngine initialization failed"     ;Warn if engine init failed
  .endif

  ;Set application caption including host and listening info
  invoke htons, $ObjTmpl(NetComCoreServerProtocol).ListeningAddr.wPort
  invoke udword2dec, addr cPortStr, eax
  invoke StrECopy, addr cCaption, offset szAppTitle
  invoke StrECopy, xax, $OfsCStr(" on ")
  invoke StrECopy, xax, [xsi].Server.pLocalHostName
  invoke StrECopy, xax, $OfsCStr(", listening at port ")
  invoke StrCopy, xax, addr cPortStr
  invoke SetWindowText, [xsi].hWnd, addr cCaption       ;Set window caption

  DbgLine                                               ;Insert debug line for readability

  invoke SetTimer, [xsi].hWnd, TimerID, 100, NULL       ;Start timer for periodic status updates
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    NetComCoreServer.OnCommand
; Purpose:   Event procedure for WM_COMMAND message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    eax = Zero if handled.

Method NetComCoreServer.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[MAX_PATH]:CHR, Dlg:$Obj(DialogAbout), hIcon:HICON

  SetObject xsi                                         ;Bind object context
  mov xax, wParam                                       ;Extract command ID
  .if ax == IDM_EXIT
    invoke SendMessage, [xsi].hWnd, WM_SYSCOMMAND, SC_CLOSE, NULL ;Close application
    xor eax, eax                                        ;Indicate handled

  .elseif ax == IDM_ABOUT
    New Dlg::DialogAbout                                ;Create About dialog
    mov hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP")) ;Load application icon
    OCall Dlg::DialogAbout.Init, xsi, [xsi].hWnd, hIcon, offset szAboutText ;Init dialog
    OCall Dlg::DialogAbout.Show                         ;Show dialog
    OCall Dlg::DialogAbout.Done                         ;Release dialog resources
    invoke DestroyIcon, hIcon                           ;Free icon
    xor eax, eax                                        ;Indicate handled

  .elseif ax == IDM_HELP
    invoke ExpandEnvironmentStrings, $OfsCStr("%OBJASM_PATH%\Help\ObjAsm_Reference_Volume-I.pdf"), \
                                     addr cBuffer, lengthof(cBuffer)  ;Resolve PDF path
    invoke PdfView, [xsi].hWnd, addr cBuffer, NULL      ;Display help PDF
    xor eax, eax                                        ;Indicate handled

  .else
    invoke DefWindowProc, [xsi].hWnd, WM_COMMAND, wParam, lParam  ;Default processing
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    NetComCoreServer.OnClose
; Purpose:   Event procedure for WM_CLOSE message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    eax = Zero if handled.

Method NetComCoreServer.OnClose, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi                                         ;Bind object context
  invoke MessageBox, [xsi].hWnd, $OfsCStr("Are you sure?"), $OfsCStr("Application exit"), \
                     MB_YESNO or MB_ICONQUESTION        ;Prompt user to confirm exit
  .if eax == IDNO
    xor eax, eax                                        ;Cancel close, indicate handled
  .else
    invoke DefWindowProc, [xsi].hWnd, WM_CLOSE, wParam, lParam  ;Proceed with default close
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    NetComCoreServer.OnTimer
; Purpose:   Event procedure for WM_TIMER message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    eax = Zero if handled.

Method NetComCoreServer.OnTimer, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[1024]:CHR                               ;Local string buffer for status output

  SetObject xsi                                         ;Bind object context
  mov xbx, $invoke(GetDC, [xsi].hWnd)                   ;Get device context
  invoke GetSysColor, COLOR_WINDOWTEXT                  ;Retrieve default text color
  invoke SetTextColor, xbx, eax                         ;Set text color

  lea xdi, cBuffer                                      ;xdi -> cBuffer

  XPOS = 20                                             ;X offset for text output
  YPOS = -10                                            ;Initial Y position

  ;Output server statistics line by line
  YPOS = YPOS + 30
  invoke wsprintf, xdi, $OfsCStr("#Workers = %lu         "), [xsi].Server.dWorkerCount
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax

  YPOS = YPOS + 30
  invoke wsprintf, xdi, $OfsCStr("#Listeners = %lu         "), [xsi].Server.Listeners.dCount
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax

  YPOS = YPOS + 20
  invoke wsprintf, xdi, $OfsCStr("#Connections = %lu       "), [xsi].Server.ConnectionPool.dCount
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax

  YPOS = YPOS + 30
  invoke wsprintf, xdi, $OfsCStr("#IOJobs = %lu            "), [xsi].Server.IOSockJobPool.dCount
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
  xor eax, eax                                          ;Return zero to indicate handled
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    NetComCoreServer.Startup
; Purpose:   Registers the object class with the OS.
; Arguments: None.
; Return:    Nothing.

.code
Method NetComCoreServer.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX                      ;Structure size
  mov WC.style, CLSSTYLE                                ;Window class style
  m2m WC.lpfnWndProc, $MethodAddr(NetComCoreServer.WndProc), xax ;Window procedure
  and WC.cbClsExtra, 0                                  ;No extra class bytes
  and WC.cbWndExtra, 0                                  ;No extra window bytes
  m2m WC.hInstance, hInstance, xax                      ;Application instance
  mov WC.hbrBackground, COLOR_WINDOW + 1                ;Default window background
  c2m WC.lpszMenuName, $OfsCStr("MENU_APP"), xax        ;Menu resource
  c2m WC.lpszClassName, offset szNetComCoreServer, xax  ;Window class name
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP")) ;Load main icon
  mov WC.hCursor, $invoke(LoadCursor, NULL, IDC_ARROW)  ;Set arrow cursor
  and WC.hIconSm, 0                                     ;No small icon

  invoke RegisterClassEx, addr WC                       ;Register window class
MethodEnd

endif
