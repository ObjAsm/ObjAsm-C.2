;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\ole.h', last modified: 19/04/2018 21:50
;Creation parameters: 

include winapifamily.inc
ifndef _INC_OLE
  _INC_OLE equ <>
  if _MSC_VER gt 1000
  endif
  ifdef WIN16
    include pshpack1.inc
  endif
  ifdef __cplusplus
    ;[...]
  endif
  ifndef WINAPI
    WINAPI equ <FAR PASCAL>
    CALLBACK equ <FAR PASCAL>
    LPCSTR equ <LPSTR>
    LRESULT equ <LONG_PTR>
    HGLOBAL equ <HANDLE>
  endif
  ifdef STRICT
    OLE_LPCSTR equ <LPCSTR>
    OLE_CONST equ <>
  else
    OLE_LPCSTR equ <LPSTR>
    OLE_CONST equ <>
  endif
  LRESULT equ <LONG_PTR>
  HGLOBAL equ <HANDLE>
  OT_LINK equ 1
  OT_EMBEDDED equ 2
  OT_STATIC equ 3
  OLEVERB_PRIMARY equ 0
  OLETARGETDEVICE struct
    otdDeviceNameOffset USHORT ?
    otdDriverNameOffset USHORT ?
    otdPortNameOffset USHORT ?
    otdExtDevmodeOffset USHORT ?
    otdExtDevmodeSize USHORT ?
    otdEnvironmentOffset USHORT ?
    otdEnvironmentSize USHORT ?
    otdData BYTE 1 dup (?)
  OLETARGETDEVICE ends
  _OLETARGETDEVICE typedef OLETARGETDEVICE
  LPOLETARGETDEVICE typedef ptr OLETARGETDEVICE
  OF_SET equ 0001h
  OF_GET equ 0002h
  OF_HANDLER equ 0004h
  OLESTATUS typedef SDWORD
  OLE_OK equ 0
  OLE_WAIT_FOR_RELEASE equ 1
  OLE_BUSY equ 2
  OLE_ERROR_PROTECT_ONLY equ 3
  OLE_ERROR_MEMORY equ 4
  OLE_ERROR_STREAM equ 5
  OLE_ERROR_STATIC equ 6
  OLE_ERROR_BLANK equ 7
  OLE_ERROR_DRAW equ 8
  OLE_ERROR_METAFILE equ 9
  OLE_ERROR_ABORT equ 10
  OLE_ERROR_CLIPBOARD equ 11
  OLE_ERROR_FORMAT equ 12
  OLE_ERROR_OBJECT equ 13
  OLE_ERROR_OPTION equ 14
  OLE_ERROR_PROTOCOL equ 15
  OLE_ERROR_ADDRESS equ 16
  OLE_ERROR_NOT_EQUAL equ 17
  OLE_ERROR_HANDLE equ 18
  OLE_ERROR_GENERIC equ 19
  OLE_ERROR_CLASS equ 20
  OLE_ERROR_SYNTAX equ 21
  OLE_ERROR_DATATYPE equ 22
  OLE_ERROR_PALETTE equ 23
  OLE_ERROR_NOT_LINK equ 24
  OLE_ERROR_NOT_EMPTY equ 25
  OLE_ERROR_SIZE equ 26
  OLE_ERROR_DRIVE equ 27
  OLE_ERROR_NETWORK equ 28
  OLE_ERROR_NAME equ 29
  OLE_ERROR_TEMPLATE equ 30
  OLE_ERROR_NEW equ 31
  OLE_ERROR_EDIT equ 32
  OLE_ERROR_OPEN equ 33
  OLE_ERROR_NOT_OPEN equ 34
  OLE_ERROR_LAUNCH equ 35
  OLE_ERROR_COMM equ 36
  OLE_ERROR_TERMINATE equ 37
  OLE_ERROR_COMMAND equ 38
  OLE_ERROR_SHOW equ 39
  OLE_ERROR_DOVERB equ 40
  OLE_ERROR_ADVISE_NATIVE equ 41
  OLE_ERROR_ADVISE_PICT equ 42
  OLE_ERROR_ADVISE_RENAME equ 43
  OLE_ERROR_POKE_NATIVE equ 44
  OLE_ERROR_REQUEST_NATIVE equ 45
  OLE_ERROR_REQUEST_PICT equ 46
  OLE_ERROR_SERVER_BLOCKED equ 47
  OLE_ERROR_REGISTRATION equ 48
  OLE_ERROR_ALREADY_REGISTERED equ 49
  OLE_ERROR_TASK equ 50
  OLE_ERROR_OUTOFDATE equ 51
  OLE_ERROR_CANT_UPDATE_CLIENT equ 52
  OLE_ERROR_UPDATE equ 53
  OLE_ERROR_SETDATA_FORMAT equ 54
  OLE_ERROR_STATIC_FROM_OTHER_OS equ 55
  OLE_ERROR_FILE_VER equ 56
  OLE_WARN_DELETE_DATA equ 1000
  
  OLE_NOTIFICATION typedef SDWORD
  OLE_CHANGED equ 0
  OLE_SAVED equ 1
  OLE_CLOSED equ 2
  OLE_RENAMED equ 3
  OLE_QUERY_PAINT equ 4
  OLE_RELEASE equ 5
  OLE_QUERY_RETRY equ 6
  
  OLE_RELEASE_METHOD typedef SDWORD
  OLE_NONE equ 0
  OLE_DELETE equ 1
  OLE_LNKPASTE equ 2
  OLE_EMBPASTE equ 3
  OLE_SHOW equ 4
  OLE_RUN equ 5
  OLE_ACTIVATE equ 6
  OLE_UPDATE equ 7
  OLE_CLOSE equ 8
  OLE_RECONNECT equ 9
  OLE_SETUPDATEOPTIONS equ 10
  OLE_SERVERUNLAUNCH equ 11
  OLE_LOADFROMSTREAM equ 12
  OLE_SETDATA equ 13
  OLE_REQUESTDATA equ 14
  OLE_OTHER equ 15
  OLE_CREATE equ 16
  OLE_CREATEFROMTEMPLATE equ 17
  OLE_CREATELINKFROMFILE equ 18
  OLE_COPYFROMLNK equ 19
  OLE_CREATEFROMFILE equ 20
  OLE_CREATEINVISIBLE equ 21
  
  OLEOPT_RENDER typedef SDWORD
  olerender_none equ 0
  olerender_draw equ 1
  olerender_format equ 2
  
  OLECLIPFORMAT typedef WORD
  OLEOPT_UPDATE typedef SDWORD
  oleupdate_always equ 0
  oleupdate_onsave equ 1
  ifdef OLE_INTERNAL
    oleupdate_oncall equ 2
    oleupdate_onclose
  else
  endif
   equ 3
  
  HOBJECT typedef HANDLE
  LHSERVER typedef LONG_PTR
  LHCLIENTDOC typedef LONG_PTR
  LHSERVERDOC typedef LONG_PTR
  LPOLEOBJECT typedef ptr _OLEOBJECT
  
  LPOLESTREAM typedef ptr _OLESTREAM
  
  LPOLECLIENT typedef ptr _OLECLIENT
  
  OLEOBJECTVTBL struct
    TYPE_QueryProtocol typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT, :OLE_LPCSTR
    QueryProtocol typedef ptr TYPE_QueryProtocol
    TYPE_Release typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT
    Release typedef ptr TYPE_Release
    TYPE_Show typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT, :BOOL
    Show typedef ptr TYPE_Show
    TYPE_DoVerb typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT, :UINT, :BOOL, :BOOL
    DoVerb typedef ptr TYPE_DoVerb
    TYPE_GetData typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT, :OLECLIPFORMAT, :ptr HANDLE
    GetData typedef ptr TYPE_GetData
    TYPE_SetData typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT, :OLECLIPFORMAT, :HANDLE
    SetData typedef ptr TYPE_SetData
    TYPE_SetTargetDevice typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT, :HGLOBAL
    SetTargetDevice typedef ptr TYPE_SetTargetDevice
    TYPE_SetBounds typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT, :ptr OLE_CONST
    SetBounds typedef ptr TYPE_SetBounds
    TYPE_EnumFormats typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT, :OLECLIPFORMAT
    EnumFormats typedef ptr TYPE_EnumFormats
    TYPE_SetColorScheme typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT, :ptr OLE_CONST
    SetColorScheme typedef ptr TYPE_SetColorScheme
    ifndef SERVERONLY
      TYPE_Delete typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT
      Delete typedef ptr TYPE_Delete
      TYPE_SetHostNames typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT, :OLE_LPCSTR, :OLE_LPCSTR
      SetHostNames typedef ptr TYPE_SetHostNames
      TYPE_SaveToStream typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT, :LPOLESTREAM
      SaveToStream typedef ptr TYPE_SaveToStream
      TYPE_Clone typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT, :LPOLECLIENT, :LHCLIENTDOC, :OLE_LPCSTR, :ptr LPOLEOBJECT
      Clone typedef ptr TYPE_Clone
      TYPE_CopyFromLink typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT, :LPOLECLIENT, :LHCLIENTDOC, :OLE_LPCSTR, :ptr LPOLEOBJECT
      CopyFromLink typedef ptr TYPE_CopyFromLink
      TYPE_Equal typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT, :LPOLEOBJECT
      Equal typedef ptr TYPE_Equal
      TYPE_CopyToClipboard typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT
      CopyToClipboard typedef ptr TYPE_CopyToClipboard
      TYPE_Draw typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT, :HDC, :ptr OLE_CONST, :ptr OLE_CONST, :HDC
      Draw typedef ptr TYPE_Draw
      TYPE_Activate typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT, :UINT, :BOOL, :BOOL, :HWND, :ptr OLE_CONST
      Activate typedef ptr TYPE_Activate
      TYPE_Execute typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT, :HGLOBAL, :UINT
      Execute typedef ptr TYPE_Execute
      TYPE_Close typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT
      Close typedef ptr TYPE_Close
      TYPE_Update typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT
      Update typedef ptr TYPE_Update
      TYPE_Reconnect typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT
      Reconnect typedef ptr TYPE_Reconnect
      TYPE_ObjectConvert typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT, :OLE_LPCSTR, :LPOLECLIENT, :LHCLIENTDOC, :OLE_LPCSTR, :ptr LPOLEOBJECT
      ObjectConvert typedef ptr TYPE_ObjectConvert
      TYPE_GetLinkUpdateOptions typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT, :ptr OLEOPT_UPDATE
      GetLinkUpdateOptions typedef ptr TYPE_GetLinkUpdateOptions
      TYPE_SetLinkUpdateOptions typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT, :OLEOPT_UPDATE
      SetLinkUpdateOptions typedef ptr TYPE_SetLinkUpdateOptions
      TYPE_Rename typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT, :OLE_LPCSTR
      Rename typedef ptr TYPE_Rename
      TYPE_QueryName typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT, :LPSTR, :ptr UINT
      QueryName typedef ptr TYPE_QueryName
      TYPE_QueryType typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT, :ptr LONG
      QueryType typedef ptr TYPE_QueryType
      TYPE_QueryBounds typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT, :ptr RECT
      QueryBounds typedef ptr TYPE_QueryBounds
      TYPE_QuerySize typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT, :ptr DWORD
      QuerySize typedef ptr TYPE_QuerySize
      TYPE_QueryOpen typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT
      QueryOpen typedef ptr TYPE_QueryOpen
      TYPE_QueryOutOfDate typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT
      QueryOutOfDate typedef ptr TYPE_QueryOutOfDate
      TYPE_QueryReleaseStatus typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT
      QueryReleaseStatus typedef ptr TYPE_QueryReleaseStatus
      TYPE_QueryReleaseError typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT
      QueryReleaseError typedef ptr TYPE_QueryReleaseError
      TYPE_QueryReleaseMethod typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT
      QueryReleaseMethod typedef ptr TYPE_QueryReleaseMethod
      TYPE_RequestData typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT, :OLECLIPFORMAT
      RequestData typedef ptr TYPE_RequestData
      TYPE_ObjectLong typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT, :UINT, :ptr LONG
      ObjectLong typedef ptr TYPE_ObjectLong
      TYPE_ChangeData typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT, :HANDLE, :LPOLECLIENT, :BOOL
      ChangeData typedef ptr TYPE_ChangeData
    endif
  OLEOBJECTVTBL ends
  _OLEOBJECTVTBL typedef OLEOBJECTVTBL
  LPOLEOBJECTVTBL typedef ptr OLEOBJECTVTBL
  ifndef OLE_INTERNAL
    OLEOBJECT struct
      lpvtbl LPOLEOBJECTVTBL ?
    OLEOBJECT ends
    _OLEOBJECT typedef OLEOBJECT
  endif
  OLECLIENTVTBL struct
    TYPE_CallBack typedef proto WIN_STD_CALL_CONV :LPOLECLIENT, :OLE_NOTIFICATION, :LPOLEOBJECT
    CallBack typedef ptr TYPE_CallBack
  OLECLIENTVTBL ends
  _OLECLIENTVTBL typedef OLECLIENTVTBL
  LPOLECLIENTVTBL typedef ptr OLECLIENTVTBL
  OLECLIENT struct
    lpvtbl LPOLECLIENTVTBL ?
  OLECLIENT ends
  _OLECLIENT typedef OLECLIENT
  OLESTREAMVTBL struct
    TYPE_Get typedef proto WIN_STD_CALL_CONV :LPOLESTREAM, :ptr, :DWORD
    Get typedef ptr TYPE_Get
    TYPE_Put typedef proto WIN_STD_CALL_CONV :LPOLESTREAM, :ptr OLE_CONST, :DWORD
    Put typedef ptr TYPE_Put
  OLESTREAMVTBL ends
  _OLESTREAMVTBL typedef OLESTREAMVTBL
  LPOLESTREAMVTBL typedef ptr OLESTREAMVTBL
  OLESTREAM struct
    lpstbl LPOLESTREAMVTBL ?
  OLESTREAM ends
  _OLESTREAM typedef OLESTREAM
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    OleDelete proto WIN_STD_CALL_CONV :LPOLEOBJECT
    OleRelease proto WIN_STD_CALL_CONV :LPOLEOBJECT
    OleSaveToStream proto WIN_STD_CALL_CONV :LPOLEOBJECT, :LPOLESTREAM
    OleEqual proto WIN_STD_CALL_CONV :LPOLEOBJECT, :LPOLEOBJECT
    OleCopyToClipboard proto WIN_STD_CALL_CONV :LPOLEOBJECT
    OleSetHostNames proto WIN_STD_CALL_CONV :LPOLEOBJECT, :LPCSTR, :LPCSTR
    OleSetTargetDevice proto WIN_STD_CALL_CONV :LPOLEOBJECT, :HGLOBAL
    OleSetBounds proto WIN_STD_CALL_CONV :LPOLEOBJECT, :ptr RECT
    OleSetColorScheme proto WIN_STD_CALL_CONV :LPOLEOBJECT, :ptr LOGPALETTE
    OleQueryBounds proto WIN_STD_CALL_CONV :LPOLEOBJECT, :ptr RECT
    OleQuerySize proto WIN_STD_CALL_CONV :LPOLEOBJECT, :ptr DWORD
    OleDraw proto WIN_STD_CALL_CONV :LPOLEOBJECT, :HDC, :ptr RECT, :ptr RECT, :HDC
    OleQueryOpen proto WIN_STD_CALL_CONV :LPOLEOBJECT
    OleActivate proto WIN_STD_CALL_CONV :LPOLEOBJECT, :UINT, :BOOL, :BOOL, :HWND, :ptr RECT
    OleExecute proto WIN_STD_CALL_CONV :LPOLEOBJECT, :HGLOBAL, :UINT
    OleClose proto WIN_STD_CALL_CONV :LPOLEOBJECT
    OleUpdate proto WIN_STD_CALL_CONV :LPOLEOBJECT
    OleReconnect proto WIN_STD_CALL_CONV :LPOLEOBJECT
    OleGetLinkUpdateOptions proto WIN_STD_CALL_CONV :LPOLEOBJECT, :ptr OLEOPT_UPDATE
    OleSetLinkUpdateOptions proto WIN_STD_CALL_CONV :LPOLEOBJECT, :OLEOPT_UPDATE
    OleQueryProtocol proto WIN_STD_CALL_CONV :LPOLEOBJECT, :LPCSTR
    OleQueryReleaseStatus proto WIN_STD_CALL_CONV :LPOLEOBJECT
    OleQueryReleaseError proto WIN_STD_CALL_CONV :LPOLEOBJECT
    OleQueryReleaseMethod proto WIN_STD_CALL_CONV :LPOLEOBJECT
    OleQueryType proto WIN_STD_CALL_CONV :LPOLEOBJECT, :ptr LONG
    OleQueryClientVersion proto WIN_STD_CALL_CONV
    OleQueryServerVersion proto WIN_STD_CALL_CONV
    OleEnumFormats proto WIN_STD_CALL_CONV :LPOLEOBJECT, :OLECLIPFORMAT
    OleGetData proto WIN_STD_CALL_CONV :LPOLEOBJECT, :OLECLIPFORMAT, :ptr HANDLE
    OleSetData proto WIN_STD_CALL_CONV :LPOLEOBJECT, :OLECLIPFORMAT, :HANDLE
    OleQueryOutOfDate proto WIN_STD_CALL_CONV :LPOLEOBJECT
    OleRequestData proto WIN_STD_CALL_CONV :LPOLEOBJECT, :OLECLIPFORMAT
    OleQueryLinkFromClip proto WIN_STD_CALL_CONV :LPCSTR, :OLEOPT_RENDER, :OLECLIPFORMAT
    OleQueryCreateFromClip proto WIN_STD_CALL_CONV :LPCSTR, :OLEOPT_RENDER, :OLECLIPFORMAT
    OleCreateFromClip proto WIN_STD_CALL_CONV :LPCSTR, :LPOLECLIENT, :LHCLIENTDOC, :LPCSTR, :ptr LPOLEOBJECT, :OLEOPT_RENDER, :OLECLIPFORMAT
    OleCreateLinkFromClip proto WIN_STD_CALL_CONV :LPCSTR, :LPOLECLIENT, :LHCLIENTDOC, :LPCSTR, :ptr LPOLEOBJECT, :OLEOPT_RENDER, :OLECLIPFORMAT
    OleCreateFromFile proto WIN_STD_CALL_CONV :LPCSTR, :LPOLECLIENT, :LPCSTR, :LPCSTR, :LHCLIENTDOC, :LPCSTR, :ptr LPOLEOBJECT, :OLEOPT_RENDER, :OLECLIPFORMAT
    OleCreateLinkFromFile proto WIN_STD_CALL_CONV :LPCSTR, :LPOLECLIENT, :LPCSTR, :LPCSTR, :LPCSTR, :LHCLIENTDOC, :LPCSTR, :ptr LPOLEOBJECT, :OLEOPT_RENDER, :OLECLIPFORMAT
    OleLoadFromStream proto WIN_STD_CALL_CONV :LPOLESTREAM, :LPCSTR, :LPOLECLIENT, :LHCLIENTDOC, :LPCSTR, :ptr LPOLEOBJECT
    OleCreate proto WIN_STD_CALL_CONV :LPCSTR, :LPOLECLIENT, :LPCSTR, :LHCLIENTDOC, :LPCSTR, :ptr LPOLEOBJECT, :OLEOPT_RENDER, :OLECLIPFORMAT
    OleCreateInvisible proto WIN_STD_CALL_CONV :LPCSTR, :LPOLECLIENT, :LPCSTR, :LHCLIENTDOC, :LPCSTR, :ptr LPOLEOBJECT, :OLEOPT_RENDER, :OLECLIPFORMAT, :BOOL
    OleCreateFromTemplate proto WIN_STD_CALL_CONV :LPCSTR, :LPOLECLIENT, :LPCSTR, :LHCLIENTDOC, :LPCSTR, :ptr LPOLEOBJECT, :OLEOPT_RENDER, :OLECLIPFORMAT
    OleClone proto WIN_STD_CALL_CONV :LPOLEOBJECT, :LPOLECLIENT, :LHCLIENTDOC, :LPCSTR, :ptr LPOLEOBJECT
    OleCopyFromLink proto WIN_STD_CALL_CONV :LPOLEOBJECT, :LPCSTR, :LPOLECLIENT, :LHCLIENTDOC, :LPCSTR, :ptr LPOLEOBJECT
    OleObjectConvert proto WIN_STD_CALL_CONV :LPOLEOBJECT, :LPCSTR, :LPOLECLIENT, :LHCLIENTDOC, :LPCSTR, :ptr LPOLEOBJECT
    OleRename proto WIN_STD_CALL_CONV :LPOLEOBJECT, :LPCSTR
    OleQueryName proto WIN_STD_CALL_CONV :LPOLEOBJECT, :LPSTR, :ptr UINT
    OleRevokeObject proto WIN_STD_CALL_CONV :LPOLECLIENT
    OleIsDcMeta proto WIN_STD_CALL_CONV :HDC
    OleRegisterClientDoc proto WIN_STD_CALL_CONV :LPCSTR, :LPCSTR, :LONG, :ptr LHCLIENTDOC
    OleRevokeClientDoc proto WIN_STD_CALL_CONV :LHCLIENTDOC
    OleRenameClientDoc proto WIN_STD_CALL_CONV :LHCLIENTDOC, :LPCSTR
    OleRevertClientDoc proto WIN_STD_CALL_CONV :LHCLIENTDOC
    OleSavedClientDoc proto WIN_STD_CALL_CONV :LHCLIENTDOC
    OleEnumObjects proto WIN_STD_CALL_CONV :LHCLIENTDOC, :ptr LPOLEOBJECT
    OLE_SERVER_USE typedef SDWORD
    OLE_SERVER_MULTI equ 0
    OLE_SERVER_SINGLE equ 1
    
    LPOLESERVER typedef ptr _OLESERVER
    
    OleRegisterServer proto WIN_STD_CALL_CONV :LPCSTR, :LPOLESERVER, :ptr LHSERVER, :HINSTANCE, :OLE_SERVER_USE
    OleRevokeServer proto WIN_STD_CALL_CONV :LHSERVER
    OleBlockServer proto WIN_STD_CALL_CONV :LHSERVER
    OleUnblockServer proto WIN_STD_CALL_CONV :LHSERVER, :ptr BOOL
    OleLockServer proto WIN_STD_CALL_CONV :LPOLEOBJECT, :ptr LHSERVER
    OleUnlockServer proto WIN_STD_CALL_CONV :LHSERVER
    LPOLESERVERDOC typedef ptr _OLESERVERDOC
    
    OleRegisterServerDoc proto WIN_STD_CALL_CONV :LHSERVER, :LPCSTR, :LPOLESERVERDOC, :ptr LHSERVERDOC
    OleRevokeServerDoc proto WIN_STD_CALL_CONV :LHSERVERDOC
    OleRenameServerDoc proto WIN_STD_CALL_CONV :LHSERVERDOC, :LPCSTR
    OleRevertServerDoc proto WIN_STD_CALL_CONV :LHSERVERDOC
    OleSavedServerDoc proto WIN_STD_CALL_CONV :LHSERVERDOC
  endif
  OLESERVERVTBL struct
    TYPE_Open typedef proto WIN_STD_CALL_CONV :LPOLESERVER, :LHSERVERDOC, :OLE_LPCSTR, :ptr LPOLESERVERDOC
    Open typedef ptr TYPE_Open
    TYPE_Create typedef proto WIN_STD_CALL_CONV :LPOLESERVER, :LHSERVERDOC, :OLE_LPCSTR, :OLE_LPCSTR, :ptr LPOLESERVERDOC
    Create typedef ptr TYPE_Create
    TYPE_CreateFromTemplate typedef proto WIN_STD_CALL_CONV :LPOLESERVER, :LHSERVERDOC, :OLE_LPCSTR, :OLE_LPCSTR, :OLE_LPCSTR, :ptr LPOLESERVERDOC
    CreateFromTemplate typedef ptr TYPE_CreateFromTemplate
    TYPE_Edit typedef proto WIN_STD_CALL_CONV :LPOLESERVER, :LHSERVERDOC, :OLE_LPCSTR, :OLE_LPCSTR, :ptr LPOLESERVERDOC
    Edit typedef ptr TYPE_Edit
    TYPE_Exit typedef proto WIN_STD_CALL_CONV :LPOLESERVER
    Exit typedef ptr TYPE_Exit
    TYPE_Release typedef proto WIN_STD_CALL_CONV :LPOLESERVER
    Release typedef ptr TYPE_Release
    TYPE_Execute typedef proto WIN_STD_CALL_CONV :LPOLESERVER, :HGLOBAL
    Execute typedef ptr TYPE_Execute
  OLESERVERVTBL ends
  _OLESERVERVTBL typedef OLESERVERVTBL
  LPOLESERVERVTBL typedef ptr OLESERVERVTBL
  OLESERVER struct
    lpvtbl LPOLESERVERVTBL ?
  OLESERVER ends
  _OLESERVER typedef OLESERVER
  OLESERVERDOCVTBL struct
    TYPE_Save typedef proto WIN_STD_CALL_CONV :LPOLESERVERDOC
    Save typedef ptr TYPE_Save
    TYPE_Close typedef proto WIN_STD_CALL_CONV :LPOLESERVERDOC
    Close typedef ptr TYPE_Close
    TYPE_SetHostNames typedef proto WIN_STD_CALL_CONV :LPOLESERVERDOC, :OLE_LPCSTR, :OLE_LPCSTR
    SetHostNames typedef ptr TYPE_SetHostNames
    TYPE_SetDocDimensions typedef proto WIN_STD_CALL_CONV :LPOLESERVERDOC, :ptr OLE_CONST
    SetDocDimensions typedef ptr TYPE_SetDocDimensions
    TYPE_GetObject typedef proto WIN_STD_CALL_CONV :LPOLESERVERDOC, :OLE_LPCSTR, :ptr LPOLEOBJECT, :LPOLECLIENT
    GetObject typedef ptr TYPE_GetObject
    TYPE_Release typedef proto WIN_STD_CALL_CONV :LPOLESERVERDOC
    Release typedef ptr TYPE_Release
    TYPE_SetColorScheme typedef proto WIN_STD_CALL_CONV :LPOLESERVERDOC, :ptr OLE_CONST
    SetColorScheme typedef ptr TYPE_SetColorScheme
    TYPE_Execute typedef proto WIN_STD_CALL_CONV :LPOLESERVERDOC, :HGLOBAL
    Execute typedef ptr TYPE_Execute
  OLESERVERDOCVTBL ends
  _OLESERVERDOCVTBL typedef OLESERVERDOCVTBL
  LPOLESERVERDOCVTBL typedef ptr OLESERVERDOCVTBL
  OLESERVERDOC struct
    lpvtbl LPOLESERVERDOCVTBL ?
  OLESERVERDOC ends
  _OLESERVERDOC typedef OLESERVERDOC
  ifdef __cplusplus
    ;[...]
  endif
  ifdef WIN16
    include poppack.inc
  endif
endif

