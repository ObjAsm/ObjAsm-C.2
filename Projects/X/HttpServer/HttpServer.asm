; ==================================================================================================
; Title:      HttpServer.asm
; Author:     G. Friedrich 
; Version:    1.2.0
; Purpose:    ObjAsm HTTP Server.
; Notes:      Version 1.2.0, December 2020
;               - First release.
;               - Run the server as admin to be able to register the URL.
;               - Create an exception rule for incomming connections on the local windows firewall
;                 Settings:
;                   - Connection: incomming
;                   - Name: OA HTTP Server
;                   - Profile: Private
;                   - Programs: all
;                   - Protocol: TCP
;                   - Port: 8080
; ==================================================================================================


WIN32_LEAN_AND_MEAN         equ 1                       ;Necessary to exclude WinSock.inc
INTERNET_PROTOCOL_VERSION   equ 4

% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc
SysSetup OOP, WIN32, ANSI_STRING;, DEBUG(WND)

% includelib &LibPath&Windows\Kernel32.lib
% includelib &LibPath&Windows\Shell32.lib
% includelib &LibPath&Windows\Shlwapi.lib
% includelib &LibPath&Windows\httpapi.lib

% include &IncPath&Windows\WinSock2.inc
% include &IncPath&Windows\Shellapi.inc
% include &IncPath&Windows\http.inc

;Load or build the following objects
MakeObjects Primer, Stream, WinPrimer
MakeObjects Button, Hyperlink
MakeObjects Window, Dialog, DialogModal, DialogAbout
MakeObjects Collection, XWCollection
MakeObjects WinApp, SdiApp
MakeObjects HttpServer

include HttpServer_Globals.inc
include HttpServer_Main.inc

.code
start proc
  SysInit

  DbgClearAll
  OCall $ObjTmpl(Application)::Application.Init
  OCall $ObjTmpl(Application)::Application.Run
  OCall $ObjTmpl(Application)::Application.Done

  SysDone
  invoke ExitProcess, 0
start endp

end
