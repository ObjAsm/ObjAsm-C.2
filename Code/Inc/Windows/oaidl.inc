;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\oaidl.h
;             Created on (UTC) 06/04/2024 06:15:57
;             Last modified on (UTC) 21/02/2024 18:18:08

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
ifndef __oaidl_h__
  __oaidl_h__ equ <>
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
  ifndef __ICreateTypeInfo_FWD_DEFINED__
    __ICreateTypeInfo_FWD_DEFINED__ equ <>
  endif
  ifndef __ICreateTypeInfo2_FWD_DEFINED__
    __ICreateTypeInfo2_FWD_DEFINED__ equ <>
  endif
  ifndef __ICreateTypeLib_FWD_DEFINED__
    __ICreateTypeLib_FWD_DEFINED__ equ <>
  endif
  ifndef __ICreateTypeLib2_FWD_DEFINED__
    __ICreateTypeLib2_FWD_DEFINED__ equ <>
  endif
  ifndef __IDispatch_FWD_DEFINED__
    __IDispatch_FWD_DEFINED__ equ <>
  endif
  ifndef __IEnumVARIANT_FWD_DEFINED__
    __IEnumVARIANT_FWD_DEFINED__ equ <>
  endif
  ifndef __ITypeComp_FWD_DEFINED__
    __ITypeComp_FWD_DEFINED__ equ <>
  endif
  ifndef __ITypeInfo_FWD_DEFINED__
    __ITypeInfo_FWD_DEFINED__ equ <>
  endif
  ifndef __ITypeInfo2_FWD_DEFINED__
    __ITypeInfo2_FWD_DEFINED__ equ <>
  endif
  ifndef __ITypeLib_FWD_DEFINED__
    __ITypeLib_FWD_DEFINED__ equ <>
  endif
  ifndef __ITypeLib2_FWD_DEFINED__
    __ITypeLib2_FWD_DEFINED__ equ <>
  endif
  ifndef __ITypeChangeEvents_FWD_DEFINED__
    __ITypeChangeEvents_FWD_DEFINED__ equ <>
  endif
  ifndef __IErrorInfo_FWD_DEFINED__
    __IErrorInfo_FWD_DEFINED__ equ <>
  endif
  ifndef __ICreateErrorInfo_FWD_DEFINED__
    __ICreateErrorInfo_FWD_DEFINED__ equ <>
  endif
  ifndef __ISupportErrorInfo_FWD_DEFINED__
    __ISupportErrorInfo_FWD_DEFINED__ equ <>
  endif
  ifndef __ITypeFactory_FWD_DEFINED__
    __ITypeFactory_FWD_DEFINED__ equ <>
  endif
  ifndef __ITypeMarshal_FWD_DEFINED__
    __ITypeMarshal_FWD_DEFINED__ equ <>
  endif
  ifndef __IRecordInfo_FWD_DEFINED__
    __IRecordInfo_FWD_DEFINED__ equ <>
  endif
  ifndef __IErrorLog_FWD_DEFINED__
    __IErrorLog_FWD_DEFINED__ equ <>
  endif
  ifndef __IPropertyBag_FWD_DEFINED__
    __IPropertyBag_FWD_DEFINED__ equ <>
  endif
  ifndef __ITypeLibRegistrationReader_FWD_DEFINED__
    __ITypeLibRegistrationReader_FWD_DEFINED__ equ <>
  endif
  ifndef __ITypeLibRegistration_FWD_DEFINED__
    __ITypeLibRegistration_FWD_DEFINED__ equ <>
  endif
  include objidl.inc
  ifdef __cplusplus
    ;[...]
  endif
  include winapifamily.inc
  if (_MSC_VER ge 800)
    if _MSC_VER ge 1200
    endif
  endif
  if (_MSC_VER ge 1020)
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    externdef __MIDL_itf_oaidl_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_oaidl_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IOleAutomationTypes_INTERFACE_DEFINED__
      __IOleAutomationTypes_INTERFACE_DEFINED__ equ <>
      CURRENCY typedef CY
      SAFEARRAYBOUND struct
        cElements ULONG ?
        lLbound LONG ?
      SAFEARRAYBOUND ends
      tagSAFEARRAYBOUND typedef SAFEARRAYBOUND
      LPSAFEARRAYBOUND typedef ptr tagSAFEARRAYBOUND
      wireVARIANT typedef ptr _wireVARIANT
      wireBRECORD typedef ptr _wireBRECORD
      SAFEARR_BSTR struct
        Size_ ULONG ?
        aBstr POINTER ?
      SAFEARR_BSTR ends
      _wireSAFEARR_BSTR typedef SAFEARR_BSTR
      SAFEARR_UNKNOWN struct
        Size_ ULONG ?
        apUnknown POINTER ?
      SAFEARR_UNKNOWN ends
      _wireSAFEARR_UNKNOWN typedef SAFEARR_UNKNOWN
      SAFEARR_DISPATCH struct
        Size_ ULONG ?
        apDispatch POINTER ?
      SAFEARR_DISPATCH ends
      _wireSAFEARR_DISPATCH typedef SAFEARR_DISPATCH
      SAFEARR_VARIANT struct
        Size_ ULONG ?
        aVariant POINTER ?
      SAFEARR_VARIANT ends
      _wireSAFEARR_VARIANT typedef SAFEARR_VARIANT
      SAFEARR_BRECORD struct
        Size_ ULONG ?
        aRecord POINTER ?
      SAFEARR_BRECORD ends
      _wireSAFEARR_BRECORD typedef SAFEARR_BRECORD
      SAFEARR_HAVEIID struct
        Size_ ULONG ?
        apUnknown POINTER ?
        iid IID <>
      SAFEARR_HAVEIID ends
      _wireSAFEARR_HAVEIID typedef SAFEARR_HAVEIID
      SF_TYPE typedef SDWORD
      SF_ERROR equ VT_ERROR
      SF_I1 equ VT_I1
      SF_I2 equ VT_I2
      SF_I4 equ VT_I4
      SF_I8 equ VT_I8
      SF_BSTR equ VT_BSTR
      SF_UNKNOWN equ VT_UNKNOWN
      SF_DISPATCH equ VT_DISPATCH
      SF_VARIANT equ VT_VARIANT
      SF_RECORD equ VT_RECORD
      SF_HAVEIID equ ( VT_UNKNOWN or VT_RESERVED )
      tagSF_TYPE typedef SF_TYPE

      SAFEARRAYUNION struct
        sfType ULONG ?
        union u
          BstrStr SAFEARR_BSTR <>
          UnknownStr SAFEARR_UNKNOWN <>
          DispatchStr SAFEARR_DISPATCH <>
          VariantStr SAFEARR_VARIANT <>
          RecordStr SAFEARR_BRECORD <>
          HaveIidStr SAFEARR_HAVEIID <>
          ByteStr BYTE_SIZEDARR <>
          WordStr WORD_SIZEDARR <>
          LongStr DWORD_SIZEDARR <>
          HyperStr HYPER_SIZEDARR <>
        ends
      SAFEARRAYUNION ends
      _wireSAFEARRAY_UNION typedef SAFEARRAYUNION
      _wireSAFEARRAY struct
        cDims USHORT ?
        fFeatures USHORT ?
        cbElements ULONG ?
        cLocks ULONG ?
        uArrayStructs SAFEARRAYUNION <>
        rgsabound SAFEARRAYBOUND 1 dup (<>)
      _wireSAFEARRAY ends
      wireSAFEARRAY typedef ptr _wireSAFEARRAY
      wirePSAFEARRAY typedef ptr wireSAFEARRAY
      SAFEARRAY struct
        cDims USHORT ?
        fFeatures USHORT ?
        cbElements ULONG ?
        cLocks ULONG ?
        pvData PVOID ?
        rgsabound SAFEARRAYBOUND 1 dup (<>)
      SAFEARRAY ends
      tagSAFEARRAY typedef SAFEARRAY
      LPSAFEARRAY typedef ptr SAFEARRAY
      FADF_AUTO equ (1h)
      FADF_STATIC equ (2h)
      FADF_EMBEDDED equ (4h)
      FADF_FIXEDSIZE equ (10h)
      FADF_RECORD equ (20h)
      FADF_HAVEIID equ (40h)
      FADF_HAVEVARTYPE equ (80h)
      FADF_BSTR equ (100h)
      FADF_UNKNOWN equ (200h)
      FADF_DISPATCH equ (400h)
      FADF_VARIANT equ (800h)
      FADF_RESERVED equ (0f008h)
      if (__STDC__ and  not Defined(_FORCENAMELESSUNION)) or Defined(NONAMELESSUNION) or ( not Defined(_MSC_EXTENSIONS) and  not Defined(_FORCENAMELESSUNION))
        __VARIANT_NAME_1 equ <n1>
        __VARIANT_NAME_2 equ <n2>
        __VARIANT_NAME_3 equ <n3>
        __VARIANT_NAME_4 equ <brecVal>
      else
        __tagVARIANT equ <>
        __VARIANT_NAME_1 equ <>
        __VARIANT_NAME_2 equ <>
        __VARIANT_NAME_3 equ <>
        __tagBRECORD equ <>
        __VARIANT_NAME_4 equ <>
      endif
      tagVARIANT struct
        union __VARIANT_NAME_1
          struct __VARIANT_NAME_2
            vt VARTYPE ?
            wReserved1 WORD ?
            wReserved2 WORD ?
            wReserved3 WORD ?
            union __VARIANT_NAME_3
              llVal LONGLONG ?
              lVal LONG ?
              bVal BYTE ?
              iVal SHORT_ ?
              fltVal FLOAT ?
              dblVal DOUBLE ?
              boolVal VARIANT_BOOL ?
              __OBSOLETE__VARIANT_BOOL VARIANT_BOOL ?
              scode SCODE ?
              cyVal CY <>
              date DATE ?
              bstrVal BSTR ?
              punkVal POINTER ?
              pdispVal POINTER ?
              parray POINTER ?
              pbVal POINTER ?
              piVal POINTER ?
              plVal POINTER ?
              pllVal POINTER ?
              pfltVal POINTER ?
              pdblVal POINTER ?
              pboolVal POINTER ?
              __OBSOLETE__VARIANT_PBOOL POINTER ?
              pscode POINTER ?
              pcyVal POINTER ?
              pdate POINTER ?
              pbstrVal POINTER ?
              ppunkVal POINTER ?
              ppdispVal POINTER ?
              pparray POINTER ?
              pvarVal POINTER ?
              byref PVOID ?
              cVal CHAR ?
              uiVal USHORT ?
              ulVal ULONG ?
              ullVal ULONGLONG ?
              intVal INT_ ?
              uintVal UINT ?
              pdecVal POINTER ?
              pcVal POINTER ?
              puiVal POINTER ?
              pulVal POINTER ?
              pullVal POINTER ?
              pintVal POINTER ?
              puintVal POINTER ?
              struct __VARIANT_NAME_4
                pvRecord PVOID ?
                pRecInfo POINTER ?
              ends
            ends
          ends
          decVal DECIMAL <>
        ends
      tagVARIANT ends
      VARIANT typedef tagVARIANT
      LPVARIANT typedef ptr VARIANT
      VARIANTARG typedef VARIANT
      LPVARIANTARG typedef ptr VARIANT
      ifdef MIDL_PASS
        ;[...]
      else
        ifndef _REFVARIANT_DEFINED
          _REFVARIANT_DEFINED equ <>
          ifdef __cplusplus
            ;[...]
          else
            REFVARIANT equ <const VARIANT * __MIDL_CONST>
          endif
        endif
      endif
      _wireBRECORD struct
        fFlags ULONG ?
        clSize ULONG ?
        pRecInfo POINTER ?
        pRecord POINTER ?
      _wireBRECORD ends
      _wireVARIANT struct
        clSize DWORD ?
        rpcReserved DWORD ?
        vt USHORT ?
        wReserved1 USHORT ?
        wReserved2 USHORT ?
        wReserved3 USHORT ?
        union
          llVal LONGLONG ?
          lVal LONG ?
          bVal BYTE ?
          iVal SHORT_ ?
          fltVal FLOAT ?
          dblVal DOUBLE ?
          boolVal VARIANT_BOOL ?
          scode SCODE ?
          cyVal CY <>
          date DATE ?
          bstrVal wireBSTR ?
          punkVal POINTER ?
          pdispVal POINTER ?
          parray wirePSAFEARRAY ?
          brecVal wireBRECORD ?
          pbVal POINTER ?
          piVal POINTER ?
          plVal POINTER ?
          pllVal POINTER ?
          pfltVal POINTER ?
          pdblVal POINTER ?
          pboolVal POINTER ?
          pscode POINTER ?
          pcyVal POINTER ?
          pdate POINTER ?
          pbstrVal POINTER ?
          ppunkVal POINTER ?
          ppdispVal POINTER ?
          pparray POINTER ?
          pvarVal POINTER ?
          cVal CHAR ?
          uiVal USHORT ?
          ulVal ULONG ?
          ullVal ULONGLONG ?
          intVal INT_ ?
          uintVal UINT ?
          decVal DECIMAL <>
          pdecVal POINTER ?
          pcVal POINTER ?
          puiVal POINTER ?
          pulVal POINTER ?
          pullVal POINTER ?
          pintVal POINTER ?
          puintVal POINTER ?
        ends
      _wireVARIANT ends
      DISPID typedef LONG
      MEMBERID typedef DISPID
      HREFTYPE typedef DWORD
      TYPEKIND typedef SDWORD
      TKIND_ENUM equ 0
      TKIND_RECORD equ 1
      TKIND_MODULE equ 2
      TKIND_INTERFACE equ 3
      TKIND_DISPATCH equ 4
      TKIND_COCLASS equ 5
      TKIND_ALIAS equ 6
      TKIND_UNION equ 7
      TKIND_MAX equ 8
      tagTYPEKIND typedef TYPEKIND

      TYPEDESC struct 4
        union
          lptdesc POINTER ?
          lpadesc POINTER ?
          hreftype HREFTYPE ?
        ends
        vt VARTYPE ?
      TYPEDESC ends
      tagTYPEDESC typedef TYPEDESC
      ARRAYDESC struct 4
        tdescElem TYPEDESC <>
        cDims USHORT ?
        rgbounds SAFEARRAYBOUND 1 dup (<>)
      ARRAYDESC ends
      tagARRAYDESC typedef ARRAYDESC
      PARAMDESCEX struct 8
        cBytes ULONG ?
        varDefaultValue VARIANTARG <>
      PARAMDESCEX ends
      tagPARAMDESCEX typedef PARAMDESCEX
      LPPARAMDESCEX typedef ptr tagPARAMDESCEX
      PARAMDESC struct 4
        pparamdescex LPPARAMDESCEX ?
        wParamFlags USHORT ?
      PARAMDESC ends
      tagPARAMDESC typedef PARAMDESC
      LPPARAMDESC typedef ptr tagPARAMDESC
      PARAMFLAG_NONE equ (0)
      PARAMFLAG_FIN equ (1h)
      PARAMFLAG_FOUT equ (2h)
      PARAMFLAG_FLCID equ (4h)
      PARAMFLAG_FRETVAL equ (8h)
      PARAMFLAG_FOPT equ (10h)
      PARAMFLAG_FHASDEFAULT equ (20h)
      PARAMFLAG_FHASCUSTDATA equ (40h)
      IDLDESC struct 4
        dwReserved ULONG_PTR ?
        wIDLFlags USHORT ?
      IDLDESC ends
      tagIDLDESC typedef IDLDESC
      LPIDLDESC typedef ptr tagIDLDESC
