;Include file created by h2inc+ version C.2.0 on (UTC) 15/06/2024 16:37:44
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\ifmib.h
;             Created on (UTC) 22/05/2024 17:57:07
;             Last modified on (UTC) 08/01/2024 17:04:20

ifndef _IFMIB_
  _IFMIB_ equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    include ifdef.inc
    ifndef ANY_SIZE
      ANY_SIZE equ 1
    endif
    MIB_IFNUMBER struct
      dwValue DWORD ?
    MIB_IFNUMBER ends
    _MIB_IFNUMBER typedef MIB_IFNUMBER
    PMIB_IFNUMBER typedef ptr MIB_IFNUMBER
    MAXLEN_PHYSADDR equ 8
    MAXLEN_IFDESCR equ 256
    MAX_INTERFACE_NAME_LEN equ 256
    MIB_IFROW struct
      wszName WCHAR MAX_INTERFACE_NAME_LEN dup (?)
      dwIndex IF_INDEX ?
      dwType IFTYPE ?
      dwMtu DWORD ?
      dwSpeed DWORD ?
      dwPhysAddrLen DWORD ?
      bPhysAddr UCHAR MAXLEN_PHYSADDR dup (?)
      dwAdminStatus DWORD ?
      dwOperStatus INTERNAL_IF_OPER_STATUS ?
      dwLastChange DWORD ?
      dwInOctets DWORD ?
      dwInUcastPkts DWORD ?
      dwInNUcastPkts DWORD ?
      dwInDiscards DWORD ?
      dwInErrors DWORD ?
      dwInUnknownProtos DWORD ?
      dwOutOctets DWORD ?
      dwOutUcastPkts DWORD ?
      dwOutNUcastPkts DWORD ?
      dwOutDiscards DWORD ?
      dwOutErrors DWORD ?
      dwOutQLen DWORD ?
      dwDescrLen DWORD ?
      bDescr UCHAR MAXLEN_IFDESCR dup (?)
    MIB_IFROW ends
    _MIB_IFROW typedef MIB_IFROW
    PMIB_IFROW typedef ptr MIB_IFROW
    MIB_IFTABLE struct
      dwNumEntries DWORD ?
      table MIB_IFROW ANY_SIZE dup (<>)
    MIB_IFTABLE ends
    _MIB_IFTABLE typedef MIB_IFTABLE
    PMIB_IFTABLE typedef ptr MIB_IFTABLE
    SIZEOF_IFTABLE macro X
      exitm <(FIELD_OFFSET(MIB_IFTABLE, table [ 0 ]) + ((X) * sizeof(MIB_IFROW)) + ALIGN_SIZE)>
    endm
  endif
endif
