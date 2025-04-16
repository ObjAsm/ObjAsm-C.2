; ==================================================================================================
; Title:      NetComServer_Protocol.inc
; Author:     G. Friedrich
; Purpose:    Demonstration program.
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


SRVPROTDATA struc
  dTotRcvBytes    DWORD         ?     ;Total recieved byte count up to the last served IOJob 
  pLastIOJob      PIO_SOCKJOB   ?     ;Last served IOJob
  dMemSize        DWORD         ?     ;Required TX length
SRVPROTDATA ends

Object NetComServerProtocol,, NetComProtocol
  RedefineMethod  Allocate,           $ObjPtr(NetComConnection)
  RedefineMethod  IsDataComplete?,    $ObjPtr(NetComConnection), PIO_SOCKJOB
  RedefineMethod  OnAccept,           $ObjPtr(NetComConnection)
  RedefineMethod  OnDisconnect,       $ObjPtr(NetComConnection)
  RedefineMethod  ProcessData,        $ObjPtr(NetComConnection), dword   ;-> Connection, Delimiter
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
; Return:     Zero if succeeded, otherwise an error code.

Method NetComServerProtocol.Allocate,, pConnection:$ObjPtr(NetComConnection)
  DbgHex pConnection, "NetComServerProtocol.Allocate", "&PROTOCOL_WND_NAME"
  MemAlloc sizeof SRVPROTDATA, MEM_INIT_ZERO
  .if xax != NULL
    mov xcx, pConnection
    mov [xcx].$Obj(NetComConnection).pProtocolData, xax
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
;             Positive INT32     - This many bytes are the complete packet length.
;             Zero               - We need more data.

Method NetComServerProtocol.IsDataComplete?, uses xsi, pConnection:$ObjPtr(NetComConnection), \
                                                       pIOSockJob:PIO_SOCKJOB
  local pRcvIOChain:PSDLL_SENTINEL

;  DbgHex pConnection, "NetComServerProtocol.IsDataComplete?", "&PROTOCOL_WND_NAME"
  ?mov xdx, pConnection
  mov xsi, [xdx].$Obj(NetComConnection).pProtocolData   ;xsi -> SRVPROTDATA
  lea xcx, [xdx].$Obj(NetComConnection).RcvIOChain      ;xcx -> SDLL_SENTINEL
  mov pRcvIOChain, xcx

  .if [xsi].SRVPROTDATA.pLastIOJob == NULL
    ;We are here since we got an IO_SOCKJOB serviced.
    ;That means, that pFirstItem != Sentinel
    mov xdx, [xcx].SDLL_SENTINEL.pFirstItem             ;First IO_SOCKJOB
    .ifBitSet [xdx - IO_HEADER_SIZE].IO_SOCKJOB.wFlags, IOF_JOB_COMPLETED
      .if [xdx - IO_HEADER_SIZE].IO_SOCKJOB.dBytesConsumed >= 4 ;At least we have the TX length
        mov xcx, [xdx - IO_HEADER_SIZE].IO_SOCKJOB.WSABuf.buf
        mrm [xsi].SRVPROTDATA.dMemSize, DWORD ptr [xcx], eax    ;TX length
      .else
        xor eax, eax                                    ;Get more data
        ExitMethod
      .endif
    .else
      xor eax, eax                                      ;Get more data
      ExitMethod
    .endif
  .endif

