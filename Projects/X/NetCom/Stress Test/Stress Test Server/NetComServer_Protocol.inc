; ==================================================================================================
; Title:      NetComServer_Protocol.inc
; Author:     G. Friedrich
; Purpose:    Demonstration program.
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Summary:
;   This code implements the server-side protocol handler for the NetCom framework.
;   It manages per-connection state, receives desktop image transmissions from NetCom clients,
;   reassembles data across multiple IO_SOCKJOB buffers, and displays the received images
;   on the DebugCenter. The protocol expects the first DWORD of each transmission to contain
;   the total payload size. The server also handles connection acceptance/rejection,
;   blacklisting, disconnections, and resource cleanup.
; --------------------------------------------------------------------------------------------------

; --------------------------------------------------------------------------------------------------
; SRVPROTDATA
;   Holds per-connection protocol state:
;   - dTotRcvBytes: total bytes received so far for this transmission
;   - pLastIOJob: pointer to the last processed IO_SOCKJOB
;   - dMemSize: expected total transmission size (from first DWORD of client payload)

SRVPROTDATA struc
  dTotRcvBytes    DWORD         ?     ;Total recieved byte count up to the last served IOJob
  pLastIOJob      PIO_SOCKJOB   ?     ;Last served IOJob
  dMemSize        DWORD         ?     ;Required TX length
SRVPROTDATA ends

; --------------------------------------------------------------------------------------------------
; Object:     NetComServerProtocol
; Purpose:    NetComServerProtocol is a descendant of NetComProtocol. It implements the
;             server-side transmission protocol used by the NetCom framework to receive,
;             validate, assemble, and process incoming desktop image data sent by clients.
;
;             The protocol reconstructs a complete transmission from multiple asynchronous
;             IO_SOCKJOB buffers, based on a size-prefixed message format, and renders the
;             received bitmap data to the DebugCenter for visualization.
;
; Notes:      - Each transmission starts with a DWORD specifying the total payload size
;               in bytes (including the DWORD itself).
;             - Per-connection protocol state is stored in a SRVPROTDATA structure and
;               allocated via the Allocate method.
;             - The IsDataComplete? method enforces protocol framing and determines when a
;               full transmission has been received.
;             - ProcessData assembles the payload, builds a DIB bitmap, and displays it.
;             - Connection acceptance may be conditionally rejected using a blacklist.
;             - All protocol state is released when the connection is closed.

Object NetComServerProtocol,, NetComProtocol
  RedefineMethod  Allocate,           $ObjPtr(NetComConnection)
  RedefineMethod  IsDataComplete?,    $ObjPtr(NetComConnection), PIO_SOCKJOB
  RedefineMethod  OnAccepted,         $ObjPtr(NetComConnection)
  RedefineMethod  OnDisconnected,     $ObjPtr(NetComConnection), DWORD
  RedefineMethod  ProcessData,        $ObjPtr(NetComConnection), DWORD   ;-> Connection, Delimiter
  RedefineMethod  Release,            $ObjPtr(NetComConnection)
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ==================================================================================================
;    NetComServerProtocol implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     NetComServerProtocol.Allocate
; Purpose:    Allocates a memory block for management data on a per connection basis.
;             Additional resources can be reserved here. The POINTER to the allocated memory is
;             stored in pProtocolData member of NetComConnection.
; Arguments:  Arg1: -> NetComConnection
; Return:     eax = Zero if succeeded, otherwise an error code.

Method NetComServerProtocol.Allocate,, pConnection:$ObjPtr(NetComConnection)
;  DbgHex pConnection, "NetComServerProtocol.Allocate", "&PROTOCOL_WND_NAME"
  MemAlloc sizeof SRVPROTDATA, MEM_INIT_ZERO            ;Allocate zero-initialized SRVPROTDATA
  .if xax != NULL
    mov xcx, pConnection
    mov [xcx].$Obj(NetComConnection).pData, xax         ;Store pointer in connection object
    xor eax, eax                                        ;Return success
  .else
    OCall ErrorReport, NULL, NCSP_OUT_OF_MEMORY
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComServerProtocol.IsDataComplete?
; Purpose:    Determine if at least one complete transmission has been received.
;             Protocol:
;               - The first DWORD of the payload contains total transmission size.
;               - Data may arrive in multiple IO_SOCKJOB buffers.
; Arguments:  Arg1: -> NetComConnection.
; Return:     eax = ERROR_BADPROTOCOL  - The buffer content is not following our protocol.
;                   ERROR_USERQUIT     - The user sent a quit message.
;                   Positive INT32     - Complete packet length => Process the data
;                   Zero               - More data needed.

Method NetComServerProtocol.IsDataComplete?, uses xsi, pConnection:$ObjPtr(NetComConnection), \
                                                       pIOSockJob:PIO_SOCKJOB
  local pRcvIOChain:PSDLL_SENTINEL

