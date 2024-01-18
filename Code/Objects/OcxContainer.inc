; ==================================================================================================
; Title:      OcxContainer.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of Active X Control Container objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; Link:       https://docs.microsoft.com/en-us/previous-versions/windows/internet-explorer/ie-developer/platform-apis/cc678965(v=vs.85)
; ==================================================================================================


; ==================================================================================================
;     Object definitions
; ==================================================================================================

externdef IID_IOleObject:GUID
externdef IID_IOleInPlaceObject:GUID
externdef IID_IOleInPlaceActiveObject:GUID
externdef IID_IOleControl:GUID
externdef IID_IDataObject:GUID
externdef IID_IViewObject2:GUID
externdef IID_IDispatch:GUID
externdef IID_IProvideClassInfo:GUID
externdef IID_ISpecifyPropertyPages:GUID
externdef IID_IPersistStorage:GUID
externdef IID_IConnectionPoint:GUID
externdef IID_IStorage:GUID
externdef IID_IClassFactory2:GUID
externdef IID_IFontDisp:GUID
externdef CLSID_OCXCLIENTSITE:GUID


SHAREFLAGS  equ   STGM_DIRECT or STGM_READWRITE or STGM_SHARE_EXCLUSIVE

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:   OcxClientSite
; Purpose:  Implement COM ClientSite for OCX components.
;           An instance is created for each OcxControl and stored in a collection owned by the
;           OcxContainer object.

Object OcxClientSite, OcxClientSiteID, Component
  VirtualMethod     Connect
  VirtualMethod     Disconnect
  VirtualMethod     DoVerb,                 DWORD
  VirtualMethod     GetName
  RedefineMethod    Init,                   POINTER

  ;Control provided interfaces
  DefineVariable    pIUnknown,              POINTER,        NULL
  DefineVariable    pIOleObject,            POINTER,        NULL
  DefineVariable    pIOleInPlaceObject,     POINTER,        NULL
  DefineVariable    pIOleInPlaceActiveObject, POINTER,      NULL
  DefineVariable    pIOleControl,           POINTER,        NULL
  DefineVariable    pIDataObject,           POINTER,        NULL
  DefineVariable    pIViewObject2,          POINTER,        NULL
  DefineVariable    pIDispatch,             POINTER,        NULL
  DefineVariable    pIProvideClassInfo,     POINTER,        NULL
  DefineVariable    pISpecifyPropertyPages, POINTER,        NULL
  DefineVariable    pIPersistStorage,       POINTER,        NULL
  DefineVariable    pIPNS_ConnectionPoint,  POINTER,        NULL      ;-> PropertyNotifySink CP

  ;Client Site provided interfaces
  DefineVariable    pIUnknownSite,          POINTER,        NULL
  DefineVariable    pISiteDispatch,         POINTER,        NULL
  DefineVariable    pIOleClientSite,        POINTER,        NULL
  DefineVariable    pIOleInPlaceSite,       POINTER,        NULL
  DefineVariable    pIOleInPlaceSiteEx,     POINTER,        NULL
  DefineVariable    pIOleInPlaceSiteWindowless, POINTER,    NULL
  DefineVariable    pIOleControlSite,       POINTER,        NULL
  DefineVariable    pISimpleFrameSite,      POINTER,        NULL
  DefineVariable    pIOleContainer,         POINTER,        NULL
  DefineVariable    pIOleDocumentSite,      POINTER,        NULL
  DefineVariable    pIErrorInfo,            POINTER,        NULL
  DefineVariable    pIOleInPlaceFrame,      POINTER,        NULL
  DefineVariable    pIServiceProvider,      POINTER,        NULL
  DefineVariable    pIStorage,              POINTER,        NULL

  ;Client Site Sinks
  DefineVariable    pIAdviseSink,           POINTER,        NULL
  DefineVariable    dAS_Cookie,             DWORD,          0         ;Cookie returned by the control
  DefineVariable    pIPropertyNotifySink,   POINTER,        NULL
  DefineVariable    dPNS_Cookie,            DWORD,          0         ;Cookie returned by the control

  ;Data members
  DefineVariable    pCtrlClsID,             REFGUID,        NULL      ;CLSID of control
  DefineVariable    pName,                  PSTRING,        NULL
  DefineVariable    dMiscStatus,            DWORD,          0         ;Control miscellaneous status
  DefineVariable    hCtrlWnd,               HWND,           0
  DefineVariable    CtrlRect,               RECT,           {0,0,1000,1000}
  DefineVariable    ClipRect,               RECT,           {0,0,1000,1000}
  DefineVariable    BorderSpace,            RECT,           {0,0,1000,1000}
  DefineVariable    dShow,                  BOOL,           FALSE
  DefineVariable    dInPlaceActive,         BOOL,           FALSE
  DefineVariable    dLockCount,             DWORD,          0

  RedefineVariable  pCLSID,   offset CLSID_OCXCLIENTSITE

