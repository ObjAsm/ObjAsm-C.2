;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\ShlObj.h', last modified: 19/04/2018 21:54
;Creation parameters: 

ifndef _SHLOBJ_H_
  _SHLOBJ_H_ equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if (_MSC_VER ge 800)
      if (_MSC_VER ge 1200)
        ifndef _MSC_EXTENSIONS
        endif
      endif
    endif
    ifndef SNDMSG
      ifdef __cplusplus
        ;[...]
      else
        SNDMSG equ <SendMessage>
      endif
    endif
    ifndef WINSHELLAPI
      if Defined(_SHELL32_)
        WINSHELLAPI equ <>
      else
        WINSHELLAPI equ <DECLSPEC_IMPORT>
      endif
    endif
    ifndef SHSTDAPI
      if Defined(_SHELL32_)
        SHSTDAPI equ <STDAPI>
        SHSTDAPI_ macro type_
          exitm <STDAPI_(type_)>
        endm
      else
        SHSTDAPI equ <EXTERN_C DECLSPEC_IMPORT HRESULT STDAPICALLTYPE>
        SHSTDAPI_ macro type_
          exitm <EXTERN_C DECLSPEC_IMPORT type_ STDAPICALLTYPE>
        endm
      endif
    endif
    ifndef SHDOCAPI
      if Defined(_SHDOCVW_)
        SHDOCAPI equ <STDAPI>
        SHDOCAPI_ macro type_
          exitm <STDAPI_(type_)>
        endm
      else
        SHDOCAPI equ <EXTERN_C DECLSPEC_IMPORT HRESULT STDAPICALLTYPE>
        SHDOCAPI_ macro type_
          exitm <EXTERN_C DECLSPEC_IMPORT type_ STDAPICALLTYPE>
        endm
      endif
    endif
    ifndef SHSTDDOCAPI
      if Defined(_SHDOCVW_) or Defined(_SHELL32_)
        SHSTDDOCAPI equ <STDAPI>
        SHSTDDOCAPI_ macro type_
          exitm <STDAPI_(type_)>
        endm
      else
        SHSTDDOCAPI equ <EXTERN_C DECLSPEC_IMPORT HRESULT STDAPICALLTYPE>
        SHSTDDOCAPI_ macro type_
          exitm <EXTERN_C DECLSPEC_IMPORT type_ STDAPICALLTYPE>
        endm
      endif
    endif
    ifndef BROWSEUIAPI
      if Defined(_BROWSEUI_)
        BROWSEUIAPI equ <STDAPI>
        BROWSEUIAPI_ macro type_
          exitm <STDAPI_(type_)>
        endm
      else
        BROWSEUIAPI equ <EXTERN_C DECLSPEC_IMPORT HRESULT STDAPICALLTYPE>
        BROWSEUIAPI_ macro type_
          exitm <EXTERN_C DECLSPEC_IMPORT type_ STDAPICALLTYPE>
        endm
      endif
    endif
    ifndef SHFOLDERAPI
      if Defined(_SHFOLDER_) or Defined(_SHELL32_)
        SHFOLDERAPI equ <STDAPI>
      else
        SHFOLDERAPI equ <EXTERN_C DECLSPEC_IMPORT HRESULT STDAPICALLTYPE>
      endif
    endif
    include ole2.inc
    ifndef _PRSHT_H_
      include prsht.inc
    endif
    ifndef _INC_COMMCTRL
      include commctrl.inc
    endif
    include shtypes.inc
    include shobjidl.inc
    include shlobj_core.inc
    if Defined(_MSC_VER) and (_MSC_VER ge 1200)
    endif
    ifdef __cplusplus
      ;[...]
    endif
    include pshpack1.inc
    if  not Defined(__cplusplus) and Defined(_MSC_VER) and (_MSC_VER ge 1200)
    endif
    if  not Defined(__cplusplus) and Defined(_MSC_VER) and (_MSC_VER ge 1200)
    endif
    INTERFACE equ <INewShortcutHookA>
    DECLARE_INTERFACE_IID_ INewShortcutHookA, IUnknown, "000214e1-0000-0000-c000-000000000046"
