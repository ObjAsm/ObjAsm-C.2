; ==================================================================================================
; Title:      GetNetworkTime.asm
; Author:     G. Friedrich
; Version:    1.0.0
; Purpose:    ObjAsm GetNetworkTime Application.
; Link:       https://en.wikipedia.org/wiki/Network_Time_Protocol
; Notes:      Version 1.0.0, January 2021
;               - First release.
; ==================================================================================================


WIN32_LEAN_AND_MEAN         equ 1                       ;Necessary to exlude WinSock.inc
INCL_WINSOCK_API_PROTOTYPES equ 1

% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, NUI32, ANSI_STRING, DEBUG(LOG, "GetNetworkTime")  ;Load OOP files and OS related objects

% include &IncPath&Windows\WinSock2.inc
% include &IncPath&Windows\ws2ipdef.inc
% include &IncPath&Windows\ws2tcpip.inc

% includelib &LibPath&Windows\Ws2_32.lib
% includelib &LibPath&Windows\Mswsock.lib
% includelib &LibPath&Windows\Kernel32.lib
% includelib &LibPath&Windows\Shell32.lib
% includelib &LibPath&Windows\Shlwapi.lib

;https://labs.apnic.net/?p=462

NTPts struc
  secs      DWORD   ?
  secdiv    DWORD   ?
NTPts ends

NTPMSG struc
  LiVnMode  BYTE    ?                                   ;LLVVVMMM = Leap Indicator, Version, Mode
  Stratum   BYTE    ?
  Poll      BYTE    ?
  Prec      BYTE    ?
  RtDel     DWORD   ?
  RtDisp    DWORD   ?
  RefId     DWORD   ?
  Ref       NTPts   <>
  Originate NTPts   <>
  Receive   NTPts   <>                                  ;Server NTP time when received
  Transmit  NTPts   <>                                  ;Server NTP time when transmitted
NTPMSG ends

.data?
  NetTime   SYSTEMTIME  <>

.const
  qNs1900   QWORD 014F373BFDE04000h                     ;SystemTimeToFileTime(01.01.1900 UTC)
  dTimeout  DWORD 1000                                   ;Max 500ms to receive response

CStr cFormat, "%02d.%02d.%04d %02d:%02d:%02d.%03d"

