;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\oaidl.h
;             Created on (UTC) 06/04/2024 06:15:57
;             Last modified on (UTC) 21/02/2024 18:18:08

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
  ;* Forward Declarations *
  ifndef __ICreateTypeInfo_FWD_DEFINED__
    __ICreateTypeInfo_FWD_DEFINED__ equ <>
    ;* __ICreateTypeInfo_FWD_DEFINED__ *
  endif
  ifndef __ICreateTypeInfo2_FWD_DEFINED__
    __ICreateTypeInfo2_FWD_DEFINED__ equ <>
    ;* __ICreateTypeInfo2_FWD_DEFINED__ *
  endif
  ifndef __ICreateTypeLib_FWD_DEFINED__
    __ICreateTypeLib_FWD_DEFINED__ equ <>
    ;* __ICreateTypeLib_FWD_DEFINED__ *
  endif
  ifndef __ICreateTypeLib2_FWD_DEFINED__
    __ICreateTypeLib2_FWD_DEFINED__ equ <>
    ;* __ICreateTypeLib2_FWD_DEFINED__ *
  endif
  ifndef __IDispatch_FWD_DEFINED__
    __IDispatch_FWD_DEFINED__ equ <>
    ;* __IDispatch_FWD_DEFINED__ *
  endif
  ifndef __IEnumVARIANT_FWD_DEFINED__
    __IEnumVARIANT_FWD_DEFINED__ equ <>
    ;* __IEnumVARIANT_FWD_DEFINED__ *
  endif
  ifndef __ITypeComp_FWD_DEFINED__
    __ITypeComp_FWD_DEFINED__ equ <>
    ;* __ITypeComp_FWD_DEFINED__ *
  endif
  ifndef __ITypeInfo_FWD_DEFINED__
    __ITypeInfo_FWD_DEFINED__ equ <>
    ;* __ITypeInfo_FWD_DEFINED__ *
  endif
  ifndef __ITypeInfo2_FWD_DEFINED__
    __ITypeInfo2_FWD_DEFINED__ equ <>
    ;* __ITypeInfo2_FWD_DEFINED__ *
  endif
  ifndef __ITypeLib_FWD_DEFINED__
    __ITypeLib_FWD_DEFINED__ equ <>
    ;* __ITypeLib_FWD_DEFINED__ *
  endif
  ifndef __ITypeLib2_FWD_DEFINED__
    __ITypeLib2_FWD_DEFINED__ equ <>
    ;* __ITypeLib2_FWD_DEFINED__ *
  endif
  ifndef __ITypeChangeEvents_FWD_DEFINED__
    __ITypeChangeEvents_FWD_DEFINED__ equ <>
    ;* __ITypeChangeEvents_FWD_DEFINED__ *
  endif
  ifndef __IErrorInfo_FWD_DEFINED__
    __IErrorInfo_FWD_DEFINED__ equ <>
    ;* __IErrorInfo_FWD_DEFINED__ *
  endif
  ifndef __ICreateErrorInfo_FWD_DEFINED__
    __ICreateErrorInfo_FWD_DEFINED__ equ <>
    ;* __ICreateErrorInfo_FWD_DEFINED__ *
  endif
  ifndef __ISupportErrorInfo_FWD_DEFINED__
    __ISupportErrorInfo_FWD_DEFINED__ equ <>
    ;* __ISupportErrorInfo_FWD_DEFINED__ *
  endif
  ifndef __ITypeFactory_FWD_DEFINED__
    __ITypeFactory_FWD_DEFINED__ equ <>
    ;* __ITypeFactory_FWD_DEFINED__ *
  endif
  ifndef __ITypeMarshal_FWD_DEFINED__
    __ITypeMarshal_FWD_DEFINED__ equ <>
    ;* __ITypeMarshal_FWD_DEFINED__ *
  endif
  ifndef __IRecordInfo_FWD_DEFINED__
    __IRecordInfo_FWD_DEFINED__ equ <>
    ;* __IRecordInfo_FWD_DEFINED__ *
  endif
  ifndef __IErrorLog_FWD_DEFINED__
    __IErrorLog_FWD_DEFINED__ equ <>
    ;* __IErrorLog_FWD_DEFINED__ *
  endif
  ifndef __IPropertyBag_FWD_DEFINED__
    __IPropertyBag_FWD_DEFINED__ equ <>
    ;* __IPropertyBag_FWD_DEFINED__ *
  endif
  ifndef __ITypeLibRegistrationReader_FWD_DEFINED__
    __ITypeLibRegistrationReader_FWD_DEFINED__ equ <>
    ;* __ITypeLibRegistrationReader_FWD_DEFINED__ *
  endif
  ifndef __ITypeLibRegistration_FWD_DEFINED__
    __ITypeLibRegistration_FWD_DEFINED__ equ <>
    ;* __ITypeLibRegistration_FWD_DEFINED__ *
  endif
  ;* header files for imported files *
  include objidl.inc
  ifdef __cplusplus
    ;[...]
  endif
  ;* interface __MIDL_itf_oaidl_0000_0000 *
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
  endif
  if (_MSC_VER ge 1020)
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    externdef __MIDL_itf_oaidl_0000_0000_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_oaidl_0000_0000_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IOleAutomationTypes_INTERFACE_DEFINED__
      __IOleAutomationTypes_INTERFACE_DEFINED__ equ <>
      ;* interface IOleAutomationTypes *
      ;* [unique][version] *
      CURRENCY typedef CY
      SAFEARRAYBOUND struct
        cElements DWORD ?
        lLbound SDWORD ?
      SAFEARRAYBOUND ends
      tagSAFEARRAYBOUND typedef SAFEARRAYBOUND
      LPSAFEARRAYBOUND typedef ptr tagSAFEARRAYBOUND
      ;* the following is what MIDL knows how to remote *
      ;* [unique] *
      wireVARIANT typedef ptr _wireVARIANT
      ;* [unique] *
      wireBRECORD typedef ptr _wireBRECORD
      SAFEARR_BSTR struct
        Size_ DWORD ?
        aBstr POINTER ?
        ;* [ref][size_is] *
      SAFEARR_BSTR ends
      _wireSAFEARR_BSTR typedef SAFEARR_BSTR
      SAFEARR_UNKNOWN struct
        Size_ DWORD ?
        apUnknown POINTER ?
        ;* [ref][size_is] *
      SAFEARR_UNKNOWN ends
      _wireSAFEARR_UNKNOWN typedef SAFEARR_UNKNOWN
      SAFEARR_DISPATCH struct
        Size_ DWORD ?
        apDispatch POINTER ?
        ;* [ref][size_is] *
      SAFEARR_DISPATCH ends
      _wireSAFEARR_DISPATCH typedef SAFEARR_DISPATCH
      SAFEARR_VARIANT struct
        Size_ DWORD ?
        aVariant POINTER ?
        ;* [ref][size_is] *
      SAFEARR_VARIANT ends
      _wireSAFEARR_VARIANT typedef SAFEARR_VARIANT
      SAFEARR_BRECORD struct
        Size_ DWORD ?
        aRecord POINTER ?
        ;* [ref][size_is] *
      SAFEARR_BRECORD ends
      _wireSAFEARR_BRECORD typedef SAFEARR_BRECORD
      SAFEARR_HAVEIID struct
        Size_ DWORD ?
        apUnknown POINTER ?
        ;* [ref][size_is] *
        iid IID <>
      SAFEARR_HAVEIID ends
      _wireSAFEARR_HAVEIID typedef SAFEARR_HAVEIID
      ;* [v1_enum] *
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
      SF_HAVEIID equ
      tagSF_TYPE typedef SF_TYPE

      SAFEARRAYUNION struct
        sfType DWORD ?
        ;* [switch_is] ** [switch_type] *
        union u
          BstrStr SAFEARR_BSTR <>
          ;* [case()] *
          UnknownStr SAFEARR_UNKNOWN <>
          ;* [case()] *
          DispatchStr SAFEARR_DISPATCH <>
          ;* [case()] *
          VariantStr SAFEARR_VARIANT <>
          ;* [case()] *
          RecordStr SAFEARR_BRECORD <>
          ;* [case()] *
          HaveIidStr SAFEARR_HAVEIID <>
          ;* [case()] *
          ByteStr BYTE_SIZEDARR <>
          ;* [case()] *
          WordStr WORD_SIZEDARR <>
          ;* [case()] *
          LongStr DWORD_SIZEDARR <>
          ;* [case()] *
          HyperStr HYPER_SIZEDARR <>
          ;* [case()] *
        ends
      SAFEARRAYUNION ends
      _wireSAFEARRAY_UNION typedef SAFEARRAYUNION
      ;* [unique] *
      _wireSAFEARRAY struct
        cDims WORD ?
        fFeatures WORD ?
        cbElements DWORD ?
        cLocks DWORD ?
        uArrayStructs SAFEARRAYUNION <>
        rgsabound SAFEARRAYBOUND 1 dup (<>)
        ;* [size_is] *
      _wireSAFEARRAY ends
      ;* [unique] *
      wirePSAFEARRAY typedef ptr wireSAFEARRAY
      SAFEARRAY struct
        cDims WORD ?
        fFeatures WORD ?
        cbElements DWORD ?
        cLocks DWORD ?
        pvData POINTER ?
        rgsabound SAFEARRAYBOUND 1 dup (<>)
      SAFEARRAY ends
      tagSAFEARRAY typedef SAFEARRAY
      ;* [wire_marshal] *
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
      ;* VARIANT STRUCTURE
      ;*
      ;*  VARTYPE vt;
      ;*  WORD wReserved1;
      ;*  WORD wReserved2;
      ;*  WORD wReserved3;
      ;*  union {
      ;*    LONGLONG       VT_I8
      ;*    LONG           VT_I4
      ;*    BYTE           VT_UI1
      ;*    SHORT          VT_I2
      ;*    FLOAT          VT_R4
      ;*    DOUBLE         VT_R8
      ;*    VARIANT_BOOL   VT_BOOL
      ;*    SCODE          VT_ERROR
      ;*    CY             VT_CY
      ;*    DATE           VT_DATE
      ;*    BSTR           VT_BSTR
      ;*    IUnknown *     VT_UNKNOWN
      ;*    IDispatch *    VT_DISPATCH
      ;*    SAFEARRAY *    VT_ARRAY
      ;*    BYTE *         VT_BYREF|VT_UI1
      ;*    SHORT *        VT_BYREF|VT_I2
      ;*    LONG *         VT_BYREF|VT_I4
      ;*    LONGLONG *     VT_BYREF|VT_I8
      ;*    FLOAT *        VT_BYREF|VT_R4
      ;*    DOUBLE *       VT_BYREF|VT_R8
      ;*    VARIANT_BOOL * VT_BYREF|VT_BOOL
      ;*    SCODE *        VT_BYREF|VT_ERROR
      ;*    CY *           VT_BYREF|VT_CY
      ;*    DATE *         VT_BYREF|VT_DATE
      ;*    BSTR *         VT_BYREF|VT_BSTR
      ;*    IUnknown **    VT_BYREF|VT_UNKNOWN
      ;*    IDispatch **   VT_BYREF|VT_DISPATCH
      ;*    SAFEARRAY **   VT_BYREF|VT_ARRAY
      ;*    VARIANT *      VT_BYREF|VT_VARIANT
      ;*    PVOID          VT_BYREF (Generic ByRef)
      ;*    CHAR           VT_I1
      ;*    USHORT         VT_UI2
      ;*    ULONG          VT_UI4
      ;*    ULONGLONG      VT_UI8
      ;*    INT            VT_INT
      ;*    UINT           VT_UINT
      ;*    DECIMAL *      VT_BYREF|VT_DECIMAL
      ;*    CHAR *         VT_BYREF|VT_I1
      ;*    USHORT *       VT_BYREF|VT_UI2
      ;*    ULONG *        VT_BYREF|VT_UI4
      ;*    ULONGLONG *    VT_BYREF|VT_UI8
      ;*    INT *          VT_BYREF|VT_INT
      ;*    UINT *         VT_BYREF|VT_UINT
      ;*  }
      ;*
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
      ;* [wire_marshal] *
      VARIANT typedef tagVARIANT
      tagVARIANT struct
        union __VARIANT_NAME_1
          struct __VARIANT_NAME_2
            vt VARTYPE ?
            wReserved1 WORD ?
            wReserved2 WORD ?
            wReserved3 WORD ?
            union __VARIANT_NAME_3
              llVal SQWORD ?
              lVal SDWORD ?
              bVal BYTE ?
              iVal SWORD ?
              fltVal REAL4 ?
              dblVal REAL8 ?
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
              byref POINTER ?
              cVal SBYTE ?
              uiVal WORD ?
              ulVal DWORD ?
              ullVal QWORD ?
              intVal SDWORD ?
              uintVal DWORD ?
              pdecVal POINTER ?
              pcVal POINTER ?
              puiVal POINTER ?
              pulVal POINTER ?
              pullVal POINTER ?
              pintVal POINTER ?
              puintVal POINTER ?
              struct __VARIANT_NAME_4
                pvRecord POINTER ?
                pRecInfo POINTER ?
              ends
            ends
          ends
          decVal DECIMAL <>
        ends
      tagVARIANT ends
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
      ; MIDL_PASS
      ;* the following is what MIDL knows how to remote *
      _wireBRECORD struct
        fFlags DWORD ?
        clSize DWORD ?
        pRecInfo POINTER ?
        pRecord POINTER ?
        ;* [size_is] *
      _wireBRECORD ends
      _wireVARIANT struct
        clSize DWORD ?
        rpcReserved DWORD ?
        vt WORD ?
        wReserved1 WORD ?
        wReserved2 WORD ?
        wReserved3 WORD ?
        ;* [switch_is][switch_type] *
        union
          llVal SQWORD ?
          ;* [case()] *
          lVal SDWORD ?
          ;* [case()] *
          bVal BYTE ?
          ;* [case()] *
          iVal SWORD ?
          ;* [case()] *
          fltVal REAL4 ?
          ;* [case()] *
          dblVal REAL8 ?
          ;* [case()] *
          boolVal VARIANT_BOOL ?
          ;* [case()] *
          scode SCODE ?
          ;* [case()] *
          cyVal CY <>
          ;* [case()] *
          date DATE ?
          ;* [case()] *
          bstrVal wireBSTR ?
          ;* [case()] *
          punkVal POINTER ?
          ;* [case()] *
          pdispVal POINTER ?
          ;* [case()] *
          parray wirePSAFEARRAY ?
          ;* [case()] *
          brecVal wireBRECORD ?
          ;* [case()] *
          pbVal POINTER ?
          ;* [case()] *
          piVal POINTER ?
          ;* [case()] *
          plVal POINTER ?
          ;* [case()] *
          pllVal POINTER ?
          ;* [case()] *
          pfltVal POINTER ?
          ;* [case()] *
          pdblVal POINTER ?
          ;* [case()] *
          pboolVal POINTER ?
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
          cVal SBYTE ?
          ;* [case()] *
          uiVal WORD ?
          ;* [case()] *
          ulVal DWORD ?
          ;* [case()] *
          ullVal QWORD ?
          ;* [case()] *
          intVal SDWORD ?
          ;* [case()] *
          uintVal DWORD ?
          ;* [case()] *
          decVal DECIMAL <>
          ;* [case()] *
          pdecVal POINTER ?
          ;* [case()] *
          pcVal POINTER ?
          ;* [case()] *
          puiVal POINTER ?
          ;* [case()] *
          pulVal POINTER ?
          ;* [case()] *
          pullVal POINTER ?
          ;* [case()] *
          pintVal POINTER ?
          ;* [case()] *
          puintVal POINTER ?
          ;* [case()] *
          ;* [case()] ** Empty union arm *
          ;* [case()] ** Empty union arm *
        ends
      _wireVARIANT ends
      DISPID typedef LONG
      MEMBERID typedef DISPID
      HREFTYPE typedef DWORD
      ;* [v1_enum] *
      TYPEKIND typedef SDWORD
      TKIND_ENUM equ 0
      TKIND_RECORD equ
      TKIND_MODULE equ
      TKIND_INTERFACE equ
      TKIND_DISPATCH equ
      TKIND_COCLASS equ
      TKIND_ALIAS equ
      TKIND_UNION equ
      TKIND_MAX equ
      tagTYPEKIND typedef TYPEKIND

      TYPEDESC struct 4
        ;* [switch_is][switch_type] *
        union
          lptdesc POINTER ?
          ;* [case()] *
          lpadesc POINTER ?
          ;* [case()] *
          hreftype HREFTYPE ?
          ;* [case()] *
          ;* [default] ** Empty union arm *
        ends
        vt VARTYPE ?
      TYPEDESC ends
      tagTYPEDESC typedef TYPEDESC
      ARRAYDESC struct 4
        tdescElem TYPEDESC <>
        cDims WORD ?
        rgbounds SAFEARRAYBOUND 1 dup (<>)
        ;* [size_is] *
      ARRAYDESC ends
      tagARRAYDESC typedef ARRAYDESC
      PARAMDESCEX struct 8
        cBytes DWORD ?
        varDefaultValue VARIANTARG <>
      PARAMDESCEX ends
      tagPARAMDESCEX typedef PARAMDESCEX
      LPPARAMDESCEX typedef ptr tagPARAMDESCEX
      PARAMDESC struct 4
        pparamdescex LPPARAMDESCEX ?
        wParamFlags WORD ?
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
        dwReserved XWORD ?
        wIDLFlags WORD ?
      IDLDESC ends
      tagIDLDESC typedef IDLDESC
      LPIDLDESC typedef ptr tagIDLDESC
      IDLFLAG_NONE equ <(PARAMFLAG_NONE)>
      IDLFLAG_FIN equ <(PARAMFLAG_FIN)>
      IDLFLAG_FOUT equ <(PARAMFLAG_FOUT)>
      IDLFLAG_FLCID equ <(PARAMFLAG_FLCID)>
      IDLFLAG_FRETVAL equ <(PARAMFLAG_FRETVAL)>
      ;;begin_internal
      if 0
        ;[...]
      else
        ;;end_internal
        ELEMDESC struct 4
          tdesc TYPEDESC <>
          ;* the type of the element *
          union
            idldesc IDLDESC <>
            ;* info for remoting the element *
            paramdesc PARAMDESC <>
            ;* info about the parameter *
          ends
        ELEMDESC ends
        tagELEMDESC typedef ELEMDESC
        LPELEMDESC typedef ptr ELEMDESC
        ;;begin_internal
        ;* 0 *
      endif
      ;;end_internal
      TYPEATTR struct
        guid GUID <>
        lcid LCID ?
        dwReserved DWORD ?
        memidConstructor MEMBERID ?
        memidDestructor MEMBERID ?
        lpstrSchema LPOLESTR ?
        cbSizeInstance DWORD ?
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
        ;* [size_is] *
        rgdispidNamedArgs POINTER ?
        ;* [size_is] *
        cArgs DWORD ?
        cNamedArgs DWORD ?
      DISPPARAMS ends
      tagDISPPARAMS typedef DISPPARAMS
      ;;begin_internal
      if 0
        ;[...]
      else
        ;;end_internal
        EXCEPINFO struct
          wCode WORD ?
          wReserved WORD ?
          bstrSource BSTR ?
          bstrDescription BSTR ?
          bstrHelpFile BSTR ?
          dwHelpContext DWORD ?
          pvReserved POINTER ?
          TYPE_pfnDeferredFillIn typedef proto WIN_STD_CALL_CONV :ptr tagEXCEPINFO
          pfnDeferredFillIn typedef ptr TYPE_pfnDeferredFillIn

          scode SCODE ?
        EXCEPINFO ends
        tagEXCEPINFO typedef EXCEPINFO
        LPEXCEPINFO typedef ptr EXCEPINFO
        ;;begin_internal
        ;* 0 *
      endif
      ;;end_internal
      ;* [v1_enum] *
      CALLCONV typedef SDWORD
      CC_FASTCALL equ 0
      CC_CDECL equ 1
      CC_MSCPASCAL equ
      CC_PASCAL equ CC_MSCPASCAL
      CC_MACPASCAL equ
      CC_STDCALL equ
      CC_FPFASTCALL equ
      CC_SYSCALL equ
      CC_MPWCDECL equ
      CC_MPWPASCAL equ
      CC_MAX equ
      tagCALLCONV typedef CALLCONV

      ;* [v1_enum] *
      FUNCKIND typedef SDWORD
      FUNC_VIRTUAL equ 0
      FUNC_PUREVIRTUAL equ
      FUNC_NONVIRTUAL equ
      FUNC_STATIC equ
      FUNC_DISPATCH equ
      tagFUNCKIND typedef FUNCKIND

      ;* [v1_enum] *
      INVOKEKIND typedef SDWORD
      INVOKE_FUNC equ 1
      INVOKE_PROPERTYGET equ 2
      INVOKE_PROPERTYPUT equ 4
      INVOKE_PROPERTYPUTREF equ 8
      tagINVOKEKIND typedef INVOKEKIND

      FUNCDESC struct 4
        memid MEMBERID ?
        lprgscode POINTER ?
        ;* [size_is] *
        lprgelemdescParam POINTER ?
        ;* [size_is] *
        funckind FUNCKIND ?
        invkind INVOKEKIND ?
        callconv CALLCONV ?
        cParams SWORD ?
        cParamsOpt SWORD ?
        oVft SWORD ?
        cScodes SWORD ?
        elemdescFunc ELEMDESC <>
        wFuncFlags WORD ?
      FUNCDESC ends
      tagFUNCDESC typedef FUNCDESC
      LPFUNCDESC typedef ptr tagFUNCDESC
      ;* [v1_enum] *
      VARKIND typedef SDWORD
      VAR_PERINSTANCE equ 0
      VAR_STATIC equ
      VAR_CONST equ
      VAR_DISPATCH equ
      tagVARKIND typedef VARKIND

      IMPLTYPEFLAG_FDEFAULT equ (1h)
      IMPLTYPEFLAG_FSOURCE equ (2h)
      IMPLTYPEFLAG_FRESTRICTED equ (4h)
      IMPLTYPEFLAG_FDEFAULTVTABLE equ (8h)
      VARDESC struct 4
        memid MEMBERID ?
        lpstrSchema LPOLESTR ?
        ;* [switch_is][switch_type] *
        union
          oInst DWORD ?
          ;* [case()] *
          lpvarValue POINTER ?
          ;* [case()] *
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

      ;* [wire_marshal] *
      CLEANLOCALSTORAGE struct
        pInterface POINTER ?
        pStorage POINTER ?
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
        ;* [size_is] *
      CUSTDATA ends
      tagCUSTDATA typedef CUSTDATA
      LPCUSTDATA typedef ptr tagCUSTDATA
      externdef IOleAutomationTypes_v1_0_c_ifspec:RPC_IF_HANDLE
      externdef IOleAutomationTypes_v1_0_s_ifspec:RPC_IF_HANDLE
      ;* __IOleAutomationTypes_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_oaidl_0000_0001 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_oaidl_0000_0001_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_oaidl_0000_0001_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ICreateTypeInfo_INTERFACE_DEFINED__
      __ICreateTypeInfo_INTERFACE_DEFINED__ equ <>
      ;* interface ICreateTypeInfo *
      ;* [local][unique][uuid][object] *
      ;* [unique] *
      LPCREATETYPEINFO typedef ptr ICreateTypeInfo
      externdef IID_ICreateTypeInfo:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ICreateTypeInfoVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ICreateTypeInfoVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ICreateTypeInfo, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ICreateTypeInfo
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ICreateTypeInfo
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetGuid)
          STD_METHOD SetGuid, :ptr ICreateTypeInfo, :REFGUID
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetTypeFlags)
          STD_METHOD SetTypeFlags, :ptr ICreateTypeInfo, :UINT
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetDocString)
          ;* [annotation][in] *
          STD_METHOD SetDocString, :ptr ICreateTypeInfo, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetHelpContext)
          STD_METHOD SetHelpContext, :ptr ICreateTypeInfo, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetVersion)
          ;* [in] *
          STD_METHOD SetVersion, :ptr ICreateTypeInfo, :WORD, :WORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo, AddRefTypeInfo)
          ;* [in] *
          STD_METHOD AddRefTypeInfo, :ptr ICreateTypeInfo, :ptr ITypeInfo, :ptr HREFTYPE
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo, AddFuncDesc)
          ;* [in] *
          STD_METHOD AddFuncDesc, :ptr ICreateTypeInfo, :UINT, :ptr FUNCDESC
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo, AddImplType)
          ;* [in] *
          STD_METHOD AddImplType, :ptr ICreateTypeInfo, :UINT, :HREFTYPE
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetImplTypeFlags)
          ;* [in] *
          STD_METHOD SetImplTypeFlags, :ptr ICreateTypeInfo, :UINT, :INT_
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetAlignment)
          STD_METHOD SetAlignment, :ptr ICreateTypeInfo, :WORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetSchema)
          ;* [annotation][in] *
          STD_METHOD SetSchema, :ptr ICreateTypeInfo, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeInfo, AddVarDesc)
          ;* [in] *
          STD_METHOD AddVarDesc, :ptr ICreateTypeInfo, :UINT, :ptr VARDESC
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetFuncAndParamNames)
          ;* [in] *
          ;* [annotation][in][size_is][in] *
          STD_METHOD SetFuncAndParamNames, :ptr ICreateTypeInfo, :UINT, :ptr LPOLESTR, :UINT
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetVarName)
          ;* [in] *
          ;* [annotation][in] *
          STD_METHOD SetVarName, :ptr ICreateTypeInfo, :UINT, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetTypeDescAlias)
          STD_METHOD SetTypeDescAlias, :ptr ICreateTypeInfo, :ptr TYPEDESC
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo, DefineFuncAsDllEntry)
          ;* [in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          STD_METHOD DefineFuncAsDllEntry, :ptr ICreateTypeInfo, :UINT, :LPOLESTR, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetFuncDocString)
          ;* [in] *
          ;* [annotation][in] *
          STD_METHOD SetFuncDocString, :ptr ICreateTypeInfo, :UINT, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetVarDocString)
          ;* [in] *
          ;* [annotation][in] *
          STD_METHOD SetVarDocString, :ptr ICreateTypeInfo, :UINT, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetFuncHelpContext)
          ;* [in] *
          STD_METHOD SetFuncHelpContext, :ptr ICreateTypeInfo, :UINT, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetVarHelpContext)
          ;* [in] *
          STD_METHOD SetVarHelpContext, :ptr ICreateTypeInfo, :UINT, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetMops)
          ;* [in] *
          ;* [annotation][in] *
          STD_METHOD SetMops, :ptr ICreateTypeInfo, :UINT, :BSTR
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetTypeIdldesc)
          STD_METHOD SetTypeIdldesc, :ptr ICreateTypeInfo, :ptr IDLDESC
          ;* [in] *
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
        ;* C style interface *
      endif
      ;* __ICreateTypeInfo_INTERFACE_DEFINED__ *
    endif
    ifndef __ICreateTypeInfo2_INTERFACE_DEFINED__
      __ICreateTypeInfo2_INTERFACE_DEFINED__ equ <>
      ;* interface ICreateTypeInfo2 *
      ;* [local][unique][uuid][object] *
      ;* [unique] *
      LPCREATETYPEINFO2 typedef ptr ICreateTypeInfo2
      externdef IID_ICreateTypeInfo2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ICreateTypeInfo2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ICreateTypeInfo2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ICreateTypeInfo2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ICreateTypeInfo2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ICreateTypeInfo2
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetGuid)
          STD_METHOD SetGuid, :ptr ICreateTypeInfo2, :REFGUID
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetTypeFlags)
          STD_METHOD SetTypeFlags, :ptr ICreateTypeInfo2, :UINT
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetDocString)
          ;* [annotation][in] *
          STD_METHOD SetDocString, :ptr ICreateTypeInfo2, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetHelpContext)
          STD_METHOD SetHelpContext, :ptr ICreateTypeInfo2, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetVersion)
          ;* [in] *
          STD_METHOD SetVersion, :ptr ICreateTypeInfo2, :WORD, :WORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo, AddRefTypeInfo)
          ;* [in] *
          STD_METHOD AddRefTypeInfo, :ptr ICreateTypeInfo2, :ptr ITypeInfo, :ptr HREFTYPE
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo, AddFuncDesc)
          ;* [in] *
          STD_METHOD AddFuncDesc, :ptr ICreateTypeInfo2, :UINT, :ptr FUNCDESC
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo, AddImplType)
          ;* [in] *
          STD_METHOD AddImplType, :ptr ICreateTypeInfo2, :UINT, :HREFTYPE
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetImplTypeFlags)
          ;* [in] *
          STD_METHOD SetImplTypeFlags, :ptr ICreateTypeInfo2, :UINT, :INT_
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetAlignment)
          STD_METHOD SetAlignment, :ptr ICreateTypeInfo2, :WORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetSchema)
          ;* [annotation][in] *
          STD_METHOD SetSchema, :ptr ICreateTypeInfo2, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeInfo, AddVarDesc)
          ;* [in] *
          STD_METHOD AddVarDesc, :ptr ICreateTypeInfo2, :UINT, :ptr VARDESC
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetFuncAndParamNames)
          ;* [in] *
          ;* [annotation][in][size_is][in] *
          STD_METHOD SetFuncAndParamNames, :ptr ICreateTypeInfo2, :UINT, :ptr LPOLESTR, :UINT
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetVarName)
          ;* [in] *
          ;* [annotation][in] *
          STD_METHOD SetVarName, :ptr ICreateTypeInfo2, :UINT, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetTypeDescAlias)
          STD_METHOD SetTypeDescAlias, :ptr ICreateTypeInfo2, :ptr TYPEDESC
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo, DefineFuncAsDllEntry)
          ;* [in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          STD_METHOD DefineFuncAsDllEntry, :ptr ICreateTypeInfo2, :UINT, :LPOLESTR, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetFuncDocString)
          ;* [in] *
          ;* [annotation][in] *
          STD_METHOD SetFuncDocString, :ptr ICreateTypeInfo2, :UINT, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetVarDocString)
          ;* [in] *
          ;* [annotation][in] *
          STD_METHOD SetVarDocString, :ptr ICreateTypeInfo2, :UINT, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetFuncHelpContext)
          ;* [in] *
          STD_METHOD SetFuncHelpContext, :ptr ICreateTypeInfo2, :UINT, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetVarHelpContext)
          ;* [in] *
          STD_METHOD SetVarHelpContext, :ptr ICreateTypeInfo2, :UINT, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetMops)
          ;* [in] *
          ;* [annotation][in] *
          STD_METHOD SetMops, :ptr ICreateTypeInfo2, :UINT, :BSTR
          DECLSPEC_XFGVIRT(ICreateTypeInfo, SetTypeIdldesc)
          STD_METHOD SetTypeIdldesc, :ptr ICreateTypeInfo2, :ptr IDLDESC
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo, LayOut)
          STD_METHOD LayOut, :ptr ICreateTypeInfo2
          DECLSPEC_XFGVIRT(ICreateTypeInfo2, DeleteFuncDesc)
          STD_METHOD DeleteFuncDesc, :ptr ICreateTypeInfo2, :UINT
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo2, DeleteFuncDescByMemId)
          ;* [in] *
          STD_METHOD DeleteFuncDescByMemId, :ptr ICreateTypeInfo2, :MEMBERID, :INVOKEKIND
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo2, DeleteVarDesc)
          STD_METHOD DeleteVarDesc, :ptr ICreateTypeInfo2, :UINT
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo2, DeleteVarDescByMemId)
          STD_METHOD DeleteVarDescByMemId, :ptr ICreateTypeInfo2, :MEMBERID
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo2, DeleteImplType)
          STD_METHOD DeleteImplType, :ptr ICreateTypeInfo2, :UINT
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo2, SetCustData)
          ;* [in] *
          STD_METHOD SetCustData, :ptr ICreateTypeInfo2, :REFGUID, :ptr VARIANT
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo2, SetFuncCustData)
          ;* [in] *
          ;* [in] *
          STD_METHOD SetFuncCustData, :ptr ICreateTypeInfo2, :UINT, :REFGUID, :ptr VARIANT
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo2, SetParamCustData)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD SetParamCustData, :ptr ICreateTypeInfo2, :UINT, :UINT, :REFGUID, :ptr VARIANT
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo2, SetVarCustData)
          ;* [in] *
          ;* [in] *
          STD_METHOD SetVarCustData, :ptr ICreateTypeInfo2, :UINT, :REFGUID, :ptr VARIANT
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo2, SetImplTypeCustData)
          ;* [in] *
          ;* [in] *
          STD_METHOD SetImplTypeCustData, :ptr ICreateTypeInfo2, :UINT, :REFGUID, :ptr VARIANT
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo2, SetHelpStringContext)
          STD_METHOD SetHelpStringContext, :ptr ICreateTypeInfo2, :ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo2, SetFuncHelpStringContext)
          ;* [in] *
          STD_METHOD SetFuncHelpStringContext, :ptr ICreateTypeInfo2, :UINT, :ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo2, SetVarHelpStringContext)
          ;* [in] *
          STD_METHOD SetVarHelpStringContext, :ptr ICreateTypeInfo2, :UINT, :ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeInfo2, Invalidate)
          STD_METHOD Invalidate, :ptr ICreateTypeInfo2
          DECLSPEC_XFGVIRT(ICreateTypeInfo2, SetName)
          ;* [annotation][in] *
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
        ;* C style interface *
      endif
      ;* __ICreateTypeInfo2_INTERFACE_DEFINED__ *
    endif
    ifndef __ICreateTypeLib_INTERFACE_DEFINED__
      __ICreateTypeLib_INTERFACE_DEFINED__ equ <>
      ;* interface ICreateTypeLib *
      ;* [local][unique][uuid][object] *
      ;* [unique] *
      LPCREATETYPELIB typedef ptr ICreateTypeLib
      externdef IID_ICreateTypeLib:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ICreateTypeLibVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ICreateTypeLibVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ICreateTypeLib, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ICreateTypeLib
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ICreateTypeLib
          DECLSPEC_XFGVIRT(ICreateTypeLib, CreateTypeInfo)
          ;* [annotation][in] *
          ;* [in] *
          STD_METHOD CreateTypeInfo, :ptr ICreateTypeLib, :LPOLESTR, :TYPEKIND, :ptr ptr ICreateTypeInfo
          ;* [out] *
          DECLSPEC_XFGVIRT(ICreateTypeLib, SetName)
          ;* [annotation][in] *
          STD_METHOD SetName, :ptr ICreateTypeLib, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeLib, SetVersion)
          ;* [in] *
          STD_METHOD SetVersion, :ptr ICreateTypeLib, :WORD, :WORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeLib, SetGuid)
          STD_METHOD SetGuid, :ptr ICreateTypeLib, :REFGUID
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeLib, SetDocString)
          ;* [annotation][in] *
          STD_METHOD SetDocString, :ptr ICreateTypeLib, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeLib, SetHelpFileName)
          ;* [annotation][in] *
          STD_METHOD SetHelpFileName, :ptr ICreateTypeLib, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeLib, SetHelpContext)
          STD_METHOD SetHelpContext, :ptr ICreateTypeLib, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeLib, SetLcid)
          STD_METHOD SetLcid, :ptr ICreateTypeLib, :LCID
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeLib, SetLibFlags)
          STD_METHOD SetLibFlags, :ptr ICreateTypeLib, :UINT
          ;* [in] *
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
        ;* C style interface *
      endif
      ;* __ICreateTypeLib_INTERFACE_DEFINED__ *
    endif
    ifndef __ICreateTypeLib2_INTERFACE_DEFINED__
      __ICreateTypeLib2_INTERFACE_DEFINED__ equ <>
      ;* interface ICreateTypeLib2 *
      ;* [local][unique][uuid][object] *
      ;* [unique] *
      LPCREATETYPELIB2 typedef ptr ICreateTypeLib2
      externdef IID_ICreateTypeLib2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ICreateTypeLib2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ICreateTypeLib2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ICreateTypeLib2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ICreateTypeLib2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ICreateTypeLib2
          DECLSPEC_XFGVIRT(ICreateTypeLib, CreateTypeInfo)
          ;* [annotation][in] *
          ;* [in] *
          STD_METHOD CreateTypeInfo, :ptr ICreateTypeLib2, :LPOLESTR, :TYPEKIND, :ptr ptr ICreateTypeInfo
          ;* [out] *
          DECLSPEC_XFGVIRT(ICreateTypeLib, SetName)
          ;* [annotation][in] *
          STD_METHOD SetName, :ptr ICreateTypeLib2, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeLib, SetVersion)
          ;* [in] *
          STD_METHOD SetVersion, :ptr ICreateTypeLib2, :WORD, :WORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeLib, SetGuid)
          STD_METHOD SetGuid, :ptr ICreateTypeLib2, :REFGUID
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeLib, SetDocString)
          ;* [annotation][in] *
          STD_METHOD SetDocString, :ptr ICreateTypeLib2, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeLib, SetHelpFileName)
          ;* [annotation][in] *
          STD_METHOD SetHelpFileName, :ptr ICreateTypeLib2, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeLib, SetHelpContext)
          STD_METHOD SetHelpContext, :ptr ICreateTypeLib2, :DWORD
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeLib, SetLcid)
          STD_METHOD SetLcid, :ptr ICreateTypeLib2, :LCID
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeLib, SetLibFlags)
          STD_METHOD SetLibFlags, :ptr ICreateTypeLib2, :UINT
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeLib, SaveAllChanges)
          STD_METHOD SaveAllChanges, :ptr ICreateTypeLib2
          DECLSPEC_XFGVIRT(ICreateTypeLib2, DeleteTypeInfo)
          ;* [annotation][in] *
          STD_METHOD DeleteTypeInfo, :ptr ICreateTypeLib2, :LPOLESTR
          DECLSPEC_XFGVIRT(ICreateTypeLib2, SetCustData)
          ;* [in] *
          STD_METHOD SetCustData, :ptr ICreateTypeLib2, :REFGUID, :ptr VARIANT
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeLib2, SetHelpStringContext)
          STD_METHOD SetHelpStringContext, :ptr ICreateTypeLib2, :ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateTypeLib2, SetHelpStringDll)
          ;* [annotation][in] *
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
        ;* C style interface *
      endif
      ;* __ICreateTypeLib2_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_oaidl_0000_0005 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    externdef __MIDL_itf_oaidl_0000_0005_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_oaidl_0000_0005_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __IDispatch_INTERFACE_DEFINED__
      __IDispatch_INTERFACE_DEFINED__ equ <>
      ;* interface IDispatch *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPDISPATCH typedef ptr IDispatch
      ;* DISPID reserved to indicate an "unknown" name *
      ;* only reserved for data members (properties); reused as a method dispid below *
      DISPID_UNKNOWN equ (- 1)
      ;* DISPID reserved for the "value" property *
      DISPID_VALUE equ (0)
      ;* The following DISPID is reserved to indicate the param
      ;* that is the right-hand-side (or "put" value) of a PropertyPut
      ;*
      DISPID_PROPERTYPUT equ (- 3)
      ;* DISPID reserved for the standard "NewEnum" method *
      DISPID_NEWENUM equ (- 4)
      ;* DISPID reserved for the standard "Evaluate" method *
      DISPID_EVALUATE equ (- 5)
      DISPID_CONSTRUCTOR equ (- 6)
      DISPID_DESTRUCTOR equ (- 7)
      DISPID_COLLECT equ (- 8)
      ;* The range -500 through -999 is reserved for Controls *
      ;* The range 0x80010000 through 0x8001FFFF is reserved for Controls *
      ;* The range -5000 through -5499 is reserved for ActiveX Accessability *
      ;* The range -2000 through -2499 is reserved for VB5 *
      ;* The range -3900 through -3999 is reserved for Forms *
      ;* The range -5500 through -5550 is reserved for Forms *
      ;* The remainder of the negative DISPIDs are reserved for future use *
      externdef IID_IDispatch:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IDispatchVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IDispatchVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IDispatch, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IDispatch
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IDispatch
          DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
          STD_METHOD GetTypeInfoCount, :ptr IDispatch, :ptr UINT
          ;* [out] *
          DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
          ;* [in] *
          ;* [in] *
          STD_METHOD GetTypeInfo, :ptr IDispatch, :UINT, :LCID, :ptr ptr ITypeInfo
          ;* [out] *
          DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
          ;* [in] *
          ;* [size_is][in] *
          ;* [range][in] *
          ;* [in] *
          STD_METHOD GetIDsOfNames, :ptr IDispatch, :REFIID, :ptr LPOLESTR, :UINT, :LCID, :ptr DISPID
          ;* [size_is][out] *
          DECLSPEC_XFGVIRT(IDispatch, Invoke)
          ;* [local] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][in] *
          ;* [annotation][out][in] *
          ;* [annotation][out] *
          ;* [annotation][out] *
          ;* [annotation][out] *
          STD_METHOD Invoke_, :ptr IDispatch, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
          ??Interface equ <>
          END_INTERFACE
        IDispatchVtbl ends
        IDispatch struct
          lpVtbl POINTER ?
        IDispatch ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      IDispatch_RemoteInvoke_Proxy proto WIN_STD_CALL_CONV :ptr IDispatch, :DISPID, :REFIID, :LCID, :DWORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT, :UINT, :ptr UINT, :ptr VARIANTARG
      ;* [size_is][out][in] *
      IDispatch_RemoteInvoke_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __IDispatch_INTERFACE_DEFINED__ *
    endif
    ifndef __IEnumVARIANT_INTERFACE_DEFINED__
      __IEnumVARIANT_INTERFACE_DEFINED__ equ <>
      ;* interface IEnumVARIANT *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPENUMVARIANT typedef ptr IEnumVARIANT
      externdef IID_IEnumVARIANT:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IEnumVARIANTVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IEnumVARIANTVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IEnumVARIANT, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IEnumVARIANT
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IEnumVARIANT
          DECLSPEC_XFGVIRT(IEnumVARIANT, Next)
          ;* [local] *
          ;* [in] *
          ;* [length_is][size_is][out] *
          STD_METHOD Next, :ptr IEnumVARIANT, :ULONG, :ptr VARIANT, :ptr ULONG
          ;* [out] *
          DECLSPEC_XFGVIRT(IEnumVARIANT, Skip)
          STD_METHOD Skip, :ptr IEnumVARIANT, :ULONG
          ;* [in] *
          DECLSPEC_XFGVIRT(IEnumVARIANT, Reset)
          STD_METHOD Reset, :ptr IEnumVARIANT
          DECLSPEC_XFGVIRT(IEnumVARIANT, Clone)
          STD_METHOD Clone, :ptr IEnumVARIANT, :ptr ptr IEnumVARIANT
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IEnumVARIANTVtbl ends
        IEnumVARIANT struct
          lpVtbl POINTER ?
        IEnumVARIANT ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      IEnumVARIANT_RemoteNext_Proxy proto WIN_STD_CALL_CONV :ptr IEnumVARIANT, :ULONG, :ptr VARIANT, :ptr ULONG
      ;* [out] *
      IEnumVARIANT_RemoteNext_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __IEnumVARIANT_INTERFACE_DEFINED__ *
    endif
    ifndef __ITypeComp_INTERFACE_DEFINED__
      __ITypeComp_INTERFACE_DEFINED__ equ <>
      ;* interface ITypeComp *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPTYPECOMP typedef ptr ITypeComp
      ;* [v1_enum] *
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
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ITypeComp, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ITypeComp
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ITypeComp
          DECLSPEC_XFGVIRT(ITypeComp, Bind)
          ;* [local] *
          ;* [annotation][in] *
          ;* [in] *
          ;* [in] *
          ;* [out] *
          ;* [out] *
          STD_METHOD Bind, :ptr ITypeComp, :LPOLESTR, :ULONG, :WORD, :ptr ptr ITypeInfo, :ptr DESCKIND, :ptr BINDPTR
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeComp, BindType)
          ;* [local] *
          ;* [annotation][in] *
          ;* [in] *
          ;* [out] *
          STD_METHOD BindType, :ptr ITypeComp, :LPOLESTR, :ULONG, :ptr ptr ITypeInfo, :ptr ptr ITypeComp
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        ITypeCompVtbl ends
        ITypeComp struct
          lpVtbl POINTER ?
        ITypeComp ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      ITypeComp_RemoteBind_Proxy proto WIN_STD_CALL_CONV :ptr ITypeComp, :LPOLESTR, :ULONG, :WORD, :ptr ptr ITypeInfo, :ptr DESCKIND, :ptr LPFUNCDESC, :ptr LPVARDESC, :ptr ptr ITypeComp, :ptr CLEANLOCALSTORAGE
      ;* [out] *
      ITypeComp_RemoteBind_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      ITypeComp_RemoteBindType_Proxy proto WIN_STD_CALL_CONV :ptr ITypeComp, :LPOLESTR, :ULONG, :ptr ptr ITypeInfo
      ;* [out] *
      ITypeComp_RemoteBindType_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __ITypeComp_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_oaidl_0000_0008 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_oaidl_0000_0008_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_oaidl_0000_0008_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ITypeInfo_INTERFACE_DEFINED__
      __ITypeInfo_INTERFACE_DEFINED__ equ <>
      ;* interface ITypeInfo *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPTYPEINFO typedef ptr ITypeInfo
      externdef IID_ITypeInfo:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ITypeInfoVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ITypeInfoVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ITypeInfo, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ITypeInfo
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ITypeInfo
          DECLSPEC_XFGVIRT(ITypeInfo, GetTypeAttr)
          ;* [local] *
          STD_METHOD GetTypeAttr, :ptr ITypeInfo, :ptr ptr TYPEATTR
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo, GetTypeComp)
          STD_METHOD GetTypeComp, :ptr ITypeInfo, :ptr ptr ITypeComp
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo, GetFuncDesc)
          ;* [local] *
          ;* [in] *
          STD_METHOD GetFuncDesc, :ptr ITypeInfo, :UINT, :ptr ptr FUNCDESC
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo, GetVarDesc)
          ;* [local] *
          ;* [in] *
          STD_METHOD GetVarDesc, :ptr ITypeInfo, :UINT, :ptr ptr VARDESC
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo, GetNames)
          ;* [local] *
          ;* [in] *
          ;* [annotation][length_is][size_is][out] *
          ;* [in] *
          ;* [annotation][out] *
          STD_METHOD GetNames, :ptr ITypeInfo, :MEMBERID, :ptr BSTR, :UINT, :ptr UINT
          DECLSPEC_XFGVIRT(ITypeInfo, GetRefTypeOfImplType)
          ;* [in] *
          STD_METHOD GetRefTypeOfImplType, :ptr ITypeInfo, :UINT, :ptr HREFTYPE
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo, GetImplTypeFlags)
          ;* [in] *
          STD_METHOD GetImplTypeFlags, :ptr ITypeInfo, :UINT, :ptr INT_
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo, GetIDsOfNames)
          ;* [local] *
          ;* [annotation][size_is][in] *
          ;* [in] *
          STD_METHOD GetIDsOfNames, :ptr ITypeInfo, :ptr LPOLESTR, :UINT, :ptr MEMBERID
          ;* [size_is][out] *
          DECLSPEC_XFGVIRT(ITypeInfo, Invoke)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [out][in] *
          ;* [out] *
          ;* [out] *
          STD_METHOD Invoke_, :ptr ITypeInfo, :PVOID, :MEMBERID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo, GetDocumentation)
          ;* [local] *
          ;* [in] *
          ;* [annotation][out] *
          ;* [annotation][out] *
          ;* [out] *
          ;* [annotation][out] *
          STD_METHOD GetDocumentation, :ptr ITypeInfo, :MEMBERID, :ptr BSTR, :ptr BSTR, :ptr DWORD, :ptr BSTR
          DECLSPEC_XFGVIRT(ITypeInfo, GetDllEntry)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          ;* [annotation][out] *
          ;* [annotation][out] *
          STD_METHOD GetDllEntry, :ptr ITypeInfo, :MEMBERID, :INVOKEKIND, :ptr BSTR, :ptr BSTR, :ptr WORD
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo, GetRefTypeInfo)
          ;* [in] *
          STD_METHOD GetRefTypeInfo, :ptr ITypeInfo, :HREFTYPE, :ptr ptr ITypeInfo
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo, AddressOfMember)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          STD_METHOD AddressOfMember, :ptr ITypeInfo, :MEMBERID, :INVOKEKIND, :ptr PVOID
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo, CreateInstance)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          STD_METHOD CreateInstance, :ptr ITypeInfo, :ptr IUnknown, :REFIID, :ptr PVOID
          ;* [iid_is][out] *
          DECLSPEC_XFGVIRT(ITypeInfo, GetMops)
          ;* [in] *
          STD_METHOD GetMops, :ptr ITypeInfo, :MEMBERID, :ptr BSTR
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo, GetContainingTypeLib)
          ;* [local] *
          ;* [out] *
          STD_METHOD GetContainingTypeLib, :ptr ITypeInfo, :ptr ptr ITypeLib, :ptr UINT
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo, ReleaseTypeAttr)
          ;* [local] *
          STD_METHOD ReleaseTypeAttr, :ptr ITypeInfo, :ptr TYPEATTR
          ;* [in] *
          DECLSPEC_XFGVIRT(ITypeInfo, ReleaseFuncDesc)
          ;* [local] *
          STD_METHOD ReleaseFuncDesc, :ptr ITypeInfo, :ptr FUNCDESC
          ;* [in] *
          DECLSPEC_XFGVIRT(ITypeInfo, ReleaseVarDesc)
          ;* [local] *
          STD_METHOD ReleaseVarDesc, :ptr ITypeInfo, :ptr VARDESC
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        ITypeInfoVtbl ends
        ITypeInfo struct
          lpVtbl POINTER ?
        ITypeInfo ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      ITypeInfo_RemoteGetTypeAttr_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :ptr LPTYPEATTR, :ptr CLEANLOCALSTORAGE
      ;* [out] *
      ITypeInfo_RemoteGetTypeAttr_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      ITypeInfo_RemoteGetFuncDesc_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :UINT, :ptr LPFUNCDESC, :ptr CLEANLOCALSTORAGE
      ;* [out] *
      ITypeInfo_RemoteGetFuncDesc_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      ITypeInfo_RemoteGetVarDesc_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :UINT, :ptr LPVARDESC, :ptr CLEANLOCALSTORAGE
      ;* [out] *
      ITypeInfo_RemoteGetVarDesc_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      ITypeInfo_RemoteGetNames_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :MEMBERID, :ptr BSTR, :UINT, :ptr UINT
      ;* [out] *
      ITypeInfo_RemoteGetNames_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [nocode][call_as] *
      ITypeInfo_LocalGetIDsOfNames_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo
      ITypeInfo_LocalGetIDsOfNames_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [nocode][call_as] *
      ITypeInfo_LocalInvoke_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo
      ITypeInfo_LocalInvoke_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      ITypeInfo_RemoteGetDocumentation_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :MEMBERID, :DWORD, :ptr BSTR, :ptr BSTR, :ptr DWORD, :ptr BSTR
      ;* [out] *
      ITypeInfo_RemoteGetDocumentation_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      ITypeInfo_RemoteGetDllEntry_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :MEMBERID, :INVOKEKIND, :DWORD, :ptr BSTR, :ptr BSTR, :ptr WORD
      ;* [out] *
      ITypeInfo_RemoteGetDllEntry_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [nocode][call_as] *
      ITypeInfo_LocalAddressOfMember_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo
      ITypeInfo_LocalAddressOfMember_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      ITypeInfo_RemoteCreateInstance_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :REFIID, :ptr ptr IUnknown
      ;* [iid_is][out] *
      ITypeInfo_RemoteCreateInstance_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      ITypeInfo_RemoteGetContainingTypeLib_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :ptr ptr ITypeLib, :ptr UINT
      ;* [out] *
      ITypeInfo_RemoteGetContainingTypeLib_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [nocode][call_as] *
      ITypeInfo_LocalReleaseTypeAttr_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo
      ITypeInfo_LocalReleaseTypeAttr_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [nocode][call_as] *
      ITypeInfo_LocalReleaseFuncDesc_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo
      ITypeInfo_LocalReleaseFuncDesc_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [nocode][call_as] *
      ITypeInfo_LocalReleaseVarDesc_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo
      ITypeInfo_LocalReleaseVarDesc_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __ITypeInfo_INTERFACE_DEFINED__ *
    endif
    ifndef __ITypeInfo2_INTERFACE_DEFINED__
      __ITypeInfo2_INTERFACE_DEFINED__ equ <>
      ;* interface ITypeInfo2 *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPTYPEINFO2 typedef ptr ITypeInfo2
      externdef IID_ITypeInfo2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ITypeInfo2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ITypeInfo2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ITypeInfo2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ITypeInfo2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ITypeInfo2
          DECLSPEC_XFGVIRT(ITypeInfo, GetTypeAttr)
          ;* [local] *
          STD_METHOD GetTypeAttr, :ptr ITypeInfo2, :ptr ptr TYPEATTR
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo, GetTypeComp)
          STD_METHOD GetTypeComp, :ptr ITypeInfo2, :ptr ptr ITypeComp
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo, GetFuncDesc)
          ;* [local] *
          ;* [in] *
          STD_METHOD GetFuncDesc, :ptr ITypeInfo2, :UINT, :ptr ptr FUNCDESC
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo, GetVarDesc)
          ;* [local] *
          ;* [in] *
          STD_METHOD GetVarDesc, :ptr ITypeInfo2, :UINT, :ptr ptr VARDESC
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo, GetNames)
          ;* [local] *
          ;* [in] *
          ;* [annotation][length_is][size_is][out] *
          ;* [in] *
          ;* [annotation][out] *
          STD_METHOD GetNames, :ptr ITypeInfo2, :MEMBERID, :ptr BSTR, :UINT, :ptr UINT
          DECLSPEC_XFGVIRT(ITypeInfo, GetRefTypeOfImplType)
          ;* [in] *
          STD_METHOD GetRefTypeOfImplType, :ptr ITypeInfo2, :UINT, :ptr HREFTYPE
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo, GetImplTypeFlags)
          ;* [in] *
          STD_METHOD GetImplTypeFlags, :ptr ITypeInfo2, :UINT, :ptr INT_
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo, GetIDsOfNames)
          ;* [local] *
          ;* [annotation][size_is][in] *
          ;* [in] *
          STD_METHOD GetIDsOfNames, :ptr ITypeInfo2, :ptr LPOLESTR, :UINT, :ptr MEMBERID
          ;* [size_is][out] *
          DECLSPEC_XFGVIRT(ITypeInfo, Invoke)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [out][in] *
          ;* [out] *
          ;* [out] *
          STD_METHOD Invoke_, :ptr ITypeInfo2, :PVOID, :MEMBERID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo, GetDocumentation)
          ;* [local] *
          ;* [in] *
          ;* [annotation][out] *
          ;* [annotation][out] *
          ;* [out] *
          ;* [annotation][out] *
          STD_METHOD GetDocumentation, :ptr ITypeInfo2, :MEMBERID, :ptr BSTR, :ptr BSTR, :ptr DWORD, :ptr BSTR
          DECLSPEC_XFGVIRT(ITypeInfo, GetDllEntry)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          ;* [annotation][out] *
          ;* [annotation][out] *
          STD_METHOD GetDllEntry, :ptr ITypeInfo2, :MEMBERID, :INVOKEKIND, :ptr BSTR, :ptr BSTR, :ptr WORD
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo, GetRefTypeInfo)
          ;* [in] *
          STD_METHOD GetRefTypeInfo, :ptr ITypeInfo2, :HREFTYPE, :ptr ptr ITypeInfo
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo, AddressOfMember)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          STD_METHOD AddressOfMember, :ptr ITypeInfo2, :MEMBERID, :INVOKEKIND, :ptr PVOID
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo, CreateInstance)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          STD_METHOD CreateInstance, :ptr ITypeInfo2, :ptr IUnknown, :REFIID, :ptr PVOID
          ;* [iid_is][out] *
          DECLSPEC_XFGVIRT(ITypeInfo, GetMops)
          ;* [in] *
          STD_METHOD GetMops, :ptr ITypeInfo2, :MEMBERID, :ptr BSTR
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo, GetContainingTypeLib)
          ;* [local] *
          ;* [out] *
          STD_METHOD GetContainingTypeLib, :ptr ITypeInfo2, :ptr ptr ITypeLib, :ptr UINT
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo, ReleaseTypeAttr)
          ;* [local] *
          STD_METHOD ReleaseTypeAttr, :ptr ITypeInfo2, :ptr TYPEATTR
          ;* [in] *
          DECLSPEC_XFGVIRT(ITypeInfo, ReleaseFuncDesc)
          ;* [local] *
          STD_METHOD ReleaseFuncDesc, :ptr ITypeInfo2, :ptr FUNCDESC
          ;* [in] *
          DECLSPEC_XFGVIRT(ITypeInfo, ReleaseVarDesc)
          ;* [local] *
          STD_METHOD ReleaseVarDesc, :ptr ITypeInfo2, :ptr VARDESC
          ;* [in] *
          DECLSPEC_XFGVIRT(ITypeInfo2, GetTypeKind)
          STD_METHOD GetTypeKind, :ptr ITypeInfo2, :ptr TYPEKIND
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo2, GetTypeFlags)
          STD_METHOD GetTypeFlags, :ptr ITypeInfo2, :ptr ULONG
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo2, GetFuncIndexOfMemId)
          ;* [in] *
          ;* [in] *
          STD_METHOD GetFuncIndexOfMemId, :ptr ITypeInfo2, :MEMBERID, :INVOKEKIND, :ptr UINT
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo2, GetVarIndexOfMemId)
          ;* [in] *
          STD_METHOD GetVarIndexOfMemId, :ptr ITypeInfo2, :MEMBERID, :ptr UINT
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo2, GetCustData)
          ;* [in] *
          STD_METHOD GetCustData, :ptr ITypeInfo2, :REFGUID, :ptr VARIANT
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo2, GetFuncCustData)
          ;* [in] *
          ;* [in] *
          STD_METHOD GetFuncCustData, :ptr ITypeInfo2, :UINT, :REFGUID, :ptr VARIANT
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo2, GetParamCustData)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD GetParamCustData, :ptr ITypeInfo2, :UINT, :UINT, :REFGUID, :ptr VARIANT
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo2, GetVarCustData)
          ;* [in] *
          ;* [in] *
          STD_METHOD GetVarCustData, :ptr ITypeInfo2, :UINT, :REFGUID, :ptr VARIANT
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo2, GetImplTypeCustData)
          ;* [in] *
          ;* [in] *
          STD_METHOD GetImplTypeCustData, :ptr ITypeInfo2, :UINT, :REFGUID, :ptr VARIANT
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo2, GetDocumentation2)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          ;* [annotation][out] *
          ;* [out] *
          ;* [annotation][out] *
          STD_METHOD GetDocumentation2, :ptr ITypeInfo2, :MEMBERID, :LCID, :ptr BSTR, :ptr DWORD, :ptr BSTR
          DECLSPEC_XFGVIRT(ITypeInfo2, GetAllCustData)
          STD_METHOD GetAllCustData, :ptr ITypeInfo2, :ptr CUSTDATA
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo2, GetAllFuncCustData)
          ;* [in] *
          STD_METHOD GetAllFuncCustData, :ptr ITypeInfo2, :UINT, :ptr CUSTDATA
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo2, GetAllParamCustData)
          ;* [in] *
          ;* [in] *
          STD_METHOD GetAllParamCustData, :ptr ITypeInfo2, :UINT, :UINT, :ptr CUSTDATA
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo2, GetAllVarCustData)
          ;* [in] *
          STD_METHOD GetAllVarCustData, :ptr ITypeInfo2, :UINT, :ptr CUSTDATA
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeInfo2, GetAllImplTypeCustData)
          ;* [in] *
          STD_METHOD GetAllImplTypeCustData, :ptr ITypeInfo2, :UINT, :ptr CUSTDATA
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        ITypeInfo2Vtbl ends
        ITypeInfo2 struct
          lpVtbl POINTER ?
        ITypeInfo2 ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      ITypeInfo2_RemoteGetDocumentation2_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo2, :MEMBERID, :LCID, :DWORD, :ptr BSTR, :ptr DWORD, :ptr BSTR
      ;* [out] *
      ITypeInfo2_RemoteGetDocumentation2_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __ITypeInfo2_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_oaidl_0000_0010 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    externdef __MIDL_itf_oaidl_0000_0010_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_oaidl_0000_0010_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ITypeLib_INTERFACE_DEFINED__
      __ITypeLib_INTERFACE_DEFINED__ equ <>
      ;* interface ITypeLib *
      ;* [unique][uuid][object] *
      ;* [v1_enum] *
      SYSKIND typedef SDWORD
      SYS_WIN16 equ 0
      SYS_WIN32 equ
      SYS_MAC equ
      SYS_WIN64 equ
      tagSYSKIND typedef SYSKIND

      ;* [v1_enum] *
      LIBFLAGS typedef SDWORD
      LIBFLAG_FRESTRICTED equ 1h
      LIBFLAG_FCONTROL equ 2h
      LIBFLAG_FHIDDEN equ 4h
      LIBFLAG_FHASDISKIMAGE equ 8h
      tagLIBFLAGS typedef LIBFLAGS

      ;* [unique] *
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
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ITypeLib, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ITypeLib
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ITypeLib
          DECLSPEC_XFGVIRT(ITypeLib, GetTypeInfoCount)
          ;* [local] *
          STD_METHOD GetTypeInfoCount, :ptr ITypeLib
          DECLSPEC_XFGVIRT(ITypeLib, GetTypeInfo)
          ;* [in] *
          STD_METHOD GetTypeInfo, :ptr ITypeLib, :UINT, :ptr ptr ITypeInfo
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeLib, GetTypeInfoType)
          ;* [in] *
          STD_METHOD GetTypeInfoType, :ptr ITypeLib, :UINT, :ptr TYPEKIND
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeLib, GetTypeInfoOfGuid)
          ;* [in] *
          STD_METHOD GetTypeInfoOfGuid, :ptr ITypeLib, :REFGUID, :ptr ptr ITypeInfo
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeLib, GetLibAttr)
          ;* [local] *
          STD_METHOD GetLibAttr, :ptr ITypeLib, :ptr ptr TLIBATTR
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeLib, GetTypeComp)
          STD_METHOD GetTypeComp, :ptr ITypeLib, :ptr ptr ITypeComp
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeLib, GetDocumentation)
          ;* [local] *
          ;* [in] *
          ;* [annotation][out] *
          ;* [annotation][out] *
          ;* [out] *
          ;* [annotation][out] *
          STD_METHOD GetDocumentation, :ptr ITypeLib, :INT_, :ptr BSTR, :ptr BSTR, :ptr DWORD, :ptr BSTR
          DECLSPEC_XFGVIRT(ITypeLib, IsName)
          ;* [local] *
          ;* [annotation][out][in] *
          ;* [in] *
          STD_METHOD IsName, :ptr ITypeLib, :LPOLESTR, :ULONG, :ptr BOOL
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeLib, FindName)
          ;* [local] *
          ;* [annotation][out][in] *
          ;* [in] *
          ;* [length_is][size_is][out] *
          ;* [length_is][size_is][out] *
          STD_METHOD FindName, :ptr ITypeLib, :LPOLESTR, :ULONG, :ptr ptr ITypeInfo, :ptr MEMBERID, :ptr USHORT
          ;* [out][in] *
          DECLSPEC_XFGVIRT(ITypeLib, ReleaseTLibAttr)
          ;* [local] *
          STD_METHOD ReleaseTLibAttr, :ptr ITypeLib, :ptr TLIBATTR
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        ITypeLibVtbl ends
        ITypeLib struct
          lpVtbl POINTER ?
        ITypeLib ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      ITypeLib_RemoteGetTypeInfoCount_Proxy proto WIN_STD_CALL_CONV :ptr ITypeLib, :ptr UINT
      ;* [out] *
      ITypeLib_RemoteGetTypeInfoCount_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      ITypeLib_RemoteGetLibAttr_Proxy proto WIN_STD_CALL_CONV :ptr ITypeLib, :ptr LPTLIBATTR, :ptr CLEANLOCALSTORAGE
      ;* [out] *
      ITypeLib_RemoteGetLibAttr_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      ITypeLib_RemoteGetDocumentation_Proxy proto WIN_STD_CALL_CONV :ptr ITypeLib, :INT_, :DWORD, :ptr BSTR, :ptr BSTR, :ptr DWORD, :ptr BSTR
      ;* [out] *
      ITypeLib_RemoteGetDocumentation_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      ITypeLib_RemoteIsName_Proxy proto WIN_STD_CALL_CONV :ptr ITypeLib, :LPOLESTR, :ULONG, :ptr BOOL, :ptr BSTR
      ;* [out] *
      ITypeLib_RemoteIsName_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      ITypeLib_RemoteFindName_Proxy proto WIN_STD_CALL_CONV :ptr ITypeLib, :LPOLESTR, :ULONG, :ptr ptr ITypeInfo, :ptr MEMBERID, :ptr USHORT, :ptr BSTR
      ;* [out] *
      ITypeLib_RemoteFindName_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [nocode][call_as] *
      ITypeLib_LocalReleaseTLibAttr_Proxy proto WIN_STD_CALL_CONV :ptr ITypeLib
      ITypeLib_LocalReleaseTLibAttr_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __ITypeLib_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_oaidl_0000_0011 *
    ;* [local] *
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    externdef __MIDL_itf_oaidl_0000_0011_v0_0_c_ifspec:RPC_IF_HANDLE
    externdef __MIDL_itf_oaidl_0000_0011_v0_0_s_ifspec:RPC_IF_HANDLE
    ifndef __ITypeLib2_INTERFACE_DEFINED__
      __ITypeLib2_INTERFACE_DEFINED__ equ <>
      ;* interface ITypeLib2 *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPTYPELIB2 typedef ptr ITypeLib2
      externdef IID_ITypeLib2:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ITypeLib2Vtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ITypeLib2Vtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ITypeLib2, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ITypeLib2
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ITypeLib2
          DECLSPEC_XFGVIRT(ITypeLib, GetTypeInfoCount)
          ;* [local] *
          STD_METHOD GetTypeInfoCount, :ptr ITypeLib2
          DECLSPEC_XFGVIRT(ITypeLib, GetTypeInfo)
          ;* [in] *
          STD_METHOD GetTypeInfo, :ptr ITypeLib2, :UINT, :ptr ptr ITypeInfo
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeLib, GetTypeInfoType)
          ;* [in] *
          STD_METHOD GetTypeInfoType, :ptr ITypeLib2, :UINT, :ptr TYPEKIND
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeLib, GetTypeInfoOfGuid)
          ;* [in] *
          STD_METHOD GetTypeInfoOfGuid, :ptr ITypeLib2, :REFGUID, :ptr ptr ITypeInfo
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeLib, GetLibAttr)
          ;* [local] *
          STD_METHOD GetLibAttr, :ptr ITypeLib2, :ptr ptr TLIBATTR
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeLib, GetTypeComp)
          STD_METHOD GetTypeComp, :ptr ITypeLib2, :ptr ptr ITypeComp
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeLib, GetDocumentation)
          ;* [local] *
          ;* [in] *
          ;* [annotation][out] *
          ;* [annotation][out] *
          ;* [out] *
          ;* [annotation][out] *
          STD_METHOD GetDocumentation, :ptr ITypeLib2, :INT_, :ptr BSTR, :ptr BSTR, :ptr DWORD, :ptr BSTR
          DECLSPEC_XFGVIRT(ITypeLib, IsName)
          ;* [local] *
          ;* [annotation][out][in] *
          ;* [in] *
          STD_METHOD IsName, :ptr ITypeLib2, :LPOLESTR, :ULONG, :ptr BOOL
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeLib, FindName)
          ;* [local] *
          ;* [annotation][out][in] *
          ;* [in] *
          ;* [length_is][size_is][out] *
          ;* [length_is][size_is][out] *
          STD_METHOD FindName, :ptr ITypeLib2, :LPOLESTR, :ULONG, :ptr ptr ITypeInfo, :ptr MEMBERID, :ptr USHORT
          ;* [out][in] *
          DECLSPEC_XFGVIRT(ITypeLib, ReleaseTLibAttr)
          ;* [local] *
          STD_METHOD ReleaseTLibAttr, :ptr ITypeLib2, :ptr TLIBATTR
          ;* [in] *
          DECLSPEC_XFGVIRT(ITypeLib2, GetCustData)
          ;* [in] *
          STD_METHOD GetCustData, :ptr ITypeLib2, :REFGUID, :ptr VARIANT
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeLib2, GetLibStatistics)
          ;* [local] *
          ;* [out] *
          STD_METHOD GetLibStatistics, :ptr ITypeLib2, :ptr ULONG, :ptr ULONG
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeLib2, GetDocumentation2)
          ;* [local] *
          ;* [in] *
          ;* [in] *
          ;* [annotation][out] *
          ;* [out] *
          ;* [annotation][out] *
          STD_METHOD GetDocumentation2, :ptr ITypeLib2, :INT_, :LCID, :ptr BSTR, :ptr DWORD, :ptr BSTR
          DECLSPEC_XFGVIRT(ITypeLib2, GetAllCustData)
          STD_METHOD GetAllCustData, :ptr ITypeLib2, :ptr CUSTDATA
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        ITypeLib2Vtbl ends
        ITypeLib2 struct
          lpVtbl POINTER ?
        ITypeLib2 ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      ITypeLib2_RemoteGetLibStatistics_Proxy proto WIN_STD_CALL_CONV :ptr ITypeLib2, :ptr ULONG, :ptr ULONG
      ;* [out] *
      ITypeLib2_RemoteGetLibStatistics_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* [call_as] *
      ITypeLib2_RemoteGetDocumentation2_Proxy proto WIN_STD_CALL_CONV :ptr ITypeLib2, :INT_, :LCID, :DWORD, :ptr BSTR, :ptr DWORD, :ptr BSTR
      ;* [out] *
      ITypeLib2_RemoteGetDocumentation2_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __ITypeLib2_INTERFACE_DEFINED__ *
    endif
    ifndef __ITypeChangeEvents_INTERFACE_DEFINED__
      __ITypeChangeEvents_INTERFACE_DEFINED__ equ <>
      ;* interface ITypeChangeEvents *
      ;* [local][unique][uuid][object] *
      ;* [unique] *
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
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ITypeChangeEvents, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ITypeChangeEvents
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ITypeChangeEvents
          DECLSPEC_XFGVIRT(ITypeChangeEvents, RequestTypeChange)
          ;* [in] *
          ;* [in] *
          ;* [annotation][in] *
          STD_METHOD RequestTypeChange, :ptr ITypeChangeEvents, :CHANGEKIND, :ptr ITypeInfo, :LPOLESTR, :ptr INT_
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeChangeEvents, AfterTypeChange)
          ;* [in] *
          ;* [in] *
          ;* [annotation][in] *
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
        ;* C style interface *
      endif
      ;* __ITypeChangeEvents_INTERFACE_DEFINED__ *
    endif
    ifndef __IErrorInfo_INTERFACE_DEFINED__
      __IErrorInfo_INTERFACE_DEFINED__ equ <>
      ;* interface IErrorInfo *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPERRORINFO typedef ptr IErrorInfo
      externdef IID_IErrorInfo:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IErrorInfoVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IErrorInfoVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IErrorInfo, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IErrorInfo
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IErrorInfo
          DECLSPEC_XFGVIRT(IErrorInfo, GetGUID)
          STD_METHOD GetGUID, :ptr IErrorInfo, :ptr GUID
          ;* [out] *
          DECLSPEC_XFGVIRT(IErrorInfo, GetSource)
          STD_METHOD GetSource, :ptr IErrorInfo, :ptr BSTR
          ;* [out] *
          DECLSPEC_XFGVIRT(IErrorInfo, GetDescription)
          STD_METHOD GetDescription, :ptr IErrorInfo, :ptr BSTR
          ;* [out] *
          DECLSPEC_XFGVIRT(IErrorInfo, GetHelpFile)
          STD_METHOD GetHelpFile, :ptr IErrorInfo, :ptr BSTR
          ;* [out] *
          DECLSPEC_XFGVIRT(IErrorInfo, GetHelpContext)
          STD_METHOD GetHelpContext, :ptr IErrorInfo, :ptr DWORD
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        IErrorInfoVtbl ends
        IErrorInfo struct
          lpVtbl POINTER ?
        IErrorInfo ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IErrorInfo_INTERFACE_DEFINED__ *
    endif
    ifndef __ICreateErrorInfo_INTERFACE_DEFINED__
      __ICreateErrorInfo_INTERFACE_DEFINED__ equ <>
      ;* interface ICreateErrorInfo *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPCREATEERRORINFO typedef ptr ICreateErrorInfo
      externdef IID_ICreateErrorInfo:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ICreateErrorInfoVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ICreateErrorInfoVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ICreateErrorInfo, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ICreateErrorInfo
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ICreateErrorInfo
          DECLSPEC_XFGVIRT(ICreateErrorInfo, SetGUID)
          STD_METHOD SetGUID, :ptr ICreateErrorInfo, :REFGUID
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateErrorInfo, SetSource)
          STD_METHOD SetSource, :ptr ICreateErrorInfo, :LPOLESTR
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateErrorInfo, SetDescription)
          STD_METHOD SetDescription, :ptr ICreateErrorInfo, :LPOLESTR
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateErrorInfo, SetHelpFile)
          STD_METHOD SetHelpFile, :ptr ICreateErrorInfo, :LPOLESTR
          ;* [in] *
          DECLSPEC_XFGVIRT(ICreateErrorInfo, SetHelpContext)
          STD_METHOD SetHelpContext, :ptr ICreateErrorInfo, :DWORD
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        ICreateErrorInfoVtbl ends
        ICreateErrorInfo struct
          lpVtbl POINTER ?
        ICreateErrorInfo ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ICreateErrorInfo_INTERFACE_DEFINED__ *
    endif
    ifndef __ISupportErrorInfo_INTERFACE_DEFINED__
      __ISupportErrorInfo_INTERFACE_DEFINED__ equ <>
      ;* interface ISupportErrorInfo *
      ;* [unique][uuid][object] *
      ;* [unique] *
      LPSUPPORTERRORINFO typedef ptr ISupportErrorInfo
      externdef IID_ISupportErrorInfo:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ISupportErrorInfoVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ISupportErrorInfoVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ISupportErrorInfo, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ISupportErrorInfo
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ISupportErrorInfo
          DECLSPEC_XFGVIRT(ISupportErrorInfo, InterfaceSupportsErrorInfo)
          STD_METHOD InterfaceSupportsErrorInfo, :ptr ISupportErrorInfo, :REFIID
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        ISupportErrorInfoVtbl ends
        ISupportErrorInfo struct
          lpVtbl POINTER ?
        ISupportErrorInfo ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ISupportErrorInfo_INTERFACE_DEFINED__ *
    endif
    ifndef __ITypeFactory_INTERFACE_DEFINED__
      __ITypeFactory_INTERFACE_DEFINED__ equ <>
      ;* interface ITypeFactory *
      ;* [uuid][object] *
      externdef IID_ITypeFactory:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ITypeFactoryVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ITypeFactoryVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ITypeFactory, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ITypeFactory
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ITypeFactory
          DECLSPEC_XFGVIRT(ITypeFactory, CreateFromTypeInfo)
          ;* [in] *
          ;* [in] *
          STD_METHOD CreateFromTypeInfo, :ptr ITypeFactory, :ptr ITypeInfo, :REFIID, :ptr ptr IUnknown
          ;* [iid_is][out] *
          ??Interface equ <>
          END_INTERFACE
        ITypeFactoryVtbl ends
        ITypeFactory struct
          lpVtbl POINTER ?
        ITypeFactory ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ITypeFactory_INTERFACE_DEFINED__ *
    endif
    ifndef __ITypeMarshal_INTERFACE_DEFINED__
      __ITypeMarshal_INTERFACE_DEFINED__ equ <>
      ;* interface ITypeMarshal *
      ;* [uuid][object][local] *
      externdef IID_ITypeMarshal:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ITypeMarshalVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ITypeMarshalVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ITypeMarshal, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ITypeMarshal
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ITypeMarshal
          DECLSPEC_XFGVIRT(ITypeMarshal, Size)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          STD_METHOD Size_, :ptr ITypeMarshal, :PVOID, :DWORD, :PVOID, :ptr ULONG
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeMarshal, Marshal)
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [in] *
          ;* [annotation][out] *
          ;* [annotation][out] *
          STD_METHOD Marshal, :ptr ITypeMarshal, :PVOID, :DWORD, :PVOID, :ULONG, :ptr BYTE, :ptr ULONG
          DECLSPEC_XFGVIRT(ITypeMarshal, Unmarshal)
          ;* [out] *
          ;* [in] *
          ;* [in] *
          ;* [annotation][in] *
          ;* [annotation][out] *
          STD_METHOD Unmarshal, :ptr ITypeMarshal, :PVOID, :DWORD, :ULONG, :ptr BYTE, :ptr ULONG
          DECLSPEC_XFGVIRT(ITypeMarshal, Free)
          STD_METHOD Free, :ptr ITypeMarshal, :PVOID
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        ITypeMarshalVtbl ends
        ITypeMarshal struct
          lpVtbl POINTER ?
        ITypeMarshal ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ITypeMarshal_INTERFACE_DEFINED__ *
    endif
    ifndef __IRecordInfo_INTERFACE_DEFINED__
      __IRecordInfo_INTERFACE_DEFINED__ equ <>
      ;* interface IRecordInfo *
      ;* [uuid][object][local] *
      ;* [unique] *
      LPRECORDINFO typedef ptr IRecordInfo
      externdef IID_IRecordInfo:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IRecordInfoVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IRecordInfoVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IRecordInfo, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IRecordInfo
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IRecordInfo
          DECLSPEC_XFGVIRT(IRecordInfo, RecordInit)
          STD_METHOD RecordInit, :ptr IRecordInfo, :PVOID
          ;* [out] *
          DECLSPEC_XFGVIRT(IRecordInfo, RecordClear)
          STD_METHOD RecordClear, :ptr IRecordInfo, :PVOID
          ;* [in] *
          DECLSPEC_XFGVIRT(IRecordInfo, RecordCopy)
          ;* [in] *
          STD_METHOD RecordCopy, :ptr IRecordInfo, :PVOID, :PVOID
          ;* [out] *
          DECLSPEC_XFGVIRT(IRecordInfo, GetGuid)
          STD_METHOD GetGuid, :ptr IRecordInfo, :ptr GUID
          ;* [out] *
          DECLSPEC_XFGVIRT(IRecordInfo, GetName)
          ;* [annotation][out] *
          STD_METHOD GetName, :ptr IRecordInfo, :ptr BSTR
          DECLSPEC_XFGVIRT(IRecordInfo, GetSize)
          STD_METHOD GetSize, :ptr IRecordInfo, :ptr ULONG
          ;* [out] *
          DECLSPEC_XFGVIRT(IRecordInfo, GetTypeInfo)
          STD_METHOD GetTypeInfo, :ptr IRecordInfo, :ptr ptr ITypeInfo
          ;* [out] *
          DECLSPEC_XFGVIRT(IRecordInfo, GetField)
          ;* [in] *
          ;* [in] *
          STD_METHOD GetField, :ptr IRecordInfo, :PVOID, :LPCOLESTR, :ptr VARIANT
          ;* [out] *
          DECLSPEC_XFGVIRT(IRecordInfo, GetFieldNoCopy)
          ;* [in] *
          ;* [in] *
          ;* [out] *
          STD_METHOD GetFieldNoCopy, :ptr IRecordInfo, :PVOID, :LPCOLESTR, :ptr VARIANT, :ptr PVOID
          ;* [out] *
          DECLSPEC_XFGVIRT(IRecordInfo, PutField)
          ;* [in] *
          ;* [out][in] *
          ;* [in] *
          STD_METHOD PutField, :ptr IRecordInfo, :ULONG, :PVOID, :LPCOLESTR, :ptr VARIANT
          ;* [in] *
          DECLSPEC_XFGVIRT(IRecordInfo, PutFieldNoCopy)
          ;* [in] *
          ;* [out][in] *
          ;* [in] *
          STD_METHOD PutFieldNoCopy, :ptr IRecordInfo, :ULONG, :PVOID, :LPCOLESTR, :ptr VARIANT
          ;* [in] *
          DECLSPEC_XFGVIRT(IRecordInfo, GetFieldNames)
          ;* [out][in] *
          ;* [annotation][length_is][size_is][out] *
          STD_METHOD GetFieldNames, :ptr IRecordInfo, :ptr ULONG, :ptr BSTR
          DECLSPEC_XFGVIRT(IRecordInfo, IsMatchingType)
          STD_METHOD IsMatchingType, :ptr IRecordInfo, :ptr IRecordInfo
          ;* [in] *
          DECLSPEC_XFGVIRT(IRecordInfo, RecordCreate)
          STD_METHOD RecordCreate, :ptr IRecordInfo
          DECLSPEC_XFGVIRT(IRecordInfo, RecordCreateCopy)
          ;* [in] *
          STD_METHOD RecordCreateCopy, :ptr IRecordInfo, :PVOID, :ptr PVOID
          ;* [out] *
          DECLSPEC_XFGVIRT(IRecordInfo, RecordDestroy)
          STD_METHOD RecordDestroy, :ptr IRecordInfo, :PVOID
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IRecordInfoVtbl ends
        IRecordInfo struct
          lpVtbl POINTER ?
        IRecordInfo ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IRecordInfo_INTERFACE_DEFINED__ *
    endif
    ifndef __IErrorLog_INTERFACE_DEFINED__
      __IErrorLog_INTERFACE_DEFINED__ equ <>
      ;* interface IErrorLog *
      ;* [unique][uuid][object] *
      LPERRORLOG typedef ptr IErrorLog
      externdef IID_IErrorLog:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IErrorLogVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IErrorLogVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IErrorLog, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IErrorLog
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IErrorLog
          DECLSPEC_XFGVIRT(IErrorLog, AddError)
          ;* [in] *
          STD_METHOD AddError, :ptr IErrorLog, :LPCOLESTR, :ptr EXCEPINFO
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IErrorLogVtbl ends
        IErrorLog struct
          lpVtbl POINTER ?
        IErrorLog ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __IErrorLog_INTERFACE_DEFINED__ *
    endif
    ifndef __IPropertyBag_INTERFACE_DEFINED__
      __IPropertyBag_INTERFACE_DEFINED__ equ <>
      ;* interface IPropertyBag *
      ;* [unique][uuid][object] *
      LPPROPERTYBAG typedef ptr IPropertyBag
      externdef IID_IPropertyBag:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        IPropertyBagVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <IPropertyBagVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr IPropertyBag, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr IPropertyBag
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr IPropertyBag
          DECLSPEC_XFGVIRT(IPropertyBag, Read)
          ;* [local] *
          ;* [in] *
          ;* [out][in] *
          STD_METHOD Read, :ptr IPropertyBag, :LPCOLESTR, :ptr VARIANT, :ptr IErrorLog
          ;* [unique][in] *
          DECLSPEC_XFGVIRT(IPropertyBag, Write)
          ;* [in] *
          STD_METHOD Write, :ptr IPropertyBag, :LPCOLESTR, :ptr VARIANT
          ;* [in] *
          ??Interface equ <>
          END_INTERFACE
        IPropertyBagVtbl ends
        IPropertyBag struct
          lpVtbl POINTER ?
        IPropertyBag ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* [call_as] *
      IPropertyBag_RemoteRead_Proxy proto WIN_STD_CALL_CONV :ptr IPropertyBag, :LPCOLESTR, :ptr VARIANT, :ptr IErrorLog, :DWORD, :ptr IUnknown
      ;* [in] *
      IPropertyBag_RemoteRead_Stub proto WIN_STD_CALL_CONV :ptr IRpcStubBuffer, :ptr IRpcChannelBuffer, :PRPC_MESSAGE, :ptr DWORD
      ;* __IPropertyBag_INTERFACE_DEFINED__ *
    endif
    ifndef __ITypeLibRegistrationReader_INTERFACE_DEFINED__
      __ITypeLibRegistrationReader_INTERFACE_DEFINED__ equ <>
      ;* interface ITypeLibRegistrationReader *
      ;* [uuid][object][local] *
      externdef IID_ITypeLibRegistrationReader:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ITypeLibRegistrationReaderVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ITypeLibRegistrationReaderVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ITypeLibRegistrationReader, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ITypeLibRegistrationReader
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ITypeLibRegistrationReader
          DECLSPEC_XFGVIRT(ITypeLibRegistrationReader, EnumTypeLibRegistrations)
          STD_METHOD EnumTypeLibRegistrations, :ptr ITypeLibRegistrationReader, :ptr ptr IEnumUnknown
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        ITypeLibRegistrationReaderVtbl ends
        ITypeLibRegistrationReader struct
          lpVtbl POINTER ?
        ITypeLibRegistrationReader ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ITypeLibRegistrationReader_INTERFACE_DEFINED__ *
    endif
    ifndef __ITypeLibRegistration_INTERFACE_DEFINED__
      __ITypeLibRegistration_INTERFACE_DEFINED__ equ <>
      ;* interface ITypeLibRegistration *
      ;* [uuid][object][local] *
      externdef IID_ITypeLibRegistration:IID
      if Defined(__cplusplus) and  not Defined(CINTERFACE)
        ;[...]
      else
        ITypeLibRegistrationVtbl struct
          BEGIN_INTERFACE
          ??Interface equ <ITypeLibRegistrationVtbl>
          DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
          ;* [in] *
          ;* [annotation][iid_is][out] *
          STD_METHOD QueryInterface, :ptr ITypeLibRegistration, :REFIID, :ptr ptr
          DECLSPEC_XFGVIRT(IUnknown, AddRef)
          STD_METHOD AddRef, :ptr ITypeLibRegistration
          DECLSPEC_XFGVIRT(IUnknown, Release)
          STD_METHOD Release, :ptr ITypeLibRegistration
          DECLSPEC_XFGVIRT(ITypeLibRegistration, GetGuid)
          STD_METHOD GetGuid, :ptr ITypeLibRegistration, :ptr GUID
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeLibRegistration, GetVersion)
          STD_METHOD GetVersion, :ptr ITypeLibRegistration, :ptr BSTR
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeLibRegistration, GetLcid)
          STD_METHOD GetLcid, :ptr ITypeLibRegistration, :ptr LCID
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeLibRegistration, GetWin32Path)
          STD_METHOD GetWin32Path, :ptr ITypeLibRegistration, :ptr BSTR
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeLibRegistration, GetWin64Path)
          STD_METHOD GetWin64Path, :ptr ITypeLibRegistration, :ptr BSTR
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeLibRegistration, GetDisplayName)
          STD_METHOD GetDisplayName, :ptr ITypeLibRegistration, :ptr BSTR
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeLibRegistration, GetFlags)
          STD_METHOD GetFlags, :ptr ITypeLibRegistration, :ptr DWORD
          ;* [out] *
          DECLSPEC_XFGVIRT(ITypeLibRegistration, GetHelpDir)
          STD_METHOD GetHelpDir, :ptr ITypeLibRegistration, :ptr BSTR
          ;* [out] *
          ??Interface equ <>
          END_INTERFACE
        ITypeLibRegistrationVtbl ends
        ITypeLibRegistration struct
          lpVtbl POINTER ?
        ITypeLibRegistration ends
        ifdef COBJMACROS
          ;[...]
        endif
        ;* C style interface *
      endif
      ;* __ITypeLibRegistration_INTERFACE_DEFINED__ *
    endif
    ;* interface __MIDL_itf_oaidl_0000_0023 *
    ;* [local] *
    externdef CLSID_TypeLibRegistrationReader:CLSID
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
  endif
  if (_MSC_VER ge 800)
    if _MSC_VER ge 1200
    else
      ;* Nameless struct/union *
    endif
  endif
  externdef __MIDL_itf_oaidl_0000_0023_v0_0_c_ifspec:RPC_IF_HANDLE
  externdef __MIDL_itf_oaidl_0000_0023_v0_0_s_ifspec:RPC_IF_HANDLE
  ;* Additional Prototypes for ALL interfaces *
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
  ;* [local] *
  IDispatch_Invoke_Proxy proto WIN_STD_CALL_CONV :ptr IDispatch, :DISPID, :REFIID, :LCID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
  ;* [annotation][out] *
  ;* [call_as] *
  IDispatch_Invoke_Stub proto WIN_STD_CALL_CONV :ptr IDispatch, :DISPID, :REFIID, :LCID, :DWORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT, :UINT, :ptr UINT, :ptr VARIANTARG
  ;* [size_is][out][in] *
  ;* [local] *
  IEnumVARIANT_Next_Proxy proto WIN_STD_CALL_CONV :ptr IEnumVARIANT, :ULONG, :ptr VARIANT, :ptr ULONG
  ;* [out] *
  ;* [call_as] *
  IEnumVARIANT_Next_Stub proto WIN_STD_CALL_CONV :ptr IEnumVARIANT, :ULONG, :ptr VARIANT, :ptr ULONG
  ;* [out] *
  ;* [local] *
  ITypeComp_Bind_Proxy proto WIN_STD_CALL_CONV :ptr ITypeComp, :LPOLESTR, :ULONG, :WORD, :ptr ptr ITypeInfo, :ptr DESCKIND, :ptr BINDPTR
  ;* [out] *
  ;* [call_as] *
  ITypeComp_Bind_Stub proto WIN_STD_CALL_CONV :ptr ITypeComp, :LPOLESTR, :ULONG, :WORD, :ptr ptr ITypeInfo, :ptr DESCKIND, :ptr LPFUNCDESC, :ptr LPVARDESC, :ptr ptr ITypeComp, :ptr CLEANLOCALSTORAGE
  ;* [out] *
  ;* [local] *
  ITypeComp_BindType_Proxy proto WIN_STD_CALL_CONV :ptr ITypeComp, :LPOLESTR, :ULONG, :ptr ptr ITypeInfo, :ptr ptr ITypeComp
  ;* [out] *
  ;* [call_as] *
  ITypeComp_BindType_Stub proto WIN_STD_CALL_CONV :ptr ITypeComp, :LPOLESTR, :ULONG, :ptr ptr ITypeInfo
  ;* [out] *
  ;* [local] *
  ITypeInfo_GetTypeAttr_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :ptr ptr TYPEATTR
  ;* [out] *
  ;* [call_as] *
  ITypeInfo_GetTypeAttr_Stub proto WIN_STD_CALL_CONV :ptr ITypeInfo, :ptr LPTYPEATTR, :ptr CLEANLOCALSTORAGE
  ;* [out] *
  ;* [local] *
  ITypeInfo_GetFuncDesc_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :UINT, :ptr ptr FUNCDESC
  ;* [out] *
  ;* [call_as] *
  ITypeInfo_GetFuncDesc_Stub proto WIN_STD_CALL_CONV :ptr ITypeInfo, :UINT, :ptr LPFUNCDESC, :ptr CLEANLOCALSTORAGE
  ;* [out] *
  ;* [local] *
  ITypeInfo_GetVarDesc_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :UINT, :ptr ptr VARDESC
  ;* [out] *
  ;* [call_as] *
  ITypeInfo_GetVarDesc_Stub proto WIN_STD_CALL_CONV :ptr ITypeInfo, :UINT, :ptr LPVARDESC, :ptr CLEANLOCALSTORAGE
  ;* [out] *
  ;* [local] *
  ITypeInfo_GetNames_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :MEMBERID, :ptr BSTR, :UINT, :ptr UINT
  ;* [annotation][out] *
  ;* [call_as] *
  ITypeInfo_GetNames_Stub proto WIN_STD_CALL_CONV :ptr ITypeInfo, :MEMBERID, :ptr BSTR, :UINT, :ptr UINT
  ;* [out] *
  ;* [local] *
  ITypeInfo_GetIDsOfNames_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :ptr LPOLESTR, :UINT, :ptr MEMBERID
  ;* [size_is][out] *
  ;* [nocode][call_as] *
  ITypeInfo_GetIDsOfNames_Stub proto WIN_STD_CALL_CONV :ptr ITypeInfo
  ;* [local] *
  ITypeInfo_Invoke_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :PVOID, :MEMBERID, :WORD, :ptr DISPPARAMS, :ptr VARIANT, :ptr EXCEPINFO, :ptr UINT
  ;* [out] *
  ;* [nocode][call_as] *
  ITypeInfo_Invoke_Stub proto WIN_STD_CALL_CONV :ptr ITypeInfo
  ;* [local] *
  ITypeInfo_GetDocumentation_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :MEMBERID, :ptr BSTR, :ptr BSTR, :ptr DWORD, :ptr BSTR
  ;* [annotation][out] *
  ;* [call_as] *
  ITypeInfo_GetDocumentation_Stub proto WIN_STD_CALL_CONV :ptr ITypeInfo, :MEMBERID, :DWORD, :ptr BSTR, :ptr BSTR, :ptr DWORD, :ptr BSTR
  ;* [out] *
  ;* [local] *
  ITypeInfo_GetDllEntry_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :MEMBERID, :INVOKEKIND, :ptr BSTR, :ptr BSTR, :ptr WORD
  ;* [out] *
  ;* [call_as] *
  ITypeInfo_GetDllEntry_Stub proto WIN_STD_CALL_CONV :ptr ITypeInfo, :MEMBERID, :INVOKEKIND, :DWORD, :ptr BSTR, :ptr BSTR, :ptr WORD
  ;* [out] *
  ;* [local] *
  ITypeInfo_AddressOfMember_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :MEMBERID, :INVOKEKIND, :ptr PVOID
  ;* [out] *
  ;* [nocode][call_as] *
  ITypeInfo_AddressOfMember_Stub proto WIN_STD_CALL_CONV :ptr ITypeInfo
  ;* [local] *
  ITypeInfo_CreateInstance_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :ptr IUnknown, :REFIID, :ptr PVOID
  ;* [iid_is][out] *
  ;* [call_as] *
  ITypeInfo_CreateInstance_Stub proto WIN_STD_CALL_CONV :ptr ITypeInfo, :REFIID, :ptr ptr IUnknown
  ;* [iid_is][out] *
  ;* [local] *
  ITypeInfo_GetContainingTypeLib_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :ptr ptr ITypeLib, :ptr UINT
  ;* [out] *
  ;* [call_as] *
  ITypeInfo_GetContainingTypeLib_Stub proto WIN_STD_CALL_CONV :ptr ITypeInfo, :ptr ptr ITypeLib, :ptr UINT
  ;* [out] *
  ;* [local] *
  ITypeInfo_ReleaseTypeAttr_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :ptr TYPEATTR
  ;* [in] *
  ;* [nocode][call_as] *
  ITypeInfo_ReleaseTypeAttr_Stub proto WIN_STD_CALL_CONV :ptr ITypeInfo
  ;* [local] *
  ITypeInfo_ReleaseFuncDesc_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :ptr FUNCDESC
  ;* [in] *
  ;* [nocode][call_as] *
  ITypeInfo_ReleaseFuncDesc_Stub proto WIN_STD_CALL_CONV :ptr ITypeInfo
  ;* [local] *
  ITypeInfo_ReleaseVarDesc_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo, :ptr VARDESC
  ;* [in] *
  ;* [nocode][call_as] *
  ITypeInfo_ReleaseVarDesc_Stub proto WIN_STD_CALL_CONV :ptr ITypeInfo
  ;* [local] *
  ITypeInfo2_GetDocumentation2_Proxy proto WIN_STD_CALL_CONV :ptr ITypeInfo2, :MEMBERID, :LCID, :ptr BSTR, :ptr DWORD, :ptr BSTR
  ;* [annotation][out] *
  ;* [call_as] *
  ITypeInfo2_GetDocumentation2_Stub proto WIN_STD_CALL_CONV :ptr ITypeInfo2, :MEMBERID, :LCID, :DWORD, :ptr BSTR, :ptr DWORD, :ptr BSTR
  ;* [out] *
  ;* [local] *
  ITypeLib_GetTypeInfoCount_Proxy proto WIN_STD_CALL_CONV :ptr ITypeLib
  ;* [call_as] *
  ITypeLib_GetTypeInfoCount_Stub proto WIN_STD_CALL_CONV :ptr ITypeLib, :ptr UINT
  ;* [out] *
  ;* [local] *
  ITypeLib_GetLibAttr_Proxy proto WIN_STD_CALL_CONV :ptr ITypeLib, :ptr ptr TLIBATTR
  ;* [out] *
  ;* [call_as] *
  ITypeLib_GetLibAttr_Stub proto WIN_STD_CALL_CONV :ptr ITypeLib, :ptr LPTLIBATTR, :ptr CLEANLOCALSTORAGE
  ;* [out] *
  ;* [local] *
  ITypeLib_GetDocumentation_Proxy proto WIN_STD_CALL_CONV :ptr ITypeLib, :INT_, :ptr BSTR, :ptr BSTR, :ptr DWORD, :ptr BSTR
  ;* [annotation][out] *
  ;* [call_as] *
  ITypeLib_GetDocumentation_Stub proto WIN_STD_CALL_CONV :ptr ITypeLib, :INT_, :DWORD, :ptr BSTR, :ptr BSTR, :ptr DWORD, :ptr BSTR
  ;* [out] *
  ;* [local] *
  ITypeLib_IsName_Proxy proto WIN_STD_CALL_CONV :ptr ITypeLib, :LPOLESTR, :ULONG, :ptr BOOL
  ;* [out] *
  ;* [call_as] *
  ITypeLib_IsName_Stub proto WIN_STD_CALL_CONV :ptr ITypeLib, :LPOLESTR, :ULONG, :ptr BOOL, :ptr BSTR
  ;* [out] *
  ;* [local] *
  ITypeLib_FindName_Proxy proto WIN_STD_CALL_CONV :ptr ITypeLib, :LPOLESTR, :ULONG, :ptr ptr ITypeInfo, :ptr MEMBERID, :ptr USHORT
  ;* [out][in] *
  ;* [call_as] *
  ITypeLib_FindName_Stub proto WIN_STD_CALL_CONV :ptr ITypeLib, :LPOLESTR, :ULONG, :ptr ptr ITypeInfo, :ptr MEMBERID, :ptr USHORT, :ptr BSTR
  ;* [out] *
  ;* [local] *
  ITypeLib_ReleaseTLibAttr_Proxy proto WIN_STD_CALL_CONV :ptr ITypeLib, :ptr TLIBATTR
  ;* [in] *
  ;* [nocode][call_as] *
  ITypeLib_ReleaseTLibAttr_Stub proto WIN_STD_CALL_CONV :ptr ITypeLib
  ;* [local] *
  ITypeLib2_GetLibStatistics_Proxy proto WIN_STD_CALL_CONV :ptr ITypeLib2, :ptr ULONG, :ptr ULONG
  ;* [out] *
  ;* [call_as] *
  ITypeLib2_GetLibStatistics_Stub proto WIN_STD_CALL_CONV :ptr ITypeLib2, :ptr ULONG, :ptr ULONG
  ;* [out] *
  ;* [local] *
  ITypeLib2_GetDocumentation2_Proxy proto WIN_STD_CALL_CONV :ptr ITypeLib2, :INT_, :LCID, :ptr BSTR, :ptr DWORD, :ptr BSTR
  ;* [annotation][out] *
  ;* [call_as] *
  ITypeLib2_GetDocumentation2_Stub proto WIN_STD_CALL_CONV :ptr ITypeLib2, :INT_, :LCID, :DWORD, :ptr BSTR, :ptr DWORD, :ptr BSTR
  ;* [out] *
  ;* [local] *
  IPropertyBag_Read_Proxy proto WIN_STD_CALL_CONV :ptr IPropertyBag, :LPCOLESTR, :ptr VARIANT, :ptr IErrorLog
  ;* [unique][in] *
  ;* [call_as] *
  IPropertyBag_Read_Stub proto WIN_STD_CALL_CONV :ptr IPropertyBag, :LPCOLESTR, :ptr VARIANT, :ptr IErrorLog, :DWORD, :ptr IUnknown
  ;* [in] *
  ;* end of Additional Prototypes *
  ifdef __cplusplus
    ;[...]
  endif
endif
