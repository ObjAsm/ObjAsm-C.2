; =================================================================================================
; Title:      IAT_Hook.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for IAT_Hook object.
; Notes:      Version C.1.0, August 2023
;            - First release.
; =================================================================================================


% include Objects.cop

_IMAGEHLP_SOURCE_ equ 0
SYM_NAME_LENGTH   equ 255
CALLER_MAX_DEEP   equ 10

% include &IncPath&Windows\DbgHelp.inc

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer

;Add here the file that defines the object(s) to be included in the library
MakeObjects IAT_Hook

end
