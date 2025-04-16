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
; Method:     NetComConnection.QueueClose
; Purpose:    Mark a NetCom connection to close
; Arguments:  None.
; Return:     Nothing.

Method NetComConnection.QueueClose
  SetObject xcx
;  DbgHex xcx, "NetComConnection.QueueClose"
  xBitSet [xcx].dFlags, NCC_CLOSE_MARKED
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.Disconnect
; Purpose:    Disconnect writing and/or reading.
; Arguments:  Arg1: type = SD_SEND/SD_READ/SD_BOTH
; Return:     Nothing.

Method NetComConnection.Disconnect, uses xsi, dType:DWORD
  SetObject xsi
;  DbgHex xsi, "NetComConnection.Disconnect"
  .ifBitClr [xsi].dFlags, NCC_DISCONNECTED_LOCAL or NCC_CLOSED
    OCall [xsi].pProtocol::NetComProtocol.OnDisconnect, xsi
    .ifBitClr [xsi].dFlags, NCC_DISCONNECTED_REMOTE
      OCall xsi.QueueRead                                 ;Issue a read to catch the FIN from the
    .endif                                                ;   remote host
    invoke shutdown, [xsi].hSocket, dType                 ;Send FIN to the remote host
    CheckSockError "ERROR on NetComConnection.Disconnect - shutdown"
    xBitSet [xsi].dFlags, NCC_DISCONNECTED_LOCAL
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.Done
; Purpose:    Finalize the NetComConnection object.
; Arguments:  None.
; Return:     Nothing.

Method NetComConnection.Done, uses xsi
  SetObject xsi
;  DbgHex xsi, "NetComConnection.Done"
  OCall [xsi].pProtocol::NetComProtocol.OnClose, xsi    ;Inform protocol object
  .if [xsi].hSocket != INVALID_SOCKET
    OCall xsi.OnClose
  .endif
  OCall xsi.FreeIOJobs
  OCall [xsi].pProtocol::NetComProtocol.Release, xsi    ;Release protocol resources
  invoke DeleteCriticalSection, addr [xsi].CritSect 
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.DoRead
; Purpose:    Perform an asynchronious read operation.
; Arguments:  Arg1: -> IOSockJob.
; Return:     Zero or Error code.

Method NetComConnection.DoRead, uses xbx xsi, pIOSockJob:PIO_SOCKJOB
  local dFlags:DWORD, dLen:DWORD

  SetObject xsi
;  DbgHex xsi, "NetComConnection.DoRead"

  mov xbx, pIOSockJob
  invoke EnterCriticalSection, addr [xsi].CritSect      ;Lock for insertion
  lea xcx, [xbx].IO_SOCKJOB.pNextItem                   ;Get address of SDLL_ITEM
  lea xax, [xsi].RcvIOChain                             ;Get address of SDLL_SENTINEL
  SDLL_Append xax, xcx                                  ;Link this IOSockJob to the IO list
  mov dLen, sizeof NETCOMADDR
  mov dFlags, MSG_PARTIAL
  invoke WSARecvFrom, [xsi].hSocket, addr [xbx].IO_SOCKJOB.WSABuf, 1, \
                      addr [xbx].IO_SOCKJOB.dBytesConsumed, addr dFlags, \
                      addr [xsi].RemoteHostAddr, addr dLen, xbx, NULL
  invoke LeaveCriticalSection, addr [xsi].CritSect
  .if eax != 0                                          ;Did read IO complete synchronously?
    invoke WSAGetLastError                              ;No, check if it is a pending state
    .if eax != ERROR_IO_PENDING
      OCall xsi.OnError, xbx, eax                       ;pIOSockJob
      jmp @@EOM
    .endif
  .endif
  lock inc [xsi].dPendingIOJobs
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.DoWrite
; Purpose:    Perform an asynchronious write operation.
; Arguments:  Arg1: -> IO_SOCKJOB.
; Return:     Zero or Error code.

Method NetComConnection.DoWrite, uses xbx xsi, pIOSockJob:PIO_SOCKJOB
  local dLen:DWORD

