; ==================================================================================================
; Title:      NetComStressServer.asm
; Author:     G. Friedrich
; Version:    1.0.0
; Purpose:    NetCom Server application.
; Notes:      Version 1.0.0, October 2017
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Summary:
;   This module implements the NetComStressServer application, a Windows SDI server using the NetCom
;   framework. It manages incoming TCP client connections, monitors I/O activity, and maintains
;   runtime statistics such as worker threads, listeners, connections, I/O jobs, bytes transferred,
;   and transfer rates.
;
;   The NetComStressServer object handles window creation, menu commands, timers, and lifecycle
;   events, embedding a NetComEngine instance to perform all network-level operations.
;
;   Each accepted client connection is wrapped in a NetComConnection object, processed
;   asynchronously, and disconnected gracefully. Data blocks from clients follow the protocol
;   defined in NetComStressServerProtocol.
;
;   Received bitmap images from clients are captured and displayed in the DebugCenter for monitoring
;   or debugging purposes.
;
;   A WM_TIMER-driven mechanism ensures the GUI updates statistics in real time without blocking
;   network operations. This implementation demonstrates efficient handling of multiple concurrent
;   client connections and real-time data visualization.
;
; --------------------------------------------------------------------------------------------------


WIN32_LEAN_AND_MEAN         equ 1                       ;Exclude rarely-used Windows headers
INCL_WINSOCK_API_PROTOTYPES equ 1                       ;Enable WinSock API prototypes

PROTOCOL_WND_NAME           textequ <Server Protocol>   ;Debug/protocol window title
INTERNET_PROTOCOL_VERSION   equ 4                       ;Select IP version (4 or 6)

% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;ObjAsm model macros and setup
SysSetup OOP, WIN64, ANSI_STRING, DEBUG(WND)            ;Initialize OOP model and OS bindings

% include &MacPath&fMath.inc                            ;Floating-point math helpers
% include &MacPath&SDLL.inc                             ;Linked List support macros

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
MakeObjects Primer, Stream, DiskStream, Collection, DataPool, StopWatch ;Core utilities and I/O
MakeObjects DataCollection, XWCollection, SortedCollection, SortedDataCollection ;Containers
MakeObjects WinPrimer, Window, Button, Hyperlink        ;Basic windowing controls
MakeObjects Dialog, DialogModal, DialogAbout            ;Dialog-related classes
MakeObjects WinApp, SdiApp                              ;Windows application base classes
MakeObjects NetCom                                      ;NetCom networking framework

.code
include NetComStressServer_Globals.inc                  ;Application-wide globals
include NetComStressServer_Main.inc                     ;NetComStressServer implementation

start proc                                              ;Program entry point
  SysInit                                               ;Initialize ObjAsm runtime model

  DbgClearTxt "NETCOMSERVER"                            ;Clear main debug output window
  DbgClearTxt "&PROTOCOL_WND_NAME"                      ;Clear protocol debug window
  OCall $ObjTmpl(NetComStressServer)::NetComStressServer.Init ;Initialize NetComStressServer object
  OCall $ObjTmpl(NetComStressServer)::NetComStressServer.Run  ;Enter application message loop
  OCall $ObjTmpl(NetComStressServer)::NetComStressServer.Done ;Shutdown and cleanup resources

  SysDone                                               ;Finalize ObjAsm runtime model
  invoke ExitProcess, 0                                 ;Terminate process with success code
start endp                                              ;End of program entry procedure

end                                                     ;End of assembly unit
