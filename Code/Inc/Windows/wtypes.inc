;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\wtypes.h
;             Created on (UTC) 22/05/2024 17:57:06
;             Last modified on (UTC) 21/02/2024 18:18:14

ifndef __REQUIRED_RPCNDR_H_VERSION__
  __REQUIRED_RPCNDR_H_VERSION__ equ 501
endif
ifndef __REQUIRED_RPCSAL_H_VERSION__
  __REQUIRED_RPCSAL_H_VERSION__ equ 100
endif
include rpc.inc
include rpcndr.inc
ifndef __RPCNDR_H_VERSION__
  .err <this stub requires an updated version of < rpcndr.h >>
endif
ifndef __wtypes_h__
  __wtypes_h__ equ <>
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
  include wtypesbase.inc
  ifdef __cplusplus
    ;[...]
  endif
  if (_MSC_VER ge 1020)
  endif
  if _MSC_VER ge 1200
  endif
  externdef __MIDL_itf_wtypes_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_wtypes_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
  ifndef __IWinTypes_INTERFACE_DEFINED__
    __IWinTypes_INTERFACE_DEFINED__ equ <>
    RemHGLOBAL struct
      fNullHGlobal LONG ?
      cbData ULONG ?
      data byte 1 dup (?)
    RemHGLOBAL ends
    tagRemHGLOBAL typedef RemHGLOBAL
    RemHMETAFILEPICT struct
      mm_ LONG ?
      xExt LONG ?
      yExt LONG ?
      cbData ULONG ?
      data byte 1 dup (?)
    RemHMETAFILEPICT ends
    tagRemHMETAFILEPICT typedef RemHMETAFILEPICT
    RemHENHMETAFILE struct
      cbData ULONG ?
      data byte 1 dup (?)
    RemHENHMETAFILE ends
    tagRemHENHMETAFILE typedef RemHENHMETAFILE
    RemHBITMAP struct
      cbData ULONG ?
      data byte 1 dup (?)
    RemHBITMAP ends
    tagRemHBITMAP typedef RemHBITMAP
    RemHPALETTE struct
      cbData ULONG ?
      data byte 1 dup (?)
    RemHPALETTE ends
    tagRemHPALETTE typedef RemHPALETTE
    RemHBRUSH struct
      cbData ULONG ?
      data byte 1 dup (?)
    RemHBRUSH ends
    tagRemBRUSH typedef RemHBRUSH
    if  not Defined(_WIN32) and  not Defined(_MPPC_)
      ;[...]
    endif
    ifndef _PALETTEENTRY_DEFINED
      _PALETTEENTRY_DEFINED equ <>
      PALETTEENTRY struct
        peRed BYTE ?
        peGreen BYTE ?
        peBlue BYTE ?
        peFlags BYTE ?
      PALETTEENTRY ends
      tagPALETTEENTRY typedef PALETTEENTRY
      PPALETTEENTRY typedef ptr tagPALETTEENTRY
      LPPALETTEENTRY typedef ptr tagPALETTEENTRY
    endif
    ifndef _LOGPALETTE_DEFINED
      _LOGPALETTE_DEFINED equ <>
      LOGPALETTE struct
        palVersion WORD ?
        palNumEntries WORD ?
        palPalEntry PALETTEENTRY 1 dup (<>)
      LOGPALETTE ends
      tagLOGPALETTE typedef LOGPALETTE
      PLOGPALETTE typedef ptr tagLOGPALETTE
      LPLOGPALETTE typedef ptr tagLOGPALETTE
    endif
    ifndef _WINDEF_
      LPCRECTL typedef ptr RECTL
      RECT struct
        left LONG ?
        top LONG ?
        right LONG ?
        bottom LONG ?
      RECT ends
      tagRECT typedef RECT
      PRECT typedef ptr tagRECT
      LPRECT typedef ptr tagRECT
      LPCRECT typedef ptr RECT
    endif
    if 0
      ;[...]
    endif
    ifndef _ROTFLAGS_DEFINED
      _ROTFLAGS_DEFINED equ <>
      ROTFLAGS_REGISTRATIONKEEPSALIVE equ 1h
      ROTFLAGS_ALLOWANYCLIENT equ 2h
    endif
    ifndef _ROT_COMPARE_MAX_DEFINED
      _ROT_COMPARE_MAX_DEFINED equ <>
      ROT_COMPARE_MAX equ 2048
    endif
    DVASPECT typedef SDWORD
    DVASPECT_CONTENT equ 1
    DVASPECT_THUMBNAIL equ 2
    DVASPECT_ICON equ 4
    DVASPECT_DOCPRINT equ 8
    tagDVASPECT typedef DVASPECT

    STGC typedef SDWORD
    STGC_DEFAULT equ 0
    STGC_OVERWRITE equ 1
    STGC_ONLYIFCURRENT equ 2
    STGC_DANGEROUSLYCOMMITMERELYTODISKCACHE equ 4
    STGC_CONSOLIDATE equ 8
    tagSTGC typedef STGC

    STGMOVE typedef SDWORD
    STGMOVE_MOVE equ 0
    STGMOVE_COPY equ 1
    STGMOVE_SHALLOWCOPY equ 2
    tagSTGMOVE typedef STGMOVE

    STATFLAG typedef SDWORD
    STATFLAG_DEFAULT equ 0
    STATFLAG_NONAME equ 1
    STATFLAG_NOOPEN equ 2
    tagSTATFLAG typedef STATFLAG

    HCONTEXT typedef ptr
    ifndef _LCID_DEFINED
      _LCID_DEFINED equ <>
      LCID typedef DWORD
    endif
    ifndef _LANGID_DEFINED
      _LANGID_DEFINED equ <>
      LANGID typedef USHORT
    endif
    WDT_INPROC_CALL equ (48746457h)
    WDT_REMOTE_CALL equ (52746457h)
    WDT_INPROC64_CALL equ (50746457h)
    userCLIPFORMAT struct
      fContext LONG ?
      union u
        dwValue DWORD ?
        pwszName POINTER ?
      ends
    userCLIPFORMAT ends
    _userCLIPFORMAT typedef userCLIPFORMAT
    wireCLIPFORMAT typedef ptr userCLIPFORMAT
    CLIPFORMAT typedef WORD
    GDI_NONREMOTE struct
      fContext LONG ?
      union u
        hInproc LONG ?
        hRemote POINTER ?
      ends
    GDI_NONREMOTE ends
    _GDI_NONREMOTE typedef GDI_NONREMOTE
    userHGLOBAL struct
      fContext LONG ?
      union u
        hInproc LONG ?
        hRemote POINTER ?
        hInproc64 SQWORD ?
      ends
    userHGLOBAL ends
    _userHGLOBAL typedef userHGLOBAL
    wireHGLOBAL typedef ptr userHGLOBAL
    userHMETAFILE struct
      fContext LONG ?
      union u
        hInproc LONG ?
        hRemote POINTER ?
        hInproc64 SQWORD ?
      ends
    userHMETAFILE ends
    _userHMETAFILE typedef userHMETAFILE
    remoteMETAFILEPICT struct
      mm_ LONG ?
      xExt LONG ?
      yExt LONG ?
      hMF POINTER ?
    remoteMETAFILEPICT ends
    _remoteMETAFILEPICT typedef remoteMETAFILEPICT
    userHMETAFILEPICT struct
      fContext LONG ?
      union u
        hInproc LONG ?
        hRemote POINTER ?
        hInproc64 SQWORD ?
      ends
    userHMETAFILEPICT ends
    _userHMETAFILEPICT typedef userHMETAFILEPICT
    userHENHMETAFILE struct
      fContext LONG ?
      union u
        hInproc LONG ?
        hRemote POINTER ?
        hInproc64 SQWORD ?
      ends
    userHENHMETAFILE ends
    _userHENHMETAFILE typedef userHENHMETAFILE
    userBITMAP struct
      bmType LONG ?
      bmWidth LONG ?
      bmHeight LONG ?
      bmWidthBytes LONG ?
      bmPlanes WORD ?
      bmBitsPixel WORD ?
      cbSize ULONG ?
      pBuffer byte 1 dup (?)
    userBITMAP ends
    _userBITMAP typedef userBITMAP
    userHBITMAP struct
      fContext LONG ?
      union u
        hInproc LONG ?
        hRemote POINTER ?
        hInproc64 SQWORD ?
      ends
    userHBITMAP ends
    _userHBITMAP typedef userHBITMAP
    userHPALETTE struct
      fContext LONG ?
      union u
        hInproc LONG ?
        hRemote POINTER ?
        hInproc64 SQWORD ?
      ends
    userHPALETTE ends
    _userHPALETTE typedef userHPALETTE
    RemotableHandle struct
      fContext LONG ?
      union u
        hInproc LONG ?
        hRemote LONG ?
      ends
    RemotableHandle ends
    _RemotableHandle typedef RemotableHandle
    wireHWND typedef ptr RemotableHandle
    wireHMENU typedef ptr RemotableHandle
    wireHACCEL typedef ptr RemotableHandle
    wireHBRUSH typedef ptr RemotableHandle
    wireHFONT typedef ptr RemotableHandle
    wireHDC typedef ptr RemotableHandle
    wireHICON typedef ptr RemotableHandle
    wireHRGN typedef ptr RemotableHandle
    wireHMONITOR typedef ptr RemotableHandle
    if 0
      ;[...]
    endif
    ifndef _TEXTMETRIC_DEFINED
      _TEXTMETRIC_DEFINED equ <>
      TEXTMETRICW struct 4
        tmHeight LONG ?
        tmAscent LONG ?
        tmDescent LONG ?
        tmInternalLeading LONG ?
        tmExternalLeading LONG ?
        tmAveCharWidth LONG ?
        tmMaxCharWidth LONG ?
        tmWeight LONG ?
        tmOverhang LONG ?
        tmDigitizedAspectX LONG ?
        tmDigitizedAspectY LONG ?
        tmFirstChar WCHAR ?
        tmLastChar WCHAR ?
        tmDefaultChar WCHAR ?
        tmBreakChar WCHAR ?
        tmItalic BYTE ?
        tmUnderlined BYTE ?
        tmStruckOut BYTE ?
        tmPitchAndFamily BYTE ?
        tmCharSet BYTE ?
      TEXTMETRICW ends
      tagTEXTMETRICW typedef TEXTMETRICW
      PTEXTMETRICW typedef ptr tagTEXTMETRICW
      LPTEXTMETRICW typedef ptr tagTEXTMETRICW
    endif
    ifndef _WIN32
      ;[...]
    endif
    wireHBITMAP typedef ptr userHBITMAP
    wireHPALETTE typedef ptr userHPALETTE
    wireHENHMETAFILE typedef ptr userHENHMETAFILE
    wireHMETAFILE typedef ptr userHMETAFILE
    wireHMETAFILEPICT typedef ptr userHMETAFILEPICT
    if 0
      ;[...]
    endif
    HMETAFILEPICT typedef ptr
    externdef IWinTypes_v0_1_c_ifspec:RPC_IF_HANDLE
    externdef IWinTypes_v0_1_s_ifspec:RPC_IF_HANDLE
  endif
  if (_MSC_VER ge 800)
    if _MSC_VER ge 1200
    endif
  endif
  DATE typedef REAL8
  ifndef _tagCY_DEFINED
    _tagCY_DEFINED equ <>
    _CY_DEFINED equ <>
    if 0
      ;[...]
    else
      CY union
        struct
          Lo ULONG ?
          Hi LONG ?
        ends
        int64 LONGLONG ?
      CY ends
      tagCY typedef CY
    endif
  endif
  LPCY typedef ptr CY
  if 0
    ;[...]
  else
    DECIMAL struct
      wReserved USHORT ?
      union
        struct
          scale BYTE ?
          sign BYTE ?
        ends
        signscale USHORT ?
      ends
      Hi32 ULONG ?
      union
        struct
          Lo32 ULONG ?
          Mid32 ULONG ?
        ends
        Lo64 ULONGLONG ?
      ends
    DECIMAL ends
    tagDEC typedef DECIMAL
    DECIMAL_NEG equ (80h)
    DECIMAL_SETZERO macro dec_
      exitm <{ (dec_).Lo64 = 0 ; (dec_).Hi32 = 0 ; (dec_).signscale = 0 ; }>
    endm
  endif
  LPDECIMAL typedef ptr DECIMAL
  if (_MSC_VER ge 800)
    if _MSC_VER ge 1200
    else
    endif
  endif
  wireBSTR typedef ptr FLAGGED_WORD_BLOB
  ifndef _PREFAST_
    BSTR typedef ptr OLECHAR
  else
    ;[...]
  endif
  LPBSTR typedef ptr BSTR
  VARIANT_BOOL typedef SWORD
  ifndef _tagBSTRBLOB_DEFINED
    _tagBSTRBLOB_DEFINED equ <>
    BSTRBLOB struct
      cbSize ULONG ?
      pData POINTER ?
    BSTRBLOB ends
    tagBSTRBLOB typedef BSTRBLOB
    LPBSTRBLOB typedef ptr tagBSTRBLOB
  endif
  VARIANT_TRUE equ ((VARIANT_BOOL) - 1)
  VARIANT_FALSE equ ((VARIANT_BOOL) 0)
  CLIPDATA struct
    cbSize ULONG ?
    ulClipFmt LONG ?
    pClipData POINTER ?
  CLIPDATA ends
  tagCLIPDATA typedef CLIPDATA
  CBPCLIPDATA macro clipdata
    exitm <((clipdata).cbSize - sizeof((clipdata).ulClipFmt))>
  endm
  VARTYPE typedef WORD
  VARENUM typedef SDWORD
  VT_EMPTY equ 0
  VT_NULL equ 1
  VT_I2 equ 2
  VT_I4 equ 3
  VT_R4 equ 4
  VT_R8 equ 5
  VT_CY equ 6
  VT_DATE equ 7
  VT_BSTR equ 8
  VT_DISPATCH equ 9
  VT_ERROR equ 10
  VT_BOOL equ 11
  VT_VARIANT equ 12
  VT_UNKNOWN equ 13
  VT_DECIMAL equ 14
  VT_I1 equ 16
  VT_UI1 equ 17
  VT_UI2 equ 18
  VT_UI4 equ 19
  VT_I8 equ 20
  VT_UI8 equ 21
  VT_INT equ 22
  VT_UINT equ 23
  VT_VOID equ 24
  VT_HRESULT equ 25
  VT_PTR equ 26
  VT_SAFEARRAY equ 27
  VT_CARRAY equ 28
  VT_USERDEFINED equ 29
  VT_LPSTR equ 30
  VT_LPWSTR equ 31
  VT_RECORD equ 36
  VT_INT_PTR equ 37
  VT_UINT_PTR equ 38
  VT_FILETIME equ 64
  VT_BLOB equ 65
  VT_STREAM equ 66
  VT_STORAGE equ 67
  VT_STREAMED_OBJECT equ 68
  VT_STORED_OBJECT equ 69
  VT_BLOB_OBJECT equ 70
  VT_CF equ 71
  VT_CLSID equ 72
  VT_VERSIONED_STREAM equ 73
  VT_BSTR_BLOB equ 0fffh
  VT_VECTOR equ 1000h
  VT_ARRAY equ 2000h
  VT_BYREF equ 4000h
  VT_RESERVED equ 8000h
  VT_ILLEGAL equ 0ffffh
  VT_ILLEGALMASKED equ 0fffh
  VT_TYPEMASK equ 0fffh

  PROPID typedef ULONG
  ifndef PROPERTYKEY_DEFINED
    PROPERTYKEY_DEFINED equ <>
    PROPERTYKEY struct
      fmtid GUID <>
      pid DWORD ?
    PROPERTYKEY ends
    _tagpropertykey typedef PROPERTYKEY
  endif
  CSPLATFORM struct
    dwPlatformId DWORD ?
    dwVersionHi DWORD ?
    dwVersionLo DWORD ?
    dwProcessorArch DWORD ?
  CSPLATFORM ends
  tagCSPLATFORM typedef CSPLATFORM
  QUERYCONTEXT struct
    dwContext DWORD ?
    Platform CSPLATFORM <>
    Locale LCID ?
    dwVersionHi DWORD ?
    dwVersionLo DWORD ?
  QUERYCONTEXT ends
  tagQUERYCONTEXT typedef QUERYCONTEXT
  TYSPEC typedef SDWORD
  TYSPEC_CLSID equ 0
  TYSPEC_FILEEXT equ 1
  TYSPEC_MIMETYPE equ 2
  TYSPEC_FILENAME equ 3
  TYSPEC_PROGID equ 4
  TYSPEC_PACKAGENAME equ 5
  TYSPEC_OBJECTID equ 6
  tagTYSPEC typedef TYSPEC

  uCLSSPEC struct
    tyspec DWORD ?
    union tagged_union
      clsid CLSID <>
      pFileExt LPOLESTR ?
      pMimeType LPOLESTR ?
      pProgId LPOLESTR ?
      pFileName LPOLESTR ?
      struct ByName
        pPackageName LPOLESTR ?
        PolicyId GUID <>
      ends
      struct ByObjectId
        ObjectId GUID <>
        PolicyId GUID <>
      ends
    ends
  uCLSSPEC ends
  __MIDL___MIDL_itf_wtypes_0000_0001_0001 typedef uCLSSPEC
  if _MSC_VER ge 1200
  endif
  externdef __MIDL_itf_wtypes_0000_0001_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_wtypes_0000_0001_v0_0_s_ifspec:RPC_IF_HANDLE
  ifdef __cplusplus
    ;[...]
  endif
endif
