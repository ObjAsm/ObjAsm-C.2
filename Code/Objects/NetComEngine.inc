; ==================================================================================================
; Title:      NetComEngine.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of NetComEngine objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


.code

if IMPLEMENT

; ==================================================================================================
;    ListenerCollection implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     ListenerCollection.DestroyItem
; Purpose:    Auxiliar function to dispose a listener from the collection. Don't call directly!
; Arguments:  Arg1: -> Listener.
; Return:     Nothing.

Method ListenerCollection.DestroyItem, uses xbx, pListener:PLISTENER
  local MyLinger:linger

  DbgText "ListenerCollection.DestroyItem"
  mov xbx, pListener
  .if xbx != NULL
    .if [xbx].LISTENER.hSocket != INVALID_SOCKET
      ;Perform an "abortive close" of the socket, just in case.
      mov MyLinger.l_onoff, 1
      m2z MyLinger.l_linger
      invoke setsockopt, [xbx].LISTENER.hSocket, SOL_SOCKET, SO_LINGER, \
                         addr MyLinger, sizeof MyLinger
      CheckSockError "ERROR on SetSockOpt SO_LINGER"
      invoke closesocket, [xbx].LISTENER.hSocket
    .endif
    MemFree xbx                                         ;Frees data from heap
  .endif
MethodEnd



; ==================================================================================================
;    NetComEngine implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     NetComEngine.ConnectionsClose
; Purpose:    Close all connections.
; Arguments:  None.
; Return:     Nothing.

Method NetComEngine.ConnectionsClose, uses xbx xdi xsi
  SetObject xsi
  LockObjectAccess [xsi].Connections                    ;ConnectionChain should not change!
    lea xdi, [xsi].ConnectionChain                      ;xdi -> SENTINEL
    mov xdx, [xdi].SDLL_SENTINEL.pFirstItem             ;Get first Item
    .while xdx != xdi
      mov xbx, [xdx].SDLL_ITEM.pNextItem
      lea xcx, [xdx - offset($Obj(NetComConnection).ChainItem)]
      OCall xcx::NetComConnection.QueueClose
      mov xdx, xbx
    .endw
  UnlockObjectAccess [xsi].Connections
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComEngine.ConnectionsDisconnect
; Purpose:    Disconnect all connections.
; Arguments:  None.
; Return:     Nothing.

Method NetComEngine.ConnectionsDisconnect, uses xbx xdi xsi
  SetObject xsi
  LockObjectAccess [xsi].Connections                    ;ConnectionChain should not change!
    lea xdi, [xsi].ConnectionChain                      ;xdi -> SENTINEL
    mov xdx, [xdi].SDLL_SENTINEL.pFirstItem             ;Get first Item
    .while xdx != xdi
      mov xbx, [xdx].SDLL_ITEM.pNextItem
      lea xcx, [xdx - offset($Obj(NetComConnection).ChainItem)]
      OCall xcx::NetComConnection.Disconnect, SD_SEND
      mov xdx, xbx
    .endw
  UnlockObjectAccess [xsi].Connections
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComEngine.ConnectionsFree
; Purpose:    Free all connections.
; Arguments:  None.
; Return:     Nothing.

Method NetComEngine.ConnectionsFree, uses xbx xdi xsi
  SetObject xsi
  LockObjectAccess [xsi].Connections                    ;ConnectionChain should not change!
    lea xdi, [xsi].ConnectionChain                      ;xdi -> SENTINEL
    mov xdx, [xax].SDLL_SENTINEL.pFirstItem             ;Get first Item
    .while xdx != xdi
      mov xbx, [xdx].SDLL_ITEM.pNextItem
      lea xcx, [xdx - offset($Obj(NetComConnection).ChainItem)]
      OCall xcx::NetComConnection.QueueFree
      mov xdx, xbx
    .endw
  UnlockObjectAccess [xsi].Connections
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComEngine.ConnectTo
; Purpose:    Create a NetComConnection, and initiate a Connect attempt.
; Arguments:  Arg1: -> Protocol object.
;             Arg2: Remote Host address.
; Return:     xax -> New NetComConnection or NULL if failed.
;             ecx = Error code.

