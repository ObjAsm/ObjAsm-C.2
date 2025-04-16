; ==================================================================================================
; Title:      OAIDL.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of Automation Interface Definition Language.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


BSTR            typedef ptr WORD
VARTYPE         typedef WORD
LCID            typedef DWORD
HREFTYPE        typedef DWORD
DISPID          typedef SDWORD
MEMBERID        typedef SDWORD
LPDISPID        typedef ptr DISPID
PVOID           typedef ptr               ;Defined in Windows.inc (Version 1.25e) of MASM32 V8
LPWSTR          typedef ptr WORD          ;Defined in Windows.inc (Version 1.25e) of MASM32 V8

DISPID_UNKNOWN  equ -1
MEMBERID_NIL    equ DISPID_UNKNOWN


; --------------------------------------------------------------------------------------------------
;  IDispatch Data Types

;IMPLTYPEFLAG_FDEFAULT       equ    1H
;IMPLTYPEFLAG_FSOURCE        equ    2H
;IMPLTYPEFLAG_FRESTRICTED    equ    4H
;IMPLTYPEFLAG_FDEFAULTVTABLE equ    8H
;
;CHANGEKIND_ADDMEMBER        equ    0H
;CHANGEKIND_DELETEMEMBER     equ    1H
;CHANGEKIND_SETNAMES         equ    2H
;CHANGEKIND_SETDOCUMENTATION equ    3H
;CHANGEKIND_GENERAL          equ    4H
;CHANGEKIND_INVALIDATE       equ    5H
;CHANGEKIND_CHANGEFAILED     equ    6H
;CHANGEKIND_MAX              equ    7H
;
; --------------------------------------------------------------------------------------------------

;CC_FASTCALL                 equ    0H
;CC_CDECL                    equ    1H
;CC_MSCPASCAL                equ    2H
;CC_PASCAL                   equ    2H
;CC_MACPASCAL                equ    3H
;CC_STDCALL                  equ    4H
;CC_FPFASTCALL               equ    5H
;CC_SYSCALL                  equ    6H
;CC_MPWCDECL                 equ    7H
;CC_MPWPASCAL                equ    8H
;CC_MAX                      equ    9H

; --------------------------------------------------------------------------------------------------

;DECIMAL struc
;  Union
;    struc
;      scale   BYTE    ?
;      sign    BYTE    ?
;    ends
;    signscale WORD    ?
;  ends
;  Hi32        DWORD   ?
;  Union
;    struc
;      Lo32    DWORD   ?
;      Mid32   DWORD   ?
;    ends
;    Lo64      REAL8   ?
;  ends
;DECIMAL ends
;LPDECIMAL typedef ptr DECIMAL

; --------------------------------------------------------------------------------------------------

;SAFEARRAYBOUND struc DWORD
;  cElements   DWORD     ?
;  lLbound     SDWORD    ?
;SAFEARRAYBOUND ends
;LPSAFEARRAYBOUND typedef ptr SAFEARRAYBOUND

;SAFEARRAY struc DWORD
;  cDims         WORD    ?  ;Count of dimensions in this array.
;  fFeatures     WORD    ?  ;Flags used by the SafeArray
;  cbElements    DWORD   ?  ;Size of an element of the array. Doesn't include size of pointed-to data
;  cLocks        DWORD   ?  ;Number of times the array has been locked without corresponding unlock.
;  pvData        POINTER ?
;; rgsabound    SAFEARRAYBOUND  <>, <>, ...    One bound for each dimension.
;SAFEARRAY ends
;LPSAFEARRAY typedef ptr SAFEARRAY

; --------------------------------------------------------------------------------------------------

