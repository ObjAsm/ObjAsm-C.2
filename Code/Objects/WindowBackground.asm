; ==================================================================================================
; Title:      WindowBackground.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for WindowBackground object.
; Notes:      Version C.1.0, May 2021
;             - Initial release.
; ==================================================================================================


% include Objects.cop

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream
LoadObjects Collection
LoadObjects DataCollection

;Add here the file that defines the object(s) to be included in the library
MakeObjects WindowBackground

end
