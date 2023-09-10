; ==================================================================================================
; Title:      MsgBoxApp.asm
; Author:     G. Friedrich
; Version:    1.0.0
; Purpose:    ObjAsm MsgBox Application.
; Notes:      Version 1.0.0, April 2020
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND, ResGuard)

% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\shlwapi.lib
% includelib &LibPath&Windows\Ole32.lib
% includelib &LibPath&Windows\Msimg32.lib

% include &COMPath&COM.inc                              ;COM basic support
% include &IncPath&Windows\CommCtrl.inc
% include &IncPath&Windows\IImgCtx.inc
% include &IncPath&Windows\richedit.inc

;Load or build the following objects
MakeObjects Primer, Stream, WinPrimer, Button, Hyperlink
MakeObjects Collection, DataCollection, SortedCollection, SortedDataCollection, XWCollection
MakeObjects Window, Dialog, DialogModal, DialogAbout, Image
MakeObjects WinApp, SdiApp
MakeObjects TextView

include MsgBoxApp_Globals.inc
include MsgBoxApp_Main.inc

.code
start proc
  SysInit
  DbgClearAll

  ResGuard_Start
  invoke CoInitialize, 0                              ;Required for Image object
  OCall $ObjTmpl(Application)::Application.Init
  OCall $ObjTmpl(Application)::Application.Run
  OCall $ObjTmpl(Application)::Application.Done
  invoke CoUninitialize
  ResGuard_Show
  ResGuard_Stop

  SysDone
  invoke ExitProcess, 0
start endp

end