;VARIANT  struct
;  union
;    struct
;      vt            VARTYPE        ?
;      wReserved1    WORD           ?
;      wReserved2    WORD           ?
;      wReserved3    WORD           ?
;      union
;        llVal       QWORD          ?            
;        lVal        DWORD          ?                
;        bVal        BYTE           ?                
;        iVal        SWORD          ?               
;        fltVal      REAL4          ?               
;        dblVal      REAL8          ?              
;        boolVal     VARIANT_BOOL   ?
;        bool        _VARIANT_BOOL  ?
;        scode       SCODE          ?
;        cyVal       CY             {}
;        date        DATE           ?
;        bstrVal     BSTR           ?
;        punkVal     POINTER        ?            
;        pdispVal    POINTER        ?           
;        parray      POINTER        ?           
;        pbVal       POINTER        ?                
;        piVal       POINTER        ?               
;        plVal       POINTER        ?                
;        pllVal      POINTER        ?            
;        pfltVal     POINTER        ?               
;        pdblVal     POINTER        ?              
;        pboolVal    POINTER        ?        
;        pbool       POINTER        ?       
;        pscode      POINTER        ?               
;        pcyVal      POINTER        ?                  
;        pdate       POINTER        ?                
;        pbstrVal    POINTER        ?                
;        ppunkVal    POINTER        ?            
;        ppdispVal   POINTER        ?           
;        pparray     POINTER        ?           
;        pvarVal     POINTER        ?             
;        byref       POINTER        ?               
;        cVal        POINTER        ?                
;        uiVal       POINTER        ?              
;        ulVal       POINTER        ?               
;        ullVal      POINTER        ?           
;        intVal      POINTER        ?                 
;        uintVal     POINTER        ?                
;        pdecVal     POINTER        ?             
;        pcVal       POINTER        ?                
;        puiVal      POINTER        ?              
;        pulVal      POINTER        ?               
;        pullVal     POINTER        ?           
;        pintVal     POINTER        ?                 
;        puintVal    POINTER        ?                
;        struct
;          pvRecord  PVOID          ?
;          pRecInfo  POINTER        ?
;        ends
;      ends
;    ends
;    decVal          DECIMAL        <>
;  ends
;VARIANT  ends
;LPVARIANT typedef ptr VARIANT

; --------------------------------------------------------------------------------------------------

LPTYPEDESC  typedef ptr TYPEDESC
LPARRAYDESC typedef ptr ARRAYDESC

;TYPEDESC struc
;  union
;    lptdesc   LPTYPEDESC  ?
;    lpadesc   LPARRAYDESC ?
;    hreftype  HREFTYPE    ?
;  ends
;  vt VARTYPE              ?
;TYPEDESC ends
;LPTYPEDESC typedef ptr TYPEDESC

; --------------------------------------------------------------------------------------------------

;ARRAYDESC struc
;  tdescElem   TYPEDESC  <>
;  cDims       WORD      ?
;  rgbounds    SAFEARRAYBOUND  1 dup (<>)
;ARRAYDESC ends
;LPARRAYDESC typedef ptr ARRAYDESC
;
; --------------------------------------------------------------------------------------------------

;CUSTDATAITEM struc
;  guid          GUID      <>
;  varValue      VARIANT   <>
;CUSTDATAITEM ends
;LPCUSTDATAITEM typedef ptr CUSTDATAITEM

; --------------------------------------------------------------------------------------------------

;CUSTDATA struc
;  cCustData   DWORD           ?
;  prgCustData LPCUSTDATAITEM  ?
;CUSTDATA ends
;LPCUSTDATA typedef ptr CUSTDATA

; --------------------------------------------------------------------------------------------------

;PARAMDESCEX struc DWORD
;  cBytes          DWORD    ?
;  varDefaultValue VARIANT  <>
;PARAMDESCEX ends
;LPPARAMDESCEX typedef ptr PARAMDESCEX

; --------------------------------------------------------------------------------------------------

;PARAMDESC struc
;  pparamdescex    LPPARAMDESCEX ?
;  wParamFlags     WORD          ?
;PARAMDESC ends
;LPPARAMDESC typedef ptr PARAMDESC

PARAMFLAG_NONE              equ     00h
PARAMFLAG_FIN               equ     01h
PARAMFLAG_FOUT              equ     02h
PARAMFLAG_FLCID             equ     04h
PARAMFLAG_FRETVAL           equ     08h
PARAMFLAG_FOPT              equ     10h
PARAMFLAG_FHASDEFAULT       equ     20h
PARAMFLAG_FHASCUSTDATA      equ     40h

; --------------------------------------------------------------------------------------------------

;IDLDESC struc
;  dwReserved  DWORD   ?
;  wIDLFlags   WORD    ?
;IDLDESC ends
;LPIDLDESC typedef ptr IDLDESC

IDLFLAG_NONE                equ     PARAMFLAG_NONE
IDLFLAG_FIN                 equ     PARAMFLAG_FIN
IDLFLAG_FOUT                equ     PARAMFLAG_FOUT
IDLFLAG_FLCID               equ     PARAMFLAG_FLCID
IDLFLAG_FRETVAL             equ     PARAMFLAG_FRETVAL

; --------------------------------------------------------------------------------------------------

