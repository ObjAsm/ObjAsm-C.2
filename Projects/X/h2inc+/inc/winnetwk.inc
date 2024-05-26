;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\winnetwk.h
;             Created on (UTC) 06/04/2024 06:16:03
;             Last modified on (UTC) 21/02/2024 18:13:16

include winapifamily.inc
ifndef _WINNETWK_
  _WINNETWK_ equ <>
  ifdef __cplusplus
    ;[...]
  endif
  if _MSC_VER ge 1200
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    include wnnc.inc
    RESOURCE_CONNECTED equ 00000001h
    RESOURCE_GLOBALNET equ 00000002h
    RESOURCE_REMEMBERED equ 00000003h
    if (WINVER ge 0400h)
      RESOURCE_RECENT equ 00000004h
      RESOURCE_CONTEXT equ 00000005h
    endif
    RESOURCETYPE_ANY equ 00000000h
    RESOURCETYPE_DISK equ 00000001h
    RESOURCETYPE_PRINT equ 00000002h
    if (WINVER ge 0400h)
      RESOURCETYPE_RESERVED equ 00000008h
    endif
    RESOURCETYPE_UNKNOWN equ 0FFFFFFFFh
    RESOURCEUSAGE_CONNECTABLE equ 00000001h
    RESOURCEUSAGE_CONTAINER equ 00000002h
    if (WINVER ge 0400h)
      RESOURCEUSAGE_NOLOCALDEVICE equ 00000004h
      RESOURCEUSAGE_SIBLING equ 00000008h
      RESOURCEUSAGE_ATTACHED equ 00000010h
      RESOURCEUSAGE_ALL equ <(RESOURCEUSAGE_CONNECTABLE or RESOURCEUSAGE_CONTAINER or RESOURCEUSAGE_ATTACHED)>
    endif
    RESOURCEUSAGE_RESERVED equ 80000000h
    RESOURCEDISPLAYTYPE_GENERIC equ 00000000h
    RESOURCEDISPLAYTYPE_DOMAIN equ 00000001h
    RESOURCEDISPLAYTYPE_SERVER equ 00000002h
    RESOURCEDISPLAYTYPE_SHARE equ 00000003h
    RESOURCEDISPLAYTYPE_FILE equ 00000004h
    RESOURCEDISPLAYTYPE_GROUP equ 00000005h
    if (WINVER ge 0400h)
      RESOURCEDISPLAYTYPE_NETWORK equ 00000006h
      RESOURCEDISPLAYTYPE_ROOT equ 00000007h
      RESOURCEDISPLAYTYPE_SHAREADMIN equ 00000008h
      RESOURCEDISPLAYTYPE_DIRECTORY equ 00000009h
    endif
    RESOURCEDISPLAYTYPE_TREE equ 0000000Ah
    if (WINVER ge 0400h)
      RESOURCEDISPLAYTYPE_NDSCONTAINER equ 0000000Bh
    endif
    NETRESOURCEA struct
      dwScope DWORD ?
      dwType DWORD ?
      dwDisplayType DWORD ?
      dwUsage DWORD ?
      lpLocalName LPSTR ?
      lpRemoteName LPSTR ?
      lpComment LPSTR ?
      lpProvider LPSTR ?
    NETRESOURCEA ends
    _NETRESOURCEA typedef NETRESOURCEA
    LPNETRESOURCEA typedef ptr NETRESOURCEA
    NETRESOURCEW struct
      dwScope DWORD ?
      dwType DWORD ?
      dwDisplayType DWORD ?
      dwUsage DWORD ?
      lpLocalName LPWSTR ?
      lpRemoteName LPWSTR ?
      lpComment LPWSTR ?
      lpProvider LPWSTR ?
    NETRESOURCEW ends
    _NETRESOURCEW typedef NETRESOURCEW
    LPNETRESOURCEW typedef ptr NETRESOURCEW
    ifdef UNICODE
      NETRESOURCE typedef NETRESOURCEW
      LPNETRESOURCE typedef LPNETRESOURCEW
    else
      NETRESOURCE typedef NETRESOURCEA
      LPNETRESOURCE typedef LPNETRESOURCEA
    endif
    NETPROPERTY_PERSISTENT equ 1
    CONNECT_UPDATE_PROFILE equ 00000001h
    CONNECT_UPDATE_RECENT equ 00000002h
    CONNECT_TEMPORARY equ 00000004h
    CONNECT_INTERACTIVE equ 00000008h
    CONNECT_PROMPT equ 00000010h
    CONNECT_NEED_DRIVE equ 00000020h
    if (WINVER ge 0400h)
      CONNECT_REFCOUNT equ 00000040h
      CONNECT_REDIRECT equ 00000080h
      CONNECT_LOCALDRIVE equ 00000100h
      CONNECT_CURRENT_MEDIA equ 00000200h
      CONNECT_DEFERRED equ 00000400h
      CONNECT_RESERVED equ 0FF000000h
    endif
    if (WINVER ge 0500h)
      CONNECT_COMMANDLINE equ 00000800h
      CONNECT_CMD_SAVECRED equ 00001000h
    endif
    if (WINVER ge 0600h)
      CONNECT_CRED_RESET equ 00002000h
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN10)
      CONNECT_REQUIRE_INTEGRITY equ 00004000h
      CONNECT_REQUIRE_PRIVACY equ 00008000h
      CONNECT_WRITE_THROUGH_SEMANTICS equ 00010000h
      CONNECT_GLOBAL_MAPPING equ 00040000h
    endif
    WNetAddConnectionA proto WIN_STD_CALL_CONV :LPCSTR, :LPCSTR, :LPCSTR
    WNetAddConnectionW proto WIN_STD_CALL_CONV :LPCWSTR, :LPCWSTR, :LPCWSTR
    ifdef UNICODE
      WNetAddConnection equ <WNetAddConnectionW>
    else
      WNetAddConnection equ <WNetAddConnectionA>
    endif
    WNetAddConnection2A proto WIN_STD_CALL_CONV :LPNETRESOURCEA, :LPCSTR, :LPCSTR, :DWORD
    WNetAddConnection2W proto WIN_STD_CALL_CONV :LPNETRESOURCEW, :LPCWSTR, :LPCWSTR, :DWORD
    ifdef UNICODE
      WNetAddConnection2 equ <WNetAddConnection2W>
    else
      WNetAddConnection2 equ <WNetAddConnection2A>
    endif
    WNetAddConnection3A proto WIN_STD_CALL_CONV :HWND, :LPNETRESOURCEA, :LPCSTR, :LPCSTR, :DWORD
    WNetAddConnection3W proto WIN_STD_CALL_CONV :HWND, :LPNETRESOURCEW, :LPCWSTR, :LPCWSTR, :DWORD
    ifdef UNICODE
      WNetAddConnection3 equ <WNetAddConnection3W>
    else
      WNetAddConnection3 equ <WNetAddConnection3A>
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN10)
      WNetAddConnection4A proto WIN_STD_CALL_CONV :HWND, :LPNETRESOURCEA, :PVOID, :DWORD, :DWORD, :PBYTE, :DWORD
      WNetAddConnection4W proto WIN_STD_CALL_CONV :HWND, :LPNETRESOURCEW, :PVOID, :DWORD, :DWORD, :PBYTE, :DWORD
      ifdef UNICODE
        WNetAddConnection4 equ <WNetAddConnection4W>
      else
        WNetAddConnection4 equ <WNetAddConnection4A>
      endif
    endif
    WNetCancelConnectionA proto WIN_STD_CALL_CONV :LPCSTR, :BOOL
    WNetCancelConnectionW proto WIN_STD_CALL_CONV :LPCWSTR, :BOOL
    ifdef UNICODE
      WNetCancelConnection equ <WNetCancelConnectionW>
    else
      WNetCancelConnection equ <WNetCancelConnectionA>
    endif
    WNetCancelConnection2A proto WIN_STD_CALL_CONV :LPCSTR, :DWORD, :BOOL
    WNetCancelConnection2W proto WIN_STD_CALL_CONV :LPCWSTR, :DWORD, :BOOL
    ifdef UNICODE
      WNetCancelConnection2 equ <WNetCancelConnection2W>
    else
      WNetCancelConnection2 equ <WNetCancelConnection2A>
    endif
    WNetGetConnectionA proto WIN_STD_CALL_CONV :LPCSTR, :LPSTR, :LPDWORD
    WNetGetConnectionW proto WIN_STD_CALL_CONV :LPCWSTR, :LPWSTR, :LPDWORD
    ifdef UNICODE
      WNetGetConnection equ <WNetGetConnectionW>
    else
      WNetGetConnection equ <WNetGetConnectionA>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if (_WIN32_WINNT ge _WIN32_WINNT_LONGHORN)
      WNetRestoreSingleConnectionW proto WIN_STD_CALL_CONV :HWND, :LPCWSTR, :BOOL
    else
      WNetRestoreConnectionW proto WIN_STD_CALL_CONV :HWND, :LPCWSTR
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (WINVER ge 0400h)
      WNetUseConnectionA proto WIN_STD_CALL_CONV :HWND, :LPNETRESOURCEA, :LPCSTR, :LPCSTR, :DWORD, :LPSTR, :LPDWORD, :LPDWORD
      WNetUseConnectionW proto WIN_STD_CALL_CONV :HWND, :LPNETRESOURCEW, :LPCWSTR, :LPCWSTR, :DWORD, :LPWSTR, :LPDWORD, :LPDWORD
      ifdef UNICODE
        WNetUseConnection equ <WNetUseConnectionW>
      else
        WNetUseConnection equ <WNetUseConnectionA>
      endif
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN10)
      WNetUseConnection4A proto WIN_STD_CALL_CONV :HWND, :LPNETRESOURCEA, :PVOID, :DWORD, :DWORD, :PBYTE, :DWORD, :LPSTR, :LPDWORD, :LPDWORD
      WNetUseConnection4W proto WIN_STD_CALL_CONV :HWND, :LPNETRESOURCEW, :PVOID, :DWORD, :DWORD, :PBYTE, :DWORD, :LPWSTR, :LPDWORD, :LPDWORD
      ifdef UNICODE
        WNetUseConnection4 equ <WNetUseConnection4W>
      else
        WNetUseConnection4 equ <WNetUseConnection4A>
      endif
    endif
    WNetConnectionDialog proto WIN_STD_CALL_CONV :HWND, :DWORD
    WNetDisconnectDialog proto WIN_STD_CALL_CONV :HWND, :DWORD
    if (WINVER ge 0400h)
      CONNECTDLGSTRUCTA struct
        cbStructure DWORD ?
        hwndOwner HWND ?
        lpConnRes LPNETRESOURCEA ?
        dwFlags DWORD ?
        dwDevNum DWORD ?
      CONNECTDLGSTRUCTA ends
      _CONNECTDLGSTRUCTA typedef CONNECTDLGSTRUCTA
      LPCONNECTDLGSTRUCTA typedef ptr CONNECTDLGSTRUCTA
      CONNECTDLGSTRUCTW struct
        cbStructure DWORD ?
        hwndOwner HWND ?
        lpConnRes LPNETRESOURCEW ?
        dwFlags DWORD ?
        dwDevNum DWORD ?
      CONNECTDLGSTRUCTW ends
      _CONNECTDLGSTRUCTW typedef CONNECTDLGSTRUCTW
      LPCONNECTDLGSTRUCTW typedef ptr CONNECTDLGSTRUCTW
      ifdef UNICODE
        CONNECTDLGSTRUCT typedef CONNECTDLGSTRUCTW
        LPCONNECTDLGSTRUCT typedef LPCONNECTDLGSTRUCTW
      else
        CONNECTDLGSTRUCT typedef CONNECTDLGSTRUCTA
        LPCONNECTDLGSTRUCT typedef LPCONNECTDLGSTRUCTA
      endif
      CONNDLG_RO_PATH equ 00000001h
      CONNDLG_CONN_POINT equ 00000002h
      CONNDLG_USE_MRU equ 00000004h
      CONNDLG_HIDE_BOX equ 00000008h
      CONNDLG_PERSIST equ 00000010h
      CONNDLG_NOT_PERSIST equ 00000020h
      WNetConnectionDialog1A proto WIN_STD_CALL_CONV :LPCONNECTDLGSTRUCTA
      WNetConnectionDialog1W proto WIN_STD_CALL_CONV :LPCONNECTDLGSTRUCTW
      ifdef UNICODE
        WNetConnectionDialog1 equ <WNetConnectionDialog1W>
      else
        WNetConnectionDialog1 equ <WNetConnectionDialog1A>
      endif
      DISCDLGSTRUCTA struct
        cbStructure DWORD ?
        hwndOwner HWND ?
        lpLocalName LPSTR ?
        lpRemoteName LPSTR ?
        dwFlags DWORD ?
      DISCDLGSTRUCTA ends
      _DISCDLGSTRUCTA typedef DISCDLGSTRUCTA
      LPDISCDLGSTRUCTA typedef ptr DISCDLGSTRUCTA
      DISCDLGSTRUCTW struct
        cbStructure DWORD ?
        hwndOwner HWND ?
        lpLocalName LPWSTR ?
        lpRemoteName LPWSTR ?
        dwFlags DWORD ?
      DISCDLGSTRUCTW ends
      _DISCDLGSTRUCTW typedef DISCDLGSTRUCTW
      LPDISCDLGSTRUCTW typedef ptr DISCDLGSTRUCTW
      ifdef UNICODE
        DISCDLGSTRUCT typedef DISCDLGSTRUCTW
        LPDISCDLGSTRUCT typedef LPDISCDLGSTRUCTW
      else
        DISCDLGSTRUCT typedef DISCDLGSTRUCTA
        LPDISCDLGSTRUCT typedef LPDISCDLGSTRUCTA
      endif
      DISC_UPDATE_PROFILE equ 00000001h
      DISC_NO_FORCE equ 00000040h
      WNetDisconnectDialog1A proto WIN_STD_CALL_CONV :LPDISCDLGSTRUCTA
      WNetDisconnectDialog1W proto WIN_STD_CALL_CONV :LPDISCDLGSTRUCTW
      ifdef UNICODE
        WNetDisconnectDialog1 equ <WNetDisconnectDialog1W>
      else
        WNetDisconnectDialog1 equ <WNetDisconnectDialog1A>
      endif
    endif
    WNetOpenEnumA proto WIN_STD_CALL_CONV :DWORD, :DWORD, :DWORD, :LPNETRESOURCEA, :LPHANDLE
    WNetOpenEnumW proto WIN_STD_CALL_CONV :DWORD, :DWORD, :DWORD, :LPNETRESOURCEW, :LPHANDLE
    ifdef UNICODE
      WNetOpenEnum equ <WNetOpenEnumW>
    else
      WNetOpenEnum equ <WNetOpenEnumA>
    endif
    WNetEnumResourceA proto WIN_STD_CALL_CONV :HANDLE, :LPDWORD, :LPVOID, :LPDWORD
    WNetEnumResourceW proto WIN_STD_CALL_CONV :HANDLE, :LPDWORD, :LPVOID, :LPDWORD
    ifdef UNICODE
      WNetEnumResource equ <WNetEnumResourceW>
    else
      WNetEnumResource equ <WNetEnumResourceA>
    endif
    WNetCloseEnum proto WIN_STD_CALL_CONV :HANDLE
    if (WINVER ge 0400h)
      WNetGetResourceParentA proto WIN_STD_CALL_CONV :LPNETRESOURCEA, :LPVOID, :LPDWORD
      WNetGetResourceParentW proto WIN_STD_CALL_CONV :LPNETRESOURCEW, :LPVOID, :LPDWORD
      ifdef UNICODE
        WNetGetResourceParent equ <WNetGetResourceParentW>
      else
        WNetGetResourceParent equ <WNetGetResourceParentA>
      endif
      WNetGetResourceInformationA proto WIN_STD_CALL_CONV :LPNETRESOURCEA, :LPVOID, :LPDWORD, :ptr LPSTR
      WNetGetResourceInformationW proto WIN_STD_CALL_CONV :LPNETRESOURCEW, :LPVOID, :LPDWORD, :ptr LPWSTR
      ifdef UNICODE
        WNetGetResourceInformation equ <WNetGetResourceInformationW>
      else
        WNetGetResourceInformation equ <WNetGetResourceInformationA>
      endif
    endif
    UNIVERSAL_NAME_INFO_LEVEL equ 00000001h
    REMOTE_NAME_INFO_LEVEL equ 00000002h
    UNIVERSAL_NAME_INFOA struct
      lpUniversalName LPSTR ?
    UNIVERSAL_NAME_INFOA ends
    _UNIVERSAL_NAME_INFOA typedef UNIVERSAL_NAME_INFOA
    LPUNIVERSAL_NAME_INFOA typedef ptr UNIVERSAL_NAME_INFOA
    UNIVERSAL_NAME_INFOW struct
      lpUniversalName LPWSTR ?
    UNIVERSAL_NAME_INFOW ends
    _UNIVERSAL_NAME_INFOW typedef UNIVERSAL_NAME_INFOW
    LPUNIVERSAL_NAME_INFOW typedef ptr UNIVERSAL_NAME_INFOW
    ifdef UNICODE
      UNIVERSAL_NAME_INFO typedef UNIVERSAL_NAME_INFOW
      LPUNIVERSAL_NAME_INFO typedef LPUNIVERSAL_NAME_INFOW
    else
      UNIVERSAL_NAME_INFO typedef UNIVERSAL_NAME_INFOA
      LPUNIVERSAL_NAME_INFO typedef LPUNIVERSAL_NAME_INFOA
    endif
    REMOTE_NAME_INFOA struct
      lpUniversalName LPSTR ?
      lpConnectionName LPSTR ?
      lpRemainingPath LPSTR ?
    REMOTE_NAME_INFOA ends
    _REMOTE_NAME_INFOA typedef REMOTE_NAME_INFOA
    LPREMOTE_NAME_INFOA typedef ptr REMOTE_NAME_INFOA
    REMOTE_NAME_INFOW struct
      lpUniversalName LPWSTR ?
      lpConnectionName LPWSTR ?
      lpRemainingPath LPWSTR ?
    REMOTE_NAME_INFOW ends
    _REMOTE_NAME_INFOW typedef REMOTE_NAME_INFOW
    LPREMOTE_NAME_INFOW typedef ptr REMOTE_NAME_INFOW
    ifdef UNICODE
      REMOTE_NAME_INFO typedef REMOTE_NAME_INFOW
      LPREMOTE_NAME_INFO typedef LPREMOTE_NAME_INFOW
    else
      REMOTE_NAME_INFO typedef REMOTE_NAME_INFOA
      LPREMOTE_NAME_INFO typedef LPREMOTE_NAME_INFOA
    endif
    WNetGetUniversalNameA proto WIN_STD_CALL_CONV :LPCSTR, :DWORD, :LPVOID, :LPDWORD
    WNetGetUniversalNameW proto WIN_STD_CALL_CONV :LPCWSTR, :DWORD, :LPVOID, :LPDWORD
    ifdef UNICODE
      WNetGetUniversalName equ <WNetGetUniversalNameW>
    else
      WNetGetUniversalName equ <WNetGetUniversalNameA>
    endif
    WNetGetUserA proto WIN_STD_CALL_CONV :LPCSTR, :LPSTR, :LPDWORD
    WNetGetUserW proto WIN_STD_CALL_CONV :LPCWSTR, :LPWSTR, :LPDWORD
    ifdef UNICODE
      WNetGetUser equ <WNetGetUserW>
    else
      WNetGetUser equ <WNetGetUserA>
    endif
    if (WINVER ge 0400h)
      WNFMT_MULTILINE equ 01h
      WNFMT_ABBREVIATED equ 02h
      WNFMT_INENUM equ 10h
      WNFMT_CONNECTION equ 20h
    endif
    if (WINVER ge 0400h)
      WNetGetProviderNameA proto WIN_STD_CALL_CONV :DWORD, :LPSTR, :LPDWORD
      WNetGetProviderNameW proto WIN_STD_CALL_CONV :DWORD, :LPWSTR, :LPDWORD
      ifdef UNICODE
        WNetGetProviderName equ <WNetGetProviderNameW>
      else
        WNetGetProviderName equ <WNetGetProviderNameA>
      endif
      NETINFOSTRUCT struct
        cbStructure DWORD ?
        dwProviderVersion DWORD ?
        dwStatus DWORD ?
        dwCharacteristics DWORD ?
        dwHandle ULONG_PTR ?
        wNetType WORD ?
        dwPrinters DWORD ?
        dwDrives DWORD ?
      NETINFOSTRUCT ends
      _NETINFOSTRUCT typedef NETINFOSTRUCT
      LPNETINFOSTRUCT typedef ptr NETINFOSTRUCT
      NETINFO_DLL16 equ 00000001h
      NETINFO_DISKRED equ 00000004h
      NETINFO_PRINTERRED equ 00000008h
      WNetGetNetworkInformationA proto WIN_STD_CALL_CONV :LPCSTR, :LPNETINFOSTRUCT
      WNetGetNetworkInformationW proto WIN_STD_CALL_CONV :LPCWSTR, :LPNETINFOSTRUCT
      ifdef UNICODE
        WNetGetNetworkInformation equ <WNetGetNetworkInformationW>
      else
        WNetGetNetworkInformation equ <WNetGetNetworkInformationA>
      endif
    endif
    WNetGetLastErrorA proto WIN_STD_CALL_CONV :LPDWORD, :LPSTR, :DWORD, :LPSTR, :DWORD
    WNetGetLastErrorW proto WIN_STD_CALL_CONV :LPDWORD, :LPWSTR, :DWORD, :LPWSTR, :DWORD
    ifdef UNICODE
      WNetGetLastError equ <WNetGetLastErrorW>
    else
      WNetGetLastError equ <WNetGetLastErrorA>
    endif
    WN_SUCCESS equ <NO_ERROR>
    WN_NO_ERROR equ <NO_ERROR>
    WN_NOT_SUPPORTED equ <ERROR_NOT_SUPPORTED>
    WN_CANCEL equ <ERROR_CANCELLED>
    WN_RETRY equ <ERROR_RETRY>
    WN_NET_ERROR equ <ERROR_UNEXP_NET_ERR>
    WN_MORE_DATA equ <ERROR_MORE_DATA>
    WN_BAD_POINTER equ <ERROR_INVALID_ADDRESS>
    WN_BAD_VALUE equ <ERROR_INVALID_PARAMETER>
    WN_BAD_USER equ <ERROR_BAD_USERNAME>
    WN_BAD_PASSWORD equ <ERROR_INVALID_PASSWORD>
    WN_ACCESS_DENIED equ <ERROR_ACCESS_DENIED>
    WN_FUNCTION_BUSY equ <ERROR_BUSY>
    WN_WINDOWS_ERROR equ <ERROR_UNEXP_NET_ERR>
    WN_OUT_OF_MEMORY equ <ERROR_NOT_ENOUGH_MEMORY>
    WN_NO_NETWORK equ <ERROR_NO_NETWORK>
    WN_EXTENDED_ERROR equ <ERROR_EXTENDED_ERROR>
    WN_BAD_LEVEL equ <ERROR_INVALID_LEVEL>
    WN_BAD_HANDLE equ <ERROR_INVALID_HANDLE>
    if (WINVER ge 0400h)
      WN_NOT_INITIALIZING equ <ERROR_ALREADY_INITIALIZED>
      WN_NO_MORE_DEVICES equ <ERROR_NO_MORE_DEVICES>
    endif
    WN_NOT_CONNECTED equ <ERROR_NOT_CONNECTED>
    WN_OPEN_FILES equ <ERROR_OPEN_FILES>
    WN_DEVICE_IN_USE equ <ERROR_DEVICE_IN_USE>
    WN_BAD_NETNAME equ <ERROR_BAD_NET_NAME>
    WN_BAD_LOCALNAME equ <ERROR_BAD_DEVICE>
    WN_ALREADY_CONNECTED equ <ERROR_ALREADY_ASSIGNED>
    WN_DEVICE_ERROR equ <ERROR_GEN_FAILURE>
    WN_CONNECTION_CLOSED equ <ERROR_CONNECTION_UNAVAIL>
    WN_NO_NET_OR_BAD_PATH equ <ERROR_NO_NET_OR_BAD_PATH>
    WN_BAD_PROVIDER equ <ERROR_BAD_PROVIDER>
    WN_CANNOT_OPEN_PROFILE equ <ERROR_CANNOT_OPEN_PROFILE>
    WN_BAD_PROFILE equ <ERROR_BAD_PROFILE>
    WN_BAD_DEV_TYPE equ <ERROR_BAD_DEV_TYPE>
    WN_DEVICE_ALREADY_REMEMBERED equ <ERROR_DEVICE_ALREADY_REMEMBERED>
    WN_CONNECTED_OTHER_PASSWORD equ <ERROR_CONNECTED_OTHER_PASSWORD>
    if (WINVER ge 0501h)
      WN_CONNECTED_OTHER_PASSWORD_DEFAULT equ <ERROR_CONNECTED_OTHER_PASSWORD_DEFAULT>
    endif
    WN_NO_MORE_ENTRIES equ <ERROR_NO_MORE_ITEMS>
    WN_NOT_CONTAINER equ <ERROR_NOT_CONTAINER>
    if (WINVER ge 0400h)
      WN_NOT_AUTHENTICATED equ <ERROR_NOT_AUTHENTICATED>
      WN_NOT_LOGGED_ON equ <ERROR_NOT_LOGGED_ON>
      WN_NOT_VALIDATED equ <ERROR_NO_LOGON_SERVERS>
    endif
    if (WINVER ge 0400h)
      NETCONNECTINFOSTRUCT struct
        cbStructure DWORD ?
        dwFlags DWORD ?
        dwSpeed DWORD ?
        dwDelay DWORD ?
        dwOptDataSize DWORD ?
      NETCONNECTINFOSTRUCT ends
      _NETCONNECTINFOSTRUCT typedef NETCONNECTINFOSTRUCT
      LPNETCONNECTINFOSTRUCT typedef ptr NETCONNECTINFOSTRUCT
      WNCON_FORNETCARD equ 00000001h
      WNCON_NOTROUTED equ 00000002h
      WNCON_SLOWLINK equ 00000004h
      WNCON_DYNAMIC equ 00000008h
      MultinetGetConnectionPerformanceA proto WIN_STD_CALL_CONV :LPNETRESOURCEA, :LPNETCONNECTINFOSTRUCT
      MultinetGetConnectionPerformanceW proto WIN_STD_CALL_CONV :LPNETRESOURCEW, :LPNETCONNECTINFOSTRUCT
      ifdef UNICODE
        MultinetGetConnectionPerformance equ <MultinetGetConnectionPerformanceW>
      else
        MultinetGetConnectionPerformance equ <MultinetGetConnectionPerformanceA>
      endif
    endif
  endif
  if _MSC_VER ge 1200
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