;  DbgText "NetComConnection.DoWrite"
  SetObject xsi
  mov xbx, pIOSockJob
  mov dLen, sizeof NETCOMADDR
  lea xdx, [xbx].IO_SOCKJOB.WSABuf
  invoke WSASendTo, [xsi].hSocket, xdx, 1, \
                    addr [xbx].IO_SOCKJOB.dBytesConsumed, 0, \
                    addr [xsi].RemoteHostAddr, addr dLen, xbx, NULL
  .if eax != 0
    invoke WSAGetLastError
    .if eax != ERROR_IO_PENDING
      OCall xsi.OnError, xbx, eax
      jmp @@EOM
    .endif
  .endif
  lock inc [xsi].dPendingIOJobs                         ;Always increment the pending write count,
  xor eax, eax                                          ;  also if the read completed synchronously!
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.FreeIOJobs
; Purpose:    Free all gattered IOJobs.
; Arguments:  None.
; Return:     Nothing.

Method NetComConnection.FreeIOJobs, uses xbx xdi xsi
  local pItem:POINTER

  SetObject xsi
;  DbgHex xsi, "NetComConnection.FreeIOJobs"

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
  SDLL_Init xbx                                       ;Reset the linked list
  SetObject xsi
  invoke LeaveCriticalSection, addr [xsi].CritSect 
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.Init
; Purpose:    Initialize the NetComConnection object.
; Arguments:  Arg1: -> Owner object (NetComConnectionPool).
;             Arg2: -> NetComProtocol or derived object.
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComConnection.Init, uses xsi, pOwner:POINTER, pProtocol:POINTER
  local dOption:DWORD, dBytesTransf:DWORD

;  DbgText "NetComConnection.Init"
  SetObject xsi
  ?mov xdx, pOwner
  ACall xsi.Init, xdx
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
      CheckSockError "ERROR on SetSockOpt TCP_NODELAY = 0"

      ;Set send buffer size to zero since we provide our own buffers
;      m2z dOption
;      invoke setsockopt, [xsi].hSocket, SOL_SOCKET, SO_SNDBUF, addr dOption, sizeof dOption
;      CheckSockError "ERROR on SetSockOpt SO_SNDBUF = 0"
;      invoke setsockopt, [xsi].hSocket, SOL_SOCKET, SO_RCVBUF, addr dOption, sizeof dOption
;      CheckSockError "ERROR on SetSockOpt SO_RCVBUF = 0"

      ;Try to obtain a POINTER to the ConnectEx procedure, which may change from socket to socket
      invoke WSAIoctl, [xsi].hSocket, SIO_GET_EXTENSION_FUNCTION_POINTER,
                       offset WSAID_CONNECTEX, sizeof WSAID_CONNECTEX,
                       addr [xsi].pConnectEx, sizeof POINTER,
                       addr dBytesTransf,
                       NULL, NULL                       ;NULL to avoid IOCP notification

      invoke MemZero, addr [xsi].ConnStartTime, sizeof SYSTEMTIME

      xor eax, eax
    .else
      DbgWarning "Failed to create socket"
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.OnAccept
; Purpose:    This method associates a newly accepted socket with the IOCP and queues an IOSockJob
;             of the "OPERATION_SOCK_READ" type.
; Arguments:  Arg1: -> IOSockJob.
; Return:     Nothing.

Method NetComConnection.OnAccept, uses xbx xdi xsi, pIOSockJob:PIO_SOCKJOB
  local dRvcTimeSize:DWORD, pProtocol:$ObjPtr(NetComProtocol)

  SetObject xsi
