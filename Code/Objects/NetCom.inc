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
;             RemoteAddr field, stored in NetComConnection. The newly-supported SOCK_SEQPACKET
;             will also use that. But the SOCK_DGRAM, SOCK_RDM and SOCK_RAW will use the
;             'session local' copy of the RemoteAddr field, stored in IOSockJob.
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
;
;                         -------------------
;          ------------->|    Application    |<----------
;         |              |-------------------|           |                 Security
;         |              |                   |           |            -------------------
;         |              |                   |    ------------------>|  NetComSupervisor |
;         |              |                   |   |       |           |-------------------|
;         |               -------------------    |    ---------------| pOwner            |
;         |                                      |   |   |           |                   |
;         |                                      |   |   |           |                   |
;         |                                      |   |   |            -------------------
;         |                                      |   |   |
;         |          Server/Client               |   |   |               Functionality
;         |       -------------------            |   |   |            -------------------
;         |   -->|   NetComEngine    |<--------------    |    ------>|  NetComProtocol   |
;         |  |   |-------------------|     |     |       |   |       |-------------------|
;          --|---| pOwner            |     |     |        ---|-------| pOwner            |
;            |   |        pSupervisor|-----------            |       |                   |
;            |   |                   |     |                 |       |                   |
;            |    -------------------      |                 |        -------------------
;            |                             |                 |
;            |                              -----------------|---
;            |                                               |   |
;            |           --------------------                |   |    -------------------
;            |       -->|NetComConnectionPool|        -------|------>|NetComIOSockJobPool|- - -
;            |      |   |--------------------|       |       |   |   |-------------------|     |
;             ------|---| pOwner             |       |       |    ---| pOwner            |
;                   |   |     pIOSockJobPool |-------        |       | dBufferSize       |     |
;                   |   |                    |               |       |                   |
;                   |    --------------------                |        -------------------      |
;                   |                                        |
;                   |                                        |                                 |
;                   |                                        |
;                   |           -------------------          |        -------------------      |
;                   |          | NetComConnection  |< - - - -|- - - -|  NetComIOSockJob  |< - -
;                   |          |-------------------||        |       |-------------------||
;                    ----------| pOwner            |||       |       |                   |||
;                              |         pProtocol |||-------        |                   ||||
;                              |                   |||               |                   |||||
;                               ------------------- ||                ------------------- |||||
;                                ------------------- |                 ------------------- ||||
;                                 -------------------                   ------------------- |||
;                                                                        --------------------||
;                                                                         ------------------- |
;                                                                          -------------------
;
;
; ==================================================================================================


SO_CONNECT_TIME             equ   0700Ch
;SO_EXCLUSIVEADDRUSE

;IO socket operations
OPERATION_SOCK_ACCEPT       equ   1h
OPERATION_SOCK_CONNECT      equ   2h
OPERATION_SOCK_RECV         equ   3h
OPERATION_SOCK_SEND         equ   4h

;IO Job Flag
IOF_JOB_COMPLETED           equ   BIT00     ;Completed

ERROR_BAD_PROTOCOL          equ   -1
ERROR_USER_QUIT             equ   -2

;Protocol commands
PROT_CMD_NONE               equ   0
PROT_CMD_DISCONNECT         equ   1         ;Connection teardown
PROT_CMD_CLOSE              equ   2         ;Connection cut
PROT_CMD_DESTROY            equ   3         ;Destroy connection object

;NetComConnection state
NCS_NONE                    equ   0
NCS_CREATED                 equ   1
NCS_BOUND                   equ   2
NCS_LISTENING               equ   3
NCS_CONNECTING              equ   4
NCS_CONNECTED               equ   5
NCS_CLOSING                 equ   6
NCS_CLOSED                  equ   7

;NetComConnection flags
NCC_SHUTDOWN_RCV_REMOTE     equ   BIT00
NCC_SHUTDOWN_SND_REMOTE     equ   BIT01
NCC_SHUTDOWN_RCV_LOCAL      equ   BIT02
NCC_SHUTDOWN_SND_LOCAL      equ   BIT03

NCC_DISCONNECTED_LOCAL      equ   NCC_SHUTDOWN_RCV_LOCAL  or NCC_SHUTDOWN_SND_LOCAL
NCC_DISCONNECTED_REMOTE     equ   NCC_SHUTDOWN_RCV_REMOTE or NCC_SHUTDOWN_SND_REMOTE
NCC_DISCONNECTED_SEND       equ   NCC_SHUTDOWN_RCV_REMOTE or NCC_SHUTDOWN_SND_LOCAL
NCC_DISCONNECTED_RECEIVE    equ   NCC_SHUTDOWN_RCV_LOCAL  or NCC_SHUTDOWN_SND_REMOTE

;Lifecycle control
NCC_CLOSED                  equ   BIT04
NCC_QUEUE_DESTROY           equ   BIT05     ;Marked to terminate the connection object
NCC_QUEUE_ACCEPT            equ   BIT06
NCC_ACCEPTED                equ   BIT07
NCC_QUEUE_CONNECT           equ   BIT08
NCC_CONNECTED               equ   BIT09

;Backpressure control
NCC_RCV_PAUSED              equ   BIT12
NCC_SND_PAUSED              equ   BIT13

