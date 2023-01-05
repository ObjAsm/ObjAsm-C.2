; ==================================================================================================
; Title:      IcmpApp.asm
; Author:     G. Friedrich
; Version:    C.2.0
; Purpose:    ObjAsm IcmpApp.
; Notes:      Version C.2.0, December 2022
;               - First release.
; ==================================================================================================

WIN32_LEAN_AND_MEAN         equ 1                       ;Necessary to exlude WinSock.inc
INTERNET_PROTOCOL_VERSION   equ 4

% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIN32, ANSI_STRING, DEBUG(CON)            ;Load OOP files and OS related objects

% include &IncPath&Windows\commctrl.inc
% include &IncPath&Windows\ShellApi.inc

% include &IncPath&Windows\WinSock2.inc
% include &IncPath&Windows\IPExport.inc
% include &IncPath&Windows\IcmpAPI.inc

% includelib &LibPath&Windows\Ws2_32.lib
% includelib &LibPath&Windows\Shell32.lib
% includelib &LibPath&Windows\Shlwapi.lib
% includelib &LibPath&Windows\Iphlpapi.lib

include IcmpApp_Globals.inc                             ;Application globals

;Load or build the following objects
MakeObjects Primer, Stream, WinPrimer
MakeObjects Button, Hyperlink
MakeObjects Window, Dialog, DialogModal, DialogAbout
MakeObjects Collection, DataCollection, SortedCollection, SortedDataCollection, XWCollection, TextView
MakeObjects WinApp, SdiApp, .\IcmpDstDialog, .\IcmpManager

include IcmpApp_Main.inc                                ;Application object

.code
start proc                                              ;Program entry point
  SysInit                                               ;Runtime initialization of OOP model

  OCall $ObjTmpl(Application)::Application.Init         ;Initialize application
  OCall $ObjTmpl(Application)::Application.Run          ;Execute application
  OCall $ObjTmpl(Application)::Application.Done         ;Finalize application

  SysDone                                               ;Runtime finalization of the OOP model
  invoke ExitProcess, 0                                 ;Exit program returning 0 to the OS
start endp

end
