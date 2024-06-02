;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\shlobj.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 21/02/2024 18:24:32

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
    ??Interface equ <>
;    DECLARE_INTERFACE_IID_(INewShortcutHookA, IUnknown, "000214e1-0000-0000-c000-000000000046")
;      STDMETHOD QueryInterface, :, :ptr ptr 
;      STDMETHOD_ ULONG, AddRef
;      STDMETHOD_ ULONG, Release
;      STDMETHOD SetReferent, :, :
;      STDMETHOD GetReferent, :, :
;      STDMETHOD SetFolder, :
;      STDMETHOD GetFolder, :, :
;      STDMETHOD GetName, :, :
;      STDMETHOD GetExtension, :, :
;    DECLARE_INTERFACE_IID__END

    INTERFACE equ <INewShortcutHookW>
    ??Interface equ <>
;    DECLARE_INTERFACE_IID_(INewShortcutHookW, IUnknown, "000214f7-0000-0000-c000-000000000046")
;      STDMETHOD QueryInterface, :, :ptr ptr 
;      STDMETHOD_ ULONG, AddRef
;      STDMETHOD_ ULONG, Release
;      STDMETHOD SetReferent, :, :
;      STDMETHOD GetReferent, :, :
;      STDMETHOD SetFolder, :
;      STDMETHOD GetFolder, :, :
;      STDMETHOD GetName, :, :
;      STDMETHOD GetExtension, :, :
;    DECLARE_INTERFACE_IID__END

    ifdef UNICODE
      INewShortcutHook equ <INewShortcutHookW>
      INewShortcutHookVtbl equ <INewShortcutHookWVtbl>
    else
      INewShortcutHook equ <INewShortcutHookA>
      INewShortcutHookVtbl equ <INewShortcutHookAVtbl>
    endif
    INTERFACE equ <ICopyHookA>
    ??Interface equ <>
;    DECLARE_INTERFACE_IID_(ICopyHookA, IUnknown, "000214EF-0000-0000-c000-000000000046")
;      STDMETHOD_ UINT, CopyCallback, :, :, :, :, :, :, :
;    DECLARE_INTERFACE_IID__END

    LPCOPYHOOKA typedef ptr ICopyHookA
    INTERFACE equ <ICopyHookW>
    ??Interface equ <>
;    DECLARE_INTERFACE_IID_(ICopyHookW, IUnknown, "000214FC-0000-0000-c000-000000000046")
;      STDMETHOD_ UINT, CopyCallback, :, :, :, :, :, :, :
;    DECLARE_INTERFACE_IID__END

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
      ??Interface equ <>
;      DECLARE_INTERFACE_IID_(IFileViewerSite, IUnknown, "000214f3-0000-0000-c000-000000000046")
;        STDMETHOD SetPinnedWindow, :
;        STDMETHOD GetPinnedWindow, :ptr 
;      DECLARE_INTERFACE_IID__END

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
      ??Interface equ <>
;      DECLARE_INTERFACE_IID(IFileViewerA, "000214f0-0000-0000-c000-000000000046")
;        STDMETHOD ShowInitialize, :
;        STDMETHOD Show, :
;        STDMETHOD PrintTo, :, :
;      DECLARE_INTERFACE_IID_END

      LPFILEVIEWERA typedef ptr IFileViewerA
      INTERFACE equ <IFileViewerW>
      ??Interface equ <>
;      DECLARE_INTERFACE_IID(IFileViewerW, "000214f8-0000-0000-c000-000000000046")
;        STDMETHOD ShowInitialize, :
;        STDMETHOD Show, :
;        STDMETHOD PrintTo, :, :
;      DECLARE_INTERFACE_IID_END

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
    ??Interface equ <>
