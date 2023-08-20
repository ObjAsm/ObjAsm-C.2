; ==================================================================================================
; Title:      Demo02.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm demonstration program 2.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIN32, WIDE_STRING, DEBUG(WND, RESGUARD)  ;Load OOP files and OS related objects

% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\shlwapi.lib

;Load or build the following objects
MakeObjects Primer, Stream, WinPrimer
MakeObjects Window, Button, Hyperlink, Dialog, DialogModal, DialogAbout
MakeObjects WinApp, SdiApp

include Demo02_Globals.inc                              ;Application globals
include Demo02_Main.inc                                 ;Application object

.code
start proc                                              ;Program entry point
  SysInit                                               ;Runtime initialization of OOP model

  ResGuard_Start                                        ;Activates ResGuard system

  invoke P0, 123
  OCall $ObjTmpl(Application)::Application.Init         ;Initialize application
  OCall $ObjTmpl(Application)::Application.Run          ;Execute application
  OCall $ObjTmpl(Application)::Application.Done         ;Finalize application
  ResGuard_Show                                         ;Shows ResGuard results

  SysDone                                               ;Runtime finalization of the OOP model
  invoke ExitProcess, 0                                 ;Exit program returning 0 to the OS
start endp

end
