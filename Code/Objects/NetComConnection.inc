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
; Method:     NetComConnection.Allow
; Purpose:    Performs internal setup work after an accept was detected. Depending in the argument
;             value, the connection is established or discarded.
; Arguments:  Arg1: TRUE/FALSE.
; Return:     Nothing.

Method NetComConnection.Allow, uses xsi, dTrueOrFalse:DWORD
  SetObject xsi
;  DbgHex xsi, "NetComConnection.Allow"
  mov xcx, [xsi].pOwner                                 ;xcx -> NetComConnectionPool
  mov xax, [xcx].$Obj(NetComConnectionPool).pOwner      ;xax -> NetComEngine
  .if dTrueOrFalse != FALSE
    ;Bind the NetComConnection Socket to the IOCP
    invoke CreateIoCompletionPort, [xsi].hSocket, [xax].$Obj(NetComEngine).hIOCP, xsi, 0
    invoke GetSystemTime, addr [xsi].ConnStartTime
    OCall xsi.QueueReceive
  .else
    ;Connection rejected
    OCall xsi.QueueDestroy                              ;Mark to free => close & free
    OCall xsi.Close, FALSE
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.Close
; Purpose:    Perform an graceful disconnection of a NetCom connection sending a FIN/RST to the
;             remote endpoint.
; Arguments:  Arg1: Abortive flag (TRUE/FALSE).
; Return:     Nothing.

Method NetComConnection.Close, uses xsi, dAbortive:DWORD
  local Linger:linger

  SetObject xsi
;  DbgHex xsi, "NetComConnection.Close"
  .ifBitClr [xsi].dFlags, NCC_CLOSED
    ;Perform a "graceful" or "abortive" disconnection of the socket sending a "FIN" or "RST"
    ;to the remote endpoint
    ?mov edx, dAbortive
    mov Linger.l_onoff, dx                              ;Linger ON/OFF
    mov Linger.l_linger, 0                              ;Wait time = 0
    invoke setsockopt, [xsi].hSocket, SOL_SOCKET, SO_LINGER, addr Linger, sizeof Linger
    DbgCheckSockReturn "NetComConnection.Close - ERROR on SetSockOpt SO_LINGER"
    xBitSet [xsi].dFlags, NCC_CLOSED                    ;Set marker
    invoke closesocket, [xsi].hSocket
    mov [xsi].hSocket, INVALID_SOCKET
    OCall [xsi].pProtocol::NetComProtocol.OnClosed, xsi
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.Disconnect
; Purpose:    Disconnect writing and/or reading.
; Arguments:  Arg1: Disconnect direction = SD_SEND/SD_RECEIVE/SD_BOTH
; Return:     Nothing.

Method NetComConnection.Disconnect, uses xsi, dDirection:DWORD
  SetObject xsi
;  DbgHex xsi, "NetComConnection.Disconnect"
  .ifBitClr [xsi].dFlags, NCC_CLOSED
    invoke shutdown, [xsi].hSocket, dDirection            ;Send FIN to the remote host
;    DbgCheckSockReturn "NetComConnection.Disconnect - shutdown error"
    .if eax == NO_ERROR
      .if dDirection == SD_RECEIVE
        xBitSet [xsi].dFlags, NCC_SHUTDOWN_RECEIVE_LOCAL
      .elseif dDirection == SD_SEND
        xBitSet [xsi].dFlags, NCC_SHUTDOWN_SEND_LOCAL
      .else
        xBitSet [xsi].dFlags, NCC_SHUTDOWN_RECEIVE_LOCAL or NCC_SHUTDOWN_SEND_LOCAL
      .endif
      OCall [xsi].pProtocol::NetComProtocol.OnDisconnected, xsi, dDirection
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.Done
; Purpose:    Finalize the NetComConnection object.
; Arguments:  None.
; Return:     Nothing.

Method NetComConnection.Done, uses xsi
  SetObject xsi
;  DbgHex xsi, "NetComConnection.Done **************************************************************"
  OCall xsi.Close, TRUE                                 ;Abortive close if needed
  OCall [xsi].pProtocol::NetComProtocol.Release, xsi    ;Release protocol resources
  invoke DeleteCriticalSection, addr [xsi].CritSect
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.DoReceive
; Purpose:    Perform an asynchronious read operation.
; Arguments:  Arg1: -> IOSockJob.
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComConnection.DoReceive, uses xdi xsi, pIOSockJob:PIO_SOCKJOB
  local dResult:DWORD, dFlags:DWORD

  SetObject xsi