;    DECLARE_INTERFACE_IID_(ICurrentWorkingDirectory, IUnknown, "91956D21-9276-11d1-921A-006097DF5BD4")
;      STDMETHOD GetDirectory, :, :
;      STDMETHOD SetDirectory, :
;    DECLARE_INTERFACE_IID__END

    DWFRF_NORMAL equ 0000h
    DWFRF_DELETECONFIGDATA equ 0001h
    DWFAF_HIDDEN equ 0001h
    DWFAF_GROUP1 equ 0002h
    DWFAF_GROUP2 equ 0004h
    DWFAF_AUTOHIDE equ 0010h
    INTERFACE equ <IDockingWindowFrame>
    ??Interface equ <>
;    DECLARE_INTERFACE_IID_(IDockingWindowFrame, IOleWindow, "47d2657a-7b27-11d0-8ca9-00a0c92dbfe8")
;      STDMETHOD AddToolbar, :ptr , :, :
;      STDMETHOD RemoveToolbar, :ptr , :
;      STDMETHOD FindToolbar, :, :, :ptr ptr 
;    DECLARE_INTERFACE_IID__END

    INTERFACE equ <IThumbnailCapture>
    ??Interface equ <>
;    DECLARE_INTERFACE_IID_(IThumbnailCapture, IUnknown, "4ea39266-7211-409f-b622-f63dbd16c533")
;      STDMETHOD CaptureThumbnail, :ptr , :ptr , :ptr 
;    DECLARE_INTERFACE_IID__END

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
      ??Interface equ <>
;      DECLARE_INTERFACE_IID_(IEnumShellImageStore, IUnknown, "6DFD582B-92E3-11D1-98A3-00C04FB687DA")
;        STDMETHOD QueryInterface, :, :ptr ptr 
;        STDMETHOD_ ULONG, AddRef
;        STDMETHOD_ ULONG, Release
;        STDMETHOD Reset
;        STDMETHOD Next, :, :ptr , :ptr 
;        STDMETHOD Skip, :
;        STDMETHOD Clone, :ptr ptr 
;      DECLARE_INTERFACE_IID__END

      LPENUMSHELLIMAGESTORE typedef ptr IEnumShellImageStore
      SHIMSTCAPFLAG_LOCKABLE equ 0001h
      SHIMSTCAPFLAG_PURGEABLE equ 0002h
      INTERFACE equ <IShellImageStore>
      ??Interface equ <>
;      DECLARE_INTERFACE_IID_(IShellImageStore, IUnknown, "48C8118C-B924-11D1-98D5-00C04FB687DA")
;        STDMETHOD QueryInterface, :, :ptr ptr 
;        STDMETHOD_ ULONG, AddRef
;        STDMETHOD_ ULONG, Release
;        STDMETHOD Open, :, :ptr 
;        STDMETHOD Create, :, :ptr 
;        STDMETHOD ReleaseLock, :ptr 
;        STDMETHOD Close, :ptr 
;        STDMETHOD Commit, :ptr 
;        STDMETHOD IsLocked
;        STDMETHOD GetMode, :ptr 
;        STDMETHOD GetCapabilities, :ptr 
;        STDMETHOD AddEntry, :, :ptr , :, :
;        STDMETHOD GetEntry, :, :, :ptr 
;        STDMETHOD DeleteEntry, :
;        STDMETHOD IsEntryInStore, :, :ptr 
;        STDMETHOD Enum, :ptr 
;      DECLARE_INTERFACE_IID__END

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
    ??Interface equ <>
;    DECLARE_INTERFACE_IID_(IShellFolderBand, IUnknown, "7FE80CC8-C247-11d0-B93A-00A0C90312E1")
;      STDMETHOD InitializeSFB, :ptr , :
;      STDMETHOD SetBandInfoSFB, :
;      STDMETHOD GetBandInfoSFB, :
;    DECLARE_INTERFACE_IID__END

    SFBID_PIDLCHANGED equ 0

    INTERFACE equ <IDeskBarClient>
    ??Interface equ <>
;    DECLARE_INTERFACE_IID_(IDeskBarClient, IOleWindow, "EB0FE175-1A3A-11D0-89B3-00A0C90A90AC")
;      STDMETHOD SetDeskBarSite, :ptr 
;      STDMETHOD SetModeDBC, :
;      STDMETHOD UIActivateDBC, :
;      STDMETHOD GetSize, :, :
;    DECLARE_INTERFACE_IID__END

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
    DBCID_UPDATESIZE equ 5

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
    ??Interface equ <>
