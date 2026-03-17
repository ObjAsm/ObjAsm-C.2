; ==================================================================================================
; Title:      XPropertyTree.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for XPropertyTree object.
; Notes:      Version C.1.0, November 2017
;             - Initial release.
; ==================================================================================================


% include Objects.cop

% include &MacPath&fMath.inc
% include &MacPath&SDLL.inc
% include &IncPath&Windows\shlobj_core.inc

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream
LoadObjects WinPrimer
LoadObjects WinControl
LoadObjects Collection
LoadObjects XWCollection
LoadObjects DataPool
LoadObjects XTreeView

;Add here the file that defines the object(s) to be included in the library
MakeObjects XPropertyTree

end