;NetCom Error states
NCE_ACCEPT                  equ   BIT27     ;Error happend while accepting
NCE_CONNECT                 equ   BIT28     ;Error happend while connecting
NCE_SEND                    equ   BIT29     ;Error happend while sending
NCE_RECEIVE                 equ   BIT30     ;Error happend while receiving
NCE_UNKNOWN                 equ   BIT31     ;Error happend during an unknown operation

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

_NETCOMADDR_ struc                          ;Auxiliar structure to get the total size
  union
    SOCKADDR                  {}            ;IPv4
    SOCKADDR_IN               {}            ;IPv4 only
    SOCKADDR_IN6              {}            ;IPv6 only
    SOCKADDR_STORAGE          {}            ;IPv4, IPv6, NetBIOS, infrared or Bluetooth
  ends
_NETCOMADDR_ ends

NETCOMADDR struc                            ;Universal address structure
  wFamily   WORD  ?
  wPort     WORD  ?
  Address   BYTE  sizeof(_NETCOMADDR_) - 2*sizeof(WORD) dup(?)
NETCOMADDR ends
PNETCOMADDR typedef ptr NETCOMADDR


LISTENER struc 4
  hSocket         SOCKET      ?
LISTENER ends
PLISTENER typedef ptr LISTENER

;This structure is not integrated into IO_SOCKJOB to be able to calculate some offsets
IO_HEADER struc 2
  Ovl             OVERLAPPED  {}            ;Must be always the first structure member!
  wOperation      WORD        ?             ;Operation ID, i.e. OPERATION_SOCK_RECV
  wFlags          WORD        ?             ;Flags: IOF_JOB_????
  dBytesConsumed  DWORD       ?             ;#bytes currently placed in the buffer
IO_HEADER ends
IO_HEADER_SIZE equ sizeof(IO_HEADER)

IO_SOCKJOB struc 4
                  IO_HEADER   {}
                  SDLL_ITEM   {}            ;Linked list to hold buffers together
  WSABuf          WSABUF      {}
  DataBuffer      BYTE        0 dup(?)      ;The data buffer is placed here
IO_SOCKJOB ends                             ;  Minimal size of the buffer must
PIO_SOCKJOB typedef ptr IO_SOCKJOB          ;  be sizeof ACCEPT_DATA

;IO_SOCKJOB databuffer structure for an OPERATION_SOCK_ACCEPT operation
ACCEPT_DATA struct 4
  LocalAddr       BYTE        (sizeof(NETCOMADDR) + 16) dup(?)   ;16 BYTEs added, see AcceptEx
  RemoteAddr      BYTE        (sizeof(NETCOMADDR) + 16) dup(?)   ;  documentation
  pListener       PLISTENER   ?
  pConnection     POINTER     ?
ACCEPT_DATA ends

;WSACF_DONT_REMOVE             equ   BIT00


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

; Example: MTU=1500, MSS=1460 (Wireshark)
; 1460 bytes TCP payload (MSS)
; + 20 bytes TCP header
; + 20 bytes IP header
; + 4 bytes Ethernet FCS (depends on capture method)
; = 1504 bytes captured

COMPLETION_KEY_VOID           equ   -1      ;Used to purge the connection
COMPLETION_KEY_KILL_WORKER    equ   -2
COMPLETION_KEY_SOCK_ACCEPTED  equ   -3

AcceptEx proto WIN_STD_CALL_CONV :SOCKET,:SOCKET,:PVOID,:DWORD,:DWORD,:DWORD,:LPDWORD,:LPOVERLAPPED
TYPE_Connectex typedef proto :HANDLE, :POINTER, :DWORD, :POINTER, :DWORD, :POINTER, :LPOVERLAPPED
PTO_CONNECTEX typedef ptr TYPE_Connectex


if TARGET_STR_TYPE eq STR_TYPE_ANSI
  GetHostName equ gethostname
else
  GetHostName equ GetHostNameW
endif

@DefProto DllImport, GetAdaptersAddresses, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :DWORD, :POINTER, :POINTER>, 20

IP_ADAPTER_UNICAST_ADDRESS struct
  Length_               DWORD     ?
  Flags                 DWORD     ?
  Next                  POINTER   ?
  Address               SOCKET_ADDRESS <>
  PrefixOrigin          DWORD     ?
  SuffixOrigin          DWORD     ?
  DadState              DWORD     ?
  ValidLifetime         DWORD     ?
  PreferredLifetime     DWORD     ?
  LeaseLifetime         DWORD     ?
  OnLinkPrefixLength    BYTE      ?
  _pad                  BYTE      3 dup(?)  ;Alignment
IP_ADAPTER_UNICAST_ADDRESS ends

IP_ADAPTER_ADDRESSES struct
  Length_               DWORD     ?
  IfIndex               DWORD     ?

  Next                  POINTER   ?
  AdapterName           POINTER   ?

  FirstUnicastAddress   POINTER   ?
  FirstAnycastAddress   POINTER   ?
  FirstMulticastAddress POINTER   ?
  FirstDnsServerAddress POINTER   ?

  DnsSuffix             PWSTR     ?
  Description           PWSTR     ?
  FriendlyName          PWSTR     ?

  PhysicalAddress       BYTE      8 dup(?)
  PhysicalAddressLength DWORD     ?

  Flags                 DWORD     ?
  Mtu                   DWORD     ?
  IfType                DWORD     ?
  OperStatus            DWORD     ?

  Ipv6IfIndex           DWORD     ?
  ZoneIndices           DWORD     16 dup(?)

  FirstPrefix           POINTER   ?
