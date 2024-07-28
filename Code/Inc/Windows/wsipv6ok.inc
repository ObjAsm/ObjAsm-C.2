;Include file created by h2incX, Version B.01.01, 26/11/2018 23:24
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'D:\MASM32\ObjAsm\Projects\h2IncX\header\wsipv6ok.h', last modified: 19/04/2018 09:43
;Creation parameters: 

ifndef _WSIPV6OK_
  _WSIPV6OK_ equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifdef IPV6STRICT
      include ws2tcpip.inc
      include wspiapi.inc
      AF_INET equ <AF_INET_IPV6INCOMPATIBLE>
      PF_INET equ <PF_INET_IPV6INCOMPATIBLE>
      in_addr equ <in_addr_IPV6INCOMPATIBLE>
      IN_ADDR equ <IN_ADDR_IPV6INCOMPATIBLE>
      PIN_ADDR equ <PIN_ADDR_IPV6INCOMPATIBLE>
      LPIN_ADDR equ <LPIN_ADDR_IPV6INCOMPATIBLE>
      IPAddr equ <IPAddr_IPV6INCOMPATIBLE>
      sockaddr_in equ <sockaddr_in_IPV6INCOMPATIBLE>
      SOCKADDR_IN equ <SOCKADDR_IN_IPV6INCOMPATIBLE>
      PSOCKADDR_IN equ <PSOCKADDR_IN_IPV6INCOMPATIBLE>
      LPSOCKADDR_IN equ <LPSOCKADDR_IN_IPV6INCOMPATIBLE>
      INADDR_ANY equ <INADDR_ANY_IPV6INCOMPATIBLE>
      INADDR_LOOPBACK equ <INADDR_LOOPBACK_IPV6INCOMPATIBLE>
      IPPROTO_IP equ <IPPROTO_IP_IPV6INCOMPATIBLE>
      IP_MULTICAST_IF equ <IP_MULTICAST_IF_IPV6INCOMPATIBLE>
      IP_MULTICAST_TTL equ <IP_MULTICAST_TTL_IPV6INCOMPATIBLE>
      IP_MULTICAST_LOOP equ <IP_MULTICAST_LOOP_IPV6INCOMPATIBLE>
      IP_ADD_MEMBERSHIP equ <IP_ADD_MEMBERSHIP_IPV6INCOMPATIBLE>
      IP_DROP_MEMBERSHIP equ <IP_DROP_MEMBERSHIP_IPV6INCOMPATIBLE>
      ip_mreq equ <ip_mreq_IPV6INCOMPATIBLE>
      gethostbyname macro a
        exitm <gethostbyname_IPV6INCOMPATIBLE>
      endm
      hostent equ <hostent_IPV6INCOMPATIBLE>
      HOSTENT equ <HOSTENT_IPV6INCOMPATIBLE>
      PHOSTENT equ <PHOSTENT_IPV6INCOMPATIBLE>
      LPHOSTENT equ <LPHOSTENT_IPV6INCOMPATIBLE>
      inet_addr macro a
        exitm <inet_addr_IPV6INCOMPATIBLE>
      endm
      gethostbyaddr macro a, b, c_
        exitm <gethostbyaddr_IPV6INCOMPATIBLE>
      endm
      inet_ntoa macro a
        exitm <inet_ntoa_IPV6INCOMPATIBLE>
      endm
      IN_MULTICAST macro a
        exitm <IN_MULTICAST_IPV6INCOMPATIBLE>
      endm
      IN_CLASSD macro a
        exitm <IN_CLASSD_IPV6INCOMPATIBLE>
      endm
      IP_TTL equ <IP_TTL_IPV6INCOMPATIBLE>
      IN_CLASSA macro a
        exitm <IN_CLASSA_IPV6INCOMPATIBLE>
      endm
      IN_CLASSB macro a
        exitm <IN_CLASSB_IPV6INCOMPATIBLE>
      endm
      IN_CLASSC macro a
        exitm <IN_CLASSC_IPV6INCOMPATIBLE>
      endm
      INADDR_BROADCAST macro a
        exitm <INADDR_BROADCAST_IPV6INCOMPATIBLE>
      endm
      WSAAsyncGetHostByAddr macro a, b, c_, d, e, f, g
        exitm <WSAAsyncGetHostByAddr_IPV6INCOMPATIBLE>
      endm
      WSAAsyncGetHostByName macro a, b, c_, d, e
        exitm <WSAAsyncGetHostByName_IPV6INCOMPATIBLE>
      endm
    endif
  endif
endif

