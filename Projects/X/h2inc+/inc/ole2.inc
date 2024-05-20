;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\ole2.h
;             Created on (UTC) 06/04/2024 06:15:57
;             Last modified on (UTC) 21/02/2024 18:13:14

include winapifamily.inc
if _MSC_VER ge 1200
  ;* nonstandard extension : single line comment *
endif
;+---------------------------------------------------------------------------
;  Microsoft Windows
;  Copyright (c) Microsoft Corporation. All rights reserved.
;  File:       OLE2.h
;  Contents:   Main OLE2 header; Defines Linking and Emmebbeding interfaces, and API's.
;              Also includes .h files for the compobj, and oleauto  subcomponents.
;----------------------------------------------------------------------------
if  not Defined(_OLE2_H_)
  _OLE2_H_ equ <>
  if _MSC_VER gt 1000
  endif
  ; Set packing to 8
  include pshpack8.inc
  ; Make 100% sure WIN32 is defined
  ifndef WIN32
    WIN32 equ 100; 100 == NT version 1.0

  endif
  ; SET to remove _export from interface definitions
  include winerror.inc
  include objbase.inc
  include oleauto.inc
  include coml2api.inc
  ; View OBJECT Error Codes
  E_DRAW equ <VIEW_E_DRAW>
  ; IDataObject Error Codes
  DATA_E_FORMATETC equ <DV_E_FORMATETC>
  ; Common stuff gleamed from OLE.2,
  ;* verbs *
  OLEIVERB_PRIMARY equ (0)
  OLEIVERB_SHOW equ (- 1)
  OLEIVERB_OPEN equ (- 2)
  OLEIVERB_HIDE equ (- 3)
  OLEIVERB_UIACTIVATE equ (- 4)
  OLEIVERB_INPLACEACTIVATE equ (- 5)
  OLEIVERB_DISCARDUNDOSTATE equ (- 6)
  ; for OleCreateEmbeddingHelper flags; roles in low word; options in high word
  EMBDHLP_INPROC_HANDLER equ 0000h
  EMBDHLP_INPROC_SERVER equ 0001h
  EMBDHLP_CREATENOW equ 00000000h
  EMBDHLP_DELAYCREATE equ 00010000h
  ;* extended create function flags *
  OLECREATE_LEAVERUNNING equ 00000001h
  OLESTREAM_CONVERSION_DEFAULT equ 00000000h
  OLESTREAM_CONVERSION_DISABLEOLELINK equ 00000001h
  ;* pull in the MIDL generated header *
  include oleidl.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ;****** DV APIs ***********************************************************
    ;* This function is declared in objbase.h and ole2.h.
    ;IsolationAware support is via objbase.h.
    ;*
    if  not Defined(ISOLATION_AWARE_ENABLED) or  not ISOLATION_AWARE_ENABLED or  not Defined(_OBJBASE_H_) or  not Defined(CreateDataAdviseHolder)
      @DefProto DllImport, CreateDataAdviseHolder, WIN_STD_CALL_CONV,, <:ptr LPDATAADVISEHOLDER>, 4
    endif
    ;****** OLE API Prototypes ************************************************
    @DefProto DllImport, OleBuildVersion, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, WriteFmtUserTypeStg, WIN_STD_CALL_CONV,, <:LPSTORAGE, :CLIPFORMAT, :LPOLESTR>, 12
    @DefProto DllImport, ReadFmtUserTypeStg, WIN_STD_CALL_CONV,, <:LPSTORAGE, :ptr CLIPFORMAT, :ptr LPOLESTR>, 12
    ;* init/term *
    @DefProto DllImport, OleInitialize, WIN_STD_CALL_CONV,, <:LPVOID>, 4
    @DefProto DllImport, OleUninitialize, WIN_STD_CALL_CONV,, <>, 0
    ;* APIs to query whether (Embedded/Linked) object can be created from
    ;the data object *
    @DefProto DllImport, OleQueryLinkFromData, WIN_STD_CALL_CONV,, <:LPDATAOBJECT>, 4
    @DefProto DllImport, OleQueryCreateFromData, WIN_STD_CALL_CONV,, <:LPDATAOBJECT>, 4
    ;* Object creation APIs *
    @DefProto DllImport, OleCreate, WIN_STD_CALL_CONV,, <:REFCLSID, :REFIID, :DWORD, :LPFORMATETC, :LPOLECLIENTSITE, :LPSTORAGE, :ptr LPVOID>, 28
    @DefProto DllImport, OleCreateEx, WIN_STD_CALL_CONV,, <:REFCLSID, :REFIID, :DWORD, :DWORD, :ULONG, :ptr DWORD, :LPFORMATETC, :ptr IAdviseSink, :ptr DWORD, :LPOLECLIENTSITE, :LPSTORAGE, :ptr LPVOID>, 48
    @DefProto DllImport, OleCreateFromData, WIN_STD_CALL_CONV,, <:LPDATAOBJECT, :REFIID, :DWORD, :LPFORMATETC, :LPOLECLIENTSITE, :LPSTORAGE, :ptr LPVOID>, 28
    @DefProto DllImport, OleCreateFromDataEx, WIN_STD_CALL_CONV,, <:LPDATAOBJECT, :REFIID, :DWORD, :DWORD, :ULONG, :ptr DWORD, :LPFORMATETC, :ptr IAdviseSink, :ptr DWORD, :LPOLECLIENTSITE, :LPSTORAGE, :ptr LPVOID>, 48
    @DefProto DllImport, OleCreateLinkFromData, WIN_STD_CALL_CONV,, <:LPDATAOBJECT, :REFIID, :DWORD, :LPFORMATETC, :LPOLECLIENTSITE, :LPSTORAGE, :ptr LPVOID>, 28
    @DefProto DllImport, OleCreateLinkFromDataEx, WIN_STD_CALL_CONV,, <:LPDATAOBJECT, :REFIID, :DWORD, :DWORD, :ULONG, :ptr DWORD, :LPFORMATETC, :ptr IAdviseSink, :ptr DWORD, :LPOLECLIENTSITE, :LPSTORAGE, :ptr LPVOID>, 48
    @DefProto DllImport, OleCreateStaticFromData, WIN_STD_CALL_CONV,, <:LPDATAOBJECT, :REFIID, :DWORD, :LPFORMATETC, :LPOLECLIENTSITE, :LPSTORAGE, :ptr LPVOID>, 28
    @DefProto DllImport, OleCreateLink, WIN_STD_CALL_CONV,, <:LPMONIKER, :REFIID, :DWORD, :LPFORMATETC, :LPOLECLIENTSITE, :LPSTORAGE, :ptr LPVOID>, 28
    @DefProto DllImport, OleCreateLinkEx, WIN_STD_CALL_CONV,, <:LPMONIKER, :REFIID, :DWORD, :DWORD, :ULONG, :ptr DWORD, :LPFORMATETC, :ptr IAdviseSink, :ptr DWORD, :LPOLECLIENTSITE, :LPSTORAGE, :ptr LPVOID>, 48
    @DefProto DllImport, OleCreateLinkToFile, WIN_STD_CALL_CONV,, <:LPCOLESTR, :REFIID, :DWORD, :LPFORMATETC, :LPOLECLIENTSITE, :LPSTORAGE, :ptr LPVOID>, 28
    @DefProto DllImport, OleCreateLinkToFileEx, WIN_STD_CALL_CONV,, <:LPCOLESTR, :REFIID, :DWORD, :DWORD, :ULONG, :ptr DWORD, :LPFORMATETC, :ptr IAdviseSink, :ptr DWORD, :LPOLECLIENTSITE, :LPSTORAGE, :ptr LPVOID>, 48
    @DefProto DllImport, OleCreateFromFile, WIN_STD_CALL_CONV,, <:REFCLSID, :LPCOLESTR, :REFIID, :DWORD, :LPFORMATETC, :LPOLECLIENTSITE, :LPSTORAGE, :ptr LPVOID>, 32
    @DefProto DllImport, OleCreateFromFileEx, WIN_STD_CALL_CONV,, <:REFCLSID, :LPCOLESTR, :REFIID, :DWORD, :DWORD, :ULONG, :ptr DWORD, :LPFORMATETC, :ptr IAdviseSink, :ptr DWORD, :LPOLECLIENTSITE, :LPSTORAGE, :ptr LPVOID>, 52
    @DefProto DllImport, OleLoad, WIN_STD_CALL_CONV,, <:LPSTORAGE, :REFIID, :LPOLECLIENTSITE, :ptr LPVOID>, 16
    @DefProto DllImport, OleSave, WIN_STD_CALL_CONV,, <:LPPERSISTSTORAGE, :LPSTORAGE, :BOOL>, 12
    @DefProto DllImport, OleLoadFromStream, WIN_STD_CALL_CONV,, <:LPSTREAM, :REFIID, :ptr LPVOID>, 12
    @DefProto DllImport, OleSaveToStream, WIN_STD_CALL_CONV,, <:LPPERSISTSTREAM, :LPSTREAM>, 8
    @DefProto DllImport, OleSetContainedObject, WIN_STD_CALL_CONV,, <:LPUNKNOWN, :BOOL>, 8
    @DefProto DllImport, OleNoteObjectVisible, WIN_STD_CALL_CONV,, <:LPUNKNOWN, :BOOL>, 8
    ;* Drag/Drop APIs *
    @DefProto DllImport, RegisterDragDrop, WIN_STD_CALL_CONV,, <:HWND, :LPDROPTARGET>, 8
    @DefProto DllImport, RevokeDragDrop, WIN_STD_CALL_CONV,, <:HWND>, 4
    @DefProto DllImport, DoDragDrop, WIN_STD_CALL_CONV,, <:LPDATAOBJECT, :LPDROPSOURCE, :DWORD, :LPDWORD>, 16
    ;* Clipboard APIs *
    @DefProto DllImport, OleSetClipboard, WIN_STD_CALL_CONV,, <:LPDATAOBJECT>, 4
    @DefProto DllImport, OleGetClipboard, WIN_STD_CALL_CONV,, <:ptr LPDATAOBJECT>, 4
    if (NTDDI_VERSION ge NTDDI_WIN10_RS1)
      @DefProto DllImport, OleGetClipboardWithEnterpriseInfo, WIN_STD_CALL_CONV,, <:ptr ptr IDataObject, :ptr PWSTR, :ptr PWSTR, :ptr PWSTR, :ptr PWSTR>, 20
    endif
    @DefProto DllImport, OleFlushClipboard, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, OleIsCurrentClipboard, WIN_STD_CALL_CONV,, <:LPDATAOBJECT>, 4
    ;* InPlace Editing APIs *
    @DefProto DllImport, OleCreateMenuDescriptor, WIN_STD_CALL_CONV,, <:HMENU, :LPOLEMENUGROUPWIDTHS>, 8
    @DefProto DllImport, OleSetMenuDescriptor, WIN_STD_CALL_CONV,, <:HOLEMENU, :HWND, :HWND, :LPOLEINPLACEFRAME, :LPOLEINPLACEACTIVEOBJECT>, 20
    @DefProto DllImport, OleDestroyMenuDescriptor, WIN_STD_CALL_CONV,, <:HOLEMENU>, 4
    @DefProto DllImport, OleTranslateAccelerator, WIN_STD_CALL_CONV,, <:LPOLEINPLACEFRAME, :LPOLEINPLACEFRAMEINFO, :LPMSG>, 12
    ;* Helper APIs *
    @DefProto DllImport, OleDuplicateData, WIN_STD_CALL_CONV,, <:HANDLE, :CLIPFORMAT, :UINT>, 12
    @DefProto DllImport, OleDraw, WIN_STD_CALL_CONV,, <:LPUNKNOWN, :DWORD, :HDC, :LPCRECT>, 16
    @DefProto DllImport, OleRun, WIN_STD_CALL_CONV,, <:LPUNKNOWN>, 4
    @DefProto DllImport, OleIsRunning, WIN_STD_CALL_CONV,, <:LPOLEOBJECT>, 4
    @DefProto DllImport, OleLockRunning, WIN_STD_CALL_CONV,, <:LPUNKNOWN, :BOOL, :BOOL>, 12
    @DefProto DllImport, ReleaseStgMedium, WIN_STD_CALL_CONV,, <:LPSTGMEDIUM>, 4
    @DefProto DllImport, CreateOleAdviseHolder, WIN_STD_CALL_CONV,, <:ptr LPOLEADVISEHOLDER>, 4
    @DefProto DllImport, OleCreateDefaultHandler, WIN_STD_CALL_CONV,, <:REFCLSID, :LPUNKNOWN, :REFIID, :ptr LPVOID>, 16
    @DefProto DllImport, OleCreateEmbeddingHelper, WIN_STD_CALL_CONV,, <:REFCLSID, :LPUNKNOWN, :DWORD, :LPCLASSFACTORY, :REFIID, :ptr LPVOID>, 24
    @DefProto DllImport, IsAccelerator, WIN_STD_CALL_CONV,, <:HACCEL, :SDWORD, :LPMSG, :ptr WORD>, 16
    ;* Icon extraction Helper APIs *
    @DefProto DllImport, OleGetIconOfFile, WIN_STD_CALL_CONV,, <:LPOLESTR, :BOOL>, 8
    @DefProto DllImport, OleGetIconOfClass, WIN_STD_CALL_CONV,, <:REFCLSID, :LPOLESTR, :BOOL>, 12
    @DefProto DllImport, OleMetafilePictFromIconAndLabel, WIN_STD_CALL_CONV,, <:HICON, :LPOLESTR, :LPOLESTR, :UINT>, 16
    ;* Registration Database Helper APIs *
    @DefProto DllImport, OleRegGetUserType, WIN_STD_CALL_CONV,, <:REFCLSID, :DWORD, :ptr LPOLESTR>, 12
    @DefProto DllImport, OleRegGetMiscStatus, WIN_STD_CALL_CONV,, <:REFCLSID, :DWORD, :ptr DWORD>, 12
    @DefProto DllImport, OleRegEnumFormatEtc, WIN_STD_CALL_CONV,, <:REFCLSID, :DWORD, :ptr LPENUMFORMATETC>, 12
    @DefProto DllImport, OleRegEnumVerbs, WIN_STD_CALL_CONV,, <:REFCLSID, :ptr LPENUMOLEVERB>, 8
    ;* OLE 1.0 conversion APIS *
    ;***** OLE 1.0 OLESTREAM declarations *************************************
    LPOLESTREAM typedef ptr _OLESTREAM
    TYPE_Get typedef proto WIN_STD_CALL_CONV :LPOLESTREAM, :ptr, :DWORD
    Get typedef ptr TYPE_Get

    DWORD proto WIN_STD_CALL_CONV :ptr CALLBACK
    LPOLESTREAMVTBL typedef ptr OLESTREAMVTBL
    OLESTREAM struct
      lpstbl LPOLESTREAMVTBL ?
    OLESTREAM ends
    _OLESTREAM typedef OLESTREAM
    TYPE_OLESTREAMQUERYCONVERTOLELINKCALLBACK typedef proto WIN_STD_CALL_CONV :LPCLSID, :LPOLESTR, :LPOLESTR, :LPOLESTR, :LPOLESTR, :ULONG, :PVOID
    OLESTREAMQUERYCONVERTOLELINKCALLBACK typedef ptr TYPE_OLESTREAMQUERYCONVERTOLELINKCALLBACK

    @DefProto DllImport, OleConvertOLESTREAMToIStorage, WIN_STD_CALL_CONV,, <:LPOLESTREAM, :LPSTORAGE, :ptr DVTARGETDEVICE>, 12
    @DefProto DllImport, OleConvertOLESTREAMToIStorage2, WIN_STD_CALL_CONV,, <:LPOLESTREAM, :LPSTORAGE, :ptr DVTARGETDEVICE, :DWORD, :PVOID, :OLESTREAMQUERYCONVERTOLELINKCALLBACK>, 24
    @DefProto DllImport, OleConvertIStorageToOLESTREAM, WIN_STD_CALL_CONV,, <:LPSTORAGE, :LPOLESTREAM>, 8
    ;* ConvertTo APIS *
    @DefProto DllImport, OleDoAutoConvert, WIN_STD_CALL_CONV,, <:LPSTORAGE, :LPCLSID>, 8
    @DefProto DllImport, OleGetAutoConvert, WIN_STD_CALL_CONV,, <:REFCLSID, :LPCLSID>, 8
    @DefProto DllImport, OleSetAutoConvert, WIN_STD_CALL_CONV,, <:REFCLSID, :REFCLSID>, 8
    @DefProto DllImport, SetConvertStg, WIN_STD_CALL_CONV,, <:LPSTORAGE, :BOOL>, 8
    @DefProto DllImport, OleConvertIStorageToOLESTREAMEx, WIN_STD_CALL_CONV,, <:LPSTORAGE, :CLIPFORMAT, :LONG, :LONG, :DWORD, :LPSTGMEDIUM, :LPOLESTREAM>, 28
    ;      bits
    @DefProto DllImport, OleConvertOLESTREAMToIStorageEx, WIN_STD_CALL_CONV,, <:LPOLESTREAM, :LPSTORAGE, :ptr CLIPFORMAT, :ptr LONG, :ptr LONG, :ptr DWORD, :LPSTGMEDIUM>, 28
    ;      size in bytes
    ;      bits
    @DefProto DllImport, OleConvertOLESTREAMToIStorageEx2, WIN_STD_CALL_CONV,, <:LPOLESTREAM, :LPSTORAGE, :ptr CLIPFORMAT, :ptr LONG, :ptr LONG, :ptr DWORD, :LPSTGMEDIUM, :DWORD, :PVOID, :OLESTREAMQUERYCONVERTOLELINKCALLBACK>, 40
    ;      bits
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  ifndef RC_INVOKED
    include poppack.inc
  endif
  ; RC_INVOKED
endif
; __OLE2_H__
if _MSC_VER ge 1200
endif
