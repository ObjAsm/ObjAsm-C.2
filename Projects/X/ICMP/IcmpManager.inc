; ==================================================================================================
; Title:      IcmpManager.inc
; Author:     G. Friedrich
; Version:    C.2.0
; Purpose:    ObjAsm support of IcmpManager objects.
; Notes:      Version C.2.0, December 2022
;               - First release.
;               - Alternative implementation to IcmpSendEcho API (icmpapi.h).
; Links:      https://learn.microsoft.com/en-us/windows/win32/winsock/tcp-ip-raw-sockets-2
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     IcmpManager
; Purpose:    Implement "Ping" and "Trace" OS commands using the IcmpSendEcho API.

Object IcmpManager, 0, Primer
  VirtualMethod     Ping
  VirtualMethod     SetDstFromIPv4, PSTRINGA
  VirtualMethod     SetDstFromURL,  PSTRINGA
  VirtualMethod     Trace

  DefineVariable    DstAddr,        SOCKADDR_IN,  {AF_INET}
  DefineVariable    dTimeout,       DWORD,        1000          ;IcmpSendEcho Timeout (ms)
ObjectEnd


; ——————————————————————————————————————————————————————————————————————————————————————————————————

if IMPLEMENT

IPv4Header struc                  ;Internet Protocol Header (size = 20)
  byVerLen      BYTE  ?           ;Version (4) and Header Length (5 => 20 BYTEs)
  byTos         BYTE  ?
  nTotalLength  WORD  ?           ;Total packet length (IPv4Header + ICMPv4Header + Payload)
  nId           WORD  ?
  nOffset       WORD  ?
  byTtl         BYTE  ?           ;“TTL”, or “time to live” (default ~ 128)
  byProtocol    BYTE  ?           ;1 = ICMP
  nChecksum     WORD  ?
  nSrcAddr      DWORD ?
  nDestAddr     DWORD ?
IPv4Header ends

