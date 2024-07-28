;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\dde.h', last modified: 19/04/2018 10:46
;Creation parameters: 

ifndef _DDEHEADER_INCLUDED_
  _DDEHEADER_INCLUDED_ equ <>
  if _MSC_VER gt 1000
  endif
  ifndef _WINDEF_
    include windef.inc
  endif
  include winapifamily.inc
  if _MSC_VER ge 1200
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    WM_DDE_FIRST equ 03E0h
    WM_DDE_INITIATE equ <(WM_DDE_FIRST)>
    WM_DDE_TERMINATE equ (WM_DDE_FIRST + 1)
    WM_DDE_ADVISE equ (WM_DDE_FIRST + 2)
    WM_DDE_UNADVISE equ (WM_DDE_FIRST + 3)
    WM_DDE_ACK equ (WM_DDE_FIRST + 4)
    WM_DDE_DATA equ (WM_DDE_FIRST + 5)
    WM_DDE_REQUEST equ (WM_DDE_FIRST + 6)
    WM_DDE_POKE equ (WM_DDE_FIRST + 7)
    WM_DDE_EXECUTE equ (WM_DDE_FIRST + 8)
    WM_DDE_LAST equ (WM_DDE_FIRST + 8)
    DDEACK struct
      ifndef _MAC
        DDEACK_??51 record bAppReturnCode_??51:8, Bitfield1_??51:6, Bitfield2_??51:1, Bitfield3_??51:1
        DDEACK_??51 <>
      else
        ;[...]
      endif
    DDEACK ends

    DDEADVISE struct
      ifndef _MAC
        DDEADVISE_??52 record reserved_??52:14, Bitfield1_??52:1, Bitfield2_??52:1
        DDEADVISE_??52 <>
      else
        ;[...]
      endif
      cfFormat SWORD ?
    DDEADVISE ends

    DDEDATA struct
      ifndef _MAC
        DDEDATA_??53 record unused_??53:12, Bitfield1_??53:1, Bitfield2_??53:1, Bitfield3_??53:1, Bitfield4_??53:1
        DDEDATA_??53 <>
      else
        ;[...]
      endif
      cfFormat SWORD ?
      Value BYTE 1 dup (?)
    DDEDATA ends

    DDEPOKE struct
      ifndef _MAC
        DDEPOKE_??54 record unused_??54:13, Bitfield1_??54:1, Bitfield2_??54:2
        DDEPOKE_??54 <>
      else
        ;[...]
      endif
      cfFormat SWORD ?
      Value BYTE 1 dup (?)
    DDEPOKE ends

    DDELN struct
      ifndef _MAC
        DDELN_??55 record unused_??55:13, Bitfield1_??55:1, Bitfield2_??55:1, Bitfield3_??55:1
        DDELN_??55 <>
      else
        ;[...]
      endif
      cfFormat SWORD ?
    DDELN ends

    DDEUP struct
      ifndef _MAC
        DDEUP_??56 record unused_??56:12, Bitfield1_??56:1, Bitfield2_??56:1, Bitfield3_??56:1, Bitfield4_??56:1
        DDEUP_??56 <>
      else
        ;[...]
      endif
      cfFormat SWORD ?
      rgb BYTE 1 dup (?)
    DDEUP ends

    DdeSetQualityOfService proto WIN_STD_CALL_CONV :HWND, :ptr SECURITY_QUALITY_OF_SERVICE, :PSECURITY_QUALITY_OF_SERVICE
    ImpersonateDdeClientWindow proto WIN_STD_CALL_CONV :HWND, :HWND
    PackDDElParam proto WIN_STD_CALL_CONV :UINT, :UINT_PTR, :UINT_PTR
    UnpackDDElParam proto WIN_STD_CALL_CONV :UINT, :LPARAM, :PUINT_PTR, :PUINT_PTR
    FreeDDElParam proto WIN_STD_CALL_CONV :UINT, :LPARAM
    ReuseDDElParam proto WIN_STD_CALL_CONV :LPARAM, :UINT, :UINT, :UINT_PTR, :UINT_PTR
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if _MSC_VER ge 1200
  endif
endif