;  DbgHex xsi, "NetComConnection.DoReceive"

  mov xdi, pIOSockJob
  invoke EnterCriticalSection, addr [xsi].CritSect      ;Lock for insertion
  lea xcx, [xdi].IO_SOCKJOB.pNextItem                   ;Get address of SDLL_ITEM
  lea xax, [xsi].RcvIOChain                             ;Get address of SDLL_SENTINEL
  SDLL_Append xax, xcx                                  ;Link this IOSockJob to the IO list
  mov dFlags, 0
  lock inc [xsi].dPendingIOJobs                         ;Increment before calling WSARecv 
  invoke WSARecv, [xsi].hSocket, addr [xdi].IO_SOCKJOB.WSABuf, 1, \
                  addr [xdi].IO_SOCKJOB.dBytesConsumed, addr dFlags, xdi, NULL
  mov dResult, eax
  invoke LeaveCriticalSection, addr [xsi].CritSect
  .if dResult != NO_ERROR                               ;Did read IO complete synchronously?
    invoke WSAGetLastError                              ;No, check if it is a pending state
    .if eax == ERROR_IO_PENDING
      xor eax, eax
    .else
      OCall xsi.OnError, xdi, eax                       ;pIOSockJob
    .endif
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.DoSend
; Purpose:    Perform an asynchronious write operation.
; Arguments:  Arg1: -> IO_SOCKJOB.
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComConnection.DoSend, uses xdi xsi, pIOSockJob:PIO_SOCKJOB
  SetObject xsi
;  DbgHex xsi, "NetComConnection.DoSend"
  mov xdi, pIOSockJob
  lock inc [xsi].dPendingIOJobs                         ;Increment before calling WSASend
  invoke WSASend, [xsi].hSocket, addr [xdi].IO_SOCKJOB.WSABuf, 1, \
                  addr [xdi].IO_SOCKJOB.dBytesConsumed, 0, xdi, NULL
  .if eax != NO_ERROR                                   ;Did read IO complete synchronously?
    invoke WSAGetLastError                              ;No, check if it is a pending state
    .if eax == ERROR_IO_PENDING
      xor eax, eax
    .else
      OCall xsi.OnError, xdi, eax                       ;pIOSockJob
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.FreeRcvIOJobs
; Purpose:    Free all gattered IOSockJobs.
; Arguments:  None.
; Return:     Nothing.

Method NetComConnection.FreeRcvIOJobs, uses xbx xdi xsi
  local pItem:POINTER

  SetObject xsi
;  DbgHex xsi, "NetComConnection.FreeRcvIOJobs"

  ;Iterate the RcvIOChain Linked List in reverse order.
  ;Since the socket is closed, no new IOSockJobs are queued
  lea xbx, [xsi].RcvIOChain
  mov xcx, [xsi].pOwner
  mov xdi, [xcx].$Obj(NetComConnectionPool).pIOSockJobPool
  invoke EnterCriticalSection, addr [xsi].CritSect
  ReleaseObject
  mov xsi, [xbx].SDLL_ITEM.pPrevItem                    ;Get the last IOSockJob
  .while xsi != xbx                                     ;Check for end of chain
    m2m pItem, [xsi].SDLL_ITEM.pPrevItem, xax           ;Save prev item in pItem
    sub xsi, IO_HEADER_SIZE                             ;xsi -> IO_SOCKJOB
    OCall xdi::NetComIOSockJobPool.FreeItem, xsi
    mov xsi, pItem                                      ;Move to previos item
  .endw
  SDLL_Init xbx                                         ;Reset the linked list
  SetObject xsi
  invoke LeaveCriticalSection, addr [xsi].CritSect
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.Init
; Purpose:    Initializes the NetComConnection object.
; Arguments:  Arg1: -> Owner object (NetComConnectionPool).
;             Arg2: -> NetComProtocol or derived object.
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComConnection.Init, uses xsi, pOwner:POINTER, pProtocol:POINTER
  local dOption:DWORD

