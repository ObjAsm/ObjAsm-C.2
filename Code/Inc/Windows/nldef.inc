;Include file created by h2inc+ version C.2.0 on (UTC) 15/06/2024 16:37:44
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\nldef.h
;             Created on (UTC) 22/05/2024 17:57:07
;             Last modified on (UTC) 21/02/2024 18:15:28

ifndef _NLDEF_
  _NLDEF_ equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    NL_PREFIX_ORIGIN typedef SDWORD
    IpPrefixOriginOther equ 0
    IpPrefixOriginManual equ 1
    IpPrefixOriginWellKnown equ 2
    IpPrefixOriginDhcp equ 3
    IpPrefixOriginRouterAdvertisement equ 4
    IpPrefixOriginUnchanged equ 1 shl 4

    NlpoOther equ <IpPrefixOriginOther>
    NlpoManual equ <IpPrefixOriginManual>
    NlpoWellKnown equ <IpPrefixOriginWellKnown>
    NlpoDhcp equ <IpPrefixOriginDhcp>
    NlpoRouterAdvertisement equ <IpPrefixOriginRouterAdvertisement>
    NL_SUFFIX_ORIGIN typedef SDWORD
    NlsoOther equ 0
    NlsoManual equ 1
    NlsoWellKnown equ 2
    NlsoDhcp equ 3
    NlsoLinkLayerAddress equ 4
    NlsoRandom equ 5
    IpSuffixOriginOther equ 0
    IpSuffixOriginManual equ 1
    IpSuffixOriginWellKnown equ 2
    IpSuffixOriginDhcp equ 3
    IpSuffixOriginLinkLayerAddress equ 4
    IpSuffixOriginRandom equ 5
    IpSuffixOriginUnchanged equ 1 shl 4

    NL_DAD_STATE typedef SDWORD
    NldsInvalid equ 0
    NldsTentative equ 1
    NldsDuplicate equ 2
    NldsDeprecated equ 3
    NldsPreferred equ 4
    IpDadStateInvalid equ 0
    IpDadStateTentative equ 1
    IpDadStateDuplicate equ 2
    IpDadStateDeprecated equ 3
    IpDadStatePreferred equ 4

    NL_MAX_METRIC_COMPONENT equ (((1) shl 31) - 1)
    MAKE_ROUTE_PROTOCOL macro suffix, value
      exitm <MIB_IPPROTO_ ## suffix = value, PROTO_IP_ ## suffix = value>
    endm
    NL_ROUTE_PROTOCOL typedef SDWORD
    RouteProtocolOther equ 1
    RouteProtocolLocal equ 2
    RouteProtocolNetMgmt equ 3
    RouteProtocolIcmp equ 4
    RouteProtocolEgp equ 5
    RouteProtocolGgp equ 6
    RouteProtocolHello equ 7
    RouteProtocolRip equ 8
    RouteProtocolIsIs equ 9
    RouteProtocolEsIs equ 10
    RouteProtocolCisco equ 11
    RouteProtocolBbn equ 12
    RouteProtocolOspf equ 13
    RouteProtocolBgp equ 14
    RouteProtocolIdpr equ 15
    RouteProtocolEigrp equ 16
    RouteProtocolDvmrp equ 17
    RouteProtocolRpl equ 18
    RouteProtocolDhcp equ 19