;  DbgHex xsi, "NetComConnection.OnAccept"

  ?mov xdx, pIOSockJob
  mov xbx, [xdx].IO_SOCKJOB.DataBuffer.ACCEPT_DATA.pListener
  m2m pProtocol, [xsi].pProtocol, xax

  mov xcx, [xsi].pOwner                                 ;xcx -> NetComConnectionPool
  mov xdi, [xcx].$Obj(NetComConnectionPool).pOwner      ;xdi -> NetComEngine
  .if [xdi].$Obj(NetComEngine).dShuttingDown == FALSE
    xBitClr [xsi].dFlags, NCC_DISCONNECTED

    ;Updates the accepting socket with the context of the listening socket.
    invoke setsockopt, [xsi].hSocket, SOL_SOCKET, SO_UPDATE_ACCEPT_CONTEXT, \
                       addr [xbx].LISTENER.hSocket, sizeof HANDLE
    CheckSockError "Error on SetSockOpt SO_UPDATE_ACCEPT_CONTEXT"

    mov dRvcTimeSize, sizeof DWORD
    invoke getsockopt, [xsi].hSocket, SOL_SOCKET, SO_CONNECT_TIME, \
                       addr [xsi].dRcvLastTime, addr dRvcTimeSize
    CheckSockError "ERROR on OnRead getsockopt SO_CONNECT_TIME"

    ;Get the local host address
    mov xcx, pIOSockJob
    mov xdx, [xcx].IO_SOCKJOB.WSABuf.buf
    invoke MemClone, addr [xsi].LocalHostAddr, \
                     addr [xdx].ACCEPT_DATA.LocalHostAddr, \
                     sizeof NETCOMADDR

    ;Get the remote host address, we don't use getpeername to avoid 1 kernel transition
    mov xcx, pIOSockJob
    mov xdx, [xcx].IO_SOCKJOB.WSABuf.buf
    invoke MemClone, addr [xsi].RemoteHostAddr, \
                     addr [xdx].ACCEPT_DATA.RemoteHostAddr, \
                     sizeof NETCOMADDR

    ;Notify the NetComConnection's Protocol handler
    OCall [xsi].pProtocol::NetComProtocol.OnAccept, xsi
    .if eax == PROT_CMD_ACCEPT_CONNECTION
      ;Bind the NetComConnection Socket to the IOCP
      mov xcx, [xsi].pOwner
      mov xax, [xcx].$Obj(NetComConnectionPool).pOwner
      invoke CreateIoCompletionPort, [xsi].hSocket, [xax].$Obj(NetComEngine).hIOCP, xsi, 0
      invoke GetSystemTime, addr [xsi].ConnStartTime

      ;Issue a read IO reusing the accept IOSockJob for a read IOJob
      mov xcx, [xsi].pOwner
      OCall [xcx].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOSockJobPool.ResetIOJob, \
                                             pIOSockJob, OPERATION_SOCK_READ
      lock dec [xsi].dPendingIOJobs                     ;DoRead increments the count again
      OCall xsi.DoRead, xax
    .else
      ;Connection rejected
      OCall [xdi].$Obj(NetComEngine).IOJobs::NetComIOSockJobPool.FreeItem, pIOSockJob
      OCall xsi.QueueFree                               ;Mark to free => close & free
    .endif
    OCall xdi::NetComEngine.QueueAcceptor, xbx, pProtocol   ;Create a new acceptor
  .else
    ;Don't accept new connections!
    ;If we are shutting down we simply release the IOSockJob ignoring this operation
    OCall [xdi].$Obj(NetComEngine).IOJobs::NetComIOSockJobPool.FreeItem, pIOSockJob

  .endif
  DbgDec [xdi].$Obj(NetComEngine).IOJobs.dCount
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.OnClose
; Purpose:    Close a NetCom connection.
; Arguments:  None.
; Return:     Nothing.

Method NetComConnection.OnClose, uses xsi
  local MyLinger:linger

  SetObject xsi