IP_ADAPTER_ADDRESSES ends


@DefProto DllImport, GetIpNetTable2, WIN_STD_CALL_CONV,, <:DWORD, :POINTER>, 8
@DefProto DllImport, FreeMibTable, WIN_STD_CALL_CONV,, <:POINTER>, 4

IF_MAX_PHYS_ADDRESS_LENGTH equ  32

MIB_IPNET_ROW2 struct 4
  Address               SOCKADDR_INET <>
  InterfaceIndex        DWORD     ?         ;NET_IFINDEX
  InterfaceLuid         LUID      <>
  PhysicalAddress       UCHAR IF_MAX_PHYS_ADDRESS_LENGTH dup (?)
  PhysicalAddressLength ULONG     ?
  State                 SDWORD    ?         ;NL_NEIGHBOR_STATE
  union
    struct
      IsRouter          BOOLEAN   ?
      IsUnreachable     BOOLEAN   ?
    ends
    Flags               UCHAR     ?
  ends
  union ReachabilityTime
    LastReachable       ULONG     ?
    LastUnreachable     ULONG     ?
  ends
MIB_IPNET_ROW2 ends
PMIB_IPNET_ROW2 typedef ptr MIB_IPNET_ROW2

MIB_IPNET_TABLE2 struct
  NumEntries            DWORD     ?
                        DWORD     ?         ;Alignment 32/64 bit
  Table                 MIB_IPNET_ROW2 0 dup(<>)
MIB_IPNET_TABLE2 ends
PMIB_IPNET_TABLE2 typedef ptr MIB_IPNET_TABLE2


; --------------------------------------------------------------------------------------------------
; Macro:      $htons / $htonl
; Purpose:    Convert a WORD/DWORD to a network port (network byte order = big endian).
; Arguments:  Arg1: Port.

$htons macro Port
  %exitm <((Port and 0ffh) shl 8) or ((Port and 0ff00h) shr 8)>
endm

$htonl macro Port
  %exitm <((Port and 0000000ffh) shl 24) or \
          ((Port and 00000ff00h) shl  8) or \
          ((Port and 000ff0000h) shr  8) or \
          ((Port and 0ff000000h) shr 24)>
endm


DEFAULT_LISTENING_PORT  equ $htons(25773)

;Defaults (can be changed at runtime via your UI/init paths)
TX_HIGH_WM_DEFAULT      equ (4*1024*1024)   ;4 MiB Watermark
TX_LOW_WM_DEFAULT       equ (2*1024*1024)   ;2 MiB Watermark

; --------------------------------------------------------------------------------------------------
; Object:  NetComIOSockJobPool
; Purpose: Implement a DataPool of IOSockJobs. An IOSockJob is a memory chunk with a header structure
;          called IO_SOCKJOB followed by a data buffer.

Object NetComIOSockJobPool, NetComIOSockJobPoolID, DataPool
  RedefineMethod  Done
  RedefineMethod  Init,               POINTER, DWORD, DWORD

  RedefineMethod  NewItem,            WORD
  RedefineMethod  FreeItem,           PIO_SOCKJOB
  RedefineMethod  Reset
  VirtualMethod   ResetIOJob,         PIO_SOCKJOB, WORD

  DefineVariable  dBufferSize,        DWORD,            0     ;Payload size of each Item in BYTEs
  DefineVariable  dCount,             DWORD,            0     ;Control value
  DefineVariable  CritSect,           CRITICAL_SECTION, {}
ObjectEnd

; --------------------------------------------------------------------------------------------------
; Object:  NetComConnection
; Purpose: Implement a NetCom connection.

Object NetComConnection, NetComConnectionID, Primer
  VirtualMethod   Admit,              DWORD
  VirtualMethod   Close,              DWORD                   ;Graceful/Abortive disconnection
  VirtualMethod   Disconnect,         DWORD                   ;Gracefull disconnect one or both directions
  RedefineMethod  Done
  RedefineMethod  Init,               POINTER, POINTER        ;-> Owner, -> NetComProtocol
  VirtualMethod   HandleProtocolCmd,  DWORD                   ;Command
  VirtualMethod   FreeRessources
  VirtualMethod   TryQueueReceive

  VirtualMethod   QueueDestroy

  ;Methods to place IO socket jobs or messages on the IOCP queue
  VirtualMethod   QueueAccept,        PLISTENER               ;-> Listener
  VirtualMethod   QueueConnect,       PNETCOMADDR, PNETCOMADDR;-> RemoteAddr, -> LocalAddr
  VirtualMethod   QueueReceive
  VirtualMethod   QueueSend,          POINTER, DWORD          ;-> Data, Size

  ;Methods to marshal completion notifications
  VirtualMethod   OnAccepted,         PIO_SOCKJOB
  VirtualMethod   OnConnected,        PIO_SOCKJOB
  VirtualMethod   OnError,            PIO_SOCKJOB, DWORD      ;-> IO_SockJob, dError
  VirtualMethod   OnReceived,         PIO_SOCKJOB
  VirtualMethod   OnSent,             PIO_SOCKJOB

  ;Methods to (re)issue send/recv jobs
  VirtualMethod   DoRcvIOJob,         PIO_SOCKJOB
  VirtualMethod   DoSndIOJob,         PIO_SOCKJOB

  ;Networking stuff
  DefineVariable  dFlags,             DWORD,            NCC_DISCONNECTED_LOCAL
  DefineVariable  ChainItem,          SDLL_ITEM,        {NULL, NULL} ;Link to other Connections
  DefineVariable  dPendingIOJobs,     DWORD,            0     ;Pending IO jobs
  DefineVariable  dCompletedIOJobs,   DWORD,            0     ;Completed IO jobs
  DefineVariable  RcvIOJobChain,      SDLL_SENTINEL,    {NULL, NULL}  ;Recieve IOSockJob chain
  DefineVariable  dRcvLstElpsdTime,   DWORD,            0     ;Last elapsed time we recieved data (secs)
  DefineVariable  pProtocol,          POINTER,          NULL
  DefineVariable  hSocket,            SOCKET,           INVALID_SOCKET
  DefineVariable  LocalAddr,          NETCOMADDR,       {AF_INETX}  ;IP + Port
  DefineVariable  RemoteAddr,         NETCOMADDR,       {AF_INETX}  ;IP + Port
  DefineVariable  ConnStartTime,      SYSTEMTIME,       {}

  ;Backpressure Metric
  DefineVariable  dSndQueuedIOJobs,   DWORD,            0     ;Total queued (in-flight + pending) IOJobs
  DefineVariable  dSndHighWtrMrk,     DWORD,            TX_HIGH_WM_DEFAULT
  DefineVariable  dSndLowWtrMrk,      DWORD,            TX_LOW_WM_DEFAULT