ObjectEnd


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:   OcxContainer
; Purpose:  Implement COM Container for OCX components.
; Links:    http://msdn.microsoft.com/en-us/library/ms686619(VS.85).aspx     Containers
;           http://msdn.microsoft.com/en-us/library/ms691268(VS.85).aspx     Interfaces
;           ATL71.DLL is distributed with the free .NET Framework 1.1.
;           http://msdn.microsoft.com/en-us/library/ms679718(VS.85).aspx     Ambient properties
;           http://www.mactech.com/articles/mactech/Vol.11/11.01/OLEIn-PlaceActivation/index.html
;
; Model:
;
;                    OCX Container                                        OCX Control
;                                                                             1..n
;                                  ———                                                ———
;                                 |   |                                              |   |
;                                  ———                                                ———
;                                   |                                                  |
;      ————————————————————————————————————                        ———————————————————————————
;     |                             |      |                      |                 IUnknown  |
;     |       OCX Client Site 1..n  |      |                      |                           |
;     |       ———————————————————————————  |              ———     |                           |
;     |     —|                  IUnknown | |             |   |————| IOleObject                |
;     |   —| |                    Site   | |              ———     |                           |
;     |  | | |                           | |   ———        ———     |                           |
;     |  | | | IOleClientSite            |—|——|   |      |   |————| IOleInPlaceObject         |
;     |  | | |                           | |   ———        ———     |                           |
;     |  | | |                           | |   ———        ———     |                           |
;     |  | | | IAdviseSink               |—|——|   |      |   |————| IOleInPlaceActiveObject   |
;     |  | | |                           | |   ———        ———     |                           |
;     |  | | |                           | |   ———        ———     |                           |
;     |  | | | IOleInPlaceSite           |—|——|   |      |   |————| IOleControl               |
;     |  | | |                           | |   ———        ———     |                           |
;     |  | | |                           | |   ———        ———     |                           |
;     |  | | | IOleControlSite           |—|——|   |      |   |————| IDataObject               |
;     |  | | |                           | |   ———        ———     |                           |
;     |  | | |                           | |   ———        ———     |                           |
;     |  | | | IOleContainer             |—|——|   |      |   |————| IViewObject2              |
;     |  | | |                           | |   ———        ———     |                           |
;     |  | | |                           | |   ———        ———     |                           |
;     |  | | | IDispatch                 |—|——|   |      |   |————| IDispatch                 |
;     |  | | |                           | |   ———        ———     |                           |
;     |  | | |                           | |   ———        ———     |                           |
;     |  | | | ISimpleFrameSite          |—|——|   |      |   |————| IConnectionPointContainer |
;     |  | | |                           | |   ———        ———     |                           |
;     |  | | |                           | |   ———        ———     |                           |
;     |  | | | IPropertyNotifySink       |—|——|   |      |   |————| IProvideClassInfo(2)      |
;     |  | | |                           | |   ———        ———     |                           |
;     |  | | |                           | |   ———        ———     |                           |
;     |  | | | IErrorInfo                |—|——|   |      |   |————| ISpecifyPropertyPages     |
;     |  | | |                           | |   ———        ———     |                           |
;     |  | | |                           | |              ———     |                           |
;     |  | | |                           | |             |   |————| IPersist...  (*)          |
;     |  | | |                           | |              ———     |                           |
;     |  | | '———————————————————————————' |              ———     |                           |
;     |  | '————————————————————————————'  |             |   |————| IOleCache(2)              |
;     |  '————————————————————————————'    |              ———     |                           |
;     |                                    |              ———     |                           |
;     |                                    |             |   |————| IExternalConnection       |
;     '————————————————————————————————————'              ———     |                           |
;                                                         ———     |                           |
;                                                        |   |————| IRunnableObject           |
;                                                         ———     |                           |
;                                                         ———     |                           |
;                                                        |   |————| IClassFactory2            |
;                                                         ———     |                           |
;                                                                 |                           |
;                                                                 '———————————————————————————'
;
;
; (*) Persistence Interfaces: IPersistStream, IPersistStreamInit, IPersistMemory, IPersistStorage,
;                             IPersistMoniker, IPersistPropertyBag
;
;
;
;
; In-Place window model
; —————————————————————
;
;             Frame
;             ———————————————————————————————————————————————————————————
;            |    Document                                               |
;            |    —————————————————————————————————————————————————————  |
;            |   |    Parent                                           | |
;            |   |    ———————————————————————————————————————————————  | |
;            |   |   |    In-Place Objects                           | | |
;            |   |   |    —————————————————————————————————————————  | | |
;            |   |   |   |                                         | | | |
;            |   |   |   |                                         | | | |
;            |   |   |   |                                         | | | |
;            |   |   |   |                                         | | | |
;            |   |   |   |                                         | | | |
;            |   |   |   |                                         | | | |
;            |   |   |   |                                         | | | |
;            |   |   |   |                                         | | | |
;            |   |   |   |                                         | | | |
;            |   |   |   |                                         | | | |
;            |   |   |   |                                         | | | |
;            |   |   |   '—————————————————————————————————————————' | | |
;            |   |   '———————————————————————————————————————————————' | |
;            |   '—————————————————————————————————————————————————————' |
;            '———————————————————————————————————————————————————————————'
;