;  DbgText "NetComConnection.Init"
  SetObject xsi
  ?mov xdx, pOwner
  ACall xsi.Init, xdx
  mov [xsi].dFlags, NCC_DISCONNECTED_LOCAL

  invoke InitializeCriticalSection, addr [xsi].CritSect
  m2m [xsi].pProtocol, pProtocol, xax
  lea xax, [xsi].RcvIOChain
  SDLL_Init xax

  OCall pProtocol::NetComProtocol.Allocate, xsi
  .if eax == OBJ_OK
    ;Create a socket with WSA_FLAG_OVERLAPPED flag set! No WSAPROTOCOL_INFO and no Group
    invoke WSASocket, AF_INETX, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED
    mov [xsi].hSocket, xax
    .if xax != INVALID_SOCKET
      ;Enable the Nagle algorithm for send coalescing
      mov dOption, 0                                  ;0 means algo enabled
      invoke setsockopt, [xsi].hSocket, IPPROTO_TCP, TCP_NODELAY, addr dOption, sizeof dOption
      DbgCheckSockReturn "NetComConnection.Init - ERROR on SetSockOpt TCP_NODELAY = 0"

      ;Set send buffer size to zero since we provide our own buffers
;      m2z dOption
;      invoke setsockopt, [xsi].hSocket, SOL_SOCKET, SO_SNDBUF, addr dOption, sizeof dOption
;      DbgCheckSockReturn "ERROR on SetSockOpt SO_SNDBUF = 0"
;      invoke setsockopt, [xsi].hSocket, SOL_SOCKET, SO_RCVBUF, addr dOption, sizeof dOption
;      DbgCheckSockReturn "ERROR on SetSockOpt SO_RCVBUF = 0"

      invoke MemZero, addr [xsi].ConnStartTime, sizeof SYSTEMTIME

      xor eax, eax
    .else
      invoke WSAGetLastError
      DbgOnSockError "NetComConnection.Init - Failed to create socket", eax
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.OnAccepted
; Purpose:    Associates a newly accepted socket with the IOCP and queues an IOSockJob
;             of the "OPERATION_SOCK_RECV" type.
; Arguments:  Arg1: -> IOSockJob. It contains in the buffer the addresses of both endpoints.
; Return:     Nothing.

Method NetComConnection.OnAccepted, uses xbx xdi xsi, pIOSockJob:PIO_SOCKJOB
  local dRcvLstElpsdTimeSize:DWORD

  SetObject xsi
;  DbgHex xsi, "NetComConnection.OnAccepted"

  mov [xsi].dFlags, 0                                   ;Reset all flags

  ?mov xdx, pIOSockJob
  mov xcx, [xsi].pOwner                                 ;xcx -> NetComConnectionPool
  mov xdi, [xcx].$Obj(NetComConnectionPool).pOwner      ;xdi -> NetComEngine

  mov xbx, [xdx].IO_SOCKJOB.DataBuffer.ACCEPT_DATA.pListener

  ;Updates the accepting socket with the context of the listening socket.
  invoke setsockopt, [xsi].hSocket, SOL_SOCKET, SO_UPDATE_ACCEPT_CONTEXT, \
                     addr [xbx].LISTENER.hSocket, sizeof HANDLE
  DbgCheckSockReturn "NetComConnection.OnAccepted - Error on SetSockOpt SO_UPDATE_ACCEPT_CONTEXT"

  mov dRcvLstElpsdTimeSize, sizeof DWORD
  invoke getsockopt, [xsi].hSocket, SOL_SOCKET, SO_CONNECT_TIME, \
                     addr [xsi].dRcvLstElpsdTime, addr dRcvLstElpsdTimeSize
  DbgCheckSockReturn "NetComConnection.OnAccepted - ERROR on OnReceived getsockopt SO_CONNECT_TIME"

  ;Get the address of the local endpoint
  mov xcx, pIOSockJob
  mov xdx, [xcx].IO_SOCKJOB.WSABuf.buf
  invoke MemClone, addr [xsi].LocalAddr, addr [xdx].ACCEPT_DATA.LocalAddr, \
                   sizeof NETCOMADDR
;  DbgNetComAddrIPV4 [xsi].LocalAddr, "NetComConnection.OnAccepted - LocalAddr"

  ;Get the address of the remote endpoint
  mov xcx, pIOSockJob
  mov xdx, [xcx].IO_SOCKJOB.WSABuf.buf
  invoke MemClone, addr [xsi].RemoteAddr, \
                   addr [xdx].ACCEPT_DATA.RemoteAddr, \
                   sizeof NETCOMADDR
