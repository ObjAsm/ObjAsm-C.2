;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\dde.h
;             Created on (UTC) 06/04/2024 06:15:53
;             Last modified on (UTC) 16/12/2023 11:07:52

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
        DDEACK_REC record DDEACK_REC_fAck:1, DDEACK_REC_fBusy:1, DDEACK_REC_reserved:6, DDEACK_REC_bAppReturnCode:8
        DDEACK_BITS DDEACK_REC <>
      else
        ;[...]
      endif
    DDEACK ends
    DDEADVISE struct
      ifndef _MAC
        DDEADVISE_REC record DDEADVISE_REC_fAckReq:1, DDEADVISE_REC_fDeferUpd:1, DDEADVISE_REC_reserved:14
        DDEADVISE_BITS DDEADVISE_REC <>
      else
        ;[...]
      endif
      cfFormat SWORD ?
    DDEADVISE ends
    DDEDATA struct
      ifndef _MAC
        DDEDATA_REC record DDEDATA_REC_fAckReq:1, DDEDATA_REC_reserved:1, DDEDATA_REC_fRelease:1, DDEDATA_REC_fResponse:1, DDEDATA_REC_unused:12
        DDEDATA_BITS DDEDATA_REC <>
      else
        ;[...]
      endif
      cfFormat SWORD ?
      Value BYTE 1 dup (?)
    DDEDATA ends
    DDEPOKE struct
      ifndef _MAC
        DDEPOKE_REC record DDEPOKE_REC_fReserved:2, DDEPOKE_REC_fRelease:1, DDEPOKE_REC_unused:13
        DDEPOKE_BITS DDEPOKE_REC <>
      else
        ;[...]
      endif
      cfFormat SWORD ?
      Value BYTE 1 dup (?)
    DDEPOKE ends
    DDELN struct
      ifndef _MAC
        DDELN_REC record DDELN_REC_fAckReq:1, DDELN_REC_fDeferUpd:1, DDELN_REC_fRelease:1, DDELN_REC_unused:13
        DDELN_BITS DDELN_REC <>
      else
        ;[...]
      endif
      cfFormat SWORD ?
    DDELN ends
    DDEUP struct
      ifndef _MAC
        DDEUP_REC record DDEUP_REC_fAckReq:1, DDEUP_REC_fReserved:1, DDEUP_REC_fRelease:1, DDEUP_REC_fAck:1, DDEUP_REC_unused:12
        DDEUP_BITS DDEUP_REC <>
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
