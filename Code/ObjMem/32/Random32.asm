; ==================================================================================================
; Title:      Random32.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  Random32
; Purpose:    Generate a random 32 bit number in a given range [0..Limit-1].
;             Park Miller random number algorithm. Written by Jaymeson Trudgen (NaN) and optimized
;             by Rickey Bowers Jr. (bitRAKE).
; Arguments:  Arg1: Range limit (max. = 07FFFFFFFh).
; Return:     eax = Random number in the range [0..Limit-1].

% include &ObjMemPath&Common\Random32_X.inc

end
