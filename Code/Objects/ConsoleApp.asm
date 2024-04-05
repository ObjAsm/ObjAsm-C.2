; ==================================================================================================
; Title:      ConsoleApp.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for ConsoleApp object.
; Notes:      Version C.1.0, April 2024
;             - First release.
; ==================================================================================================


% include Objects.cop

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream

;Add here the file that defines the object(s) to be included in the library
MakeObjects ConsoleApp

end