;      STD_METHOD QueryInterface, :THIS_, :ptr ptr
;      STD_METHOD AddRef, :THIS_
;      STD_METHOD Release, :THIS_
      STD_METHOD SetReferent, :THIS_, :HWND
      STD_METHOD GetReferent, :THIS_, :SDWORD
      STD_METHOD SetFolder, :THIS_
      STD_METHOD GetFolder, :THIS_, :SDWORD
      STD_METHOD GetName, :THIS_, :SDWORD
      STD_METHOD GetExtension, :THIS_, :SDWORD
    END_DECLARE_INTERFACE_IID_
    INTERFACE equ <INewShortcutHookW>
    DECLARE_INTERFACE_IID_ INewShortcutHookW, IUnknown, "000214f7-0000-0000-c000-000000000046"
;      STD_METHOD QueryInterface, :THIS_, :ptr ptr
;      STD_METHOD AddRef, :THIS_
;      STD_METHOD Release, :THIS_
      STD_METHOD SetReferent, :THIS_, :HWND
      STD_METHOD GetReferent, :THIS_, :SDWORD
      STD_METHOD SetFolder, :THIS_
      STD_METHOD GetFolder, :THIS_, :SDWORD
      STD_METHOD GetName, :THIS_, :SDWORD
      STD_METHOD GetExtension, :THIS_, :SDWORD
    END_DECLARE_INTERFACE_IID_
    ifdef UNICODE
      INewShortcutHook equ <INewShortcutHookW>
      INewShortcutHookVtbl equ <INewShortcutHookWVtbl>
    else
      INewShortcutHook equ <INewShortcutHookA>
      INewShortcutHookVtbl equ <INewShortcutHookAVtbl>
    endif
    INTERFACE equ <ICopyHookA>
    DECLARE_INTERFACE_IID_ ICopyHookA, IUnknown, "000214EF-0000-0000-c000-000000000046"
      STD_METHOD CopyCallback, :THIS_, :UINT, :UINT, :PCSTR, :DWORD, :PCSTR, :DWORD
    END_DECLARE_INTERFACE_IID_
    LPCOPYHOOKA typedef ptr ICopyHookA
    INTERFACE equ <ICopyHookW>
    DECLARE_INTERFACE_IID_ ICopyHookW, IUnknown, "000214FC-0000-0000-c000-000000000046"
      STD_METHOD CopyCallback, :THIS_, :UINT, :UINT, :PCWSTR, :DWORD, :PCWSTR, :DWORD
    END_DECLARE_INTERFACE_IID_
    LPCOPYHOOKW typedef ptr ICopyHookW
    ifdef UNICODE
      ICopyHook equ <ICopyHookW>
      ICopyHookVtbl equ <ICopyHookWVtbl>
      LPCOPYHOOK equ <LPCOPYHOOKW>
    else
      ICopyHook equ <ICopyHookA>
      ICopyHookVtbl equ <ICopyHookAVtbl>
      LPCOPYHOOK equ <LPCOPYHOOKA>
    endif
    if (NTDDI_VERSION lt NTDDI_WIN2K)
      INTERFACE equ <IFileViewerSite>
      DECLARE_INTERFACE_IID_ IFileViewerSite, IUnknown, "000214f3-0000-0000-c000-000000000046"
        STD_METHOD SetPinnedWindow, :THIS_
        STD_METHOD GetPinnedWindow, :ptr THIS_
      END_DECLARE_INTERFACE_IID_
      LPFILEVIEWERSITE typedef ptr IFileViewerSite
      include pshpack8.inc
      FVSHOWINFO struct
        cbSize DWORD ?
        hwndOwner HWND ?
        iShow SDWORD ?
        dwFlags DWORD ?
        rect RECT <>
        punkRel POINTER ?
        strNewFile OLECHAR MAX_PATH dup (?)
      FVSHOWINFO ends
      LPFVSHOWINFO typedef ptr FVSHOWINFO
      
      include poppack.inc
      FVSIF_RECT equ 00000001h
      FVSIF_PINNED equ 00000002h
      FVSIF_NEWFAILED equ 08000000h
      FVSIF_NEWFILE equ 80000000h
      FVSIF_CANVIEWIT equ 40000000h
      INTERFACE equ <IFileViewerA>
      DECLARE_INTERFACE_IID IFileViewerA, "000214f0-0000-0000-c000-000000000046"
        STD_METHOD ShowInitialize, :THIS_
        STD_METHOD Show, :THIS_
        STD_METHOD PrintTo, :THIS_, :BOOL
      END_DECLARE_INTERFACE_IID
      LPFILEVIEWERA typedef ptr IFileViewerA
      INTERFACE equ <IFileViewerW>
      DECLARE_INTERFACE_IID IFileViewerW, "000214f8-0000-0000-c000-000000000046"
        STD_METHOD ShowInitialize, :THIS_
        STD_METHOD Show, :THIS_
        STD_METHOD PrintTo, :THIS_, :BOOL
      END_DECLARE_INTERFACE_IID
      LPFILEVIEWERW typedef ptr IFileViewerW
      ifdef UNICODE
        IFileViewer equ <IFileViewerW>
        LPFILEVIEWER equ <LPFILEVIEWERW>
      else
        IFileViewer equ <IFileViewerA>
        LPFILEVIEWER equ <LPFILEVIEWERA>
      endif
    endif
    FCIDM_TOOLBAR equ (FCIDM_BROWSERFIRST + 0)
    FCIDM_STATUS equ (FCIDM_BROWSERFIRST + 1)
    IDC_OFFLINE_HAND equ 103
    if (_WIN32_IE ge _WIN32_IE_IE70)
      IDC_PANTOOL_HAND_OPEN equ 104
      IDC_PANTOOL_HAND_CLOSED equ 105
    endif
    PANE_NONE equ (- 1)
    PANE_ZONE equ 1
    PANE_OFFLINE equ 2
    PANE_PRINTER equ 3
    PANE_SSL equ 4
    PANE_NAVIGATION equ 5
    PANE_PROGRESS equ 6
    if (_WIN32_IE ge _WIN32_IE_IE60)
      PANE_PRIVACY equ 7
    endif
    INTERFACE equ <ICurrentWorkingDirectory>
    DECLARE_INTERFACE_IID_ ICurrentWorkingDirectory, IUnknown, "91956D21-9276-11d1-921A-006097DF5BD4"
      STD_METHOD GetDirectory, :THIS_, :DWORD
      STD_METHOD SetDirectory, :THIS_
    END_DECLARE_INTERFACE_IID_
    DWFRF_NORMAL equ 0000h
    DWFRF_DELETECONFIGDATA equ 0001h
    DWFAF_HIDDEN equ 0001h
    DWFAF_GROUP1 equ 0002h
    DWFAF_GROUP2 equ 0004h
    DWFAF_AUTOHIDE equ 0010h
    INTERFACE equ <IDockingWindowFrame>
    DECLARE_INTERFACE_IID_ IDockingWindowFrame, IOleWindow, "47d2657a-7b27-11d0-8ca9-00a0c92dbfe8"
      STD_METHOD AddToolbar, :ptr THIS_, :PCWSTR, :DWORD
      STD_METHOD RemoveToolbar, :ptr THIS_, :DWORD
      STD_METHOD FindToolbar, :THIS_, :REFIID, :ptr ptr
    END_DECLARE_INTERFACE_IID_
    INTERFACE equ <IThumbnailCapture>
    DECLARE_INTERFACE_IID_ IThumbnailCapture, IUnknown, "4ea39266-7211-409f-b622-f63dbd16c533"
      STD_METHOD CaptureThumbnail, :ptr THIS_, :ptr IUnknown, :ptr HBITMAP
    END_DECLARE_INTERFACE_IID_
    LPTHUMBNAILCAPTURE typedef ptr IThumbnailCapture
    if (NTDDI_VERSION ge NTDDI_WIN2K and NTDDI_VERSION lt NTDDI_VISTA)
      include pshpack8.inc
      ENUMSHELLIMAGESTOREDATA struct
        szPath WCHAR MAX_PATH dup (?)
        ftTimeStamp FILETIME <>
      ENUMSHELLIMAGESTOREDATA ends
      _EnumImageStoreDATAtag typedef ENUMSHELLIMAGESTOREDATA
      PENUMSHELLIMAGESTOREDATA typedef ptr ENUMSHELLIMAGESTOREDATA
      
      include poppack.inc
      INTERFACE equ <IEnumShellImageStore>
      DECLARE_INTERFACE_IID_ IEnumShellImageStore, IUnknown, "6DFD582B-92E3-11D1-98A3-00C04FB687DA"
