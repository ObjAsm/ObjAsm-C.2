; ==================================================================================================
; Title:      NetComCoreClient_Main.inc
; Author:     G. Friedrich
; Version:    See NetComCoreClient.asm
; Purpose:    NetCom Client Application.
; ==================================================================================================


CLSSTYLE equ CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW ;Window styles

CStr szNetComCoreClient, "OAC_NetComCoreClient"         ;Creates szNetComCoreClient string in .const

BUFFERSIZE  equ   2048

DEFAULT_SERVER_LISTENING_PORT equ $htons(25773)

; --------------------------------------------------------------------------------------------------
; Object:     SendDlg
; Purpose:    Modal dialog used to configure and control outbound connections and
;             application-level message transmission.
;
;             This dialog allows the user to:
;               - Specify remote host address and port
;               - Select number of parallel connections
;               - Enter an arbitrary text payload
;               - Define the number of transmission repetitions
;               - Establish, send data over, and terminate connections
;
;             Active connections are stored in a Collection object for simplified
;             iteration and cleanup.

Object SendDlg,, DialogModal
  VirtualMethod     CtlsEnable,     DWORD               ;Enable/disable UI controls
  RedefineMethod    CtlsGet                             ;Read dialog input controls
  RedefineMethod    CtlsSet                             ;Initialize dialog controls
  RedefineMethod    Done                                ;Cleanup dialog resources
  RedefineMethod    Init,           POINTER, HWND       ;Initialize dialog instance
  RedefineMethod    OnInitDialog,   WPARAM, LPARAM      ;Dialog initialization handler
  RedefineMethod    OnCommand,      WPARAM, LPARAM      ;Command event handler
  VirtualMethod     UpdateDataGrp

  DefineVariable    dComboIndex,    DWORD,      0       ;Last Selected ComboServerAddr index
  DefineVariable    dConnections,   DWORD,      1       ;Number of parallel connections
  DefineVariable    dRepetitions,   DWORD,      1       ;Number of send repetitions
  DefineVariable    cText,          CHRA,       BUFFERSIZE dup(0) ;Payload text buffer

;  Embed   ActiveConns,    Collection                    ;Holds all active NetComConnection objects
ObjectEnd

; --------------------------------------------------------------------------------------------------
; Object:     NetComCoreClient
; Purpose:    Main application object implementing a Windows SDI client using the
;             NetCom networking framework.
;
;             Responsibilities:
;               - Application window creation and lifecycle management
;               - NetComEngine initialization and shutdown
;               - Processing of menu commands and timers
;               - Hosting the SendDlg dialog

Object NetComCoreClient, ApplicationID, SdiApp          ;Single Document Interface application
  RedefineMethod    Done                                ;Cleanup before exit
  RedefineMethod    Init                                ;Application initialization
  StaticMethod      Startup                             ;Class registration

  VirtualEvent      OnCommand,  WM_COMMAND              ;Menu command handler
;  VirtualEvent      OnClose,    WM_CLOSE, WM_QUERYENDSESSION ;Close handler
  VirtualEvent      OnTimer,    WM_TIMER                ;Status refresh timer

  Embed  Client,    NetComEngine                        ;Embedded NetCom engine
  Embed  SndDlg,    SendDlg                             ;Embedded Send dialog
ObjectEnd


include NetComCoreClient_Protocol.inc


.code

if IMPLEMENT

TimerID equ 5361783                                     ;Unique timer ID for status updates

.const

; --------------------------------------------------------------------------------------------------
; Default payload text transmitted to the remote endpoint.
; This text is copied into the SendDlg payload buffer during initialization and
; can be edited by the user at runtime.
; --------------------------------------------------------------------------------------------------

bPayload db "Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod ",
            "tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At ",
            "vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, ",
            "no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit ",
            "amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut ",
            "labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam ",
            "et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata ",
            "sanctus est Lorem ipsum dolor sit amet."
.code

; ==================================================================================================
;    NetComCoreClient implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     NetComCoreClient.Done
; Purpose:    Cleanup before application termination.
;             Stops the status timer and shuts down the NetCom engine.
; Arguments:  None.
; Return:     Nothing.

Method NetComCoreClient.Done, uses xsi
  SetObject xsi
  invoke KillTimer, [xsi].hWnd, TimerID
  OCall [xsi].Client::NetComEngine.Done
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComCoreClient.Init
; Purpose:    Initializes the SDI application object, creates the main window,
;             initializes the NetCom engine and protocol, and sets default values.
; Arguments:  None.
; Return:     Nothing.

