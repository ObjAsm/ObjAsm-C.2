; ==================================================================================================
; Title:      uoqqMul.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <uoqqMul>

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  uoqqMul
; Purpose:    Multiply 2 unsigned QWORDs with extended precision.
;             (64 bit) Multiplicand multiplied by (64 bit) Multiplier = (128 bit) Product. 
; Arguments:  Arg1: Multiplicand low unsigned word.
;             Arg2 Multiplicand high unsigned word.
;             Arg3 Multiplier low unsigned word.
;             Arg4 Multiplier high unsigned word.
; Return:     ebx:ecx:edx:eax = Unsigned product.

% include &ObjMemPath&Common\uxxxMul_XP.inc

end