;        STD_METHOD QueryInterface, :THIS_, :ptr ptr
;        STD_METHOD AddRef, :THIS_
;        STD_METHOD Release, :THIS_
        STD_METHOD Reset, :THIS_
        STD_METHOD Next, :THIS_, :ptr PENUMSHELLIMAGESTOREDATA, :ptr ULONG
        STD_METHOD Skip, :THIS_
        STD_METHOD Clone, :ptr ptr THIS_
      END_DECLARE_INTERFACE_IID_
      LPENUMSHELLIMAGESTORE typedef ptr IEnumShellImageStore
      SHIMSTCAPFLAG_LOCKABLE equ 0001h
      SHIMSTCAPFLAG_PURGEABLE equ 0002h
      INTERFACE equ <IShellImageStore>
      DECLARE_INTERFACE_IID_ IShellImageStore, IUnknown, "48C8118C-B924-11D1-98D5-00C04FB687DA"
;        STD_METHOD QueryInterface, :THIS_, :ptr ptr
;        STD_METHOD AddRef, :THIS_
;        STD_METHOD Release, :THIS_
        STD_METHOD Open, :THIS_, :ptr DWORD
        STD_METHOD Create, :THIS_, :ptr DWORD
        STD_METHOD ReleaseLock, :ptr THIS_
        STD_METHOD Close, :ptr THIS_
        STD_METHOD Commit, :ptr THIS_
        STD_METHOD IsLocked, :THIS_
        STD_METHOD GetMode, :ptr THIS_
        STD_METHOD GetCapabilities, :ptr THIS_
        STD_METHOD AddEntry, :THIS_, :ptr FILETIME, :DWORD, :HBITMAP
        STD_METHOD GetEntry, :THIS_, :DWORD, :ptr HBITMAP
        STD_METHOD DeleteEntry, :THIS_
        STD_METHOD IsEntryInStore, :THIS_, :ptr FILETIME
        STD_METHOD Enum, :ptr THIS_
      END_DECLARE_INTERFACE_IID_
      LPSHELLIMAGESTORE typedef ptr IShellImageStore
    endif
    ISFB_MASK_STATE equ 00000001h
    ISFB_MASK_BKCOLOR equ 00000002h
    ISFB_MASK_VIEWMODE equ 00000004h
    ISFB_MASK_SHELLFOLDER equ 00000008h
    ISFB_MASK_IDLIST equ 00000010h
    ISFB_MASK_COLORS equ 00000020h
    ISFB_STATE_DEFAULT equ 00000000h
    ISFB_STATE_DEBOSSED equ 00000001h
    ISFB_STATE_ALLOWRENAME equ 00000002h
    ISFB_STATE_NOSHOWTEXT equ 00000004h
    ISFB_STATE_CHANNELBAR equ 00000010h
    ISFB_STATE_QLINKSMODE equ 00000020h
    ISFB_STATE_FULLOPEN equ 00000040h
    ISFB_STATE_NONAMESORT equ 00000080h
    ISFB_STATE_BTNMINSIZE equ 00000100h
    ISFBVIEWMODE_SMALLICONS equ 0001h
    ISFBVIEWMODE_LARGEICONS equ 0002h
    if (_WIN32_IE lt _WIN32_IE_IE70)
      ISFBVIEWMODE_LOGOS equ 0003h
    endif
    include pshpack8.inc
    BANDINFOSFB struct
      dwMask DWORD ?
      dwStateMask DWORD ?
      dwState DWORD ?
      crBkgnd COLORREF ?
      crBtnLt COLORREF ?
      crBtnDk COLORREF ?
      wViewMode WORD ?
      wAlign WORD ?
      psf POINTER ?
      pidl PIDLIST_ABSOLUTE ?
    BANDINFOSFB ends
    PBANDINFOSFB typedef ptr BANDINFOSFB
    
    include poppack.inc
    INTERFACE equ <IShellFolderBand>
    DECLARE_INTERFACE_IID_ IShellFolderBand, IUnknown, "7FE80CC8-C247-11d0-B93A-00A0C90312E1"
      STD_METHOD InitializeSFB, :ptr THIS_, :PCIDLIST_ABSOLUTE
      STD_METHOD SetBandInfoSFB, :THIS_
      STD_METHOD GetBandInfoSFB, :THIS_
    END_DECLARE_INTERFACE_IID_
    SFBID_PIDLCHANGED equ 0
    
    INTERFACE equ <IDeskBarClient>
    DECLARE_INTERFACE_IID_ IDeskBarClient, IOleWindow, "EB0FE175-1A3A-11D0-89B3-00A0C90A90AC"
      STD_METHOD SetDeskBarSite, :ptr THIS_
      STD_METHOD SetModeDBC, :THIS_
      STD_METHOD UIActivateDBC, :THIS_
      STD_METHOD GetSize, :THIS_, :LPRECT
    END_DECLARE_INTERFACE_IID_
    DBC_GS_IDEAL equ 0
    DBC_GS_SIZEDOWN equ 1
    DBC_HIDE equ 0
    DBC_SHOW equ 1
    DBC_SHOWOBSCURE equ 2
    DBCID_EMPTY equ 0
    DBCID_ONDRAG equ 1
    DBCID_CLSIDOFBAR equ 2
    DBCID_RESIZE equ 3
    DBCID_GETBAR equ 4
    
    SSM_CLEAR equ 0000h
    SSM_SET equ 0001h
    SSM_REFRESH equ 0002h
    SSM_UPDATE equ 0004h
    SCHEME_DISPLAY equ 0001h
    SCHEME_EDIT equ 0002h
    SCHEME_LOCAL equ 0004h
    SCHEME_GLOBAL equ 0008h
    SCHEME_REFRESH equ 0010h
    SCHEME_UPDATE equ 0020h
    SCHEME_DONOTUSE equ 0040h
    SCHEME_CREATE equ 0080h
    INTERFACE equ <IActiveDesktopP>
    DECLARE_INTERFACE_IID_ IActiveDesktopP, IUnknown, "52502EE0-EC80-11D0-89AB-00C04FC2972D"
