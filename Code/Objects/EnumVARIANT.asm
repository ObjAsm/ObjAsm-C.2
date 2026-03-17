; =================================================================================================
; Title:   EnumVARIANT.asm
; Author:  Kai Liebenau
; Version: C.1.1
; Purpose: ObjAsm compilation file for EnumVARIANT object.
; Version: Version 1.0.0, April 2007
;            - Initial release.
;          Version C.1.1, December 2020
;            - Ported to ObjAsm.
; =================================================================================================


% include Objects.cop

% include &COMPath&COM.inc
% include &COMPath&OAIDL.inc
% include &COMPath&COM_Dispatch.inc
% include &COMPath&COM_Interfaces.inc
% include &IncPath&Windows\oleauto.inc

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream
LoadObjects Collection
LoadObjects DataCollection
LoadObjects COM_Primers


;Add here the file that defines the object(s) to be included in the library
MakeObjects EnumVARIANT

end