;  DbgNetComAddrIPV4 [xsi].RemoteAddr, "NetComConnection.OnAccepted - RemoteAddr"

  OCall [xdi].$Obj(NetComEngine).IOSockJobs::NetComIOSockJobPool.FreeItem, pIOSockJob

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

Method NetComConnection.OnConnected, uses  xsi, pIOSockJob:PIO_SOCKJOB
  local dSize:DWORD

  SetObject xsi
;  DbgHex xsi, "NetComConnection.OnConnected"
  mov [xsi].dFlags, 0                                   ;Reset all flags

  mov xcx, [xsi].pOwner
  OCall [xcx].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOSockJobPool.FreeItem, pIOSockJob
  invoke setsockopt, [xsi].hSocket, SOL_SOCKET, SO_UPDATE_CONNECT_CONTEXT, NULL, 0
;  DbgCheckSockReturn "NetComConnection.OnConnected - ERROR on SetSockOpt SO_UPDATE_CONNECT_CONTEXT"
  invoke GetSystemTime, addr [xsi].ConnStartTime
  mov dSize, sizeof(NETCOMADDR)
  invoke getsockname, [xsi].hSocket, addr [xsi].LocalAddr, addr dSize
;  DbgCheckSockReturn "NetComConnection.OnConnected - getsockname"
;  DbgNetComAddrIPV4 [xsi].LocalAddr, "NetComConnection.OnConnected - LocalAddr"
;  DbgNetComAddrIPV4 [xsi].RemoteAddr, "NetComConnection.OnConnected - RemoteAddr"
  OCall [xsi].pProtocol::NetComProtocol.OnConnected, xsi
  OCall xsi.QueueReceive                                ;Queue a read to recognize a remote
MethodEnd                                               ;  disconnect

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.OnError
; Purpose:    An error condition was fired. We have to decide what to do next.
; Arguments:  Arg1: -> IO_SOCKJOB.
;             Arg2: Error.
;             Arg3: Additional Info Text.
;             Arg4: Destination Window name.
; Return:     Nothing.

Method NetComConnection.OnError, uses xbx xdi xsi, pIOSockJob:PIO_SOCKJOB, dError:DWORD
  local dProtocolCommand:DWORD

  SetObject xsi
;  DbgHex xsi, "NetComConnection.OnError"
  mov xbx, pIOSockJob
  mov xdi, [xsi].pOwner                                 ;xdi -> NetComConnectionPool

  movzx eax, [xbx].IO_SOCKJOB.wOperation
  .if eax == OPERATION_SOCK_ACCEPT
    .if dError == ERROR_OPERATION_ABORTED               ;Usual termination IO operation
      OCall [xdi].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOSockJobPool.FreeItem, xbx
      OCall xsi.QueueDestroy
      OCall xsi.Close, FALSE
    .elseif dError == WSAENOTSOCK
      OCall [xdi].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOSockJobPool.FreeItem, xbx
      .ifBitClr [xsi].dFlags, NCC_CLOSED
        OCall xsi.QueueDestroy
      .endif
    .else
      DbgOnSockError "NetComConnection.OnError - ACCEPT", dError
      xBitSet [xsi].dFlags, NCE_ACCEPT
      OCall xsi.ErrorSet, dError
      OCall [xsi].pProtocol::NetComProtocol.OnError, xsi, xbx, dError
      mov dProtocolCommand, eax
      ;Freeing of this IOJob must be done before QueueDestroy
      OCall [xdi].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOSockJobPool.FreeItem, xbx
      .if dProtocolCommand == PROT_CMD_REJECT_CONNECTION
        OCall xsi.QueueDestroy
        OCall xsi.Close, FALSE
      .endif
    .endif

  .elseif eax == OPERATION_SOCK_CONNECT
    .if dError == ERROR_OPERATION_ABORTED               ;Usual termination IO operation
      DbgOnSockError "NetComConnection.OnError - CONNECT OPERATION ABORTED", dError
      xBitClr [xsi].dFlags, NCE_CONNECT
      OCall xsi.ErrorSet, dError
      OCall [xsi].pProtocol::NetComProtocol.OnError, xsi, xbx, dError
      mov dProtocolCommand, eax
      .if dProtocolCommand == PROT_CMD_DESTROY
        OCall xsi.QueueDestroy
        OCall xsi.Close, FALSE
      .endif
    .elseif dError == WSAECONNREFUSED
      DbgOnSockError "NetComConnection.OnError - CONNECT OPERATION REFUSED", dError
      xBitClr [xsi].dFlags, NCE_CONNECT
      OCall xsi.ErrorSet, dError
      OCall [xsi].pProtocol::NetComProtocol.OnError, xsi, xbx, dError
      mov dProtocolCommand, eax
      .if dProtocolCommand == PROT_CMD_DESTROY
        OCall xsi.QueueDestroy
        OCall xsi.Close, FALSE
      .endif
    .endif
    OCall [xdi].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOSockJobPool.FreeItem, xbx

  .elseif eax == OPERATION_SOCK_SEND
    .if dError != ERROR_OPERATION_ABORTED               ;Usual termination IO operation
      .ifBitClr [xsi].dFlags, NCC_DESTROY_QUEUED
        DbgOnSockError "NetComConnection.OnError - Send", dError
        xBitSet [xsi].dFlags, NCE_SEND
        OCall xsi.ErrorSet, dError
        OCall [xsi].pProtocol::NetComProtocol.OnError, xsi, xbx, dError
        .if dProtocolCommand == PROT_CMD_DISCONNECT
          DbgOnSockError "NetComConnection.OnError - READ | Disconnect", dError
          OCall xsi.Disconnect, SD_BOTH
        .elseif dProtocolCommand == PROT_CMD_CLOSE
