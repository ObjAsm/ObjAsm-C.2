; ==================================================================================================
; Title:      WebCam.asm
; Author:     G. Friedrich
; Version:    1.0.0
; Purpose:    ObjAsm WebCam Application.
; Notes:      Version 1.0.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND)            ;Load OOP files and OS related objects

NOMMREG   equ 1
NOAVIFILE equ 1
NOMSACM   equ 1
% include &IncPath&Windows\Vfw.inc
% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\shlwapi.lib
% includelib &LibPath&Windows\vfw32.lib

;Load or build the following objects
MakeObjects Primer, Stream, WinPrimer, Window, Button, Hyperlink
MakeObjects Dialog, DialogModal, DialogAbout
MakeObjects WinApp, SdiApp

include WebCam_Globals.inc                              ;Application globals
include WebCam_Main.inc                                 ;Application object

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
