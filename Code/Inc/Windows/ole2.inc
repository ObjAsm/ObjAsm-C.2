;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\ole2.h', last modified: 19/04/2018 10:43
;Creation parameters: 

include winapifamily.inc
if _MSC_VER ge 1200
endif
if  not Defined(_OLE2_H_)
  _OLE2_H_ equ <>
  if _MSC_VER gt 1000
  endif
  include pshpack8.inc
  ifndef WIN32
    WIN32 equ 100
  endif
  include winerror.inc
  include objbase.inc
  include oleauto.inc
  include coml2api.inc
  E_DRAW equ <VIEW_E_DRAW>
  DATA_E_FORMATETC equ <DV_E_FORMATETC>
  OLEIVERB_PRIMARY equ 0
  OLEIVERB_SHOW equ -1
  OLEIVERB_OPEN equ -2
  OLEIVERB_HIDE equ -3
  OLEIVERB_UIACTIVATE equ -4
  OLEIVERB_INPLACEACTIVATE equ -5
  OLEIVERB_DISCARDUNDOSTATE equ -6
  EMBDHLP_INPROC_HANDLER equ 0000h
  EMBDHLP_INPROC_SERVER equ 0001h
  EMBDHLP_CREATENOW equ 00000000h
  EMBDHLP_DELAYCREATE equ 00010000h
  OLECREATE_LEAVERUNNING equ 00000001h
  include oleidl.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if  not Defined(ISOLATION_AWARE_ENABLED) or  not ISOLATION_AWARE_ENABLED or  not Defined(_OBJBASE_H_) or  not Defined(CreateDataAdviseHolder)
;      @DefProto DllImport, CreateDataAdviseHolder, WIN_STD_CALL_CONV,, <:ptr LPDATAADVISEHOLDER>, 4
    endif
    @DefProto DllImport, OleBuildVersion, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, WriteFmtUserTypeStg, WIN_STD_CALL_CONV,, <:LPSTORAGE, :CLIPFORMAT, :LPOLESTR>, 12
    @DefProto DllImport, ReadFmtUserTypeStg, WIN_STD_CALL_CONV,, <:LPSTORAGE, :ptr CLIPFORMAT, :ptr LPOLESTR>, 12
    @DefProto DllImport, OleInitialize, WIN_STD_CALL_CONV,, <:LPVOID>, 4
    @DefProto DllImport, OleUninitialize, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, OleQueryLinkFromData, WIN_STD_CALL_CONV,, <:LPDATAOBJECT>, 4
    @DefProto DllImport, OleQueryCreateFromData, WIN_STD_CALL_CONV,, <:LPDATAOBJECT>, 4
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
    @DefProto DllImport, RegisterDragDrop, WIN_STD_CALL_CONV,, <:HWND, :LPDROPTARGET>, 8
    @DefProto DllImport, RevokeDragDrop, WIN_STD_CALL_CONV,, <:HWND>, 4
    @DefProto DllImport, DoDragDrop, WIN_STD_CALL_CONV,, <:LPDATAOBJECT, :LPDROPSOURCE, :DWORD, :LPDWORD>, 16
    @DefProto DllImport, OleSetClipboard, WIN_STD_CALL_CONV,, <:LPDATAOBJECT>, 4
    @DefProto DllImport, OleGetClipboard, WIN_STD_CALL_CONV,, <:ptr LPDATAOBJECT>, 4
    if (NTDDI_VERSION ge NTDDI_WIN10_RS1)
      @DefProto DllImport, OleGetClipboardWithEnterpriseInfo, WIN_STD_CALL_CONV,, <:ptr ptr IDataObject, :ptr PWSTR, :ptr PWSTR, :ptr PWSTR, :ptr PWSTR>, 20
    endif
    @DefProto DllImport, OleFlushClipboard, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, OleIsCurrentClipboard, WIN_STD_CALL_CONV,, <:LPDATAOBJECT>, 4
    @DefProto DllImport, OleCreateMenuDescriptor, WIN_STD_CALL_CONV,, <:HMENU, :LPOLEMENUGROUPWIDTHS>, 8
    @DefProto DllImport, OleSetMenuDescriptor, WIN_STD_CALL_CONV,, <:HOLEMENU, :HWND, :HWND, :LPOLEINPLACEFRAME, :LPOLEINPLACEACTIVEOBJECT>, 20
    @DefProto DllImport, OleDestroyMenuDescriptor, WIN_STD_CALL_CONV,, <:HOLEMENU>, 4
    @DefProto DllImport, OleTranslateAccelerator, WIN_STD_CALL_CONV,, <:LPOLEINPLACEFRAME, :LPOLEINPLACEFRAMEINFO, :LPMSG>, 12
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
    @DefProto DllImport, OleGetIconOfFile, WIN_STD_CALL_CONV,, <:LPOLESTR, :BOOL>, 8
    @DefProto DllImport, OleGetIconOfClass, WIN_STD_CALL_CONV,, <:REFCLSID, :LPOLESTR, :BOOL>, 12
    @DefProto DllImport, OleMetafilePictFromIconAndLabel, WIN_STD_CALL_CONV,, <:HICON, :LPOLESTR, :LPOLESTR, :UINT>, 16
    @DefProto DllImport, OleRegGetUserType, WIN_STD_CALL_CONV,, <:REFCLSID, :DWORD, :ptr LPOLESTR>, 12
    @DefProto DllImport, OleRegGetMiscStatus, WIN_STD_CALL_CONV,, <:REFCLSID, :DWORD, :ptr DWORD>, 12
    @DefProto DllImport, OleRegEnumFormatEtc, WIN_STD_CALL_CONV,, <:REFCLSID, :DWORD, :ptr LPENUMFORMATETC>, 12
    @DefProto DllImport, OleRegEnumVerbs, WIN_STD_CALL_CONV,, <:REFCLSID, :ptr LPENUMOLEVERB>, 8
    LPOLESTREAM typedef ptr _OLESTREAM
    
    OLESTREAMVTBL struct
      TYPE_Get typedef proto WIN_STD_CALL_CONV :LPOLESTREAM, :ptr, :DWORD
      Get typedef ptr TYPE_Get
      TYPE_Put typedef proto WIN_STD_CALL_CONV :LPOLESTREAM, :ptr, :DWORD
      Put typedef ptr TYPE_Put
    OLESTREAMVTBL ends
    _OLESTREAMVTBL typedef OLESTREAMVTBL
    LPOLESTREAMVTBL typedef ptr OLESTREAMVTBL
    OLESTREAM struct
      lpstbl LPOLESTREAMVTBL ?
    OLESTREAM ends
