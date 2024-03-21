; ==================================================================================================
; Title:      sqwordMulEx.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

ProcName equ <sqwordMulEx>

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  sqwordMulEx
; Purpose:    Multiply 2 signed OWORDs with extended precision.
; Arguments:  Arg1: Multiplicand low signed word.
;             Arg2 Multiplicand high signed word.
;             Arg3 Multiplier low signed word.
;             Arg4 Multiplier high signed word.
; Return:     ebx:ecx:edx:eax = Signed product (128 bit).

% include &ObjMemPath&Common\sxwordMulEx_XP.inc

end