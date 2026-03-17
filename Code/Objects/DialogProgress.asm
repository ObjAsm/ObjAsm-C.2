; ==================================================================================================
; Title:      DialogProgress.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm compilation file for DialogProgress object.
; Notes:      Version C.1.1, August 2019
;             - Initial release.
; ==================================================================================================


% include Objects.cop

% include &IncPath&Windows\CommCtrl.inc
% include &IncPath&Windows\Richedit.inc

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream
LoadObjects WinPrimer
LoadObjects Window
LoadObjects Dialog
LoadObjects DialogModal

;Add here the file that defines the object(s) to be included in the library
MakeObjects DialogProgress

end
