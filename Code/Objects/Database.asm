; ==================================================================================================
; Title:      Database.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm compilation file for Database cluster objects.
; Notes:      Version C.1.1, August 2019
;             - First release.
; ==================================================================================================


% include Objects.cop

% include &MacPath&ConstDiv.inc
% include &MacPath&QuadWord.inc
% include &MacPath&fMath.inc
% include &IncPath&Windows\Shlwapi.inc

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream
LoadObjects DiskStream
LoadObjects Collection
LoadObjects SortedCollection
LoadObjects DataCollection
LoadObjects WinPrimer
LoadObjects Window
LoadObjects Dialog
LoadObjects DialogModal
LoadObjects DialogProgress


;Add here the file that defines the object(s) to be included in the library
MakeObjects Database

end
