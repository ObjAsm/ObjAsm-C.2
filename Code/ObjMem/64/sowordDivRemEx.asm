; ==================================================================================================
; Title:      sowordDivRemEx.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

ProcName equ <sowordDivRemEx>

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  sowordDivRemEx
; Arguments:  Arg1: Dividend signed low low word.
;             Arg2: Dividend signed high low word.
;             Arg3: Dividend signed low high word.
;             Arg4: Dividend signed high high word.
;             Arg5: Divisor signed low word.
;             Arg6: Divisor signed high word.
; Return:     rdx:rax = Signed quotient (128 bit).
;             rbx:rcx = Signed remainder.
;             OF set on division overlow. Register contents are invalid.
; Note:       Non-integral results are truncated (chopped) towards 0. 
;             The remainder is always less than the divisor in magnitude.

% include &ObjMemPath&Common\sxwordDivRemEx_XP.inc

end