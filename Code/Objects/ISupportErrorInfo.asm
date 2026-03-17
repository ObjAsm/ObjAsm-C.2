; ==================================================================================================
; Title:      ISupportErrorInfo.asm
; Author:     Kai Liebenau
; Version:    1.0.1
; Purpose:    ObjAsm compilation file for ISupportErrorInfo object.
; Version:    Version 1.0.0, September 2006
;               - Initial release.
;             Version 1.0.1, August 2008
;               - SysSetup introduced.
; ==================================================================================================

% include Objects.cop

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream
LoadObjects Collection
LoadObjects DataCollection
LoadObjects XWCollection
LoadObjects COM_Primers

;Add here the file that defines the object(s) to be included in the library
MakeObjects ISupportErrorInfo

end
