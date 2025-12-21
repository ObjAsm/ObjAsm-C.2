; ==================================================================================================
; Title:      SVC_Client.asm
; Author:     G. Friedrich
; Version:    C.2.0
; Purpose:    ObjAsm application.
; Notes:      Version C.2.0
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include ObjAsm model macros and core setup
SysSetup OOP, WIN64, WIDE_STRING, DEBUG(WND)           ;Enable OOP support, target Win64,
                                                        ;use wide strings

% include &MacPath&fMath.inc                            ;Include floating-point math macros

% includelib &LibPath&Windows\shell32.lib               ;Shell API library
% includelib &LibPath&Windows\shlwapi.lib               ;Shell lightweight utility library

MakeObjects Primer, Stream, WinPrimer, Window           ;Core and windowing base objects
MakeObjects Button, Hyperlink, Dialog, DialogModal, DialogAbout
MakeObjects WinApp, DlgApp                              ;Dialog application base classes


include SVC_Client_Globals.inc                          ;Global variables and constants
include SVC_Client_Main.inc                             ;Main application object implementation

.code
start proc                                              ;Program entry point

  SysInit                                               ;Initialize ObjAsm runtime and OOP model

  OCall $ObjTmpl(Application)::Application.Init         ;Create and initialize application object
  OCall $ObjTmpl(Application)::Application.Run          ;Enter the application message loop
  OCall $ObjTmpl(Application)::Application.Done         ;Perform application cleanup

  SysDone                                               ;Finalize ObjAsm runtime and free resources
  invoke ExitProcess, 0                                 ;Terminate process and return 0 to the OS

start endp

end                                                     ;End of assembly unit