;      IDLFLAG_NONE equ <(PARAMFLAG_NONE)>
;      IDLFLAG_FIN equ <(PARAMFLAG_FIN)>
;      IDLFLAG_FOUT equ <(PARAMFLAG_FOUT)>
;      IDLFLAG_FLCID equ <(PARAMFLAG_FLCID)>
;      IDLFLAG_FRETVAL equ <(PARAMFLAG_FRETVAL)>
      if 0
        ;[...]
      else
        ELEMDESC struct 4
          tdesc TYPEDESC <>
          union
            idldesc IDLDESC <>
            paramdesc PARAMDESC <>
          ends
        ELEMDESC ends
        tagELEMDESC typedef ELEMDESC
        LPELEMDESC typedef ptr ELEMDESC
      endif
      TYPEATTR struct
        guid GUID <>
        lcid LCID ?
        dwReserved DWORD ?
        memidConstructor MEMBERID ?
        memidDestructor MEMBERID ?
        lpstrSchema LPOLESTR ?
        cbSizeInstance ULONG ?
        typekind TYPEKIND ?
        cFuncs WORD ?
        cVars WORD ?
        cImplTypes WORD ?
        cbSizeVft WORD ?
        cbAlignment WORD ?
        wTypeFlags WORD ?
        wMajorVerNum WORD ?
        wMinorVerNum WORD ?
        tdescAlias TYPEDESC <>
        idldescType IDLDESC <>
      TYPEATTR ends
      tagTYPEATTR typedef TYPEATTR
      LPTYPEATTR typedef ptr tagTYPEATTR
      DISPPARAMS struct
        rgvarg POINTER ?
        rgdispidNamedArgs POINTER ?
        cArgs UINT ?
        cNamedArgs UINT ?
      DISPPARAMS ends
      tagDISPPARAMS typedef DISPPARAMS
      if 0
        ;[...]
      else
        EXCEPINFO struct
          wCode WORD ?
          wReserved WORD ?
          bstrSource BSTR ?
          bstrDescription BSTR ?
          bstrHelpFile BSTR ?
          dwHelpContext DWORD ?
          pvReserved PVOID ?
          TYPE_pfnDeferredFillIn typedef proto WIN_STD_CALL_CONV :ptr tagEXCEPINFO
          pfnDeferredFillIn typedef ptr TYPE_pfnDeferredFillIn

          scode SCODE ?
        EXCEPINFO ends
        tagEXCEPINFO typedef EXCEPINFO
        LPEXCEPINFO typedef ptr EXCEPINFO
      endif
      CALLCONV typedef SDWORD
      CC_FASTCALL equ 0
      CC_CDECL equ 1
      CC_MSCPASCAL equ ( CC_CDECL + 1 )
      CC_PASCAL equ CC_MSCPASCAL
      CC_MACPASCAL equ ( CC_PASCAL + 1 )
      CC_STDCALL equ ( CC_MACPASCAL + 1 )
      CC_FPFASTCALL equ ( CC_STDCALL + 1 )
      CC_SYSCALL equ ( CC_FPFASTCALL + 1 )
      CC_MPWCDECL equ ( CC_SYSCALL + 1 )
      CC_MPWPASCAL equ ( CC_MPWCDECL + 1 )
      CC_MAX equ ( CC_MPWPASCAL + 1 )
      tagCALLCONV typedef CALLCONV

      FUNCKIND typedef SDWORD
      FUNC_VIRTUAL equ 0
      FUNC_PUREVIRTUAL equ 1
      FUNC_NONVIRTUAL equ 2
      FUNC_STATIC equ 3
      FUNC_DISPATCH equ 4
      tagFUNCKIND typedef FUNCKIND

      INVOKEKIND typedef SDWORD
      INVOKE_FUNC equ 1
      INVOKE_PROPERTYGET equ 2
      INVOKE_PROPERTYPUT equ 4
      INVOKE_PROPERTYPUTREF equ 8
      tagINVOKEKIND typedef INVOKEKIND

      FUNCDESC struct 4
        memid MEMBERID ?
        lprgscode POINTER ?
        lprgelemdescParam POINTER ?
        funckind FUNCKIND ?
        invkind INVOKEKIND ?
        callconv CALLCONV ?
        cParams SHORT_ ?
        cParamsOpt SHORT_ ?
        oVft SHORT_ ?
        cScodes SHORT_ ?
        elemdescFunc ELEMDESC <>
        wFuncFlags WORD ?
      FUNCDESC ends
      tagFUNCDESC typedef FUNCDESC
      LPFUNCDESC typedef ptr tagFUNCDESC
      VARKIND typedef SDWORD
      VAR_PERINSTANCE equ 0
      VAR_STATIC equ 1
      VAR_CONST equ 2
      VAR_DISPATCH equ 3
      tagVARKIND typedef VARKIND

      IMPLTYPEFLAG_FDEFAULT equ (1h)
      IMPLTYPEFLAG_FSOURCE equ (2h)
      IMPLTYPEFLAG_FRESTRICTED equ (4h)
      IMPLTYPEFLAG_FDEFAULTVTABLE equ (8h)
      VARDESC struct 4
        memid MEMBERID ?
        lpstrSchema LPOLESTR ?
        union
          oInst ULONG ?
          lpvarValue POINTER ?
        ends
        elemdescVar ELEMDESC <>
        wVarFlags WORD ?
        varkind VARKIND ?
      VARDESC ends
      tagVARDESC typedef VARDESC
      LPVARDESC typedef ptr tagVARDESC
      TYPEFLAGS typedef SDWORD
      TYPEFLAG_FAPPOBJECT equ 1h
      TYPEFLAG_FCANCREATE equ 2h
      TYPEFLAG_FLICENSED equ 4h
      TYPEFLAG_FPREDECLID equ 8h
      TYPEFLAG_FHIDDEN equ 10h
      TYPEFLAG_FCONTROL equ 20h
      TYPEFLAG_FDUAL equ 40h
      TYPEFLAG_FNONEXTENSIBLE equ 80h
      TYPEFLAG_FOLEAUTOMATION equ 100h
      TYPEFLAG_FRESTRICTED equ 200h
      TYPEFLAG_FAGGREGATABLE equ 400h
      TYPEFLAG_FREPLACEABLE equ 800h
      TYPEFLAG_FDISPATCHABLE equ 1000h
      TYPEFLAG_FREVERSEBIND equ 2000h
      TYPEFLAG_FPROXY equ 4000h
      tagTYPEFLAGS typedef TYPEFLAGS

      FUNCFLAGS typedef SDWORD
      FUNCFLAG_FRESTRICTED equ 1h
      FUNCFLAG_FSOURCE equ 2h
      FUNCFLAG_FBINDABLE equ 4h
      FUNCFLAG_FREQUESTEDIT equ 8h
      FUNCFLAG_FDISPLAYBIND equ 10h
      FUNCFLAG_FDEFAULTBIND equ 20h
      FUNCFLAG_FHIDDEN equ 40h
      FUNCFLAG_FUSESGETLASTERROR equ 80h
      FUNCFLAG_FDEFAULTCOLLELEM equ 100h
      FUNCFLAG_FUIDEFAULT equ 200h
      FUNCFLAG_FNONBROWSABLE equ 400h
      FUNCFLAG_FREPLACEABLE equ 800h
      FUNCFLAG_FIMMEDIATEBIND equ 1000h
      tagFUNCFLAGS typedef FUNCFLAGS

      VARFLAGS typedef SDWORD
      VARFLAG_FREADONLY equ 1h
      VARFLAG_FSOURCE equ 2h
      VARFLAG_FBINDABLE equ 4h
      VARFLAG_FREQUESTEDIT equ 8h
      VARFLAG_FDISPLAYBIND equ 10h
      VARFLAG_FDEFAULTBIND equ 20h
      VARFLAG_FHIDDEN equ 40h
      VARFLAG_FRESTRICTED equ 80h
      VARFLAG_FDEFAULTCOLLELEM equ 100h
      VARFLAG_FUIDEFAULT equ 200h
      VARFLAG_FNONBROWSABLE equ 400h
      VARFLAG_FREPLACEABLE equ 800h
      VARFLAG_FIMMEDIATEBIND equ 1000h
      tagVARFLAGS typedef VARFLAGS

      CLEANLOCALSTORAGE struct
        pInterface POINTER ?
        pStorage PVOID ?
        flags DWORD ?
      CLEANLOCALSTORAGE ends
      tagCLEANLOCALSTORAGE typedef CLEANLOCALSTORAGE
      CUSTDATAITEM struct
        guid GUID <>
        varValue VARIANTARG <>
      CUSTDATAITEM ends
      tagCUSTDATAITEM typedef CUSTDATAITEM
      LPCUSTDATAITEM typedef ptr tagCUSTDATAITEM
      CUSTDATA struct
        cCustData DWORD ?
        prgCustData LPCUSTDATAITEM ?
      CUSTDATA ends
      tagCUSTDATA typedef CUSTDATA
      LPCUSTDATA typedef ptr tagCUSTDATA
      externdef IOleAutomationTypes_v1_0_c_ifspec:RPC_IF_HANDLE
      externdef IOleAutomationTypes_v1_0_s_ifspec:RPC_IF_HANDLE
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_oaidl_0000_0001_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_oaidl_0000_0001_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ICreateTypeInfo_INTERFACE_DEFINED__
      __ICreateTypeInfo_INTERFACE_DEFINED__ equ <>
      LPCREATETYPEINFO typedef ptr ICreateTypeInfo
      externdef IID_ICreateTypeInfo:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ICreateTypeInfoVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ICreateTypeInfoVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ICreateTypeInfo, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ICreateTypeInfo
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ICreateTypeInfo
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetGuid)
          STD_METHOD SetGuid, :ptr ICreateTypeInfo, :REFGUID
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetTypeFlags)
          STD_METHOD SetTypeFlags, :ptr ICreateTypeInfo, :UINT
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetDocString)
          STD_METHOD SetDocString, :ptr ICreateTypeInfo, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetHelpContext)
          STD_METHOD SetHelpContext, :ptr ICreateTypeInfo, :DWORD
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetVersion)
          STD_METHOD SetVersion, :ptr ICreateTypeInfo, :WORD, :WORD
          DECLSPEC_XFGVIRT(ICreateTypeInfo, AddRefTypeInfo)
          STD_METHOD AddRefTypeInfo, :ptr ICreateTypeInfo, :ptr ITypeInfo, :ptr HREFTYPE
          DECLSPEC_XFGVIRT(ICreateTypeInfo, AddFuncDesc)
          STD_METHOD AddFuncDesc, :ptr ICreateTypeInfo, :UINT, :ptr FUNCDESC
          DECLSPEC_XFGVIRT(ICreateTypeInfo, AddImplType)
          STD_METHOD AddImplType, :ptr ICreateTypeInfo, :UINT, :HREFTYPE
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetImplTypeFlags)
          STD_METHOD SetImplTypeFlags, :ptr ICreateTypeInfo, :UINT, :INT_
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetAlignment)
          STD_METHOD SetAlignment, :ptr ICreateTypeInfo, :WORD
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetSchema)
          STD_METHOD SetSchema, :ptr ICreateTypeInfo, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeInfo, AddVarDesc)
          STD_METHOD AddVarDesc, :ptr ICreateTypeInfo, :UINT, :ptr VARDESC
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetFuncAndParamNames)
          STD_METHOD SetFuncAndParamNames, :ptr ICreateTypeInfo, :UINT, :ptr LPOLESTR, :UINT
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetVarName)
          STD_METHOD SetVarName, :ptr ICreateTypeInfo, :UINT, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetTypeDescAlias)
          STD_METHOD SetTypeDescAlias, :ptr ICreateTypeInfo, :ptr TYPEDESC
          DECLSPEC_XFGVIRT(ICreateTypeInfo, DefineFuncAsDllEntry)
          STD_METHOD DefineFuncAsDllEntry, :ptr ICreateTypeInfo, :UINT, :LPOLESTR, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetFuncDocString)
          STD_METHOD SetFuncDocString, :ptr ICreateTypeInfo, :UINT, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetVarDocString)
          STD_METHOD SetVarDocString, :ptr ICreateTypeInfo, :UINT, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetFuncHelpContext)
          STD_METHOD SetFuncHelpContext, :ptr ICreateTypeInfo, :UINT, :DWORD
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetVarHelpContext)
          STD_METHOD SetVarHelpContext, :ptr ICreateTypeInfo, :UINT, :DWORD
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetMops)
          STD_METHOD SetMops, :ptr ICreateTypeInfo, :UINT, :BSTR
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetTypeIdldesc)
          STD_METHOD SetTypeIdldesc, :ptr ICreateTypeInfo, :ptr IDLDESC
          DECLSPEC_XFGVIRT(ICreateTypeInfo, LayOut)
          STD_METHOD LayOut, :ptr ICreateTypeInfo
          ??Interface equ <>
          END_INTERFACE
        ICreateTypeInfoVtbl ends
        ICreateTypeInfo struct
          lpVtbl POINTER ?
        ICreateTypeInfo ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __ICreateTypeInfo2_INTERFACE_DEFINED__
      __ICreateTypeInfo2_INTERFACE_DEFINED__ equ <>
      LPCREATETYPEINFO2 typedef ptr ICreateTypeInfo2
      externdef IID_ICreateTypeInfo2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ICreateTypeInfo2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ICreateTypeInfo2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ICreateTypeInfo2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ICreateTypeInfo2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ICreateTypeInfo2
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetGuid)
          STD_METHOD SetGuid, :ptr ICreateTypeInfo2, :REFGUID
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetTypeFlags)
          STD_METHOD SetTypeFlags, :ptr ICreateTypeInfo2, :UINT
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetDocString)
          STD_METHOD SetDocString, :ptr ICreateTypeInfo2, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetHelpContext)
          STD_METHOD SetHelpContext, :ptr ICreateTypeInfo2, :DWORD
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetVersion)
          STD_METHOD SetVersion, :ptr ICreateTypeInfo2, :WORD, :WORD
          DECLSPEC_XFGVIRT(ICreateTypeInfo, AddRefTypeInfo)
          STD_METHOD AddRefTypeInfo, :ptr ICreateTypeInfo2, :ptr ITypeInfo, :ptr HREFTYPE
          DECLSPEC_XFGVIRT(ICreateTypeInfo, AddFuncDesc)
          STD_METHOD AddFuncDesc, :ptr ICreateTypeInfo2, :UINT, :ptr FUNCDESC
          DECLSPEC_XFGVIRT(ICreateTypeInfo, AddImplType)
          STD_METHOD AddImplType, :ptr ICreateTypeInfo2, :UINT, :HREFTYPE
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetImplTypeFlags)
          STD_METHOD SetImplTypeFlags, :ptr ICreateTypeInfo2, :UINT, :INT_
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetAlignment)
          STD_METHOD SetAlignment, :ptr ICreateTypeInfo2, :WORD
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetSchema)
          STD_METHOD SetSchema, :ptr ICreateTypeInfo2, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeInfo, AddVarDesc)
          STD_METHOD AddVarDesc, :ptr ICreateTypeInfo2, :UINT, :ptr VARDESC
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetFuncAndParamNames)
          STD_METHOD SetFuncAndParamNames, :ptr ICreateTypeInfo2, :UINT, :ptr LPOLESTR, :UINT
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetVarName)
          STD_METHOD SetVarName, :ptr ICreateTypeInfo2, :UINT, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetTypeDescAlias)
          STD_METHOD SetTypeDescAlias, :ptr ICreateTypeInfo2, :ptr TYPEDESC
          DECLSPEC_XFGVIRT(ICreateTypeInfo, DefineFuncAsDllEntry)
          STD_METHOD DefineFuncAsDllEntry, :ptr ICreateTypeInfo2, :UINT, :LPOLESTR, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetFuncDocString)
          STD_METHOD SetFuncDocString, :ptr ICreateTypeInfo2, :UINT, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetVarDocString)
          STD_METHOD SetVarDocString, :ptr ICreateTypeInfo2, :UINT, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetFuncHelpContext)
          STD_METHOD SetFuncHelpContext, :ptr ICreateTypeInfo2, :UINT, :DWORD
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetVarHelpContext)
          STD_METHOD SetVarHelpContext, :ptr ICreateTypeInfo2, :UINT, :DWORD
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetMops)
          STD_METHOD SetMops, :ptr ICreateTypeInfo2, :UINT, :BSTR
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetTypeIdldesc)
          STD_METHOD SetTypeIdldesc, :ptr ICreateTypeInfo2, :ptr IDLDESC
          DECLSPEC_XFGVIRT(ICreateTypeInfo, LayOut)
          STD_METHOD LayOut, :ptr ICreateTypeInfo2
          DECLSPEC_XFGVIRT(ICreateTypeInfo2, DeleteFuncDesc)
          STD_METHOD DeleteFuncDesc, :ptr ICreateTypeInfo2, :UINT
          DECLSPEC_XFGVIRT(ICreateTypeInfo2, DeleteFuncDescByMemId)
          STD_METHOD DeleteFuncDescByMemId, :ptr ICreateTypeInfo2, :MEMBERID, :INVOKEKIND
          DECLSPEC_XFGVIRT(ICreateTypeInfo2, DeleteVarDesc)
          STD_METHOD DeleteVarDesc, :ptr ICreateTypeInfo2, :UINT
          DECLSPEC_XFGVIRT(ICreateTypeInfo2, DeleteVarDescByMemId)
          STD_METHOD DeleteVarDescByMemId, :ptr ICreateTypeInfo2, :MEMBERID
          DECLSPEC_XFGVIRT(ICreateTypeInfo2, DeleteImplType)
          STD_METHOD DeleteImplType, :ptr ICreateTypeInfo2, :UINT
          DECLSPEC_XFGVIRT(ICreateTypeInfo2, SetCustData)
          STD_METHOD SetCustData, :ptr ICreateTypeInfo2, :REFGUID, :ptr VARIANT
          DECLSPEC_XFGVIRT(ICreateTypeInfo2, SetFuncCustData)
          STD_METHOD SetFuncCustData, :ptr ICreateTypeInfo2, :UINT, :REFGUID, :ptr VARIANT
          DECLSPEC_XFGVIRT(ICreateTypeInfo2, SetParamCustData)
          STD_METHOD SetParamCustData, :ptr ICreateTypeInfo2, :UINT, :UINT, :REFGUID, :ptr VARIANT
          DECLSPEC_XFGVIRT(ICreateTypeInfo2, SetVarCustData)
          STD_METHOD SetVarCustData, :ptr ICreateTypeInfo2, :UINT, :REFGUID, :ptr VARIANT
          DECLSPEC_XFGVIRT(ICreateTypeInfo2, SetImplTypeCustData)
          STD_METHOD SetImplTypeCustData, :ptr ICreateTypeInfo2, :UINT, :REFGUID, :ptr VARIANT
          DECLSPEC_XFGVIRT(ICreateTypeInfo2, SetHelpStringContext)
          STD_METHOD SetHelpStringContext, :ptr ICreateTypeInfo2, :ULONG
          DECLSPEC_XFGVIRT(ICreateTypeInfo2, SetFuncHelpStringContext)
          STD_METHOD SetFuncHelpStringContext, :ptr ICreateTypeInfo2, :UINT, :ULONG
          DECLSPEC_XFGVIRT(ICreateTypeInfo2, SetVarHelpStringContext)
          STD_METHOD SetVarHelpStringContext, :ptr ICreateTypeInfo2, :UINT, :ULONG
          DECLSPEC_XFGVIRT(ICreateTypeInfo2, Invalidate)
          STD_METHOD Invalidate, :ptr ICreateTypeInfo2
          DECLSPEC_XFGVIRT(ICreateTypeInfo2, SetName)
          STD_METHOD SetName, :ptr ICreateTypeInfo2, :LPOLESTR
          ??Interface equ <>
          END_INTERFACE
        ICreateTypeInfo2Vtbl ends
        ICreateTypeInfo2 struct
          lpVtbl POINTER ?
        ICreateTypeInfo2 ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __ICreateTypeLib_INTERFACE_DEFINED__
      __ICreateTypeLib_INTERFACE_DEFINED__ equ <>
      LPCREATETYPELIB typedef ptr ICreateTypeLib
      externdef IID_ICreateTypeLib:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ICreateTypeLibVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ICreateTypeLibVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ICreateTypeLib, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ICreateTypeLib
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ICreateTypeLib
          DECLSPEC_XFGVIRT(ICreateTypeLib, CreateTypeInfo)
          STD_METHOD CreateTypeInfo, :ptr ICreateTypeLib, :LPOLESTR, :TYPEKIND, :ptr ptr ICreateTypeInfo
          DECLSPEC_XFGVIRT(ICreateTypeLib, SetName)
          STD_METHOD SetName, :ptr ICreateTypeLib, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeLib, SetVersion)
          STD_METHOD SetVersion, :ptr ICreateTypeLib, :WORD, :WORD
          DECLSPEC_XFGVIRT(ICreateTypeLib, SetGuid)
          STD_METHOD SetGuid, :ptr ICreateTypeLib, :REFGUID
          DECLSPEC_XFGVIRT(ICreateTypeLib, SetDocString)
          STD_METHOD SetDocString, :ptr ICreateTypeLib, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeLib, SetHelpFileName)
          STD_METHOD SetHelpFileName, :ptr ICreateTypeLib, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeLib, SetHelpContext)
          STD_METHOD SetHelpContext, :ptr ICreateTypeLib, :DWORD
          DECLSPEC_XFGVIRT(ICreateTypeLib, SetLcid)
          STD_METHOD SetLcid, :ptr ICreateTypeLib, :LCID
          DECLSPEC_XFGVIRT(ICreateTypeLib, SetLibFlags)
          STD_METHOD SetLibFlags, :ptr ICreateTypeLib, :UINT
          DECLSPEC_XFGVIRT(ICreateTypeLib, SaveAllChanges)
          STD_METHOD SaveAllChanges, :ptr ICreateTypeLib
          ??Interface equ <>
          END_INTERFACE
        ICreateTypeLibVtbl ends
        ICreateTypeLib struct
          lpVtbl POINTER ?
        ICreateTypeLib ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __ICreateTypeLib2_INTERFACE_DEFINED__
      __ICreateTypeLib2_INTERFACE_DEFINED__ equ <>
      LPCREATETYPELIB2 typedef ptr ICreateTypeLib2
      externdef IID_ICreateTypeLib2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ICreateTypeLib2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ICreateTypeLib2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ICreateTypeLib2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ICreateTypeLib2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ICreateTypeLib2
          DECLSPEC_XFGVIRT(ICreateTypeLib, CreateTypeInfo)
          STD_METHOD CreateTypeInfo, :ptr ICreateTypeLib2, :LPOLESTR, :TYPEKIND, :ptr ptr ICreateTypeInfo
          DECLSPEC_XFGVIRT(ICreateTypeLib, SetName)
          STD_METHOD SetName, :ptr ICreateTypeLib2, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeLib, SetVersion)
          STD_METHOD SetVersion, :ptr ICreateTypeLib2, :WORD, :WORD
          DECLSPEC_XFGVIRT(ICreateTypeLib, SetGuid)
          STD_METHOD SetGuid, :ptr ICreateTypeLib2, :REFGUID
          DECLSPEC_XFGVIRT(ICreateTypeLib, SetDocString)
          STD_METHOD SetDocString, :ptr ICreateTypeLib2, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeLib, SetHelpFileName)
          STD_METHOD SetHelpFileName, :ptr ICreateTypeLib2, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeLib, SetHelpContext)
          STD_METHOD SetHelpContext, :ptr ICreateTypeLib2, :DWORD
          DECLSPEC_XFGVIRT(ICreateTypeLib, SetLcid)
          STD_METHOD SetLcid, :ptr ICreateTypeLib2, :LCID
          DECLSPEC_XFGVIRT(ICreateTypeLib, SetLibFlags)
          STD_METHOD SetLibFlags, :ptr ICreateTypeLib2, :UINT
          DECLSPEC_XFGVIRT(ICreateTypeLib, SaveAllChanges)
          STD_METHOD SaveAllChanges, :ptr ICreateTypeLib2
          DECLSPEC_XFGVIRT(ICreateTypeLib2, DeleteTypeInfo)
          STD_METHOD DeleteTypeInfo, :ptr ICreateTypeLib2, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeLib2, SetCustData)
          STD_METHOD SetCustData, :ptr ICreateTypeLib2, :REFGUID, :ptr VARIANT
          DECLSPEC_XFGVIRT(ICreateTypeLib2, SetHelpStringContext)
          STD_METHOD SetHelpStringContext, :ptr ICreateTypeLib2, :ULONG
          DECLSPEC_XFGVIRT(ICreateTypeLib2, SetHelpStringDll)
          STD_METHOD SetHelpStringDll, :ptr ICreateTypeLib2, :LPOLESTR
          ??Interface equ <>
          END_INTERFACE
        ICreateTypeLib2Vtbl ends
        ICreateTypeLib2 struct
          lpVtbl POINTER ?
        ICreateTypeLib2 ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    externdef __MIDL_itf_oaidl_0000_0005_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_oaidl_0000_0005_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IDispatch_INTERFACE_DEFINED__
      __IDispatch_INTERFACE_DEFINED__ equ <>
      LPDISPATCH typedef ptr IDispatch
      DISPID_UNKNOWN equ (- 1)
      DISPID_VALUE equ (0)
      DISPID_PROPERTYPUT equ (- 3)
      DISPID_NEWENUM equ (- 4)
      DISPID_EVALUATE equ (- 5)
      DISPID_CONSTRUCTOR equ (- 6)
      DISPID_DESTRUCTOR equ (- 7)
      DISPID_COLLECT equ (- 8)
      externdef IID_IDispatch:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IDispatchVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IDispatchVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IDispatch, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IDispatch
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IDispatch
          DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
          STD_METHOD GetTypeInfoCount, :ptr IDispatch, :ptr UINT
          DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
          STD_METHOD GetTypeInfo, :ptr IDispatch, :UINT, :LCID, :ptr ptr ITypeInfo
          DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
          STD_METHOD GetIDsOfNames, :ptr IDispatch, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
          DECLSPEC_XFGVIRT(IDispatch, Invoke)
          STD_METHOD Invoke, :ptr IDispatch, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
          ??Interface equ <>
          END_INTERFACE
        IDispatchVtbl ends
        IDispatch struct
          lpVtbl POINTER ?
        IDispatch ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
      IDispatch_RemoteInvoke_Proxy proto WIN_STD_CALL_CONV :ptr IDispatch, :DISPID, :REFIID, :LCID, :DWORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT, :UINT, :ptr UINT, :ptr VARIANTARG
      IDispatch_RemoteInvoke_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
    endif
    ifndef __IEnumVARIANT_INTERFACE_DEFINED__
      __IEnumVARIANT_INTERFACE_DEFINED__ equ <>
      LPENUMVARIANT typedef ptr IEnumVARIANT
      externdef IID_IEnumVARIANT:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IEnumVARIANTVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IEnumVARIANTVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IEnumVARIANT, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IEnumVARIANT
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IEnumVARIANT
          DECLSPEC_XFGVIRT(IEnumVARIANT, Next)
          STD_METHOD Next, :ptr IEnumVARIANT, :ULONG, :ptr VARIANT, :ptr ULONG
          DECLSPEC_XFGVIRT(IEnumVARIANT, Skip)
          STD_METHOD Skip, :ptr IEnumVARIANT, :ULONG
          DECLSPEC_XFGVIRT(IEnumVARIANT, Reset)
          STD_METHOD Reset, :ptr IEnumVARIANT
          DECLSPEC_XFGVIRT(IEnumVARIANT, Clone)
          STD_METHOD Clone, :ptr IEnumVARIANT, :ptr ptr IEnumVARIANT
          ??Interface equ <>
          END_INTERFACE
        IEnumVARIANTVtbl ends
        IEnumVARIANT struct
          lpVtbl POINTER ?
        IEnumVARIANT ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
      IEnumVARIANT_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumVARIANT, :ULONG, :ptr VARIANT, :ptr ULONG
      IEnumVARIANT_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
    endif
    ifndef __ITypeComp_INTERFACE_DEFINED__
      __ITypeComp_INTERFACE_DEFINED__ equ <>
      LPTYPECOMP typedef ptr ITypeComp
      DESCKIND typedef SDWORD
      DESCKIND_NONE equ 0
      DESCKIND_FUNCDESC equ 1
      DESCKIND_VARDESC equ 2
      DESCKIND_TYPECOMP equ 3
      DESCKIND_IMPLICITAPPOBJ equ 4
      DESCKIND_MAX equ 5
      tagDESCKIND typedef DESCKIND

      BINDPTR union
        lpfuncdesc POINTER ?
        lpvardesc POINTER ?
        lptcomp POINTER ?
      BINDPTR ends
      tagBINDPTR typedef BINDPTR
      LPBINDPTR typedef ptr tagBINDPTR
      externdef IID_ITypeComp:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ITypeCompVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ITypeCompVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ITypeComp, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ITypeComp
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ITypeComp
          DECLSPEC_XFGVIRT(ITypeComp, Bind)
          STD_METHOD Bind, :ptr ITypeComp, :LPOLESTR, :ULONG, :WORD, :ptr ptr ITypeInfo, :ptr DESCKIND, :ptr BINDPTR
          DECLSPEC_XFGVIRT(ITypeComp, BindType)
          STD_METHOD BindType, :ptr ITypeComp, :LPOLESTR, :ULONG, :ptr ptr ITypeInfo, :ptr ptr ITypeComp
          ??Interface equ <>
          END_INTERFACE
        ITypeCompVtbl ends
        ITypeComp struct
          lpVtbl POINTER ?
        ITypeComp ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
      ITypeComp_RemoteBind_Proxy proto WIN_STD_CALL_CONV :ptr ITypeComp, :LPOLESTR, :ULONG, :WORD, :ptr ptr ITypeInfo, :ptr DESCKIND, :ptr LPFUNCDESC, :ptr LPVARDESC, :ptr ptr ITypeComp, :ptr CLEANLOCALSTORAGE
      ITypeComp_RemoteBind_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ITypeComp_RemoteBindType_Proxy proto WIN_STD_CALL_CONV :ptr ITypeComp, :LPOLESTR, :ULONG, :ptr ptr ITypeInfo
      ITypeComp_RemoteBindType_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_oaidl_0000_0008_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_oaidl_0000_0008_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ITypeInfo_INTERFACE_DEFINED__
      __ITypeInfo_INTERFACE_DEFINED__ equ <>
      LPTYPEINFO typedef ptr ITypeInfo
      externdef IID_ITypeInfo:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ITypeInfoVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ITypeInfoVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ITypeInfo, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ITypeInfo
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ITypeInfo
          DECLSPEC_XFGVIRT(ITypeInfo, GetTypeAttr)
          STD_METHOD GetTypeAttr, :ptr ITypeInfo, :ptr ptr TYPEATTR
          DECLSPEC_XFGVIRT(ITypeInfo, GetTypeComp)
          STD_METHOD GetTypeComp, :ptr ITypeInfo, :ptr ptr ITypeComp
          DECLSPEC_XFGVIRT(ITypeInfo, GetFuncDesc)
          STD_METHOD GetFuncDesc, :ptr ITypeInfo, :UINT, :ptr ptr FUNCDESC
          DECLSPEC_XFGVIRT(ITypeInfo, GetVarDesc)
          STD_METHOD GetVarDesc, :ptr ITypeInfo, :UINT, :ptr ptr VARDESC
          DECLSPEC_XFGVIRT(ITypeInfo, GetNames)
          STD_METHOD GetNames, :ptr ITypeInfo, :MEMBERID, :ptr BSTR, :UINT, :ptr UINT
          DECLSPEC_XFGVIRT(ITypeInfo, GetRefTypeOfImplType)
          STD_METHOD GetRefTypeOfImplType, :ptr ITypeInfo, :UINT, :ptr HREFTYPE
          DECLSPEC_XFGVIRT(ITypeInfo, GetImplTypeFlags)
          STD_METHOD GetImplTypeFlags, :ptr ITypeInfo, :UINT, :ptr INT_
          DECLSPEC_XFGVIRT(ITypeInfo, GetIDsOfNames)
          STD_METHOD GetIDsOfNames, :ptr ITypeInfo, :ptr LPOLESTR, :UINT, :ptr MEMBERID
          DECLSPEC_XFGVIRT(ITypeInfo, Invoke)
          STD_METHOD Invoke, :ptr ITypeInfo, :PVOID, :MEMBERID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
          DECLSPEC_XFGVIRT(ITypeInfo, GetDocumentation)
          STD_METHOD GetDocumentation, :ptr ITypeInfo, :MEMBERID, :ptr BSTR, :ptr BSTR, :ptr DWORD, :ptr BSTR
          DECLSPEC_XFGVIRT(ITypeInfo, GetDllEntry)
          STD_METHOD GetDllEntry, :ptr ITypeInfo, :MEMBERID, :INVOKEKIND, :ptr BSTR, :ptr BSTR, :ptr WORD
          DECLSPEC_XFGVIRT(ITypeInfo, GetRefTypeInfo)
          STD_METHOD GetRefTypeInfo, :ptr ITypeInfo, :HREFTYPE, :ptr ptr ITypeInfo
          DECLSPEC_XFGVIRT(ITypeInfo, AddressOfMember)
          STD_METHOD AddressOfMember, :ptr ITypeInfo, :MEMBERID, :INVOKEKIND, :ptr PVOID
          DECLSPEC_XFGVIRT(ITypeInfo, CreateInstance)
          STD_METHOD CreateInstance, :ptr ITypeInfo, :ptr IUnknown, :REFIID, :ptr PVOID
          DECLSPEC_XFGVIRT(ITypeInfo, GetMops)
          STD_METHOD GetMops, :ptr ITypeInfo, :MEMBERID, :ptr BSTR
          DECLSPEC_XFGVIRT(ITypeInfo, GetContainingTypeLib)
          STD_METHOD GetContainingTypeLib, :ptr ITypeInfo, :ptr ptr ITypeLib, :ptr UINT
          DECLSPEC_XFGVIRT(ITypeInfo, ReleaseTypeAttr)
          STD_METHOD ReleaseTypeAttr, :ptr ITypeInfo, :ptr TYPEATTR
          DECLSPEC_XFGVIRT(ITypeInfo, ReleaseFuncDesc)
          STD_METHOD ReleaseFuncDesc, :ptr ITypeInfo, :ptr FUNCDESC
          DECLSPEC_XFGVIRT(ITypeInfo, ReleaseVarDesc)
          STD_METHOD ReleaseVarDesc, :ptr ITypeInfo, :ptr VARDESC
          ??Interface equ <>
          END_INTERFACE
        ITypeInfoVtbl ends
        ITypeInfo struct
          lpVtbl POINTER ?
        ITypeInfo ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
      ITypeInfo_RemoteGetTypeAttr_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :ptr LPTYPEATTR, :ptr CLEANLOCALSTORAGE
      ITypeInfo_RemoteGetTypeAttr_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ITypeInfo_RemoteGetFuncDesc_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :UINT, :ptr LPFUNCDESC, :ptr CLEANLOCALSTORAGE
      ITypeInfo_RemoteGetFuncDesc_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ITypeInfo_RemoteGetVarDesc_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :UINT, :ptr LPVARDESC, :ptr CLEANLOCALSTORAGE
      ITypeInfo_RemoteGetVarDesc_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ITypeInfo_RemoteGetNames_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :MEMBERID, :ptr BSTR, :UINT, :ptr UINT
      ITypeInfo_RemoteGetNames_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ITypeInfo_LocalGetIDsOfNames_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo
      ITypeInfo_LocalGetIDsOfNames_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ITypeInfo_LocalInvoke_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo
      ITypeInfo_LocalInvoke_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ITypeInfo_RemoteGetDocumentation_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :MEMBERID, :DWORD, :ptr BSTR, :ptr BSTR, :ptr DWORD, :ptr BSTR
      ITypeInfo_RemoteGetDocumentation_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ITypeInfo_RemoteGetDllEntry_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :MEMBERID, :INVOKEKIND, :DWORD, :ptr BSTR, :ptr BSTR, :ptr WORD
      ITypeInfo_RemoteGetDllEntry_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ITypeInfo_LocalAddressOfMember_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo
      ITypeInfo_LocalAddressOfMember_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ITypeInfo_RemoteCreateInstance_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :REFIID, :ptr ptr IUnknown
      ITypeInfo_RemoteCreateInstance_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ITypeInfo_RemoteGetContainingTypeLib_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :ptr ptr ITypeLib, :ptr UINT
      ITypeInfo_RemoteGetContainingTypeLib_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ITypeInfo_LocalReleaseTypeAttr_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo
      ITypeInfo_LocalReleaseTypeAttr_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ITypeInfo_LocalReleaseFuncDesc_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo
      ITypeInfo_LocalReleaseFuncDesc_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ITypeInfo_LocalReleaseVarDesc_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo
      ITypeInfo_LocalReleaseVarDesc_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
    endif
    ifndef __ITypeInfo2_INTERFACE_DEFINED__
      __ITypeInfo2_INTERFACE_DEFINED__ equ <>
      LPTYPEINFO2 typedef ptr ITypeInfo2
      externdef IID_ITypeInfo2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ITypeInfo2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ITypeInfo2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ITypeInfo2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ITypeInfo2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ITypeInfo2
          DECLSPEC_XFGVIRT(ITypeInfo, GetTypeAttr)
          STD_METHOD GetTypeAttr, :ptr ITypeInfo2, :ptr ptr TYPEATTR
          DECLSPEC_XFGVIRT(ITypeInfo, GetTypeComp)
          STD_METHOD GetTypeComp, :ptr ITypeInfo2, :ptr ptr ITypeComp
          DECLSPEC_XFGVIRT(ITypeInfo, GetFuncDesc)
          STD_METHOD GetFuncDesc, :ptr ITypeInfo2, :UINT, :ptr ptr FUNCDESC
          DECLSPEC_XFGVIRT(ITypeInfo, GetVarDesc)
          STD_METHOD GetVarDesc, :ptr ITypeInfo2, :UINT, :ptr ptr VARDESC
          DECLSPEC_XFGVIRT(ITypeInfo, GetNames)
          STD_METHOD GetNames, :ptr ITypeInfo2, :MEMBERID, :ptr BSTR, :UINT, :ptr UINT
          DECLSPEC_XFGVIRT(ITypeInfo, GetRefTypeOfImplType)
          STD_METHOD GetRefTypeOfImplType, :ptr ITypeInfo2, :UINT, :ptr HREFTYPE
          DECLSPEC_XFGVIRT(ITypeInfo, GetImplTypeFlags)
          STD_METHOD GetImplTypeFlags, :ptr ITypeInfo2, :UINT, :ptr INT_
          DECLSPEC_XFGVIRT(ITypeInfo, GetIDsOfNames)
          STD_METHOD GetIDsOfNames, :ptr ITypeInfo2, :ptr LPOLESTR, :UINT, :ptr MEMBERID
          DECLSPEC_XFGVIRT(ITypeInfo, Invoke)
          STD_METHOD Invoke, :ptr ITypeInfo2, :PVOID, :MEMBERID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
          DECLSPEC_XFGVIRT(ITypeInfo, GetDocumentation)
          STD_METHOD GetDocumentation, :ptr ITypeInfo2, :MEMBERID, :ptr BSTR, :ptr BSTR, :ptr DWORD, :ptr BSTR
          DECLSPEC_XFGVIRT(ITypeInfo, GetDllEntry)
          STD_METHOD GetDllEntry, :ptr ITypeInfo2, :MEMBERID, :INVOKEKIND, :ptr BSTR, :ptr BSTR, :ptr WORD
          DECLSPEC_XFGVIRT(ITypeInfo, GetRefTypeInfo)
          STD_METHOD GetRefTypeInfo, :ptr ITypeInfo2, :HREFTYPE, :ptr ptr ITypeInfo
          DECLSPEC_XFGVIRT(ITypeInfo, AddressOfMember)
          STD_METHOD AddressOfMember, :ptr ITypeInfo2, :MEMBERID, :INVOKEKIND, :ptr PVOID
          DECLSPEC_XFGVIRT(ITypeInfo, CreateInstance)
          STD_METHOD CreateInstance, :ptr ITypeInfo2, :ptr IUnknown, :REFIID, :ptr PVOID
          DECLSPEC_XFGVIRT(ITypeInfo, GetMops)
          STD_METHOD GetMops, :ptr ITypeInfo2, :MEMBERID, :ptr BSTR
          DECLSPEC_XFGVIRT(ITypeInfo, GetContainingTypeLib)
          STD_METHOD GetContainingTypeLib, :ptr ITypeInfo2, :ptr ptr ITypeLib, :ptr UINT
          DECLSPEC_XFGVIRT(ITypeInfo, ReleaseTypeAttr)
          STD_METHOD ReleaseTypeAttr, :ptr ITypeInfo2, :ptr TYPEATTR
          DECLSPEC_XFGVIRT(ITypeInfo, ReleaseFuncDesc)
          STD_METHOD ReleaseFuncDesc, :ptr ITypeInfo2, :ptr FUNCDESC
          DECLSPEC_XFGVIRT(ITypeInfo, ReleaseVarDesc)
          STD_METHOD ReleaseVarDesc, :ptr ITypeInfo2, :ptr VARDESC
          DECLSPEC_XFGVIRT(ITypeInfo2, GetTypeKind)
          STD_METHOD GetTypeKind, :ptr ITypeInfo2, :ptr TYPEKIND
          DECLSPEC_XFGVIRT(ITypeInfo2, GetTypeFlags)
          STD_METHOD GetTypeFlags, :ptr ITypeInfo2, :ptr ULONG
          DECLSPEC_XFGVIRT(ITypeInfo2, GetFuncIndexOfMemId)
          STD_METHOD GetFuncIndexOfMemId, :ptr ITypeInfo2, :MEMBERID, :INVOKEKIND, :ptr UINT
          DECLSPEC_XFGVIRT(ITypeInfo2, GetVarIndexOfMemId)
          STD_METHOD GetVarIndexOfMemId, :ptr ITypeInfo2, :MEMBERID, :ptr UINT
          DECLSPEC_XFGVIRT(ITypeInfo2, GetCustData)
          STD_METHOD GetCustData, :ptr ITypeInfo2, :REFGUID, :ptr VARIANT
          DECLSPEC_XFGVIRT(ITypeInfo2, GetFuncCustData)
          STD_METHOD GetFuncCustData, :ptr ITypeInfo2, :UINT, :REFGUID, :ptr VARIANT
          DECLSPEC_XFGVIRT(ITypeInfo2, GetParamCustData)
          STD_METHOD GetParamCustData, :ptr ITypeInfo2, :UINT, :UINT, :REFGUID, :ptr VARIANT
          DECLSPEC_XFGVIRT(ITypeInfo2, GetVarCustData)
          STD_METHOD GetVarCustData, :ptr ITypeInfo2, :UINT, :REFGUID, :ptr VARIANT
          DECLSPEC_XFGVIRT(ITypeInfo2, GetImplTypeCustData)
          STD_METHOD GetImplTypeCustData, :ptr ITypeInfo2, :UINT, :REFGUID, :ptr VARIANT
          DECLSPEC_XFGVIRT(ITypeInfo2, GetDocumentation2)
          STD_METHOD GetDocumentation2, :ptr ITypeInfo2, :MEMBERID, :LCID, :ptr BSTR, :ptr DWORD, :ptr BSTR
          DECLSPEC_XFGVIRT(ITypeInfo2, GetAllCustData)
          STD_METHOD GetAllCustData, :ptr ITypeInfo2, :ptr CUSTDATA
          DECLSPEC_XFGVIRT(ITypeInfo2, GetAllFuncCustData)
          STD_METHOD GetAllFuncCustData, :ptr ITypeInfo2, :UINT, :ptr CUSTDATA
          DECLSPEC_XFGVIRT(ITypeInfo2, GetAllParamCustData)
          STD_METHOD GetAllParamCustData, :ptr ITypeInfo2, :UINT, :UINT, :ptr CUSTDATA
          DECLSPEC_XFGVIRT(ITypeInfo2, GetAllVarCustData)
          STD_METHOD GetAllVarCustData, :ptr ITypeInfo2, :UINT, :ptr CUSTDATA
          DECLSPEC_XFGVIRT(ITypeInfo2, GetAllImplTypeCustData)
          STD_METHOD GetAllImplTypeCustData, :ptr ITypeInfo2, :UINT, :ptr CUSTDATA
          ??Interface equ <>
          END_INTERFACE
        ITypeInfo2Vtbl ends
        ITypeInfo2 struct
          lpVtbl POINTER ?
        ITypeInfo2 ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
      ITypeInfo2_RemoteGetDocumentation2_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo2, :MEMBERID, :LCID, :DWORD, :ptr BSTR, :ptr DWORD, :ptr BSTR
      ITypeInfo2_RemoteGetDocumentation2_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    externdef __MIDL_itf_oaidl_0000_0010_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_oaidl_0000_0010_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ITypeLib_INTERFACE_DEFINED__
      __ITypeLib_INTERFACE_DEFINED__ equ <>
      SYSKIND typedef SDWORD
      SYS_WIN16 equ 0
      SYS_WIN32 equ 1
      SYS_MAC equ 2
      SYS_WIN64 equ 3
      tagSYSKIND typedef SYSKIND

      LIBFLAGS typedef SDWORD
      LIBFLAG_FRESTRICTED equ 1h
      LIBFLAG_FCONTROL equ 2h
      LIBFLAG_FHIDDEN equ 4h
      LIBFLAG_FHASDISKIMAGE equ 8h
      tagLIBFLAGS typedef LIBFLAGS

      LPTYPELIB typedef ptr ITypeLib
      TLIBATTR struct 4
        guid GUID <>
        lcid LCID ?
        syskind SYSKIND ?
        wMajorVerNum WORD ?
        wMinorVerNum WORD ?
        wLibFlags WORD ?
      TLIBATTR ends
      tagTLIBATTR typedef TLIBATTR
      LPTLIBATTR typedef ptr tagTLIBATTR
      externdef IID_ITypeLib:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ITypeLibVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ITypeLibVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ITypeLib, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ITypeLib
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ITypeLib
          DECLSPEC_XFGVIRT(ITypeLib, GetTypeInfoCount)
          STD_METHOD GetTypeInfoCount, :ptr ITypeLib
          DECLSPEC_XFGVIRT(ITypeLib, GetTypeInfo)
          STD_METHOD GetTypeInfo, :ptr ITypeLib, :UINT, :ptr ptr ITypeInfo
          DECLSPEC_XFGVIRT(ITypeLib, GetTypeInfoType)
          STD_METHOD GetTypeInfoType, :ptr ITypeLib, :UINT, :ptr TYPEKIND
          DECLSPEC_XFGVIRT(ITypeLib, GetTypeInfoOfGuid)
          STD_METHOD GetTypeInfoOfGuid, :ptr ITypeLib, :REFGUID, :ptr ptr ITypeInfo
          DECLSPEC_XFGVIRT(ITypeLib, GetLibAttr)
          STD_METHOD GetLibAttr, :ptr ITypeLib, :ptr ptr TLIBATTR
          DECLSPEC_XFGVIRT(ITypeLib, GetTypeComp)
          STD_METHOD GetTypeComp, :ptr ITypeLib, :ptr ptr ITypeComp
          DECLSPEC_XFGVIRT(ITypeLib, GetDocumentation)
          STD_METHOD GetDocumentation, :ptr ITypeLib, :INT_, :ptr BSTR, :ptr BSTR, :ptr DWORD, :ptr BSTR
          DECLSPEC_XFGVIRT(ITypeLib, IsName)
          STD_METHOD IsName, :ptr ITypeLib, :LPOLESTR, :ULONG, :ptr BOOL
          DECLSPEC_XFGVIRT(ITypeLib, FindName)
          STD_METHOD FindName, :ptr ITypeLib, :LPOLESTR, :ULONG, :ptr ptr ITypeInfo, :ptr MEMBERID, :ptr USHORT
          DECLSPEC_XFGVIRT(ITypeLib, ReleaseTLibAttr)
          STD_METHOD ReleaseTLibAttr, :ptr ITypeLib, :ptr TLIBATTR
          ??Interface equ <>
          END_INTERFACE
        ITypeLibVtbl ends
        ITypeLib struct
          lpVtbl POINTER ?
        ITypeLib ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
      ITypeLib_RemoteGetTypeInfoCount_Proxy proto WIN_STD_CALL_CONV :ptr ITypeLib, :ptr UINT
      ITypeLib_RemoteGetTypeInfoCount_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ITypeLib_RemoteGetLibAttr_Proxy proto WIN_STD_CALL_CONV :ptr ITypeLib, :ptr LPTLIBATTR, :ptr CLEANLOCALSTORAGE
      ITypeLib_RemoteGetLibAttr_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ITypeLib_RemoteGetDocumentation_Proxy proto WIN_STD_CALL_CONV :ptr ITypeLib, :INT_, :DWORD, :ptr BSTR, :ptr BSTR, :ptr DWORD, :ptr BSTR
      ITypeLib_RemoteGetDocumentation_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ITypeLib_RemoteIsName_Proxy proto WIN_STD_CALL_CONV :ptr ITypeLib, :LPOLESTR, :ULONG, :ptr BOOL, :ptr BSTR
      ITypeLib_RemoteIsName_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ITypeLib_RemoteFindName_Proxy proto WIN_STD_CALL_CONV :ptr ITypeLib, :LPOLESTR, :ULONG, :ptr ptr ITypeInfo, :ptr MEMBERID, :ptr USHORT, :ptr BSTR
      ITypeLib_RemoteFindName_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ITypeLib_LocalReleaseTLibAttr_Proxy proto WIN_STD_CALL_CONV :ptr ITypeLib
      ITypeLib_LocalReleaseTLibAttr_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_oaidl_0000_0011_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_oaidl_0000_0011_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ITypeLib2_INTERFACE_DEFINED__
      __ITypeLib2_INTERFACE_DEFINED__ equ <>
      LPTYPELIB2 typedef ptr ITypeLib2
      externdef IID_ITypeLib2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ITypeLib2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ITypeLib2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ITypeLib2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ITypeLib2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ITypeLib2
          DECLSPEC_XFGVIRT(ITypeLib, GetTypeInfoCount)
          STD_METHOD GetTypeInfoCount, :ptr ITypeLib2
          DECLSPEC_XFGVIRT(ITypeLib, GetTypeInfo)
          STD_METHOD GetTypeInfo, :ptr ITypeLib2, :UINT, :ptr ptr ITypeInfo
          DECLSPEC_XFGVIRT(ITypeLib, GetTypeInfoType)
          STD_METHOD GetTypeInfoType, :ptr ITypeLib2, :UINT, :ptr TYPEKIND
          DECLSPEC_XFGVIRT(ITypeLib, GetTypeInfoOfGuid)
          STD_METHOD GetTypeInfoOfGuid, :ptr ITypeLib2, :REFGUID, :ptr ptr ITypeInfo
          DECLSPEC_XFGVIRT(ITypeLib, GetLibAttr)
          STD_METHOD GetLibAttr, :ptr ITypeLib2, :ptr ptr TLIBATTR
          DECLSPEC_XFGVIRT(ITypeLib, GetTypeComp)
          STD_METHOD GetTypeComp, :ptr ITypeLib2, :ptr ptr ITypeComp
          DECLSPEC_XFGVIRT(ITypeLib, GetDocumentation)
          STD_METHOD GetDocumentation, :ptr ITypeLib2, :INT_, :ptr BSTR, :ptr BSTR, :ptr DWORD, :ptr BSTR
          DECLSPEC_XFGVIRT(ITypeLib, IsName)
          STD_METHOD IsName, :ptr ITypeLib2, :LPOLESTR, :ULONG, :ptr BOOL
          DECLSPEC_XFGVIRT(ITypeLib, FindName)
          STD_METHOD FindName, :ptr ITypeLib2, :LPOLESTR, :ULONG, :ptr ptr ITypeInfo, :ptr MEMBERID, :ptr USHORT
          DECLSPEC_XFGVIRT(ITypeLib, ReleaseTLibAttr)
          STD_METHOD ReleaseTLibAttr, :ptr ITypeLib2, :ptr TLIBATTR
          DECLSPEC_XFGVIRT(ITypeLib2, GetCustData)
          STD_METHOD GetCustData, :ptr ITypeLib2, :REFGUID, :ptr VARIANT
          DECLSPEC_XFGVIRT(ITypeLib2, GetLibStatistics)
          STD_METHOD GetLibStatistics, :ptr ITypeLib2, :ptr ULONG, :ptr ULONG
          DECLSPEC_XFGVIRT(ITypeLib2, GetDocumentation2)
          STD_METHOD GetDocumentation2, :ptr ITypeLib2, :INT_, :LCID, :ptr BSTR, :ptr DWORD, :ptr BSTR
          DECLSPEC_XFGVIRT(ITypeLib2, GetAllCustData)
          STD_METHOD GetAllCustData, :ptr ITypeLib2, :ptr CUSTDATA
          ??Interface equ <>
          END_INTERFACE
        ITypeLib2Vtbl ends
        ITypeLib2 struct
          lpVtbl POINTER ?
        ITypeLib2 ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
      ITypeLib2_RemoteGetLibStatistics_Proxy proto WIN_STD_CALL_CONV :ptr ITypeLib2, :ptr ULONG, :ptr ULONG
      ITypeLib2_RemoteGetLibStatistics_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ITypeLib2_RemoteGetDocumentation2_Proxy proto WIN_STD_CALL_CONV :ptr ITypeLib2, :INT_, :LCID, :DWORD, :ptr BSTR, :ptr DWORD, :ptr BSTR
      ITypeLib2_RemoteGetDocumentation2_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
    endif
    ifndef __ITypeChangeEvents_INTERFACE_DEFINED__
      __ITypeChangeEvents_INTERFACE_DEFINED__ equ <>
      LPTYPECHANGEEVENTS typedef ptr ITypeChangeEvents
      CHANGEKIND typedef SDWORD
      CHANGEKIND_ADDMEMBER equ 0
      CHANGEKIND_DELETEMEMBER equ 1
      CHANGEKIND_SETNAMES equ 2
      CHANGEKIND_SETDOCUMENTATION equ 3
      CHANGEKIND_GENERAL equ 4
      CHANGEKIND_INVALIDATE equ 5
      CHANGEKIND_CHANGEFAILED equ 6
      CHANGEKIND_MAX equ 7
      tagCHANGEKIND typedef CHANGEKIND

      externdef IID_ITypeChangeEvents:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ITypeChangeEventsVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ITypeChangeEventsVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ITypeChangeEvents, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ITypeChangeEvents
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ITypeChangeEvents
          DECLSPEC_XFGVIRT(ITypeChangeEvents, RequestTypeChange)
          STD_METHOD RequestTypeChange, :ptr ITypeChangeEvents, :CHANGEKIND, :ptr ITypeInfo, :LPOLESTR, :ptr INT_
          DECLSPEC_XFGVIRT(ITypeChangeEvents, AfterTypeChange)
          STD_METHOD AfterTypeChange, :ptr ITypeChangeEvents, :CHANGEKIND, :ptr ITypeInfo, :LPOLESTR
          ??Interface equ <>
          END_INTERFACE
        ITypeChangeEventsVtbl ends
        ITypeChangeEvents struct
          lpVtbl POINTER ?
        ITypeChangeEvents ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IErrorInfo_INTERFACE_DEFINED__
      __IErrorInfo_INTERFACE_DEFINED__ equ <>
      LPERRORINFO typedef ptr IErrorInfo
      externdef IID_IErrorInfo:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IErrorInfoVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IErrorInfoVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IErrorInfo, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IErrorInfo
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IErrorInfo
          DECLSPEC_XFGVIRT(IErrorInfo, GetGUID)
          STD_METHOD GetGUID, :ptr IErrorInfo, :ptr GUID
          DECLSPEC_XFGVIRT(IErrorInfo, GetSource)
          STD_METHOD GetSource, :ptr IErrorInfo, :ptr BSTR
          DECLSPEC_XFGVIRT(IErrorInfo, GetDescription)
          STD_METHOD GetDescription, :ptr IErrorInfo, :ptr BSTR
          DECLSPEC_XFGVIRT(IErrorInfo, GetHelpFile)
          STD_METHOD GetHelpFile, :ptr IErrorInfo, :ptr BSTR
          DECLSPEC_XFGVIRT(IErrorInfo, GetHelpContext)
          STD_METHOD GetHelpContext, :ptr IErrorInfo, :ptr DWORD
          ??Interface equ <>
          END_INTERFACE
        IErrorInfoVtbl ends
        IErrorInfo struct
          lpVtbl POINTER ?
        IErrorInfo ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __ICreateErrorInfo_INTERFACE_DEFINED__
      __ICreateErrorInfo_INTERFACE_DEFINED__ equ <>
      LPCREATEERRORINFO typedef ptr ICreateErrorInfo
      externdef IID_ICreateErrorInfo:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ICreateErrorInfoVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ICreateErrorInfoVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ICreateErrorInfo, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ICreateErrorInfo
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ICreateErrorInfo
          DECLSPEC_XFGVIRT(ICreateErrorInfo, SetGUID)
          STD_METHOD SetGUID, :ptr ICreateErrorInfo, :REFGUID
          DECLSPEC_XFGVIRT(ICreateErrorInfo, SetSource)
          STD_METHOD SetSource, :ptr ICreateErrorInfo, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateErrorInfo, SetDescription)
          STD_METHOD SetDescription, :ptr ICreateErrorInfo, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateErrorInfo, SetHelpFile)
          STD_METHOD SetHelpFile, :ptr ICreateErrorInfo, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateErrorInfo, SetHelpContext)
          STD_METHOD SetHelpContext, :ptr ICreateErrorInfo, :DWORD
          ??Interface equ <>
          END_INTERFACE
        ICreateErrorInfoVtbl ends
        ICreateErrorInfo struct
          lpVtbl POINTER ?
        ICreateErrorInfo ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __ISupportErrorInfo_INTERFACE_DEFINED__
      __ISupportErrorInfo_INTERFACE_DEFINED__ equ <>
      LPSUPPORTERRORINFO typedef ptr ISupportErrorInfo
      externdef IID_ISupportErrorInfo:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISupportErrorInfoVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISupportErrorInfoVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ISupportErrorInfo, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISupportErrorInfo
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISupportErrorInfo
          DECLSPEC_XFGVIRT(ISupportErrorInfo, InterfaceSupportsErrorInfo)
          STD_METHOD InterfaceSupportsErrorInfo, :ptr ISupportErrorInfo, :REFIID
          ??Interface equ <>
          END_INTERFACE
        ISupportErrorInfoVtbl ends
        ISupportErrorInfo struct
          lpVtbl POINTER ?
        ISupportErrorInfo ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __ITypeFactory_INTERFACE_DEFINED__
      __ITypeFactory_INTERFACE_DEFINED__ equ <>
      externdef IID_ITypeFactory:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ITypeFactoryVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ITypeFactoryVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ITypeFactory, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ITypeFactory
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ITypeFactory
          DECLSPEC_XFGVIRT(ITypeFactory, CreateFromTypeInfo)
          STD_METHOD CreateFromTypeInfo, :ptr ITypeFactory, :ptr ITypeInfo, :REFIID, :ptr ptr IUnknown
          ??Interface equ <>
          END_INTERFACE
        ITypeFactoryVtbl ends
        ITypeFactory struct
          lpVtbl POINTER ?
        ITypeFactory ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __ITypeMarshal_INTERFACE_DEFINED__
      __ITypeMarshal_INTERFACE_DEFINED__ equ <>
      externdef IID_ITypeMarshal:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ITypeMarshalVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ITypeMarshalVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ITypeMarshal, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ITypeMarshal
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ITypeMarshal
          DECLSPEC_XFGVIRT(ITypeMarshal, Size)
          STD_METHOD Size_, :ptr ITypeMarshal, :PVOID, :DWORD, :PVOID, :ptr ULONG
          DECLSPEC_XFGVIRT(ITypeMarshal, Marshal)
          STD_METHOD Marshal, :ptr ITypeMarshal, :PVOID, :DWORD, :PVOID, :ULONG, :ptr BYTE, :ptr ULONG
          DECLSPEC_XFGVIRT(ITypeMarshal, Unmarshal)
          STD_METHOD Unmarshal, :ptr ITypeMarshal, :PVOID, :DWORD, :ULONG, :ptr BYTE, :ptr ULONG
          DECLSPEC_XFGVIRT(ITypeMarshal, Free)
          STD_METHOD Free, :ptr ITypeMarshal, :PVOID
          ??Interface equ <>
          END_INTERFACE
        ITypeMarshalVtbl ends
        ITypeMarshal struct
          lpVtbl POINTER ?
        ITypeMarshal ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IRecordInfo_INTERFACE_DEFINED__
      __IRecordInfo_INTERFACE_DEFINED__ equ <>
      LPRECORDINFO typedef ptr IRecordInfo
      externdef IID_IRecordInfo:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IRecordInfoVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IRecordInfoVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IRecordInfo, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IRecordInfo
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IRecordInfo
          DECLSPEC_XFGVIRT(IRecordInfo, RecordInit)
          STD_METHOD RecordInit, :ptr IRecordInfo, :PVOID
          DECLSPEC_XFGVIRT(IRecordInfo, RecordClear)
          STD_METHOD RecordClear, :ptr IRecordInfo, :PVOID
          DECLSPEC_XFGVIRT(IRecordInfo, RecordCopy)
          STD_METHOD RecordCopy, :ptr IRecordInfo, :PVOID, :PVOID
          DECLSPEC_XFGVIRT(IRecordInfo, GetGuid)
          STD_METHOD GetGuid, :ptr IRecordInfo, :ptr GUID
          DECLSPEC_XFGVIRT(IRecordInfo, GetName)
          STD_METHOD GetName, :ptr IRecordInfo, :ptr BSTR
          DECLSPEC_XFGVIRT(IRecordInfo, GetSize)
          STD_METHOD GetSize, :ptr IRecordInfo, :ptr ULONG
          DECLSPEC_XFGVIRT(IRecordInfo, GetTypeInfo)
          STD_METHOD GetTypeInfo, :ptr IRecordInfo, :ptr ptr ITypeInfo
          DECLSPEC_XFGVIRT(IRecordInfo, GetField)
          STD_METHOD GetField, :ptr IRecordInfo, :PVOID, :LPCOLESTR, :ptr VARIANT
          DECLSPEC_XFGVIRT(IRecordInfo, GetFieldNoCopy)
          STD_METHOD GetFieldNoCopy, :ptr IRecordInfo, :PVOID, :LPCOLESTR, :ptr VARIANT, :ptr PVOID
          DECLSPEC_XFGVIRT(IRecordInfo, PutField)
          STD_METHOD PutField, :ptr IRecordInfo, :ULONG, :PVOID, :LPCOLESTR, :ptr VARIANT
          DECLSPEC_XFGVIRT(IRecordInfo, PutFieldNoCopy)
          STD_METHOD PutFieldNoCopy, :ptr IRecordInfo, :ULONG, :PVOID, :LPCOLESTR, :ptr VARIANT
          DECLSPEC_XFGVIRT(IRecordInfo, GetFieldNames)
          STD_METHOD GetFieldNames, :ptr IRecordInfo, :ptr ULONG, :ptr BSTR
          DECLSPEC_XFGVIRT(IRecordInfo, IsMatchingType)
          STD_METHOD IsMatchingType, :ptr IRecordInfo, :ptr IRecordInfo
          DECLSPEC_XFGVIRT(IRecordInfo, RecordCreate)
          STD_METHOD RecordCreate, :ptr IRecordInfo
          DECLSPEC_XFGVIRT(IRecordInfo, RecordCreateCopy)
          STD_METHOD RecordCreateCopy, :ptr IRecordInfo, :PVOID, :ptr PVOID
          DECLSPEC_XFGVIRT(IRecordInfo, RecordDestroy)
          STD_METHOD RecordDestroy, :ptr IRecordInfo, :PVOID
          ??Interface equ <>
          END_INTERFACE
        IRecordInfoVtbl ends
        IRecordInfo struct
          lpVtbl POINTER ?
        IRecordInfo ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IErrorLog_INTERFACE_DEFINED__
      __IErrorLog_INTERFACE_DEFINED__ equ <>
      LPERRORLOG typedef ptr IErrorLog
      externdef IID_IErrorLog:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IErrorLogVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IErrorLogVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IErrorLog, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IErrorLog
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IErrorLog
          DECLSPEC_XFGVIRT(IErrorLog, AddError)
          STD_METHOD AddError, :ptr IErrorLog, :LPCOLESTR, :ptr EXCEPINFO
          ??Interface equ <>
          END_INTERFACE
        IErrorLogVtbl ends
        IErrorLog struct
          lpVtbl POINTER ?
        IErrorLog ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __IPropertyBag_INTERFACE_DEFINED__
      __IPropertyBag_INTERFACE_DEFINED__ equ <>
      LPPROPERTYBAG typedef ptr IPropertyBag
      externdef IID_IPropertyBag:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPropertyBagVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPropertyBagVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr IPropertyBag, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPropertyBag
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPropertyBag
          DECLSPEC_XFGVIRT(IPropertyBag, Read)
          STD_METHOD Read, :ptr IPropertyBag, :LPCOLESTR, :ptr VARIANT, :ptr IErrorLog
          DECLSPEC_XFGVIRT(IPropertyBag, Write)
          STD_METHOD Write, :ptr IPropertyBag, :LPCOLESTR, :ptr VARIANT
          ??Interface equ <>
          END_INTERFACE
        IPropertyBagVtbl ends
        IPropertyBag struct
          lpVtbl POINTER ?
        IPropertyBag ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
      IPropertyBag_RemoteRead_Proxy proto WIN_STD_CALL_CONV :ptr IPropertyBag, :LPCOLESTR, :ptr VARIANT, :ptr IErrorLog, :DWORD, :ptr IUnknown
      IPropertyBag_RemoteRead_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
    endif
    ifndef __ITypeLibRegistrationReader_INTERFACE_DEFINED__
      __ITypeLibRegistrationReader_INTERFACE_DEFINED__ equ <>
      externdef IID_ITypeLibRegistrationReader:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ITypeLibRegistrationReaderVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ITypeLibRegistrationReaderVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ITypeLibRegistrationReader, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ITypeLibRegistrationReader
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ITypeLibRegistrationReader
          DECLSPEC_XFGVIRT(ITypeLibRegistrationReader, EnumTypeLibRegistrations)
          STD_METHOD EnumTypeLibRegistrations, :ptr ITypeLibRegistrationReader, :ptr ptr IEnumUnknown
          ??Interface equ <>
          END_INTERFACE
        ITypeLibRegistrationReaderVtbl ends
        ITypeLibRegistrationReader struct
          lpVtbl POINTER ?
        ITypeLibRegistrationReader ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    ifndef __ITypeLibRegistration_INTERFACE_DEFINED__
      __ITypeLibRegistration_INTERFACE_DEFINED__ equ <>
      externdef IID_ITypeLibRegistration:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ITypeLibRegistrationVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ITypeLibRegistrationVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          STD_METHOD QueryInterface, :ptr ITypeLibRegistration, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ITypeLibRegistration
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ITypeLibRegistration
          DECLSPEC_XFGVIRT(ITypeLibRegistration, GetGuid)
          STD_METHOD GetGuid, :ptr ITypeLibRegistration, :ptr GUID
          DECLSPEC_XFGVIRT(ITypeLibRegistration, GetVersion)
          STD_METHOD GetVersion, :ptr ITypeLibRegistration, :ptr BSTR
          DECLSPEC_XFGVIRT(ITypeLibRegistration, GetLcid)
          STD_METHOD GetLcid, :ptr ITypeLibRegistration, :ptr LCID
          DECLSPEC_XFGVIRT(ITypeLibRegistration, GetWin32Path)
          STD_METHOD GetWin32Path, :ptr ITypeLibRegistration, :ptr BSTR
          DECLSPEC_XFGVIRT(ITypeLibRegistration, GetWin64Path)
          STD_METHOD GetWin64Path, :ptr ITypeLibRegistration, :ptr BSTR
          DECLSPEC_XFGVIRT(ITypeLibRegistration, GetDisplayName)
          STD_METHOD GetDisplayName, :ptr ITypeLibRegistration, :ptr BSTR
          DECLSPEC_XFGVIRT(ITypeLibRegistration, GetFlags)
          STD_METHOD GetFlags, :ptr ITypeLibRegistration, :ptr DWORD
          DECLSPEC_XFGVIRT(ITypeLibRegistration, GetHelpDir)
          STD_METHOD GetHelpDir, :ptr ITypeLibRegistration, :ptr BSTR
          ??Interface equ <>
          END_INTERFACE
        ITypeLibRegistrationVtbl ends
        ITypeLibRegistration struct
          lpVtbl POINTER ?
        ITypeLibRegistration ends
        ifdef COBJMACROS
          ;[...]
        endif
      endif
    endif
    externdef CLSID_TypeLibRegistrationReader:CLSID
  endif
  if (_MSC_VER ge 800)
    if _MSC_VER ge 1200
    else
    endif
  endif
  externdef __MIDL_itf_oaidl_0000_0023_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_oaidl_0000_0023_v0_0_s_ifspec:RPC_IF_HANDLE
  BSTR_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr BSTR
  BSTR_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BSTR
  CLEANLOCALSTORAGE_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr CLEANLOCALSTORAGE
  CLEANLOCALSTORAGE_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr CLEANLOCALSTORAGE
  CLEANLOCALSTORAGE_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr CLEANLOCALSTORAGE
  CLEANLOCALSTORAGE_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr CLEANLOCALSTORAGE
  VARIANT_UserSize proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr VARIANT
  VARIANT_UserMarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr VARIANT
  VARIANT_UserUnmarshal proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr VARIANT
  VARIANT_UserFree proto WIN_STD_CALL_CONV :ptr DWORD, :ptr VARIANT
  BSTR_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr BSTR
  BSTR_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr BSTR
  BSTR_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BSTR
  CLEANLOCALSTORAGE_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr CLEANLOCALSTORAGE
  CLEANLOCALSTORAGE_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr CLEANLOCALSTORAGE
  CLEANLOCALSTORAGE_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr CLEANLOCALSTORAGE
  CLEANLOCALSTORAGE_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr CLEANLOCALSTORAGE
  VARIANT_UserSize64 proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr VARIANT
  VARIANT_UserMarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr VARIANT
  VARIANT_UserUnmarshal64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr BYTE, :ptr VARIANT
  VARIANT_UserFree64 proto WIN_STD_CALL_CONV :ptr DWORD, :ptr VARIANT
  IDispatch_Invoke_Proxy proto WIN_STD_CALL_CONV :ptr IDispatch, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
  IDispatch_Invoke_Stub proto WIN_STD_CALL_CONV :ptr IDispatch, :DISPID, :REFIID, :LCID, :DWORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT, :UINT, :ptr UINT, :ptr VARIANTARG
  IEnumVARIANT_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumVARIANT, :ULONG, :ptr VARIANT, :ptr ULONG
  IEnumVARIANT_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumVARIANT, :ULONG, :ptr VARIANT, :ptr ULONG
  ITypeComp_Bind_Proxy proto WIN_STD_CALL_CONV :ptr ITypeComp, :LPOLESTR, :ULONG, :WORD, :ptr ptr ITypeInfo, :ptr DESCKIND, :ptr BINDPTR
  ITypeComp_Bind_Stub proto WIN_STD_CALL_CONV :ptr ITypeComp, :LPOLESTR, :ULONG, :WORD, :ptr ptr ITypeInfo, :ptr DESCKIND, :ptr LPFUNCDESC, :ptr LPVARDESC, :ptr ptr ITypeComp, :ptr CLEANLOCALSTORAGE
  ITypeComp_BindType_Proxy proto WIN_STD_CALL_CONV :ptr ITypeComp, :LPOLESTR, :ULONG, :ptr ptr ITypeInfo, :ptr ptr ITypeComp
  ITypeComp_BindType_Stub proto WIN_STD_CALL_CONV :ptr ITypeComp, :LPOLESTR, :ULONG, :ptr ptr ITypeInfo
  ITypeInfo_GetTypeAttr_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :ptr ptr TYPEATTR
  ITypeInfo_GetTypeAttr_Stub proto WIN_STD_CALL_CONV :ptr ITypeInfo, :ptr LPTYPEATTR, :ptr CLEANLOCALSTORAGE
  ITypeInfo_GetFuncDesc_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :UINT, :ptr ptr FUNCDESC
  ITypeInfo_GetFuncDesc_Stub proto WIN_STD_CALL_CONV :ptr ITypeInfo, :UINT, :ptr LPFUNCDESC, :ptr CLEANLOCALSTORAGE
  ITypeInfo_GetVarDesc_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :UINT, :ptr ptr VARDESC
  ITypeInfo_GetVarDesc_Stub proto WIN_STD_CALL_CONV :ptr ITypeInfo, :UINT, :ptr LPVARDESC, :ptr CLEANLOCALSTORAGE
  ITypeInfo_GetNames_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :MEMBERID, :ptr BSTR, :UINT, :ptr UINT
  ITypeInfo_GetNames_Stub proto WIN_STD_CALL_CONV :ptr ITypeInfo, :MEMBERID, :ptr BSTR, :UINT, :ptr UINT
  ITypeInfo_GetIDsOfNames_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :ptr LPOLESTR, :UINT, :ptr MEMBERID
  ITypeInfo_GetIDsOfNames_Stub proto WIN_STD_CALL_CONV :ptr ITypeInfo
  ITypeInfo_Invoke_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :PVOID, :MEMBERID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
  ITypeInfo_Invoke_Stub proto WIN_STD_CALL_CONV :ptr ITypeInfo
  ITypeInfo_GetDocumentation_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :MEMBERID, :ptr BSTR, :ptr BSTR, :ptr DWORD, :ptr BSTR
  ITypeInfo_GetDocumentation_Stub proto WIN_STD_CALL_CONV :ptr ITypeInfo, :MEMBERID, :DWORD, :ptr BSTR, :ptr BSTR, :ptr DWORD, :ptr BSTR
  ITypeInfo_GetDllEntry_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :MEMBERID, :INVOKEKIND, :ptr BSTR, :ptr BSTR, :ptr WORD
  ITypeInfo_GetDllEntry_Stub proto WIN_STD_CALL_CONV :ptr ITypeInfo, :MEMBERID, :INVOKEKIND, :DWORD, :ptr BSTR, :ptr BSTR, :ptr WORD
  ITypeInfo_AddressOfMember_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :MEMBERID, :INVOKEKIND, :ptr PVOID
  ITypeInfo_AddressOfMember_Stub proto WIN_STD_CALL_CONV :ptr ITypeInfo
  ITypeInfo_CreateInstance_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :ptr IUnknown, :REFIID, :ptr PVOID
  ITypeInfo_CreateInstance_Stub proto WIN_STD_CALL_CONV :ptr ITypeInfo, :REFIID, :ptr ptr IUnknown
  ITypeInfo_GetContainingTypeLib_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :ptr ptr ITypeLib, :ptr UINT
  ITypeInfo_GetContainingTypeLib_Stub proto WIN_STD_CALL_CONV :ptr ITypeInfo, :ptr ptr ITypeLib, :ptr UINT
  ITypeInfo_ReleaseTypeAttr_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :ptr TYPEATTR
  ITypeInfo_ReleaseTypeAttr_Stub proto WIN_STD_CALL_CONV :ptr ITypeInfo
  ITypeInfo_ReleaseFuncDesc_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :ptr FUNCDESC
  ITypeInfo_ReleaseFuncDesc_Stub proto WIN_STD_CALL_CONV :ptr ITypeInfo
  ITypeInfo_ReleaseVarDesc_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :ptr VARDESC
  ITypeInfo_ReleaseVarDesc_Stub proto WIN_STD_CALL_CONV :ptr ITypeInfo
  ITypeInfo2_GetDocumentation2_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo2, :MEMBERID, :LCID, :ptr BSTR, :ptr DWORD, :ptr BSTR
  ITypeInfo2_GetDocumentation2_Stub proto WIN_STD_CALL_CONV :ptr ITypeInfo2, :MEMBERID, :LCID, :DWORD, :ptr BSTR, :ptr DWORD, :ptr BSTR
  ITypeLib_GetTypeInfoCount_Proxy proto WIN_STD_CALL_CONV :ptr ITypeLib
  ITypeLib_GetTypeInfoCount_Stub proto WIN_STD_CALL_CONV :ptr ITypeLib, :ptr UINT
  ITypeLib_GetLibAttr_Proxy proto WIN_STD_CALL_CONV :ptr ITypeLib, :ptr ptr TLIBATTR
  ITypeLib_GetLibAttr_Stub proto WIN_STD_CALL_CONV :ptr ITypeLib, :ptr LPTLIBATTR, :ptr CLEANLOCALSTORAGE
  ITypeLib_GetDocumentation_Proxy proto WIN_STD_CALL_CONV :ptr ITypeLib, :INT_, :ptr BSTR, :ptr BSTR, :ptr DWORD, :ptr BSTR
  ITypeLib_GetDocumentation_Stub proto WIN_STD_CALL_CONV :ptr ITypeLib, :INT_, :DWORD, :ptr BSTR, :ptr BSTR, :ptr DWORD, :ptr BSTR
  ITypeLib_IsName_Proxy proto WIN_STD_CALL_CONV :ptr ITypeLib, :LPOLESTR, :ULONG, :ptr BOOL
  ITypeLib_IsName_Stub proto WIN_STD_CALL_CONV :ptr ITypeLib, :LPOLESTR, :ULONG, :ptr BOOL, :ptr BSTR
  ITypeLib_FindName_Proxy proto WIN_STD_CALL_CONV :ptr ITypeLib, :LPOLESTR, :ULONG, :ptr ptr ITypeInfo, :ptr MEMBERID, :ptr USHORT
  ITypeLib_FindName_Stub proto WIN_STD_CALL_CONV :ptr ITypeLib, :LPOLESTR, :ULONG, :ptr ptr ITypeInfo, :ptr MEMBERID, :ptr USHORT, :ptr BSTR
  ITypeLib_ReleaseTLibAttr_Proxy proto WIN_STD_CALL_CONV :ptr ITypeLib, :ptr TLIBATTR
  ITypeLib_ReleaseTLibAttr_Stub proto WIN_STD_CALL_CONV :ptr ITypeLib
  ITypeLib2_GetLibStatistics_Proxy proto WIN_STD_CALL_CONV :ptr ITypeLib2, :ptr ULONG, :ptr ULONG
  ITypeLib2_GetLibStatistics_Stub proto WIN_STD_CALL_CONV :ptr ITypeLib2, :ptr ULONG, :ptr ULONG
  ITypeLib2_GetDocumentation2_Proxy proto WIN_STD_CALL_CONV :ptr ITypeLib2, :INT_, :LCID, :ptr BSTR, :ptr DWORD, :ptr BSTR
  ITypeLib2_GetDocumentation2_Stub proto WIN_STD_CALL_CONV :ptr ITypeLib2, :INT_, :LCID, :DWORD, :ptr BSTR, :ptr DWORD, :ptr BSTR
  IPropertyBag_Read_Proxy proto WIN_STD_CALL_CONV :ptr IPropertyBag, :LPCOLESTR, :ptr VARIANT, :ptr IErrorLog
  IPropertyBag_Read_Stub proto WIN_STD_CALL_CONV :ptr IPropertyBag, :LPCOLESTR, :ptr VARIANT, :ptr IErrorLog, :DWORD, :ptr IUnknown
  ifdef __cplusplus
    ;[...]
  endif
endif
