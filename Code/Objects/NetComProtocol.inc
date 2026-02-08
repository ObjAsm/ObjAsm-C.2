; ==================================================================================================
; Title:      NetComProtocol.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of NetComProtocol objects.
;             Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


.code

if IMPLEMENT

; ==================================================================================================
;    NetComProtocol implementation
; ==================================================================================================

DbgSetWindowName macro
  if DEBUGGING
    local pDbgWndNameW:PSTRINGW

    mov xax, pConnection
    .if xax != NULL
      lea xcx, [xax].$Obj(NetComConnection).wName
    .else
      lea xcx, szDbgSrc
    .endif
    mov pDbgWndNameW, xcx
  endif
endm

; --------------------------------------------------------------------------------------------------
; Method:     NetComProtocol.Allocate
; Purpose:    Allocate a memory chunk for management data on a per Connection basis.
;             Additional related resources can be reserved here. The POINTER to the allocated memory
;             must be stored in pData member of NetComConnection.
; Arguments:  Arg1: -> NetComConnection.
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComProtocol.Allocate,, pConnection:$ObjPtr(NetComConnection)
  DbgSetWindowName

;  DbgText "NetComProtocol.Allocate", pDbgWndNameW
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComProtocol.AddToBlackList
; Purpose:    Add an address to the BlackList.
; Arguments:  Arg1: -> NETCOMADDR.
;             Arg2: Flags.
; Return:     eax -> New ListEntry.

Method NetComProtocol.AddToBlackList,, pAddr:PNETCOMADDR
  SetObject xcx
  ?mov xdx, pAddr
  OCall [xcx].BlackList::NetComAddrCollection.Insert, xdx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComProtocol.Done
; Purpose:    Finalize this object.
; Arguments:  None.
; Return:     Nothing.

Method NetComProtocol.Done, uses xsi
  SetObject xsi
;  invoke StrDispose, [xsi].pLocalHostSrvName
  OCall [xsi].BlackList::NetComAddrCollection.Done
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComProtocol.Init
; Purpose:    Initialize this object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> String representing the service or the port number as a string.
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComProtocol.Init, uses xsi, pOwner:POINTER;, pServiceName:PSTRING
  SetObject xsi
  ?mov xdx, pOwner
  ACall xsi.Init, xdx
;  mov [xsi].pLocalHostSrvName, $invoke(StrNew, pServiceName)
  OCall [xsi].BlackList::NetComAddrCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComProtocol.IsDataComplete?
; Purpose:    A NetComConnection object will call this method to determine if we have received at
;             least one complete packet, given the rules of your Protocol. This is where your
;             derived Object examines the received data looking to find a valid Delimiter and doing
;             protocol enforcement.
; Arguments:  Arg1: -> NetComConnection.
;             Arg2: -> IO_SOCkJOB
; Return:     eax = ERROR_BAD_PROTOCOL - The buffer content is not following our protocol -
;                                        the client will get booted for this offence.
;                   ERROR_USER_QUIT    - The user sent a nice QUIT message using our protocol -
;                                        the client will get booted for this.
;                   Positive INT32     - This many bytes are valid buffer information.
;                   Zero               - We need more data.
; Note:       Zero length packets are NOT passed from the connection to the protocol.

Method NetComProtocol.IsDataComplete?,, pConnection:$ObjPtr(NetComConnection), \
                                        pIOSockJob:PIO_SOCKJOB
  DbgSetWindowName

;  DbgText "NetComProtocol.IsDataComplete?", pDbgWndNameW
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComProtocol.IsBlackListed?
; Purpose:    Check if an address is in a List (DataCollection).
; Arguments:  Arg1: -> NETCOMADDR to be checked for.
; Return:     eax = Found condition (TRUE/FALSE).
;             ecx = Index in the range [0..Count]. If the ListEntry is not found, ecx is set to the
;                   index where the ListEntry would be placed if inserted.
; ToDo:       Add CIDR matching.

Method NetComProtocol.IsBlackListed?,, pAddr:PNETCOMADDR
  SetObject xcx
  ?mov xdx, pAddr
  OCall [xcx].BlackList::NetComAddrCollection.Search, xdx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComProtocol.OnAccepted
; Purpose:    An inbound connection 'accept' has completed.
; Arguments:  Arg1: -> NetComConnection.
; Return:     Nothing.

Method NetComProtocol.OnAccepted,, pConnection:$ObjPtr(NetComConnection)
  DbgSetWindowName

