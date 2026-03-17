; ==================================================================================================
; Title:      Throbber.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for Throbber object.
; Notes:      Version C.1.0, April 2020
;             - Initial release.
; ==================================================================================================


% include Objects.cop

% include &IncPath&Windows\CommCtrl.inc

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream
LoadObjects WinPrimer

;Add here the file that defines the object(s) to be included in the library
MakeObjects Throbber

end
