;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\propkeydef.h', last modified: 19/04/2018 10:43
;Creation parameters: 

ifndef PID_FIRST_USABLE
  PID_FIRST_USABLE equ 2
endif
ifndef REFPROPERTYKEY
  ifdef __cplusplus
    ;[...]
  else
    REFPROPERTYKEY equ <ptr PROPERTYKEY>
  endif
endif
ifdef DEFINE_PROPERTYKEY
endif
ifdef INITGUID
  DEFINE_PROPERTYKEY macro name_, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8, pid
    name_ PROPERTYKEY { { l, w1, w2, { b1, b2, b3, b4, b5, b6, b7, b8 } }, pid }>
  endm
else
  DEFINE_PROPERTYKEY macro name_, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8, pid
    name_ PROPERTYKEY {}
  endm
endif
ifndef IsEqualPropertyKey
  IsEqualPropertyKey macro a, b
    exitm <(((a).pid == (b).pid) and IsEqualIID((a).fmtid, (b).fmtid))>
  endm
endif
ifndef _PROPERTYKEY_EQUALITY_OPERATORS_
  _PROPERTYKEY_EQUALITY_OPERATORS_ equ <>
  ifdef __cplusplus
    ;[...]
  endif
endif

