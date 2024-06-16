;Include file created by h2inc+ version C.2.0 on (UTC) 15/06/2024 16:37:44
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\ipmib.h
;             Created on (UTC) 22/05/2024 17:57:07
;             Last modified on (UTC) 08/01/2024 17:04:20

ifndef _IPMIB_
  _IPMIB_ equ <>
  if Defined(_MSC_VER) and (_MSC_VER gt 1000)
  endif
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    ifndef ANY_SIZE
      ANY_SIZE equ 1
    endif
    include ifmib.inc
    include nldef.inc
    if Defined(_MSC_VER)
      if _MSC_VER ge 1200
      endif
    endif
    MIB_IPADDR_PRIMARY equ 0001h
    MIB_IPADDR_DYNAMIC equ 0004h
    MIB_IPADDR_DISCONNECTED equ 0008h
    MIB_IPADDR_DELETED equ 0040h
    MIB_IPADDR_TRANSIENT equ 0080h
    MIB_IPADDR_DNS_ELIGIBLE equ 0100h
    MIB_IPADDRROW_XP struct
      dwAddr DWORD ?
      dwIndex IF_INDEX ?
      dwMask DWORD ?
      dwBCastAddr DWORD ?
      dwReasmSize DWORD ?
      unused1 WORD ?
      wType WORD ?
    MIB_IPADDRROW_XP ends
    _MIB_IPADDRROW_XP typedef MIB_IPADDRROW_XP
    PMIB_IPADDRROW_XP typedef ptr MIB_IPADDRROW_XP
    MIB_IPADDRROW_W2K struct
      dwAddr DWORD ?
      dwIndex DWORD ?
      dwMask DWORD ?
      dwBCastAddr DWORD ?
      dwReasmSize DWORD ?
      unused1 WORD ?
      unused2 WORD ?
    MIB_IPADDRROW_W2K ends
    _MIB_IPADDRROW_W2K typedef MIB_IPADDRROW_W2K
    PMIB_IPADDRROW_W2K typedef ptr MIB_IPADDRROW_W2K
    if (NTDDI_VERSION ge NTDDI_WINXP)
      MIB_IPADDRROW typedef MIB_IPADDRROW_XP
      PMIB_IPADDRROW typedef ptr MIB_IPADDRROW_XP
    elseif (NTDDI_VERSION ge NTDDI_WIN2K)
      MIB_IPADDRROW typedef MIB_IPADDRROW_W2K
      PMIB_IPADDRROW typedef ptr MIB_IPADDRROW_W2K
    else
      MIB_IPADDRROW typedef MIB_IPADDRROW_XP
      PMIB_IPADDRROW typedef ptr MIB_IPADDRROW_XP
    endif
    MIB_IPADDRTABLE struct
      dwNumEntries DWORD ?
      table MIB_IPADDRROW ANY_SIZE dup (<>)
    MIB_IPADDRTABLE ends
    _MIB_IPADDRTABLE typedef MIB_IPADDRTABLE
    PMIB_IPADDRTABLE typedef ptr MIB_IPADDRTABLE
    SIZEOF_IPADDRTABLE macro X
      exitm <(FIELD_OFFSET(MIB_IPADDRTABLE, table [ 0 ]) + ((X) * sizeof(MIB_IPADDRROW)) + ALIGN_SIZE)>
    endm
    MIB_IPFORWARDNUMBER struct
      dwValue DWORD ?
    MIB_IPFORWARDNUMBER ends
    _MIB_IPFORWARDNUMBER typedef MIB_IPFORWARDNUMBER
    PMIB_IPFORWARDNUMBER typedef ptr MIB_IPFORWARDNUMBER
    MIB_IPFORWARD_PROTO typedef NL_ROUTE_PROTOCOL
    MIB_IPFORWARD_TYPE typedef SDWORD
    MIB_IPROUTE_TYPE_OTHER equ 1
    MIB_IPROUTE_TYPE_INVALID equ 2
    MIB_IPROUTE_TYPE_DIRECT equ 3
    MIB_IPROUTE_TYPE_INDIRECT equ 4

    MIB_IPFORWARDROW struct
      dwForwardDest DWORD ?
      dwForwardMask DWORD ?
      dwForwardPolicy DWORD ?
      dwForwardNextHop DWORD ?
      dwForwardIfIndex IF_INDEX ?
      union
        dwForwardType DWORD ?
        ForwardType MIB_IPFORWARD_TYPE ?
      ends
      union
        dwForwardProto DWORD ?
        ForwardProto MIB_IPFORWARD_PROTO ?
      ends
      dwForwardAge DWORD ?
      dwForwardNextHopAS DWORD ?
      dwForwardMetric1 DWORD ?
      dwForwardMetric2 DWORD ?
      dwForwardMetric3 DWORD ?
      dwForwardMetric4 DWORD ?
      dwForwardMetric5 DWORD ?
    MIB_IPFORWARDROW ends
    _MIB_IPFORWARDROW typedef MIB_IPFORWARDROW
    PMIB_IPFORWARDROW typedef ptr MIB_IPFORWARDROW
    MIB_IPROUTE_TYPE_OTHER equ 1
    MIB_IPROUTE_TYPE_INVALID equ 2
    MIB_IPROUTE_TYPE_DIRECT equ 3
    MIB_IPROUTE_TYPE_INDIRECT equ 4
    MIB_IPROUTE_METRIC_UNUSED equ -1
    MIB_IPFORWARDTABLE struct
      dwNumEntries DWORD ?
      table MIB_IPFORWARDROW ANY_SIZE dup (<>)
    MIB_IPFORWARDTABLE ends
    _MIB_IPFORWARDTABLE typedef MIB_IPFORWARDTABLE
    PMIB_IPFORWARDTABLE typedef ptr MIB_IPFORWARDTABLE
    SIZEOF_IPFORWARDTABLE macro X
      exitm <(FIELD_OFFSET(MIB_IPFORWARDTABLE, table [ 0 ]) + ((X) * sizeof(MIB_IPFORWARDROW)) + ALIGN_SIZE)>
    endm
    MIB_IPNET_TYPE typedef SDWORD
    MIB_IPNET_TYPE_OTHER equ 1
    MIB_IPNET_TYPE_INVALID equ 2
    MIB_IPNET_TYPE_DYNAMIC equ 3
    MIB_IPNET_TYPE_STATIC equ 4

    MIB_IPNETROW_LH struct
      dwIndex IF_INDEX ?
      dwPhysAddrLen DWORD ?
      bPhysAddr UCHAR MAXLEN_PHYSADDR dup (?)
      dwAddr DWORD ?
      union
        dwType DWORD ?
        Type_ MIB_IPNET_TYPE ?
      ends
    MIB_IPNETROW_LH ends
    _MIB_IPNETROW_LH typedef MIB_IPNETROW_LH
    PMIB_IPNETROW_LH typedef ptr MIB_IPNETROW_LH
    MIB_IPNETROW_W2K struct
      dwIndex IF_INDEX ?
      dwPhysAddrLen DWORD ?
      bPhysAddr UCHAR MAXLEN_PHYSADDR dup (?)
      dwAddr DWORD ?
      dwType DWORD ?
    MIB_IPNETROW_W2K ends
    _MIB_IPNETROW_W2K typedef MIB_IPNETROW_W2K
    PMIB_IPNETROW_W2K typedef ptr MIB_IPNETROW_W2K
    if (NTDDI_VERSION ge NTDDI_VISTA)
      MIB_IPNETROW typedef MIB_IPNETROW_LH
      PMIB_IPNETROW typedef ptr MIB_IPNETROW_LH
    elseif (NTDDI_VERSION ge NTDDI_WIN2K)
      MIB_IPNETROW typedef MIB_IPNETROW_W2K
      PMIB_IPNETROW typedef ptr MIB_IPNETROW_W2K
    else
      MIB_IPNETROW typedef MIB_IPNETROW_LH
      PMIB_IPNETROW typedef ptr MIB_IPNETROW_LH
    endif
    MIB_IPNETTABLE struct
      dwNumEntries DWORD ?
      table MIB_IPNETROW ANY_SIZE dup (<>)
    MIB_IPNETTABLE ends
    _MIB_IPNETTABLE typedef MIB_IPNETTABLE
    PMIB_IPNETTABLE typedef ptr MIB_IPNETTABLE
    SIZEOF_IPNETTABLE macro X
      exitm <(FIELD_OFFSET(MIB_IPNETTABLE, table [ 0 ]) + ((X) * sizeof(MIB_IPNETROW)) + ALIGN_SIZE)>
    endm
    MIB_IPSTATS_FORWARDING typedef SDWORD
    MIB_IP_FORWARDING equ 1
    MIB_IP_NOT_FORWARDING equ 2
    PMIB_IPSTATS_FORWARDING typedef ptr MIB_IPSTATS_FORWARDING
    MIB_USE_CURRENT_TTL equ (- 1)
    MIB_USE_CURRENT_FORWARDING equ (- 1)
    MIB_IPSTATS_LH struct
      union
        dwForwarding DWORD ?
        Forwarding MIB_IPSTATS_FORWARDING ?
      ends
      dwDefaultTTL DWORD ?
      dwInReceives DWORD ?
      dwInHdrErrors DWORD ?
      dwInAddrErrors DWORD ?
      dwForwDatagrams DWORD ?
      dwInUnknownProtos DWORD ?
      dwInDiscards DWORD ?
      dwInDelivers DWORD ?
      dwOutRequests DWORD ?
      dwRoutingDiscards DWORD ?
      dwOutDiscards DWORD ?
      dwOutNoRoutes DWORD ?
      dwReasmTimeout DWORD ?
      dwReasmReqds DWORD ?
      dwReasmOks DWORD ?
      dwReasmFails DWORD ?
      dwFragOks DWORD ?
      dwFragFails DWORD ?
      dwFragCreates DWORD ?
      dwNumIf DWORD ?
      dwNumAddr DWORD ?
      dwNumRoutes DWORD ?
    MIB_IPSTATS_LH ends
    _MIB_IPSTATS_LH typedef MIB_IPSTATS_LH
    PMIB_IPSTATS_LH typedef ptr MIB_IPSTATS_LH
    MIB_IPSTATS_W2K struct
      dwForwarding DWORD ?
      dwDefaultTTL DWORD ?
      dwInReceives DWORD ?
      dwInHdrErrors DWORD ?
      dwInAddrErrors DWORD ?
      dwForwDatagrams DWORD ?
      dwInUnknownProtos DWORD ?
      dwInDiscards DWORD ?
      dwInDelivers DWORD ?
      dwOutRequests DWORD ?
      dwRoutingDiscards DWORD ?
      dwOutDiscards DWORD ?
      dwOutNoRoutes DWORD ?
      dwReasmTimeout DWORD ?
      dwReasmReqds DWORD ?
      dwReasmOks DWORD ?
      dwReasmFails DWORD ?
      dwFragOks DWORD ?
      dwFragFails DWORD ?
      dwFragCreates DWORD ?
      dwNumIf DWORD ?
      dwNumAddr DWORD ?
      dwNumRoutes DWORD ?
    MIB_IPSTATS_W2K ends
    _MIB_IPSTATS_W2K typedef MIB_IPSTATS_W2K
    PMIB_IPSTATS_W2K typedef ptr MIB_IPSTATS_W2K
    if (NTDDI_VERSION ge NTDDI_VISTA)
      MIB_IPSTATS typedef MIB_IPSTATS_LH
      PMIB_IPSTATS typedef ptr MIB_IPSTATS_LH
    elseif (NTDDI_VERSION ge NTDDI_WIN2K)
      MIB_IPSTATS typedef MIB_IPSTATS_W2K
      PMIB_IPSTATS typedef ptr MIB_IPSTATS_W2K
    endif
    MIBICMPSTATS struct
      dwMsgs DWORD ?
      dwErrors DWORD ?
      dwDestUnreachs DWORD ?
      dwTimeExcds DWORD ?
      dwParmProbs DWORD ?
      dwSrcQuenchs DWORD ?
      dwRedirects DWORD ?
      dwEchos DWORD ?
      dwEchoReps DWORD ?
      dwTimestamps DWORD ?
      dwTimestampReps DWORD ?
      dwAddrMasks DWORD ?
      dwAddrMaskReps DWORD ?
    MIBICMPSTATS ends
    _MIBICMPSTATS typedef MIBICMPSTATS
    PMIBICMPSTATS typedef ptr MIBICMPSTATS
    MIBICMPINFO struct
      icmpInStats MIBICMPSTATS <>
      icmpOutStats MIBICMPSTATS <>
    MIBICMPINFO ends
    _MIBICMPINFO typedef MIBICMPINFO
    MIB_ICMP struct
      stats MIBICMPINFO <>
    MIB_ICMP ends
    _MIB_ICMP typedef MIB_ICMP
    PMIB_ICMP typedef ptr MIB_ICMP
    MIBICMPSTATS_EX_XPSP1 struct
      dwMsgs DWORD ?
      dwErrors DWORD ?
      rgdwTypeCount DWORD 256 dup (?)
    MIBICMPSTATS_EX_XPSP1 ends
    _MIBICMPSTATS_EX_XPSP1 typedef MIBICMPSTATS_EX_XPSP1
    PMIBICMPSTATS_EX_XPSP1 typedef ptr MIBICMPSTATS_EX_XPSP1
    MIBICMPSTATS_EX typedef MIBICMPSTATS_EX_XPSP1
    PMIBICMPSTATS_EX typedef ptr MIBICMPSTATS_EX_XPSP1
    MIB_ICMP_EX_XPSP1 struct
      icmpInStats MIBICMPSTATS_EX <>
      icmpOutStats MIBICMPSTATS_EX <>
    MIB_ICMP_EX_XPSP1 ends
    _MIB_ICMP_EX_XPSP1 typedef MIB_ICMP_EX_XPSP1
    PMIB_ICMP_EX_XPSP1 typedef ptr MIB_ICMP_EX_XPSP1
    MIB_ICMP_EX typedef MIB_ICMP_EX_XPSP1
    PMIB_ICMP_EX typedef ptr MIB_ICMP_EX_XPSP1
    ICMP6_TYPE typedef SDWORD
    ICMP6_DST_UNREACH equ 1
    ICMP6_PACKET_TOO_BIG equ 2
    ICMP6_TIME_EXCEEDED equ 3
    ICMP6_PARAM_PROB equ 4
    ICMP6_ECHO_REQUEST equ 128
    ICMP6_ECHO_REPLY equ 129
    ICMP6_MEMBERSHIP_QUERY equ 130
    ICMP6_MEMBERSHIP_REPORT equ 131
    ICMP6_MEMBERSHIP_REDUCTION equ 132
    ND_ROUTER_SOLICIT equ 133
    ND_ROUTER_ADVERT equ 134
    ND_NEIGHBOR_SOLICIT equ 135
    ND_NEIGHBOR_ADVERT equ 136
    ND_REDIRECT equ 137
    ICMP6_V2_MEMBERSHIP_REPORT equ 143
    PICMP6_TYPE typedef ptr ICMP6_TYPE
    ICMP6_INFOMSG_MASK equ 80h
    ICMP6_ISTYPEINFORMATIONAL macro Type_
      exitm <(((Type_) and ICMP6_INFOMSG_MASK) != 0)>
    endm
    ICMP6_ISTYPEERROR macro Type_
      exitm <(! ICMP6_ISTYPEINFORMATIONAL(Type_))>
    endm
    ICMP4_TYPE typedef SDWORD
    ICMP4_ECHO_REPLY equ 0
    ICMP4_DST_UNREACH equ 3
    ICMP4_SOURCE_QUENCH equ 4
    ICMP4_REDIRECT equ 5
    ICMP4_ECHO_REQUEST equ 8
    ICMP4_ROUTER_ADVERT equ 9
    ICMP4_ROUTER_SOLICIT equ 10
    ICMP4_TIME_EXCEEDED equ 11
    ICMP4_PARAM_PROB equ 12
    ICMP4_TIMESTAMP_REQUEST equ 13
    ICMP4_TIMESTAMP_REPLY equ 14
    ICMP4_MASK_REQUEST equ 17
    ICMP4_MASK_REPLY equ 18
    PICMP4_TYPE typedef ptr ICMP4_TYPE
    ICMP4_ISTYPEERROR macro Type_
      exitm <(((Type_) == ICMP4_DST_UNREACH) or ((Type_) == ICMP4_SOURCE_QUENCH) or ((Type_) == ICMP4_REDIRECT) or ((Type_) == ICMP4_PARAM_PROB) or ((Type_) == ICMP4_TIME_EXCEEDED))>
    endm
    MIB_IPMCAST_OIF_XP struct
      dwOutIfIndex DWORD ?
      dwNextHopAddr DWORD ?
      dwReserved DWORD ?
      dwReserved1 DWORD ?
    MIB_IPMCAST_OIF_XP ends
    _MIB_IPMCAST_OIF_XP typedef MIB_IPMCAST_OIF_XP
    PMIB_IPMCAST_OIF_XP typedef ptr MIB_IPMCAST_OIF_XP
    MIB_IPMCAST_OIF_W2K struct
      dwOutIfIndex DWORD ?
      dwNextHopAddr DWORD ?
      pvReserved PVOID ?
      dwReserved DWORD ?
    MIB_IPMCAST_OIF_W2K ends
    _MIB_IPMCAST_OIF_W2K typedef MIB_IPMCAST_OIF_W2K
    PMIB_IPMCAST_OIF_W2K typedef ptr MIB_IPMCAST_OIF_W2K
    if (NTDDI_VERSION ge NTDDI_WINXP)
      MIB_IPMCAST_OIF typedef MIB_IPMCAST_OIF_XP
      PMIB_IPMCAST_OIF typedef ptr MIB_IPMCAST_OIF_XP
    elseif (NTDDI_VERSION ge NTDDI_WIN2K)
      MIB_IPMCAST_OIF typedef MIB_IPMCAST_OIF_W2K
      PMIB_IPMCAST_OIF typedef ptr MIB_IPMCAST_OIF_W2K
    else
      MIB_IPMCAST_OIF typedef MIB_IPMCAST_OIF_XP
      PMIB_IPMCAST_OIF typedef ptr MIB_IPMCAST_OIF_XP
    endif
    MIB_IPMCAST_MFE struct
      dwGroup DWORD ?
      dwSource DWORD ?
      dwSrcMask DWORD ?
      dwUpStrmNgbr DWORD ?
      dwInIfIndex DWORD ?
      dwInIfProtocol DWORD ?
      dwRouteProtocol DWORD ?
      dwRouteNetwork DWORD ?
      dwRouteMask DWORD ?
      ulUpTime ULONG ?
      ulExpiryTime ULONG ?
      ulTimeOut ULONG ?
      ulNumOutIf ULONG ?
      fFlags DWORD ?
      dwReserved DWORD ?
      rgmioOutInfo MIB_IPMCAST_OIF ANY_SIZE dup (<>)
    MIB_IPMCAST_MFE ends
    _MIB_IPMCAST_MFE typedef MIB_IPMCAST_MFE
    PMIB_IPMCAST_MFE typedef ptr MIB_IPMCAST_MFE
    MIB_MFE_TABLE struct
      dwNumEntries DWORD ?
      table MIB_IPMCAST_MFE ANY_SIZE dup (<>)
    MIB_MFE_TABLE ends
    _MIB_MFE_TABLE typedef MIB_MFE_TABLE
    PMIB_MFE_TABLE typedef ptr MIB_MFE_TABLE
    SIZEOF_BASIC_MIB_MFE equ (FIELD_OFFSET (MIB_IPMCAST_MFE, rgmioOutInfo [ 0 ]))
    SIZEOF_MIB_MFE macro X
      exitm <(SIZEOF_BASIC_MIB_MFE + ((X) * sizeof(MIB_IPMCAST_OIF)))>
    endm
    MIB_IPMCAST_OIF_STATS_LH struct
      dwOutIfIndex DWORD ?
      dwNextHopAddr DWORD ?
      dwDialContext DWORD ?
      ulTtlTooLow ULONG ?
      ulFragNeeded ULONG ?
      ulOutPackets ULONG ?
      ulOutDiscards ULONG ?
    MIB_IPMCAST_OIF_STATS_LH ends
    _MIB_IPMCAST_OIF_STATS_LH typedef MIB_IPMCAST_OIF_STATS_LH
    PMIB_IPMCAST_OIF_STATS_LH typedef ptr MIB_IPMCAST_OIF_STATS_LH
    MIB_IPMCAST_OIF_STATS_W2K struct
      dwOutIfIndex DWORD ?
      dwNextHopAddr DWORD ?
      pvDialContext PVOID ?
      ulTtlTooLow ULONG ?
      ulFragNeeded ULONG ?
      ulOutPackets ULONG ?
      ulOutDiscards ULONG ?
    MIB_IPMCAST_OIF_STATS_W2K ends
    _MIB_IPMCAST_OIF_STATS_W2K typedef MIB_IPMCAST_OIF_STATS_W2K
    PMIB_IPMCAST_OIF_STATS_W2K typedef ptr MIB_IPMCAST_OIF_STATS_W2K
    if (NTDDI_VERSION ge NTDDI_VISTA)
      MIB_IPMCAST_OIF_STATS typedef MIB_IPMCAST_OIF_STATS_LH
      PMIB_IPMCAST_OIF_STATS typedef ptr MIB_IPMCAST_OIF_STATS_LH
    elseif (NTDDI_VERSION ge NTDDI_WIN2K)
      MIB_IPMCAST_OIF_STATS typedef MIB_IPMCAST_OIF_STATS_W2K
      PMIB_IPMCAST_OIF_STATS typedef ptr MIB_IPMCAST_OIF_STATS_W2K
    else
      MIB_IPMCAST_OIF_STATS typedef MIB_IPMCAST_OIF_STATS_LH
      PMIB_IPMCAST_OIF_STATS typedef ptr MIB_IPMCAST_OIF_STATS_LH
    endif
    MIB_IPMCAST_MFE_STATS struct
      dwGroup DWORD ?
      dwSource DWORD ?
      dwSrcMask DWORD ?
      dwUpStrmNgbr DWORD ?
      dwInIfIndex DWORD ?
      dwInIfProtocol DWORD ?
      dwRouteProtocol DWORD ?
      dwRouteNetwork DWORD ?
      dwRouteMask DWORD ?
      ulUpTime ULONG ?
      ulExpiryTime ULONG ?
      ulNumOutIf ULONG ?
      ulInPkts ULONG ?
      ulInOctets ULONG ?
      ulPktsDifferentIf ULONG ?
      ulQueueOverflow ULONG ?
      rgmiosOutStats MIB_IPMCAST_OIF_STATS ANY_SIZE dup (<>)
    MIB_IPMCAST_MFE_STATS ends
    _MIB_IPMCAST_MFE_STATS typedef MIB_IPMCAST_MFE_STATS
    PMIB_IPMCAST_MFE_STATS typedef ptr MIB_IPMCAST_MFE_STATS
    MIB_MFE_STATS_TABLE struct
      dwNumEntries DWORD ?
      table MIB_IPMCAST_MFE_STATS ANY_SIZE dup (<>)
    MIB_MFE_STATS_TABLE ends
    _MIB_MFE_STATS_TABLE typedef MIB_MFE_STATS_TABLE
    PMIB_MFE_STATS_TABLE typedef ptr MIB_MFE_STATS_TABLE
    SIZEOF_BASIC_MIB_MFE_STATS equ (FIELD_OFFSET (MIB_IPMCAST_MFE_STATS, rgmiosOutStats [ 0 ]))
    SIZEOF_MIB_MFE_STATS macro X
      exitm <(SIZEOF_BASIC_MIB_MFE_STATS + ((X) * sizeof(MIB_IPMCAST_OIF_STATS)))>
    endm
    MIB_IPMCAST_MFE_STATS_EX_XP struct
      dwGroup DWORD ?
      dwSource DWORD ?
      dwSrcMask DWORD ?
      dwUpStrmNgbr DWORD ?
      dwInIfIndex DWORD ?
      dwInIfProtocol DWORD ?
      dwRouteProtocol DWORD ?
      dwRouteNetwork DWORD ?
      dwRouteMask DWORD ?
      ulUpTime ULONG ?
      ulExpiryTime ULONG ?
      ulNumOutIf ULONG ?
      ulInPkts ULONG ?
      ulInOctets ULONG ?
      ulPktsDifferentIf ULONG ?
      ulQueueOverflow ULONG ?
      ulUninitMfe ULONG ?
      ulNegativeMfe ULONG ?
      ulInDiscards ULONG ?
      ulInHdrErrors ULONG ?
      ulTotalOutPackets ULONG ?
      rgmiosOutStats MIB_IPMCAST_OIF_STATS ANY_SIZE dup (<>)
    MIB_IPMCAST_MFE_STATS_EX_XP ends
    _MIB_IPMCAST_MFE_STATS_EX_XP typedef MIB_IPMCAST_MFE_STATS_EX_XP
    PMIB_IPMCAST_MFE_STATS_EX_XP typedef ptr MIB_IPMCAST_MFE_STATS_EX_XP
    if (NTDDI_VERSION ge NTDDI_WINXP)
      MIB_IPMCAST_MFE_STATS_EX typedef MIB_IPMCAST_MFE_STATS_EX_XP
      PMIB_IPMCAST_MFE_STATS_EX typedef ptr MIB_IPMCAST_MFE_STATS_EX_XP
    endif
    MIB_MFE_STATS_TABLE_EX_XP struct
      dwNumEntries DWORD ?
      table PMIB_IPMCAST_MFE_STATS_EX_XP ANY_SIZE dup (?)
    MIB_MFE_STATS_TABLE_EX_XP ends
    _MIB_MFE_STATS_TABLE_EX_XP typedef MIB_MFE_STATS_TABLE_EX_XP
    PMIB_MFE_STATS_TABLE_EX_XP typedef ptr MIB_MFE_STATS_TABLE_EX_XP
    if (NTDDI_VERSION ge NTDDI_WINXP)
      MIB_MFE_STATS_TABLE_EX typedef MIB_MFE_STATS_TABLE_EX_XP
      PMIB_MFE_STATS_TABLE_EX typedef ptr MIB_MFE_STATS_TABLE_EX_XP
      SIZEOF_BASIC_MIB_MFE_STATS_EX equ (FIELD_OFFSET (MIB_IPMCAST_MFE_STATS_EX, rgmiosOutStats [ 0 ]))
      SIZEOF_MIB_MFE_STATS_EX macro X
        exitm <(SIZEOF_BASIC_MIB_MFE_STATS_EX + ((X) * sizeof(MIB_IPMCAST_OIF_STATS)))>
      endm
    endif
    MIB_IPMCAST_GLOBAL struct
      dwEnable DWORD ?
    MIB_IPMCAST_GLOBAL ends
    _MIB_IPMCAST_GLOBAL typedef MIB_IPMCAST_GLOBAL
    PMIB_IPMCAST_GLOBAL typedef ptr MIB_IPMCAST_GLOBAL
    MIB_IPMCAST_IF_ENTRY struct
      dwIfIndex DWORD ?
      dwTtl DWORD ?
      dwProtocol DWORD ?
      dwRateLimit DWORD ?
      ulInMcastOctets ULONG ?
      ulOutMcastOctets ULONG ?
    MIB_IPMCAST_IF_ENTRY ends
    _MIB_IPMCAST_IF_ENTRY typedef MIB_IPMCAST_IF_ENTRY
    PMIB_IPMCAST_IF_ENTRY typedef ptr MIB_IPMCAST_IF_ENTRY
    MIB_IPMCAST_IF_TABLE struct
      dwNumEntries DWORD ?
      table MIB_IPMCAST_IF_ENTRY ANY_SIZE dup (<>)
    MIB_IPMCAST_IF_TABLE ends
    _MIB_IPMCAST_IF_TABLE typedef MIB_IPMCAST_IF_TABLE
    PMIB_IPMCAST_IF_TABLE typedef ptr MIB_IPMCAST_IF_TABLE
    SIZEOF_MCAST_IF_TABLE macro X
      exitm <(FIELD_OFFSET(MIB_IPMCAST_IF_TABLE, table [ 0 ]) + ((X) * sizeof(MIB_IPMCAST_IF_ENTRY)) + ALIGN_SIZE)>
    endm
    if Defined(_MSC_VER)
      if _MSC_VER ge 1200
      else
      endif
    endif
  endif
endif
