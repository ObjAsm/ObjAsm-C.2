; ==================================================================================================
; Title:      uqqqMul.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
;               - Inspired llmul.asm (nt5src-master).
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

ProcName equ <uqqqMul>
TypeArg equ <DWORD>

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  uqqqMul
; Purpose:    Multiply 2 unsigned QWORDs.
;             (64 bit) Multiplicand multiplied by (64 bit) Multiplier = (64 bit) Product.
; Arguments:  Arg1: Multiplicand low unsigned word.
;             Arg2 Multiplicand high unsigned word.
;             Arg3 Multiplier low unsigned word.
;             Arg4 Multiplier high unsigned word.
; Return:     edx:eax = Unsigned product.
; Note:       Both signed and unsigned routines are the same, since multiply's
;             work out the same in 2's complement.

% include &ObjMemPath&Common\qqqMul_32P.inc

end