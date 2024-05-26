;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\ddeml.h
;             Created on (UTC) 06/04/2024 06:15:53
;             Last modified on (UTC) 21/02/2024 18:18:22

include winapifamily.inc
ifndef _INC_DDEMLH
  _INC_DDEMLH equ <>
  if _MSC_VER ge 1200
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    DECLARE_HANDLE HCONVLIST
    DECLARE_HANDLE HCONV
    DECLARE_HANDLE HSZ
    DECLARE_HANDLE HDDEDATA
    EXPENTRY equ <CALLBACK>
    HSZPAIR struct
      hszSvc HSZ ?
      hszTopic HSZ ?
    HSZPAIR ends
    tagHSZPAIR typedef HSZPAIR
    PHSZPAIR typedef ptr HSZPAIR
    CONVCONTEXT struct
      cb UINT ?
      wFlags UINT ?
      wCountryID UINT ?
      iCodePage SDWORD ?
      dwLangID DWORD ?
      dwSecurity DWORD ?
      qos SECURITY_QUALITY_OF_SERVICE <>
    CONVCONTEXT ends
    tagCONVCONTEXT typedef CONVCONTEXT
    PCONVCONTEXT typedef ptr CONVCONTEXT
    CONVINFO struct
      cb DWORD ?
      hUser DWORD_PTR ?
      hConvPartner HCONV ?
      hszSvcPartner HSZ ?
      hszServiceReq HSZ ?
      hszTopic HSZ ?
      hszItem HSZ ?
      wFmt UINT ?
      wType UINT ?
      wStatus UINT ?
      wConvst UINT ?
      wLastError UINT ?
      hConvList HCONVLIST ?
      ConvCtxt CONVCONTEXT <>
      hwnd HWND ?
      hwndPartner HWND ?
    CONVINFO ends
    tagCONVINFO typedef CONVINFO
    PCONVINFO typedef ptr CONVINFO
    XST_NULL equ 0
    XST_INCOMPLETE equ 1
    XST_CONNECTED equ 2
    XST_INIT1 equ 3
    XST_INIT2 equ 4
    XST_REQSENT equ 5
    XST_DATARCVD equ 6
    XST_POKESENT equ 7
    XST_POKEACKRCVD equ 8
    XST_EXECSENT equ 9
    XST_EXECACKRCVD equ 10
    XST_ADVSENT equ 11
    XST_UNADVSENT equ 12
    XST_ADVACKRCVD equ 13
    XST_UNADVACKRCVD equ 14
    XST_ADVDATASENT equ 15
    XST_ADVDATAACKRCVD equ 16
    CADV_LATEACK equ 0FFFFh
    ST_CONNECTED equ 0001h
    ST_ADVISE equ 0002h
    ST_ISLOCAL equ 0004h
    ST_BLOCKED equ 0008h
    ST_CLIENT equ 0010h
    ST_TERMINATED equ 0020h
    ST_INLIST equ 0040h
    ST_BLOCKNEXT equ 0080h
    ST_ISSELF equ 0100h
    DDE_FACK equ 8000h
    DDE_FBUSY equ 4000h
    DDE_FDEFERUPD equ 4000h
    DDE_FACKREQ equ 8000h
    DDE_FRELEASE equ 2000h
    DDE_FREQUESTED equ 1000h
    DDE_FAPPSTATUS equ 00ffh
    DDE_FNOTPROCESSED equ 0000h
    DDE_FACKRESERVED equ <(not (DDE_FACK or DDE_FBUSY or DDE_FAPPSTATUS))>
    DDE_FADVRESERVED equ <(not (DDE_FACKREQ or DDE_FDEFERUPD))>
    DDE_FDATRESERVED equ <(not (DDE_FACKREQ or DDE_FRELEASE or DDE_FREQUESTED))>
    DDE_FPOKRESERVED equ <(not (DDE_FRELEASE))>
    MSGF_DDEMGR equ 8001h
    CP_WINANSI equ 1004
    CP_WINUNICODE equ 1200
    ifdef UNICODE
      CP_WINNEUTRAL equ <CP_WINUNICODE>
    else
      CP_WINNEUTRAL equ <CP_WINANSI>
    endif
    XTYPF_NOBLOCK equ 0002h
    XTYPF_NODATA equ 0004h
    XTYPF_ACKREQ equ 0008h
    XCLASS_MASK equ 0FC00h
    XCLASS_BOOL equ 1000h
    XCLASS_DATA equ 2000h
    XCLASS_FLAGS equ 4000h
    XCLASS_NOTIFICATION equ 8000h
    XTYP_ERROR equ (0000h or XCLASS_NOTIFICATION or XTYPF_NOBLOCK)
    XTYP_ADVDATA equ (0010h or XCLASS_FLAGS)
    XTYP_ADVREQ equ (0020h or XCLASS_DATA or XTYPF_NOBLOCK)
    XTYP_ADVSTART equ (0030h or XCLASS_BOOL)
    XTYP_ADVSTOP equ (0040h or XCLASS_NOTIFICATION)
    XTYP_EXECUTE equ (0050h or XCLASS_FLAGS)
    XTYP_CONNECT equ (0060h or XCLASS_BOOL or XTYPF_NOBLOCK)
    XTYP_CONNECT_CONFIRM equ (0070h or XCLASS_NOTIFICATION or XTYPF_NOBLOCK)
    XTYP_XACT_COMPLETE equ (0080h or XCLASS_NOTIFICATION)
    XTYP_POKE equ (0090h or XCLASS_FLAGS)
    XTYP_REGISTER equ (00A0h or XCLASS_NOTIFICATION or XTYPF_NOBLOCK)
    XTYP_REQUEST equ (00B0h or XCLASS_DATA)
    XTYP_DISCONNECT equ (00C0h or XCLASS_NOTIFICATION or XTYPF_NOBLOCK)
    XTYP_UNREGISTER equ (00D0h or XCLASS_NOTIFICATION or XTYPF_NOBLOCK)
    XTYP_WILDCONNECT equ (00E0h or XCLASS_DATA or XTYPF_NOBLOCK)
    XTYP_MASK equ 00F0h
    XTYP_SHIFT equ 4
    TIMEOUT_ASYNC equ 0FFFFFFFFh
    QID_SYNC equ 0FFFFFFFFh
    ifdef UNICODE
      SZDDESYS_TOPIC equ <L("System")>
      SZDDESYS_ITEM_TOPICS equ <L("Topics")>
      SZDDESYS_ITEM_SYSITEMS equ <L("SysItems")>
      SZDDESYS_ITEM_RTNMSG equ <L("ReturnMessage")>
      SZDDESYS_ITEM_STATUS equ <L("Status")>
      SZDDESYS_ITEM_FORMATS equ <L("Formats")>
      SZDDESYS_ITEM_HELP equ <L("Help")>
      SZDDE_ITEM_ITEMLIST equ <L("TopicItemList")>
    else
      SZDDESYS_TOPIC equ <"System">
      SZDDESYS_ITEM_TOPICS equ <"Topics">
      SZDDESYS_ITEM_SYSITEMS equ <"SysItems">
      SZDDESYS_ITEM_RTNMSG equ <"ReturnMessage">
      SZDDESYS_ITEM_STATUS equ <"Status">
      SZDDESYS_ITEM_FORMATS equ <"Formats">
      SZDDESYS_ITEM_HELP equ <"Help">
      SZDDE_ITEM_ITEMLIST equ <"TopicItemList">
    endif
    FNCALLBACK typedef proto :UINT, :UINT, :HCONV, :HSZ, :HSZ, :HDDEDATA, :ULONG_PTR, :ULONG_PTR
    TYPE_PFNCALLBACK typedef proto WIN_STD_CALL_CONV :UINT, :UINT, :HCONV, :HSZ, :HSZ, :HDDEDATA, :ULONG_PTR, :ULONG_PTR
    PFNCALLBACK typedef ptr TYPE_PFNCALLBACK

    CBR_BLOCK equ ((HDDEDATA) - 1)
    DdeInitializeA proto WIN_STD_CALL_CONV :LPDWORD, :PFNCALLBACK, :DWORD, :DWORD
    DdeInitializeW proto WIN_STD_CALL_CONV :LPDWORD, :PFNCALLBACK, :DWORD, :DWORD
    ifdef UNICODE
      DdeInitialize equ <DdeInitializeW>
    else
      DdeInitialize equ <DdeInitializeA>
    endif
    CBF_FAIL_SELFCONNECTIONS equ 00001000h
    CBF_FAIL_CONNECTIONS equ 00002000h
    CBF_FAIL_ADVISES equ 00004000h
    CBF_FAIL_EXECUTES equ 00008000h
    CBF_FAIL_POKES equ 00010000h
    CBF_FAIL_REQUESTS equ 00020000h
    CBF_FAIL_ALLSVRXACTIONS equ 0003f000h
    CBF_SKIP_CONNECT_CONFIRMS equ 00040000h
    CBF_SKIP_REGISTRATIONS equ 00080000h
    CBF_SKIP_UNREGISTRATIONS equ 00100000h
    CBF_SKIP_DISCONNECTS equ 00200000h
    CBF_SKIP_ALLNOTIFICATIONS equ 003c0000h
    APPCMD_CLIENTONLY equ 00000010h
    APPCMD_FILTERINITS equ 00000020h
    APPCMD_MASK equ 00000FF0h
    APPCLASS_STANDARD equ 00000000h
    APPCLASS_MASK equ 0000000Fh
    DdeUninitialize proto WIN_STD_CALL_CONV :DWORD
    DdeConnectList proto WIN_STD_CALL_CONV :DWORD, :HSZ, :HSZ, :HCONVLIST, :PCONVCONTEXT
    DdeQueryNextServer proto WIN_STD_CALL_CONV :HCONVLIST, :HCONV
    DdeDisconnectList proto WIN_STD_CALL_CONV :HCONVLIST
    DdeConnect proto WIN_STD_CALL_CONV :DWORD, :HSZ, :HSZ, :PCONVCONTEXT
    DdeDisconnect proto WIN_STD_CALL_CONV :HCONV
    DdeReconnect proto WIN_STD_CALL_CONV :HCONV
    DdeQueryConvInfo proto WIN_STD_CALL_CONV :HCONV, :DWORD, :PCONVINFO
    DdeSetUserHandle proto WIN_STD_CALL_CONV :HCONV, :DWORD, :DWORD_PTR
    DdeAbandonTransaction proto WIN_STD_CALL_CONV :DWORD, :HCONV, :DWORD
    DdePostAdvise proto WIN_STD_CALL_CONV :DWORD, :HSZ, :HSZ
    DdeEnableCallback proto WIN_STD_CALL_CONV :DWORD, :HCONV, :UINT
    DdeImpersonateClient proto WIN_STD_CALL_CONV :HCONV
    EC_ENABLEALL equ 0
    EC_ENABLEONE equ <ST_BLOCKNEXT>
    EC_DISABLE equ <ST_BLOCKED>
    EC_QUERYWAITING equ 2
    DdeNameService proto WIN_STD_CALL_CONV :DWORD, :HSZ, :HSZ, :UINT
    DNS_REGISTER equ 0001h
    DNS_UNREGISTER equ 0002h
    DNS_FILTERON equ 0004h
    DNS_FILTEROFF equ 0008h
    DdeClientTransaction proto WIN_STD_CALL_CONV :LPBYTE, :DWORD, :HCONV, :HSZ, :UINT, :UINT, :DWORD, :LPDWORD
    DdeCreateDataHandle proto WIN_STD_CALL_CONV :DWORD, :LPBYTE, :DWORD, :DWORD, :HSZ, :UINT, :UINT
    DdeAddData proto WIN_STD_CALL_CONV :HDDEDATA, :LPBYTE, :DWORD, :DWORD
    DdeGetData proto WIN_STD_CALL_CONV :HDDEDATA, :LPBYTE, :DWORD, :DWORD
    DdeAccessData proto WIN_STD_CALL_CONV :HDDEDATA, :LPDWORD
    DdeUnaccessData proto WIN_STD_CALL_CONV :HDDEDATA
    DdeFreeDataHandle proto WIN_STD_CALL_CONV :HDDEDATA
    HDATA_APPOWNED equ 0001h
    DdeGetLastError proto WIN_STD_CALL_CONV :DWORD
    DMLERR_NO_ERROR equ 0
    DMLERR_FIRST equ 4000h
    DMLERR_ADVACKTIMEOUT equ 4000h
    DMLERR_BUSY equ 4001h
    DMLERR_DATAACKTIMEOUT equ 4002h
    DMLERR_DLL_NOT_INITIALIZED equ 4003h
    DMLERR_DLL_USAGE equ 4004h
    DMLERR_EXECACKTIMEOUT equ 4005h
    DMLERR_INVALIDPARAMETER equ 4006h
    DMLERR_LOW_MEMORY equ 4007h
    DMLERR_MEMORY_ERROR equ 4008h
    DMLERR_NOTPROCESSED equ 4009h
    DMLERR_NO_CONV_ESTABLISHED equ 400ah
    DMLERR_POKEACKTIMEOUT equ 400bh
    DMLERR_POSTMSG_FAILED equ 400ch
    DMLERR_REENTRANCY equ 400dh
    DMLERR_SERVER_DIED equ 400eh
    DMLERR_SYS_ERROR equ 400fh
    DMLERR_UNADVACKTIMEOUT equ 4010h
    DMLERR_UNFOUND_QUEUE_ID equ 4011h
    DMLERR_LAST equ 4011h
    DdeCreateStringHandleA proto WIN_STD_CALL_CONV :DWORD, :LPCSTR, :SDWORD
    DdeCreateStringHandleW proto WIN_STD_CALL_CONV :DWORD, :LPCWSTR, :SDWORD
    ifdef UNICODE
      DdeCreateStringHandle equ <DdeCreateStringHandleW>
    else
      DdeCreateStringHandle equ <DdeCreateStringHandleA>
    endif
    DdeQueryStringA proto WIN_STD_CALL_CONV :DWORD, :HSZ, :LPSTR, :DWORD, :SDWORD
    DdeQueryStringW proto WIN_STD_CALL_CONV :DWORD, :HSZ, :LPWSTR, :DWORD, :SDWORD
    ifdef UNICODE
      DdeQueryString equ <DdeQueryStringW>
    else
      DdeQueryString equ <DdeQueryStringA>
    endif
    DdeFreeStringHandle proto WIN_STD_CALL_CONV :DWORD, :HSZ
    DdeKeepStringHandle proto WIN_STD_CALL_CONV :DWORD, :HSZ
    DdeCmpStringHandles proto WIN_STD_CALL_CONV :HSZ, :HSZ
    ifndef NODDEMLSPY
      DDEML_MSG_HOOK_DATA struct
        uiLo UINT_PTR ?
        uiHi UINT_PTR ?
        cbData DWORD ?
        Data DWORD 8 dup (?)
      DDEML_MSG_HOOK_DATA ends
      tagDDEML_MSG_HOOK_DATA typedef DDEML_MSG_HOOK_DATA
      PDDEML_MSG_HOOK_DATA typedef ptr DDEML_MSG_HOOK_DATA
      MONMSGSTRUCT struct
        cb UINT ?
        hwndTo HWND ?
        dwTime DWORD ?
        hTask HANDLE ?
        wMsg UINT ?
        wParam WPARAM ?
        lParam LPARAM ?
        dmhd DDEML_MSG_HOOK_DATA <>
      MONMSGSTRUCT ends
      tagMONMSGSTRUCT typedef MONMSGSTRUCT
      PMONMSGSTRUCT typedef ptr MONMSGSTRUCT
      MONCBSTRUCT struct
        cb UINT ?
        dwTime DWORD ?
        hTask HANDLE ?
        dwRet DWORD ?
        wType UINT ?
        wFmt UINT ?
        hConv HCONV ?
        hsz1 HSZ ?
        hsz2 HSZ ?
        hData HDDEDATA ?
        dwData1 ULONG_PTR ?
        dwData2 ULONG_PTR ?
        cc CONVCONTEXT <>
        cbData DWORD ?
        Data DWORD 8 dup (?)
      MONCBSTRUCT ends
      tagMONCBSTRUCT typedef MONCBSTRUCT
      PMONCBSTRUCT typedef ptr MONCBSTRUCT
      MONHSZSTRUCTA struct
        cb UINT ?
        fsAction BOOL ?
        dwTime DWORD ?
        hsz HSZ ?
        hTask HANDLE ?
        str_ CHAR 1 dup (?)
      MONHSZSTRUCTA ends
      tagMONHSZSTRUCTA typedef MONHSZSTRUCTA
      PMONHSZSTRUCTA typedef ptr MONHSZSTRUCTA
      MONHSZSTRUCTW struct
        cb UINT ?
        fsAction BOOL ?
        dwTime DWORD ?
        hsz HSZ ?
        hTask HANDLE ?
        str_ WCHAR 1 dup (?)
      MONHSZSTRUCTW ends
      tagMONHSZSTRUCTW typedef MONHSZSTRUCTW
      PMONHSZSTRUCTW typedef ptr MONHSZSTRUCTW
      ifdef UNICODE
        MONHSZSTRUCT typedef MONHSZSTRUCTW
        PMONHSZSTRUCT typedef PMONHSZSTRUCTW
      else
        MONHSZSTRUCT typedef MONHSZSTRUCTA
        PMONHSZSTRUCT typedef PMONHSZSTRUCTA
      endif
      MH_CREATE equ 1
      MH_KEEP equ 2
      MH_DELETE equ 3
      MH_CLEANUP equ 4
      MONERRSTRUCT struct
        cb UINT ?
        wLastError UINT ?
        dwTime DWORD ?
        hTask HANDLE ?
      MONERRSTRUCT ends
      tagMONERRSTRUCT typedef MONERRSTRUCT
      PMONERRSTRUCT typedef ptr MONERRSTRUCT
      MONLINKSTRUCT struct
        cb UINT ?
        dwTime DWORD ?
        hTask HANDLE ?
        fEstablished BOOL ?
        fNoData BOOL ?
        hszSvc HSZ ?
        hszTopic HSZ ?
        hszItem HSZ ?
        wFmt UINT ?
        fServer BOOL ?
        hConvServer HCONV ?
        hConvClient HCONV ?
      MONLINKSTRUCT ends
      tagMONLINKSTRUCT typedef MONLINKSTRUCT
      PMONLINKSTRUCT typedef ptr MONLINKSTRUCT
      MONCONVSTRUCT struct
        cb UINT ?
        fConnect BOOL ?
        dwTime DWORD ?
        hTask HANDLE ?
        hszSvc HSZ ?
        hszTopic HSZ ?
        hConvClient HCONV ?
        hConvServer HCONV ?
      MONCONVSTRUCT ends
      tagMONCONVSTRUCT typedef MONCONVSTRUCT
      PMONCONVSTRUCT typedef ptr MONCONVSTRUCT
      MAX_MONITORS equ 4
      APPCLASS_MONITOR equ 00000001h
      XTYP_MONITOR equ (00F0h or XCLASS_NOTIFICATION or XTYPF_NOBLOCK)
      MF_HSZ_INFO equ 01000000h
      MF_SENDMSGS equ 02000000h
      MF_POSTMSGS equ 04000000h
      MF_CALLBACKS equ 08000000h
      MF_ERRORS equ 10000000h
      MF_LINKS equ 20000000h
      MF_CONV equ 40000000h
      MF_MASK equ 0FF000000h
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if _MSC_VER ge 1200
  endif
endif
