; ==================================================================================================
; Title:      QWordVector.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for QWordVector object.
; Notes:      Version C.1.0, September 2021
;             - First release.
; ==================================================================================================


% include Objects.cop

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream
LoadObjects Vector

;Add here the file that defines the object(s) to be included in the library
MakeObjects QWordVector

end
