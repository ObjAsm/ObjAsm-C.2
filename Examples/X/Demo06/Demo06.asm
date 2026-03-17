; ==================================================================================================
; Title:      Demo06.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm demonstration program Demo06.
;
; Description:
;   This module contains the program entry point for the ObjAsm Demo06 application. It initializes
;   the ObjAsm runtime, constructs the Application object, and executes the main event loop. The
;   Demo06 project demonstrates:
;     - MDI (Multiple Document Interface) architecture
;     - Toolbars, Statusbar, Rebar, and XMenu usage
;     - Dialogs, icons, and extended control handling
;     - ObjAsm OOP object lifecycle (Init => Run => Done)
;
;   The actual implementation of the Application object and related classes is located in:
;     - Demo06_Globals.inc
;     - Demo06_Main.inc
;
; Notes:
;   Version C.1.0 - October 2017
;     - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ; Include & initialize standard modules

SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND)           ; Load OOP support and OS-related objects

% include &MacPath&DlgTmpl.inc                          ; Dialog Template macros for XMenu
% include &MacPath&ConstDiv.inc

% includelib &LibPath&Windows\shlwapi.lib
% includelib &LibPath&Windows\Comctl32.lib
% includelib &LibPath&Windows\Shell32.lib

% include &IncPath&Windows\CommCtrl.inc
% include &IncPath&Windows\HtmlHelp.inc

; Load or build the following objects
MakeObjects Primer, Stream, Collection
MakeObjects WinPrimer, Window, Button, Hyperlink
MakeObjects Dialog, DialogModal, DialogAbout, DialogModalIndirect
MakeObjects SimpleImageList, MaskedImageList
MakeObjects MsgInterceptor, XMenu
MakeObjects WinControl, Toolbar, Rebar, Statusbar, Tooltip
MakeObjects WinApp, MdiApp

include Demo06_Globals.inc                              ; Application global definitions
include Demo06_Main.inc                                 ; Application object implementation

start proc                                              ; Program entry point
  SysInit                                               ; Initialize ObjAsm OOP runtime

  OCall $ObjTmpl(Application)::Application.Init         ; Initialize Application object
  OCall $ObjTmpl(Application)::Application.Run          ; Run the main event loop
  OCall $ObjTmpl(Application)::Application.Done         ; Finalize application object

  SysDone                                               ; Shutdown ObjAsm runtime environment
  invoke ExitProcess, 0                                 ; Exit program, return 0 to OS
start endp
 
end