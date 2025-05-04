; ==================================================================================================
; Title:      ADE.asm
; Author:     G. Friedrich
; Version:    1.0.0
; Purpose:    ObjAsm Assembler Development Environment. (ASM DevSuite Pro)
; Notes:      Version 1.0.0, November 2024
;               - First release.
; Features:
;   - Syntax highlighting
;   - Text highlighting of selected word
;   - Clipboard functions (Cut, Copy, Paste, Delete)
;   - Zoom in/out
;   - Block, Insert and Overwrite modes
;   - Touch gestures (Pan & Zoom)
;   - Horizontal mouse wheel support
;   - File formats (ANSI, WIDE, UFT-8, UTF-16-BOM)
;   - Line termination (CR, LF, CRLF, NULL)
;   - Save/SaveAs new style dialog
;   - Load new style dialog
;   - Drag & Drop, It automatically detects the file content and selects the best template.
;   - Control Keys
;   - Search modeless dialog (Dynamic Layout)
;   - General menu languages (English, German, Italian, Russian, Spanish)
;   - Toolbars (File, Edit, Window)
;   - Statusbar Information
;   - Ini-file configuration
;   - SEH protection
;   - Find and Replace functionality
;   - ChildWnd magnetic snapping
;   - 32 and 64 bit release versions
;   - Fast loading (~100MB/s) and rendering
;   - WM_QUERYENDSESSION logic 
;   - File.New now has the option to select the editor template 
;   - Same functionality for the "New" toolbar button using a drop down button.
;   - Editor templates: MASM, Resource & Plain Text. Each template has its own settings in the ini file 
;   - Information in the status bar what the application thinks it is editing 
;   - Tooltips for the toolbars 
;   - GetThemeBitmap, BeginBufferedAnimation
; 
; ==================================================================================================

;Note: comment $$RegCntMM = 0 in system.inc 


%include @Environ(OBJASM_PATH)\\Code\\Macros\\Model.inc ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING, DEBUG(WND, INFO);, ResGuard)  ;Load OOP files and OS related objects
;Note: don't use ANSI_STRING 

% include &MacPath&DlgTmpl.inc                          ;Dialog Template macros for XMenu
% include &MacPath&ConstDiv.inc
% include &MacPath&fMath.inc
% include &MacPath&LDLL.inc
% include &COMPath&COM.inc

% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\Comctl32.lib
% includelib &LibPath&Windows\shlwapi.lib
% includelib &LibPath&Windows\UxTheme.lib
% includelib &LibPath&Windows\Comdlg32.lib
% includelib &LibPath&Windows\Shell32.lib
% includelib &LibPath&Windows\Ole32.lib
% includelib &LibPath&Windows\OleAut32.lib
% includelib &LibPath&Windows\Msimg32.lib

% include &IncPath&Windows\CommCtrl.inc
% include &IncPath&Windows\UxTheme.inc
% include &IncPath&Windows\vsstyle.inc
% include &IncPath&Windows\WinUser.inc
% include &IncPath&Windows\commdlg.inc
% include &IncPath&Windows\Richedit.inc
% include &IncPath&Windows\IImgCtx.inc
% include &IncPath&Windows\ShellApi.inc
% include &IncPath&Windows\ShObjIDL.inc
% include &IncPath&Windows\ShTypes.inc
% include &IncPath&Windows\sGUID.inc

if TARGET_BITNESS eq 32
% include &MacPath&Exception32.inc
  SEH_FRAME textequ <>
else
%   include &MacPath&Exception64.inc
  SEH_FRAME textequ <FRAME:EHandler>
endif
% include &MacPath&MemBlock.inc
% include &IncPath&ObjAsm\MStrProcs.inc

sCLSID_FileOpenDialog   textequ   <DC1C5A9C-E88A-4DDE-A5A1-60F82A20AEF7>
sCLSID_FileSaveDialog   textequ   <C0B4E2F3-BA21-4773-8DBA-335EC946EB8B>
sIID_IFileDialog2       textequ   <61744FC7-85B5-4791-A9B0-272276309B13>

.const
DefGUID IID_NULL, %sGUID_NULL
DefGUID IID_IUnknown, %sIID_IUnknown
DefGUID CLSID_FileOpenDialog, %sCLSID_FileOpenDialog
DefGUID CLSID_FileSaveDialog, %sCLSID_FileSaveDialog
DefGUID IID_IFileOpenDialog, %sIID_IFileOpenDialog
DefGUID IID_IFileSaveDialog, %sIID_IFileSaveDialog
DefGUID IID_IFileDialog2, %sIID_IFileDialog2

.code
;Load or build the following objects
MakeObjects Primer, Stream, DiskStream
MakeObjects Collection, SortedCollection, DataCollection, SortedDataCollection, StrCollection
MakeObjects Vector, XWordVector
MakeObjects WinPrimer, Window, Dialog, DialogModal, DialogModeless
MakeObjects SimpleImageList, MaskedImageList
MakeObjects Button, IconButton, Hyperlink
MakeObjects MsgInterceptor, DialogModalIndirect, XMenu, Magnetism, Image
MakeObjects WinControl, Toolbar, Rebar, Statusbar, ComboBox, TreeView, ListView, TabCtrl, ScrollBar
MakeObjects XWCollection, TextView
MakeObjects FlipBox, Splitter
MakeObjects WinApp, MdiApp
;MakeObjects COM_Primers

include ADE_Globals.inc                                 ;Application globals
include ADE_PropertiesWnd.inc
include ADE_Main.inc                                    ;Application object

start proc SEH_FRAME                                    ;Program entry point
  SysInit                                               ;Runtime initialization of OOP model
  DbgClearAll

  ResGuard_Start
  invoke InitCommonControls  
  invoke CoInitialize, NULL

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
