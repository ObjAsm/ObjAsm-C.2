; ==================================================================================================
; Title:      NetComConnection.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of NetComConnection objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


.code

if IMPLEMENT

; ==================================================================================================
;    NetComConnection implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.Admit
; Purpose:    Performs internal setup work after an accept was detected. Depending in the argument
;             value, the connection is established or discarded.
; Arguments:  Arg1: TRUE/FALSE.
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComConnection.Admit, uses xsi, dDecision:DWORD
  SetObject xsi
;  DbgText "NetComConnection.Admit", addr [xsi].wName
  .if dDecision != FALSE
    ;Bind the NetComConnection Socket to the IOCP
    mov xcx, [xsi].pOwner                               ;xcx -> NetComConnectionPool
    mov xax, [xcx].$Obj(NetComConnectionPool).pOwner    ;xax -> NetComEngine
    invoke CreateIoCompletionPort, [xsi].hSocket, [xax].$Obj(NetComEngine).hIOCP, xsi, 0
    .if eax != 0
      invoke GetSystemTimeAsFileTime, addr [xsi].ConnStartTime
      OCall xsi.QueueReceive
    .else
      invoke WSAGetLastError
    .endif
  .else
    ;Connection rejected
    OCall xsi.QueueDestroy                              ;Mark to free => close & free
    OCall xsi.Close, FALSE
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.Close
; Purpose:    Perform a graceful/abortive disconnection of a NetCom connection sending 
;             a FIN/RST to the remote endpoint.
; Arguments:  Arg1: Abortive flag (TRUE/FALSE).
; Return:     Nothing.

Method NetComConnection.Close, uses xsi, dAbortive:DWORD
  local Linger:linger

  SetObject xsi
  .ifBitClr [xsi].dFlags, NCC_CLOSED
;    DbgText "NetComConnection.Close", addr [xsi].wName
    ;Perform a "graceful" or "abortive" disconnection of the socket sending a "FIN" or "RST"
    ;to the remote endpoint
    ?mov edx, dAbortive
    mov Linger.l_onoff, dx                              ;Linger ON/OFF
    mov Linger.l_linger, 0                              ;Wait time = 0
    invoke setsockopt, [xsi].hSocket, SOL_SOCKET, SO_LINGER, addr Linger, sizeof Linger
;    DbgCheckSockReturn "NetComConnection.Close - ERROR on SetSockOpt SO_LINGER",, addr [xsi].wName
    xBitSet [xsi].dFlags, NCC_CLOSED                    ;Set marker
    invoke closesocket, [xsi].hSocket
    mov [xsi].hSocket, INVALID_SOCKET
    OCall [xsi].pProtocol::NetComProtocol.OnClosed, xsi
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.Disconnect
; Purpose:    Disconnect writing and/or reading.
; Arguments:  Arg1: Disconnect direction = SD_RECEIVE(0)/SD_SEND(1)/SD_BOTH(2)
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComConnection.Disconnect, uses xsi, dDirection:DWORD
  local dRetValue:DWORD

  SetObject xsi
;  DbgText "NetComConnection.Disconnect", addr [xsi].wName
  mov dRetValue, NO_ERROR
  xor eax, eax
  .ifBitClr [xsi].dFlags, NCC_CLOSED
    invoke shutdown, [xsi].hSocket, dDirection            ;Send FIN to the remote host
    .if eax == NO_ERROR
      .if dDirection == SD_RECEIVE
        xBitSet [xsi].dFlags, NCC_SHUTDOWN_RCV_LOCAL
      .elseif dDirection == SD_SEND
        xBitSet [xsi].dFlags, NCC_SHUTDOWN_SND_LOCAL
      .else
        xBitSet [xsi].dFlags, NCC_SHUTDOWN_RCV_LOCAL or NCC_SHUTDOWN_SND_LOCAL
      .endif
    .else
      invoke WSAGetLastError
      mov dRetValue, eax
;      DbgCheckSockReturn "NetComConnection.Disconnect - shutdown error", eax, addr [xsi].wName
    .endif
    OCall [xsi].pProtocol::NetComProtocol.OnDisconnected, xsi, dDirection, dRetValue
  .endif
  mov eax, dRetValue
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.Done
; Purpose:    Finalize the NetComConnection object.
; Arguments:  None.
; Return:     Nothing.

Method NetComConnection.Done, uses xsi
  SetObject xsi
