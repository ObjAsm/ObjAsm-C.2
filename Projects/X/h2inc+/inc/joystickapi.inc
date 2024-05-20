;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\joystickapi.h
;             Created on (UTC) 06/04/2024 06:15:56
;             Last modified on (UTC) 21/02/2024 18:13:22

;********************************************************************************
ifdef _MSC_VER
endif
; _MSC_VER
ifndef _JOYSTICKAPI_H_
  _JOYSTICKAPI_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include mmsyscom.inc
  ; mm common definitions
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef MMNOJOY
      ;****************************************************************************
      ;Joystick support
      ;****************************************************************************
      ;* joystick error return values *
      ;* no error *
      JOYERR_NOERROR equ (0)
      ;* bad parameters *
      JOYERR_PARMS equ (JOYERR_BASE + 5)
      ;* request not completed *
      JOYERR_NOCANDO equ (JOYERR_BASE + 6)
      ;* joystick is unplugged *
      JOYERR_UNPLUGGED equ (JOYERR_BASE + 7)
      ;* constants used with JOYINFO and JOYINFOEX structures and MM_JOY* messages *
      JOY_BUTTON1 equ 0001h
      JOY_BUTTON2 equ 0002h
      JOY_BUTTON3 equ 0004h
      JOY_BUTTON4 equ 0008h
      JOY_BUTTON1CHG equ 0100h
      JOY_BUTTON2CHG equ 0200h
      JOY_BUTTON3CHG equ 0400h
      JOY_BUTTON4CHG equ 0800h
      ;* constants used with JOYINFOEX *
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
      ;* constants used with JOYINFOEX structure *
      JOY_POVCENTERED equ -1
      JOY_POVFORWARD equ 0
      JOY_POVRIGHT equ 9000
      JOY_POVBACKWARD equ 18000
      JOY_POVLEFT equ 27000
      JOY_RETURNX equ 00000001h
      JOY_RETURNY equ 00000002h
      JOY_RETURNZ equ 00000004h
      JOY_RETURNR equ 00000008h
      ;* axis 5 *
      JOY_RETURNU equ 00000010h
      ;* axis 6 *
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
      ;* joystick ID constants *
      JOYSTICKID1 equ 0
      JOYSTICKID2 equ 1
      ;* joystick driver capabilites *
      JOYCAPS_HASZ equ 0001h
      JOYCAPS_HASR equ 0002h
      JOYCAPS_HASU equ 0004h
      JOYCAPS_HASV equ 0008h
      JOYCAPS_HASPOV equ 0010h
      JOYCAPS_POV4DIR equ 0020h
      JOYCAPS_POVCTS equ 0040h
      ;* joystick device capabilities data structure *
      ifdef _WIN32
        JOYCAPSA struct
          wMid WORD ?
          ;* manufacturer ID *
          wPid WORD ?
          ;* product ID *
          szPname SBYTE MAXPNAMELEN dup (?)
          ;* product name (NULL terminated string) *
          wXmin DWORD ?
          ;* minimum x position value *
          wXmax DWORD ?
          ;* maximum x position value *
          wYmin DWORD ?
          ;* minimum y position value *
          wYmax DWORD ?
          ;* maximum y position value *
          wZmin DWORD ?
          ;* minimum z position value *
          wZmax DWORD ?
          ;* maximum z position value *
          wNumButtons DWORD ?
          ;* number of buttons *
          wPeriodMin DWORD ?
          ;* minimum message period when captured *
          wPeriodMax DWORD ?
          ;* maximum message period when captured *
          if (WINVER ge 0400h)
            wRmin DWORD ?
            ;* minimum r position value *
            wRmax DWORD ?
            ;* maximum r position value *
            wUmin DWORD ?
            ;* minimum u (5th axis) position value *
            wUmax DWORD ?
            ;* maximum u (5th axis) position value *
            wVmin DWORD ?
            ;* minimum v (6th axis) position value *
            wVmax DWORD ?
            ;* maximum v (6th axis) position value *
            wCaps DWORD ?
            ;* joystick capabilites *
            wMaxAxes DWORD ?
            ;* maximum number of axes supported *
            wNumAxes DWORD ?
            ;* number of axes in use *
            wMaxButtons DWORD ?
            ;* maximum number of buttons supported *
            szRegKey SBYTE MAXPNAMELEN dup (?)
            ;* registry key *
            szOEMVxD SBYTE MAX_JOYSTICKOEMVXDNAME dup (?)
            ;* OEM VxD in use *
          endif
        JOYCAPSA ends
        tagJOYCAPSA typedef JOYCAPSA
        PJOYCAPSA typedef ptr JOYCAPSA
        NPJOYCAPSA typedef ptr JOYCAPSA
        LPJOYCAPSA typedef ptr JOYCAPSA
        JOYCAPSW struct
          wMid WORD ?
          ;* manufacturer ID *
          wPid WORD ?
          ;* product ID *
          szPname WORD MAXPNAMELEN dup (?)
          ;* product name (NULL terminated string) *
          wXmin DWORD ?
          ;* minimum x position value *
          wXmax DWORD ?
          ;* maximum x position value *
          wYmin DWORD ?
          ;* minimum y position value *
          wYmax DWORD ?
          ;* maximum y position value *
          wZmin DWORD ?
          ;* minimum z position value *
          wZmax DWORD ?
          ;* maximum z position value *
          wNumButtons DWORD ?
          ;* number of buttons *
          wPeriodMin DWORD ?
          ;* minimum message period when captured *
          wPeriodMax DWORD ?
          ;* maximum message period when captured *
          if (WINVER ge 0400h)
            wRmin DWORD ?
            ;* minimum r position value *
            wRmax DWORD ?
            ;* maximum r position value *
            wUmin DWORD ?
            ;* minimum u (5th axis) position value *
            wUmax DWORD ?
            ;* maximum u (5th axis) position value *
            wVmin DWORD ?
            ;* minimum v (6th axis) position value *
            wVmax DWORD ?
            ;* maximum v (6th axis) position value *
            wCaps DWORD ?
            ;* joystick capabilites *
            wMaxAxes DWORD ?
            ;* maximum number of axes supported *
            wNumAxes DWORD ?
            ;* number of axes in use *
            wMaxButtons DWORD ?
            ;* maximum number of buttons supported *
            szRegKey WORD MAXPNAMELEN dup (?)
            ;* registry key *
            szOEMVxD WORD MAX_JOYSTICKOEMVXDNAME dup (?)
            ;* OEM VxD in use *
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
        ; UNICODE
        JOYCAPS2A struct
          wMid WORD ?
          ;* manufacturer ID *
          wPid WORD ?
          ;* product ID *
          szPname SBYTE MAXPNAMELEN dup (?)
          ;* product name (NULL terminated string) *
          wXmin DWORD ?
          ;* minimum x position value *
          wXmax DWORD ?
          ;* maximum x position value *
          wYmin DWORD ?
          ;* minimum y position value *
          wYmax DWORD ?
          ;* maximum y position value *
          wZmin DWORD ?
          ;* minimum z position value *
          wZmax DWORD ?
          ;* maximum z position value *
          wNumButtons DWORD ?
          ;* number of buttons *
          wPeriodMin DWORD ?
          ;* minimum message period when captured *
          wPeriodMax DWORD ?
          ;* maximum message period when captured *
          wRmin DWORD ?
          ;* minimum r position value *
          wRmax DWORD ?
          ;* maximum r position value *
          wUmin DWORD ?
          ;* minimum u (5th axis) position value *
          wUmax DWORD ?
          ;* maximum u (5th axis) position value *
          wVmin DWORD ?
          ;* minimum v (6th axis) position value *
          wVmax DWORD ?
          ;* maximum v (6th axis) position value *
          wCaps DWORD ?
          ;* joystick capabilites *
          wMaxAxes DWORD ?
          ;* maximum number of axes supported *
          wNumAxes DWORD ?
          ;* number of axes in use *
          wMaxButtons DWORD ?
          ;* maximum number of buttons supported *
          szRegKey SBYTE MAXPNAMELEN dup (?)
          ;* registry key *
          szOEMVxD SBYTE MAX_JOYSTICKOEMVXDNAME dup (?)
          ;* OEM VxD in use *
          ManufacturerGuid GUID <>
          ;* for extensible MID mapping *
          ProductGuid GUID <>
          ;* for extensible PID mapping *
          NameGuid GUID <>
          ;* for name lookup in registry *
        JOYCAPS2A ends
        tagJOYCAPS2A typedef JOYCAPS2A
        PJOYCAPS2A typedef ptr JOYCAPS2A
        NPJOYCAPS2A typedef ptr JOYCAPS2A
        LPJOYCAPS2A typedef ptr JOYCAPS2A
        JOYCAPS2W struct
          wMid WORD ?
          ;* manufacturer ID *
          wPid WORD ?
          ;* product ID *
          szPname WORD MAXPNAMELEN dup (?)
          ;* product name (NULL terminated string) *
          wXmin DWORD ?
          ;* minimum x position value *
          wXmax DWORD ?
          ;* maximum x position value *
          wYmin DWORD ?
          ;* minimum y position value *
          wYmax DWORD ?
          ;* maximum y position value *
          wZmin DWORD ?
          ;* minimum z position value *
          wZmax DWORD ?
          ;* maximum z position value *
          wNumButtons DWORD ?
          ;* number of buttons *
          wPeriodMin DWORD ?
          ;* minimum message period when captured *
          wPeriodMax DWORD ?
          ;* maximum message period when captured *
          wRmin DWORD ?
          ;* minimum r position value *
          wRmax DWORD ?
          ;* maximum r position value *
          wUmin DWORD ?
          ;* minimum u (5th axis) position value *
          wUmax DWORD ?
          ;* maximum u (5th axis) position value *
          wVmin DWORD ?
          ;* minimum v (6th axis) position value *
          wVmax DWORD ?
          ;* maximum v (6th axis) position value *
          wCaps DWORD ?
          ;* joystick capabilites *
          wMaxAxes DWORD ?
          ;* maximum number of axes supported *
          wNumAxes DWORD ?
          ;* number of axes in use *
          wMaxButtons DWORD ?
          ;* maximum number of buttons supported *
          szRegKey WORD MAXPNAMELEN dup (?)
          ;* registry key *
          szOEMVxD WORD MAX_JOYSTICKOEMVXDNAME dup (?)
          ;* OEM VxD in use *
          ManufacturerGuid GUID <>
          ;* for extensible MID mapping *
          ProductGuid GUID <>
          ;* for extensible PID mapping *
          NameGuid GUID <>
          ;* for name lookup in registry *
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
        ; UNICODE
      else
        ;[...]
      endif
      ;* joystick information data structure *
      JOYINFO struct
        wXpos DWORD ?
        ;* x position *
        wYpos DWORD ?
        ;* y position *
        wZpos DWORD ?
        ;* z position *
        wButtons DWORD ?
        ;* button states *
      JOYINFO ends
      joyinfo_tag typedef JOYINFO
      PJOYINFO typedef ptr JOYINFO
      NPJOYINFO typedef ptr JOYINFO
      LPJOYINFO typedef ptr JOYINFO
      if (WINVER ge 0400h)
        JOYINFOEX struct
          dwSize DWORD ?
          ;* size of structure *
          dwFlags DWORD ?
          ;* flags to indicate what to return *
          dwXpos DWORD ?
          ;* x position *
          dwYpos DWORD ?
          ;* y position *
          dwZpos DWORD ?
          ;* z position *
          dwRpos DWORD ?
          ;* rudder/4th axis position *
          dwUpos DWORD ?
          ;* 5th axis position *
          dwVpos DWORD ?
          ;* 6th axis position *
          dwButtons DWORD ?
          ;* button states *
          dwButtonNumber DWORD ?
          ;* current button number pressed *
          dwPOV DWORD ?
          ;* point of view state *
          dwReserved1 DWORD ?
          ;* reserved for communication between winmm & driver *
          dwReserved2 DWORD ?
          ;* reserved for future expansion *
        JOYINFOEX ends
        joyinfoex_tag typedef JOYINFOEX
        PJOYINFOEX typedef ptr JOYINFOEX
        NPJOYINFOEX typedef ptr JOYINFOEX
        LPJOYINFOEX typedef ptr JOYINFOEX
      endif
      ;* joystick function prototypes *
      if (WINVER ge 0400h)
        @DefProto DllImport, joyGetPosEx, WIN_STD_CALL_CONV,, <:UINT, :LPJOYINFOEX>, 8
        ;* WINVER >= 0x0400 *
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
        ; !UNICODE
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
      ;* ifndef MMNOJOY *
    endif
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
  ifdef __cplusplus
    ;[...]
  endif
endif
; _JOYSTICKAPI_H_
