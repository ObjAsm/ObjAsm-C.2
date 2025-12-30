; ==================================================================================================
; Title:      SRP_Protocol.inc
; Author:     G. Friedrich
; Version:    See SRP.asm
; Purpose:    Reverse Proxy Protocol for a bidirectional reverse proxy.
; Note:       Minimal TCP reverse proxy (forwarding) using NetCom
; ==================================================================================================


REVPROXYDATA struc
  pPeerConn       $ObjPtr(NetComConnection) ? ;Paired connection (client <-> backend)
REVPROXYDATA ends

Object NetComReverseProxyProtocol,, NetComProtocol
  RedefineMethod  Allocate,           $ObjPtr(NetComConnection)
  RedefineMethod  IsDataComplete?,    $ObjPtr(NetComConnection), PIO_SOCKJOB
  RedefineMethod  OnAccept,           $ObjPtr(NetComConnection)
  RedefineMethod  OnDisconnect,       $ObjPtr(NetComConnection)
  RedefineMethod  ProcessData,        $ObjPtr(NetComConnection), dword
  RedefineMethod  Release,            $ObjPtr(NetComConnection)
ObjectEnd


; ==================================================================================================

if IMPLEMENT

PROTOCOL_WND_NAME textequ <SRP-Protocol>

; ==================================================================================================
;    NetComReverseProxyProtocol implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     NetComReverseProxyProtocol.Allocate
; Purpose:    Allocates a memory block for management data on a per connection basis.
;             Additional resources can be reserved here.
; Arguments:  Arg1: -> NetComConnection
; Return:     Zero if succeeded, otherwise an error code.

Method NetComReverseProxyProtocol.Allocate,, pConnection:$ObjPtr(NetComConnection)
;  DbgHex pConnection, "NetComReverseProxyProtocol.Allocate", "&PROTOCOL_WND_NAME"
  MemAlloc sizeof REVPROXYDATA, MEM_INIT_ZERO
  .if xax != NULL
    mov xcx, pConnection
    mov [xcx].$Obj(NetComConnection).pProtocolData, xax
    xor eax, eax
  .else
    OCall ErrorReport, NULL, NCSP_OUT_OF_MEMORY
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComReverseProxyProtocol.IsDataComplete?
; Purpose:    Determines if received data is complete.
;             Streaming proxy: any completed IO job is valid.
; Arguments:  Arg1: -> NetComConnection
; Return:     Positive INT32 - complete data length
;             Zero           - need more data

Method NetComReverseProxyProtocol.IsDataComplete?,, pConnection:$ObjPtr(NetComConnection), \
                                                    pIOSockJob:PIO_SOCKJOB
;  DbgHex pConnection, "NetComReverseProxyProtocol.IsDataComplete?", "&PROTOCOL_WND_NAME"
  mov xcx, pIOSockJob
  mov eax, [xcx].IO_SOCKJOB.dBytesConsumed
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComReverseProxyProtocol.OnAccept
; Purpose:    An inbound connection 'accept' has completed.
;             Establish backend connection and pair both sides.
; Arguments:  Arg1: -> NetComConnection
; Return:     eax = CMD_ACCEPT_CONNECTION or CMD_REJECT_CONNECTION

Method NetComReverseProxyProtocol.OnAccept, uses xbx xsi, pConnection:$ObjPtr(NetComConnection)
;  DbgHex pConnection, "NetComReverseProxyProtocol.OnAccept", "&PROTOCOL_WND_NAME"
  ;Connect to the destination Server
  SetObject xsi
  mov xbx, [xsi].pOwner                                 ;xbx -> Application
  OCall [xbx].$Obj(Application).RevProxy::NetComEngine.ConnectTo, xsi, \
                                                       addr [xbx].$Obj(Application).DestAddr
  .if xax == NULL
    mov eax, PROT_CMD_REJECT_CONNECTION
  .else
    ;Pair connections
    mov xcx, pConnection
    mov xdx, [xcx].$Obj(NetComConnection).pProtocolData
    mov [xdx].REVPROXYDATA.pPeerConn, xax
    mov xdx, [xax].$Obj(NetComConnection).pProtocolData
    mov [xdx].REVPROXYDATA.pPeerConn, xcx
  
    mov eax, PROT_CMD_ACCEPT_CONNECTION
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComReverseProxyProtocol.OnDisconnect
; Purpose:    An established connection has been disconnected.
;             Tear down the paired connection as well.
; Arguments:  Arg1: -> NetComConnection
; Return:     eax = Command.

