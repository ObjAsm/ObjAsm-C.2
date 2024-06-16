;Include file created by h2inc+ version C.2.0 on (UTC) 15/06/2024 16:37:44
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\netioapi.h
;             Created on (UTC) 22/05/2024 17:57:07
;             Last modified on (UTC) 12/02/2024 17:05:30
;Errors = 0
;Warnings = 2

ifndef _NETIOAPI_H_
  _NETIOAPI_H_ equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    ifdef __cplusplus
      ;[...]
    endif
    ifndef ANY_SIZE
      ANY_SIZE equ 1
    endif
    ifdef __IPHLPAPI_H__
      NETIO_STATUS equ <DWORD>
      NETIO_SUCCESS macro x
        exitm <((x) == NO_ERROR)>
      endm
      NETIOAPI_API_ equ <WINAPI>
      _NETIOAPI_SUCCESS_ equ _Success_(return eq NO_ERROR)
    else
      include ws2def.inc
      include ws2ipdef.inc
      include ifdef.inc
      include nldef.inc
      NETIO_STATUS equ <NTSTATUS>
      NETIO_SUCCESS macro x
        exitm <NT_SUCCESS (x)>
      endm
      NETIOAPI_API_ equ <NTAPI>
      _NETIOAPI_SUCCESS_ equ <>
      ifdef IPHLPAPI_DLL_LINKAGE
      endif
      IPHLPAPI_DLL_LINKAGE equ <>
    endif
    NETIOAPI_API equ <NETIO_STATUS NETIOAPI_API_>
    MIB_NOTIFICATION_TYPE typedef SDWORD
    MibParameterNotification equ 0
    MibAddInstance equ 1
    MibDeleteInstance equ 2
    MibInitialNotification equ 3
    _MIB_NOTIFICATION_TYPE typedef MIB_NOTIFICATION_TYPE
    PMIB_NOTIFICATION_TYPE typedef ptr MIB_NOTIFICATION_TYPE
  endif
  ifdef _WS2IPDEF_
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      include ntddndis.inc
      MIB_IF_ROW2 struct
        InterfaceLuid NET_LUID <>
        InterfaceIndex NET_IFINDEX ?
        InterfaceGuid GUID <>
        Alias_ WCHAR IF_MAX_STRING_SIZE + 1 dup (?)
        Description WCHAR IF_MAX_STRING_SIZE + 1 dup (?)
        PhysicalAddressLength ULONG ?
        PhysicalAddress UCHAR IF_MAX_PHYS_ADDRESS_LENGTH dup (?)
        PermanentPhysicalAddress UCHAR IF_MAX_PHYS_ADDRESS_LENGTH dup (?)
        Mtu ULONG ?
        Type_ IFTYPE ?
        TunnelType TUNNEL_TYPE ?
        MediaType NDIS_MEDIUM ?
        PhysicalMediumType NDIS_PHYSICAL_MEDIUM ?
        AccessType NET_IF_ACCESS_TYPE ?
        DirectionType NET_IF_DIRECTION_TYPE ?
        struct InterfaceAndOperStatusFlags
          InterfaceAndOperStatusFlags_REC record InterfaceAndOperStatusFlags_REC_EndPointInterface:1, InterfaceAndOperStatusFlags_REC_LowPower:1, InterfaceAndOperStatusFlags_REC_Paused:1, InterfaceAndOperStatusFlags_REC_NotMediaConnected:1, InterfaceAndOperStatusFlags_REC_NotAuthenticated:1, InterfaceAndOperStatusFlags_REC_ConnectorPresent:1, InterfaceAndOperStatusFlags_REC_FilterInterface:1, InterfaceAndOperStatusFlags_REC_HardwareInterface:1
          InterfaceAndOperStatusFlags_BITS InterfaceAndOperStatusFlags_REC <>
        ends
        OperStatus IF_OPER_STATUS ?
        AdminStatus NET_IF_ADMIN_STATUS ?
        MediaConnectState NET_IF_MEDIA_CONNECT_STATE ?
        NetworkGuid NET_IF_NETWORK_GUID <>
        ConnectionType NET_IF_CONNECTION_TYPE ?
        TransmitLinkSpeed ULONG64 ?
        ReceiveLinkSpeed ULONG64 ?
        InOctets ULONG64 ?
        InUcastPkts ULONG64 ?
        InNUcastPkts ULONG64 ?
        InDiscards ULONG64 ?
        InErrors ULONG64 ?
        InUnknownProtos ULONG64 ?
        InUcastOctets ULONG64 ?
        InMulticastOctets ULONG64 ?
        InBroadcastOctets ULONG64 ?
        OutOctets ULONG64 ?
        OutUcastPkts ULONG64 ?
        OutNUcastPkts ULONG64 ?
        OutDiscards ULONG64 ?
        OutErrors ULONG64 ?
        OutUcastOctets ULONG64 ?
        OutMulticastOctets ULONG64 ?
        OutBroadcastOctets ULONG64 ?
        OutQLen ULONG64 ?
      MIB_IF_ROW2 ends
      _MIB_IF_ROW2 typedef MIB_IF_ROW2
      PMIB_IF_ROW2 typedef ptr MIB_IF_ROW2
      MIB_IF_TABLE2 struct
        NumEntries ULONG ?
        Table MIB_IF_ROW2 ANY_SIZE dup (<>)
      MIB_IF_TABLE2 ends
      _MIB_IF_TABLE2 typedef MIB_IF_TABLE2
      PMIB_IF_TABLE2 typedef ptr MIB_IF_TABLE2
      GetIfEntry2 proto WIN_STD_CALL_CONV :PMIB_IF_ROW2
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      if (NTDDI_VERSION ge NTDDI_WIN10_RS2)
        MIB_IF_ENTRY_LEVEL typedef SDWORD
        MibIfEntryNormal equ 0
        MibIfEntryNormalWithoutStatistics equ 2
        _MIB_IF_ENTRY_LEVEL typedef MIB_IF_ENTRY_LEVEL
        PMIB_IF_ENTRY_LEVEL typedef ptr MIB_IF_ENTRY_LEVEL
        GetIfEntry2Ex proto WIN_STD_CALL_CONV :MIB_IF_ENTRY_LEVEL, :PMIB_IF_ROW2
      endif
      GetIfTable2 proto WIN_STD_CALL_CONV :ptr PMIB_IF_TABLE2
      MIB_IF_TABLE_LEVEL typedef SDWORD
      MibIfTableNormal equ 0
      MibIfTableRaw equ 1
      if (NTDDI_VERSION ge NTDDI_WIN10_RS2)
        MibIfTableNormalWithoutStatisticsendif
       equ 2
      _MIB_IF_TABLE_LEVEL typedef MIB_IF_TABLE_LEVEL
      PMIB_IF_TABLE_LEVEL typedef ptr MIB_IF_TABLE_LEVEL
      GetIfTable2Ex proto WIN_STD_CALL_CONV :MIB_IF_TABLE_LEVEL, :ptr PMIB_IF_TABLE2
      MIB_IPINTERFACE_ROW struct
        Family ADDRESS_FAMILY ?
        InterfaceLuid NET_LUID <>
        InterfaceIndex NET_IFINDEX ?
        MaxReassemblySize ULONG ?
        InterfaceIdentifier ULONG64 ?
        MinRouterAdvertisementInterval ULONG ?
        MaxRouterAdvertisementInterval ULONG ?
        AdvertisingEnabled BOOLEAN ?
        ForwardingEnabled BOOLEAN ?
        WeakHostSend BOOLEAN ?
        WeakHostReceive BOOLEAN ?
        UseAutomaticMetric BOOLEAN ?
        UseNeighborUnreachabilityDetection BOOLEAN ?
        ManagedAddressConfigurationSupported BOOLEAN ?
        OtherStatefulConfigurationSupported BOOLEAN ?
        AdvertiseDefaultRoute BOOLEAN ?
        RouterDiscoveryBehavior NL_ROUTER_DISCOVERY_BEHAVIOR ?
        DadTransmits ULONG ?
        BaseReachableTime ULONG ?
        RetransmitTime ULONG ?
        PathMtuDiscoveryTimeout ULONG ?
        LinkLocalAddressBehavior NL_LINK_LOCAL_ADDRESS_BEHAVIOR ?
        LinkLocalAddressTimeout ULONG ?
        ZoneIndices ULONG ScopeLevelCount dup (?)
        SitePrefixLength ULONG ?
        Metric ULONG ?
        NlMtu ULONG ?
        Connected BOOLEAN ?
        SupportsWakeUpPatterns BOOLEAN ?
        SupportsNeighborDiscovery BOOLEAN ?
        SupportsRouterDiscovery BOOLEAN ?
        ReachableTime ULONG ?
        TransmitOffload NL_INTERFACE_OFFLOAD_ROD <>
        ReceiveOffload NL_INTERFACE_OFFLOAD_ROD <>
        DisableDefaultRoutes BOOLEAN ?
      MIB_IPINTERFACE_ROW ends
      _MIB_IPINTERFACE_ROW typedef MIB_IPINTERFACE_ROW
      PMIB_IPINTERFACE_ROW typedef ptr MIB_IPINTERFACE_ROW
      MIB_IPINTERFACE_TABLE struct
        NumEntries ULONG ?
        Table MIB_IPINTERFACE_ROW ANY_SIZE dup (<>)
      MIB_IPINTERFACE_TABLE ends
      _MIB_IPINTERFACE_TABLE typedef MIB_IPINTERFACE_TABLE
      PMIB_IPINTERFACE_TABLE typedef ptr MIB_IPINTERFACE_TABLE
      MIB_IFSTACK_ROW struct
        HigherLayerInterfaceIndex NET_IFINDEX ?
        LowerLayerInterfaceIndex NET_IFINDEX ?
      MIB_IFSTACK_ROW ends
      _MIB_IFSTACK_ROW typedef MIB_IFSTACK_ROW
      PMIB_IFSTACK_ROW typedef ptr MIB_IFSTACK_ROW
      MIB_INVERTEDIFSTACK_ROW struct
        LowerLayerInterfaceIndex NET_IFINDEX ?
        HigherLayerInterfaceIndex NET_IFINDEX ?
      MIB_INVERTEDIFSTACK_ROW ends
      _MIB_INVERTEDIFSTACK_ROW typedef MIB_INVERTEDIFSTACK_ROW
      PMIB_INVERTEDIFSTACK_ROW typedef ptr MIB_INVERTEDIFSTACK_ROW
      MIB_IFSTACK_TABLE struct
        NumEntries ULONG ?
        Table MIB_IFSTACK_ROW ANY_SIZE dup (<>)
      MIB_IFSTACK_TABLE ends
      _MIB_IFSTACK_TABLE typedef MIB_IFSTACK_TABLE
      PMIB_IFSTACK_TABLE typedef ptr MIB_IFSTACK_TABLE
      MIB_INVERTEDIFSTACK_TABLE struct
        NumEntries ULONG ?
        Table MIB_INVERTEDIFSTACK_ROW ANY_SIZE dup (<>)
      MIB_INVERTEDIFSTACK_TABLE ends
      _MIB_INVERTEDIFSTACK_TABLE typedef MIB_INVERTEDIFSTACK_TABLE
      PMIB_INVERTEDIFSTACK_TABLE typedef ptr MIB_INVERTEDIFSTACK_TABLE
      TYPE_PIPINTERFACE_CHANGE_CALLBACK typedef proto WIN_STD_CALL_CONV :PVOID, :PMIB_IPINTERFACE_ROW, :MIB_NOTIFICATION_TYPE
      PIPINTERFACE_CHANGE_CALLBACK typedef ptr TYPE_PIPINTERFACE_CHANGE_CALLBACK

      MIB_IP_NETWORK_CONNECTION_BANDWIDTH_ESTIMATES struct
        InboundBandwidthInformation NL_BANDWIDTH_INFORMATION <>
        OutboundBandwidthInformation NL_BANDWIDTH_INFORMATION <>
      MIB_IP_NETWORK_CONNECTION_BANDWIDTH_ESTIMATES ends
      _MIB_IP_NETWORK_CONNECTION_BANDWIDTH_ESTIMATES typedef MIB_IP_NETWORK_CONNECTION_BANDWIDTH_ESTIMATES
      PMIB_IP_NETWORK_CONNECTION_BANDWIDTH_ESTIMATES typedef ptr MIB_IP_NETWORK_CONNECTION_BANDWIDTH_ESTIMATES
      GetIfStackTable proto WIN_STD_CALL_CONV :ptr PMIB_IFSTACK_TABLE
      GetInvertedIfStackTable proto WIN_STD_CALL_CONV :ptr PMIB_INVERTEDIFSTACK_TABLE
      GetIpInterfaceEntry proto WIN_STD_CALL_CONV :PMIB_IPINTERFACE_ROW
      GetIpInterfaceTable proto WIN_STD_CALL_CONV :ADDRESS_FAMILY, :ptr PMIB_IPINTERFACE_TABLE
      InitializeIpInterfaceEntry proto WIN_STD_CALL_CONV :PMIB_IPINTERFACE_ROW
      NotifyIpInterfaceChange proto WIN_STD_CALL_CONV :ADDRESS_FAMILY, :PIPINTERFACE_CHANGE_CALLBACK, :PVOID, :BOOLEAN, :ptr HANDLE
      SetIpInterfaceEntry proto WIN_STD_CALL_CONV :PMIB_IPINTERFACE_ROW
      GetIpNetworkConnectionBandwidthEstimates proto WIN_STD_CALL_CONV :NET_IFINDEX, :ADDRESS_FAMILY, :PMIB_IP_NETWORK_CONNECTION_BANDWIDTH_ESTIMATES
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      MIB_UNICASTIPADDRESS_ROW struct
        Address SOCKADDR_INET <>
        InterfaceLuid NET_LUID <>
        InterfaceIndex NET_IFINDEX ?
        PrefixOrigin NL_PREFIX_ORIGIN ?
        SuffixOrigin NL_SUFFIX_ORIGIN ?
        ValidLifetime ULONG ?
        PreferredLifetime ULONG ?
        OnLinkPrefixLength UINT8 ?
        SkipAsSource BOOLEAN ?
        DadState NL_DAD_STATE ?
        ScopeId SCOPE_ID <>
        CreationTimeStamp LARGE_INTEGER <>
      MIB_UNICASTIPADDRESS_ROW ends
      _MIB_UNICASTIPADDRESS_ROW typedef MIB_UNICASTIPADDRESS_ROW
      PMIB_UNICASTIPADDRESS_ROW typedef ptr MIB_UNICASTIPADDRESS_ROW
      MIB_UNICASTIPADDRESS_TABLE struct
        NumEntries ULONG ?
        Table MIB_UNICASTIPADDRESS_ROW ANY_SIZE dup (<>)
      MIB_UNICASTIPADDRESS_TABLE ends
      _MIB_UNICASTIPADDRESS_TABLE typedef MIB_UNICASTIPADDRESS_TABLE
      PMIB_UNICASTIPADDRESS_TABLE typedef ptr MIB_UNICASTIPADDRESS_TABLE
      TYPE_PUNICAST_IPADDRESS_CHANGE_CALLBACK typedef proto WIN_STD_CALL_CONV :PVOID, :PMIB_UNICASTIPADDRESS_ROW, :MIB_NOTIFICATION_TYPE
      PUNICAST_IPADDRESS_CHANGE_CALLBACK typedef ptr TYPE_PUNICAST_IPADDRESS_CHANGE_CALLBACK

    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      CreateUnicastIpAddressEntry proto WIN_STD_CALL_CONV :ptr MIB_UNICASTIPADDRESS_ROW
      DeleteUnicastIpAddressEntry proto WIN_STD_CALL_CONV :ptr MIB_UNICASTIPADDRESS_ROW
      GetUnicastIpAddressEntry proto WIN_STD_CALL_CONV :PMIB_UNICASTIPADDRESS_ROW
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      GetUnicastIpAddressTable proto WIN_STD_CALL_CONV :ADDRESS_FAMILY, :ptr PMIB_UNICASTIPADDRESS_TABLE
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      InitializeUnicastIpAddressEntry proto WIN_STD_CALL_CONV :PMIB_UNICASTIPADDRESS_ROW
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      NotifyUnicastIpAddressChange proto WIN_STD_CALL_CONV :ADDRESS_FAMILY, :PUNICAST_IPADDRESS_CHANGE_CALLBACK, :PVOID, :BOOLEAN, :ptr HANDLE
      TYPE_PSTABLE_UNICAST_IPADDRESS_TABLE_CALLBACK typedef proto WIN_STD_CALL_CONV :PVOID, :PMIB_UNICASTIPADDRESS_TABLE
      PSTABLE_UNICAST_IPADDRESS_TABLE_CALLBACK typedef ptr TYPE_PSTABLE_UNICAST_IPADDRESS_TABLE_CALLBACK

      NotifyStableUnicastIpAddressTable proto WIN_STD_CALL_CONV :ADDRESS_FAMILY, :ptr PMIB_UNICASTIPADDRESS_TABLE, :PSTABLE_UNICAST_IPADDRESS_TABLE_CALLBACK, :PVOID, :ptr HANDLE
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      SetUnicastIpAddressEntry proto WIN_STD_CALL_CONV :ptr MIB_UNICASTIPADDRESS_ROW
      MIB_ANYCASTIPADDRESS_ROW struct
        Address SOCKADDR_INET <>
        InterfaceLuid NET_LUID <>
        InterfaceIndex NET_IFINDEX ?
        ScopeId SCOPE_ID <>
      MIB_ANYCASTIPADDRESS_ROW ends
      _MIB_ANYCASTIPADDRESS_ROW typedef MIB_ANYCASTIPADDRESS_ROW
      PMIB_ANYCASTIPADDRESS_ROW typedef ptr MIB_ANYCASTIPADDRESS_ROW
      MIB_ANYCASTIPADDRESS_TABLE struct
        NumEntries ULONG ?
        Table MIB_ANYCASTIPADDRESS_ROW ANY_SIZE dup (<>)
      MIB_ANYCASTIPADDRESS_TABLE ends
      _MIB_ANYCASTIPADDRESS_TABLE typedef MIB_ANYCASTIPADDRESS_TABLE
      PMIB_ANYCASTIPADDRESS_TABLE typedef ptr MIB_ANYCASTIPADDRESS_TABLE
      CreateAnycastIpAddressEntry proto WIN_STD_CALL_CONV :ptr MIB_ANYCASTIPADDRESS_ROW
      DeleteAnycastIpAddressEntry proto WIN_STD_CALL_CONV :ptr MIB_ANYCASTIPADDRESS_ROW
      GetAnycastIpAddressEntry proto WIN_STD_CALL_CONV :PMIB_ANYCASTIPADDRESS_ROW
      GetAnycastIpAddressTable proto WIN_STD_CALL_CONV :ADDRESS_FAMILY, :ptr PMIB_ANYCASTIPADDRESS_TABLE
      MIB_MULTICASTIPADDRESS_ROW struct
        Address SOCKADDR_INET <>
        InterfaceIndex NET_IFINDEX ?
        InterfaceLuid NET_LUID <>
        ScopeId SCOPE_ID <>
      MIB_MULTICASTIPADDRESS_ROW ends
      _MIB_MULTICASTIPADDRESS_ROW typedef MIB_MULTICASTIPADDRESS_ROW
      PMIB_MULTICASTIPADDRESS_ROW typedef ptr MIB_MULTICASTIPADDRESS_ROW
      MIB_MULTICASTIPADDRESS_TABLE struct
        NumEntries ULONG ?
        Table MIB_MULTICASTIPADDRESS_ROW ANY_SIZE dup (<>)
      MIB_MULTICASTIPADDRESS_TABLE ends
      _MIB_MULTICASTIPADDRESS_TABLE typedef MIB_MULTICASTIPADDRESS_TABLE
      PMIB_MULTICASTIPADDRESS_TABLE typedef ptr MIB_MULTICASTIPADDRESS_TABLE
      GetMulticastIpAddressEntry proto WIN_STD_CALL_CONV :PMIB_MULTICASTIPADDRESS_ROW
      GetMulticastIpAddressTable proto WIN_STD_CALL_CONV :ADDRESS_FAMILY, :ptr PMIB_MULTICASTIPADDRESS_TABLE
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      IP_ADDRESS_PREFIX struct
        Prefix SOCKADDR_INET <>
        PrefixLength UINT8 ?
      IP_ADDRESS_PREFIX ends
      _IP_ADDRESS_PREFIX typedef IP_ADDRESS_PREFIX
      PIP_ADDRESS_PREFIX typedef ptr IP_ADDRESS_PREFIX
      MIB_IPFORWARD_ROW2 struct
        InterfaceLuid NET_LUID <>
        InterfaceIndex NET_IFINDEX ?
        DestinationPrefix IP_ADDRESS_PREFIX <>
        NextHop SOCKADDR_INET <>
        SitePrefixLength UCHAR ?
        ValidLifetime ULONG ?
        PreferredLifetime ULONG ?
        Metric ULONG ?
        Protocol NL_ROUTE_PROTOCOL ?
        Loopback BOOLEAN ?
        AutoconfigureAddress BOOLEAN ?
        Publish BOOLEAN ?
        Immortal BOOLEAN ?
        Age ULONG ?
        Origin NL_ROUTE_ORIGIN ?
      MIB_IPFORWARD_ROW2 ends
      _MIB_IPFORWARD_ROW2 typedef MIB_IPFORWARD_ROW2
      PMIB_IPFORWARD_ROW2 typedef ptr MIB_IPFORWARD_ROW2
      MIB_IPFORWARD_TABLE2 struct
        NumEntries ULONG ?
        Table MIB_IPFORWARD_ROW2 ANY_SIZE dup (<>)
      MIB_IPFORWARD_TABLE2 ends
      _MIB_IPFORWARD_TABLE2 typedef MIB_IPFORWARD_TABLE2
      PMIB_IPFORWARD_TABLE2 typedef ptr MIB_IPFORWARD_TABLE2
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      TYPE_PIPFORWARD_CHANGE_CALLBACK typedef proto WIN_STD_CALL_CONV :PVOID, :PMIB_IPFORWARD_ROW2, :MIB_NOTIFICATION_TYPE
      PIPFORWARD_CHANGE_CALLBACK typedef ptr TYPE_PIPFORWARD_CHANGE_CALLBACK

      CreateIpForwardEntry2 proto WIN_STD_CALL_CONV :ptr MIB_IPFORWARD_ROW2
      DeleteIpForwardEntry2 proto WIN_STD_CALL_CONV :ptr MIB_IPFORWARD_ROW2
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      GetBestRoute2 proto WIN_STD_CALL_CONV :ptr NET_LUID, :NET_IFINDEX, :ptr SOCKADDR_INET, :ptr SOCKADDR_INET, :ULONG, :PMIB_IPFORWARD_ROW2, :ptr SOCKADDR_INET
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      GetIpForwardEntry2 proto WIN_STD_CALL_CONV :PMIB_IPFORWARD_ROW2
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      GetIpForwardTable2 proto WIN_STD_CALL_CONV :ADDRESS_FAMILY, :ptr PMIB_IPFORWARD_TABLE2
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      InitializeIpForwardEntry proto WIN_STD_CALL_CONV :PMIB_IPFORWARD_ROW2
      NotifyRouteChange2 proto WIN_STD_CALL_CONV :ADDRESS_FAMILY, :PIPFORWARD_CHANGE_CALLBACK, :PVOID, :BOOLEAN, :ptr HANDLE
      SetIpForwardEntry2 proto WIN_STD_CALL_CONV :ptr MIB_IPFORWARD_ROW2
      MIB_IPPATH_ROW struct
        Source SOCKADDR_INET <>
        Destination SOCKADDR_INET <>
        InterfaceLuid NET_LUID <>
        InterfaceIndex NET_IFINDEX ?
        CurrentNextHop SOCKADDR_INET <>
        PathMtu ULONG ?
        RttMean ULONG ?
        RttDeviation ULONG ?
        union
          LastReachable ULONG ?
          LastUnreachable ULONG ?
        ends
        IsReachable BOOLEAN ?
        LinkTransmitSpeed ULONG64 ?
        LinkReceiveSpeed ULONG64 ?
      MIB_IPPATH_ROW ends
      _MIB_IPPATH_ROW typedef MIB_IPPATH_ROW
      PMIB_IPPATH_ROW typedef ptr MIB_IPPATH_ROW
      MIB_IPPATH_TABLE struct
        NumEntries ULONG ?
        Table MIB_IPPATH_ROW ANY_SIZE dup (<>)
      MIB_IPPATH_TABLE ends
      _MIB_IPPATH_TABLE typedef MIB_IPPATH_TABLE
      PMIB_IPPATH_TABLE typedef ptr MIB_IPPATH_TABLE
      FlushIpPathTable proto WIN_STD_CALL_CONV :ADDRESS_FAMILY
      GetIpPathEntry proto WIN_STD_CALL_CONV :PMIB_IPPATH_ROW
      GetIpPathTable proto WIN_STD_CALL_CONV :ADDRESS_FAMILY, :ptr PMIB_IPPATH_TABLE
      MIB_IPNET_ROW2 struct
        Address SOCKADDR_INET <>
        InterfaceIndex NET_IFINDEX ?
        InterfaceLuid NET_LUID <>
        PhysicalAddress UCHAR IF_MAX_PHYS_ADDRESS_LENGTH dup (?)
        PhysicalAddressLength ULONG ?
        State NL_NEIGHBOR_STATE ?
        union
          struct
            ANONYMOUS_REC8 record ANONYMOUS_REC8_IsUnreachable:1, ANONYMOUS_REC8_IsRouter:1
            ANONYMOUS_REC8 <>
          ends
          Flags UCHAR ?
        ends
        union ReachabilityTime
          LastReachable ULONG ?
          LastUnreachable ULONG ?
        ends
      MIB_IPNET_ROW2 ends
      _MIB_IPNET_ROW2 typedef MIB_IPNET_ROW2
      PMIB_IPNET_ROW2 typedef ptr MIB_IPNET_ROW2
      MIB_IPNET_TABLE2 struct
        NumEntries ULONG ?
        Table MIB_IPNET_ROW2 ANY_SIZE dup (<>)
      MIB_IPNET_TABLE2 ends
      _MIB_IPNET_TABLE2 typedef MIB_IPNET_TABLE2
      PMIB_IPNET_TABLE2 typedef ptr MIB_IPNET_TABLE2
      CreateIpNetEntry2 proto WIN_STD_CALL_CONV :ptr MIB_IPNET_ROW2
      DeleteIpNetEntry2 proto WIN_STD_CALL_CONV :ptr MIB_IPNET_ROW2
      FlushIpNetTable2 proto WIN_STD_CALL_CONV :ADDRESS_FAMILY, :NET_IFINDEX
      GetIpNetEntry2 proto WIN_STD_CALL_CONV :PMIB_IPNET_ROW2
      GetIpNetTable2 proto WIN_STD_CALL_CONV :ADDRESS_FAMILY, :ptr PMIB_IPNET_TABLE2
      ResolveIpNetEntry2 proto WIN_STD_CALL_CONV :PMIB_IPNET_ROW2, :ptr SOCKADDR_INET
      SetIpNetEntry2 proto WIN_STD_CALL_CONV :PMIB_IPNET_ROW2
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      MIB_INVALID_TEREDO_PORT_NUMBER equ 0
      TYPE_PTEREDO_PORT_CHANGE_CALLBACK typedef proto WIN_STD_CALL_CONV :PVOID, :USHORT, :MIB_NOTIFICATION_TYPE
      PTEREDO_PORT_CHANGE_CALLBACK typedef ptr TYPE_PTEREDO_PORT_CHANGE_CALLBACK

      NotifyTeredoPortChange proto WIN_STD_CALL_CONV :PTEREDO_PORT_CHANGE_CALLBACK, :PVOID, :BOOLEAN, :ptr HANDLE
      GetTeredoPort proto WIN_STD_CALL_CONV :ptr USHORT
      ifndef TEREDO_API_NO_DEPRECATE
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      CancelMibChangeNotify2 proto WIN_STD_CALL_CONV :HANDLE
      FreeMibTable proto WIN_STD_CALL_CONV :PVOID
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      CreateSortedAddressPairs proto WIN_STD_CALL_CONV :PSOCKADDR_IN6, :ULONG, :PSOCKADDR_IN6, :ULONG, :ULONG, :ptr PSOCKADDR_IN6_PAIR, :ptr ULONG
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    ConvertCompartmentGuidToId proto WIN_STD_CALL_CONV :ptr GUID, :PNET_IF_COMPARTMENT_ID
    ConvertCompartmentIdToGuid proto WIN_STD_CALL_CONV :NET_IF_COMPARTMENT_ID, :ptr GUID
    ConvertInterfaceNameToLuidA proto WIN_STD_CALL_CONV :ptr CHAR, :ptr NET_LUID
    ConvertInterfaceNameToLuidW proto WIN_STD_CALL_CONV :ptr WCHAR, :ptr NET_LUID
    ConvertInterfaceLuidToNameA proto WIN_STD_CALL_CONV :ptr NET_LUID, :PSTR, :SIZE_T
    ConvertInterfaceLuidToNameW proto WIN_STD_CALL_CONV :ptr NET_LUID, :PWSTR, :SIZE_T
    ConvertInterfaceLuidToIndex proto WIN_STD_CALL_CONV :ptr NET_LUID, :PNET_IFINDEX
    ConvertInterfaceIndexToLuid proto WIN_STD_CALL_CONV :NET_IFINDEX, :PNET_LUID
    ConvertInterfaceLuidToAlias proto WIN_STD_CALL_CONV :ptr NET_LUID, :PWSTR, :SIZE_T
    ConvertInterfaceAliasToLuid proto WIN_STD_CALL_CONV :ptr WCHAR, :PNET_LUID
    ConvertInterfaceLuidToGuid proto WIN_STD_CALL_CONV :ptr NET_LUID, :ptr GUID
    ConvertInterfaceGuidToLuid proto WIN_STD_CALL_CONV :ptr GUID, :PNET_LUID
    IF_NAMESIZE equ <NDIS_IF_MAX_STRING_SIZE>
    if_nametoindex proto WIN_STD_CALL_CONV :PCSTR
    if_indextoname proto WIN_STD_CALL_CONV :NET_IFINDEX, :PCHAR
    GetCurrentThreadCompartmentId proto WIN_STD_CALL_CONV
    SetCurrentThreadCompartmentId proto WIN_STD_CALL_CONV :NET_IF_COMPARTMENT_ID
    GetCurrentThreadCompartmentScope proto WIN_STD_CALL_CONV :PNET_IF_COMPARTMENT_SCOPE, :PNET_IF_COMPARTMENT_ID
    SetCurrentThreadCompartmentScope proto WIN_STD_CALL_CONV :NET_IF_COMPARTMENT_SCOPE
    GetJobCompartmentId proto WIN_STD_CALL_CONV :HANDLE
    SetJobCompartmentId proto WIN_STD_CALL_CONV :HANDLE, :NET_IF_COMPARTMENT_ID
    GetSessionCompartmentId proto WIN_STD_CALL_CONV :ULONG
    SetSessionCompartmentId proto WIN_STD_CALL_CONV :ULONG, :NET_IF_COMPARTMENT_ID
    GetDefaultCompartmentId proto WIN_STD_CALL_CONV
    GetNetworkInformation proto WIN_STD_CALL_CONV :ptr NET_IF_NETWORK_GUID, :PNET_IF_COMPARTMENT_ID, :PULONG, :PWCHAR, :ULONG
    SetNetworkInformation proto WIN_STD_CALL_CONV :ptr NET_IF_NETWORK_GUID, :NET_IF_COMPARTMENT_ID, :ptr WCHAR
    ConvertLengthToIpv4Mask proto WIN_STD_CALL_CONV :ULONG, :PULONG
    ConvertIpv4MaskToLength proto WIN_STD_CALL_CONV :ULONG, :PUINT8
    DNS_SETTINGS_VERSION1 equ 0001h
    DNS_SETTINGS_VERSION2 equ 0002h
    DNS_INTERFACE_SETTINGS_VERSION1 equ 0001h
    DNS_INTERFACE_SETTINGS_VERSION2 equ 0002h
    DNS_INTERFACE_SETTINGS_VERSION3 equ 0003h
    DNS_INTERFACE_SETTINGS_VERSION4 equ 0004h
    DNS_SETTING_IPV6 equ 0001h
    DNS_SETTING_NAMESERVER equ 0002h
    DNS_SETTING_SEARCHLIST equ 0004h
    DNS_SETTING_REGISTRATION_ENABLED equ 0008h
    DNS_SETTING_REGISTER_ADAPTER_NAME equ 0010h
    DNS_SETTING_DOMAIN equ 0020h
    DNS_SETTING_HOSTNAME equ 0040h
    DNS_SETTINGS_ENABLE_LLMNR equ 0080h
    DNS_SETTINGS_QUERY_ADAPTER_NAME equ 0100h
    DNS_SETTING_PROFILE_NAMESERVER equ 0200h
    DNS_SETTING_DISABLE_UNCONSTRAINED_QUERIES equ 0400h
    DNS_SETTING_SUPPLEMENTAL_SEARCH_LIST equ 0800h
    DNS_SETTING_DOH equ 1000h
    DNS_SETTING_DOH_PROFILE equ 2000h
    DNS_SETTING_ENCRYPTED_DNS_ADAPTER_FLAGS equ 4000h
    DNS_SETTING_DDR equ 8000h
    DNS_ENABLE_DOH equ 0001h
    DNS_DOH_POLICY_NOT_CONFIGURED equ 0004h
    DNS_DOH_POLICY_DISABLE equ 0008h
    DNS_DOH_POLICY_AUTO equ 0010h
    DNS_DOH_POLICY_REQUIRED equ 0020h
    DNS_ENABLE_DDR equ 0040h
    DNS_SERVER_PROPERTY_VERSION1 equ 0001h
    DNS_DOH_SERVER_SETTINGS_ENABLE_AUTO equ 0001h
    DNS_DOH_SERVER_SETTINGS_ENABLE equ 0002h
    DNS_DOH_SERVER_SETTINGS_FALLBACK_TO_UDP equ 0004h
    DNS_DOH_AUTO_UPGRADE_SERVER equ 0008h
    DNS_DOH_SERVER_SETTINGS_ENABLE_DDR equ 0010h
    DNS_DDR_ADAPTER_ENABLE_DOH equ 0001h
    DNS_DDR_ADAPTER_ENABLE_UDP_FALLBACK equ 0002h
    DNS_SETTINGS struct
      Version ULONG ?
      Flags ULONG64 ?
      Hostname PWSTR ?
      Domain PWSTR ?
      SearchList PWSTR ?
    DNS_SETTINGS ends
    _DNS_SETTINGS typedef DNS_SETTINGS
    DNS_SETTINGS2 struct
      Version ULONG ?
      Flags ULONG64 ?
      Hostname PWSTR ?
      Domain PWSTR ?
      SearchList PWSTR ?
      SettingFlags ULONG64 ?
    DNS_SETTINGS2 ends
    _DNS_SETTINGS2 typedef DNS_SETTINGS2
    DNS_DOH_SERVER_SETTINGS struct
      ifdef MIDL_PASS
        ;[...]
      else
        Template PWSTR ?
      endif
      Flags ULONG64 ?
    DNS_DOH_SERVER_SETTINGS ends
    _DNS_DOH_SERVER_SETTINGS typedef DNS_DOH_SERVER_SETTINGS
    DNS_SERVER_PROPERTY_TYPE typedef SDWORD
    DnsServerInvalidProperty equ 0
    DnsServerDohProperty equ 1
    _DNS_SERVER_PROPERTY_TYPE typedef DNS_SERVER_PROPERTY_TYPE

    ifdef MIDL_PASS
      ;[...]
    else
      DNS_SERVER_PROPERTY_TYPES union
        DohSettings POINTER ?
      DNS_SERVER_PROPERTY_TYPES ends
      _DNS_SERVER_PROPERTY_TYPES typedef DNS_SERVER_PROPERTY_TYPES
    endif
    DNS_SERVER_PROPERTY struct
      Version ULONG ?
      ServerIndex ULONG ?
      Type_ DNS_SERVER_PROPERTY_TYPE ?
      ifdef MIDL_PASS
        ;[...]
      else
        Property DNS_SERVER_PROPERTY_TYPES <>
      endif
    DNS_SERVER_PROPERTY ends
    _DNS_SERVER_PROPERTY typedef DNS_SERVER_PROPERTY
    DNS_INTERFACE_SETTINGS struct
      Version ULONG ?
      Flags ULONG64 ?
      Domain PWSTR ?
      NameServer PWSTR ?
      SearchList PWSTR ?
      RegistrationEnabled ULONG ?
      RegisterAdapterName ULONG ?
      EnableLLMNR ULONG ?
      QueryAdapterName ULONG ?
      ProfileNameServer PWSTR ?
    DNS_INTERFACE_SETTINGS ends
    _DNS_INTERFACE_SETTINGS typedef DNS_INTERFACE_SETTINGS
    DNS_INTERFACE_SETTINGS_EX struct
      SettingsV1 DNS_INTERFACE_SETTINGS <>
      DisableUnconstrainedQueries ULONG ?
      SupplementalSearchList PWSTR ?
    DNS_INTERFACE_SETTINGS_EX ends
    _DNS_INTERFACE_SETTINGS_EX typedef DNS_INTERFACE_SETTINGS_EX
    DNS_INTERFACE_SETTINGS3 struct
      Version ULONG ?
      Flags ULONG64 ?
      Domain PWSTR ?
      NameServer PWSTR ?
      SearchList PWSTR ?
      RegistrationEnabled ULONG ?
      RegisterAdapterName ULONG ?
      EnableLLMNR ULONG ?
      QueryAdapterName ULONG ?
      ProfileNameServer PWSTR ?
      DisableUnconstrainedQueries ULONG ?
      SupplementalSearchList PWSTR ?
      cServerProperties ULONG ?
      ServerProperties POINTER ?
      cProfileServerProperties ULONG ?
      ProfileServerProperties POINTER ?
    DNS_INTERFACE_SETTINGS3 ends
    _DNS_INTERFACE_SETTINGS3 typedef DNS_INTERFACE_SETTINGS3
    DNS_INTERFACE_SETTINGS4 struct
      Version ULONG ?
      Flags ULONG64 ?
      Domain PWSTR ?
      NameServer PWSTR ?
      SearchList PWSTR ?
      RegistrationEnabled ULONG ?
      RegisterAdapterName ULONG ?
      EnableLLMNR ULONG ?
      QueryAdapterName ULONG ?
      ProfileNameServer PWSTR ?
      DisableUnconstrainedQueries ULONG ?
      SupplementalSearchList PWSTR ?
      cServerProperties ULONG ?
      ServerProperties POINTER ?
      cProfileServerProperties ULONG ?
      ProfileServerProperties POINTER ?
      EncryptedDnsAdapterFlags ULONG ?
    DNS_INTERFACE_SETTINGS4 ends
    _DNS_INTERFACE_SETTINGS4 typedef DNS_INTERFACE_SETTINGS4
    GetDnsSettings proto WIN_STD_CALL_CONV :ptr DNS_SETTINGS
    FreeDnsSettings proto WIN_STD_CALL_CONV :ptr DNS_SETTINGS
    SetDnsSettings proto WIN_STD_CALL_CONV :ptr DNS_SETTINGS
    GetInterfaceDnsSettings proto WIN_STD_CALL_CONV :GUID, :ptr DNS_INTERFACE_SETTINGS
    FreeInterfaceDnsSettings proto WIN_STD_CALL_CONV :ptr DNS_INTERFACE_SETTINGS
    SetInterfaceDnsSettings proto WIN_STD_CALL_CONV :GUID, :ptr DNS_INTERFACE_SETTINGS
    GetNetworkConnectivityHint proto WIN_STD_CALL_CONV :ptr NL_NETWORK_CONNECTIVITY_HINT
    GetNetworkConnectivityHintForInterface proto WIN_STD_CALL_CONV :NET_IFINDEX, :ptr NL_NETWORK_CONNECTIVITY_HINT
    TYPE_PNETWORK_CONNECTIVITY_HINT_CHANGE_CALLBACK typedef proto WIN_STD_CALL_CONV :PVOID, :NL_NETWORK_CONNECTIVITY_HINT
    PNETWORK_CONNECTIVITY_HINT_CHANGE_CALLBACK typedef ptr TYPE_PNETWORK_CONNECTIVITY_HINT_CHANGE_CALLBACK

    NotifyNetworkConnectivityHintChange proto WIN_STD_CALL_CONV :PNETWORK_CONNECTIVITY_HINT_CHANGE_CALLBACK, :PVOID, :BOOLEAN, :PHANDLE
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    ifdef __cplusplus
      ;[...]
    endif
  endif
endif
