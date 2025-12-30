; ==================================================================================================
; Title:      SRP_Main.inc
; Author:     G. Friedrich
; Purpose:    See SRP.asm
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Concept:
;
;       +--------+     +---------+     +--------+
;       |        |---->| Simple  |---->|        |
;       | Client |     | Reverse |     | Server |
;       |        |<----| Proxy   |<----|        |
;       +--------+     +---------+     +--------+
;
;   The diagram illustrates the architecture of the reverse proxy system implemented by SRP.
;   - Client: Represents the originating application or system that initiates a network connection.
;   - SRP: Acts as the reverse proxy, receiving connections from the client and forwarding them 
;          to the designated server. It handles bidirectional data transfer, connection pairing, 
;          and protocol management. SRP also provides a Windows GUI for configuration and control.
;   - Server: The backend system that ultimately receives the proxied connections and responds 
;             to client requests.
;
;   Data flows bidirectionally between the Client and Server through the SRP reverse proxy, allowing
;   seamless communication while enabling monitoring, address/port translation, and connection
;   control.
;
; --------------------------------------------------------------------------------------------------


APF_RUNNING         equ   BIT00                         ;Application is currently running

; --------------------------------------------------------------------------------------------------
; Object:     Application
; Purpose:    Main application dialog.

Object Application,, DlgApp
  VirtualMethod     CtlsEnable,     DWORD               ;Enable/disable UI controls
  RedefineMethod    CtlsGet                             ;Read dialog values
  RedefineMethod    CtlsSet                             ;Update dialog controls
  RedefineMethod    Done                                ;Cleanup resources
  RedefineMethod    Init                                ;Initialize dialog

  VirtualEvent      OnCommand,      WM_COMMAND          ;Handle WM_COMMAND messages
  RedefineMethod    OnInitDialog,   WPARAM, LPARAM      ;Handle WM_INITDIALOG

;  DefineVariable    hStopEvent,     HANDLE,         0   ;Reserved for future async shutdown
  DefineVariable    dFlags,         DWORD,          0   ;Runtime state flags

  DefineVariable    DestAddr,       NETCOMADDR,     {}         ;Resolved destination sockaddr
  DefineVariable    wDestPort,      WORD,           25773      ;Default destination port
  DefineVariable    LocalHostAddr,  NETCOMADDR,     {}         ;Resolved local host sockaddr
  DefineVariable    wLocalHostPort, WORD,           25772      ;Listening Local Host port

  Embed  RevProxy,  NetComEngine                        ;Embedded reverse proxy engine
ObjectEnd


include SRP_Protocol.inc

.code
; ==================================================================================================
;    Application implementation
; ==================================================================================================


.code

;GetLocalHostIPs proc uses xbx xdi xsi
;  local dSize:DWORD, cBuffer[100]:CHR
;
;  invoke GetAdaptersAddresses, AF_INETX, 0, NULL, NULL, addr dSize   ;Get buffer size
;  MemAlloc dSize                                        ;Allocate buffer
;  .if xax != NULL
;    mov xbx, xax
;    invoke GetAdaptersAddresses, AF_INETX, 0, NULL, xbx, addr dSize  ;Get adapter data
;    .if eax == ERROR_SUCCESS
;      ;Iterate adapters
;      mov xsi, xbx
;      .while xsi != NULL
;        mov xdi, [xsi].IP_ADAPTER_ADDRESSES.FirstUnicastAddress
;        ;Iterate unicast addresses
;        .while xdi != NULL
;          invoke getnameinfo, [xdi].IP_ADAPTER_UNICAST_ADDRESS.Address.lpSockaddr, \
;                              [xdi].IP_ADAPTER_UNICAST_ADDRESS.Address.iSockaddrLength, \
;                              addr cBuffer, sizeof cBuffer, \
;                              NULL, 0, \
;                              NI_NUMERICHOST
;          DbgStr cBuffer
;          mov xdi, [xdi].IP_ADAPTER_UNICAST_ADDRESS.Next  ;Next unicast address
;        .endw
;        mov xsi, [xsi].IP_ADAPTER_ADDRESSES.Next          ;Next adapter
;      .endw
;    .endif
;    MemFree xbx                                         ;Free allocated memory buffer
;  .endif
;  ret
;GetLocalHostIPs endp

