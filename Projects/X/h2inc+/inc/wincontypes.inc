;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\wincontypes.h
;             Created on (UTC) 06/04/2024 06:16:02
;             Last modified on (UTC) 08/01/2024 17:05:24

;--*
ifndef _WINCONTYPES_
  _WINCONTYPES_ equ <>
  include minwindef.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    COORD struct
      X SWORD ?
      Y SWORD ?
    COORD ends
    _COORD typedef COORD
    PCOORD typedef ptr COORD
    SMALL_RECT struct
      Left SWORD ?
      Top SWORD ?
      Right SWORD ?
      Bottom SWORD ?
    SMALL_RECT ends
    _SMALL_RECT typedef SMALL_RECT
    PSMALL_RECT typedef ptr SMALL_RECT
    KEY_EVENT_RECORD struct
      bKeyDown DWORD ?
      wRepeatCount WORD ?
      wVirtualKeyCode WORD ?
      wVirtualScanCode WORD ?
      union uChar
        UnicodeChar WORD ?
        AsciiChar SBYTE ?
      ends
      dwControlKeyState DWORD ?
    KEY_EVENT_RECORD ends
    _KEY_EVENT_RECORD typedef KEY_EVENT_RECORD
    PKEY_EVENT_RECORD typedef ptr KEY_EVENT_RECORD
    ; ControlKeyState flags
    RIGHT_ALT_PRESSED equ 0001h; the right alt key is pressed.

    LEFT_ALT_PRESSED equ 0002h; the left alt key is pressed.

    RIGHT_CTRL_PRESSED equ 0004h; the right ctrl key is pressed.

    LEFT_CTRL_PRESSED equ 0008h; the left ctrl key is pressed.

    SHIFT_PRESSED equ 0010h; the shift key is pressed.

    NUMLOCK_ON equ 0020h; the numlock light is on.

    SCROLLLOCK_ON equ 0040h; the scrolllock light is on.

    CAPSLOCK_ON equ 0080h; the capslock light is on.

    ENHANCED_KEY equ 0100h; the key is enhanced.

    NLS_DBCSCHAR equ 00010000h; DBCS for JPN: SBCS/DBCS mode.

    NLS_ALPHANUMERIC equ 00000000h; DBCS for JPN: Alphanumeric mode.

    NLS_KATAKANA equ 00020000h; DBCS for JPN: Katakana mode.

    NLS_HIRAGANA equ 00040000h; DBCS for JPN: Hiragana mode.

    NLS_ROMAN equ 00400000h; DBCS for JPN: Roman/Noroman mode.

    NLS_IME_CONVERSION equ 00800000h; DBCS for JPN: IME conversion.

    ALTNUMPAD_BIT equ 04000000h; AltNumpad OEM char (copied from ntuser\inc\kbd.h) ;internal_NT

    NLS_IME_DISABLE equ 20000000h; DBCS for JPN: IME enable/disable.

    MOUSE_EVENT_RECORD struct
      dwMousePosition COORD <>
      dwButtonState DWORD ?
      dwControlKeyState DWORD ?
      dwEventFlags DWORD ?
    MOUSE_EVENT_RECORD ends
    _MOUSE_EVENT_RECORD typedef MOUSE_EVENT_RECORD
    PMOUSE_EVENT_RECORD typedef ptr MOUSE_EVENT_RECORD
    ; ButtonState flags
    FROM_LEFT_1ST_BUTTON_PRESSED equ 0001h
    RIGHTMOST_BUTTON_PRESSED equ 0002h
    FROM_LEFT_2ND_BUTTON_PRESSED equ 0004h
    FROM_LEFT_3RD_BUTTON_PRESSED equ 0008h
    FROM_LEFT_4TH_BUTTON_PRESSED equ 0010h
    ; EventFlags
    MOUSE_MOVED equ 0001h
    DOUBLE_CLICK equ 0002h
    MOUSE_WHEELED equ 0004h
    if (_WIN32_WINNT ge 0600h)
      MOUSE_HWHEELED equ 0008h
      ;* _WIN32_WINNT >= 0x0600 *
    endif
    WINDOW_BUFFER_SIZE_RECORD struct
      dwSize COORD <>
    WINDOW_BUFFER_SIZE_RECORD ends
    _WINDOW_BUFFER_SIZE_RECORD typedef WINDOW_BUFFER_SIZE_RECORD
    PWINDOW_BUFFER_SIZE_RECORD typedef ptr WINDOW_BUFFER_SIZE_RECORD
    MENU_EVENT_RECORD struct
      dwCommandId DWORD ?
    MENU_EVENT_RECORD ends
    _MENU_EVENT_RECORD typedef MENU_EVENT_RECORD
    PMENU_EVENT_RECORD typedef ptr MENU_EVENT_RECORD
    FOCUS_EVENT_RECORD struct
      bSetFocus DWORD ?
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
      Event_ typedef Event_
    INPUT_RECORD ends
    _INPUT_RECORD typedef INPUT_RECORD
    PINPUT_RECORD typedef ptr INPUT_RECORD
    ;  EventType flags:
    KEY_EVENT equ 0001h; Event contains key event record

    MOUSE_EVENT equ 0002h; Event contains mouse event record

    WINDOW_BUFFER_SIZE_EVENT equ 0004h; Event contains window change event record

    MENU_EVENT equ 0008h; Event contains menu event record

    FOCUS_EVENT equ 0010h; event contains focus change

    CHAR_INFO struct
      union Char
        UnicodeChar WORD ?
        AsciiChar SBYTE ?
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
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
; _WINCONTYPES_
