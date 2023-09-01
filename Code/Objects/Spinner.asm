; ==================================================================================================
; Title:      Spinner.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for Spinner object.
; Notes:      Version C.1.0, April 2022
;             - First release.
; ==================================================================================================


% include Objects.cop

% include &MacPath&fMath.inc
% include &IncPath&Windows\CommCtrl.inc

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream
LoadObjects WinPrimer
LoadObjects Window

;Add here the file that defines the object(s) to be included in the library
MakeObjects Spinner

end
