; ==================================================================================================
; Title:      uoShl.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
;               - Inspired llshl.asm (nt5src-master).
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <uoShl>

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  uoShl
; Purpose:    Shift left of an unsigned OWORD (signed and unsigned procs are identical).
; Arguments:  Arg1: OWORD in rdx:rax.
;             Arg2: Shift count in cl.
; Return:     rdx:rax Shifted value.

% include &ObjMemPath&Common\oShl_64P.inc

end
