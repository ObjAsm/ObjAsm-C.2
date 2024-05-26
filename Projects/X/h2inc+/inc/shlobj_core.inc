;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\shlobj_core.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 21/02/2024 18:17:24

include winapifamily.inc
if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
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
  ifndef INITGUID
    include shlguid.inc
  endif
  include shtypes.inc
  include shobjidl_core.inc
  if Defined(_MSC_VER) and (_MSC_VER ge 1200)
  endif
  ifdef __cplusplus
    ;[...]
  endif
  include pshpack1.inc
  @DefProto DllImport, SHGetMalloc, WIN_STD_CALL_CONV,, <:ptr ptr IMalloc>, 4
  @DefProto DllImport, SHAlloc, WIN_STD_CALL_CONV,, <:SIZE_T>, 4
  @DefProto DllImport, SHFree, WIN_STD_CALL_CONV,, <:ptr>, 4
  GIL_OPENICON equ 0001h
  GIL_FORSHELL equ 0002h
  GIL_ASYNC equ 0020h
  GIL_DEFAULTICON equ 0040h
  GIL_FORSHORTCUT equ 0080h
  GIL_CHECKSHIELD equ 0200h
  GIL_SIMULATEDOC equ 0001h
  GIL_PERINSTANCE equ 0002h
  GIL_PERCLASS equ 0004h
  GIL_NOTFILENAME equ 0008h
  GIL_DONTCACHE equ 0010h
  GIL_SHIELD equ 0200h
  GIL_FORCENOSHIELD equ 0400h
  INTERFACE equ <IExtractIconA>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(IExtractIconA, IUnknown, "000214eb-0000-0000-c000-000000000046")
    STDMETHOD GetIconLocation, :, :, :, :ptr , :ptr 
    STDMETHOD Extract, :, :, :ptr , :ptr , :
  DECLARE_INTERFACE_IID__END

  LPEXTRACTICONA typedef ptr IExtractIconA
  INTERFACE equ <IExtractIconW>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(IExtractIconW, IUnknown, "000214fa-0000-0000-c000-000000000046")
    STDMETHOD GetIconLocation, :, :, :, :ptr , :ptr 
    STDMETHOD Extract, :, :, :ptr , :ptr , :
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
  INTERFACE equ <IShellIconOverlayManager>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(IShellIconOverlayManager, IUnknown, "f10b5e34-dd3b-42a7-aa7d-2f4ec54bb09b")
    STDMETHOD GetFileOverlayInfo, :, :, :ptr , :
    STDMETHOD GetReservedOverlayInfo, :, :, :ptr , :, :
    STDMETHOD RefreshOverlayImages, :
    STDMETHOD LoadNonloadedOverlayIdentifiers
    STDMETHOD OverlayIndexFromImageIndex, :, :ptr , :
  DECLARE_INTERFACE_IID__END

  SIOM_OVERLAYINDEX equ 1h
  SIOM_ICONINDEX equ 2h
  SIOM_RESERVED_SHARED equ 0
  SIOM_RESERVED_LINK equ 1
  SIOM_RESERVED_SLOWFILE equ 2
  SIOM_RESERVED_DEFAULT equ 3
  INTERFACE equ <IShellIconOverlay>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(IShellIconOverlay, IUnknown, "7d688a70-c613-11d0-999b-00c04fd655e1")
    STDMETHOD GetOverlayIndex, :, :ptr 
    STDMETHOD GetOverlayIconIndex, :, :ptr 
  DECLARE_INTERFACE_IID__END

  OI_DEFAULT equ 00000000h
  OI_ASYNC equ 0FFFFEEEEh
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
  SHELL_LINK_DATA_FLAGS typedef SDWORD
  SLDF_DEFAULT equ 00000000h
  SLDF_HAS_ID_LIST equ 00000001h
  SLDF_HAS_LINK_INFO equ 00000002h
  SLDF_HAS_NAME equ 00000004h
  SLDF_HAS_RELPATH equ 00000008h
  SLDF_HAS_WORKINGDIR equ 00000010h
  SLDF_HAS_ARGS equ 00000020h
  SLDF_HAS_ICONLOCATION equ 00000040h
  SLDF_UNICODE equ 00000080h
  SLDF_FORCE_NO_LINKINFO equ 00000100h
  SLDF_HAS_EXP_SZ equ 00000200h
  SLDF_RUN_IN_SEPARATE equ 00000400h
  if (NTDDI_VERSION lt NTDDI_VISTA)
    SLDF_HAS_LOGO3ID equ 00000800h
  endif
  SLDF_HAS_DARWINID equ 00001000h
  SLDF_RUNAS_USER equ 00002000h
  SLDF_HAS_EXP_ICON_SZ equ 00004000h
  if (NTDDI_VERSION ge NTDDI_WINXP)
    SLDF_NO_PIDL_ALIAS equ 00008000h
    SLDF_FORCE_UNCNAME equ 00010000h
    SLDF_RUN_WITH_SHIMLAYER equ 00020000h
    if (NTDDI_VERSION ge NTDDI_VISTA)
      SLDF_FORCE_NO_LINKTRACK equ 00040000h
      SLDF_ENABLE_TARGET_METADATA equ 00080000h
      SLDF_DISABLE_LINK_PATH_TRACKING equ 00100000h
      SLDF_DISABLE_KNOWNFOLDER_RELATIVE_TRACKING equ 00200000h
      if (NTDDI_VERSION ge NTDDI_WIN7)
        SLDF_NO_KF_ALIAS equ 00400000h
        SLDF_ALLOW_LINK_TO_LINK equ 00800000h
        SLDF_UNALIAS_ON_SAVE equ 01000000h
        SLDF_PREFER_ENVIRONMENT_PATH equ 02000000h
        SLDF_KEEP_LOCAL_IDLIST_FOR_UNC_TARGET equ 04000000h
        if (NTDDI_VERSION ge NTDDI_WIN8)
          SLDF_PERSIST_VOLUME_ID_RELATIVE equ 08000000h
          SLDF_VALID equ 0FFFF7FFh
        else
          SLDF_VALID equ 07FFF7FFh
        endif
      else
        SLDF_VALID equ 003FF7FFh
      endif
    endif
    SLDF_RESERVED equ 80000000h
  endif

  DEFINE_ENUM_FLAG_OPERATORS(SHELL_LINK_DATA_FLAGS)
  if  not Defined(__cplusplus) and Defined(_MSC_VER) and (_MSC_VER ge 1200)
  endif
  DATABLOCK_HEADER struct
    cbSize DWORD ?
    dwSignature DWORD ?
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
      wPopupFillAttribute WORD ?
      dwScreenBufferSize COORD <>
      dwWindowSize COORD <>
      dwWindowOrigin COORD <>
      nFont DWORD ?
      nInputBufferSize DWORD ?
      dwFontSize COORD <>
      uFontFamily UINT ?
      uFontWeight UINT ?
      FaceName WCHAR LF_FACESIZE dup (?)
      uCursorSize UINT ?
      bFullScreen BOOL ?
      bQuickEdit BOOL ?
      bInsertMode BOOL ?
      bAutoPosition BOOL ?
      uHistoryBufferSize UINT ?
      uNumberOfHistoryBuffers UINT ?
      bHistoryNoDup BOOL ?
      ColorTable COLORREF 16 dup (?)
    NT_CONSOLE_PROPS ends
    LPNT_CONSOLE_PROPS typedef ptr NT_CONSOLE_PROPS
    NT_CONSOLE_PROPS_SIG equ 0A0000002h
  endif
  NT_FE_CONSOLE_PROPS struct
    ifdef __cplusplus
      ;[...]
    else
      DUMMYSTRUCTNAME DATABLOCK_HEADER <>
    endif
    uCodePage UINT ?
  NT_FE_CONSOLE_PROPS ends
  LPNT_FE_CONSOLE_PROPS typedef ptr NT_FE_CONSOLE_PROPS
  NT_FE_CONSOLE_PROPS_SIG equ 0A0000004h
  EXP_DARWIN_LINK struct
    ifdef __cplusplus
      ;[...]
    else
      DUMMYSTRUCTNAME DATABLOCK_HEADER <>
    endif
    szDarwinID CHAR MAX_PATH dup (?)
    szwDarwinID WCHAR MAX_PATH dup (?)
  EXP_DARWIN_LINK ends
  LPEXP_DARWIN_LINK typedef ptr EXP_DARWIN_LINK
  EXP_DARWIN_ID_SIG equ 0A0000006h
  if  not Defined(__cplusplus) and Defined(_MSC_VER) and (_MSC_VER ge 1200)
  endif
  EXP_SPECIAL_FOLDER_SIG equ 0A0000005h
  EXP_SPECIAL_FOLDER struct
    cbSize DWORD ?
    dwSignature DWORD ?
    idSpecialFolder DWORD ?
    cbOffset DWORD ?
  EXP_SPECIAL_FOLDER ends
  LPEXP_SPECIAL_FOLDER typedef ptr EXP_SPECIAL_FOLDER
  EXP_SZ_LINK struct
    cbSize DWORD ?
    dwSignature DWORD ?
    szTarget CHAR MAX_PATH dup (?)
    swzTarget WCHAR MAX_PATH dup (?)
  EXP_SZ_LINK ends
  LPEXP_SZ_LINK typedef ptr EXP_SZ_LINK
  EXP_SZ_LINK_SIG equ 0A0000001h
  EXP_SZ_ICON_SIG equ 0A0000007h
  if (NTDDI_VERSION ge NTDDI_VISTA)
    EXP_PROPERTYSTORAGE struct
      cbSize DWORD ?
      dwSignature DWORD ?
      abPropertyStorage BYTE 1 dup (?)
    EXP_PROPERTYSTORAGE ends
    EXP_PROPERTYSTORAGE_SIG equ 0A0000009h
  endif
  ifdef _INC_SHELLAPI
    INTERFACE equ <IShellExecuteHookA>
    ??Interface equ <>
    DECLARE_INTERFACE_IID_(IShellExecuteHookA, IUnknown, "000214f5-0000-0000-c000-000000000046")
      STDMETHOD Execute, :
    DECLARE_INTERFACE_IID__END

    INTERFACE equ <IShellExecuteHookW>
    ??Interface equ <>
    DECLARE_INTERFACE_IID_(IShellExecuteHookW, IUnknown, "000214fb-0000-0000-c000-000000000046")
      STDMETHOD Execute, :
    DECLARE_INTERFACE_IID__END

    ifdef UNICODE
      IShellExecuteHook equ <IShellExecuteHookW>
      IShellExecuteHookVtbl equ <IShellExecuteHookWVtbl>
    else
      IShellExecuteHook equ <IShellExecuteHookA>
      IShellExecuteHookVtbl equ <IShellExecuteHookAVtbl>
    endif
  endif
  INTERFACE equ <IURLSearchHook>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(IURLSearchHook, IUnknown, "ac60f6a0-0fd9-11d0-99cb-00c04fd64497")
    STDMETHOD Translate, :, :
  DECLARE_INTERFACE_IID__END

  INTERFACE equ <ISearchContext>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(ISearchContext, IUnknown, "09F656A2-41AF-480C-88F7-16CC0D164615")
    STDMETHOD GetSearchUrl, :ptr 
    STDMETHOD GetSearchText, :ptr 
    STDMETHOD GetSearchStyle, :ptr 
  DECLARE_INTERFACE_IID__END

  INTERFACE equ <IURLSearchHook2>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(IURLSearchHook2, IURLSearchHook, "5ee44da4-6d32-46e3-86bc-07540dedd0e0")
    STDMETHOD TranslateWithSearchContext, :, :, :ptr 
  DECLARE_INTERFACE_IID__END

  FCIDM_SHVIEWFIRST equ 0000h
  FCIDM_SHVIEWLAST equ 7fffh
  FCIDM_BROWSERFIRST equ 0a000h
  FCIDM_BROWSERLAST equ 0bf00h
  FCIDM_GLOBALFIRST equ 8000h
  FCIDM_GLOBALLAST equ 9fffh
  FCIDM_MENU_FILE equ (FCIDM_GLOBALFIRST + 0000h)
  FCIDM_MENU_EDIT equ (FCIDM_GLOBALFIRST + 0040h)
  FCIDM_MENU_VIEW equ (FCIDM_GLOBALFIRST + 0080h)
  FCIDM_MENU_VIEW_SEP_OPTIONS equ (FCIDM_GLOBALFIRST + 0081h)
  FCIDM_MENU_TOOLS equ (FCIDM_GLOBALFIRST + 00c0h)
  FCIDM_MENU_TOOLS_SEP_GOTO equ (FCIDM_GLOBALFIRST + 00c1h)
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
  if (NTDDI_VERSION ge NTDDI_VISTA)
    @DefProto DllImport, ILLoadFromStreamEx, WIN_STD_CALL_CONV,, <:ptr IStream, :ptr PIDLIST_RELATIVE>, 8
  endif
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
  endif
  @DefProto DllImport, SHILCreateFromPath, WIN_STD_CALL_CONV,, <:PCWSTR, :ptr PIDLIST_ABSOLUTE, :ptr DWORD>, 12
  VOID_OFFSET macro pv, cb
    exitm <((((pv)) + (cb)))>
  endm
  if Defined(STRICT_TYPED_ITEMIDS) and Defined(__cplusplus)
    ;[...]
  else
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
    ILIsChild macro pidl
      exitm <(ILIsEmpty(pidl) or ILIsEmpty(ILNext(pidl)))>
    endm
  endif
  @DefProto DllImport, ILAppendID, WIN_STD_CALL_CONV,, <:PIDLIST_RELATIVE, :LPCSHITEMID, :BOOL>, 12
  if (NTDDI_VERSION ge NTDDI_VISTA)
    GPFIDL_DEFAULT equ 0000h
    GPFIDL_ALTNAME equ 0001h
    GPFIDL_UNCPRINTER equ 0002h

    GPFIDL_FLAGS typedef SDWORD
    @DefProto DllImport, SHGetPathFromIDListEx, WIN_STD_CALL_CONV,, <:PCIDLIST_ABSOLUTE, :PWSTR, :DWORD, :GPFIDL_FLAGS>, 16
  endif
  @DefProto DllImport, SHGetPathFromIDListA, WIN_STD_CALL_CONV,, <:PCIDLIST_ABSOLUTE, :LPSTR>, 8
  @DefProto DllImport, SHGetPathFromIDListW, WIN_STD_CALL_CONV,, <:PCIDLIST_ABSOLUTE, :LPWSTR>, 8
  ifdef UNICODE
    SHGetPathFromIDList equ <SHGetPathFromIDListW>
  else
    SHGetPathFromIDList equ <SHGetPathFromIDListA>
  endif
  @DefProto DllImport, SHCreateDirectory, WIN_STD_CALL_CONV,, <:HWND, :PCWSTR>, 8
  @DefProto DllImport, SHCreateDirectoryExA, WIN_STD_CALL_CONV,, <:HWND, :LPCSTR, :ptr SECURITY_ATTRIBUTES>, 12
  @DefProto DllImport, SHCreateDirectoryExW, WIN_STD_CALL_CONV,, <:HWND, :LPCWSTR, :ptr SECURITY_ATTRIBUTES>, 12
  ifdef UNICODE
    SHCreateDirectoryEx equ <SHCreateDirectoryExW>
  else
    SHCreateDirectoryEx equ <SHCreateDirectoryExA>
  endif
  if (NTDDI_VERSION ge NTDDI_VISTA)
    OFASI_EDIT equ 0001h
    OFASI_OPENDESKTOP equ 0002h
  endif
  if (NTDDI_VERSION ge NTDDI_WINXP)
    @DefProto DllImport, SHOpenFolderAndSelectItems, WIN_STD_CALL_CONV,, <:PCIDLIST_ABSOLUTE, :UINT, :PCUITEMID_CHILD_ARRAY, :DWORD>, 16
    @DefProto DllImport, SHCreateShellItem, WIN_STD_CALL_CONV,, <:PCIDLIST_ABSOLUTE, :ptr IShellFolder, :PCUITEMID_CHILD, :ptr ptr IShellItem>, 16
  endif
  REGSTR_PATH_SPECIAL_FOLDERS equ <REGSTR_PATH_EXPLORER TEXT("\Shell Folders")>
  CSIDL_DESKTOP equ 0000h
  CSIDL_INTERNET equ 0001h
  CSIDL_PROGRAMS equ 0002h
  CSIDL_CONTROLS equ 0003h
  CSIDL_PRINTERS equ 0004h
  CSIDL_PERSONAL equ 0005h
  CSIDL_FAVORITES equ 0006h
  CSIDL_STARTUP equ 0007h
  CSIDL_RECENT equ 0008h
  CSIDL_SENDTO equ 0009h
  CSIDL_BITBUCKET equ 000ah
  CSIDL_STARTMENU equ 000bh
  CSIDL_MYDOCUMENTS equ <CSIDL_PERSONAL>
  CSIDL_MYMUSIC equ 000dh
  CSIDL_MYVIDEO equ 000eh
  CSIDL_DESKTOPDIRECTORY equ 0010h
  CSIDL_DRIVES equ 0011h
  CSIDL_NETWORK equ 0012h
  CSIDL_NETHOOD equ 0013h
  CSIDL_FONTS equ 0014h
  CSIDL_TEMPLATES equ 0015h
  CSIDL_COMMON_STARTMENU equ 0016h
  CSIDL_COMMON_PROGRAMS equ 0017h
  CSIDL_COMMON_STARTUP equ 0018h
  CSIDL_COMMON_DESKTOPDIRECTORY equ 0019h
  CSIDL_APPDATA equ 001ah
  CSIDL_PRINTHOOD equ 001bh
  ifndef CSIDL_LOCAL_APPDATA
    CSIDL_LOCAL_APPDATA equ 001ch
  endif
  CSIDL_ALTSTARTUP equ 001dh
  CSIDL_COMMON_ALTSTARTUP equ 001eh
  CSIDL_COMMON_FAVORITES equ 001fh
  ifndef _SHFOLDER_H_
    CSIDL_INTERNET_CACHE equ 0020h
    CSIDL_COOKIES equ 0021h
    CSIDL_HISTORY equ 0022h
    CSIDL_COMMON_APPDATA equ 0023h
    CSIDL_WINDOWS equ 0024h
    CSIDL_SYSTEM equ 0025h
    CSIDL_PROGRAM_FILES equ 0026h
    CSIDL_MYPICTURES equ 0027h
  endif
  CSIDL_PROFILE equ 0028h
  CSIDL_SYSTEMX86 equ 0029h
  CSIDL_PROGRAM_FILESX86 equ 002ah
  ifndef _SHFOLDER_H_
    CSIDL_PROGRAM_FILES_COMMON equ 002bh
  endif
  CSIDL_PROGRAM_FILES_COMMONX86 equ 002ch
  CSIDL_COMMON_TEMPLATES equ 002dh
  ifndef _SHFOLDER_H_
    CSIDL_COMMON_DOCUMENTS equ 002eh
    CSIDL_COMMON_ADMINTOOLS equ 002fh
    CSIDL_ADMINTOOLS equ 0030h
  endif
  CSIDL_CONNECTIONS equ 0031h
  CSIDL_COMMON_MUSIC equ 0035h
  CSIDL_COMMON_PICTURES equ 0036h
  CSIDL_COMMON_VIDEO equ 0037h
  CSIDL_RESOURCES equ 0038h
  ifndef _SHFOLDER_H_
    CSIDL_RESOURCES_LOCALIZED equ 0039h
  endif
  CSIDL_COMMON_OEM_LINKS equ 003ah
  CSIDL_CDBURN_AREA equ 003bh
  CSIDL_COMPUTERSNEARME equ 003dh
  ifndef _SHFOLDER_H_
    CSIDL_FLAG_CREATE equ 8000h
  endif
  CSIDL_FLAG_DONT_VERIFY equ 4000h
  CSIDL_FLAG_DONT_UNEXPAND equ 2000h
  if (NTDDI_VERSION ge NTDDI_WINXP)
    CSIDL_FLAG_NO_ALIAS equ 1000h
    CSIDL_FLAG_PER_USER_INIT equ 0800h
  endif
  CSIDL_FLAG_MASK equ 0FF00h
  @DefProto DllImport, SHGetSpecialFolderLocation, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :ptr PIDLIST_ABSOLUTE>, 12
  @DefProto DllImport, SHCloneSpecialIDList, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :BOOL>, 12
  @DefProto DllImport, SHGetSpecialFolderPathA, WIN_STD_CALL_CONV,, <:HWND, :LPSTR, :SDWORD, :BOOL>, 16
  @DefProto DllImport, SHGetSpecialFolderPathW, WIN_STD_CALL_CONV,, <:HWND, :LPWSTR, :SDWORD, :BOOL>, 16
  ifdef UNICODE
    SHGetSpecialFolderPath equ <SHGetSpecialFolderPathW>
  else
    SHGetSpecialFolderPath equ <SHGetSpecialFolderPathA>
  endif
  if (NTDDI_VERSION ge NTDDI_WIN2K)
    @DefProto DllImport, SHFlushSFCache, WIN_STD_CALL_CONV,, <>, 0
    SHGFP_TYPE typedef SDWORD
    SHGFP_TYPE_CURRENT equ 0
    SHGFP_TYPE_DEFAULT equ 1

    @DefProto DllImport, SHGetFolderPathA, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :HANDLE, :DWORD, :LPSTR>, 20
    @DefProto DllImport, SHGetFolderPathW, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :HANDLE, :DWORD, :LPWSTR>, 20
    ifdef UNICODE
      SHGetFolderPath equ <SHGetFolderPathW>
    else
      SHGetFolderPath equ <SHGetFolderPathA>
    endif
    @DefProto DllImport, SHGetFolderLocation, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :HANDLE, :DWORD, :ptr PIDLIST_ABSOLUTE>, 20
  endif
  if (NTDDI_VERSION ge NTDDI_WINXP)
    @DefProto DllImport, SHSetFolderPathA, WIN_STD_CALL_CONV,, <:SDWORD, :HANDLE, :DWORD, :LPCSTR>, 16
    @DefProto DllImport, SHSetFolderPathW, WIN_STD_CALL_CONV,, <:SDWORD, :HANDLE, :DWORD, :LPCWSTR>, 16
    ifdef UNICODE
      SHSetFolderPath equ <SHSetFolderPathW>
    else
      SHSetFolderPath equ <SHSetFolderPathA>
    endif
    @DefProto DllImport, SHGetFolderPathAndSubDirA, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :HANDLE, :DWORD, :LPCSTR, :LPSTR>, 24
    @DefProto DllImport, SHGetFolderPathAndSubDirW, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :HANDLE, :DWORD, :LPCWSTR, :LPWSTR>, 24
    ifdef UNICODE
      SHGetFolderPathAndSubDir equ <SHGetFolderPathAndSubDirW>
    else
      SHGetFolderPathAndSubDir equ <SHGetFolderPathAndSubDirA>
    endif
  endif
  if (NTDDI_VERSION ge NTDDI_VISTA)
    KNOWN_FOLDER_FLAG typedef SDWORD
    KF_FLAG_DEFAULT equ 00000000h
    if (NTDDI_VERSION ge NTDDI_WIN10_RS3)
      KF_FLAG_FORCE_APP_DATA_REDIRECTION equ 00080000h
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_RS2)
      KF_FLAG_RETURN_FILTER_REDIRECTION_TARGET equ 00040000h
      KF_FLAG_FORCE_PACKAGE_REDIRECTION equ 00020000h
      KF_FLAG_NO_PACKAGE_REDIRECTION equ 00010000h
      KF_FLAG_FORCE_APPCONTAINER_REDIRECTION equ 00020000h
    endif
    if (NTDDI_VERSION ge NTDDI_WIN7)
      KF_FLAG_NO_APPCONTAINER_REDIRECTION equ 00010000h
    endif
    KF_FLAG_CREATE equ 00008000h
    KF_FLAG_DONT_VERIFY equ 00004000h
    KF_FLAG_DONT_UNEXPAND equ 00002000h
    KF_FLAG_NO_ALIAS equ 00001000h
    KF_FLAG_INIT equ 00000800h
    KF_FLAG_DEFAULT_PATH equ 00000400h
    KF_FLAG_NOT_PARENT_RELATIVE equ 00000200h
    KF_FLAG_SIMPLE_IDLIST equ 00000100h
    KF_FLAG_ALIAS_ONLY equ 80000000h

    DEFINE_ENUM_FLAG_OPERATORS(KNOWN_FOLDER_FLAG)
    @DefProto DllImport, SHGetKnownFolderIDList, WIN_STD_CALL_CONV,, <:REFKNOWNFOLDERID, :DWORD, :HANDLE, :ptr PIDLIST_ABSOLUTE>, 16
    @DefProto DllImport, SHSetKnownFolderPath, WIN_STD_CALL_CONV,, <:REFKNOWNFOLDERID, :DWORD, :HANDLE, :PCWSTR>, 16
    @DefProto DllImport, SHGetKnownFolderPath, WIN_STD_CALL_CONV,, <:REFKNOWNFOLDERID, :DWORD, :HANDLE, :ptr PWSTR>, 16
  endif
  if (NTDDI_VERSION ge NTDDI_WIN7)
    @DefProto DllImport, SHGetKnownFolderItem, WIN_STD_CALL_CONV,, <:REFKNOWNFOLDERID, :KNOWN_FOLDER_FLAG, :HANDLE, :REFIID, :ptr ptr>, 20
  endif
  if (NTDDI_VERSION ge NTDDI_WIN2K)
    FCS_READ equ 00000001h
    FCS_FORCEWRITE equ 00000002h
    FCS_WRITE equ <(FCS_READ or FCS_FORCEWRITE)>
    FCS_FLAG_DRAGDROP equ 2
    FCSM_VIEWID equ 00000001h
    FCSM_WEBVIEWTEMPLATE equ 00000002h
    FCSM_INFOTIP equ 00000004h
    FCSM_CLSID equ 00000008h
    FCSM_ICONFILE equ 00000010h
    FCSM_LOGO equ 00000020h
    FCSM_FLAGS equ 00000040h
    if (NTDDI_VERSION ge NTDDI_VISTA)
      include pshpack8.inc
      SHFOLDERCUSTOMSETTINGS struct
        dwSize DWORD ?
        dwMask DWORD ?
        pvid POINTER ?
        pszWebViewTemplate LPWSTR ?
        cchWebViewTemplate DWORD ?
        pszWebViewTemplateVersion LPWSTR ?
        pszInfoTip LPWSTR ?
        cchInfoTip DWORD ?
        pclsid POINTER ?
        dwFlags DWORD ?
        pszIconFile LPWSTR ?
        cchIconFile DWORD ?
        iIconIndex SDWORD ?
        pszLogo LPWSTR ?
        cchLogo DWORD ?
      SHFOLDERCUSTOMSETTINGS ends
      LPSHFOLDERCUSTOMSETTINGS typedef ptr SHFOLDERCUSTOMSETTINGS
      include poppack.inc
      @DefProto DllImport, SHGetSetFolderCustomSettings, WIN_STD_CALL_CONV,, <:LPSHFOLDERCUSTOMSETTINGS, :PCWSTR, :DWORD>, 12
    endif
  endif
  TYPE_BFFCALLBACK typedef proto WIN_STD_CALL_CONV :HWND, :UINT, :LPARAM, :LPARAM
  BFFCALLBACK typedef ptr TYPE_BFFCALLBACK

  include pshpack8.inc
  BROWSEINFOA struct
    hwndOwner HWND ?
    pidlRoot PCIDLIST_ABSOLUTE ?
    pszDisplayName LPSTR ?
    lpszTitle LPCSTR ?
    ulFlags UINT ?
    lpfn BFFCALLBACK ?
    lParam LPARAM ?
    iImage SDWORD ?
  BROWSEINFOA ends
  _browseinfoA typedef BROWSEINFOA
  PBROWSEINFOA typedef ptr BROWSEINFOA
  LPBROWSEINFOA typedef ptr BROWSEINFOA
  BROWSEINFOW struct
    hwndOwner HWND ?
    pidlRoot PCIDLIST_ABSOLUTE ?
    pszDisplayName LPWSTR ?
    lpszTitle LPCWSTR ?
    ulFlags UINT ?
    lpfn BFFCALLBACK ?
    lParam LPARAM ?
    iImage SDWORD ?
  BROWSEINFOW ends
  _browseinfoW typedef BROWSEINFOW
  PBROWSEINFOW typedef ptr BROWSEINFOW
  LPBROWSEINFOW typedef ptr BROWSEINFOW
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
  BIF_RETURNONLYFSDIRS equ 00000001h
  BIF_DONTGOBELOWDOMAIN equ 00000002h
  BIF_STATUSTEXT equ 00000004h
  BIF_RETURNFSANCESTORS equ 00000008h
  BIF_EDITBOX equ 00000010h
  BIF_VALIDATE equ 00000020h
  BIF_NEWDIALOGSTYLE equ 00000040h
  BIF_USENEWUI equ <(BIF_NEWDIALOGSTYLE or BIF_EDITBOX)>
  BIF_BROWSEINCLUDEURLS equ 00000080h
  BIF_UAHINT equ 00000100h
  BIF_NONEWFOLDERBUTTON equ 00000200h
  BIF_NOTRANSLATETARGETS equ 00000400h
  BIF_BROWSEFORCOMPUTER equ 00001000h
  BIF_BROWSEFORPRINTER equ 00002000h
  BIF_BROWSEINCLUDEFILES equ 00004000h
  BIF_SHAREABLE equ 00008000h
  BIF_BROWSEFILEJUNCTIONS equ 00010000h
  BFFM_INITIALIZED equ 1
  BFFM_SELCHANGED equ 2
  BFFM_VALIDATEFAILEDA equ 3
  BFFM_VALIDATEFAILEDW equ 4
  BFFM_IUNKNOWN equ 5
  BFFM_SETSTATUSTEXTA equ (WM_USER + 100)
  BFFM_ENABLEOK equ (WM_USER + 101)
  BFFM_SETSELECTIONA equ (WM_USER + 102)
  BFFM_SETSELECTIONW equ (WM_USER + 103)
  BFFM_SETSTATUSTEXTW equ (WM_USER + 104)
  BFFM_SETOKTEXT equ (WM_USER + 105)
  BFFM_SETEXPANDED equ (WM_USER + 106)
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
  @DefProto DllImport, SHLoadInProc, WIN_STD_CALL_CONV,, <:REFCLSID>, 4
  ISHCUTCMDID_DOWNLOADICON equ 0
  ISHCUTCMDID_INTSHORTCUTCREATE equ 1
  if (_WIN32_IE ge _WIN32_IE_IE70)
    ISHCUTCMDID_COMMITHISTORY equ 2
    ISHCUTCMDID_SETUSERAWURL equ 3
  endif

  CMDID_INTSHORTCUTCREATE equ <ISHCUTCMDID_INTSHORTCUTCREATE>
  STR_PARSE_WITH_PROPERTIES equ <L("ParseWithProperties")>
  STR_PARSE_PARTIAL_IDLIST equ <L("ParseOriginalItem")>
  @DefProto DllImport, SHGetDesktopFolder, WIN_STD_CALL_CONV,, <:ptr ptr IShellFolder>, 4
  INTERFACE equ <IShellDetails>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(IShellDetails, IUnknown, "000214EC-0000-0000-c000-000000000046")
    STDMETHOD GetDetailsOf, :, :, :ptr 
    STDMETHOD ColumnClick, :
  DECLARE_INTERFACE_IID__END

  INTERFACE equ <IObjMgr>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(IObjMgr, IUnknown, "00BB2761-6A77-11D0-A535-00C04FD7D062")
    STDMETHOD Append, :ptr 
    STDMETHOD Remove, :ptr 
  DECLARE_INTERFACE_IID__END

  INTERFACE equ <IACList>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(IACList, IUnknown, "77A130B0-94FD-11D0-A544-00C04FD7d062")
    STDMETHOD Expand, :
  DECLARE_INTERFACE_IID__END

  INTERFACE equ <IACList2>
  AUTOCOMPLETELISTOPTIONS typedef SDWORD
  ACLO_NONE equ 0
  ACLO_CURRENTDIR equ 1
  ACLO_MYCOMPUTER equ 2
  ACLO_DESKTOP equ 4
  ACLO_FAVORITES equ 8
  ACLO_FILESYSONLY equ 16
  if (_WIN32_IE ge _WIN32_IE_IE60)
    ACLO_FILESYSDIRS equ 32
  endif
  if (_WIN32_IE ge _WIN32_IE_IE70)
    ACLO_VIRTUALNAMESPACE equ 64
  endif
  _tagAUTOCOMPLETELISTOPTIONS typedef AUTOCOMPLETELISTOPTIONS

  ??Interface equ <>
  DECLARE_INTERFACE_IID_(IACList2, IACList, "470141a0-5186-11d2-bbb6-0060977b464c")
    STDMETHOD SetOptions, :
    STDMETHOD GetOptions, :ptr 
  DECLARE_INTERFACE_IID__END

  PROGDLG_NORMAL equ 00000000h
  PROGDLG_MODAL equ 00000001h
  PROGDLG_AUTOTIME equ 00000002h
  PROGDLG_NOTIME equ 00000004h
  PROGDLG_NOMINIMIZE equ 00000008h
  PROGDLG_NOPROGRESSBAR equ 00000010h
  if (_WIN32_IE ge _WIN32_IE_IE70)
    PROGDLG_MARQUEEPROGRESS equ 00000020h
    PROGDLG_NOCANCEL equ 00000040h
  endif
  PDTIMER_RESET equ 00000001h
  if (_WIN32_IE ge _WIN32_IE_IE70)
    PDTIMER_PAUSE equ 00000002h
    PDTIMER_RESUME equ 00000003h
  endif
  INTERFACE equ <IProgressDialog>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(IProgressDialog, IUnknown, "EBBC7C04-315E-11d2-B62F-006097DF5BD4")
    STDMETHOD StartProgressDialog, :, :ptr , :, :
    STDMETHOD StopProgressDialog
    STDMETHOD SetTitle, :
    STDMETHOD SetAnimation, :, :
    STDMETHOD_ BOOL, HasUserCancelled
    STDMETHOD SetProgress, :, :
    STDMETHOD SetProgress64, :, :
    STDMETHOD SetLine, :, :, :, :
    STDMETHOD SetCancelMsg, :, :
    STDMETHOD Timer, :, :
  DECLARE_INTERFACE_IID__END

  INTERFACE equ <IDockingWindowSite>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(IDockingWindowSite, IOleWindow, "2a342fc2-7b26-11d0-8ca9-00a0c92dbfe8")
    STDMETHOD GetBorderDW, :ptr , :ptr 
    STDMETHOD RequestBorderSpaceDW, :ptr , :
    STDMETHOD SetBorderSpaceDW, :ptr , :
  DECLARE_INTERFACE_IID__END

  ifdef _WININET_
    WALLPAPEROPT struct
      dwSize DWORD ?
      dwStyle DWORD ?
    WALLPAPEROPT ends
    _tagWALLPAPEROPT typedef WALLPAPEROPT
    LPWALLPAPEROPT typedef ptr WALLPAPEROPT
    LPCWALLPAPEROPT typedef ptr WALLPAPEROPT
    COMPONENTSOPT struct
      dwSize DWORD ?
      fEnableComponents BOOL ?
      fActiveDesktop BOOL ?
    COMPONENTSOPT ends
    _tagCOMPONENTSOPT typedef COMPONENTSOPT
    LPCOMPONENTSOPT typedef ptr COMPONENTSOPT
    LPCCOMPONENTSOPT typedef ptr COMPONENTSOPT
    COMPPOS struct
      dwSize DWORD ?
      iLeft SDWORD ?
      iTop SDWORD ?
      dwWidth DWORD ?
      dwHeight DWORD ?
      izIndex SDWORD ?
      fCanResize BOOL ?
      fCanResizeX BOOL ?
      fCanResizeY BOOL ?
      iPreferredLeftPercent SDWORD ?
      iPreferredTopPercent SDWORD ?
    COMPPOS ends
    _tagCOMPPOS typedef COMPPOS
    LPCOMPPOS typedef ptr COMPPOS
    LPCCOMPPOS typedef ptr COMPPOS
    COMPSTATEINFO struct
      dwSize DWORD ?
      iLeft SDWORD ?
      iTop SDWORD ?
      dwWidth DWORD ?
      dwHeight DWORD ?
      dwItemState DWORD ?
    COMPSTATEINFO ends
    _tagCOMPSTATEINFO typedef COMPSTATEINFO
    LPCOMPSTATEINFO typedef ptr COMPSTATEINFO
    LPCCOMPSTATEINFO typedef ptr COMPSTATEINFO
    COMPONENT_TOP equ (3fffffffh)
    COMP_TYPE_HTMLDOC equ 0
    COMP_TYPE_PICTURE equ 1
    COMP_TYPE_WEBSITE equ 2
    COMP_TYPE_CONTROL equ 3
    COMP_TYPE_CFHTML equ 4
    COMP_TYPE_MAX equ 4
    IE4COMPONENT struct
      dwSize DWORD ?
      dwID DWORD ?
      iComponentType SDWORD ?
      fChecked BOOL ?
      fDirty BOOL ?
      fNoScroll BOOL ?
      cpPos COMPPOS <>
      wszFriendlyName WCHAR MAX_PATH dup (?)
      wszSource WCHAR INTERNET_MAX_URL_LENGTH dup (?)
      wszSubscribedURL WCHAR INTERNET_MAX_URL_LENGTH dup (?)
    IE4COMPONENT ends
    _tagIE4COMPONENT typedef IE4COMPONENT
    LPIE4COMPONENT typedef ptr IE4COMPONENT
    LPCIE4COMPONENT typedef ptr IE4COMPONENT
    COMPONENT struct
      dwSize DWORD ?
      dwID DWORD ?
      iComponentType SDWORD ?
      fChecked BOOL ?
      fDirty BOOL ?
      fNoScroll BOOL ?
      cpPos COMPPOS <>
      wszFriendlyName WCHAR MAX_PATH dup (?)
      wszSource WCHAR INTERNET_MAX_URL_LENGTH dup (?)
      wszSubscribedURL WCHAR INTERNET_MAX_URL_LENGTH dup (?)
      dwCurItemState DWORD ?
      csiOriginal COMPSTATEINFO <>
      csiRestored COMPSTATEINFO <>
    COMPONENT ends
    _tagCOMPONENT typedef COMPONENT
    LPCOMPONENT typedef ptr COMPONENT
    LPCCOMPONENT typedef ptr COMPONENT
    IS_NORMAL equ 00000001h
    IS_FULLSCREEN equ 00000002h
    IS_SPLIT equ 00000004h
    IS_VALIDSIZESTATEBITS equ <(IS_NORMAL or IS_SPLIT or IS_FULLSCREEN)>
    IS_VALIDSTATEBITS equ (IS_NORMAL or IS_SPLIT or IS_FULLSCREEN or 80000000h or 40000000h)
    AD_APPLY_SAVE equ 00000001h
    AD_APPLY_HTMLGEN equ 00000002h
    AD_APPLY_REFRESH equ 00000004h
    AD_APPLY_ALL equ <(AD_APPLY_SAVE or AD_APPLY_HTMLGEN or AD_APPLY_REFRESH)>
    AD_APPLY_FORCE equ 00000008h
    AD_APPLY_BUFFERED_REFRESH equ 00000010h
    AD_APPLY_DYNAMICREFRESH equ 00000020h
    if (NTDDI_VERSION ge NTDDI_VISTA)
      AD_GETWP_BMP equ 00000000h
      AD_GETWP_IMAGE equ 00000001h
      AD_GETWP_LAST_APPLIED equ 00000002h
    endif
    WPSTYLE_CENTER equ 0
    WPSTYLE_TILE equ 1
    WPSTYLE_STRETCH equ 2
    if (NTDDI_VERSION ge NTDDI_WIN7)
      WPSTYLE_KEEPASPECT equ 3
      WPSTYLE_CROPTOFIT equ 4
    endif
    if (NTDDI_VERSION ge NTDDI_WIN8)
      WPSTYLE_SPAN equ 5
    endif
    if (NTDDI_VERSION ge NTDDI_WIN8)
      WPSTYLE_MAX equ 6
    elseif (NTDDI_VERSION ge NTDDI_WIN7)
      WPSTYLE_MAX equ 5
    else
      WPSTYLE_MAX equ 3
    endif
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
    tagDTI_ADTIWUI typedef SDWORD
    DTI_ADDUI_DEFAULT equ 00000000h
    DTI_ADDUI_DISPSUBWIZARD equ 00000001h
    DTI_ADDUI_POSITIONITEM equ 00000002h

    ADDURL_SILENT equ 0001h
    COMPONENT_DEFAULT_LEFT equ (0FFFFh)
    COMPONENT_DEFAULT_TOP equ (0FFFFh)
    INTERFACE equ <IActiveDesktop>
    ??Interface equ <>
    DECLARE_INTERFACE_IID_(IActiveDesktop, IUnknown, "f490eb00-1240-11d1-9888-006097deacf9")
      STDMETHOD QueryInterface, :, :ptr ptr 
      STDMETHOD_ ULONG, AddRef
      STDMETHOD_ ULONG, Release
      STDMETHOD ApplyChanges, :
      STDMETHOD GetWallpaper, :, :, :
      STDMETHOD SetWallpaper, :, :
      STDMETHOD GetWallpaperOptions, :, :
      STDMETHOD SetWallpaperOptions, :, :
      STDMETHOD GetPattern, :, :, :
      STDMETHOD SetPattern, :, :
      STDMETHOD GetDesktopItemOptions, :, :
      STDMETHOD SetDesktopItemOptions, :, :
      STDMETHOD AddDesktopItem, :, :
      STDMETHOD AddDesktopItemWithUI, :, :, :
      STDMETHOD ModifyDesktopItem, :, :
      STDMETHOD RemoveDesktopItem, :, :
      STDMETHOD GetDesktopItemCount, :ptr , :
      STDMETHOD GetDesktopItem, :, :, :
      STDMETHOD GetDesktopItemByID, :, :, :
      STDMETHOD GenerateDesktopItemHtml, :, :, :
      STDMETHOD AddUrl, :, :, :, :
      STDMETHOD GetDesktopItemBySource, :, :, :
    DECLARE_INTERFACE_IID__END

    LPACTIVEDESKTOP typedef ptr IActiveDesktop
  endif
  MAX_COLUMN_NAME_LEN equ 80
  MAX_COLUMN_DESC_LEN equ 128
  CFSTR_SHELLIDLIST equ <TEXT("Shell IDList Array")>
  CFSTR_SHELLIDLISTOFFSET equ <TEXT("Shell Object Offsets")>
  CFSTR_NETRESOURCES equ <TEXT("Net Resource")>
  CFSTR_FILEDESCRIPTORA equ <TEXT("FileGroupDescriptor")>
  CFSTR_FILEDESCRIPTORW equ <TEXT("FileGroupDescriptorW")>
  CFSTR_FILECONTENTS equ <TEXT("FileContents")>
  CFSTR_FILENAMEA equ <TEXT("FileName")>
  CFSTR_FILENAMEW equ <TEXT("FileNameW")>
  CFSTR_PRINTERGROUP equ <TEXT("PrinterFriendlyName")>
  CFSTR_FILENAMEMAPA equ <TEXT("FileNameMap")>
  CFSTR_FILENAMEMAPW equ <TEXT("FileNameMapW")>
  CFSTR_SHELLURL equ <TEXT("UniformResourceLocator")>
  CFSTR_INETURLA equ <CFSTR_SHELLURL>
  CFSTR_INETURLW equ <TEXT("UniformResourceLocatorW")>
  CFSTR_PREFERREDDROPEFFECT equ <TEXT("Preferred DropEffect")>
  CFSTR_PERFORMEDDROPEFFECT equ <TEXT("Performed DropEffect")>
  CFSTR_PASTESUCCEEDED equ <TEXT("Paste Succeeded")>
  CFSTR_INDRAGLOOP equ <TEXT("InShellDragLoop")>
  CFSTR_MOUNTEDVOLUME equ <TEXT("MountedVolume")>
  CFSTR_PERSISTEDDATAOBJECT equ <TEXT("PersistedDataObject")>
  CFSTR_TARGETCLSID equ <TEXT("TargetCLSID")>
  CFSTR_LOGICALPERFORMEDDROPEFFECT equ <TEXT("Logical Performed DropEffect")>
  CFSTR_AUTOPLAY_SHELLIDLISTS equ <TEXT("Autoplay Enumerated IDList Array")>
  CFSTR_UNTRUSTEDDRAGDROP equ <TEXT("UntrustedDragDrop")>
  CFSTR_FILE_ATTRIBUTES_ARRAY equ <TEXT("File Attributes Array")>
  CFSTR_INVOKECOMMAND_DROPPARAM equ <TEXT("InvokeCommand DropParam")>
  CFSTR_SHELLDROPHANDLER equ <TEXT("DropHandlerCLSID")>
  CFSTR_DROPDESCRIPTION equ <TEXT("DropDescription")>
  CFSTR_ZONEIDENTIFIER equ <TEXT("ZoneIdentifier")>
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
  DVASPECT_SHORTNAME equ 2
  DVASPECT_COPY equ 3
  DVASPECT_LINK equ 4
  include pshpack8.inc
  NRESARRAY struct
    cItems UINT ?
    nr NETRESOURCE 1 dup (<>)
  NRESARRAY ends
  _NRESARRAY typedef NRESARRAY
  LPNRESARRAY typedef ptr NRESARRAY
  include poppack.inc
  CIDA struct
    cidl UINT ?
    aoffset UINT 1 dup (?)
  CIDA ends
  _IDA typedef CIDA
  LPIDA typedef ptr CIDA
  FD_FLAGS typedef SDWORD
  FD_CLSID equ 00000001h
  FD_SIZEPOINT equ 00000002h
  FD_ATTRIBUTES equ 00000004h
  FD_CREATETIME equ 00000008h
  FD_ACCESSTIME equ 00000010h
  FD_WRITESTIME equ 00000020h
  FD_FILESIZE equ 00000040h
  FD_PROGRESSUI equ 00004000h
  FD_LINKUI equ 00008000h
  if (NTDDI_VERSION ge NTDDI_VISTA)
    FD_UNICODE equ 80000000h
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
    cFileName CHAR MAX_PATH dup (?)
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
    cFileName WCHAR MAX_PATH dup (?)
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
  FILEGROUPDESCRIPTORA struct
    cItems UINT ?
    fgd FILEDESCRIPTORA 1 dup (<>)
  FILEGROUPDESCRIPTORA ends
  _FILEGROUPDESCRIPTORA typedef FILEGROUPDESCRIPTORA
  LPFILEGROUPDESCRIPTORA typedef ptr FILEGROUPDESCRIPTORA
  FILEGROUPDESCRIPTORW struct
    cItems UINT ?
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
  DROPFILES struct
    pFiles DWORD ?
    pt POINT <>
    fNC BOOL ?
    fWide BOOL ?
  DROPFILES ends
  _DROPFILES typedef DROPFILES
  LPDROPFILES typedef ptr DROPFILES
  if (NTDDI_VERSION ge NTDDI_VISTA)
    FILE_ATTRIBUTES_ARRAY struct
      cItems UINT ?
      dwSumFileAttributes DWORD ?
      dwProductFileAttributes DWORD ?
      rgdwFileAttributes DWORD 1 dup (?)
    FILE_ATTRIBUTES_ARRAY ends
  endif
  if (NTDDI_VERSION ge NTDDI_VISTA)
    DROPIMAGETYPE typedef SDWORD
    DROPIMAGE_INVALID equ -1
    DROPIMAGE_NONE equ 0
    DROPIMAGE_COPY equ DROPEFFECT_COPY
    DROPIMAGE_MOVE equ DROPEFFECT_MOVE
    DROPIMAGE_LINK equ DROPEFFECT_LINK
    DROPIMAGE_LABEL equ 6
    DROPIMAGE_WARNING equ 7
    DROPIMAGE_NOIMAGE equ 8

    DROPDESCRIPTION struct
      type_ DROPIMAGETYPE ?
      szMessage WCHAR MAX_PATH dup (?)
      szInsert WCHAR MAX_PATH dup (?)
    DROPDESCRIPTION ends
  endif
  SHChangeNotifyEntry struct
    pidl PCIDLIST_ABSOLUTE ?
    fRecursive BOOL ?
  SHChangeNotifyEntry ends
  _SHChangeNotifyEntry typedef SHChangeNotifyEntry
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
  SHCNE_EXTENDED_EVENT equ 04000000h
  SHCNE_ASSOCCHANGED equ 08000000h
  SHCNE_DISKEVENTS equ 0002381Fh
  SHCNE_GLOBALEVENTS equ 0C0581E0h
  SHCNE_ALLEVENTS equ 7FFFFFFFh
  SHCNE_INTERRUPT equ 80000000h
  SHCNEE_ORDERCHANGED equ 2
  SHCNEE_MSI_CHANGE equ 4
  SHCNEE_MSI_UNINSTALL equ 5
  SHCNF_IDLIST equ 0000h
  SHCNF_PATHA equ 0001h
  SHCNF_PRINTERA equ 0002h
  SHCNF_DWORD equ 0003h
  SHCNF_PATHW equ 0005h
  SHCNF_PRINTERW equ 0006h
  SHCNF_TYPE equ 00FFh
  SHCNF_FLUSH equ 1000h
  SHCNF_FLUSHNOWAIT equ 3000h
  SHCNF_NOTIFYRECURSIVE equ 10000h
  ifdef UNICODE
    SHCNF_PATH equ <SHCNF_PATHW>
    SHCNF_PRINTER equ <SHCNF_PRINTERW>
  else
    SHCNF_PATH equ <SHCNF_PATHA>
    SHCNF_PRINTER equ <SHCNF_PRINTERA>
  endif
  @DefProto DllImport, SHChangeNotify, WIN_STD_CALL_CONV,, <:LONG, :UINT, :LPCVOID, :LPCVOID>, 16
  INTERFACE equ <IShellChangeNotify>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(IShellChangeNotify, IUnknown, "D82BE2B1-5764-11D0-A96E-00C04FD705A2")
    STDMETHOD OnChange, :, :, :
  DECLARE_INTERFACE_IID__END

  INTERFACE equ <IQueryInfo>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(IQueryInfo, IUnknown, "00021500-0000-0000-c000-000000000046")
    STDMETHOD GetInfoTip, :, :ptr 
    STDMETHOD GetInfoFlags, :ptr 
  DECLARE_INTERFACE_IID__END

  QITIPF_DEFAULT equ 00000000h
  QITIPF_USENAME equ 00000001h
  QITIPF_LINKNOTARGET equ 00000002h
  QITIPF_LINKUSETARGET equ 00000004h
  if (NTDDI_VERSION ge NTDDI_WINXP)
    QITIPF_USESLOWTIP equ 00000008h
  endif
  if (NTDDI_VERSION ge NTDDI_VISTA)
    QITIPF_SINGLELINE equ 00000010h
  endif
  QIF_CACHED equ 00000001h
  QIF_DONTEXPANDFOLDER equ 00000002h
  SHARD typedef SDWORD
  SHARD_PIDL equ 00000001h
  SHARD_PATHA equ 00000002h
  SHARD_PATHW equ 00000003h
  if (NTDDI_VERSION ge NTDDI_WIN7)
    SHARD_APPIDINFO equ 00000004h
    SHARD_APPIDINFOIDLIST equ 00000005h
    SHARD_LINK equ 00000006h
    SHARD_APPIDINFOLINK equ 00000007h
    SHARD_SHELLITEM equ 00000008h
  endif

  if (NTDDI_VERSION ge NTDDI_WIN7)
    SHARDAPPIDINFO struct
      psi POINTER ?
      pszAppID PCWSTR ?
    SHARDAPPIDINFO ends
    SHARDAPPIDINFOIDLIST struct
      pidl PCIDLIST_ABSOLUTE ?
      pszAppID PCWSTR ?
    SHARDAPPIDINFOIDLIST ends
    SHARDAPPIDINFOLINK struct
      psl POINTER ?
      pszAppID PCWSTR ?
    SHARDAPPIDINFOLINK ends
  endif
  ifdef UNICODE
    SHARD_PATH equ <SHARD_PATHW>
  else
    SHARD_PATH equ <SHARD_PATHA>
  endif
  @DefProto DllImport, SHAddToRecentDocs, WIN_STD_CALL_CONV,, <:UINT, :LPCVOID>, 8
  include pshpack1.inc
  SHChangeDWORDAsIDList struct
    cb USHORT ?
    dwItem1 DWORD ?
    dwItem2 DWORD ?
    cbZero USHORT ?
  SHChangeDWORDAsIDList ends
  _SHChangeDWORDAsIDList typedef SHChangeDWORDAsIDList
  LPSHChangeDWORDAsIDList typedef ptr SHChangeDWORDAsIDList
  include poppack.inc
  if (NTDDI_VERSION ge NTDDI_WIN2K)
    SHChangeUpdateImageIDList struct
      cb USHORT ?
      iIconIndex SDWORD ?
      iCurIndex SDWORD ?
      uFlags UINT ?
      dwProcessID DWORD ?
      szName WCHAR MAX_PATH dup (?)
      cbZero USHORT ?
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
  endif
  @DefProto DllImport, SHChangeNotifyRegister, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LONG, :UINT, :SDWORD, :ptr SHChangeNotifyEntry>, 24
  @DefProto DllImport, SHChangeNotifyDeregister, WIN_STD_CALL_CONV,, <:ULONG>, 4
  SCNRT_STATUS typedef SDWORD
  SCNRT_ENABLE equ 0
  SCNRT_DISABLE equ 1

  @DefProto DllImport, SHChangeNotification_Lock, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :ptr ptr PIDLIST_ABSOLUTE, :ptr LONG>, 16
  @DefProto DllImport, SHChangeNotification_Unlock, WIN_STD_CALL_CONV,, <:HANDLE>, 4
  @DefProto DllImport, SHGetRealIDL, WIN_STD_CALL_CONV,, <:ptr IShellFolder, :PCUITEMID_CHILD, :ptr PITEMID_CHILD>, 12
  @DefProto DllImport, SHGetInstanceExplorer, WIN_STD_CALL_CONV,, <:ptr ptr IUnknown>, 4
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
    SHDID_MOBILE_DEVICE equ 21
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
  include poppack.inc
  @DefProto DllImport, SHGetDataFromIDListA, WIN_STD_CALL_CONV,, <:ptr IShellFolder, :PCUITEMID_CHILD, :SDWORD, :ptr, :SDWORD>, 20
  @DefProto DllImport, SHGetDataFromIDListW, WIN_STD_CALL_CONV,, <:ptr IShellFolder, :PCUITEMID_CHILD, :SDWORD, :ptr, :SDWORD>, 20
  ifdef UNICODE
    SHGetDataFromIDList equ <SHGetDataFromIDListW>
  else
    SHGetDataFromIDList equ <SHGetDataFromIDListA>
  endif
  PRF_VERIFYEXISTS equ 0001h
  PRF_TRYPROGRAMEXTENSIONS equ (0002h or PRF_VERIFYEXISTS)
  PRF_FIRSTDIRDEF equ 0004h
  PRF_DONTFINDLNK equ 0008h
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
  NUM_POINTS equ 3
  AUTO_SCROLL_DATA struct
    iNextSample SDWORD ?
    dwLastScroll DWORD ?
    bFull BOOL ?
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
    CABINETSTATE_REC record CABINETSTATE_REC_Filler:16, CABINETSTATE_REC_fUnusedFlags:7, CABINETSTATE_REC_fAdminsCreateCommonGroups:1, CABINETSTATE_REC_fDontPrettyNames:1, CABINETSTATE_REC_fShowCompColor:1, CABINETSTATE_REC_fNewWindowMode:1, CABINETSTATE_REC_fDontShowDescBar:1, CABINETSTATE_REC_fSimpleDefault:1, CABINETSTATE_REC_fNotShell:1, CABINETSTATE_REC_fSaveLocalView:1, CABINETSTATE_REC_fFullPathTitle:1
    CABINETSTATE_BITS CABINETSTATE_REC <>
    fMenuEnumFilter UINT ?
  CABINETSTATE ends
  LPCABINETSTATE typedef ptr CABINETSTATE
  CABINETSTATE_VERSION equ 2
  @DefProto DllImport, ReadCabinetState, WIN_STD_CALL_CONV,, <:ptr CABINETSTATE, :SDWORD>, 8
  @DefProto DllImport, WriteCabinetState, WIN_STD_CALL_CONV,, <:ptr CABINETSTATE>, 4
  @DefProto DllImport, PathMakeUniqueName, WIN_STD_CALL_CONV,, <:PWSTR, :UINT, :PCWSTR, :PCWSTR, :PCWSTR>, 20
  @DefProto DllImport, PathIsExe, WIN_STD_CALL_CONV,, <:PCWSTR>, 4
  PCS_FATAL equ 80000000h
  PCS_REPLACEDCHAR equ 00000001h
  PCS_REMOVEDCHAR equ 00000002h
  PCS_TRUNCATED equ 00000004h
  PCS_PATHTOOLONG equ 00000008h
  @DefProto DllImport, PathCleanupSpec, WIN_STD_CALL_CONV,, <:PCWSTR, :PWSTR>, 8
  @DefProto DllImport, PathResolve, WIN_STD_CALL_CONV,, <:PWSTR, :PZPCWSTR, :UINT>, 12
  @DefProto DllImport, GetFileNameFromBrowse, WIN_STD_CALL_CONV,, <:HWND, :PWSTR, :UINT, :PCWSTR, :PCWSTR, :PCWSTR, :PCWSTR>, 28
  @DefProto DllImport, DriveType, WIN_STD_CALL_CONV,, <:SDWORD>, 4
  @DefProto DllImport, RealDriveType, WIN_STD_CALL_CONV,, <:SDWORD, :BOOL>, 8
  @DefProto DllImport, IsNetDrive, WIN_STD_CALL_CONV,, <:SDWORD>, 4
  MM_ADDSEPARATOR equ 00000001h
  MM_SUBMENUSHAVEIDS equ 00000002h
  MM_DONTREMOVESEPS equ 00000004h
  @DefProto DllImport, Shell_MergeMenus, WIN_STD_CALL_CONV,, <:HMENU, :HMENU, :UINT, :UINT, :UINT, :ULONG>, 24
  @DefProto DllImport, SHObjectProperties, WIN_STD_CALL_CONV,, <:HWND, :DWORD, :PCWSTR, :PCWSTR>, 16
  SHOP_PRINTERNAME equ 00000001h
  SHOP_FILEPATH equ 00000002h
  SHOP_VOLUMEGUID equ 00000004h
  @DefProto DllImport, SHFormatDrive, WIN_STD_CALL_CONV,, <:HWND, :UINT, :UINT, :UINT>, 16
  SHFMT_ID_DEFAULT equ 0FFFFh
  SHFMT_OPT_FULL equ 0001h
  SHFMT_OPT_SYSONLY equ 0002h
  SHFMT_ERROR equ 0FFFFFFFFh
  SHFMT_CANCEL equ 0FFFFFFFEh
  SHFMT_NOFORMAT equ 0FFFFFFFDh
  ifndef HPSXA_DEFINED
    HPSXA_DEFINED equ <>
    DECLARE_HANDLE HPSXA
  endif
  @DefProto DllImport, SHDestroyPropSheetExtArray, WIN_STD_CALL_CONV,, <:HPSXA>, 4
  @DefProto DllImport, SHAddFromPropSheetExtArray, WIN_STD_CALL_CONV,, <:HPSXA, :LPFNADDPROPSHEETPAGE, :LPARAM>, 12
  @DefProto DllImport, SHReplaceFromPropSheetExtArray, WIN_STD_CALL_CONV,, <:HPSXA, :UINT, :LPFNADDPROPSHEETPAGE, :LPARAM>, 16
  RESTRICTIONS typedef SDWORD
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
  REST_NOMOVINGBAND equ 40000017h
  REST_NOEDITDESKCOMP equ 40000018h
  REST_NORESOLVESEARCH equ 40000019h
  REST_NORESOLVETRACK equ 4000001Ah
  REST_FORCECOPYACLWITHFILE equ 4000001Bh
  if (NTDDI_VERSION lt NTDDI_VISTA)
    REST_NOLOGO3CHANNELNOTIFY equ 4000001Ch
  endif
  REST_NOFORGETSOFTWAREUPDATE equ 4000001Dh
  REST_NOSETACTIVEDESKTOP equ 4000001Eh
  REST_NOUPDATEWINDOWS equ 4000001Fh
  REST_NOCHANGESTARMENU equ 40000020h
  REST_NOFOLDEROPTIONS equ 40000021h
  REST_HASFINDCOMPUTERS equ 40000022h
  REST_INTELLIMENUS equ 40000023h
  REST_RUNDLGMEMCHECKBOX equ 40000024h
  REST_ARP_ShowPostSetup equ 40000025h
  REST_NOCSC equ 40000026h
  REST_NOCONTROLPANEL equ 40000027h
  REST_ENUMWORKGROUP equ 40000028h
  REST_ARP_NOARP equ 40000029h
  REST_ARP_NOREMOVEPAGE equ 4000002Ah
  REST_ARP_NOADDPAGE equ 4000002Bh
  REST_ARP_NOWINSETUPPAGE equ 4000002Ch
  REST_GREYMSIADS equ 4000002Dh
  REST_NOCHANGEMAPPEDDRIVELABEL equ 4000002Eh
  REST_NOCHANGEMAPPEDDRIVECOMMENT equ 4000002Fh
  REST_MaxRecentDocs equ 40000030h
  REST_NONETWORKCONNECTIONS equ 40000031h
  REST_FORCESTARTMENULOGOFF equ 40000032h
  REST_NOWEBVIEW equ 40000033h
  REST_NOCUSTOMIZETHISFOLDER equ 40000034h
  REST_NOENCRYPTION equ 40000035h
  REST_DONTSHOWSUPERHIDDEN equ 40000037h
  REST_NOSHELLSEARCHBUTTON equ 40000038h
  REST_NOHARDWARETAB equ 40000039h
  REST_NORUNASINSTALLPROMPT equ 4000003Ah
  REST_PROMPTRUNASINSTALLNETPATH equ 4000003Bh
  REST_NOMANAGEMYCOMPUTERVERB equ 4000003Ch
  REST_DISALLOWRUN equ 4000003Eh
  REST_NOWELCOMESCREEN equ 4000003Fh
  REST_RESTRICTCPL equ 40000040h
  REST_DISALLOWCPL equ 40000041h
  REST_NOSMBALLOONTIP equ 40000042h
  REST_NOSMHELP equ 40000043h
  REST_NOWINKEYS equ 40000044h
  REST_NOENCRYPTONMOVE equ 40000045h
  REST_NOLOCALMACHINERUN equ 40000046h
  REST_NOCURRENTUSERRUN equ 40000047h
  REST_NOLOCALMACHINERUNONCE equ 40000048h
  REST_NOCURRENTUSERRUNONCE equ 40000049h
  REST_FORCEACTIVEDESKTOPON equ 4000004Ah
  REST_NOVIEWONDRIVE equ 4000004Ch
  if (NTDDI_VERSION ge NTDDI_WINXP) or Defined(IE_BACKCOMPAT_VERSION)
    REST_NONETCRAWL equ 4000004Dh
    REST_NOSHAREDDOCUMENTS equ 4000004Eh
  endif
  REST_NOSMMYDOCS equ 4000004Fh
  if (NTDDI_VERSION ge NTDDI_WINXP)
    REST_NOSMMYPICS equ 40000050h
    REST_ALLOWBITBUCKDRIVES equ 40000051h
    REST_NONLEGACYSHELLMODE equ 40000052h
    REST_NOCONTROLPANELBARRICADE equ 40000053h
    REST_NOSTARTPAGE equ 40000054h
    REST_NOAUTOTRAYNOTIFY equ 40000055h
    REST_NOTASKGROUPING equ 40000056h
    REST_NOCDBURNING equ 40000057h
  endif
  if (NTDDI_VERSION ge NTDDI_WIN2KSP3)
    REST_MYCOMPNOPROP equ 40000058h
    REST_MYDOCSNOPROP equ 40000059h
  endif
  if (NTDDI_VERSION ge NTDDI_WINXP)
    REST_NOSTARTPANEL equ 4000005Ah
    REST_NODISPLAYAPPEARANCEPAGE equ 4000005Bh
    REST_NOTHEMESTAB equ 4000005Ch
    REST_NOVISUALSTYLECHOICE equ 4000005Dh
    REST_NOSIZECHOICE equ 4000005Eh
    REST_NOCOLORCHOICE equ 4000005Fh
    REST_SETVISUALSTYLE equ 40000060h
  endif
  if (NTDDI_VERSION ge NTDDI_WIN2KSP3)
    REST_STARTRUNNOHOMEPATH equ 40000061h
  endif
  if (NTDDI_VERSION ge NTDDI_WINXP)
    REST_NOUSERNAMEINSTARTPANEL equ 40000062h
    REST_NOMYCOMPUTERICON equ 40000063h
    REST_NOSMNETWORKPLACES equ 40000064h
    REST_NOSMPINNEDLIST equ 40000065h
    REST_NOSMMYMUSIC equ 40000066h
    REST_NOSMEJECTPC equ 40000067h
    REST_NOSMMOREPROGRAMS equ 40000068h
    REST_NOSMMFUPROGRAMS equ 40000069h
    REST_NOTRAYITEMSDISPLAY equ 4000006Ah
    REST_NOTOOLBARSONTASKBAR equ 4000006Bh
  endif
  if (NTDDI_VERSION ge NTDDI_WIN2KSP3)
    REST_NOSMCONFIGUREPROGRAMS equ 4000006Fh
  endif
  if (NTDDI_VERSION ge NTDDI_WINXP)
    REST_HIDECLOCK equ 40000070h
    REST_NOLOWDISKSPACECHECKS equ 40000071h
  endif
  if (NTDDI_VERSION ge NTDDI_WIN2KSP4)
    REST_NOENTIRENETWORK equ 40000072h
  endif
  if (NTDDI_VERSION ge NTDDI_WINXP)
    REST_NODESKTOPCLEANUP equ 40000073h
    REST_BITBUCKNUKEONDELETE equ 40000074h
    REST_BITBUCKCONFIRMDELETE equ 40000075h
    REST_BITBUCKNOPROP equ 40000076h
    REST_NODISPBACKGROUND equ 40000077h
    REST_NODISPSCREENSAVEPG equ 40000078h
    REST_NODISPSETTINGSPG equ 40000079h
    REST_NODISPSCREENSAVEPREVIEW equ 4000007Ah
    REST_NODISPLAYCPL equ 4000007Bh
    REST_HIDERUNASVERB equ 4000007Ch
    REST_NOTHUMBNAILCACHE equ 4000007Dh
  endif
  if (NTDDI_VERSION ge NTDDI_WINXPSP1) or Defined(IE_BACKCOMPAT_VERSION)
    REST_NOSTRCMPLOGICAL equ 4000007Eh
    REST_NOPUBLISHWIZARD equ 4000007Fh
    REST_NOONLINEPRINTSWIZARD equ 40000080h
    REST_NOWEBSERVICES equ 40000081h
  endif
  if (NTDDI_VERSION ge NTDDI_WIN2KSP3)
    REST_ALLOWUNHASHEDWEBVIEW equ 40000082h
  endif
  REST_ALLOWLEGACYWEBVIEW equ 40000083h
  if (NTDDI_VERSION ge NTDDI_WIN2KSP3)
    REST_REVERTWEBVIEWSECURITY equ 40000084h
  endif
  if (NTDDI_VERSION ge NTDDI_WIN2KSP4)
    REST_INHERITCONSOLEHANDLES equ 40000086h
  endif
  if (NTDDI_VERSION ge NTDDI_WINXPSP2 and NTDDI_VERSION lt NTDDI_VISTA)
    REST_SORTMAXITEMCOUNT equ 40000087h
  endif
  if (NTDDI_VERSION ge NTDDI_WINXPSP2)
    REST_NOREMOTERECURSIVEEVENTS equ 40000089h
  endif
  if (NTDDI_VERSION ge NTDDI_WINXPSP2)
    REST_NOREMOTECHANGENOTIFY equ 40000091h
    if (NTDDI_VERSION lt NTDDI_VISTA)
      REST_NOSIMPLENETIDLIST equ 40000092h
    endif
    REST_NOENUMENTIRENETWORK equ 40000093h
    if (NTDDI_VERSION lt NTDDI_VISTA)
      REST_NODETAILSTHUMBNAILONNETWORK equ 40000094h
    endif
    REST_NOINTERNETOPENWITH equ 40000095h
  endif
  if (NTDDI_VERSION ge NTDDI_WINXPSP2)
    REST_DONTRETRYBADNETNAME equ 4000009Bh
    REST_ALLOWFILECLSIDJUNCTIONS equ 4000009Ch
    REST_NOUPNPINSTALL equ 4000009Dh
  endif
  REST_ARP_DONTGROUPPATCHES equ 400000ACh
  REST_ARP_NOCHOOSEPROGRAMSPAGE equ 400000ADh
  REST_NODISCONNECT equ 41000001h
  REST_NOSECURITY equ 41000002h
  REST_NOFILEASSOCIATE equ 41000003h
  if (NTDDI_VERSION ge NTDDI_WINXPSP2)
    REST_ALLOWCOMMENTTOGGLE equ 41000004h
    if (NTDDI_VERSION lt NTDDI_VISTA)
      REST_USEDESKTOPINICACHE equ 41000005h
    endif
  endif

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
  @DefProto DllImport, SHStartNetConnectionDialogA, WIN_STD_CALL_CONV,, <:HWND, :LPCSTR, :DWORD>, 12
  @DefProto DllImport, SHStartNetConnectionDialogW, WIN_STD_CALL_CONV,, <:HWND, :LPCWSTR, :DWORD>, 12
  ifdef UNICODE
    SHStartNetConnectionDialog equ <SHStartNetConnectionDialogW>
  else
    SHStartNetConnectionDialog equ <SHStartNetConnectionDialogA>
  endif
  @DefProto DllImport, SHDefExtractIconA, WIN_STD_CALL_CONV,, <:LPCSTR, :SDWORD, :UINT, :ptr HICON, :ptr HICON, :UINT>, 24
  @DefProto DllImport, SHDefExtractIconW, WIN_STD_CALL_CONV,, <:LPCWSTR, :SDWORD, :UINT, :ptr HICON, :ptr HICON, :UINT>, 24
  ifdef UNICODE
    SHDefExtractIcon equ <SHDefExtractIconW>
  else
    SHDefExtractIcon equ <SHDefExtractIconA>
  endif
  tagOPEN_AS_INFO_FLAGS typedef SDWORD
  OAIF_ALLOW_REGISTRATION equ 00000001h
  OAIF_REGISTER_EXT equ 00000002h
  OAIF_EXEC equ 00000004h
  OAIF_FORCE_REGISTRATION equ 00000008h
  if (NTDDI_VERSION ge NTDDI_VISTA)
    OAIF_HIDE_REGISTRATION equ 00000020h
    OAIF_URL_PROTOCOL equ 00000040h
  endif
  if (NTDDI_VERSION ge NTDDI_WIN8)
    OAIF_FILE_IS_URI equ 00000080h
  endif

  OPEN_AS_INFO_FLAGS typedef SDWORD
  include pshpack8.inc
  OPENASINFO struct
    pcszFile LPCWSTR ?
    pcszClass LPCWSTR ?
    oaifInFlags OPEN_AS_INFO_FLAGS ?
  OPENASINFO ends
  _openasinfo typedef OPENASINFO
  POPENASINFO typedef ptr OPENASINFO
  include poppack.inc
  if (NTDDI_VERSION ge NTDDI_VISTA)
    @DefProto DllImport, SHOpenWithDialog, WIN_STD_CALL_CONV,, <:HWND, :ptr OPENASINFO>, 8
  endif
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
  endif
  VALIDATEUNC_CONNECT equ 0001h
  VALIDATEUNC_NOUI equ 0002h
  VALIDATEUNC_PRINT equ 0004h
  if (NTDDI_VERSION ge NTDDI_VISTA)
    VALIDATEUNC_PERSIST equ 0008h
    VALIDATEUNC_VALID equ 000Fh
  else
    VALIDATEUNC_VALID equ 0007h
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
  PROPPRG struct
    flPrg WORD ?
    flPrgInit WORD ?
    achTitle CHAR PIFNAMESIZE dup (?)
    achCmdLine CHAR PIFSTARTLOCSIZE + PIFPARAMSSIZE + 1 dup (?)
    achWorkDir CHAR PIFDEFPATHSIZE dup (?)
    wHotKey WORD ?
    achIconFile CHAR PIFDEFFILESIZE dup (?)
    wIconIndex WORD ?
    dwEnhModeFlags DWORD ?
    dwRealModeFlags DWORD ?
    achOtherFile CHAR PIFDEFFILESIZE dup (?)
    achPIFFile CHAR PIFMAXFILEPATH dup (?)
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
  INTERFACE equ <IShellFolderViewCB>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(IShellFolderViewCB, IUnknown, "2047E320-F2A9-11CE-AE65-08002B2E1262")
    STDMETHOD MessageSFVCB, :, :, :
  DECLARE_INTERFACE_IID__END

  include pshpack8.inc
  QCMINFO_PLACE_BEFORE equ 0
  QCMINFO_PLACE_AFTER equ 1
  QCMINFO_IDMAP_PLACEMENT struct
    id UINT ?
    fFlags UINT ?
  QCMINFO_IDMAP_PLACEMENT ends
  _QCMINFO_IDMAP_PLACEMENT typedef QCMINFO_IDMAP_PLACEMENT
  QCMINFO_IDMAP struct
    nMaxIds UINT ?
    pIdList QCMINFO_IDMAP_PLACEMENT 1 dup (<>)
  QCMINFO_IDMAP ends
  _QCMINFO_IDMAP typedef QCMINFO_IDMAP
  QCMINFO struct
    hmenu HMENU ?
    indexMenu UINT ?
    idCmdFirst UINT ?
    idCmdLast UINT ?
    pIdMap POINTER ?
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
    wszHelpFile WCHAR MAX_PATH dup (?)
    wszHelpTopic WCHAR MAX_PATH dup (?)
  SFVM_HELPTOPIC_DATA ends
  _SFVM_HELPTOPIC_DATA typedef SFVM_HELPTOPIC_DATA
  SFVM_MERGEMENU equ 1
  SFVM_INVOKECOMMAND equ 2
  SFVM_GETHELPTEXT equ 3
  SFVM_GETTOOLTIPTEXT equ 4
  SFVM_GETBUTTONINFO equ 5
  SFVM_GETBUTTONS equ 6
  SFVM_INITMENUPOPUP equ 7
  SFVM_FSNOTIFY equ 14
  SFVM_WINDOWCREATED equ 15
  SFVM_GETDETAILSOF equ 23
  SFVM_COLUMNCLICK equ 24
  SFVM_QUERYFSNOTIFY equ 25
  SFVM_DEFITEMCOUNT equ 26
  SFVM_DEFVIEWMODE equ 27
  SFVM_UNMERGEMENU equ 28
  SFVM_UPDATESTATUSBAR equ 31
  SFVM_BACKGROUNDENUM equ 32
  SFVM_DIDDRAGDROP equ 36
  SFVM_SETISFV equ 39
  SFVM_THISIDLIST equ 41
  SFVM_ADDPROPERTYPAGES equ 47
  SFVM_BACKGROUNDENUMDONE equ 48
  SFVM_GETNOTIFY equ 49
  SFVM_GETSORTDEFAULTS equ 53
  SFVM_SIZE equ 57
  SFVM_GETZONE equ 58
  SFVM_GETPANE equ 59
  SFVM_GETHELPTOPIC equ 63
  SFVM_GETANIMATION equ 68
  ITEMSPACING struct
    cxSmall SDWORD ?
    cySmall SDWORD ?
    cxLarge SDWORD ?
    cyLarge SDWORD ?
  ITEMSPACING ends
  _ITEMSPACING typedef ITEMSPACING
  SFVSOC_INVALIDATE_ALL equ 00000001h
  SFVSOC_NOSCROLL equ <LVSICF_NOSCROLL>
  SFVS_SELECT_NONE equ 0h
  SFVS_SELECT_ALLITEMS equ 1h
  SFVS_SELECT_INVERT equ 2h
  INTERFACE equ <IShellFolderView>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(IShellFolderView, IUnknown, "37A378C0-F82D-11CE-AE65-08002B2E1262")
    STDMETHOD Rearrange, :
    STDMETHOD GetArrangeParam, :ptr 
    STDMETHOD ArrangeGrid
    STDMETHOD AutoArrange
    STDMETHOD GetAutoArrange
    STDMETHOD AddObject, :, :ptr 
    STDMETHOD GetObject, :ptr , :
    STDMETHOD RemoveObject, :, :ptr 
    STDMETHOD GetObjectCount, :ptr 
    STDMETHOD SetObjectCount, :, :
    STDMETHOD UpdateObject, :, :, :ptr 
    STDMETHOD RefreshObject, :, :ptr 
    STDMETHOD SetRedraw, :
    STDMETHOD GetSelectedCount, :ptr 
    STDMETHOD GetSelectedObjects, :ptr ptr , :ptr 
    STDMETHOD IsDropOnSource, :ptr 
    STDMETHOD GetDragPoint, :ptr 
    STDMETHOD GetDropPoint, :ptr 
    STDMETHOD MoveIcons, :ptr 
    STDMETHOD SetItemPos, :, :ptr 
    STDMETHOD IsBkDropTarget, :ptr 
    STDMETHOD SetClipboard, :
    STDMETHOD SetPoints, :ptr 
    STDMETHOD GetItemSpacing, :ptr 
    STDMETHOD SetCallback, :ptr , :ptr ptr 
    STDMETHOD Select, :
    STDMETHOD QuerySupport, :ptr 
    STDMETHOD SetAutomationObject, :ptr 
  DECLARE_INTERFACE_IID__END

  SFV_CREATE struct
    cbSize UINT ?
    pshf POINTER ?
    psvOuter POINTER ?
    psfvcb POINTER ?
  SFV_CREATE ends
  _SFV_CREATE typedef SFV_CREATE
  @DefProto DllImport, SHCreateShellFolderView, WIN_STD_CALL_CONV,, <:ptr SFV_CREATE, :ptr ptr IShellView>, 8
  TYPE_LPFNDFMCALLBACK typedef proto WIN_STD_CALL_CONV :ptr IShellFolder, :HWND, :ptr IDataObject, :UINT, :WPARAM, :LPARAM
  LPFNDFMCALLBACK typedef ptr TYPE_LPFNDFMCALLBACK

  @DefProto DllImport, CDefFolderMenu_Create2, WIN_STD_CALL_CONV,, <:PCIDLIST_ABSOLUTE, :HWND, :UINT, :PCUITEMID_CHILD_ARRAY, :ptr IShellFolder, :LPFNDFMCALLBACK, :UINT, :ptr HKEY, :ptr ptr IContextMenu>, 36
  DEFCONTEXTMENU struct
    hwnd HWND ?
    pcmcb POINTER ?
    pidlFolder PCIDLIST_ABSOLUTE ?
    psf POINTER ?
    cidl UINT ?
    apidl PCUITEMID_CHILD_ARRAY ?
    punkAssociationInfo POINTER ?
    cKeys UINT ?
    aKeys POINTER ?
  DEFCONTEXTMENU ends
  if (NTDDI_VERSION ge NTDDI_VISTA)
    @DefProto DllImport, SHCreateDefaultContextMenu, WIN_STD_CALL_CONV,, <:ptr DEFCONTEXTMENU, :REFIID, :ptr ptr>, 12
  endif
  DFMICS struct
    cbSize DWORD ?
    fMask DWORD ?
    lParam LPARAM ?
    idCmdFirst UINT ?
    idDefMax UINT ?
    pici LPCMINVOKECOMMANDINFO ?
    if (NTDDI_VERSION ge NTDDI_VISTA)
      punkSite POINTER ?
    endif
  DFMICS ends
  PDFMICS typedef ptr DFMICS
  DFM_MERGECONTEXTMENU equ 1
  DFM_INVOKECOMMAND equ 2
  DFM_GETHELPTEXT equ 5
  DFM_WM_MEASUREITEM equ 6
  DFM_WM_DRAWITEM equ 7
  DFM_WM_INITMENUPOPUP equ 8
  DFM_VALIDATECMD equ 9
  DFM_MERGECONTEXTMENU_TOP equ 10
  DFM_GETHELPTEXTW equ 11
  DFM_INVOKECOMMANDEX equ 12
  DFM_MAPCOMMANDNAME equ 13
  DFM_GETDEFSTATICID equ 14
  DFM_GETVERBW equ 15
  DFM_GETVERBA equ 16
  DFM_MERGECONTEXTMENU_BOTTOM equ 17
  DFM_MODIFYQCMFLAGS equ 18
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

  CSFV struct
    cbSize UINT ?
    pshf POINTER ?
    psvOuter POINTER ?
    pidl PCIDLIST_ABSOLUTE ?
    lEvents LONG ?
    pfnCallback LPFNVIEWCALLBACK ?
    fvm FOLDERVIEWMODE ?
  CSFV ends
  _CSFV typedef CSFV
  LPCSFV typedef ptr CSFV
  include poppack.inc
  @DefProto DllImport, SHFind_InitMenuPopup, WIN_STD_CALL_CONV,, <:HMENU, :HWND, :UINT, :UINT>, 16
  @DefProto DllImport, SHCreateShellFolderViewEx, WIN_STD_CALL_CONV,, <:ptr CSFV, :ptr ptr IShellView>, 8
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
  PIDISF_RECENTLYCHANGED equ 00000001h
  PIDISF_CACHEDSTICKY equ 00000002h
  PIDISF_CACHEIMAGES equ 00000010h
  PIDISF_FOLLOWALLLINKS equ 00000020h
  PIDISM_GLOBAL equ 0
  PIDISM_WATCH equ 1
  PIDISM_DONTWATCH equ 2
  PIDISR_UP_TO_DATE equ 0
  PIDISR_NEEDS_ADD equ 1
  PIDISR_NEEDS_UPDATE equ 2
  PIDISR_NEEDS_DELETE equ 3
  SHELLSTATEA struct
    SHELLSTATEA_REC record SHELLSTATEA_REC_Filler:15, SHELLSTATEA_REC_fNoNetCrawling:1, SHELLSTATEA_REC_fShowSuperHidden:1, SHELLSTATEA_REC_fFilter:1, SHELLSTATEA_REC_fWebView:1, SHELLSTATEA_REC_fHideIcons:1, SHELLSTATEA_REC_fShowInfoTip:1, SHELLSTATEA_REC_fMapNetDrvBtn:1, SHELLSTATEA_REC_fShowAttribCol:1, SHELLSTATEA_REC_fDontPrettyPath:1, SHELLSTATEA_REC_fWin95Classic:1, SHELLSTATEA_REC_fDesktopHTML:1, SHELLSTATEA_REC_fDoubleClickInWebView:1, SHELLSTATEA_REC_fShowCompColor:1, SHELLSTATEA_REC_fShowSysFiles:1, SHELLSTATEA_REC_fNoConfirmRecycle:1, SHELLSTATEA_REC_fShowExtensions:1, SHELLSTATEA_REC_fShowAllObjects:1
    SHELLSTATEA_BITS SHELLSTATEA_REC <>
    dwWin95Unused DWORD ?
    uWin95Unused UINT ?
    lParamSort LONG ?
    iSortDirection SDWORD ?
    version UINT ?
    uNotUsed UINT ?
    SHELLSTATEA_REC record SHELLSTATEA_REC_Filler:16, SHELLSTATEA_REC_fSpareFlags:9, SHELLSTATEA_REC_fShowStatusBar:1, SHELLSTATEA_REC_fShowTypeOverlay:1, SHELLSTATEA_REC_fIconsOnly:1, SHELLSTATEA_REC_fAutoCheckSelect:1, SHELLSTATEA_REC_fShowStartPage:1, SHELLSTATEA_REC_fStartPanelOn:1, SHELLSTATEA_REC_fSepProcess:1
    SHELLSTATEA_BITS SHELLSTATEA_REC <>
  SHELLSTATEA ends
  LPSHELLSTATEA typedef ptr SHELLSTATEA
  SHELLSTATEW struct
    SHELLSTATEW_REC record SHELLSTATEW_REC_Filler:15, SHELLSTATEW_REC_fNoNetCrawling:1, SHELLSTATEW_REC_fShowSuperHidden:1, SHELLSTATEW_REC_fFilter:1, SHELLSTATEW_REC_fWebView:1, SHELLSTATEW_REC_fHideIcons:1, SHELLSTATEW_REC_fShowInfoTip:1, SHELLSTATEW_REC_fMapNetDrvBtn:1, SHELLSTATEW_REC_fShowAttribCol:1, SHELLSTATEW_REC_fDontPrettyPath:1, SHELLSTATEW_REC_fWin95Classic:1, SHELLSTATEW_REC_fDesktopHTML:1, SHELLSTATEW_REC_fDoubleClickInWebView:1, SHELLSTATEW_REC_fShowCompColor:1, SHELLSTATEW_REC_fShowSysFiles:1, SHELLSTATEW_REC_fNoConfirmRecycle:1, SHELLSTATEW_REC_fShowExtensions:1, SHELLSTATEW_REC_fShowAllObjects:1
    SHELLSTATEW_BITS SHELLSTATEW_REC <>
    dwWin95Unused DWORD ?
    uWin95Unused UINT ?
    lParamSort LONG ?
    iSortDirection SDWORD ?
    version UINT ?
    uNotUsed UINT ?
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
  SHELLFLAGSTATE struct
    SHELLFLAGSTATE_REC record SHELLFLAGSTATE_REC_Filler:19, SHELLFLAGSTATE_REC_fHideIcons:1, SHELLFLAGSTATE_REC_fShowInfoTip:1, SHELLFLAGSTATE_REC_fMapNetDrvBtn:1, SHELLFLAGSTATE_REC_fShowAttribCol:1, SHELLFLAGSTATE_REC_fDontPrettyPath:1, SHELLFLAGSTATE_REC_fWin95Classic:1, SHELLFLAGSTATE_REC_fDesktopHTML:1, SHELLFLAGSTATE_REC_fDoubleClickInWebView:1, SHELLFLAGSTATE_REC_fShowCompColor:1, SHELLFLAGSTATE_REC_fShowSysFiles:1, SHELLFLAGSTATE_REC_fNoConfirmRecycle:1, SHELLFLAGSTATE_REC_fShowExtensions:1, SHELLFLAGSTATE_REC_fShowAllObjects:1
    SHELLFLAGSTATE_BITS SHELLFLAGSTATE_REC <>
    if (NTDDI_VERSION ge NTDDI_VISTA)
      SHELLFLAGSTATE_REC record SHELLFLAGSTATE_REC_Filler:29, SHELLFLAGSTATE_REC_fRestFlags:1, SHELLFLAGSTATE_REC_fIconsOnly:1, SHELLFLAGSTATE_REC_fAutoCheckSelect:1
      SHELLFLAGSTATE_BITS SHELLFLAGSTATE_REC <>
    else
      SHELLFLAGSTATE_REC record SHELLFLAGSTATE_REC_Filler:29, SHELLFLAGSTATE_REC_fRestFlags:3
      SHELLFLAGSTATE_BITS SHELLFLAGSTATE_REC <>
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
  if (NTDDI_VERSION ge NTDDI_VISTA)
    SSF_AUTOCHECKSELECT equ 00800000h
    SSF_ICONSONLY equ 01000000h
    SSF_SHOWTYPEOVERLAY equ 02000000h
  endif
  if (NTDDI_VERSION ge NTDDI_WIN8)
    SSF_SHOWSTATUSBAR equ 04000000h
  endif
  @DefProto DllImport, SHGetSettings, WIN_STD_CALL_CONV,, <:ptr SHELLFLAGSTATE, :DWORD>, 8
  @DefProto DllImport, SHBindToParent, WIN_STD_CALL_CONV,, <:PCIDLIST_ABSOLUTE, :REFIID, :ptr ptr, :ptr PCUITEMID_CHILD>, 16
  if (NTDDI_VERSION ge NTDDI_VISTA)
    @DefProto DllImport, SHBindToFolderIDListParent, WIN_STD_CALL_CONV,, <:ptr IShellFolder, :PCUIDLIST_RELATIVE, :REFIID, :ptr ptr, :ptr PCUITEMID_CHILD>, 20
    @DefProto DllImport, SHBindToFolderIDListParentEx, WIN_STD_CALL_CONV,, <:ptr IShellFolder, :PCUIDLIST_RELATIVE, :ptr IBindCtx, :REFIID, :ptr ptr, :ptr PCUITEMID_CHILD>, 24
    @DefProto DllImport, SHBindToObject, WIN_STD_CALL_CONV,, <:ptr IShellFolder, :PCUIDLIST_RELATIVE, :ptr IBindCtx, :REFIID, :ptr ptr>, 20
  endif
  IDListContainerIsConsistent proto WIN_STD_CALL_CONV :PCUIDLIST_RELATIVE, :UINT
  if (NTDDI_VERSION ge NTDDI_WINXP)
    @DefProto DllImport, SHParseDisplayName, WIN_STD_CALL_CONV,, <:PCWSTR, :ptr IBindCtx, :ptr PIDLIST_ABSOLUTE, :SFGAOF, :ptr SFGAOF>, 20
  endif
  SHPPFW_NONE equ 00000000h
  SHPPFW_DEFAULT equ <SHPPFW_DIRCREATE>
  SHPPFW_DIRCREATE equ 00000001h
  SHPPFW_ASKDIRCREATE equ 00000002h
  SHPPFW_IGNOREFILENAME equ 00000004h
  SHPPFW_NOWRITECHECK equ 00000008h
  if (NTDDI_VERSION ge NTDDI_WINXP)
    SHPPFW_MEDIACHECKONLY equ 00000010h
  endif
  @DefProto DllImport, SHPathPrepareForWriteA, WIN_STD_CALL_CONV,, <:HWND, :ptr IUnknown, :LPCSTR, :DWORD>, 16
  @DefProto DllImport, SHPathPrepareForWriteW, WIN_STD_CALL_CONV,, <:HWND, :ptr IUnknown, :LPCWSTR, :DWORD>, 16
  ifdef UNICODE
    SHPathPrepareForWrite equ <SHPathPrepareForWriteW>
  else
    SHPathPrepareForWrite equ <SHPathPrepareForWriteA>
  endif
  INTERFACE equ <INamedPropertyBag>
  ??Interface equ <>
  DECLARE_INTERFACE_IID_(INamedPropertyBag, IUnknown, "FB700430-952C-11d1-946F-000000000000")
    STDMETHOD ReadPropertyNPB, :, :, :ptr 
    STDMETHOD WritePropertyNPB, :, :, :ptr 
    STDMETHOD RemovePropertyNPB, :, :
  DECLARE_INTERFACE_IID__END

  @DefProto DllImport, SHPropStgCreate, WIN_STD_CALL_CONV,, <:ptr IPropertySetStorage, :REFFMTID, :ptr CLSID, :DWORD, :DWORD, :DWORD, :ptr ptr IPropertyStorage, :ptr UINT>, 32
  @DefProto DllImport, SHPropStgReadMultiple, WIN_STD_CALL_CONV,, <:ptr IPropertyStorage, :UINT, :ULONG, :ptr PROPSPEC, :ptr PROPVARIANT>, 20
  @DefProto DllImport, SHPropStgWriteMultiple, WIN_STD_CALL_CONV,, <:ptr IPropertyStorage, :ptr UINT, :ULONG, :ptr PROPSPEC, :ptr PROPVARIANT, :PROPID>, 24
  if (NTDDI_VERSION ge NTDDI_WINXP)
    @DefProto DllImport, SHCreateFileExtractIconA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :REFIID, :ptr ptr>, 16
    @DefProto DllImport, SHCreateFileExtractIconW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :REFIID, :ptr ptr>, 16
    ifdef UNICODE
      SHCreateFileExtractIcon equ <SHCreateFileExtractIconW>
    else
      SHCreateFileExtractIcon equ <SHCreateFileExtractIconA>
    endif
    @DefProto DllImport, SHLimitInputEdit, WIN_STD_CALL_CONV,, <:HWND, :ptr IShellFolder>, 8
    @DefProto DllImport, SHGetAttributesFromDataObject, WIN_STD_CALL_CONV,, <:ptr IDataObject, :DWORD, :ptr DWORD, :ptr UINT>, 16
  endif
  @DefProto DllImport, SHMapPIDLToSystemImageListIndex, WIN_STD_CALL_CONV,, <:ptr IShellFolder, :PCUITEMID_CHILD, :ptr SDWORD>, 12
  @DefProto DllImport, SHCLSIDFromString, WIN_STD_CALL_CONV,, <:PCWSTR, :ptr CLSID>, 8
  @DefProto DllImport, PickIconDlg, WIN_STD_CALL_CONV,, <:HWND, :PWSTR, :UINT, :ptr SDWORD>, 16
  if (NTDDI_VERSION ge NTDDI_WIN7)
    @DefProto DllImport, StgMakeUniqueName, WIN_STD_CALL_CONV,, <:ptr IStorage, :PCWSTR, :DWORD, :REFIID, :ptr ptr>, 20
  endif
  if (_WIN32_IE ge _WIN32_IE_IE70)
    IESHORTCUTFLAGS typedef SDWORD
    IESHORTCUT_NEWBROWSER equ 01h
    IESHORTCUT_OPENNEWTAB equ 02h
    IESHORTCUT_FORCENAVIGATE equ 04h
    IESHORTCUT_BACKGROUNDTAB equ 08h
    tagIESHORTCUTFLAGS typedef IESHORTCUTFLAGS

  endif
  include poppack.inc
  ifdef __cplusplus
    ;[...]
  endif
endif
