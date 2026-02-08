; ==================================================================================================
; Title:      NetComEngine.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of NetComEngine objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


.data
  pConnectEx  POINTER   NULL

if IMPLEMENT

.code
; ==================================================================================================
;    Helper
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Procedure:  WsaErrBox
; Purpose:    Auxiliar procedure to to show a WSA error
; Arguments:  Arg1: Parent Window Hnadle.
;             Arg2: -> Message.
;             Arg3: -> Caption.
;             Arg4: MessageBox options.
;             Arg5: WSA Error Code.
; Return:     MessageBox return value.

WsaErrBox proc uses xbx hParent:HWND, pMessage:PSTRING, pCaption:PSTRING, \
                                      dOptions:DWORD, dError:DWORD
  local cBuffer[4096]:CHR

  lea xbx, cBuffer
  invoke StrECopy, xbx, pMessage
  invoke StrECopy, xax, offset cCRLF
  invoke StrECopy, xax, offset cCRLF
  invoke StrECopy, xax, $OfsCStr("Description: ")
  mov xdx, xax
  sub xax, xbx
  mov xbx, xdx
  neg xax
  add xax, sizeof cBuffer
  if sizeof(CHR) eq 2
    shr eax, 1
  endif
  invoke NetErr2Str, dError, xdx, eax                 ;Returns the number of CHRs written
  if sizeof(CHR) eq 2
    shl eax, 1
  endif
  add xbx, xax
  WriteF xbx, "\nError = ¦UD", dError
  invoke MessageBox, hParent, addr cBuffer, pCaption, dOptions
  ret
WsaErrBox endp


; ==================================================================================================
;    ListenerCollection implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     ListenerCollection.DestroyItem
; Purpose:    Auxiliar function to dispose a listener from the collection. Don't call directly!
; Arguments:  Arg1: -> Listener.
; Return:     Nothing.

Method ListenerCollection.DestroyItem, uses xbx, pListener:PLISTENER
  local Linger:linger

  DbgText "ListenerCollection.DestroyItem"
  mov xbx, pListener
  .if xbx != NULL
    .if [xbx].LISTENER.hSocket != INVALID_SOCKET
      ;Perform an "abortive close" of the socket, just in case.
      mov Linger.l_onoff, 1
      mov Linger.l_linger, 0
      invoke setsockopt, [xbx].LISTENER.hSocket, SOL_SOCKET, SO_LINGER, \
                         addr Linger, sizeof Linger
      DbgOnSockError "ListenerCollection.DestroyItem - ERROR on SetSockOpt SO_LINGER"
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
; Purpose:    Closes all connections.
; Arguments:  None.
; Return:     Nothing.

Method NetComEngine.ConnectionsClose, uses xbx xdi xsi
  SetObject xsi
  LockObjectAccess [xsi].ConnectionPool                 ;ConnectionChain should not change!
  lea xdi, [xsi].ConnectionChain                        ;xdi -> SENTINEL
  mov xbx, [xdi].SDLL_SENTINEL.pFirstItem               ;Get first item
  .while xbx != xdi                                     ;Empty?
    lea xcx, [xbx - offset($Obj(NetComConnection).ChainItem)]
    mov xbx, [xbx].SDLL_ITEM.pNextItem                  ;Move to next item
    OCall xcx::NetComConnection.Close, FALSE
  .endw
  UnlockObjectAccess [xsi].ConnectionPool
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComEngine.ConnectionsDestroy
; Purpose:    Destroy all connections.
; Arguments:  None.
; Return:     Nothing.

Method NetComEngine.ConnectionsDestroy, uses xbx xdi xsi
  local pConnection:$ObjPtr(NetComConnection)

  SetObject xsi
  LockObjectAccess [xsi].ConnectionPool                 ;ConnectionChain should not change!
  lea xdi, [xsi].ConnectionChain                        ;xdi -> SENTINEL
  mov xbx, [xdi].SDLL_SENTINEL.pFirstItem               ;Get first item
  .while xbx != xdi                                     ;Empty?
    lea xcx, [xbx - offset($Obj(NetComConnection).ChainItem)]
    mov pConnection, xcx
    mov xbx, [xbx].SDLL_ITEM.pNextItem                  ;Move to next item
    OCall pConnection::NetComConnection.QueueDestroy
  .endw
  SDLL_Init xdi                                         ;Reset the chain
  UnlockObjectAccess [xsi].ConnectionPool
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComEngine.ConnectionsDisconnect
; Purpose:    Disconnects all connections.
; Arguments:  None.
; Return:     Nothing.

