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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     NetComProtocol.Allocate
; Purpose:    Allocate a memory chunk for management data on a per Connection basis.
;             Additional related resources can be reserved here. The POINTER to the allocated memory
;             must be stored in pProtocolData member of NetComConnection.
; Arguments:  Arg1: -> NetComConnection.
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComProtocol.Allocate,, pConnection:$ObjPtr(NetComConnection)
;  DbgHex pConnection, "NetComProtocol.Allocate", "&PROTOCOL_WND_NAME"
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     NetComProtocol.Done
; Purpose:    Finalize this object.
; Arguments:  None.
; Return:     Nothing.

Method NetComProtocol.Done, uses xsi
  DbgText "NetComProtocol.Done", "ResGuard"
  SetObject xsi
  invoke StrDispose, [xsi].pServiceName
  OCall [xsi].BlackList::NetComAddrCollection.Done
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     NetComProtocol.Init
; Purpose:    Initialize this object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> String representing the service or the port number as a string.
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComProtocol.Init, uses xsi, pOwner:POINTER, pServiceName:PSTRING
  SetObject xsi
  ?mov xdx, pOwner
  ACall xsi.Init, xdx
  mov [xsi].pServiceName, $invoke(StrNew, pServiceName)
  OCall [xsi].BlackList::NetComAddrCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
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
;                   Positive INT32     - This many bytes are part of the complete packet.
;                   Zero               - We need more data.

Method NetComProtocol.IsDataComplete?,, pConnection:$ObjPtr(NetComConnection), \
                                        pIOSockJob:PIO_SOCKJOB
;  DbgHex pConnection, "NetComProtocol.IsDataComplete?", "&PROTOCOL_WND_NAME"
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     NetComProtocol.IsBlackListed?
; Purpose:    Check if an address is in a List (DataCollection).
; Arguments:  Arg1: -> NETCOMADDR to be checked for.
; Return:     eax = Found condition (TRUE/FALSE).
;             ecx = Index in the range [0..Count]. If the ListEntry is not found, ecx is set to the
;                   index where the ListEntry would be placed if inserted.

Method NetComProtocol.IsBlackListed?,, pAddr:PNETCOMADDR
  SetObject xcx
  ?mov xdx, pAddr
  OCall [xcx].BlackList::NetComAddrCollection.Search, xdx
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     NetComProtocol.OnAccept
; Purpose:    An inbound connection 'accept' has completed.
; Arguments:  Arg1: -> NetComConnection.
; Return:     eax = Command (PROT_CMD_ACCEPT_CONNECTION or PROT_CMD_REJECT_CONNECTION).

Method NetComProtocol.OnAccept,, pConnection:$ObjPtr(NetComConnection)
;  DbgHex pConnection, "NetComProtocol.OnAccept", "&PROTOCOL_WND_NAME"
  mov eax, PROT_CMD_ACCEPT_CONNECTION
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     NetComProtocol.OnClose
; Purpose:    A connection has, for whatever reason, been terminated.
;             You can override this, perhaps to release extra per connection resources.
; Arguments:  Arg1: -> NetComConnection.
; Return:     Nothing.

Method NetComProtocol.OnClose,, pConnection:$ObjPtr(NetComConnection)
;  DbgHex pConnection, "NetComProtocol.OnClose", "&PROTOCOL_WND_NAME"
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     NetComProtocol.OnConnect
; Purpose:    An outbound connection attempt has completed.
; Arguments:  Arg1: -> NetComConnection.
; Return:     Nothing.

Method NetComProtocol.OnConnect,, pConnection:$ObjPtr(NetComConnection)
;  DbgHex pConnection, "NetComProtocol.OnConnect", "&PROTOCOL_WND_NAME"
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     NetComProtocol.OnDisconnect
; Purpose:    An established connection has been disconnected.
; Arguments:  Arg1: -> NetComConnection.
; Return:     Nothing.

