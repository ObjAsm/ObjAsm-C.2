; ==================================================================================================
; Title:      ComGetErrStrW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, August 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <ComGetErrStrW>

; --------------------------------------------------------------------------------------------------
; Procedure:  ComGetErrStrW
; Purpose:    Return a description WIDE string from a COM error code.
; Arguments:  Arg1: COM error code.
; Return:     rax -> Error string.

% include &ObjMemPath&Common\\ComGetErrStr_TX.inc

end