;  DefineVariable  dSndBlocked,        DWORD,            0     ;Boolean: window full reached at least once
;  DefineVariable  dRcvPaused,         DWORD,            0     ;Boolean: do not post new WSARecv
  DefineVariable  dRcvQueuedIOJobs,   DWORD,            0     ;Number of posted Recv operations (0/1)

  ;Management
  DefineVariable  pData,              POINTER,          NULL  ;-> Data managed by the protocol
  DefineVariable  CritSect,           CRITICAL_SECTION, {}
;  DefineVariable  ObjLock,            OBJECT_LOCK,      {}
  DefineVariable  wName,              CHRW,             28 dup(?) ;Used for DebugCenter Wnd Caption
ObjectEnd

; --------------------------------------------------------------------------------------------------
; Object:  NetComConnectionPool
; Purpose: Implement a DataPool of NetComConnections.

Object NetComConnectionPool, NetComConnectionPoolID, DataPool
  RedefineMethod  Done
  RedefineMethod  Init,               POINTER, DWORD, POINTER
  RedefineMethod  NewItem
  RedefineMethod  FreeItem,           $ObjPtr(NetComConnection)
  RedefineMethod  Reset

  DefineVariable  dCount,             DWORD,            0     ;Control value
  DefineVariable  pIOSockJobPool,     $ObjPtr(NetComIOSockJobPool),  NULL
  DefineVariable  CritSect,           CRITICAL_SECTION, {}
ObjectEnd

; --------------------------------------------------------------------------------------------------
; Object:  NetComAddrCollection
; Purpose: Implement an WinSockAddr collection.

Object NetComAddrCollection,, SortedDataCollection
  RedefineMethod  Compare,            PNETCOMADDR, PNETCOMADDR
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
  RedefineMethod  Init,               POINTER                       ;-> Owner
  VirtualMethod   IsDataComplete?,    $ObjPtr(NetComConnection), PIO_SOCKJOB
  VirtualMethod   IsBlackListed?,     PNETCOMADDR                   ;-> NETCOMADDR
  VirtualMethod   OnAccepted,         $ObjPtr(NetComConnection)
  VirtualMethod   OnClosed,           $ObjPtr(NetComConnection)
  VirtualMethod   OnConnected,        $ObjPtr(NetComConnection)
  VirtualMethod   OnDisconnected,     $ObjPtr(NetComConnection), DWORD, DWORD
  VirtualMethod   OnError,            $ObjPtr(NetComConnection), PIO_SOCKJOB, DWORD
  VirtualMethod   OnTimeouted,        $ObjPtr(NetComConnection)
  VirtualMethod   ProcessData,        $ObjPtr(NetComConnection), DWORD ;-> NetComConnection, Index
  VirtualMethod   Release,            $ObjPtr(NetComConnection)

  ;If ClientLocalAddr is set to INADDR_ANY, the server listens on all available network interfaces
  ;Supported service strings are listed here: %WINDIR%\system32\drivers\etc\services
  DefineVariable  ListeningAddr,      NETCOMADDR, {AF_INETX, DEFAULT_LISTENING_PORT}

  ;Timeout in msecs, 0 means no timeout
  DefineVariable  dTimeoutAcp,        DWORD,      0     ;Accept - not implementd yet
  DefineVariable  dTimeoutCon,        DWORD,      0     ;Connect - not implementd yet
  DefineVariable  dTimeoutRcv,        DWORD,      0     ;Recieve
  DefineVariable  dTimeoutSnd,        DWORD,      0     ;Send - not implementd yet

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
  VirtualMethod   ConnectionsDestroy
  VirtualMethod   ConnectTo,          $ObjPtr(NetComProtocol), PNETCOMADDR, PNETCOMADDR
  RedefineMethod  Done
  RedefineMethod  Init,               POINTER, POINTER, DWORD, DWORD, DWORD
  VirtualMethod   NewConnection,      $ObjPtr(NetComProtocol)
  VirtualMethod   NewAcceptor,        PLISTENER, $ObjPtr(NetComProtocol)
  StaticMethod    Worker
  StaticMethod    Supervisor
  StaticMethod    Startup
  StaticMethod    Shutdown
  VirtualMethod   StartListening,     DWORD, $ObjPtr(NetComProtocol)
  VirtualMethod   StopListening

  DefineVariable  hIOCP,              HANDLE,         0             ;IOCP HANDLE
  DefineVariable  dWorkerCount,       DWORD,          0
  DefineVariable  pSupervisor,        POINTER,        NULL
  DefineVariable  ConnectionChain,    SDLL_SENTINEL,  {NULL, NULL}
  DefineVariable  dBytesIn,           DWORD,          0
  DefineVariable  dBytesOut,          DWORD,          0
  DefineVariable  dRateIn,            DWORD,          0
  DefineVariable  dRateOut,           DWORD,          0
  DefineVariable  pLocalHostName,     PSTRING,        NULL

  Embed ConnectionPool, NetComConnectionPool            ;Pool of NetComConnections
  Embed IOSockJobPool,  NetComIOSockJobPool             ;IOSockJob Pool
  Embed Listeners,      DataCollection                  ;DataCollection of listening sockets
  Embed Workers,        XWCollection                    ;Collection of Worker thread HANDLEs