;  DbgText "NetComConnection.Done *******************************************************", addr [xsi].wName
  invoke DeleteCriticalSection, addr [xsi].CritSect
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.DoRcvIOJob
; Purpose:    Perform an asynchronious read operation.
; Arguments:  Arg1: -> IOSockJob.
; Return:     eax = Zero if succeeded, otherwise an error code.
; Note:       Appending the IOSockJob to the RcvIOJobChain MUST be done before calling WSARecv to
;             ensure proper sequence on an multithreaded environment!

Method NetComConnection.DoRcvIOJob, uses xbx xdi xsi, pIOJob:PIOJOB
  local dRcvFlags:DWORD

  SetObject xsi
;  DbgText "NetComConnection.DoRcvIOJob", addr [xsi].wName

  mov xdi, pIOJob
  invoke EnterCriticalSection, addr [xsi].CritSect      ;Lock for insertion
  lea xcx, [xdi].IOJOB.pNextItem                   ;Get address of SDLL_ITEM
  lea xax, [xsi].RcvIOJobChain                          ;Get address of SDLL_SENTINEL
  SDLL_Append xax, xcx                                  ;Link this IOSockJob to the IO list
  mov dRcvFlags, 0
  invoke WSARecv, [xsi].hSocket, addr [xdi].IOJOB.WSABuf, 1, \
                  addr [xdi].IOJOB.dBytesConsumed, addr dRcvFlags, xdi, NULL
  .if eax != NO_ERROR                                   ;Did read IO complete synchronously?
    invoke WSAGetLastError                              ;No, check if it is a pending state
    .if eax == ERROR_IO_PENDING
      xor eax, eax                                      ;Not an error
    .endif
  .endif

  .if eax == 0
    inc [xsi].dPendingIOJobs
    inc [xsi].dRcvQueuedIOJobs
  .endif
  mov ebx, eax

  invoke LeaveCriticalSection, addr [xsi].CritSect

  .if ebx != 0
    OCall xsi.OnError, xdi, ebx                         ;pIOJob
  .endif

  mov eax, ebx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.DoSndIOJob
; Purpose:    Perform an asynchronious write operation.
; Arguments:  Arg1: -> IOJOB.
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComConnection.DoSndIOJob, uses xbx xdi xsi, pIOJob:PIOJOB
  SetObject xsi
;  DbgText "NetComConnection.DoSndIOJob", addr [xsi].wName
  mov xdi, pIOJob
  invoke EnterCriticalSection, addr [xsi].CritSect
  invoke WSASend, [xsi].hSocket, addr [xdi].IOJOB.WSABuf, 1, \
                  addr [xdi].IOJOB.dBytesConsumed, 0, xdi, NULL
  .if eax != NO_ERROR                                   ;Did read IO complete synchronously?
    invoke WSAGetLastError                              ;No, check if it is a pending state
    .if eax == ERROR_IO_PENDING
      xor eax, eax                                      ;Not an error
    .endif
  .endif

  .if eax == 0
    inc [xsi].dPendingIOJobs
    inc [xsi].dSndQueuedIOJobs
  .endif
  mov ebx, eax

  invoke LeaveCriticalSection, addr [xsi].CritSect

  .if ebx != 0
    OCall xsi.OnError, xdi, ebx                         ;pIOJob
  .endif

  mov eax, ebx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.FreeRessources
; Purpose:    Free all ressources, including the gattered IOSockJobs.
; Arguments:  None.
; Return:     Nothing.
; Note:       This method works worhs together with Done to isolate the call DeleteCriticalSection.
;             At this point no pending IOJobs should exist!

Method NetComConnection.FreeRessources, uses xbx xdi xsi
  local pPrevItem:PSDLL_ITEM, pIOSockJobPool:$ObjPtr(NetComIOJobPool)

  SetObject xsi
;  DbgText "NetComConnection.FreeRessources", addr [xsi].wName

  OCall xsi.Close, TRUE                                 ;Abortive close if needed
  OCall [xsi].pProtocol::NetComProtocol.Release, xsi    ;Release protocol resources

  ;Iterate the RcvIOJobChain Linked List in reverse order.
  lea xbx, [xsi].RcvIOJobChain
  mov xcx, [xsi].pOwner
  m2m pIOSockJobPool, [xcx].$Obj(NetComConnectionPool).pIOSockJobPool, xax
  mov xdi, [xbx].SDLL_SENTINEL.pLastItem                ;Get the last IOSockJob
  .while xdi != xbx                                     ;Check for end of chain
    m2m pPrevItem, [xdi].SDLL_ITEM.pPrevItem, xax       ;Save prev item in pItem
    OCall pIOSockJobPool::NetComIOJobPool.FreeItem, addr [xdi - IOJOB_HEADER_SIZE]
    mov xdi, pPrevItem                                  ;Move to previos item
  .endw
  SDLL_Init xbx                                         ;Reset the linked list
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.HandleProtocolCmd
; Purpose:    Executes what the Protocoll decided.
; Arguments:  Arg1: Protocol command (PROT_CMD_xxxx).
; Return:     Nothing.

