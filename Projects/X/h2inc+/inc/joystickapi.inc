;Include file created by h2inc+ version C.2.0 on (UTC) 19/05/2024 07:52:23
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\joystickapi.h\joystickapi.h
;             Created on (UTC) 06/04/2024 06:15:56
;             Last modified on (UTC) 21/02/2024 18:13:22

ifdef _MSC_VER
endif
ifndef _JOYSTICKAPI_H_
  _JOYSTICKAPI_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include mmsyscom.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef MMNOJOY
      JOYERR_NOERROR equ (0)
      JOYERR_PARMS equ (JOYERR_BASE + 5)
      JOYERR_NOCANDO equ (JOYERR_BASE + 6)
      JOYERR_UNPLUGGED equ (JOYERR_BASE + 7)
      JOY_BUTTON1 equ 0001h
      JOY_BUTTON2 equ 0002h
      JOY_BUTTON3 equ 0004h
      JOY_BUTTON4 equ 0008h
      JOY_BUTTON1CHG equ 0100h
      JOY_BUTTON2CHG equ 0200h
      JOY_BUTTON3CHG equ 0400h
      JOY_BUTTON4CHG equ 0800h
      JOY_BUTTON5 equ 00000010h
      JOY_BUTTON6 equ 00000020h
      JOY_BUTTON7 equ 00000040h
      JOY_BUTTON8 equ 00000080h
      JOY_BUTTON9 equ 00000100h
      JOY_BUTTON10 equ 00000200h
      JOY_BUTTON11 equ 00000400h
      JOY_BUTTON12 equ 00000800h
      JOY_BUTTON13 equ 00001000h
      JOY_BUTTON14 equ 00002000h
      JOY_BUTTON15 equ 00004000h
      JOY_BUTTON16 equ 00008000h
      JOY_BUTTON17 equ 00010000h
      JOY_BUTTON18 equ 00020000h
      JOY_BUTTON19 equ 00040000h
      JOY_BUTTON20 equ 00080000h
      JOY_BUTTON21 equ 00100000h
      JOY_BUTTON22 equ 00200000h
      JOY_BUTTON23 equ 00400000h
      JOY_BUTTON24 equ 00800000h
      JOY_BUTTON25 equ 01000000h
      JOY_BUTTON26 equ 02000000h
      JOY_BUTTON27 equ 04000000h
      JOY_BUTTON28 equ 08000000h
      JOY_BUTTON29 equ 10000000h
      JOY_BUTTON30 equ 20000000h
      JOY_BUTTON31 equ 40000000h
      JOY_BUTTON32 equ 80000000h
      JOY_POVCENTERED equ -1
      JOY_POVFORWARD equ 0
      JOY_POVRIGHT equ 9000
      JOY_POVBACKWARD equ 18000
      JOY_POVLEFT equ 27000
      JOY_RETURNX equ 00000001h
      JOY_RETURNY equ 00000002h
      JOY_RETURNZ equ 00000004h
      JOY_RETURNR equ 00000008h
      JOY_RETURNU equ 00000010h
      JOY_RETURNV equ 00000020h
      JOY_RETURNPOV equ 00000040h
      JOY_RETURNBUTTONS equ 00000080h
      JOY_RETURNRAWDATA equ 00000100h
      JOY_RETURNPOVCTS equ 00000200h
      JOY_RETURNCENTERED equ 00000400h
      JOY_USEDEADZONE equ 00000800h
      JOY_RETURNALL equ <(JOY_RETURNX or JOY_RETURNY or JOY_RETURNZ or JOY_RETURNR or JOY_RETURNU or JOY_RETURNV or JOY_RETURNPOV or JOY_RETURNBUTTONS)>
      JOY_CAL_READALWAYS equ 00010000h
      JOY_CAL_READXYONLY equ 00020000h
      JOY_CAL_READ3 equ 00040000h
      JOY_CAL_READ4 equ 00080000h
      JOY_CAL_READXONLY equ 00100000h
      JOY_CAL_READYONLY equ 00200000h
      JOY_CAL_READ5 equ 00400000h
      JOY_CAL_READ6 equ 00800000h
      JOY_CAL_READZONLY equ 01000000h
      JOY_CAL_READRONLY equ 02000000h
      JOY_CAL_READUONLY equ 04000000h
      JOY_CAL_READVONLY equ 08000000h
      JOYSTICKID1 equ 0
      JOYSTICKID2 equ 1
      JOYCAPS_HASZ equ 0001h
      JOYCAPS_HASR equ 0002h
      JOYCAPS_HASU equ 0004h
      JOYCAPS_HASV equ 0008h
      JOYCAPS_HASPOV equ 0010h
      JOYCAPS_POV4DIR equ 0020h
      JOYCAPS_POVCTS equ 0040h
      ifdef _WIN32
        JOYCAPSA struct
          wMid WORD ?
          wPid WORD ?
          szPname CHAR MAXPNAMELEN dup (?)
          wXmin UINT ?
          wXmax UINT ?
          wYmin UINT ?
          wYmax UINT ?
          wZmin UINT ?
          wZmax UINT ?
          wNumButtons UINT ?
          wPeriodMin UINT ?
          wPeriodMax UINT ?
          if (WINVER ge 0400h)
            wRmin UINT ?
            wRmax UINT ?
            wUmin UINT ?
            wUmax UINT ?
            wVmin UINT ?
            wVmax UINT ?
            wCaps UINT ?
            wMaxAxes UINT ?
            wNumAxes UINT ?
            wMaxButtons UINT ?
            szRegKey CHAR MAXPNAMELEN dup (?)
            szOEMVxD CHAR MAX_JOYSTICKOEMVXDNAME dup (?)
          endif
        JOYCAPSA ends
        tagJOYCAPSA typedef JOYCAPSA
        PJOYCAPSA typedef ptr JOYCAPSA
        NPJOYCAPSA typedef ptr JOYCAPSA
        LPJOYCAPSA typedef ptr JOYCAPSA
        JOYCAPSW struct
          wMid WORD ?
          wPid WORD ?
          szPname WCHAR MAXPNAMELEN dup (?)
          wXmin UINT ?
          wXmax UINT ?
          wYmin UINT ?
          wYmax UINT ?
          wZmin UINT ?
          wZmax UINT ?
          wNumButtons UINT ?
          wPeriodMin UINT ?
          wPeriodMax UINT ?
          if (WINVER ge 0400h)
            wRmin UINT ?
            wRmax UINT ?
            wUmin UINT ?
            wUmax UINT ?
            wVmin UINT ?
            wVmax UINT ?
            wCaps UINT ?
            wMaxAxes UINT ?
            wNumAxes UINT ?
            wMaxButtons UINT ?
            szRegKey WCHAR MAXPNAMELEN dup (?)
            szOEMVxD WCHAR MAX_JOYSTICKOEMVXDNAME dup (?)
          endif
        JOYCAPSW ends
        tagJOYCAPSW typedef JOYCAPSW
        PJOYCAPSW typedef ptr JOYCAPSW
        NPJOYCAPSW typedef ptr JOYCAPSW
        LPJOYCAPSW typedef ptr JOYCAPSW
        ifdef UNICODE
          JOYCAPS typedef JOYCAPSW
          PJOYCAPS typedef PJOYCAPSW
          NPJOYCAPS typedef NPJOYCAPSW
          LPJOYCAPS typedef LPJOYCAPSW
        else
          JOYCAPS typedef JOYCAPSA
          PJOYCAPS typedef PJOYCAPSA
          NPJOYCAPS typedef NPJOYCAPSA
          LPJOYCAPS typedef LPJOYCAPSA
        endif
        JOYCAPS2A struct
          wMid WORD ?
          wPid WORD ?
          szPname CHAR MAXPNAMELEN dup (?)
          wXmin UINT ?
          wXmax UINT ?
          wYmin UINT ?
          wYmax UINT ?
          wZmin UINT ?
          wZmax UINT ?
          wNumButtons UINT ?
          wPeriodMin UINT ?
          wPeriodMax UINT ?
          wRmin UINT ?
          wRmax UINT ?
          wUmin UINT ?
          wUmax UINT ?
          wVmin UINT ?
          wVmax UINT ?
          wCaps UINT ?
          wMaxAxes UINT ?
          wNumAxes UINT ?
          wMaxButtons UINT ?
          szRegKey CHAR MAXPNAMELEN dup (?)
          szOEMVxD CHAR MAX_JOYSTICKOEMVXDNAME dup (?)
          ManufacturerGuid GUID <>
          ProductGuid GUID <>
          NameGuid GUID <>
        JOYCAPS2A ends
        tagJOYCAPS2A typedef JOYCAPS2A
        PJOYCAPS2A typedef ptr JOYCAPS2A
        NPJOYCAPS2A typedef ptr JOYCAPS2A
        LPJOYCAPS2A typedef ptr JOYCAPS2A
        JOYCAPS2W struct
          wMid WORD ?
          wPid WORD ?
          szPname WCHAR MAXPNAMELEN dup (?)
          wXmin UINT ?
          wXmax UINT ?
          wYmin UINT ?
          wYmax UINT ?
          wZmin UINT ?
          wZmax UINT ?
          wNumButtons UINT ?
          wPeriodMin UINT ?
          wPeriodMax UINT ?
          wRmin UINT ?
          wRmax UINT ?
          wUmin UINT ?
          wUmax UINT ?
          wVmin UINT ?
          wVmax UINT ?
          wCaps UINT ?
          wMaxAxes UINT ?
          wNumAxes UINT ?
          wMaxButtons UINT ?
          szRegKey WCHAR MAXPNAMELEN dup (?)
          szOEMVxD WCHAR MAX_JOYSTICKOEMVXDNAME dup (?)
          ManufacturerGuid GUID <>
          ProductGuid GUID <>
          NameGuid GUID <>
        JOYCAPS2W ends
        tagJOYCAPS2W typedef JOYCAPS2W
        PJOYCAPS2W typedef ptr JOYCAPS2W
        NPJOYCAPS2W typedef ptr JOYCAPS2W
        LPJOYCAPS2W typedef ptr JOYCAPS2W
        ifdef UNICODE
          JOYCAPS2 typedef JOYCAPS2W
          PJOYCAPS2 typedef PJOYCAPS2W
          NPJOYCAPS2 typedef NPJOYCAPS2W
          LPJOYCAPS2 typedef LPJOYCAPS2W
        else
          JOYCAPS2 typedef JOYCAPS2A
          PJOYCAPS2 typedef PJOYCAPS2A
          NPJOYCAPS2 typedef NPJOYCAPS2A
          LPJOYCAPS2 typedef LPJOYCAPS2A
        endif
      else
        ;[...]
      endif
      JOYINFO struct
        wXpos UINT ?
        wYpos UINT ?
        wZpos UINT ?
        wButtons UINT ?
      JOYINFO ends
      joyinfo_tag typedef JOYINFO
      PJOYINFO typedef ptr JOYINFO
      NPJOYINFO typedef ptr JOYINFO
      LPJOYINFO typedef ptr JOYINFO
      if (WINVER ge 0400h)
        JOYINFOEX struct
          dwSize DWORD ?
          dwFlags DWORD ?
          dwXpos DWORD ?
          dwYpos DWORD ?
          dwZpos DWORD ?
          dwRpos DWORD ?
          dwUpos DWORD ?
          dwVpos DWORD ?
          dwButtons DWORD ?
          dwButtonNumber DWORD ?
          dwPOV DWORD ?
          dwReserved1 DWORD ?
          dwReserved2 DWORD ?
        JOYINFOEX ends
        joyinfoex_tag typedef JOYINFOEX
        PJOYINFOEX typedef ptr JOYINFOEX
        NPJOYINFOEX typedef ptr JOYINFOEX
        LPJOYINFOEX typedef ptr JOYINFOEX
      endif
      if (WINVER ge 0400h)
        @DefProto DllImport, joyGetPosEx, WIN_STD_CALL_CONV,, <:UINT, :LPJOYINFOEX>, 8
      endif
      @DefProto DllImport, joyGetNumDevs, WIN_STD_CALL_CONV,, <>, 0
      ifdef _WIN32
        @DefProto DllImport, joyGetDevCapsA, WIN_STD_CALL_CONV,, <:UINT_PTR, :LPJOYCAPSA, :UINT>, 12
        @DefProto DllImport, joyGetDevCapsW, WIN_STD_CALL_CONV,, <:UINT_PTR, :LPJOYCAPSW, :UINT>, 12
        ifdef UNICODE
          joyGetDevCaps equ <joyGetDevCapsW>
        else
          joyGetDevCaps equ <joyGetDevCapsA>
        endif
      else
        ;[...]
      endif
      @DefProto DllImport, joyGetPos, WIN_STD_CALL_CONV,, <:UINT, :LPJOYINFO>, 8
      @DefProto DllImport, joyGetThreshold, WIN_STD_CALL_CONV,, <:UINT, :LPUINT>, 8
      @DefProto DllImport, joyReleaseCapture, WIN_STD_CALL_CONV,, <:UINT>, 4
      @DefProto DllImport, joySetCapture, WIN_STD_CALL_CONV,, <:HWND, :UINT, :UINT, :BOOL>, 16
      @DefProto DllImport, joySetThreshold, WIN_STD_CALL_CONV,, <:UINT, :UINT>, 8
      if (WINVER ge 0400h)
        @DefProto DllImport, joyConfigChanged, WIN_STD_CALL_CONV,, <:DWORD>, 4
      endif
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
