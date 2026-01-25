; ==================================================================================================
; Title:      SRPS_Protocol.inc
; Author:     G. Friedrich
; Version:    See SRPS.asm
; Purpose:    Protocol for a bidirectional Smart Reverse Proxy Server.
; Note:       Minimal TCP reverse proxy (forwarding) using NetCom.
; ==================================================================================================


DEFAULT_SERVER_LISTENING_PORT equ $htons(25773)


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
;
; --------------------------------------------------------------------------------------------------

SRPS_DEFAULT_LISTENING_PORT equ $htons(25772)

SRPS_CONNECTION_DATA struc
  pPeerConnection $ObjPtr(NetComConnection) ?   ;Paired connection (Client <=> Server)
SRPS_CONNECTION_DATA ends

Object NetComSrpsProtocol,, NetComProtocol
  RedefineMethod    Allocate,           $ObjPtr(NetComConnection)
  RedefineMethod    IsDataComplete?,    $ObjPtr(NetComConnection), PIO_SOCKJOB
  RedefineMethod    OnAccepted,         $ObjPtr(NetComConnection)
  RedefineMethod    OnConnected,        $ObjPtr(NetComConnection)
  RedefineMethod    OnDisconnected,     $ObjPtr(NetComConnection), DWORD
  RedefineMethod    OnError,            $ObjPtr(NetComConnection), PIO_SOCKJOB, DWORD
  RedefineMethod    ProcessData,        $ObjPtr(NetComConnection), DWORD
  RedefineMethod    Release,            $ObjPtr(NetComConnection)
  VirtualMethod     ShowErrorBox,       PSTRING, DWORD

  RedefineVariable  ListeningAddr,      {AF_INETX, SRPS_DEFAULT_LISTENING_PORT}

  DefineVariable    dUseEphemeralPort,  DWORD,      TRUE          ;Setup value
  DefineVariable    ServerLocalAddr,    NETCOMADDR, {AF_INETX, 0} ;Setup Server IP + Port
  DefineVariable    ServerRemoteAddr,   NETCOMADDR, {AF_INETX, DEFAULT_LISTENING_PORT}
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ==================================================================================================
;    NetComSrpsProtocol implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     NetComSrpsProtocol.Allocate
; Purpose:    Allocates a memory block for management data on a per connection basis.
;             Additional resources can be reserved here.
; Arguments:  Arg1: -> NetComConnection
; Return:     Zero if succeeded, otherwise an error code.

Method NetComSrpsProtocol.Allocate,, pConnection:$ObjPtr(NetComConnection)
;  DbgHex pConnection, "NetComSrpsProtocol.Allocate", "&PROTOCOL_WND_NAME"
  MemAlloc sizeof SRPS_CONNECTION_DATA, MEM_INIT_ZERO
  .if xax != NULL
    mov xcx, pConnection
    mov [xcx].$Obj(NetComConnection).pData, xax
    xor eax, eax
  .else
    OCall ErrorReport, NULL, NCSP_OUT_OF_MEMORY
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComSrpsProtocol.IsDataComplete?
; Purpose:    Determines if received data is complete.
;             Streaming proxy: any completed IO job is valid.
; Arguments:  Arg1: -> NetComConnection
; Return:     eax = This many bytes are valid buffer information.

Method NetComSrpsProtocol.IsDataComplete?,, pConnection:$ObjPtr(NetComConnection), \
                                            pIOSockJob:PIO_SOCKJOB
;  DbgHex pConnection, "NetComSrpsProtocol.IsDataComplete?", "&PROTOCOL_WND_NAME"
  mov xcx, pIOSockJob
  mov eax, [xcx].IO_SOCKJOB.dBytesConsumed              ;Send what was recieved
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComSrpsProtocol.OnAccepted
; Purpose:    An inbound connection 'accept' has completed.
;             Establish backend connection and pair both sides.
; Arguments:  Arg1: -> NetComConnection
; Return:     eax = CMD_ACCEPT_CONNECTION or CMD_REJECT_CONNECTION

