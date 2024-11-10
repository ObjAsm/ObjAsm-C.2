; ==================================================================================================
; Title:      BStrAlloc.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrAlloc
; Purpose:    Allocate space for a BString with n characters. The length field is set to zero.
; Arguments:  Arg1: Character count, without the ZTC.
; Return:     rax -> New allocated BString (BSTR) or NULL if failed.

% include &ObjMemPath&Common\\BStrAlloc_X.inc

end
