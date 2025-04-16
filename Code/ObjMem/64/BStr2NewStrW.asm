; ==================================================================================================
; Title:      BStr2NewStrW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2024.
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  BStr2NewStrW
; Purpose:    Create a new STRINGW with the content of a BSTR.
; Arguments:  Arg1: BSTR.
; Return:     rax -> STRINGW. When no longer needed, it must be freed using StrDisposeW.

% include &ObjMemPath&Common\BStr2NewStrW_X.inc

end
