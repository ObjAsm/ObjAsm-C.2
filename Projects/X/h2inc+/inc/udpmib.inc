;Include file created by h2inc+ version C.2.0 on (UTC) 15/06/2024 16:37:44
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\udpmib.h
;             Created on (UTC) 22/05/2024 17:57:06
;             Last modified on (UTC) 12/02/2024 17:05:30

ifndef _UDPMIB_
  _UDPMIB_ equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    ifndef ANY_SIZE
      ANY_SIZE equ 1
    endif
    TCPIP_OWNING_MODULE_SIZE equ 16
    MIB_UDPROW struct
      dwLocalAddr DWORD ?
      dwLocalPort DWORD ?
    MIB_UDPROW ends
    _MIB_UDPROW typedef MIB_UDPROW
    PMIB_UDPROW typedef ptr MIB_UDPROW
    MIB_UDPTABLE struct
      dwNumEntries DWORD ?
      table MIB_UDPROW ANY_SIZE dup (<>)
    MIB_UDPTABLE ends
    _MIB_UDPTABLE typedef MIB_UDPTABLE
    PMIB_UDPTABLE typedef ptr MIB_UDPTABLE
    SIZEOF_UDPTABLE macro X
      exitm <(FIELD_OFFSET(MIB_UDPTABLE, table [ 0 ]) + ((X) * sizeof(MIB_UDPROW)) + ALIGN_SIZE)>
    endm
    MIB_UDPROW_OWNER_PID struct
      dwLocalAddr DWORD ?
      dwLocalPort DWORD ?
      dwOwningPid DWORD ?
    MIB_UDPROW_OWNER_PID ends
    _MIB_UDPROW_OWNER_PID typedef MIB_UDPROW_OWNER_PID
    PMIB_UDPROW_OWNER_PID typedef ptr MIB_UDPROW_OWNER_PID
    MIB_UDPTABLE_OWNER_PID struct
      dwNumEntries DWORD ?
      table MIB_UDPROW_OWNER_PID ANY_SIZE dup (<>)
    MIB_UDPTABLE_OWNER_PID ends
    _MIB_UDPTABLE_OWNER_PID typedef MIB_UDPTABLE_OWNER_PID
    PMIB_UDPTABLE_OWNER_PID typedef ptr MIB_UDPTABLE_OWNER_PID
    SIZEOF_UDPTABLE_OWNER_PID macro X
      exitm <(FIELD_OFFSET(MIB_UDPTABLE_OWNER_PID, table [ 0 ]) + ((X) * sizeof(MIB_UDPROW_OWNER_PID)) + ALIGN_SIZE)>
    endm
    MIB_UDPROW_OWNER_MODULE struct
      dwLocalAddr DWORD ?
      dwLocalPort DWORD ?
      dwOwningPid DWORD ?
      liCreateTimestamp LARGE_INTEGER <>
      union
        struct
          ANONYMOUS_REC0 record ANONYMOUS_REC0_Filler:31, ANONYMOUS_REC0_SpecificPortBind:1
          ANONYMOUS_REC0 <>
        ends
        dwFlags SDWORD ?
      ends
      OwningModuleInfo ULONGLONG TCPIP_OWNING_MODULE_SIZE dup (?)
    MIB_UDPROW_OWNER_MODULE ends
    _MIB_UDPROW_OWNER_MODULE typedef MIB_UDPROW_OWNER_MODULE
    PMIB_UDPROW_OWNER_MODULE typedef ptr MIB_UDPROW_OWNER_MODULE
    MIB_UDPTABLE_OWNER_MODULE struct
      dwNumEntries DWORD ?
      table MIB_UDPROW_OWNER_MODULE ANY_SIZE dup (<>)
    MIB_UDPTABLE_OWNER_MODULE ends
    _MIB_UDPTABLE_OWNER_MODULE typedef MIB_UDPTABLE_OWNER_MODULE
    PMIB_UDPTABLE_OWNER_MODULE typedef ptr MIB_UDPTABLE_OWNER_MODULE
    SIZEOF_UDPTABLE_OWNER_MODULE macro X
      exitm <(FIELD_OFFSET(MIB_UDPTABLE_OWNER_MODULE, table [ 0 ]) + ((X) * sizeof(MIB_UDPROW_OWNER_MODULE)) + ALIGN_SIZE)>
    endm
    MIB_UDPROW2 struct
      dwLocalAddr DWORD ?
      dwLocalPort DWORD ?
      dwOwningPid DWORD ?
      liCreateTimestamp LARGE_INTEGER <>
      union
        struct
          ANONYMOUS_REC1 record ANONYMOUS_REC1_Filler:31, ANONYMOUS_REC1_SpecificPortBind:1
          ANONYMOUS_REC1 <>
        ends
        dwFlags SDWORD ?
      ends
      OwningModuleInfo ULONGLONG TCPIP_OWNING_MODULE_SIZE dup (?)
      dwRemoteAddr DWORD ?
      dwRemotePort DWORD ?
    MIB_UDPROW2 ends
    _MIB_UDPROW2 typedef MIB_UDPROW2
    PMIB_UDPROW2 typedef ptr MIB_UDPROW2
    MIB_UDPTABLE2 struct
      dwNumEntries DWORD ?
      table MIB_UDPROW2 ANY_SIZE dup (<>)
    MIB_UDPTABLE2 ends
    _MIB_UDPTABLE2 typedef MIB_UDPTABLE2
    PMIB_UDPTABLE2 typedef ptr MIB_UDPTABLE2
    SIZEOF_UDPTABLE2 macro X
      exitm <(FIELD_OFFSET(MIB_UDPTABLE2, table [ 0 ]) + ((X) * sizeof(MIB_UDPROW2)) + ALIGN_SIZE)>
    endm
    ifdef _WS2IPDEF_
      MIB_UDP6ROW struct
        dwLocalAddr IN6_ADDR <>
        dwLocalScopeId DWORD ?
        dwLocalPort DWORD ?
      MIB_UDP6ROW ends
      _MIB_UDP6ROW typedef MIB_UDP6ROW
      PMIB_UDP6ROW typedef ptr MIB_UDP6ROW
      MIB_UDP6TABLE struct
        dwNumEntries DWORD ?
        table MIB_UDP6ROW ANY_SIZE dup (<>)
      MIB_UDP6TABLE ends
      _MIB_UDP6TABLE typedef MIB_UDP6TABLE
      PMIB_UDP6TABLE typedef ptr MIB_UDP6TABLE
      SIZEOF_UDP6TABLE macro X
        exitm <(FIELD_OFFSET(MIB_UDP6TABLE, table [ 0 ]) + ((X) * sizeof(MIB_UDP6ROW)) + ALIGN_SIZE)>
      endm
      MIB_UDP6ROW_OWNER_PID struct
        ucLocalAddr UCHAR 16 dup (?)
        dwLocalScopeId DWORD ?
        dwLocalPort DWORD ?
        dwOwningPid DWORD ?
      MIB_UDP6ROW_OWNER_PID ends
      _MIB_UDP6ROW_OWNER_PID typedef MIB_UDP6ROW_OWNER_PID
      PMIB_UDP6ROW_OWNER_PID typedef ptr MIB_UDP6ROW_OWNER_PID
      MIB_UDP6TABLE_OWNER_PID struct
        dwNumEntries DWORD ?
        table MIB_UDP6ROW_OWNER_PID ANY_SIZE dup (<>)
      MIB_UDP6TABLE_OWNER_PID ends
      _MIB_UDP6TABLE_OWNER_PID typedef MIB_UDP6TABLE_OWNER_PID
      PMIB_UDP6TABLE_OWNER_PID typedef ptr MIB_UDP6TABLE_OWNER_PID
      SIZEOF_UDP6TABLE_OWNER_PID macro X
        exitm <(FIELD_OFFSET(MIB_UDP6TABLE_OWNER_PID, table [ 0 ]) + ((X) * sizeof(MIB_UDP6ROW_OWNER_PID)) + ALIGN_SIZE)>
      endm
      MIB_UDP6ROW_OWNER_MODULE struct
        ucLocalAddr UCHAR 16 dup (?)
        dwLocalScopeId DWORD ?
        dwLocalPort DWORD ?
        dwOwningPid DWORD ?
        liCreateTimestamp LARGE_INTEGER <>
        union
          struct
            ANONYMOUS_REC2 record ANONYMOUS_REC2_Filler:31, ANONYMOUS_REC2_SpecificPortBind:1
            ANONYMOUS_REC2 <>
          ends
          dwFlags SDWORD ?
        ends
        OwningModuleInfo ULONGLONG TCPIP_OWNING_MODULE_SIZE dup (?)
      MIB_UDP6ROW_OWNER_MODULE ends
      _MIB_UDP6ROW_OWNER_MODULE typedef MIB_UDP6ROW_OWNER_MODULE
      PMIB_UDP6ROW_OWNER_MODULE typedef ptr MIB_UDP6ROW_OWNER_MODULE
      MIB_UDP6TABLE_OWNER_MODULE struct
        dwNumEntries DWORD ?
        table MIB_UDP6ROW_OWNER_MODULE ANY_SIZE dup (<>)
      MIB_UDP6TABLE_OWNER_MODULE ends
      _MIB_UDP6TABLE_OWNER_MODULE typedef MIB_UDP6TABLE_OWNER_MODULE
      PMIB_UDP6TABLE_OWNER_MODULE typedef ptr MIB_UDP6TABLE_OWNER_MODULE
      SIZEOF_UDP6TABLE_OWNER_MODULE macro X
        exitm <(FIELD_OFFSET(MIB_UDP6TABLE_OWNER_MODULE, table [ 0 ]) + ((X) * sizeof(MIB_UDP6ROW_OWNER_MODULE)) + ALIGN_SIZE)>
      endm
      MIB_UDP6ROW2 struct
        ucLocalAddr UCHAR 16 dup (?)
        dwLocalScopeId DWORD ?
        dwLocalPort DWORD ?
        dwOwningPid DWORD ?
        liCreateTimestamp LARGE_INTEGER <>
        union
          struct
            ANONYMOUS_REC3 record ANONYMOUS_REC3_Filler:31, ANONYMOUS_REC3_SpecificPortBind:1
            ANONYMOUS_REC3 <>
          ends
          dwFlags SDWORD ?
        ends
        OwningModuleInfo ULONGLONG TCPIP_OWNING_MODULE_SIZE dup (?)
        ucRemoteAddr UCHAR 16 dup (?)
        dwRemoteScopeId DWORD ?
        dwRemotePort DWORD ?
      MIB_UDP6ROW2 ends
      _MIB_UDP6ROW2 typedef MIB_UDP6ROW2
      PMIB_UDP6ROW2 typedef ptr MIB_UDP6ROW2
      MIB_UDP6TABLE2 struct
        dwNumEntries DWORD ?
        table MIB_UDP6ROW2 ANY_SIZE dup (<>)
      MIB_UDP6TABLE2 ends
      _MIB_UDP6TABLE2 typedef MIB_UDP6TABLE2
      PMIB_UDP6TABLE2 typedef ptr MIB_UDP6TABLE2
      SIZEOF_UDP6TABLE2 macro X
        exitm <(FIELD_OFFSET(MIB_UDP6TABLE2, table [ 0 ]) + ((X) * sizeof(MIB_UDP6ROW2)) + ALIGN_SIZE)>
      endm
    endif
    MIB_UDPSTATS struct
      dwInDatagrams DWORD ?
      dwNoPorts DWORD ?
      dwInErrors DWORD ?
      dwOutDatagrams DWORD ?
      dwNumAddrs DWORD ?
    MIB_UDPSTATS ends
    _MIB_UDPSTATS typedef MIB_UDPSTATS
    PMIB_UDPSTATS typedef ptr MIB_UDPSTATS
    if (NTDDI_VERSION ge NTDDI_WIN10_RS3)
      MIB_UDPSTATS2 struct
        dw64InDatagrams DWORD64 ?
        dwNoPorts DWORD ?
        dwInErrors DWORD ?
        dw64OutDatagrams DWORD64 ?
        dwNumAddrs DWORD ?
      MIB_UDPSTATS2 ends
      _MIB_UDPSTATS2 typedef MIB_UDPSTATS2
      PMIB_UDPSTATS2 typedef ptr MIB_UDPSTATS2
    endif
  endif
endif