Method NetComEngine.ConnectionsDisconnect, uses xbx xdi xsi
  SetObject xsi
  LockObjectAccess [xsi].ConnectionPool                 ;ConnectionChain should not change!
  lea xdi, [xsi].ConnectionChain                        ;xdi -> SENTINEL
  mov xdx, [xdi].SDLL_SENTINEL.pFirstItem               ;Get first Item
  .while xdx != xdi
    mov xbx, [xdx].SDLL_ITEM.pNextItem
    lea xcx, [xdx - offset($Obj(NetComConnection).ChainItem)]
    OCall xcx::NetComConnection.Disconnect, SD_SEND
    mov xdx, xbx
  .endw
  UnlockObjectAccess [xsi].ConnectionPool
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComEngine.ConnectTo
; Purpose:    Creates a NetComConnection and initiates a Connect attempt.
; Arguments:  Arg1: -> Protocol object.
;             Arg2: -> Remote address.
;             Arg2: -> Local address.
; Return:     xax -> New NetComConnection or NULL if failed.

Method NetComEngine.ConnectTo, uses xbx xsi, pProtocol:$ObjPtr(NetComProtocol), \
                                             pRemoteAddr:PNETCOMADDR, pLocalAddr:PNETCOMADDR
  SetObject xsi
  ;Get a new NetComConnection and (re)initialize it.
  ?mov xdx, pProtocol
  OCall xsi.NewConnection, xdx
  .if xax != NULL
    mov xbx, xax
    OCall xbx::NetComConnection.QueueConnect, pRemoteAddr, pLocalAddr
    .if eax != NO_ERROR
      ;If we have an error here, nothing was queued, so we can dispose our connection safely
      OCall xbx::NetComConnection.FreeRessources
      OCall xbx::NetComConnection.Done
      OCall [xsi].ConnectionPool::NetComConnectionPool.FreeItem, xbx
      xor eax, eax
    .else
      mov xax, xbx                                        ;Return xax -> NetComConnection
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComEngine.Done
; Purpose:    Finalizes the NetComEngine object.
; Arguments:  None.
; Return:     Nothing.

Method NetComEngine.Done, uses xbx xdi xsi
  local dThreadExitCode:DWORD

  SetObject xsi
;  DbgText "NetComEngine.Done"
  ;Cut all connections
  DbgLine2
;  OCall xsi.ConnectionsDisconnect
;  OCall xsi.ConnectionsDestroy

  ;Close listener sockets and release DataCollection structures
  OCall [xsi].Listeners::DataCollection.Done

  ;Tell NetComEngine worker to die, and wait for the death. Then shutdown the supervisor thread.
  DbgText "NetComEngine.Done - Closing Workers"
  .ColForEach [xsi].Workers, edi
    invoke PostQueuedCompletionStatus, [xsi].hIOCP, 0, COMPLETION_KEY_KILL_WORKER, NULL
  .ColNext

  invoke WaitForMultipleObjects, [xsi].Workers.dCount, [xsi].Workers.pItems, TRUE, 4000
  .if eax == WAIT_TIMEOUT
    DbgWarning "NetComEngine.Done - Brute force worker close"
    .ColForEach [xsi].Workers
      mov xdi, xax

      invoke GetExitCodeThread, xdi, addr dThreadExitCode
      .if eax != 0 && dThreadExitCode == STILL_ACTIVE
        invoke TerminateThread, xdi, -1
        ;IMPORTANT: calling TerminateThread can left synchronization objects in an
        ;           undefined state. Don't call an Debug macro after this point,
        ;           since you can hang the server application!
      .endif
    .ColNext
  .endif

  if DEBUGGING
    lea xdi, [xsi].ConnectionChain                        ;xdi -> SENTINEL
    mov xbx, [xdi].SDLL_SENTINEL.pFirstItem               ;Get first Item
    .while xbx != xdi                                     ;Empty?
      lea xcx, [xbx - offset($Obj(NetComConnection).ChainItem)]
      mov xbx, [xbx].SDLL_ITEM.pNextItem
      DbgConnection xcx
    .endw
  endif


  OCall [xsi].Workers::XWCollection.Done

  OCall [xsi].pSupervisor::NetComSupervisor.Done

  ;Destroy IOCP
  invoke CloseHandle, [xsi].hIOCP

  ;Clean up resource pools
  OCall [xsi].IOSockJobPool::NetComIOSockJobPool.Done
  OCall [xsi].ConnectionPool::NetComConnectionPool.Done

  ;Housekeeping
  Invoke StrDispose, [xsi].pLocalHostName
  DbgText "NetComEngine.Done"
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComEngine.Init
; Purpose:    Initializes internal collections, threads, IOCP etc.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> Supervisor.
;             Arg3: Number of preallocated connections.
;             Arg4: Number of preallocated IO_SOCKJOBs.
;             Arg5: IO socket buffer size, usually the "Maximum Segment Size" (MSS).
; Return:     eax = 0 if succeeded, otherwise an error code.