Method NetComSrpsProtocol.OnAccepted, uses xbx xsi, pConnection:$ObjPtr(NetComConnection)
  DbgHex pConnection, "NetComSrpsProtocol.OnAccepted", "&PROTOCOL_WND_NAME"
  SetObject xsi
  mov xbx, [xsi].pOwner                                 ;xbx -> Application
  ;Connect to the destination Server
  OCall [xbx].$Obj(Application).RevProxy::NetComEngine.ConnectTo, xsi, \
                                                       addr [xsi].ServerRemoteAddr, \
                                                       addr [xsi].ServerLocalAddr
  .if xax == NULL
    OCall pConnection::NetComConnection.Allow, FALSE
    DbgHex pConnection, "NetComSrpsProtocol.OnAccepted - Connection rejected", "&PROTOCOL_WND_NAME"
  .else
    ;Link connections
    mov xbx, pConnection
    mov xdx, [xbx].$Obj(NetComConnection).pData
    mov [xdx].SRPS_CONNECTION_DATA.pPeerConnection, xax
    mov xdx, [xax].$Obj(NetComConnection).pData
    mov [xdx].SRPS_CONNECTION_DATA.pPeerConnection, xbx

    OCall xbx::NetComConnection.Allow, TRUE
 .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComSrpsProtocol.OnConnected
; Purpose:    An outbound connection attempt has completed.
; Arguments:  Arg1: -> NetComConnection.
; Return:     Nothing.

Method NetComSrpsProtocol.OnConnected,, pConnection:$ObjPtr(NetComConnection)
  DbgHex pConnection, "NetComSrpsProtocol.OnConnected", "&PROTOCOL_WND_NAME"
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComSrpsProtocol.OnDisconnected
; Purpose:    An established connection has been disconnected.
;             Tear down the paired connection as well.
; Arguments:  Arg1: -> NetComConnection
;             Arg2: Disconnect direction = SD_SEND/SD_RECEIVE/SD_BOTH
; Return:     Nothing.

Method NetComSrpsProtocol.OnDisconnected, uses xbx xdi, pConnection:$ObjPtr(NetComConnection), dDirection:DWORD
  DbgHex pConnection, "NetComSrpsProtocol.OnDisconnected", "&PROTOCOL_WND_NAME"
  mov xdi, pConnection
  mov xax, [xdi].$Obj(NetComConnection).pData
  mov xbx, [xax].SRPS_CONNECTION_DATA.pPeerConnection   ;xbx -> peer connection

  .if xbx != NULL
    ;Break links on both connections to avoid recursion
    mov [xax].SRPS_CONNECTION_DATA.pPeerConnection, NULL
    mov xax, [xbx].$Obj(NetComConnection).pData
    mov [xax].SRPS_CONNECTION_DATA.pPeerConnection, NULL
    DbgHex xbx, "NetComSrpsProtocol.OnDisconnected - Peer disconnect - Connection", "&PROTOCOL_WND_NAME"
    ;Disconnect peer connection
    OCall xbx::NetComConnection.Disconnect, SD_SEND     ;Graceful disconnect
    OCall xbx::NetComConnection.QueueDestroy            ;Mark for destruction
    OCall xbx::NetComConnection.Close, FALSE
    OCall xdi::NetComConnection.QueueDestroy            ;Mark for destruction
    OCall xdi::NetComConnection.Close, FALSE
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComSrpsProtocol.OnError
; Purpose:    Error notification handler.
; Arguments:  Arg1: -> NetComConnection.
;             Arg2: -> IOSockJob.
;             Arg3: WSA Error code.
; Return:     eax = Command (PROT_CMD_REJECT_CONNECTION, PROT_CMD_CLOSE, ...), if applicable.

