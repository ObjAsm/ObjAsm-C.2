; ==================================================================================================
; Title:      NetComStressClient.asm
; Author:     G. Friedrich
; Version:    1.0.0
; Purpose:    NetCom Client Application.
; Notes:      Version 1.0.0, October 2017
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Summary:
;   This module implements the user-interface logic for the NetComStressClient application.
;   It provides command handling, status display, and a Send dialog used to establish, manage, and
;   terminate network connections using the NetCom engine.
;
;   The NetComStressClient object processes window messages such as WM_COMMAND, WM_CLOSE, and
;   WM_TIMER to control application flow, display runtime statistics, and handle user interaction
;   through menus and dialogs.
;
;   The SendDlg object encapsulates all dialog behavior required to configure a remote endpoint,
;   resolve network addresses, initiate outbound TCP connections, transmit captured desktop image
;   data, and manage the connection lifecycle and resources.
;
;   This code implements a Windows GUI client that captures the local desktop and streams it over a
;   TCP connection to a remote server, primarily as a NetCom framework demonstration or
;   remote-display sender prototype. Data transmission and UI updates are driven by timers to avoid
;   blocking operations.
;
;   All network connections are gracefully disconnected and released on user request or error
;   conditions to ensure safe resource management.
;
;   Transmission protocol:
;     Each transmission begins with a DWORD containing the total size of the
;     transmitted block in bytes (including this DWORD itself), followed by a
;     BITMAPINFO structure (including RGBQUAD color entries) and by the bitmap pixel
;     data
;
;     The transmitted memory layout is as follows:
;       DWORD  - Total transmission size in bytes (dMemSize)
;       BMI    - BITMAPINFO structure including RGBQUAD color entries
;       DATA   - Bitmap pixel data
;
;     The transmitted memory block is contiguous and is sent as a single payload
;     using the NetComConnection QueueWrite mechanism.
;
;   All network connections are gracefully disconnected and released on user request or error
;   conditions to ensure safe resource management.
;
; --------------------------------------------------------------------------------------------------


WIN32_LEAN_AND_MEAN         equ 1                       ;Exclude rarely-used Windows headers
INCL_WINSOCK_API_PROTOTYPES equ 1                       ;Enable WinSock API prototypes

APP_NAME                    textequ <NetComStressClient>      ;Application internal name
PROTOCOL_WND_NAME           textequ <Client Stress Protocol>  ;Debug/protocol window title
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
% includelib &LibPath&Windows\Iphlpapi.lib              ;IP Helper API (adapter enumeration, etc.)

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
include NetComStressClient_Globals.inc                  ;Application-wide globals
include NetComStressClient_Main.inc                     ;Main application implementation

start proc                                              ;Program entry point
  SysInit                                               ;Initialize ObjAsm runtime model

  DbgClearTxt "NETCOMSTRESSCLIENT"                      ;Clear main debug output window
  DbgClearTxt "&PROTOCOL_WND_NAME"                      ;Clear protocol debug window
  OCall $ObjTmpl(NetComStressClient)::NetComStressClient.Init ;Initialize NetComStressClient object
  OCall $ObjTmpl(NetComStressClient)::NetComStressClient.Run  ;Enter application message loop
  OCall $ObjTmpl(NetComStressClient)::NetComStressClient.Done ;Shutdown and cleanup resources

  SysDone                                               ;Finalize ObjAsm runtime model
  invoke ExitProcess, 0                                 ;Terminate process with success code
start endp                                              ;End of program entry procedure

end                                                     ;End of assembly unit

