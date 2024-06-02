; ==================================================================================================
; Title:      ShObjIDL.inc
; Transl.:    G. Friedrich
; Version:    C.1.0
; Purpose:    COM interfaces for shell objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


COM_INTERFACE_BEG IPersistFolder, IPersist, <000214ea-0000-0000-c000-000000000046>
  COM_MTD_STD   Initialize,                   POINTER
COM_INTERFACE_END


COM_INTERFACE_BEG IPersistFolder2, IPersistFolder, <1ac3d9f0-175c-11d1-95be-00609797ea4f>
  COM_MTD_STD   GetCurFolder,                 POINTER
COM_INTERFACE_END


COM_INTERFACE_BEG IPersistIDList, IPersist, <1079acfc-29bd-11d3-8e0d-00c04f6837d5>
  COM_MTD_STD   SetIDList,                    POINTER
  COM_MTD_STD   GetIDList,                    POINTER
COM_INTERFACE_END


COM_INTERFACE_BEG IEnumIDList, IUnknown, <000214f2-0000-0000-c000-000000000046>
  COM_MTD_STD   Next,                         ULONG, POINTER, POINTER
  COM_MTD_STD   Skip,                         ULONG
  COM_MTD_STD   Reset
  COM_MTD_STD   Clone,                        POINTER
COM_INTERFACE_END


COM_INTERFACE_BEG IShellPropSheetExt, IUnknown, <000214E9-0000-0000-C000-000000000046>
  COM_MTD_STD   AddPages,                     POINTER, LPARAM 
  COM_MTD_STD   ReplacePage,                  DWORD, POINTER, LPARAM
COM_INTERFACE_END


SHGDN_NORMAL              equ   0
SHGDN_INFOLDER            equ   1
SHGDN_FOREDITING          equ   1000h
SHGDN_INCLUDE_NONFILESYS  equ   2000h
SHGDN_FORADDRESSBAR       equ   4000h
SHGDN_FORPARSING          equ   8000h

SHCONTF_CHECKING_FOR_CHILDREN equ   00000010h
SHCONTF_FOLDERS               equ   00000020h
SHCONTF_NONFOLDERS            equ   00000040h
SHCONTF_INCLUDEHIDDEN         equ   00000080h
SHCONTF_INIT_ON_FIRST_NEXT    equ   00000100h
SHCONTF_NETPRINTERSRCH        equ   00000200h
SHCONTF_SHAREABLE             equ   00000400h
SHCONTF_STORAGE               equ   00000800h
SHCONTF_NAVIGATION_ENUM       equ   00001000h
SHCONTF_FASTITEMS             equ   00002000h
SHCONTF_FLATLIST              equ   00004000h
SHCONTF_ENABLE_ASYNC          equ   00008000h
SHCONTF_INCLUDESUPERHIDDEN    equ   00010000h

COM_INTERFACE_BEG IShellFolder, IUnknown, <000214e6-0000-0000-c000-000000000046>
  COM_MTD_STD   ParseDisplayName,             HWND, POINTER, POINTER, POINTER, POINTER, POINTER 
  COM_MTD_STD   EnumObjects,                  HWND, DWORD, POINTER
  COM_MTD_STD   BindToObject,                 POINTER, POINTER, POINTER, POINTER
  COM_MTD_STD   BindToStorage,                POINTER, POINTER, POINTER, POINTER
  COM_MTD_STD   CompareIDs,                   DWORD, POINTER, POINTER
  COM_MTD_STD   CreateViewObject,             HWND, POINTER, POINTER
  COM_MTD_STD   GetAttributesOf,              DWORD, POINTER, POINTER
  COM_MTD_STD   GetUIObjectOf,                HWND, DWORD, POINTER, POINTER, POINTER, POINTER
  COM_MTD_STD   GetDisplayNameOf,             POINTER, DWORD, POINTER
  COM_MTD_STD   SetNameOf,                    HWND, POINTER, POINTER, DWORD, POINTER
COM_INTERFACE_END


EXTRASEARCH struct
  guidSearch        GUID    {}
  wszFriendlyName   CHRW    80 DUP (?)
  wszUrl            CHRW    2084 DUP (?)
EXTRASEARCH ends
;LPEXTRASEARCH typedef ptr EXTRASEARCH

COM_INTERFACE_BEG IEnumExtraSearch, IUnknown, <0E700BE1-9DB6-11D1-A1CE-00C04FD75D13>
  COM_MTD_STD Next,                           DWORD, POINTER, POINTER
  COM_MTD_STD Skip,                           DWORD
  COM_MTD_STD Reset
  COM_MTD_STD Clone,                          POINTER
COM_INTERFACE_END


SHCOLUMNID struct
  fmtid   GUID    {}
  pid     DWORD   ?
SHCOLUMNID ends
;LPSHCOLUMNID typedef ptr SHCOLUMNID

COM_INTERFACE_BEG IShellFolder2, IShellFolder, <93F2F68C-1D1B-11D3-A30E-00C04F79ABD1>
  COM_MTD_STD GetDefaultSearchGUID,           POINTER
  COM_MTD_STD EnumSearches,                   POINTER
  COM_MTD_STD GetDefaultColumn,               DWORD, POINTER, POINTER
  COM_MTD_STD GetDefaultColumnState,          DWORD, POINTER
  COM_MTD_STD GetDetailsEx,                   POINTER
  COM_MTD_STD GetDetailsOf,                   POINTER
  COM_MTD_STD MapColumnToSCID,                DWORD, POINTER
COM_INTERFACE_END


SIGDN_NORMALDISPLAY                   equ 0h
SIGDN_PARENTRELATIVEPARSING           equ 80018001h
SIGDN_DESKTOPABSOLUTEPARSING          equ 80028000h
SIGDN_PARENTRELATIVEEDITING           equ 80031001h
SIGDN_DESKTOPABSOLUTEEDITING          equ 8004c000h
SIGDN_FILESYSPATH                     equ 80058000h
SIGDN_URL                             equ 80068000h
SIGDN_PARENTRELATIVEFORADDRESSBAR     equ 8007c001h
SIGDN_PARENTRELATIVE                  equ 80080001h
SIGDN_PARENTRELATIVEFORUI             equ 80094001h

SICHINT_DISPLAY                       equ 00000000h
SICHINT_CANONICAL                     equ 10000000h
SICHINT_TEST_FILESYSPATH_IF_NOT_EQUAL equ 20000000h
SICHINT_ALLFIELDS                     equ 80000000h

COM_INTERFACE_BEG IShellItem, IUnknown, <43826d1e-e718-42ee-bc55-a1e261c37bfe>
  COM_MTD_STD   BindToHandler,                POINTER, REFGUID, REFIID, POINTER
  COM_MTD_STD   GetParent,                    POINTER
  COM_MTD_STD   GetDisplayName,               DWORD, POINTER
  COM_MTD_STD   GetAttributes,                DWORD, POINTER
  COM_MTD_STD   Compare,                      POINTER, DWORD, POINTER
COM_INTERFACE_END


COM_INTERFACE_BEG IShellItem2, IShellItem, <7E9FB0D3-919F-4307-AB2E-9B1860310C93>
  COM_MTD_STD   GetPropertyStore,             DWORD, REFIID, POINTER
  COM_MTD_STD   GetPropertyStoreWithCreateObject, DWORD, POINTER, REFIID, POINTER
  COM_MTD_STD   GetPropertyStoreForKeys,      POINTER, DWORD, DWORD, REFIID, POINTER
  COM_MTD_STD   GetPropertyDescriptionList,   POINTER, REFIID, POINTER
  COM_MTD_STD   Update,                       POINTER
  COM_MTD_STD   GetProperty,                  POINTER, POINTER
  COM_MTD_STD   GetCLSID,                     POINTER, POINTER
  COM_MTD_STD   GetFileTime,                  POINTER, POINTER
  COM_MTD_STD   GetInt32,                     POINTER, POINTER
  COM_MTD_STD   GetString,                    POINTER, POINTER
  COM_MTD_STD   GetUInt32,                    POINTER, POINTER
  COM_MTD_STD   GetUInt64,                    POINTER, POINTER
  COM_MTD_STD   GetBool,                      POINTER, POINTER
COM_INTERFACE_END


NWMF_UNLOADING        equ 00000001h
NWMF_USERINITED       equ 00000002h
NWMF_FIRST            equ 00000004h
NWMF_OVERRIDEKEY      equ 00000008h
NWMF_SHOWHELP         equ 00000010h
NWMF_HTMLDIALOG       equ 00000020h
NWMF_FROMDIALOGCHILD  equ 00000040h
NWMF_USERREQUESTED    equ 00000080h
NWMF_USERALLOWED      equ 00000100h
NWMF_FORCEWINDOW      equ 00010000h
NWMF_FORCETAB         equ 00020000h
NWMF_SUGGESTWINDOW    equ 00040000h
NWMF_SUGGESTTAB       equ 00080000h
NWMF_INACTIVETAB      equ 00100000h


COM_INTERFACE_BEG INewWindowManager, IUnknown, <D2BC4C84-3F72-4A52-A604-7BCBF3982CBB>
  COM_MTD_STD EvaluateNewWindow,              POINTER, POINTER, POINTER, POINTER, BOOL, DWORD, DWORD 
COM_INTERFACE_END


COM_INTERFACE_BEG IEnumShellItems, IUnknown, <70629033-E363-4A28-A567-0DB78006E6D7>
  COM_MTD_STD Next,                           DWORD, POINTER, POINTER
  COM_MTD_STD Skip,                           DWORD
  COM_MTD_STD Reset
  COM_MTD_STD Clone,                          POINTER
COM_INTERFACE_END


SIATTRIBFLAGS_AND            equ  0001h
SIATTRIBFLAGS_OR             equ  0002h
SIATTRIBFLAGS_APPCOMPAT      equ  0003h
SIATTRIBFLAGS_MASK           equ  0003h
SIATTRIBFLAGS_ALLITEMS       equ  4000h

COM_INTERFACE_BEG IShellItemArray, IUnknown, <B63EA76D-1F85-456F-A19C-48159EFA858B>
  COM_MTD_STD   BindToHandler,                POINTER, REFGUID, REFIID, POINTER
  COM_MTD_STD   GetPropertyStore,             DWORD, REFIID, POINTER
  COM_MTD_STD   GetPropertyDescriptionList,   DWORD, REFIID, POINTER
  COM_MTD_STD   GetAttributes,                DWORD, DWORD, POINTER
  COM_MTD_STD   GetCount,                     POINTER
  COM_MTD_STD   GetItemAt,                    DWORD, POINTER
  COM_MTD_STD   EnumItems,                    POINTER
COM_INTERFACE_END

DOGIF_DEFAULT       equ 0
DOGIF_TRAVERSE_LINK equ 1
DOGIF_NO_HDROP      equ 2
DOGIF_NO_URL        equ 4
DOGIF_ONLY_IF_ONE   equ 8


