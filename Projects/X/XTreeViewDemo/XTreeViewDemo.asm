; ==================================================================================================
; Title:      XTreeViewDemo.asm
; Author:     G. Friedrich
; Version:    1.0.0
; Purpose:    ObjAsm XTreeview Demo Application.
; Notes:      Version 1.0.0, October 2017
;               - First release.
; ==================================================================================================


%include @Environ(OBJASM_PATH)\\Code\\Macros\\Model.inc ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND, ResGuard)  ;Load OOP files and OS related objects

% include &MacPath&SDLL.inc
% include &IncPath&Windows\mmsystem.inc
% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\shlwapi.lib

;Load or build the following objects
MakeObjects Primer, Stream, Collection, XWCollection
MakeObjects WinPrimer, Window, Button, Hyperlink, Dialog, DialogModal, DialogAbout
MakeObjects WinApp, SdiApp
MakeObjects WinControl
MakeObjects DataPool
MakeObjects XTreeView
MakeObjects XCustomTreeView

include XTreeViewDemo_Globals.inc
include XTreeViewDemo_Main.inc

start proc
  SysInit                                               ;Runtime initialization of OOP model

  ResGuard_Start

  OCall $ObjTmpl(XTVDemoApp)::XTVDemoApp.Init           ;Initialize the object data
  OCall $ObjTmpl(XTVDemoApp)::XTVDemoApp.Run            ;Execute the application
  OCall $ObjTmpl(XTVDemoApp)::XTVDemoApp.Done           ;Finalize it

  ResGuard_Show
  ResGuard_Stop

  SysDone                                               ;Runtime finalization of the OOP model
  invoke ExitProcess, 0                                 ;Exit program returning 0 to the OS
start endp

end