; --------------------------------------------------------------------------------------------------
; Method:     Application.CtlsEnable
; Purpose:    Enables or disables the dialog controls.
; Arguments:  Arg1: TRUE = enabled, FALSE = disabled.
; Return:     Nothing.

Method Application.CtlsEnable, uses xbx xsi, dEnable:DWORD
  SetObject xsi                                         ;Bind object context

  ;Handle inner controls - enable/disable them
  invoke GetDlgItem, [xsi].hWnd, IDC_CBO_LOCAL_HOST_ADDRESS   ;Local Host address combobox control
  invoke EnableWindow, xax, dEnable                           ;Enable/disable control
  invoke GetDlgItem, [xsi].hWnd, IDC_EDT_LOCAL_HOST_PORT      ;Local Host port edit control
  invoke EnableWindow, xax, dEnable                           ;Enable/disable control
  invoke GetDlgItem, [xsi].hWnd, IDC_UDN_LOCAL_HOST_PORT      ;Local Host port up/down control
  invoke EnableWindow, xax, dEnable                           ;Enable/disable control
  invoke GetDlgItem, [xsi].hWnd, IDC_IPA_DESTINATION_ADDRESS  ;Destination IP address control
  invoke EnableWindow, xax, dEnable                           ;Enable/disable control
  invoke GetDlgItem, [xsi].hWnd, IDC_EDT_DESTINATION_PORT     ;Destination port edit control
  invoke EnableWindow, xax, dEnable                           ;Enable/disable control
  invoke GetDlgItem, [xsi].hWnd, IDC_UDN_DESTINATION_PORT     ;Destination port up/down control
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
  local dRetValue:DWORD, dSucceeded:DWORD, WsaData:WSADATA, cLocalHostAddr[1024]:CHR
  local dDestAddr:DWORD, cDestAddr[100]:CHR, cServiceName[100]:CHR
  local Hints:ADDRINFOT, pResult:PADDRINFOT

  DbgText "Application.CtlsGet"
  SetObject xsi
  
  ;Read Local Host IP
  invoke GetDlgItem, [xsi].hWnd, IDC_CBO_LOCAL_HOST_ADDRESS
  mov xdi, xax
  lea xbx, cLocalHostAddr
  invoke SendMessage, xdi, CB_GETCURSEL, 0, 0
  invoke SendMessage, xdi, CB_GETLBTEXT, eax, xbx 

  ;Read listening port
  invoke GetDlgItemInt, [xsi].hWnd, IDC_EDT_LOCAL_HOST_PORT, addr dSucceeded, FALSE 
  .if dSucceeded != FALSE && ax > 0 && ax <= 0FFFFh
    mov [xsi].wLocalHostPort, ax                        ;Store valid port
  .else
    invoke MessageBox, [xsi].hWnd, $OfsCStr("Incorrect incoming port number"), \
                       addr cError, MB_OK or MB_ICONERROR
    xor eax, eax
    ExitMethod
  .endif

  ;Get destination IP
  invoke GetDlgItem, [xsi].hWnd, IDC_IPA_DESTINATION_ADDRESS
  mov xcx, xax
  invoke SendMessage, xcx, IPM_GETADDRESS, 0, addr dDestAddr  
  .if eax != 4                                          ;Expect 4 octets
    invoke MessageBox, [xsi].hWnd, $OfsCStr("Incorrect destination address"), \
                       addr cError, MB_OK or MB_ICONERROR
    xor eax, eax
    ExitMethod
  .endif

  ;Read destination port
  invoke GetDlgItemInt, [xsi].hWnd, IDC_EDT_DESTINATION_PORT, addr dSucceeded, FALSE 
  .if dSucceeded != FALSE && ax > 0 && ax <= 0FFFFh
    mov [xsi].wDestPort, ax                             ;Store valid port
  .else
    invoke MessageBox, [xsi].hWnd, $OfsCStr("Incorrect destination port number"), \
                       addr cError, MB_OK or MB_ICONERROR
    xor eax, eax
    ExitMethod
  .endif

  ; --------------------------------------------------------------------------------
  ; Get network components
  ; --------------------------------------------------------------------------------

  invoke WSAStartup, 0202h, addr WsaData
  .if eax != 0
    invoke MessageBox, [xsi].hWnd, $OfsCStr("Failed to start network engine"), \
                       addr cError, MB_OK or MB_ICONERROR   ;Show error
    xor eax, eax
    ExitMethod
  .endif

  mov dRetValue, FALSE

  mov Hints.ai_flags, AI_NUMERICHOST                    ;Only numeric host allowed
  mov Hints.ai_family, AF_INETX                         ;IPv4/IPv6 family
  mov Hints.ai_socktype, SOCK_STREAM                    ;TCP socket
  mov Hints.ai_protocol, IPPROTO_TCP                    ;TCP protocol
  mov Hints.ai_addrlen, 0
  mov Hints.ai_canonname, NULL
  mov Hints.ai_addr, NULL
  mov Hints.ai_next, NULL

  invoke GetDlgItemText, [xsi].hWnd, IDC_EDT_LOCAL_HOST_PORT, \
                         addr cServiceName, lengthof cServiceName ;Read service string

  invoke GetAddrInfo, addr cLocalHostAddr, addr cServiceName, addr Hints, addr pResult  ;Resolve
  .if eax == 0 && pResult != NULL
    mov xax, pResult
    lea xcx, [xsi].LocalHostAddr
    .if [xax].ADDRINFOT.ai_addrlen <= sizeof(NETCOMADDR);Check buffer size
      invoke MemClone, xcx, [xax].ADDRINFOT.ai_addr, DWORD ptr [xax].ADDRINFOT.ai_addrlen ;Copy
      invoke FreeAddrInfo, pResult                      ;Free memory
    .else
      invoke MemZero, xcx, sizeof(NETCOMADDR)           ;Clear buffer
      invoke FreeAddrInfo, pResult
      invoke MessageBox, [xsi].hWnd, $OfsCStr("Failed to validate the local host address"), \
                         addr cError, MB_OK or MB_ICONERROR   ;Show error
      jmp @@Exit
    .endif
  .else
    invoke MessageBox, [xsi].hWnd, $OfsCStr("Incorrect destination address"), \
                       addr cError, MB_OK or MB_ICONERROR     ;Show error
    jmp @@Exit
  .endif


  lea xdi, cDestAddr
  WriteF xdi, "各B.各B.各B.各B", BYTE ptr dDestAddr[3], BYTE ptr dDestAddr[2], \
                                 BYTE ptr dDestAddr[1], BYTE ptr dDestAddr[0]
  invoke GetDlgItemText, [xsi].hWnd, IDC_EDT_DESTINATION_PORT, \
                         addr cServiceName, lengthof cServiceName ;Read service string
  invoke GetAddrInfo, addr cDestAddr, addr cServiceName, addr Hints, addr pResult  ;Resolve
  .if eax == 0 && pResult != NULL
    mov xax, pResult
    lea xcx, [xsi].DestAddr
    .if [xax].ADDRINFOT.ai_addrlen <= sizeof(NETCOMADDR);Check buffer size
      invoke MemClone, xcx, [xax].ADDRINFOT.ai_addr, DWORD ptr [xax].ADDRINFOT.ai_addrlen ;Copy
      invoke FreeAddrInfo, pResult                      ;Free memory
      mov dRetValue, TRUE
    .else
      invoke MemZero, xcx, sizeof(NETCOMADDR)           ;Clear buffer
      invoke FreeAddrInfo, pResult
      invoke MessageBox, [xsi].hWnd, $OfsCStr("Failed to validate the destination address"), \
                         addr cError, MB_OK or MB_ICONERROR   ;Show error
    
      jmp @@Exit
    .endif
  .else
    invoke MessageBox, [xsi].hWnd, $OfsCStr("Incorrect destination address"), \
                       addr cError, MB_OK or MB_ICONERROR     ;Show error
    jmp @@Exit
  .endif

