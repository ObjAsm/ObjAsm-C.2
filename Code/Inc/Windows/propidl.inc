;Include file created by h2incX, Version B.01.02, 23/09/2018 18:52
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\propidl.h', last modified: 19/04/2018 10:46
;Creation parameters:

ifndef __REQUIRED_RPCNDR_H_VERSION__
  __REQUIRED_RPCNDR_H_VERSION__ equ 500
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
  ifndef __IPropertyStorage_FWD_DEFINED__
    __IPropertyStorage_FWD_DEFINED__ equ <>
    ;IPropertyStorage typedef IPropertyStorage
  endif
  ifndef __IPropertySetStorage_FWD_DEFINED__
    __IPropertySetStorage_FWD_DEFINED__ equ <>
    ;IPropertySetStorage typedef IPropertySetStorage
  endif
  ifndef __IEnumSTATPROPSTG_FWD_DEFINED__
    __IEnumSTATPROPSTG_FWD_DEFINED__ equ <>
    ;IEnumSTATPROPSTG typedef IEnumSTATPROPSTG
  endif
  ifndef __IEnumSTATPROPSETSTG_FWD_DEFINED__
    __IEnumSTATPROPSETSTG_FWD_DEFINED__ equ <>
    ;IEnumSTATPROPSETSTG typedef IEnumSTATPROPSETSTG
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
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
      VERSIONEDSTREAM struct
        guidVersion GUID <>
        pStream POINTER ?
      VERSIONEDSTREAM ends
      tagVersionedStream typedef VERSIONEDSTREAM
      LPVERSIONEDSTREAM typedef ptr tagVersionedStream
      PROPSETFLAG_DEFAULT equ 0
      PROPSETFLAG_NONSIMPLE equ 1
      PROPSETFLAG_ANSI equ 2
      PROPSETFLAG_UNBUFFERED equ 4
      PROPSETFLAG_CASE_SENSITIVE equ 8
      PROPSET_BEHAVIOR_CASE_SENSITIVE equ 1
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
                bool _VARIANT_BOOL ?
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
            REFPROPVARIANT equ <ptr PROPVARIANT>
          endif
        endif
      endif
      PID_DICTIONARY equ 0
      PID_CODEPAGE equ 1h
      PID_FIRST_USABLE equ 2h
      PID_FIRST_NAME_DEFAULT equ 0fffh
      PID_LOCALE equ 80000000h
      PID_MODIFY_TIME equ 80000001h
      PID_SECURITY equ 80000002h
      PID_BEHAVIOR equ 80000003h
      PID_ILLEGAL equ 0ffffffffh
      PID_MIN_READONLY equ 80000000h
      PID_MAX_READONLY equ 0bfffffffh
      PRSPEC_INVALID equ 0ffffffffh
      PRSPEC_LPWSTR equ 0
      PRSPEC_PROPID equ 1
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
          TYPE_IPropertyStorageVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IPropertyStorage, :REFIID, :ptr ptr
          PIPropertyStorageVtbl_QueryInterface typedef ptr TYPE_IPropertyStorageVtbl_QueryInterface
          TYPE_IPropertyStorageVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IPropertyStorage
          PIPropertyStorageVtbl_AddRef typedef ptr TYPE_IPropertyStorageVtbl_AddRef
          TYPE_IPropertyStorageVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IPropertyStorage
          PIPropertyStorageVtbl_Release typedef ptr TYPE_IPropertyStorageVtbl_Release
          TYPE_IPropertyStorageVtbl_ReadMultiple typedef proto WIN_STD_CALL_CONV :ptr IPropertyStorage, :ULONG, :ptr PROPSPEC, :ptr PROPVARIANT
          PIPropertyStorageVtbl_ReadMultiple typedef ptr TYPE_IPropertyStorageVtbl_ReadMultiple
          TYPE_IPropertyStorageVtbl_WriteMultiple typedef proto WIN_STD_CALL_CONV :ptr IPropertyStorage, :ULONG, :ptr PROPSPEC, :ptr PROPVARIANT, :PROPID
          PIPropertyStorageVtbl_WriteMultiple typedef ptr TYPE_IPropertyStorageVtbl_WriteMultiple
          TYPE_IPropertyStorageVtbl_DeleteMultiple typedef proto WIN_STD_CALL_CONV :ptr IPropertyStorage, :ULONG, :ptr PROPSPEC
          PIPropertyStorageVtbl_DeleteMultiple typedef ptr TYPE_IPropertyStorageVtbl_DeleteMultiple
          TYPE_IPropertyStorageVtbl_ReadPropertyNames typedef proto WIN_STD_CALL_CONV :ptr IPropertyStorage, :ULONG, :ptr PROPID, :ptr LPOLESTR
          PIPropertyStorageVtbl_ReadPropertyNames typedef ptr TYPE_IPropertyStorageVtbl_ReadPropertyNames
          TYPE_IPropertyStorageVtbl_WritePropertyNames typedef proto WIN_STD_CALL_CONV :ptr IPropertyStorage, :ULONG, :ptr PROPID, :ptr LPOLESTR
          PIPropertyStorageVtbl_WritePropertyNames typedef ptr TYPE_IPropertyStorageVtbl_WritePropertyNames
          TYPE_IPropertyStorageVtbl_DeletePropertyNames typedef proto WIN_STD_CALL_CONV :ptr IPropertyStorage, :ULONG, :ptr PROPID
          PIPropertyStorageVtbl_DeletePropertyNames typedef ptr TYPE_IPropertyStorageVtbl_DeletePropertyNames
          TYPE_IPropertyStorageVtbl_Commit typedef proto WIN_STD_CALL_CONV :ptr IPropertyStorage, :DWORD
          PIPropertyStorageVtbl_Commit typedef ptr TYPE_IPropertyStorageVtbl_Commit
          TYPE_IPropertyStorageVtbl_Revert typedef proto WIN_STD_CALL_CONV :ptr IPropertyStorage
          PIPropertyStorageVtbl_Revert typedef ptr TYPE_IPropertyStorageVtbl_Revert
          TYPE_IPropertyStorageVtbl_Enum typedef proto WIN_STD_CALL_CONV :ptr IPropertyStorage, :ptr ptr IEnumSTATPROPSTG
          PIPropertyStorageVtbl_Enum typedef ptr TYPE_IPropertyStorageVtbl_Enum
          TYPE_IPropertyStorageVtbl_SetTimes typedef proto WIN_STD_CALL_CONV :ptr IPropertyStorage, :ptr FILETIME, :ptr FILETIME, :ptr FILETIME
          PIPropertyStorageVtbl_SetTimes typedef ptr TYPE_IPropertyStorageVtbl_SetTimes
          TYPE_IPropertyStorageVtbl_SetClass typedef proto WIN_STD_CALL_CONV :ptr IPropertyStorage, :REFCLSID
          PIPropertyStorageVtbl_SetClass typedef ptr TYPE_IPropertyStorageVtbl_SetClass
          TYPE_IPropertyStorageVtbl_Stat typedef proto WIN_STD_CALL_CONV :ptr IPropertyStorage, :ptr STATPROPSETSTG
          PIPropertyStorageVtbl_Stat typedef ptr TYPE_IPropertyStorageVtbl_Stat
          IPropertyStorageVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IPropertyStorage>
            QueryInterface PIPropertyStorageVtbl_QueryInterface ?
            AddRef PIPropertyStorageVtbl_AddRef ?
            Release PIPropertyStorageVtbl_Release ?
            ReadMultiple PIPropertyStorageVtbl_ReadMultiple ?
            WriteMultiple PIPropertyStorageVtbl_WriteMultiple ?
            DeleteMultiple PIPropertyStorageVtbl_DeleteMultiple ?
            ReadPropertyNames PIPropertyStorageVtbl_ReadPropertyNames ?
            WritePropertyNames PIPropertyStorageVtbl_WritePropertyNames ?
            DeletePropertyNames PIPropertyStorageVtbl_DeletePropertyNames ?
            Commit PIPropertyStorageVtbl_Commit ?
            Revert PIPropertyStorageVtbl_Revert ?
            Enum PIPropertyStorageVtbl_Enum ?
            SetTimes PIPropertyStorageVtbl_SetTimes ?
            SetClass PIPropertyStorageVtbl_SetClass ?
            Stat PIPropertyStorageVtbl_Stat ?
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
          TYPE_IPropertySetStorageVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IPropertySetStorage, :REFIID, :ptr ptr
          PIPropertySetStorageVtbl_QueryInterface typedef ptr TYPE_IPropertySetStorageVtbl_QueryInterface
          TYPE_IPropertySetStorageVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IPropertySetStorage
          PIPropertySetStorageVtbl_AddRef typedef ptr TYPE_IPropertySetStorageVtbl_AddRef
          TYPE_IPropertySetStorageVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IPropertySetStorage
          PIPropertySetStorageVtbl_Release typedef ptr TYPE_IPropertySetStorageVtbl_Release
          TYPE_IPropertySetStorageVtbl_Create typedef proto WIN_STD_CALL_CONV :ptr IPropertySetStorage, :REFFMTID, :ptr CLSID, :DWORD, :DWORD, :ptr ptr IPropertyStorage
          PIPropertySetStorageVtbl_Create typedef ptr TYPE_IPropertySetStorageVtbl_Create
          TYPE_IPropertySetStorageVtbl_Open typedef proto WIN_STD_CALL_CONV :ptr IPropertySetStorage, :REFFMTID, :DWORD, :ptr ptr IPropertyStorage
          PIPropertySetStorageVtbl_Open typedef ptr TYPE_IPropertySetStorageVtbl_Open
          TYPE_IPropertySetStorageVtbl_Delete typedef proto WIN_STD_CALL_CONV :ptr IPropertySetStorage, :REFFMTID
          PIPropertySetStorageVtbl_Delete typedef ptr TYPE_IPropertySetStorageVtbl_Delete
          TYPE_IPropertySetStorageVtbl_Enum typedef proto WIN_STD_CALL_CONV :ptr IPropertySetStorage, :ptr ptr IEnumSTATPROPSETSTG
          PIPropertySetStorageVtbl_Enum typedef ptr TYPE_IPropertySetStorageVtbl_Enum
          IPropertySetStorageVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IPropertySetStorage>
            QueryInterface PIPropertySetStorageVtbl_QueryInterface ?
            AddRef PIPropertySetStorageVtbl_AddRef ?
            Release PIPropertySetStorageVtbl_Release ?
            Create PIPropertySetStorageVtbl_Create ?
            Open PIPropertySetStorageVtbl_Open ?
            Delete PIPropertySetStorageVtbl_Delete ?
            Enum PIPropertySetStorageVtbl_Enum ?
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
          TYPE_IEnumSTATPROPSTGVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IEnumSTATPROPSTG, :REFIID, :ptr ptr
          PIEnumSTATPROPSTGVtbl_QueryInterface typedef ptr TYPE_IEnumSTATPROPSTGVtbl_QueryInterface
          TYPE_IEnumSTATPROPSTGVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IEnumSTATPROPSTG
          PIEnumSTATPROPSTGVtbl_AddRef typedef ptr TYPE_IEnumSTATPROPSTGVtbl_AddRef
          TYPE_IEnumSTATPROPSTGVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IEnumSTATPROPSTG
          PIEnumSTATPROPSTGVtbl_Release typedef ptr TYPE_IEnumSTATPROPSTGVtbl_Release
          TYPE_IEnumSTATPROPSTGVtbl_Next typedef proto WIN_STD_CALL_CONV :ptr IEnumSTATPROPSTG, :ULONG, :ptr STATPROPSTG, :ptr ULONG
          PIEnumSTATPROPSTGVtbl_Next typedef ptr TYPE_IEnumSTATPROPSTGVtbl_Next
          TYPE_IEnumSTATPROPSTGVtbl_Skip typedef proto WIN_STD_CALL_CONV :ptr IEnumSTATPROPSTG, :ULONG
          PIEnumSTATPROPSTGVtbl_Skip typedef ptr TYPE_IEnumSTATPROPSTGVtbl_Skip
          TYPE_IEnumSTATPROPSTGVtbl_Reset typedef proto WIN_STD_CALL_CONV :ptr IEnumSTATPROPSTG
          PIEnumSTATPROPSTGVtbl_Reset typedef ptr TYPE_IEnumSTATPROPSTGVtbl_Reset
          TYPE_IEnumSTATPROPSTGVtbl_Clone typedef proto WIN_STD_CALL_CONV :ptr IEnumSTATPROPSTG, :ptr ptr IEnumSTATPROPSTG
          PIEnumSTATPROPSTGVtbl_Clone typedef ptr TYPE_IEnumSTATPROPSTGVtbl_Clone
          IEnumSTATPROPSTGVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEnumSTATPROPSTG>
            QueryInterface PIEnumSTATPROPSTGVtbl_QueryInterface ?
            AddRef PIEnumSTATPROPSTGVtbl_AddRef ?
            Release PIEnumSTATPROPSTGVtbl_Release ?
            Next PIEnumSTATPROPSTGVtbl_Next ?
            Skip PIEnumSTATPROPSTGVtbl_Skip ?
            Reset PIEnumSTATPROPSTGVtbl_Reset ?
            Clone PIEnumSTATPROPSTGVtbl_Clone ?
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
        ;Warning: duplicate proto = IEnumSTATPROPSTG_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumSTATPROPSTG, :ULONG, :ptr STATPROPSTG, :ptr ULONG
        ;Warning: duplicate proto = IEnumSTATPROPSTG_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      endif
      ifndef __IEnumSTATPROPSETSTG_INTERFACE_DEFINED__
        __IEnumSTATPROPSETSTG_INTERFACE_DEFINED__ equ <>
        LPENUMSTATPROPSETSTG typedef ptr IEnumSTATPROPSETSTG
        externdef IID_IEnumSTATPROPSETSTG:IID
        if Defined(__cplusplus) and  not Defined(CINTERFACE)
          ;[...]
        else
          TYPE_IEnumSTATPROPSETSTGVtbl_QueryInterface typedef proto WIN_STD_CALL_CONV :ptr IEnumSTATPROPSETSTG, :REFIID, :ptr ptr
          PIEnumSTATPROPSETSTGVtbl_QueryInterface typedef ptr TYPE_IEnumSTATPROPSETSTGVtbl_QueryInterface
          TYPE_IEnumSTATPROPSETSTGVtbl_AddRef typedef proto WIN_STD_CALL_CONV :ptr IEnumSTATPROPSETSTG
          PIEnumSTATPROPSETSTGVtbl_AddRef typedef ptr TYPE_IEnumSTATPROPSETSTGVtbl_AddRef
          TYPE_IEnumSTATPROPSETSTGVtbl_Release typedef proto WIN_STD_CALL_CONV :ptr IEnumSTATPROPSETSTG
          PIEnumSTATPROPSETSTGVtbl_Release typedef ptr TYPE_IEnumSTATPROPSETSTGVtbl_Release
          TYPE_IEnumSTATPROPSETSTGVtbl_Next typedef proto WIN_STD_CALL_CONV :ptr IEnumSTATPROPSETSTG, :ULONG, :ptr STATPROPSETSTG, :ptr ULONG
          PIEnumSTATPROPSETSTGVtbl_Next typedef ptr TYPE_IEnumSTATPROPSETSTGVtbl_Next
          TYPE_IEnumSTATPROPSETSTGVtbl_Skip typedef proto WIN_STD_CALL_CONV :ptr IEnumSTATPROPSETSTG, :ULONG
          PIEnumSTATPROPSETSTGVtbl_Skip typedef ptr TYPE_IEnumSTATPROPSETSTGVtbl_Skip
          TYPE_IEnumSTATPROPSETSTGVtbl_Reset typedef proto WIN_STD_CALL_CONV :ptr IEnumSTATPROPSETSTG
          PIEnumSTATPROPSETSTGVtbl_Reset typedef ptr TYPE_IEnumSTATPROPSETSTGVtbl_Reset
          TYPE_IEnumSTATPROPSETSTGVtbl_Clone typedef proto WIN_STD_CALL_CONV :ptr IEnumSTATPROPSETSTG, :ptr ptr IEnumSTATPROPSETSTG
          PIEnumSTATPROPSETSTGVtbl_Clone typedef ptr TYPE_IEnumSTATPROPSETSTGVtbl_Clone
          IEnumSTATPROPSETSTGVtbl struct
            BEGIN_INTERFACE
            ??Interface equ <IEnumSTATPROPSETSTG>
            QueryInterface PIEnumSTATPROPSETSTGVtbl_QueryInterface ?
            AddRef PIEnumSTATPROPSETSTGVtbl_AddRef ?
            Release PIEnumSTATPROPSETSTGVtbl_Release ?
            Next PIEnumSTATPROPSETSTGVtbl_Next ?
            Skip PIEnumSTATPROPSETSTGVtbl_Skip ?
            Reset PIEnumSTATPROPSETSTGVtbl_Reset ?
            Clone PIEnumSTATPROPSETSTGVtbl_Clone ?
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
        ;Warning: duplicate proto = IEnumSTATPROPSETSTG_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumSTATPROPSETSTG, :ULONG, :ptr STATPROPSETSTG, :ptr ULONG
        ;Warning: duplicate proto = IEnumSTATPROPSETSTG_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
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
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    ;Warning: duplicate proto = @DefProto DllImport, PropVariantCopy, WIN_STD_CALL_CONV,, <:ptr PROPVARIANT, :ptr PROPVARIANT>, 8
    ;Warning: duplicate proto = @DefProto DllImport, PropVariantClear, WIN_STD_CALL_CONV,, <:ptr PROPVARIANT>, 4
    ;Warning: duplicate proto = @DefProto DllImport, FreePropVariantArray, WIN_STD_CALL_CONV,, <:ULONG, :ptr PROPVARIANT>, 8
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
  ;Warning: duplicate proto = BSTR_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr BSTR
  ;Warning: duplicate proto = BSTR_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  ;Warning: duplicate proto = BSTR_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  ;Warning: duplicate proto = BSTR_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BSTR
  ;Warning: duplicate proto = LPSAFEARRAY_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr LPSAFEARRAY
  ;Warning: duplicate proto = LPSAFEARRAY_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr LPSAFEARRAY
  ;Warning: duplicate proto = LPSAFEARRAY_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr LPSAFEARRAY
  ;Warning: duplicate proto = LPSAFEARRAY_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr LPSAFEARRAY
  ;Warning: duplicate proto = BSTR_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr BSTR
  ;Warning: duplicate proto = BSTR_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  ;Warning: duplicate proto = BSTR_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  ;Warning: duplicate proto = BSTR_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BSTR
  ;Warning: duplicate proto = LPSAFEARRAY_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr LPSAFEARRAY
  ;Warning: duplicate proto = LPSAFEARRAY_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr LPSAFEARRAY
  ;Warning: duplicate proto = LPSAFEARRAY_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr LPSAFEARRAY
  ;Warning: duplicate proto = LPSAFEARRAY_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr LPSAFEARRAY
  ;Warning: duplicate proto = IEnumSTATPROPSTG_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumSTATPROPSTG, :ULONG, :ptr STATPROPSTG, :ptr ULONG
  ;Warning: duplicate proto = IEnumSTATPROPSTG_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumSTATPROPSTG, :ULONG, :ptr STATPROPSTG, :ptr ULONG
  ;Warning: duplicate proto = IEnumSTATPROPSETSTG_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumSTATPROPSETSTG, :ULONG, :ptr STATPROPSETSTG, :ptr ULONG
  ;Warning: duplicate proto = IEnumSTATPROPSETSTG_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumSTATPROPSETSTG, :ULONG, :ptr STATPROPSETSTG, :ptr ULONG
  ifdef __cplusplus
    ;[...]
  endif
endif