Method NetComEngine.Init, uses xbx xsi, pOwner:POINTER, pSupervisor:POINTER, \
                                        dAllocConnections:DWORD, dAllocIOSockJobs:DWORD, \
                                        dSockBufferSize:DWORD
  local dRetValue:DWORD, SysInfo:SYSTEM_INFO, cLocalHostName[256]:CHR    ;Max. 256 characters

  SetObject xsi

  mov dRetValue, NO_ERROR
  m2m [xsi].pSupervisor, pSupervisor, xax
  ACall xsi.Init, pOwner

  lea xax, [xsi].ConnectionChain
  SDLL_Init xax

  ;Override Listeners methods
  Override [xsi].Listeners::DataCollection.DestroyItem, ListenerCollection.DestroyItem

  ;Get the local host name
  invoke GetHostName, addr cLocalHostName, lengthof cLocalHostName
  mov [xsi].pLocalHostName, $invoke(StrNew, addr cLocalHostName)

  ;Initialize the collections
  lea xbx, [xsi].IOSockJobPool                             ;xbx -> NetComIOSockJobPool
  OCall xbx::NetComIOSockJobPool.Init, xsi, dAllocIOSockJobs, dSockBufferSize
  OCall [xsi].ConnectionPool::NetComConnectionPool.Init, xsi, dAllocConnections, xbx
  OCall [xsi].Listeners::DataCollection.Init, xsi, 5, 5, COL_MAX_CAPACITY
  invoke GetSystemInfo, addr SysInfo
  mrm [xsi].dWorkerCount, SysInfo.dwNumberOfProcessors, eax   ;Number of logical processors
;  mrm [xsi].dWorkerCount, 1, eax
  OCall [xsi].Workers::XWCollection.Init, xsi, eax, 0, eax

  ;Create the IOCP
  mov [xsi].hIOCP, $invoke(CreateIoCompletionPort, INVALID_HANDLE_VALUE, 0, 0, [xsi].dWorkerCount)
  .if xax == 0
    OCall xsi.ErrorReport, NULL, NCE_IOCP_INIT_ERROR
    mov dRetValue, $32($invoke(WSAGetLastError))
    DbgSockError "NetComEngine.Init - Failed to create the IOCP", dRetValue
    jmp @@Exit
  .endif

  ;Init supervisor
  OCall pSupervisor::NetComSupervisor.Init, xsi

  ;Create a Worker Thread per available "logical" cpu
  mov ebx, [xsi].dWorkerCount
  test ebx, ebx
  .while !ZERO?
    invoke CreateThread, 0, 16*1024, $MethodAddr(NetComEngine.Worker), xsi, 0, NULL
    .if xax == 0
      mov dRetValue, $32($invoke(GetLastError))
      OCall xsi.ErrorReport, NULL, NCE_THREAD_CREATION_FAILED
      DbgSockError "NetComEngine.Init - Failed to create worker thread", dRetValue
      jmp @@Exit
    .endif
    DbgHex xax, "NetComEngine.Init - New Worker"
    OCall [xsi].Workers::XWCollection.Insert, xax
    dec ebx
  .endw

