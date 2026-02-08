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
;              | Client o---A--        |          o<--a--                             ...
;              +--------+      |       |          |      |                          (N - n)
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

SND_MAX_RETRIES   equ   5
SND_DELAY_BASE    equ   100
;TX_DELAY = doubled each retry
;Retry 1 after 100 ms
;Retry 2 after 200 ms
;Retry 3 after 400 ms
;Retry 4 after 800 ms
;Retry 5 after 1600 ms

SRPS_CONNECTION_DATA struc
  pPeerConnection $ObjPtr(NetComConnection) ?   ;Paired connection (Client <=> Server)
  dSndRetryCount  DWORD                     ?   ;Send retry count, max: TX_MAX_RETRIES
  dRcvRetryDelay  DWORD                     ?   ;ms
SRPS_CONNECTION_DATA ends

Object NetComSrpsProtocol,, NetComProtocol
  RedefineMethod    Allocate,           $ObjPtr(NetComConnection)
  RedefineMethod    IsDataComplete?,    $ObjPtr(NetComConnection), PIO_SOCKJOB
  RedefineMethod    OnAccepted,         $ObjPtr(NetComConnection)
  RedefineMethod    OnConnected,        $ObjPtr(NetComConnection)
  RedefineMethod    OnDisconnected,     $ObjPtr(NetComConnection), DWORD, DWORD
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
  DbgSetWindowName

;  DbgText "NetComSrpsProtocol.Allocate", pDbgWndNameW
  MemAlloc sizeof SRPS_CONNECTION_DATA, MEM_INIT_ZERO
  .if xax != NULL
    mov xcx, pConnection
    mov [xcx].$Obj(NetComConnection).pData, xax
    xor eax, eax
  .else
    OCall ErrorReport, NULL, WSA_NOT_ENOUGH_MEMORY
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
  DbgSetWindowName

;  DbgText "NetComSrpsProtocol.IsDataComplete?", pDbgWndNameW
  mov xcx, pIOSockJob
  mov eax, [xcx].IO_SOCKJOB.dBytesConsumed              ;Send what was recieved
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComSrpsProtocol.OnAccepted
; Purpose:    An inbound connection 'accept' has completed.
;             Establish backend connection and pair both sides.
; Arguments:  Arg1: -> NetComConnection
; Return:     Nothing.

Method NetComSrpsProtocol.OnAccepted, uses xbx xsi, pConnection:$ObjPtr(NetComConnection)
  DbgSetWindowName

  SetObject xsi
  mov xbx, [xsi].pOwner                                 ;xbx -> Application
  ;Connect to the destination Server
  OCall [xbx].$Obj(Application).RevProxy::NetComEngine.ConnectTo, xsi, \
                                                       addr [xsi].ServerRemoteAddr, \
                                                       addr [xsi].ServerLocalAddr
;  DbgHex xax, "NetComSrpsProtocol.OnAccepted - Peer Connection", pDbgWndNameW
  .if xax == NULL
    OCall pConnection::NetComConnection.Admit, FALSE
;    DbgText "NetComSrpsProtocol.OnAccepted - Connection rejected", pDbgWndNameW
  .else
    ;Link connections
    mov xbx, pConnection
    mov xdx, [xbx].$Obj(NetComConnection).pData
    .if xax != NULL
      mov [xdx].SRPS_CONNECTION_DATA.pPeerConnection, xax
      mov xdx, [xax].$Obj(NetComConnection).pData
      mov [xdx].SRPS_CONNECTION_DATA.pPeerConnection, xbx

      OCall xbx::NetComConnection.Admit, TRUE
;      DbgText "NetComSrpsProtocol.OnAccepted - Connection admitted", pDbgWndNameW
    .else
      OCall pConnection::NetComConnection.Admit, FALSE
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComSrpsProtocol.OnConnected
; Purpose:    An outbound connection attempt has completed.
; Arguments:  Arg1: -> NetComConnection.
; Return:     Nothing.

Method NetComSrpsProtocol.OnConnected,, pConnection:$ObjPtr(NetComConnection)
  DbgSetWindowName

;  DbgText "NetComSrpsProtocol.OnConnected", pDbgWndNameW

  ;Queue a read to recognize a remote disconnect
  OCall pConnection::NetComConnection.QueueReceive
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComSrpsProtocol.OnDisconnected
; Purpose:    An established connection has been disconnected.
;             Tear down the paired connection as well.
; Arguments:  Arg1: -> NetComConnection
;             Arg2: Disconnect direction = SD_SEND/SD_RECEIVE/SD_BOTH
;             Arg3: Operation result.
; Return:     Nothing.

