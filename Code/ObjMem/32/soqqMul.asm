; ==================================================================================================
; Title:      soqqMul.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <soqqMul>

; --------------------------------------------------------------------------------------------------
; Procedure:  soqqMul
; Purpose:    Multiply 2 signed OWORDs with extended precision.
;             (64 bit) Multiplicand multiplied by (64 bit) Multiplier = (128 bit) Product.
; Arguments:  Arg1: Multiplicand low signed word.
;             Arg2: Multiplicand high signed word.
;             Arg3: Multiplier low signed word.
;             Arg4: Multiplier high signed word.
; Return:     ebx:ecx:edx:eax = Signed product.

% include &ObjMemPath&Common\sxxxMul_XP.inc

end