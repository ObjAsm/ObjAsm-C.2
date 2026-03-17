; ==================================================================================================
; Title:      SkinnedDialogAbout.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for SkinnedDialogAbout object.
; Notes:      Version C.1.0, November 2017
;             - Initial release.
; ==================================================================================================


% include Objects.cop

% include &IncPath&Windows\CommCtrl.inc

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream
LoadObjects WinPrimer
LoadObjects Window
LoadObjects WinControl
LoadObjects Tooltip
LoadObjects Dialog
LoadObjects DialogModal
LoadObjects MsgInterceptor
LoadObjects ElasticSkin
LoadObjects RgnButton
LoadObjects Collection
LoadObjects DataCollection
LoadObjects GifDecoder
LoadObjects GifPlayer

;Add here the file that defines the object(s) to be included in the library
MakeObjects SkinnedDialogAbout

end