Method NetComConnection.HandleProtocolCmd, uses xsi, dProtocolCommand:DWORD
  SetObject xsi
;  DbgText "NetComConnection.HandleProtocolCmd", addr [xsi].wName
  ?mov edx, dProtocolCommand
  .if edx == PROT_CMD_NONE
  .elseif edx == PROT_CMD_DISCONNECT
    OCall xsi.Disconnect, SD_BOTH
  .elseif edx == PROT_CMD_CLOSE
    OCall xsi.Close, TRUE
  .elseif edx == PROT_CMD_DESTROY
    OCall xsi.QueueDestroy
    OCall xsi.Close, TRUE
  .else
    DbgDec dProtocolCommand, "NetComConnection.HandleProtocolCmd | Unknown protocol command",
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.Init
; Purpose:    Initializes the NetComConnection object.
; Arguments:  Arg1: -> Owner object (NetComConnectionPool).
;             Arg2: -> NetComProtocol or derived object.
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComConnection.Init, uses xsi, pOwner:POINTER, pProtocol:POINTER
  local dOption:DWORD

  SetObject xsi
  ?mov xdx, pOwner
  ACall xsi.Init, xdx
  mov [xsi].dFlags, 0
  mov [xsi].dCompletedIOJobs, 0
  mov [xsi].dPendingIOJobs, 0

  FillTextW [xsi].wName, <Connection >
  invoke xword2hexW, addr [xsi].wName[??StrSize], xsi
;  DbgText "NetComConnection.Init", addr [xsi].wName

  invoke InitializeCriticalSectionEx, addr [xsi].CritSect, 4000, 0
  m2m [xsi].pProtocol, pProtocol, xax
  lea xax, [xsi].RcvIOJobChain
  SDLL_Init xax

  OCall pProtocol::NetComProtocol.Allocate, xsi
  .if eax == 0
    ;Create a socket with WSA_FLAG_OVERLAPPED flag set! No WSAPROTOCOL_INFO and no Group
    invoke WSASocket, AF_INETX, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED
    mov [xsi].hSocket, xax
    .if xax != INVALID_SOCKET
      ;Set socket options: disable nagle's algorithm for fast reaction time
      mov dOption, 1                                  ;1 means algo disabled
      invoke setsockopt, [xsi].hSocket, IPPROTO_TCP, TCP_NODELAY, addr dOption, sizeof dOption
      DbgCheckSockReturn "NetComConnection.Init - ERROR on SetSockOpt TCP_NODELAY = 1",, addr [xsi].wName

      ;Set send buffer size to zero since we provide our own buffers
;      m2z dOption
;      invoke setsockopt, [xsi].hSocket, SOL_SOCKET, SO_SNDBUF, addr dOption, sizeof dOption
;      DbgCheckSockReturn "ERROR on SetSockOpt SO_SNDBUF = 0"
;      invoke setsockopt, [xsi].hSocket, SOL_SOCKET, SO_RCVBUF, addr dOption, sizeof dOption
;      DbgCheckSockReturn "ERROR on SetSockOpt SO_RCVBUF = 0"

      invoke MemZero, addr [xsi].ConnStartTime, sizeof FILETIME

      xor eax, eax
    .else
      invoke WSAGetLastError
      DbgOnSockError "NetComConnection.Init - Failed to create socket", eax,, addr [xsi].wName
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.OnAccepted
; Purpose:    Associates a newly accepted socket with the IOCP and queues an IOSockJob
;             of the "IOJOB_RECV" type.
; Arguments:  Arg1: -> IOSockJob. It contains in the buffer the addresses of both endpoints.
; Return:     Nothing.

Method NetComConnection.OnAccepted, uses xbx xdi xsi, pIOJob:PIOJOB
  local dRcvLstElpsdTimeSize:DWORD

  SetObject xsi
