; ==================================================================================================
; Title:      NetComServer.asm
; Author:     G. Friedrich
; Version:    1.0.0
; Purpose:    NetCom Server Application.
; Notes:      Version 1.0.0, October 2017
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Summary:
;   This module implements a NetCom server application designed to accept incoming TCP connections,
;   manage multiple concurrent clients, and monitor network I/O activity.
;
;   The application provides a Windows SDI graphical user interface that allows the user to view
;   server status, including active workers, listeners, connections, IO jobs, and data throughput
;   (bytes in/out and transfer rates).
;
;   The NetComServer object manages the application lifecycle, window creation, menu handling,
;   engine initialization, protocol setup, and runtime status display.
;
;   The embedded NetComEngine object handles all network-level operations, including listening for
;   incoming connections, managing connection queues, and performing asynchronous I/O operations.
;
;   This implementation is intended as a demonstration and stress-test utility for the NetCom
;   framework, showing how to efficiently manage multiple concurrent client connections and collect
;   runtime statistics.
;
;   Runtime statistics are updated periodically via a WM_TIMER-driven mechanism to ensure the GUI
;   remains responsive.
;
; --------------------------------------------------------------------------------------------------


WIN32_LEAN_AND_MEAN         equ 1                       ;Exclude rarely-used Windows headers
INCL_WINSOCK_API_PROTOTYPES equ 1                       ;Enable WinSock API prototypes

PROTOCOL_WND_NAME           textequ <Server Protocol>   ;Debug/protocol window title
INTERNET_PROTOCOL_VERSION   equ 4                       ;Select IP version (4 or 6)

% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIN64, ANSI_STRING, DEBUG(WND)            ;Load OOP files and OS related objects

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


;Load or build the following objects
MakeObjects Primer, Stream, DiskStream, Collection, DataPool, StopWatch
MakeObjects DataCollection, XWCollection, SortedCollection, SortedDataCollection
MakeObjects WinPrimer, Window, Button, Hyperlink
MakeObjects Dialog, DialogModal, DialogAbout
MakeObjects WinApp, SdiApp
MakeObjects NetCom


.code
include NetComServer_Globals.inc                        ;Includes application globals
include NetComServer_Main.inc                           ;Includes NetComServer object

start proc                                              ;Program entry point
  SysInit                                               ;Runtime initialization of OOP model

  DbgClearTxt "NETCOMSERVER"                            ;Clear this DbgCenter text window
  DbgClearTxt "&PROTOCOL_WND_NAME"                      ;Clear this DbgCenter text window
  OCall $ObjTmpl(NetComServer)::NetComServer.Init       ;Initializes the object data
  OCall $ObjTmpl(NetComServer)::NetComServer.Run        ;Executes the application
  OCall $ObjTmpl(NetComServer)::NetComServer.Done       ;Finalizes it

  SysDone                                               ;Runtime finalization of the OOP model
  invoke ExitProcess, 0                                 ;Exits program returning 0 to the OS
start endp

end