Method NetComSrpsProtocol.OnDisconnected, uses xbx xdi, pConnection:$ObjPtr(NetComConnection), \
                                                        dDirection:DWORD, dResult:DWORD
  DbgSetWindowName

;  DbgText "NetComSrpsProtocol.OnDisconnected", pDbgWndNameW
  mov xdi, pConnection
  mov xax, [xdi].$Obj(NetComConnection).pData
  .if xax != NULL
    mov xbx, [xax].SRPS_CONNECTION_DATA.pPeerConnection   ;xbx -> peer connection
    .if xbx != NULL
      ;Break links on both connections to avoid recursion
      mov [xax].SRPS_CONNECTION_DATA.pPeerConnection, NULL
      mov xax, [xbx].$Obj(NetComConnection).pData
      .if xax != NULL
        mov [xax].SRPS_CONNECTION_DATA.pPeerConnection, NULL
      .endif
  ;    DbgHex xbx, "NetComSrpsProtocol.OnDisconnected - Peer disconnect - Connection", pDbgWndNameW
      ;Cut peer connection
      ;Calling Disconnect(SD_SEND) will trigger a sequence of actions.
      ;First it calls disconnect and then triggers OnDisconnected for the peer connection again,
      ;what starts its seldfestruction.
      OCall xbx::NetComConnection.Disconnect, SD_SEND     ;Initiate a graceful disconnect
    .endif
  .endif

  .ifBitClr [xdi].$Obj(NetComConnection).dFlags, NCC_QUEUE_DESTROY
;    DbgText "NetComSrpsProtocol.OnDisconnected - QueueDestroy", pDbgWndNameW
    OCall xdi::NetComConnection.QueueDestroy            ;Mark for selfdestruction
    .if dResult == NO_ERROR
      OCall xdi::NetComConnection.Close, FALSE
    .else
      OCall xdi::NetComConnection.Close, TRUE
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComSrpsProtocol.OnError
; Purpose:    Error notification handler.
; Arguments:  Arg1: -> NetComConnection.
;             Arg2: -> IOSockJob.
;             Arg3: WSA Error code.
; Return:     eax = Command (PROT_CMD_NONE, PROT_CMD_DESTROY, ...).

Method NetComSrpsProtocol.OnError, uses xbx xdi xsi, pConnection:$ObjPtr(NetComConnection), \
                                                     pIOSockJob:PIO_SOCKJOB, \
                                                     dError:DWORD
  local cBuffer[1024]:CHR
  DbgSetWindowName

  SetObject xsi
;  DbgDec dError, "NetComSrpsProtocol.OnError", pDbgWndNameW

  mov xcx, pIOSockJob

  .if xcx != NULL
    movzx eax, [xcx].IO_SOCKJOB.wOperation
    mov xdi, pConnection                                ;xdi -> connection
    .if eax == OPERATION_SOCK_ACCEPT
;      DbgText "NetComSrpsProtocol.OnError - Accept", pDbgWndNameW
      mov eax, PROT_CMD_DESTROY

    .elseif eax == OPERATION_SOCK_CONNECT
;      DbgText "NetComSrpsProtocol.OnError - Connect", pDbgWndNameW
      mov xax, [xdi].$Obj(NetComConnection).pData
      .if xax != NULL
        mov xbx, [xax].SRPS_CONNECTION_DATA.pPeerConnection   ;xbx -> peer connection
        .if xbx != NULL
;          DbgText "NetComSrpsProtocol.OnError - Connect: destroy peer", pDbgWndNameW
;          DbgDec dError, "NetComSrpsProtocol.OnError", pDbgWndNameW
          ;Break links on both connections to avoid recursion
          mov [xax].SRPS_CONNECTION_DATA.pPeerConnection, NULL
          mov xax, [xbx].$Obj(NetComConnection).pData
          .if xax != NULL
            mov [xax].SRPS_CONNECTION_DATA.pPeerConnection, NULL
          .endif
          OCall xbx::NetComConnection.QueueDestroy    ;Cut peer connection
          OCall xbx::NetComConnection.Close, TRUE
        .endif
      .endif
      mov eax, PROT_CMD_DESTROY                       ;Destroy itself

    .elseif eax == OPERATION_SOCK_SEND
