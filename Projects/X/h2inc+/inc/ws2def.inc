;Include file created by h2inc+ version C.2.0 on (UTC) 15/06/2024 16:37:44
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\ws2def.h
;             Created on (UTC) 22/05/2024 17:57:06
;             Last modified on (UTC) 12/02/2024 17:05:30

ifndef _WS2DEF_
  _WS2DEF_ equ <>
  if _MSC_VER gt 1000
  endif
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
  ifdef __cplusplus
    ;[...]
  endif
  if  not Defined(_WINSOCK2API_) and Defined(_WINSOCKAPI_)
    .err <Do not include winsock.h and ws2def.h in the same module. Instead include only winsock2.h.>
  endif
  if Defined(_PREFAST_) and Defined(IPV6_PREFAST_SAFE)
    ;[...]
  endif
  if (_WIN32_WINNT ge 0600h)
    ifdef _MSC_VER
      WS2DEF_INLINE equ <__inline>
    else
      WS2DEF_INLINE equ <extern inline>
    endif
  endif
  include inaddr.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    ADDRESS_FAMILY typedef USHORT
  endif
  AF_UNSPEC equ 0
  AF_UNIX equ 1
  AF_INET equ 2
  AF_IMPLINK equ 3
  AF_PUP equ 4
  AF_CHAOS equ 5
  AF_NS equ 6
  AF_IPX equ <AF_NS>
  AF_ISO equ 7
  AF_OSI equ <AF_ISO>
  AF_ECMA equ 8
  AF_DATAKIT equ 9
  AF_CCITT equ 10
  AF_SNA equ 11
  AF_DECnet equ 12
  AF_DLI equ 13
  AF_LAT equ 14
  AF_HYLINK equ 15
  AF_APPLETALK equ 16
  AF_NETBIOS equ 17
  AF_VOICEVIEW equ 18
  AF_FIREFOX equ 19
  AF_UNKNOWN1 equ 20
  AF_BAN equ 21
  AF_ATM equ 22
  AF_INET6 equ 23
  AF_CLUSTER equ 24
  AF_12844 equ 25
  AF_IRDA equ 26
  AF_NETDES equ 28
  if (_WIN32_WINNT lt 0501h)
    AF_MAX equ 29
  else
    AF_TCNPROCESS equ 29
    AF_TCNMESSAGE equ 30
    AF_ICLFXBM equ 31
    if (_WIN32_WINNT lt 0600h)
      AF_MAX equ 32
    else
      AF_BTH equ 32
      if (_WIN32_WINNT lt 0601h)
        AF_MAX equ 33
      else
        AF_LINK equ 33
        if (_WIN32_WINNT lt 0604h)
          AF_MAX equ 34
        else
          AF_HYPERV equ 34
          AF_MAX equ 35
        endif
      endif
    endif
  endif
  SOCK_STREAM equ 1
  SOCK_DGRAM equ 2
  SOCK_RAW equ 3
  SOCK_RDM equ 4
  SOCK_SEQPACKET equ 5
  SOL_SOCKET equ 0ffffh
  SOL_IP equ (SOL_SOCKET - 4)
  SOL_IPV6 equ (SOL_SOCKET - 5)
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
  SO_BSP_STATE equ 1009h
  SO_GROUP_ID equ 2001h
  SO_GROUP_PRIORITY equ 2002h
  SO_MAX_MSG_SIZE equ 2003h
  SO_CONDITIONAL_ACCEPT equ 3002h
  SO_PAUSE_ACCEPT equ 3003h
  SO_COMPARTMENT_ID equ 3004h
  if (_WIN32_WINNT ge 0600h)
    SO_RANDOMIZE_PORT equ 3005h
    SO_PORT_SCALABILITY equ 3006h
    SO_REUSE_UNICASTPORT equ 3007h
    SO_REUSE_MULTICASTPORT equ 3008h
    SO_ORIGINAL_DST equ 300Fh
    IP6T_SO_ORIGINAL_DST equ <SO_ORIGINAL_DST>
  endif
  WSK_SO_BASE equ 4000h
  TCP_NODELAY equ 0001h
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    SOCKADDR struct
      if (_WIN32_WINNT lt 0600h)
        sa_family u_short ?
      else
        sa_family ADDRESS_FAMILY ?
      endif
      sa_data CHAR 14 dup (?)
    SOCKADDR ends
    sockaddr typedef SOCKADDR
    PSOCKADDR typedef ptr SOCKADDR
    LPSOCKADDR typedef ptr SOCKADDR
    ifndef __CSADDR_DEFINED__
      __CSADDR_DEFINED__ equ <>
      SOCKET_ADDRESS struct
        lpSockaddr LPSOCKADDR ?
        iSockaddrLength INT_ ?
      SOCKET_ADDRESS ends
      _SOCKET_ADDRESS typedef SOCKET_ADDRESS
      PSOCKET_ADDRESS typedef ptr SOCKET_ADDRESS
      LPSOCKET_ADDRESS typedef ptr SOCKET_ADDRESS
    endif
    SOCKET_ADDRESS_LIST struct
      iAddressCount INT_ ?
      Address SOCKET_ADDRESS 1 dup (<>)
    SOCKET_ADDRESS_LIST ends
    _SOCKET_ADDRESS_LIST typedef SOCKET_ADDRESS_LIST
    PSOCKET_ADDRESS_LIST typedef ptr SOCKET_ADDRESS_LIST
    LPSOCKET_ADDRESS_LIST typedef ptr SOCKET_ADDRESS_LIST
    if (_WIN32_WINNT ge 0600h)
      SIZEOF_SOCKET_ADDRESS_LIST macro AddressCount
        exitm <(FIELD_OFFSET(SOCKET_ADDRESS_LIST, Address) + AddressCount * sizeof(SOCKET_ADDRESS))>
      endm
    endif
    CSADDR_INFO struct
      LocalAddr SOCKET_ADDRESS <>
      RemoteAddr SOCKET_ADDRESS <>
      iSocketType INT_ ?
      iProtocol INT_ ?
    CSADDR_INFO ends
    _CSADDR_INFO typedef CSADDR_INFO
    PCSADDR_INFO typedef ptr CSADDR_INFO
    LPCSADDR_INFO typedef ptr CSADDR_INFO
  endif
  _SS_MAXSIZE equ 128
  _SS_ALIGNSIZE equ <(sizeof(__int64))>
  if (_WIN32_WINNT ge 0600h)
    _SS_PAD1SIZE equ <(_SS_ALIGNSIZE - sizeof(USHORT))>
    _SS_PAD2SIZE equ <(_SS_MAXSIZE - (sizeof(USHORT) + _SS_PAD1SIZE + _SS_ALIGNSIZE))>
  else
    _SS_PAD1SIZE equ <(_SS_ALIGNSIZE - sizeof(short))>
    _SS_PAD2SIZE equ <(_SS_MAXSIZE - (sizeof(short) + _SS_PAD1SIZE + _SS_ALIGNSIZE))>
  endif
  SOCKADDR_STORAGE_LH struct
    ss_family ADDRESS_FAMILY ?
    __ss_pad1 CHAR _SS_PAD1SIZE dup (?)
    __ss_align SQWORD ?
    __ss_pad2 CHAR _SS_PAD2SIZE dup (?)
  SOCKADDR_STORAGE_LH ends
  sockaddr_storage typedef SOCKADDR_STORAGE_LH
  PSOCKADDR_STORAGE_LH typedef ptr SOCKADDR_STORAGE_LH
  LPSOCKADDR_STORAGE_LH typedef ptr SOCKADDR_STORAGE_LH
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    SOCKADDR_STORAGE_XP struct
      ss_family SWORD ?
      __ss_pad1 CHAR _SS_PAD1SIZE dup (?)
      __ss_align SQWORD ?
      __ss_pad2 CHAR _SS_PAD2SIZE dup (?)
    SOCKADDR_STORAGE_XP ends
    sockaddr_storage_xp typedef SOCKADDR_STORAGE_XP
    PSOCKADDR_STORAGE_XP typedef ptr SOCKADDR_STORAGE_XP
    LPSOCKADDR_STORAGE_XP typedef ptr SOCKADDR_STORAGE_XP
  endif
  if (_WIN32_WINNT ge 0600h)
    SOCKADDR_STORAGE typedef SOCKADDR_STORAGE_LH
    PSOCKADDR_STORAGE typedef ptr SOCKADDR_STORAGE
    LPSOCKADDR_STORAGE typedef ptr SOCKADDR_STORAGE
  elseif (_WIN32_WINNT ge 0501h)
    SOCKADDR_STORAGE typedef SOCKADDR_STORAGE_XP
    PSOCKADDR_STORAGE typedef ptr SOCKADDR_STORAGE
    LPSOCKADDR_STORAGE typedef ptr SOCKADDR_STORAGE
  endif
  if (_WIN32_WINNT ge 0602h)
    SOCKET_PROCESSOR_AFFINITY struct
      Processor PROCESSOR_NUMBER <>
      NumaNodeId USHORT ?
      Reserved USHORT ?
    SOCKET_PROCESSOR_AFFINITY ends
    _SOCKET_PROCESSOR_AFFINITY typedef SOCKET_PROCESSOR_AFFINITY
    PSOCKET_PROCESSOR_AFFINITY typedef ptr SOCKET_PROCESSOR_AFFINITY
  endif
  IOC_UNIX equ 00000000h
  IOC_WS2 equ 08000000h
  IOC_PROTOCOL equ 10000000h
  IOC_VENDOR equ 18000000h
  if (_WIN32_WINNT ge 0600h)
    IOC_WSK equ (IOC_WS2 or 07000000h)
  endif
  _WSAIO macro x, y
    exitm <(IOC_VOID or (x) or (y))>
  endm
  _WSAIOR macro x, y
    exitm <(IOC_OUT or (x) or (y))>
  endm
  _WSAIOW macro x, y
    exitm <(IOC_IN or (x) or (y))>
  endm
  _WSAIORW macro x, y
    exitm <(IOC_INOUT or (x) or (y))>
  endm
  SIO_ASSOCIATE_HANDLE equ _WSAIOW(IOC_WS2, 1)
  SIO_ENABLE_CIRCULAR_QUEUEING equ _WSAIO(IOC_WS2, 2)
  SIO_FIND_ROUTE equ _WSAIOR(IOC_WS2, 3)
  SIO_FLUSH equ _WSAIO(IOC_WS2, 4)
  SIO_GET_BROADCAST_ADDRESS equ _WSAIOR(IOC_WS2, 5)
  SIO_GET_EXTENSION_FUNCTION_POINTER equ _WSAIORW(IOC_WS2, 6)
  SIO_GET_QOS equ _WSAIORW(IOC_WS2, 7)
  SIO_GET_GROUP_QOS equ _WSAIORW(IOC_WS2, 8)
  SIO_MULTIPOINT_LOOPBACK equ _WSAIOW(IOC_WS2, 9)
  SIO_MULTICAST_SCOPE equ _WSAIOW(IOC_WS2, 10)
  SIO_SET_QOS equ _WSAIOW(IOC_WS2, 11)
  SIO_SET_GROUP_QOS equ _WSAIOW(IOC_WS2, 12)
  SIO_TRANSLATE_HANDLE equ _WSAIORW(IOC_WS2, 13)
  SIO_ROUTING_INTERFACE_QUERY equ _WSAIORW(IOC_WS2, 20)
  SIO_ROUTING_INTERFACE_CHANGE equ _WSAIOW(IOC_WS2, 21)
  SIO_ADDRESS_LIST_QUERY equ _WSAIOR(IOC_WS2, 22)
  SIO_ADDRESS_LIST_CHANGE equ _WSAIO(IOC_WS2, 23)
  SIO_QUERY_TARGET_PNP_HANDLE equ _WSAIOR(IOC_WS2, 24)
  SIO_QUERY_RSS_PROCESSOR_INFO equ _WSAIOR(IOC_WS2, 37)
  if (_WIN32_WINNT ge 0501h)
    SIO_ADDRESS_LIST_SORT equ _WSAIORW(IOC_WS2, 25)
  endif
  if (_WIN32_WINNT ge 0600h)
    SIO_RESERVED_1 equ _WSAIOW(IOC_WS2, 26)
    SIO_RESERVED_2 equ _WSAIOW(IOC_WS2, 33)
  endif
  SIO_GET_MULTIPLE_EXTENSION_FUNCTION_POINTER equ _WSAIORW(IOC_WS2, 36)
  IPPROTO_IP equ 0
  IPPROTO typedef SDWORD
  if (_WIN32_WINNT ge 0501h)
    IPPROTO_HOPOPTS equ 0
  endif
  IPPROTO_ICMP equ 1
  IPPROTO_IGMP equ 2
  IPPROTO_GGP equ 3
  if (_WIN32_WINNT ge 0501h)
    IPPROTO_IPV4 equ 4
  endif
  if (_WIN32_WINNT ge 0600h)
    IPPROTO_ST equ 5
  endif
  IPPROTO_TCP equ 6
  if (_WIN32_WINNT ge 0600h)
    IPPROTO_CBT equ 7
    IPPROTO_EGP equ 8
    IPPROTO_IGP equ 9
  endif
  IPPROTO_PUP equ 12
  IPPROTO_UDP equ 17
  IPPROTO_IDP equ 22
  if (_WIN32_WINNT ge 0600h)
    IPPROTO_RDP equ 27
  endif
  if (_WIN32_WINNT ge 0501h)
    IPPROTO_IPV6 equ 41
    IPPROTO_ROUTING equ 43
    IPPROTO_FRAGMENT equ 44
    IPPROTO_ESP equ 50
    IPPROTO_AH equ 51
    IPPROTO_ICMPV6 equ 58
    IPPROTO_NONE equ 59
    IPPROTO_DSTOPTS equ 60
  endif
  IPPROTO_ND equ 77
  if (_WIN32_WINNT ge 0501h)
    IPPROTO_ICLFXBM equ 78
  endif
  if (_WIN32_WINNT ge 0600h)
    IPPROTO_PIM equ 103
    IPPROTO_PGM equ 113
    IPPROTO_L2TP equ 115
    IPPROTO_SCTP equ 132
  endif
  IPPROTO_RAW equ 255
  IPPROTO_MAX equ 256
  IPPROTO_RESERVED_RAW equ 257
  IPPROTO_RESERVED_IPSEC equ 258
  IPPROTO_RESERVED_IPSECOFFLOAD equ 259
  IPPROTO_RESERVED_WNV equ 260
  IPPROTO_RESERVED_MAX equ 261
  PIPROTO typedef ptr IPPROTO
  IPPORT_TCPMUX equ 1
  IPPORT_ECHO equ 7
  IPPORT_DISCARD equ 9
  IPPORT_SYSTAT equ 11
  IPPORT_DAYTIME equ 13
  IPPORT_NETSTAT equ 15
  IPPORT_QOTD equ 17
  IPPORT_MSP equ 18
  IPPORT_CHARGEN equ 19
  IPPORT_FTP_DATA equ 20
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
  IPPORT_POP3 equ 110
  IPPORT_NTP equ 123
  IPPORT_EPMAP equ 135
  IPPORT_NETBIOS_NS equ 137
  IPPORT_NETBIOS_DGM equ 138
  IPPORT_NETBIOS_SSN equ 139
  IPPORT_IMAP equ 143
  IPPORT_SNMP equ 161
  IPPORT_SNMP_TRAP equ 162
  IPPORT_IMAP3 equ 220
  IPPORT_LDAP equ 389
  IPPORT_HTTPS equ 443
  IPPORT_MICROSOFT_DS equ 445
  IPPORT_EXECSERVER equ 512
  IPPORT_LOGINSERVER equ 513
  IPPORT_CMDSERVER equ 514
  IPPORT_EFSSERVER equ 520
  IPPORT_BIFFUDP equ 512
  IPPORT_WHOSERVER equ 513
  IPPORT_ROUTESERVER equ 520
  IPPORT_RESERVED equ 1024
  if (_WIN32_WINNT ge 0600h)
    IPPORT_REGISTERED_MIN equ <IPPORT_RESERVED>
    IPPORT_REGISTERED_MAX equ 0bfffh
    IPPORT_DYNAMIC_MIN equ 0c000h
    IPPORT_DYNAMIC_MAX equ 0ffffh
  endif
  IN_CLASSA macro i
    exitm <(((i) and 80000000h) == 0)>
  endm
  IN_CLASSA_NET equ 0ff000000h
  IN_CLASSA_NSHIFT equ 24
  IN_CLASSA_HOST equ 00ffffffh
  IN_CLASSA_MAX equ 128
  IN_CLASSB macro i
    exitm <(((i) and 0c0000000h) == 80000000h)>
  endm
  IN_CLASSB_NET equ 0ffff0000h
  IN_CLASSB_NSHIFT equ 16
  IN_CLASSB_HOST equ 0000ffffh
  IN_CLASSB_MAX equ 65536
  IN_CLASSC macro i
    exitm <(((i) and 0e0000000h) == 0c0000000h)>
  endm
  IN_CLASSC_NET equ 0ffffff00h
  IN_CLASSC_NSHIFT equ 8
  IN_CLASSC_HOST equ 000000ffh
  IN_CLASSD macro i
    exitm <(((i) and 0f0000000h) == 0e0000000h)>
  endm
  IN_CLASSD_NET equ 0f0000000h
  IN_CLASSD_NSHIFT equ 28
  IN_CLASSD_HOST equ 0fffffffh
  IN_MULTICAST macro i
    exitm <IN_CLASSD(i)>
  endm
  INADDR_ANY equ 00000000h
  INADDR_LOOPBACK equ 7f000001h
  INADDR_BROADCAST equ 0ffffffffh
  INADDR_NONE equ 0ffffffffh
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    SCOPE_LEVEL typedef SDWORD
    ScopeLevelInterface equ 1
    ScopeLevelLink equ 2
    ScopeLevelSubnet equ 3
    ScopeLevelAdmin equ 4
    ScopeLevelSite equ 5
    ScopeLevelOrganization equ 8
    ScopeLevelGlobal equ 14
    ScopeLevelCount equ 16

    SCOPE_ID struct
      union
        struct
          ANONYMOUS_REC5 record ANONYMOUS_REC5_Level:4, ANONYMOUS_REC5_Zone:28
          ANONYMOUS_REC5 <>
        ends
        Value ULONG ?
      ends
    SCOPE_ID ends
    PSCOPE_ID typedef ptr SCOPE_ID
    SCOPEID_UNSPECIFIED_INIT equ { 0 }
    SOCKADDR_IN struct
      if (_WIN32_WINNT lt 0600h)
        sin_family SWORD ?
      else
        sin_family ADDRESS_FAMILY ?
      endif
      sin_port USHORT ?
      sin_addr IN_ADDR <>
      sin_zero CHAR 8 dup (?)
    SOCKADDR_IN ends
    sockaddr_in typedef SOCKADDR_IN
    PSOCKADDR_IN typedef ptr SOCKADDR_IN
  endif
  if (_WIN32_WINNT ge 0601h)
    SOCKADDR_DL struct
      sdl_family ADDRESS_FAMILY ?
      sdl_data UCHAR 8 dup (?)
      sdl_zero UCHAR 4 dup (?)
    SOCKADDR_DL ends
    sockaddr_dl typedef SOCKADDR_DL
    PSOCKADDR_DL typedef ptr SOCKADDR_DL
  endif
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
  WSABUF struct
    len ULONG ?
    buf POINTER ?
  WSABUF ends
  _WSABUF typedef WSABUF
  LPWSABUF typedef ptr WSABUF
  WSAMSG struct
    name_ LPSOCKADDR ?
    namelen INT_ ?
    lpBuffers LPWSABUF ?
    if (_WIN32_WINNT ge 0600h)
      dwBufferCount ULONG ?
    else
      dwBufferCount DWORD ?
    endif
    Control WSABUF <>
    if (_WIN32_WINNT ge 0600h)
      dwFlags ULONG ?
    else
      dwFlags DWORD ?
    endif
  WSAMSG ends
  _WSAMSG typedef WSAMSG
  PWSAMSG typedef ptr WSAMSG
  LPWSAMSG typedef ptr WSAMSG
  if (_WIN32_WINNT ge 0600h)
    _WSACMSGHDR equ <cmsghdr>
  endif
  WSACMSGHDR struct
    cmsg_len SIZE_T ?
    cmsg_level INT_ ?
    cmsg_type INT_ ?
  WSACMSGHDR ends
  _WSACMSGHDR typedef WSACMSGHDR
  PWSACMSGHDR typedef ptr WSACMSGHDR
  LPWSACMSGHDR typedef ptr WSACMSGHDR
  if (_WIN32_WINNT ge 0600h)
    CMSGHDR typedef WSACMSGHDR
    PCMSGHDR typedef ptr WSACMSGHDR
  endif
  WSA_CMSGHDR_ALIGN macro length_
    exitm <(((length_) + TYPE_ALIGNMENT(WSACMSGHDR) - 1) and (not (TYPE_ALIGNMENT(WSACMSGHDR) - 1)))>
  endm
  WSA_CMSGDATA_ALIGN macro length_
    exitm <(((length_) + MAX_NATURAL_ALIGNMENT - 1) and (not (MAX_NATURAL_ALIGNMENT - 1)))>
  endm
  if (_WIN32_WINNT ge 0600h)
    CMSGHDR_ALIGN equ <WSA_CMSGHDR_ALIGN>
    CMSGDATA_ALIGN equ <WSA_CMSGDATA_ALIGN>
  endif
  WSA_CMSG_FIRSTHDR macro msg
    exitm <(((msg) - Control.len >= sizeof(WSACMSGHDR)) ? (LPWSACMSGHDR) (msg) - Control.buf : (LPWSACMSGHDR) NULL)>
  endm
  if (_WIN32_WINNT ge 0600h)
    CMSG_FIRSTHDR equ <WSA_CMSG_FIRSTHDR>
  endif
  WSA_CMSG_NXTHDR macro msg, cmsg
    exitm <(((cmsg) == NULL) ? WSA_CMSG_FIRSTHDR(msg) : ((((PUCHAR) (cmsg) + WSA_CMSGHDR_ALIGN((cmsg) - cmsg_len) + sizeof(WSACMSGHDR)) > (PUCHAR) ((msg) - Control.buf) + (msg) - Control.len) ? (LPWSACMSGHDR) NULL : (LPWSACMSGHDR) ((PUCHAR) (cmsg) + WSA_CMSGHDR_ALIGN((cmsg) - cmsg_len))))>
  endm
  if (_WIN32_WINNT ge 0600h)
    CMSG_NXTHDR equ <WSA_CMSG_NXTHDR>
  endif
  WSA_CMSG_DATA macro cmsg
    exitm <((PUCHAR) (cmsg) + WSA_CMSGDATA_ALIGN(sizeof(WSACMSGHDR)))>
  endm
  WSA_CMSG_SPACE macro length_
    exitm <(WSA_CMSGDATA_ALIGN(sizeof(WSACMSGHDR) + WSA_CMSGHDR_ALIGN(length_)))>
  endm
  if (_WIN32_WINNT ge 0600h)
    CMSG_SPACE equ <WSA_CMSG_SPACE>
  endif
  WSA_CMSG_LEN macro length_
    exitm <(WSA_CMSGDATA_ALIGN(sizeof(WSACMSGHDR)) + length_)>
  endm
  if (_WIN32_WINNT ge 0600h)
    CMSG_LEN equ <WSA_CMSG_LEN>
  endif
  MSG_TRUNC equ 0100h
  MSG_CTRUNC equ 0200h
  MSG_BCAST equ 0400h
  MSG_MCAST equ 0800h
  MSG_ERRQUEUE equ 1000h
  AI_PASSIVE equ 00000001h
  AI_CANONNAME equ 00000002h
  AI_NUMERICHOST equ 00000004h
  AI_NUMERICSERV equ 00000008h
  AI_DNS_ONLY equ 00000010h
  AI_FORCE_CLEAR_TEXT equ 00000020h
  AI_BYPASS_DNS_CACHE equ 00000040h
  AI_RETURN_TTL equ 00000080h
  AI_ALL equ 00000100h
  AI_ADDRCONFIG equ 00000400h
  AI_V4MAPPED equ 00000800h
  AI_NON_AUTHORITATIVE equ 00004000h
  AI_SECURE equ 00008000h
  AI_RETURN_PREFERRED_NAMES equ 00010000h
  AI_FQDN equ 00020000h
  AI_FILESERVER equ 00040000h
  AI_DISABLE_IDN_ENCODING equ 00080000h
  AI_SECURE_WITH_FALLBACK equ 00100000h
  AI_EXCLUSIVE_CUSTOM_SERVERS equ 00200000h
  AI_RETURN_RESPONSE_FLAGS equ 10000000h
  AI_REQUIRE_SECURE equ 20000000h
  AI_RESOLUTION_HANDLE equ 40000000h
  AI_EXTENDED equ 80000000h
  ADDRINFOA struct
    ai_flags SDWORD ?
    ai_family SDWORD ?
    ai_socktype SDWORD ?
    ai_protocol SDWORD ?
    ai_addrlen size_t ?
    ai_canonname POINTER ?
    ai_addr POINTER ?
    ai_next POINTER ?
  ADDRINFOA ends
  addrinfo typedef ADDRINFOA
  PADDRINFOA typedef ptr ADDRINFOA
  ADDRINFOW struct
    ai_flags SDWORD ?
    ai_family SDWORD ?
    ai_socktype SDWORD ?
    ai_protocol SDWORD ?
    ai_addrlen size_t ?
    ai_canonname PWSTR ?
    ai_addr POINTER ?
    ai_next POINTER ?
  ADDRINFOW ends
  addrinfoW typedef ADDRINFOW
  PADDRINFOW typedef ptr ADDRINFOW
  if (_WIN32_WINNT ge 0600h)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ADDRINFOEXA struct
        ai_flags SDWORD ?
        ai_family SDWORD ?
        ai_socktype SDWORD ?
        ai_protocol SDWORD ?
        ai_addrlen size_t ?
        ai_canonname POINTER ?
        ai_addr POINTER ?
        ai_blob POINTER ?
        ai_bloblen size_t ?
        ai_provider LPGUID ?
        ai_next POINTER ?
      ADDRINFOEXA ends
      addrinfoexA typedef ADDRINFOEXA
      PADDRINFOEXA typedef ptr ADDRINFOEXA
      LPADDRINFOEXA typedef ptr ADDRINFOEXA
    endif
    ADDRINFOEXW struct
      ai_flags SDWORD ?
      ai_family SDWORD ?
      ai_socktype SDWORD ?
      ai_protocol SDWORD ?
      ai_addrlen size_t ?
      ai_canonname PWSTR ?
      ai_addr POINTER ?
      ai_blob POINTER ?
      ai_bloblen size_t ?
      ai_provider LPGUID ?
      ai_next POINTER ?
    ADDRINFOEXW ends
    addrinfoexW typedef ADDRINFOEXW
    PADDRINFOEXW typedef ptr ADDRINFOEXW
    LPADDRINFOEXW typedef ptr ADDRINFOEXW
  endif
  if (_WIN32_WINNT ge 0602h)
    ADDRINFOEX_VERSION_2 equ 2
    ADDRINFOEX_VERSION_3 equ 3
    ADDRINFOEX_VERSION_4 equ 4
    ADDRINFOEX_VERSION_5 equ 5
    ADDRINFOEX_VERSION_6 equ 6
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ADDRINFOEX2A struct
        ai_flags SDWORD ?
        ai_family SDWORD ?
        ai_socktype SDWORD ?
        ai_protocol SDWORD ?
        ai_addrlen size_t ?
        ai_canonname POINTER ?
        ai_addr POINTER ?
        ai_blob POINTER ?
        ai_bloblen size_t ?
        ai_provider LPGUID ?
        ai_next POINTER ?
        ai_version SDWORD ?
        ai_fqdn POINTER ?
      ADDRINFOEX2A ends
      addrinfoex2A typedef ADDRINFOEX2A
      PADDRINFOEX2A typedef ptr ADDRINFOEX2A
      LPADDRINFOEX2A typedef ptr ADDRINFOEX2A
    endif
    ADDRINFOEX2W struct
      ai_flags SDWORD ?
      ai_family SDWORD ?
      ai_socktype SDWORD ?
      ai_protocol SDWORD ?
      ai_addrlen size_t ?
      ai_canonname PWSTR ?
      ai_addr POINTER ?
      ai_blob POINTER ?
      ai_bloblen size_t ?
      ai_provider LPGUID ?
      ai_next POINTER ?
      ai_version SDWORD ?
      ai_fqdn PWSTR ?
    ADDRINFOEX2W ends
    addrinfoex2W typedef ADDRINFOEX2W
    PADDRINFOEX2W typedef ptr ADDRINFOEX2W
    LPADDRINFOEX2W typedef ptr ADDRINFOEX2W
    ADDRINFOEX3 struct
      ai_flags SDWORD ?
      ai_family SDWORD ?
      ai_socktype SDWORD ?
      ai_protocol SDWORD ?
      ai_addrlen size_t ?
      ai_canonname PWSTR ?
      ai_addr POINTER ?
      ai_blob POINTER ?
      ai_bloblen size_t ?
      ai_provider LPGUID ?
      ai_next POINTER ?
      ai_version SDWORD ?
      ai_fqdn PWSTR ?
      ai_interfaceindex SDWORD ?
    ADDRINFOEX3 ends
    addrinfoex3 typedef ADDRINFOEX3
    PADDRINFOEX3 typedef ptr ADDRINFOEX3
    LPADDRINFOEX3 typedef ptr ADDRINFOEX3
    ADDRINFOEX4 struct
      ai_flags SDWORD ?
      ai_family SDWORD ?
      ai_socktype SDWORD ?
      ai_protocol SDWORD ?
      ai_addrlen size_t ?
      ai_canonname PWSTR ?
      ai_addr POINTER ?
      ai_blob POINTER ?
      ai_bloblen size_t ?
      ai_provider POINTER ?
      ai_next POINTER ?
      ai_version SDWORD ?
      ai_fqdn PWSTR ?
      ai_interfaceindex SDWORD ?
      ai_resolutionhandle HANDLE ?
    ADDRINFOEX4 ends
    addrinfoex4 typedef ADDRINFOEX4
    PADDRINFOEX4 typedef ptr ADDRINFOEX4
    LPADDRINFOEX4 typedef ptr ADDRINFOEX4
    ADDRINFOEX5 struct
      ai_flags SDWORD ?
      ai_family SDWORD ?
      ai_socktype SDWORD ?
      ai_protocol SDWORD ?
      ai_addrlen size_t ?
      ai_canonname PWSTR ?
      ai_addr POINTER ?
      ai_blob POINTER ?
      ai_bloblen size_t ?
      ai_provider POINTER ?
      ai_next POINTER ?
      ai_version SDWORD ?
      ai_fqdn PWSTR ?
      ai_interfaceindex SDWORD ?
      ai_resolutionhandle HANDLE ?
      ai_ttl DWORD ?
    ADDRINFOEX5 ends
    addrinfoex5 typedef ADDRINFOEX5
    PADDRINFOEX5 typedef ptr ADDRINFOEX5
    LPADDRINFOEX5 typedef ptr ADDRINFOEX5
    AI_DNS_SERVER_TYPE_UDP equ 1h
    AI_DNS_SERVER_TYPE_DOH equ 2h
    AI_DNS_SERVER_UDP_FALLBACK equ 1h
    ADDRINFO_DNS_SERVER struct
      ai_servertype DWORD ?
      ai_flags QWORD ?
      ai_addrlen DWORD ?
      ai_addr POINTER ?
      union
        ai_template PWSTR ?
      ends
    ADDRINFO_DNS_SERVER ends
    addrinfo_dns_server typedef ADDRINFO_DNS_SERVER
    AI_DNS_RESPONSE_SECURE equ 1h
    AI_DNS_RESPONSE_HOSTFILE equ 2h
    ADDRINFOEX6 struct
      ai_flags SDWORD ?
      ai_family SDWORD ?
      ai_socktype SDWORD ?
      ai_protocol SDWORD ?
      ai_addrlen size_t ?
      ai_canonname PWSTR ?
      ai_addr POINTER ?
      ai_blob POINTER ?
      ai_bloblen size_t ?
      ai_provider POINTER ?
      ai_next POINTER ?
      ai_version SDWORD ?
      ai_fqdn PWSTR ?
      ai_interfaceindex SDWORD ?
      ai_resolutionhandle HANDLE ?
      ai_ttl DWORD ?
      ai_numservers DWORD ?
      ai_servers POINTER ?
      ai_responseflags ULONG64 ?
    ADDRINFOEX6 ends
    addrinfoex6 typedef ADDRINFOEX6
    PADDRINFOEX6 typedef ptr ADDRINFOEX6
  endif
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
  NI_NOFQDN equ 01h
  NI_NUMERICHOST equ 02h
  NI_NAMEREQD equ 04h
  NI_NUMERICSERV equ 08h
  NI_DGRAM equ 10h
  NI_MAXHOST equ 1025
  NI_MAXSERV equ 32
  ifdef __cplusplus
    ;[...]
  endif
endif
