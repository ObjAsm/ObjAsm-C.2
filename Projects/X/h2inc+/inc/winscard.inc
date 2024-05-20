;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\winscard.h
;             Created on (UTC) 06/04/2024 06:16:03
;             Last modified on (UTC) 21/02/2024 18:13:14

;--*
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
    ; padding added after data member
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
    ;* In clr:pure we cannot mark data export with dllimport.
    ;* We should add small functions which returns the value of
    ;* the global.
    ;*
    if  not Defined(_M_CEE_PURE)
      SCARD_PCI_T0 equ <(and g_rgSCardT0Pci)>
      SCARD_PCI_T1 equ <(and g_rgSCardT1Pci)>
      SCARD_PCI_RAW equ <(and g_rgSCardRawPci)>
    endif
    ;//////////////////////////////////////////////////////////////////////////////
    ;  Service Manager Access Services
    ;      The following services are used to manage user and terminal contexts for
    ;      Smart Cards.
    SCARDCONTEXT typedef ULONG_PTR
    PSCARDCONTEXT typedef ptr SCARDCONTEXT
    LPSCARDCONTEXT typedef ptr SCARDCONTEXT
    SCARDHANDLE typedef ULONG_PTR
    PSCARDHANDLE typedef ptr SCARDHANDLE
    LPSCARDHANDLE typedef ptr SCARDHANDLE
    SCARD_AUTOALLOCATE equ (- 1)
    SCARD_SCOPE_USER equ 0; The context is a user context, and any

    ; database operations are performed within the
    ; domain of the user.
    SCARD_SCOPE_TERMINAL equ 1; The context is that of the current terminal,

    ; and any database operations are performed
    ; within the domain of that terminal.  (The
    ; calling application must have appropriate
    ; access permissions for any database actions.)
    SCARD_SCOPE_SYSTEM equ 2; The context is the system context, and any

    ; database operations are performed within the
    ; domain of the system.  (The calling
    ; application must have appropriate access
    ; permissions for any database actions.)
    SCardEstablishContext proto WIN_STD_CALL_CONV :DWORD, :LPCVOID, :LPCVOID, :LPSCARDCONTEXT
    SCardReleaseContext proto WIN_STD_CALL_CONV :SCARDCONTEXT
    SCardIsValidContext proto WIN_STD_CALL_CONV :SCARDCONTEXT
    ;//////////////////////////////////////////////////////////////////////////////
    ;  Smart Card Database Management Services
    ;      The following services provide for managing the Smart Card Database.
    SCARD_ALL_READERS equ <TEXT("SCard$AllReaders",000o)>
    SCARD_DEFAULT_READERS equ <TEXT("SCard$DefaultReaders",000o)>
    SCARD_LOCAL_READERS equ <TEXT("SCard$LocalReaders",000o)>
    SCARD_SYSTEM_READERS equ <TEXT("SCard$SystemReaders",000o)>
    SCARD_PROVIDER_PRIMARY equ 1; Primary Provider Id

    SCARD_PROVIDER_CSP equ 2; Crypto Service Provider Id

    SCARD_PROVIDER_KSP equ 3; Key Storage Provider Id

    ; Database Reader routines
    SCardListReaderGroupsA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPSTR, :LPDWORD
    SCardListReaderGroupsW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPWSTR, :LPDWORD
    ifdef UNICODE
      SCardListReaderGroups equ <SCardListReaderGroupsW>
    else
      SCardListReaderGroups equ <SCardListReaderGroupsA>
    endif
    ; !UNICODE
    SCardListReadersA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR, :LPSTR, :LPDWORD
    SCardListReadersW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR, :LPWSTR, :LPDWORD
    ifdef UNICODE
      SCardListReaders equ <SCardListReadersW>
    else
      SCardListReaders equ <SCardListReadersA>
    endif
    ; !UNICODE
    SCardListCardsA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCBYTE, :LPCGUID, :DWORD, :ptr CHAR, :LPDWORD
    SCardListCardsW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCBYTE, :LPCGUID, :DWORD, :ptr WCHAR, :LPDWORD
    ifdef UNICODE
      SCardListCards equ <SCardListCardsW>
    else
      SCardListCards equ <SCardListCardsA>
    endif
    ; !UNICODE
    ; NOTE:    The routine SCardListCards name differs from the PC/SC definition.
    ;          It should be:
    ;              extern WINSCARDAPI LONG WINAPI
    ;              SCardListCardTypes(
    ;                  _In_      SCARDCONTEXT hContext,
    ;                  _In_opt_  LPCBYTE pbAtr,
    ;                  _In_opt_  LPCGUID rgquidInterfaces,
    ;                  _In_      DWORD cguidInterfaceCount,
    ;                  _Out_opt_ LPTSTR mszCards,
    ;                  _Inout_   LPDWORD pcchCards);
    ;          Here's a work-around MACRO:
    SCardListCardTypes equ <SCardListCards>
    SCardListInterfacesA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR, :LPGUID, :LPDWORD
    SCardListInterfacesW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR, :LPGUID, :LPDWORD
    ifdef UNICODE
      SCardListInterfaces equ <SCardListInterfacesW>
    else
      SCardListInterfaces equ <SCardListInterfacesA>
    endif
    ; !UNICODE
    SCardGetProviderIdA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR, :LPGUID
    SCardGetProviderIdW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR, :LPGUID
    ifdef UNICODE
      SCardGetProviderId equ <SCardGetProviderIdW>
    else
      SCardGetProviderId equ <SCardGetProviderIdA>
    endif
    ; !UNICODE
    ; NOTE:    The routine SCardGetProviderId in this implementation uses GUIDs.
    ;          The PC/SC definition uses BYTEs.
    SCardGetCardTypeProviderNameA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR, :DWORD, :ptr CHAR, :LPDWORD
    SCardGetCardTypeProviderNameW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR, :DWORD, :ptr WCHAR, :LPDWORD
    ifdef UNICODE
      SCardGetCardTypeProviderName equ <SCardGetCardTypeProviderNameW>
    else
      SCardGetCardTypeProviderName equ <SCardGetCardTypeProviderNameA>
    endif
    ; !UNICODE
    ; NOTE:    This routine is an extension to the PC/SC definitions.
    ; Database Writer routines
    SCardIntroduceReaderGroupA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR
    SCardIntroduceReaderGroupW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR
    ifdef UNICODE
      SCardIntroduceReaderGroup equ <SCardIntroduceReaderGroupW>
    else
      SCardIntroduceReaderGroup equ <SCardIntroduceReaderGroupA>
    endif
    ; !UNICODE
    SCardForgetReaderGroupA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR
    SCardForgetReaderGroupW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR
    ifdef UNICODE
      SCardForgetReaderGroup equ <SCardForgetReaderGroupW>
    else
      SCardForgetReaderGroup equ <SCardForgetReaderGroupA>
    endif
    ; !UNICODE
    SCardIntroduceReaderA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR, :LPCSTR
    SCardIntroduceReaderW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR, :LPCWSTR
    ifdef UNICODE
      SCardIntroduceReader equ <SCardIntroduceReaderW>
    else
      SCardIntroduceReader equ <SCardIntroduceReaderA>
    endif
    ; !UNICODE
    SCardForgetReaderA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR
    SCardForgetReaderW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR
    ifdef UNICODE
      SCardForgetReader equ <SCardForgetReaderW>
    else
      SCardForgetReader equ <SCardForgetReaderA>
    endif
    ; !UNICODE
    SCardAddReaderToGroupA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR, :LPCSTR
    SCardAddReaderToGroupW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR, :LPCWSTR
    ifdef UNICODE
      SCardAddReaderToGroup equ <SCardAddReaderToGroupW>
    else
      SCardAddReaderToGroup equ <SCardAddReaderToGroupA>
    endif
    ; !UNICODE
    SCardRemoveReaderFromGroupA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR, :LPCSTR
    SCardRemoveReaderFromGroupW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR, :LPCWSTR
    ifdef UNICODE
      SCardRemoveReaderFromGroup equ <SCardRemoveReaderFromGroupW>
    else
      SCardRemoveReaderFromGroup equ <SCardRemoveReaderFromGroupA>
    endif
    ; !UNICODE
    SCardIntroduceCardTypeA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR, :LPCGUID, :LPCGUID, :DWORD, :LPCBYTE, :LPCBYTE, :DWORD
    SCardIntroduceCardTypeW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR, :LPCGUID, :LPCGUID, :DWORD, :LPCBYTE, :LPCBYTE, :DWORD
    ifdef UNICODE
      SCardIntroduceCardType equ <SCardIntroduceCardTypeW>
    else
      SCardIntroduceCardType equ <SCardIntroduceCardTypeA>
    endif
    ; !UNICODE
    ; NOTE:    The routine SCardIntroduceCardType's parameters' order differs from
    ;          the PC/SC definition.  It should be:
    ;              extern WINSCARDAPI LONG WINAPI
    ;              SCardIntroduceCardType(
    ;                  _In_     SCARDCONTEXT hContext,
    ;                  _In_     LPCTSTR szCardName,
    ;                  _In_     LPCBYTE pbAtr,
    ;                  _In_     LPCBYTE pbAtrMask,
    ;                  _In_     DWORD cbAtrLen,
    ;                  _In_opt_ LPCGUID pguidPrimaryProvider,
    ;                  _In_opt_ LPCGUID rgguidInterfaces,
    ;                  _In_     DWORD dwInterfaceCount);
    ;          Here's a work-around MACRO:
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
    ; !UNICODE
    ; NOTE:    This routine is an extention to the PC/SC specifications.
    SCardForgetCardTypeA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR
    SCardForgetCardTypeW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR
    ifdef UNICODE
      SCardForgetCardType equ <SCardForgetCardTypeW>
    else
      SCardForgetCardType equ <SCardForgetCardTypeA>
    endif
    ; !UNICODE
    ;//////////////////////////////////////////////////////////////////////////////
    ;  Service Manager Support Routines
    ;      The following services are supplied to simplify the use of the Service
    ;      Manager API.
    SCardFreeMemory proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCVOID
    if (NTDDI_VERSION ge NTDDI_WINXP)
      SCardAccessStartedEvent proto WIN_STD_CALL_CONV
      SCardReleaseStartedEvent proto WIN_STD_CALL_CONV
    endif
    ; (NTDDI_VERSION >= NTDDI_WINXP)
    ;//////////////////////////////////////////////////////////////////////////////
    ;  Reader Services
    ;      The following services supply means for tracking cards within readers.
    SCARD_READERSTATEA struct
      szReader =POINTER ?
      ; reader name
      pvUserData POINTER ?
      ; user defined data
      dwCurrentState DWORD ?
      ; current state of reader at time of call
      dwEventState DWORD ?
      ; state of reader after state change
      cbAtr DWORD ?
      ; Number of bytes in the returned ATR.
      rgbAtr BYTE 36 dup (?)
      ; Atr of inserted card, (extra alignment bytes)
    SCARD_READERSTATEA ends
    PSCARD_READERSTATEA typedef ptr SCARD_READERSTATEA
    LPSCARD_READERSTATEA typedef ptr SCARD_READERSTATEA
    SCARD_READERSTATEW struct
      szReader =POINTER ?
      ; reader name
      pvUserData POINTER ?
      ; user defined data
      dwCurrentState DWORD ?
      ; current state of reader at time of call
      dwEventState DWORD ?
      ; state of reader after state change
      cbAtr DWORD ?
      ; Number of bytes in the returned ATR.
      rgbAtr BYTE 36 dup (?)
      ; Atr of inserted card, (extra alignment bytes)
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
    ; UNICODE
    ; Backwards compatibility macros
    SCARD_READERSTATE_A equ <SCARD_READERSTATEA>
    SCARD_READERSTATE_W equ <SCARD_READERSTATEW>
    PSCARD_READERSTATE_A equ <PSCARD_READERSTATEA>
    PSCARD_READERSTATE_W equ <PSCARD_READERSTATEW>
    LPSCARD_READERSTATE_A equ <LPSCARD_READERSTATEA>
    LPSCARD_READERSTATE_W equ <LPSCARD_READERSTATEW>
    SCARD_STATE_UNAWARE equ 00000000h; The application is unaware of the

    ; current state, and would like to
    ; know.  The use of this value
    ; results in an immediate return
    ; from state transition monitoring
    ; services.  This is represented by
    ; all bits set to zero.
    SCARD_STATE_IGNORE equ 00000001h; The application requested that

    ; this reader be ignored.  No other
    ; bits will be set.
    SCARD_STATE_CHANGED equ 00000002h; This implies that there is a

    ; difference between the state
    ; believed by the application, and
    ; the state known by the Service
    ; Manager.  When this bit is set,
    ; the application may assume a
    ; significant state change has
    ; occurred on this reader.
    SCARD_STATE_UNKNOWN equ 00000004h; This implies that the given

    ; reader name is not recognized by
    ; the Service Manager.  If this bit
    ; is set, then SCARD_STATE_CHANGED
    ; and SCARD_STATE_IGNORE will also
    ; be set.
    SCARD_STATE_UNAVAILABLE equ 00000008h; This implies that the actual

    ; state of this reader is not
    ; available.  If this bit is set,
    ; then all the following bits are
    ; clear.
    SCARD_STATE_EMPTY equ 00000010h; This implies that there is not

    ; card in the reader.  If this bit
    ; is set, all the following bits
    ; will be clear.
    SCARD_STATE_PRESENT equ 00000020h; This implies that there is a card

    ; in the reader.
    SCARD_STATE_ATRMATCH equ 00000040h; This implies that there is a card

    ; in the reader with an ATR
    ; matching one of the target cards.
    ; If this bit is set,
    ; SCARD_STATE_PRESENT will also be
    ; set.  This bit is only returned
    ; on the SCardLocateCard() service.
    SCARD_STATE_EXCLUSIVE equ 00000080h; This implies that the card in the

    ; reader is allocated for exclusive
    ; use by another application.  If
    ; this bit is set,
    ; SCARD_STATE_PRESENT will also be
    ; set.
    SCARD_STATE_INUSE equ 00000100h; This implies that the card in the

    ; reader is in use by one or more
    ; other applications, but may be
    ; connected to in shared mode.  If
    ; this bit is set,
    ; SCARD_STATE_PRESENT will also be
    ; set.
    SCARD_STATE_MUTE equ 00000200h; This implies that the card in the

    ; reader is unresponsive or not
    ; supported by the reader or
    ; software.
    SCARD_STATE_UNPOWERED equ 00000400h; This implies that the card in the

    ; reader has not been powered up.
    SCardLocateCardsA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR, :LPSCARD_READERSTATEA, :DWORD
    SCardLocateCardsW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR, :LPSCARD_READERSTATEW, :DWORD
    ifdef UNICODE
      SCardLocateCards equ <SCardLocateCardsW>
    else
      SCardLocateCards equ <SCardLocateCardsA>
    endif
    ; !UNICODE
    if (NTDDI_VERSION ge NTDDI_WINXP)
      SCARD_ATRMASK struct
        cbAtr DWORD ?
        ; Number of bytes in the ATR and the mask.
        rgbAtr BYTE 36 dup (?)
        ; Atr of card (extra alignment bytes)
        rgbMask BYTE 36 dup (?)
        ; Mask for the Atr (extra alignment bytes)
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
      ; !UNICODE
    endif
    ; (NTDDI_VERSION >= NTDDI_WINXP)
    SCardGetStatusChangeA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :DWORD, :LPSCARD_READERSTATEA, :DWORD
    SCardGetStatusChangeW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :DWORD, :LPSCARD_READERSTATEW, :DWORD
    ifdef UNICODE
      SCardGetStatusChange equ <SCardGetStatusChangeW>
    else
      SCardGetStatusChange equ <SCardGetStatusChangeA>
    endif
    ; !UNICODE
    SCardCancel proto WIN_STD_CALL_CONV :SCARDCONTEXT
    ;//////////////////////////////////////////////////////////////////////////////
    ;  Card/Reader Communication Services
    ;      The following services provide means for communication with the card.
    SCARD_SHARE_EXCLUSIVE equ 1; This application is not willing to share this

    ; card with other applications.
    SCARD_SHARE_SHARED equ 2; This application is willing to share this

    ; card with other applications.
    SCARD_SHARE_DIRECT equ 3; This application demands direct control of

    ; the reader, so it is not available to other
    ; applications.
    SCARD_LEAVE_CARD equ 0; Don't do anything special on close

    SCARD_RESET_CARD equ 1; Reset the card on close

    SCARD_UNPOWER_CARD equ 2; Power down the card on close

    SCARD_EJECT_CARD equ 3; Eject the card on close

    SCardConnectA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR, :DWORD, :DWORD, :LPSCARDHANDLE, :LPDWORD
    SCardConnectW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR, :DWORD, :DWORD, :LPSCARDHANDLE, :LPDWORD
    ifdef UNICODE
      SCardConnect equ <SCardConnectW>
    else
      SCardConnect equ <SCardConnectA>
    endif
    ; !UNICODE
    SCardReconnect proto WIN_STD_CALL_CONV :SCARDHANDLE, :DWORD, :DWORD, :DWORD, :LPDWORD
    SCardDisconnect proto WIN_STD_CALL_CONV :SCARDHANDLE, :DWORD
    SCardBeginTransaction proto WIN_STD_CALL_CONV :SCARDHANDLE
    SCardEndTransaction proto WIN_STD_CALL_CONV :SCARDHANDLE, :DWORD
    SCardCancelTransaction proto WIN_STD_CALL_CONV :SCARDHANDLE
    ; NOTE:    This call corresponds to the PC/SC SCARDCOMM::Cancel routine,
    ;          terminating a blocked SCardBeginTransaction service.
    SCardState proto WIN_STD_CALL_CONV :SCARDHANDLE, :LPDWORD, :LPDWORD, :LPBYTE, :LPDWORD
    ; NOTE:    SCardState is an obsolete routine.  PC/SC has replaced it with
    ;          SCardStatus.
    SCardStatusA proto WIN_STD_CALL_CONV :SCARDHANDLE, :LPSTR, :LPDWORD, :LPDWORD, :LPDWORD, :LPBYTE, :LPDWORD
    SCardStatusW proto WIN_STD_CALL_CONV :SCARDHANDLE, :LPWSTR, :LPDWORD, :LPDWORD, :LPDWORD, :LPBYTE, :LPDWORD
    ifdef UNICODE
      SCardStatus equ <SCardStatusW>
    else
      SCardStatus equ <SCardStatusA>
    endif
    ; !UNICODE
    SCardTransmit proto WIN_STD_CALL_CONV :SCARDHANDLE, :LPCSCARD_IO_REQUEST, :LPCBYTE, :DWORD, :LPSCARD_IO_REQUEST, :LPBYTE, :LPDWORD
    if (NTDDI_VERSION ge NTDDI_VISTA)
      SCardGetTransmitCount proto WIN_STD_CALL_CONV :SCARDHANDLE, :LPDWORD
    endif
    ; (NTDDI_VERSION >= NTDDI_VISTA)
    ;//////////////////////////////////////////////////////////////////////////////
    ;  Reader Control Routines
    ;      The following services provide for direct, low-level manipulation of the
    ;      reader by the calling application allowing it control over the
    ;      attributes of the communications with the card.
    SCardControl proto WIN_STD_CALL_CONV :SCARDHANDLE, :DWORD, :LPCVOID, :DWORD, :LPVOID, :DWORD, :LPDWORD
    SCardGetAttrib proto WIN_STD_CALL_CONV :SCARDHANDLE, :DWORD, :LPBYTE, :LPDWORD
    ; NOTE:    The routine SCardGetAttrib's name differs from the PC/SC definition.
    ;          It should be:
    ;              extern WINSCARDAPI LONG WINAPI
    ;              SCardGetReaderCapabilities(
    ;                  _In_    SCARDHANDLE hCard,
    ;                  _In_    DWORD dwTag,
    ;                  _Out_   LPBYTE pbAttr,
    ;                  _Inout_ LPDWORD pcbAttrLen);
    ;          Here's a work-around MACRO:
    SCardGetReaderCapabilities equ <SCardGetAttrib>
    SCardSetAttrib proto WIN_STD_CALL_CONV :SCARDHANDLE, :DWORD, :LPCBYTE, :DWORD
    ; NOTE:    The routine SCardSetAttrib's name differs from the PC/SC definition.
    ;          It should be:
    ;              extern WINSCARDAPI LONG WINAPI
    ;              SCardSetReaderCapabilities(
    ;                  _In_    SCARDHANDLE hCard,
    ;                  _In_    DWORD dwTag,
    ;                  _In_    LPCBYTE pbAttr,
    ;                  _In_    DWORD cbAttrLen);
    ;          Here's a work-around MACRO:
    SCardSetReaderCapabilities equ <SCardSetAttrib>
    ;//////////////////////////////////////////////////////////////////////////////
    ;  Smart Card Dialog definitions
    ;      The following section contains structures and  exported function
    ;      declarations for the Smart Card Common Dialog dialog.
    ; Defined constants
    ; Flags
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
    ; !UNICODE
    TYPE_LPOCNCHKPROC typedef proto WIN_STD_CALL_CONV :SCARDCONTEXT, :SCARDHANDLE, :PVOID
    LPOCNCHKPROC typedef ptr TYPE_LPOCNCHKPROC

    TYPE_LPOCNDSCPROC typedef proto WIN_STD_CALL_CONV :SCARDCONTEXT, :SCARDHANDLE, :PVOID
    LPOCNDSCPROC typedef ptr TYPE_LPOCNDSCPROC

    ; OPENCARD_SEARCH_CRITERIA: In order to specify a user-extended search,
    ; lpfnCheck must not be NULL.  Moreover, the connection to be made to the
    ; card before performing the callback must be indicated by either providing
    ; lpfnConnect and lpfnDisconnect OR by setting dwShareMode.
    ; If both the connection callbacks and dwShareMode are non-NULL, the callbacks
    ; will be used.
    OPENCARD_SEARCH_CRITERIAA struct
      dwStructSize DWORD ?
      lpstrGroupNames POINTER ?
      ; OPTIONAL reader groups to include in
      nMaxGroupNames DWORD ?
      ;          search.  NULL defaults to
      ;          SCard$DefaultReaders
      rgguidInterfaces LPCGUID ?
      ; OPTIONAL requested interfaces
      cguidInterfaces DWORD ?
      ;          supported by card's SSP
      lpstrCardNames POINTER ?
      ; OPTIONAL requested card names; all cards w/
      nMaxCardNames DWORD ?
      ;          matching ATRs will be accepted
      lpfnCheck LPOCNCHKPROC ?
      ; OPTIONAL if NULL no user check will be performed.
      lpfnConnect LPOCNCONNPROCA ?
      ; OPTIONAL if lpfnConnect is provided,
      lpfnDisconnect LPOCNDSCPROC ?
      ;          lpfnDisconnect must also be set.
      pvUserData POINTER ?
      ; OPTIONAL parameter to callbacks
      dwShareMode DWORD ?
      ; OPTIONAL must be set if lpfnCheck is not null
      dwPreferredProtocols DWORD ?
      ; OPTIONAL
    OPENCARD_SEARCH_CRITERIAA ends
    POPENCARD_SEARCH_CRITERIAA typedef ptr OPENCARD_SEARCH_CRITERIAA
    LPOPENCARD_SEARCH_CRITERIAA typedef ptr OPENCARD_SEARCH_CRITERIAA
    OPENCARD_SEARCH_CRITERIAW struct
      dwStructSize DWORD ?
      lpstrGroupNames POINTER ?
      ; OPTIONAL reader groups to include in
      nMaxGroupNames DWORD ?
      ;          search.  NULL defaults to
      ;          SCard$DefaultReaders
      rgguidInterfaces LPCGUID ?
      ; OPTIONAL requested interfaces
      cguidInterfaces DWORD ?
      ;          supported by card's SSP
      lpstrCardNames POINTER ?
      ; OPTIONAL requested card names; all cards w/
      nMaxCardNames DWORD ?
      ;          matching ATRs will be accepted
      lpfnCheck LPOCNCHKPROC ?
      ; OPTIONAL if NULL no user check will be performed.
      lpfnConnect LPOCNCONNPROCW ?
      ; OPTIONAL if lpfnConnect is provided,
      lpfnDisconnect LPOCNDSCPROC ?
      ;          lpfnDisconnect must also be set.
      pvUserData POINTER ?
      ; OPTIONAL parameter to callbacks
      dwShareMode DWORD ?
      ; OPTIONAL must be set if lpfnCheck is not null
      dwPreferredProtocols DWORD ?
      ; OPTIONAL
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
    ; UNICODE
    ; OPENCARDNAME_EX: used by SCardUIDlgSelectCard; replaces obsolete OPENCARDNAME
    OPENCARDNAME_EXA struct
      dwStructSize DWORD ?
      ; REQUIRED
      hSCardContext SCARDCONTEXT ?
      ; REQUIRED
      hwndOwner HWND ?
      ; OPTIONAL
      dwFlags DWORD ?
      ; OPTIONAL -- default is SC_DLG_MINIMAL_UI
      lpstrTitle =POINTER ?
      ; OPTIONAL
      lpstrSearchDesc =POINTER ?
      ; OPTIONAL (eg. "Please insert your <brandname> smart card.")
      hIcon HICON ?
      ; OPTIONAL 32x32 icon for your brand insignia
      pOpenCardSearchCriteria POPENCARD_SEARCH_CRITERIAA ?
      ; OPTIONAL
      lpfnConnect LPOCNCONNPROCA ?
      ; OPTIONAL - performed on successful selection
      pvUserData POINTER ?
      ; OPTIONAL parameter to lpfnConnect
      dwShareMode DWORD ?
      ; OPTIONAL - if lpfnConnect is NULL, dwShareMode and
      dwPreferredProtocols DWORD ?
      ; OPTIONAL dwPreferredProtocols will be used to
      ;          connect to the selected card
      lpstrRdr POINTER ?
      ; REQUIRED [IN|OUT] Name of selected reader
      nMaxRdr DWORD ?
      ; REQUIRED [IN|OUT]
      lpstrCard POINTER ?
      ; REQUIRED [IN|OUT] Name of selected card
      nMaxCard DWORD ?
      ; REQUIRED [IN|OUT]
      dwActiveProtocol DWORD ?
      ; [OUT] set only if dwShareMode not NULL
      hCardHandle SCARDHANDLE ?
      ; [OUT] set if a card connection was indicated
    OPENCARDNAME_EXA ends
    POPENCARDNAME_EXA typedef ptr OPENCARDNAME_EXA
    LPOPENCARDNAME_EXA typedef ptr OPENCARDNAME_EXA
    OPENCARDNAME_EXW struct
      dwStructSize DWORD ?
      ; REQUIRED
      hSCardContext SCARDCONTEXT ?
      ; REQUIRED
      hwndOwner HWND ?
      ; OPTIONAL
      dwFlags DWORD ?
      ; OPTIONAL -- default is SC_DLG_MINIMAL_UI
      lpstrTitle =POINTER ?
      ; OPTIONAL
      lpstrSearchDesc =POINTER ?
      ; OPTIONAL (eg. "Please insert your <brandname> smart card.")
      hIcon HICON ?
      ; OPTIONAL 32x32 icon for your brand insignia
      pOpenCardSearchCriteria POPENCARD_SEARCH_CRITERIAW ?
      ; OPTIONAL
      lpfnConnect LPOCNCONNPROCW ?
      ; OPTIONAL - performed on successful selection
      pvUserData POINTER ?
      ; OPTIONAL parameter to lpfnConnect
      dwShareMode DWORD ?
      ; OPTIONAL - if lpfnConnect is NULL, dwShareMode and
      dwPreferredProtocols DWORD ?
      ; OPTIONAL dwPreferredProtocols will be used to
      ;          connect to the selected card
      lpstrRdr POINTER ?
      ; REQUIRED [IN|OUT] Name of selected reader
      nMaxRdr DWORD ?
      ; REQUIRED [IN|OUT]
      lpstrCard POINTER ?
      ; REQUIRED [IN|OUT] Name of selected card
      nMaxCard DWORD ?
      ; REQUIRED [IN|OUT]
      dwActiveProtocol DWORD ?
      ; [OUT] set only if dwShareMode not NULL
      hCardHandle SCARDHANDLE ?
      ; [OUT] set if a card connection was indicated
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
    ; UNICODE
    OPENCARDNAMEA_EX equ <OPENCARDNAME_EXA>
    OPENCARDNAMEW_EX equ <OPENCARDNAME_EXW>
    POPENCARDNAMEA_EX equ <POPENCARDNAME_EXA>
    POPENCARDNAMEW_EX equ <POPENCARDNAME_EXW>
    LPOPENCARDNAMEA_EX equ <LPOPENCARDNAME_EXA>
    LPOPENCARDNAMEW_EX equ <LPOPENCARDNAME_EXW>
    ; Smart Card Reader Selection Provider
    ; Only UNICODE is supported. Invoke smart card reader selection provider by calling
    ; CredUIPromptForWindowsCredentials() supplying SCARD_READER_SEL_AUTH_PACKAGE as
    ; pulAuthPackage, an instance of READER_SEL_REQUEST as pvInAuthBuffer and setting
    ; CREDUIWIN_AUTHPACKAGE_ONLY in dwFlags. Upon successful return, an instance of
    ; READER_SEL_RESPONSE will be returned in ppvOutAuthBuffer.
    SCARD_READER_SEL_AUTH_PACKAGE equ (- 629)
    ; READER_SEL_REQUEST
    ;     Reader selection request to reader selection provider
    ; Members:
    ; dwShareMode:
    ;     Share mode used by SCardConnect to connect to smart cards
    ; dwPreferredProtocols:
    ;     Acceptable protocols for SCardConnect to connect to smart cards
    ; MatchType:
    ;     Indicates how the caller wants the reader selection provider to verify smart
    ;     cards.
    ;     If MatchType is set to RSR_MATCH_TYPE_READER_AND_CONTAINER, reader selection
    ;     provider will match smart cards based on whether they are in the given
    ;     reader and have the given key container. Reader name and container name are
    ;     both optional. Reader name and container name, if any, need to be appended
    ;     after READER_SEL_REQUEST structure and set their offsets and lengths in
    ;     ReaderAndContainerParameter member.
    ;     If MatchType is set to RSR_MATCH_TYPE_SERIAL_NUMBER, reader selection
    ;     provider will match smart cards based on their serial numbers / card IDs.
    ;     Serial number is required. It needs to be appended after READER_SEL_REQUEST
    ;     structure as a byte array and set its offset and length in
    ;     SerialNumberParameter member.
    ;     If MatchType is set to RSR_MATCH_TYPE_ALL_CARDS, reader selection provider
    ;     will allow all recognized cards to be selected by user without any filtering.
    ;     The card may not be personalized for Base CSP / Smart Card KSP yet, or even
    ;     have its own CSP.
    ; ReaderAndContainerParameter.cbReaderNameOffset:
    ;     Byte offset of reader name UNICODE string from the beginning of
    ;     READER_SEL_REQUEST structure
    ; ReaderAndContainerParameter.cchReaderNameLength:
    ;     Number of characters in reader name UNICODE string including the terminating
    ;     NULL character
    ; ReaderAndContainerParameter.cbContainerNameOffset:
    ;     Byte offset of container name UNICODE string from the beginning of
    ;     READER_SEL_REQUEST structure
    ; ReaderAndContainerParameter.cchContainerNameLength:
    ;     Number of characters in container name UNICODE string including the
    ;     terminating NULL character
    ; ReaderAndContainerParameter.dwDesiredCardModuleVersion:
    ;     The desired smart card module version
    ; ReaderAndContainerParameter.dwCspFlags:
    ;     CSP and KSP flags to indicate how smart cards will be used
    ;     (Valid flags include CRYPT_NEWKEYSET, CRYPT_DELETEKEYSET, CRYPT_VERIFYCONTEXT
    ;     and CRYPT_DEFAULT_CONTAINER_OPTIONAL)
    ; SerialNumberParameter.cbSerialNumberOffset:
    ;     Byte offset of serial number byte array from the beginning of
    ;     READER_SEL_REQUEST structure
    ; SerialNumberParameter.cbSerialNumberLength:
    ;     Number of bytes in serial number byte array
    ; SerialNumberParameter.dwDesiredCardModuleVersion:
    ;     The desired smart card module version
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
    ; READER_SEL_RESPONSE
    ;     Reader selection response from reader selection provider
    ; Members:
    ; cbReaderNameOffset:
    ;     Byte offset of matched reader name UNICODE string from the beginning of
    ;     READER_SEL_RESPONSE structure
    ; cchReaderNameLength:
    ;     Number of characters in matched reader name UNICODE string including the
    ;     terminating NULL character
    ; cbCardNameOffset:
    ;     Byte offset of matched card name UNICODE string from the beginning of
    ;     READER_SEL_RESPONSE structure
    ; cchCardNameLength:
    ;     Number of characters in matched card name UNICODE string including the
    ;     terminating NULL character
    READER_SEL_RESPONSE struct
      cbReaderNameOffset DWORD ?
      cchReaderNameLength DWORD ?
      cbCardNameOffset DWORD ?
      cchCardNameLength DWORD ?
    READER_SEL_RESPONSE ends
    PREADER_SEL_RESPONSE typedef ptr READER_SEL_RESPONSE
    ; SCardUIDlgSelectCard replaces GetOpenCardName
    SCardUIDlgSelectCardA proto WIN_STD_CALL_CONV :LPOPENCARDNAMEA_EX
    SCardUIDlgSelectCardW proto WIN_STD_CALL_CONV :LPOPENCARDNAMEW_EX
    ifdef UNICODE
      SCardUIDlgSelectCard equ <SCardUIDlgSelectCardW>
    else
      SCardUIDlgSelectCard equ <SCardUIDlgSelectCardA>
    endif
    ; !UNICODE
    ; "Smart Card Common Dialog" definitions for backwards compatibility
    ;  with the Smart Card Base Services SDK version 1.0
    OPENCARDNAMEA struct
      dwStructSize DWORD ?
      hwndOwner HWND ?
      hSCardContext SCARDCONTEXT ?
      lpstrGroupNames POINTER ?
      nMaxGroupNames DWORD ?
      lpstrCardNames POINTER ?
      nMaxCardNames DWORD ?
      rgguidInterfaces LPCGUID ?
      cguidInterfaces DWORD ?
      lpstrRdr POINTER ?
      nMaxRdr DWORD ?
      lpstrCard POINTER ?
      nMaxCard DWORD ?
      lpstrTitle =POINTER ?
      dwFlags DWORD ?
      pvUserData POINTER ?
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
      lpstrGroupNames POINTER ?
      nMaxGroupNames DWORD ?
      lpstrCardNames POINTER ?
      nMaxCardNames DWORD ?
      rgguidInterfaces LPCGUID ?
      cguidInterfaces DWORD ?
      lpstrRdr POINTER ?
      nMaxRdr DWORD ?
      lpstrCard POINTER ?
      nMaxCard DWORD ?
      lpstrTitle =POINTER ?
      dwFlags DWORD ?
      pvUserData POINTER ?
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
    ; UNICODE
    ; Backwards compatibility macros
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
    ; !UNICODE
    SCardDlgExtendedError proto WIN_STD_CALL_CONV
    if (NTDDI_VERSION ge NTDDI_VISTA)
      ; Smartcard Caching API
      SCardReadCacheA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :ptr UUID, :DWORD, :LPSTR, :PBYTE, :ptr DWORD
      SCardReadCacheW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :ptr UUID, :DWORD, :LPWSTR, :PBYTE, :ptr DWORD
      ifdef UNICODE
        SCardReadCache equ <SCardReadCacheW>
      else
        SCardReadCache equ <SCardReadCacheA>
      endif
      ; !UNICODE
      SCardWriteCacheA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :ptr UUID, :DWORD, :LPSTR, :PBYTE, :DWORD
      SCardWriteCacheW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :ptr UUID, :DWORD, :LPWSTR, :PBYTE, :DWORD
      ifdef UNICODE
        SCardWriteCache equ <SCardWriteCacheW>
      else
        SCardWriteCache equ <SCardWriteCacheA>
      endif
      ; !UNICODE
    endif
    ; (NTDDI_VERSION >= NTDDI_VISTA)
    if (NTDDI_VERSION ge NTDDI_WIN8)
      SCardGetReaderIconA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR, :LPBYTE, :LPDWORD
      SCardGetReaderIconW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR, :LPBYTE, :LPDWORD
      ifdef UNICODE
        SCardGetReaderIcon equ <SCardGetReaderIconW>
      else
        SCardGetReaderIcon equ <SCardGetReaderIconA>
      endif
      ; !UNICODE
      SCardGetDeviceTypeIdA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR, :LPDWORD
      SCardGetDeviceTypeIdW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR, :LPDWORD
      ifdef UNICODE
        SCardGetDeviceTypeId equ <SCardGetDeviceTypeIdW>
      else
        SCardGetDeviceTypeId equ <SCardGetDeviceTypeIdA>
      endif
      ; !UNICODE
      SCardGetReaderDeviceInstanceIdA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR, :LPSTR, :LPDWORD
      SCardGetReaderDeviceInstanceIdW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR, :LPWSTR, :LPDWORD
      ifdef UNICODE
        SCardGetReaderDeviceInstanceId equ <SCardGetReaderDeviceInstanceIdW>
      else
        SCardGetReaderDeviceInstanceId equ <SCardGetReaderDeviceInstanceIdA>
      endif
      ; !UNICODE
      SCardListReadersWithDeviceInstanceIdA proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCSTR, :LPSTR, :LPDWORD
      SCardListReadersWithDeviceInstanceIdW proto WIN_STD_CALL_CONV :SCARDCONTEXT, :LPCWSTR, :LPWSTR, :LPDWORD
      ifdef UNICODE
        SCardListReadersWithDeviceInstanceId equ <SCardListReadersWithDeviceInstanceIdW>
      else
        SCardListReadersWithDeviceInstanceId equ <SCardListReadersWithDeviceInstanceIdA>
      endif
      ; !UNICODE
      ;//////////////////////////////////////////////////////////////////////////////
      ;  Smart Card Auditing
      SCARD_AUDIT_CHV_FAILURE equ 0h; A smart card holder verification (CHV) 

      ; attempt failed.
      SCARD_AUDIT_CHV_SUCCESS equ 1h; A smart card holder verification (CHV)

      ; attempt succeeded.
      SCardAudit proto WIN_STD_CALL_CONV :SCARDCONTEXT, :DWORD
    endif
    ; (NTDDI_VERSION >= NTDDI_WIN8)
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  if _MSC_VER ge 1200
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
; _WINSCARD_H_
