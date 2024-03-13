; ==================================================================================================
; Title:      uqwordShl.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
;               - Inspired llshl.asm (nt5src-master).
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

ProcName equ <uqwordShl>

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  uqwordShl
; Purpose:    Shift left of a signed QWORD (signed and unsigned procs are identical).
; Arguments:  Arg1: QWORD in edx:eax.
;             Arg2: Shift count in cl.
; Return:     edx:eax Shifted value.

% include &ObjMemPath&Common\qwordShl_32.inc

end