@@Exit:
  mov eax, dRetValue
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComEngine.NewAcceptor
; Purpose:    Creates a new NetComConnection and enqueues an accept IOSockJob using a new protocol.
; Arguments:  Arg1: -> Listener.
;             Arg2: -> NetComProtocol.
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComEngine.NewAcceptor, uses xbx xsi, pListener:PLISTENER, pProtocol:$ObjPtr(NetComProtocol)
  SetObject xsi
  OCall [xsi].ConnectionPool::NetComConnectionPool.NewItem ;Get a new NetComConnection from the pool
  .if xax == NULL
    mov eax, WSA_NOT_ENOUGH_MEMORY
  .else
    mov xbx, xax
    OCall xbx::NetComConnection.Init, addr [xsi].ConnectionPool, pProtocol
    OCall xbx::NetComConnection.QueueAccept, pListener  ;Queue the accept job
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComEngine.NewConnection
; Purpose:    Creates a NetComConnection.
; Arguments:  Arg1: -> protocol object.
; Return:     xax -> new NetComConnection or NULL if failed.
; Notes:      This method is useful for creating sockets with arbitrary semantics.
;             Use this for 'connectionless' socket types.

Method NetComEngine.NewConnection, uses xbx xsi, pProtocol:$ObjPtr(NetComProtocol)
  SetObject xsi
  OCall [xsi].ConnectionPool::NetComConnectionPool.NewItem
  .if xax != NULL
    mov xbx, xax
    OCall xbx::NetComConnection.Init, addr [xsi].ConnectionPool, pProtocol
    .if eax == 0                                        ;Zero means success
      ;Register the socket with IOCP, because we want socket event notifications
      invoke CreateIoCompletionPort, [xbx].$Obj(NetComConnection).hSocket, [xsi].hIOCP, xbx, 0
      mov xax, xbx
    .else
      ;Failed to initialize new connection
      OCall [xsi].ConnectionPool::NetComConnectionPool.FreeItem, xbx
      xor eax, eax
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComEngine.StartListening
; Purpose:    Creates a "Listener" and begins listening on a port (Service) using a protocol.
; Arguments:  Arg1: Number of preallocated accept connections.
;             Arg2: -> NetComProtocol.
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComEngine.StartListening, uses xbx xdi xsi, dAcceptorCount:DWORD, pProtocol:$ObjPtr(NetComProtocol)
  local dOption:DWORD, dRetValue:DWORD

  DbgText "NetComEngine.StartListening"
  SetObject xsi
  mov dRetValue, NO_ERROR

  ;Create a socket with WSA_FLAG_OVERLAPPED flag!
  MemAlloc sizeof(LISTENER)
  .if xax == NULL
    mov dRetValue, WSA_NOT_ENOUGH_MEMORY
    DbgSockError "NetComEngine.StartListening - Can not allocate LISTENER structure", dRetValue
    jmp @@Exit
  .endif
  mov xbx, xax
  mov [xbx].LISTENER.hSocket, INVALID_SOCKET
  OCall [xsi].Listeners::DataCollection.Insert, xbx

  invoke WSASocket, AF_INETX, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED
  .if xax == INVALID_SOCKET
    mov dRetValue, $32($invoke(WSAGetLastError))
    DbgSockError "NetComEngine.StartListening - Failed to create listener socket", dRetValue
    OCall xsi.ErrorReport, NULL, NCE_SOCKET_CREATION_FAILED
    jmp @@Exit
  .endif
  mov [xbx].LISTENER.hSocket, xax
  DbgText "NetComEngine.StartListening - Listener socket created"

  ;Set socket options: disable nagle's algorithm for fast reaction time
  mov dOption, 1                                        ;1 means algo disabled
  invoke setsockopt, [xbx].LISTENER.hSocket, IPPROTO_TCP, TCP_NODELAY, \
                     addr dOption, sizeof dOption
  DbgCheckSockReturn "NetComEngine.StartListening - ERROR on SetSockOpt TCP_NODELAY = 1"

  mov xdi, pProtocol
  invoke bind, [xbx].LISTENER.hSocket, addr [xdi].$Obj(NetComProtocol).ListeningAddr, \
               sizeof NETCOMADDR
  .if xax != NO_ERROR
    mov dRetValue, $32($invoke(WSAGetLastError))
    DbgSockError "NetComEngine.StartListening - Failed to bind listener socket", dRetValue
    OCall pProtocol::NetComProtocol.OnError, NULL, NULL, dRetValue
    OCall xsi.ErrorReport, NULL, NCE_LISTENER_BIND_ERROR
    jmp @@Exit
  .endif

  DbgText "NetComEngine.StartListening - SocketAddress has been bound to listener socket"
  invoke listen, [xbx].LISTENER.hSocket, SOMAXCONN
  .if eax != NO_ERROR
    mov dRetValue, $32($invoke(WSAGetLastError))
    DbgSockError "NetComEngine.StartListening - Listener socket failed to listen", dRetValue
    OCall pProtocol::NetComProtocol.OnError, NULL, NULL, dRetValue
    OCall xsi.ErrorReport, NULL, NCE_LISTENER_DOESNT_LISTEN
    jmp @@Exit
  .endif

  DbgText "NetComEngine.StartListening - Socket is listening..."
  ;Bind the listening socket to the IOCP => necessary for acceptor
  invoke CreateIoCompletionPort, [xbx].LISTENER.hSocket, [xsi].hIOCP, \
                                 COMPLETION_KEY_SOCK_ACCEPTED, 0
  .if xax == 0                                          ;0 means failure
    mov dRetValue, $32($invoke(GetLastError))
    DbgSockError "NetComEngine.StartListening - Listener can not de bound to the IOCP", dRetValue
    OCall pProtocol::NetComProtocol.OnError, NULL, NULL, eax
    OCall xsi.ErrorReport, NULL, NCE_LISTENER_IOCP_BIND_FAILED
    jmp @@Exit
  .endif

  DbgText "NetComEngine.StartListening - Socket has been bound to IOCP"
  ;Queue some accept NetComConnections
  mov edi, dAcceptorCount
  test edi, edi
  .while !ZERO?
    OCall xsi.NewAcceptor, xbx, pProtocol               ;Returns eax = error code
    .break .if eax != NO_ERROR && eax != ERROR_IO_PENDING
    dec xdi
  .endw

