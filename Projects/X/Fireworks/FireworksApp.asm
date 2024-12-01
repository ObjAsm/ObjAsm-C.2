; ==================================================================================================
; Title:      Application.asm
; Author:     G. Friedrich
; Version:    1.0.0
; Purpose:    ObjAsm Fireworks demo.
; Notes:      Version 1.0.0, July 2006
;             - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND)           ;Load OOP files and OS related objects

% include &MacPath&fMath.inc                            ;Include coprocessor math macros

% includelib &LibPath&Windows\Shell32.lib

;Load or build the following objects
MakeObjects Primer, Stream
MakeObjects WinPrimer, Window, Button, Hyperlink
MakeObjects Dialog, DialogModal, DialogAbout
MakeObjects WinApp, SdiApp, StopWatch
MakeObjects .\Fireworks

.code
include FireworksApp_Globals.inc                        ;Include application globals
include FireworksApp_Main.inc                           ;Include Application object

start proc                                              ;Program entry point
  SysInit                                               ;Runtime initialization of OOP model

  OCall $ObjTmpl(Application)::Application.Init         ;Initialize the object data
  OCall $ObjTmpl(Application)::Application.Run          ;Execute the application
  OCall $ObjTmpl(Application)::Application.Done         ;Finalize it

  SysDone                                               ;Runtime finalization of the OOP model
  invoke ExitProcess, 0                                 ;Exit program returning 0 to the OS
start endp

end
