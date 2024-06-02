;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\winscard.h
;             Created on (UTC) 06/04/2024 06:16:03
;             Last modified on (UTC) 21/02/2024 18:13:14

ifndef _WINSCARD_H_
  _WINSCARD_H_ equ <>
  if Defined(_MSC_VER) and (_MSC_VER ge 1020)
  endif
  include wtypes.inc
  include winioctl.inc
  include winsmcrd.inc
  ifndef SCARD_S_SUCCESS
    include SCardErr.inc
  endif
  include winapifamily.inc
  ifdef __cplusplus
    ;[...]
  endif
  if _MSC_VER ge 1200
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef _LPCBYTE_DEFINED
      _LPCBYTE_DEFINED equ <>
      LPCBYTE typedef ptr BYTE
    endif
    ifndef _LPCVOID_DEFINED
      _LPCVOID_DEFINED equ <>
      LPCVOID typedef ptr VOID
    endif
    ifndef WINSCARDAPI
      WINSCARDAPI equ <>
    endif
    ifndef WINSCARDDATA
      WINSCARDDATA equ <__declspec(dllimport)>
    endif
    if  not Defined(_M_CEE_PURE)
      SCARD_PCI_T0 equ <(and g_rgSCardT0Pci)>
      SCARD_PCI_T1 equ <(and g_rgSCardT1Pci)>
      SCARD_PCI_RAW equ <(and g_rgSCardRawPci)>
    endif
    SCARDCONTEXT typedef ULONG_PTR
    PSCARDCONTEXT typedef ptr SCARDCONTEXT
    LPSCARDCONTEXT typedef ptr SCARDCONTEXT
    SCARDHANDLE typedef ULONG_PTR
    PSCARDHANDLE typedef ptr SCARDHANDLE
    LPSCARDHANDLE typedef ptr SCARDHANDLE
    SCARD_AUTOALLOCATE equ (- 1)
    SCARD_SCOPE_USER equ 0
    SCARD_SCOPE_TERMINAL equ 1
    SCARD_SCOPE_SYSTEM equ 2
    SCardEstablishContext proto WIN_STD_CALL_CONV :DWORD, :LPCVOID, :LPCVOID, :LPSCARDCONTEXT
    SCardReleaseContext proto WIN_STD_CALL_CONV :SCARDCONTEXT
    SCardIsValidContext proto WIN_STD_CALL_CONV :SCARDCONTEXT
    SCARD_ALL_READERS equ <TEXT("SCard$AllReaders",000o)>
    SCARD_DEFAULT_READERS equ <TEXT("SCard$DefaultReaders",000o)>
    SCARD_LOCAL_READERS equ <TEXT("SCard$LocalReaders",000o)>
    SCARD_SYSTEM_READERS equ <TEXT("SCard$SystemReaders",000o)>
    SCARD_PROVIDER_PRIMARY equ 1
    SCARD_PROVIDER_CSP equ 2
    SCARD_PROVIDER_KSP equ 3
    SCardListReaderGroupsA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPSTR, :LPDWORD
    SCardListReaderGroupsW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPWSTR, :LPDWORD
    ifdef UNICODE
      SCardListReaderGroups equ <SCardListReaderGroupsW>
    else
      SCardListReaderGroups equ <SCardListReaderGroupsA>
    endif
    SCardListReadersA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR, :LPSTR, :LPDWORD
    SCardListReadersW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR, :LPWSTR, :LPDWORD
    ifdef UNICODE
      SCardListReaders equ <SCardListReadersW>
    else
      SCardListReaders equ <SCardListReadersA>
    endif
    SCardListCardsA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCBYTE, :LPCGUID, :DWORD, :ptr CHAR, :LPDWORD
    SCardListCardsW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCBYTE, :LPCGUID, :DWORD, :ptr WCHAR, :LPDWORD
    ifdef UNICODE
      SCardListCards equ <SCardListCardsW>
    else
      SCardListCards equ <SCardListCardsA>
    endif
    SCardListCardTypes equ <SCardListCards>
    SCardListInterfacesA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR, :LPGUID, :LPDWORD
    SCardListInterfacesW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR, :LPGUID, :LPDWORD
    ifdef UNICODE
      SCardListInterfaces equ <SCardListInterfacesW>
    else
      SCardListInterfaces equ <SCardListInterfacesA>
    endif
    SCardGetProviderIdA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR, :LPGUID
    SCardGetProviderIdW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR, :LPGUID
    ifdef UNICODE
      SCardGetProviderId equ <SCardGetProviderIdW>
    else
      SCardGetProviderId equ <SCardGetProviderIdA>
    endif
    SCardGetCardTypeProviderNameA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR, :DWORD, :ptr CHAR, :LPDWORD
    SCardGetCardTypeProviderNameW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR, :DWORD, :ptr WCHAR, :LPDWORD
    ifdef UNICODE
      SCardGetCardTypeProviderName equ <SCardGetCardTypeProviderNameW>
    else
      SCardGetCardTypeProviderName equ <SCardGetCardTypeProviderNameA>
    endif
    SCardIntroduceReaderGroupA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR
    SCardIntroduceReaderGroupW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR
    ifdef UNICODE
      SCardIntroduceReaderGroup equ <SCardIntroduceReaderGroupW>
    else
      SCardIntroduceReaderGroup equ <SCardIntroduceReaderGroupA>
    endif
    SCardForgetReaderGroupA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR
    SCardForgetReaderGroupW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR
    ifdef UNICODE
      SCardForgetReaderGroup equ <SCardForgetReaderGroupW>
    else
      SCardForgetReaderGroup equ <SCardForgetReaderGroupA>
    endif
    SCardIntroduceReaderA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR, :LPCSTR
    SCardIntroduceReaderW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR, :LPCWSTR
    ifdef UNICODE
      SCardIntroduceReader equ <SCardIntroduceReaderW>
    else
      SCardIntroduceReader equ <SCardIntroduceReaderA>
    endif
    SCardForgetReaderA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR
    SCardForgetReaderW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR
    ifdef UNICODE
      SCardForgetReader equ <SCardForgetReaderW>
    else
      SCardForgetReader equ <SCardForgetReaderA>
    endif
    SCardAddReaderToGroupA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR, :LPCSTR
    SCardAddReaderToGroupW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR, :LPCWSTR
    ifdef UNICODE
      SCardAddReaderToGroup equ <SCardAddReaderToGroupW>
    else
      SCardAddReaderToGroup equ <SCardAddReaderToGroupA>
    endif
    SCardRemoveReaderFromGroupA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR, :LPCSTR
    SCardRemoveReaderFromGroupW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR, :LPCWSTR
    ifdef UNICODE
      SCardRemoveReaderFromGroup equ <SCardRemoveReaderFromGroupW>
    else
      SCardRemoveReaderFromGroup equ <SCardRemoveReaderFromGroupA>
    endif
    SCardIntroduceCardTypeA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR, :LPCGUID, :LPCGUID, :DWORD, :LPCBYTE, :LPCBYTE, :DWORD
    SCardIntroduceCardTypeW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR, :LPCGUID, :LPCGUID, :DWORD, :LPCBYTE, :LPCBYTE, :DWORD
    ifdef UNICODE
      SCardIntroduceCardType equ <SCardIntroduceCardTypeW>
    else
      SCardIntroduceCardType equ <SCardIntroduceCardTypeA>
    endif
    PCSCardIntroduceCardType macro hContext, szCardName, pbAtr, pbAtrMask, cbAtrLen, pguidPrimaryProvider, rgguidInterfaces, dwInterfaceCount
      exitm <SCardIntroduceCardType (hContext, szCardName, pguidPrimaryProvider, rgguidInterfaces, dwInterfaceCount, pbAtr, pbAtrMask, cbAtrLen)>
    endm
    SCardSetCardTypeProviderNameA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR, :DWORD, :LPCSTR
    SCardSetCardTypeProviderNameW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR, :DWORD, :LPCWSTR
    ifdef UNICODE
      SCardSetCardTypeProviderName equ <SCardSetCardTypeProviderNameW>
    else
      SCardSetCardTypeProviderName equ <SCardSetCardTypeProviderNameA>
    endif
    SCardForgetCardTypeA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR
    SCardForgetCardTypeW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR
    ifdef UNICODE
      SCardForgetCardType equ <SCardForgetCardTypeW>
    else
      SCardForgetCardType equ <SCardForgetCardTypeA>
    endif
    SCardFreeMemory proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCVOID
    if (NTDDI_VERSION ge NTDDI_WINXP)
      SCardAccessStartedEvent proto WIN_STD_CALL_CONV
      SCardReleaseStartedEvent proto WIN_STD_CALL_CONV
    endif
    SCARD_READERSTATEA struct
      szReader LPCSTR ?
      pvUserData LPVOID ?
      dwCurrentState DWORD ?
      dwEventState DWORD ?
      cbAtr DWORD ?
      rgbAtr BYTE 36 dup (?)
    SCARD_READERSTATEA ends
    PSCARD_READERSTATEA typedef ptr SCARD_READERSTATEA
    LPSCARD_READERSTATEA typedef ptr SCARD_READERSTATEA
    SCARD_READERSTATEW struct
      szReader LPCWSTR ?
      pvUserData LPVOID ?
      dwCurrentState DWORD ?
      dwEventState DWORD ?
      cbAtr DWORD ?
      rgbAtr BYTE 36 dup (?)
    SCARD_READERSTATEW ends
    PSCARD_READERSTATEW typedef ptr SCARD_READERSTATEW
    LPSCARD_READERSTATEW typedef ptr SCARD_READERSTATEW
    ifdef UNICODE
      SCARD_READERSTATE typedef SCARD_READERSTATEW
      PSCARD_READERSTATE typedef PSCARD_READERSTATEW
      LPSCARD_READERSTATE typedef LPSCARD_READERSTATEW
    else
      SCARD_READERSTATE typedef SCARD_READERSTATEA
      PSCARD_READERSTATE typedef PSCARD_READERSTATEA
      LPSCARD_READERSTATE typedef LPSCARD_READERSTATEA
    endif
    SCARD_READERSTATE_A equ <SCARD_READERSTATEA>
    SCARD_READERSTATE_W equ <SCARD_READERSTATEW>
    PSCARD_READERSTATE_A equ <PSCARD_READERSTATEA>
    PSCARD_READERSTATE_W equ <PSCARD_READERSTATEW>
    LPSCARD_READERSTATE_A equ <LPSCARD_READERSTATEA>
    LPSCARD_READERSTATE_W equ <LPSCARD_READERSTATEW>
    SCARD_STATE_UNAWARE equ 00000000h
    SCARD_STATE_IGNORE equ 00000001h
    SCARD_STATE_CHANGED equ 00000002h
    SCARD_STATE_UNKNOWN equ 00000004h
    SCARD_STATE_UNAVAILABLE equ 00000008h
    SCARD_STATE_EMPTY equ 00000010h
    SCARD_STATE_PRESENT equ 00000020h
    SCARD_STATE_ATRMATCH equ 00000040h
    SCARD_STATE_EXCLUSIVE equ 00000080h
    SCARD_STATE_INUSE equ 00000100h
    SCARD_STATE_MUTE equ 00000200h
    SCARD_STATE_UNPOWERED equ 00000400h
    SCardLocateCardsA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR, :LPSCARD_READERSTATEA, :DWORD
    SCardLocateCardsW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR, :LPSCARD_READERSTATEW, :DWORD
    ifdef UNICODE
      SCardLocateCards equ <SCardLocateCardsW>
    else
      SCardLocateCards equ <SCardLocateCardsA>
    endif
    if (NTDDI_VERSION ge NTDDI_WINXP)
      SCARD_ATRMASK struct
        cbAtr DWORD ?
        rgbAtr BYTE 36 dup (?)
        rgbMask BYTE 36 dup (?)
      SCARD_ATRMASK ends
      _SCARD_ATRMASK typedef SCARD_ATRMASK
      PSCARD_ATRMASK typedef ptr SCARD_ATRMASK
      LPSCARD_ATRMASK typedef ptr SCARD_ATRMASK
      SCardLocateCardsByATRA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPSCARD_ATRMASK, :DWORD, :LPSCARD_READERSTATEA, :DWORD
      SCardLocateCardsByATRW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPSCARD_ATRMASK, :DWORD, :LPSCARD_READERSTATEW, :DWORD
      ifdef UNICODE
        SCardLocateCardsByATR equ <SCardLocateCardsByATRW>
      else
        SCardLocateCardsByATR equ <SCardLocateCardsByATRA>
      endif
    endif
    SCardGetStatusChangeA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :DWORD, :LPSCARD_READERSTATEA, :DWORD
    SCardGetStatusChangeW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :DWORD, :LPSCARD_READERSTATEW, :DWORD
    ifdef UNICODE
      SCardGetStatusChange equ <SCardGetStatusChangeW>
    else
      SCardGetStatusChange equ <SCardGetStatusChangeA>
    endif
    SCardCancel proto WIN_STD_CALL_CONV :SCARDCONTEXT
    SCARD_SHARE_EXCLUSIVE equ 1
    SCARD_SHARE_SHARED equ 2
    SCARD_SHARE_DIRECT equ 3
    SCARD_LEAVE_CARD equ 0
    SCARD_RESET_CARD equ 1
    SCARD_UNPOWER_CARD equ 2
    SCARD_EJECT_CARD equ 3
    SCardConnectA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR, :DWORD, :DWORD, :LPSCARDHANDLE, :LPDWORD
    SCardConnectW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR, :DWORD, :DWORD, :LPSCARDHANDLE, :LPDWORD
    ifdef UNICODE
      SCardConnect equ <SCardConnectW>
    else
      SCardConnect equ <SCardConnectA>
    endif
    SCardReconnect proto WIN_STD_CALL_CONV :SCARDHANDLE, :DWORD, :DWORD, :DWORD, :LPDWORD
    SCardDisconnect proto WIN_STD_CALL_CONV :SCARDHANDLE, :DWORD
    SCardBeginTransaction proto WIN_STD_CALL_CONV :SCARDHANDLE
    SCardEndTransaction proto WIN_STD_CALL_CONV :SCARDHANDLE, :DWORD
    SCardCancelTransaction proto WIN_STD_CALL_CONV :SCARDHANDLE
    SCardState proto WIN_STD_CALL_CONV :SCARDHANDLE, :LPDWORD, :LPDWORD, :LPBYTE, :LPDWORD
    SCardStatusA proto WIN_STD_CALL_CONV :SCARDHANDLE, :LPSTR, :LPDWORD, :LPDWORD, :LPDWORD, :LPBYTE, :LPDWORD
    SCardStatusW proto WIN_STD_CALL_CONV :SCARDHANDLE, :LPWSTR, :LPDWORD, :LPDWORD, :LPDWORD, :LPBYTE, :LPDWORD
    ifdef UNICODE
      SCardStatus equ <SCardStatusW>
    else
      SCardStatus equ <SCardStatusA>
    endif
    SCardTransmit proto WIN_STD_CALL_CONV :SCARDHANDLE, :LPCSCARD_IO_REQUEST, :LPCBYTE, :DWORD, :LPSCARD_IO_REQUEST, :LPBYTE, :LPDWORD
    if (NTDDI_VERSION ge NTDDI_VISTA)
      SCardGetTransmitCount proto WIN_STD_CALL_CONV :SCARDHANDLE, :LPDWORD
    endif
    SCardControl proto WIN_STD_CALL_CONV :SCARDHANDLE, :DWORD, :LPCVOID, :DWORD, :LPVOID, :DWORD, :LPDWORD
    SCardGetAttrib proto WIN_STD_CALL_CONV :SCARDHANDLE, :DWORD, :LPBYTE, :LPDWORD
    SCardGetReaderCapabilities equ <SCardGetAttrib>
    SCardSetAttrib proto WIN_STD_CALL_CONV :SCARDHANDLE, :DWORD, :LPCBYTE, :DWORD
    SCardSetReaderCapabilities equ <SCardSetAttrib>
    SC_DLG_MINIMAL_UI equ 01h
    SC_DLG_NO_UI equ 02h
    SC_DLG_FORCE_UI equ 04h
    SCERR_NOCARDNAME equ 4000h
    SCERR_NOGUIDS equ 8000h
    TYPE_LPOCNCONNPROCA typedef proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPSTR, :LPSTR, :PVOID
    LPOCNCONNPROCA typedef ptr TYPE_LPOCNCONNPROCA

    TYPE_LPOCNCONNPROCW typedef proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPWSTR, :LPWSTR, :PVOID
    LPOCNCONNPROCW typedef ptr TYPE_LPOCNCONNPROCW

    ifdef UNICODE
      LPOCNCONNPROC equ <LPOCNCONNPROCW>
    else
      LPOCNCONNPROC equ <LPOCNCONNPROCA>
    endif
    TYPE_LPOCNCHKPROC typedef proto WIN_STD_CALL_CONV :SCARDCONTEXT, :SCARDHANDLE, :PVOID
    LPOCNCHKPROC typedef ptr TYPE_LPOCNCHKPROC

    TYPE_LPOCNDSCPROC typedef proto WIN_STD_CALL_CONV :SCARDCONTEXT, :SCARDHANDLE, :PVOID
    LPOCNDSCPROC typedef ptr TYPE_LPOCNDSCPROC

    OPENCARD_SEARCH_CRITERIAA struct
      dwStructSize DWORD ?
      lpstrGroupNames LPSTR ?
      nMaxGroupNames DWORD ?
      rgguidInterfaces LPCGUID ?
      cguidInterfaces DWORD ?
      lpstrCardNames LPSTR ?
      nMaxCardNames DWORD ?
      lpfnCheck LPOCNCHKPROC ?
      lpfnConnect LPOCNCONNPROCA ?
      lpfnDisconnect LPOCNDSCPROC ?
      pvUserData LPVOID ?
      dwShareMode DWORD ?
      dwPreferredProtocols DWORD ?
    OPENCARD_SEARCH_CRITERIAA ends
    POPENCARD_SEARCH_CRITERIAA typedef ptr OPENCARD_SEARCH_CRITERIAA
    LPOPENCARD_SEARCH_CRITERIAA typedef ptr OPENCARD_SEARCH_CRITERIAA
    OPENCARD_SEARCH_CRITERIAW struct
      dwStructSize DWORD ?
      lpstrGroupNames LPWSTR ?
      nMaxGroupNames DWORD ?
      rgguidInterfaces LPCGUID ?
      cguidInterfaces DWORD ?
      lpstrCardNames LPWSTR ?
      nMaxCardNames DWORD ?
      lpfnCheck LPOCNCHKPROC ?
      lpfnConnect LPOCNCONNPROCW ?
      lpfnDisconnect LPOCNDSCPROC ?
      pvUserData LPVOID ?
      dwShareMode DWORD ?
      dwPreferredProtocols DWORD ?
    OPENCARD_SEARCH_CRITERIAW ends
    POPENCARD_SEARCH_CRITERIAW typedef ptr OPENCARD_SEARCH_CRITERIAW
    LPOPENCARD_SEARCH_CRITERIAW typedef ptr OPENCARD_SEARCH_CRITERIAW
    ifdef UNICODE
      OPENCARD_SEARCH_CRITERIA typedef OPENCARD_SEARCH_CRITERIAW
      POPENCARD_SEARCH_CRITERIA typedef POPENCARD_SEARCH_CRITERIAW
      LPOPENCARD_SEARCH_CRITERIA typedef LPOPENCARD_SEARCH_CRITERIAW
    else
      OPENCARD_SEARCH_CRITERIA typedef OPENCARD_SEARCH_CRITERIAA
      POPENCARD_SEARCH_CRITERIA typedef POPENCARD_SEARCH_CRITERIAA
      LPOPENCARD_SEARCH_CRITERIA typedef LPOPENCARD_SEARCH_CRITERIAA
    endif
    OPENCARDNAME_EXA struct
      dwStructSize DWORD ?
      hSCardContext SCARDCONTEXT ?
      hwndOwner HWND ?
      dwFlags DWORD ?
      lpstrTitle LPCSTR ?
      lpstrSearchDesc LPCSTR ?
      hIcon HICON ?
      pOpenCardSearchCriteria POPENCARD_SEARCH_CRITERIAA ?
      lpfnConnect LPOCNCONNPROCA ?
      pvUserData LPVOID ?
      dwShareMode DWORD ?
      dwPreferredProtocols DWORD ?
      lpstrRdr LPSTR ?
      nMaxRdr DWORD ?
      lpstrCard LPSTR ?
      nMaxCard DWORD ?
      dwActiveProtocol DWORD ?
      hCardHandle SCARDHANDLE ?
    OPENCARDNAME_EXA ends
    POPENCARDNAME_EXA typedef ptr OPENCARDNAME_EXA
    LPOPENCARDNAME_EXA typedef ptr OPENCARDNAME_EXA
    OPENCARDNAME_EXW struct
      dwStructSize DWORD ?
      hSCardContext SCARDCONTEXT ?
      hwndOwner HWND ?
      dwFlags DWORD ?
      lpstrTitle LPCWSTR ?
      lpstrSearchDesc LPCWSTR ?
      hIcon HICON ?
      pOpenCardSearchCriteria POPENCARD_SEARCH_CRITERIAW ?
      lpfnConnect LPOCNCONNPROCW ?
      pvUserData LPVOID ?
      dwShareMode DWORD ?
      dwPreferredProtocols DWORD ?
      lpstrRdr LPWSTR ?
      nMaxRdr DWORD ?
      lpstrCard LPWSTR ?
      nMaxCard DWORD ?
      dwActiveProtocol DWORD ?
      hCardHandle SCARDHANDLE ?
    OPENCARDNAME_EXW ends
    POPENCARDNAME_EXW typedef ptr OPENCARDNAME_EXW
    LPOPENCARDNAME_EXW typedef ptr OPENCARDNAME_EXW
    ifdef UNICODE
      OPENCARDNAME_EX typedef OPENCARDNAME_EXW
      POPENCARDNAME_EX typedef POPENCARDNAME_EXW
      LPOPENCARDNAME_EX typedef LPOPENCARDNAME_EXW
    else
      OPENCARDNAME_EX typedef OPENCARDNAME_EXA
      POPENCARDNAME_EX typedef POPENCARDNAME_EXA
      LPOPENCARDNAME_EX typedef LPOPENCARDNAME_EXA
    endif
    OPENCARDNAMEA_EX equ <OPENCARDNAME_EXA>
    OPENCARDNAMEW_EX equ <OPENCARDNAME_EXW>
    POPENCARDNAMEA_EX equ <POPENCARDNAME_EXA>
    POPENCARDNAMEW_EX equ <POPENCARDNAME_EXW>
    LPOPENCARDNAMEA_EX equ <LPOPENCARDNAME_EXA>
    LPOPENCARDNAMEW_EX equ <LPOPENCARDNAME_EXW>
    SCARD_READER_SEL_AUTH_PACKAGE equ (- 629)
    READER_SEL_REQUEST_MATCH_TYPE typedef SDWORD
    RSR_MATCH_TYPE_READER_AND_CONTAINER equ 1
    RSR_MATCH_TYPE_SERIAL_NUMBER equ 2
    RSR_MATCH_TYPE_ALL_CARDS equ 3

    READER_SEL_REQUEST struct
      dwShareMode DWORD ?
      dwPreferredProtocols DWORD ?
      MatchType READER_SEL_REQUEST_MATCH_TYPE ?
      union
        struct ReaderAndContainerParameter
          cbReaderNameOffset DWORD ?
          cchReaderNameLength DWORD ?
          cbContainerNameOffset DWORD ?
          cchContainerNameLength DWORD ?
          dwDesiredCardModuleVersion DWORD ?
          dwCspFlags DWORD ?
        ends
        struct SerialNumberParameter
          cbSerialNumberOffset DWORD ?
          cbSerialNumberLength DWORD ?
          dwDesiredCardModuleVersion DWORD ?
        ends
      ends
    READER_SEL_REQUEST ends
    PREADER_SEL_REQUEST typedef ptr READER_SEL_REQUEST
    READER_SEL_RESPONSE struct
      cbReaderNameOffset DWORD ?
      cchReaderNameLength DWORD ?
      cbCardNameOffset DWORD ?
      cchCardNameLength DWORD ?
    READER_SEL_RESPONSE ends
    PREADER_SEL_RESPONSE typedef ptr READER_SEL_RESPONSE
    SCardUIDlgSelectCardA proto WIN_STD_CALL_CONV :LPOPENCARDNAMEA_EX
    SCardUIDlgSelectCardW proto WIN_STD_CALL_CONV :LPOPENCARDNAMEW_EX
    ifdef UNICODE
      SCardUIDlgSelectCard equ <SCardUIDlgSelectCardW>
    else
      SCardUIDlgSelectCard equ <SCardUIDlgSelectCardA>
    endif
    OPENCARDNAMEA struct
      dwStructSize DWORD ?
      hwndOwner HWND ?
      hSCardContext SCARDCONTEXT ?
      lpstrGroupNames LPSTR ?
      nMaxGroupNames DWORD ?
      lpstrCardNames LPSTR ?
      nMaxCardNames DWORD ?
      rgguidInterfaces LPCGUID ?
      cguidInterfaces DWORD ?
      lpstrRdr LPSTR ?
      nMaxRdr DWORD ?
      lpstrCard LPSTR ?
      nMaxCard DWORD ?
      lpstrTitle LPCSTR ?
      dwFlags DWORD ?
      pvUserData LPVOID ?
      dwShareMode DWORD ?
      dwPreferredProtocols DWORD ?
      dwActiveProtocol DWORD ?
      lpfnConnect LPOCNCONNPROCA ?
      lpfnCheck LPOCNCHKPROC ?
      lpfnDisconnect LPOCNDSCPROC ?
      hCardHandle SCARDHANDLE ?
    OPENCARDNAMEA ends
    POPENCARDNAMEA typedef ptr OPENCARDNAMEA
    LPOPENCARDNAMEA typedef ptr OPENCARDNAMEA
    OPENCARDNAMEW struct
      dwStructSize DWORD ?
      hwndOwner HWND ?
      hSCardContext SCARDCONTEXT ?
      lpstrGroupNames LPWSTR ?
      nMaxGroupNames DWORD ?
      lpstrCardNames LPWSTR ?
      nMaxCardNames DWORD ?
      rgguidInterfaces LPCGUID ?
      cguidInterfaces DWORD ?
      lpstrRdr LPWSTR ?
      nMaxRdr DWORD ?
      lpstrCard LPWSTR ?
      nMaxCard DWORD ?
      lpstrTitle LPCWSTR ?
      dwFlags DWORD ?
      pvUserData LPVOID ?
      dwShareMode DWORD ?
      dwPreferredProtocols DWORD ?
      dwActiveProtocol DWORD ?
      lpfnConnect LPOCNCONNPROCW ?
      lpfnCheck LPOCNCHKPROC ?
      lpfnDisconnect LPOCNDSCPROC ?
      hCardHandle SCARDHANDLE ?
    OPENCARDNAMEW ends
    POPENCARDNAMEW typedef ptr OPENCARDNAMEW
    LPOPENCARDNAMEW typedef ptr OPENCARDNAMEW
    ifdef UNICODE
      OPENCARDNAME typedef OPENCARDNAMEW
      POPENCARDNAME typedef POPENCARDNAMEW
      LPOPENCARDNAME typedef LPOPENCARDNAMEW
    else
      OPENCARDNAME typedef OPENCARDNAMEA
      POPENCARDNAME typedef POPENCARDNAMEA
      LPOPENCARDNAME typedef LPOPENCARDNAMEA
    endif
    OPENCARDNAME_A equ <OPENCARDNAMEA>
    OPENCARDNAME_W equ <OPENCARDNAMEW>
    POPENCARDNAME_A equ <POPENCARDNAMEA>
    POPENCARDNAME_W equ <POPENCARDNAMEW>
    LPOPENCARDNAME_A equ <LPOPENCARDNAMEA>
    LPOPENCARDNAME_W equ <LPOPENCARDNAMEW>
    GetOpenCardNameA proto WIN_STD_CALL_CONV :LPOPENCARDNAMEA
    GetOpenCardNameW proto WIN_STD_CALL_CONV :LPOPENCARDNAMEW
    ifdef UNICODE
      GetOpenCardName equ <GetOpenCardNameW>
    else
      GetOpenCardName equ <GetOpenCardNameA>
    endif
    SCardDlgExtendedError proto WIN_STD_CALL_CONV
    if (NTDDI_VERSION ge NTDDI_VISTA)
      SCardReadCacheA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :ptr UUID, :DWORD, :LPSTR, :PBYTE, :ptr DWORD
      SCardReadCacheW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :ptr UUID, :DWORD, :LPWSTR, :PBYTE, :ptr DWORD
      ifdef UNICODE
        SCardReadCache equ <SCardReadCacheW>
      else
        SCardReadCache equ <SCardReadCacheA>
      endif
      SCardWriteCacheA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :ptr UUID, :DWORD, :LPSTR, :PBYTE, :DWORD
      SCardWriteCacheW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :ptr UUID, :DWORD, :LPWSTR, :PBYTE, :DWORD
      ifdef UNICODE
        SCardWriteCache equ <SCardWriteCacheW>
      else
        SCardWriteCache equ <SCardWriteCacheA>
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_WIN8)
      SCardGetReaderIconA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR, :LPBYTE, :LPDWORD
      SCardGetReaderIconW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR, :LPBYTE, :LPDWORD
      ifdef UNICODE
        SCardGetReaderIcon equ <SCardGetReaderIconW>
      else
        SCardGetReaderIcon equ <SCardGetReaderIconA>
      endif
      SCardGetDeviceTypeIdA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR, :LPDWORD
      SCardGetDeviceTypeIdW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR, :LPDWORD
      ifdef UNICODE
        SCardGetDeviceTypeId equ <SCardGetDeviceTypeIdW>
      else
        SCardGetDeviceTypeId equ <SCardGetDeviceTypeIdA>
      endif
      SCardGetReaderDeviceInstanceIdA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR, :LPSTR, :LPDWORD
      SCardGetReaderDeviceInstanceIdW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR, :LPWSTR, :LPDWORD
      ifdef UNICODE
        SCardGetReaderDeviceInstanceId equ <SCardGetReaderDeviceInstanceIdW>
      else
        SCardGetReaderDeviceInstanceId equ <SCardGetReaderDeviceInstanceIdA>
      endif
      SCardListReadersWithDeviceInstanceIdA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR, :LPSTR, :LPDWORD
      SCardListReadersWithDeviceInstanceIdW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR, :LPWSTR, :LPDWORD
      ifdef UNICODE
        SCardListReadersWithDeviceInstanceId equ <SCardListReadersWithDeviceInstanceIdW>
      else
        SCardListReadersWithDeviceInstanceId equ <SCardListReadersWithDeviceInstanceIdA>
      endif
      SCARD_AUDIT_CHV_FAILURE equ 0h
      SCARD_AUDIT_CHV_SUCCESS equ 1h
      SCardAudit proto WIN_STD_CALL_CONV :SCARDCONTEXT, :DWORD
    endif
  endif
  if _MSC_VER ge 1200
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
