; ==================================================================================================
; Title:      NetCom.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm object cluster. Support of NetCom objects.
; Links:      - http://www.codeproject.com/KB/IP/jbsocketserver3.aspx
;             - http://msdn.microsoft.com/en-us/library/ms741394(VS.85).aspx
;             - http://msdn.microsoft.com/en-us/library/aa938522.aspx
;             - http://msdn.microsoft.com/en-us/library/aa364510(VS.85).aspx - HTTP API reference
;             - http://msdn.microsoft.com/en-us/library/ms740673(VS.85).aspx   Socks2
;             - http://msdn.microsoft.com/en-us/library/ms738547.aspx          Graceful shutdown
;             - http://msdn.microsoft.com/en-us/library/ms740668(VS.85).aspx   WSA Error codes
;             - http://www.chebucto.ns.ca/~rakerman/port-table.html            Port table
;             - http://www.iana.org/assignments/port-numbers                   IANA official port nbrs
;             - http://support.microsoft.com/kb/196271/EN-US/                  Port number restriction
;             - http://www.microsoft.com/technet/itsolutions/network/deploy/depovg/tcpip2k.asp Implem.
;             - http://rdweb.cns.vt.edu/public/notes/win2k-tcpip.htm           Registry settings
;             - http://msdn.microsoft.com/de-ch/magazine/cc302334(en-us).aspx
;             - http://support.microsoft.com/kb/192800/en                      Important reading IOCP
;             - http://support.microsoft.com/kb/181611/en                      SO_SNDBUF = 0
;             - http://msdn.microsoft.com/en-us/library/ms810434.aspx          IOCP internal descrip.
;             - https://support.microsoft.com/en-nz/help/929851/the-default-dynamic-port-range-for-
;                       tcp-ip-has-changed-in-windows-vista
;
; Notes:      include the following objects in the main asm file using
;               LoadObjects StopWatch
;               LoadObjects NetComAddrCollection
;             and all necessary ancestors not previously included.
;
;             Our typical TCP streaming connections use the 'session global' copy of the
;             RemoteHostAddr field, stored in NetComConnection. The newly-supported SOCK_SEQPACKET
;             will also use that. But the SOCK_DGRAM, SOCK_RDM and SOCK_RAW will use the
;             'session local' copy of the RemoteHostAddr field, stored in IOSockJob.
;             This is because these socket types typically communicate with multiple remote hosts,
;             so we are tagging messages with host ids. This allows us to associate a message with
;             an individual remote host.
;
;             Configure your firewalls according to the "dynamic client port range" (49152 - 65535).
;
;             ServiceNames: look at %WINDIR%\system32\drivers\etc\services
;
;             Version C.1.0, October 2017
;               - First release.
; ==================================================================================================



;                                   Object relationship
;                                   -------------------
;
;
;                         -------------------
;          ------------->|    Application    |<----------
;         |              |-------------------|           |
;         |              |                   |           |
;         |              |                   |           |
;         |              |                   |           |
;         |               -------------------            |
;         |                                              |
;         |                                              |
;         |          Server/Client                       |        Functionality
;         |       -------------------                    |      -------------------
;         |   -->|   NetComEngine    |<----              |     |  NetComProtocol   |
;         |  |   |-------------------|     |             |     |-------------------|
;          --|---| pOwner            |     |              -----| pOwner            |
;            |   |                   |     |                   |                   |
;            |   |                   |     |                   |                   |
;            |    -------------------      |                    -------------------
;            |                             |
;            |                              ---------------
;            |                                             |
;            |           --------------------              |    -------------------
;            |       -->|NetComConnectionPool|        -------->|NetComIOSockJobPool|- - -
;            |      |   |--------------------|       |     |   |-------------------|     |
;             ------|---| pOwner             |       |      ---| pOwner            |
;                   |   |     pIOSockJobPool |-------          | dBufferSize       |     |
;                   |   |                    |                 |                   |
;                   |    --------------------                   -------------------      |
;                   |
;                   |                                                                    |
;                   |
;                   |           -------------------            -------------------       |
;                   |          | NetComConnection  |< - - - - |  NetComIOSockJob  |< - -
;                   |          |-------------------||         |-------------------||
;                    ----------| pOwner            |||        |                   |||
;                              |                   |||        |                   ||||
;                              |                   |||        |                   |||||
;                               ------------------- ||         ------------------- |||||
;                                ------------------- |          ------------------- ||||
;                                 -------------------            ------------------- |||
;                                                                 --------------------||
;                                                                  ------------------- |
;                                                                   -------------------
;
;
; ==================================================================================================


