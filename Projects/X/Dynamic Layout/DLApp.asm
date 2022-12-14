; ==================================================================================================
; Title:      DLApp.asm
; Author:     G. Friedrich
; Version:    1.0.0
; Purpose:    ObjAsm Dynamic Window Layout Application.
; Notes:      Version 1.0.0, October 2017
;             - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND)           ;Load OOP files and OS related objects

% includelib &LibPath&Windows\Shell32.lib
% includelib &LibPath&Windows\shlwapi.lib


;Load or build the following objects
MakeObjects Primer, Stream, WinPrimer
MakeObjects Button, Hyperlink
MakeObjects Window, Dialog, DialogModal, DialogAbout
MakeObjects WinApp, SdiApp


include DLApp_Globals.inc                               ;Application globals
include DLApp_Main.inc                                  ;DLApp object

.code
start proc                                              ;Program entry point
  SysInit                                               ;Runtime initialization of OOP model

  OCall $ObjTmpl(DLApp)::DLApp.Init                     ;Initialize application
  OCall $ObjTmpl(DLApp)::DLApp.Run                      ;Execute application
  OCall $ObjTmpl(DLApp)::DLApp.Done                     ;Finalize application

  SysDone                                               ;Runtime finalization of the OOP model
  invoke ExitProcess, 0                                 ;Exit program returning 0 to the OS
start endp

end
