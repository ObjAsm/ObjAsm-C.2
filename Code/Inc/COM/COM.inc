; ==================================================================================================
; Title:      COM.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm COM helper macros.
; Links:      http://www.microsoft.com/com/default.mspx
; Notes:      Version C.1.0, October 2017
;              - First release.
; ==================================================================================================


; ==================================================================================================
;    Macro definitions
; ==================================================================================================

OLE_COLOR   typedef  DWORD

COM_SERVER_INFO struc
  pNextServerInfo   POINTER    ?          ;-> next COM_SERVER_INFO structure
  pTemplate         POINTER    ?          ;-> Object template, ie.: offset @MyContainer
  pTypeLibGUID      REFGUID    ?          ;-> TypeLib GUID
  wMajorVersion     WORD       ?          ;Major version
  wMinorVersion     WORD       ?          ;Minor version
  pProgID           PSTRING    ?          ;-> Program ID string, ie.: "MyComServer"
  pDescription      PSTRING    ?          ;-> Server description string, ie.: "ObjAsm COM Server"
  pVerbMap          POINTER    ?          ;-> supported Verbs
  dFlags            DWORD      ?          ;-> Flags while Register
COM_SERVER_INFO ends
PCOM_SERVER_INFO typedef ptr COM_SERVER_INFO

TYPELIB_INFO struc
  pNextTypeLibInfo  POINTER    ?          ;-> next TYPELIB_INFO structure
  dResID            DWORD      ?          ;Ressource ID
  pTypeLibGUID      REFGUID    ?          ;-> TypeLib GUID
  wMajorVersion     WORD       ?          ;Major version
  wMinorVersion     WORD       ?          ;Minor version
TYPELIB_INFO ends
PTYPELIB_INFO typedef ptr TYPELIB_INFO

COINIT_MULTITHREADED                  equ   00h
COINIT_APARTMENTTHREADED              equ   02h
COINIT_DISABLE_OLE1DDE                equ   04h
COINIT_SPEED_OVER_MEMORY              equ   08h

FACILITY_CONTROL                      equ   0Ah

ADVF_NODATA                           equ   1t
ADVF_PRIMEFIRST                       equ   2t
ADVF_ONLYONCE                         equ   4t
ADVFCACHE_NOHANDLER                   equ   8t
ADVFCACHE_FORCEBUILTIN                equ   16t
ADVFCACHE_ONSAVE                      equ   32t
ADVF_DATAONSTOP                       equ   64t

OLEGETMONIKER_ONLYIFTHERE             equ   1t
OLEGETMONIKER_FORCEASSIGN             equ   2t
OLEGETMONIKER_UNASSIGN                equ   3t
OLEGETMONIKER_TEMPFORUSER             equ   4t

OLEWHICHMK_CONTAINER                  equ   1t
OLEWHICHMK_OBJREL                     equ   2t
OLEWHICHMK_OBJFULL                    equ   3t

USERCLASSTYPE_FULL                    equ   1t
USERCLASSTYPE_SHORT                   equ   2t
USERCLASSTYPE_APPNAME                 equ   3t

OLEMISC_RECOMPOSEONRESIZE             equ   1t
OLEMISC_ONLYICONIC                    equ   2t
OLEMISC_INSERTNOTREPLACE              equ   4t
OLEMISC_STATIC                        equ   8t
OLEMISC_CANTLINKINSIDE                equ   16t
OLEMISC_CANLINKBYOLE1                 equ   32t
OLEMISC_ISLINKOBJECT                  equ   64t
OLEMISC_INSIDEOUT                     equ   128t
OLEMISC_ACTIVATEWHENVISIBLE           equ   256t
OLEMISC_RENDERINGISDEVICEINDEPENDENT  equ   512t
OLEMISC_INVISIBLEATRUNTIME            equ   1024t
OLEMISC_ALWAYSRUN                     equ   2048t
OLEMISC_ACTSLIKEBUTTON                equ   4096t
OLEMISC_ACTSLIKELABEL                 equ   8192t
OLEMISC_NOUIACTIVATE                  equ   16384t
OLEMISC_ALIGNABLE                     equ   32768t
OLEMISC_SIMPLEFRAME                   equ   65536t
OLEMISC_SETCLIENTSITEFIRST            equ   131072t
OLEMISC_IMEMODE                       equ   262144t
OLEMISC_IGNOREACTIVATEWHENVISIBLE     equ   524288t
OLEMISC_WANTSTOMENUMERGE              equ   1048576t
OLEMISC_SUPPORTSMULTILEVELUNDO        equ   2097152t

