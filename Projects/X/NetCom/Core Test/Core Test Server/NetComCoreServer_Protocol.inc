; ==================================================================================================
; Title:      NetComCoreServer_Protocol.inc
; Author:     G. Friedrich
; Version:    See NetComCoreServer.asm
; Purpose:    NetCom Server Application.
; ==================================================================================================


SRVPROTDATA struc
  pNextIOData   POINTER   ?
SRVPROTDATA ends

Object NetComCoreServerProtocol,, NetComProtocol
  RedefineMethod  Allocate,           $ObjPtr(NetComConnection)
  RedefineMethod  IsDataComplete?,    $ObjPtr(NetComConnection)
  RedefineMethod  OnAccepted,         $ObjPtr(NetComConnection)
  RedefineMethod  OnDisconnected,     $ObjPtr(NetComConnection), DWORD, DWORD
  RedefineMethod  ProcessData,        $ObjPtr(NetComConnection), DWORD
  RedefineMethod  Release,            $ObjPtr(NetComConnection)
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ==================================================================================================
;    NetComCoreServerProtocol implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     NetComCoreServerProtocol.Allocate
; Purpose:    Allocates a memory chunk for management data on a per connection basis. Additional
;             related resources can be reserved here. The pointer to the allocated memory must be
;             stored in pProtocolData memver of NetComConnection.
; Arguments:  Arg1: -> NetComConnection
; Return:     Zero if succeeded, otherwise an error code.

Method NetComCoreServerProtocol.Allocate,, pConnection:$ObjPtr(NetComConnection)
;  DbgHex pConnection, "NetComCoreServerProtocol.Allocate", "&PROTOCOL_WND_NAME"
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
; Method:     NetComCoreServerProtocol.IsDataComplete?
; Purpose:    A NetComConnection class will call this method to determine if we have received at
;             least one complete packet, given the rules of your Protocol. This is where your
;             derived class examines the received data looking to find a valid delimiter and doing
;             protocol enforcement.
; Arguments:  Arg1: -> NetComConnection.
; Return:     eax = ERROR_BADPROTOCOL  - The buffer content is not following our protocol.
;                   ERROR_USERQUIT     - The user sent a quit message.
;                   Positive INT32     - Complete packet length.
;                   Zero               - More data needed.
; Note:       Search the last ZTC character in all received buffers.

Method NetComCoreServerProtocol.IsDataComplete?, uses xbx xdi xsi, pConnection:$ObjPtr(NetComConnection)
  local pRcvIOChain:POINTER

;  DbgHex pConnection, "NetComCoreServerProtocol.IsDataComplete?", "&PROTOCOL_WND_NAME"
  ;Compute the first IODATA we want to analyse
  mov xdx, pConnection
  mov xsi, [xdx].$Obj(NetComConnection).pData
  mov xax, [xsi].SRVPROTDATA.pNextIOData
  lea xcx, [xdx].$Obj(NetComConnection).RcvIOJobChain
  mov pRcvIOChain, xcx

  .if xax == NULL || xcx == [xax].SDLL_ITEM.pPrevItem
    mov xbx, [xcx].SDLL_SENTINEL.pFirstItem           ;First item in linked list
  .else
    mov xbx, [xax].SDLL_ITEM.pPrevItem
  .endif

  ;We will scan for a ZTC character
  xor edx, edx
  xor eax, eax
  .while (xbx != pRcvIOChain)
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
; Method:     NetComCoreServerProtocol.OnAccepted
; Purpose:    An inbound connection 'accept' has completed.
; Arguments:  Arg1: -> NetComConnection.
; Return:     Nothing.

Method NetComCoreServerProtocol.OnAccepted, uses xbx xsi, pConnection:$ObjPtr(NetComConnection)
  local cAddrStr[1024]:CHR, dLength:DWORD

;  DbgHex pConnection, "NetComCoreServerProtocol.OnAccepted", "&PROTOCOL_WND_NAME"
  SetObject xsi
  mov xbx, pConnection

  ;Check if the RemoteHost is in the BlackList. If yes, close the NetComConnection
  .if $OCall(xsi.IsBlackListed?, addr [xbx].$Obj(NetComConnection).RemoteAddr) != FALSE
    DbgWarning "NetComCoreServerProtocol.OnAccepted - RemoteHost is blacklisted; connection rejected...", "&PROTOCOL_WND_NAME"
    OCall xbx::NetComConnection.Admit, FALSE
  .else
    mov dLength, lengthof(cAddrStr)
    invoke WSAAddressToString, addr [xbx].$Obj(NetComConnection).LocalAddr, sizeof(sockaddr_in), \
                               NULL, addr cAddrStr, addr dLength
    OCall xbx::NetComConnection.Admit, TRUE
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComCoreServerProtocol.OnDisconnect
; Purpose:    An established connection has been disconnected.
; Arguments:  Arg1: -> NetComConnection.
;             Arg2: Disconnect direction = SD_SEND/SD_RECEIVE/SD_BOTH
;             Arg3: Operation result.
; Return:     Nothing.

Method NetComCoreServerProtocol.OnDisconnected, uses xbx, pConnection:$ObjPtr(NetComConnection), \
                                                      dDirection:DWORD, dResult:DWORD
;  DbgHex pConnection, "NetComCoreServerProtocol.OnDisconnect", "&PROTOCOL_WND_NAME"
  SetObject xsi
  ACall xsi.OnDisconnected, pConnection, dDirection, dResult
  mov xbx, pConnection
  OCall xbx::NetComConnection.QueueDestroy
  OCall xbx::NetComConnection.Close, FALSE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComCoreServerProtocol.ProcessData
; Purpose:    A client has finished sending us data, now we have to do something with that data.
; Arguments:  Arg1: -> NetComConnection.
;             Arg2: Delimiter index found in NetComProtocol.IsDataComplete?.
; Return:     ERROR_BADPROTOCOL  - The buffer content isnt following our protocol.
;             ERROR_USERQUIT     - The user sent a nice QUIT message using our protocol.
;             Positive INT32     - This many bytes were cleanly processed and should be removed
;                                  from the IOJob buffers.

Method NetComCoreServerProtocol.ProcessData,, pConnection:$ObjPtr(NetComConnection), \
                                          dDelimiterIndex:dword
;  DbgHex pConnection, "NetComCoreServerProtocol.ProcessData", "&PROTOCOL_WND_NAME"
  mov eax, dDelimiterIndex
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComCoreServerProtocol.Release
; Purpose:    Releases the memory chunk allocated with Allocate. Additional resources must be freed
;             here.
; Arguments:  Arg1: -> NetComConnection.
; Return:     Nothing.

Method NetComCoreServerProtocol.Release,, pConnection:$ObjPtr(NetComConnection)
;  DbgHex pConnection, "NetComCoreServerProtocol.Release", "&PROTOCOL_WND_NAME"
  mov xax, pConnection
  MemFree [xax].$Obj(NetComConnection).pData
MethodEnd

endif