; * IShellItemFilter interface
; */
;[
; object,
; uuid(2659B475-EEB8-48B7-8F07-B378810F48CF),
; pointer_default(unique)
;]
;interface IShellItemFilter : IUnknown
;{
;  COM_MTD_STD IncludeItem(
;        [in] IShellItem *psi);
;
;  COM_MTD_STD GetEnumFlagsForItem(
;        [in] IShellItem *psi,
;        [out] SHCONTF *pgrfFlags);
;}
;
;/*****************************************************************************
; * FOLDERSETTINGS
; */
;typedef char *LPVIEWSETTINGS;
;
;typedef [v1_enum] enum FOLDERFLAGS
;{
;    FWF_AUTOARRANGE         = 0x00000001,
;    FWF_ABBREVIATEDNAMES    = 0x00000002,
;    FWF_SNAPTOGRID          = 0x00000004,
;    FWF_OWNERDATA           = 0x00000008,
;    FWF_BESTFITWINDOW       = 0x00000010,
;    FWF_DESKTOP             = 0x00000020,
;    FWF_SINGLESEL           = 0x00000040,
;    FWF_NOSUBFOLDERS        = 0x00000080,
;    FWF_TRANSPARENT         = 0x00000100,
;    FWF_NOCLIENTEDGE        = 0x00000200,
;    FWF_NOSCROLL            = 0x00000400,
;    FWF_ALIGNLEFT           = 0x00000800,
;    FWF_NOICONS             = 0x00001000,
;    FWF_SHOWSELALWAYS       = 0x00002000,
;    FWF_NOVISIBLE           = 0x00004000,
;    FWF_SINGLECLICKACTIVATE = 0x00008000,
;    FWF_NOWEBVIEW           = 0x00010000,
;    FWF_HIDEFILENAMES       = 0x00020000,
;    FWF_CHECKSELECT         = 0x00040000,
;    FWF_NOENUMREFRESH       = 0x00080000,
;    FWF_NOGROUPING          = 0x00100000,
;    FWF_FULLROWSELECT       = 0x00200000,
;    FWF_NOFILTERS           = 0x00400000,
;    FWF_NOCOLUMNHEADER      = 0x00800000,
;    FWF_NOHEADERINALLVIEWS  = 0x01000000,
;    FWF_EXTENDEDTILES       = 0x02000000,
;    FWF_TRICHECKSELECT      = 0x04000000,
;    FWF_AUTOCHECKSELECT     = 0x08000000,
;    FWF_NOBROWSERVIEWSTATE  = 0x10000000,
;    FWF_SUBSETGROUPS        = 0x20000000,
;    FWF_USESEARCHFOLDER     = 0x40000000,
;    FWF_ALLOWRTLREADING     = 0x80000000
;} FOLDERFLAGS;
;
;typedef [v1_enum] enum FOLDERVIEWMODE
;{
;    FVM_AUTO       =-1,
;    FVM_ICON       = 1,
;    FVM_FIRST      = FVM_ICON,
;    FVM_SMALLICON  = 2,
;    FVM_LIST       = 3,
;    FVM_DETAILS    = 4,
;    FVM_THUMBNAIL  = 5,
;    FVM_TILE       = 6,
;    FVM_THUMBSTRIP = 7,
;    FVM_CONTENT    = 8,
;    FVM_LAST       = FVM_CONTENT
;} FOLDERVIEWMODE;
;
;typedef struct
;{
;    UINT ViewMode;
;    UINT fFlags;
;} FOLDERSETTINGS, *PFOLDERSETTINGS, *LPFOLDERSETTINGS;
;typedef const FOLDERSETTINGS *LPCFOLDERSETTINGS;
;
;/*****************************************************************************
; * IShellIcon interface
; */
;[
;    uuid(000214e5-0000-0000-c000-000000000046),
;    object,
;    pointer_default(unique)
;]
;interface IShellIcon : IUnknown
;{
;  COM_MTD_STD GetIconOf(
;        [in] PCUITEMID_CHILD pidl,
;        [in] UINT flags,
;        [out] int *pIconIndex);
;}
;
;/*****************************************************************************
; * IShellView interface
; */
;interface IShellBrowser;  /* forward declaration */
;[
;    object,
;    uuid(000214e3-0000-0000-c000-000000000046),
;    pointer_default(unique)
;]
;interface IShellView : IOleWindow
;{
;    typedef IShellView *LPSHELLVIEW;
;
;    typedef [v1_enum] enum _SVSIF
;    {
;        SVSI_DESELECT       = 0x00000000,
;        SVSI_SELECT         = 0x00000001,
;        SVSI_EDIT           = 0x00000003,
;        SVSI_DESELECTOTHERS = 0x00000004,
;        SVSI_ENSUREVISIBLE  = 0x00000008,
;        SVSI_FOCUSED        = 0x00000010,
;        SVSI_TRANSLATEPT    = 0x00000020,
;        SVSI_SELECTIONMARK  = 0x00000040,
;        SVSI_POSITIONITEM   = 0x00000080,
;        SVSI_CHECK          = 0x00000100,
;        SVSI_CHECK2         = 0x00000200,
;        SVSI_KEYBOARDSELECT = 0x00000401,
;        SVSI_NOTAKEFOCUS    = 0x40000000,
;    } _SVSIF;
;
;    cpp_quote("#define SVSI_NOSTATECHANGE  0x80000000")
;
;    typedef UINT SVSIF;
;
;    typedef [v1_enum] enum _SVGIO
;    {
;        SVGIO_BACKGROUND     = 0x00000000,
;        SVGIO_SELECTION      = 0x00000001,
;        SVGIO_ALLVIEW        = 0x00000002,
;        SVGIO_CHECKED        = 0x00000003,
;        SVGIO_TYPE_MASK      = 0x0000000f,
;        SVGIO_FLAG_VIEWORDER = 0x80000000,
;    } _SVGIO;
;
;    typedef INT SVGIO;
;
;    typedef [v1_enum] enum SVUIA_STATUS
;    {
;        SVUIA_DEACTIVATE       = 0,
;        SVUIA_ACTIVATE_NOFOCUS = 1,
;        SVUIA_ACTIVATE_FOCUS   = 2,
;        SVUIA_INPLACEACTIVATE  = 3
;    } SVUIA_STATUS;
;
;  COM_MTD_STD TranslateAccelerator( [in] MSG *pmsg );
;  COM_MTD_STD EnableModeless( [in] BOOL fEnable );
;  COM_MTD_STD UIActivate( [in] UINT uState );
;  COM_MTD_STD Refresh();
;  COM_MTD_STD CreateViewWindow(
;        [in] IShellView *psvPrevious,
;        [in] LPCFOLDERSETTINGS lpfs,
;        [in] IShellBrowser *psb,
;        [out] RECT *prcView,
;        [out] HWND *phWnd);
;
;  COM_MTD_STD DestroyViewWindow();
;  COM_MTD_STD GetCurrentInfo( [out] LPFOLDERSETTINGS lpfs );
;
;    [local] HRESULT AddPropertySheetPages(
;        [in] DWORD dwReserved,
;        [in] LPFNSVADDPROPSHEETPAGE pfn,
;        [in] LPARAM lparam);
;
;  COM_MTD_STD SaveViewState();
;  COM_MTD_STD SelectItem(
;        [in] LPCITEMIDLIST pidlItem,
;        [in] SVSIF uFlags);
;  COM_MTD_STD GetItemObject(
;        [in] UINT uItem,
;        [in] REFIID riid,
;        [out, iid_is(riid)] void **ppv);
;}
;
;[
;    object,
;    uuid(88e39e80-3578-11cf-ae69-08002b2e1262),
;    pointer_default(unique)
;]
;interface IShellView2 : IShellView
;{
;    typedef GUID SHELLVIEWID;
;cpp_quote("#include <pshpack8.h>")
;    typedef struct _SV2CVW2_PARAMS
;    {
;        DWORD cbSize;
;        IShellView *psvPrev;
;        LPCFOLDERSETTINGS pfs;
;        IShellBrowser *psbOwner;
;        RECT *prcView;
;        SHELLVIEWID const *pvid;
;        HWND hwndView;
;    } SV2CVW2_PARAMS, *LPSV2CVW2_PARAMS;
;cpp_quote("#include <poppack.h>")
;
;  COM_MTD_STD GetView(
;        [in, out] SHELLVIEWID *view_guid,
;        [in] ULONG view_type
;    );
;  COM_MTD_STD CreateViewWindow2(
;        [in] LPSV2CVW2_PARAMS view_params
;    );
;  COM_MTD_STD HandleRename(
;        [in] LPCITEMIDLIST new_pidl
;    );
;  COM_MTD_STD SelectAndPositionItem(
;        [in] LPCITEMIDLIST item,
;        [in] UINT flags,
;        [in] POINT *point
;    );
;}
;
;[
;    object,
;    uuid(ec39fa88-f8af-41c5-8421-38bed28f4673),
;    pointer_default(unique)
;]
;interface IShellView3 : IShellView2
;{
;    [v1_enum] enum _SV3CVW3_FLAGS
;    {
;        SV3CVW3_DEFAULT          = 0x00000000,
;        SV3CVW3_NONINTERACTIVE   = 0x00000001,
;        SV3CVW3_FORCEVIEWMODE    = 0x00000002,
;        SV3CVW3_FORCEFOLDERFLAGS = 0x00000004
;    };
;
;    typedef DWORD SV3CVW3_FLAGS;
;
;  COM_MTD_STD CreateViewWindow3(
;        [in] IShellBrowser *owner,
;        [in, unique] IShellView *prev_view,
;        [in] SV3CVW3_FLAGS view_flags,
;        [in] FOLDERFLAGS mask,
;        [in] FOLDERFLAGS flags,
;        [in] FOLDERVIEWMODE mode,
;        [in, unique] const SHELLVIEWID *view_id,
;        [in] const RECT *rect,
;        [out] HWND *hwnd);
;}
;
;/*****************************************************************************
; * IFolderView interface
; */
;[
;    uuid(cde725b0-ccc9-4519-917e-325d72fab4ce),
;    object,
;    pointer_default(unique)
;]
;interface IFolderView : IUnknown
;{
;  COM_MTD_STD GetCurrentViewMode( [out] UINT *mode );
;  COM_MTD_STD SetCurrentViewMode( [in] UINT mode );
;  COM_MTD_STD GetFolder( [in] REFIID riid, [out, iid_is(riid)] void **ppv );
;  COM_MTD_STD Item(
;        [in] int index,
;        [out] PITEMID_CHILD *ppidl
;    );
;  COM_MTD_STD ItemCount(
;        [in] UINT flags,
;        [out] int *items
;    );
;  COM_MTD_STD Items(
;        [in] UINT flags,
;        [in] REFIID riid,
;        [out, iid_is(riid)] void **ppv
;    );
;  COM_MTD_STD GetSelectionMarkedItem( [out] int *item );
;  COM_MTD_STD GetFocusedItem( [out] int *item );
;  COM_MTD_STD GetItemPosition(
;        [in] PCUITEMID_CHILD pidl,
;        [out] POINT* ppt
;    );
;  COM_MTD_STD GetSpacing( [in, out, unique] POINT* pt );
;  COM_MTD_STD GetDefaultSpacing( [out] POINT* pt );
;  COM_MTD_STD GetAutoArrange();
;  COM_MTD_STD SelectItem(
;        [in] int item,
;        [in] DWORD flags
;    );
;  COM_MTD_STD SelectAndPositionItems(
;        [in] UINT cidl,
;        [in, size_is(cidl)] PCUITEMID_CHILD_ARRAY apidl,
;        [in, unique, size_is(cidl)] POINT* apt,
;        [in] DWORD flags
;    );
;}
;
;[v1_enum] enum tagSORTDIRECTION
;{
;    SORT_DESCENDING = -1,
;    SORT_ASCENDING = 1
;};
;typedef int SORTDIRECTION;
;
;typedef struct SORTCOLUMN
;{
;    PROPERTYKEY propkey;
;    SORTDIRECTION direction;
;} SORTCOLUMN;
;
;typedef [v1_enum] enum FVTEXTTYPE
;{
;    FVST_EMPTYTEXT = 0
;} FVTEXTTYPE;
;
;[
;    uuid(1af3a467-214f-4298-908e-06b03e0b39f9),
;    object,
;    pointer_default(unique)
;]
;interface IFolderView2 : IFolderView
;{
;  COM_MTD_STD SetGroupBy(
;        [in] REFPROPERTYKEY key,
;        [in] BOOL ascending);
;
;    [local]
;  COM_MTD_STD GetGroupBy(
;        [out] PROPERTYKEY *pkey,
;        [out] BOOL *ascending);
;
;    [call_as(GetGroupBy)]
;  COM_MTD_STD RemoteGetGroupBy(
;        [out] PROPERTYKEY *pkey,
;        [out] BOOL *ascending);
;
;  COM_MTD_STD SetViewProperty(
;        [in] PCUITEMID_CHILD pidl,
;        [in] REFPROPERTYKEY propkey,
;        [in] REFPROPVARIANT propvar);
;
;  COM_MTD_STD GetViewProperty(
;        [in] PCUITEMID_CHILD pidl,
;        [in] REFPROPERTYKEY propkey,
;        [out] PROPVARIANT *propvar);
;
;  COM_MTD_STD SetTileViewProperties(
;        [in] PCUITEMID_CHILD pidl,
;        [in, string] LPCWSTR prop_list);
;
;  COM_MTD_STD SetExtendedTileViewProperties(
;        [in] PCUITEMID_CHILD pidl,
;        [in, string] LPCWSTR prop_list);
;
;  COM_MTD_STD SetText(
;        [in] FVTEXTTYPE type,
;        [in] LPCWSTR text);
;
;  COM_MTD_STD SetCurrentFolderFlags(
;        [in] DWORD mask,
;        [in] DWORD flags);
;
;  COM_MTD_STD GetCurrentFolderFlags([out] DWORD *flags);
;
;  COM_MTD_STD GetSortColumnCount([out] int *columns);
;
;  COM_MTD_STD SetSortColumns(
;        [in, size_is(count)] const SORTCOLUMN *columns,
;        [in] int count);
;
;  COM_MTD_STD GetSortColumns(
;        [out, size_is(count)] SORTCOLUMN *columns,
;        [in] int count);
;
;  COM_MTD_STD GetItem(
;        [in] int ittem,
;        [in] REFIID riid,
;        [out, iid_is(riid)] void **ppv);
;
;  COM_MTD_STD GetVisibleItem(
;        [in] int start,
;        [in] BOOL previous,
;        [out] int *item);
;
;  COM_MTD_STD GetSelectedItem(
;        [in] int start,
;        [out] int *item);
;
;  COM_MTD_STD GetSelection(
;        [in] BOOL none_implies_folder,
;        [out] IShellItemArray **array);
;
;  COM_MTD_STD GetSelectionState(
;        [in] PCUITEMID_CHILD pidl,
;        [out] DWORD *flags);
;
;  COM_MTD_STD InvokeVerbOnSelection([in, unique, string] LPCSTR verb);
;
;  COM_MTD_STD SetViewModeAndIconSize(
;        [in] FOLDERVIEWMODE mode,
;        [in] int size);
;
;  COM_MTD_STD GetViewModeAndIconSize(
;        [out] FOLDERVIEWMODE *mode,
;        [out] int *size);
;
;  COM_MTD_STD SetGroupSubsetCount([in] UINT visible_rows);
;
;  COM_MTD_STD GetGroupSubsetCount([out] UINT *visible_rows);
;
;  COM_MTD_STD SetRedraw([in] BOOL redraw);
;
;  COM_MTD_STD IsMoveInSameFolder();
;
;  COM_MTD_STD DoRename();
;}
;
;/*****************************************************************************
; * IShellBrowser interface
; */
;[
;    object,
;    uuid(000214e2-0000-0000-c000-000000000046),
;    pointer_default(unique)
;]
;interface IShellBrowser : IOleWindow
;{
;    typedef IShellBrowser *LPSHELLBROWSER;
;
;cpp_quote("#define SBSP_DEFBROWSER            0x00000000")
;cpp_quote("#define SBSP_SAMEBROWSER           0x00000001")
;cpp_quote("#define SBSP_NEWBROWSER            0x00000002")
;cpp_quote("#define SBSP_DEFMODE               0x00000000")
;cpp_quote("#define SBSP_OPENMODE              0x00000010")
;cpp_quote("#define SBSP_EXPLOREMODE           0x00000020")
;cpp_quote("#define SBSP_HELPMODE              0x00000040")
;cpp_quote("#define SBSP_NOTRANSFERHIST        0x00000080")
;cpp_quote("#define SBSP_ABSOLUTE              0x00000000")
;cpp_quote("#define SBSP_RELATIVE              0x00001000")
;cpp_quote("#define SBSP_PARENT                0x00002000")
;cpp_quote("#define SBSP_NAVIGATEBACK          0x00004000")
;cpp_quote("#define SBSP_NAVIGATEFORWARD       0x00008000")
;cpp_quote("#define SBSP_ALLOW_AUTONAVIGATE    0x00010000")
;cpp_quote("#define SBSP_KEEPSAMETEMPLATE      0x00020000")
;cpp_quote("#define SBSP_KEEPWORDWHEELTEXT     0x00040000")
;cpp_quote("#define SBSP_ACTIVATE_NOFOCUS      0x00080000")
;cpp_quote("#define SBSP_CREATENOHISTORY       0x00100000")
;cpp_quote("#define SBSP_PLAYNOSOUND           0x00200000")
;cpp_quote("#define SBSP_CALLERUNTURUSTED      0x00800000")
;cpp_quote("#define SBSP_TRUSTFIRSTDOWNLOAD    0x01000000")
;cpp_quote("#define SBSP_UNTRUSTEDFORDOWNLOAD  0x02000000")
;cpp_quote("#define SBSP_NOAUTOSELECT          0x04000000")
;cpp_quote("#define SBSP_WRITENOHISTORY        0x08000000")
;cpp_quote("#define SBSP_TRUSTEDFORACTIVEX     0x10000000")
;cpp_quote("#define SBSP_FEEDNAVIGATION        0x20000000")
;cpp_quote("#define SBSP_REDIRECT              0x40000000")
;cpp_quote("#define SBSP_INITIATEDBYHLINKFRAME 0x80000000")
;
;cpp_quote("#define FCW_STATUS      0x0001")
;cpp_quote("#define FCW_TOOLBAR     0x0002")
;cpp_quote("#define FCW_TREE        0x0003")
;cpp_quote("#define FCW_INTERNETBAR 0x0006")
;cpp_quote("#define FCW_PROGRESS    0x0008")
;
;cpp_quote("#define FCT_MERGE       0x0001")
;cpp_quote("#define FCT_CONFIGABLE  0x0002")
;cpp_quote("#define FCT_ADDTOEND    0x0004")
;
;cpp_quote("#if 0")
;    typedef LPARAM LPTBBUTTONSB;
;cpp_quote("#else")
;cpp_quote("#include <commctrl.h>")
;cpp_quote("typedef LPTBBUTTON LPTBBUTTONSB;")
;cpp_quote("#endif")
;
;  COM_MTD_STD InsertMenusSB(
;        [in] HMENU hmenuShared,
;        [in, out] LPOLEMENUGROUPWIDTHS lpMenuWidths);
;
;  COM_MTD_STD SetMenuSB(
;        [in] HMENU hmenuShared,
;        [in] HOLEMENU holemenuReserved,
;        [in] HWND hwndActiveObject);
;
;  COM_MTD_STD RemoveMenusSB( [in] HMENU hmenuShared );
;  COM_MTD_STD SetStatusTextSB( [in, unique] LPCOLESTR pszStatusText );
;  COM_MTD_STD EnableModelessSB( [in] BOOL fEnable );
;  COM_MTD_STD TranslateAcceleratorSB( [in] MSG *pmsg, [in] WORD wID );
;
;  COM_MTD_STD BrowseObject(
;        [in] LPCITEMIDLIST pidl,
;        [in] UINT wFlags);
;
;  COM_MTD_STD GetViewStateStream(
;        [in] DWORD grfMode,
;        [out] IStream **ppStrm);
;
;  COM_MTD_STD GetControlWindow(
;        [in] UINT id,
;        [out] HWND *phwnd);
;
;    [local] HRESULT SendControlMsg(
;        [in] UINT id,
;        [in] UINT uMsg,
;        [in] WPARAM wParam,
;        [in] LPARAM lParam,
;        [in] LRESULT *pret);
;
;  COM_MTD_STD QueryActiveShellView( [out] IShellView **ppshv );
;  COM_MTD_STD OnViewWindowActive( [in] IShellView *pshv );
;
;    [local]
;  COM_MTD_STD SetToolbarItems(
;        [in] LPTBBUTTONSB lpButtons,
;        [in] UINT nButtons,
;        [in] UINT uFlags);
;}
;
;
;/*****************************************************************************
; * IShellLinkA interface
; */
;[
;    object,
;    uuid(000214ee-0000-0000-c000-000000000046),
;    pointer_default(unique)
;]
;interface IShellLinkA : IUnknown
;{
;    typedef [v1_enum] enum SLR_FLAGS
;    {
;        SLR_NO_UI                     = 0x0001,
;        SLR_ANY_MATCH                 = 0x0002,
;        SLR_UPDATE                    = 0x0004,
;        SLR_NOUPDATE                  = 0x0008,
;        SLR_NOSEARCH                  = 0x0010,
;        SLR_NOTRACK                   = 0x0020,
;        SLR_NOLINKINFO                = 0x0040,
;        SLR_INVOKE_MSI                = 0x0080,
;        SLR_NO_UI_WITH_MSG_PUMP       = 0x0101,
;        SLR_OFFER_DELETE_WITHOUT_FILE = 0x0200,
;        SLR_KNOWNFOLDER               = 0x0400,
;        SLR_MACHINE_IN_LOCAL_TARGET   = 0x0800,
;        SLR_UPDATE_MACHINE_AND_SID    = 0x1000,
;        SLR_NO_OBJECT_ID              = 0x2000
;    } SLR_FLAGS;
;
;    typedef [v1_enum] enum SLGP_FLAGS
;    {
;        SLGP_SHORTPATH        = 0x0001,
;        SLGP_UNCPRIORITY      = 0x0002,
;        SLGP_RAWPATH          = 0x0004,
;        SLGP_RELATIVEPRIORITY = 0x0008
;    } SLGP_FLAGS;
;
;  COM_MTD_STD GetPath(
;        [out, size_is(cch)] LPSTR pszFile,
;        [in] int cch,
;        [in, out, unique] WIN32_FIND_DATAA *pfd,
;        [in] DWORD fFlags);
;
;  COM_MTD_STD GetIDList( [out] LPITEMIDLIST * ppidl );
;
;  COM_MTD_STD SetIDList( [in] LPCITEMIDLIST pidl );
;
;  COM_MTD_STD GetDescription(
;        [out, size_is(cch)] LPSTR pszName,
;        [in] int cch);
;
;  COM_MTD_STD SetDescription( [in] LPCSTR pszName );
;
;  COM_MTD_STD GetWorkingDirectory(
;        [out, size_is(cch)] LPSTR pszDir,
;        [in] int cch);
;
;  COM_MTD_STD SetWorkingDirectory( [in] LPCSTR pszDir );
;
;  COM_MTD_STD GetArguments(
;        [out, size_is(cch)] LPSTR pszArgs,
;        [in] int cch);
;
;  COM_MTD_STD SetArguments( [in] LPCSTR pszArgs );
;
;  COM_MTD_STD GetHotkey( [out] WORD *pwHotkey );
;
;  COM_MTD_STD SetHotkey( [in] WORD wHotkey );
;
;  COM_MTD_STD GetShowCmd( [out] int *piShowCmd );
;
;  COM_MTD_STD SetShowCmd( [in] int iShowCmd );
;
;  COM_MTD_STD GetIconLocation(
;        [out, size_is(cch)] LPSTR pszIconPath,
;        [in] int cch,
;        [out] int *piIcon);
;
;  COM_MTD_STD SetIconLocation(
;        [in] LPCSTR pszIconPath,
;        [in] int iIcon);
;
;  COM_MTD_STD SetRelativePath(
;        [in] LPCSTR pszPathRel,
;        [in] DWORD dwReserved);
;
;  COM_MTD_STD Resolve(
;        [in] HWND hwnd,
;        [in] DWORD fFlags);
;
;  COM_MTD_STD SetPath( [in] LPCSTR pszFile );
;}
;
;
;/*****************************************************************************
; * IShellLinkW interface
; */
;[
;    object,
;    uuid(000214f9-0000-0000-c000-000000000046),
;    pointer_default(unique)
;]
;interface IShellLinkW : IUnknown
;{
;  COM_MTD_STD GetPath(
;        [out, size_is(cch)] LPWSTR pszFile,
;        [in] int cch,
;        [in, out] WIN32_FIND_DATAW *pfd,
;        [in] DWORD fFlags);
;
;  COM_MTD_STD GetIDList( [out] LPITEMIDLIST * ppidl );
;
;  COM_MTD_STD SetIDList( [in] LPCITEMIDLIST pidl );
;
;  COM_MTD_STD GetDescription(
;        [out, size_is(cch)] LPWSTR pszName,
;        [in] int cch);
;
;  COM_MTD_STD SetDescription( [in] LPCWSTR pszName );
;
;  COM_MTD_STD GetWorkingDirectory(
;        [out, size_is(cch)] LPWSTR pszDir,
;        [in] int cch);
;
;  COM_MTD_STD SetWorkingDirectory( [in] LPCWSTR pszDir );
;
;  COM_MTD_STD GetArguments(
;        [out, size_is(cch)] LPWSTR pszArgs,
;        [in] int cch);
;
;  COM_MTD_STD SetArguments( [in] LPCWSTR pszArgs );
;
;  COM_MTD_STD GetHotkey( [out] WORD *pwHotkey );
;
;  COM_MTD_STD SetHotkey( [in] WORD wHotkey );
;
;  COM_MTD_STD GetShowCmd( [out] int *piShowCmd );
;
;  COM_MTD_STD SetShowCmd( [in] int iShowCmd );
;
;  COM_MTD_STD GetIconLocation(
;        [out, size_is(cch)] LPWSTR pszIconPath,
;        [in] int cch,
;        [out] int *piIcon);
;
;  COM_MTD_STD SetIconLocation(
;        [in] LPCWSTR pszIconPath,
;        [in] int iIcon);
;
;  COM_MTD_STD SetRelativePath(
;        [in] LPCWSTR pszPathRel,
;        [in] DWORD dwReserved);
;
;  COM_MTD_STD Resolve(
;        [in] HWND hwnd,
;        [in] DWORD fFlags);
;
;  COM_MTD_STD SetPath( [in] LPCWSTR pszFile );
;}
;
;cpp_quote("#define IShellLink WINELIB_NAME_AW(IShellLink)")
;
;
;/*****************************************************************************
; * IShellExtInit interface
; */
;[
;    object,
;    uuid(000214e8-0000-0000-c000-000000000046),
;    pointer_default(unique),
;    local
;]
;interface IShellExtInit : IUnknown
;{
;    typedef IShellExtInit *LPSHELLEXTINIT;
;
;  COM_MTD_STD Initialize(
;        [in] LPCITEMIDLIST pidlFolder,
;        [in] IDataObject *pdtobj,
;        [in] HKEY hkeyProgID);
;}
;
;
;/*******************************************************************************/
;/* Note: the following interfaces are not in shobjidl.idl under Windows, they  */
;/* are declared directly in shlobj.h. It hopefully won't break anything to put */
;/* them here anyway.                                                           */
;/*******************************************************************************/
;
;#ifndef MAX_PATH
;#define MAX_PATH 260
;#endif
;
;
;/*****************************************************************************
; * IPersistFolder3 interface
; */
;[
;    object,
;    uuid(cef04fdf-fe72-11d2-87a5-00c04f6837cf),
;    pointer_default(unique)
;]
;interface IPersistFolder3 : IPersistFolder2
;{
;    typedef struct
;    {
;        LPITEMIDLIST	pidlTargetFolder;
;	WCHAR		szTargetParsingName[MAX_PATH];
;	WCHAR		szNetworkProvider[MAX_PATH];
;	DWORD		dwAttributes;
;	int		csidl;
;    } PERSIST_FOLDER_TARGET_INFO;
;
;  COM_MTD_STD InitializeEx(
;        [in] IBindCtx *pbc,
;        [in] LPCITEMIDLIST pidlRoot,
;        [in] const PERSIST_FOLDER_TARGET_INFO *ppfti);
;
;  COM_MTD_STD GetFolderTargetInfo( [out] PERSIST_FOLDER_TARGET_INFO *ppfti );
;}
;
;
;/*****************************************************************************
; * IExtractIconA interface
; */
;[
;    object,
;    uuid(000214eb-0000-0000-c000-000000000046),
;    pointer_default(unique),
;    local
;]
;interface IExtractIconA : IUnknown
;{
;cpp_quote("#define GIL_OPENICON     0x0001")
;cpp_quote("#define GIL_FORSHELL     0x0002")
;cpp_quote("#define GIL_ASYNC        0x0020")
;cpp_quote("#define GIL_DEFAULTICON  0x0040")
;cpp_quote("#define GIL_FORSHORTCUT  0x0080")
;
;cpp_quote("#define GIL_SIMULATEDOC  0x0001")
;cpp_quote("#define GIL_PERINSTANCE  0x0002")
;cpp_quote("#define GIL_PERCLASS     0x0004")
;cpp_quote("#define GIL_NOTFILENAME  0x0008")
;cpp_quote("#define GIL_DONTCACHE    0x0010")
;
;    typedef IExtractIconA *LPEXTRACTICONA;
;
;  COM_MTD_STD GetIconLocation(
;        [in] UINT uFlags,
;        [out, size_is(cchMax)] LPSTR szIconFile,
;        [in] UINT cchMax,
;        [out] INT *piIndex,
;        [out] UINT *pwFlags);
;
;  COM_MTD_STD Extract(
;        [in] LPCSTR pszFile,
;        [in] UINT nIconIndex,
;        [out] HICON *phiconLarge,
;        [out] HICON *phiconSmall,
;        [in] UINT nIconSize );
;}
;
;
;/*****************************************************************************
; * IExtractIconW interface
; */
;[
;    object,
;    uuid(000214fa-0000-0000-c000-000000000046),
;    pointer_default(unique),
;    local
;]
;interface IExtractIconW : IUnknown
;{
;    typedef IExtractIconW *LPEXTRACTICONW;
;
;  COM_MTD_STD GetIconLocation(
;        [in] UINT uFlags,
;        [out, size_is(cchMax)] LPWSTR szIconFile,
;        [in] UINT cchMax,
;        [out] INT *piIndex,
;        [out] UINT *pwFlags);
;
;  COM_MTD_STD Extract(
;        [in] LPCWSTR pszFile,
;        [in] UINT nIconIndex,
;        [out] HICON *phiconLarge,
;        [out] HICON *phiconSmall,
;        [in] UINT nIconSize );
;}
;
;cpp_quote("#define LPEXTRACTICON WINELIB_NAME_AW(LPEXTRACTICON)")
;cpp_quote("#define IExtractIcon WINELIB_NAME_AW(IExtractIcon)")
;
;
;/*****************************************************************************
; * ICommDlgBrowser interface
; */
;[
;    object,
;    uuid(000214f1-0000-0000-c000-000000000046),
;    pointer_default(unique)
;]
;interface ICommDlgBrowser : IUnknown
;{
;cpp_quote("#define CDBOSC_SETFOCUS     0x00000000")
;cpp_quote("#define CDBOSC_KILLFOCUS    0x00000001")
;cpp_quote("#define CDBOSC_SELCHANGE    0x00000002")
;cpp_quote("#define CDBOSC_RENAME       0x00000003")
;cpp_quote("#define CDBOSC_STATECHANGE  0x00000004")
;
;    typedef ICommDlgBrowser *LPCOMMDLGBROWSER;
;
;  COM_MTD_STD OnDefaultCommand( [in] IShellView *shv );
;  COM_MTD_STD OnStateChange( [in] IShellView *shv, [in] ULONG uChange );
;  COM_MTD_STD IncludeObject( [in] IShellView *shv, [in] LPCITEMIDLIST pidl );
;}
;
;
;/*****************************************************************************
; * ICommDlgBrowser2 interface
; */
;[
; object,
; uuid(10339516-2894-11D2-9039-00C04F8EEB3E),
; pointer_default(unique)
;]
;interface ICommDlgBrowser2 : ICommDlgBrowser
;{
;
;  COM_MTD_STD Notify(
;        [in] IShellView *ppshv,
;        [in] DWORD dwNotifyType);
;
;  COM_MTD_STD GetDefaultMenuText(
;        [in] IShellView *ppshv,
;        [out, string, size_is(cchMax)] LPWSTR pszText,
;        [in] int cchMax);
;
;  COM_MTD_STD GetViewFlags(
;        [out] DWORD *pdwFlags);
;}
;
;
;/*****************************************************************************
; * ICommDlgBrowser3 interface
; */
;[
; object,
; uuid(C8AD25A1-3294-41EE-8165-71174BD01C57),
; pointer_default(unique)
;]
;interface ICommDlgBrowser3 : ICommDlgBrowser2
;{
;
;  COM_MTD_STD OnColumnClicked(
;        [in] IShellView *ppshv,
;        [in] int iColumn);
;
;  COM_MTD_STD GetCurrentFilter(
;        [out, string, size_is(cchFileSpec)] LPWSTR pszFileSpec,
;        [in] int cchFileSpec);
;
;  COM_MTD_STD OnPreViewCreated(
;        [in] IShellView *ppshv);
;}
;
;/*****************************************************************************
; * IDockingWindow interface
; */
;[
;    object,
;    uuid(012dd920-7b26-11d0-8ca9-00a0c92dbfe8)
;]
;interface IDockingWindow : IOleWindow
;{
;  COM_MTD_STD ShowDW(
;        [in] BOOL fShow);
;
;  COM_MTD_STD CloseDW(
;        [in] DWORD dwReserved);
;
;  COM_MTD_STD ResizeBorderDW(
;        [in] LPCRECT prcBorder,
;        [in] IUnknown *punkToolbarSite,
;        [in] BOOL fReserved);
;}
;
;
;/*****************************************************************************
; * IDockingWindowFrame interface
; */
;[
;    object,
;    uuid(47d2657a-7b27-11d0-8ca9-00a0c92dbfe8),
;    pointer_default(unique),
;    local
;]
;interface IDockingWindowFrame : IOleWindow
;{
;cpp_quote("#define DWFRF_NORMAL           0x0000")
;cpp_quote("#define DWFRF_DELETECONFIGDATA 0x0001")
;cpp_quote("#define DWFAF_HIDDEN           0x0001")
;
;  COM_MTD_STD AddToolbar(
;        [in] IUnknown *punkSrc,
;        [in] LPCWSTR pwszItem,
;        [in] DWORD dwAddFlags);
;
;  COM_MTD_STD RemoveToolbar(
;        [in] IUnknown *punkSrc,
;        [in] DWORD dwRemoveFlags);
;
;  COM_MTD_STD FindToolbar(
;        [in] LPCWSTR pwszItem,
;        [in] REFIID riid,
;        [out] LPVOID *ppvObj);
;}
;
;
;/*****************************************************************************
; * IDragSourceHelper interface
; */
;[
;    object,
;    uuid(de5bf786-477a-11d2-839d-00c04fd918d0),
;    pointer_default(unique),
;    local
;]
;interface IDragSourceHelper : IUnknown
;{
;    typedef struct
;    {
;        SIZE     sizeDragImage;
;        POINT    ptOffset;
;        HBITMAP  hbmpDragImage;
;        COLORREF crColorKey;
;    } SHDRAGIMAGE, *LPSHDRAGIMAGE;
;
;  HRESULT InitializeFromBitmap(
;      [in] LPSHDRAGIMAGE pshdi,
;      [in] IDataObject *pDataObject);
;
;  HRESULT InitializeFromWindow(
;      [in] HWND hwnd,
;      [in] POINT *ppt,
;      [in] IDataObject *pDataObject);
;}
;
;
;/*****************************************************************************
; * IDropTargetHelper interface
; */
;[
;    object,
;    uuid(4657278b-411b-11d2-839a-00c04fd918d0),
;    pointer_default(unique),
;    local
;]
;interface IDropTargetHelper : IUnknown
;{
;  COM_MTD_STD DragEnter(
;        [in] HWND hwndTarget,
;        [in] IDataObject *pDataObject,
;        [in] POINT *ppt,
;        [in] DWORD dwEffect);
;
;  COM_MTD_STD DragLeave();
;
;  COM_MTD_STD DragOver(
;        [in] POINT *ppt,
;        [in] DWORD dwEffect);
;
;  COM_MTD_STD Drop(
;        [in] IDataObject *pDataObject,
;        [in] POINT *ppt,
;        [in] DWORD dwEffect);
;
;  COM_MTD_STD Show( [in] BOOL fShow );
;}
;
;
;/*****************************************************************************
; * IContextMenu interface
; */
;[
;    object,
;    uuid(000214e4-0000-0000-c000-000000000046),
;    pointer_default(unique),
;    local
;]
;interface IContextMenu : IUnknown
;{
;cpp_quote("#define CMF_NORMAL            0x00000000")
;cpp_quote("#define CMF_DEFAULTONLY       0x00000001")
;cpp_quote("#define CMF_VERBSONLY         0x00000002")
;cpp_quote("#define CMF_EXPLORE           0x00000004")
;cpp_quote("#define CMF_NOVERBS           0x00000008")
;cpp_quote("#define CMF_CANRENAME         0x00000010")
;cpp_quote("#define CMF_NODEFAULT         0x00000020")
;cpp_quote("#define CMF_INCLUDESTATIC     0x00000040")
;cpp_quote("#define CMF_ITEMMENU          0x00000080")
;cpp_quote("#define CMF_EXTENDEDVERBS     0x00000100")
;cpp_quote("#define CMF_DISABLEDVERBS     0x00000200")
;cpp_quote("#define CMF_ASYNCVERBSTATE    0x00000400")
;cpp_quote("#define CMF_OPTIMIZEFORINVOKE 0x00000800")
;cpp_quote("#define CMF_SYNCCASCADEMENU   0x00001000")
;cpp_quote("#define CMF_DONOTPICKDEFAULT  0x00002000")
;cpp_quote("#define CMF_RESERVED          0xffff0000")
;
;cpp_quote("#define GCS_VERBA         0x00000000")
;cpp_quote("#define GCS_HELPTEXTA     0x00000001")
;cpp_quote("#define GCS_VALIDATEA     0x00000002")
;cpp_quote("#define GCS_VERBW         0x00000004")
;cpp_quote("#define GCS_HELPTEXTW     0x00000005")
;cpp_quote("#define GCS_VALIDATEW     0x00000006")
;cpp_quote("#define GCS_UNICODE       0x00000004")
;cpp_quote("#define GCS_VERB          WINELIB_NAME_AW(GCS_VERB)")
;cpp_quote("#define GCS_HELPTEXT      WINELIB_NAME_AW(GCS_HELPTEXT)")
;cpp_quote("#define GCS_VALIDATE      WINELIB_NAME_AW(GCS_VALIDATE)")
;
;cpp_quote("#define CMDSTR_NEWFOLDERA   \"NewFolder\"")
;cpp_quote("#define CMDSTR_VIEWLISTA    \"ViewList\"")
;cpp_quote("#define CMDSTR_VIEWDETAILSA \"ViewDetails\"")
;cpp_quote("#if defined(__GNUC__)")
;cpp_quote("# define CMDSTR_NEWFOLDERW (const WCHAR []){ 'N','e','w','F','o','l','d','e','r',0 }")
;cpp_quote("# define CMDSTR_VIEWLISTW (const WCHAR []){ 'V','i','e','w','L','i','s','t',0 }")
;cpp_quote("# define CMDSTR_VIEWDETAILSW (const WCHAR []){ 'V','i','e','w','D','e','t','a','i','l','s',0 }")
;cpp_quote("#elif defined(_MSC_VER)")
;cpp_quote("# define CMDSTR_NEWFOLDERW   L\"NewFolder\"")
;cpp_quote("# define CMDSTR_VIEWLISTW    L\"ViewList\"")
;cpp_quote("# define CMDSTR_VIEWDETAILSW L\"ViewDetails\"")
;cpp_quote("#else")
;cpp_quote("static const WCHAR CMDSTR_NEWFOLDERW[] = {'N','e','w','F','o','l','d','e','r',0};")
;cpp_quote("static const WCHAR CMDSTR_VIEWLISTW [] = {'V','i','e','w','L','i','s','t',0};")
;cpp_quote("static const WCHAR CMDSTR_VIEWDETAILSW[] = {'V','i','e','w','D','e','t','a','i','l','s',0};")
;cpp_quote("#endif")
;cpp_quote("#define CMDSTR_NEWFOLDER    WINELIB_NAME_AW(CMDSTR_NEWFOLDER)")
;cpp_quote("#define CMDSTR_VIEWLIST     WINELIB_NAME_AW(CMDSTR_VIEWLIST)")
;cpp_quote("#define CMDSTR_VIEWDETAILS  WINELIB_NAME_AW(CMDSTR_VIEWDETAILS)")
;
;cpp_quote("#define CMIC_MASK_HOTKEY         SEE_MASK_HOTKEY")
;cpp_quote("#define CMIC_MASK_ICON           SEE_MASK_ICON")
;cpp_quote("#define CMIC_MASK_FLAG_NO_UI     SEE_MASK_FLAG_NO_UI")
;cpp_quote("#define CMIC_MASK_UNICODE        SEE_MASK_UNICODE")
;cpp_quote("#define CMIC_MASK_NO_CONSOLE     SEE_MASK_NO_CONSOLE")
;cpp_quote("#define CMIC_MASK_HASLINKNAME    SEE_MASK_HASLINKNAME")
;cpp_quote("#define CMIC_MASK_FLAG_SEP_VDM   SEE_MASK_FLAG_SEPVDM")
;cpp_quote("#define CMIC_MASK_HASTITLE       SEE_MASK_HASTITLE")
;cpp_quote("#define CMIC_MASK_ASYNCOK        SEE_MASK_ASYNCOK")
;cpp_quote("#define CMIC_MASK_NOASYNC        SEE_MASK_NOASYNC")
;cpp_quote("#define CMIC_MASK_SHIFT_DOWN     0x10000000")
;cpp_quote("#define CMIC_MASK_PTINVOKE       0x20000000")
;cpp_quote("#define CMIC_MASK_CONTROL_DOWN   0x40000000")
;cpp_quote("#define CMIC_MASK_FLAG_LOG_USAGE SEE_MASK_FLAG_LOG_USAGE")
;cpp_quote("#define CMIC_MASK_NOZONECHECKS   SEE_MASK_NOZONECHECKS")
;
;    typedef IContextMenu *LPCONTEXTMENU;
;
;    typedef struct tagCMINVOKECOMMANDINFO
;    {
;        DWORD cbSize;
;        DWORD fMask;
;        HWND hwnd;
;        LPCSTR lpVerb;
;        LPCSTR lpParameters;
;        LPCSTR lpDirectory;
;        INT nShow;
;        DWORD dwHotKey;
;        HANDLE hIcon;
;    } CMINVOKECOMMANDINFO, *LPCMINVOKECOMMANDINFO;
;
;    typedef struct tagCMInvokeCommandInfoEx
;    {
;        DWORD cbSize;
;        DWORD fMask;
;        HWND hwnd;
;        LPCSTR lpVerb;
;        LPCSTR lpParameters;
;        LPCSTR lpDirectory;
;        INT nShow;
;        DWORD dwHotKey;
;        HANDLE hIcon;
;        LPCSTR lpTitle;
;        LPCWSTR lpVerbW;
;        LPCWSTR lpParametersW;
;        LPCWSTR lpDirectoryW;
;        LPCWSTR lpTitleW;
;        POINT ptInvoke;
;    } CMINVOKECOMMANDINFOEX, *LPCMINVOKECOMMANDINFOEX;
;
;  COM_MTD_STD QueryContextMenu(
;        [in] HMENU hmenu,
;        [in] UINT indexMenu,
;        [in] UINT idCmdFirst,
;        [in] UINT idCmdLast,
;        [in] UINT uFlags);
;
;  COM_MTD_STD InvokeCommand( [in] LPCMINVOKECOMMANDINFO lpici );
;
;  COM_MTD_STD GetCommandString(
;        [in] UINT_PTR idCmd,
;        [in] UINT uType,
;        [out] UINT *pwReserved,
;        [out, size_is(cchMax)] LPSTR pszName,
;        [in] UINT cchMax);
;}
;
;
;/*****************************************************************************
; * IContextMenu2 interface
; */
;[
;    object,
;    uuid(000214f4-0000-0000-c000-000000000046),
;    pointer_default(unique),
;    local
;]
;interface IContextMenu2 : IContextMenu
;{
;    typedef IContextMenu2 *LPCONTEXTMENU2;
;
;  COM_MTD_STD HandleMenuMsg(
;        [in] UINT uMsg,
;        [in] WPARAM wParam,
;        [in] LPARAM lParam);
;}
;
;
;/*****************************************************************************
; * IContextMenu3 interface
; */
;[
;    object,
;    uuid(bcfce0a0-ec17-11d0-8d10-00a0c90f2719),
;    pointer_default(unique),
;    local
;]
;interface IContextMenu3 : IContextMenu2
;{
;    typedef IContextMenu3 *LPCONTEXTMENU3;
;
;  COM_MTD_STD HandleMenuMsg2(
;        [in] UINT uMsg,
;        [in] WPARAM wParam,
;        [in] LPARAM lParam,
;        [out] LRESULT *plResult);
;}
;
;
;[
;    object,
;    uuid(3409e930-5a39-11d1-83fa-00a0c90dc849),
;    pointer_default(unique),
;    local
;]
;interface IContextMenuCB : IUnknown
;{
;  COM_MTD_STD CallBack(
;        [in] IShellFolder *psf,
;        [in] HWND hwndOwner,
;        [in] IDataObject *pdtobj,
;        [in] UINT uMsg,
;        [in] WPARAM wParam,
;        [in] LPARAM lParam);
;}
;
;/*****************************************************************************
; * IShellExecuteHookA interface
; */
;[
;    object,
;    uuid(000214f5-0000-0000-c000-000000000046),
;    pointer_default(unique),
;    local
;]
;interface IShellExecuteHookA : IUnknown
;{
;    cpp_quote("struct _SHELLEXECUTEINFOA;")
;  COM_MTD_STD Execute(
;        [in, out] struct _SHELLEXECUTEINFOA* pei);
;}
;
;
;/*****************************************************************************
; * IShellExecuteHookW interface
; */
;[
;    object,
;    uuid(000214fb-0000-0000-c000-000000000046),
;    pointer_default(unique),
;    local
;]
;interface IShellExecuteHookW : IUnknown
;{
;    cpp_quote("struct _SHELLEXECUTEINFOW;")
;  COM_MTD_STD Execute(
;		[in, out] struct _SHELLEXECUTEINFOW* pei);
;}
;
;/*****************************************************************************
; * IShellLinkDataList interface
; */
;[
;    object,
;    uuid(45e2b4ae-b1c3-11d0-b92f-00a0c90312e1),
;    pointer_default(unique)
;]
;interface IShellLinkDataList : IUnknown
;{
;    [local] HRESULT AddDataBlock(
;                [in] void *pDataBlock);
;    [local] HRESULT CopyDataBlock(
;                [in] DWORD dwSig,
;                [out] void **ppDataBlock);
;  COM_MTD_STD RemoveDataBlock(
;                [in] DWORD dwSig);
;  COM_MTD_STD GetFlags(
;                [out] DWORD *pdwFlags);
;  COM_MTD_STD SetFlags(
;                [in] DWORD dwFlags);
;}
;
;
;/*****************************************************************************
; * IResolveShellLink interface
; */
;[
;    object,
;    uuid(5cd52983-9449-11d2-963a-00c04f79adf0),
;    pointer_default(unique)
;]
;interface IResolveShellLink : IUnknown
;{
;  COM_MTD_STD ResolveShellLink(
;                [in] IUnknown *punk,
;                [in] HWND hwnd,
;                [in] DWORD fFlags);
;}
;
;
;/*****************************************************************************
; * IURLSearchHook interface
; */
;[
;    object,
;    uuid(ac60f6a0-0fd9-11d0-99cb-00c04fd64497),
;    pointer_default(unique),
;    local
;]
;interface IURLSearchHook : IUnknown
;{
;  COM_MTD_STD Translate(
;                [in, out] LPWSTR lpwszSearchURL,
;                [in] DWORD cchBufferSize);
;}
;
;
;/*****************************************************************************
; * ISearchContext interface
; */
;[
;    object,
;    uuid(09f656a2-41af-480c-88f7-16cc0d164615),
;    pointer_default(unique),
;    local
;]
;interface ISearchContext : IUnknown
;{
;  COM_MTD_STD GetSearchUrl(
;                [in] BSTR *pbstrSearchUrl);
;  COM_MTD_STD GetSearchText(
;                [in] BSTR *pbstrSearchText);
;  COM_MTD_STD GetSearchStyle(
;                [in] DWORD *pdwSearchStyle);
;}
;
;
;/*****************************************************************************
; * IURLSearchHook2 interface
; */
;[
;    object,
;    uuid(5ee44da4-6d32-46e3-86bc-07540dedd0e0),
;    pointer_default(unique),
;    local
;]
;interface IURLSearchHook2 : IURLSearchHook
;{
;  COM_MTD_STD TranslateWithSearchContext(
;                [in, out] LPWSTR lpwszSearchURL,
;                [in] DWORD cchBufferSize,
;                [in] ISearchContext *pSearchContext);
;}
;
;
;cpp_quote("#define INewShortcutHook WINELIB_NAME_AW(INewShortcutHook)")
;
;/*****************************************************************************
; * INewShortcutHookA interface
; */
;[
;    object,
;    uuid(000214e1-0000-0000-c000-000000000046),
;    pointer_default(unique),
;    local
;]
;interface INewShortcutHookA : IUnknown
;{
;  COM_MTD_STD SetReferent(
;                [in] LPCSTR pcszReferent,
;                [in] HWND hwnd);
;  COM_MTD_STD GetReferent(
;                [out] LPSTR pcszReferent,
;                [in] int cchReferent);
;  COM_MTD_STD SetFolder(
;                [in] LPCSTR pcszReferent);
;  COM_MTD_STD GetFolder(
;                [out] LPSTR pcszReferent,
;                [in] int cchFolder);
;  COM_MTD_STD GetName(
;                [out] LPSTR pszName,
;                [in] int cchName);
;  COM_MTD_STD GetExtension(
;                [out] LPSTR pszExtension,
;                [in] int cchExtension);
;} 
;
;
;/*****************************************************************************
; * INewShortcutHookW interface
; */
;[
;    object,
;    uuid(000214f7-0000-0000-c000-000000000046),
;    pointer_default(unique),
;    local
;]
;interface INewShortcutHookW : IUnknown
;{
;  COM_MTD_STD SetReferent(
;                [in] LPCWSTR pcszReferent,
;                [in] HWND hwnd);
;  COM_MTD_STD GetReferent(
;                [out] LPWSTR pcszReferent,
;                [in] int cchReferent);
;  COM_MTD_STD SetFolder(
;                [in] LPCWSTR pcszReferent);
;  COM_MTD_STD GetFolder(
;                [out] LPWSTR pcszReferent,
;                [in] int cchFolder);
;  COM_MTD_STD GetName(
;                [out] LPWSTR pszName,
;                [in] int cchName);
;  COM_MTD_STD GetExtension(
;                [out] LPWSTR pszExtension,
;                [in] int cchExtension);
;} 
;
;/*****************************************************************************
; * IRunnableTask interface
; */
;[
;    object,
;    uuid(85788d00-6807-11d0-b810-00c04fd706ec),
;    pointer_default(unique),
;    local
;]
;interface IRunnableTask : IUnknown
;{
;  COM_MTD_STD Run();
;  COM_MTD_STD Kill([in] BOOL fWait);
;  COM_MTD_STD Suspend();
;  COM_MTD_STD Resume();
;    ULONG IsRunning();
;}
;
;/*****************************************************************************
; * IShellChangeNotify interface
; */
;[
;    object,
;    uuid(d82be2b1-5764-11d0-a96e-00c04fd705a2),
;    pointer_default(unique),
;    local
;]
;interface IShellChangeNotify : IUnknown
;{
;  COM_MTD_STD OnChange(
;                [in] LONG lEvent,
;                [in] LPCITEMIDLIST pidl1,
;                [in] LPCITEMIDLIST pidl2);
;}
;
;/*****************************************************************************
; * IFileSystemBindData interface
; */
;[
;    object,
;    uuid(01e18d10-4d8b-11d2-855d-006008059367),
;    pointer_default(unique),
;    local
;]
;interface IFileSystemBindData : IUnknown
;{
;  COM_MTD_STD SetFindData(
;                [in] const WIN32_FIND_DATAW *pfd);
;  COM_MTD_STD GetFindData(
;                [out] WIN32_FIND_DATAW *pfd);
;}
;


