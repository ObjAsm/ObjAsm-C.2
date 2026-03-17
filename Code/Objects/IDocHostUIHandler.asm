; ==================================================================================================
; Title:      IDocHostUIHandler.asm
; Author:     G. Friedrich
; Version:    C.1.2
; Purpose:    ObjAsm compilation file for IDocHostUIHandler object.
; Notes:      Version C.1.2, December 2020
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

;Add here the file that defines the object(s) to be included in the library
MakeObjects IDocHostUIHandler

end