;  DbgHex xsi, "NetComConnection.OnClose"
  .ifBitClr [xsi].dFlags, NCC_CLOSED
    .if [xsi].hSocket != INVALID_SOCKET
      ;Perform an "abortive close" of the socket, just in case.
      mov MyLinger.l_onoff, 1
      mov MyLinger.l_linger, 0
      invoke setsockopt, [xsi].hSocket, SOL_SOCKET, SO_LINGER, addr MyLinger, sizeof MyLinger
      CheckSockError "ERROR on SetSockOpt SO_LINGER"
      invoke closesocket, [xsi].hSocket
      mov [xsi].hSocket, INVALID_SOCKET
    .endif
    OCall [xsi].pProtocol::NetComProtocol.OnClose, xsi
    invoke MemZero, addr [xsi].ConnStartTime, sizeof SYSTEMTIME
    xBitSet [xsi].dFlags, NCC_CLOSED
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.OnConnect
; Purpose:    A connect operation has finished.
; Arguments:  Arg1: -> IOSockJob.
; Return:     Nothing.

Method NetComConnection.OnConnect, uses  xsi, pIOSockJob:PIO_SOCKJOB
  SetObject xsi
;  DbgHex xsi, "NetComConnection.OnConnect"
  xBitClr [xsi].dFlags, NCC_DISCONNECTED
  mov xcx, [xsi].pOwner
  OCall [xcx].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOSockJobPool.FreeItem, pIOSockJob
  invoke setsockopt, [xsi].hSocket, SOL_SOCKET, SO_UPDATE_CONNECT_CONTEXT, NULL, 0
  CheckSockError "ERROR on SetSockOpt SO_UPDATE_CONNECT_CONTEXT"
  invoke GetSystemTime, addr [xsi].ConnStartTime
  OCall [xsi].pProtocol::NetComProtocol.OnConnect, xsi
  OCall xsi.QueueRead                                   ;Queue a read to recognize a remote 
MethodEnd                                               ;  disconnect

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.OnError
; Purpose:    An error condition was fired. We have to decide what to do next.
; Arguments:  Arg1: -> IO_SOCKJOB.
;             Arg2: Error.
;             Arg3: Additional Info Text.
;             Arg4: Destination Window name.
; Return:     Nothing.

DbgOnError macro WarningText:req, Error:req, InfoText, Dest
  if DEBUGGING
    DbgSaveContext FALSE, Error
    DbgSetDestWnd Dest
    invoke DbgOutCmd, DBG_CMD_SINGLE_LINE, DbgColorLine, DbgColorBackground, ??DbgDstWnd
    invoke DbgOutTextA, $OfsCStrA($Esc(<WarningText>)), DbgColorWarning, DbgColorBackground, \
                        DBG_EFFECT_NORMAL, ??DbgDstWnd
    $$Buffersize = 1024
    sub xsp, $$Buffersize                               ;;Reserve a buffer on the stack.
    if TARGET_BITNESS eq 32
      mov edi, esp                                      ;;Get a pointer to the buffer
    else
      lea rdi, [rsp + 28h]                              ;;Get a POINTER to the output buffer
    endif
    invoke wsprintfA, xdi, $OfsCStrA(" - WSA error code: %lit"), ebx
    invoke DbgOutTextA, xdi, DbgColorWarning, DbgColorBackground, DBG_EFFECT_NORMAL, ??DbgDstWnd
    invoke NetErr2Str, ebx, xdi, $$Buffersize - 28h     ;;Get the error message
    add xsp, 1024                                       ;;Retrieve the string space
    DbgShowTxtInfo InfoText, ??DbgDstWnd
    DbgShowSrcInfo ??DbgDstWnd
    invoke DbgOutCmd, DBG_CMD_SINGLE_LINE, DbgColorLine, DbgColorBackground, ??DbgDstWnd
    DbgLoadContext
  endif
endm