OLECLOSE_SAVEIFDIRTY                  equ   0t
OLECLOSE_NOSAVE                       equ   1t
OLECLOSE_PROMPTSAVE                   equ   2t

PROPCAT_NIL                           equ   -1t
PROPCAT_MISC                          equ   -2t
PROPCAT_FONT                          equ   -3t
PROPCAT_POSITION                      equ   -4t
PROPCAT_APPEARANCE                    equ   -5t
PROPCAT_BEHAVIOR                      equ   -6t
PROPCAT_DATA                          equ   -7t
PROPCAT_LIST                          equ   -8t
PROPCAT_TEXT                          equ   -9t
PROPCAT_SCALE                         equ   -10t
PROPCAT_DDE                           equ   -11t

OLEVERBATTRIB_NEVERDIRTIES            equ   1
OLEVERBATTRIB_ONCONTAINERMENU         equ   2

REGISTER_LOCALSERVER                  equ   1h
REGISTER_CONTROL                      equ   2h
REGISTER_THREAD_APARTMENT             equ   4h
REGISTER_THREAD_BOTH                  equ   8h
REGISTER_THREAD_FREE                  equ  10h
REGISTER_THREAD_NEUTRAL               equ  20h

PropCatItem struc
  dDispID       DWORD     ?
  dCatID        DWORD     ?
PropCatItem ends
LPPROPCATITEM typedef ptr PropCatItem

CatNameItem struc
  dCatID        DWORD     ?
  dResID        DWORD     ?
CatNameItem ends
LPCATNAMEITEM typedef ptr CatNameItem

VERBDATA struc                  ;Wrapper of OLEVERB structure
  dCommand      DWORD     ?
  pVerb         POINTER   ?
  dMenuFlags    DWORD     ?     ;See AppendMenu flags
  dVerbFlags    DWORD     ?     ;OLEVERBATTRIB_NEVERDIRTIES, OLEVERBATTRIB_ONCONTAINERMENU
VERBDATA ends
LPVERBDATA typedef ptr VERBDATA

LPDISPPARAMS typedef ptr DISPPARAMS

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     SUCCEEDED
; Purpose:   Check if HRESULT indicates succeed condition.
; Arguments: Arg1: 32 bit register.

SUCCEEDED macro Arg
  ifnb <Arg>
    test Arg, Arg
  endif
  exitm <!SIGN?>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     SUCCEEDED
; Purpose:   Check if HRESULT indicates failed condition.
; Arguments: Arg1: 32 bit register.

FAILED macro Arg
  ifnb <Arg>
    test Arg, Arg
  endif
  exitm <SIGN?>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     SAFE_ADD_REF
; Purpose:   Check if the interface pointer is different from NULL and then increments the
;            reference count.
; Arguments: Arg1: -> Interface.

SAFE_ADD_REF macro InterfacePtr
  .if InterfacePtr != NULL
    ICall InterfacePtr::IUnknown.AddRef
  .endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     SAFE_RELEASE
; Purpose:   Check if the interface pointer is different from NULL and then releases it.
; Arguments: Arg1: -> Interface.

SAFE_RELEASE macro InterfacePtr
  .if InterfacePtr != NULL
    ICall InterfacePtr::IUnknown.Release
  .endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     RELEASE_AND_NULLIFY
; Purpose:   Release the interface set to NULL.
; Arguments: Arg1: -> Interface.

