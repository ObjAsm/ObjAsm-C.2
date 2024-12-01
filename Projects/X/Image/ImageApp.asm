; ==================================================================================================
; Title:      ImageApp.asm
; Author:     G. Friedrich
; Version:    1.0.0
; Purpose:    ObjAsm Image Application.
; Notes:      Version 1.0.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND)            ;Load OOP files and OS related objects

% include &COMPath&COM.inc                              ;COM basic support
% include &IncPath&Windows\ShellApi.inc
% include &IncPath&Windows\IImgCtx.inc

% includelib &LibPath&Windows\Shell32.lib
% includelib &LibPath&Windows\Ole32.lib
% includelib &LibPath&Windows\OleAut32.lib
% includelib &LibPath&Windows\shlwapi.lib
% includelib &LibPath&Windows\Msimg32.lib

;Load or build the following objects
MakeObjects Primer, Stream, WinPrimer, Window
MakeObjects Button, Hyperlink
MakeObjects Dialog, DialogModal, DialogAbout, Image
MakeObjects WinApp, SdiApp

include ImageApp_Globals.inc                            ;Application globals
include ImageApp_Main.inc                               ;Application object


start proc                                              ;Program entry point
  SysInit                                               ;Runtime initialization of OOP model
  DbgClearAll

  invoke CoInitialize, 0
  OCall $ObjTmpl(Application)::Application.Init         ;Initialize application
  OCall $ObjTmpl(Application)::Application.Run          ;Execute application
  OCall $ObjTmpl(Application)::Application.Done         ;Finalize application
  invoke CoUninitialize

  SysDone                                               ;Runtime finalization of the OOP model
  invoke ExitProcess, 0                                 ;Exit program returning 0 to the OS
start endp

end
