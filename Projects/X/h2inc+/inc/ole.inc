;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\ole.h
;             Created on (UTC) 06/04/2024 06:15:57
;             Last modified on (UTC) 16/12/2023 11:02:00

include winapifamily.inc
;*****************************************************************************\
;*                                                                             *
;* ole.h -       Object Linking and Embedding functions, types, and definitions*
;*                                                                             *
;*               Version 1.0                                                   *
;*                                                                             *
;*               NOTE: windows.h must be #included first                       *
;*                                                                             *
;*               Copyright (c) Microsoft Corporation. All rights reserved.     *
;*                                                                             *
;\*****************************************************************************
ifndef _INC_OLE
  _INC_OLE equ <>
  if _MSC_VER gt 1000
  endif
  ifdef WIN16
    ;* Assume byte packing throughout *
    include pshpack1.inc
  endif
  ifdef __cplusplus
    ;[...]
  endif
  ;* If not included with 3.1 headers... *
  ifndef WINAPI
    WINAPI equ <FAR PASCAL>
    CALLBACK equ <FAR PASCAL>
    LPCSTR equ <LPSTR>
    LRESULT equ <LONG_PTR>
    HGLOBAL equ <HANDLE>
    ;* _INC_WINDOWS *
  endif
  ifdef STRICT
    OLE_LPCSTR equ <LPCSTR>
    OLE_CONST equ <const>
    ;* STRICT *
  else
    OLE_LPCSTR equ <LPSTR>
    OLE_CONST equ <>
    ;* !STRICT *
  endif
  LRESULT equ <LONG_PTR>
  HGLOBAL equ <HANDLE>
  ;* Object types *
  OT_LINK equ 1
  OT_EMBEDDED equ 2
  OT_STATIC equ 3
  ;* activate verbs *
  OLEVERB_PRIMARY equ 0
  ;* target device info structure *
  OLETARGETDEVICE struct
    otdDeviceNameOffset WORD ?
    otdDriverNameOffset WORD ?
    otdPortNameOffset WORD ?
    otdExtDevmodeOffset WORD ?
    otdExtDevmodeSize WORD ?
    otdEnvironmentOffset WORD ?
    otdEnvironmentSize WORD ?
    otdData BYTE 1 dup (?)
  OLETARGETDEVICE ends
  _OLETARGETDEVICE typedef OLETARGETDEVICE
  LPOLETARGETDEVICE typedef ptr OLETARGETDEVICE
  ;* flags used in some methods *
  OF_SET equ 0001h
  OF_GET equ 0002h
  OF_HANDLER equ 0004h
  ;* return codes for OLE functions *
  OLESTATUS typedef SDWORD
  OLE_OK equ 0
  ;* 0   Function operated correctly             *
  OLE_WAIT_FOR_RELEASE equ 1
  ;* 1   Command has been initiated, client      *
  ;*     must wait for release. keep dispatching *
  ;*     messages till OLE_RELESE in callback    *
  OLE_BUSY equ 2
  ;* 2   Tried to execute a method while another *
  ;*     method is in progress.                  *
  OLE_ERROR_PROTECT_ONLY equ 3
  ;* 3   Ole APIs are called in real mode        *
  OLE_ERROR_MEMORY equ 4
  ;* 4   Could not alloc or lock memory          *
  OLE_ERROR_STREAM equ 5
  ;* 5  (OLESTREAM) stream error                 *
  OLE_ERROR_STATIC equ 6
  ;* 6   Non static object expected              *
  OLE_ERROR_BLANK equ 7
  ;* 7   Critical data missing                   *
  OLE_ERROR_DRAW equ 8
  ;* 8   Error while drawing                     *
  OLE_ERROR_METAFILE equ 9
  ;* 9   Invalid metafile                        *
  OLE_ERROR_ABORT equ 10
  ;* 10  Client chose to abort metafile drawing  *
  OLE_ERROR_CLIPBOARD equ 11
  ;* 11  Failed to get/set clipboard data        *
  OLE_ERROR_FORMAT equ 12
  ;* 12  Requested format is not available       *
  OLE_ERROR_OBJECT equ 13
  ;* 13  Not a valid object                      *
  OLE_ERROR_OPTION equ 14
  ;* 14  Invalid option(link update / render)    *
  OLE_ERROR_PROTOCOL equ 15
  ;* 15  Invalid protocol                        *
  OLE_ERROR_ADDRESS equ 16
  ;* 16  One of the pointers is invalid          *
  OLE_ERROR_NOT_EQUAL equ 17
  ;* 17  Objects are not equal                   *
  OLE_ERROR_HANDLE equ 18
  ;* 18  Invalid handle encountered              *
  OLE_ERROR_GENERIC equ 19
  ;* 19  Some general error                      *
  OLE_ERROR_CLASS equ 20
  ;* 20  Invalid class                           *
  OLE_ERROR_SYNTAX equ 21
  ;* 21  Command syntax is invalid               *
  OLE_ERROR_DATATYPE equ 22
  ;* 22  Data format is not supported            *
  OLE_ERROR_PALETTE equ 23
  ;* 23  Invalid color palette                   *
  OLE_ERROR_NOT_LINK equ 24
  ;* 24  Not a linked object                     *
  OLE_ERROR_NOT_EMPTY equ 25
  ;* 25  Client doc contains objects.            *
  OLE_ERROR_SIZE equ 26
  ;* 26  Incorrect buffer size passed to the api *
  ;*     that places some string in caller's     *
  ;*     buffer                                  *
  OLE_ERROR_DRIVE equ 27
  ;* 27  Drive letter in doc name is invalid     *
  OLE_ERROR_NETWORK equ 28
  ;* 28  Failed to establish connection to a     *
  ;*     network share on which the document     *
  ;*     is located                              *
  OLE_ERROR_NAME equ 29
  ;* 29  Invalid name(doc name, object name),    *
  ;*     etc.. passed to the APIs                *
  OLE_ERROR_TEMPLATE equ 30
  ;* 30  Server failed to load template          *
  OLE_ERROR_NEW equ 31
  ;* 31  Server failed to create new doc         *
  OLE_ERROR_EDIT equ 32
  ;* 32  Server failed to create embedded        *
  ;*     instance                                *
  OLE_ERROR_OPEN equ 33
  ;* 33  Server failed to open document,         *
  ;*     possible invalid link                   *
  OLE_ERROR_NOT_OPEN equ 34
  ;* 34  Object is not open for editing          *
  OLE_ERROR_LAUNCH equ 35
  ;* 35  Failed to launch server                 *
  OLE_ERROR_COMM equ 36
  ;* 36  Failed to communicate with server       *
  OLE_ERROR_TERMINATE equ 37
  ;* 37  Error in termination                    *
  OLE_ERROR_COMMAND equ 38
  ;* 38  Error in execute                        *
  OLE_ERROR_SHOW equ 39
  ;* 39  Error in show                           *
  OLE_ERROR_DOVERB equ 40
  ;* 40  Error in sending do verb, or invalid    *
  ;*     verb                                    *
  OLE_ERROR_ADVISE_NATIVE equ 41
  ;* 41  Item could be missing                   *
  OLE_ERROR_ADVISE_PICT equ 42
  ;* 42  Item could be missing or server doesn't *
  ;*     this format.                            *
  OLE_ERROR_ADVISE_RENAME equ 43
  ;* 43  Server doesn't support rename           *
  OLE_ERROR_POKE_NATIVE equ 44
  ;* 44  Failure of poking native data to server *
  OLE_ERROR_REQUEST_NATIVE equ 45
  ;* 45  Server failed to render native data     *
  OLE_ERROR_REQUEST_PICT equ 46
  ;* 46  Server failed to render presentation    *
  ;*     data                                    *
  OLE_ERROR_SERVER_BLOCKED equ 47
  ;* 47  Trying to block a blocked server or     *
  ;*     trying to revoke a blocked server       *
  ;*     or document                             *
  OLE_ERROR_REGISTRATION equ 48
  ;* 48  Server is not registered in regestation *
  ;*     data base                               *
  OLE_ERROR_ALREADY_REGISTERED equ 49
  ;*49  Trying to register same doc multiple    *
  ;*    times                                   *
  OLE_ERROR_TASK equ 50
  ;* 50  Server or client task is invalid        *
  OLE_ERROR_OUTOFDATE equ 51
  ;* 51  Object is out of date                   *
  OLE_ERROR_CANT_UPDATE_CLIENT equ 52
  ;* 52 Embed doc's client doesn't accept       *
  ;*     updates                                 *
  OLE_ERROR_UPDATE equ 53
  ;* 53  erorr while trying to update            *
  OLE_ERROR_SETDATA_FORMAT equ 54
  ;* 54  Server app doesn't understand the       *
  ;*     format given to its SetData method      *
  OLE_ERROR_STATIC_FROM_OTHER_OS equ 55
  ;* 55 trying to load a static object created *
  ;*    on another Operating System           *
  OLE_ERROR_FILE_VER equ 56
  ;*  Following are warnings *
  OLE_WARN_DELETE_DATA equ 1000

  ;*     done with it.                           *
  ;* Codes for CallBack events *
  OLE_NOTIFICATION typedef SDWORD
  OLE_CHANGED equ 0
  ;* 0                                             *
  OLE_SAVED equ 1
  ;* 1                                             *
  OLE_CLOSED equ 2
  ;* 2                                             *
  OLE_RENAMED equ 3
  ;* 3                                             *
  OLE_QUERY_PAINT equ 4
  ;* 4  Interruptible paint support                *
  OLE_RELEASE equ 5
  ;* 5  Object is released(asynchronous operation  *
  ;*    is completed)                              *
  OLE_QUERY_RETRY equ 6

  ;* 6  Query for retry when server sends busy ACK *
  OLE_RELEASE_METHOD typedef SDWORD
  OLE_NONE equ 0
  ;* 0  no method active                           *
  OLE_DELETE equ 1
  ;* 1  object delete                              *
  OLE_LNKPASTE equ 2
  ;* 2  PasteLink(auto reconnect)                  *
  OLE_EMBPASTE equ 3
  ;* 3  paste(and update)                          *
  OLE_SHOW equ 4
  ;* 4  Show                                       *
  OLE_RUN equ 5
  ;* 5  Run                                        *
  OLE_ACTIVATE equ 6
  ;* 6  Activate                                   *
  OLE_UPDATE equ 7
  ;* 7  Update                                     *
  OLE_CLOSE equ 8
  ;* 8  Close                                      *
  OLE_RECONNECT equ 9
  ;* 9  Reconnect                                  *
  OLE_SETUPDATEOPTIONS equ 10
  ;* 10 setting update options                     *
  OLE_SERVERUNLAUNCH equ 11
  ;* 11 server is being unlaunched                 *
  OLE_LOADFROMSTREAM equ 12
  ;* 12 LoadFromStream(auto reconnect)             *
  OLE_SETDATA equ 13
  ;* 13 OleSetData                                 *
  OLE_REQUESTDATA equ 14
  ;* 14 OleRequestData                             *
  OLE_OTHER equ 15
  ;* 15 other misc async operations                *
  OLE_CREATE equ 16
  ;* 16 create                                     *
  OLE_CREATEFROMTEMPLATE equ 17
  ;* 17 CreatefromTemplate                         *
  OLE_CREATELINKFROMFILE equ 18
  ;* 18 CreateLinkFromFile                         *
  OLE_COPYFROMLNK equ 19
  ;* 19 CopyFromLink(auto reconnect)               *
  OLE_CREATEFROMFILE equ 20
  ;* 20 CreateFromFile                             *
  OLE_CREATEINVISIBLE equ 21

  ;* 21 CreateInvisible                            *
  ;* rendering options *
  OLEOPT_RENDER typedef SDWORD
  olerender_none equ 0
  olerender_draw equ 1
  olerender_format equ 2

  ;* standard clipboard format type *
  OLECLIPFORMAT typedef WORD
  ;* Link update options *
  OLEOPT_UPDATE typedef SDWORD
  oleupdate_always equ 0
  oleupdate_onsave equ 1
  ifdef OLE_INTERNAL
    oleupdate_oncall equ 2
    oleupdate_oncloseelse
    ;* OLE_INTERNAL *
  endif
   equ 3

  HOBJECT typedef HANDLE
  LHSERVER typedef LONG_PTR
  LHCLIENTDOC typedef LONG_PTR
  LHSERVERDOC typedef LONG_PTR
  LPOLEOBJECT typedef ptr _OLEOBJECT
  LPOLESTREAM typedef ptr _OLESTREAM
  LPOLECLIENT typedef ptr _OLECLIENT
  ;* object method table definitions. *
  TYPE_QueryProtocol typedef proto WIN_STD_CALL_CONV :LPOLEOBJECT, :OLE_LPCSTR
  QueryProtocol typedef ptr TYPE_QueryProtocol

  OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
  OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
  OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
  OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
  OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
  OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
  OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
  EnumFormats proto WIN_STD_CALL_CONV :LPOLEOBJECT, :OLECLIPFORMAT
  OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
  ;* Server has to implement only the above methods. *
  ifndef SERVERONLY
    ;* Extra methods required for client. *
    OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
    OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
    OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
    OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
    OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
    OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
    OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
    OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
    OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
    OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
    OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
    OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
    OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
    OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
    OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
    OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
    OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
    OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
    OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
    OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
    OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
    OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
    OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
    OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
    OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
    OLE_RELEASE_METHOD proto WIN_STD_CALL_CONV :ptr CALLBACK
    OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
    OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
    ;* This method is internal only *
    OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
    ;* !SERVERONLY *
  endif
  LPOLEOBJECTVTBL typedef ptr OLEOBJECTVTBL
  ifndef OLE_INTERNAL
    OLEOBJECT struct
      lpvtbl LPOLEOBJECTVTBL ?
    OLEOBJECT ends
    _OLEOBJECT typedef OLEOBJECT
  endif
  ;* ole client definitions *
  TYPE_CallBack typedef proto WIN_STD_CALL_CONV :LPOLECLIENT, :OLE_NOTIFICATION, :LPOLEOBJECT
  CallBack typedef ptr TYPE_CallBack

  LPOLECLIENTVTBL typedef ptr OLECLIENTVTBL
  OLECLIENT struct
    lpvtbl LPOLECLIENTVTBL ?
  OLECLIENT ends
  _OLECLIENT typedef OLECLIENT
  ;* Stream definitions *
  TYPE_Get typedef proto WIN_STD_CALL_CONV :LPOLESTREAM, :ptr, :DWORD
  Get typedef ptr TYPE_Get

  DWORD proto WIN_STD_CALL_CONV :ptr CALLBACK
  LPOLESTREAMVTBL typedef ptr OLESTREAMVTBL
  OLESTREAM struct
    lpstbl LPOLESTREAMVTBL ?
  OLESTREAM ends
  _OLESTREAM typedef OLESTREAM
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ;* Public Function Prototypes *
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
    ;* Routines related to asynchronous operations. *
    OleQueryReleaseStatus proto WIN_STD_CALL_CONV :LPOLEOBJECT
    OleQueryReleaseError proto WIN_STD_CALL_CONV :LPOLEOBJECT
    OleQueryReleaseMethod proto WIN_STD_CALL_CONV :LPOLEOBJECT
    OleQueryType proto WIN_STD_CALL_CONV :LPOLEOBJECT, :ptr LONG
    ;* LOWORD is major version, HIWORD is minor version *
    OleQueryClientVersion proto WIN_STD_CALL_CONV
    OleQueryServerVersion proto WIN_STD_CALL_CONV
    ;* Converting to format (as in clipboard): *
    OleEnumFormats proto WIN_STD_CALL_CONV :LPOLEOBJECT, :OLECLIPFORMAT
    OleGetData proto WIN_STD_CALL_CONV :LPOLEOBJECT, :OLECLIPFORMAT, :ptr HANDLE
    OleSetData proto WIN_STD_CALL_CONV :LPOLEOBJECT, :OLECLIPFORMAT, :HANDLE
    OleQueryOutOfDate proto WIN_STD_CALL_CONV :LPOLEOBJECT
    OleRequestData proto WIN_STD_CALL_CONV :LPOLEOBJECT, :OLECLIPFORMAT
    ;* Query apis for creation from clipboard *
    OleQueryLinkFromClip proto WIN_STD_CALL_CONV :LPCSTR, :OLEOPT_RENDER, :OLECLIPFORMAT
    OleQueryCreateFromClip proto WIN_STD_CALL_CONV :LPCSTR, :OLEOPT_RENDER, :OLECLIPFORMAT
    ;* Object creation functions *
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
    ;* client document API *
    OleRegisterClientDoc proto WIN_STD_CALL_CONV :LPCSTR, :LPCSTR, :LONG, :ptr LHCLIENTDOC
    OleRevokeClientDoc proto WIN_STD_CALL_CONV :LHCLIENTDOC
    OleRenameClientDoc proto WIN_STD_CALL_CONV :LHCLIENTDOC, :LPCSTR
    OleRevertClientDoc proto WIN_STD_CALL_CONV :LHCLIENTDOC
    OleSavedClientDoc proto WIN_STD_CALL_CONV :LHCLIENTDOC
    OleEnumObjects proto WIN_STD_CALL_CONV :LHCLIENTDOC, :ptr LPOLEOBJECT
    ;* server usage definitions *
    OLE_SERVER_USE typedef SDWORD
    OLE_SERVER_MULTI equ 0
    ;* multiple instances *
    OLE_SERVER_SINGLE equ 1

    ;* single instance(multiple document) *
    ;* Server API *
    LPOLESERVER typedef ptr _OLESERVER
    OleRegisterServer proto WIN_STD_CALL_CONV :LPCSTR, :LPOLESERVER, :ptr LHSERVER, :HINSTANCE, :OLE_SERVER_USE
    OleRevokeServer proto WIN_STD_CALL_CONV :LHSERVER
    OleBlockServer proto WIN_STD_CALL_CONV :LHSERVER
    OleUnblockServer proto WIN_STD_CALL_CONV :LHSERVER, :ptr BOOL
    ;* APIs to keep server open *
    OleLockServer proto WIN_STD_CALL_CONV :LPOLEOBJECT, :ptr LHSERVER
    OleUnlockServer proto WIN_STD_CALL_CONV :LHSERVER
    ;* Server document API *
    LPOLESERVERDOC typedef ptr _OLESERVERDOC
    OleRegisterServerDoc proto WIN_STD_CALL_CONV :LHSERVER, :LPCSTR, :LPOLESERVERDOC, :ptr LHSERVERDOC
    OleRevokeServerDoc proto WIN_STD_CALL_CONV :LHSERVERDOC
    OleRenameServerDoc proto WIN_STD_CALL_CONV :LHSERVERDOC, :LPCSTR
    OleRevertServerDoc proto WIN_STD_CALL_CONV :LHSERVERDOC
    OleSavedServerDoc proto WIN_STD_CALL_CONV :LHSERVERDOC
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  TYPE_Open typedef proto WIN_STD_CALL_CONV :LPOLESERVER, :LHSERVERDOC, :OLE_LPCSTR, :ptr LPOLESERVERDOC
  Open typedef ptr TYPE_Open

  ;* long handle to doc(privtate to DLL)  *
  ;* lp to OLESERVER                      *
  ;* document name                        *
  ;* place holder for returning oledoc.   *
  OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
  ;* long handle to doc(privtate to DLL)  *
  ;* lp to OLESERVER                      *
  ;* lp class name                        *
  ;* lp doc name                          *
  ;* place holder for returning oledoc.   *
  OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
  ;* long handle to doc(privtate to DLL)  *
  ;* lp to OLESERVER                      *
  ;* lp class name                        *
  ;* lp doc name                          *
  ;* lp template name                     *
  ;* place holder for returning oledoc.   *
  OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
  ;* long handle to doc(privtate to DLL)  *
  ;* lp to OLESERVER                      *
  ;* lp class name                        *
  ;* lp doc name                          *
  ;* place holder for returning oledoc.   *
  OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
  ;* lp OLESERVER                         *
  OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
  ;* lp OLESERVER                         *
  OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
  ;* lp OLESERVER                         *
  ;* handle to command strings            *
  LPOLESERVERVTBL typedef ptr OLESERVERVTBL
  OLESERVER struct
    lpvtbl LPOLESERVERVTBL ?
  OLESERVER ends
  _OLESERVER typedef OLESERVER
  TYPE_Save typedef proto WIN_STD_CALL_CONV :LPOLESERVERDOC
  Save typedef ptr TYPE_Save

  OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
  OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
  OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
  OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
  OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
  OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
  OLESTATUS proto WIN_STD_CALL_CONV :ptr CALLBACK
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
  ;* !_INC_OLE *
endif
