; ==================================================================================================
; Title:      IFileDialogApp.asm
; Author:     G. Friedrich
; Version:    1.0.0
; Purpose:    ObjAsm IFileDialog Application.
; Link:       https://msdn.microsoft.com/en-us/library/windows/desktop/dd316924(v=vs.85).aspx
; Notes:      Version 1.0.0, October 2017
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc
SysSetup OOP, WIN64, ANSI_STRING;, DEBUG(WND)

% include &COMPath&COM.inc
% include &IncPath&Windows\sGUID.inc

% include &IncPath&Windows\ShellApi.inc
% include &IncPath&Windows\CommCtrl.inc
% include &IncPath&Windows\ShObjIDL.inc
% include &IncPath&Windows\ShTypes.inc

% includelib &LibPath&Windows\Comctl32.lib
% includelib &LibPath&Windows\Shell32.lib
% includelib &LibPath&Windows\Ole32.lib
% includelib &LibPath&Windows\OleAut32.lib
% includelib &LibPath&Windows\shlwapi.lib

sCLSID_FileOpenDialog   textequ   <DC1C5A9C-E88A-4DDE-A5A1-60F82A20AEF7>
sIID_IFileDialog2       textequ   <61744FC7-85B5-4791-A9B0-272276309B13>

.const
DefGUID IID_NULL, %sGUID_NULL
DefGUID IID_IUnknown, %sIID_IUnknown
DefGUID CLSID_FileOpenDialog, %sCLSID_FileOpenDialog
DefGUID IID_IFileOpenDialog, %sIID_IFileOpenDialog
DefGUID IID_IFileDialog2, %sIID_IFileDialog2

.code
;Load or build the following objects
MakeObjects Primer, Stream, Collection, DataCollection
MakeObjects WinPrimer, Window, Button, Hyperlink
MakeObjects Dialog, DialogModal, DialogAbout
MakeObjects WinApp, SdiApp
MakeObjects COM_Primers

include IFileDialogApp_Globals.inc
include IFileDialogApp_Main.inc

start proc
  SysInit
  invoke CoInitialize, 0
  invoke InitCommonControls

  DbgClearAll
  OCall $ObjTmpl(Application)::Application.Init
  OCall $ObjTmpl(Application)::Application.Run
  OCall $ObjTmpl(Application)::Application.Done

  invoke CoUninitialize
  SysDone

  invoke ExitProcess, 0
start endp

end