;  DbgText "NetComProtocol.OnAccepted", pDbgWndNameW
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComProtocol.OnClosed
; Purpose:    A connection has, for whatever reason, been terminated.
;             You can override this, perhaps to release extra per connection resources.
; Arguments:  Arg1: -> NetComConnection.
; Return:     Nothing.

Method NetComProtocol.OnClosed,, pConnection:$ObjPtr(NetComConnection)
  DbgSetWindowName

;  DbgText "NetComProtocol.OnClosed", pDbgWndNameW
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComProtocol.OnConnected
; Purpose:    An outbound connection attempt has completed.
; Arguments:  Arg1: -> NetComConnection.
; Return:     Nothing.

Method NetComProtocol.OnConnected,, pConnection:$ObjPtr(NetComConnection)
  DbgSetWindowName

;  DbgText "NetComProtocol.OnConnected", pDbgWndNameW

  ;Queue a read to recognize a remote disconnect
  OCall pConnection::NetComConnection.QueueReceive
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComProtocol.OnDisconnected
; Purpose:    An established connection has been disconnected.
; Arguments:  Arg1: -> NetComConnection.
;             Arg2: Disconnect direction = SD_SEND/SD_RECEIVE/SD_BOTH
;             Arg3: Operation result.
; Return:     Nothing.

Method NetComProtocol.OnDisconnected,, pConnection:$ObjPtr(NetComConnection), \
                                       dDirection:DWORD, dResult:DWORD
  DbgSetWindowName

;  DbgText "NetComProtocol.OnDisconnected", pDbgWndNameW
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComProtocol.OnError
; Purpose:    Error notification handler.
; Arguments:  Arg1: -> NetComConnection.
;             Arg2: -> IOSockJob.
;             Arg3: Error code.
; Return:     eax = Command (PROT_CMD_NONE, PROT_CMD_DESTROY, ...)

Method NetComProtocol.OnError,, pConnection:$ObjPtr(NetComConnection), pIOSockJob:PIO_SOCKJOB, \
                                dError:DWORD
  DbgSetWindowName

;  DbgDec dError, "NetComProtocol.OnError", pDbgWndNameW
  mov xcx, pIOSockJob
  .if xcx == NULL
    xor eax, eax
    ExitMethod
  .endif

  movzx eax, [xcx].IO_SOCKJOB.wOperation
  .if eax == OPERATION_SOCK_ACCEPT
    mov eax, PROT_CMD_DESTROY
  .elseif eax == OPERATION_SOCK_CONNECT
    mov eax, PROT_CMD_DESTROY
  .elseif eax == OPERATION_SOCK_SEND
    mov eax, PROT_CMD_DESTROY
  .elseif eax == OPERATION_SOCK_RECV
    mov eax, PROT_CMD_DESTROY
  .else
    mov eax, PROT_CMD_DESTROY
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComProtocol.OnTimeouted
; Purpose:    A connection timeout occurs.
; Arguments:  Arg1: -> NetComConnection.
; Return:     eax = PROT_CMD_NONE, PROT_CMD_DISCONNECT, PROT_CMD_DESTROY.

Method NetComProtocol.OnTimeouted,, pConnection:$ObjPtr(NetComConnection)
  DbgSetWindowName

;  DbgText "NetComProtocol.OnTimeouted", pDbgWndNameW
  mov eax, PROT_CMD_DISCONNECT
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComProtocol.ProcessData
; Purpose:    A client has finished sending us data, now we have to do something with that data.
; Arguments:  Arg1: -> NetComConnection.
;             Arg2: Delimiter index found in NetComProtocol.IsDataComplete?.
; Return:     eax = Number of processed bytes.

Method NetComProtocol.ProcessData,, pConnection:$ObjPtr(NetComConnection), dDelimiterIndex:DWORD
  DbgSetWindowName

;  DbgText "NetComProtocol.ProcessData", pDbgWndNameW
  mov eax, dDelimiterIndex
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComProtocol.Release
; Purpose:    Release the memory chunk allocated with Allocate. Additional resources must be freed
;             here.
; Arguments:  Arg1: -> NetComConnection.
; Return:     Nothing.

Method NetComProtocol.Release,, pConnection:$ObjPtr(NetComConnection)
  DbgSetWindowName

;  DbgText "NetComProtocol.Release", pDbgWndNameW
MethodEnd

endif