;  DbgText "NetComConnection.OnAccepted", addr [xsi].wName

  xBitClr [xsi].dFlags, NCE_ACCEPT
  xBitSet [xsi].dFlags, NCC_ACCEPTED

  ?mov xdx, pIOJob
  mov xcx, [xsi].pOwner                                 ;xcx -> NetComConnectionPool
  mov xdi, [xcx].$Obj(NetComConnectionPool).pOwner      ;xdi -> NetComEngine

  mov xbx, [xdx].IOJOB.DataBuffer.ACCEPT_DATA.pListener

  ;Updates the accepting socket with the context of the listening socket.
  invoke setsockopt, [xsi].hSocket, SOL_SOCKET, SO_UPDATE_ACCEPT_CONTEXT, \
                     addr [xbx].LISTENER.hSocket, sizeof HANDLE
  DbgCheckSockReturn "NetComConnection.OnAccepted - Error on SetSockOpt SO_UPDATE_ACCEPT_CONTEXT",, addr [xsi].wName

  mov dRcvLstElpsdTimeSize, sizeof DWORD
  invoke getsockopt, [xsi].hSocket, SOL_SOCKET, SO_CONNECT_TIME, \
                     addr [xsi].dRcvLstElpsdTime, addr dRcvLstElpsdTimeSize
  DbgCheckSockReturn "NetComConnection.OnAccepted - ERROR on OnReceived getsockopt SO_CONNECT_TIME",, addr [xsi].wName

  ;Get the address of the local endpoint
  mov xcx, pIOJob
  mov xdx, [xcx].IOJOB.WSABuf.buf
  invoke MemClone, addr [xsi].LocalAddr, addr [xdx].ACCEPT_DATA.LocalAddr, sizeof NETCOMADDR
;  DbgNetComAddrIPV4 [xsi].LocalAddr, "NetComConnection.OnAccepted - LocalAddr", addr [xsi].wName

  ;Get the address of the remote endpoint
  mov xcx, pIOJob
  mov xdx, [xcx].IOJOB.WSABuf.buf
  invoke MemClone, addr [xsi].RemoteAddr, addr [xdx].ACCEPT_DATA.RemoteAddr, sizeof NETCOMADDR
;  DbgNetComAddrIPV4 [xsi].RemoteAddr, "NetComConnection.OnAccepted - RemoteAddr", addr [xsi].wName

  OCall [xdi].$Obj(NetComEngine).IOSockJobPool::NetComIOJobPool.FreeItem, pIOJob

  ;Notify the NetComConnection's Protocol handler
  OCall [xsi].pProtocol::NetComProtocol.OnAccepted, xsi

  ;Create a new acceptor
  OCall xdi::NetComEngine.NewAcceptor, xbx, [xsi].pProtocol
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.OnConnected
; Purpose:    A connect operation has finished.
; Arguments:  Arg1: -> IOSockJob.
; Return:     Nothing.

Method NetComConnection.OnConnected, uses  xsi, pIOJob:PIOJOB
  local dSize:DWORD

  SetObject xsi
;  DbgText "NetComConnection.OnConnected", addr [xsi].wName

  xBitClr [xsi].dFlags, NCE_CONNECT
  xBitSet [xsi].dFlags, NCC_CONNECTED

  mov xcx, [xsi].pOwner
  OCall [xcx].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOJobPool.FreeItem, pIOJob
  invoke setsockopt, [xsi].hSocket, SOL_SOCKET, SO_UPDATE_CONNECT_CONTEXT, NULL, 0
;  DbgCheckSockReturn "NetComConnection.OnConnected - ERROR on SetSockOpt SO_UPDATE_CONNECT_CONTEXT"
  invoke GetSystemTimeAsFileTime, addr [xsi].ConnStartTime
  mov dSize, sizeof(NETCOMADDR)
  invoke getsockname, [xsi].hSocket, addr [xsi].LocalAddr, addr dSize
;  DbgCheckSockReturn "NetComConnection.OnConnected - getsockname",, addr [xsi].wName
;  DbgNetComAddrIPV4 [xsi].LocalAddr, "NetComConnection.OnConnected - LocalAddr", addr [xsi].wName
;  DbgNetComAddrIPV4 [xsi].RemoteAddr, "NetComConnection.OnConnected - RemoteAddr", addr [xsi].wName
  OCall [xsi].pProtocol::NetComProtocol.OnConnected, xsi
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.OnError
; Purpose:    An error condition was fired. We have to decide what to do next.
; Arguments:  Arg1: -> IOJOB.
;             Arg2: Error.
; Return:     Nothing.

