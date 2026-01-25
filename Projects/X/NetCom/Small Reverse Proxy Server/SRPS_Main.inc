; ==================================================================================================
; Title:      SRPS_Main.inc
; Author:     G. Friedrich
; Purpose:    See SRPS.asm
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Concept:
;                      Client Connections        Server Connections
;
;                     Remote         Local      Local         Remote            Peer Connections
;                    Endpoint      Endpoint    Endpoint      Endpoint               (A - a)
;                                                                                   (B - b)
;              +--------+              +----------+                                 (C - c)
;              | Client o---A--        |          o<--a--
;              +--------+      |       |          |      |
;                              |       |          |      |       +--------+
;              +--------+       ----   |          |       ----   |        |
;              | Client o<--B-------|->o   SRPS   o<--b-------|->o Server |
;              +--------+       ----   |          |       ----   |        |
;                              |       |          |      |       +--------+
;              +--------+      |       |          |      |
;              | Client o<--C--        |          o<--c--
;              +--------+              +----------+
;
;   The diagram illustrates the architecture of the reverse proxy system implemented by SRPS.
;   - Client: Represents the originating application or system that initiates a network connection.
;   - SRPS:   Acts as the reverse proxy, receiving connections from the client and forwarding them
;             to the designated server. It handles bidirectional data transfer, connection pairing,
;             and protocol management. It also provides a Windows GUI for configuration and control.
;   - Server: The backend system that ultimately receives the proxied connections and responds
;             to client requests.
;
;   Data flows bidirectionally between the Client and Server through the SRPS reverse proxy,
;   allowing seamless communication while enabling monitoring, address/port translation, and
;   connection control.
;
; --------------------------------------------------------------------------------------------------


APF_RUNNING   equ   BIT00                         ;Application is currently running

WM_SHOWMSG    equ   WM_APP

MSG_INFO struct
  pMessage    PSTRING   ?
  pCaption    PSTRING   ?
  dType       DWORD     ?
  cBuffer     CHR       0 DUP (?)  
MSG_INFO ends
PMSG_INFO typedef ptr MSG_INFO

MSG_INFO_SIZE equ 1024

; --------------------------------------------------------------------------------------------------
; Object:     Application
; Purpose:    Main application dialog.

Object Application,, DlgApp
  VirtualMethod     CtlsEnable,       DWORD             ;Enable/disable UI controls
  RedefineMethod    CtlsGet                             ;Read dialog values
  RedefineMethod    CtlsSet                             ;Update dialog controls
  RedefineMethod    Done                                ;Cleanup resources
  RedefineMethod    Init                                ;Initialize dialog

  VirtualEvent      OnCommand,        WM_COMMAND        ;Handle WM_COMMAND messages
  VirtualEvent      OnShowMsg,        WM_SHOWMSG        ;Handle WM_SHOWMSG messages
  VirtualEvent      OnTimer,          WM_TIMER          ;Handle WM_TIMER messages

  DefineVariable    dFlags,           DWORD,          0 ;Runtime state flags
  DefineVariable    hTimer,           HANDLE,         0

  Embed  RevProxy,  NetComEngine                        ;Embedded reverse proxy engine
ObjectEnd


include SRPS_Protocol.inc

TIMER_ID  equ   126985

.code
; ==================================================================================================
;    Application implementation
; ==================================================================================================


.code

; --------------------------------------------------------------------------------------------------
; Procedure:  IsUnsignedDecimalString
; Purpose:    Checks if the input string is a unsigned decimal number.
; Arguments:  Arg1: -> Input string.
; Return:     eax = TRUE if a unsigned decimal number was detected, otherwise FALSE.

IsUnsignedDecimalString proc pString:PSTRING
  xor eax, eax
  ?mov xcx, pString
  .if xcx != NULL && CHR ptr [xcx] != 0
    .while TRUE
      movzx edx, CHR ptr [xcx]
      .if edx == 0
        inc eax
        .break
      .endif
      .break .if edx < "0" || edx > "9"
      add xcx, sizeof CHR
    .endw
  .endif
  ret
IsUnsignedDecimalString endp

