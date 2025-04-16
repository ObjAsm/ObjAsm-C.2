; ==================================================================================================
; Title:      BStr2NewStrA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2024.
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  BStr2NewStrA
; Purpose:    Create a new STRINGA with the content of a BSTR.
; Arguments:  Arg1: BSTR.
; Return:     eax -> STRINGA. When no longer needed, it must be freed using StrDisposeA.

% include &ObjMemPath&Common\BStr2NewStrA_X.inc

end