Method NetComConnection.OnError, uses xbx xdi xsi, pIOJob:PIOJOB, dError:DWORD
  local dProtocolCommand:DWORD

  SetObject xsi
  mov xbx, pIOJob
  mov xdi, [xsi].pOwner                                 ;xdi -> NetComConnectionPool

  movzx eax, [xbx].IOJOB.wOperation
;  DbgDec eax, "NetComConnection.OnError Operation";, addr [xsi].wName
  .if eax == IOJOB_ACCEPT
;    DbgOnSockError "NetComConnection.OnError - Accept", dError,, addr [xsi].wName
    xBitSet [xsi].dFlags, NCE_ACCEPT
    OCall [xsi].pProtocol::NetComProtocol.OnError, xsi, xbx, dError
    mov dProtocolCommand, eax
    ;This IOSockJob must be freed before QueueDestroy
    OCall [xdi].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOJobPool.FreeItem, xbx
    OCall xsi.HandleProtocolCmd, dProtocolCommand

  .elseif eax == IOJOB_CONNECT
;    DbgOnSockError "NetComConnection.OnError - Connect", dError,, addr [xsi].wName
    xBitSet [xsi].dFlags, NCE_CONNECT
    OCall [xsi].pProtocol::NetComProtocol.OnError, xsi, xbx, dError
    mov dProtocolCommand, eax
    ;This IOSockJob must be freed before QueueDestroy
    OCall [xdi].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOJobPool.FreeItem, xbx
    OCall xsi.HandleProtocolCmd, dProtocolCommand

  .elseif eax == IOJOB_SEND
;    DbgOnSockError "NetComConnection.OnError - Send", dError,, addr [xsi].wName
    xBitSet [xsi].dFlags, NCE_SEND
    OCall [xsi].pProtocol::NetComProtocol.OnError, xsi, xbx, dError
    mov dProtocolCommand, eax
    ;This IOSockJob must be freed before QueueDestroy
    OCall [xdi].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOJobPool.FreeItem, xbx
    OCall xsi.HandleProtocolCmd, dProtocolCommand

  .elseif eax == IOJOB_RECV
;    DbgOnSockError "NetComConnection.OnError - Receive", dError,, addr [xsi].wName
    xBitSet [xsi].dFlags, NCE_RECEIVE
    OCall [xsi].pProtocol::NetComProtocol.OnError, xsi, xbx, dError
    mov dProtocolCommand, eax

    ;Note: This IOSockJob is linked to the NetComConnection RcvIOJobChain.
    ;      Remove the IOSockJob from the RcvIOJobChain and toss it into the pool.
    lea xax, [xsi].RcvIOJobChain
    SDLL_RemoveLast xax, xcx
    OCall [xdi].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOJobPool.FreeItem, xbx
    OCall xsi.HandleProtocolCmd, dProtocolCommand

  .else
    DbgOnSockError "NetComConnection.OnError - Unknown operation", dError,, addr [xsi].wName
    DbgHex [xbx].IOJOB.wOperation, "NetComConnection.OnError", addr [xsi].wName
    OCall [xdi].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOJobPool.FreeItem, xbx

  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.OnReceived
; Purpose:    A read operation has finished.
; Arguments:  Arg1: -> IOJOB.
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComConnection.OnReceived, uses xbx xdi xsi, pIOJob:PIOJOB
  local dConsumed:DWORD, dRcvLstElpsdTimeSize:DWORD

  SetObject xsi
  lock dec [xsi].dRcvQueuedIOJobs
  ?mov xdx, pIOJob
  mov xbx, [xsi].pOwner

  ;Check for special case of remote socket closure (remote sent a FIN) - end of stream
  .if [xdx].IOJOB.dBytesConsumed == 0              ;Graceful remote shutdown send
;    DbgText "NetComConnection.OnReceived - FIN", addr [xsi].wName
    ;There is no other possibility to get a zero length payload => No need to pass it
    ;to any protocol handler
    ;This IOSockJob remain in the RcvIOJobChain
    xBitSet [xsi].dFlags, NCC_SHUTDOWN_SND_REMOTE       ;Remote shutdown send
    .ifBitClr [xsi].dFlags, NCC_CLOSED
      OCall xsi.Disconnect, SD_RECEIVE                  ;Local shutdown receive
    .endif

  .else
;    DbgText "NetComConnection.OnReceived", addr [xsi].wName
    mov xdx, pIOJob
    ;We queue a new read for the one we recieve here
    OCall [xbx].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOJobPool.NewItem, IOJOB_RECV
    .if xax != NULL
      OCall xsi.DoRcvIOJob, xax                          ;Increments pending IOJobs
    .else
