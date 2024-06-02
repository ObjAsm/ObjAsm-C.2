;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\mmsystem.h
;             Created on (UTC) 06/04/2024 06:15:56
;             Last modified on (UTC) 21/02/2024 18:13:14

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