ObjectEnd

; --------------------------------------------------------------------------------------------------
; Object:  NetComSupervisor
; Purpose: Controls overall status of the NetComEngine

Object NetComSupervisor, NetComSupervisorID, Primer
  RedefineMethod  Done
  RedefineMethod  Init,               POINTER           ;-> NetComEngine
  VirtualMethod   Worker

  DefineVariable  hWorker,            HANDLE,     0
  DefineVariable  WorkerWaitHandles,  HANDLE,     3 dup(?)

  ;Timeout in msecs, 0 means no timeout
  DefineVariable  dTimeoutAcp,        DWORD,      0     ;Accept - not implementd yet
  DefineVariable  dTimeoutCon,        DWORD,      0     ;Connect - not implementd yet
  DefineVariable  dTimeoutRcv,        DWORD,      0     ;Recieve
  DefineVariable  dTimeoutSnd,        DWORD,      0     ;Send - not implementd yet
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Purpose:    Debugging macros

DbgOutSockMessage macro WarningText:req, Error, InfoText
  invoke DbgOutCmd, DBG_CMD_SINGLE_LINE, DbgColorWarning, DbgColorBackground, ??DbgDstWnd
  invoke DbgOutTextA, $OfsCStrA($Esc(<WarningText>)), DbgColorWarning, DbgColorBackground, \
                      DBG_EFFECT_NORMAL, ??DbgDstWnd

  $$Buffersize = 1024
  sub xsp, $$Buffersize                               ;;Reserve a buffer on the stack.
  if TARGET_BITNESS eq 32
    mov edi, esp                                      ;;Get a pointer to the buffer
  else
    lea r14, [rsp + 28h]                              ;;Get a POINTER to the output buffer
  endif
  invoke wsprintfA, r14, $OfsCStrA(CRLF, "WSA error code: %lit - "), Error
  invoke StrEnd, r14
  mov ecx, ebx
  mov rbx, xax
  invoke NetErr2StrA, ebx, xax, $$Buffersize - 28h    ;;Get the error message
  mov CHRA ptr [rbx + xax - 2*sizeof(CHRA)], 0        ;;Remove last CHRLF
  invoke DbgOutTextA, r14, DbgColorWarning, DbgColorBackground, DBG_EFFECT_NORMAL, ??DbgDstWnd
  add xsp, 1024                                       ;;Retrieve the string space
  DbgShowTxtInfo InfoText, ??DbgDstWnd
  DbgShowSrcInfo ??DbgDstWnd
  invoke DbgOutCmd, DBG_CMD_SINGLE_LINE, DbgColorWarning, DbgColorBackground, ??DbgDstWnd
endm

DbgSockError macro WarningText:req, Error, InfoText, Dest
  if DEBUGGING
    DbgSaveContext FALSE, Error
    DbgSetDestWnd Dest
    ifb <Error>
      invoke WSAGetLastError
      mov ebx, eax
    endif
    DbgOutSockMessage WarningText, ebx, InfoText
    DbgLoadContext
  endif
endm

DbgOnSockError macro WarningText:req, Error, InfoText, Dest
  if DEBUGGING
    DbgSaveContext FALSE, Error
    DbgSetDestWnd Dest
    ifb <Error>
      invoke WSAGetLastError
      mov ebx, eax
    endif
    .if ebx != NO_ERROR
      DbgOutSockMessage WarningText, ebx, InfoText
    .endif
    DbgLoadContext
  endif
endm

DbgCheckSockReturn macro QuotedWarningText:req, InfoText, Dest
  if DEBUGGING
    .if eax != NO_ERROR
       DbgSockError QuotedWarningText,, InfoText, Dest
    .endif
  endif
endm


