;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\consoleapi2.h
;             Created on (UTC) 06/04/2024 06:15:52
;             Last modified on (UTC) 21/02/2024 18:13:22

;********************************************************************************
ifdef _MSC_VER
endif
; _MSC_VER
ifndef _APISETCONSOLEL2_
  _APISETCONSOLEL2_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  include minwinbase.inc
  include wincontypes.inc
  include windef.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    ; Attributes flags:
    FOREGROUND_BLUE equ 0001h; text color contains blue.

    FOREGROUND_GREEN equ 0002h; text color contains green.

    FOREGROUND_RED equ 0004h; text color contains red.

    FOREGROUND_INTENSITY equ 0008h; text color is intensified.

    BACKGROUND_BLUE equ 0010h; background color contains blue.

    BACKGROUND_GREEN equ 0020h; background color contains green.

    BACKGROUND_RED equ 0040h; background color contains red.

    BACKGROUND_INTENSITY equ 0080h; background color is intensified.

    COMMON_LVB_LEADING_BYTE equ 0100h; Leading Byte of DBCS

    COMMON_LVB_TRAILING_BYTE equ 0200h; Trailing Byte of DBCS

    COMMON_LVB_GRID_HORIZONTAL equ 0400h; DBCS: Grid attribute: top horizontal.

    COMMON_LVB_GRID_LVERTICAL equ 0800h; DBCS: Grid attribute: left vertical.

    COMMON_LVB_GRID_RVERTICAL equ 1000h; DBCS: Grid attribute: right vertical.

    COMMON_LVB_REVERSE_VIDEO equ 4000h; DBCS: Reverse fore/back ground attribute.

    COMMON_LVB_UNDERSCORE equ 8000h; DBCS: Underscore.

    COMMON_LVB_SBCSDBCS equ 0300h; SBCS or DBCS flag.

    @DefProto DllImport, FillConsoleOutputCharacterA, WIN_STD_CALL_CONV,, <:HANDLE, :CHAR, :DWORD, :COORD, :LPDWORD>, 20
    @DefProto DllImport, FillConsoleOutputCharacterW, WIN_STD_CALL_CONV,, <:HANDLE, :WCHAR, :DWORD, :COORD, :LPDWORD>, 20
    ifdef UNICODE
      FillConsoleOutputCharacter equ <FillConsoleOutputCharacterW>
    else
      FillConsoleOutputCharacter equ <FillConsoleOutputCharacterA>
    endif
    ; !UNICODE
    @DefProto DllImport, FillConsoleOutputAttribute, WIN_STD_CALL_CONV,, <:HANDLE, :WORD, :DWORD, :COORD, :LPDWORD>, 20
    @DefProto DllImport, GenerateConsoleCtrlEvent, WIN_STD_CALL_CONV,, <:DWORD, :DWORD>, 8
    @DefProto DllImport, CreateConsoleScreenBuffer, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :ptr SECURITY_ATTRIBUTES, :DWORD, :LPVOID>, 20
    @DefProto DllImport, SetConsoleActiveScreenBuffer, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    @DefProto DllImport, FlushConsoleInputBuffer, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    @DefProto DllImport, SetConsoleCP, WIN_STD_CALL_CONV,, <:UINT>, 4
    @DefProto DllImport, SetConsoleOutputCP, WIN_STD_CALL_CONV,, <:UINT>, 4
    CONSOLE_CURSOR_INFO struct
      dwSize DWORD ?
      bVisible DWORD ?
    CONSOLE_CURSOR_INFO ends
    _CONSOLE_CURSOR_INFO typedef CONSOLE_CURSOR_INFO
    PCONSOLE_CURSOR_INFO typedef ptr CONSOLE_CURSOR_INFO
    @DefProto DllImport, GetConsoleCursorInfo, WIN_STD_CALL_CONV,, <:HANDLE, :PCONSOLE_CURSOR_INFO>, 8
    @DefProto DllImport, SetConsoleCursorInfo, WIN_STD_CALL_CONV,, <:HANDLE, :ptr CONSOLE_CURSOR_INFO>, 8
    CONSOLE_SCREEN_BUFFER_INFO struct
      dwSize COORD <>
      dwCursorPosition COORD <>
      wAttributes WORD ?
      srWindow SMALL_RECT <>
      dwMaximumWindowSize COORD <>
    CONSOLE_SCREEN_BUFFER_INFO ends
    _CONSOLE_SCREEN_BUFFER_INFO typedef CONSOLE_SCREEN_BUFFER_INFO
    PCONSOLE_SCREEN_BUFFER_INFO typedef ptr CONSOLE_SCREEN_BUFFER_INFO
    @DefProto DllImport, GetConsoleScreenBufferInfo, WIN_STD_CALL_CONV,, <:HANDLE, :PCONSOLE_SCREEN_BUFFER_INFO>, 8
    CONSOLE_SCREEN_BUFFER_INFOEX struct
      cbSize DWORD ?
      dwSize COORD <>
      dwCursorPosition COORD <>
      wAttributes WORD ?
      srWindow SMALL_RECT <>
      dwMaximumWindowSize COORD <>
      wPopupAttributes WORD ?
      bFullscreenSupported DWORD ?
      ColorTable COLORREF 16 dup (?)
    CONSOLE_SCREEN_BUFFER_INFOEX ends
    _CONSOLE_SCREEN_BUFFER_INFOEX typedef CONSOLE_SCREEN_BUFFER_INFOEX
    PCONSOLE_SCREEN_BUFFER_INFOEX typedef ptr CONSOLE_SCREEN_BUFFER_INFOEX
    @DefProto DllImport, GetConsoleScreenBufferInfoEx, WIN_STD_CALL_CONV,, <:HANDLE, :PCONSOLE_SCREEN_BUFFER_INFOEX>, 8
    @DefProto DllImport, SetConsoleScreenBufferInfoEx, WIN_STD_CALL_CONV,, <:HANDLE, :PCONSOLE_SCREEN_BUFFER_INFOEX>, 8
    @DefProto DllImport, SetConsoleScreenBufferSize, WIN_STD_CALL_CONV,, <:HANDLE, :COORD>, 8
    @DefProto DllImport, SetConsoleCursorPosition, WIN_STD_CALL_CONV,, <:HANDLE, :COORD>, 8
    @DefProto DllImport, GetLargestConsoleWindowSize, WIN_STD_CALL_CONV,, <:HANDLE>, 4
    @DefProto DllImport, SetConsoleTextAttribute, WIN_STD_CALL_CONV,, <:HANDLE, :WORD>, 8
    @DefProto DllImport, SetConsoleWindowInfo, WIN_STD_CALL_CONV,, <:HANDLE, :BOOL, :ptr SMALL_RECT>, 12
    @DefProto DllImport, WriteConsoleOutputCharacterA, WIN_STD_CALL_CONV,, <:HANDLE, :LPCSTR, :DWORD, :COORD, :LPDWORD>, 20
    @DefProto DllImport, WriteConsoleOutputCharacterW, WIN_STD_CALL_CONV,, <:HANDLE, :LPCWSTR, :DWORD, :COORD, :LPDWORD>, 20
    ifdef UNICODE
      WriteConsoleOutputCharacter equ <WriteConsoleOutputCharacterW>
    else
      WriteConsoleOutputCharacter equ <WriteConsoleOutputCharacterA>
    endif
    ; !UNICODE
    @DefProto DllImport, WriteConsoleOutputAttribute, WIN_STD_CALL_CONV,, <:HANDLE, :ptr WORD, :DWORD, :COORD, :LPDWORD>, 20
    @DefProto DllImport, ReadConsoleOutputCharacterA, WIN_STD_CALL_CONV,, <:HANDLE, :LPSTR, :DWORD, :COORD, :LPDWORD>, 20
    @DefProto DllImport, ReadConsoleOutputCharacterW, WIN_STD_CALL_CONV,, <:HANDLE, :LPWSTR, :DWORD, :COORD, :LPDWORD>, 20
    ifdef UNICODE
      ReadConsoleOutputCharacter equ <ReadConsoleOutputCharacterW>
    else
      ReadConsoleOutputCharacter equ <ReadConsoleOutputCharacterA>
    endif
    ; !UNICODE
    @DefProto DllImport, ReadConsoleOutputAttribute, WIN_STD_CALL_CONV,, <:HANDLE, :LPWORD, :DWORD, :COORD, :LPDWORD>, 20
    @DefProto DllImport, WriteConsoleInputA, WIN_STD_CALL_CONV,, <:HANDLE, :ptr INPUT_RECORD, :DWORD, :LPDWORD>, 16
    @DefProto DllImport, WriteConsoleInputW, WIN_STD_CALL_CONV,, <:HANDLE, :ptr INPUT_RECORD, :DWORD, :LPDWORD>, 16
    ifdef UNICODE
      WriteConsoleInput equ <WriteConsoleInputW>
    else
      WriteConsoleInput equ <WriteConsoleInputA>
    endif
    ; !UNICODE
    @DefProto DllImport, ScrollConsoleScreenBufferA, WIN_STD_CALL_CONV,, <:HANDLE, :ptr SMALL_RECT, :ptr SMALL_RECT, :COORD, :ptr CHAR_INFO>, 20
    @DefProto DllImport, ScrollConsoleScreenBufferW, WIN_STD_CALL_CONV,, <:HANDLE, :ptr SMALL_RECT, :ptr SMALL_RECT, :COORD, :ptr CHAR_INFO>, 20
    ifdef UNICODE
      ScrollConsoleScreenBuffer equ <ScrollConsoleScreenBufferW>
    else
      ScrollConsoleScreenBuffer equ <ScrollConsoleScreenBufferA>
    endif
    ; !UNICODE
    @DefProto DllImport, WriteConsoleOutputA, WIN_STD_CALL_CONV,, <:HANDLE, :ptr CHAR_INFO, :COORD, :COORD, :PSMALL_RECT>, 20
    @DefProto DllImport, WriteConsoleOutputW, WIN_STD_CALL_CONV,, <:HANDLE, :ptr CHAR_INFO, :COORD, :COORD, :PSMALL_RECT>, 20
    ifdef UNICODE
      WriteConsoleOutput equ <WriteConsoleOutputW>
    else
      WriteConsoleOutput equ <WriteConsoleOutputA>
    endif
    ; !UNICODE
    @DefProto DllImport, ReadConsoleOutputA, WIN_STD_CALL_CONV,, <:HANDLE, :PCHAR_INFO, :COORD, :COORD, :PSMALL_RECT>, 20
    @DefProto DllImport, ReadConsoleOutputW, WIN_STD_CALL_CONV,, <:HANDLE, :PCHAR_INFO, :COORD, :COORD, :PSMALL_RECT>, 20
    ifdef UNICODE
      ReadConsoleOutput equ <ReadConsoleOutputW>
    else
      ReadConsoleOutput equ <ReadConsoleOutputA>
    endif
    ; !UNICODE
    @DefProto DllImport, GetConsoleTitleA, WIN_STD_CALL_CONV,, <:LPSTR, :DWORD>, 8
    @DefProto DllImport, GetConsoleTitleW, WIN_STD_CALL_CONV,, <:LPWSTR, :DWORD>, 8
    ifdef UNICODE
      GetConsoleTitle equ <GetConsoleTitleW>
    else
      GetConsoleTitle equ <GetConsoleTitleA>
    endif
    ; !UNICODE
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, GetConsoleOriginalTitleA, WIN_STD_CALL_CONV,, <:LPSTR, :DWORD>, 8
      @DefProto DllImport, GetConsoleOriginalTitleW, WIN_STD_CALL_CONV,, <:LPWSTR, :DWORD>, 8
      ifdef UNICODE
        GetConsoleOriginalTitle equ <GetConsoleOriginalTitleW>
      else
        GetConsoleOriginalTitle equ <GetConsoleOriginalTitleA>
      endif
      ; !UNICODE
      ;* _WIN32_WINNT >= 0x0600 *
    endif
    @DefProto DllImport, SetConsoleTitleA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
    @DefProto DllImport, SetConsoleTitleW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
    ifdef UNICODE
      SetConsoleTitle equ <SetConsoleTitleW>
    else
      SetConsoleTitle equ <SetConsoleTitleA>
    endif
    ; !UNICODE
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)
  ifdef __cplusplus
    ;[...]
  endif
endif
; _APISETCONSOLEL2_