@@Exit:
  invoke WSACleanup                                     ;Shutdown WinSock

  mov eax, dRetValue
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.CtlsSet
; Purpose:    Set dialog controls.
; Arguments:  None.
; Return:     Nothing.

Method Application.CtlsSet, uses xbx xdi xsi
  local dSize:DWORD, cBuffer[100]:CHR, pAdapter:POINTER, hComboAddresses:HANDLE, WsaData:WSADATA

  DbgText "Application.CtlsSet"
  SetObject xsi
  invoke WSAStartup, 0202h, addr WsaData
  .if eax != 0
    invoke MessageBox, [xsi].hWnd, $OfsCStr("Failed to start network engine"), \
                         addr cError, MB_OK or MB_ICONERROR   ;Show error
    xor eax, eax
    ExitMethod
  .endif

  invoke GetDlgItem, [xsi].hWnd, IDC_CBO_LOCAL_HOST_ADDRESS
  mov hComboAddresses, xax
  invoke SendMessage, hComboAddresses, CB_RESETCONTENT, 0, 0 
  invoke GetAdaptersAddresses, AF_INETX, 0, NULL, NULL, addr dSize   ;Get buffer size
  MemAlloc dSize                                        ;Allocate buffer
  .if xax != NULL
    mov pAdapter, xax
    invoke GetAdaptersAddresses, AF_INETX, 0, NULL, pAdapter, addr dSize  ;Get adapter data
    .if eax == ERROR_SUCCESS
      ;Iterate adapters
      mov xbx, pAdapter
