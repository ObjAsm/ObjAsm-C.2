;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\mmsystem.h', last modified: 19/04/2018 10:43
;Creation parameters: 

include winapifamily.inc
ifndef _INC_MMSYSTEM
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
    ifndef MMNOMCI
      include mciapi.inc
    endif
    include mmiscapi.inc
    include mmiscapi2.inc
    include playsoundapi.inc
    include mmeapi.inc
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    ifndef MMNOTIMER
      include timeapi.inc
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    include joystickapi.inc
    ifndef NEWTRANSPARENT
      NEWTRANSPARENT equ 3
      QUERYROPSUPPORT equ 40
    endif
    SELECTDIB equ 41
    DIBINDEX macro n
      exitm <MAKELONG((n), 10FFh)>
    endm
    ifndef SC_SCREENSAVE
      SC_SCREENSAVE equ 0F140h
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
  ifdef _WIN32
    include poppack.inc
  else
    ;[...]
  endif
endif