Method NetComEngine.ConnectTo, uses xbx xsi, pProtocol:$ObjPtr(NetComProtocol), \
                                             pRemoteHostAddr:PNETCOMADDR
  SetObject xsi
  ;Allocate a NetComConnection and (re)initialize it.
  ?mov xdx, pProtocol
  OCall xsi.NewConnection, xdx
  .if xax != NULL
    mov xbx, xax
    OCall xbx::NetComConnection.QueueConnect, pRemoteHostAddr
    mov ecx, eax                                        ;ecx = error code
    mov xax, xbx                                        ;Return xax -> NetComConnection
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComEngine.Done
; Purpose:    Finalize the NetComEngine object.
; Arguments:  None.
; Return:     Nothing.

Method NetComEngine.Done, uses xbx xdi xsi
  local dThreadExitCode:DWORD

  SetObject xsi

  ;Close all connections
  mov [xsi].dShuttingDown, SDN_CLOSE_CONNECTIONS
  OCall xsi.ConnectionsClose

  ;Close listener sockets and release DataCollection structures
  OCall [xsi].Listeners::DataCollection.Done

  ;Tell NetComEngine worker to die, and wait for the death. Then shutdown the supervisor thread.
  mov [xsi].dShuttingDown, SDN_CLOSE_WORKERS
  invoke WaitForMultipleObjects, [xsi].Workers.dCount, [xsi].Workers.pItems, TRUE, 4000
  .if eax == WAIT_TIMEOUT
    DbgWarning "Abortive worker close"
    mov [xsi].dShuttingDown, SDN_QUIT_WORKERS
    invoke WaitForMultipleObjects, [xsi].Workers.dCount, [xsi].Workers.pItems, TRUE, 4000
    .if eax == WAIT_TIMEOUT
      DbgWarning "Brute force worker close"
      xor ebx, ebx
      mov xdi, [xsi].Workers.pItems
      .while ebx < [xsi].Workers.dCount
        invoke GetExitCodeThread, HANDLE ptr [xdi], addr dThreadExitCode
        .if eax != 0 && dThreadExitCode == STILL_ACTIVE
          invoke TerminateThread, HANDLE ptr [xdi], -1
          ;IMPORTANT: calling TerminateThread can left synchronization objects in an
          ;           undefined state. Don't call an Debug macro after this point,
          ;           since you can hang the server application!
        .endif
        inc ebx
        add xdi, sizeof HANDLE
      .endw
    .endif
  .endif
  OCall [xsi].Workers::XWCollection.DeleteAll

  invoke WaitForSingleObject, [xsi].hSupervisor, 4000
  .if eax == WAIT_TIMEOUT
    invoke TerminateThread, [xsi].hSupervisor, -1
  .endif

  mov [xsi].dShuttingDown, SDN_HOUSEKEEPING
  ;Destroy Events
  invoke CloseHandle, [xsi].hIOCP

  ;Clean up resource pools
  OCall [xsi].IOJobs::NetComIOSockJobPool.Done
  OCall [xsi].Connections::NetComConnectionPool.Done
  OCall [xsi].Workers::XWCollection.Done

  ;Housekeeping
  Invoke StrDispose, [xsi].pLocalHostName

  ;Shutdown WinSock
  invoke WSACleanup
  DbgText "NetComEngine.Done"
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComEngine.Init
; Purpose:    Initialize internal collections, threads, IOCP etc.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Number of accept connections.
;             Arg3: Number of preallocated connections.
;             Arg4: Number of preallocated IO_SOCKJOBs.
;             Arg5: IO socket buffer size, usually the MTU size.
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComEngine.Init, uses xbx xsi, pOwner:POINTER, dAcceptorCount:DWORD, \
                                        dAllocConnections:DWORD, dAllocIOSockJobs:DWORD, \
                                        dSockBufferSize:DWORD
  local dThreadId:DWORD, WsaData:WSADATA, SysInfo:SYSTEM_INFO
  local cLocalHostName[256]:CHR                        ;max. 256 characters
  local Hints:ADDRINFOT, pResult:PADDRINFOT

  SetObject xsi
  ACall xsi.Init, pOwner
  lea xax, [xsi].ConnectionChain
  SDLL_Init xax

  invoke WSAStartup, 0202h, addr WsaData
  .if eax != 0
    OCall xsi.ErrorReport, NULL, NCE_WINSOCK_INIT_FAILED
    DbgSockError "Failed to start WinSock 2.2"
  .else
    Override [xsi].Listeners::DataCollection.DestroyItem, ListenerCollection.DestroyItem
    m2m [xsi].dAcceptorCount, dAcceptorCount, edx

    ;Get information about the local host
    invoke GetHostName, addr cLocalHostName, lengthof cLocalHostName
    mov [xsi].pLocalHostName, $invoke(StrNew, addr cLocalHostName)