Method NetComConnection.OnError, uses xbx xdi xsi, pIOSockJob:PIO_SOCKJOB, dError:DWORD
  local dProtocolCommand:DWORD

  SetObject xsi
  mov xbx, pIOSockJob
  mov xdi, [xsi].pOwner                                 ;xdi -> NetComConnectionPool
  lock dec [xsi].dPendingIOJobs                         ;This IOJov is not pending anymore

  movzx eax, [xbx].IO_SOCKJOB.wOperation 
  .if eax == OPERATION_SOCK_ACCEPT
    .if dError == ERROR_OPERATION_ABORTED               ;Usual termination IO operation
      OCall [xdi].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOSockJobPool.FreeItem, xbx
    .else
      DbgOnError "NetComConnection.OnError - ACCEPT", dError
      xBitSet [xsi].dFlags, NCE_ACCEPT 
      OCall xsi.ErrorSet, dError
      OCall [xsi].pProtocol::NetComProtocol.OnError, xsi, xbx, dError
      mov dProtocolCommand, eax
      ;Freeing of this IOJob must be done before QueueFree 
      OCall [xdi].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOSockJobPool.FreeItem, xbx
      .if dProtocolCommand == PROT_CMD_REJECT_CONNECTION
        OCall xsi.Disconnect, SD_SEND
        OCall xsi.QueueClose
        OCall xsi.QueueFree                             ;Only ACCEPT should free a connection
      .endif
    .endif

  .elseif eax == OPERATION_SOCK_CONNECT  
    .if dError != ERROR_OPERATION_ABORTED               ;Usual termination IO operation
    .else
      DbgOnError "NetComConnection.OnError - CONNECT", dError
      xBitSet [xsi].dFlags, NCE_CONNECT 
      OCall xsi.ErrorSet, dError
      OCall [xsi].pProtocol::NetComProtocol.OnError, xsi, xbx, dError
      mov dProtocolCommand, eax
      .if dProtocolCommand == PROT_CMD_CLOSE
        OCall xsi.Disconnect, SD_SEND
        OCall xsi.QueueClose
      .endif
    .endif
    OCall [xdi].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOSockJobPool.FreeItem, xbx

  .elseif eax == OPERATION_SOCK_WRITE  
    .if dError != ERROR_OPERATION_ABORTED               ;Usual termination IO operation
      .ifBitClr [xsi].dFlags, NCC_CLOSE_MARKED
        DbgOnError "NetComConnection.OnError - WRITE", dError
        xBitSet [xsi].dFlags, NCE_WRITE 
        OCall xsi.ErrorSet, dError
        OCall [xsi].pProtocol::NetComProtocol.OnError, xsi, xbx, dError
        .if eax == PROT_CMD_CLOSE
          OCall xsi.Disconnect, SD_SEND
          OCall xsi.QueueClose
        .endif
      .endif
    .endif
    OCall [xdi].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOSockJobPool.FreeItem, xbx

  .elseif eax == OPERATION_SOCK_READ  
    .if dError != ERROR_OPERATION_ABORTED               ;Usual termination IO operation
      OCall xsi.ErrorSet, dError                        ;Don't remove the IOJob. It's RcvIOChain chained
      OCall [xsi].pProtocol::NetComProtocol.OnError, xsi, xbx, dError
      mov dProtocolCommand, eax

      .ifBitClr [xsi].dFlags, NCE_READ
        xBitSet [xsi].dFlags, NCE_READ 
        .if dProtocolCommand == PROT_CMD_DISCONNECT
          DbgOnError "NetComConnection.OnError - READ | Disconnect", dError
          .ifBitClr [xsi].dFlags, NCC_DISCONNECTED_LOCAL
            OCall xsi.Disconnect, SD_SEND
          .endif
        .elseif dProtocolCommand == PROT_CMD_CLOSE
          DbgOnError "NetComConnection.OnError - READ | Close", dError
          .ifBitClr [xsi].dFlags, NCC_CLOSE_MARKED
            OCall xsi.Disconnect, SD_SEND
            OCall xsi.QueueClose
          .endif
        .elseif dProtocolCommand == PROT_CMD_FREE
          DbgOnError "NetComConnection.OnError - READ | Free", dError
          .ifBitClr [xsi].dFlags, NCC_FREE_MARKED
            OCall xsi.Disconnect, SD_SEND
            OCall xsi.QueueClose
            OCall xsi.QueueFree
          .endif
        .else
          DbgOnError "NetComConnection.OnError - READ | Unknown protocol command", dError
          DbgHex dProtocolCommand
        .endif
      .endif
    .endif
    
  .else
    OCall [xdi].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOSockJobPool.FreeItem, xbx
    DbgOnError "NetComConnection.OnError - Unknown operation", dError
    DbgHex [xbx].IO_SOCKJOB.wOperation

  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.OnFree
