;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\winsock.h
;             Created on (UTC) 06/04/2024 06:16:03
;             Last modified on (UTC) 21/02/2024 18:15:28

include winapifamily.inc
;* WINSOCK.H--definitions to be used with the WINSOCK.DLL
;* Copyright (c) Microsoft Corporation. All rights reserved.
;*
;* This header file corresponds to version 1.1 of the Windows Sockets specification.
;*
;* This file includes parts which are Copyright (c) 1982-1986 Regents
;* of the University of California.  All rights reserved.  The
;* Berkeley Software License Agreement specifies the terms and
;* conditions for redistribution.
;*
;*
ifndef _WINSOCKAPI_
  _WINSOCKAPI_ equ <>
  if _MSC_VER gt 1000
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ;*
    ;* Pull in WINDOWS.H if necessary
    ;*
    ifndef _INC_WINDOWS
      include windows.inc
      ;* _INC_WINDOWS *
    endif
    if _MSC_VER ge 1200
      ; padding added after data member
    endif
    ;*
    ;* Basic system type definitions, taken from the BSD file sys/types.h.
    ;*
    u_char typedef BYTE
    u_short typedef WORD
    u_int typedef DWORD
    u_long typedef DWORD
    ;*
    ;* The new type to be used in all
    ;* instances which refer to sockets.
    ;*
    SOCKET typedef UINT_PTR
    ;*
    ;* Select uses arrays of SOCKETs.  These macros manipulate such
    ;* arrays.  FD_SETSIZE may be defined by the user before including
    ;* this file, but the default here should be >= 64.
    ;*
    ;* CAVEAT IMPLEMENTOR and USER: THESE MACROS AND TYPES MUST BE
    ;* INCLUDED IN WINSOCK.H EXACTLY AS SHOWN HERE.
    ;*
    ifndef FD_SETSIZE
      FD_SETSIZE equ 64
      ;* FD_SETSIZE *
    endif
    fd_set struct
      fd_count u_int ?
      ;* how many are SET? *
      fd_array SOCKET FD_SETSIZE dup (?)
      ;* an array of SOCKETs *
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
    ;*
    ;* Structure used in select() call, taken from the BSD file sys/time.h.
    ;*
    timeval struct
      tv_sec SDWORD ?
      ;* seconds *
      tv_usec SDWORD ?
      ;* and microseconds *
    timeval ends
    ;*
    ;* Operations on timevals.
    ;*
    ;* NB: timercmp does not work for >= or <=.
    ;*
    timerisset macro tvp
      exitm <((tvp) - tv_sec or (tvp) - tv_usec)>
    endm
    timercmp macro tvp, uvp, cmp_
      exitm <((tvp) - tv_sec cmp_ (uvp) - tv_sec or (tvp) - tv_sec == (uvp) - tv_sec and (tvp) - tv_usec cmp_ (uvp) - tv_usec)>
    endm
    timerclear macro tvp
      exitm <(tvp) - tv_sec = (tvp) - tv_usec = 0>
    endm
    ;*
    ;* Commands for ioctlsocket(),  taken from the BSD file fcntl.h.
    ;*
    ;*
    ;* Ioctl's have the command encoded in the lower word,
    ;* and the size of any in or out parameters in the upper
    ;* word.  The high 2 bits of the upper word are used
    ;* to encode the in/out status of the parameter; for now
    ;* we restrict parameters to at most 128 bytes.
    ;*
    ;* parameters must be < 128 bytes *
    IOCPARM_MASK equ 7fh
    ;* no parameters *
    IOC_VOID equ 20000000h
    ;* copy out parameters *
    IOC_OUT equ 40000000h
    ;* copy in parameters *
    IOC_IN equ 80000000h
    IOC_INOUT equ <(IOC_IN or IOC_OUT)>
    ;* 0x20000000 distinguishes new &
    ;old ioctl's *
    _IO macro x, y
      exitm <(IOC_VOID or ((x) shl 8) or (y))>
    endm
    _IOR macro x, y, t
      exitm <(IOC_OUT or ((sizeof(t) and IOCPARM_MASK) shl 16) or ((x) shl 8) or (y))>
    endm
    _IOW macro x, y, t
      exitm <(IOC_IN or ((sizeof(t) and IOCPARM_MASK) shl 16) or ((x) shl 8) or (y))>
    endm
    ;* get # bytes to read *
    FIONREAD equ _IOR('f', 127, u_long)
    ;* set/clear non-blocking i/o *
    FIONBIO equ _IOW('f', 126, u_long)
    ;* set/clear async i/o *
    FIOASYNC equ _IOW('f', 125, u_long)
    ;* Socket I/O Controls *
    ;* set high watermark *
    SIOCSHIWAT equ _IOW('s', 0, u_long)
    ;* get high watermark *
    SIOCGHIWAT equ _IOR('s', 1, u_long)
    ;* set low watermark *
    SIOCSLOWAT equ _IOW('s', 2, u_long)
    ;* get low watermark *
    SIOCGLOWAT equ _IOR('s', 3, u_long)
    ;* at oob mark? *
    SIOCATMARK equ _IOR('s', 7, u_long)
    ;*
    ;* Structures returned by network data base library, taken from the
    ;* BSD file netdb.h.  All addresses are supplied in host order, and
    ;* returned in network order (suitable for use in system calls).
    ;*
    hostent struct
      h_name POINTER ?
      ;* official name of host *
      h_aliases POINTER ?
      ;* alias list *
      h_addrtype SWORD ?
      ;* host address type *
      h_length SWORD ?
      ;* length of address *
      h_addr_list POINTER ?
      ;* list of addresses *
      ;* address, for backward compat *
      h_addr equ h_addr_list [ 0 ]
    hostent ends
    ;*
    ;* It is assumed here that a network number
    ;* fits in 32 bits.
    ;*
    netent struct
      n_name POINTER ?
      ;* official name of net *
      n_aliases POINTER ?
      ;* alias list *
      n_addrtype SWORD ?
      ;* net address type *
      n_net DWORD ?
      ;* network # *
    netent ends
    servent struct
      s_name POINTER ?
      ;* official service name *
      s_aliases POINTER ?
      ;* alias list *
      ifdef _WIN64
        s_proto POINTER ?
        ;* protocol to use *
        s_port SWORD ?
        ;* port # *
      else
        s_port SWORD ?
        ;* port # *
        s_proto POINTER ?
        ;* protocol to use *
      endif
    servent ends
    protoent struct
      p_name POINTER ?
      ;* official protocol name *
      p_aliases POINTER ?
      ;* alias list *
      p_proto SWORD ?
      ;* protocol # *
    protoent ends
    ;*
    ;* Constants and structures defined by the internet system,
    ;* Per RFC 790, September 1981, taken from the BSD file netinet/in.h.
    ;*
    ;*
    ;* Protocols
    ;*
    ;* dummy for IP *
    IPPROTO_IP equ 0
    ;* control message protocol *
    IPPROTO_ICMP equ 1
    ;* group management protocol *
    IPPROTO_IGMP equ 2
    ;* gateway^2 (deprecated) *
    IPPROTO_GGP equ 3
    ;* tcp *
    IPPROTO_TCP equ 6
    ;* pup *
    IPPROTO_PUP equ 12
    ;* user datagram protocol *
    IPPROTO_UDP equ 17
    ;* xns idp *
    IPPROTO_IDP equ 22
    ;* UNOFFICIAL net disk proto *
    IPPROTO_ND equ 77
    ;* raw IP packet *
    IPPROTO_RAW equ 255
    IPPROTO_MAX equ 256
    ;*
    ;* Port/socket numbers: network standard functions
    ;*
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
    ;*
    ;* Port/socket numbers: host specific functions
    ;*
    IPPORT_TFTP equ 69
    IPPORT_RJE equ 77
    IPPORT_FINGER equ 79
    IPPORT_TTYLINK equ 87
    IPPORT_SUPDUP equ 95
    ;*
    ;* UNIX TCP sockets
    ;*
    IPPORT_EXECSERVER equ 512
    IPPORT_LOGINSERVER equ 513
    IPPORT_CMDSERVER equ 514
    IPPORT_EFSSERVER equ 520
    ;*
    ;* UNIX UDP sockets
    ;*
    IPPORT_BIFFUDP equ 512
    IPPORT_WHOSERVER equ 513
    IPPORT_ROUTESERVER equ 520
    ;* 520+1 also used *
    ;*
    ;* Ports < IPPORT_RESERVED are reserved for
    ;* privileged processes (e.g. root).
    ;*
    IPPORT_RESERVED equ 1024
    ;*
    ;* Link numbers
    ;*
    IMPLINK_IP equ 155
    IMPLINK_LOWEXPER equ 156
    IMPLINK_HIGHEXPER equ 158
    include inaddr.inc
    ;*
    ;* Definitions of bits in internet address integers.
    ;* On subnets, the decomposition of addresses to host and net parts
    ;* is done according to subnet mask, not the masks here.
    ;*
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
    ;*
    ;* Socket address, internet style.
    ;*
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
    ;*
    ;* Options for use with [gs]etsockopt at the IP level.
    ;*
    ;* set/get IP per-packet options    *
    IP_OPTIONS equ 1
    ;* set/get IP multicast interface   *
    IP_MULTICAST_IF equ 2
    ;* set/get IP multicast timetolive  *
    IP_MULTICAST_TTL equ 3
    ;* set/get IP multicast loopback    *
    IP_MULTICAST_LOOP equ 4
    ;* add  an IP group membership      *
    IP_ADD_MEMBERSHIP equ 5
    ;* drop an IP group membership      *
    IP_DROP_MEMBERSHIP equ 6
    ;* set/get IP Time To Live          *
    IP_TTL equ 7
    ;* set/get IP Type Of Service       *
    IP_TOS equ 8
    ;* set/get IP Don't Fragment flag   *
    IP_DONTFRAGMENT equ 9
    ;* normally limit m'casts to 1 hop  *
    IP_DEFAULT_MULTICAST_TTL equ 1
    ;* normally hear sends if a member  *
    IP_DEFAULT_MULTICAST_LOOP equ 1
    ;* per socket; must fit in one mbuf *
    IP_MAX_MEMBERSHIPS equ 20
    ;*
    ;* Argument structure for IP_ADD_MEMBERSHIP and IP_DROP_MEMBERSHIP.
    ;*
    ip_mreq struct
      imr_multiaddr in_addr <>
      ;* IP multicast address of group *
      imr_interface in_addr <>
      ;* local IP address of interface *
    ip_mreq ends
    ;*
    ;* Definitions related to sockets: types, address families, options,
    ;* taken from the BSD file sys/socket.h.
    ;*
    ;*
    ;* This is used instead of -1, since the
    ;* SOCKET type is unsigned.
    ;*
    INVALID_SOCKET equ (not 0)
    SOCKET_ERROR equ (- 1)
    ;*
    ;* Types
    ;*
    ;* stream socket *
    SOCK_STREAM equ 1
    ;* datagram socket *
    SOCK_DGRAM equ 2
    ;* raw-protocol interface *
    SOCK_RAW equ 3
    ;* reliably-delivered message *
    SOCK_RDM equ 4
    ;* sequenced packet stream *
    SOCK_SEQPACKET equ 5
    ;*
    ;* Option flags per-socket.
    ;*
    ;* turn on debugging info recording *
    SO_DEBUG equ 0001h
    ;* socket has had listen() *
    SO_ACCEPTCONN equ 0002h
    ;* allow local address reuse *
    SO_REUSEADDR equ 0004h
    ;* keep connections alive *
    SO_KEEPALIVE equ 0008h
    ;* just use interface addresses *
    SO_DONTROUTE equ 0010h
    ;* permit sending of broadcast msgs *
    SO_BROADCAST equ 0020h
    ;* bypass hardware when possible *
    SO_USELOOPBACK equ 0040h
    ;* linger on close if data present *
    SO_LINGER equ 0080h
    ;* leave received OOB data in line *
    SO_OOBINLINE equ 0100h
    SO_DONTLINGER equ <(u_int) (not SO_LINGER)>
    ;*
    ;* Additional options.
    ;*
    ;* send buffer size *
    SO_SNDBUF equ 1001h
    ;* receive buffer size *
    SO_RCVBUF equ 1002h
    ;* send low-water mark *
    SO_SNDLOWAT equ 1003h
    ;* receive low-water mark *
    SO_RCVLOWAT equ 1004h
    ;* send timeout *
    SO_SNDTIMEO equ 1005h
    ;* receive timeout *
    SO_RCVTIMEO equ 1006h
    ;* get error status and clear *
    SO_ERROR equ 1007h
    ;* get socket type *
    SO_TYPE equ 1008h
    ;*
    ;* Options for connect and disconnect data and options.  Used only by
    ;* non-TCP/IP transports such as DECNet, OSI TP4, etc.
    ;*
    SO_CONNDATA equ 7000h
    SO_CONNOPT equ 7001h
    SO_DISCDATA equ 7002h
    SO_DISCOPT equ 7003h
    SO_CONNDATALEN equ 7004h
    SO_CONNOPTLEN equ 7005h
    SO_DISCDATALEN equ 7006h
    SO_DISCOPTLEN equ 7007h
    ;*
    ;* Option for opening sockets for synchronous access.
    ;*
    SO_OPENTYPE equ 7008h
    SO_SYNCHRONOUS_ALERT equ 10h
    SO_SYNCHRONOUS_NONALERT equ 20h
    ;*
    ;* Other NT-specific options.
    ;*
    SO_MAXDG equ 7009h
    SO_MAXPATHDG equ 700Ah
    SO_UPDATE_ACCEPT_CONTEXT equ 700Bh
    SO_CONNECT_TIME equ 700Ch
    ;*
    ;* TCP options.
    ;*
    TCP_NODELAY equ 0001h
    TCP_BSDURGENT equ 7000h
    ;*
    ;* Address families.
    ;*
    ;* unspecified *
    AF_UNSPEC equ 0
    ;* local to host (pipes, portals) *
    AF_UNIX equ 1
    ;* internetwork: UDP, TCP, etc. *
    AF_INET equ 2
    ;* arpanet imp addresses *
    AF_IMPLINK equ 3
    ;* pup protocols: e.g. BSP *
    AF_PUP equ 4
    ;* mit CHAOS protocols *
    AF_CHAOS equ 5
    ;* IPX and SPX *
    AF_IPX equ 6
    ;* XEROX NS protocols *
    AF_NS equ 6
    ;* ISO protocols *
    AF_ISO equ 7
    ;* OSI is ISO *
    AF_OSI equ <AF_ISO>
    ;* european computer manufacturers *
    AF_ECMA equ 8
    ;* datakit protocols *
    AF_DATAKIT equ 9
    ;* CCITT protocols, X.25 etc *
    AF_CCITT equ 10
    ;* IBM SNA *
    AF_SNA equ 11
    ;* DECnet *
    AF_DECnet equ 12
    ;* Direct data link interface *
    AF_DLI equ 13
    ;* LAT *
    AF_LAT equ 14
    ;* NSC Hyperchannel *
    AF_HYLINK equ 15
    ;* AppleTalk *
    AF_APPLETALK equ 16
    ;* NetBios-style addresses *
    AF_NETBIOS equ 17
    ;* VoiceView *
    AF_VOICEVIEW equ 18
    ;* FireFox *
    AF_FIREFOX equ 19
    ;* Somebody is using this! *
    AF_UNKNOWN1 equ 20
    ;* Banyan *
    AF_BAN equ 21
    AF_MAX equ 22
    ;*
    ;* Structure used by kernel to store most
    ;* addresses.
    ;*
    sockaddr struct
      sa_family u_short ?
      ;* address family *
      sa_data SBYTE 14 dup (?)
      ;* up to 14 bytes of direct address *
    sockaddr ends
    ;*
    ;* Structure used by kernel to pass protocol
    ;* information in raw sockets.
    ;*
    sockproto struct
      sp_family u_short ?
      ;* address family *
      sp_protocol u_short ?
      ;* protocol *
    sockproto ends
    ;*
    ;* Protocol families, same as address families for now.
    ;*
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
    ;*
    ;* Structure used for manipulating linger option.
    ;*
    linger struct
      l_onoff u_short ?
      ;* option on/off *
      l_linger u_short ?
      ;* linger time *
    linger ends
    ;*
    ;* Level number for (get/set)sockopt() to apply to socket itself.
    ;*
    ;* options for socket level *
    SOL_SOCKET equ 0ffffh
    ;*
    ;* Maximum queue length specifiable by listen.
    ;*
    SOMAXCONN equ 5
    ;* process out-of-band data *
    MSG_OOB equ 1h
    ;* peek at incoming message *
    MSG_PEEK equ 2h
    ;* send without using routing tables *
    MSG_DONTROUTE equ 4h
    MSG_MAXIOVLEN equ 16
    ;* partial send or recv for message xport *
    MSG_PARTIAL equ 8000h
    ;*
    ;* Define constant based on rfc883, used by gethostbyxxxx() calls.
    ;*
    MAXGETHOSTSTRUCT equ 1024
    ;*
    ;* Define flags to be used with the WSAAsyncSelect() call.
    ;*
    FD_READ equ 01h
    FD_WRITE equ 02h
    FD_OOB equ 04h
    FD_ACCEPT equ 08h
    FD_CONNECT equ 10h
    FD_CLOSE equ 20h
    ;*
    ;* WinSock error codes are also defined in winerror.h
    ;* Hence the IFDEF.
    ;*
    ifndef WSABASEERR
      ;*
      ;* All Windows Sockets error constants are biased by WSABASEERR from
      ;* the "normal"
      ;*
      WSABASEERR equ 10000
      ;*
      ;* Windows Sockets definitions of regular Microsoft C error constants
      ;*
      WSAEINTR equ (WSABASEERR + 4)
      WSAEBADF equ (WSABASEERR + 9)
      WSAEACCES equ (WSABASEERR + 13)
      WSAEFAULT equ (WSABASEERR + 14)
      WSAEINVAL equ (WSABASEERR + 22)
      WSAEMFILE equ (WSABASEERR + 24)
      ;*
      ;* Windows Sockets definitions of regular Berkeley error constants
      ;*
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
      ;*
      ;* Extended Windows Sockets error constant definitions
      ;*
      WSASYSNOTREADY equ (WSABASEERR + 91)
      WSAVERNOTSUPPORTED equ (WSABASEERR + 92)
      WSANOTINITIALISED equ (WSABASEERR + 93)
      ;*
      ;* Error return codes from gethostbyname() and gethostbyaddr()
      ;* (when using the resolver). Note that these errors are
      ;* retrieved via WSAGetLastError() and must therefore follow
      ;* the rules for avoiding clashes with error numbers from
      ;* specific implementations or language run-time systems.
      ;* For this reason the codes are based at WSABASEERR+1001.
      ;* Note also that [WSA]NO_ADDRESS is defined only for
      ;* compatibility purposes.
      ;*
      ;* Authoritative Answer: Host not found *
      WSAHOST_NOT_FOUND equ (WSABASEERR + 1001)
      ;* Non-Authoritative: Host not found, or SERVERFAIL *
      WSATRY_AGAIN equ (WSABASEERR + 1002)
      ;* Non recoverable errors, FORMERR, REFUSED, NOTIMP *
      WSANO_RECOVERY equ (WSABASEERR + 1003)
      ;* Valid name, no data record of requested type *
      WSANO_DATA equ (WSABASEERR + 1004)
      ;* Authoritative Answer: Host not found Securely *
      WSA_SECURE_HOST_NOT_FOUND equ (WSABASEERR + 1032)
      ;* Name based IPSEC policy could not be added*
      WSA_IPSEC_NAME_POLICY_ERROR equ (WSABASEERR + 1033)
      ;*
      ;* WinSock error codes are also defined in winerror.h
      ;* Hence the IFDEF.
      ;*
      ;* ifdef WSABASEERR *
    endif
    ;*
    ;* Compatibility macros.
    ;*
    h_errno equ <WSAGetLastError ()>
    HOST_NOT_FOUND equ <WSAHOST_NOT_FOUND>
    TRY_AGAIN equ <WSATRY_AGAIN>
    NO_RECOVERY equ <WSANO_RECOVERY>
    NO_DATA equ <WSANO_DATA>
    ;* no address, look for MX record *
    WSANO_ADDRESS equ <WSANO_DATA>
    NO_ADDRESS equ <WSANO_ADDRESS>
    ;*
    ;* Windows Sockets errors redefined as regular Berkeley error constants.
    ;* These are commented out in Windows NT to avoid conflicts with errno.h.
    ;* Use the WSA constants instead.
    ;*
    if 0
      ;[...]
    endif
    ;* Socket function prototypes *
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
    ;* Database function prototypes *
    gethostbyaddr proto WIN_STD_CALL_CONV :ptr SBYTE, :SDWORD, :SDWORD
    gethostbyname proto WIN_STD_CALL_CONV :ptr SBYTE
    gethostname proto WIN_STD_CALL_CONV :ptr SBYTE, :SDWORD
    getservbyport proto WIN_STD_CALL_CONV :SDWORD, :ptr SBYTE
    getservbyname proto WIN_STD_CALL_CONV :ptr SBYTE, :ptr SBYTE
    getprotobynumber proto WIN_STD_CALL_CONV :SDWORD
    getprotobyname proto WIN_STD_CALL_CONV :ptr SBYTE
    ;* Microsoft Windows Extension function prototypes *
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
      Head POINTER ?
      HeadLength DWORD ?
      Tail POINTER ?
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
    ;* Microsoft Windows Extended data types *
    SOCKADDR typedef sockaddr
    PSOCKADDR typedef ptr sockaddr
    LPSOCKADDR typedef ptr sockaddr
    SOCKADDR_IN typedef sockaddr_in
    PSOCKADDR_IN typedef ptr sockaddr_in
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
    ;*
    ;* Windows message parameter composition and decomposition
    ;* macros.
    ;*
    ;* WSAMAKEASYNCREPLY is intended for use by the Windows Sockets implementation
    ;* when constructing the response to a WSAAsyncGetXByY() routine.
    ;*
    WSAMAKEASYNCREPLY macro buflen, error_
      exitm <MAKELONG(buflen, error_)>
    endm
    ;*
    ;* WSAMAKESELECTREPLY is intended for use by the Windows Sockets implementation
    ;* when constructing the response to WSAAsyncSelect().
    ;*
    WSAMAKESELECTREPLY macro event_, error_
      exitm <MAKELONG(event_, error_)>
    endm
    ;*
    ;* WSAGETASYNCBUFLEN is intended for use by the Windows Sockets application
    ;* to extract the buffer length from the lParam in the response
    ;* to a WSAGetXByY().
    ;*
    WSAGETASYNCBUFLEN macro lParam
      exitm <LOWORD(lParam)>
    endm
    ;*
    ;* WSAGETASYNCERROR is intended for use by the Windows Sockets application
    ;* to extract the error code from the lParam in the response
    ;* to a WSAGetXByY().
    ;*
    WSAGETASYNCERROR macro lParam
      exitm <HIWORD(lParam)>
    endm
    ;*
    ;* WSAGETSELECTEVENT is intended for use by the Windows Sockets application
    ;* to extract the event code from the lParam in the response
    ;* to a WSAAsyncSelect().
    ;*
    WSAGETSELECTEVENT macro lParam
      exitm <LOWORD(lParam)>
    endm
    ;*
    ;* WSAGETSELECTERROR is intended for use by the Windows Sockets application
    ;* to extract the error code from the lParam in the response
    ;* to a WSAAsyncSelect().
    ;*
    WSAGETSELECTERROR macro lParam
      exitm <HIWORD(lParam)>
    endm
    if (_WIN32_WINNT ge 0501h)
      ifdef IPV6STRICT
        .err <WINSOCK2 required.>
      endif
      ; IPV6STRICT
    endif
    ;(_WIN32_WINNT >= 0x0501)
    if _MSC_VER ge 1200
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  ;* _WINSOCKAPI_ *
endif