Object OcxContainer, OcxContainerID, Primer
  VirtualMethod     CreateClientSite
  VirtualMethod     CreateControl,          REFGUID, DWORD, POINTER
  VirtualMethod     CreateControlEx,        REFGUID, DWORD, BSTR, POINTER
  VirtualMethod     CreateControlLic,       REFGUID, DWORD, BSTR, POINTER
  VirtualMethod     DeleteControl,          POINTER
  RedefineMethod    Done
  RedefineMethod    Init,                   POINTER, HANDLE

  DefineVariable    hWndSite,               HANDLE,         0         ;Parent window of hCtrlWnd
  DefineVariable    pIStorageRoot,          POINTER,        NULL

  ;Supported ambient properties
  DefineVariable    dUserMode,              BOOL,           TRUE      ;User/Design mode = TRUE/FALSE
  DefineVariable    pIFontDisp,             POINTER,        NULL
  DefineVariable    dOleForeColor,          OLE_COLOR,      $RGB(0,0,255)
  DefineVariable    dOleBackColor,          OLE_COLOR,      $RGB(192,192,192)
  DefineVariable    dUserLocaleID,          LCID,           LOCALE_SYSTEM_DEFAULT
  DefineVariable    dMessageReflect,        BOOL,           FALSE
  DefineVariable    dShowGrabhandles,       BOOL,           TRUE      ;Show handles on the corners
  DefineVariable    dShowHatching,          BOOL,           TRUE      ;Show hatched border
  DefineVariable    dDisplayAsDefault,      BOOL,           TRUE
  DefineVariable    dRightToLeft,           BOOL,           FALSE
  DefineVariable    dTopToBottom,           BOOL,           TRUE
  DefineVariable    dUIDead,                BOOL,           FALSE     ;Ctrl response to the user

  Embed    OcxClientSiteColl,    Collection
ObjectEnd


include I_OcxCont_OleWindow.inc
include I_OcxCont_OleClientSite.inc
include I_OcxCont_OleInPlaceSite.inc
include I_OcxCont_OleInPlaceSiteEx.inc
include I_OcxCont_OleControlSite.inc
include I_OcxCont_OleContainer.inc
include I_OcxCont_OleDocumentSite.inc
include I_OcxCont_OleInPlaceSiteWindowless.inc
include I_OcxCont_OleInPlaceFrame.inc
include I_OcxCont_AdviseSink.inc
include I_OcxCont_SiteDispatch.inc
include I_OcxCont_SimpleFrameSite.inc
include I_OcxCont_PropertyNotifySink.inc
include I_OcxCont_ErrorInfo.inc
include I_OcxCont_ServiceProvider.inc

.code

if IMPLEMENT

.const
DefGUID CLSID_OCXCLIENTSITE, <F85F32F6-8658-4074-8B3D-743FDA45EFE8>


; ==================================================================================================
;     OcxClientSite implementation
; ==================================================================================================

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OcxClientSite.Connect
; Purpose:    Connect the control object to the container using the Site object. Called internally.
; Arguments:  None.
; Return:     Nothing.

GatterCtrlInterface macro IntName:req
  lea xax, [xsi].p&IntName&
  m2z POINTER ptr [xax]
  ICall [xsi].pIUnknown::IUnknown.QueryInterface, offset IID_&IntName&, xax
  if DEBUGGING
    .if FAILED(eax)
      @CatStr(<DbgText !"Failed to get I>, <IntName>, <!">)
    .endif
  endif
endm

if TARGET_BITNESS eq 64
  option stackbase:rbp
endif