;  ; ********************************************************
;  preserve xbx xdi !!!
;  mov xdi, pRcvIOChain
;  lea xbx, [xdi - IO_HEADER_SIZE]
;  .while TRUE
;    mov xbx, [xbx].IO_SOCKJOB.pNextItem
;    .break .if xbx == pRcvIOChain 
;    sub xbx, IO_HEADER_SIZE                             ;Correct POINTER to beginning of structure
;
;    mov ecx, [xbx].IO_SOCKJOB.dBytesConsumed
;    test ecx, ecx
;    .if ZERO?
;      mov edx, $RGB(255,0,0)
;    .else
;      mov edx, $RGB(0,0,255)
;    .endif
;
;    test [xbx].IO_SOCKJOB.wFlags, IOF_JOB_COMPLETED
;    .if ZERO?
;      mov xcx, $OfsCStr("0")
;    .else
;      mov xcx, $OfsCStr("1")
;    .endif
;    invoke DbgOutText, xcx, edx, DbgColorBackground, DBG_EFFECT_NORMAL, ??DbgDstWnd
;  .endw
;  invoke DbgOutText, $OfsCStr(" "), DbgColorForeground, DbgColorBackground, DBG_EFFECT_NEWLINE, ??DbgDstWnd
;  ; ********************************************************

  .if [xsi].SRVPROTDATA.pLastIOJob == NULL
    mov xcx, pRcvIOChain
    lea xdx, [xcx - IO_HEADER_SIZE]
  .else
    mov xdx, [xsi].SRVPROTDATA.pLastIOJob
  .endif

  mov eax, [xsi].SRVPROTDATA.dMemSize
  .while TRUE
    mov xdx, [xdx].IO_SOCKJOB.pNextItem                 ;Move to the next IO_SOCKJOB Item
    .break .if xdx == pRcvIOChain                       ;End of chain
    sub xdx, IO_HEADER_SIZE                             ;Correct POINTER to beginning of structure
    test [xdx].IO_SOCKJOB.wFlags, IOF_JOB_ENGAGED
    .break .if ZERO?                                    ;Is it pending IOJob?
    mov ecx, [xdx].IO_SOCKJOB.dBytesConsumed
    add [xsi].SRVPROTDATA.dTotRcvBytes, ecx
    mov [xsi].SRVPROTDATA.pLastIOJob, xdx
    .break .if eax <= [xsi].SRVPROTDATA.dTotRcvBytes
  .endw

  mov eax, [xsi].SRVPROTDATA.dMemSize
  .if eax > [xsi].SRVPROTDATA.dTotRcvBytes
    xor eax, eax                                        ;Get more data, otherwise We have the
  .endif                                                ;  complete data! (and maybe more...)
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComServerProtocol.OnAccept
; Purpose:    An inbound connection 'accept' has completed.
; Arguments:  Arg1: -> NetComConnection.
; Return:     eax = command (CMD_ACCEPT_CONNECTION or CMD_REJECT_CONNECTION).

Method NetComServerProtocol.OnAccept, uses xbx xsi, pConnection:$ObjPtr(NetComConnection)
  local cAddrStr[1024]:CHR

  DbgHex pConnection, "NetComServerProtocol.OnAccept", "&PROTOCOL_WND_NAME"
  SetObject xsi
  mov xbx, pConnection
  if DEBUGGING
    invoke DbgOutCmd, DBG_CMD_SINGLE_LINE, 0, 0, ??DbgDstWnd
    invoke GetNameInfo, addr [xbx].$Obj(NetComConnection).RemoteHostAddr, sizeof NETCOMADDR, \
                        addr cAddrStr, lengthof cAddrStr, \
                        NULL, 0, \
                        NI_NUMERICHOST
    invoke DbgOutText, addr cAddrStr, DbgColorString, DbgColorBackground, DBG_EFFECT_NORMAL, ??DbgDstWnd
    invoke DbgOutText, $OfsCStr(" is requesting a connection..."), DbgColorString, DbgColorBackground, \
                       DBG_EFFECT_NEWLINE, ??DbgDstWnd
  endif

  ;Check if the RemoteHost is in the BlackList. If yes, close the NetComConnection
  .if $OCall(xsi.IsBlackListed?, addr [xbx].$Obj(NetComConnection).RemoteHostAddr) != FALSE
    DbgWarning "RemoteHost is blacklisted; Connection rejected", "&PROTOCOL_WND_NAME"
    mov eax, PROT_CMD_REJECT_CONNECTION
  .else
    DbgText "RemoteHost is OK; Connection accepted", "&PROTOCOL_WND_NAME"
    mov eax, PROT_CMD_ACCEPT_CONNECTION
  .endif
  DbgLine
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComServerProtocol.OnDisconnect
; Purpose:    An established connection has been disconnected.
; Arguments:  Arg1: -> NetComConnection.
; Return:     eax = Command.

