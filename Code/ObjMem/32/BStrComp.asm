; ==================================================================================================
; Title:      BStrComp.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2024.
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrComp
; Purpose:    Compare 2 BSTRs.
; Arguments:  Arg1: First BSTR.
;             Arg2: Second BSTR.
; Return:     eax = 0 if both BSTRs are identical, otherwise non zero.

% include &ObjMemPath&Common\BStrComp_X.inc

end