;/*****************************************************************************
; *    ITaskbarList interface
; */
;[
;    object,
;    uuid(56FDF342-FD6D-11d0-958A-006097C9A090),
;    pointer_default(unique)
;]

COM_INTERFACE_BEG ITaskbarList, IUnknown, <56FDF342-FD6D-11D0-958A-006097C9A090>
  COM_MTD_STD   HrInit
  COM_MTD_STD   AddTab,                       HANDLE
  COM_MTD_STD   DeleteTab,                    HANDLE
  COM_MTD_STD   ActivateTab,                  HANDLE
  COM_MTD_STD   SetActiveAlt,                 HANDLE
COM_INTERFACE_END

;interface ITaskbarList : IUnknown
;{
;  COM_MTD_STD HrInit();
;
;  COM_MTD_STD AddTab(
;        [in] HWND hwnd);
;
;  COM_MTD_STD DeleteTab(
;        [in] HWND hwnd);
;
;  COM_MTD_STD ActivateTab(
;        [in] HWND hwnd);
;
;  COM_MTD_STD SetActiveAlt(
;        [in] HWND hwnd);
;}
;

;/*****************************************************************************
; *    ITaskbarList2 interface
; */
;[
;    object,
;    uuid(602D4995-B13A-429B-A66E-1935E44F4317),
;    pointer_default(unique)
;]