;          DbgOnSockError "NetComConnection.OnError - READ | Close", dError
          OCall xsi.Close, TRUE
        .elseif dProtocolCommand == PROT_CMD_DESTROY
          DbgOnSockError "NetComConnection.OnError - READ | Free", dError
          OCall xsi.QueueDestroy
          OCall xsi.Close, TRUE
        .else
          DbgOnSockError "NetComConnection.OnError - READ | Unknown protocol command", dError
          DbgHex dProtocolCommand, "NetComConnection.OnError"
        .endif
      .endif
    .endif
    OCall [xdi].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOSockJobPool.FreeItem, xbx

  .elseif eax == OPERATION_SOCK_RECV
    .if dError != ERROR_OPERATION_ABORTED               ;Usual termination IO operation
                                                        ;Don't remove the IOJob. It's RcvIOChain chained
      OCall [xsi].pProtocol::NetComProtocol.OnError, xsi, xbx, dError
      mov dProtocolCommand, eax

      .ifBitClr [xsi].dFlags, NCC_DESTROY_QUEUED
        xBitSet [xsi].dFlags, NCE_RECEIVE
        OCall xsi.ErrorSet, dError
        .if dProtocolCommand == PROT_CMD_DISCONNECT
          DbgOnSockError "NetComConnection.OnError - READ | Disconnect", dError
          OCall xsi.Disconnect, SD_BOTH
        .elseif dProtocolCommand == PROT_CMD_CLOSE
;          DbgOnSockError "NetComConnection.OnError - READ | Close", dError
          OCall xsi.Close, TRUE
        .elseif dProtocolCommand == PROT_CMD_DESTROY
          DbgOnSockError "NetComConnection.OnError - READ | Free", dError
          OCall xsi.QueueDestroy
          OCall xsi.Close, TRUE
        .else
          DbgOnSockError "NetComConnection.OnError - READ | Unknown protocol command", dError
          DbgHex dProtocolCommand, "NetComConnection.OnError"
        .endif
      .endif
    .endif
    OCall [xdi].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOSockJobPool.FreeItem, xbx

  .else
    DbgOnSockError "NetComConnection.OnError - Unknown operation", dError
    DbgHex [xbx].IO_SOCKJOB.wOperation, "NetComConnection.OnError"
    OCall [xdi].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOSockJobPool.FreeItem, xbx

  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.OnReceived
; Purpose:    A read operation has finished.
; Arguments:  Arg1: -> IO_SOCKJOB.
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComConnection.OnReceived, uses xbx xdi xsi, pIOSockJob:PIO_SOCKJOB
  local dConsumed:DWORD, dRcvLstElpsdTimeSize:DWORD

  SetObject xsi
