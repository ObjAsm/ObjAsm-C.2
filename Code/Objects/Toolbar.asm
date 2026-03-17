; ==================================================================================================
; Title:      Toolbar.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for Toolbar object.
; Notes:      Version C.1.0, November 2017
;             - Initial release.
; ==================================================================================================


% include Objects.cop

% include &MacPath&WinHelpers.inc
% include &IncPath&Windows\CommCtrl.inc

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream
LoadObjects WinPrimer
LoadObjects WinControl
LoadObjects SimpleImageList
LoadObjects MaskedImageList

;Add here the file that defines the object(s) to be included in the library
MakeObjects Toolbar

end
