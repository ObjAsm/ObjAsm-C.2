;Include file created by h2inc+ version C.2.0 on (UTC) 15/06/2024 16:37:44
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\iprtrmib.h
;             Created on (UTC) 22/05/2024 17:57:07
;             Last modified on (UTC) 08/01/2024 17:04:20

ifndef __ROUTING_IPRTRMIB_H__
  __ROUTING_IPRTRMIB_H__ equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    include mprapidef.inc
    include ipifcons.inc
    IPRTRMGR_PID equ 10000
    ifndef ANY_SIZE
      ANY_SIZE equ 1
    endif
    IF_NUMBER equ 0
    IF_TABLE equ (IF_NUMBER + 1)
    IF_ROW equ (IF_TABLE + 1)
    IP_STATS equ (IF_ROW + 1)
    IP_ADDRTABLE equ (IP_STATS + 1)
    IP_ADDRROW equ (IP_ADDRTABLE + 1)
    IP_FORWARDNUMBER equ (IP_ADDRROW + 1)
    IP_FORWARDTABLE equ (IP_FORWARDNUMBER + 1)
    IP_FORWARDROW equ (IP_FORWARDTABLE + 1)
    IP_NETTABLE equ (IP_FORWARDROW + 1)
    IP_NETROW equ (IP_NETTABLE + 1)
    ICMP_STATS equ (IP_NETROW + 1)
    TCP_STATS equ (ICMP_STATS + 1)
    TCP_TABLE equ (TCP_STATS + 1)
    TCP_ROW equ (TCP_TABLE + 1)
    UDP_STATS equ (TCP_ROW + 1)
    UDP_TABLE equ (UDP_STATS + 1)
    UDP_ROW equ (UDP_TABLE + 1)
    MCAST_MFE equ (UDP_ROW + 1)
    MCAST_MFE_STATS equ (MCAST_MFE + 1)
    BEST_IF equ (MCAST_MFE_STATS + 1)
    BEST_ROUTE equ (BEST_IF + 1)
    PROXY_ARP equ (BEST_ROUTE + 1)
    MCAST_IF_ENTRY equ (PROXY_ARP + 1)
    MCAST_GLOBAL equ (MCAST_IF_ENTRY + 1)
    IF_STATUS equ (MCAST_GLOBAL + 1)
    MCAST_BOUNDARY equ (IF_STATUS + 1)
    MCAST_SCOPE equ (MCAST_BOUNDARY + 1)
    DEST_MATCHING equ (MCAST_SCOPE + 1)
    DEST_LONGER equ (DEST_MATCHING + 1)
    DEST_SHORTER equ (DEST_LONGER + 1)
    ROUTE_MATCHING equ (DEST_SHORTER + 1)
    ROUTE_LONGER equ (ROUTE_MATCHING + 1)
    ROUTE_SHORTER equ (ROUTE_LONGER + 1)
    ROUTE_STATE equ (ROUTE_SHORTER + 1)
    MCAST_MFE_STATS_EX equ (ROUTE_STATE + 1)
    IP6_STATS equ (MCAST_MFE_STATS_EX + 1)
    UDP6_STATS equ (IP6_STATS + 1)
    TCP6_STATS equ (UDP6_STATS + 1)
    if (NTDDI_VERSION ge NTDDI_VISTA)
      NUMBER_OF_EXPORTED_VARIABLES equ (TCP6_STATS + 1)
    else
      NUMBER_OF_EXPORTED_VARIABLES equ (ROUTE_STATE + 1)
    endif
    MIB_OPAQUE_QUERY struct
      dwVarId DWORD ?
      rgdwVarIndex DWORD ANY_SIZE dup (?)
    MIB_OPAQUE_QUERY ends
    _MIB_OPAQUE_QUERY typedef MIB_OPAQUE_QUERY
    PMIB_OPAQUE_QUERY typedef ptr MIB_OPAQUE_QUERY
    include ipmib.inc
    include tcpmib.inc
    include udpmib.inc
    TCP_TABLE_CLASS typedef SDWORD
    TCP_TABLE_BASIC_LISTENER equ 0
    TCP_TABLE_BASIC_CONNECTIONS equ 1
    TCP_TABLE_BASIC_ALL equ 2
    TCP_TABLE_OWNER_PID_LISTENER equ 3
    TCP_TABLE_OWNER_PID_CONNECTIONS equ 4
    TCP_TABLE_OWNER_PID_ALL equ 5
    TCP_TABLE_OWNER_MODULE_LISTENER equ 6
    TCP_TABLE_OWNER_MODULE_CONNECTIONS equ 7
    TCP_TABLE_OWNER_MODULE_ALL equ 8
    _TCP_TABLE_CLASS typedef TCP_TABLE_CLASS
    PTCP_TABLE_CLASS typedef ptr TCP_TABLE_CLASS
    UDP_TABLE_CLASS typedef SDWORD
    UDP_TABLE_BASIC equ 0
    UDP_TABLE_OWNER_PID equ 1
    UDP_TABLE_OWNER_MODULE equ 2
    _UDP_TABLE_CLASS typedef UDP_TABLE_CLASS
    PUDP_TABLE_CLASS typedef ptr UDP_TABLE_CLASS
    TCPIP_OWNER_MODULE_INFO_CLASS typedef SDWORD
    TCPIP_OWNER_MODULE_INFO_BASIC equ 0
    _TCPIP_OWNER_MODULE_INFO_CLASS typedef TCPIP_OWNER_MODULE_INFO_CLASS
    PTCPIP_OWNER_MODULE_INFO_CLASS typedef ptr TCPIP_OWNER_MODULE_INFO_CLASS
    TCPIP_OWNER_MODULE_BASIC_INFO struct
      pModuleName PWCHAR ?
      pModulePath PWCHAR ?
    TCPIP_OWNER_MODULE_BASIC_INFO ends
    _TCPIP_OWNER_MODULE_BASIC_INFO typedef TCPIP_OWNER_MODULE_BASIC_INFO
    PTCPIP_OWNER_MODULE_BASIC_INFO typedef ptr TCPIP_OWNER_MODULE_BASIC_INFO
    MIB_IPMCAST_BOUNDARY struct
      dwIfIndex DWORD ?
      dwGroupAddress DWORD ?
      dwGroupMask DWORD ?
      dwStatus DWORD ?
    MIB_IPMCAST_BOUNDARY ends
    _MIB_IPMCAST_BOUNDARY typedef MIB_IPMCAST_BOUNDARY
    PMIB_IPMCAST_BOUNDARY typedef ptr MIB_IPMCAST_BOUNDARY
    MIB_IPMCAST_BOUNDARY_TABLE struct
      dwNumEntries DWORD ?
      table MIB_IPMCAST_BOUNDARY ANY_SIZE dup (<>)
    MIB_IPMCAST_BOUNDARY_TABLE ends
    _MIB_IPMCAST_BOUNDARY_TABLE typedef MIB_IPMCAST_BOUNDARY_TABLE
    PMIB_IPMCAST_BOUNDARY_TABLE typedef ptr MIB_IPMCAST_BOUNDARY_TABLE
    SIZEOF_BOUNDARY_TABLE macro X
      exitm <(FIELD_OFFSET(MIB_IPMCAST_BOUNDARY_TABLE, table [ 0 ]) + ((X) * sizeof(MIB_IPMCAST_BOUNDARY)) + ALIGN_SIZE)>
    endm
    MIB_BOUNDARYROW struct
      dwGroupAddress DWORD ?
      dwGroupMask DWORD ?
    MIB_BOUNDARYROW ends
    PMIB_BOUNDARYROW typedef ptr MIB_BOUNDARYROW
    MIB_MCAST_LIMIT_ROW struct
      dwTtl DWORD ?
      dwRateLimit DWORD ?
    MIB_MCAST_LIMIT_ROW ends
    PMIB_MCAST_LIMIT_ROW typedef ptr MIB_MCAST_LIMIT_ROW
    MAX_SCOPE_NAME_LEN equ 255
    SN_UNICODE equ <>
    SN_CHAR typedef WCHAR
    SCOPE_NAME_BUFFER struct
      SN_CHAR MAX_SCOPE_NAME_LEN+1 dup (?)
    SCOPE_NAME_BUFFER ends
    SCOPE_NAME typedef ptr SN_CHAR
    MIB_IPMCAST_SCOPE struct
      dwGroupAddress DWORD ?
      dwGroupMask DWORD ?
      snNameBuffer SCOPE_NAME_BUFFER <>
      dwStatus DWORD ?
    MIB_IPMCAST_SCOPE ends
    _MIB_IPMCAST_SCOPE typedef MIB_IPMCAST_SCOPE
    PMIB_IPMCAST_SCOPE typedef ptr MIB_IPMCAST_SCOPE
    MIB_IPDESTROW struct
      dwForwardPreference DWORD ?
      dwForwardViewSet DWORD ?
    MIB_IPDESTROW ends
    _MIB_IPDESTROW typedef MIB_IPDESTROW
    PMIB_IPDESTROW typedef ptr MIB_IPDESTROW
    MIB_IPDESTTABLE struct
      dwNumEntries DWORD ?
      table MIB_IPDESTROW ANY_SIZE dup (<>)
    MIB_IPDESTTABLE ends
    _MIB_IPDESTTABLE typedef MIB_IPDESTTABLE
    PMIB_IPDESTTABLE typedef ptr MIB_IPDESTTABLE
    MIB_BEST_IF struct
      dwDestAddr DWORD ?
      dwIfIndex DWORD ?
    MIB_BEST_IF ends
    _MIB_BEST_IF typedef MIB_BEST_IF
    PMIB_BEST_IF typedef ptr MIB_BEST_IF
    MIB_PROXYARP struct
      dwAddress DWORD ?
      dwMask DWORD ?
      dwIfIndex DWORD ?
    MIB_PROXYARP ends
    _MIB_PROXYARP typedef MIB_PROXYARP
    PMIB_PROXYARP typedef ptr MIB_PROXYARP
    MIB_IFSTATUS struct
      dwIfIndex DWORD ?
      dwAdminStatus DWORD ?
      dwOperationalStatus DWORD ?
      bMHbeatActive BOOL ?
      bMHbeatAlive BOOL ?
    MIB_IFSTATUS ends
    _MIB_IFSTATUS typedef MIB_IFSTATUS
    PMIB_IFSTATUS typedef ptr MIB_IFSTATUS
    MIB_ROUTESTATE struct
      bRoutesSetToStack BOOL ?
    MIB_ROUTESTATE ends
    _MIB_ROUTESTATE typedef MIB_ROUTESTATE
    PMIB_ROUTESTATE typedef ptr MIB_ROUTESTATE
    MIB_OPAQUE_INFO struct
      dwId DWORD ?
      union
        ullAlign ULONGLONG ?
        rgbyData BYTE 1 dup (?)
      ends
    MIB_OPAQUE_INFO ends
    _MIB_OPAQUE_INFO typedef MIB_OPAQUE_INFO
    PMIB_OPAQUE_INFO typedef ptr MIB_OPAQUE_INFO
    MAX_MIB_OFFSET equ 8
    MIB_INFO_SIZE macro S
      exitm <(MAX_MIB_OFFSET + sizeof(S))>
    endm
    MIB_INFO_SIZE_IN_DWORDS macro S
      exitm <((MIB_INFO_SIZE(S)) / sizeof(DWORD) + 1)>
    endm
    DEFINE_MIB_BUFFER macro X, Y, Z
      exitm <DWORD __rgdwBuff [ MIB_INFO_SIZE_IN_DWORDS(Y) ] ; PMIB_OPAQUE_INFO X = (PMIB_OPAQUE_INFO) __rgdwBuff ; Y * Z = (Y *) (X - rgbyData)>
    endm
    CAST_MIB_INFO macro X, Y, Z
      exitm <Z = (Y) (X - rgbyData)>
    endm
  endif
endif
