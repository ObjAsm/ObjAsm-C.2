;Include file created by h2inc+ version C.2.0 on (UTC) 15/06/2024 16:37:44
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\in6addr.h
;             Created on (UTC) 22/05/2024 17:57:07
;             Last modified on (UTC) 08/01/2024 17:04:20

ifndef s6_addr
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    IN6_ADDR struct
      union u
        Byte UCHAR 16 dup (?)
        Word USHORT 8 dup (?)
      ends
    IN6_ADDR ends
    in6_addr typedef IN6_ADDR
    PIN6_ADDR typedef ptr IN6_ADDR
    LPIN6_ADDR typedef ptr IN6_ADDR
    in_addr6 equ <in6_addr>
    _S6_un equ <u>
    _S6_u8 equ <Byte>
    s6_addr equ <_S6_un._S6_u8>
    s6_bytes equ <u.Byte>
    s6_words equ <u.Word>
  endif
endif
