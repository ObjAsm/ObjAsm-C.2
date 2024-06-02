;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\shellapi.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 21/02/2024 18:22:52

include winapifamily.inc
if Defined(_MSC_VER) and (_MSC_VER ge 1200)
endif
ifndef _INC_SHELLAPI
  _INC_SHELLAPI equ <>
  include SpecStrings.inc
  ifndef WINSHELLAPI
    if  not Defined(_SHELL32_)
      WINSHELLAPI equ <DECLSPEC_IMPORT>
    else
      WINSHELLAPI equ <>
    endif
  endif
  ifndef SHSTDAPI
    if  not Defined(_SHELL32_)
      SHSTDAPI equ <EXTERN_C DECLSPEC_IMPORT HRESULT STDAPICALLTYPE>
      SHSTDAPI_ macro type_
        exitm <EXTERN_C DECLSPEC_IMPORT type_ STDAPICALLTYPE>
      endm
    else
      SHSTDAPI equ <STDAPI>
      SHSTDAPI_ macro type_
        exitm <STDAPI_(type_)>
      endm
    endif
  endif
  ifndef SHDOCAPI
    if  not Defined(_SHDOCVW_)
      SHDOCAPI equ <EXTERN_C DECLSPEC_IMPORT HRESULT STDAPICALLTYPE>
      SHDOCAPI_ macro type_
        exitm <EXTERN_C DECLSPEC_IMPORT type_ STDAPICALLTYPE>
      endm
    else
      SHDOCAPI equ <STDAPI>
      SHDOCAPI_ macro type_
        exitm <STDAPI_(type_)>
      endm
    endif
  endif
  if  not Defined(_WIN64)
    include pshpack1.inc
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, CommandLineToArgvW, WIN_STD_CALL_CONV,, <:LPCWSTR, :ptr SDWORD>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    DECLARE_HANDLE HDROP
    @DefProto DllImport, DragQueryFileA, WIN_STD_CALL_CONV,, <:HDROP, :UINT, :LPSTR, :UINT>, 16
    @DefProto DllImport, DragQueryFileW, WIN_STD_CALL_CONV,, <:HDROP, :UINT, :LPWSTR, :UINT>, 16
    ifdef UNICODE
      DragQueryFile equ <DragQueryFileW>
    else
      DragQueryFile equ <DragQueryFileA>
    endif
    @DefProto DllImport, DragQueryPoint, WIN_STD_CALL_CONV,, <:HDROP, :ptr POINT>, 8
    @DefProto DllImport, DragFinish, WIN_STD_CALL_CONV,, <:HDROP>, 4
    @DefProto DllImport, DragAcceptFiles, WIN_STD_CALL_CONV,, <:HWND, :BOOL>, 8
    @DefProto DllImport, ShellExecuteA, WIN_STD_CALL_CONV,, <:HWND, :LPCSTR, :LPCSTR, :LPCSTR, :LPCSTR, :INT_>, 24
    @DefProto DllImport, ShellExecuteW, WIN_STD_CALL_CONV,, <:HWND, :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPCWSTR, :INT_>, 24
    ifdef UNICODE
      ShellExecute equ <ShellExecuteW>
    else
      ShellExecute equ <ShellExecuteA>
    endif
    @DefProto DllImport, FindExecutableA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :LPSTR>, 12
    @DefProto DllImport, FindExecutableW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPWSTR>, 12
    ifdef UNICODE
      FindExecutable equ <FindExecutableW>
    else
      FindExecutable equ <FindExecutableA>
    endif
    @DefProto DllImport, ShellAboutA, WIN_STD_CALL_CONV,, <:HWND, :LPCSTR, :LPCSTR, :HICON>, 16
    @DefProto DllImport, ShellAboutW, WIN_STD_CALL_CONV,, <:HWND, :LPCWSTR, :LPCWSTR, :HICON>, 16
    ifdef UNICODE
      ShellAbout equ <ShellAboutW>
    else
      ShellAbout equ <ShellAboutA>
    endif
    @DefProto DllImport, DuplicateIcon, WIN_STD_CALL_CONV,, <:HINSTANCE, :HICON>, 8
    @DefProto DllImport, ExtractAssociatedIconA, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPSTR, :ptr WORD>, 12
    @DefProto DllImport, ExtractAssociatedIconW, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPWSTR, :ptr WORD>, 12
    ifdef UNICODE
      ExtractAssociatedIcon equ <ExtractAssociatedIconW>
    else
      ExtractAssociatedIcon equ <ExtractAssociatedIconA>
    endif
    @DefProto DllImport, ExtractAssociatedIconExA, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPSTR, :ptr WORD, :ptr WORD>, 16
    @DefProto DllImport, ExtractAssociatedIconExW, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPWSTR, :ptr WORD, :ptr WORD>, 16
    ifdef UNICODE
      ExtractAssociatedIconEx equ <ExtractAssociatedIconExW>
    else
      ExtractAssociatedIconEx equ <ExtractAssociatedIconExA>
    endif
    @DefProto DllImport, ExtractIconA, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCSTR, :UINT>, 12
    @DefProto DllImport, ExtractIconW, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCWSTR, :UINT>, 12
    ifdef UNICODE
      ExtractIcon equ <ExtractIconW>
    else
      ExtractIcon equ <ExtractIconA>
    endif
    if (WINVER ge 0400h)
      DRAGINFOA struct
        uSize UINT ?
        pt POINT <>
        fNC BOOL ?
        lpFileList PZZSTR ?
        grfKeyState DWORD ?
      DRAGINFOA ends
      _DRAGINFOA typedef DRAGINFOA
      LPDRAGINFOA typedef ptr DRAGINFOA
      DRAGINFOW struct
        uSize UINT ?
        pt POINT <>
        fNC BOOL ?
        lpFileList PZZWSTR ?
        grfKeyState DWORD ?
      DRAGINFOW ends
      _DRAGINFOW typedef DRAGINFOW
      LPDRAGINFOW typedef ptr DRAGINFOW
      ifdef UNICODE
        DRAGINFO typedef DRAGINFOW
        LPDRAGINFO typedef LPDRAGINFOW
      else
        DRAGINFO typedef DRAGINFOA
        LPDRAGINFO typedef LPDRAGINFOA
      endif
      ABM_NEW equ 00000000h
      ABM_REMOVE equ 00000001h
      ABM_QUERYPOS equ 00000002h
      ABM_SETPOS equ 00000003h
      ABM_GETSTATE equ 00000004h
      ABM_GETTASKBARPOS equ 00000005h
      ABM_ACTIVATE equ 00000006h
      ABM_GETAUTOHIDEBAR equ 00000007h
      ABM_SETAUTOHIDEBAR equ 00000008h
      ABM_WINDOWPOSCHANGED equ 0000009h
      if (NTDDI_VERSION ge NTDDI_WINXP)
        ABM_SETSTATE equ 0000000ah
      endif
      if (NTDDI_VERSION ge NTDDI_WIN8)
        ABM_GETAUTOHIDEBAREX equ 0000000bh
        ABM_SETAUTOHIDEBAREX equ 0000000ch
      endif
      ABN_STATECHANGE equ 0000000h
      ABN_POSCHANGED equ 0000001h
      ABN_FULLSCREENAPP equ 0000002h
      ABN_WINDOWARRANGE equ 0000003h
      ABS_AUTOHIDE equ 0000001h
      ABS_ALWAYSONTOP equ 0000002h
      ABE_LEFT equ 0
      ABE_TOP equ 1
      ABE_RIGHT equ 2
      ABE_BOTTOM equ 3
      APPBARDATA struct
        cbSize DWORD ?
        hWnd HWND ?
        uCallbackMessage UINT ?
        uEdge UINT ?
        rc RECT <>
        lParam LPARAM ?
      APPBARDATA ends
      _AppBarData typedef APPBARDATA
      PAPPBARDATA typedef ptr APPBARDATA
      @DefProto DllImport, SHAppBarMessage, WIN_STD_CALL_CONV,, <:DWORD, :PAPPBARDATA>, 8
      @DefProto DllImport, DoEnvironmentSubstA, WIN_STD_CALL_CONV,, <:LPSTR, :UINT>, 8
      @DefProto DllImport, DoEnvironmentSubstW, WIN_STD_CALL_CONV,, <:LPWSTR, :UINT>, 8
      ifdef UNICODE
        DoEnvironmentSubst equ <DoEnvironmentSubstW>
      else
        DoEnvironmentSubst equ <DoEnvironmentSubstA>
      endif
      EIRESID macro x
        exitm <(- 1 * (x))>
      endm
      @DefProto DllImport, ExtractIconExA, WIN_STD_CALL_CONV,, <:LPCSTR, :SDWORD, :ptr HICON, :ptr HICON, :UINT>, 20
      @DefProto DllImport, ExtractIconExW, WIN_STD_CALL_CONV,, <:LPCWSTR, :SDWORD, :ptr HICON, :ptr HICON, :UINT>, 20
      ifdef UNICODE
        ExtractIconEx equ <ExtractIconExW>
      else
        ExtractIconEx equ <ExtractIconExA>
      endif
      FO_MOVE equ 0001h
      FO_COPY equ 0002h
      FO_DELETE equ 0003h
      FO_RENAME equ 0004h
      FOF_MULTIDESTFILES equ 0001h
      FOF_CONFIRMMOUSE equ 0002h
      FOF_SILENT equ 0004h
      FOF_RENAMEONCOLLISION equ 0008h
      FOF_NOCONFIRMATION equ 0010h
      FOF_WANTMAPPINGHANDLE equ 0020h
      FOF_ALLOWUNDO equ 0040h
      FOF_FILESONLY equ 0080h
      FOF_SIMPLEPROGRESS equ 0100h
      FOF_NOCONFIRMMKDIR equ 0200h
      FOF_NOERRORUI equ 0400h
      FOF_NOCOPYSECURITYATTRIBS equ 0800h
      FOF_NORECURSION equ 1000h
      FOF_NO_CONNECTED_ELEMENTS equ 2000h
      FOF_WANTNUKEWARNING equ 4000h
      if (NTDDI_VERSION ge NTDDI_WINXP)
        FOF_NORECURSEREPARSE equ 8000h
      endif
      FOF_NO_UI equ <(FOF_SILENT or FOF_NOCONFIRMATION or FOF_NOERRORUI or FOF_NOCONFIRMMKDIR)>
      FILEOP_FLAGS typedef WORD
      PO_DELETE equ 0013h
      PO_RENAME equ 0014h
      PO_PORTCHANGE equ 0020h
      PO_REN_PORT equ 0034h
      PRINTEROP_FLAGS typedef WORD
      SHFILEOPSTRUCTA struct
        hwnd HWND ?
        wFunc UINT ?
        pFrom PCZZSTR ?
        pTo PCZZSTR ?
        fFlags FILEOP_FLAGS ?
        fAnyOperationsAborted BOOL ?
        hNameMappings LPVOID ?
        lpszProgressTitle PCSTR ?
      SHFILEOPSTRUCTA ends
      _SHFILEOPSTRUCTA typedef SHFILEOPSTRUCTA
      LPSHFILEOPSTRUCTA typedef ptr SHFILEOPSTRUCTA
      SHFILEOPSTRUCTW struct
        hwnd HWND ?
        wFunc UINT ?
        pFrom PCZZWSTR ?
        pTo PCZZWSTR ?
        fFlags FILEOP_FLAGS ?
        fAnyOperationsAborted BOOL ?
        hNameMappings LPVOID ?
        lpszProgressTitle PCWSTR ?
      SHFILEOPSTRUCTW ends
      _SHFILEOPSTRUCTW typedef SHFILEOPSTRUCTW
      LPSHFILEOPSTRUCTW typedef ptr SHFILEOPSTRUCTW
      ifdef UNICODE
        SHFILEOPSTRUCT typedef SHFILEOPSTRUCTW
        LPSHFILEOPSTRUCT typedef LPSHFILEOPSTRUCTW
      else
        SHFILEOPSTRUCT typedef SHFILEOPSTRUCTA
        LPSHFILEOPSTRUCT typedef LPSHFILEOPSTRUCTA
      endif
      @DefProto DllImport, SHFileOperationA, WIN_STD_CALL_CONV,, <:LPSHFILEOPSTRUCTA>, 4
      @DefProto DllImport, SHFileOperationW, WIN_STD_CALL_CONV,, <:LPSHFILEOPSTRUCTW>, 4
      ifdef UNICODE
        SHFileOperation equ <SHFileOperationW>
      else
        SHFileOperation equ <SHFileOperationA>
      endif
      @DefProto DllImport, SHFreeNameMappings, WIN_STD_CALL_CONV,, <:HANDLE>, 4
      SHNAMEMAPPINGA struct
        pszOldPath LPSTR ?
        pszNewPath LPSTR ?
        cchOldPath SDWORD ?
        cchNewPath SDWORD ?
      SHNAMEMAPPINGA ends
      _SHNAMEMAPPINGA typedef SHNAMEMAPPINGA
      LPSHNAMEMAPPINGA typedef ptr SHNAMEMAPPINGA
      SHNAMEMAPPINGW struct
        pszOldPath LPWSTR ?
        pszNewPath LPWSTR ?
        cchOldPath SDWORD ?
        cchNewPath SDWORD ?
      SHNAMEMAPPINGW ends
      _SHNAMEMAPPINGW typedef SHNAMEMAPPINGW
      LPSHNAMEMAPPINGW typedef ptr SHNAMEMAPPINGW
      ifdef UNICODE
        SHNAMEMAPPING typedef SHNAMEMAPPINGW
        LPSHNAMEMAPPING typedef LPSHNAMEMAPPINGW
      else
        SHNAMEMAPPING typedef SHNAMEMAPPINGA
        LPSHNAMEMAPPING typedef LPSHNAMEMAPPINGA
      endif
      SE_ERR_FNF equ 2
      SE_ERR_PNF equ 3
      SE_ERR_ACCESSDENIED equ 5
      SE_ERR_OOM equ 8
      SE_ERR_DLLNOTFOUND equ 32
    endif
    SE_ERR_SHARE equ 26
    SE_ERR_ASSOCINCOMPLETE equ 27
    SE_ERR_DDETIMEOUT equ 28
    SE_ERR_DDEFAIL equ 29
    SE_ERR_DDEBUSY equ 30
    SE_ERR_NOASSOC equ 31
    if (WINVER ge 0400h)
      SEE_MASK_DEFAULT equ 00000000h
      SEE_MASK_CLASSNAME equ 00000001h
      SEE_MASK_CLASSKEY equ 00000003h
      SEE_MASK_IDLIST equ 00000004h
      SEE_MASK_INVOKEIDLIST equ 0000000ch
      if (NTDDI_VERSION lt NTDDI_VISTA)
        SEE_MASK_ICON equ 00000010h
      endif
      SEE_MASK_HOTKEY equ 00000020h
      SEE_MASK_NOCLOSEPROCESS equ 00000040h
      SEE_MASK_CONNECTNETDRV equ 00000080h
      SEE_MASK_NOASYNC equ 00000100h
      SEE_MASK_FLAG_DDEWAIT equ <SEE_MASK_NOASYNC>
      SEE_MASK_DOENVSUBST equ 00000200h
      SEE_MASK_FLAG_NO_UI equ 00000400h
      SEE_MASK_UNICODE equ 00004000h
      SEE_MASK_NO_CONSOLE equ 00008000h
      SEE_MASK_ASYNCOK equ 00100000h
      if (NTDDI_VERSION ge NTDDI_WIN2K)
        SEE_MASK_HMONITOR equ 00200000h
      endif
      if (NTDDI_VERSION ge NTDDI_WINXPSP1)
        SEE_MASK_NOZONECHECKS equ 00800000h
      endif
      if (NTDDI_VERSION ge NTDDI_WIN2K)
        SEE_MASK_NOQUERYCLASSSTORE equ 01000000h
        SEE_MASK_WAITFORINPUTIDLE equ 02000000h
      endif
      if (NTDDI_VERSION ge NTDDI_WINXP)
        SEE_MASK_FLAG_LOG_USAGE equ 04000000h
      endif
      if (NTDDI_VERSION ge NTDDI_VISTA)
        SEE_MASK_FLAG_HINST_IS_SITE equ 08000000h
      endif
      ifndef DUMMYUNIONNAME
        ifdef NONAMELESSUNION
          DUMMYUNIONNAME equ <u>
          DUMMYUNIONNAME2 equ <u2>
          DUMMYUNIONNAME3 equ <u3>
          DUMMYUNIONNAME4 equ <u4>
          DUMMYUNIONNAME5 equ <u5>
        else
          DUMMYUNIONNAME equ <>
          DUMMYUNIONNAME2 equ <>
          DUMMYUNIONNAME3 equ <>
          DUMMYUNIONNAME4 equ <>
          DUMMYUNIONNAME5 equ <>
        endif
      endif
      SHELLEXECUTEINFOA struct
        cbSize DWORD ?
        fMask ULONG ?
        hwnd HWND ?
        lpVerb LPCSTR ?
        lpFile LPCSTR ?
        lpParameters LPCSTR ?
        lpDirectory LPCSTR ?
        nShow SDWORD ?
        hInstApp HINSTANCE ?
        lpIDList POINTER ?
        lpClass LPCSTR ?
        hkeyClass HKEY ?
        dwHotKey DWORD ?
        union
          hIcon HANDLE ?
          if (NTDDI_VERSION ge NTDDI_WIN2K)
            hMonitor HANDLE ?
          endif
        ends
        hProcess HANDLE ?
      SHELLEXECUTEINFOA ends
      _SHELLEXECUTEINFOA typedef SHELLEXECUTEINFOA
      LPSHELLEXECUTEINFOA typedef ptr SHELLEXECUTEINFOA
      SHELLEXECUTEINFOW struct
        cbSize DWORD ?
        fMask ULONG ?
        hwnd HWND ?
        lpVerb LPCWSTR ?
        lpFile LPCWSTR ?
        lpParameters LPCWSTR ?
        lpDirectory LPCWSTR ?
        nShow SDWORD ?
        hInstApp HINSTANCE ?
        lpIDList POINTER ?
        lpClass LPCWSTR ?
        hkeyClass HKEY ?
        dwHotKey DWORD ?
        union
          hIcon HANDLE ?
          if (NTDDI_VERSION ge NTDDI_WIN2K)
            hMonitor HANDLE ?
          endif
        ends
        hProcess HANDLE ?
      SHELLEXECUTEINFOW ends
      _SHELLEXECUTEINFOW typedef SHELLEXECUTEINFOW
      LPSHELLEXECUTEINFOW typedef ptr SHELLEXECUTEINFOW
      ifdef UNICODE
        SHELLEXECUTEINFO typedef SHELLEXECUTEINFOW
        LPSHELLEXECUTEINFO typedef LPSHELLEXECUTEINFOW
      else
        SHELLEXECUTEINFO typedef SHELLEXECUTEINFOA
        LPSHELLEXECUTEINFO typedef LPSHELLEXECUTEINFOA
      endif
      @DefProto DllImport, ShellExecuteExA, WIN_STD_CALL_CONV,, <:ptr SHELLEXECUTEINFOA>, 4
      @DefProto DllImport, ShellExecuteExW, WIN_STD_CALL_CONV,, <:ptr SHELLEXECUTEINFOW>, 4
      ifdef UNICODE
        ShellExecuteEx equ <ShellExecuteExW>
      else
        ShellExecuteEx equ <ShellExecuteExA>
      endif
      if (NTDDI_VERSION ge NTDDI_WIN2K)
        SHCREATEPROCESSINFOW struct
          cbSize DWORD ?
          fMask ULONG ?
          hwnd HWND ?
          pszFile LPCWSTR ?
          pszParameters LPCWSTR ?
          pszCurrentDirectory LPCWSTR ?
          hUserToken HANDLE ?
          lpProcessAttributes LPSECURITY_ATTRIBUTES ?
          lpThreadAttributes LPSECURITY_ATTRIBUTES ?
          bInheritHandles BOOL ?
          dwCreationFlags DWORD ?
          lpStartupInfo LPSTARTUPINFOW ?
          lpProcessInformation LPPROCESS_INFORMATION ?
        SHCREATEPROCESSINFOW ends
        _SHCREATEPROCESSINFOW typedef SHCREATEPROCESSINFOW
        PSHCREATEPROCESSINFOW typedef ptr SHCREATEPROCESSINFOW
        @DefProto DllImport, SHCreateProcessAsUserW, WIN_STD_CALL_CONV,, <:PSHCREATEPROCESSINFOW>, 4
      endif
      if (NTDDI_VERSION ge NTDDI_VISTA)
        @DefProto DllImport, SHEvaluateSystemCommandTemplate, WIN_STD_CALL_CONV,, <:PCWSTR, :ptr PWSTR, :ptr PWSTR, :ptr PWSTR>, 16
        ASSOCCLASS typedef SDWORD
        ASSOCCLASS_SHELL_KEY equ 0
        ASSOCCLASS_PROGID_KEY equ 1
        ASSOCCLASS_PROGID_STR equ 2
        ASSOCCLASS_CLSID_KEY equ 3
        ASSOCCLASS_CLSID_STR equ 4
        ASSOCCLASS_APP_KEY equ 5
        ASSOCCLASS_APP_STR equ 6
        ASSOCCLASS_SYSTEM_STR equ 7
        ASSOCCLASS_FOLDER equ 8
        ASSOCCLASS_STAR equ 9
        if (NTDDI_VERSION ge NTDDI_WIN8)
          ASSOCCLASS_FIXED_PROGID_STR equ 10
          ASSOCCLASS_PROTOCOL_STR equ 11
        endif

        ASSOCIATIONELEMENT struct
          ac ASSOCCLASS ?
          hkClass HKEY ?
          pszClass PCWSTR ?
        ASSOCIATIONELEMENT ends
        @DefProto DllImport, AssocCreateForClasses, WIN_STD_CALL_CONV,, <:ptr ASSOCIATIONELEMENT, :ULONG, :REFIID, :ptr ptr>, 16
      endif
      if (NTDDI_VERSION ge NTDDI_WIN2K)
        SHQUERYRBINFO struct
          cbSize DWORD ?
          if  not Defined(_MAC) or Defined(_MAC_INT_64)
            i64Size SQWORD ?
            i64NumItems SQWORD ?
          else
            ;[...]
          endif
        SHQUERYRBINFO ends
        _SHQUERYRBINFO typedef SHQUERYRBINFO
        LPSHQUERYRBINFO typedef ptr SHQUERYRBINFO
        SHERB_NOCONFIRMATION equ 00000001h
        SHERB_NOPROGRESSUI equ 00000002h
        SHERB_NOSOUND equ 00000004h
        @DefProto DllImport, SHQueryRecycleBinA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPSHQUERYRBINFO>, 8
        @DefProto DllImport, SHQueryRecycleBinW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPSHQUERYRBINFO>, 8
        ifdef UNICODE
          SHQueryRecycleBin equ <SHQueryRecycleBinW>
        else
          SHQueryRecycleBin equ <SHQueryRecycleBinA>
        endif
        @DefProto DllImport, SHEmptyRecycleBinA, WIN_STD_CALL_CONV,, <:HWND, :LPCSTR, :DWORD>, 12
        @DefProto DllImport, SHEmptyRecycleBinW, WIN_STD_CALL_CONV,, <:HWND, :LPCWSTR, :DWORD>, 12
        ifdef UNICODE
          SHEmptyRecycleBin equ <SHEmptyRecycleBinW>
        else
          SHEmptyRecycleBin equ <SHEmptyRecycleBinA>
        endif
      endif
      if (NTDDI_VERSION ge NTDDI_VISTA)
        QUERY_USER_NOTIFICATION_STATE typedef SDWORD
        QUNS_NOT_PRESENT equ 1
        QUNS_BUSY equ 2
        QUNS_RUNNING_D3D_FULL_SCREEN equ 3
        QUNS_PRESENTATION_MODE equ 4
        QUNS_ACCEPTS_NOTIFICATIONS equ 5
        if (NTDDI_VERSION ge NTDDI_WIN7)
          QUNS_QUIET_TIME equ 6
        endif
        if (NTDDI_VERSION ge NTDDI_WIN8)
          QUNS_APP equ 7
        endif

        @DefProto DllImport, SHQueryUserNotificationState, WIN_STD_CALL_CONV,, <:ptr QUERY_USER_NOTIFICATION_STATE>, 4
      endif
      if (NTDDI_VERSION ge NTDDI_WIN7)
        @DefProto DllImport, SHGetPropertyStoreForWindow, WIN_STD_CALL_CONV,, <:HWND, :REFIID, :ptr ptr>, 12
      endif
      NOTIFYICONDATAA struct
        cbSize DWORD ?
        hWnd HWND ?
        uID UINT ?
        uFlags UINT ?
        uCallbackMessage UINT ?
        hIcon HICON ?
        if (NTDDI_VERSION lt NTDDI_WIN2K)
          szTip CHAR 64 dup (?)
        endif
        if (NTDDI_VERSION ge NTDDI_WIN2K)
          szTip CHAR 128 dup (?)
          dwState DWORD ?
          dwStateMask DWORD ?
          szInfo CHAR 256 dup (?)
          ifndef _SHELL_EXPORTS_INTERNALAPI_H_
            union
              uTimeout UINT ?
              uVersion UINT ?
            ends
          endif
          szInfoTitle CHAR 64 dup (?)
          dwInfoFlags DWORD ?
        endif
        if (NTDDI_VERSION ge NTDDI_WINXP)
          guidItem GUID <>
        endif
        if (NTDDI_VERSION ge NTDDI_VISTA)
          hBalloonIcon HICON ?
        endif
      NOTIFYICONDATAA ends
      _NOTIFYICONDATAA typedef NOTIFYICONDATAA
      PNOTIFYICONDATAA typedef ptr NOTIFYICONDATAA
      NOTIFYICONDATAW struct
        cbSize DWORD ?
        hWnd HWND ?
        uID UINT ?
        uFlags UINT ?
        uCallbackMessage UINT ?
        hIcon HICON ?
        if (NTDDI_VERSION lt NTDDI_WIN2K)
          szTip WCHAR 64 dup (?)
        endif
        if (NTDDI_VERSION ge NTDDI_WIN2K)
          szTip WCHAR 128 dup (?)
          dwState DWORD ?
          dwStateMask DWORD ?
          szInfo WCHAR 256 dup (?)
          ifndef _SHELL_EXPORTS_INTERNALAPI_H_
            union
              uTimeout UINT ?
              uVersion UINT ?
            ends
          endif
          szInfoTitle WCHAR 64 dup (?)
          dwInfoFlags DWORD ?
        endif
        if (NTDDI_VERSION ge NTDDI_WINXP)
          guidItem GUID <>
        endif
        if (NTDDI_VERSION ge NTDDI_VISTA)
          hBalloonIcon HICON ?
        endif
      NOTIFYICONDATAW ends
      _NOTIFYICONDATAW typedef NOTIFYICONDATAW
      PNOTIFYICONDATAW typedef ptr NOTIFYICONDATAW
      ifdef UNICODE
        NOTIFYICONDATA typedef NOTIFYICONDATAW
        PNOTIFYICONDATA typedef PNOTIFYICONDATAW
      else
        NOTIFYICONDATA typedef NOTIFYICONDATAA
        PNOTIFYICONDATA typedef PNOTIFYICONDATAA
      endif
      NOTIFYICONDATAA_V1_SIZE equ FIELD_OFFSET (NOTIFYICONDATAA, szTip [ 64 ])
      NOTIFYICONDATAW_V1_SIZE equ FIELD_OFFSET (NOTIFYICONDATAW, szTip [ 64 ])
      ifdef UNICODE
        NOTIFYICONDATA_V1_SIZE equ <NOTIFYICONDATAW_V1_SIZE>
      else
        NOTIFYICONDATA_V1_SIZE equ <NOTIFYICONDATAA_V1_SIZE>
      endif
      NOTIFYICONDATAA_V2_SIZE equ <FIELD_OFFSET (NOTIFYICONDATAA, guidItem)>
      NOTIFYICONDATAW_V2_SIZE equ <FIELD_OFFSET (NOTIFYICONDATAW, guidItem)>
      ifdef UNICODE
        NOTIFYICONDATA_V2_SIZE equ <NOTIFYICONDATAW_V2_SIZE>
      else
        NOTIFYICONDATA_V2_SIZE equ <NOTIFYICONDATAA_V2_SIZE>
      endif
      NOTIFYICONDATAA_V3_SIZE equ <FIELD_OFFSET (NOTIFYICONDATAA, hBalloonIcon)>
      NOTIFYICONDATAW_V3_SIZE equ <FIELD_OFFSET (NOTIFYICONDATAW, hBalloonIcon)>
      ifdef UNICODE
        NOTIFYICONDATA_V3_SIZE equ <NOTIFYICONDATAW_V3_SIZE>
      else
        NOTIFYICONDATA_V3_SIZE equ <NOTIFYICONDATAA_V3_SIZE>
      endif
      NIN_SELECT equ (WM_USER + 0)
      NINF_KEY equ 1h
      NIN_KEYSELECT equ <(NIN_SELECT or NINF_KEY)>
      NIN_BALLOONSHOW equ (WM_USER + 2)
      NIN_BALLOONHIDE equ (WM_USER + 3)
      NIN_BALLOONTIMEOUT equ (WM_USER + 4)
      NIN_BALLOONUSERCLICK equ (WM_USER + 5)
      if (NTDDI_VERSION ge NTDDI_VISTA)
        NIN_POPUPOPEN equ (WM_USER + 6)
        NIN_POPUPCLOSE equ (WM_USER + 7)
      endif
      if (NTDDI_VERSION ge NTDDI_WIN7)
      endif
      NIM_ADD equ 00000000h
      NIM_MODIFY equ 00000001h
      NIM_DELETE equ 00000002h
      NIM_SETFOCUS equ 00000003h
      NIM_SETVERSION equ 00000004h
      NOTIFYICON_VERSION equ 3
      if (NTDDI_VERSION ge NTDDI_VISTA)
        NOTIFYICON_VERSION_4 equ 4
      endif
      NIF_MESSAGE equ 00000001h
      NIF_ICON equ 00000002h
      NIF_TIP equ 00000004h
      NIF_STATE equ 00000008h
      NIF_INFO equ 00000010h
      if (_WIN32_IE ge 600h)
        NIF_GUID equ 00000020h
      endif
      if (NTDDI_VERSION ge NTDDI_VISTA)
        NIF_REALTIME equ 00000040h
        NIF_SHOWTIP equ 00000080h
      endif
      NIS_HIDDEN equ 00000001h
      NIS_SHAREDICON equ 00000002h
      NIIF_NONE equ 00000000h
      NIIF_INFO equ 00000001h
      NIIF_WARNING equ 00000002h
      NIIF_ERROR equ 00000003h
      if (NTDDI_VERSION ge NTDDI_WINXPSP2)
        NIIF_USER equ 00000004h
      endif
      NIIF_ICON_MASK equ 0000000Fh
      NIIF_NOSOUND equ 00000010h
      if (NTDDI_VERSION ge NTDDI_VISTA)
        NIIF_LARGE_ICON equ 00000020h
      endif
      if (NTDDI_VERSION ge NTDDI_WIN7)
        NIIF_RESPECT_QUIET_TIME equ 00000080h
      endif
      NOTIFYICONIDENTIFIER struct
        cbSize DWORD ?
        hWnd HWND ?
        uID UINT ?
        guidItem GUID <>
      NOTIFYICONIDENTIFIER ends
      _NOTIFYICONIDENTIFIER typedef NOTIFYICONIDENTIFIER
      PNOTIFYICONIDENTIFIER typedef ptr NOTIFYICONIDENTIFIER
      @DefProto DllImport, Shell_NotifyIconA, WIN_STD_CALL_CONV,, <:DWORD, :PNOTIFYICONDATAA>, 8
      @DefProto DllImport, Shell_NotifyIconW, WIN_STD_CALL_CONV,, <:DWORD, :PNOTIFYICONDATAW>, 8
      ifdef UNICODE
        Shell_NotifyIcon equ <Shell_NotifyIconW>
      else
        Shell_NotifyIcon equ <Shell_NotifyIconA>
      endif
      if (NTDDI_VERSION ge NTDDI_WIN7)
        @DefProto DllImport, Shell_NotifyIconGetRect, WIN_STD_CALL_CONV,, <:ptr NOTIFYICONIDENTIFIER, :ptr RECT>, 8
      endif
      ifndef SHFILEINFO_DEFINED
        SHFILEINFO_DEFINED equ <>
        SHFILEINFOA struct
          hIcon HICON ?
          iIcon SDWORD ?
          dwAttributes DWORD ?
          szDisplayName CHAR MAX_PATH dup (?)
          szTypeName CHAR 80 dup (?)
        SHFILEINFOA ends
        _SHFILEINFOA typedef SHFILEINFOA
        SHFILEINFOW struct
          hIcon HICON ?
          iIcon SDWORD ?
          dwAttributes DWORD ?
          szDisplayName WCHAR MAX_PATH dup (?)
          szTypeName WCHAR 80 dup (?)
        SHFILEINFOW ends
        _SHFILEINFOW typedef SHFILEINFOW
        ifdef UNICODE
          SHFILEINFO typedef SHFILEINFOW
        else
          SHFILEINFO typedef SHFILEINFOA
        endif
      endif
      SHGFI_ICON equ 000000100h
      SHGFI_DISPLAYNAME equ 000000200h
      SHGFI_TYPENAME equ 000000400h
      SHGFI_ATTRIBUTES equ 000000800h
      SHGFI_ICONLOCATION equ 000001000h
      SHGFI_EXETYPE equ 000002000h
      SHGFI_SYSICONINDEX equ 000004000h
      SHGFI_LINKOVERLAY equ 000008000h
      SHGFI_SELECTED equ 000010000h
      if (NTDDI_VERSION ge NTDDI_WIN2K)
        SHGFI_ATTR_SPECIFIED equ 000020000h
      endif
      SHGFI_LARGEICON equ 000000000h
      SHGFI_SMALLICON equ 000000001h
      SHGFI_OPENICON equ 000000002h
      SHGFI_SHELLICONSIZE equ 000000004h
      SHGFI_PIDL equ 000000008h
      SHGFI_USEFILEATTRIBUTES equ 000000010h
      SHGFI_ADDOVERLAYS equ 000000020h
      SHGFI_OVERLAYINDEX equ 000000040h
      @DefProto DllImport, SHGetFileInfoA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :ptr SHFILEINFOA, :UINT, :UINT>, 20
      @DefProto DllImport, SHGetFileInfoW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :ptr SHFILEINFOW, :UINT, :UINT>, 20
      ifdef UNICODE
        SHGetFileInfo equ <SHGetFileInfoW>
      else
        SHGetFileInfo equ <SHGetFileInfoA>
      endif
      if (NTDDI_VERSION ge NTDDI_VISTA)
        SHSTOCKICONINFO struct
          cbSize DWORD ?
          hIcon HICON ?
          iSysImageIndex SDWORD ?
          iIcon SDWORD ?
          szPath WCHAR MAX_PATH dup (?)
        SHSTOCKICONINFO ends
        _SHSTOCKICONINFO typedef SHSTOCKICONINFO
        SHGSI_ICONLOCATION equ 0
        SHGSI_ICON equ <SHGFI_ICON>
        SHGSI_SYSICONINDEX equ <SHGFI_SYSICONINDEX>
        SHGSI_LINKOVERLAY equ <SHGFI_LINKOVERLAY>
        SHGSI_SELECTED equ <SHGFI_SELECTED>
        SHGSI_LARGEICON equ <SHGFI_LARGEICON>
        SHGSI_SMALLICON equ <SHGFI_SMALLICON>
        SHGSI_SHELLICONSIZE equ <SHGFI_SHELLICONSIZE>
        SHSTOCKICONID typedef SDWORD
        SIID_DOCNOASSOC equ 0
        SIID_DOCASSOC equ 1
        SIID_APPLICATION equ 2
        SIID_FOLDER equ 3
        SIID_FOLDEROPEN equ 4
        SIID_DRIVE525 equ 5
        SIID_DRIVE35 equ 6
        SIID_DRIVEREMOVE equ 7
        SIID_DRIVEFIXED equ 8
        SIID_DRIVENET equ 9
        SIID_DRIVENETDISABLED equ 10
        SIID_DRIVECD equ 11
        SIID_DRIVERAM equ 12
        SIID_WORLD equ 13
        SIID_SERVER equ 15
        SIID_PRINTER equ 16
        SIID_MYNETWORK equ 17
        SIID_FIND equ 22
        SIID_HELP equ 23
        SIID_SHARE equ 28
        SIID_LINK equ 29
        SIID_SLOWFILE equ 30
        SIID_RECYCLER equ 31
        SIID_RECYCLERFULL equ 32
        SIID_MEDIACDAUDIO equ 40
        SIID_LOCK equ 47
        SIID_AUTOLIST equ 49
        SIID_PRINTERNET equ 50
        SIID_SERVERSHARE equ 51
        SIID_PRINTERFAX equ 52
        SIID_PRINTERFAXNET equ 53
        SIID_PRINTERFILE equ 54
        SIID_STACK equ 55
        SIID_MEDIASVCD equ 56
        SIID_STUFFEDFOLDER equ 57
        SIID_DRIVEUNKNOWN equ 58
        SIID_DRIVEDVD equ 59
        SIID_MEDIADVD equ 60
        SIID_MEDIADVDRAM equ 61
        SIID_MEDIADVDRW equ 62
        SIID_MEDIADVDR equ 63
        SIID_MEDIADVDROM equ 64
        SIID_MEDIACDAUDIOPLUS equ 65
        SIID_MEDIACDRW equ 66
        SIID_MEDIACDR equ 67
        SIID_MEDIACDBURN equ 68
        SIID_MEDIABLANKCD equ 69
        SIID_MEDIACDROM equ 70
        SIID_AUDIOFILES equ 71
        SIID_IMAGEFILES equ 72
        SIID_VIDEOFILES equ 73
        SIID_MIXEDFILES equ 74
        SIID_FOLDERBACK equ 75
        SIID_FOLDERFRONT equ 76
        SIID_SHIELD equ 77
        SIID_WARNING equ 78
        SIID_INFO equ 79
        SIID_ERROR equ 80
        SIID_KEY equ 81
        SIID_SOFTWARE equ 82
        SIID_RENAME equ 83
        SIID_DELETE equ 84
        SIID_MEDIAAUDIODVD equ 85
        SIID_MEDIAMOVIEDVD equ 86
        SIID_MEDIAENHANCEDCD equ 87
        SIID_MEDIAENHANCEDDVD equ 88
        SIID_MEDIAHDDVD equ 89
        SIID_MEDIABLURAY equ 90
        SIID_MEDIAVCD equ 91
        SIID_MEDIADVDPLUSR equ 92
        SIID_MEDIADVDPLUSRW equ 93
        SIID_DESKTOPPC equ 94
        SIID_MOBILEPC equ 95
        SIID_USERS equ 96
        SIID_MEDIASMARTMEDIA equ 97
        SIID_MEDIACOMPACTFLASH equ 98
        SIID_DEVICECELLPHONE equ 99
        SIID_DEVICECAMERA equ 100
        SIID_DEVICEVIDEOCAMERA equ 101
        SIID_DEVICEAUDIOPLAYER equ 102
        SIID_NETWORKCONNECT equ 103
        SIID_INTERNET equ 104
        SIID_ZIPFILE equ 105
        SIID_SETTINGS equ 106
        SIID_DRIVEHDDVD equ 132
        SIID_DRIVEBD equ 133
        SIID_MEDIAHDDVDROM equ 134
        SIID_MEDIAHDDVDR equ 135
        SIID_MEDIAHDDVDRAM equ 136
        SIID_MEDIABDROM equ 137
        SIID_MEDIABDR equ 138
        SIID_MEDIABDRE equ 139
        SIID_CLUSTEREDDRIVE equ 140
        SIID_MAX_ICONS equ 181

        SIID_INVALID equ ((SHSTOCKICONID) - 1)
        @DefProto DllImport, SHGetStockIconInfo, WIN_STD_CALL_CONV,, <:SHSTOCKICONID, :UINT, :ptr SHSTOCKICONINFO>, 12
      endif
      if (NTDDI_VERSION ge NTDDI_WIN2K)
        SHGetDiskFreeSpace equ <SHGetDiskFreeSpaceEx>
        @DefProto DllImport, SHGetDiskFreeSpaceExA, WIN_STD_CALL_CONV,, <:LPCSTR, :ptr ULARGE_INTEGER, :ptr ULARGE_INTEGER, :ptr ULARGE_INTEGER>, 16
        @DefProto DllImport, SHGetDiskFreeSpaceExW, WIN_STD_CALL_CONV,, <:LPCWSTR, :ptr ULARGE_INTEGER, :ptr ULARGE_INTEGER, :ptr ULARGE_INTEGER>, 16
        ifdef UNICODE
          SHGetDiskFreeSpaceEx equ <SHGetDiskFreeSpaceExW>
        else
          SHGetDiskFreeSpaceEx equ <SHGetDiskFreeSpaceExA>
        endif
        @DefProto DllImport, SHGetNewLinkInfoA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :LPSTR, :ptr BOOL, :UINT>, 20
        @DefProto DllImport, SHGetNewLinkInfoW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPWSTR, :ptr BOOL, :UINT>, 20
        ifdef UNICODE
          SHGetNewLinkInfo equ <SHGetNewLinkInfoW>
        else
          SHGetNewLinkInfo equ <SHGetNewLinkInfoA>
        endif
        SHGNLI_PIDL equ 000000001h
        SHGNLI_PREFIXNAME equ 000000002h
        SHGNLI_NOUNIQUE equ 000000004h
        SHGNLI_NOLNK equ 000000008h
        if (_WIN32_IE ge 0600h)
          SHGNLI_NOLOCNAME equ 000000010h
        endif
        if (NTDDI_VERSION ge NTDDI_WIN7)
          SHGNLI_USEURLEXT equ 000000020h
        endif
      endif
      if (NTDDI_VERSION ge NTDDI_WIN2K)
        PRINTACTION_OPEN equ 0
        PRINTACTION_PROPERTIES equ 1
        PRINTACTION_NETINSTALL equ 2
        PRINTACTION_NETINSTALLLINK equ 3
        PRINTACTION_TESTPAGE equ 4
        PRINTACTION_OPENNETPRN equ 5
        PRINTACTION_DOCUMENTDEFAULTS equ 6
        PRINTACTION_SERVERPROPERTIES equ 7
        @DefProto DllImport, SHInvokePrinterCommandA, WIN_STD_CALL_CONV,, <:HWND, :UINT, :LPCSTR, :LPCSTR, :BOOL>, 20
        @DefProto DllImport, SHInvokePrinterCommandW, WIN_STD_CALL_CONV,, <:HWND, :UINT, :LPCWSTR, :LPCWSTR, :BOOL>, 20
        ifdef UNICODE
          SHInvokePrinterCommand equ <SHInvokePrinterCommandW>
        else
          SHInvokePrinterCommand equ <SHInvokePrinterCommandA>
        endif
      endif
      if (NTDDI_VERSION ge NTDDI_VISTA)
        OPEN_PRINTER_PROPS_INFOA struct
          dwSize DWORD ?
          pszSheetName LPSTR ?
          uSheetIndex UINT ?
          dwFlags DWORD ?
          bModal BOOL ?
        OPEN_PRINTER_PROPS_INFOA ends
        _OPEN_PRINTER_PROPS_INFOA typedef OPEN_PRINTER_PROPS_INFOA
        POPEN_PRINTER_PROPS_INFOA typedef ptr OPEN_PRINTER_PROPS_INFOA
        OPEN_PRINTER_PROPS_INFOW struct
          dwSize DWORD ?
          pszSheetName LPWSTR ?
          uSheetIndex UINT ?
          dwFlags DWORD ?
          bModal BOOL ?
        OPEN_PRINTER_PROPS_INFOW ends
        _OPEN_PRINTER_PROPS_INFOW typedef OPEN_PRINTER_PROPS_INFOW
        POPEN_PRINTER_PROPS_INFOW typedef ptr OPEN_PRINTER_PROPS_INFOW
        ifdef UNICODE
          OPEN_PRINTER_PROPS_INFO typedef OPEN_PRINTER_PROPS_INFOW
          POPEN_PRINTER_PROPS_INFO typedef POPEN_PRINTER_PROPS_INFOW
        else
          OPEN_PRINTER_PROPS_INFO typedef OPEN_PRINTER_PROPS_INFOA
          POPEN_PRINTER_PROPS_INFO typedef POPEN_PRINTER_PROPS_INFOA
        endif
        PRINT_PROP_FORCE_NAME equ 01h
      endif
    endif
    if (NTDDI_VERSION ge NTDDI_WIN2K)
      @DefProto DllImport, SHLoadNonloadedIconOverlayIdentifiers, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, SHIsFileAvailableOffline, WIN_STD_CALL_CONV,, <:PCWSTR, :ptr DWORD>, 8
      OFFLINE_STATUS_LOCAL equ 0001h
      OFFLINE_STATUS_REMOTE equ 0002h
      OFFLINE_STATUS_INCOMPLETE equ 0004h
    endif
    if (NTDDI_VERSION ge NTDDI_WINXP)
      @DefProto DllImport, SHSetLocalizedName, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR, :SDWORD>, 12
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      @DefProto DllImport, SHRemoveLocalizedName, WIN_STD_CALL_CONV,, <:PCWSTR>, 4
      @DefProto DllImport, SHGetLocalizedName, WIN_STD_CALL_CONV,, <:PCWSTR, :PWSTR, :UINT, :ptr SDWORD>, 16
    endif
    if  not Defined(_SHLWAPI_)
      LWSTDAPIV_ macro type_
        exitm <EXTERN_C DECLSPEC_IMPORT type_ STDAPIVCALLTYPE>
      endm
    else
      LWSTDAPIV_ macro type_
        exitm <STDAPIV_(type_)>
      endm
    endif
    @DefProto DllImport, ShellMessageBoxA, c,, <:HINSTANCE, :HWND, :LPCSTR, :LPCSTR, :UINT, :vararg>
    @DefProto DllImport, ShellMessageBoxW, c,, <:HINSTANCE, :HWND, :LPCWSTR, :LPCWSTR, :UINT, :vararg>
    ifdef UNICODE
      ShellMessageBox equ <ShellMessageBoxW>
    else
      ShellMessageBox equ <ShellMessageBoxA>
    endif
    if (NTDDI_VERSION ge NTDDI_WIN2K)
      @DefProto DllImport, IsLFNDriveA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
      @DefProto DllImport, IsLFNDriveW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
      ifdef UNICODE
        IsLFNDrive equ <IsLFNDriveW>
      else
        IsLFNDrive equ <IsLFNDriveA>
      endif
    endif
    if _WIN32_IE ge 0600h
      @DefProto DllImport, SHEnumerateUnreadMailAccountsA, WIN_STD_CALL_CONV,, <:HKEY, :DWORD, :LPSTR, :SDWORD>, 16
      @DefProto DllImport, SHEnumerateUnreadMailAccountsW, WIN_STD_CALL_CONV,, <:HKEY, :DWORD, :LPWSTR, :SDWORD>, 16
      ifdef UNICODE
        SHEnumerateUnreadMailAccounts equ <SHEnumerateUnreadMailAccountsW>
      else
        SHEnumerateUnreadMailAccounts equ <SHEnumerateUnreadMailAccountsA>
      endif
      @DefProto DllImport, SHGetUnreadMailCountA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :ptr DWORD, :ptr FILETIME, :LPSTR, :SDWORD>, 24
      @DefProto DllImport, SHGetUnreadMailCountW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :ptr DWORD, :ptr FILETIME, :LPWSTR, :SDWORD>, 24
      ifdef UNICODE
        SHGetUnreadMailCount equ <SHGetUnreadMailCountW>
      else
        SHGetUnreadMailCount equ <SHGetUnreadMailCountA>
      endif
      @DefProto DllImport, SHSetUnreadMailCountA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :LPCSTR>, 12
      @DefProto DllImport, SHSetUnreadMailCountW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :LPCWSTR>, 12
      ifdef UNICODE
        SHSetUnreadMailCount equ <SHSetUnreadMailCountW>
      else
        SHSetUnreadMailCount equ <SHSetUnreadMailCountA>
      endif
    endif
    if (_WIN32_IE ge 0601h)
      @DefProto DllImport, SHTestTokenMembership, WIN_STD_CALL_CONV,, <:HANDLE, :ULONG>, 8
    endif
    if _WIN32_IE ge 0600h
      if (NTDDI_VERSION ge NTDDI_WINXP)
        @DefProto DllImport, SHGetImageList, WIN_STD_CALL_CONV,, <:SDWORD, :REFIID, :ptr ptr>, 12
      endif
      if (NTDDI_VERSION ge NTDDI_WINXP)
        SHIL_LARGE equ 0
        SHIL_SMALL equ 1
        SHIL_EXTRALARGE equ 2
        SHIL_SYSSMALL equ 3
        if (NTDDI_VERSION ge NTDDI_VISTA)
          SHIL_JUMBO equ 4
          SHIL_LAST equ <SHIL_JUMBO>
        else
          SHIL_LAST equ <SHIL_SYSSMALL>
        endif
      endif
      TYPE_PFNCANSHAREFOLDERW typedef proto WIN_STD_CALL_CONV :PCWSTR
      PFNCANSHAREFOLDERW typedef ptr TYPE_PFNCANSHAREFOLDERW

      TYPE_PFNSHOWSHAREFOLDERUIW typedef proto WIN_STD_CALL_CONV :HWND, :PCWSTR
      PFNSHOWSHAREFOLDERUIW typedef ptr TYPE_PFNSHOWSHAREFOLDERUIW

    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if  not Defined(_WIN64)
    include poppack.inc
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if (NTDDI_VERSION ge NTDDI_VISTA)
      WC_NETADDRESS equ <L("msctls_netaddress")>
      @DefProto DllImport, InitNetworkAddressControl, WIN_STD_CALL_CONV,, <>, 0
      NCM_GETADDRESS equ (WM_USER + 1)
      NetAddr_GetAddress macro hwnd, pv
        exitm <SNDMSG (hwnd, NCM_GETADDRESS, 0, pv)>
      endm
      NC_ADDRESS struct
        pAddrInfo POINTER ?
        PortNumber USHORT ?
        PrefixLength BYTE ?
      NC_ADDRESS ends
      tagNC_ADDRESS typedef NC_ADDRESS
      PNC_ADDRESS typedef ptr NC_ADDRESS
      NCM_SETALLOWTYPE equ (WM_USER + 2)
      NetAddr_SetAllowType macro hwnd, addrMask
        exitm <SNDMSG (hwnd, NCM_SETALLOWTYPE, addrMask, 0)>
      endm
      NCM_GETALLOWTYPE equ (WM_USER + 3)
      NetAddr_GetAllowType macro hwnd
        exitm <SNDMSG (hwnd, NCM_GETALLOWTYPE, 0, 0)>
      endm
      NCM_DISPLAYERRORTIP equ (WM_USER + 4)
      NetAddr_DisplayErrorTip macro hwnd
        exitm <SNDMSG (hwnd, NCM_DISPLAYERRORTIP, 0, 0)>
      endm
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      @DefProto DllImport, SHGetDriveMedia, WIN_STD_CALL_CONV,, <:PCWSTR, :ptr DWORD>, 8
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
    endif
  endif
endif
if Defined(_MSC_VER) and (_MSC_VER ge 1200)
endif
