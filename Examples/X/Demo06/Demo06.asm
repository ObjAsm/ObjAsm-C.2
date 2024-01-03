; ==================================================================================================
; Title:      Demo06.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm demonstration program 6.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules

SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND)            ;Load OOP files and OS related objects

% include &MacPath&DlgTmpl.inc                          ;Dialog Template macros for XMenu
% include &MacPath&ConstDiv.inc

% includelib &LibPath&Windows\shlwapi.lib
% includelib &LibPath&Windows\Comctl32.lib
% includelib &LibPath&Windows\Shell32.lib

% include &IncPath&Windows\CommCtrl.inc
% include &IncPath&Windows\HtmlHelp.inc

;Load or build the following objects
MakeObjects Primer, Stream, Collection
MakeObjects WinPrimer, Window, Button, Hyperlink
MakeObjects Dialog, DialogModal, DialogAbout, DialogModalIndirect
MakeObjects SimpleImageList, MaskedImageList
MakeObjects MsgInterceptor, XMenu
MakeObjects WinControl, Toolbar, Rebar, Statusbar, Tooltip
MakeObjects WinApp, MdiApp

include Demo06_Globals.inc                              ;Application globals
include Demo06_Main.inc                                 ;Application object

start proc                                              ;Program entry point
  SysInit                                               ;Runtime initialization of OOP model

  OCall $ObjTmpl(Application)::Application.Init         ;Initialize the object data
  OCall $ObjTmpl(Application)::Application.Run          ;Execute application
  OCall $ObjTmpl(Application)::Application.Done         ;Finalize application

  SysDone                                               ;Runtime finalization of the OOP model
  invoke ExitProcess, 0                                 ;Exit program returning 0 to the OS
start endp
 
end
