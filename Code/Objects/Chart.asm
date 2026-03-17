; ==================================================================================================
; Title:      Chart.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for Chart object.
; Notes:      Version C.1.0, August 2021
;             - Initial release.
; ==================================================================================================


% include Objects.cop

% include &MacPath&fMath.inc
% include &IncPath&Windows\CommCtrl.inc

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream
LoadObjects WinPrimer
LoadObjects Window
LoadObjects WinApp
LoadObjects Dialog
LoadObjects DialogModal
LoadObjects DialogModeless
LoadObjects Array
LoadObjects Collection
LoadObjects SortedCollection
LoadObjects DataCollection
LoadObjects SortedDataCollection
LoadObjects XWCollection
LoadObjects SimpleImageList
LoadObjects MaskedImageList
LoadObjects Button
LoadObjects IconButton
LoadObjects ColorButton
LoadObjects WinControl
LoadObjects MsgInterceptor
LoadObjects TabCtrl
LoadObjects TextView

;Add here the file that defines the object(s) to be included in the library
MakeObjects Chart

end
