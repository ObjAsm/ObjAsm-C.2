; ==================================================================================================
; Title:      aCRC32C.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, March 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  aCRC32C
; Purpose:    Compute the CRC-32C (Castagnoli), using the polynomial 11EDC6F41h from an aligned
;             memory block.
; Arguments:  Arg1: -> Aligned memory block.
;             Arg2: Memory block size in BYTEs.
; Return:     eax = CRC32C.

% include &ObjMemPath&Common\aCRC32C_XP.inc

end
