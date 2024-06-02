;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\propkeydef.h
;             Created on (UTC) 06/04/2024 06:15:57
;             Last modified on (UTC) 16/12/2023 11:07:16

ifndef PID_FIRST_USABLE
  PID_FIRST_USABLE equ 2
endif
ifndef REFPROPERTYKEY
  ifdef __cplusplus
    ;[...]
  else
    REFPROPERTYKEY typedef ptr GUID
  endif
endif
ifdef DEFINE_PROPERTYKEY
endif
ifdef INITGUID
  DEFINE_PROPERTYKEY macro GUID_Name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8
    GUID_Name GUID { l, w1, w2, { b1, b2, b3, b4, b5, b6, b7, b8}}
  endm
else
  DEFINE_PROPERTYKEY macro GUID_Name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8
    externdef GUID_Name:GUID
    s&GUID_Name textequ <GUID {l, w1, w2, {b1, b2, b3, b4, b5, b6, b7, b8}}>
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
