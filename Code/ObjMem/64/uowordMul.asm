; ==================================================================================================
; Title:      uowordMul.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
;               - Inspired llmul.asm (nt5src-master).
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

ProcName equ <uowordMul>
TypeArg equ <QWORD>

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  uowordMul
; Purpose:    Multiply 2 unsigned OWORDs.
; Arguments:  Arg1: Multiplicand low unsigned word.
;             Arg2 Multiplicand high unsigned word.
;             Arg3 Multiplier low unsigned word.
;             Arg4 Multiplier high unsigned word.
; Return:     rdx:rax = Product.
; Note:       Both signed and unsigned routines are the same, since multiply's
;             work out the same in 2's complement.

% include &ObjMemPath&Common\owordMul_64.inc

end