COM_INTERFACE_BEG ITaskbarList2, ITaskbarList, <602D4995-B13A-429B-A66E-1935E44F4317>
  COM_MTD_STD   MarkFullscreenWindow,         HANDLE, BOOL
COM_INTERFACE_END

;interface ITaskbarList2 : ITaskbarList
;{
;  COM_MTD_STD MarkFullscreenWindow(
;        [in] HWND hwnd,
;        [in] BOOL fullscreen);
;}
;
;cpp_quote("#ifdef MIDL_PASS")
;typedef IUnknown* HIMAGELIST;
;cpp_quote("#endif")
;

THBF_ENABLED         equ 0000h
THBF_DISABLED        equ 0001h
THBF_DISMISSONCLICK  equ 0002h
THBF_NOBACKGROUND    equ 0004h
THBF_HIDDEN          equ 0008h
THBF_NONINTERACTIVE  equ 0010h


;typedef [v1_enum] enum THUMBBUTTONFLAGS {
;    THBF_ENABLED         = 0x0000,
;    THBF_DISABLED        = 0x0001,
;    THBF_DISMISSONCLICK  = 0x0002,
;    THBF_NOBACKGROUND    = 0x0004,
;    THBF_HIDDEN          = 0x0008,
;    THBF_NONINTERACTIVE  = 0x0010
;} THUMBBUTTONFLAGS;
;
;cpp_quote("DEFINE_ENUM_FLAG_OPERATORS(THUMBBUTTONFLAGS)")
;

