; ==================================================================================================
; Title:      NetComServer_Protocol.inc
; Author:     G. Friedrich
; Version:    See NetComServer.asm
; Purpose:    NetCom Server Application.
; ==================================================================================================


;If you use a browser, use the following address to connect to the server: http://127.0.0.1:25773

SRVPROTDATA struc
  pNextIOData   POINTER   ?
SRVPROTDATA ends

Object NetComServerProtocol,, NetComProtocol
  RedefineMethod  Allocate,           $ObjPtr(NetComConnection)
  RedefineMethod  IsDataComplete?,    $ObjPtr(NetComConnection)          ;-> NetComConnection
  RedefineMethod  OnAccept,           $ObjPtr(NetComConnection)          ;-> NetComConnection
  RedefineMethod  OnDisconnect,       $ObjPtr(NetComConnection)          ;-> NetComConnection
  RedefineMethod  ProcessData,        $ObjPtr(NetComConnection), dword   ;-> NetComConnection, DelimiterIndex
  RedefineMethod  Release,            $ObjPtr(NetComConnection)
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ==================================================================================================
;    NetComServerProtocol implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     NetComServerProtocol.Allocate
; Purpose:    Allocates a memory chunk for management data on a per connection basis. Additional
;             related resources can be reserved here. The pointer to the allocated memory must be
;             stored in pProtocolData memver of NetComConnection.
; Arguments:  Arg1: -> NetComConnection
; Return:     Zero if succeeded, otherwise an error code.

Method NetComServerProtocol.Allocate,, pConnection:$ObjPtr(NetComConnection)
  DbgHex pConnection, "NetComServerProtocol.Allocate", "&PROTOCOL_WND_NAME"
  MemAlloc sizeof SRVPROTDATA
  .if xax != NULL
    mov xcx, pConnection
    mov [xcx].$Obj(NetComConnection).pProtocolData, xax
    m2z [xax].SRVPROTDATA.pNextIOData
    xor eax, eax
  .else
    OCall ErrorReport, NULL, NCSP_OUT_OF_MEMORY
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComServerProtocol.IsDataComplete?
; Purpose:    A NetComConnection class will call this method to determine if we have received at
;             least one complete packet, given the rules of your Protocol. This is where your
;             derived class examines the received data looking to find a valid Delimiter and doing
;             protocol enforcement.
; Arguments:  Arg1: -> NetComConnection.
; Return:     ERROR_BADPROTOCOL  - The buffer content is not following our protocol.
;             ERROR_USERQUIT     - The user sent a nice QUIT message using our protocol.
;             Positive INT32     - This many bytes are part of the complete packet.
;             Zero               - We need more data.

; Search the last "@" character in all buffers

Method NetComServerProtocol.IsDataComplete?, uses xbx xdi xsi, pConnection:$ObjPtr(NetComConnection)
  local pRcvIOChain:POINTER

  DbgHex pConnection, "NetComServerProtocol.IsDataComplete?", "&PROTOCOL_WND_NAME"
  ;Compute the first IODATA we want to analyse
  mov xdx, pConnection
  mov xsi, [xdx].$Obj(NetComConnection).pProtocolData
  mov xax, [xsi].SRVPROTDATA.pNextIOData
  lea xcx, [xdx].$Obj(NetComConnection).RcvIOChain
  mov pRcvIOChain, xcx

  .if xax == NULL || xcx == [xax].SDLL_ITEM.pPrevItem
    mov xbx, [xcx].SDLL_SENTINEL.pFirstItem           ;First item in linked list
  .else
    mov xbx, [xax].SDLL_ITEM.pPrevItem
  .endif

  ;We will scan for a "@" character
  xor edx, edx
  xor eax, eax
  .while (xbx != pRcvIOChain) && ([xbx - IO_HEADER_SIZE].IO_SOCKJOB.wFlags & IOF_JOB_ENGAGED)
    ;Stop on first non ready buffer
    mov xdi, [xbx - IO_HEADER_SIZE].IO_SOCKJOB.WSABuf.buf
    xor ecx, ecx
    .while ecx < [xbx - IO_HEADER_SIZE].IO_SOCKJOB.dBytesConsumed
      inc edx
      .if byte ptr [xdi] == "@"
        mov eax, edx
      .endif
      inc ecx
      inc xdi
    .endw
    mov xbx, [xbx].SDLL_ITEM.pNextItem
  .endw
  mov [xsi].SRVPROTDATA.pNextIOData, xbx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComServerProtocol.OnAccept
