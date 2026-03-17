; ==================================================================================================
; Title:      D3Engine.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for D3Engine object.
; Notes:      Version C.1.0, November 2017
;             - Initial release.
; ==================================================================================================


% include Objects.cop

% include &MacPath&fMath.inc

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream
LoadObjects DiskStream
LoadObjects Collection
LoadObjects SortedCollection
LoadObjects SortedDataCollection
LoadObjects DataCollection

;Add here the file that defines the object(s) to be included in the library
MakeObjects D3Engine

end