RELEASE_AND_NULLIFY macro InterfacePtr
  mov xcx, InterfacePtr
  m2z POINTER ptr InterfacePtr
  ICall xcx::IUnknown.Release
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     SAFE_RELEASE_AND_NULLIFY
; Purpose:   Check if the interface pointer is different from NULL and then releases it.
;            The pointer is set to NULL.
; Arguments: Arg1: -> Interface.

SAFE_RELEASE_AND_NULLIFY macro InterfacePtr
  .if InterfacePtr != NULL
    RELEASE_AND_NULLIFY InterfacePtr
  .endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     MAKE_HRESULT
; Purpose:   Build the HRESULT value from its compinents.
; Arguments: Arg1: Severity.
;            Arg2: Facility.
;            Arg3: Code.

MAKE_HRESULT macro Sev, Fac, Code
  exitm <(Sev shl 31) or (Fac shl 16) or (Code)>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     ($)GuidComp
; Purpose:   Wrapper macro to check if 2 GUIDs are iqual.
; Arguments: Arg1: -> first GUID
;            Arg2: -> second GUID

GuidComp macro pGUID1:req, pGUID2:req
  invoke MemComp, pGUID1, pGUID2, sizeof(GUID)
endm

$GuidComp macro pGUID1:req, pGUID2:req
  GuidComp pGUID1, pGUID2
  exitm <eax>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     COM_INTERFACE_BEG
; Purpose:   Start the definition of an interface.
; Arguments: Arg1: Interface name.
;            Arg2: Ancestor interface.
;            Arg3: (optional) Interface GUID.

COM_INTERFACE_BEG macro IfcName:req, AncName:=<>, sIID
  ifnb <sIID>
    sIID_&IfcName textequ <sIID>                        ;;Create symbolic IID
  endif

  ??InterfaceName equ <IfcName>
  ??Interface CatStr <IfcName>, <Vtbl>

  ??Interface struct

  ifnb <AncName>
    $$sz1 CatStr <AncName>, <Vtbl>
    %$$sz1 {}                                           ;;Include ancestor methods
  else
    $$sz1 textequ <>
  endif

  @CatStr(%??Interface, <_Inherit>) textequ $$sz1       ;;Remember the interface ancestor
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     COM_INTERFACE_END
; Purpose:   Terminate definition of an interface.
; Arguments: None.

COM_INTERFACE_END macro
  ;;Terminate structure definition
  ??Interface ends

%echo  P%??InterfaceName typedef ptr ??Interface            ;;Pointer type to interface struct 
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     COM_MTD_STD
; Purpose:   Define a method in the interface definition.
; Arguments: Arg1: Method name.
;            Arg2: Method arguments (with or without colons & pSelf (or This) is passed implicitly).

COM_MTD_STD macro MtdName:req, Args:vararg
  COM_MTD_DSP MtdName, Args
  @CatStr(<_>, MtdName) POINTER ?                     ;;Make an entry in the structure
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     COM_MTD_DSP
; Purpose:   Define a dispatchable method. It has no enty in the VMT.
; Arguments: Arg1: Method name.
;            Arg2: Method arguments (with or without colons & pSelf (or This) is passed implicity).

