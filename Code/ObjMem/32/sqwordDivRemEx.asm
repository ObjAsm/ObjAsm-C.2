; ==================================================================================================
; Title:      sqwordDivRemEx.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

ProcName equ <sqwordDivRemEx>

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  sqwordDivRemEx
; Arguments:  Arg1: Dividend signed low low word.
;             Arg2: Dividend signed high low word.
;             Arg3: Dividend signed low high word.
;             Arg4: Dividend signed high high word.
;             Arg5: Divisor signed low word.
;             Arg6: Divisor signed high word.
; Return:     edx:eax = Signed quotient (64 bit).
;             ebx:ecx = Signed remainder.
;             OF set on division overlow. Register contents are invalid.
; Note:       Non-integral results are truncated (chopped) towards 0. 
;             The remainder is always less than the divisor in magnitude.

% include &ObjMemPath&Common\sxwordDivRemEx_XP.inc

end