; --------------------------------------------------------------------------------------------------
; Method:     Application.CtlsEnable
; Purpose:    Enables or disables the dialog controls.
; Arguments:  Arg1: TRUE = enabled, FALSE = disabled.
; Return:     Nothing.

Method Application.CtlsEnable, uses xbx xsi, dEnable:DWORD
  SetObject xsi                                         ;Bind object context

  ;Handle inner controls - enable/disable them
  invoke GetDlgItem, [xsi].hWnd, IDC_CBO_CLIENT_LOCAL_ADDR    ;Client local address combobox control
  invoke EnableWindow, xax, dEnable                           ;Enable/disable control
  invoke GetDlgItem, [xsi].hWnd, IDC_EDT_CLIENT_LOCAL_PORT    ;Client local port edit control
  invoke EnableWindow, xax, dEnable                           ;Enable/disable control
  invoke GetDlgItem, [xsi].hWnd, IDC_UDN_CLIENT_LOCAL_PORT    ;Client local port up/down control
  invoke EnableWindow, xax, dEnable                           ;Enable/disable control

  invoke GetDlgItem, [xsi].hWnd, IDC_CBO_SERVER_LOCAL_ADDR    ;Server local address combobox control
  invoke EnableWindow, xax, dEnable                           ;Enable/disable control
  invoke GetDlgItem, [xsi].hWnd, IDC_CHK_SERVER_USE_EPHEM_PORT;Server local ephem. checkbox control
  invoke EnableWindow, xax, dEnable                           ;Enable/disable control
  invoke GetDlgItem, [xsi].hWnd, IDC_EDT_SERVER_LOCAL_PORT    ;Server local port edit control
  invoke EnableWindow, xax, dEnable                           ;Enable/disable control
  invoke GetDlgItem, [xsi].hWnd, IDC_UDN_SERVER_LOCAL_PORT    ;Server local port up/down control
  invoke EnableWindow, xax, dEnable                           ;Enable/disable control
  invoke GetDlgItem, [xsi].hWnd, IDC_CBO_SERVER_REMOTE_ADDR   ;Server remote IP address control
  invoke EnableWindow, xax, dEnable                           ;Enable/disable control
  invoke GetDlgItem, [xsi].hWnd, IDC_EDT_SERVER_REMOTE_PORT   ;Server remote port edit control
  invoke EnableWindow, xax, dEnable                           ;Enable/disable control
  invoke GetDlgItem, [xsi].hWnd, IDC_UDN_SERVER_REMOTE_PORT   ;Server remote port up/down control
  invoke EnableWindow, xax, dEnable                           ;Enable/disable control

  ;Handle buttons - switch between Start and Stop
  .if dEnable != FALSE
    mov ebx, IDC_BTN_START                              ;Enable Start button
    mov edx, IDC_BTN_STOP                               ;Disable Stop button
  .else
    mov ebx, IDC_BTN_STOP                               ;Enable Stop button
    mov edx, IDC_BTN_START                              ;Disable Start button
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
; Method:     Application.CtlsGet
; Purpose:    Get dialog controls.
; Arguments:  None.
; Return:     eax = TRUE if succeeded or FALSE otherwise.

