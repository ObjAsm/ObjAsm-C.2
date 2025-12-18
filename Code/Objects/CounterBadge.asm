; ==================================================================================================
; Title:      CounterBadge.asm
; Author:     G. Friedrich
; Version:    C.2.0
; Purpose:    ObjAsm compilation file for CounterBadge object.
; Notes:      Version C.2.0, November 2025
;             - First release.
; ==================================================================================================


% include Objects.cop

;Add here all files that build the inheritance path and referenced objects

;Add here the file that defines the object(s) to be included in the library
MakeObjects Primer, TextBadge, CounterBadge

end