Method NetComProtocol.OnDisconnect,, pConnection:$ObjPtr(NetComConnection)
;  DbgHex pConnection, "NetComProtocol.OnDisconnect", "&PROTOCOL_WND_NAME"
  ?mov xdx, pConnection
  xBitSet [xdx].$Obj(NetComConnection).dFlags, NCC_DISCONNECTED
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     NetComProtocol.OnError
; Purpose:    Error notification handler.
; Arguments:  Arg1: -> NetComConnection.
;             Arg2: -> IOSockJob.
;             Arg3: Error code.
; Return:     eax = Command.

Method NetComProtocol.OnError,, pConnection:$ObjPtr(NetComConnection), pIOSockJob:PIO_SOCKJOB, \
                                dError:DWORD
;  DbgHex pConnection, "NetComProtocol.OnError", "&PROTOCOL_WND_NAME"
;  DbgDec dError,, "&PROTOCOL_WND_NAME"
  ?mov xdx, pConnection
  mov xcx, pIOSockJob
  movzx eax, [xcx].IO_SOCKJOB.wOperation
  .if eax == OPERATION_SOCK_ACCEPT
    mov eax, PROT_CMD_REJECT_CONNECTION

  .elseif eax == OPERATION_SOCK_CONNECT
    xBitSet [xdx].$Obj(NetComConnection).dFlags, NCC_DISCONNECTED
    mov eax, PROT_CMD_CLOSE

  .elseif eax == OPERATION_SOCK_WRITE
    xBitSet [xdx].$Obj(NetComConnection).dFlags, NCC_DISCONNECTED
    mov eax, PROT_CMD_CLOSE

  .elseif eax == OPERATION_SOCK_READ
    .if dError == WSAECONNRESET || eax == ERROR_NETNAME_DELETED || eax == ERROR_OPERATION_ABORTED
      xBitSet [xdx].$Obj(NetComConnection).dFlags, NCC_DISCONNECTED
      mov eax, PROT_CMD_CLOSE

    .elseif dError == WSAEDISCON
      DbgText "Error: disconnect"
      xBitSet [xdx].$Obj(NetComConnection).dFlags, NCC_DISCONNECTED
      mov eax, PROT_CMD_CLOSE

    .else
      DbgWarning "An unhandled error has happened..."
      xBitSet [xdx].$Obj(NetComConnection).dFlags, NCC_DISCONNECTED
      mov eax, PROT_CMD_CLOSE

    .endif

  .else
    DbgWarning "Unknown operation", "&PROTOCOL_WND_NAME"
    DbgDec [xdx].IO_SOCKJOB.wOperation,, "&PROTOCOL_WND_NAME"
    xor eax, eax

  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     NetComProtocol.OnTimeout
; Purpose:    A connection timeout occurs.
; Arguments:  Arg1: -> NetComConnection.
; Return:     eax = PROT_CMD_CONTINUE or PROT_CMD_DISCONNECT.

Method NetComProtocol.OnTimeout,, pConnection:$ObjPtr(NetComConnection)
;  DbgHex pConnection, "NetComProtocol.OnTimeout", "&PROTOCOL_WND_NAME"
  mov eax, PROT_CMD_DISCONNECT
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     NetComProtocol.ProcessData
; Purpose:    A client has finished sending us data, now we have to do something with that data.
; Arguments:  Arg1: -> NetComConnection.
;             Arg2: Delimiter index found in NetComProtocol.IsDataComplete?.
; Return:     eax = Number of processed bytes.

Method NetComProtocol.ProcessData,, pConnection:$ObjPtr(NetComConnection), dDelimiterIndex:DWORD
;  DbgHex pConnection, "NetComProtocol.ProcessData", "&PROTOCOL_WND_NAME"
  mov eax, dDelimiterIndex
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     NetComProtocol.Release
; Purpose:    Release the memory chunk allocated with Allocate. Additional resources must be freed
;             here.
; Arguments:  Arg1: -> NetComConnection.
; Return:     Nothing.

Method NetComProtocol.Release,, pConnection:$ObjPtr(NetComConnection)
;  DbgHex pConnection, "NetComProtocol.Release", "&PROTOCOL_WND_NAME"
MethodEnd

endif