@@Exit:
  mov eax, dRetValue
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComEngine.Startup
; Purpose:    WinSock startup.
; Arguments:  None.
; Return:     Nothing.
; Note:       The WinSock startup is placed here so that other related APIs will work before the
;             NetComEngine is started.

Method NetComEngine.Startup
  local WsaData:WSADATA, hSocket:SOCKET, dBytesTransf:DWORD

  invoke WSAStartup, 0202h, addr WsaData
  .if eax != 0
    ;Write the error code into the NetComEngine template.
    ;New instances inherit this error code and must check it.
    OCall $ObjTmpl(NetComEngine)::NetComEngine.ErrorSet, NCE_WINSOCK_INIT_FAILED
  .endif

  invoke WSASocket, AF_INETX, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED
  .if xax != 0
    mov hSocket, xax

    ;Try to obtain a POINTER to the ConnectEx procedure, which may change from socket to socket
    invoke WSAIoctl, hSocket, SIO_GET_EXTENSION_FUNCTION_POINTER,
                     offset WSAID_CONNECTEX, sizeof WSAID_CONNECTEX,
                     addr pConnectEx, sizeof POINTER,
                     addr dBytesTransf, NULL, NULL
    .if eax != NO_ERROR
      DbgWarning "NetComEngine.Startup - Failed to get and address of the procedure ConnextEx"
    .endif
    invoke closesocket, hSocket
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComEngine.Shutdown
; Purpose:    WinSock Shutdown.
; Arguments:  None.
; Return:     Nothing.

Method NetComEngine.Shutdown
  invoke WSACleanup
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComEngine.StopListening
; Purpose:    Stops the engine.
; Arguments:  None.
; Return:     Nothing.

