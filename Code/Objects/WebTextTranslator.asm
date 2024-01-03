; ==================================================================================================
; Title:      WebTextTranslator.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for WebTextTranslator object.
; Notes:      Version C.1.0, November 2022
;             - First release.
; ==================================================================================================


% include Objects.cop

% include &IncPath&Windows\wininet.inc


;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream
LoadObjects DiskStream
LoadObjects Collection
LoadObjects SortedCollection

;Add here the file that defines the object(s) to be included in the library
MakeObjects WebTextTranslator

end
