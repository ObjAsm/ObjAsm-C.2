; ==================================================================================================
; Title:      Api3DEng.asm
; Author:     G. Friedrich
; Version:    2.0.0
; Purpose:    ObjAsm API 3D Engine program.
; Notes:      Version 2.0.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND);, ResGuard)

% include &MacPath&fMath.inc
% include &MacPath&DlgTmpl.inc
% include &MacPath&ConstDiv.inc

% include &IncPath&Windows\CommCtrl.inc

% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\Comctl32.lib
% includelib &LibPath&Windows\shlwapi.lib
% includelib &LibPath&Windows\Winmm.lib
% includelib &LibPath&Windows\Msimg32.lib

include Api3DEng_Globals.inc

MakeObjects Primer, Stream, DiskStream, StopWatch
MakeObjects Collection, DataCollection, SortedCollection, SortedDataCollection
MakeObjects WinPrimer, Window, Button, Hyperlink
MakeObjects Dialog, DialogModal, DialogAbout, DialogModalIndirect
MakeObjects SimpleImageList, MaskedImageList, MsgInterceptor
MakeObjects WinControl, Toolbar, Statusbar, XMenu
MakeObjects WinApp, SdiApp
MakeObjects Vector, DWordVector, SortedDwordVector

MakeObjects D3Engine

include Api3DEng_Main.inc

start proc
  SysInit

  DbgClearAll
  ResGuard_Start
  fSetPrecision REAL4
  OCall $ObjTmpl(Application)::Application.Init
  OCall $ObjTmpl(Application)::Application.Run
  OCall $ObjTmpl(Application)::Application.Done
  ResGuard_Show
  ResGuard_Stop

  SysDone
  invoke ExitProcess, 0
start endp

end
