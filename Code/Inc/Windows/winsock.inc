;Include file created by h2incX, Version B.01.01, 29/10/2018 18:21
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\winsock.h', last modified: 19/04/2018 09:44
;Creation parameters: 

include winapifamily.inc
ifndef _WINSOCKAPI_
  _WINSOCKAPI_ equ <>
  if _MSC_VER gt 1000
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef _INC_WINDOWS
      include windows.inc
    endif
    if _MSC_VER ge 1200
    endif
    u_char typedef BYTE
    u_short typedef WORD
    u_int typedef DWORD
    u_long typedef DWORD
    SOCKET typedef UINT_PTR
    ifndef FD_SETSIZE
      FD_SETSIZE equ 64
    endif
    fd_set struct
      fd_count u_int ?
      fd_array SOCKET FD_SETSIZE dup (?)
    fd_set ends
    ifdef __cplusplus
      ;[...]
    endif
    __WSAFDIsSet proto WIN_STD_CALL_CONV :SOCKET, :ptr fd_set
    ifdef __cplusplus
      ;[...]
    endif
    FD_CLR macro fd, set
      exitm <do { u_int __i ; for (__i = 0 ; __i < ((fd_set FAR *) (set)) - fd_count ; __i +) { if (((fd_set FAR *) (set)) - fd_array [ __i ] == fd) { while (__i < ((fd_set FAR *) (set)) - fd_count - 1) { ((fd_set FAR *) (set)) - fd_array [ __i ] = ((fd_set FAR *) (set)) - fd_array [ __i + 1 ] ; __i + ; } ((fd_set FAR *) (set)) - fd_count - ; break ; } } } while (0)>
    endm
    FD_SET macro fd, set
      exitm <do { if (((fd_set FAR *) (set)) - fd_count < FD_SETSIZE) ((fd_set FAR *) (set)) - fd_array [ ((fd_set FAR *) (set)) - fd_count + ] = (fd) ; } while (0)>
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
    IPPROTO_IP equ 0
    IPPROTO_ICMP equ 1
    IPPROTO_IGMP equ 2
    IPPROTO_GGP equ 3
    IPPROTO_TCP equ 6
    IPPROTO_PUP equ 12
    IPPROTO_UDP equ 17
    IPPROTO_IDP equ 22
    IPPROTO_ND equ 77
    IPPROTO_RAW equ 255
    IPPROTO_MAX equ 256
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
    include inaddr.inc
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
    INADDR_ANY equ 00000000h
    INADDR_LOOPBACK equ 7f000001h
    INADDR_BROADCAST equ 0ffffffffh
    INADDR_NONE equ 0ffffffffh
    sockaddr_in struct
      sin_family SWORD ?
      sin_port u_short ?
      sin_addr in_addr <>
      sin_zero SBYTE 8 dup (?)
    sockaddr_in ends
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
    IP_OPTIONS equ 1
    IP_MULTICAST_IF equ 2
    IP_MULTICAST_TTL equ 3
    IP_MULTICAST_LOOP equ 4
    IP_ADD_MEMBERSHIP equ 5
    IP_DROP_MEMBERSHIP equ 6
    IP_TTL equ 7
    IP_TOS equ 8
    IP_DONTFRAGMENT equ 9
    IP_DEFAULT_MULTICAST_TTL equ 1
    IP_DEFAULT_MULTICAST_LOOP equ 1
    IP_MAX_MEMBERSHIPS equ 20
    ip_mreq struct
      imr_multiaddr in_addr <>
      imr_interface in_addr <>
    ip_mreq ends
    INVALID_SOCKET equ (not 0)
    SOCKET_ERROR equ -1
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
    SO_DONTLINGER equ <(u_int) (not SO_LINGER)>
    SO_SNDBUF equ 1001h
    SO_RCVBUF equ 1002h
    SO_SNDLOWAT equ 1003h
    SO_RCVLOWAT equ 1004h
    SO_SNDTIMEO equ 1005h
    SO_RCVTIMEO equ 1006h
    SO_ERROR equ 1007h
    SO_TYPE equ 1008h
    SO_CONNDATA equ 7000h
    SO_CONNOPT equ 7001h
    SO_DISCDATA equ 7002h
    SO_DISCOPT equ 7003h
    SO_CONNDATALEN equ 7004h
    SO_CONNOPTLEN equ 7005h
    SO_DISCDATALEN equ 7006h
    SO_DISCOPTLEN equ 7007h
    SO_OPENTYPE equ 7008h
    SO_SYNCHRONOUS_ALERT equ 10h
    SO_SYNCHRONOUS_NONALERT equ 20h
    SO_MAXDG equ 7009h
    SO_MAXPATHDG equ 700Ah
    SO_UPDATE_ACCEPT_CONTEXT equ 700Bh
    SO_CONNECT_TIME equ 700Ch
    TCP_NODELAY equ 0001h
    TCP_BSDURGENT equ 7000h
    AF_UNSPEC equ 0
    AF_UNIX equ 1
    AF_INET equ 2
    AF_IMPLINK equ 3
    AF_PUP equ 4
    AF_CHAOS equ 5
    AF_IPX equ 6
    AF_NS equ 6
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
    AF_MAX equ 22
    sockaddr struct
      sa_family u_short ?
      sa_data SBYTE 14 dup (?)
    sockaddr ends
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
    PF_MAX equ <AF_MAX>
    linger struct
      l_onoff u_short ?
      l_linger u_short ?
    linger ends
    SOL_SOCKET equ 0ffffh
    SOMAXCONN equ 5
    MSG_OOB equ 1h
    MSG_PEEK equ 2h
    MSG_DONTROUTE equ 4h
    MSG_MAXIOVLEN equ 16
    MSG_PARTIAL equ 8000h
    MAXGETHOSTSTRUCT equ 1024
    FD_READ equ 01h
    FD_WRITE equ 02h
    FD_OOB equ 04h
    FD_ACCEPT equ 08h
    FD_CONNECT equ 10h
    FD_CLOSE equ 20h
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
      WSAEDISCON equ (WSABASEERR + 101)
      WSASYSNOTREADY equ (WSABASEERR + 91)
      WSAVERNOTSUPPORTED equ (WSABASEERR + 92)
      WSANOTINITIALISED equ (WSABASEERR + 93)
      WSAHOST_NOT_FOUND equ (WSABASEERR + 1001)
      WSATRY_AGAIN equ (WSABASEERR + 1002)
      WSANO_RECOVERY equ (WSABASEERR + 1003)
      WSANO_DATA equ (WSABASEERR + 1004)
      WSA_SECURE_HOST_NOT_FOUND equ (WSABASEERR + 1032)
      WSA_IPSEC_NAME_POLICY_ERROR equ (WSABASEERR + 1033)
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
    ifdef __cplusplus
      ;[...]
    endif
    accept proto WIN_STD_CALL_CONV :SOCKET, :ptr sockaddr, :ptr SDWORD
    bind proto WIN_STD_CALL_CONV :SOCKET, :ptr sockaddr, :SDWORD
    closesocket proto WIN_STD_CALL_CONV :SOCKET
    connect proto WIN_STD_CALL_CONV :SOCKET, :ptr sockaddr, :SDWORD
    ioctlsocket proto WIN_STD_CALL_CONV :SOCKET, :SDWORD, :ptr u_long
    getpeername proto WIN_STD_CALL_CONV :SOCKET, :ptr sockaddr, :ptr SDWORD
    getsockname proto WIN_STD_CALL_CONV :SOCKET, :ptr sockaddr, :ptr SDWORD
    getsockopt proto WIN_STD_CALL_CONV :SOCKET, :SDWORD, :SDWORD, :ptr SBYTE, :ptr SDWORD
    htonl proto WIN_STD_CALL_CONV :u_long
    htons proto WIN_STD_CALL_CONV :u_short
    inet_addr proto WIN_STD_CALL_CONV :ptr SBYTE
    inet_ntoa proto WIN_STD_CALL_CONV :in_addr
    listen proto WIN_STD_CALL_CONV :SOCKET, :SDWORD
    ntohl proto WIN_STD_CALL_CONV :u_long
    ntohs proto WIN_STD_CALL_CONV :u_short
    recv proto WIN_STD_CALL_CONV :SOCKET, :ptr SBYTE, :SDWORD, :SDWORD
    recvfrom proto WIN_STD_CALL_CONV :SOCKET, :ptr SBYTE, :SDWORD, :SDWORD, :ptr sockaddr, :ptr SDWORD
    select proto WIN_STD_CALL_CONV :SDWORD, :ptr fd_set, :ptr fd_set, :ptr fd_set, :ptr timeval
    send proto WIN_STD_CALL_CONV :SOCKET, :ptr SBYTE, :SDWORD, :SDWORD
    sendto proto WIN_STD_CALL_CONV :SOCKET, :ptr SBYTE, :SDWORD, :SDWORD, :ptr sockaddr, :SDWORD
    setsockopt proto WIN_STD_CALL_CONV :SOCKET, :SDWORD, :SDWORD, :ptr SBYTE, :SDWORD
    shutdown proto WIN_STD_CALL_CONV :SOCKET, :SDWORD
    socket proto WIN_STD_CALL_CONV :SDWORD, :SDWORD, :SDWORD
    gethostbyaddr proto WIN_STD_CALL_CONV :ptr SBYTE, :SDWORD, :SDWORD
    gethostbyname proto WIN_STD_CALL_CONV :ptr SBYTE
    gethostname proto WIN_STD_CALL_CONV :ptr SBYTE, :SDWORD
    getservbyport proto WIN_STD_CALL_CONV :SDWORD, :ptr SBYTE
    getservbyname proto WIN_STD_CALL_CONV :ptr SBYTE, :ptr SBYTE
    getprotobynumber proto WIN_STD_CALL_CONV :SDWORD
    getprotobyname proto WIN_STD_CALL_CONV :ptr SBYTE
    WSAStartup proto WIN_STD_CALL_CONV :WORD, :LPWSADATA
    WSACleanup proto WIN_STD_CALL_CONV
    WSASetLastError proto WIN_STD_CALL_CONV :SDWORD
    WSAGetLastError proto WIN_STD_CALL_CONV
    WSAIsBlocking proto WIN_STD_CALL_CONV
    WSAUnhookBlockingHook proto WIN_STD_CALL_CONV
    WSASetBlockingHook proto WIN_STD_CALL_CONV :FARPROC
    WSACancelBlockingCall proto WIN_STD_CALL_CONV
    WSAAsyncGetServByName proto WIN_STD_CALL_CONV :HWND, :u_int, :ptr SBYTE, :ptr SBYTE, :ptr SBYTE, :SDWORD
    WSAAsyncGetServByPort proto WIN_STD_CALL_CONV :HWND, :u_int, :SDWORD, :ptr SBYTE, :ptr SBYTE, :SDWORD
    WSAAsyncGetProtoByName proto WIN_STD_CALL_CONV :HWND, :u_int, :ptr SBYTE, :ptr SBYTE, :SDWORD
    WSAAsyncGetProtoByNumber proto WIN_STD_CALL_CONV :HWND, :u_int, :SDWORD, :ptr SBYTE, :SDWORD
    WSAAsyncGetHostByName proto WIN_STD_CALL_CONV :HWND, :u_int, :ptr SBYTE, :ptr SBYTE, :SDWORD
    WSAAsyncGetHostByAddr proto WIN_STD_CALL_CONV :HWND, :u_int, :ptr SBYTE, :SDWORD, :SDWORD, :ptr SBYTE, :SDWORD
    WSACancelAsyncRequest proto WIN_STD_CALL_CONV :HANDLE
    WSAAsyncSelect proto WIN_STD_CALL_CONV :SOCKET, :HWND, :u_int, :SDWORD
    WSARecvEx proto WIN_STD_CALL_CONV :SOCKET, :ptr SBYTE, :SDWORD, :ptr SDWORD
    TRANSMIT_FILE_BUFFERS struct
      Head PVOID ?
      HeadLength DWORD ?
      Tail PVOID ?
      TailLength DWORD ?
    TRANSMIT_FILE_BUFFERS ends
    _TRANSMIT_FILE_BUFFERS typedef TRANSMIT_FILE_BUFFERS
    PTRANSMIT_FILE_BUFFERS typedef ptr TRANSMIT_FILE_BUFFERS
    LPTRANSMIT_FILE_BUFFERS typedef ptr TRANSMIT_FILE_BUFFERS
    
    TF_DISCONNECT equ 01h
    TF_REUSE_SOCKET equ 02h
    TF_WRITE_BEHIND equ 04h
    TransmitFile proto WIN_STD_CALL_CONV :SOCKET, :HANDLE, :DWORD, :DWORD, :LPOVERLAPPED, :LPTRANSMIT_FILE_BUFFERS, :DWORD
    AcceptEx proto WIN_STD_CALL_CONV :SOCKET, :SOCKET, :PVOID, :DWORD, :DWORD, :DWORD, :LPDWORD, :LPOVERLAPPED
    GetAcceptExSockaddrs proto WIN_STD_CALL_CONV :PVOID, :DWORD, :DWORD, :DWORD, :ptr ptr sockaddr, :LPINT, :ptr ptr sockaddr, :LPINT
    ifdef __cplusplus
      ;[...]
    endif
    SOCKADDR typedef sockaddr
    
    PSOCKADDR typedef ptr sockaddr
    
    LPSOCKADDR typedef ptr sockaddr
    
    SOCKADDR_IN typedef sockaddr_in
    
    PSOCKADDR_IN typedef ptr sockaddr_in
    
    LPSOCKADDR_IN typedef ptr sockaddr_in
    
    LINGER typedef linger
    
    PLINGER typedef ptr linger
    
    LPLINGER typedef ptr linger
    
    FD_SET_ typedef fd_set
    
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
    if (_WIN32_WINNT ge 0501h)
      ifdef IPV6STRICT
        .err <WINSOCK2 required.>
      endif
    endif
    if _MSC_VER ge 1200
    endif
  endif
endif

