;Include file created by h2incX, Version B.01.01, 19/04/2018 10:43
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\guiddef.h', last modified: 19/04/2018 10:43
;Creation parameters: 

ifndef GUID_DEFINED
  GUID_DEFINED equ <>
  if Defined(__midl)
    ;[...]
  else
    GUID struct
      Data1 DWORD ?
      Data2 WORD ?
      Data3 WORD ?
      Data4 BYTE 8 dup (?)
    GUID ends

    _GUID typedef GUID
  endif
endif
ifndef FAR
  ifdef _WIN32
    ;FAR equ <>
  else
    ;[...]
  endif
endif
ifndef DECLSPEC_SELECTANY
  if (_MSC_VER ge 1100)
    DECLSPEC_SELECTANY equ <__declspec(selectany)>
  else
    DECLSPEC_SELECTANY equ <>
  endif
endif
ifndef EXTERN_C
  ifdef __cplusplus
    ;[...]
  else
    EXTERN_C equ <extern>
  endif
endif
ifdef DEFINE_GUID
endif
ifdef INITGUID
 DEFINE_GUID macro GUID_Name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8
  GUID_Name GUID { l, w1, w2, { b1, b2, b3, b4, b5, b6, b7, b8}}
 endm
else
 DEFINE_GUID macro GUID_Name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8
  externdef GUID_Name:GUID
  s&GUID_Name textequ <{l, w1, w2, {b1, b2, b3, b4, b5, b6, b7, b8}}>
 endm
endif
DEFINE_OLEGUID macro GUID_Name, l, w1, w2
 DEFINE_GUID GUID_Name, l, w1, w2, 0C0h, 0, 0, 0, 0, 0, 0, 46h
endm
ifndef _GUIDDEF_H_
  _GUIDDEF_H_ equ <>
  ifndef __LPGUID_DEFINED__
    __LPGUID_DEFINED__ equ <>
    LPGUID typedef ptr GUID
  endif
  ifndef __LPCGUID_DEFINED__
    __LPCGUID_DEFINED__ equ <>
    LPCGUID typedef ptr GUID
  endif
  ifndef __IID_DEFINED__
    __IID_DEFINED__ equ <>
    IID typedef GUID
    LPIID typedef ptr IID
    IID_NULL equ <GUID_NULL>
    IsEqualIID macro riid1, riid2
      exitm <IsEqualGUID(riid1, riid2)>
    endm
    CLSID typedef GUID
    LPCLSID typedef ptr CLSID
    CLSID_NULL equ <GUID_NULL>
    IsEqualCLSID macro rclsid1, rclsid2
      exitm <IsEqualGUID(rclsid1, rclsid2)>
    endm
    FMTID typedef GUID
    LPFMTID typedef ptr FMTID
    FMTID_NULL equ <GUID_NULL>
    IsEqualFMTID macro rfmtid1, rfmtid2
      exitm <IsEqualGUID(rfmtid1, rfmtid2)>
    endm
    ifdef __midl_proxy
      __MIDL_CONST equ <>
    else
      __MIDL_CONST equ <>
    endif
    ifndef _REFGUID_DEFINED
      _REFGUID_DEFINED equ <>
      ifdef __cplusplus
        ;[...]
      else
        REFGUID typedef ptr GUID
      endif
    endif
    ifndef _REFIID_DEFINED
      _REFIID_DEFINED equ <>
      ifdef __cplusplus
        ;[...]
      else
        REFIID typedef ptr IID
      endif
    endif
    ifndef _REFCLSID_DEFINED
      _REFCLSID_DEFINED equ <>
      ifdef __cplusplus
        ;[...]
      else
        REFCLSID typedef ptr IID
      endif
    endif
    ifndef _REFFMTID_DEFINED
      _REFFMTID_DEFINED equ <>
      ifdef __cplusplus
        ;[...]
      else
        REFFMTID typedef ptr IID
      endif
    endif
  endif
  if  not Defined(__midl)
    if  not Defined(_SYS_GUID_OPERATORS_)
      _SYS_GUID_OPERATORS_ equ <>
      include string.inc
      ifdef __cplusplus
        ;[...]
      else
        InlineIsEqualGUID macro rguid1, rguid2
          exitm <((rguid1) [ 0 ] == (rguid2) [ 0 ] and (rguid1) [ 1 ] == (rguid2) [ 1 ] and (rguid1) [ 2 ] == (rguid2) [ 2 ] and (rguid1) [ 3 ] == (rguid2) [ 3 ])>
        endm
        IsEqualGUID macro rguid1, rguid2
          exitm <(! memcmp (rguid1, rguid2, sizeof(GUID)))>
        endm
      endif
      ifdef __INLINE_ISEQUAL_GUID
        IsEqualGUID macro rguid1, rguid2
          exitm <InlineIsEqualGUID(rguid1, rguid2)>
        endm
      endif
      IsEqualIID macro riid1, riid2
        exitm <IsEqualGUID(riid1, riid2)>
      endm
      IsEqualCLSID macro rclsid1, rclsid2
        exitm <IsEqualGUID(rclsid1, rclsid2)>
      endm
      if  not Defined(_SYS_GUID_OPERATOR_EQ_) and  not Defined(_NO_SYS_GUID_OPERATOR_EQ_)
        _SYS_GUID_OPERATOR_EQ_ equ <>
        ifdef __cplusplus
          ;[...]
        endif
      endif
    endif
  endif
endif
