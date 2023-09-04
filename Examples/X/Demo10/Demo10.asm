; ==================================================================================================
; Title:      Demo10.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm demonstration program 10.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


%include @Environ(OBJASM_PATH)\\Code\\Macros\\Model.inc ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND, ResGuard)  ;Load OOP files and OS related objects

% include &MacPath&DlgTmpl.inc                          ;Dialog Template macros for XMenu
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

include Demo10_Globals.inc                              ;Application globals
include Demo10_Main.inc                                 ;Application object

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
