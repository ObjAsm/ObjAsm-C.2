;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\shlobj_core.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 21/02/2024 18:17:24

;===========================================================================*
include winapifamily.inc
if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
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
  ifndef INITGUID
    include shlguid.inc
    ;* !INITGUID *
  endif
  include shtypes.inc
  include shobjidl_core.inc
  if Defined(_MSC_VER) and (_MSC_VER ge 1200)
  endif
  ifdef __cplusplus
    ;[...]
  endif
  ;* Assume byte packing throughout *
  include pshpack1.inc
  ;===========================================================================
  ; Legacy exports that are no longer needed, call the COM API instead
  ;===========================================================================
  @DefProto DllImport, SHGetMalloc, WIN_STD_CALL_CONV,, <:ptr ptr IMalloc>, 4
  ; CoGetMalloc(MEMCTX_TASK,ppMalloc)
  @DefProto DllImport, SHAlloc, WIN_STD_CALL_CONV,, <:SIZE_T>, 4
  ; CoTaskMemAlloc(cb)
  @DefProto DllImport, SHFree, WIN_STD_CALL_CONV,, <:ptr>, 4
  ; CoTaskMemFree(pv)
  ;===========================================================================
  ; IExtractIcon interface
  ;  This interface is used in two different places in the shell.
  ; Case-1: Icons of sub-folders for the scope-pane of the explorer.
  ;  It is used by the explorer to get the "icon location" of
  ; sub-folders from each shell folders. When the user expands a folder
  ; in the scope pane of the explorer, the explorer does following:
  ;  (1) binds to the folder (gets IShellFolder),
  ;  (2) enumerates its sub-folders by calling its EnumObjects member,
  ;  (3) calls its GetUIObjectOf member to get IExtractIcon interface
  ;     for each sub-folders.
  ;  In this case, the explorer uses only IExtractIcon::GetIconLocation
  ; member to get the location of the appropriate icon. An icon location
  ; always consists of a file name (typically DLL or EXE) and either an icon
  ; resource or an icon index.
  ; Case-2: Extracting an icon image from a file
  ;  It is used by the shell when it extracts an icon image
  ; from a file. When the shell is extracting an icon from a file,
  ; it does following:
  ;  (1) creates the icon extraction handler object (by getting its CLSID
  ;     under the {ProgID}\shell\ExtractIconHanler key and calling
  ;     CoCreateInstance requesting for IExtractIcon interface).
  ;  (2) Calls IExtractIcon::GetIconLocation.
  ;  (3) Then, calls IExtractIcon::ExtractIcon with the location/index pair.
  ;  (4) If (3) returns S_OK, it uses the returned icon.
  ;  (5) Otherwise, it recursively calls this logic with new location
  ;     assuming that the location string contains a fully qualified path name.
  ;  From extension programmer's point of view, there are only two cases
  ; where they provide implementations of IExtractIcon:
  ;  Case-1) providing explorer extensions (i.e., IShellFolder).
  ;  Case-2) providing per-instance icons for some types of files.
  ; Because Case-1 is described above, we'll explain only Case-2 here.
  ; When the shell is about display an icon for a file, it does following:
  ;  (1) Finds its ProgID and ClassID.
  ;  (2) If the file has a ClassID, it gets the icon location string from the
  ;    "DefaultIcon" key under it. The string indicates either per-class
  ;    icon (e.g., "EXAMPLE.DLL,2") or per-instance icon (e.g., "%1,1").
  ;  (3) If a per-instance icon is specified, the shell creates an icon
  ;    extraction handler object for it, and extracts the icon from it
  ;    (which is described above).
  ;  It is important to note that the shell calls IExtractIcon::GetIconLocation
  ; first, then calls IExtractIcon::Extract. Most application programs
  ; that support per-instance icons will probably store an icon location
  ; (DLL/EXE name and index/id) rather than an icon image in each file.
  ; In those cases, a programmer needs to implement only the GetIconLocation
  ; member and it Extract member simply returns S_FALSE. They need to
  ; implement Extract member only if they decided to store the icon images
  ; within files themselved or some other database (which is very rare).
  ; [Member functions]
  ; IExtractIcon::GetIconLocation
  ;  This function returns an icon location.
  ;  Parameters:
  ;   uFlags     [in]  -- Specifies if it is opened or not (GIL_OPENICON or 0)
  ;   szIconFile [out] -- Specifies the string buffer buffer for a location name.
  ;   cchMax     [in]  -- Specifies the size of szIconFile (almost always MAX_PATH)
  ;   piIndex    [out] -- Sepcifies the address of UINT for the index.
  ;   pwFlags    [out] -- Returns GIL_* flags
  ;  Returns:
  ;   S_OK, if it returns a valid location; S_FALSE, if the shell use a
  ;   default icon.
  ;  Notes: The location may or may not be a path to a file. The caller can
  ;   not assume anything unless the subsequent Extract member call returns
  ;   S_FALSE.
  ;   if the returned location is not a path to a file, GIL_NOTFILENAME should
  ;   be set in the returned flags.
  ; IExtractIcon::Extract
  ;  This function extracts an icon image from a specified file.
  ;  Parameters:
  ;   pszFile [in] -- Specifies the icon location (typically a path to a file).
  ;   nIconIndex [in] -- Specifies the icon index.
  ;   phiconLarge [out] -- Specifies the HICON variable for large icon.
  ;   phiconSmall [out] -- Specifies the HICON variable for small icon.
  ;   nIconSize [in] -- Specifies the size icon required (size of large icon)
  ;                     LOWORD is the requested large icon size
  ;                     HIWORD is the requested small icon size
  ;  Returns:
  ;   S_OK, if it extracted the from the file.
  ;   S_FALSE, if the caller should extract from the file specified in the
  ;           location.
  ;===========================================================================
  ; GetIconLocation() input flags
  GIL_OPENICON equ 0001h; allows containers to specify an "open" look

  GIL_FORSHELL equ 0002h; icon is to be displayed in a ShellFolder

  GIL_ASYNC equ 0020h; this is an async extract, return E_PENDING

  GIL_DEFAULTICON equ 0040h; get the default icon location if the final one takes too long to get

  GIL_FORSHORTCUT equ 0080h; the icon is for a shortcut to the object

  GIL_CHECKSHIELD equ 0200h; return GIL_SHIELD or GIL_FORCENOSHIELD, don't block if GIL_ASYNC is set

  ; GetIconLocation() return flags
  GIL_SIMULATEDOC equ 0001h; simulate this document icon for this

  GIL_PERINSTANCE equ 0002h; icons from this class are per instance (each file has its own)

  GIL_PERCLASS equ 0004h; icons from this class per class (shared for all files of this type)

  GIL_NOTFILENAME equ 0008h; location is not a filename, must call ::ExtractIcon

  GIL_DONTCACHE equ 0010h; this icon should not be cached

  GIL_SHIELD equ 0200h; icon should be "stamped" with the LUA shield

  GIL_FORCENOSHIELD equ 0400h; icon must *not* be "stamped" with the LUA shield

  INTERFACE equ <IExtractIconA>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(IExtractIconA, IUnknown, "000214eb-0000-0000-c000-000000000046")
    STDMETHOD GetIconLocation, :DWORD, :POINTER, :DWORD, :ptr SDWORD, :ptr DWORD
    STDMETHOD Extract, :PCSTR, :DWORD, :ptr HICON, :ptr HICON, :DWORD
  DECLARE_INTERFACE_IID__END

  LPEXTRACTICONA typedef ptr IExtractIconA
  INTERFACE equ <IExtractIconW>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(IExtractIconW, IUnknown, "000214fa-0000-0000-c000-000000000046")
    STDMETHOD GetIconLocation, :DWORD, :POINTER, :DWORD, :ptr SDWORD, :ptr DWORD
    STDMETHOD Extract, :PCWSTR, :DWORD, :ptr HICON, :ptr HICON, :DWORD
  DECLARE_INTERFACE_IID__END

  LPEXTRACTICONW typedef ptr IExtractIconW
  ifdef UNICODE
    IExtractIcon equ <IExtractIconW>
    IExtractIconVtbl equ <IExtractIconWVtbl>
    LPEXTRACTICON equ <LPEXTRACTICONW>
  else
    IExtractIcon equ <IExtractIconA>
    IExtractIconVtbl equ <IExtractIconAVtbl>
    LPEXTRACTICON equ <LPEXTRACTICONA>
  endif
  ;===========================================================================
  ; IShellIconOverlayManager
  ; Used to return the icon overlay information including OverlayIndex, Image Index or Priority for an IShellFolder object.
  ; IShellIconOverlayManager:GetFileOverlayInfo(LPCWSTR pwszPath, DWORD dwAttrib, int * pIndex, DWORD dwflags)
  ;      pwszPath        full path of the file
  ;      dwAttrib        attribute of this file
  ;      pIndex          pointer to the Icon Index in the system image list
  ;      pOverlayIndex   pointer to the OverlayIndex in the system image list
  ;      pPriority       pointer to the Priority of this overlay
  ; IShellIconOverlayManager:GetReservedOverlayInfo(LPCWSTR pwszPath, DWORD dwAttrib, int * pIndex, DWORD dwflags, int iReservedID)
  ;      iReservedID     reserved icon overlay id
  ;  returns:
  ;      S_OK,  if the index of an Overlay is found
  ;      S_FALSE, if no Overlay exists for this file
  ;      E_FAIL, if lpfd is bad
  ; IShellIconOverlayManager:RefreshOverlayImages(DWORD dwFlags)
  ;      This will refresh the overlay cache, depends on the dwFlags passed in
  ;      It will reload the icons into the imagelist, when passed SIOM_ICONINDEX
  ; IShellIconOverlayManager::LoadNonloadedOverlayIdentifiers()
  ;      This method loads any registered overlay identifiers (handlers) that
  ;      are not currently loaded.
  ; IShellIconOverlayManager::OverlayIndexFromImageIndex(int iImage, int *piIndex, BOOL fAdd)
  ;      iImage          existing shell image list index to look for
  ;      piIndex         returned overlay index
  ;      fAdd            Add image if not already present?
  ;===========================================================================
  INTERFACE equ <IShellIconOverlayManager>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(IShellIconOverlayManager, IUnknown, "f10b5e34-dd3b-42a7-aa7d-2f4ec54bb09b")
    STDMETHOD GetFileOverlayInfo, :PCWSTR, :DWORD, :ptr SDWORD, :DWORD
    STDMETHOD GetReservedOverlayInfo, :PCWSTR, :DWORD, :ptr SDWORD, :DWORD, :SDWORD
    STDMETHOD RefreshOverlayImages, :DWORD
    STDMETHOD LoadNonloadedOverlayIdentifiers
    STDMETHOD OverlayIndexFromImageIndex, :SDWORD, :ptr SDWORD, :DWORD
  DECLARE_INTERFACE_IID__END

  SIOM_OVERLAYINDEX equ 1h
  SIOM_ICONINDEX equ 2h
  SIOM_RESERVED_SHARED equ 0
  SIOM_RESERVED_LINK equ 1
  SIOM_RESERVED_SLOWFILE equ 2
  SIOM_RESERVED_DEFAULT equ 3
  ;===========================================================================
  ; IShellIconOverlay
  ; Used to return the icon overlay index or its icon index for an IShellFolder object,
  ; this is always implemented with IShellFolder
  ; IShellIconOverlay:GetOverlayIndex(LPCITEMIDLIST pidl, DWORD * pdwIndex)
  ;      pidl            object to identify icon overlay for.
  ;      pdwIndex        the Overlay Index in the system image list
  ; IShellIconOverlay:GetOverlayIconIndex(LPCITEMIDLIST pidl, DWORD * pdwIndex)
  ;      pdwIconIndex    the Overlay Icon index in the system image list
  ; This method is only used for those who are interested in seeing the real bits
  ; of the Overlay Icon
  ;  returns:
  ;      S_OK,  if the index of an Overlay is found
  ;      S_FALSE, if no Overlay exists for this file
  ;      E_FAIL, if pidl is bad
  ;===========================================================================
  INTERFACE equ <IShellIconOverlay>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(IShellIconOverlay, IUnknown, "7d688a70-c613-11d0-999b-00c04fd655e1")
    STDMETHOD GetOverlayIndex, :PCUITEMID_CHILD, :ptr SDWORD
    STDMETHOD GetOverlayIconIndex, :PCUITEMID_CHILD, :ptr SDWORD
  DECLARE_INTERFACE_IID__END

  OI_DEFAULT equ 00000000h
  OI_ASYNC equ 0FFFFEEEEh
  ;-------------------------------------------------------------------------
  ; SHGetIconOverlayIndex
  ; This function takes the path and icon/res id to the icon and convert it into
  ; an overlay index in the system image list.
  ; Note: there are totally only 15 slots for system image overlays, some of which
  ; was reserved by the system, or taken by the overlayidentifiers, so it's possible
  ; that this function would fail and return -1;
  ; To get the default overlays in the system, such as the share hand, link shortcut
  ; and slow files, pass NULL as the file name, then the IDO_SHGIOI_* flags as the icon index
  ;-------------------------------------------------------------------------
  IDO_SHGIOI_SHARE equ 0FFFFFFFh
  IDO_SHGIOI_LINK equ 0FFFFFFEh
  IDO_SHGIOI_SLOWFILE equ 0FFFFFFFDh
  IDO_SHGIOI_DEFAULT equ 0FFFFFFFCh
  @DefProto DllImport, SHGetIconOverlayIndexA, WIN_STD_CALL_CONV,, <:LPCSTR, :SDWORD>, 8
  @DefProto DllImport, SHGetIconOverlayIndexW, WIN_STD_CALL_CONV,, <:LPCWSTR, :SDWORD>, 8
  ifdef UNICODE
    SHGetIconOverlayIndex equ <SHGetIconOverlayIndexW>
  else
    SHGetIconOverlayIndex equ <SHGetIconOverlayIndexA>
  endif
  ; !UNICODE
  ; IShellLinkDataList::GetFlags()/SetFlags()
  SHELL_LINK_DATA_FLAGS typedef SDWORD
  SLDF_DEFAULT equ 00000000h
  SLDF_HAS_ID_LIST equ 00000001h
  ; Shell link saved with ID list
  SLDF_HAS_LINK_INFO equ 00000002h
  ; Shell link saved with LinkInfo
  SLDF_HAS_NAME equ 00000004h
  SLDF_HAS_RELPATH equ 00000008h
  SLDF_HAS_WORKINGDIR equ 00000010h
  SLDF_HAS_ARGS equ 00000020h
  SLDF_HAS_ICONLOCATION equ 00000040h
  SLDF_UNICODE equ 00000080h
  ; the strings are unicode
  SLDF_FORCE_NO_LINKINFO equ 00000100h
  ; disable LINKINFO tracking information (used to track network drives and compute UNC paths if one exists)
  SLDF_HAS_EXP_SZ equ 00000200h
  ; the link contains expandable env strings
  SLDF_RUN_IN_SEPARATE equ 00000400h
  ; Run the 16-bit target exe in a separate VDM/WOW
  if (NTDDI_VERSION lt NTDDI_VISTA)
    SLDF_HAS_LOGO3ID equ 00000800h
    ; not used anymore
  endif
  SLDF_HAS_DARWINID equ 00001000h
  ; MSI (Darwin) link that can be installed on demand
  SLDF_RUNAS_USER equ 00002000h
  ; Run target as a different user
  SLDF_HAS_EXP_ICON_SZ equ 00004000h
  ; contains expandable env string for icon path
  if (NTDDI_VERSION ge NTDDI_WINXP)
    SLDF_NO_PIDL_ALIAS equ 00008000h
    ; disable IDList alias mapping when parsing the IDList from the path
    SLDF_FORCE_UNCNAME equ 00010000h
    ; make GetPath() prefer the UNC name to the local name
    SLDF_RUN_WITH_SHIMLAYER equ 00020000h
    ; activate target of this link with shim layer active
    if (NTDDI_VERSION ge NTDDI_VISTA)
      SLDF_FORCE_NO_LINKTRACK equ 00040000h
      ; disable ObjectID tracking information
      SLDF_ENABLE_TARGET_METADATA equ 00080000h
      ; enable caching of target metadata into link
      SLDF_DISABLE_LINK_PATH_TRACKING equ 00100000h
      ; disable EXP_SZ_LINK_SIG tracking
      SLDF_DISABLE_KNOWNFOLDER_RELATIVE_TRACKING equ 00200000h
      ; disable KnownFolder tracking information (EXP_KNOWN_FOLDER)
      if (NTDDI_VERSION ge NTDDI_WIN7)
        SLDF_NO_KF_ALIAS equ 00400000h
        ; disable Known Folder alias mapping when loading the IDList during deserialization
        SLDF_ALLOW_LINK_TO_LINK equ 00800000h
        ; allows this link to point to another shell link - must only be used when it is not possible to create cycles
        SLDF_UNALIAS_ON_SAVE equ 01000000h
        ; unalias the IDList when saving
        SLDF_PREFER_ENVIRONMENT_PATH equ 02000000h
        ; the IDList is not persisted, instead it is recalculated from the path with environmental variables at load time
        ; we don't hit the disk to recalculate the IDList (the result is a simple IDList).  also Resolve does nothing
        ; if SetPath is called and the path does not have environmental variable in it, SLDF_PREFER_ENVIRONMENT_PATH is removed
        SLDF_KEEP_LOCAL_IDLIST_FOR_UNC_TARGET equ 04000000h
        ; if target is a UNC location on a local machine, keep the local target in addition to the remote one
        if (NTDDI_VERSION ge NTDDI_WIN8)
          SLDF_PERSIST_VOLUME_ID_RELATIVE equ 08000000h
          ; persist target idlist in its volume ID-relative form to avoid dependency on drive letters
          SLDF_VALID equ 0FFFF7FFh
          ; bits that are valid for ::SetFlags()
        else
          SLDF_VALID equ 07FFF7FFh
          ; bits that are valid for ::SetFlags()
        endif
      else
        SLDF_VALID equ 003FF7FFh
        ; bits that are valid for ::SetFlags()
      endif
    endif
    SLDF_RESERVED equ 80000000h
    ; Reserved-- so we can use the low word as an index value in the future
  endif

  DEFINE_ENUM_FLAG_OPERATORS(SHELL_LINK_DATA_FLAGS)
  if  not Defined(__cplusplus) and Defined(_MSC_VER) and (_MSC_VER ge 1200)
    ;* nonstandard extension used : nameless struct/union *
  endif
  DATABLOCK_HEADER struct
    cbSize DWORD ?
    ; Size of this extra data block
    dwSignature DWORD ?
    ; signature of this extra data block
  DATABLOCK_HEADER ends
  tagDATABLOCKHEADER typedef DATABLOCK_HEADER
  LPDATABLOCK_HEADER typedef ptr DATABLOCK_HEADER
  LPDBLIST typedef ptr DATABLOCK_HEADER
  ifdef LF_FACESIZE
    NT_CONSOLE_PROPS struct
      ifdef __cplusplus
        ;[...]
      else
        DUMMYSTRUCTNAME DATABLOCK_HEADER <>
      endif
      wFillAttribute WORD ?
      ; fill attribute for console
      wPopupFillAttribute WORD ?
      ; fill attribute for console popups
      dwScreenBufferSize COORD <>
      ; screen buffer size for console
      dwWindowSize COORD <>
      ; window size for console
      dwWindowOrigin COORD <>
      ; window origin for console
      nFont DWORD ?
      nInputBufferSize DWORD ?
      dwFontSize COORD <>
      uFontFamily DWORD ?
      uFontWeight DWORD ?
      FaceName WORD LF_FACESIZE dup (?)
      uCursorSize DWORD ?
      bFullScreen DWORD ?
      bQuickEdit DWORD ?
      bInsertMode DWORD ?
      bAutoPosition DWORD ?
      uHistoryBufferSize DWORD ?
      uNumberOfHistoryBuffers DWORD ?
      bHistoryNoDup DWORD ?
      ColorTable COLORREF 16 dup (?)
    NT_CONSOLE_PROPS ends
    LPNT_CONSOLE_PROPS typedef ptr NT_CONSOLE_PROPS
    NT_CONSOLE_PROPS_SIG equ 0A0000002h
  endif
  ; LF_FACESIZE
  ; This is a FE Console property
  NT_FE_CONSOLE_PROPS struct
    ifdef __cplusplus
      ;[...]
    else
      DUMMYSTRUCTNAME DATABLOCK_HEADER <>
    endif
    uCodePage DWORD ?
  NT_FE_CONSOLE_PROPS ends
  LPNT_FE_CONSOLE_PROPS typedef ptr NT_FE_CONSOLE_PROPS
  NT_FE_CONSOLE_PROPS_SIG equ 0A0000004h
  EXP_DARWIN_LINK struct
    ifdef __cplusplus
      ;[...]
    else
      DUMMYSTRUCTNAME DATABLOCK_HEADER <>
    endif
    szDarwinID SBYTE MAX_PATH dup (?)
    ; ANSI darwin ID associated with link
    szwDarwinID WORD MAX_PATH dup (?)
    ; UNICODE darwin ID associated with link
  EXP_DARWIN_LINK ends
  LPEXP_DARWIN_LINK typedef ptr EXP_DARWIN_LINK
  EXP_DARWIN_ID_SIG equ 0A0000006h
  if  not Defined(__cplusplus) and Defined(_MSC_VER) and (_MSC_VER ge 1200)
  endif
  EXP_SPECIAL_FOLDER_SIG equ 0A0000005h; LPEXP_SPECIAL_FOLDER

  EXP_SPECIAL_FOLDER struct
    cbSize DWORD ?
    ; Size of this extra data block
    dwSignature DWORD ?
    ; signature of this extra data block
    idSpecialFolder DWORD ?
    ; special folder id this link points into
    cbOffset DWORD ?
    ; ofset into pidl from SLDF_HAS_ID_LIST for child
  EXP_SPECIAL_FOLDER ends
  LPEXP_SPECIAL_FOLDER typedef ptr EXP_SPECIAL_FOLDER
  EXP_SZ_LINK struct
    cbSize DWORD ?
    ; Size of this extra data block
    dwSignature DWORD ?
    ; signature of this extra data block
    szTarget SBYTE MAX_PATH dup (?)
    ; ANSI target name w/EXP_SZ in it
    swzTarget WORD MAX_PATH dup (?)
    ; UNICODE target name w/EXP_SZ in it
  EXP_SZ_LINK ends
  LPEXP_SZ_LINK typedef ptr EXP_SZ_LINK
  EXP_SZ_LINK_SIG equ 0A0000001h; LPEXP_SZ_LINK (target)

  EXP_SZ_ICON_SIG equ 0A0000007h; LPEXP_SZ_LINK (icon)

  if (NTDDI_VERSION ge NTDDI_VISTA)
    EXP_PROPERTYSTORAGE struct
      cbSize DWORD ?
      ; Size of this extra data block
      dwSignature DWORD ?
      ; signature of this extra data block
      abPropertyStorage BYTE 1 dup (?)
    EXP_PROPERTYSTORAGE ends
    EXP_PROPERTYSTORAGE_SIG equ 0A0000009h
  endif
  ; NTDDI_VISTA
  ;* for LPSHELLEXECUTEINFO *
  ifdef _INC_SHELLAPI
    ;===========================================================================
    ; IShellExecuteHook Interface
    ;===========================================================================
    INTERFACE equ <IShellExecuteHookA>
    ??Interface equ <>
    DECLARE_INTERFACE_IID_(IShellExecuteHookA, IUnknown, "000214f5-0000-0000-c000-000000000046")
      STDMETHOD Execute, :LPSHELLEXECUTEINFOA
    DECLARE_INTERFACE_IID__END

    INTERFACE equ <IShellExecuteHookW>
    ??Interface equ <>
    DECLARE_INTERFACE_IID_(IShellExecuteHookW, IUnknown, "000214fb-0000-0000-c000-000000000046")
      STDMETHOD Execute, :LPSHELLEXECUTEINFOW
    DECLARE_INTERFACE_IID__END

    ifdef UNICODE
      IShellExecuteHook equ <IShellExecuteHookW>
      IShellExecuteHookVtbl equ <IShellExecuteHookWVtbl>
    else
      IShellExecuteHook equ <IShellExecuteHookA>
      IShellExecuteHookVtbl equ <IShellExecuteHookAVtbl>
    endif
    ; UNICODE
  endif
  ; _INC_SHELLAPI
  ;===========================================================================
  ; IURLSearchHook Interface
  ;===========================================================================
  INTERFACE equ <IURLSearchHook>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(IURLSearchHook, IUnknown, "ac60f6a0-0fd9-11d0-99cb-00c04fd64497")
    STDMETHOD Translate, :POINTER, :DWORD
  DECLARE_INTERFACE_IID__END

  INTERFACE equ <ISearchContext>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(ISearchContext, IUnknown, "09F656A2-41AF-480C-88F7-16CC0D164615")
    STDMETHOD GetSearchUrl, :ptr BSTR
    STDMETHOD GetSearchText, :ptr BSTR
    STDMETHOD GetSearchStyle, :ptr DWORD
  DECLARE_INTERFACE_IID__END

  INTERFACE equ <IURLSearchHook2>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(IURLSearchHook2, IURLSearchHook, "5ee44da4-6d32-46e3-86bc-07540dedd0e0")
    STDMETHOD TranslateWithSearchContext, :POINTER, :DWORD, :ptr ISearchContext
  DECLARE_INTERFACE_IID__END

  ;--------------------------------------------------------------------------
  ; Command/menuitem IDs
  ;  The explorer dispatches WM_COMMAND messages based on the range of
  ; command/menuitem IDs. All the IDs of menuitems that the view (right
  ; pane) inserts must be in FCIDM_SHVIEWFIRST/LAST (otherwise, the explorer
  ; won't dispatch them). The view should not deal with any menuitems
  ; in FCIDM_BROWSERFIRST/LAST (otherwise, it won't work with the future
  ; version of the shell).
  ;  FCIDM_SHVIEWFIRST/LAST      for the right pane (IShellView)
  ;  FCIDM_BROWSERFIRST/LAST     for the explorer frame (IShellBrowser)
  ;  FCIDM_GLOBAL/LAST           for the explorer's submenu IDs
  ;--------------------------------------------------------------------------
  FCIDM_SHVIEWFIRST equ 0000h
  FCIDM_SHVIEWLAST equ 7fffh
  FCIDM_BROWSERFIRST equ 0a000h
  FCIDM_BROWSERLAST equ 0bf00h
  FCIDM_GLOBALFIRST equ 8000h
  FCIDM_GLOBALLAST equ 9fffh
  ; Global submenu IDs and separator IDs
  FCIDM_MENU_FILE equ (FCIDM_GLOBALFIRST + 0000h)
  FCIDM_MENU_EDIT equ (FCIDM_GLOBALFIRST + 0040h)
  FCIDM_MENU_VIEW equ (FCIDM_GLOBALFIRST + 0080h)
  FCIDM_MENU_VIEW_SEP_OPTIONS equ (FCIDM_GLOBALFIRST + 0081h)
  FCIDM_MENU_TOOLS equ (FCIDM_GLOBALFIRST + 00c0h); for Win9x compat

  FCIDM_MENU_TOOLS_SEP_GOTO equ (FCIDM_GLOBALFIRST + 00c1h); for Win9x compat

  FCIDM_MENU_HELP equ (FCIDM_GLOBALFIRST + 0100h)
  FCIDM_MENU_FIND equ (FCIDM_GLOBALFIRST + 0140h)
  FCIDM_MENU_EXPLORE equ (FCIDM_GLOBALFIRST + 0150h)
  FCIDM_MENU_FAVORITES equ (FCIDM_GLOBALFIRST + 0170h)
  @DefProto DllImport, ILClone, WIN_STD_CALL_CONV,, <:PCUIDLIST_RELATIVE>, 4
  @DefProto DllImport, ILCloneFirst, WIN_STD_CALL_CONV,, <:PCUIDLIST_RELATIVE>, 4
  @DefProto DllImport, ILCombine, WIN_STD_CALL_CONV,, <:PCIDLIST_ABSOLUTE, :PCUIDLIST_RELATIVE>, 8
  @DefProto DllImport, ILFree, WIN_STD_CALL_CONV,, <:PIDLIST_RELATIVE>, 4
  @DefProto DllImport, ILGetNext, WIN_STD_CALL_CONV,, <:PCUIDLIST_RELATIVE>, 4
  @DefProto DllImport, ILGetSize, WIN_STD_CALL_CONV,, <:PCUIDLIST_RELATIVE>, 4
  @DefProto DllImport, ILFindChild, WIN_STD_CALL_CONV,, <:PIDLIST_ABSOLUTE, :PCIDLIST_ABSOLUTE>, 8
  @DefProto DllImport, ILFindLastID, WIN_STD_CALL_CONV,, <:PCUIDLIST_RELATIVE>, 4
  @DefProto DllImport, ILRemoveLastID, WIN_STD_CALL_CONV,, <:PUIDLIST_RELATIVE>, 4
  @DefProto DllImport, ILIsEqual, WIN_STD_CALL_CONV,, <:PCIDLIST_ABSOLUTE, :PCIDLIST_ABSOLUTE>, 8
  @DefProto DllImport, ILIsParent, WIN_STD_CALL_CONV,, <:PCIDLIST_ABSOLUTE, :PCIDLIST_ABSOLUTE, :BOOL>, 12
  @DefProto DllImport, ILSaveToStream, WIN_STD_CALL_CONV,, <:ptr IStream, :PCUIDLIST_RELATIVE>, 8
  ILLoadFromStream proto WIN_STD_CALL_CONV :ptr IStream, :ptr PIDLIST_RELATIVE
  ; use ILLoadFromStreamEx instead
  if (NTDDI_VERSION ge NTDDI_VISTA)
    @DefProto DllImport, ILLoadFromStreamEx, WIN_STD_CALL_CONV,, <:ptr IStream, :ptr PIDLIST_RELATIVE>, 8
  endif
  ; NTDDI_VISTA
  @DefProto DllImport, ILCreateFromPathA, WIN_STD_CALL_CONV,, <:PCSTR>, 4
  @DefProto DllImport, ILCreateFromPathW, WIN_STD_CALL_CONV,, <:PCWSTR>, 4
  ifdef NO_WRAPPERS_FOR_ILCREATEFROMPATH
    @DefProto DllImport, ILCreateFromPath, WIN_STD_CALL_CONV,, <:PCTSTR>, 4
  else
    ifdef UNICODE
      ILCreateFromPath equ <ILCreateFromPathW>
    else
      ILCreateFromPath equ <ILCreateFromPathA>
    endif
    ; !UNICODE
  endif
  ; NO_WRAPPERS_FOR_ILCREATEFROMPATH
  @DefProto DllImport, SHILCreateFromPath, WIN_STD_CALL_CONV,, <:PCWSTR, :ptr PIDLIST_ABSOLUTE, :ptr DWORD>, 12
  VOID_OFFSET macro pv, cb
    exitm <((((pv)) + (cb)))>
  endm
  if Defined(STRICT_TYPED_ITEMIDS) and Defined(__cplusplus)
    ;[...]
    ; NTDDI_VISTA
    ; defined(STRICT_TYPED_ITEMIDS) && defined(__cplusplus)
  else
  ; !defined(STRICT_TYPED_ITEMIDS) || !defined(__cplusplus)
    ILCloneFull equ <ILClone>
    ILCloneChild equ <ILCloneFirst>
    ILSkip macro pidl, cb
      exitm <((PUIDLIST_RELATIVE) VOID_OFFSET((pidl), (cb)))>
    endm
    ILNext macro pidl
      exitm <ILSkip(pidl, (pidl) - mkid.cb)>
    endm
    ILIsAligned macro pidl
      exitm <(((pidl) and (sizeof(void *) - 1)) == 0)>
    endm
    ILIsEmpty macro pidl
      exitm <((pidl) == NULL or (pidl) - mkid.cb == 0)>
    endm
    ; ILIsChild does not guarantee that pidl is non-null or non-empty.
    ILIsChild macro pidl
      exitm <(ILIsEmpty(pidl) or ILIsEmpty(ILNext(pidl)))>
    endm
  endif
  ; defined(STRICT_TYPED_ITEMIDS) && defined(__cplusplus)
  @DefProto DllImport, ILAppendID, WIN_STD_CALL_CONV,, <:PIDLIST_RELATIVE, :LPCSHITEMID, :BOOL>, 12
  if (NTDDI_VERSION ge NTDDI_VISTA)
    ; SHGetPathFromIDListEx returns a win32 file system path for the item in the name space.
    ;  and has a few special cases that include returning UNC printer names too!
    GPFIDL_DEFAULT equ 0000h
    ; normal Win32 file name, servers and drive roots included
    GPFIDL_ALTNAME equ 0001h
    ; short file name
    GPFIDL_UNCPRINTER equ 0002h
    ; include UNC printer names too (non file system item)

    GPFIDL_FLAGS typedef SDWORD
    @DefProto DllImport, SHGetPathFromIDListEx, WIN_STD_CALL_CONV,, <:PCIDLIST_ABSOLUTE, :PWSTR, :DWORD, :GPFIDL_FLAGS>, 16
  endif
  ; NTDDI_VISTA
  ; SHGetPathFromIDListW is the old version of SHGetPathFromIDListEx that assumes the size of the buffer (MAX_PATH).
  ; The pidl should point to a file system object.
  @DefProto DllImport, SHGetPathFromIDListA, WIN_STD_CALL_CONV,, <:PCIDLIST_ABSOLUTE, :LPSTR>, 8
  ; SHGetPathFromIDListW is the old version of SHGetPathFromIDListEx that assumes the size of the buffer (MAX_PATH).
  ; The pidl should point to a file system object.
  @DefProto DllImport, SHGetPathFromIDListW, WIN_STD_CALL_CONV,, <:PCIDLIST_ABSOLUTE, :LPWSTR>, 8
  ifdef UNICODE
    SHGetPathFromIDList equ <SHGetPathFromIDListW>
  else
    SHGetPathFromIDList equ <SHGetPathFromIDListA>
  endif
  ; !UNICODE
  @DefProto DllImport, SHCreateDirectory, WIN_STD_CALL_CONV,, <:HWND, :PCWSTR>, 8
  @DefProto DllImport, SHCreateDirectoryExA, WIN_STD_CALL_CONV,, <:HWND, :LPCSTR, :ptr SECURITY_ATTRIBUTES>, 12
  @DefProto DllImport, SHCreateDirectoryExW, WIN_STD_CALL_CONV,, <:HWND, :LPCWSTR, :ptr SECURITY_ATTRIBUTES>, 12
  ifdef UNICODE
    SHCreateDirectoryEx equ <SHCreateDirectoryExW>
  else
    SHCreateDirectoryEx equ <SHCreateDirectoryExA>
  endif
  ; !UNICODE
  if (NTDDI_VERSION ge NTDDI_VISTA)
    OFASI_EDIT equ 0001h
    OFASI_OPENDESKTOP equ 0002h
  endif
  if (NTDDI_VERSION ge NTDDI_WINXP)
    @DefProto DllImport, SHOpenFolderAndSelectItems, WIN_STD_CALL_CONV,, <:PCIDLIST_ABSOLUTE, :UINT, :PCUITEMID_CHILD_ARRAY, :DWORD>, 16
    ;  deprecated because of parameter ambiguity
    ;  call SHCreateItemWithParent() or SHCreateItemFromIDList() instead
    @DefProto DllImport, SHCreateShellItem, WIN_STD_CALL_CONV,, <:PCIDLIST_ABSOLUTE, :ptr IShellFolder, :PCUITEMID_CHILD, :ptr ptr IShellItem>, 16
  endif
  ; SHGetSpecialFolderLocation
  ;  Caller should use SHGetMalloc to obtain an allocator that can free the pidl
  ; registry entries for special paths are kept in :
  REGSTR_PATH_SPECIAL_FOLDERS equ <REGSTR_PATH_EXPLORER TEXT("\Shell Folders")>
  CSIDL_DESKTOP equ 0000h; <desktop>

  CSIDL_INTERNET equ 0001h; Internet Explorer (icon on desktop)

  CSIDL_PROGRAMS equ 0002h; Start Menu\Programs

  CSIDL_CONTROLS equ 0003h; My Computer\Control Panel

  CSIDL_PRINTERS equ 0004h; My Computer\Printers

  CSIDL_PERSONAL equ 0005h; My Documents

  CSIDL_FAVORITES equ 0006h; <user name>\Favorites

  CSIDL_STARTUP equ 0007h; Start Menu\Programs\Startup

  CSIDL_RECENT equ 0008h; <user name>\Recent

  CSIDL_SENDTO equ 0009h; <user name>\SendTo

  CSIDL_BITBUCKET equ 000ah; <desktop>\Recycle Bin

  CSIDL_STARTMENU equ 000bh; <user name>\Start Menu

  CSIDL_MYDOCUMENTS equ <CSIDL_PERSONAL>;  Personal was just a silly name for My Documents

  CSIDL_MYMUSIC equ 000dh; "My Music" folder

  CSIDL_MYVIDEO equ 000eh; "My Videos" folder

  CSIDL_DESKTOPDIRECTORY equ 0010h; <user name>\Desktop

  CSIDL_DRIVES equ 0011h; My Computer

  CSIDL_NETWORK equ 0012h; Network Neighborhood (My Network Places)

  CSIDL_NETHOOD equ 0013h; <user name>\nethood

  CSIDL_FONTS equ 0014h; windows\fonts

  CSIDL_TEMPLATES equ 0015h
  CSIDL_COMMON_STARTMENU equ 0016h; All Users\Start Menu

  CSIDL_COMMON_PROGRAMS equ 0017h; All Users\Start Menu\Programs

  CSIDL_COMMON_STARTUP equ 0018h; All Users\Startup

  CSIDL_COMMON_DESKTOPDIRECTORY equ 0019h; All Users\Desktop

  CSIDL_APPDATA equ 001ah; <user name>\Application Data

  CSIDL_PRINTHOOD equ 001bh; <user name>\PrintHood

  ifndef CSIDL_LOCAL_APPDATA
    CSIDL_LOCAL_APPDATA equ 001ch; <user name>\Local Settings\Applicaiton Data (non roaming)

  endif
  ; CSIDL_LOCAL_APPDATA
  CSIDL_ALTSTARTUP equ 001dh; non localized startup

  CSIDL_COMMON_ALTSTARTUP equ 001eh; non localized common startup

  CSIDL_COMMON_FAVORITES equ 001fh
  ifndef _SHFOLDER_H_
    CSIDL_INTERNET_CACHE equ 0020h
    CSIDL_COOKIES equ 0021h
    CSIDL_HISTORY equ 0022h
    CSIDL_COMMON_APPDATA equ 0023h; All Users\Application Data

    CSIDL_WINDOWS equ 0024h; GetWindowsDirectory()

    CSIDL_SYSTEM equ 0025h; GetSystemDirectory()

    CSIDL_PROGRAM_FILES equ 0026h; C:\Program Files

    CSIDL_MYPICTURES equ 0027h; C:\Program Files\My Pictures

  endif
  ; _SHFOLDER_H_
  CSIDL_PROFILE equ 0028h; USERPROFILE

  CSIDL_SYSTEMX86 equ 0029h; x86 system directory on RISC

  CSIDL_PROGRAM_FILESX86 equ 002ah; x86 C:\Program Files on RISC

  ifndef _SHFOLDER_H_
    CSIDL_PROGRAM_FILES_COMMON equ 002bh; C:\Program Files\Common

  endif
  ; _SHFOLDER_H_
  CSIDL_PROGRAM_FILES_COMMONX86 equ 002ch; x86 Program Files\Common on RISC

  CSIDL_COMMON_TEMPLATES equ 002dh; All Users\Templates

  ifndef _SHFOLDER_H_
    CSIDL_COMMON_DOCUMENTS equ 002eh; All Users\Documents

    CSIDL_COMMON_ADMINTOOLS equ 002fh; All Users\Start Menu\Programs\Administrative Tools

    CSIDL_ADMINTOOLS equ 0030h; <user name>\Start Menu\Programs\Administrative Tools

  endif
  ; _SHFOLDER_H_
  CSIDL_CONNECTIONS equ 0031h; Network and Dial-up Connections

  CSIDL_COMMON_MUSIC equ 0035h; All Users\My Music

  CSIDL_COMMON_PICTURES equ 0036h; All Users\My Pictures

  CSIDL_COMMON_VIDEO equ 0037h; All Users\My Video

  CSIDL_RESOURCES equ 0038h; Resource Direcotry

  ifndef _SHFOLDER_H_
    CSIDL_RESOURCES_LOCALIZED equ 0039h; Localized Resource Direcotry

  endif
  ; _SHFOLDER_H_
  CSIDL_COMMON_OEM_LINKS equ 003ah; Links to All Users OEM specific apps

  CSIDL_CDBURN_AREA equ 003bh; USERPROFILE\Local Settings\Application Data\Microsoft\CD Burning

  ; unused                               0x003c
  CSIDL_COMPUTERSNEARME equ 003dh; Computers Near Me (computered from Workgroup membership)

  ifndef _SHFOLDER_H_
    CSIDL_FLAG_CREATE equ 8000h; combine with CSIDL_ value to force folder creation in SHGetFolderPath()

  endif
  ; _SHFOLDER_H_
  CSIDL_FLAG_DONT_VERIFY equ 4000h; combine with CSIDL_ value to return an unverified folder path

  CSIDL_FLAG_DONT_UNEXPAND equ 2000h; combine with CSIDL_ value to avoid unexpanding environment variables

  if (NTDDI_VERSION ge NTDDI_WINXP)
    CSIDL_FLAG_NO_ALIAS equ 1000h; combine with CSIDL_ value to insure non-alias versions of the pidl

    CSIDL_FLAG_PER_USER_INIT equ 0800h; combine with CSIDL_ value to indicate per-user init (eg. upgrade)

  endif
  ; NTDDI_WINXP
  CSIDL_FLAG_MASK equ 0FF00h; mask for all possible flag values

  @DefProto DllImport, SHGetSpecialFolderLocation, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :ptr PIDLIST_ABSOLUTE>, 12
  @DefProto DllImport, SHCloneSpecialIDList, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :BOOL>, 12
  @DefProto DllImport, SHGetSpecialFolderPathA, WIN_STD_CALL_CONV,, <:HWND, :LPSTR, :SDWORD, :BOOL>, 16
  @DefProto DllImport, SHGetSpecialFolderPathW, WIN_STD_CALL_CONV,, <:HWND, :LPWSTR, :SDWORD, :BOOL>, 16
  ifdef UNICODE
    SHGetSpecialFolderPath equ <SHGetSpecialFolderPathW>
  else
    SHGetSpecialFolderPath equ <SHGetSpecialFolderPathA>
  endif
  ; !UNICODE
  if (NTDDI_VERSION ge NTDDI_WIN2K)
    @DefProto DllImport, SHFlushSFCache, WIN_STD_CALL_CONV,, <>, 0
    SHGFP_TYPE typedef SDWORD
    SHGFP_TYPE_CURRENT equ 0
    ; current value for user, verify it exists
    SHGFP_TYPE_DEFAULT equ 1
    ; default value, may not exist

    @DefProto DllImport, SHGetFolderPathA, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :HANDLE, :DWORD, :LPSTR>, 20
    @DefProto DllImport, SHGetFolderPathW, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :HANDLE, :DWORD, :LPWSTR>, 20
    ifdef UNICODE
      SHGetFolderPath equ <SHGetFolderPathW>
    else
      SHGetFolderPath equ <SHGetFolderPathA>
    endif
    ; !UNICODE
    @DefProto DllImport, SHGetFolderLocation, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :HANDLE, :DWORD, :ptr PIDLIST_ABSOLUTE>, 20
  endif
  ; NTDDI_WIN2K
  if (NTDDI_VERSION ge NTDDI_WINXP)
    @DefProto DllImport, SHSetFolderPathA, WIN_STD_CALL_CONV,, <:SDWORD, :HANDLE, :DWORD, :LPCSTR>, 16
    @DefProto DllImport, SHSetFolderPathW, WIN_STD_CALL_CONV,, <:SDWORD, :HANDLE, :DWORD, :LPCWSTR>, 16
    ifdef UNICODE
      SHSetFolderPath equ <SHSetFolderPathW>
    else
      SHSetFolderPath equ <SHSetFolderPathA>
    endif
    ; !UNICODE
    @DefProto DllImport, SHGetFolderPathAndSubDirA, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :HANDLE, :DWORD, :LPCSTR, :LPSTR>, 24
    @DefProto DllImport, SHGetFolderPathAndSubDirW, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :HANDLE, :DWORD, :LPCWSTR, :LPWSTR>, 24
    ifdef UNICODE
      SHGetFolderPathAndSubDir equ <SHGetFolderPathAndSubDirW>
    else
      SHGetFolderPathAndSubDir equ <SHGetFolderPathAndSubDirA>
    endif
    ; !UNICODE
  endif
  ; NTDDI_VISTA
  if (NTDDI_VERSION ge NTDDI_VISTA)
    ; flags for Known Folder APIs
    ;NTDDI_WIN10_RS3
    ;NTDDI_WIN10_RS2
    ;NTDDI_WIN7
    KNOWN_FOLDER_FLAG typedef SDWORD
    KF_FLAG_DEFAULT equ 00000000h
    if (NTDDI_VERSION ge NTDDI_WIN10_RS3)
      ; When called from packaged app, LocalAppData/RoamingAppData folders are redirected to
      ; app private locations that match the paths returned from WinRT API:
      ;   Windows.Storage.ApplicationData.Current.{LocalFolder|RoamingFolder}
      ; A few other folders are redirected to subdirectories of LocalAppData.
      KF_FLAG_FORCE_APP_DATA_REDIRECTION equ 00080000h
    endif
    ;NTDDI_WIN10_RS3
    if (NTDDI_VERSION ge NTDDI_WIN10_RS2)
      ; When running in a Centennial process, some file system locations are redirected to 
      ; package-specific locations by the file system. Specifying this flag will cause the
      ; target of the redirection to be returned for these locations. This is useful in
      ; cases where the real location in the file system needs to be known.
      KF_FLAG_RETURN_FILTER_REDIRECTION_TARGET equ 00040000h
      ; New form for KF_FLAG_FORCE_APPCONTAINER_REDIRECTION and KF_FLAG_NO_APPCONTAINER_REDIRECTION
      ; The new forms should be used and will exhibit the same behavior as the old flags.
      ; When running inside an AppContainer process, or when providing an AppContainer token,
      ; some folders are redirected to AppContainer-specific locations within the package's location.
      ; Specifying this flag will force this redirection for folders that are not normally 
      ; redirected for centennial processes. Useful for sharing files between between UWA and 
      ; Centennial apps that are within the same package.
      KF_FLAG_FORCE_PACKAGE_REDIRECTION equ 00020000h
      ; When running inside a packaged process (Centennial,  AppContainer, etc.), or when providing 
      ; a packaged process token, some folders are redirected to package-specific locations.
      ; Specifying this flag will disable redirection on locations where it applied,
      ; and instead return the non-redirected location.
      KF_FLAG_NO_PACKAGE_REDIRECTION equ 00010000h
      ; see comment for KF_FLAG_FORCE_PACKAGE_REDIRECTION
      KF_FLAG_FORCE_APPCONTAINER_REDIRECTION equ 00020000h
    endif
    ;NTDDI_WIN10_RS2
    if (NTDDI_VERSION ge NTDDI_WIN7)
      ; When running inside an AppContainer, or when poviding an AppContainer token, specifying this flag will prevent redirection to AppContainer
      ; folders and instead return the path that would be returned when not running inside an AppContainer
      KF_FLAG_NO_APPCONTAINER_REDIRECTION equ 00010000h
    endif
    ;NTDDI_WIN7
    ; Make sure that the folder already exists or create it and apply security specified in folder definition
    ; If folder can not be created then function will return failure and no folder path (IDList) will be returned
    ; If folder is located on the network the function may take long time to execute
    KF_FLAG_CREATE equ 00008000h
    ; If this flag is specified then the folder path is returned and no verification is performed
    ; Use this flag is you want to get folder's path (IDList) and do not need to verify folder's existence
    ; If this flag is NOT specified then Known Folder API will try to verify that the folder exists
    ;     If folder does not exist or can not be accessed then function will return failure and no folder path (IDList) will be returned
    ;     If folder is located on the network the function may take long time to execute
    KF_FLAG_DONT_VERIFY equ 00004000h
    ; Set folder path as is and do not try to substitute parts of the path with environments variables.
    ; If flag is not specified then Known Folder will try to replace parts of the path with some
    ; known environment variables (%USERPROFILE%, %APPDATA% etc.)
    KF_FLAG_DONT_UNEXPAND equ 00002000h
    ; Get file system based IDList if available. If the flag is not specified the Known Folder API
    ; will try to return aliased IDList by default. Example for FOLDERID_Documents -
    ; Aliased - [desktop]\[user]\[Documents] - exact location is determined by shell namespace layout and might change
    ; Non aliased - [desktop]\[computer]\[disk_c]\[users]\[user]\[Documents] - location is determined by folder location in the file system
    KF_FLAG_NO_ALIAS equ 00001000h
    ; Initialize the folder with desktop.ini settings
    ; If folder can not be initialized then function will return failure and no folder path will be returned
    ; If folder is located on the network the function may take long time to execute
    KF_FLAG_INIT equ 00000800h
    ; Get the default path, will also verify folder existence unless KF_FLAG_DONT_VERIFY is also specified
    KF_FLAG_DEFAULT_PATH equ 00000400h
    ; Get the not-parent-relative default path. Only valid with KF_FLAG_DEFAULT_PATH
    KF_FLAG_NOT_PARENT_RELATIVE equ 00000200h
    ; Build simple IDList
    KF_FLAG_SIMPLE_IDLIST equ 00000100h
    ; only return the aliased IDLists, don't fallback to file system path
    KF_FLAG_ALIAS_ONLY equ 80000000h

    DEFINE_ENUM_FLAG_OPERATORS(KNOWN_FOLDER_FLAG)
    @DefProto DllImport, SHGetKnownFolderIDList, WIN_STD_CALL_CONV,, <:REFKNOWNFOLDERID, :DWORD, :HANDLE, :ptr PIDLIST_ABSOLUTE>, 16
    ;* KNOWN_FOLDER_FLAG *
    @DefProto DllImport, SHSetKnownFolderPath, WIN_STD_CALL_CONV,, <:REFKNOWNFOLDERID, :DWORD, :HANDLE, :PCWSTR>, 16
    ;* KNOWN_FOLDER_FLAG *
    @DefProto DllImport, SHGetKnownFolderPath, WIN_STD_CALL_CONV,, <:REFKNOWNFOLDERID, :DWORD, :HANDLE, :ptr PWSTR>, 16
    ;* KNOWN_FOLDER_FLAG *
    ; free *ppszPath with CoTaskMemFree
  endif
  ; NTDDI_VISTA
  if (NTDDI_VERSION ge NTDDI_WIN7)
    ; returns IShellItem or related interface
    @DefProto DllImport, SHGetKnownFolderItem, WIN_STD_CALL_CONV,, <:REFKNOWNFOLDERID, :KNOWN_FOLDER_FLAG, :HANDLE, :REFIID, :ptr ptr>, 20
  endif
  ; NTDDI_WIN7
  if (NTDDI_VERSION ge NTDDI_WIN2K)
    FCS_READ equ 00000001h
    FCS_FORCEWRITE equ 00000002h
    FCS_WRITE equ <(FCS_READ or FCS_FORCEWRITE)>
    FCS_FLAG_DRAGDROP equ 2
    ; Mask which values have been retreived or being set.
    FCSM_VIEWID equ 00000001h; deprecated

    FCSM_WEBVIEWTEMPLATE equ 00000002h; deprecated

    FCSM_INFOTIP equ 00000004h
    FCSM_CLSID equ 00000008h
    FCSM_ICONFILE equ 00000010h
    FCSM_LOGO equ 00000020h
    FCSM_FLAGS equ 00000040h
    if (NTDDI_VERSION ge NTDDI_VISTA)
      include pshpack8.inc
      ; Used by SHGetSetFolderCustomSettings
      SHFOLDERCUSTOMSETTINGS struct
        dwSize DWORD ?
        dwMask DWORD ?
        ; IN/OUT  Which Attributes to Get/Set
        pvid POINTER ?
        ; OUT - if dwReadWrite is FCS_READ, IN - otherwise
        ; The folder's WebView template path
        pszWebViewTemplate POINTER ?
        ; OUT - if dwReadWrite is FCS_READ, IN - otherwise
        cchWebViewTemplate DWORD ?
        ; IN - Specifies the size of the buffer pointed to by pszWebViewTemplate
        ; Ignored if dwReadWrite is FCS_READ
        pszWebViewTemplateVersion POINTER ?
        ; currently IN only
        ; Infotip for the folder
        pszInfoTip POINTER ?
        ; OUT - if dwReadWrite is FCS_READ, IN - otherwise
        cchInfoTip DWORD ?
        ; IN - Specifies the size of the buffer pointed to by pszInfoTip
        ; Ignored if dwReadWrite is FCS_READ
        ; CLSID that points to more info in the registry
        pclsid POINTER ?
        ; OUT - if dwReadWrite is FCS_READ, IN - otherwise
        ; Other flags for the folder. Takes FCS_FLAG_* values
        dwFlags DWORD ?
        ; OUT - if dwReadWrite is FCS_READ, IN - otherwise
        pszIconFile POINTER ?
        ; OUT - if dwReadWrite is FCS_READ, IN - otherwise
        cchIconFile DWORD ?
        ; IN - Specifies the size of the buffer pointed to by pszIconFile
        ; Ignored if dwReadWrite is FCS_READ
        iIconIndex SDWORD ?
        ; OUT - if dwReadWrite is FCS_READ, IN - otherwise
        pszLogo POINTER ?
        ; OUT - if dwReadWrite is FCS_READ, IN - otherwise
        cchLogo DWORD ?
        ; IN - Specifies the size of the buffer pointed to by pszIconFile
        ; Ignored if dwReadWrite is FCS_READ
      SHFOLDERCUSTOMSETTINGS ends
      LPSHFOLDERCUSTOMSETTINGS typedef ptr SHFOLDERCUSTOMSETTINGS
      ;* Return to byte packing *
      include poppack.inc
      ; Gets/Sets the Folder Custom Settings for pszPath based on dwReadWrite. dwReadWrite can be FCS_READ/FCS_WRITE/FCS_FORCEWRITE
      @DefProto DllImport, SHGetSetFolderCustomSettings, WIN_STD_CALL_CONV,, <:LPSHFOLDERCUSTOMSETTINGS, :PCWSTR, :DWORD>, 12
    endif
    ;NTDDI_VISTA
  endif
  ; NTDDI_WIN2K
  ;-------------------------------------------------------------------------
  ; SHBrowseForFolder API
  ;-------------------------------------------------------------------------
  TYPE_BFFCALLBACK typedef proto WIN_STD_CALL_CONV :HWND, :UINT, :LPARAM, :LPARAM
  BFFCALLBACK typedef ptr TYPE_BFFCALLBACK

  include pshpack8.inc
  BROWSEINFOA struct
    hwndOwner HWND ?
    pidlRoot PCIDLIST_ABSOLUTE ?
    pszDisplayName POINTER ?
    ; Return display name of item selected.
    lpszTitle =POINTER ?
    ; text to go in the banner over the tree.
    ulFlags DWORD ?
    ; Flags that control the return stuff
    lpfn BFFCALLBACK ?
    lParam LPARAM ?
    ; extra info that's passed back in callbacks
    iImage SDWORD ?
    ; output var: where to return the Image index.
  BROWSEINFOA ends
  _browseinfoA typedef BROWSEINFOA
  PBROWSEINFOA typedef ptr BROWSEINFOA
  LPBROWSEINFOA typedef ptr BROWSEINFOA
  BROWSEINFOW struct
    hwndOwner HWND ?
    pidlRoot PCIDLIST_ABSOLUTE ?
    pszDisplayName POINTER ?
    ; Return display name of item selected.
    lpszTitle =POINTER ?
    ; text to go in the banner over the tree.
    ulFlags DWORD ?
    ; Flags that control the return stuff
    lpfn BFFCALLBACK ?
    lParam LPARAM ?
    ; extra info that's passed back in callbacks
    iImage SDWORD ?
    ; output var: where to return the Image index.
  BROWSEINFOW ends
  _browseinfoW typedef BROWSEINFOW
  PBROWSEINFOW typedef ptr BROWSEINFOW
  LPBROWSEINFOW typedef ptr BROWSEINFOW
  ;* Return to byte packing *
  include poppack.inc
  ifdef UNICODE
    BROWSEINFO equ <BROWSEINFOW>
    PBROWSEINFO equ <PBROWSEINFOW>
    LPBROWSEINFO equ <LPBROWSEINFOW>
  else
    BROWSEINFO equ <BROWSEINFOA>
    PBROWSEINFO equ <PBROWSEINFOA>
    LPBROWSEINFO equ <LPBROWSEINFOA>
  endif
  ; Browsing for directory.
  BIF_RETURNONLYFSDIRS equ 00000001h; For finding a folder to start document searching

  BIF_DONTGOBELOWDOMAIN equ 00000002h; For starting the Find Computer

  BIF_STATUSTEXT equ 00000004h; Top of the dialog has 2 lines of text for BROWSEINFO.lpszTitle and one line if

  ; this flag is set.  Passing the message BFFM_SETSTATUSTEXTA to the hwnd can set the
  ; rest of the text.  This is not used with BIF_USENEWUI and BROWSEINFO.lpszTitle gets
  ; all three lines of text.
  BIF_RETURNFSANCESTORS equ 00000008h
  BIF_EDITBOX equ 00000010h; Add an editbox to the dialog

  BIF_VALIDATE equ 00000020h; insist on valid result (or CANCEL)

  BIF_NEWDIALOGSTYLE equ 00000040h; Use the new dialog layout with the ability to resize

  ; Caller needs to call OleInitialize() before using this API
  BIF_USENEWUI equ <(BIF_NEWDIALOGSTYLE or BIF_EDITBOX)>
  BIF_BROWSEINCLUDEURLS equ 00000080h; Allow URLs to be displayed or entered. (Requires BIF_USENEWUI)

  BIF_UAHINT equ 00000100h; Add a UA hint to the dialog, in place of the edit box. May not be combined with BIF_EDITBOX

  BIF_NONEWFOLDERBUTTON equ 00000200h; Do not add the "New Folder" button to the dialog.  Only applicable with BIF_NEWDIALOGSTYLE.

  BIF_NOTRANSLATETARGETS equ 00000400h; don't traverse target as shortcut

  BIF_BROWSEFORCOMPUTER equ 00001000h; Browsing for Computers.

  BIF_BROWSEFORPRINTER equ 00002000h; Browsing for Printers

  BIF_BROWSEINCLUDEFILES equ 00004000h; Browsing for Everything

  BIF_SHAREABLE equ 00008000h; sharable resources displayed (remote shares, requires BIF_USENEWUI)

  BIF_BROWSEFILEJUNCTIONS equ 00010000h; allow folder junctions like zip files and libraries to be browsed

  ; message from browser
  BFFM_INITIALIZED equ 1
  BFFM_SELCHANGED equ 2
  BFFM_VALIDATEFAILEDA equ 3; lParam:szPath ret:1(cont),0(EndDialog)

  BFFM_VALIDATEFAILEDW equ 4; lParam:wzPath ret:1(cont),0(EndDialog)

  BFFM_IUNKNOWN equ 5; provides IUnknown to client. lParam: IUnknown*

  ; messages to browser
  BFFM_SETSTATUSTEXTA equ (WM_USER + 100)
  BFFM_ENABLEOK equ (WM_USER + 101)
  BFFM_SETSELECTIONA equ (WM_USER + 102)
  BFFM_SETSELECTIONW equ (WM_USER + 103)
  BFFM_SETSTATUSTEXTW equ (WM_USER + 104)
  BFFM_SETOKTEXT equ (WM_USER + 105); Unicode only

  BFFM_SETEXPANDED equ (WM_USER + 106); Unicode only

  @DefProto DllImport, SHBrowseForFolderA, WIN_STD_CALL_CONV,, <:LPBROWSEINFOA>, 4
  @DefProto DllImport, SHBrowseForFolderW, WIN_STD_CALL_CONV,, <:LPBROWSEINFOW>, 4
  ifdef UNICODE
    SHBrowseForFolder equ <SHBrowseForFolderW>
    BFFM_SETSTATUSTEXT equ <BFFM_SETSTATUSTEXTW>
    BFFM_SETSELECTION equ <BFFM_SETSELECTIONW>
    BFFM_VALIDATEFAILED equ <BFFM_VALIDATEFAILEDW>
  else
    SHBrowseForFolder equ <SHBrowseForFolderA>
    BFFM_SETSTATUSTEXT equ <BFFM_SETSTATUSTEXTA>
    BFFM_SETSELECTION equ <BFFM_SETSELECTIONA>
    BFFM_VALIDATEFAILED equ <BFFM_VALIDATEFAILEDA>
  endif
  ;-------------------------------------------------------------------------
  ; SHLoadInProc
  ;   This function is no longer implemented. It will return E_NOTIMPL.
  ;-------------------------------------------------------------------------
  @DefProto DllImport, SHLoadInProc, WIN_STD_CALL_CONV,, <:REFCLSID>, 4
  ;-------------------------------------------------------------------------
  ; Internet Shortcut Object
  ;-------------------------------------------------------------------------
  ; Cmds for CGID_ShortCut
  ISHCUTCMDID_DOWNLOADICON equ 0
  ISHCUTCMDID_INTSHORTCUTCREATE equ 1
  if (_WIN32_IE ge _WIN32_IE_IE70)
    ISHCUTCMDID_COMMITHISTORY equ 2
    ISHCUTCMDID_SETUSERAWURL equ 3
  endif

  CMDID_INTSHORTCUTCREATE equ <ISHCUTCMDID_INTSHORTCUTCREATE>
  ; Bindctx key, passed to IShellFolder::ParseDiplayName.  Provides dbfolder with extra
  ; data, besides the name, necessary for the parse. the object in the bind context implements
  ; IPropertyStore and provides a fixed set of properties
  STR_PARSE_WITH_PROPERTIES equ <L("ParseWithProperties")>
  ; Bindctx key, passed to IShellFolder::ParseDisplayName(). used to pass the original item that
  ; is being re-parsed. that item is stored as an IShellItem that supports IParentAndItem,
  ; and should be the un-aliased form of the item.
  STR_PARSE_PARTIAL_IDLIST equ <L("ParseOriginalItem")>
  ; Helper function which returns a IShellFolder interface to the desktop
  ; folder. This is equivalent to call CoCreateInstance with CLSID_ShellDesktop.
  ;  CoCreateInstance(CLSID_Desktop, NULL, CLSCTX_INPROC, IID_PPV_ARGS(&pshf));
  @DefProto DllImport, SHGetDesktopFolder, WIN_STD_CALL_CONV,, <:ptr ptr IShellFolder>, 4
  ; this interface is deprecated, data sources should
  ; implement IShellFolder2::GetDetailsOf()/GetDetailsEx() instead
  INTERFACE equ <IShellDetails>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(IShellDetails, IUnknown, "000214EC-0000-0000-c000-000000000046")
    STDMETHOD GetDetailsOf, :PCUITEMID_CHILD, :DWORD, :ptr SHELLDETAILS
    STDMETHOD ColumnClick, :DWORD
  DECLARE_INTERFACE_IID__END

  ; IObjMgr::Append(punk)
  ;   This function adds an object to the end of a list of objects.
  ; IObjMgr::Remove(punk)
  ;   This function removes an object from a list of objects.
  ; This is implemented by CLSID_ACLMulti so each AutoComplete List
  ; (CLSID_ACLHistory, CLSID_ACListISF, CLSID_ACLMRU) can be added.
  ; CLSID_ACLMulti's IEnumString will then be the union of the results
  ; from the COM Objects added.
  INTERFACE equ <IObjMgr>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(IObjMgr, IUnknown, "00BB2761-6A77-11D0-A535-00C04FD7D062")
    STDMETHOD Append, :ptr IUnknown
    STDMETHOD Remove, :ptr IUnknown
  DECLARE_INTERFACE_IID__END

  ; IACList::Expand(LPCWSTR)
  ;   This function tells an autocomplete list to expand a specific string.
  ; If the user enters a multi-level path, AutoComplete (CLSID_AutoComplete)
  ; will use this interface to tell the "AutoComplete Lists" where to expand
  ; the results.
  ; For Example, if the user enters "C:\Program Files\Micros", AutoComplete
  ; first completely enumerate the "AutoComplete Lists" via IEnumString.  Then it
  ; will call the "AutoComplete Lists" with IACList::Expand(L"C:\Program Files").
  ; It will then enumerate the IEnumString interface again to get results in
  ; that directory.
  INTERFACE equ <IACList>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(IACList, IUnknown, "77A130B0-94FD-11D0-A544-00C04FD7d062")
    STDMETHOD Expand, :PCWSTR
  DECLARE_INTERFACE_IID__END

  ; This interface exists to allow the caller to set filter criteria
  ; for an AutoComplete List.  AutoComplete Lists generates the list of
  ; possible AutoComplete completions.  CLSID_ACListISF is one AutoComplete
  ; List COM object that implements this interface.
  INTERFACE equ <IACList2>
  AUTOCOMPLETELISTOPTIONS typedef SDWORD
  ACLO_NONE equ 0
  ; don't enumerate anything
  ACLO_CURRENTDIR equ 1
  ; enumerate current directory
  ACLO_MYCOMPUTER equ 2
  ; enumerate MyComputer
  ACLO_DESKTOP equ 4
  ; enumerate Desktop Folder
  ACLO_FAVORITES equ 8
  ; enumerate Favorites Folder
  ACLO_FILESYSONLY equ 16
  ; enumerate only the file system
  if (_WIN32_IE ge _WIN32_IE_IE60)
    ACLO_FILESYSDIRS equ 32
    ; enumerate only the file system dirs, UNC shares, and UNC servers.
  endif
  if (_WIN32_IE ge _WIN32_IE_IE70)
    ACLO_VIRTUALNAMESPACE equ 64
    ; enumereate on the virual namespace
  endif
  _tagAUTOCOMPLETELISTOPTIONS typedef AUTOCOMPLETELISTOPTIONS

  ??Interface equ <>
  DECLARE_INTERFACE_IID_(IACList2, IACList, "470141a0-5186-11d2-bbb6-0060977b464c")
    ; *** IACList2 specific methods ***
    STDMETHOD SetOptions, :DWORD
    STDMETHOD GetOptions, :ptr DWORD
  DECLARE_INTERFACE_IID__END

  ;*-------------------------------------------------------------------------*\
  ;INTERFACE: IProgressDialog
  ;DESCRIPTION:
  ;CLSID_ProgressDialog/IProgressDialog exist to allow a caller to create
  ;a progress dialog, set it's title, animation, text lines, progress, and
  ;it will do all the work of updating on a background thread, being modeless,
  ;handling the user canceling the operation, and estimating the time remaining
  ;until the operation completes.
  ;USAGE:
  ;This is how the dialog is used during operations that require progress
  ;and the ability to cancel:
  ;{
  ;DWORD dwComplete, dwTotal;
  ;IProgressDialog * ppd;
  ;CoCreateInstance(CLSID_ProgressDialog, NULL, CLSCTX_INPROC_SERVER, IID_IProgressDialog, (void **)&ppd);
  ;ppd->SetTitle(L"My Slow Operation");                                // Set the title of the dialog.
  ;ppd->SetAnimation(hInstApp, IDA_OPERATION_ANIMATION);               // Set the animation to play.
  ;ppd->StartProgressDialog(hwndParent, punk, PROGDLG_AUTOTIME, NULL); // Display and enable automatic estimated time remaining.
  ;ppd->SetCancelMsg(L"Please wait while the current operation is cleaned up", NULL);   // Will only be displayed if Cancel button is pressed.
  ;dwComplete = 0;
  ;dwTotal = CalcTotalUnitsToDo();
  ; Reset because CalcTotalUnitsToDo() took a long time and the estimated time
  ; is based on the time between ::StartProgressDialog() and the first
  ; ::SetProgress() call.
  ;ppd->Timer(PDTIMER_RESET, NULL);
  ;for (nIndex = 0; nIndex < nTotal; nIndex++)
  ;{
  ;if (TRUE == ppd->HasUserCancelled())
  ;break;
  ;ppd->SetLine(2, L"I'm processing item n", FALSE, NULL);
  ;dwComplete += DoSlowOperation();
  ;ppd->SetProgress(dwCompleted, dwTotal);
  ;}
  ;ppd->StopProgressDialog();
  ;ppd->Release();
  ;}
  ;\*-------------------------------------------------------------------------*
  ; Flags for IProgressDialog::StartProgressDialog() (dwFlags)
  ; The flag space includes OPPROGDLG_ and PROGDLG_ values, please guarantee they don't conflict. See shobjidl.idl for OPPROGDLG_*
  PROGDLG_NORMAL equ 00000000h; default normal progress dlg behavior

  PROGDLG_MODAL equ 00000001h; the dialog is modal to its hwndParent (default is modeless)

  PROGDLG_AUTOTIME equ 00000002h; automatically updates the "Line3" text with the "time remaining" (you cant call SetLine3 if you passs this!)

  PROGDLG_NOTIME equ 00000004h; we dont show the "time remaining" if this is set. We need this if dwTotal < dwCompleted for sparse files

  PROGDLG_NOMINIMIZE equ 00000008h; Do not have a minimize button in the caption bar.

  PROGDLG_NOPROGRESSBAR equ 00000010h; Don't display the progress bar

  if (_WIN32_IE ge _WIN32_IE_IE70)
    PROGDLG_MARQUEEPROGRESS equ 00000020h; Use marquee progress (comctl32 v6 required)

    PROGDLG_NOCANCEL equ 00000040h; No cancel button (operation cannot be canceled) (use sparingly)

  endif
  ; Time Actions (dwTimerAction)
  PDTIMER_RESET equ 00000001h; Reset the timer so the progress will be calculated from now until the first ::SetProgress() is called so

  ; those this time will correspond to the values passed to ::SetProgress().  Only do this before ::SetProgress() is called.
  if (_WIN32_IE ge _WIN32_IE_IE70)
    PDTIMER_PAUSE equ 00000002h; Progress has been suspended

    PDTIMER_RESUME equ 00000003h; Progress has resumed

  endif
  INTERFACE equ <IProgressDialog>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(IProgressDialog, IUnknown, "EBBC7C04-315E-11d2-B62F-006097DF5BD4")
    STDMETHOD StartProgressDialog, :HWND, :ptr IUnknown, :DWORD, :LPCVOID
    STDMETHOD StopProgressDialog
    STDMETHOD SetTitle, :PCWSTR
    STDMETHOD SetAnimation, :HINSTANCE, :DWORD
    STDMETHOD_ BOOL, HasUserCancelled
    STDMETHOD SetProgress, :DWORD, :DWORD
    STDMETHOD SetProgress64, :QWORD, :QWORD
    STDMETHOD SetLine, :DWORD, :PCWSTR, :DWORD, :LPCVOID
    STDMETHOD SetCancelMsg, :PCWSTR, :LPCVOID
    STDMETHOD Timer, :DWORD, :LPCVOID
  DECLARE_INTERFACE_IID__END

  ;==========================================================================
  ; IDockingWindowSite/IDockingWindow/IDockingWindowFrame interfaces
  ; IInputObjectSite/IInputObject interfaces
  ;  These interfaces allow us (or ISVs) to install/update external Internet
  ; Toolbar for IE and the shell. The frame will simply get the CLSID from
  ; registry (to be defined) and CoCreateInstance it.
  ;==========================================================================
  ;-------------------------------------------------------------------------
  ; IDockingWindowSite interface
  ;   A site implements this interface so the object can negotiate for
  ; and inquire about real estate on the site.
  ; [Member functions]
  ; IDockingWindowSite::GetBorderDW(punkObj, prcBorder)
  ;   Site returns the bounding rectangle of the given source object
  ;   (punkObj).
  ; IDockingWindowSite::RequestBorderSpaceDW(punkObj, pbw)
  ;   Object requests that the site makes room for it, as specified in
  ;   *pbw.
  ; IDockingWindowSite::SetBorderSpaceDW(punkObj, pbw)
  ;   Object requests that the site set the border spacing to the size
  ;   specified in *pbw.
  ;-------------------------------------------------------------------------
  INTERFACE equ <IDockingWindowSite>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(IDockingWindowSite, IOleWindow, "2a342fc2-7b26-11d0-8ca9-00a0c92dbfe8")
    STDMETHOD GetBorderDW, :ptr IUnknown, :ptr RECT
    STDMETHOD RequestBorderSpaceDW, :ptr IUnknown, :LPCBORDERWIDTHS
    STDMETHOD SetBorderSpaceDW, :ptr IUnknown, :LPCBORDERWIDTHS
  DECLARE_INTERFACE_IID__END

  ; We need to make sure that WININET.H is included before this interface is
  ; used because the COMPONENT structure uses INTERNET_MAX_URL_LENGTH
  ifdef _WININET_
    ;  Flags and structures used by IActiveDesktop
    WALLPAPEROPT struct
      dwSize DWORD ?
      ; size of this Structure.
      dwStyle DWORD ?
      ; WPSTYLE_* mentioned above
    WALLPAPEROPT ends
    _tagWALLPAPEROPT typedef WALLPAPEROPT
    LPWALLPAPEROPT typedef ptr WALLPAPEROPT
    LPCWALLPAPEROPT typedef ptr WALLPAPEROPT
    COMPONENTSOPT struct
      dwSize DWORD ?
      ;Size of this structure
      fEnableComponents DWORD ?
      ;Enable components?
      fActiveDesktop DWORD ?
      ; Active desktop enabled ?
    COMPONENTSOPT ends
    _tagCOMPONENTSOPT typedef COMPONENTSOPT
    LPCOMPONENTSOPT typedef ptr COMPONENTSOPT
    LPCCOMPONENTSOPT typedef ptr COMPONENTSOPT
    COMPPOS struct
      dwSize DWORD ?
      ;Size of this structure
      iLeft SDWORD ?
      ;Left of top-left corner in screen co-ordinates.
      iTop SDWORD ?
      ;Top of top-left corner in screen co-ordinates.
      dwWidth DWORD ?
      ; Width in pixels.
      dwHeight DWORD ?
      ; Height in pixels.
      izIndex SDWORD ?
      ; Indicates the Z-order of the component.
      fCanResize DWORD ?
      ; Is the component resizeable?
      fCanResizeX DWORD ?
      ; Resizeable in X-direction?
      fCanResizeY DWORD ?
      ; Resizeable in Y-direction?
      iPreferredLeftPercent SDWORD ?
      ;Left of top-left corner as percent of screen width
      iPreferredTopPercent SDWORD ?
      ;Top of top-left corner as percent of screen height
    COMPPOS ends
    _tagCOMPPOS typedef COMPPOS
    LPCOMPPOS typedef ptr COMPPOS
    LPCCOMPPOS typedef ptr COMPPOS
    COMPSTATEINFO struct
      dwSize DWORD ?
      ; Size of this structure.
      iLeft SDWORD ?
      ; Left of the top-left corner in screen co-ordinates.
      iTop SDWORD ?
      ; Top of top-left corner in screen co-ordinates.
      dwWidth DWORD ?
      ; Width in pixels.
      dwHeight DWORD ?
      ; Height in pixels.
      dwItemState DWORD ?
      ; State of the component (full-screen mode or split-screen or normal state.
    COMPSTATEINFO ends
    _tagCOMPSTATEINFO typedef COMPSTATEINFO
    LPCOMPSTATEINFO typedef ptr COMPSTATEINFO
    LPCCOMPSTATEINFO typedef ptr COMPSTATEINFO
    COMPONENT_TOP equ (3fffffffh); izOrder value meaning component is at the top

    ; iCompType values
    COMP_TYPE_HTMLDOC equ 0
    COMP_TYPE_PICTURE equ 1
    COMP_TYPE_WEBSITE equ 2
    COMP_TYPE_CONTROL equ 3
    COMP_TYPE_CFHTML equ 4
    COMP_TYPE_MAX equ 4
    ; The following is the COMPONENT structure used in IE4.01, IE4.0 and Memphis. It is kept here for compatibility
    ; reasons.
    IE4COMPONENT struct
      dwSize DWORD ?
      ;Size of this structure
      dwID DWORD ?
      ;Reserved: Set it always to zero.
      iComponentType SDWORD ?
      ;One of COMP_TYPE_*
      fChecked DWORD ?
      ; Is this component enabled?
      fDirty DWORD ?
      ; Had the component been modified and not yet saved to disk?
      fNoScroll DWORD ?
      ; Is the component scrollable?
      cpPos COMPPOS <>
      ; Width, height etc.,
      wszFriendlyName WORD MAX_PATH dup (?)
      ; Friendly name of component.
      wszSource WORD INTERNET_MAX_URL_LENGTH dup (?)
      ;URL of the component.
      wszSubscribedURL WORD INTERNET_MAX_URL_LENGTH dup (?)
      ;Subscrined URL
    IE4COMPONENT ends
    _tagIE4COMPONENT typedef IE4COMPONENT
    LPIE4COMPONENT typedef ptr IE4COMPONENT
    LPCIE4COMPONENT typedef ptr IE4COMPONENT
    ; The following is the new NT5 component structure. Note that the initial portion of this component exactly
    ; matches the IE4COMPONENT structure. All new fields are added at the bottom and the dwSize field is used to
    ; distinguish between IE4COMPONENT and the new COMPONENT structures.
    COMPONENT struct
      dwSize DWORD ?
      ;Size of this structure
      dwID DWORD ?
      ;Reserved: Set it always to zero.
      iComponentType SDWORD ?
      ;One of COMP_TYPE_*
      fChecked DWORD ?
      ; Is this component enabled?
      fDirty DWORD ?
      ; Had the component been modified and not yet saved to disk?
      fNoScroll DWORD ?
      ; Is the component scrollable?
      cpPos COMPPOS <>
      ; Width, height etc.,
      wszFriendlyName WORD MAX_PATH dup (?)
      ; Friendly name of component.
      wszSource WORD INTERNET_MAX_URL_LENGTH dup (?)
      ;URL of the component.
      wszSubscribedURL WORD INTERNET_MAX_URL_LENGTH dup (?)
      ;Subscrined URL
      ;New fields are added below. Everything above here must exactly match the IE4COMPONENT Structure.
      dwCurItemState DWORD ?
      ; Current state of the Component.
      csiOriginal COMPSTATEINFO <>
      ; Original state of the component when it was first added.
      csiRestored COMPSTATEINFO <>
      ; Restored state of the component.
    COMPONENT ends
    _tagCOMPONENT typedef COMPONENT
    LPCOMPONENT typedef ptr COMPONENT
    LPCCOMPONENT typedef ptr COMPONENT
    ; Defines for dwCurItemState
    IS_NORMAL equ 00000001h
    IS_FULLSCREEN equ 00000002h
    IS_SPLIT equ 00000004h
    IS_VALIDSIZESTATEBITS equ <(IS_NORMAL or IS_SPLIT or IS_FULLSCREEN)>; The set of IS_* state bits which define the "size" of the component - these bits are mutually exclusive.

    IS_VALIDSTATEBITS equ (IS_NORMAL or IS_SPLIT or IS_FULLSCREEN or 80000000h or 40000000h); All of the currently defined IS_* bits.

    ;//////////////////////////////////////////
    ; Flags for IActiveDesktop::ApplyChanges()
    AD_APPLY_SAVE equ 00000001h
    AD_APPLY_HTMLGEN equ 00000002h
    AD_APPLY_REFRESH equ 00000004h
    AD_APPLY_ALL equ <(AD_APPLY_SAVE or AD_APPLY_HTMLGEN or AD_APPLY_REFRESH)>
    AD_APPLY_FORCE equ 00000008h
    AD_APPLY_BUFFERED_REFRESH equ 00000010h
    AD_APPLY_DYNAMICREFRESH equ 00000020h
    ;//////////////////////////////////////////
    ; Flags for IActiveDesktop::GetWallpaper()
    if (NTDDI_VERSION ge NTDDI_VISTA)
      AD_GETWP_BMP equ 00000000h
      AD_GETWP_IMAGE equ 00000001h
      AD_GETWP_LAST_APPLIED equ 00000002h
    endif
    ;//////////////////////////////////////////
    ; Flags for IActiveDesktop::GetWallpaperOptions()
    ;           IActiveDesktop::SetWallpaperOptions()
    WPSTYLE_CENTER equ 0
    WPSTYLE_TILE equ 1
    WPSTYLE_STRETCH equ 2
    if (NTDDI_VERSION ge NTDDI_WIN7)
      WPSTYLE_KEEPASPECT equ 3
      WPSTYLE_CROPTOFIT equ 4
    endif
    ; NTDDI_WIN7
    if (NTDDI_VERSION ge NTDDI_WIN8)
      WPSTYLE_SPAN equ 5
    endif
    ; NTDDI_WIN8
    if (NTDDI_VERSION ge NTDDI_WIN8)
      WPSTYLE_MAX equ 6
    elseif (NTDDI_VERSION ge NTDDI_WIN7)
      WPSTYLE_MAX equ 5
    else
      WPSTYLE_MAX equ 3
    endif
    ;//////////////////////////////////////////
    ; Flags for IActiveDesktop::ModifyComponent()
    COMP_ELEM_TYPE equ 00000001h
    COMP_ELEM_CHECKED equ 00000002h
    COMP_ELEM_DIRTY equ 00000004h
    COMP_ELEM_NOSCROLL equ 00000008h
    COMP_ELEM_POS_LEFT equ 00000010h
    COMP_ELEM_POS_TOP equ 00000020h
    COMP_ELEM_SIZE_WIDTH equ 00000040h
    COMP_ELEM_SIZE_HEIGHT equ 00000080h
    COMP_ELEM_POS_ZINDEX equ 00000100h
    COMP_ELEM_SOURCE equ 00000200h
    COMP_ELEM_FRIENDLYNAME equ 00000400h
    COMP_ELEM_SUBSCRIBEDURL equ 00000800h
    COMP_ELEM_ORIGINAL_CSI equ 00001000h
    COMP_ELEM_RESTORED_CSI equ 00002000h
    COMP_ELEM_CURITEMSTATE equ 00004000h
    COMP_ELEM_ALL equ <(COMP_ELEM_TYPE or COMP_ELEM_CHECKED or COMP_ELEM_DIRTY or COMP_ELEM_NOSCROLL or COMP_ELEM_POS_LEFT or COMP_ELEM_SIZE_WIDTH or COMP_ELEM_SIZE_HEIGHT or COMP_ELEM_POS_ZINDEX or COMP_ELEM_SOURCE or COMP_ELEM_FRIENDLYNAME or COMP_ELEM_POS_TOP or COMP_ELEM_SUBSCRIBEDURL or COMP_ELEM_ORIGINAL_CSI or COMP_ELEM_RESTORED_CSI or COMP_ELEM_CURITEMSTATE)>
    ;//////////////////////////////////////////
    ; Flags for IActiveDesktop::AddDesktopItemWithUI()
    tagDTI_ADTIWUI typedef SDWORD
    DTI_ADDUI_DEFAULT equ 00000000h
    DTI_ADDUI_DISPSUBWIZARD equ 00000001h
    DTI_ADDUI_POSITIONITEM equ 00000002h

    ;//////////////////////////////////////////
    ; Flags for IActiveDesktop::AddUrl()
    ADDURL_SILENT equ 0001h
    ;//////////////////////////////////////////
    ; Default positions for ADI
    COMPONENT_DEFAULT_LEFT equ (0FFFFh)
    COMPONENT_DEFAULT_TOP equ (0FFFFh)
    ;  Interface for manipulating the Active Desktop.
    INTERFACE equ <IActiveDesktop>
    ??Interface equ <>
    DECLARE_INTERFACE_IID_(IActiveDesktop, IUnknown, "f490eb00-1240-11d1-9888-006097deacf9")
      ; IUnknown methods
      STDMETHOD QueryInterface, :REFIID, :ptr ptr 
      STDMETHOD_ ULONG, AddRef
      STDMETHOD_ ULONG, Release
      ; IActiveDesktop methods
      STDMETHOD ApplyChanges, :DWORD
      STDMETHOD GetWallpaper, :POINTER, :DWORD, :DWORD
      STDMETHOD SetWallpaper, :PCWSTR, :DWORD
      STDMETHOD GetWallpaperOptions, :LPWALLPAPEROPT, :DWORD
      STDMETHOD SetWallpaperOptions, :LPCWALLPAPEROPT, :DWORD
      STDMETHOD GetPattern, :POINTER, :DWORD, :DWORD
      STDMETHOD SetPattern, :PCWSTR, :DWORD
      STDMETHOD GetDesktopItemOptions, :LPCOMPONENTSOPT, :DWORD
      STDMETHOD SetDesktopItemOptions, :LPCCOMPONENTSOPT, :DWORD
      STDMETHOD AddDesktopItem, :LPCCOMPONENT, :DWORD
      STDMETHOD AddDesktopItemWithUI, :HWND, :LPCOMPONENT, :DWORD
      STDMETHOD ModifyDesktopItem, :LPCCOMPONENT, :DWORD
      STDMETHOD RemoveDesktopItem, :LPCCOMPONENT, :DWORD
      STDMETHOD GetDesktopItemCount, :ptr SDWORD, :DWORD
      STDMETHOD GetDesktopItem, :SDWORD, :LPCOMPONENT, :DWORD
      STDMETHOD GetDesktopItemByID, :XWORD, :LPCOMPONENT, :DWORD
      STDMETHOD GenerateDesktopItemHtml, :PCWSTR, :LPCOMPONENT, :DWORD
      STDMETHOD AddUrl, :HWND, :PCWSTR, :LPCOMPONENT, :DWORD
      STDMETHOD GetDesktopItemBySource, :PCWSTR, :LPCOMPONENT, :DWORD
    DECLARE_INTERFACE_IID__END

    LPACTIVEDESKTOP typedef ptr IActiveDesktop
  endif
  ; _WININET_
  MAX_COLUMN_NAME_LEN equ 80
  MAX_COLUMN_DESC_LEN equ 128
  ;==========================================================================
  ; Clipboard format which may be supported by IDataObject from system
  ; defined shell folders (such as directories, network, ...).
  ;==========================================================================
  CFSTR_SHELLIDLIST equ <TEXT("Shell IDList Array")>; CF_IDLIST

  CFSTR_SHELLIDLISTOFFSET equ <TEXT("Shell Object Offsets")>; CF_OBJECTPOSITIONS

  CFSTR_NETRESOURCES equ <TEXT("Net Resource")>; CF_NETRESOURCE

  CFSTR_FILEDESCRIPTORA equ <TEXT("FileGroupDescriptor")>; CF_FILEGROUPDESCRIPTORA

  CFSTR_FILEDESCRIPTORW equ <TEXT("FileGroupDescriptorW")>; CF_FILEGROUPDESCRIPTORW

  CFSTR_FILECONTENTS equ <TEXT("FileContents")>; CF_FILECONTENTS

  CFSTR_FILENAMEA equ <TEXT("FileName")>; CF_FILENAMEA

  CFSTR_FILENAMEW equ <TEXT("FileNameW")>; CF_FILENAMEW

  CFSTR_PRINTERGROUP equ <TEXT("PrinterFriendlyName")>; CF_PRINTERS

  CFSTR_FILENAMEMAPA equ <TEXT("FileNameMap")>; CF_FILENAMEMAPA

  CFSTR_FILENAMEMAPW equ <TEXT("FileNameMapW")>; CF_FILENAMEMAPW

  CFSTR_SHELLURL equ <TEXT("UniformResourceLocator")>
  CFSTR_INETURLA equ <CFSTR_SHELLURL>
  CFSTR_INETURLW equ <TEXT("UniformResourceLocatorW")>
  CFSTR_PREFERREDDROPEFFECT equ <TEXT("Preferred DropEffect")>
  CFSTR_PERFORMEDDROPEFFECT equ <TEXT("Performed DropEffect")>
  CFSTR_PASTESUCCEEDED equ <TEXT("Paste Succeeded")>
  CFSTR_INDRAGLOOP equ <TEXT("InShellDragLoop")>
  CFSTR_MOUNTEDVOLUME equ <TEXT("MountedVolume")>
  CFSTR_PERSISTEDDATAOBJECT equ <TEXT("PersistedDataObject")>
  CFSTR_TARGETCLSID equ <TEXT("TargetCLSID")>; HGLOBAL with a CLSID of the drop target

  CFSTR_LOGICALPERFORMEDDROPEFFECT equ <TEXT("Logical Performed DropEffect")>
  CFSTR_AUTOPLAY_SHELLIDLISTS equ <TEXT("Autoplay Enumerated IDList Array")>; (HGLOBAL with LPIDA)

  CFSTR_UNTRUSTEDDRAGDROP equ <TEXT("UntrustedDragDrop")>;  DWORD

  CFSTR_FILE_ATTRIBUTES_ARRAY equ <TEXT("File Attributes Array")>; (FILE_ATTRIBUTES_ARRAY format on HGLOBAL)

  CFSTR_INVOKECOMMAND_DROPPARAM equ <TEXT("InvokeCommand DropParam")>; (HGLOBAL with LPWSTR)

  CFSTR_SHELLDROPHANDLER equ <TEXT("DropHandlerCLSID")>; (HGLOBAL with CLSID of drop handler)

  CFSTR_DROPDESCRIPTION equ <TEXT("DropDescription")>; (HGLOBAL with DROPDESCRIPTION)

  CFSTR_ZONEIDENTIFIER equ <TEXT("ZoneIdentifier")>;  DWORD, to be used with CFSTR_FILECONTENTS data transfers

  ifdef UNICODE
    CFSTR_FILEDESCRIPTOR equ <CFSTR_FILEDESCRIPTORW>
    CFSTR_FILENAME equ <CFSTR_FILENAMEW>
    CFSTR_FILENAMEMAP equ <CFSTR_FILENAMEMAPW>
    CFSTR_INETURL equ <CFSTR_INETURLW>
  else
    CFSTR_FILEDESCRIPTOR equ <CFSTR_FILEDESCRIPTORA>
    CFSTR_FILENAME equ <CFSTR_FILENAMEA>
    CFSTR_FILENAMEMAP equ <CFSTR_FILENAMEMAPA>
    CFSTR_INETURL equ <CFSTR_INETURLA>
  endif
  DVASPECT_SHORTNAME equ 2; use for CF_HDROP to get short name version of file paths

  DVASPECT_COPY equ 3; use to indicate format is a "Copy" of the data (FILECONTENTS, FILEDESCRIPTOR, etc)

  DVASPECT_LINK equ 4; use to indicate format is a "Shortcut" to the data (FILECONTENTS, FILEDESCRIPTOR, etc)

  include pshpack8.inc
  ; format of CF_NETRESOURCE
  NRESARRAY struct
    ; anr
    cItems DWORD ?
    nr NETRESOURCE 1 dup (<>)
  NRESARRAY ends
  _NRESARRAY typedef NRESARRAY
  LPNRESARRAY typedef ptr NRESARRAY
  ;* Return to byte packing *
  include poppack.inc
  ; format of CF_IDLIST
  CIDA struct
    cidl DWORD ?
    ; number of relative IDList
    aoffset DWORD 1 dup (?)
    ; [0]: folder IDList, [1]-[cidl]: item IDList
  CIDA ends
  _IDA typedef CIDA
  LPIDA typedef ptr CIDA
  ; FILEDESCRIPTOR.dwFlags field indicate which fields are valid in the FILEDESCRIPTOR struct
  FD_FLAGS typedef SDWORD
  FD_CLSID equ 00000001h
  FD_SIZEPOINT equ 00000002h
  FD_ATTRIBUTES equ 00000004h
  FD_CREATETIME equ 00000008h
  FD_ACCESSTIME equ 00000010h
  FD_WRITESTIME equ 00000020h
  FD_FILESIZE equ 00000040h
  FD_PROGRESSUI equ 00004000h
  ; Show Progress UI w/Drag and Drop
  FD_LINKUI equ 00008000h
  ; 'link' UI is prefered
  if (NTDDI_VERSION ge NTDDI_VISTA)
    FD_UNICODE equ 80000000h
    ; this descriptor is UNICODE
  endif

  FILEDESCRIPTORA struct
    dwFlags DWORD ?
    clsid CLSID <>
    sizel SIZEL <>
    pointl POINTL <>
    dwFileAttributes DWORD ?
    ftCreationTime FILETIME <>
    ftLastAccessTime FILETIME <>
    ftLastWriteTime FILETIME <>
    nFileSizeHigh DWORD ?
    nFileSizeLow DWORD ?
    cFileName SBYTE MAX_PATH dup (?)
  FILEDESCRIPTORA ends
  _FILEDESCRIPTORA typedef FILEDESCRIPTORA
  LPFILEDESCRIPTORA typedef ptr FILEDESCRIPTORA
  FILEDESCRIPTORW struct
    dwFlags DWORD ?
    clsid CLSID <>
    sizel SIZEL <>
    pointl POINTL <>
    dwFileAttributes DWORD ?
    ftCreationTime FILETIME <>
    ftLastAccessTime FILETIME <>
    ftLastWriteTime FILETIME <>
    nFileSizeHigh DWORD ?
    nFileSizeLow DWORD ?
    cFileName WORD MAX_PATH dup (?)
  FILEDESCRIPTORW ends
  _FILEDESCRIPTORW typedef FILEDESCRIPTORW
  LPFILEDESCRIPTORW typedef ptr FILEDESCRIPTORW
  ifdef UNICODE
    FILEDESCRIPTOR equ <FILEDESCRIPTORW>
    LPFILEDESCRIPTOR equ <LPFILEDESCRIPTORW>
  else
    FILEDESCRIPTOR equ <FILEDESCRIPTORA>
    LPFILEDESCRIPTOR equ <LPFILEDESCRIPTORA>
  endif
  ; format of CF_FILEGROUPDESCRIPTOR
  FILEGROUPDESCRIPTORA struct
    ; fgd
    cItems DWORD ?
    fgd FILEDESCRIPTORA 1 dup (<>)
  FILEGROUPDESCRIPTORA ends
  _FILEGROUPDESCRIPTORA typedef FILEGROUPDESCRIPTORA
  LPFILEGROUPDESCRIPTORA typedef ptr FILEGROUPDESCRIPTORA
  FILEGROUPDESCRIPTORW struct
    ; fgd
    cItems DWORD ?
    fgd FILEDESCRIPTORW 1 dup (<>)
  FILEGROUPDESCRIPTORW ends
  _FILEGROUPDESCRIPTORW typedef FILEGROUPDESCRIPTORW
  LPFILEGROUPDESCRIPTORW typedef ptr FILEGROUPDESCRIPTORW
  ifdef UNICODE
    FILEGROUPDESCRIPTOR equ <FILEGROUPDESCRIPTORW>
    LPFILEGROUPDESCRIPTOR equ <LPFILEGROUPDESCRIPTORW>
  else
    FILEGROUPDESCRIPTOR equ <FILEGROUPDESCRIPTORA>
    LPFILEGROUPDESCRIPTOR equ <LPFILEGROUPDESCRIPTORA>
  endif
  ; format of CF_HDROP and CF_PRINTERS, in the HDROP case the data that follows
  ; is a double null terinated list of file names, for printers they are printer
  ; friendly names
  DROPFILES struct
    pFiles DWORD ?
    ; offset of file list
    pt POINT <>
    ; drop point (client coords)
    fNC DWORD ?
    ; is it on NonClient area
    ; and pt is in screen coords
    fWide DWORD ?
    ; WIDE character switch
  DROPFILES ends
  _DROPFILES typedef DROPFILES
  LPDROPFILES typedef ptr DROPFILES
  if (NTDDI_VERSION ge NTDDI_VISTA)
    FILE_ATTRIBUTES_ARRAY struct
      cItems DWORD ?
      ; number of items in rgdwFileAttributes array
      dwSumFileAttributes DWORD ?
      ; all of the attributes ORed together
      dwProductFileAttributes DWORD ?
      ; all of the attributes ANDed together
      rgdwFileAttributes DWORD 1 dup (?)
      ; array
    FILE_ATTRIBUTES_ARRAY ends
    ; clipboard format definition for CFSTR_FILE_ATTRIBUTES_ARRAY
  endif
  ; NTDDI_VISTA
  if (NTDDI_VERSION ge NTDDI_VISTA)
    DROPIMAGETYPE typedef SDWORD
    DROPIMAGE_INVALID equ -1
    ; no image preference (use default)
    DROPIMAGE_NONE equ 0
    ; red "no" circle
    DROPIMAGE_COPY equ DROPEFFECT_COPY
    ; plus for copy
    DROPIMAGE_MOVE equ DROPEFFECT_MOVE
    ; movement arrow for move
    DROPIMAGE_LINK equ DROPEFFECT_LINK
    ; link arrow for link
    DROPIMAGE_LABEL equ 6
    ; tag icon to indicate metadata will be changed
    DROPIMAGE_WARNING equ 7
    ; yellow exclamation, something is amiss with the operation
    DROPIMAGE_NOIMAGE equ 8
    ; no image at all

    DROPDESCRIPTION struct
      type_ DROPIMAGETYPE ?
      ; indicates the stock image to use
      ; text such as "Move to %1"
      szMessage WORD MAX_PATH dup (?)
      ; text such as "Documents", inserted as specified by szMessage
      szInsert WORD MAX_PATH dup (?)
      ; some UI coloring is applied to the text in szInsert, if used by specifying %1 in szMessage.
      ; %% and %1 are the subset of FormatMessage markers that are processed here.
    DROPDESCRIPTION ends
  endif
  ; (NTDDI_VERSION >= NTDDI_VISTA)
  ;====== File System Notification APIs ===============================
  SHChangeNotifyEntry struct
    pidl PCIDLIST_ABSOLUTE ?
    fRecursive DWORD ?
  SHChangeNotifyEntry ends
  _SHChangeNotifyEntry typedef SHChangeNotifyEntry
  ;  File System Notification flags
  SHCNRF_InterruptLevel equ 0001h
  SHCNRF_ShellLevel equ 0002h
  SHCNRF_RecursiveInterrupt equ 1000h
  SHCNRF_NewDelivery equ 8000h
  SHCNE_RENAMEITEM equ 00000001h
  SHCNE_CREATE equ 00000002h
  SHCNE_DELETE equ 00000004h
  SHCNE_MKDIR equ 00000008h
  SHCNE_RMDIR equ 00000010h
  SHCNE_MEDIAINSERTED equ 00000020h
  SHCNE_MEDIAREMOVED equ 00000040h
  SHCNE_DRIVEREMOVED equ 00000080h
  SHCNE_DRIVEADD equ 00000100h
  SHCNE_NETSHARE equ 00000200h
  SHCNE_NETUNSHARE equ 00000400h
  SHCNE_ATTRIBUTES equ 00000800h
  SHCNE_UPDATEDIR equ 00001000h
  SHCNE_UPDATEITEM equ 00002000h
  SHCNE_SERVERDISCONNECT equ 00004000h
  SHCNE_UPDATEIMAGE equ 00008000h
  SHCNE_DRIVEADDGUI equ 00010000h
  SHCNE_RENAMEFOLDER equ 00020000h
  SHCNE_FREESPACE equ 00040000h
  ; SHCNE_EXTENDED_EVENT: the extended event is identified in dwItem1,
  ; packed in LPITEMIDLIST format (same as SHCNF_DWORD packing).
  ; Additional information can be passed in the dwItem2 parameter
  ; of SHChangeNotify (called "pidl2" below), which if present, must also
  ; be in LPITEMIDLIST format.
  ; Unlike the standard events, the extended events are ORDINALs, so we
  ; don't run out of bits.  Extended events follow the SHCNEE_* naming
  ; convention.
  ; The dwItem2 parameter varies according to the extended event.
  SHCNE_EXTENDED_EVENT equ 04000000h
  SHCNE_ASSOCCHANGED equ 08000000h
  SHCNE_DISKEVENTS equ 0002381Fh
  SHCNE_GLOBALEVENTS equ 0C0581E0h; Events that dont match pidls first

  SHCNE_ALLEVENTS equ 7FFFFFFFh
  SHCNE_INTERRUPT equ 80000000h; The presence of this flag indicates

  ; that the event was generated by an
  ; interrupt.  It is stripped out before
  ; the clients of SHCNNotify_ see it.
  ; SHCNE_EXTENDED_EVENT extended events.  These events are ordinals.
  ; This is not a bitfield.
  SHCNEE_ORDERCHANGED equ 2; pidl2 is the changed folder

  SHCNEE_MSI_CHANGE equ 4; pidl2 is a SHChangeProductKeyAsIDList

  SHCNEE_MSI_UNINSTALL equ 5; pidl2 is a SHChangeProductKeyAsIDList

  ; Flags
  ; uFlags & SHCNF_TYPE is an ID which indicates what dwItem1 and dwItem2 mean
  SHCNF_IDLIST equ 0000h; LPITEMIDLIST

  SHCNF_PATHA equ 0001h; path name

  SHCNF_PRINTERA equ 0002h; printer friendly name

  SHCNF_DWORD equ 0003h; DWORD

  SHCNF_PATHW equ 0005h; path name

  SHCNF_PRINTERW equ 0006h; printer friendly name

  SHCNF_TYPE equ 00FFh
  SHCNF_FLUSH equ 1000h
  SHCNF_FLUSHNOWAIT equ 3000h; includes SHCNF_FLUSH

  SHCNF_NOTIFYRECURSIVE equ 10000h; Notify clients registered for any child

  ifdef UNICODE
    SHCNF_PATH equ <SHCNF_PATHW>
    SHCNF_PRINTER equ <SHCNF_PRINTERW>
  else
    SHCNF_PATH equ <SHCNF_PATHA>
    SHCNF_PRINTER equ <SHCNF_PRINTERA>
  endif
  ;  APIs
  @DefProto DllImport, SHChangeNotify, WIN_STD_CALL_CONV,, <:LONG, :UINT, :LPCVOID, :LPCVOID>, 16
  ; IShellChangeNotify
  INTERFACE equ <IShellChangeNotify>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(IShellChangeNotify, IUnknown, "D82BE2B1-5764-11D0-A96E-00C04FD705A2")
    STDMETHOD OnChange, :SDWORD, :PCIDLIST_ABSOLUTE, :PCIDLIST_ABSOLUTE
  DECLARE_INTERFACE_IID__END

  ; IQueryInfo
  ;-------------------------------------------------------------------------
  ; IQueryInfo interface
  ; [Methods]
  ;              ::GetInfoTip()
  ;-------------------------------------------------------------------------
  INTERFACE equ <IQueryInfo>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(IQueryInfo, IUnknown, "00021500-0000-0000-c000-000000000046")
    STDMETHOD GetInfoTip, :DWORD, :ptr POINTER
    STDMETHOD GetInfoFlags, :ptr DWORD
  DECLARE_INTERFACE_IID__END

  QITIPF_DEFAULT equ 00000000h
  QITIPF_USENAME equ 00000001h
  QITIPF_LINKNOTARGET equ 00000002h
  QITIPF_LINKUSETARGET equ 00000004h
  if (NTDDI_VERSION ge NTDDI_WINXP)
    QITIPF_USESLOWTIP equ 00000008h; Flag says it's OK to take a long time generating tip

  endif
  if (NTDDI_VERSION ge NTDDI_VISTA)
    QITIPF_SINGLELINE equ 00000010h
  endif
  QIF_CACHED equ 00000001h
  QIF_DONTEXPANDFOLDER equ 00000002h
  ; SHAddToRecentDocs
  SHARD typedef SDWORD
  SHARD_PIDL equ 00000001h
  SHARD_PATHA equ 00000002h
  SHARD_PATHW equ 00000003h
  if (NTDDI_VERSION ge NTDDI_WIN7)
    SHARD_APPIDINFO equ 00000004h
    ; indicates the data type is a pointer to a SHARDAPPIDINFO structure
    SHARD_APPIDINFOIDLIST equ 00000005h
    ; indicates the data type is a pointer to a SHARDAPPIDINFOIDLIST structure
    SHARD_LINK equ 00000006h
    ; indicates the data type is a pointer to an IShellLink instance
    SHARD_APPIDINFOLINK equ 00000007h
    ; indicates the data type is a pointer to a SHARDAPPIDINFOLINK structure
    SHARD_SHELLITEM equ 00000008h
    ; indicates the data type is a pointer to an IShellItem instance
  endif

  if (NTDDI_VERSION ge NTDDI_WIN7)
    SHARDAPPIDINFO struct
      psi POINTER ?
      ; The namespace location of the the item that should be added to the recent docs folder.
      pszAppID PCWSTR ?
      ; The id of the application that should be associated with this recent doc.
    SHARDAPPIDINFO ends
    SHARDAPPIDINFOIDLIST struct
      pidl PCIDLIST_ABSOLUTE ?
      ; The idlist for the shell item that should be added to the recent docs folder.
      pszAppID PCWSTR ?
      ; The id of the application that should be associated with this recent doc.
    SHARDAPPIDINFOIDLIST ends
    SHARDAPPIDINFOLINK struct
      psl POINTER ?
      ; An IShellLink instance that when launched opens a recently used item in the specified
      ; application. This link is not added to the recent docs folder, but will be added to the
      ; specified application's destination list.
      pszAppID PCWSTR ?
      ; The id of the application that should be associated with this recent doc.
    SHARDAPPIDINFOLINK ends
  endif
  ifdef UNICODE
    SHARD_PATH equ <SHARD_PATHW>
  else
    SHARD_PATH equ <SHARD_PATHA>
  endif
  ; The type of the data pointed to by pv is a function of uFlags values that are SHARD_XXX values.  PV can be a PCIDLIST_ABSOLUTE, PCWSTR, PCSTR, SHARDAPPIDINFO, or SHARDAPPIDINFOIDLIST.
  @DefProto DllImport, SHAddToRecentDocs, WIN_STD_CALL_CONV,, <:UINT, :LPCVOID>, 8
  include pshpack1.inc
  SHChangeDWORDAsIDList struct
    cb WORD ?
    dwItem1 DWORD ?
    dwItem2 DWORD ?
    cbZero WORD ?
  SHChangeDWORDAsIDList ends
  _SHChangeDWORDAsIDList typedef SHChangeDWORDAsIDList
  LPSHChangeDWORDAsIDList typedef ptr SHChangeDWORDAsIDList
  include poppack.inc
  if (NTDDI_VERSION ge NTDDI_WIN2K)
    SHChangeUpdateImageIDList struct
      cb WORD ?
      iIconIndex SDWORD ?
      iCurIndex SDWORD ?
      uFlags DWORD ?
      dwProcessID DWORD ?
      szName WORD MAX_PATH dup (?)
      cbZero WORD ?
    SHChangeUpdateImageIDList ends
    _SHChangeUpdateImageIDList typedef SHChangeUpdateImageIDList
    LPSHChangeUpdateImageIDList typedef ptr SHChangeUpdateImageIDList
    @DefProto DllImport, SHHandleUpdateImage, WIN_STD_CALL_CONV,, <:PCIDLIST_ABSOLUTE>, 4
    @DefProto DllImport, SHUpdateImageA, WIN_STD_CALL_CONV,, <:LPCSTR, :SDWORD, :UINT, :SDWORD>, 16
    @DefProto DllImport, SHUpdateImageW, WIN_STD_CALL_CONV,, <:LPCWSTR, :SDWORD, :UINT, :SDWORD>, 16
    ifdef UNICODE
      SHUpdateImage equ <SHUpdateImageW>
    else
      SHUpdateImage equ <SHUpdateImageA>
    endif
    ; !UNICODE
    ;* NTDDI_WIN2K *
  endif
  @DefProto DllImport, SHChangeNotifyRegister, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LONG, :UINT, :SDWORD, :ptr SHChangeNotifyEntry>, 24
  @DefProto DllImport, SHChangeNotifyDeregister, WIN_STD_CALL_CONV,, <:ULONG>, 4
  SCNRT_STATUS typedef SDWORD
  SCNRT_ENABLE equ 0
  SCNRT_DISABLE equ 1

  @DefProto DllImport, SHChangeNotification_Lock, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :ptr ptr PIDLIST_ABSOLUTE, :ptr LONG>, 16
  @DefProto DllImport, SHChangeNotification_Unlock, WIN_STD_CALL_CONV,, <:HANDLE>, 4
  ; The pidls that are given to the view via the ChangeNotifyEvents are simple Pidls,
  ; SHGetRealIDL() will convert them to true PIDLs.
  @DefProto DllImport, SHGetRealIDL, WIN_STD_CALL_CONV,, <:ptr IShellFolder, :PCUITEMID_CHILD, :ptr PITEMID_CHILD>, 12
  @DefProto DllImport, SHGetInstanceExplorer, WIN_STD_CALL_CONV,, <:ptr ptr IUnknown>, 4
  ; SHGetDataFromIDListA/W
  ; SHGetDataFromIDList nFormat values TCHAR
  SHGDFIL_FINDDATA equ 1
  SHGDFIL_NETRESOURCE equ 2
  SHGDFIL_DESCRIPTIONID equ 3
  SHDID_ROOT_REGITEM equ 1
  SHDID_FS_FILE equ 2
  SHDID_FS_DIRECTORY equ 3
  SHDID_FS_OTHER equ 4
  SHDID_COMPUTER_DRIVE35 equ 5
  SHDID_COMPUTER_DRIVE525 equ 6
  SHDID_COMPUTER_REMOVABLE equ 7
  SHDID_COMPUTER_FIXED equ 8
  SHDID_COMPUTER_NETDRIVE equ 9
  SHDID_COMPUTER_CDROM equ 10
  SHDID_COMPUTER_RAMDISK equ 11
  SHDID_COMPUTER_OTHER equ 12
  SHDID_NET_DOMAIN equ 13
  SHDID_NET_SERVER equ 14
  SHDID_NET_SHARE equ 15
  SHDID_NET_RESTOFNET equ 16
  SHDID_NET_OTHER equ 17
  if (NTDDI_VERSION ge NTDDI_WINXP)
    SHDID_COMPUTER_IMAGING equ 18
    SHDID_COMPUTER_AUDIO equ 19
    SHDID_COMPUTER_SHAREDDOCS equ 20
  endif
  if (NTDDI_VERSION ge NTDDI_VISTA)
    SHDID_MOBILE_DEVICE equ 21; PDA/PalmPC

  endif
  if (NTDDI_VERSION ge NTDDI_WIN10_RS4)
    SHDID_REMOTE_DESKTOP_DRIVE equ 22
  endif
  include pshpack8.inc
  SHDESCRIPTIONID struct
    dwDescriptionId DWORD ?
    clsid CLSID <>
  SHDESCRIPTIONID ends
  _SHDESCRIPTIONID typedef SHDESCRIPTIONID
  LPSHDESCRIPTIONID typedef ptr SHDESCRIPTIONID
  ;* Return to byte packing *
  include poppack.inc
  ; these delegate to IShellFolder2::GetDetailsEx()
  @DefProto DllImport, SHGetDataFromIDListA, WIN_STD_CALL_CONV,, <:ptr IShellFolder, :PCUITEMID_CHILD, :SDWORD, :ptr, :SDWORD>, 20
  @DefProto DllImport, SHGetDataFromIDListW, WIN_STD_CALL_CONV,, <:ptr IShellFolder, :PCUITEMID_CHILD, :SDWORD, :ptr, :SDWORD>, 20
  ifdef UNICODE
    SHGetDataFromIDList equ <SHGetDataFromIDListW>
  else
    SHGetDataFromIDList equ <SHGetDataFromIDListA>
  endif
  ; !UNICODE
  ;===========================================================================
  ; PathResolve flags
  PRF_VERIFYEXISTS equ 0001h
  PRF_TRYPROGRAMEXTENSIONS equ (0002h or PRF_VERIFYEXISTS)
  PRF_FIRSTDIRDEF equ 0004h
  PRF_DONTFINDLNK equ 0008h; if PRF_TRYPROGRAMEXTENSIONS is specified

  if (NTDDI_VERSION ge NTDDI_WINXPSP2)
    PRF_REQUIREABSOLUTE equ 0010h
  endif
  @DefProto DllImport, RestartDialog, WIN_STD_CALL_CONV,, <:HWND, :PCWSTR, :DWORD>, 12
  if (NTDDI_VERSION ge NTDDI_WINXP)
    @DefProto DllImport, RestartDialogEx, WIN_STD_CALL_CONV,, <:HWND, :PCWSTR, :DWORD, :DWORD>, 16
  endif
  @DefProto DllImport, SHCoCreateInstance, WIN_STD_CALL_CONV,, <:PCWSTR, :ptr CLSID, :ptr IUnknown, :REFIID, :ptr ptr>, 20
  if (NTDDI_VERSION ge NTDDI_VISTA)
    @DefProto DllImport, SHCreateDataObject, WIN_STD_CALL_CONV,, <:PCIDLIST_ABSOLUTE, :UINT, :PCUITEMID_CHILD_ARRAY, :ptr IDataObject, :REFIID, :ptr ptr>, 24
  endif
  @DefProto DllImport, CIDLData_CreateFromIDArray, WIN_STD_CALL_CONV,, <:PCIDLIST_ABSOLUTE, :UINT, :PCUIDLIST_RELATIVE_ARRAY, :ptr ptr IDataObject>, 16
  @DefProto DllImport, SHCreateStdEnumFmtEtc, WIN_STD_CALL_CONV,, <:UINT, :ptr FORMATETC, :ptr ptr IEnumFORMATETC>, 12
  @DefProto DllImport, SHDoDragDrop, WIN_STD_CALL_CONV,, <:HWND, :ptr IDataObject, :ptr IDropSource, :DWORD, :ptr DWORD>, 20
  ; stuff for doing auto scrolling
  NUM_POINTS equ 3
  AUTO_SCROLL_DATA struct
    ; asd
    iNextSample SDWORD ?
    dwLastScroll DWORD ?
    bFull DWORD ?
    pts POINT NUM_POINTS dup (<>)
    dwTimes DWORD NUM_POINTS dup (?)
  AUTO_SCROLL_DATA ends
  @DefProto DllImport, DAD_SetDragImage, WIN_STD_CALL_CONV,, <:HIMAGELIST, :ptr POINT>, 8
  @DefProto DllImport, DAD_DragEnterEx, WIN_STD_CALL_CONV,, <:HWND, :POINT>, 8
  @DefProto DllImport, DAD_DragEnterEx2, WIN_STD_CALL_CONV,, <:HWND, :POINT, :ptr IDataObject>, 12
  @DefProto DllImport, DAD_ShowDragImage, WIN_STD_CALL_CONV,, <:BOOL>, 4
  @DefProto DllImport, DAD_DragMove, WIN_STD_CALL_CONV,, <:POINT>, 4
  @DefProto DllImport, DAD_DragLeave, WIN_STD_CALL_CONV,, <>, 0
  @DefProto DllImport, DAD_AutoScroll, WIN_STD_CALL_CONV,, <:HWND, :ptr AUTO_SCROLL_DATA, :ptr POINT>, 12
  CABINETSTATE struct
    cLength WORD ?
    nVersion WORD ?
    ; NT: Show compressed volumes in a different colour
    ; NT: Do 8.3 name conversion, or not!
    ; NT: Administrators create comon groups
    CABINETSTATE_REC record CABINETSTATE_REC_Filler:16, CABINETSTATE_REC_fUnusedFlags:7, CABINETSTATE_REC_fAdminsCreateCommonGroups:1, CABINETSTATE_REC_fDontPrettyNames:1, CABINETSTATE_REC_fShowCompColor:1, CABINETSTATE_REC_fNewWindowMode:1, CABINETSTATE_REC_fDontShowDescBar:1, CABINETSTATE_REC_fSimpleDefault:1, CABINETSTATE_REC_fNotShell:1, CABINETSTATE_REC_fSaveLocalView:1, CABINETSTATE_REC_fFullPathTitle:1
    CABINETSTATE_BITS CABINETSTATE_REC <>
    fMenuEnumFilter DWORD ?
  CABINETSTATE ends
  LPCABINETSTATE typedef ptr CABINETSTATE
  CABINETSTATE_VERSION equ 2
  ; APIs for reading and writing the cabinet state.
  @DefProto DllImport, ReadCabinetState, WIN_STD_CALL_CONV,, <:ptr CABINETSTATE, :SDWORD>, 8
  @DefProto DllImport, WriteCabinetState, WIN_STD_CALL_CONV,, <:ptr CABINETSTATE>, 4
  @DefProto DllImport, PathMakeUniqueName, WIN_STD_CALL_CONV,, <:PWSTR, :UINT, :PCWSTR, :PCWSTR, :PCWSTR>, 20
  @DefProto DllImport, PathIsExe, WIN_STD_CALL_CONV,, <:PCWSTR>, 4
  ;  Return codes from PathCleanupSpec.  Negative return values are
  ;  unrecoverable errors
  PCS_FATAL equ 80000000h
  PCS_REPLACEDCHAR equ 00000001h
  PCS_REMOVEDCHAR equ 00000002h
  PCS_TRUNCATED equ 00000004h
  PCS_PATHTOOLONG equ 00000008h; Always combined with FATAL

  @DefProto DllImport, PathCleanupSpec, WIN_STD_CALL_CONV,, <:PCWSTR, :PWSTR>, 8
  @DefProto DllImport, PathResolve, WIN_STD_CALL_CONV,, <:PWSTR, :PZPCWSTR, :UINT>, 12
  @DefProto DllImport, GetFileNameFromBrowse, WIN_STD_CALL_CONV,, <:HWND, :PWSTR, :UINT, :PCWSTR, :PCWSTR, :PCWSTR, :PCWSTR>, 28
  @DefProto DllImport, DriveType, WIN_STD_CALL_CONV,, <:SDWORD>, 4
  @DefProto DllImport, RealDriveType, WIN_STD_CALL_CONV,, <:SDWORD, :BOOL>, 8
  @DefProto DllImport, IsNetDrive, WIN_STD_CALL_CONV,, <:SDWORD>, 4
  ; Flags for Shell_MergeMenus
  MM_ADDSEPARATOR equ 00000001h
  MM_SUBMENUSHAVEIDS equ 00000002h
  MM_DONTREMOVESEPS equ 00000004h
  @DefProto DllImport, Shell_MergeMenus, WIN_STD_CALL_CONV,, <:HMENU, :HMENU, :UINT, :UINT, :UINT, :ULONG>, 24
  ;*
  ;* The SHObjectProperties API provides an easy way to invoke the Properties
  ;*   context menu command on a subset of the shell item namespace.
  ;*
  ;*   PARAMETERS
  ;*
  ;*     hwnd              The window handle of the window which will own the dialog
  ;*     shopObjectType    A SHOP_ value as defined below
  ;*     pszObjectName     Name of the object, see SHOP_ values below
  ;*     pszPropertyPage   The name of the property sheet page to open to or NULL.
  ;*
  ;*   RETURN
  ;*
  ;*     TRUE if the Properties command was invoked
  ;*
  @DefProto DllImport, SHObjectProperties, WIN_STD_CALL_CONV,, <:HWND, :DWORD, :PCWSTR, :PCWSTR>, 16
  SHOP_PRINTERNAME equ 00000001h; pszObjectName points to a printer friendly name

  SHOP_FILEPATH equ 00000002h; pszObjectName points to a fully qualified path+file name

  SHOP_VOLUMEGUID equ 00000004h; pszObjectName points to a Volume GUID

  ;*
  ;* The SHFormatDrive API provides access to the Shell
  ;*   format dialog. This allows apps which want to format disks
  ;*   to bring up the same dialog that the Shell does to do it.
  ;*
  ;*   This dialog is not sub-classable. You cannot put custom
  ;*   controls in it. If you want this ability, you will have
  ;*   to write your own front end for the DMaint_FormatDrive
  ;*   engine.
  ;*
  ;*   NOTE that the user can format as many diskettes in the specified
  ;*   drive, or as many times, as he/she wishes to. There is no way to
  ;*   force any specififc number of disks to format. If you want this
  ;*   ability, you will have to write your own front end for the
  ;*   DMaint_FormatDrive engine.
  ;*
  ;*   NOTE also that the format will not start till the user pushes the
  ;*   start button in the dialog. There is no way to do auto start. If
  ;*   you want this ability, you will have to write your own front end
  ;*   for the DMaint_FormatDrive engine.
  ;*
  ;*   PARAMETERS
  ;*
  ;*     hwnd    = The window handle of the window which will own the dialog
  ;*               NOTE that unlike SHCheckDrive, hwnd == NULL does not cause
  ;*               this dialog to come up as a "top level application" window.
  ;*               This parameter should always be non-null, this dialog is
  ;*               only designed to be the child of another window, not a
  ;*               stand-alone application.
  ;*     drive   = The 0 based (A: == 0) drive number of the drive to format
  ;*     fmtID   = The ID of the physical format to format the disk with
  ;*               NOTE: The special value SHFMT_ID_DEFAULT means "use the
  ;*                     default format specified by the DMaint_FormatDrive
  ;*                     engine". If you want to FORCE a particular format
  ;*                     ID "up front" you will have to call
  ;*                     DMaint_GetFormatOptions yourself before calling
  ;*                     this to obtain the valid list of phys format IDs
  ;*                     (contents of the PhysFmtIDList array in the
  ;*                     FMTINFOSTRUCT).
  ;*     options = There is currently only two option bits defined
  ;*
  ;*                SHFMT_OPT_FULL
  ;*                SHFMT_OPT_SYSONLY
  ;*
  ;*               The normal defualt in the Shell format dialog is
  ;*               "Quick Format", setting this option bit indicates that
  ;*               the caller wants to start with FULL format selected
  ;*               (this is useful for folks detecting "unformatted" disks
  ;*               and wanting to bring up the format dialog).
  ;*
  ;*               The SHFMT_OPT_SYSONLY initializes the dialog to
  ;*               default to just sys the disk.
  ;*
  ;*               All other bits are reserved for future expansion and
  ;*               must be 0.
  ;*
  ;*               Please note that this is a bit field and not a value
  ;*               and treat it accordingly.
  ;*
  ;*   RETURN
  ;*      The return is either one of the SHFMT_* values, or if the
  ;*      returned DWORD value is not == to one of these values, then
  ;*      the return is the physical format ID of the last succesful
  ;*      format. The LOWORD of this value can be passed on subsequent
  ;*      calls as the fmtID parameter to "format the same type you did
  ;*      last time".
  ;*
  ;*
  @DefProto DllImport, SHFormatDrive, WIN_STD_CALL_CONV,, <:HWND, :UINT, :UINT, :UINT>, 16
  ; Special value of fmtID which means "use the default format"
  SHFMT_ID_DEFAULT equ 0FFFFh
  ; Option bits for options parameter
  SHFMT_OPT_FULL equ 0001h
  SHFMT_OPT_SYSONLY equ 0002h
  ; Special return values. PLEASE NOTE that these are DWORD values.
  SHFMT_ERROR equ 0FFFFFFFFh; Error on last format, drive may be formatable

  SHFMT_CANCEL equ 0FFFFFFFEh; Last format was canceled

  SHFMT_NOFORMAT equ 0FFFFFFFDh; Drive is not formatable

  ifndef HPSXA_DEFINED
    HPSXA_DEFINED equ <>
    DECLARE_HANDLE HPSXA
  endif
  @DefProto DllImport, SHDestroyPropSheetExtArray, WIN_STD_CALL_CONV,, <:HPSXA>, 4
  @DefProto DllImport, SHAddFromPropSheetExtArray, WIN_STD_CALL_CONV,, <:HPSXA, :LPFNADDPROPSHEETPAGE, :LPARAM>, 12
  @DefProto DllImport, SHReplaceFromPropSheetExtArray, WIN_STD_CALL_CONV,, <:HPSXA, :UINT, :LPFNADDPROPSHEETPAGE, :LPARAM>, 16
  ; shell restriction values, parameter for SHRestricted()
  ; NTDDI_WINXP
  ; NTDDI_WINXP
  ; NTDDI_WIN2KSP3
  ; NTDDI_WINXP
  ; NTDDI_WIN2KSP3
  ; NTDDI_WINXP
  ; NTDDI_WIN2KSP3
  ; NTDDI_WINXP
  ; NTDDI_WIN2KSP4
  ; NTDDI_WINXP
  ; NTDDI_WINXPSP1
  ; NTDDI_WIN2KSP3
  ; NTDDI_WIN2KSP3
  ; NTDDI_WIN2KSP4
  ; NTDDI_WINXPSP2
  ; NTDDI_WINXPSP2
  ; NTDDI_WINXPSP2
  ; NTDDI_VISTA
  RESTRICTIONS typedef SDWORD
  ; NTDDI_WINXPSP2
  REST_NONE equ 00000000h
  REST_NORUN equ 00000001h
  REST_NOCLOSE equ 00000002h
  REST_NOSAVESET equ 00000004h
  REST_NOFILEMENU equ 00000008h
  REST_NOSETFOLDERS equ 00000010h
  REST_NOSETTASKBAR equ 00000020h
  REST_NODESKTOP equ 00000040h
  REST_NOFIND equ 00000080h
  REST_NODRIVES equ 00000100h
  REST_NODRIVEAUTORUN equ 00000200h
  REST_NODRIVETYPEAUTORUN equ 00000400h
  REST_NONETHOOD equ 00000800h
  REST_STARTBANNER equ 00001000h
  REST_RESTRICTRUN equ 00002000h
  REST_NOPRINTERTABS equ 00004000h
  REST_NOPRINTERDELETE equ 00008000h
  REST_NOPRINTERADD equ 00010000h
  REST_NOSTARTMENUSUBFOLDERS equ 00020000h
  REST_MYDOCSONNET equ 00040000h
  REST_NOEXITTODOS equ 00080000h
  REST_ENFORCESHELLEXTSECURITY equ 00100000h
  REST_LINKRESOLVEIGNORELINKINFO equ 00200000h
  REST_NOCOMMONGROUPS equ 00400000h
  REST_SEPARATEDESKTOPPROCESS equ 00800000h
  REST_NOWEB equ 01000000h
  REST_NOTRAYCONTEXTMENU equ 02000000h
  REST_NOVIEWCONTEXTMENU equ 04000000h
  REST_NONETCONNECTDISCONNECT equ 08000000h
  REST_STARTMENULOGOFF equ 10000000h
  REST_NOSETTINGSASSIST equ 20000000h
  REST_NOINTERNETICON equ 40000001h
  REST_NORECENTDOCSHISTORY equ 40000002h
  REST_NORECENTDOCSMENU equ 40000003h
  REST_NOACTIVEDESKTOP equ 40000004h
  REST_NOACTIVEDESKTOPCHANGES equ 40000005h
  REST_NOFAVORITESMENU equ 40000006h
  REST_CLEARRECENTDOCSONEXIT equ 40000007h
  REST_CLASSICSHELL equ 40000008h
  REST_NOCUSTOMIZEWEBVIEW equ 40000009h
  REST_NOHTMLWALLPAPER equ 40000010h
  REST_NOCHANGINGWALLPAPER equ 40000011h
  REST_NODESKCOMP equ 40000012h
  REST_NOADDDESKCOMP equ 40000013h
  REST_NODELDESKCOMP equ 40000014h
  REST_NOCLOSEDESKCOMP equ 40000015h
  REST_NOCLOSE_DRAGDROPBAND equ 40000016h
  ; Disable Close and Drag & Drop on ALL Bands
  REST_NOMOVINGBAND equ 40000017h
  ; Disable Moving ALL Bands
  REST_NOEDITDESKCOMP equ 40000018h
  REST_NORESOLVESEARCH equ 40000019h
  REST_NORESOLVETRACK equ 4000001Ah
  REST_FORCECOPYACLWITHFILE equ 4000001Bh
  if (NTDDI_VERSION lt NTDDI_VISTA)
    REST_NOLOGO3CHANNELNOTIFY equ 4000001Ch
  endif
  REST_NOFORGETSOFTWAREUPDATE equ 4000001Dh
  REST_NOSETACTIVEDESKTOP equ 4000001Eh
  ; No Active desktop on Settings Menu
  REST_NOUPDATEWINDOWS equ 4000001Fh
  ; No Windows Update on Settings Menu
  REST_NOCHANGESTARMENU equ 40000020h
  ; No Context menu or Drag and Drop on Start menu
  REST_NOFOLDEROPTIONS equ 40000021h
  ; No Folder Options on Settings Menu
  REST_HASFINDCOMPUTERS equ 40000022h
  ; Show Start/Search/Computers
  REST_INTELLIMENUS equ 40000023h
  REST_RUNDLGMEMCHECKBOX equ 40000024h
  REST_ARP_ShowPostSetup equ 40000025h
  ; ARP: Show Post-Setup page
  REST_NOCSC equ 40000026h
  ; Disable the ClientSide caching on SM
  REST_NOCONTROLPANEL equ 40000027h
  ; Remove the Control Panel only from SM|Settings
  REST_ENUMWORKGROUP equ 40000028h
  ; Enumerate workgroup in root of nethood
  REST_ARP_NOARP equ 40000029h
  ; ARP: Don't Allow ARP to come up at all
  REST_ARP_NOREMOVEPAGE equ 4000002Ah
  ; ARP: Don't allow Remove page
  REST_ARP_NOADDPAGE equ 4000002Bh
  ; ARP: Don't allow Add page
  REST_ARP_NOWINSETUPPAGE equ 4000002Ch
  ; ARP: Don't allow opt components page
  REST_GREYMSIADS equ 4000002Dh
  ; SM: Allow the greying of Darwin Ads in SM
  REST_NOCHANGEMAPPEDDRIVELABEL equ 4000002Eh
  ; Don't enable the UI which allows users to rename mapped drive labels
  REST_NOCHANGEMAPPEDDRIVECOMMENT equ 4000002Fh
  ; Don't enable the UI which allows users to change mapped drive comments
  REST_MaxRecentDocs equ 40000030h
  REST_NONETWORKCONNECTIONS equ 40000031h
  ; No Start Menu | Settings |Network Connections
  REST_FORCESTARTMENULOGOFF equ 40000032h
  ; Force logoff on the Start Menu
  REST_NOWEBVIEW equ 40000033h
  ; Disable Web View
  REST_NOCUSTOMIZETHISFOLDER equ 40000034h
  ; Disable Customize This Folder
  REST_NOENCRYPTION equ 40000035h
  ; Don't allow file encryption
  ;  Do NOT use me                     0x40000036,
  REST_DONTSHOWSUPERHIDDEN equ 40000037h
  ; don't show super hidden files
  REST_NOSHELLSEARCHBUTTON equ 40000038h
  REST_NOHARDWARETAB equ 40000039h
  ; No Hardware tab on Drives or in control panel
  REST_NORUNASINSTALLPROMPT equ 4000003Ah
  ; Don't bring up "Run As" prompt for install programs
  REST_PROMPTRUNASINSTALLNETPATH equ 4000003Bh
  ; Force the  "Run As" prompt for install programs on unc/network shares
  REST_NOMANAGEMYCOMPUTERVERB equ 4000003Ch
  ; No Manage verb on My Computer
  ;  Do NOT use me                     0x4000003D,
  REST_DISALLOWRUN equ 4000003Eh
  ; don't allow certain apps to be run
  REST_NOWELCOMESCREEN equ 4000003Fh
  ; don't allow the welcome screen to be displayed.
  REST_RESTRICTCPL equ 40000040h
  ; only allow certain cpls to be run
  REST_DISALLOWCPL equ 40000041h
  ; don't allow certain cpls to be run
  REST_NOSMBALLOONTIP equ 40000042h
  ; No Start Menu Balloon Tip
  REST_NOSMHELP equ 40000043h
  ; No Help on the Start Menu
  REST_NOWINKEYS equ 40000044h
  ; No Windows-X Hot keys
  REST_NOENCRYPTONMOVE equ 40000045h
  ; Don't automatically try to encrypt files that are moved to encryped directories
  REST_NOLOCALMACHINERUN equ 40000046h
  ; ignore HKLM\sw\ms\win\cv\Run and all of it's sub keys
  REST_NOCURRENTUSERRUN equ 40000047h
  ; ignore HKCU\sw\ms\win\cv\Run and all of it's sub keys
  REST_NOLOCALMACHINERUNONCE equ 40000048h
  ; ignore HKLM\sw\ms\win\cv\RunOnce and all of it's sub keys
  REST_NOCURRENTUSERRUNONCE equ 40000049h
  ; ignore HKCU\sw\ms\win\cv\RunOnce and all of it's sub keys
  REST_FORCEACTIVEDESKTOPON equ 4000004Ah
  ; Force ActiveDesktop to be turned ON all the time.
  ;  Do NOT use me                     0x4000004B,
  REST_NOVIEWONDRIVE equ 4000004Ch
  ; disallows CreateViewObject() on specified drives (CFSFolder only)
  if (NTDDI_VERSION ge NTDDI_WINXP) or Defined(IE_BACKCOMPAT_VERSION)
    REST_NONETCRAWL equ 4000004Dh
    ; disables the crawling of the WNet namespace.
    REST_NOSHAREDDOCUMENTS equ 4000004Eh
    ; don't auto share the Shared Documents/create link
  endif
  ; NTDDI_WINXP
  REST_NOSMMYDOCS equ 4000004Fh
  ; Don't show the My Documents item on the Start Menu.
  if (NTDDI_VERSION ge NTDDI_WINXP)
    REST_NOSMMYPICS equ 40000050h
    ; Don't show the My Pictures item on the Start Menu
    REST_ALLOWBITBUCKDRIVES equ 40000051h
    ; Bit mask indicating which which drives have bit bucket support
    REST_NONLEGACYSHELLMODE equ 40000052h
    ; new consumer shell modes
    REST_NOCONTROLPANELBARRICADE equ 40000053h
    ; The webview barricade in Control Panel
    REST_NOSTARTPAGE equ 40000054h
    ; Whistler Start Page on desktop.
    REST_NOAUTOTRAYNOTIFY equ 40000055h
    ; Whistler auto-tray notify feature
    REST_NOTASKGROUPING equ 40000056h
    ; Whistler taskbar button grouping feature
    REST_NOCDBURNING equ 40000057h
    ; whistler cd burning feature
  endif
  ; NTDDI_WINXP
  if (NTDDI_VERSION ge NTDDI_WIN2KSP3)
    REST_MYCOMPNOPROP equ 40000058h
    ; disables Properties on My Computer's context menu
    REST_MYDOCSNOPROP equ 40000059h
    ; disables Properties on My Documents' context menu
  endif
  ; NTDDI_WIN2KSP3
  if (NTDDI_VERSION ge NTDDI_WINXP)
    REST_NOSTARTPANEL equ 4000005Ah
    ; Windows start panel (New start menu) for Whistler.
    REST_NODISPLAYAPPEARANCEPAGE equ 4000005Bh
    ; disable Themes and Appearance tabs in the Display Control Panel.
    REST_NOTHEMESTAB equ 4000005Ch
    ; disable the Themes tab in the Display Control Panel.
    REST_NOVISUALSTYLECHOICE equ 4000005Dh
    ; disable the visual style drop down in the Appearance tab of the Display Control Panel.
    REST_NOSIZECHOICE equ 4000005Eh
    ; disable the size drop down in the Appearance tab of the Display Control Panel.
    REST_NOCOLORCHOICE equ 4000005Fh
    ; disable the color drop down in the Appearance tab of the Display Control Panel.
    REST_SETVISUALSTYLE equ 40000060h
    ; Load the specified file as the visual style.
  endif
  ; NTDDI_WINXP
  if (NTDDI_VERSION ge NTDDI_WIN2KSP3)
    REST_STARTRUNNOHOMEPATH equ 40000061h
    ; dont use the %HOMEPATH% env var for the Start-Run dialog
  endif
  ; NTDDI_WIN2KSP3
  if (NTDDI_VERSION ge NTDDI_WINXP)
    REST_NOUSERNAMEINSTARTPANEL equ 40000062h
    ; don't show the username is the startpanel.
    REST_NOMYCOMPUTERICON equ 40000063h
    ; don't show my computer anywhere, hide its contents
    REST_NOSMNETWORKPLACES equ 40000064h
    ; don't show network places in startpanel.
    REST_NOSMPINNEDLIST equ 40000065h
    ; don't show the pinned list in startpanel.
    REST_NOSMMYMUSIC equ 40000066h
    ; don't show MyMusic folder in startpanel
    REST_NOSMEJECTPC equ 40000067h
    ; don't show "Undoc PC" command in startmenu
    REST_NOSMMOREPROGRAMS equ 40000068h
    ; don't show "More Programs" button in StartPanel.
    REST_NOSMMFUPROGRAMS equ 40000069h
    ; don't show the MFU programs list in StartPanel.
    REST_NOTRAYITEMSDISPLAY equ 4000006Ah
    ; disables the display of the system tray
    REST_NOTOOLBARSONTASKBAR equ 4000006Bh
    ; disables toolbar display on the taskbar
  endif
  ; NTDDI_WINXP
  if (NTDDI_VERSION ge NTDDI_WIN2KSP3)
    REST_NOSMCONFIGUREPROGRAMS equ 4000006Fh
    ; No Configure Programs on Settings Menu
  endif
  ; NTDDI_WIN2KSP3
  if (NTDDI_VERSION ge NTDDI_WINXP)
    REST_HIDECLOCK equ 40000070h
    ; don't show the clock
    REST_NOLOWDISKSPACECHECKS equ 40000071h
    ; disable the low disk space checking
  endif
  ; NTDDI_WINXP
  if (NTDDI_VERSION ge NTDDI_WIN2KSP4)
    REST_NOENTIRENETWORK equ 40000072h
    ; removes the "Entire Network" link (i.e. from "My Network Places")
  endif
  ; NTDDI_WIN2KSP4
  if (NTDDI_VERSION ge NTDDI_WINXP)
    REST_NODESKTOPCLEANUP equ 40000073h
    ; disable the desktop cleanup wizard
    REST_BITBUCKNUKEONDELETE equ 40000074h
    ; disables recycling of files
    REST_BITBUCKCONFIRMDELETE equ 40000075h
    ; always show the delete confirmation dialog when deleting files
    REST_BITBUCKNOPROP equ 40000076h
    ; disables Properties on Recycle Bin's context menu
    REST_NODISPBACKGROUND equ 40000077h
    ; disables the Desktop tab in the Display CPL
    REST_NODISPSCREENSAVEPG equ 40000078h
    ; disables the Screen Saver tab in the Display CPL
    REST_NODISPSETTINGSPG equ 40000079h
    ; disables the Settings tab in the Display CPL
    REST_NODISPSCREENSAVEPREVIEW equ 4000007Ah
    ; disables the screen saver on the Screen Saver tab in the Display CPL
    REST_NODISPLAYCPL equ 4000007Bh
    ; disables the Display CPL
    REST_HIDERUNASVERB equ 4000007Ch
    ; hides the "Run As..." context menu item
    REST_NOTHUMBNAILCACHE equ 4000007Dh
    ; disables use of the thumbnail cache
  endif
  ; NTDDI_WINXP
  if (NTDDI_VERSION ge NTDDI_WINXPSP1) or Defined(IE_BACKCOMPAT_VERSION)
    REST_NOSTRCMPLOGICAL equ 4000007Eh
    ; dont use StrCmpLogical() instead use default CompareString()
    REST_NOPUBLISHWIZARD equ 4000007Fh
    ; disables publishing wizard (WPW)
    REST_NOONLINEPRINTSWIZARD equ 40000080h
    ; disables online prints wizard (OPW)
    REST_NOWEBSERVICES equ 40000081h
    ; disables the web specified services for both OPW and WPW
  endif
  ; NTDDI_WINXPSP1
  if (NTDDI_VERSION ge NTDDI_WIN2KSP3)
    REST_ALLOWUNHASHEDWEBVIEW equ 40000082h
    ; allow the user to be promted to accept web view templates that don't already have an md5 hash in the registry
  endif
  ; NTDDI_WIN2KSP3
  REST_ALLOWLEGACYWEBVIEW equ 40000083h
  ; allow legacy webview template to be shown.
  if (NTDDI_VERSION ge NTDDI_WIN2KSP3)
    REST_REVERTWEBVIEWSECURITY equ 40000084h
    ; disable added webview security measures (revert to w2k functionality).
  endif
  ; NTDDI_WIN2KSP3
  if (NTDDI_VERSION ge NTDDI_WIN2KSP4)
    REST_INHERITCONSOLEHANDLES equ 40000086h
    ; ShellExec() will check for the current process and target process being console processes to inherit handles
  endif
  ; NTDDI_WIN2KSP4
  if (NTDDI_VERSION ge NTDDI_WINXPSP2 and NTDDI_VERSION lt NTDDI_VISTA)
    REST_SORTMAXITEMCOUNT equ 40000087h
    ; Do not sort views with more items than this key. Useful for viewing big amount of files in one folder.
  endif
  if (NTDDI_VERSION ge NTDDI_WINXPSP2)
    REST_NOREMOTERECURSIVEEVENTS equ 40000089h
    ; Dont register network change events recursively to avoid network traffic
  endif
  ; NTDDI_WINXPSP2
  if (NTDDI_VERSION ge NTDDI_WINXPSP2)
    REST_NOREMOTECHANGENOTIFY equ 40000091h
    ; Do not notify for remote changy notifies
    if (NTDDI_VERSION lt NTDDI_VISTA)
      REST_NOSIMPLENETIDLIST equ 40000092h
      ; No simple network IDLists
    endif
    REST_NOENUMENTIRENETWORK equ 40000093h
    ; Don't enumerate entire network if we happen to get to it (in conjunction with REST_NOENTIRENETWORK)
    if (NTDDI_VERSION lt NTDDI_VISTA)
      REST_NODETAILSTHUMBNAILONNETWORK equ 40000094h
      ; Disable Thumbnail for Network files in DUI Details pane
    endif
    REST_NOINTERNETOPENWITH equ 40000095h
    ; dont allow looking on the internet for file associations
  endif
  ; NTDDI_WINXPSP2
  if (NTDDI_VERSION ge NTDDI_WINXPSP2)
    REST_DONTRETRYBADNETNAME equ 4000009Bh
    ; In Network Places: if provider returns ERROR_BAD_NET_NAME, give up
    REST_ALLOWFILECLSIDJUNCTIONS equ 4000009Ch
    ; re-enable legacy support for file.{guid} junctions in FileSystem Folder
    REST_NOUPNPINSTALL equ 4000009Dh
    ; disable "install UPnP" task in My Net Places
  endif
  ; NTDDI_WINXPSP2
  REST_ARP_DONTGROUPPATCHES equ 400000ACh
  ;List individual patches in Add/Remove Programs
  REST_ARP_NOCHOOSEPROGRAMSPAGE equ 400000ADh
  ;Choose programs page
  REST_NODISCONNECT equ 41000001h
  ; No Disconnect option in Start menu
  REST_NOSECURITY equ 41000002h
  ; No Security option in start menu
  REST_NOFILEASSOCIATE equ 41000003h
  ; Do not allow user to change file association
  if (NTDDI_VERSION ge NTDDI_WINXPSP2)
    REST_ALLOWCOMMENTTOGGLE equ 41000004h
    ; Allow the user to toggle the positions of the Comment and the Computer Name
    if (NTDDI_VERSION lt NTDDI_VISTA)
      REST_USEDESKTOPINICACHE equ 41000005h
      ; Cache desktop.ini entries from network folders
    endif
    ; NTDDI_VISTA
  endif
  ; NTDDI_WINXPSP2

  @DefProto DllImport, OpenRegStream, WIN_STD_CALL_CONV,, <:HKEY, :PCWSTR, :PCWSTR, :DWORD>, 16
  @DefProto DllImport, SHFindFiles, WIN_STD_CALL_CONV,, <:PCIDLIST_ABSOLUTE, :PCIDLIST_ABSOLUTE>, 8
  @DefProto DllImport, PathGetShortPath, WIN_STD_CALL_CONV,, <:PWSTR>, 4
  @DefProto DllImport, PathYetAnotherMakeUniqueName, WIN_STD_CALL_CONV,, <:PWSTR, :PCWSTR, :PCWSTR, :PCWSTR>, 16
  @DefProto DllImport, Win32DeleteFile, WIN_STD_CALL_CONV,, <:PCWSTR>, 4
  @DefProto DllImport, SHRestricted, WIN_STD_CALL_CONV,, <:RESTRICTIONS>, 4
  @DefProto DllImport, SignalFileOpen, WIN_STD_CALL_CONV,, <:PCIDLIST_ABSOLUTE>, 4
  if (NTDDI_VERSION ge NTDDI_VISTA)
    @DefProto DllImport, AssocGetDetailsOfPropKey, WIN_STD_CALL_CONV,, <:ptr IShellFolder, :PCUITEMID_CHILD, :ptr PROPERTYKEY, :ptr VARIANT, :ptr BOOL>, 20
  endif
  ; both ANSI and UNICODE
  @DefProto DllImport, SHStartNetConnectionDialogA, WIN_STD_CALL_CONV,, <:HWND, :LPCSTR, :DWORD>, 12
  ; both ANSI and UNICODE
  @DefProto DllImport, SHStartNetConnectionDialogW, WIN_STD_CALL_CONV,, <:HWND, :LPCWSTR, :DWORD>, 12
  ifdef UNICODE
    SHStartNetConnectionDialog equ <SHStartNetConnectionDialogW>
  else
    SHStartNetConnectionDialog equ <SHStartNetConnectionDialogA>
  endif
  ; !UNICODE
  @DefProto DllImport, SHDefExtractIconA, WIN_STD_CALL_CONV,, <:LPCSTR, :SDWORD, :UINT, :ptr HICON, :ptr HICON, :UINT>, 24
  @DefProto DllImport, SHDefExtractIconW, WIN_STD_CALL_CONV,, <:LPCWSTR, :SDWORD, :UINT, :ptr HICON, :ptr HICON, :UINT>, 24
  ifdef UNICODE
    SHDefExtractIcon equ <SHDefExtractIconW>
  else
    SHDefExtractIcon equ <SHDefExtractIconA>
  endif
  ; !UNICODE
  ; Elevation
  ; OpenAsInfo flags
  tagOPEN_AS_INFO_FLAGS typedef SDWORD
  OAIF_ALLOW_REGISTRATION equ 00000001h
  ; enable the "always use this file" checkbox (NOTE if you don't pass this, it will be disabled)
  OAIF_REGISTER_EXT equ 00000002h
  ; do the registration after the user hits "ok"
  OAIF_EXEC equ 00000004h
  ; execute file after registering
  OAIF_FORCE_REGISTRATION equ 00000008h
  ; force the "always use this file" checkbox to be checked (normally, you won't use the OAIF_ALLOW_REGISTRATION when you pass this)
  if (NTDDI_VERSION ge NTDDI_VISTA)
    OAIF_HIDE_REGISTRATION equ 00000020h
    ; hide the "always use this file" checkbox
    OAIF_URL_PROTOCOL equ 00000040h
    ; the "extension" passed is actually a protocol (uri scheme), and open with should show apps registered as capable of handling that protocol
  endif
  if (NTDDI_VERSION ge NTDDI_WIN8)
    OAIF_FILE_IS_URI equ 00000080h
    ; pcszFile is actually a URI
  endif

  OPEN_AS_INFO_FLAGS typedef SDWORD
  include pshpack8.inc
  OPENASINFO struct
    pcszFile =POINTER ?
    ; [in] file name, or protocol name if
    ;      OAIF_URL_PROTOCOL is set.
    pcszClass =POINTER ?
    ; [in] file class description. NULL means
    ;      use pcszFile's extension. ignored
    ;      if OAIF_URL_PROTOCOL is set.
    oaifInFlags OPEN_AS_INFO_FLAGS ?
    ; [in] input flags from OPEN_AS_INFO_FLAGS enumeration
  OPENASINFO ends
  _openasinfo typedef OPENASINFO
  POPENASINFO typedef ptr OPENASINFO
  ;* Return to byte packing *
  include poppack.inc
  if (NTDDI_VERSION ge NTDDI_VISTA)
    @DefProto DllImport, SHOpenWithDialog, WIN_STD_CALL_CONV,, <:HWND, :ptr OPENASINFO>, 8
  endif
  ; NTDDI_VISTA
  @DefProto DllImport, Shell_GetImageLists, WIN_STD_CALL_CONV,, <:ptr HIMAGELIST, :ptr HIMAGELIST>, 8
  @DefProto DllImport, Shell_GetCachedImageIndex, WIN_STD_CALL_CONV,, <:PCWSTR, :SDWORD, :UINT>, 12
  if (NTDDI_VERSION ge NTDDI_VISTA)
    @DefProto DllImport, Shell_GetCachedImageIndexA, WIN_STD_CALL_CONV,, <:LPCSTR, :SDWORD, :UINT>, 12
    @DefProto DllImport, Shell_GetCachedImageIndexW, WIN_STD_CALL_CONV,, <:LPCWSTR, :SDWORD, :UINT>, 12
    ifdef UNICODE
      Shell_GetCachedImageIndex equ <Shell_GetCachedImageIndexW>
    else
      Shell_GetCachedImageIndex equ <Shell_GetCachedImageIndexA>
    endif
    ; !UNICODE
  endif
  ; NTDDI_VISTA
  VALIDATEUNC_CONNECT equ 0001h; connect a drive letter

  VALIDATEUNC_NOUI equ 0002h; don't bring up UI

  VALIDATEUNC_PRINT equ 0004h; validate as print share instead of disk share

  if (NTDDI_VERSION ge NTDDI_VISTA)
    VALIDATEUNC_PERSIST equ 0008h; the connection should be made persistent

    VALIDATEUNC_VALID equ 000Fh; valid flags

  else
    VALIDATEUNC_VALID equ 0007h; valid flags

  endif
  @DefProto DllImport, SHValidateUNC, WIN_STD_CALL_CONV,, <:HWND, :PWSTR, :UINT>, 12
  PIFNAMESIZE equ 30
  PIFSTARTLOCSIZE equ 63
  PIFDEFPATHSIZE equ 64
  PIFPARAMSSIZE equ 64
  PIFSHPROGSIZE equ 64
  PIFSHDATASIZE equ 64
  PIFDEFFILESIZE equ 80
  PIFMAXFILEPATH equ 260
  ;* prg *
  PROPPRG struct
    flPrg WORD ?
    ; see PRG_ flags
    flPrgInit WORD ?
    ; see PRGINIT_ flags
    achTitle SBYTE PIFNAMESIZE dup (?)
    ; name[30]
    achCmdLine SBYTE PIFSTARTLOCSIZE + PIFPARAMSSIZE + 1 dup (?)
    ; startfile[63] + params[64]
    achWorkDir SBYTE PIFDEFPATHSIZE dup (?)
    ; defpath[64]
    wHotKey WORD ?
    ; PfHotKeyScan thru PfHotKeyVal
    achIconFile SBYTE PIFDEFFILESIZE dup (?)
    ; name of file containing icon
    wIconIndex WORD ?
    ; index of icon within file
    dwEnhModeFlags DWORD ?
    ; reserved enh-mode flags
    dwRealModeFlags DWORD ?
    ; real-mode flags (see RMOPT_*)
    achOtherFile SBYTE PIFDEFFILESIZE dup (?)
    ; name of "other" file in directory
    achPIFFile SBYTE PIFMAXFILEPATH dup (?)
    ; name of PIF file
  PROPPRG ends
  PPROPPRG typedef ptr PROPPRG
  LPPROPPRG typedef ptr PROPPRG
  LPCPROPPRG typedef ptr PROPPRG
  @DefProto DllImport, PifMgr_OpenProperties, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR, :UINT, :UINT>, 16
  @DefProto DllImport, PifMgr_GetProperties, WIN_STD_CALL_CONV,, <:HANDLE, :PCSTR, :ptr, :SDWORD, :UINT>, 20
  @DefProto DllImport, PifMgr_SetProperties, WIN_STD_CALL_CONV,, <:HANDLE, :PCSTR, :ptr, :SDWORD, :UINT>, 20
  @DefProto DllImport, PifMgr_CloseProperties, WIN_STD_CALL_CONV,, <:HANDLE, :UINT>, 8
  @DefProto DllImport, SHSetInstanceExplorer, WIN_STD_CALL_CONV,, <:ptr IUnknown>, 4
  @DefProto DllImport, IsUserAnAdmin, WIN_STD_CALL_CONV,, <>, 0
  @DefProto DllImport, SHShellFolderView_Message, WIN_STD_CALL_CONV,, <:HWND, :UINT, :LPARAM>, 12
  ; Callback interface for the IShellView object returned from SHCreateShellFolderView.
  INTERFACE equ <IShellFolderViewCB>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(IShellFolderViewCB, IUnknown, "2047E320-F2A9-11CE-AE65-08002B2E1262")
    STDMETHOD MessageSFVCB, :DWORD, :WPARAM, :LPARAM
  DECLARE_INTERFACE_IID__END

  include pshpack8.inc
  QCMINFO_PLACE_BEFORE equ 0
  QCMINFO_PLACE_AFTER equ 1
  QCMINFO_IDMAP_PLACEMENT struct
    id DWORD ?
    fFlags DWORD ?
  QCMINFO_IDMAP_PLACEMENT ends
  _QCMINFO_IDMAP_PLACEMENT typedef QCMINFO_IDMAP_PLACEMENT
  QCMINFO_IDMAP struct
    nMaxIds DWORD ?
    pIdList QCMINFO_IDMAP_PLACEMENT 1 dup (<>)
  QCMINFO_IDMAP ends
  _QCMINFO_IDMAP typedef QCMINFO_IDMAP
  QCMINFO struct
    hmenu HMENU ?
    ; in
    indexMenu DWORD ?
    ; in
    idCmdFirst DWORD ?
    ; in/out
    idCmdLast DWORD ?
    ; in
    pIdMap POINTER ?
    ; in / unused
  QCMINFO ends
  _QCMINFO typedef QCMINFO
  LPQCMINFO typedef ptr QCMINFO
  DETAILSINFO struct
    pidl PCUITEMID_CHILD ?
    fmt SDWORD ?
    cxChar SDWORD ?
    str_ STRRET <>
    iImage SDWORD ?
  DETAILSINFO ends
  _DETAILSINFO typedef DETAILSINFO
  PDETAILSINFO typedef ptr DETAILSINFO
  SFVM_PROPPAGE_DATA struct
    dwReserved DWORD ?
    pfn LPFNADDPROPSHEETPAGE ?
    lParam LPARAM ?
  SFVM_PROPPAGE_DATA ends
  _SFVM_PROPPAGE_DATA typedef SFVM_PROPPAGE_DATA
  SFVM_HELPTOPIC_DATA struct
    wszHelpFile WORD MAX_PATH dup (?)
    wszHelpTopic WORD MAX_PATH dup (?)
  SFVM_HELPTOPIC_DATA ends
  _SFVM_HELPTOPIC_DATA typedef SFVM_HELPTOPIC_DATA
  ;                                 uMsg    wParam             lParam
  SFVM_MERGEMENU equ 1; -                  LPQCMINFO

  SFVM_INVOKECOMMAND equ 2; idCmd              -

  SFVM_GETHELPTEXT equ 3; idCmd,cchMax       pszText

  SFVM_GETTOOLTIPTEXT equ 4; idCmd,cchMax       pszText

  SFVM_GETBUTTONINFO equ 5; -                  LPTBINFO

  SFVM_GETBUTTONS equ 6; idCmdFirst,cbtnMax LPTBBUTTON

  SFVM_INITMENUPOPUP equ 7; idCmdFirst,nIndex  hmenu

  SFVM_FSNOTIFY equ 14; LPCITEMIDLIST*     lEvent

  SFVM_WINDOWCREATED equ 15; hwnd               -

  SFVM_GETDETAILSOF equ 23; iColumn            DETAILSINFO*

  SFVM_COLUMNCLICK equ 24; iColumn            -

  SFVM_QUERYFSNOTIFY equ 25; -                  SHChangeNotifyEntry *

  SFVM_DEFITEMCOUNT equ 26; -                  UINT*

  SFVM_DEFVIEWMODE equ 27; -                  FOLDERVIEWMODE*

  SFVM_UNMERGEMENU equ 28; -                  hmenu

  SFVM_UPDATESTATUSBAR equ 31; fInitialize        -

  SFVM_BACKGROUNDENUM equ 32; -                  -

  SFVM_DIDDRAGDROP equ 36; dwEffect           IDataObject *

  SFVM_SETISFV equ 39; -                  IShellFolderView*

  SFVM_THISIDLIST equ 41; -                  LPITMIDLIST*

  SFVM_ADDPROPERTYPAGES equ 47; -                  SFVM_PROPPAGE_DATA *

  SFVM_BACKGROUNDENUMDONE equ 48; -                  -

  SFVM_GETNOTIFY equ 49; LPITEMIDLIST*      LONG*

  SFVM_GETSORTDEFAULTS equ 53; iDirection         iParamSort

  SFVM_SIZE equ 57; -                  -

  SFVM_GETZONE equ 58; -                  DWORD*

  SFVM_GETPANE equ 59; Pane ID            DWORD*

  SFVM_GETHELPTOPIC equ 63; -                  SFVM_HELPTOPIC_DATA *

  SFVM_GETANIMATION equ 68; HINSTANCE *        WCHAR *

  ; IShellFolderView
  ; Deprecated: use IFolderView and IFolderView2 instead.
  ; IShellFolderView is supported by the IShellView object returned from SHCreateShellFolderView.
  ; Warnings:
  ;  - Some methods on this interface do not follow standard COM rules.
  ;  - Some methods can be used to configure the IShellView or cause it to behave incorrectly.
  ;  - Few of these methods have parameter or range validation, so callers can cause the IShellView to fault.
  ITEMSPACING struct
    cxSmall SDWORD ?
    cySmall SDWORD ?
    cxLarge SDWORD ?
    cyLarge SDWORD ?
  ITEMSPACING ends
  _ITEMSPACING typedef ITEMSPACING
  ; defines for IShellFolderView::SetObjectCount
  SFVSOC_INVALIDATE_ALL equ 00000001h; Assumed to reset only what is neccessary...

  SFVSOC_NOSCROLL equ <LVSICF_NOSCROLL>
  ; defines for IShellFolderView::SelectItems()
  SFVS_SELECT_NONE equ 0h; unselect all

  SFVS_SELECT_ALLITEMS equ 1h; select all

  SFVS_SELECT_INVERT equ 2h; Invert the selection

  INTERFACE equ <IShellFolderView>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(IShellFolderView, IUnknown, "37A378C0-F82D-11CE-AE65-08002B2E1262")
    STDMETHOD Rearrange, :LPARAM
    ; use IFolderView2::SetSortColumns
    STDMETHOD GetArrangeParam, :ptr LPARAM
    ; use IFolderView2::GetSortColumns
    STDMETHOD ArrangeGrid
    ; select Arrange by Grid
    STDMETHOD AutoArrange
    ; select Auto Arrange
    STDMETHOD GetAutoArrange
    ; use IFolderView::GetAutoArrange
    STDMETHOD AddObject, :PUITEMID_CHILD, :ptr DWORD
    ; items added here may disappear (the data source is the final arbiter of which items are available to the view)
    STDMETHOD GetObject, :ptr PITEMID_CHILD, :DWORD
    ; use IFolderView::Item
    STDMETHOD RemoveObject, :PUITEMID_CHILD, :ptr DWORD
    ; items removed here may reappear (the data source is the final arbiter of which items are available to the view)
    STDMETHOD GetObjectCount, :ptr DWORD
    ; use IFolderView::ItemCount
    STDMETHOD SetObjectCount, :DWORD, :DWORD
    ; not implemented on Vista.  Sends LVM_SETITEMCOUNT with WPARAM=uCount and LPARAM=dwFlags to listview on XP.
    STDMETHOD UpdateObject, :PUITEMID_CHILD, :PUITEMID_CHILD, :ptr DWORD
    ; swaps ITEMID_CHILDs, returning new index.  Changes may be discarded (the data source is the final arbiter of which items are available to the view)
    STDMETHOD RefreshObject, :PUITEMID_CHILD, :ptr DWORD
    ; tickles the listview to re-draw the item
    STDMETHOD SetRedraw, :DWORD
    ; sends WM_SETREDRAW to the listview
    STDMETHOD GetSelectedCount, :ptr DWORD
    ; use IFolderView2::GetSelection
    ; NOTE: GetSelectedObjects hands out const pointers to internal ITEMID_CHILD structures. The caller is expected to act on them immediately (and not cache them).  LocalFree the array, but not the items it contains.
    STDMETHOD GetSelectedObjects, :ptr ptr PCUITEMID_CHILD, :ptr DWORD
    ; use IFolderView2::GetSelection.
    STDMETHOD IsDropOnSource, :ptr IDropTarget
    ; use IFolderView2::IsMoveInSameFolder
    STDMETHOD GetDragPoint, :ptr POINT
    ; returns point corresponding to drag-and-drop operation
    STDMETHOD GetDropPoint, :ptr POINT
    ; returns point corresponding to drag-and-drop operation
    STDMETHOD MoveIcons, :ptr IDataObject
    ; not implemented
    STDMETHOD SetItemPos, :PCUITEMID_CHILD, :ptr POINT
    ; use IFolderView::SelectAndPositionItems
    STDMETHOD IsBkDropTarget, :ptr IDropTarget
    ; returns S_OK if drag-and-drop is on the background, S_FALSE otherwise
    STDMETHOD SetClipboard, :DWORD
    ; if bMove is TRUE, this attempts to cut (edit.cut, ctrl-x) the current selection.  bMove of FALSE is not supported.
    STDMETHOD SetPoints, :ptr IDataObject
    ; copies points of current selection in to data object.  Call is not needed if drag operation was originated by the IShellView.
    STDMETHOD GetItemSpacing, :ptr ITEMSPACING
    ; use IFolderView::GetSpacing instead.  GetItemSpacing returns the spacing for small and large view modes only, returning S_OK if the current view mode is is positionable, S_FALSE otherwise.
    STDMETHOD SetCallback, :ptr IShellFolderViewCB, :ptr ptr IShellFolderViewCB
    ; replace the IShellFolderViewCB that the IShellView uses
    STDMETHOD Select, :DWORD
    ; SFVS_ select flags: select all, select none, invert selection
    STDMETHOD QuerySupport, :ptr DWORD
    ; does nothing, returns S_OK.
    STDMETHOD SetAutomationObject, :ptr IDispatch
    ; replaces the IShellView's internal automation object.
  DECLARE_INTERFACE_IID__END

  ; SHCreateShellFolderView struct
  SFV_CREATE struct
    cbSize DWORD ?
    ; must be sizeof(SFV_CREATE)
    pshf POINTER ?
    ; IShellFolder the IShellView will use
    psvOuter POINTER ?
    ; optional: IShellView to pass to psfvcb
    psfvcb POINTER ?
    ; No callback if NULL
  SFV_CREATE ends
  _SFV_CREATE typedef SFV_CREATE
  @DefProto DllImport, SHCreateShellFolderView, WIN_STD_CALL_CONV,, <:ptr SFV_CREATE, :ptr ptr IShellView>, 8
  TYPE_LPFNDFMCALLBACK typedef proto WIN_STD_CALL_CONV :ptr IShellFolder, :HWND, :ptr IDataObject, :UINT, :WPARAM, :LPARAM
  LPFNDFMCALLBACK typedef ptr TYPE_LPFNDFMCALLBACK

  @DefProto DllImport, CDefFolderMenu_Create2, WIN_STD_CALL_CONV,, <:PCIDLIST_ABSOLUTE, :HWND, :UINT, :PCUITEMID_CHILD_ARRAY, :ptr IShellFolder, :LPFNDFMCALLBACK, :UINT, :ptr HKEY, :ptr ptr IContextMenu>, 36
  DEFCONTEXTMENU struct
    hwnd HWND ?
    pcmcb POINTER ?
    ; optional: callback object
    pidlFolder PCIDLIST_ABSOLUTE ?
    ; optional: IDList to folder of the items, computed from psf if NULL
    psf POINTER ?
    ; folder of the items
    cidl DWORD ?
    ; # of items in apidl
    apidl PCUITEMID_CHILD_ARRAY ?
    ; items operating on, used to get IDataObject and IAssociationArray
    punkAssociationInfo POINTER ?
    ; optional: IQueryAssociations, specifies where to load extensions from, computed from apidl if NULL
    cKeys DWORD ?
    ; # of items in aKeys, may be zero
    aKeys POINTER ?
    ; optional: specifies where to load extensions from
  DEFCONTEXTMENU ends
  ; creates object that implements IContextMenu/IContextMenu2/IContextMenu3, typically
  ; used in the implemetnation of ::GetUIObjectOf()
  if (NTDDI_VERSION ge NTDDI_VISTA)
    @DefProto DllImport, SHCreateDefaultContextMenu, WIN_STD_CALL_CONV,, <:ptr DEFCONTEXTMENU, :REFIID, :ptr ptr>, 12
  endif
  ; NTDDI_VISTA
  ; structure for lParam of DFM_INFOKECOMMANDEX
  DFMICS struct
    cbSize DWORD ?
    fMask DWORD ?
    ; CMIC_MASK_ values for the invoke
    lParam LPARAM ?
    ; same as lParam of DFM_INFOKECOMMAND
    idCmdFirst DWORD ?
    idDefMax DWORD ?
    pici LPCMINVOKECOMMANDINFO ?
    ; the whole thing so you can re-invoke on a child
    if (NTDDI_VERSION ge NTDDI_VISTA)
      punkSite POINTER ?
      ; site pointer for context menu handler
    endif
  DFMICS ends
  PDFMICS typedef ptr DFMICS
  ; Note on context menus ranges:
  ;  Standard Items // DFM_MERGECONTEXTMENU, context menu extensions, DFM_MERGECONTEXTMENU_TOP
  ;  Separator
  ;  View Items   // context menu extensions can get here
  ;  Separator
  ;  (defcm S_FALSE "default" items, if applicable)
  ;  Separator
  ;  Folder Items // context menu extensions can get here
  ;  Separator
  ;  Bottom Items // DFM_MERGECONTEXTMENU_BOTTOM
  ;                                  uMsg       wParam       lParam
  DFM_MERGECONTEXTMENU equ 1; uFlags       LPQCMINFO

  DFM_INVOKECOMMAND equ 2; idCmd        pszArgs

  DFM_GETHELPTEXT equ 5; idCmd,cchMax pszText -Ansi

  DFM_WM_MEASUREITEM equ 6; ---from the message---

  DFM_WM_DRAWITEM equ 7; ---from the message---

  DFM_WM_INITMENUPOPUP equ 8; ---from the message---

  DFM_VALIDATECMD equ 9; idCmd        0

  DFM_MERGECONTEXTMENU_TOP equ 10; uFlags       LPQCMINFO

  DFM_GETHELPTEXTW equ 11; idCmd,cchMax pszText -Unicode

  DFM_INVOKECOMMANDEX equ 12; idCmd        PDFMICS

  DFM_MAPCOMMANDNAME equ 13; idCmd *      pszCommandName

  DFM_GETDEFSTATICID equ 14; idCmd *      0

  DFM_GETVERBW equ 15; idCmd,cchMax pszText -Unicode

  DFM_GETVERBA equ 16; idCmd,cchMax pszText -Ansi

  DFM_MERGECONTEXTMENU_BOTTOM equ 17; uFlags       LPQCMINFO

  DFM_MODIFYQCMFLAGS equ 18; uFlags       UINT *puNewFlags;   modify the CFM_XXX values passed to IContextMenu::QueryContextMenu

  ; Commands from DFM_INVOKECOMMAND when strings are passed in
  DFM_CMD_DELETE equ (- 1)
  DFM_CMD_MOVE equ (- 2)
  DFM_CMD_COPY equ (- 3)
  DFM_CMD_LINK equ (- 4)
  DFM_CMD_PROPERTIES equ (- 5)
  DFM_CMD_NEWFOLDER equ (- 6)
  DFM_CMD_PASTE equ (- 7)
  DFM_CMD_VIEWLIST equ (- 8)
  DFM_CMD_VIEWDETAILS equ (- 9)
  DFM_CMD_PASTELINK equ (- 10)
  DFM_CMD_PASTESPECIAL equ (- 11)
  DFM_CMD_MODALPROP equ (- 12)
  DFM_CMD_RENAME equ (- 13)
  TYPE_LPFNVIEWCALLBACK typedef proto WIN_STD_CALL_CONV :ptr IShellView, :ptr IShellFolder, :HWND, :UINT, :WPARAM, :LPARAM
  LPFNVIEWCALLBACK typedef ptr TYPE_LPFNVIEWCALLBACK

  ; SHCreateShellFolderViewEx struct
  CSFV struct
    cbSize DWORD ?
    pshf POINTER ?
    psvOuter POINTER ?
    pidl PCIDLIST_ABSOLUTE ?
    lEvents SDWORD ?
    pfnCallback LPFNVIEWCALLBACK ?
    ; No callback if NULL
    fvm FOLDERVIEWMODE ?
  CSFV ends
  _CSFV typedef CSFV
  LPCSFV typedef ptr CSFV
  ;* Return to byte packing *
  include poppack.inc
  @DefProto DllImport, SHFind_InitMenuPopup, WIN_STD_CALL_CONV,, <:HMENU, :HWND, :UINT, :UINT>, 16
  @DefProto DllImport, SHCreateShellFolderViewEx, WIN_STD_CALL_CONV,, <:ptr CSFV, :ptr ptr IShellView>, 8
  ; Legacy PROPIDs for Internet Shortcuts (FMTID_Intshcut) to be used with
  ; IPropertySetStorage/IPropertyStorage.
  ; The known property ids and their variant types are:
  ;      PID_IS_URL          [VT_LPWSTR]   URL
  ;      PID_IS_NAME         [VT_LPWSTR]   Name of the internet shortcut
  ;      PID_IS_WORKINGDIR   [VT_LPWSTR]   Working directory for the shortcut
  ;      PID_IS_HOTKEY       [VT_UI2]      Hotkey for the shortcut
  ;      PID_IS_SHOWCMD      [VT_I4]       Show command for shortcut
  ;      PID_IS_ICONINDEX    [VT_I4]       Index into file that has icon
  ;      PID_IS_ICONFILE     [VT_LPWSTR]   File that has the icon
  ;      PID_IS_WHATSNEW     [VT_LPWSTR]   What's New text
  ;      PID_IS_AUTHOR       [VT_LPWSTR]   Author
  ;      PID_IS_DESCRIPTION  [VT_LPWSTR]   Description text of site
  ;      PID_IS_COMMENT      [VT_LPWSTR]   User annotated comment
  PID_IS_URL equ 2
  PID_IS_NAME equ 4
  PID_IS_WORKINGDIR equ 5
  PID_IS_HOTKEY equ 6
  PID_IS_SHOWCMD equ 7
  PID_IS_ICONINDEX equ 8
  PID_IS_ICONFILE equ 9
  PID_IS_WHATSNEW equ 10
  PID_IS_AUTHOR equ 11
  PID_IS_DESCRIPTION equ 12
  PID_IS_COMMENT equ 13
  PID_IS_ROAMED equ 15
  ; PROPIDs for Internet Sites (FMTID_InternetSite) to be used with
  ; IPropertySetStorage/IPropertyStorage
  ; The known property ids and their variant types are:
  ;      PID_INTSITE_WHATSNEW     [VT_LPWSTR]   What's New text
  ;      PID_INTSITE_AUTHOR       [VT_LPWSTR]   Author
  ;      PID_INTSITE_LASTVISIT    [VT_FILETIME] Time site was last visited
  ;      PID_INTSITE_LASTMOD      [VT_FILETIME] Time site was last modified
  ;      PID_INTSITE_VISITCOUNT   [VT_UI4]      Number of times user has visited
  ;      PID_INTSITE_DESCRIPTION  [VT_LPWSTR]   Description text of site
  ;      PID_INTSITE_COMMENT      [VT_LPWSTR]   User annotated comment
  ;      PID_INTSITE_RECURSE      [VT_UI4]      Levels to recurse (0-3)
  ;      PID_INTSITE_WATCH        [VT_UI4]      PIDISM_ flags
  ;      PID_INTSITE_SUBSCRIPTION [VT_UI8]      Subscription cookie
  ;      PID_INTSITE_URL          [VT_LPWSTR]   URL
  ;      PID_INTSITE_TITLE        [VT_LPWSTR]   Title
  ;      PID_INTSITE_CODEPAGE     [VT_UI4]      Codepage of the document
  ;      PID_INTSITE_TRACKING     [VT_UI4]      Tracking
  ;      PID_INTSITE_ICONINDEX    [VT_I4]       Retrieve the index to the icon
  ;      PID_INTSITE_ICONFILE     [VT_LPWSTR]   Retrieve the file containing the icon index.
  ;      PID_INTSITE_RAWURL       [VT_LPWSTR]   The raw, un-encoded, unicode url.
  ;      PID_INTSITE_ROAMED       [VT_UI4]      Indicates that this entry was roamed from a different machine
  PID_INTSITE_WHATSNEW equ 2
  PID_INTSITE_AUTHOR equ 3
  PID_INTSITE_LASTVISIT equ 4
  PID_INTSITE_LASTMOD equ 5
  PID_INTSITE_VISITCOUNT equ 6
  PID_INTSITE_DESCRIPTION equ 7
  PID_INTSITE_COMMENT equ 8
  PID_INTSITE_FLAGS equ 9
  PID_INTSITE_CONTENTLEN equ 10
  PID_INTSITE_CONTENTCODE equ 11
  PID_INTSITE_RECURSE equ 12
  PID_INTSITE_WATCH equ 13
  PID_INTSITE_SUBSCRIPTION equ 14
  PID_INTSITE_URL equ 15
  PID_INTSITE_TITLE equ 16
  PID_INTSITE_CODEPAGE equ 18
  PID_INTSITE_TRACKING equ 19
  PID_INTSITE_ICONINDEX equ 20
  PID_INTSITE_ICONFILE equ 21
  PID_INTSITE_ROAMED equ 34
  ; Flags for PID_IS_FLAGS
  PIDISF_RECENTLYCHANGED equ 00000001h
  PIDISF_CACHEDSTICKY equ 00000002h
  PIDISF_CACHEIMAGES equ 00000010h
  PIDISF_FOLLOWALLLINKS equ 00000020h
  ; Values for PID_INTSITE_WATCH
  PIDISM_GLOBAL equ 0; Monitor based on global setting

  PIDISM_WATCH equ 1; User says watch

  PIDISM_DONTWATCH equ 2; User says don't watch

  ; Values for PID_INTSITE_ROAMED
  PIDISR_UP_TO_DATE equ 0; No action needed

  PIDISR_NEEDS_ADD equ 1; The entry was added due to roaming

  PIDISR_NEEDS_UPDATE equ 2; The entry was roamed and contains updated information

  PIDISR_NEEDS_DELETE equ 3; The entry was roamed and should be deleted

  ;//////////////////////////////////////////////////////////////////
  ; The shell keeps track of some per-user state to handle display
  ; options that is of major interest to ISVs.
  ; The key one requested right now is "DoubleClickInWebView".
  SHELLSTATEA struct
    ; No longer used, dead bit
    SHELLSTATEA_REC record SHELLSTATEA_REC_Filler:15, SHELLSTATEA_REC_fNoNetCrawling:1, SHELLSTATEA_REC_fShowSuperHidden:1, SHELLSTATEA_REC_fFilter:1, SHELLSTATEA_REC_fWebView:1, SHELLSTATEA_REC_fHideIcons:1, SHELLSTATEA_REC_fShowInfoTip:1, SHELLSTATEA_REC_fMapNetDrvBtn:1, SHELLSTATEA_REC_fShowAttribCol:1, SHELLSTATEA_REC_fDontPrettyPath:1, SHELLSTATEA_REC_fWin95Classic:1, SHELLSTATEA_REC_fDesktopHTML:1, SHELLSTATEA_REC_fDoubleClickInWebView:1, SHELLSTATEA_REC_fShowCompColor:1, SHELLSTATEA_REC_fShowSysFiles:1, SHELLSTATEA_REC_fNoConfirmRecycle:1, SHELLSTATEA_REC_fShowExtensions:1, SHELLSTATEA_REC_fShowAllObjects:1
    SHELLSTATEA_BITS SHELLSTATEA_REC <>
    dwWin95Unused DWORD ?
    ; Win95 only - no longer supported pszHiddenFileExts
    uWin95Unused DWORD ?
    ; Win95 only - no longer supported cbHiddenFileExts
    ; Note: Not a typo!  This is a persisted structure so we cannot use LPARAM
    lParamSort SDWORD ?
    iSortDirection SDWORD ?
    version DWORD ?
    ; new for win2k. need notUsed var to calc the right size of ie4 struct
    ; FIELD_OFFSET does not work on bit fields
    uNotUsed DWORD ?
    ; feel free to rename and use
    ; new for Whistler.
    ;Indicates if the Whistler StartPanel mode is ON or OFF.
    ;Indicates if the Whistler StartPage on desktop is ON or OFF.
    ; new for Windows Vista
    ; new for Windows 8
    SHELLSTATEA_REC record SHELLSTATEA_REC_Filler:16, SHELLSTATEA_REC_fSpareFlags:9, SHELLSTATEA_REC_fShowStatusBar:1, SHELLSTATEA_REC_fShowTypeOverlay:1, SHELLSTATEA_REC_fIconsOnly:1, SHELLSTATEA_REC_fAutoCheckSelect:1, SHELLSTATEA_REC_fShowStartPage:1, SHELLSTATEA_REC_fStartPanelOn:1, SHELLSTATEA_REC_fSepProcess:1
    SHELLSTATEA_BITS SHELLSTATEA_REC <>
  SHELLSTATEA ends
  LPSHELLSTATEA typedef ptr SHELLSTATEA
  SHELLSTATEW struct
    ; No longer used, dead bit
    SHELLSTATEW_REC record SHELLSTATEW_REC_Filler:15, SHELLSTATEW_REC_fNoNetCrawling:1, SHELLSTATEW_REC_fShowSuperHidden:1, SHELLSTATEW_REC_fFilter:1, SHELLSTATEW_REC_fWebView:1, SHELLSTATEW_REC_fHideIcons:1, SHELLSTATEW_REC_fShowInfoTip:1, SHELLSTATEW_REC_fMapNetDrvBtn:1, SHELLSTATEW_REC_fShowAttribCol:1, SHELLSTATEW_REC_fDontPrettyPath:1, SHELLSTATEW_REC_fWin95Classic:1, SHELLSTATEW_REC_fDesktopHTML:1, SHELLSTATEW_REC_fDoubleClickInWebView:1, SHELLSTATEW_REC_fShowCompColor:1, SHELLSTATEW_REC_fShowSysFiles:1, SHELLSTATEW_REC_fNoConfirmRecycle:1, SHELLSTATEW_REC_fShowExtensions:1, SHELLSTATEW_REC_fShowAllObjects:1
    SHELLSTATEW_BITS SHELLSTATEW_REC <>
    dwWin95Unused DWORD ?
    ; Win95 only - no longer supported pszHiddenFileExts
    uWin95Unused DWORD ?
    ; Win95 only - no longer supported cbHiddenFileExts
    ; Note: Not a typo!  This is a persisted structure so we cannot use LPARAM
    lParamSort SDWORD ?
    iSortDirection SDWORD ?
    version DWORD ?
    ; new for win2k. need notUsed var to calc the right size of ie4 struct
    ; FIELD_OFFSET does not work on bit fields
    uNotUsed DWORD ?
    ; feel free to rename and use
    ; new for Whistler.
    ;Indicates if the Whistler StartPanel mode is ON or OFF.
    ;Indicates if the Whistler StartPage on desktop is ON or OFF.
    ; new for Windows Vista
    ; new for Windows 8
    SHELLSTATEW_REC record SHELLSTATEW_REC_Filler:16, SHELLSTATEW_REC_fSpareFlags:9, SHELLSTATEW_REC_fShowStatusBar:1, SHELLSTATEW_REC_fShowTypeOverlay:1, SHELLSTATEW_REC_fIconsOnly:1, SHELLSTATEW_REC_fAutoCheckSelect:1, SHELLSTATEW_REC_fShowStartPage:1, SHELLSTATEW_REC_fStartPanelOn:1, SHELLSTATEW_REC_fSepProcess:1
    SHELLSTATEW_BITS SHELLSTATEW_REC <>
  SHELLSTATEW ends
  LPSHELLSTATEW typedef ptr SHELLSTATEW
  SHELLSTATEVERSION_IE4 equ 9
  SHELLSTATEVERSION_WIN2K equ 10
  ifdef UNICODE
    SHELLSTATE equ <SHELLSTATEW>
    LPSHELLSTATE equ <LPSHELLSTATEW>
  else
    SHELLSTATE equ <SHELLSTATEA>
    LPSHELLSTATE equ <LPSHELLSTATEA>
  endif
  SHELLSTATE_SIZE_WIN95 equ <FIELD_OFFSET (SHELLSTATE, lParamSort)>
  SHELLSTATE_SIZE_NT4 equ <FIELD_OFFSET (SHELLSTATE, version)>
  SHELLSTATE_SIZE_IE4 equ <FIELD_OFFSET (SHELLSTATE, uNotUsed)>
  SHELLSTATE_SIZE_WIN2K equ <sizeof(SHELLSTATE)>
  @DefProto DllImport, SHGetSetSettings, WIN_STD_CALL_CONV,, <:LPSHELLSTATE, :DWORD, :BOOL>, 12
  ;  SysFiles are these windows special files:
  ;      "dll sys vxd 386 drv"
  ;  hidden files are files with the FILE_ATTRIBUTE_HIDDEN attribute
  ;  system files are files with the FILE_ATTRIBUTE_SYSTEM attribute
  ;      fShowAllObjects fShowSysFiles   Result
  ;      --------------- -------------   ------
  ;      0               0               hide hidden + SysFiles + system files
  ;      0               1               hide hidden files.
  ;      1               0               show all files.
  ;      1               1               show all files.
  SHELLFLAGSTATE struct
    SHELLFLAGSTATE_REC record SHELLFLAGSTATE_REC_Filler:19, SHELLFLAGSTATE_REC_fHideIcons:1, SHELLFLAGSTATE_REC_fShowInfoTip:1, SHELLFLAGSTATE_REC_fMapNetDrvBtn:1, SHELLFLAGSTATE_REC_fShowAttribCol:1, SHELLFLAGSTATE_REC_fDontPrettyPath:1, SHELLFLAGSTATE_REC_fWin95Classic:1, SHELLFLAGSTATE_REC_fDesktopHTML:1, SHELLFLAGSTATE_REC_fDoubleClickInWebView:1, SHELLFLAGSTATE_REC_fShowCompColor:1, SHELLFLAGSTATE_REC_fShowSysFiles:1, SHELLFLAGSTATE_REC_fNoConfirmRecycle:1, SHELLFLAGSTATE_REC_fShowExtensions:1, SHELLFLAGSTATE_REC_fShowAllObjects:1
    SHELLFLAGSTATE_BITS SHELLFLAGSTATE_REC <>
    if (NTDDI_VERSION ge NTDDI_VISTA)
      SHELLFLAGSTATE_REC record SHELLFLAGSTATE_REC_Filler:29, SHELLFLAGSTATE_REC_fRestFlags:1, SHELLFLAGSTATE_REC_fIconsOnly:1, SHELLFLAGSTATE_REC_fAutoCheckSelect:1
      SHELLFLAGSTATE_BITS SHELLFLAGSTATE_REC <>
      ; when adding additional flags keep SHELLSTATE and SHGetSettings in sync.
    else
      SHELLFLAGSTATE_REC record SHELLFLAGSTATE_REC_Filler:29, SHELLFLAGSTATE_REC_fRestFlags:3
      SHELLFLAGSTATE_BITS SHELLFLAGSTATE_REC <>
      ; when adding additional flags keep SHELLSTATE and SHGetSettings in sync.
    endif
  SHELLFLAGSTATE ends
  LPSHELLFLAGSTATE typedef ptr SHELLFLAGSTATE
  SSF_SHOWALLOBJECTS equ 00000001h
  SSF_SHOWEXTENSIONS equ 00000002h
  SSF_HIDDENFILEEXTS equ 00000004h
  SSF_SERVERADMINUI equ 00000004h
  SSF_SHOWCOMPCOLOR equ 00000008h
  SSF_SORTCOLUMNS equ 00000010h
  SSF_SHOWSYSFILES equ 00000020h
  SSF_DOUBLECLICKINWEBVIEW equ 00000080h
  SSF_SHOWATTRIBCOL equ 00000100h
  SSF_DESKTOPHTML equ 00000200h
  SSF_WIN95CLASSIC equ 00000400h
  SSF_DONTPRETTYPATH equ 00000800h
  SSF_SHOWINFOTIP equ 00002000h
  SSF_MAPNETDRVBUTTON equ 00001000h
  SSF_NOCONFIRMRECYCLE equ 00008000h
  SSF_HIDEICONS equ 00004000h
  SSF_FILTER equ 00010000h
  SSF_WEBVIEW equ 00020000h
  SSF_SHOWSUPERHIDDEN equ 00040000h
  SSF_SEPPROCESS equ 00080000h
  if (NTDDI_VERSION ge NTDDI_WINXP)
    SSF_NONETCRAWLING equ 00100000h
    SSF_STARTPANELON equ 00200000h
    SSF_SHOWSTARTPAGE equ 00400000h
  endif
  ; NTDDI_WINXP
  if (NTDDI_VERSION ge NTDDI_VISTA)
    SSF_AUTOCHECKSELECT equ 00800000h
    SSF_ICONSONLY equ 01000000h
    SSF_SHOWTYPEOVERLAY equ 02000000h
  endif
  ; NTDDI_VISTA
  if (NTDDI_VERSION ge NTDDI_WIN8)
    SSF_SHOWSTATUSBAR equ 04000000h
  endif
  ; NTDDI_VISTA
  ; Specify the bits you are interested in in dwMask and they will be
  ; filled out in the lpss structure.
  ; When these settings change, a WM_SETTINGCHANGE message is sent
  ; with the string lParam value of "ShellState".
  @DefProto DllImport, SHGetSettings, WIN_STD_CALL_CONV,, <:ptr SHELLFLAGSTATE, :DWORD>, 8
  ; Given a pidl, you can get an interface pointer (as specified by riid) of the pidl's parent folder (in ppv)
  ; If ppidlLast is non-NULL, you can also get the pidl of the last item.
  @DefProto DllImport, SHBindToParent, WIN_STD_CALL_CONV,, <:PCIDLIST_ABSOLUTE, :REFIID, :ptr ptr, :ptr PCUITEMID_CHILD>, 16
  if (NTDDI_VERSION ge NTDDI_VISTA)
    ; Same as SHBindToParent, except you also specify which root to use.
    @DefProto DllImport, SHBindToFolderIDListParent, WIN_STD_CALL_CONV,, <:ptr IShellFolder, :PCUIDLIST_RELATIVE, :REFIID, :ptr ptr, :ptr PCUITEMID_CHILD>, 20
    ; same as SHBindToFolderIDListParent but with a IBindCtx *pbc;
    @DefProto DllImport, SHBindToFolderIDListParentEx, WIN_STD_CALL_CONV,, <:ptr IShellFolder, :PCUIDLIST_RELATIVE, :ptr IBindCtx, :REFIID, :ptr ptr, :ptr PCUITEMID_CHILD>, 24
    ; helper function that gets the desktop object, then calls BindToObject on that
    @DefProto DllImport, SHBindToObject, WIN_STD_CALL_CONV,, <:ptr IShellFolder, :PCUIDLIST_RELATIVE, :ptr IBindCtx, :REFIID, :ptr ptr>, 20
  endif
  ; NTDDI_VISTA
  ; This function is used to validate that the container structure of an IDList is valid.
  ; This should be used by all code that reads an IDList from a persistence format to ensure
  ; that invalid forms do not lead to a security exploit in the code that interprets the IDList.
  ; Shell data sources are responsible for validating the private parts of the ITEMIDs.
  ; Hidden data is validated by the functions that interpret that data.
  IDListContainerIsConsistent proto WIN_STD_CALL_CONV :PCUIDLIST_RELATIVE, :UINT
  ;  test to make sure that the pidl does not overrun itself
  ;  this is for callers that un-persist pidl data, and
  ;  assumes that the caller knows the allocated size of the pidl
  ;  similar to ILGetSize(pidl) <= cbAlloc except that
  ;  it doesnt assert or throw exceptions
  ; can read pidl->mkid.cb
  ; not end of pidl and >= 2
  ; doesn't go past end of buffer
  ;  given a string it will call psfDesktop->ParseDisplayName() to try and create a pidl
  ;  if no pbc specified, it uses the preferred options for parsing.
  ;  this includes mapping file system paths to their appropriate aliased location (RegisterObjectParam(STR_PARSE_TRANSLATE_ALIASES))
  ;  psfgaoOut is optional for SFGAO attributes
  if (NTDDI_VERSION ge NTDDI_WINXP)
    @DefProto DllImport, SHParseDisplayName, WIN_STD_CALL_CONV,, <:PCWSTR, :ptr IBindCtx, :ptr PIDLIST_ABSOLUTE, :SFGAOF, :ptr SFGAOF>, 20
  endif
  ; NTDDI_WINXP
  ; This API will make its best effort to prepare the path for the caller.  This includes:
  ; 1. Prompting for the ejectable media to be re-inserted. (Floppy, CD-ROM, ZIP drive, etc.)
  ; 2. Prompting for the media to be formatted. (Floppy, hard drive, etc.)
  ; 3. Remount mapped drives if the connection was lost. (\\unc\share mapped to N: becomes disconnected)
  ; 4. If the path doesn't exist, create it.  (SHPPFW_DIRCREATE and SHPPFW_ASKDIRCREATE)
  ; 5. Display an error if the media is read only. (SHPPFW_NOWRITECHECK not set)
  ; PARAMETERS:
  ;      hwnd: Parernt window for UI.  NULL means don't display UI. OPTIONAL
  ;      punkEnableModless: Parent that will be set to modal during UI using IOleInPlaceActiveObject::EnableModeless(). OPTIONAL
  ;      pszPath: Path to verify is valid for writting.  This can be a UNC or file drive path.  The path
  ;               should only contain directories.  Pass SHPPFW_IGNOREFILENAME if the last path segment
  ;               is always filename to ignore.
  ;      dwFlags: SHPPFW_* Flags to modify behavior
  SHPPFW_NONE equ 00000000h
  SHPPFW_DEFAULT equ <SHPPFW_DIRCREATE>; May change

  SHPPFW_DIRCREATE equ 00000001h; Create the directory if it doesn't exist without asking the user.

  SHPPFW_ASKDIRCREATE equ 00000002h; Create the directory if it doesn't exist after asking the user.

  SHPPFW_IGNOREFILENAME equ 00000004h; Ignore the last item in pszPath because it's a file.  Example: pszPath="C:\DirA\DirB", only use "C:\DirA".

  SHPPFW_NOWRITECHECK equ 00000008h; Caller only needs to read from the drive, so don't check if it's READ ONLY.

  if (NTDDI_VERSION ge NTDDI_WINXP)
    SHPPFW_MEDIACHECKONLY equ 00000010h; do the retrys on the media (or net path), return errors if the file can't be found

  endif
  ; NTDDI_WINXP
  @DefProto DllImport, SHPathPrepareForWriteA, WIN_STD_CALL_CONV,, <:HWND, :ptr IUnknown, :LPCSTR, :DWORD>, 16
  @DefProto DllImport, SHPathPrepareForWriteW, WIN_STD_CALL_CONV,, <:HWND, :ptr IUnknown, :LPCWSTR, :DWORD>, 16
  ifdef UNICODE
    SHPathPrepareForWrite equ <SHPathPrepareForWriteW>
  else
    SHPathPrepareForWrite equ <SHPathPrepareForWriteA>
  endif
  ; !UNICODE
  ;--------------------------------------------------------------------------
  ; Interface used for exposing the INI file methods on a shortcut file
  ;--------------------------------------------------------------------------
  INTERFACE equ <INamedPropertyBag>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(INamedPropertyBag, IUnknown, "FB700430-952C-11d1-946F-000000000000")
    STDMETHOD ReadPropertyNPB, :PCWSTR, :PCWSTR, :ptr PROPVARIANT
    STDMETHOD WritePropertyNPB, :PCWSTR, :PCWSTR, :ptr PROPVARIANT
    STDMETHOD RemovePropertyNPB, :PCWSTR, :PCWSTR
  DECLARE_INTERFACE_IID__END

  ;  SHPropStgCreate()
  ;  Wrap of IPropertySetStorage::Open/Create
  ;  This function ensures proper handling of code page retrieval/assignment
  ;  for the requested property set operation.
  ;  psstg,          //  Address of IPropertySetStorage vtable
  ;  fmtid,          //  property set ID
  ;  pclsid,         //  class ID associated with the set. This can be NULL
  ;  grfFlags,       //  PROPSETFLAG_xxx.  All sets containing ansi bytes should be created with
  ;  PROPSETFLAG_ANSI, otherwise PROPSETFLAG_DEFAULT.
  ;  grfMode,        //  STGM_ flags.  Must contain STGM_DIRECT|STGM_EXCLUSIVE.
  ;  dwDisposition,  //  OPEN_EXISTING. OPEN_ALWAYS, CREATE_NEW, or CREATE_ALWAYS
  ;  IPropertyStorage** ppstg,  // Address to receive requested vtable
  ;  puCodePage      //  Optional address to receive the code page ID for the set.
  @DefProto DllImport, SHPropStgCreate, WIN_STD_CALL_CONV,, <:ptr IPropertySetStorage, :REFFMTID, :ptr CLSID, :DWORD, :DWORD, :DWORD, :ptr ptr IPropertyStorage, :ptr UINT>, 32
  ;  SHPropStgReadMultiple()
  ;  IPropertyStorage::ReadMultiple wrap
  ;  The wrap ensures ANSI/UNICODE translations are handled properly for
  ;  legacy property sets.
  ;  pps,       // address of IPropertyStorage vtable.
  ;  uCodePage, //Code page value retrieved from SHCreatePropertySet
  ;  cpspec,    //Count of properties being read
  ;  rgpspec,   //Array of the properties to be read
  ;  rgvar      //Array of PROPVARIANTs containing the property values on return
  @DefProto DllImport, SHPropStgReadMultiple, WIN_STD_CALL_CONV,, <:ptr IPropertyStorage, :UINT, :ULONG, :ptr PROPSPEC, :ptr PROPVARIANT>, 20
  ;  SHPropStgWriteMultiple()
  ;  IPropertyStorage::WriteMultiple wrap
  ;  The wrap ensures ANSI/UNICODE translations are handled properly for
  ;  legacy property sets.
  ;  pps,       // address of IPropertyStorage vtable.
  ;  uCodePage, // code page retrieved from SHCreatePropertySet.
  ;  cpspec,    // The number of properties being set
  ;  rgpspec,   // Property specifiers
  ;  rgvar,     // Array of PROPVARIANT values
  ;  propidNameFirst // Minimum value for property identifiers. This value should be >= PID_FIRST_USABLE
  @DefProto DllImport, SHPropStgWriteMultiple, WIN_STD_CALL_CONV,, <:ptr IPropertyStorage, :ptr UINT, :ULONG, :ptr PROPSPEC, :ptr PROPVARIANT, :PROPID>, 24
  if (NTDDI_VERSION ge NTDDI_WINXP)
    @DefProto DllImport, SHCreateFileExtractIconA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :REFIID, :ptr ptr>, 16
    @DefProto DllImport, SHCreateFileExtractIconW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :REFIID, :ptr ptr>, 16
    ifdef UNICODE
      SHCreateFileExtractIcon equ <SHCreateFileExtractIconW>
    else
      SHCreateFileExtractIcon equ <SHCreateFileExtractIconA>
    endif
    ; !UNICODE
    @DefProto DllImport, SHLimitInputEdit, WIN_STD_CALL_CONV,, <:HWND, :ptr IShellFolder>, 8
    @DefProto DllImport, SHGetAttributesFromDataObject, WIN_STD_CALL_CONV,, <:ptr IDataObject, :DWORD, :ptr DWORD, :ptr UINT>, 16
  endif
  ; NTDDI_WINXP
  ; A usefull function in Defview for mapping idlist into index into system
  ; image list.  Optionally it can also look up the index of the selected
  ; icon.
  @DefProto DllImport, SHMapPIDLToSystemImageListIndex, WIN_STD_CALL_CONV,, <:ptr IShellFolder, :PCUITEMID_CHILD, :ptr SDWORD>, 12
  @DefProto DllImport, SHCLSIDFromString, WIN_STD_CALL_CONV,, <:PCWSTR, :ptr CLSID>, 8
  @DefProto DllImport, PickIconDlg, WIN_STD_CALL_CONV,, <:HWND, :PWSTR, :UINT, :ptr SDWORD>, 16
  if (NTDDI_VERSION ge NTDDI_WIN7)
    ; returns an IStream or IStorage via riid/ppv
    @DefProto DllImport, StgMakeUniqueName, WIN_STD_CALL_CONV,, <:ptr IStorage, :PCWSTR, :DWORD, :REFIID, :ptr ptr>, 20
  endif
  ; NTDDI_WIN7
  if (_WIN32_IE ge _WIN32_IE_IE70)
    IESHORTCUTFLAGS typedef SDWORD
    IESHORTCUT_NEWBROWSER equ 01h
    IESHORTCUT_OPENNEWTAB equ 02h
    IESHORTCUT_FORCENAVIGATE equ 04h
    IESHORTCUT_BACKGROUNDTAB equ 08h
    tagIESHORTCUTFLAGS typedef IESHORTCUTFLAGS

  endif
  ; _WIN32_IE_IE70
  include poppack.inc
  ifdef __cplusplus
    ;[...]
  endif
  ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
endif
