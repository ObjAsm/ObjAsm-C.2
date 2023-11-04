; ==================================================================================================
; Title:      CompressedRes.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Compressed Resources.
; Notes:      Version C.1.0, October 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND)            ;Load OOP files and OS related objects

% include &MacPath&fMath.inc
% include &MacPath&DlgTmpl.inc
% include &MacPath&ConstDiv.inc

% include &IncPath&Windows\compressapi.inc

% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\shlwapi.lib
% includelib &LibPath&Windows\Cabinet.lib

;Load or build the following objects
MakeObjects Primer, Stream, WinPrimer
MakeObjects Button, Hyperlink
MakeObjects Window, Dialog, DialogModal, DialogAbout
MakeObjects WinApp, SdiApp

include CompressedRes_Globals.inc                       ;Application globals
include CompressedRes_Main.inc                          ;Application object

.code
start proc                                              ;Program entry point
  SysInit                                               ;Runtime initialization of OOP model
  DbgClearAll

  OCall $ObjTmpl(Application)::Application.Init         ;Initialize application
  OCall $ObjTmpl(Application)::Application.Run          ;Execute application
  OCall $ObjTmpl(Application)::Application.Done         ;Finalize application

  SysDone                                               ;Runtime finalization of the OOP model
  invoke ExitProcess, 0                                 ;Exit program returning 0 to the OS
start endp

end
