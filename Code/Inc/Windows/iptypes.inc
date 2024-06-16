;Include file created by h2inc+ version C.2.0 on (UTC) 15/06/2024 16:37:44
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\iptypes.h
;             Created on (UTC) 06/04/2024 06:15:56
;             Last modified on (UTC) 08/01/2024 17:04:20

ifndef IP_TYPES_INCLUDED
  IP_TYPES_INCLUDED equ <>
  if _MSC_VER gt 1000
  endif
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    ifdef __cplusplus
      ;[...]
    endif
;    include time.inc
    include ifdef.inc
    include nldef.inc
    MAX_ADAPTER_DESCRIPTION_LENGTH equ 128
    MAX_ADAPTER_NAME_LENGTH equ 256
    MAX_ADAPTER_ADDRESS_LENGTH equ 8
    DEFAULT_MINIMUM_ENTITIES equ 32
    MAX_HOSTNAME_LEN equ 128
    MAX_DOMAIN_NAME_LEN equ 128
    MAX_SCOPE_ID_LEN equ 256
    MAX_DHCPV6_DUID_LENGTH equ 130
    MAX_DNS_SUFFIX_STRING_LENGTH equ 256
    BROADCAST_NODETYPE equ 1
    PEER_TO_PEER_NODETYPE equ 2
    MIXED_NODETYPE equ 4
    HYBRID_NODETYPE equ 8
    IP_ADDRESS_STRING struct
      String SBYTE 4 * 4 dup (?)
    IP_ADDRESS_STRING ends
    PIP_ADDRESS_STRING typedef ptr IP_ADDRESS_STRING
    IP_MASK_STRING typedef IP_ADDRESS_STRING
    PIP_MASK_STRING typedef ptr IP_ADDRESS_STRING
    IP_ADDR_STRING struct
      Next POINTER ?
      IpAddress IP_ADDRESS_STRING <>
      IpMask IP_MASK_STRING <>
      Context DWORD ?
    IP_ADDR_STRING ends
    _IP_ADDR_STRING typedef IP_ADDR_STRING
    PIP_ADDR_STRING typedef ptr IP_ADDR_STRING
    IP_ADAPTER_INFO struct
      Next POINTER ?
      ComboIndex DWORD ?
      AdapterName SBYTE MAX_ADAPTER_NAME_LENGTH + 4 dup (?)
      Description SBYTE MAX_ADAPTER_DESCRIPTION_LENGTH + 4 dup (?)
      AddressLength UINT ?
      Address BYTE MAX_ADAPTER_ADDRESS_LENGTH dup (?)
      Index DWORD ?
      Type_ UINT ?
      DhcpEnabled UINT ?
      CurrentIpAddress PIP_ADDR_STRING ?
      IpAddressList IP_ADDR_STRING <>
      GatewayList IP_ADDR_STRING <>
      DhcpServer IP_ADDR_STRING <>
      HaveWins BOOL ?
      PrimaryWinsServer IP_ADDR_STRING <>
      SecondaryWinsServer IP_ADDR_STRING <>
      LeaseObtained QWORD ?
      LeaseExpires QWORD ?
    IP_ADAPTER_INFO ends
    _IP_ADAPTER_INFO typedef IP_ADAPTER_INFO
    PIP_ADAPTER_INFO typedef ptr IP_ADAPTER_INFO
    ifdef _WINSOCK2API_
      IP_PREFIX_ORIGIN typedef NL_PREFIX_ORIGIN
      IP_SUFFIX_ORIGIN typedef NL_SUFFIX_ORIGIN
      IP_DAD_STATE typedef NL_DAD_STATE
      IP_ADAPTER_UNICAST_ADDRESS_LH struct
        union
          Alignment ULONGLONG ?
          struct
            Length_ ULONG ?
            Flags DWORD ?
          ends
        ends
        Next POINTER ?
        Address SOCKET_ADDRESS <>
        PrefixOrigin IP_PREFIX_ORIGIN ?
        SuffixOrigin IP_SUFFIX_ORIGIN ?
        DadState IP_DAD_STATE ?
        ValidLifetime ULONG ?
        PreferredLifetime ULONG ?
        LeaseLifetime ULONG ?
        OnLinkPrefixLength UINT8 ?
      IP_ADAPTER_UNICAST_ADDRESS_LH ends
      _IP_ADAPTER_UNICAST_ADDRESS_LH typedef IP_ADAPTER_UNICAST_ADDRESS_LH
      PIP_ADAPTER_UNICAST_ADDRESS_LH typedef ptr IP_ADAPTER_UNICAST_ADDRESS_LH
      IP_ADAPTER_UNICAST_ADDRESS_XP struct
        union
          Alignment ULONGLONG ?
          struct
            Length_ ULONG ?
            Flags DWORD ?
          ends
        ends
        Next POINTER ?
        Address SOCKET_ADDRESS <>
        PrefixOrigin IP_PREFIX_ORIGIN ?
        SuffixOrigin IP_SUFFIX_ORIGIN ?
        DadState IP_DAD_STATE ?
        ValidLifetime ULONG ?
        PreferredLifetime ULONG ?
        LeaseLifetime ULONG ?
      IP_ADAPTER_UNICAST_ADDRESS_XP ends
      _IP_ADAPTER_UNICAST_ADDRESS_XP typedef IP_ADAPTER_UNICAST_ADDRESS_XP
      PIP_ADAPTER_UNICAST_ADDRESS_XP typedef ptr IP_ADAPTER_UNICAST_ADDRESS_XP
      if (NTDDI_VERSION ge NTDDI_VISTA)
        IP_ADAPTER_UNICAST_ADDRESS typedef IP_ADAPTER_UNICAST_ADDRESS_LH
        PIP_ADAPTER_UNICAST_ADDRESS typedef ptr IP_ADAPTER_UNICAST_ADDRESS_LH
      elseif (NTDDI_VERSION ge NTDDI_WINXP)
        IP_ADAPTER_UNICAST_ADDRESS typedef IP_ADAPTER_UNICAST_ADDRESS_XP
        PIP_ADAPTER_UNICAST_ADDRESS typedef ptr IP_ADAPTER_UNICAST_ADDRESS_XP
      endif
      IP_ADAPTER_ADDRESS_DNS_ELIGIBLE equ 01h
      IP_ADAPTER_ADDRESS_TRANSIENT equ 02h
      IP_ADAPTER_ANYCAST_ADDRESS_XP struct
        union
          Alignment ULONGLONG ?
          struct
            Length_ ULONG ?
            Flags DWORD ?
          ends
        ends
        Next POINTER ?
        Address SOCKET_ADDRESS <>
      IP_ADAPTER_ANYCAST_ADDRESS_XP ends
      _IP_ADAPTER_ANYCAST_ADDRESS_XP typedef IP_ADAPTER_ANYCAST_ADDRESS_XP
      PIP_ADAPTER_ANYCAST_ADDRESS_XP typedef ptr IP_ADAPTER_ANYCAST_ADDRESS_XP
      if (NTDDI_VERSION ge NTDDI_WINXP)
        IP_ADAPTER_ANYCAST_ADDRESS typedef IP_ADAPTER_ANYCAST_ADDRESS_XP
        PIP_ADAPTER_ANYCAST_ADDRESS typedef ptr IP_ADAPTER_ANYCAST_ADDRESS_XP
      endif
      IP_ADAPTER_MULTICAST_ADDRESS_XP struct
        union
          Alignment ULONGLONG ?
          struct
            Length_ ULONG ?
            Flags DWORD ?
          ends
        ends
        Next POINTER ?
        Address SOCKET_ADDRESS <>
      IP_ADAPTER_MULTICAST_ADDRESS_XP ends
      _IP_ADAPTER_MULTICAST_ADDRESS_XP typedef IP_ADAPTER_MULTICAST_ADDRESS_XP
      PIP_ADAPTER_MULTICAST_ADDRESS_XP typedef ptr IP_ADAPTER_MULTICAST_ADDRESS_XP
      if (NTDDI_VERSION ge NTDDI_WINXP)
        IP_ADAPTER_MULTICAST_ADDRESS typedef IP_ADAPTER_MULTICAST_ADDRESS_XP
        PIP_ADAPTER_MULTICAST_ADDRESS typedef ptr IP_ADAPTER_MULTICAST_ADDRESS_XP
      endif
      IP_ADAPTER_DNS_SERVER_ADDRESS_XP struct
        union
          Alignment ULONGLONG ?
          struct
            Length_ ULONG ?
            Reserved DWORD ?
          ends
        ends
        Next POINTER ?
        Address SOCKET_ADDRESS <>
      IP_ADAPTER_DNS_SERVER_ADDRESS_XP ends
      _IP_ADAPTER_DNS_SERVER_ADDRESS_XP typedef IP_ADAPTER_DNS_SERVER_ADDRESS_XP
      PIP_ADAPTER_DNS_SERVER_ADDRESS_XP typedef ptr IP_ADAPTER_DNS_SERVER_ADDRESS_XP
      if (NTDDI_VERSION ge NTDDI_WINXP)
        IP_ADAPTER_DNS_SERVER_ADDRESS typedef IP_ADAPTER_DNS_SERVER_ADDRESS_XP
        PIP_ADAPTER_DNS_SERVER_ADDRESS typedef ptr IP_ADAPTER_DNS_SERVER_ADDRESS_XP
      endif
      IP_ADAPTER_WINS_SERVER_ADDRESS_LH struct
        union
          Alignment ULONGLONG ?
          struct
            Length_ ULONG ?
            Reserved DWORD ?
          ends
        ends
        Next POINTER ?
        Address SOCKET_ADDRESS <>
      IP_ADAPTER_WINS_SERVER_ADDRESS_LH ends
      _IP_ADAPTER_WINS_SERVER_ADDRESS_LH typedef IP_ADAPTER_WINS_SERVER_ADDRESS_LH
      PIP_ADAPTER_WINS_SERVER_ADDRESS_LH typedef ptr IP_ADAPTER_WINS_SERVER_ADDRESS_LH
      if (NTDDI_VERSION ge NTDDI_VISTA)
        IP_ADAPTER_WINS_SERVER_ADDRESS typedef IP_ADAPTER_WINS_SERVER_ADDRESS_LH
        PIP_ADAPTER_WINS_SERVER_ADDRESS typedef ptr IP_ADAPTER_WINS_SERVER_ADDRESS_LH
      endif
      IP_ADAPTER_GATEWAY_ADDRESS_LH struct
        union
          Alignment ULONGLONG ?
          struct
            Length_ ULONG ?
            Reserved DWORD ?
          ends
        ends
        Next POINTER ?
        Address SOCKET_ADDRESS <>
      IP_ADAPTER_GATEWAY_ADDRESS_LH ends
      _IP_ADAPTER_GATEWAY_ADDRESS_LH typedef IP_ADAPTER_GATEWAY_ADDRESS_LH
      PIP_ADAPTER_GATEWAY_ADDRESS_LH typedef ptr IP_ADAPTER_GATEWAY_ADDRESS_LH
      if (NTDDI_VERSION ge NTDDI_VISTA)
        IP_ADAPTER_GATEWAY_ADDRESS typedef IP_ADAPTER_GATEWAY_ADDRESS_LH
        PIP_ADAPTER_GATEWAY_ADDRESS typedef ptr IP_ADAPTER_GATEWAY_ADDRESS_LH
      endif
      IP_ADAPTER_PREFIX_XP struct
        union
          Alignment ULONGLONG ?
          struct
            Length_ ULONG ?
            Flags DWORD ?
          ends
        ends
        Next POINTER ?
        Address SOCKET_ADDRESS <>
        PrefixLength ULONG ?
      IP_ADAPTER_PREFIX_XP ends
      _IP_ADAPTER_PREFIX_XP typedef IP_ADAPTER_PREFIX_XP
      PIP_ADAPTER_PREFIX_XP typedef ptr IP_ADAPTER_PREFIX_XP
      if (NTDDI_VERSION ge NTDDI_WINXP)
        IP_ADAPTER_PREFIX typedef IP_ADAPTER_PREFIX_XP
        PIP_ADAPTER_PREFIX typedef ptr IP_ADAPTER_PREFIX_XP
      endif
      IP_ADAPTER_DNS_SUFFIX struct
        Next POINTER ?
        String WCHAR MAX_DNS_SUFFIX_STRING_LENGTH dup (?)
      IP_ADAPTER_DNS_SUFFIX ends
      _IP_ADAPTER_DNS_SUFFIX typedef IP_ADAPTER_DNS_SUFFIX
      PIP_ADAPTER_DNS_SUFFIX typedef ptr IP_ADAPTER_DNS_SUFFIX
      IP_ADAPTER_DDNS_ENABLED equ 00000001h
      IP_ADAPTER_REGISTER_ADAPTER_SUFFIX equ 00000002h
      IP_ADAPTER_DHCP_ENABLED equ 00000004h
      IP_ADAPTER_RECEIVE_ONLY equ 00000008h
      IP_ADAPTER_NO_MULTICAST equ 00000010h
      IP_ADAPTER_IPV6_OTHER_STATEFUL_CONFIG equ 00000020h
      IP_ADAPTER_NETBIOS_OVER_TCPIP_ENABLED equ 00000040h
      IP_ADAPTER_IPV4_ENABLED equ 00000080h
      IP_ADAPTER_IPV6_ENABLED equ 00000100h
      IP_ADAPTER_IPV6_MANAGE_ADDRESS_CONFIG equ 00000200h
      IP_ADAPTER_ADDRESSES_LH struct
        union
          Alignment ULONGLONG ?
          struct
            Length_ ULONG ?
            IfIndex IF_INDEX ?
          ends
        ends
        Next POINTER ?
        AdapterName PCHAR ?
        FirstUnicastAddress PIP_ADAPTER_UNICAST_ADDRESS_LH ?
        FirstAnycastAddress PIP_ADAPTER_ANYCAST_ADDRESS_XP ?
        FirstMulticastAddress PIP_ADAPTER_MULTICAST_ADDRESS_XP ?
        FirstDnsServerAddress PIP_ADAPTER_DNS_SERVER_ADDRESS_XP ?
        DnsSuffix PWCHAR ?
        Description PWCHAR ?
        FriendlyName PWCHAR ?
        PhysicalAddress BYTE MAX_ADAPTER_ADDRESS_LENGTH dup (?)
        PhysicalAddressLength ULONG ?
        union
          Flags ULONG ?
          struct
            ;ANONYMOUS_REC4 record ANONYMOUS_REC4_Filler:22, ANONYMOUS_REC4_Ipv6ManagedAddressConfigurationSupported:1, ANONYMOUS_REC4_Ipv6Enabled:1, ANONYMOUS_REC4_Ipv4Enabled:1, ANONYMOUS_REC4_NetbiosOverTcpipEnabled:1, ANONYMOUS_REC4_Ipv6OtherStatefulConfig:1, ANONYMOUS_REC4_NoMulticast:1, ANONYMOUS_REC4_ReceiveOnly:1, ANONYMOUS_REC4_Dhcpv4Enabled:1, ANONYMOUS_REC4_RegisterAdapterSuffix:1, ANONYMOUS_REC4_DdnsEnabled:1
            ANONYMOUS_BITS4 DWORD ?
          ends
        ends
        Mtu ULONG ?
        IfType IFTYPE ?
        OperStatus IF_OPER_STATUS ?
        Ipv6IfIndex IF_INDEX ?
        ZoneIndices ULONG 16 dup (?)
        FirstPrefix PIP_ADAPTER_PREFIX_XP ?
        TransmitLinkSpeed ULONG64 ?
        ReceiveLinkSpeed ULONG64 ?
        FirstWinsServerAddress PIP_ADAPTER_WINS_SERVER_ADDRESS_LH ?
        FirstGatewayAddress PIP_ADAPTER_GATEWAY_ADDRESS_LH ?
        Ipv4Metric ULONG ?
        Ipv6Metric ULONG ?
        Luid IF_LUID <>
        Dhcpv4Server SOCKET_ADDRESS <>
        CompartmentId NET_IF_COMPARTMENT_ID ?
        NetworkGuid NET_IF_NETWORK_GUID <>
        ConnectionType NET_IF_CONNECTION_TYPE ?
        TunnelType TUNNEL_TYPE ?
        Dhcpv6Server SOCKET_ADDRESS <>
        Dhcpv6ClientDuid BYTE MAX_DHCPV6_DUID_LENGTH dup (?)
        Dhcpv6ClientDuidLength ULONG ?
        Dhcpv6Iaid ULONG ?
        if (NTDDI_VERSION ge NTDDI_VISTASP1)
          FirstDnsSuffix PIP_ADAPTER_DNS_SUFFIX ?
        endif
      IP_ADAPTER_ADDRESSES_LH ends
      _IP_ADAPTER_ADDRESSES_LH typedef IP_ADAPTER_ADDRESSES_LH
      PIP_ADAPTER_ADDRESSES_LH typedef ptr IP_ADAPTER_ADDRESSES_LH
      IP_ADAPTER_ADDRESSES_XP struct
        union
          Alignment ULONGLONG ?
          struct
            Length_ ULONG ?
            IfIndex DWORD ?
          ends
        ends
        Next POINTER ?
        AdapterName PCHAR ?
        FirstUnicastAddress PIP_ADAPTER_UNICAST_ADDRESS_XP ?
        FirstAnycastAddress PIP_ADAPTER_ANYCAST_ADDRESS_XP ?
        FirstMulticastAddress PIP_ADAPTER_MULTICAST_ADDRESS_XP ?
        FirstDnsServerAddress PIP_ADAPTER_DNS_SERVER_ADDRESS_XP ?
        DnsSuffix PWCHAR ?
        Description PWCHAR ?
        FriendlyName PWCHAR ?
        PhysicalAddress BYTE MAX_ADAPTER_ADDRESS_LENGTH dup (?)
        PhysicalAddressLength DWORD ?
        Flags DWORD ?
        Mtu DWORD ?
        IfType DWORD ?
        OperStatus IF_OPER_STATUS ?
        Ipv6IfIndex DWORD ?
        ZoneIndices DWORD 16 dup (?)
        FirstPrefix PIP_ADAPTER_PREFIX_XP ?
      IP_ADAPTER_ADDRESSES_XP ends
      _IP_ADAPTER_ADDRESSES_XP typedef IP_ADAPTER_ADDRESSES_XP
      PIP_ADAPTER_ADDRESSES_XP typedef ptr IP_ADAPTER_ADDRESSES_XP
      if (NTDDI_VERSION ge NTDDI_VISTA)
        IP_ADAPTER_ADDRESSES typedef IP_ADAPTER_ADDRESSES_LH
        PIP_ADAPTER_ADDRESSES typedef ptr IP_ADAPTER_ADDRESSES_LH
      elseif (NTDDI_VERSION ge NTDDI_WINXP)
        IP_ADAPTER_ADDRESSES typedef IP_ADAPTER_ADDRESSES_XP
        PIP_ADAPTER_ADDRESSES typedef ptr IP_ADAPTER_ADDRESSES_XP
      else
        IP_ADAPTER_ADDRESSES typedef IP_ADAPTER_ADDRESSES_XP
        PIP_ADAPTER_ADDRESSES typedef ptr IP_ADAPTER_ADDRESSES_XP
      endif
      GAA_FLAG_SKIP_UNICAST equ 0001h
      GAA_FLAG_SKIP_ANYCAST equ 0002h
      GAA_FLAG_SKIP_MULTICAST equ 0004h
      GAA_FLAG_SKIP_DNS_SERVER equ 0008h
      GAA_FLAG_INCLUDE_PREFIX equ 0010h
      GAA_FLAG_SKIP_FRIENDLY_NAME equ 0020h
      GAA_FLAG_INCLUDE_WINS_INFO equ 0040h
      GAA_FLAG_INCLUDE_GATEWAYS equ 0080h
      GAA_FLAG_INCLUDE_ALL_INTERFACES equ 0100h
      GAA_FLAG_INCLUDE_ALL_COMPARTMENTS equ 0200h
      GAA_FLAG_INCLUDE_TUNNEL_BINDINGORDER equ 0400h
      GAA_FLAG_SKIP_DNS_INFO equ 0800h
    endif
    IP_PER_ADAPTER_INFO_W2KSP1 struct
      AutoconfigEnabled UINT ?
      AutoconfigActive UINT ?
      CurrentDnsServer PIP_ADDR_STRING ?
      DnsServerList IP_ADDR_STRING <>
    IP_PER_ADAPTER_INFO_W2KSP1 ends
    _IP_PER_ADAPTER_INFO_W2KSP1 typedef IP_PER_ADAPTER_INFO_W2KSP1
    PIP_PER_ADAPTER_INFO_W2KSP1 typedef ptr IP_PER_ADAPTER_INFO_W2KSP1
    if (NTDDI_VERSION ge NTDDI_WIN2KSP1)
      IP_PER_ADAPTER_INFO typedef IP_PER_ADAPTER_INFO_W2KSP1
      PIP_PER_ADAPTER_INFO typedef ptr IP_PER_ADAPTER_INFO_W2KSP1
    endif
    FIXED_INFO_W2KSP1 struct
      HostName SBYTE MAX_HOSTNAME_LEN + 4 dup (?)
      DomainName SBYTE MAX_DOMAIN_NAME_LEN + 4 dup (?)
      CurrentDnsServer PIP_ADDR_STRING ?
      DnsServerList IP_ADDR_STRING <>
      NodeType UINT ?
      ScopeId SBYTE MAX_SCOPE_ID_LEN + 4 dup (?)
      EnableRouting UINT ?
      EnableProxy UINT ?
      EnableDns UINT ?
    FIXED_INFO_W2KSP1 ends
    PFIXED_INFO_W2KSP1 typedef ptr FIXED_INFO_W2KSP1
    if (NTDDI_VERSION ge NTDDI_WIN2KSP1)
      FIXED_INFO typedef FIXED_INFO_W2KSP1
      PFIXED_INFO typedef ptr FIXED_INFO_W2KSP1
    endif
    ifndef IP_INTERFACE_NAME_INFO_DEFINED
      IP_INTERFACE_NAME_INFO_DEFINED equ <>
      IP_INTERFACE_NAME_INFO_W2KSP1 struct
        Index ULONG ?
        MediaType ULONG ?
        ConnectionType UCHAR ?
        AccessType UCHAR ?
        DeviceGuid GUID <>
        InterfaceGuid GUID <>
      IP_INTERFACE_NAME_INFO_W2KSP1 ends
      ip_interface_name_info_w2ksp1 typedef IP_INTERFACE_NAME_INFO_W2KSP1
      PIP_INTERFACE_NAME_INFO_W2KSP1 typedef ptr IP_INTERFACE_NAME_INFO_W2KSP1
      if (NTDDI_VERSION ge NTDDI_WIN2KSP1)
        IP_INTERFACE_NAME_INFO typedef IP_INTERFACE_NAME_INFO_W2KSP1
        PIP_INTERFACE_NAME_INFO typedef ptr IP_INTERFACE_NAME_INFO_W2KSP1
      endif
    endif
  endif
endif
