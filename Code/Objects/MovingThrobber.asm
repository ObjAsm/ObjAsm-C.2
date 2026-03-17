; ==================================================================================================
; Title:      MovingThrobber.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for MovingThrobber object.
; Notes:      Version C.1.0, April 2020
;             - Initial release.
; ==================================================================================================


% include Objects.cop

GDIPVER equ 0100h

% include &COMPath&COM.inc                              ;COM basic support
% include &MacPath&fMath.inc
% include &IncPath&Windows\CommCtrl.inc
% include &IncPath&Windows\richedit.inc
% include &IncPath&Windows\GdiplusPixelFormats.inc
% include &IncPath&Windows\GdiplusInit.inc
% include &IncPath&Windows\GdiplusEnums.inc
% include &IncPath&Windows\GdiplusGpStubs.inc
% include &IncPath&Windows\GdiPlusFlat.inc

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream
LoadObjects WinPrimer
LoadObjects Throbber

;Add here the file that defines the object(s) to be included in the library
MakeObjects MovingThrobber

end
