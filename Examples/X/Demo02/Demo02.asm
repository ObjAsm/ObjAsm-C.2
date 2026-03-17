; ==================================================================================================
; Title:      Demo02.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm demonstration application Demo02.
; Notes:      Version C.1.0, October 2017
;               - Initial release.
;
; Description:
;   Demo02 is the first ObjAsm example showcasing Windows application development using:
;     - WinPrimer and WinApp framework objects
;     - Windows controls (Button, Hyperlink)
;     - Dialogs (standard, modal, About-box)
;     - SDI application model
;
;   This file provides the program entry point. The actual application object and global resources
;   are defined in:
;     - Demo02_Globals.inc
;     - Demo02_Main.inc
;
;   The application lifecycle is demonstrated through:
;     - Init   setup of the main application object
;     - Run    message loop execution
;     - Done   resource cleanup
;
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ; Include and initialize ObjAsm modules
SysSetup OOP, WIN64, WIDE_STRING ;, DEBUG(WND)          ; Load OOP support for Win64 + WIDE strings
                                                        ; (OPTIONAL: enable DebugCenter window)
% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\shlwapi.lib

MakeObjects Primer, Stream, WinPrimer
MakeObjects Window, Button, Hyperlink, Dialog, DialogModal, DialogAbout
MakeObjects WinApp, SdiApp

include Demo02_Globals.inc                              ; Application global definitions
include Demo02_Main.inc                                 ; Main Application object

start proc                                              ; Program entry point
  SysInit                                               ; Initialize ObjAsm runtime and OS layer

  OCall $ObjTmpl(Application)::Application.Init         ; Initialize Application object
  OCall $ObjTmpl(Application)::Application.Run          ; Execute message loop
  OCall $ObjTmpl(Application)::Application.Done         ; Finalize and release resources

  SysDone                                               ; Shutdown ObjAsm runtime
  invoke ExitProcess, 0                                 ; Exit program (return code 0)
start endp

end