;    _OLESTREAM typedef OLESTREAM
    @DefProto DllImport, OleConvertOLESTREAMToIStorage, WIN_STD_CALL_CONV,, <:LPOLESTREAM, :LPSTORAGE, :ptr DVTARGETDEVICE>, 12
    @DefProto DllImport, OleConvertIStorageToOLESTREAM, WIN_STD_CALL_CONV,, <:LPSTORAGE, :LPOLESTREAM>, 8
    @DefProto DllImport, OleDoAutoConvert, WIN_STD_CALL_CONV,, <:LPSTORAGE, :LPCLSID>, 8
    @DefProto DllImport, OleGetAutoConvert, WIN_STD_CALL_CONV,, <:REFCLSID, :LPCLSID>, 8
    @DefProto DllImport, OleSetAutoConvert, WIN_STD_CALL_CONV,, <:REFCLSID, :REFCLSID>, 8
    @DefProto DllImport, SetConvertStg, WIN_STD_CALL_CONV,, <:LPSTORAGE, :BOOL>, 8
    @DefProto DllImport, OleConvertIStorageToOLESTREAMEx, WIN_STD_CALL_CONV,, <:LPSTORAGE, :CLIPFORMAT, :LONG, :LONG, :DWORD, :LPSTGMEDIUM, :LPOLESTREAM>, 28
    @DefProto DllImport, OleConvertOLESTREAMToIStorageEx, WIN_STD_CALL_CONV,, <:LPOLESTREAM, :LPSTORAGE, :ptr CLIPFORMAT, :ptr LONG, :ptr LONG, :ptr DWORD, :LPSTGMEDIUM>, 28
  endif
  ifndef RC_INVOKED
    include poppack.inc
  endif
endif
if _MSC_VER ge 1200
endif

