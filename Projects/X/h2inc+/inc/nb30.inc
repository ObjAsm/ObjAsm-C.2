;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
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
    ; padding added after data member
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ;****************************************************************
    ;*                                                              *
    ;*              Data structure templates                        *
    ;*                                                              *
    ;****************************************************************
    ;* absolute length of a net name           *
    NCBNAMSZ equ 16
    ;* lana's in range 0 to MAX_LANA inclusive *
    MAX_LANA equ 254
    ;*
    ;* Network Control Block
    ;*
    NCB struct
      ncb_command BYTE ?
      ;* command code                   *
      ncb_retcode BYTE ?
      ;* return code                    *
      ncb_lsn BYTE ?
      ;* local session number           *
      ncb_num BYTE ?
      ;* number of our network name     *
      ncb_buffer PUCHAR ?
      ;* address of message buffer      *
      ncb_length WORD ?
      ;* size of message buffer         *
      ncb_callname BYTE NCBNAMSZ dup (?)
      ;* blank-padded name of remote    *
      ncb_name BYTE NCBNAMSZ dup (?)
      ;* our blank-padded netname       *
      ncb_rto BYTE ?
      ;* rcv timeout/retry count        *
      ncb_sto BYTE ?
      ;* send timeout/sys timeout       *
      TYPE_ncb_post typedef proto WIN_STD_CALL_CONV :ptr _NCB
      ncb_post typedef ptr TYPE_ncb_post

      ;* POST routine address        *
      ncb_lana_num BYTE ?
      ;* lana (adapter) number          *
      ncb_cmd_cplt BYTE ?
      ;* 0xff => commmand pending       *
      ifdef _WIN64
        ncb_reserve BYTE 18 dup (?)
        ;* reserved, used by BIOS         *
      else
        ncb_reserve BYTE 10 dup (?)
        ;* reserved, used by BIOS         *
      endif
      ncb_event HANDLE ?
      ;* HANDLE to Win32 event which    *
      ;* will be set to the signalled   *
      ;* state when an ASYNCH command   *
      ;* completes                      *
    NCB ends
    _NCB typedef NCB
    PNCB typedef ptr NCB
    ;*
    ;*  Structure returned to the NCB command NCBASTAT is ADAPTER_STATUS followed
    ;*  by an array of NAME_BUFFER structures.
    ;*
    ADAPTER_STATUS struct
      adapter_address BYTE 6 dup (?)
      rev_major BYTE ?
      reserved0 BYTE ?
      adapter_type BYTE ?
      rev_minor BYTE ?
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
      name_ BYTE NCBNAMSZ dup (?)
      name_num BYTE ?
      name_flags BYTE ?
    NAME_BUFFER ends
    _NAME_BUFFER typedef NAME_BUFFER
    PNAME_BUFFER typedef ptr NAME_BUFFER
    ;  values for name_flags bits.
    NAME_FLAGS_MASK equ 87h
    GROUP_NAME equ 80h
    UNIQUE_NAME equ 00h
    REGISTERING equ 00h
    REGISTERED equ 04h
    DEREGISTERED equ 05h
    DUPLICATE equ 06h
    DUPLICATE_DEREG equ 07h
    ;*
    ;*  Structure returned to the NCB command NCBSSTAT is SESSION_HEADER followed
    ;*  by an array of SESSION_BUFFER structures. If the NCB_NAME starts with an
    ;*  asterisk then an array of these structures is returned containing the
    ;*  status for all names.
    ;*
    SESSION_HEADER struct
      sess_name BYTE ?
      num_sess BYTE ?
      rcv_dg_outstanding BYTE ?
      rcv_any_outstanding BYTE ?
    SESSION_HEADER ends
    _SESSION_HEADER typedef SESSION_HEADER
    PSESSION_HEADER typedef ptr SESSION_HEADER
    SESSION_BUFFER struct
      lsn BYTE ?
      state BYTE ?
      local_name BYTE NCBNAMSZ dup (?)
      remote_name BYTE NCBNAMSZ dup (?)
      rcvs_outstanding BYTE ?
      sends_outstanding BYTE ?
    SESSION_BUFFER ends
    _SESSION_BUFFER typedef SESSION_BUFFER
    PSESSION_BUFFER typedef ptr SESSION_BUFFER
    ;  Values for state
    LISTEN_OUTSTANDING equ 01h
    CALL_PENDING equ 02h
    SESSION_ESTABLISHED equ 03h
    HANGUP_PENDING equ 04h
    HANGUP_COMPLETE equ 05h
    SESSION_ABORTED equ 06h
    ;*
    ;*  Structure returned to the NCB command NCBENUM.
    ;*
    ;*  On a system containing lana's 0, 2 and 3, a structure with
    ;*  length =3, lana[0]=0, lana[1]=2 and lana[2]=3 will be returned.
    ;*
    LANA_ENUM struct
      length_ BYTE ?
      ;  Number of valid entries in lana[]
      lana BYTE MAX_LANA + 1 dup (?)
    LANA_ENUM ends
    _LANA_ENUM typedef LANA_ENUM
    PLANA_ENUM typedef ptr LANA_ENUM
    ;*
    ;*  Structure returned to the NCB command NCBFINDNAME is FIND_NAME_HEADER followed
    ;*  by an array of FIND_NAME_BUFFER structures.
    ;*
    FIND_NAME_HEADER struct
      node_count WORD ?
      reserved BYTE ?
      unique_group BYTE ?
    FIND_NAME_HEADER ends
    _FIND_NAME_HEADER typedef FIND_NAME_HEADER
    PFIND_NAME_HEADER typedef ptr FIND_NAME_HEADER
    FIND_NAME_BUFFER struct
      length_ BYTE ?
      access_control BYTE ?
      frame_control BYTE ?
      destination_addr BYTE 6 dup (?)
      source_addr BYTE 6 dup (?)
      routing_info BYTE 18 dup (?)
    FIND_NAME_BUFFER ends
    _FIND_NAME_BUFFER typedef FIND_NAME_BUFFER
    PFIND_NAME_BUFFER typedef ptr FIND_NAME_BUFFER
    ;*
    ;*  Structure provided with NCBACTION. The purpose of NCBACTION is to provide
    ;*  transport specific extensions to netbios.
    ;*
    ACTION_HEADER struct
      transport_id DWORD ?
      action_code WORD ?
      reserved WORD ?
    ACTION_HEADER ends
    _ACTION_HEADER typedef ACTION_HEADER
    PACTION_HEADER typedef ptr ACTION_HEADER
    ;  Values for transport_id
    ALL_TRANSPORTS equ <"M",0o,0o,0o>
    MS_NBF equ <"MNBF">
    ;****************************************************************
    ;*                                                              *
    ;*              Special values and constants                    *
    ;*                                                              *
    ;****************************************************************
    ;*
    ;*      NCB Command codes
    ;*
    ;* NCB CALL                           *
    NCBCALL equ 10h
    ;* NCB LISTEN                         *
    NCBLISTEN equ 11h
    ;* NCB HANG UP                        *
    NCBHANGUP equ 12h
    ;* NCB SEND                           *
    NCBSEND equ 14h
    ;* NCB RECEIVE                        *
    NCBRECV equ 15h
    ;* NCB RECEIVE ANY                    *
    NCBRECVANY equ 16h
    ;* NCB CHAIN SEND                     *
    NCBCHAINSEND equ 17h
    ;* NCB SEND DATAGRAM                  *
    NCBDGSEND equ 20h
    ;* NCB RECEIVE DATAGRAM               *
    NCBDGRECV equ 21h
    ;* NCB SEND BROADCAST DATAGRAM        *
    NCBDGSENDBC equ 22h
    ;* NCB RECEIVE BROADCAST DATAGRAM     *
    NCBDGRECVBC equ 23h
    ;* NCB ADD NAME                       *
    NCBADDNAME equ 30h
    ;* NCB DELETE NAME                    *
    NCBDELNAME equ 31h
    ;* NCB RESET                          *
    NCBRESET equ 32h
    ;* NCB ADAPTER STATUS                 *
    NCBASTAT equ 33h
    ;* NCB SESSION STATUS                 *
    NCBSSTAT equ 34h
    ;* NCB CANCEL                         *
    NCBCANCEL equ 35h
    ;* NCB ADD GROUP NAME                 *
    NCBADDGRNAME equ 36h
    ;* NCB ENUMERATE LANA NUMBERS         *
    NCBENUM equ 37h
    ;* NCB UNLINK                         *
    NCBUNLINK equ 70h
    ;* NCB SEND NO ACK                    *
    NCBSENDNA equ 71h
    ;* NCB CHAIN SEND NO ACK              *
    NCBCHAINSENDNA equ 72h
    ;* NCB LAN STATUS ALERT               *
    NCBLANSTALERT equ 73h
    ;* NCB ACTION                         *
    NCBACTION equ 77h
    ;* NCB FIND NAME                      *
    NCBFINDNAME equ 78h
    ;* NCB TRACE                          *
    NCBTRACE equ 79h
    ;* high bit set == asynchronous       *
    ASYNCH equ 80h
    ;*
    ;*      NCB Return codes
    ;*
    ;* good return                                *
    NRC_GOODRET equ 00h
    ;* also returned when ASYNCH request accepted *
    ;* illegal buffer length                      *
    NRC_BUFLEN equ 01h
    ;* illegal command                            *
    NRC_ILLCMD equ 03h
    ;* command timed out                          *
    NRC_CMDTMO equ 05h
    ;* message incomplete, issue another command  *
    NRC_INCOMP equ 06h
    ;* illegal buffer address                     *
    NRC_BADDR equ 07h
    ;* session number out of range                *
    NRC_SNUMOUT equ 08h
    ;* no resource available                      *
    NRC_NORES equ 09h
    ;* session closed                             *
    NRC_SCLOSED equ 0ah
    ;* command cancelled                          *
    NRC_CMDCAN equ 0bh
    ;* duplicate name                             *
    NRC_DUPNAME equ 0dh
    ;* name table full                            *
    NRC_NAMTFUL equ 0eh
    ;* no deletions, name has active sessions     *
    NRC_ACTSES equ 0fh
    ;* local session table full                   *
    NRC_LOCTFUL equ 11h
    ;* remote session table full                  *
    NRC_REMTFUL equ 12h
    ;* illegal name number                        *
    NRC_ILLNN equ 13h
    ;* no callname                                *
    NRC_NOCALL equ 14h
    ;* cannot put * in NCB_NAME                   *
    NRC_NOWILD equ 15h
    ;* name in use on remote adapter              *
    NRC_INUSE equ 16h
    ;* name deleted                               *
    NRC_NAMERR equ 17h
    ;* session ended abnormally                   *
    NRC_SABORT equ 18h
    ;* name conflict detected                     *
    NRC_NAMCONF equ 19h
    ;* interface busy, IRET before retrying       *
    NRC_IFBUSY equ 21h
    ;* too many commands outstanding, retry later *
    NRC_TOOMANY equ 22h
    ;* ncb_lana_num field invalid                 *
    NRC_BRIDGE equ 23h
    ;* command completed while cancel occurring   *
    NRC_CANOCCR equ 24h
    ;* command not valid to cancel                *
    NRC_CANCEL equ 26h
    ;* name defined by anther local process       *
    NRC_DUPENV equ 30h
    ;* environment undefined. RESET required      *
    NRC_ENVNOTDEF equ 34h
    ;* required OS resources exhausted            *
    NRC_OSRESNOTAV equ 35h
    ;* max number of applications exceeded        *
    NRC_MAXAPPS equ 36h
    ;* no saps available for netbios              *
    NRC_NOSAPS equ 37h
    ;* requested resources are not available      *
    NRC_NORESOURCES equ 38h
    ;* invalid ncb address or length > segment    *
    NRC_INVADDRESS equ 39h
    ;* invalid NCB DDID                           *
    NRC_INVDDID equ 3Bh
    ;* lock of user area failed                   *
    NRC_LOCKFAIL equ 3Ch
    ;* NETBIOS not loaded                         *
    NRC_OPENERR equ 3fh
    ;* system error                               *
    NRC_SYSTEM equ 40h
    ;* asynchronous command is not yet finished   *
    NRC_PENDING equ 0ffh
    ;****************************************************************
    ;*                                                              *
    ;*              main user entry point for NetBIOS 3.0           *
    ;*                                                              *
    ;* Usage: result = Netbios( pncb );                             *
    ;****************************************************************
    Netbios proto WIN_STD_CALL_CONV :PNCB
    ;****************************************************************
    ;*                                                              *
    ;*              Prefix for callback routines                    *
    ;*                                                              *
    ;* Usage in a declaration: NCB_POST MyPostRoutine( PNCB pncb ); *
    ;****************************************************************
    NCB_POST equ <void CALLBACK>
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  if _MSC_VER ge 1200
  endif
  ifdef __cplusplus
    ;[...]
  endif
  ;* NCB_INCLUDED *
endif
