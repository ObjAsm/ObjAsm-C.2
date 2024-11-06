; ==================================================================================================
; Title:      soyoDivRem.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <soyoDivRem>

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  soyoDivRem
; Purpose:    Calculate a signed extended precision division, emulating the idiv x86 instrunction.
;             (256 bit) Dividend divided by (128 bit) Divisor = (128 bit) Quotient. 
; Arguments:  Arg1: Dividend signed low low word.
;             Arg2: Dividend signed high low word.
;             Arg3: Dividend signed low high word.
;             Arg4: Dividend signed high high word.
;             Arg5: Divisor signed low word.
;             Arg6: Divisor signed high word.
; Return:     rdx:rax = Signed quotient.
;             rbx:rcx = Signed remainder.
;             OF set on division overlow and the content of the registers is undetermined.
; Note:       Non-integral results are truncated (chopped) towards 0. 
;             The remainder is always less than the divisor in magnitude.

% include &ObjMemPath&Common\sxxxDivRem_XP.inc

end