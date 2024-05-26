;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\consoleapi3.h
;             Created on (UTC) 06/04/2024 06:15:52
;             Last modified on (UTC) 21/02/2024 18:13:24

ifdef _MSC_VER
endif
ifndef _APISETCONSOLEL3_
  _APISETCONSOLEL3_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  include minwinbase.inc
  include wincontypes.inc
  include windef.inc
  ifndef NOGDI
    include wingdi.inc
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, GetNumberOfConsoleMouseButtons, WIN_STD_CALL_CONV,, <:LPDWORD>, 4
    if (_WIN32_WINNT ge 0500h)
      @DefProto DllImport, GetConsoleFontSize, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD>, 8
      @DefProto DllImport, GetCurrentConsoleFont, WIN_STD_CALL_CONV,, <:HANDLE, :BOOL, :PCONSOLE_FONT_INFO>, 12
      ifndef NOGDI
        CONSOLE_FONT_INFOEX struct
          cbSize ULONG ?
          nFont DWORD ?
          dwFontSize COORD <>
          FontFamily UINT ?
          FontWeight UINT ?
          FaceName WCHAR LF_FACESIZE dup (?)
        CONSOLE_FONT_INFOEX ends
        _CONSOLE_FONT_INFOEX typedef CONSOLE_FONT_INFOEX
        PCONSOLE_FONT_INFOEX typedef ptr CONSOLE_FONT_INFOEX
        @DefProto DllImport, GetCurrentConsoleFontEx, WIN_STD_CALL_CONV,, <:HANDLE, :BOOL, :PCONSOLE_FONT_INFOEX>, 12
        @DefProto DllImport, SetCurrentConsoleFontEx, WIN_STD_CALL_CONV,, <:HANDLE, :BOOL, :PCONSOLE_FONT_INFOEX>, 12
      endif
      CONSOLE_NO_SELECTION equ 0000h
      CONSOLE_SELECTION_IN_PROGRESS equ 0001h
      CONSOLE_SELECTION_NOT_EMPTY equ 0002h
      CONSOLE_MOUSE_SELECTION equ 0004h
      CONSOLE_MOUSE_DOWN equ 0008h
      CONSOLE_SELECTION_INFO struct
        dwFlags DWORD ?
        dwSelectionAnchor COORD <>
        srSelection SMALL_RECT <>
      CONSOLE_SELECTION_INFO ends
      _CONSOLE_SELECTION_INFO typedef CONSOLE_SELECTION_INFO
      PCONSOLE_SELECTION_INFO typedef ptr CONSOLE_SELECTION_INFO
      @DefProto DllImport, GetConsoleSelectionInfo, WIN_STD_CALL_CONV,, <:PCONSOLE_SELECTION_INFO>, 4
      HISTORY_NO_DUP_FLAG equ 1h
      CONSOLE_HISTORY_INFO struct
        cbSize UINT ?
        HistoryBufferSize UINT ?
        NumberOfHistoryBuffers UINT ?
        dwFlags DWORD ?
      CONSOLE_HISTORY_INFO ends
      _CONSOLE_HISTORY_INFO typedef CONSOLE_HISTORY_INFO
      PCONSOLE_HISTORY_INFO typedef ptr CONSOLE_HISTORY_INFO
      @DefProto DllImport, GetConsoleHistoryInfo, WIN_STD_CALL_CONV,, <:PCONSOLE_HISTORY_INFO>, 4
      @DefProto DllImport, SetConsoleHistoryInfo, WIN_STD_CALL_CONV,, <:PCONSOLE_HISTORY_INFO>, 4
      CONSOLE_FULLSCREEN equ 1
      CONSOLE_FULLSCREEN_HARDWARE equ 2
      @DefProto DllImport, GetConsoleDisplayMode, WIN_STD_CALL_CONV,, <:LPDWORD>, 4
      CONSOLE_FULLSCREEN_MODE equ 1
      CONSOLE_WINDOWED_MODE equ 2
      @DefProto DllImport, SetConsoleDisplayMode, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :PCOORD>, 12
      @DefProto DllImport, GetConsoleWindow, WIN_STD_CALL_CONV,, <>, 0
    endif
    if (_WIN32_WINNT ge 0501h)
      @DefProto DllImport, AddConsoleAliasA, WIN_STD_CALL_CONV,, <:LPSTR, :LPSTR, :LPSTR>, 12
      @DefProto DllImport, AddConsoleAliasW, WIN_STD_CALL_CONV,, <:LPWSTR, :LPWSTR, :LPWSTR>, 12
      ifdef UNICODE
        AddConsoleAlias equ <AddConsoleAliasW>
      else
        AddConsoleAlias equ <AddConsoleAliasA>
      endif
      @DefProto DllImport, GetConsoleAliasA, WIN_STD_CALL_CONV,, <:LPSTR, :LPSTR, :DWORD, :LPSTR>, 16
      @DefProto DllImport, GetConsoleAliasW, WIN_STD_CALL_CONV,, <:LPWSTR, :LPWSTR, :DWORD, :LPWSTR>, 16
      ifdef UNICODE
        GetConsoleAlias equ <GetConsoleAliasW>
      else
        GetConsoleAlias equ <GetConsoleAliasA>
      endif
      @DefProto DllImport, GetConsoleAliasesLengthA, WIN_STD_CALL_CONV,, <:LPSTR>, 4
      @DefProto DllImport, GetConsoleAliasesLengthW, WIN_STD_CALL_CONV,, <:LPWSTR>, 4
      ifdef UNICODE
        GetConsoleAliasesLength equ <GetConsoleAliasesLengthW>
      else
        GetConsoleAliasesLength equ <GetConsoleAliasesLengthA>
      endif
      @DefProto DllImport, GetConsoleAliasExesLengthA, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, GetConsoleAliasExesLengthW, WIN_STD_CALL_CONV,, <>, 0
      ifdef UNICODE
        GetConsoleAliasExesLength equ <GetConsoleAliasExesLengthW>
      else
        GetConsoleAliasExesLength equ <GetConsoleAliasExesLengthA>
      endif
      @DefProto DllImport, GetConsoleAliasesA, WIN_STD_CALL_CONV,, <:LPSTR, :DWORD, :LPSTR>, 12
      @DefProto DllImport, GetConsoleAliasesW, WIN_STD_CALL_CONV,, <:LPWSTR, :DWORD, :LPWSTR>, 12
      ifdef UNICODE
        GetConsoleAliases equ <GetConsoleAliasesW>
      else
        GetConsoleAliases equ <GetConsoleAliasesA>
      endif
      @DefProto DllImport, GetConsoleAliasExesA, WIN_STD_CALL_CONV,, <:LPSTR, :DWORD>, 8
      @DefProto DllImport, GetConsoleAliasExesW, WIN_STD_CALL_CONV,, <:LPWSTR, :DWORD>, 8
      ifdef UNICODE
        GetConsoleAliasExes equ <GetConsoleAliasExesW>
      else
        GetConsoleAliasExes equ <GetConsoleAliasExesA>
      endif
    endif
    @DefProto DllImport, ExpungeConsoleCommandHistoryA, WIN_STD_CALL_CONV,, <:LPSTR>, 4
    @DefProto DllImport, ExpungeConsoleCommandHistoryW, WIN_STD_CALL_CONV,, <:LPWSTR>, 4
    ifdef UNICODE
      ExpungeConsoleCommandHistory equ <ExpungeConsoleCommandHistoryW>
    else
      ExpungeConsoleCommandHistory equ <ExpungeConsoleCommandHistoryA>
    endif
    @DefProto DllImport, SetConsoleNumberOfCommandsA, WIN_STD_CALL_CONV,, <:DWORD, :LPSTR>, 8
    @DefProto DllImport, SetConsoleNumberOfCommandsW, WIN_STD_CALL_CONV,, <:DWORD, :LPWSTR>, 8
    ifdef UNICODE
      SetConsoleNumberOfCommands equ <SetConsoleNumberOfCommandsW>
    else
      SetConsoleNumberOfCommands equ <SetConsoleNumberOfCommandsA>
    endif
    @DefProto DllImport, GetConsoleCommandHistoryLengthA, WIN_STD_CALL_CONV,, <:LPSTR>, 4
    @DefProto DllImport, GetConsoleCommandHistoryLengthW, WIN_STD_CALL_CONV,, <:LPWSTR>, 4
    ifdef UNICODE
      GetConsoleCommandHistoryLength equ <GetConsoleCommandHistoryLengthW>
    else
      GetConsoleCommandHistoryLength equ <GetConsoleCommandHistoryLengthA>
    endif
    @DefProto DllImport, GetConsoleCommandHistoryA, WIN_STD_CALL_CONV,, <:LPSTR, :DWORD, :LPSTR>, 12
    @DefProto DllImport, GetConsoleCommandHistoryW, WIN_STD_CALL_CONV,, <:LPWSTR, :DWORD, :LPWSTR>, 12
    ifdef UNICODE
      GetConsoleCommandHistory equ <GetConsoleCommandHistoryW>
    else
      GetConsoleCommandHistory equ <GetConsoleCommandHistoryA>
    endif
    if (_WIN32_WINNT ge 0501h)
      @DefProto DllImport, GetConsoleProcessList, WIN_STD_CALL_CONV,, <:LPDWORD, :DWORD>, 8
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