Method OcxClientSite.Connect, uses xdi xsi
  local cStorageName[MAX_PATH]:CHRW

  SetObject xsi

  ;Try to gatter all these control interfaces
  GatterCtrlInterface IOleObject
  GatterCtrlInterface IOleInPlaceObject
  GatterCtrlInterface IOleInPlaceActiveObject
  GatterCtrlInterface IOleControl
  GatterCtrlInterface IDataObject
  GatterCtrlInterface IViewObject2
  GatterCtrlInterface IDispatch
  GatterCtrlInterface IProvideClassInfo
  GatterCtrlInterface ISpecifyPropertyPages
  GatterCtrlInterface IPersistStorage

  SetOwner xdi, OcxContainer, xsi

  .if [xsi].pIOleObject != NULL
    ;Get the MiscStatus flags
    ICall [xsi].pIOleObject::IOleObject.GetMiscStatus, DVASPECT_CONTENT, addr [xsi].dMiscStatus
    DbgHex [xsi].dMiscStatus, "[xsi].dMiscStatus"

    .ifBitSet [xsi].dMiscStatus, OLEMISC_SETCLIENTSITEFIRST
      ;Set the Control's clientsite
      ICall [xsi].pIOleObject::IOleObject.SetClientSite, [xsi].pIOleClientSite
      ;If all went right, the control should have querried at least for IDispatch
      .if FAILED(eax)
        DbgWarning "IOleObject.SetClientSite failed"
        DbgComError(eax)
      .endif
    .endif

    ;Set Advise Sink
    ICall [xsi].pIOleObject::IOleObject.Advise, [xsi].pIAdviseSink, addr [xsi].dAS_Cookie
    .if FAILED(eax)
      DbgWarning "IOleObject.Advise failed"
      DbgComError eax
    .endif
  .endif

  ;Storage initialization
  invoke dword2hexW, addr cStorageName, esi
  DbgStrW cStorageName
  m2z [xsi].pIStorage
  ICall [xdi].pIStorageRoot::IStorage.OpenStorage, addr cStorageName, NULL, SHAREFLAGS, 0, 0, \
                                                   addr [xsi].pIStorage
  .if eax == STG_E_FILENOTFOUND
    ICall [xdi].pIStorageRoot::IStorage.CreateStorage, addr cStorageName, SHAREFLAGS, 0, 0, \
                                                       addr [xsi].pIStorage
    .if eax != S_OK
      DbgComError eax
    .else
      ICall [xsi].pIStorage::IStorage.SetClass, [xsi].pCtrlClsID
      ;Call IPersistStorage::Load or ::InitNew
      .if [xsi].pIPersistStorage != NULL
        ICall [xsi].pIPersistStorage::IPersistStorage.Load, [xsi].pIStorage
        .if FAILED(eax)
          ICall [xsi].pIPersistStorage::IPersistStorage.InitNew, [xsi].pIStorage
        .endif
      .endif
    .endif
  .endif

  .if [xsi].pIOleObject != NULL
    ICall [xsi].pIOleObject::IOleObject.SetHostNames, $OfsCStrW("ObjAsm OCX Control Container"), \
                                                      NULL
  .endif

  ;Put the Control from loaded to running state (rarely needed for activex controls)
  .if [xsi].pIUnknown != NULL
    invoke OleRun, [xsi].pIUnknown
  .endif

  .if [xsi].pIOleObject != NULL
    ;Activate the Control
    OCall DoVerb, OLEIVERB_INPLACEACTIVATE
    .if FAILED(eax)
      DbgWarning "OLEIVERB_INPLACEACTIVATE failed, trying OLEIVERB_SHOW..."
      OCall DoVerb, OLEIVERB_SHOW
    .endif

    ;If we did it not before, the we set the client site now
    .ifBitClr [xsi].dMiscStatus, OLEMISC_SETCLIENTSITEFIRST
      ICall [xsi].pIOleObject::IOleObject.SetClientSite, [xsi].pIOleClientSite
    .endif
  .endif

  .if [xsi].pIOleInPlaceObject != NULL
    ICall [xsi].pIOleInPlaceObject::IOleInPlaceObject.GetWindow_, addr [xsi].hCtrlWnd
  .endif

  ;Establish a connection between a server (control) ConnectionPoint and IPropertyNotifySink

  invoke ComEventsAdvice, [xsi].pIUnknown, \
                          [xsi].pIPropertyNotifySink, offset IID_IPropertyNotifySink, \
                          addr [xsi].pIPNS_ConnectionPoint, addr [xsi].dPNS_Cookie
  ;if the cookie went lost, the connection could not be established and
  ;we doesn't need the ConnectionPoint anymore
  .if [xsi].dPNS_Cookie == 0
    SAFE_RELEASE_AND_NULLIFY [xsi].pIPNS_ConnectionPoint
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OcxClientSite.Disconnect
; Purpose:    Disconnect the control object from the container.
; Arguments:  None.
; Return:     Nothing.