SO_CONNECT_TIME             equ   0700Ch

;SO_EXCLUSIVEADDRUSE

;IO socket operations
OPERATION_SOCK_ACCEPT       equ   1h
OPERATION_SOCK_WRITE        equ   2h
OPERATION_SOCK_READ         equ   3h
OPERATION_SOCK_CONNECT      equ   4h

;IO Flag
IOF_JOB_COMPLETED           equ   BIT00     ;Pending or completed
IOF_JOB_ENGAGED             equ   BIT01     ;Engaged (read chain)

ERROR_BAD_PROTOCOL          equ   -10
ERROR_USER_QUIT             equ   -12

;Protocol commands
PROT_CMD_ACCEPT_CONNECTION  equ   1
PROT_CMD_REJECT_CONNECTION  equ   2
PROT_CMD_DISCONNECT         equ   3         ;Connection teardown
PROT_CMD_CLOSE              equ   4         ;Connection cut
PROT_CMD_CONTINUE           equ   5         ;Continue actual operation
PROT_CMD_DELETE_IOJOBS      equ   6
PROT_CMD_FREE               equ   7         ;Free connection object

;NetCom Connection states
NCC_DISCONNECTED_LOCAL      equ   BIT00     ;Disconnected by local host
NCC_DISCONNECTED_REMOTE     equ   BIT01     ;Disconnected by remote host
NCC_CLOSE_MARKED            equ   BIT02     ;Marked to close
NCC_CLOSED                  equ   BIT03     ;Closed
NCC_FREE_MARKED             equ   BIT04     ;Marked to free
NCC_FREED                   equ   BIT05     ;Freed

NCC_DISCONNECTED            equ   NCC_DISCONNECTED_LOCAL or NCC_DISCONNECTED_REMOTE

;NetCom Error states
NCE_ACCEPT                  equ   BIT27     ;Error happend while accepting
NCE_CONNECT                 equ   BIT28     ;Error happend while connecting
NCE_WRITE                   equ   BIT29     ;Error happend while writing
NCE_READ                    equ   BIT30     ;Error happend while reading
NCE_UNKNOWN                 equ   BIT31     ;Error happend during an unknown operation


;Shutdown stages
SDN_CLOSE_CONNECTIONS       equ   1
SDN_CLOSE_WORKERS           equ   2
SDN_QUIT_WORKERS            equ   3         ;Abortive close
SDN_HOUSEKEEPING            equ   4

;Error codes
ERROR_BASE = 111111110
AddErrMsg NCE_WINSOCK_INIT_FAILED,          "NetComEngine failed initializing WinSock library"
AddErrMsg NCE_IOCP_INIT_ERROR,              "NetComEngine failed to create an IOCP"
AddErrMsg NCE_THREAD_CREATION_FAILED,       "NetComEngine failed creating a thread"
AddErrMsg NCE_SOCKET_CREATION_FAILED,       "NetComEngine failed to create a socket"
AddErrMsg NCE_LISTENER_BIND_ERROR,          "NetComEngine failed to bind listener socket"
AddErrMsg NCE_LISTENER_DOESNT_LISTEN,       "Listening socked failed to listen"
AddErrMsg NCE_LISTENER_IOCP_BIND_FAILED,    "Failed to bind the listener socket to the IOCP"

AddErrMsg NCCP_OUT_OF_MEMORY,               "Out of memory in NetComConnectionPool"
AddErrMsg NCJP_OUT_OF_MEMORY,               "Out of memory in NetComIOSockJobPool"

AddErrMsg NCCN_OUT_OF_MEMORY,               "Out of memory in NetComConnection"
AddErrMsg NCCN_DISCONNECTED,                "NetComConnection disconnected"

AddErrMsg NCSP_OUT_OF_MEMORY,               "Out of memory in NetComSvrProtocol"

