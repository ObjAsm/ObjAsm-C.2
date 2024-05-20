;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\shellapi.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 21/02/2024 18:22:52

include winapifamily.inc
;*****************************************************************************\
;*                                                                             *
;* shellapi.h -  SHELL.DLL functions, types, and definitions                   *
;*                                                                             *
;* Copyright (c) Microsoft Corporation. All rights reserved.                   *
;*                                                                             *
;\*****************************************************************************
if Defined(_MSC_VER) and (_MSC_VER ge 1200)
  ;* nonstandard extension : single line comment *
  ;* nonstandard extension used : nameless struct/union *
  ;* padding added after data member *
endif
ifndef _INC_SHELLAPI
  _INC_SHELLAPI equ <>
  include SpecStrings.inc
  ; Define API decoration for direct importing of DLL references.
  ifndef WINSHELLAPI
    if  not Defined(_SHELL32_)
      WINSHELLAPI equ <DECLSPEC_IMPORT>
    else
      WINSHELLAPI equ <>
    endif
  endif
  ; WINSHELLAPI
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
  ; SHSTDAPI
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
  ; SHDOCAPI
  if  not Defined(_WIN64)
    include pshpack1.inc
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
    @DefProto DllImport, CommandLineToArgvW, WIN_STD_CALL_CONV,, <:LPCWSTR, :ptr SDWORD>, 8
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_GAMES) *
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
    ; !UNICODE
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
    ; !UNICODE
    ; SE_ERR_DLLNOTFOUND
    @DefProto DllImport, FindExecutableA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :LPSTR>, 12
    ; SE_ERR_DLLNOTFOUND
    @DefProto DllImport, FindExecutableW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPWSTR>, 12
    ifdef UNICODE
      FindExecutable equ <FindExecutableW>
    else
      FindExecutable equ <FindExecutableA>
    endif
    ; !UNICODE
    @DefProto DllImport, ShellAboutA, WIN_STD_CALL_CONV,, <:HWND, :LPCSTR, :LPCSTR, :HICON>, 16
    @DefProto DllImport, ShellAboutW, WIN_STD_CALL_CONV,, <:HWND, :LPCWSTR, :LPCWSTR, :HICON>, 16
    ifdef UNICODE
      ShellAbout equ <ShellAboutW>
    else
      ShellAbout equ <ShellAboutA>
    endif
    ; !UNICODE
    @DefProto DllImport, DuplicateIcon, WIN_STD_CALL_CONV,, <:HINSTANCE, :HICON>, 8
    @DefProto DllImport, ExtractAssociatedIconA, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPSTR, :ptr WORD>, 12
    @DefProto DllImport, ExtractAssociatedIconW, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPWSTR, :ptr WORD>, 12
    ifdef UNICODE
      ExtractAssociatedIcon equ <ExtractAssociatedIconW>
    else
      ExtractAssociatedIcon equ <ExtractAssociatedIconA>
    endif
    ; !UNICODE
    @DefProto DllImport, ExtractAssociatedIconExA, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPSTR, :ptr WORD, :ptr WORD>, 16
    @DefProto DllImport, ExtractAssociatedIconExW, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPWSTR, :ptr WORD, :ptr WORD>, 16
    ifdef UNICODE
      ExtractAssociatedIconEx equ <ExtractAssociatedIconExW>
    else
      ExtractAssociatedIconEx equ <ExtractAssociatedIconExA>
    endif
    ; !UNICODE
    @DefProto DllImport, ExtractIconA, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCSTR, :UINT>, 12
    @DefProto DllImport, ExtractIconW, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCWSTR, :UINT>, 12
    ifdef UNICODE
      ExtractIcon equ <ExtractIconW>
    else
      ExtractIcon equ <ExtractIconA>
    endif
    ; !UNICODE
    if (WINVER ge 0400h)
      DRAGINFOA struct
        uSize DWORD ?
        ;* init with sizeof(DRAGINFO) *
        pt POINT <>
        fNC DWORD ?
        lpFileList PZZSTR ?
        grfKeyState DWORD ?
      DRAGINFOA ends
      _DRAGINFOA typedef DRAGINFOA
      LPDRAGINFOA typedef ptr DRAGINFOA
      DRAGINFOW struct
        uSize DWORD ?
        ;* init with sizeof(DRAGINFO) *
        pt POINT <>
        fNC DWORD ?
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
      ;//
      ;// AppBar stuff
      ;//
      ABM_NEW equ 00000000h
      ABM_REMOVE equ 00000001h
      ABM_QUERYPOS equ 00000002h
      ABM_SETPOS equ 00000003h
      ABM_GETSTATE equ 00000004h
      ABM_GETTASKBARPOS equ 00000005h
      ABM_ACTIVATE equ 00000006h; lParam == TRUE/FALSE means activate/deactivate

      ABM_GETAUTOHIDEBAR equ 00000007h
      ABM_SETAUTOHIDEBAR equ 00000008h; this can fail at any time.  MUST check the result

      ; lParam = TRUE/FALSE  Set/Unset
      ; uEdge = what edge
      ABM_WINDOWPOSCHANGED equ 0000009h
      if (NTDDI_VERSION ge NTDDI_WINXP)
        ABM_SETSTATE equ 0000000ah
      endif
      ; (NTDDI_VERSION >= NTDDI_WINXP)
      if (NTDDI_VERSION ge NTDDI_WIN8)
        ABM_GETAUTOHIDEBAREX equ 0000000bh; multimon aware autohide bars

        ABM_SETAUTOHIDEBAREX equ 0000000ch
      endif
      ; these are put in the wparam of callback messages
      ABN_STATECHANGE equ 0000000h
      ABN_POSCHANGED equ 0000001h
      ABN_FULLSCREENAPP equ 0000002h
      ABN_WINDOWARRANGE equ 0000003h; lParam == TRUE means hide

      ; flags for get state
      ABS_AUTOHIDE equ 0000001h
      ABS_ALWAYSONTOP equ 0000002h
      ABE_LEFT equ 0
      ABE_TOP equ 1
      ABE_RIGHT equ 2
      ABE_BOTTOM equ 3
      APPBARDATA struct
        cbSize DWORD ?
        hWnd HWND ?
        uCallbackMessage DWORD ?
        uEdge DWORD ?
        rc RECT <>
        lParam LPARAM ?
        ; message specific
      APPBARDATA ends
      _AppBarData typedef APPBARDATA
      PAPPBARDATA typedef ptr APPBARDATA
      @DefProto DllImport, SHAppBarMessage, WIN_STD_CALL_CONV,, <:DWORD, :PAPPBARDATA>, 8
      ;//
      ;//  EndAppBar
      ;//
      @DefProto DllImport, DoEnvironmentSubstA, WIN_STD_CALL_CONV,, <:LPSTR, :UINT>, 8
      @DefProto DllImport, DoEnvironmentSubstW, WIN_STD_CALL_CONV,, <:LPWSTR, :UINT>, 8
      ifdef UNICODE
        DoEnvironmentSubst equ <DoEnvironmentSubstW>
      else
        DoEnvironmentSubst equ <DoEnvironmentSubstA>
      endif
      ; !UNICODE
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
      ; !UNICODE
      ; Shell File Operations
      FO_MOVE equ 0001h
      FO_COPY equ 0002h
      FO_DELETE equ 0003h
      FO_RENAME equ 0004h
      ; SHFILEOPSTRUCT.fFlags and IFileOperation::SetOperationFlags() flag values
      FOF_MULTIDESTFILES equ 0001h
      FOF_CONFIRMMOUSE equ 0002h
      FOF_SILENT equ 0004h; don't display progress UI (confirm prompts may be displayed still)

      FOF_RENAMEONCOLLISION equ 0008h; automatically rename the source files to avoid the collisions

      FOF_NOCONFIRMATION equ 0010h; don't display confirmation UI, assume "yes" for cases that can be bypassed, "no" for those that can not

      FOF_WANTMAPPINGHANDLE equ 0020h; Fill in SHFILEOPSTRUCT.hNameMappings

      ; Must be freed using SHFreeNameMappings
      FOF_ALLOWUNDO equ 0040h; enable undo including Recycle behavior for IFileOperation::Delete()

      FOF_FILESONLY equ 0080h; only operate on the files (non folders), both files and folders are assumed without this

      FOF_SIMPLEPROGRESS equ 0100h; means don't show names of files

      FOF_NOCONFIRMMKDIR equ 0200h; don't dispplay confirmatino UI before making any needed directories, assume "Yes" in these cases

      FOF_NOERRORUI equ 0400h; don't put up error UI, other UI may be displayed, progress, confirmations

      FOF_NOCOPYSECURITYATTRIBS equ 0800h; dont copy file security attributes (ACLs)

      FOF_NORECURSION equ 1000h; don't recurse into directories for operations that would recurse

      FOF_NO_CONNECTED_ELEMENTS equ 2000h; don't operate on connected elements ("xxx_files" folders that go with .htm files)

      FOF_WANTNUKEWARNING equ 4000h; during delete operation, warn if object is being permanently destroyed instead of recycling (partially overrides FOF_NOCONFIRMATION)

      if (NTDDI_VERSION ge NTDDI_WINXP)
        FOF_NORECURSEREPARSE equ 8000h; deprecated; the operations engine always does the right thing on FolderLink objects (symlinks, reparse points, folder shortcuts)

      endif
      ; (NTDDI_VERSION >= NTDDI_WINXP)
      FOF_NO_UI equ <(FOF_SILENT or FOF_NOCONFIRMATION or FOF_NOERRORUI or FOF_NOCONFIRMMKDIR)>; don't display any UI at all

      FILEOP_FLAGS typedef WORD
      PO_DELETE equ 0013h; printer is being deleted

      PO_RENAME equ 0014h; printer is being renamed

      PO_PORTCHANGE equ 0020h; port this printer connected to is being changed

      ; if this id is set, the strings received by
      ; the copyhook are a doubly-null terminated
      ; list of strings.  The first is the printer
      ; name and the second is the printer port.
      PO_REN_PORT equ 0034h; PO_RENAME and PO_PORTCHANGE at same time.

      ; no POF_ flags currently defined
      PRINTEROP_FLAGS typedef WORD
      ; implicit parameters are:
      ;      if pFrom or pTo are unqualified names the current directories are
      ;      taken from the global current drive/directory settings managed
      ;      by Get/SetCurrentDrive/Directory
      ;      the global confirmation settings
      SHFILEOPSTRUCTA struct
        hwnd HWND ?
        wFunc DWORD ?
        pFrom PCZZSTR ?
        pTo PCZZSTR ?
        fFlags FILEOP_FLAGS ?
        fAnyOperationsAborted DWORD ?
        hNameMappings POINTER ?
        lpszProgressTitle PCSTR ?
        ; only used if FOF_SIMPLEPROGRESS
      SHFILEOPSTRUCTA ends
      _SHFILEOPSTRUCTA typedef SHFILEOPSTRUCTA
      LPSHFILEOPSTRUCTA typedef ptr SHFILEOPSTRUCTA
      SHFILEOPSTRUCTW struct
        hwnd HWND ?
        wFunc DWORD ?
        pFrom PCZZWSTR ?
        pTo PCZZWSTR ?
        fFlags FILEOP_FLAGS ?
        fAnyOperationsAborted DWORD ?
        hNameMappings POINTER ?
        lpszProgressTitle PCWSTR ?
        ; only used if FOF_SIMPLEPROGRESS
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
      ; !UNICODE
      @DefProto DllImport, SHFreeNameMappings, WIN_STD_CALL_CONV,, <:HANDLE>, 4
      SHNAMEMAPPINGA struct
        pszOldPath POINTER ?
        pszNewPath POINTER ?
        cchOldPath SDWORD ?
        cchNewPath SDWORD ?
      SHNAMEMAPPINGA ends
      _SHNAMEMAPPINGA typedef SHNAMEMAPPINGA
      LPSHNAMEMAPPINGA typedef ptr SHNAMEMAPPINGA
      SHNAMEMAPPINGW struct
        pszOldPath POINTER ?
        pszNewPath POINTER ?
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
      ; UNICODE
      ;//
      ;// End Shell File Operations
      ;//
      ;//
      ;//  Begin ShellExecuteEx and family
      ;//
      ;* ShellExecute() and ShellExecuteEx() error codes *
      ;* regular WinExec() codes *
      SE_ERR_FNF equ 2; file not found

      SE_ERR_PNF equ 3; path not found

      SE_ERR_ACCESSDENIED equ 5; access denied

      SE_ERR_OOM equ 8; out of memory

      SE_ERR_DLLNOTFOUND equ 32
      ;* WINVER >= 0x0400 *
    endif
    ;* error values for ShellExecute() beyond the regular WinExec() codes *
    SE_ERR_SHARE equ 26
    SE_ERR_ASSOCINCOMPLETE equ 27
    SE_ERR_DDETIMEOUT equ 28
    SE_ERR_DDEFAIL equ 29
    SE_ERR_DDEBUSY equ 30
    SE_ERR_NOASSOC equ 31
    if (WINVER ge 0400h)
      ; Note CLASSKEY overrides CLASSNAME
      SEE_MASK_DEFAULT equ 00000000h
      SEE_MASK_CLASSNAME equ 00000001h; SHELLEXECUTEINFO.lpClass is valid

      SEE_MASK_CLASSKEY equ 00000003h; SHELLEXECUTEINFO.hkeyClass is valid

      ; Note SEE_MASK_INVOKEIDLIST(0xC) implies SEE_MASK_IDLIST(0x04)
      SEE_MASK_IDLIST equ 00000004h; SHELLEXECUTEINFO.lpIDList is valid

      SEE_MASK_INVOKEIDLIST equ 0000000ch; enable IContextMenu based verbs

      if (NTDDI_VERSION lt NTDDI_VISTA)
        SEE_MASK_ICON equ 00000010h; not used

      endif
      ; (NTDDI_VERSION < NTDDI_VISTA)
      SEE_MASK_HOTKEY equ 00000020h; SHELLEXECUTEINFO.dwHotKey is valid

      SEE_MASK_NOCLOSEPROCESS equ 00000040h; SHELLEXECUTEINFO.hProcess

      SEE_MASK_CONNECTNETDRV equ 00000080h; enables re-connecting disconnected network drives

      SEE_MASK_NOASYNC equ 00000100h; block on the call until the invoke has completed, use for callers that exit after calling ShellExecuteEx()

      SEE_MASK_FLAG_DDEWAIT equ <SEE_MASK_NOASYNC>; Use SEE_MASK_NOASYNC instead of SEE_MASK_FLAG_DDEWAIT as it more accuratly describes the behavior

      SEE_MASK_DOENVSUBST equ 00000200h; indicates that SHELLEXECUTEINFO.lpFile contains env vars that should be expanded

      SEE_MASK_FLAG_NO_UI equ 00000400h; disable UI including error messages

      SEE_MASK_UNICODE equ 00004000h
      SEE_MASK_NO_CONSOLE equ 00008000h
      SEE_MASK_ASYNCOK equ 00100000h
      if (NTDDI_VERSION ge NTDDI_WIN2K)
        SEE_MASK_HMONITOR equ 00200000h; SHELLEXECUTEINFO.hMonitor

      endif
      ; (NTDDI_VERSION >= NTDDI_WIN2K)
      if (NTDDI_VERSION ge NTDDI_WINXPSP1)
        SEE_MASK_NOZONECHECKS equ 00800000h
      endif
      ; (NTDDI_VERSION >= NTDDI_WINXPSP1)
      if (NTDDI_VERSION ge NTDDI_WIN2K)
        SEE_MASK_NOQUERYCLASSSTORE equ 01000000h
        SEE_MASK_WAITFORINPUTIDLE equ 02000000h
      endif
      ; (NTDDI_VERSION >= NTDDI_WIN2K)
      if (NTDDI_VERSION ge NTDDI_WINXP)
        SEE_MASK_FLAG_LOG_USAGE equ 04000000h
      endif
      ; (NTDDI_VERSION >= NTDDI_WINXP)
      if (NTDDI_VERSION ge NTDDI_VISTA)
        ; When SEE_MASK_FLAG_HINST_IS_SITE is specified SHELLEXECUTEINFO.hInstApp is used as an
        ; _In_ parameter and specifies a IUnknown* to be used as a site pointer. The site pointer
        ; is used to provide services to shell execute, the handler binding process and the verb handlers
        ; once they are invoked.
        SEE_MASK_FLAG_HINST_IS_SITE equ 08000000h
      endif
      ; (NTDDI_VERSION >= NTDDI_VISTA)
      ; For compilers that don't support nameless unions
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
      ; DUMMYUNIONNAME
      ; (NTDDI_VERSION >= NTDDI_WIN2K)
      SHELLEXECUTEINFOA struct
        cbSize DWORD ?
        ; in, required, sizeof of this structure
        fMask DWORD ?
        ; in, SEE_MASK_XXX values
        hwnd HWND ?
        ; in, optional
        lpVerb =POINTER ?
        ; in, optional when unspecified the default verb is choosen
        lpFile =POINTER ?
        ; in, either this value or lpIDList must be specified
        lpParameters =POINTER ?
        ; in, optional
        lpDirectory =POINTER ?
        ; in, optional
        nShow SDWORD ?
        ; in, required
        hInstApp HINSTANCE ?
        ; out when SEE_MASK_NOCLOSEPROCESS is specified
        lpIDList POINTER ?
        ; in, valid when SEE_MASK_IDLIST is specified, PCIDLIST_ABSOLUTE, for use with SEE_MASK_IDLIST & SEE_MASK_INVOKEIDLIST
        lpClass =POINTER ?
        ; in, valid when SEE_MASK_CLASSNAME is specified
        hkeyClass HKEY ?
        ; in, valid when SEE_MASK_CLASSKEY is specified
        dwHotKey DWORD ?
        ; in, valid when SEE_MASK_HOTKEY is specified
        union
          ; (NTDDI_VERSION >= NTDDI_WIN2K)
          hIcon HANDLE ?
          ; not used
          if (NTDDI_VERSION ge NTDDI_WIN2K)
            hMonitor HANDLE ?
            ; in, valid when SEE_MASK_HMONITOR specified
          endif
          ; (NTDDI_VERSION >= NTDDI_WIN2K)
        ends
        hProcess HANDLE ?
        ; out, valid when SEE_MASK_NOCLOSEPROCESS specified
      SHELLEXECUTEINFOA ends
      _SHELLEXECUTEINFOA typedef SHELLEXECUTEINFOA
      LPSHELLEXECUTEINFOA typedef ptr SHELLEXECUTEINFOA
      ; (NTDDI_VERSION >= NTDDI_WIN2K)
      SHELLEXECUTEINFOW struct
        cbSize DWORD ?
        ; in, required, sizeof of this structure
        fMask DWORD ?
        ; in, SEE_MASK_XXX values
        hwnd HWND ?
        ; in, optional
        lpVerb =POINTER ?
        ; in, optional when unspecified the default verb is choosen
        lpFile =POINTER ?
        ; in, either this value or lpIDList must be specified
        lpParameters =POINTER ?
        ; in, optional
        lpDirectory =POINTER ?
        ; in, optional
        nShow SDWORD ?
        ; in, required
        hInstApp HINSTANCE ?
        ; out when SEE_MASK_NOCLOSEPROCESS is specified
        lpIDList POINTER ?
        ; in, valid when SEE_MASK_IDLIST is specified, PCIDLIST_ABSOLUTE, for use with SEE_MASK_IDLIST & SEE_MASK_INVOKEIDLIST
        lpClass =POINTER ?
        ; in, valid when SEE_MASK_CLASSNAME is specified
        hkeyClass HKEY ?
        ; in, valid when SEE_MASK_CLASSKEY is specified
        dwHotKey DWORD ?
        ; in, valid when SEE_MASK_HOTKEY is specified
        union
          ; (NTDDI_VERSION >= NTDDI_WIN2K)
          hIcon HANDLE ?
          ; not used
          if (NTDDI_VERSION ge NTDDI_WIN2K)
            hMonitor HANDLE ?
            ; in, valid when SEE_MASK_HMONITOR specified
          endif
          ; (NTDDI_VERSION >= NTDDI_WIN2K)
        ends
        hProcess HANDLE ?
        ; out, valid when SEE_MASK_NOCLOSEPROCESS specified
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
      ; UNICODE
      @DefProto DllImport, ShellExecuteExA, WIN_STD_CALL_CONV,, <:ptr SHELLEXECUTEINFOA>, 4
      @DefProto DllImport, ShellExecuteExW, WIN_STD_CALL_CONV,, <:ptr SHELLEXECUTEINFOW>, 4
      ifdef UNICODE
        ShellExecuteEx equ <ShellExecuteExW>
      else
        ShellExecuteEx equ <ShellExecuteExA>
      endif
      ; !UNICODE
      if (NTDDI_VERSION ge NTDDI_WIN2K)
        ; deprecated, no longer implemented
        SHCREATEPROCESSINFOW struct
          cbSize DWORD ?
          fMask DWORD ?
          hwnd HWND ?
          pszFile =POINTER ?
          pszParameters =POINTER ?
          pszCurrentDirectory =POINTER ?
          hUserToken HANDLE ?
          lpProcessAttributes LPSECURITY_ATTRIBUTES ?
          lpThreadAttributes LPSECURITY_ATTRIBUTES ?
          bInheritHandles DWORD ?
          dwCreationFlags DWORD ?
          lpStartupInfo LPSTARTUPINFOW ?
          lpProcessInformation LPPROCESS_INFORMATION ?
        SHCREATEPROCESSINFOW ends
        _SHCREATEPROCESSINFOW typedef SHCREATEPROCESSINFOW
        PSHCREATEPROCESSINFOW typedef ptr SHCREATEPROCESSINFOW
        @DefProto DllImport, SHCreateProcessAsUserW, WIN_STD_CALL_CONV,, <:PSHCREATEPROCESSINFOW>, 4
      endif
      ; (NTDDI_VERSION >= NTDDI_WIN2K)
      if (NTDDI_VERSION ge NTDDI_VISTA)
        @DefProto DllImport, SHEvaluateSystemCommandTemplate, WIN_STD_CALL_CONV,, <:PCWSTR, :ptr PWSTR, :ptr PWSTR, :ptr PWSTR>, 16
        ;  SHEvaluateSystemCommandTemplate()
        ;      *   enforces stricter validation before calling CreateProcess().  may also be
        ;              used before calling ShellExecute().
        ;      *   should be used when caller wants the deterministic behavior from a command template
        ;              regardless of execution context.  it ignores the current process state,
        ;              such as the %PATH%, GetCurrentDirectory(), and parent process directory.
        ;      *   should be used when the command is hardcoded.
        ;      *   is used by ShellExecute() when handling file associations from HKCR.
        ;      *   reduces CreateProcess() commandline exploits
        ;      *   is not designed for processing user input, and may generate unexpected failures.
        ;  INPUT:
        ;      pszCmdTemplate =    command line, this may or may not include parameters.
        ;                          if the parameters are substitution parameters then this API
        ;                          should be called before parameters have been replaced.
        ;                          (check the examples below to see sample supported inputs.)
        ;  OUTPUT on return: S_OK
        ;      ppszApplication =   verified path to the Application.  this should be passed as the lpApplication
        ;                          parameter to CreateProcess() or the lpFile parameter to ShellExecute().
        ;                          (allocated using CoTaskMemAlloc(), free with CoTaskMemFree())
        ;      ppszCommandLine =   OPTIONAL - use if planning to call CreateProcess().
        ;                          resulting command line template.  parameters should be replaced based on this template,
        ;                          and then passed as the lpCommandLine parameter to CreateProcess().
        ;                          it is guaranteed to be of a form that PathGetArgs() will always succeed correctly.
        ;                          (allocated using CoTaskMemAlloc(), free with CoTaskMemFree())
        ;      ppszParameters  =   OPTIONAL - use if planning to call ShellExecute().
        ;                          resulting parameter list template.  parameters should be replaced based on this template,
        ;                          and then passed as the lpParameters parameter to ShellExecute().
        ;                          NOTE: identical to PathGetArgs(*ppszCommandLine).
        ;                          (allocated using CoTaskMemAlloc(), free with CoTaskMemFree())
        ;  OUTPUT on return: FAILED()
        ;      all outputs will be NULL'ed on failure
        ;  NOTES:  the parsing logic to determine a valid Application path is non-trivial, although
        ;              the extension is not required and if missing will be completed
        ;              in the following standard order:  { .PIF, .COM, .EXE, .BAT, .CMD }
        ;      Relative Paths are System Paths - if the first token has no path qualifiers
        ;              then the token is first checked to see if a key of the same name has
        ;              been installed under HKLM\Software\Microsoft\Windows\CurrentVersion\App Paths.
        ;              if the key or default value does not exist, it is assumed to be a child
        ;              of the system directories.  the following directories will be searched
        ;              in order for the relative token: { CSIDL_SYSTEM, CSIDL_WINDOWS }
        ;      Prefer Quoted Paths - if the first token in pszCmdTemplate is quoted and appears
        ;              to be an absolute path then the token is the only possible result.
        ;      Limit Forms of Unquoted Paths - if the first token is unquoted and appears
        ;              to be an absolute path, then it is subject to more stringent limitations.
        ;              if the token is a substring of CSIDL_PROGRAM_FILES or does not
        ;              exist on the file system, then SHEvaluateSystemCommandTemplate() will
        ;              attempt to complete using a token delimited by the first space of the
        ;              last valid path segment (usually the file name).  if this token also doesnt exist,
        ;              then the next space will be used, etc.
        ;  USAGE:      used before calling into CreateProcess() or ShellExecute(), callers
        ;              would typically look like the following:
        ;* #if 0 // SAMPLE CODE
        ;HRESULT MyCreateProcessPriv(_In_ PCWSTR pszCmd)
        ;{
        ;PWSTR pszApp;
        ;PWSTR pszCmdLine;
        ;HRESULT hr = SHEvaluateSystemCommandTemplate(pszCmd, &pszApp, &pszCmdLine);
        ;if (SUCCEEDED(hr))
        ;{
        ;  if this was a real template, maybe some kind of wnsprintf() first?
        ;PROCESS_INFORMATION pi;
        ;STARTUPINFO si = {0};
        ;si.cb = sizeof(startup);
        ;si.wShowWindow = SW_SHOWNORMAL;
        ;if (CreateProcess(pszApp, pszCmdLine, NULL, NULL, FALSE,
        ;CREATE_DEFAULT_ERROR_MODE, NULL, NULL, &si, &pi))
        ;{
        ;  we are good
        ;ASSERT(hr == S_OK);
        ;CloseHandle(pi.hProcess);
        ;CloseHandle(pi.hThread);
        ;}
        ;else
        ;{
        ;hr = HRESULT_FROM_WIN32(GetLastError());
        ;}
        ;CoTaskMemFree(pszApp);
        ;CoTaskMemFree(pszCmdLine);
        ;}
        ;return hr;
        ;}
        ;HRESULT MyShellExec(_In_ PCWSTR pszCmd)
        ;{
        ;PWSTR pszApp;
        ;PWSTR pszCmdLine;
        ;HRESULT hr = SHEvaluateSystemCommandTemplate(pszCmd, &pszApp, &pszCmdLine);
        ;if (SUCCEEDED(hr))
        ;{
        ;  if this was a real template, maybe some kind of wnsprintf() first?
        ;SHELLEXECUTEINFOW sei = {
        ;sizeof(sei),           // cbSize;
        ;0,                     // fMask
        ;NULL,                  // hwnd
        ;NULL,                  // lpVerb
        ;pszApp,                // lpFile
        ;PathGetArgs(pszCmdLine), // lpParameters
        ;NULL,                  // lpDirectory
        ;SW_SHOWNORMAL,         // nShow
        ;0,                     // hInstApp
        ;NULL,                  // lpIDList
        ;NULL,                  // lpClass
        ;NULL,                  // hkeyClass
        ;0,                     // dwHotKey
        ;NULL,                  // hIcon
        ;NULL                   // hProcess
        ;};
        ;if (ShellExecuteEx(&sei))
        ;{
        ;  we are good
        ;ASSERT(hr == S_OK);
        ;}
        ;else
        ;{
        ;hr = HRESULT_FROM_WIN32(GetLastError());
        ;}
        ;CoTaskMemFree(pszApp);
        ;CoTaskMemFree(pszCmdLine);
        ;}
        ;return hr;
        ;}
        ;#endif //  0 // SAMPLE CODE
        ;*
        ;  EXAMPLE:   Each example will show an input parameter and the results returned by
        ;              SHEvaluateSystemCommandTemplate().  Also included is the alternate result
        ;              of what CreateProcess() would have created if pszCmdTemplate were
        ;              passed directly as lpCommandLine and lpApplication were NULL.
        ;              (results marked with an asterisk (*) indicate differences.)
        ;          Assume for the examples that the following paths and values exist:
        ;      SHGetFolderPath() values:
        ;          CSIDL_SYSTEM            =   C:\windows\system32
        ;          CSIDL_WINDOWS           =   C:\windows
        ;          CSIDL_PROGRAM_FILES     =   C:\Program Files
        ;      Environment settings
        ;          GetModuleFileName(NULL) =   C:\Program Files\Example\sample.exe
        ;          GetCurrentDirectory()   =   \\server\share\foo
        ;          HKLM\...\App Paths\pbrush.exe = C:\windows\system32\mspaint.exe
        ;          HKLM\...\App Paths\mycl.exe = C:\Program Files\Compilers\mycl.exe
        ;          PATH                    =   c:\windows\system32;C:\windows;c:\;C:\Program Files\Compilers\
        ;      Valid Application paths:
        ;          C:\Program Files\Internet Explorer\iexplore.exe
        ;          C:\windows\system32\rundll32.exe
        ;          C:\windows\system32\notepad.exe
        ;          C:\windows\notepad.exe
        ;          C:\Program Files\Example\sample.exe
        ;          C:\Program Files\Compilers\cl.exe
        ;          C:\Other Programs\prog.exe
        ;      Suspicious (possibly hostile) Application paths:
        ;          C:\Program.exe
        ;          C:\Program Files\Internet.exe
        ;          C:\Program Files\Example\regedit.bat
        ;          C:\mycl.exe
        ;          \\server\share\foo\rundll32.exe
        ;          \\server\share\foo\myapp.exe
        ;  Relative Path Example #1
        ;      pszCmdTemplate      =   notepad.exe %1
        ;          SHEvaluateSystemCommandTemplate() returns: S_OK
        ;              pszApplication  =   C:\windows\system32\notepad.exe
        ;              pszCommandLine  =   "notepad.exe" %1
        ;          CreateProcess() would return TRUE
        ;              new process =   C:\windows\system32\notepad.exe
        ;  Relative Path Example #2
        ;      pszCmdTemplate      =   rundll32.exe shell32.dll,RunDll
        ;          SHEvaluateSystemCommandTemplate() returns: S_OK
        ;              pszApplication  =   C:\windows\system32\rundll32.exe
        ;              pszCommandLine  =   "rundll32.exe" shell32.dll,RunDll
        ;          * CreateProcess() would return TRUE
        ;              new process =   \\server\share\foo\rundll32.exe
        ;  Relative Path Example #3
        ;      pszCmdTemplate      =   regedit %1
        ;          SHEvaluateSystemCommandTemplate() returns: S_OK
        ;              pszApplication  =   C:\windows\system32\regedit.exe
        ;              pszCommandLine  =   "regedit.exe" %1
        ;          * CreateProcess() would return TRUE
        ;              new process =   C:\Program Files\Example\regedit.bat
        ;  Relative Path Example #4
        ;      pszCmdTemplate      =   pbrush "%1"
        ;          SHEvaluateSystemCommandTemplate() returns: S_OK
        ;              pszApplication  =   C:\windows\system32\mspaint.exe
        ;              pszCommandLine  =   "mspaint.exe" "%1"
        ;          * CreateProcess() would return FALSE
        ;  Relative Path Example #5
        ;      pszCmdTemplate      =   mycl "%1" "%2"
        ;          SHEvaluateSystemCommandTemplate() returns: S_OK
        ;              pszApplication  =   C:\Program Files\Compilers\mycl.exe
        ;              pszCommandLine  =   "mycl.exe" "%1" "%2"
        ;          * CreateProcess() would return TRUE
        ;              new process =   C:\mycl.exe
        ;  Relative Path Example #6
        ;      pszCmdTemplate      =   myapp.exe
        ;          SHEvaluateSystemCommandTemplate() returns: CO_E_APPNOTFOUND
        ;          * CreateProcess() would return TRUE
        ;              new process =   \\server\share\foo\myapp.exe
        ;  Quoted Path Example #1
        ;      pszCmdTemplate      =   "C:\Program Files\Internet Explorer\iexplore.exe" -nohome
        ;          SHEvaluateSystemCommandTemplate() returns: S_OK
        ;              pszApplication  =   C:\Program Files\Internet Explorer\iexplore.exe
        ;              pszCommandLine  =   "C:\Program Files\Internet Explorer\iexplore.exe" -nohome
        ;          CreateProcess() would return TRUE
        ;              new process =   C:\Program Files\Internet Explorer\iexplore.exe
        ;  Quoted Path Example #2
        ;      pszCmdTemplate      =   "C:\Program Files\Internet" -url
        ;          SHEvaluateSystemCommandTemplate() returns: S_OK
        ;              pszApplication  =   C:\Program Files\Internet.exe
        ;              pszCommandLine  =   "C:\Program Files\Internet.exe" -url
        ;          CreateProcess() would return TRUE
        ;              new process =   C:\Program Files\internet.exe
        ;  Quoted Path Example #3
        ;      pszCmdTemplate      =   "C:\Program" -url
        ;          SHEvaluateSystemCommandTemplate() returns: S_OK
        ;              pszApplication  =   C:\Program.exe
        ;              pszCommandLine  =   "C:\Program.exe" -url
        ;          CreateProcess() would return TRUE
        ;              new process =   C:\Program.exe
        ;  Unquoted Example #1
        ;      pszCmdTemplate      =   C:\Program Files\Internet Explorer\iexplore.exe -nohome
        ;          SHEvaluateSystemCommandTemplate() returns: S_OK
        ;              pszApplication  =   C:\Program Files\Internet Explorer\iexplore.exe
        ;              pszCommandLine  =   "C:\Program Files\Internet Explorer\iexplore.exe" -nohome
        ;          * CreateProcess() would return TRUE
        ;              new process =   C:\Program.exe
        ;  Unquoted Example #2
        ;      pszCmdTemplate      =   C:\Program Files\Internet Explorer\iexplore.exe -url fool.htm
        ;          SHEvaluateSystemCommandTemplate() returns: S_OK
        ;              pszApplication  =   C:\Program Files\Internet Explorer\iexplore.exe
        ;              pszCommandLine  =   "C:\Program Files\Internet Explorer\iexplore.exe" -url fool.htm
        ;          * CreateProcess() would return TRUE
        ;              new process =   C:\Program.exe
        ;  Unquoted Example #3
        ;      pszCmdTemplate      =   C:\Program Files\Internet Explorer\iexplore.exe -url C:\fool.htm
        ;          SHEvaluateSystemCommandTemplate() returns: S_OK
        ;              pszApplication  =   C:\Program Files\Internet Explorer\iexplore.exe
        ;              pszCommandLine  =   "C:\Program Files\Internet Explorer\iexplore.exe" -url C:\fool.htm
        ;          * CreateProcess() would return TRUE
        ;              new process =   C:\Program.exe
        ;  Unquoted Example #4
        ;      pszCmdTemplate      =   C:\Program Files\Internet -url
        ;          SHEvaluateSystemCommandTemplate() returns: S_OK
        ;              pszApplication  =   C:\Program Files\Internet.exe
        ;              pszCommandLine  =   "C:\Program Files\Internet.exe" -url
        ;          * CreateProcess() would return TRUE
        ;              new process =   C:\Program.exe
        ;  Unquoted Example #5
        ;      pszCmdTemplate      =   C:\Other Programs\prog.exe -go %1 \fool %2
        ;          SHEvaluateSystemCommandTemplate() returns: S_OK
        ;              pszApplication  =   C:\Other Programs\prog.exe
        ;              pszCommandLine  =   "C:\Other Programs\prog.exe" %1 \fool %2
        ;          * CreateProcess() would return TRUE
        ;              new process =   C:\Other Programs\prog.exe
        ;  Unquoted Example #6
        ;      pszCmdTemplate      =   C:\Other Programs\prog.exe -go "\fool" "%1"
        ;          SHEvaluateSystemCommandTemplate() returns: S_OK
        ;              pszApplication  =   C:\Other Programs\prog.exe
        ;              pszCommandLine  =   "C:\Other Programs\prog.exe" -go "\fool" "%1"
        ;          * CreateProcess() would return TRUE
        ;              new process =   C:\Other Programs\prog.exe
        ;  Unquoted Example #7
        ;      pszCmdTemplate      =   C:\Program Files\Internet Explorer\iexplore.exe -url \fool.htm
        ;          SHEvaluateSystemCommandTemplate() returns: CO_E_APPNOTFOUND
        ;          * CreateProcess() would return TRUE
        ;              new process =   C:\Program.exe
        ;  Unquoted Example #8
        ;      pszCmdTemplate      =   C:\Program -url
        ;          SHEvaluateSystemCommandTemplate() returns: CO_E_APPNOTFOUND
        ;          * CreateProcess() would return TRUE
        ;              new process =   C:\Program.exe
        ;  Unquoted Example #9
        ;      pszCmdTemplate      =   C:\Other Programs\prog.exe -go \fool us
        ;          SHEvaluateSystemCommandTemplate() returns: CO_E_APPNOTFOUND
        ;          * CreateProcess() would return TRUE
        ;              new process =   C:\Other Programs\prog.exe
        ;  Unquoted Example #10
        ;      pszCmdTemplate      =   C:\Other Programs\prog.exe -go \fool %1
        ;          SHEvaluateSystemCommandTemplate() returns: CO_E_APPNOTFOUND
        ;          * CreateProcess() would return TRUE
        ;              new process =   C:\Other Programs\prog.exe
        ;  Unquoted Example #11
        ;      pszCmdTemplate      =   C:\Program "%1"
        ;          SHEvaluateSystemCommandTemplate() returns: E_ACCESSDENIED
        ;          * CreateProcess() would return TRUE
        ;              new process =   C:\Program.exe
        ;  Unquoted Example #12
        ;      pszCmdTemplate      =   C:\Program
        ;          SHEvaluateSystemCommandTemplate() returns: E_ACCESSDENIED
        ;          * CreateProcess() would return TRUE
        ;              new process =   C:\Program.exe
        ;  used for implementing IShellFolder::GetUIObject(IID_IQueryAssociations)
        ;  designed for namespace extensions with registered extensible types
        ;  SHCreateDefaultContextMenu() and others use IQueryAssociations to build up data sets
        ASSOCCLASS typedef SDWORD
        ;  which other members are used
        ASSOCCLASS_SHELL_KEY equ 0
        ;  hkeyClass
        ASSOCCLASS_PROGID_KEY equ 1
        ;  hkeyClass
        ASSOCCLASS_PROGID_STR equ 2
        ;  pszClass (HKCR\pszClass)
        ASSOCCLASS_CLSID_KEY equ 3
        ;  hkeyClass
        ASSOCCLASS_CLSID_STR equ 4
        ;  pszClass (HKCR\CLSID\pszClass)
        ASSOCCLASS_APP_KEY equ 5
        ;  hkeyClass
        ASSOCCLASS_APP_STR equ 6
        ;  pszClass (HKCR\Applications\PathFindFileName(pszClass))
        ASSOCCLASS_SYSTEM_STR equ 7
        ;  pszClass
        ASSOCCLASS_FOLDER equ 8
        ;  none
        ASSOCCLASS_STAR equ 9
        ;  none
        if (NTDDI_VERSION ge NTDDI_WIN8)
          ASSOCCLASS_FIXED_PROGID_STR equ 10
          ;  pszClass (HKCR\pszClass), do not apply mapping of pszClass based on user defaults
          ASSOCCLASS_PROTOCOL_STR equ 11
          ;  pszClass is a protocol, apply mapping of pszClass based on user defaults
        endif

        ASSOCIATIONELEMENT struct
          ac ASSOCCLASS ?
          ; required
          hkClass HKEY ?
          ; may be NULL
          pszClass PCWSTR ?
          ; may be NULL
        ASSOCIATIONELEMENT ends
        ; the object returned from this API implements IQueryAssociations
        @DefProto DllImport, AssocCreateForClasses, WIN_STD_CALL_CONV,, <:ptr ASSOCIATIONELEMENT, :ULONG, :REFIID, :ptr ptr>, 16
        ;* #if 0 // SAMPLE CODE
        ;HRESULT CCustomFolder::_AssocCreate(_In_ PCUITEMID_CHILD pidl, _In_ REFIID riid, _Outptr_ void **ppv)
        ;{
        ;*ppv = nullptr;
        ;ASSOCIATIONELEMENT rgAssoc[] =
        ;{
        ;{ ASSOCCLASS_PROGID_STR, nullptr, CCustomFolder::_MapChildToType(pidl)},
        ;{ ASSOCCLASS_FOLDER, nullptr, nullptr},
        ;};
        ;if (CCustomFolder::_IsFolder(pidl))
        ;{
        ;return AssocCreateForClasses(rgAssoc, ARRAYSIZE(rgAssoc), riid, ppv);
        ;}
        ;else
        ;{
        ;  skip FOLDER at the end
        ;return AssocCreateForClasses(rgAssoc, ARRAYSIZE(rgAssoc)-1, riid, ppv);
        ;}
        ;}
        ;HRESULT CCustomFolder::GetUIObjectOf(...)
        ;{
        ;  validate parameters
        ;if (riid == IID_IQueryAssociations)
        ;{
        ;hr = _AssocCreate(apidl[0], riid, ppv);
        ;}
        ;  else if ...
        ;}
        ;#endif // SAMPLE CODE
        ;*
      endif
      ; (NTDDI_VERSION >= NTDDI_VISTA)
      ;//
      ;//  End ShellExecuteEx and family
      ;//
      if (NTDDI_VERSION ge NTDDI_WIN2K)
        ; RecycleBin
        ; struct for query recycle bin info
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
        ; flags for SHEmptyRecycleBin
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
        ; !UNICODE
        @DefProto DllImport, SHEmptyRecycleBinA, WIN_STD_CALL_CONV,, <:HWND, :LPCSTR, :DWORD>, 12
        @DefProto DllImport, SHEmptyRecycleBinW, WIN_STD_CALL_CONV,, <:HWND, :LPCWSTR, :DWORD>, 12
        ifdef UNICODE
          SHEmptyRecycleBin equ <SHEmptyRecycleBinW>
        else
          SHEmptyRecycleBin equ <SHEmptyRecycleBinA>
        endif
        ; !UNICODE
        ;//
        ;// end of RecycleBin
      endif
      ; (NTDDI_VERSION >= NTDDI_WIN2K)
      ;//
      ;// Taskbar notification definitions
      ;//
      if (NTDDI_VERSION ge NTDDI_VISTA)
        QUERY_USER_NOTIFICATION_STATE typedef SDWORD
        QUNS_NOT_PRESENT equ 1
        ; The user is not present.  Heuristic check for modes like: screen saver, locked machine, non-active FUS session
        QUNS_BUSY equ 2
        ; The user is busy.  Heuristic check for modes like: full-screen app
        QUNS_RUNNING_D3D_FULL_SCREEN equ 3
        ; full-screen (exlusive-mode) D3D app
        QUNS_PRESENTATION_MODE equ 4
        ; Windows presentation mode (laptop feature) is turned on
        QUNS_ACCEPTS_NOTIFICATIONS equ 5
        ; notifications can be freely sent
        if (NTDDI_VERSION ge NTDDI_WIN7)
          QUNS_QUIET_TIME equ 6
          ; We are in OOBE quiet period
        endif
        if (NTDDI_VERSION ge NTDDI_WIN8)
          QUNS_APP equ 7
          ; App-mode application
        endif

        @DefProto DllImport, SHQueryUserNotificationState, WIN_STD_CALL_CONV,, <:ptr QUERY_USER_NOTIFICATION_STATE>, 4
      endif
      ; (NTDDI_VERSION >= NTDDI_VISTA)
      if (NTDDI_VERSION ge NTDDI_WIN7)
        ; This api retrieves an IPropertyStore that stores the window's properties.
        @DefProto DllImport, SHGetPropertyStoreForWindow, WIN_STD_CALL_CONV,, <:HWND, :REFIID, :ptr ptr>, 12
      endif
      NOTIFYICONDATAA struct
        cbSize DWORD ?
        hWnd HWND ?
        uID DWORD ?
        uFlags DWORD ?
        uCallbackMessage DWORD ?
        hIcon HICON ?
        if (NTDDI_VERSION lt NTDDI_WIN2K)
          szTip SBYTE 64 dup (?)
        endif
        if (NTDDI_VERSION ge NTDDI_WIN2K)
          szTip SBYTE 128 dup (?)
          dwState DWORD ?
          dwStateMask DWORD ?
          szInfo SBYTE 256 dup (?)
          ifndef _SHELL_EXPORTS_INTERNALAPI_H_
            union
              uTimeout DWORD ?
              uVersion DWORD ?
              ; used with NIM_SETVERSION, values 0, 3 and 4
            ends
          endif
          szInfoTitle SBYTE 64 dup (?)
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
        uID DWORD ?
        uFlags DWORD ?
        uCallbackMessage DWORD ?
        hIcon HICON ?
        if (NTDDI_VERSION lt NTDDI_WIN2K)
          szTip WORD 64 dup (?)
        endif
        if (NTDDI_VERSION ge NTDDI_WIN2K)
          szTip WORD 128 dup (?)
          dwState DWORD ?
          dwStateMask DWORD ?
          szInfo WORD 256 dup (?)
          ifndef _SHELL_EXPORTS_INTERNALAPI_H_
            union
              uTimeout DWORD ?
              uVersion DWORD ?
              ; used with NIM_SETVERSION, values 0, 3 and 4
            ends
          endif
          szInfoTitle WORD 64 dup (?)
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
      ; UNICODE
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
      ; (NTDDI_VERSION >= NTDDI_VISTA)
      if (NTDDI_VERSION ge NTDDI_WIN7)
      endif
      ; (NTDDI_VERSION >= NTDDI_WIN7)
      NIM_ADD equ 00000000h
      NIM_MODIFY equ 00000001h
      NIM_DELETE equ 00000002h
      NIM_SETFOCUS equ 00000003h
      NIM_SETVERSION equ 00000004h
      ; set NOTIFYICONDATA.uVersion with 0, 3 or 4
      ; please read the documentation on the behavior difference that the different versions imply
      NOTIFYICON_VERSION equ 3
      if (NTDDI_VERSION ge NTDDI_VISTA)
        NOTIFYICON_VERSION_4 equ 4
      endif
      ; (NTDDI_VERSION >= NTDDI_VISTA)
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
      ; (NTDDI_VERSION >= NTDDI_VISTA)
      NIS_HIDDEN equ 00000001h
      NIS_SHAREDICON equ 00000002h
      ; says this is the source of a shared icon
      ; Notify Icon Infotip flags
      NIIF_NONE equ 00000000h
      ; icon flags are mutually exclusive
      ; and take only the lowest 2 bits
      NIIF_INFO equ 00000001h
      NIIF_WARNING equ 00000002h
      NIIF_ERROR equ 00000003h
      if (NTDDI_VERSION ge NTDDI_WINXPSP2)
        ; also available in NTDDI_WS03SP1
        NIIF_USER equ 00000004h
      endif
      ; (NTDDI_VERSION >= NTDDI_WINXPSP2)
      NIIF_ICON_MASK equ 0000000Fh
      NIIF_NOSOUND equ 00000010h
      if (NTDDI_VERSION ge NTDDI_VISTA)
        NIIF_LARGE_ICON equ 00000020h
      endif
      ; (NTDDI_VERSION >= NTDDI_VISTA)
      if (NTDDI_VERSION ge NTDDI_WIN7)
        NIIF_RESPECT_QUIET_TIME equ 00000080h
      endif
      ; (NTDDI_VERSION >= NTDDI_WIN7)
      NOTIFYICONIDENTIFIER struct
        cbSize DWORD ?
        hWnd HWND ?
        uID DWORD ?
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
      ; !UNICODE
      if (NTDDI_VERSION ge NTDDI_WIN7)
        @DefProto DllImport, Shell_NotifyIconGetRect, WIN_STD_CALL_CONV,, <:ptr NOTIFYICONIDENTIFIER, :ptr RECT>, 8
      endif
      ; (NTDDI_VERSION >= NTDDI_WIN7)
      ;//
      ;// End Taskbar Notification Icons
      ;//
      ifndef SHFILEINFO_DEFINED
        SHFILEINFO_DEFINED equ <>
        ;//
        ;// Begin SHGetFileInfo
        ;//
        ;*
        ;* The SHGetFileInfo API provides an easy way to get attributes
        ;* for a file given a pathname.
        ;*
        ;*   PARAMETERS
        ;*
        ;*     pszPath              file name to get info about
        ;*     dwFileAttributes     file attribs, only used with SHGFI_USEFILEATTRIBUTES
        ;*     psfi                 place to return file info
        ;*     cbFileInfo           size of structure
        ;*     uFlags               flags
        ;*
        ;*   RETURN
        ;*     TRUE if things worked
        ;*
        SHFILEINFOA struct
          hIcon HICON ?
          ; out: icon
          iIcon SDWORD ?
          ; out: icon index
          dwAttributes DWORD ?
          ; out: SFGAO_ flags
          szDisplayName SBYTE MAX_PATH dup (?)
          ; out: display name (or path)
          szTypeName SBYTE 80 dup (?)
          ; out: type name
        SHFILEINFOA ends
        _SHFILEINFOA typedef SHFILEINFOA
        SHFILEINFOW struct
          hIcon HICON ?
          ; out: icon
          iIcon SDWORD ?
          ; out: icon index
          dwAttributes DWORD ?
          ; out: SFGAO_ flags
          szDisplayName WORD MAX_PATH dup (?)
          ; out: display name (or path)
          szTypeName WORD 80 dup (?)
          ; out: type name
        SHFILEINFOW ends
        _SHFILEINFOW typedef SHFILEINFOW
        ifdef UNICODE
          SHFILEINFO typedef SHFILEINFOW
        else
          SHFILEINFO typedef SHFILEINFOA
        endif
        ; UNICODE
        ; NOTE: This is also in shlwapi.h.  Please keep in synch.
      endif
      ; !SHFILEINFO_DEFINED
      SHGFI_ICON equ 000000100h; get icon

      SHGFI_DISPLAYNAME equ 000000200h; get display name

      SHGFI_TYPENAME equ 000000400h; get type name

      SHGFI_ATTRIBUTES equ 000000800h; get attributes

      SHGFI_ICONLOCATION equ 000001000h; get icon location

      SHGFI_EXETYPE equ 000002000h; return exe type

      SHGFI_SYSICONINDEX equ 000004000h; get system icon index

      SHGFI_LINKOVERLAY equ 000008000h; put a link overlay on icon

      SHGFI_SELECTED equ 000010000h; show icon in selected state

      if (NTDDI_VERSION ge NTDDI_WIN2K)
        SHGFI_ATTR_SPECIFIED equ 000020000h; get only specified attributes

      endif
      ; (NTDDI_VERSION >= NTDDI_WIN2K)
      SHGFI_LARGEICON equ 000000000h; get large icon

      SHGFI_SMALLICON equ 000000001h; get small icon

      SHGFI_OPENICON equ 000000002h; get open icon

      SHGFI_SHELLICONSIZE equ 000000004h; get shell size icon

      SHGFI_PIDL equ 000000008h; pszPath is a pidl

      SHGFI_USEFILEATTRIBUTES equ 000000010h; use passed dwFileAttribute

      SHGFI_ADDOVERLAYS equ 000000020h; apply the appropriate overlays

      SHGFI_OVERLAYINDEX equ 000000040h; Get the index of the overlay

      ; in the upper 8 bits of the iIcon
      @DefProto DllImport, SHGetFileInfoA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :ptr SHFILEINFOA, :UINT, :UINT>, 20
      @DefProto DllImport, SHGetFileInfoW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :ptr SHFILEINFOW, :UINT, :UINT>, 20
      ifdef UNICODE
        SHGetFileInfo equ <SHGetFileInfoW>
      else
        SHGetFileInfo equ <SHGetFileInfoA>
      endif
      ; !UNICODE
      if (NTDDI_VERSION ge NTDDI_VISTA)
        SHSTOCKICONINFO struct
          cbSize DWORD ?
          hIcon HICON ?
          iSysImageIndex SDWORD ?
          iIcon SDWORD ?
          szPath WORD MAX_PATH dup (?)
        SHSTOCKICONINFO ends
        _SHSTOCKICONINFO typedef SHSTOCKICONINFO
        SHGSI_ICONLOCATION equ 0; you always get the icon location

        SHGSI_ICON equ <SHGFI_ICON>
        SHGSI_SYSICONINDEX equ <SHGFI_SYSICONINDEX>
        SHGSI_LINKOVERLAY equ <SHGFI_LINKOVERLAY>
        SHGSI_SELECTED equ <SHGFI_SELECTED>
        SHGSI_LARGEICON equ <SHGFI_LARGEICON>
        SHGSI_SMALLICON equ <SHGFI_SMALLICON>
        SHGSI_SHELLICONSIZE equ <SHGFI_SHELLICONSIZE>
        ;  Shell icons
        SHSTOCKICONID typedef SDWORD
        SIID_DOCNOASSOC equ 0
        ; document (blank page), no associated program
        SIID_DOCASSOC equ 1
        ; document with an associated program
        SIID_APPLICATION equ 2
        ; generic application with no custom icon
        SIID_FOLDER equ 3
        ; folder (closed)
        SIID_FOLDEROPEN equ 4
        ; folder (open)
        SIID_DRIVE525 equ 5
        ; 5.25" floppy disk drive
        SIID_DRIVE35 equ 6
        ; 3.5" floppy disk drive
        SIID_DRIVEREMOVE equ 7
        ; removable drive
        SIID_DRIVEFIXED equ 8
        ; fixed (hard disk) drive
        SIID_DRIVENET equ 9
        ; network drive
        SIID_DRIVENETDISABLED equ 10
        ; disconnected network drive
        SIID_DRIVECD equ 11
        ; CD drive
        SIID_DRIVERAM equ 12
        ; RAM disk drive
        SIID_WORLD equ 13
        ; entire network
        SIID_SERVER equ 15
        ; a computer on the network
        SIID_PRINTER equ 16
        ; printer
        SIID_MYNETWORK equ 17
        ; My network places
        SIID_FIND equ 22
        ; Find
        SIID_HELP equ 23
        ; Help
        SIID_SHARE equ 28
        ; overlay for shared items
        SIID_LINK equ 29
        ; overlay for shortcuts to items
        SIID_SLOWFILE equ 30
        ; overlay for slow items
        SIID_RECYCLER equ 31
        ; empty recycle bin
        SIID_RECYCLERFULL equ 32
        ; full recycle bin
        SIID_MEDIACDAUDIO equ 40
        ; Audio CD Media
        SIID_LOCK equ 47
        ; Security lock
        SIID_AUTOLIST equ 49
        ; AutoList
        SIID_PRINTERNET equ 50
        ; Network printer
        SIID_SERVERSHARE equ 51
        ; Server share
        SIID_PRINTERFAX equ 52
        ; Fax printer
        SIID_PRINTERFAXNET equ 53
        ; Networked Fax Printer
        SIID_PRINTERFILE equ 54
        ; Print to File
        SIID_STACK equ 55
        ; Stack
        SIID_MEDIASVCD equ 56
        ; SVCD Media
        SIID_STUFFEDFOLDER equ 57
        ; Folder containing other items
        SIID_DRIVEUNKNOWN equ 58
        ; Unknown drive
        SIID_DRIVEDVD equ 59
        ; DVD Drive
        SIID_MEDIADVD equ 60
        ; DVD Media
        SIID_MEDIADVDRAM equ 61
        ; DVD-RAM Media
        SIID_MEDIADVDRW equ 62
        ; DVD-RW Media
        SIID_MEDIADVDR equ 63
        ; DVD-R Media
        SIID_MEDIADVDROM equ 64
        ; DVD-ROM Media
        SIID_MEDIACDAUDIOPLUS equ 65
        ; CD+ (Enhanced CD) Media
        SIID_MEDIACDRW equ 66
        ; CD-RW Media
        SIID_MEDIACDR equ 67
        ; CD-R Media
        SIID_MEDIACDBURN equ 68
        ; Burning CD
        SIID_MEDIABLANKCD equ 69
        ; Blank CD Media
        SIID_MEDIACDROM equ 70
        ; CD-ROM Media
        SIID_AUDIOFILES equ 71
        ; Audio files
        SIID_IMAGEFILES equ 72
        ; Image files
        SIID_VIDEOFILES equ 73
        ; Video files
        SIID_MIXEDFILES equ 74
        ; Mixed files
        SIID_FOLDERBACK equ 75
        ; Folder back
        SIID_FOLDERFRONT equ 76
        ; Folder front
        SIID_SHIELD equ 77
        ; Security shield. Use for UAC prompts only.
        SIID_WARNING equ 78
        ; Warning
        SIID_INFO equ 79
        ; Informational
        SIID_ERROR equ 80
        ; Error
        SIID_KEY equ 81
        ; Key / Secure
        SIID_SOFTWARE equ 82
        ; Software
        SIID_RENAME equ 83
        ; Rename
        SIID_DELETE equ 84
        ; Delete
        SIID_MEDIAAUDIODVD equ 85
        ; Audio DVD Media
        SIID_MEDIAMOVIEDVD equ 86
        ; Movie DVD Media
        SIID_MEDIAENHANCEDCD equ 87
        ; Enhanced CD Media
        SIID_MEDIAENHANCEDDVD equ 88
        ; Enhanced DVD Media
        SIID_MEDIAHDDVD equ 89
        ; HD-DVD Media
        SIID_MEDIABLURAY equ 90
        ; BluRay Media
        SIID_MEDIAVCD equ 91
        ; VCD Media
        SIID_MEDIADVDPLUSR equ 92
        ; DVD+R Media
        SIID_MEDIADVDPLUSRW equ 93
        ; DVD+RW Media
        SIID_DESKTOPPC equ 94
        ; desktop computer
        SIID_MOBILEPC equ 95
        ; mobile computer (laptop/notebook)
        SIID_USERS equ 96
        ; users
        SIID_MEDIASMARTMEDIA equ 97
        ; Smart Media
        SIID_MEDIACOMPACTFLASH equ 98
        ; Compact Flash
        SIID_DEVICECELLPHONE equ 99
        ; Cell phone
        SIID_DEVICECAMERA equ 100
        ; Camera
        SIID_DEVICEVIDEOCAMERA equ 101
        ; Video camera
        SIID_DEVICEAUDIOPLAYER equ 102
        ; Audio player
        SIID_NETWORKCONNECT equ 103
        ; Connect to network
        SIID_INTERNET equ 104
        ; Internet
        SIID_ZIPFILE equ 105
        ; ZIP file
        SIID_SETTINGS equ 106
        ; Settings
        ; 107-131 are internal Vista RTM icons
        ; 132-159 for SP1 icons
        SIID_DRIVEHDDVD equ 132
        ; HDDVD Drive (all types)
        SIID_DRIVEBD equ 133
        ; BluRay Drive (all types)
        SIID_MEDIAHDDVDROM equ 134
        ; HDDVD-ROM Media
        SIID_MEDIAHDDVDR equ 135
        ; HDDVD-R Media
        SIID_MEDIAHDDVDRAM equ 136
        ; HDDVD-RAM Media
        SIID_MEDIABDROM equ 137
        ; BluRay ROM Media
        SIID_MEDIABDR equ 138
        ; BluRay R Media
        SIID_MEDIABDRE equ 139
        ; BluRay RE Media (Rewriable and RAM)
        SIID_CLUSTEREDDRIVE equ 140
        ; Clustered disk
        ; 160+ are for Windows 7 icons
        SIID_MAX_ICONS equ 181

        SIID_INVALID equ ((SHSTOCKICONID) - 1)
        @DefProto DllImport, SHGetStockIconInfo, WIN_STD_CALL_CONV,, <:SHSTOCKICONID, :UINT, :ptr SHSTOCKICONINFO>, 12
      endif
      ; (NTDDI_VERSION >= NTDDI_VISTA)
      if (NTDDI_VERSION ge NTDDI_WIN2K)
        SHGetDiskFreeSpace equ <SHGetDiskFreeSpaceEx>
        @DefProto DllImport, SHGetDiskFreeSpaceExA, WIN_STD_CALL_CONV,, <:LPCSTR, :ptr ULARGE_INTEGER, :ptr ULARGE_INTEGER, :ptr ULARGE_INTEGER>, 16
        @DefProto DllImport, SHGetDiskFreeSpaceExW, WIN_STD_CALL_CONV,, <:LPCWSTR, :ptr ULARGE_INTEGER, :ptr ULARGE_INTEGER, :ptr ULARGE_INTEGER>, 16
        ifdef UNICODE
          SHGetDiskFreeSpaceEx equ <SHGetDiskFreeSpaceExW>
        else
          SHGetDiskFreeSpaceEx equ <SHGetDiskFreeSpaceExA>
        endif
        ; !UNICODE
        @DefProto DllImport, SHGetNewLinkInfoA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :LPSTR, :ptr BOOL, :UINT>, 20
        @DefProto DllImport, SHGetNewLinkInfoW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPWSTR, :ptr BOOL, :UINT>, 20
        ifdef UNICODE
          SHGetNewLinkInfo equ <SHGetNewLinkInfoW>
        else
          SHGetNewLinkInfo equ <SHGetNewLinkInfoA>
        endif
        ; !UNICODE
        SHGNLI_PIDL equ 000000001h; pszLinkTo is a pidl

        SHGNLI_PREFIXNAME equ 000000002h; Make name "Shortcut to xxx"

        SHGNLI_NOUNIQUE equ 000000004h; don't do the unique name generation

        SHGNLI_NOLNK equ 000000008h; don't add ".lnk" extension

        if (_WIN32_IE ge 0600h)
          SHGNLI_NOLOCNAME equ 000000010h; use non localized (parsing) name from the target

        endif
        if (NTDDI_VERSION ge NTDDI_WIN7)
          SHGNLI_USEURLEXT equ 000000020h; use ".url" extension instead of ".lnk"

        endif
      endif
      ; (NTDDI_VERSION >= NTDDI_WIN2K)
      if (NTDDI_VERSION ge NTDDI_WIN2K)
        PRINTACTION_OPEN equ 0; pszBuf1:<PrinterName>

        PRINTACTION_PROPERTIES equ 1; pszBuf1:<PrinterName>, pszBuf2:optional <PageName>

        PRINTACTION_NETINSTALL equ 2; pszBuf1:<NetPrinterName>

        PRINTACTION_NETINSTALLLINK equ 3; pszBuf1:<NetPrinterName>, pszBuf2:<path to store link>

        PRINTACTION_TESTPAGE equ 4; pszBuf1:<PrinterName>

        PRINTACTION_OPENNETPRN equ 5; pszBuf1:<NetPrinterName>

        PRINTACTION_DOCUMENTDEFAULTS equ 6; pszBuf1:<PrinterName>

        PRINTACTION_SERVERPROPERTIES equ 7; pszBuf1:<Server> or <NetPrinterName>

        ; deprecated, instead invoke verbs on printers/netprinters using IContextMenu or ShellExecute()
        @DefProto DllImport, SHInvokePrinterCommandA, WIN_STD_CALL_CONV,, <:HWND, :UINT, :LPCSTR, :LPCSTR, :BOOL>, 20
        @DefProto DllImport, SHInvokePrinterCommandW, WIN_STD_CALL_CONV,, <:HWND, :UINT, :LPCWSTR, :LPCWSTR, :BOOL>, 20
        ifdef UNICODE
          SHInvokePrinterCommand equ <SHInvokePrinterCommandW>
        else
          SHInvokePrinterCommand equ <SHInvokePrinterCommandA>
        endif
        ; !UNICODE
      endif
      ; (NTDDI_VERSION >= NTDDI_WIN2K)
      if (NTDDI_VERSION ge NTDDI_VISTA)
        OPEN_PRINTER_PROPS_INFOA struct
          dwSize DWORD ?
          pszSheetName POINTER ?
          uSheetIndex DWORD ?
          dwFlags DWORD ?
          bModal DWORD ?
        OPEN_PRINTER_PROPS_INFOA ends
        _OPEN_PRINTER_PROPS_INFOA typedef OPEN_PRINTER_PROPS_INFOA
        POPEN_PRINTER_PROPS_INFOA typedef ptr OPEN_PRINTER_PROPS_INFOA
        OPEN_PRINTER_PROPS_INFOW struct
          dwSize DWORD ?
          pszSheetName POINTER ?
          uSheetIndex DWORD ?
          dwFlags DWORD ?
          bModal DWORD ?
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
        ; UNICODE
        PRINT_PROP_FORCE_NAME equ 01h
      endif
      ; (NTDDI_VERSION >= NTDDI_WIN2K)
      ;* WINVER >= 0x0400 *
    endif
    if (NTDDI_VERSION ge NTDDI_WIN2K)
      ; The SHLoadNonloadedIconOverlayIdentifiers API causes the shell's
      ; icon overlay manager to load any registered icon overlay
      ; identifers that are not currently loaded.  This is useful if an
      ; overlay identifier did not load at shell startup but is needed
      ; and can be loaded at a later time.  Identifiers already loaded
      ; are not affected.  Overlay identifiers implement the
      ; IShellIconOverlayIdentifier interface.
      ; Returns:
      ;      S_OK
      @DefProto DllImport, SHLoadNonloadedIconOverlayIdentifiers, WIN_STD_CALL_CONV,, <>, 0
      ; The SHIsFileAvailableOffline API determines whether a file
      ; or folder is available for offline use.
      ; Parameters:
      ;     pwszPath             file name to get info about
      ;     pdwStatus            (optional) OFFLINE_STATUS_* flags returned here
      ; Returns:
      ;     S_OK                 File/directory is available offline, unless
      ;                            OFFLINE_STATUS_INCOMPLETE is returned.
      ;     E_INVALIDARG         Path is invalid, or not a net path
      ;     E_FAIL               File/directory is not available offline
      ; Notes:
      ;     OFFLINE_STATUS_INCOMPLETE is never returned for directories.
      ;     Both OFFLINE_STATUS_LOCAL and OFFLINE_STATUS_REMOTE may be returned,
      ;     indicating "open in both places." This is common when the server is online.
      @DefProto DllImport, SHIsFileAvailableOffline, WIN_STD_CALL_CONV,, <:PCWSTR, :ptr DWORD>, 8
      OFFLINE_STATUS_LOCAL equ 0001h; If open, it's open locally

      OFFLINE_STATUS_REMOTE equ 0002h; If open, it's open remotely

      OFFLINE_STATUS_INCOMPLETE equ 0004h; The local copy is currently imcomplete.

      ; The file will not be available offline
      ; until it has been synchronized.
    endif
    if (NTDDI_VERSION ge NTDDI_WINXP)
      ;  sets the specified path to use the string resource
      ;  as the UI instead of the file system name
      @DefProto DllImport, SHSetLocalizedName, WIN_STD_CALL_CONV,, <:PCWSTR, :PCWSTR, :SDWORD>, 12
    endif
    ; (NTDDI_VERSION >= NTDDI_WINXP)
    if (NTDDI_VERSION ge NTDDI_VISTA)
      ;  sets the specified path to use the string resource
      ;  as the UI instead of the file system name
      @DefProto DllImport, SHRemoveLocalizedName, WIN_STD_CALL_CONV,, <:PCWSTR>, 4
      ;  gets the string resource for the specified path
      @DefProto DllImport, SHGetLocalizedName, WIN_STD_CALL_CONV,, <:PCWSTR, :PWSTR, :UINT, :ptr SDWORD>, 16
    endif
    ; (NTDDI_VERSION >= NTDDI_VISTA)
    ;====== ShellMessageBox ================================================
    ; If lpcTitle is NULL, the title is taken from hWnd
    ; If lpcText is NULL, this is assumed to be an Out Of Memory message
    ; If the selector of lpcTitle or lpcText is NULL, the offset should be a
    ;     string resource ID
    ; The variable arguments must all be 32-bit values (even if fewer bits
    ;     are actually used)
    ; lpcText (or whatever string resource it causes to be loaded) should
    ;     be a formatting string similar to wsprintf except that only the
    ;     following formats are available:
    ;         %%              formats to a single '%'
    ;         %nn%s           the nn-th arg is a string which is inserted
    ;         %nn%ld          the nn-th arg is a DWORD, and formatted decimal
    ;         %nn%lx          the nn-th arg is a DWORD, and formatted hex
    ;     note that lengths are allowed on the %s, %ld, and %lx, just
    ;                         like wsprintf
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
    ; !UNICODE
    if (NTDDI_VERSION ge NTDDI_WIN2K)
      @DefProto DllImport, IsLFNDriveA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
      @DefProto DllImport, IsLFNDriveW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
      ifdef UNICODE
        IsLFNDrive equ <IsLFNDriveW>
      else
        IsLFNDrive equ <IsLFNDriveA>
      endif
      ; !UNICODE
    endif
    ; (NTDDI_VERSION >= NTDDI_WIN2K)
    if _WIN32_IE ge 0600h
      @DefProto DllImport, SHEnumerateUnreadMailAccountsA, WIN_STD_CALL_CONV,, <:HKEY, :DWORD, :LPSTR, :SDWORD>, 16
      @DefProto DllImport, SHEnumerateUnreadMailAccountsW, WIN_STD_CALL_CONV,, <:HKEY, :DWORD, :LPWSTR, :SDWORD>, 16
      ifdef UNICODE
        SHEnumerateUnreadMailAccounts equ <SHEnumerateUnreadMailAccountsW>
      else
        SHEnumerateUnreadMailAccounts equ <SHEnumerateUnreadMailAccountsA>
      endif
      ; !UNICODE
      @DefProto DllImport, SHGetUnreadMailCountA, WIN_STD_CALL_CONV,, <:HKEY, :LPCSTR, :ptr DWORD, :ptr FILETIME, :LPSTR, :SDWORD>, 24
      @DefProto DllImport, SHGetUnreadMailCountW, WIN_STD_CALL_CONV,, <:HKEY, :LPCWSTR, :ptr DWORD, :ptr FILETIME, :LPWSTR, :SDWORD>, 24
      ifdef UNICODE
        SHGetUnreadMailCount equ <SHGetUnreadMailCountW>
      else
        SHGetUnreadMailCount equ <SHGetUnreadMailCountA>
      endif
      ; !UNICODE
      @DefProto DllImport, SHSetUnreadMailCountA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :LPCSTR>, 12
      @DefProto DllImport, SHSetUnreadMailCountW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :LPCWSTR>, 12
      ifdef UNICODE
        SHSetUnreadMailCount equ <SHSetUnreadMailCountW>
      else
        SHSetUnreadMailCount equ <SHSetUnreadMailCountA>
      endif
      ; !UNICODE
      ;*  _WIN32_IE >= 0x0600     *
    endif
    if (_WIN32_IE ge 0601h)
      @DefProto DllImport, SHTestTokenMembership, WIN_STD_CALL_CONV,, <:HANDLE, :ULONG>, 8
    endif
    ; (_WIN32_IE >= 0x0601)
    if _WIN32_IE ge 0600h
      if (NTDDI_VERSION ge NTDDI_WINXP)
        @DefProto DllImport, SHGetImageList, WIN_STD_CALL_CONV,, <:SDWORD, :REFIID, :ptr ptr>, 12
      endif
      ; (NTDDI_VERSION >= NTDDI_WINXP)
      if (NTDDI_VERSION ge NTDDI_WINXP)
        SHIL_LARGE equ 0; normally 32x32

        SHIL_SMALL equ 1; normally 16x16

        SHIL_EXTRALARGE equ 2
        SHIL_SYSSMALL equ 3; like SHIL_SMALL, but tracks system small icon metric correctly

        if (NTDDI_VERSION ge NTDDI_VISTA)
          SHIL_JUMBO equ 4; normally 256x256

          SHIL_LAST equ <SHIL_JUMBO>
        else
          SHIL_LAST equ <SHIL_SYSSMALL>
        endif
        ; (NTDDI_VERSION >= NTDDI_VISTA)
      endif
      ; (NTDDI_VERSION >= NTDDI_WINXP)
      ; Function call types for ntshrui folder sharing helpers
      TYPE_PFNCANSHAREFOLDERW typedef proto WIN_STD_CALL_CONV :PCWSTR
      PFNCANSHAREFOLDERW typedef ptr TYPE_PFNCANSHAREFOLDERW

      TYPE_PFNSHOWSHAREFOLDERUIW typedef proto WIN_STD_CALL_CONV :HWND, :PCWSTR
      PFNSHOWSHAREFOLDERUIW typedef ptr TYPE_PFNSHOWSHAREFOLDERUIW

      ;*  _WIN32_IE >= 0x0600     *
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if  not Defined(_WIN64)
    include poppack.inc
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if (NTDDI_VERSION ge NTDDI_VISTA)
      ; API for new Network Address Control
      ; Instantiation
      WC_NETADDRESS equ <L("msctls_netaddress")>
      @DefProto DllImport, InitNetworkAddressControl, WIN_STD_CALL_CONV,, <>, 0
      ; Address Control Messages
      ; NCM_GETADDRESS returns the type of address that is present in the
      ; control (based on TBD Net Address flags).  If the input string has
      ; not been validated using this message will force the validation of
      ; the input string.  The WPARAM is a BOOL to determine to show the
      ; balloon tip.  The LPARAM is a pointer to the structure to fill in
      ; with the address type and address string.
      NCM_GETADDRESS equ (WM_USER + 1)
      NetAddr_GetAddress macro hwnd, pv
        exitm <SNDMSG (hwnd, NCM_GETADDRESS, 0, pv)>
      endm
      NC_ADDRESS struct
        pAddrInfo POINTER ?
        ; defined in iphlpapi.h
        PortNumber WORD ?
        PrefixLength BYTE ?
      NC_ADDRESS ends
      tagNC_ADDRESS typedef NC_ADDRESS
      PNC_ADDRESS typedef ptr NC_ADDRESS
      ; NCM_SETALLOWTYPE sets the type of addresses that the control will allow.
      ; The address flags are defined in iphlpapi.h
      NCM_SETALLOWTYPE equ (WM_USER + 2)
      NetAddr_SetAllowType macro hwnd, addrMask
        exitm <SNDMSG (hwnd, NCM_SETALLOWTYPE, addrMask, 0)>
      endm
      ; NCM_GETALLOWTYPE returns the currently allowed type mask.
      NCM_GETALLOWTYPE equ (WM_USER + 3)
      NetAddr_GetAllowType macro hwnd
        exitm <SNDMSG (hwnd, NCM_GETALLOWTYPE, 0, 0)>
      endm
      ; NCM_DISPLAYERRORTIP displays the error balloon tip with the correct
      ; error string (based on the last failure from the NCM_GETADDRESS call
      NCM_DISPLAYERRORTIP equ (WM_USER + 4)
      NetAddr_DisplayErrorTip macro hwnd
        exitm <SNDMSG (hwnd, NCM_DISPLAYERRORTIP, 0, 0)>
      endm
    endif
    ; (NTDDI_VERSION >= NTDDI_VISTA)
    if (NTDDI_VERSION ge NTDDI_VISTA)
      ; Returns the type of media (CD, DVD, Blank, etc) that is in the drive.
      ; dwMediaContent is set to a combination of ARCONTENT flags.
      @DefProto DllImport, SHGetDriveMedia, WIN_STD_CALL_CONV,, <:PCWSTR, :ptr DWORD>, 8
    endif
    ; (NTDDI_VERSION >= NTDDI_VISTA)
    ; Windows Parental Controls (WPC) query apis
    if (NTDDI_VERSION ge NTDDI_VISTA)
    endif
    ; (NTDDI_VERSION >= NTDDI_VISTA)
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  ;* _INC_SHELLAPI *
endif
if Defined(_MSC_VER) and (_MSC_VER ge 1200)
endif