Method OcxClientSite.Disconnect, uses xsi
  SetObject xsi

  ;Unadvise and cleanup
  .if [xsi].dAS_Cookie != 0                           ;This also ensures that pIOleObject != NULL
    ICall [xsi].pIOleObject::IOleObject.Unadvise, [xsi].dAS_Cookie
    m2z [xsi].dAS_Cookie
  .endif
  Destroy [xsi].pIAdviseSink

  .if [xsi].dPNS_Cookie != 0
    invoke ComEventsUnadvice, [xsi].pIPNS_ConnectionPoint, [xsi].dPNS_Cookie
    m2z [xsi].dPNS_Cookie
  .endif

  ;Release all aquired interfaces
  SAFE_RELEASE_AND_NULLIFY [xsi].pISpecifyPropertyPages
  SAFE_RELEASE_AND_NULLIFY [xsi].pIProvideClassInfo
  SAFE_RELEASE_AND_NULLIFY [xsi].pIDispatch
  SAFE_RELEASE_AND_NULLIFY [xsi].pIViewObject2
  SAFE_RELEASE_AND_NULLIFY [xsi].pIDataObject
  SAFE_RELEASE_AND_NULLIFY [xsi].pIOleControl
  SAFE_RELEASE_AND_NULLIFY [xsi].pIOleInPlaceActiveObject
  SAFE_RELEASE_AND_NULLIFY [xsi].pIOleInPlaceObject

  .if [xsi].pIOleObject != NULL
    ICall [xsi].pIOleObject::IOleObject.Close, OLECLOSE_SAVEIFDIRTY
    ICall [xsi].pIOleObject::IOleObject.SetClientSite, NULL
    ICall [xsi].pIOleObject::IOleObject.Release
  .endif

  SAFE_RELEASE_AND_NULLIFY [xsi].pIPersistStorage
  SAFE_RELEASE_AND_NULLIFY [xsi].pIUnknown

  ;Final cleanup
  invoke StrDispose, [xsi].pName                          ;It is safe to call this API

  ;Now we trigger the component destruction. This MUST be the last thing we do.
  ICall [xsi].pIUnknownSite::IUnknown.Release
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OcxClientSite.DoVerb
; Purpose:    Perform a verb specific command.
; Arguments:  Arg1: Verb command.
; Return:     eax = HRESULT.

Method OcxClientSite.DoVerb, uses xbx xsi, dVerb:DWORD
  DbgText "OcxClientSite.DoVerb"
  DbgHex edx, "Verb"
  SetObject xsi
  .if [xsi].pIOleObject != NULL
    SetOwner xbx, OcxContainer, xsi
    ICall [xsi].pIOleObject::IOleObject.DoVerb, dVerb, 0, [xsi].pIOleClientSite, 0, \
                                                [xbx].hWndSite, addr [xsi].CtrlRect
    if DEBUGGING
      .if FAILED(eax)
        DbgWarning "IOleObject.DoVerb failed"
        DbgDec dVerb
        DbgComError eax
      .endif
    endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OcxClientSite.Init
; Purpose:    Initialize the Control object.
; Arguments:  Arg1: -> Owner object (OcxContainer).
; Return:     eax = OBJ_OK if succeeded.

