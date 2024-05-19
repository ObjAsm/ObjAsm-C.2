;Include file created by h2inc+ version C.2.0 on (UTC) 19/05/2024 07:52:23
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\winuser.h\winuser.h
;             Created on (UTC) 06/04/2024 06:16:03
;             Last modified on (UTC) 21/02/2024 18:18:34

include winapifamily.inc
ifndef _WINUSER_
  _WINUSER_ equ <>
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
    endif
  endif
  ifndef WINVER
    WINVER equ 0500h
  endif
  include stdarg.inc
  ifndef NOAPISET
    include libloaderapi.inc
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
      LPMENUTEMPLATEA typedef PVOID
      LPMENUTEMPLATEW typedef PVOID
      ifdef UNICODE
        LPMENUTEMPLATE typedef LPMENUTEMPLATEW
      else
        LPMENUTEMPLATE typedef LPMENUTEMPLATEA
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      TYPE_WNDPROC typedef proto WIN_STD_CALL_CONV :HWND, :UINT, :WPARAM, :LPARAM
      WNDPROC typedef ptr TYPE_WNDPROC

    endif
    ifdef STRICT
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
        TYPE_DLGPROC typedef proto WIN_STD_CALL_CONV :HWND, :UINT, :WPARAM, :LPARAM
        DLGPROC typedef ptr TYPE_DLGPROC

      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
        TYPE_TIMERPROC typedef proto WIN_STD_CALL_CONV :HWND, :UINT, :UINT_PTR, :DWORD
        TIMERPROC typedef ptr TYPE_TIMERPROC

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

        endif
      endif
    else
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        DLGPROC typedef FARPROC
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
        TIMERPROC typedef FARPROC
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
        endif
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ifdef UNICODE
        PROPENUMPROC typedef PROPENUMPROCW
        PROPENUMPROCEX typedef PROPENUMPROCEXW
        EDITWORDBREAKPROC typedef EDITWORDBREAKPROCW
      else
        PROPENUMPROC typedef PROPENUMPROCA
        PROPENUMPROCEX typedef PROPENUMPROCEXA
        EDITWORDBREAKPROC typedef EDITWORDBREAKPROCA
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
      else
        NAMEENUMPROCA typedef FARPROC
        NAMEENUMPROCW typedef FARPROC
        WINSTAENUMPROCA typedef FARPROC
        DESKTOPENUMPROCA typedef FARPROC
        WINSTAENUMPROCW typedef FARPROC
        DESKTOPENUMPROCW typedef FARPROC
      endif
      ifdef UNICODE
        WINSTAENUMPROC typedef WINSTAENUMPROCW
        DESKTOPENUMPROC typedef DESKTOPENUMPROCW
      else
        WINSTAENUMPROC typedef WINSTAENUMPROCA
        DESKTOPENUMPROC typedef DESKTOPENUMPROCA
      endif
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
    ifndef NORESOURCE
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
        MINIMUM_RESERVED_MANIFEST_RESOURCE_ID equ MAKEINTRESOURCE (1)
        MAXIMUM_RESERVED_MANIFEST_RESOURCE_ID equ MAKEINTRESOURCE (16)
      endif
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
      @DefProto DllImport, wsprintfA, c,, <:LPSTR, :LPCSTR, :vararg>
      @DefProto DllImport, wsprintfW, c,, <:LPWSTR, :LPCWSTR, :vararg>
      ifdef UNICODE
        wsprintf equ <wsprintfW>
      else
        wsprintf equ <wsprintfA>
      endif
      if Defined(DEPRECATE_SUPPORTED)
      endif
    endif
    SETWALLPAPER_DEFAULT equ (- 1)
    ifndef NOSCROLL
      SB_HORZ equ 0
      SB_VERT equ 1
      SB_CTL equ 2
      SB_BOTH equ 3
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
    endif
    ifndef NOSHOWWINDOW
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
      HIDE_WINDOW equ 0
      SHOW_OPENWINDOW equ 1
      SHOW_ICONWINDOW equ 2
      SHOW_FULLSCREEN equ 3
      SHOW_OPENNOACTIVATE equ 4
      SW_PARENTCLOSING equ 1
      SW_OTHERZOOM equ 2
      SW_PARENTOPENING equ 3
      SW_OTHERUNZOOM equ 4
    endif
    if (WINVER ge 0500h)
      AW_HOR_POSITIVE equ 00000001h
      AW_HOR_NEGATIVE equ 00000002h
      AW_VER_POSITIVE equ 00000004h
      AW_VER_NEGATIVE equ 00000008h
      AW_CENTER equ 00000010h
      AW_HIDE equ 00010000h
      AW_ACTIVATE equ 00020000h
      AW_SLIDE equ 00040000h
      AW_BLEND equ 00080000h
    endif
    KF_EXTENDED equ 0100h
    KF_DLGMODE equ 0800h
    KF_MENUMODE equ 1000h
    KF_ALTDOWN equ 2000h
    KF_REPEAT equ 4000h
    KF_UP equ 8000h
    ifndef NOVIRTUALKEYCODES
      VK_LBUTTON equ 01h
      VK_RBUTTON equ 02h
      VK_CANCEL equ 03h
      VK_MBUTTON equ 04h
      if (_WIN32_WINNT ge 0500h)
        VK_XBUTTON1 equ 05h
        VK_XBUTTON2 equ 06h
      endif
      VK_BACK equ 08h
      VK_TAB equ 09h
      VK_CLEAR equ 0Ch
      VK_RETURN equ 0Dh
      VK_SHIFT equ 10h
      VK_CONTROL equ 11h
      VK_MENU equ 12h
      VK_PAUSE equ 13h
      VK_CAPITAL equ 14h
      VK_KANA equ 15h
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
      VK_LWIN equ 5Bh
      VK_RWIN equ 5Ch
      VK_APPS equ 5Dh
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
        VK_NAVIGATION_VIEW equ 88h
        VK_NAVIGATION_MENU equ 89h
        VK_NAVIGATION_UP equ 8Ah
        VK_NAVIGATION_DOWN equ 8Bh
        VK_NAVIGATION_LEFT equ 8Ch
        VK_NAVIGATION_RIGHT equ 8Dh
        VK_NAVIGATION_ACCEPT equ 8Eh
        VK_NAVIGATION_CANCEL equ 8Fh
      endif
      VK_NUMLOCK equ 90h
      VK_SCROLL equ 91h
      VK_OEM_NEC_EQUAL equ 92h
      VK_OEM_FJ_JISHO equ 92h
      VK_OEM_FJ_MASSHOU equ 93h
      VK_OEM_FJ_TOUROKU equ 94h
      VK_OEM_FJ_LOYA equ 95h
      VK_OEM_FJ_ROYA equ 96h
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
      endif
      VK_OEM_1 equ 0BAh
      VK_OEM_PLUS equ 0BBh
      VK_OEM_COMMA equ 0BCh
      VK_OEM_MINUS equ 0BDh
      VK_OEM_PERIOD equ 0BEh
      VK_OEM_2 equ 0BFh
      VK_OEM_3 equ 0C0h
      if (_WIN32_WINNT ge 0604h)
        VK_GAMEPAD_A equ 0C3h
        VK_GAMEPAD_B equ 0C4h
        VK_GAMEPAD_X equ 0C5h
        VK_GAMEPAD_Y equ 0C6h
        VK_GAMEPAD_RIGHT_SHOULDER equ 0C7h
        VK_GAMEPAD_LEFT_SHOULDER equ 0C8h
        VK_GAMEPAD_LEFT_TRIGGER equ 0C9h
        VK_GAMEPAD_RIGHT_TRIGGER equ 0CAh
        VK_GAMEPAD_DPAD_UP equ 0CBh
        VK_GAMEPAD_DPAD_DOWN equ 0CCh
        VK_GAMEPAD_DPAD_LEFT equ 0CDh
        VK_GAMEPAD_DPAD_RIGHT equ 0CEh
        VK_GAMEPAD_MENU equ 0CFh
        VK_GAMEPAD_VIEW equ 0D0h
        VK_GAMEPAD_LEFT_THUMBSTICK_BUTTON equ 0D1h
        VK_GAMEPAD_RIGHT_THUMBSTICK_BUTTON equ 0D2h
        VK_GAMEPAD_LEFT_THUMBSTICK_UP equ 0D3h
        VK_GAMEPAD_LEFT_THUMBSTICK_DOWN equ 0D4h
        VK_GAMEPAD_LEFT_THUMBSTICK_RIGHT equ 0D5h
        VK_GAMEPAD_LEFT_THUMBSTICK_LEFT equ 0D6h
        VK_GAMEPAD_RIGHT_THUMBSTICK_UP equ 0D7h
        VK_GAMEPAD_RIGHT_THUMBSTICK_DOWN equ 0D8h
        VK_GAMEPAD_RIGHT_THUMBSTICK_RIGHT equ 0D9h
        VK_GAMEPAD_RIGHT_THUMBSTICK_LEFT equ 0DAh
      endif
      VK_OEM_4 equ 0DBh
      VK_OEM_5 equ 0DCh
      VK_OEM_6 equ 0DDh
      VK_OEM_7 equ 0DEh
      VK_OEM_8 equ 0DFh
      VK_OEM_AX equ 0E1h
      VK_OEM_102 equ 0E2h
      VK_ICO_HELP equ 0E3h
      VK_ICO_00 equ 0E4h
      if (WINVER ge 0400h)
        VK_PROCESSKEY equ 0E5h
      endif
      VK_ICO_CLEAR equ 0E6h
      if (_WIN32_WINNT ge 0500h)
        VK_PACKET equ 0E7h
      endif
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
    endif
    ifndef NOWH
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
      endif
      if (_WIN32_WINNT ge 0400h)
        WH_KEYBOARD_LL equ 13
        WH_MOUSE_LL equ 14
      endif
      if (WINVER ge 0400h)
        if (_WIN32_WINNT ge 0400h)
          WH_MAX equ 14
        else
          WH_MAX equ 12
        endif
      else
        WH_MAX equ 11
      endif
      WH_MINHOOK equ <WH_MIN>
      WH_MAXHOOK equ <WH_MAX>
      HC_ACTION equ 0
      HC_GETNEXT equ 1
      HC_SKIP equ 2
      HC_NOREMOVE equ 3
      HC_NOREM equ <HC_NOREMOVE>
      HC_SYSMODALON equ 4
      HC_SYSMODALOFF equ 5
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
        CBT_CREATEWNDA struct
          lpcs POINTER ?
          hwndInsertAfter HWND ?
        CBT_CREATEWNDA ends
        tagCBT_CREATEWNDA typedef CBT_CREATEWNDA
        LPCBT_CREATEWNDA typedef ptr CBT_CREATEWNDA
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
        CBTACTIVATESTRUCT struct
          fMouse BOOL ?
          hWndActive HWND ?
        CBTACTIVATESTRUCT ends
        tagCBTACTIVATESTRUCT typedef CBTACTIVATESTRUCT
        LPCBTACTIVATESTRUCT typedef ptr CBTACTIVATESTRUCT
      endif
      if (_WIN32_WINNT ge 0501h)
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
          WTSSESSION_NOTIFICATION struct
            cbSize DWORD ?
            dwSessionId DWORD ?
          WTSSESSION_NOTIFICATION ends
          tagWTSSESSION_NOTIFICATION typedef WTSSESSION_NOTIFICATION
          PWTSSESSION_NOTIFICATION typedef ptr WTSSESSION_NOTIFICATION
        endif
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
      endif
      MSGF_DIALOGBOX equ 0
      MSGF_MESSAGEBOX equ 1
      MSGF_MENU equ 2
      MSGF_SCROLLBAR equ 5
      MSGF_NEXTWINDOW equ 6
      MSGF_MAX equ 8
      MSGF_USER equ 4096
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
      endif
      if (_WIN32_WINNT ge 0500h)
        HSHELL_ACCESSIBILITYSTATE equ 11
        HSHELL_APPCOMMAND equ 12
      endif
      if (_WIN32_WINNT ge 0501h)
        HSHELL_WINDOWREPLACED equ 13
        HSHELL_WINDOWREPLACING equ 14
      endif
      if (_WIN32_WINNT ge 0602h)
        HSHELL_MONITORCHANGED equ 16
        if (NTDDI_VERSION ge NTDDI_WIN10_RS3)
        endif
      endif
      HSHELL_HIGHBIT equ 8000h
      HSHELL_FLASH equ <(HSHELL_REDRAW or HSHELL_HIGHBIT)>
      HSHELL_RUDEAPPACTIVATED equ <(HSHELL_WINDOWACTIVATED or HSHELL_HIGHBIT)>
      if (_WIN32_WINNT ge 0500h)
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
        endif
        if (_WIN32_WINNT ge 0600h)
          APPCOMMAND_DELETE equ 53
          APPCOMMAND_DWM_FLIP3D equ 54
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
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        SHELLHOOKINFO struct
          hwnd HWND ?
          rc RECT <>
        SHELLHOOKINFO ends
        LPSHELLHOOKINFO typedef ptr SHELLHOOKINFO
        EVENTMSG struct
          message UINT ?
          paramL UINT ?
          paramH UINT ?
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
        CWPSTRUCT struct
          lParam LPARAM ?
          wParam WPARAM ?
          message UINT ?
          hwnd HWND ?
        CWPSTRUCT ends
        tagCWPSTRUCT typedef CWPSTRUCT
        PCWPSTRUCT typedef ptr CWPSTRUCT
        NPCWPSTRUCT typedef ptr CWPSTRUCT
        LPCWPSTRUCT typedef ptr CWPSTRUCT
        if (WINVER ge 0400h)
          CWPRETSTRUCT struct
            lResult LRESULT ?
            lParam LPARAM ?
            wParam WPARAM ?
            message UINT ?
            hwnd HWND ?
          CWPRETSTRUCT ends
          tagCWPRETSTRUCT typedef CWPRETSTRUCT
          PCWPRETSTRUCT typedef ptr CWPRETSTRUCT
          NPCWPRETSTRUCT typedef ptr CWPRETSTRUCT
          LPCWPRETSTRUCT typedef ptr CWPRETSTRUCT
        endif
      endif
      if (_WIN32_WINNT ge 0400h)
        LLKHF_EXTENDED equ (KF_EXTENDED shr 8)
        LLKHF_INJECTED equ 00000010h
        LLKHF_ALTDOWN equ (KF_ALTDOWN shr 8)
        LLKHF_UP equ (KF_UP shr 8)
        LLKHF_LOWER_IL_INJECTED equ 00000002h
        LLMHF_INJECTED equ 00000001h
        LLMHF_LOWER_IL_INJECTED equ 00000002h
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
          KBDLLHOOKSTRUCT struct
            vkCode DWORD ?
            scanCode DWORD ?
            flags DWORD ?
            time DWORD ?
            dwExtraInfo ULONG_PTR ?
          KBDLLHOOKSTRUCT ends
          tagKBDLLHOOKSTRUCT typedef KBDLLHOOKSTRUCT
          LPKBDLLHOOKSTRUCT typedef ptr KBDLLHOOKSTRUCT
          PKBDLLHOOKSTRUCT typedef ptr KBDLLHOOKSTRUCT
          MSLLHOOKSTRUCT struct
            pt POINT <>
            mouseData DWORD ?
            flags DWORD ?
            time DWORD ?
            dwExtraInfo ULONG_PTR ?
          MSLLHOOKSTRUCT ends
          tagMSLLHOOKSTRUCT typedef MSLLHOOKSTRUCT
          LPMSLLHOOKSTRUCT typedef ptr MSLLHOOKSTRUCT
          PMSLLHOOKSTRUCT typedef ptr MSLLHOOKSTRUCT
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
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
        MOUSEHOOKSTRUCT struct
          pt POINT <>
          hwnd HWND ?
          wHitTestCode UINT ?
          dwExtraInfo ULONG_PTR ?
        MOUSEHOOKSTRUCT ends
        tagMOUSEHOOKSTRUCT typedef MOUSEHOOKSTRUCT
        LPMOUSEHOOKSTRUCT typedef ptr MOUSEHOOKSTRUCT
        PMOUSEHOOKSTRUCT typedef ptr MOUSEHOOKSTRUCT
        if (_WIN32_WINNT ge 0500h)
          ifdef __cplusplus
            ;[...]
          else
            MOUSEHOOKSTRUCTEX struct
              DUMMYSTRUCTNAME MOUSEHOOKSTRUCT <>
              mouseData DWORD ?
            MOUSEHOOKSTRUCTEX ends
            tagMOUSEHOOKSTRUCTEX typedef MOUSEHOOKSTRUCTEX
            LPMOUSEHOOKSTRUCTEX typedef ptr MOUSEHOOKSTRUCTEX
            PMOUSEHOOKSTRUCTEX typedef ptr MOUSEHOOKSTRUCTEX
          endif
        endif
        if (WINVER ge 0400h)
          HARDWAREHOOKSTRUCT struct
            hwnd HWND ?
            message UINT ?
            wParam WPARAM ?
            lParam LPARAM ?
          HARDWAREHOOKSTRUCT ends
          tagHARDWAREHOOKSTRUCT typedef HARDWAREHOOKSTRUCT
          LPHARDWAREHOOKSTRUCT typedef ptr HARDWAREHOOKSTRUCT
          PHARDWAREHOOKSTRUCT typedef ptr HARDWAREHOOKSTRUCT
        endif
      endif
    endif
    HKL_PREV equ 0
    HKL_NEXT equ 1
    KLF_ACTIVATE equ 00000001h
    KLF_SUBSTITUTE_OK equ 00000002h
    KLF_REORDER equ 00000008h
    if (WINVER ge 0400h)
      KLF_REPLACELANG equ 00000010h
      KLF_NOTELLSHELL equ 00000080h
    endif
    KLF_SETFORPROCESS equ 00000100h
    if (_WIN32_WINNT ge 0500h)
      KLF_SHIFTLOCK equ 00010000h
      KLF_RESET equ 40000000h
    endif
    if (WINVER ge 0500h)
      INPUTLANGCHANGE_SYSCHARSET equ 0001h
      INPUTLANGCHANGE_FORWARD equ 0002h
      INPUTLANGCHANGE_BACKWARD equ 0004h
    endif
    KL_NAMELENGTH equ 9
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, LoadKeyboardLayoutA, WIN_STD_CALL_CONV,, <:LPCSTR, :UINT>, 8
      @DefProto DllImport, LoadKeyboardLayoutW, WIN_STD_CALL_CONV,, <:LPCWSTR, :UINT>, 8
      ifdef UNICODE
        LoadKeyboardLayout equ <LoadKeyboardLayoutW>
      else
        LoadKeyboardLayout equ <LoadKeyboardLayoutA>
      endif
      if (WINVER ge 0400h)
        @DefProto DllImport, ActivateKeyboardLayout, WIN_STD_CALL_CONV,, <:HKL, :UINT>, 8
      else
        @DefProto DllImport, ActivateKeyboardLayout, WIN_STD_CALL_CONV,, <:HKL, :UINT>, 8
      endif
      if (WINVER ge 0400h)
        @DefProto DllImport, ToUnicodeEx, WIN_STD_CALL_CONV,, <:UINT, :UINT, :ptr BYTE, :LPWSTR, :SDWORD, :UINT, :HKL>, 28
      endif
      @DefProto DllImport, UnloadKeyboardLayout, WIN_STD_CALL_CONV,, <:HKL>, 4
      @DefProto DllImport, GetKeyboardLayoutNameA, WIN_STD_CALL_CONV,, <:LPSTR>, 4
      @DefProto DllImport, GetKeyboardLayoutNameW, WIN_STD_CALL_CONV,, <:LPWSTR>, 4
      ifdef UNICODE
        GetKeyboardLayoutName equ <GetKeyboardLayoutNameW>
      else
        GetKeyboardLayoutName equ <GetKeyboardLayoutNameA>
      endif
      if (WINVER ge 0400h)
        @DefProto DllImport, GetKeyboardLayoutList, WIN_STD_CALL_CONV,, <:SDWORD, :ptr HKL>, 8
        @DefProto DllImport, GetKeyboardLayout, WIN_STD_CALL_CONV,, <:DWORD>, 4
      endif
    endif
    if (WINVER ge 0500h)
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        MOUSEMOVEPOINT struct
          x SDWORD ?
          y SDWORD ?
          time DWORD ?
          dwExtraInfo ULONG_PTR ?
        MOUSEMOVEPOINT ends
        tagMOUSEMOVEPOINT typedef MOUSEMOVEPOINT
        PMOUSEMOVEPOINT typedef ptr MOUSEMOVEPOINT
        LPMOUSEMOVEPOINT typedef ptr MOUSEMOVEPOINT
      endif
      GMMP_USE_DISPLAY_POINTS equ 1
      GMMP_USE_HIGH_RESOLUTION_POINTS equ 2
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, GetMouseMovePointsEx, WIN_STD_CALL_CONV,, <:UINT, :LPMOUSEMOVEPOINT, :LPMOUSEMOVEPOINT, :SDWORD, :DWORD>, 20
      endif
    endif
    ifndef NODESKTOP
      DESKTOP_READOBJECTS equ 0001h
      DESKTOP_CREATEWINDOW equ 0002h
      DESKTOP_CREATEMENU equ 0004h
      DESKTOP_HOOKCONTROL equ 0008h
      DESKTOP_JOURNALRECORD equ 0010h
      DESKTOP_JOURNALPLAYBACK equ 0020h
      DESKTOP_ENUMERATE equ 0040h
      DESKTOP_WRITEOBJECTS equ 0080h
      DESKTOP_SWITCHDESKTOP equ 0100h
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
            @DefProto DllImport, CreateDesktopExA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :ptr DEVMODEA, :DWORD, :ACCESS_MASK, :LPSECURITY_ATTRIBUTES, :ULONG, :PVOID>, 32
            @DefProto DllImport, CreateDesktopExW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :ptr DEVMODEW, :DWORD, :ACCESS_MASK, :LPSECURITY_ATTRIBUTES, :ULONG, :PVOID>, 32
            ifdef UNICODE
              CreateDesktopEx equ <CreateDesktopExW>
            else
              CreateDesktopEx equ <CreateDesktopExA>
            endif
          endif
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, OpenDesktopA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :BOOL, :ACCESS_MASK>, 16
        @DefProto DllImport, OpenDesktopW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :BOOL, :ACCESS_MASK>, 16
        ifdef UNICODE
          OpenDesktop equ <OpenDesktopW>
        else
          OpenDesktop equ <OpenDesktopA>
        endif
        @DefProto DllImport, OpenInputDesktop, WIN_STD_CALL_CONV,, <:DWORD, :BOOL, :ACCESS_MASK>, 12
        @DefProto DllImport, EnumDesktopsA, WIN_STD_CALL_CONV,, <:HWINSTA, :DESKTOPENUMPROCA, :LPARAM>, 12
        @DefProto DllImport, EnumDesktopsW, WIN_STD_CALL_CONV,, <:HWINSTA, :DESKTOPENUMPROCW, :LPARAM>, 12
        ifdef UNICODE
          EnumDesktops equ <EnumDesktopsW>
        else
          EnumDesktops equ <EnumDesktopsA>
        endif
        @DefProto DllImport, EnumDesktopWindows, WIN_STD_CALL_CONV,, <:HDESK, :WNDENUMPROC, :LPARAM>, 12
        @DefProto DllImport, SwitchDesktop, WIN_STD_CALL_CONV,, <:HDESK>, 4
        @DefProto DllImport, SetThreadDesktop, WIN_STD_CALL_CONV,, <:HDESK>, 4
        @DefProto DllImport, CloseDesktop, WIN_STD_CALL_CONV,, <:HDESK>, 4
        @DefProto DllImport, GetThreadDesktop, WIN_STD_CALL_CONV,, <:DWORD>, 4
      endif
    endif
    ifndef NOWINDOWSTATION
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
      CWF_CREATE_ONLY equ 00000001h
      WSF_VISIBLE equ 0001h
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, CreateWindowStationA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :ACCESS_MASK, :LPSECURITY_ATTRIBUTES>, 16
        @DefProto DllImport, CreateWindowStationW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :ACCESS_MASK, :LPSECURITY_ATTRIBUTES>, 16
        ifdef UNICODE
          CreateWindowStation equ <CreateWindowStationW>
        else
          CreateWindowStation equ <CreateWindowStationA>
        endif
        @DefProto DllImport, OpenWindowStationA, WIN_STD_CALL_CONV,, <:LPCSTR, :BOOL, :ACCESS_MASK>, 12
        @DefProto DllImport, OpenWindowStationW, WIN_STD_CALL_CONV,, <:LPCWSTR, :BOOL, :ACCESS_MASK>, 12
        ifdef UNICODE
          OpenWindowStation equ <OpenWindowStationW>
        else
          OpenWindowStation equ <OpenWindowStationA>
        endif
        @DefProto DllImport, EnumWindowStationsA, WIN_STD_CALL_CONV,, <:WINSTAENUMPROCA, :LPARAM>, 8
        @DefProto DllImport, EnumWindowStationsW, WIN_STD_CALL_CONV,, <:WINSTAENUMPROCW, :LPARAM>, 8
        ifdef UNICODE
          EnumWindowStations equ <EnumWindowStationsW>
        else
          EnumWindowStations equ <EnumWindowStationsA>
        endif
        @DefProto DllImport, CloseWindowStation, WIN_STD_CALL_CONV,, <:HWINSTA>, 4
        @DefProto DllImport, SetProcessWindowStation, WIN_STD_CALL_CONV,, <:HWINSTA>, 4
        @DefProto DllImport, GetProcessWindowStation, WIN_STD_CALL_CONV,, <>, 0
      endif
    endif
    ifndef NOSECURITY
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, SetUserObjectSecurity, WIN_STD_CALL_CONV,, <:HANDLE, :PSECURITY_INFORMATION, :PSECURITY_DESCRIPTOR>, 12
        @DefProto DllImport, GetUserObjectSecurity, WIN_STD_CALL_CONV,, <:HANDLE, :PSECURITY_INFORMATION, :PSECURITY_DESCRIPTOR, :DWORD, :LPDWORD>, 20
      endif
      UOI_FLAGS equ 1
      UOI_NAME equ 2
      UOI_TYPE equ 3
      UOI_USER_SID equ 4
      if (WINVER ge 0600h)
        UOI_HEAPSIZE equ 5
        UOI_IO equ 6
      endif
      UOI_TIMERPROC_EXCEPTION_SUPPRESSION equ 7
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        USEROBJECTFLAGS struct
          fInherit BOOL ?
          fReserved BOOL ?
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
        @DefProto DllImport, SetUserObjectInformationA, WIN_STD_CALL_CONV,, <:HANDLE, :SDWORD, :PVOID, :DWORD>, 16
        @DefProto DllImport, SetUserObjectInformationW, WIN_STD_CALL_CONV,, <:HANDLE, :SDWORD, :PVOID, :DWORD>, 16
        ifdef UNICODE
          SetUserObjectInformation equ <SetUserObjectInformationW>
        else
          SetUserObjectInformation equ <SetUserObjectInformationA>
        endif
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      if (WINVER ge 0400h)
        WNDCLASSEXA struct
          cbSize UINT ?
          style UINT ?
          lpfnWndProc WNDPROC ?
          cbClsExtra SDWORD ?
          cbWndExtra SDWORD ?
          hInstance HINSTANCE ?
          hIcon HICON ?
          hCursor HCURSOR ?
          hbrBackground HBRUSH ?
          lpszMenuName LPCSTR ?
          lpszClassName LPCSTR ?
          hIconSm HICON ?
        WNDCLASSEXA ends
        tagWNDCLASSEXA typedef WNDCLASSEXA
        PWNDCLASSEXA typedef ptr WNDCLASSEXA
        NPWNDCLASSEXA typedef ptr WNDCLASSEXA
        LPWNDCLASSEXA typedef ptr WNDCLASSEXA
        WNDCLASSEXW struct
          cbSize UINT ?
          style UINT ?
          lpfnWndProc WNDPROC ?
          cbClsExtra SDWORD ?
          cbWndExtra SDWORD ?
          hInstance HINSTANCE ?
          hIcon HICON ?
          hCursor HCURSOR ?
          hbrBackground HBRUSH ?
          lpszMenuName LPCWSTR ?
          lpszClassName LPCWSTR ?
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
      endif
      WNDCLASSA struct
        style UINT ?
        lpfnWndProc WNDPROC ?
        cbClsExtra SDWORD ?
        cbWndExtra SDWORD ?
        hInstance HINSTANCE ?
        hIcon HICON ?
        hCursor HCURSOR ?
        hbrBackground HBRUSH ?
        lpszMenuName LPCSTR ?
        lpszClassName LPCSTR ?
      WNDCLASSA ends
      tagWNDCLASSA typedef WNDCLASSA
      PWNDCLASSA typedef ptr WNDCLASSA
      NPWNDCLASSA typedef ptr WNDCLASSA
      LPWNDCLASSA typedef ptr WNDCLASSA
      WNDCLASSW struct
        style UINT ?
        lpfnWndProc WNDPROC ?
        cbClsExtra SDWORD ?
        cbWndExtra SDWORD ?
        hInstance HINSTANCE ?
        hIcon HICON ?
        hCursor HCURSOR ?
        hbrBackground HBRUSH ?
        lpszMenuName LPCWSTR ?
        lpszClassName LPCWSTR ?
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
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, IsHungAppWindow, WIN_STD_CALL_CONV,, <:HWND>, 4
      if (WINVER ge 0501h)
        @DefProto DllImport, DisableProcessWindowsGhosting, WIN_STD_CALL_CONV,, <>, 0
      endif
    endif
    ifndef NOMSG
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
        MSG struct
          hwnd HWND ?
          message UINT ?
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
    endif
    ifndef NOWINOFFSETS
      GWL_WNDPROC equ (- 4)
      GWL_HINSTANCE equ (- 6)
      GWL_HWNDPARENT equ (- 8)
      GWL_STYLE equ (- 16)
      GWL_EXSTYLE equ (- 20)
      GWL_USERDATA equ (- 21)
      GWL_ID equ (- 12)
      ifdef _WIN64
      endif
      GWLP_WNDPROC equ (- 4)
      GWLP_HINSTANCE equ (- 6)
      GWLP_HWNDPARENT equ (- 8)
      GWLP_USERDATA equ (- 21)
      GWLP_ID equ (- 12)
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
      endif
      ifdef _WIN64
      endif
      GCLP_MENUNAME equ (- 8)
      GCLP_HBRBACKGROUND equ (- 10)
      GCLP_HCURSOR equ (- 12)
      GCLP_HICON equ (- 14)
      GCLP_HMODULE equ (- 16)
      GCLP_WNDPROC equ (- 24)
      GCLP_HICONSM equ (- 34)
    endif
    ifndef NOWINMESSAGES
      WM_NULL equ 0000h
      WM_CREATE equ 0001h
      WM_DESTROY equ 0002h
      WM_MOVE equ 0003h
      WM_SIZE equ 0005h
      WM_ACTIVATE equ 0006h
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
      endif
      if (NTDDI_VERSION ge NTDDI_WIN10_19H1)
      endif
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
      endif
      WM_COMPACTING equ 0041h
      WM_COMMNOTIFY equ 0044h
      WM_WINDOWPOSCHANGING equ 0046h
      WM_WINDOWPOSCHANGED equ 0047h
      WM_POWER equ 0048h
      PWR_OK equ 1
      PWR_FAIL equ (- 1)
      PWR_SUSPENDREQUEST equ 1
      PWR_SUSPENDRESUME equ 2
      PWR_CRITICALRESUME equ 3
      WM_COPYDATA equ 004Ah
      WM_CANCELJOURNAL equ 004Bh
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        COPYDATASTRUCT struct
          dwData ULONG_PTR ?
          cbData DWORD ?
          lpData PVOID ?
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
        endif
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
      endif
      if (_WIN32_WINNT ge 0501h)
        WM_INPUT_DEVICE_CHANGE equ 00FEh
      endif
      if (_WIN32_WINNT ge 0501h)
        WM_INPUT equ 00FFh
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
      endif
      if (WINVER ge 0400h)
        WM_IME_STARTCOMPOSITION equ 010Dh
        WM_IME_ENDCOMPOSITION equ 010Eh
        WM_IME_COMPOSITION equ 010Fh
        WM_IME_KEYLAST equ 010Fh
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
              UIS_SET equ 1
              UIS_CLEAR equ 2
              UIS_INITIALIZE equ 3
              UISF_HIDEFOCUS equ 1h
              UISF_HIDEACCEL equ 2h
              if (_WIN32_WINNT ge 0501h)
                UISF_ACTIVE equ 4h
              endif
            endif
          endif
        endif
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
      endif
      if (_WIN32_WINNT ge 0400h)
        WHEEL_DELTA equ 120
        GET_WHEEL_DELTA_WPARAM macro wParam
          exitm <(HIWORD(wParam))>
        endm
        WHEEL_PAGESCROLL equ <(UINT_MAX)>
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
        XBUTTON1 equ 0001h
        XBUTTON2 equ 0002h
      endif
      WM_PARENTNOTIFY equ 0210h
      WM_ENTERMENULOOP equ 0211h
      WM_EXITMENULOOP equ 0212h
      if (WINVER ge 0400h)
        WM_NEXTMENU equ 0213h
        WM_SIZING equ 0214h
        WM_CAPTURECHANGED equ 0215h
        WM_MOVING equ 0216h
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
                  Data UCHAR 1 dup (?)
                POWERBROADCAST_SETTING ends
                PPOWERBROADCAST_SETTING typedef ptr POWERBROADCAST_SETTING
              endif
            endif
          endif
        endif
      endif
      if (WINVER ge 0400h)
        WM_DEVICECHANGE equ 0219h
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
      endif
      if (WINVER ge 0601h)
        WM_TOUCH equ 0240h
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
      endif
      if (WINVER ge 0400h)
        WM_IME_SETCONTEXT equ 0281h
        WM_IME_NOTIFY equ 0282h
        WM_IME_CONTROL equ 0283h
        WM_IME_COMPOSITIONFULL equ 0284h
        WM_IME_SELECT equ 0285h
        WM_IME_CHAR equ 0286h
      endif
      if (WINVER ge 0500h)
        WM_IME_REQUEST equ 0288h
      endif
      if (WINVER ge 0400h)
        WM_IME_KEYDOWN equ 0290h
        WM_IME_KEYUP equ 0291h
      endif
      if ((_WIN32_WINNT ge 0400h) or (WINVER ge 0500h))
        WM_MOUSEHOVER equ 02A1h
        WM_MOUSELEAVE equ 02A3h
      endif
      if (WINVER ge 0500h)
        WM_NCMOUSEHOVER equ 02A0h
        WM_NCMOUSELEAVE equ 02A2h
      endif
      if (_WIN32_WINNT ge 0501h)
        WM_WTSSESSION_CHANGE equ 02B1h
        WM_TABLET_FIRST equ 02c0h
        WM_TABLET_LAST equ 02dfh
      endif
      if (WINVER ge 0601h)
        WM_DPICHANGED equ 02E0h
      endif
      if (WINVER ge 0605h)
        WM_DPICHANGED_BEFOREPARENT equ 02E2h
        WM_DPICHANGED_AFTERPARENT equ 02E3h
        WM_GETDPISCALEDSIZE equ 02E4h
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
      endif
      if (_WIN32_WINNT ge 0500h)
        WM_APPCOMMAND equ 0319h
      endif
      if (_WIN32_WINNT ge 0501h)
        WM_THEMECHANGED equ 031Ah
      endif
      if (_WIN32_WINNT ge 0501h)
        WM_CLIPBOARDUPDATE equ 031Dh
      endif
      if (_WIN32_WINNT ge 0600h)
        WM_DWMCOMPOSITIONCHANGED equ 031Eh
        WM_DWMNCRENDERINGCHANGED equ 031Fh
        WM_DWMCOLORIZATIONCOLORCHANGED equ 0320h
        WM_DWMWINDOWMAXIMIZEDCHANGE equ 0321h
      endif
      if (_WIN32_WINNT ge 0601h)
        WM_DWMSENDICONICTHUMBNAIL equ 0323h
        WM_DWMSENDICONICLIVEPREVIEWBITMAP equ 0326h
      endif
      if (WINVER ge 0600h)
        WM_GETTITLEBARINFOEX equ 033Fh
      endif
      if (WINVER ge 0400h)
      endif
      if (WINVER ge 0400h)
        WM_HANDHELDFIRST equ 0358h
        WM_HANDHELDLAST equ 035Fh
        WM_AFXFIRST equ 0360h
        WM_AFXLAST equ 037Fh
      endif
      WM_PENWINFIRST equ 0380h
      WM_PENWINLAST equ 038Fh
      if (WINVER ge 0400h)
        WM_APP equ 8000h
      endif
      WM_USER equ 0400h
      if (WINVER ge 0400h)
        WMSZ_LEFT equ 1
        WMSZ_RIGHT equ 2
        WMSZ_TOP equ 3
        WMSZ_TOPLEFT equ 4
        WMSZ_TOPRIGHT equ 5
        WMSZ_BOTTOM equ 6
        WMSZ_BOTTOMLEFT equ 7
        WMSZ_BOTTOMRIGHT equ 8
      endif
      ifndef NONCMESSAGES
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
        endif
        SMTO_NORMAL equ 0000h
        SMTO_BLOCK equ 0001h
        SMTO_ABORTIFHUNG equ 0002h
        if (WINVER ge 0500h)
          SMTO_NOTIMEOUTIFNOTHUNG equ 0008h
        endif
        if (WINVER ge 0600h)
          SMTO_ERRORONEXIT equ 0020h
        endif
        if (WINVER ge 0602h)
        endif
      endif
      MA_ACTIVATE equ 1
      MA_ACTIVATEANDEAT equ 2
      MA_NOACTIVATE equ 3
      MA_NOACTIVATEANDEAT equ 4
      ICON_SMALL equ 0
      ICON_BIG equ 1
      if (_WIN32_WINNT ge 0501h)
        ICON_SMALL2 equ 2
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, RegisterWindowMessageA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
        @DefProto DllImport, RegisterWindowMessageW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
        ifdef UNICODE
          RegisterWindowMessage equ <RegisterWindowMessageW>
        else
          RegisterWindowMessage equ <RegisterWindowMessageA>
        endif
      endif
      SIZE_RESTORED equ 0
      SIZE_MINIMIZED equ 1
      SIZE_MAXIMIZED equ 2
      SIZE_MAXSHOW equ 3
      SIZE_MAXHIDE equ 4
      SIZENORMAL equ <SIZE_RESTORED>
      SIZEICONIC equ <SIZE_MINIMIZED>
      SIZEFULLSCREEN equ <SIZE_MAXIMIZED>
      SIZEZOOMSHOW equ <SIZE_MAXSHOW>
      SIZEZOOMHIDE equ <SIZE_MAXHIDE>
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        WINDOWPOS struct
          hwnd HWND ?
          hwndInsertAfter HWND ?
          x SDWORD ?
          y SDWORD ?
          cx_ SDWORD ?
          cy SDWORD ?
          flags UINT ?
        WINDOWPOS ends
        tagWINDOWPOS typedef WINDOWPOS
        LPWINDOWPOS typedef ptr WINDOWPOS
        PWINDOWPOS typedef ptr WINDOWPOS
        NCCALCSIZE_PARAMS struct
          rgrc RECT 3 dup (<>)
          lppos PWINDOWPOS ?
        NCCALCSIZE_PARAMS ends
        tagNCCALCSIZE_PARAMS typedef NCCALCSIZE_PARAMS
        LPNCCALCSIZE_PARAMS typedef ptr NCCALCSIZE_PARAMS
      endif
      WVR_ALIGNTOP equ 0010h
      WVR_ALIGNLEFT equ 0020h
      WVR_ALIGNBOTTOM equ 0040h
      WVR_ALIGNRIGHT equ 0080h
      WVR_HREDRAW equ 0100h
      WVR_VREDRAW equ 0200h
      WVR_REDRAW equ <(WVR_HREDRAW or WVR_VREDRAW)>
      WVR_VALIDRECTS equ 0400h
      ifndef NOKEYSTATES
        MK_LBUTTON equ 0001h
        MK_RBUTTON equ 0002h
        MK_SHIFT equ 0004h
        MK_CONTROL equ 0008h
        MK_MBUTTON equ 0010h
        if (_WIN32_WINNT ge 0500h)
          MK_XBUTTON1 equ 0020h
          MK_XBUTTON2 equ 0040h
        endif
      endif
      if (_WIN32_WINNT ge 0400h)
        ifndef NOTRACKMOUSEEVENT
          TME_HOVER equ 00000001h
          TME_LEAVE equ 00000002h
          if (WINVER ge 0500h)
            TME_NONCLIENT equ 00000010h
          endif
          TME_QUERY equ 40000000h
          TME_CANCEL equ 80000000h
          HOVER_DEFAULT equ 0FFFFFFFFh
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
          endif
        endif
        if (_WIN32_WINNT ge 0400h)
        endif
      endif
    endif
    ifndef NOWINSTYLES
      WS_OVERLAPPED equ 00000000h
      WS_POPUP equ 80000000h
      WS_CHILD equ 40000000h
      WS_MINIMIZE equ 20000000h
      WS_VISIBLE equ 10000000h
      WS_DISABLED equ 08000000h
      WS_CLIPSIBLINGS equ 04000000h
      WS_CLIPCHILDREN equ 02000000h
      WS_MAXIMIZE equ 01000000h
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
      WS_OVERLAPPEDWINDOW equ <(WS_OVERLAPPED or WS_CAPTION or WS_SYSMENU or WS_THICKFRAME or WS_MINIMIZEBOX or WS_MAXIMIZEBOX)>
      WS_POPUPWINDOW equ <(WS_POPUP or WS_BORDER or WS_SYSMENU)>
      WS_CHILDWINDOW equ <(WS_CHILD)>
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
      endif
      if (_WIN32_WINNT ge 0500h)
        WS_EX_LAYERED equ 00080000h
      endif
      if (WINVER ge 0500h)
        WS_EX_NOINHERITLAYOUT equ 00100000h
      endif
      if (WINVER ge 0602h)
        WS_EX_NOREDIRECTIONBITMAP equ 00200000h
      endif
      if (WINVER ge 0500h)
        WS_EX_LAYOUTRTL equ 00400000h
      endif
      if (_WIN32_WINNT ge 0501h)
        WS_EX_COMPOSITED equ 02000000h
      endif
      if (_WIN32_WINNT ge 0500h)
        WS_EX_NOACTIVATE equ 08000000h
      endif
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
      endif
    endif
    if (WINVER ge 0400h)
      PRF_CHECKVISIBLE equ 00000001h
      PRF_NONCLIENT equ 00000002h
      PRF_CLIENT equ 00000004h
      PRF_ERASEBKGND equ 00000008h
      PRF_CHILDREN equ 00000010h
      PRF_OWNED equ 00000020h
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
      BF_DIAGONAL_ENDTOPRIGHT equ <(BF_DIAGONAL or BF_TOP or BF_RIGHT)>
      BF_DIAGONAL_ENDTOPLEFT equ <(BF_DIAGONAL or BF_TOP or BF_LEFT)>
      BF_DIAGONAL_ENDBOTTOMLEFT equ <(BF_DIAGONAL or BF_BOTTOM or BF_LEFT)>
      BF_DIAGONAL_ENDBOTTOMRIGHT equ <(BF_DIAGONAL or BF_BOTTOM or BF_RIGHT)>
      BF_MIDDLE equ 0800h
      BF_SOFT equ 1000h
      BF_ADJUST equ 2000h
      BF_FLAT equ 4000h
      BF_MONO equ 8000h
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, DrawEdge, WIN_STD_CALL_CONV,, <:HDC, :LPRECT, :UINT, :UINT>, 16
      endif
      DFC_CAPTION equ 1
      DFC_MENU equ 2
      DFC_SCROLL equ 3
      DFC_BUTTON equ 4
      if (WINVER ge 0500h)
        DFC_POPUPMENU equ 5
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
      endif
      DFCS_ADJUSTRECT equ 2000h
      DFCS_FLAT equ 4000h
      DFCS_MONO equ 8000h
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, DrawFrameControl, WIN_STD_CALL_CONV,, <:HDC, :LPRECT, :UINT, :UINT>, 16
      endif
      DC_ACTIVE equ 0001h
      DC_SMALLCAP equ 0002h
      DC_ICON equ 0004h
      DC_TEXT equ 0008h
      DC_INBUTTON equ 0010h
      if (WINVER ge 0500h)
        DC_GRADIENT equ 0020h
      endif
      if (_WIN32_WINNT ge 0501h)
        DC_BUTTONS equ 1000h
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, DrawCaption, WIN_STD_CALL_CONV,, <:HWND, :HDC, :ptr RECT, :UINT>, 16
      endif
      IDANI_OPEN equ 1
      IDANI_CAPTION equ 3
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, DrawAnimatedRects, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :ptr RECT, :ptr RECT>, 16
      endif
    endif
    ifndef NOCLIPBOARD
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
      endif
      if (WINVER ge 0500h)
        CF_DIBV5 equ 17
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
      CF_PRIVATEFIRST equ 0200h
      CF_PRIVATELAST equ 02FFh
      CF_GDIOBJFIRST equ 0300h
      CF_GDIOBJLAST equ 03FFh
    endif
    FVIRTKEY equ <TRUE>
    FNOINVERT equ 02h
    FSHIFT equ 04h
    FCONTROL equ 08h
    FALT equ 10h
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ACCEL struct
        ifndef _MAC
          fVirt BYTE ?
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
        fErase BOOL ?
        rcPaint RECT <>
        fRestore BOOL ?
        fIncUpdate BOOL ?
        rgbReserved BYTE 32 dup (?)
      PAINTSTRUCT ends
      tagPAINTSTRUCT typedef PAINTSTRUCT
      PPAINTSTRUCT typedef ptr PAINTSTRUCT
      NPPAINTSTRUCT typedef ptr PAINTSTRUCT
      LPPAINTSTRUCT typedef ptr PAINTSTRUCT
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      CREATESTRUCTA struct
        lpCreateParams LPVOID ?
        hInstance HINSTANCE ?
        hMenu HMENU ?
        hwndParent HWND ?
        cy SDWORD ?
        cx_ SDWORD ?
        y SDWORD ?
        x SDWORD ?
        style LONG ?
        lpszName LPCSTR ?
        lpszClass LPCSTR ?
        dwExStyle DWORD ?
      CREATESTRUCTA ends
      tagCREATESTRUCTA typedef CREATESTRUCTA
      LPCREATESTRUCTA typedef ptr CREATESTRUCTA
      CREATESTRUCTW struct
        lpCreateParams LPVOID ?
        hInstance HINSTANCE ?
        hMenu HMENU ?
        hwndParent HWND ?
        cy SDWORD ?
        cx_ SDWORD ?
        y SDWORD ?
        x SDWORD ?
        style LONG ?
        lpszName LPCWSTR ?
        lpszClass LPCWSTR ?
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
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      WINDOWPLACEMENT struct
        length_ UINT ?
        flags UINT ?
        showCmd UINT ?
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
      endif
    endif
    if (WINVER ge 0400h)
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        NMHDR struct
          hwndFrom HWND ?
          idFrom UINT_PTR ?
          code UINT ?
        NMHDR ends
        tagNMHDR typedef NMHDR
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        LPNMHDR typedef ptr NMHDR
        STYLESTRUCT struct
          styleOld DWORD ?
          styleNew DWORD ?
        STYLESTRUCT ends
        tagSTYLESTRUCT typedef STYLESTRUCT
        LPSTYLESTRUCT typedef ptr STYLESTRUCT
      endif
    endif
    ODT_MENU equ 1
    ODT_LISTBOX equ 2
    ODT_COMBOBOX equ 3
    ODT_BUTTON equ 4
    if (WINVER ge 0400h)
      ODT_STATIC equ 5
    endif
    ODA_DRAWENTIRE equ 0001h
    ODA_SELECT equ 0002h
    ODA_FOCUS equ 0004h
    ODS_SELECTED equ 0001h
    ODS_GRAYED equ 0002h
    ODS_DISABLED equ 0004h
    ODS_CHECKED equ 0008h
    ODS_FOCUS equ 0010h
    if (WINVER ge 0400h)
      ODS_DEFAULT equ 0020h
      ODS_COMBOBOXEDIT equ 1000h
    endif
    if (WINVER ge 0500h)
      ODS_HOTLIGHT equ 0040h
      ODS_INACTIVE equ 0080h
      if (_WIN32_WINNT ge 0500h)
        ODS_NOACCEL equ 0100h
        ODS_NOFOCUSRECT equ 0200h
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      MEASUREITEMSTRUCT struct
        CtlType UINT ?
        CtlID UINT ?
        itemID UINT ?
        itemWidth UINT ?
        itemHeight UINT ?
        itemData ULONG_PTR ?
      MEASUREITEMSTRUCT ends
      tagMEASUREITEMSTRUCT typedef MEASUREITEMSTRUCT
      PMEASUREITEMSTRUCT typedef ptr MEASUREITEMSTRUCT
      LPMEASUREITEMSTRUCT typedef ptr MEASUREITEMSTRUCT
      DRAWITEMSTRUCT struct
        CtlType UINT ?
        CtlID UINT ?
        itemID UINT ?
        itemAction UINT ?
        itemState UINT ?
        hwndItem HWND ?
        hDC HDC ?
        rcItem RECT <>
        itemData ULONG_PTR ?
      DRAWITEMSTRUCT ends
      tagDRAWITEMSTRUCT typedef DRAWITEMSTRUCT
      PDRAWITEMSTRUCT typedef ptr DRAWITEMSTRUCT
      LPDRAWITEMSTRUCT typedef ptr DRAWITEMSTRUCT
      DELETEITEMSTRUCT struct
        CtlType UINT ?
        CtlID UINT ?
        itemID UINT ?
        hwndItem HWND ?
        itemData ULONG_PTR ?
      DELETEITEMSTRUCT ends
      tagDELETEITEMSTRUCT typedef DELETEITEMSTRUCT
      PDELETEITEMSTRUCT typedef ptr DELETEITEMSTRUCT
      LPDELETEITEMSTRUCT typedef ptr DELETEITEMSTRUCT
      COMPAREITEMSTRUCT struct
        CtlType UINT ?
        CtlID UINT ?
        hwndItem HWND ?
        itemID1 UINT ?
        itemData1 ULONG_PTR ?
        itemID2 UINT ?
        itemData2 ULONG_PTR ?
        dwLocaleId DWORD ?
      COMPAREITEMSTRUCT ends
      tagCOMPAREITEMSTRUCT typedef COMPAREITEMSTRUCT
      PCOMPAREITEMSTRUCT typedef ptr COMPAREITEMSTRUCT
      LPCOMPAREITEMSTRUCT typedef ptr COMPAREITEMSTRUCT
    endif
    ifndef NOMSG
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
        @DefProto DllImport, GetMessageA, WIN_STD_CALL_CONV,, <:LPMSG, :HWND, :UINT, :UINT>, 16
        @DefProto DllImport, GetMessageW, WIN_STD_CALL_CONV,, <:LPMSG, :HWND, :UINT, :UINT>, 16
        ifdef UNICODE
          GetMessage equ <GetMessageW>
        else
          GetMessage equ <GetMessageA>
        endif
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
        if Defined(_M_CEE)
          ;[...]
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, SetMessageQueue, WIN_STD_CALL_CONV,, <:SDWORD>, 4
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
        @DefProto DllImport, PeekMessageA, WIN_STD_CALL_CONV,, <:LPMSG, :HWND, :UINT, :UINT, :UINT>, 20
        @DefProto DllImport, PeekMessageW, WIN_STD_CALL_CONV,, <:LPMSG, :HWND, :UINT, :UINT, :UINT>, 20
        ifdef UNICODE
          PeekMessage equ <PeekMessageW>
        else
          PeekMessage equ <PeekMessageA>
        endif
      endif
      PM_NOREMOVE equ 0000h
      PM_REMOVE equ 0001h
      PM_NOYIELD equ 0002h
      if (WINVER ge 0500h)
        PM_QS_INPUT equ (QS_INPUT shl 16)
        PM_QS_POSTMESSAGE equ ((QS_POSTMESSAGE or QS_HOTKEY or QS_TIMER) shl 16)
        PM_QS_PAINT equ (QS_PAINT shl 16)
        PM_QS_SENDMESSAGE equ (QS_SENDMESSAGE shl 16)
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, RegisterHotKey, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :UINT, :UINT>, 16
      @DefProto DllImport, UnregisterHotKey, WIN_STD_CALL_CONV,, <:HWND, :SDWORD>, 8
    endif
    MOD_ALT equ 0001h
    MOD_CONTROL equ 0002h
    MOD_SHIFT equ 0004h
    MOD_WIN equ 0008h
    if (WINVER ge 0601h)
      MOD_NOREPEAT equ 4000h
    endif
    IDHOT_SNAPWINDOW equ (- 1)
    IDHOT_SNAPDESKTOP equ (- 2)
    ifdef WIN_INTERNAL
      ifndef LSTRING
        NOLSTRING equ <>
      endif
      ifndef LFILEIO
        NOLFILEIO equ <>
      endif
    endif
    if (WINVER ge 0400h)
    endif
    if (_WIN32_WINNT ge 0400h)
      ENDSESSION_CLOSEAPP equ 00000001h
    endif
    if (_WIN32_WINNT ge 0400h)
      ENDSESSION_CRITICAL equ 40000000h
    endif
    if (_WIN32_WINNT ge 0400h)
      ENDSESSION_LOGOFF equ 80000000h
    endif
    EWX_LOGOFF equ 00000000h
    EWX_SHUTDOWN equ 00000001h
    EWX_REBOOT equ 00000002h
    EWX_FORCE equ 00000004h
    EWX_POWEROFF equ 00000008h
    if (_WIN32_WINNT ge 0500h)
      EWX_FORCEIFHUNG equ 00000010h
    endif
    EWX_QUICKRESOLVE equ 00000020h
    if (_WIN32_WINNT ge 0600h)
      EWX_RESTARTAPPS equ 00000040h
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
      endif
      if (_WIN32_WINNT ge 0501h)
        @DefProto DllImport, IsWow64Message, WIN_STD_CALL_CONV,, <>, 0
      endif
      if (WINVER ge 0400h)
        @DefProto DllImport, SetMessageExtraInfo, WIN_STD_CALL_CONV,, <:LPARAM>, 4
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, SendMessageA, WIN_STD_CALL_CONV,, <:HWND, :UINT, :WPARAM, :LPARAM>, 16
      @DefProto DllImport, SendMessageW, WIN_STD_CALL_CONV,, <:HWND, :UINT, :WPARAM, :LPARAM>, 16
      ifdef UNICODE
        SendMessage equ <SendMessageW>
      else
        SendMessage equ <SendMessageA>
      endif
      if Defined(_M_CEE)
        ;[...]
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, SendMessageTimeoutA, WIN_STD_CALL_CONV,, <:HWND, :UINT, :WPARAM, :LPARAM, :UINT, :UINT, :PDWORD_PTR>, 28
      @DefProto DllImport, SendMessageTimeoutW, WIN_STD_CALL_CONV,, <:HWND, :UINT, :WPARAM, :LPARAM, :UINT, :UINT, :PDWORD_PTR>, 28
      ifdef UNICODE
        SendMessageTimeout equ <SendMessageTimeoutW>
      else
        SendMessageTimeout equ <SendMessageTimeoutA>
      endif
      @DefProto DllImport, SendNotifyMessageA, WIN_STD_CALL_CONV,, <:HWND, :UINT, :WPARAM, :LPARAM>, 16
      @DefProto DllImport, SendNotifyMessageW, WIN_STD_CALL_CONV,, <:HWND, :UINT, :WPARAM, :LPARAM>, 16
      ifdef UNICODE
        SendNotifyMessage equ <SendNotifyMessageW>
      else
        SendNotifyMessage equ <SendNotifyMessageA>
      endif
      @DefProto DllImport, SendMessageCallbackA, WIN_STD_CALL_CONV,, <:HWND, :UINT, :WPARAM, :LPARAM, :SENDASYNCPROC, :ULONG_PTR>, 24
      @DefProto DllImport, SendMessageCallbackW, WIN_STD_CALL_CONV,, <:HWND, :UINT, :WPARAM, :LPARAM, :SENDASYNCPROC, :ULONG_PTR>, 24
      ifdef UNICODE
        SendMessageCallback equ <SendMessageCallbackW>
      else
        SendMessageCallback equ <SendMessageCallbackA>
      endif
      if (_WIN32_WINNT ge 0501h)
        BSMINFO struct
          cbSize UINT ?
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
      endif
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
        elseif Defined(_WIN32_WINDOWS)
          @DefProto DllImport, BroadcastSystemMessage, WIN_STD_CALL_CONV,, <:DWORD, :LPDWORD, :UINT, :WPARAM, :LPARAM>, 20
        endif
      endif
      BSM_ALLCOMPONENTS equ 00000000h
      BSM_VXDS equ 00000001h
      BSM_NETDRIVER equ 00000002h
      BSM_INSTALLABLEDRIVERS equ 00000004h
      BSM_APPLICATIONS equ 00000008h
      BSM_ALLDESKTOPS equ 00000010h
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
      endif
      if (_WIN32_WINNT ge 0501h)
        BSF_RETURNHDESK equ 00000200h
        BSF_LUID equ 00000400h
      endif
      BROADCAST_QUERY_DENY equ 424D5144h
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      if (WINVER ge 0500h)
        HDEVNOTIFY typedef PVOID
        PHDEVNOTIFY typedef ptr HDEVNOTIFY
        DEVICE_NOTIFY_WINDOW_HANDLE equ 00000000h
        DEVICE_NOTIFY_SERVICE_HANDLE equ 00000001h
        if (_WIN32_WINNT ge 0501h)
          DEVICE_NOTIFY_ALL_INTERFACE_CLASSES equ 00000004h
        endif
        @DefProto DllImport, RegisterDeviceNotificationA, WIN_STD_CALL_CONV,, <:HANDLE, :LPVOID, :DWORD>, 12
        @DefProto DllImport, RegisterDeviceNotificationW, WIN_STD_CALL_CONV,, <:HANDLE, :LPVOID, :DWORD>, 12
        ifdef UNICODE
          RegisterDeviceNotification equ <RegisterDeviceNotificationW>
        else
          RegisterDeviceNotification equ <RegisterDeviceNotificationA>
        endif
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
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, PostMessageA, WIN_STD_CALL_CONV,, <:HWND, :UINT, :WPARAM, :LPARAM>, 16
      @DefProto DllImport, PostMessageW, WIN_STD_CALL_CONV,, <:HWND, :UINT, :WPARAM, :LPARAM>, 16
      ifdef UNICODE
        PostMessage equ <PostMessageW>
      else
        PostMessage equ <PostMessageA>
      endif
      @DefProto DllImport, PostThreadMessageA, WIN_STD_CALL_CONV,, <:DWORD, :UINT, :WPARAM, :LPARAM>, 16
      @DefProto DllImport, PostThreadMessageW, WIN_STD_CALL_CONV,, <:DWORD, :UINT, :WPARAM, :LPARAM>, 16
      ifdef UNICODE
        PostThreadMessage equ <PostThreadMessageW>
      else
        PostThreadMessage equ <PostThreadMessageA>
      endif
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
    HWND_BROADCAST equ (0ffffh)
    if (WINVER ge 0500h)
      HWND_MESSAGE equ (- 3)
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, AttachThreadInput, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :BOOL>, 12
      @DefProto DllImport, ReplyMessage, WIN_STD_CALL_CONV,, <:LRESULT>, 4
      @DefProto DllImport, WaitMessage, WIN_STD_CALL_CONV,, <>, 0
      if (_WIN32_WINNT ge 602h)
      endif
      @DefProto DllImport, WaitForInputIdle, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD>, 8
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
      @DefProto DllImport, PostQuitMessage, WIN_STD_CALL_CONV,, <:SDWORD>, 4
      ifdef STRICT
        @DefProto DllImport, CallWindowProcA, WIN_STD_CALL_CONV,, <:WNDPROC, :HWND, :UINT, :WPARAM, :LPARAM>, 20
        @DefProto DllImport, CallWindowProcW, WIN_STD_CALL_CONV,, <:WNDPROC, :HWND, :UINT, :WPARAM, :LPARAM>, 20
        ifdef UNICODE
          CallWindowProc equ <CallWindowProcW>
        else
          CallWindowProc equ <CallWindowProcA>
        endif
      else
        @DefProto DllImport, CallWindowProcA, WIN_STD_CALL_CONV,, <:FARPROC, :HWND, :UINT, :WPARAM, :LPARAM>, 20
        @DefProto DllImport, CallWindowProcW, WIN_STD_CALL_CONV,, <:FARPROC, :HWND, :UINT, :WPARAM, :LPARAM>, 20
        ifdef UNICODE
          CallWindowProc equ <CallWindowProcW>
        else
          CallWindowProc equ <CallWindowProcA>
        endif
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, InSendMessage, WIN_STD_CALL_CONV,, <>, 0
    endif
    if (WINVER ge 0500h)
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, InSendMessageEx, WIN_STD_CALL_CONV,, <:LPVOID>, 4
      endif
      ISMEX_NOSEND equ 00000000h
      ISMEX_SEND equ 00000001h
      ISMEX_NOTIFY equ 00000002h
      ISMEX_CALLBACK equ 00000004h
      ISMEX_REPLIED equ 00000008h
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, GetDoubleClickTime, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, SetDoubleClickTime, WIN_STD_CALL_CONV,, <:UINT>, 4
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, RegisterClassA, WIN_STD_CALL_CONV,, <:ptr WNDCLASSA>, 4
      @DefProto DllImport, RegisterClassW, WIN_STD_CALL_CONV,, <:ptr WNDCLASSW>, 4
      ifdef UNICODE
        RegisterClass equ <RegisterClassW>
      else
        RegisterClass equ <RegisterClassA>
      endif
      @DefProto DllImport, UnregisterClassA, WIN_STD_CALL_CONV,, <:LPCSTR, :HINSTANCE>, 8
      @DefProto DllImport, UnregisterClassW, WIN_STD_CALL_CONV,, <:LPCWSTR, :HINSTANCE>, 8
      ifdef UNICODE
        UnregisterClass equ <UnregisterClassW>
      else
        UnregisterClass equ <UnregisterClassA>
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, GetClassInfoA, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCSTR, :LPWNDCLASSA>, 12
      @DefProto DllImport, GetClassInfoW, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCWSTR, :LPWNDCLASSW>, 12
      ifdef UNICODE
        GetClassInfo equ <GetClassInfoW>
      else
        GetClassInfo equ <GetClassInfoA>
      endif
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
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, GetClassInfoExA, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCSTR, :LPWNDCLASSEXA>, 12
        @DefProto DllImport, GetClassInfoExW, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCWSTR, :LPWNDCLASSEXW>, 12
        ifdef UNICODE
          GetClassInfoEx equ <GetClassInfoExW>
        else
          GetClassInfoEx equ <GetClassInfoExA>
        endif
      endif
    endif
    CW_USEDEFAULT equ (80000000h)
    HWND_DESKTOP equ (0)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      if (_WIN32_WINNT ge 0501h)
        TYPE_PREGISTERCLASSNAMEW typedef proto WIN_STD_CALL_CONV :LPCWSTR
        PREGISTERCLASSNAMEW typedef ptr TYPE_PREGISTERCLASSNAMEW

      endif
      @DefProto DllImport, CreateWindowExA, WIN_STD_CALL_CONV,, <:DWORD, :LPCSTR, :LPCSTR, :DWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :HWND, :HMENU, :HINSTANCE, :LPVOID>, 48
      @DefProto DllImport, CreateWindowExW, WIN_STD_CALL_CONV,, <:DWORD, :LPCWSTR, :LPCWSTR, :DWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :HWND, :HMENU, :HINSTANCE, :LPVOID>, 48
      ifdef UNICODE
        CreateWindowEx equ <CreateWindowExW>
      else
        CreateWindowEx equ <CreateWindowExA>
      endif
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
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, IsWindow, WIN_STD_CALL_CONV,, <:HWND>, 4
      @DefProto DllImport, IsMenu, WIN_STD_CALL_CONV,, <:HMENU>, 4
      @DefProto DllImport, IsChild, WIN_STD_CALL_CONV,, <:HWND, :HWND>, 8
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, DestroyWindow, WIN_STD_CALL_CONV,, <:HWND>, 4
      @DefProto DllImport, ShowWindow, WIN_STD_CALL_CONV,, <:HWND, :SDWORD>, 8
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      if (WINVER ge 0500h)
        @DefProto DllImport, AnimateWindow, WIN_STD_CALL_CONV,, <:HWND, :DWORD, :DWORD>, 12
      endif
    endif
    if (_WIN32_WINNT ge 0500h)
      if Defined(_WINGDI_) and  not Defined(NOGDI)
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
          @DefProto DllImport, UpdateLayeredWindow, WIN_STD_CALL_CONV,, <:HWND, :HDC, :ptr POINT, :ptr SIZE_, :HDC, :ptr POINT, :COLORREF, :ptr BLENDFUNCTION, :DWORD>, 36
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
          endif
          UpdateLayeredWindowIndirect typedef proto :HWND, :ptr UPDATELAYEREDWINDOWINFO
        endif
      endif
      if (_WIN32_WINNT ge 0501h)
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
          @DefProto DllImport, GetLayeredWindowAttributes, WIN_STD_CALL_CONV,, <:HWND, :ptr COLORREF, :ptr BYTE, :ptr DWORD>, 16
          PW_CLIENTONLY equ 00000001h
          if (_WIN32_WINNT ge 0603h)
            PW_RENDERFULLCONTENT equ 00000002h
          endif
          @DefProto DllImport, PrintWindow, WIN_STD_CALL_CONV,, <:HWND, :HDC, :UINT>, 12
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, SetLayeredWindowAttributes, WIN_STD_CALL_CONV,, <:HWND, :COLORREF, :BYTE, :DWORD>, 16
      endif
      LWA_COLORKEY equ 00000001h
      LWA_ALPHA equ 00000002h
      ULW_COLORKEY equ 00000001h
      ULW_ALPHA equ 00000002h
      ULW_OPAQUE equ 00000004h
      ULW_EX_NORESIZE equ 00000008h
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      if (WINVER ge 0400h)
        @DefProto DllImport, ShowWindowAsync, WIN_STD_CALL_CONV,, <:HWND, :SDWORD>, 8
      endif
      @DefProto DllImport, FlashWindow, WIN_STD_CALL_CONV,, <:HWND, :BOOL>, 8
      if (WINVER ge 0500h)
        FLASHWINFO struct
          cbSize UINT ?
          hwnd HWND ?
          dwFlags DWORD ?
          uCount UINT ?
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
      endif
      @DefProto DllImport, ShowOwnedPopups, WIN_STD_CALL_CONV,, <:HWND, :BOOL>, 8
      @DefProto DllImport, OpenIcon, WIN_STD_CALL_CONV,, <:HWND>, 4
      @DefProto DllImport, CloseWindow, WIN_STD_CALL_CONV,, <:HWND>, 4
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, MoveWindow, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :BOOL>, 24
      @DefProto DllImport, SetWindowPos, WIN_STD_CALL_CONV,, <:HWND, :HWND, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :UINT>, 28
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
      endif
    endif
    ifndef NODEFERWINDOWPOS
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, BeginDeferWindowPos, WIN_STD_CALL_CONV,, <:SDWORD>, 4
        @DefProto DllImport, DeferWindowPos, WIN_STD_CALL_CONV,, <:HDWP, :HWND, :HWND, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :UINT>, 32
        @DefProto DllImport, EndDeferWindowPos, WIN_STD_CALL_CONV,, <:HDWP>, 4
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, IsWindowVisible, WIN_STD_CALL_CONV,, <:HWND>, 4
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, IsIconic, WIN_STD_CALL_CONV,, <:HWND>, 4
      @DefProto DllImport, AnyPopup, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, BringWindowToTop, WIN_STD_CALL_CONV,, <:HWND>, 4
      @DefProto DllImport, IsZoomed, WIN_STD_CALL_CONV,, <:HWND>, 4
    endif
    SWP_NOSIZE equ 0001h
    SWP_NOMOVE equ 0002h
    SWP_NOZORDER equ 0004h
    SWP_NOREDRAW equ 0008h
    SWP_NOACTIVATE equ 0010h
    SWP_FRAMECHANGED equ 0020h
    SWP_SHOWWINDOW equ 0040h
    SWP_HIDEWINDOW equ 0080h
    SWP_NOCOPYBITS equ 0100h
    SWP_NOOWNERZORDER equ 0200h
    SWP_NOSENDCHANGING equ 0400h
    SWP_DRAWFRAME equ <SWP_FRAMECHANGED>
    SWP_NOREPOSITION equ <SWP_NOOWNERZORDER>
    if (WINVER ge 0400h)
      SWP_DEFERERASE equ 2000h
      SWP_ASYNCWINDOWPOS equ 4000h
    endif
    HWND_TOP equ (0)
    HWND_BOTTOM equ (1)
    HWND_TOPMOST equ (- 1)
    HWND_NOTOPMOST equ (- 2)
    ifndef NOCTLMGR
      include pshpack2.inc
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        DLGTEMPLATE struct
          style DWORD ?
          dwExtendedStyle DWORD ?
          cdit WORD ?
          x SWORD ?
          y SWORD ?
          cx_ SWORD ?
          cy SWORD ?
        DLGTEMPLATE ends
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        LPDLGTEMPLATEA typedef ptr DLGTEMPLATE
        LPDLGTEMPLATEW typedef ptr DLGTEMPLATE
        ifdef UNICODE
          LPDLGTEMPLATE typedef LPDLGTEMPLATEW
        else
          LPDLGTEMPLATE typedef LPDLGTEMPLATEA
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        LPCDLGTEMPLATEA typedef ptr DLGTEMPLATE
        LPCDLGTEMPLATEW typedef ptr DLGTEMPLATE
        ifdef UNICODE
          LPCDLGTEMPLATE typedef LPCDLGTEMPLATEW
        else
          LPCDLGTEMPLATE typedef LPCDLGTEMPLATEA
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
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
        LPDLGITEMTEMPLATEA typedef ptr DLGITEMTEMPLATE
        LPDLGITEMTEMPLATEW typedef ptr DLGITEMTEMPLATE
        ifdef UNICODE
          LPDLGITEMTEMPLATE typedef LPDLGITEMTEMPLATEW
        else
          LPDLGITEMTEMPLATE typedef LPDLGITEMTEMPLATEA
        endif
      endif
      include poppack.inc
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, CreateDialogParamA, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCSTR, :HWND, :DLGPROC, :LPARAM>, 20
        @DefProto DllImport, CreateDialogParamW, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCWSTR, :HWND, :DLGPROC, :LPARAM>, 20
        ifdef UNICODE
          CreateDialogParam equ <CreateDialogParamW>
        else
          CreateDialogParam equ <CreateDialogParamA>
        endif
        @DefProto DllImport, CreateDialogIndirectParamA, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCDLGTEMPLATEA, :HWND, :DLGPROC, :LPARAM>, 20
        @DefProto DllImport, CreateDialogIndirectParamW, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCDLGTEMPLATEW, :HWND, :DLGPROC, :LPARAM>, 20
        ifdef UNICODE
          CreateDialogIndirectParam equ <CreateDialogIndirectParamW>
        else
          CreateDialogIndirectParam equ <CreateDialogIndirectParamA>
        endif
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
        @DefProto DllImport, DialogBoxParamA, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCSTR, :HWND, :DLGPROC, :LPARAM>, 20
        @DefProto DllImport, DialogBoxParamW, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCWSTR, :HWND, :DLGPROC, :LPARAM>, 20
        ifdef UNICODE
          DialogBoxParam equ <DialogBoxParamW>
        else
          DialogBoxParam equ <DialogBoxParamA>
        endif
        @DefProto DllImport, DialogBoxIndirectParamA, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCDLGTEMPLATEA, :HWND, :DLGPROC, :LPARAM>, 20
        @DefProto DllImport, DialogBoxIndirectParamW, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCDLGTEMPLATEW, :HWND, :DLGPROC, :LPARAM>, 20
        ifdef UNICODE
          DialogBoxIndirectParam equ <DialogBoxIndirectParamW>
        else
          DialogBoxIndirectParam equ <DialogBoxIndirectParamA>
        endif
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
        @DefProto DllImport, GetDlgItemTextA, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LPSTR, :SDWORD>, 16
        @DefProto DllImport, GetDlgItemTextW, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LPWSTR, :SDWORD>, 16
        ifdef UNICODE
          GetDlgItemText equ <GetDlgItemTextW>
        else
          GetDlgItemText equ <GetDlgItemTextA>
        endif
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
      endif
      ifndef _MAC
        DLGWINDOWEXTRA equ 30
      else
        ;[...]
      endif
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
      endif
      ifndef NOCLIPBOARD
        @DefProto DllImport, OpenClipboard, WIN_STD_CALL_CONV,, <:HWND>, 4
        @DefProto DllImport, CloseClipboard, WIN_STD_CALL_CONV,, <>, 0
        if (WINVER ge 0500h)
          @DefProto DllImport, GetClipboardSequenceNumber, WIN_STD_CALL_CONV,, <>, 0
        endif
        @DefProto DllImport, GetClipboardOwner, WIN_STD_CALL_CONV,, <>, 0
        @DefProto DllImport, SetClipboardViewer, WIN_STD_CALL_CONV,, <:HWND>, 4
        @DefProto DllImport, GetClipboardViewer, WIN_STD_CALL_CONV,, <>, 0
        @DefProto DllImport, ChangeClipboardChain, WIN_STD_CALL_CONV,, <:HWND, :HWND>, 8
        @DefProto DllImport, SetClipboardData, WIN_STD_CALL_CONV,, <:UINT, :HANDLE>, 8
        @DefProto DllImport, GetClipboardData, WIN_STD_CALL_CONV,, <:UINT>, 4
        GETCLIPBMETADATA struct
          Version UINT ?
          IsDelayRendered BOOL ?
          IsSynthetic BOOL ?
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
        @DefProto DllImport, CountClipboardFormats, WIN_STD_CALL_CONV,, <>, 0
        @DefProto DllImport, EnumClipboardFormats, WIN_STD_CALL_CONV,, <:UINT>, 4
        @DefProto DllImport, GetClipboardFormatNameA, WIN_STD_CALL_CONV,, <:UINT, :LPSTR, :SDWORD>, 12
        @DefProto DllImport, GetClipboardFormatNameW, WIN_STD_CALL_CONV,, <:UINT, :LPWSTR, :SDWORD>, 12
        ifdef UNICODE
          GetClipboardFormatName equ <GetClipboardFormatNameW>
        else
          GetClipboardFormatName equ <GetClipboardFormatNameA>
        endif
        @DefProto DllImport, EmptyClipboard, WIN_STD_CALL_CONV,, <>, 0
        @DefProto DllImport, IsClipboardFormatAvailable, WIN_STD_CALL_CONV,, <:UINT>, 4
        @DefProto DllImport, GetPriorityClipboardFormat, WIN_STD_CALL_CONV,, <:ptr UINT, :SDWORD>, 8
        @DefProto DllImport, GetOpenClipboardWindow, WIN_STD_CALL_CONV,, <>, 0
        if (WINVER ge 0600h)
          @DefProto DllImport, AddClipboardFormatListener, WIN_STD_CALL_CONV,, <:HWND>, 4
          @DefProto DllImport, RemoveClipboardFormatListener, WIN_STD_CALL_CONV,, <:HWND>, 4
          @DefProto DllImport, GetUpdatedClipboardFormats, WIN_STD_CALL_CONV,, <:PUINT, :UINT, :PUINT>, 12
        endif
      endif
      @DefProto DllImport, CharToOemA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPSTR>, 8
      @DefProto DllImport, CharToOemW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPSTR>, 8
      ifdef UNICODE
        CharToOem equ <CharToOemW>
      else
        CharToOem equ <CharToOemA>
      endif
      @DefProto DllImport, OemToCharA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPSTR>, 8
      @DefProto DllImport, OemToCharW, WIN_STD_CALL_CONV,, <:LPCSTR, :LPWSTR>, 8
      ifdef UNICODE
        OemToChar equ <OemToCharW>
      else
        OemToChar equ <OemToCharA>
      endif
      @DefProto DllImport, CharToOemBuffA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPSTR, :DWORD>, 12
      @DefProto DllImport, CharToOemBuffW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPSTR, :DWORD>, 12
      ifdef UNICODE
        CharToOemBuff equ <CharToOemBuffW>
      else
        CharToOemBuff equ <CharToOemBuffA>
      endif
      @DefProto DllImport, OemToCharBuffA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPSTR, :DWORD>, 12
      @DefProto DllImport, OemToCharBuffW, WIN_STD_CALL_CONV,, <:LPCSTR, :LPWSTR, :DWORD>, 12
      ifdef UNICODE
        OemToCharBuff equ <OemToCharBuffW>
      else
        OemToCharBuff equ <OemToCharBuffA>
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      @DefProto DllImport, CharUpperA, WIN_STD_CALL_CONV,, <:LPSTR>, 4
      @DefProto DllImport, CharUpperW, WIN_STD_CALL_CONV,, <:LPWSTR>, 4
      ifdef UNICODE
        CharUpper equ <CharUpperW>
      else
        CharUpper equ <CharUpperA>
      endif
      @DefProto DllImport, CharUpperBuffA, WIN_STD_CALL_CONV,, <:LPSTR, :DWORD>, 8
      @DefProto DllImport, CharUpperBuffW, WIN_STD_CALL_CONV,, <:LPWSTR, :DWORD>, 8
      ifdef UNICODE
        CharUpperBuff equ <CharUpperBuffW>
      else
        CharUpperBuff equ <CharUpperBuffA>
      endif
      @DefProto DllImport, CharLowerA, WIN_STD_CALL_CONV,, <:LPSTR>, 4
      @DefProto DllImport, CharLowerW, WIN_STD_CALL_CONV,, <:LPWSTR>, 4
      ifdef UNICODE
        CharLower equ <CharLowerW>
      else
        CharLower equ <CharLowerA>
      endif
      @DefProto DllImport, CharLowerBuffA, WIN_STD_CALL_CONV,, <:LPSTR, :DWORD>, 8
      @DefProto DllImport, CharLowerBuffW, WIN_STD_CALL_CONV,, <:LPWSTR, :DWORD>, 8
      ifdef UNICODE
        CharLowerBuff equ <CharLowerBuffW>
      else
        CharLowerBuff equ <CharLowerBuffA>
      endif
      @DefProto DllImport, CharNextA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
      @DefProto DllImport, CharNextW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
      ifdef UNICODE
        CharNext equ <CharNextW>
      else
        CharNext equ <CharNextA>
      endif
      @DefProto DllImport, CharPrevA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR>, 8
      @DefProto DllImport, CharPrevW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR>, 8
      ifdef UNICODE
        CharPrev equ <CharPrevW>
      else
        CharPrev equ <CharPrevA>
      endif
      if (WINVER ge 0400h)
        @DefProto DllImport, CharNextExA, WIN_STD_CALL_CONV,, <:WORD, :LPCSTR, :DWORD>, 12
        @DefProto DllImport, CharPrevExA, WIN_STD_CALL_CONV,, <:WORD, :LPCSTR, :LPCSTR, :DWORD>, 16
      endif
    endif
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
        @DefProto DllImport, IsCharAlphaA, WIN_STD_CALL_CONV,, <:CHAR>, 4
        @DefProto DllImport, IsCharAlphaW, WIN_STD_CALL_CONV,, <:WCHAR>, 4
        ifdef UNICODE
          IsCharAlpha equ <IsCharAlphaW>
        else
          IsCharAlpha equ <IsCharAlphaA>
        endif
        @DefProto DllImport, IsCharAlphaNumericA, WIN_STD_CALL_CONV,, <:CHAR>, 4
        @DefProto DllImport, IsCharAlphaNumericW, WIN_STD_CALL_CONV,, <:WCHAR>, 4
        ifdef UNICODE
          IsCharAlphaNumeric equ <IsCharAlphaNumericW>
        else
          IsCharAlphaNumeric equ <IsCharAlphaNumericA>
        endif
        @DefProto DllImport, IsCharUpperA, WIN_STD_CALL_CONV,, <:CHAR>, 4
        @DefProto DllImport, IsCharUpperW, WIN_STD_CALL_CONV,, <:WCHAR>, 4
        ifdef UNICODE
          IsCharUpper equ <IsCharUpperW>
        else
          IsCharUpper equ <IsCharUpperA>
        endif
        @DefProto DllImport, IsCharLowerA, WIN_STD_CALL_CONV,, <:CHAR>, 4
        @DefProto DllImport, IsCharLowerW, WIN_STD_CALL_CONV,, <:WCHAR>, 4
        ifdef UNICODE
          IsCharLower equ <IsCharLowerW>
        else
          IsCharLower equ <IsCharLowerA>
        endif
      endif
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
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PC_APP)
      @DefProto DllImport, GetKeyNameTextA, WIN_STD_CALL_CONV,, <:LONG, :LPSTR, :SDWORD>, 12
      @DefProto DllImport, GetKeyNameTextW, WIN_STD_CALL_CONV,, <:LONG, :LPWSTR, :SDWORD>, 12
      ifdef UNICODE
        GetKeyNameText equ <GetKeyNameTextW>
      else
        GetKeyNameText equ <GetKeyNameTextA>
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, GetKeyboardType, WIN_STD_CALL_CONV,, <:SDWORD>, 4
      @DefProto DllImport, ToAscii, WIN_STD_CALL_CONV,, <:UINT, :UINT, :ptr BYTE, :LPWORD, :UINT>, 20
      if (WINVER ge 0400h)
        @DefProto DllImport, ToAsciiEx, WIN_STD_CALL_CONV,, <:UINT, :UINT, :ptr BYTE, :LPWORD, :UINT, :HKL>, 24
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
      if (WINVER ge 0400h)
        @DefProto DllImport, VkKeyScanExA, WIN_STD_CALL_CONV,, <:CHAR, :HKL>, 8
        @DefProto DllImport, VkKeyScanExW, WIN_STD_CALL_CONV,, <:WCHAR, :HKL>, 8
        ifdef UNICODE
          VkKeyScanEx equ <VkKeyScanExW>
        else
          VkKeyScanEx equ <VkKeyScanExA>
        endif
      endif
      KEYEVENTF_EXTENDEDKEY equ 0001h
      KEYEVENTF_KEYUP equ 0002h
      if (_WIN32_WINNT ge 0500h)
        KEYEVENTF_UNICODE equ 0004h
        KEYEVENTF_SCANCODE equ 0008h
      endif
      @DefProto DllImport, keybd_event, WIN_STD_CALL_CONV,, <:BYTE, :BYTE, :DWORD, :ULONG_PTR>, 16
    endif
    MOUSEEVENTF_MOVE equ 0001h
    MOUSEEVENTF_LEFTDOWN equ 0002h
    MOUSEEVENTF_LEFTUP equ 0004h
    MOUSEEVENTF_RIGHTDOWN equ 0008h
    MOUSEEVENTF_RIGHTUP equ 0010h
    MOUSEEVENTF_MIDDLEDOWN equ 0020h
    MOUSEEVENTF_MIDDLEUP equ 0040h
    MOUSEEVENTF_XDOWN equ 0080h
    MOUSEEVENTF_XUP equ 0100h
    MOUSEEVENTF_WHEEL equ 0800h
    if (_WIN32_WINNT ge 0600h)
      MOUSEEVENTF_HWHEEL equ 01000h
    endif
    if (WINVER ge 0600h)
      MOUSEEVENTF_MOVE_NOCOALESCE equ 2000h
    endif
    MOUSEEVENTF_VIRTUALDESK equ 4000h
    MOUSEEVENTF_ABSOLUTE equ 8000h
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, mouse_event, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :DWORD, :DWORD, :ULONG_PTR>, 20
    endif
    if (_WIN32_WINNT gt 0400h)
      MOUSEINPUT struct
        dx_ LONG ?
        dy LONG ?
        mouseData DWORD ?
        dwFlags DWORD ?
        time DWORD ?
        dwExtraInfo ULONG_PTR ?
      MOUSEINPUT ends
      tagMOUSEINPUT typedef MOUSEINPUT
      PMOUSEINPUT typedef ptr MOUSEINPUT
      LPMOUSEINPUT typedef ptr MOUSEINPUT
      KEYBDINPUT struct
        wVk WORD ?
        wScan WORD ?
        dwFlags DWORD ?
        time DWORD ?
        dwExtraInfo ULONG_PTR ?
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
      endif
    endif
    if (WINVER ge 0601h)
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        DECLARE_HANDLE HTOUCHINPUT
        TOUCHINPUT struct
          x LONG ?
          y LONG ?
          hSource HANDLE ?
          dwID DWORD ?
          dwFlags DWORD ?
          dwMask DWORD ?
          dwTime DWORD ?
          dwExtraInfo ULONG_PTR ?
          cxContact DWORD ?
          cyContact DWORD ?
        TOUCHINPUT ends
        tagTOUCHINPUT typedef TOUCHINPUT
        PTOUCHINPUT typedef ptr TOUCHINPUT
        PCTOUCHINPUT typedef ptr TOUCHINPUT
      endif
      TOUCH_COORD_TO_PIXEL macro l
        exitm <((l) / 100)>
      endm
      TOUCHEVENTF_MOVE equ 0001h
      TOUCHEVENTF_DOWN equ 0002h
      TOUCHEVENTF_UP equ 0004h
      TOUCHEVENTF_INRANGE equ 0008h
      TOUCHEVENTF_PRIMARY equ 0010h
      TOUCHEVENTF_NOCOALESCE equ 0020h
      TOUCHEVENTF_PEN equ 0040h
      TOUCHEVENTF_PALM equ 0080h
      TOUCHINPUTMASKF_TIMEFROMSYSTEM equ 0001h
      TOUCHINPUTMASKF_EXTRAINFO equ 0002h
      TOUCHINPUTMASKF_CONTACTAREA equ 0004h
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, GetTouchInputInfo, WIN_STD_CALL_CONV,, <:HTOUCHINPUT, :UINT, :PTOUCHINPUT, :SDWORD>, 16
        @DefProto DllImport, CloseTouchInputHandle, WIN_STD_CALL_CONV,, <:HTOUCHINPUT>, 4
      endif
      TWF_FINETOUCH equ (00000001h)
      TWF_WANTPALM equ (00000002h)
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, RegisterTouchWindow, WIN_STD_CALL_CONV,, <:HWND, :ULONG>, 8
        @DefProto DllImport, UnregisterTouchWindow, WIN_STD_CALL_CONV,, <:HWND>, 4
        @DefProto DllImport, IsTouchWindow, WIN_STD_CALL_CONV,, <:HWND, :PULONG>, 8
      endif
    endif
    if (WINVER ge 0602h)
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        POINTER_STRUCTURES equ <>
        tagPOINTER_INPUT_TYPE typedef SDWORD
        PT_POINTER equ 1
        PT_TOUCH equ 2
        PT_PEN equ 3
        PT_MOUSE equ 4
        if (WINVER ge 0603h)
          PT_TOUCHPAD equ 5
        endif

        POINTER_INPUT_TYPE typedef DWORD
        POINTER_FLAGS typedef UINT32
      endif
      POINTER_FLAG_NONE equ 00000000h
      POINTER_FLAG_NEW equ 00000001h
      POINTER_FLAG_INRANGE equ 00000002h
      POINTER_FLAG_INCONTACT equ 00000004h
      POINTER_FLAG_FIRSTBUTTON equ 00000010h
      POINTER_FLAG_SECONDBUTTON equ 00000020h
      POINTER_FLAG_THIRDBUTTON equ 00000040h
      POINTER_FLAG_FOURTHBUTTON equ 00000080h
      POINTER_FLAG_FIFTHBUTTON equ 00000100h
      POINTER_FLAG_PRIMARY equ 00002000h
      POINTER_FLAG_CONFIDENCE equ 00004000h
      POINTER_FLAG_CANCELED equ 00008000h
      POINTER_FLAG_DOWN equ 00010000h
      POINTER_FLAG_UPDATE equ 00020000h
      POINTER_FLAG_UP equ 00040000h
      POINTER_FLAG_WHEEL equ 00080000h
      POINTER_FLAG_HWHEEL equ 00100000h
      POINTER_FLAG_CAPTURECHANGED equ 00200000h
      POINTER_FLAG_HASTRANSFORM equ 00400000h
      POINTER_MOD_SHIFT equ (0004h)
      POINTER_MOD_CTRL equ (0008h)
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
          pointerId UINT32 ?
          frameId UINT32 ?
          pointerFlags POINTER_FLAGS ?
          sourceDevice HANDLE ?
          hwndTarget HWND ?
          ptPixelLocation POINT <>
          ptHimetricLocation POINT <>
          ptPixelLocationRaw POINT <>
          ptHimetricLocationRaw POINT <>
          dwTime DWORD ?
          historyCount UINT32 ?
          InputData INT32 ?
          dwKeyStates DWORD ?
          PerformanceCount UINT64 ?
          ButtonChangeType POINTER_BUTTON_CHANGE_TYPE ?
        POINTER_INFO ends
        tagPOINTER_INFO typedef POINTER_INFO
        TOUCH_FLAGS typedef UINT32
        TOUCH_FLAG_NONE equ 00000000h
        TOUCH_MASK typedef UINT32
        TOUCH_MASK_NONE equ 00000000h
        TOUCH_MASK_CONTACTAREA equ 00000001h
        TOUCH_MASK_ORIENTATION equ 00000002h
        TOUCH_MASK_PRESSURE equ 00000004h
        POINTER_TOUCH_INFO struct
          pointerInfo POINTER_INFO <>
          touchFlags TOUCH_FLAGS ?
          touchMask TOUCH_MASK ?
          rcContact RECT <>
          rcContactRaw RECT <>
          orientation UINT32 ?
          pressure UINT32 ?
        POINTER_TOUCH_INFO ends
        tagPOINTER_TOUCH_INFO typedef POINTER_TOUCH_INFO
        PEN_FLAGS typedef UINT32
        PEN_FLAG_NONE equ 00000000h
        PEN_FLAG_BARREL equ 00000001h
        PEN_FLAG_INVERTED equ 00000002h
        PEN_FLAG_ERASER equ 00000004h
        PEN_MASK typedef UINT32
        PEN_MASK_NONE equ 00000000h
        PEN_MASK_PRESSURE equ 00000001h
        PEN_MASK_ROTATION equ 00000002h
        PEN_MASK_TILT_X equ 00000004h
        PEN_MASK_TILT_Y equ 00000008h
        POINTER_PEN_INFO struct
          pointerInfo POINTER_INFO <>
          penFlags PEN_FLAGS ?
          penMask PEN_MASK ?
          pressure UINT32 ?
          rotation UINT32 ?
          tiltX INT32 ?
          tiltY INT32 ?
        POINTER_PEN_INFO ends
        tagPOINTER_PEN_INFO typedef POINTER_PEN_INFO
      endif
      POINTER_MESSAGE_FLAG_NEW equ 00000001h
      POINTER_MESSAGE_FLAG_INRANGE equ 00000002h
      POINTER_MESSAGE_FLAG_INCONTACT equ 00000004h
      POINTER_MESSAGE_FLAG_FIRSTBUTTON equ 00000010h
      POINTER_MESSAGE_FLAG_SECONDBUTTON equ 00000020h
      POINTER_MESSAGE_FLAG_THIRDBUTTON equ 00000040h
      POINTER_MESSAGE_FLAG_FOURTHBUTTON equ 00000080h
      POINTER_MESSAGE_FLAG_FIFTHBUTTON equ 00000100h
      POINTER_MESSAGE_FLAG_PRIMARY equ 00002000h
      POINTER_MESSAGE_FLAG_CONFIDENCE equ 00004000h
      POINTER_MESSAGE_FLAG_CANCELED equ 00008000h
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
      PA_ACTIVATE equ <MA_ACTIVATE>
      PA_NOACTIVATE equ <MA_NOACTIVATE>
      MAX_TOUCH_COUNT equ 256
      TOUCH_FEEDBACK_DEFAULT equ 1h
      TOUCH_FEEDBACK_INDIRECT equ 2h
      TOUCH_FEEDBACK_NONE equ 3h
      POINTER_FEEDBACK_MODE typedef SDWORD
      POINTER_FEEDBACK_DEFAULT equ 1
      POINTER_FEEDBACK_INDIRECT equ 2
      POINTER_FEEDBACK_NONE equ 3

      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, InitializeTouchInjection, WIN_STD_CALL_CONV,, <:UINT32, :DWORD>, 8
        @DefProto DllImport, InjectTouchInput, WIN_STD_CALL_CONV,, <:UINT32, :ptr POINTER_TOUCH_INFO>, 8
        USAGE_PROPERTIES struct
          level USHORT ?
          page_ USHORT ?
          usage USHORT ?
          logicalMinimum INT32 ?
          logicalMaximum INT32 ?
          unit USHORT ?
          exponent USHORT ?
          count BYTE ?
          physicalMinimum INT32 ?
          physicalMaximum INT32 ?
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
          page_ USHORT ?
          usage USHORT ?
          value INT32 ?
          index USHORT ?
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
        TOUCH_HIT_TESTING_INPUT struct
          pointerId UINT32 ?
          point POINT <>
          boundingBox RECT <>
          nonOccludedBoundingBox RECT <>
          orientation UINT32 ?
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
      endif
    endif
    if (WINVER ge 0603h)
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
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
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PC_APP)
      if (_WIN32_WINNT ge 0500h)
        LASTINPUTINFO struct
          cbSize UINT ?
          dwTime DWORD ?
        LASTINPUTINFO ends
        tagLASTINPUTINFO typedef LASTINPUTINFO
        PLASTINPUTINFO typedef ptr LASTINPUTINFO
        @DefProto DllImport, GetLastInputInfo, WIN_STD_CALL_CONV,, <:PLASTINPUTINFO>, 4
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PC_APP)
      @DefProto DllImport, MapVirtualKeyA, WIN_STD_CALL_CONV,, <:UINT, :UINT>, 8
      @DefProto DllImport, MapVirtualKeyW, WIN_STD_CALL_CONV,, <:UINT, :UINT>, 8
      ifdef UNICODE
        MapVirtualKey equ <MapVirtualKeyW>
      else
        MapVirtualKey equ <MapVirtualKeyA>
      endif
      if (WINVER ge 0400h)
        @DefProto DllImport, MapVirtualKeyExA, WIN_STD_CALL_CONV,, <:UINT, :UINT, :HKL>, 12
        @DefProto DllImport, MapVirtualKeyExW, WIN_STD_CALL_CONV,, <:UINT, :UINT, :HKL>, 12
        ifdef UNICODE
          MapVirtualKeyEx equ <MapVirtualKeyExW>
        else
          MapVirtualKeyEx equ <MapVirtualKeyExA>
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        MAPVK_VK_TO_VSC equ (0)
        MAPVK_VSC_TO_VK equ (1)
        MAPVK_VK_TO_CHAR equ (2)
        MAPVK_VSC_TO_VK_EX equ (3)
      endif
      if (WINVER ge 0600h)
        MAPVK_VK_TO_VSC_EX equ (4)
      endif
      @DefProto DllImport, GetInputState, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, GetQueueStatus, WIN_STD_CALL_CONV,, <:UINT>, 4
      @DefProto DllImport, GetCapture, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, SetCapture, WIN_STD_CALL_CONV,, <:HWND>, 4
      @DefProto DllImport, ReleaseCapture, WIN_STD_CALL_CONV,, <>, 0
      @DefProto DllImport, MsgWaitForMultipleObjects, WIN_STD_CALL_CONV,, <:DWORD, :ptr HANDLE, :BOOL, :DWORD, :DWORD>, 20
      @DefProto DllImport, MsgWaitForMultipleObjectsEx, WIN_STD_CALL_CONV,, <:DWORD, :ptr HANDLE, :DWORD, :DWORD, :DWORD>, 20
    endif
    MWMO_WAITALL equ 0001h
    MWMO_ALERTABLE equ 0002h
    MWMO_INPUTAVAILABLE equ 0004h
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
    endif
    if (_WIN32_WINNT ge 0602h)
      QS_TOUCH equ 0800h
      QS_POINTER equ 1000h
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
    endif
    QS_ALLEVENTS equ <(QS_INPUT or QS_POSTMESSAGE or QS_TIMER or QS_PAINT or QS_HOTKEY)>
    QS_ALLINPUT equ <(QS_INPUT or QS_POSTMESSAGE or QS_TIMER or QS_PAINT or QS_HOTKEY or QS_SENDMESSAGE)>
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      USER_TIMER_MAXIMUM equ 7FFFFFFFh
      USER_TIMER_MINIMUM equ 0000000Ah
      @DefProto DllImport, SetTimer, WIN_STD_CALL_CONV,, <:HWND, :UINT_PTR, :UINT, :TIMERPROC>, 16
      if (WINVER ge 0601h)
        TIMERV_DEFAULT_COALESCING equ (0)
        TIMERV_NO_COALESCING equ (0FFFFFFFFh)
        TIMERV_COALESCING_MIN equ (1)
        TIMERV_COALESCING_MAX equ (7FFFFFF5h)
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      if (WINVER ge 0601h)
        @DefProto DllImport, SetCoalescableTimer, WIN_STD_CALL_CONV,, <:HWND, :UINT_PTR, :UINT, :TIMERPROC, :ULONG>, 20
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, KillTimer, WIN_STD_CALL_CONV,, <:HWND, :UINT_PTR>, 8
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
      @DefProto DllImport, CreateAcceleratorTableA, WIN_STD_CALL_CONV,, <:LPACCEL, :SDWORD>, 8
      @DefProto DllImport, CreateAcceleratorTableW, WIN_STD_CALL_CONV,, <:LPACCEL, :SDWORD>, 8
      ifdef UNICODE
        CreateAcceleratorTable equ <CreateAcceleratorTableW>
      else
        CreateAcceleratorTable equ <CreateAcceleratorTableA>
      endif
      @DefProto DllImport, DestroyAcceleratorTable, WIN_STD_CALL_CONV,, <:HACCEL>, 4
      @DefProto DllImport, CopyAcceleratorTableA, WIN_STD_CALL_CONV,, <:HACCEL, :LPACCEL, :SDWORD>, 12
      @DefProto DllImport, CopyAcceleratorTableW, WIN_STD_CALL_CONV,, <:HACCEL, :LPACCEL, :SDWORD>, 12
      ifdef UNICODE
        CopyAcceleratorTable equ <CopyAcceleratorTableW>
      else
        CopyAcceleratorTable equ <CopyAcceleratorTableA>
      endif
      ifndef NOMSG
        @DefProto DllImport, TranslateAcceleratorA, WIN_STD_CALL_CONV,, <:HWND, :HACCEL, :LPMSG>, 12
        @DefProto DllImport, TranslateAcceleratorW, WIN_STD_CALL_CONV,, <:HWND, :HACCEL, :LPMSG>, 12
        ifdef UNICODE
          TranslateAccelerator equ <TranslateAcceleratorW>
        else
          TranslateAccelerator equ <TranslateAcceleratorA>
        endif
      endif
    endif
    ifndef NOSYSMETRICS
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
        SM_CXFIXEDFRAME equ <SM_CXDLGFRAME>
        SM_CYFIXEDFRAME equ <SM_CYDLGFRAME>
        SM_CXSIZEFRAME equ <SM_CXFRAME>
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
      endif
      SM_SHOWSOUNDS equ 70
      if (WINVER ge 0400h)
        SM_CXMENUCHECK equ 71
        SM_CYMENUCHECK equ 72
        SM_SLOWMACHINE equ 73
        SM_MIDEASTENABLED equ 74
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
      endif
      if (_WIN32_WINNT ge 0500h)
        SM_IMMENABLED equ 82
      endif
      if (_WIN32_WINNT ge 0501h)
        SM_CXFOCUSBORDER equ 83
        SM_CYFOCUSBORDER equ 84
      endif
      if (_WIN32_WINNT ge 0501h)
        SM_TABLETPC equ 86
        SM_MEDIACENTER equ 87
        SM_STARTER equ 88
        SM_SERVERR2 equ 89
      endif
      if (_WIN32_WINNT ge 0600h)
        SM_MOUSEHORIZONTALWHEELPRESENT equ 91
        SM_CXPADDEDBORDER equ 92
      endif
      if (WINVER ge 0601h)
        SM_DIGITIZER equ 94
        SM_MAXIMUMTOUCHES equ 95
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
        endif
        if (WINVER ge 0501h)
          SM_REMOTECONTROL equ 2001h
        endif
        if (WINVER ge 0501h)
          SM_CARETBLINKINGENABLED equ 2002h
        endif
        if (WINVER ge 0602h)
          SM_CONVERTIBLESLATEMODE equ 2003h
          SM_SYSTEMDOCKED equ 2004h
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, GetSystemMetrics, WIN_STD_CALL_CONV,, <:SDWORD>, 4
        if (WINVER ge 0605h)
          @DefProto DllImport, GetSystemMetricsForDpi, WIN_STD_CALL_CONV,, <:SDWORD, :UINT>, 8
        endif
      endif
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
        @DefProto DllImport, LoadMenuIndirectA, WIN_STD_CALL_CONV,, <:ptr MENUTEMPLATEA>, 4
        @DefProto DllImport, LoadMenuIndirectW, WIN_STD_CALL_CONV,, <:ptr MENUTEMPLATEW>, 4
        ifdef UNICODE
          LoadMenuIndirect equ <LoadMenuIndirectW>
        else
          LoadMenuIndirect equ <LoadMenuIndirectA>
        endif
        @DefProto DllImport, GetMenu, WIN_STD_CALL_CONV,, <:HWND>, 4
        @DefProto DllImport, SetMenu, WIN_STD_CALL_CONV,, <:HWND, :HMENU>, 8
        @DefProto DllImport, ChangeMenuA, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :LPCSTR, :UINT, :UINT>, 20
        @DefProto DllImport, ChangeMenuW, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :LPCWSTR, :UINT, :UINT>, 20
        ifdef UNICODE
          ChangeMenu equ <ChangeMenuW>
        else
          ChangeMenu equ <ChangeMenuA>
        endif
        @DefProto DllImport, HiliteMenuItem, WIN_STD_CALL_CONV,, <:HWND, :HMENU, :UINT, :UINT>, 16
        @DefProto DllImport, GetMenuStringA, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :LPSTR, :SDWORD, :UINT>, 20
        @DefProto DllImport, GetMenuStringW, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :LPWSTR, :SDWORD, :UINT>, 20
        ifdef UNICODE
          GetMenuString equ <GetMenuStringW>
        else
          GetMenuString equ <GetMenuStringA>
        endif
        @DefProto DllImport, GetMenuState, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :UINT>, 12
        @DefProto DllImport, DrawMenuBar, WIN_STD_CALL_CONV,, <:HWND>, 4
        if (_WIN32_WINNT ge 0501h)
          PMB_ACTIVE equ 00000001h
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
        @DefProto DllImport, AppendMenuA, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :UINT_PTR, :LPCSTR>, 16
        @DefProto DllImport, AppendMenuW, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :UINT_PTR, :LPCWSTR>, 16
        ifdef UNICODE
          AppendMenu equ <AppendMenuW>
        else
          AppendMenu equ <AppendMenuA>
        endif
        @DefProto DllImport, ModifyMenuA, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :UINT, :UINT_PTR, :LPCSTR>, 20
        @DefProto DllImport, ModifyMenuW, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :UINT, :UINT_PTR, :LPCWSTR>, 20
        ifdef UNICODE
          ModifyMenu equ <ModifyMenuW>
        else
          ModifyMenu equ <ModifyMenuA>
        endif
        @DefProto DllImport, RemoveMenu, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :UINT>, 12
        @DefProto DllImport, DeleteMenu, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :UINT>, 12
        @DefProto DllImport, SetMenuItemBitmaps, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :UINT, :HBITMAP, :HBITMAP>, 20
        @DefProto DllImport, GetMenuCheckMarkDimensions, WIN_STD_CALL_CONV,, <>, 0
        @DefProto DllImport, TrackPopupMenu, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :SDWORD, :SDWORD, :SDWORD, :HWND, :ptr RECT>, 28
        if (WINVER ge 0400h)
          MNC_IGNORE equ 0
          MNC_CLOSE equ 1
          MNC_EXECUTE equ 2
          MNC_SELECT equ 3
          TPMPARAMS struct
            cbSize UINT ?
            rcExclude RECT <>
          TPMPARAMS ends
          tagTPMPARAMS typedef TPMPARAMS
          LPTPMPARAMS typedef ptr TPMPARAMS
          @DefProto DllImport, TrackPopupMenuEx, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :SDWORD, :SDWORD, :HWND, :LPTPMPARAMS>, 24
        endif
        if (_WIN32_WINNT ge 0601h)
          @DefProto DllImport, CalculatePopupWindowPosition, WIN_STD_CALL_CONV,, <:ptr POINT, :ptr SIZE_, :UINT, :ptr RECT, :ptr RECT>, 20
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
            cyMax UINT ?
            hbrBack HBRUSH ?
            dwContextHelpID DWORD ?
            dwMenuData ULONG_PTR ?
          MENUINFO ends
          tagMENUINFO typedef MENUINFO
          LPMENUINFO typedef ptr MENUINFO
          LPCMENUINFO typedef ptr MENUINFO
          @DefProto DllImport, GetMenuInfo, WIN_STD_CALL_CONV,, <:HMENU, :LPMENUINFO>, 8
          @DefProto DllImport, SetMenuInfo, WIN_STD_CALL_CONV,, <:HMENU, :LPCMENUINFO>, 8
          @DefProto DllImport, EndMenu, WIN_STD_CALL_CONV,, <>, 0
          MND_CONTINUE equ 0
          MND_ENDMENU equ 1
          MENUGETOBJECTINFO struct
            dwFlags DWORD ?
            uPos UINT ?
            hmenu HMENU ?
            riid PVOID ?
            pvObj PVOID ?
          MENUGETOBJECTINFO ends
          tagMENUGETOBJECTINFO typedef MENUGETOBJECTINFO
          PMENUGETOBJECTINFO typedef ptr MENUGETOBJECTINFO
          MNGOF_TOPGAP equ 00000001h
          MNGOF_BOTTOMGAP equ 00000002h
          MNGO_NOINTERFACE equ 00000000h
          MNGO_NOERROR equ 00000001h
        endif
        if (WINVER ge 0400h)
          MIIM_STATE equ 00000001h
          MIIM_ID equ 00000002h
          MIIM_SUBMENU equ 00000004h
          MIIM_CHECKMARKS equ 00000008h
          MIIM_TYPE equ 00000010h
          MIIM_DATA equ 00000020h
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
        endif
        if (WINVER ge 0400h)
          MENUITEMINFOA struct
            cbSize UINT ?
            fMask UINT ?
            fType UINT ?
            fState UINT ?
            wID UINT ?
            hSubMenu HMENU ?
            hbmpChecked HBITMAP ?
            hbmpUnchecked HBITMAP ?
            dwItemData ULONG_PTR ?
            dwTypeData LPSTR ?
            cch UINT ?
            if (WINVER ge 0500h)
              hbmpItem HBITMAP ?
            endif
          MENUITEMINFOA ends
          tagMENUITEMINFOA typedef MENUITEMINFOA
          LPMENUITEMINFOA typedef ptr MENUITEMINFOA
          MENUITEMINFOW struct
            cbSize UINT ?
            fMask UINT ?
            fType UINT ?
            fState UINT ?
            wID UINT ?
            hSubMenu HMENU ?
            hbmpChecked HBITMAP ?
            hbmpUnchecked HBITMAP ?
            dwItemData ULONG_PTR ?
            dwTypeData LPWSTR ?
            cch UINT ?
            if (WINVER ge 0500h)
              hbmpItem HBITMAP ?
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
          LPCMENUITEMINFOA typedef ptr MENUITEMINFOA
          LPCMENUITEMINFOW typedef ptr MENUITEMINFOW
          ifdef UNICODE
            LPCMENUITEMINFO typedef LPCMENUITEMINFOW
          else
            LPCMENUITEMINFO typedef LPCMENUITEMINFOA
          endif
          @DefProto DllImport, InsertMenuItemA, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :BOOL, :LPCMENUITEMINFOA>, 16
          @DefProto DllImport, InsertMenuItemW, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :BOOL, :LPCMENUITEMINFOW>, 16
          ifdef UNICODE
            InsertMenuItem equ <InsertMenuItemW>
          else
            InsertMenuItem equ <InsertMenuItemA>
          endif
          @DefProto DllImport, GetMenuItemInfoA, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :BOOL, :LPMENUITEMINFOA>, 16
          @DefProto DllImport, GetMenuItemInfoW, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :BOOL, :LPMENUITEMINFOW>, 16
          ifdef UNICODE
            GetMenuItemInfo equ <GetMenuItemInfoW>
          else
            GetMenuItemInfo equ <GetMenuItemInfoA>
          endif
          @DefProto DllImport, SetMenuItemInfoA, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :BOOL, :LPCMENUITEMINFOA>, 16
          @DefProto DllImport, SetMenuItemInfoW, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :BOOL, :LPCMENUITEMINFOW>, 16
          ifdef UNICODE
            SetMenuItemInfo equ <SetMenuItemInfoW>
          else
            SetMenuItemInfo equ <SetMenuItemInfoA>
          endif
          GMDI_USEDISABLED equ 0001h
          GMDI_GOINTOPOPUPS equ 0002h
          @DefProto DllImport, GetMenuDefaultItem, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :UINT>, 12
          @DefProto DllImport, SetMenuDefaultItem, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :UINT>, 12
          @DefProto DllImport, GetMenuItemRect, WIN_STD_CALL_CONV,, <:HWND, :HMENU, :UINT, :LPRECT>, 16
          @DefProto DllImport, MenuItemFromPoint, WIN_STD_CALL_CONV,, <:HWND, :HMENU, :POINT>, 12
        endif
        TPM_LEFTBUTTON equ 0000h
        TPM_RIGHTBUTTON equ 0002h
        TPM_LEFTALIGN equ 0000h
        TPM_CENTERALIGN equ 0004h
        TPM_RIGHTALIGN equ 0008h
        if (WINVER ge 0400h)
          TPM_TOPALIGN equ 0000h
          TPM_VCENTERALIGN equ 0010h
          TPM_BOTTOMALIGN equ 0020h
          TPM_HORIZONTAL equ 0000h
          TPM_VERTICAL equ 0040h
          TPM_NONOTIFY equ 0080h
          TPM_RETURNCMD equ 0100h
        endif
        if (WINVER ge 0500h)
          TPM_RECURSE equ 0001h
          TPM_HORPOSANIMATION equ 0400h
          TPM_HORNEGANIMATION equ 0800h
          TPM_VERPOSANIMATION equ 1000h
          TPM_VERNEGANIMATION equ 2000h
          if (_WIN32_WINNT ge 0500h)
            TPM_NOANIMATION equ 4000h
          endif
          if (_WIN32_WINNT ge 0501h)
            TPM_LAYOUTRTL equ 8000h
          endif
        endif
        if (_WIN32_WINNT ge 0601h)
          TPM_WORKAREA equ 10000h
        endif
      endif
    endif
    if (WINVER ge 0400h)
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        DROPSTRUCT struct
          hwndSource HWND ?
          hwndSink HWND ?
          wFmt DWORD ?
          dwData ULONG_PTR ?
          ptDrop POINT <>
          dwControlData DWORD ?
        DROPSTRUCT ends
        tagDROPSTRUCT typedef DROPSTRUCT
        PDROPSTRUCT typedef ptr DROPSTRUCT
        LPDROPSTRUCT typedef ptr DROPSTRUCT
      endif
      DOF_EXECUTABLE equ 8001h
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
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, DrawIcon, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :HICON>, 16
    endif
    ifndef NODRAWTEXT
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
          endif
        endif
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
          DRAWTEXTPARAMS struct
            cbSize UINT ?
            iTabLength SDWORD ?
            iLeftMargin SDWORD ?
            iRightMargin SDWORD ?
            uiLengthDrawn UINT ?
          DRAWTEXTPARAMS ends
          tagDRAWTEXTPARAMS typedef DRAWTEXTPARAMS
          LPDRAWTEXTPARAMS typedef ptr DRAWTEXTPARAMS
        endif
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
        endif
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, GrayStringA, WIN_STD_CALL_CONV,, <:HDC, :HBRUSH, :GRAYSTRINGPROC, :LPARAM, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD>, 36
      @DefProto DllImport, GrayStringW, WIN_STD_CALL_CONV,, <:HDC, :HBRUSH, :GRAYSTRINGPROC, :LPARAM, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD>, 36
      ifdef UNICODE
        GrayString equ <GrayStringW>
      else
        GrayString equ <GrayStringA>
      endif
    endif
    if (WINVER ge 0400h)
      DST_COMPLEX equ 0000h
      DST_TEXT equ 0001h
      DST_PREFIXTEXT equ 0002h
      DST_ICON equ 0003h
      DST_BITMAP equ 0004h
      DSS_NORMAL equ 0000h
      DSS_UNION equ 0010h
      DSS_DISABLED equ 0020h
      DSS_MONO equ 0080h
      if (_WIN32_WINNT ge 0500h)
        DSS_HIDEPREFIX equ 0200h
        DSS_PREFIXONLY equ 0400h
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
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, TabbedTextOutA, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :LPCSTR, :SDWORD, :SDWORD, :ptr INT_, :SDWORD>, 32
      @DefProto DllImport, TabbedTextOutW, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :LPCWSTR, :SDWORD, :SDWORD, :ptr INT_, :SDWORD>, 32
      ifdef UNICODE
        TabbedTextOut equ <TabbedTextOutW>
      else
        TabbedTextOut equ <TabbedTextOutA>
      endif
      @DefProto DllImport, GetTabbedTextExtentA, WIN_STD_CALL_CONV,, <:HDC, :LPCSTR, :SDWORD, :SDWORD, :ptr INT_>, 20
      @DefProto DllImport, GetTabbedTextExtentW, WIN_STD_CALL_CONV,, <:HDC, :LPCWSTR, :SDWORD, :SDWORD, :ptr INT_>, 20
      ifdef UNICODE
        GetTabbedTextExtent equ <GetTabbedTextExtentW>
      else
        GetTabbedTextExtent equ <GetTabbedTextExtentA>
      endif
      @DefProto DllImport, UpdateWindow, WIN_STD_CALL_CONV,, <:HWND>, 4
      @DefProto DllImport, SetActiveWindow, WIN_STD_CALL_CONV,, <:HWND>, 4
      @DefProto DllImport, GetForegroundWindow, WIN_STD_CALL_CONV,, <>, 0
      if (WINVER ge 0400h)
        @DefProto DllImport, PaintDesktop, WIN_STD_CALL_CONV,, <:HDC>, 4
        @DefProto DllImport, SwitchToThisWindow, WIN_STD_CALL_CONV,, <:HWND, :BOOL>, 8
      endif
      @DefProto DllImport, SetForegroundWindow, WIN_STD_CALL_CONV,, <:HWND>, 4
      if (_WIN32_WINNT ge 0500h)
        @DefProto DllImport, AllowSetForegroundWindow, WIN_STD_CALL_CONV,, <:DWORD>, 4
        ASFW_ANY equ (- 1)
        @DefProto DllImport, LockSetForegroundWindow, WIN_STD_CALL_CONV,, <:UINT>, 4
        LSFW_LOCK equ 1
        LSFW_UNLOCK equ 2
      endif
      @DefProto DllImport, WindowFromDC, WIN_STD_CALL_CONV,, <:HDC>, 4
      @DefProto DllImport, GetDC, WIN_STD_CALL_CONV,, <:HWND>, 4
      @DefProto DllImport, GetDCEx, WIN_STD_CALL_CONV,, <:HWND, :HRGN, :DWORD>, 12
    endif
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
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, GetWindowRgn, WIN_STD_CALL_CONV,, <:HWND, :HRGN>, 8
      if (_WIN32_WINNT ge 0501h)
        @DefProto DllImport, GetWindowRgnBox, WIN_STD_CALL_CONV,, <:HWND, :LPRECT>, 8
      endif
      @DefProto DllImport, ExcludeUpdateRgn, WIN_STD_CALL_CONV,, <:HDC, :HWND>, 8
      @DefProto DllImport, InvalidateRect, WIN_STD_CALL_CONV,, <:HWND, :ptr RECT, :BOOL>, 12
      @DefProto DllImport, ValidateRect, WIN_STD_CALL_CONV,, <:HWND, :ptr RECT>, 8
      @DefProto DllImport, InvalidateRgn, WIN_STD_CALL_CONV,, <:HWND, :HRGN, :BOOL>, 12
      @DefProto DllImport, ValidateRgn, WIN_STD_CALL_CONV,, <:HWND, :HRGN>, 8
      @DefProto DllImport, RedrawWindow, WIN_STD_CALL_CONV,, <:HWND, :ptr RECT, :HRGN, :UINT>, 16
    endif
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
      @DefProto DllImport, LockWindowUpdate, WIN_STD_CALL_CONV,, <:HWND>, 4
      @DefProto DllImport, ScrollWindow, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :SDWORD, :ptr RECT, :ptr RECT>, 20
      @DefProto DllImport, ScrollDC, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :ptr RECT, :ptr RECT, :HRGN, :LPRECT>, 28
      @DefProto DllImport, ScrollWindowEx, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :SDWORD, :ptr RECT, :ptr RECT, :HRGN, :LPRECT, :UINT>, 32
    endif
    SW_SCROLLCHILDREN equ 0001h
    SW_INVALIDATE equ 0002h
    SW_ERASE equ 0004h
    if (WINVER ge 0500h)
      SW_SMOOTHSCROLL equ 0010h
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ifndef NOSCROLL
        @DefProto DllImport, SetScrollPos, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :SDWORD, :BOOL>, 16
        @DefProto DllImport, GetScrollPos, WIN_STD_CALL_CONV,, <:HWND, :SDWORD>, 8
        @DefProto DllImport, SetScrollRange, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :SDWORD, :SDWORD, :BOOL>, 20
        @DefProto DllImport, GetScrollRange, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LPINT, :LPINT>, 16
        @DefProto DllImport, ShowScrollBar, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :BOOL>, 12
        @DefProto DllImport, EnableScrollBar, WIN_STD_CALL_CONV,, <:HWND, :UINT, :UINT>, 12
        ESB_ENABLE_BOTH equ 0000h
        ESB_DISABLE_BOTH equ 0003h
        ESB_DISABLE_LEFT equ 0001h
        ESB_DISABLE_RIGHT equ 0002h
        ESB_DISABLE_UP equ 0001h
        ESB_DISABLE_DOWN equ 0002h
        ESB_DISABLE_LTUP equ <ESB_DISABLE_LEFT>
        ESB_DISABLE_RTDN equ <ESB_DISABLE_RIGHT>
      endif
      @DefProto DllImport, SetPropA, WIN_STD_CALL_CONV,, <:HWND, :LPCSTR, :HANDLE>, 12
      @DefProto DllImport, SetPropW, WIN_STD_CALL_CONV,, <:HWND, :LPCWSTR, :HANDLE>, 12
      ifdef UNICODE
        SetProp equ <SetPropW>
      else
        SetProp equ <SetPropA>
      endif
      @DefProto DllImport, GetPropA, WIN_STD_CALL_CONV,, <:HWND, :LPCSTR>, 8
      @DefProto DllImport, GetPropW, WIN_STD_CALL_CONV,, <:HWND, :LPCWSTR>, 8
      ifdef UNICODE
        GetProp equ <GetPropW>
      else
        GetProp equ <GetPropA>
      endif
      @DefProto DllImport, RemovePropA, WIN_STD_CALL_CONV,, <:HWND, :LPCSTR>, 8
      @DefProto DllImport, RemovePropW, WIN_STD_CALL_CONV,, <:HWND, :LPCWSTR>, 8
      ifdef UNICODE
        RemoveProp equ <RemovePropW>
      else
        RemoveProp equ <RemovePropA>
      endif
      @DefProto DllImport, EnumPropsExA, WIN_STD_CALL_CONV,, <:HWND, :PROPENUMPROCEXA, :LPARAM>, 12
      @DefProto DllImport, EnumPropsExW, WIN_STD_CALL_CONV,, <:HWND, :PROPENUMPROCEXW, :LPARAM>, 12
      ifdef UNICODE
        EnumPropsEx equ <EnumPropsExW>
      else
        EnumPropsEx equ <EnumPropsExA>
      endif
      @DefProto DllImport, EnumPropsA, WIN_STD_CALL_CONV,, <:HWND, :PROPENUMPROCA>, 8
      @DefProto DllImport, EnumPropsW, WIN_STD_CALL_CONV,, <:HWND, :PROPENUMPROCW>, 8
      ifdef UNICODE
        EnumProps equ <EnumPropsW>
      else
        EnumProps equ <EnumPropsA>
      endif
      @DefProto DllImport, SetWindowTextA, WIN_STD_CALL_CONV,, <:HWND, :LPCSTR>, 8
      @DefProto DllImport, SetWindowTextW, WIN_STD_CALL_CONV,, <:HWND, :LPCWSTR>, 8
      ifdef UNICODE
        SetWindowText equ <SetWindowTextW>
      else
        SetWindowText equ <SetWindowTextA>
      endif
      @DefProto DllImport, GetWindowTextA, WIN_STD_CALL_CONV,, <:HWND, :LPSTR, :SDWORD>, 12
      @DefProto DllImport, GetWindowTextW, WIN_STD_CALL_CONV,, <:HWND, :LPWSTR, :SDWORD>, 12
      ifdef UNICODE
        GetWindowText equ <GetWindowTextW>
      else
        GetWindowText equ <GetWindowTextA>
      endif
      @DefProto DllImport, GetWindowTextLengthA, WIN_STD_CALL_CONV,, <:HWND>, 4
      @DefProto DllImport, GetWindowTextLengthW, WIN_STD_CALL_CONV,, <:HWND>, 4
      ifdef UNICODE
        GetWindowTextLength equ <GetWindowTextLengthW>
      else
        GetWindowTextLength equ <GetWindowTextLengthA>
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, GetClientRect, WIN_STD_CALL_CONV,, <:HWND, :LPRECT>, 8
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, GetWindowRect, WIN_STD_CALL_CONV,, <:HWND, :LPRECT>, 8
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, AdjustWindowRect, WIN_STD_CALL_CONV,, <:LPRECT, :DWORD, :BOOL>, 12
      @DefProto DllImport, AdjustWindowRectEx, WIN_STD_CALL_CONV,, <:LPRECT, :DWORD, :BOOL, :DWORD>, 16
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      if (WINVER ge 0605h)
        @DefProto DllImport, AdjustWindowRectExForDpi, WIN_STD_CALL_CONV,, <:LPRECT, :DWORD, :BOOL, :DWORD, :UINT>, 20
      endif
    endif
    if (WINVER ge 0400h)
      HELPINFO_WINDOW equ 0001h
      HELPINFO_MENUITEM equ 0002h
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        HELPINFO struct
          cbSize UINT ?
          iContextType SDWORD ?
          iCtrlId SDWORD ?
          hItemHandle HANDLE ?
          dwContextId DWORD_PTR ?
          MousePos POINT <>
        HELPINFO ends
        tagHELPINFO typedef HELPINFO
        LPHELPINFO typedef ptr HELPINFO
        @DefProto DllImport, SetWindowContextHelpId, WIN_STD_CALL_CONV,, <:HWND, :DWORD>, 8
        @DefProto DllImport, GetWindowContextHelpId, WIN_STD_CALL_CONV,, <:HWND>, 4
        @DefProto DllImport, SetMenuContextHelpId, WIN_STD_CALL_CONV,, <:HMENU, :DWORD>, 8
        @DefProto DllImport, GetMenuContextHelpId, WIN_STD_CALL_CONV,, <:HMENU>, 4
      endif
    endif
    ifndef NOMB
      MB_OK equ 00000000h
      MB_OKCANCEL equ 00000001h
      MB_ABORTRETRYIGNORE equ 00000002h
      MB_YESNOCANCEL equ 00000003h
      MB_YESNO equ 00000004h
      MB_RETRYCANCEL equ 00000005h
      if (WINVER ge 0500h)
        MB_CANCELTRYCONTINUE equ 00000006h
      endif
      MB_ICONHAND equ 00000010h
      MB_ICONQUESTION equ 00000020h
      MB_ICONEXCLAMATION equ 00000030h
      MB_ICONASTERISK equ 00000040h
      if (WINVER ge 0400h)
        MB_USERICON equ 00000080h
        MB_ICONWARNING equ <MB_ICONEXCLAMATION>
        MB_ICONERROR equ <MB_ICONHAND>
      endif
      MB_ICONINFORMATION equ <MB_ICONASTERISK>
      MB_ICONSTOP equ <MB_ICONHAND>
      MB_DEFBUTTON1 equ 00000000h
      MB_DEFBUTTON2 equ 00000100h
      MB_DEFBUTTON3 equ 00000200h
      if (WINVER ge 0400h)
        MB_DEFBUTTON4 equ 00000300h
      endif
      MB_APPLMODAL equ 00000000h
      MB_SYSTEMMODAL equ 00001000h
      MB_TASKMODAL equ 00002000h
      if (WINVER ge 0400h)
        MB_HELP equ 00004000h
      endif
      MB_NOFOCUS equ 00008000h
      MB_SETFOREGROUND equ 00010000h
      MB_DEFAULT_DESKTOP_ONLY equ 00020000h
      if (WINVER ge 0400h)
        MB_TOPMOST equ 00040000h
        MB_RIGHT equ 00080000h
        MB_RTLREADING equ 00100000h
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
        if (WINVER ge 0400h)
          TYPE_MSGBOXCALLBACK typedef proto WIN_STD_CALL_CONV :LPHELPINFO
          MSGBOXCALLBACK typedef ptr TYPE_MSGBOXCALLBACK

          MSGBOXPARAMSA struct
            cbSize UINT ?
            hwndOwner HWND ?
            hInstance HINSTANCE ?
            lpszText LPCSTR ?
            lpszCaption LPCSTR ?
            dwStyle DWORD ?
            lpszIcon LPCSTR ?
            dwContextHelpId DWORD_PTR ?
            lpfnMsgBoxCallback MSGBOXCALLBACK ?
            dwLanguageId DWORD ?
          MSGBOXPARAMSA ends
          tagMSGBOXPARAMSA typedef MSGBOXPARAMSA
          PMSGBOXPARAMSA typedef ptr MSGBOXPARAMSA
          LPMSGBOXPARAMSA typedef ptr MSGBOXPARAMSA
          MSGBOXPARAMSW struct
            cbSize UINT ?
            hwndOwner HWND ?
            hInstance HINSTANCE ?
            lpszText LPCWSTR ?
            lpszCaption LPCWSTR ?
            dwStyle DWORD ?
            lpszIcon LPCWSTR ?
            dwContextHelpId DWORD_PTR ?
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
          @DefProto DllImport, MessageBoxIndirectA, WIN_STD_CALL_CONV,, <:ptr MSGBOXPARAMSA>, 4
          @DefProto DllImport, MessageBoxIndirectW, WIN_STD_CALL_CONV,, <:ptr MSGBOXPARAMSW>, 4
          ifdef UNICODE
            MessageBoxIndirect equ <MessageBoxIndirectW>
          else
            MessageBoxIndirect equ <MessageBoxIndirectA>
          endif
        endif
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, MessageBeep, WIN_STD_CALL_CONV,, <:UINT>, 4
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, ShowCursor, WIN_STD_CALL_CONV,, <:BOOL>, 4
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, SetCursorPos, WIN_STD_CALL_CONV,, <:SDWORD, :SDWORD>, 8
      if (WINVER ge 0600h)
        @DefProto DllImport, SetPhysicalCursorPos, WIN_STD_CALL_CONV,, <:SDWORD, :SDWORD>, 8
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, SetCursor, WIN_STD_CALL_CONV,, <:HCURSOR>, 4
      @DefProto DllImport, GetCursorPos, WIN_STD_CALL_CONV,, <:LPPOINT>, 4
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      if (WINVER ge 0600h)
        @DefProto DllImport, GetPhysicalCursorPos, WIN_STD_CALL_CONV,, <:LPPOINT>, 4
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
      endif
      if (WINVER ge 0603h)
        @DefProto DllImport, LogicalToPhysicalPointForPerMonitorDPI, WIN_STD_CALL_CONV,, <:HWND, :LPPOINT>, 8
        @DefProto DllImport, PhysicalToLogicalPointForPerMonitorDPI, WIN_STD_CALL_CONV,, <:HWND, :LPPOINT>, 8
      endif
      @DefProto DllImport, MapWindowPoints, WIN_STD_CALL_CONV,, <:HWND, :HWND, :LPPOINT, :UINT>, 16
      @DefProto DllImport, WindowFromPoint, WIN_STD_CALL_CONV,, <:POINT>, 4
      if (WINVER ge 0600h)
        @DefProto DllImport, WindowFromPhysicalPoint, WIN_STD_CALL_CONV,, <:POINT>, 4
      endif
      @DefProto DllImport, ChildWindowFromPoint, WIN_STD_CALL_CONV,, <:HWND, :POINT>, 8
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PC_APP)
      @DefProto DllImport, ClipCursor, WIN_STD_CALL_CONV,, <:ptr RECT>, 4
    endif
    if (WINVER ge 0400h)
      CWP_ALL equ 0000h
      CWP_SKIPINVISIBLE equ 0001h
      CWP_SKIPDISABLED equ 0002h
      CWP_SKIPTRANSPARENT equ 0004h
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, ChildWindowFromPointEx, WIN_STD_CALL_CONV,, <:HWND, :POINT, :UINT>, 12
      endif
    endif
    ifndef NOCOLOR
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
      endif
      if (WINVER ge 0500h)
        COLOR_HOTLIGHT equ 26
        COLOR_GRADIENTACTIVECAPTION equ 27
        COLOR_GRADIENTINACTIVECAPTION equ 28
        if (WINVER ge 0501h)
          COLOR_MENUHILIGHT equ 29
          COLOR_MENUBAR equ 30
        endif
      endif
      if (WINVER ge 0400h)
        COLOR_DESKTOP equ <COLOR_BACKGROUND>
        COLOR_3DFACE equ <COLOR_BTNFACE>
        COLOR_3DSHADOW equ <COLOR_BTNSHADOW>
        COLOR_3DHIGHLIGHT equ <COLOR_BTNHIGHLIGHT>
        COLOR_3DHILIGHT equ <COLOR_BTNHIGHLIGHT>
        COLOR_BTNHILIGHT equ <COLOR_BTNHIGHLIGHT>
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, GetSysColor, WIN_STD_CALL_CONV,, <:SDWORD>, 4
        if (WINVER ge 0400h)
          @DefProto DllImport, GetSysColorBrush, WIN_STD_CALL_CONV,, <:SDWORD>, 4
        endif
        @DefProto DllImport, SetSysColors, WIN_STD_CALL_CONV,, <:SDWORD, :ptr INT_, :ptr COLORREF>, 12
      endif
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
      endif
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
        @DefProto DllImport, SetWindowLongA, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LONG>, 12
        @DefProto DllImport, SetWindowLongW, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LONG>, 12
        ifdef UNICODE
          SetWindowLong equ <SetWindowLongW>
        else
          SetWindowLong equ <SetWindowLongA>
        endif
        ifdef _WIN64
          @DefProto DllImport, GetWindowLongPtrA, WIN_STD_CALL_CONV,, <:HWND, :SDWORD>, 8
          @DefProto DllImport, GetWindowLongPtrW, WIN_STD_CALL_CONV,, <:HWND, :SDWORD>, 8
          ifdef UNICODE
            GetWindowLongPtr equ <GetWindowLongPtrW>
          else
            GetWindowLongPtr equ <GetWindowLongPtrA>
          endif
          @DefProto DllImport, SetWindowLongPtrA, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LONG_PTR>, 12
          @DefProto DllImport, SetWindowLongPtrW, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LONG_PTR>, 12
          ifdef UNICODE
            SetWindowLongPtr equ <SetWindowLongPtrW>
          else
            SetWindowLongPtr equ <SetWindowLongPtrA>
          endif
        else
          GetWindowLongPtrA equ <GetWindowLongA>
          GetWindowLongPtrW equ <GetWindowLongW>
          ifdef UNICODE
            GetWindowLongPtr equ <GetWindowLongPtrW>
          else
            GetWindowLongPtr equ <GetWindowLongPtrA>
          endif
          SetWindowLongPtrA equ <SetWindowLongA>
          SetWindowLongPtrW equ <SetWindowLongW>
          ifdef UNICODE
            SetWindowLongPtr equ <SetWindowLongPtrW>
          else
            SetWindowLongPtr equ <SetWindowLongPtrA>
          endif
        endif
      endif
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
        @DefProto DllImport, SetClassLongA, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LONG>, 12
        @DefProto DllImport, SetClassLongW, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LONG>, 12
        ifdef UNICODE
          SetClassLong equ <SetClassLongW>
        else
          SetClassLong equ <SetClassLongA>
        endif
        ifdef _WIN64
          @DefProto DllImport, GetClassLongPtrA, WIN_STD_CALL_CONV,, <:HWND, :SDWORD>, 8
          @DefProto DllImport, GetClassLongPtrW, WIN_STD_CALL_CONV,, <:HWND, :SDWORD>, 8
          ifdef UNICODE
            GetClassLongPtr equ <GetClassLongPtrW>
          else
            GetClassLongPtr equ <GetClassLongPtrA>
          endif
          @DefProto DllImport, SetClassLongPtrA, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LONG_PTR>, 12
          @DefProto DllImport, SetClassLongPtrW, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LONG_PTR>, 12
          ifdef UNICODE
            SetClassLongPtr equ <SetClassLongPtrW>
          else
            SetClassLongPtr equ <SetClassLongPtrA>
          endif
        else
          GetClassLongPtrA equ <GetClassLongA>
          GetClassLongPtrW equ <GetClassLongW>
          ifdef UNICODE
            GetClassLongPtr equ <GetClassLongPtrW>
          else
            GetClassLongPtr equ <GetClassLongPtrA>
          endif
          SetClassLongPtrA equ <SetClassLongA>
          SetClassLongPtrW equ <SetClassLongW>
          ifdef UNICODE
            SetClassLongPtr equ <SetClassLongPtrW>
          else
            SetClassLongPtr equ <SetClassLongPtrA>
          endif
        endif
      endif
      if (WINVER ge 0500h)
        @DefProto DllImport, GetProcessDefaultLayout, WIN_STD_CALL_CONV,, <:ptr DWORD>, 4
        @DefProto DllImport, SetProcessDefaultLayout, WIN_STD_CALL_CONV,, <:DWORD>, 4
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
      if (WINVER ge 0400h)
        @DefProto DllImport, FindWindowExA, WIN_STD_CALL_CONV,, <:HWND, :HWND, :LPCSTR, :LPCSTR>, 16
        @DefProto DllImport, FindWindowExW, WIN_STD_CALL_CONV,, <:HWND, :HWND, :LPCWSTR, :LPCWSTR>, 16
        ifdef UNICODE
          FindWindowEx equ <FindWindowExW>
        else
          FindWindowEx equ <FindWindowExA>
        endif
        @DefProto DllImport, GetShellWindow, WIN_STD_CALL_CONV,, <>, 0
      endif
      @DefProto DllImport, RegisterShellHookWindow, WIN_STD_CALL_CONV,, <:HWND>, 4
      @DefProto DllImport, DeregisterShellHookWindow, WIN_STD_CALL_CONV,, <:HWND>, 4
      @DefProto DllImport, EnumWindows, WIN_STD_CALL_CONV,, <:WNDENUMPROC, :LPARAM>, 8
      @DefProto DllImport, EnumThreadWindows, WIN_STD_CALL_CONV,, <:DWORD, :WNDENUMPROC, :LPARAM>, 12
      EnumTaskWindows macro hTask, lpfn, lParam
        exitm <EnumThreadWindows (HandleToUlong(hTask), lpfn, lParam)>
      endm
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, GetClassNameA, WIN_STD_CALL_CONV,, <:HWND, :LPSTR, :SDWORD>, 12
      @DefProto DllImport, GetClassNameW, WIN_STD_CALL_CONV,, <:HWND, :LPWSTR, :SDWORD>, 12
      ifdef UNICODE
        GetClassName equ <GetClassNameW>
      else
        GetClassName equ <GetClassNameA>
      endif
      if Defined(_M_CEE)
        ;[...]
      endif
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
      endif
      GetWindowTask macro hWnd
        exitm <(GetWindowThreadProcessId (hWnd, NULL))>
      endm
      @DefProto DllImport, GetLastActivePopup, WIN_STD_CALL_CONV,, <:HWND>, 4
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
        else
          @DefProto DllImport, SetWindowsHookA, WIN_STD_CALL_CONV,, <:SDWORD, :HOOKPROC>, 8
          @DefProto DllImport, SetWindowsHookW, WIN_STD_CALL_CONV,, <:SDWORD, :HOOKPROC>, 8
          ifdef UNICODE
            SetWindowsHook equ <SetWindowsHookW>
          else
            SetWindowsHook equ <SetWindowsHookA>
          endif
        endif
        @DefProto DllImport, UnhookWindowsHook, WIN_STD_CALL_CONV,, <:SDWORD, :HOOKPROC>, 8
        @DefProto DllImport, SetWindowsHookExA, WIN_STD_CALL_CONV,, <:SDWORD, :HOOKPROC, :HINSTANCE, :DWORD>, 16
        @DefProto DllImport, SetWindowsHookExW, WIN_STD_CALL_CONV,, <:SDWORD, :HOOKPROC, :HINSTANCE, :DWORD>, 16
        ifdef UNICODE
          SetWindowsHookEx equ <SetWindowsHookExW>
        else
          SetWindowsHookEx equ <SetWindowsHookExA>
        endif
        @DefProto DllImport, UnhookWindowsHookEx, WIN_STD_CALL_CONV,, <:HHOOK>, 4
        @DefProto DllImport, CallNextHookEx, WIN_STD_CALL_CONV,, <:HHOOK, :SDWORD, :WPARAM, :LPARAM>, 16
        ifdef STRICT
          DefHookProc macro nCode, wParam, lParam, phhk
            exitm <CallNextHookEx (* phhk, nCode, wParam, lParam)>
          endm
        else
          DefHookProc macro nCode, wParam, lParam, phhk
            exitm <CallNextHookEx ((HHOOK) * phhk, nCode, wParam, lParam)>
          endm
        endif
      endif
    endif
    ifndef NOMENUS
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
      endif
      MF_SYSMENU equ 00002000h
      MF_HELP equ 00004000h
      if (WINVER ge 0400h)
        MF_RIGHTJUSTIFY equ 00004000h
      endif
      MF_MOUSESELECT equ 00008000h
      if (WINVER ge 0400h)
        MF_END equ 00000080h
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
        MFS_GRAYED equ 00000003h
        MFS_DISABLED equ <MFS_GRAYED>
        MFS_CHECKED equ <MF_CHECKED>
        MFS_HILITE equ <MF_HILITE>
        MFS_ENABLED equ <MF_ENABLED>
        MFS_UNCHECKED equ <MF_UNCHECKED>
        MFS_UNHILITE equ <MF_UNHILITE>
        MFS_DEFAULT equ <MF_DEFAULT>
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        if (WINVER ge 0400h)
          @DefProto DllImport, CheckMenuRadioItem, WIN_STD_CALL_CONV,, <:HMENU, :UINT, :UINT, :UINT, :UINT>, 20
        endif
        MENUITEMTEMPLATEHEADER struct
          versionNumber WORD ?
          offset_ WORD ?
        MENUITEMTEMPLATEHEADER ends
        PMENUITEMTEMPLATEHEADER typedef ptr MENUITEMTEMPLATEHEADER
        MENUITEMTEMPLATE struct
          mtOption WORD ?
          mtID WORD ?
          mtString WCHAR 1 dup (?)
        MENUITEMTEMPLATE ends
        PMENUITEMTEMPLATE typedef ptr MENUITEMTEMPLATE
        MF_END equ 00000080h
      endif
    endif
    ifndef NOSYSCOMMANDS
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
      endif
      if (WINVER ge 0600h)
        SCF_ISSECURE equ 00000001h
      endif
      GET_SC_WPARAM macro wParam
        exitm <(wParam and 0FFF0h)>
      endm
      SC_ICON equ <SC_MINIMIZE>
      SC_ZOOM equ <SC_MAXIMIZE>
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, LoadBitmapA, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCSTR>, 8
      @DefProto DllImport, LoadBitmapW, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCWSTR>, 8
      ifdef UNICODE
        LoadBitmap equ <LoadBitmapW>
      else
        LoadBitmap equ <LoadBitmapA>
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, LoadCursorA, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCSTR>, 8
      @DefProto DllImport, LoadCursorW, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCWSTR>, 8
      ifdef UNICODE
        LoadCursor equ <LoadCursorW>
      else
        LoadCursor equ <LoadCursorA>
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, LoadCursorFromFileA, WIN_STD_CALL_CONV,, <:LPCSTR>, 4
      @DefProto DllImport, LoadCursorFromFileW, WIN_STD_CALL_CONV,, <:LPCWSTR>, 4
      ifdef UNICODE
        LoadCursorFromFile equ <LoadCursorFromFileW>
      else
        LoadCursorFromFile equ <LoadCursorFromFileA>
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      @DefProto DllImport, CreateCursor, WIN_STD_CALL_CONV,, <:HINSTANCE, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :ptr VOID, :ptr VOID>, 28
      @DefProto DllImport, DestroyCursor, WIN_STD_CALL_CONV,, <:HCURSOR>, 4
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ifndef _MAC
        CopyCursor macro pcur
          exitm <(CopyIcon ((HICON) (pcur)))>
        endm
      else
        ;[...]
      endif
    endif
    IDC_ARROW equ MAKEINTRESOURCE (32512)
    IDC_IBEAM equ MAKEINTRESOURCE (32513)
    IDC_WAIT equ MAKEINTRESOURCE (32514)
    IDC_CROSS equ MAKEINTRESOURCE (32515)
    IDC_UPARROW equ MAKEINTRESOURCE (32516)
    IDC_SIZE equ MAKEINTRESOURCE (32640)
    IDC_ICON equ MAKEINTRESOURCE (32641)
    IDC_SIZENWSE equ MAKEINTRESOURCE (32642)
    IDC_SIZENESW equ MAKEINTRESOURCE (32643)
    IDC_SIZEWE equ MAKEINTRESOURCE (32644)
    IDC_SIZENS equ MAKEINTRESOURCE (32645)
    IDC_SIZEALL equ MAKEINTRESOURCE (32646)
    IDC_NO equ MAKEINTRESOURCE (32648)
    if (WINVER ge 0500h)
      IDC_HAND equ MAKEINTRESOURCE (32649)
    endif
    IDC_APPSTARTING equ MAKEINTRESOURCE (32650)
    if (WINVER ge 0400h)
      IDC_HELP equ MAKEINTRESOURCE (32651)
    endif
    if (WINVER ge 0606h)
      IDC_PIN equ MAKEINTRESOURCE (32671)
      IDC_PERSON equ MAKEINTRESOURCE (32672)
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, SetSystemCursor, WIN_STD_CALL_CONV,, <:HCURSOR, :DWORD>, 8
      ICONINFO struct
        fIcon BOOL ?
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
      @DefProto DllImport, PrivateExtractIconsA, WIN_STD_CALL_CONV,, <:LPCSTR, :SDWORD, :SDWORD, :SDWORD, :ptr HICON, :ptr UINT, :UINT, :UINT>, 32
      @DefProto DllImport, PrivateExtractIconsW, WIN_STD_CALL_CONV,, <:LPCWSTR, :SDWORD, :SDWORD, :SDWORD, :ptr HICON, :ptr UINT, :UINT, :UINT>, 32
      ifdef UNICODE
        PrivateExtractIcons equ <PrivateExtractIconsW>
      else
        PrivateExtractIcons equ <PrivateExtractIconsA>
      endif
      @DefProto DllImport, CreateIcon, WIN_STD_CALL_CONV,, <:HINSTANCE, :SDWORD, :SDWORD, :BYTE, :BYTE, :ptr BYTE, :ptr BYTE>, 28
      @DefProto DllImport, DestroyIcon, WIN_STD_CALL_CONV,, <:HICON>, 4
      @DefProto DllImport, LookupIconIdFromDirectory, WIN_STD_CALL_CONV,, <:PBYTE, :BOOL>, 8
      if (WINVER ge 0400h)
        @DefProto DllImport, LookupIconIdFromDirectoryEx, WIN_STD_CALL_CONV,, <:PBYTE, :BOOL, :SDWORD, :SDWORD, :UINT>, 20
      endif
      @DefProto DllImport, CreateIconFromResource, WIN_STD_CALL_CONV,, <:PBYTE, :DWORD, :BOOL, :DWORD>, 16
      if (WINVER ge 0400h)
        @DefProto DllImport, CreateIconFromResourceEx, WIN_STD_CALL_CONV,, <:PBYTE, :DWORD, :BOOL, :DWORD, :SDWORD, :SDWORD, :UINT>, 28
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
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
      if (NTDDI_VERSION ge NTDDI_WIN10_CO)
        CURSOR_CREATION_SCALING_NONE equ 1
        CURSOR_CREATION_SCALING_DEFAULT equ 2
        @DefProto DllImport, SetThreadCursorCreationScaling, WIN_STD_CALL_CONV,, <:UINT>, 4
      endif
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
        @DefProto DllImport, CopyImage, WIN_STD_CALL_CONV,, <:HANDLE, :UINT, :SDWORD, :SDWORD, :UINT>, 20
        DI_MASK equ 0001h
        DI_IMAGE equ 0002h
        DI_NORMAL equ 0003h
        DI_COMPAT equ 0004h
        DI_DEFAULTSIZE equ 0008h
        if (_WIN32_WINNT ge 0501h)
          DI_NOMIRROR equ 0010h
        endif
        @DefProto DllImport, DrawIconEx, WIN_STD_CALL_CONV,, <:HDC, :SDWORD, :SDWORD, :HICON, :SDWORD, :SDWORD, :UINT, :HBRUSH, :UINT>, 36
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, CreateIconIndirect, WIN_STD_CALL_CONV,, <:PICONINFO>, 4
      @DefProto DllImport, CopyIcon, WIN_STD_CALL_CONV,, <:HICON>, 4
      @DefProto DllImport, GetIconInfo, WIN_STD_CALL_CONV,, <:HICON, :PICONINFO>, 8
      if (_WIN32_WINNT ge 0600h)
        ICONINFOEXA struct
          cbSize DWORD ?
          fIcon BOOL ?
          xHotspot DWORD ?
          yHotspot DWORD ?
          hbmMask HBITMAP ?
          hbmColor HBITMAP ?
          wResID WORD ?
          szModName CHAR MAX_PATH dup (?)
          szResName CHAR MAX_PATH dup (?)
        ICONINFOEXA ends
        _ICONINFOEXA typedef ICONINFOEXA
        PICONINFOEXA typedef ptr ICONINFOEXA
        ICONINFOEXW struct
          cbSize DWORD ?
          fIcon BOOL ?
          xHotspot DWORD ?
          yHotspot DWORD ?
          hbmMask HBITMAP ?
          hbmColor HBITMAP ?
          wResID WORD ?
          szModName WCHAR MAX_PATH dup (?)
          szResName WCHAR MAX_PATH dup (?)
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
        @DefProto DllImport, GetIconInfoExA, WIN_STD_CALL_CONV,, <:HICON, :PICONINFOEXA>, 8
        @DefProto DllImport, GetIconInfoExW, WIN_STD_CALL_CONV,, <:HICON, :PICONINFOEXW>, 8
        ifdef UNICODE
          GetIconInfoEx equ <GetIconInfoExW>
        else
          GetIconInfoEx equ <GetIconInfoExA>
        endif
      endif
      if (WINVER ge 0400h)
        RES_ICON equ 1
        RES_CURSOR equ 2
      endif
    endif
    ifdef OEMRESOURCE
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
      OCR_SIZE equ 32640
      OCR_ICON equ 32641
      OCR_SIZENWSE equ 32642
      OCR_SIZENESW equ 32643
      OCR_SIZEWE equ 32644
      OCR_SIZENS equ 32645
      OCR_SIZEALL equ 32646
      OCR_ICOCUR equ 32647
      OCR_NO equ 32648
      if (WINVER ge 0500h)
        OCR_HAND equ 32649
      endif
      if (WINVER ge 0400h)
        OCR_APPSTARTING equ 32650
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
      endif
      if (WINVER ge 0600h)
        OIC_SHIELD equ 32518
      endif
    endif
    ORD_LANGDRIVER equ 1
    ifndef NOICONS
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
        endif
        if (WINVER ge 0600h)
          IDI_SHIELD equ MAKEINTRESOURCE (32518)
        endif
      endif
      if (WINVER ge 0400h)
        IDI_WARNING equ <IDI_EXCLAMATION>
        IDI_ERROR equ <IDI_HAND>
        IDI_INFORMATION equ <IDI_ASTERISK>
      endif
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
      endif
    endif
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
    endif
    if (WINVER ge 0500h)
      IDTRYAGAIN equ 10
      IDCONTINUE equ 11
    endif
    if (WINVER ge 0501h)
      ifndef IDTIMEOUT
        IDTIMEOUT equ 32000
      endif
    endif
    ifndef NOCTLMGR
      ifndef NOWINSTYLES
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
        endif
      endif
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
      endif
      if (WINVER ge 0604h)
        EN_BEFORE_PASTE equ 0800h
        EN_AFTER_PASTE equ 0801h
      endif
      if (WINVER ge 0400h)
        EC_LEFTMARGIN equ 0001h
        EC_RIGHTMARGIN equ 0002h
        EC_USEFONTINFO equ 0ffffh
      endif
      if (WINVER ge 0500h)
        EMSIS_COMPOSITIONSTRING equ 0001h
        EIMES_GETCOMPSTRATONCE equ 0001h
        EIMES_CANCELCOMPSTRINFOCUS equ 0002h
        EIMES_COMPLETECOMPSTRKILLFOCUS equ 0004h
      endif
      ifndef NOWINMESSAGES
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
          EM_SETLIMITTEXT equ <EM_LIMITTEXT>
          EM_GETLIMITTEXT equ 00D5h
          EM_POSFROMCHAR equ 00D6h
          EM_CHARFROMPOS equ 00D7h
        endif
        if (WINVER ge 0500h)
          EM_SETIMESTATUS equ 00D8h
          EM_GETIMESTATUS equ 00D9h
        endif
        if (WINVER ge 0604h)
          EM_ENABLEFEATURE equ 00DAh
        endif
      endif
      if (WINVER ge 0604h)
        EDIT_CONTROL_FEATURE typedef SDWORD
        EDIT_CONTROL_FEATURE_ENTERPRISE_DATA_PROTECTION_PASTE_SUPPORT equ 0
        EDIT_CONTROL_FEATURE_PASTE_NOTIFICATIONS equ 1

      endif
      WB_LEFT equ 0
      WB_RIGHT equ 1
      WB_ISDELIMITER equ 2
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
      endif
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
      endif
      BM_GETCHECK equ 00F0h
      BM_SETCHECK equ 00F1h
      BM_GETSTATE equ 00F2h
      BM_SETSTATE equ 00F3h
      BM_SETSTYLE equ 00F4h
      if (WINVER ge 0400h)
        BM_CLICK equ 00F5h
        BM_GETIMAGE equ 00F6h
        BM_SETIMAGE equ 00F7h
      endif
      if (WINVER ge 0600h)
        BM_SETDONTCLICK equ 00F8h
      endif
      if (WINVER ge 0400h)
        BST_UNCHECKED equ 0000h
        BST_CHECKED equ 0001h
        BST_INDETERMINATE equ 0002h
        BST_PUSHED equ 0004h
        BST_FOCUS equ 0008h
      endif
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
      endif
      if (WINVER ge 0501h)
        SS_REALSIZECONTROL equ 00000040h
      endif
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
      endif
      ifndef NOWINMESSAGES
        STM_SETICON equ 0170h
        STM_GETICON equ 0171h
        if (WINVER ge 0400h)
          STM_SETIMAGE equ 0172h
          STM_GETIMAGE equ 0173h
          STN_CLICKED equ 0
          STN_DBLCLK equ 1
          STN_ENABLE equ 2
          STN_DISABLE equ 3
        endif
        STM_MSGMAX equ 0174h
      endif
      WC_DIALOG equ (MAKEINTATOM(8002h))
      DWL_MSGRESULT equ 0
      DWL_DLGPROC equ 4
      DWL_USER equ 8
      ifdef _WIN64
      endif
      DWLP_MSGRESULT equ 0
      DWLP_DLGPROC equ <DWLP_MSGRESULT + sizeof(LRESULT)>
      DWLP_USER equ <DWLP_DLGPROC + sizeof(DLGPROC)>
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        ifndef NOMSG
          @DefProto DllImport, IsDialogMessageA, WIN_STD_CALL_CONV,, <:HWND, :LPMSG>, 8
          @DefProto DllImport, IsDialogMessageW, WIN_STD_CALL_CONV,, <:HWND, :LPMSG>, 8
          ifdef UNICODE
            IsDialogMessage equ <IsDialogMessageW>
          else
            IsDialogMessage equ <IsDialogMessageA>
          endif
        endif
        @DefProto DllImport, MapDialogRect, WIN_STD_CALL_CONV,, <:HWND, :LPRECT>, 8
        @DefProto DllImport, DlgDirListA, WIN_STD_CALL_CONV,, <:HWND, :LPSTR, :SDWORD, :SDWORD, :UINT>, 20
        @DefProto DllImport, DlgDirListW, WIN_STD_CALL_CONV,, <:HWND, :LPWSTR, :SDWORD, :SDWORD, :UINT>, 20
        ifdef UNICODE
          DlgDirList equ <DlgDirListW>
        else
          DlgDirList equ <DlgDirListA>
        endif
      endif
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
        @DefProto DllImport, DlgDirListComboBoxA, WIN_STD_CALL_CONV,, <:HWND, :LPSTR, :SDWORD, :SDWORD, :UINT>, 20
        @DefProto DllImport, DlgDirListComboBoxW, WIN_STD_CALL_CONV,, <:HWND, :LPWSTR, :SDWORD, :SDWORD, :UINT>, 20
        ifdef UNICODE
          DlgDirListComboBox equ <DlgDirListComboBoxW>
        else
          DlgDirListComboBox equ <DlgDirListComboBoxA>
        endif
        @DefProto DllImport, DlgDirSelectComboBoxExA, WIN_STD_CALL_CONV,, <:HWND, :LPSTR, :SDWORD, :SDWORD>, 16
        @DefProto DllImport, DlgDirSelectComboBoxExW, WIN_STD_CALL_CONV,, <:HWND, :LPWSTR, :SDWORD, :SDWORD>, 16
        ifdef UNICODE
          DlgDirSelectComboBoxEx equ <DlgDirSelectComboBoxExW>
        else
          DlgDirSelectComboBoxEx equ <DlgDirSelectComboBoxExA>
        endif
      endif
      DS_ABSALIGN equ 01h
      DS_SYSMODAL equ 02h
      DS_LOCALEDIT equ 20h
      DS_SETFONT equ 40h
      DS_MODALFRAME equ 80h
      DS_NOIDLEMSG equ 100h
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
      endif
      if Defined(_WIN32_WCE) and (_WIN32_WCE ge 0500h)
        DS_USEPIXELS equ 8000h
      endif
      DM_GETDEFID equ (WM_USER + 0)
      DM_SETDEFID equ (WM_USER + 1)
      if (WINVER ge 0400h)
        DM_REPOSITION equ (WM_USER + 2)
      endif
      DC_HASDEFID equ 534Bh
      DLGC_WANTARROWS equ 0001h
      DLGC_WANTTAB equ 0002h
      DLGC_WANTALLKEYS equ 0004h
      DLGC_WANTMESSAGE equ 0004h
      DLGC_HASSETSEL equ 0008h
      DLGC_DEFPUSHBUTTON equ 0010h
      DLGC_UNDEFPUSHBUTTON equ 0020h
      DLGC_RADIOBUTTON equ 0040h
      DLGC_WANTCHARS equ 0080h
      DLGC_STATIC equ 0100h
      DLGC_BUTTON equ 2000h
      LB_CTLCODE equ 0
      LB_OKAY equ 0
      LB_ERR equ (- 1)
      LB_ERRSPACE equ (- 2)
      LBN_ERRSPACE equ (- 2)
      LBN_SELCHANGE equ 1
      LBN_DBLCLK equ 2
      LBN_SELCANCEL equ 3
      LBN_SETFOCUS equ 4
      LBN_KILLFOCUS equ 5
      ifndef NOWINMESSAGES
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
        endif
        if Defined(_WIN32_WCE) and (_WIN32_WCE ge 0400h)
          LB_MULTIPLEADDSTRING equ 01B1h
        endif
        if (_WIN32_WINNT ge 0501h)
          LB_GETLISTBOXINFO equ 01B2h
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
      endif
      ifndef NOWINSTYLES
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
        endif
        LBS_COMBOBOX equ 8000h
        LBS_STANDARD equ <(LBS_NOTIFY or LBS_SORT or WS_VSCROLL or WS_BORDER)>
      endif
      CB_OKAY equ 0
      CB_ERR equ (- 1)
      CB_ERRSPACE equ (- 2)
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
        endif
      endif
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
        endif
        if (_WIN32_WINNT ge 0501h)
          CB_GETCOMBOBOXINFO equ 0164h
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
      endif
      ifndef NOWINSTYLES
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
        endif
      endif
      ifndef NOWINMESSAGES
        SBM_SETPOS equ 00E0h
        SBM_GETPOS equ 00E1h
        SBM_SETRANGE equ 00E2h
        SBM_SETRANGEREDRAW equ 00E6h
        SBM_GETRANGE equ 00E3h
        SBM_ENABLE_ARROWS equ 00E4h
        if (WINVER ge 0400h)
          SBM_SETSCROLLINFO equ 00E9h
          SBM_GETSCROLLINFO equ 00EAh
        endif
        if (_WIN32_WINNT ge 0501h)
          SBM_GETSCROLLBARINFO equ 00EBh
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
              cbSize UINT ?
              fMask UINT ?
              nMin SDWORD ?
              nMax SDWORD ?
              nPage UINT ?
              nPos SDWORD ?
              nTrackPos SDWORD ?
            SCROLLINFO ends
            tagSCROLLINFO typedef SCROLLINFO
            LPSCROLLINFO typedef ptr SCROLLINFO
            LPCSCROLLINFO typedef ptr SCROLLINFO
            @DefProto DllImport, SetScrollInfo, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LPCSCROLLINFO, :BOOL>, 16
            @DefProto DllImport, GetScrollInfo, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LPSCROLLINFO>, 12
          endif
        endif
      endif
    endif
    ifndef NOMDI
      MDIS_ALLCHILDSTYLES equ 0001h
      MDITILE_VERTICAL equ 0000h
      MDITILE_HORIZONTAL equ 0001h
      MDITILE_SKIPDISABLED equ 0002h
      if (_WIN32_WINNT ge 0500h)
        MDITILE_ZORDER equ 0004h
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        MDICREATESTRUCTA struct
          szClass LPCSTR ?
          szTitle LPCSTR ?
          hOwner HANDLE ?
          x SDWORD ?
          y SDWORD ?
          cx_ SDWORD ?
          cy SDWORD ?
          style DWORD ?
          lParam LPARAM ?
        MDICREATESTRUCTA ends
        tagMDICREATESTRUCTA typedef MDICREATESTRUCTA
        LPMDICREATESTRUCTA typedef ptr MDICREATESTRUCTA
        MDICREATESTRUCTW struct
          szClass LPCWSTR ?
          szTitle LPCWSTR ?
          hOwner HANDLE ?
          x SDWORD ?
          y SDWORD ?
          cx_ SDWORD ?
          cy SDWORD ?
          style DWORD ?
          lParam LPARAM ?
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
        CLIENTCREATESTRUCT struct
          hWindowMenu HANDLE ?
          idFirstChild UINT ?
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
        ifndef NOMSG
          @DefProto DllImport, TranslateMDISysAccel, WIN_STD_CALL_CONV,, <:HWND, :LPMSG>, 8
        endif
        @DefProto DllImport, ArrangeIconicWindows, WIN_STD_CALL_CONV,, <:HWND>, 4
        @DefProto DllImport, CreateMDIWindowA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPCSTR, :DWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :HWND, :HINSTANCE, :LPARAM>, 40
        @DefProto DllImport, CreateMDIWindowW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :DWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :HWND, :HINSTANCE, :LPARAM>, 40
        ifdef UNICODE
          CreateMDIWindow equ <CreateMDIWindowW>
        else
          CreateMDIWindow equ <CreateMDIWindowA>
        endif
        if (WINVER ge 0400h)
          @DefProto DllImport, TileWindows, WIN_STD_CALL_CONV,, <:HWND, :UINT, :ptr RECT, :UINT, :ptr HWND>, 20
          @DefProto DllImport, CascadeWindows, WIN_STD_CALL_CONV,, <:HWND, :UINT, :ptr RECT, :UINT, :ptr HWND>, 20
        endif
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef NOHELP
      HELPPOLY typedef DWORD
      MULTIKEYHELPA struct
        ifndef _MAC
          mkSize DWORD ?
        else
          ;[...]
        endif
        mkKeylist CHAR ?
        szKeyphrase CHAR 1 dup (?)
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
        mkKeylist WCHAR ?
        szKeyphrase WCHAR 1 dup (?)
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
      HELPWININFOA struct
        wStructSize SDWORD ?
        x SDWORD ?
        y SDWORD ?
        dx_ SDWORD ?
        dy SDWORD ?
        wMax SDWORD ?
        rgchMember CHAR 2 dup (?)
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
        rgchMember WCHAR 2 dup (?)
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
      HELP_CONTEXT equ 0001h
      HELP_QUIT equ 0002h
      HELP_INDEX equ 0003h
      HELP_CONTENTS equ 0003h
      HELP_HELPONHELP equ 0004h
      HELP_SETINDEX equ 0005h
      HELP_SETCONTENTS equ 0005h
      HELP_CONTEXTPOPUP equ 0008h
      HELP_FORCEFILE equ 0009h
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
        IDH_NO_HELP equ 28440
        IDH_MISSING_CONTEXT equ 28441
        IDH_GENERIC_HELP_BUTTON equ 28442
        IDH_OK equ 28443
        IDH_CANCEL equ 28444
        IDH_HELP equ 28445
      endif
      @DefProto DllImport, WinHelpA, WIN_STD_CALL_CONV,, <:HWND, :LPCSTR, :UINT, :ULONG_PTR>, 16
      @DefProto DllImport, WinHelpW, WIN_STD_CALL_CONV,, <:HWND, :LPCWSTR, :UINT, :ULONG_PTR>, 16
      ifdef UNICODE
        WinHelp equ <WinHelpW>
      else
        WinHelp equ <WinHelpA>
      endif
    endif
  endif
  if (WINVER ge 0500h)
    GR_GDIOBJECTS equ 0
    GR_USEROBJECTS equ 1
  endif
  if (WINVER ge 0601h)
    GR_GDIOBJECTS_PEAK equ 2
    GR_USEROBJECTS_PEAK equ 4
  endif
  if (WINVER ge 0601h)
    GR_GLOBAL equ (- 2)
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if (WINVER ge 0500h)
      @DefProto DllImport, GetGuiResources, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD>, 8
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
  endif
  ifndef NOSYSPARAMSINFO
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
    endif
    SPI_GETSOUNDSENTRY equ 0040h
    SPI_SETSOUNDSENTRY equ 0041h
    if (_WIN32_WINNT ge 0400h)
      SPI_GETSNAPTODEFBUTTON equ 005Fh
      SPI_SETSNAPTODEFBUTTON equ 0060h
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
    endif
    if (WINVER ge 0600h)
      SPI_GETAUDIODESCRIPTION equ 0074h
      SPI_SETAUDIODESCRIPTION equ 0075h
      SPI_GETSCREENSAVESECURE equ 0076h
      SPI_SETSCREENSAVESECURE equ 0077h
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
    endif
    if (WINVER ge 0602h)
      MAX_TOUCH_PREDICTION_FILTER_TAPS equ 3
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        TOUCHPREDICTIONPARAMETERS struct
          cbSize UINT ?
          dwLatency UINT ?
          dwSampleTime UINT ?
          bUseHWTimeStamp UINT ?
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
      endif
      SPI_GETTOUCHPREDICTIONPARAMETERS equ 009Ch
      SPI_SETTOUCHPREDICTIONPARAMETERS equ 009Dh
      MAX_LOGICALDPIOVERRIDE equ 2
      MIN_LOGICALDPIOVERRIDE equ -2
      SPI_GETLOGICALDPIOVERRIDE equ 009Eh
      SPI_SETLOGICALDPIOVERRIDE equ 009Fh
      SPI_GETMENURECT equ 00A2h
      SPI_SETMENURECT equ 00A3h
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_19H1)
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_CO)
    endif
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
      endif
      if (WINVER ge 0601h)
        SPI_GETCARETBROWSING equ 104Ch
        SPI_SETCARETBROWSING equ 104Dh
        SPI_GETTHREADLOCALINPUTSETTINGS equ 104Eh
        SPI_SETTHREADLOCALINPUTSETTINGS equ 104Fh
        SPI_GETSYSTEMLANGUAGEBAR equ 1050h
        SPI_SETSYSTEMLANGUAGEBAR equ 1051h
      endif
      if (NTDDI_VERSION ge NTDDI_WIN10_RS3)
      endif
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
        FE_FONTSMOOTHINGORIENTATIONBGR equ 0000h
        FE_FONTSMOOTHINGORIENTATIONRGB equ 0001h
      endif
      if (_WIN32_WINNT ge 0600h)
        SPI_GETMINIMUMHITRADIUS equ 2014h
        SPI_SETMINIMUMHITRADIUS equ 2015h
        SPI_GETMESSAGEDURATION equ 2016h
        SPI_SETMESSAGEDURATION equ 2017h
      endif
      if (WINVER ge 0602h)
        SPI_GETCONTACTVISUALIZATION equ 2018h
        SPI_SETCONTACTVISUALIZATION equ 2019h
        CONTACTVISUALIZATION_OFF equ 0000h
        CONTACTVISUALIZATION_ON equ 0001h
        CONTACTVISUALIZATION_PRESENTATIONMODE equ 0002h
        SPI_GETGESTUREVISUALIZATION equ 201Ah
        SPI_SETGESTUREVISUALIZATION equ 201Bh
        GESTUREVISUALIZATION_OFF equ 0000h
        GESTUREVISUALIZATION_ON equ 001Fh
        GESTUREVISUALIZATION_TAP equ 0001h
        GESTUREVISUALIZATION_DOUBLETAP equ 0002h
        GESTUREVISUALIZATION_PRESSANDTAP equ 0004h
        GESTUREVISUALIZATION_PRESSANDHOLD equ 0008h
        GESTUREVISUALIZATION_RIGHTTAP equ 0010h
      endif
      if (WINVER ge 0602h)
        SPI_GETMOUSEWHEELROUTING equ 201Ch
        SPI_SETMOUSEWHEELROUTING equ 201Dh
        MOUSEWHEEL_ROUTING_FOCUS equ 0
        MOUSEWHEEL_ROUTING_HYBRID equ 1
        if (WINVER ge 0603h)
          MOUSEWHEEL_ROUTING_MOUSE_POS equ 2
        endif
      endif
      if (WINVER ge 0604h)
        SPI_GETPENVISUALIZATION equ 201Eh
        SPI_SETPENVISUALIZATION equ 201Fh
        PENVISUALIZATION_ON equ 0023h
        PENVISUALIZATION_OFF equ 0000h
        PENVISUALIZATION_TAP equ 0001h
        PENVISUALIZATION_DOUBLETAP equ 0002h
        PENVISUALIZATION_CURSOR equ 0020h
        SPI_GETPENARBITRATIONTYPE equ 2020h
        SPI_SETPENARBITRATIONTYPE equ 2021h
        PENARBITRATIONTYPE_NONE equ 0000h
        PENARBITRATIONTYPE_WIN8 equ 0001h
        PENARBITRATIONTYPE_FIS equ 0002h
        PENARBITRATIONTYPE_SPT equ 0003h
        PENARBITRATIONTYPE_MAX equ 0004h
      endif
      if (NTDDI_VERSION ge NTDDI_WIN10_RS3)
        SPI_GETCARETTIMEOUT equ 2022h
        SPI_SETCARETTIMEOUT equ 2023h
      endif
      if (NTDDI_VERSION ge NTDDI_WIN10_RS4)
        SPI_GETHANDEDNESS equ 2024h
        SPI_SETHANDEDNESS equ 2025h
        HANDEDNESS typedef SDWORD
        HANDEDNESS_LEFT equ 0
        HANDEDNESS_RIGHT equ 1
        tagHANDEDNESS typedef HANDEDNESS
        PHANDEDNESS typedef ptr HANDEDNESS
      endif
    endif
    SPIF_UPDATEINIFILE equ 0001h
    SPIF_SENDWININICHANGE equ 0002h
    SPIF_SENDCHANGE equ <SPIF_SENDWININICHANGE>
    METRICS_USEDEFAULT equ -1
    ifdef _WINGDI_
      ifndef NOGDI
        if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
          NONCLIENTMETRICSA struct
            cbSize UINT ?
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
            endif
          NONCLIENTMETRICSA ends
          tagNONCLIENTMETRICSA typedef NONCLIENTMETRICSA
          PNONCLIENTMETRICSA typedef ptr NONCLIENTMETRICSA
          LPNONCLIENTMETRICSA typedef ptr NONCLIENTMETRICSA
          NONCLIENTMETRICSW struct
            cbSize UINT ?
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
        endif
      endif
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
        cbSize UINT ?
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
            cbSize UINT ?
            iHorzSpacing SDWORD ?
            iVertSpacing SDWORD ?
            iTitleWrap SDWORD ?
            lfFont LOGFONTA <>
          ICONMETRICSA ends
          tagICONMETRICSA typedef ICONMETRICSA
          PICONMETRICSA typedef ptr ICONMETRICSA
          LPICONMETRICSA typedef ptr ICONMETRICSA
          ICONMETRICSW struct
            cbSize UINT ?
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
        endif
      endif
      ANIMATIONINFO struct
        cbSize UINT ?
        iMinAnimate SDWORD ?
      ANIMATIONINFO ends
      tagANIMATIONINFO typedef ANIMATIONINFO
      LPANIMATIONINFO typedef ptr ANIMATIONINFO
      SERIALKEYSA struct
        cbSize UINT ?
        dwFlags DWORD ?
        lpszActivePort LPSTR ?
        lpszPort LPSTR ?
        iBaudRate UINT ?
        iPortState UINT ?
        iActive UINT ?
      SERIALKEYSA ends
      tagSERIALKEYSA typedef SERIALKEYSA
      LPSERIALKEYSA typedef ptr SERIALKEYSA
      SERIALKEYSW struct
        cbSize UINT ?
        dwFlags DWORD ?
        lpszActivePort LPWSTR ?
        lpszPort LPWSTR ?
        iBaudRate UINT ?
        iPortState UINT ?
        iActive UINT ?
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
      SERKF_SERIALKEYSON equ 00000001h
      SERKF_AVAILABLE equ 00000002h
      SERKF_INDICATOR equ 00000004h
      HIGHCONTRASTA struct
        cbSize UINT ?
        dwFlags DWORD ?
        lpszDefaultScheme LPSTR ?
      HIGHCONTRASTA ends
      tagHIGHCONTRASTA typedef HIGHCONTRASTA
      LPHIGHCONTRASTA typedef ptr HIGHCONTRASTA
      HIGHCONTRASTW struct
        cbSize UINT ?
        dwFlags DWORD ?
        lpszDefaultScheme LPWSTR ?
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
    endif
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
    CDS_UPDATEREGISTRY equ 00000001h
    CDS_TEST equ 00000002h
    CDS_FULLSCREEN equ 00000004h
    CDS_GLOBAL equ 00000008h
    CDS_SET_PRIMARY equ 00000010h
    CDS_VIDEOPARAMETERS equ 00000020h
    if (WINVER ge 0600h)
      CDS_ENABLE_UNSAFE_MODES equ 00000100h
      CDS_DISABLE_UNSAFE_MODES equ 00000200h
    endif
    CDS_RESET equ 40000000h
    CDS_RESET_EX equ 20000000h
    CDS_NORESET equ 10000000h
    include tvout.inc
    DISP_CHANGE_SUCCESSFUL equ 0
    DISP_CHANGE_RESTART equ 1
    DISP_CHANGE_FAILED equ -1
    DISP_CHANGE_BADMODE equ -2
    DISP_CHANGE_NOTUPDATED equ -3
    DISP_CHANGE_BADFLAGS equ -4
    DISP_CHANGE_BADPARAM equ -5
    if (_WIN32_WINNT ge 0501h)
      DISP_CHANGE_BADDUALVIEW equ -6
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
          @DefProto DllImport, ChangeDisplaySettingsExA, WIN_STD_CALL_CONV,, <:LPCSTR, :ptr DEVMODEA, :HWND, :DWORD, :LPVOID>, 20
          @DefProto DllImport, ChangeDisplaySettingsExW, WIN_STD_CALL_CONV,, <:LPCWSTR, :ptr DEVMODEW, :HWND, :DWORD, :LPVOID>, 20
          ifdef UNICODE
            ChangeDisplaySettingsEx equ <ChangeDisplaySettingsExW>
          else
            ChangeDisplaySettingsEx equ <ChangeDisplaySettingsExA>
          endif
          ENUM_CURRENT_SETTINGS equ (- 1)
          ENUM_REGISTRY_SETTINGS equ (- 2)
          @DefProto DllImport, EnumDisplaySettingsA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :ptr DEVMODEA>, 12
          @DefProto DllImport, EnumDisplaySettingsW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :ptr DEVMODEW>, 12
          ifdef UNICODE
            EnumDisplaySettings equ <EnumDisplaySettingsW>
          else
            EnumDisplaySettings equ <EnumDisplaySettingsA>
          endif
          if (WINVER ge 0500h)
            @DefProto DllImport, EnumDisplaySettingsExA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :ptr DEVMODEA, :DWORD>, 16
            @DefProto DllImport, EnumDisplaySettingsExW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :ptr DEVMODEW, :DWORD>, 16
            ifdef UNICODE
              EnumDisplaySettingsEx equ <EnumDisplaySettingsExW>
            else
              EnumDisplaySettingsEx equ <EnumDisplaySettingsExA>
            endif
            EDS_RAWMODE equ 00000002h
            EDS_ROTATEDMODE equ 00000004h
            @DefProto DllImport, EnumDisplayDevicesA, WIN_STD_CALL_CONV,, <:LPCSTR, :DWORD, :PDISPLAY_DEVICEA, :DWORD>, 16
            @DefProto DllImport, EnumDisplayDevicesW, WIN_STD_CALL_CONV,, <:LPCWSTR, :DWORD, :PDISPLAY_DEVICEW, :DWORD>, 16
            ifdef UNICODE
              EnumDisplayDevices equ <EnumDisplayDevicesW>
            else
              EnumDisplayDevices equ <EnumDisplayDevicesA>
            endif
            EDD_GET_DEVICE_INTERFACE_NAME equ 00000001h
          endif
          if (WINVER ge 0601h)
            @DefProto DllImport, GetDisplayConfigBufferSizes, WIN_STD_CALL_CONV,, <:UINT32, :ptr UINT32, :ptr UINT32>, 12
            @DefProto DllImport, SetDisplayConfig, WIN_STD_CALL_CONV,, <:UINT32, :ptr DISPLAYCONFIG_PATH_INFO, :UINT32, :ptr DISPLAYCONFIG_MODE_INFO, :UINT32>, 20
            @DefProto DllImport, QueryDisplayConfig, WIN_STD_CALL_CONV,, <:UINT32, :ptr UINT32, :ptr DISPLAYCONFIG_PATH_INFO, :ptr UINT32, :ptr DISPLAYCONFIG_MODE_INFO, :ptr DISPLAYCONFIG_TOPOLOGY_ID>, 24
            @DefProto DllImport, DisplayConfigGetDeviceInfo, WIN_STD_CALL_CONV,, <:ptr DISPLAYCONFIG_DEVICE_INFO_HEADER>, 4
            @DefProto DllImport, DisplayConfigSetDeviceInfo, WIN_STD_CALL_CONV,, <:ptr DISPLAYCONFIG_DEVICE_INFO_HEADER>, 4
          endif
        endif
      endif
      @DefProto DllImport, SystemParametersInfoA, WIN_STD_CALL_CONV,, <:UINT, :UINT, :PVOID, :UINT>, 16
      @DefProto DllImport, SystemParametersInfoW, WIN_STD_CALL_CONV,, <:UINT, :UINT, :PVOID, :UINT>, 16
      ifdef UNICODE
        SystemParametersInfo equ <SystemParametersInfoW>
      else
        SystemParametersInfo equ <SystemParametersInfoA>
      endif
      if (WINVER ge 0605h)
        @DefProto DllImport, SystemParametersInfoForDpi, WIN_STD_CALL_CONV,, <:UINT, :UINT, :PVOID, :UINT, :UINT>, 20
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    FILTERKEYS struct
      cbSize UINT ?
      dwFlags DWORD ?
      iWaitMSec DWORD ?
      iDelayMSec DWORD ?
      iRepeatMSec DWORD ?
      iBounceMSec DWORD ?
    FILTERKEYS ends
    tagFILTERKEYS typedef FILTERKEYS
    LPFILTERKEYS typedef ptr FILTERKEYS
  endif
  FKF_FILTERKEYSON equ 00000001h
  FKF_AVAILABLE equ 00000002h
  FKF_HOTKEYACTIVE equ 00000004h
  FKF_CONFIRMHOTKEY equ 00000008h
  FKF_HOTKEYSOUND equ 00000010h
  FKF_INDICATOR equ 00000020h
  FKF_CLICKON equ 00000040h
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    STICKYKEYS struct
      cbSize UINT ?
      dwFlags DWORD ?
    STICKYKEYS ends
    tagSTICKYKEYS typedef STICKYKEYS
    LPSTICKYKEYS typedef ptr STICKYKEYS
  endif
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
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    MOUSEKEYS struct
      cbSize UINT ?
      dwFlags DWORD ?
      iMaxSpeed DWORD ?
      iTimeToMaxSpeed DWORD ?
      iCtrlSpeed DWORD ?
      dwReserved1 DWORD ?
      dwReserved2 DWORD ?
    MOUSEKEYS ends
    tagMOUSEKEYS typedef MOUSEKEYS
    LPMOUSEKEYS typedef ptr MOUSEKEYS
  endif
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
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ACCESSTIMEOUT struct
      cbSize UINT ?
      dwFlags DWORD ?
      iTimeOutMSec DWORD ?
    ACCESSTIMEOUT ends
    tagACCESSTIMEOUT typedef ACCESSTIMEOUT
    LPACCESSTIMEOUT typedef ptr ACCESSTIMEOUT
  endif
  ATF_TIMEOUTON equ 00000001h
  ATF_ONOFFFEEDBACK equ 00000002h
  SSGF_NONE equ 0
  SSGF_DISPLAY equ 3
  SSTF_NONE equ 0
  SSTF_CHARS equ 1
  SSTF_BORDER equ 2
  SSTF_DISPLAY equ 3
  SSWF_NONE equ 0
  SSWF_TITLE equ 1
  SSWF_WINDOW equ 2
  SSWF_DISPLAY equ 3
  SSWF_CUSTOM equ 4
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    SOUNDSENTRYA struct
      cbSize UINT ?
      dwFlags DWORD ?
      iFSTextEffect DWORD ?
      iFSTextEffectMSec DWORD ?
      iFSTextEffectColorBits DWORD ?
      iFSGrafEffect DWORD ?
      iFSGrafEffectMSec DWORD ?
      iFSGrafEffectColor DWORD ?
      iWindowsEffect DWORD ?
      iWindowsEffectMSec DWORD ?
      lpszWindowsEffectDLL LPSTR ?
      iWindowsEffectOrdinal DWORD ?
    SOUNDSENTRYA ends
    tagSOUNDSENTRYA typedef SOUNDSENTRYA
    LPSOUNDSENTRYA typedef ptr SOUNDSENTRYA
    SOUNDSENTRYW struct
      cbSize UINT ?
      dwFlags DWORD ?
      iFSTextEffect DWORD ?
      iFSTextEffectMSec DWORD ?
      iFSTextEffectColorBits DWORD ?
      iFSGrafEffect DWORD ?
      iFSGrafEffectMSec DWORD ?
      iFSGrafEffectColor DWORD ?
      iWindowsEffect DWORD ?
      iWindowsEffectMSec DWORD ?
      lpszWindowsEffectDLL LPWSTR ?
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
  endif
  SSF_SOUNDSENTRYON equ 00000001h
  SSF_AVAILABLE equ 00000002h
  SSF_INDICATOR equ 00000004h
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_PC_APP)
    if (_WIN32_WINNT ge 0600h)
      @DefProto DllImport, SoundSentry, WIN_STD_CALL_CONV,, <>, 0
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    TOGGLEKEYS struct
      cbSize UINT ?
      dwFlags DWORD ?
    TOGGLEKEYS ends
    tagTOGGLEKEYS typedef TOGGLEKEYS
    LPTOGGLEKEYS typedef ptr TOGGLEKEYS
  endif
  TKF_TOGGLEKEYSON equ 00000001h
  TKF_AVAILABLE equ 00000002h
  TKF_HOTKEYACTIVE equ 00000004h
  TKF_CONFIRMHOTKEY equ 00000008h
  TKF_HOTKEYSOUND equ 00000010h
  TKF_INDICATOR equ 00000020h
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if (_WIN32_WINNT ge 0600h)
      AUDIODESCRIPTION struct
        cbSize UINT ?
        Enabled BOOL ?
        Locale LCID ?
      AUDIODESCRIPTION ends
      tagAUDIODESCRIPTION typedef AUDIODESCRIPTION
      LPAUDIODESCRIPTION typedef ptr AUDIODESCRIPTION
    endif
    @DefProto DllImport, SetDebugErrorLevel, WIN_STD_CALL_CONV,, <:DWORD>, 4
  endif
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
  endif
  if (WINVER ge 0500h)
    MONITOR_DEFAULTTONULL equ 00000000h
    MONITOR_DEFAULTTOPRIMARY equ 00000001h
    MONITOR_DEFAULTTONEAREST equ 00000002h
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, MonitorFromPoint, WIN_STD_CALL_CONV,, <:POINT, :DWORD>, 8
      @DefProto DllImport, MonitorFromRect, WIN_STD_CALL_CONV,, <:LPCRECT, :DWORD>, 8
      @DefProto DllImport, MonitorFromWindow, WIN_STD_CALL_CONV,, <:HWND, :DWORD>, 8
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
      else
        MONITORINFOEXA struct
          DUMMYSTRUCTNAME MONITORINFO <>
          szDevice CHAR CCHDEVICENAME dup (?)
        MONITORINFOEXA ends
        tagMONITORINFOEXA typedef MONITORINFOEXA
        LPMONITORINFOEXA typedef ptr MONITORINFOEXA
        MONITORINFOEXW struct
          DUMMYSTRUCTNAME MONITORINFO <>
          szDevice WCHAR CCHDEVICENAME dup (?)
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
      endif
      @DefProto DllImport, GetMonitorInfoA, WIN_STD_CALL_CONV,, <:HMONITOR, :LPMONITORINFO>, 8
      @DefProto DllImport, GetMonitorInfoW, WIN_STD_CALL_CONV,, <:HMONITOR, :LPMONITORINFO>, 8
      ifdef UNICODE
        GetMonitorInfo equ <GetMonitorInfoW>
      else
        GetMonitorInfo equ <GetMonitorInfoA>
      endif
      TYPE_MONITORENUMPROC typedef proto WIN_STD_CALL_CONV :HMONITOR, :HDC, :LPRECT, :LPARAM
      MONITORENUMPROC typedef ptr TYPE_MONITORENUMPROC

      @DefProto DllImport, EnumDisplayMonitors, WIN_STD_CALL_CONV,, <:HDC, :LPCRECT, :MONITORENUMPROC, :LPARAM>, 16
    endif
    ifndef NOWINABLE
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, NotifyWinEvent, WIN_STD_CALL_CONV,, <:DWORD, :HWND, :LONG, :LONG>, 16
        TYPE_WINEVENTPROC typedef proto WIN_STD_CALL_CONV :HWINEVENTHOOK, :DWORD, :HWND, :LONG, :LONG, :DWORD, :DWORD
        WINEVENTPROC typedef ptr TYPE_WINEVENTPROC

        @DefProto DllImport, SetWinEventHook, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :HMODULE, :WINEVENTPROC, :DWORD, :DWORD, :DWORD>, 28
        if (_WIN32_WINNT ge 0501h)
          @DefProto DllImport, IsWinEventHookInstalled, WIN_STD_CALL_CONV,, <:DWORD>, 4
        endif
      endif
      WINEVENT_OUTOFCONTEXT equ 0000h
      WINEVENT_SKIPOWNTHREAD equ 0001h
      WINEVENT_SKIPOWNPROCESS equ 0002h
      WINEVENT_INCONTEXT equ 0004h
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, UnhookWinEvent, WIN_STD_CALL_CONV,, <:HWINEVENTHOOK>, 4
      endif
      CHILDID_SELF equ 0
      INDEXID_OBJECT equ 0
      INDEXID_CONTAINER equ 0
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
      EVENT_MIN equ 00000001h
      EVENT_MAX equ 7FFFFFFFh
      EVENT_SYSTEM_SOUND equ 0001h
      EVENT_SYSTEM_ALERT equ 0002h
      EVENT_SYSTEM_FOREGROUND equ 0003h
      EVENT_SYSTEM_MENUSTART equ 0004h
      EVENT_SYSTEM_MENUEND equ 0005h
      EVENT_SYSTEM_MENUPOPUPSTART equ 0006h
      EVENT_SYSTEM_MENUPOPUPEND equ 0007h
      EVENT_SYSTEM_CAPTURESTART equ 0008h
      EVENT_SYSTEM_CAPTUREEND equ 0009h
      EVENT_SYSTEM_MOVESIZESTART equ 000Ah
      EVENT_SYSTEM_MOVESIZEEND equ 000Bh
      EVENT_SYSTEM_CONTEXTHELPSTART equ 000Ch
      EVENT_SYSTEM_CONTEXTHELPEND equ 000Dh
      EVENT_SYSTEM_DRAGDROPSTART equ 000Eh
      EVENT_SYSTEM_DRAGDROPEND equ 000Fh
      EVENT_SYSTEM_DIALOGSTART equ 0010h
      EVENT_SYSTEM_DIALOGEND equ 0011h
      EVENT_SYSTEM_SCROLLINGSTART equ 0012h
      EVENT_SYSTEM_SCROLLINGEND equ 0013h
      EVENT_SYSTEM_SWITCHSTART equ 0014h
      EVENT_SYSTEM_SWITCHEND equ 0015h
      EVENT_SYSTEM_MINIMIZESTART equ 0016h
      EVENT_SYSTEM_MINIMIZEEND equ 0017h
      if (_WIN32_WINNT ge 0600h)
        EVENT_SYSTEM_DESKTOPSWITCH equ 0020h
      endif
      if (_WIN32_WINNT ge 0602h)
        EVENT_SYSTEM_SWITCHER_APPGRABBED equ 0024h
        EVENT_SYSTEM_SWITCHER_APPOVERTARGET equ 0025h
        EVENT_SYSTEM_SWITCHER_APPDROPPED equ 0026h
        EVENT_SYSTEM_SWITCHER_CANCELLED equ 0027h
      endif
      if (_WIN32_WINNT ge 0602h)
        EVENT_SYSTEM_IME_KEY_NOTIFICATION equ 0029h
      endif
      if (_WIN32_WINNT ge 0601h)
        EVENT_SYSTEM_END equ 00FFh
        EVENT_OEM_DEFINED_START equ 0101h
        EVENT_OEM_DEFINED_END equ 01FFh
        EVENT_UIA_EVENTID_START equ 4E00h
        EVENT_UIA_EVENTID_END equ 4EFFh
        EVENT_UIA_PROPID_START equ 7500h
        EVENT_UIA_PROPID_END equ 75FFh
      endif
      if (_WIN32_WINNT ge 0501h)
        EVENT_CONSOLE_CARET equ 4001h
        EVENT_CONSOLE_UPDATE_REGION equ 4002h
        EVENT_CONSOLE_UPDATE_SIMPLE equ 4003h
        EVENT_CONSOLE_UPDATE_SCROLL equ 4004h
        EVENT_CONSOLE_LAYOUT equ 4005h
        EVENT_CONSOLE_START_APPLICATION equ 4006h
        EVENT_CONSOLE_END_APPLICATION equ 4007h
        if Defined(_WIN64)
          CONSOLE_APPLICATION_16BIT equ 0000h
        else
          CONSOLE_APPLICATION_16BIT equ 0001h
        endif
        CONSOLE_CARET_SELECTION equ 0001h
        CONSOLE_CARET_VISIBLE equ 0002h
      endif
      if (_WIN32_WINNT ge 0601h)
        EVENT_CONSOLE_END equ 40FFh
      endif
      EVENT_OBJECT_CREATE equ 8000h
      EVENT_OBJECT_DESTROY equ 8001h
      EVENT_OBJECT_SHOW equ 8002h
      EVENT_OBJECT_HIDE equ 8003h
      EVENT_OBJECT_REORDER equ 8004h
      EVENT_OBJECT_FOCUS equ 8005h
      EVENT_OBJECT_SELECTION equ 8006h
      EVENT_OBJECT_SELECTIONADD equ 8007h
      EVENT_OBJECT_SELECTIONREMOVE equ 8008h
      EVENT_OBJECT_SELECTIONWITHIN equ 8009h
      EVENT_OBJECT_STATECHANGE equ 800Ah
      EVENT_OBJECT_LOCATIONCHANGE equ 800Bh
      EVENT_OBJECT_NAMECHANGE equ 800Ch
      EVENT_OBJECT_DESCRIPTIONCHANGE equ 800Dh
      EVENT_OBJECT_VALUECHANGE equ 800Eh
      EVENT_OBJECT_PARENTCHANGE equ 800Fh
      EVENT_OBJECT_HELPCHANGE equ 8010h
      EVENT_OBJECT_DEFACTIONCHANGE equ 8011h
      EVENT_OBJECT_ACCELERATORCHANGE equ 8012h
      if (_WIN32_WINNT ge 0600h)
        EVENT_OBJECT_INVOKED equ 8013h
        EVENT_OBJECT_TEXTSELECTIONCHANGED equ 8014h
        EVENT_OBJECT_CONTENTSCROLLED equ 8015h
      endif
      if (_WIN32_WINNT ge 0601h)
        EVENT_SYSTEM_ARRANGMENTPREVIEW equ 8016h
      endif
      if (_WIN32_WINNT ge 0602h)
        EVENT_OBJECT_CLOAKED equ 8017h
        EVENT_OBJECT_UNCLOAKED equ 8018h
        EVENT_OBJECT_LIVEREGIONCHANGED equ 8019h
        EVENT_OBJECT_HOSTEDOBJECTSINVALIDATED equ 8020h
        EVENT_OBJECT_DRAGSTART equ 8021h
        EVENT_OBJECT_DRAGCANCEL equ 8022h
        EVENT_OBJECT_DRAGCOMPLETE equ 8023h
        EVENT_OBJECT_DRAGENTER equ 8024h
        EVENT_OBJECT_DRAGLEAVE equ 8025h
        EVENT_OBJECT_DRAGDROPPED equ 8026h
        EVENT_OBJECT_IME_SHOW equ 8027h
        EVENT_OBJECT_IME_HIDE equ 8028h
        EVENT_OBJECT_IME_CHANGE equ 8029h
        EVENT_OBJECT_TEXTEDIT_CONVERSIONTARGETCHANGED equ 8030h
      endif
      if (_WIN32_WINNT ge 0601h)
        EVENT_OBJECT_END equ 80FFh
        EVENT_AIA_START equ 0A000h
        EVENT_AIA_END equ 0AFFFh
      endif
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
      ALERT_SYSTEM_INFORMATIONAL equ 1
      ALERT_SYSTEM_WARNING equ 2
      ALERT_SYSTEM_ERROR equ 3
      ALERT_SYSTEM_QUERY equ 4
      ALERT_SYSTEM_CRITICAL equ 5
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
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, GetGUIThreadInfo, WIN_STD_CALL_CONV,, <:DWORD, :PGUITHREADINFO>, 8
        @DefProto DllImport, BlockInput, WIN_STD_CALL_CONV,, <:BOOL>, 4
        if (_WIN32_WINNT ge 0600h)
          USER_DEFAULT_SCREEN_DPI equ 96
          @DefProto DllImport, SetProcessDPIAware, WIN_STD_CALL_CONV,, <>, 0
          @DefProto DllImport, IsProcessDPIAware, WIN_STD_CALL_CONV,, <>, 0
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
        endif
        if (WINVER ge 0605h)
          @DefProto DllImport, SetProcessDpiAwarenessContext, WIN_STD_CALL_CONV,, <:DPI_AWARENESS_CONTEXT>, 4
        endif
        if (NTDDI_VERSION ge NTDDI_WIN10_19H1)
          @DefProto DllImport, GetDpiAwarenessContextForProcess, WIN_STD_CALL_CONV,, <:HANDLE>, 4
        endif
        if (WINVER ge 0606h)
          @DefProto DllImport, SetThreadDpiHostingBehavior, WIN_STD_CALL_CONV,, <:DPI_HOSTING_BEHAVIOR>, 4
          @DefProto DllImport, GetThreadDpiHostingBehavior, WIN_STD_CALL_CONV,, <>, 0
          @DefProto DllImport, GetWindowDpiHostingBehavior, WIN_STD_CALL_CONV,, <:HWND>, 4
        endif
        @DefProto DllImport, GetWindowModuleFileNameA, WIN_STD_CALL_CONV,, <:HWND, :LPSTR, :UINT>, 12
        @DefProto DllImport, GetWindowModuleFileNameW, WIN_STD_CALL_CONV,, <:HWND, :LPWSTR, :UINT>, 12
        ifdef UNICODE
          GetWindowModuleFileName equ <GetWindowModuleFileNameW>
        else
          GetWindowModuleFileName equ <GetWindowModuleFileNameA>
        endif
      endif
      ifndef NO_STATE_FLAGS
        STATE_SYSTEM_UNAVAILABLE equ 00000001h
        STATE_SYSTEM_SELECTED equ 00000002h
        STATE_SYSTEM_FOCUSED equ 00000004h
        STATE_SYSTEM_PRESSED equ 00000008h
        STATE_SYSTEM_CHECKED equ 00000010h
        STATE_SYSTEM_MIXED equ 00000020h
        STATE_SYSTEM_INDETERMINATE equ <STATE_SYSTEM_MIXED>
        STATE_SYSTEM_READONLY equ 00000040h
        STATE_SYSTEM_HOTTRACKED equ 00000080h
        STATE_SYSTEM_DEFAULT equ 00000100h
        STATE_SYSTEM_EXPANDED equ 00000200h
        STATE_SYSTEM_COLLAPSED equ 00000400h
        STATE_SYSTEM_BUSY equ 00000800h
        STATE_SYSTEM_FLOATING equ 00001000h
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
        STATE_SYSTEM_MULTISELECTABLE equ 01000000h
        STATE_SYSTEM_EXTSELECTABLE equ 02000000h
        STATE_SYSTEM_ALERT_LOW equ 04000000h
        STATE_SYSTEM_ALERT_MEDIUM equ 08000000h
        STATE_SYSTEM_ALERT_HIGH equ 10000000h
        STATE_SYSTEM_PROTECTED equ 20000000h
        STATE_SYSTEM_VALID equ 3FFFFFFFh
      endif
      CCHILDREN_TITLEBAR equ 5
      CCHILDREN_SCROLLBAR equ 5
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_GAMES)
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
        endif
        @DefProto DllImport, GetCursorInfo, WIN_STD_CALL_CONV,, <:PCURSORINFO>, 4
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        WINDOWINFO struct
          cbSize DWORD ?
          rcWindow RECT <>
          rcClient RECT <>
          dwStyle DWORD ?
          dwExStyle DWORD ?
          dwWindowStatus DWORD ?
          cxWindowBorders UINT ?
          cyWindowBorders UINT ?
          atomWindowType ATOM ?
          wCreatorVersion WORD ?
        WINDOWINFO ends
        tagWINDOWINFO typedef WINDOWINFO
        PWINDOWINFO typedef ptr WINDOWINFO
        LPWINDOWINFO typedef ptr WINDOWINFO
        WS_ACTIVECAPTION equ 0001h
        @DefProto DllImport, GetWindowInfo, WIN_STD_CALL_CONV,, <:HWND, :PWINDOWINFO>, 8
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
        endif
        MENUBARINFO struct
          cbSize DWORD ?
          rcBar RECT <>
          hMenu HMENU ?
          hwndMenu HWND ?
          MENUBARINFO_REC record MENUBARINFO_REC_fUnused:30, MENUBARINFO_REC_fFocused:1, MENUBARINFO_REC_fBarFocused:1
          MENUBARINFO_BITS MENUBARINFO_REC <>
        MENUBARINFO ends
        tagMENUBARINFO typedef MENUBARINFO
        PMENUBARINFO typedef ptr MENUBARINFO
        LPMENUBARINFO typedef ptr MENUBARINFO
        @DefProto DllImport, GetMenuBarInfo, WIN_STD_CALL_CONV,, <:HWND, :LONG, :LONG, :PMENUBARINFO>, 16
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
      endif
      GA_PARENT equ 1
      GA_ROOT equ 2
      GA_ROOTOWNER equ 3
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        @DefProto DllImport, GetAncestor, WIN_STD_CALL_CONV,, <:HWND, :UINT>, 8
        @DefProto DllImport, RealChildWindowFromPoint, WIN_STD_CALL_CONV,, <:HWND, :POINT>, 8
        @DefProto DllImport, RealGetWindowClassA, WIN_STD_CALL_CONV,, <:HWND, :LPSTR, :UINT>, 12
        @DefProto DllImport, RealGetWindowClassW, WIN_STD_CALL_CONV,, <:HWND, :LPWSTR, :UINT>, 12
        ifdef UNICODE
          RealGetWindowClass equ <RealGetWindowClassW>
        else
          RealGetWindowClass equ <RealGetWindowClassA>
        endif
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
        @DefProto DllImport, GetListBoxInfo, WIN_STD_CALL_CONV,, <:HWND>, 4
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if (_WIN32_WINNT ge 0500h)
      @DefProto DllImport, LockWorkStation, WIN_STD_CALL_CONV,, <>, 0
    endif
    if (_WIN32_WINNT ge 0500h)
      @DefProto DllImport, UserHandleGrantAccess, WIN_STD_CALL_CONV,, <:HANDLE, :HANDLE, :BOOL>, 12
    endif
  endif
  if (_WIN32_WINNT ge 0501h)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      DECLARE_HANDLE HRAWINPUT
    endif
    GET_RAWINPUT_CODE_WPARAM macro wParam
      exitm <((wParam) and 0ffh)>
    endm
    RIM_INPUT equ 0
    RIM_INPUTSINK equ 1
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      RAWINPUTHEADER struct
        dwType DWORD ?
        dwSize DWORD ?
        hDevice HANDLE ?
        wParam WPARAM ?
      RAWINPUTHEADER ends
      tagRAWINPUTHEADER typedef RAWINPUTHEADER
      PRAWINPUTHEADER typedef ptr RAWINPUTHEADER
      LPRAWINPUTHEADER typedef ptr RAWINPUTHEADER
    endif
    RIM_TYPEMOUSE equ 0
    RIM_TYPEKEYBOARD equ 1
    RIM_TYPEHID equ 2
    RIM_TYPEMAX equ 2
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      if _MSC_VER ge 1200
      endif
      RAWMOUSE struct
        usFlags USHORT ?
        union
          ulButtons ULONG ?
          struct
            usButtonFlags USHORT ?
            usButtonData USHORT ?
          ends
        ends
        ulRawButtons ULONG ?
        lLastX LONG ?
        lLastY LONG ?
        ulExtraInformation ULONG ?
      RAWMOUSE ends
      tagRAWMOUSE typedef RAWMOUSE
      PRAWMOUSE typedef ptr RAWMOUSE
      LPRAWMOUSE typedef ptr RAWMOUSE
      if _MSC_VER ge 1200
      endif
    endif
    RI_MOUSE_LEFT_BUTTON_DOWN equ 0001h
    RI_MOUSE_LEFT_BUTTON_UP equ 0002h
    RI_MOUSE_RIGHT_BUTTON_DOWN equ 0004h
    RI_MOUSE_RIGHT_BUTTON_UP equ 0008h
    RI_MOUSE_MIDDLE_BUTTON_DOWN equ 0010h
    RI_MOUSE_MIDDLE_BUTTON_UP equ 0020h
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
    RI_MOUSE_WHEEL equ 0400h
    if (WINVER ge 0600h)
      RI_MOUSE_HWHEEL equ 0800h
    endif
    MOUSE_MOVE_RELATIVE equ 0
    MOUSE_MOVE_ABSOLUTE equ 1
    MOUSE_VIRTUAL_DESKTOP equ 02h
    MOUSE_ATTRIBUTES_CHANGED equ 04h
    if (WINVER ge 0600h)
      MOUSE_MOVE_NOCOALESCE equ 08h
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      RAWKEYBOARD struct
        MakeCode USHORT ?
        Flags USHORT ?
        Reserved USHORT ?
        VKey USHORT ?
        Message UINT ?
        ExtraInformation ULONG ?
      RAWKEYBOARD ends
      tagRAWKEYBOARD typedef RAWKEYBOARD
      PRAWKEYBOARD typedef ptr RAWKEYBOARD
      LPRAWKEYBOARD typedef ptr RAWKEYBOARD
    endif
    KEYBOARD_OVERRUN_MAKE_CODE equ 0FFh
    RI_KEY_MAKE equ 0
    RI_KEY_BREAK equ 1
    RI_KEY_E0 equ 2
    RI_KEY_E1 equ 4
    RI_KEY_TERMSRV_SET_LED equ 8
    RI_KEY_TERMSRV_SHADOW equ 10h
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      RAWHID struct
        dwSizeHid DWORD ?
        dwCount DWORD ?
        bRawData BYTE 1 dup (?)
      RAWHID ends
      tagRAWHID typedef RAWHID
      PRAWHID typedef ptr RAWHID
      LPRAWHID typedef ptr RAWHID
    endif
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
    endif
    ifdef _WIN64
      RAWINPUT_ALIGN macro x
        exitm <(((x) + sizeof(QWORD) - 1) and not (sizeof(QWORD) - 1))>
      endm
    else
      RAWINPUT_ALIGN macro x
        exitm <(((x) + sizeof(DWORD) - 1) and not (sizeof(DWORD) - 1))>
      endm
    endif
    NEXTRAWINPUTBLOCK macro ptr_
      exitm <((PRAWINPUT) RAWINPUT_ALIGN(((ptr_) + (ptr_) - header.dwSize)))>
    endm
    RID_INPUT equ 10000003h
    RID_HEADER equ 10000005h
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, GetRawInputData, WIN_STD_CALL_CONV,, <:HRAWINPUT, :UINT, :LPVOID, :PUINT, :UINT>, 20
    endif
    RIDI_PREPARSEDDATA equ 20000005h
    RIDI_DEVICENAME equ 20000007h
    RIDI_DEVICEINFO equ 2000000bh
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      RID_DEVICE_INFO_MOUSE struct
        dwId DWORD ?
        dwNumberOfButtons DWORD ?
        dwSampleRate DWORD ?
        fHasHorizontalWheel BOOL ?
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
        usUsagePage USHORT ?
        usUsage USHORT ?
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
      @DefProto DllImport, GetRawInputBuffer, WIN_STD_CALL_CONV,, <:PRAWINPUT, :PUINT, :UINT>, 12
      RAWINPUTDEVICE struct
        usUsagePage USHORT ?
        usUsage USHORT ?
        dwFlags DWORD ?
        hwndTarget HWND ?
      RAWINPUTDEVICE ends
      tagRAWINPUTDEVICE typedef RAWINPUTDEVICE
      PRAWINPUTDEVICE typedef ptr RAWINPUTDEVICE
      LPRAWINPUTDEVICE typedef ptr RAWINPUTDEVICE
      PCRAWINPUTDEVICE typedef ptr RAWINPUTDEVICE
    endif
    RIDEV_REMOVE equ 00000001h
    RIDEV_EXCLUDE equ 00000010h
    RIDEV_PAGEONLY equ 00000020h
    RIDEV_NOLEGACY equ 00000030h
    RIDEV_INPUTSINK equ 00000100h
    RIDEV_CAPTUREMOUSE equ 00000200h
    RIDEV_NOHOTKEYS equ 00000200h
    RIDEV_APPKEYS equ 00000400h
    if (_WIN32_WINNT ge 0501h)
      RIDEV_EXINPUTSINK equ 00001000h
      RIDEV_DEVNOTIFY equ 00002000h
    endif
    RIDEV_EXMODEMASK equ 000000F0h
    RIDEV_EXMODE macro mode
      exitm <((mode) and RIDEV_EXMODEMASK)>
    endm
    if (_WIN32_WINNT ge 0501h)
      GIDC_ARRIVAL equ 1
      GIDC_REMOVAL equ 2
    endif
    if (_WIN32_WINNT ge 0601h)
      GET_DEVICE_CHANGE_WPARAM macro wParam
        exitm <(LOWORD(wParam))>
      endm
    elseif (_WIN32_WINNT ge 0501h)
      GET_DEVICE_CHANGE_LPARAM macro lParam
        exitm <(LOWORD(lParam))>
      endm
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
    endif
  endif
  if (WINVER ge 0602h)
    POINTER_DEVICE_PRODUCT_STRING_MAX equ 520
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
      endif
      POINTER_DEVICE_TYPE_MAX equ 0FFFFFFFFh
      tagPOINTER_DEVICE_TYPE typedef POINTER_DEVICE_TYPE

      POINTER_DEVICE_INFO struct
        displayOrientation DWORD ?
        device HANDLE ?
        pointerDeviceType POINTER_DEVICE_TYPE ?
        monitor_ HMONITOR ?
        startingCursorId ULONG ?
        maxActiveContacts USHORT ?
        productString WCHAR POINTER_DEVICE_PRODUCT_STRING_MAX dup (?)
      POINTER_DEVICE_INFO ends
      tagPOINTER_DEVICE_INFO typedef POINTER_DEVICE_INFO
      POINTER_DEVICE_PROPERTY struct
        logicalMin INT32 ?
        logicalMax INT32 ?
        physicalMin INT32 ?
        physicalMax INT32 ?
        unit UINT32 ?
        unitExponent UINT32 ?
        usagePageId USHORT ?
        usageId USHORT ?
      POINTER_DEVICE_PROPERTY ends
      tagPOINTER_DEVICE_PROPERTY typedef POINTER_DEVICE_PROPERTY
      POINTER_DEVICE_CURSOR_TYPE typedef SDWORD
      POINTER_DEVICE_CURSOR_TYPE_UNKNOWN equ 00000000h
      POINTER_DEVICE_CURSOR_TYPE_TIP equ 00000001h
      POINTER_DEVICE_CURSOR_TYPE_ERASER equ 00000002h
      POINTER_DEVICE_CURSOR_TYPE_MAX equ 0FFFFFFFFh
      tagPOINTER_DEVICE_CURSOR_TYPE typedef POINTER_DEVICE_CURSOR_TYPE

      POINTER_DEVICE_CURSOR_INFO struct
        cursorId UINT32 ?
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
    endif
  endif
  if (WINVER ge 0600h)
    MSGFLT_ADD equ 1
    MSGFLT_REMOVE equ 2
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, ChangeWindowMessageFilter, WIN_STD_CALL_CONV,, <:UINT, :DWORD>, 8
    endif
  endif
  if (WINVER ge 0601h)
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
    endif
    MSGFLT_RESET equ (0)
    MSGFLT_ALLOW equ (1)
    MSGFLT_DISALLOW equ (2)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, ChangeWindowMessageFilterEx, WIN_STD_CALL_CONV,, <:HWND, :UINT, :DWORD, :PCHANGEFILTERSTRUCT>, 16
    endif
  endif
  if (WINVER ge 0601h)
  endif
  if (WINVER ge 0601h)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      DECLARE_HANDLE HGESTUREINFO
    endif
    GF_BEGIN equ 00000001h
    GF_INERTIA equ 00000002h
    GF_END equ 00000004h
    GID_BEGIN equ 1
    GID_END equ 2
    GID_ZOOM equ 3
    GID_PAN equ 4
    GID_ROTATE equ 5
    GID_TWOFINGERTAP equ 6
    GID_PRESSANDTAP equ 7
    GID_ROLLOVER equ <GID_PRESSANDTAP>
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      GESTUREINFO struct
        cbSize UINT ?
        dwFlags DWORD ?
        dwID DWORD ?
        hwndTarget HWND ?
        ptsLocation POINTS <>
        dwInstanceID DWORD ?
        dwSequenceID DWORD ?
        ullArguments ULONGLONG ?
        cbExtraArgs UINT ?
      GESTUREINFO ends
      tagGESTUREINFO typedef GESTUREINFO
      PGESTUREINFO typedef ptr GESTUREINFO
      PCGESTUREINFO typedef ptr GESTUREINFO
      GESTURENOTIFYSTRUCT struct
        cbSize UINT ?
        dwFlags DWORD ?
        hwndTarget HWND ?
        ptsLocation POINTS <>
        dwInstanceID DWORD ?
      GESTURENOTIFYSTRUCT ends
      tagGESTURENOTIFYSTRUCT typedef GESTURENOTIFYSTRUCT
      PGESTURENOTIFYSTRUCT typedef ptr GESTURENOTIFYSTRUCT
      GID_ROTATE_ANGLE_TO_ARGUMENT macro _arg_
        exitm <(((((_arg_) + 2.0 * 3.14159265) / (4.0 * 3.14159265)) * 65535.0))>
      endm
      GID_ROTATE_ANGLE_FROM_ARGUMENT macro _arg_
        exitm <((((_arg_) / 65535.0) * 4.0 * 3.14159265) - 2.0 * 3.14159265)>
      endm
      @DefProto DllImport, GetGestureInfo, WIN_STD_CALL_CONV,, <:HGESTUREINFO, :PGESTUREINFO>, 8
      @DefProto DllImport, GetGestureExtraArgs, WIN_STD_CALL_CONV,, <:HGESTUREINFO, :UINT, :PBYTE>, 12
      @DefProto DllImport, CloseGestureInfoHandle, WIN_STD_CALL_CONV,, <:HGESTUREINFO>, 4
      GESTURECONFIG struct
        dwID DWORD ?
        dwWant DWORD ?
        dwBlock DWORD ?
      GESTURECONFIG ends
      tagGESTURECONFIG typedef GESTURECONFIG
      PGESTURECONFIG typedef ptr GESTURECONFIG
    endif
    GC_ALLGESTURES equ 00000001h
    GC_ZOOM equ 00000001h
    GC_PAN equ 00000001h
    GC_PAN_WITH_SINGLE_FINGER_VERTICALLY equ 00000002h
    GC_PAN_WITH_SINGLE_FINGER_HORIZONTALLY equ 00000004h
    GC_PAN_WITH_GUTTER equ 00000008h
    GC_PAN_WITH_INERTIA equ 00000010h
    GC_ROTATE equ 00000001h
    GC_TWOFINGERTAP equ 00000001h
    GC_PRESSANDTAP equ 00000001h
    GC_ROLLOVER equ <GC_PRESSANDTAP>
    GESTURECONFIGMAXCOUNT equ 256
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, SetGestureConfig, WIN_STD_CALL_CONV,, <:HWND, :DWORD, :UINT, :PGESTURECONFIG, :UINT>, 20
      GCF_INCLUDE_ANCESTORS equ 00000001h
      @DefProto DllImport, GetGestureConfig, WIN_STD_CALL_CONV,, <:HWND, :DWORD, :DWORD, :PUINT, :PGESTURECONFIG, :UINT>, 24
    endif
  endif
  if (WINVER ge 0601h)
    NID_INTEGRATED_TOUCH equ 00000001h
    NID_EXTERNAL_TOUCH equ 00000002h
    NID_INTEGRATED_PEN equ 00000004h
    NID_EXTERNAL_PEN equ 00000008h
    NID_MULTI_INPUT equ 00000040h
    NID_READY equ 00000080h
  endif
  MAX_STR_BLOCKREASON equ 256
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    @DefProto DllImport, ShutdownBlockReasonCreate, WIN_STD_CALL_CONV,, <:HWND, :LPCWSTR>, 8
    @DefProto DllImport, ShutdownBlockReasonQuery, WIN_STD_CALL_CONV,, <:HWND, :LPWSTR, :ptr DWORD>, 12
    @DefProto DllImport, ShutdownBlockReasonDestroy, WIN_STD_CALL_CONV,, <:HWND>, 4
  endif
  if (WINVER ge 0601h)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      INPUT_MESSAGE_DEVICE_TYPE typedef SDWORD
      IMDT_UNAVAILABLE equ 00000000h
      IMDT_KEYBOARD equ 00000001h
      IMDT_MOUSE equ 00000002h
      IMDT_TOUCH equ 00000004h
      IMDT_PEN equ 00000008h
      if (WINVER ge 0603h)
        IMDT_TOUCHPAD equ 00000010h
      endif
      tagINPUT_MESSAGE_DEVICE_TYPE typedef INPUT_MESSAGE_DEVICE_TYPE

      INPUT_MESSAGE_ORIGIN_ID typedef SDWORD
      IMO_UNAVAILABLE equ 00000000h
      IMO_HARDWARE equ 00000001h
      IMO_INJECTED equ 00000002h
      IMO_SYSTEM equ 00000004h
      tagINPUT_MESSAGE_ORIGIN_ID typedef INPUT_MESSAGE_ORIGIN_ID

      INPUT_MESSAGE_SOURCE struct
        deviceType INPUT_MESSAGE_DEVICE_TYPE ?
        originId INPUT_MESSAGE_ORIGIN_ID ?
      INPUT_MESSAGE_SOURCE ends
      tagINPUT_MESSAGE_SOURCE typedef INPUT_MESSAGE_SOURCE
      @DefProto DllImport, GetCurrentInputMessageSource, WIN_STD_CALL_CONV,, <:ptr INPUT_MESSAGE_SOURCE>, 4
      @DefProto DllImport, GetCIMSSM, WIN_STD_CALL_CONV,, <:ptr INPUT_MESSAGE_SOURCE>, 4
    endif
  endif
  if (WINVER ge 0602h)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
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
    endif
    ifndef MIDL_PASS
      DEFINE_ENUM_FLAG_OPERATORS(AR_STATE)
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ORIENTATION_PREFERENCE typedef SDWORD
      ORIENTATION_PREFERENCE_NONE equ 0h
      ORIENTATION_PREFERENCE_LANDSCAPE equ 1h
      ORIENTATION_PREFERENCE_PORTRAIT equ 2h
      ORIENTATION_PREFERENCE_LANDSCAPE_FLIPPED equ 4h
      ORIENTATION_PREFERENCE_PORTRAIT_FLIPPED equ 8h

      ifndef MIDL_PASS
        DEFINE_ENUM_FLAG_OPERATORS(ORIENTATION_PREFERENCE)
      endif
      @DefProto DllImport, GetAutoRotationState, WIN_STD_CALL_CONV,, <:PAR_STATE>, 4
      @DefProto DllImport, GetDisplayAutoRotationPreferences, WIN_STD_CALL_CONV,, <:ptr ORIENTATION_PREFERENCE>, 4
      @DefProto DllImport, GetDisplayAutoRotationPreferencesByProcessId, WIN_STD_CALL_CONV,, <:DWORD, :ptr ORIENTATION_PREFERENCE, :ptr BOOL>, 12
      @DefProto DllImport, SetDisplayAutoRotationPreferences, WIN_STD_CALL_CONV,, <:ORIENTATION_PREFERENCE>, 4
    endif
  endif
  if (WINVER ge 0601h)
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      @DefProto DllImport, IsImmersiveProcess, WIN_STD_CALL_CONV,, <:HANDLE>, 4
      @DefProto DllImport, SetProcessRestrictionExemption, WIN_STD_CALL_CONV,, <:BOOL>, 4
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
  endif
  if (WINVER ge 0607h)
    @DefProto DllImport, SetAdditionalForegroundBoostProcesses, WIN_STD_CALL_CONV,, <:HWND, :DWORD, :ptr HANDLE>, 12
    TOOLTIP_DISMISS_FLAGS typedef SDWORD
    TDF_REGISTER equ 0001h
    TDF_UNREGISTER equ 0002h

    @DefProto DllImport, RegisterForTooltipDismissNotification, WIN_STD_CALL_CONV,, <:HWND, :TOOLTIP_DISMISS_FLAGS>, 8
    WM_TOOLTIPDISMISS equ 0345h
  endif
  if _MSC_VER ge 1200
  endif
  if  not Defined(RC_INVOKED)
    if Defined(ISOLATION_AWARE_ENABLED) and (ISOLATION_AWARE_ENABLED ne 0)
      ;[...]
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