THB_BITMAP   equ  0001h
THB_ICON     equ  0002h
THB_TOOLTIP  equ  0004h
THB_FLAGS    equ  0008h

;typedef [v1_enum] enum THUMBBUTTONMASK {
;    THB_BITMAP   = 0x0001,
;    THB_ICON     = 0x0002,
;    THB_TOOLTIP  = 0x0004,
;    THB_FLAGS    = 0x0008
;} THUMBBUTTONMASK;
;
;cpp_quote("DEFINE_ENUM_FLAG_OPERATORS(THUMBBUTTONMASK)")
;
;cpp_quote("#include <pshpack8.h>")
;typedef struct THUMBBUTTON {
;    THUMBBUTTONMASK dwMask;
;    UINT iId;
;    UINT iBitmap;
;    HICON hIcon;
;    WCHAR szTip[260];
;    THUMBBUTTONFLAGS dwFlags;
;} THUMBBUTTON, *LPTHUMBBUTTON;
;cpp_quote("#include <poppack.h>")
;
;[
;    uuid(ea1afb91-9e28-4b86-90e9-9e9f8a5eefaf),
;    object
;]

TBPF_NOPROGRESS     equ   0000h
TBPF_INDETERMINATE  equ   0001h
TBPF_NORMAL         equ   0002h
TBPF_ERROR          equ   0004h
TBPF_PAUSED         equ   0008h

;interface ITaskbarList3 : ITaskbarList2
;{
;    typedef [v1_enum] enum TBPFLAG {
;        TBPF_NOPROGRESS     = 0x0000,
;        TBPF_INDETERMINATE  = 0x0001,
;        TBPF_NORMAL         = 0x0002,
;        TBPF_ERROR          = 0x0004,
;        TBPF_PAUSED         = 0x0008
;    } TBPFLAG;
;
;    cpp_quote("DEFINE_ENUM_FLAG_OPERATORS(TBPFLAG)")

COM_INTERFACE_BEG ITaskbarList3, ITaskbarList2, <ea1afb91-9e28-4b86-90e9-9e9f8a5eefaf>
  COM_MTD_STD   SetProgressValue,         HWND, ULONGLONG, ULONGLONG
  COM_MTD_STD   SetProgressState,         HWND, SDWORD
  COM_MTD_STD   RegisterTab,              HWND, HWND
  COM_MTD_STD   UnregisterTab,            HWND
  COM_MTD_STD   SetTabOrder,              HWND, HWND
  COM_MTD_STD   SetTabActive,             HWND, HWND, DWORD
  COM_MTD_STD   ThumbBarAddButtons,       HWND, UINT, POINTER
  COM_MTD_STD   ThumbBarUpdateButtons,    HWND, UINT, POINTER
  COM_MTD_STD   ThumbBarSetImageList,     HWND, HIMAGELIST
  COM_MTD_STD   SetOverlayIcon,           HWND, HICON, POINTER
  COM_MTD_STD   SetThumbnailTooltip,      HWND, POINTER
  COM_MTD_STD   SetThumbnailClip,         HWND, PRECT
COM_INTERFACE_END


;  COM_MTD_STD SetProgressValue(
;            [in] HWND hwnd,
;            [in] ULONGLONG ullCompleted,
;            [in] ULONGLONG ullTotal);
;
;  COM_MTD_STD SetProgressState(
;            [in] HWND hwnd,
;            [in] TBPFLAG tbpFlags);
;
;  COM_MTD_STD RegisterTab(
;            [in] HWND hwndTab,
;            [in] HWND hwndMDI);
;
;  COM_MTD_STD UnregisterTab([in] HWND hwndTab);
;
;  COM_MTD_STD SetTabOrder(
;            [in] HWND hwndTab,
;            [in] HWND hwndInsertBefore);
;
;  COM_MTD_STD SetTabActive(
;            [in] HWND hwndTab,
;            [in] HWND hwndMDI,
;            [in] DWORD dwReserved);
;
;  COM_MTD_STD ThumbBarAddButtons(
;            [in] HWND hwnd,
;            [in] UINT cButtons,
;            [in, size_is(cButtons)] LPTHUMBBUTTON pButton);
;
;  COM_MTD_STD ThumbBarUpdateButtons(
;            [in] HWND hwnd,
;            [in] UINT cButtons,
;            [in, size_is(cButtons)] LPTHUMBBUTTON pButton);
;
;  COM_MTD_STD ThumbBarSetImageList(
;            [in] HWND hwnd,
;            [in] HIMAGELIST himl);
;
;  COM_MTD_STD SetOverlayIcon(
;            [in] HWND hwnd,
;            [in] HICON hIcon,
;            [in, unique, string] LPCWSTR pszDescription);
;
;  COM_MTD_STD SetThumbnailTooltip(
;            [in] HWND hwnd,
;            [in, unique, string] LPCWSTR pszTip);
;
;  COM_MTD_STD SetThumbnailClip(
;            [in] HWND hwnd,
;            [in] RECT *prcClip);
;}
;
;[
;    uuid(c43dc798-95d1-4bea-9030-bb99e2983a1a),
;    object
;]

COM_INTERFACE_BEG ITaskbarList4, ITaskbarList3, <c43dc798-95d1-4bea-9030-bb99e2983a1a>
  COM_MTD_STD   SetTabProperties,         HWND, DWORD
COM_INTERFACE_END

STPF_NONE                       equ   0000h
STPF_USEAPPTHUMBNAILALWAYS      equ   0001h
STPF_USEAPPTHUMBNAILWHENACTIVE  equ   0002h
STPF_USEAPPPEEKALWAYS           equ   0004h
STPF_USEAPPPEEKWHENACTIVE       equ   0008h