COM_MTD_DSP macro MtdName:req, Args:vararg
  ;Accept arguments with and without double point. Build new list = $$ArgList
  $$ArgList textequ <>
  for $$Arg:req, <Args>
    ifidn @SubStr($$Arg, 1, 1), <:>
      %ifb <$$ArgList>
        $$ArgList textequ <$$Arg>
      else
        $$ArgList CatStr $$ArgList, <,>, <$$Arg>
      endif
    else
      %ifb <$$ArgList>
        $$ArgList CatStr <:>, <$$Arg>
      else
        $$ArgList CatStr $$ArgList, <,:>, <$$Arg>
      endif
    endif
  endm

  %ifb <$$ArgList>
    @CatStr(%??Interface, <_>, MtdName, <_Args>) catStr <:ptr>
  else
    @CatStr(%??Interface, <_>, MtdName, <_Args>) catStr <:ptr,>, $$ArgList
  endif
  if TARGET_BITNESS eq 32
    %ifb <$$ArgList>
      %@CatStr(%??Interface, <_>, MtdName) proto stdcall, :ptr
      %@CatStr(<TYPE_>, %??Interface, <_>, MtdName) typedef proto stdcall, :ptr
    else
      %@CatStr(%??Interface, <_>, MtdName) proto stdcall, :ptr, $$ArgList
      %@CatStr(<TYPE_>, %??Interface, <_>, MtdName) typedef proto stdcall, :ptr, $$ArgList
    endif
  else
    ifb <Args>
      %@CatStr(%??Interface, <_>, MtdName) proto fastcall, :ptr
      %@CatStr(<TYPE_>, %??Interface, <_>, MtdName) typedef proto fastcall, :ptr
    else
      %@CatStr(%??Interface, <_>, MtdName) proto fastcall, :ptr, $$ArgList
      %@CatStr(<TYPE_>, %??Interface, <_>, MtdName) typedef proto fastcall, :ptr, $$ArgList
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     BeginMap
; Purpose:   Start a category map.
; Arguments: Arg1: Number of items.

BeginMap macro ItemCount:req
  exitm <DWORD ItemCount>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     MGUID
; Purpose:   Transform a formated GUID string to a GUID record.
;            Must be 36 bytes long, including dashes!
;            Format: MGUID(00000000-0000-0000-0000-000000000000)
; Arguments: GUID string.
; Return:    GUID record.

MGUID macro GUIDStr:req
  if @SizeStr(GUIDStr) eq 36
    $$GUID01 SubStr <GUIDStr>, 1, 8
    $$GUID01 CatStr <0>, $$GUID01, <h>

    $$GUID02 SubStr <GUIDStr>, 10, 4
    $$GUID02 CatStr <0>, $$GUID02, <h>

    $$GUID03 SubStr <GUIDStr>, 15, 4
    $$GUID03 CatStr <0>, $$GUID03, <h>

    $$GUID04 SubStr <GUIDStr>, 20, 2
    $$GUID04 CatStr <0>, $$GUID04, <h>

    $$GUID05 SubStr <GUIDStr>, 22, 2
    $$GUID05 CatStr <0>, $$GUID05, <h>

    $$GUID06 SubStr <GUIDStr>, 25, 2
    $$GUID06 CatStr <0>, $$GUID06, <h>

    $$GUID07 SubStr <GUIDStr>, 27, 2
    $$GUID07 CatStr <0>, $$GUID07, <h>

    $$GUID08 SubStr <GUIDStr>, 29, 2
    $$GUID08 CatStr <0>, $$GUID08, <h>

    $$GUID09 SubStr <GUIDStr>, 31, 2
    $$GUID09 CatStr <0>, $$GUID09, <h>

    $$GUID10 SubStr <GUIDStr>, 33, 2
    $$GUID10 CatStr <0>, $$GUID10, <h>

    $$GUID11 SubStr <GUIDStr>, 35, 2
    $$GUID11 CatStr <0>, $$GUID11, <h>
  else
    .err <MGUID incorrect input string>
  endif

  exitm <{$$GUID01, $$GUID02, $$GUID03, {$$GUID04, $$GUID05, $$GUID06, $$GUID07, $$GUID08, $$GUID09, $$GUID10, $$GUID11}}>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     DefGUID
; Purpose:   Define a symbol with a formated GUID string.
; Arguments: Arg1: GUID symbol.
;            Arg2: GUID string. Definition: sIID_IXXX textequ <12345678-1234-1234-1234-1234567890AB>

DefGUID macro GUIDSymbol:req, GUIDStr:req
  if @SizeStr(GUIDStr) eq 36
    externdef GUIDSymbol:GUID                           ;;Export this symbol
    GUIDSymbol GUID MGUID(GUIDStr)
  else
    .err <DefGUID incorrect input string>
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
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
