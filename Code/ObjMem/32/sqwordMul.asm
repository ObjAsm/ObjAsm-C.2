; ==================================================================================================
; Title:      sqwordMul.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
;               - Inspired llmul.asm (nt5src-master).
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

ProcName equ <sqwordMul>
TypeArg equ <SQWORD>

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  sqwordMul
; Purpose:    Multiply 2 signed QWORDs.
; Arguments:  Arg1: Multiplicand.
;             Arg2: Multiplier.
; Return:     edx:eax = Product.
; Note:       Both signed and unsigned routines are the same, since multiply's
;             work out the same in 2's complement.

% include &ObjMemPath&Common\qwordMul_32.inc

end