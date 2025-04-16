; ==================================================================================================
; Title:      syooMul.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <syooMul>

; --------------------------------------------------------------------------------------------------
; Procedure:  syooMul
; Purpose:    Multiply 2 signed OWORDs with extended precision.
;             (128 bit) Multiplicand multiplied by (128 bit) Multiplier = (256 bit) Product.
; Arguments:  Arg1: Multiplicand low signed word.
;             Arg2: Multiplicand high signed word.
;             Arg3: Multiplier low signed word.
;             Arg4: Multiplier high signed word.
; Return:     rbx:rcx:rdx:rax = Signed product.

% include &ObjMemPath&Common\sxxxMul_XP.inc

end