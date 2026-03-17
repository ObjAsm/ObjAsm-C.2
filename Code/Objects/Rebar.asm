; ==================================================================================================
; Title:      Rebar.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for Rebar object.
; Notes:      Version C.1.0, November 2017
;             - Initial release.
; ==================================================================================================


% include Objects.cop

% include &MacPath&DlgTmpl.inc
% include &IncPath&Windows\CommCtrl.inc

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream
LoadObjects WinPrimer
LoadObjects Window
LoadObjects WinControl
LoadObjects MsgInterceptor
LoadObjects Dialog
LoadObjects DialogModal
LoadObjects DialogModalIndirect
LoadObjects SimpleImageList
LoadObjects MaskedImageList
LoadObjects Collection
LoadObjects XMenu

;Add here the file that defines the object(s) to be included in the library
MakeObjects Rebar

end