;  DbgHex xsi, "NetComConnection.OnReceived"
  ?mov xdx, pIOSockJob
  mov xbx, [xsi].pOwner

  xBitSet [xdx].IO_SOCKJOB.wFlags, IOF_JOB_LINKED
  ;Check for special case of remote socket closure (remote sent a FIN) - end of stream
  .if [xdx].IO_SOCKJOB.dBytesConsumed == 0              ;Graceful remote shutdown send
    ;There is no other possibility to get a zero length payload => No need to pass it
    ;to any protocol handler
;    DbgText "NetComConnection.OnReceived - dBytesConsumed = 0"
    BitSet [xsi].dFlags, NCC_SHUTDOWN_SEND_REMOTE       ;Remote shutdown send
    .ifBitClr [xsi].dFlags, NCC_CLOSED
      OCall xsi.Disconnect, SD_RECEIVE                  ;Local shutdown receive
    .endif
    ;Free this last packet
    OCall [xbx].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOSockJobPool.FreeItem, pIOSockJob

  .else
    mov xdx, pIOSockJob
    ;We queue a new read for the one we recieve here
    OCall [xbx].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOSockJobPool.NewItem, \
                                                                               OPERATION_SOCK_RECV
    .if xax != NULL
      OCall xsi.DoReceive, xax                          ;Increments pending IOJobs
    .else
      DbgHex xsi, "NetComConnection.OnReceived - DoReceive failed"
    .endif

    ;Return the number of seconds a socket has been connected.
    mov dRcvLstElpsdTimeSize, sizeof DWORD
    invoke getsockopt, [xsi].hSocket, SOL_SOCKET, SO_CONNECT_TIME, \
                       addr [xsi].dRcvLstElpsdTime, addr dRcvLstElpsdTimeSize
    DbgCheckSockReturn "ERROR on OnReceived getsockopt SO_CONNECT_TIME"

    OCall [xsi].pProtocol::NetComProtocol.IsDataComplete?, xsi, pIOSockJob
    .if eax == ERROR_BAD_PROTOCOL || eax == ERROR_USER_QUIT
      OCall xsi.Disconnect, SD_BOTH
      OCall [xbx].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOSockJobPool.FreeItem, pIOSockJob
      OCall xsi.QueueDestroy
    .elseif eax != 0
      OCall [xsi].pProtocol::NetComProtocol.ProcessData, xsi, eax   ;Return value is the #of BYTES that can be disposed
      .if eax != 0                                        ;eax = byte count to free from IO_SOCKJOBs
        ;eax = #bytes consumed, which should be removed.
        ;Note this value could be larger than one IOSockJob buffer, meaning that it represents
        ;several IOSockJobs. Also note that the total #bytes buffered could be larger than the
        ;#bytes consumed meaning the last IOSockJob will contain some data that is not part of
        ;the complete receive and must remain buffered!
        mov dConsumed, eax
        lea xdi, [xsi].RcvIOChain                       ;Sentinel
        mov xbx, [xdi].SDLL_SENTINEL.pFirstItem         ;Get first item
        .while xbx != xdi && dConsumed != 0
;          DbgStr [xbx - IO_HEADER_SIZE].IO_SOCKJOB.WSABuf.buf
          mov edx, [xbx - IO_HEADER_SIZE].IO_SOCKJOB.dBytesConsumed
          .if edx <= dConsumed
            sub dConsumed, edx
            mov xcx, [xsi].pOwner
            lea xax, [xbx - IO_HEADER_SIZE]             ;xax -> IOSockJob
            mov pIOSockJob, xax
            mov xbx, [xbx].SDLL_ITEM.pNextItem
            OCall [xcx].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOSockJobPool.FreeItem,\
                                                                                      pIOSockJob
            .break .if dConsumed == 0
          .else
            ;This is the last IOSockJob to be purged. We will be leaving some data in the buffer,
            ;so we'll need to move the buffer POINTER to the unconsumed data.
            mov ecx, dConsumed
            add [xbx - IO_HEADER_SIZE].IO_SOCKJOB.WSABuf.buf, xcx
            sub [xbx - IO_HEADER_SIZE].IO_SOCKJOB.dBytesConsumed, ecx
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
; Arguments:  Arg1: -> IO_SOCKJOB.
; Return:     Nothing.

Method NetComConnection.OnSent,, pIOSockJob:PIO_SOCKJOB
  SetObject xcx