Method NetComCoreClient.Init, uses xsi
  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD
  local cCaption[512]:CHR, cAddrStr[100]:CHR, dLength:DWORD

  SetObject xsi
  ACall xsi.Init

  mov dWndWidth, 550                                    ;Default creation width
  mov dWndHeight, 350                                   ;Default creation height
  mov dWndPosX, $32($invoke(CenterForm, dWndWidth, $32($invoke(GetSystemMetrics, SM_CXSCREEN))))
  sub dWndPosX, 450
  mov dWndPosY, $32($invoke(CenterForm, dWndHeight, $32($invoke(GetSystemMetrics, SM_CYSCREEN))))

  invoke CreateWindowEx, WS_EX_LEFT or WS_EX_APPWINDOW, \
                         offset szNetComCoreClient, offset szAppTitle, WS_OVERLAPPEDWINDOW, \
                         dWndPosX, dWndPosY, dWndWidth, dWndHeight, NULL, NULL, hInstance, xsi

  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL          ;Show the window
  invoke UpdateWindow, [xsi].hWnd                       ;Update if necessary

  OCall [xsi].Client::NetComEngine.Init, xsi, offset $ObjTmpl(NetComSupervisor), \
                                              5, 5, MSS_ETHERNET_IPVX
  OCall $ObjTmpl(NetComCoreClientProtocol)::NetComCoreClientProtocol.Init, xsi

  ;Set the transmitted text
  lea xdx, [xsi].SndDlg
  invoke MemClone, addr [xdx].$Obj(SendDlg).cText, offset bPayload, sizeof bPayload

  invoke SetWindowText, [xsi].hWnd, offset szAppTitle

  invoke SetTimer, [xsi].hWnd, TimerID, 500, NULL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComCoreClient.OnCommand
; Purpose:    Handles WM_COMMAND messages triggered by menu selections.
;             Processes standard commands such as Exit, Send, About, and Help.
; Arguments:  wParam: First message parameter (command identifier).
;             lParam: Second message parameter.
; Return:     eax = Zero if the message was handled, non-zero otherwise.

Method NetComCoreClient.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[MAX_PATH]:CHR, Dlg:$Obj(DialogAbout), hIcon:HICON

  SetObject xsi
  mov xax, wParam
  .if ax == IDM_EXIT
    invoke SendMessage, [xsi].hWnd, WM_SYSCOMMAND, SC_CLOSE, NULL
    xor eax, eax

  .elseif ax == IDM_SEND
    OCall [xsi].SndDlg::SendDlg.Init, xsi, [xsi].hWnd
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
                                     addr cBuffer, lengthof(cBuffer)
    invoke PdfView, [xsi].hWnd, addr cBuffer, $OfsCStr("Introduction")
    xor eax, eax

  .else
    invoke DefWindowProc, [xsi].hWnd, WM_COMMAND, wParam, lParam
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComCoreClient.OnClose
; Purpose:    Handles WM_CLOSE messages.
;             Prompts the user to confirm application exit.
; Arguments:  wParam: First message parameter.
;             lParam: Second message parameter.
; Return:     eax = Zero if the close request is cancelled, otherwise passes to default handler.

Method NetComCoreClient.OnClose, uses xsi, wParam:WPARAM, lParam:LPARAM
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
; Method:     NetComCoreClient.OnTimer
; Purpose:    Handles WM_TIMER messages.
;             Refreshes runtime statistics in the client area, such as number of
;             connections, I/O jobs, bytes transmitted, and throughput rates.
; Arguments:  wParam: Timer identifier.
;             lParam: Unused.
; Return:     eax: Always zero (message handled).

Method NetComCoreClient.OnTimer, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[1024]:CHR

;  DbgText "NetComCoreClient.OnTimer"
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
  invoke wsprintf, xdi, $OfsCStr("#Connections = %lu       "), [xsi].Client.ConnectionPool.dCount
  invoke StrLength, xdi
  invoke TextOut, xbx, XPOS, YPOS, xdi, eax             ;Draw text

  YPOS = YPOS + 30
  invoke wsprintf, xdi, $OfsCStr("#IOJobs = %lu            "), [xsi].Client.IOSockJobPool.dCount
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
; Method:     NetComCoreClient.Startup
; Purpose:    Registers the window class for the SDI application with the operating system.
;             This must be called prior to creating the main application window.
; Arguments:  None.
; Return:     Nothing.