;WSA GUIDs
WSAID_CONNECTEX            GUID {025A207B9h,0DDF3h,04660h,{08Eh,0E9h,076h,0E5h,08Ch,074h,006h,03Eh}}
;WSAID_ACCEPTEX             GUID {0B5367DF1h,0CBACh,011CFh,{095h,0CAh,000h,080h,05Fh,048h,0A1h,092h}}
;WSAID_DISCONNECTEX         GUID {07FDA2E11h,08630h,0436Fh,{0A0h,031h,0F5h,036h,0A6h,0EEh,0C1h,057h}}
;WSAID_GETACCEPTEXSOCKADDRS GUID {0B5367DF2h,0CBACh,011CFh,{095h,0CAh,000h,080h,05Fh,048h,0A1h,092h}}
;WSAID_TRANSMITFILE         GUID {0B5367DF0h,0CBACh,011CFh,{095h,0CAh,000h,080h,05Fh,048h,0A1h,092h}}
;WSAID_TRANSMITPACKETS      GUID {0D9689DA0h,01F90h,011D3h,{099h,071h,000h,0C0h,04Fh,068h,0C8h,076h}}
;WSAID_WSARECVMSG           GUID {0F689D7C8h,06F1Fh,0436Bh,{08Ah,053h,0E5h,04Fh,0E3h,051h,0C3h,022h}}

SIO_GET_EXTENSION_FUNCTION_POINTER  equ IOC_INOUT or IOC_WS2 or 6

SO_UPDATE_ACCEPT_CONTEXT      equ   700Bh
SO_UPDATE_CONNECT_CONTEXT     equ   7010h

NETCOMADDR struc                                        ;Needed for NetComAddrCollection
  union
    SOCKADDR                  {}                        ;IPv4
    SOCKADDR_IN               {}                        ;IPv4 only
    SOCKADDR_IN6              {}                        ;IPv6 only
    SOCKADDR_STORAGE          {}                        ;IPv4, IPv6, NetBIOS, infrared or Bluetooth
  ends
NETCOMADDR ends
PNETCOMADDR typedef ptr NETCOMADDR

LISTENER struc 4
  hSocket         HANDLE      ?
LISTENER ends
PLISTENER typedef ptr LISTENER

;This structure is not integrated into IO_SOCKJOB to be able to calculate some offsets
IO_HEADER struc 2
  Ovl             OVERLAPPED  {}                        ;Must be the first structure member!
  wOperation      WORD        ?                         ;Operation ID, i.e. OPERATION_SOCK_READ
  wFlags          WORD        ?                         ;Flags, i.e. IOF_JOB_ENGAGED
  dBytesConsumed  DWORD       ?                         ;#bytes currently in buffer
IO_HEADER ends
IO_HEADER_SIZE equ sizeof(IO_HEADER)

IO_SOCKJOB struc 4
                  IO_HEADER   {}
                  SDLL_ITEM   {}                        ;Linked list to hold buffers together
  WSABuf          WSABUF      {}
  DataBuffer      BYTE        0 dup(?)                  ;The data buffer is placed here
IO_SOCKJOB ends                                         ;  Minimal size of the buffer must
PIO_SOCKJOB typedef ptr IO_SOCKJOB                      ;  be sizeof ACCEPT_DATA

ACCEPT_DATA struct 4
  LocalHostAddr   BYTE        (sizeof(NETCOMADDR) + 16) dup(?)   ;16 BYTEs added, see AcceptEx
  RemoteHostAddr  BYTE        (sizeof(NETCOMADDR) + 16) dup(?)   ;  documentation
  pListener       PLISTENER   ?
  pConnection     POINTER     ?
ACCEPT_DATA ends

NETCOMADDR_ENTRY struc
              NETCOMADDR      {}
;  wCounter    WORD            ?
;  wFlags      WORD            ?                         ;Reserved for internal use
NETCOMADDR_ENTRY ends
PNETCOMADDR_ENTRY typedef ptr NETCOMADDR_ENTRY

WSACF_DONT_REMOVE             equ   BIT00


;Maximum Transmission Unit (MTU) of network hardware in BYTEs
MTU_ETHERNET                  equ   1500
MTU_ETHERNET_JUMBO            equ   9000
MTU_WIFI_80211                equ   2312
MTU_ISDN                      equ   576
MTU_X25                       equ   576
MTU_HYPERCHANNEL              equ   65535

;Maximum Segment Size (MSS) in BYTEs => Application Payload.
;This value can be further reduced if some socket options are enabled.
;Depending on the physical route of the connection, the effective segment size may even be lower.
MSS_ETHERNET_IPV4             equ   MTU_ETHERNET - 40   ;20 Bytes TCP-Header + 20 Bytes IP-Header
MSS_ETHERNET_IPV6             equ   MTU_ETHERNET - 60   ;40 Bytes TCP-Header + 20 Bytes IP-Header

