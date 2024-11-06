; ==================================================================================================
; Title:      UefiGetErrStrW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, August 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemUefi.cop

ProcName textequ <UefiGetErrStrW>

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  UefiGetErrStrW
; Purpose:    Return a description WIDE string from an UEFI error code.
; Arguments:  Arg1: UEFI error code.
; Return:     eax -> Error string.

% include &ObjMemPath&Common\\UefiGetErrStr_TX.inc

end
