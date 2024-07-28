;Include file created by h2incX, Version B.01.01, 26/11/2018 23:24
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'D:\MASM32\ObjAsm\Projects\h2IncX\header\in6addr.h', last modified: 19/04/2018 09:44
;Creation parameters: 

ifndef s6_addr
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    IN6_ADDR struct
      union u
        Byte_ UCHAR 16 dup (?)
        Word_ USHORT 8 dup (?)
      ends
    IN6_ADDR ends

    in6_addr typedef IN6_ADDR
    PIN6_ADDR typedef ptr IN6_ADDR
    LPIN6_ADDR typedef ptr IN6_ADDR
    
    in_addr6 equ <in6_addr>
    _S6_un equ <u>
    _S6_u8 equ <Byte_>
    s6_addr equ <_S6_un._S6_u8>
    s6_bytes equ <u.Byte>
    s6_words equ <u.Word>
  endif
endif

