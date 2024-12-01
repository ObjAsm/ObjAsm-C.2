; ==================================================================================================
; Title:      Application.asm
; Author:     G. Friedrich
; Version:    1.0.0
; Purpose:    ObjAsm Dynamic Window Layout Application.
; Notes:      Version 1.0.0, October 2017
;             - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND, ResGuard)  ;Load OOP files and OS related objects

% includelib &LibPath&Windows\Shell32.lib
% includelib &LibPath&Windows\shlwapi.lib


;Load or build the following objects
MakeObjects Primer, Stream, WinPrimer
MakeObjects Button, Hyperlink
MakeObjects Window, Dialog, DialogModal, DialogAbout
MakeObjects WinApp, SdiApp


include DLApp_Globals.inc                               ;Application globals
include DLApp_Main.inc                                  ;Application object

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
