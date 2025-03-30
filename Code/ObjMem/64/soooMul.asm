; ==================================================================================================
; Title:      soooMul.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
;               - Inspired llmul.asm (nt5src-master).
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <soooMul>
TypeArg equ <SQWORD>

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  soooMul
; Purpose:    Multiply 2 signed OWORDs.
;             (128 bit) Multiplicand multiplied by (128 bit) Multiplier = (128 bit) Product.
; Arguments:  Arg1: Multiplicand low signed word.
;             Arg2: Multiplicand high signed word.
;             Arg3: Multiplier low signed word.
;             Arg4: Multiplier high signed word.
; Return:     rdx:rax = Signed product.
; Note:       Both signed and unsigned routines are the same, since multiply's
;             work out the same in 2's complement.

% include &ObjMemPath&Common\oooMul_64P.inc

end