Method Application.CtlsGet, uses xdi xbx xsi
  local dRetValue:DWORD, dSucceeded:DWORD, Hints:ADDRINFOT, pResult:PADDRINFOT
  local cClientLocalAddr[32]:CHR, cClientLocalServiceName[32]:CHR
  local cServerLocalAddr[32]:CHR, cServerLocalServiceName[32]:CHR
  local cServerRemoteAddr[32]:CHR, cServerRemoteServiceName[32]:CHR
  local cBuffer:DWORD

  DbgText "Application.CtlsGet"
  SetObject xsi

  ;Read client local IP
  mov xdi, $invoke(GetDlgItem, [xsi].hWnd, IDC_CBO_CLIENT_LOCAL_ADDR)
  invoke SendMessage, xdi, CB_GETCURSEL, 0, 0
  lea xbx, cClientLocalAddr
  invoke SendMessage, xdi, CB_GETLBTEXT, eax, xbx       ;Can only return valid addresses

  ;Read client local port (listening port)
  invoke GetDlgItemInt, [xsi].hWnd, IDC_EDT_CLIENT_LOCAL_PORT, addr dSucceeded, FALSE
  .if dSucceeded != FALSE && ax > 0 && ax <= 0FFFFh
    invoke GetDlgItemText, [xsi].hWnd, IDC_EDT_CLIENT_LOCAL_PORT, \
                           addr cClientLocalServiceName, lengthof cClientLocalServiceName
  .else
    invoke MessageBox, [xsi].hWnd, $OfsCStr("Incorrect client local port number"), \
                       addr cError, MB_OK or MB_ICONERROR
    xor eax, eax
    ExitMethod
  .endif

  ;Read server local IP
  mov xdi, $invoke(GetDlgItem, [xsi].hWnd, IDC_CBO_SERVER_LOCAL_ADDR)
  invoke SendMessage, xdi, CB_GETCURSEL, 0, 0
  lea xbx, cServerLocalAddr
  invoke SendMessage, xdi, CB_GETLBTEXT, eax, xbx       ;Can only return valid addresses

  lea xbx, $ObjTmpl(NetComSrpsProtocol)

  ;Read server use ephemeral port
  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_CHK_SERVER_USE_EPHEM_PORT
  xor ecx, ecx
  cmp eax, BST_CHECKED
  setz cl
  mov [xbx].$Obj(NetComSrpsProtocol).dUseEphemeralPort, ecx

  ;Read server local port
  .if ecx == FALSE
    invoke GetDlgItemInt, [xsi].hWnd, IDC_EDT_SERVER_LOCAL_PORT, addr dSucceeded, FALSE
    .if dSucceeded != FALSE && ax > 0 && ax <= 0FFFFh
      invoke GetDlgItemText, [xsi].hWnd, IDC_EDT_SERVER_LOCAL_PORT, \
                             addr cServerLocalServiceName, lengthof cServerLocalServiceName
    .else
      invoke MessageBox, [xsi].hWnd, $OfsCStr("Incorrect server connection local port number"), \
                         addr cError, MB_OK or MB_ICONERROR
      xor eax, eax
      ExitMethod
    .endif
  .else
    FillString cServerLocalServiceName, <0>
  .endif

  ;Read server remote IP
  mov xdi, $invoke(GetDlgItem, [xsi].hWnd, IDC_CBO_SERVER_REMOTE_ADDR)
  invoke SendMessage, xdi, CB_GETCURSEL, 0, 0
  lea xbx, cServerRemoteAddr
  invoke SendMessage, xdi, CB_GETLBTEXT, eax, xbx       ;Can only return valid addresses

  ;Read server remote port
  invoke GetDlgItemInt, [xsi].hWnd, IDC_EDT_SERVER_REMOTE_PORT, addr dSucceeded, FALSE
  .if dSucceeded != FALSE && ax > 0 && ax <= 0FFFFh
    invoke GetDlgItemText, [xsi].hWnd, IDC_EDT_SERVER_REMOTE_PORT, \
                           addr cServerRemoteServiceName, lengthof cServerRemoteServiceName
  .else
    invoke MessageBox, [xsi].hWnd, $OfsCStr("Incorrect server remote port number"), \
                       addr cError, MB_OK or MB_ICONERROR
    xor eax, eax
    ExitMethod
  .endif

  ; --------------------------------------------------------------------------------
  ; Get network components
  ; --------------------------------------------------------------------------------

  mov dRetValue, FALSE

  mov Hints.ai_flags, AI_NUMERICHOST or \       ;Only numeric host allowed
                      AI_PASSIVE                ;Socket address will be used with a bind call
  mov Hints.ai_family, AF_INETX                 ;IPv4/IPv6 family
  mov Hints.ai_socktype, SOCK_STREAM            ;TCP socket
  mov Hints.ai_protocol, IPPROTO_TCP            ;TCP protocol
  mov Hints.ai_addrlen, 0                       ;Must be set to zero
  mov Hints.ai_canonname, NULL                  ;Must be set to NULL
  mov Hints.ai_addr, NULL                       ;Must be set to NULL
  mov Hints.ai_next, NULL                       ;Must be set to NULL

  ;Get client local NETCOMADDR ----------------------------
  ;Compare with "ANY", if iqual => use NULL as pNodeName argument for GetAddrInfo
  lea xbx, $ObjTmpl(NetComSrpsProtocol)
  invoke StrComp, addr cClientLocalAddr, addr cAny
  xor ecx, ecx
  .if eax != 0
    lea xcx, cClientLocalAddr
  .endif
  invoke GetAddrInfo, xcx, addr cClientLocalServiceName, addr Hints, addr pResult
  .if eax != 0
    invoke WSAGetLastError
    invoke WsaErrBox, [xsi].hWnd, $OfsCStr("Incorrect client local address or port number"), \
                       offset cError, MB_OK or MB_ICONERROR, eax
    jmp @@Exit
  .endif
  mov xax, pResult
  lea xcx, [xbx].$Obj(NetComSrpsProtocol).ListeningAddr
  invoke MemClone, xcx, [xax].ADDRINFOT.ai_addr, DWORD ptr [xax].ADDRINFOT.ai_addrlen
  invoke FreeAddrInfo, pResult                          ;Free memory

  ;Get Server local NETCOMADDR ----------------------------
  mov Hints.ai_flags, AI_NUMERICHOST                    ;Only numeric host allowed
  invoke StrComp, addr cServerLocalAddr, addr cAuto
  xor ecx, ecx
  .if eax != 0
    lea xcx, cServerLocalAddr
  .endif
  xor edx, edx
  .if [xbx].$Obj(NetComSrpsProtocol).dUseEphemeralPort == FALSE
    lea xdx, cServerLocalServiceName
  .endif
  .if xcx != NULL || xdx != NULL
    invoke GetAddrInfo, xcx, xdx, addr Hints, addr pResult
    .if eax != 0
      invoke WSAGetLastError
      invoke WsaErrBox, [xsi].hWnd, $OfsCStr("Incorrect server local address or port number"), \
                         offset cError, MB_OK or MB_ICONERROR, eax
      jmp @@Exit
    .endif
    mov xax, pResult
    lea xcx, [xbx].$Obj(NetComSrpsProtocol).ServerLocalAddr
    invoke MemClone, xcx, [xax].ADDRINFOT.ai_addr, DWORD ptr [xax].ADDRINFOT.ai_addrlen
    invoke FreeAddrInfo, pResult                        ;Free memory
  .else
    lea xdi, [xbx].$Obj(NetComSrpsProtocol).ServerLocalAddr
    invoke MemZero, xdi, sizeof NETCOMADDR
    mov [xdi].NETCOMADDR.wFamily, AF_INETX
  .endif
  DbgNetComAddrIPV4 [xbx].$Obj(NetComSrpsProtocol).ServerLocalAddr, "Application.CtlsGet - Server Local Address"

  ;Get Server remote NETCOMADDR ---------------------------
  mov Hints.ai_flags, AI_NUMERICHOST                    ;Only numeric host allowed
  invoke GetAddrInfo, addr cServerRemoteAddr, addr cServerRemoteServiceName, addr Hints, addr pResult  ;Resolve
  .if eax != 0
    invoke WSAGetLastError
    invoke WsaErrBox, [xsi].hWnd, $OfsCStr("Incorrect server remote address or port number"), \
                       offset cError, MB_OK or MB_ICONERROR, eax
    jmp @@Exit
  .endif
  mov xax, pResult
  lea xcx, [xbx].$Obj(NetComSrpsProtocol).ServerRemoteAddr
  invoke MemClone, xcx, [xax].ADDRINFOT.ai_addr, DWORD ptr [xax].ADDRINFOT.ai_addrlen
  invoke FreeAddrInfo, pResult                          ;Free memory
  
  mov dRetValue, TRUE
  DbgNetComAddrIPV4 [xbx].$Obj(NetComSrpsProtocol).ServerRemoteAddr, "Application.CtlsGet - Server Remote Address"