;      DbgText "NetComConnection.OnReceived - DoRcvIOJob failed", addr [xsi].wName
    .endif

    ;Return the number of seconds a socket has been connected.
    mov dRcvLstElpsdTimeSize, sizeof DWORD
    invoke getsockopt, [xsi].hSocket, SOL_SOCKET, SO_CONNECT_TIME, \
                       addr [xsi].dRcvLstElpsdTime, addr dRcvLstElpsdTimeSize
;    DbgCheckSockReturn "ERROR on OnReceived getsockopt SO_CONNECT_TIME",, addr [xsi].wName

    OCall [xsi].pProtocol::NetComProtocol.IsDataComplete?, xsi, pIOJob
    .if eax == ERROR_BAD_PROTOCOL || eax == ERROR_USER_QUIT
      OCall xsi.Disconnect, SD_BOTH
      OCall [xbx].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOJobPool.FreeItem, pIOJob
      OCall xsi.QueueDestroy
      OCall xsi.Close, TRUE
    .elseif eax != 0
      OCall [xsi].pProtocol::NetComProtocol.ProcessData, xsi, eax   ;Return value is the #of BYTES that can be disposed
      .if eax != 0                                        ;eax = byte count to free from IO_SOCKJOBs
        ;eax = #bytes consumed, which should be removed.
        ;Note this value could be larger than one IOSockJob buffer, meaning that it represents
        ;several IOSockJobs. Also note that the total #bytes buffered could be larger than the
        ;#bytes consumed meaning the last IOSockJob will contain some data that is not part of
        ;the complete receive and must remain buffered!
        mov dConsumed, eax
        lea xdi, [xsi].RcvIOJobChain                    ;Sentinel
        mov xbx, [xdi].SDLL_SENTINEL.pFirstItem         ;Get first item
        .while xbx != xdi && dConsumed != 0
;          DbgStr [xbx - IOJOB_HEADER_SIZE].IOJOB.WSABuf.buf
          mov edx, [xbx - IOJOB_HEADER_SIZE].IOJOB.dBytesConsumed
          .if edx <= dConsumed
            sub dConsumed, edx
            mov xcx, [xsi].pOwner
            lea xax, [xbx - IOJOB_HEADER_SIZE]             ;xax -> IOSockJob
            mov pIOJob, xax
            mov xbx, [xbx].SDLL_ITEM.pNextItem
            OCall [xcx].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOJobPool.FreeItem, pIOJob
            .break .if dConsumed == 0
          .else
            ;This is the last IOSockJob to be purged. We will be leaving some data in the buffer,
            ;so we'll need to move the buffer POINTER to the unconsumed data.
            mov ecx, dConsumed
            add [xbx - IOJOB_HEADER_SIZE].IOJOB.WSABuf.buf, xcx
            sub [xbx - IOJOB_HEADER_SIZE].IOJOB.dBytesConsumed, ecx
            .break
          .endif
        .endw
        mov [xdi].SDLL_SENTINEL.pFirstItem, xbx
        mov [xbx].SDLL_ITEM.pPrevItem, xdi
      .endif
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.OnSent
; Purpose:    A write operation has finished.
; Arguments:  Arg1: -> IOJOB.
; Return:     Nothing.

Method NetComConnection.OnSent, uses xsi, pIOJob:PIOJOB
  SetObject xsi
;  DbgText "NetComConnection.OnSent", addr [xsi].wName

  mov xdx, pIOJob
  mov eax, [xdx].IOJOB.dBytesConsumed
  lock sub [xsi].dSndQueuedIOJobs, eax

  ;If below Low-WM => clear block
  mov eax, [xsi].dSndQueuedIOJobs
  .if eax < [xsi].dSndLowWtrMrk
    xBitClr [xsi].dFlags, NCC_SND_PAUSED
  .endif

  ;Toss the completed IOSockJob back in the IOJobPool
  mov xax, [xsi].pOwner
  OCall [xax].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOJobPool.FreeItem, xdx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.QueueAccept
; Purpose:    Queues an accept IOJOB.
; Arguments:  Arg1: -> LISTENER.
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComConnection.QueueAccept, uses xbx xdi xsi, pListener:PLISTENER
  local dBytesRecieved:DWORD

  SetObject xsi
