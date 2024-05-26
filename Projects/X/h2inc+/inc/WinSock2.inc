;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\winsock2.h
;             Created on (UTC) 06/04/2024 06:16:03
;             Last modified on (UTC) 21/02/2024 18:15:28

ifndef _WINSOCK2API_
  _WINSOCK2API_ equ <>
  _WINSOCKAPI_ equ <>
  include winapifamily.inc
  if  not Defined(_WINSOCK_DEPRECATED_BY)
    if ((Defined(_WINSOCK_DEPRECATED_NO_WARNINGS) or Defined(BUILD_WINDOWS)) and  not Defined(_WINSOCK_DEPRECATE_WARNINGS)) or Defined(MIDL_PASS)
      _WINSOCK_DEPRECATED_BY macro replacement
        exitm <>
      endm
    else
      _WINSOCK_DEPRECATED_BY macro replacement
        exitm <__declspec(deprecated ("Use " replacement " instead or define _WINSOCK_DEPRECATED_NO_WARNINGS to disable deprecated API warnings"))>
      endm
    endif
  endif
  if  not Defined(_WINSOCK_DEPRECATED)
    if ((Defined(_WINSOCK_DEPRECATED_NO_WARNINGS) or Defined(BUILD_WINDOWS)) and  not Defined(_WINSOCK_DEPRECATE_WARNINGS)) or Defined(MIDL_PASS)
      _WINSOCK_DEPRECATED equ <>
    else
      _WINSOCK_DEPRECATED equ <__declspec(deprecated ("Define _WINSOCK_DEPRECATED_NO_WARNINGS to disable deprecated API warnings"))>
    endif
  endif
  ifndef INCL_WINSOCK_API_PROTOTYPES
    INCL_WINSOCK_API_PROTOTYPES equ 1
  endif
  ifndef INCL_WINSOCK_API_TYPEDEFS
    INCL_WINSOCK_API_TYPEDEFS equ 0
  endif
  ifndef _INC_WINDOWS
    include windows.inc
  endif
  if ( not Defined(_WIN64) and  not Defined(WIN32))
    include pshpack4.inc
    _NEED_POPPACK equ <>
  endif
  if  not Defined(MAKEWORD)
    MAKEWORD macro low_, high_
      exitm <((((low_)) or (((high_))) shl 8))>
    endm
  endif
  ifndef WINSOCK_VERSION
    WINSOCK_VERSION equ MAKEWORD(2, 2)
  endif
  ifndef WINSOCK_API_LINKAGE
    ifdef DECLSPEC_IMPORT
      WINSOCK_API_LINKAGE equ <DECLSPEC_IMPORT>
    else
      WINSOCK_API_LINKAGE equ <>
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
  u_char typedef BYTE
  u_short typedef WORD
  u_int typedef DWORD
  u_long typedef DWORD
  if (_WIN32_WINNT ge 0501h)
    u_int64 typedef QWORD
  endif
  include ws2def.inc
  SOCKET typedef UINT_PTR
  ifndef FD_SETSIZE
    FD_SETSIZE equ 64
  endif
  fd_set struct
    fd_count u_int ?
    fd_array SOCKET FD_SETSIZE dup (?)
  fd_set ends
  __WSAFDIsSet proto WIN_STD_CALL_CONV :SOCKET, :ptr fd_set
  FD_CLR macro fd, set
    exitm <do { u_int __i ; for (__i = 0 ; __i < ((fd_set FAR *) (set)) - fd_count ; __i +) { if (((fd_set FAR *) (set)) - fd_array [ __i ] == fd) { while (__i < ((fd_set FAR *) (set)) - fd_count - 1) { ((fd_set FAR *) (set)) - fd_array [ __i ] = ((fd_set FAR *) (set)) - fd_array [ __i + 1 ] ; __i + ; } ((fd_set FAR *) (set)) - fd_count - ; break ; } } } while (0)>
  endm
  FD_SET macro fd, set
    exitm <do { u_int __i ; for (__i = 0 ; __i < ((fd_set FAR *) (set)) - fd_count ; __i +) { if (((fd_set FAR *) (set)) - fd_array [ __i ] == (fd)) { break ; } } if (__i == ((fd_set FAR *) (set)) - fd_count) { if (((fd_set FAR *) (set)) - fd_count < FD_SETSIZE) { ((fd_set FAR *) (set)) - fd_array [ __i ] = (fd) ; ((fd_set FAR *) (set)) - fd_count + ; } } } while (0)>
  endm
  FD_ZERO macro set
    exitm <(((fd_set FAR *) (set)) - fd_count = 0)>
  endm
  FD_ISSET macro fd, set
    exitm <__WSAFDIsSet ((fd), (fd_set FAR *) (set))>
  endm
  timeval struct
    tv_sec SDWORD ?
    tv_usec SDWORD ?
  timeval ends
  timerisset macro tvp
    exitm <((tvp) - tv_sec or (tvp) - tv_usec)>
  endm
  timercmp macro tvp, uvp, cmp_
    exitm <((tvp) - tv_sec cmp_ (uvp) - tv_sec or (tvp) - tv_sec == (uvp) - tv_sec and (tvp) - tv_usec cmp_ (uvp) - tv_usec)>
  endm
  timerclear macro tvp
    exitm <(tvp) - tv_sec = (tvp) - tv_usec = 0>
  endm
  IOCPARM_MASK equ 7fh
  IOC_VOID equ 20000000h
  IOC_OUT equ 40000000h
  IOC_IN equ 80000000h
  IOC_INOUT equ <(IOC_IN or IOC_OUT)>
  _IO macro x, y
    exitm <(IOC_VOID or ((x) shl 8) or (y))>
  endm
  _IOR macro x, y, t
    exitm <(IOC_OUT or ((sizeof(t) and IOCPARM_MASK) shl 16) or ((x) shl 8) or (y))>
  endm
  _IOW macro x, y, t
    exitm <(IOC_IN or ((sizeof(t) and IOCPARM_MASK) shl 16) or ((x) shl 8) or (y))>
  endm
  FIONREAD equ _IOR('f', 127, u_long)
  FIONBIO equ _IOW('f', 126, u_long)
  FIOASYNC equ _IOW('f', 125, u_long)
  SIOCSHIWAT equ _IOW('s', 0, u_long)
  SIOCGHIWAT equ _IOR('s', 1, u_long)
  SIOCSLOWAT equ _IOW('s', 2, u_long)
  SIOCGLOWAT equ _IOR('s', 3, u_long)
  SIOCATMARK equ _IOR('s', 7, u_long)
  hostent struct
    h_name POINTER ?
    h_aliases POINTER ?
    h_addrtype SWORD ?
    h_length SWORD ?
    h_addr_list POINTER ?
    h_addr equ h_addr_list [ 0 ]
  hostent ends
  netent struct
    n_name POINTER ?
    n_aliases POINTER ?
    n_addrtype SWORD ?
    n_net u_long ?
  netent ends
  servent struct
    s_name POINTER ?
    s_aliases POINTER ?
    ifdef _WIN64
      s_proto POINTER ?
      s_port SWORD ?
    else
      s_port SWORD ?
      s_proto POINTER ?
    endif
  servent ends
  protoent struct
    p_name POINTER ?
    p_aliases POINTER ?
    p_proto SWORD ?
  protoent ends
  IPPORT_ECHO equ 7
  IPPORT_DISCARD equ 9
  IPPORT_SYSTAT equ 11
  IPPORT_DAYTIME equ 13
  IPPORT_NETSTAT equ 15
  IPPORT_FTP equ 21
  IPPORT_TELNET equ 23
  IPPORT_SMTP equ 25
  IPPORT_TIMESERVER equ 37
  IPPORT_NAMESERVER equ 42
  IPPORT_WHOIS equ 43
  IPPORT_MTP equ 57
  IPPORT_TFTP equ 69
  IPPORT_RJE equ 77
  IPPORT_FINGER equ 79
  IPPORT_TTYLINK equ 87
  IPPORT_SUPDUP equ 95
  IPPORT_EXECSERVER equ 512
  IPPORT_LOGINSERVER equ 513
  IPPORT_CMDSERVER equ 514
  IPPORT_EFSSERVER equ 520
  IPPORT_BIFFUDP equ 512
  IPPORT_WHOSERVER equ 513
  IPPORT_ROUTESERVER equ 520
  IPPORT_RESERVED equ 1024
  IMPLINK_IP equ 155
  IMPLINK_LOWEXPER equ 156
  IMPLINK_HIGHEXPER equ 158
  ifndef s_addr
    in_addr struct
      union S_un
        struct S_un_b
          s_b1 u_char ?
          s_b2 u_char ?
          s_b3 u_char ?
          s_b4 u_char ?
        ends
        struct S_un_w
          s_w1 u_short ?
          s_w2 u_short ?
        ends
        S_addr u_long ?
      ends
      s_addr equ <S_un.S_addr>
      s_host equ <S_un.S_un_b.s_b2>
      s_net equ <S_un.S_un_b.s_b1>
      s_imp equ <S_un.S_un_w.s_w2>
      s_impno equ <S_un.S_un_b.s_b4>
      s_lh equ <S_un.S_un_b.s_b3>
    in_addr ends
  endif
  ADDR_ANY equ <INADDR_ANY>
  WSADESCRIPTION_LEN equ 256
  WSASYS_STATUS_LEN equ 128
  WSADATA struct 4
    wVersion WORD ?
    wHighVersion WORD ?
    ifdef _WIN64
      iMaxSockets WORD ?
      iMaxUdpDg WORD ?
      lpVendorInfo POINTER ?
      szDescription SBYTE WSADESCRIPTION_LEN + 1 dup (?)
      szSystemStatus SBYTE WSASYS_STATUS_LEN + 1 dup (?)
    else
      szDescription SBYTE WSADESCRIPTION_LEN + 1 dup (?)
      szSystemStatus SBYTE WSASYS_STATUS_LEN + 1 dup (?)
      iMaxSockets WORD ?
      iMaxUdpDg WORD ?
      lpVendorInfo POINTER ?
    endif
  WSADATA ends
  WSAData typedef WSADATA
  LPWSADATA typedef ptr WSADATA
  INVALID_SOCKET equ (not 0)
  SOCKET_ERROR equ (- 1)
  FROM_PROTOCOL_INFO equ (- 1)
  SOCK_STREAM equ 1
  SOCK_DGRAM equ 2
  SOCK_RAW equ 3
  SOCK_RDM equ 4
  SOCK_SEQPACKET equ 5
  SO_DEBUG equ 0001h
  SO_ACCEPTCONN equ 0002h
  SO_REUSEADDR equ 0004h
  SO_KEEPALIVE equ 0008h
  SO_DONTROUTE equ 0010h
  SO_BROADCAST equ 0020h
  SO_USELOOPBACK equ 0040h
  SO_LINGER equ 0080h
  SO_OOBINLINE equ 0100h
  SO_DONTLINGER equ <(not SO_LINGER)>
  SO_EXCLUSIVEADDRUSE equ <((not SO_REUSEADDR))>
  SO_SNDBUF equ 1001h
  SO_RCVBUF equ 1002h
  SO_SNDLOWAT equ 1003h
  SO_RCVLOWAT equ 1004h
  SO_SNDTIMEO equ 1005h
  SO_RCVTIMEO equ 1006h
  SO_ERROR equ 1007h
  SO_TYPE equ 1008h
  SO_GROUP_ID equ 2001h
  SO_GROUP_PRIORITY equ 2002h
  SO_MAX_MSG_SIZE equ 2003h
  SO_PROTOCOL_INFOA equ 2004h
  SO_PROTOCOL_INFOW equ 2005h
  ifdef UNICODE
    SO_PROTOCOL_INFO equ <SO_PROTOCOL_INFOW>
  else
    SO_PROTOCOL_INFO equ <SO_PROTOCOL_INFOA>
  endif
  PVD_CONFIG equ 3001h
  SO_CONDITIONAL_ACCEPT equ 3002h
  sockproto struct
    sp_family u_short ?
    sp_protocol u_short ?
  sockproto ends
  PF_UNSPEC equ <AF_UNSPEC>
  PF_UNIX equ <AF_UNIX>
  PF_INET equ <AF_INET>
  PF_IMPLINK equ <AF_IMPLINK>
  PF_PUP equ <AF_PUP>
  PF_CHAOS equ <AF_CHAOS>
  PF_NS equ <AF_NS>
  PF_IPX equ <AF_IPX>
  PF_ISO equ <AF_ISO>
  PF_OSI equ <AF_OSI>
  PF_ECMA equ <AF_ECMA>
  PF_DATAKIT equ <AF_DATAKIT>
  PF_CCITT equ <AF_CCITT>
  PF_SNA equ <AF_SNA>
  PF_DECnet equ <AF_DECnet>
  PF_DLI equ <AF_DLI>
  PF_LAT equ <AF_LAT>
  PF_HYLINK equ <AF_HYLINK>
  PF_APPLETALK equ <AF_APPLETALK>
  PF_VOICEVIEW equ <AF_VOICEVIEW>
  PF_FIREFOX equ <AF_FIREFOX>
  PF_UNKNOWN1 equ <AF_UNKNOWN1>
  PF_BAN equ <AF_BAN>
  PF_ATM equ <AF_ATM>
  PF_INET6 equ <AF_INET6>
  if (_WIN32_WINNT ge 0600h)
    PF_BTH equ <AF_BTH>
  endif
  PF_MAX equ <AF_MAX>
  linger struct
    l_onoff u_short ?
    l_linger u_short ?
  linger ends
  SOL_SOCKET equ 0ffffh
  SOMAXCONN equ 7fffffffh
  SOMAXCONN_HINT macro b
    exitm <(- (b))>
  endm
  MSG_OOB equ 1h
  MSG_PEEK equ 2h
  MSG_DONTROUTE equ 4h
  if (_WIN32_WINNT ge 0502h)
    MSG_WAITALL equ 8h
  endif
  if (_WIN32_WINNT ge 0603h)
    MSG_PUSH_IMMEDIATE equ 20h
  endif
  MSG_PARTIAL equ 8000h
  MSG_INTERRUPT equ 10h
  MSG_MAXIOVLEN equ 16
  MAXGETHOSTSTRUCT equ 1024
  FD_READ_BIT equ 0
  FD_READ equ (1 shl FD_READ_BIT)
  FD_WRITE_BIT equ 1
  FD_WRITE equ (1 shl FD_WRITE_BIT)
  FD_OOB_BIT equ 2
  FD_OOB equ (1 shl FD_OOB_BIT)
  FD_ACCEPT_BIT equ 3
  FD_ACCEPT equ (1 shl FD_ACCEPT_BIT)
  FD_CONNECT_BIT equ 4
  FD_CONNECT equ (1 shl FD_CONNECT_BIT)
  FD_CLOSE_BIT equ 5
  FD_CLOSE equ (1 shl FD_CLOSE_BIT)
  FD_QOS_BIT equ 6
  FD_QOS equ (1 shl FD_QOS_BIT)
  FD_GROUP_QOS_BIT equ 7
  FD_GROUP_QOS equ (1 shl FD_GROUP_QOS_BIT)
  FD_ROUTING_INTERFACE_CHANGE_BIT equ 8
  FD_ROUTING_INTERFACE_CHANGE equ (1 shl FD_ROUTING_INTERFACE_CHANGE_BIT)
  FD_ADDRESS_LIST_CHANGE_BIT equ 9
  FD_ADDRESS_LIST_CHANGE equ (1 shl FD_ADDRESS_LIST_CHANGE_BIT)
  FD_MAX_EVENTS equ 10
  FD_ALL_EVENTS equ ((1 shl FD_MAX_EVENTS) - 1)
  ifndef WSABASEERR
    WSABASEERR equ 10000
    WSAEINTR equ (WSABASEERR + 4)
    WSAEBADF equ (WSABASEERR + 9)
    WSAEACCES equ (WSABASEERR + 13)
    WSAEFAULT equ (WSABASEERR + 14)
    WSAEINVAL equ (WSABASEERR + 22)
    WSAEMFILE equ (WSABASEERR + 24)
    WSAEWOULDBLOCK equ (WSABASEERR + 35)
    WSAEINPROGRESS equ (WSABASEERR + 36)
    WSAEALREADY equ (WSABASEERR + 37)
    WSAENOTSOCK equ (WSABASEERR + 38)
    WSAEDESTADDRREQ equ (WSABASEERR + 39)
    WSAEMSGSIZE equ (WSABASEERR + 40)
    WSAEPROTOTYPE equ (WSABASEERR + 41)
    WSAENOPROTOOPT equ (WSABASEERR + 42)
    WSAEPROTONOSUPPORT equ (WSABASEERR + 43)
    WSAESOCKTNOSUPPORT equ (WSABASEERR + 44)
    WSAEOPNOTSUPP equ (WSABASEERR + 45)
    WSAEPFNOSUPPORT equ (WSABASEERR + 46)
    WSAEAFNOSUPPORT equ (WSABASEERR + 47)
    WSAEADDRINUSE equ (WSABASEERR + 48)
    WSAEADDRNOTAVAIL equ (WSABASEERR + 49)
    WSAENETDOWN equ (WSABASEERR + 50)
    WSAENETUNREACH equ (WSABASEERR + 51)
    WSAENETRESET equ (WSABASEERR + 52)
    WSAECONNABORTED equ (WSABASEERR + 53)
    WSAECONNRESET equ (WSABASEERR + 54)
    WSAENOBUFS equ (WSABASEERR + 55)
    WSAEISCONN equ (WSABASEERR + 56)
    WSAENOTCONN equ (WSABASEERR + 57)
    WSAESHUTDOWN equ (WSABASEERR + 58)
    WSAETOOMANYREFS equ (WSABASEERR + 59)
    WSAETIMEDOUT equ (WSABASEERR + 60)
    WSAECONNREFUSED equ (WSABASEERR + 61)
    WSAELOOP equ (WSABASEERR + 62)
    WSAENAMETOOLONG equ (WSABASEERR + 63)
    WSAEHOSTDOWN equ (WSABASEERR + 64)
    WSAEHOSTUNREACH equ (WSABASEERR + 65)
    WSAENOTEMPTY equ (WSABASEERR + 66)
    WSAEPROCLIM equ (WSABASEERR + 67)
    WSAEUSERS equ (WSABASEERR + 68)
    WSAEDQUOT equ (WSABASEERR + 69)
    WSAESTALE equ (WSABASEERR + 70)
    WSAEREMOTE equ (WSABASEERR + 71)
    WSASYSNOTREADY equ (WSABASEERR + 91)
    WSAVERNOTSUPPORTED equ (WSABASEERR + 92)
    WSANOTINITIALISED equ (WSABASEERR + 93)
    WSAEDISCON equ (WSABASEERR + 101)
    WSAENOMORE equ (WSABASEERR + 102)
    WSAECANCELLED equ (WSABASEERR + 103)
    WSAEINVALIDPROCTABLE equ (WSABASEERR + 104)
    WSAEINVALIDPROVIDER equ (WSABASEERR + 105)
    WSAEPROVIDERFAILEDINIT equ (WSABASEERR + 106)
    WSASYSCALLFAILURE equ (WSABASEERR + 107)
    WSASERVICE_NOT_FOUND equ (WSABASEERR + 108)
    WSATYPE_NOT_FOUND equ (WSABASEERR + 109)
    WSA_E_NO_MORE equ (WSABASEERR + 110)
    WSA_E_CANCELLED equ (WSABASEERR + 111)
    WSAEREFUSED equ (WSABASEERR + 112)
    WSAHOST_NOT_FOUND equ (WSABASEERR + 1001)
    WSATRY_AGAIN equ (WSABASEERR + 1002)
    WSANO_RECOVERY equ (WSABASEERR + 1003)
    WSANO_DATA equ (WSABASEERR + 1004)
    WSA_QOS_RECEIVERS equ (WSABASEERR + 1005)
    WSA_QOS_SENDERS equ (WSABASEERR + 1006)
    WSA_QOS_NO_SENDERS equ (WSABASEERR + 1007)
    WSA_QOS_NO_RECEIVERS equ (WSABASEERR + 1008)
    WSA_QOS_REQUEST_CONFIRMED equ (WSABASEERR + 1009)
    WSA_QOS_ADMISSION_FAILURE equ (WSABASEERR + 1010)
    WSA_QOS_POLICY_FAILURE equ (WSABASEERR + 1011)
    WSA_QOS_BAD_STYLE equ (WSABASEERR + 1012)
    WSA_QOS_BAD_OBJECT equ (WSABASEERR + 1013)
    WSA_QOS_TRAFFIC_CTRL_ERROR equ (WSABASEERR + 1014)
    WSA_QOS_GENERIC_ERROR equ (WSABASEERR + 1015)
    WSA_QOS_ESERVICETYPE equ (WSABASEERR + 1016)
    WSA_QOS_EFLOWSPEC equ (WSABASEERR + 1017)
    WSA_QOS_EPROVSPECBUF equ (WSABASEERR + 1018)
    WSA_QOS_EFILTERSTYLE equ (WSABASEERR + 1019)
    WSA_QOS_EFILTERTYPE equ (WSABASEERR + 1020)
    WSA_QOS_EFILTERCOUNT equ (WSABASEERR + 1021)
    WSA_QOS_EOBJLENGTH equ (WSABASEERR + 1022)
    WSA_QOS_EFLOWCOUNT equ (WSABASEERR + 1023)
    WSA_QOS_EUNKOWNPSOBJ equ (WSABASEERR + 1024)
    WSA_QOS_EPOLICYOBJ equ (WSABASEERR + 1025)
    WSA_QOS_EFLOWDESC equ (WSABASEERR + 1026)
    WSA_QOS_EPSFLOWSPEC equ (WSABASEERR + 1027)
    WSA_QOS_EPSFILTERSPEC equ (WSABASEERR + 1028)
    WSA_QOS_ESDMODEOBJ equ (WSABASEERR + 1029)
    WSA_QOS_ESHAPERATEOBJ equ (WSABASEERR + 1030)
    WSA_QOS_RESERVED_PETYPE equ (WSABASEERR + 1031)
  endif
  h_errno equ <WSAGetLastError ()>
  HOST_NOT_FOUND equ <WSAHOST_NOT_FOUND>
  TRY_AGAIN equ <WSATRY_AGAIN>
  NO_RECOVERY equ <WSANO_RECOVERY>
  NO_DATA equ <WSANO_DATA>
  WSANO_ADDRESS equ <WSANO_DATA>
  NO_ADDRESS equ <WSANO_ADDRESS>
  if 0
    ;[...]
  endif
  ifdef WIN32
    WSAAPI equ <FAR PASCAL>
    WSAEVENT equ <HANDLE>
    LPWSAEVENT equ <LPHANDLE>
    WSAOVERLAPPED equ <OVERLAPPED>
    LPWSAOVERLAPPED typedef ptr _OVERLAPPED
    WSA_IO_PENDING equ <(ERROR_IO_PENDING)>
    WSA_IO_INCOMPLETE equ <(ERROR_IO_INCOMPLETE)>
    WSA_INVALID_HANDLE equ <(ERROR_INVALID_HANDLE)>
    WSA_INVALID_PARAMETER equ <(ERROR_INVALID_PARAMETER)>
    WSA_NOT_ENOUGH_MEMORY equ <(ERROR_NOT_ENOUGH_MEMORY)>
    WSA_OPERATION_ABORTED equ <(ERROR_OPERATION_ABORTED)>
    WSA_INVALID_EVENT equ <((WSAEVENT) NULL)>
    WSA_MAXIMUM_WAIT_EVENTS equ <(MAXIMUM_WAIT_OBJECTS)>
    WSA_WAIT_FAILED equ <(WAIT_FAILED)>
    WSA_WAIT_EVENT_0 equ <(WAIT_OBJECT_0)>
    WSA_WAIT_IO_COMPLETION equ <(WAIT_IO_COMPLETION)>
    WSA_WAIT_TIMEOUT equ <(WAIT_TIMEOUT)>
    WSA_INFINITE equ <(INFINITE)>
  else
    WSAAPI equ <FAR PASCAL>
    WSAEVENT typedef DWORD
    LPWSAEVENT typedef ptr DWORD
    WSAOVERLAPPED struct
      Internal DWORD ?
      InternalHigh DWORD ?
      Offset_ DWORD ?
      OffsetHigh DWORD ?
      hEvent WSAEVENT ?
    WSAOVERLAPPED ends
    _WSAOVERLAPPED typedef WSAOVERLAPPED
    LPWSAOVERLAPPED typedef ptr WSAOVERLAPPED
    WSA_IO_PENDING equ <(WSAEWOULDBLOCK)>
    WSA_IO_INCOMPLETE equ <(WSAEWOULDBLOCK)>
    WSA_INVALID_HANDLE equ <(WSAENOTSOCK)>
    WSA_INVALID_PARAMETER equ <(WSAEINVAL)>
    WSA_NOT_ENOUGH_MEMORY equ <(WSAENOBUFS)>
    WSA_OPERATION_ABORTED equ <(WSAEINTR)>
    WSA_INVALID_EVENT equ <((WSAEVENT) NULL)>
    WSA_MAXIMUM_WAIT_EVENTS equ <(MAXIMUM_WAIT_OBJECTS)>
    WSA_WAIT_FAILED equ (- 1)
    WSA_WAIT_EVENT_0 equ (0)
    WSA_WAIT_TIMEOUT equ (102h)
    WSA_INFINITE equ (- 1)
  endif
  LPQOS equ <LPVOID>
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    include qos.inc
    QOS struct
      SendingFlowspec FLOWSPEC <>
      ReceivingFlowspec FLOWSPEC <>
      ProviderSpecific WSABUF <>
    QOS ends
    _QualityOfService typedef QOS
    LPQOS typedef ptr QOS
  endif
  CF_ACCEPT equ 0000h
  CF_REJECT equ 0001h
  CF_DEFER equ 0002h
  SD_RECEIVE equ 00h
  SD_SEND equ 01h
  SD_BOTH equ 02h
  GROUP_ typedef DWORD
  SG_UNCONSTRAINED_GROUP equ 01h
  SG_CONSTRAINED_GROUP equ 02h
  WSANETWORKEVENTS struct
    lNetworkEvents SDWORD ?
    iErrorCode SDWORD FD_MAX_EVENTS dup (?)
  WSANETWORKEVENTS ends
  _WSANETWORKEVENTS typedef WSANETWORKEVENTS
  LPWSANETWORKEVENTS typedef ptr WSANETWORKEVENTS
  ifndef GUID_DEFINED
    include guiddef.inc
  endif
  MAX_PROTOCOL_CHAIN equ 7
  BASE_PROTOCOL equ 1
  LAYERED_PROTOCOL equ 0
  WSAPROTOCOLCHAIN struct
    ChainLen SDWORD ?
    ChainEntries DWORD MAX_PROTOCOL_CHAIN dup (?)
  WSAPROTOCOLCHAIN ends
  _WSAPROTOCOLCHAIN typedef WSAPROTOCOLCHAIN
  LPWSAPROTOCOLCHAIN typedef ptr WSAPROTOCOLCHAIN
  WSAPROTOCOL_LEN equ 255
  WSAPROTOCOL_INFOA struct
    dwServiceFlags1 DWORD ?
    dwServiceFlags2 DWORD ?
    dwServiceFlags3 DWORD ?
    dwServiceFlags4 DWORD ?
    dwProviderFlags DWORD ?
    ProviderId GUID <>
    dwCatalogEntryId DWORD ?
    ProtocolChain WSAPROTOCOLCHAIN <>
    iVersion SDWORD ?
    iAddressFamily SDWORD ?
    iMaxSockAddr SDWORD ?
    iMinSockAddr SDWORD ?
    iSocketType SDWORD ?
    iProtocol SDWORD ?
    iProtocolMaxOffset SDWORD ?
    iNetworkByteOrder SDWORD ?
    iSecurityScheme SDWORD ?
    dwMessageSize DWORD ?
    dwProviderReserved DWORD ?
    szProtocol CHAR WSAPROTOCOL_LEN + 1 dup (?)
  WSAPROTOCOL_INFOA ends
  _WSAPROTOCOL_INFOA typedef WSAPROTOCOL_INFOA
  LPWSAPROTOCOL_INFOA typedef ptr WSAPROTOCOL_INFOA
  WSAPROTOCOL_INFOW struct
    dwServiceFlags1 DWORD ?
    dwServiceFlags2 DWORD ?
    dwServiceFlags3 DWORD ?
    dwServiceFlags4 DWORD ?
    dwProviderFlags DWORD ?
    ProviderId GUID <>
    dwCatalogEntryId DWORD ?
    ProtocolChain WSAPROTOCOLCHAIN <>
    iVersion SDWORD ?
    iAddressFamily SDWORD ?
    iMaxSockAddr SDWORD ?
    iMinSockAddr SDWORD ?
    iSocketType SDWORD ?
    iProtocol SDWORD ?
    iProtocolMaxOffset SDWORD ?
    iNetworkByteOrder SDWORD ?
    iSecurityScheme SDWORD ?
    dwMessageSize DWORD ?
    dwProviderReserved DWORD ?
    szProtocol WCHAR WSAPROTOCOL_LEN + 1 dup (?)
  WSAPROTOCOL_INFOW ends
  _WSAPROTOCOL_INFOW typedef WSAPROTOCOL_INFOW
  LPWSAPROTOCOL_INFOW typedef ptr WSAPROTOCOL_INFOW
  ifdef UNICODE
    WSAPROTOCOL_INFO typedef WSAPROTOCOL_INFOW
    LPWSAPROTOCOL_INFO typedef LPWSAPROTOCOL_INFOW
  else
    WSAPROTOCOL_INFO typedef WSAPROTOCOL_INFOA
    LPWSAPROTOCOL_INFO typedef LPWSAPROTOCOL_INFOA
  endif
  PFL_MULTIPLE_PROTO_ENTRIES equ 00000001h
  PFL_RECOMMENDED_PROTO_ENTRY equ 00000002h
  PFL_HIDDEN equ 00000004h
  PFL_MATCHES_PROTOCOL_ZERO equ 00000008h
  PFL_NETWORKDIRECT_PROVIDER equ 00000010h
  XP1_CONNECTIONLESS equ 00000001h
  XP1_GUARANTEED_DELIVERY equ 00000002h
  XP1_GUARANTEED_ORDER equ 00000004h
  XP1_MESSAGE_ORIENTED equ 00000008h
  XP1_PSEUDO_STREAM equ 00000010h
  XP1_GRACEFUL_CLOSE equ 00000020h
  XP1_EXPEDITED_DATA equ 00000040h
  XP1_CONNECT_DATA equ 00000080h
  XP1_DISCONNECT_DATA equ 00000100h
  XP1_SUPPORT_BROADCAST equ 00000200h
  XP1_SUPPORT_MULTIPOINT equ 00000400h
  XP1_MULTIPOINT_CONTROL_PLANE equ 00000800h
  XP1_MULTIPOINT_DATA_PLANE equ 00001000h
  XP1_QOS_SUPPORTED equ 00002000h
  XP1_INTERRUPT equ 00004000h
  XP1_UNI_SEND equ 00008000h
  XP1_UNI_RECV equ 00010000h
  XP1_IFS_HANDLES equ 00020000h
  XP1_PARTIAL_MESSAGE equ 00040000h
  XP1_SAN_SUPPORT_SDP equ 00080000h
  BIGENDIAN equ 0000h
  LITTLEENDIAN equ 0001h
  SECURITY_PROTOCOL_NONE equ 0000h
  JL_SENDER_ONLY equ 01h
  JL_RECEIVER_ONLY equ 02h
  JL_BOTH equ 04h
  WSA_FLAG_OVERLAPPED equ 01h
  WSA_FLAG_MULTIPOINT_C_ROOT equ 02h
  WSA_FLAG_MULTIPOINT_C_LEAF equ 04h
  WSA_FLAG_MULTIPOINT_D_ROOT equ 08h
  WSA_FLAG_MULTIPOINT_D_LEAF equ 10h
  WSA_FLAG_ACCESS_SYSTEM_SECURITY equ 40h
  WSA_FLAG_NO_HANDLE_INHERIT equ 80h
  WSA_FLAG_REGISTERED_IO equ 100h
  TYPE_LPCONDITIONPROC typedef proto WIN_STD_CALL_CONV :LPWSABUF, :LPWSABUF, :LPQOS, :LPQOS, :LPWSABUF, :LPWSABUF, :ptr GROUP_, :DWORD_PTR
  LPCONDITIONPROC typedef ptr TYPE_LPCONDITIONPROC

  TYPE_LPWSAOVERLAPPED_COMPLETION_ROUTINE typedef proto WIN_STD_CALL_CONV :DWORD, :DWORD, :LPWSAOVERLAPPED, :DWORD
  LPWSAOVERLAPPED_COMPLETION_ROUTINE typedef ptr TYPE_LPWSAOVERLAPPED_COMPLETION_ROUTINE

  if (_WIN32_WINNT ge 0501h)
    SIO_NSP_NOTIFY_CHANGE equ _WSAIOW(IOC_WS2, 25)
    WSACOMPLETIONTYPE typedef SDWORD
    NSP_NOTIFY_IMMEDIATELY equ 0
    NSP_NOTIFY_HWND equ 1
    NSP_NOTIFY_EVENT equ 2
    NSP_NOTIFY_PORT equ 3
    NSP_NOTIFY_APC equ 4
    _WSACOMPLETIONTYPE typedef WSACOMPLETIONTYPE
    PWSACOMPLETIONTYPE typedef ptr WSACOMPLETIONTYPE
    LPWSACOMPLETIONTYPE typedef ptr WSACOMPLETIONTYPE
    WSACOMPLETION struct
      Type_ WSACOMPLETIONTYPE ?
      union Parameters
        struct WindowMessage
          hWnd HWND ?
          uMsg UINT ?
          context WPARAM ?
        ends
        struct Event_
          lpOverlapped LPWSAOVERLAPPED ?
        ends
        struct Apc
          lpOverlapped LPWSAOVERLAPPED ?
          lpfnCompletionProc LPWSAOVERLAPPED_COMPLETION_ROUTINE ?
        ends
        struct Port
          lpOverlapped LPWSAOVERLAPPED ?
          hPort HANDLE ?
          Key ULONG_PTR ?
        ends
      ends
    WSACOMPLETION ends
    _WSACOMPLETION typedef WSACOMPLETION
    PWSACOMPLETION typedef ptr WSACOMPLETION
    LPWSACOMPLETION typedef ptr WSACOMPLETION
  endif
  TH_NETDEV equ 00000001h
  TH_TAPI equ 00000002h
  ifndef _tagBLOB_DEFINED
    _tagBLOB_DEFINED equ <>
    _BLOB_DEFINED equ <>
    _LPBLOB_DEFINED equ <>
    BLOB struct
      cbSize ULONG ?
      ifdef MIDL_PASS
        ;[...]
      else
        pBlobData POINTER ?
      endif
    BLOB ends
    _BLOB typedef BLOB
    LPBLOB typedef ptr BLOB
  endif
  SERVICE_MULTIPLE equ (00000001h)
  NS_ALL equ (0)
  NS_SAP equ (1)
  NS_NDS equ (2)
  NS_PEER_BROWSE equ (3)
  NS_SLP equ (5)
  NS_DHCP equ (6)
  NS_TCPIP_LOCAL equ (10)
  NS_TCPIP_HOSTS equ (11)
  NS_DNS equ (12)
  NS_NETBT equ (13)
  NS_WINS equ (14)
  if (_WIN32_WINNT ge 0501h)
    NS_NLA equ (15)
  endif
  if (_WIN32_WINNT ge 0600h)
    NS_BTH equ (16)
  endif
  NS_NBP equ (20)
  NS_MS equ (30)
  NS_STDA equ (31)
  NS_NTDS equ (32)
  if (_WIN32_WINNT ge 0600h)
    NS_EMAIL equ (37)
    NS_PNRPNAME equ (38)
    NS_PNRPCLOUD equ (39)
  endif
  NS_X500 equ (40)
  NS_NIS equ (41)
  NS_NISPLUS equ (42)
  NS_WRQ equ (50)
  NS_NETDES equ (60)
  NS_ALL equ (0)
  NS_SAP equ (1)
  NS_NDS equ (2)
  NS_PEER_BROWSE equ (3)
  NS_SLP equ (5)
  NS_DHCP equ (6)
  NS_TCPIP_LOCAL equ (10)
  NS_TCPIP_HOSTS equ (11)
  NS_DNS equ (12)
  NS_NETBT equ (13)
  NS_WINS equ (14)
  if (_WIN32_WINNT ge 0501h)
    NS_NLA equ (15)
  endif
  if (_WIN32_WINNT ge 0600h)
    NS_BTH equ (16)
  endif
  NS_LOCALNAME equ (19)
  NS_NBP equ (20)
  NS_MS equ (30)
  NS_STDA equ (31)
  NS_NTDS equ (32)
  if (_WIN32_WINNT ge 0600h)
    NS_EMAIL equ (37)
    NS_PNRPNAME equ (38)
    NS_PNRPCLOUD equ (39)
  endif
  NS_X500 equ (40)
  NS_NIS equ (41)
  NS_NISPLUS equ (42)
  NS_WRQ equ (50)
  NS_NETDES equ (60)
  RES_UNUSED_1 equ (00000001h)
  RES_FLUSH_CACHE equ (00000002h)
  ifndef RES_SERVICE
    RES_SERVICE equ (00000004h)
  endif
  SERVICE_TYPE_VALUE_IPXPORTA equ <"IpxSocket">
  SERVICE_TYPE_VALUE_IPXPORTW equ <L("IpxSocket")>
  SERVICE_TYPE_VALUE_SAPIDA equ <"SapId">
  SERVICE_TYPE_VALUE_SAPIDW equ <L("SapId")>
  SERVICE_TYPE_VALUE_TCPPORTA equ <"TcpPort">
  SERVICE_TYPE_VALUE_TCPPORTW equ <L("TcpPort")>
  SERVICE_TYPE_VALUE_UDPPORTA equ <"UdpPort">
  SERVICE_TYPE_VALUE_UDPPORTW equ <L("UdpPort")>
  SERVICE_TYPE_VALUE_OBJECTIDA equ <"ObjectId">
  SERVICE_TYPE_VALUE_OBJECTIDW equ <L("ObjectId")>
  ifdef UNICODE
    SERVICE_TYPE_VALUE_SAPID equ <SERVICE_TYPE_VALUE_SAPIDW>
    SERVICE_TYPE_VALUE_TCPPORT equ <SERVICE_TYPE_VALUE_TCPPORTW>
    SERVICE_TYPE_VALUE_UDPPORT equ <SERVICE_TYPE_VALUE_UDPPORTW>
    SERVICE_TYPE_VALUE_OBJECTID equ <SERVICE_TYPE_VALUE_OBJECTIDW>
  else
    SERVICE_TYPE_VALUE_SAPID equ <SERVICE_TYPE_VALUE_SAPIDA>
    SERVICE_TYPE_VALUE_TCPPORT equ <SERVICE_TYPE_VALUE_TCPPORTA>
    SERVICE_TYPE_VALUE_UDPPORT equ <SERVICE_TYPE_VALUE_UDPPORTA>
    SERVICE_TYPE_VALUE_OBJECTID equ <SERVICE_TYPE_VALUE_OBJECTIDA>
  endif
  AFPROTOCOLS struct
    iAddressFamily INT_ ?
    iProtocol INT_ ?
  AFPROTOCOLS ends
  _AFPROTOCOLS typedef AFPROTOCOLS
  PAFPROTOCOLS typedef ptr AFPROTOCOLS
  LPAFPROTOCOLS typedef ptr AFPROTOCOLS
  WSAECOMPARATOR typedef SDWORD
  COMP_EQUAL equ 0
  COMP_NOTLESS equ 1
  _WSAEcomparator typedef WSAECOMPARATOR
  PWSAECOMPARATOR typedef ptr WSAECOMPARATOR
  LPWSAECOMPARATOR typedef ptr WSAECOMPARATOR
  WSAVERSION struct
    dwVersion DWORD ?
    ecHow WSAECOMPARATOR ?
  WSAVERSION ends
  _WSAVersion typedef WSAVERSION
  PWSAVERSION typedef ptr WSAVERSION
  LPWSAVERSION typedef ptr WSAVERSION
  WSAQUERYSETA struct
    dwSize DWORD ?
    lpszServiceInstanceName LPSTR ?
    lpServiceClassId LPGUID ?
    lpVersion LPWSAVERSION ?
    lpszComment LPSTR ?
    dwNameSpace DWORD ?
    lpNSProviderId LPGUID ?
    lpszContext LPSTR ?
    dwNumberOfProtocols DWORD ?
    lpafpProtocols LPAFPROTOCOLS ?
    lpszQueryString LPSTR ?
    dwNumberOfCsAddrs DWORD ?
    lpcsaBuffer LPCSADDR_INFO ?
    dwOutputFlags DWORD ?
    lpBlob LPBLOB ?
  WSAQUERYSETA ends
  _WSAQuerySetA typedef WSAQUERYSETA
  PWSAQUERYSETA typedef ptr WSAQUERYSETA
  LPWSAQUERYSETA typedef ptr WSAQUERYSETA
  WSAQUERYSETW struct
    dwSize DWORD ?
    lpszServiceInstanceName LPWSTR ?
    lpServiceClassId LPGUID ?
    lpVersion LPWSAVERSION ?
    lpszComment LPWSTR ?
    dwNameSpace DWORD ?
    lpNSProviderId LPGUID ?
    lpszContext LPWSTR ?
    dwNumberOfProtocols DWORD ?
    lpafpProtocols LPAFPROTOCOLS ?
    lpszQueryString LPWSTR ?
    dwNumberOfCsAddrs DWORD ?
    lpcsaBuffer LPCSADDR_INFO ?
    dwOutputFlags DWORD ?
    lpBlob LPBLOB ?
  WSAQUERYSETW ends
  _WSAQuerySetW typedef WSAQUERYSETW
  PWSAQUERYSETW typedef ptr WSAQUERYSETW
  LPWSAQUERYSETW typedef ptr WSAQUERYSETW
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    WSAQUERYSET2A struct
      dwSize DWORD ?
      lpszServiceInstanceName LPSTR ?
      lpVersion LPWSAVERSION ?
      lpszComment LPSTR ?
      dwNameSpace DWORD ?
      lpNSProviderId LPGUID ?
      lpszContext LPSTR ?
      dwNumberOfProtocols DWORD ?
      lpafpProtocols LPAFPROTOCOLS ?
      lpszQueryString LPSTR ?
      dwNumberOfCsAddrs DWORD ?
      lpcsaBuffer LPCSADDR_INFO ?
      dwOutputFlags DWORD ?
      lpBlob LPBLOB ?
    WSAQUERYSET2A ends
    _WSAQuerySet2A typedef WSAQUERYSET2A
    PWSAQUERYSET2A typedef ptr WSAQUERYSET2A
    LPWSAQUERYSET2A typedef ptr WSAQUERYSET2A
    WSAQUERYSET2W struct
      dwSize DWORD ?
      lpszServiceInstanceName LPWSTR ?
      lpVersion LPWSAVERSION ?
      lpszComment LPWSTR ?
      dwNameSpace DWORD ?
      lpNSProviderId LPGUID ?
      lpszContext LPWSTR ?
      dwNumberOfProtocols DWORD ?
      lpafpProtocols LPAFPROTOCOLS ?
      lpszQueryString LPWSTR ?
      dwNumberOfCsAddrs DWORD ?
      lpcsaBuffer LPCSADDR_INFO ?
      dwOutputFlags DWORD ?
      lpBlob LPBLOB ?
    WSAQUERYSET2W ends
    _WSAQuerySet2W typedef WSAQUERYSET2W
    PWSAQUERYSET2W typedef ptr WSAQUERYSET2W
    LPWSAQUERYSET2W typedef ptr WSAQUERYSET2W
    ifdef UNICODE
      WSAQUERYSET typedef WSAQUERYSETW
      PWSAQUERYSET typedef PWSAQUERYSETW
      LPWSAQUERYSET typedef LPWSAQUERYSETW
      WSAQUERYSET2 typedef WSAQUERYSET2W
      PWSAQUERYSET2 typedef PWSAQUERYSET2W
      LPWSAQUERYSET2 typedef LPWSAQUERYSET2W
    else
      WSAQUERYSET typedef WSAQUERYSETA
      PWSAQUERYSET typedef PWSAQUERYSETA
      LPWSAQUERYSET typedef LPWSAQUERYSETA
      WSAQUERYSET2 typedef WSAQUERYSET2A
      PWSAQUERYSET2 typedef PWSAQUERYSET2A
      LPWSAQUERYSET2 typedef LPWSAQUERYSET2A
    endif
  endif
  LUP_DEEP equ 00000001h
  LUP_CONTAINERS equ 00000002h
  LUP_NOCONTAINERS equ 00000004h
  LUP_NEAREST equ 00000008h
  LUP_RETURN_NAME equ 00000010h
  LUP_RETURN_TYPE equ 00000020h
  LUP_RETURN_VERSION equ 00000040h
  LUP_RETURN_COMMENT equ 00000080h
  LUP_RETURN_ADDR equ 00000100h
  LUP_RETURN_BLOB equ 00000200h
  LUP_RETURN_ALIASES equ 00000400h
  LUP_RETURN_QUERY_STRING equ 00000800h
  LUP_RETURN_ALL equ 00000FF0h
  LUP_RES_SERVICE equ 00008000h
  LUP_FLUSHCACHE equ 00001000h
  LUP_FLUSHPREVIOUS equ 00002000h
  LUP_NON_AUTHORITATIVE equ 00004000h
  LUP_SECURE equ 00008000h
  LUP_RETURN_PREFERRED_NAMES equ 00010000h
  LUP_DNS_ONLY equ 00020000h
  LUP_RETURN_RESPONSE_FLAGS equ 00040000h
  LUP_ADDRCONFIG equ 00100000h
  LUP_DUAL_ADDR equ 00200000h
  LUP_FILESERVER equ 00400000h
  LUP_DISABLE_IDN_ENCODING equ 00800000h
  LUP_API_ANSI equ 01000000h
  LUP_EXTENDED_QUERYSET equ 02000000h
  LUP_SECURE_WITH_FALLBACK equ 04000000h
  LUP_EXCLUSIVE_CUSTOM_SERVERS equ 08000000h
  LUP_REQUIRE_SECURE equ 10000000h
  LUP_RETURN_TTL equ 20000000h
  LUP_FORCE_CLEAR_TEXT equ 40000000h
  LUP_RESOLUTION_HANDLE equ 80000000h
  RESULT_IS_ALIAS equ 0001h
  if (_WIN32_WINNT ge 0501h)
    RESULT_IS_ADDED equ 0010h
    RESULT_IS_CHANGED equ 0020h
    RESULT_IS_DELETED equ 0040h
  endif
  WSAESETSERVICEOP typedef SDWORD
  RNRSERVICE_REGISTER equ 0
  RNRSERVICE_DEREGISTER equ 1
  RNRSERVICE_DELETE equ 2
  _WSAESETSERVICEOP typedef WSAESETSERVICEOP
  PWSAESETSERVICEOP typedef ptr WSAESETSERVICEOP
  LPWSAESETSERVICEOP typedef ptr WSAESETSERVICEOP
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    WSANSCLASSINFOA struct
      lpszName LPSTR ?
      dwNameSpace DWORD ?
      dwValueType DWORD ?
      dwValueSize DWORD ?
      lpValue LPVOID ?
    WSANSCLASSINFOA ends
    _WSANSClassInfoA typedef WSANSCLASSINFOA
    PWSANSCLASSINFOA typedef ptr WSANSCLASSINFOA
    LPWSANSCLASSINFOA typedef ptr WSANSCLASSINFOA
  endif
  WSANSCLASSINFOW struct
    lpszName LPWSTR ?
    dwNameSpace DWORD ?
    dwValueType DWORD ?
    dwValueSize DWORD ?
    lpValue LPVOID ?
  WSANSCLASSINFOW ends
  _WSANSClassInfoW typedef WSANSCLASSINFOW
  PWSANSCLASSINFOW typedef ptr WSANSCLASSINFOW
  LPWSANSCLASSINFOW typedef ptr WSANSCLASSINFOW
  ifdef UNICODE
    WSANSCLASSINFO typedef WSANSCLASSINFOW
    PWSANSCLASSINFO typedef PWSANSCLASSINFOW
    LPWSANSCLASSINFO typedef LPWSANSCLASSINFOW
  else
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      WSANSCLASSINFO typedef WSANSCLASSINFOA
      PWSANSCLASSINFO typedef PWSANSCLASSINFOA
      LPWSANSCLASSINFO typedef LPWSANSCLASSINFOA
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    WSASERVICECLASSINFOA struct
      lpServiceClassId LPGUID ?
      lpszServiceClassName LPSTR ?
      dwCount DWORD ?
      lpClassInfos LPWSANSCLASSINFOA ?
    WSASERVICECLASSINFOA ends
    _WSAServiceClassInfoA typedef WSASERVICECLASSINFOA
    PWSASERVICECLASSINFOA typedef ptr WSASERVICECLASSINFOA
    LPWSASERVICECLASSINFOA typedef ptr WSASERVICECLASSINFOA
  endif
  WSASERVICECLASSINFOW struct
    lpServiceClassId LPGUID ?
    lpszServiceClassName LPWSTR ?
    dwCount DWORD ?
    lpClassInfos LPWSANSCLASSINFOW ?
  WSASERVICECLASSINFOW ends
  _WSAServiceClassInfoW typedef WSASERVICECLASSINFOW
  PWSASERVICECLASSINFOW typedef ptr WSASERVICECLASSINFOW
  LPWSASERVICECLASSINFOW typedef ptr WSASERVICECLASSINFOW
  ifdef UNICODE
    WSASERVICECLASSINFO typedef WSASERVICECLASSINFOW
    PWSASERVICECLASSINFO typedef PWSASERVICECLASSINFOW
    LPWSASERVICECLASSINFO typedef LPWSASERVICECLASSINFOW
  else
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      WSASERVICECLASSINFO typedef WSASERVICECLASSINFOA
      PWSASERVICECLASSINFO typedef PWSASERVICECLASSINFOA
      LPWSASERVICECLASSINFO typedef LPWSASERVICECLASSINFOA
    endif
  endif
  WSANAMESPACE_INFOA struct
    NSProviderId GUID <>
    dwNameSpace DWORD ?
    fActive BOOL ?
    dwVersion DWORD ?
    lpszIdentifier LPSTR ?
  WSANAMESPACE_INFOA ends
  _WSANAMESPACE_INFOA typedef WSANAMESPACE_INFOA
  PWSANAMESPACE_INFOA typedef ptr WSANAMESPACE_INFOA
  LPWSANAMESPACE_INFOA typedef ptr WSANAMESPACE_INFOA
  WSANAMESPACE_INFOW struct
    NSProviderId GUID <>
    dwNameSpace DWORD ?
    fActive BOOL ?
    dwVersion DWORD ?
    lpszIdentifier LPWSTR ?
  WSANAMESPACE_INFOW ends
  _WSANAMESPACE_INFOW typedef WSANAMESPACE_INFOW
  PWSANAMESPACE_INFOW typedef ptr WSANAMESPACE_INFOW
  LPWSANAMESPACE_INFOW typedef ptr WSANAMESPACE_INFOW
  WSANAMESPACE_INFOEXA struct
    NSProviderId GUID <>
    dwNameSpace DWORD ?
    fActive BOOL ?
    dwVersion DWORD ?
    lpszIdentifier LPSTR ?
    ProviderSpecific BLOB <>
  WSANAMESPACE_INFOEXA ends
  _WSANAMESPACE_INFOEXA typedef WSANAMESPACE_INFOEXA
  PWSANAMESPACE_INFOEXA typedef ptr WSANAMESPACE_INFOEXA
  LPWSANAMESPACE_INFOEXA typedef ptr WSANAMESPACE_INFOEXA
  WSANAMESPACE_INFOEXW struct
    NSProviderId GUID <>
    dwNameSpace DWORD ?
    fActive BOOL ?
    dwVersion DWORD ?
    lpszIdentifier LPWSTR ?
    ProviderSpecific BLOB <>
  WSANAMESPACE_INFOEXW ends
  _WSANAMESPACE_INFOEXW typedef WSANAMESPACE_INFOEXW
  PWSANAMESPACE_INFOEXW typedef ptr WSANAMESPACE_INFOEXW
  LPWSANAMESPACE_INFOEXW typedef ptr WSANAMESPACE_INFOEXW
  ifdef UNICODE
    WSANAMESPACE_INFO typedef WSANAMESPACE_INFOW
    PWSANAMESPACE_INFO typedef PWSANAMESPACE_INFOW
    LPWSANAMESPACE_INFO typedef LPWSANAMESPACE_INFOW
    WSANAMESPACE_INFOEX typedef WSANAMESPACE_INFOEXW
    PWSANAMESPACE_INFOEX typedef PWSANAMESPACE_INFOEXW
    LPWSANAMESPACE_INFOEX typedef LPWSANAMESPACE_INFOEXW
  else
    WSANAMESPACE_INFO typedef WSANAMESPACE_INFOA
    PWSANAMESPACE_INFO typedef PWSANAMESPACE_INFOA
    LPWSANAMESPACE_INFO typedef LPWSANAMESPACE_INFOA
    WSANAMESPACE_INFOEX typedef WSANAMESPACE_INFOEXA
    PWSANAMESPACE_INFOEX typedef PWSANAMESPACE_INFOEXA
    LPWSANAMESPACE_INFOEX typedef LPWSANAMESPACE_INFOEXA
  endif
  if (_WIN32_WINNT ge 0600h)
    POLLRDNORM equ 0100h
    POLLRDBAND equ 0200h
    POLLIN equ <(POLLRDNORM or POLLRDBAND)>
    POLLPRI equ 0400h
    POLLWRNORM equ 0010h
    POLLOUT equ <(POLLWRNORM)>
    POLLWRBAND equ 0020h
    POLLERR equ 0001h
    POLLHUP equ 0002h
    POLLNVAL equ 0004h
    WSAPOLLFD struct
      fd SOCKET ?
      events SHORT_ ?
      revents SHORT_ ?
    WSAPOLLFD ends
    pollfd typedef WSAPOLLFD
    PWSAPOLLFD typedef ptr WSAPOLLFD
    LPWSAPOLLFD typedef ptr WSAPOLLFD
  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, accept, WIN_STD_CALL_CONV,, <:SOCKET, :ptr sockaddr, :ptr SDWORD>, 12
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_ACCEPT typedef proto WIN_STD_CALL_CONV :SOCKET, :ptr sockaddr, :ptr SDWORD
    LPFN_ACCEPT typedef ptr TYPE_LPFN_ACCEPT

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, bind, WIN_STD_CALL_CONV,, <:SOCKET, :ptr sockaddr, :SDWORD>, 12
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_BIND typedef proto WIN_STD_CALL_CONV :SOCKET, :ptr sockaddr, :SDWORD
    LPFN_BIND typedef ptr TYPE_LPFN_BIND

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, closesocket, WIN_STD_CALL_CONV,, <:SOCKET>, 4
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_CLOSESOCKET typedef proto WIN_STD_CALL_CONV :SOCKET
    LPFN_CLOSESOCKET typedef ptr TYPE_LPFN_CLOSESOCKET

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, connect, WIN_STD_CALL_CONV,, <:SOCKET, :ptr sockaddr, :SDWORD>, 12
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_CONNECT typedef proto WIN_STD_CALL_CONV :SOCKET, :ptr sockaddr, :SDWORD
    LPFN_CONNECT typedef ptr TYPE_LPFN_CONNECT

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, ioctlsocket, WIN_STD_CALL_CONV,, <:SOCKET, :SDWORD, :ptr u_long>, 12
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_IOCTLSOCKET typedef proto WIN_STD_CALL_CONV :SOCKET, :SDWORD, :ptr u_long
    LPFN_IOCTLSOCKET typedef ptr TYPE_LPFN_IOCTLSOCKET

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, getpeername, WIN_STD_CALL_CONV,, <:SOCKET, :ptr sockaddr, :ptr SDWORD>, 12
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_GETPEERNAME typedef proto WIN_STD_CALL_CONV :SOCKET, :ptr sockaddr, :ptr SDWORD
    LPFN_GETPEERNAME typedef ptr TYPE_LPFN_GETPEERNAME

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, getsockname, WIN_STD_CALL_CONV,, <:SOCKET, :ptr sockaddr, :ptr SDWORD>, 12
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_GETSOCKNAME typedef proto WIN_STD_CALL_CONV :SOCKET, :ptr sockaddr, :ptr SDWORD
    LPFN_GETSOCKNAME typedef ptr TYPE_LPFN_GETSOCKNAME

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, getsockopt, WIN_STD_CALL_CONV,, <:SOCKET, :SDWORD, :SDWORD, :ptr SBYTE, :ptr SDWORD>, 20
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_GETSOCKOPT typedef proto WIN_STD_CALL_CONV :SOCKET, :SDWORD, :SDWORD, :ptr SBYTE, :ptr SDWORD
    LPFN_GETSOCKOPT typedef ptr TYPE_LPFN_GETSOCKOPT

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, htonl, WIN_STD_CALL_CONV,, <:u_long>, 4
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_HTONL typedef proto WIN_STD_CALL_CONV :u_long
    LPFN_HTONL typedef ptr TYPE_LPFN_HTONL

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, htons, WIN_STD_CALL_CONV,, <:u_short>, 4
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_HTONS typedef proto WIN_STD_CALL_CONV :u_short
    LPFN_HTONS typedef ptr TYPE_LPFN_HTONS

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    _WINSOCK_DEPRECATED_BY("inet_pton() or InetPton()")
    @DefProto DllImport, inet_addr, WIN_STD_CALL_CONV,, <:ptr SBYTE>, 4
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_INET_ADDR typedef proto WIN_STD_CALL_CONV :ptr SBYTE
    LPFN_INET_ADDR typedef ptr TYPE_LPFN_INET_ADDR

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    _WINSOCK_DEPRECATED_BY("inet_ntop() or InetNtop()")
    @DefProto DllImport, inet_ntoa, WIN_STD_CALL_CONV,, <:in_addr>, 4
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_INET_NTOA typedef proto WIN_STD_CALL_CONV :in_addr
    LPFN_INET_NTOA typedef ptr TYPE_LPFN_INET_NTOA

  endif
  if  not Defined(NO_EXTRA_HTON_FUNCTIONS) and  not Defined(__midl) and (Defined(INCL_EXTRA_HTON_FUNCTIONS) or NTDDI_VERSION ge NTDDI_WIN8)
    _WS2_32_WINSOCK_SWAP_LONG macro l
      exitm <((((l) shr 24) and 000000FFh) or (((l) shr 8) and 0000FF00h) or (((l) shl 8) and 00FF0000h) or (((l) shl 24) and 0FF000000h))>
    endm
    _WS2_32_WINSOCK_SWAP_LONGLONG macro l
      exitm <((((l) shr 56) and 00000000000000FFLh) or (((l) shr 40) and 000000000000FF00Lh) or (((l) shr 24) and 0000000000FF0000Lh) or (((l) shr 8) and 00000000FF000000Lh) or (((l) shl 8) and 000000FF00000000Lh) or (((l) shl 24) and 0000FF0000000000Lh) or (((l) shl 40) and 00FF000000000000Lh) or (((l) shl 56) and 0FF00000000000000Lh))>
    endm
    ifndef htonll
      htonll proto WIN_STD_CALL_CONV :QWORD
    endif
    ifndef ntohll
      ntohll proto WIN_STD_CALL_CONV :QWORD
    endif
    ifndef htonf
      htonf proto WIN_STD_CALL_CONV :REAL4
    endif
    ifndef ntohf
      ntohf proto WIN_STD_CALL_CONV :DWORD
    endif
    ifndef htond
      htond proto WIN_STD_CALL_CONV :REAL8
    endif
    ifndef ntohd
      ntohd proto WIN_STD_CALL_CONV :QWORD
    endif
  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, listen, WIN_STD_CALL_CONV,, <:SOCKET, :SDWORD>, 8
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_LISTEN typedef proto WIN_STD_CALL_CONV :SOCKET, :SDWORD
    LPFN_LISTEN typedef ptr TYPE_LPFN_LISTEN

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, ntohl, WIN_STD_CALL_CONV,, <:u_long>, 4
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_NTOHL typedef proto WIN_STD_CALL_CONV :u_long
    LPFN_NTOHL typedef ptr TYPE_LPFN_NTOHL

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, ntohs, WIN_STD_CALL_CONV,, <:u_short>, 4
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_NTOHS typedef proto WIN_STD_CALL_CONV :u_short
    LPFN_NTOHS typedef ptr TYPE_LPFN_NTOHS

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, recv, WIN_STD_CALL_CONV,, <:SOCKET, :ptr SBYTE, :SDWORD, :SDWORD>, 16
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_RECV typedef proto WIN_STD_CALL_CONV :SOCKET, :ptr SBYTE, :SDWORD, :SDWORD
    LPFN_RECV typedef ptr TYPE_LPFN_RECV

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, recvfrom, WIN_STD_CALL_CONV,, <:SOCKET, :ptr SBYTE, :SDWORD, :SDWORD, :ptr sockaddr, :ptr SDWORD>, 24
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_RECVFROM typedef proto WIN_STD_CALL_CONV :SOCKET, :ptr SBYTE, :SDWORD, :SDWORD, :ptr sockaddr, :ptr SDWORD
    LPFN_RECVFROM typedef ptr TYPE_LPFN_RECVFROM

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, select, WIN_STD_CALL_CONV,, <:SDWORD, :ptr fd_set, :ptr fd_set, :ptr fd_set, :ptr timeval>, 20
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_SELECT typedef proto WIN_STD_CALL_CONV :SDWORD, :ptr fd_set, :ptr fd_set, :ptr fd_set, :ptr timeval
    LPFN_SELECT typedef ptr TYPE_LPFN_SELECT

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, send, WIN_STD_CALL_CONV,, <:SOCKET, :ptr SBYTE, :SDWORD, :SDWORD>, 16
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_SEND typedef proto WIN_STD_CALL_CONV :SOCKET, :ptr SBYTE, :SDWORD, :SDWORD
    LPFN_SEND typedef ptr TYPE_LPFN_SEND

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, sendto, WIN_STD_CALL_CONV,, <:SOCKET, :ptr SBYTE, :SDWORD, :SDWORD, :ptr sockaddr, :SDWORD>, 24
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_SENDTO typedef proto WIN_STD_CALL_CONV :SOCKET, :ptr SBYTE, :SDWORD, :SDWORD, :ptr sockaddr, :SDWORD
    LPFN_SENDTO typedef ptr TYPE_LPFN_SENDTO

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, setsockopt, WIN_STD_CALL_CONV,, <:SOCKET, :SDWORD, :SDWORD, :ptr SBYTE, :SDWORD>, 20
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_SETSOCKOPT typedef proto WIN_STD_CALL_CONV :SOCKET, :SDWORD, :SDWORD, :ptr SBYTE, :SDWORD
    LPFN_SETSOCKOPT typedef ptr TYPE_LPFN_SETSOCKOPT

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, shutdown, WIN_STD_CALL_CONV,, <:SOCKET, :SDWORD>, 8
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_SHUTDOWN typedef proto WIN_STD_CALL_CONV :SOCKET, :SDWORD
    LPFN_SHUTDOWN typedef ptr TYPE_LPFN_SHUTDOWN

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, socket, WIN_STD_CALL_CONV,, <:SDWORD, :SDWORD, :SDWORD>, 12
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_SOCKET typedef proto WIN_STD_CALL_CONV :SDWORD, :SDWORD, :SDWORD
    LPFN_SOCKET typedef ptr TYPE_LPFN_SOCKET

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    _WINSOCK_DEPRECATED_BY("getnameinfo() or GetNameInfoW()")
    @DefProto DllImport, gethostbyaddr, WIN_STD_CALL_CONV,, <:ptr SBYTE, :SDWORD, :SDWORD>, 12
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_GETHOSTBYADDR typedef proto WIN_STD_CALL_CONV :ptr SBYTE, :SDWORD, :SDWORD
    LPFN_GETHOSTBYADDR typedef ptr TYPE_LPFN_GETHOSTBYADDR

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    _WINSOCK_DEPRECATED_BY("getaddrinfo() or GetAddrInfoW()")
    @DefProto DllImport, gethostbyname, WIN_STD_CALL_CONV,, <:ptr SBYTE>, 4
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_GETHOSTBYNAME typedef proto WIN_STD_CALL_CONV :ptr SBYTE
    LPFN_GETHOSTBYNAME typedef ptr TYPE_LPFN_GETHOSTBYNAME

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, gethostname, WIN_STD_CALL_CONV,, <:ptr SBYTE, :SDWORD>, 8
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_GETHOSTNAME typedef proto WIN_STD_CALL_CONV :ptr SBYTE, :SDWORD
    LPFN_GETHOSTNAME typedef ptr TYPE_LPFN_GETHOSTNAME

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, GetHostNameW, WIN_STD_CALL_CONV,, <:PWSTR, :SDWORD>, 8
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_GETHOSTNAMEW typedef proto WIN_STD_CALL_CONV :PWSTR, :SDWORD
    LPFN_GETHOSTNAMEW typedef ptr TYPE_LPFN_GETHOSTNAMEW

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, getservbyport, WIN_STD_CALL_CONV,, <:SDWORD, :ptr SBYTE>, 8
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_GETSERVBYPORT typedef proto WIN_STD_CALL_CONV :SDWORD, :ptr SBYTE
    LPFN_GETSERVBYPORT typedef ptr TYPE_LPFN_GETSERVBYPORT

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, getservbyname, WIN_STD_CALL_CONV,, <:ptr SBYTE, :ptr SBYTE>, 8
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_GETSERVBYNAME typedef proto WIN_STD_CALL_CONV :ptr SBYTE, :ptr SBYTE
    LPFN_GETSERVBYNAME typedef ptr TYPE_LPFN_GETSERVBYNAME

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, getprotobynumber, WIN_STD_CALL_CONV,, <:SDWORD>, 4
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_GETPROTOBYNUMBER typedef proto WIN_STD_CALL_CONV :SDWORD
    LPFN_GETPROTOBYNUMBER typedef ptr TYPE_LPFN_GETPROTOBYNUMBER

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, getprotobyname, WIN_STD_CALL_CONV,, <:ptr SBYTE>, 4
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_GETPROTOBYNAME typedef proto WIN_STD_CALL_CONV :ptr SBYTE
    LPFN_GETPROTOBYNAME typedef ptr TYPE_LPFN_GETPROTOBYNAME

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, WSAStartup, WIN_STD_CALL_CONV,, <:WORD, :LPWSADATA>, 8
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSASTARTUP typedef proto WIN_STD_CALL_CONV :WORD, :LPWSADATA
    LPFN_WSASTARTUP typedef ptr TYPE_LPFN_WSASTARTUP

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, WSACleanup, WIN_STD_CALL_CONV,, <>, 0
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSACLEANUP typedef proto WIN_STD_CALL_CONV
    LPFN_WSACLEANUP typedef ptr TYPE_LPFN_WSACLEANUP

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, WSASetLastError, WIN_STD_CALL_CONV,, <:SDWORD>, 4
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSASETLASTERROR typedef proto WIN_STD_CALL_CONV :SDWORD
    LPFN_WSASETLASTERROR typedef ptr TYPE_LPFN_WSASETLASTERROR

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, WSAGetLastError, WIN_STD_CALL_CONV,, <>, 0
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSAGETLASTERROR typedef proto WIN_STD_CALL_CONV
    LPFN_WSAGETLASTERROR typedef ptr TYPE_LPFN_WSAGETLASTERROR

  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if INCL_WINSOCK_API_PROTOTYPES
      _WINSOCK_DEPRECATED_BY("Winsock 2")
      @DefProto DllImport, WSAIsBlocking, WIN_STD_CALL_CONV,, <>, 0
    endif
    if INCL_WINSOCK_API_TYPEDEFS
      TYPE_LPFN_WSAISBLOCKING typedef proto WIN_STD_CALL_CONV
      LPFN_WSAISBLOCKING typedef ptr TYPE_LPFN_WSAISBLOCKING

    endif
    if INCL_WINSOCK_API_PROTOTYPES
      _WINSOCK_DEPRECATED_BY("Winsock 2")
      @DefProto DllImport, WSAUnhookBlockingHook, WIN_STD_CALL_CONV,, <>, 0
    endif
    if INCL_WINSOCK_API_TYPEDEFS
      TYPE_LPFN_WSAUNHOOKBLOCKINGHOOK typedef proto WIN_STD_CALL_CONV
      LPFN_WSAUNHOOKBLOCKINGHOOK typedef ptr TYPE_LPFN_WSAUNHOOKBLOCKINGHOOK

    endif
    if INCL_WINSOCK_API_PROTOTYPES
      _WINSOCK_DEPRECATED_BY("Winsock 2")
      @DefProto DllImport, WSASetBlockingHook, WIN_STD_CALL_CONV,, <:FARPROC>, 4
    endif
    if INCL_WINSOCK_API_TYPEDEFS
      TYPE_LPFN_WSASETBLOCKINGHOOK typedef proto WIN_STD_CALL_CONV :FARPROC
      LPFN_WSASETBLOCKINGHOOK typedef ptr TYPE_LPFN_WSASETBLOCKINGHOOK

    endif
    if INCL_WINSOCK_API_PROTOTYPES
      _WINSOCK_DEPRECATED_BY("Winsock 2")
      @DefProto DllImport, WSACancelBlockingCall, WIN_STD_CALL_CONV,, <>, 0
    endif
    if INCL_WINSOCK_API_TYPEDEFS
      TYPE_LPFN_WSACANCELBLOCKINGCALL typedef proto WIN_STD_CALL_CONV
      LPFN_WSACANCELBLOCKINGCALL typedef ptr TYPE_LPFN_WSACANCELBLOCKINGCALL

    endif
    if INCL_WINSOCK_API_PROTOTYPES
      _WINSOCK_DEPRECATED_BY("getservbyname()")
      @DefProto DllImport, WSAAsyncGetServByName, WIN_STD_CALL_CONV,, <:HWND, :u_int, :ptr SBYTE, :ptr SBYTE, :ptr SBYTE, :SDWORD>, 24
    endif
    if INCL_WINSOCK_API_TYPEDEFS
      TYPE_LPFN_WSAASYNCGETSERVBYNAME typedef proto WIN_STD_CALL_CONV :HWND, :u_int, :ptr SBYTE, :ptr SBYTE, :ptr SBYTE, :SDWORD
      LPFN_WSAASYNCGETSERVBYNAME typedef ptr TYPE_LPFN_WSAASYNCGETSERVBYNAME

    endif
    if INCL_WINSOCK_API_PROTOTYPES
      _WINSOCK_DEPRECATED_BY("getservbyport()")
      @DefProto DllImport, WSAAsyncGetServByPort, WIN_STD_CALL_CONV,, <:HWND, :u_int, :SDWORD, :ptr SBYTE, :ptr SBYTE, :SDWORD>, 24
    endif
    if INCL_WINSOCK_API_TYPEDEFS
      TYPE_LPFN_WSAASYNCGETSERVBYPORT typedef proto WIN_STD_CALL_CONV :HWND, :u_int, :SDWORD, :ptr SBYTE, :ptr SBYTE, :SDWORD
      LPFN_WSAASYNCGETSERVBYPORT typedef ptr TYPE_LPFN_WSAASYNCGETSERVBYPORT

    endif
    if INCL_WINSOCK_API_PROTOTYPES
      _WINSOCK_DEPRECATED_BY("getprotobyname()")
      @DefProto DllImport, WSAAsyncGetProtoByName, WIN_STD_CALL_CONV,, <:HWND, :u_int, :ptr SBYTE, :ptr SBYTE, :SDWORD>, 20
    endif
    if INCL_WINSOCK_API_TYPEDEFS
      TYPE_LPFN_WSAASYNCGETPROTOBYNAME typedef proto WIN_STD_CALL_CONV :HWND, :u_int, :ptr SBYTE, :ptr SBYTE, :SDWORD
      LPFN_WSAASYNCGETPROTOBYNAME typedef ptr TYPE_LPFN_WSAASYNCGETPROTOBYNAME

    endif
    if INCL_WINSOCK_API_PROTOTYPES
      _WINSOCK_DEPRECATED_BY("getprotobynumber()")
      @DefProto DllImport, WSAAsyncGetProtoByNumber, WIN_STD_CALL_CONV,, <:HWND, :u_int, :SDWORD, :ptr SBYTE, :SDWORD>, 20
    endif
    if INCL_WINSOCK_API_TYPEDEFS
      TYPE_LPFN_WSAASYNCGETPROTOBYNUMBER typedef proto WIN_STD_CALL_CONV :HWND, :u_int, :SDWORD, :ptr SBYTE, :SDWORD
      LPFN_WSAASYNCGETPROTOBYNUMBER typedef ptr TYPE_LPFN_WSAASYNCGETPROTOBYNUMBER

    endif
    if INCL_WINSOCK_API_PROTOTYPES
      _WINSOCK_DEPRECATED_BY("GetAddrInfoExW()")
      @DefProto DllImport, WSAAsyncGetHostByName, WIN_STD_CALL_CONV,, <:HWND, :u_int, :ptr SBYTE, :ptr SBYTE, :SDWORD>, 20
    endif
    if INCL_WINSOCK_API_TYPEDEFS
      TYPE_LPFN_WSAASYNCGETHOSTBYNAME typedef proto WIN_STD_CALL_CONV :HWND, :u_int, :ptr SBYTE, :ptr SBYTE, :SDWORD
      LPFN_WSAASYNCGETHOSTBYNAME typedef ptr TYPE_LPFN_WSAASYNCGETHOSTBYNAME

    endif
    if INCL_WINSOCK_API_PROTOTYPES
      _WINSOCK_DEPRECATED_BY("getnameinfo() or GetNameInfoW()")
      @DefProto DllImport, WSAAsyncGetHostByAddr, WIN_STD_CALL_CONV,, <:HWND, :u_int, :ptr SBYTE, :SDWORD, :SDWORD, :ptr SBYTE, :SDWORD>, 28
    endif
    if INCL_WINSOCK_API_TYPEDEFS
      TYPE_LPFN_WSAASYNCGETHOSTBYADDR typedef proto WIN_STD_CALL_CONV :HWND, :u_int, :ptr SBYTE, :SDWORD, :SDWORD, :ptr SBYTE, :SDWORD
      LPFN_WSAASYNCGETHOSTBYADDR typedef ptr TYPE_LPFN_WSAASYNCGETHOSTBYADDR

    endif
    if INCL_WINSOCK_API_PROTOTYPES
      @DefProto DllImport, WSACancelAsyncRequest, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    endif
    if INCL_WINSOCK_API_TYPEDEFS
      TYPE_LPFN_WSACANCELASYNCREQUEST typedef proto WIN_STD_CALL_CONV :HANDLE
      LPFN_WSACANCELASYNCREQUEST typedef ptr TYPE_LPFN_WSACANCELASYNCREQUEST

    endif
    if INCL_WINSOCK_API_PROTOTYPES
      _WINSOCK_DEPRECATED_BY("WSAEventSelect()")
      @DefProto DllImport, WSAAsyncSelect, WIN_STD_CALL_CONV,, <:SOCKET, :HWND, :u_int, :SDWORD>, 16
    endif
    if INCL_WINSOCK_API_TYPEDEFS
      TYPE_LPFN_WSAASYNCSELECT typedef proto WIN_STD_CALL_CONV :SOCKET, :HWND, :u_int, :SDWORD
      LPFN_WSAASYNCSELECT typedef ptr TYPE_LPFN_WSAASYNCSELECT

    endif
  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, WSAAccept, WIN_STD_CALL_CONV,, <:SOCKET, :ptr sockaddr, :LPINT, :LPCONDITIONPROC, :DWORD_PTR>, 20
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSAACCEPT typedef proto WIN_STD_CALL_CONV :SOCKET, :ptr sockaddr, :LPINT, :LPCONDITIONPROC, :DWORD_PTR
    LPFN_WSAACCEPT typedef ptr TYPE_LPFN_WSAACCEPT

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, WSACloseEvent, WIN_STD_CALL_CONV,, <:WSAEVENT>, 4
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSACLOSEEVENT typedef proto WIN_STD_CALL_CONV :WSAEVENT
    LPFN_WSACLOSEEVENT typedef ptr TYPE_LPFN_WSACLOSEEVENT

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, WSAConnect, WIN_STD_CALL_CONV,, <:SOCKET, :ptr sockaddr, :SDWORD, :LPWSABUF, :LPWSABUF, :LPQOS, :LPQOS>, 28
  endif
  if INCL_WINSOCK_API_PROTOTYPES
    ifdef UNICODE
      WSAConnectByName equ <WSAConnectByNameW>
    else
      WSAConnectByName equ <WSAConnectByNameA>
    endif
    WSAConnectByNameW proto WIN_STD_CALL_CONV :SOCKET, :LPWSTR, :LPWSTR, :LPDWORD, :LPSOCKADDR, :LPDWORD, :LPSOCKADDR, :ptr timeval, :LPWSAOVERLAPPED
    _WINSOCK_DEPRECATED_BY("WSAConnectByNameW()")
    WSAConnectByNameA proto WIN_STD_CALL_CONV :SOCKET, :LPCSTR, :LPCSTR, :LPDWORD, :LPSOCKADDR, :LPDWORD, :LPSOCKADDR, :ptr timeval, :LPWSAOVERLAPPED
    WSAConnectByList proto WIN_STD_CALL_CONV :SOCKET, :PSOCKET_ADDRESS_LIST, :LPDWORD, :LPSOCKADDR, :LPDWORD, :LPSOCKADDR, :ptr timeval, :LPWSAOVERLAPPED
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSACONNECT typedef proto WIN_STD_CALL_CONV :SOCKET, :ptr sockaddr, :SDWORD, :LPWSABUF, :LPWSABUF, :LPQOS, :LPQOS
    LPFN_WSACONNECT typedef ptr TYPE_LPFN_WSACONNECT

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, WSACreateEvent, WIN_STD_CALL_CONV,, <>, 0
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSACREATEEVENT typedef proto WIN_STD_CALL_CONV
    LPFN_WSACREATEEVENT typedef ptr TYPE_LPFN_WSACREATEEVENT

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    _WINSOCK_DEPRECATED_BY("WSADuplicateSocketW()")
    @DefProto DllImport, WSADuplicateSocketA, WIN_STD_CALL_CONV,, <:SOCKET, :DWORD, :LPWSAPROTOCOL_INFOA>, 12
    @DefProto DllImport, WSADuplicateSocketW, WIN_STD_CALL_CONV,, <:SOCKET, :DWORD, :LPWSAPROTOCOL_INFOW>, 12
    ifdef UNICODE
      WSADuplicateSocket equ <WSADuplicateSocketW>
    else
      WSADuplicateSocket equ <WSADuplicateSocketA>
    endif
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSADUPLICATESOCKETA typedef proto WIN_STD_CALL_CONV :SOCKET, :DWORD, :LPWSAPROTOCOL_INFOA
    LPFN_WSADUPLICATESOCKETA typedef ptr TYPE_LPFN_WSADUPLICATESOCKETA

    TYPE_LPFN_WSADUPLICATESOCKETW typedef proto WIN_STD_CALL_CONV :SOCKET, :DWORD, :LPWSAPROTOCOL_INFOW
    LPFN_WSADUPLICATESOCKETW typedef ptr TYPE_LPFN_WSADUPLICATESOCKETW

    ifdef UNICODE
      LPFN_WSADUPLICATESOCKET equ <LPFN_WSADUPLICATESOCKETW>
    else
      LPFN_WSADUPLICATESOCKET equ <LPFN_WSADUPLICATESOCKETA>
    endif
  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, WSAEnumNetworkEvents, WIN_STD_CALL_CONV,, <:SOCKET, :WSAEVENT, :LPWSANETWORKEVENTS>, 12
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSAENUMNETWORKEVENTS typedef proto WIN_STD_CALL_CONV :SOCKET, :WSAEVENT, :LPWSANETWORKEVENTS
    LPFN_WSAENUMNETWORKEVENTS typedef ptr TYPE_LPFN_WSAENUMNETWORKEVENTS

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    _WINSOCK_DEPRECATED_BY("WSAEnumProtocolsW()")
    @DefProto DllImport, WSAEnumProtocolsA, WIN_STD_CALL_CONV,, <:LPINT, :LPWSAPROTOCOL_INFOA, :LPDWORD>, 12
    @DefProto DllImport, WSAEnumProtocolsW, WIN_STD_CALL_CONV,, <:LPINT, :LPWSAPROTOCOL_INFOW, :LPDWORD>, 12
    ifdef UNICODE
      WSAEnumProtocols equ <WSAEnumProtocolsW>
    else
      WSAEnumProtocols equ <WSAEnumProtocolsA>
    endif
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSAENUMPROTOCOLSA typedef proto WIN_STD_CALL_CONV :LPINT, :LPWSAPROTOCOL_INFOA, :LPDWORD
    LPFN_WSAENUMPROTOCOLSA typedef ptr TYPE_LPFN_WSAENUMPROTOCOLSA

    TYPE_LPFN_WSAENUMPROTOCOLSW typedef proto WIN_STD_CALL_CONV :LPINT, :LPWSAPROTOCOL_INFOW, :LPDWORD
    LPFN_WSAENUMPROTOCOLSW typedef ptr TYPE_LPFN_WSAENUMPROTOCOLSW

    ifdef UNICODE
      LPFN_WSAENUMPROTOCOLS equ <LPFN_WSAENUMPROTOCOLSW>
    else
      LPFN_WSAENUMPROTOCOLS equ <LPFN_WSAENUMPROTOCOLSA>
    endif
  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, WSAEventSelect, WIN_STD_CALL_CONV,, <:SOCKET, :WSAEVENT, :SDWORD>, 12
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSAEVENTSELECT typedef proto WIN_STD_CALL_CONV :SOCKET, :WSAEVENT, :SDWORD
    LPFN_WSAEVENTSELECT typedef ptr TYPE_LPFN_WSAEVENTSELECT

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, WSAGetOverlappedResult, WIN_STD_CALL_CONV,, <:SOCKET, :LPWSAOVERLAPPED, :LPDWORD, :BOOL, :LPDWORD>, 20
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSAGETOVERLAPPEDRESULT typedef proto WIN_STD_CALL_CONV :SOCKET, :LPWSAOVERLAPPED, :LPDWORD, :BOOL, :LPDWORD
    LPFN_WSAGETOVERLAPPEDRESULT typedef ptr TYPE_LPFN_WSAGETOVERLAPPEDRESULT

  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if INCL_WINSOCK_API_PROTOTYPES
      @DefProto DllImport, WSAGetQOSByName, WIN_STD_CALL_CONV,, <:SOCKET, :LPWSABUF, :LPQOS>, 12
    endif
    if INCL_WINSOCK_API_TYPEDEFS
      TYPE_LPFN_WSAGETQOSBYNAME typedef proto WIN_STD_CALL_CONV :SOCKET, :LPWSABUF, :LPQOS
      LPFN_WSAGETQOSBYNAME typedef ptr TYPE_LPFN_WSAGETQOSBYNAME

    endif
  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, WSAHtonl, WIN_STD_CALL_CONV,, <:SOCKET, :u_long, :ptr u_long>, 12
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSAHTONL typedef proto WIN_STD_CALL_CONV :SOCKET, :u_long, :ptr u_long
    LPFN_WSAHTONL typedef ptr TYPE_LPFN_WSAHTONL

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, WSAHtons, WIN_STD_CALL_CONV,, <:SOCKET, :u_short, :ptr u_short>, 12
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSAHTONS typedef proto WIN_STD_CALL_CONV :SOCKET, :u_short, :ptr u_short
    LPFN_WSAHTONS typedef ptr TYPE_LPFN_WSAHTONS

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, WSAIoctl, WIN_STD_CALL_CONV,, <:SOCKET, :DWORD, :LPVOID, :DWORD, :LPVOID, :DWORD, :LPDWORD, :LPWSAOVERLAPPED, :LPWSAOVERLAPPED_COMPLETION_ROUTINE>, 36
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSAIOCTL typedef proto WIN_STD_CALL_CONV :SOCKET, :DWORD, :LPVOID, :DWORD, :LPVOID, :DWORD, :LPDWORD, :LPWSAOVERLAPPED, :LPWSAOVERLAPPED_COMPLETION_ROUTINE
    LPFN_WSAIOCTL typedef ptr TYPE_LPFN_WSAIOCTL

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, WSAJoinLeaf, WIN_STD_CALL_CONV,, <:SOCKET, :ptr sockaddr, :SDWORD, :LPWSABUF, :LPWSABUF, :LPQOS, :LPQOS, :DWORD>, 32
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSAJOINLEAF typedef proto WIN_STD_CALL_CONV :SOCKET, :ptr sockaddr, :SDWORD, :LPWSABUF, :LPWSABUF, :LPQOS, :LPQOS, :DWORD
    LPFN_WSAJOINLEAF typedef ptr TYPE_LPFN_WSAJOINLEAF

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, WSANtohl, WIN_STD_CALL_CONV,, <:SOCKET, :u_long, :ptr u_long>, 12
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSANTOHL typedef proto WIN_STD_CALL_CONV :SOCKET, :u_long, :ptr u_long
    LPFN_WSANTOHL typedef ptr TYPE_LPFN_WSANTOHL

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, WSANtohs, WIN_STD_CALL_CONV,, <:SOCKET, :u_short, :ptr u_short>, 12
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSANTOHS typedef proto WIN_STD_CALL_CONV :SOCKET, :u_short, :ptr u_short
    LPFN_WSANTOHS typedef ptr TYPE_LPFN_WSANTOHS

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, WSARecv, WIN_STD_CALL_CONV,, <:SOCKET, :LPWSABUF, :DWORD, :LPDWORD, :LPDWORD, :LPWSAOVERLAPPED, :LPWSAOVERLAPPED_COMPLETION_ROUTINE>, 28
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSARECV typedef proto WIN_STD_CALL_CONV :SOCKET, :LPWSABUF, :DWORD, :LPDWORD, :LPDWORD, :LPWSAOVERLAPPED, :LPWSAOVERLAPPED_COMPLETION_ROUTINE
    LPFN_WSARECV typedef ptr TYPE_LPFN_WSARECV

  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if INCL_WINSOCK_API_PROTOTYPES
      _WINSOCK_DEPRECATED_BY("WSARecv()")
      @DefProto DllImport, WSARecvDisconnect, WIN_STD_CALL_CONV,, <:SOCKET, :LPWSABUF>, 8
    endif
    if INCL_WINSOCK_API_TYPEDEFS
      TYPE_LPFN_WSARECVDISCONNECT typedef proto WIN_STD_CALL_CONV :SOCKET, :LPWSABUF
      LPFN_WSARECVDISCONNECT typedef ptr TYPE_LPFN_WSARECVDISCONNECT

    endif
  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, WSARecvFrom, WIN_STD_CALL_CONV,, <:SOCKET, :LPWSABUF, :DWORD, :LPDWORD, :LPDWORD, :ptr sockaddr, :LPINT, :LPWSAOVERLAPPED, :LPWSAOVERLAPPED_COMPLETION_ROUTINE>, 36
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSARECVFROM typedef proto WIN_STD_CALL_CONV :SOCKET, :LPWSABUF, :DWORD, :LPDWORD, :LPDWORD, :ptr sockaddr, :LPINT, :LPWSAOVERLAPPED, :LPWSAOVERLAPPED_COMPLETION_ROUTINE
    LPFN_WSARECVFROM typedef ptr TYPE_LPFN_WSARECVFROM

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, WSAResetEvent, WIN_STD_CALL_CONV,, <:WSAEVENT>, 4
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSARESETEVENT typedef proto WIN_STD_CALL_CONV :WSAEVENT
    LPFN_WSARESETEVENT typedef ptr TYPE_LPFN_WSARESETEVENT

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, WSASend, WIN_STD_CALL_CONV,, <:SOCKET, :LPWSABUF, :DWORD, :LPDWORD, :DWORD, :LPWSAOVERLAPPED, :LPWSAOVERLAPPED_COMPLETION_ROUTINE>, 28
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSASEND typedef proto WIN_STD_CALL_CONV :SOCKET, :LPWSABUF, :DWORD, :LPDWORD, :DWORD, :LPWSAOVERLAPPED, :LPWSAOVERLAPPED_COMPLETION_ROUTINE
    LPFN_WSASEND typedef ptr TYPE_LPFN_WSASEND

  endif
  if (_WIN32_WINNT ge 0600h)
    if INCL_WINSOCK_API_PROTOTYPES
      @DefProto DllImport, WSASendMsg, WIN_STD_CALL_CONV,, <:SOCKET, :LPWSAMSG, :DWORD, :LPDWORD, :LPWSAOVERLAPPED, :LPWSAOVERLAPPED_COMPLETION_ROUTINE>, 24
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if INCL_WINSOCK_API_PROTOTYPES
      _WINSOCK_DEPRECATED_BY("WSASend()")
      @DefProto DllImport, WSASendDisconnect, WIN_STD_CALL_CONV,, <:SOCKET, :LPWSABUF>, 8
    endif
    if INCL_WINSOCK_API_TYPEDEFS
      TYPE_LPFN_WSASENDDISCONNECT typedef proto WIN_STD_CALL_CONV :SOCKET, :LPWSABUF
      LPFN_WSASENDDISCONNECT typedef ptr TYPE_LPFN_WSASENDDISCONNECT

    endif
  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, WSASendTo, WIN_STD_CALL_CONV,, <:SOCKET, :LPWSABUF, :DWORD, :LPDWORD, :DWORD, :ptr sockaddr, :SDWORD, :LPWSAOVERLAPPED, :LPWSAOVERLAPPED_COMPLETION_ROUTINE>, 36
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSASENDTO typedef proto WIN_STD_CALL_CONV :SOCKET, :LPWSABUF, :DWORD, :LPDWORD, :DWORD, :ptr sockaddr, :SDWORD, :LPWSAOVERLAPPED, :LPWSAOVERLAPPED_COMPLETION_ROUTINE
    LPFN_WSASENDTO typedef ptr TYPE_LPFN_WSASENDTO

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, WSASetEvent, WIN_STD_CALL_CONV,, <:WSAEVENT>, 4
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSASETEVENT typedef proto WIN_STD_CALL_CONV :WSAEVENT
    LPFN_WSASETEVENT typedef ptr TYPE_LPFN_WSASETEVENT

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    _WINSOCK_DEPRECATED_BY("WSASocketW()")
    @DefProto DllImport, WSASocketA, WIN_STD_CALL_CONV,, <:SDWORD, :SDWORD, :SDWORD, :LPWSAPROTOCOL_INFOA, :GROUP_, :DWORD>, 24
    @DefProto DllImport, WSASocketW, WIN_STD_CALL_CONV,, <:SDWORD, :SDWORD, :SDWORD, :LPWSAPROTOCOL_INFOW, :GROUP_, :DWORD>, 24
    ifdef UNICODE
      WSASocket equ <WSASocketW>
    else
      WSASocket equ <WSASocketA>
    endif
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSASOCKETA typedef proto WIN_STD_CALL_CONV :SDWORD, :SDWORD, :SDWORD, :LPWSAPROTOCOL_INFOA, :GROUP_, :DWORD
    LPFN_WSASOCKETA typedef ptr TYPE_LPFN_WSASOCKETA

    TYPE_LPFN_WSASOCKETW typedef proto WIN_STD_CALL_CONV :SDWORD, :SDWORD, :SDWORD, :LPWSAPROTOCOL_INFOW, :GROUP_, :DWORD
    LPFN_WSASOCKETW typedef ptr TYPE_LPFN_WSASOCKETW

    ifdef UNICODE
      LPFN_WSASOCKET equ <LPFN_WSASOCKETW>
    else
      LPFN_WSASOCKET equ <LPFN_WSASOCKETA>
    endif
  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, WSAWaitForMultipleEvents, WIN_STD_CALL_CONV,, <:DWORD, :ptr WSAEVENT, :BOOL, :DWORD, :BOOL>, 20
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSAWAITFORMULTIPLEEVENTS typedef proto WIN_STD_CALL_CONV :DWORD, :ptr WSAEVENT, :BOOL, :DWORD, :BOOL
    LPFN_WSAWAITFORMULTIPLEEVENTS typedef ptr TYPE_LPFN_WSAWAITFORMULTIPLEEVENTS

  endif
  if INCL_WINSOCK_API_PROTOTYPES
    _WINSOCK_DEPRECATED_BY("WSAAddressToStringW()")
    @DefProto DllImport, WSAAddressToStringA, WIN_STD_CALL_CONV,, <:LPSOCKADDR, :DWORD, :LPWSAPROTOCOL_INFOA, :LPSTR, :LPDWORD>, 20
    @DefProto DllImport, WSAAddressToStringW, WIN_STD_CALL_CONV,, <:LPSOCKADDR, :DWORD, :LPWSAPROTOCOL_INFOW, :LPWSTR, :LPDWORD>, 20
    ifdef UNICODE
      WSAAddressToString equ <WSAAddressToStringW>
    else
      WSAAddressToString equ <WSAAddressToStringA>
    endif
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSAADDRESSTOSTRINGA typedef proto WIN_STD_CALL_CONV :LPSOCKADDR, :DWORD, :LPWSAPROTOCOL_INFOA, :LPSTR, :LPDWORD
    LPFN_WSAADDRESSTOSTRINGA typedef ptr TYPE_LPFN_WSAADDRESSTOSTRINGA

    TYPE_LPFN_WSAADDRESSTOSTRINGW typedef proto WIN_STD_CALL_CONV :LPSOCKADDR, :DWORD, :LPWSAPROTOCOL_INFOW, :LPWSTR, :LPDWORD
    LPFN_WSAADDRESSTOSTRINGW typedef ptr TYPE_LPFN_WSAADDRESSTOSTRINGW

    ifdef UNICODE
      LPFN_WSAADDRESSTOSTRING equ <LPFN_WSAADDRESSTOSTRINGW>
    else
      LPFN_WSAADDRESSTOSTRING equ <LPFN_WSAADDRESSTOSTRINGA>
    endif
  endif
  if INCL_WINSOCK_API_PROTOTYPES
    _WINSOCK_DEPRECATED_BY("WSAStringToAddressW()")
    @DefProto DllImport, WSAStringToAddressA, WIN_STD_CALL_CONV,, <:LPSTR, :INT_, :LPWSAPROTOCOL_INFOA, :LPSOCKADDR, :LPINT>, 20
    @DefProto DllImport, WSAStringToAddressW, WIN_STD_CALL_CONV,, <:LPWSTR, :INT_, :LPWSAPROTOCOL_INFOW, :LPSOCKADDR, :LPINT>, 20
    ifdef UNICODE
      WSAStringToAddress equ <WSAStringToAddressW>
    else
      WSAStringToAddress equ <WSAStringToAddressA>
    endif
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSASTRINGTOADDRESSA typedef proto WIN_STD_CALL_CONV :LPSTR, :INT_, :LPWSAPROTOCOL_INFOA, :LPSOCKADDR, :LPINT
    LPFN_WSASTRINGTOADDRESSA typedef ptr TYPE_LPFN_WSASTRINGTOADDRESSA

    TYPE_LPFN_WSASTRINGTOADDRESSW typedef proto WIN_STD_CALL_CONV :LPWSTR, :INT_, :LPWSAPROTOCOL_INFOW, :LPSOCKADDR, :LPINT
    LPFN_WSASTRINGTOADDRESSW typedef ptr TYPE_LPFN_WSASTRINGTOADDRESSW

    ifdef UNICODE
      LPFN_WSASTRINGTOADDRESS equ <LPFN_WSASTRINGTOADDRESSW>
    else
      LPFN_WSASTRINGTOADDRESS equ <LPFN_WSASTRINGTOADDRESSA>
    endif
  endif
  if INCL_WINSOCK_API_PROTOTYPES
    _WINSOCK_DEPRECATED_BY("WSALookupServiceBeginW()")
    @DefProto DllImport, WSALookupServiceBeginA, WIN_STD_CALL_CONV,, <:LPWSAQUERYSETA, :DWORD, :LPHANDLE>, 12
    @DefProto DllImport, WSALookupServiceBeginW, WIN_STD_CALL_CONV,, <:LPWSAQUERYSETW, :DWORD, :LPHANDLE>, 12
    ifdef UNICODE
      WSALookupServiceBegin equ <WSALookupServiceBeginW>
    else
      WSALookupServiceBegin equ <WSALookupServiceBeginA>
    endif
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSALOOKUPSERVICEBEGINA typedef proto WIN_STD_CALL_CONV :LPWSAQUERYSETA, :DWORD, :LPHANDLE
    LPFN_WSALOOKUPSERVICEBEGINA typedef ptr TYPE_LPFN_WSALOOKUPSERVICEBEGINA

    TYPE_LPFN_WSALOOKUPSERVICEBEGINW typedef proto WIN_STD_CALL_CONV :LPWSAQUERYSETW, :DWORD, :LPHANDLE
    LPFN_WSALOOKUPSERVICEBEGINW typedef ptr TYPE_LPFN_WSALOOKUPSERVICEBEGINW

    ifdef UNICODE
      LPFN_WSALOOKUPSERVICEBEGIN equ <LPFN_WSALOOKUPSERVICEBEGINW>
    else
      LPFN_WSALOOKUPSERVICEBEGIN equ <LPFN_WSALOOKUPSERVICEBEGINA>
    endif
  endif
  if INCL_WINSOCK_API_PROTOTYPES
    _WINSOCK_DEPRECATED_BY("WSALookupServiceNextW()")
    @DefProto DllImport, WSALookupServiceNextA, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :LPDWORD, :LPWSAQUERYSETA>, 16
    @DefProto DllImport, WSALookupServiceNextW, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :LPDWORD, :LPWSAQUERYSETW>, 16
    ifdef UNICODE
      WSALookupServiceNext equ <WSALookupServiceNextW>
    else
      WSALookupServiceNext equ <WSALookupServiceNextA>
    endif
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSALOOKUPSERVICENEXTA typedef proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :LPDWORD, :LPWSAQUERYSETA
    LPFN_WSALOOKUPSERVICENEXTA typedef ptr TYPE_LPFN_WSALOOKUPSERVICENEXTA

    TYPE_LPFN_WSALOOKUPSERVICENEXTW typedef proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :LPDWORD, :LPWSAQUERYSETW
    LPFN_WSALOOKUPSERVICENEXTW typedef ptr TYPE_LPFN_WSALOOKUPSERVICENEXTW

    ifdef UNICODE
      LPFN_WSALOOKUPSERVICENEXT equ <LPFN_WSALOOKUPSERVICENEXTW>
    else
      LPFN_WSALOOKUPSERVICENEXT equ <LPFN_WSALOOKUPSERVICENEXTA>
    endif
  endif
  if (_WIN32_WINNT ge 0501h)
    if INCL_WINSOCK_API_PROTOTYPES
      @DefProto DllImport, WSANSPIoctl, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :LPVOID, :DWORD, :LPVOID, :DWORD, :LPDWORD, :LPWSACOMPLETION>, 32
    endif
    if INCL_WINSOCK_API_TYPEDEFS
      TYPE_LPFN_WSANSPIOCTL typedef proto WIN_STD_CALL_CONV :HANDLE, :DWORD, :LPVOID, :DWORD, :LPVOID, :DWORD, :LPDWORD, :LPWSACOMPLETION
      LPFN_WSANSPIOCTL typedef ptr TYPE_LPFN_WSANSPIOCTL

    endif
  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, WSALookupServiceEnd, WIN_STD_CALL_CONV,, <:HANDLE>, 4
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSALOOKUPSERVICEEND typedef proto WIN_STD_CALL_CONV :HANDLE
    LPFN_WSALOOKUPSERVICEEND typedef ptr TYPE_LPFN_WSALOOKUPSERVICEEND

  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if INCL_WINSOCK_API_PROTOTYPES
      _WINSOCK_DEPRECATED_BY("WSAInstallServiceClassW()")
      @DefProto DllImport, WSAInstallServiceClassA, WIN_STD_CALL_CONV,, <:LPWSASERVICECLASSINFOA>, 4
      @DefProto DllImport, WSAInstallServiceClassW, WIN_STD_CALL_CONV,, <:LPWSASERVICECLASSINFOW>, 4
      ifdef UNICODE
        WSAInstallServiceClass equ <WSAInstallServiceClassW>
      else
        WSAInstallServiceClass equ <WSAInstallServiceClassA>
      endif
    endif
    if INCL_WINSOCK_API_TYPEDEFS
      TYPE_LPFN_WSAINSTALLSERVICECLASSA typedef proto WIN_STD_CALL_CONV :LPWSASERVICECLASSINFOA
      LPFN_WSAINSTALLSERVICECLASSA typedef ptr TYPE_LPFN_WSAINSTALLSERVICECLASSA

      TYPE_LPFN_WSAINSTALLSERVICECLASSW typedef proto WIN_STD_CALL_CONV :LPWSASERVICECLASSINFOW
      LPFN_WSAINSTALLSERVICECLASSW typedef ptr TYPE_LPFN_WSAINSTALLSERVICECLASSW

      ifdef UNICODE
        LPFN_WSAINSTALLSERVICECLASS equ <LPFN_WSAINSTALLSERVICECLASSW>
      else
        LPFN_WSAINSTALLSERVICECLASS equ <LPFN_WSAINSTALLSERVICECLASSA>
      endif
    endif
    if INCL_WINSOCK_API_PROTOTYPES
      @DefProto DllImport, WSARemoveServiceClass, WIN_STD_CALL_CONV,, <:LPGUID>, 4
    endif
    if INCL_WINSOCK_API_TYPEDEFS
      TYPE_LPFN_WSAREMOVESERVICECLASS typedef proto WIN_STD_CALL_CONV :LPGUID
      LPFN_WSAREMOVESERVICECLASS typedef ptr TYPE_LPFN_WSAREMOVESERVICECLASS

    endif
  endif
  if INCL_WINSOCK_API_PROTOTYPES
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      _WINSOCK_DEPRECATED_BY("WSAGetServiceClassInfoW()")
      @DefProto DllImport, WSAGetServiceClassInfoA, WIN_STD_CALL_CONV,, <:LPGUID, :LPGUID, :LPDWORD, :LPWSASERVICECLASSINFOA>, 16
    endif
    @DefProto DllImport, WSAGetServiceClassInfoW, WIN_STD_CALL_CONV,, <:LPGUID, :LPGUID, :LPDWORD, :LPWSASERVICECLASSINFOW>, 16
    ifdef UNICODE
      WSAGetServiceClassInfo equ <WSAGetServiceClassInfoW>
    else
      WSAGetServiceClassInfo equ <WSAGetServiceClassInfoA>
    endif
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      TYPE_LPFN_WSAGETSERVICECLASSINFOA typedef proto WIN_STD_CALL_CONV :LPGUID, :LPGUID, :LPDWORD, :LPWSASERVICECLASSINFOA
      LPFN_WSAGETSERVICECLASSINFOA typedef ptr TYPE_LPFN_WSAGETSERVICECLASSINFOA

    endif
    TYPE_LPFN_WSAGETSERVICECLASSINFOW typedef proto WIN_STD_CALL_CONV :LPGUID, :LPGUID, :LPDWORD, :LPWSASERVICECLASSINFOW
    LPFN_WSAGETSERVICECLASSINFOW typedef ptr TYPE_LPFN_WSAGETSERVICECLASSINFOW

    ifdef UNICODE
      LPFN_WSAGETSERVICECLASSINFO equ <LPFN_WSAGETSERVICECLASSINFOW>
    else
      LPFN_WSAGETSERVICECLASSINFO equ <LPFN_WSAGETSERVICECLASSINFOA>
    endif
  endif
  if INCL_WINSOCK_API_PROTOTYPES
    _WINSOCK_DEPRECATED_BY("WSAEnumNameSpaceProvidersW()")
    @DefProto DllImport, WSAEnumNameSpaceProvidersA, WIN_STD_CALL_CONV,, <:LPDWORD, :LPWSANAMESPACE_INFOA>, 8
    @DefProto DllImport, WSAEnumNameSpaceProvidersW, WIN_STD_CALL_CONV,, <:LPDWORD, :LPWSANAMESPACE_INFOW>, 8
    ifdef UNICODE
      WSAEnumNameSpaceProviders equ <WSAEnumNameSpaceProvidersW>
    else
      WSAEnumNameSpaceProviders equ <WSAEnumNameSpaceProvidersA>
    endif
    if (_WIN32_WINNT ge 0600h)
      _WINSOCK_DEPRECATED_BY("WSAEnumNameSpaceProvidersW()")
      @DefProto DllImport, WSAEnumNameSpaceProvidersExA, WIN_STD_CALL_CONV,, <:LPDWORD, :LPWSANAMESPACE_INFOEXA>, 8
      @DefProto DllImport, WSAEnumNameSpaceProvidersExW, WIN_STD_CALL_CONV,, <:LPDWORD, :LPWSANAMESPACE_INFOEXW>, 8
      ifdef UNICODE
        WSAEnumNameSpaceProvidersEx equ <WSAEnumNameSpaceProvidersExW>
      else
        WSAEnumNameSpaceProvidersEx equ <WSAEnumNameSpaceProvidersExA>
      endif
    endif
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSAENUMNAMESPACEPROVIDERSA typedef proto WIN_STD_CALL_CONV :LPDWORD, :LPWSANAMESPACE_INFOA
    LPFN_WSAENUMNAMESPACEPROVIDERSA typedef ptr TYPE_LPFN_WSAENUMNAMESPACEPROVIDERSA

    TYPE_LPFN_WSAENUMNAMESPACEPROVIDERSW typedef proto WIN_STD_CALL_CONV :LPDWORD, :LPWSANAMESPACE_INFOW
    LPFN_WSAENUMNAMESPACEPROVIDERSW typedef ptr TYPE_LPFN_WSAENUMNAMESPACEPROVIDERSW

    ifdef UNICODE
      LPFN_WSAENUMNAMESPACEPROVIDERS equ <LPFN_WSAENUMNAMESPACEPROVIDERSW>
    else
      LPFN_WSAENUMNAMESPACEPROVIDERS equ <LPFN_WSAENUMNAMESPACEPROVIDERSA>
    endif
    if (_WIN32_WINNT ge 0600h)
      TYPE_LPFN_WSAENUMNAMESPACEPROVIDERSEXA typedef proto WIN_STD_CALL_CONV :LPDWORD, :LPWSANAMESPACE_INFOEXA
      LPFN_WSAENUMNAMESPACEPROVIDERSEXA typedef ptr TYPE_LPFN_WSAENUMNAMESPACEPROVIDERSEXA

      TYPE_LPFN_WSAENUMNAMESPACEPROVIDERSEXW typedef proto WIN_STD_CALL_CONV :LPDWORD, :LPWSANAMESPACE_INFOEXW
      LPFN_WSAENUMNAMESPACEPROVIDERSEXW typedef ptr TYPE_LPFN_WSAENUMNAMESPACEPROVIDERSEXW

      ifdef UNICODE
        LPFN_WSAENUMNAMESPACEPROVIDERSEX equ <LPFN_WSAENUMNAMESPACEPROVIDERSEXW>
      else
        LPFN_WSAENUMNAMESPACEPROVIDERSEX equ <LPFN_WSAENUMNAMESPACEPROVIDERSEXA>
      endif
    endif
  endif
  if INCL_WINSOCK_API_PROTOTYPES
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      _WINSOCK_DEPRECATED_BY("WSAGetServiceClassNameByClassIdW()")
      @DefProto DllImport, WSAGetServiceClassNameByClassIdA, WIN_STD_CALL_CONV,, <:LPGUID, :LPSTR, :LPDWORD>, 12
    endif
    @DefProto DllImport, WSAGetServiceClassNameByClassIdW, WIN_STD_CALL_CONV,, <:LPGUID, :LPWSTR, :LPDWORD>, 12
    ifdef UNICODE
      WSAGetServiceClassNameByClassId equ <WSAGetServiceClassNameByClassIdW>
    else
      WSAGetServiceClassNameByClassId equ <WSAGetServiceClassNameByClassIdA>
    endif
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      TYPE_LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDA typedef proto WIN_STD_CALL_CONV :LPGUID, :LPSTR, :LPDWORD
      LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDA typedef ptr TYPE_LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDA

    endif
    TYPE_LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDW typedef proto WIN_STD_CALL_CONV :LPGUID, :LPWSTR, :LPDWORD
    LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDW typedef ptr TYPE_LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDW

    ifdef UNICODE
      LPFN_WSAGETSERVICECLASSNAMEBYCLASSID equ <LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDW>
    else
      LPFN_WSAGETSERVICECLASSNAMEBYCLASSID equ <LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDA>
    endif
  endif
  if INCL_WINSOCK_API_PROTOTYPES
    _WINSOCK_DEPRECATED_BY("WSASetServiceW()")
    @DefProto DllImport, WSASetServiceA, WIN_STD_CALL_CONV,, <:LPWSAQUERYSETA, :WSAESETSERVICEOP, :DWORD>, 12
    @DefProto DllImport, WSASetServiceW, WIN_STD_CALL_CONV,, <:LPWSAQUERYSETW, :WSAESETSERVICEOP, :DWORD>, 12
    ifdef UNICODE
      WSASetService equ <WSASetServiceW>
    else
      WSASetService equ <WSASetServiceA>
    endif
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSASETSERVICEA typedef proto WIN_STD_CALL_CONV :LPWSAQUERYSETA, :WSAESETSERVICEOP, :DWORD
    LPFN_WSASETSERVICEA typedef ptr TYPE_LPFN_WSASETSERVICEA

    TYPE_LPFN_WSASETSERVICEW typedef proto WIN_STD_CALL_CONV :LPWSAQUERYSETW, :WSAESETSERVICEOP, :DWORD
    LPFN_WSASETSERVICEW typedef ptr TYPE_LPFN_WSASETSERVICEW

    ifdef UNICODE
      LPFN_WSASETSERVICE equ <LPFN_WSASETSERVICEW>
    else
      LPFN_WSASETSERVICE equ <LPFN_WSASETSERVICEA>
    endif
  endif
  if INCL_WINSOCK_API_PROTOTYPES
    @DefProto DllImport, WSAProviderConfigChange, WIN_STD_CALL_CONV,, <:LPHANDLE, :LPWSAOVERLAPPED, :LPWSAOVERLAPPED_COMPLETION_ROUTINE>, 12
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_WSAPROVIDERCONFIGCHANGE typedef proto WIN_STD_CALL_CONV :LPHANDLE, :LPWSAOVERLAPPED, :LPWSAOVERLAPPED_COMPLETION_ROUTINE
    LPFN_WSAPROVIDERCONFIGCHANGE typedef ptr TYPE_LPFN_WSAPROVIDERCONFIGCHANGE

  endif
  if (_WIN32_WINNT ge 0600h)
    if INCL_WINSOCK_API_PROTOTYPES
      @DefProto DllImport, WSAPoll, WIN_STD_CALL_CONV,, <:LPWSAPOLLFD, :ULONG, :INT_>, 12
    endif
  endif
  SOCK_NOTIFY_REGISTRATION struct
    socket SOCKET ?
    completionKey PVOID ?
    eventFilter UINT16 ?
    operation UINT8 ?
    triggerFlags UINT8 ?
    registrationResult DWORD ?
  SOCK_NOTIFY_REGISTRATION ends
  SOCK_NOTIFY_REGISTER_EVENT_NONE equ 00h
  SOCK_NOTIFY_REGISTER_EVENT_IN equ 01h
  SOCK_NOTIFY_REGISTER_EVENT_OUT equ 02h
  SOCK_NOTIFY_REGISTER_EVENT_HANGUP equ 04h
  SOCK_NOTIFY_REGISTER_EVENTS_ALL equ <(SOCK_NOTIFY_REGISTER_EVENT_IN or SOCK_NOTIFY_REGISTER_EVENT_OUT or SOCK_NOTIFY_REGISTER_EVENT_HANGUP)>
  SOCK_NOTIFY_EVENT_IN equ <SOCK_NOTIFY_REGISTER_EVENT_IN>
  SOCK_NOTIFY_EVENT_OUT equ <SOCK_NOTIFY_REGISTER_EVENT_OUT>
  SOCK_NOTIFY_EVENT_HANGUP equ <SOCK_NOTIFY_REGISTER_EVENT_HANGUP>
  SOCK_NOTIFY_EVENT_ERR equ 40h
  SOCK_NOTIFY_EVENT_REMOVE equ 80h
  SOCK_NOTIFY_EVENTS_ALL equ <(SOCK_NOTIFY_REGISTER_EVENTS_ALL or SOCK_NOTIFY_EVENT_ERR or SOCK_NOTIFY_EVENT_REMOVE)>
  SOCK_NOTIFY_OP_NONE equ 00h
  SOCK_NOTIFY_OP_ENABLE equ 01h
  SOCK_NOTIFY_OP_DISABLE equ 02h
  SOCK_NOTIFY_OP_REMOVE equ 04h
  SOCK_NOTIFY_TRIGGER_ONESHOT equ 01h
  SOCK_NOTIFY_TRIGGER_PERSISTENT equ 02h
  SOCK_NOTIFY_TRIGGER_LEVEL equ 04h
  SOCK_NOTIFY_TRIGGER_EDGE equ 08h
  SOCK_NOTIFY_TRIGGER_ALL equ <(SOCK_NOTIFY_TRIGGER_ONESHOT or SOCK_NOTIFY_TRIGGER_PERSISTENT or SOCK_NOTIFY_TRIGGER_LEVEL or SOCK_NOTIFY_TRIGGER_EDGE)>
  if (NTDDI_VERSION ge NTDDI_WIN10_MN)
    if INCL_WINSOCK_API_PROTOTYPES
      @DefProto DllImport, ProcessSocketNotifications, WIN_STD_CALL_CONV,, <:HANDLE, :UINT32, :ptr SOCK_NOTIFY_REGISTRATION, :UINT32, :ULONG, :ptr OVERLAPPED_ENTRY, :ptr UINT32>, 28
      if  not Defined(__midl)
        SocketNotificationRetrieveEvents proto WIN_STD_CALL_CONV :ptr OVERLAPPED_ENTRY
      endif
    endif
  endif
  LPSOCKADDR_IN typedef ptr sockaddr_in
  LINGER typedef linger
  PLINGER typedef ptr linger
  LPLINGER typedef ptr linger
  FD_SET typedef fd_set
  PFD_SET typedef ptr fd_set
  LPFD_SET typedef ptr fd_set
  HOSTENT typedef hostent
  PHOSTENT typedef ptr hostent
  LPHOSTENT typedef ptr hostent
  SERVENT typedef servent
  PSERVENT typedef ptr servent
  LPSERVENT typedef ptr servent
  PROTOENT typedef protoent
  PPROTOENT typedef ptr protoent
  LPPROTOENT typedef ptr protoent
  TIMEVAL typedef timeval
  PTIMEVAL typedef ptr timeval
  LPTIMEVAL typedef ptr timeval
  WSAMAKEASYNCREPLY macro buflen, error_
    exitm <MAKELONG(buflen, error_)>
  endm
  WSAMAKESELECTREPLY macro event_, error_
    exitm <MAKELONG(event_, error_)>
  endm
  WSAGETASYNCBUFLEN macro lParam
    exitm <LOWORD(lParam)>
  endm
  WSAGETASYNCERROR macro lParam
    exitm <HIWORD(lParam)>
  endm
  WSAGETSELECTEVENT macro lParam
    exitm <LOWORD(lParam)>
  endm
  WSAGETSELECTERROR macro lParam
    exitm <HIWORD(lParam)>
  endm
  ifdef __cplusplus
    ;[...]
  endif
  ifdef _NEED_POPPACK
    include poppack.inc
  endif
  if (_WIN32_WINNT ge 0501h)
    ifdef IPV6STRICT
      include wsipv6ok.inc
    endif
  endif
endif