Method NetComCoreClient.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CLSSTYLE
  m2m WC.lpfnWndProc, $MethodAddr(NetComCoreClient.WndProc), xax
  mov WC.cbClsExtra, 0
  mov WC.cbWndExtra, 0
  m2m WC.hInstance, hInstance, xax
  mov WC.hbrBackground, COLOR_WINDOW + 1
  c2m WC.lpszMenuName, $OfsCStr("MENU_APP"), xax
  c2m WC.lpszClassName, offset szNetComCoreClient, xax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
  mov WC.hCursor, $invoke(LoadCursor, NULL, IDC_ARROW)
  mov WC.hIconSm, 0

  invoke RegisterClassEx, addr WC                       ;Register the class
MethodEnd


; ==================================================================================================
;    SendDlg implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     SendDlg.CtlsEnable
; Purpose:    Enables or disables the dialog controls.
; Arguments:  Arg1: TRUE = enabled, FALSE = disabled.
; Return:     Nothing.

Method SendDlg.CtlsEnable, uses xbx xdi xsi, dEnable:DWORD
  SetObject xsi                                         ;Bind object context

  ;Handle inner controls - enable/disable them
  invoke GetDlgItem, [xsi].hWnd, IDC_CBO_ADDR           ;Get address edit control
  invoke EnableWindow, xax, dEnable                     ;Enable/disable control

  invoke GetDlgItem, [xsi].hWnd, IDC_EDT_PORT           ;Get port edit control
  invoke EnableWindow, xax, dEnable                     ;Enable/disable control
  invoke GetDlgItem, [xsi].hWnd, IDC_UDN_PORT           ;Get port Up/Down control
  invoke EnableWindow, xax, dEnable                     ;Enable/disable control

  invoke GetDlgItem, [xsi].hWnd, IDC_EDT_CONNECTIONS    ;Get connections edit control
  invoke EnableWindow, xax, dEnable                     ;Enable/disable control
  invoke GetDlgItem, [xsi].hWnd, IDC_UDN_CONNECTIONS    ;Get connections Up/Down control
  invoke EnableWindow, xax, dEnable                     ;Enable/disable control

  invoke GetDlgItem, [xsi].hWnd, IDC_EDT_DATA           ;Get data edit control
  invoke EnableWindow, xax, dEnable                     ;Enable/disable control

  invoke GetDlgItem, [xsi].hWnd, IDC_EDT_REPETITIONS    ;Get repetitions edit control
  invoke EnableWindow, xax, dEnable                     ;Enable/disable control
  invoke GetDlgItem, [xsi].hWnd, IDC_UDN_REPETITIONS    ;Get repetitions Up/Down control
  invoke EnableWindow, xax, dEnable                     ;Enable/disable control

  invoke GetDlgItem, [xsi].hWnd, IDC_BTN_SEND           ;Get Send button control
  xor edx, edx
  .if dEnable == FALSE
    inc edx
  .endif
  invoke EnableWindow, xax, edx                         ;Enable/disable control

  ;Handle buttons - switch between connect and disconnect
  ;The send button is managed by the client protocol
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
; Method:     SendDlg.CtlsGet
; Purpose:    Read current values from the dialog controls and update the object state.
;             Resolves the server address, stores the payload text, and updates the connection
;             and repetition counts.
; Arguments:  None.
; Return:     TRUE if all values are valid, otherwise FALSE.