; Purpose:    Free a NetCom connection.
; Arguments:  None.
; Return:     Nothing.

Method NetComConnection.OnFree, uses xsi
  SetObject xsi
  DbgHex xsi, "NetComConnection.OnFree"
  OCall xsi.Done
  xBitSet [xsi].dFlags, NCC_FREED
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.OnRead
; Purpose:    A read operation has finished.
; Arguments:  Arg1: -> IO_SOCKJOB.
; Return:     eax = Error code.

Method NetComConnection.OnRead, uses xbx xdi xsi, pIOSockJob:PIO_SOCKJOB
  local dConsumed:DWORD, dRvcTimeSize:DWORD

  SetObject xsi
;  DbgHex xsi, "NetComConnection.OnRead"
  ?mov xdx, pIOSockJob
  
  lock inc [xsi].dCompletedIOJobs
  lock dec [xsi].dPendingIOJobs
  xBitSet [xdx].IO_SOCKJOB.wFlags, IOF_JOB_ENGAGED
  ;Check for special case of remote socket closure
  .if [xdx].IO_SOCKJOB.dBytesConsumed == 0              ;Graceful shutdown
    xBitSet [xsi].dFlags, NCC_DISCONNECTED_REMOTE       ;Remote Host disconnected
    .ifBitClr [xsi].dFlags, NCC_DISCONNECTED_LOCAL
      OCall xsi.Disconnect, SD_SEND                     ;Local Host disconnect
    .endif
  .else
    mov xdx, pIOSockJob
    ;We queue a new read for the one we recieve here
    mov xcx, [xsi].pOwner
    OCall [xcx].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOSockJobPool.NewItem, \
                                                                               OPERATION_SOCK_READ
    .if xax != NULL
      OCall xsi.DoRead, xax
    .else
      DbgHex xsi, "NetComConnection.OnRead - DoRead failed"
    .endif

    ;Return the number of seconds a socket has been connected.
    mov dRvcTimeSize, sizeof DWORD
    invoke getsockopt, [xsi].hSocket, SOL_SOCKET, SO_CONNECT_TIME, \
                       addr [xsi].dRcvLastTime, addr dRvcTimeSize
    CheckSockError "ERROR on OnRead getsockopt SO_CONNECT_TIME"

    OCall [xsi].pProtocol::NetComProtocol.IsDataComplete?, xsi, pIOSockJob
    .if eax != 0                                        ;eax = byte count to free from IO_SOCKJOBs
      OCall [xsi].pProtocol::NetComProtocol.ProcessData, xsi, eax
      .if eax == ERROR_BAD_PROTOCOL || eax == ERROR_USER_QUIT
        OCall xsi.Disconnect, SD_SEND
        OCall xsi.QueueClose
      .else
        ;eax = #bytes consumed, which should be removed.
        ;Note this value could be larger than one IOSockJob buffer, meaning that it represents
        ;several IOJobs. Also note that the total #bytes buffered could be larger than the
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
            lock dec [xsi].dCompletedIOJobs
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
; Method:     NetComConnection.OnWrite
; Purpose:    A write operation has finished.
; Arguments:  Arg1: -> IO_SOCKJOB.
; Return:     Nothing.

Method NetComConnection.OnWrite, uses xsi, pIOSockJob:PIO_SOCKJOB
  SetObject xsi
  DbgHex xsi, "NetComConnection.OnWrite"
  mov xcx, [xsi].pOwner
  ;Toss the completed IOSockJob back in the IOJobPool
  OCall [xcx].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOSockJobPool.FreeItem, pIOSockJob
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.QueueAccept
; Purpose:    Queue an accept IO_SOCKJOB.
; Arguments:  Arg1: -> LISTENER.
;             Arg2: -> NetComProtocol.
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComConnection.QueueAccept, uses xdi xsi, pListener:PLISTENER, pProtocoll:POINTER
  local dBytesRecieved:DWORD

  SetObject xsi
