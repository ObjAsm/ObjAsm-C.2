;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\consoleapi.h
;             Created on (UTC) 06/04/2024 06:15:52
;             Last modified on (UTC) 21/02/2024 18:13:14

ifdef _MSC_VER
endif
ifndef _APISETCONSOLE_
  _APISETCONSOLE_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include minwindef.inc
  include minwinbase.inc
  include wincontypes.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, AllocConsole, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, FreeConsole, WIN_STD_CALL_CONV,, <>, 0
    if (_WIN32_WINNT ge 0500h)
      @DefProto DllImport, AttachConsole, WIN_STD_CALL_CONV,, <:DWORD>, 4
      ATTACH_PARENT_PROCESS equ (- 1)
    endif
    @DefProto DllImport, GetConsoleCP, WIN_STD_CALL_CONV,, <>, 0
    @DefProto DllImport, GetConsoleOutputCP, WIN_STD_CALL_CONV,, <>, 0
    ENABLE_PROCESSED_INPUT equ 0001h
    ENABLE_LINE_INPUT equ 0002h
    ENABLE_ECHO_INPUT equ 0004h
    ENABLE_WINDOW_INPUT equ 0008h
    ENABLE_MOUSE_INPUT equ 0010h
    ENABLE_INSERT_MODE equ 0020h
    ENABLE_QUICK_EDIT_MODE equ 0040h
    ENABLE_EXTENDED_FLAGS equ 0080h
    ENABLE_AUTO_POSITION equ 0100h
    ENABLE_VIRTUAL_TERMINAL_INPUT equ 0200h
    ENABLE_PROCESSED_OUTPUT equ 0001h
    ENABLE_WRAP_AT_EOL_OUTPUT equ 0002h
    ENABLE_VIRTUAL_TERMINAL_PROCESSING equ 0004h
    DISABLE_NEWLINE_AUTO_RETURN equ 0008h
    ENABLE_LVB_GRID_WORLDWIDE equ 0010h
    @DefProto DllImport, GetConsoleMode, WIN_STD_CALL_CONV,, <:HANDLE, :LPDWORD>, 8
    @DefProto DllImport, SetConsoleMode, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD>, 8
    @DefProto DllImport, GetNumberOfConsoleInputEvents, WIN_STD_CALL_CONV,, <:HANDLE, :LPDWORD>, 8
    @DefProto DllImport, ReadConsoleInputA, WIN_STD_CALL_CONV,, <:HANDLE, :PINPUT_RECORD, :DWORD, :LPDWORD>, 16
    @DefProto DllImport, ReadConsoleInputW, WIN_STD_CALL_CONV,, <:HANDLE, :PINPUT_RECORD, :DWORD, :LPDWORD>, 16
    ifdef UNICODE
      ReadConsoleInput equ <ReadConsoleInputW>
    else
      ReadConsoleInput equ <ReadConsoleInputA>
    endif
    ifndef UNICODE
      PeekConsoleInput equ <PeekConsoleInputA>
    endif
    @DefProto DllImport, PeekConsoleInputA, WIN_STD_CALL_CONV,, <:HANDLE, :PINPUT_RECORD, :DWORD, :LPDWORD>, 16
    @DefProto DllImport, PeekConsoleInputW, WIN_STD_CALL_CONV,, <:HANDLE, :PINPUT_RECORD, :DWORD, :LPDWORD>, 16
    ifdef UNICODE
      PeekConsoleInput equ <PeekConsoleInputW>
    else
      PeekConsoleInput equ <PeekConsoleInputA>
    endif
    CONSOLE_READCONSOLE_CONTROL struct
      nLength ULONG ?
      nInitialChars ULONG ?
      dwCtrlWakeupMask ULONG ?
      dwControlKeyState ULONG ?
    CONSOLE_READCONSOLE_CONTROL ends
    _CONSOLE_READCONSOLE_CONTROL typedef CONSOLE_READCONSOLE_CONTROL
    PCONSOLE_READCONSOLE_CONTROL typedef ptr CONSOLE_READCONSOLE_CONTROL
    @DefProto DllImport, ReadConsoleA, WIN_STD_CALL_CONV,, <:HANDLE, :LPVOID, :DWORD, :LPDWORD, :PCONSOLE_READCONSOLE_CONTROL>, 20
    @DefProto DllImport, ReadConsoleW, WIN_STD_CALL_CONV,, <:HANDLE, :LPVOID, :DWORD, :LPDWORD, :PCONSOLE_READCONSOLE_CONTROL>, 20
    ifdef UNICODE
      ReadConsole equ <ReadConsoleW>
    else
      ReadConsole equ <ReadConsoleA>
    endif
    @DefProto DllImport, WriteConsoleA, WIN_STD_CALL_CONV,, <:HANDLE, :ptr VOID, :DWORD, :LPDWORD, :LPVOID>, 20
    @DefProto DllImport, WriteConsoleW, WIN_STD_CALL_CONV,, <:HANDLE, :ptr VOID, :DWORD, :LPDWORD, :LPVOID>, 20
    ifdef UNICODE
      WriteConsole equ <WriteConsoleW>
    else
      WriteConsole equ <WriteConsoleA>
    endif
    CTRL_C_EVENT equ 0
    CTRL_BREAK_EVENT equ 1
    CTRL_CLOSE_EVENT equ 2
    CTRL_LOGOFF_EVENT equ 5
    CTRL_SHUTDOWN_EVENT equ 6
    TYPE_PHANDLER_ROUTINE typedef proto WIN_STD_CALL_CONV :DWORD
    PHANDLER_ROUTINE typedef ptr TYPE_PHANDLER_ROUTINE

    @DefProto DllImport, SetConsoleCtrlHandler, WIN_STD_CALL_CONV,, <:PHANDLER_ROUTINE, :BOOL>, 8
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (NTDDI_VERSION ge NTDDI_WIN10_RS5)
      PSEUDOCONSOLE_INHERIT_CURSOR equ (1h)
      @DefProto DllImport, CreatePseudoConsole, WIN_STD_CALL_CONV,, <:COORD, :HANDLE, :HANDLE, :DWORD, :ptr HPCON>, 20
      @DefProto DllImport, ResizePseudoConsole, WIN_STD_CALL_CONV,, <:HPCON, :COORD>, 8
      @DefProto DllImport, ClosePseudoConsole, WIN_STD_CALL_CONV,, <:HPCON>, 4
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
