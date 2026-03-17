; ==================================================================================================
; Title:      RegExW.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm compilation file for RegExA object.
; Notes:      Version C.1.1 December 2020
;             - Updated to version 8.44.
;             Version C.1.0, November 2017
;             - Initial release.
; ==================================================================================================


% include Objects.cop

% include &IncPath&PCRE\PCRE844S.inc

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream

;Add here the file that defines the object(s) to be included in the library
MakeObjects RegExW

end