;ELEMDESC struc
;  tdesc         TYPEDESC    <>
;  union
;    idldesc     IDLDESC     <>
;    paramdesc   PARAMDESC   <>
;  ends
;ELEMDESC ends
;LPELEMDESC typedef ptr ELEMDESC

; --------------------------------------------------------------------------------------------------

;; *** FUNCKIND enum
;FUNC_VIRTUAL                equ     0h
;FUNC_PUREVIRTUAL            equ     1h
;FUNC_NONVIRTUAL             equ     2h
;FUNC_STATIC                 equ     3h
;FUNC_DISPATCH               equ     4h
;
;; *** INVOKEKIND enum
;INVOKE_FUNC                 equ     1h
;INVOKE_PROPERTYGET          equ     2h
;INVOKE_PROPERTYPUT          equ     4h
;INVOKE_PROPERTYPUTREF       equ     8h


; *** CALLCONV enum
;CC_FASTCALL                 equ     0h
;CC_CDECL                    equ     1h
;CC_MSCPASCAL                equ     2h
;CC_PASCAL                   equ     2h
;CC_MACPASCAL                equ     3h
;CC_STDCALL                  equ     4h
;CC_FPFASTCALL               equ     5h
;CC_SYSCALL                  equ     6h
;CC_MPWCDECL                 equ     7h
;CC_MPWPASCAL                equ     8h
;CC_MAX                      equ     9h

; *** FUNCFLAGS flags
FUNCFLAG_FRESTRICTED        equ     01h
FUNCFLAG_FSOURCE            equ     02h
FUNCFLAG_FBINDABLE          equ     04h
FUNCFLAG_FREQUESTEDIT       equ     08h
FUNCFLAG_FDISPLAYBIND       equ     010h
FUNCFLAG_FDEFAULTBIND       equ     020h
FUNCFLAG_FHIDDEN            equ     040h
FUNCFLAG_FUSESGETLASTERROR  equ     080h
FUNCFLAG_FDEFAULTCOLLELEM   equ     0100h
FUNCFLAG_FUIDEFAULT         equ     0200h
FUNCFLAG_FNONBROWSABLE      equ     0400h
FUNCFLAG_FREPLACEABLE       equ     0800h
FUNCFLAG_FIMMEDIATEBIND     equ     01000h

;FUNCDESC struc
;  memid               DWORD       ?
;  lprgscode           DWORD       ?
;  lprgelemdescParam   LPELEMDESC  ?
;  funckind            FUNCKIND    ?
;  invkind             INVOKEKIND  ?
;  callconv            CALLCONV    ?
;  cParams             WORD        ?
;  cParamsOpt          WORD        ?
;  oVft                WORD        ?
;  cScodes             WORD        ?
;  elemdescFunc        ELEMDESC    <>
;  wFuncFlags          WORD        ?
;FUNCDESC ends
;LPFUNCDESC typedef ptr FUNCDESC

; --------------------------------------------------------------------------------------------------

; *** VARKIND enum
VAR_PERINSTANCE             equ     0h
VAR_STATIC                  equ     1h
VAR_CONST                   equ     2h
VAR_DISPATCH                equ     3h

; *** VARFLAGS flags
VARFLAG_FREADONLY           equ     01h
VARFLAG_FSOURCE             equ     02h
VARFLAG_FBINDABLE           equ     04h
VARFLAG_FREQUESTEDIT        equ     08h
VARFLAG_FDISPLAYBIND        equ     010h
VARFLAG_FDEFAULTBIND        equ     020h
VARFLAG_FHIDDEN             equ     040h
VARFLAG_FRESTRICTED         equ     080h
VARFLAG_FDEFAULTCOLLELEM    equ     0100h
VARFLAG_FUIDEFAULT          equ     0200h
VARFLAG_FNONBROWSABLE       equ     0400h
VARFLAG_FREPLACEABLE        equ     0800h
VARFLAG_FIMMEDIATEBIND      equ     01000h

;VARDESC struc
;  memid       DWORD         ?
;  lpstrSchema PVOID         ?
;  union
;    oInst       DWORD       ?
;    lpvarValue  LPVARIANT   ?
;  ends
;  elemdescVar ELEMDESC      <>
;  wVarFlags   WORD          ?
;              WORD          ?       ; align to DWORD
;  varkind     VARKIND       ?
;VARDESC ends
;LPVARDESC typedef ptr VARDESC

; --------------------------------------------------------------------------------------------------

