;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\wspiapi.h
;             Created on (UTC) 06/04/2024 06:16:03
;             Last modified on (UTC) 12/02/2024 17:05:52

;--*
ifndef _WSPIAPI_H_
  _WSPIAPI_H_ equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if (NTDDI_VERSION ge NTDDI_WIN2K)
      include stdio.inc
      ; sprintf()
      include stdlib.inc
      ; calloc(), strtoul()
      include malloc.inc
      ; calloc()
      include string.inc
      ; strlen(), strcmp(), strstr()
      if Defined(__GOT_SECURE_LIB__) and __GOT_SECURE_LIB__ ge 200402
        _WSPIAPI_STRCPY_S equ <strcpy_s>
        _WSPIAPI_STRCAT_S equ <strcat_s>
        _WSPIAPI_STRNCPY_S equ <strncpy_s>
        _WSPIAPI_SPRINTF_S_1 equ <sprintf_s>
      else
        _WSPIAPI_STRCPY_S macro _Dst, _Size, _Src
          exitm <strcpy ((_Dst), (_Src))>
        endm
        _WSPIAPI_STRCAT_S macro _Dst, _Size, _Src
          exitm <strcat ((_Dst), (_Src))>
        endm
        _WSPIAPI_STRNCPY_S macro _Dst, _Size, _Src, _Count
          exitm <strncpy ((_Dst), (_Src), (_Count)) ; (_Dst) [ (_Size) - 1 ] = 0>
        endm
        _WSPIAPI_SPRINTF_S_1 macro _Dst, _Size, _Format, _Arg1
          exitm <sprintf ((_Dst), (_Format), (_Arg1))>
        endm
      endif
      ; defined(__GOT_SECURE_LIB__) && __GOT_SECURE_LIB__ >= 200402L
      if  not Defined(_WSPIAPI_COUNTOF)
        if  not Defined(__cplusplus)
          _WSPIAPI_COUNTOF macro _Array
            exitm <(sizeof(_Array) / sizeof(_Array [ 0 ]))>
          endm
        else
          ;[...]
        endif
      endif
      WspiapiMalloc macro tSize
        exitm <calloc (1, (tSize))>
      endm
      WspiapiFree macro p
        exitm <free (p)>
      endm
      WspiapiSwap macro a, b, c_
        exitm <{ (c_) = (a) ; (a) = (b) ; (b) = (c_) ; }>
      endm
      getaddrinfo equ <WspiapiGetAddrInfo>
      getnameinfo equ <WspiapiGetNameInfo>
      freeaddrinfo equ <WspiapiFreeAddrInfo>
      ; These function pointers are also within the #if (NTDDI_VERSION >= WIN2K)
      ; because they are used by the other functions defined in this file available
      ; only on win2k and above.
      TYPE_WSPIAPI_PGETADDRINFO typedef proto WIN_STD_CALL_CONV :ptr SBYTE, :ptr SBYTE, :ptr addrinfo, :ptr ptr addrinfo
      WSPIAPI_PGETADDRINFO typedef ptr TYPE_WSPIAPI_PGETADDRINFO

      TYPE_WSPIAPI_PGETNAMEINFO typedef proto WIN_STD_CALL_CONV :ptr sockaddr, :socklen_t, :ptr SBYTE, :size_t, :ptr SBYTE, :size_t, :SDWORD
      WSPIAPI_PGETNAMEINFO typedef ptr TYPE_WSPIAPI_PGETNAMEINFO

      TYPE_WSPIAPI_PFREEADDRINFO typedef proto WIN_STD_CALL_CONV :ptr addrinfo
      WSPIAPI_PFREEADDRINFO typedef ptr TYPE_WSPIAPI_PFREEADDRINFO

      ifdef __cplusplus
        ;[...]
      endif
      ;//////////////////////////////////////////////////////////
      ; v4 only versions of getaddrinfo and friends.
      ; NOTE: gai_strerror is inlined in ws2tcpip.h
      ;//////////////////////////////////////////////////////////
      WspiapiStrdup proto WIN_STD_CALL_CONV :ptr SBYTE
      ;*++
      ;Routine Description
      ;allocates enough storage via calloc() for a copy of the string,
      ;copies the string into the new memory, and returns a pointer to it.
      ;Arguments
      ;pszString       string to copy into new memory
      ;Return Value
      ;a pointer to the newly allocated storage with the string in it.
      ;NULL if enough memory could not be allocated, or string was NULL.
      ;--*
      WspiapiParseV4Address proto WIN_STD_CALL_CONV :ptr SBYTE, :PDWORD
      ;*++
      ;Routine Description
      ;get the IPv4 address (in network byte order) from its string
      ;representation.  the syntax should be a.b.c.d.
      ;Arguments
      ;pszArgument         string representation of the IPv4 address
      ;ptAddress           pointer to the resulting IPv4 address
      ;Return Value
      ;Returns FALSE if there is an error, TRUE for success.
      ;--*
      ; ensure there are 3 '.' (periods)
      ; return an error if dwAddress is INADDR_NONE (255.255.255.255)
      ; since this is never a valid argument to getaddrinfo.
      WspiapiNewAddrInfo proto WIN_STD_CALL_CONV :SDWORD, :SDWORD, :WORD, :DWORD
      ;*++
      ;Routine Description
      ;allocate an addrinfo structure and populate fields.
      ;IPv4 specific internal function, not exported.
      ;Arguments
      ;iSocketType         SOCK_*.  can be wildcarded (zero).
      ;iProtocol           IPPROTO_*.  can be wildcarded (zero).
      ;wPort               port number of service (in network order).
      ;dwAddress           IPv4 address (in network order).
      ;Return Value
      ;returns an addrinfo struct, or NULL if out of memory.
      ;--*
      ; allocate a new addrinfo structure.
      ; fill in the fields...
      WspiapiQueryDNS proto WIN_STD_CALL_CONV :ptr SBYTE, :SDWORD, :SDWORD, :WORD, :ptr SBYTE, :ptr ptr addrinfo
      ;*++
      ;Routine Description
      ;helper routine for WspiapiLookupNode.
      ;performs name resolution by querying the DNS for A records.
      ;*pptResult would need to be freed if an error is returned.
      ;Arguments
      ;pszNodeName         name of node to resolve.
      ;iSocketType         SOCK_*.  can be wildcarded (zero).
      ;iProtocol           IPPROTO_*.  can be wildcarded (zero).
      ;wPort               port number of service (in network order).
      ;pszAlias            where to return the alias.  must be of size NI_MAXHOST.
      ;pptResult           where to return the result.
      ;Return Value
      ;Returns 0 on success, an EAI_* style error value otherwise.
      ;--*
      ; create an addrinfo structure...
      ; pick up the canonical name.
      WspiapiLookupNode proto WIN_STD_CALL_CONV :ptr SBYTE, :SDWORD, :SDWORD, :WORD, :BOOL, :ptr ptr addrinfo
      ;*++
      ;Routine Description
      ;resolve a nodename and return a list of addrinfo structures.
      ;IPv4 specific internal function, not exported.
      ;*pptResult would need to be freed if an error is returned.
      ;NOTE: if bAI_CANONNAME is true, the canonical name should be
      ;returned in the first addrinfo structure.
      ;Arguments
      ;pszNodeName         name of node to resolve.
      ;iSocketType         SOCK_*.  can be wildcarded (zero).
      ;iProtocol           IPPROTO_*.  can be wildcarded (zero).
      ;wPort               port number of service (in network order).
      ;bAI_CANONNAME       whether the AI_CANONNAME flag is set.
      ;pptResult           where to return result.
      ;Return Value
      ;Returns 0 on success, an EAI_* style error value otherwise.
      ;--*
      ; if we found addresses, then we are done.
      ; stop infinite loops due to DNS misconfiguration.  there appears
      ; to be no particular recommended limit in RFCs 1034 and 1035.
      ; there was a new CNAME, look again.
      WspiapiClone proto WIN_STD_CALL_CONV :WORD, :ptr addrinfo
      ;*++
      ;Routine Description
      ;clone every addrinfo structure in ptResult for the UDP service.
      ;ptResult would need to be freed if an error is returned.
      ;Arguments
      ;wPort               port number of UDP service.
      ;ptResult            list of addrinfo structures, each
      ;of whose node needs to be cloned.
      ;Return Value
      ;Returns 0 on success, an EAI_MEMORY on allocation failure.
      ;--*
      ; create an addrinfo structure...
      ; link the cloned addrinfo
      WspiapiLegacyFreeAddrInfo proto WIN_STD_CALL_CONV :ptr addrinfo
      ;*++
      ;Routine Description
      ;Free an addrinfo structure (or chain of structures).
      ;As specified in RFC 2553, Section 6.4.
      ;Arguments
      ;ptHead              structure (chain) to free
      ;--*
      ; next strcture to free
      WspiapiLegacyGetAddrInfo proto WIN_STD_CALL_CONV :ptr SBYTE, :ptr SBYTE, :ptr addrinfo, :ptr ptr addrinfo
      ;*++
      ;Routine Description
      ;Protocol-independent name-to-address translation.
      ;As specified in RFC 2553, Section 6.4.
      ;This is the hacked version that only supports IPv4.
      ;Arguments
      ;pszNodeName         node name to lookup.
      ;pszServiceName      service name to lookup.
      ;ptHints             hints about how to process request.
      ;pptResult           where to return result.
      ;Return Value
      ;returns zero if successful, an EAI_* error code if not.
      ;--*
      ; initialize pptResult with default return value.
      ;//////////////////////////////////////
      ; validate arguments...
      ; both the node name and the service name can't be NULL.
      ; validate hints.
      ; all members other than ai_flags, ai_family, ai_socktype
      ; and ai_protocol must be zero or a null pointer.
      ; the spec has the "bad flags" error code, so presumably we
      ; should check something here.  insisting that there aren't
      ; any unspecified flags set would break forward compatibility,
      ; however.  so we just check for non-sensical combinations.
      ; we cannot come up with a canonical name given a null node name.
      ; we only support a limited number of protocol families.
      ; we only support only these socket types.
      ; REVIEW: What if ai_socktype and ai_protocol are at odds?
      ;//////////////////////////////////////
      ; do service lookup...
      ; numeric port string
      ; non numeric port string
      ; assumes 0 is an invalid service port...
      ; no service exists
      ; if both tcp and udp, process tcp now & clone udp later.
      ;//////////////////////////////////////
      ; do node name lookup...
      ; if we weren't given a node name,
      ; return the wildcard or loopback address (depending on AI_PASSIVE).
      ; if we have a numeric host address string,
      ; return the binary address.
      ; create an addrinfo structure...
      ; implementation specific behavior: set AI_NUMERICHOST
      ; to indicate that we got a numeric host address string.
      ; return the numeric address string as the canonical name
      ; if we do not have a numeric host address string and
      ; AI_NUMERICHOST flag is set, return an error!
      ; since we have a non-numeric node name,
      ; we have to do a regular node name lookup.
      WspiapiLegacyGetNameInfo proto WIN_STD_CALL_CONV :ptr sockaddr, :socklen_t, :ptr SBYTE, :size_t, :ptr SBYTE, :size_t, :SDWORD
      ;*++
      ;Routine Description
      ;protocol-independent address-to-name translation.
      ;as specified in RFC 2553, Section 6.5.
      ;this is the hacked version that only supports IPv4.
      ;Arguments
      ;ptSocketAddress     socket address to translate.
      ;tSocketLength       length of above socket address.
      ;pszNodeName         where to return the node name.
      ;tNodeLength         size of above buffer.
      ;pszServiceName      where to return the service name.
      ;tServiceLength      size of above buffer.
      ;iFlags              flags of type NI_*.
      ;Return Value
      ;returns zero if successful, an EAI_* error code if not.
      ;--*
      ; sanity check ptSocketAddress and tSocketLength.
      ; the draft has the "bad flags" error code, so presumably we
      ; should check something here.  insisting that there aren't
      ; any unspecified flags set would break forward compatibility,
      ; however.  so we just check for non-sensical combinations.
      ; translate the port to a service name (if requested).
      ; return numeric form of the address.
      ; return service name corresponding to port.
      ; lookup successful.
      ; DRAFT: return numeric form of the port!
      ; translate the address to a node name (if requested).
      ; this is the IPv4-only version, so we have an IPv4 address.
      ; return numeric form of the address.
      ; return node name corresponding to address.
      ; DNS lookup successful.
      ; stop copying at a "." if NI_NOFQDN is specified.
      ; DNS lookup failed.  return numeric form of the address.
      WSPIAPI_FUNCTION struct
        pszName POINTER ?
        pfAddress FARPROC ?
      WSPIAPI_FUNCTION ends
      WSPIAPI_FUNCTION_ARRAY equ <{ "getaddrinfo", (FARPROC) WspiapiLegacyGetAddrInfo, "getnameinfo", (FARPROC) WspiapiLegacyGetNameInfo, "freeaddrinfo", (FARPROC) WspiapiLegacyFreeAddrInfo, }>
      WspiapiLoad proto WIN_STD_CALL_CONV :WORD
      ;*++
      ;Routine Description
      ;try to locate the address family independent name resolution routines
      ;(i.e. getaddrinfo, getnameinfo, freeaddrinfo, gai_strerror).
      ;Locks
      ;this function call is not synchronized.  hence the library containing
      ;the routines might be loaded multiple times.  another option is to
      ;synchronize through a spin lock using a static local variable and the
      ;InterlockedExchange operation.  
      ;Arguments
      ;wFunction           ordinal # of the function to get the pointer to
      ;0   getaddrinfo
      ;1   getnameinfo
      ;2   freeaddrinfo
      ;Return Value
      ;address of the library/legacy routine
      ;--*
      ; these static variables store state across calls, across threads.
      ; we overwrite rgtGlobal only if all routines exist in library.
      ; WspiapiLoad has already been called once
      ; breakout loop
      ; in Whistler and beyond...
      ; the routines are present in the WinSock 2 library (ws2_32.dll).
      ; printf("Looking in ws2_32 for getaddrinfo...\n");
      ; in the IPv6 Technology Preview...        
      ; the routines are present in the IPv6 WinSock library (wship6.dll).
      ; printf("Looking in wship6 for getaddrinfo...\n");
      ; use routines from this library...
      ; since getaddrinfo is here, we expect all routines to be here,
      ; but will fall back to IPv4-only if any of them is missing.
      ; printf("found!\n");
      WspiapiGetAddrInfo proto WIN_STD_CALL_CONV :ptr SBYTE, :ptr SBYTE, :ptr addrinfo, :ptr ptr addrinfo
      WspiapiGetNameInfo proto WIN_STD_CALL_CONV :ptr sockaddr, :socklen_t, :ptr SBYTE, :size_t, :ptr SBYTE, :size_t, :SDWORD
      WspiapiFreeAddrInfo proto WIN_STD_CALL_CONV :ptr addrinfo
      ifdef __cplusplus
        ;[...]
      endif
    endif
    ; if (NTDDI_VERSION >= WIN2K)
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
endif
; _WSPIAPI_H_
