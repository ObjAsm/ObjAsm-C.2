; ==================================================================================================
; Title:      Demo07.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm demonstration program Demo07.
;
; Description:
;   This module contains the application entry point and system-level initialization required
;   for Demo07, an advanced ObjAsm MDI demonstration. The file performs:
;     - ObjAsm runtime initialization (SysInit, SysDone)
;     - COM initialization for image and multimedia components
;     - Resource Guard activation for leak detection
;     - Floating-point environment initialization
;     - Creation and execution of the Application object (Init => Run => Done)
;
;   Demo07 showcases extended GUI capabilities, including:
;     - Charting and XY plotting (ChartWnd, ChartXY)
;     - Rich user interface controls (Toolbars, Rebars, Tabs, TextView, themed controls)
;     - Dialogs (modal, modeless, password, about-box)
;     - Gif decoding and playback
;     - Icon and color button controls
;     - XMenu and extended menu handling
;
;   This module loads a diverse set of supporting objects and libraries, integrates the
;   Windows common control framework, and binds the Demo07_Main and Demo07_Globals
;   implementation modules to construct the complete application environment.
;
; Notes:
;   Version C.1.0 - August 2021
;       - Initial release.

; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND, ResGuard)

% include &MacPath&fMath.inc

% include &MacPath&Strings.inc                          ; Include wide string support for DlgTmpl
% include &MacPath&DlgTmpl.inc                          ; Include Dlg Template macros for XMenu
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

;Load or build the following objects
MakeObjects Primer, Stream
MakeObjects Collection, DataCollection, SortedCollection, SortedDataCollection, XWCollection
MakeObjects WinPrimer, Window, GifDecoder, GifPlayer
MakeObjects Button, Hyperlink, Dialog, DialogModal, DialogModeless, DialogAbout, DialogPassword
MakeObjects SimpleImageList, MaskedImageList
MakeObjects IconButton, ColorButton
MakeObjects MsgInterceptor, DialogModalIndirect, XMenu
MakeObjects WinControl, Toolbar, Rebar, Statusbar, TabCtrl, TextView
MakeObjects WinApp, MdiApp
MakeObjects Array, Chart, ChartXY

include Demo07_Globals.inc
include Demo07_Main.inc

start proc
  SysInit
  DbgClearAll

  ResGuard_Start
  finit
  invoke CoInitialize, 0                                ; Required for Image object
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
