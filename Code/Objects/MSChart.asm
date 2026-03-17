; ==================================================================================================
; Title:      MSChart.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for MSChart object.
; Notes:      Version C.1.0, November 2017
;             - Initial release.
; ==================================================================================================


% include Objects.cop

% include &MacPath&Strings.inc
% include &MacPath&BStrings.inc
% include &IncPath&Windows\sGUID.inc
% include &IncPath&Windows\ocidl.inc
% include &IncPath&Windows\OleCtl.inc

% include &COMPath&COM.inc
% include &COMPath&COM_Dispatch.inc
% include &COMPath&COM_Dispatch.inc
% include &COMPath&COM_Dispatch.asm

% include &OA_PATH&Projects\32\MSChart\MSChart20Lib.inc

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream
LoadObjects Collection
LoadObjects DataCollection
LoadObjects WinPrimer
LoadObjects Window
LoadObjects Dialog
LoadObjects DialogModal
LoadObjects DialogAbout
LoadObjects WinApp
LoadObjects SdiApp
LoadObjects COM_Primers
LoadObjects IDispatch
LoadObjects ConnectionPoint
LoadObjects IConnectionPointContainer

;Add here the file that defines the object(s) to be included in the library
MakeObjects MSChart

end