;  DbgHex pConnection, "NetComServerProtocol.IsDataComplete?", "&PROTOCOL_WND_NAME"
  ?mov xdx, pConnection
  mov xsi, [xdx].$Obj(NetComConnection).pData           ;xsi -> SRVPROTDATA
  lea xcx, [xdx].$Obj(NetComConnection).RcvIOChain      ;xcx -> IO job chain sentinel
  mov pRcvIOChain, xcx

  ; ----------------------------------------------------------------------
  ; First IO job: read total transmission size from client
  ; ----------------------------------------------------------------------
  .if [xsi].SRVPROTDATA.pLastIOJob == NULL
    mov xdx, [xcx].SDLL_SENTINEL.pFirstItem             ;First IO_SOCKJOB
    .ifBitSet [xdx - IO_HEADER_SIZE].IO_SOCKJOB.wFlags, IOF_JOB_COMPLETED
      .if [xdx - IO_HEADER_SIZE].IO_SOCKJOB.dBytesConsumed >= 4
        mov xcx, [xdx - IO_HEADER_SIZE].IO_SOCKJOB.WSABuf.buf
        mrm [xsi].SRVPROTDATA.dMemSize, DWORD ptr [xcx], eax    ;Store TX length
      .else
        xor eax, eax                                    ;Need more data
        ExitMethod
      .endif
    .else
      xor eax, eax                                      ;Job not yet complete
      ExitMethod
    .endif
  .endif

  ; ----------------------------------------------------------------------
  ; Accumulate bytes across IO_SOCKJOB chain
  ; ----------------------------------------------------------------------
  .if [xsi].SRVPROTDATA.pLastIOJob == NULL
    mov xcx, pRcvIOChain
    lea xdx, [xcx - IO_HEADER_SIZE]
  .else
    mov xdx, [xsi].SRVPROTDATA.pLastIOJob
  .endif

  mov eax, [xsi].SRVPROTDATA.dMemSize
  .while TRUE
    mov xdx, [xdx].IO_SOCKJOB.pNextItem                 ;Next IO_SOCKJOB
    .break .if xdx == pRcvIOChain                       ;End of chain
    sub xdx, IO_HEADER_SIZE                             ;Correct pointer to structure
    test [xdx].IO_SOCKJOB.wFlags, IOF_JOB_LINKED
    .break .if ZERO?                                    ;Job not active
    mov ecx, [xdx].IO_SOCKJOB.dBytesConsumed
    add [xsi].SRVPROTDATA.dTotRcvBytes, ecx             ;Update total received
    mov [xsi].SRVPROTDATA.pLastIOJob, xdx
    .break .if eax <= [xsi].SRVPROTDATA.dTotRcvBytes    ;Complete packet received?
  .endw

  mov eax, [xsi].SRVPROTDATA.dMemSize
  .if eax > [xsi].SRVPROTDATA.dTotRcvBytes
    xor eax, eax                                        ;Incomplete
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComServerProtocol.OnAccepted
; Purpose:    Handle incoming connection requests.
;             Reject if remote host is blacklisted.
; Arguments:  Arg1: -> NetComConnection
; Return:     eax = CMD_ACCEPT_CONNECTION or CMD_REJECT_CONNECTION

Method NetComServerProtocol.OnAccepted, uses xbx xsi, pConnection:$ObjPtr(NetComConnection)
  local cAddrStr[1024]:CHR

;  DbgHex pConnection, "NetComServerProtocol.OnAccept", "&PROTOCOL_WND_NAME"
  SetObject xsi
  mov xbx, pConnection
  if DEBUGGING
    invoke GetNameInfo, addr [xbx].$Obj(NetComConnection).RemoteAddr, sizeof NETCOMADDR, \
                        addr cAddrStr, lengthof cAddrStr, NULL, 0, NI_NUMERICHOST
    invoke DbgOutText, addr cAddrStr, DbgColorString, DbgColorBackground, DBG_EFFECT_NORMAL, ??DbgDstWnd
    invoke DbgOutText, $OfsCStr(" is requesting a connection..."), \
                       DbgColorString, DbgColorBackground, DBG_EFFECT_NEWLINE, ??DbgDstWnd
  endif

  .if $OCall(xsi.IsBlackListed?, addr [xbx].$Obj(NetComConnection).RemoteAddr) != FALSE
    DbgWarning "RemoteHost is blacklisted; Connection rejected", "&PROTOCOL_WND_NAME"
    OCall pConnection::NetComConnection.Allow, FALSE
    mov eax, PROT_CMD_REJECT_CONNECTION
  .else
    DbgText "RemoteHost is OK; Connection accepted", "&PROTOCOL_WND_NAME"
    OCall pConnection::NetComConnection.Allow, TRUE
    mov eax, PROT_CMD_ACCEPT_CONNECTION
  .endif
  DbgLine
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComServerProtocol.OnDisconnected
; Purpose:    Marks connection as free and calls base disconnection handler
; Arguments:  Arg1: -> NetComConnection.
;             Arg2: Disconnect direction = SD_SEND/SD_RECEIVE/SD_BOTH
; Return:     Nothing.

