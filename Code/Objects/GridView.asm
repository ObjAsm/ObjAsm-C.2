; ==================================================================================================
; Title:      GridView.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for GridView object.
; Notes:      Version C.1.1, May 2020
;             - Initial release.
; ==================================================================================================


% include Objects.cop

% include &IncPath&Windows\CommCtrl.inc

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream
LoadObjects Collection
LoadObjects DataCollection
LoadObjects SortedCollection
LoadObjects SortedDataCollection
LoadObjects XWCollection
LoadObjects WinPrimer
LoadObjects Window

;Add here the file that defines the object(s) to be included in the library
MakeObjects GridView

end
