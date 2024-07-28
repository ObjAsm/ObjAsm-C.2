;Include file created by h2incX, Version C.01.00, 07/01/2023 18:05
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'C:\Program Files (x86)\Windows Kits\10\Include\10.0.22621.0\shared\netiodef.h', last modified: 19/10/2022 13:00

ifndef _NETIODEF_
  _NETIODEF_ equ <>
  include winapifamily.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
;    include ws2def.inc
;    include ws2ipdef.inc
;    include mswsockdef.inc
;    include mstcpip.inc
;    include nldef.inc
    IS_POWER_OF_TWO macro x
      exitm <(((x) != 0) and (((x) and ((x) - 1)) == 0))>
    endm
    if Defined(_NTDDK_) or Defined(_NTRTL_)
      IS_VALID_IPV4_MASK macro x
        exitm <((x.S_un.S_addr == - 1) or IS_POWER_OF_TWO(not RtlUlongByteSwap (x.S_un.S_addr) + 1))>
      endm
    endif
    ifndef BYTE_ORDER
      _LITTLE_ENDIAN equ 1234
      _BIG_ENDIAN equ 4321
      _PDP_ENDIAN equ 3412
      if Defined(vax) or Defined(ns32000) or Defined(sun386) or Defined(MIPSEL) or Defined(BIT_ZERO_ON_RIGHT)
        BYTE_ORDER equ <_LITTLE_ENDIAN>
      endif
      if Defined(sel) or Defined(pyr) or Defined(mc68000) or Defined(sparc) or Defined(is68k) or Defined(tahoe) or Defined(ibm032) or Defined(ibm370) or Defined(MIPSEB) or Defined(BIT_ZERO_ON_LEFT)
        BYTE_ORDER equ <_BIG_ENDIAN>
      endif
      ifndef BYTE_ORDER
        if Defined(u3b2) or Defined(m68k)
          BYTE_ORDER equ <_BIG_ENDIAN>
        endif
        if Defined(i286) or Defined(_X86_) or Defined(_AMD64_) or Defined(_IA64_) or Defined(_ARM_) or Defined(_ARM64_)
          BYTE_ORDER equ <_LITTLE_ENDIAN>
        endif
      endif
    endif
    ifndef BYTE_ORDER
    endif
    HANDLE8 typedef UINT8
    PHANDLE8 typedef ptr UINT8
    HANDLE16 typedef UINT16
    PHANDLE16 typedef ptr UINT16
    HANDLE32 typedef UINT32
    PHANDLE32 typedef ptr UINT32
    ifndef __HANDLE64_DEFINED__
      __HANDLE64_DEFINED__ equ <>
      HANDLE64 typedef ptr
      PHANDLE64 typedef ptr HANDLE64
    endif
    MAKE_DD_DEVICE_NAME macro x
      exitm <(L("\Device\") x)>
    endm
    MAKE_WIN_DEVICE_NAME macro x
      exitm <(L("\\.\") x)>
    endm
;    include ifdef.inc
    if Defined(_MSC_VER)
      if _MSC_VER ge 1200
      endif
    endif
    DL_ADDRESS_LENGTH_MAXIMUM equ <IF_MAX_PHYS_ADDRESS_LENGTH>
    DL_HEADER_LENGTH_MAXIMUM equ 64
    DL_ETHERNET_HEADER_LENGTH_MAXIMUM equ <(sizeof(ETHERNET_HEADER) + sizeof(SNAP_HEADER))>
    DL_TUNNEL_HEADER_LENGTH_MAXIMUM equ <max(sizeof(IPV4_HEADER), sizeof(IPV6_HEADER))>
    ifndef _DEFINE_DL_ADDRESS_TYPE_
      _DEFINE_DL_ADDRESS_TYPE_ equ <>
      DL_ADDRESS_TYPE typedef SDWORD
      DlUnicast equ 0
      DlMulticast equ 1
      DlBroadcast equ 2
      PDL_ADDRESS_TYPE typedef ptr DL_ADDRESS_TYPE
      
    endif
    _DL_OUI union
      Byte_ UINT8 3 dup (?)
      struct
        DUMMYRECORDNAME_??3A record Group_??3A:1, Local_??3A:1
        DUMMYRECORDNAME_??3A <>
      ends
    _DL_OUI ends
    DL_OUI typedef _DL_OUI
    PDL_OUI typedef ptr _DL_OUI
    
    _DL_EI48 union
      Byte_ UINT8 3 dup (?)
    _DL_EI48 ends
    DL_EI48 typedef _DL_EI48
    PDL_EI48 typedef ptr _DL_EI48
    
    _DL_EUI48 union
      Byte_ UINT8 6 dup (?)
      struct
        Oui DL_OUI <>
        Ei48 DL_EI48 <>
      ends
    _DL_EUI48 ends
    DL_EUI48 typedef _DL_EUI48
    PDL_EUI48 typedef ptr _DL_EUI48
    
    EUI48_BROADCAST_INIT equ { 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh }
    externdef eui48_broadcast:DL_EUI48
    _DL_EI64 union
      Byte_ UINT8 5 dup (?)
    _DL_EI64 ends
    DL_EI64 typedef _DL_EI64
    PDL_EI64 typedef ptr _DL_EI64
    
    _DL_EUI64 union
      Byte_ UINT8 8 dup (?)
      Value UINT64 ?
      struct
        Oui DL_OUI <>
        union
          Ei64 DL_EI64 <>
          struct
            Type_ UINT8 ?
            Tse UINT8 ?
            Ei48 DL_EI48 <>
          ends
        ends
      ends
    _DL_EUI64 ends
    DL_EUI64 typedef _DL_EUI64
    PDL_EUI64 typedef ptr _DL_EUI64
    
    SNAP_HEADER struct
      Dsap UINT8 ?
      Ssap UINT8 ?
      Control UINT8 ?
      Oui UINT8 3 dup (?)
      Type_ UINT16 ?
    SNAP_HEADER ends
    _SNAP_HEADER typedef SNAP_HEADER
    PSNAP_HEADER typedef ptr SNAP_HEADER
    
    SNAP_DSAP equ 0aah
    SNAP_SSAP equ 0aah
    SNAP_CONTROL equ 03h
    SNAP_OUI equ 00h
    SNAP_TYPE_ARP equ <ETHERNET_TYPE_ARP>
    SNAP_TYPE_IPV4 equ <ETHERNET_TYPE_IPV4>
    SNAP_TYPE_IPV6 equ <ETHERNET_TYPE_IPV6>
    ETHERNET_HEADER struct
      Destination DL_EUI48 <>
      Source DL_EUI48 <>
      union
        Type_ UINT16 ?
        Length_ UINT16 ?
      ends
    ETHERNET_HEADER ends
    _ETHERNET_HEADER typedef ETHERNET_HEADER
    PETHERNET_HEADER typedef ptr ETHERNET_HEADER
    
    ETH_LENGTH_OF_HEADER equ 14
    ETH_LENGTH_OF_VLAN_HEADER equ 4
    ETH_LENGTH_OF_SNAP_HEADER equ 8
    ETHERNET_TYPE_MINIMUM equ 0600h
    ETHERNET_TYPE_IPV4 equ 0800h
    ETHERNET_TYPE_ARP equ 0806h
    ETHERNET_TYPE_IPV6 equ 86ddh
    ETHERNET_TYPE_802_1Q equ 8100h
    ETHERNET_TYPE_802_1AD equ 88a8h
    VLAN_TAG struct
      union
        Tag UINT16 ?
        struct
          DUMMYRECORDNAME_??4A record VID_??4A:12, CFI_??4A:1, User_Priority_??4A:3
          DUMMYRECORDNAME_??4A <>
        ends
      ends
      Type_ UINT16 ?
    VLAN_TAG ends
    _VLAN_TAG typedef VLAN_TAG
    EthernetAddressType proto WIN_STD_CALL_CONV :ptr UCHAR
    if Defined(_MSC_VER)
      if _MSC_VER ge 1200
      else
      endif
    endif
    ICMP_HEADER struct
      Type_ UINT8 ?
      Code UINT8 ?
      Checksum UINT16 ?
    ICMP_HEADER ends
    _ICMP_HEADER typedef ICMP_HEADER
    PICMP_HEADER typedef ptr ICMP_HEADER
    
    ICMP_MESSAGE struct
      Header ICMP_HEADER <>
      union Data
        Data32 UINT32 1 dup (?)
        Data16 UINT16 2 dup (?)
        Data8 UINT8 4 dup (?)
      ends
    ICMP_MESSAGE ends
    _ICMP_MESSAGE typedef ICMP_MESSAGE
    PICMP_MESSAGE typedef ptr ICMP_MESSAGE
    
    if Defined(_MSC_VER)
      if _MSC_VER ge 1200
      endif
    endif
    IPV4_HEADER struct
      union
        VersionAndHeaderLength UINT8 ?
        struct
          DUMMYRECORDNAME_??5A record HeaderLength_??5A:4, Version_??5A:4
          DUMMYRECORDNAME_??5A <>
        ends
      ends
      union
        TypeOfServiceAndEcnField UINT8 ?
        struct
          DUMMYRECORDNAME_??6A record EcnField_??6A:2, TypeOfService_??6A:6
          DUMMYRECORDNAME_??6A <>
        ends
      ends
      TotalLength UINT16 ?
      Identification UINT16 ?
      union
        FlagsAndOffset UINT16 ?
        struct
          DUMMYRECORDNAME_??7A record DontUse1_??7A:5, MoreFragments_??7A:1, DontFragment_??7A:1, Reserved_??7A:1, DontUse2_??7A:8
          DUMMYRECORDNAME_??7A <>
        ends
      ends
      TimeToLive UINT8 ?
      Protocol UINT8 ?
      HeaderChecksum UINT16 ?
      SourceAddress IN_ADDR <>
      DestinationAddress IN_ADDR <>
    IPV4_HEADER ends
    _IPV4_HEADER typedef IPV4_HEADER
    PIPV4_HEADER typedef ptr IPV4_HEADER
    
    ip4_hdr equ <_IPV4_HEADER>
    ip4_ver_hlen equ <VersionAndHeaderLength>
    ip4_ver equ <Version>
    ip4_hlen equ <HeaderLength>
    ip4_tos equ <TypeOfService>
    ip4_len equ <TotalLength>
    ip4_id equ <Identification>
    ip4_flags_offset equ <FlagsAndOffset>
    ip4_flags equ <Flags>
    ip4_offset equ <FragmentOffset>
    ip4_ttl equ <TimeToLive>
    ip4_protocol equ <Protocol>
    ip4_xsum equ <HeaderChecksum>
    ip4_src equ <SourceAddress>
    ip4_dest equ <DestinationAddress>
    IP_VER_MASK equ 0F0h
    IPV4_VERSION equ 4
    IPV4_VERSION_BYTE equ (IPV4_VERSION shl 4)
    IPV4_DEFAULT_VERHLEN equ <((IPV4_VERSION_BYTE) or (sizeof(IPV4_HEADER) / sizeof(UINT32)))>
    MAX_IPV4_PACKET equ 65535
    MAX_IPV4_PAYLOAD equ <(MAX_IPV4_PACKET - sizeof(IPV4_HEADER))>
    MAX_IPV4_HLEN equ 60
    IPV4_MINIMUM_MTU equ 576
    IPV4_MINIMUM_ULMTU equ <(IPV4_MINIMUM_MTU - sizeof(IPV4_HEADER))>
    IPV4_MIN_MINIMUM_MTU equ 352
    IPV4_MAX_MINIMUM_MTU equ <IPV4_MINIMUM_MTU>
    Ip4HeaderLengthInBytes proto WIN_STD_CALL_CONV :ptr IPV4_HEADER
    MAX_IP_OPTIONS_LENGTH equ ((0Fh * sizeof(UINT32)) - sizeof(IPV4_HEADER))
    SIZEOF_IP_OPT_ROUTING_HEADER equ 3
    SIZEOF_IP_OPT_TIMESTAMP_HEADER equ 4
    SIZEOF_IP_OPT_SECURITY equ 11
    SIZEOF_IP_OPT_STREAMIDENTIFIER equ 4
    SIZEOF_IP_OPT_ROUTERALERT equ 4
    IP4_OFF_MASK equ 0ff1fh
    if Defined(_NTDDK_) or Defined(_NTRTL_)
      Ip4FragmentOffset proto WIN_STD_CALL_CONV :ptr IPV4_HEADER
    endif
    IPV4_OPTION_HEADER struct
      union
        OptionType UINT8 ?
        struct
          DUMMYRECORDNAME_??8A record OptionNumber_??8A:5, OptionClass_??8A:2, CopiedFlag_??8A:1
          DUMMYRECORDNAME_??8A <>
        ends
      ends
      OptionLength UINT8 ?
    IPV4_OPTION_HEADER ends
    _IPV4_OPTION_HEADER typedef IPV4_OPTION_HEADER
    PIPV4_OPTION_HEADER typedef ptr IPV4_OPTION_HEADER
    
    ifndef IP_EXPORT_INCLUDED
      IPV4_OPTION_TYPE typedef SDWORD
      IP_OPT_EOL equ 00h
      IP_OPT_NOP equ 01h
      IP_OPT_SECURITY equ 82h
      IP_OPT_LSRR equ 83h
      IP_OPT_TS equ 44h
      IP_OPT_RR equ 07h
      IP_OPT_SSRR equ 89h
      IP_OPT_SID equ 88h
      IP_OPT_ROUTER_ALERT equ 94h
      IP_OPT_MULTIDEST equ 95h
      
    else
      IPV4_OPTION_TYPE typedef ULONG
    endif
    IPV4_TIMESTAMP_OPTION struct
      ifdef __cplusplus
        ;[...]
      else
      endif
      Pointer UINT8 ?
      union
        FlagsOverflow UINT8 ?
        struct
          DUMMYRECORDNAME_??9A record Flags_??9A:4, Overflow_??9A:4
          DUMMYRECORDNAME_??9A <>
        ends
      ends
    IPV4_TIMESTAMP_OPTION ends
    _IPV4_TIMESTAMP_OPTION typedef IPV4_TIMESTAMP_OPTION
    PIPV4_TIMESTAMP_OPTION typedef ptr IPV4_TIMESTAMP_OPTION
    
    IP_OPTION_TIMESTAMP_FLAGS typedef SDWORD
    IP_OPTION_TIMESTAMP_ONLY equ 0
    IP_OPTION_TIMESTAMP_ADDRESS equ 1
    IP_OPTION_TIMESTAMP_SPECIFIC_ADDRESS equ 3
    
    IPV4_ROUTING_HEADER struct
      ifdef __cplusplus
        ;[...]
      else
      endif
      Pointer UINT8 ?
    IPV4_ROUTING_HEADER ends
    _IPV4_ROUTING_HEADER typedef IPV4_ROUTING_HEADER
    PIPV4_ROUTING_HEADER typedef ptr IPV4_ROUTING_HEADER
    
    ICMPV4_HEADER typedef ICMP_HEADER
    PICMPV4_HEADER typedef ptr ICMP_HEADER
    ICMPV4_MESSAGE typedef ICMP_MESSAGE
    PICMPV4_MESSAGE typedef ptr ICMP_MESSAGE
    icmp4_hdr equ <_ICMPV4_MESSAGE>
    icmp4_type equ <Header.Type>
    icmp4_code equ <Header.Code>
    icmp4_cksum equ <Header.Checksum>
    icmp4_un_data32 equ <Data32>
    icmp4_un_data16 equ <Data16>
    icmp4_un_data8 equ <Data8>
    icmp4_dataun equ <Data>
    icmp4_data32 equ <icmp4_dataun.icmp4_un_data32>
    icmp4_data16 equ <icmp4_dataun.icmp4_un_data16>
    icmp4_data8 equ <icmp4_dataun.icmp4_un_data8>
    icmp4_pptr equ icmp4_data32 [ 0 ]
    icmp4_mtu equ icmp4_data32 [ 0 ]
    icmp4_id equ icmp4_data16 [ 0 ]
    icmp4_seq equ icmp4_data16 [ 1 ]
    icmp4_maxdelay equ icmp4_data16 [ 0 ]
    ICMP4_UNREACH_CODE typedef SDWORD
    ICMP4_UNREACH_NET equ 0
    ICMP4_UNREACH_HOST equ 1
    ICMP4_UNREACH_PROTOCOL equ 2
    ICMP4_UNREACH_PORT equ 3
    ICMP4_UNREACH_FRAG_NEEDED equ 4
    ICMP4_UNREACH_SOURCEROUTE_FAILED equ 5
    ICMP4_UNREACH_NET_UNKNOWN equ 6
    ICMP4_UNREACH_HOST_UNKNOWN equ 7
    ICMP4_UNREACH_ISOLATED equ 8
    ICMP4_UNREACH_NET_ADMIN equ 9
    ICMP4_UNREACH_HOST_ADMIN equ 10
    ICMP4_UNREACH_NET_TOS equ 11
    ICMP4_UNREACH_HOST_TOS equ 12
    ICMP4_UNREACH_ADMIN equ 13
    PICMP4_UNREACH_CODE typedef ptr ICMP4_UNREACH_CODE
    
    ICMP4_TIME_EXCEED_CODE typedef SDWORD
    ICMP4_TIME_EXCEED_TRANSIT equ 0
    ICMP4_TIME_EXCEED_REASSEMBLY equ 1
    PICMP4_TIME_EXCEED_CODE typedef ptr ICMP4_TIME_EXCEED_CODE
    
    ICMPV4_ROUTER_SOLICIT struct
      RsHeader ICMPV4_MESSAGE <>
    ICMPV4_ROUTER_SOLICIT ends
    _ICMPV4_ROUTER_SOLICIT typedef ICMPV4_ROUTER_SOLICIT
    PICMPV4_ROUTER_SOLICIT typedef ptr ICMPV4_ROUTER_SOLICIT
    
    RsType equ <RsHeader.icmp4_type>
    RsCode equ <RsHeader.icmp4_code>
    RsCksum equ <RsHeader.icmp4_cksum>
    RsReserved equ RsHeader.icmp4_data32 [ 0 ]
    ICMPV4_ROUTER_ADVERT_HEADER struct
      RaHeader ICMPV4_MESSAGE <>
    ICMPV4_ROUTER_ADVERT_HEADER ends
    _ICMPV4_ROUTER_ADVERT_HEADER typedef ICMPV4_ROUTER_ADVERT_HEADER
    PICMPV4_ROUTER_ADVERT_HEADER typedef ptr ICMPV4_ROUTER_ADVERT_HEADER
    
    RaType equ <RaHeader.icmp4_type>
    RaCode equ <RaHeader.icmp4_code>
    RaCksum equ <RaHeader.icmp4_cksum>
    RaNumAddr equ RaHeader.icmp4_data8 [ 0 ]
    RaAddrEntrySize equ RaHeader.icmp4_data8 [ 1 ]
    RaAddrLifetime equ RaHeader.icmp4_data16 [ 1 ]
    ICMPV4_ROUTER_ADVERT_ENTRY struct
      RouterAdvertAddr IN_ADDR <>
      PreferenceLevel LONG ?
    ICMPV4_ROUTER_ADVERT_ENTRY ends
    _ICMPV4_ROUTER_ADVERT_ENTRY typedef ICMPV4_ROUTER_ADVERT_ENTRY
    PICMPV4_ROUTER_ADVERT_ENTRY typedef ptr ICMPV4_ROUTER_ADVERT_ENTRY
    
    ICMPV4_INVALID_PREFERENCE_LEVEL equ 80000000h
    ICMPV4_TIMESTAMP_MESSAGE struct
      Header ICMPV4_MESSAGE <>
      OriginateTimestamp UINT32 ?
      ReceiveTimestamp UINT32 ?
      TransmitTimestamp UINT32 ?
    ICMPV4_TIMESTAMP_MESSAGE ends
    _ICMPV4_TIMESTAMP_MESSAGE typedef ICMPV4_TIMESTAMP_MESSAGE
    PICMPV4_TIMESTAMP_MESSAGE typedef ptr ICMPV4_TIMESTAMP_MESSAGE
    
    ICMPV4_ADDRESS_MASK_MESSAGE struct
      Header ICMPV4_MESSAGE <>
      AddressMask UINT32 ?
    ICMPV4_ADDRESS_MASK_MESSAGE ends
    _ICMPV4_ADDRESS_MASK_MESSAGE typedef ICMPV4_ADDRESS_MASK_MESSAGE
    PICMPV4_ADDRESS_MASK_MESSAGE typedef ptr ICMPV4_ADDRESS_MASK_MESSAGE
    
    icmp4_ts_type equ <Header.icmp4_type>
    icmp4_ts_code equ <Header.icmp4_code>
    icmp4_ts_cksum equ <Header.icmp4_cksum>
    icmp4_ts_id equ <Header.icmp4_id>
    icmp4_ts_seq equ <Header.icmp4_seq>
    icmp4_ts_originate equ <OriginateTimestamp>
    icmp4_ts_receive equ <ReceiveTimestamp>
    icmp4_ts_transmit equ <TransmitTimestamp>
    ARP_HEADER struct
      HardwareAddressSpace USHORT ?
      ProtocolAddressSpace USHORT ?
      HardwareAddressLength UCHAR ?
      ProtocolAddressLength UCHAR ?
      Opcode USHORT ?
      SenderHardwareAddress UCHAR 0 dup (?)
    ARP_HEADER ends
    _ARP_HEADER typedef ARP_HEADER
    PARP_HEADER typedef ptr ARP_HEADER
    
    ARP_OPCODE typedef SDWORD
    ARP_REQUEST equ 1
    ARP_RESPONSE equ 2
    
    ARP_HARDWARE_TYPE typedef SDWORD
    ARP_HW_ENET equ 1
    ARP_HW_802 equ 6
    
    IGMP_QUERY_TYPE equ 11h
    IGMP_VERSION1_REPORT_TYPE equ 12h
    IGMP_VERSION2_REPORT_TYPE equ 16h
    IGMP_LEAVE_GROUP_TYPE equ 17h
    IGMP_VERSION3_REPORT_TYPE equ 22h
    IGMP_HEADER struct
      union
        struct
          DUMMYRECORDNAME_??10A record Type_??10A:4, Version_??10A:4
          DUMMYRECORDNAME_??10A <>
        ends
        VersionType UINT8 ?
      ends
      union
        Reserved UINT8 ?
        MaxRespTime UINT8 ?
        Code UINT8 ?
      ends
      Checksum UINT16 ?
      MulticastAddress IN_ADDR <>
    IGMP_HEADER ends
    _IGMP_HEADER typedef IGMP_HEADER
    PIGMP_HEADER typedef ptr IGMP_HEADER
    
    IGMP_MAX_RESP_CODE_TYPE typedef SDWORD
    IGMP_MAX_RESP_CODE_TYPE_NORMAL equ 0
    IGMP_MAX_RESP_CODE_TYPE_FLOAT equ 1
    
    IGMPV3_QUERY_HEADER struct
      Type_ UINT8 ?
      union
        MaxRespCode UINT8 ?
        struct
          DUMMYRECORDNAME_??11A record MaxRespCodeMantissa_??11A:4, MaxRespCodeExponent_??11A:3, MaxRespCodeType_??11A:1
          DUMMYRECORDNAME_??11A <>
        ends
      ends
      Checksum UINT16 ?
      MulticastAddress IN_ADDR <>
      IGMPV3_QUERY_HEADER_??12A record QuerierRobustnessVariable_??12A:3, SuppressRouterSideProcessing_??12A:1, Reserved_??12A:4
      IGMPV3_QUERY_HEADER_??12A <>
      union
        QueriersQueryInterfaceCode UINT8 ?
        struct
          DUMMYRECORDNAME_??13A record QQCMantissa_??13A:4, QQCExponent_??13A:3, QQCType_??13A:1
          DUMMYRECORDNAME_??13A <>
        ends
      ends
      SourceCount UINT16 ?
    IGMPV3_QUERY_HEADER ends
    _IGMPV3_QUERY_HEADER typedef IGMPV3_QUERY_HEADER
    PIGMPV3_QUERY_HEADER typedef ptr IGMPV3_QUERY_HEADER
    
    IGMPV3_REPORT_RECORD_HEADER struct
      Type_ UINT8 ?
      AuxillaryDataLength UINT8 ?
      SourceCount UINT16 ?
      MulticastAddress IN_ADDR <>
    IGMPV3_REPORT_RECORD_HEADER ends
    _IGMPV3_REPORT_RECORD_HEADER typedef IGMPV3_REPORT_RECORD_HEADER
    PIGMPV3_REPORT_RECORD_HEADER typedef ptr IGMPV3_REPORT_RECORD_HEADER
    
    IGMPV3_REPORT_HEADER struct
      Type_ UINT8 ?
      Reserved UINT8 ?
      Checksum UINT16 ?
      Reserved2 UINT16 ?
      RecordCount UINT16 ?
    IGMPV3_REPORT_HEADER ends
    _IGMPV3_REPORT_HEADER_ typedef IGMPV3_REPORT_HEADER
    PIGMPV3_REPORT_HEADER typedef ptr IGMPV3_REPORT_HEADER
    
    if Defined(_MSC_VER)
      if _MSC_VER ge 1200
      else
      endif
    endif
    IPV6_HEADER struct
      union
        VersionClassFlow UINT32 ?
        struct
          DUMMYRECORDNAME_??14A record Bitfield0_??14A:4, Version_??14A:4, Bitfield2_??14A:24
          DUMMYRECORDNAME_??14A <>
        ends
      ends
      PayloadLength UINT16 ?
      NextHeader UINT8 ?
      HopLimit UINT8 ?
      SourceAddress IN6_ADDR <>
      DestinationAddress IN6_ADDR <>
    IPV6_HEADER ends
    _IPV6_HEADER typedef IPV6_HEADER
    PIPV6_HEADER typedef ptr IPV6_HEADER
    
    ip6_hdr equ <_IPV6_HEADER>
    ip6_flow equ <VersionClassFlow>
    ip6_plen equ <PayloadLength>
    ip6_nxt equ <NextHeader>
    ip6_hops equ <HopLimit>
    ip6_hlim equ <HopLimit>
    ip6_src equ <SourceAddress>
    ip6_dst equ <DestinationAddress>
    IP_VER_MASK equ 0F0h
    IPV6_VERSION equ 60h
    IPV6_TRAFFIC_CLASS_MASK equ 0000C00Fh
    IPV6_FULL_TRAFFIC_CLASS_MASK equ 0000F00Fh
    IPV6_ECN_MASK equ 00003000h
    IPV6_FLOW_LABEL_MASK equ 0FFFF0F00h
    MAX_IPV6_PAYLOAD equ 65535
    MAX_IPV6_PACKET equ <(MAX_IPV6_PAYLOAD + sizeof(IPV6_HEADER))>
    IPV6_ECN_SHIFT equ 12
    IPV6_MINIMUM_MTU equ 1280
    IPV6_MINIMUM_ULMTU equ <(IPV6_MINIMUM_MTU - sizeof(IPV6_HEADER))>
    IPV6_TRAFFIC_CLASS macro VersionClassFlow
      exitm <((UCHAR) ((((VersionClassFlow) and IPV6_TRAFFIC_CLASS_MASK) shr 12) + (((VersionClassFlow) and IPV6_TRAFFIC_CLASS_MASK) shl 4)))>
    endm
    IPV6_FULL_TRAFFIC_CLASS macro VersionClassFlow
      exitm <((UCHAR) ((((VersionClassFlow) and IPV6_FULL_TRAFFIC_CLASS_MASK) shr 12) + (((VersionClassFlow) and IPV6_FULL_TRAFFIC_CLASS_MASK) shl 4)))>
    endm
    IPV6_FRAGMENT_HEADER struct
      NextHeader UINT8 ?
      Reserved UINT8 ?
      union
        struct
          DUMMYRECORDNAME_??15A record DontUse1_??15A:8, MoreFragments_??15A:1, ReservedBits_??15A:2, DontUse2_??15A:5
          DUMMYRECORDNAME_??15A <>
        ends
        OffsetAndFlags UINT16 ?
      ends
      Id UINT32 ?
    IPV6_FRAGMENT_HEADER ends
    _IPV6_FRAGMENT_HEADER typedef IPV6_FRAGMENT_HEADER
    PIPV6_FRAGMENT_HEADER typedef ptr IPV6_FRAGMENT_HEADER
    
    ip6_frag equ <_IPV6_FRAGMENT_HEADER>
    ip6f_nxt equ <NextHeader>
    ip6f_reserved equ <Reserved>
    ip6f_offlg equ <OffsetAndFlags>
    ip6f_ident equ <Id>
    IP6F_OFF_MASK equ 0f8ffh
    IP6F_RESERVED_MASK equ 0600h
    IP6F_MORE_FRAG equ 0100h
    if Defined(_NTDDK_) or Defined(_NTRTL_)
      Ip6FragmentOffset proto WIN_STD_CALL_CONV :ptr IPV6_FRAGMENT_HEADER
    endif
    IPV6_EXTENSION_HEADER struct
      NextHeader UINT8 ?
      Length_ UINT8 ?
    IPV6_EXTENSION_HEADER ends
    _IPV6_EXTENSION_HEADER typedef IPV6_EXTENSION_HEADER
    PIPV6_EXTENSION_HEADER typedef ptr IPV6_EXTENSION_HEADER
    
    EXT_LEN_UNIT equ 8
    IPV6_EXTENSION_HEADER_LENGTH macro Blocks
      exitm <((Blocks + 1) * EXT_LEN_UNIT)>
    endm
    MAX_IPV6_EXTENSION_HEADER_LENGTH equ IPV6_EXTENSION_HEADER_LENGTH(0FFh)
    IPV6_EXTENSION_HEADER_BLOCKS macro Length_
      exitm <((Length_ / EXT_LEN_UNIT) - 1)>
    endm
    IP_AUTHENTICATION_HEADER_LENGTH macro Blocks
      exitm <((Blocks + 2) * 4)>
    endm
    IP_AUTHENTICATION_HEADER_BLOCKS macro Length_
      exitm <(((Length_ + sizeof(AUTHENTICATION_HEADER)) / 4) - 2)>
    endm
    IPV6_ROUTER_ALERT_LENGTH equ IPV6_EXTENSION_HEADER_LENGTH(0)
    ip6_hbh equ <_IPV6_EXTENSION_HEADER>
    ip6h_nxt equ <NextHeader>
    ip6h_len equ <Length>
    ip6_dest equ <_IPV6_EXTENSION_HEADER>
    ip6d_nxt equ <NextHeader>
    ip6d_len equ <Length>
    IPV6_OPTION_HEADER struct
      Type_ UINT8 ?
      DataLength UINT8 ?
    IPV6_OPTION_HEADER ends
    _IPV6_OPTION_HEADER typedef IPV6_OPTION_HEADER
    PIPV6_OPTION_HEADER typedef ptr IPV6_OPTION_HEADER
    
    IPV6_OPTION_TYPE typedef SDWORD
    IP6OPT_PAD1 equ 00h
    IP6OPT_PADN equ 01h
    IP6OPT_TUNNEL_LIMIT equ 04h
    IP6OPT_ROUTER_ALERT equ 05h
    IP6OPT_JUMBO equ 0c2h
    IP6OPT_NSAP_ADDR equ 0c3h
    PIPV6_OPTION_TYPE typedef ptr IPV6_OPTION_TYPE
    
    IP6OPT_TYPE macro Type_
      exitm <((Type_) and 0c0h)>
    endm
    IP6OPT_TYPE_SKIP equ 00h
    IP6OPT_TYPE_DISCARD equ 40h
    IP6OPT_TYPE_FORCEICMP equ 80h
    IP6OPT_TYPE_ICMP equ 0c0h
    IP6OPT_MUTABLE equ 20h
    IP6OPT_ISMUTABLE macro Type_
      exitm <(((Type_) and IP6OPT_MUTABLE) != 0)>
    endm
    IPV6_OPTION_JUMBOGRAM struct
      Header IPV6_OPTION_HEADER <>
      JumbogramLength UINT8 4 dup (?)
    IPV6_OPTION_JUMBOGRAM ends
    _IPV6_OPTION_JUMBOGRAM typedef IPV6_OPTION_JUMBOGRAM
    PIPV6_OPTION_JUMBOGRAM typedef ptr IPV6_OPTION_JUMBOGRAM
    
    ip6_opt_jumbo equ <_IPV6_OPTION_JUMBOGRAM>
    ip6oj_type equ <Header.Type>
    ip6oj_len equ <Header.DataLength>
    ip6oj_jumbo_len equ <JumbogramLength>
    IPV6_OPTION_ROUTER_ALERT struct
      Header IPV6_OPTION_HEADER <>
      Value UINT8 2 dup (?)
    IPV6_OPTION_ROUTER_ALERT ends
    _IPV6_OPTION_ROUTER_ALERT typedef IPV6_OPTION_ROUTER_ALERT
    PIPV6_OPTION_ROUTER_ALERT typedef ptr IPV6_OPTION_ROUTER_ALERT
    
    ip6_opt_router equ <_IPV6_OPTION_ROUTER_ALERT>
    ip6or_type equ <Header.Type>
    ip6or_len equ <Header.DataLength>
    ip6or_value equ <Value>
    SIZEOF_IPV6_ROUTERALERT equ IPV6_EXTENSION_HEADER_LENGTH(0)
    IPV6_ROUTING_HEADER struct
      NextHeader UCHAR ?
      Length_ UCHAR ?
      RoutingType UCHAR ?
      SegmentsLeft UCHAR ?
      Reserved UCHAR 4 dup (?)
    IPV6_ROUTING_HEADER ends
    _IPV6_ROUTING_HEADER typedef IPV6_ROUTING_HEADER
    PIPV6_ROUTING_HEADER typedef ptr IPV6_ROUTING_HEADER
    
    ip6_rthdr equ <_IPV6_ROUTING_HEADER>
    ip6r_nxt equ <NextHeader>
    ip6r_len equ <Length>
    ip6r_type equ <RoutingType>
    ip6r_segleft equ <SegmentsLeft>
    ICMPV6_HEADER typedef ICMP_HEADER
    PICMPV6_HEADER typedef ptr ICMP_HEADER
    ICMPV6_MESSAGE typedef ICMP_MESSAGE
    PICMPV6_MESSAGE typedef ptr ICMP_MESSAGE
    icmp6_hdr equ <_ICMPV6_MESSAGE>
    icmp6_type equ <Header.Type>
    icmp6_code equ <Header.Code>
    icmp6_cksum equ <Header.Checksum>
    icmp6_un_data32 equ <Data32>
    icmp6_un_data16 equ <Data16>
    icmp6_un_data8 equ <Data8>
    icmp6_dataun equ <Data>
    icmp6_data32 equ <icmp6_dataun.icmp6_un_data32>
    icmp6_data16 equ <icmp6_dataun.icmp6_un_data16>
    icmp6_data8 equ <icmp6_dataun.icmp6_un_data8>
    icmp6_pptr equ icmp6_data32 [ 0 ]
    icmp6_mtu equ icmp6_data32 [ 0 ]
    icmp6_id equ icmp6_data16 [ 0 ]
    icmp6_seq equ icmp6_data16 [ 1 ]
    icmp6_maxdelay equ icmp6_data16 [ 0 ]
    ICMP6_INFOMSG_MASK equ 80h
    ICMP6_DST_UNREACH_NOROUTE equ 0
    ICMP6_DST_UNREACH_ADMIN equ 1
    ICMP6_DST_UNREACH_BEYONDSCOPE equ 2
    ICMP6_DST_UNREACH_ADDR equ 3
    ICMP6_DST_UNREACH_NOPORT equ 4
    ICMP6_TIME_EXCEED_TRANSIT equ 0
    ICMP6_TIME_EXCEED_REASSEMBLY equ 1
    ICMP6_PARAMPROB_HEADER equ 0
    ICMP6_PARAMPROB_NEXTHEADER equ 1
    ICMP6_PARAMPROB_OPTION equ 2
    ICMP6_PARAMPROB_FIRSTFRAGMENT equ 3
    ICMPV6_ECHO_REQUEST_FLAG_REVERSE equ 1h
    ND_ROUTER_SOLICIT_HEADER struct
      nd_rs_hdr ICMPV6_MESSAGE <>
    ND_ROUTER_SOLICIT_HEADER ends
    nd_router_solicit typedef ND_ROUTER_SOLICIT_HEADER
    PND_ROUTER_SOLICIT_HEADER typedef ptr ND_ROUTER_SOLICIT_HEADER
    
    nd_rs_type equ <nd_rs_hdr.icmp6_type>
    nd_rs_code equ <nd_rs_hdr.icmp6_code>
    nd_rs_cksum equ <nd_rs_hdr.icmp6_cksum>
    nd_rs_reserved equ nd_rs_hdr.icmp6_data32 [ 0 ]
    ND_ROUTER_ADVERT_HEADER struct
      nd_ra_hdr ICMPV6_MESSAGE <>
      nd_ra_reachable UINT32 ?
      nd_ra_retransmit UINT32 ?
    ND_ROUTER_ADVERT_HEADER ends
    nd_router_advert typedef ND_ROUTER_ADVERT_HEADER
    PND_ROUTER_ADVERT_HEADER typedef ptr ND_ROUTER_ADVERT_HEADER
    
    nd_ra_type equ <nd_ra_hdr.icmp6_type>
    nd_ra_code equ <nd_ra_hdr.icmp6_code>
    nd_ra_cksum equ <nd_ra_hdr.icmp6_cksum>
    nd_ra_curhoplimit equ nd_ra_hdr.icmp6_data8 [ 0 ]
    nd_ra_flags_reserved equ nd_ra_hdr.icmp6_data8 [ 1 ]
    ND_RA_FLAG_MANAGED equ 80h
    ND_RA_FLAG_OTHER equ 40h
    ND_RA_FLAG_HOME_AGENT equ 20h
    ND_RA_FLAG_PREFERENCE equ 18h
    nd_ra_router_lifetime equ nd_ra_hdr.icmp6_data16 [ 1 ]
    IPV6_ROUTER_ADVERTISEMENT_FLAGS union
      struct
        DUMMYRECORDNAME_??16A record Reserved_??16:3, Preference_??16:2, HomeAgent_??16:1, OtherStatefulConfiguration_??16:1, ManagedAddressConfiguration_??16:1
        DUMMYRECORDNAME_??16A <>
      ends
      Value UINT8 ?
    IPV6_ROUTER_ADVERTISEMENT_FLAGS ends
    _IPV6_ROUTER_ADVERTISEMENT_FLAGS typedef IPV6_ROUTER_ADVERTISEMENT_FLAGS
    PIPV6_ROUTER_ADVERTISEMENT_FLAGS typedef ptr IPV6_ROUTER_ADVERTISEMENT_FLAGS
    
    ND_NEIGHBOR_SOLICIT_HEADER struct
      nd_ns_hdr ICMPV6_MESSAGE <>
      nd_ns_target IN6_ADDR <>
    ND_NEIGHBOR_SOLICIT_HEADER ends
    nd_neighbor_solicit typedef ND_NEIGHBOR_SOLICIT_HEADER
    PND_NEIGHBOR_SOLICIT_HEADER typedef ptr ND_NEIGHBOR_SOLICIT_HEADER
    
    nd_ns_type equ <nd_ns_hdr.icmp6_type>
    nd_ns_code equ <nd_ns_hdr.icmp6_code>
    nd_ns_cksum equ <nd_ns_hdr.icmp6_cksum>
    nd_ns_reserved equ nd_ns_hdr.icmp6_data32 [ 0 ]
    ND_NEIGHBOR_ADVERT_HEADER struct
      nd_na_hdr ICMPV6_MESSAGE <>
      nd_na_target IN6_ADDR <>
    ND_NEIGHBOR_ADVERT_HEADER ends
    nd_neighbor_advert typedef ND_NEIGHBOR_ADVERT_HEADER
    PND_NEIGHBOR_ADVERT_HEADER typedef ptr ND_NEIGHBOR_ADVERT_HEADER
    
    nd_na_type equ <nd_na_hdr.icmp6_type>
    nd_na_code equ <nd_na_hdr.icmp6_code>
    nd_na_cksum equ <nd_na_hdr.icmp6_cksum>
    nd_na_flags_reserved equ nd_na_hdr.icmp6_data32 [ 0 ]
    if (BYTE_ORDER eq _BIG_ENDIAN)
      ND_NA_FLAG_ROUTER equ 80000000h
      ND_NA_FLAG_SOLICITED equ 40000000h
      ND_NA_FLAG_OVERRIDE equ 20000000h
    else
      ND_NA_FLAG_ROUTER equ 00000080h
      ND_NA_FLAG_SOLICITED equ 00000040h
      ND_NA_FLAG_OVERRIDE equ 00000020h
    endif
    IPV6_NEIGHBOR_ADVERTISEMENT_FLAGS union
      struct
        DUMMYRECORDNAME_??17A record Reserved1_??17:5, Override_??17:1, Solicited_??17:1, Router_??17:1
        DUMMYRECORDNAME_??17A <>
        Reserved2 UINT8 3 dup (?)
      ends
      Value UINT32 ?
    IPV6_NEIGHBOR_ADVERTISEMENT_FLAGS ends
    _IPV6_NEIGHBOR_ADVERTISEMENT_FLAGS typedef IPV6_NEIGHBOR_ADVERTISEMENT_FLAGS
    PIPV6_NEIGHBOR_ADVERTISEMENT_FLAGS typedef ptr IPV6_NEIGHBOR_ADVERTISEMENT_FLAGS
    
    ND_REDIRECT_HEADER struct
      nd_rd_hdr ICMPV6_MESSAGE <>
      nd_rd_target IN6_ADDR <>
      nd_rd_dst IN6_ADDR <>
    ND_REDIRECT_HEADER ends
    nd_redirect typedef ND_REDIRECT_HEADER
    PND_REDIRECT_HEADER typedef ptr ND_REDIRECT_HEADER
    
    nd_rd_type equ <nd_rd_hdr.icmp6_type>
    nd_rd_code equ <nd_rd_hdr.icmp6_code>
    nd_rd_cksum equ <nd_rd_hdr.icmp6_cksum>
    nd_rd_reserved equ nd_rd_hdr.icmp6_data32 [ 0 ]
    ND_OPTION_HDR struct
      nd_opt_type UINT8 ?
      nd_opt_len UINT8 ?
    ND_OPTION_HDR ends
    nd_opt_hdr typedef ND_OPTION_HDR
    PND_OPTION_HDR typedef ptr ND_OPTION_HDR
    
    ND_OPTION_TYPE typedef SDWORD
    ND_OPT_SOURCE_LINKADDR equ 1
    ND_OPT_TARGET_LINKADDR equ 2
    ND_OPT_PREFIX_INFORMATION equ 3
    ND_OPT_REDIRECTED_HEADER equ 4
    ND_OPT_MTU equ 5
    ND_OPT_NBMA_SHORTCUT_LIMIT equ 6
    ND_OPT_ADVERTISEMENT_INTERVAL equ 7
    ND_OPT_HOME_AGENT_INFORMATION equ 8
    ND_OPT_SOURCE_ADDR_LIST equ 9
    ND_OPT_TARGET_ADDR_LIST equ 10
    ND_OPT_ROUTE_INFO equ 24
    ND_OPT_RDNSS equ 25
    ND_OPT_DNSSL equ 31
    PND_OPTION_TYPE typedef ptr ND_OPTION_TYPE
    
    ND_OPTION_PREFIX_INFO struct
      nd_opt_pi_type UINT8 ?
      nd_opt_pi_len UINT8 ?
      nd_opt_pi_prefix_len UINT8 ?
      union
        nd_opt_pi_flags_reserved UINT8 ?
        struct Flags
          Flags_??18 record Route_??18:1, Reserved1_??18:3, SitePrefix_??18:1, RouterAddress_??18:1, Autonomous_??18:1, OnLink_??18:1
          Flags_??18 <>
        ends
      ends
      nd_opt_pi_valid_time UINT32 ?
      nd_opt_pi_preferred_time UINT32 ?
      union
        nd_opt_pi_reserved2 UINT32 ?
        struct
          nd_opt_pi_reserved3 UINT8 3 dup (?)
          nd_opt_pi_site_prefix_len UINT8 ?
        ends
      ends
      nd_opt_pi_prefix IN6_ADDR <>
    ND_OPTION_PREFIX_INFO ends
    nd_opt_prefix_info typedef ND_OPTION_PREFIX_INFO
    PND_OPTION_PREFIX_INFO typedef ptr ND_OPTION_PREFIX_INFO
    
    ND_OPT_PI_FLAG_ONLINK equ 80h
    ND_OPT_PI_FLAG_AUTO equ 40h
    ND_OPT_PI_FLAG_ROUTER_ADDR equ 20h
    ND_OPT_PI_FLAG_SITE_PREFIX equ 10h
    ND_OPT_PI_FLAG_ROUTE equ 01h
    ND_OPTION_RD_HDR struct
      nd_opt_rh_type UINT8 ?
      nd_opt_rh_len UINT8 ?
      nd_opt_rh_reserved1 UINT16 ?
      nd_opt_rh_reserved2 UINT32 ?
    ND_OPTION_RD_HDR ends
    nd_opt_rd_hdr typedef ND_OPTION_RD_HDR
    PND_OPTION_RD_HDR typedef ptr ND_OPTION_RD_HDR
    
    ND_OPTION_MTU struct
      nd_opt_mtu_type UINT8 ?
      nd_opt_mtu_len UINT8 ?
      nd_opt_mtu_reserved UINT16 ?
      nd_opt_mtu_mtu UINT32 ?
    ND_OPTION_MTU ends
    nd_opt_mtu typedef ND_OPTION_MTU
    PND_OPTION_MTU typedef ptr ND_OPTION_MTU
    
    ND_OPTION_ROUTE_INFO struct
      nd_opt_ri_type UINT8 ?
      nd_opt_ri_len UINT8 ?
      nd_opt_ri_prefix_len UINT8 ?
      union
        nd_opt_ri_flags_reserved UINT8 ?
        struct Flags
          Flags_??19A record Reserved_??19A:3, Preference_??19A:2
          Flags_??19A <>
        ends
      ends
      nd_opt_ri_route_lifetime UINT32 ?
      nd_opt_ri_prefix IN6_ADDR <>
    ND_OPTION_ROUTE_INFO ends
    nd_opt_route_info typedef ND_OPTION_ROUTE_INFO
    PND_OPTION_ROUTE_INFO typedef ptr ND_OPTION_ROUTE_INFO
    
    ND_OPT_RI_FLAG_PREFERENCE equ 18h
    ND_OPTION_RDNSS struct
      nd_opt_rdnss_type UINT8 ?
      nd_opt_rdnss_len UINT8 ?
      nd_opt_rdnss_reserved UINT16 ?
      nd_opt_rdnss_lifetime UINT32 ?
    ND_OPTION_RDNSS ends
    nd_opt_rdnss typedef ND_OPTION_RDNSS
    PND_OPTION_RDNSS typedef ptr ND_OPTION_RDNSS
    
    ND_OPT_RDNSS_MIN_LEN equ 24
    ND_OPTION_DNSSL struct
      nd_opt_dnssl_type UINT8 ?
      nd_opt_dnssl_len UINT8 ?
      nd_opt_dnssl_reserved UINT16 ?
      nd_opt_dnssl_lifetime UINT32 ?
    ND_OPTION_DNSSL ends
    nd_opt_dnssl typedef ND_OPTION_DNSSL
    PND_OPTION_DNSSL typedef ptr ND_OPTION_DNSSL
    
    ND_OPT_DNSSL_MIN_LEN equ 16
    MLD_HEADER struct
      IcmpHeader ICMPV6_HEADER <>
      MaxRespTime UINT16 ?
      Reserved UINT16 ?
      MulticastAddress IN6_ADDR <>
    MLD_HEADER ends
    _MLD_HEADER typedef MLD_HEADER
    PMLD_HEADER typedef ptr MLD_HEADER
    
    mld_type equ <IcmpHeader.Type>
    mld_checksum equ <IcmpHeader.Checksum>
    MLD_MAX_RESP_CODE_TYPE typedef SDWORD
    MLD_MAX_RESP_CODE_TYPE_NORMAL equ 0
    MLD_MAX_RESP_CODE_TYPE_FLOAT equ 1
    
    MLDV2_QUERY_HEADER struct
      IcmpHeader ICMPV6_HEADER <>
      union
        MaxRespCode UINT16 ?
        struct
          DUMMYRECORDNAME_??20A record MaxRespCodeMantissaHi_??20A:4, MaxRespCodeExponent_??20A:3, MaxRespCodeType_??20A:1, MaxRespCodeMantissaLo_??20A:8
          DUMMYRECORDNAME_??20A <>
        ends
      ends
      Reserved UINT16 ?
      MulticastAddress IN6_ADDR <>
      MLDV2_QUERY_HEADER_??21 record QuerierRobustnessVariable_??21:3, SuppressRouterSideProcessing_??21:1, QueryReserved_??21:4
      MLDV2_QUERY_HEADER_??21 <>
      union
        QueriersQueryInterfaceCode UINT8 ?
        struct
          DUMMYRECORDNAME_??22 record QQCMantissa_??22:4, QQCExponent_??22:3, QQCType_??22:1
          DUMMYRECORDNAME_??22 <>
        ends
      ends
      SourceCount UINT16 ?
    MLDV2_QUERY_HEADER ends
    _MLDV2_QUERY_HEADER typedef MLDV2_QUERY_HEADER
    PMLDV2_QUERY_HEADER typedef ptr MLDV2_QUERY_HEADER
    
    MLDV2_REPORT_RECORD_HEADER struct
      Type_ UINT8 ?
      AuxillaryDataLength UINT8 ?
      SourceCount UINT16 ?
      MulticastAddress IN6_ADDR <>
    MLDV2_REPORT_RECORD_HEADER ends
    _MLDV2_REPORT_RECORD_HEADER typedef MLDV2_REPORT_RECORD_HEADER
    PMLDV2_REPORT_RECORD_HEADER typedef ptr MLDV2_REPORT_RECORD_HEADER
    
    MLDV2_REPORT_HEADER struct
      IcmpHeader ICMPV6_HEADER <>
      Reserved UINT16 ?
      RecordCount UINT16 ?
    MLDV2_REPORT_HEADER ends
    _MLDV2_REPORT_HEADER typedef MLDV2_REPORT_HEADER
    PMLDV2_REPORT_HEADER typedef ptr MLDV2_REPORT_HEADER
    
    if Defined(_NTDDK_) or Defined(_NTRTL_)
      Ipv6pGetVersionClassEcnFlow proto WIN_STD_CALL_CONV :UINT8, :UINT8, :UINT32
    endif
    IN6_EMBEDDEDV4_UOCTET_POSITION equ 8
    IN6_EMBEDDEDV4_BITS_IN_BYTE equ 8
    In6IsEmbeddedV4AddrPrefixLengthValid proto WIN_STD_CALL_CONV :ULONG
    In6ExtractEmbeddedV4AddrFromV6 proto WIN_STD_CALL_CONV :ptr IN6_ADDR, :ULONG, :ptr IN_ADDR
    In6SetAddrV4Embedded proto WIN_STD_CALL_CONV :ptr IN6_ADDR, :ULONG, :ptr IN_ADDR, :ptr IN6_ADDR
    SEQ_NUM typedef UINT32
    PSEQ_NUM typedef ptr UINT32
    TCP_HDR struct
      th_sport UINT16 ?
      th_dport UINT16 ?
      th_seq SEQ_NUM ?
      th_ack SEQ_NUM ?
      TCP_HDR_??23 record th_x2_??23:4, th_len_??23:4
      TCP_HDR_??23 <>
      th_flags UINT8 ?
      th_win UINT16 ?
      th_sum UINT16 ?
      th_urp UINT16 ?
    TCP_HDR ends
    tcp_hdr typedef TCP_HDR
    if NDIS_RECEIVE_UNALIGNED
      PTCP_HDR typedef ptr TCP_HDR
    else
    endif
    TH_MAX_LEN equ (0Fh shl 2)
    TH_FIN equ 01h
    TH_SYN equ 02h
    TH_RST equ 04h
    TH_PSH equ 08h
    TH_ACK equ 10h
    TH_URG equ 20h
    TH_ECE equ 40h
    TH_CWR equ 80h
    TH_ALL equ <(TH_FIN or TH_SYN or TH_RST or TH_PSH or TH_ACK or TH_URG or TH_ECE or TH_CWR)>
    TH_SYN_ALL equ <(TH_FIN or TH_SYN or TH_RST or TH_ACK)>
    TH_OPT_EOL equ 00h
    TH_OPT_NOP equ 01h
    TH_OPT_MSS equ 02h
    TH_OPT_WS equ 03h
    TH_OPT_SACK_PERMITTED equ 04h
    TH_OPT_SACK equ 05h
    TH_OPT_TS equ 08h
    TH_OPT_FASTOPEN equ 22h
    TCP_OPT_MSS struct
      Kind UINT8 ?
      Length_ UINT8 ?
      Mss UINT16 ?
    TCP_OPT_MSS ends
    tcp_opt_mss typedef TCP_OPT_MSS
    TCP_OPT_WS struct
      Kind UINT8 ?
      Length_ UINT8 ?
      ShiftCnt UINT8 ?
    TCP_OPT_WS ends
    tcp_opt_ws typedef TCP_OPT_WS
    TCP_OPT_SACK_PERMITTED struct
      Kind UINT8 ?
      Length_ UINT8 ?
    TCP_OPT_SACK_PERMITTED ends
    tcp_opt_sack_permitted typedef TCP_OPT_SACK_PERMITTED
    TCP_OPT_SACK struct
      Kind UINT8 ?
      Length_ UINT8 ?
      struct Block
        Left SEQ_NUM ?
        Right SEQ_NUM ?
      ends
    TCP_OPT_SACK ends
    tcp_opt_sack typedef TCP_OPT_SACK
    TCP_OPT_TS struct
      Kind UINT8 ?
      Length_ UINT8 ?
      Val UINT32 ?
      EcR UINT32 ?
    TCP_OPT_TS ends
    tcp_opt_ts typedef TCP_OPT_TS
    TCP_OPT_UNKNOWN struct
      Kind UINT8 ?
      Length_ UINT8 ?
    TCP_OPT_UNKNOWN ends
    tcp_opt_unknown typedef TCP_OPT_UNKNOWN
    TCP_OPT_FASTOPEN struct
      Kind UINT8 ?
      Length_ UINT8 ?
      Cookie UINT8 0 dup (?)
    TCP_OPT_FASTOPEN ends
    tcp_opt_fastopen typedef TCP_OPT_FASTOPEN
;    include ifdef.inc
    if Defined(_MSC_VER)
      if _MSC_VER ge 1200
      endif
    endif
    DL_TUNNEL_ADDRESS struct
      CompartmentId COMPARTMENT_ID ?
      ScopeId SCOPE_ID <>
      IpAddress UCHAR 0 dup (?)
    DL_TUNNEL_ADDRESS ends
    PDL_TUNNEL_ADDRESS typedef ptr DL_TUNNEL_ADDRESS
    
    DL_SIZEOF_TUNNEL_ADDRESS macro AddressBytes
      exitm <(FIELD_OFFSET(DL_TUNNEL_ADDRESS, IpAddress) + (AddressBytes))>
    endm
    DL_SIZEOF_IPV4_TUNNEL_ADDRESS equ <DL_SIZEOF_TUNNEL_ADDRESS(sizeof(IN_ADDR))>
    DL_SIZEOF_IPV6_TUNNEL_ADDRESS equ <DL_SIZEOF_TUNNEL_ADDRESS(sizeof(IN6_ADDR))>
    TUNNEL_SUB_TYPE typedef SDWORD
    TUNNEL_SUB_TYPE_NONE equ 0
    TUNNEL_SUB_TYPE_CP equ 1
    TUNNEL_SUB_TYPE_IPTLS equ 2
    TUNNEL_SUB_TYPE_HA equ 3
    _TUNNEL_SUB_TYPE typedef TUNNEL_SUB_TYPE
    PTUNNEL_SUB_TYPE typedef ptr TUNNEL_SUB_TYPE
    
    DL_TEREDO_ADDRESS struct
      Reserved UINT8 6 dup (?)
      union
        Eui64 DL_EUI64 <>
        struct
          Flags USHORT ?
          MappedPort USHORT ?
          MappedAddress IN_ADDR <>
        ends
      ends
    DL_TEREDO_ADDRESS ends
    PDL_TEREDO_ADDRESS typedef ptr DL_TEREDO_ADDRESS
    
    DL_TEREDO_ADDRESS_PRV struct
      Reserved UINT8 6 dup (?)
      union
        Eui64 DL_EUI64 <>
        struct
          Flags USHORT ?
          MappedPort USHORT ?
          MappedAddress IN_ADDR <>
          LocalAddress IN_ADDR <>
          InterfaceIndex IF_INDEX ?
          LocalPort USHORT ?
          DlDestination DL_EUI48 <>
        ends
      ends
    DL_TEREDO_ADDRESS_PRV ends
    PDL_TEREDO_ADDRESS_PRV typedef ptr DL_TEREDO_ADDRESS_PRV
    
    IPTLS_METADATA struct
      SequenceNumber ULONGLONG ?
    IPTLS_METADATA ends
    _IPTLS_METADATA typedef IPTLS_METADATA
    PIPTLS_METADATA typedef ptr IPTLS_METADATA
    
;    include ifdef.inc
    NPI_MODULEID_TYPE typedef SDWORD
    MIT_GUID equ 1
    MIT_IF_LUID equ 2
    _NPI_MODULEID_TYPE typedef NPI_MODULEID_TYPE
    
    NPI_MODULEID struct
      Length_ USHORT ?
      Type_ NPI_MODULEID_TYPE ?
      ifdef __midl
        ;[...]
      endif
      union
        ifdef __midl
          ;[...]
        endif
        Guid GUID <>
        ifdef __midl
          ;[...]
        endif
        IfLuid LUID <>
        ifdef __midl
          ;[...]
        endif
      ends
    NPI_MODULEID ends
    _NPI_MODULEID typedef NPI_MODULEID
    PNPI_MODULEID typedef ptr NPI_MODULEID
    ifndef __midl
      NmrIsEqualNpiModuleId proto WIN_STD_CALL_CONV :PNPI_MODULEID, :PNPI_MODULEID
      ifdef __cplusplus
        ;[...]
      else
      endif
    endif
    NPIID typedef GUID
    PNPIID typedef ptr NPIID
    externdef NPI_MS_NMR_MODULEID:NPI_MODULEID
    FL_PACKET_TYPE_FLAGS equ <(NDIS_PACKET_TYPE_ALL_MULTICAST or NDIS_PACKET_TYPE_PROMISCUOUS or NDIS_PACKET_TYPE_NO_LOCAL)>
    externdef NPI_FRAMING_LAYER_ID:NPIID
    externdef NPI_MS_TUN_MODULEID:NPI_MODULEID
    externdef NPI_MS_FL48_MODULEID:NPI_MODULEID
    externdef NPI_MS_FL68_MODULEID:NPI_MODULEID
    externdef NPI_MS_FL4L_MODULEID:NPI_MODULEID
    externdef NPI_MS_FL6L_MODULEID:NPI_MODULEID
    externdef NPI_MS_FL4T_MODULEID:NPI_MODULEID
    externdef NPI_MS_FL6T_MODULEID:NPI_MODULEID
    externdef NPI_MS_WANARPV4_MODULEID:NPI_MODULEID
    externdef NPI_MS_WANARPV6_MODULEID:NPI_MODULEID
    externdef NPI_MS_FL_WANARP_MODULEID:NPI_MODULEID
    externdef NPI_MS_FLRDMA_MODULEID:NPI_MODULEID
    externdef NPI_MS_NDIS_MODULEID:NPI_MODULEID
    externdef NPI_NETWORK_LAYER_ID:NPIID
    externdef NPI_MS_IPV6_MODULEID:NPI_MODULEID
    externdef NPI_MS_IPV4_MODULEID:NPI_MODULEID
    FALLBACK_INDEX typedef SDWORD
    FallbackIndexTcpFastopen equ 0
    FallbackIndexMax equ 1
    
    ifdef NETIODEF_DEFINED_ASSERT
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
 