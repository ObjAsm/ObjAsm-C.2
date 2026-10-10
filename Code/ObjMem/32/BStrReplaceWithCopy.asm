; ==================================================================================================
; Title:      BStrReplaceWithCopy.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2024
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  BStrReplaceWithCopy
; Purpose:    Dispose a BSTR and replace it with a copy of another BSTR.
; Arguments:  Arg1: -> BSTR to be replaced.
;             Arg2: -> Replacing source BSTR.
; Return:     eax -> Replacing BSTR copy or NULL if failed.

% include &ObjMemPath&Common\BStrReplaceWithCopy_X.inc

end
