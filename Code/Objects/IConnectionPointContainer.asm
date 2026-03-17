; ==================================================================================================
; Title:      IConnectionPointContainer.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for IConnectionPointContainer object.
; Notes:      Version C.1.0, November 2017
;             - Initial release.
; ==================================================================================================


% include Objects.cop

% include &COMPath&COM.inc
% include &COMPath&COM_Dispatch.inc
% include &IncPath&Windows\ocidl.inc
% include &IncPath&Windows\OleCtl.inc

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream
LoadObjects Collection
LoadObjects DataCollection
LoadObjects COM_Primers
LoadObjects ConnectionPoint

;Add here the file that defines the object(s) to be included in the library
MakeObjects IConnectionPointContainer

end
