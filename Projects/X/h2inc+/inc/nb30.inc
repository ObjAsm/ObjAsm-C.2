;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\nb30.h
;             Created on (UTC) 06/04/2024 06:15:57
;             Last modified on (UTC) 16/12/2023 11:05:36

ifndef NCB_INCLUDED
  NCB_INCLUDED equ <>
  if _MSC_VER gt 1000
  endif
  include winapifamily.inc
  ifdef __cplusplus
    ;[...]
  endif
  if _MSC_VER ge 1200
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    NCBNAMSZ equ 16
    MAX_LANA equ 254
    NCB struct
      ncb_command UCHAR ?
      ncb_retcode UCHAR ?
      ncb_lsn UCHAR ?
      ncb_num UCHAR ?
      ncb_buffer PUCHAR ?
      ncb_length WORD ?
      ncb_callname UCHAR NCBNAMSZ dup (?)
      ncb_name UCHAR NCBNAMSZ dup (?)
      ncb_rto UCHAR ?
      ncb_sto UCHAR ?
      TYPE_ncb_post typedef proto WIN_STD_CALL_CONV :ptr _NCB
      ncb_post typedef ptr TYPE_ncb_post

      ncb_lana_num UCHAR ?
      ncb_cmd_cplt UCHAR ?
      ifdef _WIN64
        ncb_reserve UCHAR 18 dup (?)
      else
        ncb_reserve UCHAR 10 dup (?)
      endif
      ncb_event HANDLE ?
    NCB ends
    _NCB typedef NCB
    PNCB typedef ptr NCB
    ADAPTER_STATUS struct
      adapter_address UCHAR 6 dup (?)
      rev_major UCHAR ?
      reserved0 UCHAR ?
      adapter_type UCHAR ?
      rev_minor UCHAR ?
      duration WORD ?
      frmr_recv WORD ?
      frmr_xmit WORD ?
      iframe_recv_err WORD ?
      xmit_aborts WORD ?
      xmit_success DWORD ?
      recv_success DWORD ?
      iframe_xmit_err WORD ?
      recv_buff_unavail WORD ?
      t1_timeouts WORD ?
      ti_timeouts WORD ?
      reserved1 DWORD ?
      free_ncbs WORD ?
      max_cfg_ncbs WORD ?
      max_ncbs WORD ?
      xmit_buf_unavail WORD ?
      max_dgram_size WORD ?
      pending_sess WORD ?
      max_cfg_sess WORD ?
      max_sess WORD ?
      max_sess_pkt_size WORD ?
      name_count WORD ?
    ADAPTER_STATUS ends
    _ADAPTER_STATUS typedef ADAPTER_STATUS
    PADAPTER_STATUS typedef ptr ADAPTER_STATUS
    NAME_BUFFER struct
      name_ UCHAR NCBNAMSZ dup (?)
      name_num UCHAR ?
      name_flags UCHAR ?
    NAME_BUFFER ends
    _NAME_BUFFER typedef NAME_BUFFER
    PNAME_BUFFER typedef ptr NAME_BUFFER
    NAME_FLAGS_MASK equ 87h
    GROUP_NAME equ 80h
    UNIQUE_NAME equ 00h
    REGISTERING equ 00h
    REGISTERED equ 04h
    DEREGISTERED equ 05h
    DUPLICATE equ 06h
    DUPLICATE_DEREG equ 07h
    SESSION_HEADER struct
      sess_name UCHAR ?
      num_sess UCHAR ?
      rcv_dg_outstanding UCHAR ?
      rcv_any_outstanding UCHAR ?
    SESSION_HEADER ends
    _SESSION_HEADER typedef SESSION_HEADER
    PSESSION_HEADER typedef ptr SESSION_HEADER
    SESSION_BUFFER struct
      lsn UCHAR ?
      state UCHAR ?
      local_name UCHAR NCBNAMSZ dup (?)
      remote_name UCHAR NCBNAMSZ dup (?)
      rcvs_outstanding UCHAR ?
      sends_outstanding UCHAR ?
    SESSION_BUFFER ends
    _SESSION_BUFFER typedef SESSION_BUFFER
    PSESSION_BUFFER typedef ptr SESSION_BUFFER
    LISTEN_OUTSTANDING equ 01h
    CALL_PENDING equ 02h
    SESSION_ESTABLISHED equ 03h
    HANGUP_PENDING equ 04h
    HANGUP_COMPLETE equ 05h
    SESSION_ABORTED equ 06h
    LANA_ENUM struct
      length_ UCHAR ?
      lana UCHAR MAX_LANA + 1 dup (?)
    LANA_ENUM ends
    _LANA_ENUM typedef LANA_ENUM
    PLANA_ENUM typedef ptr LANA_ENUM
    FIND_NAME_HEADER struct
      node_count WORD ?
      reserved UCHAR ?
      unique_group UCHAR ?
    FIND_NAME_HEADER ends
    _FIND_NAME_HEADER typedef FIND_NAME_HEADER
    PFIND_NAME_HEADER typedef ptr FIND_NAME_HEADER
    FIND_NAME_BUFFER struct
      length_ UCHAR ?
      access_control UCHAR ?
      frame_control UCHAR ?
      destination_addr UCHAR 6 dup (?)
      source_addr UCHAR 6 dup (?)
      routing_info UCHAR 18 dup (?)
    FIND_NAME_BUFFER ends
    _FIND_NAME_BUFFER typedef FIND_NAME_BUFFER
    PFIND_NAME_BUFFER typedef ptr FIND_NAME_BUFFER
    ACTION_HEADER struct
      transport_id ULONG ?
      action_code USHORT ?
      reserved USHORT ?
    ACTION_HEADER ends
    _ACTION_HEADER typedef ACTION_HEADER
    PACTION_HEADER typedef ptr ACTION_HEADER
    ALL_TRANSPORTS equ <"M",0o,0o,0o>
    MS_NBF equ <"MNBF">
    NCBCALL equ 10h
    NCBLISTEN equ 11h
    NCBHANGUP equ 12h
    NCBSEND equ 14h
    NCBRECV equ 15h
    NCBRECVANY equ 16h
    NCBCHAINSEND equ 17h
    NCBDGSEND equ 20h
    NCBDGRECV equ 21h
    NCBDGSENDBC equ 22h
    NCBDGRECVBC equ 23h
    NCBADDNAME equ 30h
    NCBDELNAME equ 31h
    NCBRESET equ 32h
    NCBASTAT equ 33h
    NCBSSTAT equ 34h
    NCBCANCEL equ 35h
    NCBADDGRNAME equ 36h
    NCBENUM equ 37h
    NCBUNLINK equ 70h
    NCBSENDNA equ 71h
    NCBCHAINSENDNA equ 72h
    NCBLANSTALERT equ 73h
    NCBACTION equ 77h
    NCBFINDNAME equ 78h
    NCBTRACE equ 79h
    ASYNCH equ 80h
    NRC_GOODRET equ 00h
    NRC_BUFLEN equ 01h
    NRC_ILLCMD equ 03h
    NRC_CMDTMO equ 05h
    NRC_INCOMP equ 06h
    NRC_BADDR equ 07h
    NRC_SNUMOUT equ 08h
    NRC_NORES equ 09h
    NRC_SCLOSED equ 0ah
    NRC_CMDCAN equ 0bh
    NRC_DUPNAME equ 0dh
    NRC_NAMTFUL equ 0eh
    NRC_ACTSES equ 0fh
    NRC_LOCTFUL equ 11h
    NRC_REMTFUL equ 12h
    NRC_ILLNN equ 13h
    NRC_NOCALL equ 14h
    NRC_NOWILD equ 15h
    NRC_INUSE equ 16h
    NRC_NAMERR equ 17h
    NRC_SABORT equ 18h
    NRC_NAMCONF equ 19h
    NRC_IFBUSY equ 21h
    NRC_TOOMANY equ 22h
    NRC_BRIDGE equ 23h
    NRC_CANOCCR equ 24h
    NRC_CANCEL equ 26h
    NRC_DUPENV equ 30h
    NRC_ENVNOTDEF equ 34h
    NRC_OSRESNOTAV equ 35h
    NRC_MAXAPPS equ 36h
    NRC_NOSAPS equ 37h
    NRC_NORESOURCES equ 38h
    NRC_INVADDRESS equ 39h
    NRC_INVDDID equ 3Bh
    NRC_LOCKFAIL equ 3Ch
    NRC_OPENERR equ 3fh
    NRC_SYSTEM equ 40h
    NRC_PENDING equ 0ffh
    Netbios proto WIN_STD_CALL_CONV :PNCB
    NCB_POST equ <void CALLBACK>
  endif
  if _MSC_VER ge 1200
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
