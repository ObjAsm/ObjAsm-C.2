; ==================================================================================================
; Title:      StrW2NewBStr.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2024.
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrW2NewBStr
; Purpose:    Create a new BSTR with the content of a STRINGW.
; Arguments:  Arg1: -> STRINGW.
; Return:     rax = BSTR. When no longer needed, it must be freed using BStrDispose or 
;             SysFreeString.

% include &ObjMemPath&Common\StrW2NewBStr_X.inc

end