;    mov xbx, [xsi].pOwner
;    invoke MemClone, addr [xsi].LocalHostAddr, addr [xbx].$Obj(Sequencer).LocAddress, \
;                     sizeof(NETCOMADDR)

    mov Hints.ai_flags, 0
    mov Hints.ai_family, AF_INETX
    mov Hints.ai_socktype, SOCK_STREAM
    mov Hints.ai_protocol, IPPROTO_TCP
    mov Hints.ai_addrlen, 0
    mov Hints.ai_canonname, NULL
    mov Hints.ai_addr, NULL
    mov Hints.ai_next, NULL
    invoke GetAddrInfo, [xsi].pLocalHostName, NULL, addr Hints, addr pResult
    .if eax == 0 && pResult != NULL
      mov xax, pResult
      invoke MemClone, addr [xsi].LocalHostAddr, [xax].ADDRINFOT.ai_addr, \
                       DWORD ptr [xax].ADDRINFOT.ai_addrlen
      invoke FreeAddrInfo, pResult
    .endif

    ;Initialize the collections
    lea xbx, [xsi].IOJobs                               ;xbx -> NetComIOSockJobPool
    OCall xbx::NetComIOSockJobPool.Init, xsi, dAllocIOSockJobs, dSockBufferSize
    OCall [xsi].Connections::NetComConnectionPool.Init, xsi, dAllocConnections, xbx
    OCall [xsi].Listeners::DataCollection.Init, xsi, 5, 5, COL_MAX_CAPACITY
    invoke GetSystemInfo, addr SysInfo
    mrm [xsi].dWorkerCount, SysInfo.dwNumberOfProcessors, eax
    OCall [xsi].Workers::XWCollection.Init, xsi, eax, eax, eax

    ;Create the IOCP
    mov [xsi].hIOCP, $invoke(CreateIoCompletionPort, INVALID_HANDLE_VALUE, 0, 0, [xsi].dWorkerCount)
    .if xax == 0
      OCall xsi.ErrorReport, NULL, NCE_IOCP_INIT_ERROR
      DbgSockError "Failed to create the IOCP"
    .else
      ;Create one Worker Thread per available logical cpu
      mov ebx, [xsi].dWorkerCount
      test ebx, ebx
      .while !ZERO?
        invoke CreateThread, 0, 16*1024, $MethodAddr(NetComEngine.Worker), xsi, 0, addr dThreadId
        .if xax != 0
          OCall [xsi].Workers::XWCollection.Insert, xax
        .else
          OCall xsi.ErrorReport, NULL, NCE_THREAD_CREATION_FAILED
          DbgSockError "Failed to create worker thread"
          ExitMethod
        .endif
        dec ebx
      .endw

      ;Create supervisor thread
      invoke CreateThread, 0, 16*1024, $MethodAddr(NetComEngine.Supervisor), xsi, 0, addr dThreadId
      .if xax != 0
        mov [xsi].hSupervisor, xax
        xor eax, eax
      .else
        OCall xsi.ErrorReport, NULL, NCE_THREAD_CREATION_FAILED
        DbgSockError "Failed to create supervisor thread"
      .endif
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComEngine.Listen
; Purpose:    Create a "Listener" and begin listening on a port (Service) using a protocol.
; Arguments:  Arg1: -> NetComProtocol.
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComEngine.Listen, uses xbx xdi xsi, pProtocol:$ObjPtr(NetComProtocol)
  local dOption:DWORD, Hints:ADDRINFOT, pResult:PADDRINFOT, dBindResult:DWORD

  SetObject xsi

  ;Create a socket with WSA_FLAG_OVERLAPPED flag!
  MemAlloc sizeof(LISTENER)
  .if xax != NULL
    mov xbx, xax
    OCall [xsi].Listeners::DataCollection.Insert, xbx

    invoke WSASocket, AF_INETX, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED
    .if xax == INVALID_SOCKET
      OCall xsi.ErrorReport, NULL, NCE_SOCKET_CREATION_FAILED
      DbgSockError "Failed to create listener socket"
    .else
      ;DbgText "Listener socket created"
      mov [xbx].LISTENER.hSocket, xax

      ;Set socket options: disable nagle's algorithm
      m2z dOption
      invoke setsockopt, [xbx].LISTENER.hSocket, IPPROTO_TCP, TCP_NODELAY, \
                         addr dOption, sizeof dOption
      CheckSockError "ERROR on SetSockOpt TCP_NODELAY"

      mov Hints.ai_flags, AI_PASSIVE                    ;Bind to all available interfaces
      mov Hints.ai_family, AF_INETX
      mov Hints.ai_socktype, SOCK_STREAM
      mov Hints.ai_protocol, IPPROTO_TCP
      mov Hints.ai_addrlen, 0
      mov Hints.ai_canonname, NULL
      mov Hints.ai_addr, NULL
      mov Hints.ai_next, NULL
      mov xdx, pProtocol
      invoke GetAddrInfo, NULL, [xdx].$Obj(NetComProtocol).pServiceName, \
                          addr Hints, addr pResult
      mov xax, pResult
      invoke bind, [xbx].LISTENER.hSocket, [xax].ADDRINFOT.ai_addr, \
                   DWORD ptr [xax].ADDRINFOT.ai_addrlen
      mov dBindResult, eax
      invoke FreeAddrInfo, pResult
      .if dBindResult != 0
        OCall xsi.ErrorReport, NULL, NCE_LISTENER_BIND_ERROR
        DbgSockError "Failed to bind listener socket"
      .else
        DbgText "SocketAddress has been bound to listener socket"
        invoke listen, [xbx].LISTENER.hSocket, SOMAXCONN
        .if eax != 0                                    ;Zero means no error
          OCall xsi.ErrorReport, NULL, NCE_LISTENER_DOESNT_LISTEN
          DbgSockError "Listener socket failed to listen"
        .else
          DbgText "Socket is listening..."
          ;Bind the listening socket to the IOCP => necessary for acceptor
          invoke CreateIoCompletionPort, [xbx].LISTENER.hSocket, [xsi].hIOCP, \
                                         COMPLETION_KEY_LISTENER, 0
          .if eax == NULL                               ;NULL means failure
            OCall xsi.ErrorReport, NULL, NCE_LISTENER_IOCP_BIND_FAILED
            DbgSockError "Listener can not de bound to the IOCP"
          .else
            DbgText "Socket has been bound to IOCP"
            ;Queue some accept NetComConnections
            mov edi, [xsi].dAcceptorCount
            test edi, edi
            .while !ZERO?
              OCall xsi.QueueAcceptor, xbx, pProtocol
              test eax, eax
              jnz @F
              dec xdi
            .endw
            xor eax, eax
          @@:
          .endif
        .endif
      .endif
    .endif
  .else
    mov eax, -1
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComEngine.FreeConnection
; Purpose:    Release a NetComConnection.
; Arguments:  Arg1: -> NetComConnection object.
; Return:     Nothing.

