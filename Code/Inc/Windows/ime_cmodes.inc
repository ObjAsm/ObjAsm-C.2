;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\ime_cmodes.h', last modified: 19/04/2018 10:43
;Creation parameters: 

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

