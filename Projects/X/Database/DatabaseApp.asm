; ==================================================================================================
; Title:      DatabaseApp.asm
; Author:     G. Friedrich
; Version:    1.1.0
; Purpose:    ObjAsm Database Application.
; Notes:      Version 1.1.0, August 2019
;             - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND)

% include &COMPath&COM.inc                              ;COM basic support

% include &MacPath&fMath.inc
% include &MacPath&ConstDiv.inc
% include &MacPath&DlgTmpl.inc
% include &MacPath&QuadWord.inc
% include &IncPath&Windows\sGUID.inc

% include &IncPath&Windows\ShellApi.inc
% include &IncPath&Windows\CommCtrl.inc
% include &IncPath&Windows\shlwapi.inc
% include &IncPath&Windows\uxtheme.inc
% include &IncPath&Windows\vsstyle.inc
% include &IncPath&Windows\richedit.inc
% include &IncPath&Windows\ShObjIDL.inc
% include &IncPath&Windows\ShTypes.inc
% include &IncPath&Windows\IImgCtx.inc


% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\Ole32.lib
% includelib &LibPath&Windows\OleAut32.lib
% includelib &LibPath&Windows\Comctl32.lib
% includelib &LibPath&Windows\shlwapi.lib
% includelib &LibPath&Windows\uxtheme.lib
% includelib &LibPath&Windows\Msimg32.lib


include DatabaseApp_Globals.inc

sCLSID_FileOpenDialog   textequ   <DC1C5A9C-E88A-4DDE-A5A1-60F82A20AEF7>
sIID_IFileDialog2       textequ   <61744FC7-85B5-4791-A9B0-272276309B13>

.const
DefGUID IID_NULL, %sGUID_NULL
DefGUID IID_IUnknown, %sIID_IUnknown
DefGUID CLSID_FileOpenDialog, %sCLSID_FileOpenDialog
DefGUID IID_IFileOpenDialog, %sIID_IFileOpenDialog
DefGUID IID_IFileDialog2, %sIID_IFileDialog2

MakeObjects Primer, Stream, DiskStream, StopWatch
MakeObjects Collection, DataCollection, SortedCollection, XWCollection
MakeObjects WinPrimer, Window, Button, IconButton, Hyperlink
MakeObjects Dialog, DialogModal, DialogAbout, DialogProgress
MakeObjects SimpleImageList, MaskedImageList
MakeObjects MsgInterceptor, DialogModalIndirect, XMenu, Image
MakeObjects WinControl, ListView, Toolbar, Statusbar, ScrollBar, Progressbar
MakeObjects WinApp, SdiApp

LoadObjects Database
MakeObjects DB_RecordEditor, DB_RecordEditorDlg
MakeObjects DB_StructEditor, DB_StructEditorDlg, DB_NewTableDlg
MakeObjects DB_SeekDlg, DB_QueryDlg, DB_IndexDlg

include DatabaseApp_Main.inc

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
