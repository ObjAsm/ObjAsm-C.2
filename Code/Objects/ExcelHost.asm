; ==================================================================================================
; Title:      ExcelHost.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for ExcelHost object.
; Notes:      Version C.1.0, November 2017
;             - Initial release.
; ==================================================================================================


% include Objects.cop

% include &MacPath&BStrings.inc
% include &COMPath&COM.inc
% include &COMPath&COM_Dispatch.inc
% include &COMPath&OAIDL.inc
% include &IncPath&Windows\Ole2.inc
% include &IncPath&Windows\sGUID.inc

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer

;Add here the file that defines the object(s) to be included in the library
MakeObjects ExcelHost

end