DbgOutComAddrIPV4 macro NetComAddr:req
  invoke DbgOutTextA, $OfsCStrA("Family = "), DbgColorDefaultPre, DbgColorBackground, \
                      DBG_EFFECT_NORMAL, ??DbgDstWnd
  movsx edx, SWORD ptr NetComAddr.NETCOMADDR.wFamily
  invoke sdword2decA, r14, edx
  invoke DbgOutTextA, r14, DbgColorDefaultVar, DbgColorBackground, \
                      DBG_EFFECT_NORMAL, ??DbgDstWnd

  invoke DbgOutTextA, $OfsCStrA(", Port = "), DbgColorDefaultPre, DbgColorBackground, \
                      DBG_EFFECT_NORMAL, ??DbgDstWnd
  movzx edx, BYTE ptr NetComAddr.NETCOMADDR.wPort[1]
  mov dh, BYTE ptr NetComAddr.NETCOMADDR.wPort[0]
  invoke udword2decA, r14, edx
  invoke DbgOutTextA, r14, DbgColorDefaultVar, DbgColorBackground, \
                      DBG_EFFECT_NORMAL, ??DbgDstWnd

  invoke DbgOutTextA, $OfsCStrA(", IP = "), DbgColorDefaultPre, DbgColorBackground, \
                      DBG_EFFECT_NORMAL, ??DbgDstWnd
  movzx edx, BYTE ptr NetComAddr.NETCOMADDR.Address[0]
  invoke udword2decA, r14, edx
  invoke DbgOutTextA, r14, DbgColorDefaultVar, DbgColorBackground, \
                      DBG_EFFECT_NORMAL, ??DbgDstWnd
  invoke DbgOutTextA, $OfsCStrA("."), DbgColorDefaultPre, DbgColorBackground, \
                      DBG_EFFECT_NORMAL, ??DbgDstWnd

  movzx edx, BYTE ptr NetComAddr.NETCOMADDR.Address[1]
  invoke udword2decA, r14, edx
  invoke DbgOutTextA, r14, DbgColorDefaultVar, DbgColorBackground, \
                      DBG_EFFECT_NORMAL, ??DbgDstWnd
  invoke DbgOutTextA, $OfsCStrA("."), DbgColorDefaultPre, DbgColorBackground, \
                      DBG_EFFECT_NORMAL, ??DbgDstWnd

  movzx edx, BYTE ptr NetComAddr.NETCOMADDR.Address[2]
  invoke udword2decA, r14, edx
  invoke DbgOutTextA, r14, DbgColorDefaultVar, DbgColorBackground, \
                      DBG_EFFECT_NORMAL, ??DbgDstWnd
  invoke DbgOutTextA, $OfsCStrA("."), DbgColorDefaultPre, DbgColorBackground, \
                      DBG_EFFECT_NORMAL, ??DbgDstWnd

  movzx edx, BYTE ptr NetComAddr.NETCOMADDR.Address[3]
  invoke udword2decA, r14, edx
  invoke DbgOutTextA, r14, DbgColorDefaultVar, DbgColorBackground, \
                      DBG_EFFECT_NORMAL, ??DbgDstWnd
endm

DbgNetComAddrIPV4 macro NetComAddr:req, InfoText, Dest
  if DEBUGGING
    DbgSaveContext TRUE, NetComAddr
    DbgSetDestWnd Dest
    $$Buffersize = 1024
    sub xsp, $$Buffersize                               ;;Reserve a buffer on the stack.
    if TARGET_BITNESS eq 32
      mov edi, esp                                      ;;Get a pointer to the buffer
    else
      lea r14, [rsp + 28h]                              ;;Get a POINTER to the output buffer
    endif
    DbgOutComAddrIPV4 [xbx]

    add xsp, $$Buffersize                               ;;Restore stack
    DbgShowTxtInfo InfoText, ??DbgDstWnd
    DbgShowSrcInfo ??DbgDstWnd
    DbgLoadContext
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      $NetworkAddressIPv4
; Purpose:    Convert a string to an IPv4 network address (network byte order = big endian).
; Arguments:  Arg1: String (aaa.bbb.ccc.ddd).

$NetworkAddressIPv4 macro StrAddr:req
  $$Addr = 0
  $$Pos1 = 1
  $$Multiplier = 1
  repeat 3
    $$Pos2 InStr $$Pos1, <StrAddr>, <.>
    $$Addr = $$Addr + $$Multiplier * @SubStr(<&StrAddr>, $$Pos1, $$Pos2 - $$Pos1)
    $$Pos1 = $$Pos2 + 1
    $$Multiplier = 256*$$Multiplier
  endm
  $$Addr = $$Addr + $$Multiplier*@SubStr(<&StrAddr>, $$Pos1)
  %exitm <$$Addr>
endm

; --------------------------------------------------------------------------------------------------
; Macro:      DbgConnection
; Purpose:    Shows NetComConnection internal data.
; Arguments:  Arg1: -> NetComConnection.
;             Arg2: Optional information.
;             Arg3: Optional destination Window name.

DBG_COLOR_FORE_CONNECTION equ DbgColorDefaultVar
DBG_COLOR_BACK_CONNECTION equ DbgColorBackground