;  DbgHex xcx, "NetComConnection.OnSent"
  mov xax, [xcx].pOwner
  ;Toss the completed IOSockJob back in the IOJobPool
  OCall [xax].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOSockJobPool.FreeItem, pIOSockJob
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.QueueAccept
; Purpose:    Queues an accept IO_SOCKJOB.
; Arguments:  Arg1: -> LISTENER.
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComConnection.QueueAccept, uses xdi xsi, pListener:PLISTENER
  local dRetValue:DWORD, dBytesRecieved:DWORD

  SetObject xsi
;  DbgHex xsi, "NetComConnection.QueueAccept"
  mov dRetValue, 0

  ;Allocate an IOSockJob to represent the accept IO operation
  mov xcx, [xsi].pOwner
  OCall [xcx].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOSockJobPool.NewItem, \
                                                          OPERATION_SOCK_ACCEPT
  ;DbgHex xax, "NetComConnection.QueueAccept - Acceptor IOSockJob"
  .if xax != NULL
    mov xdi, xax
    mrm [xdi].IO_SOCKJOB.DataBuffer.ACCEPT_DATA.pListener, pListener, xcx   ;xcx -> LISTENER
    mov [xdi].IO_SOCKJOB.DataBuffer.ACCEPT_DATA.pConnection, xsi

    lock inc [xsi].dPendingIOJobs                           ;Increment before calling AcceptEx
    ;if ReceiveDataLength = 0, AcceptEx completes as soon as a connection arrives,
    ;without waiting for any data. Local and remote addresses are written into the buffer
    invoke AcceptEx, [xcx].LISTENER.hSocket, [xsi].hSocket, [xdi].IO_SOCKJOB.WSABuf.buf, 0, \
                     sizeof ACCEPT_DATA.LocalAddr, \
                     sizeof ACCEPT_DATA.RemoteAddr, \
                     addr dBytesRecieved, xdi
    .if eax == FALSE
      invoke WSAGetLastError
      mov dRetValue, eax
      .if eax == ERROR_IO_PENDING                           ;Accept is pending, which is normal
;        DbgHex xsi, "NetComConnection.QueueAccept - Connection accept pending"
      .elseif eax == WSAECONNRESET                          ;An incoming connection was indicated,
        OCall xsi.OnError, xdi, eax                         ;but was subsequently terminated by the
        ExitMethod                                          ;remote peer prior to accepting the call
      .else
        OCall xsi.OnError, xdi, eax
        ExitMethod
      .endif
    .else
;      DbgHex xsi, "NetComConnection.QueueAccept - Connection accepted immediately"
    .endif
  .else
    OCall xsi.ErrorReport, NULL, NCCN_OUT_OF_MEMORY
    mov dRetValue, WSA_NOT_ENOUGH_MEMORY
  .endif

  mov eax, dRetValue
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.QueueDestroy
; Purpose:    Mark a NetCom connection to destroy.
; Arguments:  None.
; Return:     Nothing.

Method NetComConnection.QueueDestroy
  SetObject xcx
;  DbgHex xcx, "NetComConnection.QueueDestroy"
  xBitSet [xcx].dFlags, NCC_DESTROY_QUEUED
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.QueueConnect
; Purpose:    Queue a connect IO_SOCKJOB.
; Arguments:  Arg1: -> Remote address.
;             Arg2: -> Local address. If NULL, not binding is performed.
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComConnection.QueueConnect, uses xdi xsi, pRemoteAddr:PNETCOMADDR, pLocalAddr:PNETCOMADDR
  local dOption:DWORD;, dSize:DWORD

  SetObject xsi
;  DbgHex xsi, "NetComConnection.QueueConnect"

  ;Here we can change the returning port
  mov dOption, 1
  invoke setsockopt, [xsi].hSocket, SOL_SOCKET, SO_REUSEADDR, addr dOption, sizeof dOption
;  DbgCheckSockReturn "NetComConnection.QueueConnect- ERROR on SetSockOpt SO_REUSEADDR"

  invoke MemClone, addr [xsi].RemoteAddr, pRemoteAddr, sizeof NETCOMADDR

  ;Associate a local address with the socket
  .if pLocalAddr != NULL
    invoke MemClone, addr [xsi].LocalAddr, pLocalAddr, sizeof NETCOMADDR
    invoke bind, [xsi].hSocket, pLocalAddr, sizeof NETCOMADDR
    .if eax != 0
;      DbgSockError "NetComConnection.QueueConnect - BIND result"
      ExitMethod
    .endif
  .endif