;    MAKE_ROUTE_PROTOCOL(OTHER, 1)MAKE_ROUTE_PROTOCOL(LOCAL, 2)MAKE_ROUTE_PROTOCOL(NETMGMT, 3)MAKE_ROUTE_PROTOCOL(ICMP, 4)MAKE_ROUTE_PROTOCOL(EGP, 5)MAKE_ROUTE_PROTOCOL(GGP, 6)MAKE_ROUTE_PROTOCOL(HELLO, 7)MAKE_ROUTE_PROTOCOL(RIP, 8)MAKE_ROUTE_PROTOCOL(IS_IS, 9)MAKE_ROUTE_PROTOCOL(ES_IS, 10)MAKE_ROUTE_PROTOCOL(CISCO, 11)MAKE_ROUTE_PROTOCOL(BBN, 12)MAKE_ROUTE_PROTOCOL(OSPF, 13)MAKE_ROUTE_PROTOCOL(BGP, 14)MAKE_ROUTE_PROTOCOL(IDPR, 15)MAKE_ROUTE_PROTOCOL(EIGRP, 16)MAKE_ROUTE_PROTOCOL(DVMRP, 17)MAKE_ROUTE_PROTOCOL(RPL, 18)MAKE_ROUTE_PROTOCOL(DHCP, 19)MAKE_ROUTE_PROTOCOL(NT_AUTOSTATIC, 10002)MAKE_ROUTE_PROTOCOL(NT_STATIC, 10006)MAKE_ROUTE_PROTOCOL(NT_STATIC_NON_DOD, 10007)PNL_ROUTE_PROTOCOL typedef ptr NL_ROUTE_PROTOCOL
    NL_ADDRESS_TYPE typedef SDWORD
    NlatUnspecified equ 0
    NlatUnicast equ 1
    NlatAnycast equ 2
    NlatMulticast equ 3
    NlatBroadcast equ 4
    NlatInvalid equ 5
    PNL_ADDRESS_TYPE typedef ptr NL_ADDRESS_TYPE
    NL_ROUTE_ORIGIN typedef SDWORD
    NlroManual equ 0
    NlroWellKnown equ 1
    NlroDHCP equ 2
    NlroRouterAdvertisement equ 3
    Nlro6to4 equ 4
    _NL_ROUTE_ORIGIN typedef NL_ROUTE_ORIGIN
    PNL_ROUTE_ORIGIN typedef ptr NL_ROUTE_ORIGIN
    NL_NEIGHBOR_STATE typedef SDWORD
    NlnsUnreachable equ 0
    NlnsIncomplete equ 1
    NlnsProbe equ 2
    NlnsDelay equ 3
    NlnsStale equ 4
    NlnsReachable equ 5
    NlnsPermanent equ 6
    NlnsMaximum equ 7
    _NL_NEIGHBOR_STATE typedef NL_NEIGHBOR_STATE
    PNL_NEIGHBOR_STATE typedef ptr NL_NEIGHBOR_STATE
    NL_LINK_LOCAL_ADDRESS_BEHAVIOR typedef SDWORD
    LinkLocalAlwaysOff equ 0
    LinkLocalDelayed equ 1
    LinkLocalAlwaysOn equ 2
    LinkLocalUnchanged equ -1
    _NL_LINK_LOCAL_ADDRESS_BEHAVIOR typedef NL_LINK_LOCAL_ADDRESS_BEHAVIOR

    NL_INTERFACE_OFFLOAD_ROD struct
      NL_INTERFACE_OFFLOAD_ROD_REC record NL_INTERFACE_OFFLOAD_ROD_REC_TlGiantSendOffloadSupported:1, NL_INTERFACE_OFFLOAD_ROD_REC_TlLargeSendOffloadSupported:1, NL_INTERFACE_OFFLOAD_ROD_REC_FastPathCompatible:1, NL_INTERFACE_OFFLOAD_ROD_REC_TlStreamOptionsSupported:1, NL_INTERFACE_OFFLOAD_ROD_REC_TlStreamChecksumSupported:1, NL_INTERFACE_OFFLOAD_ROD_REC_TlDatagramChecksumSupported:1, NL_INTERFACE_OFFLOAD_ROD_REC_NlOptionsSupported:1, NL_INTERFACE_OFFLOAD_ROD_REC_NlChecksumSupported:1
      NL_INTERFACE_OFFLOAD_ROD_BITS NL_INTERFACE_OFFLOAD_ROD_REC <>
    NL_INTERFACE_OFFLOAD_ROD ends
    _NL_INTERFACE_OFFLOAD_ROD typedef NL_INTERFACE_OFFLOAD_ROD
    PNL_INTERFACE_OFFLOAD_ROD typedef ptr NL_INTERFACE_OFFLOAD_ROD
    NL_ROUTER_DISCOVERY_BEHAVIOR typedef SDWORD
    RouterDiscoveryDisabled equ 0
    RouterDiscoveryEnabled equ 1
    RouterDiscoveryDhcp equ 2
    RouterDiscoveryUnchanged equ -1
    _NL_ROUTER_DISCOVERY_BEHAVIOR typedef NL_ROUTER_DISCOVERY_BEHAVIOR

    NL_BANDWIDTH_FLAG typedef SDWORD
    NlbwDisabled equ 0
    NlbwEnabled equ 1
    NlbwUnchanged equ -1
    _NL_BANDWIDTH_FLAG typedef NL_BANDWIDTH_FLAG
    PNL_BANDWIDTH_FLAG typedef ptr NL_BANDWIDTH_FLAG
    NL_PATH_BANDWIDTH_ROD struct
      Bandwidth ULONG64 ?
      Instability ULONG64 ?
      BandwidthPeaked BOOLEAN ?
    NL_PATH_BANDWIDTH_ROD ends
    _NL_PATH_BANDWIDTH_ROD typedef NL_PATH_BANDWIDTH_ROD
    PNL_PATH_BANDWIDTH_ROD typedef ptr NL_PATH_BANDWIDTH_ROD
    NL_NETWORK_CATEGORY typedef SDWORD
    NetworkCategoryPublic equ 0
    NetworkCategoryPrivate equ 1
    NetworkCategoryDomainAuthenticated equ 2
    NetworkCategoryUnchanged equ -1
    NetworkCategoryUnknown equ -1
    _NL_NETWORK_CATEGORY typedef NL_NETWORK_CATEGORY
    PNL_NETWORK_CATEGORY typedef ptr NL_NETWORK_CATEGORY
    NL_INTERFACE_NETWORK_CATEGORY_STATE typedef SDWORD
    NlincCategoryUnknown equ 0
    NlincPublic equ 1
    NlincPrivate equ 2
    NlincDomainAuthenticated equ 3
    NlincCategoryStateMax equ 4
    _NL_INTERFACE_NETWORK_CATEGORY_STATE typedef NL_INTERFACE_NETWORK_CATEGORY_STATE
    PNL_INTERFACE_NETWORK_CATEGORY_STATE typedef ptr NL_INTERFACE_NETWORK_CATEGORY_STATE
    NL_NETWORK_CONNECTIVITY_LEVEL_HINT typedef SDWORD
    NetworkConnectivityLevelHintUnknown equ 0
    NetworkConnectivityLevelHintNone equ 1
    NetworkConnectivityLevelHintLocalAccess equ 2
    NetworkConnectivityLevelHintInternetAccess equ 3
    NetworkConnectivityLevelHintConstrainedInternetAccess equ 4
    NetworkConnectivityLevelHintHidden equ 5
    _NL_NETWORK_CONNECTIVITY_LEVEL_HINT typedef NL_NETWORK_CONNECTIVITY_LEVEL_HINT

    NL_NETWORK_CONNECTIVITY_COST_HINT typedef SDWORD
    NetworkConnectivityCostHintUnknown equ 0
    NetworkConnectivityCostHintUnrestricted equ 1
    NetworkConnectivityCostHintFixed equ 2
    NetworkConnectivityCostHintVariable equ 3
    _NL_NETWORK_CONNECTIVITY_COST_HINT typedef NL_NETWORK_CONNECTIVITY_COST_HINT

    NL_NETWORK_CONNECTIVITY_HINT struct
      ConnectivityLevel NL_NETWORK_CONNECTIVITY_LEVEL_HINT ?
      ConnectivityCost NL_NETWORK_CONNECTIVITY_COST_HINT ?
      ApproachingDataLimit BOOLEAN ?
      OverDataLimit BOOLEAN ?
      Roaming BOOLEAN ?
    NL_NETWORK_CONNECTIVITY_HINT ends
    _NL_NETWORK_CONNECTIVITY_HINT typedef NL_NETWORK_CONNECTIVITY_HINT
    NET_IF_CURRENT_SESSION equ (- 1)
    NL_BANDWIDTH_INFORMATION struct
      Bandwidth ULONG64 ?
      Instability ULONG64 ?
      BandwidthPeaked BOOLEAN ?
    NL_BANDWIDTH_INFORMATION ends
    _NL_BANDWIDTH_INFORMATION typedef NL_BANDWIDTH_INFORMATION
    PNL_BANDWIDTH_INFORMATION typedef ptr NL_BANDWIDTH_INFORMATION
  endif
endif
