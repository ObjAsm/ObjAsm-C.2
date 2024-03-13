; ==================================================================================================
; Title:      sowordShl.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

ProcName equ <sowordShl>

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  sowordShl
; Purpose:    Shift left of a signed OWORD (signed and unsigned procs are identical).
; Arguments:  Arg1: OWORD in rdx:rax.
;             Arg2: Shift count in cl.
; Return:     rdx:rax Shifted value.

% include &ObjMemPath&Common\owordShl_64.inc

end
