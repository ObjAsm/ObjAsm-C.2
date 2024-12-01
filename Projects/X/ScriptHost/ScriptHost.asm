; ==================================================================================================
; Title:      ScriptHost.asm
; Author:     G. Friedrich
; Version:    1.0.0
; Purpose:    ObjAsm ScriptHost Application.
; Notes:      Version 1.0.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND, ResGuard)

% include &MacPath&Strings.inc                              ;Wide string support
% include &MacPath&BStrings.inc                             ;BSTR support
% include &COMPath&COM.inc                                  ;COM basic support
% include &COMPath&COM_Dispatch.inc

% include &IncPath&Windows\Shlwapi.inc
% include &IncPath&Windows\ActivScp.inc
% include &IncPath&Windows\ActivDbg.inc
% include &IncPath&Windows\Richedit.inc
% include &IncPath&Windows\CommCtrl.inc
% include &IncPath&Windows\sGUID.inc

% includelib &LibPath&Windows\Comctl32.lib
% includelib &LibPath&Windows\Shell32.lib
% includelib &LibPath&Windows\Ole32.lib
% includelib &LibPath&Windows\OleAut32.lib
% includelib &LibPath&Windows\Comdlg32.lib
% includelib &LibPath&Windows\Shlwapi.lib

sCLSID_ProcessDebugManager textequ <78A51822-51F4-11D0-8F20-00805F2CD064>

.const                                                      ;GUID global constants
;Allocate the GUIDs used by the Script Engine
DefGUID IID_NULL, %sGUID_NULL
DefGUID IID_IUnknown, %sIID_IUnknown
DefGUID IID_IClassFactory, %sIID_IClassFactory
DefGUID IID_IDispatch, %sIID_IDispatch
DefGUID IID_IActiveScript, %sIID_IActiveScript
if TARGET_BITNESS eq 32
  DefGUID IID_IActiveScriptParse, %sIID_IActiveScriptParse32
  DefGUID IID_IProcessDebugManager, %sIID_IProcessDebugManager32
  DefGUID IID_IActiveScriptSiteDebug, %sIID_IActiveScriptSiteDebug32
else
  DefGUID IID_IActiveScriptParse, %sIID_IActiveScriptParse64
  DefGUID IID_IProcessDebugManager, %sIID_IProcessDebugManager64
  DefGUID IID_IActiveScriptSiteDebug, %sIID_IActiveScriptSiteDebug64
endif
DefGUID IID_IActiveScriptSite, %sIID_IActiveScriptSite
DefGUID IID_IActiveScriptSiteWindow, %sIID_IActiveScriptSiteWindow
DefGUID CLSID_ProcessDebugManager, %sCLSID_ProcessDebugManager

;Allocate the GUID that specifies our Visual Basic Script Engine
DefGUID CLSID_VBScript, <B54F3741-5B07-11cf-A4B0-00AA004A55E8>

;Allocate the GUIDs of our new script elements
DefGUID CLSID_CScriptOutput, <2B5DF56D-C8D8-4098-9A73-F8337166F767>
DefGUID LIBID_LScriptOutput, <BB69A4F3-5A9B-4026-9AA5-15EA3B42C361>
DefGUID IID_IScriptOutput,   <AB0B8860-62D3-4f17-A875-37CDA03229B8>

;Load or build the following objects
MakeObjects Primer, Stream, Collection, DataCollection
MakeObjects WinPrimer, Window, Button, Hyperlink
MakeObjects Dialog, DialogModal, DialogAbout, DialogModeless
MakeObjects WinControl, FlipBox, Splitter
MakeObjects COM_Primers, IDispatch, IDual
MakeObjects ScriptHost

.code
include ScriptHost_Globals.inc
include ScriptHost_Main.inc

start proc uses xbx
  SysInit
  
  ResGuard_Start

  DbgClearAll

  invoke InitCommonControls
  mov xbx, $invoke(LoadLibraryW, $OfsCStrW("RichEd20.dll"))

  OCall $ObjTmpl(Application)::Application.Init, NULL, 0, IDD_MAIN
  OCall $ObjTmpl(Application)::Application.Show
  OCall $ObjTmpl(Application)::Application.Done

  invoke FreeLibrary, xbx

  ResGuard_Show
  ResGuard_Stop

  SysDone
  invoke ExitProcess, 0
start endp

end