DbgConnection macro pConnection:req, InfoText, Dest
  if DEBUGGING
    DbgSaveContext FALSE, pConnection
    assume xax:NOTHING, xbx:NOTHING, xcx:NOTHING, xdx:NOTHING, xdi:NOTHING, xsi:NOTHING
    DbgSetDestWnd Dest
    invoke DbgOutCmd, DBG_CMD_SINGLE_LINE, DBG_COLOR_FORE_CONNECTION, DBG_COLOR_BACK_CONNECTION, ??DbgDstWnd
    ifnb <InfoText>
      invoke DbgOutTextA, $OfsCStrA(<InfoText>), DBG_COLOR_FORE_CONNECTION, DBG_COLOR_BACK_CONNECTION, \
                          DBG_EFFECT_NORMAL, ??DbgDstWnd
    endif
    DbgShowSrcInfo ??DbgDstWnd

    $$Buffersize = 1024
    sub xsp, $$Buffersize                               ;;Reserve a buffer on the stack.
    if TARGET_BITNESS eq 32
      mov esi, esp                                      ;;Get a pointer to the buffer
    else
      lea r15, [rsp + 28h]                              ;;Get a POINTER to the output buffer
    endif

    mov xdi, r15
    WriteFA xdi, "Connection = ¦HXh", xbx
    invoke DbgOutTextA, r15, DBG_COLOR_FORE_CONNECTION, DBG_COLOR_BACK_CONNECTION, \
                        DBG_EFFECT_NEWLINE, ??DbgDstWnd

    FillStringA [r15], <Connection flags = >
    lea xdi, [r15 + ??StrLen]
    xor eax, eax
    mov edx, [xbx].$Obj(NetComConnection).dFlags
    mov xcx, 32                                         ;;Bits
  @@:
    rcl edx, 1                                          ;;Set bit in carry flag
    setc al
    add al, "0"
    stosb
    loop @B
    mov DCHRA ptr [xdi], "y"                            ;;Set "y" specifier and ZTC
    invoke DbgOutTextA, r15, DBG_COLOR_FORE_CONNECTION, DBG_COLOR_BACK_CONNECTION, DBG_EFFECT_NEWLINE, ??DbgDstWnd

    mov xdi, r15
    WriteFA xdi, "Pending IO-Jobs = ¦UD", [xbx].$Obj(NetComConnection).dPendingIOJobs
    invoke DbgOutTextA, r15, DBG_COLOR_FORE_CONNECTION, DBG_COLOR_BACK_CONNECTION, \
                        DBG_EFFECT_NEWLINE, ??DbgDstWnd

    mov xdi, r15
    WriteFA xdi, "Completed IO-Jobs = ¦UD", [xbx].$Obj(NetComConnection).dCompletedIOJobs
    invoke DbgOutTextA, r15, DBG_COLOR_FORE_CONNECTION, DBG_COLOR_BACK_CONNECTION, \
                        DBG_EFFECT_NEWLINE, ??DbgDstWnd
;    mov xdi, r15
;    WriteFA xdi, "Receive last time = ¦UD seconds", [xbx].$Obj(NetComConnection).dRcvLstElpsdTime
;    invoke DbgOutTextA, r15, DBG_COLOR_FORE_CONNECTION, DBG_COLOR_BACK_CONNECTION, \
;                        DBG_EFFECT_NEWLINE, ??DbgDstWnd
;
;    mov xdi, r15
;    WriteFA xdi, "Protocol = ¦HXh", [xbx].$Obj(NetComConnection).pProtocol
;    invoke DbgOutTextA, r15, DBG_COLOR_FORE_CONNECTION, DBG_COLOR_BACK_CONNECTION, \
;                        DBG_EFFECT_NEWLINE, ??DbgDstWnd

    mov xdi, r15
    WriteFA xdi, "Socket Handle = ¦HX ", [xbx].$Obj(NetComConnection).hSocket
    invoke DbgOutTextA, r15, DBG_COLOR_FORE_CONNECTION, DBG_COLOR_BACK_CONNECTION, \
                        DBG_EFFECT_NEWLINE, ??DbgDstWnd

    mov r14, r15
    DbgOutComAddrIPV4 [xbx].$Obj(NetComConnection).LocalAddr
    invoke DbgOutTextA, $OfsCStrA(", Local address"), DBG_COLOR_FORE_CONNECTION, DBG_COLOR_BACK_CONNECTION, \
                        DBG_EFFECT_NEWLINE, ??DbgDstWnd
    mov r14, r15
    DbgOutComAddrIPV4 [xbx].$Obj(NetComConnection).RemoteAddr
    invoke DbgOutTextA, $OfsCStrA(", Remote address"), DBG_COLOR_FORE_CONNECTION, DBG_COLOR_BACK_CONNECTION, \
                        DBG_EFFECT_NEWLINE, ??DbgDstWnd

    add xsp, 1024                                       ;;Retrieve the string space

    DbgLoadContext
  endif
endm

; ==================================================================================================

include NetComAddrCollection.inc   ;Collection for handling of NETCOMADDR structures
include NetComProtocol.inc         ;Base object for handling of Network Events
include NetComIOSockJobPool.inc    ;Object for recycling of NetComIOJob objects
include NetComConnection.inc       ;This object represents one TCP/IP network session
include NetComConnectionPool.inc   ;Object for recycling of NetComConnections
include NetComEngine.inc           ;The main IOCP object, and IOCP message handler thread
include NetComSupervisor.inc       ;

; ==================================================================================================

endif