;  DbgText "NetComConnection.QueueAccept", addr [xsi].wName

  ;Allocate an IOSockJob to represent the accept IO operation
  mov xcx, [xsi].pOwner
  OCall [xcx].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOJobPool.NewItem, IOJOB_ACCEPT
  ;DbgHex xax, "NetComConnection.QueueAccept - Acceptor IOSockJob"
  .if xax == NULL
    OCall xsi.ErrorReport, NULL, WSA_NOT_ENOUGH_MEMORY
    mov eax, WSA_NOT_ENOUGH_MEMORY
    ExitMethod
  .endif
  mov xdi, xax

  invoke EnterCriticalSection, addr [xsi].CritSect

  mrm [xdi].IOJOB.DataBuffer.ACCEPT_DATA.pListener, pListener, xcx   ;xcx -> LISTENER
  mov [xdi].IOJOB.DataBuffer.ACCEPT_DATA.pConnection, xsi
  BitClr [xsi].dFlags, NCE_ACCEPT
  BitSet [xsi].dFlags, NCC_QUEUE_ACCEPT
  ;if ReceiveDataLength = 0, AcceptEx completes as soon as a connection arrives,
  ;without waiting for any data. Local and remote addresses are written into the buffer§
  invoke AcceptEx, [xcx].LISTENER.hSocket, [xsi].hSocket, [xdi].IOJOB.WSABuf.buf, 0, \
                   sizeof ACCEPT_DATA.LocalAddr, \
                   sizeof ACCEPT_DATA.RemoteAddr, \
                   addr dBytesRecieved, xdi
  .if eax != NO_ERROR                                   ;Did read IO complete synchronously?
    invoke WSAGetLastError                              ;No, check if it is a pending state
    .if eax == ERROR_IO_PENDING
      xor eax, eax                                      ;Not an error
    .endif
  .endif

  .if eax == 0
    inc [xsi].dPendingIOJobs
  .endif
  mov ebx, eax

  invoke LeaveCriticalSection, addr [xsi].CritSect

  .if ebx != 0
    OCall xsi.OnError, xdi, ebx                         ;pIOJob
  .endif

  mov eax, ebx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.QueueDestroy
; Purpose:    Mark a NetCom connection to destroy.
; Arguments:  None.
; Return:     Nothing.

Method NetComConnection.QueueDestroy, uses xsi
  SetObject xsi
;  DbgText "NetComConnection.QueueDestroy", addr [xsi].wName
  xBitSet [xsi].dFlags, NCC_QUEUE_DESTROY
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.QueueConnect
; Purpose:    Queue a connect IOJOB.
; Arguments:  Arg1: -> Remote address.
;             Arg2: -> Local address. If NULL, not binding is performed.
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComConnection.QueueConnect, uses xbx xdi xsi, pRemoteAddr:PNETCOMADDR, \
                                                        pLocalAddr:PNETCOMADDR
  local dOption:DWORD

  SetObject xsi
;  DbgText "NetComConnection.QueueConnect", addr [xsi].wName

  ;Here we can change the returning port
  mov dOption, 1
  invoke setsockopt, [xsi].hSocket, SOL_SOCKET, SO_REUSEADDR, addr dOption, sizeof dOption
;  DbgCheckSockReturn "NetComConnection.QueueConnect- ERROR on SetSockOpt SO_REUSEADDR"

  invoke MemClone, addr [xsi].RemoteAddr, pRemoteAddr, sizeof NETCOMADDR

  ;Associate a local address with the socket
  .if pLocalAddr != NULL
    invoke MemClone, addr [xsi].LocalAddr, pLocalAddr, sizeof NETCOMADDR
    invoke bind, [xsi].hSocket, pLocalAddr, sizeof NETCOMADDR
    .if eax == SOCKET_ERROR
      invoke WSAGetLastError
      DbgSockError "NetComConnection.QueueConnect - BIND result", eax,, addr [xsi].wName
      ;In this case, nothing is queued to the IOCP. ConnectEx would fail.
      ExitMethod
    .endif
  .endif

