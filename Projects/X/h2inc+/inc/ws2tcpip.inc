;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\ws2tcpip.h
;             Created on (UTC) 06/04/2024 06:16:03
;             Last modified on (UTC) 12/02/2024 17:05:30

ifndef _WS2TCPIP_H_
  _WS2TCPIP_H_ equ <>
  if _MSC_VER gt 1000
  endif
  include winapifamily.inc
  if _MSC_VER ge 1200
  endif
  if  not Defined(_WINSOCK_DEPRECATED_BY)
    if ((Defined(_WINSOCK_DEPRECATED_NO_WARNINGS) or Defined(BUILD_WINDOWS)) and  not Defined(_WINSOCK_DEPRECATE_WARNINGS)) or Defined(MIDL_PASS)
      _WINSOCK_DEPRECATED_BY macro replacement
        exitm <>
      endm
    else
      _WINSOCK_DEPRECATED_BY macro replacement
        exitm <__declspec(deprecated ("Use " replacement " instead or define _WINSOCK_DEPRECATED_NO_WARNINGS to disable deprecated API warnings"))>
      endm
    endif
  endif
  include winsock2.inc
  include ws2ipdef.inc
  include limits.inc
  ifdef _PREFAST_
    ;[...]
  endif
  UDP_NOCHECKSUM equ 1
  UDP_CHECKSUM_COVERAGE equ 20
  ifdef _MSC_VER
    WS2TCPIP_INLINE equ <__inline>
  else
    WS2TCPIP_INLINE equ <extern inline>
  endif
  EAI_AGAIN equ <WSATRY_AGAIN>
  EAI_BADFLAGS equ <WSAEINVAL>
  EAI_FAIL equ <WSANO_RECOVERY>
  EAI_FAMILY equ <WSAEAFNOSUPPORT>
  EAI_MEMORY equ <WSA_NOT_ENOUGH_MEMORY>
  EAI_NOSECURENAME equ <WSA_SECURE_HOST_NOT_FOUND>
  EAI_NONAME equ <WSAHOST_NOT_FOUND>
  EAI_SERVICE equ <WSATYPE_NOT_FOUND>
  EAI_SOCKTYPE equ <WSAESOCKTNOSUPPORT>
  EAI_IPSECPOLICY equ <WSA_IPSEC_NAME_POLICY_ERROR>
  EAI_NODATA equ <EAI_NONAME>
  ifdef UNICODE
    ADDRINFOT typedef ADDRINFOW
    PADDRINFOT typedef ptr ADDRINFOW
  else
    ADDRINFOT typedef ADDRINFOA
    PADDRINFOT typedef ptr ADDRINFOA
  endif
  ADDRINFO typedef ADDRINFOA
  LPADDRINFO typedef ptr ADDRINFOA
  if (_WIN32_WINNT ge 0600h)
    ifdef UNICODE
      ADDRINFOEX typedef ADDRINFOEXW
      PADDRINFOEX typedef ptr ADDRINFOEXW
    else
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        ADDRINFOEX typedef ADDRINFOEXA
        PADDRINFOEX typedef ptr ADDRINFOEXA
      endif
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
  @DefProto DllImport, getaddrinfo, WIN_STD_CALL_CONV,, <:PCSTR, :PCSTR, :ptr ADDRINFOA, :ptr PADDRINFOA>, 16
  if (NTDDI_VERSION ge NTDDI_WINXPSP2) or (_WIN32_WINNT ge 0502h)
    @DefProto DllImport, GetAddrInfoW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR, :ptr ADDRINFOW, :ptr PADDRINFOW>, 16
    GetAddrInfoA equ <getaddrinfo>
    ifdef UNICODE
      GetAddrInfo equ <GetAddrInfoW>
    else
      GetAddrInfo equ <GetAddrInfoA>
    endif
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_GETADDRINFO typedef proto WIN_STD_CALL_CONV :PCSTR, :PCSTR, :ptr ADDRINFOA, :ptr PADDRINFOA
    LPFN_GETADDRINFO typedef ptr TYPE_LPFN_GETADDRINFO

    TYPE_LPFN_GETADDRINFOW typedef proto WIN_STD_CALL_CONV :PCWSTR, :PCWSTR, :ptr ADDRINFOW, :ptr PADDRINFOW
    LPFN_GETADDRINFOW typedef ptr TYPE_LPFN_GETADDRINFOW

    LPFN_GETADDRINFOA equ <LPFN_GETADDRINFO>
    ifdef UNICODE
      LPFN_GETADDRINFOT equ <LPFN_GETADDRINFOW>
    else
      LPFN_GETADDRINFOT equ <LPFN_GETADDRINFOA>
    endif
  endif
  if (_WIN32_WINNT ge 0600h)
    TYPE_LPLOOKUPSERVICE_COMPLETION_ROUTINE typedef proto WIN_STD_CALL_CONV :DWORD, :DWORD, :LPWSAOVERLAPPED
    LPLOOKUPSERVICE_COMPLETION_ROUTINE typedef ptr TYPE_LPLOOKUPSERVICE_COMPLETION_ROUTINE

    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      _WINSOCK_DEPRECATED_BY("GetAddrInfoExW()")
      @DefProto DllImport, GetAddrInfoExA, WIN_STD_CALL_CONV,, <:PCSTR, :PCSTR, :DWORD, :LPGUID, :ptr ADDRINFOEXA, :ptr PADDRINFOEXA, :ptr timeval, :LPOVERLAPPED, :LPLOOKUPSERVICE_COMPLETION_ROUTINE, :LPHANDLE>, 40
    endif
    @DefProto DllImport, GetAddrInfoExW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR, :DWORD, :LPGUID, :ptr ADDRINFOEXW, :ptr PADDRINFOEXW, :ptr timeval, :LPOVERLAPPED, :LPLOOKUPSERVICE_COMPLETION_ROUTINE, :LPHANDLE>, 40
    @DefProto DllImport, GetAddrInfoExCancel, WIN_STD_CALL_CONV,, <:LPHANDLE>, 4
    @DefProto DllImport, GetAddrInfoExOverlappedResult, WIN_STD_CALL_CONV,, <:LPOVERLAPPED>, 4
    ifdef UNICODE
      GetAddrInfoEx equ <GetAddrInfoExW>
    else
      GetAddrInfoEx equ <GetAddrInfoExA>
    endif
    if INCL_WINSOCK_API_TYPEDEFS
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
        TYPE_LPFN_GETADDRINFOEXA typedef proto WIN_STD_CALL_CONV :PCSTR, :PCSTR, :DWORD, :LPGUID, :ptr ADDRINFOEXA, :ptr PADDRINFOEXA, :ptr timeval, :LPOVERLAPPED, :LPLOOKUPSERVICE_COMPLETION_ROUTINE, :LPHANDLE
        LPFN_GETADDRINFOEXA typedef ptr TYPE_LPFN_GETADDRINFOEXA

      endif
      TYPE_LPFN_GETADDRINFOEXW typedef proto WIN_STD_CALL_CONV :PCWSTR, :PCWSTR, :DWORD, :LPGUID, :ptr ADDRINFOEXW, :ptr PADDRINFOEXW, :ptr timeval, :LPOVERLAPPED, :LPLOOKUPSERVICE_COMPLETION_ROUTINE, :LPHANDLE
      LPFN_GETADDRINFOEXW typedef ptr TYPE_LPFN_GETADDRINFOEXW

      TYPE_LPFN_GETADDRINFOEXCANCEL typedef proto WIN_STD_CALL_CONV :LPHANDLE
      LPFN_GETADDRINFOEXCANCEL typedef ptr TYPE_LPFN_GETADDRINFOEXCANCEL

      TYPE_LPFN_GETADDRINFOEXOVERLAPPEDRESULT typedef proto WIN_STD_CALL_CONV :LPOVERLAPPED
      LPFN_GETADDRINFOEXOVERLAPPEDRESULT typedef ptr TYPE_LPFN_GETADDRINFOEXOVERLAPPEDRESULT

      ifdef UNICODE
        LPFN_GETADDRINFOEX equ <LPFN_GETADDRINFOEXW>
      else
        LPFN_GETADDRINFOEX equ <LPFN_GETADDRINFOEXA>
      endif
    endif
  endif
  if (_WIN32_WINNT ge 0600h)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      _WINSOCK_DEPRECATED_BY("SetAddrInfoExW()")
      @DefProto DllImport, SetAddrInfoExA, WIN_STD_CALL_CONV,, <:PCSTR, :PCSTR, :ptr SOCKET_ADDRESS, :DWORD, :LPBLOB, :DWORD, :DWORD, :LPGUID, :ptr timeval, :LPOVERLAPPED, :LPLOOKUPSERVICE_COMPLETION_ROUTINE, :LPHANDLE>, 48
    endif
    @DefProto DllImport, SetAddrInfoExW, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR, :ptr SOCKET_ADDRESS, :DWORD, :LPBLOB, :DWORD, :DWORD, :LPGUID, :ptr timeval, :LPOVERLAPPED, :LPLOOKUPSERVICE_COMPLETION_ROUTINE, :LPHANDLE>, 48
    ifdef UNICODE
      SetAddrInfoEx equ <SetAddrInfoExW>
    else
      SetAddrInfoEx equ <SetAddrInfoExA>
    endif
    if INCL_WINSOCK_API_TYPEDEFS
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        TYPE_LPFN_SETADDRINFOEXA typedef proto WIN_STD_CALL_CONV :PCSTR, :PCSTR, :ptr SOCKET_ADDRESS, :DWORD, :LPBLOB, :DWORD, :DWORD, :LPGUID, :ptr timeval, :LPOVERLAPPED, :LPLOOKUPSERVICE_COMPLETION_ROUTINE, :LPHANDLE
        LPFN_SETADDRINFOEXA typedef ptr TYPE_LPFN_SETADDRINFOEXA

      endif
      TYPE_LPFN_SETADDRINFOEXW typedef proto WIN_STD_CALL_CONV :PCWSTR, :PCWSTR, :ptr SOCKET_ADDRESS, :DWORD, :LPBLOB, :DWORD, :DWORD, :LPGUID, :ptr timeval, :LPOVERLAPPED, :LPLOOKUPSERVICE_COMPLETION_ROUTINE, :LPHANDLE
      LPFN_SETADDRINFOEXW typedef ptr TYPE_LPFN_SETADDRINFOEXW

      ifdef UNICODE
        LPFN_SETADDRINFOEX equ <LPFN_SETADDRINFOEXW>
      else
        LPFN_SETADDRINFOEX equ <LPFN_SETADDRINFOEXA>
      endif
    endif
  endif
  @DefProto DllImport, freeaddrinfo, WIN_STD_CALL_CONV,, <:PADDRINFOA>, 4
  if (NTDDI_VERSION ge NTDDI_WINXPSP2) or (_WIN32_WINNT ge 0502h)
    @DefProto DllImport, FreeAddrInfoW, WIN_STD_CALL_CONV,, <:PADDRINFOW>, 4
    FreeAddrInfoA equ <freeaddrinfo>
    ifdef UNICODE
      FreeAddrInfo equ <FreeAddrInfoW>
    else
      FreeAddrInfo equ <FreeAddrInfoA>
    endif
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_FREEADDRINFO typedef proto WIN_STD_CALL_CONV :PADDRINFOA
    LPFN_FREEADDRINFO typedef ptr TYPE_LPFN_FREEADDRINFO

    TYPE_LPFN_FREEADDRINFOW typedef proto WIN_STD_CALL_CONV :PADDRINFOW
    LPFN_FREEADDRINFOW typedef ptr TYPE_LPFN_FREEADDRINFOW

    LPFN_FREEADDRINFOA equ <LPFN_FREEADDRINFO>
    ifdef UNICODE
      LPFN_FREEADDRINFOT equ <LPFN_FREEADDRINFOW>
    else
      LPFN_FREEADDRINFOT equ <LPFN_FREEADDRINFOA>
    endif
  endif
  if (_WIN32_WINNT ge 0600h)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      _WINSOCK_DEPRECATED_BY("FreeAddrInfoExW()")
      @DefProto DllImport, FreeAddrInfoEx, WIN_STD_CALL_CONV,, <:PADDRINFOEXA>, 4
    endif
    @DefProto DllImport, FreeAddrInfoExW, WIN_STD_CALL_CONV,, <:PADDRINFOEXW>, 4
    FreeAddrInfoExA equ <FreeAddrInfoEx>
    ifdef UNICODE
      FreeAddrInfoEx equ <FreeAddrInfoExW>
    endif
    if INCL_WINSOCK_API_TYPEDEFS
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
        TYPE_LPFN_FREEADDRINFOEXA typedef proto WIN_STD_CALL_CONV :PADDRINFOEXA
        LPFN_FREEADDRINFOEXA typedef ptr TYPE_LPFN_FREEADDRINFOEXA

      endif
      TYPE_LPFN_FREEADDRINFOEXW typedef proto WIN_STD_CALL_CONV :PADDRINFOEXW
      LPFN_FREEADDRINFOEXW typedef ptr TYPE_LPFN_FREEADDRINFOEXW

      ifdef UNICODE
        LPFN_FREEADDRINFOEX equ <LPFN_FREEADDRINFOEXW>
      else
        LPFN_FREEADDRINFOEX equ <LPFN_FREEADDRINFOEXA>
      endif
    endif
  endif
  socklen_t typedef SDWORD
  @DefProto DllImport, getnameinfo, WIN_STD_CALL_CONV,, <:ptr SOCKADDR, :socklen_t, :PCHAR, :DWORD, :PCHAR, :DWORD, :INT_>, 28
  if (NTDDI_VERSION ge NTDDI_WINXPSP2) or (_WIN32_WINNT ge 0502h)
    @DefProto DllImport, GetNameInfoW, WIN_STD_CALL_CONV,, <:ptr SOCKADDR, :socklen_t, :PWCHAR, :DWORD, :PWCHAR, :DWORD, :INT_>, 28
    GetNameInfoA equ <getnameinfo>
    ifdef UNICODE
      GetNameInfo equ <GetNameInfoW>
    else
      GetNameInfo equ <GetNameInfoA>
    endif
  endif
  if INCL_WINSOCK_API_TYPEDEFS
    TYPE_LPFN_GETNAMEINFO typedef proto WIN_STD_CALL_CONV :ptr SOCKADDR, :socklen_t, :PCHAR, :DWORD, :PCHAR, :DWORD, :INT_
    LPFN_GETNAMEINFO typedef ptr TYPE_LPFN_GETNAMEINFO

    TYPE_LPFN_GETNAMEINFOW typedef proto WIN_STD_CALL_CONV :ptr SOCKADDR, :socklen_t, :PWCHAR, :DWORD, :PWCHAR, :DWORD, :INT_
    LPFN_GETNAMEINFOW typedef ptr TYPE_LPFN_GETNAMEINFOW

    LPFN_GETNAMEINFOA equ <LPFN_GETNAMEINFO>
    ifdef UNICODE
      LPFN_GETNAMEINFOT equ <LPFN_GETNAMEINFOW>
    else
      LPFN_GETNAMEINFOT equ <LPFN_GETNAMEINFOA>
    endif
  endif
  if (NTDDI_VERSION ge NTDDI_VISTA)
    @DefProto DllImport, inet_pton, WIN_STD_CALL_CONV,, <:INT_, :PCSTR, :PVOID>, 12
    InetPtonW proto WIN_STD_CALL_CONV :INT_, :PCWSTR, :PVOID
    inet_ntop proto WIN_STD_CALL_CONV :INT_, :ptr VOID, :PSTR, :size_t
    InetNtopW proto WIN_STD_CALL_CONV :INT_, :ptr VOID, :PWSTR, :size_t
    InetPtonA equ <inet_pton>
    InetNtopA equ <inet_ntop>
    ifdef UNICODE
      InetPton equ <InetPtonW>
      InetNtop equ <InetNtopW>
    else
      InetPton equ <InetPtonA>
      InetNtop equ <InetNtopA>
    endif
    if INCL_WINSOCK_API_TYPEDEFS
      TYPE_LPFN_INET_PTONA typedef proto WIN_STD_CALL_CONV :INT_, :PCSTR, :PVOID
      LPFN_INET_PTONA typedef ptr TYPE_LPFN_INET_PTONA

      TYPE_LPFN_INET_PTONW typedef proto WIN_STD_CALL_CONV :INT_, :PCWSTR, :PVOID
      LPFN_INET_PTONW typedef ptr TYPE_LPFN_INET_PTONW

      TYPE_LPFN_INET_NTOPA typedef proto WIN_STD_CALL_CONV :INT_, :PVOID, :PSTR, :size_t
      LPFN_INET_NTOPA typedef ptr TYPE_LPFN_INET_NTOPA

      TYPE_LPFN_INET_NTOPW typedef proto WIN_STD_CALL_CONV :INT_, :PVOID, :PWSTR, :size_t
      LPFN_INET_NTOPW typedef ptr TYPE_LPFN_INET_NTOPW

      ifdef UNICODE
        LPFN_INET_PTON equ <LPFN_INET_PTONW>
        LPFN_INET_NTOP equ <LPFN_INET_NTOPW>
      else
        LPFN_INET_PTON equ <LPFN_INET_PTONA>
        LPFN_INET_NTOP equ <LPFN_INET_NTOPA>
      endif
    endif
  endif
  if INCL_WINSOCK_API_PROTOTYPES
    ifdef UNICODE
      gai_strerror equ <gai_strerrorW>
    else
      gai_strerror equ <gai_strerrorA>
    endif
    GAI_STRERROR_BUFFER_SIZE equ 1024
    gai_strerrorA proto WIN_STD_CALL_CONV :SDWORD
    gai_strerrorW proto WIN_STD_CALL_CONV :SDWORD
  endif
  setipv4sourcefilter proto WIN_STD_CALL_CONV :SOCKET, :IN_ADDR, :IN_ADDR, :MULTICAST_MODE_TYPE, :ULONG, :ptr IN_ADDR
  getipv4sourcefilter proto WIN_STD_CALL_CONV :SOCKET, :IN_ADDR, :IN_ADDR, :ptr MULTICAST_MODE_TYPE, :ptr ULONG, :ptr IN_ADDR
  if (NTDDI_VERSION ge NTDDI_WINXP)
    setsourcefilter proto WIN_STD_CALL_CONV :SOCKET, :ULONG, :ptr SOCKADDR, :SDWORD, :MULTICAST_MODE_TYPE, :ULONG, :ptr SOCKADDR_STORAGE
    getsourcefilter proto WIN_STD_CALL_CONV :SOCKET, :ULONG, :ptr SOCKADDR, :SDWORD, :ptr MULTICAST_MODE_TYPE, :ptr ULONG, :ptr SOCKADDR_STORAGE
  endif
  ifdef IDEAL_SEND_BACKLOG_IOCTLS
    idealsendbacklogquery proto WIN_STD_CALL_CONV :SOCKET, :ptr ULONG
    idealsendbacklognotify proto WIN_STD_CALL_CONV :SOCKET, :LPWSAOVERLAPPED, :LPWSAOVERLAPPED_COMPLETION_ROUTINE
  endif
  if (NTDDI_VERSION ge NTDDI_WIN10_VB)
    WSAGetIPUserMtu proto WIN_STD_CALL_CONV :SOCKET, :ptr DWORD
    if (_WIN32_WINNT ge 0501h)
    endif
    WSASetIPUserMtu proto WIN_STD_CALL_CONV :SOCKET, :DWORD
    if (_WIN32_WINNT ge 0501h)
    endif
    WSAGetFailConnectOnIcmpError proto WIN_STD_CALL_CONV :SOCKET, :ptr DWORD
    WSASetFailConnectOnIcmpError proto WIN_STD_CALL_CONV :SOCKET, :DWORD
    WSAGetIcmpErrorInfo proto WIN_STD_CALL_CONV :SOCKET, :ptr ICMP_ERROR_INFO
    WSAGetUdpSendMessageSize proto WIN_STD_CALL_CONV :SOCKET, :ptr DWORD
    WSASetUdpSendMessageSize proto WIN_STD_CALL_CONV :SOCKET, :DWORD
    WSAGetUdpRecvMaxCoalescedSize proto WIN_STD_CALL_CONV :SOCKET, :ptr DWORD
    WSASetUdpRecvMaxCoalescedSize proto WIN_STD_CALL_CONV :SOCKET, :DWORD
  endif
  if (NTDDI_VERSION ge NTDDI_WIN10_FE)
    WSAGetRecvIPEcn proto WIN_STD_CALL_CONV :SOCKET, :ptr DWORD
    if (_WIN32_WINNT ge 0501h)
    endif
    WSASetRecvIPEcn proto WIN_STD_CALL_CONV :SOCKET, :DWORD
    if (_WIN32_WINNT ge 0501h)
    endif
  endif
  if (_WIN32_WINNT ge 0600h)
    ifdef _SECURE_SOCKET_TYPES_DEFINED_
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PKG_APPRUNTIME)
        @DefProto DllImport, WSASetSocketSecurity, WIN_STD_CALL_CONV,, <:SOCKET, :ptr SOCKET_SECURITY_SETTINGS, :ULONG, :LPWSAOVERLAPPED, :LPWSAOVERLAPPED_COMPLETION_ROUTINE>, 20
        @DefProto DllImport, WSAQuerySocketSecurity, WIN_STD_CALL_CONV,, <:SOCKET, :ptr SOCKET_SECURITY_QUERY_TEMPLATE, :ULONG, :ptr SOCKET_SECURITY_QUERY_INFO, :ptr ULONG, :LPWSAOVERLAPPED, :LPWSAOVERLAPPED_COMPLETION_ROUTINE>, 28
        @DefProto DllImport, WSASetSocketPeerTargetName, WIN_STD_CALL_CONV,, <:SOCKET, :ptr SOCKET_PEER_TARGET_NAME, :ULONG, :LPWSAOVERLAPPED, :LPWSAOVERLAPPED_COMPLETION_ROUTINE>, 20
        @DefProto DllImport, WSADeleteSocketPeerTargetName, WIN_STD_CALL_CONV,, <:SOCKET, :ptr sockaddr, :ULONG, :LPWSAOVERLAPPED, :LPWSAOVERLAPPED_COMPLETION_ROUTINE>, 20
        @DefProto DllImport, WSAImpersonateSocketPeer, WIN_STD_CALL_CONV,, <:SOCKET, :ptr sockaddr, :ULONG>, 12
        @DefProto DllImport, WSARevertImpersonation, WIN_STD_CALL_CONV,, <>, 0
      endif
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
  ifdef _PREFAST_
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if  not Defined(_WIN32_WINNT) or (_WIN32_WINNT le 0500h)
      include wspiapi.inc
    endif
  endif
  if _MSC_VER ge 1200
  endif
endif
