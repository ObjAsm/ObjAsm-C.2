; ==================================================================================================
; Title:      BStrReplace.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2024
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  BStrReplace
; Purpose:    Dispose an existing BSTR and replace it with a new one.
; Arguments:  Arg1: -> BSTR to be replaced.
;             Arg2: -> new BSTR.
; Return:     rax -> New allocated BSTR or NULL if failed.

% include &ObjMemPath&Common\BStrReplace_X.inc

end