@@Exit:
  mov eax, dRetValue
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.CtlsSet
; Purpose:    Set dialog controls.
; Arguments:  None.
; Return:     Nothing.

Method Application.CtlsSet, uses xbx xdi xsi
  local dSize:DWORD, pAdapter:POINTER, dPort:DWORD, pMibTable:PMIB_IPNET_TABLE2
  local hComboClientLocalAddr:HANDLE, hComboServerLocalAddr:HANDLE, hComboServerRemoteAddr:HANDLE
  local cBuffer[100]:CHR, dBufferLength:DWORD

  DbgText "Application.CtlsSet"
  SetObject xsi
  
  ;Set "Client local address" and "Server local address" comboboxes
  mov hComboClientLocalAddr, $invoke(GetDlgItem, [xsi].hWnd, IDC_CBO_CLIENT_LOCAL_ADDR)
  mov hComboServerLocalAddr, $invoke(GetDlgItem, [xsi].hWnd, IDC_CBO_SERVER_LOCAL_ADDR)
  invoke SendMessage, hComboClientLocalAddr, CB_RESETCONTENT, 0, 0
  invoke SendMessage, hComboClientLocalAddr, CB_ADDSTRING, 0, addr cAny
  invoke SendMessage, hComboServerLocalAddr, CB_RESETCONTENT, 0, 0
  invoke SendMessage, hComboServerLocalAddr, CB_ADDSTRING, 0, addr cAuto

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
          invoke SendMessage, hComboClientLocalAddr, CB_ADDSTRING, 0, addr cBuffer
          invoke SendMessage, hComboServerLocalAddr, CB_ADDSTRING, 0, addr cBuffer
          mov xdi, [xdi].IP_ADAPTER_UNICAST_ADDRESS.Next  ;Next unicast address
        .endw
        mov xbx, [xbx].IP_ADAPTER_ADDRESSES.Next        ;Next adapter
      .endw
    .endif
    MemFree pAdapter                                    ;Free allocated memory buffer
  .endif
  invoke SendMessage, hComboClientLocalAddr, CB_SETCURSEL, 0, 0
  invoke SendMessage, hComboServerLocalAddr, CB_SETCURSEL, 0, 0

  ;Set "Client local port" edit control limits and value
  lea xbx, $ObjTmpl(NetComSrpsProtocol)
  invoke htons, [xbx].$Obj(NetComSrpsProtocol).ListeningAddr.wPort
  mov dPort, eax
  invoke SetDlgItemInt, [xsi].hWnd, IDC_EDT_CLIENT_LOCAL_PORT, dPort, FALSE   ;Update listening port

  ;Set "Client local port" up/down control limits and value
  mov xdi, $invoke(GetDlgItem, [xsi].hWnd, IDC_UDN_CLIENT_LOCAL_PORT)
  invoke SendMessage, xdi, UDM_SETBASE, 10, 0
  invoke SendMessage, xdi, UDM_SETRANGE32, 1, 0FFFFh
  invoke SendMessage, xdi, UDM_SETPOS32, 0, dPort

  ;Check/uncheck "use ephemeral port" control
  mov eax, BST_CHECKED
  .if [xbx].$Obj(NetComSrpsProtocol).dUseEphemeralPort == FALSE
    mov eax, BST_UNCHECKED
  .endif
  invoke CheckDlgButton, [xsi].hWnd, IDC_CHK_SERVER_USE_EPHEM_PORT, eax

  ;Set "Server remote address" combobox
  mov hComboServerRemoteAddr, $invoke(GetDlgItem, [xsi].hWnd, IDC_CBO_SERVER_REMOTE_ADDR)
  invoke SendMessage, hComboServerRemoteAddr, CB_RESETCONTENT, 0, 0

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
          invoke SendMessage, hComboServerRemoteAddr, CB_ADDSTRING, 0, addr cBuffer
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
      invoke WSAAddressToString, addr [xdi].MIB_IPNET_ROW2.Address, sizeof SOCKADDR_INET, NULL, addr cBuffer, addr dBufferLength
      .if eax == NO_ERROR
        invoke SendMessage, hComboServerRemoteAddr, CB_ADDSTRING, 0, addr cBuffer
      .endif
      add xdi, sizeof(MIB_IPNET_ROW2)
      dec ebx
    .endw
    invoke FreeMibTable, pMibTable
  .endif
  
  invoke SendMessage, hComboServerRemoteAddr, CB_SETCURSEL, 0, 0

  ;Enable/disable "Server local port" edit control
  lea xbx, $ObjTmpl(NetComSrpsProtocol)
  invoke GetDlgItem, [xsi].hWnd, IDC_EDT_SERVER_LOCAL_PORT
  xor edx, edx
  cmp [xbx].$Obj(NetComSrpsProtocol).dUseEphemeralPort, FALSE
  setz dl
  invoke EnableWindow, xax, edx

  ;Set "Server local port" edit control
  invoke htons, [xbx].$Obj(NetComSrpsProtocol).ServerRemoteAddr.wPort
  mov dPort, eax
  invoke SetDlgItemInt, [xsi].hWnd, IDC_EDT_SERVER_REMOTE_PORT, dPort, FALSE  ;Update Server port

  ;Set server local port up/down control limits and value
  mov xdi, $invoke(GetDlgItem, [xsi].hWnd, IDC_UDN_SERVER_REMOTE_PORT)
  invoke SendMessage, xdi, UDM_SETBASE, 10, 0
  invoke SendMessage, xdi, UDM_SETRANGE32, 1, 0FFFFh
  invoke SendMessage, xdi, UDM_SETPOS32, 0, dPort
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.Done
; Purpose:    Finalize the application object and frees allocated resources.
; Arguments:  None.
; Return:     Nothing.

