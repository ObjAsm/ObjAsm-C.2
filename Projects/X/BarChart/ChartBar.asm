; ==================================================================================================
; Title:      ChartBar.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm ChartBar demonstration program.
; Notes:      Version C.1.0, August 2021
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND)

% include &MacPath&fMath.inc

% include &MacPath&Strings.inc                          ;Include wide string support for DlgTmpl
% include &MacPath&DlgTmpl.inc                          ;Include Dlg Template macros for XMenu
% include &MacPath&ConstDiv.inc
% include &IncPath&Windows\CommCtrl.inc
% include &IncPath&Windows\UxTheme.inc
% include &IncPath&Windows\vsstyle.inc
% include &IncPath&Windows\IImgCtx.inc
% include &IncPath&Windows\richedit.inc

% includelib &LibPath&Windows\Shell32.lib
% includelib &LibPath&Windows\Comdlg32.lib
% includelib &LibPath&Windows\Comctl32.lib
% includelib &LibPath&Windows\shlwapi.lib
% includelib &LibPath&Windows\UxTheme.lib
% includelib &LibPath&Windows\OleAut32.lib
% includelib &LibPath&Windows\Ole32.lib
% includelib &LibPath&Windows\Msimg32.lib

INCLUDE_CHART_SETUP_DIALOG = TRUE

;Load or build the following objects
MakeObjects Primer, Stream
MakeObjects Collection, DataCollection, SortedCollection, SortedDataCollection, XWCollection
MakeObjects WinPrimer, Window, GifDecoder, GifPlayer
MakeObjects Dialog, DialogModal, DialogModeless, DialogAbout, DialogPassword
MakeObjects SimpleImageList, MaskedImageList
MakeObjects Button, IconButton, ColorButton, Hyperlink
MakeObjects MsgInterceptor, DialogModalIndirect, XMenu
MakeObjects WinControl, Toolbar, Rebar, Statusbar, TabCtrl, TextView
MakeObjects WinApp, MdiApp
MakeObjects Array, Chart, ChartBar, ChartXY

include ChartBar_Globals.inc
include ChartBar_Main.inc

start proc
  SysInit
  DbgClearAll

  finit
  invoke CoInitialize, 0                                ;Required for Image object
  OCall $ObjTmpl(Application)::Application.Init
  OCall $ObjTmpl(Application)::Application.Run
  OCall $ObjTmpl(Application)::Application.Done
  invoke CoUninitialize

  SysDone
  invoke ExitProcess, 0
start endp

end
