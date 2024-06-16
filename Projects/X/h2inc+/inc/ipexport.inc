;Include file created by h2inc+ version C.2.0 on (UTC) 15/06/2024 16:37:44
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\ipexport.h
;             Created on (UTC) 06/04/2024 06:15:56
;             Last modified on (UTC) 12/02/2024 17:05:30

ifndef IP_EXPORT_INCLUDED
  IP_EXPORT_INCLUDED equ 1
  if _MSC_VER gt 1000
  endif
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    IPAddr typedef ULONG
    IPMask typedef ULONG
    IP_STATUS typedef ULONG
    include in6addr.inc
    IPv6Addr typedef in6_addr
    include inaddr.inc
    IP_OPTION_INFORMATION struct
      Ttl UCHAR ?
      Tos UCHAR ?
      Flags UCHAR ?
      OptionsSize UCHAR ?
      OptionsData PUCHAR ?
    IP_OPTION_INFORMATION ends
    ip_option_information typedef IP_OPTION_INFORMATION
    PIP_OPTION_INFORMATION typedef ptr IP_OPTION_INFORMATION
    if Defined(_WIN64)
      IP_OPTION_INFORMATION32 struct
        Ttl UCHAR ?
        Tos UCHAR ?
        Flags UCHAR ?
        OptionsSize UCHAR ?
        OptionsData POINTER ?
      IP_OPTION_INFORMATION32 ends
      ip_option_information32 typedef IP_OPTION_INFORMATION32
      PIP_OPTION_INFORMATION32 typedef ptr IP_OPTION_INFORMATION32
    endif
    ICMP_ECHO_REPLY struct
      Address IPAddr ?
      Status ULONG ?
      RoundTripTime ULONG ?
      DataSize USHORT ?
      Reserved USHORT ?
      Data PVOID ?
      Options ip_option_information ?
    ICMP_ECHO_REPLY ends
    icmp_echo_reply typedef ICMP_ECHO_REPLY
    PICMP_ECHO_REPLY typedef ptr ICMP_ECHO_REPLY
    if Defined(_WIN64)
      ICMP_ECHO_REPLY32 struct
        Address IPAddr ?
        Status ULONG ?
        RoundTripTime ULONG ?
        DataSize USHORT ?
        Reserved USHORT ?
        Data POINTER ?
        Options ip_option_information32 ?
      ICMP_ECHO_REPLY32 ends
      icmp_echo_reply32 typedef ICMP_ECHO_REPLY32
      PICMP_ECHO_REPLY32 typedef ptr ICMP_ECHO_REPLY32
    endif
    if (NTDDI_VERSION ge NTDDI_WINXP)
      include pshpack1.inc
      IPV6_ADDRESS_EX struct
        sin6_port USHORT ?
        sin6_flowinfo ULONG ?
        sin6_addr USHORT 8 dup (?)
        sin6_scope_id ULONG ?
      IPV6_ADDRESS_EX ends
      _IPV6_ADDRESS_EX typedef IPV6_ADDRESS_EX
      PIPV6_ADDRESS_EX typedef ptr IPV6_ADDRESS_EX
      include poppack.inc
      ICMPV6_ECHO_REPLY_LH struct
        Address IPV6_ADDRESS_EX <>
        Status ULONG ?
        RoundTripTime DWORD ?
      ICMPV6_ECHO_REPLY_LH ends
      icmpv6_echo_reply_lh typedef ICMPV6_ECHO_REPLY_LH
      PICMPV6_ECHO_REPLY_LH typedef ptr ICMPV6_ECHO_REPLY_LH
      ICMPV6_ECHO_REPLY typedef ICMPV6_ECHO_REPLY_LH
      PICMPV6_ECHO_REPLY typedef ptr ICMPV6_ECHO_REPLY_LH
    endif
    ARP_SEND_REPLY struct
      DestAddress IPAddr ?
      SrcAddress IPAddr ?
    ARP_SEND_REPLY ends
    arp_send_reply typedef ARP_SEND_REPLY
    PARP_SEND_REPLY typedef ptr ARP_SEND_REPLY
    TCP_RESERVE_PORT_RANGE struct
      UpperRange USHORT ?
      LowerRange USHORT ?
    TCP_RESERVE_PORT_RANGE ends
    tcp_reserve_port_range typedef TCP_RESERVE_PORT_RANGE
    PTCP_RESERVE_PORT_RANGE typedef ptr TCP_RESERVE_PORT_RANGE
    MAX_ADAPTER_NAME equ 128
    IP_ADAPTER_INDEX_MAP struct
      Index ULONG ?
      Name_ WCHAR MAX_ADAPTER_NAME dup (?)
    IP_ADAPTER_INDEX_MAP ends
    _IP_ADAPTER_INDEX_MAP typedef IP_ADAPTER_INDEX_MAP
    PIP_ADAPTER_INDEX_MAP typedef ptr IP_ADAPTER_INDEX_MAP
    IP_INTERFACE_INFO struct
      NumAdapters LONG ?
      Adapter IP_ADAPTER_INDEX_MAP 1 dup (<>)
    IP_INTERFACE_INFO ends
    _IP_INTERFACE_INFO typedef IP_INTERFACE_INFO
    PIP_INTERFACE_INFO typedef ptr IP_INTERFACE_INFO
    IP_UNIDIRECTIONAL_ADAPTER_ADDRESS struct
      NumAdapters ULONG ?
      Address IPAddr 1 dup (?)
    IP_UNIDIRECTIONAL_ADAPTER_ADDRESS ends
    _IP_UNIDIRECTIONAL_ADAPTER_ADDRESS typedef IP_UNIDIRECTIONAL_ADAPTER_ADDRESS
    PIP_UNIDIRECTIONAL_ADAPTER_ADDRESS typedef ptr IP_UNIDIRECTIONAL_ADAPTER_ADDRESS
    IP_ADAPTER_ORDER_MAP struct
      NumAdapters ULONG ?
      AdapterOrder ULONG 1 dup (?)
    IP_ADAPTER_ORDER_MAP ends
    _IP_ADAPTER_ORDER_MAP typedef IP_ADAPTER_ORDER_MAP
    PIP_ADAPTER_ORDER_MAP typedef ptr IP_ADAPTER_ORDER_MAP
    IP_MCAST_COUNTER_INFO struct
      InMcastOctets ULONG64 ?
      OutMcastOctets ULONG64 ?
      InMcastPkts ULONG64 ?
      OutMcastPkts ULONG64 ?
    IP_MCAST_COUNTER_INFO ends
    _IP_MCAST_COUNTER_INFO typedef IP_MCAST_COUNTER_INFO
    PIP_MCAST_COUNTER_INFO typedef ptr IP_MCAST_COUNTER_INFO
    IP_STATUS_BASE equ 11000
    IP_SUCCESS equ 0
    IP_BUF_TOO_SMALL equ (IP_STATUS_BASE + 1)
    IP_DEST_NET_UNREACHABLE equ (IP_STATUS_BASE + 2)
    IP_DEST_HOST_UNREACHABLE equ (IP_STATUS_BASE + 3)
    IP_DEST_PROT_UNREACHABLE equ (IP_STATUS_BASE + 4)
    IP_DEST_PORT_UNREACHABLE equ (IP_STATUS_BASE + 5)
    IP_NO_RESOURCES equ (IP_STATUS_BASE + 6)
    IP_BAD_OPTION equ (IP_STATUS_BASE + 7)
    IP_HW_ERROR equ (IP_STATUS_BASE + 8)
    IP_PACKET_TOO_BIG equ (IP_STATUS_BASE + 9)
    IP_REQ_TIMED_OUT equ (IP_STATUS_BASE + 10)
    IP_BAD_REQ equ (IP_STATUS_BASE + 11)
    IP_BAD_ROUTE equ (IP_STATUS_BASE + 12)
    IP_TTL_EXPIRED_TRANSIT equ (IP_STATUS_BASE + 13)
    IP_TTL_EXPIRED_REASSEM equ (IP_STATUS_BASE + 14)
    IP_PARAM_PROBLEM equ (IP_STATUS_BASE + 15)
    IP_SOURCE_QUENCH equ (IP_STATUS_BASE + 16)
    IP_OPTION_TOO_BIG equ (IP_STATUS_BASE + 17)
    IP_BAD_DESTINATION equ (IP_STATUS_BASE + 18)
    IP_DEST_NO_ROUTE equ (IP_STATUS_BASE + 2)
    IP_DEST_ADDR_UNREACHABLE equ (IP_STATUS_BASE + 3)
    IP_DEST_PROHIBITED equ (IP_STATUS_BASE + 4)
    IP_DEST_PORT_UNREACHABLE equ (IP_STATUS_BASE + 5)
    IP_HOP_LIMIT_EXCEEDED equ (IP_STATUS_BASE + 13)
    IP_REASSEMBLY_TIME_EXCEEDED equ (IP_STATUS_BASE + 14)
    IP_PARAMETER_PROBLEM equ (IP_STATUS_BASE + 15)
    IP_DEST_UNREACHABLE equ (IP_STATUS_BASE + 40)
    IP_TIME_EXCEEDED equ (IP_STATUS_BASE + 41)
    IP_BAD_HEADER equ (IP_STATUS_BASE + 42)
    IP_UNRECOGNIZED_NEXT_HEADER equ (IP_STATUS_BASE + 43)
    IP_ICMP_ERROR equ (IP_STATUS_BASE + 44)
    IP_DEST_SCOPE_MISMATCH equ (IP_STATUS_BASE + 45)
    IP_ADDR_DELETED equ (IP_STATUS_BASE + 19)
    IP_SPEC_MTU_CHANGE equ (IP_STATUS_BASE + 20)
    IP_MTU_CHANGE equ (IP_STATUS_BASE + 21)
    IP_UNLOAD equ (IP_STATUS_BASE + 22)
    IP_ADDR_ADDED equ (IP_STATUS_BASE + 23)
    IP_MEDIA_CONNECT equ (IP_STATUS_BASE + 24)
    IP_MEDIA_DISCONNECT equ (IP_STATUS_BASE + 25)
    IP_BIND_ADAPTER equ (IP_STATUS_BASE + 26)
    IP_UNBIND_ADAPTER equ (IP_STATUS_BASE + 27)
    IP_DEVICE_DOES_NOT_EXIST equ (IP_STATUS_BASE + 28)
    IP_DUPLICATE_ADDRESS equ (IP_STATUS_BASE + 29)
    IP_INTERFACE_METRIC_CHANGE equ (IP_STATUS_BASE + 30)
    IP_RECONFIG_SECFLTR equ (IP_STATUS_BASE + 31)
    IP_NEGOTIATING_IPSEC equ (IP_STATUS_BASE + 32)
    IP_INTERFACE_WOL_CAPABILITY_CHANGE equ (IP_STATUS_BASE + 33)
    IP_DUPLICATE_IPADD equ (IP_STATUS_BASE + 34)
    IP_GENERAL_FAILURE equ (IP_STATUS_BASE + 50)
    MAX_IP_STATUS equ <IP_GENERAL_FAILURE>
    IP_PENDING equ (IP_STATUS_BASE + 255)
    IP_FLAG_REVERSE equ 1h
    IP_FLAG_DF equ 2h
    IP_OPT_EOL equ 0
    IP_OPT_NOP equ 1
    IP_OPT_SECURITY equ 82h
    IP_OPT_LSRR equ 83h
    IP_OPT_SSRR equ 89h
    IP_OPT_RR equ 7h
    IP_OPT_TS equ 44h
    IP_OPT_SID equ 88h
    IP_OPT_ROUTER_ALERT equ 94h
    MAX_OPT_SIZE equ 40
    ifdef CHICAGO
      IOCTL_IP_RTCHANGE_NOTIFY_REQUEST equ 101
      IOCTL_IP_ADDCHANGE_NOTIFY_REQUEST equ 102
      IOCTL_ARP_SEND_REQUEST equ 103
      IOCTL_IP_INTERFACE_INFO equ 104
      IOCTL_IP_GET_BEST_INTERFACE equ 105
      IOCTL_IP_UNIDIRECTIONAL_ADAPTER_ADDRESS equ 106
    endif
  endif
endif
