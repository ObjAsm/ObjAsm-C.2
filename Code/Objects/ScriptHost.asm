; ==================================================================================================
; Title:      ScriptHost.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for ScriptHost object.
; Notes:      Version C.1.0, November 2017
;             - First release.
; ==================================================================================================


% include Objects.cop

% include &COMPath&COM.inc
% include &COMPath&COM_Dispatch.inc
% include &IncPath&Windows\Shlwapi.inc
% include &IncPath&Windows\ActivScp.inc
% include &IncPath&Windows\ActivDbg.inc


;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream
LoadObjects Collection
LoadObjects DataCollection
LoadObjects COM_Primers
LoadObjects IDispatch
LoadObjects IDual

;Add here the file that defines the object(s) to be included in the library
MakeObjects ScriptHost

end
