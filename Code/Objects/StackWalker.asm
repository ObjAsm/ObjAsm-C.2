; =================================================================================================
; Title:      StackWalker.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for StackWalker object.
; Notes:      Version C.1.0, August 2023
;            - First release.
; =================================================================================================


% include Objects.cop

% include &IncPath&DbgHelp.inc

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer

;Add here the file that defines the object(s) to be included in the library
MakeObjects StackWalker

end
