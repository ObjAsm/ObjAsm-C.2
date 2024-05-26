;Include file created by h2inc+ version C.2.0 on (UTC) 26/05/2024 13:31:25
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\windef.h
;             Created on (UTC) 22/05/2024 17:57:06
;             Last modified on (UTC) 21/02/2024 18:18:30

include winapifamily.inc
ifndef _WINDEF_
  _WINDEF_ equ <>
  ifdef __cplusplus
    ;[...]
  endif
  ifdef _M_CEE_PURE
    ;[...]
  endif
  include minwindef.inc
  ifndef WINVER
    WINVER equ 0500h
  endif
  ifndef NT_INCLUDED
    include winnt.inc
  endif
  ifndef WIN_INTERNAL
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
      DECLARE_HANDLE HWND
      DECLARE_HANDLE HHOOK
    endif
    ifdef WINABLE
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        DECLARE_HANDLE HEVENT
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    if  not Defined(_MAC) or  not Defined(GDI_INTERNAL)
      ifdef STRICT
        HGDIOBJ typedef ptr
      else
        DECLARE_HANDLE HGDIOBJ
      endif
    endif
    if  not Defined(_MAC) or  not Defined(WIN_INTERNAL)
      DECLARE_HANDLE HACCEL
    endif
    if  not Defined(_MAC) or  not Defined(GDI_INTERNAL)
      DECLARE_HANDLE HBITMAP
      DECLARE_HANDLE HBRUSH
    endif
    if (WINVER ge 0400h)
      DECLARE_HANDLE HCOLORSPACE
    endif
    if  not Defined(_MAC) or  not Defined(GDI_INTERNAL)
      DECLARE_HANDLE HDC
    endif
    DECLARE_HANDLE HGLRC
    DECLARE_HANDLE HDESK
    DECLARE_HANDLE HENHMETAFILE
    if  not Defined(_MAC) or  not Defined(GDI_INTERNAL)
      DECLARE_HANDLE HFONT
    endif
    DECLARE_HANDLE HICON
    if  not Defined(_MAC) or  not Defined(WIN_INTERNAL)
      DECLARE_HANDLE HMENU
    endif
    if  not Defined(_MAC) or  not Defined(GDI_INTERNAL)
      DECLARE_HANDLE HPALETTE
      DECLARE_HANDLE HPEN
    endif
    if (WINVER ge 0400h)
      DECLARE_HANDLE HWINEVENTHOOK
    endif
  endif
  if (WINVER ge 0500h)
    ifndef _MAC
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
        DECLARE_HANDLE HMONITOR
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      DECLARE_HANDLE HUMPD
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    ifndef _MAC
      HCURSOR typedef HICON
    else
      ;[...]
    endif
    COLORREF typedef DWORD
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    LPCOLORREF typedef ptr DWORD
    HFILE_ERROR equ (- 1)
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    RECT struct
      left LONG ?
      top LONG ?
      right LONG ?
      bottom LONG ?
    RECT ends
    tagRECT typedef RECT
    PRECT typedef ptr RECT
    NPRECT typedef ptr RECT
    LPRECT typedef ptr RECT
    LPCRECT typedef ptr RECT
    RECTL struct
      left LONG ?
      top LONG ?
      right LONG ?
      bottom LONG ?
    RECTL ends
    _RECTL typedef RECTL
    PRECTL typedef ptr RECTL
    LPRECTL typedef ptr RECTL
    LPCRECTL typedef ptr RECTL
    POINT struct
      x LONG ?
      y LONG ?
    POINT ends
    tagPOINT typedef POINT
    PPOINT typedef ptr POINT
    NPPOINT typedef ptr POINT
    LPPOINT typedef ptr POINT
    POINTL struct
      x LONG ?
      y LONG ?
    POINTL ends
    _POINTL typedef POINTL
    PPOINTL typedef ptr POINTL
    SIZE_ struct
      cx_ LONG ?
      cy LONG ?
    SIZE_ ends
    tagSIZE typedef SIZE_
    PSIZE typedef ptr SIZE_
    LPSIZE typedef ptr SIZE_
    SIZEL typedef SIZE_
    PSIZEL typedef ptr SIZE_
    LPSIZEL typedef ptr SIZE_
    POINTS struct
      ifndef _MAC
        x SHORT_ ?
        y SHORT_ ?
      else
        ;[...]
      endif
    POINTS ends
    tagPOINTS typedef POINTS
    PPOINTS typedef ptr POINTS
    LPPOINTS typedef ptr POINTS
    APP_LOCAL_DEVICE_ID_SIZE equ 32
    APP_LOCAL_DEVICE_ID struct
      value BYTE APP_LOCAL_DEVICE_ID_SIZE dup (?)
    APP_LOCAL_DEVICE_ID ends
  endif
  DM_UPDATE equ 1
  DM_COPY equ 2
  DM_PROMPT equ 4
  DM_MODIFY equ 8
  DM_IN_BUFFER equ <DM_MODIFY>
  DM_IN_PROMPT equ <DM_PROMPT>
  DM_OUT_BUFFER equ <DM_COPY>
  DM_OUT_DEFAULT equ <DM_UPDATE>
  DC_FIELDS equ 1
  DC_PAPERS equ 2
  DC_PAPERSIZE equ 3
  DC_MINEXTENT equ 4
  DC_MAXEXTENT equ 5
  DC_BINS equ 6
  DC_DUPLEX equ 7
  DC_SIZE equ 8
  DC_EXTRA equ 9
  DC_VERSION equ 10
  DC_DRIVER equ 11
  DC_BINNAMES equ 12
  DC_ENUMRESOLUTIONS equ 13
  DC_FILEDEPENDENCIES equ 14
  DC_TRUETYPE equ 15
  DC_PAPERNAMES equ 16
  DC_ORIENTATION equ 17
  DC_COPIES equ 18
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    _DPI_AWARENESS_CONTEXTS_ equ <>
    DECLARE_HANDLE DPI_AWARENESS_CONTEXT
    DPI_AWARENESS typedef SDWORD
    DPI_AWARENESS_INVALID equ -1
    DPI_AWARENESS_UNAWARE equ 0
    DPI_AWARENESS_SYSTEM_AWARE equ 1
    DPI_AWARENESS_PER_MONITOR_AWARE equ 2

    DPI_AWARENESS_CONTEXT_UNAWARE equ ((DPI_AWARENESS_CONTEXT) - 1)
    DPI_AWARENESS_CONTEXT_SYSTEM_AWARE equ ((DPI_AWARENESS_CONTEXT) - 2)
    DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE equ ((DPI_AWARENESS_CONTEXT) - 3)
    DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2 equ ((DPI_AWARENESS_CONTEXT) - 4)
    DPI_AWARENESS_CONTEXT_UNAWARE_GDISCALED equ ((DPI_AWARENESS_CONTEXT) - 5)
    DPI_HOSTING_BEHAVIOR typedef SDWORD
    DPI_HOSTING_BEHAVIOR_INVALID equ -1
    DPI_HOSTING_BEHAVIOR_DEFAULT equ 0
    DPI_HOSTING_BEHAVIOR_MIXED equ 1

  endif
endif
