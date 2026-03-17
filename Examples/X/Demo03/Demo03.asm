; ==================================================================================================
; Title:      Demo03.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm demonstration application Demo03.
; Notes:      Version C.1.0, October 2017
;               - Initial release.
;
; Description:
;   Demo03 demonstrates advanced ObjAsm usage, including:
;     - Rebar-based toolbar layouts
;     - Status bars, tooltips, and modeless dialogs
;     - Image lists and icon resources
;     - Structured object-oriented message processing within an SDI framework
;
;   This file provides the program entry point for Demo03 and initializes the ObjAsm runtime
;   environment. It is responsible for:
;     - Loading and configuring the required ObjAsm modules and object classes
;     - Setting up the Windows OOP framework for a 64-bit, WIDE-string application
;     - Starting the application lifecycle (Init => Run => Done)
;     - Cleanly shutting down the runtime and returning control to the operating system
;
; ==================================================================================================

% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc    ; Include and initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING ;, DEBUG(WND)           ; Load OOP framework and OS-related objects

% include &MacPath&DlgTmpl.inc                           ; Include dialog template macros for XMenu
% include &IncPath&Windows\CommCtrl.inc
% include &IncPath&Windows\ShellApi.inc

% includelib &LibPath&Windows\Comctl32.lib
% includelib &LibPath&Windows\Shell32.lib

; Load or register the following object classes
MakeObjects Primer, Stream, Collection
MakeObjects WinPrimer, Window, Button, Hyperlink, Dialog, DialogModal, DialogAbout
MakeObjects DialogModeless, DialogModalIndirect
MakeObjects SimpleImageList, MaskedImageList
MakeObjects MsgInterceptor, WinControl
MakeObjects XMenu, Toolbar, Rebar, Statusbar, Tooltip
MakeObjects WinApp, SdiApp

include Demo03_Globals.inc                              ; Include application-global definitions
include Demo03_Main.inc                                 ; Include the main Application object

start proc                                              ; Program entry point
  SysInit                                               ; Initialize the ObjAsm runtime

  OCall $ObjTmpl(Application)::Application.Init         ; Initialize the application object
  OCall $ObjTmpl(Application)::Application.Run          ; Execute the application's message loop
  OCall $ObjTmpl(Application)::Application.Done         ; Finalize and release resources

  SysDone                                               ; Shutdown ObjAsm runtime
  invoke ExitProcess, 0                                 ; Exit program (return code 0)
start endp

end