Method Application.Done, uses xsi
  SetObject xsi                                         ;Bind object context
  invoke KillTimer, [xsi].hWnd, TIMER_ID
  OCall [xsi].RevProxy::NetComEngine.StopListening
  OCall [xsi].RevProxy::NetComEngine.Done
  OCall $ObjTmpl(NetComSrpsProtocol)::NetComSrpsProtocol.Done
  ACall xsi.Done                                        ;Call ancestor Done method
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.Init
; Purpose:    Initialize the application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Init, uses xbx xsi
  local cBuffer[1024]:CHR

  SetObject xsi
  ACall xsi.Init                                        ;Call ancestor Init
  invoke CreateDialogParam, hInstance, IDD_DLG_MAIN, 0, $MethodAddr(DlgApp.WndProc), xsi
  .if xax == NULL
    DbgApiError
    lea xbx, cBuffer
    WriteF xbx, "\`¦ST\` failed to start\:", offset szAppTitle ;Prepare error message
    invoke MessageBox, 0, addr cBuffer, addr cError, MB_OK or MB_ICONERROR or MB_TASKMODAL
    invoke ExitProcess, 1                               ;Exit program with failure
  .else
    invoke LoadIcon, hInstance, offset szIcoName
    invoke SendMessage, [xsi].hWnd, WM_SETICON, ICON_BIG, xax   ;Set big icon
    invoke SendMessage, [xsi].hWnd, WM_SETICON, ICON_SMALL, xax ;Set small icon

    OCall $ObjTmpl(NetComSrpsProtocol)::NetComSrpsProtocol.Init, xsi
    .if eax != 0
      lea xbx, cBuffer
      WriteF xbx, "\`¦ST\` failed to initialize the Reverse Proxy protocol\:", offset szAppTitle ;Prepare error message
      invoke MessageBox, 0, addr cBuffer, addr cError, MB_OK or MB_ICONERROR or MB_TASKMODAL
      invoke ExitProcess, 1                               ;Exit program with failure
    .endif
  .endif
  OCall [xsi].RevProxy::NetComEngine.Init, xsi, 50, 1000, MSS_ETHERNET_IPVX ;Init network engine
  .if eax != 0
    invoke MessageBox, [xsi].hWnd, $OfsCStr("Failed to start the NetCom engine"), \
                       addr cError, MB_OK or MB_ICONERROR ;Show error
    invoke ExitProcess, 1                                 ;Exit program with failure
  .endif

  invoke SetWindowText, [xsi].hWnd, offset szAppTitle
  invoke SetTimer, [xsi].hWnd, TIMER_ID, 1000, NULL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = If an application processes this message, it should return zero.

