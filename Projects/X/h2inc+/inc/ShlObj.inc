;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\shlobj.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 21/02/2024 18:24:32

;===========================================================================*
ifndef _SHLOBJ_H_
  _SHLOBJ_H_ equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if (_MSC_VER ge 800)
      if (_MSC_VER ge 1200)
        ifndef _MSC_EXTENSIONS
          ;* truncation of constant value *
        endif
        ;* padding added after data member *
      endif
      ;* nonstandard extension : single line comment *
    endif
    ifndef SNDMSG
      ifdef __cplusplus
        ;[...]
      else
        SNDMSG equ <SendMessage>
      endif
    endif
    ; ifndef SNDMSG
    ; Define API decoration for direct importing of DLL references.
    ifndef WINSHELLAPI
      if Defined(_SHELL32_)
        WINSHELLAPI equ <>
      else
        WINSHELLAPI equ <DECLSPEC_IMPORT>
      endif
    endif
    ; WINSHELLAPI
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
    ; SHSTDAPI
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
    ; SHDOCAPI
    ; shell32 APIs that are also exported from shdocvw
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
    ; SHSTDDOCAPI
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
      ; defined(_BROWSEUI_)
    endif
    ; BROWSEUIAPI
    ; shell32 APIs that are also exported from shfolder
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
      ; for LPTBBUTTON
    endif
    include shtypes.inc
    include shobjidl.inc
    include shlobj_core.inc
    if Defined(_MSC_VER) and (_MSC_VER ge 1200)
    endif
    ifdef __cplusplus
      ;[...]
    endif
    ;* Assume byte packing throughout *
    include pshpack1.inc
    if  not Defined(__cplusplus) and Defined(_MSC_VER) and (_MSC_VER ge 1200)
      ;* nonstandard extension used : nameless struct/union *
    endif
    if  not Defined(__cplusplus) and Defined(_MSC_VER) and (_MSC_VER ge 1200)
    endif
    INTERFACE equ <INewShortcutHookA>
    ??Interface equ <>
    DECLARE_INTERFACE_IID_(INewShortcutHookA, IUnknown, "000214e1-0000-0000-c000-000000000046")
      STDMETHOD QueryInterface, :REFIID, :ptr ptr 
      STDMETHOD_ ULONG, AddRef
      STDMETHOD_ ULONG, Release
      STDMETHOD SetReferent, :PCSTR, :HWND
      STDMETHOD GetReferent, :POINTER, :SDWORD
      STDMETHOD SetFolder, :PCSTR
      STDMETHOD GetFolder, :POINTER, :SDWORD
      STDMETHOD GetName, :POINTER, :SDWORD
      STDMETHOD GetExtension, :POINTER, :SDWORD
    DECLARE_INTERFACE_IID__END

    INTERFACE equ <INewShortcutHookW>
    ??Interface equ <>
    DECLARE_INTERFACE_IID_(INewShortcutHookW, IUnknown, "000214f7-0000-0000-c000-000000000046")
      STDMETHOD QueryInterface, :REFIID, :ptr ptr 
      STDMETHOD_ ULONG, AddRef
      STDMETHOD_ ULONG, Release
      STDMETHOD SetReferent, :PCWSTR, :HWND
      STDMETHOD GetReferent, :POINTER, :SDWORD
      STDMETHOD SetFolder, :PCWSTR
      STDMETHOD GetFolder, :POINTER, :SDWORD
      STDMETHOD GetName, :POINTER, :SDWORD
      STDMETHOD GetExtension, :POINTER, :SDWORD
    DECLARE_INTERFACE_IID__END

    ifdef UNICODE
      INewShortcutHook equ <INewShortcutHookW>
      INewShortcutHookVtbl equ <INewShortcutHookWVtbl>
    else
      INewShortcutHook equ <INewShortcutHookA>
      INewShortcutHookVtbl equ <INewShortcutHookAVtbl>
    endif
    ;===========================================================================
    ; ICopyHook Interface
    ;  The copy hook is called whenever file system directories are
    ;  copy/moved/deleted/renamed via the shell.  It is also called by the shell
    ;  on changes of status of printers.
    ;  Clients register their id under STRREG_SHEX_COPYHOOK for file system hooks
    ;  and STRREG_SHEx_PRNCOPYHOOK for printer hooks.
    ;  the CopyCallback is called prior to the action, so the hook has the chance
    ;  to allow, deny or cancel the operation by returning the falues:
    ;     IDYES  -  means allow the operation
    ;     IDNO   -  means disallow the operation on this file, but continue with
    ;              any other operations (eg. batch copy)
    ;     IDCANCEL - means disallow the current operation and cancel any pending
    ;              operations
    ;   arguments to the CopyCallback
    ;      hwnd - window to use for any UI
    ;      wFunc - what operation is being done
    ;      wFlags - and flags (FOF_*) set in the initial call to the file operation
    ;      pszSrcFile - name of the source file
    ;      dwSrcAttribs - file attributes of the source file
    ;      pszDestFile - name of the destiation file (for move and renames)
    ;      dwDestAttribs - file attributes of the destination file
    ;===========================================================================
    INTERFACE equ <ICopyHookA>
    ??Interface equ <>
    DECLARE_INTERFACE_IID_(ICopyHookA, IUnknown, "000214EF-0000-0000-c000-000000000046")
      STDMETHOD_ UINT, CopyCallback, :HWND, :DWORD, :DWORD, :PCSTR, :DWORD, :PCSTR, :DWORD
    DECLARE_INTERFACE_IID__END

    LPCOPYHOOKA typedef ptr ICopyHookA
    INTERFACE equ <ICopyHookW>
    ??Interface equ <>
    DECLARE_INTERFACE_IID_(ICopyHookW, IUnknown, "000214FC-0000-0000-c000-000000000046")
      STDMETHOD_ UINT, CopyCallback, :HWND, :DWORD, :DWORD, :PCWSTR, :DWORD, :PCWSTR, :DWORD
    DECLARE_INTERFACE_IID__END

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
    ; IFileViewer, IFileViewerSite not supported as of win2k
    if (NTDDI_VERSION lt NTDDI_WIN2K)
      ;===========================================================================
      ; IFileViewerSite Interface
      ;===========================================================================
      INTERFACE equ <IFileViewerSite>
      ??Interface equ <>
      DECLARE_INTERFACE_IID_(IFileViewerSite, IUnknown, "000214f3-0000-0000-c000-000000000046")
        STDMETHOD SetPinnedWindow, :HWND
        STDMETHOD GetPinnedWindow, :ptr HWND
      DECLARE_INTERFACE_IID__END

      LPFILEVIEWERSITE typedef ptr IFileViewerSite
      ;===========================================================================
      ; IFileViewer Interface
      ; Implemented in a FileViewer component object.  Used to tell a
      ; FileViewer to PrintTo or to view, the latter happening though
      ; ShowInitialize and Show.  The filename is always given to the
      ; viewer through IPersistFile.
      ;===========================================================================
      include pshpack8.inc
      FVSHOWINFO struct
        ; Stuff passed into viewer (in)
        cbSize DWORD ?
        ; Size of structure for future expansion...
        hwndOwner HWND ?
        ; who is the owner window.
        iShow SDWORD ?
        ; The show command
        ; Passed in and updated  (in/Out)
        dwFlags DWORD ?
        ; flags
        rect RECT <>
        ; Where to create the window may have defaults
        punkRel POINTER ?
        ; Relese this interface when window is visible
        ; Stuff that might be returned from viewer (out)
        strNewFile OLECHAR MAX_PATH dup (?)
        ; New File to view.
      FVSHOWINFO ends
      LPFVSHOWINFO typedef ptr FVSHOWINFO
      ;* Return to byte packing *
      include poppack.inc
      ; Define File View Show Info Flags.
      FVSIF_RECT equ 00000001h; The rect variable has valid data.

      FVSIF_PINNED equ 00000002h; We should Initialize pinned

      FVSIF_NEWFAILED equ 08000000h; The new file passed back failed

      ; to be viewed.
      FVSIF_NEWFILE equ 80000000h; A new file to view has been returned

      FVSIF_CANVIEWIT equ 40000000h; The viewer can view it.

      INTERFACE equ <IFileViewerA>
      ??Interface equ <>
      DECLARE_INTERFACE_IID(IFileViewerA, "000214f0-0000-0000-c000-000000000046")
        STDMETHOD ShowInitialize, :LPFILEVIEWERSITE
        STDMETHOD Show, :LPFVSHOWINFO
        STDMETHOD PrintTo, :POINTER, :DWORD
      DECLARE_INTERFACE_IID_END

      LPFILEVIEWERA typedef ptr IFileViewerA
      INTERFACE equ <IFileViewerW>
      ??Interface equ <>
      DECLARE_INTERFACE_IID(IFileViewerW, "000214f8-0000-0000-c000-000000000046")
        STDMETHOD ShowInitialize, :LPFILEVIEWERSITE
        STDMETHOD Show, :LPFVSHOWINFO
        STDMETHOD PrintTo, :POINTER, :DWORD
      DECLARE_INTERFACE_IID_END

      LPFILEVIEWERW typedef ptr IFileViewerW
      ifdef UNICODE
        IFileViewer equ <IFileViewerW>
        LPFILEVIEWER equ <LPFILEVIEWERW>
      else
        IFileViewer equ <IFileViewerA>
        LPFILEVIEWER equ <LPFILEVIEWERA>
      endif
      ; IFileViewer, IFileViewerSite not supported as of win2k
    endif
    ; (NTDDI_VERSION < NTDDI_WIN2K)
    ;--------------------------------------------------------------------------
    ; control IDs known to the view
    ;--------------------------------------------------------------------------
    FCIDM_TOOLBAR equ (FCIDM_BROWSERFIRST + 0)
    FCIDM_STATUS equ (FCIDM_BROWSERFIRST + 1)
    ;--------------------------------------------------------------------------
    ; The resource id of the offline cursor
    ; This cursor is avaialble in shdocvw.dll
    IDC_OFFLINE_HAND equ 103
    if (_WIN32_IE ge _WIN32_IE_IE70)
      IDC_PANTOOL_HAND_OPEN equ 104
      IDC_PANTOOL_HAND_CLOSED equ 105
    endif
    ;--------------------------------------------------------------------------
    ; SBCMDID_GETPANE - not necessarily in order
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
    ; ICurrentWorkingDirectory::GetDirectory(LPWSTR pwzPath, DWORD cchSize)
    ;   This function gets the Current Working Directory from a COM object that
    ;   stores such state.
    ; ICurrentWorkingDirectory::SetDirectory(LPCWSTR pwzPath)
    ;   This function sets the Current Working Directory of a COM object that
    ;   stores such state.
    ; This function can be used generically.  One COM object that implements it
    ; is CLSID_ACListISF so that the AutoComplete engine can complete relative
    ; paths.  SetDirectory() will set the "Current Working Directory" and
    ; AutoComplete with then complete both absolute and relative paths.
    ; For Example, if ::SetDirectory(L"C:\Program Files") is called, then
    ; the user can AutoComplete "..\winnt".  In order to set the current
    ; working directory for non-file system paths, "ftp://ftp.microsoft.com/" or
    ; "Control Panel" for example, use IPersistFolder.
    INTERFACE equ <ICurrentWorkingDirectory>
    ??Interface equ <>
    DECLARE_INTERFACE_IID_(ICurrentWorkingDirectory, IUnknown, "91956D21-9276-11d1-921A-006097DF5BD4")
      STDMETHOD GetDirectory, :POINTER, :DWORD
      STDMETHOD SetDirectory, :PCWSTR
    DECLARE_INTERFACE_IID__END

    ;==========================================================================
    ; IDockingWindowSite/IDockingWindow/IDockingWindowFrame interfaces
    ; IInputObjectSite/IInputObject interfaces
    ;  These interfaces allow us (or ISVs) to install/update external Internet
    ; Toolbar for IE and the shell. The frame will simply get the CLSID from
    ; registry (to be defined) and CoCreateInstance it.
    ;==========================================================================
    ;-------------------------------------------------------------------------
    ; IDockingWindowFrame interface
    ; [Member functions]
    ; IDockingWindowFrame::AddToolbar(punkSrc, pwszItem, dwReserved)
    ; IDockingWindowFrame::RemoveToolbar(punkSrc, dwRemoveFlags)
    ; IDockingWindowFrame::FindToolbar(pwszItem, riid, ppv)
    ;-------------------------------------------------------------------------
    ; flags for RemoveToolbar
    DWFRF_NORMAL equ 0000h
    DWFRF_DELETECONFIGDATA equ 0001h
    ; flags for AddToolbar
    DWFAF_HIDDEN equ 0001h; add hidden

    DWFAF_GROUP1 equ 0002h; insert at end of group 1

    DWFAF_GROUP2 equ 0004h; insert at end of group 2

    DWFAF_AUTOHIDE equ 0010h; The toolbar will be subject to AutoHide in Full Screen mode

    INTERFACE equ <IDockingWindowFrame>
    ??Interface equ <>
    DECLARE_INTERFACE_IID_(IDockingWindowFrame, IOleWindow, "47d2657a-7b27-11d0-8ca9-00a0c92dbfe8")
      STDMETHOD AddToolbar, :ptr IUnknown, :PCWSTR, :DWORD
      STDMETHOD RemoveToolbar, :ptr IUnknown, :DWORD
      STDMETHOD FindToolbar, :PCWSTR, :REFIID, :ptr ptr 
    DECLARE_INTERFACE_IID__END

    ;* ***************** IThumbnailCapture
    ;* CaptureThumbnail : takes an IHTMLDocument2 and returns a thumbnail of specified
    ;*                    size as an hbitmap
    ;*
    INTERFACE equ <IThumbnailCapture>
    ??Interface equ <>
    DECLARE_INTERFACE_IID_(IThumbnailCapture, IUnknown, "4ea39266-7211-409f-b622-f63dbd16c533")
      ; *** IThumbnailCapture methods ***
      STDMETHOD CaptureThumbnail, :ptr SIZE, :ptr IUnknown, :ptr HBITMAP
    DECLARE_INTERFACE_IID__END

    LPTHUMBNAILCAPTURE typedef ptr IThumbnailCapture
    if (NTDDI_VERSION ge NTDDI_WIN2K and NTDDI_VERSION lt NTDDI_VISTA)
      include pshpack8.inc
      ENUMSHELLIMAGESTOREDATA struct
        szPath WORD MAX_PATH dup (?)
        ftTimeStamp FILETIME <>
      ENUMSHELLIMAGESTOREDATA ends
      _EnumImageStoreDATAtag typedef ENUMSHELLIMAGESTOREDATA
      PENUMSHELLIMAGESTOREDATA typedef ptr ENUMSHELLIMAGESTOREDATA
      ;* Return to byte packing *
      include poppack.inc
      INTERFACE equ <IEnumShellImageStore>
      ??Interface equ <>
      DECLARE_INTERFACE_IID_(IEnumShellImageStore, IUnknown, "6DFD582B-92E3-11D1-98A3-00C04FB687DA")
        STDMETHOD QueryInterface, :REFIID, :ptr ptr 
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        STDMETHOD Reset
        STDMETHOD Next, :DWORD, :ptr PENUMSHELLIMAGESTOREDATA, :ptr DWORD
        STDMETHOD Skip, :DWORD
        STDMETHOD Clone, :ptr ptr IEnumShellImageStore
      DECLARE_INTERFACE_IID__END

      LPENUMSHELLIMAGESTORE typedef ptr IEnumShellImageStore
      ; flags used to determine the capabilities of the storage for the images
      SHIMSTCAPFLAG_LOCKABLE equ 0001h; does the store require/support locking

      SHIMSTCAPFLAG_PURGEABLE equ 0002h; does the store require dead items purging externally ?

      INTERFACE equ <IShellImageStore>
      ; this interface is used to manipulate the Image cache. It can potentially be used
      ; in a free threaded manner in conjunction with the Lock parameter to Open and close
      ??Interface equ <>
      DECLARE_INTERFACE_IID_(IShellImageStore, IUnknown, "48C8118C-B924-11D1-98D5-00C04FB687DA")
        STDMETHOD QueryInterface, :REFIID, :ptr ptr 
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ; if the lock parameter is used, then all other calls into
        ; open and/or create will block until the lock is released.
        STDMETHOD Open, :DWORD, :ptr DWORD
        STDMETHOD Create, :DWORD, :ptr DWORD
        ; if the lock is passed to either of these two methods, it releases the lock
        ; once the operation is complete.
        STDMETHOD ReleaseLock, :ptr DWORD
        STDMETHOD Close, :ptr DWORD
        STDMETHOD Commit, :ptr DWORD
        STDMETHOD IsLocked
        STDMETHOD GetMode, :ptr DWORD
        STDMETHOD GetCapabilities, :ptr DWORD
        STDMETHOD AddEntry, :PCWSTR, :ptr FILETIME, :DWORD, :HBITMAP
        STDMETHOD GetEntry, :PCWSTR, :DWORD, :ptr HBITMAP
        STDMETHOD DeleteEntry, :PCWSTR
        STDMETHOD IsEntryInStore, :PCWSTR, :ptr FILETIME
        STDMETHOD Enum, :ptr LPENUMSHELLIMAGESTORE
      DECLARE_INTERFACE_IID__END

      LPSHELLIMAGESTORE typedef ptr IShellImageStore
    endif
    ; (NTDDI_VERSION >= NTDDI_WIN2K && NTDDI_VERSION < NTDDI_VISTA)
    ;//  IShellFolderBand
    ; Field mask
    ISFB_MASK_STATE equ 00000001h; TRUE if dwStateMask and dwState is valid

    ISFB_MASK_BKCOLOR equ 00000002h; TRUE if crBkgnd field is valid

    ISFB_MASK_VIEWMODE equ 00000004h; TRUE if wViewMode field is valid

    ISFB_MASK_SHELLFOLDER equ 00000008h
    ISFB_MASK_IDLIST equ 00000010h
    ISFB_MASK_COLORS equ 00000020h; TRUE if crXXXX fields are valid (except bkgnd)

    ISFB_STATE_DEFAULT equ 00000000h
    ISFB_STATE_DEBOSSED equ 00000001h
    ISFB_STATE_ALLOWRENAME equ 00000002h
    ISFB_STATE_NOSHOWTEXT equ 00000004h; TRUE if _fNoShowText

    ISFB_STATE_CHANNELBAR equ 00000010h; TRUE if we want NavigateTarget support

    ISFB_STATE_QLINKSMODE equ 00000020h; TRUE if we want to turn off drag & drop onto content items

    ISFB_STATE_FULLOPEN equ 00000040h; TRUE if band should maximize when opened

    ISFB_STATE_NONAMESORT equ 00000080h; TRUE if band should _not_ sort icons by name

    ISFB_STATE_BTNMINSIZE equ 00000100h; TRUE if band should report min thickness of button

    ISFBVIEWMODE_SMALLICONS equ 0001h
    ISFBVIEWMODE_LARGEICONS equ 0002h
    if (_WIN32_IE lt _WIN32_IE_IE70)
      ISFBVIEWMODE_LOGOS equ 0003h
    endif
    include pshpack8.inc
    BANDINFOSFB struct
      dwMask DWORD ?
      ; [in] ISFB_MASK mask of valid fields from crBkgnd on
      dwStateMask DWORD ?
      ; [in] ISFB_STATE mask of dwState bits being set/queried
      dwState DWORD ?
      ; [in/out] ISFB_STATE bits
      crBkgnd COLORREF ?
      ; [in/out]
      crBtnLt COLORREF ?
      ; [in/out]
      crBtnDk COLORREF ?
      ; [in/out]
      wViewMode WORD ?
      ; [in/out]
      wAlign WORD ?
      ; not used (yet)
      psf POINTER ?
      ; [out]
      pidl PIDLIST_ABSOLUTE ?
      ; [out]
    BANDINFOSFB ends
    PBANDINFOSFB typedef ptr BANDINFOSFB
    ;* Return to byte packing *
    include poppack.inc
    INTERFACE equ <IShellFolderBand>
    ??Interface equ <>
    DECLARE_INTERFACE_IID_(IShellFolderBand, IUnknown, "7FE80CC8-C247-11d0-B93A-00A0C90312E1")
      STDMETHOD InitializeSFB, :ptr IShellFolder, :PCIDLIST_ABSOLUTE
      STDMETHOD SetBandInfoSFB, :PBANDINFOSFB
      STDMETHOD GetBandInfoSFB, :PBANDINFOSFB
    DECLARE_INTERFACE_IID__END

    ; Command Target IDs
    SFBID_PIDLCHANGED equ 0

    ;//  IDeskBarClient
    INTERFACE equ <IDeskBarClient>
    ??Interface equ <>
    DECLARE_INTERFACE_IID_(IDeskBarClient, IOleWindow, "EB0FE175-1A3A-11D0-89B3-00A0C90A90AC")
      STDMETHOD SetDeskBarSite, :ptr IUnknown
      STDMETHOD SetModeDBC, :DWORD
      STDMETHOD UIActivateDBC, :DWORD
      STDMETHOD GetSize, :DWORD, :LPRECT
    DECLARE_INTERFACE_IID__END

    DBC_GS_IDEAL equ 0; get the ideal size

    DBC_GS_SIZEDOWN equ 1; clip the height of a rect to a multiple of the rebar's integral size

    DBC_HIDE equ 0; Band is hidden (being destroyed)

    DBC_SHOW equ 1; Band is visible

    DBC_SHOWOBSCURE equ 2; Band is completely obscured

    DBCID_EMPTY equ 0
    ; bandsite is empty
    DBCID_ONDRAG equ 1
    ; (down)DragMoveEnter/Leave vaIn:I4:eDrag
    DBCID_CLSIDOFBAR equ 2
    ; clsid of bar inside
    DBCID_RESIZE equ 3
    ; resize from keyboard accelerator
    DBCID_GETBAR equ 4
    ; returns vaOut:VT_UNKNOWN of hosting dockbar (IDeskBar)
    DBCID_UPDATESIZE equ 5
    ; resize from non-user source (search activation failure)

    ; Flags for SetSafeMode
    SSM_CLEAR equ 0000h
    SSM_SET equ 0001h
    SSM_REFRESH equ 0002h
    SSM_UPDATE equ 0004h
    ; Flags for Set/GetScheme
    SCHEME_DISPLAY equ 0001h
    SCHEME_EDIT equ 0002h
    SCHEME_LOCAL equ 0004h
    SCHEME_GLOBAL equ 0008h
    SCHEME_REFRESH equ 0010h
    SCHEME_UPDATE equ 0020h
    SCHEME_DONOTUSE equ 0040h; used to be SCHEME_ENUMERATE; no longer supported

    SCHEME_CREATE equ 0080h
    INTERFACE equ <IActiveDesktopP>
    ??Interface equ <>
    DECLARE_INTERFACE_IID_(IActiveDesktopP, IUnknown, "52502EE0-EC80-11D0-89AB-00C04FC2972D")
      ; IUnknown methods
      STDMETHOD QueryInterface, :REFIID, :ptr ptr 
      STDMETHOD_ ULONG, AddRef
      STDMETHOD_ ULONG, Release
      ; IActiveDesktopP methods
      STDMETHOD SetSafeMode, :DWORD
      STDMETHOD EnsureUpdateHTML
      STDMETHOD SetScheme, :PCWSTR, :DWORD
      STDMETHOD GetScheme, :POINTER, :ptr DWORD, :DWORD
    DECLARE_INTERFACE_IID__END

    LPACTIVEDESKTOPP typedef ptr IActiveDesktopP
    ;Flags for GetObjectFlags
    GADOF_DIRTY equ 00000001h
    INTERFACE equ <IADesktopP2>
    ??Interface equ <>
    DECLARE_INTERFACE_IID_(IADesktopP2, IUnknown, "B22754E2-4574-11d1-9888-006097DEACF9")
      ; IUnknown methods
      STDMETHOD QueryInterface, :REFIID, :ptr ptr 
      STDMETHOD_ ULONG, AddRef
      STDMETHOD_ ULONG, Release
      ; IADesktopP2 methods
      STDMETHOD ReReadWallpaper
      STDMETHOD GetADObjectFlags, :ptr DWORD, :DWORD
      STDMETHOD UpdateAllDesktopSubscriptions
      STDMETHOD MakeDynamicChanges, :ptr IOleObject
    DECLARE_INTERFACE_IID__END

    LPADESKTOPP2 typedef ptr IADesktopP2
    include pshpack1.inc
    SHCOLUMNINFO struct
      scid SHCOLUMNID <>
      ; OUT the unique identifier of this column
      vt VARTYPE ?
      ; OUT the native type of the data returned
      fmt DWORD ?
      ; OUT this listview format (LVCFMT_LEFT, usually)
      cChars DWORD ?
      ; OUT the default width of the column, in characters
      csFlags DWORD ?
      ; OUT SHCOLSTATE flags
      wszTitle WORD MAX_COLUMN_NAME_LEN dup (?)
      ; OUT the title of the column
      wszDescription WORD MAX_COLUMN_DESC_LEN dup (?)
      ; OUT full description of this column
    SHCOLUMNINFO ends
    LPSHCOLUMNINFO typedef ptr SHCOLUMNINFO
    LPCSHCOLUMNINFO typedef ptr SHCOLUMNINFO
    ;* Return to default *
    include poppack.inc
    include pshpack8.inc
    SHCOLUMNINIT struct
      dwFlags DWORD ?
      ; initialization flags
      dwReserved DWORD ?
      ; reserved for future use.
      wszFolder WORD MAX_PATH dup (?)
      ; fully qualified folder path (or empty if multiple folders)
    SHCOLUMNINIT ends
    LPSHCOLUMNINIT typedef ptr SHCOLUMNINIT
    LPCSHCOLUMNINIT typedef ptr SHCOLUMNINIT
    SHCDF_UPDATEITEM equ 00000001h; this flag is a hint that the file has changed since the last call to GetItemData

    SHCOLUMNDATA struct
      dwFlags DWORD ?
      ; combination of SHCDF_ flags.
      dwFileAttributes DWORD ?
      ; file attributes.
      dwReserved DWORD ?
      ; reserved for future use.
      pwszExt POINTER ?
      ; address of file name extension
      wszFile WORD MAX_PATH dup (?)
      ; Absolute path of file.
    SHCOLUMNDATA ends
    LPSHCOLUMNDATA typedef ptr SHCOLUMNDATA
    LPCSHCOLUMNDATA typedef ptr SHCOLUMNDATA
    ;* Return to byte packing *
    include poppack.inc
    INTERFACE equ <IColumnProvider>
    ; Note: these objects must be threadsafe!  GetItemData _will_ be called
    ; simultaneously from multiple threads.
    ??Interface equ <>
    DECLARE_INTERFACE_IID_(IColumnProvider, IUnknown, "E8025004-1C42-11d2-BE2C-00A0C9A83DA1")
      ; IUnknown methods
      STDMETHOD QueryInterface, :REFIID, :ptr ptr 
      STDMETHOD_ ULONG, AddRef
      STDMETHOD_ ULONG, Release
      ; IColumnProvider methods
      STDMETHOD Initialize, :LPCSHCOLUMNINIT
      STDMETHOD GetColumnInfo, :DWORD, :ptr SHCOLUMNINFO
      STDMETHOD GetItemData, :LPCSHCOLUMNID, :LPCSHCOLUMNDATA, :ptr VARIANT
    DECLARE_INTERFACE_IID__END

    if (NTDDI_VERSION ge NTDDI_WIN2K)
      SHChangeProductKeyAsIDList struct
        cb WORD ?
        wszProductKey WORD 39 dup (?)
        cbZero WORD ?
      SHChangeProductKeyAsIDList ends
      _SHChangeProductKeyAsIDList typedef SHChangeProductKeyAsIDList
      LPSHChangeProductKeyAsIDList typedef ptr SHChangeProductKeyAsIDList
      ;* NTDDI_WIN2K *
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      ;  use SHChangeNotifyRegisterThread() to enable Async Register and Deregister.
      ;  call with SCNRT_ENABLE at the thread proc begining and SCNRT_DISABLE at the end
      ;  the call with SCNRT_DISABLE can block while it synchronizes with the main ChangeNotify thread
      @DefProto DllImport, SHChangeNotifyRegisterThread, WIN_STD_CALL_CONV,, <:SCNRT_STATUS>, 4
    endif
    ;===========================================================================
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
    ; !UNICODE
    @DefProto DllImport, GetFileNameFromBrowse, WIN_STD_CALL_CONV,, <:HWND, :PWSTR, :UINT, :PCWSTR, :PCWSTR, :PCWSTR, :PCWSTR>, 28
    @DefProto DllImport, DriveType, WIN_STD_CALL_CONV,, <:SDWORD>, 4
    @DefProto DllImport, SHCreatePropSheetExtArray, WIN_STD_CALL_CONV,, <:HKEY, :PCWSTR, :UINT>, 12
    if (NTDDI_VERSION ge NTDDI_WIN2K and NTDDI_VERSION lt NTDDI_VISTA)
      INTERFACE equ <IDefViewFrame>
      ??Interface equ <>
      DECLARE_INTERFACE_IID_(IDefViewFrame, IUnknown, "710EB7A0-45ED-11D0-924A-0020AFC7AC4D")
        STDMETHOD GetWindowLV, :ptr HWND
        STDMETHOD ReleaseWindowLV
        STDMETHOD GetShellFolder, :ptr ptr IShellFolder
      DECLARE_INTERFACE_IID__END

    endif
    if (NTDDI_VERSION lt NTDDI_VISTA)
      ; Path processing function
      PPCF_ADDQUOTES equ 00000001h; return a quoted name if required

      PPCF_ADDARGUMENTS equ 00000003h; appends arguments (and wraps in quotes if required)

      PPCF_NODIRECTORIES equ 00000010h; don't match to directories

      PPCF_FORCEQUALIFY equ 00000040h; qualify even non-relative names

      PPCF_LONGESTPOSSIBLE equ 00000080h; always find the longest possible name

      @DefProto DllImport, PathProcessCommand, WIN_STD_CALL_CONV,, <:PCWSTR, :PWSTR, :SDWORD, :DWORD>, 16
    endif
    if (NTDDI_VERSION lt NTDDI_VISTA)
      @DefProto DllImport, SHLoadOLE, WIN_STD_CALL_CONV,, <:LPARAM>, 4
    endif
    ; IDocViewSite
    INTERFACE equ <IDocViewSite>
    ??Interface equ <>
    DECLARE_INTERFACE_IID_(IDocViewSite, IUnknown, "87D605E0-C511-11CF-89A9-00A0C9054129")
      STDMETHOD OnSetTitle, :ptr VARIANTARG
    DECLARE_INTERFACE_IID__END

    OPENPROPS_NONE equ 0000h
    OPENPROPS_INHIBITPIF equ 8000h
    GETPROPS_NONE equ 0000h
    SETPROPS_NONE equ 0000h
    CLOSEPROPS_NONE equ 0000h
    CLOSEPROPS_DISCARD equ 0001h
    INTERFACE equ <IInitializeObject>
    ??Interface equ <>
    DECLARE_INTERFACE_IID_(IInitializeObject, IUnknown, "4622AD16-FF23-11d0-8D34-00A0C90F2719")
      STDMETHOD Initialize
    DECLARE_INTERFACE_IID__END

    BMICON_LARGE equ 0
    BMICON_SMALL equ 1

    INTERFACE equ <IBanneredBar>
    ??Interface equ <>
    DECLARE_INTERFACE_IID_(IBanneredBar, IUnknown, "596A9A94-013E-11d1-8D34-00A0C90F2719")
      STDMETHOD SetIconSize, :DWORD
      STDMETHOD GetIconSize, :ptr DWORD
      STDMETHOD SetBitmap, :HBITMAP
      STDMETHOD GetBitmap, :ptr HBITMAP
    DECLARE_INTERFACE_IID__END

    include pshpack8.inc
    ; TBINFO flags
    TBIF_APPEND equ 0
    TBIF_PREPEND equ 1
    TBIF_REPLACE equ 2
    TBIF_DEFAULT equ 00000000h
    TBIF_INTERNETBAR equ 00010000h
    TBIF_STANDARDTOOLBAR equ 00020000h
    TBIF_NOTOOLBAR equ 00030000h
    TBINFO struct
      cbuttons DWORD ?
      ; out
      uFlags DWORD ?
      ; out (one of TBIF_ flags)
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
    ; !UNICODE
    ; Tell the FolderView to rearrange.  The lParam will be passed to
    ; IShellFolder::CompareIDs
    SFVM_REARRANGE equ 00000001h
    ShellFolderView_ReArrange macro _hwnd, _lparam
      exitm <SHShellFolderView_Message (_hwnd, SFVM_REARRANGE, _lparam)>
    endm
    ; Add an OBJECT into the view
    SFVM_ADDOBJECT equ 00000003h
    ShellFolderView_AddObject macro _hwnd, _pidl
      exitm <SHShellFolderView_Message (_hwnd, SFVM_ADDOBJECT, (_pidl))>
    endm
    ; Remove an OBJECT into the view
    SFVM_REMOVEOBJECT equ 00000006h
    ShellFolderView_RemoveObject macro _hwnd, _pidl
      exitm <SHShellFolderView_Message (_hwnd, SFVM_REMOVEOBJECT, (_pidl))>
    endm
    ; updates an object by passing in pointer to two PIDLS, the first
    ; is the old pidl, the second one is the one with update information.
    ; _ppidl[1] must be a *copy* of a pidl, as control over the lifetime
    ; of the pidl belongs to the view after successful completion of
    ; this call.  (Unsuccessful completion (a -1 return) implies failure
    ; and the caller must free the memory.)  Win95 waits a while before
    ; freeing the pidl, IE4 frees the pidl immediately.
    ; IShellFolderView::UpdateObject does not suffer from this problem.
    SFVM_UPDATEOBJECT equ 00000007h
    ShellFolderView_UpdateObject macro _hwnd, _ppidl
      exitm <SHShellFolderView_Message (_hwnd, SFVM_UPDATEOBJECT, (_ppidl))>
    endm
    ; Returns an array of the selected IDS to the caller.
    ;     lparam is a pointer to receive the idlists into
    ;     return value is the count of items in the array.
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
    ; Sets the position of an item in the viewer
    ;     lparam is a pointer to a SVF_SETITEMPOS
    ;     return value is unused
    SFVM_SETITEMPOS equ 0000000eh
    ShellFolderView_SetItemPos macro _hwnd, _pidl, _x, _y
      exitm <{ SFV_SETITEMPOS _sip = { _pidl, { _x, _y } } ; SHShellFolderView_Message (_hwnd, SFVM_SETITEMPOS, (LPSFV_SETITEMPOS) and _sip) ; }>
    endm
    ;  Notifies a ShellView when one of its objects get put on the clipboard
    ;  as a result of a menu command.
    ;     lparam is the dwEffect (DROPEFFECT_MOVE, DROPEFFECT_COPY)
    ;     return value is void.
    SFVM_SETCLIPBOARD equ 00000010h
    ShellFolderView_SetClipboard macro _hwnd, _dwEffect
      exitm <SHShellFolderView_Message (_hwnd, SFVM_SETCLIPBOARD, (_dwEffect))>
    endm
    SFVM_SETPOINTS equ 00000017h
    ShellFolderView_SetPoints macro _hwnd, _pdtobj
      exitm <SHShellFolderView_Message (_hwnd, SFVM_SETPOINTS, (_pdtobj))>
    endm
    ;* Return to byte packing *
    include poppack.inc
    ifdef __urlmon_h__
      ;    NOTE: urlmon.h must be included before shlobj.h to access this function.
      ;    SoftwareUpdateMessageBox
      ;    Provides a standard message box for the alerting the user that a software
      ;    update is available or installed. No UI will be displayed if there is no
      ;    update available or if the available update version is less than or equal
      ;    to the Advertised update version.
      ;    hWnd                - [in] Handle of owner window
      ;    szDistUnit          - [in] Unique identifier string for a code distribution unit. For
      ;                               ActiveX controls and Active Setup installed components, this
      ;                               is typically a GUID string.
      ;    dwFlags             - [in] Must be 0.
      ;    psdi                - [in,out] Pointer to SOFTDISTINFO ( see URLMon.h ). May be NULL.
      ;                                cbSize should be initialized
      ;                                by the caller to sizeof(SOFTDISTINFO), dwReserved should be set to 0.
      ;    RETURNS:
      ;    IDNO     - The user chose cancel. If *pbRemind is FALSE, the caller should save the
      ;               update version from the SOFTDISTINFO and pass it in as the Advertised
      ;               version in future calls.
      ;    IDYES    - The user has selected Update Now/About Update. The caller should navigate to
      ;               the SOFTDISTINFO's pszHREF to initiate the install or learn about it.
      ;               The caller should save the update version from the SOFTDISTINFO and pass
      ;               it in as the Advertised version in future calls.
      ;    IDIGNORE - There is no pending software update. Note: There is
      ;               no Ignore button in the standard UI. This occurs if the available
      ;               version is less than the installed version or is not present or if the
      ;               Advertised version is greater than or equal to the update version.
      ;    IDABORT  - An error occured. Call GetSoftwareUpdateInfo() for a more specific HRESULT.
      ;               Note: There is no Abort button in the standard UI.
      @DefProto DllImport, SoftwareUpdateMessageBox, WIN_STD_CALL_CONV,, <:HWND, :PCWSTR, :DWORD, :LPSOFTDISTINFO>, 16
    endif
    ; if __urlmon_h__
    if (NTDDI_VERSION ge NTDDI_WINXP)
      include pshpack8.inc
      ;* Return to byte packing *
      include poppack.inc
    endif
    ; NTDDI_WINXP
    if (NTDDI_VERSION ge NTDDI_WIN2K)
      ; The SHMultiFileProperties API displays a property sheet for a
      ; set of files specified in an IDList Array.
      ; Parameters:
      ;      pdtobj  - Data object containing list of files.  The data
      ;                object must provide the "Shell IDList Array"
      ;                clipboard format.  The parent folder's implementation of
      ;                IShellFolder::GetDisplayNameOf must return a fully-qualified
      ;                filesystem path for each item in response to the
      ;                SHGDN_FORPARSING flag.
      ;      dwFlags - Reserved for future use.  Should be set to 0.
      ; Returns:
      ;      S_OK
      @DefProto DllImport, SHMultiFileProperties, WIN_STD_CALL_CONV,, <:ptr IDataObject, :DWORD>, 8
    endif
    ; NTDDI_WIN2K
    @DefProto DllImport, SHCreateQueryCancelAutoPlayMoniker, WIN_STD_CALL_CONV,, <:ptr ptr IMoniker>, 4
    ; deprecated: use CreateClassMoniker(CLSID_YourOwnClsid, ...)
    @DefProto DllImport, PerUserInit, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, SHRunControlPanel, WIN_STD_CALL_CONV,, <:PCWSTR, :HWND>, 8
    include pshpack8.inc
    AASHELLMENUFILENAME struct
      cbTotal SWORD ?
      rgbReserved BYTE 12 dup (?)
      szFileName WORD 1 dup (?)
      ; variable length string
    AASHELLMENUFILENAME ends
    tagAAMENUFILENAME typedef AASHELLMENUFILENAME
    LPAASHELLMENUFILENAME typedef ptr AASHELLMENUFILENAME
    AASHELLMENUITEM struct
      lpReserved1 POINTER ?
      iReserved SDWORD ?
      uiReserved DWORD ?
      lpName LPAASHELLMENUFILENAME ?
      ; name of file
      psz POINTER ?
      ; text to use if no file
    AASHELLMENUITEM ends
    tagAASHELLMENUITEM typedef AASHELLMENUITEM
    LPAASHELLMENUITEM typedef ptr AASHELLMENUITEM
    ;* Return to byte packing *
    include poppack.inc
    if (_WIN32_IE ge _WIN32_IE_XP)
      @DefProto DllImport, ImportPrivacySettings, WIN_STD_CALL_CONV,, <:PCWSTR, :ptr BOOL, :ptr BOOL>, 12
      ifndef IEnumPrivacyRecords
      endif
      @DefProto DllImport, DoPrivacyDlg, WIN_STD_CALL_CONV,, <:HWND, :PCWSTR, :ptr IEnumPrivacyRecords, :BOOL>, 16
    endif
    ; _WIN32_IE_XP
    include poppack.inc
    ifdef __cplusplus
      ;[...]
    endif
    if (_MSC_VER ge 800)
      if (_MSC_VER ge 1200)
      else
      endif
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  ;* _SHLOBJ_H_ *
endif