Method NetComReverseProxyProtocol.OnDisconnect, uses xdi, pConnection:$ObjPtr(NetComConnection)
;  DbgHex pConnection, "NetComReverseProxyProtocol.OnDisconnect", "&PROTOCOL_WND_NAME"
  ?mov xdi, pConnection
  mov xax, [xdi].$Obj(NetComConnection).pProtocolData
  mov xcx, [xax].REVPROXYDATA.pPeerConn

  .if xcx != NULL
    ;Break pairing to avoid recursion
    mov [xax].REVPROXYDATA.pPeerConn, NULL
    OCall xcx::NetComConnection.Disconnect, SD_BOTH
  .endif

  xBitSet [xdi].$Obj(NetComConnection).dFlags, NCC_FREE_MARKED
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComReverseProxyProtocol.ProcessData
; Purpose:    Forwards received data to the paired connection.
; Arguments:  Arg1: -> NetComConnection
;             Arg2: Transmission length
; Return:     Positive INT32 - bytes processed

Method NetComReverseProxyProtocol.ProcessData, uses xbx xdi xsi, \
                                               pConnection:$ObjPtr(NetComConnection), \
                                               TransmitionLength:dword
;  DbgHex pConnection, "NetComReverseProxyProtocol.ProcessData", "&PROTOCOL_WND_NAME"
  ?mov xdx, pConnection
  mov xsi, [xdx].$Obj(NetComConnection).pProtocolData
  mov xdi, [xsi].REVPROXYDATA.pPeerConn
  .if xdi == NULL
    xor eax, eax
    ExitMethod
  .endif
  
  .ifBitSet [xdi].$Obj(NetComConnection).dFlags, NCC_DISCONNECTED
    DbgHex xdi, "NetComReverseProxyProtocol.ProcessData =!> Disconnected"
    xor eax, eax
    ExitMethod
  .endif
  
  lea xcx, [xdx].$Obj(NetComConnection).RcvIOChain
  mov xbx, [xcx].SDLL_SENTINEL.pFirstItem

  .while xbx != xcx
    lea xsi, [xbx - IO_HEADER_SIZE]
    test [xsi].IO_SOCKJOB.wFlags, IOF_JOB_COMPLETED
    .break .if ZERO?

    mov eax, [xsi].IO_SOCKJOB.dBytesConsumed
    .if eax != 0
      OCall xdi::NetComConnection.QueueWrite, [xsi].IO_SOCKJOB.WSABuf.buf, \
                                              [xsi].IO_SOCKJOB.dBytesConsumed
    .endif

    mov xbx, [xbx].SDLL_ITEM.pNextItem
  .endw

  mov eax, TransmitionLength
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComReverseProxyProtocol.Release
; Purpose:    Releases the memory chunk allocated with Allocate.
; Arguments:  Arg1: -> NetComConnection
; Return:     Nothing.

Method NetComReverseProxyProtocol.Release,, pConnection:$ObjPtr(NetComConnection)
;  DbgHex pConnection, "NetComReverseProxyProtocol.Release", "&PROTOCOL_WND_NAME"
  ?mov xdx, pConnection
  mov xax, [xdx].$Obj(NetComConnection).pProtocolData
  MemFree xax
MethodEnd

endif