;  DbgNetComAddrIPV4 [xsi].RemoteAddr, "NetComConnection.QueueConnect - RemoteAddr"
;  DbgNetComAddrIPV4 [xsi].LocalAddr, "NetComConnection.QueueConnect - LocalAddr"

  mov xcx, [xsi].pOwner                               ;xcx -> NetComConnectionPool
  OCall [xcx].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOSockJobPool.NewItem, \
                                                                            OPERATION_SOCK_CONNECT
  .if xax == NULL
    OCall xsi.ErrorReport, NULL, NCCN_OUT_OF_MEMORY
    mov eax, -1
    ExitMethod
  .endif

  mov xdi, xax
  m2z [xdi].IO_SOCKJOB.WSABuf.len                 ;Size MUST be zero
  lock inc [xsi].dPendingIOJobs                   ;Increment before calling ConnectEx
  invoke PTO_CONNECTEX ptr pConnectEx, [xsi].hSocket, pRemoteAddr, sizeof NETCOMADDR, \
                                       NULL, 0, NULL, xdi
  .if eax == FALSE
    invoke WSAGetLastError                        ;Connectiopn pending
    .if eax == ERROR_IO_PENDING
;      DbgHex xsi, "NetComConnection.QueueConnect - Connection pending"
      xor eax, eax
      ExitMethod
    .elseif eax != NO_ERROR                       ;NO_ERROR => completed in the meantime
      DbgSockError "NetComConnection.QueueConnect - Error while connecting", eax
;      DbgHex xsi, "NetComConnection.QueueConnect - Connection with error"
      OCall xsi.OnError, xdi, eax
      ExitMethod
    .endif
  .endif
  ;Connection completed
  DbgText "NetComConnection.QueueConnect - Connection completed immediately"
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.QueueReceive
; Purpose:    Queue a read IO_SOCKJOB.
; Arguments:  None.
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComConnection.QueueReceive, uses xsi
  SetObject xsi
;  DbgHex xsi, "NetComConnection.QueueReceive"
  mov xcx, [xsi].pOwner
  OCall [xcx].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOSockJobPool.NewItem, \
                                                                             OPERATION_SOCK_RECV
  .if xax != NULL
    OCall xsi.DoReceive, xax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.QueueSend
; Purpose:    Copy the information pointed to by pData to the send buffers and queue a
;             write operation on each one.
; Arguments:  Arg1: -> Data buffer.
;             Arg2: Data size.
; Return:     eax = Data size not queued. Zero means all was sent.

Method NetComConnection.QueueSend, uses xdi xsi, pData:POINTER, dSize:DWORD
  local dBufferSize:DWORD, pItem:POINTER

  SetObject xsi
;  DbgHex xsi, "NetComConnection.QueueSend"
  mov xcx, [xsi].pOwner                               ;xcx -> NetComConnectionPool
  mov xdx, [xcx].$Obj(NetComConnectionPool).pIOSockJobPool  ;xdx -> NetComIOJobPool
  m2m dBufferSize, [xdx].$Obj(NetComIOSockJobPool).dBufferSize, eax
  mov edi, dSize
  .while edi != 0
    mov xcx, [xsi].pOwner                             ;xcx -> NetComConnectionPool
    OCall [xcx].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOSockJobPool.NewItem, \
                                                                             OPERATION_SOCK_SEND
    .if xax != NULL
      mov pItem, xax
      .if dBufferSize < edi
        ;Send a full buffer and cycle again
        m2m [xax].IO_SOCKJOB.WSABuf.len, dBufferSize, edx
        invoke MemClone, [xax].IO_SOCKJOB.WSABuf.buf, pData, dBufferSize
        OCall xsi.DoSend, pItem
        .break .if eax != 0
        mov edx, dBufferSize
        add pData, xdx
        sub edi, edx
      .else
        ;Send a partially full buffer
        mov [xax].IO_SOCKJOB.WSABuf.len, edi
        invoke MemClone, [xax].IO_SOCKJOB.WSABuf.buf, pData, edi
        OCall xsi.DoSend, pItem
        .break .if eax != 0
        xor edi, edi
      .endif
    .else
      OCall xsi.ErrorReport, NULL, NCCN_OUT_OF_MEMORY
      .break
    .endif
  .endw
  mov eax, edi
MethodEnd

endif
