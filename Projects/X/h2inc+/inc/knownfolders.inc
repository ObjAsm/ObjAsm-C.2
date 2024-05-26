;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\knownfolders.h
;             Created on (UTC) 06/04/2024 06:15:56
;             Last modified on (UTC) 12/02/2024 17:06:02

include winapifamily.inc
if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
  ifdef DEFINE_KNOWN_FOLDER
  endif
  if Defined(INITGUID) or Defined(INITKNOWNFOLDERS)
    DEFINE_KNOWN_FOLDER macro name_, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8
      exitm <EXTERN_C const GUID DECLSPEC_SELECTANY name_ = { l, w1, w2, { b1, b2, b3, b4, b5, b6, b7, b8 } }>
    endm
  else
    DEFINE_KNOWN_FOLDER macro name_, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8
      exitm <EXTERN_C const GUID name_>
    endm
  endif
  DEFINE_KNOWN_FOLDER FOLDERID_NetworkFolder, 0D20BEEC4h, 5CA8h, 4905h, 0AEh, 3Bh, 0BFh, 25h, 1Eh, 0A0h, 9Bh, 53h
  DEFINE_KNOWN_FOLDER FOLDERID_ComputerFolder, 0AC0837Ch, 0BBF8h, 452Ah, 85h, 0Dh, 79h, 0D0h, 8Eh, 66h, 7Ch, 0A7h
  DEFINE_KNOWN_FOLDER FOLDERID_InternetFolder, 4D9F7874h, 4E0Ch, 4904h, 96h, 7Bh, 40h, 0B0h, 0D2h, 0Ch, 3Eh, 4Bh
  DEFINE_KNOWN_FOLDER FOLDERID_ControlPanelFolder, 82A74AEBh, 0AEB4h, 465Ch, 0A0h, 14h, 0D0h, 97h, 0EEh, 34h, 6Dh, 63h
  DEFINE_KNOWN_FOLDER FOLDERID_PrintersFolder, 76FC4E2Dh, 0D6ADh, 4519h, 0A6h, 63h, 37h, 0BDh, 56h, 06h, 81h, 85h
  DEFINE_KNOWN_FOLDER FOLDERID_SyncManagerFolder, 43668BF8h, 0C14Eh, 49B2h, 97h, 0C9h, 74h, 77h, 84h, 0D7h, 84h, 0B7h
  DEFINE_KNOWN_FOLDER FOLDERID_SyncSetupFolder, 0f214138h, 0b1d3h, 4a90h, 0bbh, 0a9h, 27h, 0cbh, 0c0h, 0c5h, 38h, 9ah
  DEFINE_KNOWN_FOLDER FOLDERID_ConflictFolder, 4bfefb45h, 347dh, 4006h, 0a5h, 0beh, 0ach, 0ch, 0b0h, 56h, 71h, 92h
  DEFINE_KNOWN_FOLDER FOLDERID_SyncResultsFolder, 289a9a43h, 0be44h, 4057h, 0a4h, 1bh, 58h, 7ah, 76h, 0d7h, 0e7h, 0f9h
  DEFINE_KNOWN_FOLDER FOLDERID_RecycleBinFolder, 0B7534046h, 3ECBh, 4C18h, 0BEh, 4Eh, 64h, 0CDh, 4Ch, 0B7h, 0D6h, 0ACh
  DEFINE_KNOWN_FOLDER FOLDERID_ConnectionsFolder, 6F0CD92Bh, 2E97h, 45D1h, 88h, 0FFh, 0B0h, 0D1h, 86h, 0B8h, 0DEh, 0DDh
  DEFINE_KNOWN_FOLDER FOLDERID_Fonts, 0FD228CB7h, 0AE11h, 4AE3h, 86h, 4Ch, 16h, 0F3h, 91h, 0Ah, 0B8h, 0FEh
  DEFINE_KNOWN_FOLDER FOLDERID_Desktop, 0B4BFCC3Ah, 0DB2Ch, 424Ch, 0B0h, 29h, 7Fh, 0E9h, 9Ah, 87h, 0C6h, 41h
  DEFINE_KNOWN_FOLDER FOLDERID_Startup, 0B97D20BBh, 0F46Ah, 4C97h, 0BAh, 10h, 5Eh, 36h, 08h, 43h, 08h, 54h
  DEFINE_KNOWN_FOLDER FOLDERID_Programs, 0A77F5D77h, 2E2Bh, 44C3h, 0A6h, 0A2h, 0ABh, 0A6h, 01h, 05h, 4Ah, 51h
  DEFINE_KNOWN_FOLDER FOLDERID_StartMenu, 625B53C3h, 0AB48h, 4EC1h, 0BAh, 1Fh, 0A1h, 0EFh, 41h, 46h, 0FCh, 19h
  DEFINE_KNOWN_FOLDER FOLDERID_Recent, 0AE50C081h, 0EBD2h, 438Ah, 86h, 55h, 8Ah, 09h, 2Eh, 34h, 98h, 7Ah
  DEFINE_KNOWN_FOLDER FOLDERID_SendTo, 8983036Ch, 27C0h, 404Bh, 8Fh, 08h, 10h, 2Dh, 10h, 0DCh, 0FDh, 74h
  DEFINE_KNOWN_FOLDER FOLDERID_Documents, 0FDD39AD0h, 238Fh, 46AFh, 0ADh, 0B4h, 6Ch, 85h, 48h, 03h, 69h, 0C7h
  DEFINE_KNOWN_FOLDER FOLDERID_Favorites, 1777F761h, 68ADh, 4D8Ah, 87h, 0BDh, 30h, 0B7h, 59h, 0FAh, 33h, 0DDh
  DEFINE_KNOWN_FOLDER FOLDERID_NetHood, 0C5ABBF53h, 0E17Fh, 4121h, 89h, 00h, 86h, 62h, 6Fh, 0C2h, 0C9h, 73h
  DEFINE_KNOWN_FOLDER FOLDERID_PrintHood, 9274BD8Dh, 0CFD1h, 41C3h, 0B3h, 5Eh, 0B1h, 3Fh, 55h, 0A7h, 58h, 0F4h
  DEFINE_KNOWN_FOLDER FOLDERID_Templates, 0A63293E8h, 664Eh, 48DBh, 0A0h, 79h, 0DFh, 75h, 9Eh, 05h, 09h, 0F7h
  DEFINE_KNOWN_FOLDER FOLDERID_CommonStartup, 82A5EA35h, 0D9CDh, 47C5h, 96h, 29h, 0E1h, 5Dh, 2Fh, 71h, 4Eh, 6Eh
  DEFINE_KNOWN_FOLDER FOLDERID_CommonPrograms, 0139D44Eh, 6AFEh, 49F2h, 86h, 90h, 3Dh, 0AFh, 0CAh, 0E6h, 0FFh, 0B8h
  DEFINE_KNOWN_FOLDER FOLDERID_CommonStartMenu, 0A4115719h, 0D62Eh, 491Dh, 0AAh, 7Ch, 0E7h, 4Bh, 8Bh, 0E3h, 0B0h, 67h
  DEFINE_KNOWN_FOLDER FOLDERID_PublicDesktop, 0C4AA340Dh, 0F20Fh, 4863h, 0AFh, 0EFh, 0F8h, 7Eh, 0F2h, 0E6h, 0BAh, 25h
  DEFINE_KNOWN_FOLDER FOLDERID_ProgramData, 62AB5D82h, 0FDC1h, 4DC3h, 0A9h, 0DDh, 07h, 0Dh, 1Dh, 49h, 5Dh, 97h
  DEFINE_KNOWN_FOLDER FOLDERID_CommonTemplates, 0B94237E7h, 57ACh, 4347h, 91h, 51h, 0B0h, 8Ch, 6Ch, 32h, 0D1h, 0F7h
  DEFINE_KNOWN_FOLDER FOLDERID_PublicDocuments, 0ED4824AFh, 0DCE4h, 45A8h, 81h, 0E2h, 0FCh, 79h, 65h, 08h, 36h, 34h
  DEFINE_KNOWN_FOLDER FOLDERID_RoamingAppData, 3EB685DBh, 65F9h, 4CF6h, 0A0h, 3Ah, 0E3h, 0EFh, 65h, 72h, 9Fh, 3Dh
  DEFINE_KNOWN_FOLDER FOLDERID_LocalAppData, 0F1B32785h, 6FBAh, 4FCFh, 9Dh, 55h, 7Bh, 8Eh, 7Fh, 15h, 70h, 91h
  DEFINE_KNOWN_FOLDER FOLDERID_LocalAppDataLow, 0A520A1A4h, 1780h, 4FF6h, 0BDh, 18h, 16h, 73h, 43h, 0C5h, 0AFh, 16h
  DEFINE_KNOWN_FOLDER FOLDERID_InternetCache, 352481E8h, 33BEh, 4251h, 0BAh, 85h, 60h, 07h, 0CAh, 0EDh, 0CFh, 9Dh
  DEFINE_KNOWN_FOLDER FOLDERID_Cookies, 2B0F765Dh, 0C0E9h, 4171h, 90h, 8Eh, 08h, 0A6h, 11h, 0B8h, 4Fh, 0F6h
  DEFINE_KNOWN_FOLDER FOLDERID_History, 0D9DC8A3Bh, 0B784h, 432Eh, 0A7h, 81h, 5Ah, 11h, 30h, 0A7h, 59h, 63h
  DEFINE_KNOWN_FOLDER FOLDERID_System, 1AC14E77h, 02E7h, 4E5Dh, 0B7h, 44h, 2Eh, 0B1h, 0AEh, 51h, 98h, 0B7h
  DEFINE_KNOWN_FOLDER FOLDERID_SystemX86, 0D65231B0h, 0B2F1h, 4857h, 0A4h, 0CEh, 0A8h, 0E7h, 0C6h, 0EAh, 7Dh, 27h
  DEFINE_KNOWN_FOLDER FOLDERID_Windows, 0F38BF404h, 1D43h, 42F2h, 93h, 05h, 67h, 0DEh, 0Bh, 28h, 0FCh, 23h
  DEFINE_KNOWN_FOLDER FOLDERID_Profile, 5E6C858Fh, 0E22h, 4760h, 9Ah, 0FEh, 0EAh, 33h, 17h, 0B6h, 71h, 73h
  DEFINE_KNOWN_FOLDER FOLDERID_Pictures, 33E28130h, 4E1Eh, 4676h, 83h, 5Ah, 98h, 39h, 5Ch, 3Bh, 0C3h, 0BBh
  DEFINE_KNOWN_FOLDER FOLDERID_ProgramFilesX86, 7C5A40EFh, 0A0FBh, 4BFCh, 87h, 4Ah, 0C0h, 0F2h, 0E0h, 0B9h, 0FAh, 8Eh
  DEFINE_KNOWN_FOLDER FOLDERID_ProgramFilesCommonX86, 0DE974D24h, 0D9C6h, 4D3Eh, 0BFh, 91h, 0F4h, 45h, 51h, 20h, 0B9h, 17h
  DEFINE_KNOWN_FOLDER FOLDERID_ProgramFilesX64, 6d809377h, 6af0h, 444bh, 89h, 57h, 0a3h, 77h, 3fh, 02h, 20h, 0eh
  DEFINE_KNOWN_FOLDER FOLDERID_ProgramFilesCommonX64, 6365d5a7h, 0f0dh, 45e5h, 87h, 0f6h, 0dh, 0a5h, 6bh, 6ah, 4fh, 7dh
  DEFINE_KNOWN_FOLDER FOLDERID_ProgramFiles, 905e63b6h, 0c1bfh, 494eh, 0b2h, 9ch, 65h, 0b7h, 32h, 0d3h, 0d2h, 1ah
  DEFINE_KNOWN_FOLDER FOLDERID_ProgramFilesCommon, 0F7F1ED05h, 9F6Dh, 47A2h, 0AAh, 0AEh, 29h, 0D3h, 17h, 0C6h, 0F0h, 66h
  DEFINE_KNOWN_FOLDER FOLDERID_UserProgramFiles, 5cd7aee2h, 2219h, 4a67h, 0b8h, 5dh, 6ch, 9ch, 0e1h, 56h, 60h, 0cbh
  DEFINE_KNOWN_FOLDER FOLDERID_UserProgramFilesCommon, 0bcbd3057h, 0ca5ch, 4622h, 0b4h, 2dh, 0bch, 56h, 0dbh, 0ah, 0e5h, 16h
  DEFINE_KNOWN_FOLDER FOLDERID_AdminTools, 724EF170h, 0A42Dh, 4FEFh, 9Fh, 26h, 0B6h, 0Eh, 84h, 6Fh, 0BAh, 4Fh
  DEFINE_KNOWN_FOLDER FOLDERID_CommonAdminTools, 0D0384E7Dh, 0BAC3h, 4797h, 8Fh, 14h, 0CBh, 0A2h, 29h, 0B3h, 92h, 0B5h
  DEFINE_KNOWN_FOLDER FOLDERID_Music, 4BD8D571h, 6D19h, 48D3h, 0BEh, 97h, 42h, 22h, 20h, 08h, 0Eh, 43h
  DEFINE_KNOWN_FOLDER FOLDERID_Videos, 18989B1Dh, 99B5h, 455Bh, 84h, 1Ch, 0ABh, 7Ch, 74h, 0E4h, 0DDh, 0FCh
  DEFINE_KNOWN_FOLDER FOLDERID_Ringtones, 0C870044Bh, 0F49Eh, 4126h, 0A9h, 0C3h, 0B5h, 2Ah, 1Fh, 0F4h, 11h, 0E8h
  DEFINE_KNOWN_FOLDER FOLDERID_PublicPictures, 0B6EBFB86h, 6907h, 413Ch, 9Ah, 0F7h, 4Fh, 0C2h, 0ABh, 0F0h, 7Ch, 0C5h
  DEFINE_KNOWN_FOLDER FOLDERID_PublicMusic, 3214FAB5h, 9757h, 4298h, 0BBh, 61h, 92h, 0A9h, 0DEh, 0AAh, 44h, 0FFh
  DEFINE_KNOWN_FOLDER FOLDERID_PublicVideos, 2400183Ah, 6185h, 49FBh, 0A2h, 0D8h, 4Ah, 39h, 2Ah, 60h, 2Bh, 0A3h
  DEFINE_KNOWN_FOLDER FOLDERID_PublicRingtones, 0E555AB60h, 153Bh, 4D17h, 9Fh, 04h, 0A5h, 0FEh, 99h, 0FCh, 15h, 0ECh
  DEFINE_KNOWN_FOLDER FOLDERID_ResourceDir, 8AD10C31h, 2ADBh, 4296h, 0A8h, 0F7h, 0E4h, 70h, 12h, 32h, 0C9h, 72h
  DEFINE_KNOWN_FOLDER FOLDERID_LocalizedResourcesDir, 2A00375Eh, 224Ch, 49DEh, 0B8h, 0D1h, 44h, 0Dh, 0F7h, 0EFh, 3Dh, 0DCh
  DEFINE_KNOWN_FOLDER FOLDERID_CommonOEMLinks, 0C1BAE2D0h, 10DFh, 4334h, 0BEh, 0DDh, 7Ah, 0A2h, 0Bh, 22h, 7Ah, 9Dh
  DEFINE_KNOWN_FOLDER FOLDERID_CDBurning, 9E52AB10h, 0F80Dh, 49DFh, 0ACh, 0B8h, 43h, 30h, 0F5h, 68h, 78h, 55h
  DEFINE_KNOWN_FOLDER FOLDERID_UserProfiles, 0762D272h, 0C50Ah, 4BB0h, 0A3h, 82h, 69h, 7Dh, 0CDh, 72h, 9Bh, 80h
  DEFINE_KNOWN_FOLDER FOLDERID_Playlists, 0DE92C1C7h, 837Fh, 4F69h, 0A3h, 0BBh, 86h, 0E6h, 31h, 20h, 4Ah, 23h
  DEFINE_KNOWN_FOLDER FOLDERID_SamplePlaylists, 15CA69B3h, 30EEh, 49C1h, 0ACh, 0E1h, 6Bh, 5Eh, 0C3h, 72h, 0AFh, 0B5h
  DEFINE_KNOWN_FOLDER FOLDERID_SampleMusic, 0B250C668h, 0F57Dh, 4EE1h, 0A6h, 3Ch, 29h, 0Eh, 0E7h, 0D1h, 0AAh, 1Fh
  DEFINE_KNOWN_FOLDER FOLDERID_SamplePictures, 0C4900540h, 2379h, 4C75h, 84h, 4Bh, 64h, 0E6h, 0FAh, 0F8h, 71h, 6Bh
  DEFINE_KNOWN_FOLDER FOLDERID_SampleVideos, 859EAD94h, 2E85h, 48ADh, 0A7h, 1Ah, 09h, 69h, 0CBh, 56h, 0A6h, 0CDh
  DEFINE_KNOWN_FOLDER FOLDERID_PhotoAlbums, 69D2CF90h, 0FC33h, 4FB7h, 9Ah, 0Ch, 0EBh, 0B0h, 0F0h, 0FCh, 0B4h, 3Ch
  DEFINE_KNOWN_FOLDER FOLDERID_Public, 0DFDF76A2h, 0C82Ah, 4D63h, 90h, 6Ah, 56h, 44h, 0ACh, 45h, 73h, 85h
  DEFINE_KNOWN_FOLDER FOLDERID_ChangeRemovePrograms, 0df7266ach, 9274h, 4867h, 8dh, 55h, 3bh, 0d6h, 61h, 0deh, 87h, 2dh
  DEFINE_KNOWN_FOLDER FOLDERID_AppUpdates, 0a305ce99h, 0f527h, 492bh, 8bh, 1ah, 7eh, 76h, 0fah, 98h, 0d6h, 0e4h
  DEFINE_KNOWN_FOLDER FOLDERID_AddNewPrograms, 0de61d971h, 5ebch, 4f02h, 0a3h, 0a9h, 6ch, 82h, 89h, 5eh, 5ch, 04h
  DEFINE_KNOWN_FOLDER FOLDERID_Downloads, 374de290h, 123fh, 4565h, 91h, 64h, 39h, 0c4h, 92h, 5eh, 46h, 7bh
  DEFINE_KNOWN_FOLDER FOLDERID_PublicDownloads, 3d644c9bh, 1fb8h, 4f30h, 9bh, 45h, 0f6h, 70h, 23h, 5fh, 79h, 0c0h
  DEFINE_KNOWN_FOLDER FOLDERID_SavedSearches, 7d1d3a04h, 0debbh, 4115h, 95h, 0cfh, 2fh, 29h, 0dah, 29h, 20h, 0dah
  DEFINE_KNOWN_FOLDER FOLDERID_QuickLaunch, 52a4f021h, 7b75h, 48a9h, 9fh, 6bh, 4bh, 87h, 0a2h, 10h, 0bch, 8fh
  DEFINE_KNOWN_FOLDER FOLDERID_Contacts, 56784854h, 0c6cbh, 462bh, 81h, 69h, 88h, 0e3h, 50h, 0ach, 0b8h, 82h
  DEFINE_KNOWN_FOLDER FOLDERID_SidebarParts, 0a75d362eh, 50fch, 4fb7h, 0ach, 2ch, 0a8h, 0beh, 0aah, 31h, 44h, 93h
  DEFINE_KNOWN_FOLDER FOLDERID_SidebarDefaultParts, 7b396e54h, 9ec5h, 4300h, 0beh, 0ah, 24h, 82h, 0ebh, 0aeh, 1ah, 26h
  DEFINE_KNOWN_FOLDER FOLDERID_PublicGameTasks, 0debf2536h, 0e1a8h, 4c59h, 0b6h, 0a2h, 41h, 45h, 86h, 47h, 6ah, 0eah
  DEFINE_KNOWN_FOLDER FOLDERID_GameTasks, 54fae61h, 4dd8h, 4787h, 80h, 0b6h, 9h, 2h, 20h, 0c4h, 0b7h, 0h
  DEFINE_KNOWN_FOLDER FOLDERID_SavedGames, 4c5c32ffh, 0bb9dh, 43b0h, 0b5h, 0b4h, 2dh, 72h, 0e5h, 4eh, 0aah, 0a4h
  DEFINE_KNOWN_FOLDER FOLDERID_Games, 0cac52c1ah, 0b53dh, 4edch, 92h, 0d7h, 6bh, 2eh, 8ah, 0c1h, 94h, 34h
  DEFINE_KNOWN_FOLDER FOLDERID_SEARCH_MAPI, 98ec0e18h, 2098h, 4d44h, 86h, 44h, 66h, 97h, 93h, 15h, 0a2h, 81h
  DEFINE_KNOWN_FOLDER FOLDERID_SEARCH_CSC, 0ee32e446h, 31cah, 4abah, 81h, 4fh, 0a5h, 0ebh, 0d2h, 0fdh, 6dh, 5eh
  DEFINE_KNOWN_FOLDER FOLDERID_Links, 0bfb9d5e0h, 0c6a9h, 404ch, 0b2h, 0b2h, 0aeh, 6dh, 0b6h, 0afh, 49h, 68h
  DEFINE_KNOWN_FOLDER FOLDERID_UsersFiles, 0f3ce0f7ch, 4901h, 4acch, 86h, 48h, 0d5h, 0d4h, 4bh, 04h, 0efh, 8fh
  DEFINE_KNOWN_FOLDER FOLDERID_UsersLibraries, 0a302545dh, 0deffh, 464bh, 0abh, 0e8h, 61h, 0c8h, 64h, 8dh, 93h, 9bh
  DEFINE_KNOWN_FOLDER FOLDERID_SearchHome, 190337d1h, 0b8cah, 4121h, 0a6h, 39h, 6dh, 47h, 2dh, 16h, 97h, 2ah
  DEFINE_KNOWN_FOLDER FOLDERID_OriginalImages, 2C36C0AAh, 5812h, 4b87h, 0bfh, 0d0h, 4ch, 0d0h, 0dfh, 0b1h, 9bh, 39h
  DEFINE_KNOWN_FOLDER FOLDERID_DocumentsLibrary, 7b0db17dh, 9cd2h, 4a93h, 97h, 33h, 46h, 0cch, 89h, 02h, 2eh, 7ch
  DEFINE_KNOWN_FOLDER FOLDERID_MusicLibrary, 2112ab0ah, 0c86ah, 4ffeh, 0a3h, 68h, 0dh, 0e9h, 6eh, 47h, 1h, 2eh
  DEFINE_KNOWN_FOLDER FOLDERID_PicturesLibrary, 0a990ae9fh, 0a03bh, 4e80h, 94h, 0bch, 99h, 12h, 0d7h, 50h, 41h, 4h
  DEFINE_KNOWN_FOLDER FOLDERID_VideosLibrary, 491e922fh, 5643h, 4af4h, 0a7h, 0ebh, 4eh, 7ah, 13h, 8dh, 81h, 74h
  DEFINE_KNOWN_FOLDER FOLDERID_RecordedTVLibrary, 1a6fdba2h, 0f42dh, 4358h, 0a7h, 98h, 0b7h, 4dh, 74h, 59h, 26h, 0c5h
  DEFINE_KNOWN_FOLDER FOLDERID_HomeGroup, 52528a6bh, 0b9e3h, 4addh, 0b6h, 0dh, 58h, 8ch, 2dh, 0bah, 84h, 2dh
  DEFINE_KNOWN_FOLDER FOLDERID_HomeGroupCurrentUser, 9b74b6a3h, 0dfdh, 4f11h, 9eh, 78h, 5fh, 78h, 0h, 0f2h, 0e7h, 72h
  DEFINE_KNOWN_FOLDER FOLDERID_DeviceMetadataStore, 5ce4a5e9h, 0e4ebh, 479dh, 0b8h, 9fh, 13h, 0ch, 02h, 88h, 61h, 55h
  DEFINE_KNOWN_FOLDER FOLDERID_Libraries, 1b3ea5dch, 0b587h, 4786h, 0b4h, 0efh, 0bdh, 1dh, 0c3h, 32h, 0aeh, 0aeh
  DEFINE_KNOWN_FOLDER FOLDERID_PublicLibraries, 48daf80bh, 0e6cfh, 4f4eh, 0b8h, 00h, 0eh, 69h, 0d8h, 4eh, 0e3h, 84h
  DEFINE_KNOWN_FOLDER FOLDERID_UserPinned, 9e3995abh, 1f9ch, 4f13h, 0b8h, 27h, 48h, 0b2h, 4bh, 6ch, 71h, 74h
  DEFINE_KNOWN_FOLDER FOLDERID_ImplicitAppShortcuts, 0bcb5256fh, 79f6h, 4ceeh, 0b7h, 25h, 0dch, 34h, 0e4h, 2h, 0fdh, 46h
  DEFINE_KNOWN_FOLDER FOLDERID_AccountPictures, 008ca0b1h, 55b4h, 4c56h, 0b8h, 0a8h, 4dh, 0e4h, 0b2h, 99h, 0d3h, 0beh
  DEFINE_KNOWN_FOLDER FOLDERID_PublicUserTiles, 0482af6ch, 08f1h, 4c34h, 8ch, 90h, 0e1h, 7eh, 0c9h, 8bh, 1eh, 17h
  DEFINE_KNOWN_FOLDER FOLDERID_AppsFolder, 1e87508dh, 89c2h, 42f0h, 8ah, 7eh, 64h, 5ah, 0fh, 50h, 0cah, 58h
  DEFINE_KNOWN_FOLDER FOLDERID_StartMenuAllPrograms, 0f26305efh, 6948h, 40b9h, 0b2h, 55h, 81h, 45h, 3dh, 9h, 0c7h, 85h
  DEFINE_KNOWN_FOLDER FOLDERID_CommonStartMenuPlaces, 0a440879fh, 87a0h, 4f7dh, 0b7h, 0h, 2h, 7h, 0b9h, 66h, 19h, 4ah
  DEFINE_KNOWN_FOLDER FOLDERID_ApplicationShortcuts, 0a3918781h, 0e5f2h, 4890h, 0b3h, 0d9h, 0a7h, 0e5h, 43h, 32h, 32h, 8ch
  DEFINE_KNOWN_FOLDER FOLDERID_RoamingTiles, 0bcfc5ah, 0ed94h, 4e48h, 96h, 0a1h, 3fh, 62h, 17h, 0f2h, 19h, 90h
  DEFINE_KNOWN_FOLDER FOLDERID_RoamedTileImages, 0aaa8d5a5h, 0f1d6h, 4259h, 0bah, 0a8h, 78h, 0e7h, 0efh, 60h, 83h, 5eh
  DEFINE_KNOWN_FOLDER FOLDERID_Screenshots, 0b7bede81h, 0df94h, 4682h, 0a7h, 0d8h, 57h, 0a5h, 26h, 20h, 0b8h, 6fh
  DEFINE_KNOWN_FOLDER FOLDERID_CameraRoll, 0ab5fb87bh, 7ce2h, 4f83h, 91h, 5dh, 55h, 8h, 46h, 0c9h, 53h, 7bh
  DEFINE_KNOWN_FOLDER FOLDERID_SkyDrive, 0a52bba46h, 0e9e1h, 435fh, 0b3h, 0d9h, 28h, 0dah, 0a6h, 48h, 0c0h, 0f6h
  DEFINE_KNOWN_FOLDER FOLDERID_OneDrive, 0a52bba46h, 0e9e1h, 435fh, 0b3h, 0d9h, 28h, 0dah, 0a6h, 48h, 0c0h, 0f6h
  DEFINE_KNOWN_FOLDER FOLDERID_SkyDriveDocuments, 24d89e24h, 2f19h, 4534h, 9dh, 0deh, 6ah, 66h, 71h, 0fbh, 0b8h, 0feh
  DEFINE_KNOWN_FOLDER FOLDERID_SkyDrivePictures, 339719b5h, 8c47h, 4894h, 94h, 0c2h, 0d8h, 0f7h, 7ah, 0ddh, 44h, 0a6h
  DEFINE_KNOWN_FOLDER FOLDERID_SkyDriveMusic, 0c3f2459eh, 80d6h, 45dch, 0bfh, 0efh, 1fh, 76h, 9fh, 2bh, 0e7h, 30h
  DEFINE_KNOWN_FOLDER FOLDERID_SkyDriveCameraRoll, 767e6811h, 49cbh, 4273h, 87h, 0c2h, 20h, 0f3h, 55h, 0e1h, 08h, 5bh
  DEFINE_KNOWN_FOLDER FOLDERID_SearchHistory, 0d4c3db6h, 03a3h, 462fh, 0a0h, 0e6h, 08h, 92h, 4ch, 41h, 0b5h, 0d4h
  DEFINE_KNOWN_FOLDER FOLDERID_SearchTemplates, 7e636bfeh, 0dfa9h, 4d5eh, 0b4h, 56h, 0d7h, 0b3h, 98h, 51h, 0d8h, 0a9h
  DEFINE_KNOWN_FOLDER FOLDERID_CameraRollLibrary, 2b20df75h, 1edah, 4039h, 80h, 97h, 38h, 79h, 82h, 27h, 0d5h, 0b7h
  DEFINE_KNOWN_FOLDER FOLDERID_SavedPictures, 3b193882h, 0d3adh, 4eabh, 96h, 5ah, 69h, 82h, 9dh, 1fh, 0b5h, 9fh
  DEFINE_KNOWN_FOLDER FOLDERID_SavedPicturesLibrary, 0e25b5812h, 0be88h, 4bd9h, 94h, 0b0h, 29h, 23h, 34h, 77h, 0b6h, 0c3h
  DEFINE_KNOWN_FOLDER FOLDERID_RetailDemo, 12d4c69eh, 24adh, 4923h, 0beh, 19h, 31h, 32h, 1ch, 43h, 0a7h, 67h
  DEFINE_KNOWN_FOLDER FOLDERID_Device, 1C2AC1DCh, 4358h, 4B6Ch, 97h, 33h, 0AFh, 21h, 15h, 65h, 76h, 0F0h
  DEFINE_KNOWN_FOLDER FOLDERID_DevelopmentFiles, 0dbe8e08eh, 3053h, 4bbch, 0b1h, 83h, 2ah, 7bh, 2bh, 19h, 1eh, 59h
  DEFINE_KNOWN_FOLDER FOLDERID_Objects3D, 31c0dd25h, 9439h, 4f12h, 0bfh, 41h, 7fh, 0f4h, 0edh, 0a3h, 87h, 22h
  DEFINE_KNOWN_FOLDER FOLDERID_AppCaptures, 0edc0fe71h, 98d8h, 4f4ah, 0b9h, 20h, 0c8h, 0dch, 13h, 3ch, 0b1h, 65h
  DEFINE_KNOWN_FOLDER FOLDERID_LocalDocuments, 0f42ee2d3h, 909fh, 4907h, 88h, 71h, 4ch, 22h, 0fch, 0bh, 0f7h, 56h
  DEFINE_KNOWN_FOLDER FOLDERID_LocalPictures, 0ddd015dh, 0b06ch, 45d5h, 8ch, 4ch, 0f5h, 97h, 13h, 85h, 46h, 39h
  DEFINE_KNOWN_FOLDER FOLDERID_LocalVideos, 35286a68h, 3c57h, 41a1h, 0bbh, 0b1h, 0eh, 0aeh, 73h, 0d7h, 6ch, 95h
  DEFINE_KNOWN_FOLDER FOLDERID_LocalMusic, 0a0c69a99h, 21c8h, 4671h, 87h, 03h, 79h, 34h, 16h, 2fh, 0cfh, 1dh
  DEFINE_KNOWN_FOLDER FOLDERID_LocalDownloads, 7d83ee9bh, 2244h, 4e70h, 0b1h, 0f5h, 53h, 93h, 04h, 2ah, 0f1h, 0e4h
  DEFINE_KNOWN_FOLDER FOLDERID_RecordedCalls, 2f8b40c2h, 83edh, 48eeh, 0b3h, 83h, 0a1h, 0f1h, 57h, 0ech, 6fh, 9ah
  DEFINE_KNOWN_FOLDER FOLDERID_AllAppMods, 7ad67899h, 66afh, 43bah, 91h, 56h, 6ah, 0adh, 42h, 0e6h, 0c5h, 96h
  DEFINE_KNOWN_FOLDER FOLDERID_CurrentAppMods, 3db40b20h, 2a30h, 4dbeh, 91h, 7eh, 77h, 1dh, 0d2h, 1dh, 0d0h, 99h
  DEFINE_KNOWN_FOLDER FOLDERID_AppDataDesktop, 0b2c5e279h, 7addh, 439fh, 0b2h, 8ch, 0c4h, 1fh, 0e1h, 0bbh, 0f6h, 72h
  DEFINE_KNOWN_FOLDER FOLDERID_AppDataDocuments, 7be16610h, 1f7fh, 44ach, 0bfh, 0f0h, 83h, 0e1h, 5fh, 2fh, 0fch, 0a1h
  DEFINE_KNOWN_FOLDER FOLDERID_AppDataFavorites, 7cfbefbch, 0de1fh, 45aah, 0b8h, 43h, 0a5h, 42h, 0ach, 53h, 6ch, 0c9h
  DEFINE_KNOWN_FOLDER FOLDERID_AppDataProgramData, 559d40a3h, 0a036h, 40fah, 0afh, 61h, 84h, 0cbh, 43h, 0ah, 4dh, 34h
  DEFINE_KNOWN_FOLDER FOLDERID_LocalStorage, 0B3EB08D3h, 0A1F3h, 496Bh, 86h, 5Ah, 42h, 0B5h, 36h, 0CDh, 0A0h, 0ECh
endif