;      STD_METHOD QueryInterface, :THIS_, :ptr ptr
;      STD_METHOD AddRef, :THIS_
;      STD_METHOD Release, :THIS_
      STD_METHOD SetSafeMode, :THIS_
      STD_METHOD EnsureUpdateHTML, :THIS_
      STD_METHOD SetScheme, :THIS_, :DWORD
      STD_METHOD GetScheme, :THIS_, :ptr DWORD, :DWORD
    END_DECLARE_INTERFACE_IID_
    LPACTIVEDESKTOPP typedef ptr IActiveDesktopP
    GADOF_DIRTY equ 00000001h
    INTERFACE equ <IADesktopP2>
    DECLARE_INTERFACE_IID_ IADesktopP2, IUnknown, "B22754E2-4574-11d1-9888-006097DEACF9"
;      STD_METHOD QueryInterface, :THIS_, :ptr ptr
;      STD_METHOD AddRef, :THIS_
;      STD_METHOD Release, :THIS_
      STD_METHOD ReReadWallpaper, :THIS_
      STD_METHOD GetADObjectFlags, :ptr THIS_, :DWORD
      STD_METHOD UpdateAllDesktopSubscriptions, :THIS_
      STD_METHOD MakeDynamicChanges, :ptr THIS_
    END_DECLARE_INTERFACE_IID_
    LPADESKTOPP2 typedef ptr IADesktopP2
    include pshpack1.inc
    SHCOLUMNINFO struct
      scid SHCOLUMNID <>
      vt VARTYPE ?
      fmt DWORD ?
      cChars UINT ?
      csFlags DWORD ?
      wszTitle WCHAR MAX_COLUMN_NAME_LEN dup (?)
      wszDescription WCHAR MAX_COLUMN_DESC_LEN dup (?)
    SHCOLUMNINFO ends
    LPSHCOLUMNINFO typedef ptr SHCOLUMNINFO
    
    LPCSHCOLUMNINFO typedef ptr SHCOLUMNINFO
    include poppack.inc
    include pshpack8.inc
    SHCOLUMNINIT struct
      dwFlags ULONG ?
      dwReserved ULONG ?
      wszFolder WCHAR MAX_PATH dup (?)
    SHCOLUMNINIT ends
    LPSHCOLUMNINIT typedef ptr SHCOLUMNINIT
    
    LPCSHCOLUMNINIT typedef ptr SHCOLUMNINIT
    SHCDF_UPDATEITEM equ 00000001h
    SHCOLUMNDATA struct
      dwFlags ULONG ?
      dwFileAttributes DWORD ?
      dwReserved ULONG ?
      pwszExt POINTER ?
      wszFile WCHAR MAX_PATH dup (?)
    SHCOLUMNDATA ends
    LPSHCOLUMNDATA typedef ptr SHCOLUMNDATA
    
    LPCSHCOLUMNDATA typedef ptr SHCOLUMNDATA
    include poppack.inc
    INTERFACE equ <IColumnProvider>
    DECLARE_INTERFACE_IID_ IColumnProvider, IUnknown, "E8025004-1C42-11d2-BE2C-00A0C9A83DA1"
