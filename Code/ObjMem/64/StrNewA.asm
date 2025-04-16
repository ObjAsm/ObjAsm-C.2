; ==================================================================================================
; Title:      StrNewA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <StrNewA>

; --------------------------------------------------------------------------------------------------
; Procedure:  StrNewA
; Purpose:    Allocate a new copy of the source string.
;             If the pointer to the source string is NULL, StrNew returns NULL and doesn't allocate
;             any memory space. Otherwise, StrNew makes a duplicate of the source string.
;             The allocated memory space is Length(String) + ZTC.
; Arguments:  Arg1: -> Source WIDE string.
; Return:     rax -> New string copy.

% include &ObjMemPath&Common\StrNew_TXP.inc

end
