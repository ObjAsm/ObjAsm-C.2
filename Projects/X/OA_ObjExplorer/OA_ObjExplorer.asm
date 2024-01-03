; ==================================================================================================
; Title:      OA_ObjExplorer.asm
; Author:     G. Friedrich
; Version:    2.0.1
; Purpose:    ObjAsm Object Explorer Application.
; Notes:      Version 1.0.0, December 2017
;               - First release.
;             Version 1.1.0, August 2020
;               - WebBrowser rendering replaced by TextView.
;             Version 2.0.0, October 2021
;               - General overhaul.
;             Version 2.0.1, November 2022
;               - OA_Info.stm: name and path moved to ini file.
;
; Todos:      - Namespaces need better handling
;             - Interfaces are not recognized --> API convention change! See h2incX project
;             - HelpLines are not collected nor displayed
;             - Set some information on the StatusBar from resources
;             - Context menu is not used. Code remains for future use
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc
SysSetup OOP, WIN64, ANSI_STRING;, DEBUG(WND, ResGuard)           ;MUST be ANSI!!!

% includelib &LibPath&Windows\Kernel32.lib
% includelib &LibPath&Windows\Shell32.lib
% includelib &LibPath&Windows\Shlwapi.lib
% includelib &LibPath&Windows\UxTheme.lib
% includelib &LibPath&Windows\Comctl32.lib
% includelib &LibPath&Windows\Comdlg32.lib
% includelib &LibPath&Windows\MSVCRT.lib
% includelib &LibPath&Windows\UUID.lib
% includelib &LibPath&Windows\Ole32.lib
% includelib &LibPath&Windows\Msimg32.lib

% includelib &LibPath&PCRE\PCRE844S&TARGET_STR_AFFIX&.lib

% include &COMPath&COM.inc                              ;COM basic support
% include &IncPath&Windows\IImgCtx.inc
% include &IncPath&Windows\CommCtrl.inc
% include &IncPath&Windows\vsstyle.inc
% include &IncPath&Windows\shlwapi.inc
% include &IncPath&Windows\uxtheme.inc
% include &IncPath&Windows\richedit.inc

% include &IncPath&PCRE\PCRE844S.inc

% include &MacPath&DlgTmpl.inc                          ;Include Dlg Template macros for XMenu
% include &MacPath&ConstDiv.inc
% include &MacPath&SDLL.inc
% include &MacPath&fMath.inc

.code
;Load or build the following objects
MakeObjects Primer, Stream, DiskStream, MemoryStream
MakeObjects Collection, DataCollection, SortedCollection, SortedDataCollection, XWCollection
MakeObjects SimpleImageList, MaskedImageList
MakeObjects StopWatch
MakeObjects WinPrimer, Window
MakeObjects Dialog, DialogModal, DialogModeless
MakeObjects WinControl, Button, IconButton, Hyperlink
MakeObjects MsgInterceptor, DialogModalIndirect, XMenu
MakeObjects Toolbar, Rebar, Statusbar
MakeObjects DataPool, IniFile, RegEx
MakeObjects FlipBox, Splitter, XTreeView
MakeObjects Image
MakeObjects WinApp, MdiApp, TextView


include OAE_TextSource.inc
include OAE_ObjDB_Collections.inc
include OAE_ObjDB.inc
include OAE_InfoTree.inc
include OAE_TreeWindow.inc
include OA_ObjExplorer_Globals.inc
include OAE_AboutDlg.inc
include OA_ObjExplorer_Main.inc
include OAE_PropWnd.inc
include OAE_IntPropWnd.inc
include OAE_ObjPropWnd.inc
include OAE_SetupDlg.inc
include OAE_FindInfoDlg.inc


start proc
  SysInit

  ResGuard_Start
  DbgClearAll
  invoke CoInitialize, 0                                ;Required for Image object
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
