; ==================================================================================================
; Title:      RibbonApp.asm
; Author:     G. Friedrich
; Version:    1.0.0
; Purpose:    ObjAsm Ribbon Application.
; Link:       https://msdn.microsoft.com/en-us/library/windows/desktop/dd316924(v=vs.85).aspx
; Notes:      Version 1.0.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND, ResGuard)

COM_MTD_STD textequ <STD_METHOD>

% include &MacPath&fMath.inc
% include &MacPath&BStrings.inc                         ;BSTR support
% include &COMPath&COM.inc
% include &IncPath&Windows\sGUID.inc

% include &IncPath&Windows\shellapi.inc
% include &IncPath&Windows\CommCtrl.inc
% include &IncPath&Windows\propkeydef.inc

% includelib &LibPath&Windows\Shell32.lib
% includelib &LibPath&Windows\Comctl32.lib
% includelib &LibPath&Windows\shlwapi.lib
% includelib &LibPath&Windows\Ole32.lib
% includelib &LibPath&Windows\OleAut32.lib

% include &COMPath&UIRibbon.inc

.const
DefGUID IID_NULL, %sGUID_NULL
DefGUID IID_IUnknown, %sIID_IUnknown
DefGUID IID_IDispatch, %sIID_IDispatch

DefGUID CLSID_UIRibbonFramework, %sCLSID_UIRibbonFramework
DefGUID IID_IUIApplication, %sIID_IUIApplication
DefGUID IID_IUICommandHandler, %sIID_IUICommandHandler
DefGUID IID_IUIRibbon, %sIID_IUIRibbon

.code
;Load or build the following objects
MakeObjects Primer, Stream, Collection, DataCollection
MakeObjects WinPrimer, Window, Button, Hyperlink
MakeObjects Dialog, DialogModal, DialogAbout
MakeObjects WinApp, SdiApp
MakeObjects COM_Primers, Ribbon

include RibbonApp_Globals.inc
include RibbonApp_Main.inc

start proc
  SysInit

  ResGuard_Start
  invoke CoInitialize, 0
  invoke InitCommonControls

  DbgClearAll
  OCall $ObjTmpl(RibbonApp)::RibbonApp.Init
  OCall $ObjTmpl(RibbonApp)::RibbonApp.Run
  OCall $ObjTmpl(RibbonApp)::RibbonApp.Done

  invoke CoUninitialize

  ResGuard_Show
  ResGuard_Stop

  SysDone

  invoke ExitProcess, 0
start endp

end
