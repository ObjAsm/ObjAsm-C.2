; ==================================================================================================
; Title:      NetComServer_Protocol.inc
; Author:     G. Friedrich
; Version:    See NetComServer.asm
; Purpose:    NetCom Server Application.
; ==================================================================================================


SRVPROTDATA struc
  pNextIOData   POINTER   ?
SRVPROTDATA ends

Object NetComServerProtocol,, NetComProtocol
  RedefineMethod  Allocate,           $ObjPtr(NetComConnection)
  RedefineMethod  IsDataComplete?,    $ObjPtr(NetComConnection)          ;-> NetComConnection
  RedefineMethod  OnAccepted,         $ObjPtr(NetComConnection)          ;-> NetComConnection
  RedefineMethod  OnDisconnected,     $ObjPtr(NetComConnection), DWORD   ;-> NetComConnection
  RedefineMethod  ProcessData,        $ObjPtr(NetComConnection), DWORD   ;-> NetComConnection, DelimiterIndex
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
;  DbgHex pConnection, "NetComServerProtocol.Allocate", "&PROTOCOL_WND_NAME"
  MemAlloc sizeof SRVPROTDATA
  .if xax != NULL
    mov xcx, pConnection
    mov [xcx].$Obj(NetComConnection).pData, xax
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
; Return:     eax = ERROR_BADPROTOCOL  - The buffer content is not following our protocol.
;                   ERROR_USERQUIT     - The user sent a quit message.
;                   Positive INT32     - Complete packet length.
;                   Zero               - More data needed.
; Note:       Search the last ZTC character in all received buffers.

Method NetComServerProtocol.IsDataComplete?, uses xbx xdi xsi, pConnection:$ObjPtr(NetComConnection)
  local pRcvIOChain:POINTER

;  DbgHex pConnection, "NetComServerProtocol.IsDataComplete?", "&PROTOCOL_WND_NAME"
  ;Compute the first IODATA we want to analyse
  mov xdx, pConnection
  mov xsi, [xdx].$Obj(NetComConnection).pData
  mov xax, [xsi].SRVPROTDATA.pNextIOData
  lea xcx, [xdx].$Obj(NetComConnection).RcvIOChain
  mov pRcvIOChain, xcx

  .if xax == NULL || xcx == [xax].SDLL_ITEM.pPrevItem
    mov xbx, [xcx].SDLL_SENTINEL.pFirstItem           ;First item in linked list
  .else
    mov xbx, [xax].SDLL_ITEM.pPrevItem
  .endif

  ;We will scan for a ZTC character
  xor edx, edx
  xor eax, eax
  .while (xbx != pRcvIOChain) && ([xbx - IO_HEADER_SIZE].IO_SOCKJOB.wFlags & IOF_JOB_LINKED)
    ;Stop on first non ready buffer
    mov xdi, [xbx - IO_HEADER_SIZE].IO_SOCKJOB.WSABuf.buf
    xor ecx, ecx
    .while ecx < [xbx - IO_HEADER_SIZE].IO_SOCKJOB.dBytesConsumed
      inc edx
      .if CHRA ptr [xdi] == 0
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
; Method:     NetComServerProtocol.OnAccepted
; Purpose:    An inbound connection 'accept' has completed.
; Arguments:  Arg1: -> NetComConnection.
; Return:     eax = command (CMD_ACCEPT_CONNECTION or CMD_REJECT_CONNECTION).

Method NetComServerProtocol.OnAccepted, uses xbx xsi, pConnection:$ObjPtr(NetComConnection)
  local cAddrStr[1024]:CHR, dLength:DWORD

;  DbgHex pConnection, "NetComServerProtocol.OnAccepted", "&PROTOCOL_WND_NAME"
  SetObject xsi
  mov xbx, pConnection

  ;Check if the RemoteHost is in the BlackList. If yes, close the NetComConnection
  .if $OCall(xsi.IsBlackListed?, addr [xbx].$Obj(NetComConnection).RemoteAddr) != FALSE
    DbgWarning "NetComServerProtocol.OnAccepted - RemoteHost is blacklisted; connection rejected...", "&PROTOCOL_WND_NAME"
    OCall xbx::NetComConnection.Allow, FALSE
    mov eax, PROT_CMD_REJECT_CONNECTION
  .else
;    DbgText "NetComServerProtocol.OnAccepted - RemoteHost is OK; connection granded...", "&PROTOCOL_WND_NAME"

    mov dLength, lengthof(cAddrStr)
    invoke WSAAddressToString, addr [xbx].$Obj(NetComConnection).LocalAddr, sizeof(sockaddr_in), \
                               NULL, addr cAddrStr, addr dLength
;    DbgStr cAddrStr
    OCall xbx::NetComConnection.Allow, TRUE
    mov eax, PROT_CMD_ACCEPT_CONNECTION
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComServerProtocol.OnDisconnect
; Purpose:    An established connection has been disconnected.
; Arguments:  Arg1: -> NetComConnection.
;             Arg2: Disconnect direction = SD_SEND/SD_RECEIVE/SD_BOTH
; Return:     Nothing.

Method NetComServerProtocol.OnDisconnected, uses xbx, pConnection:$ObjPtr(NetComConnection), dDirection:DWORD
;  DbgHex pConnection, "NetComServerProtocol.OnDisconnect", "&PROTOCOL_WND_NAME"
  SetObject xsi
  ACall xsi.OnDisconnected, pConnection, dDirection
  mov xbx, pConnection
  OCall xbx::NetComConnection.QueueDestroy
  OCall xbx::NetComConnection.Close, FALSE
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
;  DbgHex pConnection, "NetComServerProtocol.ProcessData", "&PROTOCOL_WND_NAME"
  mov eax, dDelimiterIndex
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComServerProtocol.Release
; Purpose:    Releases the memory chunk allocated with Allocate. Additional resources must be freed
;             here.
; Arguments:  Arg1: -> NetComConnection.
; Return:     Nothing.

Method NetComServerProtocol.Release,, pConnection:$ObjPtr(NetComConnection)
;  DbgHex pConnection, "NetComServerProtocol.Release", "&PROTOCOL_WND_NAME"
  mov xax, pConnection
  MemFree [xax].$Obj(NetComConnection).pData
MethodEnd

endif