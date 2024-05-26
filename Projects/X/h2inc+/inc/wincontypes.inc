;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\wincontypes.h
;             Created on (UTC) 06/04/2024 06:16:02
;             Last modified on (UTC) 08/01/2024 17:05:24

ifndef _WINCONTYPES_
  _WINCONTYPES_ equ <>
  include minwindef.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    COORD struct
      X SHORT_ ?
      Y SHORT_ ?
    COORD ends
    _COORD typedef COORD
    PCOORD typedef ptr COORD
    SMALL_RECT struct
      Left SHORT_ ?
      Top SHORT_ ?
      Right SHORT_ ?
      Bottom SHORT_ ?
    SMALL_RECT ends
    _SMALL_RECT typedef SMALL_RECT
    PSMALL_RECT typedef ptr SMALL_RECT
    KEY_EVENT_RECORD struct
      bKeyDown BOOL ?
      wRepeatCount WORD ?
      wVirtualKeyCode WORD ?
      wVirtualScanCode WORD ?
      union uChar
        UnicodeChar WCHAR ?
        AsciiChar CHAR ?
      ends
      dwControlKeyState DWORD ?
    KEY_EVENT_RECORD ends
    _KEY_EVENT_RECORD typedef KEY_EVENT_RECORD
    PKEY_EVENT_RECORD typedef ptr KEY_EVENT_RECORD
    RIGHT_ALT_PRESSED equ 0001h
    LEFT_ALT_PRESSED equ 0002h
    RIGHT_CTRL_PRESSED equ 0004h
    LEFT_CTRL_PRESSED equ 0008h
    SHIFT_PRESSED equ 0010h
    NUMLOCK_ON equ 0020h
    SCROLLLOCK_ON equ 0040h
    CAPSLOCK_ON equ 0080h
    ENHANCED_KEY equ 0100h
    NLS_DBCSCHAR equ 00010000h
    NLS_ALPHANUMERIC equ 00000000h
    NLS_KATAKANA equ 00020000h
    NLS_HIRAGANA equ 00040000h
    NLS_ROMAN equ 00400000h
    NLS_IME_CONVERSION equ 00800000h
    ALTNUMPAD_BIT equ 04000000h
    NLS_IME_DISABLE equ 20000000h
    MOUSE_EVENT_RECORD struct
      dwMousePosition COORD <>
      dwButtonState DWORD ?
      dwControlKeyState DWORD ?
      dwEventFlags DWORD ?
    MOUSE_EVENT_RECORD ends
    _MOUSE_EVENT_RECORD typedef MOUSE_EVENT_RECORD
    PMOUSE_EVENT_RECORD typedef ptr MOUSE_EVENT_RECORD
    FROM_LEFT_1ST_BUTTON_PRESSED equ 0001h
    RIGHTMOST_BUTTON_PRESSED equ 0002h
    FROM_LEFT_2ND_BUTTON_PRESSED equ 0004h
    FROM_LEFT_3RD_BUTTON_PRESSED equ 0008h
    FROM_LEFT_4TH_BUTTON_PRESSED equ 0010h
    MOUSE_MOVED equ 0001h
    DOUBLE_CLICK equ 0002h
    MOUSE_WHEELED equ 0004h
    if (_WIN32_WINNT ge 0600h)
      MOUSE_HWHEELED equ 0008h
    endif
    WINDOW_BUFFER_SIZE_RECORD struct
      dwSize COORD <>
    WINDOW_BUFFER_SIZE_RECORD ends
    _WINDOW_BUFFER_SIZE_RECORD typedef WINDOW_BUFFER_SIZE_RECORD
    PWINDOW_BUFFER_SIZE_RECORD typedef ptr WINDOW_BUFFER_SIZE_RECORD
    MENU_EVENT_RECORD struct
      dwCommandId UINT ?
    MENU_EVENT_RECORD ends
    _MENU_EVENT_RECORD typedef MENU_EVENT_RECORD
    PMENU_EVENT_RECORD typedef ptr MENU_EVENT_RECORD
    FOCUS_EVENT_RECORD struct
      bSetFocus BOOL ?
    FOCUS_EVENT_RECORD ends
    _FOCUS_EVENT_RECORD typedef FOCUS_EVENT_RECORD
    PFOCUS_EVENT_RECORD typedef ptr FOCUS_EVENT_RECORD
    INPUT_RECORD struct 4
      EventType WORD ?
      union Event_
        KeyEvent KEY_EVENT_RECORD <>
        MouseEvent MOUSE_EVENT_RECORD <>
        WindowBufferSizeEvent WINDOW_BUFFER_SIZE_RECORD <>
        MenuEvent MENU_EVENT_RECORD <>
        FocusEvent FOCUS_EVENT_RECORD <>
      ends
    INPUT_RECORD ends
    _INPUT_RECORD typedef INPUT_RECORD
    PINPUT_RECORD typedef ptr INPUT_RECORD
    KEY_EVENT equ 0001h
    MOUSE_EVENT equ 0002h
    WINDOW_BUFFER_SIZE_EVENT equ 0004h
    MENU_EVENT equ 0008h
    FOCUS_EVENT equ 0010h
    CHAR_INFO struct
      union Char
        UnicodeChar WCHAR ?
        AsciiChar CHAR ?
      ends
      Attributes WORD ?
    CHAR_INFO ends
    _CHAR_INFO typedef CHAR_INFO
    PCHAR_INFO typedef ptr CHAR_INFO
    CONSOLE_FONT_INFO struct
      nFont DWORD ?
      dwFontSize COORD <>
    CONSOLE_FONT_INFO ends
    _CONSOLE_FONT_INFO typedef CONSOLE_FONT_INFO
    PCONSOLE_FONT_INFO typedef ptr CONSOLE_FONT_INFO
    HPCON typedef ptr VOID
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
