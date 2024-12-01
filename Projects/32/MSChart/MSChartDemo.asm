; ==================================================================================================
; Title:      MSChartDemo.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm charting demo with MSChart.
; Notes:      Version C.1.0, October 2017
;               - First release.
;               - MSChrt20.ocx is unfortunately 32-bit only.  
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc
SysSetup OOP, WIN32, WIDE_STRING;, DEBUG(WND)

include MSChartDemo_Globals.inc

% include &MacPath&fMath.inc
% include &MacPath&Strings.inc
% include &MacPath&BStrings.inc

% include &COMPath&COM.inc
% include &IncPath&Windows\sGUID.inc
% include &IncPath&Windows\ocidl.inc
% include &IncPath&Windows\OleCtl.inc

% include &COMPath&COM_Dispatch.inc
% include &COMPath&COM_Dispatch.inc
% include &COMPath&COM_Dispatch.asm

% include MSChart20Lib.inc

% includelib &LibPath&Windows\Ole32.lib
% includelib &LibPath&Windows\OleAut32.lib
% includelib &LibPath&Windows\Shell32.lib
% includelib &LibPath&Windows\Shlwapi.lib


MakeObjects Primer, Stream, Collection, DataCollection
MakeObjects WinPrimer, Window, Button, Hyperlink, Dialog, DialogModal, DialogAbout
MakeObjects WinApp, SdiApp
MakeObjects COM_Primers, IDispatch, ConnectionPoint, IConnectionPointContainer
MakeObjects MSChart

.const
DefGUID IID_NULL, %sGUID_NULL
DefGUID IID_IUnknown, %sIID_IUnknown
DefGUID IID__DMSChart, %sIID__DMSChart
DefGUID IID__DMSChartEvents, %sIID__DMSChartEvents
DefGUID IID_IConnectionPointContainer, %sIID_IConnectionPointContainer
DefGUID IID_IConnectionPoint, %sIID_IConnectionPoint
DefGUID IID_IEnumConnections, %sIID_IEnumConnections
DefGUID IID_IEnumConnectionPoints, %sIID_IEnumConnectionPoints
DefGUID IID_IDispatch, %sIID_IDispatch
DefGUID IID_IOleObject, %sIID_IOleObject

DefGUID TLBID_MSChart20Lib, %sTLBID_MSChart20Lib


.code

include MSChartDemo_Main.inc

start proc
  SysInit

  invoke CoInitialize, 0

  OCall $ObjTmpl(Application)::Application.Init
  OCall $ObjTmpl(Application)::Application.Run
  OCall $ObjTmpl(Application)::Application.Done

  invoke CoUninitialize

  SysDone

  invoke ExitProcess, 0
start endp

end