;  DbgNetComAddrIPV4 [xsi].LocalAddr, "NetComConnection.QueueConnect - LocalAddr", addr [xsi].wName
;  DbgNetComAddrIPV4 [xsi].RemoteAddr, "NetComConnection.QueueConnect - RemoteAddr", addr [xsi].wName

  mov xcx, [xsi].pOwner                               ;xcx -> NetComConnectionPool
  OCall [xcx].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOJobPool.NewItem, IOJOB_CONNECT
  .if xax == NULL
    OCall xsi.ErrorReport, NULL, WSA_NOT_ENOUGH_MEMORY
    ExitMethod
  .endif
  mov xdi, xax

  invoke EnterCriticalSection, addr [xsi].CritSect

  m2z [xdi].IOJOB.WSABuf.len                 ;Size MUST be zero
  BitClr [xsi].dFlags, NCE_CONNECT
  BitSet [xsi].dFlags, NCC_QUEUE_CONNECT
  invoke PTO_CONNECTEX ptr pConnectEx, [xsi].hSocket, pRemoteAddr, sizeof NETCOMADDR, \
                                       NULL, 0, NULL, xdi
  .if eax != NO_ERROR                                   ;Did read IO complete synchronously?
    invoke WSAGetLastError                              ;No, check if it is a pending state
    .if eax == ERROR_IO_PENDING
      xor eax, eax                                      ;Not an error
    .endif
  .endif

  .if eax == 0
    inc [xsi].dPendingIOJobs
  .endif
  mov ebx, eax

  invoke LeaveCriticalSection, addr [xsi].CritSect

  .if ebx != 0
    OCall xsi.OnError, xdi, ebx                         ;pIOJob
  .endif

  mov eax, ebx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.QueueReceive
; Purpose:    Queue a read IOJOB.
; Arguments:  None.
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComConnection.QueueReceive, uses xsi
  SetObject xsi
;  DbgText "NetComConnection.QueueReceive", addr [xsi].wName
  mov xcx, [xsi].pOwner
  OCall [xcx].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOJobPool.NewItem, IOJOB_RECV
  .if xax == NULL
    OCall xsi.ErrorReport, NULL, NCCN_OUT_OF_MEMORY
  .else
    OCall xsi.DoRcvIOJob, xax                           ;dRcvQueuedIOJobs is incr. inside DoRcvIOJob
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.QueueSend
; Purpose:    Copy the information pointed to by pData to the send buffers and queue a
;             Send operation on each one.
; Arguments:  Arg1: -> Data buffer.
;             Arg2: Data size.
; Return:     eax = Data size not queued. Zero means all was sent.

Method NetComConnection.QueueSend, uses xdi xsi, pData:POINTER, dSize:DWORD
  local dBufferSize:DWORD, pItem:PIOJOB

  SetObject xsi
;  DbgText "NetComConnection.QueueSend", addr [xsi].wName
;  mov eax, dSize
;  mov edx, [xsi].dSndHighWtrMrk
;  sub edx, [xsi].dSndQueuedIOJobs
;  .if SIGN? || ZERO?
;    xBitSet [xsi].dFlags, NCC_SND_PAUSED
;    ExitMethod                                        ;eax = dSize
;  .endif
;  mov edi, eax
;  cmp edi, edx
;  cmovg edi, edx

  mov edi, dSize

  mov xcx, [xsi].pOwner                               ;xcx -> NetComConnectionPool
  mov xdx, [xcx].$Obj(NetComConnectionPool).pIOSockJobPool  ;xdx -> NetComIOJobPool
  m2m dBufferSize, [xdx].$Obj(NetComIOJobPool).dBufferSize, eax

  .while edi != 0
    mov xcx, [xsi].pOwner                             ;xcx -> NetComConnectionPool
    OCall [xcx].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOJobPool.NewItem, IOJOB_SEND
    .if xax != NULL
      mov pItem, xax
      .if dBufferSize < edi
        ;Send a full buffer and cycle again
        m2m [xax].IOJOB.WSABuf.len, dBufferSize, edx
        invoke MemClone, [xax].IOJOB.WSABuf.buf, pData, dBufferSize
        OCall xsi.DoSndIOJob, pItem
        .break .if eax != NO_ERROR
        mov edx, dBufferSize
        sub edi, edx
        add pData, xdx
      .else
        ;Send a partially full buffer and break
        mov [xax].IOJOB.WSABuf.len, edi
        invoke MemClone, [xax].IOJOB.WSABuf.buf, pData, edi
        OCall xsi.DoSndIOJob, pItem
        .break .if eax != NO_ERROR
        xor edi, edi
        .break
      .endif
    .else
      OCall xsi.ErrorReport, NULL, NCCN_OUT_OF_MEMORY
      .break
    .endif
  .endw
  mov eax, edi
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.TryQueueReceive
; Purpose:    Tries to resume the receiving IOJobs.
; Arguments:  None.
; Return:     Nothing.

Method NetComConnection.TryQueueReceive, uses xsi
  SetObject xsi
  .ifBitClr [xsi].dFlags, NCC_RCV_PAUSED
    .if [xsi].dRcvQueuedIOJobs == 0
      OCall xsi.QueueReceive
    .endif
  .endif
MethodEnd

endif