if INTERNET_PROTOCOL_VERSION eq 4
  MSS_ETHERNET_IPVX   equ   MSS_ETHERNET_IPV4
else
  MSS_ETHERNET_IPVX   equ   MSS_ETHERNET_IPV6
endif


COMPLETION_KEY_LISTENER       equ   -1


AcceptEx proto WIN_STD_CALL_CONV :SOCKET,:SOCKET,:PVOID,:DWORD,:DWORD,:DWORD,:LPDWORD,:LPOVERLAPPED


if TARGET_STR_TYPE eq STR_TYPE_ANSI
  GetHostName equ gethostname
else
  GetHostName equ GetHostNameW
endif


; --------------------------------------------------------------------------------------------------
; Object:  NetComIOSockJobPool
; Purpose: Implement a DataPool of IOJobs. An IOSockJob is a memory chunk with a header structure
;          called IO_SOCKJOB followed by a data buffer.

Object NetComIOSockJobPool, NetComIOSockJobPoolID, DataPool
  RedefineMethod  Init,               POINTER, DWORD, DWORD

  RedefineMethod  NewItem,            WORD
  RedefineMethod  FreeItem,           PIO_SOCKJOB
  VirtualMethod   ResetIOJob,         PIO_SOCKJOB, WORD

  DefineVariable  dBufferSize,        DWORD,            0
  DefineVariable  dCount,             DWORD,            0     ;Control value, can be omited
ObjectEnd

; --------------------------------------------------------------------------------------------------
; Object:  NetComConnection
; Purpose: Implement a NetCom connection.

TYPE_Connectex typedef proto :HANDLE, :POINTER, :DWORD, :POINTER, :DWORD, :POINTER, :LPOVERLAPPED
PTO_CONNECTEX typedef ptr TYPE_Connectex

Object NetComConnection, NetComConnectionID, Primer
  VirtualMethod   Disconnect,         DWORD
  RedefineMethod  Done
  RedefineMethod  Init,               POINTER, POINTER
  VirtualMethod   FreeIOJobs

  ;Methods to place supervisor jobs
  VirtualMethod   QueueClose
  VirtualMethod   QueueFree

  ;Methods to place IO socket jobs or messages on the IOCP queue
  VirtualMethod   QueueAccept,        PLISTENER, POINTER      ;-> Listener, -> NetComProtocol
  VirtualMethod   QueueConnect,       PNETCOMADDR             ;-> HostAddr
  VirtualMethod   QueueRead
  VirtualMethod   QueueWrite,         POINTER, DWORD          ;-> Data, Size

  ;Methods to marshal completion notifications
  VirtualMethod   OnAccept,           PIO_SOCKJOB
  VirtualMethod   OnClose
  VirtualMethod   OnConnect,          PIO_SOCKJOB
  VirtualMethod   OnError,            PIO_SOCKJOB, DWORD      ;-> IO_SockJob, dError
  VirtualMethod   OnFree
  VirtualMethod   OnRead,             PIO_SOCKJOB
  VirtualMethod   OnWrite,            PIO_SOCKJOB

  ;Methods to (re)issue send/recv jobs
  VirtualMethod   DoRead,             PIO_SOCKJOB
  VirtualMethod   DoWrite,            PIO_SOCKJOB

  ;Data Members
  DefineVariable  ChainItem,          SDLL_ITEM,        {NULL, NULL}
  DefineVariable  dPendingIOJobs,     DWORD,            0     ;Pending IO jobs
  DefineVariable  dCompletedIOJobs,   DWORD,            0     ;Completed IO jobs
  DefineVariable  RcvIOChain,         SDLL_SENTINEL,    {NULL, NULL}  ;Recieve IOSockJob chain
  DefineVariable  dFlags,             DWORD,            NCC_DISCONNECTED
  DefineVariable  dRcvLastTime,       DWORD,            -1    ;Last time we recieved data (secs)

  ;Networking stuff
  DefineVariable  pProtocol,          POINTER,          NULL
  DefineVariable  hSocket,            SOCKET,           INVALID_SOCKET
  DefineVariable  RemoteHostAddr,     NETCOMADDR,       {}
  DefineVariable  LocalHostAddr,      NETCOMADDR,       {}    ;Here is the complete addr, incl. port
  DefineVariable  ConnStartTime,      SYSTEMTIME,       {0,0,0,0,0,0,0,0}
  DefineVariable  pConnectEx,         PTO_CONNECTEX,    NULL  ;Procedure address per socket basis

  DefineVariable  pProtocolData,      POINTER,          NULL  ;-> local protocol data
  DefineVariable  CritSect,           CRITICAL_SECTION, {}
