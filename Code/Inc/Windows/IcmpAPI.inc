;Include file created by h2incX, Version C.01.00, 30/12/2022 22:28
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'IcmpAPI.h', last modified: 13/10/2022 20:07


ifndef _ICMP_INCLUDED_
  _ICMP_INCLUDED_ equ <>
  if _MSC_VER gt 1000
  endif
  include winapifamily.inc
  ifndef IPHLPAPI_DLL_LINKAGE
    ifdef DECLSPEC_IMPORT
      IPHLPAPI_DLL_LINKAGE equ <DECLSPEC_IMPORT>
    else
      IPHLPAPI_DLL_LINKAGE equ <>
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    ifdef __cplusplus
      ;[...]
    endif
    @DefProto DllImport, IcmpCreateFile, WIN_STD_CALL_CONV,, <>, 0
    if (NTDDI_VERSION ge NTDDI_WINXP)
      @DefProto DllImport, Icmp6CreateFile, WIN_STD_CALL_CONV,, <>, 0
    endif
    @DefProto DllImport, IcmpCloseHandle, WIN_STD_CALL_CONV,, <:HANDLE>, 4
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, IcmpSendEcho, WIN_STD_CALL_CONV,, <:HANDLE, :IPAddr, :LPVOID, :WORD, :PIP_OPTION_INFORMATION, :LPVOID, :DWORD, :DWORD>, 32
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    ifdef PIO_APC_ROUTINE_DEFINED
      @DefProto DllImport, IcmpSendEcho2, WIN_STD_CALL_CONV,, <:HANDLE, :HANDLE, :PIO_APC_ROUTINE, :PVOID, :IPAddr, :LPVOID, :WORD, :PIP_OPTION_INFORMATION, :LPVOID, :DWORD, :DWORD>, 48
    else
      @DefProto DllImport, IcmpSendEcho2, WIN_STD_CALL_CONV,, <:HANDLE, :HANDLE, :FARPROC, :PVOID, :IPAddr, :LPVOID, :WORD, :PIP_OPTION_INFORMATION, :LPVOID, :DWORD, :DWORD>, 48
    endif
     
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    if (NTDDI_VERSION ge NTDDI_VISTASP1)
      ifdef PIO_APC_ROUTINE_DEFINED
        @DefProto DllImport, IcmpSendEcho2Ex, WIN_STD_CALL_CONV,, <:HANDLE, :HANDLE, :PIO_APC_ROUTINE, :PVOID, :IPAddr, :IPAddr, :LPVOID, :WORD, :PIP_OPTION_INFORMATION, :LPVOID, :DWORD, :DWORD>, 52
      else
        @DefProto DllImport, IcmpSendEcho2Ex, WIN_STD_CALL_CONV,, <:HANDLE, :HANDLE, :FARPROC, :PVOID, :IPAddr, :IPAddr, :LPVOID, :WORD, :PIP_OPTION_INFORMATION, :LPVOID, :DWORD, :DWORD>, 52
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    if (NTDDI_VERSION ge NTDDI_WINXP)
      ifdef PIO_APC_ROUTINE_DEFINED
        @DefProto DllImport, Icmp6SendEcho2, WIN_STD_CALL_CONV,, <:HANDLE, :HANDLE, :PIO_APC_ROUTINE, :PVOID, :ptr sockaddr_in6, :ptr sockaddr_in6, :LPVOID, :WORD, :PIP_OPTION_INFORMATION, :LPVOID, :DWORD, :DWORD>, 52
      else
        @DefProto DllImport, Icmp6SendEcho2, WIN_STD_CALL_CONV,, <:HANDLE, :HANDLE, :FARPROC, :PVOID, :ptr sockaddr_in6, :ptr sockaddr_in6, :LPVOID, :WORD, :PIP_OPTION_INFORMATION, :LPVOID, :DWORD, :DWORD>, 52
      endif
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    @DefProto DllImport, IcmpParseReplies, WIN_STD_CALL_CONV,, <:LPVOID, :DWORD>, 8
    if (NTDDI_VERSION ge NTDDI_WINXP)
      @DefProto DllImport, Icmp6ParseReplies, WIN_STD_CALL_CONV,, <:LPVOID, :DWORD>, 8
    endif
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    ifdef __cplusplus
      ;[...]
    endif
  endif
endif
 