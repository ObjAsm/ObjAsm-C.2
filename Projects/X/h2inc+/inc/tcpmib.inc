;Include file created by h2inc+ version C.2.0 on (UTC) 15/06/2024 16:37:44
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\tcpmib.h
;             Created on (UTC) 22/05/2024 17:57:06
;             Last modified on (UTC) 21/02/2024 18:15:30

ifndef _TCPMIB_
  _TCPMIB_ equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    ifndef ANY_SIZE
      ANY_SIZE equ 1
    endif
    TCPIP_OWNING_MODULE_SIZE equ 16
    MIB_TCP_STATE typedef SDWORD
    MIB_TCP_STATE_CLOSED equ 1
    MIB_TCP_STATE_LISTEN equ 2
    MIB_TCP_STATE_SYN_SENT equ 3
    MIB_TCP_STATE_SYN_RCVD equ 4
    MIB_TCP_STATE_ESTAB equ 5
    MIB_TCP_STATE_FIN_WAIT1 equ 6
    MIB_TCP_STATE_FIN_WAIT2 equ 7
    MIB_TCP_STATE_CLOSE_WAIT equ 8
    MIB_TCP_STATE_CLOSING equ 9
    MIB_TCP_STATE_LAST_ACK equ 10
    MIB_TCP_STATE_TIME_WAIT equ 11
    MIB_TCP_STATE_DELETE_TCB equ 12
    MIB_TCP_STATE_RESERVED equ 100

    TCP_CONNECTION_OFFLOAD_STATE typedef SDWORD
    TcpConnectionOffloadStateInHost equ 0
    TcpConnectionOffloadStateOffloading equ 1
    TcpConnectionOffloadStateOffloaded equ 2
    TcpConnectionOffloadStateUploading equ 3
    TcpConnectionOffloadStateMax equ 4
    PTCP_CONNECTION_OFFLOAD_STATE typedef ptr TCP_CONNECTION_OFFLOAD_STATE
    MIB_TCPROW_LH struct
      union
        dwState DWORD ?
        State MIB_TCP_STATE ?
      ends
      dwLocalAddr DWORD ?
      dwLocalPort DWORD ?
      dwRemoteAddr DWORD ?
      dwRemotePort DWORD ?
    MIB_TCPROW_LH ends
    _MIB_TCPROW_LH typedef MIB_TCPROW_LH
    PMIB_TCPROW_LH typedef ptr MIB_TCPROW_LH
    MIB_TCPROW_W2K struct
      dwState DWORD ?
      dwLocalAddr DWORD ?
      dwLocalPort DWORD ?
      dwRemoteAddr DWORD ?
      dwRemotePort DWORD ?
    MIB_TCPROW_W2K ends
    _MIB_TCPROW_W2K typedef MIB_TCPROW_W2K
    PMIB_TCPROW_W2K typedef ptr MIB_TCPROW_W2K
    if (NTDDI_VERSION ge NTDDI_VISTA)
      MIB_TCPROW typedef MIB_TCPROW_LH
      PMIB_TCPROW typedef ptr MIB_TCPROW_LH
    elseif (NTDDI_VERSION ge NTDDI_WIN2K)
      MIB_TCPROW typedef MIB_TCPROW_W2K
      PMIB_TCPROW typedef ptr MIB_TCPROW_W2K
    else
      MIB_TCPROW typedef MIB_TCPROW_LH
      PMIB_TCPROW typedef ptr MIB_TCPROW_LH
    endif
    MIB_TCPTABLE struct
      dwNumEntries DWORD ?
      table MIB_TCPROW ANY_SIZE dup (<>)
    MIB_TCPTABLE ends
    _MIB_TCPTABLE typedef MIB_TCPTABLE
    PMIB_TCPTABLE typedef ptr MIB_TCPTABLE
    SIZEOF_TCPTABLE macro X
      exitm <(FIELD_OFFSET(MIB_TCPTABLE, table [ 0 ]) + ((X) * sizeof(MIB_TCPROW)) + ALIGN_SIZE)>
    endm
    MIB_TCPROW2 struct
      dwState DWORD ?
      dwLocalAddr DWORD ?
      dwLocalPort DWORD ?
      dwRemoteAddr DWORD ?
      dwRemotePort DWORD ?
      dwOwningPid DWORD ?
      dwOffloadState TCP_CONNECTION_OFFLOAD_STATE ?
    MIB_TCPROW2 ends
    _MIB_TCPROW2 typedef MIB_TCPROW2
    PMIB_TCPROW2 typedef ptr MIB_TCPROW2
    MIB_TCPTABLE2 struct
      dwNumEntries DWORD ?
      table MIB_TCPROW2 ANY_SIZE dup (<>)
    MIB_TCPTABLE2 ends
    _MIB_TCPTABLE2 typedef MIB_TCPTABLE2
    PMIB_TCPTABLE2 typedef ptr MIB_TCPTABLE2
    SIZEOF_TCPTABLE2 macro X
      exitm <(FIELD_OFFSET(MIB_TCPTABLE2, table [ 0 ]) + ((X) * sizeof(MIB_TCPROW2)) + ALIGN_SIZE)>
    endm
    MIB_TCPROW_OWNER_PID struct
      dwState DWORD ?
      dwLocalAddr DWORD ?
      dwLocalPort DWORD ?
      dwRemoteAddr DWORD ?
      dwRemotePort DWORD ?
      dwOwningPid DWORD ?
    MIB_TCPROW_OWNER_PID ends
    _MIB_TCPROW_OWNER_PID typedef MIB_TCPROW_OWNER_PID
    PMIB_TCPROW_OWNER_PID typedef ptr MIB_TCPROW_OWNER_PID
    MIB_TCPTABLE_OWNER_PID struct
      dwNumEntries DWORD ?
      table MIB_TCPROW_OWNER_PID ANY_SIZE dup (<>)
    MIB_TCPTABLE_OWNER_PID ends
    _MIB_TCPTABLE_OWNER_PID typedef MIB_TCPTABLE_OWNER_PID
    PMIB_TCPTABLE_OWNER_PID typedef ptr MIB_TCPTABLE_OWNER_PID
    SIZEOF_TCPTABLE_OWNER_PID macro X
      exitm <(FIELD_OFFSET(MIB_TCPTABLE_OWNER_PID, table [ 0 ]) + ((X) * sizeof(MIB_TCPROW_OWNER_PID)) + ALIGN_SIZE)>
    endm
    MIB_TCPROW_OWNER_MODULE struct
      dwState DWORD ?
      dwLocalAddr DWORD ?
      dwLocalPort DWORD ?
      dwRemoteAddr DWORD ?
      dwRemotePort DWORD ?
      dwOwningPid DWORD ?
      liCreateTimestamp LARGE_INTEGER <>
      OwningModuleInfo ULONGLONG TCPIP_OWNING_MODULE_SIZE dup (?)
    MIB_TCPROW_OWNER_MODULE ends
    _MIB_TCPROW_OWNER_MODULE typedef MIB_TCPROW_OWNER_MODULE
    PMIB_TCPROW_OWNER_MODULE typedef ptr MIB_TCPROW_OWNER_MODULE
    MIB_TCPTABLE_OWNER_MODULE struct
      dwNumEntries DWORD ?
      table MIB_TCPROW_OWNER_MODULE ANY_SIZE dup (<>)
    MIB_TCPTABLE_OWNER_MODULE ends
    _MIB_TCPTABLE_OWNER_MODULE typedef MIB_TCPTABLE_OWNER_MODULE
    PMIB_TCPTABLE_OWNER_MODULE typedef ptr MIB_TCPTABLE_OWNER_MODULE
    SIZEOF_TCPTABLE_OWNER_MODULE macro X
      exitm <(FIELD_OFFSET(MIB_TCPTABLE_OWNER_MODULE, table [ 0 ]) + ((X) * sizeof(MIB_TCPROW_OWNER_MODULE)) + ALIGN_SIZE)>
    endm
    ifdef _WS2IPDEF_
      MIB_TCP6ROW struct
        State MIB_TCP_STATE ?
        LocalAddr IN6_ADDR <>
        dwLocalScopeId DWORD ?
        dwLocalPort DWORD ?
        RemoteAddr IN6_ADDR <>
        dwRemoteScopeId DWORD ?
        dwRemotePort DWORD ?
      MIB_TCP6ROW ends
      _MIB_TCP6ROW typedef MIB_TCP6ROW
      PMIB_TCP6ROW typedef ptr MIB_TCP6ROW
      MIB_TCP6TABLE struct
        dwNumEntries DWORD ?
        table MIB_TCP6ROW ANY_SIZE dup (<>)
      MIB_TCP6TABLE ends
      _MIB_TCP6TABLE typedef MIB_TCP6TABLE
      PMIB_TCP6TABLE typedef ptr MIB_TCP6TABLE
      SIZEOF_TCP6TABLE macro X
        exitm <(FIELD_OFFSET(MIB_TCP6TABLE, table [ 0 ]) + ((X) * sizeof(MIB_TCP6ROW)) + ALIGN_SIZE)>
      endm
      MIB_TCP6ROW2 struct
        LocalAddr IN6_ADDR <>
        dwLocalScopeId DWORD ?
        dwLocalPort DWORD ?
        RemoteAddr IN6_ADDR <>
        dwRemoteScopeId DWORD ?
        dwRemotePort DWORD ?
        State MIB_TCP_STATE ?
        dwOwningPid DWORD ?
        dwOffloadState TCP_CONNECTION_OFFLOAD_STATE ?
      MIB_TCP6ROW2 ends
      _MIB_TCP6ROW2 typedef MIB_TCP6ROW2
      PMIB_TCP6ROW2 typedef ptr MIB_TCP6ROW2
      MIB_TCP6TABLE2 struct
        dwNumEntries DWORD ?
        table MIB_TCP6ROW2 ANY_SIZE dup (<>)
      MIB_TCP6TABLE2 ends
      _MIB_TCP6TABLE2 typedef MIB_TCP6TABLE2
      PMIB_TCP6TABLE2 typedef ptr MIB_TCP6TABLE2
      SIZEOF_TCP6TABLE2 macro X
        exitm <(FIELD_OFFSET(MIB_TCP6TABLE2, table [ 0 ]) + ((X) * sizeof(MIB_TCP6ROW2)) + ALIGN_SIZE)>
      endm
      MIB_TCP6ROW_OWNER_PID struct
        ucLocalAddr UCHAR 16 dup (?)
        dwLocalScopeId DWORD ?
        dwLocalPort DWORD ?
        ucRemoteAddr UCHAR 16 dup (?)
        dwRemoteScopeId DWORD ?
        dwRemotePort DWORD ?
        dwState DWORD ?
        dwOwningPid DWORD ?
      MIB_TCP6ROW_OWNER_PID ends
      _MIB_TCP6ROW_OWNER_PID typedef MIB_TCP6ROW_OWNER_PID
      PMIB_TCP6ROW_OWNER_PID typedef ptr MIB_TCP6ROW_OWNER_PID
      MIB_TCP6TABLE_OWNER_PID struct
        dwNumEntries DWORD ?
        table MIB_TCP6ROW_OWNER_PID ANY_SIZE dup (<>)
      MIB_TCP6TABLE_OWNER_PID ends
      _MIB_TCP6TABLE_OWNER_PID typedef MIB_TCP6TABLE_OWNER_PID
      PMIB_TCP6TABLE_OWNER_PID typedef ptr MIB_TCP6TABLE_OWNER_PID
      SIZEOF_TCP6TABLE_OWNER_PID macro X
        exitm <(FIELD_OFFSET(MIB_TCP6TABLE_OWNER_PID, table [ 0 ]) + ((X) * sizeof(MIB_TCP6ROW_OWNER_PID)) + ALIGN_SIZE)>
      endm
      MIB_TCP6ROW_OWNER_MODULE struct
        ucLocalAddr UCHAR 16 dup (?)
        dwLocalScopeId DWORD ?
        dwLocalPort DWORD ?
        ucRemoteAddr UCHAR 16 dup (?)
        dwRemoteScopeId DWORD ?
        dwRemotePort DWORD ?
        dwState DWORD ?
        dwOwningPid DWORD ?
        liCreateTimestamp LARGE_INTEGER <>
        OwningModuleInfo ULONGLONG TCPIP_OWNING_MODULE_SIZE dup (?)
      MIB_TCP6ROW_OWNER_MODULE ends
      _MIB_TCP6ROW_OWNER_MODULE typedef MIB_TCP6ROW_OWNER_MODULE
      PMIB_TCP6ROW_OWNER_MODULE typedef ptr MIB_TCP6ROW_OWNER_MODULE
      MIB_TCP6TABLE_OWNER_MODULE struct
        dwNumEntries DWORD ?
        table MIB_TCP6ROW_OWNER_MODULE ANY_SIZE dup (<>)
      MIB_TCP6TABLE_OWNER_MODULE ends
      _MIB_TCP6TABLE_OWNER_MODULE typedef MIB_TCP6TABLE_OWNER_MODULE
      PMIB_TCP6TABLE_OWNER_MODULE typedef ptr MIB_TCP6TABLE_OWNER_MODULE
      SIZEOF_TCP6TABLE_OWNER_MODULE macro X
        exitm <(FIELD_OFFSET(MIB_TCP6TABLE_OWNER_MODULE, table [ 0 ]) + ((X) * sizeof(MIB_TCP6ROW_OWNER_MODULE)) + ALIGN_SIZE)>
      endm
    endif
    MIB_TCP_MAXCONN_DYNAMIC equ (- 1)
    TCP_RTO_ALGORITHM typedef SDWORD
    TcpRtoAlgorithmOther equ 1
    TcpRtoAlgorithmConstant equ 2
    TcpRtoAlgorithmRsre equ 3
    TcpRtoAlgorithmVanj equ 4
    MIB_TCP_RTO_OTHER equ 1
    MIB_TCP_RTO_CONSTANT equ 2
    MIB_TCP_RTO_RSRE equ 3
    MIB_TCP_RTO_VANJ equ 4
    PTCP_RTO_ALGORITHM typedef ptr TCP_RTO_ALGORITHM
    MIB_TCPSTATS_LH struct
      union
        dwRtoAlgorithm DWORD ?
        RtoAlgorithm TCP_RTO_ALGORITHM ?
      ends
      dwRtoMin DWORD ?
      dwRtoMax DWORD ?
      dwMaxConn DWORD ?
      dwActiveOpens DWORD ?
      dwPassiveOpens DWORD ?
      dwAttemptFails DWORD ?
      dwEstabResets DWORD ?
      dwCurrEstab DWORD ?
      dwInSegs DWORD ?
      dwOutSegs DWORD ?
      dwRetransSegs DWORD ?
      dwInErrs DWORD ?
      dwOutRsts DWORD ?
      dwNumConns DWORD ?
    MIB_TCPSTATS_LH ends
    _MIB_TCPSTATS_LH typedef MIB_TCPSTATS_LH
    PMIB_TCPSTATS_LH typedef ptr MIB_TCPSTATS_LH
    MIB_TCPSTATS_W2K struct
      dwRtoAlgorithm DWORD ?
      dwRtoMin DWORD ?
      dwRtoMax DWORD ?
      dwMaxConn DWORD ?
      dwActiveOpens DWORD ?
      dwPassiveOpens DWORD ?
      dwAttemptFails DWORD ?
      dwEstabResets DWORD ?
      dwCurrEstab DWORD ?
      dwInSegs DWORD ?
      dwOutSegs DWORD ?
      dwRetransSegs DWORD ?
      dwInErrs DWORD ?
      dwOutRsts DWORD ?
      dwNumConns DWORD ?
    MIB_TCPSTATS_W2K ends
    _MIB_TCPSTATS_W2K typedef MIB_TCPSTATS_W2K
    PMIB_TCPSTATS_W2K typedef ptr MIB_TCPSTATS_W2K
    if (NTDDI_VERSION ge NTDDI_VISTA)
      MIB_TCPSTATS typedef MIB_TCPSTATS_LH
      PMIB_TCPSTATS typedef ptr MIB_TCPSTATS_LH
    elseif (NTDDI_VERSION ge NTDDI_WIN2K)
      MIB_TCPSTATS typedef MIB_TCPSTATS_W2K
      PMIB_TCPSTATS typedef ptr MIB_TCPSTATS_W2K
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_RS3)
      MIB_TCPSTATS2 struct
        RtoAlgorithm TCP_RTO_ALGORITHM ?
        dwRtoMin DWORD ?
        dwRtoMax DWORD ?
        dwMaxConn DWORD ?
        dwActiveOpens DWORD ?
        dwPassiveOpens DWORD ?
        dwAttemptFails DWORD ?
        dwEstabResets DWORD ?
        dwCurrEstab DWORD ?
        dw64InSegs DWORD64 ?
        dw64OutSegs DWORD64 ?
        dwRetransSegs DWORD ?
        dwInErrs DWORD ?
        dwOutRsts DWORD ?
        dwNumConns DWORD ?
      MIB_TCPSTATS2 ends
      _MIB_TCPSTATS2 typedef MIB_TCPSTATS2
      PMIB_TCPSTATS2 typedef ptr MIB_TCPSTATS2
    endif
  endif
endif