Method NetComServerProtocol.OnDisconnect,, pConnection:$ObjPtr(NetComConnection)
  DbgHex pConnection, "NetComServerProtocol.OnDisconnect", "&PROTOCOL_WND_NAME"
  SetObject xcx
  ACall xcx.OnDisconnect, pConnection
  mov xdx, pConnection
  xBitSet [xdx].$Obj(NetComConnection).dFlags, NCC_FREE_MARKED
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComServerProtocol.ProcessData
; Purpose:    A client has finished sending us data. Now we build the bitmap and display it on
;             DebugCenter.
; Arguments:  Arg1: -> NetComConnection.
;             Arg2: Transmition length found by NetComProtocol.IsDataComplete?.
; Return:     ERROR_BADPROTOCOL  - The buffer content isnt following our protocol.
;             ERROR_USERQUIT     - The user sent a nice QUIT message using our protocol.
;             Positive INT32     - This many bytes were cleanly processed and should be removed
;                                  from the IOJob buffers.

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
  MemAlloc eax                                          ;Allocate memory for the assembled transmition
  mov pMemory, xax
  mov pBuffer, xax

  lea xdi, [xsi].RcvIOChain                             ;Sentinel
  mov xbx, [xdi].SDLL_SENTINEL.pFirstItem               ;xbx -> first item
  .while xbx != xdi && dConsumed != 0
    mov eax, [xbx - IO_HEADER_SIZE].IO_SOCKJOB.dBytesConsumed
    .if eax <= dConsumed
      sub dConsumed, eax
      lea xdx, [xbx - IO_HEADER_SIZE]                   ;xdx -> IOSockJob
      mov xbx, [xbx].SDLL_ITEM.pNextItem                ;Move to next IOSockJob
      mov xcx, pMemory
      add pMemory, xax
      invoke MemClone, xcx, [xdx].IO_SOCKJOB.WSABuf.buf, eax
      .break .if dConsumed == 0
    .else
      lea xdx, [xbx - IO_HEADER_SIZE]                   ;xdx -> IOSockJob
      invoke MemClone, pMemory, [xdx].IO_SOCKJOB.WSABuf.buf, dConsumed
      .break
    .endif
  .endw

  ;Build the Bitmap and display it on DebugCenter
  ;CreateCompatibleBitmap => SetDIBits
  mov hScreenDC, $invoke(GetDC, 0)                      ;Get the DC of desktop
  mov hMemDC, $invoke(CreateCompatibleDC, hScreenDC)    ;Create a DC compatible with hScreenDC
  mov xbx, pBuffer
  add xbx, sizeof(DWORD)                                ;Skip TX length
  m2m dSizeX, [xbx].BITMAPINFO.bmiHeader.biWidth, eax
  m2m dSizeY, [xbx].BITMAPINFO.bmiHeader.biHeight, ecx
  mov hNewBmp, $invoke(CreateCompatibleBitmap, hScreenDC, dSizeX, dSizeY) ;Create a compatible bmp
  mov hPrvBmp, $invoke(SelectObject, hMemDC, hNewBmp)
  lea xax, [xbx + sizeof(BITMAPINFO)]
  invoke SetDIBits, hMemDC, hNewBmp, 0, [xbx].BITMAPINFO.bmiHeader.biHeight, \
                    xax, xbx, DIB_RGB_COLORS
  invoke SelectObject, hMemDC, hPrvBmp                  ;Return back the previous Bitmap
  invoke DeleteDC, hMemDC
  invoke ReleaseDC, 0, hScreenDC
  invoke StrECopyW, addr wCaptionDC, $OfsCStrW("Desktop image from connection ")
  invoke xword2hexW, xax, pConnection
  invoke DbgOutBitmap, hNewBmp, $RGB(0,0,0), addr wCaptionDC
  invoke DeleteObject, hNewBmp

  MemFree pBuffer                                       ;Dispose assembled payload

  mov xbx, [xsi].pProtocolData
  mov [xbx].SRVPROTDATA.dMemSize, 0
  mov [xbx].SRVPROTDATA.dTotRcvBytes, 0
  mov [xbx].SRVPROTDATA.pLastIOJob, NULL
  mov eax, dRetval

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