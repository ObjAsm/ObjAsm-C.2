;Include file created by h2inc+ version C.2.0 on (UTC) 19/05/2024 07:52:23
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\propidl.h\propidl.h
;             Created on (UTC) 06/04/2024 06:15:57
;             Last modified on (UTC) 21/02/2024 18:18:10

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
ifndef COM_NO_WINDOWS_H
  include windows.inc
  include ole2.inc
endif
ifndef __propidl_h__
  __propidl_h__ equ <>
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
  ifndef __IPropertyStorage_FWD_DEFINED__
    __IPropertyStorage_FWD_DEFINED__ equ <>
  endif
  ifndef __IPropertySetStorage_FWD_DEFINED__
    __IPropertySetStorage_FWD_DEFINED__ equ <>
  endif
  ifndef __IEnumSTATPROPSTG_FWD_DEFINED__
    __IEnumSTATPROPSTG_FWD_DEFINED__ equ <>
  endif
  ifndef __IEnumSTATPROPSETSTG_FWD_DEFINED__
    __IEnumSTATPROPSETSTG_FWD_DEFINED__ equ <>
  endif
  include objidl.inc
  include oaidl.inc
  ifdef __cplusplus
    ;[...]
  endif
  if (_MSC_VER ge 800)
    if _MSC_VER ge 1200
    endif
  endif
  if (_MSC_VER ge 1020)
  endif
  include winapifamily.inc
  ifndef _PROPIDLBASE_
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      VERSIONEDSTREAM struct
        guidVersion GUID <>
        pStream POINTER ?
      VERSIONEDSTREAM ends
      tagVersionedStream typedef VERSIONEDSTREAM
      LPVERSIONEDSTREAM typedef ptr tagVersionedStream
      PROPSETFLAG_DEFAULT equ (0)
      PROPSETFLAG_NONSIMPLE equ (1)
      PROPSETFLAG_ANSI equ (2)
      PROPSETFLAG_UNBUFFERED equ (4)
      PROPSETFLAG_CASE_SENSITIVE equ (8)
      PROPSET_BEHAVIOR_CASE_SENSITIVE equ (1)
      ifdef MIDL_PASS
        ;[...]
      else
        PROPVARIANT typedef tagPROPVARIANT
      endif
      CAC struct
        cElems ULONG ?
        pElems POINTER ?
      CAC ends
      tagCAC typedef CAC
      CAUB struct
        cElems ULONG ?
        pElems POINTER ?
      CAUB ends
      tagCAUB typedef CAUB
      CAI struct
        cElems ULONG ?
        pElems POINTER ?
      CAI ends
      tagCAI typedef CAI
      CAUI struct
        cElems ULONG ?
        pElems POINTER ?
      CAUI ends
      tagCAUI typedef CAUI
      CAL struct
        cElems ULONG ?
        pElems POINTER ?
      CAL ends
      tagCAL typedef CAL
      CAUL struct
        cElems ULONG ?
        pElems POINTER ?
      CAUL ends
      tagCAUL typedef CAUL
      CAFLT struct
        cElems ULONG ?
        pElems POINTER ?
      CAFLT ends
      tagCAFLT typedef CAFLT
      CADBL struct
        cElems ULONG ?
        pElems POINTER ?
      CADBL ends
      tagCADBL typedef CADBL
      CACY struct
        cElems ULONG ?
        pElems POINTER ?
      CACY ends
      tagCACY typedef CACY
      CADATE struct
        cElems ULONG ?
        pElems POINTER ?
      CADATE ends
      tagCADATE typedef CADATE
      CABSTR struct
        cElems ULONG ?
        pElems POINTER ?
      CABSTR ends
      tagCABSTR typedef CABSTR
      CABSTRBLOB struct
        cElems ULONG ?
        pElems POINTER ?
      CABSTRBLOB ends
      tagCABSTRBLOB typedef CABSTRBLOB
      CABOOL struct
        cElems ULONG ?
        pElems POINTER ?
      CABOOL ends
      tagCABOOL typedef CABOOL
      CASCODE struct
        cElems ULONG ?
        pElems POINTER ?
      CASCODE ends
      tagCASCODE typedef CASCODE
      CAPROPVARIANT struct
        cElems ULONG ?
        pElems POINTER ?
      CAPROPVARIANT ends
      tagCAPROPVARIANT typedef CAPROPVARIANT
      CAH struct
        cElems ULONG ?
        pElems POINTER ?
      CAH ends
      tagCAH typedef CAH
      CAUH struct
        cElems ULONG ?
        pElems POINTER ?
      CAUH ends
      tagCAUH typedef CAUH
      CALPSTR struct
        cElems ULONG ?
        pElems POINTER ?
      CALPSTR ends
      tagCALPSTR typedef CALPSTR
      CALPWSTR struct
        cElems ULONG ?
        pElems POINTER ?
      CALPWSTR ends
      tagCALPWSTR typedef CALPWSTR
      CAFILETIME struct
        cElems ULONG ?
        pElems POINTER ?
      CAFILETIME ends
      tagCAFILETIME typedef CAFILETIME
      CACLIPDATA struct
        cElems ULONG ?
        pElems POINTER ?
      CACLIPDATA ends
      tagCACLIPDATA typedef CACLIPDATA
      CACLSID struct
        cElems ULONG ?
        pElems POINTER ?
      CACLSID ends
      tagCACLSID typedef CACLSID
      ifdef MIDL_PASS
        ;[...]
      else
        PROPVAR_PAD1 typedef WORD
        PROPVAR_PAD2 typedef WORD
        PROPVAR_PAD3 typedef WORD
        tag_inner_PROPVARIANT equ <>
      endif
      if  not Defined(_MSC_EXTENSIONS)
      else
        ifndef MIDL_PASS
          tagPROPVARIANT struct
            union
            endif
            struct
              vt VARTYPE ?
              wReserved1 PROPVAR_PAD1 ?
              wReserved2 PROPVAR_PAD2 ?
              wReserved3 PROPVAR_PAD3 ?
              union
                cVal CHAR ?
                bVal UCHAR ?
                iVal SHORT_ ?
                uiVal USHORT ?
                lVal LONG ?
                ulVal ULONG ?
                intVal INT_ ?
                uintVal UINT ?
                hVal LARGE_INTEGER <>
                uhVal ULARGE_INTEGER <>
                fltVal FLOAT ?
                dblVal DOUBLE ?
                boolVal VARIANT_BOOL ?
                __OBSOLETE__VARIANT_BOOL VARIANT_BOOL ?
                scode SCODE ?
                cyVal CY <>
                date DATE ?
                filetime FILETIME <>
                puuid POINTER ?
                pclipdata POINTER ?
                bstrVal BSTR ?
                bstrblobVal BSTRBLOB <>
                blob BLOB <>
                pszVal LPSTR ?
                pwszVal LPWSTR ?
                punkVal POINTER ?
                pdispVal POINTER ?
                pStream POINTER ?
                pStorage POINTER ?
                pVersionedStream LPVERSIONEDSTREAM ?
                parray LPSAFEARRAY ?
                cac CAC <>
                caub CAUB <>
                cai CAI <>
                caui CAUI <>
                cal CAL <>
                caul CAUL <>
                cah CAH <>
                cauh CAUH <>
                caflt CAFLT <>
                cadbl CADBL <>
                cabool CABOOL <>
                cascode CASCODE <>
                cacy CACY <>
                cadate CADATE <>
                cafiletime CAFILETIME <>
                cauuid CACLSID <>
                caclipdata CACLIPDATA <>
                cabstr CABSTR <>
                cabstrblob CABSTRBLOB <>
                calpstr CALPSTR <>
                calpwstr CALPWSTR <>
                capropvar CAPROPVARIANT <>
                pcVal POINTER ?
                pbVal POINTER ?
                piVal POINTER ?
                puiVal POINTER ?
                plVal POINTER ?
                pulVal POINTER ?
                pintVal POINTER ?
                puintVal POINTER ?
                pfltVal POINTER ?
                pdblVal POINTER ?
                pboolVal POINTER ?
                pdecVal POINTER ?
                pscode POINTER ?
                pcyVal POINTER ?
                pdate POINTER ?
                pbstrVal POINTER ?
                ppunkVal POINTER ?
                ppdispVal POINTER ?
                pparray POINTER ?
                pvarVal POINTER ?
              ends
            ends
            ifndef MIDL_PASS
              decVal DECIMAL <>
            ends
          tagPROPVARIANT ends
        endif
      endif
      ifdef MIDL_PASS
        ;[...]
      else
        LPPROPVARIANT typedef ptr tagPROPVARIANT
        ifndef _REFPROPVARIANT_DEFINED
          _REFPROPVARIANT_DEFINED equ <>
          ifdef __cplusplus
            ;[...]
          else
            REFPROPVARIANT equ <const PROPVARIANT * __MIDL_CONST>
          endif
        endif
      endif
      PID_DICTIONARY equ (0)
      PID_CODEPAGE equ (1h)
      PID_FIRST_USABLE equ (2h)
      PID_FIRST_NAME_DEFAULT equ (0fffh)
      PID_LOCALE equ (80000000h)
      PID_MODIFY_TIME equ (80000001h)
      PID_SECURITY equ (80000002h)
      PID_BEHAVIOR equ (80000003h)
      PID_ILLEGAL equ (0ffffffffh)
      PID_MIN_READONLY equ (80000000h)
      PID_MAX_READONLY equ (0bfffffffh)
      PRSPEC_INVALID equ (0ffffffffh)
      PRSPEC_LPWSTR equ (0)
      PRSPEC_PROPID equ (1)
      PROPSPEC struct
        ulKind ULONG ?
        union
          propid PROPID ?
          lpwstr LPOLESTR ?
        ends
      PROPSPEC ends
      tagPROPSPEC typedef PROPSPEC
      STATPROPSTG struct
        lpwstrName LPOLESTR ?
        propid PROPID ?
        vt VARTYPE ?
      STATPROPSTG ends
      tagSTATPROPSTG typedef STATPROPSTG
      PROPSETHDR_OSVER_KIND macro dwOSVer
        exitm <HIWORD((dwOSVer))>
      endm
      PROPSETHDR_OSVER_MAJOR macro dwOSVer
        exitm <LOBYTE(LOWORD((dwOSVer)))>
      endm
      PROPSETHDR_OSVER_MINOR macro dwOSVer
        exitm <HIBYTE(LOWORD((dwOSVer)))>
      endm
      PROPSETHDR_OSVERSION_UNKNOWN equ 0FFFFFFFFh
      STATPROPSETSTG struct
        fmtid FMTID <>
        clsid CLSID <>
        grfFlags DWORD ?
        mtime FILETIME <>
        ctime FILETIME <>
        atime FILETIME <>
        dwOSVersion DWORD ?
      STATPROPSETSTG ends
      tagSTATPROPSETSTG typedef STATPROPSETSTG
      externdef __MIDL_itf_propidl_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_propidl_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IPropertyStorage_INTERFACE_DEFINED__
        __IPropertyStorage_INTERFACE_DEFINED__ equ <>
        externdef IID_IPropertyStorage:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IPropertyStorageVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IPropertyStorageVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IPropertyStorage, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IPropertyStorage
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IPropertyStorage
            DECLSPEC_XFGVIRT(IPropertyStorage, ReadMultiple)
            STD_METHOD ReadMultiple, :ptr IPropertyStorage, :ULONG, :ptr PROPSPEC, :ptr PROPVARIANT
            DECLSPEC_XFGVIRT(IPropertyStorage, WriteMultiple)
            STD_METHOD WriteMultiple, :ptr IPropertyStorage, :ULONG, :ptr PROPSPEC, :ptr PROPVARIANT, :PROPID
            DECLSPEC_XFGVIRT(IPropertyStorage, DeleteMultiple)
            STD_METHOD DeleteMultiple, :ptr IPropertyStorage, :ULONG, :ptr PROPSPEC
            DECLSPEC_XFGVIRT(IPropertyStorage, ReadPropertyNames)
            STD_METHOD ReadPropertyNames, :ptr IPropertyStorage, :ULONG, :ptr PROPID, :ptr LPOLESTR
            DECLSPEC_XFGVIRT(IPropertyStorage, WritePropertyNames)
            STD_METHOD WritePropertyNames, :ptr IPropertyStorage, :ULONG, :ptr PROPID, :ptr LPOLESTR
            DECLSPEC_XFGVIRT(IPropertyStorage, DeletePropertyNames)
            STD_METHOD DeletePropertyNames, :ptr IPropertyStorage, :ULONG, :ptr PROPID
            DECLSPEC_XFGVIRT(IPropertyStorage, Commit)
            STD_METHOD Commit, :ptr IPropertyStorage, :DWORD
            DECLSPEC_XFGVIRT(IPropertyStorage, Revert)
            STD_METHOD Revert, :ptr IPropertyStorage
            DECLSPEC_XFGVIRT(IPropertyStorage, Enum)
            STD_METHOD Enum, :ptr IPropertyStorage, :ptr ptr IEnumSTATPROPSTG
            DECLSPEC_XFGVIRT(IPropertyStorage, SetTimes)
            STD_METHOD SetTimes, :ptr IPropertyStorage, :ptr FILETIME, :ptr FILETIME, :ptr FILETIME
            DECLSPEC_XFGVIRT(IPropertyStorage, SetClass)
            STD_METHOD SetClass, :ptr IPropertyStorage, :REFCLSID
            DECLSPEC_XFGVIRT(IPropertyStorage, Stat)
            STD_METHOD Stat, :ptr IPropertyStorage, :ptr STATPROPSETSTG
            ??Interface equ <>
            END_INTERFACE
          IPropertyStorageVtbl ends
          IPropertyStorage struct
            lpVtbl POINTER ?
          IPropertyStorage ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IPropertySetStorage_INTERFACE_DEFINED__
        __IPropertySetStorage_INTERFACE_DEFINED__ equ <>
        LPPROPERTYSETSTORAGE typedef ptr IPropertySetStorage
        externdef IID_IPropertySetStorage:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IPropertySetStorageVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IPropertySetStorageVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IPropertySetStorage, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IPropertySetStorage
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IPropertySetStorage
            DECLSPEC_XFGVIRT(IPropertySetStorage, Create)
            STD_METHOD Create, :ptr IPropertySetStorage, :REFFMTID, :ptr CLSID, :DWORD, :DWORD, :ptr ptr IPropertyStorage
            DECLSPEC_XFGVIRT(IPropertySetStorage, Open)
            STD_METHOD Open, :ptr IPropertySetStorage, :REFFMTID, :DWORD, :ptr ptr IPropertyStorage
            DECLSPEC_XFGVIRT(IPropertySetStorage, Delete)
            STD_METHOD Delete, :ptr IPropertySetStorage, :REFFMTID
            DECLSPEC_XFGVIRT(IPropertySetStorage, Enum)
            STD_METHOD Enum, :ptr IPropertySetStorage, :ptr ptr IEnumSTATPROPSETSTG
            ??Interface equ <>
            END_INTERFACE
          IPropertySetStorageVtbl ends
          IPropertySetStorage struct
            lpVtbl POINTER ?
          IPropertySetStorage ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
      endif
      ifndef __IEnumSTATPROPSTG_INTERFACE_DEFINED__
        __IEnumSTATPROPSTG_INTERFACE_DEFINED__ equ <>
        LPENUMSTATPROPSTG typedef ptr IEnumSTATPROPSTG
        externdef IID_IEnumSTATPROPSTG:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IEnumSTATPROPSTGVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEnumSTATPROPSTGVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IEnumSTATPROPSTG, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IEnumSTATPROPSTG
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IEnumSTATPROPSTG
            DECLSPEC_XFGVIRT(IEnumSTATPROPSTG, Next)
            STD_METHOD Next, :ptr IEnumSTATPROPSTG, :ULONG, :ptr STATPROPSTG, :ptr ULONG
            DECLSPEC_XFGVIRT(IEnumSTATPROPSTG, Skip)
            STD_METHOD Skip, :ptr IEnumSTATPROPSTG, :ULONG
            DECLSPEC_XFGVIRT(IEnumSTATPROPSTG, Reset)
            STD_METHOD Reset, :ptr IEnumSTATPROPSTG
            DECLSPEC_XFGVIRT(IEnumSTATPROPSTG, Clone)
            STD_METHOD Clone, :ptr IEnumSTATPROPSTG, :ptr ptr IEnumSTATPROPSTG
            ??Interface equ <>
            END_INTERFACE
          IEnumSTATPROPSTGVtbl ends
          IEnumSTATPROPSTG struct
            lpVtbl POINTER ?
          IEnumSTATPROPSTG ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
        IEnumSTATPROPSTG_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumSTATPROPSTG, :ULONG, :ptr STATPROPSTG, :ptr ULONG
        IEnumSTATPROPSTG_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      endif
      ifndef __IEnumSTATPROPSETSTG_INTERFACE_DEFINED__
        __IEnumSTATPROPSETSTG_INTERFACE_DEFINED__ equ <>
        LPENUMSTATPROPSETSTG typedef ptr IEnumSTATPROPSETSTG
        externdef IID_IEnumSTATPROPSETSTG:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IEnumSTATPROPSETSTGVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEnumSTATPROPSETSTGVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            STD_METHOD QueryInterface, :ptr IEnumSTATPROPSETSTG, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IEnumSTATPROPSETSTG
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IEnumSTATPROPSETSTG
            DECLSPEC_XFGVIRT(IEnumSTATPROPSETSTG, Next)
            STD_METHOD Next, :ptr IEnumSTATPROPSETSTG, :ULONG, :ptr STATPROPSETSTG, :ptr ULONG
            DECLSPEC_XFGVIRT(IEnumSTATPROPSETSTG, Skip)
            STD_METHOD Skip, :ptr IEnumSTATPROPSETSTG, :ULONG
            DECLSPEC_XFGVIRT(IEnumSTATPROPSETSTG, Reset)
            STD_METHOD Reset, :ptr IEnumSTATPROPSETSTG
            DECLSPEC_XFGVIRT(IEnumSTATPROPSETSTG, Clone)
            STD_METHOD Clone, :ptr IEnumSTATPROPSETSTG, :ptr ptr IEnumSTATPROPSETSTG
            ??Interface equ <>
            END_INTERFACE
          IEnumSTATPROPSETSTGVtbl ends
          IEnumSTATPROPSETSTG struct
            lpVtbl POINTER ?
          IEnumSTATPROPSETSTG ends
          ifdef COBJMACROS
            ;[...]
          endif
        endif
        IEnumSTATPROPSETSTG_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumSTATPROPSETSTG, :ULONG, :ptr STATPROPSETSTG, :ptr ULONG
        IEnumSTATPROPSETSTG_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      endif
      LPPROPERTYSTORAGE typedef ptr IPropertyStorage
    endif
    _PROPIDLBASE_ equ <>
  endif
  include coml2api.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    PIDDI_THUMBNAIL equ 00000002h
    PIDSI_TITLE equ 00000002h
    PIDSI_SUBJECT equ 00000003h
    PIDSI_AUTHOR equ 00000004h
    PIDSI_KEYWORDS equ 00000005h
    PIDSI_COMMENTS equ 00000006h
    PIDSI_TEMPLATE equ 00000007h
    PIDSI_LASTAUTHOR equ 00000008h
    PIDSI_REVNUMBER equ 00000009h
    PIDSI_EDITTIME equ 0000000ah
    PIDSI_LASTPRINTED equ 0000000bh
    PIDSI_CREATE_DTM equ 0000000ch
    PIDSI_LASTSAVE_DTM equ 0000000dh
    PIDSI_PAGECOUNT equ 0000000eh
    PIDSI_WORDCOUNT equ 0000000fh
    PIDSI_CHARCOUNT equ 00000010h
    PIDSI_THUMBNAIL equ 00000011h
    PIDSI_APPNAME equ 00000012h
    PIDSI_DOC_SECURITY equ 00000013h
    PIDDSI_CATEGORY equ 00000002h
    PIDDSI_PRESFORMAT equ 00000003h
    PIDDSI_BYTECOUNT equ 00000004h
    PIDDSI_LINECOUNT equ 00000005h
    PIDDSI_PARCOUNT equ 00000006h
    PIDDSI_SLIDECOUNT equ 00000007h
    PIDDSI_NOTECOUNT equ 00000008h
    PIDDSI_HIDDENCOUNT equ 00000009h
    PIDDSI_MMCLIPCOUNT equ 0000000Ah
    PIDDSI_SCALE equ 0000000Bh
    PIDDSI_HEADINGPAIR equ 0000000Ch
    PIDDSI_DOCPARTS equ 0000000Dh
    PIDDSI_MANAGER equ 0000000Eh
    PIDDSI_COMPANY equ 0000000Fh
    PIDDSI_LINKSDIRTY equ 00000010h
    PIDMSI_EDITOR equ 00000002h
    PIDMSI_SUPPLIER equ 00000003h
    PIDMSI_SOURCE equ 00000004h
    PIDMSI_SEQUENCE_NO equ 00000005h
    PIDMSI_PROJECT equ 00000006h
    PIDMSI_STATUS equ 00000007h
    PIDMSI_OWNER equ 00000008h
    PIDMSI_RATING equ 00000009h
    PIDMSI_PRODUCTION equ 0000000Ah
    PIDMSI_COPYRIGHT equ 0000000Bh
    PIDMSI_STATUS_VALUE typedef SDWORD
    PIDMSI_STATUS_NORMAL equ 0
    PIDMSI_STATUS_NEW equ
    PIDMSI_STATUS_PRELIM equ
    PIDMSI_STATUS_DRAFT equ
    PIDMSI_STATUS_INPROGRESS equ
    PIDMSI_STATUS_EDIT equ
    PIDMSI_STATUS_REVIEW equ
    PIDMSI_STATUS_PROOF equ
    PIDMSI_STATUS_FINAL equ
    PIDMSI_STATUS_OTHER equ 7fffh

  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, PropVariantCopy, WIN_STD_CALL_CONV,, <:ptr PROPVARIANT, :ptr PROPVARIANT>, 8
    @DefProto DllImport, PropVariantClear, WIN_STD_CALL_CONV,, <:ptr PROPVARIANT>, 4
    @DefProto DllImport, FreePropVariantArray, WIN_STD_CALL_CONV,, <:ULONG, :ptr PROPVARIANT>, 8
    if Defined(_MSC_EXTENSIONS)
      _PROPVARIANTINIT_DEFINED_ equ <>
      ifdef __cplusplus
        ;[...]
      else
        PropVariantInit macro pvar
          exitm <memset ((pvar), 0, sizeof(PROPVARIANT))>
        endm
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef _SERIALIZEDPROPERTYVALUE_DEFINED_
      _SERIALIZEDPROPERTYVALUE_DEFINED_ equ <>
      SERIALIZEDPROPERTYVALUE struct
        dwType DWORD ?
        rgb BYTE 1 dup (?)
      SERIALIZEDPROPERTYVALUE ends
      tagSERIALIZEDPROPERTYVALUE typedef SERIALIZEDPROPERTYVALUE
    endif
    StgConvertVariantToProperty proto WIN_STD_CALL_CONV :ptr PROPVARIANT, :USHORT, :ptr SERIALIZEDPROPERTYVALUE, :ptr ULONG, :PROPID, :BOOLEAN, :ptr ULONG
    ifdef __cplusplus
      ;[...]
    endif
  endif
  if _MSC_VER ge 1200
  else
  endif
  externdef __MIDL_itf_propidl_0000_0004_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_propidl_0000_0004_v0_0_s_ifspec:RPC_IF_HANDLE
  BSTR_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr BSTR
  BSTR_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BSTR
  LPSAFEARRAY_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr LPSAFEARRAY
  LPSAFEARRAY_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr LPSAFEARRAY
  LPSAFEARRAY_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr LPSAFEARRAY
  LPSAFEARRAY_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr LPSAFEARRAY
  BSTR_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr BSTR
  BSTR_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BSTR
  LPSAFEARRAY_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr LPSAFEARRAY
  LPSAFEARRAY_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr LPSAFEARRAY
  LPSAFEARRAY_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr LPSAFEARRAY
  LPSAFEARRAY_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr LPSAFEARRAY
  IEnumSTATPROPSTG_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumSTATPROPSTG, :ULONG, :ptr STATPROPSTG, :ptr ULONG
  IEnumSTATPROPSTG_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumSTATPROPSTG, :ULONG, :ptr STATPROPSTG, :ptr ULONG
  IEnumSTATPROPSETSTG_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumSTATPROPSETSTG, :ULONG, :ptr STATPROPSETSTG, :ptr ULONG
  IEnumSTATPROPSETSTG_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumSTATPROPSETSTG, :ULONG, :ptr STATPROPSETSTG, :ptr ULONG
  ifdef __cplusplus
    ;[...]
  endif
endif
