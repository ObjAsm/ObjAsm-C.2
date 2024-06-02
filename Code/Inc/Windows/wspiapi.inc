;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\wspiapi.h
;             Created on (UTC) 06/04/2024 06:16:03
;             Last modified on (UTC) 12/02/2024 17:05:52

ifndef _WSPIAPI_H_
  _WSPIAPI_H_ equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if (NTDDI_VERSION ge NTDDI_WIN2K)
      include stdio.inc
      include stdlib.inc
      include malloc.inc
      include string.inc
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
      TYPE_WSPIAPI_PGETADDRINFO typedef proto WIN_STD_CALL_CONV :ptr SBYTE, :ptr SBYTE, :ptr addrinfo, :ptr ptr addrinfo
      WSPIAPI_PGETADDRINFO typedef ptr TYPE_WSPIAPI_PGETADDRINFO

      TYPE_WSPIAPI_PGETNAMEINFO typedef proto WIN_STD_CALL_CONV :ptr sockaddr, :socklen_t, :ptr SBYTE, :size_t, :ptr SBYTE, :size_t, :SDWORD
      WSPIAPI_PGETNAMEINFO typedef ptr TYPE_WSPIAPI_PGETNAMEINFO

      TYPE_WSPIAPI_PFREEADDRINFO typedef proto WIN_STD_CALL_CONV :ptr addrinfo
      WSPIAPI_PFREEADDRINFO typedef ptr TYPE_WSPIAPI_PFREEADDRINFO

      ifdef __cplusplus
        ;[...]
      endif
      WspiapiStrdup proto WIN_STD_CALL_CONV :ptr SBYTE
      WspiapiParseV4Address proto WIN_STD_CALL_CONV :ptr SBYTE, :PDWORD
      WspiapiNewAddrInfo proto WIN_STD_CALL_CONV :SDWORD, :SDWORD, :WORD, :DWORD
      WspiapiQueryDNS proto WIN_STD_CALL_CONV :ptr SBYTE, :SDWORD, :SDWORD, :WORD, :ptr SBYTE, :ptr ptr addrinfo
      WspiapiLookupNode proto WIN_STD_CALL_CONV :ptr SBYTE, :SDWORD, :SDWORD, :WORD, :BOOL, :ptr ptr addrinfo
      WspiapiClone proto WIN_STD_CALL_CONV :WORD, :ptr addrinfo
      WspiapiLegacyFreeAddrInfo proto WIN_STD_CALL_CONV :ptr addrinfo
      WspiapiLegacyGetAddrInfo proto WIN_STD_CALL_CONV :ptr SBYTE, :ptr SBYTE, :ptr addrinfo, :ptr ptr addrinfo
      WspiapiLegacyGetNameInfo proto WIN_STD_CALL_CONV :ptr sockaddr, :socklen_t, :ptr SBYTE, :size_t, :ptr SBYTE, :size_t, :SDWORD
      WSPIAPI_FUNCTION struct
        pszName POINTER ?
        pfAddress FARPROC ?
      WSPIAPI_FUNCTION ends
      WSPIAPI_FUNCTION_ARRAY equ <{ "getaddrinfo", (FARPROC) WspiapiLegacyGetAddrInfo, "getnameinfo", (FARPROC) WspiapiLegacyGetNameInfo, "freeaddrinfo", (FARPROC) WspiapiLegacyFreeAddrInfo, }>
      WspiapiLoad proto WIN_STD_CALL_CONV :WORD
      WspiapiGetAddrInfo proto WIN_STD_CALL_CONV :ptr SBYTE, :ptr SBYTE, :ptr addrinfo, :ptr ptr addrinfo
      WspiapiGetNameInfo proto WIN_STD_CALL_CONV :ptr sockaddr, :socklen_t, :ptr SBYTE, :size_t, :ptr SBYTE, :size_t, :SDWORD
      WspiapiFreeAddrInfo proto WIN_STD_CALL_CONV :ptr addrinfo
      ifdef __cplusplus
        ;[...]
      endif
    endif
  endif
endif
