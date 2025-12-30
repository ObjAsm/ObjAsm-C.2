; ==================================================================================================
; Title:      SRP_Globals.inc
; Author:     G. Friedrich
; Purpose:    See SRP.asm
; ==================================================================================================


include SRP_Shared.inc

%CStr szAppTitle, "&APP_TITLE"
%CStr szAboutText,"&ABOUT_TEXT", 13, 10, \
                  "Version &VER_PRODUCTVERSION_STR", 13, 10, \
                  "Designed with ObjAsm", 13, 10, \
                  "© &COPYRIGHT", 13, 10, 13, 10, \ 
                  @CatStr(<!">, %BUILD_DATE_STR, \
                          <  -  Build: >, %BUILD_NUMBER, <->, %ASSEMBLER, <->, \
                          %TARGET_MODE_STR, <->, %BUILD_BITNESS, <!">)
CStr szIcoName,   "ICON_APP"
CStr cError,      "Error"

@DefProto DllImport, GetAdaptersAddresses, WIN_STD_CALL_CONV,, <:DWORD, :DWORD, :DWORD, :POINTER, :POINTER>, 20

if TARGET_STR_TYPE eq STR_TYPE_ANSI
  GetHostName equ gethostname
else
  GetHostName equ GetHostNameW
endif
  
IP_ADAPTER_UNICAST_ADDRESS struct
  Length_              DWORD      ?
  Flags                DWORD      ?
  Next                 QWORD      ?
  Address              SOCKET_ADDRESS <>
  PrefixOrigin         DWORD      ?
  SuffixOrigin         DWORD      ?
  DadState             DWORD      ?
  ValidLifetime        DWORD      ?
  PreferredLifetime    DWORD      ?
  LeaseLifetime        DWORD      ?
  OnLinkPrefixLength   BYTE       ?
  _pad                 BYTE 3 dup(?) ; alignment
IP_ADAPTER_UNICAST_ADDRESS ends

IP_ADAPTER_ADDRESSES struct
  Length_                    DWORD ?
  IfIndex                    DWORD ?

  Next                       QWORD ?
  AdapterName                QWORD ?

  FirstUnicastAddress        QWORD ?
  FirstAnycastAddress        QWORD ?
  FirstMulticastAddress      QWORD ?
  FirstDnsServerAddress      QWORD ?

  DnsSuffix                  PWSTR ?
  Description                PWSTR ?
  FriendlyName               PWSTR ?

  PhysicalAddress            BYTE 8 dup(?)
  PhysicalAddressLength      DWORD ?

  Flags                      DWORD ?
  Mtu                        DWORD ?
  IfType                     DWORD ?
  OperStatus                 DWORD ?

  Ipv6IfIndex                DWORD ?
  ZoneIndices                DWORD 16 dup(?)

  FirstPrefix                QWORD ?
IP_ADAPTER_ADDRESSES ends