Method NetComSrpsProtocol.OnError, uses xbx xdi xsi, pConnection:$ObjPtr(NetComConnection), \
                                                     pIOSockJob:PIO_SOCKJOB, \
                                                     dError:DWORD
  local cBuffer[1024]:CHR

  SetObject xsi
  DbgDec dError, "NetComSrpsProtocol.OnError", "&PROTOCOL_WND_NAME"

  mov xcx, pIOSockJob

  .if xcx != NULL
    movzx eax, [xcx].IO_SOCKJOB.wOperation
    mov xbx, pConnection                                  ;xbx -> connection
    .if eax == OPERATION_SOCK_ACCEPT
      .if dError == WSA_OPERATION_ABORTED
        DbgSockError "NetComSrpsProtocol.OnError - Accept WSA_OPERATION_ABORTED"
        DbgHex xdi, "pConnection"
        OCall xdi::NetComConnection.QueueDestroy
      .else
        DbgSockError "NetComEngine.Worker - Accept ERROR", dError
        DbgHex xdi, "NetComEngine.Worker - pConnection"
      .endif
      mov eax, PROT_CMD_REJECT_CONNECTION

    .elseif eax == OPERATION_SOCK_CONNECT
      mov xax, [xbx].$Obj(NetComConnection).pData
      mov xdi, [xax].SRPS_CONNECTION_DATA.pPeerConnection ;xdi -> peer connection

      ;Break links on both connections to avoid recursion
      mov [xax].SRPS_CONNECTION_DATA.pPeerConnection, NULL
      mov xax, [xdi].$Obj(NetComConnection).pData
      mov [xax].SRPS_CONNECTION_DATA.pPeerConnection, NULL

      ;Disconnect both connections
      DbgText "NetComSrpsProtocol.OnError - QueueDestroy fault connection", "&PROTOCOL_WND_NAME"
      OCall xbx::NetComConnection.QueueDestroy
      OCall xbx::NetComConnection.Close, FALSE
      DbgText "NetComSrpsProtocol.OnError - QueueDestroy peer connection", "&PROTOCOL_WND_NAME"
      OCall xdi::NetComConnection.QueueDestroy
      OCall xdi::NetComConnection.Close, FALSE
      xor eax, eax

    .elseif eax == OPERATION_SOCK_SEND
      .ifBitClr [xbx].$Obj(NetComConnection).dFlags, NCC_CLOSED
        DbgText "*****************************************************************************************************"
        DbgText "*****************************************************************************************************"

        mov xax, [xbx].$Obj(NetComConnection).pData
        mov xdi, [xax].SRPS_CONNECTION_DATA.pPeerConnection     ;xdi -> peer connection
        .if xdi != NULL
          mov [xax].SRPS_CONNECTION_DATA.pPeerConnection, NULL
          OCall xdi::NetComConnection.QueueDestroy              ;Destroy peer connection
          OCall xdi::NetComConnection.Close, TRUE
        .endif
        mov eax, PROT_CMD_DESTROY                               ;Destroy self
      .endif

    .elseif eax == OPERATION_SOCK_RECV
      .ifBitClr [xbx].$Obj(NetComConnection).dFlags, NCC_CLOSED
        DbgText "*****************************************************************************************************"
        DbgText "*****************************************************************************************************"

        mov xax, [xbx].$Obj(NetComConnection).pData
        mov xdi, [xax].SRPS_CONNECTION_DATA.pPeerConnection     ;xdi -> peer connection
        .if xdi != NULL
          mov [xax].SRPS_CONNECTION_DATA.pPeerConnection, NULL
          OCall xdi::NetComConnection.QueueDestroy              ;Destroy peer connection
          OCall xdi::NetComConnection.Close, TRUE
        .endif
        mov eax, PROT_CMD_DESTROY                               ;Destroy self
      .endif

    .else
      DbgWarning "NetComSrpsProtocol.OnError - Unknown operation", "&PROTOCOL_WND_NAME"
      DbgDec [xdx].IO_SOCKJOB.wOperation,, "&PROTOCOL_WND_NAME"
      xor eax, eax
    .endif

  .else
    ;Catch some well known errors
    mov eax, dError
    .if eax == WSAEADDRINUSE
      lea xbx, cBuffer
      mov edi, $32($invoke(htons, [xsi].ListeningAddr.NETCOMADDR.wPort))
      WriteF xbx, "¦ST ¦UD.", $OfsCStr("There is another application listening port"), edi
      OCall xsi.ShowErrorBox, addr cBuffer, dError
    .else
      lea xbx, cBuffer
      WriteF xbx, "Unhandled error"
      OCall xsi.ShowErrorBox, addr cBuffer, dError
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComSrpsProtocol.ProcessData
; Purpose:    Forwards received data to the paired connection.
; Arguments:  Arg1: -> NetComConnection
;             Arg2: Transmission length
; Return:     Positive INT32 - bytes processed.

Method NetComSrpsProtocol.ProcessData, uses xbx xdi xsi, pConnection:$ObjPtr(NetComConnection), \
                                                         TransmitionLength:DWORD