;interface ITaskbarList4 : ITaskbarList3
;{
;    typedef [v1_enum] enum STPFLAG {
;        STPF_NONE                       = 0x0000,
;        STPF_USEAPPTHUMBNAILALWAYS      = 0x0001,
;        STPF_USEAPPTHUMBNAILWHENACTIVE  = 0x0002,
;        STPF_USEAPPPEEKALWAYS           = 0x0004,
;        STPF_USEAPPPEEKWHENACTIVE       = 0x0008
;    } STPFLAG;
;
;    cpp_quote("DEFINE_ENUM_FLAG_OPERATORS(STPFLAG)")
;
;  COM_MTD_STD SetTabProperties(
;            [in] HWND hwndTab,
;            [in] STPFLAG stpFlags);
;}
;
;/*****************************************************************************
; *    IAutoCompleteDropDown interface
; */
;[
;    object,
;    uuid(3CD141F4-3C6A-11d2-BCAA-00C04FD929DB),
;    pointer_default(unique)
;]
;interface IAutoCompleteDropDown : IUnknown
;{
;cpp_quote("#define ACDD_VISIBLE   0x0001")
;
;  COM_MTD_STD GetDropDownStatus(
;        [out] DWORD *pdwFlags,
;        [out, string] LPWSTR *ppwszString);
;
;  COM_MTD_STD ResetEnumerator();
;}
;
;[
;    object,
;    uuid(cb728b20-f786-11ce-92ad-00aa00a74cd0),
;    pointer_default(unique)
;]
;interface IProfferService : IUnknown
;{
;  COM_MTD_STD ProfferService(
;        [in] REFGUID service,
;        [in] IServiceProvider *pService,
;        [out] DWORD *pCookie);
;
;  COM_MTD_STD RevokeService([in] DWORD cookie);
;}
;
;/*****************************************************************************
; * IExplorerBrowserEvents interface
; */
;[
; object,
; uuid(361BBDC7-E6EE-4E13-BE58-58E2240C810F)
;]
;interface IExplorerBrowserEvents : IUnknown
;{
;  COM_MTD_STD OnNavigationPending(
;        [in] PCIDLIST_ABSOLUTE pidlFolder);
;
;  COM_MTD_STD OnViewCreated(
;        [in] IShellView *psv);
;
;  COM_MTD_STD OnNavigationComplete(
;        [in] PCIDLIST_ABSOLUTE pidlFolder);
;
;  COM_MTD_STD OnNavigationFailed(
;        [in] PCIDLIST_ABSOLUTE pidlFolder);
;}
;
;typedef GUID EXPLORERPANE;
;typedef EXPLORERPANE *REFEXPLORERPANE;
;
;cpp_quote("#define SID_ExplorerPaneVisibility IID_IExplorerPaneVisibility")
;
;/*****************************************************************************
; * IExplorerPaneVisibility interface
; */
;[
; object,
; uuid(E07010EC-BC17-44C0-97B0-46C7C95B9EDC)
;]
;interface IExplorerPaneVisibility : IUnknown
;{
;    [v1_enum] enum _EXPLORERPANESTATE {
;        EPS_DONTCARE     = 0x0,
;        EPS_DEFAULT_ON   = 0x1,
;        EPS_DEFAULT_OFF  = 0x2,
;        EPS_STATE_MASK   = 0xffff,
;        EPS_INITIALSTATE = 0x10000,
;        EPS_FORCE        = 0x20000
;    };
;    typedef DWORD EXPLORERPANESTATE;
;
;  COM_MTD_STD GetPaneState(
;        [in] REFEXPLORERPANE ep,
;        [out] EXPLORERPANESTATE *peps);
;}
;
;typedef [v1_enum] enum tagEXPLORER_BROWSER_FILL_FLAGS {
;    EBF_NONE                     = 0,
;    EBF_SELECTFROMDATAOBJECT     = 0x100,
;    EBF_NODROPTARGET             = 0x200
;} EXPLORER_BROWSER_FILL_FLAGS;
;
;typedef [v1_enum] enum tagEXPLORER_BROWSER_OPTIONS {
;    EBO_NONE               = 0x00,
;    EBO_NAVIGATEONCE       = 0x01,
;    EBO_SHOWFRAMES         = 0x02,
;    EBO_ALWAYSNAVIGATE     = 0x04,
;    EBO_NOTRAVELLOG        = 0x08,
;    EBO_NOWRAPPERWINDOW    = 0x10,
;    EBO_HTMLSHAREPOINTVIEW = 0x20,
;    EBO_NOBORDER           = 0x40,
;    EBO_NOPERSISTVIEWSTATE = 0x80,
;} EXPLORER_BROWSER_OPTIONS;
;
;cpp_quote("#define SID_SExplorerBrowserFrame IID_ICommDlgBrowser")
;
;/*****************************************************************************
; * IExplorerBrowser interface
; */
;[
; object,
; uuid(DFD3B6B5-C10C-4BE9-85F6-A66969F402F6),
; pointer_default(unique)
;]
;interface IExplorerBrowser : IUnknown
;{
;
;    [local] HRESULT Initialize(
;        [in] HWND hwndParent,
;        [in] const RECT *prc,
;        [in, unique] const FOLDERSETTINGS *pfs);
;
;  COM_MTD_STD Destroy();
;
;    [local] HRESULT SetRect(
;        [in,out,unique] HDWP *phdwp,
;        [in] RECT rcBrowser);
;
;  COM_MTD_STD SetPropertyBag(
;        [in, string] LPCWSTR pszPropertyBag);
;
;  COM_MTD_STD SetEmptyText(
;        [in, string] LPCWSTR pszEmptyText);
;
;  COM_MTD_STD SetFolderSettings(
;        [in] const FOLDERSETTINGS *pfs);
;
;  COM_MTD_STD Advise(
;        [in] IExplorerBrowserEvents *psbe,
;        [out] DWORD *pdwCookie);
;
;  COM_MTD_STD Unadvise(
;        [in] DWORD dwCookie);
;
;  COM_MTD_STD SetOptions(
;        [in] EXPLORER_BROWSER_OPTIONS dwFlag);
;
;  COM_MTD_STD GetOptions(
;        [out] EXPLORER_BROWSER_OPTIONS *pdwFlag);
;
;  COM_MTD_STD BrowseToIDList(
;        [in] PCUIDLIST_RELATIVE pidl,
;        [in] UINT uFlags);
;
;  COM_MTD_STD BrowseToObject(
;        [in] IUnknown *punk,
;        [in] UINT uFlags);
;
;  COM_MTD_STD FillFromObject(
;        [in] IUnknown *punk,
;        [in] EXPLORER_BROWSER_FILL_FLAGS dwFlags);
;
;  COM_MTD_STD RemoveAll();
;
;  COM_MTD_STD GetCurrentView(
;        [in] REFIID riid,
;        [out, iid_is(riid)] void **ppv);
;}
;
;/*****************************************************************************
; * INameSpaceTreeControl interface
; */
;[
; object,
; uuid(028212A3-B627-47E9-8856-C14265554E4F)
;]
;interface INameSpaceTreeControl : IUnknown
;{
;    [v1_enum] enum _NSTCSTYLE {
;        NSTCS_HASEXPANDOS                 = 0x00000001,
;        NSTCS_HASLINES                    = 0x00000002,
;        NSTCS_SINGLECLICKEXPAND           = 0x00000004,
;        NSTCS_FULLROWSELECT               = 0x00000008,
;        NSTCS_SPRINGEXPAND                = 0x00000010,
;        NSTCS_HORIZONTALSCROLL            = 0x00000020,
;        NSTCS_ROOTHASEXPANDO              = 0x00000040,
;        NSTCS_SHOWSELECTIONALWAYS         = 0x00000080,
;        NSTCS_NOINFOTIP                   = 0x00000200,
;        NSTCS_EVENHEIGHT                  = 0x00000400,
;        NSTCS_NOREPLACEOPEN               = 0x00000800,
;        NSTCS_DISABLEDRAGDROP             = 0x00001000,
;        NSTCS_NOORDERSTREAM               = 0x00002000,
;        NSTCS_RICHTOOLTIP                 = 0x00004000,
;        NSTCS_BORDER                      = 0x00008000,
;        NSTCS_NOEDITLABELS                = 0x00010000,
;        NSTCS_TABSTOP                     = 0x00020000,
;        NSTCS_FAVORITESMODE               = 0x00080000,
;        NSTCS_AUTOHSCROLL                 = 0x00100000,
;        NSTCS_FADEINOUTEXPANDOS           = 0x00200000,
;        NSTCS_EMPTYTEXT                   = 0x00400000,
;        NSTCS_CHECKBOXES                  = 0x00800000,
;        NSTCS_PARTIALCHECKBOXES           = 0x01000000,
;        NSTCS_EXCLUSIONCHECKBOXES         = 0x02000000,
;        NSTCS_DIMMEDCHECKBOXES            = 0x04000000,
;        NSTCS_NOINDENTCHECKS              = 0x08000000,
;        NSTCS_ALLOWJUNCTIONS              = 0x10000000,
;        NSTCS_SHOWTABSBUTTON              = 0x20000000,
;        NSTCS_SHOWDELETEBUTTON            = 0x40000000,
;        NSTCS_SHOWREFRESHBUTTON      = (int)0x80000000
;    };
;    typedef DWORD NSTCSTYLE;
;
;    [v1_enum] enum _NSTCROOTSTYLE {
;        NSTCRS_VISIBLE                    = 0x0000,
;        NSTCRS_HIDDEN                     = 0x0001,
;        NSTCRS_EXPANDED                   = 0x0002
;    };
;    typedef DWORD NSTCROOTSTYLE;
;
;    [v1_enum] enum _NSTCITEMSTATE {
;        NSTCIS_NONE                       = 0x0000,
;        NSTCIS_SELECTED                   = 0x0001,
;        NSTCIS_EXPANDED                   = 0x0002,
;        NSTCIS_BOLD                       = 0x0004,
;        NSTCIS_DISABLED                   = 0x0008,
;        NSTCIS_SELECTEDNOEXPAND           = 0x0010
;    };
;    typedef DWORD NSTCITEMSTATE;
;
;    typedef [v1_enum] enum NSTCGNI {
;        NSTCGNI_NEXT                      = 0,
;        NSTCGNI_NEXTVISIBLE               = 1,
;        NSTCGNI_PREV                      = 2,
;        NSTCGNI_PREVVISIBLE               = 3,
;        NSTCGNI_PARENT                    = 4,
;        NSTCGNI_CHILD                     = 5,
;        NSTCGNI_FIRSTVISIBLE              = 6,
;        NSTCGNI_LASTVISIBLE               = 7
;    } NSTCGNI;
;
;  COM_MTD_STD Initialize(
;        [in] HWND hwndParent,
;        [in, unique] RECT *prc,
;        [in] NSTCSTYLE nstcsFlags);
;
;  COM_MTD_STD TreeAdvise(
;        [in] IUnknown *punk,
;        [out] DWORD *pdwCookie);
;
;  COM_MTD_STD TreeUnadvise(
;        [in] DWORD dwCookie);
;
;  COM_MTD_STD AppendRoot(
;        [in] IShellItem *psiRoot,
;        [in] SHCONTF grfEnumFlags,
;        [in] NSTCROOTSTYLE grfRootStyle,
;        [in, unique] IShellItemFilter *pif);
;
;  COM_MTD_STD InsertRoot(
;        [in] int iIndex,
;        [in] IShellItem *psiRoot,
;        [in] SHCONTF grfEnumFlags,
;        [in] NSTCROOTSTYLE grfRootStyle,
;        [in, unique] IShellItemFilter *pif);
;
;  COM_MTD_STD RemoveRoot(
;        [in] IShellItem *psiRoot);
;
;  COM_MTD_STD RemoveAllRoots();
;
;  COM_MTD_STD GetRootItems(
;        [out] IShellItemArray **ppsiaRootItems);
;
;  COM_MTD_STD SetItemState(
;        [in] IShellItem *psi,
;        [in] NSTCITEMSTATE nstcisMask,
;        [in] NSTCITEMSTATE nstcisFlags);
;
;  COM_MTD_STD GetItemState(
;        [in] IShellItem *psi,
;        [in] NSTCITEMSTATE nstcismask,
;        [out] NSTCITEMSTATE *pnstcisFlags);
;
;  COM_MTD_STD GetSelectedItems(
;        [out] IShellItemArray **psiaItems);
;
;  COM_MTD_STD GetItemCustomState(
;        [in] IShellItem *psi,
;        [out] int *piStateNumber);
;
;  COM_MTD_STD SetItemCustomState(
;        [in] IShellItem *psi,
;        [in] int iStateNumber);
;
;  COM_MTD_STD EnsureItemVisible(
;        [in] IShellItem *psi);
;
;  COM_MTD_STD SetTheme(
;        [in, string] LPCWSTR pszTheme);
;
;  COM_MTD_STD GetNextItem(
;        [in, unique] IShellItem *psi,
;        [in] NSTCGNI nstcgi,
;        [out] IShellItem **ppsiNext);
;
;  COM_MTD_STD HitTest(
;        [in] POINT *ppt,
;        [out] IShellItem **ppsiOut);
;
;  COM_MTD_STD GetItemRect(
;        [in] IShellItem *psi,
;        [out] RECT *prect);
;
;  COM_MTD_STD CollapseAll();
;}
;
;/*****************************************************************************
; * INameSpaceTreeControl2 interface
; */
;[
; object,
; uuid(7CC7AED8-290E-49BC-8945-C1401CC9306C)
;]
;interface INameSpaceTreeControl2 : INameSpaceTreeControl
;{
;    typedef [v1_enum] enum NSTCSTYLE2 {
;        NSTCS2_DEFAULT                     = 0x00,
;        NSTCS2_INTERRUPTNOTIFICATIONS      = 0x01,
;        NSTCS2_SHOWNULLSPACEMENU           = 0x02,
;        NSTCS2_DISPLAYPADDING              = 0x04,
;        NSTCS2_DISPLAYPINNEDONLY           = 0x08,
;        NTSCS2_NOSINGLETONAUTOEXPAND       = 0x10,  /* The apparent typo here is   */
;        NTSCS2_NEVERINSERTNONENUMERATED    = 0x20   /* present also in the Win SDK */
;    } NSTCSTYLE2;
;    cpp_quote("DEFINE_ENUM_FLAG_OPERATORS(NSTCSTYLE2)")
;
;  COM_MTD_STD SetControlStyle(
;        [in] NSTCSTYLE nstcsMask,
;        [in] NSTCSTYLE nstcsStyle);
;
;  COM_MTD_STD GetControlStyle(
;        [in] NSTCSTYLE nstcsMask,
;        [out] NSTCSTYLE *pnstcsStyle);
;
;  COM_MTD_STD SetControlStyle2(
;        [in] NSTCSTYLE2 nstcsMask,
;        [in] NSTCSTYLE2 nstcsStyle);
;
;  COM_MTD_STD GetControlStyle2(
;        [in] NSTCSTYLE2 nstcsMask,
;        [out] NSTCSTYLE2 *pnstcsStyle);
;}
;
;/*****************************************************************************
; * INameSpaceTreeControlEvents interface
; */
;
;[
; object,
; uuid(93D77985-B3D8-4484-8318-672CDDA002CE),
; local
;]
;interface INameSpaceTreeControlEvents : IUnknown
;{
;    [v1_enum] enum _NSTCEHITTEST {
;        NSTCEHT_NOWHERE                    = 0x0001,
;        NSTCEHT_ONITEMICON                 = 0x0002,
;        NSTCEHT_ONITEMLABEL                = 0x0004,
;        NSTCEHT_ONITEMIDENT                = 0x0008,
;        NSTCEHT_ONITEMBUTTON               = 0x0010,
;        NSTCEHT_ONITEMRIGHT                = 0x0020,
;        NSTCEHT_ONITEMSTATEICON            = 0x0040,
;        NSTCEHT_ONITEM                     = 0x0046,
;        NSTCEHT_ONITEMTABBUTTON            = 0x1000
;    };
;    typedef DWORD NSTCEHITTEST;
;
;    [v1_enum] enum _NSTCECLICKTYPE {
;        NSTCECT_LBUTTON                    = 0x1,
;        NSTCECT_MBUTTON                    = 0x2,
;        NSTCECT_RBUTTON                    = 0x3,
;        NSTCECT_BUTTON                     = 0x3,
;        NSTCECT_DBLCLICK                   = 0x4
;    };
;    typedef DWORD NSTCECLICKTYPE;
;
;  COM_MTD_STD OnItemClick(
;        [in] IShellItem *psi,
;        [in] NSTCEHITTEST nstceHitTest,
;        [in] NSTCECLICKTYPE nstceClickType);
;
;  COM_MTD_STD OnPropertyItemCommit(
;        [in] IShellItem *psi);
;
;  COM_MTD_STD OnItemStateChanging(
;        [in] IShellItem *psi,
;        [in] NSTCITEMSTATE nstcisMask,
;        [in] NSTCITEMSTATE nstcisState);
;
;  COM_MTD_STD OnItemStateChanged(
;        [in] IShellItem *psi,
;        [in] NSTCITEMSTATE nstcisMask,
;        [in] NSTCITEMSTATE nstcisState);
;
;  COM_MTD_STD OnSelectionChanged(
;        [in] IShellItemArray *psiaSelection);
;
;  COM_MTD_STD OnKeyboardInput(
;        [in] UINT uMsg,
;        [in] WPARAM wParam,
;        [in] LPARAM lParam);
;
;  COM_MTD_STD OnBeforeExpand(
;        [in] IShellItem *psi);
;
;  COM_MTD_STD OnAfterExpand(
;        [in] IShellItem *psi);
;
;  COM_MTD_STD OnBeginLabelEdit(
;        [in] IShellItem *psi);
;
;  COM_MTD_STD OnEndLabelEdit(
;        [in] IShellItem *psi);
;
;  COM_MTD_STD OnGetToolTip(
;        [in] IShellItem *psi,
;        [out, string, size_is(cchTip)] LPWSTR pszTip,
;        [in] int cchTip);
;
;  COM_MTD_STD OnBeforeItemDelete(
;        [in] IShellItem *psi);
;
;  COM_MTD_STD OnItemAdded(
;        [in] IShellItem *psi,
;        [in] BOOL fIsRoot);
;
;  COM_MTD_STD OnItemDeleted(
;        [in] IShellItem *psi,
;        [in] BOOL fIsRoot);
;
;  COM_MTD_STD OnBeforeContextMenu(
;        [in, unique] IShellItem *psi,
;        [in] REFIID riid,
;        [out, iid_is(riid)] void **ppv);
;
;  COM_MTD_STD OnAfterContextMenu(
;        [in] IShellItem *psi,
;        [in] IContextMenu *pcmIn,
;        [in] REFIID riid,
;        [out, iid_is(riid)] void **ppv);
;
;  COM_MTD_STD OnBeforeStateImageChange(
;        [in] IShellItem *psi);
;
;  COM_MTD_STD OnGetDefaultIconIndex(
;        [in] IShellItem *psi,
;        [out] int *piDefaultIcon,
;        [out] int *piOpenIcon);
;}
;
;/*****************************************************************************
; * INameSpaceTreeControlCustomDraw interface
; */
;[
; object,
; uuid(2D3BA758-33EE-42D5-BB7B-5F3431D86C78),
; local
;]
;
;interface INameSpaceTreeControlCustomDraw : IUnknown
;{
;    typedef struct NSTCCUSTOMDRAW
;    {
;        IShellItem *psi;
;        UINT uItemState;
;        NSTCITEMSTATE nstcis;
;        LPCWSTR pszText;
;        int iImage;
;        HIMAGELIST himl;
;        int iLevel;
;        int iIndent;
;    } NSTCCUSTOMDRAW;
;
;  COM_MTD_STD PrePaint(
;        [in] HDC hdc,
;        [in] RECT *prc,
;        [out] LRESULT *plres);
;
;  COM_MTD_STD PostPaint(
;        [in] HDC hdc,
;        [in] RECT *prc);
;
;  COM_MTD_STD ItemPrePaint(
;        [in] HDC hdc,
;        [in] RECT *prc,
;        [in] NSTCCUSTOMDRAW *pnstccdItem,
;        [in, out] COLORREF *pclrText,
;        [in, out] COLORREF *pclrTextBk,
;        [out] LRESULT *plres);
;
;  COM_MTD_STD ItemPostPaint(
;        [in] HDC hdc,
;        [in] RECT *prc,
;        [in] NSTCCUSTOMDRAW *pnstccdItem);
;}
;
;/*****************************************************************************
; * INameSpaceTreeControlDropHandler interface
; */
;[
; object,
; uuid(F9C665D6-C2F2-4C19-BF33-8322D7352F51),
; local
;]
;interface INameSpaceTreeControlDropHandler : IUnknown
;{
;  COM_MTD_STD OnDragEnter(
;        [in, unique] IShellItem *psiOver,
;        [in] IShellItemArray *psiaData,
;        [in] BOOL fOutsideSource,
;        [in] DWORD grfKeyState,
;        [in, out] DWORD *pdwEffect);
;
;  COM_MTD_STD OnDragOver(
;        [in, unique] IShellItem *psiOver,
;        [in] IShellItemArray *psiaData,
;        [in] DWORD grfKeyState,
;        [in, out] DWORD *pdwEffect);
;
;  COM_MTD_STD OnDragPosition(
;        [in, unique] IShellItem *psiOver,
;        [in] IShellItemArray *psiaData,
;        [in] int iNewPosition,
;        [in] int iOldPosition);
;
;  COM_MTD_STD OnDrop(
;        [in, unique] IShellItem *psiOver,
;        [in] IShellItemArray *psiaData,
;        [in] int iPosition,
;        [in] DWORD grfKeyState,
;        [in, out] DWORD *pdwEffect);
;
;  COM_MTD_STD OnDropPosition(
;        [in, unique] IShellItem *psiOver,
;        [in] IShellItemArray *psiaData,
;        [in] int iNewPosition,
;        [in] int iOldPosition);
;
;  COM_MTD_STD OnDragLeave(
;        [in, unique] IShellItem *psiOver);
;}
;cpp_quote("#define NSTCDHPOS_ONTOP -1")
;


