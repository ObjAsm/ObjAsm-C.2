; ==================================================================================================
; Title:      SpinningThrobber.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Spinning Throbber.
; Notes:      Version C.1.0, August 2022
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

% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\shlwapi.lib
% includelib &LibPath&Windows\Msimg32.lib
% includelib &LibPath&Windows\Ole32.lib
% includelib &LibPath&Windows\GdiPlus.lib

;Load or build the following objects
MakeObjects Primer, Stream, WinPrimer
MakeObjects Window, Button, Hyperlink, Dialog, DialogModal, DialogAbout
MakeObjects Throbber, SpinningThrobber
MakeObjects WinApp, SdiApp
MakeObjects Collection, DataCollection, SortedCollection, SortedDataCollection, XWCollection
MakeObjects TextView


include SpinningThrobber_Globals.inc                    ;Application globals
include SpinningThrobber_Main.inc                       ;Application object

.code
start proc                                              ;Program entry point
  local dMajorVersion:DWORD

  SysInit                                               ;Runtime initialization of OOP model

  DbgClearAll
  ResGuard_Start

  invoke GetWinVersion, addr dMajorVersion, NULL, NULL
  .if dMajorVersion < 8
    invoke MsgBox, 0, offset cWarningMsg, offset cAppWarning, MB_OK
  .else
    invoke CoInitialize, 0
    OCall $ObjTmpl(Application)::Application.Init       ;Initialize application
    OCall $ObjTmpl(Application)::Application.Run        ;Execute application
    OCall $ObjTmpl(Application)::Application.Done       ;Finalize application
    invoke CoUninitialize
  .endif

  ResGuard_Show
  ResGuard_Stop

  SysDone                                               ;Runtime finalization of the OOP model
  invoke ExitProcess, 0                                 ;Exit program returning 0 to the OS
start endp

end
