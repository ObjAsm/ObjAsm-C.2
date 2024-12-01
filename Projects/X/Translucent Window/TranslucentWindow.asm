; ==================================================================================================
; Title:      TranslucentWindow.asm
; Author:     G. Friedrich
; Version:    1.0.0
; Purpose:    ObjAsm Application.
; Notes:      Version 1.0.0, October 2017
;               - First release.
; ==================================================================================================


%include @Environ(OBJASM_PATH)\\Code\\Macros\\Model.inc ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND)            ;Load OOP files and OS related objects

% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\Shlwapi.lib

MakeObjects Primer, Stream                              ;Load or build the following objects
MakeObjects WinPrimer, Window, Button, Hyperlink, Dialog, DialogModal, DialogAbout
MakeObjects WinApp, SdiApp


.code
include TranslucentWindow_Globals.inc
include TranslucentWindow_Main.inc


start proc
  SysInit

  OCall $ObjTmpl(Application)::Application.Init
  OCall $ObjTmpl(Application)::Application.Run
  OCall $ObjTmpl(Application)::Application.Done

  SysDone
  invoke ExitProcess, 0
start endp

end