;      DbgStrW [xbx].IP_ADAPTER_ADDRESSES.DnsSuffix
;      DbgStrW [xbx].IP_ADAPTER_ADDRESSES.Description
;      DbgStrW [xbx].IP_ADAPTER_ADDRESSES.FriendlyName
      .while xbx != NULL
        mov xdi, [xbx].IP_ADAPTER_ADDRESSES.FirstUnicastAddress
        ;Iterate unicast addresses
        .while xdi != NULL
          invoke getnameinfo, [xdi].IP_ADAPTER_UNICAST_ADDRESS.Address.lpSockaddr, \
                              [xdi].IP_ADAPTER_UNICAST_ADDRESS.Address.iSockaddrLength, \
                              addr cBuffer, sizeof cBuffer, \
                              NULL, 0, \
                              NI_NUMERICHOST
          invoke SendMessage, hComboAddresses, CB_ADDSTRING, 0, addr cBuffer
          mov xdi, [xdi].IP_ADAPTER_UNICAST_ADDRESS.Next  ;Next unicast address
        .endw
        mov xbx, [xbx].IP_ADAPTER_ADDRESSES.Next        ;Next adapter
      .endw
    .endif
    MemFree pAdapter                                    ;Free allocated memory buffer
  .endif

  invoke WSACleanup                                     ;Shutdown WinSock


  movzx eax, [xsi].wLocalHostPort
  invoke SetDlgItemInt, [xsi].hWnd, IDC_EDT_LOCAL_HOST_PORT, eax, FALSE   ;Update listening port
  
  mov xbx, $invoke(GetDlgItem, [xsi].hWnd, IDC_UDN_LOCAL_HOST_PORT)
  invoke SendMessage, xbx, UDM_SETBASE, 10, 0
  invoke SendMessage, xbx, UDM_SETRANGE32, 1, 0FFFFh
  invoke SendMessage, xbx, UDM_SETPOS32, 0, [xsi].wLocalHostPort

  movzx eax, [xsi].wDestPort
  invoke SetDlgItemInt, [xsi].hWnd, IDC_EDT_DESTINATION_PORT, eax, FALSE ;Update destination port

  mov xbx, $invoke(GetDlgItem, [xsi].hWnd, IDC_UDN_DESTINATION_PORT)
  invoke SendMessage, xbx, UDM_SETBASE, 10, 0
  invoke SendMessage, xbx, UDM_SETRANGE32, 1, 0FFFFh
  invoke SendMessage, xbx, UDM_SETPOS32, 0, [xsi].wDestPort
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.Done
; Purpose:    Finalize the application object and frees allocated resources.
; Arguments:  None.
; Return:     Nothing.