ICMPv4Header struc                ;Internet Control Message Protocol (size = 8)
  byType        BYTE  ?
  byCode        BYTE  ?
  nChecksum     WORD  ?
  nId           WORD  ?           ;Unique ID on this system (e.g.: the application's process ID)
  nSequence     WORD  ?
ICMPv4Header ends

DEFAULT_MTU       equ   1500      ;Maximum Transmission Unit
SEND_PAYLOAD_SIZE equ   32        ;The message size that the ICMP echo request should carry with it
RECV_PAYLOAD_SIZE equ   DEFAULT_MTU - sizeof(IPv4Header) - sizeof(ICMPv4Header)

IcmpReplayBuffer struct
            ICMP_ECHO_REPLY   {}
  Payload   BYTE              RECV_PAYLOAD_SIZE dup(?)
IcmpReplayBuffer ends

HopInfo struc
  dRoundTripTime    DWORD     3 dup(?)
  pHostName         PSTRINGA  ?
HopInfo ends

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      CheckSockError
; Purpose:    Helper macro to display an WSA error.
; Arguments:  Arg1: Text to display

DbgSockError macro WarningText:req, InfoText, Dest
  local MsgBuffer

  $$Buffersize = 1024
  .data?
    MsgBuffer CHR $$Buffersize dup(?)
  .code
  if DEBUGGING
    DbgSaveContext
    DbgSetDestWnd Dest
    invoke DbgOutText, $OfsCStr($Esc(<WarningText>)), DbgColorWarning, DbgColorBackground, \
                        DBG_EFFECT_NORMAL, ??DbgDstWnd
    invoke WSAGetLastError
    mov esi, eax
    mov xdi, offset MsgBuffer                           ;;Get a POINTER to the output buffer
    WriteF xdi, " - WSA error code: ¦UD = ", esi
    invoke StrEnd, xdi
    mov xdx, xax
    add xax, $$Buffersize
    sub xax, xdi
    invoke NetErr2Str, esi, xdx, eax                    ;;Get the error message
    invoke DbgOutText, xdi, DbgColorWarning, DbgColorBackground, DBG_EFFECT_NORMAL, ??DbgDstWnd
    DbgShowTxtInfo InfoText, ??DbgDstWnd
    DbgShowSrcInfo ??DbgDstWnd
    DbgLoadContext
  endif
endm

CheckSockError macro WarningText:req, InfoText, Dest
  if DEBUGGING
    .if eax == SOCKET_ERROR
      DbgSockError WarningText, InfoText, Dest
    .endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $NetworkAddressIPv4
; Purpose:    Convert a string to an IPv4 network address (network byte order = big endian).
; Arguments:  Arg1: String (aaa.bbb.ccc.ddd).

$NetworkAddressIPv4 macro Address:req
  $$Addr = 0
  $$Pos1 = 1
  $$Multiplier = 1
  repeat 3
    $$Pos2 InStr $$Pos1, <Address>, <.>
    $$Addr = $$Addr + $$Multiplier * @SubStr(<&Address>, $$Pos1, $$Pos2 - $$Pos1)
    $$Pos1 = $$Pos2 + 1
    $$Multiplier = 256*$$Multiplier
  endm
  $$Addr = $$Addr + $$Multiplier*@SubStr(<&Address>, $$Pos1)
  %exitm <$$Addr>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
;Checksum for ICMP is calculated in the same way as for
;IP header
;This code was taken from: http://www.netfor2.com/ipsum.htm

CalcChecksum proc uses xbx pBuffer:POINTER, dLen:DWORD
  ;Make WORDs out of every two adjacent BYTEs in the packet and add them up
  ?mov xcx, pBuffer
  ?mov edx, dLen
  xor eax, eax
  test edx, edx
  .while !ZERO?
    movzx ebx, WORD ptr [xcx]
    xchg bl, bh
    add xcx, sizeof(WORD)
    add eax, ebx
    sub edx, sizeof(WORD)                               ;Buffersize is always multiple of 2
  .endw

  ;Take only 16 bits out of the 32 bit sum and add up the carries
  .repeat
    mov ecx, eax
    shr ecx, 16
    .break .if ZERO?
    and eax, 0FFFFh
    add eax, ecx
  .until FALSE

  ;One's complement the result
  not eax
  xchg al, ah                                           ;Convert to network byte order (BE)
  and eax, 0FFFFh
  ret
CalcChecksum endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IcmpManager.Ping
; Purpose:    Send a Ping.
; Arguments:  None.
; Return:     eax = RoundTripTime in ms or -1 if a timeout occurs.

Method IcmpManager.Ping, uses xsi
  local hIcmp:HANDLE, Options:IP_OPTION_INFORMATION
  local SendBuffer[SEND_PAYLOAD_SIZE]:BYTE, RecvBuffer:IcmpReplayBuffer

  DbgLine
  SetObject xsi
  mov hIcmp, $invoke(IcmpCreateFile)
  FillStringA SendBuffer, <abcdefghijklmnopqrstuvwabcdefghi> ;Fill payload
  mov Options.Ttl, 128                                  ;OS ping default value is 128
  mov Options.Tos, 0
  mov Options.Flags, 0
  mov Options.OptionsSize, 0
  mov Options.OptionsData, NULL
  invoke IcmpSendEcho, hIcmp, [xsi].DstAddr.sin_addr.S_un.S_addr, \
                       addr SendBuffer, sizeof(SendBuffer), \
                       addr Options, addr RecvBuffer, sizeof(RecvBuffer), [xsi].dTimeout
  .if RecvBuffer.Status != IP_SUCCESS
    mov RecvBuffer.RoundTripTime, 0
    DbgWarning "Ping error or timeout!"
  .else
    DbgWriteF ,, "Ping roundtrip = ¦UD ms.", RecvBuffer.RoundTripTime
  .endif
  invoke IcmpCloseHandle, hIcmp
  mov eax, RecvBuffer.RoundTripTime
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IcmpManager.Trace
; Purpose:    Trace possible routes (paths) and measuring transit delays of packets across an
;             Internet Protocol (IP) network.
; Arguments:  Arg1: -> URL string.
; Return:     eax = 1 if succeeded, otherwise 0.
; Links:      https://en.wikipedia.org/wiki/Traceroute

Method IcmpManager.Trace, uses xbx xdi xsi
  local hIcmp:HANDLE, HI:HopInfo, Options:IP_OPTION_INFORMATION
  local SendBuffer[SEND_PAYLOAD_SIZE]:BYTE, RecvBuffer:IcmpReplayBuffer

  DbgLine
  SetObject xsi
  mov hIcmp, $invoke(IcmpCreateFile)
  FillStringA SendBuffer, <abcdefghijklmnopqrstuvwabcdefghi> ;Fill payload
  mov HI.HopInfo.pHostName, NULL
  mov Options.Ttl, 1
  mov Options.Tos, 0
  mov Options.Flags, 0
  mov Options.OptionsSize, 0
  mov Options.OptionsData, NULL

  .repeat
    xor ebx, ebx
    mov HI.pHostName, NULL
    .while ebx < 3                                        ;3 attempts
      invoke IcmpSendEcho, hIcmp, [xsi].DstAddr.sin_addr.S_un.S_addr, \
                           addr SendBuffer, sizeof(SendBuffer), \
                           addr Options, addr RecvBuffer, sizeof(RecvBuffer), [xsi].dTimeout
      .if RecvBuffer.Status == IP_TTL_EXPIRED_TRANSIT || RecvBuffer.Status == IP_SUCCESS
        .if HI.pHostName == NULL                        ;Check if we just have a string
          invoke gethostbyaddr, addr RecvBuffer.Address, 4, AF_INET
          .if xax != NULL
            mov HI.HopInfo.pHostName, $invoke(StrNewA, [xax].hostent.h_name)
          .endif
        .endif
        mov eax, RecvBuffer.RoundTripTime
      .else
        mov eax, -1
      .endif
      mov HI.dRoundTripTime[xbx*sizeof(DWORD)], eax
      inc ebx
    .endw
    .if HI.pHostName == NULL
      mov HI.pHostName, $invoke(StrNew, $OfsCStrA("No response"))
    .endif
    lea xdi, RecvBuffer.Address
    DbgWriteF ,, "Hop ¦UD: ¦SD/¦SD/¦SD ms ¦AT¦V4 ¦AT¦SA", Options.Ttl, \
              HI.dRoundTripTime[0], HI.dRoundTripTime[4], HI.dRoundTripTime[8], \
              22, xdi, 40, HI.HopInfo.pHostName

;    DbgWriteF ,, "Hop ¦UD: ¦SD/¦SD/¦SD ms ¦AT¦V6 ¦AT¦SA", Options.Ttl, \
;              HI.dRoundTripTime[0], HI.dRoundTripTime[4], HI.dRoundTripTime[8], \
;              22, xdi, 64, HI.HopInfo.pHostName

    invoke StrDispose, HI.pHostName
    inc Options.Ttl                                     ;Add one Hop more
  .until RecvBuffer.Status == IP_SUCCESS                ;Exit if last IcmpSendEcho was successful

  invoke IcmpCloseHandle, hIcmp
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IcmpManager.SetDstFromIPv4
; Purpose:    Set the destination address from an IPv4 string.
; Arguments:  Arg1: -> String in the format xxx.xxx.xxx.xxx
; Return:     eax = 1 if succeeded, otherwise 0.

Method IcmpManager.SetDstFromIPv4, uses xsi, pIpStr:PSTRINGA
  SetObject xsi
  invoke inet_addr, pIpStr
  .if eax != INADDR_NONE
    mov [xsi].DstAddr.sin_addr.S_un.S_addr, eax
    mov eax, 1
  .else
    xor eax, eax
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IcmpManager.SetDstFromURL
; Purpose:    Set the destination address from an URL string.
; Arguments:  Arg1: -> URL ANSI string (e.g. www.google.com).
; Return:     eax = 1 if succeeded, otherwise 0.

Method IcmpManager.SetDstFromURL, uses xsi, pUrlStr:PSTRINGA
  SetObject xsi
  SetObject xsi
  invoke gethostbyname, pUrlStr                         ;xax -> hostent
  .if xax != NULL
    mov xdx, [xax].hostent.h_addr_list                  ;xdx -> first IP address POINTER
    mov xax, [xdx]                                      ;xax -> first IP address
    mov ecx, [xax]
    mov [xsi].DstAddr.sin_addr.S_un.S_addr, ecx
    mov eax, 1
  .else
    xor eax, eax
  .endif
MethodEnd

endif
