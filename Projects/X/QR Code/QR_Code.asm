; ==================================================================================================
; Title:      QR_Code.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm QR_Code.
; Notes:      Version C.1.0, November 2022
;               - First release.
; Links:      https://github.com/nayuki/QR-Code-generator
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIN64, ANSI_STRING;, DEBUG(WND, ResGuard)  ;Load OOP files and OS related objects

% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\shlwapi.lib
% includelib &LibPath&QRCodeGen\QRCodeGen.lib

% include &IncPath&QRCodeGen\QRCodeGen.inc

;Load or build the following objects
MakeObjects Primer, Stream, WinPrimer
MakeObjects Button, Hyperlink
MakeObjects Window, Dialog, DialogModal, DialogAbout
MakeObjects WinApp, SdiApp

include QR_Code_Globals.inc                             ;Application globals
include QR_Code_Main.inc                                ;Application object

.code

start proc                                              ;Program entry point
  SysInit                                               ;Runtime initialization of OOP model

  ResGuard_Start

  OCall $ObjTmpl(Application)::Application.Init         ;Initialize application
  OCall $ObjTmpl(Application)::Application.Run          ;Execute application
  OCall $ObjTmpl(Application)::Application.Done         ;Finalize application

  ResGuard_Show
  ResGuard_Stop

  SysDone                                               ;Runtime finalization of the OOP model
  invoke ExitProcess, 0                                 ;Exit program returning 0 to the OS
start endp

end