;      DbgText "NetComSrpsProtocol.OnError - Send", pDbgWndNameW
      mov xax, [xdi].$Obj(NetComConnection).pData
      .if xax != NULL
        mov xbx, [xax].SRPS_CONNECTION_DATA.pPeerConnection   ;xbx -> peer connection
        .if xbx != NULL
          ;Break links on both connections to avoid recursion
          mov [xax].SRPS_CONNECTION_DATA.pPeerConnection, NULL
          mov xax, [xbx].$Obj(NetComConnection).pData
          .if xax != NULL
            mov [xax].SRPS_CONNECTION_DATA.pPeerConnection, NULL
          .endif
          OCall xbx::NetComConnection.QueueDestroy    ;Cut peer connection
          OCall xbx::NetComConnection.Close, TRUE
        .endif
      .endif
      mov eax, PROT_CMD_DESTROY                       ;Destroy itself

    .elseif eax == OPERATION_SOCK_RECV
;      DbgText "NetComSrpsProtocol.OnError - Receive", pDbgWndNameW
      mov xax, [xdi].$Obj(NetComConnection).pData
      .if xax != NULL
        mov xbx, [xax].SRPS_CONNECTION_DATA.pPeerConnection   ;xbx -> peer connection
        .if xbx != NULL
          ;Break links on both connections to avoid recursion
          mov [xax].SRPS_CONNECTION_DATA.pPeerConnection, NULL
          mov xax, [xbx].$Obj(NetComConnection).pData
          .if xax != NULL
            mov [xax].SRPS_CONNECTION_DATA.pPeerConnection, NULL
          .endif
          OCall xbx::NetComConnection.QueueDestroy    ;Cut peer connection
          OCall xbx::NetComConnection.Close, TRUE
        .endif
      .endif
      mov eax, PROT_CMD_DESTROY                       ;Destroy itself

    .else
      DbgWarning "NetComSrpsProtocol.OnError - Unknown operation", pDbgWndNameW
      DbgDec [xdx].IO_SOCKJOB.wOperation,, pDbgWndNameW
      mov eax, PROT_CMD_NONE
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
  local dRemainingBytes:DWORD
  DbgSetWindowName

;  DbgText "NetComSrpsProtocol.ProcessData", pDbgWndNameW
  ?mov xdx, pConnection

  mov xsi, [xdx].$Obj(NetComConnection).pData
  .if xsi != NULL
    mov xdi, [xsi].SRPS_CONNECTION_DATA.pPeerConnection
    .if xdi != NULL
      jmp @F
    .endif
  .endif
  xor eax, eax
  ExitMethod

@@:
  .ifBitSet [xdi].$Obj(NetComConnection).dFlags, NCC_DISCONNECTED_SEND
;    DbgHex xdi, "NetComSrpsProtocol.ProcessData =!> Send Disconnected", pDbgWndNameW
    xor eax, eax
    ExitMethod
  .endif

  lea xbx, [xdx].$Obj(NetComConnection).RcvIOJobChain   ;xbx -> Sentinel from the incoming connection
  m2m dRemainingBytes, TransmitionLength, eax

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

    OCall xdi::NetComConnection.QueueSend, addr [xsi].IO_SOCKJOB.DataBuffer, [xsi].IO_SOCKJOB.dBytesConsumed
    ;Return value is the number of not queued bytes, what may be different than TransmitionLength
    sub dRemainingBytes, eax
    .if eax != 0
      ;Move the pointer inside IOJob
      mov ecx, [xsi].IO_SOCKJOB.dBytesConsumed
      sub ecx, eax
      add xcx, [xsi].IO_SOCKJOB.WSABuf.buf
      mov [xsi].IO_SOCKJOB.WSABuf.buf, xcx
      mov [xsi].IO_SOCKJOB.dBytesConsumed, eax
      .break
    .endif
    ;Toss the received IOSockJob back in the IOJobPool
    mov xax, [xdi].$Obj(NetComConnection).pOwner
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
  DbgSetWindowName

  ?mov xdx, pConnection
;  DbgText "NetComSrpsProtocol.Release", pDbgWndNameW
  mov xax, [xdx].$Obj(NetComConnection).pData
  mov [xdx].$Obj(NetComConnection).pData, NULL
  .if xax != NULL
    MemFree xax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComSrpsProtocol.ShowErrorBox
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