Method Application.Done, uses xsi
  SetObject xsi                                         ;Bind object context
  .ifBitSet [xsi].dFlags, APF_RUNNING
    OCall [xsi].RevProxy::NetComEngine.Done             ;Shutdown network engine
  .endif
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
    lea xbx, cBuffer
    WriteF xbx, "\`吁T\` failed to start\:", offset szAppTitle ;Prepare error message
    invoke MessageBox, 0, addr cBuffer, addr cError, MB_OK or MB_ICONERROR or MB_TASKMODAL
    invoke ExitProcess, 1                               ;Exit program with failure
  .else
    invoke LoadIcon, hInstance, offset szIcoName
    invoke SendMessage, [xsi].hWnd, WM_SETICON, ICON_BIG, xax   ;Set big icon
    invoke SendMessage, [xsi].hWnd, WM_SETICON, ICON_SMALL, xax ;Set small icon

    ;Set application caption
    invoke SetWindowText, [xsi].hWnd, offset szAppTitle
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = FALSE.

Method Application.OnInitDialog, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  DbgText "Application.OnInitDialog"
  SetObject xsi

  ;Do some visuals
  invoke GetWindowLongPtr, [xsi].hWnd, GWL_STYLE        ;Get window style
  BitClr xax, WS_MAXIMIZEBOX                            ;Remove maximize box
  invoke SetWindowLongPtr, [xsi].hWnd, GWL_STYLE, xax   ;Apply updated style

  ACall xsi.OnInitDialog, wParam, lParam                ;Call ancestor OnInitDialog
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = If an application processes this message, it should return zero.

Method Application.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  local cDestServiceName[20]:CHR

  SetObject xsi
  mov xax, wParam

  .if ax == IDC_BTN_START
    OCall xsi.CtlsGet                                   ;Read dialog controls
    .if eax != FALSE
      OCall [xsi].RevProxy::NetComEngine.Init, xsi, 3, 50, 1000, MSS_ETHERNET_IPVX ;Init network engine
      .if eax == 0
        movzx edx, [xsi].wLocalHostPort
        invoke udword2dec, addr cDestServiceName, edx   ;Convert port to string
        OCall $ObjTmpl(NetComReverseProxyProtocol)::NetComReverseProxyProtocol.Init, xsi, \
                addr cDestServiceName
        .if eax == 0
          ;Start listening
          OCall [xsi].RevProxy::NetComEngine.Listen, offset $ObjTmpl(NetComReverseProxyProtocol)
          DbgText "Reverse Proxy is running"            ;Debug message
          BitSet [xsi].dFlags, APF_RUNNING              ;Mark as running
          OCall xsi.CtlsEnable, FALSE                   ;Disable controls
        .else
          DbgWarning "Failed to initialize the Reverse Proxy protocol"  ;Warn on failure
        .endif
      .else
        DbgWarning "Failed to initialize the network engine"            ;Warn on failure
      .endif
    .endif
    xor eax, eax                                        ;Return zero

  .elseif ax == IDC_BTN_STOP
    OCall [xsi].RevProxy::NetComEngine.Done             ;Stop network engine
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

  .else
    xor eax, eax
    inc eax                                             ;Return default (unhandled)
  .endif
MethodEnd