;  DbgHex xsi, "NetComConnection.QueueAccept"

  ;Allocate an IOSockJob to represent the accept IO operation
  mov xcx, [xsi].pOwner
  OCall [xcx].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOSockJobPool.NewItem, \
                                                          OPERATION_SOCK_ACCEPT
  ;DbgHex eax, "Acceptor IOSockJob"
  .if xax != NULL
    mov xdi, xax
    mrm [xdi].IO_SOCKJOB.DataBuffer.ACCEPT_DATA.pListener, pListener, xcx   ;xcx -> LISTENER 
    mov [xdi].IO_SOCKJOB.DataBuffer.ACCEPT_DATA.pConnection, xsi
    ;if ReceiveDataLength = 0, AcceptEx completes as soon as a connection arrives,
    ;without waiting for any data. Local and remote addresses are written into the buffer
    invoke AcceptEx, [xcx].LISTENER.hSocket, [xsi].hSocket, [xdi].IO_SOCKJOB.WSABuf.buf, 0, \
                     sizeof ACCEPT_DATA.LocalHostAddr, \
                     sizeof ACCEPT_DATA.RemoteHostAddr, \
                     addr dBytesRecieved, xdi
    .if eax == FALSE
      invoke WSAGetLastError
      .if eax != ERROR_IO_PENDING                       ;Accept is pending, which is normal
        OCall xsi.OnError, xdi, eax
        ExitMethod
      .endif
      lock inc [xsi].dPendingIOJobs
    .endif
    xor eax, eax
  .else
    OCall xsi.ErrorReport, NULL, NCCN_OUT_OF_MEMORY
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.QueueConnect
; Purpose:    Queue a connect IO_SOCKJOB.
; Arguments:  Arg1: Remote host address.
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComConnection.QueueConnect, uses xdi xsi, pRemoteHostAddr:PNETCOMADDR
  local dOption:DWORD, dSize:DWORD

  SetObject xsi
;  DbgHex xsi, "NetComConnection.QueueConnect"

  ?mov xdx, pRemoteHostAddr
  invoke MemClone, addr [xsi].RemoteHostAddr, xdx, sizeof NETCOMADDR

  mov xax, [xsi].pOwner                                 ;xax -> NetComConnectionPool
  mov xdi, [xax].$Obj(NetComConnectionPool).pOwner      ;xdi -> NetComEngine
  invoke MemClone, addr [xsi].LocalHostAddr, \
                   addr [xdi].$Obj(NetComEngine).LocalHostAddr, \
                   sizeof NETCOMADDR
  ;Here we can change the returning port

  mov dOption, 1
  invoke setsockopt, [xsi].hSocket, SOL_SOCKET, SO_REUSEADDR, addr dOption, sizeof dOption
  CheckSockError "ERROR on SetSockOpt SO_REUSEADDR"

  ;Associate a local address with the socket
  invoke bind, [xsi].hSocket, addr [xsi].LocalHostAddr, sizeof NETCOMADDR
  .if eax == 0
    mov dSize, NETCOMADDR
    ;Retrieve assigned port
    invoke getsockname, [xsi].hSocket, addr [xsi].LocalHostAddr, addr dSize

    mov xcx, [xsi].pOwner                               ;xcx -> NetComConnectionPool
    OCall [xcx].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOSockJobPool.NewItem, \
                                                                              OPERATION_SOCK_CONNECT
    .if xax != NULL
      mov xdi, xax
      .if [xsi].pConnectEx != NULL
        m2z [xdi].IO_SOCKJOB.WSABuf.len                 ;dSize MUST be zero to get
        invoke [xsi].pConnectEx, [xsi].hSocket, addr [xsi].RemoteHostAddr, \
                                                sizeof NETCOMADDR, NULL, 0, NULL, xdi
        .if eax != 0                                    ;Zero means success
          invoke WSAGetLastError
          .if eax != ERROR_IO_PENDING
            DbgWarning "Error while connecting"
            OCall xsi.OnError, xdi, eax
            ExitMethod
          .endif
        .endif
        lock inc [xsi].dPendingIOJobs
        xor eax, eax
      .else
        DbgWarning "FAILED TO GET PTR TO CONNECTEX"
        invoke WSAGetLastError
        DbgDec eax, "Socket Error Code"
      .endif
    .else
      OCall xsi.ErrorReport, NULL, NCCN_OUT_OF_MEMORY
    .endif
  .else
    DbgDec eax, "BIND result"
    invoke WSAGetLastError
    DbgDec eax, "SOCKET ERRORCODE"
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.QueueFree
; Purpose:    Mark a NetCom connection to free.
; Arguments:  None.
; Return:     Nothing.

