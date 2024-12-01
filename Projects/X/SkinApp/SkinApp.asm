; ==================================================================================================
; Title:      Application.asm
; Author:     G. Friedrich
; Version:    1.0.0
; Purpose:    ObjAsm Skined Application.
; Notes:      Version 1.0.0, November 2017
;               - First release.
; ==================================================================================================


%include @Environ(OBJASM_PATH)\\Code\\Macros\\Model.inc ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND, ResGuard)

% include &MacPath&Strings.inc                          ;Load WIDE string support
% include &MacPath&DlgTmpl.inc                          ;Load tempate dialog support
% include &MacPath&ConstDiv.inc
% include &IncPath&Windows\CommCtrl.inc

% includelib &LibPath&Windows\Shell32.lib
% includelib &LibPath&Windows\OLE32.lib
% includelib &LibPath&Windows\Comctl32.lib

;Load or build the following objects
MakeObjects Primer, Stream, Collection, DataCollection
MakeObjects WinPrimer, Window, Dialog, DialogModal
MakeObjects SimpleImageList, MaskedImageList
MakeObjects MsgInterceptor, DialogModalIndirect, XMenu
MakeObjects WinControl, Tooltip
MakeObjects Button, RgnButton, Hyperlink
MakeObjects GifDecoder, GifPlayer
MakeObjects ElasticSkin, SkinnedMsgBox, SkinnedDialogAbout
MakeObjects WinApp, SdiApp

.code
include SkinApp_Globals.inc                             ;Include application globals
include SkinApp_Main.inc                                ;Include Application referenced object

start proc                                              ;Program entry point
  SysInit                                               ;Runtime initialization of OOP model

  ResGuard_Start

  invoke CoInitializeEx, NULL, COINIT_APARTMENTTHREADED or COINIT_DISABLE_OLE1DDE
  OCall $ObjTmpl(Application)::Application.Init         ;Initialize the object data
  OCall $ObjTmpl(Application)::Application.Run          ;Execute the application
  OCall $ObjTmpl(Application)::Application.Done         ;Finalize it
  invoke CoUninitialize

  ResGuard_Show
  ResGuard_Stop

  SysDone                                               ;Runtime finalization of the OOP model
  invoke ExitProcess, 0                                 ;Exit program returning 0 to the OS
start endp

end
