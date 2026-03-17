; ==================================================================================================
; Title:      Pixelmap.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for Pixelmap object.
; Notes:      Version C.1.0, November 2017
;             - Initial release.
; ==================================================================================================


% include Objects.cop

% include &COMPath&COM.inc
% include &MacPath&fMath.inc
% include &IncPath&Windows\OleCtl.inc
% include &IncPath&Windows\sGUID.inc

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream

;Add here the file that defines the object(s) to be included in the library
MakeObjects Pixelmap

end
