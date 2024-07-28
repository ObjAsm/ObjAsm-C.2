;Include file created by h2incX, Version B.01.01, 22/10/2018 23:24
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\oaidl.h', last modified: 19/04/2018 10:46
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
ifndef __oaidl_h__
  __oaidl_h__ equ <>
  if Defined(_MSC_VER) and (_MSC_VER ge 1020)
  endif
  ifndef __ICreateTypeInfo_FWD_DEFINED__
    __ICreateTypeInfo_FWD_DEFINED__ equ <>
    ;ICreateTypeInfo typedef ICreateTypeInfo
    
  endif
  ifndef __ICreateTypeInfo2_FWD_DEFINED__
    __ICreateTypeInfo2_FWD_DEFINED__ equ <>
    ;ICreateTypeInfo2 typedef ICreateTypeInfo2
    
  endif
  ifndef __ICreateTypeLib_FWD_DEFINED__
    __ICreateTypeLib_FWD_DEFINED__ equ <>
    ;ICreateTypeLib typedef ICreateTypeLib
    
  endif
  ifndef __ICreateTypeLib2_FWD_DEFINED__
    __ICreateTypeLib2_FWD_DEFINED__ equ <>
    ;ICreateTypeLib2 typedef ICreateTypeLib2
    
  endif
  ifndef __IDispatch_FWD_DEFINED__
    __IDispatch_FWD_DEFINED__ equ <>
    ;IDispatch typedef IDispatch
    
  endif
  ifndef __IEnumVARIANT_FWD_DEFINED__
    __IEnumVARIANT_FWD_DEFINED__ equ <>
    ;IEnumVARIANT typedef IEnumVARIANT
    
  endif
  ifndef __ITypeComp_FWD_DEFINED__
    __ITypeComp_FWD_DEFINED__ equ <>
    ;ITypeComp typedef ITypeComp
    
  endif
  ifndef __ITypeInfo_FWD_DEFINED__
    __ITypeInfo_FWD_DEFINED__ equ <>
    ;ITypeInfo typedef ITypeInfo
    
  endif
  ifndef __ITypeInfo2_FWD_DEFINED__
    __ITypeInfo2_FWD_DEFINED__ equ <>
    ;ITypeInfo2 typedef ITypeInfo2
    
  endif
  ifndef __ITypeLib_FWD_DEFINED__
    __ITypeLib_FWD_DEFINED__ equ <>
    ;ITypeLib typedef ITypeLib
    
  endif
  ifndef __ITypeLib2_FWD_DEFINED__
    __ITypeLib2_FWD_DEFINED__ equ <>
    ;ITypeLib2 typedef ITypeLib2
    
  endif
  ifndef __ITypeChangeEvents_FWD_DEFINED__
    __ITypeChangeEvents_FWD_DEFINED__ equ <>
    ;ITypeChangeEvents typedef ITypeChangeEvents
    
  endif
  ifndef __IErrorInfo_FWD_DEFINED__
    __IErrorInfo_FWD_DEFINED__ equ <>
    ;IErrorInfo typedef IErrorInfo
    
  endif
  ifndef __ICreateErrorInfo_FWD_DEFINED__
    __ICreateErrorInfo_FWD_DEFINED__ equ <>
    ;ICreateErrorInfo typedef ICreateErrorInfo
    
  endif
  ifndef __ISupportErrorInfo_FWD_DEFINED__
    __ISupportErrorInfo_FWD_DEFINED__ equ <>
    ;ISupportErrorInfo typedef ISupportErrorInfo
    
  endif
  ifndef __ITypeFactory_FWD_DEFINED__
    __ITypeFactory_FWD_DEFINED__ equ <>
    ;ITypeFactory typedef ITypeFactory
    
  endif
  ifndef __ITypeMarshal_FWD_DEFINED__
    __ITypeMarshal_FWD_DEFINED__ equ <>
    ;ITypeMarshal typedef ITypeMarshal
    
  endif
  ifndef __IRecordInfo_FWD_DEFINED__
    __IRecordInfo_FWD_DEFINED__ equ <>
    ;IRecordInfo typedef IRecordInfo
    
  endif
  ifndef __IErrorLog_FWD_DEFINED__
    __IErrorLog_FWD_DEFINED__ equ <>
    ;IErrorLog typedef IErrorLog
    
  endif
  ifndef __IPropertyBag_FWD_DEFINED__
    __IPropertyBag_FWD_DEFINED__ equ <>
    ;IPropertyBag typedef IPropertyBag
    
  endif
  ifndef __ITypeLibRegistrationReader_FWD_DEFINED__
    __ITypeLibRegistrationReader_FWD_DEFINED__ equ <>
    ;ITypeLibRegistrationReader typedef ITypeLibRegistrationReader
    
  endif
  ifndef __ITypeLibRegistration_FWD_DEFINED__
    __ITypeLibRegistration_FWD_DEFINED__ equ <>
    ;ITypeLibRegistration typedef ITypeLibRegistration
    
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
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
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
      FADF_AUTO equ 1h
      FADF_STATIC equ 2h
      FADF_EMBEDDED equ 4h
      FADF_FIXEDSIZE equ 10h
      FADF_RECORD equ 20h
      FADF_HAVEIID equ 40h
      FADF_HAVEVARTYPE equ 80h
      FADF_BSTR equ 100h
      FADF_UNKNOWN equ 200h
      FADF_DISPATCH equ 400h
      FADF_VARIANT equ 800h
      FADF_RESERVED equ 0f008h
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
              bool VARIANT_BOOL ?
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
              pbool POINTER ?
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
            REFVARIANT equ <ptr VARIANT>
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
      
      PARAMFLAG_NONE equ 0
      PARAMFLAG_FIN equ 1h
      PARAMFLAG_FOUT equ 2h
      PARAMFLAG_FLCID equ 4h
      PARAMFLAG_FRETVAL equ 8h
      PARAMFLAG_FOPT equ 10h
      PARAMFLAG_FHASDEFAULT equ 20h
      PARAMFLAG_FHASCUSTDATA equ 40h
      IDLDESC struct 4
        dwReserved ULONG_PTR ?
        wIDLFlags USHORT ?
      IDLDESC ends

      tagIDLDESC typedef IDLDESC
      LPIDLDESC typedef ptr tagIDLDESC
      
      IDLFLAG_NONE equ <(PARAMFLAG_NONE)>
      IDLFLAG_FIN equ <(PARAMFLAG_FIN)>
      IDLFLAG_FOUT equ <(PARAMFLAG_FOUT)>
      IDLFLAG_FLCID equ <(PARAMFLAG_FLCID)>
      IDLFLAG_FRETVAL equ <(PARAMFLAG_FRETVAL)>
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
          pfnDeferredFillIn TYPE_pfnDeferredFillIn  ?
          scode SCODE ?
        EXCEPINFO ends