Method SendDlg.CtlsGet, uses xdi xsi
  local dRetValue:DWORD, cAddress[100]:CHR, Hints:ADDRINFOT, pResult:PADDRINFOT
  local hComboServerAddr:HANDLE, cServiceName[100]:CHR

  SetObject xsi                                         ;Bind object context
  mov dRetValue, FALSE

  mov hComboServerAddr, $invoke(GetDlgItem, [xsi].hWnd, IDC_CBO_ADDR)
  lea xdi, cAddress
  invoke GetWindowText, hComboServerAddr, xdi, lengthof cAddress
  invoke StrLRTrim, xdi, xdi
  
  invoke SendMessage, hComboServerAddr, CB_GETCURSEL, 0, 0
  mov [xsi].dComboIndex, eax
  
  lea xdi, cServiceName
  invoke GetDlgItemText, [xsi].hWnd, IDC_EDT_PORT, xdi, lengthof cServiceName
  invoke StrLRTrim, xdi, xdi
  invoke dec2dword, xdi
  .if SDWORD ptr eax <= 0 || SDWORD ptr eax > 0FFFFh
    invoke MessageBox, [xsi].hWnd, $OfsCStr("Incorrect server port number"), \
                       addr cError, MB_OK or MB_ICONERROR
    xor eax, eax
    ExitMethod
  .endif

  mov [xsi].dConnections, $32($invoke(GetDlgItemInt, [xsi].hWnd, IDC_EDT_CONNECTIONS, NULL, FALSE))
  invoke GetDlgItemTextA, [xsi].hWnd, IDC_EDT_DATA, addr [xsi].cText, BUFFERSIZE
  mov [xsi].dRepetitions, $32($invoke(GetDlgItemInt, [xsi].hWnd, IDC_EDT_REPETITIONS, NULL, FALSE))

  mov Hints.ai_flags, AI_NUMERICHOST                    ;Numeric host only
  mov Hints.ai_family, AF_INETX                         ;IPv4/IPv6
  mov Hints.ai_socktype, SOCK_STREAM                    ;TCP socket
  mov Hints.ai_protocol, IPPROTO_TCP
  mov Hints.ai_addrlen, 0
  mov Hints.ai_canonname, NULL
  mov Hints.ai_addr, NULL
  mov Hints.ai_next, NULL
  invoke GetAddrInfo, addr cAddress, addr cServiceName, addr Hints, addr pResult  ;Resolve address
  .if eax != 0
    mov dRetValue, eax
    invoke MessageBox, [xsi].hWnd, $OfsCStr("Incorrect server address or port number"), \
                       addr cError, MB_OK or MB_ICONERROR     ;Show error
    jmp @@Exit
  .endif  
  mov xax, pResult
  lea xcx, $ObjTmpl(NetComCoreClientProtocol).ServerRemoteAddr
  invoke MemClone, xcx, [xax].ADDRINFOT.ai_addr, DWORD ptr [xax].ADDRINFOT.ai_addrlen ;Copy address
  invoke FreeAddrInfo, pResult                          ;Free memory
  mov dRetValue, TRUE

@@Exit:
  mov eax, dRetValue                                    ;Return TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SendDlg.CtlsSet
; Purpose:    Initialize the dialog controls with values from the object state.
; Arguments:  None.
; Return:     Nothing.

