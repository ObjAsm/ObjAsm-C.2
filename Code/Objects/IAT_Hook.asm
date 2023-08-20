; =================================================================================================
; Title:   IAT32Hook.asm
; Author:  G. Friedrich
; Version: 1.0.1
; Purpose: ObjAsm32 compilation file for IAT32Hook object.
; Notes:   Version 1.0.0, March 2005
;            - First release.
;          Version 1.0.1, August 2008
;            - SysSetup introduced.
; =================================================================================================

%include @Environ(OA32_PATH)\\Code\\Macros\\Model.inc
SysSetup OOP_OBJECT_LIB

% include &IncPath&ImageHlp.inc

;Add here all files that build the inheritance path and referenced objects
include Primer.inc

;Add here the file that defines the object(s) to be included in the library
MakeObjects IAT32Hook

end
