; ==================================================================================================
; Title:      StopWatch.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for StopWatch object.
; Notes:      Version C.1.0, November 2017
;             - Initial release.
; ==================================================================================================


% include Objects.cop

% include &MacPath&fMath.inc

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer

;Add here the file that defines the object(s) to be included in the library
MakeObjects StopWatch

end
