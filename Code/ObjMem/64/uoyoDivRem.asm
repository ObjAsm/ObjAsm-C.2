; ==================================================================================================
; Title:      uoyoDivRem.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

ProcName equ <uoyoDivRem>

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  uoyoDivRem
; Purpose:    Calculate a unsigned extended precision division, emulating the div x86 instruction.
;             (256 bit) Dividend divided by (128 bit) Divisor = (128 bit) Quotient. 
; Arguments:  Arg1: Dividend unsigned low low word.
;             Arg2: Dividend unsigned high low word.
;             Arg3: Dividend unsigned low high word.
;             Arg4: Dividend unsigned high high word.
;             Arg5: Divisor unsigned low word.
;             Arg6: Divisor unsigned high word.
; Return:     rdx:rax = Unsigned quotient.
;             rbx:rcx = Unsigned remainder.
;             OF set on division overlow. Register contents are invalid.
; Note:       Non-integral results are truncated (chopped) towards 0. 
;             The remainder is always less than the divisor in magnitude.

% include &ObjMemPath&Common\uxxxDivRem_XP.inc

end