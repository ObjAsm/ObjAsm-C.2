; ==================================================================================================
; Title:      uowordShl.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
;               - Inspired llshl.asm (nt5src-master).
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

ProcName equ <uowordShl>

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  uowordShl
; Purpose:    Shift left of an unsigned OWORD (signed and unsigned procs are identical).
; Arguments:  Arg1: OWORD in rdx:rax.
;             Arg2: Shift count in cl.
; Return:     rdx:rax Shifted value.

% include &ObjMemPath&Common\qwordShl_32.inc

end
