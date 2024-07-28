;Include file created by h2incX, Version B.01.01, 26/11/2018 23:24
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'D:\MASM32\ObjAsm\Projects\h2IncX\header\ws2ipdef.h', last modified: 19/04/2018 09:44
;Creation parameters: 

ifndef _WS2IPDEF_
  _WS2IPDEF_ equ <>
  if _MSC_VER gt 1000
  endif
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    ifdef __cplusplus
      ;[...]
    endif
  endif
  ifdef _PREFAST_
    ;[...]
  endif
  ifndef WS2IPDEF_ASSERT
    WS2IPDEF_ASSERT macro exp
      exitm <((VOID) 0)>
    endm
  endif
  ifdef _MSC_VER
    WS2TCPIP_INLINE equ <__inline>
  else
    WS2TCPIP_INLINE equ <extern inline>
  endif
  include in6addr.inc
  sockaddr_in6_old struct
    sin6_family SHORT_ ?
    sin6_port USHORT ?
    sin6_flowinfo ULONG ?
    sin6_addr IN6_ADDR <>
  sockaddr_in6_old ends

  sockaddr_gen union
    Address sockaddr <>
    AddressIn sockaddr_in <>
    AddressIn6 sockaddr_in6_old <>
  sockaddr_gen ends

  INTERFACE_INFO struct
    iiFlags ULONG ?
    iiAddress sockaddr_gen <>
    iiBroadcastAddress sockaddr_gen <>
    iiNetmask sockaddr_gen <>
  INTERFACE_INFO ends

  _INTERFACE_INFO typedef INTERFACE_INFO
  LPINTERFACE_INFO typedef ptr INTERFACE_INFO
  
  INTERFACE_INFO_EX struct
    iiFlags ULONG ?
    iiAddress SOCKET_ADDRESS <>
    iiBroadcastAddress SOCKET_ADDRESS <>
    iiNetmask SOCKET_ADDRESS <>
  INTERFACE_INFO_EX ends

  _INTERFACE_INFO_EX typedef INTERFACE_INFO_EX
  LPINTERFACE_INFO_EX typedef ptr INTERFACE_INFO_EX
  
  IFF_UP equ 00000001h
  IFF_BROADCAST equ 00000002h
  IFF_LOOPBACK equ 00000004h
  IFF_POINTTOPOINT equ 00000008h
  IFF_MULTICAST equ 00000010h
  PMTUD_STATE typedef SDWORD
  IP_PMTUDISC_NOT_SET equ 0
  IP_PMTUDISC_DO equ 1
  IP_PMTUDISC_DONT equ 2
  IP_PMTUDISC_PROBE equ 3
  IP_PMTUDISC_MAX equ 4
  _PMTUD_STATE typedef PMTUD_STATE
  PPMTUD_STATE typedef ptr PMTUD_STATE
  
  IP_OPTIONS equ 1
  IP_HDRINCL equ 2
  IP_TOS equ 3
  IP_TTL equ 4
  IP_MULTICAST_IF equ 9
  IP_MULTICAST_TTL equ 10
  IP_MULTICAST_LOOP equ 11
  IP_ADD_MEMBERSHIP equ 12
  IP_DROP_MEMBERSHIP equ 13
  IP_DONTFRAGMENT equ 14
  IP_ADD_SOURCE_MEMBERSHIP equ 15
  IP_DROP_SOURCE_MEMBERSHIP equ 16
  IP_BLOCK_SOURCE equ 17
  IP_UNBLOCK_SOURCE equ 18
  IP_PKTINFO equ 19
  IP_HOPLIMIT equ 21
  IP_RECVTTL equ 21
  IP_RECEIVE_BROADCAST equ 22
  IP_RECVIF equ 24
  IP_RECVDSTADDR equ 25
  IP_IFLIST equ 28
  IP_ADD_IFLIST equ 29
  IP_DEL_IFLIST equ 30
  IP_UNICAST_IF equ 31
  IP_RTHDR equ 32
  IP_GET_IFLIST equ 33
  IP_RECVRTHDR equ 38
  IP_TCLASS equ 39
  IP_RECVTCLASS equ 40
  IP_RECVTOS equ 40
  IP_ORIGINAL_ARRIVAL_IF equ 47
  IP_ECN equ 50
  IP_PKTINFO_EX equ 51
  IP_WFP_REDIRECT_RECORDS equ 60
  IP_WFP_REDIRECT_CONTEXT equ 70
  IP_MTU_DISCOVER equ 71
  IP_MTU equ 73
  IP_NRT_INTERFACE equ 74
  IP_RECVERR equ 75
  IP_UNSPECIFIED_TYPE_OF_SERVICE equ -1
  IPV6_ADDRESS_BITS equ <RTL_BITS_OF(IN6_ADDR)>
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    SOCKADDR_IN6_LH struct
      sin6_family ADDRESS_FAMILY ?
      sin6_port USHORT ?
      sin6_flowinfo ULONG ?
      sin6_addr IN6_ADDR <>
      union
        sin6_scope_id ULONG ?
        sin6_scope_struct SCOPE_ID <>
      ends
    SOCKADDR_IN6_LH ends

    sockaddr_in6 typedef SOCKADDR_IN6_LH
    PSOCKADDR_IN6_LH typedef ptr SOCKADDR_IN6_LH
    LPSOCKADDR_IN6_LH typedef ptr SOCKADDR_IN6_LH
    
    SOCKADDR_IN6_W2KSP1 struct
      sin6_family SWORD ?
      sin6_port USHORT ?
      sin6_flowinfo ULONG ?
      sin6_addr in6_addr <>
      sin6_scope_id ULONG ?
    SOCKADDR_IN6_W2KSP1 ends

    sockaddr_in6_w2ksp1 typedef SOCKADDR_IN6_W2KSP1
    PSOCKADDR_IN6_W2KSP1 typedef ptr SOCKADDR_IN6_W2KSP1
    LPSOCKADDR_IN6_W2KSP1 typedef ptr SOCKADDR_IN6_W2KSP1
    
    if (NTDDI_VERSION ge NTDDI_VISTA)
      SOCKADDR_IN6 typedef SOCKADDR_IN6_LH
      PSOCKADDR_IN6 typedef ptr SOCKADDR_IN6_LH
      LPSOCKADDR_IN6 typedef ptr SOCKADDR_IN6_LH
    elseif (NTDDI_VERSION ge NTDDI_WIN2KSP1)
      SOCKADDR_IN6 typedef SOCKADDR_IN6_W2KSP1
      PSOCKADDR_IN6 typedef ptr SOCKADDR_IN6_W2KSP1
      LPSOCKADDR_IN6 typedef ptr SOCKADDR_IN6_W2KSP1
    else
      SOCKADDR_IN6 typedef SOCKADDR_IN6_LH
      PSOCKADDR_IN6 typedef ptr SOCKADDR_IN6_LH
      LPSOCKADDR_IN6 typedef ptr SOCKADDR_IN6_LH
    endif
    SOCKADDR_INET union
      Ipv4 SOCKADDR_IN <>
      Ipv6 SOCKADDR_IN6 <>
      si_family ADDRESS_FAMILY ?
    SOCKADDR_INET ends

    _SOCKADDR_INET typedef SOCKADDR_INET
    PSOCKADDR_INET typedef ptr SOCKADDR_INET
    
    SOCKADDR_IN6_PAIR struct
      SourceAddress PSOCKADDR_IN6 ?
      DestinationAddress PSOCKADDR_IN6 ?
    SOCKADDR_IN6_PAIR ends

    _sockaddr_in6_pair typedef SOCKADDR_IN6_PAIR
    PSOCKADDR_IN6_PAIR typedef ptr SOCKADDR_IN6_PAIR
    
    SS_PORT macro ssp
      exitm <(((PSOCKADDR_IN) (ssp)) - sin_port)>
    endm
    if (NTDDI_VERSION ge NTDDI_WIN2KSP1)
      IN6ADDR_ANY_INIT equ { { { 0 } } }
      IN6ADDR_LOOPBACK_INIT equ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }
      IN6ADDR_ALLNODESONNODE_INIT equ { 0ffh, 01h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 01h }
      IN6ADDR_ALLNODESONLINK_INIT equ { 0ffh, 02h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 01h }
      IN6ADDR_ALLROUTERSONLINK_INIT equ { 0ffh, 02h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 02h }
      IN6ADDR_ALLMLDV2ROUTERSONLINK_INIT equ { 0ffh, 02h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 16h }
      IN6ADDR_TEREDOINITIALLINKLOCALADDRESS_INIT equ { 0feh, 80h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0feh }
      IN6ADDR_TEREDOOLDLINKLOCALADDRESSXP_INIT equ { 0feh, 80h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 'T', 'E', 'R', 'E', 'D', 'O' }
      IN6ADDR_TEREDOOLDLINKLOCALADDRESSVISTA_INIT equ { 0feh, 80h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh }
      IN6ADDR_LINKLOCALPREFIX_INIT equ { 0feh, 80h, }
      IN6ADDR_MULTICASTPREFIX_INIT equ { 0ffh, 00h, }
      IN6ADDR_SOLICITEDNODEMULTICASTPREFIX_INIT equ { 0ffh, 02h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 01h, 0ffh, }
      IN6ADDR_V4MAPPEDPREFIX_INIT equ { 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h, 0ffh, 0ffh, }
      IN6ADDR_6TO4PREFIX_INIT equ { 20h, 02h, }
      IN6ADDR_TEREDOPREFIX_INIT equ { 20h, 01h, 00h, 00h, }
      IN6ADDR_TEREDOPREFIX_INIT_OLD equ { 3fh, 0feh, 83h, 1fh, }
      IN6ADDR_ULAPREFIX_INIT equ { 0fch }
      IN6ADDR_SITELOCALPREFIX_INIT equ { 0feh, 0c0h }
      IN6ADDR_6BONETESTPREFIX_INIT equ { 3fh, 0feh }
      IN6ADDR_LINKLOCALPREFIX_LENGTH equ 64
      IN6ADDR_MULTICASTPREFIX_LENGTH equ 8
      IN6ADDR_SOLICITEDNODEMULTICASTPREFIX_LENGTH equ 104
      IN6ADDR_V4MAPPEDPREFIX_LENGTH equ 96
      IN6ADDR_6TO4PREFIX_LENGTH equ 16
      IN6ADDR_TEREDOPREFIX_LENGTH equ 32
      ifdef __cplusplus
        ;[...]
      endif
      externdef scopeid_unspecified:SCOPE_ID
      externdef in4addr_any:IN_ADDR
      externdef in4addr_loopback:IN_ADDR
      externdef in4addr_broadcast:IN_ADDR
      externdef in4addr_allnodesonlink:IN_ADDR
      externdef in4addr_allroutersonlink:IN_ADDR
      externdef in4addr_alligmpv3routersonlink:IN_ADDR
      externdef in4addr_allteredohostsonlink:IN_ADDR
      externdef in4addr_linklocalprefix:IN_ADDR
      externdef in4addr_multicastprefix:IN_ADDR
      externdef in6addr_any:IN6_ADDR
      externdef in6addr_loopback:IN6_ADDR
      externdef in6addr_allnodesonnode:IN6_ADDR
      externdef in6addr_allnodesonlink:IN6_ADDR
      externdef in6addr_allroutersonlink:IN6_ADDR
      externdef in6addr_allmldv2routersonlink:IN6_ADDR
      externdef in6addr_teredoinitiallinklocaladdress:IN6_ADDR
      externdef in6addr_linklocalprefix:IN6_ADDR
      externdef in6addr_multicastprefix:IN6_ADDR
      externdef in6addr_solicitednodemulticastprefix:IN6_ADDR
      externdef in6addr_v4mappedprefix:IN6_ADDR
      externdef in6addr_6to4prefix:IN6_ADDR
      externdef in6addr_teredoprefix:IN6_ADDR
      externdef in6addr_teredoprefix_old:IN6_ADDR
      ifdef __cplusplus
        ;[...]
      endif
      ifndef __midl
        IN6_ADDR_EQUAL proto WIN_STD_CALL_CONV :ptr IN6_ADDR, :ptr IN6_ADDR
        IN6_ARE_ADDR_EQUAL equ <IN6_ADDR_EQUAL>
        IN6_IS_ADDR_UNSPECIFIED proto WIN_STD_CALL_CONV :ptr IN6_ADDR
        IN6_IS_ADDR_LOOPBACK proto WIN_STD_CALL_CONV :ptr IN6_ADDR
        IN6_IS_ADDR_MULTICAST proto WIN_STD_CALL_CONV :ptr IN6_ADDR
        IN6_IS_ADDR_EUI64 proto WIN_STD_CALL_CONV :ptr IN6_ADDR
        IN6_IS_ADDR_SUBNET_ROUTER_ANYCAST proto WIN_STD_CALL_CONV :ptr IN6_ADDR
        IN6_IS_ADDR_SUBNET_RESERVED_ANYCAST proto WIN_STD_CALL_CONV :ptr IN6_ADDR
        IN6_IS_ADDR_ANYCAST proto WIN_STD_CALL_CONV :ptr IN6_ADDR
        IN6_IS_ADDR_LINKLOCAL proto WIN_STD_CALL_CONV :ptr IN6_ADDR
        IN6_IS_ADDR_SITELOCAL proto WIN_STD_CALL_CONV :ptr IN6_ADDR
        IN6_IS_ADDR_GLOBAL proto WIN_STD_CALL_CONV :ptr IN6_ADDR
        IN6_IS_ADDR_V4MAPPED proto WIN_STD_CALL_CONV :ptr IN6_ADDR
        IN6_IS_ADDR_V4COMPAT proto WIN_STD_CALL_CONV :ptr IN6_ADDR
        IN6_IS_ADDR_V4TRANSLATED proto WIN_STD_CALL_CONV :ptr IN6_ADDR
        IN6_IS_ADDR_MC_NODELOCAL proto WIN_STD_CALL_CONV :ptr IN6_ADDR
        IN6_IS_ADDR_MC_LINKLOCAL proto WIN_STD_CALL_CONV :ptr IN6_ADDR
        IN6_IS_ADDR_MC_SITELOCAL proto WIN_STD_CALL_CONV :ptr IN6_ADDR
        IN6_IS_ADDR_MC_ORGLOCAL proto WIN_STD_CALL_CONV :ptr IN6_ADDR
        IN6_IS_ADDR_MC_GLOBAL proto WIN_STD_CALL_CONV :ptr IN6_ADDR
        IN6_SET_ADDR_UNSPECIFIED proto WIN_STD_CALL_CONV :PIN6_ADDR
        IN6_SET_ADDR_LOOPBACK proto WIN_STD_CALL_CONV :PIN6_ADDR
        IN6ADDR_SETANY proto WIN_STD_CALL_CONV :PSOCKADDR_IN6
        IN6ADDR_SETLOOPBACK proto WIN_STD_CALL_CONV :PSOCKADDR_IN6
        IN6ADDR_ISANY proto WIN_STD_CALL_CONV :ptr SOCKADDR_IN6
        IN6ADDR_ISLOOPBACK proto WIN_STD_CALL_CONV :ptr SOCKADDR_IN6
        IN6ADDR_ISEQUAL proto WIN_STD_CALL_CONV :ptr SOCKADDR_IN6, :ptr SOCKADDR_IN6
        IN6ADDR_ISUNSPECIFIED proto WIN_STD_CALL_CONV :ptr SOCKADDR_IN6
      endif
    endif
  endif
  SIO_GET_INTERFACE_LIST equ _IOR('t', 127, ULONG)
  SIO_GET_INTERFACE_LIST_EX equ _IOR('t', 126, ULONG)
  SIO_SET_MULTICAST_FILTER equ _IOW('t', 125, ULONG)
  SIO_GET_MULTICAST_FILTER equ _IOW('t', 124 or IOC_IN, ULONG)
  SIOCSIPMSFILTER equ <SIO_SET_MULTICAST_FILTER>
  SIOCGIPMSFILTER equ <SIO_GET_MULTICAST_FILTER>
  SIOCSMSFILTER equ _IOW('t', 126, ULONG)
  SIOCGMSFILTER equ _IOW('t', 127 or IOC_IN, ULONG)
  if (NTDDI_VERSION ge NTDDI_VISTASP1)
    IDEAL_SEND_BACKLOG_IOCTLS equ <>
    SIO_IDEAL_SEND_BACKLOG_QUERY equ _IOR('t', 123, ULONG)
    SIO_IDEAL_SEND_BACKLOG_CHANGE equ _IO('t', 122)
  endif
  MCAST_JOIN_GROUP equ 41
  MCAST_LEAVE_GROUP equ 42
  MCAST_BLOCK_SOURCE equ 43
  MCAST_UNBLOCK_SOURCE equ 44
  MCAST_JOIN_SOURCE_GROUP equ 45
  MCAST_LEAVE_SOURCE_GROUP equ 46
  MULTICAST_MODE_TYPE typedef SDWORD
  MCAST_INCLUDE equ 0
  MCAST_EXCLUDE equ 1
  
  IP_MREQ struct
    imr_multiaddr IN_ADDR <>
    imr_interface IN_ADDR <>
  IP_MREQ ends

  ip_mreq typedef IP_MREQ
  PIP_MREQ typedef ptr IP_MREQ
  
  IP_MREQ_SOURCE struct
    imr_multiaddr IN_ADDR <>
    imr_sourceaddr IN_ADDR <>
    imr_interface IN_ADDR <>
  IP_MREQ_SOURCE ends

  ip_mreq_source typedef IP_MREQ_SOURCE
  PIP_MREQ_SOURCE typedef ptr IP_MREQ_SOURCE
  
  IP_MSFILTER struct
    imsf_multiaddr IN_ADDR <>
    imsf_interface IN_ADDR <>
    imsf_fmode MULTICAST_MODE_TYPE ?
    imsf_numsrc ULONG ?
    imsf_slist IN_ADDR 1 dup (<>)
  IP_MSFILTER ends

  ip_msfilter typedef IP_MSFILTER
  PIP_MSFILTER typedef ptr IP_MSFILTER
  
  IP_MSFILTER_SIZE macro NumSources
    exitm <(sizeof(IP_MSFILTER) - sizeof(IN_ADDR) + (NumSources) * sizeof(IN_ADDR))>
  endm
  IPV6_HOPOPTS equ 1
  IPV6_HDRINCL equ 2
  IPV6_UNICAST_HOPS equ 4
  IPV6_MULTICAST_IF equ 9
  IPV6_MULTICAST_HOPS equ 10
  IPV6_MULTICAST_LOOP equ 11
  IPV6_ADD_MEMBERSHIP equ 12
  IPV6_JOIN_GROUP equ <IPV6_ADD_MEMBERSHIP>
  IPV6_DROP_MEMBERSHIP equ 13
  IPV6_LEAVE_GROUP equ <IPV6_DROP_MEMBERSHIP>
  IPV6_DONTFRAG equ 14
  IPV6_PKTINFO equ 19
  IPV6_HOPLIMIT equ 21
  IPV6_PROTECTION_LEVEL equ 23
  IPV6_RECVIF equ 24
  IPV6_RECVDSTADDR equ 25
  IPV6_CHECKSUM equ 26
  IPV6_V6ONLY equ 27
  IPV6_IFLIST equ 28
  IPV6_ADD_IFLIST equ 29
  IPV6_DEL_IFLIST equ 30
  IPV6_UNICAST_IF equ 31
  IPV6_RTHDR equ 32
  IPV6_GET_IFLIST equ 33
  IPV6_RECVRTHDR equ 38
  IPV6_TCLASS equ 39
  IPV6_RECVTCLASS equ 40
  IPV6_ECN equ 50
  IPV6_PKTINFO_EX equ 51
  IPV6_WFP_REDIRECT_RECORDS equ 60
  IPV6_WFP_REDIRECT_CONTEXT equ 70
  IPV6_MTU_DISCOVER equ 71
  IPV6_MTU equ 72
  IPV6_NRT_INTERFACE equ 74
  IPV6_RECVERR equ 75
  IP_UNSPECIFIED_HOP_LIMIT equ -1
  IP_PROTECTION_LEVEL equ <IPV6_PROTECTION_LEVEL>
  PROTECTION_LEVEL_UNRESTRICTED equ 10
  PROTECTION_LEVEL_EDGERESTRICTED equ 20
  PROTECTION_LEVEL_RESTRICTED equ 30
  if (NTDDI_VERSION lt NTDDI_VISTA)
    PROTECTION_LEVEL_DEFAULT equ <PROTECTION_LEVEL_EDGERESTRICTED>
  else
    PROTECTION_LEVEL_DEFAULT equ (- 1)
  endif
  IPV6_MREQ struct
    ipv6mr_multiaddr IN6_ADDR <>
    ipv6mr_interface ULONG ?
  IPV6_MREQ ends

  ipv6_mreq typedef IPV6_MREQ
  PIPV6_MREQ typedef ptr IPV6_MREQ
  
  if (NTDDI_VERSION ge NTDDI_WINXP)
    GROUP_REQ struct
      gr_interface ULONG ?
      gr_group SOCKADDR_STORAGE <>
    GROUP_REQ ends

    group_req typedef GROUP_REQ
    PGROUP_REQ typedef ptr GROUP_REQ
    
    GROUP_SOURCE_REQ struct
      gsr_interface ULONG ?
      gsr_group SOCKADDR_STORAGE <>
      gsr_source SOCKADDR_STORAGE <>
    GROUP_SOURCE_REQ ends

    group_source_req typedef GROUP_SOURCE_REQ
    PGROUP_SOURCE_REQ typedef ptr GROUP_SOURCE_REQ
    
    GROUP_FILTER struct
      gf_interface ULONG ?
      gf_group SOCKADDR_STORAGE <>
      gf_fmode MULTICAST_MODE_TYPE ?
      gf_numsrc ULONG ?
      gf_slist SOCKADDR_STORAGE 1 dup (<>)
    GROUP_FILTER ends

    group_filter typedef GROUP_FILTER
    PGROUP_FILTER typedef ptr GROUP_FILTER
    
    GROUP_FILTER_SIZE macro numsrc
      exitm <(sizeof(GROUP_FILTER) - sizeof(SOCKADDR_STORAGE) + (numsrc) * sizeof(SOCKADDR_STORAGE))>
    endm
  endif
  IN_PKTINFO struct
    ipi_addr IN_ADDR <>
    ipi_ifindex ULONG ?
  IN_PKTINFO ends

  in_pktinfo typedef IN_PKTINFO
  PIN_PKTINFO typedef ptr IN_PKTINFO
  
  IN6_PKTINFO struct
    ipi6_addr IN6_ADDR <>
    ipi6_ifindex ULONG ?
  IN6_PKTINFO ends

  in6_pktinfo typedef IN6_PKTINFO
  PIN6_PKTINFO typedef ptr IN6_PKTINFO
  
  IN_PKTINFO_EX struct
    pkt_info IN_PKTINFO <>
    scope_id SCOPE_ID <>
  IN_PKTINFO_EX ends

  in_pktinfo_ex typedef IN_PKTINFO_EX
  PIN_PKTINFO_EX typedef ptr IN_PKTINFO_EX
  
  IN6_PKTINFO_EX struct
    pkt_info IN6_PKTINFO <>
    scope_id SCOPE_ID <>
  IN6_PKTINFO_EX ends

  in6_pktinfo_ex typedef IN6_PKTINFO_EX
  PIN6_PKTINFO_EX typedef ptr IN6_PKTINFO_EX
  
  IN_RECVERR struct
    protocol IPPROTO ?
    info ULONG ?
    type_ UINT8 ?
    code UINT8 ?
  IN_RECVERR ends

  in_recverr typedef IN_RECVERR
  PIN_RECVERR typedef ptr IN_RECVERR
  
  INET_ADDRSTRLEN equ 22
  INET6_ADDRSTRLEN equ 65
  TCP_OFFLOAD_NO_PREFERENCE equ 0
  TCP_OFFLOAD_NOT_PREFERRED equ 1
  TCP_OFFLOAD_PREFERRED equ 2
  TCP_EXPEDITED_1122 equ 0002h
  TCP_KEEPALIVE equ 3
  TCP_MAXSEG equ 4
  TCP_MAXRT equ 5
  TCP_STDURG equ 6
  TCP_NOURG equ 7
  TCP_ATMARK equ 8
  TCP_NOSYNRETRIES equ 9
  TCP_TIMESTAMPS equ 10
  TCP_OFFLOAD_PREFERENCE equ 11
  TCP_CONGESTION_ALGORITHM equ 12
  TCP_DELAY_FIN_ACK equ 13
  TCP_MAXRTMS equ 14
  TCP_FASTOPEN equ 15
  TCP_KEEPCNT equ 16
  TCP_KEEPIDLE equ <TCP_KEEPALIVE>
  TCP_KEEPINTVL equ 17
  ifdef _PREFAST_
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    ifdef __cplusplus
      ;[...]
    endif
  endif
endif

