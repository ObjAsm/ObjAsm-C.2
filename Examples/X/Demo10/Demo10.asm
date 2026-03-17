; ==================================================================================================
; Title:      Demo10.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    Program entry point for ObjAsm demonstration program 10.
;
; Description:
;   This module provides the application entry point and performs all system-level initialization
;   required for Demo10, an advanced MDI demonstration built using the ObjAsm OOP framework.
;   Demo10.asm establishes the runtime environment, loads the framework object classes, and
;   delegates all operational behavior to the Application object defined in Demo10_Main.inc.
;
;   Responsibilities of this module include:
;   - Initializing the ObjAsm runtime (SysInit / SysDone)
;   - Setting up debug and resource tracking through ResGuard
;   - Loading required framework classes (Window, Toolbar, Rebar, XMenu, Splitter,
;     ProjectWnd, PropertiesWnd, TabCtrl, various controls, and image list objects)
;   - Including global definitions (Demo10_Globals.inc)
;   - Invoking the Application object lifecycle: Init => Run => Done
;   - Finalizing resources and exiting cleanly via ExitProcess
;
;   When combined with Demo10_Main.inc, this module forms the foundation of an extensive MDI-based
;   interface showcasing multiple toolbars, split views, tabbed dialog systems, custom menus,
;   multilingual UI features, and dynamic layout management through splitters and dockable windows.
;
; Notes:
;   Version C.1.0 - October 2017
;     - Initial release.
;
; ==================================================================================================


%include @Environ(OBJASM_PATH)\\Code\\Macros\\Model.inc ; Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND, ResGuard)  ; Load OOP files and OS related objects

% include &MacPath&DlgTmpl.inc                          ; Dialog Template macros for XMenu
% include &MacPath&ConstDiv.inc

% includelib &LibPath&Windows\Comctl32.lib
% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\shlwapi.lib
% includelib &LibPath&Windows\UxTheme.lib

% include &IncPath&Windows\UxTheme.inc
% include &IncPath&Windows\vsstyle.inc

;Load or build the following objects
MakeObjects Primer, Stream, WinPrimer, Window
MakeObjects Collection, DataCollection
MakeObjects Dialog, DialogModal, DialogAbout, DialogModeless
MakeObjects SimpleImageList, MaskedImageList
MakeObjects Button, IconButton, Hyperlink
MakeObjects MsgInterceptor, DialogModalIndirect, XMenu
MakeObjects WinControl, Toolbar, Rebar, Statusbar, ComboBox, TreeView, ListView, TabCtrl
MakeObjects FlipBox, Splitter, ProjectWnd, PropertiesWnd
MakeObjects WinApp, MdiApp

include Demo10_Globals.inc                              ; Application globals
include Demo10_Main.inc                                 ; Application object

start proc                                              ; Program entry point
  SysInit                                               ; Runtime initialization of OOP model

  ResGuard_Start
  OCall $ObjTmpl(Application)::Application.Init         ; Initialize application
  OCall $ObjTmpl(Application)::Application.Run          ; Execute application
  OCall $ObjTmpl(Application)::Application.Done         ; Finalize application
  ResGuard_Show
  ResGuard_Stop

  SysDone                                               ; Runtime finalization of the OOP model
  invoke ExitProcess, 0                                 ; Exit program returning 0 to the OS
start endp

end