Method NetComEngine.FreeConnection, uses xsi, pConnection:$ObjPtr(NetComConnection)
  SetObject xsi
  OCall pConnection::NetComConnection.OnFree
  OCall [xsi].Connections::NetComConnectionPool.FreeItem, pConnection
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComEngine.NewConnection
; Purpose:    Create a NetComConnection.
; Arguments:  Arg1: -> protocol object.
; Return:     xax -> new NetComConnection or NULL if failed.
; Notes:      This method is useful for creating sockets with arbitrary semantics.
;             Use this for 'connectionless' socket types.

Method NetComEngine.NewConnection, uses xbx xsi, pProtocol:$ObjPtr(NetComProtocol)
  SetObject xsi
  OCall [xsi].Connections::NetComConnectionPool.NewItem
  .if xax != NULL
    mov xbx, xax
    OCall xbx::NetComConnection.Init, addr [xsi].Connections, pProtocol
    .if eax == 0                                        ;Zero means success
      ;Register the socket with IOCP, because we want socket event notifications
      invoke CreateIoCompletionPort, [xbx].$Obj(NetComConnection).hSocket, [xsi].hIOCP, xbx, 0
      mov xax, xbx
    .else
      ;Failed to initialize new connection
      OCall [xsi].Connections::NetComConnectionPool.FreeItem, xbx
      xor eax, eax
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComEngine.QueueAcceptor
; Purpose:    This method allocates a new NetComConnection and enqueues an accept IOSockJob
;             using the listener protocol.
; Arguments:  Arg1: -> Listener.
;             Arg2: -> NetComProtocol.
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComEngine.QueueAcceptor, uses xbx xsi, pListener:PLISTENER, \
                                                 pProtocol:$ObjPtr(NetComProtocol)
  SetObject xsi
  OCall [xsi].Connections::NetComConnectionPool.NewItem ;Allocate a NetComConnection
  .if xax != NULL
    mov xbx, xax
    OCall xbx::NetComConnection.Init, addr [xsi].Connections, pProtocol
    OCall xbx::NetComConnection.QueueAccept, pListener, pProtocol   ;Queue the accept job
  .else
    mov eax, [xsi].dErrorCode
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComEngine.Supervisor
; Purpose:    This thread is responsible making all administrative work on the engine.
; Arguments:  None.
; Return:     Nothing.