LIBFLAG_FRESTRICTED         equ     1h
LIBFLAG_FCONTROL            equ     2h
LIBFLAG_FHIDDEN             equ     4h
LIBFLAG_FHASDISKIMAGE       equ     8h
;LIBFLAGS typedef SWORD

; --------------------------------------------------------------------------------------------------

SYS_WIN16                   equ     0h
SYS_WIN32                   equ     1h
SYS_MAC                     equ     2h
;SYSKIND typedef DWORD

; --------------------------------------------------------------------------------------------------

;TLIBATTR struc
;  guid          GUID        <>
;  lcid          DWORD       ?
;  syskind       SYSKIND     ?
;  wMajorVerNum  WORD        ?
;  wMinorVerNum  WORD        ?
;  wibFlags      WORD        ?
;TLIBATTR ends
;LPTLIBATTR typedef ptr TLIBATTR

; --------------------------------------------------------------------------------------------------

TKIND_ENUM                  equ     0
TKIND_RECORD                equ     1
TKIND_MODULE                equ     2
TKIND_INTERFACE             equ     3
TKIND_DISPATCH              equ     4
TKIND_COCLASS               equ     5
TKIND_ALIAS                 equ     6
TKIND_UNION                 equ     7
TKIND_MAX                   equ     8

TYPEFLAG_FAPPOBJECT         equ     0001h
TYPEFLAG_FCANCREATE         equ     0002h
TYPEFLAG_FLICENSED          equ     0004h
TYPEFLAG_FPREDECLID         equ     0008h
TYPEFLAG_FHIDDEN            equ     0010h
TYPEFLAG_FCONTROL           equ     0020h
TYPEFLAG_FDUAL              equ     0040h
TYPEFLAG_FNONEXTENSIBLE     equ     0080h
TYPEFLAG_FOLEAUTOMATION     equ     0100h
TYPEFLAG_FRESTRICTED        equ     0200h
TYPEFLAG_FAGGREGATABLE      equ     0400h
TYPEFLAG_FREPLACEABLE       equ     0800h
TYPEFLAG_FDISPATCHABLE      equ     1000h
TYPEFLAG_FREVERSEBIND       equ     2000h

;TYPEATTR struc
;  guid              GUID      <>
;  lcid              LCID      ?
;  dwReserved        DWORD     ?
;  memidConstructor  MEMBERID  ?
;  memidDestructor   MEMBERID  ?
;  lpstrSchema       PVOID     ?
;  cbSizeInstance    DWORD     ?
;  typekind          TYPEKIND  ?
;  cFuncs            WORD      ?
;  cVars             WORD      ?
;  cImplTypes        WORD      ?
;  cbSizeVft         WORD      ?
;  cbAlignment       WORD      ?
;  wTypeFlags        WORD      ?
;  wMajorVerNum      WORD      ?
;  wMinorVerNum      WORD      ?
;  tdescAlias        TYPEDESC  <>
;  idldescType       IDLDESC   <>
;TYPEATTR ends
;LPTYPEATTR typedef ptr TYPEATTR

; --------------------------------------------------------------------------------------------------

;DISPPARAMS struc
;  rgvarg            LPVARIANT ?
;  rgdispidNamedArgs LPDISPID  ?
;  cArgs             DWORD     ?
;  cNamedArgs        DWORD     ?
;DISPPARAMS ends
;ptr DISPPARAMS typedef ptr DISPPARAMS

; --------------------------------------------------------------------------------------------------

EXCEPINFO_fnDeferredFillInProto typedef proto stdcall :ptr EXCEPINFO
EXCEPINFO_fnDeferredFillIn      typedef ptr EXCEPINFO_fnDeferredFillInProto

;EXCEPINFO struc
;  wCode             WORD      ?
;  wReserved         WORD      ?
;  bstrSource        BSTR      ?
;  bstrDescription   BSTR      ?
;  bstrHelpFile      BSTR      ?
;  dwHelpContext     DWORD     ?
;  pvReserved        DWORD     ?
;  pfnDeferredFillIn EXCEPINFO_fnDeferredFillIn  ?
;  scode             DWORD     ?
;EXCEPINFO ends
;LPEXCEPINFO typedef ptr EXCEPINFO

; --------------------------------------------------------------------------------------------------

;PARAMDATA struc
;  szName      PVOID           ?
;  vt          VARTYPE         ?
;PARAMDATA ends
;LPPARAMDATA typedef ptr PARAMDATA

; --------------------------------------------------------------------------------------------------

