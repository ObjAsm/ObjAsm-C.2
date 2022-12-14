;Include file created by h2incX, Version C.01.00, 07/01/2023 17:53
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'C:\Program Files (x86)\Windows Kits\10\Include\10.0.22621.0\shared\ip2string.h', last modified: 13/10/2022 20:07

ifndef __IP2STRING__
  __IP2STRING__ equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    ifdef __cplusplus
      ;[...]
    endif

    ;Copied from netiodef.inc --------
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
    ;---------------------------------

    DL_EUI48 typedef _DL_EUI48
    PDL_EUI48 typedef ptr _DL_EUI48
    
    @DefProto DllImport, RtlIpv4AddressToStringA, WIN_STD_CALL_CONV,, <:ptr in_addr, :PSTR>, 8
    @DefProto DllImport, RtlIpv6AddressToStringA, WIN_STD_CALL_CONV,, <:ptr in6_addr, :PSTR>, 8
    @DefProto DllImport, RtlEthernetAddressToStringA, WIN_STD_CALL_CONV,, <:ptr DL_EUI48, :PSTR>, 8
    @DefProto DllImport, RtlIpv4AddressToStringExA, WIN_STD_CALL_CONV,, <:ptr in_addr, :USHORT, :PSTR, :PULONG>, 16
    @DefProto DllImport, RtlIpv6AddressToStringExA, WIN_STD_CALL_CONV,, <:ptr in6_addr, :ULONG, :USHORT, :PSTR, :PULONG>, 20
    @DefProto DllImport, RtlIpv4AddressToStringW, WIN_STD_CALL_CONV,, <:ptr in_addr, :PWSTR>, 8
    @DefProto DllImport, RtlIpv6AddressToStringW, WIN_STD_CALL_CONV,, <:ptr in6_addr, :PWSTR>, 8
    @DefProto DllImport, RtlEthernetAddressToStringW, WIN_STD_CALL_CONV,, <:ptr DL_EUI48, :PWSTR>, 8
    @DefProto DllImport, RtlIpv4AddressToStringExW, WIN_STD_CALL_CONV,, <:ptr in_addr, :USHORT, :PWSTR, :PULONG>, 16
    @DefProto DllImport, RtlIpv6AddressToStringExW, WIN_STD_CALL_CONV,, <:ptr in6_addr, :ULONG, :USHORT, :PWSTR, :PULONG>, 20
    @DefProto DllImport, RtlIpv4StringToAddressA, WIN_STD_CALL_CONV,, <:PCSTR, :BOOLEAN, :ptr PCSTR, :ptr in_addr>, 16
    @DefProto DllImport, RtlIpv6StringToAddressA, WIN_STD_CALL_CONV,, <:PCSTR, :ptr PCSTR, :ptr in6_addr>, 12
    @DefProto DllImport, RtlEthernetStringToAddressA, WIN_STD_CALL_CONV,, <:PCSTR, :ptr PCSTR, :ptr DL_EUI48>, 12
    @DefProto DllImport, RtlIpv4StringToAddressExA, WIN_STD_CALL_CONV,, <:PCSTR, :BOOLEAN, :ptr in_addr, :PUSHORT>, 16
    @DefProto DllImport, RtlIpv6StringToAddressExA, WIN_STD_CALL_CONV,, <:PCSTR, :ptr in6_addr, :PULONG, :PUSHORT>, 16
    @DefProto DllImport, RtlIpv4StringToAddressW, WIN_STD_CALL_CONV,, <:PCWSTR, :BOOLEAN, :ptr LPCWSTR, :ptr in_addr>, 16
    @DefProto DllImport, RtlIpv6StringToAddressW, WIN_STD_CALL_CONV,, <:PCWSTR, :ptr PCWSTR, :ptr in6_addr>, 12
    @DefProto DllImport, RtlEthernetStringToAddressW, WIN_STD_CALL_CONV,, <:PCWSTR, :ptr LPCWSTR, :ptr DL_EUI48>, 12
    @DefProto DllImport, RtlIpv4StringToAddressExW, WIN_STD_CALL_CONV,, <:PCWSTR, :BOOLEAN, :ptr in_addr, :PUSHORT>, 16
    @DefProto DllImport, RtlIpv6StringToAddressExW, WIN_STD_CALL_CONV,, <:PCWSTR, :ptr in6_addr, :PULONG, :PUSHORT>, 16
    ifdef UNICODE
      RtlIpv4AddressToString equ <RtlIpv4AddressToStringW>
      RtlIpv6AddressToString equ <RtlIpv6AddressToStringW>
      RtlEthernetAddressToString equ <RtlEthernetAddressToStringW>
      RtlIpv4StringToAddress equ <RtlIpv4StringToAddressW>
      RtlIpv6StringToAddress equ <RtlIpv6StringToAddressW>
      RtlEthernetStringToAddress equ <RtlEthernetStringToAddressW>
      RtlIpv6StringToAddressEx equ <RtlIpv6StringToAddressExW>
      RtlIpv4AddressToStringEx equ <RtlIpv4AddressToStringExW>
      RtlIpv6AddressToStringEx equ <RtlIpv6AddressToStringExW>
      RtlIpv4StringToAddressEx equ <RtlIpv4StringToAddressExW>
    else
      RtlIpv4AddressToString equ <RtlIpv4AddressToStringA>
      RtlIpv6AddressToString equ <RtlIpv6AddressToStringA>
      RtlEthernetAddressToString equ <RtlEthernetAddressToStringA>
      RtlIpv4StringToAddress equ <RtlIpv4StringToAddressA>
      RtlIpv6StringToAddress equ <RtlIpv6StringToAddressA>
      RtlEthernetStringToAddress equ <RtlEthernetStringToAddressA>
      RtlIpv6StringToAddressEx equ <RtlIpv6StringToAddressExA>
      RtlIpv4AddressToStringEx equ <RtlIpv4AddressToStringExA>
      RtlIpv6AddressToStringEx equ <RtlIpv6AddressToStringExA>
      RtlIpv4StringToAddressEx equ <RtlIpv4StringToAddressExA>
    endif
    ifdef __cplusplus
      ;[...]
    endif
  endif
endif
 