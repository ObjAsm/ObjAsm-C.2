; ==================================================================================================
; Title:      sowordMul.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
;               - Inspired llmul.asm (nt5src-master).
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

ProcName equ <sowordMul>
TypeArg equ <SQWORD>

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  sowordMul
; Purpose:    Multiply 2 signed OWORDs.
; Arguments:  Arg1: Multiplicand.
;             Arg2: Multiplier.
; Return:     rdx:rax = Product.
; Note:       Both signed and unsigned routines are the same, since multiply's
;             work out the same in 2's complement.

% include &ObjMemPath&Common\owordMul_64.inc

end