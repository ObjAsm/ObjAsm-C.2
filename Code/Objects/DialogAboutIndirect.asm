; ==================================================================================================
; Title:      DialogAboutIndirect.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for DialogAboutIndirect object.
; Notes:      Version C.1.0, November 2017
;             - Initial release.
; ==================================================================================================


% include Objects.cop

% include &MacPath&DlgTmpl.inc

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream
LoadObjects WinPrimer
LoadObjects Window
LoadObjects Button
LoadObjects Hyperlink
LoadObjects Dialog
LoadObjects DialogModal
LoadObjects DialogModalIndirect

;Add here the file that defines the object(s) to be included in the library
MakeObjects DialogAboutIndirect

end