Method OcxClientSite.Init, uses xbx xsi, pOwner:POINTER
  SetObject xsi
  ACall xsi.Init, pOwner, NULL
  SetOwner xbx, OcxContainer, xsi
  mov [xsi].pIAdviseSink, $New(I_OcxCont_AdviseSink)
  ;We use as Cookie the pIAdviseSink value
  mov [xsi].dAS_Cookie, eax
  OCall xax::I_OcxCont_AdviseSink.Init, xsi

  mov [xsi].pIPropertyNotifySink, $New(I_OcxCont_PropertyNotifySink)
  OCall [xsi].Interfaces::Collection.Insert, xax
  OCall xax::I_OcxCont_PropertyNotifySink.Init, xsi

  mov [xsi].pIOleClientSite, $New(I_OcxCont_OleClientSite)
  OCall [xsi].Interfaces::Collection.Insert, xax
  OCall xax::I_OcxCont_OleClientSite.Init, xsi
  mov [xsi].pISiteDispatch, $New(I_OcxCont_SiteDispatch)
  OCall [xsi].Interfaces::Collection.Insert, xax
  OCall xax::I_OcxCont_SiteDispatch.Init, xsi, NULL, NULL
  mov [xsi].pIOleInPlaceSite, $New(I_OcxCont_OleInPlaceSite)
  OCall [xsi].Interfaces::Collection.Insert, xax
  OCall xax::I_OcxCont_OleInPlaceSite.Init, xsi, [xbx].hWndSite
  mov [xsi].pIOleInPlaceSiteEx, $New(I_OcxCont_OleInPlaceSiteEx)
  OCall [xsi].Interfaces::Collection.Insert, xax
  OCall xax::I_OcxCont_OleInPlaceSiteEx.Init, xsi, [xbx].hWndSite
  mov [xsi].pIOleInPlaceSiteWindowless, $New(I_OcxCont_OleInPlaceSiteWindowless)
  OCall [xsi].Interfaces::Collection.Insert, xax
  OCall xax::I_OcxCont_OleInPlaceSiteWindowless.Init, xsi, [xbx].hWndSite
  mov [xsi].pIOleInPlaceFrame, $New(I_OcxCont_OleInPlaceFrame)
  OCall [xsi].Interfaces::Collection.Insert, xax
  OCall xax::I_OcxCont_OleInPlaceFrame.Init, xsi, [xbx].hWndSite
  mov [xsi].pIOleControlSite, $New(I_OcxCont_OleControlSite)
  OCall [xsi].Interfaces::Collection.Insert, xax
  OCall xax::I_OcxCont_OleControlSite.Init, xsi
  mov [xsi].pISimpleFrameSite, $New(I_OcxCont_SimpleFrameSite)
  OCall [xsi].Interfaces::Collection.Insert, xax
  OCall xax::I_OcxCont_SimpleFrameSite.Init, xsi
  mov [xsi].pIErrorInfo, $New(I_OcxCont_ErrorInfo)
  OCall [xsi].Interfaces::Collection.Insert, xax
  OCall xax::I_OcxCont_ErrorInfo.Init, xsi
  mov [xsi].pIOleContainer, $New(I_OcxCont_OleContainer)
  OCall [xsi].Interfaces::Collection.Insert, xax
  OCall xax::I_OcxCont_OleContainer.Init, xsi
;  mov [xsi].pIOleDocumentSite, $New(I_OcxCont_OleDocumentSite)
;  OCall [xsi].Interfaces::Collection.Insert, xax
;  OCall xax::I_OcxCont_OleDocumentSite.Init, xsi
;  mov [xsi].pIServiceProvider, $New(I_OcxCont_ServiceProvider)
;  OCall [xsi].Interfaces::Collection.Insert, xax
;  OCall xax::I_OcxCont_ServiceProvider.Init, xsi

  ;Increment the ref count to take control over the component destruction
  OCall xsi.GetInterface, offset IID_IUnknown, addr [xsi].pIUnknownSite
  xor eax, eax                                        ;eax = OBJ_OK
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OcxClientSite.GetName
; Purpose:    Retrieve the name of the control (ANSI).
; Arguments:  None.
; Return:     Nothing.

Method OcxClientSite.GetName, uses xsi
  local hKey:HKEY, dSize:DWORD, cText[MAX_PATH]:CHRW
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    local cCLSID[100]:CHRW
  endif

  SetObject xsi
  FillTextW cText, <CLSID\>
  lea xdx, [cText + 12]
  invoke StringFromGUID2, [xsi].pCtrlClsID, xdx, lengthof(cText) - 6
  IF TARGET_STR_TYPE eq STR_TYPE_ANSI
    lea xax, [cText]
    invoke WideCharToMultiByte, CP_ACP, 0, xax, -1, xax, sizeof cCLSID, NULL, NULL
  ENDIF

  invoke RegOpenKeyEx, HKEY_CLASSES_ROOT, addr cText, 0, KEY_READ, addr hKey

  .if (eax == ERROR_SUCCESS)
    mov dSize, lengthof cText
    invoke RegQueryValueEx, hKey, offset wNULL, NULL, NULL, addr cText, addr dSize
    invoke RegCloseKey, hKey
    invoke StrDispose, [xsi].pName                    ;It is safe to call this API
    mov [xsi].pName, $invoke(StrNew, addr cText)
  .endif
MethodEnd


; ==================================================================================================
;     OcxContainer implementation
; ==================================================================================================
;
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OcxContainer.CreateClientSite
; Purpose:    Create a new OcxClientSite used to connect to the control.
; Arguments:  None.
; Return:     xax -> New created OcxControlSite, or NULL if failed.