;  State	      Who is here	  What it means
;  -------------------------------------------
;  CLOSED       Both          No connection
;  LISTEN       Server        Waiting for SYN
;  SYN_SENT     Client        Sent SYN
;  SYN_RECEIVED Server        Got SYN
;  ESTABLISHED  Both          Connected
;  FIN_WAIT_1   Closing side  Sent FIN
;  FIN_WAIT_2   Closing side  FIN acked
;  CLOSE_WAIT   Other side    Received FIN
;  LAST_ACK     Other side    Sent FIN
;  TIME_WAIT    Active closer Cleanup
;  CLOSING      Both          Simultaneous FIN
;
;
;  Mapping WSA calls to TCP states:
;
;  1) Creating a socket
;  WSAStartup(...)
;  socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
;  TCP state: CLOSED
;  At this point the socket exists, but no connection.
;  ________________________________________
;  2) Server side
;  bind + listen -> LISTEN
;  bind(sock, ...);
;  listen(sock, backlog);
;  TCP state: LISTEN
;  The socket is now waiting for incoming connections.
;  ________________________________________
;  accept -> SYN_RECEIVED -> ESTABLISHED
;  clientSock = accept(listenSock, ...);
;  Behind the scenes:
;  Client sends SYN
;  Server enters SYN_RECEIVED
;  Server sends SYN-ACK
;  Client sends ACK
;  TCP state: ESTABLISHED
;  Your accept() only returns once the connection is ESTABLISHED.
;  ________________________________________
;  3) Client side
;  connect -> SYN_SENT -> ESTABLISHED
;  connect(sock, ...);
;  Behind the scenes: SYN_SENT (wait for SYN-ACK) (send ACK)
;  TCP state: ESTABLISHED
;  If successful, connect() returns and the socket is ready.
;  ________________________________________
;  4) Data transfer (ESTABLISHED)
;  send(sock, buf, len, 0);
;  recv(sock, buf, len, 0);
;  TCP state: ESTABLISHED
;  TCP handles segmentation, retransmission, ordering, flow control.
;  ________________________________________
;  5) Half-close with shutdown()
;  shutdown(sock, SD_SEND);   // same as SHUT_WR
;  TCP state: FIN_WAIT_1 -> FIN_WAIT_2
;  You told TCP: "I am done sending, but I can still receive."
;  Peer enters: CLOSE_WAIT
;  ________________________________________
;  6) Full close with closesocket()
;  closesocket(sock);
;  TCP transitions: FIN_WAIT_1 -> FIN_WAIT_2 -> TIME_WAIT -> CLOSED
;  Or on the peer: CLOSE_WAIT -> LAST_ACK -> CLOSED
;  ________________________________________
;  Abortive close (RST)
;  If you do:
;  setsockopt(sock, SOL_SOCKET, SO_LINGER, ...);
;  closesocket(sock);
;  TCP may send: RST
;  Which immediately destroys the connection (no TIME_WAIT).
;  This is an abort, not a graceful close.
;  ________________________________________
;  Error handling via WSA
;  Winsock reports TCP state problems as errors:
;  TCP condition	WSA error
;  Connection reset	WSAECONNRESET
;  Peer closed	recv() returns 0
;  Broken pipe	WSAECONNABORTED
;  Timeout	    WSAETIMEDOUT
;  Unreachable	WSAENETUNREACH
;  ________________________________________
;  Common state-related bugs in WSA apps
;  1) CLOSE_WAIT leak
;  You forgot to call closesocket() after peer closed.
;  Symptom: netstat shows tons of CLOSE_WAIT sockets
;  ________________________________________
;  2) TIME_WAIT exhaustion
;  You open/close thousands of short-lived connections.
;  Symptom: Cannot bind() - address already in use
;  ________________________________________
;  3) Sending after shutdown
;  shutdown(sock, SD_SEND);
;  send(sock, ...);   // -> WSAESHUTDOWN
;  ________________________________________
;  Summary
;  WSA Call	TCP State Effect
;  socket()	CLOSED
;  bind()+listen()	LISTEN
;  connect()	SYN_SENT -> ESTABLISHED
;  accept()	SYN_RECEIVED -> ESTABLISHED
;  send()/recv()	ESTABLISHED
;  shutdown(SD_SEND)	FIN_WAIT_1 -> FIN_WAIT_2
;  closesocket()	LAST_ACK / TIME_WAIT
;  SO_LINGER abort	RST



;  Client side                          Server side
;  -----------                          -----------
;
;  [CLOSED]                             [CLOSED]
;     ¦                                    ¦
;     ¦ socket()                           ¦ socket()
;     v                                    ¦ bind()
;  [CREATED]                               ¦ listen()
;     ¦                                    V
;     ¦ Associate with IOCP             [LISTENING]
;     v                                    ¦
;  [IOCP-BOUND]                            ¦ Associate listen socket with IOCP
;     ¦                                    V
;     ¦ ConnectEx()                     [ACCEPTING]
;     ¦  (pending)                         ¦
;     v                                    ¦ AcceptEx()
;  [CONNECTING]                            ¦  (pending)
;     ¦                                    V
;     ¦ IOCP completion                 [ACCEPTED]
;     ¦  (success)                         ¦
;     V                                    ¦ IOCP completion
;  [CONNECTED]                             ¦
;     ¦                                    ¦ setsockopt(SO_UPDATE_ACCEPT_CONTEXT)
;     ¦ Post WSARecv()                     V
;     ¦ Post WSASend()                  [CONNECTED]
;     V                                    ¦
;  [ACTIVE I/O]                            ¦ Post WSARecv()
;     ¦                                    ¦ Post WSASend()
;     ¦ shutdown(SD_SEND)                  V
;     V                                 [ACTIVE I/O]
;  [HALF-CLOSED]                           ¦
;     ¦                                    ¦ recv == 0
;     ¦ recv returns 0                     V
;     V                                 [PEER-CLOSED]
;  [CLOSING]                               ¦
;     ¦                                    ¦ closesocket()
;     ¦ closesocket()                      ¦
;     V                                    V
;  [CLOSED]                             [CLOSED]
;