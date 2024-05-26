;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\inaddr.h
;             Created on (UTC) 22/05/2024 17:57:07
;             Last modified on (UTC) 08/01/2024 17:04:20

ifndef s_addr
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    IN_ADDR struct
      union S_un
        struct S_un_b
          s_b1 UCHAR ?
          s_b2 UCHAR ?
          s_b3 UCHAR ?
          s_b4 UCHAR ?
        ends
        struct S_un_w
          s_w1 USHORT ?
          s_w2 USHORT ?
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
