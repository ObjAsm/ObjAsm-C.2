;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\propidlbase.h
;             Created on (UTC) 06/04/2024 06:15:57
;             Last modified on (UTC) 21/02/2024 18:18:10

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
ifndef COM_NO_WINDOWS_H
  include windows.inc
  include ole2.inc
  ;*COM_NO_WINDOWS_H*
endif
ifndef __propidlbase_h__
  __propidlbase_h__ equ <>
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
  ifndef __IPropertyStorage_FWD_DEFINED__
    __IPropertyStorage_FWD_DEFINED__ equ <>
    ;* __IPropertyStorage_FWD_DEFINED__ *
  endif
  ifndef __IPropertySetStorage_FWD_DEFINED__
    __IPropertySetStorage_FWD_DEFINED__ equ <>
    ;* __IPropertySetStorage_FWD_DEFINED__ *
  endif
  ifndef __IEnumSTATPROPSTG_FWD_DEFINED__
    __IEnumSTATPROPSTG_FWD_DEFINED__ equ <>
    ;* __IEnumSTATPROPSTG_FWD_DEFINED__ *
  endif
  ifndef __IEnumSTATPROPSETSTG_FWD_DEFINED__
    __IEnumSTATPROPSETSTG_FWD_DEFINED__ equ <>
    ;* __IEnumSTATPROPSETSTG_FWD_DEFINED__ *
  endif
  ;* header files for imported files *
  include objidl.inc
  include oaidl.inc
  ifdef __cplusplus
    ;[...]
  endif
  ;* interface __MIDL_itf_propidlbase_0000_0000 *
  ;* [local] *
  include winapifamily.inc
  ;+-------------------------------------------------------------------------
  ;  Microsoft Windows
  ;  Copyright (c) Microsoft Corporation. All rights reserved.
  ;--------------------------------------------------------------------------
  if (_MSC_VER ge 800)
    if _MSC_VER ge 1200
      ;* padding added after data member *
    endif
    ;* Nameless struct/union *
    ;* obsolete member named 'bool' *
  endif
  if (_MSC_VER ge 1020)
  endif
  ifndef _PROPIDLBASE_
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      VERSIONEDSTREAM struct
        guidVersion GUID <>
        pStream POINTER ?
      VERSIONEDSTREAM ends
      tagVersionedStream typedef VERSIONEDSTREAM
      LPVERSIONEDSTREAM typedef ptr tagVersionedStream
      ; Flags for IPropertySetStorage::Create
      PROPSETFLAG_DEFAULT equ (0)
      PROPSETFLAG_NONSIMPLE equ (1)
      PROPSETFLAG_ANSI equ (2)
      ;   (This flag is only supported on StgCreatePropStg & StgOpenPropStg
      PROPSETFLAG_UNBUFFERED equ (4)
      ;   (This flag causes a version-1 property set to be created
      PROPSETFLAG_CASE_SENSITIVE equ (8)
      ; Flags for the reserved PID_BEHAVIOR property
      PROPSET_BEHAVIOR_CASE_SENSITIVE equ (1)
      ifdef MIDL_PASS
        ;[...]
      else
        ; This is the standard C layout of the PROPVARIANT.
        PROPVARIANT typedef tagPROPVARIANT
      endif
      CAC struct
        cElems DWORD ?
        pElems POINTER ?
        ;* [size_is] *
      CAC ends
      tagCAC typedef CAC
      CAUB struct
        cElems DWORD ?
        pElems POINTER ?
        ;* [size_is] *
      CAUB ends
      tagCAUB typedef CAUB
      CAI struct
        cElems DWORD ?
        pElems POINTER ?
        ;* [size_is] *
      CAI ends
      tagCAI typedef CAI
      CAUI struct
        cElems DWORD ?
        pElems POINTER ?
        ;* [size_is] *
      CAUI ends
      tagCAUI typedef CAUI
      CAL struct
        cElems DWORD ?
        pElems POINTER ?
        ;* [size_is] *
      CAL ends
      tagCAL typedef CAL
      CAUL struct
        cElems DWORD ?
        pElems POINTER ?
        ;* [size_is] *
      CAUL ends
      tagCAUL typedef CAUL
      CAFLT struct
        cElems DWORD ?
        pElems POINTER ?
        ;* [size_is] *
      CAFLT ends
      tagCAFLT typedef CAFLT
      CADBL struct
        cElems DWORD ?
        pElems POINTER ?
        ;* [size_is] *
      CADBL ends
      tagCADBL typedef CADBL
      CACY struct
        cElems DWORD ?
        pElems POINTER ?
        ;* [size_is] *
      CACY ends
      tagCACY typedef CACY
      CADATE struct
        cElems DWORD ?
        pElems POINTER ?
        ;* [size_is] *
      CADATE ends
      tagCADATE typedef CADATE
      CABSTR struct
        cElems DWORD ?
        pElems POINTER ?
        ;* [size_is] *
      CABSTR ends
      tagCABSTR typedef CABSTR
      CABSTRBLOB struct
        cElems DWORD ?
        pElems POINTER ?
        ;* [size_is] *
      CABSTRBLOB ends
      tagCABSTRBLOB typedef CABSTRBLOB
      CABOOL struct
        cElems DWORD ?
        pElems POINTER ?
        ;* [size_is] *
      CABOOL ends
      tagCABOOL typedef CABOOL
      CASCODE struct
        cElems DWORD ?
        pElems POINTER ?
        ;* [size_is] *
      CASCODE ends
      tagCASCODE typedef CASCODE
      CAPROPVARIANT struct
        cElems DWORD ?
        pElems POINTER ?
        ;* [size_is] *
      CAPROPVARIANT ends
      tagCAPROPVARIANT typedef CAPROPVARIANT
      CAH struct
        cElems DWORD ?
        pElems POINTER ?
        ;* [size_is] *
      CAH ends
      tagCAH typedef CAH
      CAUH struct
        cElems DWORD ?
        pElems POINTER ?
        ;* [size_is] *
      CAUH ends
      tagCAUH typedef CAUH
      CALPSTR struct
        cElems DWORD ?
        pElems POINTER ?
        ;* [size_is] *
      CALPSTR ends
      tagCALPSTR typedef CALPSTR
      CALPWSTR struct
        cElems DWORD ?
        pElems POINTER ?
        ;* [size_is] *
      CALPWSTR ends
      tagCALPWSTR typedef CALPWSTR
      CAFILETIME struct
        cElems DWORD ?
        pElems POINTER ?
        ;* [size_is] *
      CAFILETIME ends
      tagCAFILETIME typedef CAFILETIME
      CACLIPDATA struct
        cElems DWORD ?
        pElems POINTER ?
        ;* [size_is] *
      CACLIPDATA ends
      tagCACLIPDATA typedef CACLIPDATA
      CACLSID struct
        cElems DWORD ?
        pElems POINTER ?
        ;* [size_is] *
      CACLSID ends
      tagCACLSID typedef CACLSID
      ifdef MIDL_PASS
        ;[...]
      else
        ; This is the standard C layout of the structure.
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
              ;* [switch_is] ** [switch_type] *
              union
                ;* [case()] ** Empty union arm *
                cVal SBYTE ?
                ;* [case()] *
                bVal BYTE ?
                ;* [case()] *
                iVal SWORD ?
                ;* [case()] *
                uiVal WORD ?
                ;* [case()] *
                lVal SDWORD ?
                ;* [case()] *
                ulVal DWORD ?
                ;* [case()] *
                intVal SDWORD ?
                ;* [case()] *
                uintVal DWORD ?
                ;* [case()] *
                hVal LARGE_INTEGER <>
                ;* [case()] *
                uhVal ULARGE_INTEGER <>
                ;* [case()] *
                fltVal REAL4 ?
                ;* [case()] *
                dblVal REAL8 ?
                ;* [case()] *
                boolVal VARIANT_BOOL ?
                ;* [case()] *
                __OBSOLETE__VARIANT_BOOL VARIANT_BOOL ?
                ;* [case()] *
                scode SCODE ?
                ;* [case()] *
                cyVal CY <>
                ;* [case()] *
                date DATE ?
                ;* [case()] *
                filetime FILETIME <>
                ;* [case()] *
                puuid POINTER ?
                ;* [case()] *
                pclipdata POINTER ?
                ;* [case()] *
                bstrVal BSTR ?
                ;* [case()] *
                bstrblobVal BSTRBLOB <>
                ;* [case()] *
                blob BLOB <>
                ;* [case()] *
                pszVal POINTER ?
                ;* [case()] *
                pwszVal POINTER ?
                ;* [case()] *
                punkVal POINTER ?
                ;* [case()] *
                pdispVal POINTER ?
                ;* [case()] *
                pStream POINTER ?
                ;* [case()] *
                pStorage POINTER ?
                ;* [case()] *
                pVersionedStream LPVERSIONEDSTREAM ?
                ;* [case()] *
                parray LPSAFEARRAY ?
                ;* [case()] *
                cac CAC <>
                ;* [case()] *
                caub CAUB <>
                ;* [case()] *
                cai CAI <>
                ;* [case()] *
                caui CAUI <>
                ;* [case()] *
                cal CAL <>
                ;* [case()] *
                caul CAUL <>
                ;* [case()] *
                cah CAH <>
                ;* [case()] *
                cauh CAUH <>
                ;* [case()] *
                caflt CAFLT <>
                ;* [case()] *
                cadbl CADBL <>
                ;* [case()] *
                cabool CABOOL <>
                ;* [case()] *
                cascode CASCODE <>
                ;* [case()] *
                cacy CACY <>
                ;* [case()] *
                cadate CADATE <>
                ;* [case()] *
                cafiletime CAFILETIME <>
                ;* [case()] *
                cauuid CACLSID <>
                ;* [case()] *
                caclipdata CACLIPDATA <>
                ;* [case()] *
                cabstr CABSTR <>
                ;* [case()] *
                cabstrblob CABSTRBLOB <>
                ;* [case()] *
                calpstr CALPSTR <>
                ;* [case()] *
                calpwstr CALPWSTR <>
                ;* [case()] *
                capropvar CAPROPVARIANT <>
                ;* [case()] *
                pcVal POINTER ?
                ;* [case()] *
                pbVal POINTER ?
                ;* [case()] *
                piVal POINTER ?
                ;* [case()] *
                puiVal POINTER ?
                ;* [case()] *
                plVal POINTER ?
                ;* [case()] *
                pulVal POINTER ?
                ;* [case()] *
                pintVal POINTER ?
                ;* [case()] *
                puintVal POINTER ?
                ;* [case()] *
                pfltVal POINTER ?
                ;* [case()] *
                pdblVal POINTER ?
                ;* [case()] *
                pboolVal POINTER ?
                ;* [case()] *
                pdecVal POINTER ?
                ;* [case()] *
                pscode POINTER ?
                ;* [case()] *
                pcyVal POINTER ?
                ;* [case()] *
                pdate POINTER ?
                ;* [case()] *
                pbstrVal POINTER ?
                ;* [case()] *
                ppunkVal POINTER ?
                ;* [case()] *
                ppdispVal POINTER ?
                ;* [case()] *
                pparray POINTER ?
                ;* [case()] *
                pvarVal POINTER ?
                ;* [case()] *
              ends
            ends
            ifndef MIDL_PASS
              decVal DECIMAL <>
            ends
          tagPROPVARIANT ends
        endif
        ;* _MSC_EXTENSIONS *
      endif
      ifdef MIDL_PASS
        ;[...]
      else
        ; This is the standard C layout of the PROPVARIANT.
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
      ; MIDL_PASS
      ; Reserved global Property IDs
      PID_DICTIONARY equ (0)
      PID_CODEPAGE equ (1h)
      PID_FIRST_USABLE equ (2h)
      PID_FIRST_NAME_DEFAULT equ (0fffh)
      PID_LOCALE equ (80000000h)
      PID_MODIFY_TIME equ (80000001h)
      PID_SECURITY equ (80000002h)
      PID_BEHAVIOR equ (80000003h)
      PID_ILLEGAL equ (0ffffffffh)
      ; Range which is read-only to downlevel implementations
      PID_MIN_READONLY equ (80000000h)
      PID_MAX_READONLY equ (0bfffffffh)
      PRSPEC_INVALID equ (0ffffffffh)
      PRSPEC_LPWSTR equ (0)
      PRSPEC_PROPID equ (1)
      PROPSPEC struct
        ulKind DWORD ?
        ;* [switch_is] ** [switch_type] *
        union
          propid PROPID ?
          ;* [case()] *
          lpwstr LPOLESTR ?
          ;* [case()] *
          ;* [default] ** Empty union arm *
        ends
      PROPSPEC ends
      tagPROPSPEC typedef PROPSPEC
      STATPROPSTG struct
        lpwstrName LPOLESTR ?
        propid PROPID ?
        vt VARTYPE ?
      STATPROPSTG ends
      tagSTATPROPSTG typedef STATPROPSTG
      ; Macros for parsing the OS Version of the Property Set Header
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
      externdef __MIDL_itf_propidlbase_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
      externdef __MIDL_itf_propidlbase_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
      ifndef __IPropertyStorage_INTERFACE_DEFINED__
        __IPropertyStorage_INTERFACE_DEFINED__ equ <>
        ;* interface IPropertyStorage *
        ;* [unique][uuid][object] *
        externdef IID_IPropertyStorage:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IPropertyStorageVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IPropertyStorageVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IPropertyStorage, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IPropertyStorage
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IPropertyStorage
            DECLSPEC_XFGVIRT(IPropertyStorage, ReadMultiple)
            ;* [in] *
            ;* [size_is][in] *
            STD_METHOD ReadMultiple, :ptr IPropertyStorage, :ULONG, :ptr PROPSPEC, :ptr PROPVARIANT
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IPropertyStorage, WriteMultiple)
            ;* [in] *
            ;* [size_is][in] *
            ;* [size_is][in] *
            STD_METHOD WriteMultiple, :ptr IPropertyStorage, :ULONG, :ptr PROPSPEC, :ptr PROPVARIANT, :PROPID
            ;* [in] *
            DECLSPEC_XFGVIRT(IPropertyStorage, DeleteMultiple)
            ;* [in] *
            STD_METHOD DeleteMultiple, :ptr IPropertyStorage, :ULONG, :ptr PROPSPEC
            ;* [size_is][in] *
            DECLSPEC_XFGVIRT(IPropertyStorage, ReadPropertyNames)
            ;* [in] *
            ;* [size_is][in] *
            STD_METHOD ReadPropertyNames, :ptr IPropertyStorage, :ULONG, :ptr PROPID, :ptr LPOLESTR
            ;* [size_is][out] *
            DECLSPEC_XFGVIRT(IPropertyStorage, WritePropertyNames)
            ;* [in] *
            ;* [size_is][in] *
            STD_METHOD WritePropertyNames, :ptr IPropertyStorage, :ULONG, :ptr PROPID, :ptr LPOLESTR
            ;* [size_is][in] *
            DECLSPEC_XFGVIRT(IPropertyStorage, DeletePropertyNames)
            ;* [in] *
            STD_METHOD DeletePropertyNames, :ptr IPropertyStorage, :ULONG, :ptr PROPID
            ;* [size_is][in] *
            DECLSPEC_XFGVIRT(IPropertyStorage, Commit)
            STD_METHOD Commit, :ptr IPropertyStorage, :DWORD
            ;* [in] *
            DECLSPEC_XFGVIRT(IPropertyStorage, Revert)
            STD_METHOD Revert, :ptr IPropertyStorage
            DECLSPEC_XFGVIRT(IPropertyStorage, Enum)
            STD_METHOD Enum, :ptr IPropertyStorage, :ptr ptr IEnumSTATPROPSTG
            ;* [out] *
            DECLSPEC_XFGVIRT(IPropertyStorage, SetTimes)
            ;* [in] *
            ;* [in] *
            STD_METHOD SetTimes, :ptr IPropertyStorage, :ptr FILETIME, :ptr FILETIME, :ptr FILETIME
            ;* [in] *
            DECLSPEC_XFGVIRT(IPropertyStorage, SetClass)
            STD_METHOD SetClass, :ptr IPropertyStorage, :REFCLSID
            ;* [in] *
            DECLSPEC_XFGVIRT(IPropertyStorage, Stat)
            STD_METHOD Stat, :ptr IPropertyStorage, :ptr STATPROPSETSTG
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IPropertyStorageVtbl ends
          IPropertyStorage struct
            lpVtbl POINTER ?
          IPropertyStorage ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IPropertyStorage_INTERFACE_DEFINED__ *
      endif
      ifndef __IPropertySetStorage_INTERFACE_DEFINED__
        __IPropertySetStorage_INTERFACE_DEFINED__ equ <>
        ;* interface IPropertySetStorage *
        ;* [unique][uuid][object] *
        ;* [unique] *
        LPPROPERTYSETSTORAGE typedef ptr IPropertySetStorage
        externdef IID_IPropertySetStorage:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IPropertySetStorageVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IPropertySetStorageVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IPropertySetStorage, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IPropertySetStorage
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IPropertySetStorage
            DECLSPEC_XFGVIRT(IPropertySetStorage, Create)
            ;* [in] *
            ;* [unique][in] *
            ;* [in] *
            ;* [in] *
            STD_METHOD Create, :ptr IPropertySetStorage, :REFFMTID, :ptr CLSID, :DWORD, :DWORD, :ptr ptr IPropertyStorage
            ;* [out] *
            DECLSPEC_XFGVIRT(IPropertySetStorage, Open)
            ;* [in] *
            ;* [in] *
            STD_METHOD Open, :ptr IPropertySetStorage, :REFFMTID, :DWORD, :ptr ptr IPropertyStorage
            ;* [out] *
            DECLSPEC_XFGVIRT(IPropertySetStorage, Delete)
            STD_METHOD Delete, :ptr IPropertySetStorage, :REFFMTID
            ;* [in] *
            DECLSPEC_XFGVIRT(IPropertySetStorage, Enum)
            STD_METHOD Enum, :ptr IPropertySetStorage, :ptr ptr IEnumSTATPROPSETSTG
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IPropertySetStorageVtbl ends
          IPropertySetStorage struct
            lpVtbl POINTER ?
          IPropertySetStorage ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* __IPropertySetStorage_INTERFACE_DEFINED__ *
      endif
      ifndef __IEnumSTATPROPSTG_INTERFACE_DEFINED__
        __IEnumSTATPROPSTG_INTERFACE_DEFINED__ equ <>
        ;* interface IEnumSTATPROPSTG *
        ;* [unique][uuid][object] *
        ;* [unique] *
        LPENUMSTATPROPSTG typedef ptr IEnumSTATPROPSTG
        externdef IID_IEnumSTATPROPSTG:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IEnumSTATPROPSTGVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEnumSTATPROPSTGVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IEnumSTATPROPSTG, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IEnumSTATPROPSTG
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IEnumSTATPROPSTG
            DECLSPEC_XFGVIRT(IEnumSTATPROPSTG, Next)
            ;* [local] *
            ;* [in] *
            ;* [annotation][length_is][size_is][out] *
            ;* [annotation][out] *
            STD_METHOD Next, :ptr IEnumSTATPROPSTG, :ULONG, :ptr STATPROPSTG, :ptr ULONG
            DECLSPEC_XFGVIRT(IEnumSTATPROPSTG, Skip)
            STD_METHOD Skip, :ptr IEnumSTATPROPSTG, :ULONG
            ;* [in] *
            DECLSPEC_XFGVIRT(IEnumSTATPROPSTG, Reset)
            STD_METHOD Reset, :ptr IEnumSTATPROPSTG
            DECLSPEC_XFGVIRT(IEnumSTATPROPSTG, Clone)
            STD_METHOD Clone, :ptr IEnumSTATPROPSTG, :ptr ptr IEnumSTATPROPSTG
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IEnumSTATPROPSTGVtbl ends
          IEnumSTATPROPSTG struct
            lpVtbl POINTER ?
          IEnumSTATPROPSTG ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* [call_as] *
        IEnumSTATPROPSTG_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumSTATPROPSTG, :ULONG, :ptr STATPROPSTG, :ptr ULONG
        ;* [out] *
        IEnumSTATPROPSTG_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        ;* __IEnumSTATPROPSTG_INTERFACE_DEFINED__ *
      endif
      ifndef __IEnumSTATPROPSETSTG_INTERFACE_DEFINED__
        __IEnumSTATPROPSETSTG_INTERFACE_DEFINED__ equ <>
        ;* interface IEnumSTATPROPSETSTG *
        ;* [unique][uuid][object] *
        ;* [unique] *
        LPENUMSTATPROPSETSTG typedef ptr IEnumSTATPROPSETSTG
        externdef IID_IEnumSTATPROPSETSTG:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          IEnumSTATPROPSETSTGVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEnumSTATPROPSETSTGVtbl>
            DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
            ;* [in] *
            ;* [annotation][iid_is][out] *
            STD_METHOD QueryInterface, :ptr IEnumSTATPROPSETSTG, :REFIID, :ptr ptr
            DECLSPEC_XFGVIRT(IUnknown, AddRef)
            STD_METHOD AddRef, :ptr IEnumSTATPROPSETSTG
            DECLSPEC_XFGVIRT(IUnknown, Release)
            STD_METHOD Release, :ptr IEnumSTATPROPSETSTG
            DECLSPEC_XFGVIRT(IEnumSTATPROPSETSTG, Next)
            ;* [local] *
            ;* [in] *
            ;* [annotation][length_is][size_is][out] *
            ;* [annotation][out] *
            STD_METHOD Next, :ptr IEnumSTATPROPSETSTG, :ULONG, :ptr STATPROPSETSTG, :ptr ULONG
            DECLSPEC_XFGVIRT(IEnumSTATPROPSETSTG, Skip)
            STD_METHOD Skip, :ptr IEnumSTATPROPSETSTG, :ULONG
            ;* [in] *
            DECLSPEC_XFGVIRT(IEnumSTATPROPSETSTG, Reset)
            STD_METHOD Reset, :ptr IEnumSTATPROPSETSTG
            DECLSPEC_XFGVIRT(IEnumSTATPROPSETSTG, Clone)
            STD_METHOD Clone, :ptr IEnumSTATPROPSETSTG, :ptr ptr IEnumSTATPROPSETSTG
            ;* [out] *
            ??Interface equ <>
            END_INTERFACE
          IEnumSTATPROPSETSTGVtbl ends
          IEnumSTATPROPSETSTG struct
            lpVtbl POINTER ?
          IEnumSTATPROPSETSTG ends
          ifdef COBJMACROS
            ;[...]
          endif
          ;* C style interface *
        endif
        ;* [call_as] *
        IEnumSTATPROPSETSTG_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumSTATPROPSETSTG, :ULONG, :ptr STATPROPSETSTG, :ptr ULONG
        ;* [out] *
        IEnumSTATPROPSETSTG_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
        ;* __IEnumSTATPROPSETSTG_INTERFACE_DEFINED__ *
      endif
      ;* interface __MIDL_itf_propidlbase_0000_0004 *
      ;* [local] *
      ;* [unique] *
      LPPROPERTYSTORAGE typedef ptr IPropertyStorage
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    _PROPIDLBASE_ equ <>
  endif
  if _MSC_VER ge 1200
  else
    ;* Nameless struct/union *
    ;* keywords bool, true, false, etc.. *
  endif
  externdef __MIDL_itf_propidlbase_0000_0004_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_propidlbase_0000_0004_v0_0_s_ifspec:RPC_IF_HANDLE
  ;* Additional Prototypes for ALL interfaces *
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
  ;* [local] *
  IEnumSTATPROPSTG_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumSTATPROPSTG, :ULONG, :ptr STATPROPSTG, :ptr ULONG
  ;* [annotation][out] *
  ;* [call_as] *
  IEnumSTATPROPSTG_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumSTATPROPSTG, :ULONG, :ptr STATPROPSTG, :ptr ULONG
  ;* [out] *
  ;* [local] *
  IEnumSTATPROPSETSTG_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumSTATPROPSETSTG, :ULONG, :ptr STATPROPSETSTG, :ptr ULONG
  ;* [annotation][out] *
  ;* [call_as] *
  IEnumSTATPROPSETSTG_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumSTATPROPSETSTG, :ULONG, :ptr STATPROPSETSTG, :ptr ULONG
  ;* [out] *
  ;* end of Additional Prototypes *
  ifdef __cplusplus
    ;[...]
  endif
endif
