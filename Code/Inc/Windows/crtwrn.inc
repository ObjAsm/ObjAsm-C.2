;Include file created by h2incX, Version B.01.01, 15/11/2018 21:48
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\crtwrn.h', last modified: 01/10/2012 07:50
;Creation parameters: 

ifndef _INC_CRTWRN
  _INC_CRTWRN equ <>
  include crtdefs.inc
  __CRT_WARNING macro _Number, _Description
    exitm <message (__FILE__ "(" _CRT_STRINGIZE(__LINE__) ") : " "warning CRT" _CRT_STRINGIZE(_Number) ": " _CRT_STRINGIZE(_Description))>
  endm
  _CRT_WARNING macro _Id
    exitm <__CRT_WARNING(_CRTWRN_WNUMBER_ ## _Id, _CRTWRN_MESSAGE_ ## _Id)>
  endm
  _CRTWRN_WNUMBER__NO_SPECIAL_TRANSFER equ 1004
  _CRTWRN_MESSAGE__NO_SPECIAL_TRANSFER equ <Special transfer of control routines not defined for this platform>
  _CRTWRN_WNUMBER__DEPRECATE_STATIC_CPPLIB equ 1007
  _CRTWRN_MESSAGE__DEPRECATE_STATIC_CPPLIB equ <_STATIC_CPPLIB is deprecated>
endif

