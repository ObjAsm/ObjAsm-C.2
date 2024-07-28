; ==================================================================================================
; Title:      OA_Tools.asm
; Author:     G. Friedrich
; Version:    1.0.1
; Purpose:    ObjAsm Tools.
; Notes:      Version 1.0.1, July, 2024
;               - Detection and handling of "using" in MASM64 SDK added by HSE.
;             Version 1.0.0, October 2017
;               - First release.
; ==================================================================================================


%include @Environ(OBJASM_PATH)\\Code\\Macros\\Model.inc ;Include & initialize standard modules

;ANSI_STRING will not work on languages that use UNICODE characters, like chinese or russian.
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND, ResGuard)

GDIPVER equ 0100h

% include &COMPath&COM.inc                              ;COM basic support
% include &IncPath&Windows\sGUID.inc

% include &MacPath&Strings.inc                          ;Include wide string support for DlgTmpl
% include &MacPath&DlgTmpl.inc                          ;Include Dlg Template macros for XMenu
% include &MacPath&ConstDiv.inc
% include &MacPath&QuadWord.inc
% include &IncPath&Windows\CommCtrl.inc
% include &IncPath&Windows\richedit.inc
% include &IncPath&Windows\UxTheme.inc
% include &IncPath&Windows\vsstyle.inc
% include &IncPath&Windows\Shlwapi.inc
% include &IncPath&Windows\ShObjIDL.inc
% include &IncPath&Windows\ShTypes.inc
% include &IncPath&Windows\GdiplusPixelFormats.inc
% include &IncPath&Windows\GdiplusInit.inc
% include &IncPath&Windows\GdiplusEnums.inc
% include &IncPath&Windows\GdiplusGpStubs.inc
% include &IncPath&Windows\GdiPlusFlat.inc

% includelib &LibPath&Windows\Shell32.lib
% includelib &LibPath&Windows\Comdlg32.lib
% includelib &LibPath&Windows\Comctl32.lib
% includelib &LibPath&Windows\shlwapi.lib
% includelib &LibPath&Windows\UxTheme.lib
% includelib &LibPath&Windows\Ole32.lib
% includelib &LibPath&Windows\OleAut32.lib
% includelib &LibPath&Windows\GdiPlus.lib

sCLSID_FileOpenDialog   textequ   <DC1C5A9C-E88A-4DDE-A5A1-60F82A20AEF7>
sIID_IFileDialog2       textequ   <61744FC7-85B5-4791-A9B0-272276309B13>
sIID_IShellItem         textequ   <43826d1e-e718-42ee-bc55-a1e261c37bfe>

.const
DefGUID IID_NULL, %sGUID_NULL
DefGUID IID_IUnknown, %sIID_IUnknown
DefGUID CLSID_FileOpenDialog, %sCLSID_FileOpenDialog
DefGUID IID_IFileOpenDialog, %sIID_IFileOpenDialog
DefGUID IID_IFileDialog2, %sIID_IFileDialog2
DefGUID IID_IShellItem, %sIID_IShellItem

;Load or build the following objects
MakeObjects Primer, Stream, DiskStream
MakeObjects Collection, DataCollection, SortedCollection, SortedStrCollectionA
MakeObjects WinPrimer, Window, Button, Hyperlink, IconButton, ColorButton
MakeObjects Dialog, DialogModal, DialogModeless, DialogModalIndirect
MakeObjects SimpleImageList, MaskedImageList, MsgInterceptor, XMenu
MakeObjects WinControl, TabCtrl, Toolbar, Rebar, Statusbar, Tooltip
MakeObjects RegKey, WinApp, MdiApp

.code
include OA_Tools_Globals.inc                            ;Include application globals
include OA_Tools_Main.inc                               ;Include OAT_App object

start proc uses xbx                                     ;Program entry point
  SysInit                                               ;Runtime initialization of OOP model
  ResGuard_Start

  mov xbx, $invoke(LoadLibrary, $OfsCStr("RichEd20.dll"))

  invoke CoInitialize, 0
  invoke InitCommonControls

  OCall $ObjTmpl(OAT_App)::OAT_App.Init                 ;Initialize the object data
  OCall $ObjTmpl(OAT_App)::OAT_App.Run                  ;Execute the application
  OCall $ObjTmpl(OAT_App)::OAT_App.Done                 ;Finalize it

  invoke CoUninitialize
  invoke FreeLibrary, xbx                               ;Unload RichEdit library

  ResGuard_Show
  ResGuard_Stop

  SysDone                                               ;Runtime finalization of the OOP model
  invoke ExitProcess, 0                                 ;Exit program returning 0 to the OS
start endp

end
