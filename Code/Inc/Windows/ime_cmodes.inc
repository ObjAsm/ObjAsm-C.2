;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\ime_cmodes.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 16/12/2023 11:05:20

ifndef _IME_CMODES_
  _IME_CMODES_ equ <>
  IME_CMODE_ALPHANUMERIC equ 0000h
  IME_CMODE_NATIVE equ 0001h
  IME_CMODE_CHINESE equ <IME_CMODE_NATIVE>
  IME_CMODE_HANGUL equ <IME_CMODE_NATIVE>
  IME_CMODE_JAPANESE equ <IME_CMODE_NATIVE>
  IME_CMODE_KATAKANA equ 0002h
  IME_CMODE_LANGUAGE equ 0003h
  IME_CMODE_FULLSHAPE equ 0008h
  IME_CMODE_ROMAN equ 0010h
  IME_CMODE_CHARCODE equ 0020h
  IME_CMODE_HANJACONVERT equ 0040h
  IME_CMODE_NATIVESYMBOL equ 0080h
endif