Method NetComEngine.Supervisor, uses xbx xdi xsi
  local dConnectionTime:DWORD, dConnectionTimeSize:DWORD, SW:$Obj(StopWatch)
  local dLastBytesIn:DWORD, dLastBytesOut:DWORD, dBytesIn:DWORD, dBytesOut:DWORD, dElapsedTime:DWORD
  local pConnection:$ObjPtr(NetComConnection)

  SetObject xsi
  mov dConnectionTimeSize, sizeof dConnectionTime
  New SW::StopWatch
  OCall xax::StopWatch.Init, xsi
  m2z DWORD ptr [SW.$Obj(StopWatch).r8Resolution]
  mov DWORD ptr [SW.$Obj(StopWatch).r8Resolution + 4], 408F4000h    ;REAL8 = 1000.0
  m2z dLastBytesIn
  m2z dLastBytesOut

  .repeat
    OCall SW::StopWatch.Reset
    OCall SW::StopWatch.Start
    LockObjectAccess [xsi].$Obj(NetComEngine).Connections

      lea xdi, [xsi].ConnectionChain
      mov xbx, [xdi].SDLL_SENTINEL.pFirstItem
      .while xbx != xdi                                             ;Check for end of chain
        lea xbx, [xbx - offset $Obj(NetComConnection).ChainItem]    ;xbx -> NetComConnection instance
        mov pConnection, xbx

        .if [xbx].$Obj(NetComConnection).hSocket != INVALID_SOCKET  ;Only valid sockets
          ;Check all connections for a possible attack
          ;We want to check if a NetComConnection timeouts

