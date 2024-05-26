;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\shlguid.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 21/02/2024 18:17:24

include winapifamily.inc
if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
  DEFINE_GUID CLSID_NetworkDomain, 46e06680h, 4bf0h, 11d1h, 83h, 0eeh, 00h, 0a0h, 0c9h, 0dh, 0c8h, 49h
  DEFINE_GUID CLSID_NetworkServer, 0c0542a90h, 4bf0h, 11d1h, 83h, 0eeh, 00h, 0a0h, 0c9h, 0dh, 0c8h, 49h
  DEFINE_GUID CLSID_NetworkShare, 54a754c0h, 4bf0h, 11d1h, 83h, 0eeh, 00h, 0a0h, 0c9h, 0dh, 0c8h, 49h
  DEFINE_GUID CLSID_MyComputer, 20D04FE0h, 3AEAh, 1069h, 0A2h, 0D8h, 08h, 00h, 2Bh, 30h, 30h, 9Dh
  DEFINE_GUID CLSID_Internet, 871C5380h, 42A0h, 1069h, 0A2h, 0EAh, 08h, 00h, 2Bh, 30h, 30h, 9Dh
  DEFINE_GUID CLSID_RecycleBin, 645FF040h, 5081h, 101Bh, 9Fh, 08h, 00h, 0AAh, 00h, 2Fh, 95h, 4Eh
  DEFINE_GUID CLSID_ControlPanel, 21EC2020h, 3AEAh, 1069h, 0A2h, 0DDh, 08h, 00h, 2Bh, 30h, 30h, 9Dh
  DEFINE_GUID CLSID_Printers, 2227A280h, 3AEAh, 1069h, 0A2h, 0DEh, 08h, 00h, 2Bh, 30h, 30h, 9Dh
  DEFINE_GUID CLSID_MyDocuments, 450d8fbah, 0ad25h, 11d0h, 98h, 0a8h, 08h, 00h, 36h, 1bh, 11h, 03h
  STR_MYDOCS_CLSID equ <"{450D8FBA-AD25-11D0-98A8-0800361B1103}">
  DEFINE_GUID CATID_BrowsableShellExt, 00021490h, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID CATID_BrowseInPlace, 00021491h, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID CATID_DeskBand, 00021492h, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID CATID_InfoBand, 00021493h, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID CATID_CommBand, 00021494h, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  PSGUID_INTERNETSHORTCUT equ { 000214A0h, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h }
  DEFINE_GUID FMTID_Intshcut, 000214A0h, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  PSGUID_INTERNETSITE equ { 000214A1h, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h }
  DEFINE_GUID FMTID_InternetSite, 000214A1h, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID CGID_Explorer, 000214D0h, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID CGID_ShellDocView, 000214D1h, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID CGID_ShellServiceObject, 000214D2h, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID CGID_ExplorerBarDoc, 000214D3h, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID IID_INewShortcutHookA, 000214E1h, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID IID_IShellBrowser, 000214E2h, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID IID_IShellView, 000214E3h, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID IID_IContextMenu, 000214E4h, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID IID_IShellIcon, 000214E5h, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID IID_IShellFolder, 000214E6h, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID IID_IShellExtInit, 000214E8h, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID IID_IShellPropSheetExt, 000214E9h, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID IID_IPersistFolder, 000214EAh, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID IID_IExtractIconA, 000214EBh, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID IID_IShellDetails, 000214ECh, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID IID_IShellLinkA, 000214EEh, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID IID_ICopyHookA, 000214EFh, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID IID_IFileViewerA, 000214F0h, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID IID_ICommDlgBrowser, 000214F1h, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID IID_IEnumIDList, 000214F2h, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID IID_IFileViewerSite, 000214F3h, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID IID_IContextMenu2, 000214F4h, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID IID_IShellExecuteHookA, 000214F5h, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID IID_IPropSheetPage, 000214F6h, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID IID_INewShortcutHookW, 000214F7h, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID IID_IFileViewerW, 000214F8h, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID IID_IShellLinkW, 000214F9h, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID IID_IExtractIconW, 000214FAh, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID IID_IShellExecuteHookW, 000214FBh, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID IID_ICopyHookW, 000214FCh, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID IID_IRemoteComputer, 000214FEh, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  IID_IShellCopyHookA equ <IID_ICopyHookA>
  IID_IShellCopyHookW equ <IID_ICopyHookW>
  SID_LinkSite equ <IID_IShellLinkW>
  DEFINE_GUID IID_IQueryInfo, 00021500h, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID IID_IBriefcaseStg, 8BCE1FA1h, 0921h, 101Bh, 0B1h, 0FFh, 00h, 0DDh, 01h, 0Ch, 0CCh, 48h
  DEFINE_GUID IID_IShellView2, 88E39E80h, 3578h, 11CFh, 0AEh, 69h, 08h, 00h, 2Bh, 2Eh, 12h, 62h
  DEFINE_GUID IID_IURLSearchHook, 0AC60F6A0h, 0FD9h, 11D0h, 99h, 0CBh, 00h, 0C0h, 4Fh, 0D6h, 44h, 97h
  DEFINE_GUID IID_ISearchContext, 09F656A2h, 41AFh, 480Ch, 88h, 0F7h, 16h, 0CCh, 0Dh, 16h, 46h, 15h
  DEFINE_GUID IID_IURLSearchHook2, 5ee44da4h, 6d32h, 46e3h, 86h, 0bch, 07h, 54h, 0dh, 0edh, 0d0h, 0e0h
  DEFINE_GUID IID_IDefViewID, 985F64F0h, 0D410h, 4E02h, 0BEh, 22h, 0DAh, 07h, 0F2h, 0B5h, 0C5h, 0E1h
  IDefViewID equ <IUnknown>
  DEFINE_GUID CLSID_FolderShortcut, 0AFACED1h, 0E828h, 11D1h, 91h, 87h, 0B5h, 32h, 0F1h, 0E9h, 57h, 5Dh
  DEFINE_GUID IID_IDockingWindowSite, 2a342fc2h, 7b26h, 11d0h, 8ch, 0a9h, 0h, 0a0h, 0c9h, 2dh, 0bfh, 0e8h
  DEFINE_GUID IID_IDockingWindowFrame, 47d2657ah, 7b27h, 11d0h, 8ch, 0a9h, 0h, 0a0h, 0c9h, 2dh, 0bfh, 0e8h
  DEFINE_GUID IID_IShellIconOverlay, 7D688A70h, 0C613h, 11D0h, 99h, 9Bh, 00h, 0C0h, 4Fh, 0D6h, 55h, 0E1h
  DEFINE_GUID IID_IShellIconOverlayIdentifier, 0C6C4200h, 0C589h, 11D0h, 99h, 9Ah, 00h, 0C0h, 4Fh, 0D6h, 55h, 0E1h
  DEFINE_GUID IID_ICommDlgBrowser2, 10339516h, 2894h, 11d2h, 90h, 39h, 0h, 0c0h, 4fh, 8eh, 0ebh, 3eh
  DEFINE_GUID IID_IShellFolderViewCB, 2047E320h, 0F2A9h, 11CEh, 0AEh, 65h, 08h, 00h, 2Bh, 2Eh, 12h, 62h
  SID_ShellFolderViewCB equ <IID_IShellFolderViewCB>
  DEFINE_GUID CLSID_CFSIconOverlayManager, 63B51F81h, 0C868h, 11D0h, 99h, 9Ch, 00h, 0C0h, 4Fh, 0D6h, 55h, 0E1h
  DEFINE_GUID IID_IShellIconOverlayManager, 0f10b5e34h, 0dd3bh, 42a7h, 0aah, 7dh, 2fh, 4eh, 0c5h, 4bh, 0b0h, 9bh
  DEFINE_GUID IID_IThumbnailCapture, 4ea39266h, 7211h, 409fh, 0b6h, 22h, 0f6h, 3dh, 0bdh, 16h, 0c5h, 33h
  DEFINE_GUID IID_IShellImageStore, 48c8118ch, 0b924h, 11d1h, 98h, 0d5h, 0h, 0c0h, 4fh, 0b6h, 87h, 0dah
  if (NTDDI_VERSION lt NTDDI_VISTA)
    DEFINE_GUID CLSID_ShellThumbnailDiskCache, 1ebdcf80h, 0a200h, 11d0h, 0a3h, 0a4h, 0h, 0c0h, 4fh, 0d7h, 6h, 0ech
  endif
  DEFINE_GUID IID_IContextMenu3, 0bcfce0a0h, 0ec17h, 11d0h, 8dh, 10h, 0h, 0a0h, 0c9h, 0fh, 27h, 19h
  DEFINE_GUID SID_DefView, 6D12FE80h, 7911h, 11CFh, 95h, 34h, 00h, 00h, 0C0h, 5Bh, 0AEh, 0Bh
  DEFINE_GUID CGID_DefView, 4af07f10h, 0d231h, 11d0h, 0b9h, 42h, 0h, 0a0h, 0c9h, 3h, 12h, 0e1h
  DEFINE_GUID CLSID_MenuBand, 5b4dae26h, 0b807h, 11d0h, 98h, 15h, 0h, 0c0h, 4fh, 0d9h, 19h, 72h
  DEFINE_GUID IID_IShellFolderBand, 7fe80cc8h, 0c247h, 11d0h, 0b9h, 3ah, 0h, 0a0h, 0c9h, 3h, 12h, 0e1h
  DEFINE_GUID IID_IDefViewFrame, 710EB7A0h, 45EDh, 11D0h, 92h, 4Ah, 00h, 20h, 0AFh, 0C7h, 0ACh, 4Dh
  DEFINE_GUID VID_LargeIcons, 0057D0E0h, 3573h, 11CFh, 0AEh, 69h, 08h, 00h, 2Bh, 2Eh, 12h, 62h
  DEFINE_GUID VID_SmallIcons, 089000C0h, 3573h, 11CFh, 0AEh, 69h, 08h, 00h, 2Bh, 2Eh, 12h, 62h
  DEFINE_GUID VID_List, 0E1FA5E0h, 3573h, 11CFh, 0AEh, 69h, 08h, 00h, 2Bh, 2Eh, 12h, 62h
  DEFINE_GUID VID_Details, 137E7700h, 3573h, 11CFh, 0AEh, 69h, 08h, 00h, 2Bh, 2Eh, 12h, 62h
  DEFINE_GUID VID_Tile, 65f125e5h, 7be1h, 4810h, 0bah, 9dh, 0d2h, 71h, 0c8h, 43h, 2ch, 0e3h
  DEFINE_GUID VID_Content, 30c2c434h, 0889h, 4c8dh, 98h, 5dh, 0a9h, 0f7h, 18h, 30h, 0b0h, 0a9h
  DEFINE_GUID VID_Thumbnails, 8bebb290h, 52d0h, 11d0h, 0b7h, 0f4h, 0h, 0c0h, 4fh, 0d7h, 6h, 0ech
  DEFINE_GUID VID_ThumbStrip, 8EEFA624h, 0D1E9h, 445Bh, 94h, 0B7h, 74h, 0FBh, 0CEh, 2Eh, 0A1h, 1Ah
  SID_SShellBrowser equ <IID_IShellBrowser>
  SID_SShellDesktop equ <CLSID_ShellDesktop>
  DEFINE_GUID SID_SInPlaceBrowser, 1D2AE02Bh, 3655h, 46CCh, 0B6h, 3Ah, 28h, 59h, 88h, 15h, 3Bh, 0CAh
  if (NTDDI_VERSION ge NTDDI_WIN7)
    DEFINE_GUID SID_SSearchBoxInfo, 142daa61h, 516bh, 4713h, 0b4h, 9ch, 0fbh, 98h, 5eh, 0f8h, 29h, 98h
    DEFINE_GUID SID_CommandsPropertyBag, 6e043250h, 4416h, 485ch, 0b1h, 43h, 0e6h, 2ah, 76h, 0dh, 9fh, 0e5h
  endif
  DEFINE_GUID IID_IDiscardableBrowserProperty, 49c3de7ch, 0d329h, 11d0h, 0abh, 73h, 00h, 0c0h, 4fh, 0c3h, 3eh, 80h
  DEFINE_GUID IID_IShellChangeNotify, 0D82BE2B1h, 5764h, 11D0h, 0A9h, 6Eh, 00h, 0C0h, 4Fh, 0D7h, 05h, 0A2h
  ifdef UNICODE
    IID_IFileViewer equ <IID_IFileViewerW>
    IID_IShellLink equ <IID_IShellLinkW>
    IID_IExtractIcon equ <IID_IExtractIconW>
    IID_IShellCopyHook equ <IID_IShellCopyHookW>
    IID_IShellExecuteHook equ <IID_IShellExecuteHookW>
    IID_INewShortcutHook equ <IID_INewShortcutHookW>
  else
    IID_IFileViewer equ <IID_IFileViewerA>
    IID_IShellLink equ <IID_IShellLinkA>
    IID_IExtractIcon equ <IID_IExtractIconA>
    IID_IShellCopyHook equ <IID_IShellCopyHookA>
    IID_IShellExecuteHook equ <IID_IShellExecuteHookA>
    IID_INewShortcutHook equ <IID_INewShortcutHookA>
  endif
  ifndef NO_INTSHCUT_GUIDS
    include isguids.inc
  endif
  ifndef NO_SHDOCVW_GUIDS
    ifndef GUID_DEFS_ONLY
      include exdisp.inc
      include shldisp.inc
    endif
    externdef CLSID_CUrlHistory:GUID
    SID_SUrlHistory equ <CLSID_CUrlHistory>
    externdef CLSID_CUrlHistoryBoth:GUID
    DEFINE_GUID CLSID_CURLSearchHook, 0CFBFAE00h, 17A6h, 11D0h, 99h, 0CBh, 00h, 0C0h, 4Fh, 0D6h, 44h, 97h
    SID_SInternetExplorer equ <IID_IWebBrowserApp>
    SID_SWebBrowserApp equ <IID_IWebBrowserApp>
    SID_SWebBrowserEventsService equ <IID_IWebBrowserEventsService>
    DEFINE_GUID IID_IObjMgr, 00BB2761h, 6A77h, 11D0h, 0A5h, 35h, 00h, 0C0h, 4Fh, 0D7h, 0D0h, 62h
    DEFINE_GUID IID_IACList, 77A130B0h, 94FDh, 11D0h, 0A5h, 44h, 00h, 0C0h, 4Fh, 0D7h, 0d0h, 62h
    DEFINE_GUID IID_IACList2, 470141a0h, 5186h, 11d2h, 0bbh, 0b6h, 00h, 60h, 97h, 7bh, 46h, 4ch
    DEFINE_GUID IID_ICurrentWorkingDirectory, 91956d21h, 9276h, 11d1h, 92h, 1ah, 00h, 60h, 97h, 0dfh, 5bh, 0d4h
    DEFINE_GUID CLSID_AutoComplete, 00BB2763h, 6A77h, 11D0h, 0A5h, 35h, 00h, 0C0h, 4Fh, 0D7h, 0D0h, 62h
    DEFINE_GUID CLSID_ACLHistory, 00BB2764h, 6A77h, 11D0h, 0A5h, 35h, 00h, 0C0h, 4Fh, 0D7h, 0D0h, 62h
    DEFINE_GUID CLSID_ACListISF, 03C036F1h, 0A186h, 11D0h, 82h, 4Ah, 00h, 0AAh, 00h, 5Bh, 43h, 83h
    DEFINE_GUID CLSID_ACLMRU, 6756a641h, 0de71h, 11d0h, 83h, 1bh, 0h, 0aah, 0h, 5bh, 43h, 83h
    DEFINE_GUID CLSID_ACLMulti, 00BB2765h, 6A77h, 11D0h, 0A5h, 35h, 00h, 0C0h, 4Fh, 0D7h, 0D0h, 62h
    if (_WIN32_IE ge 0600h)
      DEFINE_GUID CLSID_ACLCustomMRU, 6935db93h, 21e8h, 4ccch, 0beh, 0b9h, 9fh, 0e3h, 0c7h, 7ah, 29h, 7ah
    endif
    DEFINE_GUID CLSID_ProgressDialog, 0f8383852h, 0fcd3h, 11d1h, 0a6h, 0b9h, 0h, 60h, 97h, 0dfh, 5bh, 0d4h
    DEFINE_GUID IID_IProgressDialog, 0ebbc7c04h, 315eh, 11d2h, 0b6h, 2fh, 0h, 60h, 97h, 0dfh, 5bh, 0d4h
    SID_SProgressUI equ <CLSID_ProgressDialog>
    DEFINE_GUID SID_STopLevelBrowser, 4C96BE40h, 915Ch, 11CFh, 99h, 0D3h, 00h, 0AAh, 00h, 4Ah, 0E8h, 37h
  endif
  DEFINE_GUID CLSID_FileTypes, 0B091E540h, 83E3h, 11CFh, 0A7h, 13h, 00h, 20h, 0AFh, 0D7h, 97h, 62h
  DEFINE_GUID CLSID_ActiveDesktop, 75048700h, 0EF1Fh, 11D0h, 98h, 88h, 00h, 60h, 97h, 0DEh, 0ACh, 0F9h
  DEFINE_GUID IID_IActiveDesktop, 0F490EB00h, 1240h, 11D1h, 98h, 88h, 00h, 60h, 97h, 0DEh, 0ACh, 0F9h
  DEFINE_GUID IID_IActiveDesktopP, 52502EE0h, 0EC80h, 11D0h, 89h, 0ABh, 00h, 0C0h, 4Fh, 0C2h, 97h, 2Dh
  DEFINE_GUID IID_IADesktopP2, 0b22754e2h, 4574h, 11d1h, 98h, 88h, 0h, 60h, 97h, 0deh, 0ach, 0f9h
  DEFINE_GUID IID_ISynchronizedCallBack, 74c26041h, 70d1h, 11d1h, 0b7h, 5ah, 0h, 0a0h, 0c9h, 5h, 64h, 0feh
  DEFINE_GUID IID_IQueryAssociations, 0c46ca590h, 3c3fh, 11d2h, 0beh, 0e6h, 00h, 00h, 0f8h, 05h, 0cah, 57h
  DEFINE_GUID CLSID_QueryAssociations, 0a07034fdh, 6caah, 4954h, 0ach, 3fh, 97h, 0a2h, 72h, 16h, 0f9h, 8ah
  DEFINE_GUID IID_IColumnProvider, 0e8025004h, 1c42h, 11d2h, 0beh, 2ch, 0h, 0a0h, 0c9h, 0a8h, 3dh, 0a1h
  DEFINE_GUID CLSID_LinkColumnProvider, 24f14f02h, 7b1ch, 11d1h, 83h, 8fh, 0h, 0h, 0f8h, 4h, 61h, 0cfh
  DEFINE_GUID CGID_ShortCut, 93a68750h, 951ah, 11d1h, 94h, 6fh, 0h, 0h, 0h, 0h, 0h, 0h
  DEFINE_GUID IID_INamedPropertyBag, 0fb700430h, 952ch, 11d1h, 94h, 6fh, 0h, 0h, 0h, 0h, 0h, 0h
  DEFINE_GUID CLSID_InternetButtons, 1E796980h, 9CC5h, 11D1h, 0A8h, 3Fh, 00h, 0C0h, 4Fh, 0C9h, 9Dh, 61h
  DEFINE_GUID CLSID_MSOButtons, 178f34b8h, 0a282h, 11d2h, 86h, 0c5h, 0h, 0c0h, 4fh, 8eh, 0eah, 99h
  DEFINE_GUID CLSID_ToolbarExtButtons, 2ce4b5d8h, 0a28fh, 11d2h, 86h, 0c5h, 0h, 0c0h, 4fh, 8eh, 0eah, 99h
  DEFINE_GUID CLSID_DarwinAppPublisher, 0CFCCC7A0h, 0A282h, 11D1h, 90h, 82h, 00h, 60h, 08h, 05h, 93h, 82h
  DEFINE_GUID CLSID_DocHostUIHandler, 7057e952h, 0bd1bh, 11d1h, 89h, 19h, 0h, 0c0h, 4fh, 0c2h, 0c8h, 36h
  DEFINE_GUID IID_IShellFolder2, 93f2f68ch, 1d1bh, 11d3h, 0a3h, 0eh, 0h, 0c0h, 4fh, 79h, 0abh, 0d1h
  PSGUID_SHELLDETAILS equ { 28636aa6h, 953dh, 11d2h, 0b5h, 0d6h, 0h, 0c0h, 4fh, 0d9h, 18h, 0d0h }
  DEFINE_GUID FMTID_ShellDetails, 28636aa6h, 953dh, 11d2h, 0b5h, 0d6h, 0h, 0c0h, 4fh, 0d9h, 18h, 0d0h
  PID_FINDDATA equ 0
  PID_NETRESOURCE equ 1
  PID_DESCRIPTIONID equ 2
  PID_WHICHFOLDER equ 3
  PID_NETWORKLOCATION equ 4
  PID_COMPUTERNAME equ 5
  DEFINE_GUID FMTID_Storage, 0b725f130h, 47efh, 101ah, 0a5h, 0f1h, 02h, 60h, 8ch, 9eh, 0ebh, 0ach
  PSGUID_IMAGEPROPERTIES equ { 14b81da1h, 0135h, 4d31h, 96h, 0d9h, 6ch, 0bfh, 0c9h, 67h, 1ah, 99h }
  DEFINE_GUID FMTID_ImageProperties, 14b81da1h, 0135h, 4d31h, 96h, 0d9h, 6ch, 0bfh, 0c9h, 67h, 1ah, 99h
  PSGUID_CUSTOMIMAGEPROPERTIES equ { 7ecd8b0eh, 0c136h, 4a9bh, 94h, 11h, 4eh, 0bdh, 66h, 73h, 0cch, 0c3h }
  DEFINE_GUID FMTID_CustomImageProperties, 7ecd8b0eh, 0c136h, 4a9bh, 94h, 11h, 4eh, 0bdh, 66h, 73h, 0cch, 0c3h
  PSGUID_LIBRARYPROPERTIES equ { 5d76b67fh, 9b3dh, 44bbh, 0b6h, 0aeh, 25h, 0dah, 4fh, 63h, 8ah, 67h }
  DEFINE_GUID FMTID_LibraryProperties, 5d76b67fh, 9b3dh, 44bbh, 0b6h, 0aeh, 25h, 0dah, 4fh, 63h, 8ah, 67h
  PSGUID_DISPLACED equ { 9b174b33h, 40ffh, 11d2h, 0a2h, 7eh, 0h, 0c0h, 4fh, 0c3h, 8h, 71h }
  DEFINE_GUID FMTID_Displaced, 9b174b33h, 40ffh, 11d2h, 0a2h, 7eh, 0h, 0c0h, 4fh, 0c3h, 8h, 71h
  PID_DISPLACED_FROM equ 2
  PID_DISPLACED_DATE equ 3
  PSGUID_BRIEFCASE equ { 328d8b21h, 7729h, 4bfch, 95h, 4ch, 90h, 2bh, 32h, 9dh, 56h, 0b0h }
  DEFINE_GUID FMTID_Briefcase, 328d8b21h, 7729h, 4bfch, 95h, 4ch, 90h, 2bh, 32h, 9dh, 56h, 0b0h
  PID_SYNC_COPY_IN equ 2
  PSGUID_MISC equ { 9b174b34h, 40ffh, 11d2h, 0a2h, 7eh, 0h, 0c0h, 4fh, 0c3h, 8h, 71h }
  DEFINE_GUID FMTID_Misc, 9b174b34h, 40ffh, 11d2h, 0a2h, 7eh, 0h, 0c0h, 4fh, 0c3h, 8h, 71h
  PID_MISC_STATUS equ 2
  PID_MISC_ACCESSCOUNT equ 3
  PID_MISC_OWNER equ 4
  PID_HTMLINFOTIPFILE equ 5
  PID_MISC_PICS equ 6
  PSGUID_WEBVIEW equ { 0f2275480h, 0f782h, 4291h, 0bdh, 94h, 0f1h, 36h, 93h, 51h, 3ah, 0ech }
  DEFINE_GUID FMTID_WebView, 0f2275480h, 0f782h, 4291h, 0bdh, 94h, 0f1h, 36h, 93h, 51h, 3ah, 0ech
  PID_DISPLAY_PROPERTIES equ 0
  PID_INTROTEXT equ 1
  PSGUID_MUSIC equ { 56a3372eh, 0ce9ch, 11d2h, 9fh, 0eh, 0h, 60h, 97h, 0c6h, 86h, 0f6h }
  DEFINE_GUID FMTID_MUSIC, 56a3372eh, 0ce9ch, 11d2h, 9fh, 0eh, 0h, 60h, 97h, 0c6h, 86h, 0f6h
  PIDSI_ARTIST equ 2
  PIDSI_SONGTITLE equ 3
  PIDSI_ALBUM equ 4
  PIDSI_YEAR equ 5
  PIDSI_COMMENT equ 6
  PIDSI_TRACK equ 7
  PIDSI_GENRE equ 11
  PIDSI_LYRICS equ 12
  PSGUID_DRM equ { 0aeac19e4h, 89aeh, 4508h, 0b9h, 0b7h, 0bbh, 86h, 7ah, 0beh, 0e2h, 0edh }
  DEFINE_GUID FMTID_DRM, 0aeac19e4h, 89aeh, 4508h, 0b9h, 0b7h, 0bbh, 86h, 7ah, 0beh, 0e2h, 0edh
  PIDDRSI_PROTECTED equ 2
  PIDDRSI_DESCRIPTION equ 3
  PIDDRSI_PLAYCOUNT equ 4
  PIDDRSI_PLAYSTARTS equ 5
  PIDDRSI_PLAYEXPIRES equ 6
  PSGUID_VIDEO equ { 64440491h, 4c8bh, 11d1h, 8bh, 70h, 8h, 0h, 36h, 0b1h, 1ah, 3h }
  PIDVSI_STREAM_NAME equ 00000002h
  PIDVSI_FRAME_WIDTH equ 00000003h
  PIDVSI_FRAME_HEIGHT equ 00000004h
  PIDVSI_TIMELENGTH equ 00000007h
  PIDVSI_FRAME_COUNT equ 00000005h
  PIDVSI_FRAME_RATE equ 00000006h
  PIDVSI_DATA_RATE equ 00000008h
  PIDVSI_SAMPLE_SIZE equ 00000009h
  PIDVSI_COMPRESSION equ 0000000Ah
  PIDVSI_STREAM_NUMBER equ 0000000Bh
  PSGUID_AUDIO equ { 64440490h, 4c8bh, 11d1h, 8bh, 70h, 8h, 0h, 36h, 0b1h, 1ah, 3h }
  PIDASI_FORMAT equ 00000002h
  PIDASI_TIMELENGTH equ 00000003h
  PIDASI_AVG_DATA_RATE equ 00000004h
  PIDASI_SAMPLE_RATE equ 00000005h
  PIDASI_SAMPLE_SIZE equ 00000006h
  PIDASI_CHANNEL_COUNT equ 00000007h
  PIDASI_STREAM_NUMBER equ 00000008h
  PIDASI_STREAM_NAME equ 00000009h
  PIDASI_COMPRESSION equ 0000000Ah
  PSGUID_CONTROLPANEL equ { 305ca226h, 0d286h, 468eh, 0b8h, 48h, 2bh, 2eh, 8eh, 69h, 7bh, 74h }
  PID_CONTROLPANEL_CATEGORY equ 2
  PSGUID_VOLUME equ { 9b174b35h, 40ffh, 11d2h, 0a2h, 7eh, 0h, 0c0h, 4fh, 0c3h, 8h, 71h }
  DEFINE_GUID FMTID_Volume, 9b174b35h, 40ffh, 11d2h, 0a2h, 7eh, 0h, 0c0h, 4fh, 0c3h, 8h, 71h
  PID_VOLUME_FREE equ 2
  PID_VOLUME_CAPACITY equ 3
  PID_VOLUME_FILESYSTEM equ 4
  PSGUID_SHARE equ { 0d8c3986fh, 813bh, 449ch, 84h, 5dh, 87h, 0b9h, 5dh, 67h, 4ah, 0deh }
  PID_SHARE_CSC_STATUS equ 2
  PSGUID_LINK equ { 0b9b4b3fch, 2b51h, 4a42h, 0b5h, 0d8h, 32h, 41h, 46h, 0afh, 0cfh, 25h }
  PID_LINK_TARGET equ 2
  PID_LINK_TARGET_TYPE equ 3
  PSGUID_QUERY_D equ { 49691c90h, 7e17h, 101ah, 0a9h, 1ch, 08h, 00h, 2bh, 2eh, 0cdh, 0a9h }
  DEFINE_GUID FMTID_Query, 49691c90h, 7e17h, 101ah, 0a9h, 1ch, 08h, 00h, 2bh, 2eh, 0cdh, 0a9h
  PID_QUERY_RANK equ 2
  PSGUID_SUMMARYINFORMATION equ { 0f29f85e0h, 4ff9h, 1068h, 0abh, 91h, 08h, 00h, 2bh, 27h, 0b3h, 0d9h }
  PSGUID_DOCUMENTSUMMARYINFORMATION equ { 0d5cdd502h, 2e9ch, 101bh, 93h, 97h, 08h, 00h, 2bh, 2ch, 0f9h, 0aeh }
  PSGUID_MEDIAFILESUMMARYINFORMATION equ { 64440492h, 4c8bh, 11d1h, 8bh, 70h, 08h, 00h, 36h, 0b1h, 1ah, 03h }
  PSGUID_IMAGESUMMARYINFORMATION equ { 6444048fh, 4c8bh, 11d1h, 8bh, 70h, 8h, 00h, 36h, 0b1h, 1ah, 03h }
  DEFINE_GUID IID_IEnumExtraSearch, 0e700be1h, 9db6h, 11d1h, 0a1h, 0ceh, 0h, 0c0h, 4fh, 0d7h, 5dh, 13h
  DEFINE_GUID CLSID_HWShellExecute, 0ffb8655fh, 81b9h, 4fceh, 0b8h, 9ch, 9ah, 6bh, 0a7h, 6dh, 13h, 0e7h
  DEFINE_GUID CLSID_DragDropHelper, 4657278ah, 411bh, 11d2h, 83h, 9ah, 0h, 0c0h, 4fh, 0d9h, 18h, 0d0h
  DEFINE_GUID CLSID_CAnchorBrowsePropertyPage, 3050f3BBh, 98b5h, 11cfh, 0bbh, 82h, 00h, 0aah, 00h, 0bdh, 0ceh, 0bh
  DEFINE_GUID CLSID_CImageBrowsePropertyPage, 3050f3B3h, 98b5h, 11cfh, 0bbh, 82h, 00h, 0aah, 00h, 0bdh, 0ceh, 0bh
  DEFINE_GUID CLSID_CDocBrowsePropertyPage, 3050f3B4h, 98b5h, 11cfh, 0bbh, 82h, 00h, 0aah, 00h, 0bdh, 0ceh, 0bh
  DEFINE_GUID IID_IFileSystemBindData, 1e18d10h, 4d8bh, 11d2h, 85h, 5dh, 0h, 60h, 8h, 5h, 93h, 67h
  DEFINE_GUID SID_STopWindow, 49e1b500h, 4636h, 11d3h, 97h, 0f7h, 0h, 0c0h, 4fh, 45h, 0d0h, 0b3h
  DEFINE_GUID SID_SGetViewFromViewDual, 889A935Dh, 971Eh, 4B12h, 0B9h, 0Ch, 24h, 0DFh, 0C9h, 0E1h, 0E5h, 0E8h
  DEFINE_GUID CLSID_FolderItem, 0fef10fa2h, 355eh, 4e06h, 93h, 81h, 9bh, 24h, 0d7h, 0f7h, 0cch, 88h
  DEFINE_GUID CLSID_FolderItemsMultiLevel, 53c74826h, 0ab99h, 4d33h, 0ach, 0a4h, 31h, 17h, 0f5h, 1dh, 37h, 88h
  DEFINE_GUID CLSID_NewMenu, 0d969a300h, 0e7ffh, 11d0h, 0a9h, 3bh, 0h, 0a0h, 0c9h, 0fh, 27h, 19h
  DEFINE_GUID BHID_SFObject, 3981e224h, 0f559h, 11d3h, 8eh, 3ah, 00h, 0c0h, 4fh, 68h, 37h, 0d5h
  DEFINE_GUID BHID_SFUIObject, 3981e225h, 0f559h, 11d3h, 8eh, 3ah, 00h, 0c0h, 4fh, 68h, 37h, 0d5h
  DEFINE_GUID BHID_SFViewObject, 3981e226h, 0f559h, 11d3h, 8eh, 3ah, 00h, 0c0h, 4fh, 68h, 37h, 0d5h
  DEFINE_GUID BHID_Storage, 3981e227h, 0f559h, 11d3h, 8eh, 3ah, 00h, 0c0h, 4fh, 68h, 37h, 0d5h
  DEFINE_GUID BHID_Stream, 1cebb3abh, 7c10h, 499ah, 0a4h, 17h, 92h, 0cah, 16h, 0c4h, 0cbh, 83h
  DEFINE_GUID BHID_RandomAccessStream, 0f16fc93bh, 77aeh, 4cfeh, 0bdh, 0a7h, 0a8h, 66h, 0eeh, 0a6h, 87h, 8dh
  DEFINE_GUID BHID_LinkTargetItem, 3981e228h, 0f559h, 11d3h, 8eh, 3ah, 00h, 0c0h, 4fh, 68h, 37h, 0d5h
  DEFINE_GUID BHID_StorageEnum, 4621a4e3h, 0f0d6h, 4773h, 8ah, 9ch, 46h, 0e7h, 7bh, 17h, 48h, 40h
  DEFINE_GUID BHID_Transfer, 0d5e346a1h, 0f753h, 4932h, 0b4h, 3h, 45h, 74h, 80h, 0eh, 24h, 98h
  DEFINE_GUID BHID_PropertyStore, 0384e1a4h, 1523h, 439ch, 0a4h, 0c8h, 0abh, 91h, 10h, 52h, 0f5h, 86h
  DEFINE_GUID BHID_ThumbnailHandler, 7b2e650ah, 8e20h, 4f4ah, 0b0h, 9eh, 65h, 97h, 0afh, 0c7h, 2fh, 0b0h
  DEFINE_GUID BHID_EnumItems, 94f60519h, 2850h, 4924h, 0aah, 5ah, 0d1h, 5eh, 84h, 86h, 80h, 39h
  DEFINE_GUID BHID_DataObject, 0b8c0bd9fh, 0ed24h, 455ch, 83h, 0e6h, 0d5h, 39h, 0ch, 4fh, 0e8h, 0c4h
  DEFINE_GUID BHID_AssociationArray, 0bea9ef17h, 82f1h, 4f60h, 92h, 84h, 4fh, 8dh, 0b7h, 5ch, 3bh, 0e9h
  DEFINE_GUID BHID_Filter, 38d08778h, 0f557h, 4690h, 9eh, 0bfh, 0bah, 54h, 70h, 6ah, 0d8h, 0f7h
  DEFINE_GUID BHID_EnumAssocHandlers, 0b8ab0b9ch, 0c2ech, 4f7ah, 91h, 8dh, 31h, 49h, 00h, 0e6h, 28h, 0ah
  DEFINE_GUID BHID_StorageItem, 404e2109h, 77d2h, 4699h, 0a5h, 0a0h, 4fh, 0dfh, 10h, 0dbh, 98h, 37h
  DEFINE_GUID BHID_FilePlaceholder, 8677dcebh, 0aae0h, 4005h, 8dh, 3dh, 54h, 7fh, 0a8h, 52h, 0f8h, 25h
  DEFINE_GUID CATID_FilePlaceholderMergeHandler, 3e9c9a51h, 0d4aah, 4870h, 0b4h, 7ch, 74h, 24h, 0b4h, 91h, 0f1h, 0cch
  if _WIN32_IE ge 0600h
    DEFINE_GUID SID_CtxQueryAssociations, 0faadfc40h, 0b777h, 4b69h, 0aah, 81h, 77h, 03h, 5eh, 0f0h, 0e6h, 0e8h
  endif
  DEFINE_GUID IID_IDocViewSite, 87D605E0h, 0C511h, 11CFh, 89h, 0A9h, 00h, 0A0h, 0C9h, 05h, 41h, 29h
  DEFINE_GUID CLSID_QuickLinks, 0e5cbf21h, 0d15fh, 11d0h, 83h, 1h, 0h, 0aah, 0h, 5bh, 43h, 83h
  DEFINE_GUID CLSID_ISFBand, 0D82BE2B0h, 5764h, 11D0h, 0A9h, 6Eh, 00h, 0C0h, 4Fh, 0D7h, 05h, 0A2h
  DEFINE_GUID IID_CDefView, 4434FF80h, 0EF4Ch, 11CEh, 0AEh, 65h, 08h, 00h, 2Bh, 2Eh, 12h, 62h
  DEFINE_GUID CLSID_ShellFldSetExt, 6D5313C0h, 8C62h, 11D1h, 0B2h, 0CDh, 00h, 60h, 97h, 0DFh, 8Ch, 11h
  DEFINE_GUID SID_SMenuBandChild, 0ed9cc020h, 8b9h, 11d1h, 98h, 23h, 0h, 0c0h, 4fh, 0d9h, 19h, 72h
  DEFINE_GUID SID_SMenuBandParent, 8c278eech, 3eabh, 11d1h, 8ch, 0b0h, 0h, 0c0h, 4fh, 0d9h, 18h, 0d0h
  DEFINE_GUID SID_SMenuPopup, 0D1E7AFEBh, 6A2Eh, 11d0h, 8Ch, 78h, 0h, 0C0h, 4Fh, 0D9h, 18h, 0B4h
  DEFINE_GUID SID_SMenuBandBottomSelected, 165ebaf4h, 6d51h, 11d2h, 83h, 0adh, 0h, 0c0h, 4fh, 0d9h, 18h, 0d0h
  DEFINE_GUID SID_SMenuBandBottom, 743ca664h, 0debh, 11d1h, 98h, 25h, 0h, 0c0h, 4fh, 0d9h, 19h, 72h
  DEFINE_GUID SID_MenuShellFolder, 0a6c17eb4h, 2d65h, 11d2h, 83h, 8fh, 0h, 0c0h, 4fh, 0d9h, 18h, 0d0h
  DEFINE_GUID SID_SMenuBandContextMenuModifier, 39545874h, 7162h, 465eh, 0b7h, 83h, 2ah, 0a1h, 87h, 4fh, 0efh, 81h
  DEFINE_GUID SID_SMenuBandBKContextMenu, 164bbd86h, 1d0dh, 4de0h, 9ah, 3bh, 0d9h, 72h, 96h, 47h, 0c2h, 0b8h
  DEFINE_GUID CGID_MENUDESKBAR, 5c9f0a12h, 959eh, 11d0h, 0a3h, 0a4h, 0h, 0a0h, 0c9h, 8h, 26h, 36h
  DEFINE_GUID SID_SMenuBandTop, 9493a810h, 0ec38h, 11d0h, 0bch, 46h, 0h, 0aah, 0h, 6ch, 0e2h, 0f5h
  DEFINE_GUID CLSID_MenuToolbarBase, 40b96610h, 0b522h, 11d1h, 0b3h, 0b4h, 0h, 0aah, 0h, 6eh, 0fdh, 0e7h
  DEFINE_GUID IID_IBanneredBar, 596a9a94h, 13eh, 11d1h, 8dh, 34h, 0h, 0a0h, 0c9h, 0fh, 27h, 19h
  DEFINE_GUID CLSID_MenuBandSite, 0e13ef4e4h, 0d2f2h, 11d0h, 98h, 16h, 0h, 0c0h, 4fh, 0d9h, 19h, 72h
  DEFINE_GUID SID_SCommDlgBrowser, 80f30233h, 0b7dfh, 11d2h, 0a3h, 3bh, 0h, 60h, 97h, 0dfh, 5bh, 0d4h
  DEFINE_GUID CPFG_LOGON_USERNAME, 0da15bbe8h, 954dh, 4fd3h, 0b0h, 0f4h, 1fh, 0b5h, 0b9h, 0bh, 17h, 4bh
  DEFINE_GUID CPFG_LOGON_PASSWORD, 60624cfah, 0a477h, 47b1h, 8ah, 8eh, 3ah, 4ah, 19h, 98h, 18h, 27h
  DEFINE_GUID CPFG_SMARTCARD_USERNAME, 3e1ecf69h, 568ch, 4d96h, 9dh, 59h, 46h, 44h, 41h, 74h, 0e2h, 0d6h
  DEFINE_GUID CPFG_SMARTCARD_PIN, 4fe5263bh, 9181h, 46c1h, 0b0h, 0a4h, 9dh, 0edh, 0d4h, 0dbh, 7dh, 0eah
  DEFINE_GUID CPFG_CREDENTIAL_PROVIDER_LOGO, 2d837775h, 0f6cdh, 464eh, 0a7h, 45h, 48h, 2fh, 0d0h, 0b4h, 74h, 93h
  DEFINE_GUID CPFG_CREDENTIAL_PROVIDER_LABEL, 286bbff3h, 0bad4h, 438fh, 0b0h, 7h, 79h, 0b7h, 26h, 7ch, 3dh, 48h
  DEFINE_GUID CPFG_STANDALONE_SUBMIT_BUTTON, 0b7b0ad8h, 0cc36h, 4d59h, 80h, 2bh, 82h, 0f7h, 14h, 0fah, 70h, 22h
  DEFINE_GUID CPFG_STYLE_LINK_AS_BUTTON, 088fa508h, 94a6h, 4430h, 0a4h, 0cbh, 6fh, 0c6h, 0e3h, 0c0h, 0b9h, 0e2h
  include knownfolders.inc
  DEFINE_GUID FOLDERTYPEID_Invalid, 57807898h, 8c4fh, 4462h, 0bbh, 63h, 71h, 04h, 23h, 80h, 0b1h, 09h
  DEFINE_GUID FOLDERTYPEID_Generic, 5c4f28b5h, 0f869h, 4e84h, 8eh, 60h, 0f1h, 1dh, 0b9h, 7ch, 5ch, 0c7h
  DEFINE_GUID FOLDERTYPEID_GenericSearchResults, 7fde1a1eh, 8b31h, 49a5h, 93h, 0b8h, 6bh, 0e1h, 4ch, 0fah, 49h, 43h
  DEFINE_GUID FOLDERTYPEID_GenericLibrary, 5f4eab9ah, 6833h, 4f61h, 89h, 9dh, 31h, 0cfh, 46h, 97h, 9dh, 49h
  DEFINE_GUID FOLDERTYPEID_Documents, 7d49d726h, 3c21h, 4f05h, 99h, 0aah, 0fdh, 0c2h, 0c9h, 47h, 46h, 56h
  DEFINE_GUID FOLDERTYPEID_Pictures, 0b3690e58h, 0e961h, 423bh, 0b6h, 87h, 38h, 6eh, 0bfh, 0d8h, 32h, 39h
  DEFINE_GUID FOLDERTYPEID_Music, 94d6ddcch, 4a68h, 4175h, 0a3h, 74h, 0bdh, 58h, 4ah, 51h, 0bh, 78h
  DEFINE_GUID FOLDERTYPEID_Videos, 5fa96407h, 7e77h, 483ch, 0ach, 93h, 69h, 1dh, 05h, 85h, 0dh, 0e8h
  DEFINE_GUID FOLDERTYPEID_Downloads, 885a186eh, 0a440h, 4adah, 81h, 2bh, 0dbh, 87h, 1bh, 94h, 22h, 59h
  DEFINE_GUID FOLDERTYPEID_UserFiles, 0cd0fc69bh, 71e2h, 46e5h, 96h, 90h, 5bh, 0cdh, 9fh, 57h, 0aah, 0b3h
  DEFINE_GUID FOLDERTYPEID_UsersLibraries, 0c4d98f09h, 6124h, 4fe0h, 99h, 42h, 82h, 64h, 16h, 8h, 2dh, 0a9h
  DEFINE_GUID FOLDERTYPEID_OtherUsers, 0b337fd00h, 9dd5h, 4635h, 0a6h, 0d4h, 0dah, 33h, 0fdh, 10h, 2bh, 7ah
  DEFINE_GUID FOLDERTYPEID_PublishedItems, 7f2f5b96h, 0ff74h, 41dah, 0afh, 0d8h, 1ch, 78h, 0a5h, 0f3h, 0aeh, 0a2h
  DEFINE_GUID FOLDERTYPEID_Communications, 91475fe5h, 586bh, 4ebah, 8dh, 75h, 0d1h, 74h, 34h, 0b8h, 0cdh, 0f6h
  DEFINE_GUID FOLDERTYPEID_Contacts, 0de2b70ech, 9bf7h, 4a93h, 0bdh, 3dh, 24h, 3fh, 78h, 81h, 0d4h, 92h
  DEFINE_GUID FOLDERTYPEID_StartMenu, 0ef87b4cbh, 0f2ceh, 4785h, 86h, 58h, 4ch, 0a6h, 0c6h, 3eh, 38h, 0c6h
  DEFINE_GUID FOLDERTYPEID_RecordedTV, 5557a28fh, 5da6h, 4f83h, 88h, 09h, 0c2h, 0c9h, 8ah, 11h, 0a6h, 0fah
  DEFINE_GUID FOLDERTYPEID_SavedGames, 0d0363307h, 28cbh, 4106h, 9fh, 23h, 29h, 56h, 0e3h, 0e5h, 0e0h, 0e7h
  DEFINE_GUID FOLDERTYPEID_OpenSearch, 8faf9629h, 1980h, 46ffh, 80h, 23h, 9dh, 0ceh, 0abh, 9ch, 3eh, 0e3h
  DEFINE_GUID FOLDERTYPEID_SearchConnector, 982725eeh, 6f47h, 479eh, 0b4h, 47h, 81h, 2bh, 0fah, 7dh, 2eh, 8fh
  DEFINE_GUID FOLDERTYPEID_AccountPictures, 0db2a5d8fh, 06e6h, 4007h, 0abh, 0a6h, 0afh, 87h, 7dh, 52h, 6eh, 0a6h
  DEFINE_GUID FOLDERTYPEID_Games, 0b689b0d0h, 76d3h, 4cbbh, 87h, 0f7h, 58h, 5dh, 0eh, 0ch, 0e0h, 70h
  DEFINE_GUID FOLDERTYPEID_ControlPanelCategory, 0de4f0660h, 0fa10h, 4b8fh, 0a4h, 94h, 06h, 8bh, 20h, 0b2h, 23h, 07h
  DEFINE_GUID FOLDERTYPEID_ControlPanelClassic, 0c3794f3h, 0b545h, 43aah, 0a3h, 29h, 0c3h, 74h, 30h, 0c5h, 8dh, 2ah
  DEFINE_GUID FOLDERTYPEID_Printers, 2c7bbec6h, 0c844h, 4a0ah, 91h, 0fah, 0ceh, 0f6h, 0f5h, 9ch, 0fdh, 0a1h
  DEFINE_GUID FOLDERTYPEID_RecycleBin, 0d6d9e004h, 0cd87h, 442bh, 9dh, 57h, 5eh, 0ah, 0ebh, 4fh, 6fh, 72h
  DEFINE_GUID FOLDERTYPEID_SoftwareExplorer, 0d674391bh, 52d9h, 4e07h, 83h, 4eh, 67h, 0c9h, 86h, 10h, 0f3h, 9dh
  DEFINE_GUID FOLDERTYPEID_CompressedFolder, 80213e82h, 0bcfdh, 4c4fh, 88h, 17h, 0bbh, 27h, 60h, 12h, 67h, 0a9h
  DEFINE_GUID FOLDERTYPEID_NetworkExplorer, 25cc242bh, 9a7ch, 4f51h, 80h, 0e0h, 7ah, 29h, 28h, 0feh, 0beh, 42h
  DEFINE_GUID FOLDERTYPEID_Searches, 0b0ba2e3h, 405fh, 415eh, 0a6h, 0eeh, 0cah, 0d6h, 25h, 20h, 78h, 53h
  DEFINE_GUID FOLDERTYPEID_SearchHome, 834d8a44h, 0974h, 4ed6h, 86h, 6eh, 0f2h, 03h, 0d8h, 0bh, 38h, 10h
  DEFINE_GUID FOLDERTYPEID_StorageProviderGeneric, 4F01EBC5h, 2385h, 41f2h, 0A2h, 8Eh, 2Ch, 5Ch, 91h, 0FBh, 56h, 0E0h
  DEFINE_GUID FOLDERTYPEID_StorageProviderDocuments, 0DD61BD66h, 70E8h, 48ddh, 96h, 55h, 65h, 0C5h, 0E1h, 0AAh, 0C2h, 0D1h
  DEFINE_GUID FOLDERTYPEID_StorageProviderPictures, 71d642a9h, 0f2b1h, 42cdh, 0adh, 92h, 0ebh, 93h, 0h, 0c7h, 0cch, 0ah
  DEFINE_GUID FOLDERTYPEID_StorageProviderMusic, 672ECD7Eh, 0AF04h, 4399h, 87h, 5Ch, 02h, 90h, 84h, 5Bh, 62h, 47h
  DEFINE_GUID FOLDERTYPEID_StorageProviderVideos, 51294DA1h, 0D7B1h, 485bh, 9Eh, 9Ah, 17h, 0CFh, 0FEh, 33h, 0E1h, 87h
  DEFINE_GUID SYNCMGR_OBJECTID_Icon, 6dbc85c3h, 5d07h, 4c72h, 0a7h, 77h, 7fh, 0ech, 78h, 7h, 2ch, 6h
  DEFINE_GUID SYNCMGR_OBJECTID_EventStore, 4bef34b9h, 0a786h, 4075h, 0bah, 88h, 0ch, 2bh, 9dh, 89h, 0a9h, 8fh
  DEFINE_GUID SYNCMGR_OBJECTID_ConflictStore, 0d78181f4h, 2389h, 47e4h, 0a9h, 60h, 60h, 0bch, 0c2h, 0edh, 93h, 0bh
  DEFINE_GUID SYNCMGR_OBJECTID_BrowseContent, 57cbb584h, 0e9b4h, 47aeh, 0a1h, 20h, 0c4h, 0dfh, 33h, 35h, 0deh, 0e2h
  DEFINE_GUID SYNCMGR_OBJECTID_ShowSchedule, 0edc6f3e3h, 8441h, 4109h, 0adh, 0f3h, 6ch, 1ch, 0a0h, 0b7h, 0deh, 47h
  DEFINE_GUID SYNCMGR_OBJECTID_QueryBeforeActivate, 0d882d80bh, 0e7aah, 49edh, 86h, 0b7h, 0e6h, 0e1h, 0f7h, 14h, 0cdh, 0feh
  DEFINE_GUID SYNCMGR_OBJECTID_QueryBeforeDeactivate, 0a0efc282h, 60e0h, 460eh, 93h, 74h, 0eah, 88h, 51h, 3ch, 0fch, 80h
  DEFINE_GUID SYNCMGR_OBJECTID_QueryBeforeEnable, 4cbf7f0h, 5bebh, 4de1h, 0bch, 90h, 90h, 83h, 45h, 0c4h, 80h, 0f6h
  DEFINE_GUID SYNCMGR_OBJECTID_QueryBeforeDisable, 0bb5f64aah, 0f004h, 4eb5h, 8eh, 4dh, 26h, 75h, 19h, 66h, 34h, 4ch
  DEFINE_GUID SYNCMGR_OBJECTID_QueryBeforeDelete, 0f76c3397h, 0afb3h, 45d7h, 0a5h, 9fh, 5ah, 49h, 0e9h, 5h, 43h, 7eh
  DEFINE_GUID SYNCMGR_OBJECTID_EventLinkClick, 2203bdc1h, 1af1h, 4082h, 8ch, 30h, 28h, 39h, 9fh, 41h, 38h, 4ch
  DEFINE_GUID EP_NavPane, 0cb316b22h, 25f7h, 42b8h, 8ah, 09h, 54h, 0dh, 23h, 0a4h, 3ch, 2fh
  DEFINE_GUID EP_Commands, 0d9745868h, 0ca5fh, 4a76h, 91h, 0cdh, 0f5h, 0a1h, 29h, 0fbh, 0b0h, 76h
  DEFINE_GUID EP_Commands_Organize, 72e81700h, 0e3ech, 4660h, 0bfh, 24h, 3ch, 3bh, 7bh, 64h, 88h, 06h
  DEFINE_GUID EP_Commands_View, 21f7c32dh, 0eeaah, 439bh, 0bbh, 51h, 37h, 0b9h, 6fh, 0d6h, 0a9h, 43h
  DEFINE_GUID EP_DetailsPane, 43abf98bh, 89b8h, 472dh, 0b9h, 0ceh, 0e6h, 9bh, 82h, 29h, 0f0h, 19h
  DEFINE_GUID EP_PreviewPane, 893c63d1h, 45c8h, 4d17h, 0beh, 19h, 22h, 3bh, 0e7h, 1bh, 0e3h, 65h
  DEFINE_GUID EP_QueryPane, 65bcde4fh, 4f07h, 4f27h, 83h, 0a7h, 1ah, 0fch, 0a4h, 0dfh, 7dh, 0ddh
  DEFINE_GUID EP_AdvQueryPane, 0b4e9db8bh, 34bah, 4c39h, 0b5h, 0cch, 16h, 0a1h, 0bdh, 2ch, 41h, 1ch
  DEFINE_GUID EP_StatusBar, 65fe56ceh, 5cfeh, 4bc4h, 0adh, 8ah, 7ah, 0e3h, 0feh, 7eh, 8fh, 7ch
  DEFINE_GUID EP_Ribbon, 0d27524a8h, 0c9f2h, 4834h, 0a1h, 6h, 0dfh, 88h, 89h, 0fdh, 4fh, 37h
  DEFINE_GUID CATID_LocationFactory, 965c4d51h, 8b76h, 4e57h, 80h, 0b7h, 56h, 4dh, 2eh, 0a4h, 0b5h, 5eh
  DEFINE_GUID CATID_LocationProvider, 1b3ca474h, 2614h, 414bh, 0b8h, 13h, 1ah, 0ceh, 0cah, 3eh, 3dh, 0d8h
  DEFINE_GUID ItemCount_Property_GUID, 0abbf5c45h, 5ccch, 47b7h, 0bbh, 4eh, 87h, 0cbh, 87h, 0bbh, 0d1h, 62h
  DEFINE_GUID SelectedItemCount_Property_GUID, 8fe316d2h, 0e52h, 460ah, 9ch, 1eh, 48h, 0f2h, 73h, 0d4h, 70h, 0a3h
  DEFINE_GUID ItemIndex_Property_GUID, 92a053dah, 2969h, 4021h, 0bfh, 27h, 51h, 4ch, 0fch, 2eh, 4ah, 69h
  DEFINE_GUID CATID_SearchableApplication, 366c292ah, 0d9b3h, 4dbfh, 0bbh, 70h, 0e6h, 2eh, 0c3h, 0d0h, 0bbh, 0bfh
endif
