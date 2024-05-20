;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\winuser.h
;             Created on (UTC) 06/04/2024 06:16:03
;             Last modified on (UTC) 21/02/2024 18:18:34

include winapifamily.inc
;****************************************************************************
;*                                                                           *
;* winuser.h -- USER procedure declarations, constant definitions and macros *
;*                                                                           *
;* Copyright (c) Microsoft Corporation. All rights reserved.                 *
;*                                                                           *
;****************************************************************************
ifndef _WINUSER_
  _WINUSER_ equ <>
  ; Define API decoration for direct importing of DLL references.
  if  not Defined(WINUSERAPI)
    if  not Defined(_USER32_)
      WINUSERAPI equ <DECLSPEC_IMPORT>
    else
      WINUSERAPI equ <extern "C">
    endif
  endif
  if  not Defined(WINABLEAPI)
    if  not Defined(_USER32_)
      WINABLEAPI equ <DECLSPEC_IMPORT>
    else
      WINABLEAPI equ <>
    endif
  endif
  ifdef _MAC
    ;[...]
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if _MSC_VER ge 1200
    ifndef _MSC_EXTENSIONS
      ; truncation of constant value
    endif
    ; padding added after data member
  endif
  ifndef WINVER
    ;* version 5.0 *
    WINVER equ 0500h
    ;* !WINVER *
  endif
  include stdarg.inc
  ifndef NOAPISET
    include libloaderapi.inc
    ; LoadString%
  endif
  ifndef NOUSER
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      HDWP typedef HANDLE
      MENUTEMPLATEA typedef VOID
      MENUTEMPLATEW typedef VOID
      ifdef UNICODE
        MENUTEMPLATE typedef MENUTEMPLATEW
      else
        MENUTEMPLATE typedef MENUTEMPLATEA
      endif
      ; UNICODE
      LPMENUTEMPLATEA typedef PVOID
      LPMENUTEMPLATEW typedef PVOID
      ifdef UNICODE
        LPMENUTEMPLATE typedef LPMENUTEMPLATEW
      else
        LPMENUTEMPLATE typedef LPMENUTEMPLATEA
      endif
      ; UNICODE
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      TYPE_WNDPROC typedef proto WIN_STD_CALL_CONV :HWND, :UINT, :WPARAM, :LPARAM
      WNDPROC typedef ptr TYPE_WNDPROC

      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_GAMES) *
    endif
    ifdef STRICT
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
        TYPE_DLGPROC typedef proto WIN_STD_CALL_CONV :HWND, :UINT, :WPARAM, :LPARAM
        DLGPROC typedef ptr TYPE_DLGPROC

        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
        TYPE_TIMERPROC typedef proto WIN_STD_CALL_CONV :HWND, :UINT, :UINT_PTR, :DWORD
        TIMERPROC typedef ptr TYPE_TIMERPROC

        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_GAMES) *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        TYPE_GRAYSTRINGPROC typedef proto WIN_STD_CALL_CONV :HDC, :LPARAM, :SDWORD
        GRAYSTRINGPROC typedef ptr TYPE_GRAYSTRINGPROC

        TYPE_WNDENUMPROC typedef proto WIN_STD_CALL_CONV :HWND, :LPARAM
        WNDENUMPROC typedef ptr TYPE_WNDENUMPROC

        TYPE_HOOKPROC typedef proto WIN_STD_CALL_CONV :SDWORD, :WPARAM, :LPARAM
        HOOKPROC typedef ptr TYPE_HOOKPROC

        TYPE_SENDASYNCPROC typedef proto WIN_STD_CALL_CONV :HWND, :UINT, :ULONG_PTR, :LRESULT
        SENDASYNCPROC typedef ptr TYPE_SENDASYNCPROC

        TYPE_PROPENUMPROCA typedef proto WIN_STD_CALL_CONV :HWND, :LPCSTR, :HANDLE
        PROPENUMPROCA typedef ptr TYPE_PROPENUMPROCA

        TYPE_PROPENUMPROCW typedef proto WIN_STD_CALL_CONV :HWND, :LPCWSTR, :HANDLE
        PROPENUMPROCW typedef ptr TYPE_PROPENUMPROCW

        TYPE_PROPENUMPROCEXA typedef proto WIN_STD_CALL_CONV :HWND, :LPSTR, :HANDLE, :ULONG_PTR
        PROPENUMPROCEXA typedef ptr TYPE_PROPENUMPROCEXA

        TYPE_PROPENUMPROCEXW typedef proto WIN_STD_CALL_CONV :HWND, :LPWSTR, :HANDLE, :ULONG_PTR
        PROPENUMPROCEXW typedef ptr TYPE_PROPENUMPROCEXW

        TYPE_EDITWORDBREAKPROCA typedef proto WIN_STD_CALL_CONV :LPSTR, :SDWORD, :SDWORD, :SDWORD
        EDITWORDBREAKPROCA typedef ptr TYPE_EDITWORDBREAKPROCA

        TYPE_EDITWORDBREAKPROCW typedef proto WIN_STD_CALL_CONV :LPWSTR, :SDWORD, :SDWORD, :SDWORD
        EDITWORDBREAKPROCW typedef ptr TYPE_EDITWORDBREAKPROCW

        if (WINVER ge 0400h)
          TYPE_DRAWSTATEPROC typedef proto WIN_STD_CALL_CONV :HDC, :LPARAM, :WPARAM, :SDWORD, :SDWORD
          DRAWSTATEPROC typedef ptr TYPE_DRAWSTATEPROC

          ;* WINVER >= 0x0400 *
        endif
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;* !STRICT *
    else
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        DLGPROC typedef FARPROC
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
        TIMERPROC typedef FARPROC
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_GAMES) *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        GRAYSTRINGPROC typedef FARPROC
        WNDENUMPROC typedef FARPROC
        HOOKPROC typedef FARPROC
        SENDASYNCPROC typedef FARPROC
        EDITWORDBREAKPROCA typedef FARPROC
        EDITWORDBREAKPROCW typedef FARPROC
        PROPENUMPROCA typedef FARPROC
        PROPENUMPROCW typedef FARPROC
        PROPENUMPROCEXA typedef FARPROC
        PROPENUMPROCEXW typedef FARPROC
        if (WINVER ge 0400h)
          DRAWSTATEPROC typedef FARPROC
          ;* WINVER >= 0x0400 *
        endif
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;* !STRICT *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ifdef UNICODE
        PROPENUMPROC typedef PROPENUMPROCW
        PROPENUMPROCEX typedef PROPENUMPROCEXW
        EDITWORDBREAKPROC typedef EDITWORDBREAKPROCW
        ;* !UNICODE *
      else
        PROPENUMPROC typedef PROPENUMPROCA
        PROPENUMPROCEX typedef PROPENUMPROCEXA
        EDITWORDBREAKPROC typedef EDITWORDBREAKPROCA
        ;* UNICODE *
      endif
      ifdef STRICT
        TYPE_NAMEENUMPROCA typedef proto WIN_STD_CALL_CONV :LPSTR, :LPARAM
        NAMEENUMPROCA typedef ptr TYPE_NAMEENUMPROCA

        TYPE_NAMEENUMPROCW typedef proto WIN_STD_CALL_CONV :LPWSTR, :LPARAM
        NAMEENUMPROCW typedef ptr TYPE_NAMEENUMPROCW

        WINSTAENUMPROCA typedef NAMEENUMPROCA
        DESKTOPENUMPROCA typedef NAMEENUMPROCA
        WINSTAENUMPROCW typedef NAMEENUMPROCW
        DESKTOPENUMPROCW typedef NAMEENUMPROCW
        ;* !STRICT *
      else
        NAMEENUMPROCA typedef FARPROC
        NAMEENUMPROCW typedef FARPROC
        WINSTAENUMPROCA typedef FARPROC
        DESKTOPENUMPROCA typedef FARPROC
        WINSTAENUMPROCW typedef FARPROC
        DESKTOPENUMPROCW typedef FARPROC
        ;* !STRICT *
      endif
      ifdef UNICODE
        WINSTAENUMPROC typedef WINSTAENUMPROCW
        DESKTOPENUMPROC typedef DESKTOPENUMPROCW
        ;* !UNICODE *
      else
        WINSTAENUMPROC typedef WINSTAENUMPROCA
        DESKTOPENUMPROC typedef DESKTOPENUMPROCA
        ;* UNICODE *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    IS_INTRESOURCE macro _r
      exitm <((((_r)) shr 16) == 0)>
    endm
    MAKEINTRESOURCEA macro i
      exitm <((((i))))>
    endm
    MAKEINTRESOURCEW macro i
      exitm <((((i))))>
    endm
    ifdef UNICODE
      MAKEINTRESOURCE equ <MAKEINTRESOURCEW>
    else
      MAKEINTRESOURCE equ <MAKEINTRESOURCEA>
    endif
    ; !UNICODE
    ifndef NORESOURCE
      ;*
      ;* Predefined Resource Types
      ;*
      RT_CURSOR equ MAKEINTRESOURCE (1)
      RT_BITMAP equ MAKEINTRESOURCE (2)
      RT_ICON equ MAKEINTRESOURCE (3)
      RT_MENU equ MAKEINTRESOURCE (4)
      RT_DIALOG equ MAKEINTRESOURCE (5)
      RT_STRING equ MAKEINTRESOURCE (6)
      RT_FONTDIR equ MAKEINTRESOURCE (7)
      RT_FONT equ MAKEINTRESOURCE (8)
      RT_ACCELERATOR equ MAKEINTRESOURCE (9)
      RT_RCDATA equ MAKEINTRESOURCE (10)
      RT_MESSAGETABLE equ MAKEINTRESOURCE (11)
      DIFFERENCE equ 11
      RT_GROUP_CURSOR equ <MAKEINTRESOURCE ((RT_CURSOR) + DIFFERENCE)>
      RT_GROUP_ICON equ <MAKEINTRESOURCE ((RT_ICON) + DIFFERENCE)>
      RT_VERSION equ MAKEINTRESOURCE (16)
      RT_DLGINCLUDE equ MAKEINTRESOURCE (17)
      if (WINVER ge 0400h)
        RT_PLUGPLAY equ MAKEINTRESOURCE (19)
        RT_VXD equ MAKEINTRESOURCE (20)
        RT_ANICURSOR equ MAKEINTRESOURCE (21)
        RT_ANIICON equ MAKEINTRESOURCE (22)
        ;* WINVER >= 0x0400 *
      endif
      RT_HTML equ MAKEINTRESOURCE (23)
      ifdef RC_INVOKED
        ;[...]
      else
        RT_MANIFEST equ MAKEINTRESOURCE (24)
        CREATEPROCESS_MANIFEST_RESOURCE_ID equ MAKEINTRESOURCE (1)
        ISOLATIONAWARE_MANIFEST_RESOURCE_ID equ MAKEINTRESOURCE (2)
        ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID equ MAKEINTRESOURCE (3)
        ISOLATIONPOLICY_MANIFEST_RESOURCE_ID equ MAKEINTRESOURCE (4)
        ISOLATIONPOLICY_BROWSER_MANIFEST_RESOURCE_ID equ MAKEINTRESOURCE (5)
        ;*inclusive*
        MINIMUM_RESERVED_MANIFEST_RESOURCE_ID equ MAKEINTRESOURCE (1)
        ;*inclusive*
        MAXIMUM_RESERVED_MANIFEST_RESOURCE_ID equ MAKEINTRESOURCE (16)
        ;* RC_INVOKED *
      endif
      ;* !NORESOURCE *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      if Defined(DEPRECATE_SUPPORTED)
      endif
      @DefProto DllImport, wvsprintfA, WIN_STD_CALL_CONV,, <:LPSTR, :LPCSTR, :va_list>, 12
      @DefProto DllImport, wvsprintfW, WIN_STD_CALL_CONV,, <:LPWSTR, :LPCWSTR, :va_list>, 12
      ifdef UNICODE
        wvsprintf equ <wvsprintfW>
      else
        wvsprintf equ <wvsprintfA>
      endif
      ; !UNICODE
      @DefProto DllImport, wsprintfA, c,, <:LPSTR, :LPCSTR, :vararg>
      @DefProto DllImport, wsprintfW, c,, <:LPWSTR, :LPCWSTR, :vararg>
      ifdef UNICODE
        wsprintf equ <wsprintfW>
      else
        wsprintf equ <wsprintfA>
      endif
      ; !UNICODE
      if Defined(DEPRECATE_SUPPORTED)
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ;*
    ;* SPI_SETDESKWALLPAPER defined constants
    ;*
    SETWALLPAPER_DEFAULT equ (- 1)
    ifndef NOSCROLL
      ;*
      ;* Scroll Bar Constants
      ;*
      SB_HORZ equ 0
      SB_VERT equ 1
      SB_CTL equ 2
      SB_BOTH equ 3
      ;*
      ;* Scroll Bar Commands
      ;*
      SB_LINEUP equ 0
      SB_LINELEFT equ 0
      SB_LINEDOWN equ 1
      SB_LINERIGHT equ 1
      SB_PAGEUP equ 2
      SB_PAGELEFT equ 2
      SB_PAGEDOWN equ 3
      SB_PAGERIGHT equ 3
      SB_THUMBPOSITION equ 4
      SB_THUMBTRACK equ 5
      SB_TOP equ 6
      SB_LEFT equ 6
      SB_BOTTOM equ 7
      SB_RIGHT equ 7
      SB_ENDSCROLL equ 8
      ;* !NOSCROLL *
    endif
    ifndef NOSHOWWINDOW
      ;*
      ;* ShowWindow() Commands
      ;*
      SW_HIDE equ 0
      SW_SHOWNORMAL equ 1
      SW_NORMAL equ 1
      SW_SHOWMINIMIZED equ 2
      SW_SHOWMAXIMIZED equ 3
      SW_MAXIMIZE equ 3
      SW_SHOWNOACTIVATE equ 4
      SW_SHOW equ 5
      SW_MINIMIZE equ 6
      SW_SHOWMINNOACTIVE equ 7
      SW_SHOWNA equ 8
      SW_RESTORE equ 9
      SW_SHOWDEFAULT equ 10
      SW_FORCEMINIMIZE equ 11
      SW_MAX equ 11
      ;*
      ;* Old ShowWindow() Commands
      ;*
      HIDE_WINDOW equ 0
      SHOW_OPENWINDOW equ 1
      SHOW_ICONWINDOW equ 2
      SHOW_FULLSCREEN equ 3
      SHOW_OPENNOACTIVATE equ 4
      ;*
      ;* Identifiers for the WM_SHOWWINDOW message
      ;*
      SW_PARENTCLOSING equ 1
      SW_OTHERZOOM equ 2
      SW_PARENTOPENING equ 3
      SW_OTHERUNZOOM equ 4
      ;* !NOSHOWWINDOW *
    endif
    if (WINVER ge 0500h)
      ;*
      ;* AnimateWindow() Commands
      ;*
      AW_HOR_POSITIVE equ 00000001h
      AW_HOR_NEGATIVE equ 00000002h
      AW_VER_POSITIVE equ 00000004h
      AW_VER_NEGATIVE equ 00000008h
      AW_CENTER equ 00000010h
      AW_HIDE equ 00010000h
      AW_ACTIVATE equ 00020000h
      AW_SLIDE equ 00040000h
      AW_BLEND equ 00080000h
      ;* WINVER >= 0x0500 *
    endif
    ;*
    ;* WM_KEYUP/DOWN/CHAR HIWORD(lParam) flags
    ;*
    KF_EXTENDED equ 0100h
    KF_DLGMODE equ 0800h
    KF_MENUMODE equ 1000h
    KF_ALTDOWN equ 2000h
    KF_REPEAT equ 4000h
    KF_UP equ 8000h
    ifndef NOVIRTUALKEYCODES
      ;*
      ;* Virtual Keys, Standard Set
      ;*
      VK_LBUTTON equ 01h
      VK_RBUTTON equ 02h
      VK_CANCEL equ 03h
      ;* NOT contiguous with L & RBUTTON *
      VK_MBUTTON equ 04h
      if (_WIN32_WINNT ge 0500h)
        ;* NOT contiguous with L & RBUTTON *
        VK_XBUTTON1 equ 05h
        ;* NOT contiguous with L & RBUTTON *
        VK_XBUTTON2 equ 06h
        ;* _WIN32_WINNT >= 0x0500 *
      endif
      ;*
      ;* 0x07 : reserved
      ;*
      VK_BACK equ 08h
      VK_TAB equ 09h
      ;*
      ;* 0x0A - 0x0B : reserved
      ;*
      VK_CLEAR equ 0Ch
      VK_RETURN equ 0Dh
      ;*
      ;* 0x0E - 0x0F : unassigned
      ;*
      VK_SHIFT equ 10h
      VK_CONTROL equ 11h
      VK_MENU equ 12h
      VK_PAUSE equ 13h
      VK_CAPITAL equ 14h
      VK_KANA equ 15h
      ;* old name - should be here for compatibility *
      VK_HANGEUL equ 15h
      VK_HANGUL equ 15h
      VK_IME_ON equ 16h
      VK_JUNJA equ 17h
      VK_FINAL equ 18h
      VK_HANJA equ 19h
      VK_KANJI equ 19h
      VK_IME_OFF equ 1Ah
      VK_ESCAPE equ 1Bh
      VK_CONVERT equ 1Ch
      VK_NONCONVERT equ 1Dh
      VK_ACCEPT equ 1Eh
      VK_MODECHANGE equ 1Fh
      VK_SPACE equ 20h
      VK_PRIOR equ 21h
      VK_NEXT equ 22h
      VK_END equ 23h
      VK_HOME equ 24h
      VK_LEFT equ 25h
      VK_UP equ 26h
      VK_RIGHT equ 27h
      VK_DOWN equ 28h
      VK_SELECT equ 29h
      VK_PRINT equ 2Ah
      VK_EXECUTE equ 2Bh
      VK_SNAPSHOT equ 2Ch
      VK_INSERT equ 2Dh
      VK_DELETE equ 2Eh
      VK_HELP equ 2Fh
      ;*
      ;* VK_0 - VK_9 are the same as ASCII '0' - '9' (0x30 - 0x39)
      ;* 0x3A - 0x40 : unassigned
      ;* VK_A - VK_Z are the same as ASCII 'A' - 'Z' (0x41 - 0x5A)
      ;*
      VK_LWIN equ 5Bh
      VK_RWIN equ 5Ch
      VK_APPS equ 5Dh
      ;*
      ;* 0x5E : reserved
      ;*
      VK_SLEEP equ 5Fh
      VK_NUMPAD0 equ 60h
      VK_NUMPAD1 equ 61h
      VK_NUMPAD2 equ 62h
      VK_NUMPAD3 equ 63h
      VK_NUMPAD4 equ 64h
      VK_NUMPAD5 equ 65h
      VK_NUMPAD6 equ 66h
      VK_NUMPAD7 equ 67h
      VK_NUMPAD8 equ 68h
      VK_NUMPAD9 equ 69h
      VK_MULTIPLY equ 6Ah
      VK_ADD equ 6Bh
      VK_SEPARATOR equ 6Ch
      VK_SUBTRACT equ 6Dh
      VK_DECIMAL equ 6Eh
      VK_DIVIDE equ 6Fh
      VK_F1 equ 70h
      VK_F2 equ 71h
      VK_F3 equ 72h
      VK_F4 equ 73h
      VK_F5 equ 74h
      VK_F6 equ 75h
      VK_F7 equ 76h
      VK_F8 equ 77h
      VK_F9 equ 78h
      VK_F10 equ 79h
      VK_F11 equ 7Ah
      VK_F12 equ 7Bh
      VK_F13 equ 7Ch
      VK_F14 equ 7Dh
      VK_F15 equ 7Eh
      VK_F16 equ 7Fh
      VK_F17 equ 80h
      VK_F18 equ 81h
      VK_F19 equ 82h
      VK_F20 equ 83h
      VK_F21 equ 84h
      VK_F22 equ 85h
      VK_F23 equ 86h
      VK_F24 equ 87h
      if (_WIN32_WINNT ge 0604h)
        ;*
        ;* 0x88 - 0x8F : UI navigation
        ;*
        VK_NAVIGATION_VIEW equ 88h; reserved

        VK_NAVIGATION_MENU equ 89h; reserved

        VK_NAVIGATION_UP equ 8Ah; reserved

        VK_NAVIGATION_DOWN equ 8Bh; reserved

        VK_NAVIGATION_LEFT equ 8Ch; reserved

        VK_NAVIGATION_RIGHT equ 8Dh; reserved

        VK_NAVIGATION_ACCEPT equ 8Eh; reserved

        VK_NAVIGATION_CANCEL equ 8Fh; reserved

        ;* _WIN32_WINNT >= 0x0604 *
      endif
      VK_NUMLOCK equ 90h
      VK_SCROLL equ 91h
      ;*
      ;* NEC PC-9800 kbd definitions
      ;*
      VK_OEM_NEC_EQUAL equ 92h; '=' key on numpad

      ;*
      ;* Fujitsu/OASYS kbd definitions
      ;*
      VK_OEM_FJ_JISHO equ 92h; 'Dictionary' key

      VK_OEM_FJ_MASSHOU equ 93h; 'Unregister word' key

      VK_OEM_FJ_TOUROKU equ 94h; 'Register word' key

      VK_OEM_FJ_LOYA equ 95h; 'Left OYAYUBI' key

      VK_OEM_FJ_ROYA equ 96h; 'Right OYAYUBI' key

      ;*
      ;* 0x97 - 0x9F : unassigned
      ;*
      ;*
      ;* VK_L* & VK_R* - left and right Alt, Ctrl and Shift virtual keys.
      ;* Used only as parameters to GetAsyncKeyState() and GetKeyState().
      ;* No other API or message will distinguish left and right keys in this way.
      ;*
      VK_LSHIFT equ 0A0h
      VK_RSHIFT equ 0A1h
      VK_LCONTROL equ 0A2h
      VK_RCONTROL equ 0A3h
      VK_LMENU equ 0A4h
      VK_RMENU equ 0A5h
      if (_WIN32_WINNT ge 0500h)
        VK_BROWSER_BACK equ 0A6h
        VK_BROWSER_FORWARD equ 0A7h
        VK_BROWSER_REFRESH equ 0A8h
        VK_BROWSER_STOP equ 0A9h
        VK_BROWSER_SEARCH equ 0AAh
        VK_BROWSER_FAVORITES equ 0ABh
        VK_BROWSER_HOME equ 0ACh
        VK_VOLUME_MUTE equ 0ADh
        VK_VOLUME_DOWN equ 0AEh
        VK_VOLUME_UP equ 0AFh
        VK_MEDIA_NEXT_TRACK equ 0B0h
        VK_MEDIA_PREV_TRACK equ 0B1h
        VK_MEDIA_STOP equ 0B2h
        VK_MEDIA_PLAY_PAUSE equ 0B3h
        VK_LAUNCH_MAIL equ 0B4h
        VK_LAUNCH_MEDIA_SELECT equ 0B5h
        VK_LAUNCH_APP1 equ 0B6h
        VK_LAUNCH_APP2 equ 0B7h
        ;* _WIN32_WINNT >= 0x0500 *
      endif
      ;*
      ;* 0xB8 - 0xB9 : reserved
      ;*
      VK_OEM_1 equ 0BAh; ';:' for US

      VK_OEM_PLUS equ 0BBh; '+' any country

      VK_OEM_COMMA equ 0BCh; ',' any country

      VK_OEM_MINUS equ 0BDh; '-' any country

      VK_OEM_PERIOD equ 0BEh; '.' any country

      VK_OEM_2 equ 0BFh; '/?' for US

      VK_OEM_3 equ 0C0h; '`~' for US

      ;*
      ;* 0xC1 - 0xC2 : reserved
      ;*
      if (_WIN32_WINNT ge 0604h)
        ;*
        ;* 0xC3 - 0xDA : Gamepad input
        ;*
        VK_GAMEPAD_A equ 0C3h; reserved

        VK_GAMEPAD_B equ 0C4h; reserved

        VK_GAMEPAD_X equ 0C5h; reserved

        VK_GAMEPAD_Y equ 0C6h; reserved

        VK_GAMEPAD_RIGHT_SHOULDER equ 0C7h; reserved

        VK_GAMEPAD_LEFT_SHOULDER equ 0C8h; reserved

        VK_GAMEPAD_LEFT_TRIGGER equ 0C9h; reserved

        VK_GAMEPAD_RIGHT_TRIGGER equ 0CAh; reserved

        VK_GAMEPAD_DPAD_UP equ 0CBh; reserved

        VK_GAMEPAD_DPAD_DOWN equ 0CCh; reserved

        VK_GAMEPAD_DPAD_LEFT equ 0CDh; reserved

        VK_GAMEPAD_DPAD_RIGHT equ 0CEh; reserved

        VK_GAMEPAD_MENU equ 0CFh; reserved

        VK_GAMEPAD_VIEW equ 0D0h; reserved

        VK_GAMEPAD_LEFT_THUMBSTICK_BUTTON equ 0D1h; reserved

        VK_GAMEPAD_RIGHT_THUMBSTICK_BUTTON equ 0D2h; reserved

        VK_GAMEPAD_LEFT_THUMBSTICK_UP equ 0D3h; reserved

        VK_GAMEPAD_LEFT_THUMBSTICK_DOWN equ 0D4h; reserved

        VK_GAMEPAD_LEFT_THUMBSTICK_RIGHT equ 0D5h; reserved

        VK_GAMEPAD_LEFT_THUMBSTICK_LEFT equ 0D6h; reserved

        VK_GAMEPAD_RIGHT_THUMBSTICK_UP equ 0D7h; reserved

        VK_GAMEPAD_RIGHT_THUMBSTICK_DOWN equ 0D8h; reserved

        VK_GAMEPAD_RIGHT_THUMBSTICK_RIGHT equ 0D9h; reserved

        VK_GAMEPAD_RIGHT_THUMBSTICK_LEFT equ 0DAh; reserved

        ;* _WIN32_WINNT >= 0x0604 *
      endif
      VK_OEM_4 equ 0DBh;  '[{' for US

      VK_OEM_5 equ 0DCh;  '\|' for US

      VK_OEM_6 equ 0DDh;  ']}' for US

      VK_OEM_7 equ 0DEh;  ''"' for US

      VK_OEM_8 equ 0DFh
      ;*
      ;* 0xE0 : reserved
      ;*
      ;*
      ;* Various extended or enhanced keyboards
      ;*
      VK_OEM_AX equ 0E1h;  'AX' key on Japanese AX kbd

      VK_OEM_102 equ 0E2h;  "<>" or "\|" on RT 102-key kbd.

      VK_ICO_HELP equ 0E3h;  Help key on ICO

      VK_ICO_00 equ 0E4h;  00 key on ICO

      if (WINVER ge 0400h)
        VK_PROCESSKEY equ 0E5h
        ;* WINVER >= 0x0400 *
      endif
      VK_ICO_CLEAR equ 0E6h
      if (_WIN32_WINNT ge 0500h)
        VK_PACKET equ 0E7h
        ;* _WIN32_WINNT >= 0x0500 *
      endif
      ;*
      ;* 0xE8 : unassigned
      ;*
      ;*
      ;* Nokia/Ericsson definitions
      ;*
      VK_OEM_RESET equ 0E9h
      VK_OEM_JUMP equ 0EAh
      VK_OEM_PA1 equ 0EBh
      VK_OEM_PA2 equ 0ECh
      VK_OEM_PA3 equ 0EDh
      VK_OEM_WSCTRL equ 0EEh
      VK_OEM_CUSEL equ 0EFh
      VK_OEM_ATTN equ 0F0h
      VK_OEM_FINISH equ 0F1h
      VK_OEM_COPY equ 0F2h
      VK_OEM_AUTO equ 0F3h
      VK_OEM_ENLW equ 0F4h
      VK_OEM_BACKTAB equ 0F5h
      VK_ATTN equ 0F6h
      VK_CRSEL equ 0F7h
      VK_EXSEL equ 0F8h
      VK_EREOF equ 0F9h
      VK_PLAY equ 0FAh
      VK_ZOOM equ 0FBh
      VK_NONAME equ 0FCh
      VK_PA1 equ 0FDh
      VK_OEM_CLEAR equ 0FEh
      ;*
      ;* 0xFF : reserved
      ;*
      ;* !NOVIRTUALKEYCODES *
    endif
    ifndef NOWH
      ;*
      ;* SetWindowsHook() codes
      ;*
      WH_MIN equ (- 1)
      WH_MSGFILTER equ (- 1)
      WH_JOURNALRECORD equ 0
      WH_JOURNALPLAYBACK equ 1
      WH_KEYBOARD equ 2
      WH_GETMESSAGE equ 3
      WH_CALLWNDPROC equ 4
      WH_CBT equ 5
      WH_SYSMSGFILTER equ 6
      WH_MOUSE equ 7
      if Defined(_WIN32_WINDOWS)
        WH_HARDWARE equ 8
      endif
      WH_DEBUG equ 9
      WH_SHELL equ 10
      WH_FOREGROUNDIDLE equ 11
      if (WINVER ge 0400h)
        WH_CALLWNDPROCRET equ 12
        ;* WINVER >= 0x0400 *
      endif
      if (_WIN32_WINNT ge 0400h)
        WH_KEYBOARD_LL equ 13
        WH_MOUSE_LL equ 14
      endif
      ; (_WIN32_WINNT >= 0x0400)
      if (WINVER ge 0400h)
        if (_WIN32_WINNT ge 0400h)
          WH_MAX equ 14
        else
          WH_MAX equ 12
        endif
        ; (_WIN32_WINNT >= 0x0400)
      else
        WH_MAX equ 11
      endif
      WH_MINHOOK equ <WH_MIN>
      WH_MAXHOOK equ <WH_MAX>
      ;*
      ;* Hook Codes
      ;*
      HC_ACTION equ 0
      HC_GETNEXT equ 1
      HC_SKIP equ 2
      HC_NOREMOVE equ 3
      HC_NOREM equ <HC_NOREMOVE>
      HC_SYSMODALON equ 4
      HC_SYSMODALOFF equ 5
      ;*
      ;* CBT Hook Codes
      ;*
      HCBT_MOVESIZE equ 0
      HCBT_MINMAX equ 1
      HCBT_QS equ 2
      HCBT_CREATEWND equ 3
      HCBT_DESTROYWND equ 4
      HCBT_ACTIVATE equ 5
      HCBT_CLICKSKIPPED equ 6
      HCBT_KEYSKIPPED equ 7
      HCBT_SYSCOMMAND equ 8
      HCBT_SETFOCUS equ 9
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        ;*
        ;* HCBT_CREATEWND parameters pointed to by lParam
        ;*
        CBT_CREATEWNDA struct
          lpcs POINTER ?
          hwndInsertAfter HWND ?
        CBT_CREATEWNDA ends
        tagCBT_CREATEWNDA typedef CBT_CREATEWNDA
        LPCBT_CREATEWNDA typedef ptr CBT_CREATEWNDA
        ;*
        ;* HCBT_CREATEWND parameters pointed to by lParam
        ;*
        CBT_CREATEWNDW struct
          lpcs POINTER ?
          hwndInsertAfter HWND ?
        CBT_CREATEWNDW ends
        tagCBT_CREATEWNDW typedef CBT_CREATEWNDW
        LPCBT_CREATEWNDW typedef ptr CBT_CREATEWNDW
        ifdef UNICODE
          CBT_CREATEWND typedef CBT_CREATEWNDW
          LPCBT_CREATEWND typedef LPCBT_CREATEWNDW
        else
          CBT_CREATEWND typedef CBT_CREATEWNDA
          LPCBT_CREATEWND typedef LPCBT_CREATEWNDA
        endif
        ; UNICODE
        ;*
        ;* HCBT_ACTIVATE structure pointed to by lParam
        ;*
        CBTACTIVATESTRUCT struct
          fMouse DWORD ?
          hWndActive HWND ?
        CBTACTIVATESTRUCT ends
        tagCBTACTIVATESTRUCT typedef CBTACTIVATESTRUCT
        LPCBTACTIVATESTRUCT typedef ptr CBTACTIVATESTRUCT
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      if (_WIN32_WINNT ge 0501h)
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
          ;*
          ;* WTSSESSION_NOTIFICATION struct pointed by lParam, for WM_WTSSESSION_CHANGE
          ;*
          WTSSESSION_NOTIFICATION struct
            cbSize DWORD ?
            dwSessionId DWORD ?
          WTSSESSION_NOTIFICATION ends
          tagWTSSESSION_NOTIFICATION typedef WTSSESSION_NOTIFICATION
          PWTSSESSION_NOTIFICATION typedef ptr WTSSESSION_NOTIFICATION
          ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
        endif
        ;*
        ;* codes passed in WPARAM for WM_WTSSESSION_CHANGE
        ;*
        WTS_CONSOLE_CONNECT equ 1h
        WTS_CONSOLE_DISCONNECT equ 2h
        WTS_REMOTE_CONNECT equ 3h
        WTS_REMOTE_DISCONNECT equ 4h
        WTS_SESSION_LOGON equ 5h
        WTS_SESSION_LOGOFF equ 6h
        WTS_SESSION_LOCK equ 7h
        WTS_SESSION_UNLOCK equ 8h
        WTS_SESSION_REMOTE_CONTROL equ 9h
        WTS_SESSION_CREATE equ 0ah
        WTS_SESSION_TERMINATE equ 0bh
        ;* _WIN32_WINNT >= 0x0501 *
      endif
      ;*
      ;* WH_MSGFILTER Filter Proc Codes
      ;*
      MSGF_DIALOGBOX equ 0
      MSGF_MESSAGEBOX equ 1
      MSGF_MENU equ 2
      MSGF_SCROLLBAR equ 5
      MSGF_NEXTWINDOW equ 6
      MSGF_MAX equ 8; unused

      MSGF_USER equ 4096
      ;*
      ;* Shell support
      ;*
      HSHELL_WINDOWCREATED equ 1
      HSHELL_WINDOWDESTROYED equ 2
      HSHELL_ACTIVATESHELLWINDOW equ 3
      if (WINVER ge 0400h)
        HSHELL_WINDOWACTIVATED equ 4
        HSHELL_GETMINRECT equ 5
        HSHELL_REDRAW equ 6
        HSHELL_TASKMAN equ 7
        HSHELL_LANGUAGE equ 8
        HSHELL_SYSMENU equ 9
        HSHELL_ENDTASK equ 10
        ;* WINVER >= 0x0400 *
      endif
      if (_WIN32_WINNT ge 0500h)
        HSHELL_ACCESSIBILITYSTATE equ 11
        HSHELL_APPCOMMAND equ 12
        ;* _WIN32_WINNT >= 0x0500 *
      endif
      if (_WIN32_WINNT ge 0501h)
        HSHELL_WINDOWREPLACED equ 13
        HSHELL_WINDOWREPLACING equ 14
        ;* _WIN32_WINNT >= 0x0501 *
      endif
      if (_WIN32_WINNT ge 0602h)
        HSHELL_MONITORCHANGED equ 16
        if (NTDDI_VERSION ge NTDDI_WIN10_RS3)
        endif
        ; NTDDI_VERSION >= NTDDI_WIN10_RS3
        ;* _WIN32_WINNT >= 0x0602 *
      endif
      HSHELL_HIGHBIT equ 8000h
      HSHELL_FLASH equ <(HSHELL_REDRAW or HSHELL_HIGHBIT)>
      HSHELL_RUDEAPPACTIVATED equ <(HSHELL_WINDOWACTIVATED or HSHELL_HIGHBIT)>
      if (_WIN32_WINNT ge 0500h)
        ;* cmd for HSHELL_APPCOMMAND and WM_APPCOMMAND *
        APPCOMMAND_BROWSER_BACKWARD equ 1
        APPCOMMAND_BROWSER_FORWARD equ 2
        APPCOMMAND_BROWSER_REFRESH equ 3
        APPCOMMAND_BROWSER_STOP equ 4
        APPCOMMAND_BROWSER_SEARCH equ 5
        APPCOMMAND_BROWSER_FAVORITES equ 6
        APPCOMMAND_BROWSER_HOME equ 7
        APPCOMMAND_VOLUME_MUTE equ 8
        APPCOMMAND_VOLUME_DOWN equ 9
        APPCOMMAND_VOLUME_UP equ 10
        APPCOMMAND_MEDIA_NEXTTRACK equ 11
        APPCOMMAND_MEDIA_PREVIOUSTRACK equ 12
        APPCOMMAND_MEDIA_STOP equ 13
        APPCOMMAND_MEDIA_PLAY_PAUSE equ 14
        APPCOMMAND_LAUNCH_MAIL equ 15
        APPCOMMAND_LAUNCH_MEDIA_SELECT equ 16
        APPCOMMAND_LAUNCH_APP1 equ 17
        APPCOMMAND_LAUNCH_APP2 equ 18
        APPCOMMAND_BASS_DOWN equ 19
        APPCOMMAND_BASS_BOOST equ 20
        APPCOMMAND_BASS_UP equ 21
        APPCOMMAND_TREBLE_DOWN equ 22
        APPCOMMAND_TREBLE_UP equ 23
        if (_WIN32_WINNT ge 0501h)
          APPCOMMAND_MICROPHONE_VOLUME_MUTE equ 24
          APPCOMMAND_MICROPHONE_VOLUME_DOWN equ 25
          APPCOMMAND_MICROPHONE_VOLUME_UP equ 26
          APPCOMMAND_HELP equ 27
          APPCOMMAND_FIND equ 28
          APPCOMMAND_NEW equ 29
          APPCOMMAND_OPEN equ 30
          APPCOMMAND_CLOSE equ 31
          APPCOMMAND_SAVE equ 32
          APPCOMMAND_PRINT equ 33
          APPCOMMAND_UNDO equ 34
          APPCOMMAND_REDO equ 35
          APPCOMMAND_COPY equ 36
          APPCOMMAND_CUT equ 37
          APPCOMMAND_PASTE equ 38
          APPCOMMAND_REPLY_TO_MAIL equ 39
          APPCOMMAND_FORWARD_MAIL equ 40
          APPCOMMAND_SEND_MAIL equ 41
          APPCOMMAND_SPELL_CHECK equ 42
          APPCOMMAND_DICTATE_OR_COMMAND_CONTROL_TOGGLE equ 43
          APPCOMMAND_MIC_ON_OFF_TOGGLE equ 44
          APPCOMMAND_CORRECTION_LIST equ 45
          APPCOMMAND_MEDIA_PLAY equ 46
          APPCOMMAND_MEDIA_PAUSE equ 47
          APPCOMMAND_MEDIA_RECORD equ 48
          APPCOMMAND_MEDIA_FAST_FORWARD equ 49
          APPCOMMAND_MEDIA_REWIND equ 50
          APPCOMMAND_MEDIA_CHANNEL_UP equ 51
          APPCOMMAND_MEDIA_CHANNEL_DOWN equ 52
          ;* _WIN32_WINNT >= 0x0501 *
        endif
        if (_WIN32_WINNT ge 0600h)
          APPCOMMAND_DELETE equ 53
          APPCOMMAND_DWM_FLIP3D equ 54
          ;* _WIN32_WINNT >= 0x0600 *
        endif
        FAPPCOMMAND_MOUSE equ 8000h
        FAPPCOMMAND_KEY equ 0
        FAPPCOMMAND_OEM equ 1000h
        FAPPCOMMAND_MASK equ 0F000h
        GET_APPCOMMAND_LPARAM macro lParam
          exitm <((HIWORD(lParam) and not FAPPCOMMAND_MASK))>
        endm
        GET_DEVICE_LPARAM macro lParam
          exitm <((HIWORD(lParam) and FAPPCOMMAND_MASK))>
        endm
        GET_MOUSEORKEY_LPARAM equ <GET_DEVICE_LPARAM>
        GET_FLAGS_LPARAM macro lParam
          exitm <(LOWORD(lParam))>
        endm
        GET_KEYSTATE_LPARAM macro lParam
          exitm <GET_FLAGS_LPARAM(lParam)>
        endm
        ;* _WIN32_WINNT >= 0x0500 *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        SHELLHOOKINFO struct
          hwnd HWND ?
          rc RECT <>
        SHELLHOOKINFO ends
        LPSHELLHOOKINFO typedef ptr SHELLHOOKINFO
        ;*
        ;* Message Structure used in Journaling
        ;*
        EVENTMSG struct
          message DWORD ?
          paramL DWORD ?
          paramH DWORD ?
          time DWORD ?
          hwnd HWND ?
        EVENTMSG ends
        tagEVENTMSG typedef EVENTMSG
        PEVENTMSGMSG typedef ptr EVENTMSG
        NPEVENTMSGMSG typedef ptr EVENTMSG
        LPEVENTMSGMSG typedef ptr EVENTMSG
        PEVENTMSG typedef ptr tagEVENTMSG
        NPEVENTMSG typedef ptr tagEVENTMSG
        LPEVENTMSG typedef ptr tagEVENTMSG
        ;*
        ;* Message structure used by WH_CALLWNDPROC
        ;*
        CWPSTRUCT struct
          lParam LPARAM ?
          wParam WPARAM ?
          message DWORD ?
          hwnd HWND ?
        CWPSTRUCT ends
        tagCWPSTRUCT typedef CWPSTRUCT
        PCWPSTRUCT typedef ptr CWPSTRUCT
        NPCWPSTRUCT typedef ptr CWPSTRUCT
        LPCWPSTRUCT typedef ptr CWPSTRUCT
        if (WINVER ge 0400h)
          ;*
          ;* Message structure used by WH_CALLWNDPROCRET
          ;*
          CWPRETSTRUCT struct
            lResult LRESULT ?
            lParam LPARAM ?
            wParam WPARAM ?
            message DWORD ?
            hwnd HWND ?
          CWPRETSTRUCT ends
          tagCWPRETSTRUCT typedef CWPRETSTRUCT
          PCWPRETSTRUCT typedef ptr CWPRETSTRUCT
          NPCWPRETSTRUCT typedef ptr CWPRETSTRUCT
          LPCWPRETSTRUCT typedef ptr CWPRETSTRUCT
          ;* WINVER >= 0x0400 *
        endif
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      if (_WIN32_WINNT ge 0400h)
        ;*
        ;* Low level hook flags
        ;*
        ;* 0x00000001 *
        LLKHF_EXTENDED equ (KF_EXTENDED shr 8)
        LLKHF_INJECTED equ 00000010h
        ;* 0x00000020 *
        LLKHF_ALTDOWN equ (KF_ALTDOWN shr 8)
        ;* 0x00000080 *
        LLKHF_UP equ (KF_UP shr 8)
        LLKHF_LOWER_IL_INJECTED equ 00000002h
        LLMHF_INJECTED equ 00000001h
        LLMHF_LOWER_IL_INJECTED equ 00000002h
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
          ;*
          ;* Structure used by WH_KEYBOARD_LL
          ;*
          KBDLLHOOKSTRUCT struct
            vkCode DWORD ?
            scanCode DWORD ?
            flags DWORD ?
            time DWORD ?
            dwExtraInfo XWORD ?
          KBDLLHOOKSTRUCT ends
          tagKBDLLHOOKSTRUCT typedef KBDLLHOOKSTRUCT
          LPKBDLLHOOKSTRUCT typedef ptr KBDLLHOOKSTRUCT
          PKBDLLHOOKSTRUCT typedef ptr KBDLLHOOKSTRUCT
          ;*
          ;* Structure used by WH_MOUSE_LL
          ;*
          MSLLHOOKSTRUCT struct
            pt POINT <>
            mouseData DWORD ?
            flags DWORD ?
            time DWORD ?
            dwExtraInfo XWORD ?
          MSLLHOOKSTRUCT ends
          tagMSLLHOOKSTRUCT typedef MSLLHOOKSTRUCT
          LPMSLLHOOKSTRUCT typedef ptr MSLLHOOKSTRUCT
          PMSLLHOOKSTRUCT typedef ptr MSLLHOOKSTRUCT
          ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
        endif
      endif
      ; (_WIN32_WINNT >= 0x0400)
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        ;*
        ;* Structure used by WH_DEBUG
        ;*
        DEBUGHOOKINFO struct
          idThread DWORD ?
          idThreadInstaller DWORD ?
          lParam LPARAM ?
          wParam WPARAM ?
          code SDWORD ?
        DEBUGHOOKINFO ends
        tagDEBUGHOOKINFO typedef DEBUGHOOKINFO
        PDEBUGHOOKINFO typedef ptr DEBUGHOOKINFO
        NPDEBUGHOOKINFO typedef ptr DEBUGHOOKINFO
        LPDEBUGHOOKINFO typedef ptr DEBUGHOOKINFO
        ;*
        ;* Structure used by WH_MOUSE
        ;*
        MOUSEHOOKSTRUCT struct
          pt POINT <>
          hwnd HWND ?
          wHitTestCode DWORD ?
          dwExtraInfo XWORD ?
        MOUSEHOOKSTRUCT ends
        tagMOUSEHOOKSTRUCT typedef MOUSEHOOKSTRUCT
        LPMOUSEHOOKSTRUCT typedef ptr MOUSEHOOKSTRUCT
        PMOUSEHOOKSTRUCT typedef ptr MOUSEHOOKSTRUCT
        if (_WIN32_WINNT ge 0500h)
          ifdef __cplusplus
            ;[...]
          else
          ; ndef __cplusplus
            MOUSEHOOKSTRUCTEX struct
              DUMMYSTRUCTNAME MOUSEHOOKSTRUCT <>
              mouseData DWORD ?
            MOUSEHOOKSTRUCTEX ends
            tagMOUSEHOOKSTRUCTEX typedef MOUSEHOOKSTRUCTEX
            LPMOUSEHOOKSTRUCTEX typedef ptr MOUSEHOOKSTRUCTEX
            PMOUSEHOOKSTRUCTEX typedef ptr MOUSEHOOKSTRUCTEX
          endif
          ;* _WIN32_WINNT >= 0x0500 *
        endif
        if (WINVER ge 0400h)
          ;*
          ;* Structure used by WH_HARDWARE
          ;*
          HARDWAREHOOKSTRUCT struct
            hwnd HWND ?
            message DWORD ?
            wParam WPARAM ?
            lParam LPARAM ?
          HARDWAREHOOKSTRUCT ends
          tagHARDWAREHOOKSTRUCT typedef HARDWAREHOOKSTRUCT
          LPHARDWAREHOOKSTRUCT typedef ptr HARDWAREHOOKSTRUCT
          PHARDWAREHOOKSTRUCT typedef ptr HARDWAREHOOKSTRUCT
          ;* WINVER >= 0x0400 *
        endif
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;* !NOWH *
    endif
    ;*
    ;* Keyboard Layout API
    ;*
    HKL_PREV equ 0
    HKL_NEXT equ 1
    KLF_ACTIVATE equ 00000001h
    KLF_SUBSTITUTE_OK equ 00000002h
    KLF_REORDER equ 00000008h
    if (WINVER ge 0400h)
      KLF_REPLACELANG equ 00000010h
      KLF_NOTELLSHELL equ 00000080h
      ;* WINVER >= 0x0400 *
    endif
    KLF_SETFORPROCESS equ 00000100h
    if (_WIN32_WINNT ge 0500h)
      KLF_SHIFTLOCK equ 00010000h
      KLF_RESET equ 40000000h
      ;* _WIN32_WINNT >= 0x0500 *
    endif
    if (WINVER ge 0500h)
      ;*
      ;* Bits in wParam of WM_INPUTLANGCHANGEREQUEST message
      ;*
      INPUTLANGCHANGE_SYSCHARSET equ 0001h
      INPUTLANGCHANGE_FORWARD equ 0002h
      INPUTLANGCHANGE_BACKWARD equ 0004h
      ;* WINVER >= 0x0500 *
    endif
    ;*
    ;* Size of KeyboardLayoutName (number of characters), including nul terminator
    ;*
    KL_NAMELENGTH equ 9
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, LoadKeyboardLayoutA, WIN_STD_CALL_CONV,, <:LPCSTR, :UINT>, 8
      @DefProto DllImport, LoadKeyboardLayoutW, WIN_STD_CALL_CONV,, <:LPCWSTR, :UINT>, 8
      ifdef UNICODE
        LoadKeyboardLayout equ <LoadKeyboardLayoutW>
      else
        LoadKeyboardLayout equ <LoadKeyboardLayoutA>
      endif
      ; !UNICODE
      if (WINVER ge 0400h)
        @DefProto DllImport, ActivateKeyboardLayout, WIN_STD_CALL_CONV,, <:HKL, :UINT>, 8
      else
        @DefProto DllImport, ActivateKeyboardLayout, WIN_STD_CALL_CONV,, <:HKL, :UINT>, 8
        ;* WINVER >= 0x0400 *
      endif
      if (WINVER ge 0400h)
        @DefProto DllImport, ToUnicodeEx, WIN_STD_CALL_CONV,, <:UINT, :UINT, :ptr BYTE, :LPWSTR, :SDWORD, :UINT, :HKL>, 28
        ;* WINVER >= 0x0400 *
      endif
      @DefProto DllImport, UnloadKeyboardLayout, WIN_STD_CALL_CONV,, <:HKL>, 4
      @DefProto DllImport, GetKeyboardLayoutNameA, WIN_STD_CALL_CONV,, <:LPSTR>, 4
      @DefProto DllImport, GetKeyboardLayoutNameW, WIN_STD_CALL_CONV,, <:LPWSTR>, 4
      ifdef UNICODE
        GetKeyboardLayoutName equ <GetKeyboardLayoutNameW>
      else
        GetKeyboardLayoutName equ <GetKeyboardLayoutNameA>
      endif
      ; !UNICODE
      if (WINVER ge 0400h)
        @DefProto DllImport, GetKeyboardLayoutList, WIN_STD_CALL_CONV,, <:SDWORD, :ptr HKL>, 8
        @DefProto DllImport, GetKeyboardLayout, WIN_STD_CALL_CONV,, <:DWORD>, 4
        ;* WINVER >= 0x0400 *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if (WINVER ge 0500h)
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        MOUSEMOVEPOINT struct
          x SDWORD ?
          y SDWORD ?
          time DWORD ?
          dwExtraInfo XWORD ?
        MOUSEMOVEPOINT ends
        tagMOUSEMOVEPOINT typedef MOUSEMOVEPOINT
        PMOUSEMOVEPOINT typedef ptr MOUSEMOVEPOINT
        LPMOUSEMOVEPOINT typedef ptr MOUSEMOVEPOINT
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;*
      ;* Values for resolution parameter of GetMouseMovePointsEx
      ;*
      GMMP_USE_DISPLAY_POINTS equ 1
      GMMP_USE_HIGH_RESOLUTION_POINTS equ 2
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, GetMouseMovePointsEx, WIN_STD_CALL_CONV,, <:UINT, :LPMOUSEMOVEPOINT, :LPMOUSEMOVEPOINT, :SDWORD, :DWORD>, 20
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;* WINVER >= 0x0500 *
    endif
    ifndef NODESKTOP
      ;*
      ;* Desktop-specific access flags
      ;*
      DESKTOP_READOBJECTS equ 0001h
      DESKTOP_CREATEWINDOW equ 0002h
      DESKTOP_CREATEMENU equ 0004h
      DESKTOP_HOOKCONTROL equ 0008h
      DESKTOP_JOURNALRECORD equ 0010h
      DESKTOP_JOURNALPLAYBACK equ 0020h
      DESKTOP_ENUMERATE equ 0040h
      DESKTOP_WRITEOBJECTS equ 0080h
      DESKTOP_SWITCHDESKTOP equ 0100h
      ;*
      ;* Desktop-specific control flags
      ;*
      DF_ALLOWOTHERACCOUNTHOOK equ 0001h
      ifdef _WINGDI_
        ifndef NOGDI
          if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
            @DefProto DllImport, CreateDesktopA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :ptr DEVMODEA, :DWORD, :ACCESS_MASK, :LPSECURITY_ATTRIBUTES>, 24
            @DefProto DllImport, CreateDesktopW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :ptr DEVMODEW, :DWORD, :ACCESS_MASK, :LPSECURITY_ATTRIBUTES>, 24
            ifdef UNICODE
              CreateDesktop equ <CreateDesktopW>
            else
              CreateDesktop equ <CreateDesktopA>
            endif
            ; !UNICODE
            @DefProto DllImport, CreateDesktopExA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :ptr DEVMODEA, :DWORD, :ACCESS_MASK, :LPSECURITY_ATTRIBUTES, :ULONG, :PVOID>, 32
            @DefProto DllImport, CreateDesktopExW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :ptr DEVMODEW, :DWORD, :ACCESS_MASK, :LPSECURITY_ATTRIBUTES, :ULONG, :PVOID>, 32
            ifdef UNICODE
              CreateDesktopEx equ <CreateDesktopExW>
            else
              CreateDesktopEx equ <CreateDesktopExA>
            endif
            ; !UNICODE
            ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
          endif
          ;* NOGDI *
        endif
        ;* _WINGDI_ *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, OpenDesktopA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :BOOL, :ACCESS_MASK>, 16
        @DefProto DllImport, OpenDesktopW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :BOOL, :ACCESS_MASK>, 16
        ifdef UNICODE
          OpenDesktop equ <OpenDesktopW>
        else
          OpenDesktop equ <OpenDesktopA>
        endif
        ; !UNICODE
        @DefProto DllImport, OpenInputDesktop, WIN_STD_CALL_CONV,, <:DWORD, :BOOL, :ACCESS_MASK>, 12
        @DefProto DllImport, EnumDesktopsA, WIN_STD_CALL_CONV,, <:HWINSTA, :DESKTOPENUMPROCA, :LPARAM>, 12
        @DefProto DllImport, EnumDesktopsW, WIN_STD_CALL_CONV,, <:HWINSTA, :DESKTOPENUMPROCW, :LPARAM>, 12
        ifdef UNICODE
          EnumDesktops equ <EnumDesktopsW>
        else
          EnumDesktops equ <EnumDesktopsA>
        endif
        ; !UNICODE
        @DefProto DllImport, EnumDesktopWindows, WIN_STD_CALL_CONV,, <:HDESK, :WNDENUMPROC, :LPARAM>, 12
        @DefProto DllImport, SwitchDesktop, WIN_STD_CALL_CONV,, <:HDESK>, 4
        @DefProto DllImport, SetThreadDesktop, WIN_STD_CALL_CONV,, <:HDESK>, 4
        @DefProto DllImport, CloseDesktop, WIN_STD_CALL_CONV,, <:HDESK>, 4
        @DefProto DllImport, GetThreadDesktop, WIN_STD_CALL_CONV,, <:DWORD>, 4
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;* !NODESKTOP *
    endif
    ifndef NOWINDOWSTATION
      ;*
      ;* Windowstation-specific access flags
      ;*
      WINSTA_ENUMDESKTOPS equ 0001h
      WINSTA_READATTRIBUTES equ 0002h
      WINSTA_ACCESSCLIPBOARD equ 0004h
      WINSTA_CREATEDESKTOP equ 0008h
      WINSTA_WRITEATTRIBUTES equ 0010h
      WINSTA_ACCESSGLOBALATOMS equ 0020h
      WINSTA_EXITWINDOWS equ 0040h
      WINSTA_ENUMERATE equ 0100h
      WINSTA_READSCREEN equ 0200h
      WINSTA_ALL_ACCESS equ <(WINSTA_ENUMDESKTOPS or WINSTA_READATTRIBUTES or WINSTA_ACCESSCLIPBOARD or WINSTA_CREATEDESKTOP or WINSTA_WRITEATTRIBUTES or WINSTA_ACCESSGLOBALATOMS or WINSTA_EXITWINDOWS or WINSTA_ENUMERATE or WINSTA_READSCREEN)>
      ;*
      ;* Windowstation creation flags.
      ;*
      CWF_CREATE_ONLY equ 00000001h
      ;*
      ;* Windowstation-specific attribute flags
      ;*
      WSF_VISIBLE equ 0001h
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, CreateWindowStationA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :ACCESS_MASK, :LPSECURITY_ATTRIBUTES>, 16
        @DefProto DllImport, CreateWindowStationW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :ACCESS_MASK, :LPSECURITY_ATTRIBUTES>, 16
        ifdef UNICODE
          CreateWindowStation equ <CreateWindowStationW>
        else
          CreateWindowStation equ <CreateWindowStationA>
        endif
        ; !UNICODE
        @DefProto DllImport, OpenWindowStationA, WIN_STD_CALL_CONV,, <:LPCSTR, :BOOL, :ACCESS_MASK>, 12
        @DefProto DllImport, OpenWindowStationW, WIN_STD_CALL_CONV,, <:LPCWSTR, :BOOL, :ACCESS_MASK>, 12
        ifdef UNICODE
          OpenWindowStation equ <OpenWindowStationW>
        else
          OpenWindowStation equ <OpenWindowStationA>
        endif
        ; !UNICODE
        @DefProto DllImport, EnumWindowStationsA, WIN_STD_CALL_CONV,, <:WINSTAENUMPROCA, :LPARAM>, 8
        @DefProto DllImport, EnumWindowStationsW, WIN_STD_CALL_CONV,, <:WINSTAENUMPROCW, :LPARAM>, 8
        ifdef UNICODE
          EnumWindowStations equ <EnumWindowStationsW>
        else
          EnumWindowStations equ <EnumWindowStationsA>
        endif
        ; !UNICODE
        @DefProto DllImport, CloseWindowStation, WIN_STD_CALL_CONV,, <:HWINSTA>, 4
        @DefProto DllImport, SetProcessWindowStation, WIN_STD_CALL_CONV,, <:HWINSTA>, 4
        @DefProto DllImport, GetProcessWindowStation, WIN_STD_CALL_CONV,, <>, 0
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;* !NOWINDOWSTATION *
    endif
    ifndef NOSECURITY
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, SetUserObjectSecurity, WIN_STD_CALL_CONV,, <:HANDLE, :PSECURITY_INFORMATION, :PSECURITY_DESCRIPTOR>, 12
        @DefProto DllImport, GetUserObjectSecurity, WIN_STD_CALL_CONV,, <:HANDLE, :PSECURITY_INFORMATION, :PSECURITY_DESCRIPTOR, :DWORD, :LPDWORD>, 20
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      UOI_FLAGS equ 1
      UOI_NAME equ 2
      UOI_TYPE equ 3
      UOI_USER_SID equ 4
      if (WINVER ge 0600h)
        UOI_HEAPSIZE equ 5
        UOI_IO equ 6
        ;* WINVER >= 0x0600 *
      endif
      UOI_TIMERPROC_EXCEPTION_SUPPRESSION equ 7
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        USEROBJECTFLAGS struct
          fInherit DWORD ?
          fReserved DWORD ?
          dwFlags DWORD ?
        USEROBJECTFLAGS ends
        tagUSEROBJECTFLAGS typedef USEROBJECTFLAGS
        PUSEROBJECTFLAGS typedef ptr USEROBJECTFLAGS
        @DefProto DllImport, GetUserObjectInformationA, WIN_STD_CALL_CONV,, <:HANDLE, :SDWORD, :PVOID, :DWORD, :LPDWORD>, 20
        @DefProto DllImport, GetUserObjectInformationW, WIN_STD_CALL_CONV,, <:HANDLE, :SDWORD, :PVOID, :DWORD, :LPDWORD>, 20
        ifdef UNICODE
          GetUserObjectInformation equ <GetUserObjectInformationW>
        else
          GetUserObjectInformation equ <GetUserObjectInformationA>
        endif
        ; !UNICODE
        @DefProto DllImport, SetUserObjectInformationA, WIN_STD_CALL_CONV,, <:HANDLE, :SDWORD, :PVOID, :DWORD>, 16
        @DefProto DllImport, SetUserObjectInformationW, WIN_STD_CALL_CONV,, <:HANDLE, :SDWORD, :PVOID, :DWORD>, 16
        ifdef UNICODE
          SetUserObjectInformation equ <SetUserObjectInformationW>
        else
          SetUserObjectInformation equ <SetUserObjectInformationA>
        endif
        ; !UNICODE
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;* !NOSECURITY *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      if (WINVER ge 0400h)
        WNDCLASSEXA struct
          cbSize DWORD ?
          ;* Win 3.x *
          style DWORD ?
          lpfnWndProc WNDPROC ?
          cbClsExtra SDWORD ?
          cbWndExtra SDWORD ?
          hInstance HINSTANCE ?
          hIcon HICON ?
          hCursor HCURSOR ?
          hbrBackground HBRUSH ?
          lpszMenuName =POINTER ?
          lpszClassName =POINTER ?
          ;* Win 4.0 *
          hIconSm HICON ?
        WNDCLASSEXA ends
        tagWNDCLASSEXA typedef WNDCLASSEXA
        PWNDCLASSEXA typedef ptr WNDCLASSEXA
        NPWNDCLASSEXA typedef ptr WNDCLASSEXA
        LPWNDCLASSEXA typedef ptr WNDCLASSEXA
        WNDCLASSEXW struct
          cbSize DWORD ?
          ;* Win 3.x *
          style DWORD ?
          lpfnWndProc WNDPROC ?
          cbClsExtra SDWORD ?
          cbWndExtra SDWORD ?
          hInstance HINSTANCE ?
          hIcon HICON ?
          hCursor HCURSOR ?
          hbrBackground HBRUSH ?
          lpszMenuName =POINTER ?
          lpszClassName =POINTER ?
          ;* Win 4.0 *
          hIconSm HICON ?
        WNDCLASSEXW ends
        tagWNDCLASSEXW typedef WNDCLASSEXW
        PWNDCLASSEXW typedef ptr WNDCLASSEXW
        NPWNDCLASSEXW typedef ptr WNDCLASSEXW
        LPWNDCLASSEXW typedef ptr WNDCLASSEXW
        ifdef UNICODE
          WNDCLASSEX typedef WNDCLASSEXW
          PWNDCLASSEX typedef PWNDCLASSEXW
          NPWNDCLASSEX typedef NPWNDCLASSEXW
          LPWNDCLASSEX typedef LPWNDCLASSEXW
        else
          WNDCLASSEX typedef WNDCLASSEXA
          PWNDCLASSEX typedef PWNDCLASSEXA
          NPWNDCLASSEX typedef NPWNDCLASSEXA
          LPWNDCLASSEX typedef LPWNDCLASSEXA
        endif
        ; UNICODE
        ;* WINVER >= 0x0400 *
      endif
      WNDCLASSA struct
        style DWORD ?
        lpfnWndProc WNDPROC ?
        cbClsExtra SDWORD ?
        cbWndExtra SDWORD ?
        hInstance HINSTANCE ?
        hIcon HICON ?
        hCursor HCURSOR ?
        hbrBackground HBRUSH ?
        lpszMenuName =POINTER ?
        lpszClassName =POINTER ?
      WNDCLASSA ends
      tagWNDCLASSA typedef WNDCLASSA
      PWNDCLASSA typedef ptr WNDCLASSA
      NPWNDCLASSA typedef ptr WNDCLASSA
      LPWNDCLASSA typedef ptr WNDCLASSA
      WNDCLASSW struct
        style DWORD ?
        lpfnWndProc WNDPROC ?
        cbClsExtra SDWORD ?
        cbWndExtra SDWORD ?
        hInstance HINSTANCE ?
        hIcon HICON ?
        hCursor HCURSOR ?
        hbrBackground HBRUSH ?
        lpszMenuName =POINTER ?
        lpszClassName =POINTER ?
      WNDCLASSW ends
      tagWNDCLASSW typedef WNDCLASSW
      PWNDCLASSW typedef ptr WNDCLASSW
      NPWNDCLASSW typedef ptr WNDCLASSW
      LPWNDCLASSW typedef ptr WNDCLASSW
      ifdef UNICODE
        WNDCLASS typedef WNDCLASSW
        PWNDCLASS typedef PWNDCLASSW
        NPWNDCLASS typedef NPWNDCLASSW
        LPWNDCLASS typedef LPWNDCLASSW
      else
        WNDCLASS typedef WNDCLASSA
        PWNDCLASS typedef PWNDCLASSA
        NPWNDCLASS typedef NPWNDCLASSA
        LPWNDCLASS typedef LPWNDCLASSA
      endif
      ; UNICODE
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, IsHungAppWindow, WIN_STD_CALL_CONV,, <:HWND>, 4
      if (WINVER ge 0501h)
        @DefProto DllImport, DisableProcessWindowsGhosting, WIN_STD_CALL_CONV,, <>, 0
        ;* WINVER >= 0x0501 *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ifndef NOMSG
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
        ;*
        ;* Message structure
        ;*
        MSG struct
          hwnd HWND ?
          message DWORD ?
          wParam WPARAM ?
          lParam LPARAM ?
          time DWORD ?
          pt POINT <>
          ifdef _MAC
            ;[...]
          endif
        MSG ends
        tagMSG typedef MSG
        PMSG typedef ptr MSG
        NPMSG typedef ptr MSG
        LPMSG typedef ptr MSG
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
      endif
      POINTSTOPOINT macro pt, pts
        exitm <{ (pt).x = LOWORD(* and pts) ; (pt).y = HIWORD(* and pts) ; }>
      endm
      POINTTOPOINTS macro pt
        exitm <(MAKELONG(((pt).x), ((pt).y)))>
      endm
      MAKEWPARAM macro l, h
        exitm <(MAKELONG(l, h))>
      endm
      MAKELPARAM macro l, h
        exitm <(MAKELONG(l, h))>
      endm
      MAKELRESULT macro l, h
        exitm <(MAKELONG(l, h))>
      endm
      ;* !NOMSG *
    endif
    ifndef NOWINOFFSETS
      ;*
      ;* Window field offsets for GetWindowLong()
      ;*
      GWL_WNDPROC equ (- 4)
      GWL_HINSTANCE equ (- 6)
      GWL_HWNDPARENT equ (- 8)
      GWL_STYLE equ (- 16)
      GWL_EXSTYLE equ (- 20)
      GWL_USERDATA equ (- 21)
      GWL_ID equ (- 12)
      ifdef _WIN64
        ;* _WIN64 *
      endif
      GWLP_WNDPROC equ (- 4)
      GWLP_HINSTANCE equ (- 6)
      GWLP_HWNDPARENT equ (- 8)
      GWLP_USERDATA equ (- 21)
      GWLP_ID equ (- 12)
      ;*
      ;* Used in _GetWindowLongPtr to return internal state of user32 edit control
      ;*
      ;*
      ;* Class field offsets for GetClassLong()
      ;*
      GCL_MENUNAME equ (- 8)
      GCL_HBRBACKGROUND equ (- 10)
      GCL_HCURSOR equ (- 12)
      GCL_HICON equ (- 14)
      GCL_HMODULE equ (- 16)
      GCL_CBWNDEXTRA equ (- 18)
      GCL_CBCLSEXTRA equ (- 20)
      GCL_WNDPROC equ (- 24)
      GCL_STYLE equ (- 26)
      GCW_ATOM equ (- 32)
      if (WINVER ge 0400h)
        GCL_HICONSM equ (- 34)
        ;* WINVER >= 0x0400 *
      endif
      ifdef _WIN64
        ;* _WIN64 *
      endif
      GCLP_MENUNAME equ (- 8)
      GCLP_HBRBACKGROUND equ (- 10)
      GCLP_HCURSOR equ (- 12)
      GCLP_HICON equ (- 14)
      GCLP_HMODULE equ (- 16)
      GCLP_WNDPROC equ (- 24)
      GCLP_HICONSM equ (- 34)
      ;* !NOWINOFFSETS *
    endif
    ifndef NOWINMESSAGES
      ;*
      ;* Window Messages
      ;*
      WM_NULL equ 0000h
      WM_CREATE equ 0001h
      WM_DESTROY equ 0002h
      WM_MOVE equ 0003h
      WM_SIZE equ 0005h
      WM_ACTIVATE equ 0006h
      ;*
      ;* WM_ACTIVATE state values
      ;*
      WA_INACTIVE equ 0
      WA_ACTIVE equ 1
      WA_CLICKACTIVE equ 2
      WM_SETFOCUS equ 0007h
      WM_KILLFOCUS equ 0008h
      WM_ENABLE equ 000Ah
      WM_SETREDRAW equ 000Bh
      WM_SETTEXT equ 000Ch
      WM_GETTEXT equ 000Dh
      WM_GETTEXTLENGTH equ 000Eh
      WM_PAINT equ 000Fh
      WM_CLOSE equ 0010h
      ifndef _WIN32_WCE
        WM_QUERYENDSESSION equ 0011h
        WM_QUERYOPEN equ 0013h
        WM_ENDSESSION equ 0016h
      endif
      WM_QUIT equ 0012h
      WM_ERASEBKGND equ 0014h
      WM_SYSCOLORCHANGE equ 0015h
      WM_SHOWWINDOW equ 0018h
      WM_WININICHANGE equ 001Ah
      if (WINVER ge 0400h)
        WM_SETTINGCHANGE equ <WM_WININICHANGE>
        ;* WINVER >= 0x0400 *
      endif
      if (NTDDI_VERSION ge NTDDI_WIN10_19H1)
      endif
      ; NTDDI_VERSION >= NTDDI_WIN10_19H1
      WM_DEVMODECHANGE equ 001Bh
      WM_ACTIVATEAPP equ 001Ch
      WM_FONTCHANGE equ 001Dh
      WM_TIMECHANGE equ 001Eh
      WM_CANCELMODE equ 001Fh
      WM_SETCURSOR equ 0020h
      WM_MOUSEACTIVATE equ 0021h
      WM_CHILDACTIVATE equ 0022h
      WM_QUEUESYNC equ 0023h
      WM_GETMINMAXINFO equ 0024h
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        ;*
        ;* Struct pointed to by WM_GETMINMAXINFO lParam
        ;*
        MINMAXINFO struct
          ptReserved POINT <>
          ptMaxSize POINT <>
          ptMaxPosition POINT <>
          ptMinTrackSize POINT <>
          ptMaxTrackSize POINT <>
        MINMAXINFO ends
        tagMINMAXINFO typedef MINMAXINFO
        PMINMAXINFO typedef ptr MINMAXINFO
        LPMINMAXINFO typedef ptr MINMAXINFO
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      WM_PAINTICON equ 0026h
      WM_ICONERASEBKGND equ 0027h
      WM_NEXTDLGCTL equ 0028h
      WM_SPOOLERSTATUS equ 002Ah
      WM_DRAWITEM equ 002Bh
      WM_MEASUREITEM equ 002Ch
      WM_DELETEITEM equ 002Dh
      WM_VKEYTOITEM equ 002Eh
      WM_CHARTOITEM equ 002Fh
      WM_SETFONT equ 0030h
      WM_GETFONT equ 0031h
      WM_SETHOTKEY equ 0032h
      WM_GETHOTKEY equ 0033h
      WM_QUERYDRAGICON equ 0037h
      WM_COMPAREITEM equ 0039h
      if (WINVER ge 0500h)
        ifndef _WIN32_WCE
          WM_GETOBJECT equ 003Dh
        endif
        ;* WINVER >= 0x0500 *
      endif
      WM_COMPACTING equ 0041h
      ;* no longer suported *
      WM_COMMNOTIFY equ 0044h
      WM_WINDOWPOSCHANGING equ 0046h
      WM_WINDOWPOSCHANGED equ 0047h
      WM_POWER equ 0048h
      ;*
      ;* wParam for WM_POWER window message and DRV_POWER driver notification
      ;*
      PWR_OK equ 1
      PWR_FAIL equ (- 1)
      PWR_SUSPENDREQUEST equ 1
      PWR_SUSPENDRESUME equ 2
      PWR_CRITICALRESUME equ 3
      WM_COPYDATA equ 004Ah
      WM_CANCELJOURNAL equ 004Bh
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        ;*
        ;* lParam of WM_COPYDATA message points to...
        ;*
        COPYDATASTRUCT struct
          dwData XWORD ?
          cbData DWORD ?
          lpData POINTER ?
        COPYDATASTRUCT ends
        tagCOPYDATASTRUCT typedef COPYDATASTRUCT
        PCOPYDATASTRUCT typedef ptr COPYDATASTRUCT
        if (WINVER ge 0400h)
          MDINEXTMENU struct
            hmenuIn HMENU ?
            hmenuNext HMENU ?
            hwndNext HWND ?
          MDINEXTMENU ends
          tagMDINEXTMENU typedef MDINEXTMENU
          PMDINEXTMENU typedef ptr MDINEXTMENU
          LPMDINEXTMENU typedef ptr MDINEXTMENU
          ;* WINVER >= 0x0400 *
        endif
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      if (WINVER ge 0400h)
        WM_NOTIFY equ 004Eh
        WM_INPUTLANGCHANGEREQUEST equ 0050h
        WM_INPUTLANGCHANGE equ 0051h
        WM_TCARD equ 0052h
        WM_HELP equ 0053h
        WM_USERCHANGED equ 0054h
        WM_NOTIFYFORMAT equ 0055h
        NFR_ANSI equ 1
        NFR_UNICODE equ 2
        NF_QUERY equ 3
        NF_REQUERY equ 4
        WM_CONTEXTMENU equ 007Bh
        WM_STYLECHANGING equ 007Ch
        WM_STYLECHANGED equ 007Dh
        WM_DISPLAYCHANGE equ 007Eh
        WM_GETICON equ 007Fh
        WM_SETICON equ 0080h
        ;* WINVER >= 0x0400 *
      endif
      WM_NCCREATE equ 0081h
      WM_NCDESTROY equ 0082h
      WM_NCCALCSIZE equ 0083h
      WM_NCHITTEST equ 0084h
      WM_NCPAINT equ 0085h
      WM_NCACTIVATE equ 0086h
      WM_GETDLGCODE equ 0087h
      ifndef _WIN32_WCE
        WM_SYNCPAINT equ 0088h
      endif
      WM_NCMOUSEMOVE equ 00A0h
      WM_NCLBUTTONDOWN equ 00A1h
      WM_NCLBUTTONUP equ 00A2h
      WM_NCLBUTTONDBLCLK equ 00A3h
      WM_NCRBUTTONDOWN equ 00A4h
      WM_NCRBUTTONUP equ 00A5h
      WM_NCRBUTTONDBLCLK equ 00A6h
      WM_NCMBUTTONDOWN equ 00A7h
      WM_NCMBUTTONUP equ 00A8h
      WM_NCMBUTTONDBLCLK equ 00A9h
      if (_WIN32_WINNT ge 0500h)
        WM_NCXBUTTONDOWN equ 00ABh
        WM_NCXBUTTONUP equ 00ACh
        WM_NCXBUTTONDBLCLK equ 00ADh
        ;* _WIN32_WINNT >= 0x0500 *
      endif
      if (_WIN32_WINNT ge 0501h)
        WM_INPUT_DEVICE_CHANGE equ 00FEh
        ;* _WIN32_WINNT >= 0x0501 *
      endif
      if (_WIN32_WINNT ge 0501h)
        WM_INPUT equ 00FFh
        ;* _WIN32_WINNT >= 0x0501 *
      endif
      WM_KEYFIRST equ 0100h
      WM_KEYDOWN equ 0100h
      WM_KEYUP equ 0101h
      WM_CHAR equ 0102h
      WM_DEADCHAR equ 0103h
      WM_SYSKEYDOWN equ 0104h
      WM_SYSKEYUP equ 0105h
      WM_SYSCHAR equ 0106h
      WM_SYSDEADCHAR equ 0107h
      if (_WIN32_WINNT ge 0501h)
        WM_UNICHAR equ 0109h
        WM_KEYLAST equ 0109h
        UNICODE_NOCHAR equ 0FFFFh
      else
        WM_KEYLAST equ 0108h
        ;* _WIN32_WINNT >= 0x0501 *
      endif
      if (WINVER ge 0400h)
        WM_IME_STARTCOMPOSITION equ 010Dh
        WM_IME_ENDCOMPOSITION equ 010Eh
        WM_IME_COMPOSITION equ 010Fh
        WM_IME_KEYLAST equ 010Fh
        ;* WINVER >= 0x0400 *
      endif
      WM_INITDIALOG equ 0110h
      WM_COMMAND equ 0111h
      WM_SYSCOMMAND equ 0112h
      WM_TIMER equ 0113h
      WM_HSCROLL equ 0114h
      WM_VSCROLL equ 0115h
      WM_INITMENU equ 0116h
      WM_INITMENUPOPUP equ 0117h
      if (WINVER ge 0601h)
        WM_GESTURE equ 0119h
        WM_GESTURENOTIFY equ 011Ah
        ;* WINVER >= 0x0601 *
      endif
      WM_MENUSELECT equ 011Fh
      WM_MENUCHAR equ 0120h
      WM_ENTERIDLE equ 0121h
      if (WINVER ge 0500h)
        ifndef _WIN32_WCE
          WM_MENURBUTTONUP equ 0122h
          WM_MENUDRAG equ 0123h
          WM_MENUGETOBJECT equ 0124h
          WM_UNINITMENUPOPUP equ 0125h
          WM_MENUCOMMAND equ 0126h
          ifndef _WIN32_WCE
            if (_WIN32_WINNT ge 0500h)
              WM_CHANGEUISTATE equ 0127h
              WM_UPDATEUISTATE equ 0128h
              WM_QUERYUISTATE equ 0129h
              ;*
              ;* LOWORD(wParam) values in WM_*UISTATE*
              ;*
              UIS_SET equ 1
              UIS_CLEAR equ 2
              UIS_INITIALIZE equ 3
              ;*
              ;* HIWORD(wParam) values in WM_*UISTATE*
              ;*
              UISF_HIDEFOCUS equ 1h
              UISF_HIDEACCEL equ 2h
              if (_WIN32_WINNT ge 0501h)
                UISF_ACTIVE equ 4h
                ;* _WIN32_WINNT >= 0x0501 *
              endif
              ;* _WIN32_WINNT >= 0x0500 *
            endif
          endif
        endif
        ;* WINVER >= 0x0500 *
      endif
      WM_CTLCOLORMSGBOX equ 0132h
      WM_CTLCOLOREDIT equ 0133h
      WM_CTLCOLORLISTBOX equ 0134h
      WM_CTLCOLORBTN equ 0135h
      WM_CTLCOLORDLG equ 0136h
      WM_CTLCOLORSCROLLBAR equ 0137h
      WM_CTLCOLORSTATIC equ 0138h
      MN_GETHMENU equ 01E1h
      WM_MOUSEFIRST equ 0200h
      WM_MOUSEMOVE equ 0200h
      WM_LBUTTONDOWN equ 0201h
      WM_LBUTTONUP equ 0202h
      WM_LBUTTONDBLCLK equ 0203h
      WM_RBUTTONDOWN equ 0204h
      WM_RBUTTONUP equ 0205h
      WM_RBUTTONDBLCLK equ 0206h
      WM_MBUTTONDOWN equ 0207h
      WM_MBUTTONUP equ 0208h
      WM_MBUTTONDBLCLK equ 0209h
      if (_WIN32_WINNT ge 0400h) or (_WIN32_WINDOWS gt 0400h)
        WM_MOUSEWHEEL equ 020Ah
      endif
      if (_WIN32_WINNT ge 0500h)
        WM_XBUTTONDOWN equ 020Bh
        WM_XBUTTONUP equ 020Ch
        WM_XBUTTONDBLCLK equ 020Dh
      endif
      if (_WIN32_WINNT ge 0600h)
        WM_MOUSEHWHEEL equ 020Eh
      endif
      if (_WIN32_WINNT ge 0600h)
        WM_MOUSELAST equ 020Eh
      elseif (_WIN32_WINNT ge 0500h)
        WM_MOUSELAST equ 020Dh
      elseif (_WIN32_WINNT ge 0400h) or (_WIN32_WINDOWS gt 0400h)
        WM_MOUSELAST equ 020Ah
      else
        WM_MOUSELAST equ 0209h
        ;* (_WIN32_WINNT >= 0x0600) *
      endif
      if (_WIN32_WINNT ge 0400h)
        ;* Value for rolling one detent *
        WHEEL_DELTA equ 120
        GET_WHEEL_DELTA_WPARAM macro wParam
          exitm <(HIWORD(wParam))>
        endm
        ;* Setting to scroll one page for SPI_GET/SETWHEELSCROLLLINES *
        WHEEL_PAGESCROLL equ <(UINT_MAX)>
        ;* _WIN32_WINNT >= 0x0400 *
      endif
      if (_WIN32_WINNT ge 0500h)
        GET_KEYSTATE_WPARAM macro wParam
          exitm <(LOWORD(wParam))>
        endm
        GET_NCHITTEST_WPARAM macro wParam
          exitm <(LOWORD(wParam))>
        endm
        GET_XBUTTON_WPARAM macro wParam
          exitm <(HIWORD(wParam))>
        endm
        ;* XButton values are WORD flags *
        XBUTTON1 equ 0001h
        XBUTTON2 equ 0002h
        ;* Were there to be an XBUTTON3, its value would be 0x0004 *
        ;* _WIN32_WINNT >= 0x0500 *
      endif
      WM_PARENTNOTIFY equ 0210h
      WM_ENTERMENULOOP equ 0211h
      WM_EXITMENULOOP equ 0212h
      if (WINVER ge 0400h)
        WM_NEXTMENU equ 0213h
        WM_SIZING equ 0214h
        WM_CAPTURECHANGED equ 0215h
        WM_MOVING equ 0216h
        ;* WINVER >= 0x0400 *
      endif
      if (WINVER ge 0400h)
        WM_POWERBROADCAST equ 0218h
        ifndef _WIN32_WCE
          PBT_APMQUERYSUSPEND equ 0000h
          PBT_APMQUERYSTANDBY equ 0001h
          PBT_APMQUERYSUSPENDFAILED equ 0002h
          PBT_APMQUERYSTANDBYFAILED equ 0003h
          PBT_APMSUSPEND equ 0004h
          PBT_APMSTANDBY equ 0005h
          PBT_APMRESUMECRITICAL equ 0006h
          PBT_APMRESUMESUSPEND equ 0007h
          PBT_APMRESUMESTANDBY equ 0008h
          PBTF_APMRESUMEFROMFAILURE equ 00000001h
          PBT_APMBATTERYLOW equ 0009h
          PBT_APMPOWERSTATUSCHANGE equ 000Ah
          PBT_APMOEMEVENT equ 000Bh
          PBT_APMRESUMEAUTOMATIC equ 0012h
          if (_WIN32_WINNT ge 0502h)
            ifndef PBT_POWERSETTINGCHANGE
              PBT_POWERSETTINGCHANGE equ 8013h
              if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
                POWERBROADCAST_SETTING struct
                  PowerSetting GUID <>
                  DataLength DWORD ?
                  Data BYTE 1 dup (?)
                POWERBROADCAST_SETTING ends
                PPOWERBROADCAST_SETTING typedef ptr POWERBROADCAST_SETTING
                ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
              endif
            endif
            ; PBT_POWERSETTINGCHANGE
          endif
          ; (_WIN32_WINNT >= 0x0502)
        endif
        ;* WINVER >= 0x0400 *
      endif
      if (WINVER ge 0400h)
        WM_DEVICECHANGE equ 0219h
        ;* WINVER >= 0x0400 *
      endif
      WM_MDICREATE equ 0220h
      WM_MDIDESTROY equ 0221h
      WM_MDIACTIVATE equ 0222h
      WM_MDIRESTORE equ 0223h
      WM_MDINEXT equ 0224h
      WM_MDIMAXIMIZE equ 0225h
      WM_MDITILE equ 0226h
      WM_MDICASCADE equ 0227h
      WM_MDIICONARRANGE equ 0228h
      WM_MDIGETACTIVE equ 0229h
      WM_MDISETMENU equ 0230h
      WM_ENTERSIZEMOVE equ 0231h
      WM_EXITSIZEMOVE equ 0232h
      WM_DROPFILES equ 0233h
      WM_MDIREFRESHMENU equ 0234h
      if (WINVER ge 0602h)
        WM_POINTERDEVICECHANGE equ 238h
        WM_POINTERDEVICEINRANGE equ 239h
        WM_POINTERDEVICEOUTOFRANGE equ 23Ah
        ;* WINVER >= 0x0602 *
      endif
      if (WINVER ge 0601h)
        WM_TOUCH equ 0240h
        ;* WINVER >= 0x0601 *
      endif
      if (WINVER ge 0602h)
        WM_NCPOINTERUPDATE equ 0241h
        WM_NCPOINTERDOWN equ 0242h
        WM_NCPOINTERUP equ 0243h
        WM_POINTERUPDATE equ 0245h
        WM_POINTERDOWN equ 0246h
        WM_POINTERUP equ 0247h
        WM_POINTERENTER equ 0249h
        WM_POINTERLEAVE equ 024Ah
        WM_POINTERACTIVATE equ 024Bh
        WM_POINTERCAPTURECHANGED equ 024Ch
        WM_TOUCHHITTESTING equ 024Dh
        WM_POINTERWHEEL equ 024Eh
        WM_POINTERHWHEEL equ 024Fh
        DM_POINTERHITTEST equ 0250h
        WM_POINTERROUTEDTO equ 0251h
        WM_POINTERROUTEDAWAY equ 0252h
        WM_POINTERROUTEDRELEASED equ 0253h
        ;* WINVER >= 0x0602 *
      endif
      if (WINVER ge 0400h)
        WM_IME_SETCONTEXT equ 0281h
        WM_IME_NOTIFY equ 0282h
        WM_IME_CONTROL equ 0283h
        WM_IME_COMPOSITIONFULL equ 0284h
        WM_IME_SELECT equ 0285h
        WM_IME_CHAR equ 0286h
        ;* WINVER >= 0x0400 *
      endif
      if (WINVER ge 0500h)
        WM_IME_REQUEST equ 0288h
        ;* WINVER >= 0x0500 *
      endif
      if (WINVER ge 0400h)
        WM_IME_KEYDOWN equ 0290h
        WM_IME_KEYUP equ 0291h
        ;* WINVER >= 0x0400 *
      endif
      if ((_WIN32_WINNT ge 0400h) or (WINVER ge 0500h))
        WM_MOUSEHOVER equ 02A1h
        WM_MOUSELEAVE equ 02A3h
      endif
      if (WINVER ge 0500h)
        WM_NCMOUSEHOVER equ 02A0h
        WM_NCMOUSELEAVE equ 02A2h
        ;* WINVER >= 0x0500 *
      endif
      if (_WIN32_WINNT ge 0501h)
        WM_WTSSESSION_CHANGE equ 02B1h
        WM_TABLET_FIRST equ 02c0h
        WM_TABLET_LAST equ 02dfh
        ;* _WIN32_WINNT >= 0x0501 *
      endif
      if (WINVER ge 0601h)
        WM_DPICHANGED equ 02E0h
        ;* WINVER >= 0x0601 *
      endif
      if (WINVER ge 0605h)
        WM_DPICHANGED_BEFOREPARENT equ 02E2h
        WM_DPICHANGED_AFTERPARENT equ 02E3h
        WM_GETDPISCALEDSIZE equ 02E4h
        ;* WINVER >= 0x0605 *
      endif
      WM_CUT equ 0300h
      WM_COPY equ 0301h
      WM_PASTE equ 0302h
      WM_CLEAR equ 0303h
      WM_UNDO equ 0304h
      WM_RENDERFORMAT equ 0305h
      WM_RENDERALLFORMATS equ 0306h
      WM_DESTROYCLIPBOARD equ 0307h
      WM_DRAWCLIPBOARD equ 0308h
      WM_PAINTCLIPBOARD equ 0309h
      WM_VSCROLLCLIPBOARD equ 030Ah
      WM_SIZECLIPBOARD equ 030Bh
      WM_ASKCBFORMATNAME equ 030Ch
      WM_CHANGECBCHAIN equ 030Dh
      WM_HSCROLLCLIPBOARD equ 030Eh
      WM_QUERYNEWPALETTE equ 030Fh
      WM_PALETTEISCHANGING equ 0310h
      WM_PALETTECHANGED equ 0311h
      WM_HOTKEY equ 0312h
      if (WINVER ge 0400h)
        WM_PRINT equ 0317h
        WM_PRINTCLIENT equ 0318h
        ;* WINVER >= 0x0400 *
      endif
      if (_WIN32_WINNT ge 0500h)
        WM_APPCOMMAND equ 0319h
        ;* _WIN32_WINNT >= 0x0500 *
      endif
      if (_WIN32_WINNT ge 0501h)
        WM_THEMECHANGED equ 031Ah
        ;* _WIN32_WINNT >= 0x0501 *
      endif
      if (_WIN32_WINNT ge 0501h)
        WM_CLIPBOARDUPDATE equ 031Dh
        ;* _WIN32_WINNT >= 0x0501 *
      endif
      if (_WIN32_WINNT ge 0600h)
        WM_DWMCOMPOSITIONCHANGED equ 031Eh
        WM_DWMNCRENDERINGCHANGED equ 031Fh
        WM_DWMCOLORIZATIONCOLORCHANGED equ 0320h
        WM_DWMWINDOWMAXIMIZEDCHANGE equ 0321h
        ;* _WIN32_WINNT >= 0x0600 *
      endif
      if (_WIN32_WINNT ge 0601h)
        WM_DWMSENDICONICTHUMBNAIL equ 0323h
        WM_DWMSENDICONICLIVEPREVIEWBITMAP equ 0326h
        ;* _WIN32_WINNT >= 0x0601 *
      endif
      if (WINVER ge 0600h)
        WM_GETTITLEBARINFOEX equ 033Fh
        ;* WINVER >= 0x0600 *
      endif
      if (WINVER ge 0400h)
        ;* WINVER >= 0x0400 *
      endif
      if (WINVER ge 0400h)
        WM_HANDHELDFIRST equ 0358h
        WM_HANDHELDLAST equ 035Fh
        WM_AFXFIRST equ 0360h
        WM_AFXLAST equ 037Fh
        ;* WINVER >= 0x0400 *
      endif
      WM_PENWINFIRST equ 0380h
      WM_PENWINLAST equ 038Fh
      if (WINVER ge 0400h)
        WM_APP equ 8000h
        ;* WINVER >= 0x0400 *
      endif
      ;*
      ;* NOTE: All Message Numbers below 0x0400 are RESERVED.
      ;*
      ;* Private Window Messages Start Here:
      ;*
      WM_USER equ 0400h
      if (WINVER ge 0400h)
        ;*  wParam for WM_SIZING message  *
        WMSZ_LEFT equ 1
        WMSZ_RIGHT equ 2
        WMSZ_TOP equ 3
        WMSZ_TOPLEFT equ 4
        WMSZ_TOPRIGHT equ 5
        WMSZ_BOTTOM equ 6
        WMSZ_BOTTOMLEFT equ 7
        WMSZ_BOTTOMRIGHT equ 8
        ;* WINVER >= 0x0400 *
      endif
      ifndef NONCMESSAGES
        ;*
        ;* WM_NCHITTEST and MOUSEHOOKSTRUCT Mouse Position Codes
        ;*
        HTERROR equ (- 2)
        HTTRANSPARENT equ (- 1)
        HTNOWHERE equ 0
        HTCLIENT equ 1
        HTCAPTION equ 2
        HTSYSMENU equ 3
        HTGROWBOX equ 4
        HTSIZE equ <HTGROWBOX>
        HTMENU equ 5
        HTHSCROLL equ 6
        HTVSCROLL equ 7
        HTMINBUTTON equ 8
        HTMAXBUTTON equ 9
        HTLEFT equ 10
        HTRIGHT equ 11
        HTTOP equ 12
        HTTOPLEFT equ 13
        HTTOPRIGHT equ 14
        HTBOTTOM equ 15
        HTBOTTOMLEFT equ 16
        HTBOTTOMRIGHT equ 17
        HTBORDER equ 18
        HTREDUCE equ <HTMINBUTTON>
        HTZOOM equ <HTMAXBUTTON>
        HTSIZEFIRST equ <HTLEFT>
        HTSIZELAST equ <HTBOTTOMRIGHT>
        if (WINVER ge 0400h)
          HTOBJECT equ 19
          HTCLOSE equ 20
          HTHELP equ 21
          ;* WINVER >= 0x0400 *
        endif
        ;*
        ;* SendMessageTimeout values
        ;*
        SMTO_NORMAL equ 0000h
        SMTO_BLOCK equ 0001h
        SMTO_ABORTIFHUNG equ 0002h
        if (WINVER ge 0500h)
          SMTO_NOTIMEOUTIFNOTHUNG equ 0008h
          ;* WINVER >= 0x0500 *
        endif
        if (WINVER ge 0600h)
          SMTO_ERRORONEXIT equ 0020h
          ;* WINVER >= 0x0600 *
        endif
        if (WINVER ge 0602h)
          ;* WINVER >= 0x0602 *
        endif
        ;* !NONCMESSAGES *
      endif
      ;*
      ;* WM_MOUSEACTIVATE Return Codes
      ;*
      MA_ACTIVATE equ 1
      MA_ACTIVATEANDEAT equ 2
      MA_NOACTIVATE equ 3
      MA_NOACTIVATEANDEAT equ 4
      ;*
      ;* WM_SETICON / WM_GETICON Type Codes
      ;*
      ICON_SMALL equ 0
      ICON_BIG equ 1
      if (_WIN32_WINNT ge 0501h)
        ICON_SMALL2 equ 2
        ;* _WIN32_WINNT >= 0x0501 *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, RegisterWindowMessageA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
        @DefProto DllImport, RegisterWindowMessageW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
        ifdef UNICODE
          RegisterWindowMessage equ <RegisterWindowMessageW>
        else
          RegisterWindowMessage equ <RegisterWindowMessageA>
        endif
        ; !UNICODE
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;*
      ;* WM_SIZE message wParam values
      ;*
      SIZE_RESTORED equ 0
      SIZE_MINIMIZED equ 1
      SIZE_MAXIMIZED equ 2
      SIZE_MAXSHOW equ 3
      SIZE_MAXHIDE equ 4
      ;*
      ;* Obsolete constant names
      ;*
      SIZENORMAL equ <SIZE_RESTORED>
      SIZEICONIC equ <SIZE_MINIMIZED>
      SIZEFULLSCREEN equ <SIZE_MAXIMIZED>
      SIZEZOOMSHOW equ <SIZE_MAXSHOW>
      SIZEZOOMHIDE equ <SIZE_MAXHIDE>
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        ;*
        ;* WM_WINDOWPOSCHANGING/CHANGED struct pointed to by lParam
        ;*
        WINDOWPOS struct
          hwnd HWND ?
          hwndInsertAfter HWND ?
          x SDWORD ?
          y SDWORD ?
          cx_ SDWORD ?
          cy SDWORD ?
          flags DWORD ?
        WINDOWPOS ends
        tagWINDOWPOS typedef WINDOWPOS
        LPWINDOWPOS typedef ptr WINDOWPOS
        PWINDOWPOS typedef ptr WINDOWPOS
        ;*
        ;* WM_NCCALCSIZE parameter structure
        ;*
        NCCALCSIZE_PARAMS struct
          rgrc RECT 3 dup (<>)
          lppos PWINDOWPOS ?
        NCCALCSIZE_PARAMS ends
        tagNCCALCSIZE_PARAMS typedef NCCALCSIZE_PARAMS
        LPNCCALCSIZE_PARAMS typedef ptr NCCALCSIZE_PARAMS
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;*
      ;* WM_NCCALCSIZE "window valid rect" return values
      ;*
      WVR_ALIGNTOP equ 0010h
      WVR_ALIGNLEFT equ 0020h
      WVR_ALIGNBOTTOM equ 0040h
      WVR_ALIGNRIGHT equ 0080h
      WVR_HREDRAW equ 0100h
      WVR_VREDRAW equ 0200h
      WVR_REDRAW equ <(WVR_HREDRAW or WVR_VREDRAW)>
      WVR_VALIDRECTS equ 0400h
      ifndef NOKEYSTATES
        ;*
        ;* Key State Masks for Mouse Messages
        ;*
        MK_LBUTTON equ 0001h
        MK_RBUTTON equ 0002h
        MK_SHIFT equ 0004h
        MK_CONTROL equ 0008h
        MK_MBUTTON equ 0010h
        if (_WIN32_WINNT ge 0500h)
          MK_XBUTTON1 equ 0020h
          MK_XBUTTON2 equ 0040h
          ;* _WIN32_WINNT >= 0x0500 *
        endif
        ;* !NOKEYSTATES *
      endif
      if (_WIN32_WINNT ge 0400h)
        ifndef NOTRACKMOUSEEVENT
          TME_HOVER equ 00000001h
          TME_LEAVE equ 00000002h
          if (WINVER ge 0500h)
            TME_NONCLIENT equ 00000010h
            ;* WINVER >= 0x0500 *
          endif
          TME_QUERY equ 40000000h
          TME_CANCEL equ 80000000h
          HOVER_DEFAULT equ 0FFFFFFFFh
          ;* _WIN32_WINNT >= 0x0400 *
        endif
        if (_WIN32_WINNT ge 0400h)
          if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
            TRACKMOUSEEVENT struct
              cbSize DWORD ?
              dwFlags DWORD ?
              hwndTrack HWND ?
              dwHoverTime DWORD ?
            TRACKMOUSEEVENT ends
            tagTRACKMOUSEEVENT typedef TRACKMOUSEEVENT
            LPTRACKMOUSEEVENT typedef ptr TRACKMOUSEEVENT
            @DefProto DllImport, TrackMouseEvent, WIN_STD_CALL_CONV,, <:LPTRACKMOUSEEVENT>, 4
            ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
          endif
          ;* _WIN32_WINNT >= 0x0400 *
        endif
        if (_WIN32_WINNT ge 0400h)
          ;* !NOTRACKMOUSEEVENT *
        endif
        ;* _WIN32_WINNT >= 0x0400 *
      endif
      ;* !NOWINMESSAGES *
    endif
    ifndef NOWINSTYLES
      ;*
      ;* Window Styles
      ;*
      WS_OVERLAPPED equ 00000000h
      WS_POPUP equ 80000000h
      WS_CHILD equ 40000000h
      WS_MINIMIZE equ 20000000h
      WS_VISIBLE equ 10000000h
      WS_DISABLED equ 08000000h
      WS_CLIPSIBLINGS equ 04000000h
      WS_CLIPCHILDREN equ 02000000h
      WS_MAXIMIZE equ 01000000h
      ;* WS_BORDER | WS_DLGFRAME  *
      WS_CAPTION equ 00C00000h
      WS_BORDER equ 00800000h
      WS_DLGFRAME equ 00400000h
      WS_VSCROLL equ 00200000h
      WS_HSCROLL equ 00100000h
      WS_SYSMENU equ 00080000h
      WS_THICKFRAME equ 00040000h
      WS_GROUP equ 00020000h
      WS_TABSTOP equ 00010000h
      WS_MINIMIZEBOX equ 00020000h
      WS_MAXIMIZEBOX equ 00010000h
      WS_TILED equ <WS_OVERLAPPED>
      WS_ICONIC equ <WS_MINIMIZE>
      WS_SIZEBOX equ <WS_THICKFRAME>
      WS_TILEDWINDOW equ <WS_OVERLAPPEDWINDOW>
      ;*
      ;* Common Window Styles
      ;*
      WS_OVERLAPPEDWINDOW equ <(WS_OVERLAPPED or WS_CAPTION or WS_SYSMENU or WS_THICKFRAME or WS_MINIMIZEBOX or WS_MAXIMIZEBOX)>
      WS_POPUPWINDOW equ <(WS_POPUP or WS_BORDER or WS_SYSMENU)>
      WS_CHILDWINDOW equ <(WS_CHILD)>
      ;*
      ;* Extended Window Styles
      ;*
      WS_EX_DLGMODALFRAME equ 00000001h
      WS_EX_NOPARENTNOTIFY equ 00000004h
      WS_EX_TOPMOST equ 00000008h
      WS_EX_ACCEPTFILES equ 00000010h
      WS_EX_TRANSPARENT equ 00000020h
      if (WINVER ge 0400h)
        WS_EX_MDICHILD equ 00000040h
        WS_EX_TOOLWINDOW equ 00000080h
        WS_EX_WINDOWEDGE equ 00000100h
        WS_EX_CLIENTEDGE equ 00000200h
        WS_EX_CONTEXTHELP equ 00000400h
        ;* WINVER >= 0x0400 *
      endif
      if (WINVER ge 0400h)
        WS_EX_RIGHT equ 00001000h
        WS_EX_LEFT equ 00000000h
        WS_EX_RTLREADING equ 00002000h
        WS_EX_LTRREADING equ 00000000h
        WS_EX_LEFTSCROLLBAR equ 00004000h
        WS_EX_RIGHTSCROLLBAR equ 00000000h
        WS_EX_CONTROLPARENT equ 00010000h
        WS_EX_STATICEDGE equ 00020000h
        WS_EX_APPWINDOW equ 00040000h
        WS_EX_OVERLAPPEDWINDOW equ <(WS_EX_WINDOWEDGE or WS_EX_CLIENTEDGE)>
        WS_EX_PALETTEWINDOW equ <(WS_EX_WINDOWEDGE or WS_EX_TOOLWINDOW or WS_EX_TOPMOST)>
        ;* WINVER >= 0x0400 *
      endif
      if (_WIN32_WINNT ge 0500h)
        WS_EX_LAYERED equ 00080000h
        ;* _WIN32_WINNT >= 0x0500 *
      endif
      if (WINVER ge 0500h)
        WS_EX_NOINHERITLAYOUT equ 00100000h; Disable inheritence of mirroring by children

        ;* WINVER >= 0x0500 *
      endif
      if (WINVER ge 0602h)
        WS_EX_NOREDIRECTIONBITMAP equ 00200000h
        ;* WINVER >= 0x0602 *
      endif
      if (WINVER ge 0500h)
        WS_EX_LAYOUTRTL equ 00400000h; Right to left mirroring

        ;* WINVER >= 0x0500 *
      endif
      if (_WIN32_WINNT ge 0501h)
        WS_EX_COMPOSITED equ 02000000h
        ;* _WIN32_WINNT >= 0x0501 *
      endif
      if (_WIN32_WINNT ge 0500h)
        WS_EX_NOACTIVATE equ 08000000h
        ;* _WIN32_WINNT >= 0x0500 *
      endif
      ;*
      ;* Class styles
      ;*
      CS_VREDRAW equ 0001h
      CS_HREDRAW equ 0002h
      CS_DBLCLKS equ 0008h
      CS_OWNDC equ 0020h
      CS_CLASSDC equ 0040h
      CS_PARENTDC equ 0080h
      CS_NOCLOSE equ 0200h
      CS_SAVEBITS equ 0800h
      CS_BYTEALIGNCLIENT equ 1000h
      CS_BYTEALIGNWINDOW equ 2000h
      CS_GLOBALCLASS equ 4000h
      CS_IME equ 00010000h
      if (_WIN32_WINNT ge 0501h)
        CS_DROPSHADOW equ 00020000h
        ;* _WIN32_WINNT >= 0x0501 *
      endif
      ;* !NOWINSTYLES *
    endif
    if (WINVER ge 0400h)
      ;* WM_PRINT flags *
      PRF_CHECKVISIBLE equ 00000001h
      PRF_NONCLIENT equ 00000002h
      PRF_CLIENT equ 00000004h
      PRF_ERASEBKGND equ 00000008h
      PRF_CHILDREN equ 00000010h
      PRF_OWNED equ 00000020h
      ;* 3D border styles *
      BDR_RAISEDOUTER equ 0001h
      BDR_SUNKENOUTER equ 0002h
      BDR_RAISEDINNER equ 0004h
      BDR_SUNKENINNER equ 0008h
      BDR_OUTER equ <(BDR_RAISEDOUTER or BDR_SUNKENOUTER)>
      BDR_INNER equ <(BDR_RAISEDINNER or BDR_SUNKENINNER)>
      BDR_RAISED equ <(BDR_RAISEDOUTER or BDR_RAISEDINNER)>
      BDR_SUNKEN equ <(BDR_SUNKENOUTER or BDR_SUNKENINNER)>
      EDGE_RAISED equ <(BDR_RAISEDOUTER or BDR_RAISEDINNER)>
      EDGE_SUNKEN equ <(BDR_SUNKENOUTER or BDR_SUNKENINNER)>
      EDGE_ETCHED equ <(BDR_SUNKENOUTER or BDR_RAISEDINNER)>
      EDGE_BUMP equ <(BDR_RAISEDOUTER or BDR_SUNKENINNER)>
      ;* Border flags *
      BF_LEFT equ 0001h
      BF_TOP equ 0002h
      BF_RIGHT equ 0004h
      BF_BOTTOM equ 0008h
      BF_TOPLEFT equ <(BF_TOP or BF_LEFT)>
      BF_TOPRIGHT equ <(BF_TOP or BF_RIGHT)>
      BF_BOTTOMLEFT equ <(BF_BOTTOM or BF_LEFT)>
      BF_BOTTOMRIGHT equ <(BF_BOTTOM or BF_RIGHT)>
      BF_RECT equ <(BF_LEFT or BF_TOP or BF_RIGHT or BF_BOTTOM)>
      BF_DIAGONAL equ 0010h
      ; For diagonal lines, the BF_RECT flags specify the end point of the
      ; vector bounded by the rectangle parameter.
      BF_DIAGONAL_ENDTOPRIGHT equ <(BF_DIAGONAL or BF_TOP or BF_RIGHT)>
      BF_DIAGONAL_ENDTOPLEFT equ <(BF_DIAGONAL or BF_TOP or BF_LEFT)>
      BF_DIAGONAL_ENDBOTTOMLEFT equ <(BF_DIAGONAL or BF_BOTTOM or BF_LEFT)>
      BF_DIAGONAL_ENDBOTTOMRIGHT equ <(BF_DIAGONAL or BF_BOTTOM or BF_RIGHT)>
      ;* Fill in the middle *
      BF_MIDDLE equ 0800h
      ;* For softer buttons *
      BF_SOFT equ 1000h
      ;* Calculate the space left over *
      BF_ADJUST equ 2000h
      ;* For flat rather than 3D borders *
      BF_FLAT equ 4000h
      ;* For monochrome borders *
      BF_MONO equ 8000h
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, DrawEdge, WIN_STD_CALL_CONV,, <:HDC, :LPRECT, :UINT, :UINT>, 16
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;* flags for DrawFrameControl *
      DFC_CAPTION equ 1
      DFC_MENU equ 2
      DFC_SCROLL equ 3
      DFC_BUTTON equ 4
      if (WINVER ge 0500h)
        DFC_POPUPMENU equ 5
        ;* WINVER >= 0x0500 *
      endif
      DFCS_CAPTIONCLOSE equ 0000h
      DFCS_CAPTIONMIN equ 0001h
      DFCS_CAPTIONMAX equ 0002h
      DFCS_CAPTIONRESTORE equ 0003h
      DFCS_CAPTIONHELP equ 0004h
      DFCS_MENUARROW equ 0000h
      DFCS_MENUCHECK equ 0001h
      DFCS_MENUBULLET equ 0002h
      DFCS_MENUARROWRIGHT equ 0004h
      DFCS_SCROLLUP equ 0000h
      DFCS_SCROLLDOWN equ 0001h
      DFCS_SCROLLLEFT equ 0002h
      DFCS_SCROLLRIGHT equ 0003h
      DFCS_SCROLLCOMBOBOX equ 0005h
      DFCS_SCROLLSIZEGRIP equ 0008h
      DFCS_SCROLLSIZEGRIPRIGHT equ 0010h
      DFCS_BUTTONCHECK equ 0000h
      DFCS_BUTTONRADIOIMAGE equ 0001h
      DFCS_BUTTONRADIOMASK equ 0002h
      DFCS_BUTTONRADIO equ 0004h
      DFCS_BUTTON3STATE equ 0008h
      DFCS_BUTTONPUSH equ 0010h
      DFCS_INACTIVE equ 0100h
      DFCS_PUSHED equ 0200h
      DFCS_CHECKED equ 0400h
      if (WINVER ge 0500h)
        DFCS_TRANSPARENT equ 0800h
        DFCS_HOT equ 1000h
        ;* WINVER >= 0x0500 *
      endif
      DFCS_ADJUSTRECT equ 2000h
      DFCS_FLAT equ 4000h
      DFCS_MONO equ 8000h
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, DrawFrameControl, WIN_STD_CALL_CONV,, <:HDC, :LPRECT, :UINT, :UINT>, 16
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;* flags for DrawCaption *
      DC_ACTIVE equ 0001h
      DC_SMALLCAP equ 0002h
      DC_ICON equ 0004h
      DC_TEXT equ 0008h
      DC_INBUTTON equ 0010h
      if (WINVER ge 0500h)
        DC_GRADIENT equ 0020h
        ;* WINVER >= 0x0500 *
      endif
      if (_WIN32_WINNT ge 0501h)
        DC_BUTTONS equ 1000h
        ;* _WIN32_WINNT >= 0x0501 *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, DrawCaption, WIN_STD_CALL_CONV,, <:HWND, :HDC, :ptr RECT, :UINT>, 16
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      IDANI_OPEN equ 1
      IDANI_CAPTION equ 3
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, DrawAnimatedRects, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :ptr RECT, :ptr RECT>, 16
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;* WINVER >= 0x0400 *
    endif
    ifndef NOCLIPBOARD
      ;*
      ;* Predefined Clipboard Formats
      ;*
      CF_TEXT equ 1
      CF_BITMAP equ 2
      CF_METAFILEPICT equ 3
      CF_SYLK equ 4
      CF_DIF equ 5
      CF_TIFF equ 6
      CF_OEMTEXT equ 7
      CF_DIB equ 8
      CF_PALETTE equ 9
      CF_PENDATA equ 10
      CF_RIFF equ 11
      CF_WAVE equ 12
      CF_UNICODETEXT equ 13
      CF_ENHMETAFILE equ 14
      if (WINVER ge 0400h)
        CF_HDROP equ 15
        CF_LOCALE equ 16
        ;* WINVER >= 0x0400 *
      endif
      if (WINVER ge 0500h)
        CF_DIBV5 equ 17
        ;* WINVER >= 0x0500 *
      endif
      if (WINVER ge 0500h)
        CF_MAX equ 18
      elseif (WINVER ge 0400h)
        CF_MAX equ 17
      else
        CF_MAX equ 15
      endif
      CF_OWNERDISPLAY equ 0080h
      CF_DSPTEXT equ 0081h
      CF_DSPBITMAP equ 0082h
      CF_DSPMETAFILEPICT equ 0083h
      CF_DSPENHMETAFILE equ 008Eh
      ;*
      ;* "Private" formats don't get GlobalFree()'d
      ;*
      CF_PRIVATEFIRST equ 0200h
      CF_PRIVATELAST equ 02FFh
      ;*
      ;* "GDIOBJ" formats do get DeleteObject()'d
      ;*
      CF_GDIOBJFIRST equ 0300h
      CF_GDIOBJLAST equ 03FFh
      ;* !NOCLIPBOARD *
    endif
    ;*
    ;* Defines for the fVirt field of the Accelerator table structure.
    ;*
    ;* Assumed to be == TRUE *
    FVIRTKEY equ <TRUE>
    FNOINVERT equ 02h
    FSHIFT equ 04h
    FCONTROL equ 08h
    FALT equ 10h
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ACCEL struct
        ifndef _MAC
          fVirt BYTE ?
          ;* Also called the flags field *
          key WORD ?
          cmd WORD ?
        else
          ;[...]
        endif
      ACCEL ends
      tagACCEL typedef ACCEL
      LPACCEL typedef ptr ACCEL
      PAINTSTRUCT struct
        hdc HDC ?
        fErase DWORD ?
        rcPaint RECT <>
        fRestore DWORD ?
        fIncUpdate DWORD ?
        rgbReserved BYTE 32 dup (?)
      PAINTSTRUCT ends
      tagPAINTSTRUCT typedef PAINTSTRUCT
      PPAINTSTRUCT typedef ptr PAINTSTRUCT
      NPPAINTSTRUCT typedef ptr PAINTSTRUCT
      LPPAINTSTRUCT typedef ptr PAINTSTRUCT
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      CREATESTRUCTA struct
        lpCreateParams POINTER ?
        hInstance HINSTANCE ?
        hMenu HMENU ?
        hwndParent HWND ?
        cy SDWORD ?
        cx_ SDWORD ?
        y SDWORD ?
        x SDWORD ?
        style SDWORD ?
        lpszName =POINTER ?
        lpszClass =POINTER ?
        dwExStyle DWORD ?
      CREATESTRUCTA ends
      tagCREATESTRUCTA typedef CREATESTRUCTA
      LPCREATESTRUCTA typedef ptr CREATESTRUCTA
      CREATESTRUCTW struct
        lpCreateParams POINTER ?
        hInstance HINSTANCE ?
        hMenu HMENU ?
        hwndParent HWND ?
        cy SDWORD ?
        cx_ SDWORD ?
        y SDWORD ?
        x SDWORD ?
        style SDWORD ?
        lpszName =POINTER ?
        lpszClass =POINTER ?
        dwExStyle DWORD ?
      CREATESTRUCTW ends
      tagCREATESTRUCTW typedef CREATESTRUCTW
      LPCREATESTRUCTW typedef ptr CREATESTRUCTW
      ifdef UNICODE
        CREATESTRUCT typedef CREATESTRUCTW
        LPCREATESTRUCT typedef LPCREATESTRUCTW
      else
        CREATESTRUCT typedef CREATESTRUCTA
        LPCREATESTRUCT typedef LPCREATESTRUCTA
      endif
      ; UNICODE
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      WINDOWPLACEMENT struct
        length_ DWORD ?
        flags DWORD ?
        showCmd DWORD ?
        ptMinPosition POINT <>
        ptMaxPosition POINT <>
        rcNormalPosition RECT <>
        ifdef _MAC
          ;[...]
        endif
      WINDOWPLACEMENT ends
      tagWINDOWPLACEMENT typedef WINDOWPLACEMENT
      PWINDOWPLACEMENT typedef ptr WINDOWPLACEMENT
      LPWINDOWPLACEMENT typedef ptr WINDOWPLACEMENT
      WPF_SETMINPOSITION equ 0001h
      WPF_RESTORETOMAXIMIZED equ 0002h
      if (_WIN32_WINNT ge 0500h)
        WPF_ASYNCWINDOWPLACEMENT equ 0004h
        ;* _WIN32_WINNT >= 0x0500 *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if (WINVER ge 0400h)
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        NMHDR struct
          hwndFrom HWND ?
          idFrom XWORD ?
          code DWORD ?
          ; NM_ code
        NMHDR ends
        tagNMHDR typedef NMHDR
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        LPNMHDR typedef ptr NMHDR
        STYLESTRUCT struct
          styleOld DWORD ?
          styleNew DWORD ?
        STYLESTRUCT ends
        tagSTYLESTRUCT typedef STYLESTRUCT
        LPSTYLESTRUCT typedef ptr STYLESTRUCT
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;* WINVER >= 0x0400 *
    endif
    ;*
    ;* Owner draw control types
    ;*
    ODT_MENU equ 1
    ODT_LISTBOX equ 2
    ODT_COMBOBOX equ 3
    ODT_BUTTON equ 4
    if (WINVER ge 0400h)
      ODT_STATIC equ 5
      ;* WINVER >= 0x0400 *
    endif
    ;*
    ;* Owner draw actions
    ;*
    ODA_DRAWENTIRE equ 0001h
    ODA_SELECT equ 0002h
    ODA_FOCUS equ 0004h
    ;*
    ;* Owner draw state
    ;*
    ODS_SELECTED equ 0001h
    ODS_GRAYED equ 0002h
    ODS_DISABLED equ 0004h
    ODS_CHECKED equ 0008h
    ODS_FOCUS equ 0010h
    if (WINVER ge 0400h)
      ODS_DEFAULT equ 0020h
      ODS_COMBOBOXEDIT equ 1000h
      ;* WINVER >= 0x0400 *
    endif
    if (WINVER ge 0500h)
      ODS_HOTLIGHT equ 0040h
      ODS_INACTIVE equ 0080h
      if (_WIN32_WINNT ge 0500h)
        ODS_NOACCEL equ 0100h
        ODS_NOFOCUSRECT equ 0200h
        ;* _WIN32_WINNT >= 0x0500 *
      endif
      ;* WINVER >= 0x0500 *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ;*
      ;* MEASUREITEMSTRUCT for ownerdraw
      ;*
      MEASUREITEMSTRUCT struct
        CtlType DWORD ?
        CtlID DWORD ?
        itemID DWORD ?
        itemWidth DWORD ?
        itemHeight DWORD ?
        itemData XWORD ?
      MEASUREITEMSTRUCT ends
      tagMEASUREITEMSTRUCT typedef MEASUREITEMSTRUCT
      PMEASUREITEMSTRUCT typedef ptr MEASUREITEMSTRUCT
      LPMEASUREITEMSTRUCT typedef ptr MEASUREITEMSTRUCT
      ;*
      ;* DRAWITEMSTRUCT for ownerdraw
      ;*
      DRAWITEMSTRUCT struct
        CtlType DWORD ?
        CtlID DWORD ?
        itemID DWORD ?
        itemAction DWORD ?
        itemState DWORD ?
        hwndItem HWND ?
        hDC HDC ?
        rcItem RECT <>
        itemData XWORD ?
      DRAWITEMSTRUCT ends
      tagDRAWITEMSTRUCT typedef DRAWITEMSTRUCT
      PDRAWITEMSTRUCT typedef ptr DRAWITEMSTRUCT
      LPDRAWITEMSTRUCT typedef ptr DRAWITEMSTRUCT
      ;*
      ;* DELETEITEMSTRUCT for ownerdraw
      ;*
      DELETEITEMSTRUCT struct
        CtlType DWORD ?
        CtlID DWORD ?
        itemID DWORD ?
        hwndItem HWND ?
        itemData XWORD ?
      DELETEITEMSTRUCT ends
      tagDELETEITEMSTRUCT typedef DELETEITEMSTRUCT
      PDELETEITEMSTRUCT typedef ptr DELETEITEMSTRUCT
      LPDELETEITEMSTRUCT typedef ptr DELETEITEMSTRUCT
      ;*
      ;* COMPAREITEMSTUCT for ownerdraw sorting
      ;*
      COMPAREITEMSTRUCT struct
        CtlType DWORD ?
        CtlID DWORD ?
        hwndItem HWND ?
        itemID1 DWORD ?
        itemData1 XWORD ?
        itemID2 DWORD ?
        itemData2 XWORD ?
        dwLocaleId DWORD ?
      COMPAREITEMSTRUCT ends
      tagCOMPAREITEMSTRUCT typedef COMPAREITEMSTRUCT
      PCOMPAREITEMSTRUCT typedef ptr COMPAREITEMSTRUCT
      LPCOMPAREITEMSTRUCT typedef ptr COMPAREITEMSTRUCT
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ifndef NOMSG
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
        ;*
        ;* Message Function Templates
        ;*
        @DefProto DllImport, GetMessageA, WIN_STD_CALL_CONV,, <:LPMSG, :HWND, :UINT, :UINT>, 16
        @DefProto DllImport, GetMessageW, WIN_STD_CALL_CONV,, <:LPMSG, :HWND, :UINT, :UINT>, 16
        ifdef UNICODE
          GetMessage equ <GetMessageW>
        else
          GetMessage equ <GetMessageA>
        endif
        ; !UNICODE
        if Defined(_M_CEE)
          ;[...]
        endif
        @DefProto DllImport, TranslateMessage, WIN_STD_CALL_CONV,, <:ptr MSG>, 4
        @DefProto DllImport, DispatchMessageA, WIN_STD_CALL_CONV,, <:ptr MSG>, 4
        @DefProto DllImport, DispatchMessageW, WIN_STD_CALL_CONV,, <:ptr MSG>, 4
        ifdef UNICODE
          DispatchMessage equ <DispatchMessageW>
        else
          DispatchMessage equ <DispatchMessageA>
        endif
        ; !UNICODE
        if Defined(_M_CEE)
          ;[...]
        endif
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_GAMES) *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, SetMessageQueue, WIN_STD_CALL_CONV,, <:SDWORD>, 4
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
        @DefProto DllImport, PeekMessageA, WIN_STD_CALL_CONV,, <:LPMSG, :HWND, :UINT, :UINT, :UINT>, 20
        @DefProto DllImport, PeekMessageW, WIN_STD_CALL_CONV,, <:LPMSG, :HWND, :UINT, :UINT, :UINT>, 20
        ifdef UNICODE
          PeekMessage equ <PeekMessageW>
        else
          PeekMessage equ <PeekMessageA>
        endif
        ; !UNICODE
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_GAMES) *
      endif
      ;*
      ;* PeekMessage() Options
      ;*
      PM_NOREMOVE equ 0000h
      PM_REMOVE equ 0001h
      PM_NOYIELD equ 0002h
      if (WINVER ge 0500h)
        PM_QS_INPUT equ (QS_INPUT shl 16)
        PM_QS_POSTMESSAGE equ ((QS_POSTMESSAGE or QS_HOTKEY or QS_TIMER) shl 16)
        PM_QS_PAINT equ (QS_PAINT shl 16)
        PM_QS_SENDMESSAGE equ (QS_SENDMESSAGE shl 16)
        ;* WINVER >= 0x0500 *
      endif
      ;* !NOMSG *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, RegisterHotKey, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :UINT, :UINT>, 16
      @DefProto DllImport, UnregisterHotKey, WIN_STD_CALL_CONV,, <:HWND, :SDWORD>, 8
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    MOD_ALT equ 0001h
    MOD_CONTROL equ 0002h
    MOD_SHIFT equ 0004h
    MOD_WIN equ 0008h
    if (WINVER ge 0601h)
      MOD_NOREPEAT equ 4000h
      ;* WINVER >= 0x0601 *
    endif
    ;* SHIFT-PRINTSCRN  *
    IDHOT_SNAPWINDOW equ (- 1)
    ;* PRINTSCRN        *
    IDHOT_SNAPDESKTOP equ (- 2)
    ifdef WIN_INTERNAL
      ifndef LSTRING
        NOLSTRING equ <>
        ;* LSTRING *
      endif
      ifndef LFILEIO
        NOLFILEIO equ <>
        ;* LFILEIO *
      endif
      ;* WIN_INTERNAL *
    endif
    if (WINVER ge 0400h)
      ;* WINVER >= 0x0400 *
    endif
    if (_WIN32_WINNT ge 0400h)
      ENDSESSION_CLOSEAPP equ 00000001h
      ;* _WIN32_WINNT >= 0x0400 *
    endif
    if (_WIN32_WINNT ge 0400h)
      ENDSESSION_CRITICAL equ 40000000h
      ;* _WIN32_WINNT >= 0x0400 *
    endif
    if (_WIN32_WINNT ge 0400h)
      ENDSESSION_LOGOFF equ 80000000h
      ;* _WIN32_WINNT >= 0x0400 *
    endif
    EWX_LOGOFF equ 00000000h
    EWX_SHUTDOWN equ 00000001h
    EWX_REBOOT equ 00000002h
    EWX_FORCE equ 00000004h
    EWX_POWEROFF equ 00000008h
    if (_WIN32_WINNT ge 0500h)
      EWX_FORCEIFHUNG equ 00000010h
      ;* _WIN32_WINNT >= 0x0500 *
    endif
    EWX_QUICKRESOLVE equ 00000020h
    if (_WIN32_WINNT ge 0600h)
      EWX_RESTARTAPPS equ 00000040h
      ;* _WIN32_WINNT >= 0x0600 *
    endif
    EWX_HYBRID_SHUTDOWN equ 00400000h
    EWX_BOOTOPTIONS equ 01000000h
    EWX_ARSO equ 04000000h
    EWX_CHECK_SAFE_FOR_SERVER equ 08000000h
    EWX_SYSTEM_INITIATED equ 10000000h
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ExitWindows macro dwReserved, Code
        exitm <ExitWindowsEx (EWX_LOGOFF, 0FFFFFFFFh)>
      endm
      @DefProto DllImport, ExitWindowsEx, WIN_STD_CALL_CONV,, <:UINT, :DWORD>, 8
      @DefProto DllImport, SwapMouseButton, WIN_STD_CALL_CONV,, <:BOOL>, 4
      @DefProto DllImport, GetMessagePos, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, GetMessageTime, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, GetMessageExtraInfo, WIN_STD_CALL_CONV,, <>, 0
      if (_WIN32_WINNT ge 0602h)
        @DefProto DllImport, GetUnpredictedMessagePos, WIN_STD_CALL_CONV,, <>, 0
        ;* _WIN32_WINNT >= 0x0602 *
      endif
      if (_WIN32_WINNT ge 0501h)
        @DefProto DllImport, IsWow64Message, WIN_STD_CALL_CONV,, <>, 0
        ;* _WIN32_WINNT >= 0x0501 *
      endif
      if (WINVER ge 0400h)
        @DefProto DllImport, SetMessageExtraInfo, WIN_STD_CALL_CONV,, <:LPARAM>, 4
        ;* WINVER >= 0x0400 *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, SendMessageA, WIN_STD_CALL_CONV,, <:HWND, :UINT, :WPARAM, :LPARAM>, 16
      @DefProto DllImport, SendMessageW, WIN_STD_CALL_CONV,, <:HWND, :UINT, :WPARAM, :LPARAM>, 16
      ifdef UNICODE
        SendMessage equ <SendMessageW>
      else
        SendMessage equ <SendMessageA>
      endif
      ; !UNICODE
      if Defined(_M_CEE)
        ;[...]
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, SendMessageTimeoutA, WIN_STD_CALL_CONV,, <:HWND, :UINT, :WPARAM, :LPARAM, :UINT, :UINT, :PDWORD_PTR>, 28
      @DefProto DllImport, SendMessageTimeoutW, WIN_STD_CALL_CONV,, <:HWND, :UINT, :WPARAM, :LPARAM, :UINT, :UINT, :PDWORD_PTR>, 28
      ifdef UNICODE
        SendMessageTimeout equ <SendMessageTimeoutW>
      else
        SendMessageTimeout equ <SendMessageTimeoutA>
      endif
      ; !UNICODE
      @DefProto DllImport, SendNotifyMessageA, WIN_STD_CALL_CONV,, <:HWND, :UINT, :WPARAM, :LPARAM>, 16
      @DefProto DllImport, SendNotifyMessageW, WIN_STD_CALL_CONV,, <:HWND, :UINT, :WPARAM, :LPARAM>, 16
      ifdef UNICODE
        SendNotifyMessage equ <SendNotifyMessageW>
      else
        SendNotifyMessage equ <SendNotifyMessageA>
      endif
      ; !UNICODE
      @DefProto DllImport, SendMessageCallbackA, WIN_STD_CALL_CONV,, <:HWND, :UINT, :WPARAM, :LPARAM, :SENDASYNCPROC, :ULONG_PTR>, 24
      @DefProto DllImport, SendMessageCallbackW, WIN_STD_CALL_CONV,, <:HWND, :UINT, :WPARAM, :LPARAM, :SENDASYNCPROC, :ULONG_PTR>, 24
      ifdef UNICODE
        SendMessageCallback equ <SendMessageCallbackW>
      else
        SendMessageCallback equ <SendMessageCallbackA>
      endif
      ; !UNICODE
      if (_WIN32_WINNT ge 0501h)
        BSMINFO struct
          cbSize DWORD ?
          hdesk HDESK ?
          hwnd HWND ?
          luid LUID <>
        BSMINFO ends
        PBSMINFO typedef ptr BSMINFO
        @DefProto DllImport, BroadcastSystemMessageExA, WIN_STD_CALL_CONV,, <:DWORD, :LPDWORD, :UINT, :WPARAM, :LPARAM, :PBSMINFO>, 24
        @DefProto DllImport, BroadcastSystemMessageExW, WIN_STD_CALL_CONV,, <:DWORD, :LPDWORD, :UINT, :WPARAM, :LPARAM, :PBSMINFO>, 24
        ifdef UNICODE
          BroadcastSystemMessageEx equ <BroadcastSystemMessageExW>
        else
          BroadcastSystemMessageEx equ <BroadcastSystemMessageExA>
        endif
        ; !UNICODE
        ;* _WIN32_WINNT >= 0x0501 *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if (WINVER ge 0400h)
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        if Defined(_WIN32_WINNT)
          @DefProto DllImport, BroadcastSystemMessageA, WIN_STD_CALL_CONV,, <:DWORD, :LPDWORD, :UINT, :WPARAM, :LPARAM>, 20
          @DefProto DllImport, BroadcastSystemMessageW, WIN_STD_CALL_CONV,, <:DWORD, :LPDWORD, :UINT, :WPARAM, :LPARAM>, 20
          ifdef UNICODE
            BroadcastSystemMessage equ <BroadcastSystemMessageW>
          else
            BroadcastSystemMessage equ <BroadcastSystemMessageA>
          endif
          ; !UNICODE
        elseif Defined(_WIN32_WINDOWS)
          ; The Win95 version isn't A/W decorated
          @DefProto DllImport, BroadcastSystemMessage, WIN_STD_CALL_CONV,, <:DWORD, :LPDWORD, :UINT, :WPARAM, :LPARAM>, 20
        endif
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;Broadcast Special Message Recipient list
      BSM_ALLCOMPONENTS equ 00000000h
      BSM_VXDS equ 00000001h
      BSM_NETDRIVER equ 00000002h
      BSM_INSTALLABLEDRIVERS equ 00000004h
      BSM_APPLICATIONS equ 00000008h
      BSM_ALLDESKTOPS equ 00000010h
      ;Broadcast Special Message Flags
      BSF_QUERY equ 00000001h
      BSF_IGNORECURRENTTASK equ 00000002h
      BSF_FLUSHDISK equ 00000004h
      BSF_NOHANG equ 00000008h
      BSF_POSTMESSAGE equ 00000010h
      BSF_FORCEIFHUNG equ 00000020h
      BSF_NOTIMEOUTIFNOTHUNG equ 00000040h
      if (_WIN32_WINNT ge 0500h)
        BSF_ALLOWSFW equ 00000080h
        BSF_SENDNOTIFYMESSAGE equ 00000100h
        ;* _WIN32_WINNT >= 0x0500 *
      endif
      if (_WIN32_WINNT ge 0501h)
        BSF_RETURNHDESK equ 00000200h
        BSF_LUID equ 00000400h
        ;* _WIN32_WINNT >= 0x0501 *
      endif
      BROADCAST_QUERY_DENY equ 424D5144h; Return this value to deny a query.

      ;* WINVER >= 0x0400 *
    endif
    ; RegisterDeviceNotification
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      if (WINVER ge 0500h)
        HDEVNOTIFY typedef PVOID
        PHDEVNOTIFY typedef ptr HDEVNOTIFY
        DEVICE_NOTIFY_WINDOW_HANDLE equ 00000000h
        DEVICE_NOTIFY_SERVICE_HANDLE equ 00000001h
        if (_WIN32_WINNT ge 0501h)
          DEVICE_NOTIFY_ALL_INTERFACE_CLASSES equ 00000004h
          ;* _WIN32_WINNT >= 0x0501 *
        endif
        @DefProto DllImport, RegisterDeviceNotificationA, WIN_STD_CALL_CONV,, <:HANDLE, :LPVOID, :DWORD>, 12
        @DefProto DllImport, RegisterDeviceNotificationW, WIN_STD_CALL_CONV,, <:HANDLE, :LPVOID, :DWORD>, 12
        ifdef UNICODE
          RegisterDeviceNotification equ <RegisterDeviceNotificationW>
        else
          RegisterDeviceNotification equ <RegisterDeviceNotificationA>
        endif
        ; !UNICODE
        @DefProto DllImport, UnregisterDeviceNotification, WIN_STD_CALL_CONV,, <:HDEVNOTIFY>, 4
        if (_WIN32_WINNT ge 0502h)
          if  not Defined(_HPOWERNOTIFY_DEF_)
            _HPOWERNOTIFY_DEF_ equ <>
            HPOWERNOTIFY typedef PVOID
            PHPOWERNOTIFY typedef ptr HPOWERNOTIFY
          endif
          @DefProto DllImport, RegisterPowerSettingNotification, WIN_STD_CALL_CONV,, <:HANDLE, :LPCGUID, :DWORD>, 12
          @DefProto DllImport, UnregisterPowerSettingNotification, WIN_STD_CALL_CONV,, <:HPOWERNOTIFY>, 4
          @DefProto DllImport, RegisterSuspendResumeNotification, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD>, 8
          @DefProto DllImport, UnregisterSuspendResumeNotification, WIN_STD_CALL_CONV,, <:HPOWERNOTIFY>, 4
        endif
        ; (_WIN32_WINNT >= 0x0502)
        ;* WINVER >= 0x0500 *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, PostMessageA, WIN_STD_CALL_CONV,, <:HWND, :UINT, :WPARAM, :LPARAM>, 16
      @DefProto DllImport, PostMessageW, WIN_STD_CALL_CONV,, <:HWND, :UINT, :WPARAM, :LPARAM>, 16
      ifdef UNICODE
        PostMessage equ <PostMessageW>
      else
        PostMessage equ <PostMessageA>
      endif
      ; !UNICODE
      @DefProto DllImport, PostThreadMessageA, WIN_STD_CALL_CONV,, <:DWORD, :UINT, :WPARAM, :LPARAM>, 16
      @DefProto DllImport, PostThreadMessageW, WIN_STD_CALL_CONV,, <:DWORD, :UINT, :WPARAM, :LPARAM>, 16
      ifdef UNICODE
        PostThreadMessage equ <PostThreadMessageW>
      else
        PostThreadMessage equ <PostThreadMessageA>
      endif
      ; !UNICODE
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_GAMES) *
    endif
    PostAppMessageA macro idThread, wMsg, wParam, lParam
      exitm <PostThreadMessageA (idThread, wMsg, wParam, lParam)>
    endm
    PostAppMessageW macro idThread, wMsg, wParam, lParam
      exitm <PostThreadMessageW (idThread, wMsg, wParam, lParam)>
    endm
    ifdef UNICODE
      PostAppMessage equ <PostAppMessageW>
    else
      PostAppMessage equ <PostAppMessageA>
    endif
    ; !UNICODE
    ;*
    ;* Special HWND value for use with PostMessage() and SendMessage()
    ;*
    HWND_BROADCAST equ (0ffffh)
    if (WINVER ge 0500h)
      HWND_MESSAGE equ (- 3)
      ;* WINVER >= 0x0500 *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, AttachThreadInput, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :BOOL>, 12
      @DefProto DllImport, ReplyMessage, WIN_STD_CALL_CONV,, <:LRESULT>, 4
      @DefProto DllImport, WaitMessage, WIN_STD_CALL_CONV,, <>, 0
      if (_WIN32_WINNT ge 602h)
      endif
      @DefProto DllImport, WaitForInputIdle, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD>, 8
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      ifndef _MAC
      else
        ;[...]
      endif
      @DefProto DllImport, DefWindowProcA, WIN_STD_CALL_CONV,, <:HWND, :UINT, :WPARAM, :LPARAM>, 16
      ifndef _MAC
      else
        ;[...]
      endif
      @DefProto DllImport, DefWindowProcW, WIN_STD_CALL_CONV,, <:HWND, :UINT, :WPARAM, :LPARAM>, 16
      ifdef UNICODE
        DefWindowProc equ <DefWindowProcW>
      else
        DefWindowProc equ <DefWindowProcA>
      endif
      ; !UNICODE
      @DefProto DllImport, PostQuitMessage, WIN_STD_CALL_CONV,, <:SDWORD>, 4
      ifdef STRICT
        @DefProto DllImport, CallWindowProcA, WIN_STD_CALL_CONV,, <:WNDPROC, :HWND, :UINT, :WPARAM, :LPARAM>, 20
        @DefProto DllImport, CallWindowProcW, WIN_STD_CALL_CONV,, <:WNDPROC, :HWND, :UINT, :WPARAM, :LPARAM>, 20
        ifdef UNICODE
          CallWindowProc equ <CallWindowProcW>
        else
          CallWindowProc equ <CallWindowProcA>
        endif
        ; !UNICODE
        ;* !STRICT *
      else
        @DefProto DllImport, CallWindowProcA, WIN_STD_CALL_CONV,, <:FARPROC, :HWND, :UINT, :WPARAM, :LPARAM>, 20
        @DefProto DllImport, CallWindowProcW, WIN_STD_CALL_CONV,, <:FARPROC, :HWND, :UINT, :WPARAM, :LPARAM>, 20
        ifdef UNICODE
          CallWindowProc equ <CallWindowProcW>
        else
          CallWindowProc equ <CallWindowProcA>
        endif
        ; !UNICODE
        ;* !STRICT *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, InSendMessage, WIN_STD_CALL_CONV,, <>, 0
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if (WINVER ge 0500h)
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, InSendMessageEx, WIN_STD_CALL_CONV,, <:LPVOID>, 4
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;*
      ;* InSendMessageEx return value
      ;*
      ISMEX_NOSEND equ 00000000h
      ISMEX_SEND equ 00000001h
      ISMEX_NOTIFY equ 00000002h
      ISMEX_CALLBACK equ 00000004h
      ISMEX_REPLIED equ 00000008h
      ;* WINVER >= 0x0500 *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, GetDoubleClickTime, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, SetDoubleClickTime, WIN_STD_CALL_CONV,, <:UINT>, 4
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, RegisterClassA, WIN_STD_CALL_CONV,, <:ptr WNDCLASSA>, 4
      @DefProto DllImport, RegisterClassW, WIN_STD_CALL_CONV,, <:ptr WNDCLASSW>, 4
      ifdef UNICODE
        RegisterClass equ <RegisterClassW>
      else
        RegisterClass equ <RegisterClassA>
      endif
      ; !UNICODE
      @DefProto DllImport, UnregisterClassA, WIN_STD_CALL_CONV,, <:LPCSTR, :HINSTANCE>, 8
      @DefProto DllImport, UnregisterClassW, WIN_STD_CALL_CONV,, <:LPCWSTR, :HINSTANCE>, 8
      ifdef UNICODE
        UnregisterClass equ <UnregisterClassW>
      else
        UnregisterClass equ <UnregisterClassA>
      endif
      ; !UNICODE
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, GetClassInfoA, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCSTR, :LPWNDCLASSA>, 12
      @DefProto DllImport, GetClassInfoW, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCWSTR, :LPWNDCLASSW>, 12
      ifdef UNICODE
        GetClassInfo equ <GetClassInfoW>
      else
        GetClassInfo equ <GetClassInfoA>
      endif
      ; !UNICODE
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      if (WINVER ge 0400h)
        @DefProto DllImport, RegisterClassExA, WIN_STD_CALL_CONV,, <:ptr WNDCLASSEXA>, 4
        @DefProto DllImport, RegisterClassExW, WIN_STD_CALL_CONV,, <:ptr WNDCLASSEXW>, 4
        ifdef UNICODE
          RegisterClassEx equ <RegisterClassExW>
        else
          RegisterClassEx equ <RegisterClassExA>
        endif
        ; !UNICODE
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_GAMES) *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, GetClassInfoExA, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCSTR, :LPWNDCLASSEXA>, 12
        @DefProto DllImport, GetClassInfoExW, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCWSTR, :LPWNDCLASSEXW>, 12
        ifdef UNICODE
          GetClassInfoEx equ <GetClassInfoExW>
        else
          GetClassInfoEx equ <GetClassInfoExA>
        endif
        ; !UNICODE
        ;* WINVER >= 0x0400 *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    CW_USEDEFAULT equ (80000000h)
    ;*
    ;* Special value for CreateWindow, et al.
    ;*
    HWND_DESKTOP equ (0)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      if (_WIN32_WINNT ge 0501h)
        TYPE_PREGISTERCLASSNAMEW typedef proto WIN_STD_CALL_CONV :LPCWSTR
        PREGISTERCLASSNAMEW typedef ptr TYPE_PREGISTERCLASSNAMEW

        ;* _WIN32_WINNT >= 0x0501 *
      endif
      @DefProto DllImport, CreateWindowExA, WIN_STD_CALL_CONV,, <:DWORD, :LPCSTR, :LPCSTR, :DWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :HWND, :HMENU, :HINSTANCE, :LPVOID>, 48
      @DefProto DllImport, CreateWindowExW, WIN_STD_CALL_CONV,, <:DWORD, :LPCWSTR, :LPCWSTR, :DWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :HWND, :HMENU, :HINSTANCE, :LPVOID>, 48
      ifdef UNICODE
        CreateWindowEx equ <CreateWindowExW>
      else
        CreateWindowEx equ <CreateWindowExA>
      endif
      ; !UNICODE
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_GAMES) *
    endif
    CreateWindowA macro lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam
      exitm <CreateWindowExA (0, lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)>
    endm
    CreateWindowW macro lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam
      exitm <CreateWindowExW (0, lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)>
    endm
    ifdef UNICODE
      CreateWindow equ <CreateWindowW>
    else
      CreateWindow equ <CreateWindowA>
    endif
    ; !UNICODE
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, IsWindow, WIN_STD_CALL_CONV,, <:HWND>, 4
      @DefProto DllImport, IsMenu, WIN_STD_CALL_CONV,, <:HMENU>, 4
      @DefProto DllImport, IsChild, WIN_STD_CALL_CONV,, <:HWND, :HWND>, 8
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, DestroyWindow, WIN_STD_CALL_CONV,, <:HWND>, 4
      @DefProto DllImport, ShowWindow, WIN_STD_CALL_CONV,, <:HWND, :SDWORD>, 8
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      if (WINVER ge 0500h)
        @DefProto DllImport, AnimateWindow, WIN_STD_CALL_CONV,, <:HWND, :DWORD, :DWORD>, 12
        ;* WINVER >= 0x0500 *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if (_WIN32_WINNT ge 0500h)
      if Defined(_WINGDI_) and  not Defined(NOGDI)
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
          @DefProto DllImport, UpdateLayeredWindow, WIN_STD_CALL_CONV,, <:HWND, :HDC, :ptr POINT, :ptr SIZE_, :HDC, :ptr POINT, :COLORREF, :ptr BLENDFUNCTION, :DWORD>, 36
          ;*
          ;* Layered Window Update information
          ;*
          UPDATELAYEREDWINDOWINFO struct
            cbSize DWORD ?
            hdcDst HDC ?
            pptDst POINTER ?
            psize POINTER ?
            hdcSrc HDC ?
            pptSrc POINTER ?
            crKey COLORREF ?
            pblend POINTER ?
            dwFlags DWORD ?
            prcDirty POINTER ?
          UPDATELAYEREDWINDOWINFO ends
          tagUPDATELAYEREDWINDOWINFO typedef UPDATELAYEREDWINDOWINFO
          PUPDATELAYEREDWINDOWINFO typedef ptr UPDATELAYEREDWINDOWINFO
          if (_WIN32_WINNT lt 0502h)
            ;* _WIN32_WINNT < 0x0502 *
          endif
          UpdateLayeredWindowIndirect typedef proto :HWND, :ptr UPDATELAYEREDWINDOWINFO
          ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
        endif
      endif
      if (_WIN32_WINNT ge 0501h)
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
          @DefProto DllImport, GetLayeredWindowAttributes, WIN_STD_CALL_CONV,, <:HWND, :ptr COLORREF, :ptr BYTE, :ptr DWORD>, 16
          PW_CLIENTONLY equ 00000001h
          if (_WIN32_WINNT ge 0603h)
            PW_RENDERFULLCONTENT equ 00000002h
            ;* _WIN32_WINNT >= 0x0603 *
          endif
          @DefProto DllImport, PrintWindow, WIN_STD_CALL_CONV,, <:HWND, :HDC, :UINT>, 12
          ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
        endif
        ;* _WIN32_WINNT >= 0x0501 *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, SetLayeredWindowAttributes, WIN_STD_CALL_CONV,, <:HWND, :COLORREF, :BYTE, :DWORD>, 16
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      LWA_COLORKEY equ 00000001h
      LWA_ALPHA equ 00000002h
      ULW_COLORKEY equ 00000001h
      ULW_ALPHA equ 00000002h
      ULW_OPAQUE equ 00000004h
      ULW_EX_NORESIZE equ 00000008h
      ;* _WIN32_WINNT >= 0x0500 *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      if (WINVER ge 0400h)
        @DefProto DllImport, ShowWindowAsync, WIN_STD_CALL_CONV,, <:HWND, :SDWORD>, 8
        ;* WINVER >= 0x0400 *
      endif
      @DefProto DllImport, FlashWindow, WIN_STD_CALL_CONV,, <:HWND, :BOOL>, 8
      if (WINVER ge 0500h)
        FLASHWINFO struct
          cbSize DWORD ?
          hwnd HWND ?
          dwFlags DWORD ?
          uCount DWORD ?
          dwTimeout DWORD ?
        FLASHWINFO ends
        PFLASHWINFO typedef ptr FLASHWINFO
        @DefProto DllImport, FlashWindowEx, WIN_STD_CALL_CONV,, <:PFLASHWINFO>, 4
        FLASHW_STOP equ 0
        FLASHW_CAPTION equ 00000001h
        FLASHW_TRAY equ 00000002h
        FLASHW_ALL equ <(FLASHW_CAPTION or FLASHW_TRAY)>
        FLASHW_TIMER equ 00000004h
        FLASHW_TIMERNOFG equ 0000000Ch
        ;* WINVER >= 0x0500 *
      endif
      @DefProto DllImport, ShowOwnedPopups, WIN_STD_CALL_CONV,, <:HWND, :BOOL>, 8
      @DefProto DllImport, OpenIcon, WIN_STD_CALL_CONV,, <:HWND>, 4
      @DefProto DllImport, CloseWindow, WIN_STD_CALL_CONV,, <:HWND>, 4
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, MoveWindow, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :BOOL>, 24
      @DefProto DllImport, SetWindowPos, WIN_STD_CALL_CONV,, <:HWND, :HWND, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :UINT>, 28
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, GetWindowPlacement, WIN_STD_CALL_CONV,, <:HWND, :ptr WINDOWPLACEMENT>, 8
      @DefProto DllImport, SetWindowPlacement, WIN_STD_CALL_CONV,, <:HWND, :ptr WINDOWPLACEMENT>, 8
      if (_WIN32_WINNT ge 0601h)
        WDA_NONE equ 00000000h
        WDA_MONITOR equ 00000001h
        WDA_EXCLUDEFROMCAPTURE equ 00000011h
        @DefProto DllImport, GetWindowDisplayAffinity, WIN_STD_CALL_CONV,, <:HWND, :ptr DWORD>, 8
        @DefProto DllImport, SetWindowDisplayAffinity, WIN_STD_CALL_CONV,, <:HWND, :DWORD>, 8
        ;* _WIN32_WINNT >= 0x0601 *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ifndef NODEFERWINDOWPOS
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, BeginDeferWindowPos, WIN_STD_CALL_CONV,, <:SDWORD>, 4
        @DefProto DllImport, DeferWindowPos, WIN_STD_CALL_CONV,, <:HDWP, :HWND, :HWND, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :UINT>, 32
        @DefProto DllImport, EndDeferWindowPos, WIN_STD_CALL_CONV,, <:HDWP>, 4
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;* !NODEFERWINDOWPOS *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, IsWindowVisible, WIN_STD_CALL_CONV,, <:HWND>, 4
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, IsIconic, WIN_STD_CALL_CONV,, <:HWND>, 4
      @DefProto DllImport, AnyPopup, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, BringWindowToTop, WIN_STD_CALL_CONV,, <:HWND>, 4
      @DefProto DllImport, IsZoomed, WIN_STD_CALL_CONV,, <:HWND>, 4
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ;*
    ;* SetWindowPos Flags
    ;*
    SWP_NOSIZE equ 0001h
    SWP_NOMOVE equ 0002h
    SWP_NOZORDER equ 0004h
    SWP_NOREDRAW equ 0008h
    SWP_NOACTIVATE equ 0010h
    ;* The frame changed: send WM_NCCALCSIZE *
    SWP_FRAMECHANGED equ 0020h
    SWP_SHOWWINDOW equ 0040h
    SWP_HIDEWINDOW equ 0080h
    SWP_NOCOPYBITS equ 0100h
    ;* Don't do owner Z ordering *
    SWP_NOOWNERZORDER equ 0200h
    ;* Don't send WM_WINDOWPOSCHANGING *
    SWP_NOSENDCHANGING equ 0400h
    SWP_DRAWFRAME equ <SWP_FRAMECHANGED>
    SWP_NOREPOSITION equ <SWP_NOOWNERZORDER>
    if (WINVER ge 0400h)
      SWP_DEFERERASE equ 2000h; same as SWP_DEFERDRAWING

      SWP_ASYNCWINDOWPOS equ 4000h; same as SWP_CREATESPB

      ;* WINVER >= 0x0400 *
    endif
    HWND_TOP equ (0)
    HWND_BOTTOM equ (1)
    HWND_TOPMOST equ (- 1)
    HWND_NOTOPMOST equ (- 2)
    ifndef NOCTLMGR
      ;*
      ;* WARNING:
      ;* The following structures must NOT be DWORD padded because they are
      ;* followed by strings, etc that do not have to be DWORD aligned.
      ;*
      include pshpack2.inc
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        ;*
        ;* original NT 32 bit dialog template:
        ;*
        DLGTEMPLATE struct
          style DWORD ?
          dwExtendedStyle DWORD ?
          cdit WORD ?
          x SWORD ?
          y SWORD ?
          cx_ SWORD ?
          cy SWORD ?
        DLGTEMPLATE ends
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        LPDLGTEMPLATEA typedef ptr DLGTEMPLATE
        LPDLGTEMPLATEW typedef ptr DLGTEMPLATE
        ifdef UNICODE
          LPDLGTEMPLATE typedef LPDLGTEMPLATEW
        else
          LPDLGTEMPLATE typedef LPDLGTEMPLATEA
        endif
        ; UNICODE
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        LPCDLGTEMPLATEA typedef ptr DLGTEMPLATE
        LPCDLGTEMPLATEW typedef ptr DLGTEMPLATE
        ifdef UNICODE
          LPCDLGTEMPLATE typedef LPCDLGTEMPLATEW
        else
          LPCDLGTEMPLATE typedef LPCDLGTEMPLATEA
        endif
        ; UNICODE
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        ;*
        ;* 32 bit Dialog item template.
        ;*
        DLGITEMTEMPLATE struct
          style DWORD ?
          dwExtendedStyle DWORD ?
          x SWORD ?
          y SWORD ?
          cx_ SWORD ?
          cy SWORD ?
          id WORD ?
        DLGITEMTEMPLATE ends
        PDLGITEMTEMPLATEA typedef ptr DLGITEMTEMPLATE
        PDLGITEMTEMPLATEW typedef ptr DLGITEMTEMPLATE
        ifdef UNICODE
          PDLGITEMTEMPLATE typedef PDLGITEMTEMPLATEW
        else
          PDLGITEMTEMPLATE typedef PDLGITEMTEMPLATEA
        endif
        ; UNICODE
        LPDLGITEMTEMPLATEA typedef ptr DLGITEMTEMPLATE
        LPDLGITEMTEMPLATEW typedef ptr DLGITEMTEMPLATE
        ifdef UNICODE
          LPDLGITEMTEMPLATE typedef LPDLGITEMTEMPLATEW
        else
          LPDLGITEMTEMPLATE typedef LPDLGITEMTEMPLATEA
        endif
        ; UNICODE
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;* Resume normal packing *
      include poppack.inc
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, CreateDialogParamA, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCSTR, :HWND, :DLGPROC, :LPARAM>, 20
        @DefProto DllImport, CreateDialogParamW, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCWSTR, :HWND, :DLGPROC, :LPARAM>, 20
        ifdef UNICODE
          CreateDialogParam equ <CreateDialogParamW>
        else
          CreateDialogParam equ <CreateDialogParamA>
        endif
        ; !UNICODE
        @DefProto DllImport, CreateDialogIndirectParamA, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCDLGTEMPLATEA, :HWND, :DLGPROC, :LPARAM>, 20
        @DefProto DllImport, CreateDialogIndirectParamW, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCDLGTEMPLATEW, :HWND, :DLGPROC, :LPARAM>, 20
        ifdef UNICODE
          CreateDialogIndirectParam equ <CreateDialogIndirectParamW>
        else
          CreateDialogIndirectParam equ <CreateDialogIndirectParamA>
        endif
        ; !UNICODE
        CreateDialogA macro hInstance, lpName, hWndParent, lpDialogFunc
          exitm <CreateDialogParamA (hInstance, lpName, hWndParent, lpDialogFunc, 0)>
        endm
        CreateDialogW macro hInstance, lpName, hWndParent, lpDialogFunc
          exitm <CreateDialogParamW (hInstance, lpName, hWndParent, lpDialogFunc, 0)>
        endm
        ifdef UNICODE
          CreateDialog equ <CreateDialogW>
        else
          CreateDialog equ <CreateDialogA>
        endif
        ; !UNICODE
        CreateDialogIndirectA macro hInstance, lpTemplate, hWndParent, lpDialogFunc
          exitm <CreateDialogIndirectParamA (hInstance, lpTemplate, hWndParent, lpDialogFunc, 0)>
        endm
        CreateDialogIndirectW macro hInstance, lpTemplate, hWndParent, lpDialogFunc
          exitm <CreateDialogIndirectParamW (hInstance, lpTemplate, hWndParent, lpDialogFunc, 0)>
        endm
        ifdef UNICODE
          CreateDialogIndirect equ <CreateDialogIndirectW>
        else
          CreateDialogIndirect equ <CreateDialogIndirectA>
        endif
        ; !UNICODE
        @DefProto DllImport, DialogBoxParamA, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCSTR, :HWND, :DLGPROC, :LPARAM>, 20
        @DefProto DllImport, DialogBoxParamW, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCWSTR, :HWND, :DLGPROC, :LPARAM>, 20
        ifdef UNICODE
          DialogBoxParam equ <DialogBoxParamW>
        else
          DialogBoxParam equ <DialogBoxParamA>
        endif
        ; !UNICODE
        @DefProto DllImport, DialogBoxIndirectParamA, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCDLGTEMPLATEA, :HWND, :DLGPROC, :LPARAM>, 20
        @DefProto DllImport, DialogBoxIndirectParamW, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCDLGTEMPLATEW, :HWND, :DLGPROC, :LPARAM>, 20
        ifdef UNICODE
          DialogBoxIndirectParam equ <DialogBoxIndirectParamW>
        else
          DialogBoxIndirectParam equ <DialogBoxIndirectParamA>
        endif
        ; !UNICODE
        DialogBoxA macro hInstance, lpTemplate, hWndParent, lpDialogFunc
          exitm <DialogBoxParamA (hInstance, lpTemplate, hWndParent, lpDialogFunc, 0)>
        endm
        DialogBoxW macro hInstance, lpTemplate, hWndParent, lpDialogFunc
          exitm <DialogBoxParamW (hInstance, lpTemplate, hWndParent, lpDialogFunc, 0)>
        endm
        ifdef UNICODE
          DialogBox equ <DialogBoxW>
        else
          DialogBox equ <DialogBoxA>
        endif
        ; !UNICODE
        DialogBoxIndirectA macro hInstance, lpTemplate, hWndParent, lpDialogFunc
          exitm <DialogBoxIndirectParamA (hInstance, lpTemplate, hWndParent, lpDialogFunc, 0)>
        endm
        DialogBoxIndirectW macro hInstance, lpTemplate, hWndParent, lpDialogFunc
          exitm <DialogBoxIndirectParamW (hInstance, lpTemplate, hWndParent, lpDialogFunc, 0)>
        endm
        ifdef UNICODE
          DialogBoxIndirect equ <DialogBoxIndirectW>
        else
          DialogBoxIndirect equ <DialogBoxIndirectA>
        endif
        ; !UNICODE
        @DefProto DllImport, EndDialog, WIN_STD_CALL_CONV,, <:HWND, :INT_PTR>, 8
        @DefProto DllImport, GetDlgItem, WIN_STD_CALL_CONV,, <:HWND, :SDWORD>, 8
        @DefProto DllImport, SetDlgItemInt, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :UINT, :BOOL>, 16
        @DefProto DllImport, GetDlgItemInt, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :ptr BOOL, :BOOL>, 16
        @DefProto DllImport, SetDlgItemTextA, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LPCSTR>, 12
        @DefProto DllImport, SetDlgItemTextW, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LPCWSTR>, 12
        ifdef UNICODE
          SetDlgItemText equ <SetDlgItemTextW>
        else
          SetDlgItemText equ <SetDlgItemTextA>
        endif
        ; !UNICODE
        @DefProto DllImport, GetDlgItemTextA, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LPSTR, :SDWORD>, 16
        @DefProto DllImport, GetDlgItemTextW, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LPWSTR, :SDWORD>, 16
        ifdef UNICODE
          GetDlgItemText equ <GetDlgItemTextW>
        else
          GetDlgItemText equ <GetDlgItemTextA>
        endif
        ; !UNICODE
        @DefProto DllImport, CheckDlgButton, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :UINT>, 12
        @DefProto DllImport, CheckRadioButton, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :SDWORD, :SDWORD>, 16
        @DefProto DllImport, IsDlgButtonChecked, WIN_STD_CALL_CONV,, <:HWND, :SDWORD>, 8
        @DefProto DllImport, SendDlgItemMessageA, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :UINT, :WPARAM, :LPARAM>, 20
        @DefProto DllImport, SendDlgItemMessageW, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :UINT, :WPARAM, :LPARAM>, 20
        ifdef UNICODE
          SendDlgItemMessage equ <SendDlgItemMessageW>
        else
          SendDlgItemMessage equ <SendDlgItemMessageA>
        endif
        ; !UNICODE
        @DefProto DllImport, GetNextDlgGroupItem, WIN_STD_CALL_CONV,, <:HWND, :HWND, :BOOL>, 12
        @DefProto DllImport, GetNextDlgTabItem, WIN_STD_CALL_CONV,, <:HWND, :HWND, :BOOL>, 12
        @DefProto DllImport, GetDlgCtrlID, WIN_STD_CALL_CONV,, <:HWND>, 4
        @DefProto DllImport, GetDialogBaseUnits, WIN_STD_CALL_CONV,, <>, 0
        ifndef _MAC
        else
          ;[...]
        endif
        @DefProto DllImport, DefDlgProcA, WIN_STD_CALL_CONV,, <:HWND, :UINT, :WPARAM, :LPARAM>, 16
        ifndef _MAC
        else
          ;[...]
        endif
        @DefProto DllImport, DefDlgProcW, WIN_STD_CALL_CONV,, <:HWND, :UINT, :WPARAM, :LPARAM>, 16
        ifdef UNICODE
          DefDlgProc equ <DefDlgProcW>
        else
          DefDlgProc equ <DefDlgProcA>
        endif
        ; !UNICODE
        DIALOG_CONTROL_DPI_CHANGE_BEHAVIORS typedef SDWORD
        DCDC_DEFAULT equ 0000h
        DCDC_DISABLE_FONT_UPDATE equ 0001h
        DCDC_DISABLE_RELAYOUT equ 0002h

        ifndef MIDL_PASS
          DEFINE_ENUM_FLAG_OPERATORS(DIALOG_CONTROL_DPI_CHANGE_BEHAVIORS)
        endif
        SetDialogControlDpiChangeBehavior proto WIN_STD_CALL_CONV :HWND, :DIALOG_CONTROL_DPI_CHANGE_BEHAVIORS, :DIALOG_CONTROL_DPI_CHANGE_BEHAVIORS
        GetDialogControlDpiChangeBehavior proto WIN_STD_CALL_CONV :HWND
        DIALOG_DPI_CHANGE_BEHAVIORS typedef SDWORD
        DDC_DEFAULT equ 0000h
        DDC_DISABLE_ALL equ 0001h
        DDC_DISABLE_RESIZE equ 0002h
        DDC_DISABLE_CONTROL_RELAYOUT equ 0004h

        ifndef MIDL_PASS
          DEFINE_ENUM_FLAG_OPERATORS(DIALOG_DPI_CHANGE_BEHAVIORS)
        endif
        SetDialogDpiChangeBehavior proto WIN_STD_CALL_CONV :HWND, :DIALOG_DPI_CHANGE_BEHAVIORS, :DIALOG_DPI_CHANGE_BEHAVIORS
        GetDialogDpiChangeBehavior proto WIN_STD_CALL_CONV :HWND
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;*
      ;* Window extra byted needed for private dialog classes.
      ;*
      ifndef _MAC
        DLGWINDOWEXTRA equ 30
      else
        ;[...]
      endif
      ;* !NOCTLMGR *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ifndef NOMSG
        @DefProto DllImport, CallMsgFilterA, WIN_STD_CALL_CONV,, <:LPMSG, :SDWORD>, 8
        @DefProto DllImport, CallMsgFilterW, WIN_STD_CALL_CONV,, <:LPMSG, :SDWORD>, 8
        ifdef UNICODE
          CallMsgFilter equ <CallMsgFilterW>
        else
          CallMsgFilter equ <CallMsgFilterA>
        endif
        ; !UNICODE
        ;* !NOMSG *
      endif
      ifndef NOCLIPBOARD
        ;*
        ;* Clipboard Manager Functions
        ;*
        @DefProto DllImport, OpenClipboard, WIN_STD_CALL_CONV,, <:HWND>, 4
        @DefProto DllImport, CloseClipboard, WIN_STD_CALL_CONV,, <>, 0
        if (WINVER ge 0500h)
          @DefProto DllImport, GetClipboardSequenceNumber, WIN_STD_CALL_CONV,, <>, 0
          ;* WINVER >= 0x0500 *
        endif
        @DefProto DllImport, GetClipboardOwner, WIN_STD_CALL_CONV,, <>, 0
        @DefProto DllImport, SetClipboardViewer, WIN_STD_CALL_CONV,, <:HWND>, 4
        @DefProto DllImport, GetClipboardViewer, WIN_STD_CALL_CONV,, <>, 0
        @DefProto DllImport, ChangeClipboardChain, WIN_STD_CALL_CONV,, <:HWND, :HWND>, 8
        @DefProto DllImport, SetClipboardData, WIN_STD_CALL_CONV,, <:UINT, :HANDLE>, 8
        @DefProto DllImport, GetClipboardData, WIN_STD_CALL_CONV,, <:UINT>, 4
        GETCLIPBMETADATA struct
          Version DWORD ?
          ; Currently version 1; increment this value to add more fields.
          IsDelayRendered DWORD ?
          ; Indicates if the data is delay-rendered.
          IsSynthetic DWORD ?
          ; Indicates if the data is produced on-demand from another format (some bitmap/text/metafile).
        GETCLIPBMETADATA ends
        tagGETCLIPBMETADATA typedef GETCLIPBMETADATA
        PGETCLIPBMETADATA typedef ptr GETCLIPBMETADATA
        @DefProto DllImport, GetClipboardMetadata, WIN_STD_CALL_CONV,, <:UINT, :PGETCLIPBMETADATA>, 8
        @DefProto DllImport, RegisterClipboardFormatA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
        @DefProto DllImport, RegisterClipboardFormatW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
        ifdef UNICODE
          RegisterClipboardFormat equ <RegisterClipboardFormatW>
        else
          RegisterClipboardFormat equ <RegisterClipboardFormatA>
        endif
        ; !UNICODE
        @DefProto DllImport, CountClipboardFormats, WIN_STD_CALL_CONV,, <>, 0
        @DefProto DllImport, EnumClipboardFormats, WIN_STD_CALL_CONV,, <:UINT>, 4
        @DefProto DllImport, GetClipboardFormatNameA, WIN_STD_CALL_CONV,, <:UINT, :LPSTR, :SDWORD>, 12
        @DefProto DllImport, GetClipboardFormatNameW, WIN_STD_CALL_CONV,, <:UINT, :LPWSTR, :SDWORD>, 12
        ifdef UNICODE
          GetClipboardFormatName equ <GetClipboardFormatNameW>
        else
          GetClipboardFormatName equ <GetClipboardFormatNameA>
        endif
        ; !UNICODE
        @DefProto DllImport, EmptyClipboard, WIN_STD_CALL_CONV,, <>, 0
        @DefProto DllImport, IsClipboardFormatAvailable, WIN_STD_CALL_CONV,, <:UINT>, 4
        @DefProto DllImport, GetPriorityClipboardFormat, WIN_STD_CALL_CONV,, <:ptr UINT, :SDWORD>, 8
        @DefProto DllImport, GetOpenClipboardWindow, WIN_STD_CALL_CONV,, <>, 0
        if (WINVER ge 0600h)
          @DefProto DllImport, AddClipboardFormatListener, WIN_STD_CALL_CONV,, <:HWND>, 4
          @DefProto DllImport, RemoveClipboardFormatListener, WIN_STD_CALL_CONV,, <:HWND>, 4
          @DefProto DllImport, GetUpdatedClipboardFormats, WIN_STD_CALL_CONV,, <:PUINT, :UINT, :PUINT>, 12
          ;* WINVER >= 0x0600 *
        endif
        ;* !NOCLIPBOARD *
      endif
      ;*
      ;* Character Translation Routines
      ;*
      @DefProto DllImport, CharToOemA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPSTR>, 8
      @DefProto DllImport, CharToOemW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPSTR>, 8
      ifdef UNICODE
        CharToOem equ <CharToOemW>
      else
        CharToOem equ <CharToOemA>
      endif
      ; !UNICODE
      @DefProto DllImport, OemToCharA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPSTR>, 8
      @DefProto DllImport, OemToCharW, WIN_STD_CALL_CONV,, <:LPCSTR, :LPWSTR>, 8
      ifdef UNICODE
        OemToChar equ <OemToCharW>
      else
        OemToChar equ <OemToCharA>
      endif
      ; !UNICODE
      @DefProto DllImport, CharToOemBuffA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPSTR, :DWORD>, 12
      @DefProto DllImport, CharToOemBuffW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPSTR, :DWORD>, 12
      ifdef UNICODE
        CharToOemBuff equ <CharToOemBuffW>
      else
        CharToOemBuff equ <CharToOemBuffA>
      endif
      ; !UNICODE
      @DefProto DllImport, OemToCharBuffA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPSTR, :DWORD>, 12
      @DefProto DllImport, OemToCharBuffW, WIN_STD_CALL_CONV,, <:LPCSTR, :LPWSTR, :DWORD>, 12
      ifdef UNICODE
        OemToCharBuff equ <OemToCharBuffW>
      else
        OemToCharBuff equ <OemToCharBuffA>
      endif
      ; !UNICODE
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, CharUpperA, WIN_STD_CALL_CONV,, <:LPSTR>, 4
      @DefProto DllImport, CharUpperW, WIN_STD_CALL_CONV,, <:LPWSTR>, 4
      ifdef UNICODE
        CharUpper equ <CharUpperW>
      else
        CharUpper equ <CharUpperA>
      endif
      ; !UNICODE
      @DefProto DllImport, CharUpperBuffA, WIN_STD_CALL_CONV,, <:LPSTR, :DWORD>, 8
      @DefProto DllImport, CharUpperBuffW, WIN_STD_CALL_CONV,, <:LPWSTR, :DWORD>, 8
      ifdef UNICODE
        CharUpperBuff equ <CharUpperBuffW>
      else
        CharUpperBuff equ <CharUpperBuffA>
      endif
      ; !UNICODE
      @DefProto DllImport, CharLowerA, WIN_STD_CALL_CONV,, <:LPSTR>, 4
      @DefProto DllImport, CharLowerW, WIN_STD_CALL_CONV,, <:LPWSTR>, 4
      ifdef UNICODE
        CharLower equ <CharLowerW>
      else
        CharLower equ <CharLowerA>
      endif
      ; !UNICODE
      @DefProto DllImport, CharLowerBuffA, WIN_STD_CALL_CONV,, <:LPSTR, :DWORD>, 8
      @DefProto DllImport, CharLowerBuffW, WIN_STD_CALL_CONV,, <:LPWSTR, :DWORD>, 8
      ifdef UNICODE
        CharLowerBuff equ <CharLowerBuffW>
      else
        CharLowerBuff equ <CharLowerBuffA>
      endif
      ; !UNICODE
      @DefProto DllImport, CharNextA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
      @DefProto DllImport, CharNextW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
      ifdef UNICODE
        CharNext equ <CharNextW>
      else
        CharNext equ <CharNextA>
      endif
      ; !UNICODE
      @DefProto DllImport, CharPrevA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR>, 8
      @DefProto DllImport, CharPrevW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR>, 8
      ifdef UNICODE
        CharPrev equ <CharPrevW>
      else
        CharPrev equ <CharPrevA>
      endif
      ; !UNICODE
      if (WINVER ge 0400h)
        @DefProto DllImport, CharNextExA, WIN_STD_CALL_CONV,, <:WORD, :LPCSTR, :DWORD>, 12
        @DefProto DllImport, CharPrevExA, WIN_STD_CALL_CONV,, <:WORD, :LPCSTR, :LPCSTR, :DWORD>, 16
        ;* WINVER >= 0x0400 *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
    endif
    ;*
    ;* Compatibility defines for character translation routines
    ;*
    AnsiToOem equ <CharToOemA>
    OemToAnsi equ <OemToCharA>
    AnsiToOemBuff equ <CharToOemBuffA>
    OemToAnsiBuff equ <OemToCharBuffA>
    AnsiUpper equ <CharUpperA>
    AnsiUpperBuff equ <CharUpperBuffA>
    AnsiLower equ <CharLowerA>
    AnsiLowerBuff equ <CharLowerBuffA>
    AnsiNext equ <CharNextA>
    AnsiPrev equ <CharPrevA>
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      ifndef NOLANGUAGE
        ;*
        ;* Language dependent Routines
        ;*
        @DefProto DllImport, IsCharAlphaA, WIN_STD_CALL_CONV,, <:CHAR>, 4
        @DefProto DllImport, IsCharAlphaW, WIN_STD_CALL_CONV,, <:WCHAR>, 4
        ifdef UNICODE
          IsCharAlpha equ <IsCharAlphaW>
        else
          IsCharAlpha equ <IsCharAlphaA>
        endif
        ; !UNICODE
        @DefProto DllImport, IsCharAlphaNumericA, WIN_STD_CALL_CONV,, <:CHAR>, 4
        @DefProto DllImport, IsCharAlphaNumericW, WIN_STD_CALL_CONV,, <:WCHAR>, 4
        ifdef UNICODE
          IsCharAlphaNumeric equ <IsCharAlphaNumericW>
        else
          IsCharAlphaNumeric equ <IsCharAlphaNumericA>
        endif
        ; !UNICODE
        @DefProto DllImport, IsCharUpperA, WIN_STD_CALL_CONV,, <:CHAR>, 4
        @DefProto DllImport, IsCharUpperW, WIN_STD_CALL_CONV,, <:WCHAR>, 4
        ifdef UNICODE
          IsCharUpper equ <IsCharUpperW>
        else
          IsCharUpper equ <IsCharUpperA>
        endif
        ; !UNICODE
        @DefProto DllImport, IsCharLowerA, WIN_STD_CALL_CONV,, <:CHAR>, 4
        @DefProto DllImport, IsCharLowerW, WIN_STD_CALL_CONV,, <:WCHAR>, 4
        ifdef UNICODE
          IsCharLower equ <IsCharLowerW>
        else
          IsCharLower equ <IsCharLowerA>
        endif
        ; !UNICODE
        ;* !NOLANGUAGE *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, SetFocus, WIN_STD_CALL_CONV,, <:HWND>, 4
      @DefProto DllImport, GetActiveWindow, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, GetFocus, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, GetKBCodePage, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, GetKeyState, WIN_STD_CALL_CONV,, <:SDWORD>, 4
      @DefProto DllImport, GetAsyncKeyState, WIN_STD_CALL_CONV,, <:SDWORD>, 4
      @DefProto DllImport, GetKeyboardState, WIN_STD_CALL_CONV,, <:PBYTE>, 4
      @DefProto DllImport, SetKeyboardState, WIN_STD_CALL_CONV,, <:LPBYTE>, 4
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PC_APP)
      @DefProto DllImport, GetKeyNameTextA, WIN_STD_CALL_CONV,, <:LONG, :LPSTR, :SDWORD>, 12
      @DefProto DllImport, GetKeyNameTextW, WIN_STD_CALL_CONV,, <:LONG, :LPWSTR, :SDWORD>, 12
      ifdef UNICODE
        GetKeyNameText equ <GetKeyNameTextW>
      else
        GetKeyNameText equ <GetKeyNameTextA>
      endif
      ; !UNICODE
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_PC_APP) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, GetKeyboardType, WIN_STD_CALL_CONV,, <:SDWORD>, 4
      @DefProto DllImport, ToAscii, WIN_STD_CALL_CONV,, <:UINT, :UINT, :ptr BYTE, :LPWORD, :UINT>, 20
      if (WINVER ge 0400h)
        @DefProto DllImport, ToAsciiEx, WIN_STD_CALL_CONV,, <:UINT, :UINT, :ptr BYTE, :LPWORD, :UINT, :HKL>, 24
        ;* WINVER >= 0x0400 *
      endif
      @DefProto DllImport, ToUnicode, WIN_STD_CALL_CONV,, <:UINT, :UINT, :ptr BYTE, :LPWSTR, :SDWORD, :UINT>, 24
      @DefProto DllImport, OemKeyScan, WIN_STD_CALL_CONV,, <:WORD>, 4
      @DefProto DllImport, VkKeyScanA, WIN_STD_CALL_CONV,, <:CHAR>, 4
      @DefProto DllImport, VkKeyScanW, WIN_STD_CALL_CONV,, <:WCHAR>, 4
      ifdef UNICODE
        VkKeyScan equ <VkKeyScanW>
      else
        VkKeyScan equ <VkKeyScanA>
      endif
      ; !UNICODE
      if (WINVER ge 0400h)
        @DefProto DllImport, VkKeyScanExA, WIN_STD_CALL_CONV,, <:CHAR, :HKL>, 8
        @DefProto DllImport, VkKeyScanExW, WIN_STD_CALL_CONV,, <:WCHAR, :HKL>, 8
        ifdef UNICODE
          VkKeyScanEx equ <VkKeyScanExW>
        else
          VkKeyScanEx equ <VkKeyScanExA>
        endif
        ; !UNICODE
        ;* WINVER >= 0x0400 *
      endif
      KEYEVENTF_EXTENDEDKEY equ 0001h
      KEYEVENTF_KEYUP equ 0002h
      if (_WIN32_WINNT ge 0500h)
        KEYEVENTF_UNICODE equ 0004h
        KEYEVENTF_SCANCODE equ 0008h
        ;* _WIN32_WINNT >= 0x0500 *
      endif
      @DefProto DllImport, keybd_event, WIN_STD_CALL_CONV,, <:BYTE, :BYTE, :DWORD, :ULONG_PTR>, 16
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ;* mouse move *
    MOUSEEVENTF_MOVE equ 0001h
    ;* left button down *
    MOUSEEVENTF_LEFTDOWN equ 0002h
    ;* left button up *
    MOUSEEVENTF_LEFTUP equ 0004h
    ;* right button down *
    MOUSEEVENTF_RIGHTDOWN equ 0008h
    ;* right button up *
    MOUSEEVENTF_RIGHTUP equ 0010h
    ;* middle button down *
    MOUSEEVENTF_MIDDLEDOWN equ 0020h
    ;* middle button up *
    MOUSEEVENTF_MIDDLEUP equ 0040h
    ;* x button down *
    MOUSEEVENTF_XDOWN equ 0080h
    ;* x button down *
    MOUSEEVENTF_XUP equ 0100h
    ;* wheel button rolled *
    MOUSEEVENTF_WHEEL equ 0800h
    if (_WIN32_WINNT ge 0600h)
      ;* hwheel button rolled *
      MOUSEEVENTF_HWHEEL equ 01000h
    endif
    if (WINVER ge 0600h)
      ;* do not coalesce mouse moves *
      MOUSEEVENTF_MOVE_NOCOALESCE equ 2000h
      ;* WINVER >= 0x0600 *
    endif
    ;* map to entire virtual desktop *
    MOUSEEVENTF_VIRTUALDESK equ 4000h
    ;* absolute move *
    MOUSEEVENTF_ABSOLUTE equ 8000h
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, mouse_event, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :DWORD, :DWORD, :ULONG_PTR>, 20
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if (_WIN32_WINNT gt 0400h)
      MOUSEINPUT struct
        dx_ SDWORD ?
        dy SDWORD ?
        mouseData DWORD ?
        dwFlags DWORD ?
        time DWORD ?
        dwExtraInfo XWORD ?
      MOUSEINPUT ends
      tagMOUSEINPUT typedef MOUSEINPUT
      PMOUSEINPUT typedef ptr MOUSEINPUT
      LPMOUSEINPUT typedef ptr MOUSEINPUT
      KEYBDINPUT struct
        wVk WORD ?
        wScan WORD ?
        dwFlags DWORD ?
        time DWORD ?
        ;*
        ;* When dwFlags has KEYEVENTF_SYSTEMINJECTION specified this field may carry
        ;* KEY_UNICODE_SEQUENCE_ITEM or KEY_UNICODE_SEQUENCE_END which are used by InputService
        ;* to distinguish injected unicode sequences. Those flags are stored in low word.
        ;* When dwFlags has KEYEVENTF_ATTRIBUTED_INPUT specified this field carries in its high word
        ;* ID of attributes associated with injected input. This ID is assigned by InputService and
        ;* recognized only by it.
        ;* For all other usage scenarios please refer to official documentation.
        ;*
        dwExtraInfo XWORD ?
      KEYBDINPUT ends
      tagKEYBDINPUT typedef KEYBDINPUT
      PKEYBDINPUT typedef ptr KEYBDINPUT
      LPKEYBDINPUT typedef ptr KEYBDINPUT
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        HARDWAREINPUT struct
          uMsg DWORD ?
          wParamL WORD ?
          wParamH WORD ?
        HARDWAREINPUT ends
        tagHARDWAREINPUT typedef HARDWAREINPUT
        PHARDWAREINPUT typedef ptr HARDWAREINPUT
        LPHARDWAREINPUT typedef ptr HARDWAREINPUT
        INPUT_MOUSE equ 0
        INPUT_KEYBOARD equ 1
        INPUT_HARDWARE equ 2
        INPUT struct
          type_ DWORD ?
          union
            mi MOUSEINPUT <>
            ki KEYBDINPUT <>
            hi HARDWAREINPUT <>
          ends
        INPUT ends
        tagINPUT typedef INPUT
        PINPUT typedef ptr INPUT
        LPINPUT typedef ptr INPUT
        @DefProto DllImport, SendInput, WIN_STD_CALL_CONV,, <:UINT, :LPINPUT, :SDWORD>, 12
        ; array of inputs
        ; sizeof(INPUT)
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
    endif
    ; (_WIN32_WINNT > 0x0400)
    if (WINVER ge 0601h)
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        ;*
        ;* Touch Input defines and functions
        ;*
        ;*
        ;* Touch input handle
        ;*
        DECLARE_HANDLE HTOUCHINPUT
        TOUCHINPUT struct
          x SDWORD ?
          y SDWORD ?
          hSource HANDLE ?
          dwID DWORD ?
          dwFlags DWORD ?
          dwMask DWORD ?
          dwTime DWORD ?
          dwExtraInfo XWORD ?
          cxContact DWORD ?
          cyContact DWORD ?
        TOUCHINPUT ends
        tagTOUCHINPUT typedef TOUCHINPUT
        PTOUCHINPUT typedef ptr TOUCHINPUT
        PCTOUCHINPUT typedef ptr TOUCHINPUT
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;*
      ;* Conversion of touch input coordinates to pixels
      ;*
      TOUCH_COORD_TO_PIXEL macro l
        exitm <((l) / 100)>
      endm
      ;*
      ;* Touch input flag values (TOUCHINPUT.dwFlags)
      ;*
      TOUCHEVENTF_MOVE equ 0001h
      TOUCHEVENTF_DOWN equ 0002h
      TOUCHEVENTF_UP equ 0004h
      TOUCHEVENTF_INRANGE equ 0008h
      TOUCHEVENTF_PRIMARY equ 0010h
      TOUCHEVENTF_NOCOALESCE equ 0020h
      TOUCHEVENTF_PEN equ 0040h
      TOUCHEVENTF_PALM equ 0080h
      ;*
      ;* Touch input mask values (TOUCHINPUT.dwMask)
      ;*
      TOUCHINPUTMASKF_TIMEFROMSYSTEM equ 0001h; the dwTime field contains a system generated value

      TOUCHINPUTMASKF_EXTRAINFO equ 0002h; the dwExtraInfo field is valid

      TOUCHINPUTMASKF_CONTACTAREA equ 0004h; the cxContact and cyContact fields are valid

      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, GetTouchInputInfo, WIN_STD_CALL_CONV,, <:HTOUCHINPUT, :UINT, :PTOUCHINPUT, :SDWORD>, 16
        ; array of touch inputs
        ; sizeof(TOUCHINPUT)
        @DefProto DllImport, CloseTouchInputHandle, WIN_STD_CALL_CONV,, <:HTOUCHINPUT>, 4
        ; input event handle; from touch message lParam
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;*
      ;* RegisterTouchWindow flag values
      ;*
      TWF_FINETOUCH equ (00000001h)
      TWF_WANTPALM equ (00000002h)
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, RegisterTouchWindow, WIN_STD_CALL_CONV,, <:HWND, :ULONG>, 8
        @DefProto DllImport, UnregisterTouchWindow, WIN_STD_CALL_CONV,, <:HWND>, 4
        @DefProto DllImport, IsTouchWindow, WIN_STD_CALL_CONV,, <:HWND, :PULONG>, 8
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;* WINVER >= 0x0601 *
    endif
    if (WINVER ge 0602h)
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        POINTER_STRUCTURES equ <>
        tagPOINTER_INPUT_TYPE typedef SDWORD
        PT_POINTER equ 1
        ; Generic pointer
        PT_TOUCH equ 2
        ; Touch
        PT_PEN equ 3
        ; Pen
        PT_MOUSE equ 4
        ; Mouse
        if (WINVER ge 0603h)
          PT_TOUCHPAD equ 5
          ; Touchpad
          ;* WINVER >= 0x0603 *
        endif

        POINTER_INPUT_TYPE typedef DWORD
        POINTER_FLAGS typedef UINT32
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      POINTER_FLAG_NONE equ 00000000h; Default

      POINTER_FLAG_NEW equ 00000001h; New pointer

      POINTER_FLAG_INRANGE equ 00000002h; Pointer has not departed

      POINTER_FLAG_INCONTACT equ 00000004h; Pointer is in contact

      POINTER_FLAG_FIRSTBUTTON equ 00000010h; Primary action

      POINTER_FLAG_SECONDBUTTON equ 00000020h; Secondary action

      POINTER_FLAG_THIRDBUTTON equ 00000040h; Third button

      POINTER_FLAG_FOURTHBUTTON equ 00000080h; Fourth button

      POINTER_FLAG_FIFTHBUTTON equ 00000100h; Fifth button

      POINTER_FLAG_PRIMARY equ 00002000h; Pointer is primary for system

      POINTER_FLAG_CONFIDENCE equ 00004000h; Pointer is considered unlikely to be accidental

      POINTER_FLAG_CANCELED equ 00008000h; Pointer is departing in an abnormal manner

      POINTER_FLAG_DOWN equ 00010000h; Pointer transitioned to down state (made contact)

      POINTER_FLAG_UPDATE equ 00020000h; Pointer update

      POINTER_FLAG_UP equ 00040000h; Pointer transitioned from down state (broke contact)

      POINTER_FLAG_WHEEL equ 00080000h; Vertical wheel

      POINTER_FLAG_HWHEEL equ 00100000h; Horizontal wheel

      POINTER_FLAG_CAPTURECHANGED equ 00200000h; Lost capture

      POINTER_FLAG_HASTRANSFORM equ 00400000h; Input has a transform associated with it

      ;*
      ;* Pointer info key states defintions.
      ;*
      POINTER_MOD_SHIFT equ (0004h); Shift key is held down.

      POINTER_MOD_CTRL equ (0008h); Ctrl key is held down.

      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        POINTER_BUTTON_CHANGE_TYPE typedef SDWORD
        POINTER_CHANGE_NONE equ 0
        POINTER_CHANGE_FIRSTBUTTON_DOWN equ 1
        POINTER_CHANGE_FIRSTBUTTON_UP equ 2
        POINTER_CHANGE_SECONDBUTTON_DOWN equ 3
        POINTER_CHANGE_SECONDBUTTON_UP equ 4
        POINTER_CHANGE_THIRDBUTTON_DOWN equ 5
        POINTER_CHANGE_THIRDBUTTON_UP equ 6
        POINTER_CHANGE_FOURTHBUTTON_DOWN equ 7
        POINTER_CHANGE_FOURTHBUTTON_UP equ 8
        POINTER_CHANGE_FIFTHBUTTON_DOWN equ 9
        POINTER_CHANGE_FIFTHBUTTON_UP equ 10
        tagPOINTER_BUTTON_CHANGE_TYPE typedef POINTER_BUTTON_CHANGE_TYPE

        POINTER_INFO struct
          pointerType POINTER_INPUT_TYPE ?
          pointerId DWORD ?
          frameId DWORD ?
          pointerFlags POINTER_FLAGS ?
          sourceDevice HANDLE ?
          hwndTarget HWND ?
          ptPixelLocation POINT <>
          ptHimetricLocation POINT <>
          ptPixelLocationRaw POINT <>
          ptHimetricLocationRaw POINT <>
          dwTime DWORD ?
          historyCount DWORD ?
          InputData SDWORD ?
          dwKeyStates DWORD ?
          PerformanceCount QWORD ?
          ButtonChangeType POINTER_BUTTON_CHANGE_TYPE ?
        POINTER_INFO ends
        tagPOINTER_INFO typedef POINTER_INFO
        TOUCH_FLAGS typedef UINT32
        TOUCH_FLAG_NONE equ 00000000h; Default

        TOUCH_MASK typedef UINT32
        TOUCH_MASK_NONE equ 00000000h; Default - none of the optional fields are valid

        TOUCH_MASK_CONTACTAREA equ 00000001h; The rcContact field is valid

        TOUCH_MASK_ORIENTATION equ 00000002h; The orientation field is valid

        TOUCH_MASK_PRESSURE equ 00000004h; The pressure field is valid

        POINTER_TOUCH_INFO struct
          pointerInfo POINTER_INFO <>
          touchFlags TOUCH_FLAGS ?
          touchMask TOUCH_MASK ?
          rcContact RECT <>
          rcContactRaw RECT <>
          orientation DWORD ?
          pressure DWORD ?
        POINTER_TOUCH_INFO ends
        tagPOINTER_TOUCH_INFO typedef POINTER_TOUCH_INFO
        PEN_FLAGS typedef UINT32
        PEN_FLAG_NONE equ 00000000h; Default

        PEN_FLAG_BARREL equ 00000001h; The barrel button is pressed

        PEN_FLAG_INVERTED equ 00000002h; The pen is inverted

        PEN_FLAG_ERASER equ 00000004h; The eraser button is pressed

        PEN_MASK typedef UINT32
        PEN_MASK_NONE equ 00000000h; Default - none of the optional fields are valid

        PEN_MASK_PRESSURE equ 00000001h; The pressure field is valid

        PEN_MASK_ROTATION equ 00000002h; The rotation field is valid

        PEN_MASK_TILT_X equ 00000004h; The tiltX field is valid

        PEN_MASK_TILT_Y equ 00000008h; The tiltY field is valid

        POINTER_PEN_INFO struct
          pointerInfo POINTER_INFO <>
          penFlags PEN_FLAGS ?
          penMask PEN_MASK ?
          pressure DWORD ?
          rotation DWORD ?
          tiltX SDWORD ?
          tiltY SDWORD ?
        POINTER_PEN_INFO ends
        tagPOINTER_PEN_INFO typedef POINTER_PEN_INFO
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;*
      ;* Flags that appear in pointer input message parameters
      ;*
      POINTER_MESSAGE_FLAG_NEW equ 00000001h; New pointer

      POINTER_MESSAGE_FLAG_INRANGE equ 00000002h; Pointer has not departed

      POINTER_MESSAGE_FLAG_INCONTACT equ 00000004h; Pointer is in contact

      POINTER_MESSAGE_FLAG_FIRSTBUTTON equ 00000010h; Primary action

      POINTER_MESSAGE_FLAG_SECONDBUTTON equ 00000020h; Secondary action

      POINTER_MESSAGE_FLAG_THIRDBUTTON equ 00000040h; Third button

      POINTER_MESSAGE_FLAG_FOURTHBUTTON equ 00000080h; Fourth button

      POINTER_MESSAGE_FLAG_FIFTHBUTTON equ 00000100h; Fifth button

      POINTER_MESSAGE_FLAG_PRIMARY equ 00002000h; Pointer is primary

      POINTER_MESSAGE_FLAG_CONFIDENCE equ 00004000h; Pointer is considered unlikely to be accidental

      POINTER_MESSAGE_FLAG_CANCELED equ 00008000h; Pointer is departing in an abnormal manner

      ;*
      ;* Macros to retrieve information from pointer input message parameters
      ;*
      GET_POINTERID_WPARAM macro wParam
        exitm <(LOWORD(wParam))>
      endm
      IS_POINTER_FLAG_SET_WPARAM macro wParam, flag
        exitm <((HIWORD(wParam) and (flag)) == (flag))>
      endm
      IS_POINTER_NEW_WPARAM macro wParam
        exitm <IS_POINTER_FLAG_SET_WPARAM(wParam, POINTER_MESSAGE_FLAG_NEW)>
      endm
      IS_POINTER_INRANGE_WPARAM macro wParam
        exitm <IS_POINTER_FLAG_SET_WPARAM(wParam, POINTER_MESSAGE_FLAG_INRANGE)>
      endm
      IS_POINTER_INCONTACT_WPARAM macro wParam
        exitm <IS_POINTER_FLAG_SET_WPARAM(wParam, POINTER_MESSAGE_FLAG_INCONTACT)>
      endm
      IS_POINTER_FIRSTBUTTON_WPARAM macro wParam
        exitm <IS_POINTER_FLAG_SET_WPARAM(wParam, POINTER_MESSAGE_FLAG_FIRSTBUTTON)>
      endm
      IS_POINTER_SECONDBUTTON_WPARAM macro wParam
        exitm <IS_POINTER_FLAG_SET_WPARAM(wParam, POINTER_MESSAGE_FLAG_SECONDBUTTON)>
      endm
      IS_POINTER_THIRDBUTTON_WPARAM macro wParam
        exitm <IS_POINTER_FLAG_SET_WPARAM(wParam, POINTER_MESSAGE_FLAG_THIRDBUTTON)>
      endm
      IS_POINTER_FOURTHBUTTON_WPARAM macro wParam
        exitm <IS_POINTER_FLAG_SET_WPARAM(wParam, POINTER_MESSAGE_FLAG_FOURTHBUTTON)>
      endm
      IS_POINTER_FIFTHBUTTON_WPARAM macro wParam
        exitm <IS_POINTER_FLAG_SET_WPARAM(wParam, POINTER_MESSAGE_FLAG_FIFTHBUTTON)>
      endm
      IS_POINTER_PRIMARY_WPARAM macro wParam
        exitm <IS_POINTER_FLAG_SET_WPARAM(wParam, POINTER_MESSAGE_FLAG_PRIMARY)>
      endm
      HAS_POINTER_CONFIDENCE_WPARAM macro wParam
        exitm <IS_POINTER_FLAG_SET_WPARAM(wParam, POINTER_MESSAGE_FLAG_CONFIDENCE)>
      endm
      IS_POINTER_CANCELED_WPARAM macro wParam
        exitm <IS_POINTER_FLAG_SET_WPARAM(wParam, POINTER_MESSAGE_FLAG_CANCELED)>
      endm
      ;*
      ;* WM_POINTERACTIVATE return codes
      ;*
      PA_ACTIVATE equ <MA_ACTIVATE>
      PA_NOACTIVATE equ <MA_NOACTIVATE>
      MAX_TOUCH_COUNT equ 256
      TOUCH_FEEDBACK_DEFAULT equ 1h
      TOUCH_FEEDBACK_INDIRECT equ 2h
      TOUCH_FEEDBACK_NONE equ 3h
      POINTER_FEEDBACK_MODE typedef SDWORD
      POINTER_FEEDBACK_DEFAULT equ 1
      ; The injected pointer input feedback may get suppressed by the end-user settings in the Pen and Touch control panel.
      POINTER_FEEDBACK_INDIRECT equ 2
      ; The injected pointer input feedback overrides the end-user settings in the Pen and Touch control panel.
      POINTER_FEEDBACK_NONE equ 3
      ; No touch visualizations.

      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, InitializeTouchInjection, WIN_STD_CALL_CONV,, <:UINT32, :DWORD>, 8
        @DefProto DllImport, InjectTouchInput, WIN_STD_CALL_CONV,, <:UINT32, :ptr POINTER_TOUCH_INFO>, 8
        USAGE_PROPERTIES struct
          level WORD ?
          page_ WORD ?
          usage WORD ?
          logicalMinimum SDWORD ?
          logicalMaximum SDWORD ?
          unit WORD ?
          exponent WORD ?
          count BYTE ?
          physicalMinimum SDWORD ?
          physicalMaximum SDWORD ?
        USAGE_PROPERTIES ends
        tagUSAGE_PROPERTIES typedef USAGE_PROPERTIES
        PUSAGE_PROPERTIES typedef ptr USAGE_PROPERTIES
        POINTER_TYPE_INFO struct
          type_ POINTER_INPUT_TYPE ?
          union
            touchInfo POINTER_TOUCH_INFO <>
            penInfo POINTER_PEN_INFO <>
          ends
        POINTER_TYPE_INFO ends
        tagPOINTER_TYPE_INFO typedef POINTER_TYPE_INFO
        PPOINTER_TYPE_INFO typedef ptr POINTER_TYPE_INFO
        INPUT_INJECTION_VALUE struct
          page_ WORD ?
          usage WORD ?
          value SDWORD ?
          index WORD ?
        INPUT_INJECTION_VALUE ends
        tagINPUT_INJECTION_VALUE typedef INPUT_INJECTION_VALUE
        PINPUT_INJECTION_VALUE typedef ptr INPUT_INJECTION_VALUE
        @DefProto DllImport, GetPointerType, WIN_STD_CALL_CONV,, <:UINT32, :ptr POINTER_INPUT_TYPE>, 8
        @DefProto DllImport, GetPointerCursorId, WIN_STD_CALL_CONV,, <:UINT32, :ptr UINT32>, 8
        @DefProto DllImport, GetPointerInfo, WIN_STD_CALL_CONV,, <:UINT32, :ptr POINTER_INFO>, 8
        @DefProto DllImport, GetPointerInfoHistory, WIN_STD_CALL_CONV,, <:UINT32, :ptr UINT32, :ptr POINTER_INFO>, 12
        @DefProto DllImport, GetPointerFrameInfo, WIN_STD_CALL_CONV,, <:UINT32, :ptr UINT32, :ptr POINTER_INFO>, 12
        @DefProto DllImport, GetPointerFrameInfoHistory, WIN_STD_CALL_CONV,, <:UINT32, :ptr UINT32, :ptr UINT32, :ptr POINTER_INFO>, 16
        @DefProto DllImport, GetPointerTouchInfo, WIN_STD_CALL_CONV,, <:UINT32, :ptr POINTER_TOUCH_INFO>, 8
        @DefProto DllImport, GetPointerTouchInfoHistory, WIN_STD_CALL_CONV,, <:UINT32, :ptr UINT32, :ptr POINTER_TOUCH_INFO>, 12
        @DefProto DllImport, GetPointerFrameTouchInfo, WIN_STD_CALL_CONV,, <:UINT32, :ptr UINT32, :ptr POINTER_TOUCH_INFO>, 12
        @DefProto DllImport, GetPointerFrameTouchInfoHistory, WIN_STD_CALL_CONV,, <:UINT32, :ptr UINT32, :ptr UINT32, :ptr POINTER_TOUCH_INFO>, 16
        @DefProto DllImport, GetPointerPenInfo, WIN_STD_CALL_CONV,, <:UINT32, :ptr POINTER_PEN_INFO>, 8
        @DefProto DllImport, GetPointerPenInfoHistory, WIN_STD_CALL_CONV,, <:UINT32, :ptr UINT32, :ptr POINTER_PEN_INFO>, 12
        @DefProto DllImport, GetPointerFramePenInfo, WIN_STD_CALL_CONV,, <:UINT32, :ptr UINT32, :ptr POINTER_PEN_INFO>, 12
        @DefProto DllImport, GetPointerFramePenInfoHistory, WIN_STD_CALL_CONV,, <:UINT32, :ptr UINT32, :ptr UINT32, :ptr POINTER_PEN_INFO>, 16
        @DefProto DllImport, SkipPointerFrameMessages, WIN_STD_CALL_CONV,, <:UINT32>, 4
        @DefProto DllImport, RegisterPointerInputTarget, WIN_STD_CALL_CONV,, <:HWND, :POINTER_INPUT_TYPE>, 8
        @DefProto DllImport, UnregisterPointerInputTarget, WIN_STD_CALL_CONV,, <:HWND, :POINTER_INPUT_TYPE>, 8
        @DefProto DllImport, RegisterPointerInputTargetEx, WIN_STD_CALL_CONV,, <:HWND, :POINTER_INPUT_TYPE, :BOOL>, 12
        @DefProto DllImport, UnregisterPointerInputTargetEx, WIN_STD_CALL_CONV,, <:HWND, :POINTER_INPUT_TYPE>, 8
        if (NTDDI_VERSION ge NTDDI_WIN10_RS5)
          DECLARE_HANDLE HSYNTHETICPOINTERDEVICE
          @DefProto DllImport, CreateSyntheticPointerDevice, WIN_STD_CALL_CONV,, <:POINTER_INPUT_TYPE, :ULONG, :POINTER_FEEDBACK_MODE>, 12
          @DefProto DllImport, InjectSyntheticPointerInput, WIN_STD_CALL_CONV,, <:HSYNTHETICPOINTERDEVICE, :ptr POINTER_TYPE_INFO, :UINT32>, 12
          @DefProto DllImport, DestroySyntheticPointerDevice, WIN_STD_CALL_CONV,, <:HSYNTHETICPOINTERDEVICE>, 4
        endif
        ; NTDDI_VERSION >= NTDDI_WIN10_RS5
        @DefProto DllImport, EnableMouseInPointer, WIN_STD_CALL_CONV,, <:BOOL>, 4
        @DefProto DllImport, IsMouseInPointerEnabled, WIN_STD_CALL_CONV,, <>, 0
        if WDK_NTDDI_VERSION ge NTDDI_WIN10_RS3
          @DefProto DllImport, EnableMouseInPointerForThread, WIN_STD_CALL_CONV,, <>, 0
        endif
        TOUCH_HIT_TESTING_DEFAULT equ 0h
        TOUCH_HIT_TESTING_CLIENT equ 1h
        TOUCH_HIT_TESTING_NONE equ 2h
        @DefProto DllImport, RegisterTouchHitTestingWindow, WIN_STD_CALL_CONV,, <:HWND, :ULONG>, 8
        TOUCH_HIT_TESTING_PROXIMITY_EVALUATION struct
          score UINT16 ?
          adjustedPoint POINT <>
        TOUCH_HIT_TESTING_PROXIMITY_EVALUATION ends
        tagTOUCH_HIT_TESTING_PROXIMITY_EVALUATION typedef TOUCH_HIT_TESTING_PROXIMITY_EVALUATION
        PTOUCH_HIT_TESTING_PROXIMITY_EVALUATION typedef ptr TOUCH_HIT_TESTING_PROXIMITY_EVALUATION
        ;*
        ;* WM_TOUCHHITTESTING structure
        ;*
        TOUCH_HIT_TESTING_INPUT struct
          pointerId DWORD ?
          point POINT <>
          boundingBox RECT <>
          nonOccludedBoundingBox RECT <>
          orientation DWORD ?
        TOUCH_HIT_TESTING_INPUT ends
        tagTOUCH_HIT_TESTING_INPUT typedef TOUCH_HIT_TESTING_INPUT
        PTOUCH_HIT_TESTING_INPUT typedef ptr TOUCH_HIT_TESTING_INPUT
        TOUCH_HIT_TESTING_PROXIMITY_CLOSEST equ 0h
        TOUCH_HIT_TESTING_PROXIMITY_FARTHEST equ 0FFFh
        @DefProto DllImport, EvaluateProximityToRect, WIN_STD_CALL_CONV,, <:ptr RECT, :ptr TOUCH_HIT_TESTING_INPUT, :ptr TOUCH_HIT_TESTING_PROXIMITY_EVALUATION>, 12
        @DefProto DllImport, EvaluateProximityToPolygon, WIN_STD_CALL_CONV,, <:UINT32, :ptr POINT, :ptr TOUCH_HIT_TESTING_INPUT, :ptr TOUCH_HIT_TESTING_PROXIMITY_EVALUATION>, 16
        @DefProto DllImport, PackTouchHitTestingProximityEvaluation, WIN_STD_CALL_CONV,, <:ptr TOUCH_HIT_TESTING_INPUT, :ptr TOUCH_HIT_TESTING_PROXIMITY_EVALUATION>, 8
        FEEDBACK_TYPE typedef SDWORD
        FEEDBACK_TOUCH_CONTACTVISUALIZATION equ 1
        FEEDBACK_PEN_BARRELVISUALIZATION equ 2
        FEEDBACK_PEN_TAP equ 3
        FEEDBACK_PEN_DOUBLETAP equ 4
        FEEDBACK_PEN_PRESSANDHOLD equ 5
        FEEDBACK_PEN_RIGHTTAP equ 6
        FEEDBACK_TOUCH_TAP equ 7
        FEEDBACK_TOUCH_DOUBLETAP equ 8
        FEEDBACK_TOUCH_PRESSANDHOLD equ 9
        FEEDBACK_TOUCH_RIGHTTAP equ 10
        FEEDBACK_GESTURE_PRESSANDTAP equ 11
        FEEDBACK_MAX equ 0FFFFFFFFh
        tagFEEDBACK_TYPE typedef FEEDBACK_TYPE

        GWFS_INCLUDE_ANCESTORS equ 00000001h
        @DefProto DllImport, GetWindowFeedbackSetting, WIN_STD_CALL_CONV,, <:HWND, :FEEDBACK_TYPE, :DWORD, :ptr UINT32, :ptr VOID>, 20
        @DefProto DllImport, SetWindowFeedbackSetting, WIN_STD_CALL_CONV,, <:HWND, :FEEDBACK_TYPE, :DWORD, :UINT32, :ptr VOID>, 20
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;* WINVER >= 0x0602 *
    endif
    if (WINVER ge 0603h)
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        ;Disable warning C4201:nameless struct/union
        if _MSC_VER ge 1200
        endif
        INPUT_TRANSFORM struct
          union
            struct
              _11 REAL4 ?
              _12 REAL4 ?
              _13 REAL4 ?
              _14 REAL4 ?
              _21 REAL4 ?
              _22 REAL4 ?
              _23 REAL4 ?
              _24 REAL4 ?
              _31 REAL4 ?
              _32 REAL4 ?
              _33 REAL4 ?
              _34 REAL4 ?
              _41 REAL4 ?
              _42 REAL4 ?
              _43 REAL4 ?
              _44 REAL4 ?
            ends
            m REAL4 4 * 4 dup (?)
          ends
        INPUT_TRANSFORM ends
        tagINPUT_TRANSFORM typedef INPUT_TRANSFORM
        if _MSC_VER ge 1200
        endif
        @DefProto DllImport, GetPointerInputTransform, WIN_STD_CALL_CONV,, <:UINT32, :UINT32, :ptr INPUT_TRANSFORM>, 12
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;* WINVER >= 0x0603 *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PC_APP)
      if (_WIN32_WINNT ge 0500h)
        LASTINPUTINFO struct
          cbSize DWORD ?
          dwTime DWORD ?
        LASTINPUTINFO ends
        tagLASTINPUTINFO typedef LASTINPUTINFO
        PLASTINPUTINFO typedef ptr LASTINPUTINFO
        @DefProto DllImport, GetLastInputInfo, WIN_STD_CALL_CONV,, <:PLASTINPUTINFO>, 4
        ;* _WIN32_WINNT >= 0x0500 *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_PC_APP) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PC_APP)
      @DefProto DllImport, MapVirtualKeyA, WIN_STD_CALL_CONV,, <:UINT, :UINT>, 8
      @DefProto DllImport, MapVirtualKeyW, WIN_STD_CALL_CONV,, <:UINT, :UINT>, 8
      ifdef UNICODE
        MapVirtualKey equ <MapVirtualKeyW>
      else
        MapVirtualKey equ <MapVirtualKeyA>
      endif
      ; !UNICODE
      if (WINVER ge 0400h)
        @DefProto DllImport, MapVirtualKeyExA, WIN_STD_CALL_CONV,, <:UINT, :UINT, :HKL>, 12
        @DefProto DllImport, MapVirtualKeyExW, WIN_STD_CALL_CONV,, <:UINT, :UINT, :HKL>, 12
        ifdef UNICODE
          MapVirtualKeyEx equ <MapVirtualKeyExW>
        else
          MapVirtualKeyEx equ <MapVirtualKeyExA>
        endif
        ; !UNICODE
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_PC_APP) *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        MAPVK_VK_TO_VSC equ (0)
        MAPVK_VSC_TO_VK equ (1)
        MAPVK_VK_TO_CHAR equ (2)
        MAPVK_VSC_TO_VK_EX equ (3)
        ;* WINVER >= 0x0400 *
      endif
      if (WINVER ge 0600h)
        MAPVK_VK_TO_VSC_EX equ (4)
        ;* WINVER >= 0x0600 *
      endif
      @DefProto DllImport, GetInputState, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, GetQueueStatus, WIN_STD_CALL_CONV,, <:UINT>, 4
      @DefProto DllImport, GetCapture, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, SetCapture, WIN_STD_CALL_CONV,, <:HWND>, 4
      @DefProto DllImport, ReleaseCapture, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, MsgWaitForMultipleObjects, WIN_STD_CALL_CONV,, <:DWORD, :ptr HANDLE, :BOOL, :DWORD, :DWORD>, 20
      @DefProto DllImport, MsgWaitForMultipleObjectsEx, WIN_STD_CALL_CONV,, <:DWORD, :ptr HANDLE, :DWORD, :DWORD, :DWORD>, 20
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    MWMO_WAITALL equ 0001h
    MWMO_ALERTABLE equ 0002h
    MWMO_INPUTAVAILABLE equ 0004h
    ;*
    ;* Queue status flags for GetQueueStatus() and MsgWaitForMultipleObjects()
    ;*
    QS_KEY equ 0001h
    QS_MOUSEMOVE equ 0002h
    QS_MOUSEBUTTON equ 0004h
    QS_POSTMESSAGE equ 0008h
    QS_TIMER equ 0010h
    QS_PAINT equ 0020h
    QS_SENDMESSAGE equ 0040h
    QS_HOTKEY equ 0080h
    QS_ALLPOSTMESSAGE equ 0100h
    if (_WIN32_WINNT ge 0501h)
      QS_RAWINPUT equ 0400h
      ;* _WIN32_WINNT >= 0x0501 *
    endif
    if (_WIN32_WINNT ge 0602h)
      QS_TOUCH equ 0800h
      QS_POINTER equ 1000h
      ;* _WIN32_WINNT >= 0x0602 *
    endif
    QS_MOUSE equ <(QS_MOUSEMOVE or QS_MOUSEBUTTON)>
    if (_WIN32_WINNT ge 602h)
      QS_INPUT equ <(QS_MOUSE or QS_KEY or QS_RAWINPUT or QS_TOUCH or QS_POINTER)>
    else
      if (_WIN32_WINNT ge 0501h)
        QS_INPUT equ <(QS_MOUSE or QS_KEY or QS_RAWINPUT)>
      else
        QS_INPUT equ <(QS_MOUSE or QS_KEY)>
      endif
      ; (_WIN32_WINNT >= 0x0501)
    endif
    QS_ALLEVENTS equ <(QS_INPUT or QS_POSTMESSAGE or QS_TIMER or QS_PAINT or QS_HOTKEY)>
    QS_ALLINPUT equ <(QS_INPUT or QS_POSTMESSAGE or QS_TIMER or QS_PAINT or QS_HOTKEY or QS_SENDMESSAGE)>
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      USER_TIMER_MAXIMUM equ 7FFFFFFFh
      USER_TIMER_MINIMUM equ 0000000Ah
      ;*
      ;* Windows Functions
      ;*
      @DefProto DllImport, SetTimer, WIN_STD_CALL_CONV,, <:HWND, :UINT_PTR, :UINT, :TIMERPROC>, 16
      if (WINVER ge 0601h)
        TIMERV_DEFAULT_COALESCING equ (0)
        TIMERV_NO_COALESCING equ (0FFFFFFFFh)
        TIMERV_COALESCING_MIN equ (1)
        TIMERV_COALESCING_MAX equ (7FFFFFF5h)
        ;* WINVER >= 0x0601 *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      if (WINVER ge 0601h)
        @DefProto DllImport, SetCoalescableTimer, WIN_STD_CALL_CONV,, <:HWND, :UINT_PTR, :UINT, :TIMERPROC, :ULONG>, 20
        ;* WINVER >= 0x0601 *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, KillTimer, WIN_STD_CALL_CONV,, <:HWND, :UINT_PTR>, 8
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, IsWindowUnicode, WIN_STD_CALL_CONV,, <:HWND>, 4
      @DefProto DllImport, EnableWindow, WIN_STD_CALL_CONV,, <:HWND, :BOOL>, 8
      @DefProto DllImport, IsWindowEnabled, WIN_STD_CALL_CONV,, <:HWND>, 4
      @DefProto DllImport, LoadAcceleratorsA, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCSTR>, 8
      @DefProto DllImport, LoadAcceleratorsW, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCWSTR>, 8
      ifdef UNICODE
        LoadAccelerators equ <LoadAcceleratorsW>
      else
        LoadAccelerators equ <LoadAcceleratorsA>
      endif
      ; !UNICODE
      @DefProto DllImport, CreateAcceleratorTableA, WIN_STD_CALL_CONV,, <:LPACCEL, :SDWORD>, 8
      @DefProto DllImport, CreateAcceleratorTableW, WIN_STD_CALL_CONV,, <:LPACCEL, :SDWORD>, 8
      ifdef UNICODE
        CreateAcceleratorTable equ <CreateAcceleratorTableW>
      else
        CreateAcceleratorTable equ <CreateAcceleratorTableA>
      endif
      ; !UNICODE
      @DefProto DllImport, DestroyAcceleratorTable, WIN_STD_CALL_CONV,, <:HACCEL>, 4
      @DefProto DllImport, CopyAcceleratorTableA, WIN_STD_CALL_CONV,, <:HACCEL, :LPACCEL, :SDWORD>, 12
      @DefProto DllImport, CopyAcceleratorTableW, WIN_STD_CALL_CONV,, <:HACCEL, :LPACCEL, :SDWORD>, 12
      ifdef UNICODE
        CopyAcceleratorTable equ <CopyAcceleratorTableW>
      else
        CopyAcceleratorTable equ <CopyAcceleratorTableA>
      endif
      ; !UNICODE
      ifndef NOMSG
        @DefProto DllImport, TranslateAcceleratorA, WIN_STD_CALL_CONV,, <:HWND, :HACCEL, :LPMSG>, 12
        @DefProto DllImport, TranslateAcceleratorW, WIN_STD_CALL_CONV,, <:HWND, :HACCEL, :LPMSG>, 12
        ifdef UNICODE
          TranslateAccelerator equ <TranslateAcceleratorW>
        else
          TranslateAccelerator equ <TranslateAcceleratorA>
        endif
        ; !UNICODE
        ;* !NOMSG *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ifndef NOSYSMETRICS
      ;*
      ;* GetSystemMetrics() codes
      ;*
      SM_CXSCREEN equ 0
      SM_CYSCREEN equ 1
      SM_CXVSCROLL equ 2
      SM_CYHSCROLL equ 3
      SM_CYCAPTION equ 4
      SM_CXBORDER equ 5
      SM_CYBORDER equ 6
      SM_CXDLGFRAME equ 7
      SM_CYDLGFRAME equ 8
      SM_CYVTHUMB equ 9
      SM_CXHTHUMB equ 10
      SM_CXICON equ 11
      SM_CYICON equ 12
      SM_CXCURSOR equ 13
      SM_CYCURSOR equ 14
      SM_CYMENU equ 15
      SM_CXFULLSCREEN equ 16
      SM_CYFULLSCREEN equ 17
      SM_CYKANJIWINDOW equ 18
      SM_MOUSEPRESENT equ 19
      SM_CYVSCROLL equ 20
      SM_CXHSCROLL equ 21
      SM_DEBUG equ 22
      SM_SWAPBUTTON equ 23
      SM_RESERVED1 equ 24
      SM_RESERVED2 equ 25
      SM_RESERVED3 equ 26
      SM_RESERVED4 equ 27
      SM_CXMIN equ 28
      SM_CYMIN equ 29
      SM_CXSIZE equ 30
      SM_CYSIZE equ 31
      SM_CXFRAME equ 32
      SM_CYFRAME equ 33
      SM_CXMINTRACK equ 34
      SM_CYMINTRACK equ 35
      SM_CXDOUBLECLK equ 36
      SM_CYDOUBLECLK equ 37
      SM_CXICONSPACING equ 38
      SM_CYICONSPACING equ 39
      SM_MENUDROPALIGNMENT equ 40
      SM_PENWINDOWS equ 41
      SM_DBCSENABLED equ 42
      SM_CMOUSEBUTTONS equ 43
      if (WINVER ge 0400h)
        ;* ;win40 name change *
        SM_CXFIXEDFRAME equ <SM_CXDLGFRAME>
        ;* ;win40 name change *
        SM_CYFIXEDFRAME equ <SM_CYDLGFRAME>
        ;* ;win40 name change *
        SM_CXSIZEFRAME equ <SM_CXFRAME>
        ;* ;win40 name change *
        SM_CYSIZEFRAME equ <SM_CYFRAME>
        SM_SECURE equ 44
        SM_CXEDGE equ 45
        SM_CYEDGE equ 46
        SM_CXMINSPACING equ 47
        SM_CYMINSPACING equ 48
        SM_CXSMICON equ 49
        SM_CYSMICON equ 50
        SM_CYSMCAPTION equ 51
        SM_CXSMSIZE equ 52
        SM_CYSMSIZE equ 53
        SM_CXMENUSIZE equ 54
        SM_CYMENUSIZE equ 55
        SM_ARRANGE equ 56
        SM_CXMINIMIZED equ 57
        SM_CYMINIMIZED equ 58
        SM_CXMAXTRACK equ 59
        SM_CYMAXTRACK equ 60
        SM_CXMAXIMIZED equ 61
        SM_CYMAXIMIZED equ 62
        SM_NETWORK equ 63
        SM_CLEANBOOT equ 67
        SM_CXDRAG equ 68
        SM_CYDRAG equ 69
        ;* WINVER >= 0x0400 *
      endif
      SM_SHOWSOUNDS equ 70
      if (WINVER ge 0400h)
        ;* Use instead of GetMenuCheckMarkDimensions()! *
        SM_CXMENUCHECK equ 71
        SM_CYMENUCHECK equ 72
        SM_SLOWMACHINE equ 73
        SM_MIDEASTENABLED equ 74
        ;* WINVER >= 0x0400 *
      endif
      if (WINVER ge 0500h) or (_WIN32_WINNT ge 0400h)
        SM_MOUSEWHEELPRESENT equ 75
      endif
      if (WINVER ge 0500h)
        SM_XVIRTUALSCREEN equ 76
        SM_YVIRTUALSCREEN equ 77
        SM_CXVIRTUALSCREEN equ 78
        SM_CYVIRTUALSCREEN equ 79
        SM_CMONITORS equ 80
        SM_SAMEDISPLAYFORMAT equ 81
        ;* WINVER >= 0x0500 *
      endif
      if (_WIN32_WINNT ge 0500h)
        SM_IMMENABLED equ 82
        ;* _WIN32_WINNT >= 0x0500 *
      endif
      if (_WIN32_WINNT ge 0501h)
        SM_CXFOCUSBORDER equ 83
        SM_CYFOCUSBORDER equ 84
        ;* _WIN32_WINNT >= 0x0501 *
      endif
      if (_WIN32_WINNT ge 0501h)
        SM_TABLETPC equ 86
        SM_MEDIACENTER equ 87
        SM_STARTER equ 88
        SM_SERVERR2 equ 89
        ;* _WIN32_WINNT >= 0x0501 *
      endif
      if (_WIN32_WINNT ge 0600h)
        SM_MOUSEHORIZONTALWHEELPRESENT equ 91
        SM_CXPADDEDBORDER equ 92
        ;* _WIN32_WINNT >= 0x0600 *
      endif
      if (WINVER ge 0601h)
        SM_DIGITIZER equ 94
        SM_MAXIMUMTOUCHES equ 95
        ;* WINVER >= 0x0601 *
      endif
      if (WINVER lt 0500h) and ( not Defined(_WIN32_WINNT) or (_WIN32_WINNT lt 0400h))
        SM_CMETRICS equ 76
      elseif WINVER eq 500h
        SM_CMETRICS equ 83
      elseif WINVER eq 501h
        SM_CMETRICS equ 91
      elseif WINVER eq 600h
        SM_CMETRICS equ 93
      else
        SM_CMETRICS equ 97
      endif
      if (WINVER ge 0500h)
        SM_REMOTESESSION equ 1000h
        if (_WIN32_WINNT ge 0501h)
          SM_SHUTTINGDOWN equ 2000h
          ;* _WIN32_WINNT >= 0x0501 *
        endif
        if (WINVER ge 0501h)
          SM_REMOTECONTROL equ 2001h
          ;* WINVER >= 0x0501 *
        endif
        if (WINVER ge 0501h)
          SM_CARETBLINKINGENABLED equ 2002h
          ;* WINVER >= 0x0501 *
        endif
        if (WINVER ge 0602h)
          SM_CONVERTIBLESLATEMODE equ 2003h
          SM_SYSTEMDOCKED equ 2004h
          ;* WINVER >= 0x0602 *
        endif
        ;* WINVER >= 0x0500 *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, GetSystemMetrics, WIN_STD_CALL_CONV,, <:SDWORD>, 4
        if (WINVER ge 0605h)
          @DefProto DllImport, GetSystemMetricsForDpi, WIN_STD_CALL_CONV,, <:SDWORD, :UINT>, 8
          ;* WINVER >= 0x0605 *
        endif
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;* !NOSYSMETRICS *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ifndef NOMENUS
        @DefProto DllImport, LoadMenuA, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCSTR>, 8
        @DefProto DllImport, LoadMenuW, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCWSTR>, 8
        ifdef UNICODE
          LoadMenu equ <LoadMenuW>
        else
          LoadMenu equ <LoadMenuA>
        endif
        ; !UNICODE
        @DefProto DllImport, LoadMenuIndirectA, WIN_STD_CALL_CONV,, <:ptr MENUTEMPLATEA>, 4
        @DefProto DllImport, LoadMenuIndirectW, WIN_STD_CALL_CONV,, <:ptr MENUTEMPLATEW>, 4
        ifdef UNICODE
          LoadMenuIndirect equ <LoadMenuIndirectW>
        else
          LoadMenuIndirect equ <LoadMenuIndirectA>
        endif
        ; !UNICODE
        @DefProto DllImport, GetMenu, WIN_STD_CALL_CONV,, <:HWND>, 4
        @DefProto DllImport, SetMenu, WIN_STD_CALL_CONV,, <:HWND, :HMENU>, 8
        @DefProto DllImport, ChangeMenuA, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :LPCSTR, :UINT, :UINT>, 20
        @DefProto DllImport, ChangeMenuW, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :LPCWSTR, :UINT, :UINT>, 20
        ifdef UNICODE
          ChangeMenu equ <ChangeMenuW>
        else
          ChangeMenu equ <ChangeMenuA>
        endif
        ; !UNICODE
        @DefProto DllImport, HiliteMenuItem, WIN_STD_CALL_CONV,, <:HWND, :HMENU, :UINT, :UINT>, 16
        @DefProto DllImport, GetMenuStringA, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :LPSTR, :SDWORD, :UINT>, 20
        @DefProto DllImport, GetMenuStringW, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :LPWSTR, :SDWORD, :UINT>, 20
        ifdef UNICODE
          GetMenuString equ <GetMenuStringW>
        else
          GetMenuString equ <GetMenuStringA>
        endif
        ; !UNICODE
        @DefProto DllImport, GetMenuState, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :UINT>, 12
        @DefProto DllImport, DrawMenuBar, WIN_STD_CALL_CONV,, <:HWND>, 4
        if (_WIN32_WINNT ge 0501h)
          PMB_ACTIVE equ 00000001h
          ;* _WIN32_WINNT >= 0x0501 *
        endif
        @DefProto DllImport, GetSystemMenu, WIN_STD_CALL_CONV,, <:HWND, :BOOL>, 8
        @DefProto DllImport, CreateMenu, WIN_STD_CALL_CONV,, <>, 0
        @DefProto DllImport, CreatePopupMenu, WIN_STD_CALL_CONV,, <>, 0
        @DefProto DllImport, DestroyMenu, WIN_STD_CALL_CONV,, <:HMENU>, 4
        @DefProto DllImport, CheckMenuItem, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :UINT>, 12
        @DefProto DllImport, EnableMenuItem, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :UINT>, 12
        @DefProto DllImport, GetSubMenu, WIN_STD_CALL_CONV,, <:HMENU, :SDWORD>, 8
        @DefProto DllImport, GetMenuItemID, WIN_STD_CALL_CONV,, <:HMENU, :SDWORD>, 8
        @DefProto DllImport, GetMenuItemCount, WIN_STD_CALL_CONV,, <:HMENU>, 4
        @DefProto DllImport, InsertMenuA, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :UINT, :UINT_PTR, :LPCSTR>, 20
        @DefProto DllImport, InsertMenuW, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :UINT, :UINT_PTR, :LPCWSTR>, 20
        ifdef UNICODE
          InsertMenu equ <InsertMenuW>
        else
          InsertMenu equ <InsertMenuA>
        endif
        ; !UNICODE
        @DefProto DllImport, AppendMenuA, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :UINT_PTR, :LPCSTR>, 16
        @DefProto DllImport, AppendMenuW, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :UINT_PTR, :LPCWSTR>, 16
        ifdef UNICODE
          AppendMenu equ <AppendMenuW>
        else
          AppendMenu equ <AppendMenuA>
        endif
        ; !UNICODE
        @DefProto DllImport, ModifyMenuA, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :UINT, :UINT_PTR, :LPCSTR>, 20
        @DefProto DllImport, ModifyMenuW, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :UINT, :UINT_PTR, :LPCWSTR>, 20
        ifdef UNICODE
          ModifyMenu equ <ModifyMenuW>
        else
          ModifyMenu equ <ModifyMenuA>
        endif
        ; !UNICODE
        @DefProto DllImport, RemoveMenu, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :UINT>, 12
        @DefProto DllImport, DeleteMenu, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :UINT>, 12
        @DefProto DllImport, SetMenuItemBitmaps, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :UINT, :HBITMAP, :HBITMAP>, 20
        @DefProto DllImport, GetMenuCheckMarkDimensions, WIN_STD_CALL_CONV,, <>, 0
        @DefProto DllImport, TrackPopupMenu, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :SDWORD, :SDWORD, :SDWORD, :HWND, :ptr RECT>, 28
        if (WINVER ge 0400h)
          ;* return codes for WM_MENUCHAR *
          MNC_IGNORE equ 0
          MNC_CLOSE equ 1
          MNC_EXECUTE equ 2
          MNC_SELECT equ 3
          TPMPARAMS struct
            cbSize DWORD ?
            ;* Size of structure *
            rcExclude RECT <>
            ;* Screen coordinates of rectangle to exclude when positioning *
          TPMPARAMS ends
          tagTPMPARAMS typedef TPMPARAMS
          LPTPMPARAMS typedef ptr TPMPARAMS
          @DefProto DllImport, TrackPopupMenuEx, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :SDWORD, :SDWORD, :HWND, :LPTPMPARAMS>, 24
          ;* WINVER >= 0x0400 *
        endif
        if (_WIN32_WINNT ge 0601h)
          @DefProto DllImport, CalculatePopupWindowPosition, WIN_STD_CALL_CONV,, <:ptr POINT, :ptr SIZE_, :UINT, :ptr RECT, :ptr RECT>, 20
          ;* TPM_XXX values *
          ;* _WIN32_WINNT >= 0x0601 *
        endif
        if (WINVER ge 0500h)
          MNS_NOCHECK equ 80000000h
          MNS_MODELESS equ 40000000h
          MNS_DRAGDROP equ 20000000h
          MNS_AUTODISMISS equ 10000000h
          MNS_NOTIFYBYPOS equ 08000000h
          MNS_CHECKORBMP equ 04000000h
          MIM_MAXHEIGHT equ 00000001h
          MIM_BACKGROUND equ 00000002h
          MIM_HELPID equ 00000004h
          MIM_MENUDATA equ 00000008h
          MIM_STYLE equ 00000010h
          MIM_APPLYTOSUBMENUS equ 80000000h
          MENUINFO struct
            cbSize DWORD ?
            fMask DWORD ?
            dwStyle DWORD ?
            cyMax DWORD ?
            hbrBack HBRUSH ?
            dwContextHelpID DWORD ?
            dwMenuData XWORD ?
          MENUINFO ends
          tagMENUINFO typedef MENUINFO
          LPMENUINFO typedef ptr MENUINFO
          LPCMENUINFO typedef ptr MENUINFO
          @DefProto DllImport, GetMenuInfo, WIN_STD_CALL_CONV,, <:HMENU, :LPMENUINFO>, 8
          @DefProto DllImport, SetMenuInfo, WIN_STD_CALL_CONV,, <:HMENU, :LPCMENUINFO>, 8
          @DefProto DllImport, EndMenu, WIN_STD_CALL_CONV,, <>, 0
          ;*
          ;* WM_MENUDRAG return values.
          ;*
          MND_CONTINUE equ 0
          MND_ENDMENU equ 1
          MENUGETOBJECTINFO struct
            dwFlags DWORD ?
            uPos DWORD ?
            hmenu HMENU ?
            riid POINTER ?
            pvObj POINTER ?
          MENUGETOBJECTINFO ends
          tagMENUGETOBJECTINFO typedef MENUGETOBJECTINFO
          PMENUGETOBJECTINFO typedef ptr MENUGETOBJECTINFO
          ;*
          ;* MENUGETOBJECTINFO dwFlags values
          ;*
          MNGOF_TOPGAP equ 00000001h
          MNGOF_BOTTOMGAP equ 00000002h
          ;*
          ;* WM_MENUGETOBJECT return values
          ;*
          MNGO_NOINTERFACE equ 00000000h
          MNGO_NOERROR equ 00000001h
          ;* WINVER >= 0x0500 *
        endif
        if (WINVER ge 0400h)
          MIIM_STATE equ 00000001h
          MIIM_ID equ 00000002h
          MIIM_SUBMENU equ 00000004h
          MIIM_CHECKMARKS equ 00000008h
          MIIM_TYPE equ 00000010h
          MIIM_DATA equ 00000020h
          ;* WINVER >= 0x0400 *
        endif
        if (WINVER ge 0500h)
          MIIM_STRING equ 00000040h
          MIIM_BITMAP equ 00000080h
          MIIM_FTYPE equ 00000100h
          HBMMENU_CALLBACK equ (- 1)
          HBMMENU_SYSTEM equ (1)
          HBMMENU_MBAR_RESTORE equ (2)
          HBMMENU_MBAR_MINIMIZE equ (3)
          HBMMENU_MBAR_CLOSE equ (5)
          HBMMENU_MBAR_CLOSE_D equ (6)
          HBMMENU_MBAR_MINIMIZE_D equ (7)
          HBMMENU_POPUP_CLOSE equ (8)
          HBMMENU_POPUP_RESTORE equ (9)
          HBMMENU_POPUP_MAXIMIZE equ (10)
          HBMMENU_POPUP_MINIMIZE equ (11)
          ;* WINVER >= 0x0500 *
        endif
        if (WINVER ge 0400h)
          MENUITEMINFOA struct
            cbSize DWORD ?
            fMask DWORD ?
            fType DWORD ?
            ; used if MIIM_TYPE (4.0) or MIIM_FTYPE (>4.0)
            fState DWORD ?
            ; used if MIIM_STATE
            wID DWORD ?
            ; used if MIIM_ID
            hSubMenu HMENU ?
            ; used if MIIM_SUBMENU
            hbmpChecked HBITMAP ?
            ; used if MIIM_CHECKMARKS
            hbmpUnchecked HBITMAP ?
            ; used if MIIM_CHECKMARKS
            dwItemData XWORD ?
            ; used if MIIM_DATA
            dwTypeData POINTER ?
            ; used if MIIM_TYPE (4.0) or MIIM_STRING (>4.0)
            cch DWORD ?
            ; used if MIIM_TYPE (4.0) or MIIM_STRING (>4.0)
            if (WINVER ge 0500h)
              hbmpItem HBITMAP ?
              ; used if MIIM_BITMAP
              ;* WINVER >= 0x0500 *
            endif
          MENUITEMINFOA ends
          tagMENUITEMINFOA typedef MENUITEMINFOA
          LPMENUITEMINFOA typedef ptr MENUITEMINFOA
          MENUITEMINFOW struct
            cbSize DWORD ?
            fMask DWORD ?
            fType DWORD ?
            ; used if MIIM_TYPE (4.0) or MIIM_FTYPE (>4.0)
            fState DWORD ?
            ; used if MIIM_STATE
            wID DWORD ?
            ; used if MIIM_ID
            hSubMenu HMENU ?
            ; used if MIIM_SUBMENU
            hbmpChecked HBITMAP ?
            ; used if MIIM_CHECKMARKS
            hbmpUnchecked HBITMAP ?
            ; used if MIIM_CHECKMARKS
            dwItemData XWORD ?
            ; used if MIIM_DATA
            dwTypeData POINTER ?
            ; used if MIIM_TYPE (4.0) or MIIM_STRING (>4.0)
            cch DWORD ?
            ; used if MIIM_TYPE (4.0) or MIIM_STRING (>4.0)
            if (WINVER ge 0500h)
              hbmpItem HBITMAP ?
              ; used if MIIM_BITMAP
              ;* WINVER >= 0x0500 *
            endif
          MENUITEMINFOW ends
          tagMENUITEMINFOW typedef MENUITEMINFOW
          LPMENUITEMINFOW typedef ptr MENUITEMINFOW
          ifdef UNICODE
            MENUITEMINFO typedef MENUITEMINFOW
            LPMENUITEMINFO typedef LPMENUITEMINFOW
          else
            MENUITEMINFO typedef MENUITEMINFOA
            LPMENUITEMINFO typedef LPMENUITEMINFOA
          endif
          ; UNICODE
          LPCMENUITEMINFOA typedef ptr MENUITEMINFOA
          LPCMENUITEMINFOW typedef ptr MENUITEMINFOW
          ifdef UNICODE
            LPCMENUITEMINFO typedef LPCMENUITEMINFOW
          else
            LPCMENUITEMINFO typedef LPCMENUITEMINFOA
          endif
          ; UNICODE
          @DefProto DllImport, InsertMenuItemA, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :BOOL, :LPCMENUITEMINFOA>, 16
          @DefProto DllImport, InsertMenuItemW, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :BOOL, :LPCMENUITEMINFOW>, 16
          ifdef UNICODE
            InsertMenuItem equ <InsertMenuItemW>
          else
            InsertMenuItem equ <InsertMenuItemA>
          endif
          ; !UNICODE
          @DefProto DllImport, GetMenuItemInfoA, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :BOOL, :LPMENUITEMINFOA>, 16
          @DefProto DllImport, GetMenuItemInfoW, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :BOOL, :LPMENUITEMINFOW>, 16
          ifdef UNICODE
            GetMenuItemInfo equ <GetMenuItemInfoW>
          else
            GetMenuItemInfo equ <GetMenuItemInfoA>
          endif
          ; !UNICODE
          @DefProto DllImport, SetMenuItemInfoA, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :BOOL, :LPCMENUITEMINFOA>, 16
          @DefProto DllImport, SetMenuItemInfoW, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :BOOL, :LPCMENUITEMINFOW>, 16
          ifdef UNICODE
            SetMenuItemInfo equ <SetMenuItemInfoW>
          else
            SetMenuItemInfo equ <SetMenuItemInfoA>
          endif
          ; !UNICODE
          GMDI_USEDISABLED equ 0001h
          GMDI_GOINTOPOPUPS equ 0002h
          @DefProto DllImport, GetMenuDefaultItem, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :UINT>, 12
          @DefProto DllImport, SetMenuDefaultItem, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :UINT>, 12
          @DefProto DllImport, GetMenuItemRect, WIN_STD_CALL_CONV,, <:HWND, :HMENU, :UINT, :LPRECT>, 16
          @DefProto DllImport, MenuItemFromPoint, WIN_STD_CALL_CONV,, <:HWND, :HMENU, :POINT>, 12
          ;* WINVER >= 0x0400 *
        endif
        ;*
        ;* Flags for TrackPopupMenu
        ;*
        TPM_LEFTBUTTON equ 0000h
        TPM_RIGHTBUTTON equ 0002h
        TPM_LEFTALIGN equ 0000h
        TPM_CENTERALIGN equ 0004h
        TPM_RIGHTALIGN equ 0008h
        if (WINVER ge 0400h)
          TPM_TOPALIGN equ 0000h
          TPM_VCENTERALIGN equ 0010h
          TPM_BOTTOMALIGN equ 0020h
          ;* Horz alignment matters more *
          TPM_HORIZONTAL equ 0000h
          ;* Vert alignment matters more *
          TPM_VERTICAL equ 0040h
          ;* Don't send any notification msgs *
          TPM_NONOTIFY equ 0080h
          TPM_RETURNCMD equ 0100h
          ;* WINVER >= 0x0400 *
        endif
        if (WINVER ge 0500h)
          TPM_RECURSE equ 0001h
          TPM_HORPOSANIMATION equ 0400h
          TPM_HORNEGANIMATION equ 0800h
          TPM_VERPOSANIMATION equ 1000h
          TPM_VERNEGANIMATION equ 2000h
          if (_WIN32_WINNT ge 0500h)
            TPM_NOANIMATION equ 4000h
            ;* _WIN32_WINNT >= 0x0500 *
          endif
          if (_WIN32_WINNT ge 0501h)
            TPM_LAYOUTRTL equ 8000h
            ;* _WIN32_WINNT >= 0x0501 *
          endif
          ;* WINVER >= 0x0500 *
        endif
        if (_WIN32_WINNT ge 0601h)
          TPM_WORKAREA equ 10000h
          ;* _WIN32_WINNT >= 0x0601 *
        endif
        ;* !NOMENUS *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if (WINVER ge 0400h)
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        ; Drag-and-drop support
        ; Obsolete - use OLE instead
        DROPSTRUCT struct
          hwndSource HWND ?
          hwndSink HWND ?
          wFmt DWORD ?
          dwData XWORD ?
          ptDrop POINT <>
          dwControlData DWORD ?
        DROPSTRUCT ends
        tagDROPSTRUCT typedef DROPSTRUCT
        PDROPSTRUCT typedef ptr DROPSTRUCT
        LPDROPSTRUCT typedef ptr DROPSTRUCT
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      DOF_EXECUTABLE equ 8001h; wFmt flags

      DOF_DOCUMENT equ 8002h
      DOF_DIRECTORY equ 8003h
      DOF_MULTIPLE equ 8004h
      DOF_PROGMAN equ 0001h
      DOF_SHELLDATA equ 0002h
      DO_DROPFILE equ 454C4946h
      DO_PRINTFILE equ 544E5250h
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, DragObject, WIN_STD_CALL_CONV,, <:HWND, :HWND, :UINT, :ULONG_PTR, :HCURSOR>, 20
        @DefProto DllImport, DragDetect, WIN_STD_CALL_CONV,, <:HWND, :POINT>, 8
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;* WINVER >= 0x0400 *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, DrawIcon, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :HICON>, 16
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ifndef NODRAWTEXT
      ;*
      ;* DrawText() Format Flags
      ;*
      DT_TOP equ 00000000h
      DT_LEFT equ 00000000h
      DT_CENTER equ 00000001h
      DT_RIGHT equ 00000002h
      DT_VCENTER equ 00000004h
      DT_BOTTOM equ 00000008h
      DT_WORDBREAK equ 00000010h
      DT_SINGLELINE equ 00000020h
      DT_EXPANDTABS equ 00000040h
      DT_TABSTOP equ 00000080h
      DT_NOCLIP equ 00000100h
      DT_EXTERNALLEADING equ 00000200h
      DT_CALCRECT equ 00000400h
      DT_NOPREFIX equ 00000800h
      DT_INTERNAL equ 00001000h
      if (WINVER ge 0400h)
        DT_EDITCONTROL equ 00002000h
        DT_PATH_ELLIPSIS equ 00004000h
        DT_END_ELLIPSIS equ 00008000h
        DT_MODIFYSTRING equ 00010000h
        DT_RTLREADING equ 00020000h
        DT_WORD_ELLIPSIS equ 00040000h
        if (WINVER ge 0500h)
          DT_NOFULLWIDTHCHARBREAK equ 00080000h
          if (_WIN32_WINNT ge 0500h)
            DT_HIDEPREFIX equ 00100000h
            DT_PREFIXONLY equ 00200000h
            ;* _WIN32_WINNT >= 0x0500 *
          endif
          ;* WINVER >= 0x0500 *
        endif
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
          DRAWTEXTPARAMS struct
            cbSize DWORD ?
            iTabLength SDWORD ?
            iLeftMargin SDWORD ?
            iRightMargin SDWORD ?
            uiLengthDrawn DWORD ?
          DRAWTEXTPARAMS ends
          tagDRAWTEXTPARAMS typedef DRAWTEXTPARAMS
          LPDRAWTEXTPARAMS typedef ptr DRAWTEXTPARAMS
          ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
        endif
        ;* WINVER >= 0x0400 *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        _In_bypassable_reads_or_z_ macro size_
          exitm <_When_(((size_) == - 1) or (_String_length_ (_Curr_) < (size_)), _In_z_) _When_(((size_) != - 1) and (_String_length_ (_Curr_) >= (size_)), _In_reads_(size_))>
        endm
        _Inout_grows_updates_bypassable_or_z_ macro size_, grows
          exitm <_When_(((size_) == - 1) or (_String_length_ (_Curr_) < (size_)), _Pre_z_ _Pre_valid_ _Out_writes_z_(_String_length_ (_Curr_) + (grows))) _When_(((size_) != - 1) and (_String_length_ (_Curr_) >= (size_)), _Pre_count_(size_) _Pre_valid_ _Out_writes_z_((size_) + (grows)))>
        endm
        @DefProto DllImport, DrawTextA, WIN_STD_CALL_CONV,, <:HDC, :LPCSTR, :SDWORD, :LPRECT, :UINT>, 20
        @DefProto DllImport, DrawTextW, WIN_STD_CALL_CONV,, <:HDC, :LPCWSTR, :SDWORD, :LPRECT, :UINT>, 20
        ifdef UNICODE
          DrawText equ <DrawTextW>
        else
          DrawText equ <DrawTextA>
        endif
        ; !UNICODE
        if Defined(_M_CEE)
          ;[...]
        endif
        if (WINVER ge 0400h)
          @DefProto DllImport, DrawTextExA, WIN_STD_CALL_CONV,, <:HDC, :LPSTR, :SDWORD, :LPRECT, :UINT, :LPDRAWTEXTPARAMS>, 24
          @DefProto DllImport, DrawTextExW, WIN_STD_CALL_CONV,, <:HDC, :LPWSTR, :SDWORD, :LPRECT, :UINT, :LPDRAWTEXTPARAMS>, 24
          ifdef UNICODE
            DrawTextEx equ <DrawTextExW>
          else
            DrawTextEx equ <DrawTextExA>
          endif
          ; !UNICODE
          ;* WINVER >= 0x0400 *
        endif
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;* !NODRAWTEXT *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, GrayStringA, WIN_STD_CALL_CONV,, <:HDC, :HBRUSH, :GRAYSTRINGPROC, :LPARAM, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD>, 36
      @DefProto DllImport, GrayStringW, WIN_STD_CALL_CONV,, <:HDC, :HBRUSH, :GRAYSTRINGPROC, :LPARAM, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD>, 36
      ifdef UNICODE
        GrayString equ <GrayStringW>
      else
        GrayString equ <GrayStringA>
      endif
      ; !UNICODE
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if (WINVER ge 0400h)
      ;* Monolithic state-drawing routine *
      ;* Image type *
      DST_COMPLEX equ 0000h
      DST_TEXT equ 0001h
      DST_PREFIXTEXT equ 0002h
      DST_ICON equ 0003h
      DST_BITMAP equ 0004h
      ;* State type *
      DSS_NORMAL equ 0000h
      ;* Gray string appearance *
      DSS_UNION equ 0010h
      DSS_DISABLED equ 0020h
      DSS_MONO equ 0080h
      if (_WIN32_WINNT ge 0500h)
        DSS_HIDEPREFIX equ 0200h
        DSS_PREFIXONLY equ 0400h
        ;* _WIN32_WINNT >= 0x0500 *
      endif
      DSS_RIGHT equ 8000h
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, DrawStateA, WIN_STD_CALL_CONV,, <:HDC, :HBRUSH, :DRAWSTATEPROC, :LPARAM, :WPARAM, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :UINT>, 40
        @DefProto DllImport, DrawStateW, WIN_STD_CALL_CONV,, <:HDC, :HBRUSH, :DRAWSTATEPROC, :LPARAM, :WPARAM, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :UINT>, 40
        ifdef UNICODE
          DrawState equ <DrawStateW>
        else
          DrawState equ <DrawStateA>
        endif
        ; !UNICODE
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;* WINVER >= 0x0400 *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, TabbedTextOutA, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :LPCSTR, :SDWORD, :SDWORD, :ptr INT_, :SDWORD>, 32
      @DefProto DllImport, TabbedTextOutW, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :LPCWSTR, :SDWORD, :SDWORD, :ptr INT_, :SDWORD>, 32
      ifdef UNICODE
        TabbedTextOut equ <TabbedTextOutW>
      else
        TabbedTextOut equ <TabbedTextOutA>
      endif
      ; !UNICODE
      @DefProto DllImport, GetTabbedTextExtentA, WIN_STD_CALL_CONV,, <:HDC, :LPCSTR, :SDWORD, :SDWORD, :ptr INT_>, 20
      @DefProto DllImport, GetTabbedTextExtentW, WIN_STD_CALL_CONV,, <:HDC, :LPCWSTR, :SDWORD, :SDWORD, :ptr INT_>, 20
      ifdef UNICODE
        GetTabbedTextExtent equ <GetTabbedTextExtentW>
      else
        GetTabbedTextExtent equ <GetTabbedTextExtentA>
      endif
      ; !UNICODE
      @DefProto DllImport, UpdateWindow, WIN_STD_CALL_CONV,, <:HWND>, 4
      @DefProto DllImport, SetActiveWindow, WIN_STD_CALL_CONV,, <:HWND>, 4
      @DefProto DllImport, GetForegroundWindow, WIN_STD_CALL_CONV,, <>, 0
      if (WINVER ge 0400h)
        @DefProto DllImport, PaintDesktop, WIN_STD_CALL_CONV,, <:HDC>, 4
        @DefProto DllImport, SwitchToThisWindow, WIN_STD_CALL_CONV,, <:HWND, :BOOL>, 8
        ;* WINVER >= 0x0400 *
      endif
      @DefProto DllImport, SetForegroundWindow, WIN_STD_CALL_CONV,, <:HWND>, 4
      if (_WIN32_WINNT ge 0500h)
        @DefProto DllImport, AllowSetForegroundWindow, WIN_STD_CALL_CONV,, <:DWORD>, 4
        ASFW_ANY equ (- 1)
        @DefProto DllImport, LockSetForegroundWindow, WIN_STD_CALL_CONV,, <:UINT>, 4
        LSFW_LOCK equ 1
        LSFW_UNLOCK equ 2
        ;* _WIN32_WINNT >= 0x0500 *
      endif
      @DefProto DllImport, WindowFromDC, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, GetDC, WIN_STD_CALL_CONV,, <:HWND>, 4
      @DefProto DllImport, GetDCEx, WIN_STD_CALL_CONV,, <:HWND, :HRGN, :DWORD>, 12
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ;*
    ;* GetDCEx() flags
    ;*
    DCX_WINDOW equ 00000001h
    DCX_CACHE equ 00000002h
    DCX_NORESETATTRS equ 00000004h
    DCX_CLIPCHILDREN equ 00000008h
    DCX_CLIPSIBLINGS equ 00000010h
    DCX_PARENTCLIP equ 00000020h
    DCX_EXCLUDERGN equ 00000040h
    DCX_INTERSECTRGN equ 00000080h
    DCX_EXCLUDEUPDATE equ 00000100h
    DCX_INTERSECTUPDATE equ 00000200h
    DCX_LOCKWINDOWUPDATE equ 00000400h
    DCX_VALIDATE equ 00200000h
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, GetWindowDC, WIN_STD_CALL_CONV,, <:HWND>, 4
      @DefProto DllImport, ReleaseDC, WIN_STD_CALL_CONV,, <:HWND, :HDC>, 8
      @DefProto DllImport, BeginPaint, WIN_STD_CALL_CONV,, <:HWND, :LPPAINTSTRUCT>, 8
      @DefProto DllImport, EndPaint, WIN_STD_CALL_CONV,, <:HWND, :ptr PAINTSTRUCT>, 8
      @DefProto DllImport, GetUpdateRect, WIN_STD_CALL_CONV,, <:HWND, :LPRECT, :BOOL>, 12
      @DefProto DllImport, GetUpdateRgn, WIN_STD_CALL_CONV,, <:HWND, :HRGN, :BOOL>, 12
      @DefProto DllImport, SetWindowRgn, WIN_STD_CALL_CONV,, <:HWND, :HRGN, :BOOL>, 12
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, GetWindowRgn, WIN_STD_CALL_CONV,, <:HWND, :HRGN>, 8
      if (_WIN32_WINNT ge 0501h)
        @DefProto DllImport, GetWindowRgnBox, WIN_STD_CALL_CONV,, <:HWND, :LPRECT>, 8
        ;* _WIN32_WINNT >= 0x0501 *
      endif
      @DefProto DllImport, ExcludeUpdateRgn, WIN_STD_CALL_CONV,, <:HDC, :HWND>, 8
      @DefProto DllImport, InvalidateRect, WIN_STD_CALL_CONV,, <:HWND, :ptr RECT, :BOOL>, 12
      @DefProto DllImport, ValidateRect, WIN_STD_CALL_CONV,, <:HWND, :ptr RECT>, 8
      @DefProto DllImport, InvalidateRgn, WIN_STD_CALL_CONV,, <:HWND, :HRGN, :BOOL>, 12
      @DefProto DllImport, ValidateRgn, WIN_STD_CALL_CONV,, <:HWND, :HRGN>, 8
      @DefProto DllImport, RedrawWindow, WIN_STD_CALL_CONV,, <:HWND, :ptr RECT, :HRGN, :UINT>, 16
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ;*
    ;* RedrawWindow() flags
    ;*
    RDW_INVALIDATE equ 0001h
    RDW_INTERNALPAINT equ 0002h
    RDW_ERASE equ 0004h
    RDW_VALIDATE equ 0008h
    RDW_NOINTERNALPAINT equ 0010h
    RDW_NOERASE equ 0020h
    RDW_NOCHILDREN equ 0040h
    RDW_ALLCHILDREN equ 0080h
    RDW_UPDATENOW equ 0100h
    RDW_ERASENOW equ 0200h
    RDW_FRAME equ 0400h
    RDW_NOFRAME equ 0800h
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ;*
      ;* LockWindowUpdate API
      ;*
      @DefProto DllImport, LockWindowUpdate, WIN_STD_CALL_CONV,, <:HWND>, 4
      @DefProto DllImport, ScrollWindow, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :SDWORD, :ptr RECT, :ptr RECT>, 20
      @DefProto DllImport, ScrollDC, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :ptr RECT, :ptr RECT, :HRGN, :LPRECT>, 28
      @DefProto DllImport, ScrollWindowEx, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :SDWORD, :ptr RECT, :ptr RECT, :HRGN, :LPRECT, :UINT>, 32
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ;* Scroll children within *lprcScroll. *
    SW_SCROLLCHILDREN equ 0001h
    ;* Invalidate after scrolling *
    SW_INVALIDATE equ 0002h
    ;* If SW_INVALIDATE, don't send WM_ERASEBACKGROUND *
    SW_ERASE equ 0004h
    if (WINVER ge 0500h)
      ;* Use smooth scrolling *
      SW_SMOOTHSCROLL equ 0010h
      ;* WINVER >= 0x0500 *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ifndef NOSCROLL
        @DefProto DllImport, SetScrollPos, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :SDWORD, :BOOL>, 16
        @DefProto DllImport, GetScrollPos, WIN_STD_CALL_CONV,, <:HWND, :SDWORD>, 8
        @DefProto DllImport, SetScrollRange, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :SDWORD, :SDWORD, :BOOL>, 20
        @DefProto DllImport, GetScrollRange, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LPINT, :LPINT>, 16
        @DefProto DllImport, ShowScrollBar, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :BOOL>, 12
        @DefProto DllImport, EnableScrollBar, WIN_STD_CALL_CONV,, <:HWND, :UINT, :UINT>, 12
        ;*
        ;* EnableScrollBar() flags
        ;*
        ESB_ENABLE_BOTH equ 0000h
        ESB_DISABLE_BOTH equ 0003h
        ESB_DISABLE_LEFT equ 0001h
        ESB_DISABLE_RIGHT equ 0002h
        ESB_DISABLE_UP equ 0001h
        ESB_DISABLE_DOWN equ 0002h
        ESB_DISABLE_LTUP equ <ESB_DISABLE_LEFT>
        ESB_DISABLE_RTDN equ <ESB_DISABLE_RIGHT>
        ;* !NOSCROLL *
      endif
      @DefProto DllImport, SetPropA, WIN_STD_CALL_CONV,, <:HWND, :LPCSTR, :HANDLE>, 12
      @DefProto DllImport, SetPropW, WIN_STD_CALL_CONV,, <:HWND, :LPCWSTR, :HANDLE>, 12
      ifdef UNICODE
        SetProp equ <SetPropW>
      else
        SetProp equ <SetPropA>
      endif
      ; !UNICODE
      @DefProto DllImport, GetPropA, WIN_STD_CALL_CONV,, <:HWND, :LPCSTR>, 8
      @DefProto DllImport, GetPropW, WIN_STD_CALL_CONV,, <:HWND, :LPCWSTR>, 8
      ifdef UNICODE
        GetProp equ <GetPropW>
      else
        GetProp equ <GetPropA>
      endif
      ; !UNICODE
      @DefProto DllImport, RemovePropA, WIN_STD_CALL_CONV,, <:HWND, :LPCSTR>, 8
      @DefProto DllImport, RemovePropW, WIN_STD_CALL_CONV,, <:HWND, :LPCWSTR>, 8
      ifdef UNICODE
        RemoveProp equ <RemovePropW>
      else
        RemoveProp equ <RemovePropA>
      endif
      ; !UNICODE
      @DefProto DllImport, EnumPropsExA, WIN_STD_CALL_CONV,, <:HWND, :PROPENUMPROCEXA, :LPARAM>, 12
      @DefProto DllImport, EnumPropsExW, WIN_STD_CALL_CONV,, <:HWND, :PROPENUMPROCEXW, :LPARAM>, 12
      ifdef UNICODE
        EnumPropsEx equ <EnumPropsExW>
      else
        EnumPropsEx equ <EnumPropsExA>
      endif
      ; !UNICODE
      @DefProto DllImport, EnumPropsA, WIN_STD_CALL_CONV,, <:HWND, :PROPENUMPROCA>, 8
      @DefProto DllImport, EnumPropsW, WIN_STD_CALL_CONV,, <:HWND, :PROPENUMPROCW>, 8
      ifdef UNICODE
        EnumProps equ <EnumPropsW>
      else
        EnumProps equ <EnumPropsA>
      endif
      ; !UNICODE
      @DefProto DllImport, SetWindowTextA, WIN_STD_CALL_CONV,, <:HWND, :LPCSTR>, 8
      @DefProto DllImport, SetWindowTextW, WIN_STD_CALL_CONV,, <:HWND, :LPCWSTR>, 8
      ifdef UNICODE
        SetWindowText equ <SetWindowTextW>
      else
        SetWindowText equ <SetWindowTextA>
      endif
      ; !UNICODE
      @DefProto DllImport, GetWindowTextA, WIN_STD_CALL_CONV,, <:HWND, :LPSTR, :SDWORD>, 12
      @DefProto DllImport, GetWindowTextW, WIN_STD_CALL_CONV,, <:HWND, :LPWSTR, :SDWORD>, 12
      ifdef UNICODE
        GetWindowText equ <GetWindowTextW>
      else
        GetWindowText equ <GetWindowTextA>
      endif
      ; !UNICODE
      @DefProto DllImport, GetWindowTextLengthA, WIN_STD_CALL_CONV,, <:HWND>, 4
      @DefProto DllImport, GetWindowTextLengthW, WIN_STD_CALL_CONV,, <:HWND>, 4
      ifdef UNICODE
        GetWindowTextLength equ <GetWindowTextLengthW>
      else
        GetWindowTextLength equ <GetWindowTextLengthA>
      endif
      ; !UNICODE
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, GetClientRect, WIN_STD_CALL_CONV,, <:HWND, :LPRECT>, 8
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, GetWindowRect, WIN_STD_CALL_CONV,, <:HWND, :LPRECT>, 8
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, AdjustWindowRect, WIN_STD_CALL_CONV,, <:LPRECT, :DWORD, :BOOL>, 12
      @DefProto DllImport, AdjustWindowRectEx, WIN_STD_CALL_CONV,, <:LPRECT, :DWORD, :BOOL, :DWORD>, 16
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      if (WINVER ge 0605h)
        @DefProto DllImport, AdjustWindowRectExForDpi, WIN_STD_CALL_CONV,, <:LPRECT, :DWORD, :BOOL, :DWORD, :UINT>, 20
        ;* WINVER >= 0x0605 *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if (WINVER ge 0400h)
      HELPINFO_WINDOW equ 0001h
      HELPINFO_MENUITEM equ 0002h
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        ;* Structure pointed to by lParam of WM_HELP *
        HELPINFO struct
          cbSize DWORD ?
          ;* Size in bytes of this struct  *
          iContextType SDWORD ?
          ;* Either HELPINFO_WINDOW or HELPINFO_MENUITEM *
          iCtrlId SDWORD ?
          ;* Control Id or a Menu item Id. *
          hItemHandle HANDLE ?
          ;* hWnd of control or hMenu.     *
          dwContextId XWORD ?
          ;* Context Id associated with this item *
          MousePos POINT <>
          ;* Mouse Position in screen co-ordinates *
        HELPINFO ends
        tagHELPINFO typedef HELPINFO
        LPHELPINFO typedef ptr HELPINFO
        @DefProto DllImport, SetWindowContextHelpId, WIN_STD_CALL_CONV,, <:HWND, :DWORD>, 8
        @DefProto DllImport, GetWindowContextHelpId, WIN_STD_CALL_CONV,, <:HWND>, 4
        @DefProto DllImport, SetMenuContextHelpId, WIN_STD_CALL_CONV,, <:HMENU, :DWORD>, 8
        @DefProto DllImport, GetMenuContextHelpId, WIN_STD_CALL_CONV,, <:HMENU>, 4
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;* WINVER >= 0x0400 *
    endif
    ifndef NOMB
      ;*
      ;* MessageBox() Flags
      ;*
      MB_OK equ 00000000h
      MB_OKCANCEL equ 00000001h
      MB_ABORTRETRYIGNORE equ 00000002h
      MB_YESNOCANCEL equ 00000003h
      MB_YESNO equ 00000004h
      MB_RETRYCANCEL equ 00000005h
      if (WINVER ge 0500h)
        MB_CANCELTRYCONTINUE equ 00000006h
        ;* WINVER >= 0x0500 *
      endif
      MB_ICONHAND equ 00000010h
      MB_ICONQUESTION equ 00000020h
      MB_ICONEXCLAMATION equ 00000030h
      MB_ICONASTERISK equ 00000040h
      if (WINVER ge 0400h)
        MB_USERICON equ 00000080h
        MB_ICONWARNING equ <MB_ICONEXCLAMATION>
        MB_ICONERROR equ <MB_ICONHAND>
        ;* WINVER >= 0x0400 *
      endif
      MB_ICONINFORMATION equ <MB_ICONASTERISK>
      MB_ICONSTOP equ <MB_ICONHAND>
      MB_DEFBUTTON1 equ 00000000h
      MB_DEFBUTTON2 equ 00000100h
      MB_DEFBUTTON3 equ 00000200h
      if (WINVER ge 0400h)
        MB_DEFBUTTON4 equ 00000300h
        ;* WINVER >= 0x0400 *
      endif
      MB_APPLMODAL equ 00000000h
      MB_SYSTEMMODAL equ 00001000h
      MB_TASKMODAL equ 00002000h
      if (WINVER ge 0400h)
        MB_HELP equ 00004000h; Help Button

        ;* WINVER >= 0x0400 *
      endif
      MB_NOFOCUS equ 00008000h
      MB_SETFOREGROUND equ 00010000h
      MB_DEFAULT_DESKTOP_ONLY equ 00020000h
      if (WINVER ge 0400h)
        MB_TOPMOST equ 00040000h
        MB_RIGHT equ 00080000h
        MB_RTLREADING equ 00100000h
        ;* WINVER >= 0x0400 *
      endif
      ifdef _WIN32_WINNT
        if (_WIN32_WINNT ge 0400h)
          MB_SERVICE_NOTIFICATION equ 00200000h
        else
          MB_SERVICE_NOTIFICATION equ 00040000h
        endif
        MB_SERVICE_NOTIFICATION_NT3X equ 00040000h
      endif
      MB_TYPEMASK equ 0000000Fh
      MB_ICONMASK equ 000000F0h
      MB_DEFMASK equ 00000F00h
      MB_MODEMASK equ 00003000h
      MB_MISCMASK equ 0000C000h
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, MessageBoxA, WIN_STD_CALL_CONV,, <:HWND, :LPCSTR, :LPCSTR, :UINT>, 16
        @DefProto DllImport, MessageBoxW, WIN_STD_CALL_CONV,, <:HWND, :LPCWSTR, :LPCWSTR, :UINT>, 16
        ifdef UNICODE
          MessageBox equ <MessageBoxW>
        else
          MessageBox equ <MessageBoxA>
        endif
        ; !UNICODE
        if Defined(_M_CEE)
          ;[...]
        endif
        @DefProto DllImport, MessageBoxExA, WIN_STD_CALL_CONV,, <:HWND, :LPCSTR, :LPCSTR, :UINT, :WORD>, 20
        @DefProto DllImport, MessageBoxExW, WIN_STD_CALL_CONV,, <:HWND, :LPCWSTR, :LPCWSTR, :UINT, :WORD>, 20
        ifdef UNICODE
          MessageBoxEx equ <MessageBoxExW>
        else
          MessageBoxEx equ <MessageBoxExA>
        endif
        ; !UNICODE
        if (WINVER ge 0400h)
          TYPE_MSGBOXCALLBACK typedef proto WIN_STD_CALL_CONV :LPHELPINFO
          MSGBOXCALLBACK typedef ptr TYPE_MSGBOXCALLBACK

          MSGBOXPARAMSA struct
            cbSize DWORD ?
            hwndOwner HWND ?
            hInstance HINSTANCE ?
            lpszText =POINTER ?
            lpszCaption =POINTER ?
            dwStyle DWORD ?
            lpszIcon =POINTER ?
            dwContextHelpId XWORD ?
            lpfnMsgBoxCallback MSGBOXCALLBACK ?
            dwLanguageId DWORD ?
          MSGBOXPARAMSA ends
          tagMSGBOXPARAMSA typedef MSGBOXPARAMSA
          PMSGBOXPARAMSA typedef ptr MSGBOXPARAMSA
          LPMSGBOXPARAMSA typedef ptr MSGBOXPARAMSA
          MSGBOXPARAMSW struct
            cbSize DWORD ?
            hwndOwner HWND ?
            hInstance HINSTANCE ?
            lpszText =POINTER ?
            lpszCaption =POINTER ?
            dwStyle DWORD ?
            lpszIcon =POINTER ?
            dwContextHelpId XWORD ?
            lpfnMsgBoxCallback MSGBOXCALLBACK ?
            dwLanguageId DWORD ?
          MSGBOXPARAMSW ends
          tagMSGBOXPARAMSW typedef MSGBOXPARAMSW
          PMSGBOXPARAMSW typedef ptr MSGBOXPARAMSW
          LPMSGBOXPARAMSW typedef ptr MSGBOXPARAMSW
          ifdef UNICODE
            MSGBOXPARAMS typedef MSGBOXPARAMSW
            PMSGBOXPARAMS typedef PMSGBOXPARAMSW
            LPMSGBOXPARAMS typedef LPMSGBOXPARAMSW
          else
            MSGBOXPARAMS typedef MSGBOXPARAMSA
            PMSGBOXPARAMS typedef PMSGBOXPARAMSA
            LPMSGBOXPARAMS typedef LPMSGBOXPARAMSA
          endif
          ; UNICODE
          @DefProto DllImport, MessageBoxIndirectA, WIN_STD_CALL_CONV,, <:ptr MSGBOXPARAMSA>, 4
          @DefProto DllImport, MessageBoxIndirectW, WIN_STD_CALL_CONV,, <:ptr MSGBOXPARAMSW>, 4
          ifdef UNICODE
            MessageBoxIndirect equ <MessageBoxIndirectW>
          else
            MessageBoxIndirect equ <MessageBoxIndirectA>
          endif
          ; !UNICODE
          ;* WINVER >= 0x0400 *
        endif
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, MessageBeep, WIN_STD_CALL_CONV,, <:UINT>, 4
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;* !NOMB *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, ShowCursor, WIN_STD_CALL_CONV,, <:BOOL>, 4
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, SetCursorPos, WIN_STD_CALL_CONV,, <:SDWORD, :SDWORD>, 8
      if (WINVER ge 0600h)
        @DefProto DllImport, SetPhysicalCursorPos, WIN_STD_CALL_CONV,, <:SDWORD, :SDWORD>, 8
        ;* WINVER >= 0x0600 *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, SetCursor, WIN_STD_CALL_CONV,, <:HCURSOR>, 4
      @DefProto DllImport, GetCursorPos, WIN_STD_CALL_CONV,, <:LPPOINT>, 4
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      if (WINVER ge 0600h)
        @DefProto DllImport, GetPhysicalCursorPos, WIN_STD_CALL_CONV,, <:LPPOINT>, 4
        ;* WINVER >= 0x0600 *
      endif
      @DefProto DllImport, GetClipCursor, WIN_STD_CALL_CONV,, <:LPRECT>, 4
      @DefProto DllImport, GetCursor, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, CreateCaret, WIN_STD_CALL_CONV,, <:HWND, :HBITMAP, :SDWORD, :SDWORD>, 16
      @DefProto DllImport, GetCaretBlinkTime, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, SetCaretBlinkTime, WIN_STD_CALL_CONV,, <:UINT>, 4
      @DefProto DllImport, DestroyCaret, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, HideCaret, WIN_STD_CALL_CONV,, <:HWND>, 4
      @DefProto DllImport, ShowCaret, WIN_STD_CALL_CONV,, <:HWND>, 4
      @DefProto DllImport, SetCaretPos, WIN_STD_CALL_CONV,, <:SDWORD, :SDWORD>, 8
      @DefProto DllImport, GetCaretPos, WIN_STD_CALL_CONV,, <:LPPOINT>, 4
      @DefProto DllImport, ClientToScreen, WIN_STD_CALL_CONV,, <:HWND, :LPPOINT>, 8
      @DefProto DllImport, ScreenToClient, WIN_STD_CALL_CONV,, <:HWND, :LPPOINT>, 8
      if (WINVER ge 0600h)
        @DefProto DllImport, LogicalToPhysicalPoint, WIN_STD_CALL_CONV,, <:HWND, :LPPOINT>, 8
        @DefProto DllImport, PhysicalToLogicalPoint, WIN_STD_CALL_CONV,, <:HWND, :LPPOINT>, 8
        ;* WINVER >= 0x0600 *
      endif
      if (WINVER ge 0603h)
        @DefProto DllImport, LogicalToPhysicalPointForPerMonitorDPI, WIN_STD_CALL_CONV,, <:HWND, :LPPOINT>, 8
        @DefProto DllImport, PhysicalToLogicalPointForPerMonitorDPI, WIN_STD_CALL_CONV,, <:HWND, :LPPOINT>, 8
        ;* WINVER >= 0x0603 *
      endif
      @DefProto DllImport, MapWindowPoints, WIN_STD_CALL_CONV,, <:HWND, :HWND, :LPPOINT, :UINT>, 16
      @DefProto DllImport, WindowFromPoint, WIN_STD_CALL_CONV,, <:POINT>, 4
      if (WINVER ge 0600h)
        @DefProto DllImport, WindowFromPhysicalPoint, WIN_STD_CALL_CONV,, <:POINT>, 4
        ;* WINVER >= 0x0600 *
      endif
      @DefProto DllImport, ChildWindowFromPoint, WIN_STD_CALL_CONV,, <:HWND, :POINT>, 8
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PC_APP)
      @DefProto DllImport, ClipCursor, WIN_STD_CALL_CONV,, <:ptr RECT>, 4
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_PC_APP) *
    endif
    if (WINVER ge 0400h)
      CWP_ALL equ 0000h
      CWP_SKIPINVISIBLE equ 0001h
      CWP_SKIPDISABLED equ 0002h
      CWP_SKIPTRANSPARENT equ 0004h
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, ChildWindowFromPointEx, WIN_STD_CALL_CONV,, <:HWND, :POINT, :UINT>, 12
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;* WINVER >= 0x0400 *
    endif
    ifndef NOCOLOR
      ;*
      ;* Color Types
      ;*
      CTLCOLOR_MSGBOX equ 0
      CTLCOLOR_EDIT equ 1
      CTLCOLOR_LISTBOX equ 2
      CTLCOLOR_BTN equ 3
      CTLCOLOR_DLG equ 4
      CTLCOLOR_SCROLLBAR equ 5
      CTLCOLOR_STATIC equ 6
      CTLCOLOR_MAX equ 7
      COLOR_SCROLLBAR equ 0
      COLOR_BACKGROUND equ 1
      COLOR_ACTIVECAPTION equ 2
      COLOR_INACTIVECAPTION equ 3
      COLOR_MENU equ 4
      COLOR_WINDOW equ 5
      COLOR_WINDOWFRAME equ 6
      COLOR_MENUTEXT equ 7
      COLOR_WINDOWTEXT equ 8
      COLOR_CAPTIONTEXT equ 9
      COLOR_ACTIVEBORDER equ 10
      COLOR_INACTIVEBORDER equ 11
      COLOR_APPWORKSPACE equ 12
      COLOR_HIGHLIGHT equ 13
      COLOR_HIGHLIGHTTEXT equ 14
      COLOR_BTNFACE equ 15
      COLOR_BTNSHADOW equ 16
      COLOR_GRAYTEXT equ 17
      COLOR_BTNTEXT equ 18
      COLOR_INACTIVECAPTIONTEXT equ 19
      COLOR_BTNHIGHLIGHT equ 20
      if (WINVER ge 0400h)
        COLOR_3DDKSHADOW equ 21
        COLOR_3DLIGHT equ 22
        COLOR_INFOTEXT equ 23
        COLOR_INFOBK equ 24
        ;* WINVER >= 0x0400 *
      endif
      if (WINVER ge 0500h)
        COLOR_HOTLIGHT equ 26
        COLOR_GRADIENTACTIVECAPTION equ 27
        COLOR_GRADIENTINACTIVECAPTION equ 28
        if (WINVER ge 0501h)
          COLOR_MENUHILIGHT equ 29
          COLOR_MENUBAR equ 30
          ;* WINVER >= 0x0501 *
        endif
        ;* WINVER >= 0x0500 *
      endif
      if (WINVER ge 0400h)
        COLOR_DESKTOP equ <COLOR_BACKGROUND>
        COLOR_3DFACE equ <COLOR_BTNFACE>
        COLOR_3DSHADOW equ <COLOR_BTNSHADOW>
        COLOR_3DHIGHLIGHT equ <COLOR_BTNHIGHLIGHT>
        COLOR_3DHILIGHT equ <COLOR_BTNHIGHLIGHT>
        COLOR_BTNHILIGHT equ <COLOR_BTNHIGHLIGHT>
        ;* WINVER >= 0x0400 *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, GetSysColor, WIN_STD_CALL_CONV,, <:SDWORD>, 4
        if (WINVER ge 0400h)
          @DefProto DllImport, GetSysColorBrush, WIN_STD_CALL_CONV,, <:SDWORD>, 4
          ;* WINVER >= 0x0400 *
        endif
        @DefProto DllImport, SetSysColors, WIN_STD_CALL_CONV,, <:SDWORD, :ptr INT_, :ptr COLORREF>, 12
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;* !NOCOLOR *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, DrawFocusRect, WIN_STD_CALL_CONV,, <:HDC, :ptr RECT>, 8
      @DefProto DllImport, FillRect, WIN_STD_CALL_CONV,, <:HDC, :ptr RECT, :HBRUSH>, 12
      @DefProto DllImport, FrameRect, WIN_STD_CALL_CONV,, <:HDC, :ptr RECT, :HBRUSH>, 12
      @DefProto DllImport, InvertRect, WIN_STD_CALL_CONV,, <:HDC, :ptr RECT>, 8
      @DefProto DllImport, SetRect, WIN_STD_CALL_CONV,, <:LPRECT, :SDWORD, :SDWORD, :SDWORD, :SDWORD>, 20
      @DefProto DllImport, SetRectEmpty, WIN_STD_CALL_CONV,, <:LPRECT>, 4
      @DefProto DllImport, CopyRect, WIN_STD_CALL_CONV,, <:LPRECT, :ptr RECT>, 8
      @DefProto DllImport, InflateRect, WIN_STD_CALL_CONV,, <:LPRECT, :SDWORD, :SDWORD>, 12
      @DefProto DllImport, IntersectRect, WIN_STD_CALL_CONV,, <:LPRECT, :ptr RECT, :ptr RECT>, 12
      @DefProto DllImport, UnionRect, WIN_STD_CALL_CONV,, <:LPRECT, :ptr RECT, :ptr RECT>, 12
      @DefProto DllImport, SubtractRect, WIN_STD_CALL_CONV,, <:LPRECT, :ptr RECT, :ptr RECT>, 12
      @DefProto DllImport, OffsetRect, WIN_STD_CALL_CONV,, <:LPRECT, :SDWORD, :SDWORD>, 12
      @DefProto DllImport, IsRectEmpty, WIN_STD_CALL_CONV,, <:ptr RECT>, 4
      @DefProto DllImport, EqualRect, WIN_STD_CALL_CONV,, <:ptr RECT, :ptr RECT>, 8
      @DefProto DllImport, PtInRect, WIN_STD_CALL_CONV,, <:ptr RECT, :POINT>, 8
      ifndef NOWINOFFSETS
        @DefProto DllImport, GetWindowWord, WIN_STD_CALL_CONV,, <:HWND, :SDWORD>, 8
        @DefProto DllImport, SetWindowWord, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :WORD>, 12
        ;* !NOWINOFFSETS *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      ifndef NOWINOFFSETS
        @DefProto DllImport, GetWindowLongA, WIN_STD_CALL_CONV,, <:HWND, :SDWORD>, 8
        @DefProto DllImport, GetWindowLongW, WIN_STD_CALL_CONV,, <:HWND, :SDWORD>, 8
        ifdef UNICODE
          GetWindowLong equ <GetWindowLongW>
        else
          GetWindowLong equ <GetWindowLongA>
        endif
        ; !UNICODE
        @DefProto DllImport, SetWindowLongA, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LONG>, 12
        @DefProto DllImport, SetWindowLongW, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LONG>, 12
        ifdef UNICODE
          SetWindowLong equ <SetWindowLongW>
        else
          SetWindowLong equ <SetWindowLongA>
        endif
        ; !UNICODE
        ifdef _WIN64
          @DefProto DllImport, GetWindowLongPtrA, WIN_STD_CALL_CONV,, <:HWND, :SDWORD>, 8
          @DefProto DllImport, GetWindowLongPtrW, WIN_STD_CALL_CONV,, <:HWND, :SDWORD>, 8
          ifdef UNICODE
            GetWindowLongPtr equ <GetWindowLongPtrW>
          else
            GetWindowLongPtr equ <GetWindowLongPtrA>
          endif
          ; !UNICODE
          @DefProto DllImport, SetWindowLongPtrA, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LONG_PTR>, 12
          @DefProto DllImport, SetWindowLongPtrW, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LONG_PTR>, 12
          ifdef UNICODE
            SetWindowLongPtr equ <SetWindowLongPtrW>
          else
            SetWindowLongPtr equ <SetWindowLongPtrA>
          endif
          ; !UNICODE
          ;* _WIN64 *
        else
          GetWindowLongPtrA equ <GetWindowLongA>
          GetWindowLongPtrW equ <GetWindowLongW>
          ifdef UNICODE
            GetWindowLongPtr equ <GetWindowLongPtrW>
          else
            GetWindowLongPtr equ <GetWindowLongPtrA>
          endif
          ; !UNICODE
          SetWindowLongPtrA equ <SetWindowLongA>
          SetWindowLongPtrW equ <SetWindowLongW>
          ifdef UNICODE
            SetWindowLongPtr equ <SetWindowLongPtrW>
          else
            SetWindowLongPtr equ <SetWindowLongPtrA>
          endif
          ; !UNICODE
          ;* _WIN64 *
        endif
        ;* !NOWINOFFSETS *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ifndef NOWINOFFSETS
        @DefProto DllImport, GetClassWord, WIN_STD_CALL_CONV,, <:HWND, :SDWORD>, 8
        @DefProto DllImport, SetClassWord, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :WORD>, 12
        @DefProto DllImport, GetClassLongA, WIN_STD_CALL_CONV,, <:HWND, :SDWORD>, 8
        @DefProto DllImport, GetClassLongW, WIN_STD_CALL_CONV,, <:HWND, :SDWORD>, 8
        ifdef UNICODE
          GetClassLong equ <GetClassLongW>
        else
          GetClassLong equ <GetClassLongA>
        endif
        ; !UNICODE
        @DefProto DllImport, SetClassLongA, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LONG>, 12
        @DefProto DllImport, SetClassLongW, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LONG>, 12
        ifdef UNICODE
          SetClassLong equ <SetClassLongW>
        else
          SetClassLong equ <SetClassLongA>
        endif
        ; !UNICODE
        ifdef _WIN64
          @DefProto DllImport, GetClassLongPtrA, WIN_STD_CALL_CONV,, <:HWND, :SDWORD>, 8
          @DefProto DllImport, GetClassLongPtrW, WIN_STD_CALL_CONV,, <:HWND, :SDWORD>, 8
          ifdef UNICODE
            GetClassLongPtr equ <GetClassLongPtrW>
          else
            GetClassLongPtr equ <GetClassLongPtrA>
          endif
          ; !UNICODE
          @DefProto DllImport, SetClassLongPtrA, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LONG_PTR>, 12
          @DefProto DllImport, SetClassLongPtrW, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LONG_PTR>, 12
          ifdef UNICODE
            SetClassLongPtr equ <SetClassLongPtrW>
          else
            SetClassLongPtr equ <SetClassLongPtrA>
          endif
          ; !UNICODE
          ;* _WIN64 *
        else
          GetClassLongPtrA equ <GetClassLongA>
          GetClassLongPtrW equ <GetClassLongW>
          ifdef UNICODE
            GetClassLongPtr equ <GetClassLongPtrW>
          else
            GetClassLongPtr equ <GetClassLongPtrA>
          endif
          ; !UNICODE
          SetClassLongPtrA equ <SetClassLongA>
          SetClassLongPtrW equ <SetClassLongW>
          ifdef UNICODE
            SetClassLongPtr equ <SetClassLongPtrW>
          else
            SetClassLongPtr equ <SetClassLongPtrA>
          endif
          ; !UNICODE
          ;* _WIN64 *
        endif
        ;* !NOWINOFFSETS *
      endif
      if (WINVER ge 0500h)
        @DefProto DllImport, GetProcessDefaultLayout, WIN_STD_CALL_CONV,, <:ptr DWORD>, 4
        @DefProto DllImport, SetProcessDefaultLayout, WIN_STD_CALL_CONV,, <:DWORD>, 4
        ;* WINVER >= 0x0500 *
      endif
      @DefProto DllImport, GetDesktopWindow, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, GetParent, WIN_STD_CALL_CONV,, <:HWND>, 4
      @DefProto DllImport, SetParent, WIN_STD_CALL_CONV,, <:HWND, :HWND>, 8
      @DefProto DllImport, EnumChildWindows, WIN_STD_CALL_CONV,, <:HWND, :WNDENUMPROC, :LPARAM>, 12
      @DefProto DllImport, FindWindowA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR>, 8
      @DefProto DllImport, FindWindowW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR>, 8
      ifdef UNICODE
        FindWindow equ <FindWindowW>
      else
        FindWindow equ <FindWindowA>
      endif
      ; !UNICODE
      if (WINVER ge 0400h)
        @DefProto DllImport, FindWindowExA, WIN_STD_CALL_CONV,, <:HWND, :HWND, :LPCSTR, :LPCSTR>, 16
        @DefProto DllImport, FindWindowExW, WIN_STD_CALL_CONV,, <:HWND, :HWND, :LPCWSTR, :LPCWSTR>, 16
        ifdef UNICODE
          FindWindowEx equ <FindWindowExW>
        else
          FindWindowEx equ <FindWindowExA>
        endif
        ; !UNICODE
        @DefProto DllImport, GetShellWindow, WIN_STD_CALL_CONV,, <>, 0
        ;* WINVER >= 0x0400 *
      endif
      @DefProto DllImport, RegisterShellHookWindow, WIN_STD_CALL_CONV,, <:HWND>, 4
      @DefProto DllImport, DeregisterShellHookWindow, WIN_STD_CALL_CONV,, <:HWND>, 4
      @DefProto DllImport, EnumWindows, WIN_STD_CALL_CONV,, <:WNDENUMPROC, :LPARAM>, 8
      @DefProto DllImport, EnumThreadWindows, WIN_STD_CALL_CONV,, <:DWORD, :WNDENUMPROC, :LPARAM>, 12
      EnumTaskWindows macro hTask, lpfn, lParam
        exitm <EnumThreadWindows (HandleToUlong(hTask), lpfn, lParam)>
      endm
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, GetClassNameA, WIN_STD_CALL_CONV,, <:HWND, :LPSTR, :SDWORD>, 12
      @DefProto DllImport, GetClassNameW, WIN_STD_CALL_CONV,, <:HWND, :LPWSTR, :SDWORD>, 12
      ifdef UNICODE
        GetClassName equ <GetClassNameW>
      else
        GetClassName equ <GetClassNameA>
      endif
      ; !UNICODE
      if Defined(_M_CEE)
        ;[...]
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, GetTopWindow, WIN_STD_CALL_CONV,, <:HWND>, 4
      GetNextWindow macro hWnd, wCmd
        exitm <GetWindow (hWnd, wCmd)>
      endm
      GetSysModalWindow macro 
        exitm <(NULL)>
      endm
      SetSysModalWindow macro hWnd
        exitm <(NULL)>
      endm
      @DefProto DllImport, GetWindowThreadProcessId, WIN_STD_CALL_CONV,, <:HWND, :LPDWORD>, 8
      if (_WIN32_WINNT ge 0501h)
        @DefProto DllImport, IsGUIThread, WIN_STD_CALL_CONV,, <:BOOL>, 4
        ;* _WIN32_WINNT >= 0x0501 *
      endif
      GetWindowTask macro hWnd
        exitm <(GetWindowThreadProcessId (hWnd, NULL))>
      endm
      @DefProto DllImport, GetLastActivePopup, WIN_STD_CALL_CONV,, <:HWND>, 4
      ;*
      ;* GetWindow() Constants
      ;*
      GW_HWNDFIRST equ 0
      GW_HWNDLAST equ 1
      GW_HWNDNEXT equ 2
      GW_HWNDPREV equ 3
      GW_OWNER equ 4
      GW_CHILD equ 5
      if (WINVER le 0400h)
        GW_MAX equ 5
      else
        GW_ENABLEDPOPUP equ 6
        GW_MAX equ 6
      endif
      @DefProto DllImport, GetWindow, WIN_STD_CALL_CONV,, <:HWND, :UINT>, 8
      ifndef NOWH
        ifdef STRICT
          @DefProto DllImport, SetWindowsHookA, WIN_STD_CALL_CONV,, <:SDWORD, :HOOKPROC>, 8
          @DefProto DllImport, SetWindowsHookW, WIN_STD_CALL_CONV,, <:SDWORD, :HOOKPROC>, 8
          ifdef UNICODE
            SetWindowsHook equ <SetWindowsHookW>
          else
            SetWindowsHook equ <SetWindowsHookA>
          endif
          ; !UNICODE
          ;* !STRICT *
        else
          @DefProto DllImport, SetWindowsHookA, WIN_STD_CALL_CONV,, <:SDWORD, :HOOKPROC>, 8
          @DefProto DllImport, SetWindowsHookW, WIN_STD_CALL_CONV,, <:SDWORD, :HOOKPROC>, 8
          ifdef UNICODE
            SetWindowsHook equ <SetWindowsHookW>
          else
            SetWindowsHook equ <SetWindowsHookA>
          endif
          ; !UNICODE
          ;* !STRICT *
        endif
        @DefProto DllImport, UnhookWindowsHook, WIN_STD_CALL_CONV,, <:SDWORD, :HOOKPROC>, 8
        @DefProto DllImport, SetWindowsHookExA, WIN_STD_CALL_CONV,, <:SDWORD, :HOOKPROC, :HINSTANCE, :DWORD>, 16
        @DefProto DllImport, SetWindowsHookExW, WIN_STD_CALL_CONV,, <:SDWORD, :HOOKPROC, :HINSTANCE, :DWORD>, 16
        ifdef UNICODE
          SetWindowsHookEx equ <SetWindowsHookExW>
        else
          SetWindowsHookEx equ <SetWindowsHookExA>
        endif
        ; !UNICODE
        @DefProto DllImport, UnhookWindowsHookEx, WIN_STD_CALL_CONV,, <:HHOOK>, 4
        @DefProto DllImport, CallNextHookEx, WIN_STD_CALL_CONV,, <:HHOOK, :SDWORD, :WPARAM, :LPARAM>, 16
        ;*
        ;* Macros for source-level compatibility with old functions.
        ;*
        ifdef STRICT
          DefHookProc macro nCode, wParam, lParam, phhk
            exitm <CallNextHookEx (* phhk, nCode, wParam, lParam)>
          endm
        else
          DefHookProc macro nCode, wParam, lParam, phhk
            exitm <CallNextHookEx ((HHOOK) * phhk, nCode, wParam, lParam)>
          endm
          ;* STRICT *
        endif
        ;* !NOWH *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ifndef NOMENUS
      ;* ;win40  -- A lot of MF_* flags have been renamed as MFT_* and MFS_* flags *
      ;*
      ;* Menu flags for Add/Check/EnableMenuItem()
      ;*
      MF_INSERT equ 00000000h
      MF_CHANGE equ 00000080h
      MF_APPEND equ 00000100h
      MF_DELETE equ 00000200h
      MF_REMOVE equ 00001000h
      MF_BYCOMMAND equ 00000000h
      MF_BYPOSITION equ 00000400h
      MF_SEPARATOR equ 00000800h
      MF_ENABLED equ 00000000h
      MF_GRAYED equ 00000001h
      MF_DISABLED equ 00000002h
      MF_UNCHECKED equ 00000000h
      MF_CHECKED equ 00000008h
      MF_USECHECKBITMAPS equ 00000200h
      MF_STRING equ 00000000h
      MF_BITMAP equ 00000004h
      MF_OWNERDRAW equ 00000100h
      MF_POPUP equ 00000010h
      MF_MENUBARBREAK equ 00000020h
      MF_MENUBREAK equ 00000040h
      MF_UNHILITE equ 00000000h
      MF_HILITE equ 00000080h
      if (WINVER ge 0400h)
        MF_DEFAULT equ 00001000h
        ;* WINVER >= 0x0400 *
      endif
      MF_SYSMENU equ 00002000h
      MF_HELP equ 00004000h
      if (WINVER ge 0400h)
        MF_RIGHTJUSTIFY equ 00004000h
        ;* WINVER >= 0x0400 *
      endif
      MF_MOUSESELECT equ 00008000h
      if (WINVER ge 0400h)
        ;* Obsolete -- only used by old RES files *
        MF_END equ 00000080h
        ;* WINVER >= 0x0400 *
      endif
      if (WINVER ge 0400h)
        MFT_STRING equ <MF_STRING>
        MFT_BITMAP equ <MF_BITMAP>
        MFT_MENUBARBREAK equ <MF_MENUBARBREAK>
        MFT_MENUBREAK equ <MF_MENUBREAK>
        MFT_OWNERDRAW equ <MF_OWNERDRAW>
        MFT_RADIOCHECK equ 00000200h
        MFT_SEPARATOR equ <MF_SEPARATOR>
        MFT_RIGHTORDER equ 00002000h
        MFT_RIGHTJUSTIFY equ <MF_RIGHTJUSTIFY>
        ;* Menu flags for Add/Check/EnableMenuItem() *
        MFS_GRAYED equ 00000003h
        MFS_DISABLED equ <MFS_GRAYED>
        MFS_CHECKED equ <MF_CHECKED>
        MFS_HILITE equ <MF_HILITE>
        MFS_ENABLED equ <MF_ENABLED>
        MFS_UNCHECKED equ <MF_UNCHECKED>
        MFS_UNHILITE equ <MF_UNHILITE>
        MFS_DEFAULT equ <MF_DEFAULT>
        ;* WINVER >= 0x0400 *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        if (WINVER ge 0400h)
          @DefProto DllImport, CheckMenuRadioItem, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :UINT, :UINT, :UINT>, 20
          ;* WINVER >= 0x0400 *
        endif
        ;*
        ;* Menu item resource format
        ;*
        MENUITEMTEMPLATEHEADER struct
          versionNumber WORD ?
          offset_ WORD ?
        MENUITEMTEMPLATEHEADER ends
        PMENUITEMTEMPLATEHEADER typedef ptr MENUITEMTEMPLATEHEADER
        MENUITEMTEMPLATE struct
          ; version 0
          mtOption WORD ?
          mtID WORD ?
          mtString WORD 1 dup (?)
        MENUITEMTEMPLATE ends
        PMENUITEMTEMPLATE typedef ptr MENUITEMTEMPLATE
        MF_END equ 00000080h
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;* !NOMENUS *
    endif
    ifndef NOSYSCOMMANDS
      ;*
      ;* System Menu Command Values
      ;*
      SC_SIZE equ 0F000h
      SC_MOVE equ 0F010h
      SC_MINIMIZE equ 0F020h
      SC_MAXIMIZE equ 0F030h
      SC_NEXTWINDOW equ 0F040h
      SC_PREVWINDOW equ 0F050h
      SC_CLOSE equ 0F060h
      SC_VSCROLL equ 0F070h
      SC_HSCROLL equ 0F080h
      SC_MOUSEMENU equ 0F090h
      SC_KEYMENU equ 0F100h
      SC_ARRANGE equ 0F110h
      SC_RESTORE equ 0F120h
      SC_TASKLIST equ 0F130h
      SC_SCREENSAVE equ 0F140h
      SC_HOTKEY equ 0F150h
      if (WINVER ge 0400h)
        SC_DEFAULT equ 0F160h
        SC_MONITORPOWER equ 0F170h
        SC_CONTEXTHELP equ 0F180h
        SC_SEPARATOR equ 0F00Fh
        ;* WINVER >= 0x0400 *
      endif
      if (WINVER ge 0600h)
        SCF_ISSECURE equ 00000001h
        ;* WINVER >= 0x0600 *
      endif
      GET_SC_WPARAM macro wParam
        exitm <(wParam and 0FFF0h)>
      endm
      ;*
      ;* Obsolete names
      ;*
      SC_ICON equ <SC_MINIMIZE>
      SC_ZOOM equ <SC_MAXIMIZE>
      ;* !NOSYSCOMMANDS *
    endif
    ;*
    ;* Resource Loading Routines
    ;*
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, LoadBitmapA, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCSTR>, 8
      @DefProto DllImport, LoadBitmapW, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCWSTR>, 8
      ifdef UNICODE
        LoadBitmap equ <LoadBitmapW>
      else
        LoadBitmap equ <LoadBitmapA>
      endif
      ; !UNICODE
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, LoadCursorA, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCSTR>, 8
      @DefProto DllImport, LoadCursorW, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCWSTR>, 8
      ifdef UNICODE
        LoadCursor equ <LoadCursorW>
      else
        LoadCursor equ <LoadCursorA>
      endif
      ; !UNICODE
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, LoadCursorFromFileA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
      @DefProto DllImport, LoadCursorFromFileW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
      ifdef UNICODE
        LoadCursorFromFile equ <LoadCursorFromFileW>
      else
        LoadCursorFromFile equ <LoadCursorFromFileA>
      endif
      ; !UNICODE
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CreateCursor, WIN_STD_CALL_CONV,, <:HINSTANCE, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :ptr VOID, :ptr VOID>, 28
      @DefProto DllImport, DestroyCursor, WIN_STD_CALL_CONV,, <:HCURSOR>, 4
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_GAMES) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ifndef _MAC
        CopyCursor macro pcur
          exitm <(CopyIcon ((HICON) (pcur)))>
        endm
      else
        ;[...]
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ;*
    ;* Standard Cursor IDs
    ;*
    IDC_ARROW equ MAKEINTRESOURCE (32512)
    IDC_IBEAM equ MAKEINTRESOURCE (32513)
    IDC_WAIT equ MAKEINTRESOURCE (32514)
    IDC_CROSS equ MAKEINTRESOURCE (32515)
    IDC_UPARROW equ MAKEINTRESOURCE (32516)
    ;* OBSOLETE: use IDC_SIZEALL *
    IDC_SIZE equ MAKEINTRESOURCE (32640)
    ;* OBSOLETE: use IDC_ARROW *
    IDC_ICON equ MAKEINTRESOURCE (32641)
    IDC_SIZENWSE equ MAKEINTRESOURCE (32642)
    IDC_SIZENESW equ MAKEINTRESOURCE (32643)
    IDC_SIZEWE equ MAKEINTRESOURCE (32644)
    IDC_SIZENS equ MAKEINTRESOURCE (32645)
    IDC_SIZEALL equ MAKEINTRESOURCE (32646)
    ;*not in win3.1 *
    IDC_NO equ MAKEINTRESOURCE (32648)
    if (WINVER ge 0500h)
      IDC_HAND equ MAKEINTRESOURCE (32649)
      ;* WINVER >= 0x0500 *
    endif
    ;*not in win3.1 *
    IDC_APPSTARTING equ MAKEINTRESOURCE (32650)
    if (WINVER ge 0400h)
      IDC_HELP equ MAKEINTRESOURCE (32651)
      ;* WINVER >= 0x0400 *
    endif
    if (WINVER ge 0606h)
      IDC_PIN equ MAKEINTRESOURCE (32671)
      IDC_PERSON equ MAKEINTRESOURCE (32672)
      ;* WINVER >= 0x0606 *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, SetSystemCursor, WIN_STD_CALL_CONV,, <:HCURSOR, :DWORD>, 8
      ICONINFO struct
        fIcon DWORD ?
        xHotspot DWORD ?
        yHotspot DWORD ?
        hbmMask HBITMAP ?
        hbmColor HBITMAP ?
      ICONINFO ends
      _ICONINFO typedef ICONINFO
      PICONINFO typedef ptr ICONINFO
      @DefProto DllImport, LoadIconA, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCSTR>, 8
      @DefProto DllImport, LoadIconW, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCWSTR>, 8
      ifdef UNICODE
        LoadIcon equ <LoadIconW>
      else
        LoadIcon equ <LoadIconA>
      endif
      ; !UNICODE
      @DefProto DllImport, PrivateExtractIconsA, WIN_STD_CALL_CONV,, <:LPCSTR, :SDWORD, :SDWORD, :SDWORD, :ptr HICON, :ptr UINT, :UINT, :UINT>, 32
      @DefProto DllImport, PrivateExtractIconsW, WIN_STD_CALL_CONV,, <:LPCWSTR, :SDWORD, :SDWORD, :SDWORD, :ptr HICON, :ptr UINT, :UINT, :UINT>, 32
      ifdef UNICODE
        PrivateExtractIcons equ <PrivateExtractIconsW>
      else
        PrivateExtractIcons equ <PrivateExtractIconsA>
      endif
      ; !UNICODE
      @DefProto DllImport, CreateIcon, WIN_STD_CALL_CONV,, <:HINSTANCE, :SDWORD, :SDWORD, :BYTE, :BYTE, :ptr BYTE, :ptr BYTE>, 28
      @DefProto DllImport, DestroyIcon, WIN_STD_CALL_CONV,, <:HICON>, 4
      @DefProto DllImport, LookupIconIdFromDirectory, WIN_STD_CALL_CONV,, <:PBYTE, :BOOL>, 8
      if (WINVER ge 0400h)
        @DefProto DllImport, LookupIconIdFromDirectoryEx, WIN_STD_CALL_CONV,, <:PBYTE, :BOOL, :SDWORD, :SDWORD, :UINT>, 20
        ;* WINVER >= 0x0400 *
      endif
      @DefProto DllImport, CreateIconFromResource, WIN_STD_CALL_CONV,, <:PBYTE, :DWORD, :BOOL, :DWORD>, 16
      if (WINVER ge 0400h)
        @DefProto DllImport, CreateIconFromResourceEx, WIN_STD_CALL_CONV,, <:PBYTE, :DWORD, :BOOL, :DWORD, :SDWORD, :SDWORD, :UINT>, 28
        ;* Icon/Cursor header *
        CURSORSHAPE struct
          xHotSpot SDWORD ?
          yHotSpot SDWORD ?
          cx_ SDWORD ?
          cy SDWORD ?
          cbWidth SDWORD ?
          Planes BYTE ?
          BitsPixel BYTE ?
        CURSORSHAPE ends
        tagCURSORSHAPE typedef CURSORSHAPE
        LPCURSORSHAPE typedef ptr CURSORSHAPE
        ;* WINVER >= 0x0400 *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      if (NTDDI_VERSION ge NTDDI_WIN10_CO)
        CURSOR_CREATION_SCALING_NONE equ 1
        CURSOR_CREATION_SCALING_DEFAULT equ 2
        @DefProto DllImport, SetThreadCursorCreationScaling, WIN_STD_CALL_CONV,, <:UINT>, 4
        ;* NTDDI_VERSION >= NTDDI_WIN10_CO *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_GAMES) *
    endif
    IMAGE_BITMAP equ 0
    IMAGE_ICON equ 1
    IMAGE_CURSOR equ 2
    if (WINVER ge 0400h)
      IMAGE_ENHMETAFILE equ 3
      LR_DEFAULTCOLOR equ 00000000h
      LR_MONOCHROME equ 00000001h
      LR_COLOR equ 00000002h
      LR_COPYRETURNORG equ 00000004h
      LR_COPYDELETEORG equ 00000008h
      LR_LOADFROMFILE equ 00000010h
      LR_LOADTRANSPARENT equ 00000020h
      LR_DEFAULTSIZE equ 00000040h
      LR_VGACOLOR equ 00000080h
      LR_LOADMAP3DCOLORS equ 00001000h
      LR_CREATEDIBSECTION equ 00002000h
      LR_COPYFROMRESOURCE equ 00004000h
      LR_SHARED equ 00008000h
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, LoadImageA, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCSTR, :UINT, :SDWORD, :SDWORD, :UINT>, 24
        @DefProto DllImport, LoadImageW, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCWSTR, :UINT, :SDWORD, :SDWORD, :UINT>, 24
        ifdef UNICODE
          LoadImage equ <LoadImageW>
        else
          LoadImage equ <LoadImageA>
        endif
        ; !UNICODE
        @DefProto DllImport, CopyImage, WIN_STD_CALL_CONV,, <:HANDLE, :UINT, :SDWORD, :SDWORD, :UINT>, 20
        DI_MASK equ 0001h
        DI_IMAGE equ 0002h
        DI_NORMAL equ 0003h
        DI_COMPAT equ 0004h
        DI_DEFAULTSIZE equ 0008h
        if (_WIN32_WINNT ge 0501h)
          DI_NOMIRROR equ 0010h
          ;* _WIN32_WINNT >= 0x0501 *
        endif
        @DefProto DllImport, DrawIconEx, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :HICON, :SDWORD, :SDWORD, :UINT, :HBRUSH, :UINT>, 36
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;* WINVER >= 0x0400 *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, CreateIconIndirect, WIN_STD_CALL_CONV,, <:PICONINFO>, 4
      @DefProto DllImport, CopyIcon, WIN_STD_CALL_CONV,, <:HICON>, 4
      @DefProto DllImport, GetIconInfo, WIN_STD_CALL_CONV,, <:HICON, :PICONINFO>, 8
      if (_WIN32_WINNT ge 0600h)
        ICONINFOEXA struct
          cbSize DWORD ?
          fIcon DWORD ?
          xHotspot DWORD ?
          yHotspot DWORD ?
          hbmMask HBITMAP ?
          hbmColor HBITMAP ?
          wResID WORD ?
          szModName SBYTE MAX_PATH dup (?)
          szResName SBYTE MAX_PATH dup (?)
        ICONINFOEXA ends
        _ICONINFOEXA typedef ICONINFOEXA
        PICONINFOEXA typedef ptr ICONINFOEXA
        ICONINFOEXW struct
          cbSize DWORD ?
          fIcon DWORD ?
          xHotspot DWORD ?
          yHotspot DWORD ?
          hbmMask HBITMAP ?
          hbmColor HBITMAP ?
          wResID WORD ?
          szModName WORD MAX_PATH dup (?)
          szResName WORD MAX_PATH dup (?)
        ICONINFOEXW ends
        _ICONINFOEXW typedef ICONINFOEXW
        PICONINFOEXW typedef ptr ICONINFOEXW
        ifdef UNICODE
          ICONINFOEX typedef ICONINFOEXW
          PICONINFOEX typedef PICONINFOEXW
        else
          ICONINFOEX typedef ICONINFOEXA
          PICONINFOEX typedef PICONINFOEXA
        endif
        ; UNICODE
        @DefProto DllImport, GetIconInfoExA, WIN_STD_CALL_CONV,, <:HICON, :PICONINFOEXA>, 8
        @DefProto DllImport, GetIconInfoExW, WIN_STD_CALL_CONV,, <:HICON, :PICONINFOEXW>, 8
        ifdef UNICODE
          GetIconInfoEx equ <GetIconInfoExW>
        else
          GetIconInfoEx equ <GetIconInfoExA>
        endif
        ; !UNICODE
        ;* _WIN32_WINNT >= 0x0600 *
      endif
      if (WINVER ge 0400h)
        RES_ICON equ 1
        RES_CURSOR equ 2
        ;* WINVER >= 0x0400 *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ifdef OEMRESOURCE
      ;*
      ;* OEM Resource Ordinal Numbers
      ;*
      OBM_CLOSE equ 32754
      OBM_UPARROW equ 32753
      OBM_DNARROW equ 32752
      OBM_RGARROW equ 32751
      OBM_LFARROW equ 32750
      OBM_REDUCE equ 32749
      OBM_ZOOM equ 32748
      OBM_RESTORE equ 32747
      OBM_REDUCED equ 32746
      OBM_ZOOMD equ 32745
      OBM_RESTORED equ 32744
      OBM_UPARROWD equ 32743
      OBM_DNARROWD equ 32742
      OBM_RGARROWD equ 32741
      OBM_LFARROWD equ 32740
      OBM_MNARROW equ 32739
      OBM_COMBO equ 32738
      OBM_UPARROWI equ 32737
      OBM_DNARROWI equ 32736
      OBM_RGARROWI equ 32735
      OBM_LFARROWI equ 32734
      OBM_OLD_CLOSE equ 32767
      OBM_SIZE equ 32766
      OBM_OLD_UPARROW equ 32765
      OBM_OLD_DNARROW equ 32764
      OBM_OLD_RGARROW equ 32763
      OBM_OLD_LFARROW equ 32762
      OBM_BTSIZE equ 32761
      OBM_CHECK equ 32760
      OBM_CHECKBOXES equ 32759
      OBM_BTNCORNERS equ 32758
      OBM_OLD_REDUCE equ 32757
      OBM_OLD_ZOOM equ 32756
      OBM_OLD_RESTORE equ 32755
      OCR_NORMAL equ 32512
      OCR_IBEAM equ 32513
      OCR_WAIT equ 32514
      OCR_CROSS equ 32515
      OCR_UP equ 32516
      ;* OBSOLETE: use OCR_SIZEALL *
      OCR_SIZE equ 32640
      ;* OBSOLETE: use OCR_NORMAL *
      OCR_ICON equ 32641
      OCR_SIZENWSE equ 32642
      OCR_SIZENESW equ 32643
      OCR_SIZEWE equ 32644
      OCR_SIZENS equ 32645
      OCR_SIZEALL equ 32646
      ;* OBSOLETE: use OIC_WINLOGO *
      OCR_ICOCUR equ 32647
      OCR_NO equ 32648
      if (WINVER ge 0500h)
        OCR_HAND equ 32649
        ;* WINVER >= 0x0500 *
      endif
      if (WINVER ge 0400h)
        OCR_APPSTARTING equ 32650
        ;* WINVER >= 0x0400 *
      endif
      OIC_SAMPLE equ 32512
      OIC_HAND equ 32513
      OIC_QUES equ 32514
      OIC_BANG equ 32515
      OIC_NOTE equ 32516
      if (WINVER ge 0400h)
        OIC_WINLOGO equ 32517
        OIC_WARNING equ <OIC_BANG>
        OIC_ERROR equ <OIC_HAND>
        OIC_INFORMATION equ <OIC_NOTE>
        ;* WINVER >= 0x0400 *
      endif
      if (WINVER ge 0600h)
        OIC_SHIELD equ 32518
        ;* WINVER >= 0x0600 *
      endif
      ;* OEMRESOURCE *
    endif
    ; The ordinal number for the entry point of language drivers.
    ORD_LANGDRIVER equ 1
    ifndef NOICONS
      ;*
      ;* Standard Icon IDs
      ;*
      ifdef RC_INVOKED
        ;[...]
      else
        IDI_APPLICATION equ MAKEINTRESOURCE (32512)
        IDI_HAND equ MAKEINTRESOURCE (32513)
        IDI_QUESTION equ MAKEINTRESOURCE (32514)
        IDI_EXCLAMATION equ MAKEINTRESOURCE (32515)
        IDI_ASTERISK equ MAKEINTRESOURCE (32516)
        if (WINVER ge 0400h)
          IDI_WINLOGO equ MAKEINTRESOURCE (32517)
          ;* WINVER >= 0x0400 *
        endif
        if (WINVER ge 0600h)
          IDI_SHIELD equ MAKEINTRESOURCE (32518)
          ;* WINVER >= 0x0600 *
        endif
        ;* RC_INVOKED *
      endif
      if (WINVER ge 0400h)
        IDI_WARNING equ <IDI_EXCLAMATION>
        IDI_ERROR equ <IDI_HAND>
        IDI_INFORMATION equ <IDI_ASTERISK>
        ;* WINVER >= 0x0400 *
      endif
      ;* !NOICONS *
    endif
    ifdef NOAPISET
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, LoadStringA, WIN_STD_CALL_CONV,, <:HINSTANCE, :UINT, :LPSTR, :SDWORD>, 16
        @DefProto DllImport, LoadStringW, WIN_STD_CALL_CONV,, <:HINSTANCE, :UINT, :LPWSTR, :SDWORD>, 16
        ifdef UNICODE
          LoadString equ <LoadStringW>
        else
          LoadString equ <LoadStringA>
        endif
        ; !UNICODE
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
    endif
    ;*
    ;* Dialog Box Command IDs
    ;*
    IDOK equ 1
    IDCANCEL equ 2
    IDABORT equ 3
    IDRETRY equ 4
    IDIGNORE equ 5
    IDYES equ 6
    IDNO equ 7
    if (WINVER ge 0400h)
      IDCLOSE equ 8
      IDHELP equ 9
      ;* WINVER >= 0x0400 *
    endif
    if (WINVER ge 0500h)
      IDTRYAGAIN equ 10
      IDCONTINUE equ 11
      ;* WINVER >= 0x0500 *
    endif
    if (WINVER ge 0501h)
      ifndef IDTIMEOUT
        IDTIMEOUT equ 32000
      endif
      ;* WINVER >= 0x0501 *
    endif
    ifndef NOCTLMGR
      ;*
      ;* Control Manager Structures and Definitions
      ;*
      ifndef NOWINSTYLES
        ;*
        ;* Edit Control Styles
        ;*
        ES_LEFT equ 0000h
        ES_CENTER equ 0001h
        ES_RIGHT equ 0002h
        ES_MULTILINE equ 0004h
        ES_UPPERCASE equ 0008h
        ES_LOWERCASE equ 0010h
        ES_PASSWORD equ 0020h
        ES_AUTOVSCROLL equ 0040h
        ES_AUTOHSCROLL equ 0080h
        ES_NOHIDESEL equ 0100h
        ES_OEMCONVERT equ 0400h
        ES_READONLY equ 0800h
        ES_WANTRETURN equ 1000h
        if (WINVER ge 0400h)
          ES_NUMBER equ 2000h
          ;* WINVER >= 0x0400 *
        endif
        ;* !NOWINSTYLES *
      endif
      ;*
      ;* Edit Control Notification Codes
      ;*
      EN_SETFOCUS equ 0100h
      EN_KILLFOCUS equ 0200h
      EN_CHANGE equ 0300h
      EN_UPDATE equ 0400h
      EN_ERRSPACE equ 0500h
      EN_MAXTEXT equ 0501h
      EN_HSCROLL equ 0601h
      EN_VSCROLL equ 0602h
      if (_WIN32_WINNT ge 0500h)
        EN_ALIGN_LTR_EC equ 0700h
        EN_ALIGN_RTL_EC equ 0701h
        ;* _WIN32_WINNT >= 0x0500 *
      endif
      if (WINVER ge 0604h)
        EN_BEFORE_PASTE equ 0800h
        EN_AFTER_PASTE equ 0801h
        ;* WINVER >= 0x0604 *
      endif
      if (WINVER ge 0400h)
        ;* Edit control EM_SETMARGIN parameters *
        EC_LEFTMARGIN equ 0001h
        EC_RIGHTMARGIN equ 0002h
        EC_USEFONTINFO equ 0ffffh
        ;* WINVER >= 0x0400 *
      endif
      if (WINVER ge 0500h)
        ;* wParam of EM_GET/SETIMESTATUS  *
        EMSIS_COMPOSITIONSTRING equ 0001h
        ;* lParam for EMSIS_COMPOSITIONSTRING  *
        EIMES_GETCOMPSTRATONCE equ 0001h
        EIMES_CANCELCOMPSTRINFOCUS equ 0002h
        EIMES_COMPLETECOMPSTRKILLFOCUS equ 0004h
        ;* WINVER >= 0x0500 *
      endif
      ifndef NOWINMESSAGES
        ;*
        ;* Edit Control Messages
        ;*
        EM_GETSEL equ 00B0h
        EM_SETSEL equ 00B1h
        EM_GETRECT equ 00B2h
        EM_SETRECT equ 00B3h
        EM_SETRECTNP equ 00B4h
        EM_SCROLL equ 00B5h
        EM_LINESCROLL equ 00B6h
        EM_SCROLLCARET equ 00B7h
        EM_GETMODIFY equ 00B8h
        EM_SETMODIFY equ 00B9h
        EM_GETLINECOUNT equ 00BAh
        EM_LINEINDEX equ 00BBh
        EM_SETHANDLE equ 00BCh
        EM_GETHANDLE equ 00BDh
        EM_GETTHUMB equ 00BEh
        EM_LINELENGTH equ 00C1h
        EM_REPLACESEL equ 00C2h
        EM_GETLINE equ 00C4h
        EM_LIMITTEXT equ 00C5h
        EM_CANUNDO equ 00C6h
        EM_UNDO equ 00C7h
        EM_FMTLINES equ 00C8h
        EM_LINEFROMCHAR equ 00C9h
        EM_SETTABSTOPS equ 00CBh
        EM_SETPASSWORDCHAR equ 00CCh
        EM_EMPTYUNDOBUFFER equ 00CDh
        EM_GETFIRSTVISIBLELINE equ 00CEh
        EM_SETREADONLY equ 00CFh
        EM_SETWORDBREAKPROC equ 00D0h
        EM_GETWORDBREAKPROC equ 00D1h
        EM_GETPASSWORDCHAR equ 00D2h
        if (WINVER ge 0400h)
          EM_SETMARGINS equ 00D3h
          EM_GETMARGINS equ 00D4h
          ;* ;win40 Name change *
          EM_SETLIMITTEXT equ <EM_LIMITTEXT>
          EM_GETLIMITTEXT equ 00D5h
          EM_POSFROMCHAR equ 00D6h
          EM_CHARFROMPOS equ 00D7h
          ;* WINVER >= 0x0400 *
        endif
        if (WINVER ge 0500h)
          EM_SETIMESTATUS equ 00D8h
          EM_GETIMESTATUS equ 00D9h
          ;* WINVER >= 0x0500 *
        endif
        if (WINVER ge 0604h)
          EM_ENABLEFEATURE equ 00DAh
          ;* WINVER >= 0x0604 *
        endif
        ;* !NOWINMESSAGES *
      endif
      if (WINVER ge 0604h)
        ;*
        ;* EM_ENABLEFEATURE options
        ;*
        EDIT_CONTROL_FEATURE typedef SDWORD
        EDIT_CONTROL_FEATURE_ENTERPRISE_DATA_PROTECTION_PASTE_SUPPORT equ 0
        EDIT_CONTROL_FEATURE_PASTE_NOTIFICATIONS equ 1

        ;* WINVER >= 0x0604 *
      endif
      ;*
      ;* EDITWORDBREAKPROC code values
      ;*
      WB_LEFT equ 0
      WB_RIGHT equ 1
      WB_ISDELIMITER equ 2
      ;*
      ;* Button Control Styles
      ;*
      BS_PUSHBUTTON equ 00000000h
      BS_DEFPUSHBUTTON equ 00000001h
      BS_CHECKBOX equ 00000002h
      BS_AUTOCHECKBOX equ 00000003h
      BS_RADIOBUTTON equ 00000004h
      BS_3STATE equ 00000005h
      BS_AUTO3STATE equ 00000006h
      BS_GROUPBOX equ 00000007h
      BS_USERBUTTON equ 00000008h
      BS_AUTORADIOBUTTON equ 00000009h
      BS_PUSHBOX equ 0000000Ah
      BS_OWNERDRAW equ 0000000Bh
      BS_TYPEMASK equ 0000000Fh
      BS_LEFTTEXT equ 00000020h
      if (WINVER ge 0400h)
        BS_TEXT equ 00000000h
        BS_ICON equ 00000040h
        BS_BITMAP equ 00000080h
        BS_LEFT equ 00000100h
        BS_RIGHT equ 00000200h
        BS_CENTER equ 00000300h
        BS_TOP equ 00000400h
        BS_BOTTOM equ 00000800h
        BS_VCENTER equ 00000C00h
        BS_PUSHLIKE equ 00001000h
        BS_MULTILINE equ 00002000h
        BS_NOTIFY equ 00004000h
        BS_FLAT equ 00008000h
        BS_RIGHTBUTTON equ <BS_LEFTTEXT>
        ;* WINVER >= 0x0400 *
      endif
      ;*
      ;* User Button Notification Codes
      ;*
      BN_CLICKED equ 0
      BN_PAINT equ 1
      BN_HILITE equ 2
      BN_UNHILITE equ 3
      BN_DISABLE equ 4
      BN_DOUBLECLICKED equ 5
      if (WINVER ge 0400h)
        BN_PUSHED equ <BN_HILITE>
        BN_UNPUSHED equ <BN_UNHILITE>
        BN_DBLCLK equ <BN_DOUBLECLICKED>
        BN_SETFOCUS equ 6
        BN_KILLFOCUS equ 7
        ;* WINVER >= 0x0400 *
      endif
      ;*
      ;* Button Control Messages
      ;*
      BM_GETCHECK equ 00F0h
      BM_SETCHECK equ 00F1h
      BM_GETSTATE equ 00F2h
      BM_SETSTATE equ 00F3h
      BM_SETSTYLE equ 00F4h
      if (WINVER ge 0400h)
        BM_CLICK equ 00F5h
        BM_GETIMAGE equ 00F6h
        BM_SETIMAGE equ 00F7h
        ;* WINVER >= 0x0400 *
      endif
      if (WINVER ge 0600h)
        BM_SETDONTCLICK equ 00F8h
        ;* WINVER >= 0x0600 *
      endif
      if (WINVER ge 0400h)
        BST_UNCHECKED equ 0000h
        BST_CHECKED equ 0001h
        BST_INDETERMINATE equ 0002h
        BST_PUSHED equ 0004h
        BST_FOCUS equ 0008h
        ;* WINVER >= 0x0400 *
      endif
      ;*
      ;* Static Control Constants
      ;*
      SS_LEFT equ 00000000h
      SS_CENTER equ 00000001h
      SS_RIGHT equ 00000002h
      SS_ICON equ 00000003h
      SS_BLACKRECT equ 00000004h
      SS_GRAYRECT equ 00000005h
      SS_WHITERECT equ 00000006h
      SS_BLACKFRAME equ 00000007h
      SS_GRAYFRAME equ 00000008h
      SS_WHITEFRAME equ 00000009h
      SS_USERITEM equ 0000000Ah
      SS_SIMPLE equ 0000000Bh
      SS_LEFTNOWORDWRAP equ 0000000Ch
      if (WINVER ge 0400h)
        SS_OWNERDRAW equ 0000000Dh
        SS_BITMAP equ 0000000Eh
        SS_ENHMETAFILE equ 0000000Fh
        SS_ETCHEDHORZ equ 00000010h
        SS_ETCHEDVERT equ 00000011h
        SS_ETCHEDFRAME equ 00000012h
        SS_TYPEMASK equ 0000001Fh
        ;* WINVER >= 0x0400 *
      endif
      if (WINVER ge 0501h)
        SS_REALSIZECONTROL equ 00000040h
        ;* WINVER >= 0x0501 *
      endif
      ;* Don't do "&" character translation *
      SS_NOPREFIX equ 00000080h
      if (WINVER ge 0400h)
        SS_NOTIFY equ 00000100h
        SS_CENTERIMAGE equ 00000200h
        SS_RIGHTJUST equ 00000400h
        SS_REALSIZEIMAGE equ 00000800h
        SS_SUNKEN equ 00001000h
        SS_EDITCONTROL equ 00002000h
        SS_ENDELLIPSIS equ 00004000h
        SS_PATHELLIPSIS equ 00008000h
        SS_WORDELLIPSIS equ 0000C000h
        SS_ELLIPSISMASK equ 0000C000h
        ;* WINVER >= 0x0400 *
      endif
      ifndef NOWINMESSAGES
        ;*
        ;* Static Control Mesages
        ;*
        STM_SETICON equ 0170h
        STM_GETICON equ 0171h
        if (WINVER ge 0400h)
          STM_SETIMAGE equ 0172h
          STM_GETIMAGE equ 0173h
          STN_CLICKED equ 0
          STN_DBLCLK equ 1
          STN_ENABLE equ 2
          STN_DISABLE equ 3
          ;* WINVER >= 0x0400 *
        endif
        STM_MSGMAX equ 0174h
        ;* !NOWINMESSAGES *
      endif
      ;*
      ;* Dialog window class
      ;*
      WC_DIALOG equ (MAKEINTATOM(8002h))
      ;*
      ;* Get/SetWindowWord/Long offsets for use with WC_DIALOG windows
      ;*
      DWL_MSGRESULT equ 0
      DWL_DLGPROC equ 4
      DWL_USER equ 8
      ifdef _WIN64
        ;* _WIN64 *
      endif
      DWLP_MSGRESULT equ 0
      DWLP_DLGPROC equ <DWLP_MSGRESULT + sizeof(LRESULT)>
      DWLP_USER equ <DWLP_DLGPROC + sizeof(DLGPROC)>
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        ;*
        ;* Dialog Manager Routines
        ;*
        ifndef NOMSG
          @DefProto DllImport, IsDialogMessageA, WIN_STD_CALL_CONV,, <:HWND, :LPMSG>, 8
          @DefProto DllImport, IsDialogMessageW, WIN_STD_CALL_CONV,, <:HWND, :LPMSG>, 8
          ifdef UNICODE
            IsDialogMessage equ <IsDialogMessageW>
          else
            IsDialogMessage equ <IsDialogMessageA>
          endif
          ; !UNICODE
          ;* !NOMSG *
        endif
        @DefProto DllImport, MapDialogRect, WIN_STD_CALL_CONV,, <:HWND, :LPRECT>, 8
        @DefProto DllImport, DlgDirListA, WIN_STD_CALL_CONV,, <:HWND, :LPSTR, :SDWORD, :SDWORD, :UINT>, 20
        @DefProto DllImport, DlgDirListW, WIN_STD_CALL_CONV,, <:HWND, :LPWSTR, :SDWORD, :SDWORD, :UINT>, 20
        ifdef UNICODE
          DlgDirList equ <DlgDirListW>
        else
          DlgDirList equ <DlgDirListA>
        endif
        ; !UNICODE
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;*
      ;* DlgDirList, DlgDirListComboBox flags values
      ;*
      DDL_READWRITE equ 0000h
      DDL_READONLY equ 0001h
      DDL_HIDDEN equ 0002h
      DDL_SYSTEM equ 0004h
      DDL_DIRECTORY equ 0010h
      DDL_ARCHIVE equ 0020h
      DDL_POSTMSGS equ 2000h
      DDL_DRIVES equ 4000h
      DDL_EXCLUSIVE equ 8000h
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, DlgDirSelectExA, WIN_STD_CALL_CONV,, <:HWND, :LPSTR, :SDWORD, :SDWORD>, 16
        @DefProto DllImport, DlgDirSelectExW, WIN_STD_CALL_CONV,, <:HWND, :LPWSTR, :SDWORD, :SDWORD>, 16
        ifdef UNICODE
          DlgDirSelectEx equ <DlgDirSelectExW>
        else
          DlgDirSelectEx equ <DlgDirSelectExA>
        endif
        ; !UNICODE
        @DefProto DllImport, DlgDirListComboBoxA, WIN_STD_CALL_CONV,, <:HWND, :LPSTR, :SDWORD, :SDWORD, :UINT>, 20
        @DefProto DllImport, DlgDirListComboBoxW, WIN_STD_CALL_CONV,, <:HWND, :LPWSTR, :SDWORD, :SDWORD, :UINT>, 20
        ifdef UNICODE
          DlgDirListComboBox equ <DlgDirListComboBoxW>
        else
          DlgDirListComboBox equ <DlgDirListComboBoxA>
        endif
        ; !UNICODE
        @DefProto DllImport, DlgDirSelectComboBoxExA, WIN_STD_CALL_CONV,, <:HWND, :LPSTR, :SDWORD, :SDWORD>, 16
        @DefProto DllImport, DlgDirSelectComboBoxExW, WIN_STD_CALL_CONV,, <:HWND, :LPWSTR, :SDWORD, :SDWORD>, 16
        ifdef UNICODE
          DlgDirSelectComboBoxEx equ <DlgDirSelectComboBoxExW>
        else
          DlgDirSelectComboBoxEx equ <DlgDirSelectComboBoxExA>
        endif
        ; !UNICODE
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;*
      ;* Dialog Styles
      ;*
      DS_ABSALIGN equ 01h
      DS_SYSMODAL equ 02h
      ;* 16-bit: Edit items get Local storage. 32-bit and up: meaningless. *
      DS_LOCALEDIT equ 20h
      ;* User specified font for Dlg controls *
      DS_SETFONT equ 40h
      ;* Can be combined with WS_CAPTION  *
      DS_MODALFRAME equ 80h
      ;* WM_ENTERIDLE message will not be sent *
      DS_NOIDLEMSG equ 100h
      ;* not in win3.1 *
      DS_SETFOREGROUND equ 200h
      if (WINVER ge 0400h)
        DS_3DLOOK equ 0004h
        DS_FIXEDSYS equ 0008h
        DS_NOFAILCREATE equ 0010h
        DS_CONTROL equ 0400h
        DS_CENTER equ 0800h
        DS_CENTERMOUSE equ 1000h
        DS_CONTEXTHELP equ 2000h
        DS_SHELLFONT equ <(DS_SETFONT or DS_FIXEDSYS)>
        ;* WINVER >= 0x0400 *
      endif
      if Defined(_WIN32_WCE) and (_WIN32_WCE ge 0500h)
        DS_USEPIXELS equ 8000h
      endif
      DM_GETDEFID equ (WM_USER + 0)
      DM_SETDEFID equ (WM_USER + 1)
      if (WINVER ge 0400h)
        DM_REPOSITION equ (WM_USER + 2)
        ;* WINVER >= 0x0400 *
      endif
      ;*
      ;* Returned in HIWORD() of DM_GETDEFID result if msg is supported
      ;*
      DC_HASDEFID equ 534Bh
      ;*
      ;* Dialog Codes
      ;*
      ;* Control wants arrow keys         *
      DLGC_WANTARROWS equ 0001h
      ;* Control wants tab keys           *
      DLGC_WANTTAB equ 0002h
      ;* Control wants all keys           *
      DLGC_WANTALLKEYS equ 0004h
      ;* Pass message to control          *
      DLGC_WANTMESSAGE equ 0004h
      ;* Understands EM_SETSEL message    *
      DLGC_HASSETSEL equ 0008h
      ;* Default pushbutton               *
      DLGC_DEFPUSHBUTTON equ 0010h
      ;* Non-default pushbutton           *
      DLGC_UNDEFPUSHBUTTON equ 0020h
      ;* Radio button                     *
      DLGC_RADIOBUTTON equ 0040h
      ;* Want WM_CHAR messages            *
      DLGC_WANTCHARS equ 0080h
      ;* Static item: don't include       *
      DLGC_STATIC equ 0100h
      ;* Button item: can be checked      *
      DLGC_BUTTON equ 2000h
      LB_CTLCODE equ 0
      ;*
      ;* Listbox Return Values
      ;*
      LB_OKAY equ 0
      LB_ERR equ (- 1)
      LB_ERRSPACE equ (- 2)
      ;*
      ;**  The idStaticPath parameter to DlgDirList can have the following values
      ;**  ORed if the list box should show other details of the files along with
      ;**  the name of the files;
      ;*
      ;* all other details also will be returned *
      ;*
      ;* Listbox Notification Codes
      ;*
      LBN_ERRSPACE equ (- 2)
      LBN_SELCHANGE equ 1
      LBN_DBLCLK equ 2
      LBN_SELCANCEL equ 3
      LBN_SETFOCUS equ 4
      LBN_KILLFOCUS equ 5
      ifndef NOWINMESSAGES
        ;*
        ;* Listbox messages
        ;*
        LB_ADDSTRING equ 0180h
        LB_INSERTSTRING equ 0181h
        LB_DELETESTRING equ 0182h
        LB_SELITEMRANGEEX equ 0183h
        LB_RESETCONTENT equ 0184h
        LB_SETSEL equ 0185h
        LB_SETCURSEL equ 0186h
        LB_GETSEL equ 0187h
        LB_GETCURSEL equ 0188h
        LB_GETTEXT equ 0189h
        LB_GETTEXTLEN equ 018Ah
        LB_GETCOUNT equ 018Bh
        LB_SELECTSTRING equ 018Ch
        LB_DIR equ 018Dh
        LB_GETTOPINDEX equ 018Eh
        LB_FINDSTRING equ 018Fh
        LB_GETSELCOUNT equ 0190h
        LB_GETSELITEMS equ 0191h
        LB_SETTABSTOPS equ 0192h
        LB_GETHORIZONTALEXTENT equ 0193h
        LB_SETHORIZONTALEXTENT equ 0194h
        LB_SETCOLUMNWIDTH equ 0195h
        LB_ADDFILE equ 0196h
        LB_SETTOPINDEX equ 0197h
        LB_GETITEMRECT equ 0198h
        LB_GETITEMDATA equ 0199h
        LB_SETITEMDATA equ 019Ah
        LB_SELITEMRANGE equ 019Bh
        LB_SETANCHORINDEX equ 019Ch
        LB_GETANCHORINDEX equ 019Dh
        LB_SETCARETINDEX equ 019Eh
        LB_GETCARETINDEX equ 019Fh
        LB_SETITEMHEIGHT equ 01A0h
        LB_GETITEMHEIGHT equ 01A1h
        LB_FINDSTRINGEXACT equ 01A2h
        LB_SETLOCALE equ 01A5h
        LB_GETLOCALE equ 01A6h
        LB_SETCOUNT equ 01A7h
        if (WINVER ge 0400h)
          LB_INITSTORAGE equ 01A8h
          LB_ITEMFROMPOINT equ 01A9h
          ;* WINVER >= 0x0400 *
        endif
        if Defined(_WIN32_WCE) and (_WIN32_WCE ge 0400h)
          LB_MULTIPLEADDSTRING equ 01B1h
        endif
        if (_WIN32_WINNT ge 0501h)
          LB_GETLISTBOXINFO equ 01B2h
          ;* _WIN32_WINNT >= 0x0501 *
        endif
        if (_WIN32_WINNT ge 0501h)
          LB_MSGMAX equ 01B3h
        elseif Defined(_WIN32_WCE) and (_WIN32_WCE ge 0400h)
          LB_MSGMAX equ 01B1h
        elseif (WINVER ge 0400h)
          LB_MSGMAX equ 01B0h
        else
          LB_MSGMAX equ 01A8h
        endif
        ;* !NOWINMESSAGES *
      endif
      ifndef NOWINSTYLES
        ;*
        ;* Listbox Styles
        ;*
        LBS_NOTIFY equ 0001h
        LBS_SORT equ 0002h
        LBS_NOREDRAW equ 0004h
        LBS_MULTIPLESEL equ 0008h
        LBS_OWNERDRAWFIXED equ 0010h
        LBS_OWNERDRAWVARIABLE equ 0020h
        LBS_HASSTRINGS equ 0040h
        LBS_USETABSTOPS equ 0080h
        LBS_NOINTEGRALHEIGHT equ 0100h
        LBS_MULTICOLUMN equ 0200h
        LBS_WANTKEYBOARDINPUT equ 0400h
        LBS_EXTENDEDSEL equ 0800h
        LBS_DISABLENOSCROLL equ 1000h
        LBS_NODATA equ 2000h
        if (WINVER ge 0400h)
          LBS_NOSEL equ 4000h
          ;* WINVER >= 0x0400 *
        endif
        LBS_COMBOBOX equ 8000h
        LBS_STANDARD equ <(LBS_NOTIFY or LBS_SORT or WS_VSCROLL or WS_BORDER)>
        ;* !NOWINSTYLES *
      endif
      ;*
      ;* Combo Box return Values
      ;*
      CB_OKAY equ 0
      CB_ERR equ (- 1)
      CB_ERRSPACE equ (- 2)
      ;*
      ;* Combo Box Notification Codes
      ;*
      CBN_ERRSPACE equ (- 1)
      CBN_SELCHANGE equ 1
      CBN_DBLCLK equ 2
      CBN_SETFOCUS equ 3
      CBN_KILLFOCUS equ 4
      CBN_EDITCHANGE equ 5
      CBN_EDITUPDATE equ 6
      CBN_DROPDOWN equ 7
      CBN_CLOSEUP equ 8
      CBN_SELENDOK equ 9
      CBN_SELENDCANCEL equ 10
      ifndef NOWINSTYLES
        ;*
        ;* Combo Box styles
        ;*
        CBS_SIMPLE equ 0001h
        CBS_DROPDOWN equ 0002h
        CBS_DROPDOWNLIST equ 0003h
        CBS_OWNERDRAWFIXED equ 0010h
        CBS_OWNERDRAWVARIABLE equ 0020h
        CBS_AUTOHSCROLL equ 0040h
        CBS_OEMCONVERT equ 0080h
        CBS_SORT equ 0100h
        CBS_HASSTRINGS equ 0200h
        CBS_NOINTEGRALHEIGHT equ 0400h
        CBS_DISABLENOSCROLL equ 0800h
        if (WINVER ge 0400h)
          CBS_UPPERCASE equ 2000h
          CBS_LOWERCASE equ 4000h
          ;* WINVER >= 0x0400 *
        endif
        ;* !NOWINSTYLES *
      endif
      ;*
      ;* Combo Box messages
      ;*
      ifndef NOWINMESSAGES
        CB_GETEDITSEL equ 0140h
        CB_LIMITTEXT equ 0141h
        CB_SETEDITSEL equ 0142h
        CB_ADDSTRING equ 0143h
        CB_DELETESTRING equ 0144h
        CB_DIR equ 0145h
        CB_GETCOUNT equ 0146h
        CB_GETCURSEL equ 0147h
        CB_GETLBTEXT equ 0148h
        CB_GETLBTEXTLEN equ 0149h
        CB_INSERTSTRING equ 014Ah
        CB_RESETCONTENT equ 014Bh
        CB_FINDSTRING equ 014Ch
        CB_SELECTSTRING equ 014Dh
        CB_SETCURSEL equ 014Eh
        CB_SHOWDROPDOWN equ 014Fh
        CB_GETITEMDATA equ 0150h
        CB_SETITEMDATA equ 0151h
        CB_GETDROPPEDCONTROLRECT equ 0152h
        CB_SETITEMHEIGHT equ 0153h
        CB_GETITEMHEIGHT equ 0154h
        CB_SETEXTENDEDUI equ 0155h
        CB_GETEXTENDEDUI equ 0156h
        CB_GETDROPPEDSTATE equ 0157h
        CB_FINDSTRINGEXACT equ 0158h
        CB_SETLOCALE equ 0159h
        CB_GETLOCALE equ 015Ah
        if (WINVER ge 0400h)
          CB_GETTOPINDEX equ 015bh
          CB_SETTOPINDEX equ 015ch
          CB_GETHORIZONTALEXTENT equ 015dh
          CB_SETHORIZONTALEXTENT equ 015eh
          CB_GETDROPPEDWIDTH equ 015fh
          CB_SETDROPPEDWIDTH equ 0160h
          CB_INITSTORAGE equ 0161h
          if Defined(_WIN32_WCE) and (_WIN32_WCE ge 0400h)
            CB_MULTIPLEADDSTRING equ 0163h
          endif
          ;* WINVER >= 0x0400 *
        endif
        if (_WIN32_WINNT ge 0501h)
          CB_GETCOMBOBOXINFO equ 0164h
          ;* _WIN32_WINNT >= 0x0501 *
        endif
        if (_WIN32_WINNT ge 0501h)
          CB_MSGMAX equ 0165h
        elseif Defined(_WIN32_WCE) and (_WIN32_WCE ge 0400h)
          CB_MSGMAX equ 0163h
        elseif (WINVER ge 0400h)
          CB_MSGMAX equ 0162h
        else
          CB_MSGMAX equ 015Bh
        endif
        ;* !NOWINMESSAGES *
      endif
      ifndef NOWINSTYLES
        ;*
        ;* Scroll Bar Styles
        ;*
        SBS_HORZ equ 0000h
        SBS_VERT equ 0001h
        SBS_TOPALIGN equ 0002h
        SBS_LEFTALIGN equ 0002h
        SBS_BOTTOMALIGN equ 0004h
        SBS_RIGHTALIGN equ 0004h
        SBS_SIZEBOXTOPLEFTALIGN equ 0002h
        SBS_SIZEBOXBOTTOMRIGHTALIGN equ 0004h
        SBS_SIZEBOX equ 0008h
        if (WINVER ge 0400h)
          SBS_SIZEGRIP equ 0010h
          ;* WINVER >= 0x0400 *
        endif
        ;* !NOWINSTYLES *
      endif
      ;*
      ;* Scroll bar messages
      ;*
      ifndef NOWINMESSAGES
        ;*not in win3.1 *
        SBM_SETPOS equ 00E0h
        ;*not in win3.1 *
        SBM_GETPOS equ 00E1h
        ;*not in win3.1 *
        SBM_SETRANGE equ 00E2h
        ;*not in win3.1 *
        SBM_SETRANGEREDRAW equ 00E6h
        ;*not in win3.1 *
        SBM_GETRANGE equ 00E3h
        ;*not in win3.1 *
        SBM_ENABLE_ARROWS equ 00E4h
        if (WINVER ge 0400h)
          SBM_SETSCROLLINFO equ 00E9h
          SBM_GETSCROLLINFO equ 00EAh
          ;* WINVER >= 0x0400 *
        endif
        if (_WIN32_WINNT ge 0501h)
          SBM_GETSCROLLBARINFO equ 00EBh
          ;* _WIN32_WINNT >= 0x0501 *
        endif
        if (WINVER ge 0400h)
          SIF_RANGE equ 0001h
          SIF_PAGE equ 0002h
          SIF_POS equ 0004h
          SIF_DISABLENOSCROLL equ 0008h
          SIF_TRACKPOS equ 0010h
          SIF_ALL equ <(SIF_RANGE or SIF_PAGE or SIF_POS or SIF_TRACKPOS)>
          if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
            SCROLLINFO struct
              cbSize DWORD ?
              fMask DWORD ?
              nMin SDWORD ?
              nMax SDWORD ?
              nPage DWORD ?
              nPos SDWORD ?
              nTrackPos SDWORD ?
            SCROLLINFO ends
            tagSCROLLINFO typedef SCROLLINFO
            LPSCROLLINFO typedef ptr SCROLLINFO
            LPCSCROLLINFO typedef ptr SCROLLINFO
            @DefProto DllImport, SetScrollInfo, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LPCSCROLLINFO, :BOOL>, 16
            @DefProto DllImport, GetScrollInfo, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LPSCROLLINFO>, 12
            ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
          endif
          ;* WINVER >= 0x0400 *
        endif
        ;* !NOWINMESSAGES *
      endif
      ;* !NOCTLMGR *
    endif
    ifndef NOMDI
      ;*
      ;* MDI client style bits
      ;*
      MDIS_ALLCHILDSTYLES equ 0001h
      ;*
      ;* wParam Flags for WM_MDITILE and WM_MDICASCADE messages.
      ;*
      ;*not in win3.1 *
      MDITILE_VERTICAL equ 0000h
      ;*not in win3.1 *
      MDITILE_HORIZONTAL equ 0001h
      ;*not in win3.1 *
      MDITILE_SKIPDISABLED equ 0002h
      if (_WIN32_WINNT ge 0500h)
        MDITILE_ZORDER equ 0004h
        ;* _WIN32_WINNT >= 0x0500 *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        MDICREATESTRUCTA struct
          szClass =POINTER ?
          szTitle =POINTER ?
          hOwner HANDLE ?
          x SDWORD ?
          y SDWORD ?
          cx_ SDWORD ?
          cy SDWORD ?
          style DWORD ?
          lParam LPARAM ?
          ;* app-defined stuff *
        MDICREATESTRUCTA ends
        tagMDICREATESTRUCTA typedef MDICREATESTRUCTA
        LPMDICREATESTRUCTA typedef ptr MDICREATESTRUCTA
        MDICREATESTRUCTW struct
          szClass =POINTER ?
          szTitle =POINTER ?
          hOwner HANDLE ?
          x SDWORD ?
          y SDWORD ?
          cx_ SDWORD ?
          cy SDWORD ?
          style DWORD ?
          lParam LPARAM ?
          ;* app-defined stuff *
        MDICREATESTRUCTW ends
        tagMDICREATESTRUCTW typedef MDICREATESTRUCTW
        LPMDICREATESTRUCTW typedef ptr MDICREATESTRUCTW
        ifdef UNICODE
          MDICREATESTRUCT typedef MDICREATESTRUCTW
          LPMDICREATESTRUCT typedef LPMDICREATESTRUCTW
        else
          MDICREATESTRUCT typedef MDICREATESTRUCTA
          LPMDICREATESTRUCT typedef LPMDICREATESTRUCTA
        endif
        ; UNICODE
        CLIENTCREATESTRUCT struct
          hWindowMenu HANDLE ?
          idFirstChild DWORD ?
        CLIENTCREATESTRUCT ends
        tagCLIENTCREATESTRUCT typedef CLIENTCREATESTRUCT
        LPCLIENTCREATESTRUCT typedef ptr CLIENTCREATESTRUCT
        @DefProto DllImport, DefFrameProcA, WIN_STD_CALL_CONV,, <:HWND, :HWND, :UINT, :WPARAM, :LPARAM>, 20
        @DefProto DllImport, DefFrameProcW, WIN_STD_CALL_CONV,, <:HWND, :HWND, :UINT, :WPARAM, :LPARAM>, 20
        ifdef UNICODE
          DefFrameProc equ <DefFrameProcW>
        else
          DefFrameProc equ <DefFrameProcA>
        endif
        ; !UNICODE
        ifndef _MAC
        else
          ;[...]
        endif
        @DefProto DllImport, DefMDIChildProcA, WIN_STD_CALL_CONV,, <:HWND, :UINT, :WPARAM, :LPARAM>, 16
        ifndef _MAC
        else
          ;[...]
        endif
        @DefProto DllImport, DefMDIChildProcW, WIN_STD_CALL_CONV,, <:HWND, :UINT, :WPARAM, :LPARAM>, 16
        ifdef UNICODE
          DefMDIChildProc equ <DefMDIChildProcW>
        else
          DefMDIChildProc equ <DefMDIChildProcA>
        endif
        ; !UNICODE
        ifndef NOMSG
          @DefProto DllImport, TranslateMDISysAccel, WIN_STD_CALL_CONV,, <:HWND, :LPMSG>, 8
          ;* !NOMSG *
        endif
        @DefProto DllImport, ArrangeIconicWindows, WIN_STD_CALL_CONV,, <:HWND>, 4
        @DefProto DllImport, CreateMDIWindowA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :DWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :HWND, :HINSTANCE, :LPARAM>, 40
        @DefProto DllImport, CreateMDIWindowW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :DWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :HWND, :HINSTANCE, :LPARAM>, 40
        ifdef UNICODE
          CreateMDIWindow equ <CreateMDIWindowW>
        else
          CreateMDIWindow equ <CreateMDIWindowA>
        endif
        ; !UNICODE
        if (WINVER ge 0400h)
          @DefProto DllImport, TileWindows, WIN_STD_CALL_CONV,, <:HWND, :UINT, :ptr RECT, :UINT, :ptr HWND>, 20
          @DefProto DllImport, CascadeWindows, WIN_STD_CALL_CONV,, <:HWND, :UINT, :ptr RECT, :UINT, :ptr HWND>, 20
          ;* WINVER >= 0x0400 *
        endif
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;* !NOMDI *
    endif
    ;* !NOUSER *
  endif
  ;****** Help support ********************************************************
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef NOHELP
      HELPPOLY typedef DWORD
      MULTIKEYHELPA struct
        ifndef _MAC
          mkSize DWORD ?
        else
          ;[...]
        endif
        mkKeylist SBYTE ?
        szKeyphrase SBYTE 1 dup (?)
      MULTIKEYHELPA ends
      tagMULTIKEYHELPA typedef MULTIKEYHELPA
      PMULTIKEYHELPA typedef ptr MULTIKEYHELPA
      LPMULTIKEYHELPA typedef ptr MULTIKEYHELPA
      MULTIKEYHELPW struct
        ifndef _MAC
          mkSize DWORD ?
        else
          ;[...]
        endif
        mkKeylist WORD ?
        szKeyphrase WORD 1 dup (?)
      MULTIKEYHELPW ends
      tagMULTIKEYHELPW typedef MULTIKEYHELPW
      PMULTIKEYHELPW typedef ptr MULTIKEYHELPW
      LPMULTIKEYHELPW typedef ptr MULTIKEYHELPW
      ifdef UNICODE
        MULTIKEYHELP typedef MULTIKEYHELPW
        PMULTIKEYHELP typedef PMULTIKEYHELPW
        LPMULTIKEYHELP typedef LPMULTIKEYHELPW
      else
        MULTIKEYHELP typedef MULTIKEYHELPA
        PMULTIKEYHELP typedef PMULTIKEYHELPA
        LPMULTIKEYHELP typedef LPMULTIKEYHELPA
      endif
      ; UNICODE
      HELPWININFOA struct
        wStructSize SDWORD ?
        x SDWORD ?
        y SDWORD ?
        dx_ SDWORD ?
        dy SDWORD ?
        wMax SDWORD ?
        rgchMember SBYTE 2 dup (?)
      HELPWININFOA ends
      tagHELPWININFOA typedef HELPWININFOA
      PHELPWININFOA typedef ptr HELPWININFOA
      LPHELPWININFOA typedef ptr HELPWININFOA
      HELPWININFOW struct
        wStructSize SDWORD ?
        x SDWORD ?
        y SDWORD ?
        dx_ SDWORD ?
        dy SDWORD ?
        wMax SDWORD ?
        rgchMember WORD 2 dup (?)
      HELPWININFOW ends
      tagHELPWININFOW typedef HELPWININFOW
      PHELPWININFOW typedef ptr HELPWININFOW
      LPHELPWININFOW typedef ptr HELPWININFOW
      ifdef UNICODE
        HELPWININFO typedef HELPWININFOW
        PHELPWININFO typedef PHELPWININFOW
        LPHELPWININFO typedef LPHELPWININFOW
      else
        HELPWININFO typedef HELPWININFOA
        PHELPWININFO typedef PHELPWININFOA
        LPHELPWININFO typedef LPHELPWININFOA
      endif
      ; UNICODE
      ;*
      ;* Commands to pass to WinHelp()
      ;*
      ;* Display topic in ulTopic *
      HELP_CONTEXT equ 0001h
      ;* Terminate help *
      HELP_QUIT equ 0002h
      ;* Display index *
      HELP_INDEX equ 0003h
      HELP_CONTENTS equ 0003h
      ;* Display help on using help *
      HELP_HELPONHELP equ 0004h
      ;* Set current Index for multi index help *
      HELP_SETINDEX equ 0005h
      HELP_SETCONTENTS equ 0005h
      HELP_CONTEXTPOPUP equ 0008h
      HELP_FORCEFILE equ 0009h
      ;* Display topic for keyword in offabData *
      HELP_KEY equ 0101h
      HELP_COMMAND equ 0102h
      HELP_PARTIALKEY equ 0105h
      HELP_MULTIKEY equ 0201h
      HELP_SETWINPOS equ 0203h
      if (WINVER ge 0400h)
        HELP_CONTEXTMENU equ 000ah
        HELP_FINDER equ 000bh
        HELP_WM_HELP equ 000ch
        HELP_SETPOPUP_POS equ 000dh
        HELP_TCARD equ 8000h
        HELP_TCARD_DATA equ 0010h
        HELP_TCARD_OTHER_CALLER equ 0011h
        ; These are in winhelp.h in Win95.
        IDH_NO_HELP equ 28440
        IDH_MISSING_CONTEXT equ 28441; Control doesn't have matching help context

        IDH_GENERIC_HELP_BUTTON equ 28442; Property sheet help button

        IDH_OK equ 28443
        IDH_CANCEL equ 28444
        IDH_HELP equ 28445
        ;* WINVER >= 0x0400 *
      endif
      @DefProto DllImport, WinHelpA, WIN_STD_CALL_CONV,, <:HWND, :LPCSTR, :UINT, :ULONG_PTR>, 16
      @DefProto DllImport, WinHelpW, WIN_STD_CALL_CONV,, <:HWND, :LPCWSTR, :UINT, :ULONG_PTR>, 16
      ifdef UNICODE
        WinHelp equ <WinHelpW>
      else
        WinHelp equ <WinHelpA>
      endif
      ; !UNICODE
      ;* !NOHELP *
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  if (WINVER ge 0500h)
    ;* Count of GDI objects *
    GR_GDIOBJECTS equ 0
    ;* Count of USER objects *
    GR_USEROBJECTS equ 1
    ;* WINVER >= 0x0500 *
  endif
  if (WINVER ge 0601h)
    ;* Peak count of GDI objects *
    GR_GDIOBJECTS_PEAK equ 2
    ;* Peak count of USER objects *
    GR_USEROBJECTS_PEAK equ 4
    ;* WINVER >= 0x0601 *
  endif
  if (WINVER ge 0601h)
    GR_GLOBAL equ (- 2)
    ;* WINVER >= 0x0601 *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if (WINVER ge 0500h)
      @DefProto DllImport, GetGuiResources, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD>, 8
      ;* WINVER >= 0x0500 *
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  ifndef NOSYSPARAMSINFO
    ;*
    ;* Parameter for SystemParametersInfo.
    ;*
    SPI_GETBEEP equ 0001h
    SPI_SETBEEP equ 0002h
    SPI_GETMOUSE equ 0003h
    SPI_SETMOUSE equ 0004h
    SPI_GETBORDER equ 0005h
    SPI_SETBORDER equ 0006h
    SPI_GETKEYBOARDSPEED equ 000Ah
    SPI_SETKEYBOARDSPEED equ 000Bh
    SPI_LANGDRIVER equ 000Ch
    SPI_ICONHORIZONTALSPACING equ 000Dh
    SPI_GETSCREENSAVETIMEOUT equ 000Eh
    SPI_SETSCREENSAVETIMEOUT equ 000Fh
    SPI_GETSCREENSAVEACTIVE equ 0010h
    SPI_SETSCREENSAVEACTIVE equ 0011h
    SPI_GETGRIDGRANULARITY equ 0012h
    SPI_SETGRIDGRANULARITY equ 0013h
    SPI_SETDESKWALLPAPER equ 0014h
    SPI_SETDESKPATTERN equ 0015h
    SPI_GETKEYBOARDDELAY equ 0016h
    SPI_SETKEYBOARDDELAY equ 0017h
    SPI_ICONVERTICALSPACING equ 0018h
    SPI_GETICONTITLEWRAP equ 0019h
    SPI_SETICONTITLEWRAP equ 001Ah
    SPI_GETMENUDROPALIGNMENT equ 001Bh
    SPI_SETMENUDROPALIGNMENT equ 001Ch
    SPI_SETDOUBLECLKWIDTH equ 001Dh
    SPI_SETDOUBLECLKHEIGHT equ 001Eh
    SPI_GETICONTITLELOGFONT equ 001Fh
    SPI_SETDOUBLECLICKTIME equ 0020h
    SPI_SETMOUSEBUTTONSWAP equ 0021h
    SPI_SETICONTITLELOGFONT equ 0022h
    SPI_GETFASTTASKSWITCH equ 0023h
    SPI_SETFASTTASKSWITCH equ 0024h
    if (WINVER ge 0400h)
      SPI_SETDRAGFULLWINDOWS equ 0025h
      SPI_GETDRAGFULLWINDOWS equ 0026h
      SPI_GETNONCLIENTMETRICS equ 0029h
      SPI_SETNONCLIENTMETRICS equ 002Ah
      SPI_GETMINIMIZEDMETRICS equ 002Bh
      SPI_SETMINIMIZEDMETRICS equ 002Ch
      SPI_GETICONMETRICS equ 002Dh
      SPI_SETICONMETRICS equ 002Eh
      SPI_SETWORKAREA equ 002Fh
      SPI_GETWORKAREA equ 0030h
      SPI_SETPENWINDOWS equ 0031h
      SPI_GETHIGHCONTRAST equ 0042h
      SPI_SETHIGHCONTRAST equ 0043h
      SPI_GETKEYBOARDPREF equ 0044h
      SPI_SETKEYBOARDPREF equ 0045h
      SPI_GETSCREENREADER equ 0046h
      SPI_SETSCREENREADER equ 0047h
      SPI_GETANIMATION equ 0048h
      SPI_SETANIMATION equ 0049h
      SPI_GETFONTSMOOTHING equ 004Ah
      SPI_SETFONTSMOOTHING equ 004Bh
      SPI_SETDRAGWIDTH equ 004Ch
      SPI_SETDRAGHEIGHT equ 004Dh
      SPI_SETHANDHELD equ 004Eh
      SPI_GETLOWPOWERTIMEOUT equ 004Fh
      SPI_GETPOWEROFFTIMEOUT equ 0050h
      SPI_SETLOWPOWERTIMEOUT equ 0051h
      SPI_SETPOWEROFFTIMEOUT equ 0052h
      SPI_GETLOWPOWERACTIVE equ 0053h
      SPI_GETPOWEROFFACTIVE equ 0054h
      SPI_SETLOWPOWERACTIVE equ 0055h
      SPI_SETPOWEROFFACTIVE equ 0056h
      SPI_SETCURSORS equ 0057h
      SPI_SETICONS equ 0058h
      SPI_GETDEFAULTINPUTLANG equ 0059h
      SPI_SETDEFAULTINPUTLANG equ 005Ah
      SPI_SETLANGTOGGLE equ 005Bh
      SPI_GETWINDOWSEXTENSION equ 005Ch
      SPI_SETMOUSETRAILS equ 005Dh
      SPI_GETMOUSETRAILS equ 005Eh
      SPI_SETSCREENSAVERRUNNING equ 0061h
      SPI_SCREENSAVERRUNNING equ <SPI_SETSCREENSAVERRUNNING>
      ;* WINVER >= 0x0400 *
    endif
    SPI_GETFILTERKEYS equ 0032h
    SPI_SETFILTERKEYS equ 0033h
    SPI_GETTOGGLEKEYS equ 0034h
    SPI_SETTOGGLEKEYS equ 0035h
    SPI_GETMOUSEKEYS equ 0036h
    SPI_SETMOUSEKEYS equ 0037h
    SPI_GETSHOWSOUNDS equ 0038h
    SPI_SETSHOWSOUNDS equ 0039h
    SPI_GETSTICKYKEYS equ 003Ah
    SPI_SETSTICKYKEYS equ 003Bh
    SPI_GETACCESSTIMEOUT equ 003Ch
    SPI_SETACCESSTIMEOUT equ 003Dh
    if (WINVER ge 0400h)
      SPI_GETSERIALKEYS equ 003Eh
      SPI_SETSERIALKEYS equ 003Fh
      ;* WINVER >= 0x0400 *
    endif
    SPI_GETSOUNDSENTRY equ 0040h
    SPI_SETSOUNDSENTRY equ 0041h
    if (_WIN32_WINNT ge 0400h)
      SPI_GETSNAPTODEFBUTTON equ 005Fh
      SPI_SETSNAPTODEFBUTTON equ 0060h
      ;* _WIN32_WINNT >= 0x0400 *
    endif
    if (_WIN32_WINNT ge 0400h) or (_WIN32_WINDOWS gt 0400h)
      SPI_GETMOUSEHOVERWIDTH equ 0062h
      SPI_SETMOUSEHOVERWIDTH equ 0063h
      SPI_GETMOUSEHOVERHEIGHT equ 0064h
      SPI_SETMOUSEHOVERHEIGHT equ 0065h
      SPI_GETMOUSEHOVERTIME equ 0066h
      SPI_SETMOUSEHOVERTIME equ 0067h
      SPI_GETWHEELSCROLLLINES equ 0068h
      SPI_SETWHEELSCROLLLINES equ 0069h
      SPI_GETMENUSHOWDELAY equ 006Ah
      SPI_SETMENUSHOWDELAY equ 006Bh
      if (_WIN32_WINNT ge 0600h)
        SPI_GETWHEELSCROLLCHARS equ 006Ch
        SPI_SETWHEELSCROLLCHARS equ 006Dh
      endif
      SPI_GETSHOWIMEUI equ 006Eh
      SPI_SETSHOWIMEUI equ 006Fh
    endif
    if (WINVER ge 0500h)
      SPI_GETMOUSESPEED equ 0070h
      SPI_SETMOUSESPEED equ 0071h
      SPI_GETSCREENSAVERRUNNING equ 0072h
      SPI_GETDESKWALLPAPER equ 0073h
      ;* WINVER >= 0x0500 *
    endif
    if (WINVER ge 0600h)
      SPI_GETAUDIODESCRIPTION equ 0074h
      SPI_SETAUDIODESCRIPTION equ 0075h
      SPI_GETSCREENSAVESECURE equ 0076h
      SPI_SETSCREENSAVESECURE equ 0077h
      ;* WINVER >= 0x0600 *
    endif
    if (_WIN32_WINNT ge 0601h)
      SPI_GETHUNGAPPTIMEOUT equ 0078h
      SPI_SETHUNGAPPTIMEOUT equ 0079h
      SPI_GETWAITTOKILLTIMEOUT equ 007Ah
      SPI_SETWAITTOKILLTIMEOUT equ 007Bh
      SPI_GETWAITTOKILLSERVICETIMEOUT equ 007Ch
      SPI_SETWAITTOKILLSERVICETIMEOUT equ 007Dh
      SPI_GETMOUSEDOCKTHRESHOLD equ 007Eh
      SPI_SETMOUSEDOCKTHRESHOLD equ 007Fh
      SPI_GETPENDOCKTHRESHOLD equ 0080h
      SPI_SETPENDOCKTHRESHOLD equ 0081h
      SPI_GETWINARRANGING equ 0082h
      SPI_SETWINARRANGING equ 0083h
      SPI_GETMOUSEDRAGOUTTHRESHOLD equ 0084h
      SPI_SETMOUSEDRAGOUTTHRESHOLD equ 0085h
      SPI_GETPENDRAGOUTTHRESHOLD equ 0086h
      SPI_SETPENDRAGOUTTHRESHOLD equ 0087h
      SPI_GETMOUSESIDEMOVETHRESHOLD equ 0088h
      SPI_SETMOUSESIDEMOVETHRESHOLD equ 0089h
      SPI_GETPENSIDEMOVETHRESHOLD equ 008Ah
      SPI_SETPENSIDEMOVETHRESHOLD equ 008Bh
      SPI_GETDRAGFROMMAXIMIZE equ 008Ch
      SPI_SETDRAGFROMMAXIMIZE equ 008Dh
      SPI_GETSNAPSIZING equ 008Eh
      SPI_SETSNAPSIZING equ 008Fh
      SPI_GETDOCKMOVING equ 0090h
      SPI_SETDOCKMOVING equ 0091h
      ;* _WIN32_WINNT >= 0x0601 *
    endif
    if (WINVER ge 0602h)
      MAX_TOUCH_PREDICTION_FILTER_TAPS equ 3
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        TOUCHPREDICTIONPARAMETERS struct
          cbSize DWORD ?
          dwLatency DWORD ?
          ; Latency in millisecs
          dwSampleTime DWORD ?
          ; Sample time in millisecs (used to deduce velocity)
          bUseHWTimeStamp DWORD ?
          ; Use H/W TimeStamps
        TOUCHPREDICTIONPARAMETERS ends
        tagTouchPredictionParameters typedef TOUCHPREDICTIONPARAMETERS
        PTOUCHPREDICTIONPARAMETERS typedef ptr TOUCHPREDICTIONPARAMETERS
        TOUCHPREDICTIONPARAMETERS_DEFAULT_LATENCY equ 8
        TOUCHPREDICTIONPARAMETERS_DEFAULT_SAMPLETIME equ 8
        TOUCHPREDICTIONPARAMETERS_DEFAULT_USE_HW_TIMESTAMP equ 1
        TOUCHPREDICTIONPARAMETERS_DEFAULT_RLS_DELTA equ 0.001
        TOUCHPREDICTIONPARAMETERS_DEFAULT_RLS_LAMBDA_MIN equ 0.9
        TOUCHPREDICTIONPARAMETERS_DEFAULT_RLS_LAMBDA_MAX equ 0.999
        TOUCHPREDICTIONPARAMETERS_DEFAULT_RLS_LAMBDA_LEARNING_RATE equ 0.001
        TOUCHPREDICTIONPARAMETERS_DEFAULT_RLS_EXPO_SMOOTH_ALPHA equ 0.99
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      SPI_GETTOUCHPREDICTIONPARAMETERS equ 009Ch
      SPI_SETTOUCHPREDICTIONPARAMETERS equ 009Dh
      MAX_LOGICALDPIOVERRIDE equ 2
      MIN_LOGICALDPIOVERRIDE equ -2
      SPI_GETLOGICALDPIOVERRIDE equ 009Eh
      SPI_SETLOGICALDPIOVERRIDE equ 009Fh
      SPI_GETMENURECT equ 00A2h
      SPI_SETMENURECT equ 00A3h
      ;* WINVER >= 0x0602 *
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_19H1)
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_CO)
      ;* constants for SPI_{GET|SET}WAKEONINPUTDEVICETYPES *
    endif
    ; NTDDI_VERSION >= NTDDI_WIN10_CO
    if (WINVER ge 0500h)
      SPI_GETACTIVEWINDOWTRACKING equ 1000h
      SPI_SETACTIVEWINDOWTRACKING equ 1001h
      SPI_GETMENUANIMATION equ 1002h
      SPI_SETMENUANIMATION equ 1003h
      SPI_GETCOMBOBOXANIMATION equ 1004h
      SPI_SETCOMBOBOXANIMATION equ 1005h
      SPI_GETLISTBOXSMOOTHSCROLLING equ 1006h
      SPI_SETLISTBOXSMOOTHSCROLLING equ 1007h
      SPI_GETGRADIENTCAPTIONS equ 1008h
      SPI_SETGRADIENTCAPTIONS equ 1009h
      SPI_GETKEYBOARDCUES equ 100Ah
      SPI_SETKEYBOARDCUES equ 100Bh
      SPI_GETMENUUNDERLINES equ <SPI_GETKEYBOARDCUES>
      SPI_SETMENUUNDERLINES equ <SPI_SETKEYBOARDCUES>
      SPI_GETACTIVEWNDTRKZORDER equ 100Ch
      SPI_SETACTIVEWNDTRKZORDER equ 100Dh
      SPI_GETHOTTRACKING equ 100Eh
      SPI_SETHOTTRACKING equ 100Fh
      SPI_GETMENUFADE equ 1012h
      SPI_SETMENUFADE equ 1013h
      SPI_GETSELECTIONFADE equ 1014h
      SPI_SETSELECTIONFADE equ 1015h
      SPI_GETTOOLTIPANIMATION equ 1016h
      SPI_SETTOOLTIPANIMATION equ 1017h
      SPI_GETTOOLTIPFADE equ 1018h
      SPI_SETTOOLTIPFADE equ 1019h
      SPI_GETCURSORSHADOW equ 101Ah
      SPI_SETCURSORSHADOW equ 101Bh
      if (_WIN32_WINNT ge 0501h)
        SPI_GETMOUSESONAR equ 101Ch
        SPI_SETMOUSESONAR equ 101Dh
        SPI_GETMOUSECLICKLOCK equ 101Eh
        SPI_SETMOUSECLICKLOCK equ 101Fh
        SPI_GETMOUSEVANISH equ 1020h
        SPI_SETMOUSEVANISH equ 1021h
        SPI_GETFLATMENU equ 1022h
        SPI_SETFLATMENU equ 1023h
        SPI_GETDROPSHADOW equ 1024h
        SPI_SETDROPSHADOW equ 1025h
        SPI_GETBLOCKSENDINPUTRESETS equ 1026h
        SPI_SETBLOCKSENDINPUTRESETS equ 1027h
        ;* _WIN32_WINNT >= 0x0501 *
      endif
      SPI_GETUIEFFECTS equ 103Eh
      SPI_SETUIEFFECTS equ 103Fh
      if (_WIN32_WINNT ge 0600h)
        SPI_GETDISABLEOVERLAPPEDCONTENT equ 1040h
        SPI_SETDISABLEOVERLAPPEDCONTENT equ 1041h
        SPI_GETCLIENTAREAANIMATION equ 1042h
        SPI_SETCLIENTAREAANIMATION equ 1043h
        SPI_GETCLEARTYPE equ 1048h
        SPI_SETCLEARTYPE equ 1049h
        SPI_GETSPEECHRECOGNITION equ 104Ah
        SPI_SETSPEECHRECOGNITION equ 104Bh
        ;* _WIN32_WINNT >= 0x0600 *
      endif
      if (WINVER ge 0601h)
        SPI_GETCARETBROWSING equ 104Ch
        SPI_SETCARETBROWSING equ 104Dh
        SPI_GETTHREADLOCALINPUTSETTINGS equ 104Eh
        SPI_SETTHREADLOCALINPUTSETTINGS equ 104Fh
        SPI_GETSYSTEMLANGUAGEBAR equ 1050h
        SPI_SETSYSTEMLANGUAGEBAR equ 1051h
        ;* WINVER >= 0x0601 *
      endif
      if (NTDDI_VERSION ge NTDDI_WIN10_RS3)
      endif
      ; NTDDI_VERSION >= NTDDI_WIN10_RS3
      SPI_GETFOREGROUNDLOCKTIMEOUT equ 2000h
      SPI_SETFOREGROUNDLOCKTIMEOUT equ 2001h
      SPI_GETACTIVEWNDTRKTIMEOUT equ 2002h
      SPI_SETACTIVEWNDTRKTIMEOUT equ 2003h
      SPI_GETFOREGROUNDFLASHCOUNT equ 2004h
      SPI_SETFOREGROUNDFLASHCOUNT equ 2005h
      SPI_GETCARETWIDTH equ 2006h
      SPI_SETCARETWIDTH equ 2007h
      if (_WIN32_WINNT ge 0501h)
        SPI_GETMOUSECLICKLOCKTIME equ 2008h
        SPI_SETMOUSECLICKLOCKTIME equ 2009h
        SPI_GETFONTSMOOTHINGTYPE equ 200Ah
        SPI_SETFONTSMOOTHINGTYPE equ 200Bh
        ;* constants for SPI_GETFONTSMOOTHINGTYPE and SPI_SETFONTSMOOTHINGTYPE: *
        FE_FONTSMOOTHINGSTANDARD equ 0001h
        FE_FONTSMOOTHINGCLEARTYPE equ 0002h
        SPI_GETFONTSMOOTHINGCONTRAST equ 200Ch
        SPI_SETFONTSMOOTHINGCONTRAST equ 200Dh
        SPI_GETFOCUSBORDERWIDTH equ 200Eh
        SPI_SETFOCUSBORDERWIDTH equ 200Fh
        SPI_GETFOCUSBORDERHEIGHT equ 2010h
        SPI_SETFOCUSBORDERHEIGHT equ 2011h
        SPI_GETFONTSMOOTHINGORIENTATION equ 2012h
        SPI_SETFONTSMOOTHINGORIENTATION equ 2013h
        ;* constants for SPI_GETFONTSMOOTHINGORIENTATION and SPI_SETFONTSMOOTHINGORIENTATION: *
        FE_FONTSMOOTHINGORIENTATIONBGR equ 0000h
        FE_FONTSMOOTHINGORIENTATIONRGB equ 0001h
        ;* _WIN32_WINNT >= 0x0501 *
      endif
      if (_WIN32_WINNT ge 0600h)
        SPI_GETMINIMUMHITRADIUS equ 2014h
        SPI_SETMINIMUMHITRADIUS equ 2015h
        SPI_GETMESSAGEDURATION equ 2016h
        SPI_SETMESSAGEDURATION equ 2017h
        ;* _WIN32_WINNT >= 0x0600 *
      endif
      if (WINVER ge 0602h)
        SPI_GETCONTACTVISUALIZATION equ 2018h
        SPI_SETCONTACTVISUALIZATION equ 2019h
        ;* constants for SPI_GETCONTACTVISUALIZATION and SPI_SETCONTACTVISUALIZATION *
        CONTACTVISUALIZATION_OFF equ 0000h
        CONTACTVISUALIZATION_ON equ 0001h
        CONTACTVISUALIZATION_PRESENTATIONMODE equ 0002h
        SPI_GETGESTUREVISUALIZATION equ 201Ah
        SPI_SETGESTUREVISUALIZATION equ 201Bh
        ;* constants for SPI_GETGESTUREVISUALIZATION and SPI_SETGESTUREVISUALIZATION *
        GESTUREVISUALIZATION_OFF equ 0000h
        GESTUREVISUALIZATION_ON equ 001Fh
        GESTUREVISUALIZATION_TAP equ 0001h
        GESTUREVISUALIZATION_DOUBLETAP equ 0002h
        GESTUREVISUALIZATION_PRESSANDTAP equ 0004h
        GESTUREVISUALIZATION_PRESSANDHOLD equ 0008h
        GESTUREVISUALIZATION_RIGHTTAP equ 0010h
        ;* WINVER >= 0x0602 *
      endif
      if (WINVER ge 0602h)
        SPI_GETMOUSEWHEELROUTING equ 201Ch
        SPI_SETMOUSEWHEELROUTING equ 201Dh
        MOUSEWHEEL_ROUTING_FOCUS equ 0
        MOUSEWHEEL_ROUTING_HYBRID equ 1
        if (WINVER ge 0603h)
          MOUSEWHEEL_ROUTING_MOUSE_POS equ 2
          ;* WINVER >= 0x0603 *
        endif
        ;* WINVER >= 0x0602 *
      endif
      if (WINVER ge 0604h)
        SPI_GETPENVISUALIZATION equ 201Eh
        SPI_SETPENVISUALIZATION equ 201Fh
        ;* constants for SPI_{GET|SET}PENVISUALIZATION *
        PENVISUALIZATION_ON equ 0023h
        PENVISUALIZATION_OFF equ 0000h
        PENVISUALIZATION_TAP equ 0001h
        PENVISUALIZATION_DOUBLETAP equ 0002h
        PENVISUALIZATION_CURSOR equ 0020h
        SPI_GETPENARBITRATIONTYPE equ 2020h
        SPI_SETPENARBITRATIONTYPE equ 2021h
        ;* constants for SPI_{GET|SET}PENARBITRATIONTYPE *
        PENARBITRATIONTYPE_NONE equ 0000h
        PENARBITRATIONTYPE_WIN8 equ 0001h
        PENARBITRATIONTYPE_FIS equ 0002h
        PENARBITRATIONTYPE_SPT equ 0003h
        PENARBITRATIONTYPE_MAX equ 0004h
        ;* WINVER >= 0x0604 *
      endif
      if (NTDDI_VERSION ge NTDDI_WIN10_RS3)
        SPI_GETCARETTIMEOUT equ 2022h
        SPI_SETCARETTIMEOUT equ 2023h
      endif
      ; NTDDI_VERSION >= NTDDI_WIN10_RS3
      if (NTDDI_VERSION ge NTDDI_WIN10_RS4)
        SPI_GETHANDEDNESS equ 2024h
        SPI_SETHANDEDNESS equ 2025h
        HANDEDNESS typedef SDWORD
        HANDEDNESS_LEFT equ 0
        HANDEDNESS_RIGHT equ 1
        tagHANDEDNESS typedef HANDEDNESS
        PHANDEDNESS typedef ptr HANDEDNESS
      endif
      ; NTDDI_VERSION >= NTDDI_WIN10_RS4
      ;* WINVER >= 0x0500 *
    endif
    ;*
    ;* Flags
    ;*
    SPIF_UPDATEINIFILE equ 0001h
    SPIF_SENDWININICHANGE equ 0002h
    SPIF_SENDCHANGE equ <SPIF_SENDWININICHANGE>
    METRICS_USEDEFAULT equ -1
    ifdef _WINGDI_
      ifndef NOGDI
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
          NONCLIENTMETRICSA struct
            cbSize DWORD ?
            iBorderWidth SDWORD ?
            iScrollWidth SDWORD ?
            iScrollHeight SDWORD ?
            iCaptionWidth SDWORD ?
            iCaptionHeight SDWORD ?
            lfCaptionFont LOGFONTA <>
            iSmCaptionWidth SDWORD ?
            iSmCaptionHeight SDWORD ?
            lfSmCaptionFont LOGFONTA <>
            iMenuWidth SDWORD ?
            iMenuHeight SDWORD ?
            lfMenuFont LOGFONTA <>
            lfStatusFont LOGFONTA <>
            lfMessageFont LOGFONTA <>
            if (WINVER ge 0600h)
              iPaddedBorderWidth SDWORD ?
              ;* WINVER >= 0x0600 *
            endif
          NONCLIENTMETRICSA ends
          tagNONCLIENTMETRICSA typedef NONCLIENTMETRICSA
          PNONCLIENTMETRICSA typedef ptr NONCLIENTMETRICSA
          LPNONCLIENTMETRICSA typedef ptr NONCLIENTMETRICSA
          NONCLIENTMETRICSW struct
            cbSize DWORD ?
            iBorderWidth SDWORD ?
            iScrollWidth SDWORD ?
            iScrollHeight SDWORD ?
            iCaptionWidth SDWORD ?
            iCaptionHeight SDWORD ?
            lfCaptionFont LOGFONTW <>
            iSmCaptionWidth SDWORD ?
            iSmCaptionHeight SDWORD ?
            lfSmCaptionFont LOGFONTW <>
            iMenuWidth SDWORD ?
            iMenuHeight SDWORD ?
            lfMenuFont LOGFONTW <>
            lfStatusFont LOGFONTW <>
            lfMessageFont LOGFONTW <>
            if (WINVER ge 0600h)
              iPaddedBorderWidth SDWORD ?
              ;* WINVER >= 0x0600 *
            endif
          NONCLIENTMETRICSW ends
          tagNONCLIENTMETRICSW typedef NONCLIENTMETRICSW
          PNONCLIENTMETRICSW typedef ptr NONCLIENTMETRICSW
          LPNONCLIENTMETRICSW typedef ptr NONCLIENTMETRICSW
          ifdef UNICODE
            NONCLIENTMETRICS typedef NONCLIENTMETRICSW
            PNONCLIENTMETRICS typedef PNONCLIENTMETRICSW
            LPNONCLIENTMETRICS typedef LPNONCLIENTMETRICSW
          else
            NONCLIENTMETRICS typedef NONCLIENTMETRICSA
            PNONCLIENTMETRICS typedef PNONCLIENTMETRICSA
            LPNONCLIENTMETRICS typedef LPNONCLIENTMETRICSA
          endif
          ; UNICODE
          ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
        endif
        ;* NOGDI *
      endif
      ;* _WINGDI_ *
    endif
    ARW_BOTTOMLEFT equ 0000h
    ARW_BOTTOMRIGHT equ 0001h
    ARW_TOPLEFT equ 0002h
    ARW_TOPRIGHT equ 0003h
    ARW_STARTMASK equ 0003h
    ARW_STARTRIGHT equ 0001h
    ARW_STARTTOP equ 0002h
    ARW_LEFT equ 0000h
    ARW_RIGHT equ 0000h
    ARW_UP equ 0004h
    ARW_DOWN equ 0004h
    ARW_HIDE equ 0008h
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      MINIMIZEDMETRICS struct
        cbSize DWORD ?
        iWidth SDWORD ?
        iHorzGap SDWORD ?
        iVertGap SDWORD ?
        iArrange SDWORD ?
      MINIMIZEDMETRICS ends
      tagMINIMIZEDMETRICS typedef MINIMIZEDMETRICS
      PMINIMIZEDMETRICS typedef ptr MINIMIZEDMETRICS
      LPMINIMIZEDMETRICS typedef ptr MINIMIZEDMETRICS
      ifdef _WINGDI_
        ifndef NOGDI
          ICONMETRICSA struct
            cbSize DWORD ?
            iHorzSpacing SDWORD ?
            iVertSpacing SDWORD ?
            iTitleWrap SDWORD ?
            lfFont LOGFONTA <>
          ICONMETRICSA ends
          tagICONMETRICSA typedef ICONMETRICSA
          PICONMETRICSA typedef ptr ICONMETRICSA
          LPICONMETRICSA typedef ptr ICONMETRICSA
          ICONMETRICSW struct
            cbSize DWORD ?
            iHorzSpacing SDWORD ?
            iVertSpacing SDWORD ?
            iTitleWrap SDWORD ?
            lfFont LOGFONTW <>
          ICONMETRICSW ends
          tagICONMETRICSW typedef ICONMETRICSW
          PICONMETRICSW typedef ptr ICONMETRICSW
          LPICONMETRICSW typedef ptr ICONMETRICSW
          ifdef UNICODE
            ICONMETRICS typedef ICONMETRICSW
            PICONMETRICS typedef PICONMETRICSW
            LPICONMETRICS typedef LPICONMETRICSW
          else
            ICONMETRICS typedef ICONMETRICSA
            PICONMETRICS typedef PICONMETRICSA
            LPICONMETRICS typedef LPICONMETRICSA
          endif
          ; UNICODE
          ;* NOGDI *
        endif
        ;* _WINGDI_ *
      endif
      ANIMATIONINFO struct
        cbSize DWORD ?
        iMinAnimate SDWORD ?
      ANIMATIONINFO ends
      tagANIMATIONINFO typedef ANIMATIONINFO
      LPANIMATIONINFO typedef ptr ANIMATIONINFO
      SERIALKEYSA struct
        cbSize DWORD ?
        dwFlags DWORD ?
        lpszActivePort POINTER ?
        lpszPort POINTER ?
        iBaudRate DWORD ?
        iPortState DWORD ?
        iActive DWORD ?
      SERIALKEYSA ends
      tagSERIALKEYSA typedef SERIALKEYSA
      LPSERIALKEYSA typedef ptr SERIALKEYSA
      SERIALKEYSW struct
        cbSize DWORD ?
        dwFlags DWORD ?
        lpszActivePort POINTER ?
        lpszPort POINTER ?
        iBaudRate DWORD ?
        iPortState DWORD ?
        iActive DWORD ?
      SERIALKEYSW ends
      tagSERIALKEYSW typedef SERIALKEYSW
      LPSERIALKEYSW typedef ptr SERIALKEYSW
      ifdef UNICODE
        SERIALKEYS typedef SERIALKEYSW
        LPSERIALKEYS typedef LPSERIALKEYSW
      else
        SERIALKEYS typedef SERIALKEYSA
        LPSERIALKEYS typedef LPSERIALKEYSA
      endif
      ; UNICODE
      ;* flags for SERIALKEYS dwFlags field *
      SERKF_SERIALKEYSON equ 00000001h
      SERKF_AVAILABLE equ 00000002h
      SERKF_INDICATOR equ 00000004h
      HIGHCONTRASTA struct
        cbSize DWORD ?
        dwFlags DWORD ?
        lpszDefaultScheme POINTER ?
      HIGHCONTRASTA ends
      tagHIGHCONTRASTA typedef HIGHCONTRASTA
      LPHIGHCONTRASTA typedef ptr HIGHCONTRASTA
      HIGHCONTRASTW struct
        cbSize DWORD ?
        dwFlags DWORD ?
        lpszDefaultScheme POINTER ?
      HIGHCONTRASTW ends
      tagHIGHCONTRASTW typedef HIGHCONTRASTW
      LPHIGHCONTRASTW typedef ptr HIGHCONTRASTW
      ifdef UNICODE
        HIGHCONTRAST typedef HIGHCONTRASTW
        LPHIGHCONTRAST typedef LPHIGHCONTRASTW
      else
        HIGHCONTRAST typedef HIGHCONTRASTA
        LPHIGHCONTRAST typedef LPHIGHCONTRASTA
      endif
      ; UNICODE
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ;* flags for HIGHCONTRAST dwFlags field *
    HCF_HIGHCONTRASTON equ 00000001h
    HCF_AVAILABLE equ 00000002h
    HCF_HOTKEYACTIVE equ 00000004h
    HCF_CONFIRMHOTKEY equ 00000008h
    HCF_HOTKEYSOUND equ 00000010h
    HCF_INDICATOR equ 00000020h
    HCF_HOTKEYAVAILABLE equ 00000040h
    HCF_LOGONDESKTOP equ 00000100h
    HCF_DEFAULTDESKTOP equ 00000200h
    HCF_OPTION_NOTHEMECHANGE equ 00001000h
    ;* Flags for ChangeDisplaySettings *
    CDS_UPDATEREGISTRY equ 00000001h
    CDS_TEST equ 00000002h
    CDS_FULLSCREEN equ 00000004h
    CDS_GLOBAL equ 00000008h
    CDS_SET_PRIMARY equ 00000010h
    CDS_VIDEOPARAMETERS equ 00000020h
    if (WINVER ge 0600h)
      CDS_ENABLE_UNSAFE_MODES equ 00000100h
      CDS_DISABLE_UNSAFE_MODES equ 00000200h
      ;* WINVER >= 0x0600 *
    endif
    CDS_RESET equ 40000000h
    CDS_RESET_EX equ 20000000h
    CDS_NORESET equ 10000000h
    include tvout.inc
    ;* Return values for ChangeDisplaySettings *
    DISP_CHANGE_SUCCESSFUL equ 0
    DISP_CHANGE_RESTART equ 1
    DISP_CHANGE_FAILED equ -1
    DISP_CHANGE_BADMODE equ -2
    DISP_CHANGE_NOTUPDATED equ -3
    DISP_CHANGE_BADFLAGS equ -4
    DISP_CHANGE_BADPARAM equ -5
    if (_WIN32_WINNT ge 0501h)
      DISP_CHANGE_BADDUALVIEW equ -6
      ;* _WIN32_WINNT >= 0x0501 *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ifdef _WINGDI_
        ifndef NOGDI
          @DefProto DllImport, ChangeDisplaySettingsA, WIN_STD_CALL_CONV,, <:ptr DEVMODEA, :DWORD>, 8
          @DefProto DllImport, ChangeDisplaySettingsW, WIN_STD_CALL_CONV,, <:ptr DEVMODEW, :DWORD>, 8
          ifdef UNICODE
            ChangeDisplaySettings equ <ChangeDisplaySettingsW>
          else
            ChangeDisplaySettings equ <ChangeDisplaySettingsA>
          endif
          ; !UNICODE
          @DefProto DllImport, ChangeDisplaySettingsExA, WIN_STD_CALL_CONV,, <:LPCSTR, :ptr DEVMODEA, :HWND, :DWORD, :LPVOID>, 20
          @DefProto DllImport, ChangeDisplaySettingsExW, WIN_STD_CALL_CONV,, <:LPCWSTR, :ptr DEVMODEW, :HWND, :DWORD, :LPVOID>, 20
          ifdef UNICODE
            ChangeDisplaySettingsEx equ <ChangeDisplaySettingsExW>
          else
            ChangeDisplaySettingsEx equ <ChangeDisplaySettingsExA>
          endif
          ; !UNICODE
          ENUM_CURRENT_SETTINGS equ (- 1)
          ENUM_REGISTRY_SETTINGS equ (- 2)
          @DefProto DllImport, EnumDisplaySettingsA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :ptr DEVMODEA>, 12
          @DefProto DllImport, EnumDisplaySettingsW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :ptr DEVMODEW>, 12
          ifdef UNICODE
            EnumDisplaySettings equ <EnumDisplaySettingsW>
          else
            EnumDisplaySettings equ <EnumDisplaySettingsA>
          endif
          ; !UNICODE
          if (WINVER ge 0500h)
            @DefProto DllImport, EnumDisplaySettingsExA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :ptr DEVMODEA, :DWORD>, 16
            @DefProto DllImport, EnumDisplaySettingsExW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :ptr DEVMODEW, :DWORD>, 16
            ifdef UNICODE
              EnumDisplaySettingsEx equ <EnumDisplaySettingsExW>
            else
              EnumDisplaySettingsEx equ <EnumDisplaySettingsExA>
            endif
            ; !UNICODE
            ;* Flags for EnumDisplaySettingsEx *
            EDS_RAWMODE equ 00000002h
            EDS_ROTATEDMODE equ 00000004h
            @DefProto DllImport, EnumDisplayDevicesA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :PDISPLAY_DEVICEA, :DWORD>, 16
            @DefProto DllImport, EnumDisplayDevicesW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :PDISPLAY_DEVICEW, :DWORD>, 16
            ifdef UNICODE
              EnumDisplayDevices equ <EnumDisplayDevicesW>
            else
              EnumDisplayDevices equ <EnumDisplayDevicesA>
            endif
            ; !UNICODE
            ;* Flags for EnumDisplayDevices *
            EDD_GET_DEVICE_INTERFACE_NAME equ 00000001h
            ;* WINVER >= 0x0500 *
          endif
          if (WINVER ge 0601h)
            @DefProto DllImport, GetDisplayConfigBufferSizes, WIN_STD_CALL_CONV,, <:UINT32, :ptr UINT32, :ptr UINT32>, 12
            @DefProto DllImport, SetDisplayConfig, WIN_STD_CALL_CONV,, <:UINT32, :ptr DISPLAYCONFIG_PATH_INFO, :UINT32, :ptr DISPLAYCONFIG_MODE_INFO, :UINT32>, 20
            @DefProto DllImport, QueryDisplayConfig, WIN_STD_CALL_CONV,, <:UINT32, :ptr UINT32, :ptr DISPLAYCONFIG_PATH_INFO, :ptr UINT32, :ptr DISPLAYCONFIG_MODE_INFO, :ptr DISPLAYCONFIG_TOPOLOGY_ID>, 24
            @DefProto DllImport, DisplayConfigGetDeviceInfo, WIN_STD_CALL_CONV,, <:ptr DISPLAYCONFIG_DEVICE_INFO_HEADER>, 4
            @DefProto DllImport, DisplayConfigSetDeviceInfo, WIN_STD_CALL_CONV,, <:ptr DISPLAYCONFIG_DEVICE_INFO_HEADER>, 4
            ;* WINVER >= 0x0601 *
          endif
          ;* NOGDI *
        endif
        ;* _WINGDI_ *
      endif
      @DefProto DllImport, SystemParametersInfoA, WIN_STD_CALL_CONV,, <:UINT, :UINT, :PVOID, :UINT>, 16
      @DefProto DllImport, SystemParametersInfoW, WIN_STD_CALL_CONV,, <:UINT, :UINT, :PVOID, :UINT>, 16
      ifdef UNICODE
        SystemParametersInfo equ <SystemParametersInfoW>
      else
        SystemParametersInfo equ <SystemParametersInfoA>
      endif
      ; !UNICODE
      if (WINVER ge 0605h)
        @DefProto DllImport, SystemParametersInfoForDpi, WIN_STD_CALL_CONV,, <:UINT, :UINT, :PVOID, :UINT, :UINT>, 20
        ;* WINVER >= 0x0605 *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ;* !NOSYSPARAMSINFO  *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ;*
    ;* Accessibility support
    ;*
    FILTERKEYS struct
      cbSize DWORD ?
      dwFlags DWORD ?
      iWaitMSec DWORD ?
      ; Acceptance Delay
      iDelayMSec DWORD ?
      ; Delay Until Repeat
      iRepeatMSec DWORD ?
      ; Repeat Rate
      iBounceMSec DWORD ?
      ; Debounce Time
    FILTERKEYS ends
    tagFILTERKEYS typedef FILTERKEYS
    LPFILTERKEYS typedef ptr FILTERKEYS
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  ;*
  ;* FILTERKEYS dwFlags field
  ;*
  FKF_FILTERKEYSON equ 00000001h
  FKF_AVAILABLE equ 00000002h
  FKF_HOTKEYACTIVE equ 00000004h
  FKF_CONFIRMHOTKEY equ 00000008h
  FKF_HOTKEYSOUND equ 00000010h
  FKF_INDICATOR equ 00000020h
  FKF_CLICKON equ 00000040h
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    STICKYKEYS struct
      cbSize DWORD ?
      dwFlags DWORD ?
    STICKYKEYS ends
    tagSTICKYKEYS typedef STICKYKEYS
    LPSTICKYKEYS typedef ptr STICKYKEYS
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  ;*
  ;* STICKYKEYS dwFlags field
  ;*
  SKF_STICKYKEYSON equ 00000001h
  SKF_AVAILABLE equ 00000002h
  SKF_HOTKEYACTIVE equ 00000004h
  SKF_CONFIRMHOTKEY equ 00000008h
  SKF_HOTKEYSOUND equ 00000010h
  SKF_INDICATOR equ 00000020h
  SKF_AUDIBLEFEEDBACK equ 00000040h
  SKF_TRISTATE equ 00000080h
  SKF_TWOKEYSOFF equ 00000100h
  if (_WIN32_WINNT ge 0500h)
    SKF_LALTLATCHED equ 10000000h
    SKF_LCTLLATCHED equ 04000000h
    SKF_LSHIFTLATCHED equ 01000000h
    SKF_RALTLATCHED equ 20000000h
    SKF_RCTLLATCHED equ 08000000h
    SKF_RSHIFTLATCHED equ 02000000h
    SKF_LWINLATCHED equ 40000000h
    SKF_RWINLATCHED equ 80000000h
    SKF_LALTLOCKED equ 00100000h
    SKF_LCTLLOCKED equ 00040000h
    SKF_LSHIFTLOCKED equ 00010000h
    SKF_RALTLOCKED equ 00200000h
    SKF_RCTLLOCKED equ 00080000h
    SKF_RSHIFTLOCKED equ 00020000h
    SKF_LWINLOCKED equ 00400000h
    SKF_RWINLOCKED equ 00800000h
    ;* _WIN32_WINNT >= 0x0500 *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    MOUSEKEYS struct
      cbSize DWORD ?
      dwFlags DWORD ?
      iMaxSpeed DWORD ?
      iTimeToMaxSpeed DWORD ?
      iCtrlSpeed DWORD ?
      dwReserved1 DWORD ?
      dwReserved2 DWORD ?
    MOUSEKEYS ends
    tagMOUSEKEYS typedef MOUSEKEYS
    LPMOUSEKEYS typedef ptr MOUSEKEYS
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  ;*
  ;* MOUSEKEYS dwFlags field
  ;*
  MKF_MOUSEKEYSON equ 00000001h
  MKF_AVAILABLE equ 00000002h
  MKF_HOTKEYACTIVE equ 00000004h
  MKF_CONFIRMHOTKEY equ 00000008h
  MKF_HOTKEYSOUND equ 00000010h
  MKF_INDICATOR equ 00000020h
  MKF_MODIFIERS equ 00000040h
  MKF_REPLACENUMBERS equ 00000080h
  if (_WIN32_WINNT ge 0500h)
    MKF_LEFTBUTTONSEL equ 10000000h
    MKF_RIGHTBUTTONSEL equ 20000000h
    MKF_LEFTBUTTONDOWN equ 01000000h
    MKF_RIGHTBUTTONDOWN equ 02000000h
    MKF_MOUSEMODE equ 80000000h
    ;* _WIN32_WINNT >= 0x0500 *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ACCESSTIMEOUT struct
      cbSize DWORD ?
      dwFlags DWORD ?
      iTimeOutMSec DWORD ?
    ACCESSTIMEOUT ends
    tagACCESSTIMEOUT typedef ACCESSTIMEOUT
    LPACCESSTIMEOUT typedef ptr ACCESSTIMEOUT
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  ;*
  ;* ACCESSTIMEOUT dwFlags field
  ;*
  ATF_TIMEOUTON equ 00000001h
  ATF_ONOFFFEEDBACK equ 00000002h
  ;* values for SOUNDSENTRY iFSGrafEffect field *
  SSGF_NONE equ 0
  SSGF_DISPLAY equ 3
  ;* values for SOUNDSENTRY iFSTextEffect field *
  SSTF_NONE equ 0
  SSTF_CHARS equ 1
  SSTF_BORDER equ 2
  SSTF_DISPLAY equ 3
  ;* values for SOUNDSENTRY iWindowsEffect field *
  SSWF_NONE equ 0
  SSWF_TITLE equ 1
  SSWF_WINDOW equ 2
  SSWF_DISPLAY equ 3
  SSWF_CUSTOM equ 4
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    SOUNDSENTRYA struct
      cbSize DWORD ?
      dwFlags DWORD ?
      iFSTextEffect DWORD ?
      iFSTextEffectMSec DWORD ?
      iFSTextEffectColorBits DWORD ?
      iFSGrafEffect DWORD ?
      iFSGrafEffectMSec DWORD ?
      iFSGrafEffectColor DWORD ?
      iWindowsEffect DWORD ?
      iWindowsEffectMSec DWORD ?
      lpszWindowsEffectDLL POINTER ?
      iWindowsEffectOrdinal DWORD ?
    SOUNDSENTRYA ends
    tagSOUNDSENTRYA typedef SOUNDSENTRYA
    LPSOUNDSENTRYA typedef ptr SOUNDSENTRYA
    SOUNDSENTRYW struct
      cbSize DWORD ?
      dwFlags DWORD ?
      iFSTextEffect DWORD ?
      iFSTextEffectMSec DWORD ?
      iFSTextEffectColorBits DWORD ?
      iFSGrafEffect DWORD ?
      iFSGrafEffectMSec DWORD ?
      iFSGrafEffectColor DWORD ?
      iWindowsEffect DWORD ?
      iWindowsEffectMSec DWORD ?
      lpszWindowsEffectDLL POINTER ?
      iWindowsEffectOrdinal DWORD ?
    SOUNDSENTRYW ends
    tagSOUNDSENTRYW typedef SOUNDSENTRYW
    LPSOUNDSENTRYW typedef ptr SOUNDSENTRYW
    ifdef UNICODE
      SOUNDSENTRY typedef SOUNDSENTRYW
      LPSOUNDSENTRY typedef LPSOUNDSENTRYW
    else
      SOUNDSENTRY typedef SOUNDSENTRYA
      LPSOUNDSENTRY typedef LPSOUNDSENTRYA
    endif
    ; UNICODE
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  ;*
  ;* SOUNDSENTRY dwFlags field
  ;*
  SSF_SOUNDSENTRYON equ 00000001h
  SSF_AVAILABLE equ 00000002h
  SSF_INDICATOR equ 00000004h
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PC_APP)
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, SoundSentry, WIN_STD_CALL_CONV,, <>, 0
      ;* _WIN32_WINNT >= 0x0600 *
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_PC_APP) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    TOGGLEKEYS struct
      cbSize DWORD ?
      dwFlags DWORD ?
    TOGGLEKEYS ends
    tagTOGGLEKEYS typedef TOGGLEKEYS
    LPTOGGLEKEYS typedef ptr TOGGLEKEYS
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  ;*
  ;* TOGGLEKEYS dwFlags field
  ;*
  TKF_TOGGLEKEYSON equ 00000001h
  TKF_AVAILABLE equ 00000002h
  TKF_HOTKEYACTIVE equ 00000004h
  TKF_CONFIRMHOTKEY equ 00000008h
  TKF_HOTKEYSOUND equ 00000010h
  TKF_INDICATOR equ 00000020h
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if (_WIN32_WINNT ge 0600h)
      AUDIODESCRIPTION struct
        cbSize DWORD ?
        ; sizeof(AudioDescriptionType)
        Enabled DWORD ?
        ; On/Off
        Locale LCID ?
        ; locale ID for language
      AUDIODESCRIPTION ends
      tagAUDIODESCRIPTION typedef AUDIODESCRIPTION
      LPAUDIODESCRIPTION typedef ptr AUDIODESCRIPTION
      ;* _WIN32_WINNT >= 0x0600 *
    endif
    ;*
    ;* Set debug level
    ;*
    @DefProto DllImport, SetDebugErrorLevel, WIN_STD_CALL_CONV,, <:DWORD>, 4
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  ;*
  ;* SetLastErrorEx() types.
  ;*
  SLE_ERROR equ 00000001h
  SLE_MINORERROR equ 00000002h
  SLE_WARNING equ 00000003h
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    @DefProto DllImport, SetLastErrorEx, WIN_STD_CALL_CONV,, <:DWORD, :DWORD>, 8
    @DefProto DllImport, InternalGetWindowText, WIN_STD_CALL_CONV,, <:HWND, :LPWSTR, :SDWORD>, 12
    if Defined(WINNT)
      @DefProto DllImport, EndTask, WIN_STD_CALL_CONV,, <:HWND, :BOOL, :BOOL>, 12
    endif
    @DefProto DllImport, CancelShutdown, WIN_STD_CALL_CONV,, <>, 0
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  if (WINVER ge 0500h)
    ;*
    ;* Multimonitor API.
    ;*
    MONITOR_DEFAULTTONULL equ 00000000h
    MONITOR_DEFAULTTOPRIMARY equ 00000001h
    MONITOR_DEFAULTTONEAREST equ 00000002h
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, MonitorFromPoint, WIN_STD_CALL_CONV,, <:POINT, :DWORD>, 8
      @DefProto DllImport, MonitorFromRect, WIN_STD_CALL_CONV,, <:LPCRECT, :DWORD>, 8
      @DefProto DllImport, MonitorFromWindow, WIN_STD_CALL_CONV,, <:HWND, :DWORD>, 8
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    MONITORINFOF_PRIMARY equ 00000001h
    ifndef CCHDEVICENAME
      CCHDEVICENAME equ 32
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      MONITORINFO struct
        cbSize DWORD ?
        rcMonitor RECT <>
        rcWork RECT <>
        dwFlags DWORD ?
      MONITORINFO ends
      tagMONITORINFO typedef MONITORINFO
      LPMONITORINFO typedef ptr MONITORINFO
      ifdef __cplusplus
        ;[...]
        ; UNICODE
      else
      ; ndef __cplusplus
        MONITORINFOEXA struct
          DUMMYSTRUCTNAME MONITORINFO <>
          szDevice SBYTE CCHDEVICENAME dup (?)
        MONITORINFOEXA ends
        tagMONITORINFOEXA typedef MONITORINFOEXA
        LPMONITORINFOEXA typedef ptr MONITORINFOEXA
        MONITORINFOEXW struct
          DUMMYSTRUCTNAME MONITORINFO <>
          szDevice WORD CCHDEVICENAME dup (?)
        MONITORINFOEXW ends
        tagMONITORINFOEXW typedef MONITORINFOEXW
        LPMONITORINFOEXW typedef ptr MONITORINFOEXW
        ifdef UNICODE
          MONITORINFOEX typedef MONITORINFOEXW
          LPMONITORINFOEX typedef LPMONITORINFOEXW
        else
          MONITORINFOEX typedef MONITORINFOEXA
          LPMONITORINFOEX typedef LPMONITORINFOEXA
        endif
        ; UNICODE
      endif
      @DefProto DllImport, GetMonitorInfoA, WIN_STD_CALL_CONV,, <:HMONITOR, :LPMONITORINFO>, 8
      @DefProto DllImport, GetMonitorInfoW, WIN_STD_CALL_CONV,, <:HMONITOR, :LPMONITORINFO>, 8
      ifdef UNICODE
        GetMonitorInfo equ <GetMonitorInfoW>
      else
        GetMonitorInfo equ <GetMonitorInfoA>
      endif
      ; !UNICODE
      TYPE_MONITORENUMPROC typedef proto WIN_STD_CALL_CONV :HMONITOR, :HDC, :LPRECT, :LPARAM
      MONITORENUMPROC typedef ptr TYPE_MONITORENUMPROC

      @DefProto DllImport, EnumDisplayMonitors, WIN_STD_CALL_CONV,, <:HDC, :LPCRECT, :MONITORENUMPROC, :LPARAM>, 16
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ifndef NOWINABLE
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        ;*
        ;* WinEvents - Active Accessibility hooks
        ;*
        @DefProto DllImport, NotifyWinEvent, WIN_STD_CALL_CONV,, <:DWORD, :HWND, :LONG, :LONG>, 16
        TYPE_WINEVENTPROC typedef proto WIN_STD_CALL_CONV :HWINEVENTHOOK, :DWORD, :HWND, :LONG, :LONG, :DWORD, :DWORD
        WINEVENTPROC typedef ptr TYPE_WINEVENTPROC

        @DefProto DllImport, SetWinEventHook, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :HMODULE, :WINEVENTPROC, :DWORD, :DWORD, :DWORD>, 28
        if (_WIN32_WINNT ge 0501h)
          @DefProto DllImport, IsWinEventHookInstalled, WIN_STD_CALL_CONV,, <:DWORD>, 4
          ;* _WIN32_WINNT >= 0x0501 *
        endif
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;*
      ;* dwFlags for SetWinEventHook
      ;*
      WINEVENT_OUTOFCONTEXT equ 0000h; Events are ASYNC

      WINEVENT_SKIPOWNTHREAD equ 0001h; Don't call back for events on installer's thread

      WINEVENT_SKIPOWNPROCESS equ 0002h; Don't call back for events on installer's process

      WINEVENT_INCONTEXT equ 0004h; Events are SYNC, this causes your dll to be injected into every process

      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, UnhookWinEvent, WIN_STD_CALL_CONV,, <:HWINEVENTHOOK>, 4
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;*
      ;* idObject values for WinEventProc and NotifyWinEvent
      ;*
      ;*
      ;* hwnd + idObject can be used with OLEACC.DLL's OleGetObjectFromWindow()
      ;* to get an interface pointer to the container.  indexChild is the item
      ;* within the container in question.  Setup a VARIANT with vt VT_I4 and
      ;* lVal the indexChild and pass that in to all methods.  Then you
      ;* are raring to go.
      ;*
      ;*
      ;* Common object IDs (cookies, only for sending WM_GETOBJECT to get at the
      ;* thing in question).  Positive IDs are reserved for apps (app specific),
      ;* negative IDs are system things and are global, 0 means "just little old
      ;* me".
      ;*
      CHILDID_SELF equ 0
      INDEXID_OBJECT equ 0
      INDEXID_CONTAINER equ 0
      ;*
      ;* Reserved IDs for system objects
      ;*
      OBJID_WINDOW equ (00000000h)
      OBJID_SYSMENU equ (0FFFFFFFFh)
      OBJID_TITLEBAR equ (0FFFFFFFEh)
      OBJID_MENU equ (0FFFFFFFDh)
      OBJID_CLIENT equ (0FFFFFFFCh)
      OBJID_VSCROLL equ (0FFFFFFFBh)
      OBJID_HSCROLL equ (0FFFFFFFAh)
      OBJID_SIZEGRIP equ (0FFFFFFF9h)
      OBJID_CARET equ (0FFFFFFF8h)
      OBJID_CURSOR equ (0FFFFFFF7h)
      OBJID_ALERT equ (0FFFFFFF6h)
      OBJID_SOUND equ (0FFFFFFF5h)
      OBJID_QUERYCLASSNAMEIDX equ (0FFFFFFF4h)
      OBJID_NATIVEOM equ (0FFFFFFF0h)
      ;*
      ;* EVENT DEFINITION
      ;*
      EVENT_MIN equ 00000001h
      EVENT_MAX equ 7FFFFFFFh
      ;*
      ;*  EVENT_SYSTEM_SOUND
      ;*  Sent when a sound is played.  Currently nothing is generating this, we
      ;*  this event when a system sound (for menus, etc) is played.  Apps
      ;*  generate this, if accessible, when a private sound is played.  For
      ;*  example, if Mail plays a "New Mail" sound.
      ;*
      ;*  System Sounds:
      ;*  (Generated by PlaySoundEvent in USER itself)
      ;*      hwnd            is NULL
      ;*      idObject        is OBJID_SOUND
      ;*      idChild         is sound child ID if one
      ;*  App Sounds:
      ;*  (PlaySoundEvent won't generate notification; up to app)
      ;*      hwnd + idObject gets interface pointer to Sound object
      ;*      idChild identifies the sound in question
      ;*  are going to be cleaning up the SOUNDSENTRY feature in the control panel
      ;*  and will use this at that time.  Applications implementing WinEvents
      ;*  are perfectly welcome to use it.  Clients of IAccessible* will simply
      ;*  turn around and get back a non-visual object that describes the sound.
      ;*
      EVENT_SYSTEM_SOUND equ 0001h
      ;*
      ;* EVENT_SYSTEM_ALERT
      ;* System Alerts:
      ;* (Generated by MessageBox() calls for example)
      ;*      hwnd            is hwndMessageBox
      ;*      idObject        is OBJID_ALERT
      ;* App Alerts:
      ;* (Generated whenever)
      ;*      hwnd+idObject gets interface pointer to Alert
      ;*
      EVENT_SYSTEM_ALERT equ 0002h
      ;*
      ;* EVENT_SYSTEM_FOREGROUND
      ;* Sent when the foreground (active) window changes, even if it is changing
      ;* to another window in the same thread as the previous one.
      ;*      hwnd            is hwndNewForeground
      ;*      idObject        is OBJID_WINDOW
      ;*      idChild    is INDEXID_OBJECT
      ;*
      EVENT_SYSTEM_FOREGROUND equ 0003h
      ;*
      ;* Menu
      ;*      hwnd            is window (top level window or popup menu window)
      ;*      idObject        is ID of control (OBJID_MENU, OBJID_SYSMENU, OBJID_SELF for popup)
      ;*      idChild         is CHILDID_SELF
      ;*
      ;* EVENT_SYSTEM_MENUSTART
      ;* EVENT_SYSTEM_MENUEND
      ;* For MENUSTART, hwnd+idObject+idChild refers to the control with the menu bar,
      ;*  or the control bringing up the context menu.
      ;*
      ;* Sent when entering into and leaving from menu mode (system, app bar, and
      ;* track popups).
      ;*
      EVENT_SYSTEM_MENUSTART equ 0004h
      EVENT_SYSTEM_MENUEND equ 0005h
      ;*
      ;* EVENT_SYSTEM_MENUPOPUPSTART
      ;* EVENT_SYSTEM_MENUPOPUPEND
      ;* Sent when a menu popup comes up and just before it is taken down.  Note
      ;* that for a call to TrackPopupMenu(), a client will see EVENT_SYSTEM_MENUSTART
      ;* followed almost immediately by EVENT_SYSTEM_MENUPOPUPSTART for the popup
      ;* being shown.
      ;*
      ;* For MENUPOPUP, hwnd+idObject+idChild refers to the NEW popup coming up, not the
      ;* parent item which is hierarchical.  You can get the parent menu/popup by
      ;* asking for the accParent object.
      ;*
      EVENT_SYSTEM_MENUPOPUPSTART equ 0006h
      EVENT_SYSTEM_MENUPOPUPEND equ 0007h
      ;*
      ;* EVENT_SYSTEM_CAPTURESTART
      ;* EVENT_SYSTEM_CAPTUREEND
      ;* Sent when a window takes the capture and releases the capture.
      ;*
      EVENT_SYSTEM_CAPTURESTART equ 0008h
      EVENT_SYSTEM_CAPTUREEND equ 0009h
      ;*
      ;* Move Size
      ;* EVENT_SYSTEM_MOVESIZESTART
      ;* EVENT_SYSTEM_MOVESIZEEND
      ;* Sent when a window enters and leaves move-size dragging mode.
      ;*
      EVENT_SYSTEM_MOVESIZESTART equ 000Ah
      EVENT_SYSTEM_MOVESIZEEND equ 000Bh
      ;*
      ;* Context Help
      ;* EVENT_SYSTEM_CONTEXTHELPSTART
      ;* EVENT_SYSTEM_CONTEXTHELPEND
      ;* Sent when a window enters and leaves context sensitive help mode.
      ;*
      EVENT_SYSTEM_CONTEXTHELPSTART equ 000Ch
      EVENT_SYSTEM_CONTEXTHELPEND equ 000Dh
      ;*
      ;* Drag & Drop
      ;* EVENT_SYSTEM_DRAGDROPSTART
      ;* EVENT_SYSTEM_DRAGDROPEND
      ;* Send the START notification just before going into drag&drop loop.  Send
      ;* the END notification just after canceling out.
      ;* Note that it is up to apps and OLE to generate this, since the system
      ;* doesn't know.  Like EVENT_SYSTEM_SOUND, it will be a while before this
      ;* is prevalent.
      ;*
      EVENT_SYSTEM_DRAGDROPSTART equ 000Eh
      EVENT_SYSTEM_DRAGDROPEND equ 000Fh
      ;*
      ;* Dialog
      ;* Send the START notification right after the dialog is completely
      ;*  initialized and visible.  Send the END right before the dialog
      ;*  is hidden and goes away.
      ;* EVENT_SYSTEM_DIALOGSTART
      ;* EVENT_SYSTEM_DIALOGEND
      ;*
      EVENT_SYSTEM_DIALOGSTART equ 0010h
      EVENT_SYSTEM_DIALOGEND equ 0011h
      ;*
      ;* EVENT_SYSTEM_SCROLLING
      ;* EVENT_SYSTEM_SCROLLINGSTART
      ;* EVENT_SYSTEM_SCROLLINGEND
      ;* Sent when beginning and ending the tracking of a scrollbar in a window,
      ;* and also for scrollbar controls.
      ;*
      EVENT_SYSTEM_SCROLLINGSTART equ 0012h
      EVENT_SYSTEM_SCROLLINGEND equ 0013h
      ;*
      ;* Alt-Tab Window
      ;* Send the START notification right after the switch window is initialized
      ;* and visible.  Send the END right before it is hidden and goes away.
      ;* EVENT_SYSTEM_SWITCHSTART
      ;* EVENT_SYSTEM_SWITCHEND
      ;*
      EVENT_SYSTEM_SWITCHSTART equ 0014h
      EVENT_SYSTEM_SWITCHEND equ 0015h
      ;*
      ;* EVENT_SYSTEM_MINIMIZESTART
      ;* EVENT_SYSTEM_MINIMIZEEND
      ;* Sent when a window minimizes and just before it restores.
      ;*
      EVENT_SYSTEM_MINIMIZESTART equ 0016h
      EVENT_SYSTEM_MINIMIZEEND equ 0017h
      if (_WIN32_WINNT ge 0600h)
        EVENT_SYSTEM_DESKTOPSWITCH equ 0020h
        ;* _WIN32_WINNT >= 0x0600 *
      endif
      if (_WIN32_WINNT ge 0602h)
        ; AppGrabbed: HWND = hwnd of app thumbnail, objectID = 0, childID = 0
        EVENT_SYSTEM_SWITCHER_APPGRABBED equ 0024h
        ; OverTarget: HWND = hwnd of app thumbnail, objectID =
        ;            1 for center
        ;            2 for near snapped
        ;            3 for far snapped
        ;            4 for prune
        ;            childID = 0
        EVENT_SYSTEM_SWITCHER_APPOVERTARGET equ 0025h
        ; Dropped: HWND = hwnd of app thumbnail, objectID = <same as above>, childID = 0
        EVENT_SYSTEM_SWITCHER_APPDROPPED equ 0026h
        ; Cancelled: HWND = hwnd of app thumbnail, objectID = 0, childID = 0
        EVENT_SYSTEM_SWITCHER_CANCELLED equ 0027h
        ;* _WIN32_WINNT >= 0x0602 *
      endif
      if (_WIN32_WINNT ge 0602h)
        ;*
        ;* Sent when an IME's soft key is pressed and should be echoed,
        ;* but is not passed through the keyboard hook.
        ;* Must not be sent when a key is sent through the keyboard hook.
        ;*     HWND             is the hwnd of the UI containing the soft key
        ;*     idChild          is the Unicode value of the character entered
        ;*     idObject         is a bitfield
        ;*         0x00000001: set if a 32-bit Unicode surrogate pair is used
        ;*
        EVENT_SYSTEM_IME_KEY_NOTIFICATION equ 0029h
        ;* _WIN32_WINNT >= 0x0602 *
      endif
      if (_WIN32_WINNT ge 0601h)
        EVENT_SYSTEM_END equ 00FFh
        EVENT_OEM_DEFINED_START equ 0101h
        EVENT_OEM_DEFINED_END equ 01FFh
        EVENT_UIA_EVENTID_START equ 4E00h
        EVENT_UIA_EVENTID_END equ 4EFFh
        EVENT_UIA_PROPID_START equ 7500h
        EVENT_UIA_PROPID_END equ 75FFh
        ;* _WIN32_WINNT >= 0x0601 *
      endif
      if (_WIN32_WINNT ge 0501h)
        EVENT_CONSOLE_CARET equ 4001h
        EVENT_CONSOLE_UPDATE_REGION equ 4002h
        EVENT_CONSOLE_UPDATE_SIMPLE equ 4003h
        EVENT_CONSOLE_UPDATE_SCROLL equ 4004h
        EVENT_CONSOLE_LAYOUT equ 4005h
        EVENT_CONSOLE_START_APPLICATION equ 4006h
        EVENT_CONSOLE_END_APPLICATION equ 4007h
        ;*
        ;* Flags for EVENT_CONSOLE_START/END_APPLICATION.
        ;*
        if Defined(_WIN64)
          CONSOLE_APPLICATION_16BIT equ 0000h
        else
          CONSOLE_APPLICATION_16BIT equ 0001h
        endif
        ;*
        ;* Flags for EVENT_CONSOLE_CARET
        ;*
        CONSOLE_CARET_SELECTION equ 0001h
        CONSOLE_CARET_VISIBLE equ 0002h
        ;* _WIN32_WINNT >= 0x0501 *
      endif
      if (_WIN32_WINNT ge 0601h)
        EVENT_CONSOLE_END equ 40FFh
        ;* _WIN32_WINNT >= 0x0601 *
      endif
      ;*
      ;* Object events
      ;*
      ;* The system AND apps generate these.  The system generates these for
      ;* real windows.  Apps generate these for objects within their window which
      ;* act like a separate control, e.g. an item in a list view.
      ;*
      ;* When the system generate them, dwParam2 is always WMOBJID_SELF.  When
      ;* apps generate them, apps put the has-meaning-to-the-app-only ID value
      ;* in dwParam2.
      ;* For all events, if you want detailed accessibility information, callers
      ;* should
      ;*      * Call AccessibleObjectFromWindow() with the hwnd, idObject parameters
      ;*          of the event, and IID_IAccessible as the REFIID, to get back an
      ;*          IAccessible* to talk to
      ;*      * Initialize and fill in a VARIANT as VT_I4 with lVal the idChild
      ;*          parameter of the event.
      ;*      * If idChild isn't zero, call get_accChild() in the container to see
      ;*          if the child is an object in its own right.  If so, you will get
      ;*          back an IDispatch* object for the child.  You should release the
      ;*          parent, and call QueryInterface() on the child object to get its
      ;*          IAccessible*.  Then you talk directly to the child.  Otherwise,
      ;*          if get_accChild() returns you nothing, you should continue to
      ;*          use the child VARIANT.  You will ask the container for the properties
      ;*          of the child identified by the VARIANT.  In other words, the
      ;*          child in this case is accessible but not a full-blown object.
      ;*          Like a button on a titlebar which is 'small' and has no children.
      ;*
      ;*
      ;* For all EVENT_OBJECT events,
      ;*      hwnd is the dude to Send the WM_GETOBJECT message to (unless NULL,
      ;*          see above for system things)
      ;*      idObject is the ID of the object that can resolve any queries a
      ;*          client might have.  It's a way to deal with windowless controls,
      ;*          controls that are just drawn on the screen in some larger parent
      ;*          window (like SDM), or standard frame elements of a window.
      ;*      idChild is the piece inside of the object that is affected.  This
      ;*          allows clients to access things that are too small to have full
      ;*          blown objects in their own right.  Like the thumb of a scrollbar.
      ;*          The hwnd/idObject pair gets you to the container, the dude you
      ;*          probably want to talk to most of the time anyway.  The idChild
      ;*          can then be passed into the acc properties to get the name/value
      ;*          of it as needed.
      ;*
      ;* Example #1:
      ;*      System propagating a listbox selection change
      ;*      EVENT_OBJECT_SELECTION
      ;*          hwnd == listbox hwnd
      ;*          idObject == OBJID_WINDOW
      ;*          idChild == new selected item, or CHILDID_SELF if
      ;*              nothing now selected within container.
      ;*      Word '97 propagating a listbox selection change
      ;*          hwnd == SDM window
      ;*          idObject == SDM ID to get at listbox 'control'
      ;*          idChild == new selected item, or CHILDID_SELF if
      ;*              nothing
      ;*
      ;* Example #2:
      ;*      System propagating a menu item selection on the menu bar
      ;*      EVENT_OBJECT_SELECTION
      ;*          hwnd == top level window
      ;*          idObject == OBJID_MENU
      ;*          idChild == ID of child menu bar item selected
      ;*
      ;* Example #3:
      ;*      System propagating a dropdown coming off of said menu bar item
      ;*      EVENT_OBJECT_CREATE
      ;*          hwnd == popup item
      ;*          idObject == OBJID_WINDOW
      ;*          idChild == CHILDID_SELF
      ;*
      ;* Example #4:
      ;*
      ;* For EVENT_OBJECT_REORDER, the object referred to by hwnd/idObject is the
      ;* PARENT container in which the zorder is occurring.  This is because if
      ;* one child is zordering, all of them are changing their relative zorder.
      ;*
      EVENT_OBJECT_CREATE equ 8000h; hwnd + ID + idChild is created item

      EVENT_OBJECT_DESTROY equ 8001h; hwnd + ID + idChild is destroyed item

      EVENT_OBJECT_SHOW equ 8002h; hwnd + ID + idChild is shown item

      EVENT_OBJECT_HIDE equ 8003h; hwnd + ID + idChild is hidden item

      EVENT_OBJECT_REORDER equ 8004h; hwnd + ID + idChild is parent of zordering children

      ;*
      ;* NOTE:
      ;* Minimize the number of notifications!
      ;*
      ;* When you are hiding a parent object, obviously all child objects are no
      ;* longer visible on screen.  They still have the same "visible" status,
      ;* but are not truly visible.  Hence do not send HIDE notifications for the
      ;* children also.  One implies all.  The same goes for SHOW.
      ;*
      EVENT_OBJECT_FOCUS equ 8005h; hwnd + ID + idChild is focused item

      EVENT_OBJECT_SELECTION equ 8006h; hwnd + ID + idChild is selected item (if only one), or idChild is OBJID_WINDOW if complex

      EVENT_OBJECT_SELECTIONADD equ 8007h; hwnd + ID + idChild is item added

      EVENT_OBJECT_SELECTIONREMOVE equ 8008h; hwnd + ID + idChild is item removed

      EVENT_OBJECT_SELECTIONWITHIN equ 8009h; hwnd + ID + idChild is parent of changed selected items

      ;*
      ;* NOTES:
      ;* There is only one "focused" child item in a parent.  This is the place
      ;* keystrokes are going at a given moment.  Hence only send a notification
      ;* about where the NEW focus is going.  A NEW item getting the focus already
      ;* implies that the OLD item is losing it.
      ;*
      ;* SELECTION however can be multiple.  Hence the different SELECTION
      ;* notifications.  Here's when to use each:
      ;*
      ;* (1) Send a SELECTION notification in the simple single selection
      ;*     case (like the focus) when the item with the selection is
      ;*     merely moving to a different item within a container.  hwnd + ID
      ;*     is the container control, idChildItem is the new child with the
      ;*     selection.
      ;*
      ;* (2) Send a SELECTIONADD notification when a new item has simply been added
      ;*     to the selection within a container.  This is appropriate when the
      ;*     number of newly selected items is very small.  hwnd + ID is the
      ;*     container control, idChildItem is the new child added to the selection.
      ;*
      ;* (3) Send a SELECTIONREMOVE notification when a new item has simply been
      ;*     removed from the selection within a container.  This is appropriate
      ;*     when the number of newly selected items is very small, just like
      ;*     SELECTIONADD.  hwnd + ID is the container control, idChildItem is the
      ;*     new child removed from the selection.
      ;*
      ;* (4) Send a SELECTIONWITHIN notification when the selected items within a
      ;*     control have changed substantially.  Rather than propagate a large
      ;*     number of changes to reflect removal for some items, addition of
      ;*     others, just tell somebody who cares that a lot happened.  It will
      ;*     be faster an easier for somebody watching to just turn around and
      ;*     query the container control what the new bunch of selected items
      ;*     are.
      ;*
      EVENT_OBJECT_STATECHANGE equ 800Ah; hwnd + ID + idChild is item w/ state change

      ;*
      ;* Examples of when to send an EVENT_OBJECT_STATECHANGE include
      ;*      * It is being enabled/disabled (USER does for windows)
      ;*      * It is being pressed/released (USER does for buttons)
      ;*      * It is being checked/unchecked (USER does for radio/check buttons)
      ;*
      EVENT_OBJECT_LOCATIONCHANGE equ 800Bh; hwnd + ID + idChild is moved/sized item

      ;*
      ;* Note:
      ;* A LOCATIONCHANGE is not sent for every child object when the parent
      ;* changes shape/moves.  Send one notification for the topmost object
      ;* that is changing.  For example, if the user resizes a top level window,
      ;* USER will generate a LOCATIONCHANGE for it, but not for the menu bar,
      ;* title bar, scrollbars, etc.  that are also changing shape/moving.
      ;*
      ;* In other words, it only generates LOCATIONCHANGE notifications for
      ;* real windows that are moving/sizing.  It will not generate a LOCATIONCHANGE
      ;* for every non-floating child window when the parent moves (the children are
      ;* logically moving also on screen, but not relative to the parent).
      ;*
      ;* Now, if the app itself resizes child windows as a result of being
      ;* sized, USER will generate LOCATIONCHANGEs for those dudes also because
      ;* it doesn't know better.
      ;*
      ;* Note also that USER will generate LOCATIONCHANGE notifications for two
      ;* non-window sys objects:
      ;*      (1) System caret
      ;*      (2) Cursor
      ;*
      EVENT_OBJECT_NAMECHANGE equ 800Ch; hwnd + ID + idChild is item w/ name change

      EVENT_OBJECT_DESCRIPTIONCHANGE equ 800Dh; hwnd + ID + idChild is item w/ desc change

      EVENT_OBJECT_VALUECHANGE equ 800Eh; hwnd + ID + idChild is item w/ value change

      EVENT_OBJECT_PARENTCHANGE equ 800Fh; hwnd + ID + idChild is item w/ new parent

      EVENT_OBJECT_HELPCHANGE equ 8010h; hwnd + ID + idChild is item w/ help change

      EVENT_OBJECT_DEFACTIONCHANGE equ 8011h; hwnd + ID + idChild is item w/ def action change

      EVENT_OBJECT_ACCELERATORCHANGE equ 8012h; hwnd + ID + idChild is item w/ keybd accel change

      if (_WIN32_WINNT ge 0600h)
        EVENT_OBJECT_INVOKED equ 8013h; hwnd + ID + idChild is item invoked

        EVENT_OBJECT_TEXTSELECTIONCHANGED equ 8014h; hwnd + ID + idChild is item w? test selection change

        ;*
        ;* EVENT_OBJECT_CONTENTSCROLLED
        ;* Sent when ending the scrolling of a window object.
        ;*
        ;* Unlike the similar event (EVENT_SYSTEM_SCROLLEND), this event will be
        ;* associated with the scrolling window itself. There is no difference
        ;* between horizontal or vertical scrolling.
        ;*
        ;* This event should be posted whenever scroll action is completed, including
        ;* when it is scrolled by scroll bars, mouse wheel, or keyboard navigations.
        ;*
        ;*   example:
        ;*          hwnd == window that is scrolling
        ;*          idObject == OBJID_CLIENT
        ;*          idChild == CHILDID_SELF
        ;*
        EVENT_OBJECT_CONTENTSCROLLED equ 8015h
        ;* _WIN32_WINNT >= 0x0600 *
      endif
      if (_WIN32_WINNT ge 0601h)
        EVENT_SYSTEM_ARRANGMENTPREVIEW equ 8016h
        ;* _WIN32_WINNT >= 0x0601 *
      endif
      if (_WIN32_WINNT ge 0602h)
        ;*
        ;* EVENT_OBJECT_CLOAKED / UNCLOAKED
        ;* Sent when a window is cloaked or uncloaked.
        ;* A cloaked window still exists, but is invisible to
        ;* the user.
        ;*
        EVENT_OBJECT_CLOAKED equ 8017h
        EVENT_OBJECT_UNCLOAKED equ 8018h
        ;*
        ;* EVENT_OBJECT_LIVEREGIONCHANGED
        ;* Sent when an object that is part of a live region
        ;* changes.  A live region is an area of an application
        ;* that changes frequently and/or asynchronously, so
        ;* that an assistive technology tool might want to pay
        ;* special attention to it.
        ;*
        EVENT_OBJECT_LIVEREGIONCHANGED equ 8019h
        ;*
        ;* EVENT_OBJECT_HOSTEDOBJECTSINVALIDATED
        ;* Sent when a window that is hosting other Accessible
        ;* objects changes the hosted objects.  A client may
        ;* wish to requery to see what the new hosted objects are,
        ;* especially if it has been monitoring events from this
        ;* window.  A hosted object is one with a different Accessibility
        ;* framework (MSAA or UI Automation) from its host.
        ;*
        ;* Changes in hosted objects with the *same* framework
        ;* as the parent should be handed with the usual structural
        ;* change events, such as EVENT_OBJECT_CREATED for MSAA.
        ;* see above.
        ;*
        EVENT_OBJECT_HOSTEDOBJECTSINVALIDATED equ 8020h
        ;*
        ;* Drag / Drop Events
        ;* These events are used in conjunction with the
        ;* UI Automation Drag/Drop patterns.
        ;*
        ;* For DRAGSTART, DRAGCANCEL, and DRAGCOMPLETE,
        ;* HWND+objectID+childID refers to the object being dragged.
        ;*
        ;* For DRAGENTER, DRAGLEAVE, and DRAGDROPPED,
        ;* HWND+objectID+childID refers to the target of the drop
        ;* that is being hovered over.
        ;*
        EVENT_OBJECT_DRAGSTART equ 8021h
        EVENT_OBJECT_DRAGCANCEL equ 8022h
        EVENT_OBJECT_DRAGCOMPLETE equ 8023h
        EVENT_OBJECT_DRAGENTER equ 8024h
        EVENT_OBJECT_DRAGLEAVE equ 8025h
        EVENT_OBJECT_DRAGDROPPED equ 8026h
        ;*
        ;* EVENT_OBJECT_IME_SHOW/HIDE
        ;* Sent by an IME window when it has become visible or invisible.
        ;*
        EVENT_OBJECT_IME_SHOW equ 8027h
        EVENT_OBJECT_IME_HIDE equ 8028h
        ;*
        ;* EVENT_OBJECT_IME_CHANGE
        ;* Sent by an IME window whenever it changes size or position.
        ;*
        EVENT_OBJECT_IME_CHANGE equ 8029h
        EVENT_OBJECT_TEXTEDIT_CONVERSIONTARGETCHANGED equ 8030h
        ;* _WIN32_WINNT >= 0x0602 *
      endif
      if (_WIN32_WINNT ge 0601h)
        EVENT_OBJECT_END equ 80FFh
        EVENT_AIA_START equ 0A000h
        EVENT_AIA_END equ 0AFFFh
        ;* _WIN32_WINNT >= 0x0601 *
      endif
      ;*
      ;* Child IDs
      ;*
      ;*
      ;* System Sounds (idChild of system SOUND notification)
      ;*
      SOUND_SYSTEM_STARTUP equ 1
      SOUND_SYSTEM_SHUTDOWN equ 2
      SOUND_SYSTEM_BEEP equ 3
      SOUND_SYSTEM_ERROR equ 4
      SOUND_SYSTEM_QUESTION equ 5
      SOUND_SYSTEM_WARNING equ 6
      SOUND_SYSTEM_INFORMATION equ 7
      SOUND_SYSTEM_MAXIMIZE equ 8
      SOUND_SYSTEM_MINIMIZE equ 9
      SOUND_SYSTEM_RESTOREUP equ 10
      SOUND_SYSTEM_RESTOREDOWN equ 11
      SOUND_SYSTEM_APPSTART equ 12
      SOUND_SYSTEM_FAULT equ 13
      SOUND_SYSTEM_APPEND equ 14
      SOUND_SYSTEM_MENUCOMMAND equ 15
      SOUND_SYSTEM_MENUPOPUP equ 16
      CSOUND_SYSTEM equ 16
      ;*
      ;* System Alerts (indexChild of system ALERT notification)
      ;*
      ALERT_SYSTEM_INFORMATIONAL equ 1; MB_INFORMATION

      ALERT_SYSTEM_WARNING equ 2; MB_WARNING

      ALERT_SYSTEM_ERROR equ 3; MB_ERROR

      ALERT_SYSTEM_QUERY equ 4; MB_QUESTION

      ALERT_SYSTEM_CRITICAL equ 5; HardSysErrBox

      CALERT_SYSTEM equ 6
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        GUITHREADINFO struct
          cbSize DWORD ?
          flags DWORD ?
          hwndActive HWND ?
          hwndFocus HWND ?
          hwndCapture HWND ?
          hwndMenuOwner HWND ?
          hwndMoveSize HWND ?
          hwndCaret HWND ?
          rcCaret RECT <>
        GUITHREADINFO ends
        tagGUITHREADINFO typedef GUITHREADINFO
        PGUITHREADINFO typedef ptr GUITHREADINFO
        LPGUITHREADINFO typedef ptr GUITHREADINFO
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      GUI_CARETBLINKING equ 00000001h
      GUI_INMOVESIZE equ 00000002h
      GUI_INMENUMODE equ 00000004h
      GUI_SYSTEMMENUMODE equ 00000008h
      GUI_POPUPMENUMODE equ 00000010h
      if (_WIN32_WINNT ge 0501h)
        if Defined(_WIN64)
          GUI_16BITTASK equ 00000000h
        else
          GUI_16BITTASK equ 00000020h
        endif
        ;* _WIN32_WINNT >= 0x0501 *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, GetGUIThreadInfo, WIN_STD_CALL_CONV,, <:DWORD, :PGUITHREADINFO>, 8
        @DefProto DllImport, BlockInput, WIN_STD_CALL_CONV,, <:BOOL>, 4
        if (_WIN32_WINNT ge 0600h)
          USER_DEFAULT_SCREEN_DPI equ 96
          @DefProto DllImport, SetProcessDPIAware, WIN_STD_CALL_CONV,, <>, 0
          @DefProto DllImport, IsProcessDPIAware, WIN_STD_CALL_CONV,, <>, 0
          ;* _WIN32_WINNT >= 0x0600 *
        endif
        if (WINVER ge 0605h)
          @DefProto DllImport, SetThreadDpiAwarenessContext, WIN_STD_CALL_CONV,, <:DPI_AWARENESS_CONTEXT>, 4
          @DefProto DllImport, GetThreadDpiAwarenessContext, WIN_STD_CALL_CONV,, <>, 0
          @DefProto DllImport, GetWindowDpiAwarenessContext, WIN_STD_CALL_CONV,, <:HWND>, 4
          @DefProto DllImport, GetAwarenessFromDpiAwarenessContext, WIN_STD_CALL_CONV,, <:DPI_AWARENESS_CONTEXT>, 4
          @DefProto DllImport, GetDpiFromDpiAwarenessContext, WIN_STD_CALL_CONV,, <:DPI_AWARENESS_CONTEXT>, 4
          @DefProto DllImport, AreDpiAwarenessContextsEqual, WIN_STD_CALL_CONV,, <:DPI_AWARENESS_CONTEXT, :DPI_AWARENESS_CONTEXT>, 8
          @DefProto DllImport, IsValidDpiAwarenessContext, WIN_STD_CALL_CONV,, <:DPI_AWARENESS_CONTEXT>, 4
          @DefProto DllImport, GetDpiForWindow, WIN_STD_CALL_CONV,, <:HWND>, 4
          @DefProto DllImport, GetDpiForSystem, WIN_STD_CALL_CONV,, <>, 0
          @DefProto DllImport, GetSystemDpiForProcess, WIN_STD_CALL_CONV,, <:HANDLE>, 4
          @DefProto DllImport, EnableNonClientDpiScaling, WIN_STD_CALL_CONV,, <:HWND>, 4
          @DefProto DllImport, InheritWindowMonitor, WIN_STD_CALL_CONV,, <:HWND, :HWND>, 8
          ;* WINVER >= 0x0605 *
        endif
        if (WINVER ge 0605h)
          @DefProto DllImport, SetProcessDpiAwarenessContext, WIN_STD_CALL_CONV,, <:DPI_AWARENESS_CONTEXT>, 4
          ;* WINVER >= 0x0605 *
        endif
        if (NTDDI_VERSION ge NTDDI_WIN10_19H1)
          @DefProto DllImport, GetDpiAwarenessContextForProcess, WIN_STD_CALL_CONV,, <:HANDLE>, 4
        endif
        ; NTDDI_VERSION >= NTDDI_WIN10_19H1
        if (WINVER ge 0606h)
          @DefProto DllImport, SetThreadDpiHostingBehavior, WIN_STD_CALL_CONV,, <:DPI_HOSTING_BEHAVIOR>, 4
          @DefProto DllImport, GetThreadDpiHostingBehavior, WIN_STD_CALL_CONV,, <>, 0
          @DefProto DllImport, GetWindowDpiHostingBehavior, WIN_STD_CALL_CONV,, <:HWND>, 4
          ;* WINVER >= 0x0606 *
        endif
        @DefProto DllImport, GetWindowModuleFileNameA, WIN_STD_CALL_CONV,, <:HWND, :LPSTR, :UINT>, 12
        @DefProto DllImport, GetWindowModuleFileNameW, WIN_STD_CALL_CONV,, <:HWND, :LPWSTR, :UINT>, 12
        ifdef UNICODE
          GetWindowModuleFileName equ <GetWindowModuleFileNameW>
        else
          GetWindowModuleFileName equ <GetWindowModuleFileNameA>
        endif
        ; !UNICODE
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ifndef NO_STATE_FLAGS
        STATE_SYSTEM_UNAVAILABLE equ 00000001h; Disabled

        STATE_SYSTEM_SELECTED equ 00000002h
        STATE_SYSTEM_FOCUSED equ 00000004h
        STATE_SYSTEM_PRESSED equ 00000008h
        STATE_SYSTEM_CHECKED equ 00000010h
        STATE_SYSTEM_MIXED equ 00000020h; 3-state checkbox or toolbar button

        STATE_SYSTEM_INDETERMINATE equ <STATE_SYSTEM_MIXED>
        STATE_SYSTEM_READONLY equ 00000040h
        STATE_SYSTEM_HOTTRACKED equ 00000080h
        STATE_SYSTEM_DEFAULT equ 00000100h
        STATE_SYSTEM_EXPANDED equ 00000200h
        STATE_SYSTEM_COLLAPSED equ 00000400h
        STATE_SYSTEM_BUSY equ 00000800h
        STATE_SYSTEM_FLOATING equ 00001000h; Children "owned" not "contained" by parent

        STATE_SYSTEM_MARQUEED equ 00002000h
        STATE_SYSTEM_ANIMATED equ 00004000h
        STATE_SYSTEM_INVISIBLE equ 00008000h
        STATE_SYSTEM_OFFSCREEN equ 00010000h
        STATE_SYSTEM_SIZEABLE equ 00020000h
        STATE_SYSTEM_MOVEABLE equ 00040000h
        STATE_SYSTEM_SELFVOICING equ 00080000h
        STATE_SYSTEM_FOCUSABLE equ 00100000h
        STATE_SYSTEM_SELECTABLE equ 00200000h
        STATE_SYSTEM_LINKED equ 00400000h
        STATE_SYSTEM_TRAVERSED equ 00800000h
        STATE_SYSTEM_MULTISELECTABLE equ 01000000h; Supports multiple selection

        STATE_SYSTEM_EXTSELECTABLE equ 02000000h; Supports extended selection

        STATE_SYSTEM_ALERT_LOW equ 04000000h; This information is of low priority

        STATE_SYSTEM_ALERT_MEDIUM equ 08000000h; This information is of medium priority

        STATE_SYSTEM_ALERT_HIGH equ 10000000h; This information is of high priority

        STATE_SYSTEM_PROTECTED equ 20000000h; access to this is restricted

        STATE_SYSTEM_VALID equ 3FFFFFFFh
      endif
      CCHILDREN_TITLEBAR equ 5
      CCHILDREN_SCROLLBAR equ 5
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
        ;*
        ;* Information about the global cursor.
        ;*
        CURSORINFO struct
          cbSize DWORD ?
          flags DWORD ?
          hCursor HCURSOR ?
          ptScreenPos POINT <>
        CURSORINFO ends
        tagCURSORINFO typedef CURSORINFO
        PCURSORINFO typedef ptr CURSORINFO
        LPCURSORINFO typedef ptr CURSORINFO
        CURSOR_SHOWING equ 00000001h
        if (WINVER ge 0602h)
          CURSOR_SUPPRESSED equ 00000002h
          ;* WINVER >= 0x0602 *
        endif
        @DefProto DllImport, GetCursorInfo, WIN_STD_CALL_CONV,, <:PCURSORINFO>, 4
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_GAMES) *
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        ;*
        ;* Window information snapshot
        ;*
        WINDOWINFO struct
          cbSize DWORD ?
          rcWindow RECT <>
          rcClient RECT <>
          dwStyle DWORD ?
          dwExStyle DWORD ?
          dwWindowStatus DWORD ?
          cxWindowBorders DWORD ?
          cyWindowBorders DWORD ?
          atomWindowType ATOM ?
          wCreatorVersion WORD ?
        WINDOWINFO ends
        tagWINDOWINFO typedef WINDOWINFO
        PWINDOWINFO typedef ptr WINDOWINFO
        LPWINDOWINFO typedef ptr WINDOWINFO
        WS_ACTIVECAPTION equ 0001h
        @DefProto DllImport, GetWindowInfo, WIN_STD_CALL_CONV,, <:HWND, :PWINDOWINFO>, 8
        ;*
        ;* Titlebar information.
        ;*
        TITLEBARINFO struct
          cbSize DWORD ?
          rcTitleBar RECT <>
          rgstate DWORD CCHILDREN_TITLEBAR + 1 dup (?)
        TITLEBARINFO ends
        tagTITLEBARINFO typedef TITLEBARINFO
        PTITLEBARINFO typedef ptr TITLEBARINFO
        LPTITLEBARINFO typedef ptr TITLEBARINFO
        @DefProto DllImport, GetTitleBarInfo, WIN_STD_CALL_CONV,, <:HWND, :PTITLEBARINFO>, 8
        if (WINVER ge 0600h)
          TITLEBARINFOEX struct
            cbSize DWORD ?
            rcTitleBar RECT <>
            rgstate DWORD CCHILDREN_TITLEBAR + 1 dup (?)
            rgrect RECT CCHILDREN_TITLEBAR + 1 dup (<>)
          TITLEBARINFOEX ends
          tagTITLEBARINFOEX typedef TITLEBARINFOEX
          PTITLEBARINFOEX typedef ptr TITLEBARINFOEX
          LPTITLEBARINFOEX typedef ptr TITLEBARINFOEX
          ;* WINVER >= 0x0600 *
        endif
        ;*
        ;* Menubar information
        ;*
        MENUBARINFO struct
          cbSize DWORD ?
          rcBar RECT <>
          ; rect of bar, popup, item
          hMenu HMENU ?
          ; real menu handle of bar, popup
          hwndMenu HWND ?
          ; hwnd of item submenu if one
          ; bar, popup has the focus
          ; item has the focus
          MENUBARINFO_REC record MENUBARINFO_REC_fUnused:30, MENUBARINFO_REC_fFocused:1, MENUBARINFO_REC_fBarFocused:1
          MENUBARINFO_BITS MENUBARINFO_REC <>
          ; reserved
        MENUBARINFO ends
        tagMENUBARINFO typedef MENUBARINFO
        PMENUBARINFO typedef ptr MENUBARINFO
        LPMENUBARINFO typedef ptr MENUBARINFO
        @DefProto DllImport, GetMenuBarInfo, WIN_STD_CALL_CONV,, <:HWND, :LONG, :LONG, :PMENUBARINFO>, 16
        ;*
        ;* Scrollbar information
        ;*
        SCROLLBARINFO struct
          cbSize DWORD ?
          rcScrollBar RECT <>
          dxyLineButton SDWORD ?
          xyThumbTop SDWORD ?
          xyThumbBottom SDWORD ?
          reserved SDWORD ?
          rgstate DWORD CCHILDREN_SCROLLBAR + 1 dup (?)
        SCROLLBARINFO ends
        tagSCROLLBARINFO typedef SCROLLBARINFO
        PSCROLLBARINFO typedef ptr SCROLLBARINFO
        LPSCROLLBARINFO typedef ptr SCROLLBARINFO
        @DefProto DllImport, GetScrollBarInfo, WIN_STD_CALL_CONV,, <:HWND, :LONG, :PSCROLLBARINFO>, 12
        ;*
        ;* Combobox information
        ;*
        COMBOBOXINFO struct
          cbSize DWORD ?
          rcItem RECT <>
          rcButton RECT <>
          stateButton DWORD ?
          hwndCombo HWND ?
          hwndItem HWND ?
          hwndList HWND ?
        COMBOBOXINFO ends
        tagCOMBOBOXINFO typedef COMBOBOXINFO
        PCOMBOBOXINFO typedef ptr COMBOBOXINFO
        LPCOMBOBOXINFO typedef ptr COMBOBOXINFO
        @DefProto DllImport, GetComboBoxInfo, WIN_STD_CALL_CONV,, <:HWND, :PCOMBOBOXINFO>, 8
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;*
      ;* The "real" ancestor window
      ;*
      GA_PARENT equ 1
      GA_ROOT equ 2
      GA_ROOTOWNER equ 3
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, GetAncestor, WIN_STD_CALL_CONV,, <:HWND, :UINT>, 8
        ;*
        ;* This gets the REAL child window at the point.  If it is in the dead
        ;* space of a group box, it will try a sibling behind it.  But static
        ;* fields will get returned.  In other words, it is kind of a cross between
        ;* ChildWindowFromPointEx and WindowFromPoint.
        ;*
        @DefProto DllImport, RealChildWindowFromPoint, WIN_STD_CALL_CONV,, <:HWND, :POINT>, 8
        ;*
        ;* This gets the name of the window TYPE, not class.  This allows us to
        ;* recognize ThunderButton32 et al.
        ;*
        @DefProto DllImport, RealGetWindowClassA, WIN_STD_CALL_CONV,, <:HWND, :LPSTR, :UINT>, 12
        ;*
        ;* This gets the name of the window TYPE, not class.  This allows us to
        ;* recognize ThunderButton32 et al.
        ;*
        @DefProto DllImport, RealGetWindowClassW, WIN_STD_CALL_CONV,, <:HWND, :LPWSTR, :UINT>, 12
        ifdef UNICODE
          RealGetWindowClass equ <RealGetWindowClassW>
        else
          RealGetWindowClass equ <RealGetWindowClassA>
        endif
        ; !UNICODE
        ;*
        ;* Alt-Tab Switch window information.
        ;*
        ALTTABINFO struct
          cbSize DWORD ?
          cItems SDWORD ?
          cColumns SDWORD ?
          cRows SDWORD ?
          iColFocus SDWORD ?
          iRowFocus SDWORD ?
          cxItem SDWORD ?
          cyItem SDWORD ?
          ptStart POINT <>
        ALTTABINFO ends
        tagALTTABINFO typedef ALTTABINFO
        PALTTABINFO typedef ptr ALTTABINFO
        LPALTTABINFO typedef ptr ALTTABINFO
        @DefProto DllImport, GetAltTabInfoA, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :PALTTABINFO, :LPSTR, :UINT>, 20
        @DefProto DllImport, GetAltTabInfoW, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :PALTTABINFO, :LPWSTR, :UINT>, 20
        ifdef UNICODE
          GetAltTabInfo equ <GetAltTabInfoW>
        else
          GetAltTabInfo equ <GetAltTabInfoA>
        endif
        ; !UNICODE
        ;*
        ;* Listbox information.
        ;* Returns the number of items per row.
        ;*
        @DefProto DllImport, GetListBoxInfo, WIN_STD_CALL_CONV,, <:HWND>, 4
        ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
      endif
      ;* NOWINABLE *
    endif
    ;* WINVER >= 0x0500 *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if (_WIN32_WINNT ge 0500h)
      @DefProto DllImport, LockWorkStation, WIN_STD_CALL_CONV,, <>, 0
      ;* _WIN32_WINNT >= 0x0500 *
    endif
    if (_WIN32_WINNT ge 0500h)
      @DefProto DllImport, UserHandleGrantAccess, WIN_STD_CALL_CONV,, <:HANDLE, :HANDLE, :BOOL>, 12
      ;* _WIN32_WINNT >= 0x0500 *
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  if (_WIN32_WINNT ge 0501h)
    ;*
    ;* Raw Input Messages.
    ;*
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      DECLARE_HANDLE HRAWINPUT
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ;*
    ;* WM_INPUT wParam
    ;*
    ;*
    ;* Use this macro to get the input code from wParam.
    ;*
    GET_RAWINPUT_CODE_WPARAM macro wParam
      exitm <((wParam) and 0ffh)>
    endm
    ;*
    ;* The input is in the regular message flow,
    ;* the app is required to call DefWindowProc
    ;* so that the system can perform clean ups.
    ;*
    RIM_INPUT equ 0
    ;*
    ;* The input is sink only. The app is expected
    ;* to behave nicely.
    ;*
    RIM_INPUTSINK equ 1
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ;*
      ;* Raw Input data header
      ;*
      RAWINPUTHEADER struct
        dwType DWORD ?
        dwSize DWORD ?
        hDevice HANDLE ?
        wParam WPARAM ?
      RAWINPUTHEADER ends
      tagRAWINPUTHEADER typedef RAWINPUTHEADER
      PRAWINPUTHEADER typedef ptr RAWINPUTHEADER
      LPRAWINPUTHEADER typedef ptr RAWINPUTHEADER
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ;*
    ;* Type of the raw input
    ;*
    RIM_TYPEMOUSE equ 0
    RIM_TYPEKEYBOARD equ 1
    RIM_TYPEHID equ 2
    RIM_TYPEMAX equ 2
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ;Disable warning C4201:nameless struct/union
      if _MSC_VER ge 1200
      endif
      ;*
      ;* Raw format of the mouse input
      ;*
      RAWMOUSE struct
        ;*
        ;* Indicator flags.
        ;*
        usFlags WORD ?
        ;*
        ;* The transition state of the mouse buttons.
        ;*
        union
          ulButtons DWORD ?
          struct
            usButtonFlags WORD ?
            usButtonData WORD ?
          ends
        ends
        ;*
        ;* The raw state of the mouse buttons.
        ;*
        ulRawButtons DWORD ?
        ;*
        ;* The signed relative or absolute motion in the X direction.
        ;*
        lLastX SDWORD ?
        ;*
        ;* The signed relative or absolute motion in the Y direction.
        ;*
        lLastY SDWORD ?
        ;*
        ;* Device-specific additional information for the event.
        ;*
        ulExtraInformation DWORD ?
      RAWMOUSE ends
      tagRAWMOUSE typedef RAWMOUSE
      PRAWMOUSE typedef ptr RAWMOUSE
      LPRAWMOUSE typedef ptr RAWMOUSE
      if _MSC_VER ge 1200
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ;*
    ;* Define the mouse button state indicators.
    ;*
    RI_MOUSE_LEFT_BUTTON_DOWN equ 0001h; Left Button changed to down.

    RI_MOUSE_LEFT_BUTTON_UP equ 0002h; Left Button changed to up.

    RI_MOUSE_RIGHT_BUTTON_DOWN equ 0004h; Right Button changed to down.

    RI_MOUSE_RIGHT_BUTTON_UP equ 0008h; Right Button changed to up.

    RI_MOUSE_MIDDLE_BUTTON_DOWN equ 0010h; Middle Button changed to down.

    RI_MOUSE_MIDDLE_BUTTON_UP equ 0020h; Middle Button changed to up.

    RI_MOUSE_BUTTON_1_DOWN equ <RI_MOUSE_LEFT_BUTTON_DOWN>
    RI_MOUSE_BUTTON_1_UP equ <RI_MOUSE_LEFT_BUTTON_UP>
    RI_MOUSE_BUTTON_2_DOWN equ <RI_MOUSE_RIGHT_BUTTON_DOWN>
    RI_MOUSE_BUTTON_2_UP equ <RI_MOUSE_RIGHT_BUTTON_UP>
    RI_MOUSE_BUTTON_3_DOWN equ <RI_MOUSE_MIDDLE_BUTTON_DOWN>
    RI_MOUSE_BUTTON_3_UP equ <RI_MOUSE_MIDDLE_BUTTON_UP>
    RI_MOUSE_BUTTON_4_DOWN equ 0040h
    RI_MOUSE_BUTTON_4_UP equ 0080h
    RI_MOUSE_BUTTON_5_DOWN equ 0100h
    RI_MOUSE_BUTTON_5_UP equ 0200h
    ;*
    ;* If usButtonFlags has RI_MOUSE_WHEEL, the wheel delta is stored in usButtonData.
    ;* Take it as a signed value.
    ;*
    RI_MOUSE_WHEEL equ 0400h
    if (WINVER ge 0600h)
      RI_MOUSE_HWHEEL equ 0800h
      ;* WINVER >= 0x0600 *
    endif
    ;*
    ;* Define the mouse indicator flags.
    ;*
    MOUSE_MOVE_RELATIVE equ 0
    MOUSE_MOVE_ABSOLUTE equ 1
    MOUSE_VIRTUAL_DESKTOP equ 02h; the coordinates are mapped to the virtual desktop

    MOUSE_ATTRIBUTES_CHANGED equ 04h; requery for mouse attributes

    if (WINVER ge 0600h)
      MOUSE_MOVE_NOCOALESCE equ 08h; do not coalesce mouse moves

      ;* WINVER >= 0x0600 *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ;*
      ;* Raw format of the keyboard input
      ;*
      RAWKEYBOARD struct
        ;*
        ;* The "make" scan code (key depression).
        ;*
        MakeCode WORD ?
        ;*
        ;* The flags field indicates a "break" (key release) and other
        ;* miscellaneous scan code information defined in ntddkbd.h.
        ;*
        Flags WORD ?
        Reserved WORD ?
        ;*
        ;* Windows message compatible information
        ;*
        VKey WORD ?
        Message DWORD ?
        ;*
        ;* Device-specific additional information for the event.
        ;*
        ExtraInformation DWORD ?
      RAWKEYBOARD ends
      tagRAWKEYBOARD typedef RAWKEYBOARD
      PRAWKEYBOARD typedef ptr RAWKEYBOARD
      LPRAWKEYBOARD typedef ptr RAWKEYBOARD
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ;*
    ;* Define the keyboard overrun MakeCode.
    ;*
    KEYBOARD_OVERRUN_MAKE_CODE equ 0FFh
    ;*
    ;* Define the keyboard input data Flags.
    ;*
    RI_KEY_MAKE equ 0
    RI_KEY_BREAK equ 1
    RI_KEY_E0 equ 2
    RI_KEY_E1 equ 4
    RI_KEY_TERMSRV_SET_LED equ 8
    RI_KEY_TERMSRV_SHADOW equ 10h
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ;*
      ;* Raw format of the input from Human Input Devices
      ;*
      RAWHID struct
        dwSizeHid DWORD ?
        ; byte size of each report
        dwCount DWORD ?
        ; number of input packed
        bRawData BYTE 1 dup (?)
      RAWHID ends
      tagRAWHID typedef RAWHID
      PRAWHID typedef ptr RAWHID
      LPRAWHID typedef ptr RAWHID
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ;*
    ;* RAWINPUT data structure.
    ;*
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      RAWINPUT struct
        header RAWINPUTHEADER <>
        union data
          mouse RAWMOUSE <>
          keyboard RAWKEYBOARD <>
          hid RAWHID <>
        ends
      RAWINPUT ends
      tagRAWINPUT typedef RAWINPUT
      PRAWINPUT typedef ptr RAWINPUT
      LPRAWINPUT typedef ptr RAWINPUT
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ifdef _WIN64
      RAWINPUT_ALIGN macro x
        exitm <(((x) + sizeof(QWORD) - 1) and not (sizeof(QWORD) - 1))>
      endm
    else
    ; _WIN64
      RAWINPUT_ALIGN macro x
        exitm <(((x) + sizeof(DWORD) - 1) and not (sizeof(DWORD) - 1))>
      endm
    endif
    ; _WIN64
    NEXTRAWINPUTBLOCK macro ptr_
      exitm <((PRAWINPUT) RAWINPUT_ALIGN(((ptr_) + (ptr_) - header.dwSize)))>
    endm
    ;*
    ;* Flags for GetRawInputData
    ;*
    RID_INPUT equ 10000003h
    RID_HEADER equ 10000005h
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, GetRawInputData, WIN_STD_CALL_CONV,, <:HRAWINPUT, :UINT, :LPVOID, :PUINT, :UINT>, 20
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ;*
    ;* Raw Input Device Information
    ;*
    RIDI_PREPARSEDDATA equ 20000005h
    RIDI_DEVICENAME equ 20000007h; the return valus is the character length, not the byte size

    RIDI_DEVICEINFO equ 2000000bh
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      RID_DEVICE_INFO_MOUSE struct
        dwId DWORD ?
        dwNumberOfButtons DWORD ?
        dwSampleRate DWORD ?
        fHasHorizontalWheel DWORD ?
      RID_DEVICE_INFO_MOUSE ends
      tagRID_DEVICE_INFO_MOUSE typedef RID_DEVICE_INFO_MOUSE
      PRID_DEVICE_INFO_MOUSE typedef ptr RID_DEVICE_INFO_MOUSE
      RID_DEVICE_INFO_KEYBOARD struct
        dwType DWORD ?
        dwSubType DWORD ?
        dwKeyboardMode DWORD ?
        dwNumberOfFunctionKeys DWORD ?
        dwNumberOfIndicators DWORD ?
        dwNumberOfKeysTotal DWORD ?
      RID_DEVICE_INFO_KEYBOARD ends
      tagRID_DEVICE_INFO_KEYBOARD typedef RID_DEVICE_INFO_KEYBOARD
      PRID_DEVICE_INFO_KEYBOARD typedef ptr RID_DEVICE_INFO_KEYBOARD
      RID_DEVICE_INFO_HID struct
        dwVendorId DWORD ?
        dwProductId DWORD ?
        dwVersionNumber DWORD ?
        ;*
        ;* Top level collection UsagePage and Usage
        ;*
        usUsagePage WORD ?
        usUsage WORD ?
      RID_DEVICE_INFO_HID ends
      tagRID_DEVICE_INFO_HID typedef RID_DEVICE_INFO_HID
      PRID_DEVICE_INFO_HID typedef ptr RID_DEVICE_INFO_HID
      RID_DEVICE_INFO struct
        cbSize DWORD ?
        dwType DWORD ?
        union
          mouse RID_DEVICE_INFO_MOUSE <>
          keyboard RID_DEVICE_INFO_KEYBOARD <>
          hid RID_DEVICE_INFO_HID <>
        ends
      RID_DEVICE_INFO ends
      tagRID_DEVICE_INFO typedef RID_DEVICE_INFO
      PRID_DEVICE_INFO typedef ptr RID_DEVICE_INFO
      LPRID_DEVICE_INFO typedef ptr RID_DEVICE_INFO
      @DefProto DllImport, GetRawInputDeviceInfoA, WIN_STD_CALL_CONV,, <:HANDLE, :UINT, :LPVOID, :PUINT>, 16
      @DefProto DllImport, GetRawInputDeviceInfoW, WIN_STD_CALL_CONV,, <:HANDLE, :UINT, :LPVOID, :PUINT>, 16
      ifdef UNICODE
        GetRawInputDeviceInfo equ <GetRawInputDeviceInfoW>
      else
        GetRawInputDeviceInfo equ <GetRawInputDeviceInfoA>
      endif
      ; !UNICODE
      ;*
      ;* Raw Input Bulk Read: GetRawInputBuffer
      ;*
      @DefProto DllImport, GetRawInputBuffer, WIN_STD_CALL_CONV,, <:PRAWINPUT, :PUINT, :UINT>, 12
      ;*
      ;* Raw Input request APIs
      ;*
      RAWINPUTDEVICE struct
        usUsagePage WORD ?
        ; Toplevel collection UsagePage
        usUsage WORD ?
        ; Toplevel collection Usage
        dwFlags DWORD ?
        hwndTarget HWND ?
        ; Target hwnd. NULL = follows keyboard focus
      RAWINPUTDEVICE ends
      tagRAWINPUTDEVICE typedef RAWINPUTDEVICE
      PRAWINPUTDEVICE typedef ptr RAWINPUTDEVICE
      LPRAWINPUTDEVICE typedef ptr RAWINPUTDEVICE
      PCRAWINPUTDEVICE typedef ptr RAWINPUTDEVICE
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    RIDEV_REMOVE equ 00000001h
    RIDEV_EXCLUDE equ 00000010h
    RIDEV_PAGEONLY equ 00000020h
    RIDEV_NOLEGACY equ 00000030h
    RIDEV_INPUTSINK equ 00000100h
    RIDEV_CAPTUREMOUSE equ 00000200h; effective when mouse nolegacy is specified, otherwise it would be an error

    RIDEV_NOHOTKEYS equ 00000200h; effective for keyboard.

    RIDEV_APPKEYS equ 00000400h; effective for keyboard.

    if (_WIN32_WINNT ge 0501h)
      RIDEV_EXINPUTSINK equ 00001000h
      RIDEV_DEVNOTIFY equ 00002000h
      ;* _WIN32_WINNT >= 0x0501 *
    endif
    RIDEV_EXMODEMASK equ 000000F0h
    RIDEV_EXMODE macro mode
      exitm <((mode) and RIDEV_EXMODEMASK)>
    endm
    if (_WIN32_WINNT ge 0501h)
      ;*
      ;* Flags for the WM_INPUT_DEVICE_CHANGE message.
      ;*
      GIDC_ARRIVAL equ 1
      GIDC_REMOVAL equ 2
      ;* _WIN32_WINNT >= 0x0501 *
    endif
    if (_WIN32_WINNT ge 0601h)
      GET_DEVICE_CHANGE_WPARAM macro wParam
        exitm <(LOWORD(wParam))>
      endm
    elseif (_WIN32_WINNT ge 0501h)
      GET_DEVICE_CHANGE_LPARAM macro lParam
        exitm <(LOWORD(lParam))>
      endm
      ;* (_WIN32_WINNT >= 0x0601) *
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, RegisterRawInputDevices, WIN_STD_CALL_CONV,, <:PCRAWINPUTDEVICE, :UINT, :UINT>, 12
      @DefProto DllImport, GetRegisteredRawInputDevices, WIN_STD_CALL_CONV,, <:PRAWINPUTDEVICE, :PUINT, :UINT>, 12
      RAWINPUTDEVICELIST struct
        hDevice HANDLE ?
        dwType DWORD ?
      RAWINPUTDEVICELIST ends
      tagRAWINPUTDEVICELIST typedef RAWINPUTDEVICELIST
      PRAWINPUTDEVICELIST typedef ptr RAWINPUTDEVICELIST
      @DefProto DllImport, GetRawInputDeviceList, WIN_STD_CALL_CONV,, <:PRAWINPUTDEVICELIST, :PUINT, :UINT>, 12
      @DefProto DllImport, DefRawInputProc, WIN_STD_CALL_CONV,, <:ptr PRAWINPUT, :INT_, :UINT>, 12
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ;* _WIN32_WINNT >= 0x0501 *
  endif
  if (WINVER ge 0602h)
    POINTER_DEVICE_PRODUCT_STRING_MAX equ 520
    ;*
    ;* wParam values for WM_POINTERDEVICECHANGE
    ;*
    PDC_ARRIVAL equ 001h
    PDC_REMOVAL equ 002h
    PDC_ORIENTATION_0 equ 004h
    PDC_ORIENTATION_90 equ 008h
    PDC_ORIENTATION_180 equ 010h
    PDC_ORIENTATION_270 equ 020h
    PDC_MODE_DEFAULT equ 040h
    PDC_MODE_CENTERED equ 080h
    PDC_MAPPING_CHANGE equ 100h
    PDC_RESOLUTION equ 200h
    PDC_ORIGIN equ 400h
    PDC_MODE_ASPECTRATIOPRESERVED equ 800h
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      POINTER_DEVICE_TYPE typedef SDWORD
      POINTER_DEVICE_TYPE_INTEGRATED_PEN equ 00000001h
      POINTER_DEVICE_TYPE_EXTERNAL_PEN equ 00000002h
      POINTER_DEVICE_TYPE_TOUCH equ 00000003h
      if (WINVER ge 0603h)
        POINTER_DEVICE_TYPE_TOUCH_PAD equ 00000004h
        ;* WINVER >= 0x0603 *
      endif
      POINTER_DEVICE_TYPE_MAX equ 0FFFFFFFFh
      tagPOINTER_DEVICE_TYPE typedef POINTER_DEVICE_TYPE

      POINTER_DEVICE_INFO struct
        displayOrientation DWORD ?
        device HANDLE ?
        pointerDeviceType POINTER_DEVICE_TYPE ?
        monitor_ HMONITOR ?
        startingCursorId DWORD ?
        maxActiveContacts WORD ?
        productString WORD POINTER_DEVICE_PRODUCT_STRING_MAX dup (?)
      POINTER_DEVICE_INFO ends
      tagPOINTER_DEVICE_INFO typedef POINTER_DEVICE_INFO
      POINTER_DEVICE_PROPERTY struct
        logicalMin SDWORD ?
        logicalMax SDWORD ?
        physicalMin SDWORD ?
        physicalMax SDWORD ?
        unit DWORD ?
        unitExponent DWORD ?
        usagePageId WORD ?
        usageId WORD ?
      POINTER_DEVICE_PROPERTY ends
      tagPOINTER_DEVICE_PROPERTY typedef POINTER_DEVICE_PROPERTY
      POINTER_DEVICE_CURSOR_TYPE typedef SDWORD
      POINTER_DEVICE_CURSOR_TYPE_UNKNOWN equ 00000000h
      POINTER_DEVICE_CURSOR_TYPE_TIP equ 00000001h
      POINTER_DEVICE_CURSOR_TYPE_ERASER equ 00000002h
      POINTER_DEVICE_CURSOR_TYPE_MAX equ 0FFFFFFFFh
      tagPOINTER_DEVICE_CURSOR_TYPE typedef POINTER_DEVICE_CURSOR_TYPE

      POINTER_DEVICE_CURSOR_INFO struct
        cursorId DWORD ?
        cursor POINTER_DEVICE_CURSOR_TYPE ?
      POINTER_DEVICE_CURSOR_INFO ends
      tagPOINTER_DEVICE_CURSOR_INFO typedef POINTER_DEVICE_CURSOR_INFO
      @DefProto DllImport, GetPointerDevices, WIN_STD_CALL_CONV,, <:ptr UINT32, :ptr POINTER_DEVICE_INFO>, 8
      @DefProto DllImport, GetPointerDevice, WIN_STD_CALL_CONV,, <:HANDLE, :ptr POINTER_DEVICE_INFO>, 8
      @DefProto DllImport, GetPointerDeviceProperties, WIN_STD_CALL_CONV,, <:HANDLE, :ptr UINT32, :ptr POINTER_DEVICE_PROPERTY>, 12
      @DefProto DllImport, RegisterPointerDeviceNotifications, WIN_STD_CALL_CONV,, <:HWND, :BOOL>, 8
      @DefProto DllImport, GetPointerDeviceRects, WIN_STD_CALL_CONV,, <:HANDLE, :ptr RECT, :ptr RECT>, 12
      @DefProto DllImport, GetPointerDeviceCursors, WIN_STD_CALL_CONV,, <:HANDLE, :ptr UINT32, :ptr POINTER_DEVICE_CURSOR_INFO>, 12
      @DefProto DllImport, GetRawPointerDeviceData, WIN_STD_CALL_CONV,, <:UINT32, :UINT32, :UINT32, :ptr POINTER_DEVICE_PROPERTY, :ptr LONG>, 20
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ;* WINVER >= 0x0602 *
  endif
  if (WINVER ge 0600h)
    ;*
    ;* Message Filter
    ;*
    MSGFLT_ADD equ 1
    MSGFLT_REMOVE equ 2
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, ChangeWindowMessageFilter, WIN_STD_CALL_CONV,, <:UINT, :DWORD>, 8
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ;* WINVER >= 0x0600 *
  endif
  if (WINVER ge 0601h)
    ;*
    ;* Message filter info values (CHANGEFILTERSTRUCT.ExtStatus)
    ;*
    MSGFLTINFO_NONE equ (0)
    MSGFLTINFO_ALREADYALLOWED_FORWND equ (1)
    MSGFLTINFO_ALREADYDISALLOWED_FORWND equ (2)
    MSGFLTINFO_ALLOWED_HIGHER equ (3)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      CHANGEFILTERSTRUCT struct
        cbSize DWORD ?
        ExtStatus DWORD ?
      CHANGEFILTERSTRUCT ends
      tagCHANGEFILTERSTRUCT typedef CHANGEFILTERSTRUCT
      PCHANGEFILTERSTRUCT typedef ptr CHANGEFILTERSTRUCT
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ;*
    ;* Message filter action values (action parameter to ChangeWindowMessageFilterEx)
    ;*
    MSGFLT_RESET equ (0)
    MSGFLT_ALLOW equ (1)
    MSGFLT_DISALLOW equ (2)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, ChangeWindowMessageFilterEx, WIN_STD_CALL_CONV,, <:HWND, :UINT, :DWORD, :PCHANGEFILTERSTRUCT>, 16
      ; Message filter action value
      ; Optional
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ;* WINVER >= 0x0601 *
  endif
  if (WINVER ge 0601h)
    ;* WINVER >= 0x0601 *
  endif
  if (WINVER ge 0601h)
    ;*
    ;* Gesture defines and functions
    ;*
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ;*
      ;* Gesture information handle
      ;*
      DECLARE_HANDLE HGESTUREINFO
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ;*
    ;* Gesture flags - GESTUREINFO.dwFlags
    ;*
    GF_BEGIN equ 00000001h
    GF_INERTIA equ 00000002h
    GF_END equ 00000004h
    ;*
    ;* Gesture IDs
    ;*
    GID_BEGIN equ 1
    GID_END equ 2
    GID_ZOOM equ 3
    GID_PAN equ 4
    GID_ROTATE equ 5
    GID_TWOFINGERTAP equ 6
    GID_PRESSANDTAP equ 7
    GID_ROLLOVER equ <GID_PRESSANDTAP>
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ;*
      ;* Gesture information structure
      ;*   - Pass the HGESTUREINFO received in the WM_GESTURE message lParam into the
      ;*     GetGestureInfo function to retrieve this information.
      ;*   - If cbExtraArgs is non-zero, pass the HGESTUREINFO received in the WM_GESTURE
      ;*     message lParam into the GetGestureExtraArgs function to retrieve extended
      ;*     argument information.
      ;*
      GESTUREINFO struct
        cbSize DWORD ?
        ; size, in bytes, of this structure (including variable length Args field)
        dwFlags DWORD ?
        ; see GF_* flags
        dwID DWORD ?
        ; gesture ID, see GID_* defines
        hwndTarget HWND ?
        ; handle to window targeted by this gesture
        ptsLocation POINTS <>
        ; current location of this gesture
        dwInstanceID DWORD ?
        ; internally used
        dwSequenceID DWORD ?
        ; internally used
        ullArguments QWORD ?
        ; arguments for gestures whose arguments fit in 8 BYTES
        cbExtraArgs DWORD ?
        ; size, in bytes, of extra arguments, if any, that accompany this gesture
      GESTUREINFO ends
      tagGESTUREINFO typedef GESTUREINFO
      PGESTUREINFO typedef ptr GESTUREINFO
      PCGESTUREINFO typedef ptr GESTUREINFO
      ;*
      ;* Gesture notification structure
      ;*   - The WM_GESTURENOTIFY message lParam contains a pointer to this structure.
      ;*   - The WM_GESTURENOTIFY message notifies a window that gesture recognition is
      ;*     in progress and a gesture will be generated if one is recognized under the
      ;*     current gesture settings.
      ;*
      GESTURENOTIFYSTRUCT struct
        cbSize DWORD ?
        ; size, in bytes, of this structure
        dwFlags DWORD ?
        ; unused
        hwndTarget HWND ?
        ; handle to window targeted by the gesture
        ptsLocation POINTS <>
        ; starting location
        dwInstanceID DWORD ?
        ; internally used
      GESTURENOTIFYSTRUCT ends
      tagGESTURENOTIFYSTRUCT typedef GESTURENOTIFYSTRUCT
      PGESTURENOTIFYSTRUCT typedef ptr GESTURENOTIFYSTRUCT
      ;*
      ;* Gesture argument helpers
      ;*   - Angle should be a double in the range of -2pi to +2pi
      ;*   - Argument should be an unsigned 16-bit value
      ;*
      GID_ROTATE_ANGLE_TO_ARGUMENT macro _arg_
        exitm <(((((_arg_) + 2.0 * 3.14159265) / (4.0 * 3.14159265)) * 65535.0))>
      endm
      GID_ROTATE_ANGLE_FROM_ARGUMENT macro _arg_
        exitm <((((_arg_) / 65535.0) * 4.0 * 3.14159265) - 2.0 * 3.14159265)>
      endm
      ;*
      ;* Gesture information retrieval
      ;*   - HGESTUREINFO is received by a window in the lParam of a WM_GESTURE message.
      ;*
      @DefProto DllImport, GetGestureInfo, WIN_STD_CALL_CONV,, <:HGESTUREINFO, :PGESTUREINFO>, 8
      ;*
      ;* Gesture extra arguments retrieval
      ;*   - HGESTUREINFO is received by a window in the lParam of a WM_GESTURE message.
      ;*   - Size, in bytes, of the extra argument data is available in the cbExtraArgs
      ;*     field of the GESTUREINFO structure retrieved using the GetGestureInfo function.
      ;*
      @DefProto DllImport, GetGestureExtraArgs, WIN_STD_CALL_CONV,, <:HGESTUREINFO, :UINT, :PBYTE>, 12
      ;*
      ;* Gesture information handle management
      ;*   - If an application processes the WM_GESTURE message, then once it is done
      ;*     with the associated HGESTUREINFO, the application is responsible for
      ;*     closing the handle using this function. Failure to do so may result in
      ;*     process memory leaks.
      ;*   - If the message is instead passed to DefWindowProc, or is forwarded using
      ;*     one of the PostMessage or SendMessage class of API functions, the handle
      ;*     is transfered with the message and need not be closed by the application.
      ;*
      @DefProto DllImport, CloseGestureInfoHandle, WIN_STD_CALL_CONV,, <:HGESTUREINFO>, 4
      ;*
      ;* Gesture configuration structure
      ;*   - Used in SetGestureConfig and GetGestureConfig
      ;*   - Note that any setting not included in either GESTURECONFIG.dwWant or
      ;*     GESTURECONFIG.dwBlock will use the parent window's preferences or
      ;*     system defaults.
      ;*
      GESTURECONFIG struct
        dwID DWORD ?
        ; gesture ID
        dwWant DWORD ?
        ; settings related to gesture ID that are to be turned on
        dwBlock DWORD ?
        ; settings related to gesture ID that are to be turned off
      GESTURECONFIG ends
      tagGESTURECONFIG typedef GESTURECONFIG
      PGESTURECONFIG typedef ptr GESTURECONFIG
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ;*
    ;* Gesture configuration flags - GESTURECONFIG.dwWant or GESTURECONFIG.dwBlock
    ;*
    ;*
    ;* Common gesture configuration flags - set GESTURECONFIG.dwID to zero
    ;*
    GC_ALLGESTURES equ 00000001h
    ;*
    ;* Zoom gesture configuration flags - set GESTURECONFIG.dwID to GID_ZOOM
    ;*
    GC_ZOOM equ 00000001h
    ;*
    ;* Pan gesture configuration flags - set GESTURECONFIG.dwID to GID_PAN
    ;*
    GC_PAN equ 00000001h
    GC_PAN_WITH_SINGLE_FINGER_VERTICALLY equ 00000002h
    GC_PAN_WITH_SINGLE_FINGER_HORIZONTALLY equ 00000004h
    GC_PAN_WITH_GUTTER equ 00000008h
    GC_PAN_WITH_INERTIA equ 00000010h
    ;*
    ;* Rotate gesture configuration flags - set GESTURECONFIG.dwID to GID_ROTATE
    ;*
    GC_ROTATE equ 00000001h
    ;*
    ;* Two finger tap gesture configuration flags - set GESTURECONFIG.dwID to GID_TWOFINGERTAP
    ;*
    GC_TWOFINGERTAP equ 00000001h
    ;*
    ;* PressAndTap gesture configuration flags - set GESTURECONFIG.dwID to GID_PRESSANDTAP
    ;*
    GC_PRESSANDTAP equ 00000001h
    GC_ROLLOVER equ <GC_PRESSANDTAP>
    GESTURECONFIGMAXCOUNT equ 256; Maximum number of gestures that can be included

    ; in a single call to SetGestureConfig / GetGestureConfig
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, SetGestureConfig, WIN_STD_CALL_CONV,, <:HWND, :DWORD, :UINT, :PGESTURECONFIG, :UINT>, 20
      ; order specified and repeated occurances will overwrite previous ones
      ; sizeof(GESTURECONFIG)
      GCF_INCLUDE_ANCESTORS equ 00000001h; If specified, GetGestureConfig returns consolidated configuration

      ; for the specified window and it's parent window chain
      @DefProto DllImport, GetGestureConfig, WIN_STD_CALL_CONV,, <:HWND, :DWORD, :DWORD, :PUINT, :PGESTURECONFIG, :UINT>, 24
      ; pointer to buffer to receive the returned array of GESTURECONFIG structures
      ; sizeof(GESTURECONFIG)
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ;* WINVER >= 0x0601 *
  endif
  if (WINVER ge 0601h)
    ;*
    ;* GetSystemMetrics(SM_DIGITIZER) flag values
    ;*
    NID_INTEGRATED_TOUCH equ 00000001h
    NID_EXTERNAL_TOUCH equ 00000002h
    NID_INTEGRATED_PEN equ 00000004h
    NID_EXTERNAL_PEN equ 00000008h
    NID_MULTI_INPUT equ 00000040h
    NID_READY equ 00000080h
    ;* WINVER >= 0x0601 *
  endif
  MAX_STR_BLOCKREASON equ 256
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    @DefProto DllImport, ShutdownBlockReasonCreate, WIN_STD_CALL_CONV,, <:HWND, :LPCWSTR>, 8
    @DefProto DllImport, ShutdownBlockReasonQuery, WIN_STD_CALL_CONV,, <:HWND, :LPWSTR, :ptr DWORD>, 12
    @DefProto DllImport, ShutdownBlockReasonDestroy, WIN_STD_CALL_CONV,, <:HWND>, 4
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  if (WINVER ge 0601h)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ;*
      ;* Identifiers for message input source device type.
      ;*
      INPUT_MESSAGE_DEVICE_TYPE typedef SDWORD
      IMDT_UNAVAILABLE equ 00000000h
      ; not specified
      IMDT_KEYBOARD equ 00000001h
      ; from keyboard
      IMDT_MOUSE equ 00000002h
      ; from mouse
      IMDT_TOUCH equ 00000004h
      ; from touch
      IMDT_PEN equ 00000008h
      ; from pen
      if (WINVER ge 0603h)
        IMDT_TOUCHPAD equ 00000010h
        ; from touchpad
        ;* WINVER >= 0x0603 *
      endif
      tagINPUT_MESSAGE_DEVICE_TYPE typedef INPUT_MESSAGE_DEVICE_TYPE

      INPUT_MESSAGE_ORIGIN_ID typedef SDWORD
      IMO_UNAVAILABLE equ 00000000h
      ; not specified
      IMO_HARDWARE equ 00000001h
      ; from a hardware device or injected by a UIAccess app
      IMO_INJECTED equ 00000002h
      ; injected via SendInput() by a non-UIAccess app
      IMO_SYSTEM equ 00000004h
      ; injected by the system
      tagINPUT_MESSAGE_ORIGIN_ID typedef INPUT_MESSAGE_ORIGIN_ID

      ;*
      ;* Input source structure.
      ;*
      INPUT_MESSAGE_SOURCE struct
        deviceType INPUT_MESSAGE_DEVICE_TYPE ?
        originId INPUT_MESSAGE_ORIGIN_ID ?
      INPUT_MESSAGE_SOURCE ends
      tagINPUT_MESSAGE_SOURCE typedef INPUT_MESSAGE_SOURCE
      ;*
      ;* API to determine the input source of the current messsage.
      ;*
      @DefProto DllImport, GetCurrentInputMessageSource, WIN_STD_CALL_CONV,, <:ptr INPUT_MESSAGE_SOURCE>, 4
      @DefProto DllImport, GetCIMSSM, WIN_STD_CALL_CONV,, <:ptr INPUT_MESSAGE_SOURCE>, 4
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ;* WINVER >= 0x0601 *
  endif
  if (WINVER ge 0602h)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      ;*
      ;* AutoRotation state structure
      ;*
      AR_STATE typedef SDWORD
      AR_ENABLED equ 0h
      AR_DISABLED equ 1h
      AR_SUPPRESSED equ 2h
      AR_REMOTESESSION equ 4h
      AR_MULTIMON equ 8h
      AR_NOSENSOR equ 10h
      AR_NOT_SUPPORTED equ 20h
      AR_DOCKED equ 40h
      AR_LAPTOP equ 80h
      tagAR_STATE typedef AR_STATE
      PAR_STATE typedef ptr AR_STATE
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) *
    endif
    ifndef MIDL_PASS
      ; Don't define this for MIDL compiler passes over winuser.h. Some of them
      ; don't include winnt.h (where DEFINE_ENUM_FLAG_OPERATORS is defined and
      ; get compile errors.
      DEFINE_ENUM_FLAG_OPERATORS(AR_STATE)
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ;*
      ;* Orientation preference structure. This is used by applications to specify
      ;* their orientation preferences to windows.
      ;*
      ORIENTATION_PREFERENCE typedef SDWORD
      ORIENTATION_PREFERENCE_NONE equ 0h
      ORIENTATION_PREFERENCE_LANDSCAPE equ 1h
      ORIENTATION_PREFERENCE_PORTRAIT equ 2h
      ORIENTATION_PREFERENCE_LANDSCAPE_FLIPPED equ 4h
      ORIENTATION_PREFERENCE_PORTRAIT_FLIPPED equ 8h

      ifndef MIDL_PASS
        ; Don't define this for MIDL compiler passes over winuser.h. Some of them
        ; don't include winnt.h (where DEFINE_ENUM_FLAG_OPERATORS is defined and
        ; get compile errors.
        DEFINE_ENUM_FLAG_OPERATORS(ORIENTATION_PREFERENCE)
      endif
      @DefProto DllImport, GetAutoRotationState, WIN_STD_CALL_CONV,, <:PAR_STATE>, 4
      @DefProto DllImport, GetDisplayAutoRotationPreferences, WIN_STD_CALL_CONV,, <:ptr ORIENTATION_PREFERENCE>, 4
      @DefProto DllImport, GetDisplayAutoRotationPreferencesByProcessId, WIN_STD_CALL_CONV,, <:DWORD, :ptr ORIENTATION_PREFERENCE, :ptr BOOL>, 12
      @DefProto DllImport, SetDisplayAutoRotationPreferences, WIN_STD_CALL_CONV,, <:ORIENTATION_PREFERENCE>, 4
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ;* WINVER >= 0x0602 *
  endif
  if (WINVER ge 0601h)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, IsImmersiveProcess, WIN_STD_CALL_CONV,, <:HANDLE>, 4
      @DefProto DllImport, SetProcessRestrictionExemption, WIN_STD_CALL_CONV,, <:BOOL>, 4
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ;* WINVER >= 0x0601 *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  ;*
  ;* Ink Feedback APIs
  ;*
  if (WINVER ge 0607h)
    @DefProto DllImport, SetAdditionalForegroundBoostProcesses, WIN_STD_CALL_CONV,, <:HWND, :DWORD, :ptr HANDLE>, 12
    ;* TOOLTIP_DISMISS_FLAGS:
    ;*
    ;* These are flags used with the RegisterForTooltipDismissNotification API.
    ;*
    ;* TDF_REGISTER -   Used to register tooltip to receive notification of trigger key combination
    ;*                  via WM_TOOLTIPDISMISS.
    ;*
    ;* TDF_UNREGISTER - Used to unregister tooltip from receiving notification of trigger key
    ;*                  combination via WM_TOOLTIPDISMISS.
    ;*
    TOOLTIP_DISMISS_FLAGS typedef SDWORD
    TDF_REGISTER equ 0001h
    TDF_UNREGISTER equ 0002h

    @DefProto DllImport, RegisterForTooltipDismissNotification, WIN_STD_CALL_CONV,, <:HWND, :TOOLTIP_DISMISS_FLAGS>, 8
    ;*
    ;* Support for Accessibility Tooltip Dismissal API:
    ;*
    ;* This message notifies apps/frameworks that a trigger event has occurred and they should dismiss the
    ;* respective tooltip window.
    ;* This is used with RegisterForTooltipDismissNotification.
    ;*
    ;* Note that only kernel mode can originate this message.
    ;*
    WM_TOOLTIPDISMISS equ 0345h
    ;* WINVER >= 0x0607 *
  endif
  if _MSC_VER ge 1200
  endif
  ;* RC complains about long symbols in #ifs *
  if  not Defined(RC_INVOKED)
    if Defined(ISOLATION_AWARE_ENABLED) and (ISOLATION_AWARE_ENABLED ne 0)
      ;[...]
    endif
    ;* RC *
  endif
  ifdef __cplusplus
    ;[...]
  endif
  ;* !_WINUSER_ *
endif