;      STD_METHOD QueryInterface, :THIS_, :ptr ptr
;      STD_METHOD AddRef, :THIS_
;      STD_METHOD Release, :THIS_
      STD_METHOD Initialize, :THIS_
      STD_METHOD GetColumnInfo, :THIS_, :ptr SHCOLUMNINFO
      STD_METHOD GetItemData, :THIS_, :LPCSHCOLUMNDATA, :ptr VARIANT
    END_DECLARE_INTERFACE_IID_
    if (NTDDI_VERSION ge NTDDI_WIN2K)
      SHChangeProductKeyAsIDList struct
        cb USHORT ?
        wszProductKey WCHAR 39 dup (?)
        cbZero USHORT ?
      SHChangeProductKeyAsIDList ends
      _SHChangeProductKeyAsIDList typedef SHChangeProductKeyAsIDList
      LPSHChangeProductKeyAsIDList typedef ptr SHChangeProductKeyAsIDList
      
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      @DefProto DllImport, SHChangeNotifyRegisterThread, WIN_STD_CALL_CONV,, <:SCNRT_STATUS>, 4
    endif
    if (NTDDI_VERSION ge NTDDI_WINXP)
    endif
    @DefProto DllImport, PathQualify, WIN_STD_CALL_CONV,, <:PWSTR>, 4
    @DefProto DllImport, PathIsSlowA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD>, 8
    @DefProto DllImport, PathIsSlowW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD>, 8
    ifdef UNICODE
      PathIsSlow equ <PathIsSlowW>
    else
      PathIsSlow equ <PathIsSlowA>
    endif
    @DefProto DllImport, GetFileNameFromBrowse, WIN_STD_CALL_CONV,, <:HWND, :PWSTR, :UINT, :PCWSTR, :PCWSTR, :PCWSTR, :PCWSTR>, 28
    @DefProto DllImport, DriveType, WIN_STD_CALL_CONV,, <:SDWORD>, 4
    @DefProto DllImport, SHCreatePropSheetExtArray, WIN_STD_CALL_CONV,, <:HKEY, :PCWSTR, :UINT>, 12
    if (NTDDI_VERSION ge NTDDI_WIN2K and NTDDI_VERSION lt NTDDI_VISTA)
      INTERFACE equ <IDefViewFrame>
      DECLARE_INTERFACE_IID_ IDefViewFrame, IUnknown, "710EB7A0-45ED-11D0-924A-0020AFC7AC4D"
        STD_METHOD GetWindowLV, :ptr THIS_
        STD_METHOD ReleaseWindowLV, :THIS_
        STD_METHOD GetShellFolder, :ptr ptr THIS_
      END_DECLARE_INTERFACE_IID_
    endif
    if (NTDDI_VERSION lt NTDDI_VISTA)
      PPCF_ADDQUOTES equ 00000001h
      PPCF_ADDARGUMENTS equ 00000003h
      PPCF_NODIRECTORIES equ 00000010h
      PPCF_FORCEQUALIFY equ 00000040h
      PPCF_LONGESTPOSSIBLE equ 00000080h
      @DefProto DllImport, PathProcessCommand, WIN_STD_CALL_CONV,, <:PCWSTR, :PWSTR, :SDWORD, :DWORD>, 16
    endif
    if (NTDDI_VERSION lt NTDDI_VISTA)
      @DefProto DllImport, SHLoadOLE, WIN_STD_CALL_CONV,, <:LPARAM>, 4
    endif
    INTERFACE equ <IDocViewSite>
    DECLARE_INTERFACE_IID_ IDocViewSite, IUnknown, "87D605E0-C511-11CF-89A9-00A0C9054129"
      STD_METHOD OnSetTitle, :ptr THIS_
    END_DECLARE_INTERFACE_IID_
    OPENPROPS_NONE equ 0000h
    OPENPROPS_INHIBITPIF equ 8000h
    GETPROPS_NONE equ 0000h
    SETPROPS_NONE equ 0000h
    CLOSEPROPS_NONE equ 0000h
    CLOSEPROPS_DISCARD equ 0001h
    INTERFACE equ <IInitializeObject>
    DECLARE_INTERFACE_IID_ IInitializeObject, IUnknown, "4622AD16-FF23-11d0-8D34-00A0C90F2719"
      STD_METHOD Initialize, :THIS_
    END_DECLARE_INTERFACE_IID_
    BMICON_LARGE equ 0
    BMICON_SMALL equ 1
    
    INTERFACE equ <IBanneredBar>
    DECLARE_INTERFACE_IID_ IBanneredBar, IUnknown, "596A9A94-013E-11d1-8D34-00A0C90F2719"
      STD_METHOD SetIconSize, :THIS_
      STD_METHOD GetIconSize, :ptr THIS_
      STD_METHOD SetBitmap, :THIS_
      STD_METHOD GetBitmap, :ptr THIS_
    END_DECLARE_INTERFACE_IID_
    include pshpack8.inc
    TBIF_APPEND equ 0
    TBIF_PREPEND equ 1
    TBIF_REPLACE equ 2
    TBIF_DEFAULT equ 00000000h
    TBIF_INTERNETBAR equ 00010000h
    TBIF_STANDARDTOOLBAR equ 00020000h
    TBIF_NOTOOLBAR equ 00030000h
    TBINFO struct
      cbuttons UINT ?
      uFlags UINT ?
    TBINFO ends
    _TBINFO typedef TBINFO
    LPTBINFO typedef ptr TBINFO
    @DefProto DllImport, SHOpenPropSheetA, WIN_STD_CALL_CONV,, <:LPCSTR, :ptr HKEY, :UINT, :ptr CLSID, :ptr IDataObject, :ptr IShellBrowser, :LPCSTR>, 28
    @DefProto DllImport, SHOpenPropSheetW, WIN_STD_CALL_CONV,, <:LPCWSTR, :ptr HKEY, :UINT, :ptr CLSID, :ptr IDataObject, :ptr IShellBrowser, :LPCWSTR>, 28
    ifdef UNICODE
      SHOpenPropSheet equ <SHOpenPropSheetW>
    else
      SHOpenPropSheet equ <SHOpenPropSheetA>
    endif
    SFVM_REARRANGE equ 00000001h
    ShellFolderView_ReArrange macro _hwnd, _lparam
      exitm <SHShellFolderView_Message (_hwnd, SFVM_REARRANGE, _lparam)>
    endm
    SFVM_ADDOBJECT equ 00000003h
    ShellFolderView_AddObject macro _hwnd, _pidl
      exitm <SHShellFolderView_Message (_hwnd, SFVM_ADDOBJECT, (_pidl))>
    endm
    SFVM_REMOVEOBJECT equ 00000006h
    ShellFolderView_RemoveObject macro _hwnd, _pidl
      exitm <SHShellFolderView_Message (_hwnd, SFVM_REMOVEOBJECT, (_pidl))>
    endm
    SFVM_UPDATEOBJECT equ 00000007h
    ShellFolderView_UpdateObject macro _hwnd, _ppidl
      exitm <SHShellFolderView_Message (_hwnd, SFVM_UPDATEOBJECT, (_ppidl))>
    endm
    SFVM_GETSELECTEDOBJECTS equ 00000009h
    ShellFolderView_GetSelectedObjects macro _hwnd, ppidl
      exitm <SHShellFolderView_Message (_hwnd, SFVM_GETSELECTEDOBJECTS, (ppidl))>
    endm
    SFV_SETITEMPOS struct
      pidl PCUITEMID_CHILD ?
      pt POINT <>
    SFV_SETITEMPOS ends
    _SFV_SETITEMPOS typedef SFV_SETITEMPOS
    LPSFV_SETITEMPOS typedef ptr SFV_SETITEMPOS
    PCSFV_SETITEMPOS typedef ptr SFV_SETITEMPOS
    SFVM_SETITEMPOS equ 0000000eh
    ShellFolderView_SetItemPos macro _hwnd, _pidl, _x, _y
      exitm <{ SFV_SETITEMPOS _sip = { _pidl, { _x, _y } } ; SHShellFolderView_Message (_hwnd, SFVM_SETITEMPOS, (LPSFV_SETITEMPOS) and _sip) ; }>
    endm
    SFVM_SETCLIPBOARD equ 00000010h
    ShellFolderView_SetClipboard macro _hwnd, _dwEffect
      exitm <SHShellFolderView_Message (_hwnd, SFVM_SETCLIPBOARD, (_dwEffect))>
    endm
    SFVM_SETPOINTS equ 00000017h
    ShellFolderView_SetPoints macro _hwnd, _pdtobj
      exitm <SHShellFolderView_Message (_hwnd, SFVM_SETPOINTS, (_pdtobj))>
    endm
    include poppack.inc
    ifdef __urlmon_h__
      @DefProto DllImport, SoftwareUpdateMessageBox, WIN_STD_CALL_CONV,, <:HWND, :PCWSTR, :DWORD, :LPSOFTDISTINFO>, 16
    endif
    if (NTDDI_VERSION ge NTDDI_WINXP)
      include pshpack8.inc
      include poppack.inc
    endif
    if (NTDDI_VERSION ge NTDDI_WIN2K)
      @DefProto DllImport, SHMultiFileProperties, WIN_STD_CALL_CONV,, <:ptr IDataObject, :DWORD>, 8
    endif
    @DefProto DllImport, SHCreateQueryCancelAutoPlayMoniker, WIN_STD_CALL_CONV,, <:ptr ptr IMoniker>, 4
    @DefProto DllImport, PerUserInit, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, SHRunControlPanel, WIN_STD_CALL_CONV,, <:PCWSTR, :HWND>, 8
    include pshpack8.inc
    AASHELLMENUFILENAME struct
      cbTotal SHORT_ ?
      rgbReserved BYTE 12 dup (?)
      szFileName WCHAR 1 dup (?)
    AASHELLMENUFILENAME ends
    tagAAMENUFILENAME typedef AASHELLMENUFILENAME
    LPAASHELLMENUFILENAME typedef ptr AASHELLMENUFILENAME
    
    AASHELLMENUITEM struct
      lpReserved1 POINTER ?
      iReserved SDWORD ?
      uiReserved UINT ?
      lpName LPAASHELLMENUFILENAME ?
      psz LPWSTR ?
    AASHELLMENUITEM ends
    tagAASHELLMENUITEM typedef AASHELLMENUITEM
    LPAASHELLMENUITEM typedef ptr AASHELLMENUITEM
    
    include poppack.inc
    if (_WIN32_IE ge _WIN32_IE_XP)
      @DefProto DllImport, ImportPrivacySettings, WIN_STD_CALL_CONV,, <:PCWSTR, :ptr BOOL, :ptr BOOL>, 12
      ifndef IEnumPrivacyRecords
        ;IEnumPrivacyRecords typedef IEnumPrivacyRecords
        
      endif
      @DefProto DllImport, DoPrivacyDlg, WIN_STD_CALL_CONV,, <:HWND, :PCWSTR, :ptr IEnumPrivacyRecords, :BOOL>, 16
    endif
    include poppack.inc
    ifdef __cplusplus
      ;[...]
    endif
    if (_MSC_VER ge 800)
      if (_MSC_VER ge 1200)
      else
      endif
    endif
  endif
endif