;METHODDATA struc
;    szName    PVOID           ?
;    ppdata    PVOID           ?
;    dispid    DWORD           ?
;    iMeth     WORD            ?
;    cc        SWORD           ?
;    cArgs     WORD            ?
;    wFlags    DWORD           ?
;    vtReturn  VARTYPE         ?
;METHODDATA ends
;LPMETHODDATA typedef ptr METHODDATA

; --------------------------------------------------------------------------------------------------

;INTERFACEDATA struc
;    pmethdata  LPMETHODDATA   ?
;    cMembers   WORD           ?
;INTERFACEDATA ends
;LPintERFACEDATA typedef ptr INTERFACEDATA

; --------------------------------------------------------------------------------------------------
;  ITypeComp Data Types

DESCKIND_NONE               equ     0h
DESCKIND_FUNCDESC           equ     1h
DESCKIND_VARDESC            equ     2h
DESCKIND_TYPECOMP           equ     3h
DESCKIND_IMPLICITAPPOBJ     equ     4h
DESCKIND_MAX                equ     5h
;DESCKIND typedef SDWORD

; --------------------------------------------------------------------------------------------------

;BINDPTR union
;  lpfuncdesc      PVOID       ?
;  lpvardesc       PVOID       ?
;  lptcomp         PVOID       ?
;BINDPTR ends
;LPBINDPTR typedef ptr BINDPTR

; --------------------------------------------------------------------------------------------------

REGKIND_DEFAULT             equ     0h
REGKIND_REGISTER            equ     1h
REGKIND_NONE                equ     2h
;REGKIND typedef DWORD

DISPATCH_METHOD             equ     1
DISPATCH_PROPERTYGET        equ     2
DISPATCH_PROPERTYPUT        equ     4
DISPATCH_PROPERTYPUTREF     equ     8

IMPLTYPEFLAG_FDEFAULT       equ     1
IMPLTYPEFLAG_FSOURCE        equ     2
IMPLTYPEFLAG_FRESTRICTED    equ     4
IMPLTYPEFLAG_FDEFAULTVTABLE equ     8

DISPID_VALUE                equ     0
DISPID_UNKNOWN              equ    -1
DISPID_PROPERTYPUT          equ    -3
DISPID_NEWENUM              equ    -4
DISPID_EVALUATE             equ    -5

; VTS_xx definitions
VTS_I2              equ    02h          ;'short'
VTS_I4              equ    03h          ;'long'
VTS_R4              equ    04h          ;'float'
VTS_R8              equ    05h          ;'double'
VTS_CY              equ    06h          ;'CY' or 'CY*' ???
VTS_DATE            equ    07h          ;'DATE' (QWORD)
VTS_WBSTR           equ    08h          ;'LPCOLESTR'
VTS_DISPATCH        equ    09h          ;'IDispatch*'
VTS_SCODE           equ    0Ah          ;'SCODE'
VTS_BOOL            equ    0Bh          ;'BOOL'
VTS_VARIANT         equ    0Ch          ;'const VARIANT&' or 'VARIANT*'
VTS_UNKNOWN         equ    0Dh          ;'IUnknown*'
VTS_BSTR            equ    0Eh          ;'LPCSTR'
VTS_UI1             equ    0Fh          ;'BYTE'

VTS_PI2             equ    42h          ;'short*'
VTS_PI4             equ    43h          ;'long*'
VTS_PR4             equ    44h          ;'float*'
VTS_PR8             equ    45h          ;'double*'
VTS_PCY             equ    46h          ;'CY*'
VTS_PDATE           equ    47h          ;'DATE*'
VTS_PBSTR           equ    48h          ;'BSTR*'
VTS_PDISPATCH       equ    49h          ;'IDispatch**'
VTS_PSCODE          equ    4Ah          ;'SCODE*'
VTS_PBOOL           equ    4Bh          ;'VARIANT_BOOL*'
VTS_PVARIANT        equ    4Ch          ;'VARIANT*'
VTS_PUNKNOWN        equ    4Dh          ;'IUnknown**'
VTS_PUI1            equ    4Fh          ;'BYTE*'

VTS_NONE            equ    00h          ;used for members with 0 params

; --------------------------------------------------------------------------------------------------
; Macro:     TypeMissing
; Purpose:   Set a varint to the missing state. Frequently used for optional parameters.
; Arguments: Arg1: Varint variables.

TypeMissing macro Variants:vararg
    local Variant

    for Variant, <Variants>
      mov Variant.vt, VT_ERROR
      mov Variant.scode, DISP_E_PARAMNOTFOUND
    endm
endm