Method NetComConnection.QueueFree
  SetObject xcx
;  DbgHex xcx, "NetComConnection.QueueFree"
  xBitSet [xcx].dFlags, NCC_FREE_MARKED
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.QueueRead
; Purpose:    Queue a read IO_SOCKJOB.
; Arguments:  None.
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComConnection.QueueRead, uses xsi
  SetObject xsi
;  DbgHex xsi, "NetComConnection.QueueRead"
  .ifBitClr [xsi].dFlags, NCC_DISCONNECTED              ;We are connected
    mov xcx, [xsi].pOwner
    OCall [xcx].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOSockJobPool.NewItem, \
                                                                               OPERATION_SOCK_READ
    .if xax != NULL
      OCall xsi.DoRead, xax
    .endif
  .else
    OCall xsi.ErrorReport, NULL, NCCN_DISCONNECTED
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComConnection.QueueWrite
; Purpose:    Copy the information pointed to by pData to the send buffers and queue a
;             write operation on each one.
; Arguments:  Arg1: -> Data buffer.
;             Arg2: Data size.
; Return:     eax = Data size not queued. Zero means all was sent.

Method NetComConnection.QueueWrite, uses xdi xsi, pData:POINTER, dSize:DWORD
  local dBufferSize:DWORD, pItem:POINTER

  SetObject xsi
;  DbgHex xsi, "NetComConnection.QueueWrite"
  .ifBitClr [xsi].dFlags, NCC_DISCONNECTED
    mov xcx, [xsi].pOwner                               ;xcx -> NetComConnectionPool
    mov xdx, [xcx].$Obj(NetComConnectionPool).pIOSockJobPool  ;xdx -> NetComIOJobPool
    m2m dBufferSize, [xdx].$Obj(NetComIOSockJobPool).dBufferSize, eax
    mov edi, dSize
    .while edi != 0
      mov xcx, [xsi].pOwner                             ;xcx -> NetComConnectionPool
      OCall [xcx].$Obj(NetComConnectionPool).pIOSockJobPool::NetComIOSockJobPool.NewItem, \
                                                                               OPERATION_SOCK_WRITE
      .if xax != NULL
        mov pItem, xax
        .if dBufferSize < edi
          ;Send a full buffer and cycle again
          m2m [xax].IO_SOCKJOB.WSABuf.len, dBufferSize, edx
          invoke MemClone, [xax].IO_SOCKJOB.WSABuf.buf, pData, dBufferSize
          OCall xsi.DoWrite, pItem
          .break .if eax != 0
          mov edx, dBufferSize
          add pData, xdx
          sub edi, edx
        .else
          ;Send a partially full buffer
          mov [xax].IO_SOCKJOB.WSABuf.len, edi
          invoke MemClone, [xax].IO_SOCKJOB.WSABuf.buf, pData, edi
          OCall xsi.DoWrite, pItem
          .break .if eax != 0
          xor edi, edi
        .endif
      .else
        OCall xsi.ErrorReport, NULL, NCCN_OUT_OF_MEMORY
        .break
      .endif
    .endw
    mov eax, edi
  .else
    xor eax, eax
  .endif
MethodEnd

endif
