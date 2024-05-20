;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\shlguid.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 21/02/2024 18:17:24

;===========================================================================
include winapifamily.inc
if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
  DEFINE_GUID CLSID_NetworkDomain, 46e06680h, 4bf0h, 11d1h, 83h, 0eeh, 00h, 0a0h, 0c9h, 0dh, 0c8h, 49h
  ;46e06680-4bf0-11d1-83ee-00a0c90dc849
  DEFINE_GUID CLSID_NetworkServer, 0c0542a90h, 4bf0h, 11d1h, 83h, 0eeh, 00h, 0a0h, 0c9h, 0dh, 0c8h, 49h
  ;c0542a90-4bf0-11d1-83ee-00a0c90dc849
  DEFINE_GUID CLSID_NetworkShare, 54a754c0h, 4bf0h, 11d1h, 83h, 0eeh, 00h, 0a0h, 0c9h, 0dh, 0c8h, 49h
  ;54a754c0-4bf1-11d1-83ee-00a0c90dc849
  DEFINE_GUID CLSID_MyComputer, 20D04FE0h, 3AEAh, 1069h, 0A2h, 0D8h, 08h, 00h, 2Bh, 30h, 30h, 9Dh
  ;20D04FE0-3AEA-1069-A2D8-08002B30309D
  DEFINE_GUID CLSID_Internet, 871C5380h, 42A0h, 1069h, 0A2h, 0EAh, 08h, 00h, 2Bh, 30h, 30h, 9Dh
  ;871C5380-42A0-1069-A2EA-08002B30309D
  DEFINE_GUID CLSID_RecycleBin, 645FF040h, 5081h, 101Bh, 9Fh, 08h, 00h, 0AAh, 00h, 2Fh, 95h, 4Eh
  ;645FF040-5081-101B-9F08-00AA002F954E
  DEFINE_GUID CLSID_ControlPanel, 21EC2020h, 3AEAh, 1069h, 0A2h, 0DDh, 08h, 00h, 2Bh, 30h, 30h, 9Dh
  ;21EC2020-3AEA-1069-A2DD-08002B30309D
  DEFINE_GUID CLSID_Printers, 2227A280h, 3AEAh, 1069h, 0A2h, 0DEh, 08h, 00h, 2Bh, 30h, 30h, 9Dh
  DEFINE_GUID CLSID_MyDocuments, 450d8fbah, 0ad25h, 11d0h, 98h, 0a8h, 08h, 00h, 36h, 1bh, 11h, 03h
  ;450D8FBA-AD25-11D0-98A8-0800361B1103
  ; string version of above CLSIDs
  ; useful for doing psfDesktop->ParseDisplayName( L"::" L STR_MYDOCS_CLSID, ...);
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
  SID_LinkSite equ <IID_IShellLinkW>; IServiceProvider::QueryService() access the link object that is defering to you

  DEFINE_GUID IID_IQueryInfo, 00021500h, 0, 0, 0C0h, 0, 0, 0, 0, 0, 0, 46h
  DEFINE_GUID IID_IBriefcaseStg, 8BCE1FA1h, 0921h, 101Bh, 0B1h, 0FFh, 00h, 0DDh, 01h, 0Ch, 0CCh, 48h
  DEFINE_GUID IID_IShellView2, 88E39E80h, 3578h, 11CFh, 0AEh, 69h, 08h, 00h, 2Bh, 2Eh, 12h, 62h
  DEFINE_GUID IID_IURLSearchHook, 0AC60F6A0h, 0FD9h, 11D0h, 99h, 0CBh, 00h, 0C0h, 4Fh, 0D6h, 44h, 97h
  DEFINE_GUID IID_ISearchContext, 09F656A2h, 41AFh, 480Ch, 88h, 0F7h, 16h, 0CCh, 0Dh, 16h, 46h, 15h
  DEFINE_GUID IID_IURLSearchHook2, 5ee44da4h, 6d32h, 46e3h, 86h, 0bch, 07h, 54h, 0dh, 0edh, 0d0h, 0e0h
  DEFINE_GUID IID_IDefViewID, 985F64F0h, 0D410h, 4E02h, 0BEh, 22h, 0DAh, 07h, 0F2h, 0B5h, 0C5h, 0E1h
  IDefViewID equ <IUnknown>
  ; CLSID_FolderShortcut {0AFACED1-E828-11D1-9187-B532F1E9575D}
  DEFINE_GUID CLSID_FolderShortcut, 0AFACED1h, 0E828h, 11D1h, 91h, 87h, 0B5h, 32h, 0F1h, 0E9h, 57h, 5Dh
  DEFINE_GUID IID_IDockingWindowSite, 2a342fc2h, 7b26h, 11d0h, 8ch, 0a9h, 0h, 0a0h, 0c9h, 2dh, 0bfh, 0e8h
  DEFINE_GUID IID_IDockingWindowFrame, 47d2657ah, 7b27h, 11d0h, 8ch, 0a9h, 0h, 0a0h, 0c9h, 2dh, 0bfh, 0e8h
  DEFINE_GUID IID_IShellIconOverlay, 7D688A70h, 0C613h, 11D0h, 99h, 9Bh, 00h, 0C0h, 4Fh, 0D6h, 55h, 0E1h
  DEFINE_GUID IID_IShellIconOverlayIdentifier, 0C6C4200h, 0C589h, 11D0h, 99h, 9Ah, 00h, 0C0h, 4Fh, 0D6h, 55h, 0E1h
  ; {10339516-2894-11d2-9039-00C04F8EEB3E}
  DEFINE_GUID IID_ICommDlgBrowser2, 10339516h, 2894h, 11d2h, 90h, 39h, 0h, 0c0h, 4fh, 8eh, 0ebh, 3eh
  ; {2047E320-F2A9-11CE-AE65-08002B2E1262}
  DEFINE_GUID IID_IShellFolderViewCB, 2047E320h, 0F2A9h, 11CEh, 0AEh, 65h, 08h, 00h, 2Bh, 2Eh, 12h, 62h
  SID_ShellFolderViewCB equ <IID_IShellFolderViewCB>
  ; {63B51F81-C868-11D0-999C-00C04FD655E1}
  DEFINE_GUID CLSID_CFSIconOverlayManager, 63B51F81h, 0C868h, 11D0h, 99h, 9Ch, 00h, 0C0h, 4Fh, 0D6h, 55h, 0E1h
  ; f10b5e34-dd3b-42a7-aa7d-2f4ec54bb09b
  DEFINE_GUID IID_IShellIconOverlayManager, 0f10b5e34h, 0dd3bh, 42a7h, 0aah, 7dh, 2fh, 4eh, 0c5h, 4bh, 0b0h, 9bh
  ; {4ea39266-7211-409f-b622-f63dbd16c533}
  DEFINE_GUID IID_IThumbnailCapture, 4ea39266h, 7211h, 409fh, 0b6h, 22h, 0f6h, 3dh, 0bdh, 16h, 0c5h, 33h
  ; {48C8118C-B924-11d1-98D5-00C04FB687DA}
  DEFINE_GUID IID_IShellImageStore, 48c8118ch, 0b924h, 11d1h, 98h, 0d5h, 0h, 0c0h, 4fh, 0b6h, 87h, 0dah
  if (NTDDI_VERSION lt NTDDI_VISTA)
    ; {1EBDCF80-A200-11d0-A3A4-00C04FD706EC}
    DEFINE_GUID CLSID_ShellThumbnailDiskCache, 1ebdcf80h, 0a200h, 11d0h, 0a3h, 0a4h, 0h, 0c0h, 4fh, 0d7h, 6h, 0ech
  endif
  ; {BCFCE0A0-EC17-11d0-8D10-00A0C90F2719}
  DEFINE_GUID IID_IContextMenu3, 0bcfce0a0h, 0ec17h, 11d0h, 8dh, 10h, 0h, 0a0h, 0c9h, 0fh, 27h, 19h
  DEFINE_GUID SID_DefView, 6D12FE80h, 7911h, 11CFh, 95h, 34h, 00h, 00h, 0C0h, 5Bh, 0AEh, 0Bh
  DEFINE_GUID CGID_DefView, 4af07f10h, 0d231h, 11d0h, 0b9h, 42h, 0h, 0a0h, 0c9h, 3h, 12h, 0e1h
  DEFINE_GUID CLSID_MenuBand, 5b4dae26h, 0b807h, 11d0h, 98h, 15h, 0h, 0c0h, 4fh, 0d9h, 19h, 72h
  ; IShellFolderBand stuff
  ; {7FE80CC8-C247-11d0-B93A-00A0C90312E1}
  DEFINE_GUID IID_IShellFolderBand, 7fe80cc8h, 0c247h, 11d0h, 0b9h, 3ah, 0h, 0a0h, 0c9h, 3h, 12h, 0e1h
  ; 710EB7A0-45ED-11D0-924A-0020AFC7AC4D
  DEFINE_GUID IID_IDefViewFrame, 710EB7A0h, 45EDh, 11D0h, 92h, 4Ah, 00h, 20h, 0AFh, 0C7h, 0ACh, 4Dh
  ; 0057D0E0-3573-11CF-AE69-08002B2E1262
  DEFINE_GUID VID_LargeIcons, 0057D0E0h, 3573h, 11CFh, 0AEh, 69h, 08h, 00h, 2Bh, 2Eh, 12h, 62h
  ; 089000C0-3573-11CF-AE69-08002B2E1262
  DEFINE_GUID VID_SmallIcons, 089000C0h, 3573h, 11CFh, 0AEh, 69h, 08h, 00h, 2Bh, 2Eh, 12h, 62h
  ; 0E1FA5E0-3573-11CF-AE69-08002B2E1262
  DEFINE_GUID VID_List, 0E1FA5E0h, 3573h, 11CFh, 0AEh, 69h, 08h, 00h, 2Bh, 2Eh, 12h, 62h
  ; 137E7700-3573-11CF-AE69-08002B2E1262
  DEFINE_GUID VID_Details, 137E7700h, 3573h, 11CFh, 0AEh, 69h, 08h, 00h, 2Bh, 2Eh, 12h, 62h
  ; 5984FFE0-28D4-11CF-AE66-08002B2E1262
  DEFINE_GUID VID_Tile, 65f125e5h, 7be1h, 4810h, 0bah, 9dh, 0d2h, 71h, 0c8h, 43h, 2ch, 0e3h
  ; 65F125E5-7BE1-4810-BA9D-D271C8432CE3
  DEFINE_GUID VID_Content, 30c2c434h, 0889h, 4c8dh, 98h, 5dh, 0a9h, 0f7h, 18h, 30h, 0b0h, 0a9h
  ; 30C2C434-0889-4c8d-985D-A9F71830B0A9
  ; NOTE: This has to be the same as the old CLSID_Thumbnails
  ; {8BEBB290-52D0-11d0-B7F4-00C04FD706EC}
  DEFINE_GUID VID_Thumbnails, 8bebb290h, 52d0h, 11d0h, 0b7h, 0f4h, 0h, 0c0h, 4fh, 0d7h, 6h, 0ech
  ; ThumbStrip
  ; {8EEFA624-D1E9-445B-94B7-74FBCE2EA11A}
  DEFINE_GUID VID_ThumbStrip, 8EEFA624h, 0D1E9h, 445Bh, 94h, 0B7h, 74h, 0FBh, 0CEh, 2Eh, 0A1h, 1Ah
  SID_SShellBrowser equ <IID_IShellBrowser>
  SID_SShellDesktop equ <CLSID_ShellDesktop>
  ; define downlevel for multi-platform IE use; OSes prior to Win7 will fail this SID.
  ; {1D2AE02B-3655-46CC-B63A-285988153BCA}
  DEFINE_GUID SID_SInPlaceBrowser, 1D2AE02Bh, 3655h, 46CCh, 0B6h, 3Ah, 28h, 59h, 88h, 15h, 3Bh, 0CAh
  if (NTDDI_VERSION ge NTDDI_WIN7)
    ; {142daa61-516b-4713-b49c-fb985ef82998}
    DEFINE_GUID SID_SSearchBoxInfo, 142daa61h, 516bh, 4713h, 0b4h, 9ch, 0fbh, 98h, 5eh, 0f8h, 29h, 98h
    ; Objects that are created in the context of a context menu can use this service to discover a
    ; property bag (IPropertyBag, INamedPropertyStore) that can used to share state between
    ; those objects. For example a command state handler can share this information with a verb or 2 verbs
    ; can share state. This is useful when computing that state can be expensive.
    ; {6e043250-4416-485c-b143-e62a760d9fe5}
    DEFINE_GUID SID_CommandsPropertyBag, 6e043250h, 4416h, 485ch, 0b1h, 43h, 0e6h, 2ah, 76h, 0dh, 9fh, 0e5h
  endif
  ; NTDDI_WIN7
  ; IDiscardableBrowserProperty is an IID-only interface. If the object supports this
  ; interface it can be discarded anytime. IWebBrowser::PutProperty QI's for
  ; this interface to detect discardable properties.
  DEFINE_GUID IID_IDiscardableBrowserProperty, 49c3de7ch, 0d329h, 11d0h, 0abh, 73h, 00h, 0c0h, 4fh, 0c3h, 3eh, 80h
  ; IShellChangeNotify is a sink of LPCITEMIDLIST notification events
  ; D82BE2B1-5764-11D0-A96E-00C04FD705A2
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
    ; internet shortcut GUIDs
  endif
  ifndef NO_SHDOCVW_GUIDS
    ifndef GUID_DEFS_ONLY
      include exdisp.inc
      include shldisp.inc
    endif
    ; {3C374A40-BAE4-11CF-BF7D-00AA006946EE}
    externdef CLSID_CUrlHistory:GUID
    SID_SUrlHistory equ <CLSID_CUrlHistory>
    ; {6659983c-8476-4eb4-b78c-e5968f326ba0}
    externdef CLSID_CUrlHistoryBoth:GUID
    DEFINE_GUID CLSID_CURLSearchHook, 0CFBFAE00h, 17A6h, 11D0h, 99h, 0CBh, 00h, 0C0h, 4Fh, 0D6h, 44h, 97h
    SID_SInternetExplorer equ <IID_IWebBrowserApp>
    SID_SWebBrowserApp equ <IID_IWebBrowserApp>
    SID_SWebBrowserEventsService equ <IID_IWebBrowserEventsService>
    ; AutoComplete Guids
    DEFINE_GUID IID_IObjMgr, 00BB2761h, 6A77h, 11D0h, 0A5h, 35h, 00h, 0C0h, 4Fh, 0D7h, 0D0h, 62h
    DEFINE_GUID IID_IACList, 77A130B0h, 94FDh, 11D0h, 0A5h, 44h, 00h, 0C0h, 4Fh, 0D7h, 0d0h, 62h
    DEFINE_GUID IID_IACList2, 470141a0h, 5186h, 11d2h, 0bbh, 0b6h, 00h, 60h, 97h, 7bh, 46h, 4ch
    DEFINE_GUID IID_ICurrentWorkingDirectory, 91956d21h, 9276h, 11d1h, 92h, 1ah, 00h, 60h, 97h, 0dfh, 5bh, 0d4h
    ; {91956D21-9276-11d1-921A-006097DF5BD4}
    DEFINE_GUID CLSID_AutoComplete, 00BB2763h, 6A77h, 11D0h, 0A5h, 35h, 00h, 0C0h, 4Fh, 0D7h, 0D0h, 62h
    DEFINE_GUID CLSID_ACLHistory, 00BB2764h, 6A77h, 11D0h, 0A5h, 35h, 00h, 0C0h, 4Fh, 0D7h, 0D0h, 62h
    DEFINE_GUID CLSID_ACListISF, 03C036F1h, 0A186h, 11D0h, 82h, 4Ah, 00h, 0AAh, 00h, 5Bh, 43h, 83h
    DEFINE_GUID CLSID_ACLMRU, 6756a641h, 0de71h, 11d0h, 83h, 1bh, 0h, 0aah, 0h, 5bh, 43h, 83h
    ; {6756A641-DE71-11d0-831B-00AA005B4383}
    DEFINE_GUID CLSID_ACLMulti, 00BB2765h, 6A77h, 11D0h, 0A5h, 35h, 00h, 0C0h, 4Fh, 0D7h, 0D0h, 62h
    if (_WIN32_IE ge 0600h)
      DEFINE_GUID CLSID_ACLCustomMRU, 6935db93h, 21e8h, 4ccch, 0beh, 0b9h, 9fh, 0e3h, 0c7h, 7ah, 29h, 7ah
    endif
    ; IProgressDialog
    ; {F8383852-FCD3-11d1-A6B9-006097DF5BD4}
    DEFINE_GUID CLSID_ProgressDialog, 0f8383852h, 0fcd3h, 11d1h, 0a6h, 0b9h, 0h, 60h, 97h, 0dfh, 5bh, 0d4h
    ; {EBBC7C04-315E-11d2-B62F-006097DF5BD4}
    DEFINE_GUID IID_IProgressDialog, 0ebbc7c04h, 315eh, 11d2h, 0b6h, 2fh, 0h, 60h, 97h, 0dfh, 5bh, 0d4h
    ; Progress objects exposed via QueryService
    SID_SProgressUI equ <CLSID_ProgressDialog>
    ; Top-most browser implementation in the heirarchy. use IServiceProvider::QueryService()
    ; to get to interfaces (IID_IShellBrowser, IID_IShellBrowserService, etc.)
    DEFINE_GUID SID_STopLevelBrowser, 4C96BE40h, 915Ch, 11CFh, 99h, 0D3h, 00h, 0AAh, 00h, 4Ah, 0E8h, 37h
  endif
  ; !NO_SHDOCVW_GUIDS
  ;B091E540-83E3-11CF-A713-0020AFD79762
  DEFINE_GUID CLSID_FileTypes, 0B091E540h, 83E3h, 11CFh, 0A7h, 13h, 00h, 20h, 0AFh, 0D7h, 97h, 62h
  ; {75048700-EF1F-11D0-9888-006097DEACF9}
  DEFINE_GUID CLSID_ActiveDesktop, 75048700h, 0EF1Fh, 11D0h, 98h, 88h, 00h, 60h, 97h, 0DEh, 0ACh, 0F9h
  ; {F490EB00-1240-11D1-9888-006097DEACF9}
  DEFINE_GUID IID_IActiveDesktop, 0F490EB00h, 1240h, 11D1h, 98h, 88h, 00h, 60h, 97h, 0DEh, 0ACh, 0F9h
  ; {52502EE0-EC80-11D0-89AB-00C04FC2972D}
  DEFINE_GUID IID_IActiveDesktopP, 52502EE0h, 0EC80h, 11D0h, 89h, 0ABh, 00h, 0C0h, 4Fh, 0C2h, 97h, 2Dh
  ; {B22754E2-4574-11d1-9888-006097DEACF9}
  DEFINE_GUID IID_IADesktopP2, 0b22754e2h, 4574h, 11d1h, 98h, 88h, 0h, 60h, 97h, 0deh, 0ach, 0f9h
  ; {74C26041-70D1-11d1-B75A-00A0C90564FE}
  DEFINE_GUID IID_ISynchronizedCallBack, 74c26041h, 70d1h, 11d1h, 0b7h, 5ah, 0h, 0a0h, 0c9h, 5h, 64h, 0feh
  ;  {c46ca590-3c3f-11d2-bee6-0000f805ca57}
  DEFINE_GUID IID_IQueryAssociations, 0c46ca590h, 3c3fh, 11d2h, 0beh, 0e6h, 00h, 00h, 0f8h, 05h, 0cah, 57h
  ; {a07034fd-6caa-4954-ac3f-97a27216f98a}
  DEFINE_GUID CLSID_QueryAssociations, 0a07034fdh, 6caah, 4954h, 0ach, 3fh, 97h, 0a2h, 72h, 16h, 0f9h, 8ah
  ; {E8025004-1C42-11d2-BE2C-00A0C9A83DA1}
  DEFINE_GUID IID_IColumnProvider, 0e8025004h, 1c42h, 11d2h, 0beh, 2ch, 0h, 0a0h, 0c9h, 0a8h, 3dh, 0a1h
  ; {24F14F02-7B1C-11d1-838f-0000F80461CF}
  DEFINE_GUID CLSID_LinkColumnProvider, 24f14f02h, 7b1ch, 11d1h, 83h, 8fh, 0h, 0h, 0f8h, 4h, 61h, 0cfh
  ; For Internet Shortcut Creation Command
  ; The shell uses this command to allow trident to save off it's per frame data in the shortcut
  ; and to allow it to fire the OnPersist() event on every frame
  ; {93A68750-951A-11d1-946F-000000000000}
  DEFINE_GUID CGID_ShortCut, 93a68750h, 951ah, 11d1h, 94h, 6fh, 0h, 0h, 0h, 0h, 0h, 0h
  ; {FB700430-952C-11d1-946F-000000000000}
  DEFINE_GUID IID_INamedPropertyBag, 0fb700430h, 952ch, 11d1h, 94h, 6fh, 0h, 0h, 0h, 0h, 0h, 0h
  ; {1E796980-9CC5-11D1-A83F-00C04FC99D61}
  DEFINE_GUID CLSID_InternetButtons, 1E796980h, 9CC5h, 11D1h, 0A8h, 3Fh, 00h, 0C0h, 4Fh, 0C9h, 9Dh, 61h
  ; {178F34B8-A282-11d2-86C5-00C04F8EEA99}
  DEFINE_GUID CLSID_MSOButtons, 178f34b8h, 0a282h, 11d2h, 86h, 0c5h, 0h, 0c0h, 4fh, 8eh, 0eah, 99h
  ; {2CE4B5D8-A28F-11d2-86C5-00C04F8EEA99}
  DEFINE_GUID CLSID_ToolbarExtButtons, 2ce4b5d8h, 0a28fh, 11d2h, 86h, 0c5h, 0h, 0c0h, 4fh, 8eh, 0eah, 99h
  ; {CFCCC7A0-A282-11D1-9082-006008059382}
  DEFINE_GUID CLSID_DarwinAppPublisher, 0CFCCC7A0h, 0A282h, 11D1h, 90h, 82h, 00h, 60h, 08h, 05h, 93h, 82h
  ; {7057E952-BD1B-11d1-8919-00C04FC2C836}
  DEFINE_GUID CLSID_DocHostUIHandler, 7057e952h, 0bd1bh, 11d1h, 89h, 19h, 0h, 0c0h, 4fh, 0c2h, 0c8h, 36h
  ; {93F2F68C-1D1B-11d3-A30E-00C04F79ABD1}
  DEFINE_GUID IID_IShellFolder2, 93f2f68ch, 1d1bh, 11d3h, 0a3h, 0eh, 0h, 0c0h, 4fh, 79h, 0abh, 0d1h
  ; {28636aa6-953d-11d2-b5d6-00c04fd918d0}
  PSGUID_SHELLDETAILS equ { 28636aa6h, 953dh, 11d2h, 0b5h, 0d6h, 0h, 0c0h, 4fh, 0d9h, 18h, 0d0h }
  DEFINE_GUID FMTID_ShellDetails, 28636aa6h, 953dh, 11d2h, 0b5h, 0d6h, 0h, 0c0h, 4fh, 0d9h, 18h, 0d0h
  PID_FINDDATA equ 0
  PID_NETRESOURCE equ 1
  PID_DESCRIPTIONID equ 2
  PID_WHICHFOLDER equ 3
  PID_NETWORKLOCATION equ 4
  PID_COMPUTERNAME equ 5
  ; PSGUID_STORAGE comes from ntquery.h
  ;#define PSGUID_STORAGE    {0xb725f130, 0x47ef, 0x101a, 0xa5, 0xf1, 0x02, 0x60, 0x8c, 0x9e, 0xeb, 0xac}
  DEFINE_GUID FMTID_Storage, 0b725f130h, 47efh, 101ah, 0a5h, 0f1h, 02h, 60h, 8ch, 9eh, 0ebh, 0ach
  ; Image properties
  PSGUID_IMAGEPROPERTIES equ { 14b81da1h, 0135h, 4d31h, 96h, 0d9h, 6ch, 0bfh, 0c9h, 67h, 1ah, 99h }
  DEFINE_GUID FMTID_ImageProperties, 14b81da1h, 0135h, 4d31h, 96h, 0d9h, 6ch, 0bfh, 0c9h, 67h, 1ah, 99h
  ; Custom Image Properties (not EXIF tags, which go into the auxiliary image property store)
  ; {7ECD8B0E-C136-4a9b-9411-4EBD6673CCC3}
  PSGUID_CUSTOMIMAGEPROPERTIES equ { 7ecd8b0eh, 0c136h, 4a9bh, 94h, 11h, 4eh, 0bdh, 66h, 73h, 0cch, 0c3h }
  DEFINE_GUID FMTID_CustomImageProperties, 7ecd8b0eh, 0c136h, 4a9bh, 94h, 11h, 4eh, 0bdh, 66h, 73h, 0cch, 0c3h
  ; Library properties
  PSGUID_LIBRARYPROPERTIES equ { 5d76b67fh, 9b3dh, 44bbh, 0b6h, 0aeh, 25h, 0dah, 4fh, 63h, 8ah, 67h }
  DEFINE_GUID FMTID_LibraryProperties, 5d76b67fh, 9b3dh, 44bbh, 0b6h, 0aeh, 25h, 0dah, 4fh, 63h, 8ah, 67h
  ; The GUIDs used to identify shell item attributes (columns). See IShellFolder2::GetDetailsEx implementations...
  ; {9B174B33-40FF-11d2-A27E-00C04FC30871}
  PSGUID_DISPLACED equ { 9b174b33h, 40ffh, 11d2h, 0a2h, 7eh, 0h, 0c0h, 4fh, 0c3h, 8h, 71h }
  DEFINE_GUID FMTID_Displaced, 9b174b33h, 40ffh, 11d2h, 0a2h, 7eh, 0h, 0c0h, 4fh, 0c3h, 8h, 71h
  PID_DISPLACED_FROM equ 2
  PID_DISPLACED_DATE equ 3
  ; {328D8B21-7729-4bfc-954C-902B329D56B0}
  PSGUID_BRIEFCASE equ { 328d8b21h, 7729h, 4bfch, 95h, 4ch, 90h, 2bh, 32h, 9dh, 56h, 0b0h }
  DEFINE_GUID FMTID_Briefcase, 328d8b21h, 7729h, 4bfch, 95h, 4ch, 90h, 2bh, 32h, 9dh, 56h, 0b0h
  PID_SYNC_COPY_IN equ 2
  ; {9B174B34-40FF-11d2-A27E-00C04FC30871}
  PSGUID_MISC equ { 9b174b34h, 40ffh, 11d2h, 0a2h, 7eh, 0h, 0c0h, 4fh, 0c3h, 8h, 71h }
  DEFINE_GUID FMTID_Misc, 9b174b34h, 40ffh, 11d2h, 0a2h, 7eh, 0h, 0c0h, 4fh, 0c3h, 8h, 71h
  PID_MISC_STATUS equ 2
  PID_MISC_ACCESSCOUNT equ 3
  PID_MISC_OWNER equ 4
  PID_HTMLINFOTIPFILE equ 5
  PID_MISC_PICS equ 6
  ; {F2275480-F782-4291-BD94-F13693513AEC}
  PSGUID_WEBVIEW equ { 0f2275480h, 0f782h, 4291h, 0bdh, 94h, 0f1h, 36h, 93h, 51h, 3ah, 0ech }
  DEFINE_GUID FMTID_WebView, 0f2275480h, 0f782h, 4291h, 0bdh, 94h, 0f1h, 36h, 93h, 51h, 3ah, 0ech
  PID_DISPLAY_PROPERTIES equ 0
  PID_INTROTEXT equ 1
  ; {56A3372E-CE9C-11d2-9F0E-006097C686F6}
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
  ; {AEAC19E4-89AE-4508-B9B7-BB867ABEE2ED}
  PSGUID_DRM equ { 0aeac19e4h, 89aeh, 4508h, 0b9h, 0b7h, 0bbh, 86h, 7ah, 0beh, 0e2h, 0edh }
  DEFINE_GUID FMTID_DRM, 0aeac19e4h, 89aeh, 4508h, 0b9h, 0b7h, 0bbh, 86h, 7ah, 0beh, 0e2h, 0edh
  PIDDRSI_PROTECTED equ 2
  PIDDRSI_DESCRIPTION equ 3
  PIDDRSI_PLAYCOUNT equ 4
  PIDDRSI_PLAYSTARTS equ 5
  PIDDRSI_PLAYEXPIRES equ 6
  ; {64440491-4C8B-11D1-8B70-080036B11A03}
  PSGUID_VIDEO equ { 64440491h, 4c8bh, 11d1h, 8bh, 70h, 8h, 0h, 36h, 0b1h, 1ah, 3h }
  ;  FMTID_VideoSummaryInformation property identifiers.  See propkey.h for their types.
  PIDVSI_STREAM_NAME equ 00000002h; "System.Video.StreamName"   (old name "StreamName")

  PIDVSI_FRAME_WIDTH equ 00000003h; "System.Video.FrameWidth"   (old name "FrameWidth")

  PIDVSI_FRAME_HEIGHT equ 00000004h; "System.Video.FrameHeight"  (old name "FrameHeight")

  PIDVSI_TIMELENGTH equ 00000007h;                             (old name "TimeLength")

  PIDVSI_FRAME_COUNT equ 00000005h; "System.Media.FrameCount"   (old name "FrameCount")

  PIDVSI_FRAME_RATE equ 00000006h; "System.Video.FrameRate"    (old name "FrameRate")

  PIDVSI_DATA_RATE equ 00000008h; "System.Video.DataRate"     (old name "DataRate")

  PIDVSI_SAMPLE_SIZE equ 00000009h; "System.Video.SampleSize"   (old name "SampleSize")

  PIDVSI_COMPRESSION equ 0000000Ah; "System.Video.Compression"  (old name "Compression")

  PIDVSI_STREAM_NUMBER equ 0000000Bh; "System.Video.StreamNumber" (old name "StreamNumber")

  ; {64440490-4C8B-11D1-8B70-080036B11A03}
  PSGUID_AUDIO equ { 64440490h, 4c8bh, 11d1h, 8bh, 70h, 8h, 0h, 36h, 0b1h, 1ah, 3h }
  ;  FMTID_AudioSummaryInformation property identifiers
  PIDASI_FORMAT equ 00000002h; VT_BSTR

  PIDASI_TIMELENGTH equ 00000003h; VT_UI4, milliseconds

  PIDASI_AVG_DATA_RATE equ 00000004h; VT_UI4,  Hz

  PIDASI_SAMPLE_RATE equ 00000005h; VT_UI4,  bits

  PIDASI_SAMPLE_SIZE equ 00000006h; VT_UI4,  bits

  PIDASI_CHANNEL_COUNT equ 00000007h; VT_UI4

  PIDASI_STREAM_NUMBER equ 00000008h; VT_UI2

  PIDASI_STREAM_NAME equ 00000009h; VT_LPWSTR

  PIDASI_COMPRESSION equ 0000000Ah; VT_LPWSTR

  ; {305CA226-D286-468e-B848-2B2E8E697B74}
  PSGUID_CONTROLPANEL equ { 305ca226h, 0d286h, 468eh, 0b8h, 48h, 2bh, 2eh, 8eh, 69h, 7bh, 74h }
  PID_CONTROLPANEL_CATEGORY equ 2
  ; {9B174B35-40FF-11d2-A27E-00C04FC30871}
  PSGUID_VOLUME equ { 9b174b35h, 40ffh, 11d2h, 0a2h, 7eh, 0h, 0c0h, 4fh, 0c3h, 8h, 71h }
  DEFINE_GUID FMTID_Volume, 9b174b35h, 40ffh, 11d2h, 0a2h, 7eh, 0h, 0c0h, 4fh, 0c3h, 8h, 71h
  PID_VOLUME_FREE equ 2
  PID_VOLUME_CAPACITY equ 3
  PID_VOLUME_FILESYSTEM equ 4
  ; {D8C3986F-813B-449c-845D-87B95D674ADE}
  PSGUID_SHARE equ { 0d8c3986fh, 813bh, 449ch, 84h, 5dh, 87h, 0b9h, 5dh, 67h, 4ah, 0deh }
  PID_SHARE_CSC_STATUS equ 2; server or share status, "online" "offline"

  ; {B9B4B3FC-2B51-4a42-B5D8-324146AFCF25}
  PSGUID_LINK equ { 0b9b4b3fch, 2b51h, 4a42h, 0b5h, 0d8h, 32h, 41h, 46h, 0afh, 0cfh, 25h }
  PID_LINK_TARGET equ 2
  PID_LINK_TARGET_TYPE equ 3
  PSGUID_QUERY_D equ { 49691c90h, 7e17h, 101ah, 0a9h, 1ch, 08h, 00h, 2bh, 2eh, 0cdh, 0a9h }
  DEFINE_GUID FMTID_Query, 49691c90h, 7e17h, 101ah, 0a9h, 1ch, 08h, 00h, 2bh, 2eh, 0cdh, 0a9h
  PID_QUERY_RANK equ 2
  ; FMTID_SummaryInformation, see OLE docs for PID_ values for these
  PSGUID_SUMMARYINFORMATION equ { 0f29f85e0h, 4ff9h, 1068h, 0abh, 91h, 08h, 00h, 2bh, 27h, 0b3h, 0d9h }
  ; FMTID_DocumentSummaryInformation, see OLE docs on the PID_ values for this
  PSGUID_DOCUMENTSUMMARYINFORMATION equ { 0d5cdd502h, 2e9ch, 101bh, 93h, 97h, 08h, 00h, 2bh, 2ch, 0f9h, 0aeh }
  ; FMTID_MediaFileSummaryInformation, see propidl.h PID_ values for this
  PSGUID_MEDIAFILESUMMARYINFORMATION equ { 64440492h, 4c8bh, 11d1h, 8bh, 70h, 08h, 00h, 36h, 0b1h, 1ah, 03h }
  ; FMTID_ImageSummaryInformation
  PSGUID_IMAGESUMMARYINFORMATION equ { 6444048fh, 4c8bh, 11d1h, 8bh, 70h, 8h, 00h, 36h, 0b1h, 1ah, 03h }
  ; {0E700BE1-9DB6-11d1-A1CE-00C04FD75D13}
  DEFINE_GUID IID_IEnumExtraSearch, 0e700be1h, 9db6h, 11d1h, 0a1h, 0ceh, 0h, 0c0h, 4fh, 0d7h, 5dh, 13h
  ; {FFB8655F-81B9-4fce-B89C-9A6BA76D13E7}
  DEFINE_GUID CLSID_HWShellExecute, 0ffb8655fh, 81b9h, 4fceh, 0b8h, 9ch, 9ah, 6bh, 0a7h, 6dh, 13h, 0e7h
  ; {4657278A-411B-11d2-839A-00C04FD918D0}
  DEFINE_GUID CLSID_DragDropHelper, 4657278ah, 411bh, 11d2h, 83h, 9ah, 0h, 0c0h, 4fh, 0d9h, 18h, 0d0h
  ; {3050f3BB-98b5-11cf-bb82-00aa00bdce0b}
  DEFINE_GUID CLSID_CAnchorBrowsePropertyPage, 3050f3BBh, 98b5h, 11cfh, 0bbh, 82h, 00h, 0aah, 00h, 0bdh, 0ceh, 0bh
  ; {3050f3B3-98b5-11cf-bb82-00aa00bdce0b}
  DEFINE_GUID CLSID_CImageBrowsePropertyPage, 3050f3B3h, 98b5h, 11cfh, 0bbh, 82h, 00h, 0aah, 00h, 0bdh, 0ceh, 0bh
  ; {3050f3B4-98b5-11cf-bb82-00aa00bdce0b}
  DEFINE_GUID CLSID_CDocBrowsePropertyPage, 3050f3B4h, 98b5h, 11cfh, 0bbh, 82h, 00h, 0aah, 00h, 0bdh, 0ceh, 0bh
  ; {01E18D10-4D8B-11d2-855D-006008059367}
  DEFINE_GUID IID_IFileSystemBindData, 1e18d10h, 4d8bh, 11d2h, 85h, 5dh, 0h, 60h, 8h, 5h, 93h, 67h
  ; {49E1B500-4636-11d3-97F7-00C04F45D0B3}
  DEFINE_GUID SID_STopWindow, 49e1b500h, 4636h, 11d3h, 97h, 0f7h, 0h, 0c0h, 4fh, 45h, 0d0h, 0b3h
  ; {889A935D-971E-4B12-B90C-24DFC9E1E5E8}
  DEFINE_GUID SID_SGetViewFromViewDual, 889A935Dh, 971Eh, 4B12h, 0B9h, 0Ch, 24h, 0DFh, 0C9h, 0E1h, 0E5h, 0E8h
  ; {FEF10FA2-355E-4e06-9381-9B24D7F7CC88}
  DEFINE_GUID CLSID_FolderItem, 0fef10fa2h, 355eh, 4e06h, 93h, 81h, 9bh, 24h, 0d7h, 0f7h, 0cch, 88h
  ; {53C74826-AB99-4d33-ACA4-3117F51D3788}
  DEFINE_GUID CLSID_FolderItemsMultiLevel, 53c74826h, 0ab99h, 4d33h, 0ach, 0a4h, 31h, 17h, 0f5h, 1dh, 37h, 88h
  ; {D969A300-E7FF-11d0-A93B-00A0C90F2719}
  DEFINE_GUID CLSID_NewMenu, 0d969a300h, 0e7ffh, 11d0h, 0a9h, 3bh, 0h, 0a0h, 0c9h, 0fh, 27h, 19h
  ;  BHIDs for IShellItem::BindToHandler()
  ; use this for IShellFolder::BindToObject() objects; IShellFolder
  ;  {3981e224-f559-11d3-8e3a-00c04f6837d5}
  DEFINE_GUID BHID_SFObject, 3981e224h, 0f559h, 11d3h, 8eh, 3ah, 00h, 0c0h, 4fh, 68h, 37h, 0d5h
  ; use this for IShellFolder::GetUIObject() objects; IContextMenu, IDataObject, IDropTarget, IQueryAssociation, etc.
  ;  {3981e225-f559-11d3-8e3a-00c04f6837d5}
  DEFINE_GUID BHID_SFUIObject, 3981e225h, 0f559h, 11d3h, 8eh, 3ah, 00h, 0c0h, 4fh, 68h, 37h, 0d5h
  ; use this for IShellFolder::CreateViewObject() objects; IShellView, IDropTarget, IContextMenu
  ;  {3981e226-f559-11d3-8e3a-00c04f6837d5}
  DEFINE_GUID BHID_SFViewObject, 3981e226h, 0f559h, 11d3h, 8eh, 3ah, 00h, 0c0h, 4fh, 68h, 37h, 0d5h
  ; use this for storage objects like IStream, IPropertyStore, IStorage
  ;  {3981e227-f559-11d3-8e3a-00c04f6837d5}
  DEFINE_GUID BHID_Storage, 3981e227h, 0f559h, 11d3h, 8eh, 3ah, 00h, 0c0h, 4fh, 68h, 37h, 0d5h
  ; use this to get an IStream for the item
  ; {1CEBB3AB-7C10-499a-A417-92CA16C4CB83}
  DEFINE_GUID BHID_Stream, 1cebb3abh, 7c10h, 499ah, 0a4h, 17h, 92h, 0cah, 16h, 0c4h, 0cbh, 83h
  ; use this to get an IRandomAccessStream for the item
  ; {f16fc93b-77ae-4cfe-bda7-a866eea6878d}
  DEFINE_GUID BHID_RandomAccessStream, 0f16fc93bh, 77aeh, 4cfeh, 0bdh, 0a7h, 0a8h, 66h, 0eeh, 0a6h, 87h, 8dh
  ; use this to deref the item if it is a link to get its target item, use IShellItem
  ;  {3981e228-f559-11d3-8e3a-00c04f6837d5}
  DEFINE_GUID BHID_LinkTargetItem, 3981e228h, 0f559h, 11d3h, 8eh, 3ah, 00h, 0c0h, 4fh, 68h, 37h, 0d5h
  ; if the item is a folder use this to get an IEnumShellItems that enumerates the storage contents
  ; {4621A4E3-F0D6-4773-8A9C-46E77B174840}
  DEFINE_GUID BHID_StorageEnum, 4621a4e3h, 0f0d6h, 4773h, 8ah, 9ch, 46h, 0e7h, 7bh, 17h, 48h, 40h
  ; if the item is a folder use this to get an ITransferSource or ITransferDestiation object
  ; {5D080304-FE2C-48fc-84CE-CF620B0F3C53}
  DEFINE_GUID BHID_Transfer, 0d5e346a1h, 0f753h, 4932h, 0b4h, 3h, 45h, 74h, 80h, 0eh, 24h, 98h
  ; use this to get an IPropertyStore or IPropertyStoreFactory
  ; to have more control over the property store for the item
  ; {0384e1a4-1523-439c-a4c8-ab911052f586}
  DEFINE_GUID BHID_PropertyStore, 0384e1a4h, 1523h, 439ch, 0a4h, 0c8h, 0abh, 91h, 10h, 52h, 0f5h, 86h
  ; use this to get IExtractImage / IThumbnailProvider for an item
  ; {7b2e650a-8e20-4f4a-b09e-6597afc72fb0}
  DEFINE_GUID BHID_ThumbnailHandler, 7b2e650ah, 8e20h, 4f4ah, 0b0h, 9eh, 65h, 97h, 0afh, 0c7h, 2fh, 0b0h
  ; if the item is a folder use this to get an IEnumShellItems that enumerates all items
  ; in the folder including folders, non folders and hidden items
  ; {94f60519-2850-4924-aa5a-d15e84868039}
  DEFINE_GUID BHID_EnumItems, 94f60519h, 2850h, 4924h, 0aah, 5ah, 0d1h, 5eh, 84h, 86h, 80h, 39h
  ; use this to get an IDataObject for an item or an array of items IShellItem/IShellItemArray::BindToHandler()
  ; {B8C0BD9F-ED24-455c-83E6-D5390C4FE8C4}
  DEFINE_GUID BHID_DataObject, 0b8c0bd9fh, 0ed24h, 455ch, 83h, 0e6h, 0d5h, 39h, 0ch, 4fh, 0e8h, 0c4h
  ; use this to get an IQueryAssociations for an item or an array of items IShellItem/IShellItemArray::BindToHandler()
  ; {bea9ef17-82f1-4f60-9284-4f8db75c3be9}
  DEFINE_GUID BHID_AssociationArray, 0bea9ef17h, 82f1h, 4f60h, 92h, 84h, 4fh, 8dh, 0b7h, 5ch, 3bh, 0e9h
  ; use this to get an IFilter for an item
  ; {38d08778-f557-4690-9ebf-ba54706ad8f7}
  DEFINE_GUID BHID_Filter, 38d08778h, 0f557h, 4690h, 9eh, 0bfh, 0bah, 54h, 70h, 6ah, 0d8h, 0f7h
  ; use this to retrieve an IEnumAssocHandlers that enumerates the association handlers for the given item.  Returns an
  ; enumeration of recommended handlers, similar to calling SHAssocEnumHandlers with ASSOC_FILTER_RECOMMENDED.
  ; {b8ab0b9c-c2ec-4f7a-918d-314900e6280a}
  DEFINE_GUID BHID_EnumAssocHandlers, 0b8ab0b9ch, 0c2ech, 4f7ah, 91h, 8dh, 31h, 49h, 00h, 0e6h, 28h, 0ah
  ; use this to get an IStorageItem for an item
  ; {404e2109-77d2-4699-a5a0-4fdf10db9837}
  DEFINE_GUID BHID_StorageItem, 404e2109h, 77d2h, 4699h, 0a5h, 0a0h, 4fh, 0dfh, 10h, 0dbh, 98h, 37h
  ; use this to retrieve an IFilePlaceholder that provides placeholder file functionality.
  ; {8677DCEB-AAE0-4005-8D3D-547FA852F825}
  DEFINE_GUID BHID_FilePlaceholder, 8677dcebh, 0aae0h, 4005h, 8dh, 3dh, 54h, 7fh, 0a8h, 52h, 0f8h, 25h
  ; {3E9C9A51-D4AA-4870-B47C-7424B491F1CC}
  DEFINE_GUID CATID_FilePlaceholderMergeHandler, 3e9c9a51h, 0d4aah, 4870h, 0b4h, 7ch, 74h, 24h, 0b4h, 91h, 0f1h, 0cch
  if _WIN32_IE ge 0600h
    ; {faadfc40-b777-4b69-aa81-77035ef0e6e8}
    DEFINE_GUID SID_CtxQueryAssociations, 0faadfc40h, 0b777h, 4b69h, 0aah, 81h, 77h, 03h, 5eh, 0f0h, 0e6h, 0e8h
  endif
  ; _WIN32_IE >= 0x0600
  ; {0x87D605E0L, 0xC511, 0x11CF, 0x89, 0xA9, 0x00, 0xA0, 0xC9, 0x05, 0x41, 0x29};
  DEFINE_GUID IID_IDocViewSite, 87D605E0h, 0C511h, 11CFh, 89h, 0A9h, 00h, 0A0h, 0C9h, 05h, 41h, 29h
  ; {0E5CBF21-D15F-11d0-8301-00AA005B4383}
  DEFINE_GUID CLSID_QuickLinks, 0e5cbf21h, 0d15fh, 11d0h, 83h, 1h, 0h, 0aah, 0h, 5bh, 43h, 83h
  ; The IShellFolder band
  ; D82BE2B0-5764-11D0-A96E-00C04FD705A2
  DEFINE_GUID CLSID_ISFBand, 0D82BE2B0h, 5764h, 11D0h, 0A9h, 6Eh, 00h, 0C0h, 4Fh, 0D7h, 05h, 0A2h
  ; { 0x4434FF80L, 0xEF4C, 0x11CE, { 0xAE, 0x65, 0x08, 0x00, 0x2B, 0x2E, 0x12, 0x62 } };
  DEFINE_GUID IID_CDefView, 4434FF80h, 0EF4Ch, 11CEh, 0AEh, 65h, 08h, 00h, 2Bh, 2Eh, 12h, 62h
  ; {6D5313C0-8C62-11D1-B2CD-006097DF8C11}
  DEFINE_GUID CLSID_ShellFldSetExt, 6D5313C0h, 8C62h, 11D1h, 0B2h, 0CDh, 00h, 60h, 97h, 0DFh, 8Ch, 11h
  DEFINE_GUID SID_SMenuBandChild, 0ed9cc020h, 8b9h, 11d1h, 98h, 23h, 0h, 0c0h, 4fh, 0d9h, 19h, 72h
  DEFINE_GUID SID_SMenuBandParent, 8c278eech, 3eabh, 11d1h, 8ch, 0b0h, 0h, 0c0h, 4fh, 0d9h, 18h, 0d0h
  ; D1E7AFEB-6A2E-11d0-8C78-00C04FD918B4
  DEFINE_GUID SID_SMenuPopup, 0D1E7AFEBh, 6A2Eh, 11d0h, 8Ch, 78h, 0h, 0C0h, 4Fh, 0D9h, 18h, 0B4h
  ; {165EBAF4-6D51-11d2-83AD-00C04FD918D0}
  DEFINE_GUID SID_SMenuBandBottomSelected, 165ebaf4h, 6d51h, 11d2h, 83h, 0adh, 0h, 0c0h, 4fh, 0d9h, 18h, 0d0h
  DEFINE_GUID SID_SMenuBandBottom, 743ca664h, 0debh, 11d1h, 98h, 25h, 0h, 0c0h, 4fh, 0d9h, 19h, 72h
  ; {A6C17EB4-2D65-11d2-838F-00C04FD918D0}
  DEFINE_GUID SID_MenuShellFolder, 0a6c17eb4h, 2d65h, 11d2h, 83h, 8fh, 0h, 0c0h, 4fh, 0d9h, 18h, 0d0h
  ; {39545874-7162-465e-b783-2aa1874fef81}
  DEFINE_GUID SID_SMenuBandContextMenuModifier, 39545874h, 7162h, 465eh, 0b7h, 83h, 2ah, 0a1h, 87h, 4fh, 0efh, 81h
  ; {164BBD86-1D0D-4de0-9A3B-D9729647C2B8}
  DEFINE_GUID SID_SMenuBandBKContextMenu, 164bbd86h, 1d0dh, 4de0h, 9ah, 3bh, 0d9h, 72h, 96h, 47h, 0c2h, 0b8h
  ;Command Group ID for MenuDeskBar
  ; {5C9F0A12-959E-11d0-A3A4-00A0C9082636}
  DEFINE_GUID CGID_MENUDESKBAR, 5c9f0a12h, 959eh, 11d0h, 0a3h, 0a4h, 0h, 0a0h, 0c9h, 8h, 26h, 36h
  DEFINE_GUID SID_SMenuBandTop, 9493a810h, 0ec38h, 11d0h, 0bch, 46h, 0h, 0aah, 0h, 6ch, 0e2h, 0f5h
  ; {40B96610-B522-11d1-B3B4-00AA006EFDE7}
  DEFINE_GUID CLSID_MenuToolbarBase, 40b96610h, 0b522h, 11d1h, 0b3h, 0b4h, 0h, 0aah, 0h, 6eh, 0fdh, 0e7h
  ; {596A9A94-013E-11d1-8D34-00A0C90F2719}
  DEFINE_GUID IID_IBanneredBar, 596a9a94h, 13eh, 11d1h, 8dh, 34h, 0h, 0a0h, 0c9h, 0fh, 27h, 19h
  ; {E13EF4E4-D2F2-11d0-9816-00C04FD91972}
  DEFINE_GUID CLSID_MenuBandSite, 0e13ef4e4h, 0d2f2h, 11d0h, 98h, 16h, 0h, 0c0h, 4fh, 0d9h, 19h, 72h
  ; {80F30233-B7DF-11d2-A33B-006097DF5BD4}
  DEFINE_GUID SID_SCommDlgBrowser, 80f30233h, 0b7dfh, 11d2h, 0a3h, 3bh, 0h, 60h, 97h, 0dfh, 5bh, 0d4h
  ; These GUIDs may be assigned to the CREDENTIAL_PROVIDER_FIELD_DESCRIPTOR::guidFieldType
  ; member by Microsoft ICredentialProvider implementations.
  ; {da15bbe8-954sd-4fd3-b0f4-1fb5b90b174b}
  DEFINE_GUID CPFG_LOGON_USERNAME, 0da15bbe8h, 954dh, 4fd3h, 0b0h, 0f4h, 1fh, 0b5h, 0b9h, 0bh, 17h, 4bh
  ; {60624cfa-a477-47b1-8a8e-3a4a19981827}
  DEFINE_GUID CPFG_LOGON_PASSWORD, 60624cfah, 0a477h, 47b1h, 8ah, 8eh, 3ah, 4ah, 19h, 98h, 18h, 27h
  ; {3e1ecf69-568c-4d96-9d59-46444174e2d6}
  DEFINE_GUID CPFG_SMARTCARD_USERNAME, 3e1ecf69h, 568ch, 4d96h, 9dh, 59h, 46h, 44h, 41h, 74h, 0e2h, 0d6h
  ; {4fe5263b-9181-46c1-b0a4-9dedd4db7dea}
  DEFINE_GUID CPFG_SMARTCARD_PIN, 4fe5263bh, 9181h, 46c1h, 0b0h, 0a4h, 9dh, 0edh, 0d4h, 0dbh, 7dh, 0eah
  ; {2d837775-f6cd-464e-a745-482fd0b47493}
  DEFINE_GUID CPFG_CREDENTIAL_PROVIDER_LOGO, 2d837775h, 0f6cdh, 464eh, 0a7h, 45h, 48h, 2fh, 0d0h, 0b4h, 74h, 93h
  ; {286BBFF3-BAD4-438F-B007-79B7267C3D48}
  DEFINE_GUID CPFG_CREDENTIAL_PROVIDER_LABEL, 286bbff3h, 0bad4h, 438fh, 0b0h, 7h, 79h, 0b7h, 26h, 7ch, 3dh, 48h
  ; {0b7b0ad8-cc36-4d59-802b-82f714fa7022}
  DEFINE_GUID CPFG_STANDALONE_SUBMIT_BUTTON, 0b7b0ad8h, 0cc36h, 4d59h, 80h, 2bh, 82h, 0f7h, 14h, 0fah, 70h, 22h
  ; {088fa508-94a6-4430-a4cb-6fc6e3c0b9e2}
  DEFINE_GUID CPFG_STYLE_LINK_AS_BUTTON, 088fa508h, 94a6h, 4430h, 0a4h, 0cbh, 6fh, 0c6h, 0e3h, 0c0h, 0b9h, 0e2h
  ;  Known Folder IDs
  include knownfolders.inc
  ; some known folder types
  ; FOLDERTYPEID_Invalid:              {57807898-8c4f-4462-bb63-71042380b109}
  DEFINE_GUID FOLDERTYPEID_Invalid, 57807898h, 8c4fh, 4462h, 0bbh, 63h, 71h, 04h, 23h, 80h, 0b1h, 09h
  ; FOLDERTYPEID_Generic:              {5c4f28b5-f869-4e84-8e60-f11db97c5cc7}
  DEFINE_GUID FOLDERTYPEID_Generic, 5c4f28b5h, 0f869h, 4e84h, 8eh, 60h, 0f1h, 1dh, 0b9h, 7ch, 5ch, 0c7h
  ; FOLDERTYPEID_GenericSearchResults: {7fde1a1e-8b31-49a5-93b8-6be14cfa4943}
  DEFINE_GUID FOLDERTYPEID_GenericSearchResults, 7fde1a1eh, 8b31h, 49a5h, 93h, 0b8h, 6bh, 0e1h, 4ch, 0fah, 49h, 43h
  ; FOLDERTYPEID_GenericLibrary:       {5f4eab9a-6833-4f61-899d-31cf46979d49}
  DEFINE_GUID FOLDERTYPEID_GenericLibrary, 5f4eab9ah, 6833h, 4f61h, 89h, 9dh, 31h, 0cfh, 46h, 97h, 9dh, 49h
  ; FOLDERTYPEID_Documents:            {7d49d726-3c21-4f05-99aa-fdc2c9474656}
  DEFINE_GUID FOLDERTYPEID_Documents, 7d49d726h, 3c21h, 4f05h, 99h, 0aah, 0fdh, 0c2h, 0c9h, 47h, 46h, 56h
  ; FOLDERTYPEID_Pictures:             {b3690e58-e961-423b-b687-386ebfd83239}
  DEFINE_GUID FOLDERTYPEID_Pictures, 0b3690e58h, 0e961h, 423bh, 0b6h, 87h, 38h, 6eh, 0bfh, 0d8h, 32h, 39h
  ; FOLDERTYPEID_Music:                {94d6ddcc-4a68-4175-a374-bd584a510b78}
  DEFINE_GUID FOLDERTYPEID_Music, 94d6ddcch, 4a68h, 4175h, 0a3h, 74h, 0bdh, 58h, 4ah, 51h, 0bh, 78h
  ; FOLDERTYPEID_Videos:               {5fa96407-7e77-483c-ac93-691d05850de8}
  DEFINE_GUID FOLDERTYPEID_Videos, 5fa96407h, 7e77h, 483ch, 0ach, 93h, 69h, 1dh, 05h, 85h, 0dh, 0e8h
  ; FOLDERTYPEID_Downloads:            {885a186e-a440-4ada-812b-db871b942259}
  DEFINE_GUID FOLDERTYPEID_Downloads, 885a186eh, 0a440h, 4adah, 81h, 2bh, 0dbh, 87h, 1bh, 94h, 22h, 59h
  ; FOLDERTYPEID_UserFiles:            {CD0FC69B-71E2-46e5-9690-5BCD9F57AAB3}
  DEFINE_GUID FOLDERTYPEID_UserFiles, 0cd0fc69bh, 71e2h, 46e5h, 96h, 90h, 5bh, 0cdh, 9fh, 57h, 0aah, 0b3h
  ; FOLDERTYPID_UsersLibraries         {C4D98F09-6124-4fe0-9942-826416082DA9}
  DEFINE_GUID FOLDERTYPEID_UsersLibraries, 0c4d98f09h, 6124h, 4fe0h, 99h, 42h, 82h, 64h, 16h, 8h, 2dh, 0a9h
  ; FOLDERTYPEID_OtherUsers,           {B337FD00-9DD5-4635-A6D4-DA33FD102B7A}
  DEFINE_GUID FOLDERTYPEID_OtherUsers, 0b337fd00h, 9dd5h, 4635h, 0a6h, 0d4h, 0dah, 33h, 0fdh, 10h, 2bh, 7ah
  ; {7F2F5B96-FF74-41da-AFD8-1C78A5F3AEA2}
  DEFINE_GUID FOLDERTYPEID_PublishedItems, 7f2f5b96h, 0ff74h, 41dah, 0afh, 0d8h, 1ch, 78h, 0a5h, 0f3h, 0aeh, 0a2h
  ; FOLDERTYPEID_Communications:       {91475fe5-586b-4eba-8d75-d17434b8cdf6}
  DEFINE_GUID FOLDERTYPEID_Communications, 91475fe5h, 586bh, 4ebah, 8dh, 75h, 0d1h, 74h, 34h, 0b8h, 0cdh, 0f6h
  ; FOLDERTYPEID_Contacts:             {de2b70ec-9bf7-4a93-bd3d-243f7881d492}
  DEFINE_GUID FOLDERTYPEID_Contacts, 0de2b70ech, 9bf7h, 4a93h, 0bdh, 3dh, 24h, 3fh, 78h, 81h, 0d4h, 92h
  ; FOLDERTYPEID_StartMenu:            {ef87b4cb-f2ce-4785-8658-4ca6c63e38c6}
  DEFINE_GUID FOLDERTYPEID_StartMenu, 0ef87b4cbh, 0f2ceh, 4785h, 86h, 58h, 4ch, 0a6h, 0c6h, 3eh, 38h, 0c6h
  ; FOLDERTYPEID_RecordedTV:           {5557a28f-5da6-4f83-8809-c2c98a11a6fa}
  DEFINE_GUID FOLDERTYPEID_RecordedTV, 5557a28fh, 5da6h, 4f83h, 88h, 09h, 0c2h, 0c9h, 8ah, 11h, 0a6h, 0fah
  ; FOLDERTYPEID_SavedGames:           {d0363307-28cb-4106-9f23-2956e3e5e0e7}
  DEFINE_GUID FOLDERTYPEID_SavedGames, 0d0363307h, 28cbh, 4106h, 9fh, 23h, 29h, 56h, 0e3h, 0e5h, 0e0h, 0e7h
  ; FOLDERTYPEID_OpenSearch:           {8faf9629-1980-46ff-8023-9dceab9c3ee3}
  DEFINE_GUID FOLDERTYPEID_OpenSearch, 8faf9629h, 1980h, 46ffh, 80h, 23h, 9dh, 0ceh, 0abh, 9ch, 3eh, 0e3h
  ; FOLDERTYPEID_SearchConnector:      {982725ee-6f47-479e-b447-812bfa7d2e8f}
  DEFINE_GUID FOLDERTYPEID_SearchConnector, 982725eeh, 6f47h, 479eh, 0b4h, 47h, 81h, 2bh, 0fah, 7dh, 2eh, 8fh
  ; FOLDERTYPEID_AccountPictures:      {db2a5d8f-06e6-4007-aba6-af877d526ea6}
  DEFINE_GUID FOLDERTYPEID_AccountPictures, 0db2a5d8fh, 06e6h, 4007h, 0abh, 0a6h, 0afh, 87h, 7dh, 52h, 6eh, 0a6h
  ; foldertypes that do not have top views are below
  ; FOLDERTYPEID_Games Folder          {b689b0d0-76d3-4cbb-87f7-585d0e0ce070}
  DEFINE_GUID FOLDERTYPEID_Games, 0b689b0d0h, 76d3h, 4cbbh, 87h, 0f7h, 58h, 5dh, 0eh, 0ch, 0e0h, 70h
  ; category view of control panel
  ; FOLDERTYPEID_ControlPanelCategory: {de4f0660-fa10-4b8f-a494-068b20b22307}
  DEFINE_GUID FOLDERTYPEID_ControlPanelCategory, 0de4f0660h, 0fa10h, 4b8fh, 0a4h, 94h, 06h, 8bh, 20h, 0b2h, 23h, 07h
  ; classic-mode control panel
  ; FOLDERTYPEID_ControlPanelClassic:  {0c3794f3-b545-43aa-a329-c37430c58d2a}
  DEFINE_GUID FOLDERTYPEID_ControlPanelClassic, 0c3794f3h, 0b545h, 43aah, 0a3h, 29h, 0c3h, 74h, 30h, 0c5h, 8dh, 2ah
  ; prnfldr
  ; FOLDERTYPEID_Printers:             {2c7bbec6-c844-4a0a-91fa-cef6f59cfda1}
  DEFINE_GUID FOLDERTYPEID_Printers, 2c7bbec6h, 0c844h, 4a0ah, 91h, 0fah, 0ceh, 0f6h, 0f5h, 9ch, 0fdh, 0a1h
  ; bbckfldr
  ; FOLDERTYPEID_RecycleBin:           {d6d9e004-cd87-442b-9d57-5e0aeb4f6f72}
  DEFINE_GUID FOLDERTYPEID_RecycleBin, 0d6d9e004h, 0cd87h, 442bh, 9dh, 57h, 5eh, 0ah, 0ebh, 4fh, 6fh, 72h
  ; software explorer for ARP
  ; FOLDERTYPEID_SoftwareExplorer:     {d674391b-52d9-4e07-834e-67c98610f39d}
  DEFINE_GUID FOLDERTYPEID_SoftwareExplorer, 0d674391bh, 52d9h, 4e07h, 83h, 4eh, 67h, 0c9h, 86h, 10h, 0f3h, 9dh
  ; ZIP folders
  ; FOLDERTYPEID_CompressedFolder:     {80213e82-bcfd-4c4f-8817-bb27601267a9}
  DEFINE_GUID FOLDERTYPEID_CompressedFolder, 80213e82h, 0bcfdh, 4c4fh, 88h, 17h, 0bbh, 27h, 60h, 12h, 67h, 0a9h
  ; NetworkExplorerFolder
  ; FOLDERTYPEID_NetworkExplorer:      {25CC242B-9A7C-4f51-80E0-7A2928FEBE42}
  DEFINE_GUID FOLDERTYPEID_NetworkExplorer, 25cc242bh, 9a7ch, 4f51h, 80h, 0e0h, 7ah, 29h, 28h, 0feh, 0beh, 42h
  ; searches folder
  ; FOLDERTYPEID_Searches:             {0b0ba2e3-405f-415e-a6ee-cad625207853}
  DEFINE_GUID FOLDERTYPEID_Searches, 0b0ba2e3h, 405fh, 415eh, 0a6h, 0eeh, 0cah, 0d6h, 25h, 20h, 78h, 53h
  ; search home
  ; FOLDERTYPEID_SearchHome:           {834d8a44-0974-4ed6-866e-f203d80b3810}
  DEFINE_GUID FOLDERTYPEID_SearchHome, 834d8a44h, 0974h, 4ed6h, 86h, 6eh, 0f2h, 03h, 0d8h, 0bh, 38h, 10h
  ; FOLDERTYPEID_StorageProviderGeneric:   {4F01EBC5-2385-41f2-A28E-2C5C91FB56E0}
  DEFINE_GUID FOLDERTYPEID_StorageProviderGeneric, 4F01EBC5h, 2385h, 41f2h, 0A2h, 8Eh, 2Ch, 5Ch, 91h, 0FBh, 56h, 0E0h
  ; FOLDERTYPEID_StorageProviderDocuments: {DD61BD66-70E8-48dd-9655-65C5E1AAC2D1}
  DEFINE_GUID FOLDERTYPEID_StorageProviderDocuments, 0DD61BD66h, 70E8h, 48ddh, 96h, 55h, 65h, 0C5h, 0E1h, 0AAh, 0C2h, 0D1h
  ; FOLDERTYPEID_StorageProviderPictures:  {71D642A9-F2B1-42cd-AD92-EB9300C7CC0A}
  DEFINE_GUID FOLDERTYPEID_StorageProviderPictures, 71d642a9h, 0f2b1h, 42cdh, 0adh, 92h, 0ebh, 93h, 0h, 0c7h, 0cch, 0ah
  ; FOLDERTYPEID_StorageProviderMusic:     {672ECD7E-AF04-4399-875C-0290845B6247}
  DEFINE_GUID FOLDERTYPEID_StorageProviderMusic, 672ECD7Eh, 0AF04h, 4399h, 87h, 5Ch, 02h, 90h, 84h, 5Bh, 62h, 47h
  ; FOLDERTYPEID_StorageProviderVideos:    {51294DA1-D7B1-485b-9E9A-17CFFE33E187}
  DEFINE_GUID FOLDERTYPEID_StorageProviderVideos, 51294DA1h, 0D7B1h, 485bh, 9Eh, 9Ah, 17h, 0CFh, 0FEh, 33h, 0E1h, 87h
  ; Sync Manager object IDs.  These are GUIDs used in calls to the GetObject()
  ; method on ISyncMgrHandler and ISyncMgrSyncItem, defined in SyncMgr.idl.
  ; {6DBC85C3-5D07-4c72-A777-7FEC78072C06}
  DEFINE_GUID SYNCMGR_OBJECTID_Icon, 6dbc85c3h, 5d07h, 4c72h, 0a7h, 77h, 7fh, 0ech, 78h, 7h, 2ch, 6h
  ; {4BEF34B9-A786-4075-BA88-0C2B9D89A98F}
  DEFINE_GUID SYNCMGR_OBJECTID_EventStore, 4bef34b9h, 0a786h, 4075h, 0bah, 88h, 0ch, 2bh, 9dh, 89h, 0a9h, 8fh
  ; {D78181F4-2389-47e4-A960-60BCC2ED930B}
  DEFINE_GUID SYNCMGR_OBJECTID_ConflictStore, 0d78181f4h, 2389h, 47e4h, 0a9h, 60h, 60h, 0bch, 0c2h, 0edh, 93h, 0bh
  ; {57CBB584-E9B4-47ae-A120-C4DF3335DEE2}
  DEFINE_GUID SYNCMGR_OBJECTID_BrowseContent, 57cbb584h, 0e9b4h, 47aeh, 0a1h, 20h, 0c4h, 0dfh, 33h, 35h, 0deh, 0e2h
  ; {EDC6F3E3-8441-4109-ADF3-6C1CA0B7DE47}
  DEFINE_GUID SYNCMGR_OBJECTID_ShowSchedule, 0edc6f3e3h, 8441h, 4109h, 0adh, 0f3h, 6ch, 1ch, 0a0h, 0b7h, 0deh, 47h
  ; {D882D80B-E7AA-49ed-86B7-E6E1F714CDFE}
  DEFINE_GUID SYNCMGR_OBJECTID_QueryBeforeActivate, 0d882d80bh, 0e7aah, 49edh, 86h, 0b7h, 0e6h, 0e1h, 0f7h, 14h, 0cdh, 0feh
  ; {A0EFC282-60E0-460e-9374-EA88513CFC80}
  DEFINE_GUID SYNCMGR_OBJECTID_QueryBeforeDeactivate, 0a0efc282h, 60e0h, 460eh, 93h, 74h, 0eah, 88h, 51h, 3ch, 0fch, 80h
  ; {04CBF7F0-5BEB-4de1-BC90-908345C480F6}
  DEFINE_GUID SYNCMGR_OBJECTID_QueryBeforeEnable, 4cbf7f0h, 5bebh, 4de1h, 0bch, 90h, 90h, 83h, 45h, 0c4h, 80h, 0f6h
  ; {BB5F64AA-F004-4eb5-8E4D-26751966344C}
  DEFINE_GUID SYNCMGR_OBJECTID_QueryBeforeDisable, 0bb5f64aah, 0f004h, 4eb5h, 8eh, 4dh, 26h, 75h, 19h, 66h, 34h, 4ch
  ; {F76C3397-AFB3-45d7-A59F-5A49E905437E}
  DEFINE_GUID SYNCMGR_OBJECTID_QueryBeforeDelete, 0f76c3397h, 0afb3h, 45d7h, 0a5h, 9fh, 5ah, 49h, 0e9h, 5h, 43h, 7eh
  ; {2203bdc1-1af1-4082-8c30-28399f41384c}
  DEFINE_GUID SYNCMGR_OBJECTID_EventLinkClick, 2203bdc1h, 1af1h, 4082h, 8ch, 30h, 28h, 39h, 9fh, 41h, 38h, 4ch
  ; IExplorerPaneVisibility constants
  ; {cb316b22-25f7-42b8-8a09-540d23a43c2f}
  DEFINE_GUID EP_NavPane, 0cb316b22h, 25f7h, 42b8h, 8ah, 09h, 54h, 0dh, 23h, 0a4h, 3ch, 2fh
  ; {d9745868-ca5f-4a76-91cd-f5a129fbb076}
  DEFINE_GUID EP_Commands, 0d9745868h, 0ca5fh, 4a76h, 91h, 0cdh, 0f5h, 0a1h, 29h, 0fbh, 0b0h, 76h
  ; {72e81700-e3ec-4660-bf24-3c3b7b648806}
  DEFINE_GUID EP_Commands_Organize, 72e81700h, 0e3ech, 4660h, 0bfh, 24h, 3ch, 3bh, 7bh, 64h, 88h, 06h
  ; {21f7c32d-eeaa-439b-bb51-37b96fd6a943}
  DEFINE_GUID EP_Commands_View, 21f7c32dh, 0eeaah, 439bh, 0bbh, 51h, 37h, 0b9h, 6fh, 0d6h, 0a9h, 43h
  ; {43abf98b-89b8-472d-b9ce-e69b8229f019}
  DEFINE_GUID EP_DetailsPane, 43abf98bh, 89b8h, 472dh, 0b9h, 0ceh, 0e6h, 9bh, 82h, 29h, 0f0h, 19h
  ; {893c63d1-45c8-4d17-be19-223be71be365}
  DEFINE_GUID EP_PreviewPane, 893c63d1h, 45c8h, 4d17h, 0beh, 19h, 22h, 3bh, 0e7h, 1bh, 0e3h, 65h
  ; {65bcde4f-4f07-4f27-83a7-1afca4df7ddd}
  DEFINE_GUID EP_QueryPane, 65bcde4fh, 4f07h, 4f27h, 83h, 0a7h, 1ah, 0fch, 0a4h, 0dfh, 7dh, 0ddh
  ; {b4e9db8b-34ba-4c39-b5cc-16a1bd2c411c}
  DEFINE_GUID EP_AdvQueryPane, 0b4e9db8bh, 34bah, 4c39h, 0b5h, 0cch, 16h, 0a1h, 0bdh, 2ch, 41h, 1ch
  ; {65fe56ce-5cfe-4bc4-ad8a-7ae3fe7e8f7c}
  DEFINE_GUID EP_StatusBar, 65fe56ceh, 5cfeh, 4bc4h, 0adh, 8ah, 7ah, 0e3h, 0feh, 7eh, 8fh, 7ch
  ; {D27524A8-C9F2-4834-A106-DF8889FD4F37}
  DEFINE_GUID EP_Ribbon, 0d27524a8h, 0c9f2h, 4834h, 0a1h, 6h, 0dfh, 88h, 89h, 0fdh, 4fh, 37h
  ; {965c4d51-8b76-4e57-80b7-564d2ea4b55e}
  DEFINE_GUID CATID_LocationFactory, 965c4d51h, 8b76h, 4e57h, 80h, 0b7h, 56h, 4dh, 2eh, 0a4h, 0b5h, 5eh
  ; {1b3ca474-2614-414b-b813-1aceca3e3dd8}
  DEFINE_GUID CATID_LocationProvider, 1b3ca474h, 2614h, 414bh, 0b8h, 13h, 1ah, 0ceh, 0cah, 3eh, 3dh, 0d8h
  ; ItemsView 
  ; {ABBF5C45-5CCC-47b7-BB4E-87CB87BBD162}
  DEFINE_GUID ItemCount_Property_GUID, 0abbf5c45h, 5ccch, 47b7h, 0bbh, 4eh, 87h, 0cbh, 87h, 0bbh, 0d1h, 62h
  ; {8FE316D2-0E52-460a-9C1E-48F273D470A3}
  DEFINE_GUID SelectedItemCount_Property_GUID, 8fe316d2h, 0e52h, 460ah, 9ch, 1eh, 48h, 0f2h, 73h, 0d4h, 70h, 0a3h
  ; {92A053DA-2969-4021-BF27-514CFC2E4A69}
  DEFINE_GUID ItemIndex_Property_GUID, 92a053dah, 2969h, 4021h, 0bfh, 27h, 51h, 4ch, 0fch, 2eh, 4ah, 69h
  ; {366C292A-D9B3-4dbf-BB70-E62EC3D0BBBF}
  DEFINE_GUID CATID_SearchableApplication, 366c292ah, 0d9b3h, 4dbfh, 0bbh, 70h, 0e6h, 2eh, 0c3h, 0d0h, 0bbh, 0bfh
  ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
endif