ObjectEnd

; --------------------------------------------------------------------------------------------------
; Object:  NetComConnectionPool
; Purpose: Implement a DataPool of NetComConnections.

Object NetComConnectionPool, NetComConnectionPoolID, DataPool
  RedefineMethod  Init,               POINTER, DWORD, POINTER
  RedefineMethod  NewItem
  RedefineMethod  FreeItem,           $ObjPtr(NetComConnection)

  DefineVariable  dCount,             DWORD,    0
  DefineVariable  pIOSockJobPool,     $ObjPtr(NetComIOSockJobPool),  NULL
ObjectEnd

; --------------------------------------------------------------------------------------------------
; Object:  NetComAddrCollection
; Purpose: Implement an WinSockAddr collection.

Object NetComAddrCollection,, SortedDataCollection
  RedefineMethod  Compare,            PNETCOMADDR_ENTRY, PNETCOMADDR
  RedefineMethod  Init,               POINTER, DWORD, DWORD, DWORD
  RedefineMethod  Insert,             POINTER
ObjectEnd

; --------------------------------------------------------------------------------------------------
; Object:  NetComProtocol
; Purpose: NetworkProtocol is a base object from which you can derive your own protocol and
;          application specific objects. You can imagine that this object sits inbetween the main
;          NetComEngine object and your application - it is an 'event sink' - its methods are called
;          by the NetComEngine object. Its main job is to enforce the rules of a network
;          protocol, but it can also be used to alert your application about some important events,
;          for example the completion of a Connect attempt. Your application should create one of
;          these objects instances for each network protocol that you wish to support, and hand such
;          instances to the NetComEngine whenever you call NetComEngine.ConnectTo or
;          NetComEngine.Listen...
;          The NetComEngine object will thereafter marshal completed events to the NetComProtocol
;          derived object you provided on a per NetComConnection basis. This implies that each
;          network session can use a different protocol.

Object NetComProtocol, NetComProtocolID, Primer
  VirtualMethod   Allocate,           $ObjPtr(NetComConnection)
  VirtualMethod   AddToBlackList,     PNETCOMADDR                   ;-> NETCOMADDR
  RedefineMethod  Done
  RedefineMethod  Init,               POINTER, PSTRING              ;-> Owner, -> Service name
  VirtualMethod   IsDataComplete?,    $ObjPtr(NetComConnection), PIO_SOCKJOB
  VirtualMethod   IsBlackListed?,     PNETCOMADDR                   ;-> NETCOMADDR
  VirtualMethod   OnAccept,           $ObjPtr(NetComConnection)
  VirtualMethod   OnClose,            $ObjPtr(NetComConnection)
  VirtualMethod   OnConnect,          $ObjPtr(NetComConnection)
  VirtualMethod   OnDisconnect,       $ObjPtr(NetComConnection)
  VirtualMethod   OnError,            $ObjPtr(NetComConnection), PIO_SOCKJOB, DWORD
  VirtualMethod   OnTimeout,          $ObjPtr(NetComConnection)
  VirtualMethod   ProcessData,        $ObjPtr(NetComConnection), DWORD ;-> NetComConnection, Index
  VirtualMethod   Release,            $ObjPtr(NetComConnection)

  DefineVariable  pServiceName,       PSTRING,  NULL
  DefineVariable  dTimeoutRcv,        DWORD,    0       ;Timeout in msecs, 0 means no timeout
  DefineVariable  dTimeoutSnd,        DWORD,    0       ;Timeout in msecs, 0 means no timeout

  Embed BlackList, NetComAddrCollection         ;List of addresses that are not allowed to connect
ObjectEnd

; --------------------------------------------------------------------------------------------------
; Object:  NetComEngine
; Purpose: Implement the IOCP core of the NetComEngine.
; Note:    Connections are tracked in a linked list, since they may come from an attack!
;          The supervisor thread should analyse them and eventually close the connections and add
;          the IP addresses to the black list.

