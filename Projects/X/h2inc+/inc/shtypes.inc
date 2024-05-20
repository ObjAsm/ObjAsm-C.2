;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\shtypes.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 21/02/2024 18:17:36

;* verify that the <rpcndr.h> version is high enough to compile this file*
ifndef __REQUIRED_RPCNDR_H_VERSION__
  __REQUIRED_RPCNDR_H_VERSION__ equ 501
endif
;* verify that the <rpcsal.h> version is high enough to compile this file*
ifndef __REQUIRED_RPCSAL_H_VERSION__
  __REQUIRED_RPCSAL_H_VERSION__ equ 100
endif
include rpc.inc
include rpcndr.inc
ifndef __RPCNDR_H_VERSION__
  .err <this stub requires an updated version of < rpcndr.h >>
  ;* __RPCNDR_H_VERSION__ *
endif
ifndef __shtypes_h__
  __shtypes_h__ equ <>
  if Defined(_MSC_VER) and (_MSC_VER ge 1020)
  endif
  ifndef DECLSPEC_XFGVIRT
    if Defined(_CONTROL_FLOW_GUARD_XFG)
      DECLSPEC_XFGVIRT macro base, func
        exitm <__declspec(xfg_virtual (base, func))>
      endm
    else
      DECLSPEC_XFGVIRT macro base, func
        exitm <>
      endm
    endif
  endif
  ;* Forward Declarations *
  ;* header files for imported files *
  include wtypes.inc
  include unknwn.inc
  ifdef __cplusplus
    ;[...]
  endif
  ;* interface __MIDL_itf_shtypes_0000_0000 *
  ;* [local] *
  if _MSC_VER ge 1200
    ;* nonstandard extension : single line comment *
    ;* padding added after data member *
  endif
  ;+-------------------------------------------------------------------------
  ;  Microsoft Windows
  ;  Copyright (c) Microsoft Corporation. All rights reserved.
  ;--------------------------------------------------------------------------
  ; For compilers that don't support nameless unions
  ifndef DUMMYUNIONNAME
    ifdef NONAMELESSUNION
      DUMMYUNIONNAME equ <u>
      DUMMYUNIONNAME2 equ <u2>
      DUMMYUNIONNAME3 equ <u3>
      DUMMYUNIONNAME4 equ <u4>
      DUMMYUNIONNAME5 equ <u5>
    else
      DUMMYUNIONNAME equ <>
      DUMMYUNIONNAME2 equ <>
      DUMMYUNIONNAME3 equ <>
      DUMMYUNIONNAME4 equ <>
      DUMMYUNIONNAME5 equ <>
    endif
  endif
  ; DUMMYUNIONNAME
  ;===========================================================================
  ; Object identifiers in the explorer's name space (ItemID and IDList)
  ;  All the items that the user can browse with the explorer (such as files,
  ; directories, servers, work-groups, etc.) has an identifier which is unique
  ; among items within the parent folder. Those identifiers are called item
  ; IDs (SHITEMID). Since all its parent folders have their own item IDs,
  ; any items can be uniquely identified by a list of item IDs, which is called
  ; an ID list (ITEMIDLIST).
  ;  ID lists are almost always allocated by the task allocator (see some
  ; description below as well as OLE 2.0 SDK) and may be passed across
  ; some of shell interfaces (such as IShellFolder). Each item ID in an ID list
  ; is only meaningful to its parent folder (which has generated it), and all
  ; the clients must treat it as an opaque binary data except the first two
  ; bytes, which indicates the size of the item ID.
  ;  When a shell extension -- which implements the IShellFolder interace --
  ; generates an item ID, it may put any information in it, not only the data
  ; with that it needs to identifies the item, but also some additional
  ; information, which would help implementing some other functions efficiently.
  ; For example, the shell's IShellFolder implementation of file system items
  ; stores the primary (long) name of a file or a directory as the item
  ; identifier, but it also stores its alternative (short) name, size and date
  ; etc.
  ;  When an ID list is passed to one of shell APIs (such as SHGetPathFromIDList),
  ; it is always an absolute path -- relative from the root of the name space,
  ; which is the desktop folder. When an ID list is passed to one of IShellFolder
  ; member function, it is always a relative path from the folder (unless it
  ; is explicitly specified).
  ;===========================================================================
  ; SHITEMID -- Item ID  (mkid)
  ;     USHORT      cb;             // Size of the ID (including cb itself)
  ;     BYTE        abID[];         // The item ID (variable length)
  include pshpack1.inc
  SHITEMID struct
    cb WORD ?
    abID BYTE 1 dup (?)
  SHITEMID ends
  _SHITEMID typedef SHITEMID
  include poppack.inc
  if Defined(_M_IX86)
    __unaligned equ <>
  endif
  ; __unaligned
  LPSHITEMID typedef ptr SHITEMID
  LPCSHITEMID typedef ptr SHITEMID
  ; ITEMIDLIST -- List if item IDs (combined with 0-terminator)
  include pshpack1.inc
  ITEMIDLIST struct
    mkid SHITEMID <>
  ITEMIDLIST ends
  _ITEMIDLIST typedef ITEMIDLIST
  if Defined(STRICT_TYPED_ITEMIDS) and Defined(__cplusplus)
    ;[...]
  else
  ; !(defined(STRICT_TYPED_ITEMIDS) && defined(__cplusplus))
    ITEMIDLIST_RELATIVE typedef ITEMIDLIST
    ITEMID_CHILD typedef ITEMIDLIST
    ITEMIDLIST_ABSOLUTE typedef ITEMIDLIST
  endif
  ; defined(STRICT_TYPED_ITEMIDS) && defined(__cplusplus)
  include poppack.inc
  ;* [unique] *
  wirePIDL typedef ptr BYTE_BLOB
  ;* [wire_marshal] *
  LPITEMIDLIST typedef ptr ITEMIDLIST
  ;* [wire_marshal] *
  LPCITEMIDLIST typedef ptr ITEMIDLIST
  if Defined(STRICT_TYPED_ITEMIDS) and Defined(__cplusplus)
    ;[...]
  else
  ; !(defined(STRICT_TYPED_ITEMIDS) && defined(__cplusplus))
    PIDLIST_ABSOLUTE equ <LPITEMIDLIST>
    PCIDLIST_ABSOLUTE equ <LPCITEMIDLIST>
    PCUIDLIST_ABSOLUTE equ <LPCITEMIDLIST>
    PIDLIST_RELATIVE equ <LPITEMIDLIST>
    PCIDLIST_RELATIVE equ <LPCITEMIDLIST>
    PUIDLIST_RELATIVE equ <LPITEMIDLIST>
    PCUIDLIST_RELATIVE equ <LPCITEMIDLIST>
    PITEMID_CHILD equ <LPITEMIDLIST>
    PCITEMID_CHILD equ <LPCITEMIDLIST>
    PUITEMID_CHILD equ <LPITEMIDLIST>
    PCUITEMID_CHILD equ <LPCITEMIDLIST>
    PCUITEMID_CHILD_ARRAY equ <LPCITEMIDLIST *>
    PCUIDLIST_RELATIVE_ARRAY equ <LPCITEMIDLIST *>
    PCIDLIST_ABSOLUTE_ARRAY equ <LPCITEMIDLIST *>
    PCUIDLIST_ABSOLUTE_ARRAY equ <LPCITEMIDLIST *>
  endif
  ; defined(STRICT_TYPED_ITEMIDS) && defined(__cplusplus)
  ifdef MIDL_PASS
    ;[...]
  endif
  ; MIDL_PASS
  ;-------------------------------------------------------------------------
  ; struct STRRET
  ; structure for returning strings from IShellFolder member functions
  ;-------------------------------------------------------------------------
  ;  uType indicate which union member to use 
  ;    STRRET_WSTR    Use STRRET.pOleStr     must be freed by caller of GetDisplayNameOf
  ;    STRRET_OFFSET  Use STRRET.uOffset     Offset into SHITEMID for ANSI string 
  ;    STRRET_CSTR    Use STRRET.cStr        ANSI Buffer
  ;* [v1_enum] *
  STRRET_TYPE typedef SDWORD
  STRRET_WSTR equ 0
  STRRET_OFFSET equ 1h
  STRRET_CSTR equ 2h
  tagSTRRET_TYPE typedef STRRET_TYPE

  if Defined(_MSC_VER) and (_MSC_VER ge 1200)
    ;* nonstandard extension used : nameless struct/union *
  endif
  include pshpack8.inc
  STRRET struct
    uType DWORD ?
    ;* [switch_is][switch_type] *
    union
      pOleStr POINTER ?
      ;* [case()][string] *
      uOffset DWORD ?
      ;* [case()] *
      cStr SBYTE 260 dup (?)
      ;* [case()] *
    ends
  STRRET ends
  _STRRET typedef STRRET
  include poppack.inc
  if Defined(_MSC_VER) and (_MSC_VER ge 1200)
  endif
  LPSTRRET typedef ptr STRRET
  ;-------------------------------------------------------------------------
  ; struct SHELLDETAILS
  ; structure for returning strings from IShellDetails
  ;-------------------------------------------------------------------------
  ;  fmt;            // LVCFMT_* value (header only)
  ;  cxChar;         // Number of 'average' characters (header only)
  ;  str;            // String information
  include pshpack1.inc
  SHELLDETAILS struct
    fmt SDWORD ?
    cxChar SDWORD ?
    str_ STRRET <>
  SHELLDETAILS ends
  _SHELLDETAILS typedef SHELLDETAILS
  LPSHELLDETAILS typedef ptr _SHELLDETAILS
  include poppack.inc
  if (_WIN32_IE ge _WIN32_IE_IE60SP2)
    ;* [v1_enum] *
    PERCEIVED typedef SDWORD
    PERCEIVED_TYPE_FIRST equ -3
    PERCEIVED_TYPE_CUSTOM equ -3
    PERCEIVED_TYPE_UNSPECIFIED equ -2
    PERCEIVED_TYPE_FOLDER equ -1
    PERCEIVED_TYPE_UNKNOWN equ 0
    PERCEIVED_TYPE_TEXT equ 1
    PERCEIVED_TYPE_IMAGE equ 2
    PERCEIVED_TYPE_AUDIO equ 3
    PERCEIVED_TYPE_VIDEO equ 4
    PERCEIVED_TYPE_COMPRESSED equ 5
    PERCEIVED_TYPE_DOCUMENT equ 6
    PERCEIVED_TYPE_SYSTEM equ 7
    PERCEIVED_TYPE_APPLICATION equ 8
    PERCEIVED_TYPE_GAMEMEDIA equ 9
    PERCEIVED_TYPE_CONTACTS equ 10
    PERCEIVED_TYPE_LAST equ 10
    tagPERCEIVED typedef PERCEIVED

    PERCEIVEDFLAG_UNDEFINED equ 0000h
    PERCEIVEDFLAG_SOFTCODED equ 0001h
    PERCEIVEDFLAG_HARDCODED equ 0002h
    PERCEIVEDFLAG_NATIVESUPPORT equ 0004h
    PERCEIVEDFLAG_GDIPLUS equ 0010h
    PERCEIVEDFLAG_WMSDK equ 0020h
    PERCEIVEDFLAG_ZIPFOLDER equ 0040h
    PERCEIVEDFLAG typedef DWORD
  endif
  ; _WIN32_IE_IE60SP2
  if (NTDDI_VERSION ge NTDDI_VISTA)
    COMDLG_FILTERSPEC struct
      pszName =POINTER ?
      ;* [string] *
      pszSpec =POINTER ?
      ;* [string] *
    COMDLG_FILTERSPEC ends
    _COMDLG_FILTERSPEC typedef COMDLG_FILTERSPEC
  endif
  ; NTDDI_VISTA
  KNOWNFOLDERID typedef GUID
  if 0
    ;[...]
  endif
  ; 0
  ifdef __cplusplus
    ;[...]
  else
  ; !__cplusplus
    REFKNOWNFOLDERID equ <const KNOWNFOLDERID * __MIDL_CONST>
  endif
  ; __cplusplus
  KF_REDIRECT_FLAGS typedef DWORD
  FOLDERTYPEID typedef GUID
  if 0
    ;[...]
  endif
  ; 0
  ifdef __cplusplus
    ;[...]
  else
  ; !__cplusplus
    REFFOLDERTYPEID equ <const FOLDERTYPEID * __MIDL_CONST>
  endif
  ; __cplusplus
  TASKOWNERID typedef GUID
  if 0
    ;[...]
  endif
  ; 0
  ifdef __cplusplus
    ;[...]
  else
  ; !__cplusplus
    REFTASKOWNERID equ <const TASKOWNERID * __MIDL_CONST>
  endif
  ; __cplusplus
  ELEMENTID typedef GUID
  if 0
    ;[...]
  endif
  ; 0
  ifdef __cplusplus
    ;[...]
  else
  ; !__cplusplus
    REFELEMENTID equ <const ELEMENTID * __MIDL_CONST>
  endif
  ; __cplusplus
  ifndef LF_FACESIZE
    LOGFONTA struct
      lfHeight SDWORD ?
      lfWidth SDWORD ?
      lfEscapement SDWORD ?
      lfOrientation SDWORD ?
      lfWeight SDWORD ?
      lfItalic BYTE ?
      lfUnderline BYTE ?
      lfStrikeOut BYTE ?
      lfCharSet BYTE ?
      lfOutPrecision BYTE ?
      lfClipPrecision BYTE ?
      lfQuality BYTE ?
      lfPitchAndFamily BYTE ?
      lfFaceName SBYTE 32 dup (?)
    LOGFONTA ends
    tagLOGFONTA typedef LOGFONTA
    LOGFONTW struct
      lfHeight SDWORD ?
      lfWidth SDWORD ?
      lfEscapement SDWORD ?
      lfOrientation SDWORD ?
      lfWeight SDWORD ?
      lfItalic BYTE ?
      lfUnderline BYTE ?
      lfStrikeOut BYTE ?
      lfCharSet BYTE ?
      lfOutPrecision BYTE ?
      lfClipPrecision BYTE ?
      lfQuality BYTE ?
      lfPitchAndFamily BYTE ?
      lfFaceName WORD 32 dup (?)
    LOGFONTW ends
    tagLOGFONTW typedef LOGFONTW
    LOGFONT typedef LOGFONTW
  endif
  ; LF_FACESIZE
  ;* [v1_enum] *
  SHCOLSTATE typedef SDWORD
  SHCOLSTATE_DEFAULT equ 0
  SHCOLSTATE_TYPE_STR equ 1h
  SHCOLSTATE_TYPE_INT equ 2h
  SHCOLSTATE_TYPE_DATE equ 3h
  SHCOLSTATE_TYPEMASK equ 0fh
  SHCOLSTATE_ONBYDEFAULT equ 10h
  SHCOLSTATE_SLOW equ 20h
  SHCOLSTATE_EXTENDED equ 40h
  SHCOLSTATE_SECONDARYUI equ 80h
  SHCOLSTATE_HIDDEN equ 100h
  SHCOLSTATE_PREFER_VARCMP equ 200h
  SHCOLSTATE_PREFER_FMTCMP equ 400h
  SHCOLSTATE_NOSORTBYFOLDERNESS equ 800h
  SHCOLSTATE_VIEWONLY equ 10000h
  SHCOLSTATE_BATCHREAD equ 20000h
  SHCOLSTATE_NO_GROUPBY equ 40000h
  SHCOLSTATE_FIXED_WIDTH equ 1000h
  SHCOLSTATE_NODPISCALE equ 2000h
  SHCOLSTATE_FIXED_RATIO equ 4000h
  SHCOLSTATE_DISPLAYMASK equ 0f000h
  tagSHCOLSTATE typedef SHCOLSTATE

  SHCOLSTATEF typedef DWORD
  SHCOLUMNID typedef PROPERTYKEY
  LPCSHCOLUMNID typedef ptr SHCOLUMNID
  ;* [v1_enum] *
  DEVICE_SCALE_FACTOR typedef SDWORD
  DEVICE_SCALE_FACTOR_INVALID equ 0
  SCALE_100_PERCENT equ 100
  SCALE_120_PERCENT equ 120
  SCALE_125_PERCENT equ 125
  SCALE_140_PERCENT equ 140
  SCALE_150_PERCENT equ 150
  SCALE_160_PERCENT equ 160
  SCALE_175_PERCENT equ 175
  SCALE_180_PERCENT equ 180
  SCALE_200_PERCENT equ 200
  SCALE_225_PERCENT equ 225
  SCALE_250_PERCENT equ 250
  SCALE_300_PERCENT equ 300
  SCALE_350_PERCENT equ 350
  SCALE_400_PERCENT equ 400
  SCALE_450_PERCENT equ 450
  SCALE_500_PERCENT equ 500

  if _MSC_VER ge 1200
  endif
  externdef __MIDL_itf_shtypes_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_shtypes_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
  ;* Additional Prototypes for ALL interfaces *
  ;* end of Additional Prototypes *
  ifdef __cplusplus
    ;[...]
  endif
endif