Method NetComServerProtocol.OnDisconnected, uses xbx, pConnection:$ObjPtr(NetComConnection), dDirection:DWORD
  DbgHex pConnection, "NetComServerProtocol.OnDisconnect", "&PROTOCOL_WND_NAME"
  mov xbx, pConnection
;  OCall xbx::NetComConnection.Disconnect, SD_SEND     ;Graceful disconnect
  OCall xbx::NetComConnection.QueueDestroy            ;Mark for destruction
  OCall xbx::NetComConnection.Close, FALSE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComServerProtocol.ProcessData
; Purpose:    Reassemble complete payload, build bitmap, and display.
;             The first DWORD of the payload contains the total size in bytes.
; Arguments:  Arg1: -> NetComConnection
;             Arg2: Transmission length from IsDataComplete?
; Return:     eax = Number of bytes processed.

Method NetComServerProtocol.ProcessData, uses xbx xdi xsi, pConnection:$ObjPtr(NetComConnection), \
                                                           TransmitionLength:dword
  local dConsumed:DWORD, pMemory:POINTER, dRetval:DWORD
  local hNewBmp:HBITMAP, hPrvBmp:HBITMAP, hScreenDC:HDC, hMemDC:HANDLE
  local dSizeX:DWORD, dSizeY:DWORD, pBuffer:POINTER, wCaptionDC[100]:CHRW

;  DbgHex pConnection, "NetComServerProtocol.ProcessData", "&PROTOCOL_WND_NAME"
  SetObject xsi, NetComConnection, pConnection
  mov eax, TransmitionLength
  mov dConsumed, eax
  mov dRetval, eax
  MemAlloc eax                                          ;Allocate contiguous buffer for payload
  mov pMemory, xax
  mov pBuffer, xax

  ; ----------------------------------------------------------------------
  ; Copy data from IO_SOCKJOB chain into contiguous buffer
  ; ----------------------------------------------------------------------
  lea xdi, [xsi].RcvIOChain
  mov xbx, [xdi].SDLL_SENTINEL.pFirstItem
  .while xbx != xdi && dConsumed != 0
    mov eax, [xbx - IO_HEADER_SIZE].IO_SOCKJOB.dBytesConsumed
    .if eax <= dConsumed
      sub dConsumed, eax
      lea xdx, [xbx - IO_HEADER_SIZE]
      mov xbx, [xbx].SDLL_ITEM.pNextItem
      mov xcx, pMemory
      add pMemory, xax
      invoke MemClone, xcx, [xdx].IO_SOCKJOB.WSABuf.buf, eax
    .else
      lea xdx, [xbx - IO_HEADER_SIZE]
      invoke MemClone, pMemory, [xdx].IO_SOCKJOB.WSABuf.buf, dConsumed
      .break
    .endif
  .endw

  ; ----------------------------------------------------------------------
  ; Build bitmap from received data and display on DebugCenter
  ; ----------------------------------------------------------------------
  mov hScreenDC, $invoke(GetDC, 0)
  mov hMemDC, $invoke(CreateCompatibleDC, hScreenDC)
  mov xbx, pBuffer
  add xbx, sizeof(DWORD)                                ;Skip total size DWORD
  m2m dSizeX, [xbx].BITMAPINFO.bmiHeader.biWidth, eax
  m2m dSizeY, [xbx].BITMAPINFO.bmiHeader.biHeight, ecx
  mov hNewBmp, $invoke(CreateCompatibleBitmap, hScreenDC, dSizeX, dSizeY)
  mov hPrvBmp, $invoke(SelectObject, hMemDC, hNewBmp)
  lea xax, [xbx + sizeof(BITMAPINFO)]
  invoke SetDIBits, hMemDC, hNewBmp, 0, dSizeY, xax, xbx, DIB_RGB_COLORS
  invoke SelectObject, hMemDC, hPrvBmp
  invoke DeleteDC, hMemDC
  invoke ReleaseDC, 0, hScreenDC
  invoke StrECopyW, addr wCaptionDC, $OfsCStrW("Desktop image from connection ")
  invoke xword2hexW, xax, pConnection
  invoke DbgOutBitmap, hNewBmp, $RGB(0,0,0), addr wCaptionDC
  invoke DeleteObject, hNewBmp

  MemFree pBuffer                                       ;Release assembled payload

  ; ----------------------------------------------------------------------
  ; Reset protocol state for next transmission
  ; ----------------------------------------------------------------------
  mov xbx, [xsi].pData
  mov [xbx].SRVPROTDATA.dMemSize, 0
  mov [xbx].SRVPROTDATA.dTotRcvBytes, 0
  mov [xbx].SRVPROTDATA.pLastIOJob, NULL
  mov eax, dRetval
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComServerProtocol.Release
; Purpose:    Release protocol memory allocated by Allocate
; Arguments:  Arg1: -> NetComConnection
; Return:     Nothing.

Method NetComServerProtocol.Release,, pConnection:$ObjPtr(NetComConnection)
;  DbgHex pConnection, "NetComServerProtocol.Release", "&PROTOCOL_WND_NAME"
  mov xax, pConnection
  MemFree [xax].$Obj(NetComConnection).pData
MethodEnd

endif