FDEOR_DEFAULT   equ   0
FDEOR_ACCEPT    equ   1
FDEOR_REFUSE    equ   2

FDESVR_DEFAULT  equ   0
FDESVR_ACCEPT   equ   1
FDESVR_REFUSE   equ   2


COM_INTERFACE_BEG IFileDialogEvents, IUnknown, <973510DB-7D7F-452B-8975-74A85828D354>
  COM_MTD_STD   OnFileOk,                     POINTER
  COM_MTD_STD   OnFolderChanging,             POINTER, POINTER
  COM_MTD_STD   OnFolderChange,               POINTER
  COM_MTD_STD   OnSelectionChange,            POINTER
  COM_MTD_STD   OnShareViolation,             POINTER, POINTER, POINTER
  COM_MTD_STD   OnTypeChange,                 POINTER
  COM_MTD_STD   OnOverwrite,                  POINTER, POINTER, POINTER
COM_INTERFACE_END


FDAP_BOTTOM    equ  0
FDAP_TOP       equ  1

COM_INTERFACE_BEG IModalWindow, IUnknown, <B4DB1657-70D7-485E-8E3E-6FCB5A5C1802>
  COM_MTD_STD   Show,                         HWND
COM_INTERFACE_END


FOS_OVERWRITEPROMPT        equ  		00000002h
FOS_STRICTFILETYPES        equ  		00000004h
FOS_NOCHANGEDIR            equ  		00000008h
FOS_PICKFOLDERS            equ  		00000020h
FOS_FORCEFILESYSTEM        equ  		00000040h
FOS_ALLNONSTORAGEITEMS     equ  		00000080h
FOS_NOVALIDATE             equ  		00000100h
FOS_ALLOWMULTISELECT       equ  		00000200h
FOS_PATHMUSTEXIST          equ  		00000800h
FOS_FILEMUSTEXIST          equ  		00001000h
FOS_CREATEPROMPT           equ  		00002000h
FOS_SHAREAWARE             equ  		00004000h
FOS_NOREADONLYRETURN       equ  		00008000h
FOS_NOTESTFILECREATE       equ  		00010000h
FOS_HIDEMRUPLACES          equ  		00020000h
FOS_HIDEPINNEDPLACES       equ  		00040000h
FOS_NODEREFERENCELINKS     equ  		00100000h
FOS_DONTADDTORECENT        equ  		02000000h
FOS_FORCESHOWHIDDEN        equ  		10000000h
FOS_DEFAULTNOMINIMODE      equ  		20000000h
FOS_FORCEPREVIEWPANEON     equ  		40000000h
FOS_SUPPORTSTREAMABLEITEMS equ  		80000000h

COM_INTERFACE_BEG IFileDialog, IModalWindow, <42F85136-DB7E-439C-85F1-E4075D135FC8>
  COM_MTD_STD   SetFileTypes,                 DWORD, POINTER
  COM_MTD_STD   SetFileTypeIndex,             DWORD
  COM_MTD_STD   GetFileTypeIndex,             POINTER
  COM_MTD_STD   Advise,                       POINTER
  COM_MTD_STD   Unadvise,                     DWORD
  COM_MTD_STD   SetOptions,                   DWORD
  COM_MTD_STD   GetOptions,                   POINTER
  COM_MTD_STD   SetDefaultFolder,             POINTER
  COM_MTD_STD   SetFolder,                    POINTER
  COM_MTD_STD   GetFolder,                    POINTER
  COM_MTD_STD   GetCurrentSelection,          POINTER
  COM_MTD_STD   SetFileName,                  POINTER
  COM_MTD_STD   GetFileName,                  POINTER
  COM_MTD_STD   SetTitle,                     POINTER
  COM_MTD_STD   SetOkButtonLabel,             POINTER
  COM_MTD_STD   SetFileNameLabel,             POINTER
  COM_MTD_STD   GetResult,                    POINTER
  COM_MTD_STD   AddPlace,                     POINTER, DWORD
  COM_MTD_STD   SetDefaultExtension,          POINTER
  COM_MTD_STD   Close,                        HRESULT
  COM_MTD_STD   SetClientGuid,                REFGUID
  COM_MTD_STD   ClearClientData
  COM_MTD_STD   SetFilter,                    POINTER
COM_INTERFACE_END


COM_INTERFACE_BEG IFileDialog2, IFileDialog, <61744FC7-85B5-4791-A9B0-272276309B13>
  COM_MTD_STD   SetCancelButtonLabel,         POINTER
  COM_MTD_STD   SetNavigationRoot,            POINTER
COM_INTERFACE_END


COM_INTERFACE_BEG IFileOperationProgressSink, IUnknown, <04B0F1A7-9490-44BC-96E1-4296A31252E2>
  COM_MTD_STD   StartOperations
  COM_MTD_STD   FinishOperations,             HRESULT
  COM_MTD_STD   PreRenameItem,                DWORD, POINTER, POINTER
  COM_MTD_STD   PostRenameItem,               DWORD, POINTER, POINTER, HRESULT, POINTER
  COM_MTD_STD   PreMoveItem,                  DWORD, POINTER, POINTER, POINTER
  COM_MTD_STD   PostMoveItem,                 DWORD, POINTER, POINTER, POINTER, HRESULT, POINTER
  COM_MTD_STD   PreCopyItem,                  DWORD, POINTER, POINTER, POINTER
  COM_MTD_STD   PostCopyItem,                 DWORD, POINTER, POINTER, POINTER, HRESULT, POINTER
  COM_MTD_STD   PreDeleteItem,                DWORD, POINTER
  COM_MTD_STD   PostDeleteItem,               DWORD, POINTER, HRESULT, POINTER
  COM_MTD_STD   PreNewItem,                   DWORD, POINTER, POINTER
  COM_MTD_STD   PostNewItem,                  DWORD, POINTER, POINTER, POINTER, DWORD, HRESULT, POINTER
  COM_MTD_STD   UpdateProgress,               DWORD, DWORD
  COM_MTD_STD   ResetTimer
  COM_MTD_STD   PauseTimer
  COM_MTD_STD   ResumeTimer
COM_INTERFACE_END


COM_INTERFACE_BEG IFileSaveDialog, IFileDialog, <84BCCD23-5FDE-4CDB-AEA4-AF64B83D78AB>
  COM_MTD_STD   SetSaveAsItem,                POINTER
  COM_MTD_STD   SetProperties,                POINTER
  COM_MTD_STD   SetCollectedProperties,       POINTER, BOOL
  COM_MTD_STD   GetProperties,                POINTER
  COM_MTD_STD   ApplyProperties,              POINTER, POINTER, HWND, POINTER
COM_INTERFACE_END


CDCS_INACTIVE         equ   0
CDCS_ENABLED          equ   1
CDCS_VISIBLE          equ   2
CDCS_ENABLEDVISIBLE   equ   3

COM_INTERFACE_BEG IFileOpenDialog, IFileDialog, <D57C7288-D4AD-4768-BE02-9D969532D960>
  COM_MTD_STD   GetResults,                   POINTER
  COM_MTD_STD   GetSelectedItems,             POINTER
COM_INTERFACE_END


