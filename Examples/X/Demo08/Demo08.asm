; ==================================================================================================
; Title:      Demo08.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    Program entry point for the ObjAsm DlgApp demonstration application (Demo08).
;
; Description:
;   This module provides the application entry point and performs all required runtime
;   initialization for Demo08, a dialog-based ObjAsm example. Unlike the frame-window or
;   MDI-driven demos, Demo08 demonstrates how the DlgApp framework can be used to create
;   applications where a dialog box acts as the main application window.
;
;   Demo08 highlights:
;       - A minimal, clean application structure using a modal-style main dialog
;       - Demonstration of the DlgApp object lifecycle (Init ? Run ? Done)
;       - Integration of window controls and basic resource handling via dialog templates
;
; Notes:
;   Version C.1.0 - September 2021
;       - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ; Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND)           ; Load OOP files and OS related objects

% include &MacPath&fMath.inc

% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\shlwapi.lib

;Load or build the following objects
MakeObjects Primer, Stream, WinPrimer, Window
MakeObjects Button, Hyperlink, Dialog, DialogModal, DialogAbout
MakeObjects WinApp, DlgApp


include Demo08_Globals.inc                              ; Application globals
include Demo08_Main.inc                                 ; Application object

start proc                                              ; Program entry point
  SysInit                                               ; Runtime initialization of OOP model

  DbgClearAll
  OCall $ObjTmpl(Application)::Application.Init         ; Initialize application
  OCall $ObjTmpl(Application)::Application.Run          ; Execute application
  OCall $ObjTmpl(Application)::Application.Done         ; Finalize application

  SysDone                                               ; Runtime finalization of the OOP model
  invoke ExitProcess, 0                                 ; Exit program returning 0 to the OS
start endp

end
