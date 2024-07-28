;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\inaddr.h', last modified: 19/04/2018 10:44
;Creation parameters: 

ifndef s_addr
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    IN_ADDR struct
      union S_un
        struct S_un_b
          s_b1 UCHAR ?
        ends
        struct S_un_w
          s_w1 USHORT ?
        ends
        S_addr ULONG ?
      ends
      s_addr equ <S_un.S_addr>
      s_host equ <S_un.S_un_b.s_b2>
      s_net equ <S_un.S_un_b.s_b1>
      s_imp equ <S_un.S_un_w.s_w2>
      s_impno equ <S_un.S_un_b.s_b4>
      s_lh equ <S_un.S_un_b.s_b3>
    IN_ADDR ends

    in_addr typedef IN_ADDR
    PIN_ADDR typedef ptr IN_ADDR
    LPIN_ADDR typedef ptr IN_ADDR
    
  endif
endif