;        tagEXCEPINFO typedef EXCEPINFO
        LPEXCEPINFO typedef ptr EXCEPINFO
        
      endif
      CALLCONV typedef SDWORD
      CC_FASTCALL equ 0
      CC_CDECL equ 1
      CC_MSCPASCAL equ 2
      CC_PASCAL equ CC_MSCPASCAL
      CC_MACPASCAL equ
      CC_STDCALL equ
      CC_FPFASTCALL equ
      CC_SYSCALL equ
      CC_MPWCDECL equ
      CC_MPWPASCAL equ
      CC_MAX equ
      tagCALLCONV typedef CALLCONV
      
      FUNCKIND typedef SDWORD
      FUNC_VIRTUAL equ 0
      FUNC_PUREVIRTUAL equ
      FUNC_NONVIRTUAL equ
      FUNC_STATIC equ
      FUNC_DISPATCH equ
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
      VAR_STATIC equ
      VAR_CONST equ
      VAR_DISPATCH equ
      tagVARKIND typedef VARKIND
      
      IMPLTYPEFLAG_FDEFAULT equ 1h
      IMPLTYPEFLAG_FSOURCE equ 2h
      IMPLTYPEFLAG_FRESTRICTED equ 4h
      IMPLTYPEFLAG_FDEFAULTVTABLE equ 8h
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
          STD_METHOD QueryInterface, :ptr ICreateTypeInfo, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr ICreateTypeInfo
          STD_METHOD Release, :ptr ICreateTypeInfo
          STD_METHOD SetGuid, :ptr ICreateTypeInfo, :REFGUID
          STD_METHOD SetTypeFlags, :ptr ICreateTypeInfo, :UINT
          STD_METHOD SetDocString, :ptr ICreateTypeInfo, :LPOLESTR
          STD_METHOD SetHelpContext, :ptr ICreateTypeInfo, :DWORD
          STD_METHOD SetVersion, :ptr ICreateTypeInfo, :WORD, :WORD
          STD_METHOD AddRefTypeInfo, :ptr ICreateTypeInfo, :ptr ITypeInfo, :ptr HREFTYPE
          STD_METHOD AddFuncDesc, :ptr ICreateTypeInfo, :UINT, :ptr FUNCDESC
          STD_METHOD AddImplType, :ptr ICreateTypeInfo, :UINT, :HREFTYPE
          STD_METHOD SetImplTypeFlags, :ptr ICreateTypeInfo, :UINT, :INT_
          STD_METHOD SetAlignment, :ptr ICreateTypeInfo, :WORD
          STD_METHOD SetSchema, :ptr ICreateTypeInfo, :LPOLESTR
          STD_METHOD AddVarDesc, :ptr ICreateTypeInfo, :UINT, :ptr VARDESC
          STD_METHOD SetFuncAndParamNames, :ptr ICreateTypeInfo, :UINT, :ptr LPOLESTR, :UINT
          STD_METHOD SetVarName, :ptr ICreateTypeInfo, :UINT, :LPOLESTR
          STD_METHOD SetTypeDescAlias, :ptr ICreateTypeInfo, :ptr TYPEDESC
          STD_METHOD DefineFuncAsDllEntry, :ptr ICreateTypeInfo, :UINT, :LPOLESTR, :LPOLESTR
          STD_METHOD SetFuncDocString, :ptr ICreateTypeInfo, :UINT, :LPOLESTR
          STD_METHOD SetVarDocString, :ptr ICreateTypeInfo, :UINT, :LPOLESTR
          STD_METHOD SetFuncHelpContext, :ptr ICreateTypeInfo, :UINT, :DWORD
          STD_METHOD SetVarHelpContext, :ptr ICreateTypeInfo, :UINT, :DWORD
          STD_METHOD SetMops, :ptr ICreateTypeInfo, :UINT, :BSTR
          STD_METHOD SetTypeIdldesc, :ptr ICreateTypeInfo, :ptr IDLDESC
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
          STD_METHOD QueryInterface, :ptr ICreateTypeInfo2, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr ICreateTypeInfo2
          STD_METHOD Release, :ptr ICreateTypeInfo2
          STD_METHOD SetGuid, :ptr ICreateTypeInfo2, :REFGUID
          STD_METHOD SetTypeFlags, :ptr ICreateTypeInfo2, :UINT
          STD_METHOD SetDocString, :ptr ICreateTypeInfo2, :LPOLESTR
          STD_METHOD SetHelpContext, :ptr ICreateTypeInfo2, :DWORD
          STD_METHOD SetVersion, :ptr ICreateTypeInfo2, :WORD, :WORD
          STD_METHOD AddRefTypeInfo, :ptr ICreateTypeInfo2, :ptr ITypeInfo, :ptr HREFTYPE
          STD_METHOD AddFuncDesc, :ptr ICreateTypeInfo2, :UINT, :ptr FUNCDESC
          STD_METHOD AddImplType, :ptr ICreateTypeInfo2, :UINT, :HREFTYPE
          STD_METHOD SetImplTypeFlags, :ptr ICreateTypeInfo2, :UINT, :INT_
          STD_METHOD SetAlignment, :ptr ICreateTypeInfo2, :WORD
          STD_METHOD SetSchema, :ptr ICreateTypeInfo2, :LPOLESTR
          STD_METHOD AddVarDesc, :ptr ICreateTypeInfo2, :UINT, :ptr VARDESC
          STD_METHOD SetFuncAndParamNames, :ptr ICreateTypeInfo2, :UINT, :ptr LPOLESTR, :UINT
          STD_METHOD SetVarName, :ptr ICreateTypeInfo2, :UINT, :LPOLESTR
          STD_METHOD SetTypeDescAlias, :ptr ICreateTypeInfo2, :ptr TYPEDESC
          STD_METHOD DefineFuncAsDllEntry, :ptr ICreateTypeInfo2, :UINT, :LPOLESTR, :LPOLESTR
          STD_METHOD SetFuncDocString, :ptr ICreateTypeInfo2, :UINT, :LPOLESTR
          STD_METHOD SetVarDocString, :ptr ICreateTypeInfo2, :UINT, :LPOLESTR
          STD_METHOD SetFuncHelpContext, :ptr ICreateTypeInfo2, :UINT, :DWORD
          STD_METHOD SetVarHelpContext, :ptr ICreateTypeInfo2, :UINT, :DWORD
          STD_METHOD SetMops, :ptr ICreateTypeInfo2, :UINT, :BSTR
          STD_METHOD SetTypeIdldesc, :ptr ICreateTypeInfo2, :ptr IDLDESC
          STD_METHOD LayOut, :ptr ICreateTypeInfo2
          STD_METHOD DeleteFuncDesc, :ptr ICreateTypeInfo2, :UINT
          STD_METHOD DeleteFuncDescByMemId, :ptr ICreateTypeInfo2, :MEMBERID, :INVOKEKIND
          STD_METHOD DeleteVarDesc, :ptr ICreateTypeInfo2, :UINT
          STD_METHOD DeleteVarDescByMemId, :ptr ICreateTypeInfo2, :MEMBERID
          STD_METHOD DeleteImplType, :ptr ICreateTypeInfo2, :UINT
          STD_METHOD SetCustData, :ptr ICreateTypeInfo2, :REFGUID, :ptr VARIANT
          STD_METHOD SetFuncCustData, :ptr ICreateTypeInfo2, :UINT, :REFGUID, :ptr VARIANT
          STD_METHOD SetParamCustData, :ptr ICreateTypeInfo2, :UINT, :UINT, :REFGUID, :ptr VARIANT
          STD_METHOD SetVarCustData, :ptr ICreateTypeInfo2, :UINT, :REFGUID, :ptr VARIANT
          STD_METHOD SetImplTypeCustData, :ptr ICreateTypeInfo2, :UINT, :REFGUID, :ptr VARIANT
          STD_METHOD SetHelpStringContext, :ptr ICreateTypeInfo2, :ULONG
          STD_METHOD SetFuncHelpStringContext, :ptr ICreateTypeInfo2, :UINT, :ULONG
          STD_METHOD SetVarHelpStringContext, :ptr ICreateTypeInfo2, :UINT, :ULONG
          STD_METHOD Invalidate, :ptr ICreateTypeInfo2
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
          STD_METHOD QueryInterface, :ptr ICreateTypeLib, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr ICreateTypeLib
          STD_METHOD Release, :ptr ICreateTypeLib
          STD_METHOD CreateTypeInfo, :ptr ICreateTypeLib, :LPOLESTR, :TYPEKIND, :ptr ptr ICreateTypeInfo
          STD_METHOD SetName, :ptr ICreateTypeLib, :LPOLESTR
          STD_METHOD SetVersion, :ptr ICreateTypeLib, :WORD, :WORD
          STD_METHOD SetGuid, :ptr ICreateTypeLib, :REFGUID
          STD_METHOD SetDocString, :ptr ICreateTypeLib, :LPOLESTR
          STD_METHOD SetHelpFileName, :ptr ICreateTypeLib, :LPOLESTR
          STD_METHOD SetHelpContext, :ptr ICreateTypeLib, :DWORD
          STD_METHOD SetLcid, :ptr ICreateTypeLib, :LCID
          STD_METHOD SetLibFlags, :ptr ICreateTypeLib, :UINT
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
          STD_METHOD QueryInterface, :ptr ICreateTypeLib2, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr ICreateTypeLib2
          STD_METHOD Release, :ptr ICreateTypeLib2
          STD_METHOD CreateTypeInfo, :ptr ICreateTypeLib2, :LPOLESTR, :TYPEKIND, :ptr ptr ICreateTypeInfo
          STD_METHOD SetName, :ptr ICreateTypeLib2, :LPOLESTR
          STD_METHOD SetVersion, :ptr ICreateTypeLib2, :WORD, :WORD
          STD_METHOD SetGuid, :ptr ICreateTypeLib2, :REFGUID
          STD_METHOD SetDocString, :ptr ICreateTypeLib2, :LPOLESTR
          STD_METHOD SetHelpFileName, :ptr ICreateTypeLib2, :LPOLESTR
          STD_METHOD SetHelpContext, :ptr ICreateTypeLib2, :DWORD
          STD_METHOD SetLcid, :ptr ICreateTypeLib2, :LCID
          STD_METHOD SetLibFlags, :ptr ICreateTypeLib2, :UINT
          STD_METHOD SaveAllChanges, :ptr ICreateTypeLib2
          STD_METHOD DeleteTypeInfo, :ptr ICreateTypeLib2, :LPOLESTR
          STD_METHOD SetCustData, :ptr ICreateTypeLib2, :REFGUID, :ptr VARIANT
          STD_METHOD SetHelpStringContext, :ptr ICreateTypeLib2, :ULONG
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
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_oaidl_0000_0005_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_oaidl_0000_0005_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IDispatch_INTERFACE_DEFINED__
      __IDispatch_INTERFACE_DEFINED__ equ <>
      LPDISPATCH typedef ptr IDispatch
      DISPID_UNKNOWN equ -1
      DISPID_VALUE equ 0
      DISPID_PROPERTYPUT equ -3
      DISPID_NEWENUM equ -4
      DISPID_EVALUATE equ -5
      DISPID_CONSTRUCTOR equ -6
      DISPID_DESTRUCTOR equ -7
      DISPID_COLLECT equ -8
      externdef IID_IDispatch:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IDispatchVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IDispatchVtbl>
          STD_METHOD QueryInterface, :ptr IDispatch, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IDispatch
          STD_METHOD Release, :ptr IDispatch
          STD_METHOD GetTypeInfoCount, :ptr IDispatch, :ptr UINT
          STD_METHOD GetTypeInfo, :ptr IDispatch, :UINT, :LCID, :ptr ptr ITypeInfo
          STD_METHOD GetIDsOfNames, :ptr IDispatch, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
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
          STD_METHOD QueryInterface, :ptr IEnumVARIANT, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IEnumVARIANT
          STD_METHOD Release, :ptr IEnumVARIANT
          STD_METHOD Next, :ptr IEnumVARIANT, :ULONG, :ptr VARIANT, :ptr ULONG
          STD_METHOD Skip, :ptr IEnumVARIANT, :ULONG
          STD_METHOD Reset, :ptr IEnumVARIANT
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
      DESCKIND_FUNCDESC equ
      DESCKIND_VARDESC equ
      DESCKIND_TYPECOMP equ
      DESCKIND_IMPLICITAPPOBJ equ
      DESCKIND_MAX equ
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
          STD_METHOD QueryInterface, :ptr ITypeComp, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr ITypeComp
          STD_METHOD Release, :ptr ITypeComp
          STD_METHOD Bind, :ptr ITypeComp, :LPOLESTR, :ULONG, :WORD, :ptr ptr ITypeInfo, :ptr DESCKIND, :ptr BINDPTR
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
          STD_METHOD QueryInterface, :ptr ITypeInfo, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr ITypeInfo
          STD_METHOD Release, :ptr ITypeInfo
          STD_METHOD GetTypeAttr, :ptr ITypeInfo, :ptr ptr TYPEATTR
          STD_METHOD GetTypeComp, :ptr ITypeInfo, :ptr ptr ITypeComp
          STD_METHOD GetFuncDesc, :ptr ITypeInfo, :UINT, :ptr ptr FUNCDESC
          STD_METHOD GetVarDesc, :ptr ITypeInfo, :UINT, :ptr ptr VARDESC
          STD_METHOD GetNames, :ptr ITypeInfo, :MEMBERID, :ptr BSTR, :UINT, :ptr UINT
          STD_METHOD GetRefTypeOfImplType, :ptr ITypeInfo, :UINT, :ptr HREFTYPE
          STD_METHOD GetImplTypeFlags, :ptr ITypeInfo, :UINT, :ptr INT_
          STD_METHOD GetIDsOfNames, :ptr ITypeInfo, :ptr LPOLESTR, :UINT, :ptr MEMBERID
          STD_METHOD Invoke, :ptr ITypeInfo, :PVOID, :MEMBERID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
          STD_METHOD GetDocumentation, :ptr ITypeInfo, :MEMBERID, :ptr BSTR, :ptr BSTR, :ptr DWORD, :ptr BSTR
          STD_METHOD GetDllEntry, :ptr ITypeInfo, :MEMBERID, :INVOKEKIND, :ptr BSTR, :ptr BSTR, :ptr WORD
          STD_METHOD GetRefTypeInfo, :ptr ITypeInfo, :HREFTYPE, :ptr ptr ITypeInfo
          STD_METHOD AddressOfMember, :ptr ITypeInfo, :MEMBERID, :INVOKEKIND, :ptr PVOID
          STD_METHOD CreateInstance, :ptr ITypeInfo, :ptr IUnknown, :REFIID, :ptr PVOID
          STD_METHOD GetMops, :ptr ITypeInfo, :MEMBERID, :ptr BSTR
          STD_METHOD GetContainingTypeLib, :ptr ITypeInfo, :ptr ptr ITypeLib, :ptr UINT
          STD_METHOD ReleaseTypeAttr, :ptr ITypeInfo, :ptr TYPEATTR
          STD_METHOD ReleaseFuncDesc, :ptr ITypeInfo, :ptr FUNCDESC
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
          STD_METHOD QueryInterface, :ptr ITypeInfo2, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr ITypeInfo2
          STD_METHOD Release, :ptr ITypeInfo2
          STD_METHOD GetTypeAttr, :ptr ITypeInfo2, :ptr ptr TYPEATTR
          STD_METHOD GetTypeComp, :ptr ITypeInfo2, :ptr ptr ITypeComp
          STD_METHOD GetFuncDesc, :ptr ITypeInfo2, :UINT, :ptr ptr FUNCDESC
          STD_METHOD GetVarDesc, :ptr ITypeInfo2, :UINT, :ptr ptr VARDESC
          STD_METHOD GetNames, :ptr ITypeInfo2, :MEMBERID, :ptr BSTR, :UINT, :ptr UINT
          STD_METHOD GetRefTypeOfImplType, :ptr ITypeInfo2, :UINT, :ptr HREFTYPE
          STD_METHOD GetImplTypeFlags, :ptr ITypeInfo2, :UINT, :ptr INT_
          STD_METHOD GetIDsOfNames, :ptr ITypeInfo2, :ptr LPOLESTR, :UINT, :ptr MEMBERID
          STD_METHOD Invoke_, :ptr ITypeInfo2, :PVOID, :MEMBERID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
          STD_METHOD GetDocumentation, :ptr ITypeInfo2, :MEMBERID, :ptr BSTR, :ptr BSTR, :ptr DWORD, :ptr BSTR
          STD_METHOD GetDllEntry, :ptr ITypeInfo2, :MEMBERID, :INVOKEKIND, :ptr BSTR, :ptr BSTR, :ptr WORD
          STD_METHOD GetRefTypeInfo, :ptr ITypeInfo2, :HREFTYPE, :ptr ptr ITypeInfo
          STD_METHOD AddressOfMember, :ptr ITypeInfo2, :MEMBERID, :INVOKEKIND, :ptr PVOID
          STD_METHOD CreateInstance, :ptr ITypeInfo2, :ptr IUnknown, :REFIID, :ptr PVOID
          STD_METHOD GetMops, :ptr ITypeInfo2, :MEMBERID, :ptr BSTR
          STD_METHOD GetContainingTypeLib, :ptr ITypeInfo2, :ptr ptr ITypeLib, :ptr UINT
          STD_METHOD ReleaseTypeAttr, :ptr ITypeInfo2, :ptr TYPEATTR
          STD_METHOD ReleaseFuncDesc, :ptr ITypeInfo2, :ptr FUNCDESC
          STD_METHOD ReleaseVarDesc, :ptr ITypeInfo2, :ptr VARDESC
          STD_METHOD GetTypeKind, :ptr ITypeInfo2, :ptr TYPEKIND
          STD_METHOD GetTypeFlags, :ptr ITypeInfo2, :ptr ULONG
          STD_METHOD GetFuncIndexOfMemId, :ptr ITypeInfo2, :MEMBERID, :INVOKEKIND, :ptr UINT
          STD_METHOD GetVarIndexOfMemId, :ptr ITypeInfo2, :MEMBERID, :ptr UINT
          STD_METHOD GetCustData, :ptr ITypeInfo2, :REFGUID, :ptr VARIANT
          STD_METHOD GetFuncCustData, :ptr ITypeInfo2, :UINT, :REFGUID, :ptr VARIANT
          STD_METHOD GetParamCustData, :ptr ITypeInfo2, :UINT, :UINT, :REFGUID, :ptr VARIANT
          STD_METHOD GetVarCustData, :ptr ITypeInfo2, :UINT, :REFGUID, :ptr VARIANT
          STD_METHOD GetImplTypeCustData, :ptr ITypeInfo2, :UINT, :REFGUID, :ptr VARIANT
          STD_METHOD GetDocumentation2, :ptr ITypeInfo2, :MEMBERID, :LCID, :ptr BSTR, :ptr DWORD, :ptr BSTR
          STD_METHOD GetAllCustData, :ptr ITypeInfo2, :ptr CUSTDATA
          STD_METHOD GetAllFuncCustData, :ptr ITypeInfo2, :UINT, :ptr CUSTDATA
          STD_METHOD GetAllParamCustData, :ptr ITypeInfo2, :UINT, :UINT, :ptr CUSTDATA
          STD_METHOD GetAllVarCustData, :ptr ITypeInfo2, :UINT, :ptr CUSTDATA
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
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_oaidl_0000_0010_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_oaidl_0000_0010_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ITypeLib_INTERFACE_DEFINED__
      __ITypeLib_INTERFACE_DEFINED__ equ <>
      SYSKIND typedef SDWORD
      SYS_WIN16 equ 0
      SYS_WIN32 equ
      SYS_MAC equ
      SYS_WIN64 equ
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
          STD_METHOD QueryInterface, :ptr ITypeLib, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr ITypeLib
          STD_METHOD Release, :ptr ITypeLib
          STD_METHOD GetTypeInfoCount, :ptr ITypeLib
          STD_METHOD GetTypeInfo, :ptr ITypeLib, :UINT, :ptr ptr ITypeInfo
          STD_METHOD GetTypeInfoType, :ptr ITypeLib, :UINT, :ptr TYPEKIND
          STD_METHOD GetTypeInfoOfGuid, :ptr ITypeLib, :REFGUID, :ptr ptr ITypeInfo
          STD_METHOD GetLibAttr, :ptr ITypeLib, :ptr ptr TLIBATTR
          STD_METHOD GetTypeComp, :ptr ITypeLib, :ptr ptr ITypeComp
          STD_METHOD GetDocumentation, :ptr ITypeLib, :INT_, :ptr BSTR, :ptr BSTR, :ptr DWORD, :ptr BSTR
          STD_METHOD IsName, :ptr ITypeLib, :LPOLESTR, :ULONG, :ptr BOOL
          STD_METHOD FindName, :ptr ITypeLib, :LPOLESTR, :ULONG, :ptr ptr ITypeInfo, :ptr MEMBERID, :ptr USHORT
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
          STD_METHOD QueryInterface, :ptr ITypeLib2, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr ITypeLib2
          STD_METHOD Release, :ptr ITypeLib2
          STD_METHOD GetTypeInfoCount, :ptr ITypeLib2
          STD_METHOD GetTypeInfo, :ptr ITypeLib2, :UINT, :ptr ptr ITypeInfo
          STD_METHOD GetTypeInfoType, :ptr ITypeLib2, :UINT, :ptr TYPEKIND
          STD_METHOD GetTypeInfoOfGuid, :ptr ITypeLib2, :REFGUID, :ptr ptr ITypeInfo
          STD_METHOD GetLibAttr, :ptr ITypeLib2, :ptr ptr TLIBATTR
          STD_METHOD GetTypeComp, :ptr ITypeLib2, :ptr ptr ITypeComp
          STD_METHOD GetDocumentation, :ptr ITypeLib2, :INT_, :ptr BSTR, :ptr BSTR, :ptr DWORD, :ptr BSTR
          STD_METHOD IsName, :ptr ITypeLib2, :LPOLESTR, :ULONG, :ptr BOOL
          STD_METHOD FindName, :ptr ITypeLib2, :LPOLESTR, :ULONG, :ptr ptr ITypeInfo, :ptr MEMBERID, :ptr USHORT
          STD_METHOD ReleaseTLibAttr, :ptr ITypeLib2, :ptr TLIBATTR
          STD_METHOD GetCustData, :ptr ITypeLib2, :REFGUID, :ptr VARIANT
          STD_METHOD GetLibStatistics, :ptr ITypeLib2, :ptr ULONG, :ptr ULONG
          STD_METHOD GetDocumentation2, :ptr ITypeLib2, :INT_, :LCID, :ptr BSTR, :ptr DWORD, :ptr BSTR
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
      CHANGEKIND_DELETEMEMBER equ
      CHANGEKIND_SETNAMES equ
      CHANGEKIND_SETDOCUMENTATION equ
      CHANGEKIND_GENERAL equ
      CHANGEKIND_INVALIDATE equ
      CHANGEKIND_CHANGEFAILED equ
      CHANGEKIND_MAX equ
      tagCHANGEKIND typedef CHANGEKIND
      
      externdef IID_ITypeChangeEvents:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ITypeChangeEventsVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ITypeChangeEventsVtbl>
          STD_METHOD QueryInterface, :ptr ITypeChangeEvents, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr ITypeChangeEvents
          STD_METHOD Release, :ptr ITypeChangeEvents
          STD_METHOD RequestTypeChange, :ptr ITypeChangeEvents, :CHANGEKIND, :ptr ITypeInfo, :LPOLESTR, :ptr INT_
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
          STD_METHOD QueryInterface, :ptr IErrorInfo, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IErrorInfo
          STD_METHOD Release, :ptr IErrorInfo
          STD_METHOD GetGUID, :ptr IErrorInfo, :ptr GUID
          STD_METHOD GetSource, :ptr IErrorInfo, :ptr BSTR
          STD_METHOD GetDescription, :ptr IErrorInfo, :ptr BSTR
          STD_METHOD GetHelpFile, :ptr IErrorInfo, :ptr BSTR
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
          STD_METHOD QueryInterface, :ptr ICreateErrorInfo, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr ICreateErrorInfo
          STD_METHOD Release, :ptr ICreateErrorInfo
          STD_METHOD SetGUID, :ptr ICreateErrorInfo, :REFGUID
          STD_METHOD SetSource, :ptr ICreateErrorInfo, :LPOLESTR
          STD_METHOD SetDescription, :ptr ICreateErrorInfo, :LPOLESTR
          STD_METHOD SetHelpFile, :ptr ICreateErrorInfo, :LPOLESTR
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
          STD_METHOD QueryInterface, :ptr ISupportErrorInfo, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr ISupportErrorInfo
          STD_METHOD Release, :ptr ISupportErrorInfo
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
          STD_METHOD QueryInterface, :ptr ITypeFactory, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr ITypeFactory
          STD_METHOD Release, :ptr ITypeFactory
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
          STD_METHOD QueryInterface, :ptr ITypeMarshal, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr ITypeMarshal
          STD_METHOD Release, :ptr ITypeMarshal
          STD_METHOD Size_, :ptr ITypeMarshal, :PVOID, :DWORD, :PVOID, :ptr ULONG
          STD_METHOD Marshal, :ptr ITypeMarshal, :PVOID, :DWORD, :PVOID, :ULONG, :ptr BYTE, :ptr ULONG
          STD_METHOD Unmarshal, :ptr ITypeMarshal, :PVOID, :DWORD, :ULONG, :ptr BYTE, :ptr ULONG
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
          STD_METHOD QueryInterface, :ptr IRecordInfo, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IRecordInfo
          STD_METHOD Release, :ptr IRecordInfo
          STD_METHOD RecordInit, :ptr IRecordInfo, :PVOID
          STD_METHOD RecordClear, :ptr IRecordInfo, :PVOID
          STD_METHOD RecordCopy, :ptr IRecordInfo, :PVOID, :PVOID
          STD_METHOD GetGuid, :ptr IRecordInfo, :ptr GUID
          STD_METHOD GetName, :ptr IRecordInfo, :ptr BSTR
          STD_METHOD GetSize, :ptr IRecordInfo, :ptr ULONG
          STD_METHOD GetTypeInfo, :ptr IRecordInfo, :ptr ptr ITypeInfo
          STD_METHOD GetField, :ptr IRecordInfo, :PVOID, :LPCOLESTR, :ptr VARIANT
          STD_METHOD GetFieldNoCopy, :ptr IRecordInfo, :PVOID, :LPCOLESTR, :ptr VARIANT, :ptr PVOID
          STD_METHOD PutField, :ptr IRecordInfo, :ULONG, :PVOID, :LPCOLESTR, :ptr VARIANT
          STD_METHOD PutFieldNoCopy, :ptr IRecordInfo, :ULONG, :PVOID, :LPCOLESTR, :ptr VARIANT
          STD_METHOD GetFieldNames, :ptr IRecordInfo, :ptr ULONG, :ptr BSTR
          STD_METHOD IsMatchingType, :ptr IRecordInfo, :ptr IRecordInfo
          STD_METHOD RecordCreate, :ptr IRecordInfo
          STD_METHOD RecordCreateCopy, :ptr IRecordInfo, :PVOID, :ptr PVOID
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
          STD_METHOD QueryInterface, :ptr IErrorLog, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IErrorLog
          STD_METHOD Release, :ptr IErrorLog
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
          STD_METHOD QueryInterface, :ptr IPropertyBag, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr IPropertyBag
          STD_METHOD Release, :ptr IPropertyBag
          STD_METHOD Read, :ptr IPropertyBag, :LPCOLESTR, :ptr VARIANT, :ptr IErrorLog
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
          STD_METHOD QueryInterface, :ptr ITypeLibRegistrationReader, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr ITypeLibRegistrationReader
          STD_METHOD Release, :ptr ITypeLibRegistrationReader
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
          STD_METHOD QueryInterface, :ptr ITypeLibRegistration, :REFIID, :ptr ptr
          STD_METHOD AddRef, :ptr ITypeLibRegistration
          STD_METHOD Release, :ptr ITypeLibRegistration
          STD_METHOD GetGuid, :ptr ITypeLibRegistration, :ptr GUID
          STD_METHOD GetVersion, :ptr ITypeLibRegistration, :ptr BSTR
          STD_METHOD GetLcid, :ptr ITypeLibRegistration, :ptr LCID
          STD_METHOD GetWin32Path, :ptr ITypeLibRegistration, :ptr BSTR
          STD_METHOD GetWin64Path, :ptr ITypeLibRegistration, :ptr BSTR
          STD_METHOD GetDisplayName, :ptr ITypeLibRegistration, :ptr BSTR
          STD_METHOD GetFlags, :ptr ITypeLibRegistration, :ptr DWORD
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
