; ==================================================================================================
; Title:      uowordDivRemEx.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, March 2024.
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

ProcName equ <uowordDivRemEx>

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  uowordDivRemEx
; Arguments:  Arg1: Dividend unsigned low low word.
;             Arg2: Dividend unsigned high low word.
;             Arg3: Dividend unsigned low high word.
;             Arg4: Dividend unsigned high high word.
;             Arg5: Divisor unsigned low word.
;             Arg6: Divisor unsigned high word.
; Return:     rdx:rax = Unsigned quotient (128 bit).
;             rbx:rcx = Unsigned remainder.
;             OF set on division overlow. Register contents are invalid.
; Note:       Non-integral results are truncated (chopped) towards 0. 
;             The remainder is always less than the divisor in magnitude.

% include &ObjMemPath&Common\uxwordDivRemEx_XP.inc

end