;          .if [xbx].$Obj(NetComConnection).dRcvLastTime != -1           ;Only established connections
;            .if [xbx].$Obj(NetComConnection).ObjLock.dLockCount == 0    ;Skip locked connections
;              .ifBitClr [xbx].$Obj(NetComConnection).dFlags, NCC_ABORT  ;Not processed before?
;                invoke getsockopt, [xbx].$Obj(NetComConnection).hSocket, SOL_SOCKET, SO_CONNECT_TIME, \
;                                   addr dConnectionTime, addr dConnectionTimeSize
;                CheckSockError "ERROR on getsockopt SO_CONNECT_TIME"
;                mov eax, dConnectionTime
;                sub eax, [xbx].$Obj(NetComConnection).dRcvLastTime
;                mov xcx, [xbx].$Obj(NetComConnection).pProtocol
;                mov edx, [xcx].$Obj(NetComProtocol).dTimeoutRcv
;                .if edx != 0 && eax >= edx
;                  OCall xcx::NetComProtocol.OnTimeout, xbx
;                  .if eax == PROT_CMD_CLOSE
;                    OCall xbx::NetComConnection.QueueClose
;                  .endif
;                .endif
;              .endif
;            .endif
;          .endif
        .endif

        ;Check for disconnection or closure
        mov eax, [xbx].$Obj(NetComConnection).dFlags
        .ifBitClr eax, NCC_CLOSED
          .ifBitSet eax, NCC_CLOSE_MARKED
            and eax, NCC_DISCONNECTED
            .if eax == NCC_DISCONNECTED
              .if [xbx].$Obj(NetComConnection).dPendingIOJobs == 0
                OCall xbx::NetComConnection.OnClose
              .endif
            .endif
          .endif
        .endif

        mov eax, [xbx].$Obj(NetComConnection).dFlags

        ;Move to next Connection now, in case xbx is freed by the comming code
        mov xbx, POINTER ptr [xbx + offset $Obj(NetComConnection).ChainItem]

        .ifBitClr eax, NCC_FREED
          .ifBitSet eax, NCC_FREE_MARKED
            .ifBitClr eax, NCC_CLOSED
              and eax, NCC_DISCONNECTED
              .if eax == NCC_DISCONNECTED
                OCall pConnection::NetComConnection.OnClose
              .endif
            .endif
            OCall xsi.FreeConnection, pConnection
          .endif
        .endif

      .endw

    UnlockObjectAccess [xsi].$Obj(NetComEngine).Connections
    invoke Sleep, 500

    ;Compute input and output transfer rates
    OCall SW::StopWatch.Stop
    OCall SW::StopWatch.GetTime                                 ;edx should be always zero
    mov dElapsedTime, eax

    mrm dBytesIn, [xsi].dBytesIn, eax
    sub eax, dLastBytesIn                                       ;Get net value
    shl eax, 3                                                  ;Convert to bits
    m2m dLastBytesIn, dBytesIn, edx                             ;Save value
    xor edx, edx                                                ;Prep for div
    div dElapsedTime
    mov [xsi].dRateIn, eax

    mrm dBytesOut, [xsi].dBytesOut, eax
    sub eax, dLastBytesOut                                      ;Get net value
    shl eax, 3                                                  ;Convert to bits
    m2m dLastBytesOut, dBytesOut, edx                           ;Save value
    xor edx, edx                                                ;Prep for div
    div dElapsedTime
    mov [xsi].dRateOut, eax

  .until [xsi].Workers.dCount == 0

  OCall SW::StopWatch.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComEngine.Worker
; Purpose:    Here is the HEART AND SOUL of the NetComEngine.
;             This thread is responsible for waiting on IOCP completion notifications and passing
;             them to the corresponding method.
;             There can be several of these Worker threads operating asynchronously.
; Arguments:  None.
; Return:     Nothing.