Method Application.OnCommand, uses xbx xsi, wParam:WPARAM, lParam:LPARAM

  SetObject xsi
  mov xax, wParam

  .if ax == IDC_BTN_START
    OCall xsi.CtlsGet                                   ;Read dialog controls
    .if eax != FALSE
      ;16 pending acceptors is a regular number on most servers
      mov xax, offset $ObjTmpl(NetComSrpsProtocol)
      DbgHex xax, "pProtocol"
      OCall [xsi].RevProxy::NetComEngine.StartListening, 16, offset $ObjTmpl(NetComSrpsProtocol)
      .if eax == NO_ERROR
        DbgText "Reverse Proxy is listening"            ;Debug message
        DbgLine2
        BitSet [xsi].dFlags, APF_RUNNING                ;Mark as running
        OCall xsi.CtlsEnable, FALSE                     ;Disable controls
      .endif
    .endif
    xor eax, eax                                        ;Return zero

  .elseif ax == IDC_BTN_STOP
    OCall [xsi].RevProxy::NetComEngine.StopListening
    OCall [xsi].RevProxy::NetComEngine.ConnectionsDestroy
    OCall [xsi].RevProxy::NetComEngine.ConnectionsClose
    BitClr [xsi].dFlags, APF_RUNNING                    ;Clear running flag
    OCall xsi.CtlsEnable, TRUE                          ;Re-enable controls
    xor eax, eax                                        ;Return zero

  .elseif ax == IDCANCEL
    .ifBitSet [xsi].dFlags, APF_RUNNING
      invoke MessageBox, [xsi].hWnd, $OfsCStr("Are you sure you want to exit?"), \
                         $OfsCStr("Application exit"), MB_YESNO or MB_ICONQUESTION ;Confirm exit
      .if eax == IDYES
        invoke DestroyWindow, [xsi].hWnd                ;Destroy dialog
      .endif
    .else
      invoke DestroyWindow, [xsi].hWnd                  ;Destroy dialog without prompt
    .endif
    xor eax, eax                                        ;Return zero

  .elseif ax == IDC_CHK_SERVER_USE_EPHEM_PORT
    invoke IsDlgButtonChecked, [xsi].hWnd, IDC_CHK_SERVER_USE_EPHEM_PORT
    xor ebx, ebx
    cmp eax, BST_UNCHECKED
    setz bl
    invoke GetDlgItem, [xsi].hWnd, IDC_EDT_SERVER_LOCAL_PORT ;Server local port edit control
    invoke EnableWindow, xax, ebx                       ;Enable/disable control
    xor eax, eax                                        ;Return zero

  .else
    xor eax, eax
    inc eax                                             ;Return default (unhandled)
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnShowMsg
; Purpose:    Shows a MessageBox displaying a message.
; Arguments:  Arg1: -> MSG_INFO.
;             Arg2: Dummy.
; Return:     Nothing.

Method Application.OnShowMsg, uses xbx, pMsgInfo:WPARAM, lParam:LPARAM
  SetObject xcx
  mov xbx, pMsgInfo
  invoke MessageBox, [xcx].hWnd, [xbx].MSG_INFO.pMessage, [xbx].MSG_INFO.pCaption, [xbx].MSG_INFO.dType
  MemFree xbx  
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnTimer
; Purpose:    Event procedure for WM_TIMER message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnTimer, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[1024]:CHR

  SetObject xsi

  ;Set application caption
  lea xdi, cBuffer
  lea xbx, [xsi].RevProxy
  WriteF xdi, "¦ST - ¦UD/¦UD", offset szAppTitle, \
                              [xbx].$Obj(NetComEngine).Connections.dCount, \
                              [xbx].$Obj(NetComEngine).IOSockJobs.dCount   

  invoke SetWindowText, [xsi].hWnd, addr cBuffer
MethodEnd
