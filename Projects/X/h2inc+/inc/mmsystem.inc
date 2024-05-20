;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\mmsystem.h
;             Created on (UTC) 06/04/2024 06:15:56
;             Last modified on (UTC) 21/02/2024 18:13:14

include winapifamily.inc
;*==========================================================================
;*
;*  mmsystem.h -- Include file for Multimedia API's
;*
;*  Version 4.00
;*
;*  Copyright (C) 1992-1998 Microsoft Corporation.  All Rights Reserved.
;*
;*--------------------------------------------------------------------------
;*
;*  Define:         Prevent inclusion of:
;*  --------------  --------------------------------------------------------
;*  MMNODRV         Installable driver support
;*  MMNOSOUND       Sound support
;*  MMNOWAVE        Waveform support
;*  MMNOMIDI        MIDI support
;*  MMNOAUX         Auxiliary audio support
;*  MMNOMIXER       Mixer support
;*  MMNOTIMER       Timer support
;*  MMNOJOY         Joystick support
;*  MMNOMCI         MCI support
;*  MMNOMMIO        Multimedia file I/O support
;*  MMNOMMSYSTEM    General MMSYSTEM functions
;*
;*==========================================================================
;*
ifndef _INC_MMSYSTEM
  ;* #defined if mmsystem.h has been included *
  _INC_MMSYSTEM equ <>
  include mmsyscom.inc
  ifdef _WIN32
    include pshpack1.inc
  else
    ;[...]
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ;****************************************************************************
    ;Multimedia Extensions Window Messages
    ;****************************************************************************
    ifndef MMNOMCI
      ;* MMNOMCI         MCI support *
      include mciapi.inc
    endif
    ; #ifndef MMNOMCI
    ;* MMNODRV - Installable driver support *
    include mmiscapi.inc
    include mmiscapi2.inc
    ;* MMNOSOUND  Sound support *
    include playsoundapi.inc
    include mmeapi.inc
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    ifndef MMNOTIMER
      ;****************************************************************************
      ;Timer support
      ;****************************************************************************
      include timeapi.inc
      ;* timer data types *
      ;* ifndef MMNOTIMER *
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ; Joystickapi API Set contract
    include joystickapi.inc
    ;****************************************************************************
    ;DISPLAY Driver extensions
    ;****************************************************************************
    ifndef NEWTRANSPARENT
      ;* use with SetBkMode() *
      NEWTRANSPARENT equ 3
      ;* use to determine ROP support *
      QUERYROPSUPPORT equ 40
      ;* ifndef NEWTRANSPARENT *
    endif
    ;****************************************************************************
    ;DIB Driver extensions
    ;****************************************************************************
    ;* DIB.DRV select dib escape *
    SELECTDIB equ 41
    DIBINDEX macro n
      exitm <MAKELONG((n), 10FFh)>
    endm
    ;****************************************************************************
    ;ScreenSaver support
    ;The current application will receive a syscommand of SC_SCREENSAVE just
    ;before the screen saver is invoked.  If the app wishes to prevent a
    ;screen save, return non-zero value, otherwise call DefWindowProc().
    ;****************************************************************************
    ifndef SC_SCREENSAVE
      SC_SCREENSAVE equ 0F140h
      ;* ifndef SC_SCREENSAVE *
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  ifdef __cplusplus
    ;[...]
  endif
  ifdef _WIN32
    include poppack.inc
  else
    ;[...]
  endif
  ;* _INC_MMSYSTEM *
endif
