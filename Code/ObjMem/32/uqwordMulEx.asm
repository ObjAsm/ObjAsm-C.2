; ==================================================================================================
; Title:      uqwordMulEx.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

ProcName equ <uqwordMulEx>

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  uqwordMulEx
; Purpose:    Multiply 2 unsigned OWORDs with extended precision.
; Arguments:  Arg1: Multiplicand low unsigned word.
;             Arg2 Multiplicand high unsigned word.
;             Arg3 Multiplier low unsigned word.
;             Arg4 Multiplier high unsigned word.
; Return:     ebx:ecx:edx:eax = Unsigned product (128 bit).

% include &ObjMemPath&Common\uxwordMulEx_XP.inc

end