Method OcxContainer.CreateClientSite, uses xbx
  New OcxClientSite
  .if xax != NULL
    mov xbx, xax
    OCall xbx::OcxClientSite.Init, pSelf
    .if eax == OBJ_OK
      mov xax, xbx
    .else
      Kill xbx
      xor eax, eax
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OcxContainer.CreateControl
; Purpose:    Create a new hosted control using CoCreateInstance.
; Arguments:  Arg1: -> Control class ID (GUID).
;             Arg2: Class context.
;             Arg3: -> ClientSite to be used to connect to the control.
; Return:     eax = OBJ_OK if succeeded.

Method OcxContainer.CreateControl, uses xbx xsi, pCtrlClsID:REFGUID, dClsCtx:DWORD, \
                                                 pClientSite:POINTER
  SetObject xsi
  .if pClientSite != NULL
    mov xbx, pClientSite
    assume xbx:$ObjPtr(OcxClientSite)
    invoke CoCreateInstance, pCtrlClsID, NULL, dClsCtx, offset IID_IUnknown, addr [xbx].pIUnknown
    .if SUCCEEDED(eax)
      ;Insert new ClientSite
      OCall [xsi].OcxClientSiteColl::Collection.Insert, xbx
      m2m [xbx].pCtrlClsID, pCtrlClsID, xax
      OCall xbx::OcxClientSite.GetName
      OCall xbx::OcxClientSite.Connect
      xor eax, eax
    .else
      DbgComError eax, "CoCreateInstance failure in OcxContainer.CreateControl"
      DbgGUID pCtrlClsID, "requested CLSID"
      OCall xsi.ErrorReport, NULL, OCT_COCREATEINSTANCE_FAILED
    .endif
    assume xbx:NOTHING
  .else
    OCall xsi.ErrorReport, NULL, OCT_INVALID_POINTER
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OcxContainer.CreateControlEx
; Purpose:    Create a new hosted control using CoCreateInstanceEx.
; Arguments:  Arg1: -> Control class ID (GUID).
;             Arg2: Class context.
;             Arg3: BSTR identifiying the remote host machine.
;             Arg4: -> ClientSite to be used to connect to the control.
; Return:     eax = OBJ_OK if succeeded.

Method OcxContainer.CreateControlEx, uses xbx xsi, pCtrlClsID:REFGUID, dClsCtx:DWORD, \
                                                   pMachine:BSTR, pClientSite:POINTER
  local csi:COSERVERINFO, dExeContext:DWORD, mqi[1]:MULTI_QI

  SetObject xsi
  .if pClientSite != NULL
    m2m mqi[0*sizeof MULTI_QI].pIID, offset IID_IUnknown, xax
    m2z mqi[0*sizeof MULTI_QI].pItf
    m2z mqi[0*sizeof MULTI_QI].hr

    .if pMachine == NULL
      xor ebx, ebx
      m2m dExeContext, dClsCtx, eax
    .else
      m2z csi.dwReserved1
      m2m csi.pwszName, pMachine, xax
      m2z csi.pAuthInfo
      m2z csi.dwReserved2
      lea xbx, csi
      mov dExeContext, CLSCTX_REMOTE_SERVER
    .endif

    invoke CoCreateInstanceEx, pCtrlClsID, NULL, dExeContext, xbx, 3, addr mqi
    .if SUCCEEDED(eax)
      mov xbx, pClientSite
      OCall [xsi].OcxClientSiteColl::Collection.Insert, xbx
      .if mqi[0*sizeof MULTI_QI].hr == S_OK
        m2m [xbx].$Obj(OcxClientSite).pIUnknown, mqi[0*sizeof MULTI_QI].pItf, xax
      .endif
      m2m [xbx].$Obj(OcxClientSite).pCtrlClsID, pCtrlClsID, xax
      OCall xbx::OcxClientSite.GetName
      OCall xbx::OcxClientSite.Connect
      xor eax, eax
    .endif
  .else
    OCall xsi.ErrorReport, NULL, OCT_INVALID_POINTER
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OcxContainer.CreateControlLic
; Purpose:    Create a new hosted control using IClassFactory2.
; Arguments:  Arg1: -> Control class ID (GUID).
;             Arg2: Class context.
;             Arg3: -> License Key (BSTR).
;             Arg4: -> ClientSite to be used to connect to the control.
; Return:     eax = OBJ_OK if succeeded.