; Purpose:    An inbound connection 'accept' has completed.
; Arguments:  Arg1: -> NetComConnection.
; Return:     eax = command (CMD_ACCEPT_CONNECTION or CMD_REJECT_CONNECTION).

Method NetComServerProtocol.OnAccept, uses xbx xsi, pConnection:$ObjPtr(NetComConnection)
  local cAddrStr[1024]:CHR, dLength:DWORD

  DbgHex pConnection, "NetComServerProtocol.OnAccept", "&PROTOCOL_WND_NAME"
  SetObject xsi
  mov xbx, pConnection
  if DEBUGGING
    DbgLine
    DbgText "RemoteHost is requesting a connection"
    DbgHex [xbx].$Obj(NetComConnection).RemoteHostAddr.sin_addr, 
    DbgHex WORD ptr [xbx].$Obj(NetComConnection).RemoteHostAddr.sin_port
  endif

  ;Check if the RemoteHost is in the BlackList. If yes, close the NetComConnection
  .if $OCall(xsi.IsBlackListed?, addr [xbx].$Obj(NetComConnection).RemoteHostAddr) != FALSE
    DbgWarning "RemoteHost is blacklisted; connection rejected..."
    mov eax, PROT_CMD_REJECT_CONNECTION
  .else
    DbgText "RemoteHost is OK; connection granded..."
    
    mov dLength, lengthof(cAddrStr)
    invoke WSAAddressToString, addr [xbx].$Obj(NetComConnection).LocalHostAddr, sizeof(sockaddr_in), \
                               NULL, \
                               addr cAddrStr, addr dLength
    DbgStr cAddrStr
    mov eax, PROT_CMD_ACCEPT_CONNECTION
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComServerProtocol.OnDisconnect
; Purpose:    An established connection has been disconnected.
; Arguments:  Arg1: -> NetComConnection.
; Return:     eax = Command.

Method NetComServerProtocol.OnDisconnect, uses xsi, pConnection:$ObjPtr(NetComConnection)
  DbgHex pConnection, "NetComServerProtocol.OnDisconnect", "&PROTOCOL_WND_NAME"
  SetObject xsi
  ACall xsi.OnDisconnect, pConnection
  mov xdx, pConnection
  BitSet [xdx].$Obj(NetComConnection).dFlags, NCC_FREE_MARKED
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComServerProtocol.ProcessData
; Purpose:    A client has finished sending us data, now we have to do something with that data.
; Arguments:  Arg1: -> NetComConnection.
;             Arg2: Delimiter index found in NetComProtocol.IsDataComplete?.
; Return:     ERROR_BADPROTOCOL  - The buffer content isnt following our protocol.
;             ERROR_USERQUIT     - The user sent a nice QUIT message using our protocol.
;             Positive INT32     - This many bytes were cleanly processed and should be removed
;                                  from the IOJob buffers.

Method NetComServerProtocol.ProcessData,, pConnection:$ObjPtr(NetComConnection), \
                                          dDelimiterIndex:dword
  DbgHex pConnection, "NetComServerProtocol.ProcessData", "&PROTOCOL_WND_NAME"
  mov eax, dDelimiterIndex
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComServerProtocol.Release
; Purpose:    Releases the memory chunk allocated with Allocate. Additional resources must be freed
;             here.
; Arguments:  Arg1: -> NetComConnection.
; Return:     Nothing.

Method NetComServerProtocol.Release,, pConnection:$ObjPtr(NetComConnection)
  DbgHex pConnection, "NetComServerProtocol.Release", "&PROTOCOL_WND_NAME"
  mov xax, pConnection
  MemFree [xax].$Obj(NetComConnection).pProtocolData
MethodEnd

endif