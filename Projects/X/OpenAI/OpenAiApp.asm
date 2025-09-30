; ==================================================================================================
; Title:      OpenAiApp.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm OpenAI Application.
; Notes:      Version C.1.0, September 2025
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND)            ;Load OOP files and OS related objects

GDIPVER equ 0100h

% include &MacPath&LDLL.inc                             ;Required for Json
% include &MacPath&fMath.inc                            ;Required for Throbber

% include &IncPath&Windows\GdiplusPixelFormats.inc      ;Required for Throbber
% include &IncPath&Windows\GdiplusInit.inc
% include &IncPath&Windows\GdiplusEnums.inc
% include &IncPath&Windows\GdiplusGpStubs.inc
% include &IncPath&Windows\GdiPlusFlat.inc

% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\shlwapi.lib
% includelib &LibPath&Windows\Wininet.lib
% includelib &LibPath&Windows\GdiPlus.lib               ;Required for Throbber
% includelib &LibPath&Windows\Ole32.lib

% include &IncPath&Windows\wininet.inc                  ;Required for CloudAI

;Load or build the following objects
MakeObjects Primer, Stream, MemoryStream, WinPrimer
MakeObjects Button, Hyperlink, Throbber, MovingThrobber
MakeObjects Window, Dialog, DialogModal, DialogAbout
MakeObjects WinApp, DlgApp
MakeObjects Json, CloudAI, OpenAI

include OpenAiApp_Globals.inc                           ;Application globals
include OpenAiApp_Main.inc                              ;Application object

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
