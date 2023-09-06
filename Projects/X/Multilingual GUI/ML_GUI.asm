; ==================================================================================================
; Title:      ML_GUI.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Multilanguage GUI.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND, ResGuard)  ;Load OOP files and OS related objects

GDIPVER equ 0100h

% include &COMPath&COM.inc                              ;COM basic support
% include &MacPath&fMath.inc
% include &IncPath&Windows\CommCtrl.inc
% include &IncPath&Windows\richedit.inc
% include &IncPath&Windows\GdiplusPixelFormats.inc
% include &IncPath&Windows\GdiplusInit.inc
% include &IncPath&Windows\GdiplusEnums.inc
% include &IncPath&Windows\GdiplusGpStubs.inc
% include &IncPath&Windows\GdiPlusFlat.inc
% include &IncPath&Windows\wininet.inc

% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\shlwapi.lib
% includelib &LibPath&Windows\Wininet.lib
% includelib &LibPath&Windows\Msimg32.lib
% includelib &LibPath&Windows\Ole32.lib
% includelib &LibPath&Windows\GdiPlus.lib

;Load or build the following objects
MakeObjects Primer, Stream, DiskStream, WinPrimer
MakeObjects Button, Hyperlink
MakeObjects Window, Dialog, DialogModal, DialogAbout
MakeObjects WinApp, SdiApp
MakeObjects Throbber, MovingThrobber
MakeObjects Collection, SortedCollection, WebTextTranslator

include ML_GUI_Globals.inc                              ;Application globals
include ML_GUI_Main.inc                                 ;Application object


.code
start proc                                              ;Program entry point
  SysInit                                               ;Runtime initialization of OOP model
  DbgClearAll

  ResGuard_Start
  invoke CoInitialize, 0
  OCall $ObjTmpl(Application)::Application.Init         ;Initialize application
  OCall $ObjTmpl(Application)::Application.Run          ;Execute application
  OCall $ObjTmpl(Application)::Application.Done         ;Finalize application
  invoke CoUninitialize
  ResGuard_Show
  ResGuard_Stop

  SysDone                                               ;Runtime finalization of the OOP model
  invoke ExitProcess, 0                                 ;Exit program returning 0 to the OS
start endp

end
