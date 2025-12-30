; ==================================================================================================
; Title:      NetComClient.asm
; Author:     G. Friedrich
; Version:    1.0.0
; Purpose:    NetCom Client Application.
; Notes:      Version 1.0.0, October 2017
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Summary:
;   This module implements an alternative NetCom client variant that demonstrates controlled
;   multi-connection message transmission in a robust and testable manner.
;
;   The application provides a Windows SDI GUI that allows the user to:
;     - Configure a remote address and service port for connection establishment
;     - Open and manage multiple parallel TCP connections simultaneously
;     - Transmit a configurable text payload repeatedly across all active connections
;     - Gracefully disconnect and release all resources associated with each connection
;
;   This implementation focuses on stress-testing the NetCom engine by sending repeated
;   application-level messages using a configurable number of connections and message repetitions
;   to evaluate performance and reliability.
;
;   The SendDlg dialog encapsulates all connection management, payload preparation, and transmission
;   logic, while the NetComClient object manages the application lifecycle, engine initialization,
;   and status display.
;
;   Runtime statistics including workers, listeners, connections, I/O jobs, and throughput are
;   periodically displayed using a WM_TIMER-driven refresh mechanism for real-time monitoring.
;
; --------------------------------------------------------------------------------------------------


WIN32_LEAN_AND_MEAN         equ 1                       ;Exclude rarely-used Windows headers
INCL_WINSOCK_API_PROTOTYPES equ 1                       ;Enable WinSock API prototypes

APP_NAME                    textequ <NetComClient>      ;Application internal name
PROTOCOL_WND_NAME           textequ <Client Protocol>   ;Debug/protocol window title
INTERNET_PROTOCOL_VERSION   equ 4                       ;Select IP version (4 or 6)

% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;ObjAsm model macros and setup
SysSetup OOP, WIN64, ANSI_STRING;, DEBUG(WND)           ;Initialize OOP model

% include &MacPath&fMath.inc                            ;Floating-point math helpers
% include &MacPath&SDLL.inc                             ;Linked list support macros

% include &IncPath&Windows\WinSock2.inc                 ;WinSock core definitions
% include &IncPath&Windows\ws2ipdef.inc                 ;IP protocol definitions
% include &IncPath&Windows\ws2tcpip.inc                 ;TCP/IP helper APIs

% include &IncPath&Windows\ShellApi.inc                 ;Shell API declarations
% include &IncPath&Windows\CommCtrl.inc                 ;Common controls support

% includelib &LibPath&Windows\Ws2_32.lib                ;WinSock 2 library
% includelib &LibPath&Windows\Mswsock.lib               ;Microsoft WinSock extensions
% includelib &LibPath&Windows\Kernel32.lib              ;Core Windows kernel functions
% includelib &LibPath&Windows\Shell32.lib               ;Shell functionality
% includelib &LibPath&Windows\Shlwapi.lib               ;Shell lightweight utilities

if INTERNET_PROTOCOL_VERSION eq 4
  AF_INETX  equ   AF_INET                               ;Use IPv4 address family
elseif INTERNET_PROTOCOL_VERSION eq 6
  AF_INETX  equ   AF_INET6                              ;Use IPv6 address family
else
  %.err <NetComEngine.Init - wrong IP version: $ToStr(%INTERNET_PROTOCOL_VERSION)>
endif


; Load or build the following ObjAsm framework objects
MakeObjects Primer, Stream, StopWatch                   ;Core utility and timing objects
MakeObjects Collection, DataCollection, XWCollection    ;Generic container classes
MakeObjects SortedCollection, SortedDataCollection      ;Sorted container variants
MakeObjects WinPrimer, Window, Button, Hyperlink        ;Basic windowing controls
MakeObjects Dialog, DialogModal, DialogAbout            ;Dialog-related classes
MakeObjects DataPool                                    ;Data pool support
MakeObjects WinApp, SdiApp                              ;Windows application base classes
MakeObjects NetCom                                      ;NetCom networking framework

.code
include NetComClient_Globals.inc                        ;Application-wide globals
include NetComClient_Main.inc                           ;Main application implementation

start proc                                              ;Program entry point
  SysInit                                               ;Initialize ObjAsm runtime model

  DbgClearTxt "NETCOMCLIENT"                            ;Clear main debug output window
  DbgClearTxt "&PROTOCOL_WND_NAME"                      ;Clear protocol debug window
  OCall $ObjTmpl(NetComClient)::NetComClient.Init       ;Initialize NetComClient object
  OCall $ObjTmpl(NetComClient)::NetComClient.Run        ;Enter application message loop
  OCall $ObjTmpl(NetComClient)::NetComClient.Done       ;Shutdown and cleanup resources

  SysDone                                               ;Finalize ObjAsm runtime model
  invoke ExitProcess, 0                                 ;Terminate process with success code
start endp                                              ;End of program entry procedure

end                                                     ;End of assembly unit

