; ==================================================================================================
; Title:      uqoqDivRem.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

ProcName equ <uqoqDivRem>

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  uqoqDivRem
; Purpose:    Calculate an unsigned extended precision division, emulating the div x86 instrunction.
;             (128 bit) Dividend divided by (64 bit) Divisor = (64 bit) Quotient. 
; Arguments:  Arg1: Dividend unsigned low low word.
;             Arg2: Dividend unsigned high low word.
;             Arg3: Dividend unsigned low high word.
;             Arg4: Dividend unsigned high high word.
;             Arg5: Divisor unsigned low word.
;             Arg6: Divisor unsigned high word.
; Return:     edx:eax = Unsigned quotient.
;             ebx:ecx = Unsigned remainder.
;             OF set on division overlow and the content of the registers is undetermined.
; Note:       Non-integral results are truncated (chopped) towards 0. 
;             The remainder is always less than the divisor in magnitude.

% include &ObjMemPath&Common\uxxxDivRem_XP.inc

end