Method OcxContainer.CreateControlLic, uses xbx xsi, pCtrlClsID:REFGUID, dClsCtx:DWORD, \
                                                    pLicKey:BSTR, pClientSite:POINTER
  local pClassFactory2:POINTER, LicInfo:LICINFO, bInternalLicKey:BOOL

  SetObject xsi
  m2z bInternalLicKey

  .if pClientSite != NULL
    mov xbx, pClientSite
    assume xbx:$ObjPtr(OcxClientSite)

    invoke CoGetClassObject, pCtrlClsID, dClsCtx, NULL, addr IID_IClassFactory2, addr pClassFactory2
    .if SUCCEEDED(eax)
      .if pLicKey == NULL
        ICall pClassFactory2::IClassFactory2.GetLicInfo, addr LicInfo
        DbgHex LicInfo.fRuntimeKeyAvail, "fRuntimeKeyAvail"
        DbgHex LicInfo.fLicVerified, "fLicVerified"
        .if LicInfo.fRuntimeKeyAvail == TRUE
          ICall pClassFactory2::IClassFactory2.RequestLicKey, NULL, addr pLicKey
          .if SUCCEEDED(eax)
            mov bInternalLicKey, TRUE
          .endif
        .endif
      .endif

      ICall pClassFactory2::IClassFactory2.CreateInstanceLic, NULL, NULL, offset IID_IUnknown, \
                                                              pLicKey, addr [xbx].pIUnknown
      .if SUCCEEDED(eax)
        ;Cleanup
        .if (pLicKey != NULL) && (bInternalLicKey == TRUE)
          invoke SysFreeString, pLicKey
        .endif
        ICall pClassFactory2::IClassFactory2.Release

        ;Insert new OcxClientSite
        OCall [xsi].OcxClientSiteColl::Collection.Insert, xbx
        m2m [xbx].pCtrlClsID, pCtrlClsID, xax
        OCall xbx::OcxClientSite.GetName
        OCall xbx::OcxClientSite.Connect
        mov xax, xbx
      .else
        DbgComError eax
        Kill xbx
        xor eax, eax
      .endif
    .else
      Kill xbx
      xor eax, eax
    .endif
    assume xbx:NOTHING
  .else
    OCall xsi.ErrorReport, NULL, OCT_INVALID_POINTER
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OcxContainer.DeleteControl
; Purpose:    Delete the currently hosted control.
; Arguments:  Arg1: -> OcxClientSite.
; Return:     Nothing.

Method OcxContainer.DeleteControl,, pClientSite:POINTER
  .if pClientSite != NULL
    OCall pClientSite::OcxClientSite.Disconnect
    SetObject xcx
    OCall [xcx].OcxClientSiteColl::Collection.Delete, pClientSite
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OcxContainer.Done
; Purpose:    Finalize the Host object.
; Arguments:  None.
; Return:     Nothing.

Method OcxContainer.Done, uses xbx xdi xsi
  SetObject xsi
  xor ebx, ebx
  mov xdi, [xsi].OcxClientSiteColl.pItems
  .while ebx != [xsi].OcxClientSiteColl.dCount
    OCall POINTER ptr [xdi]::OcxClientSite.Disconnect
    add xdi, sizeof(POINTER)
    inc ebx
  .endw
  OCall [xsi].OcxClientSiteColl::Collection.DeleteAll

  OCall [xsi].OcxClientSiteColl::Collection.Done

  SAFE_RELEASE_AND_NULLIFY [xsi].pIFontDisp
  SAFE_RELEASE_AND_NULLIFY [xsi].pIStorageRoot
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OcxContainer.Init
; Purpose:    Initialize the OcxContainer object.
; Arguments:  Arg1: -> Owner.
;             Arg2: Container Window handle. It acts as parent for all control windows.
; Return:     eax = OBJ_OK if succeeded.

Method OcxContainer.Init, uses xsi, pOwner:POINTER, hWndSite:HANDLE
  local FD:FONTDESC

  SetObject xsi
  ACall xsi.Init, pOwner
  m2m [xsi].hWndSite, hWndSite, xax
  OCall [xsi].OcxClientSiteColl::Collection.Init, xsi, 10, 10, COL_MAX_CAPACITY

  mov FD.cbSizeofstruct, sizeof FONTDESC
  c2m FD.lpstrName, $OfsCStrW("MS Sans Serif"), xax
  mov FD.cySize.Lo, 100000                              ;Points * 10000
  m2z FD.cySize.Hi
  mov FD.sWeight, FW_NORMAL
  mov FD.sCharset, ANSI_CHARSET
  mov FD.fItalic, -1
  mov FD.fUnderline, FALSE
  mov FD.fStrikethrough, FALSE
  invoke OleCreateFontIndirect, addr FD, offset IID_IFontDisp, addr [xsi].pIFontDisp

  invoke GetUserDefaultLCID
  mov [xsi].dUserLocaleID, eax

  invoke StgCreateDocfile, NULL, SHAREFLAGS, 0, addr [xsi].pIStorageRoot
  if DEBUGGING
    .if FAILED(eax)
      DbgComError eax
    .endif
  endif

  xor eax, eax                                          ;OBJ_OK
MethodEnd

endif