Method NetComEngine.Worker, uses xbx xdi xsi
  local pIOSockJob:PIO_SOCKJOB, xCompletionKey:XWORD, dBytesTransfered:DWORD
  local dFlags:DWORD, dBytesConsumed:DWORD, dOvrResult:DWORD

  SetObject xsi
  .repeat
    ;The GetQueuedCompletionStatus API call will (if successful) return two useful pieces of
    ;information to us. One is the "completion key" of the completed IO, the other is a POINTER
    ;to the IOSockJob which represents the IO operation which (we hope) is completed.
    invoke GetQueuedCompletionStatus, [xsi].hIOCP, addr dBytesTransfered,
                                                   addr xCompletionKey,
                                                   addr pIOSockJob,         ;-> IO_SOCKJOB
                                                   250                      ;0.25 s timeout
    mov xbx, pIOSockJob
    .if xbx != NULL
      .if xCompletionKey == COMPLETION_KEY_LISTENER
        mov xdi, [xbx].IO_SOCKJOB.DataBuffer.ACCEPT_DATA.pConnection
      .else
        mov xdi, xCompletionKey                         ;xdi -> NetComConnection
      .endif

      invoke EnterCriticalSection, addr [xdi].$Obj(NetComConnection).CritSect
      ;Determine whether the operation completed successfully or not
      invoke WSAGetOverlappedResult, [xdi].$Obj(NetComConnection).hSocket, xbx, \
                                     addr dBytesConsumed, \
                                     FALSE, addr dFlags
      mov dOvrResult, eax
      ;Serialize on a per connection basis
;      LockObjectAccess [xdi].$Obj(NetComConnection)
      .if dOvrResult != FALSE
        movzx eax, [xbx].IO_SOCKJOB.wOperation
        .if eax == OPERATION_SOCK_READ
          mrm [xbx].IO_SOCKJOB.dBytesConsumed, dBytesConsumed, edx
          xBitSet [xbx].IO_SOCKJOB.wFlags, IOF_JOB_COMPLETED
          lock add [xsi].dBytesIn, edx
          OCall xdi::NetComConnection.OnRead, xbx

        .elseif eax == OPERATION_SOCK_WRITE
          mrm [xbx].IO_SOCKJOB.dBytesConsumed, dBytesConsumed, edx
          xBitSet [xbx].IO_SOCKJOB.wFlags, IOF_JOB_COMPLETED
          lock add [xsi].dBytesOut, edx
          OCall xdi::NetComConnection.OnWrite, xbx

        .elseif eax == OPERATION_SOCK_CONNECT
          xBitSet [xbx].IO_SOCKJOB.wFlags, IOF_JOB_COMPLETED
          OCall xdi::NetComConnection.OnConnect, xbx

        .elseif eax == OPERATION_SOCK_ACCEPT
          xBitSet [xbx].IO_SOCKJOB.wFlags, IOF_JOB_COMPLETED
          OCall xdi::NetComConnection.OnAccept, xbx

        .else
          xBitSet [xbx].IO_SOCKJOB.wFlags, IOF_JOB_COMPLETED
          invoke WSAGetLastError                        ;This error is thread specific
          OCall xdi::NetComConnection.OnError, xbx, eax
        .endif

      .else
        ;Operation failed!
        xBitSet [xbx].IO_SOCKJOB.wFlags, IOF_JOB_COMPLETED
        invoke WSAGetLastError                          ;This error is thread specific
        .if eax != ERROR_IO_INCOMPLETE
          OCall xdi::NetComConnection.OnError, xbx, eax
        .endif
      .endif
;      UnlockObjectAccess [xdi].$Obj(NetComConnection)
      invoke LeaveCriticalSection, addr [xdi].$Obj(NetComConnection).CritSect

    .endif

  .until ([xsi].dShuttingDown == SDN_CLOSE_WORKERS && [xsi].IOJobs.dCount == 0) || \
          [xsi].dShuttingDown == SDN_QUIT_WORKERS       ;Abortive close

;  DbgText "NetComEngine worker death"
MethodEnd

endif
