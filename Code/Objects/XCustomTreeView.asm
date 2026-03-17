; ==================================================================================================
; Title:      XCustomTreeView.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for XCustomTreeView object.
; Notes:      Version C.1.0, November 2017
;             - Initial release.
; ==================================================================================================


% include Objects.cop

% include &MacPath&SDLL.inc

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream
LoadObjects WinPrimer
LoadObjects Window
LoadObjects WinControl
LoadObjects Collection
LoadObjects XWCollection
LoadObjects DataPool
LoadObjects XTreeView
LoadObjects WinApp

;Add here the file that defines the object(s) to be included in the library
MakeObjects XCustomTreeView

end