Method SendDlg.CtlsSet, uses xbx xsi
  local cBuffer[100]:CHR, dBufferLength:DWORD, pMibTable:PMIB_IPNET_TABLE2
  local hComboServerAddr:HANDLE, dSize:DWORD, dPort:DWORD, pAdapter:POINTER, cPortStr[20]:CHR

  SetObject xsi

  ;Set "Server address" combobox
  mov hComboServerAddr, $invoke(GetDlgItem, [xsi].hWnd, IDC_CBO_ADDR)
  invoke SendMessage, hComboServerAddr, CB_RESETCONTENT, 0, 0

  ;Add local adapter IPs
  invoke GetAdaptersAddresses, AF_INETX, 0, NULL, NULL, addr dSize   ;Get buffer size
  MemAlloc dSize                                        ;Allocate buffer
  .if xax != NULL
    mov pAdapter, xax
    invoke GetAdaptersAddresses, AF_INETX, 0, NULL, pAdapter, addr dSize  ;Get adapter data
    .if eax == ERROR_SUCCESS
      ;Iterate adapters
      mov xbx, pAdapter
      .while xbx != NULL
        mov xdi, [xbx].IP_ADAPTER_ADDRESSES.FirstUnicastAddress
        ;Iterate unicast addresses
        .while xdi != NULL
          invoke getnameinfo, [xdi].IP_ADAPTER_UNICAST_ADDRESS.Address.lpSockaddr, \
                              [xdi].IP_ADAPTER_UNICAST_ADDRESS.Address.iSockaddrLength, \
                              addr cBuffer, sizeof cBuffer, \
                              NULL, 0, \
                              NI_NUMERICHOST
          .break .if eax != ERROR_SUCCESS
          invoke SendMessage, hComboServerAddr, CB_ADDSTRING, 0, addr cBuffer
          mov xdi, [xdi].IP_ADAPTER_UNICAST_ADDRESS.Next  ;Next unicast address
        .endw
        mov xbx, [xbx].IP_ADAPTER_ADDRESSES.Next        ;Next adapter
      .endw
    .endif
    MemFree pAdapter                                    ;Free allocated memory buffer
  .endif

  ;Add known neighbor IPs
  invoke GetIpNetTable2, AF_INETX, addr pMibTable
  .if eax == NO_ERROR
    mov xdi, pMibTable
    mov ebx, [xdi].MIB_IPNET_TABLE2.NumEntries
    lea xdi, [xdi].MIB_IPNET_TABLE2.Table
    test ebx, ebx
    .while !ZERO?
      mov dBufferLength, lengthof(cBuffer)
      invoke WSAAddressToString, addr [xdi].MIB_IPNET_ROW2.Address, sizeof SOCKADDR_INET, \
                                 NULL, addr cBuffer, addr dBufferLength
      .if eax == NO_ERROR
        invoke SendMessage, hComboServerAddr, CB_ADDSTRING, 0, addr cBuffer
      .endif
      add xdi, sizeof(MIB_IPNET_ROW2)
      dec ebx
    .endw
    invoke FreeMibTable, pMibTable
  .endif

  invoke SendMessage, hComboServerAddr, CB_SETCURSEL, [xsi].dComboIndex, 0

  ;Set port and up/down control
  invoke htons, $ObjTmpl(NetComCoreClientProtocol).ServerRemoteAddr.wPort
  mov dPort, eax
  invoke udword2dec, addr cPortStr, dPort
  invoke SetDlgItemText, [xsi].hWnd, IDC_EDT_PORT, addr cPortStr

  mov xbx, $invoke(GetDlgItem, [xsi].hWnd, IDC_UDN_PORT)
  invoke SendMessage, xbx, UDM_SETBASE, 10, 0
  invoke SendMessage, xbx, UDM_SETRANGE32, 1, 0FFFFh
  invoke SendMessage, xbx, UDM_SETPOS32, 0, dPort

  ;Set number of connections and up/down control
  invoke SetDlgItemInt, [xsi].hWnd, IDC_EDT_CONNECTIONS, [xsi].dConnections, FALSE
  mov xbx, $invoke(GetDlgItem, [xsi].hWnd, IDC_UDN_CONNECTIONS)
  invoke SendMessage, xbx, UDM_SETBASE, 10, 0
  invoke SendMessage, xbx, UDM_SETRANGE32, 1, 07FFFFFFFh
  invoke SendMessage, xbx, UDM_SETPOS32, 0, [xsi].dConnections

  ;Set data to transmit edit control
  invoke SetDlgItemTextA, [xsi].hWnd, IDC_EDT_DATA, addr [xsi].cText
  OCall xsi.UpdateDataGrp

  ;Set number of repetitions and up/down control
  invoke SetDlgItemInt, [xsi].hWnd, IDC_EDT_REPETITIONS, [xsi].dRepetitions, FALSE
  mov xbx, $invoke(GetDlgItem, [xsi].hWnd, IDC_UDN_REPETITIONS)
  invoke SendMessage, xbx, UDM_SETBASE, 10, 0
  invoke SendMessage, xbx, UDM_SETRANGE32, 1, 07FFFFFFFh
  invoke SendMessage, xbx, UDM_SETPOS32, 0, [xsi].dRepetitions
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SendDlg.Done
; Purpose:    Finalize the dialog object, freeing any allocated resources.
; Arguments:  None
; Return:     Nothing.

Method SendDlg.Done, uses xsi
  SetObject xsi
;  OCall [xsi].ActiveConns::Collection.Done
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SendDlg.Init
; Purpose:    Initialize the dialog object, setting up controls and default values.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
; Return:     Nothing.

Method SendDlg.Init, uses xsi, pOwner:POINTER, hParent:HWND
  SetObject xsi
  ACall xsi.Init, pOwner, hParent, IDD_DLG_SEND
;  OCall [xsi].ActiveConns::Collection.Init, xsi, 10, 10, COL_MAX_CAPACITY
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SendDlg.OnInitDialog
; Purpose:    Handle the WM_INITDIALOG message to perform initial setup.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero to indicate successful initialization.

Method SendDlg.OnInitDialog, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  ACall xsi.OnInitDialog, wParam, lParam                ;Call ancestor implementation
  xor eax, eax                                          ;Return zero
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SendDlg.OnCommand
; Purpose:    Handle WM_COMMAND messages, responding to user actions.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if the command is handled, otherwise non-zero.