Object NetComEngine, NetComEngineID, Primer
  VirtualMethod   ConnectionsClose
  VirtualMethod   ConnectionsDisconnect
  VirtualMethod   ConnectionsFree
  VirtualMethod   ConnectTo,          $ObjPtr(NetComProtocol), PNETCOMADDR
  RedefineMethod  Done
  VirtualMethod   FreeConnection,     $ObjPtr(NetComConnection)
  RedefineMethod  Init,               POINTER, DWORD, DWORD, DWORD, DWORD
  VirtualMethod   Listen,             $ObjPtr(NetComProtocol)       ;-> NetComProtocol
  VirtualMethod   NewConnection,      $ObjPtr(NetComProtocol)       ;-> NetComProtocol
  VirtualMethod   QueueAcceptor,      PLISTENER, $ObjPtr(NetComProtocol)
  StaticMethod    Worker
  StaticMethod    Supervisor

  DefineVariable  hIOCP,              HANDLE,         0             ;IOCP HANDLE
  DefineVariable  dWorkerCount,       DWORD,          0
  DefineVariable  dShuttingDown,      DWORD,          0
  DefineVariable  dAcceptorCount,     DWORD,          0             ;Acceptor count
  DefineVariable  hSupervisor,        HANDLE,         0             ;Thread HANDLE
  DefineVariable  ConnectionChain,    SDLL_SENTINEL,  {NULL, NULL}
  DefineVariable  dBytesIn,           DWORD,          0
  DefineVariable  dBytesOut,          DWORD,          0
  DefineVariable  dRateIn,            DWORD,          0
  DefineVariable  dRateOut,           DWORD,          0
  DefineVariable  pLocalHostName,     PSTRING,        NULL
  DefineVariable  LocalHostAddr,      NETCOMADDR,     {}

  Embed Connections,  NetComConnectionPool              ;Pool of NetComConnections
  Embed Listeners,    DataCollection                    ;DataCollection of listening sockets
  Embed IOJobs,       NetComIOSockJobPool               ;IOSockJob Pool
  Embed Workers,      XWCollection                      ;Collection of Worker thread HANDLEs
ObjectEnd


; ==================================================================================================

if IMPLEMENT

DbgSockError macro WarningText:req, InfoText, Dest
  if DEBUGGING
    DbgSaveContext
    DbgSetDestWnd Dest
    invoke DbgOutTextA, $OfsCStrA($Esc(<WarningText>)), DbgColorWarning, DbgColorBackground, DBG_EFFECT_NORMAL, \
                        ??DbgDstWnd
    invoke WSAGetLastError
    mov ebx, eax
    $$Buffersize = 1024
    sub xsp, $$Buffersize                               ;;Reserve a buffer on the stack.
    if TARGET_BITNESS eq 32
      mov edi, esp                                      ;;Get a pointer to the buffer
    else
      lea rdi, [rsp + 28h]                              ;;Get a POINTER to the output buffer
    endif
    invoke wsprintfA, xdi, $OfsCStrA(" - WSA error code: %lit - "), ebx
    invoke DbgOutTextA, xdi, DbgColorWarning, DbgColorBackground, DBG_EFFECT_NORMAL, ??DbgDstWnd
    invoke NetErr2Str, ebx, xdi, $$Buffersize - 28h     ;Get the error message
    invoke DbgOutTextA, xdi, DbgColorWarning, DbgColorBackground, DBG_EFFECT_NORMAL, ??DbgDstWnd
    add xsp, 1024                                       ;Retrieve the string room
    DbgShowTxtInfo InfoText, ??DbgDstWnd
    DbgShowSrcInfo ??DbgDstWnd
    DbgLoadContext
  endif
endm

CheckSockError macro QuotedWarningText:req, InfoText, Dest
  if DEBUGGING
    .if eax == SOCKET_ERROR
      DbgSockError QuotedWarningText, InfoText, Dest
    .endif
  endif
endm

; --------------------------------------------------------------------------------------------------
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

; --------------------------------------------------------------------------------------------------
; Macro:      $NetworkPort
; Purpose:    Convert a WORD to a network port (network byte order = big endian).
; Arguments:  Arg1: Port.

$NetworkPort macro Port:req
  %exitm <(Port and 0FFh) shl 8 + (Port shr 8)>
endm


; ==================================================================================================

include NetComAddrCollection.inc   ;Collection for handling of NETCOMADDR structures
include NetComProtocol.inc         ;Base object for handling of Network Events
include NetComIOSockJobPool.inc    ;Object for recycling of NetComIOJob objects
include NetComConnection.inc       ;This object represents one TCP/IP network session
include NetComConnectionPool.inc   ;Object for recycling of NetComConnections
include NetComEngine.inc           ;The main IOCP object, and IOCP message handler thread

; ==================================================================================================

endif
