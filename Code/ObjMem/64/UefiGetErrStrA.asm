; ==================================================================================================
; Title:      UefiGetErrStrA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, August 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemUefi.cop

ProcName textequ <UefiGetErrStrA>

; --------------------------------------------------------------------------------------------------
; Procedure:  UefiGetErrStrA
; Purpose:    Return a description ANSI string from an UEFI error code.
; Arguments:  Arg1: UEFI error code.
; Return:     rax -> Error string.

% include &ObjMemPath&Common\\UefiGetErrStr_TX.inc

end