Method SendDlg.OnCommand, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local pItem:PSDLL_ITEM, cBuffer[BUFFERSIZE + 20]:CHRA, dSize:DWORD

  SetObject xsi
  mov xdi, [xsi].pOwner                                 ;xdi -> NetComCoreClient
  LoWord wParam                                         ;Extract command ID

  ;Handle Connect button
  .if eax == IDC_BTN_CONNECT
    .if $OCall(xsi.CtlsGet) != FALSE                    ;If input is valid
      OCall xsi.CtlsEnable, FALSE                       ;Disable controls during connection
      mov ebx, [xsi].dConnections
      test ebx, ebx
      .while !ZERO?
        OCall [xdi].$Obj(NetComCoreClient).Client::NetComEngine.ConnectTo, \
                                         offset $ObjTmpl(NetComCoreClientProtocol), \
                                         addr $ObjTmpl(NetComCoreClientProtocol).ServerRemoteAddr, \
                                         addr $ObjTmpl(NetComCoreClientProtocol).ClientLocalAddr
        dec ebx
      .endw
    .endif
    xor eax, eax                                        ;Indicate handled

  ;Handle Send button
  .elseif eax == IDC_BTN_SEND
    .if $OCall(xsi.CtlsGet) != FALSE
      xor ebx, ebx
      .while ebx < [xsi].dRepetitions
        inc ebx
        lea xdi, cBuffer
        invoke udword2decA, xdi, ebx                    ;Convert repetition count to string
        lea xcx, [xdi + xax*sizeof(CHRA) - sizeof(CHRA)]
        FillTextA [xcx], < - >
        add xcx, ??StrSize
        invoke StrECopyA, xcx, addr [xsi].cText         ;Copy text payload
        sub xax, xdi                                    ;Calculate length
        inc eax                                         ;Include ZTC
        mov dSize, eax
        mov xcx, [xsi].pOwner                           ;xcx -> NetComCoreClient
        lea xdi, [xcx].$Obj(NetComCoreClient).Client.ConnectionChain
        SDLL_GetFirst xdi, xax
        .while !ZERO?
          mov pItem, xax
          lea xdx, cBuffer
          lea xcx, [xax - offset $Obj(NetComConnection).ChainItem] 
          OCall xcx::NetComConnection.QueueSend, xdx, dSize
          mov xax, pItem
          SDLL_GetNext xax, xdi
        .endw
      .endw
    .endif
    xor eax, eax                                        ;Indicate handled

  ;Handle Disconnect button
  .elseif eax == IDC_BTN_DISCONNECT
    OCall xsi.CtlsEnable, TRUE                          ;Re-enable controls
    mov xcx, [xsi].pOwner                               ;xcx -> NetComCoreClient
    lea xbx, [xcx].$Obj(NetComCoreClient).Client
    OCall xbx::NetComEngine.ConnectionsDisconnect
    OCall xbx::NetComEngine.ConnectionsDestroy
    OCall xbx::NetComEngine.ConnectionsClose
    lea xcx, [xbx].$Obj(NetComEngine).ConnectionChain
    SDLL_Init xcx
    xor eax, eax                                        ;Indicate handled

  ;Handle Cancel button
  .elseif eax == IDCANCEL
    mov xcx, [xsi].pOwner                               ;xcx -> NetComCoreClient
    lea xbx, [xcx].$Obj(NetComCoreClient).Client
    OCall xbx::NetComEngine.ConnectionsDisconnect
    OCall xbx::NetComEngine.ConnectionsDestroy
    OCall xbx::NetComEngine.ConnectionsClose
    lea xcx, [xbx].$Obj(NetComEngine).ConnectionChain
    SDLL_Init xcx
    OCall xsi.DestroyDialog, wParam                     ;Close dialog
    xor eax, eax                                        ;Indicate handled

  ;Handle Cancel button
  .elseif eax == IDC_EDT_DATA
    HiWord wParam                                       ;Extract command ID
    .if eax == EN_UPDATE
      OCall xsi.UpdateDataGrp
    .endif
    xor eax, eax                                        ;Indicate handled

  ;Handle other commands
  .else
    xor eax, eax
    inc eax                                             ;Indicate not handled
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SendDlg.UpdateDataGrp
; Purpose:    Updates the caption of the Data Group
; Arguments:  None
; Return:     Nothign.

Method SendDlg.UpdateDataGrp, uses xbx xsi
  local cBuffer[100]:CHR

  SetObject xsi
  invoke GetDlgItem, [xsi].hWnd, IDC_EDT_DATA
  invoke SendMessageA, xax, WM_GETTEXTLENGTH, 0, 0
  lea xbx, cBuffer
  WriteF xbx, "Data (¦UD bytes + sizeof(Header & ZTC)", eax
  invoke SetDlgItemText, [xsi].hWnd, IDC_GRP_DATA, addr cBuffer
MethodEnd

endif
