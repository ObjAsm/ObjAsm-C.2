; ==================================================================================================
; Title:      sqqqMul.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
;               - Inspired llmul.asm (nt5src-master).
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

ProcName equ <sqqqMul>
TypeArg equ <SDWORD>

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  sqqqMul
; Purpose:    Multiply 2 signed QWORDs.
;             (64 bit) Multiplicand multiplied by (64 bit) Multiplier = (64 bit) Product.
; Arguments:  Arg1: Multiplicand low signed word.
;             Arg2 Multiplicand high signed word.
;             Arg3 Multiplier low signed word.
;             Arg4 Multiplier high signed word.
; Return:     edx:eax = Signed product.
; Note:       Both signed and unsigned routines are the same, since multiply's
;             work out the same in 2's complement.

% include &ObjMemPath&Common\qqqMul_32P.inc

end