COM_INTERFACE_BEG IFileDialogCustomize, IUnknown, <E6FDD21A-163F-4975-9C8C-A69F1BA37034>
  COM_MTD_STD   EnableOpenDropDown,           DWORD 
  COM_MTD_STD   AddMenu,                      DWORD, POINTER
  COM_MTD_STD   AddPushButton,                DWORD, POINTER
  COM_MTD_STD   AddComboBox,                  DWORD
  COM_MTD_STD   AddRadioButtonList,           DWORD
  COM_MTD_STD   AddCheckButton,               DWORD, POINTER, BOOL
  COM_MTD_STD   AddEditBox,                   DWORD, POINTER
  COM_MTD_STD   AddSeparator,                 DWORD
  COM_MTD_STD   AddText,                      DWORD, POINTER
  COM_MTD_STD   SetControlLabel,              DWORD, POINTER
  COM_MTD_STD   GetControlState,              DWORD, POINTER
  COM_MTD_STD   SetControlState,              DWORD, DWORD
  COM_MTD_STD   GetEditBoxText,               DWORD, POINTER
  COM_MTD_STD   SetEditBoxText,               DWORD, POINTER
  COM_MTD_STD   GetCheckButtonState,          DWORD, POINTER
  COM_MTD_STD   SetCheckButtonState,          DWORD, BOOL
  COM_MTD_STD   AddControlItem,               DWORD, DWORD, POINTER
  COM_MTD_STD   RemoveControlItem,            DWORD, DWORD
  COM_MTD_STD   RemoveAllControlItems,        DWORD
  COM_MTD_STD   GetControlItemState,          DWORD, DWORD, POINTER
  COM_MTD_STD   SetControlItemState,          DWORD, DWORD, DWORD
  COM_MTD_STD   GetSelectedControlItem,       DWORD, POINTER
  COM_MTD_STD   SetSelectedControlItem,       DWORD, DWORD
  COM_MTD_STD   StartVisualGroup,             DWORD, POINTER
  COM_MTD_STD   EndVisualGroup
  COM_MTD_STD   MakeProminent,                DWORD
  COM_MTD_STD   SetControlItemText,           DWORD, DWORD, POINTER
COM_INTERFACE_END


KF_CATEGORY_VIRTUAL equ 00000001h
KF_CATEGORY_FIXED   equ 00000002h
KF_CATEGORY_COMMON  equ 00000003h
KF_CATEGORY_PERUSER equ 00000004h

KF_REDIRECTION_CAPABILITIES_ALLOW_ALL               equ 000000ffh
KF_REDIRECTION_CAPABILITIES_REDIRECTABLE            equ 00000001h
KF_REDIRECTION_CAPABILITIES_DENY_ALL                equ 000fff00h
KF_REDIRECTION_CAPABILITIES_DENY_POLICY_REDIRECTED  equ 00000100h
KF_REDIRECTION_CAPABILITIES_DENY_POLICY             equ 00000200h
KF_REDIRECTION_CAPABILITIES_DENY_PERMISSIONS        equ 00000400h

KFDF_LOCAL_REDIRECT_ONLY    equ 00000002h
KFDF_ROAMABLE               equ 00000004h
KFDF_PRECREATE              equ 00000008h
KFDF_STREAM                 equ 00000010h
KFDF_PUBLISHEXPANDEDPATH    equ 00000020h
KFDF_NO_REDIRECT_UI         equ 00000040h

COM_INTERFACE_BEG IFileDialogControlEvents, IUnknown, <36116642-D713-4B97-9B83-7484A9D00433>
  COM_MTD_STD   OnItemSelected,               POINTER, DWORD, DWORD
  COM_MTD_STD   OnButtonClicked,              POINTER, DWORD
  COM_MTD_STD   OnCheckButtonToggled,         POINTER, DWORD, BOOL
  COM_MTD_STD   OnControlActivating,          POINTER, DWORD
COM_INTERFACE_END


KNOWNFOLDER_DEFINITION struct
    category          DWORD        ? 
    pszName           POINTER      ?        
    pszDescription    POINTER      ?        
    fidParent         DWORD        ?
    pszRelativePath   POINTER      ?        
    pszParsingName    POINTER      ?       
    pszTooltip        POINTER      ?       
    pszLocalizedName  POINTER      ?       
    pszIcon           POINTER      ?       
    pszSecurity       POINTER      ?       
    dwAttributes      DWORD        ?       
    kfdFlags          DWORD        ?
    ftidType          DWORD        ?
KNOWNFOLDER_DEFINITION ends

COM_INTERFACE_BEG IKnownFolder, IUnknown, <3aa7af7e-9b36-420C-a8e3-f77d4674a488>
  COM_MTD_STD   GetId,                        POINTER
  COM_MTD_STD   GetCategory,                  POINTER
  COM_MTD_STD   GetShellItem,                 DWORD, REFIID, POINTER
  COM_MTD_STD   GetPath_,                     DWORD, POINTER
  COM_MTD_STD   SetPath,                      DWORD, POINTER
  COM_MTD_STD   GetIDList,                    DWORD, POINTER
  COM_MTD_STD   GetFolderType,                POINTER
  COM_MTD_STD   GetRedirectionCapabilities,   POINTER
  COM_MTD_STD   GetFolderDefinition,          POINTER
COM_INTERFACE_END


KF_REDIRECT_USER_EXCLUSIVE               equ  00000001h
KF_REDIRECT_COPY_SOURCE_DACL             equ  00000002h
KF_REDIRECT_OWNER_USER                   equ  00000004h
KF_REDIRECT_SET_OWNER_EXPLICIT           equ  00000008h
KF_REDIRECT_CHECK_ONLY                   equ  00000010h
KF_REDIRECT_WITH_UI                      equ  00000020h
KF_REDIRECT_UNPIN                        equ  00000040h
KF_REDIRECT_PIN                          equ  00000080h
KF_REDIRECT_COPY_CONTENTS                equ  00000200h
KF_REDIRECT_DEL_SOURCE_CONTENTS          equ  00000400h
KF_REDIRECT_EXCLUDE_ALL_KNOWN_SUBFOLDERS equ  00000800h

FFFP_EXACTMATCH             equ 0
FFFP_NEARESTPARENTMATCH     equ 1

COM_INTERFACE_BEG IKnownFolderManager, IUnknown, <8BE2D872-86AA-4d47-B776-32CCA40C7018>
  COM_MTD_STD   FolderIdFromCsidl,            SDWORD, POINTER
  COM_MTD_STD   FolderIdToCsidl,              POINTER, POINTER
  COM_MTD_STD   GetFolderIds,                 POINTER, POINTER
  COM_MTD_STD   GetFolder,                    POINTER, POINTER
  COM_MTD_STD   GetFolderByName,              POINTER, POINTER
  COM_MTD_STD   RegisterFolder,               POINTER, POINTER
  COM_MTD_STD   UnregisterFolder,             POINTER
  COM_MTD_STD   FindFolderFromPath,           POINTER, DWORD, POINTER
  COM_MTD_STD   FindFolderFromIDList,         POINTER, POINTER
  COM_MTD_STD   Redirect,                     POINTER, HWND, DWORD, POINTER, DWORD, POINTER, POINTER
COM_INTERFACE_END


AL_MACHINE          equ   0
AL_EFFECTIVE        equ   1
AL_USER             equ   2

AT_FILEEXTENSION    equ   0  
AT_URLPROTOCOL      equ   1
AT_STARTMENUCLIENT  equ   2


COM_INTERFACE_BEG IApplicationAssociationRegistration, IUnknown, <4E530B0A-E611-4C77-A3AC-9031D022281B>
  COM_MTD_STD   QueryCurrentDefault,          POINTER, DWORD, DWORD, POINTER 
  COM_MTD_STD   QueryAppIsDefault,            POINTER, DWORD, DWORD, POINTER, BOOL
  COM_MTD_STD   QueryAppIsDefaultAll,         DWORD, POINTER, BOOL
  COM_MTD_STD   SetAppAsDefault,              POINTER, DWORD, DWORD
  COM_MTD_STD   SetAppAsDefaultAll,           POINTER
  COM_MTD_STD   ClearUserAssociations
COM_INTERFACE_END


COM_INTERFACE_BEG IApplicationDestinations, IUnknown, <12337D35-94C6-48A0-BCE7-6A9C69D4D600>
  COM_MTD_STD   SetAppID,                     POINTER
  COM_MTD_STD   RemoveDestination,            POINTER
  COM_MTD_STD   RemoveAllDestinations
COM_INTERFACE_END


KDC_FREQUENT  equ 1
KDC_RECENT    equ 2

COM_INTERFACE_BEG ICustomDestinationList, IUnknown, <6332DEBF-87B5-4670-90C0-5E57B408A49E>
  COM_MTD_STD   SetAppID,                     POINTER
  COM_MTD_STD   BeginList,                    POINTER, REFIID, POINTER
  COM_MTD_STD   AppendCategory,               POINTER, POINTER
  COM_MTD_STD   AppendKnownCategory,          DWORD
  COM_MTD_STD   AddUserTasks,                 POINTER
  COM_MTD_STD   CommitList
  COM_MTD_STD   GetRemovedDestinations,       REFIID, POINTER
  COM_MTD_STD   DeleteList,                   POINTER
  COM_MTD_STD   AbortList
COM_INTERFACE_END


COM_INTERFACE_BEG IQueryCancelAutoPlay, IUnknown, <DDEFE873-6997-4E68-BE26-39B633ADBE12>
  COM_MTD_STD   AllowAutoPlay,                POINTER, DWORD, POINTER, DWORD
COM_INTERFACE_END


TS_NONE          equ  0
TS_PERFORMING    equ  1
TS_PREPARING     equ  2
TS_INDETERMINATE equ  4

COM_INTERFACE_BEG ITransferAdviseSink, IUnknown, <D594D0D8-8DA7-457B-B3B4-CE5DBAAC0B88>
  COM_MTD_STD   UpdateProgress,               QWORD, DWORD, DWORD, DWORD, DWORD
  COM_MTD_STD   UpdateTransferState,          DWORD
  COM_MTD_STD   ConfirmOverwrite,             POINTER, POINTER, POINTER
  COM_MTD_STD   ConfirmEncryptionLoss,        POINTER
  COM_MTD_STD   FileFailure,                  POINTER, POINTER, HRESULT, POINTER, DWORD
  COM_MTD_STD   SubStreamFailure,             POINTER, POINTER, HRESULT
  COM_MTD_STD   PropertyFailure,              POINTER, POINTER, HRESULT
COM_INTERFACE_END


TSF_NORMAL                     equ  0h
TSF_FAIL_EXIST                 equ  0h
TSF_RENAME_EXIST               equ  1h
TSF_OVERWRITE_EXIST            equ  2h
TSF_ALLOW_DECRYPTION           equ  4h
TSF_NO_SECURITY                equ  8h
TSF_COPY_CREATION_TIME         equ  10h
TSF_COPY_WRITE_TIME            equ  20h
TSF_USE_FULL_ACCESS            equ  40h
TSF_DELETE_RECYCLE_IF_POSSIBLE equ  80h
TSF_COPY_HARD_LINK             equ  100h
TSF_COPY_LOCALIZED_NAME        equ  200h
TSF_MOVE_AS_COPY_DELETE        equ  400h
TSF_SUSPEND_SHELLEVENTS        equ  800h

COM_INTERFACE_BEG ITransferSource, IUnknown, <00ADB003-BDE9-45C6-8E29-D09F9353E108>
  COM_MTD_STD   Advise,                       POINTER, DWORD
  COM_MTD_STD   Unadvise,                     DWORD
  COM_MTD_STD   SetProperties,                POINTER
  COM_MTD_STD   OpenItem,                     POINTER, DWORD, REFIID, POINTER
  COM_MTD_STD   MoveItem,                     POINTER, POINTER, DWORD, POINTER
  COM_MTD_STD   RecycleItem,                  POINTER, POINTER, DWORD, POINTER
  COM_MTD_STD   RemoveItem,                   POINTER, DWORD
  COM_MTD_STD   RenameItem,                   POINTER, POINTER, DWORD, POINTER
  COM_MTD_STD   LinkItem,                     POINTER, POINTER, DWORD, POINTER
  COM_MTD_STD   ApplyPropertiesToItem,        POINTER, POINTER
  COM_MTD_STD   GetDefaultDestinationName,    POINTER, POINTER, POINTER
  COM_MTD_STD   EnterFolder,                  POINTER, POINTER
  COM_MTD_STD   LeaveFolder,                  POINTER, POINTER
COM_INTERFACE_END


COM_INTERFACE_BEG ITransferDestination, IUnknown, <48ADDD32-3CA5-4124-ABE3-B5A72531B207>
  COM_MTD_STD   Advise,                       POINTER, DWORD
  COM_MTD_STD   Unadvise,                     DWORD
  COM_MTD_STD   CreateItem,                   POINTER, DWORD, QWORD, DWORD, POINTER, REFIID, POINTER 
COM_INTERFACE_END


COM_INTERFACE_BEG IAssocHandlerInvoker, IUnknown, <92218CAB-ECAA-4335-8133-807FD234C2EE>
  COM_MTD_STD   SupportsSelection
  COM_MTD_STD   Invoke
COM_INTERFACE_END


COM_INTERFACE_BEG IAssocHandler, IUnknown, <F04061AC-1659-4A3F-A954-775AA57FC083>
  COM_MTD_STD   GetName,                      POINTER
  COM_MTD_STD   GetUIName,                    POINTER
  COM_MTD_STD   GetIconLocation,              POINTER, POINTER
  COM_MTD_STD   IsRecommended
  COM_MTD_STD   MakeDefault,                  POINTER
  COM_MTD_STD   Invoke,                       POINTER
  COM_MTD_STD   CreateInvoker,                POINTER, POINTER
COM_INTERFACE_END


ASSOC_FILTER_NONE         equ 0
ASSOC_FILTER_RECOMMENDED  equ 1

COM_INTERFACE_BEG IEnumAssocHandlers, IUnknown, <973810AE-9599-4B88-9E4D-6EE98C9552DA>
  COM_MTD_STD   Next,                         DWORD, POINTER, POINTER
COM_INTERFACE_END


ShellObjects_Version  equ 1
ShellObjects_lcid     equ 0

sLIBID_ShellObjects             textequ <50A7E9B1-70EF-11D1-B75A-00A0C90564FE>
sCLSID_ExplorerBrowser          textequ <71F96385-DDD6-48D3-A0C1-AE06E8B055FB>
sCLSID_FileOpenDialog           textequ <DC1C5A9C-E88A-4DDE-A5A1-60F82A20AEF7>
sCLSID_FileSaveDialog           textequ <C0B4E2F3-BA21-4773-8DBA-335EC946EB8B>
sCLSID_NamespaceTreeControl     textequ <AE054212-3535-4430-83ED-D501AA6680E6>
sCLSID_KnownFolderManager       textequ <4df0c730-df9d-4ae3-9153-aa6b82e9795a>
sCLSID_ApplicationAssociationRegistration textequ <591209c7-767b-42b2-9fba-44ee4615f2c7>
sCLSID_ApplicationDestinations  textequ <86c14003-4d6b-4ef3-a7b4-0506663b2e68>
sCLSID_ShellLink                textequ <00021401-0000-0000-c000-000000000046>
sCLSID_TaskbarList              textequ <56fdf344-fd6d-11d0-958a-006097c9a090>
sCLSID_DestinationList          textequ <77f10cf0-3db5-4966-b520-b7c54fd35ed6>
sCLSID_EnumerableObjectCollection textequ <2d3468c1-36a7-43b6-ac24-d3f02fd9607a>
sCLSID_QueryCancelAutoPlay      textequ <331f1768-05a9-4ddd-b86e-dae34ddc998a>