.code
GetNetworkTime proc pTimeServerName:PSTRING, pNetTime:PSYSTEMTIME
  local wsd:WSADATA, hSocket:HANDLE
  local ServerAddr:SOCKADDR_STORAGE, Hints:ADDRINFOT, pResult:PADDRINFOT
  local NtpMsg:NTPMSG, FileTimeNow:FILETIME
  local dT0:DWORD, dT3:DWORD, qNtpTransmit:QUADWORD, qNtpReceive:QUADWORD

  cmp pNetTime, NULL
  je ErrorParam

  invoke WSAStartup, 202h, addr wsd                     ;Version 2.2

  ;No leap second adjustment (2 bits), Version 1 (current ver. is 4) (3 bits), Client mode (3 bits)
  mov NtpMsg.LiVnMode, 00100011y
  invoke MemZero, addr NtpMsg.Stratum, sizeof NtpMsg - sizeof NtpMsg.LiVnMode

  mov Hints.ai_flags, 0
  mov Hints.ai_family, AF_INET
  mov Hints.ai_socktype, SOCK_DGRAM
  mov Hints.ai_protocol, IPPROTO_UDP
  mov Hints.ai_addrlen, 0
  mov Hints.ai_canonname, NULL
  mov Hints.ai_addr, NULL
  mov Hints.ai_next, NULL
  invoke GetAddrInfo, pTimeServerName, $OfsCStr("ntp"), addr Hints, addr pResult
  or eax, eax
  jnz ErrorWSA
  mov xax, pResult
  lea xcx, ServerAddr
  invoke MemClone, xcx, [xax].ADDRINFOT.ai_addr, DWORD ptr [xax].ADDRINFOT.ai_addrlen
  invoke FreeAddrInfo, pResult

  invoke socket, AF_INET, SOCK_DGRAM, IPPROTO_UDP
  cmp eax, INVALID_SOCKET
  je ErrorWSA
  mov hSocket, xax
  invoke setsockopt, hSocket, SOL_SOCKET, SO_RCVTIMEO, addr dTimeout, sizeof dTimeout
  cmp eax, SOCKET_ERROR
  je ErrorWSA
  invoke connect, hSocket, addr ServerAddr, sizeof ServerAddr
  cmp eax, SOCKET_ERROR
  je ErrorWSA
  invoke GetTickCount
  mov dT0, eax
  invoke send, hSocket, addr NtpMsg, sizeof NtpMsg, 0   ;Returns number bytes sent or SOCKET_ERROR
  cmp eax, SOCKET_ERROR
  je ErrorWSA
  invoke recv, hSocket, addr NtpMsg, sizeof NtpMsg, MSG_PEEK
  cmp eax, SOCKET_ERROR
  je ErrorWSA
  cmp eax, sizeof NtpMsg
  jne ErrorWSA
  invoke GetTickCount
  mov dT3, eax
  invoke closesocket, hSocket
  invoke WSACleanup

  cmp NtpMsg.Transmit.secs, 0
  je ErrorNoData

  mov eax, NtpMsg.Receive.secs
  mov ecx, NtpMsg.Receive.secdiv
  bswap eax                                             ;Convert to little endian
  bswap ecx                                             ;Convert to little endian
  mov qNtpReceive.HiDWord, eax
  mov qNtpReceive.LoDWord, ecx

  mov eax, NtpMsg.Transmit.secs                         ;Integer part
  mov ecx, NtpMsg.Transmit.secdiv                       ;Fractional part
  bswap eax                                             ;Convert to little endian
  bswap ecx                                             ;Convert to little endian
  mov qNtpTransmit.HiDWord, eax
  mov qNtpTransmit.LoDWord, ecx

  mov edx, dT3
  sub edx, dT0
  DbgWriteF ,, "Delay = ¦UD ms", edx
  xor eax, eax
  mov ecx, 1000
  div ecx                                               ;eax = T3-T0 in ntp fractional units

  mov edx, qNtpTransmit.LoDWord
  sub edx, qNtpReceive.LoDWord
  sub eax, edx
  shr eax, 1                                            ;Assume symmetry between send and receive

  xor ecx, ecx
  add qNtpTransmit.LoDWord, eax                         ;Save fractional part
  adc ecx, qNtpTransmit.HiDWord

  mov eax, 10000000                                     ;Scale to 100ns intervals
  mul ecx                                               ;edx::eax
  add eax, DWORD ptr [qNs1900 + 0]                      ;Add 100ns intervals from 1601 to 1900
  adc edx, DWORD ptr [qNs1900 + sizeof DWORD]
  mov DWORD ptr [FileTimeNow + 0], eax                  ;Store the result for FileTimeToSystemTime
  mov DWORD ptr [FileTimeNow + sizeof DWORD], edx

  invoke FileTimeToSystemTime, addr FileTimeNow, pNetTime

  mov eax, qNtpTransmit.LoDWord
  mov ecx, 1000
  mul ecx                                               ;
  mov xcx, pNetTime
  mov [xcx].SYSTEMTIME.wMilliseconds, dx

  xor eax, eax                                          ;eax = 0 => no error
  ret

ErrorWSA:
  invoke WSAGetLastError
  jmp ErrorExit
ErrorParam:
  mov eax, WSA_INVALID_PARAMETER
  jmp ErrorExit
ErrorNoData:
  mov eax, WSANO_DATA
ErrorExit:
  DbgWriteF ,, "WSA Error ¦UD", eax
  ret
GetNetworkTime endp

GetTimeInfo macro ServerName
  DbgWarning ServerName
  repeat 5
    invoke GetNetworkTime, $OfsCStr(ServerName), addr NetTime
    .if eax == 0
      invoke wsprintf, addr ServerTime, addr cFormat, NetTime.wDay, NetTime.wMonth, NetTime.wYear, \
                       NetTime.wHour, NetTime.wMinute, NetTime.wSecond, NetTime.wMilliseconds
      DbgStr ServerTime
    .endif
  endm
  DbgLine
endm

.code
start proc
  local ServerTime[100]:CHR

  SysInit
  DbgClearAll
  BitClr dDbgOpt, DBG_OPT_SHOWINFO

  GetTimeInfo "ntp01.vzug.com"
  GetTimeInfo "pool.ntp.org"
  GetTimeInfo "time.nist.gov"
  GetTimeInfo "time-c.nist.gov"
  GetTimeInfo "tick.usno.navy.mil"
  GetTimeInfo "ut1-wwv.nist.gov"
  GetTimeInfo "ntp0.cornell.edu"
  GetTimeInfo "time.google.com"
  GetTimeInfo "time.windows.com"
  GetTimeInfo "time.euro.apple.com"
  
  invoke MessageBox, 0, $OfsCStr("NTP-Server requests ready.", CRLF, "Check the GetNetworkTime.dbg file to see the results."), $OfsCStr("Information"), MB_OK or MB_ICONINFORMATION   
  SysDone

  invoke ExitProcess, 0
start endp

end
