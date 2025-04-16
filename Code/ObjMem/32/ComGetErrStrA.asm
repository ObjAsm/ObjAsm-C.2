; ==================================================================================================
; Title:      ComGetErrStrA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, August 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemUefi.cop

ProcName textequ <ComGetErrStrA>

; --------------------------------------------------------------------------------------------------
; Procedure:  ComGetErrStrA
; Purpose:    Return a description ANSI string from a COM error code.
; Arguments:  Arg1: COM error code.
; Return:     eax -> Error string.

% include &ObjMemPath&Common\\ComGetErrStr_TX.inc

end
