; ==================================================================================================
; Title:      Json.asm
; Author:     G. Friedrich
; Version:    1.0.0
; Purpose:    ObjAsm compilation file for Json object.
; Version:    Version 1.0.0, December 2020
;               - Initial release.
; ==================================================================================================

% include Objects.cop

% include &MacPath&LDLL.inc

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream

;Add here the file that defines the object(s) to be included in the library
MakeObjects Json

end