;    DECLARE_INTERFACE_IID_(IActiveDesktopP, IUnknown, "52502EE0-EC80-11D0-89AB-00C04FC2972D")
;      STDMETHOD QueryInterface, :, :ptr ptr 
;      STDMETHOD_ ULONG, AddRef
;      STDMETHOD_ ULONG, Release
;      STDMETHOD SetSafeMode, :
;      STDMETHOD EnsureUpdateHTML
;      STDMETHOD SetScheme, :, :
;      STDMETHOD GetScheme, :, :ptr , :
;    DECLARE_INTERFACE_IID__END

    LPACTIVEDESKTOPP typedef ptr IActiveDesktopP
    GADOF_DIRTY equ 00000001h
    INTERFACE equ <IADesktopP2>
    ??Interface equ <>
;    DECLARE_INTERFACE_IID_(IADesktopP2, IUnknown, "B22754E2-4574-11d1-9888-006097DEACF9")
;      STDMETHOD QueryInterface, :, :ptr ptr 
;      STDMETHOD_ ULONG, AddRef
;      STDMETHOD_ ULONG, Release
;      STDMETHOD ReReadWallpaper
;      STDMETHOD GetADObjectFlags, :ptr , :
;      STDMETHOD UpdateAllDesktopSubscriptions
;      STDMETHOD MakeDynamicChanges, :ptr 
;    DECLARE_INTERFACE_IID__END

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
    ??Interface equ <>
;    DECLARE_INTERFACE_IID_(IColumnProvider, IUnknown, "E8025004-1C42-11d2-BE2C-00A0C9A83DA1")
;      STDMETHOD QueryInterface, :, :ptr ptr 
;      STDMETHOD_ ULONG, AddRef
;      STDMETHOD_ ULONG, Release
;      STDMETHOD Initialize, :
;      STDMETHOD GetColumnInfo, :, :ptr 
;      STDMETHOD GetItemData, :, :, :ptr 
;    DECLARE_INTERFACE_IID__END

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
      ??Interface equ <>
;      DECLARE_INTERFACE_IID_(IDefViewFrame, IUnknown, "710EB7A0-45ED-11D0-924A-0020AFC7AC4D")
;        STDMETHOD GetWindowLV, :ptr 
;        STDMETHOD ReleaseWindowLV
;        STDMETHOD GetShellFolder, :ptr ptr 
;      DECLARE_INTERFACE_IID__END

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
    ??Interface equ <>
;    DECLARE_INTERFACE_IID_(IDocViewSite, IUnknown, "87D605E0-C511-11CF-89A9-00A0C9054129")
;      STDMETHOD OnSetTitle, :ptr 
;    DECLARE_INTERFACE_IID__END

    OPENPROPS_NONE equ 0000h
    OPENPROPS_INHIBITPIF equ 8000h
    GETPROPS_NONE equ 0000h
    SETPROPS_NONE equ 0000h
    CLOSEPROPS_NONE equ 0000h
    CLOSEPROPS_DISCARD equ 0001h
    INTERFACE equ <IInitializeObject>
    ??Interface equ <>
;    DECLARE_INTERFACE_IID_(IInitializeObject, IUnknown, "4622AD16-FF23-11d0-8D34-00A0C90F2719")
;      STDMETHOD Initialize
;    DECLARE_INTERFACE_IID__END

    BMICON_LARGE equ 0
    BMICON_SMALL equ 1

    INTERFACE equ <IBanneredBar>
    ??Interface equ <>
;    DECLARE_INTERFACE_IID_(IBanneredBar, IUnknown, "596A9A94-013E-11d1-8D34-00A0C90F2719")
;      STDMETHOD SetIconSize, :
;      STDMETHOD GetIconSize, :ptr 
;      STDMETHOD SetBitmap, :
;      STDMETHOD GetBitmap, :ptr 
;    DECLARE_INTERFACE_IID__END

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