Method NetComEngine.StopListening, uses xsi

  DbgText "NetComEngine.StopListening"
  SetObject xsi

  ;Close all listerners
  DbgText "NetComEngine.StopListening - Closing listeners"

  ;Closes all listening sockets. Pending IOs are cancelled through the IOCP,
  ;which frees the associated acceptor connections.
  OCall [xsi].Listeners::DataCollection.DisposeAll
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
  .while TRUE
    ;The GetQueuedCompletionStatus API call will (if successful) return two useful pieces of
    ;information. One is the "completion key" of the completed IO, the other is a POINTER
    ;to the IOSockJob which represents the IO operation which was completed.
    invoke GetQueuedCompletionStatus, [xsi].hIOCP, addr dBytesTransfered,
                                                   addr xCompletionKey,
                                                   addr pIOSockJob,
                                                   INFINITE
    .break .if xCompletionKey == COMPLETION_KEY_KILL_WORKER   ;Exit thread loop immediately
    mov xbx, pIOSockJob
    .if xbx != NULL
      .if xCompletionKey == COMPLETION_KEY_VOID
        mov xdi, xbx                                    ;pConnection passed using pIOSockJob
        DbgHex xdi, "NetComEngine.Worker - Void posted"
      .else
        .if xCompletionKey == COMPLETION_KEY_SOCK_ACCEPTED
          mov xdi, [xbx].IO_SOCKJOB.DataBuffer.ACCEPT_DATA.pConnection
;          DbgHex xdi, "NetComEngine.Worker - Listener detected an incomming connection - accept connection"
        .else
          mov xdi, xCompletionKey                       ;xdi -> NetComConnection
        .endif
      .endif
;      DbgHex xdi, "NetComEngine.Worker - Connection"
      invoke EnterCriticalSection, addr [xdi].$Obj(NetComConnection).CritSect

      ;Determine whether the operation completed successfully or not
      invoke WSAGetOverlappedResult, [xdi].$Obj(NetComConnection).hSocket, xbx, \
                                     addr dBytesConsumed, \
                                     FALSE, addr dFlags
      mov dOvrResult, eax
      ;Serialize on a per connection basis
      BitSet [xbx].IO_SOCKJOB.wFlags, IOF_JOB_COMPLETED
      dec [xdi].$Obj(NetComConnection).dPendingIOJobs
      inc [xdi].$Obj(NetComConnection).dCompletedIOJobs

      .if dOvrResult != FALSE
        ;Operation succeeded *****************************************************************
        ;Each of the following connection handlers must manage the IOSockJob themselves
        movzx eax, [xbx].IO_SOCKJOB.wOperation
        .if eax == OPERATION_SOCK_RECV
          mrm [xbx].IO_SOCKJOB.dBytesConsumed, dBytesConsumed, edx
          lock add [xsi].dBytesIn, edx
          OCall xdi::NetComConnection.OnReceived, xbx

        .elseif eax == OPERATION_SOCK_SEND
          mrm [xbx].IO_SOCKJOB.dBytesConsumed, dBytesConsumed, edx
          lock add [xsi].dBytesOut, edx
          OCall xdi::NetComConnection.OnSent, xbx

        .elseif eax == OPERATION_SOCK_CONNECT
          OCall xdi::NetComConnection.OnConnected, xbx

        .elseif eax == OPERATION_SOCK_ACCEPT
          OCall xdi::NetComConnection.OnAccepted, xbx

        .else
          invoke WSAGetLastError                        ;This error is thread specific
          OCall xdi::NetComConnection.OnError, xbx, eax
        .endif

      .else
        ;Operation failed! *******************************************************************
        invoke WSAGetLastError                          ;This error is thread specific
        OCall xdi::NetComConnection.OnError, xbx, eax
      .endif

      ;If the connection is flagged for destruction, proceed ONLY if the
      ;connection has no pending IOJobs
      .ifBitSet [xdi].$Obj(NetComConnection).dFlags, NCC_QUEUE_DESTROY
        .if [xdi].$Obj(NetComConnection).dPendingIOJobs == 0
          OCall xdi::NetComConnection.FreeRessources
          invoke LeaveCriticalSection, addr [xdi].$Obj(NetComConnection).CritSect
          OCall xdi::NetComConnection.Done
          OCall [xsi].ConnectionPool::NetComConnectionPool.FreeItem, xdi
          .continue
        .endif
      .endif

      invoke LeaveCriticalSection, addr [xdi].$Obj(NetComConnection).CritSect
    .endif

  .endw

  DbgText "NetComEngine.Worker - death"
  DbgDec [xsi].IOSockJobPool.dCount, "NetComEngine.Worker"
MethodEnd

endif
