; ==================================================================================================
; Title:      SRP.asm
; Author:     G. Friedrich
; Version:    C.2.0
; Purpose:    ObjAsm Simple Reverse Proxy application.
; Notes:      Version C.2.0, December 2025
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Summary:
;   This code implement a minimal bidirectional TCP reverse proxy using the NetCom engine.
;   The system provides a Windows SDI GUI for configuring local host and destination addresses and
;   ports, controlling the reverse proxy, and monitoring runtime state.
;
;   The Application object manages the dialog lifecycle, initializes and finalizes the embedded 
;   NetComEngine, validates user input, populates local IP addresses, and enables/disables UI 
;   controls dynamically. Runtime flags track the application state (e.g., running or idle), 
;   while event handlers respond to Start, Stop, and Cancel commands.
;
;   The NetComReverseProxyProtocol object implements the core reverse proxy logic. It pairs 
;   client and server connections, forwards data bidirectionally, and ensures proper cleanup 
;   on disconnection. Memory allocation for protocol data, data completeness checks, and queueing 
;   of transmitted data are fully encapsulated. 
;
;   Together, these modules provide a robust, minimal reverse proxy setup capable of streaming 
;   data between clients and servers while maintaining consistent GUI and network state.
;
; --------------------------------------------------------------------------------------------------


WIN32_LEAN_AND_MEAN         equ 1                       ;Exclude rarely-used Windows headers
INCL_WINSOCK_API_PROTOTYPES equ 1                       ;Enable WinSock API prototypes

PROTOCOL_WND_NAME           textequ <Server Protocol>   ;Debug/protocol window title
INTERNET_PROTOCOL_VERSION   equ 4                       ;Select IP version (4 or 6)

% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIN64, ANSI_STRING;, DEBUG(WND)            ;Load OOP files and OS related objects

% include &MacPath&fMath.inc                            ;Floating-point math helpers
% include &MacPath&SDLL.inc                             ;Linked List support macros

% include &IncPath&Windows\WinSock2.inc                 ;WinSock core definitions
% include &IncPath&Windows\ws2ipdef.inc                 ;IP protocol definitions
% include &IncPath&Windows\ws2tcpip.inc                 ;TCP/IP helper APIs
;% include &IncPath&Windows\iphlpapi.inc

% include &IncPath&Windows\ShellApi.inc                 ;Shell API declarations
% include &IncPath&Windows\CommCtrl.inc                 ;Common controls support

% includelib &LibPath&Windows\Ws2_32.lib                ;WinSock 2 library
% includelib &LibPath&Windows\Mswsock.lib               ;Microsoft WinSock extensions
% includelib &LibPath&Windows\Kernel32.lib              ;Core Windows kernel functions
% includelib &LibPath&Windows\Shell32.lib               ;Shell functionality
% includelib &LibPath&Windows\Iphlpapi.lib              ;IP Helper API (adapter enumeration, etc.)

if INTERNET_PROTOCOL_VERSION eq 4
  AF_INETX  equ   AF_INET                               ;Use IPv4 address family
elseif INTERNET_PROTOCOL_VERSION eq 6
  AF_INETX  equ   AF_INET6                              ;Use IPv6 address family
else
  %.err <NetComEngine.Init - wrong IP version: $ToStr(%INTERNET_PROTOCOL_VERSION)>
endif


;Load or build the following objects
MakeObjects Primer, Stream, DiskStream, Collection, DataPool, StopWatch
MakeObjects DataCollection, XWCollection, SortedCollection, SortedDataCollection
MakeObjects WinPrimer, Window, Button, Hyperlink
MakeObjects Dialog, DialogModal, DialogAbout
MakeObjects WinApp, DlgApp
MakeObjects NetCom


include SRP_Globals.inc                                 ;Application globals
include SRP_Main.inc                                    ;Application object

.code
start proc                                              ;Program entry point
  SysInit                                               ;Runtime initialization of OOP model

  DbgClearTxt "SRP"                                     ;Clear this DbgCenter text window
  DbgClearTxt "&PROTOCOL_WND_NAME"                      ;Clear this DbgCenter text window
  OCall $ObjTmpl(Application)::Application.Init         ;Initialize application
  OCall $ObjTmpl(Application)::Application.Run          ;Execute application
  OCall $ObjTmpl(Application)::Application.Done         ;Finalize application

  SysDone                                               ;Runtime finalization of the OOP model
  invoke ExitProcess, 0                                 ;Exit program returning 0 to the OS
start endp

end
