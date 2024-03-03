; ==================================================================================================
; Title:      SortedReal4Vector.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for SortedReal4Vector object.
; Notes:      Version C.1.0, February 2024
;             - First release.
; ==================================================================================================


% include Objects.cop
% include &MacPath&fMath.inc

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream
LoadObjects Vector
LoadObjects Real4Vector

;Add here the file that defines the object(s) to be included in the library
MakeObjects SortedReal4Vector

end
