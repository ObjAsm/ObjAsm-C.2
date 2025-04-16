; ==================================================================================================
; Title:      uyooMul.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <uyooMul>

; --------------------------------------------------------------------------------------------------
; Procedure:  uyooMul
; Purpose:    Multiply 2 unsigned OWORDs with extended precision.
;             (128 bit) Multiplicand multiplied by (128 bit) Multiplier = (256 bit) Product.
; Arguments:  Arg1: Multiplicand low unsigned word.
;             Arg2: Multiplicand high unsigned word.
;             Arg3: Multiplier low unsigned word.
;             Arg4: Multiplier high unsigned word.
; Return:     rbx:rcx:rdx:rax = Unsigned product.

% include &ObjMemPath&Common\uxxxMul_XP.inc

end