;  DbgHex pConnection, "NetComSrpsProtocol.ProcessData", "&PROTOCOL_WND_NAME"
  ?mov xdx, pConnection
  mov xsi, [xdx].$Obj(NetComConnection).pData
  mov xdi, [xsi].SRPS_CONNECTION_DATA.pPeerConnection
  .if xdi == NULL
    xor eax, eax
    ExitMethod
  .endif

  .ifBitSet [xdi].$Obj(NetComConnection).dFlags, NCC_DISCONNECTED_SEND
    DbgHex xdi, "NetComSrpsProtocol.ProcessData =!> Send Disconnected", "&PROTOCOL_WND_NAME"
    xor eax, eax
    ExitMethod
  .endif
  
  lea xbx, [xdx].$Obj(NetComConnection).RcvIOChain      ;xbx -> Sentinel from the incoming connection

  .while TRUE
    ;Get first IOJob from receive chain
    mov xax, [xbx].SDLL_SENTINEL.pFirstItem
    cmp xax, xbx
    .break .if ZERO?                                    ;Chain empty?

    ;Check if the IOJob was completed
    lea xsi, [xax - IO_HEADER_SIZE]                     ;xsi -> IO_SOCKJOB 
    test [xsi].IO_SOCKJOB.wFlags, IOF_JOB_COMPLETED
    .break .if ZERO?                                    ;IOJob receive pending?
    
    ;Remove from receive chain
    mov xdx, [xax].SDLL_ITEM.pNextItem
    mov [xbx].SDLL_SENTINEL.pFirstItem, xdx
    mov [xdx].SDLL_ITEM.pPrevItem, xbx

    OCall xdi::NetComConnection.QueueSend, addr [xsi].IO_SOCKJOB.DataBuffer, TransmitionLength

    mov xax, [xdi].$Obj(NetComConnection).pOwner
    ;Toss the received IOSockJob back in the IOJobPool
    OCall [xax].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOSockJobPool.FreeItem, xsi
    
  .endw

  xor eax, eax                                          ;Dont touch the receive chain
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComSrpsProtocol.Release
; Purpose:    Releases the memory chunk allocated with Allocate.
; Arguments:  Arg1: -> NetComConnection
; Return:     Nothing.

Method NetComSrpsProtocol.Release,, pConnection:$ObjPtr(NetComConnection)
  DbgHex pConnection, "NetComSrpsProtocol.Release", "&PROTOCOL_WND_NAME"
  ?mov xdx, pConnection
  mov xax, [xdx].$Obj(NetComConnection).pData
  MemFree xax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.NetComSrpsProtocol
; Purpose:    Shows a MessageBox displaying a message and WSA error message.
; Arguments:  Arg1: -> Message.
;             Arg2: error code.
; Return:     Nothing.

Method NetComSrpsProtocol.ShowErrorBox, uses xbx xsi, pMessage:PSTRING, dError:DWORD
  local pMsgInfo:PMSG_INFO

  SetObject xsi
  MemAlloc MSG_INFO_SIZE * sizeof(CHR)
  .if xax != NULL
    mov pMsgInfo, xax
    mov [xax].MSG_INFO.dType, MB_OK or MB_ICONERROR
    lea xbx, [xax].MSG_INFO.cBuffer
    mov [xax].MSG_INFO.pMessage, xbx
    invoke StrECopy, xbx, pMessage
    mov xbx, xax
    invoke StrECopy, xbx, offset cCRLF
    invoke StrECopy, xax, offset cCRLF
    invoke StrECopy, xax, $OfsCStr("Description: ")
    mov xbx, xax
    sub xax, pMsgInfo
    neg eax
    add eax, MSG_INFO_SIZE
    if sizeof(CHR) eq 2
      shr eax, 1
    endif
    invoke NetErr2Str, dError, xbx, eax                 ;Returns the number of CHRs written
    if sizeof(CHR) eq 2
      shl eax, 1
    endif
    add xbx, xax
    WriteF xbx, "\nError = ¦UD", dError
    mov xax, pMsgInfo
    add xbx, sizeof(CHR)
    mov [xax].MSG_INFO.pCaption, xbx
    invoke StrCopy, xbx, offset cError
    mov xax, [xsi].pOwner
    invoke PostMessage, [xax].$Obj(WinApp).hWnd, WM_SHOWMSG, pMsgInfo, NULL
  .endif
MethodEnd

endif
